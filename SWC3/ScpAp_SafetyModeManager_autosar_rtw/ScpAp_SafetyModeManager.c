/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ScpAp_SafetyModeManager.c
 *
 * Code generated for Simulink model 'ScpAp_SafetyModeManager'.
 *
 * Model version                  : 1.75
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Thu Feb 12 16:24:11 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ScpAp_SafetyModeManager.h"
#include "Platform_Types.h"
#include "Rte_Type.h"

/* PublicStructure Variables for Internal Data */
ARID_DEF_ScpAp_SafetyModeMana_T ScpAp_SafetyModeManage_ARID_DEF;
              /* '<S3>/RP_ScpAp_VechSafetyStatus_L2p_IF_VechSafetyStatus_L2p' */

/* Static Memory for Internal Data */

/* SwAddrMethod AswVariable for Internal Data */
#define ScpAp_SafetyModeManager_START_SEC_AswVariable
#include "ScpAp_SafetyModeManager_MemMap.h"

SafetyMode_L2p_IDT ScpAp_SafetyModeManage_Mode_L2p;/* '<S5>/Autonomous' */
boolean ScpAp_SafetyModeMana_Status_Chk;/* '<S5>/Relational Operator1' */
boolean ScpAp_SafetyM_AutonomousAllowed;/* '<S5>/Switch' */
boolean ScpAp_SafetyModeManage_Mode_Chk;/* '<S5>/Relational Operator' */

#define ScpAp_SafetyModeManager_STOP_SEC_AswVariable
#include "ScpAp_SafetyModeManager_MemMap.h"

/* Model step function */

/* SwAddrMethod CODE for Runnable */
#define ScpAp_SafetyModeManager_START_SEC_CODE
#include "ScpAp_SafetyModeManager_MemMap.h"

void SafetyModeManager_Main(void)
{
  /* SignalConversion generated from: '<S3>/RP_ScpAp_VechSafetyStatus_L2p_IF_VechSafetyStatus_L2p' incorporates:
   *  Inport: '<Root>/RP_ScpAp_VechSafetyStatus_L2p_IF_VechSafetyStatus_L2p'
   */
  (void)Rte_Read_RP_ScpAp_VechSafetyStatus_L2p_IF_VechSafetyStatus_L2p
    (&ScpAp_SafetyModeManage_ARID_DEF.VechSafetyStatus);

  /* Outputs for Atomic SubSystem: '<Root>/SafetyModeManager_Main_sys' */
  /* Outputs for Atomic SubSystem: '<S1>/SWC3_Control' */
  /* RelationalOperator: '<S5>/Relational Operator1' incorporates:
   *  Constant: '<S5>/Constant4'
   *  SignalConversion generated from: '<S3>/RP_ScpAp_VechSafetyStatus_L2p_IF_VechSafetyStatus_L2p'
   */
  ScpAp_SafetyModeMana_Status_Chk =
    (ScpAp_SafetyModeManage_ARID_DEF.VechSafetyStatus == NORMAL);

  /* Switch: '<S5>/Switch' incorporates:
   *  Logic: '<S5>/AND'
   */
  ScpAp_SafetyM_AutonomousAllowed = (ScpAp_SafetyModeManage_Mode_Chk &&
    ScpAp_SafetyModeMana_Status_Chk);

  /* End of Outputs for SubSystem: '<S1>/SWC3_Control' */

  /* Outputs for Atomic SubSystem: '<S1>/Comm_Tx' */
  /* SignalConversion generated from: '<S4>/AutonomousAllowed' */
  ScpAp_SafetyModeManage_ARID_DEF.AutonomousAllowed_d =
    ScpAp_SafetyM_AutonomousAllowed;

  /* SignalConversion generated from: '<S4>/Mode_L2p' incorporates:
   *  SignalConversion generated from: '<S5>/Autonomous'
   */
  ScpAp_SafetyModeManage_ARID_DEF.Mode_L2p_b = ScpAp_SafetyModeManage_Mode_L2p;

  /* End of Outputs for SubSystem: '<S1>/Comm_Tx' */
  /* End of Outputs for SubSystem: '<Root>/SafetyModeManager_Main_sys' */

  /* Outport: '<Root>/PP_AutonomousAllowed_IF_AutonomousAllowed' */
  (void)Rte_Write_PP_AutonomousAllowed_IF_AutonomousAllowed
    (ScpAp_SafetyModeManage_ARID_DEF.AutonomousAllowed_d);

  /* Outport: '<Root>/PP_Mode_L2p_IF_SafetyMode_L2p' incorporates:
   *  SignalConversion generated from: '<S4>/Mode_L2p'
   */
  (void)Rte_Write_PP_Mode_L2p_IF_SafetyMode_L2p
    (ScpAp_SafetyModeManage_ARID_DEF.Mode_L2p_b);
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
  ScpAp_SafetyModeManage_ARID_DEF.Mode_L2p_b = AUTONOMOUS;
  ScpAp_SafetyModeManage_Mode_L2p = AUTONOMOUS;

  /* ConstCode for Atomic SubSystem: '<Root>/SafetyModeManager_Main_sys' */
  /* ConstCode for Atomic SubSystem: '<S1>/SWC3_Control' */
  /* ConstCode for SignalConversion generated from: '<S5>/Autonomous' incorporates:
   *  Constant: '<S1>/Constant'
   */
  ScpAp_SafetyModeManage_Mode_L2p = AUTONOMOUS;

  /* ConstCode for RelationalOperator: '<S5>/Relational Operator' */
  ScpAp_SafetyModeManage_Mode_Chk = TRUE;

  /* End of ConstCode for SubSystem: '<S1>/SWC3_Control' */
  /* End of ConstCode for SubSystem: '<Root>/SafetyModeManager_Main_sys' */
}

#define ScpAp_SafetyModeManager_STOP_SEC_CODE
#include "ScpAp_SafetyModeManager_MemMap.h"

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
