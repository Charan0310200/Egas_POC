/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ScpAp_SafetyModeManager.c
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

#include "ScpAp_SafetyModeManager.h"
#include "Rte_Type.h"
#include "Platform_Types.h"

/* Static Memory for Internal Data */

/* SwAddrMethod AswVariable for Internal Data */
#define ScpAp_SafetyModeManager_START_SEC_AswVariable
#include "ScpAp_SafetyModeManager_MemMap.h"

VechSafetyStatus_L2p_IDT ScpAp_SafetyMo_VechSafetyStatus;/* '<S3>/Data Type Conversion' */
SafetyMode_L2p_IDT ScpAp_SafetyModeManage_Mode_L2p;/* '<S5>/Autonomous' */
SafetyMode_L2p_IDT ScpAp_SafetyM_AutonomousAllowed;/* '<S5>/Switch' */
boolean ScpAp_SafetyModeManage_Mode_Chk;/* '<S5>/Relational Operator' */
boolean ScpAp_SafetyModeMana_Status_Chk;/* '<S5>/Relational Operator1' */

#define ScpAp_SafetyModeManager_STOP_SEC_AswVariable
#include "ScpAp_SafetyModeManager_MemMap.h"

/* Model step function */

/* SwAddrMethod CODE for Runnable */
#define ScpAp_SafetyModeManager_START_SEC_CODE
#include "ScpAp_SafetyModeManager_MemMap.h"

void SafetyModeManager_Main(void)
{
  /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/RP_ScpAp_VechSafetyStatus_L2p_IF_VechSafetyStatus_L2p'
   */
  (void)Rte_Read_RP_ScpAp_VechSafetyStatus_L2p_IF_VechSafetyStatus_L2p
    (&ScpAp_SafetyMo_VechSafetyStatus);

  /* Outputs for Atomic SubSystem: '<Root>/SafetyModeManager_Main_sys' */
  /* Outputs for Atomic SubSystem: '<S1>/SWC3_Control' */
  /* SignalConversion generated from: '<S5>/Autonomous' incorporates:
   *  Constant: '<S1>/Constant'
   */
  ScpAp_SafetyModeManage_Mode_L2p = AUTONOMOUS;

  /* RelationalOperator: '<S5>/Relational Operator' */
  ScpAp_SafetyModeManage_Mode_Chk = TRUE;

  /* RelationalOperator: '<S5>/Relational Operator1' incorporates:
   *  Constant: '<S5>/Constant4'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  ScpAp_SafetyModeMana_Status_Chk = (ScpAp_SafetyMo_VechSafetyStatus == NORMAL);

  /* Switch: '<S5>/Switch' incorporates:
   *  Logic: '<S5>/AND'
   */
  if (ScpAp_SafetyModeMana_Status_Chk) {
    /* Switch: '<S5>/Switch' incorporates:
     *  Constant: '<S5>/Constant'
     */
    ScpAp_SafetyM_AutonomousAllowed = AUTONOMOUS;
  } else {
    /* Switch: '<S5>/Switch' incorporates:
     *  Constant: '<S5>/Constant2'
     */
    ScpAp_SafetyM_AutonomousAllowed = MANUAL;
  }

  /* End of Switch: '<S5>/Switch' */
  /* End of Outputs for SubSystem: '<S1>/SWC3_Control' */
  /* End of Outputs for SubSystem: '<Root>/SafetyModeManager_Main_sys' */

  /* Outport: '<Root>/PP_AutonomousAllowed_IF_AutonomousAllowed' incorporates:
   *  Switch: '<S5>/Switch'
   */
  (void)Rte_Write_PP_AutonomousAllowed_IF_AutonomousAllowed
    (ScpAp_SafetyM_AutonomousAllowed);

  /* Outport: '<Root>/PP_Mode_L2p_IF_SafetyMode_L2p' incorporates:
   *  SignalConversion generated from: '<S5>/Autonomous'
   */
  (void)Rte_Write_PP_Mode_L2p_IF_SafetyMode_L2p(1U);
}

#define ScpAp_SafetyModeManager_STOP_SEC_CODE
#include "ScpAp_SafetyModeManager_MemMap.h"

/* Model initialize function */

/* SwAddrMethod CODE for Runnable */
#define ScpAp_SafetyModeManager_START_SEC_CODE
#include "ScpAp_SafetyModeManager_MemMap.h"

void ScpAp_SafetyModeManager_Init(void)
{
  /* Registration code */
  ScpAp_SafetyModeManage_Mode_L2p = AUTONOMOUS;
  ScpAp_SafetyM_AutonomousAllowed = AUTONOMOUS;
}

#define ScpAp_SafetyModeManager_STOP_SEC_CODE
#include "ScpAp_SafetyModeManager_MemMap.h"

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
