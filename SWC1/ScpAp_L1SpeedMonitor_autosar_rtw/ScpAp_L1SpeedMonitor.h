/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ScpAp_L1SpeedMonitor.h
 *
 * Code generated for Simulink model 'ScpAp_L1SpeedMonitor'.
 *
 * Model version                  : 1.177
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Tue Feb 10 15:17:05 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef ScpAp_L1SpeedMonitor_h_
#define ScpAp_L1SpeedMonitor_h_
#ifndef ScpAp_L1SpeedMonitor_COMMON_INCLUDES_
#define ScpAp_L1SpeedMonitor_COMMON_INCLUDES_
#include "Platform_Types.h"
#include "Rte_ScpAp_L1SpeedMonitor.h"
#endif                               /* ScpAp_L1SpeedMonitor_COMMON_INCLUDES_ */

#include "ScpAp_L1SpeedMonitor_types.h"
#include "Rte_Type.h"

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  IF_ValidityFlag_L1p_IDT PP_ValidityFlag_L1p_IF_Validity;
                          /* '<Root>/PP_ValidityFlag_L1p_IF_ValidityFlag_L1p' */
  float32 IMU_AccelX_L1p_g;            /* '<S4>/IMU_AccelX_L1p' */
  uint16 WSS_FL_L1p_e;                 /* '<S4>/WSS_FL_L1p' */
  uint16 WSS_FR_L1p_p;                 /* '<S4>/WSS_FR_L1p' */
  uint16 WSS_R_L1p_b;                  /* '<S4>/WSS_R_L1p' */
  uint8 MotorSpd_Equiv_L1p_l;          /* '<S4>/MotorSpd_Equiv_L1p' */
} ARID_DEF_ScpAp_L1SpeedMonitor_T;

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_ScpAp_L1SpeedMonitor_T ScpAp_L1SpeedMonitor_ARID_DEF;
                          /* '<Root>/PP_ValidityFlag_L1p_IF_ValidityFlag_L1p' */

/* Static Memory for Internal Data */

/* SwAddrMethod AswVariable for Internal Data */
#define ScpAp_L1SpeedMonitor_START_SEC_AswVariable
#include "ScpAp_L1SpeedMonitor_MemMap.h"

extern float64 ScpAp_L1Spee_Cal_IMU_AccelX_L1p;/* '<S16>/Add' */
extern float64 ScpAp_L1SpeedMonitor_Output;/* '<S12>/Switch1' */
extern float64 StuckCntOutput_Prev;    /* '<S12>/Unit Delay' */
extern float32 ScpAp_L1SpeedMon_X_Accel_L1_Phy;/* '<S13>/Abs' */
extern float32 ScpAp_L1SpeedMon_IMU_AccelX_L1p;/* '<S13>/Switch1' */
extern float32 ScpAp_L1SpeedMo_IMU_AccelX_Diff;/* '<S11>/Subtract3' */
extern float32 IMU_AccelX_L1p_Prev;    /* '<S13>/Unit Delay' */
extern float32 STC_IMU_Accel_XL1p_Prev;/* '<S11>/Unit Delay3' */
extern uint16 ScpAp_L1SpeedM_WhlSpdFR_Phy_Kph;/* '<S21>/Data Type Conversion' */
extern uint16 ScpAp_L1SpeedMonitor_WSS_R_L1p;/* '<S21>/Switch1' */
extern uint16 ScpAp_L1SpeedMoni_Cal_WSS_R_L1p;/* '<S24>/Add' */
extern uint16 ScpAp_L1Spee_WhlSpdFR_Phy_Kph_n;/* '<S20>/Data Type Conversion' */
extern uint16 ScpAp_L1SpeedMonitor_WSS_FR_L1p;/* '<S20>/Switch1' */
extern uint16 ScpAp_L1SpeedMon_Cal_WSS_FR_L1p;/* '<S23>/Add' */
extern uint16 ScpAp_L1Spe_WhlSpdFR_Phy_Kph_nw;/* '<S19>/Data Type Conversion' */
extern uint16 ScpAp_L1SpeedMonitor_WSS_FL_L1p;/* '<S19>/Switch1' */
extern uint16 ScpAp_L1SpeedMon_Cal_WSS_FL_L1p;/* '<S22>/Add' */
extern uint16 ScpAp_L1SpeedMonito_WSS_FR_Diff;/* '<S11>/Subtract' */
extern uint16 ScpAp_L1SpeedMonito_WSS_FL_Diff;/* '<S11>/Subtract1' */
extern uint16 ScpAp_L1SpeedMonitor_WSS_R_Diff;/* '<S11>/Subtract2' */
extern uint16 WSS_R_L1p_Prev;          /* '<S21>/Unit Delay' */
extern uint16 WSS_FR_L1p_Prev;         /* '<S20>/Unit Delay' */
extern uint16 WSS_FL_L1p_Prev;         /* '<S19>/Unit Delay' */
extern uint16 STC_WSS_FR_L1p_Prev;     /* '<S11>/Unit Delay' */
extern uint16 STC_WSS_FL_L1p_Prev;     /* '<S11>/Unit Delay1' */
extern uint16 STC_WSS_R_L1p_Prev;      /* '<S11>/Unit Delay2' */
extern uint8 ScpAp_L1Spee_MotorSpd_Equiv_L1p;/* '<S14>/Switch1' */
extern uint8 ScpAp_L1SpeedMonit_MotorSpd_kph;/* '<S18>/Data Type Conversion' */
extern uint8 ScpAp_L1_Cal_MotorSpd_Equiv_L1p;/* '<S17>/Add' */
extern uint8 ScpAp_L1Spe_MotorSpd_Equiv_Diff;/* '<S11>/Subtract4' */
extern uint8 MotorSpd_Equiv_L1p_Prev;  /* '<S14>/Unit Delay' */
extern uint8 STC_MotorSpd_Equiv_L1p_Prev;/* '<S11>/Unit Delay4' */
extern boolean ScpAp_L1Speed_WhlSpdR_Valid_Chk;/* '<S21>/OR' */
extern boolean ScpAp_L1SpeedMo_WSS_R_Valid_Flg;/* '<S21>/Switch' */
extern boolean ScpAp_L1Spee_WhlSpdFR_Valid_Chk;/* '<S20>/WSS_FR_OR_Op' */
extern boolean ScpAp_L1SpeedM_WSS_FR_Valid_Flg;/* '<S20>/Switch' */
extern boolean ScpAp_L1Spee_WhlSpdFL_Valid_Chk;/* '<S19>/OR' */
extern boolean ScpAp_L1SpeedM_WSS_FL_Valid_Flg;/* '<S19>/Switch' */
extern boolean ScpAp_L1Sp_Motor_Spd_ValidCheck;/* '<S14>/OR' */
extern boolean ScpAp_L1Spe_Motor_RPM_Valid_Flg;/* '<S14>/Switch' */
extern boolean ScpAp_L1SpeedMo_IMU_Accel_Valid;/* '<S13>/Relational Operator' */
extern boolean ScpAp_L1Sp_IMU_AccelX_Valid_Flg;/* '<S13>/Switch' */
extern boolean ScpAp_L1SpeedMoni_Chk_Stuck_Cnt;/* '<S9>/Switch' */
extern boolean ScpAp_L1SpeedMoni_Trg_Stuck_Cnt;/* '<S11>/OR' */
extern boolean ScpAp_L1S_SensorStuck_Valid_Flg;/* '<S11>/Switch' */

#define ScpAp_L1SpeedMonitor_STOP_SEC_AswVariable
#include "ScpAp_L1SpeedMonitor_MemMap.h"

/* Constant memory autosar model workspace parameters */

/* SwAddrMethod CALIB for Model Work Space Parameters */
#define ScpAp_L1SpeedMonitor_START_SEC_CALIB
#include "ScpAp_L1SpeedMonitor_MemMap.h"

extern const float64 Accel_Max;        /* Variable: Accel_Max
                                        * Referenced by: '<S13>/Constant2'
                                        */
extern const float64 Alpha_Accel_IMU;  /* Variable: Alpha_Accel_IMU
                                        * Referenced by: '<S10>/Constant2'
                                        */
extern const float64 Alpha_Motor;      /* Variable: Alpha_Motor
                                        * Referenced by: '<S10>/Constant'
                                        */
extern const float64 Alpha_WSS;        /* Variable: Alpha_WSS
                                        * Referenced by: '<S10>/Constant1'
                                        */
extern const uint16 Motor_Spd_Max;     /* Variable: Motor_Spd_Max
                                        * Referenced by: '<S14>/Motor_Max_Spd'
                                        */
extern const uint16 Motor_Spd_Min;     /* Variable: Motor_Spd_Min
                                        * Referenced by: '<S14>/Motor_Min_Spd'
                                        */

#define ScpAp_L1SpeedMonitor_STOP_SEC_CALIB
#include "ScpAp_L1SpeedMonitor_MemMap.h"

/* Exported data declaration */

/* Const memory section */
/* Declaration for custom storage class: Const */
extern const uint16 WhlSpd_Max;        /* Referenced by:
                                        * '<S19>/Constant1'
                                        * '<S20>/Constant1'
                                        * '<S21>/Constant1'
                                        */
extern const uint16 WhlSpd_Min;        /* Referenced by:
                                        * '<S19>/Constant'
                                        * '<S20>/Constant'
                                        * '<S21>/Constant'
                                        */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ScpAp_L1SpeedMonitor'
 * '<S1>'   : 'ScpAp_L1SpeedMonitor/ScpAp_L1SpeedMonitor_Init'
 * '<S2>'   : 'ScpAp_L1SpeedMonitor/SensorIFL1_Main_10_sys'
 * '<S3>'   : 'ScpAp_L1SpeedMonitor/SensorIFL1_Main_10_sys/Comm_Rx'
 * '<S4>'   : 'ScpAp_L1SpeedMonitor/SensorIFL1_Main_10_sys/Comm_Tx'
 * '<S5>'   : 'ScpAp_L1SpeedMonitor/SensorIFL1_Main_10_sys/SWC_1_Control'
 * '<S6>'   : 'ScpAp_L1SpeedMonitor/SensorIFL1_Main_10_sys/Comm_Rx/mEbcm2L_WhlSpd'
 * '<S7>'   : 'ScpAp_L1SpeedMonitor/SensorIFL1_Main_10_sys/Comm_Rx/mVculmuLinAccel'
 * '<S8>'   : 'ScpAp_L1SpeedMonitor/SensorIFL1_Main_10_sys/Comm_Rx/mWhdStat'
 * '<S9>'   : 'ScpAp_L1SpeedMonitor/SensorIFL1_Main_10_sys/SWC_1_Control/Stuck_Counter'
 * '<S10>'  : 'ScpAp_L1SpeedMonitor/SensorIFL1_Main_10_sys/SWC_1_Control/WSS_IMU_Motor'
 * '<S11>'  : 'ScpAp_L1SpeedMonitor/SensorIFL1_Main_10_sys/SWC_1_Control/Stuck_Counter/Stuck_Cnt_Validity_Check'
 * '<S12>'  : 'ScpAp_L1SpeedMonitor/SensorIFL1_Main_10_sys/SWC_1_Control/Stuck_Counter/Stuck_Cnt_Validity_Check/UpCounter'
 * '<S13>'  : 'ScpAp_L1SpeedMonitor/SensorIFL1_Main_10_sys/SWC_1_Control/WSS_IMU_Motor/IMU'
 * '<S14>'  : 'ScpAp_L1SpeedMonitor/SensorIFL1_Main_10_sys/SWC_1_Control/WSS_IMU_Motor/Motor'
 * '<S15>'  : 'ScpAp_L1SpeedMonitor/SensorIFL1_Main_10_sys/SWC_1_Control/WSS_IMU_Motor/WSS'
 * '<S16>'  : 'ScpAp_L1SpeedMonitor/SensorIFL1_Main_10_sys/SWC_1_Control/WSS_IMU_Motor/IMU/IMU_AccelX_L1p_Calculation'
 * '<S17>'  : 'ScpAp_L1SpeedMonitor/SensorIFL1_Main_10_sys/SWC_1_Control/WSS_IMU_Motor/Motor/MotorSpd_Equiv_L1p_Calculation'
 * '<S18>'  : 'ScpAp_L1SpeedMonitor/SensorIFL1_Main_10_sys/SWC_1_Control/WSS_IMU_Motor/Motor/RPM_to_Kph'
 * '<S19>'  : 'ScpAp_L1SpeedMonitor/SensorIFL1_Main_10_sys/SWC_1_Control/WSS_IMU_Motor/WSS/WSS_FL'
 * '<S20>'  : 'ScpAp_L1SpeedMonitor/SensorIFL1_Main_10_sys/SWC_1_Control/WSS_IMU_Motor/WSS/WSS_FR'
 * '<S21>'  : 'ScpAp_L1SpeedMonitor/SensorIFL1_Main_10_sys/SWC_1_Control/WSS_IMU_Motor/WSS/WSS_R'
 * '<S22>'  : 'ScpAp_L1SpeedMonitor/SensorIFL1_Main_10_sys/SWC_1_Control/WSS_IMU_Motor/WSS/WSS_FL/WSS_FL_L1p_Calculation'
 * '<S23>'  : 'ScpAp_L1SpeedMonitor/SensorIFL1_Main_10_sys/SWC_1_Control/WSS_IMU_Motor/WSS/WSS_FR/WSS_FR_L1p_Calculation'
 * '<S24>'  : 'ScpAp_L1SpeedMonitor/SensorIFL1_Main_10_sys/SWC_1_Control/WSS_IMU_Motor/WSS/WSS_R/WSS_R_L1p_Calculation'
 */
#endif                                 /* ScpAp_L1SpeedMonitor_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
