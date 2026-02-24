/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ScpAp_VechilestateEstimation_L2p.h
 *
 * Code generated for Simulink model 'ScpAp_VechilestateEstimation_L2p'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Mon Feb 16 10:54:50 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef ScpAp_VechilestateEstimation_L2p_h_
#define ScpAp_VechilestateEstimation_L2p_h_
#ifndef ScpAp_VechilestateEstimation_L2p_COMMON_INCLUDES_
#define ScpAp_VechilestateEstimation_L2p_COMMON_INCLUDES_
#include "Platform_Types.h"
#include "Rte_ScpAp_VechilestateEstimation_L2p.h"
#endif                   /* ScpAp_VechilestateEstimation_L2p_COMMON_INCLUDES_ */

#include "ScpAp_VechilestateEstimation_L2p_types.h"
#include "Rte_Type.h"

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  IF_SensorFaultFlgs_L2p_IDT PP_SensorValidityFlag_L2p_IF_Se;
                /* '<Root>/PP_SensorValidityFlag_L2p_IF_SensorFaultFlags_L2p' */
  float32 IMU_AccelX_L1p;  /* '<S3>/RP_ScpAp_IMU_AccelX_L1_IF_IMU_AccelX_L1p' */
  sint16 VehicleSpeed_L2_i;            /* '<S4>/VehicleSpeed_L2' */
  uint16 VehicleAccel_L2_g;            /* '<S4>/VehicleAccel_L2' */
  uint16 Wheelspeed_FL_L1p;
                    /* '<S3>/RP_ScpAp_Wheelspeed_FL_L1p_IF_Wheelspeed_Fx_L1p' */
  uint16 Wheelspeed_FR_L1p;
                    /* '<S3>/RP_ScpAp_Wheelspeed_FR_L1p_IF_Wheelspeed_Fx_L1p' */
  uint16 Wheelspeed_R_L1p;
                     /* '<S3>/RP_ScpAp_Wheelspeed_R_L1p_IF_Wheelspeed_Fx_L1p' */
  uint8 MotorSpeed_L1p;   /* '<S3>/RP_ScpAp_MotorSpeed_L1p_IF_MotorSpeed_L1p' */
} ARID_DEF_ScpAp_VechilestateEs_T;

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_ScpAp_VechilestateEs_T ScpAp_VechilestateEsti_ARID_DEF;
                /* '<Root>/PP_SensorValidityFlag_L2p_IF_SensorFaultFlags_L2p' */

/* Static Memory for Internal Data */

/* SwAddrMethod ASW_Variable for Internal Data */
#define ScpAp_VechilestateEstimation_L2p_START_SEC_ASW_Variable
#include "ScpAp_VechilestateEstimation_L2p_MemMap.h"

extern float64 ScpAp_VechilestateE_Valid_Wheel;/* '<S10>/Sum' */
extern float64 ScpAp_Vechilestat_Valid_Wheel_R;/* '<S15>/Switch' */
extern float64 ScpAp_Vechilesta_Valid_Wheel_FR;/* '<S14>/Switch' */
extern float64 ScpAp_Vechilesta_Valid_Wheel_FL;/* '<S13>/Switch' */
extern sint16 ScpAp_VehicleSpeed_Weighted_L2;/* '<S9>/Sum' */
extern sint16 ScpAp_Vechilest_VehicleSpeed_L2;/* '<S9>/Switch' */
extern sint16 ScpAp_VechilestateEst_Motor_Spd;/* '<S6>/Switch' */
extern sint16 VehicleSpeed_L2_Prev;    /* '<S5>/Unit Delay' */
extern uint16 ScpAp_V_VehicleAccel_from_speed;/* '<S8>/Data Type Conversion' */
extern uint16 ScpAp_Vechilest_VehicleAccel_L2;/* '<S8>/Switch1' */
extern uint16 ScpAp_Vechi_Cal_VehicleAccel_L2;/* '<S11>/Data Type Conversion' */
extern uint16 ScpAp_Vechilestat_WSS_x_L1p_Max;/* '<S7>/Max' */
extern uint16 ScpAp_Vechilestat_WSS_x_L1p_Min;/* '<S7>/Max1' */
extern boolean ScpAp_Vech_VhlSpd_Wgt_L2_Switch;/* '<S9>/OR' */
extern boolean ScpAp_Vechilesta_MotorRPM_Fault;/* '<S7>/Switch' */
extern boolean ScpAp_VechilestateE_Accel_Fault;/* '<S7>/Switch1' */
extern boolean ScpAp_VechilestateEst_WSS_Fault;/* '<S7>/Switch2' */
extern boolean ScpAp_Vechile_VehSpeedEst_Fault;/* '<S7>/Switch3' */

#define ScpAp_VechilestateEstimation_L2p_STOP_SEC_ASW_Variable
#include "ScpAp_VechilestateEstimation_L2p_MemMap.h"

/* Constant memory autosar model workspace parameters */

/* SwAddrMethod CALIB for Model Work Space Parameters */
#define ScpAp_VechilestateEstimation_L2p_START_SEC_CALIB
#include "ScpAp_VechilestateEstimation_L2p_MemMap.h"

extern const float64 Accel_Diff_Th;    /* Variable: Accel_Diff_Th
                                        * Referenced by: '<S7>/Constant5'
                                        */
extern const float64 Speed_Diff_Th;    /* Variable: Speed_Diff_Th
                                        * Referenced by: '<S7>/Constant1'
                                        */
extern const float64 Wheel_Diff_Th;    /* Variable: Wheel_Diff_Th
                                        * Referenced by: '<S7>/Constant8'
                                        */
extern const sint16 W1;                /* Variable: W1
                                        * Referenced by: '<S9>/Constant'
                                        */
extern const sint16 W2;                /* Variable: W2
                                        * Referenced by: '<S9>/Constant1'
                                        */

#define ScpAp_VechilestateEstimation_L2p_STOP_SEC_CALIB
#include "ScpAp_VechilestateEstimation_L2p_MemMap.h"

/* Exported data declaration */

/* Const memory section */
/* Declaration for custom storage class: Const */
extern const uint16 WhlSpd_Max;        /* Referenced by:
                                        * '<S7>/Constant12'
                                        * '<S9>/Constant3'
                                        */
extern const uint16 WhlSpd_Min;        /* Referenced by:
                                        * '<S7>/Constant11'
                                        * '<S9>/Constant2'
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
 * '<Root>' : 'ScpAp_VechilestateEstimation_L2p'
 * '<S1>'   : 'ScpAp_VechilestateEstimation_L2p/ScpAp_VechilestateEstimation_L2p_Init'
 * '<S2>'   : 'ScpAp_VechilestateEstimation_L2p/VehstateEst_Main_sys'
 * '<S3>'   : 'ScpAp_VechilestateEstimation_L2p/VehstateEst_Main_sys/Comm_Rx'
 * '<S4>'   : 'ScpAp_VechilestateEstimation_L2p/VehstateEst_Main_sys/Comm_Tx'
 * '<S5>'   : 'ScpAp_VechilestateEstimation_L2p/VehstateEst_Main_sys/SWC2_Control'
 * '<S6>'   : 'ScpAp_VechilestateEstimation_L2p/VehstateEst_Main_sys/SWC2_Control/Motor_Speed'
 * '<S7>'   : 'ScpAp_VechilestateEstimation_L2p/VehstateEst_Main_sys/SWC2_Control/SensorFault'
 * '<S8>'   : 'ScpAp_VechilestateEstimation_L2p/VehstateEst_Main_sys/SWC2_Control/VehAccel_L2'
 * '<S9>'   : 'ScpAp_VechilestateEstimation_L2p/VehstateEst_Main_sys/SWC2_Control/Vehicle_Speed_L2'
 * '<S10>'  : 'ScpAp_VechilestateEstimation_L2p/VehstateEst_Main_sys/SWC2_Control/Wheel_Spd_Avg'
 * '<S11>'  : 'ScpAp_VechilestateEstimation_L2p/VehstateEst_Main_sys/SWC2_Control/VehAccel_L2/Cal_VehicleAccel_L2 '
 * '<S12>'  : 'ScpAp_VechilestateEstimation_L2p/VehstateEst_Main_sys/SWC2_Control/Wheel_Spd_Avg/Valid_Wheels_Chk'
 * '<S13>'  : 'ScpAp_VechilestateEstimation_L2p/VehstateEst_Main_sys/SWC2_Control/Wheel_Spd_Avg/Valid_Wheels_Chk/Chk_Valid_Wheel_FL'
 * '<S14>'  : 'ScpAp_VechilestateEstimation_L2p/VehstateEst_Main_sys/SWC2_Control/Wheel_Spd_Avg/Valid_Wheels_Chk/Chk_Valid_Wheel_FR'
 * '<S15>'  : 'ScpAp_VechilestateEstimation_L2p/VehstateEst_Main_sys/SWC2_Control/Wheel_Spd_Avg/Valid_Wheels_Chk/Chk_Valid_Wheel_R'
 */
#endif                                 /* ScpAp_VechilestateEstimation_L2p_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
