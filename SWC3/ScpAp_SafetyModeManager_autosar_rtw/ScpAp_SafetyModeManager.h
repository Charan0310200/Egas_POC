/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ScpAp_SafetyModeManager.h
 *
 * Code generated for Simulink model 'ScpAp_SafetyModeManager'.
 *
 * Model version                  : 1.64
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Sun Feb  8 19:19:03 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef ScpAp_SafetyModeManager_h_
#define ScpAp_SafetyModeManager_h_
#ifndef ScpAp_SafetyModeManager_COMMON_INCLUDES_
#define ScpAp_SafetyModeManager_COMMON_INCLUDES_
#include "Platform_Types.h"
#include "Rte_ScpAp_SafetyModeManager.h"
#endif                            /* ScpAp_SafetyModeManager_COMMON_INCLUDES_ */

#include "ScpAp_SafetyModeManager_types.h"
#include "Rte_Type.h"

/* Static Memory for Internal Data */

/* SwAddrMethod AswVariable for Internal Data */
#define ScpAp_SafetyModeManager_START_SEC_AswVariable
#include "ScpAp_SafetyModeManager_MemMap.h"

extern VechSafetyStatus_L2p_IDT ScpAp_SafetyMo_VechSafetyStatus;/* '<S3>/Data Type Conversion' */
extern SafetyMode_L2p_IDT ScpAp_SafetyModeManage_Mode_L2p;/* '<S5>/Autonomous' */
extern SafetyMode_L2p_IDT ScpAp_SafetyM_AutonomousAllowed;/* '<S5>/Switch' */
extern boolean ScpAp_SafetyModeManage_Mode_Chk;/* '<S5>/Relational Operator' */
extern boolean ScpAp_SafetyModeMana_Status_Chk;/* '<S5>/Relational Operator1' */

#define ScpAp_SafetyModeManager_STOP_SEC_AswVariable
#include "ScpAp_SafetyModeManager_MemMap.h"

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
 * '<Root>' : 'ScpAp_SafetyModeManager'
 * '<S1>'   : 'ScpAp_SafetyModeManager/SafetyModeManager_Main_sys'
 * '<S2>'   : 'ScpAp_SafetyModeManager/ScpAp_SafetyModeManager_Init'
 * '<S3>'   : 'ScpAp_SafetyModeManager/SafetyModeManager_Main_sys/Comm_Rx'
 * '<S4>'   : 'ScpAp_SafetyModeManager/SafetyModeManager_Main_sys/Comm_Tx'
 * '<S5>'   : 'ScpAp_SafetyModeManager/SafetyModeManager_Main_sys/SWC3_Control'
 */
#endif                                 /* ScpAp_SafetyModeManager_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
