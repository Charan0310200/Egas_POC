/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ScpAp_SpeedSupervision.h
 *
 * Code generated for Simulink model 'ScpAp_SpeedSupervision'.
 *
 * Model version                  : 1.104
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Mon Feb 16 11:15:04 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef ScpAp_SpeedSupervision_h_
#define ScpAp_SpeedSupervision_h_
#ifndef ScpAp_SpeedSupervision_COMMON_INCLUDES_
#define ScpAp_SpeedSupervision_COMMON_INCLUDES_
#include "Platform_Types.h"
#include "Rte_ScpAp_SpeedSupervision.h"
#endif                             /* ScpAp_SpeedSupervision_COMMON_INCLUDES_ */

#include "ScpAp_SpeedSupervision_types.h"
#include "Rte_Type.h"

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  float32 IMU_AccelX_L1p;  /* '<S3>/RP_ScpAp_IMU_AccelX_L1_IF_IMU_AccelX_L1p' */
  sint16 SafeTorquecmd_L2p;            /* '<S4>/SafeTorquecmd_L2p' */
  sint16 NominalTorquecmd_L2p;
              /* '<S3>/RP_ScpAP_NominalTorquecmd_L2p_IF_NominalTorquecmd_L2p' */
  sint16 VechileAccel_L2p;
                      /* '<S3>/RP_ScpAP_VechileAccel_L2p_IF_VechileAccel_L2p' */
  uint16 Vechilespeed_L2p;
                      /* '<S3>/RP_ScpAp_Vechilespeed_L2p_IF_Vechilespeed_L2p' */
  uint8 MotorSpeed_L1p;   /* '<S3>/RP_ScpAp_MotorSpeed_L1p_IF_MotorSpeed_L1p' */
  SafetyMode_L2p_IDT SafetyMode_L2p;
                                /* '<S3>/RP_ScpAp_Mode_L2p_IF_SafetyMode_L2p' */
  boolean SafetyOverspeedFlag;         /* '<S4>/SafetyOverspeedFlag' */
  boolean SafetySpeedMonitorFaultFlag; /* '<S4>/SafetySpeedMonitorFaultFlag' */
  boolean AutonomousAllowed;
                    /* '<S3>/RP_ScpAp_AutonomousAllowed_IF_AutonomousAllowed' */
} ARID_DEF_ScpAp_SpeedSupervisi_T;

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_ScpAp_SpeedSupervisi_T ScpAp_SpeedSupervision_ARID_DEF;
                           /* '<S3>/RP_ScpAp_IMU_AccelX_L1_IF_IMU_AccelX_L1p' */

/* Static Memory for Internal Data */

/* SwAddrMethod ASW_Variables for Internal Data */
#define ScpAp_SpeedSupervision_START_SEC_ASW_Variables
#include "ScpAp_SpeedSupervision_MemMap.h"

extern float64 ScpAp_S_SpeedMonitorFaultFlag_1;/* '<S5>/Switch' */
extern float64 ScpAp_SpeedSupe_Predicted_Speed;/* '<S5>/Add' */
extern float64 ScpAp_Spee_OverspeedPredictFlag;/* '<S5>/Switch3' */
extern float64 ScpAp_S_SpeedMonitorFault_Flg_3;/* '<S5>/Switch7' */
extern float64 ScpAp_SpeedS_OverSpeedFlg_Raw_2;/* '<S5>/Switch6' */
extern float64 ScpAp_S_SpeedMonitorFault_Flg_2;/* '<S7>/Switch6' */
extern sint16 ScpAp_Spee_OvrSpdPredictFlg_Chk;/* '<S5>/Switch5' */
extern sint16 ScpAp_SpeedSuper_OverSpdFlg_Chk;/* '<S5>/Switch4' */
extern sint16 ScpAp_SpeedSup_SafeTorqueCmd_L2;/* '<S5>/Switch2' */
extern boolean ScpAp_SpeedSupervisi_Autonomous;/* '<S5>/Switch1' */
extern boolean ScpAp_Spe_SpeedMonitorFaultFlag;/* '<S5>/Unit Delay' */
extern boolean ScpAp_SpeedSup_OverSpeedFlg_Raw;/* '<S5>/Unit Delay1' */
extern boolean ScpAp_NominalTrq_Equal_SafeTrq;/* '<S5>/Relational Operator6' */
extern boolean ScpAp_SpeedS_OverSpeedFlg_Raw_1;/* '<S6>/Switch2' */
extern boolean ScpAp_Spe_OverspeedFlag_Latched;/* '<S6>/Switch3' */
extern boolean ScpAp_SpeedSuperv_OverSpeed_Flg;/* '<S6>/Switch5' */
extern boolean SpeedMonitorFaultFlag;  /* '<S5>/Unit Delay' */
extern boolean OverSpeedFlg_Raw;       /* '<S5>/Unit Delay1' */

#define ScpAp_SpeedSupervision_STOP_SEC_ASW_Variables
#include "ScpAp_SpeedSupervision_MemMap.h"

/* Constant memory autosar model workspace parameters */

/* SwAddrMethod CALIB for Model Work Space Parameters */
#define ScpAp_SpeedSupervision_START_SEC_CALIB
#include "ScpAp_SpeedSupervision_MemMap.h"

extern const float64 K_Pred;           /* Variable: K_Pred
                                        * Referenced by: '<S5>/Constant10'
                                        */
extern const float64 TH_Hystersis;     /* Variable: TH_Hystersis
                                        * Referenced by: '<S6>/Constant11'
                                        */
extern const float64 TH_Mon_Accel_Diff;/* Variable: TH_Mon_Accel_Diff
                                        * Referenced by: '<S5>/Constant'
                                        */
extern const float64 TH_Mon_Speed_Diff;/* Variable: TH_Mon_Speed_Diff
                                        * Referenced by: '<S7>/Constant16'
                                        */
extern const float64 TH_Pred_Margin;   /* Variable: TH_Pred_Margin
                                        * Referenced by: '<S5>/Constant12'
                                        */
extern const float64 TH_Speed_Limit_Margin;/* Variable: TH_Speed_Limit_Margin
                                            * Referenced by: '<S6>/Constant6'
                                            */
extern const sint16 Torque_Decel_Limit;/* Variable: Torque_Decel_Limit
                                        * Referenced by: '<S5>/Constant15'
                                        */
extern const sint16 Torque_PreLimit;   /* Variable: Torque_PreLimit
                                        * Referenced by: '<S5>/Constant16'
                                        */

#define ScpAp_SpeedSupervision_STOP_SEC_CALIB
#include "ScpAp_SpeedSupervision_MemMap.h"

/* Exported data declaration */

/* Const memory section */
/* Declaration for custom storage class: Const */
extern const uint16 WhlSpd_Max;        /* Referenced by:
                                        * '<S5>/Constant11'
                                        * '<S6>/Constant10'
                                        * '<S6>/Constant5'
                                        */

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S7>/Abs1' : Eliminated since data is unsigned
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
 * '<Root>' : 'ScpAp_SpeedSupervision'
 * '<S1>'   : 'ScpAp_SpeedSupervision/SafetySpeedSuperv_Main_sys'
 * '<S2>'   : 'ScpAp_SpeedSupervision/ScpAp_SpeedSupervision_Init'
 * '<S3>'   : 'ScpAp_SpeedSupervision/SafetySpeedSuperv_Main_sys/Comm_Rx'
 * '<S4>'   : 'ScpAp_SpeedSupervision/SafetySpeedSuperv_Main_sys/Comm_Tx'
 * '<S5>'   : 'ScpAp_SpeedSupervision/SafetySpeedSuperv_Main_sys/SWC5_Control'
 * '<S6>'   : 'ScpAp_SpeedSupervision/SafetySpeedSuperv_Main_sys/SWC5_Control/Autonomous_Mode_Cal'
 * '<S7>'   : 'ScpAp_SpeedSupervision/SafetySpeedSuperv_Main_sys/SWC5_Control/Manual_Mode_Cal'
 */
#endif                                 /* ScpAp_SpeedSupervision_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
