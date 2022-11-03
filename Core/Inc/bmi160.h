#ifndef __BMI160_H
#define __BMI160_H

#include "main.h"
#include "bmi160_defines.h"

int8_t BMI160_Initialize(void);
int8_t BMI160_ReadChipID(uint8_t *chipId);
uint8_t BMI160_CheckSensorID(void);
int8_t BMI160_PerformSoftReset(void);
int8_t BMI160_PowerUpAccelerometer(void);
int8_t BMI160_PowerUpGyroscope(void);
int8_t BMI160_ReadGyro(int16_t* x, int16_t* y, int16_t* z);
float BMI160_ScaledData(const int16_t gRaw, const BMI160GyroRange gyroRange);
int8_t BMI160_GetTemperature(int16_t *temp);
float BMI160_ConvertRawTemp(int16_t tempRaw);
int8_t BMI160_GetAccelerationX(int16_t *accel);
int8_t BMI160_GetAccelerationY(int16_t *accel);
int8_t BMI160_GetAccelerationZ(int16_t *accel);
int8_t BMI160_GetAcceleration(int16_t* x, int16_t* y, int16_t* z);
int8_t BMI160_GetMotion6(int16_t* ax, int16_t* ay, int16_t* az, int16_t* gx, int16_t* gy, int16_t* gz);
BMI160GyroRate BMI160_GetGyroRate(void);
int8_t BMI160_SetGyroRate(const BMI160GyroRate rate);
BMI160AccelRate BMI160_GetAccelRate(void);
int8_t BMI160_SetAccelRate(const BMI160AccelRate rate);
BMI160DLPFMode BMI160_GetGyroDLPFMode(void);
BMI160DLPFMode BMI160_GetAccelDLPFMode(void);
int8_t BMI160_SetAccelDLPFMode(BMI160DLPFMode mode);
BMI160GyroRange BMI160_GetFullScaleGyroRange(void);
int8_t BMI160_SetFullScaleGyroRange(const BMI160GyroRange range);
BMI160AccelRange BMI160_GetFullScaleAccelRange(void);
int8_t BMI160_SetFullScaleAccelRange(const BMI160AccelRange range);
uint8_t BMI160_GetAccelOffsetEnabled(void);
int8_t BMI160_SetAccelOffsetEnabled(const uint8_t enabled);
int8_t BMI160_AutoCalibrateXAccelOffset(int target);
int8_t BMI160_AutoCalibrateYAccelOffset(int target);
int8_t BMI160_AutoCalibrateZAccelOffset(int target);
int8_t BMI160_GetXAccelOffset(uint8_t *accelOffset);
int8_t BMI160_SetXAccelOffset(int8_t offset);
int8_t BMI160_GetYAccelOffset(uint8_t *accelOffset);
int8_t BMI160_SetYAccelOffset(int8_t offset);
int8_t BMI160_GetZAccelOffset(uint8_t *accelOffset);
int8_t BMI160_SetZAccelOffset(int8_t offset);
uint8_t BMI160_GetGyroOffsetEnabled(void);
int8_t BMI160_SetGyroOffsetEnabled(uint8_t enabled);
int8_t BMI160_AutoCalibrateGyroOffset(void);
int8_t BMI160_GetXGyroOffset(int16_t *gyrOffset);
int8_t BMI160_SetXGyroOffset(int16_t offset);
int8_t BMI160_GetYGyroOffset(int16_t *gyrOffset);
int8_t BMI160_SetYGyroOffset(int16_t offset);
int8_t BMI160_GetZGyroOffset(int16_t *gyrOffset);
int8_t BMI160_SetZGyroOffset(int16_t offset);
uint8_t BMI160_GetFreefallDetectionThreshold(uint8_t *freeFallDetectPtr);
int8_t BMI160_SetFreefallDetectionThreshold(uint8_t threshold);
int8_t BMI160_GetFreefallDetectionDuration(uint8_t *freeFallDetectPtr);
int8_t BMI160_SetFreefallDetectionDuration(uint8_t duration);
int8_t BMI160_GetShockDetectionThreshold(uint8_t *shockDetectTreshPtr);
uint8_t BMI160_GetShockDetectionDuration(uint8_t *shockDetectDuratPtr);
int8_t BMI160_SetShockDetectionDuration(uint8_t duration);
int8_t BMI160_GetStepDetectionMode(uint8_t *stepModePtr);
int8_t BMI160_SetStepDetectionMode(const BMI160StepMode mode);
uint8_t BMI160_GetStepCountEnabled(void);
int8_t BMI160_SetStepCountEnabled(const uint8_t enabled);
uint16_t BMI160_GetStepCount(uint16_t *stepCountPtr);
int8_t BMI160_GetMotionDetectionThreshold(uint8_t * motionDetectTreshPtr);
int8_t BMI160_SetMotionDetectionThreshold(const uint8_t threshold);
uint8_t BMI160_GetMotionDetectionDuration(void);
int8_t BMI160_SetMotionDetectionDuration(const uint8_t samples);
int8_t BMI160_GetZeroMotionDetectionThreshold(uint8_t * zeroMotionDetectTreshPtr);
int8_t BMI160_SetZeroMotionDetectionThreshold(const uint8_t threshold);
uint8_t BMI160_GetZeroMotionDetectionDuration(void);
int8_t BMI160_SetZeroMotionDetectionDuration(const uint8_t duration);
uint8_t BMI160_GetTapDetectionThreshold(void);
int8_t BMI160_SetTapDetectionThreshold(const uint8_t threshold);
uint8_t BMI160_GetTapShockDuration(void);

#endif


