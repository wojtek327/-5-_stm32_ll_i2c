#include "bmi160.h"
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

#define BMI160_SIGN_EXTEND(val, from) \
    (((val) & (1 << ((from) - 1))) ? (val | (((1 << (1 + (sizeof(val) << 3) - (from))) - 1) << (from))) : val)

static int8_t BMI160_WriteRegister(uint8_t address, uint8_t cmd);
static int8_t BMI160_ReadRegister(uint8_t address, uint8_t dataSize, uint8_t *rec);
static uint8_t BMI160_ReadRegBits(uint8_t reg, unsigned pos, unsigned len);
static int8_t BMI160_WriteRegisterBits(uint8_t reg, uint8_t data, unsigned pos, unsigned len);

static int8_t I2C_BMI160_ReceiveData(uint8_t devAddr, uint8_t* buffer, uint8_t len, uint16_t maxDelay)
{
  uint16_t countTimeout = 0;

  if(len == 1) { LL_I2C_AcknowledgeNextData(I2C1, LL_I2C_NACK); }
  else { LL_I2C_AcknowledgeNextData(I2C1, LL_I2C_ACK); }

  LL_I2C_GenerateStartCondition(I2C1);

  while(!LL_I2C_IsActiveFlag_SB(I2C1)) {
    LL_mDelay(1);
    countTimeout++;
    if(countTimeout > maxDelay) {
    	return -1;
    }
  }

  LL_I2C_TransmitData8(I2C1, (devAddr) | 0x01);

  while(!LL_I2C_IsActiveFlag_ADDR(I2C1)) {
    LL_mDelay(1);
    countTimeout++;
    if(countTimeout > maxDelay) {
    	return -2;
    }
  }

  LL_I2C_ClearFlag_ADDR(I2C1);

  for(int i = 0; i < len; i++) {
    if(i == (len - 1)) {
      LL_I2C_AcknowledgeNextData(I2C1, LL_I2C_NACK);
    }

    while(!LL_I2C_IsActiveFlag_RXNE(I2C1)) {
      LL_mDelay(1);
      countTimeout++;
      if(countTimeout > maxDelay) {
    	  return -3;
      }
    }

    buffer[i] = LL_I2C_ReceiveData8(I2C1);
  }

  LL_I2C_GenerateStopCondition(I2C1);

  return 0;
}

static int8_t I2C_BMI160_SendData(uint8_t devAddr, uint8_t* buffer, uint16_t len, uint16_t maxDelay)
{
  uint16_t countTimeout = 0;

  LL_I2C_GenerateStartCondition(I2C1);

  while(!LL_I2C_IsActiveFlag_SB(I2C1)) {
    LL_mDelay(1);
    countTimeout++;
    if(countTimeout > maxDelay) {
    	return -1;
    }
  }

  LL_I2C_TransmitData8(I2C1, (devAddr) | 0x00);

  while(!LL_I2C_IsActiveFlag_ADDR(I2C1))
  {
    LL_mDelay(1);
    countTimeout++;
    if(countTimeout > maxDelay) {
    	return -2;
    }
  }

  LL_I2C_ClearFlag_ADDR(I2C1);

  for(int i=0; i < len; i++)
  {
    while(!LL_I2C_IsActiveFlag_TXE(I2C1)) {
      LL_mDelay(1);
      countTimeout++;
      if(countTimeout > maxDelay) {
    	  return -3;
      }
    }

    LL_I2C_TransmitData8(I2C1, buffer[i]);
  }

  while(!LL_I2C_IsActiveFlag_BTF(I2C1)) {
    LL_mDelay(1);
    countTimeout++;
    if(countTimeout > maxDelay) {
    	return -4;
    }
  }

  LL_I2C_GenerateStopCondition(I2C1);

  return 0;
}

static int8_t BMI160_ReadRegister(uint8_t address, uint8_t dataSize, uint8_t *rec)
{
	int8_t opResoult = 0;
	uint8_t data[1] = {0x00};
	data[0] = address;

	opResoult = I2C_BMI160_SendData(BMI160_I2C_ADDR, data, 1, 50);
	if(opResoult != 0 ) { return (opResoult); }
	opResoult = I2C_BMI160_ReceiveData(BMI160_I2C_ADDR + 1, &rec[0], dataSize, 50);

	return opResoult;
}

static int8_t BMI160_WriteRegister(uint8_t address, uint8_t cmd)
{
	uint8_t data[2] = {0x00};
	int8_t opResoult = 0;
	data[0] = address;
	data[1] = cmd;

	opResoult = I2C_BMI160_SendData(BMI160_I2C_ADDR, data, 2, 50);

	return opResoult;
}

static uint8_t BMI160_ReadRegBits(uint8_t reg, unsigned pos, unsigned len)
{
	uint8_t readData = 0;
	int8_t opStatus = BMI160_ReadRegister(reg, 1, &readData);

	if(opStatus != 0) {
		return 0x00;
	}

    uint8_t mask = (1 << len) - 1;
    readData >>= pos;
    readData &= mask;

    return readData;
}

static int8_t BMI160_WriteRegisterBits(uint8_t reg, uint8_t data, unsigned pos, unsigned len)
{
	uint8_t readData = 0;
	int8_t opStatus = BMI160_ReadRegister(reg, 1, &readData);

	if(opStatus != 0) {
		return opStatus;
	}

    uint8_t mask = ((1 << len) - 1) << pos;

    data <<= pos;
    data &= mask;
    readData &= ~(mask);
    readData |= data;

    return BMI160_WriteRegister(reg, readData);
}



int8_t BMI160_Initialize(void)
{
	int8_t opStatus = 0;

	opStatus = BMI160_PerformSoftReset();
	if(opStatus != 0) { return -1; }

    LL_mDelay(100);

	if(BMI160_CheckSensorID() == 0) { return -2; }

    LL_mDelay(100);

	opStatus = BMI160_PowerUpAccelerometer();
	if(opStatus != 0) { return -3; }

    LL_mDelay(100);

	opStatus = BMI160_PowerUpGyroscope();
	if(opStatus != 0) { return -4; }

    LL_mDelay(100);

	opStatus = BMI160_SetFullScaleGyroRange(BMI160_GYRO_RANGE_250);
	if(opStatus != 0) { return -5; }

    LL_mDelay(100);

	opStatus = BMI160_SetFullScaleAccelRange(BMI160_ACCEL_RANGE_2G);
	if(opStatus != 0) { return -6; }

    LL_mDelay(100);

	opStatus = BMI160_WriteRegister(BMI160_RA_INT_MAP_0, 0xFF);
	if(opStatus != 0) { return -7; }

    LL_mDelay(100);

	opStatus = BMI160_WriteRegister(BMI160_RA_INT_MAP_1, 0xF0);
	if(opStatus != 0) { return -8; }

    LL_mDelay(100);

	opStatus = BMI160_WriteRegister(BMI160_RA_INT_MAP_2, 0x00);
	if(opStatus != 0) { return -9; }

    LL_mDelay(100);

	return 0;
}

int8_t BMI160_ReadChipID(uint8_t *chipId)
{
	uint8_t readData = 0;
	int8_t opStatus = BMI160_ReadRegister(BMI160_RA_CHIP_ID, 1, &readData);

	if(opStatus != 0)
	{
		return opStatus;
	}

	*(chipId + 0) = readData;

	return opStatus;
}

uint8_t BMI160_CheckSensorID(void) {
	uint8_t readedChipId = 0;
	int8_t opStat = BMI160_ReadChipID(&readedChipId);

	if(opStat != 0) { return 0; }

	if(readedChipId == SENSOR_CHIP_ID_BMI160) {
		return 1;
	}
	else if(readedChipId == SENSOR_CHIP_ID_BMI160_C2) {
		return 2;
	}
	else if(readedChipId == SENSOR_CHIP_ID_BMI160_C3) {
		return 3;
	}

	return 0;
}

int8_t BMI160_PerformSoftReset(void)
{
	int8_t opStatus = BMI160_WriteRegister(BMI160_RA_CMD, BMI160_CMD_SOFT_RESET);
	return opStatus;
}

int8_t BMI160_PowerUpAccelerometer(void)
{
	int8_t opStatus = BMI160_WriteRegister(BMI160_RA_CMD, BMI160_CMD_ACC_MODE_NORMAL);

	if(opStatus != 0) {
		return opStatus;
	}

	LL_mDelay(1);

	while(0x1 != BMI160_ReadRegBits(BMI160_RA_PMU_STATUS, BMI160_ACC_PMU_STATUS_BIT, BMI160_ACC_PMU_STATUS_LEN)) {
		LL_mDelay(1);
	}

	return 0;
}

int8_t BMI160_PowerUpGyroscope(void)
{
	int8_t opStatus = BMI160_WriteRegister(BMI160_RA_CMD, BMI160_CMD_GYR_MODE_NORMAL);

	if(opStatus != 0)
	{
		return opStatus;
	}

	LL_mDelay(1);

	while(0x1 != BMI160_ReadRegBits(BMI160_RA_PMU_STATUS, BMI160_GYR_PMU_STATUS_BIT, BMI160_GYR_PMU_STATUS_LEN))
	{
		LL_mDelay(1);
	}

	return 0;
}

int8_t BMI160_ReadGyro(int16_t* x, int16_t* y, int16_t* z)
{
    uint8_t buffer[6];

    buffer[0] = BMI160_RA_GYRO_X_L;

    int8_t opStat = BMI160_ReadRegister(BMI160_RA_GYRO_X_L, 6, &buffer[0]);

    if(opStat != 0) { return opStat; }

    *x = (((int16_t)buffer[1]) << 8) | buffer[0];
    *y = (((int16_t)buffer[3]) << 8) | buffer[2];
    *z = (((int16_t)buffer[5]) << 8) | buffer[4];

    return opStat;
}

float BMI160_ScaledData(const int16_t gRaw, const BMI160GyroRange gyroRange) {
  float g = 0.0F;

  if(gyroRange == BMI160_GYRO_RANGE_2000) {
	  g = (gRaw / SENS_2000_DPS_LSB_PER_DPS);
  }
  else if(gyroRange == BMI160_GYRO_RANGE_1000) {
	  g = (gRaw / SENS_1000_DPS_LSB_PER_DPS);
  }
  else if(gyroRange == BMI160_GYRO_RANGE_500) {
	  g = (gRaw / SENS_500_DPS_LSB_PER_DPS);
  }
  else if(gyroRange == BMI160_GYRO_RANGE_250) {
	  g = (gRaw / SENS_250_DPS_LSB_PER_DPS);
  }
  else if(gyroRange == BMI160_GYRO_RANGE_125) {
	  g = (gRaw / SENS_125_DPS_LSB_PER_DPS);
  }

  return g;
}

int8_t BMI160_GetTemperature(int16_t *temp) {
    uint8_t buffer[2] = {0x00};

    int8_t opStat = BMI160_ReadRegister(BMI160_RA_TEMP_L, 2, &buffer[0]);

    if(opStat != 0) { return opStat; }

    *(temp + 0) = (((int16_t)buffer[1]) << 8) | buffer[0];
    return opStat;
}

float BMI160_ConvertRawTemp(int16_t tempRaw)
{
	float convertTemp = 0;

    if(tempRaw & 0x8000) { convertTemp = (23.0F - ((0x10000 - tempRaw)/512.0F)); }
    else { convertTemp = ((tempRaw/512.0F) + 23.0F); }

    return convertTemp;
}

int8_t BMI160_GetAccelerationX(int16_t *accel) {
    uint8_t buffer[2] = {0x00};

    int8_t opStat = BMI160_ReadRegister(BMI160_RA_ACCEL_X_L, 2, &buffer[0]);
    if(opStat != 0) { return opStat; }

    *(accel + 0) = (((int16_t)buffer[1]) << 8) | buffer[0];
    return opStat;
}

int8_t BMI160_GetAccelerationY(int16_t *accel) {
    uint8_t buffer[2] = {0x00};

    int8_t opStat = BMI160_ReadRegister(BMI160_RA_ACCEL_Y_L, 2, &buffer[0]);

    if(opStat != 0) { return opStat; }

    *(accel + 0) = (((int16_t)buffer[1]) << 8) | buffer[0];
    return opStat;
}

int8_t BMI160_GetAccelerationZ(int16_t *accel) {
    uint8_t buffer[2] = {0x00};

    int8_t opStat = BMI160_ReadRegister(BMI160_RA_ACCEL_Z_L, 2, &buffer[0]);

    if(opStat != 0) { return opStat; }

    *(accel + 0) = (((int16_t)buffer[1]) << 8) | buffer[0];
    return opStat;
}

int8_t BMI160_GetAcceleration(int16_t* x, int16_t* y, int16_t* z) {
    uint8_t buffer[6] = {0x00};

    int8_t opStat = BMI160_ReadRegister(BMI160_RA_ACCEL_X_L, 6, &buffer[0]);

    if(opStat != 0) { return opStat; }

    *x = (((int16_t)buffer[1]) << 8) | buffer[0];
    *y = (((int16_t)buffer[3]) << 8) | buffer[2];
    *z = (((int16_t)buffer[5]) << 8) | buffer[4];

    return opStat;
}

int8_t BMI160_GetMotion6(int16_t* ax, int16_t* ay, int16_t* az, int16_t* gx, int16_t* gy, int16_t* gz) {
    uint8_t buffer[12] = {0x00};

    int8_t opStat = BMI160_ReadRegister(BMI160_RA_GYRO_X_L, 12, &buffer[0]);

    if(opStat != 0) { return opStat; }

    *gx = (((int16_t)buffer[1])  << 8) | buffer[0];
    *gy = (((int16_t)buffer[3])  << 8) | buffer[2];
    *gz = (((int16_t)buffer[5])  << 8) | buffer[4];
    *ax = (((int16_t)buffer[7])  << 8) | buffer[6];
    *ay = (((int16_t)buffer[9])  << 8) | buffer[8];
    *az = (((int16_t)buffer[11]) << 8) | buffer[10];

    return opStat;
}

BMI160GyroRate BMI160_GetGyroRate(void) {
	return (BMI160GyroRate)BMI160_ReadRegBits(BMI160_RA_GYRO_CONF, BMI160_GYRO_RATE_SEL_BIT, BMI160_GYRO_RATE_SEL_LEN);
}

int8_t BMI160_SetGyroRate(const BMI160GyroRate rate) {
	return BMI160_WriteRegisterBits(BMI160_RA_GYRO_CONF, (uint8_t)rate, BMI160_GYRO_RATE_SEL_BIT, BMI160_GYRO_RATE_SEL_LEN);
}

BMI160AccelRate BMI160_GetAccelRate(void) {
	return (BMI160AccelRate)BMI160_ReadRegBits(BMI160_RA_ACCEL_CONF, BMI160_ACCEL_RATE_SEL_BIT, BMI160_ACCEL_RATE_SEL_LEN);
}

int8_t BMI160_SetAccelRate(const BMI160AccelRate rate) {
	return BMI160_WriteRegisterBits(BMI160_RA_ACCEL_CONF, (uint8_t)rate, BMI160_ACCEL_RATE_SEL_BIT, BMI160_ACCEL_RATE_SEL_LEN);
}

BMI160DLPFMode BMI160_GetGyroDLPFMode(void) {
    return (BMI160DLPFMode)BMI160_ReadRegBits(BMI160_RA_GYRO_CONF, BMI160_GYRO_DLPF_SEL_BIT, BMI160_GYRO_DLPF_SEL_LEN);
}

int8_t BMI160_SetGyroDLPFMode(BMI160DLPFMode mode) {
	return BMI160_WriteRegisterBits(BMI160_RA_GYRO_CONF, mode, BMI160_GYRO_DLPF_SEL_BIT, BMI160_GYRO_DLPF_SEL_LEN);
}

BMI160DLPFMode BMI160_GetAccelDLPFMode(void) {
    return (BMI160DLPFMode)BMI160_ReadRegBits(BMI160_RA_ACCEL_CONF, BMI160_ACCEL_DLPF_SEL_BIT, BMI160_ACCEL_DLPF_SEL_LEN);
}

int8_t BMI160_SetAccelDLPFMode(BMI160DLPFMode mode) {
    return BMI160_WriteRegisterBits(BMI160_RA_ACCEL_CONF, mode, BMI160_ACCEL_DLPF_SEL_BIT, BMI160_ACCEL_DLPF_SEL_LEN);
}

BMI160GyroRange BMI160_GetFullScaleGyroRange(void) {
	return (BMI160GyroRange)BMI160_ReadRegBits(BMI160_RA_GYRO_RANGE, BMI160_GYRO_RANGE_SEL_BIT, BMI160_GYRO_RANGE_SEL_LEN);
}

int8_t BMI160_SetFullScaleGyroRange(const BMI160GyroRange range) {
    return BMI160_WriteRegisterBits(BMI160_RA_GYRO_RANGE, (uint8_t)range, BMI160_GYRO_RANGE_SEL_BIT, BMI160_GYRO_RANGE_SEL_LEN);
}

BMI160AccelRange BMI160_GetFullScaleAccelRange(void) {
	return (BMI160AccelRange)BMI160_ReadRegBits(BMI160_RA_ACCEL_RANGE, BMI160_ACCEL_RANGE_SEL_BIT, BMI160_ACCEL_RANGE_SEL_LEN);
}

int8_t BMI160_SetFullScaleAccelRange(const BMI160AccelRange range) {
	return BMI160_WriteRegisterBits(BMI160_RA_ACCEL_RANGE, (uint8_t)range, BMI160_ACCEL_RANGE_SEL_BIT, BMI160_ACCEL_RANGE_SEL_LEN);
}

uint8_t BMI160_GetAccelOffsetEnabled(void) {
    return !!(BMI160_ReadRegBits(BMI160_RA_OFFSET_6, BMI160_ACC_OFFSET_EN, 1));
}

int8_t BMI160_SetAccelOffsetEnabled(const uint8_t enabled) {
	return BMI160_WriteRegisterBits(BMI160_RA_OFFSET_6, enabled ? 0x1 : 0, BMI160_ACC_OFFSET_EN, 1);
}

int8_t BMI160_AutoCalibrateXAccelOffset(int target)
{
    uint8_t foc_conf = 0;
    if (target == 1) { foc_conf = (0x1 << BMI160_FOC_ACC_X_BIT); }
    else if (target == -1) { foc_conf = (0x2 << BMI160_FOC_ACC_X_BIT); }
    else if (target == 0) { foc_conf = (0x3 << BMI160_FOC_ACC_X_BIT); }
    else { return -1; }

    BMI160_WriteRegister(BMI160_RA_FOC_CONF, foc_conf);
    BMI160_WriteRegister(BMI160_RA_CMD, BMI160_CMD_START_FOC);

    while (!(BMI160_ReadRegBits(BMI160_RA_STATUS, BMI160_STATUS_FOC_RDY, 1)))
    {
    	LL_mDelay(1);
    }

    return 0;
}

int8_t BMI160_AutoCalibrateYAccelOffset(int target) {
    uint8_t foc_conf = 0;
    if (target == 1) { foc_conf = (0x1 << BMI160_FOC_ACC_Y_BIT); }
    else if (target == -1) { foc_conf = (0x2 << BMI160_FOC_ACC_Y_BIT); }
    else if (target == 0) { foc_conf = (0x3 << BMI160_FOC_ACC_Y_BIT); }
    else { return -1; }

    BMI160_WriteRegister(BMI160_RA_FOC_CONF, foc_conf);
    BMI160_WriteRegister(BMI160_RA_CMD, BMI160_CMD_START_FOC);\
    while (!(BMI160_ReadRegBits(BMI160_RA_STATUS, BMI160_STATUS_FOC_RDY, 1)))
    {
    	LL_mDelay(1);
    }

    return 0;
}

int8_t BMI160_AutoCalibrateZAccelOffset(int target) {
    uint8_t foc_conf;
    if (target == 1) { foc_conf = (0x1 << BMI160_FOC_ACC_Z_BIT); }
    else if (target == -1) { foc_conf = (0x2 << BMI160_FOC_ACC_Z_BIT); }
    else if (target == 0) { foc_conf = (0x3 << BMI160_FOC_ACC_Z_BIT); }
    else { return -1; }

    BMI160_WriteRegister(BMI160_RA_FOC_CONF, foc_conf);
    BMI160_WriteRegister(BMI160_RA_CMD, BMI160_CMD_START_FOC);
    while (!(BMI160_ReadRegBits(BMI160_RA_STATUS, BMI160_STATUS_FOC_RDY, 1)))
    {
    	LL_mDelay(1);
    }

    return 0;
}

int8_t BMI160_GetXAccelOffset(uint8_t *accelOffset) {
	uint8_t readData = 0;
	int8_t opStatus = BMI160_ReadRegister(BMI160_RA_OFFSET_0, 1, &readData);

	if(opStatus != 0) {
		return opStatus;
	}

	*(accelOffset + 0) = readData;

    return opStatus;
}

int8_t BMI160_SetXAccelOffset(int8_t offset)
{
	int8_t opStatus = BMI160_WriteRegister(BMI160_RA_OFFSET_0, offset);
    return opStatus;
}

int8_t BMI160_GetYAccelOffset(uint8_t *accelOffset) {
	uint8_t readData = 0;
	int8_t opStatus = BMI160_ReadRegister(BMI160_RA_OFFSET_1, 1, &readData);

	if(opStatus != 0) {
		return opStatus;
	}

	*(accelOffset + 0) = readData;

    return opStatus;
}

int8_t BMI160_SetYAccelOffset(int8_t offset) {
	return BMI160_WriteRegister(BMI160_RA_OFFSET_1, offset);
}

int8_t BMI160_GetZAccelOffset(uint8_t *accelOffset) {
	uint8_t readData = 0;
	int8_t opStatus = BMI160_ReadRegister(BMI160_RA_OFFSET_2, 1, &readData);

	if(opStatus != 0) {
		return opStatus;
	}

	*(accelOffset + 0) = readData;

    return opStatus;
}

int8_t BMI160_SetZAccelOffset(int8_t offset) {
	return BMI160_WriteRegister(BMI160_RA_OFFSET_2, offset);
}

uint8_t BMI160_GetGyroOffsetEnabled(void) {
    return !!(BMI160_ReadRegBits(BMI160_RA_OFFSET_6, BMI160_GYR_OFFSET_EN, 1));
}

int8_t BMI160_SetGyroOffsetEnabled(uint8_t enabled) {
	return BMI160_WriteRegisterBits(BMI160_RA_OFFSET_6, enabled ? 0x1 : 0, BMI160_GYR_OFFSET_EN, 1);
}

int8_t BMI160_AutoCalibrateGyroOffset(void) {
    uint8_t foc_conf = (1 << BMI160_FOC_GYR_EN);

    int8_t opStatus = BMI160_WriteRegister(BMI160_RA_FOC_CONF, foc_conf);
	if(opStatus != 0) { return opStatus; }
	opStatus = BMI160_WriteRegister(BMI160_RA_CMD, BMI160_CMD_START_FOC);
	if(opStatus != 0) { return opStatus; }

    while (!(BMI160_ReadRegBits(BMI160_RA_STATUS, BMI160_STATUS_FOC_RDY, 1)))
    {
    	LL_mDelay(1);
    }

    return 0;
}

int8_t BMI160_GetXGyroOffset(int16_t *gyrOffset) {
	uint8_t readData = 0;
	int8_t opStatus = BMI160_ReadRegister(BMI160_RA_OFFSET_3, 1, &readData);

	if(opStatus != 0){ return opStatus; }

	int16_t offset = readData;
	offset |= (int16_t)(BMI160_ReadRegBits(BMI160_RA_OFFSET_6, BMI160_GYR_OFFSET_X_MSB_BIT, BMI160_GYR_OFFSET_X_MSB_LEN)) << 8;
	*(gyrOffset + 0) =  (int16_t)BMI160_SIGN_EXTEND(offset, 10);

    return opStatus;
}

int8_t BMI160_SetXGyroOffset(int16_t offset) {
	int8_t opStatus = BMI160_WriteRegister(BMI160_RA_OFFSET_3, offset);

	if(opStatus != 0) { return opStatus; }

	opStatus = BMI160_WriteRegisterBits(BMI160_RA_OFFSET_6, offset >> 8, BMI160_GYR_OFFSET_X_MSB_BIT, BMI160_GYR_OFFSET_X_MSB_LEN);

	return opStatus;
}

int8_t BMI160_GetYGyroOffset(int16_t *gyrOffset) {
	uint8_t readData = 0;

	int8_t opStatus = BMI160_ReadRegister(BMI160_RA_OFFSET_4, 1, &readData);

	if(opStatus != 0){
		return opStatus;
	}

	int16_t offset = readData;
    offset |= (int16_t)(BMI160_ReadRegBits(BMI160_RA_OFFSET_6, BMI160_GYR_OFFSET_Y_MSB_BIT, BMI160_GYR_OFFSET_Y_MSB_LEN)) << 8;
	*(gyrOffset + 0) =  (int16_t)BMI160_SIGN_EXTEND(offset, 10);

    return opStatus;
}

int8_t BMI160_SetYGyroOffset(int16_t offset) {
	int8_t opStatus = BMI160_WriteRegister(BMI160_RA_OFFSET_4, offset);

	if(opStatus != 0) { return opStatus; }

	opStatus = BMI160_WriteRegisterBits(BMI160_RA_OFFSET_6, offset >> 8, BMI160_GYR_OFFSET_X_MSB_BIT, BMI160_GYR_OFFSET_X_MSB_LEN);

	return opStatus;
}

int8_t BMI160_GetZGyroOffset(int16_t *gyrOffset) {
	uint8_t readData = 0;
	int8_t opStatus = BMI160_ReadRegister(BMI160_RA_OFFSET_5, 1, &readData);

	if(opStatus != 0){
		return opStatus;
	}

	int16_t offset = readData;

    offset |= (int16_t)(BMI160_ReadRegBits(BMI160_RA_OFFSET_6, BMI160_GYR_OFFSET_Z_MSB_BIT, BMI160_GYR_OFFSET_Z_MSB_LEN)) << 8;
	*(gyrOffset + 0) =  (int16_t)BMI160_SIGN_EXTEND(offset, 10);

    return opStatus;
}

int8_t BMI160_SetZGyroOffset(int16_t offset) {
	int8_t opStatus = BMI160_WriteRegister(BMI160_RA_OFFSET_5, offset);

	if(opStatus != 0) { return opStatus; }

	opStatus = BMI160_WriteRegisterBits(BMI160_RA_OFFSET_6, offset >> 8, BMI160_GYR_OFFSET_Z_MSB_BIT, BMI160_GYR_OFFSET_Z_MSB_LEN);

	return opStatus;
}

uint8_t BMI160_GetFreefallDetectionThreshold(uint8_t *freeFallDetectPtr) {
	uint8_t readData = 0;
	int8_t opStatus = BMI160_ReadRegister(BMI160_RA_INT_LOWHIGH_1, 1, &readData);

	if(opStatus != 0) { return opStatus; }

	*(freeFallDetectPtr + 0) = readData;

    return opStatus;
}

int8_t BMI160_SetFreefallDetectionThreshold(uint8_t threshold) {
	return BMI160_WriteRegister(BMI160_RA_INT_LOWHIGH_1, threshold);
}

int8_t BMI160_GetFreefallDetectionDuration(uint8_t *freeFallDetectPtr) {
	uint8_t readData = 0;
	int8_t opStatus = BMI160_ReadRegister(BMI160_RA_INT_LOWHIGH_0, 1, &readData);

	if(opStatus != 0) {
		return opStatus;
	}

	*(freeFallDetectPtr + 0) = readData;

    return opStatus;
}

int8_t BMI160_SetFreefallDetectionDuration(uint8_t duration) {
	return BMI160_WriteRegister(BMI160_RA_INT_LOWHIGH_0, duration);
}

int8_t BMI160_GetShockDetectionThreshold(uint8_t *shockDetectTreshPtr) {
	uint8_t readData = 0;
	int8_t opStatus = BMI160_ReadRegister(BMI160_RA_INT_LOWHIGH_4, 1, &readData);

	if(opStatus != 0) {
		return opStatus;
	}

	*(shockDetectTreshPtr + 0) = readData;

    return opStatus;
}

uint8_t BMI160_SetShockDetectionThreshold(uint8_t threshold) {
	return BMI160_WriteRegister(BMI160_RA_INT_LOWHIGH_4, threshold);
}

uint8_t BMI160_GetShockDetectionDuration(uint8_t *shockDetectDuratPtr) {
	uint8_t readData = 0;
	int8_t opStatus = BMI160_ReadRegister(BMI160_RA_INT_LOWHIGH_3, 1, &readData);

	if(opStatus != 0) {
		return opStatus;
	}

	*(shockDetectDuratPtr + 0) = readData;

    return opStatus;
}

int8_t BMI160_SetShockDetectionDuration(uint8_t duration) {
	return BMI160_WriteRegister(BMI160_RA_INT_LOWHIGH_3, duration);
}

int8_t BMI160_GetStepDetectionMode(uint8_t *stepModePtr) {
    uint8_t ret_step_conf0 = 0;
    uint8_t ret_min_step_buf = 0;

    int8_t opStatus = BMI160_ReadRegister(BMI160_RA_STEP_CONF_0, 1, &ret_step_conf0);
	if(opStatus != 0) { return opStatus; }
	opStatus = BMI160_ReadRegister(BMI160_RA_STEP_CONF_1, 1, &ret_min_step_buf);
	if(opStatus != 0) { return opStatus; }

    if ((ret_step_conf0 == BMI160_RA_STEP_CONF_0_NOR) && (ret_min_step_buf == BMI160_RA_STEP_CONF_1_NOR))
    {
    	*(stepModePtr + 0) = BMI160_STEP_MODE_NORMAL;
    }
    else if ((ret_step_conf0 == BMI160_RA_STEP_CONF_0_SEN) && (ret_min_step_buf == BMI160_RA_STEP_CONF_1_SEN))
	{
    	*(stepModePtr + 0) = BMI160_STEP_MODE_SENSITIVE;
	}
    else if ((ret_step_conf0 == BMI160_RA_STEP_CONF_0_ROB) && (ret_min_step_buf == BMI160_RA_STEP_CONF_1_ROB))
    {
    	*(stepModePtr + 0) = BMI160_STEP_MODE_ROBUST;
    }
    else
    {
    	*(stepModePtr + 0) = BMI160_STEP_MODE_UNKNOWN;
    }

    return opStatus;
}

int8_t BMI160_SetStepDetectionMode(const BMI160StepMode mode) {
    uint8_t step_conf0 = 0;
    uint8_t min_step_buf = 0;

    switch (mode)
    {
		case BMI160_STEP_MODE_NORMAL:
			step_conf0 = 0x15;
			min_step_buf = 0x3;
			break;
		case BMI160_STEP_MODE_SENSITIVE:
			step_conf0 = 0x2D;
			min_step_buf = 0x0;
			break;
		case BMI160_STEP_MODE_ROBUST:
			step_conf0 = 0x1D;
			min_step_buf = 0x7;
			break;
		default:
			return (-10);
    };

    int8_t opStatus = BMI160_WriteRegister(BMI160_RA_STEP_CONF_0, step_conf0);
	if(opStatus != 0) { return opStatus; }
	opStatus = BMI160_WriteRegisterBits(BMI160_RA_STEP_CONF_1, min_step_buf, BMI160_STEP_BUF_MIN_BIT, BMI160_STEP_BUF_MIN_LEN);

    return opStatus;
}

uint8_t BMI160_GetStepCountEnabled(void) {
    return !!(BMI160_ReadRegBits(BMI160_RA_STEP_CONF_1, BMI160_STEP_CNT_EN_BIT, 1));
}

int8_t BMI160_SetStepCountEnabled(const uint8_t enabled) {
    return BMI160_WriteRegisterBits(BMI160_RA_STEP_CONF_1, enabled ? 0x1 : 0, BMI160_STEP_CNT_EN_BIT, 1);
}

uint16_t BMI160_GetStepCount(uint16_t *stepCountPtr) {
    uint8_t buffer[2];
    buffer[0] = BMI160_RA_STEP_CNT_L;

    int8_t opStat = BMI160_ReadRegister(BMI160_RA_STEP_CNT_L, 6, &buffer[0]);

    if(opStat != 0) { return opStat; }

    *(stepCountPtr + 0) = (((uint16_t)buffer[1]) << 8) | buffer[0];

    return opStat;
}

int8_t BMI160_ResetStepCount(void) {
	return BMI160_WriteRegister(BMI160_RA_CMD, BMI160_CMD_STEP_CNT_CLR);
}

int8_t BMI160_GetMotionDetectionThreshold(uint8_t * motionDetectTreshPtr) {
	uint8_t readData = 0;
	int8_t opStatus = BMI160_ReadRegister(BMI160_RA_INT_MOTION_1, 1, &readData);

	if(opStatus != 0) {
		return opStatus;
	}

	*(motionDetectTreshPtr + 0) = readData;

    return opStatus;
}

int8_t BMI160_SetMotionDetectionThreshold(const uint8_t threshold) {
    return BMI160_WriteRegister(BMI160_RA_INT_MOTION_1, threshold);
}

uint8_t BMI160_GetMotionDetectionDuration(void) {
    return (1 + BMI160_ReadRegBits(BMI160_RA_INT_MOTION_0, BMI160_ANYMOTION_DUR_BIT, BMI160_ANYMOTION_DUR_LEN));
}

int8_t BMI160_SetMotionDetectionDuration(const uint8_t samples) {
	return BMI160_WriteRegisterBits(BMI160_RA_INT_MOTION_0, samples - 1, BMI160_ANYMOTION_DUR_BIT, BMI160_ANYMOTION_DUR_LEN);
}

int8_t BMI160_GetZeroMotionDetectionThreshold(uint8_t * zeroMotionDetectTreshPtr) {
	uint8_t readData = 0;
	int8_t opStatus = BMI160_ReadRegister(BMI160_RA_INT_MOTION_2, 1, &readData);

	if(opStatus != 0) {
		return opStatus;
	}

	*(zeroMotionDetectTreshPtr + 0) = readData;

    return readData;
}

int8_t BMI160_SetZeroMotionDetectionThreshold(const uint8_t threshold) {
    return BMI160_WriteRegister(BMI160_RA_INT_MOTION_2, threshold);
}

uint8_t BMI160_GetZeroMotionDetectionDuration(void) {
    return BMI160_ReadRegBits(BMI160_RA_INT_MOTION_0, BMI160_NOMOTION_DUR_BIT, BMI160_NOMOTION_DUR_LEN);
}

int8_t BMI160_SetZeroMotionDetectionDuration(const uint8_t duration) {
	return BMI160_WriteRegisterBits(BMI160_RA_INT_MOTION_0, duration, BMI160_NOMOTION_DUR_BIT, BMI160_NOMOTION_DUR_LEN);
}

uint8_t BMI160_GetTapDetectionThreshold(void) {
    return BMI160_ReadRegBits(BMI160_RA_INT_TAP_1, BMI160_TAP_THRESH_BIT, BMI160_TAP_THRESH_LEN);
}

int8_t BMI160_SetTapDetectionThreshold(const uint8_t threshold) {
	return BMI160_WriteRegisterBits(BMI160_RA_INT_TAP_1, threshold, BMI160_TAP_THRESH_BIT, BMI160_TAP_THRESH_LEN);
}

uint8_t BMI160_GetTapShockDuration(void) {
    return !!(BMI160_ReadRegBits(BMI160_RA_INT_TAP_0, BMI160_TAP_SHOCK_BIT, 1));
}
