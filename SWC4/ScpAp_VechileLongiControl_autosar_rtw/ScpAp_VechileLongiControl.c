/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ScpAp_VechileLongiControl.c
 *
 * Code generated for Simulink model 'ScpAp_VechileLongiControl'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Tue Feb 17 16:18:36 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ScpAp_VechileLongiControl.h"
#include <math.h>
#include "Rte_Type.h"
#include "Platform_Types.h"

/* PublicStructure Variables for Internal Data */
ARID_DEF_ScpAp_VechileLongiCo_T ScpAp_VechileLongiCont_ARID_DEF;
                      /* '<S3>/RP_ScpAp_Vechilespeed_L2p_IF_Vechilespeed_L2p' */

/* Static Memory for Internal Data */

/* SwAddrMethod ASW_Variables for Internal Data */
#define ScpAp_VechileLongiControl_START_SEC_ASW_Variables
#include "ScpAp_VechileLongiControl_MemMap.h"

float64 Integrator_State;              /* '<S6>/Unit Delay' */
float32 ScpAp_VechileLong_VehSpdCmd_Kph;/* '<S6>/m//s to Kmph' */
float32 ScpAp_VechileLongiC_Speed_Error;/* '<S6>/Subtract' */
sint16 ScpAp_Vech_NominalTorquecmd_L2p;/* '<S5>/Switch' */
sint16 ScpAp_Clamped_Integrator_State; /* '<S6>/Data Type Conversion' */
sint16 ScpAp_Vechile_proportional_term;/* '<S6>/Data Type Conversion1' */
sint16 ScpAp_VechileLongiC_Control_raw;/* '<S6>/Add1' */
sint16 ScpAp_Cal_NominalTorquecmd_L2p; /* '<S6>/Saturation2' */

#define ScpAp_VechileLongiControl_STOP_SEC_ASW_Variables
#include "ScpAp_VechileLongiControl_MemMap.h"

/* Model step function */

/* SwAddrMethod CODE for Runnable */
#define ScpAp_VechileLongiControl_START_SEC_CODE
#include "ScpAp_VechileLongiControl_MemMap.h"

void VechileLongiControl_Main(void)
{
  SG_mVehCtrlADRq_IDT_E2E tmpRead;
  float64 tmp;
  float32 tmp_0;

  /* Inport: '<Root>/RP_ScpApADRx_SG_mVehCtrlADRq_SG_mVehCtrlADRq' */
  (void)Rte_Read_RP_ScpApADRx_SG_mVehCtrlADRq_SG_mVehCtrlADRq(&tmpRead);

  /* SignalConversion generated from: '<S3>/RP_ScpAp_Vechilespeed_L2p_IF_Vechilespeed_L2p' incorporates:
   *  Inport: '<Root>/RP_ScpAp_Vechilespeed_L2p_IF_Vechilespeed_L2p'
   */
  (void)Rte_Read_RP_ScpAp_Vechilespeed_L2p_IF_Vechilespeed_L2p
    (&ScpAp_VechileLongiCont_ARID_DEF.Vechilespeed_L2p);

  /* SignalConversion generated from: '<S3>/RP_ScpAp_Mode_L2p_IF_SafetyMode_L2p' incorporates:
   *  Inport: '<Root>/RP_ScpAp_Mode_L2p_IF_SafetyMode_L2p'
   */
  (void)Rte_Read_RP_ScpAp_Mode_L2p_IF_SafetyMode_L2p
    (&ScpAp_VechileLongiCont_ARID_DEF.Mode_L2p);

  /* Outputs for Atomic SubSystem: '<Root>/VechileLongiControl_Main_sys' */
  /* Outputs for Atomic SubSystem: '<S2>/SWC4_Control' */
  /* Outputs for Atomic SubSystem: '<S5>/Calculate_NominalTorquecmd_L2p' */
  /* Saturate: '<S6>/Saturation1' incorporates:
   *  UnitDelay: '<S6>/Unit Delay'
   */
  if (Integrator_State > 30.0) {
    tmp = 30.0;
  } else if (Integrator_State < -30.0) {
    tmp = -30.0;
  } else {
    tmp = Integrator_State;
  }

  /* DataTypeConversion: '<S6>/Data Type Conversion' incorporates:
   *  Saturate: '<S6>/Saturation1'
   */
  tmp = fmod(floor(tmp), 65536.0);
  if (tmp < 0.0) {
    /* DataTypeConversion: '<S6>/Data Type Conversion' */
    ScpAp_Clamped_Integrator_State = (sint16)-(sint16)(uint16)-tmp;
  } else {
    /* DataTypeConversion: '<S6>/Data Type Conversion' */
    ScpAp_Clamped_Integrator_State = (sint16)(uint16)tmp;
  }

  /* End of DataTypeConversion: '<S6>/Data Type Conversion' */

  /* Outputs for Atomic SubSystem: '<S2>/Comm_Rx' */
  /* Gain: '<S6>/m//s to Kmph' incorporates:
   *  SignalConversion generated from: '<S3>/Bus Selector'
   */
  ScpAp_VechileLong_VehSpdCmd_Kph = 3.6F * tmpRead.VehSpdCmd;

  /* End of Outputs for SubSystem: '<S2>/Comm_Rx' */

  /* Saturate: '<S6>/Saturation' */
  if (ScpAp_VechileLong_VehSpdCmd_Kph > 32.0F) {
    tmp_0 = 32.0F;
  } else if (ScpAp_VechileLong_VehSpdCmd_Kph < 0.0F) {
    tmp_0 = 0.0F;
  } else {
    tmp_0 = ScpAp_VechileLong_VehSpdCmd_Kph;
  }

  /* Sum: '<S6>/Subtract' incorporates:
   *  Saturate: '<S6>/Saturation'
   */
  ScpAp_VechileLongiC_Speed_Error = tmp_0 - (float32)
    ScpAp_VechileLongiCont_ARID_DEF.Vechilespeed_L2p;

  /* DataTypeConversion: '<S6>/Data Type Conversion1' incorporates:
   *  Gain: '<S6>/Gain1'
   */
  tmp_0 = fmodf(floorf(4.0F * ScpAp_VechileLongiC_Speed_Error), 65536.0F);
  if (tmp_0 < 0.0F) {
    /* DataTypeConversion: '<S6>/Data Type Conversion1' */
    ScpAp_Vechile_proportional_term = (sint16)-(sint16)(uint16)-tmp_0;
  } else {
    /* DataTypeConversion: '<S6>/Data Type Conversion1' */
    ScpAp_Vechile_proportional_term = (sint16)(uint16)tmp_0;
  }

  /* End of DataTypeConversion: '<S6>/Data Type Conversion1' */

  /* Sum: '<S6>/Add1' */
  ScpAp_VechileLongiC_Control_raw = (sint16)(ScpAp_Vechile_proportional_term +
    ScpAp_Clamped_Integrator_State);

  /* Saturate: '<S6>/Saturation2' */
  if (ScpAp_VechileLongiC_Control_raw > 120) {
    /* Saturate: '<S6>/Saturation2' */
    ScpAp_Cal_NominalTorquecmd_L2p = 120;
  } else if (ScpAp_VechileLongiC_Control_raw < -70) {
    /* Saturate: '<S6>/Saturation2' */
    ScpAp_Cal_NominalTorquecmd_L2p = -70;
  } else {
    /* Saturate: '<S6>/Saturation2' */
    ScpAp_Cal_NominalTorquecmd_L2p = ScpAp_VechileLongiC_Control_raw;
  }

  /* End of Saturate: '<S6>/Saturation2' */

  /* Sum: '<S6>/Add' incorporates:
   *  Constant: '<S6>/Constant'
   *  Gain: '<S6>/Gain'
   *  Product: '<S6>/Product'
   *  UnitDelay: '<S6>/Unit Delay'
   */
  Integrator_State += 0.7F * ScpAp_VechileLongiC_Speed_Error * 0.01;

  /* End of Outputs for SubSystem: '<S5>/Calculate_NominalTorquecmd_L2p' */

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/Constant'
   *  RelationalOperator: '<S5>/Relational Operator'
   *  SignalConversion generated from: '<S3>/RP_ScpAp_Mode_L2p_IF_SafetyMode_L2p'
   */
  if (ScpAp_VechileLongiCont_ARID_DEF.Mode_L2p == AUTONOMOUS) {
    /* Switch: '<S5>/Switch' */
    ScpAp_Vech_NominalTorquecmd_L2p = ScpAp_Cal_NominalTorquecmd_L2p;
  } else {
    /* Switch: '<S5>/Switch' incorporates:
     *  Constant: '<S5>/Constant1'
     */
    ScpAp_Vech_NominalTorquecmd_L2p = 0;
  }

  /* End of Switch: '<S5>/Switch' */
  /* End of Outputs for SubSystem: '<S2>/SWC4_Control' */

  /* Outputs for Atomic SubSystem: '<S2>/Comm_Tx' */
  /* Outport: '<Root>/PP_NominalTorquecmd_L2p_IF_NominalTorquecmd_L2p' incorporates:
   *  SignalConversion generated from: '<S4>/NominalTorquecmd_L2p'
   */
  (void)Rte_Write_PP_NominalTorquecmd_L2p_IF_NominalTorquecmd_L2p
    (ScpAp_Vech_NominalTorquecmd_L2p);

  /* End of Outputs for SubSystem: '<S2>/Comm_Tx' */
  /* End of Outputs for SubSystem: '<Root>/VechileLongiControl_Main_sys' */
}

#define ScpAp_VechileLongiControl_STOP_SEC_CODE
#include "ScpAp_VechileLongiControl_MemMap.h"

/* Model initialize function */

/* SwAddrMethod CODE for Runnable */
#define ScpAp_VechileLongiControl_START_SEC_CODE
#include "ScpAp_VechileLongiControl_MemMap.h"

void ScpAp_VechileLongiControl_Init(void)
{
  /* Registration code */
  ScpAp_VechileLongiCont_ARID_DEF.Mode_L2p = AUTONOMOUS;
}

#define ScpAp_VechileLongiControl_STOP_SEC_CODE
#include "ScpAp_VechileLongiControl_MemMap.h"

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
