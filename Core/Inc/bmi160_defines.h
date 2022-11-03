#ifndef __BMI160_DEFINES_H
#define __BMI160_DEFINES_H

#define BMI160_I2C_ADDR	(0x69 << 1)

#define BMI160_SPI_READ_BIT         7

#define SENS_2000_DPS_LSB_PER_DPS 	16.4F
#define SENS_1000_DPS_LSB_PER_DPS 	32.8F
#define SENS_500_DPS_LSB_PER_DPS 	65.6F
#define SENS_250_DPS_LSB_PER_DPS 	131.2F
#define SENS_125_DPS_LSB_PER_DPS 	262.4F

#define SENSOR_CHIP_ID_BMI160 		(0xD0)		//BMI160/162AB
#define SENSOR_CHIP_ID_BMI160_C2 	(0xD1)		//BMI160C2
#define SENSOR_CHIP_ID_BMI160_C3 	(0xD3)		//BMI160C3

#define BMI160_RA_CHIP_ID           0x00

#define BMI160_ACC_PMU_STATUS_BIT   4
#define BMI160_ACC_PMU_STATUS_LEN   2
#define BMI160_GYR_PMU_STATUS_BIT   2
#define BMI160_GYR_PMU_STATUS_LEN   2

#define BMI160_RA_PMU_STATUS        0x03

#define BMI160_RA_GYRO_X_L          0x0C
#define BMI160_RA_GYRO_X_H          0x0D
#define BMI160_RA_GYRO_Y_L          0x0E
#define BMI160_RA_GYRO_Y_H          0x0F
#define BMI160_RA_GYRO_Z_L          0x10
#define BMI160_RA_GYRO_Z_H          0x11
#define BMI160_RA_ACCEL_X_L         0x12
#define BMI160_RA_ACCEL_X_H         0x13
#define BMI160_RA_ACCEL_Y_L         0x14
#define BMI160_RA_ACCEL_Y_H         0x15
#define BMI160_RA_ACCEL_Z_L         0x16
#define BMI160_RA_ACCEL_Z_H         0x17

#define BMI160_STATUS_FOC_RDY       3
#define BMI160_STATUS_NVM_RDY       4
#define BMI160_STATUS_DRDY_GYR      6
#define BMI160_STATUS_DRDY_ACC      7

#define BMI160_RA_STATUS            0x1B

#define BMI160_STEP_INT_BIT         0
#define BMI160_ANYMOTION_INT_BIT    2
#define BMI160_D_TAP_INT_BIT        4
#define BMI160_S_TAP_INT_BIT        5
#define BMI160_NOMOTION_INT_BIT     7
#define BMI160_FFULL_INT_BIT        5
#define BMI160_DRDY_INT_BIT         4
#define BMI160_LOW_G_INT_BIT        3
#define BMI160_HIGH_G_INT_BIT       2

#define BMI160_TAP_SIGN_BIT         7
#define BMI160_TAP_1ST_Z_BIT        6
#define BMI160_TAP_1ST_Y_BIT        5
#define BMI160_TAP_1ST_X_BIT        4

#define BMI160_ANYMOTION_SIGN_BIT   3
#define BMI160_ANYMOTION_1ST_Z_BIT  2
#define BMI160_ANYMOTION_1ST_Y_BIT  1
#define BMI160_ANYMOTION_1ST_X_BIT  0

#define BMI160_HIGH_G_SIGN_BIT      3
#define BMI160_HIGH_G_1ST_Z_BIT     2
#define BMI160_HIGH_G_1ST_Y_BIT     1
#define BMI160_HIGH_G_1ST_X_BIT     0

#define BMI160_RA_INT_STATUS_0      0x1C
#define BMI160_RA_INT_STATUS_1      0x1D
#define BMI160_RA_INT_STATUS_2      0x1E
#define BMI160_RA_INT_STATUS_3      0x1F

#define BMI160_RA_TEMP_L            0x20
#define BMI160_RA_TEMP_H            0x21

#define BMI160_RA_FIFO_LENGTH_0     0x22
#define BMI160_RA_FIFO_LENGTH_1     0x23

#define BMI160_FIFO_DATA_INVALID    0x80
#define BMI160_RA_FIFO_DATA         0x24

#define BMI160_ACCEL_RATE_SEL_BIT    0
#define BMI160_ACCEL_RATE_SEL_LEN    4

#define BMI160_RA_ACCEL_CONF        0x40
#define BMI160_RA_ACCEL_RANGE       0x41

#define BMI160_GYRO_RATE_SEL_BIT    0
#define BMI160_GYRO_RATE_SEL_LEN    4

#define BMI160_RA_GYRO_CONF         0x42
#define BMI160_RA_GYRO_RANGE        0x43

#define BMI160_FIFO_HEADER_EN_BIT   4
#define BMI160_FIFO_ACC_EN_BIT      6
#define BMI160_FIFO_GYR_EN_BIT      7

#define BMI160_RA_FIFO_CONFIG_0     0x46
#define BMI160_RA_FIFO_CONFIG_1     0x47

#define BMI160_ANYMOTION_EN_BIT     0
#define BMI160_ANYMOTION_EN_LEN     3
#define BMI160_D_TAP_EN_BIT         4
#define BMI160_S_TAP_EN_BIT         5
#define BMI160_NOMOTION_EN_BIT      0
#define BMI160_NOMOTION_EN_LEN      3
#define BMI160_LOW_G_EN_BIT         3
#define BMI160_LOW_G_EN_LEN         1
#define BMI160_HIGH_G_EN_BIT        0
#define BMI160_HIGH_G_EN_LEN        3

#define BMI160_STEP_EN_BIT          3
#define BMI160_DRDY_EN_BIT          4
#define BMI160_FFULL_EN_BIT         5

#define BMI160_RA_INT_EN_0          0x50
#define BMI160_RA_INT_EN_1          0x51
#define BMI160_RA_INT_EN_2          0x52

#define BMI160_INT1_EDGE_CTRL       0
#define BMI160_INT1_LVL             1
#define BMI160_INT1_OD              2
#define BMI160_INT1_OUTPUT_EN       3

#define BMI160_RA_INT_OUT_CTRL      0x53

#define BMI160_LATCH_MODE_BIT       0
#define BMI160_LATCH_MODE_LEN       4

#define BMI160_RA_INT_LATCH         0x54
#define BMI160_RA_INT_MAP_0         0x55
#define BMI160_RA_INT_MAP_1         0x56
#define BMI160_RA_INT_MAP_2         0x57

#define BMI160_ANYMOTION_DUR_BIT    0
#define BMI160_ANYMOTION_DUR_LEN    2
#define BMI160_NOMOTION_DUR_BIT     2
#define BMI160_NOMOTION_DUR_LEN     6

#define BMI160_NOMOTION_SEL_BIT     0
#define BMI160_NOMOTION_SEL_LEN     1

#define BMI160_RA_INT_LOWHIGH_0     0x5A
#define BMI160_RA_INT_LOWHIGH_1     0x5B
#define BMI160_RA_INT_LOWHIGH_2     0x5C
#define BMI160_RA_INT_LOWHIGH_3     0x5D
#define BMI160_RA_INT_LOWHIGH_4     0x5E

#define BMI160_RA_INT_MOTION_0      0x5F
#define BMI160_RA_INT_MOTION_1      0x60
#define BMI160_RA_INT_MOTION_2      0x61
#define BMI160_RA_INT_MOTION_3      0x62

#define BMI160_TAP_DUR_BIT          0
#define BMI160_TAP_DUR_LEN          3
#define BMI160_TAP_SHOCK_BIT        6
#define BMI160_TAP_QUIET_BIT        7
#define BMI160_TAP_THRESH_BIT       0
#define BMI160_TAP_THRESH_LEN       5

#define BMI160_RA_INT_TAP_0         0x63
#define BMI160_RA_INT_TAP_1         0x64

#define BMI160_FOC_ACC_Z_BIT        0
#define BMI160_FOC_ACC_Z_LEN        2
#define BMI160_FOC_ACC_Y_BIT        2
#define BMI160_FOC_ACC_Y_LEN        2
#define BMI160_FOC_ACC_X_BIT        4
#define BMI160_FOC_ACC_X_LEN        2
#define BMI160_FOC_GYR_EN           6

#define BMI160_RA_FOC_CONF          0x69

#define BMI160_GYR_OFFSET_X_MSB_BIT 0
#define BMI160_GYR_OFFSET_X_MSB_LEN 2
#define BMI160_GYR_OFFSET_Y_MSB_BIT 2
#define BMI160_GYR_OFFSET_Y_MSB_LEN 2
#define BMI160_GYR_OFFSET_Z_MSB_BIT 4
#define BMI160_GYR_OFFSET_Z_MSB_LEN 2
#define BMI160_ACC_OFFSET_EN        6
#define BMI160_GYR_OFFSET_EN        7

#define BMI160_RA_OFFSET_0          0x71
#define BMI160_RA_OFFSET_1          0x72
#define BMI160_RA_OFFSET_2          0x73
#define BMI160_RA_OFFSET_3          0x74
#define BMI160_RA_OFFSET_4          0x75
#define BMI160_RA_OFFSET_5          0x76
#define BMI160_RA_OFFSET_6          0x77

#define BMI160_RA_STEP_CNT_L        0x78
#define BMI160_RA_STEP_CNT_H        0x79

#define BMI160_STEP_BUF_MIN_BIT     0
#define BMI160_STEP_BUF_MIN_LEN     3
#define BMI160_STEP_CNT_EN_BIT      3

#define BMI160_STEP_TIME_MIN_BIT    0
#define BMI160_STEP_TIME_MIN_LEN    3
#define BMI160_STEP_THRESH_MIN_BIT  3
#define BMI160_STEP_THRESH_MIN_LEN  2
#define BMI160_STEP_ALPHA_BIT       5
#define BMI160_STEP_ALPHA_LEN       3

#define BMI160_RA_STEP_CONF_0       0x7A
#define BMI160_RA_STEP_CONF_1       0x7B

#define BMI160_RA_STEP_CONF_0_NOR   0x15
#define BMI160_RA_STEP_CONF_0_SEN   0x2D
#define BMI160_RA_STEP_CONF_0_ROB   0x1D
#define BMI160_RA_STEP_CONF_1_NOR   0x03
#define BMI160_RA_STEP_CONF_1_SEN   0x00
#define BMI160_RA_STEP_CONF_1_ROB   0x07


#define BMI160_GYRO_RANGE_SEL_BIT   0
#define BMI160_GYRO_RANGE_SEL_LEN   3

#define BMI160_GYRO_RATE_SEL_BIT    0
#define BMI160_GYRO_RATE_SEL_LEN    4

#define BMI160_GYRO_DLPF_SEL_BIT    4
#define BMI160_GYRO_DLPF_SEL_LEN    2

#define BMI160_ACCEL_DLPF_SEL_BIT   4
#define BMI160_ACCEL_DLPF_SEL_LEN   3

#define BMI160_ACCEL_RANGE_SEL_BIT  0
#define BMI160_ACCEL_RANGE_SEL_LEN  4

#define BMI160_CMD_START_FOC        0x03
#define BMI160_CMD_ACC_MODE_NORMAL  0x11
#define BMI160_CMD_GYR_MODE_NORMAL  0x15
#define BMI160_CMD_FIFO_FLUSH       0xB0
#define BMI160_CMD_INT_RESET        0xB1
#define BMI160_CMD_STEP_CNT_CLR     0xB2
#define BMI160_CMD_SOFT_RESET       0xB6

#define BMI160_RA_CMD               0x7E

#define BMI160_ACCEL_BW_MASK                      (0x70)
#define BMI160_ACCEL_ODR_MASK                     (0x0F)
#define BMI160_ACCEL_UNDERSAMPLING_MASK           (0x80)
#define BMI160_ACCEL_RANGE_MASK                   (0x0F)
#define BMI160_GYRO_BW_MASK                       (0x30)
#define BMI160_GYRO_ODR_MASK                      (0x0F)
#define BMI160_GYRO_RANGE_MASK                    (0x07)

#define BMI160_ACCEL_BW_POS                       (4)
#define BMI160_GYRO_BW_POS                        (4)

/** Mask definitions for INT_EN registers */
#define BMI160_ANY_MOTION_X_INT_EN_MASK           (0x01)
#define BMI160_HIGH_G_X_INT_EN_MASK               (0x01)
#define BMI160_NO_MOTION_X_INT_EN_MASK            (0x01)
#define BMI160_ANY_MOTION_Y_INT_EN_MASK           (0x02)
#define BMI160_HIGH_G_Y_INT_EN_MASK               (0x02)
#define BMI160_NO_MOTION_Y_INT_EN_MASK            (0x02)
#define BMI160_ANY_MOTION_Z_INT_EN_MASK           (0x04)
#define BMI160_HIGH_G_Z_INT_EN_MASK               (0x04)
#define BMI160_NO_MOTION_Z_INT_EN_MASK            (0x04)
#define BMI160_SIG_MOTION_INT_EN_MASK             (0x07)
#define BMI160_ANY_MOTION_ALL_INT_EN_MASK         (0x07)
#define BMI160_STEP_DETECT_INT_EN_MASK            (0x08)
#define BMI160_DOUBLE_TAP_INT_EN_MASK             (0x10)
#define BMI160_SINGLE_TAP_INT_EN_MASK             (0x20)
#define BMI160_FIFO_FULL_INT_EN_MASK              (0x20)
#define BMI160_ORIENT_INT_EN_MASK                 (0x40)
#define BMI160_FIFO_WATERMARK_INT_EN_MASK         (0x40)
#define BMI160_LOW_G_INT_EN_MASK                  (0x08)
#define BMI160_STEP_DETECT_EN_MASK                (0x08)
#define BMI160_FLAT_INT_EN_MASK                   (0x80)
#define BMI160_DATA_RDY_INT_EN_MASK               (0x10)

/** PMU status Macros */
#define BMI160_AUX_PMU_SUSPEND                    (0x00)
#define BMI160_AUX_PMU_NORMAL                     (0x01)
#define BMI160_AUX_PMU_LOW_POWER                  (0x02)

#define BMI160_GYRO_PMU_SUSPEND                   (0x00)
#define BMI160_GYRO_PMU_NORMAL                    (0x01)
#define BMI160_GYRO_PMU_FSU                       (0x03)

#define BMI160_ACCEL_PMU_SUSPEND                  (0x00)
#define BMI160_ACCEL_PMU_NORMAL                   (0x01)
#define BMI160_ACCEL_PMU_LOW_POWER                (0x02)

/** Mask definitions for INT_OUT_CTRL register */
#define BMI160_INT1_EDGE_CTRL_MASK                (0x01)
#define BMI160_INT1_OUTPUT_MODE_MASK              (0x04)
#define BMI160_INT1_OUTPUT_TYPE_MASK              (0x02)
#define BMI160_INT1_OUTPUT_EN_MASK                (0x08)
#define BMI160_INT2_EDGE_CTRL_MASK                (0x10)
#define BMI160_INT2_OUTPUT_MODE_MASK              (0x40)
#define BMI160_INT2_OUTPUT_TYPE_MASK              (0x20)
#define BMI160_INT2_OUTPUT_EN_MASK                (0x80)

/** Mask definitions for INT_LATCH register */
#define BMI160_INT1_INPUT_EN_MASK                 (0x10)
#define BMI160_INT2_INPUT_EN_MASK                 (0x20)
#define BMI160_INT_LATCH_MASK                     (0x0F)

/** Mask definitions for INT_MAP register */
#define BMI160_INT1_LOW_G_MASK                    (0x01)
#define BMI160_INT1_HIGH_G_MASK                   (0x02)
#define BMI160_INT1_SLOPE_MASK                    (0x04)
#define BMI160_INT1_NO_MOTION_MASK                (0x08)
#define BMI160_INT1_DOUBLE_TAP_MASK               (0x10)
#define BMI160_INT1_SINGLE_TAP_MASK               (0x20)
#define BMI160_INT1_FIFO_FULL_MASK                (0x20)
#define BMI160_INT1_FIFO_WM_MASK                  (0x40)
#define BMI160_INT1_ORIENT_MASK                   (0x40)
#define BMI160_INT1_FLAT_MASK                     (0x80)
#define BMI160_INT1_DATA_READY_MASK               (0x80)
#define BMI160_INT2_LOW_G_MASK                    (0x01)
#define BMI160_INT1_LOW_STEP_DETECT_MASK          (0x01)
#define BMI160_INT2_LOW_STEP_DETECT_MASK          (0x01)
#define BMI160_INT2_HIGH_G_MASK                   (0x02)
#define BMI160_INT2_FIFO_FULL_MASK                (0x02)
#define BMI160_INT2_FIFO_WM_MASK                  (0x04)
#define BMI160_INT2_SLOPE_MASK                    (0x04)
#define BMI160_INT2_DATA_READY_MASK               (0x08)
#define BMI160_INT2_NO_MOTION_MASK                (0x08)
#define BMI160_INT2_DOUBLE_TAP_MASK               (0x10)
#define BMI160_INT2_SINGLE_TAP_MASK               (0x20)
#define BMI160_INT2_ORIENT_MASK                   (0x40)
#define BMI160_INT2_FLAT_MASK                     (0x80)

/** Mask definitions for INT_DATA register */
#define BMI160_TAP_SRC_INT_MASK                   (0x08)
#define BMI160_LOW_HIGH_SRC_INT_MASK              (0x80)
#define BMI160_MOTION_SRC_INT_MASK                (0x80)

/** Mask definitions for INT_MOTION register */
#define BMI160_SLOPE_INT_DUR_MASK                 (0x03)
#define BMI160_NO_MOTION_INT_DUR_MASK             (0xFC)
#define BMI160_NO_MOTION_SEL_BIT_MASK             (0x01)

/** Mask definitions for INT_TAP register */
#define BMI160_TAP_DUR_MASK                       (0x07)
#define BMI160_TAP_SHOCK_DUR_MASK                 (0x40)
#define BMI160_TAP_QUIET_DUR_MASK                 (0x80)
#define BMI160_TAP_THRES_MASK                     (0x1F)

/** Mask definitions for INT_FLAT register */
#define BMI160_FLAT_THRES_MASK                    (0x3F)
#define BMI160_FLAT_HOLD_TIME_MASK                (0x30)
#define BMI160_FLAT_HYST_MASK                     (0x07)

/** Mask definitions for INT_LOWHIGH register */
#define BMI160_LOW_G_HYST_MASK                    (0x03)
#define BMI160_LOW_G_LOW_MODE_MASK                (0x04)
#define BMI160_HIGH_G_HYST_MASK                   (0xC0)

/** Mask definitions for INT_SIG_MOTION register */
#define BMI160_SIG_MOTION_SEL_MASK                (0x02)
#define BMI160_SIG_MOTION_SKIP_MASK               (0x0C)
#define BMI160_SIG_MOTION_PROOF_MASK              (0x30)

/** Mask definitions for INT_ORIENT register */
#define BMI160_ORIENT_MODE_MASK                   (0x03)
#define BMI160_ORIENT_BLOCK_MASK                  (0x0C)
#define BMI160_ORIENT_HYST_MASK                   (0xF0)
#define BMI160_ORIENT_THETA_MASK                  (0x3F)
#define BMI160_ORIENT_UD_ENABLE                   (0x40)
#define BMI160_AXES_EN_MASK                       (0x80)

/** Mask definitions for FIFO_CONFIG register */
#define BMI160_FIFO_GYRO                          (0x80)
#define BMI160_FIFO_ACCEL                         (0x40)
#define BMI160_FIFO_AUX                           (0x20)
#define BMI160_FIFO_TAG_INT1                      (0x08)
#define BMI160_FIFO_TAG_INT2                      (0x04)
#define BMI160_FIFO_TIME                          (0x02)
#define BMI160_FIFO_HEADER                        (0x10)
#define BMI160_FIFO_CONFIG_1_MASK                 (0xFE)

/** Mask definitions for STEP_CONF register */
#define BMI160_STEP_COUNT_EN_BIT_MASK             (0x08)
#define BMI160_STEP_DETECT_MIN_THRES_MASK         (0x18)
#define BMI160_STEP_DETECT_STEPTIME_MIN_MASK      (0x07)
#define BMI160_STEP_MIN_BUF_MASK                  (0x07)

/** Mask definition for FIFO Header Data Tag */
#define BMI160_FIFO_TAG_INTR_MASK                 (0xFC)

/** Fifo byte counter mask definitions */
#define BMI160_FIFO_BYTE_COUNTER_MASK             (0x07)

/** Enable/disable bit value */
#define BMI160_ENABLE                             (0x01)
#define BMI160_DISABLE                            (0x00)

/** Latch Duration */
#define BMI160_LATCH_DUR_NONE                     (0x00)
#define BMI160_LATCH_DUR_312_5_MICRO_SEC          (0x01)
#define BMI160_LATCH_DUR_625_MICRO_SEC            (0x02)
#define BMI160_LATCH_DUR_1_25_MILLI_SEC           (0x03)
#define BMI160_LATCH_DUR_2_5_MILLI_SEC            (0x04)
#define BMI160_LATCH_DUR_5_MILLI_SEC              (0x05)
#define BMI160_LATCH_DUR_10_MILLI_SEC             (0x06)
#define BMI160_LATCH_DUR_20_MILLI_SEC             (0x07)
#define BMI160_LATCH_DUR_40_MILLI_SEC             (0x08)
#define BMI160_LATCH_DUR_80_MILLI_SEC             (0x09)
#define BMI160_LATCH_DUR_160_MILLI_SEC            (0x0A)
#define BMI160_LATCH_DUR_320_MILLI_SEC            (0x0B)
#define BMI160_LATCH_DUR_640_MILLI_SEC            (0x0C)
#define BMI160_LATCH_DUR_1_28_SEC                 (0x0D)
#define BMI160_LATCH_DUR_2_56_SEC                 (0x0E)
#define BMI160_LATCHED                            (0x0F)

/** BMI160 Register map */
#define BMI160_CHIP_ID_ADDR                       (0x00)
#define BMI160_ERROR_REG_ADDR                     (0x02)
#define BMI160_PMU_STATUS_ADDR                    (0x03)
#define BMI160_AUX_DATA_ADDR                      (0x04)
#define BMI160_GYRO_DATA_ADDR                     (0x0C)
#define BMI160_ACCEL_DATA_ADDR                    (0x12)
#define BMI160_STATUS_ADDR                        (0x1B)
#define BMI160_INT_STATUS_ADDR                    (0x1C)
#define BMI160_FIFO_LENGTH_ADDR                   (0x22)
#define BMI160_FIFO_DATA_ADDR                     (0x24)
#define BMI160_ACCEL_CONFIG_ADDR                  (0x40)
#define BMI160_ACCEL_RANGE_ADDR                   (0x41)
#define BMI160_GYRO_CONFIG_ADDR                   (0x42)
#define BMI160_GYRO_RANGE_ADDR                    (0x43)
#define BMI160_AUX_ODR_ADDR                       (0x44)
#define BMI160_FIFO_DOWN_ADDR                     (0x45)
#define BMI160_FIFO_CONFIG_0_ADDR                 (0x46)
#define BMI160_FIFO_CONFIG_1_ADDR                 (0x47)
#define BMI160_AUX_IF_0_ADDR                      (0x4B)
#define BMI160_AUX_IF_1_ADDR                      (0x4C)
#define BMI160_AUX_IF_2_ADDR                      (0x4D)
#define BMI160_AUX_IF_3_ADDR                      (0x4E)
#define BMI160_AUX_IF_4_ADDR                      (0x4F)
#define BMI160_INT_ENABLE_0_ADDR                  (0x50)
#define BMI160_INT_ENABLE_1_ADDR                  (0x51)
#define BMI160_INT_ENABLE_2_ADDR                  (0x52)
#define BMI160_INT_OUT_CTRL_ADDR                  (0x53)
#define BMI160_INT_LATCH_ADDR                     (0x54)
#define BMI160_INT_MAP_0_ADDR                     (0x55)
#define BMI160_INT_MAP_1_ADDR                     (0x56)
#define BMI160_INT_MAP_2_ADDR                     (0x57)
#define BMI160_INT_DATA_0_ADDR                    (0x58)
#define BMI160_INT_DATA_1_ADDR                    (0x59)
#define BMI160_INT_LOWHIGH_0_ADDR                 (0x5A)
#define BMI160_INT_LOWHIGH_1_ADDR                 (0x5B)
#define BMI160_INT_LOWHIGH_2_ADDR                 (0x5C)
#define BMI160_INT_LOWHIGH_3_ADDR                 (0x5D)
#define BMI160_INT_LOWHIGH_4_ADDR                 (0x5E)
#define BMI160_INT_MOTION_0_ADDR                  (0x5F)
#define BMI160_INT_MOTION_1_ADDR                  (0x60)
#define BMI160_INT_MOTION_2_ADDR                  (0x61)
#define BMI160_INT_MOTION_3_ADDR                  (0x62)
#define BMI160_INT_TAP_0_ADDR                     (0x63)
#define BMI160_INT_TAP_1_ADDR                     (0x64)
#define BMI160_INT_ORIENT_0_ADDR                  (0x65)
#define BMI160_INT_ORIENT_1_ADDR                  (0x66)
#define BMI160_INT_FLAT_0_ADDR                    (0x67)
#define BMI160_INT_FLAT_1_ADDR                    (0x68)
#define BMI160_FOC_CONF_ADDR                      (0x69)
#define BMI160_CONF_ADDR                          (0x6A)

#define BMI160_IF_CONF_ADDR                       (0x6B)
#define BMI160_SELF_TEST_ADDR                     (0x6D)
#define BMI160_OFFSET_ADDR                        (0x71)
#define BMI160_OFFSET_CONF_ADDR                   (0x77)
#define BMI160_INT_STEP_CNT_0_ADDR                (0x78)
#define BMI160_INT_STEP_CONFIG_0_ADDR             (0x7A)
#define BMI160_INT_STEP_CONFIG_1_ADDR             (0x7B)
#define BMI160_COMMAND_REG_ADDR                   (0x7E)
#define BMI160_SPI_COMM_TEST_ADDR                 (0x7F)
#define BMI160_INTL_PULLUP_CONF_ADDR              (0x85)

/** Error code definitions */
#define BMI160_OK                                 (0)
#define BMI160_E_NULL_PTR                         (-1)
#define BMI160_E_COM_FAIL                         (-2)
#define BMI160_E_DEV_NOT_FOUND                    (-3)
#define BMI160_E_OUT_OF_RANGE                     (-4)
#define BMI160_E_INVALID_INPUT                    (-5)
#define BMI160_E_ACCEL_ODR_BW_INVALID             (-6)
#define BMI160_E_GYRO_ODR_BW_INVALID              (-7)
#define BMI160_E_LWP_PRE_FLTR_INT_INVALID         (-8)
#define BMI160_E_LWP_PRE_FLTR_INVALID             (-9)
#define BMI160_E_AUX_NOT_FOUND                    (-10)
#define BMI160_E_FOC_FAILURE                      (-11)
#define BMI160_E_READ_WRITE_LENGTH_INVALID        (-12)
#define BMI160_E_INVALID_CONFIG                   (-13)

/**\name API warning codes */
#define BMI160_W_GYRO_SELF_TEST_FAIL              (1)
#define BMI160_W_ACCEl_SELF_TEST_FAIL             (2)

/** BMI160 unique chip identifier */
#define BMI160_CHIP_ID                            (0xD1)

/** Soft reset command */
#define BMI160_SOFT_RESET_CMD                     (0xb6)
#define BMI160_SOFT_RESET_DELAY_MS                (1)

/** Start FOC command */
#define BMI160_START_FOC_CMD                      (0x03)

/** NVM backup enabling command */
#define BMI160_NVM_BACKUP_EN                      (0xA0)

/* Delay in ms settings */
#define BMI160_ACCEL_DELAY_MS                     (5)
#define BMI160_GYRO_DELAY_MS                      (80)
#define BMI160_ONE_MS_DELAY                       (1)
#define BMI160_AUX_COM_DELAY                      (10)
#define BMI160_GYRO_SELF_TEST_DELAY               (20)
#define BMI160_ACCEL_SELF_TEST_DELAY              (50)

/** Self test configurations */
#define BMI160_ACCEL_SELF_TEST_CONFIG             (0x2C)
#define BMI160_ACCEL_SELF_TEST_POSITIVE_EN        (0x0D)
#define BMI160_ACCEL_SELF_TEST_NEGATIVE_EN        (0x09)
#define BMI160_ACCEL_SELF_TEST_LIMIT              (8192)

/** Power mode settings */
/* Accel power mode */
#define BMI160_ACCEL_NORMAL_MODE                  (0x11)
#define BMI160_ACCEL_LOWPOWER_MODE                (0x12)
#define BMI160_ACCEL_SUSPEND_MODE                 (0x10)

/* Gyro power mode */
#define BMI160_GYRO_SUSPEND_MODE                  (0x14)
#define BMI160_GYRO_NORMAL_MODE                   (0x15)
#define BMI160_GYRO_FASTSTARTUP_MODE              (0x17)

/* Aux power mode */
#define BMI160_AUX_SUSPEND_MODE                   (0x18)
#define BMI160_AUX_NORMAL_MODE                    (0x19)
#define BMI160_AUX_LOWPOWER_MODE                  (0x1A)

/** Bandwidth settings */
/* Accel Bandwidth */
#define BMI160_ACCEL_BW_OSR4_AVG1                 (0x00)
#define BMI160_ACCEL_BW_OSR2_AVG2                 (0x01)
#define BMI160_ACCEL_BW_NORMAL_AVG4               (0x02)
#define BMI160_ACCEL_BW_RES_AVG8                  (0x03)
#define BMI160_ACCEL_BW_RES_AVG16                 (0x04)
#define BMI160_ACCEL_BW_RES_AVG32                 (0x05)
#define BMI160_ACCEL_BW_RES_AVG64                 (0x06)
#define BMI160_ACCEL_BW_RES_AVG128                (0x07)

#define BMI160_GYRO_BW_OSR4_MODE                  (0x00)
#define BMI160_GYRO_BW_OSR2_MODE                  (0x01)
#define BMI160_GYRO_BW_NORMAL_MODE                (0x02)

/* Output Data Rate settings */
/* Accel Output data rate */
#define BMI160_ACCEL_ODR_RESERVED                 (0x00)
#define BMI160_ACCEL_ODR_1_56HZ                   (0x02)
#define BMI160_ACCEL_ODR_3_12HZ                   (0x03)
#define BMI160_ACCEL_ODR_6_25HZ                   (0x04)
#define BMI160_ACCEL_ODR_12_5HZ                   (0x05)
#define BMI160_ACCEL_ODR_25HZ                     (0x06)
#define BMI160_ACCEL_ODR_50HZ                     (0x07)
#define BMI160_ACCEL_ODR_100HZ                    (0x08)
#define BMI160_ACCEL_ODR_200HZ                    (0x09)
#define BMI160_ACCEL_ODR_400HZ                    (0x0A)
#define BMI160_ACCEL_ODR_800HZ                    (0x0B)
#define BMI160_ACCEL_ODR_1600HZ                   (0x0C)
#define BMI160_ACCEL_ODR_RESERVED0                (0x0D)
#define BMI160_ACCEL_ODR_RESERVED1                (0x0E)
#define BMI160_ACCEL_ODR_RESERVED2                (0x0F)

/* Gyro Output data rate */
#define BMI160_GYRO_ODR_RESERVED                  (0x00)
#define BMI160_GYRO_ODR_25HZ                      (0x06)
#define BMI160_GYRO_ODR_50HZ                      (0x07)
#define BMI160_GYRO_ODR_100HZ                     (0x08)
#define BMI160_GYRO_ODR_200HZ                     (0x09)
#define BMI160_GYRO_ODR_400HZ                     (0x0A)
#define BMI160_GYRO_ODR_800HZ                     (0x0B)
#define BMI160_GYRO_ODR_1600HZ                    (0x0C)
#define BMI160_GYRO_ODR_3200HZ                    (0x0D)

/* Auxiliary sensor Output data rate */
#define BMI160_AUX_ODR_RESERVED                   (0x00)
#define BMI160_AUX_ODR_0_78HZ                     (0x01)
#define BMI160_AUX_ODR_1_56HZ                     (0x02)
#define BMI160_AUX_ODR_3_12HZ                     (0x03)
#define BMI160_AUX_ODR_6_25HZ                     (0x04)
#define BMI160_AUX_ODR_12_5HZ                     (0x05)
#define BMI160_AUX_ODR_25HZ                       (0x06)
#define BMI160_AUX_ODR_50HZ                       (0x07)
#define BMI160_AUX_ODR_100HZ                      (0x08)
#define BMI160_AUX_ODR_200HZ                      (0x09)
#define BMI160_AUX_ODR_400HZ                      (0x0A)
#define BMI160_AUX_ODR_800HZ                      (0x0B)

/** FIFO_CONFIG Definitions */
#define BMI160_FIFO_TIME_ENABLE                   (0x02)
#define BMI160_FIFO_TAG_INT2_ENABLE               (0x04)
#define BMI160_FIFO_TAG_INT1_ENABLE               (0x08)
#define BMI160_FIFO_HEAD_ENABLE                   (0x10)
#define BMI160_FIFO_M_ENABLE                      (0x20)
#define BMI160_FIFO_A_ENABLE                      (0x40)
#define BMI160_FIFO_M_A_ENABLE                    (0x60)
#define BMI160_FIFO_G_ENABLE                      (0x80)
#define BMI160_FIFO_M_G_ENABLE                    (0xA0)
#define BMI160_FIFO_G_A_ENABLE                    (0xC0)
#define BMI160_FIFO_M_G_A_ENABLE                  (0xE0)

/* Macro to specify the number of bytes over-read from the
 * FIFO in order to get the sensor time at the end of FIFO */
#ifndef BMI160_FIFO_BYTES_OVERREAD
#define BMI160_FIFO_BYTES_OVERREAD                (25)
#endif

/* Accel, gyro and aux. sensor length and also their combined
 * length definitions in FIFO */
#define BMI160_FIFO_G_LENGTH                      (6)
#define BMI160_FIFO_A_LENGTH                      (6)
#define BMI160_FIFO_M_LENGTH                      (8)
#define BMI160_FIFO_GA_LENGTH                     (12)
#define BMI160_FIFO_MA_LENGTH                     (14)
#define BMI160_FIFO_MG_LENGTH                     (14)
#define BMI160_FIFO_MGA_LENGTH                    (20)

/** FIFO Header Data definitions */
#define BMI160_FIFO_HEAD_SKIP_FRAME               (0x40)
#define BMI160_FIFO_HEAD_SENSOR_TIME              (0x44)
#define BMI160_FIFO_HEAD_INPUT_CONFIG             (0x48)
#define BMI160_FIFO_HEAD_OVER_READ                (0x80)
#define BMI160_FIFO_HEAD_A                        (0x84)
#define BMI160_FIFO_HEAD_G                        (0x88)
#define BMI160_FIFO_HEAD_G_A                      (0x8C)
#define BMI160_FIFO_HEAD_M                        (0x90)
#define BMI160_FIFO_HEAD_M_A                      (0x94)
#define BMI160_FIFO_HEAD_M_G                      (0x98)
#define BMI160_FIFO_HEAD_M_G_A                    (0x9C)

/** FIFO sensor time length definitions */
#define BMI160_SENSOR_TIME_LENGTH                 (3)

/** FIFO DOWN selection */
/* Accel fifo down-sampling values*/
#define  BMI160_ACCEL_FIFO_DOWN_ZERO              (0x00)
#define  BMI160_ACCEL_FIFO_DOWN_ONE               (0x10)
#define  BMI160_ACCEL_FIFO_DOWN_TWO               (0x20)
#define  BMI160_ACCEL_FIFO_DOWN_THREE             (0x30)
#define  BMI160_ACCEL_FIFO_DOWN_FOUR              (0x40)
#define  BMI160_ACCEL_FIFO_DOWN_FIVE              (0x50)
#define  BMI160_ACCEL_FIFO_DOWN_SIX               (0x60)
#define  BMI160_ACCEL_FIFO_DOWN_SEVEN             (0x70)

/* Gyro fifo down-smapling values*/
#define  BMI160_GYRO_FIFO_DOWN_ZERO               (0x00)
#define  BMI160_GYRO_FIFO_DOWN_ONE                (0x01)
#define  BMI160_GYRO_FIFO_DOWN_TWO                (0x02)
#define  BMI160_GYRO_FIFO_DOWN_THREE              (0x03)
#define  BMI160_GYRO_FIFO_DOWN_FOUR               (0x04)
#define  BMI160_GYRO_FIFO_DOWN_FIVE               (0x05)
#define  BMI160_GYRO_FIFO_DOWN_SIX                (0x06)
#define  BMI160_GYRO_FIFO_DOWN_SEVEN              (0x07)

/* Accel Fifo filter enable*/
#define  BMI160_ACCEL_FIFO_FILT_EN                (0x80)

/* Gyro Fifo filter enable*/
#define  BMI160_GYRO_FIFO_FILT_EN                 (0x08)

/** Definitions to check validity of FIFO frames */
#define FIFO_CONFIG_MSB_CHECK                     (0x80)
#define FIFO_CONFIG_LSB_CHECK                     (0x00)

/*! BMI160 accel FOC configurations */
#define BMI160_FOC_ACCEL_DISABLED                 (0x00)
#define BMI160_FOC_ACCEL_POSITIVE_G               (0x01)
#define BMI160_FOC_ACCEL_NEGATIVE_G               (0x02)
#define BMI160_FOC_ACCEL_0G                       (0x03)

/** Array Parameter DefinItions */
#define BMI160_SENSOR_TIME_LSB_BYTE               (0)
#define BMI160_SENSOR_TIME_XLSB_BYTE              (1)
#define BMI160_SENSOR_TIME_MSB_BYTE               (2)

/** Interface settings */
#define BMI160_SPI_INTF                           (1)
#define BMI160_I2C_INTF                           (0)
#define BMI160_SPI_RD_MASK                        (0x80)
#define BMI160_SPI_WR_MASK                        (0x7F)

/* Sensor & time select definition*/
#define BMI160_ACCEL_SEL                          (0x01)
#define BMI160_GYRO_SEL                           (0x02)
#define BMI160_TIME_SEL                           (0x04)

/* Sensor select mask*/
#define BMI160_SEN_SEL_MASK                       (0x07)

/* Error code mask */
#define BMI160_ERR_REG_MASK                       (0x0F)

/* BMI160 secondary IF address */
#define BMI160_AUX_BMM150_I2C_ADDR                (0x10)

/** BMI160 Length definitions */
#define BMI160_ONE                                (1)
#define BMI160_TWO                                (2)
#define BMI160_THREE                              (3)
#define BMI160_FOUR                               (4)
#define BMI160_FIVE                               (5)

/** BMI160 fifo level Margin */
#define BMI160_FIFO_LEVEL_MARGIN                  (16)

/** BMI160 fifo flush Command */
#define BMI160_FIFO_FLUSH_VALUE                   (0xB0)

/** BMI160 offset values for xyz axes of accel */
#define BMI160_ACCEL_MIN_OFFSET                   (-128)
#define BMI160_ACCEL_MAX_OFFSET                   (127)

/** BMI160 offset values for xyz axes of gyro */
#define BMI160_GYRO_MIN_OFFSET                    (-512)
#define BMI160_GYRO_MAX_OFFSET                    (511)

/** BMI160 fifo full interrupt position and mask */
#define BMI160_FIFO_FULL_INT_POS                  (5)
#define BMI160_FIFO_FULL_INT_MSK                  (0x20)
#define BMI160_FIFO_WTM_INT_POS                   (6)
#define BMI160_FIFO_WTM_INT_MSK                   (0x40)

#define BMI160_FIFO_FULL_INT_PIN1_POS             (5)
#define BMI160_FIFO_FULL_INT_PIN1_MSK             (0x20)
#define BMI160_FIFO_FULL_INT_PIN2_POS             (1)
#define BMI160_FIFO_FULL_INT_PIN2_MSK             (0x02)

#define BMI160_FIFO_WTM_INT_PIN1_POS              (6)
#define BMI160_FIFO_WTM_INT_PIN1_MSK              (0x40)
#define BMI160_FIFO_WTM_INT_PIN2_POS              (2)
#define BMI160_FIFO_WTM_INT_PIN2_MSK              (0x04)

#define BMI160_MANUAL_MODE_EN_POS                 (7)
#define BMI160_MANUAL_MODE_EN_MSK                 (0x80)
#define BMI160_AUX_READ_BURST_POS                 (0)
#define BMI160_AUX_READ_BURST_MSK                 (0x03)

#define BMI160_GYRO_SELF_TEST_POS                 (4)
#define BMI160_GYRO_SELF_TEST_MSK                 (0x10)
#define BMI160_GYRO_SELF_TEST_STATUS_POS          (1)
#define BMI160_GYRO_SELF_TEST_STATUS_MSK          (0x02)

#define BMI160_GYRO_FOC_EN_POS                    (6)
#define BMI160_GYRO_FOC_EN_MSK                    (0x40)

#define BMI160_ACCEL_FOC_X_CONF_POS               (4)
#define BMI160_ACCEL_FOC_X_CONF_MSK               (0x30)

#define BMI160_ACCEL_FOC_Y_CONF_POS               (2)
#define BMI160_ACCEL_FOC_Y_CONF_MSK               (0x0C)

#define BMI160_ACCEL_FOC_Z_CONF_MSK               (0x03)

#define BMI160_FOC_STATUS_POS                     (3)
#define BMI160_FOC_STATUS_MSK                     (0x08)

#define BMI160_GYRO_OFFSET_X_MSK                  (0x03)

#define BMI160_GYRO_OFFSET_Y_POS                  (2)
#define BMI160_GYRO_OFFSET_Y_MSK                  (0x0C)

#define BMI160_GYRO_OFFSET_Z_POS                  (4)
#define BMI160_GYRO_OFFSET_Z_MSK                  (0x30)

#define BMI160_GYRO_OFFSET_EN_POS                 (7)
#define BMI160_GYRO_OFFSET_EN_MSK                 (0x80)

#define BMI160_ACCEL_OFFSET_EN_POS                (6)
#define BMI160_ACCEL_OFFSET_EN_MSK                (0x40)

#define BMI160_GYRO_OFFSET_POS                    (8)
#define BMI160_GYRO_OFFSET_MSK                    (0x0300)

#define BMI160_NVM_UPDATE_POS                     (1)
#define BMI160_NVM_UPDATE_MSK                     (0x02)

#define BMI160_NVM_STATUS_POS                     (4)
#define BMI160_NVM_STATUS_MSK                     (0x10)

#define BMI160_MAG_POWER_MODE_MSK                 (0x03)

#define BMI160_ACCEL_POWER_MODE_MSK               (0x30)
#define BMI160_ACCEL_POWER_MODE_POS               (4)

#define BMI160_GYRO_POWER_MODE_MSK                (0x0C)
#define BMI160_GYRO_POWER_MODE_POS                (2)

typedef enum {
    BMI160_ACCEL_RATE_25_2HZ = 5,  /**<   25/2  Hz */
    BMI160_ACCEL_RATE_25HZ,        /**<   25    Hz */
    BMI160_ACCEL_RATE_50HZ,        /**<   50    Hz */
    BMI160_ACCEL_RATE_100HZ,       /**<  100    Hz */
    BMI160_ACCEL_RATE_200HZ,       /**<  200    Hz */
    BMI160_ACCEL_RATE_400HZ,       /**<  400    Hz */
    BMI160_ACCEL_RATE_800HZ,       /**<  800    Hz */
    BMI160_ACCEL_RATE_1600HZ,      /**< 1600    Hz */
} BMI160AccelRate;

typedef enum {
    BMI160_GYRO_RATE_25HZ = 6,     /**<   25    Hz */
    BMI160_GYRO_RATE_50HZ,         /**<   50    Hz */
    BMI160_GYRO_RATE_100HZ,        /**<  100    Hz */
    BMI160_GYRO_RATE_200HZ,        /**<  200    Hz */
    BMI160_GYRO_RATE_400HZ,        /**<  400    Hz */
    BMI160_GYRO_RATE_800HZ,        /**<  800    Hz */
    BMI160_GYRO_RATE_1600HZ,       /**< 1600    Hz */
    BMI160_GYRO_RATE_3200HZ,       /**< 3200    Hz */
} BMI160GyroRate;

typedef enum {
    BMI160_DLPF_MODE_NORM = 0x2,
    BMI160_DLPF_MODE_OSR2 = 0x1,
    BMI160_DLPF_MODE_OSR4 = 0x0,
} BMI160DLPFMode;

typedef enum {
    BMI160_ACCEL_RANGE_2G  = 0X03, /**<  +/-  2g range */
    BMI160_ACCEL_RANGE_4G  = 0X05, /**<  +/-  4g range */
    BMI160_ACCEL_RANGE_8G  = 0X08, /**<  +/-  8g range */
    BMI160_ACCEL_RANGE_16G = 0X0C, /**<  +/- 16g range */
} BMI160AccelRange;

/**
 * Gyroscope Sensitivity Range options
 * @see setFullScaleGyroRange()
 */
typedef enum {
    BMI160_GYRO_RANGE_2000 = 0, /**<  +/- 2000 degrees/second */
    BMI160_GYRO_RANGE_1000,     /**<  +/- 1000 degrees/second */
    BMI160_GYRO_RANGE_500,      /**<  +/-  500 degrees/second */
    BMI160_GYRO_RANGE_250,      /**<  +/-  250 degrees/second */
    BMI160_GYRO_RANGE_125,      /**<  +/-  125 degrees/second */
} BMI160GyroRange;

typedef enum {
    BMI160_STEP_MODE_NORMAL = 0,
    BMI160_STEP_MODE_SENSITIVE,
    BMI160_STEP_MODE_ROBUST,
    BMI160_STEP_MODE_UNKNOWN,
} BMI160StepMode;

typedef enum {
    BMI160_TAP_SHOCK_DURATION_50MS = 0,
    BMI160_TAP_SHOCK_DURATION_75MS,
} BMI160TapShockDuration;

typedef enum {
    BMI160_TAP_QUIET_DURATION_30MS = 0,
    BMI160_TAP_QUIET_DURATION_20MS,
} BMI160TapQuietDuration;

typedef enum {
    BMI160_DOUBLE_TAP_DURATION_50MS = 0,
    BMI160_DOUBLE_TAP_DURATION_100MS,
    BMI160_DOUBLE_TAP_DURATION_150MS,
    BMI160_DOUBLE_TAP_DURATION_200MS,
    BMI160_DOUBLE_TAP_DURATION_250MS,
    BMI160_DOUBLE_TAP_DURATION_375MS,
    BMI160_DOUBLE_TAP_DURATION_500MS,
    BMI160_DOUBLE_TAP_DURATION_700MS,
} BMI160DoubleTapDuration;

typedef enum {
    BMI160_ZERO_MOTION_DURATION_1_28S   = 0x00, /**<   1.28 seconds */
    BMI160_ZERO_MOTION_DURATION_2_56S,          /**<   2.56 seconds */
    BMI160_ZERO_MOTION_DURATION_3_84S,          /**<   3.84 seconds */
    BMI160_ZERO_MOTION_DURATION_5_12S,          /**<   5.12 seconds */
    BMI160_ZERO_MOTION_DURATION_6_40S,          /**<   6.40 seconds */
    BMI160_ZERO_MOTION_DURATION_7_68S,          /**<   7.68 seconds */
    BMI160_ZERO_MOTION_DURATION_8_96S,          /**<   8.96 seconds */
    BMI160_ZERO_MOTION_DURATION_10_24S,         /**<  10.24 seconds */
    BMI160_ZERO_MOTION_DURATION_11_52S,         /**<  11.52 seconds */
    BMI160_ZERO_MOTION_DURATION_12_80S,         /**<  12.80 seconds */
    BMI160_ZERO_MOTION_DURATION_14_08S,         /**<  14.08 seconds */
    BMI160_ZERO_MOTION_DURATION_15_36S,         /**<  15.36 seconds */
    BMI160_ZERO_MOTION_DURATION_16_64S,         /**<  16.64 seconds */
    BMI160_ZERO_MOTION_DURATION_17_92S,         /**<  17.92 seconds */
    BMI160_ZERO_MOTION_DURATION_19_20S,         /**<  19.20 seconds */
    BMI160_ZERO_MOTION_DURATION_20_48S,         /**<  20.48 seconds */
    BMI160_ZERO_MOTION_DURATION_25_60S  = 0x10, /**<  25.60 seconds */
    BMI160_ZERO_MOTION_DURATION_30_72S,         /**<  30.72 seconds */
    BMI160_ZERO_MOTION_DURATION_35_84S,         /**<  35.84 seconds */
    BMI160_ZERO_MOTION_DURATION_40_96S,         /**<  40.96 seconds */
    BMI160_ZERO_MOTION_DURATION_46_08S,         /**<  46.08 seconds */
    BMI160_ZERO_MOTION_DURATION_51_20S,         /**<  51.20 seconds */
    BMI160_ZERO_MOTION_DURATION_56_32S,         /**<  56.32 seconds */
    BMI160_ZERO_MOTION_DURATION_61_44S,         /**<  61.44 seconds */
    BMI160_ZERO_MOTION_DURATION_66_56S,         /**<  66.56 seconds */
    BMI160_ZERO_MOTION_DURATION_71_68S,         /**<  71.68 seconds */
    BMI160_ZERO_MOTION_DURATION_76_80S,         /**<  76.80 seconds */
    BMI160_ZERO_MOTION_DURATION_81_92S,         /**<  81.92 seconds */
    BMI160_ZERO_MOTION_DURATION_87_04S,         /**<  87.04 seconds */
    BMI160_ZERO_MOTION_DURATION_92_16S,         /**<  92.16 seconds */
    BMI160_ZERO_MOTION_DURATION_97_28S,         /**<  97.28 seconds */
    BMI160_ZERO_MOTION_DURATION_102_40S,        /**< 102.40 seconds */
    BMI160_ZERO_MOTION_DURATION_112_64S = 0x20, /**< 112.64 seconds */
    BMI160_ZERO_MOTION_DURATION_122_88S,        /**< 122.88 seconds */
    BMI160_ZERO_MOTION_DURATION_133_12S,        /**< 133.12 seconds */
    BMI160_ZERO_MOTION_DURATION_143_36S,        /**< 143.36 seconds */
    BMI160_ZERO_MOTION_DURATION_153_60S,        /**< 153.60 seconds */
    BMI160_ZERO_MOTION_DURATION_163_84S,        /**< 163.84 seconds */
    BMI160_ZERO_MOTION_DURATION_174_08S,        /**< 174.08 seconds */
    BMI160_ZERO_MOTION_DURATION_184_32S,        /**< 184.32 seconds */
    BMI160_ZERO_MOTION_DURATION_194_56S,        /**< 194.56 seconds */
    BMI160_ZERO_MOTION_DURATION_204_80S,        /**< 204.80 seconds */
    BMI160_ZERO_MOTION_DURATION_215_04S,        /**< 215.04 seconds */
    BMI160_ZERO_MOTION_DURATION_225_28S,        /**< 225.28 seconds */
    BMI160_ZERO_MOTION_DURATION_235_52S,        /**< 235.52 seconds */
    BMI160_ZERO_MOTION_DURATION_245_76S,        /**< 245.76 seconds */
    BMI160_ZERO_MOTION_DURATION_256_00S,        /**< 256.00 seconds */
    BMI160_ZERO_MOTION_DURATION_266_24S,        /**< 266.24 seconds */
    BMI160_ZERO_MOTION_DURATION_276_48S,        /**< 276.48 seconds */
    BMI160_ZERO_MOTION_DURATION_286_72S,        /**< 286.72 seconds */
    BMI160_ZERO_MOTION_DURATION_296_96S,        /**< 296.96 seconds */
    BMI160_ZERO_MOTION_DURATION_307_20S,        /**< 307.20 seconds */
    BMI160_ZERO_MOTION_DURATION_317_44S,        /**< 317.44 seconds */
    BMI160_ZERO_MOTION_DURATION_327_68S,        /**< 327.68 seconds */
    BMI160_ZERO_MOTION_DURATION_337_92S,        /**< 337.92 seconds */
    BMI160_ZERO_MOTION_DURATION_348_16S,        /**< 348.16 seconds */
    BMI160_ZERO_MOTION_DURATION_358_40S,        /**< 358.40 seconds */
    BMI160_ZERO_MOTION_DURATION_368_64S,        /**< 368.64 seconds */
    BMI160_ZERO_MOTION_DURATION_378_88S,        /**< 378.88 seconds */
    BMI160_ZERO_MOTION_DURATION_389_12S,        /**< 389.12 seconds */
    BMI160_ZERO_MOTION_DURATION_399_36S,        /**< 399.36 seconds */
    BMI160_ZERO_MOTION_DURATION_409_60S,        /**< 409.60 seconds */
    BMI160_ZERO_MOTION_DURATION_419_84S,        /**< 419.84 seconds */
    BMI160_ZERO_MOTION_DURATION_430_08S,        /**< 430.08 seconds */
} BMI160ZeroMotionDuration;


#endif
