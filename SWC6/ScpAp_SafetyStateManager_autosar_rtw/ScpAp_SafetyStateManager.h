/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ScpAp_SafetyStateManager.h
 *
 * Code generated for Simulink model 'ScpAp_SafetyStateManager'.
 *
 * Model version                  : 1.148
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Thu Feb 19 12:25:02 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef ScpAp_SafetyStateManager_h_
#define ScpAp_SafetyStateManager_h_
#ifndef ScpAp_SafetyStateManager_COMMON_INCLUDES_
#define ScpAp_SafetyStateManager_COMMON_INCLUDES_
#include "Platform_Types.h"
#include "Rte_ScpAp_SafetyStateManager.h"
#endif                           /* ScpAp_SafetyStateManager_COMMON_INCLUDES_ */

#include "ScpAp_SafetyStateManager_types.h"
#include "Rte_Type.h"

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  SG_mWhdCtrl_IDT PP_SG_mWhdCtrl_SG_mWhdCtrl_VDP;
                                   /* '<Root>/PP_SG_mWhdCtrl_SG_mWhdCtrl_VDP' */
  SG_mBrkCtrl_IDT PP_SG_mBrkCtrl_SG_mBrkCtrl_VDP;
                                   /* '<Root>/PP_SG_mBrkCtrl_SG_mBrkCtrl_VDP' */
  float32 In1;                         /* '<S1>/EGAS_StateMachine' */
  float32 In2;                         /* '<S1>/EGAS_StateMachine' */
  float32 Min;                         /* '<S6>/Min' */
  float32 Brake_Decel_Level;           /* '<S1>/EGAS_StateMachine' */
  float32 Brake_Limp;                  /* '<S1>/EGAS_StateMachine' */
  float32 Brake_Max_Safe;              /* '<S1>/EGAS_StateMachine' */
  float32 Torque_Decel_Limit;          /* '<S1>/EGAS_StateMachine' */
  VechSafetyStatus_L2p_IDT VechSafetyStatus_L2p;/* '<S4>/VechSafetyStatus_L2p' */
  uint8 is_active_c1_ScpAp_SafetyStateM;/* '<S1>/EGAS_StateMachine' */
  uint8 is_c1_ScpAp_SafetyStateManager;/* '<S1>/EGAS_StateMachine' */
  uint8 temporalCounter_i1;            /* '<S1>/EGAS_StateMachine' */
  boolean SafetyOverspeedFlag;
                /* '<S3>/RP_ScpAp_SafetyOverspeedFlag_IF_SafetyOverspeedFlag' */
  boolean SafetySpeedMonitorFaultFlag;
  /* '<S3>/RP_ScpAP_SafetySpeedMonitorFaultFlag_IF_SafetySpeedMonitorFaultFlag' */
} ARID_DEF_ScpAp_SafetyStateMan_T;

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_ScpAp_SafetyStateMan_T ScpAp_SafetyStateManag_ARID_DEF;
                                   /* '<Root>/PP_SG_mWhdCtrl_SG_mWhdCtrl_VDP' */

/* Static Memory for Internal Data */

/* SwAddrMethod ASW_Variables for Internal Data */
#define ScpAp_SafetyStateManager_START_SEC_ASW_Variables
#include "ScpAp_SafetyStateManager_MemMap.h"

extern float32 ScpAp_SafetyStateManag_BrkTrqRq;/* '<S1>/EGAS_StateMachine' */
extern float32 ScpAp_SafetyStateManager_TrqCmd;/* '<S1>/EGAS_StateMachine' */
extern float32 ScpAp_SafetyStateManager_SpdCmd;/* '<S4>/Constant18' */
extern float32 ScpAp_SafetyStateMan_SpdSlewLmt;/* '<S4>/Constant19' */
extern float32 ScpAp_SafetyStateMan_TrqSlewLmt;/* '<S4>/Constant20' */
extern float32 ScpAp_SafetyS_SafeTorquecmd_L2p;/* '<S3>/Data Type Conversion' */
extern uint8 ScpAp_SafetySta_MsgCrc_mBrkCtrl;/* '<S4>/Constant10' */
extern uint8 ScpAp_SafetyStateManager_EPBCmd;/* '<S4>/Constant7' */
extern uint8 ScpAp_SafetySt_MsgCntr_mBrkCtrl;/* '<S4>/Constant9' */
extern uint8 ScpAp_SafetyStateM_CtrlMode_Whd;/* '<S4>/Constant12' */
extern uint8 ScpAp_SafetySt_MsgCntr_mWhdCtrl;/* '<S4>/Constant15' */
extern uint8 ScpAp_SafetySta_MsgCrc_mWhdCtrl;/* '<S4>/Constant16' */
extern uint8 ScpAp_SafetyStateManage_MtrMode;/* '<S4>/Constant17' */
extern VechSafetyStatus_L2p_IDT ScpAp_SafetySta_MultiportSwitch;/* '<S1>/Multiport Switch' */
extern boolean ScpAp_SafetySta_Aeb_Active_Ebcm;/* '<S4>/Constant' */
extern boolean ScpAp_SafetyStat_BrkEnbl_EBCM2L;/* '<S4>/Constant1' */
extern boolean ScpAp_SafetySta_ClearFltRq_Ebcm;/* '<S4>/Constant2' */
extern boolean ScpAp_SafetyStateManage_DsblTCS;/* '<S4>/Constant3' */
extern boolean ScpAp_SafetySta_EbcmMaintModeRq;/* '<S4>/Constant4' */
extern boolean ScpAp_SafetyStateM_EbcmShtdwnRq;/* '<S4>/Constant5' */
extern boolean ScpAp_SafetyStateMana_EpbCalCmd;/* '<S4>/Constant6' */
extern boolean ScpAp_SafetyStateManager_HoldRq;/* '<S4>/Constant8' */
extern boolean ScpAp_SafetyStateManager_Boot;/* '<S4>/Constant11' */
extern boolean ScpAp_SafetyStateManager_Debug;/* '<S4>/Constant13' */
extern boolean ScpAp_SafetyStateManage_EnblCmd;/* '<S4>/Constant14' */

#define ScpAp_SafetyStateManager_STOP_SEC_ASW_Variables
#include "ScpAp_SafetyStateManager_MemMap.h"

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
 * '<Root>' : 'ScpAp_SafetyStateManager'
 * '<S1>'   : 'ScpAp_SafetyStateManager/SafetyState_Main_sys'
 * '<S2>'   : 'ScpAp_SafetyStateManager/ScpAp_SafetyStateManager_Init'
 * '<S3>'   : 'ScpAp_SafetyStateManager/SafetyState_Main_sys/Comm_Rx'
 * '<S4>'   : 'ScpAp_SafetyStateManager/SafetyState_Main_sys/Comm_Tx'
 * '<S5>'   : 'ScpAp_SafetyStateManager/SafetyState_Main_sys/EGAS_StateMachine'
 * '<S6>'   : 'ScpAp_SafetyStateManager/SafetyState_Main_sys/EGAS_StateMachine/Minimum'
 */
#endif                                 /* ScpAp_SafetyStateManager_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
