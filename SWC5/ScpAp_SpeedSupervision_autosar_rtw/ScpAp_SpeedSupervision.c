/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ScpAp_SpeedSupervision.c
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

#include "ScpAp_SpeedSupervision.h"
#include <math.h>
#include "Rte_Type.h"
#include "Platform_Types.h"

/* Exported data definition */

/* Const memory section */
/* Definition for custom storage class: Const */
const uint16 WhlSpd_Max = 32U;         /* Referenced by:
                                        * '<S5>/Constant11'
                                        * '<S6>/Constant10'
                                        * '<S6>/Constant5'
                                        */

/* PublicStructure Variables for Internal Data */
ARID_DEF_ScpAp_SpeedSupervisi_T ScpAp_SpeedSupervision_ARID_DEF;
                           /* '<S3>/RP_ScpAp_IMU_AccelX_L1_IF_IMU_AccelX_L1p' */

/* Static Memory for Internal Data */

/* SwAddrMethod ASW_Variables for Internal Data */
#define ScpAp_SpeedSupervision_START_SEC_ASW_Variables
#include "ScpAp_SpeedSupervision_MemMap.h"

float64 ScpAp_S_SpeedMonitorFaultFlag_1;/* '<S5>/Switch' */
float64 ScpAp_SpeedSupe_Predicted_Speed;/* '<S5>/Add' */
float64 ScpAp_Spee_OverspeedPredictFlag;/* '<S5>/Switch3' */
float64 ScpAp_S_SpeedMonitorFault_Flg_3;/* '<S5>/Switch7' */
float64 ScpAp_SpeedS_OverSpeedFlg_Raw_2;/* '<S5>/Switch6' */
float64 ScpAp_S_SpeedMonitorFault_Flg_2;/* '<S7>/Switch6' */
sint16 ScpAp_Spee_OvrSpdPredictFlg_Chk;/* '<S5>/Switch5' */
sint16 ScpAp_SpeedSuper_OverSpdFlg_Chk;/* '<S5>/Switch4' */
sint16 ScpAp_SpeedSup_SafeTorqueCmd_L2;/* '<S5>/Switch2' */
boolean ScpAp_SpeedSupervisi_Autonomous;/* '<S5>/Switch1' */
boolean ScpAp_Spe_SpeedMonitorFaultFlag;/* '<S5>/Unit Delay' */
boolean ScpAp_SpeedSup_OverSpeedFlg_Raw;/* '<S5>/Unit Delay1' */
boolean ScpAp_NominalTrq_Equal_SafeTrq;/* '<S5>/Relational Operator6' */
boolean ScpAp_SpeedS_OverSpeedFlg_Raw_1;/* '<S6>/Switch2' */
boolean ScpAp_Spe_OverspeedFlag_Latched;/* '<S6>/Switch3' */
boolean ScpAp_SpeedSuperv_OverSpeed_Flg;/* '<S6>/Switch5' */
boolean SpeedMonitorFaultFlag;         /* '<S5>/Unit Delay' */
boolean OverSpeedFlg_Raw;              /* '<S5>/Unit Delay1' */

#define ScpAp_SpeedSupervision_STOP_SEC_ASW_Variables
#include "ScpAp_SpeedSupervision_MemMap.h"

/* Model step function */

/* SwAddrMethod CODE for Runnable */
#define ScpAp_SpeedSupervision_START_SEC_CODE
#include "ScpAp_SpeedSupervision_MemMap.h"

void SafetySpeedSuperv_Main(void)
{
  IF_SensorFaultFlgs_L2p_IDT rtb_TmpSignalConversionAtRP_Scp;

  /* SignalConversion generated from: '<S3>/RP_ScpAp_Vechilespeed_L2p_IF_Vechilespeed_L2p' incorporates:
   *  Inport: '<Root>/RP_ScpAp_Vechilespeed_L2p_IF_Vechilespeed_L2p'
   */
  (void)Rte_Read_RP_ScpAp_Vechilespeed_L2p_IF_Vechilespeed_L2p
    (&ScpAp_SpeedSupervision_ARID_DEF.Vechilespeed_L2p);

  /* SignalConversion generated from: '<S3>/RP_ScpAP_VechileAccel_L2p_IF_VechileAccel_L2p' incorporates:
   *  Inport: '<Root>/RP_ScpAP_VechileAccel_L2p_IF_VechileAccel_L2p'
   */
  (void)Rte_Read_RP_ScpAP_VechileAccel_L2p_IF_VechileAccel_L2p
    (&ScpAp_SpeedSupervision_ARID_DEF.VechileAccel_L2p);

  /* SignalConversion generated from: '<S3>/RP_ScpAP_NominalTorquecmd_L2p_IF_NominalTorquecmd_L2p' incorporates:
   *  Inport: '<Root>/RP_ScpAP_NominalTorquecmd_L2p_IF_NominalTorquecmd_L2p'
   */
  (void)Rte_Read_RP_ScpAP_NominalTorquecmd_L2p_IF_NominalTorquecmd_L2p
    (&ScpAp_SpeedSupervision_ARID_DEF.NominalTorquecmd_L2p);

  /* SignalConversion generated from: '<S3>/RP_ScpAp_MotorSpeed_L1p_IF_MotorSpeed_L1p' incorporates:
   *  Inport: '<Root>/RP_ScpAp_MotorSpeed_L1p_IF_MotorSpeed_L1p'
   */
  (void)Rte_Read_RP_ScpAp_MotorSpeed_L1p_IF_MotorSpeed_L1p
    (&ScpAp_SpeedSupervision_ARID_DEF.MotorSpeed_L1p);

  /* SignalConversion generated from: '<S3>/RP_ScpAp_Mode_L2p_IF_SafetyMode_L2p' incorporates:
   *  Inport: '<Root>/RP_ScpAp_Mode_L2p_IF_SafetyMode_L2p'
   */
  (void)Rte_Read_RP_ScpAp_Mode_L2p_IF_SafetyMode_L2p
    (&ScpAp_SpeedSupervision_ARID_DEF.SafetyMode_L2p);

  /* SignalConversion generated from: '<S3>/RP_ScpAp_IMU_AccelX_L1_IF_IMU_AccelX_L1p' incorporates:
   *  Inport: '<Root>/RP_ScpAp_IMU_AccelX_L1_IF_IMU_AccelX_L1p'
   */
  (void)Rte_Read_RP_ScpAp_IMU_AccelX_L1_IF_IMU_AccelX_L1p
    (&ScpAp_SpeedSupervision_ARID_DEF.IMU_AccelX_L1p);

  /* SignalConversion generated from: '<S3>/RP_ScpAp_AutonomousAllowed_IF_AutonomousAllowed' incorporates:
   *  Inport: '<Root>/RP_ScpAp_AutonomousAllowed_IF_AutonomousAllowed'
   */
  (void)Rte_Read_RP_ScpAp_AutonomousAllowed_IF_AutonomousAllowed
    (&ScpAp_SpeedSupervision_ARID_DEF.AutonomousAllowed);

  /* SignalConversion generated from: '<Root>/RP_ScpAp_SensorValidityFlag_L2p_IF_SensorFaultFlags_L2p' incorporates:
   *  Inport: '<Root>/RP_ScpAp_SensorValidityFlag_L2p_IF_SensorFaultFlags_L2p'
   */
  (void)Rte_Read_RP_ScpAp_SensorValidityFlag_L2p_IF_SensorFaultFlags_L2p
    (&rtb_TmpSignalConversionAtRP_Scp);

  /* Outputs for Atomic SubSystem: '<Root>/SafetySpeedSuperv_Main_sys' */
  /* Outputs for Atomic SubSystem: '<S1>/SWC5_Control' */
  /* Outputs for Atomic SubSystem: '<S1>/Comm_Rx' */
  /* Switch: '<S5>/Switch' incorporates:
   *  Abs: '<S5>/Abs'
   *  Constant: '<S5>/Constant'
   *  Logic: '<S5>/OR'
   *  RelationalOperator: '<S5>/Relational Operator'
   *  SignalConversion generated from: '<S3>/Bus Selector'
   *  Sum: '<S5>/Subtract'
   * */
  ScpAp_S_SpeedMonitorFaultFlag_1 = ((fabsf((float32)
    ScpAp_SpeedSupervision_ARID_DEF.VechileAccel_L2p -
    ScpAp_SpeedSupervision_ARID_DEF.IMU_AccelX_L1p) > TH_Mon_Accel_Diff) ||
    rtb_TmpSignalConversionAtRP_Scp.WSS_Fault ||
    rtb_TmpSignalConversionAtRP_Scp.VechSpeedEst_Fault ||
    rtb_TmpSignalConversionAtRP_Scp.MotorRPM_Fault ||
    rtb_TmpSignalConversionAtRP_Scp.Accel_Fault);

  /* End of Outputs for SubSystem: '<S1>/Comm_Rx' */

  /* Switch: '<S5>/Switch1' incorporates:
   *  Constant: '<S5>/Constant3'
   *  Logic: '<S5>/OR2'
   *  RelationalOperator: '<S5>/Relational Operator1'
   *  RelationalOperator: '<S5>/Relational Operator2'
   *  SignalConversion generated from: '<S3>/RP_ScpAp_Mode_L2p_IF_SafetyMode_L2p'
   */
  ScpAp_SpeedSupervisi_Autonomous =
    ((ScpAp_SpeedSupervision_ARID_DEF.SafetyMode_L2p == AUTONOMOUS) &&
     ScpAp_SpeedSupervision_ARID_DEF.AutonomousAllowed);

  /* Outputs for Enabled SubSystem: '<S5>/Manual_Mode_Cal' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  /* RelationalOperator: '<S5>/Relational Operator3' */
  if (!ScpAp_SpeedSupervisi_Autonomous) {
    /* Switch: '<S7>/Switch6' incorporates:
     *  Constant: '<S7>/Constant16'
     *  RelationalOperator: '<S7>/Relational Operator5'
     *  Sum: '<S7>/Subtract2'
     */
    ScpAp_S_SpeedMonitorFault_Flg_2 = ((uint16)
      (ScpAp_SpeedSupervision_ARID_DEF.Vechilespeed_L2p -
       ScpAp_SpeedSupervision_ARID_DEF.MotorSpeed_L1p) > TH_Mon_Speed_Diff);
  }

  /* End of RelationalOperator: '<S5>/Relational Operator3' */
  /* End of Outputs for SubSystem: '<S5>/Manual_Mode_Cal' */

  /* UnitDelay: '<S5>/Unit Delay' */
  ScpAp_Spe_SpeedMonitorFaultFlag = SpeedMonitorFaultFlag;

  /* UnitDelay: '<S5>/Unit Delay1' */
  ScpAp_SpeedSup_OverSpeedFlg_Raw = OverSpeedFlg_Raw;

  /* Sum: '<S5>/Add' incorporates:
   *  Constant: '<S5>/Constant10'
   *  Product: '<S5>/Product'
   */
  ScpAp_SpeedSupe_Predicted_Speed = K_Pred * (float64)
    ScpAp_SpeedSupervision_ARID_DEF.NominalTorquecmd_L2p + (float64)
    ScpAp_SpeedSupervision_ARID_DEF.Vechilespeed_L2p;

  /* Switch: '<S5>/Switch3' incorporates:
   *  Constant: '<S5>/Constant11'
   *  Constant: '<S5>/Constant12'
   *  RelationalOperator: '<S5>/Relational Operator5'
   *  Sum: '<S5>/Add1'
   */
  ScpAp_Spee_OverspeedPredictFlag = (ScpAp_SpeedSupe_Predicted_Speed > (float64)
    WhlSpd_Max + TH_Pred_Margin);

  /* Switch: '<S5>/Switch5' */
  if (ScpAp_Spee_OverspeedPredictFlag > 0.0) {
    /* MinMax: '<S5>/Min1' incorporates:
     *  Constant: '<S5>/Constant16'
     */
    if (ScpAp_SpeedSupervision_ARID_DEF.NominalTorquecmd_L2p <= Torque_PreLimit)
    {
      /* Switch: '<S5>/Switch5' */
      ScpAp_Spee_OvrSpdPredictFlg_Chk =
        ScpAp_SpeedSupervision_ARID_DEF.NominalTorquecmd_L2p;
    } else {
      /* Switch: '<S5>/Switch5' */
      ScpAp_Spee_OvrSpdPredictFlg_Chk = Torque_PreLimit;
    }
  } else {
    /* Switch: '<S5>/Switch5' incorporates:
     *  MinMax: '<S5>/Min1'
     */
    ScpAp_Spee_OvrSpdPredictFlg_Chk =
      ScpAp_SpeedSupervision_ARID_DEF.NominalTorquecmd_L2p;
  }

  /* End of Switch: '<S5>/Switch5' */

  /* Switch: '<S5>/Switch4' */
  if (ScpAp_SpeedSup_OverSpeedFlg_Raw) {
    /* MinMax: '<S5>/Min' incorporates:
     *  Constant: '<S5>/Constant15'
     */
    if (ScpAp_SpeedSupervision_ARID_DEF.NominalTorquecmd_L2p <=
        Torque_Decel_Limit) {
      /* Switch: '<S5>/Switch4' */
      ScpAp_SpeedSuper_OverSpdFlg_Chk =
        ScpAp_SpeedSupervision_ARID_DEF.NominalTorquecmd_L2p;
    } else {
      /* Switch: '<S5>/Switch4' */
      ScpAp_SpeedSuper_OverSpdFlg_Chk = Torque_Decel_Limit;
    }
  } else {
    /* Switch: '<S5>/Switch4' incorporates:
     *  MinMax: '<S5>/Min'
     */
    ScpAp_SpeedSuper_OverSpdFlg_Chk = ScpAp_Spee_OvrSpdPredictFlg_Chk;
  }

  /* End of Switch: '<S5>/Switch4' */

  /* Switch: '<S5>/Switch2' */
  if (ScpAp_Spe_SpeedMonitorFaultFlag) {
    /* Switch: '<S5>/Switch2' incorporates:
     *  Constant: '<S5>/Constant9'
     */
    ScpAp_SpeedSup_SafeTorqueCmd_L2 = 0;
  } else {
    /* Switch: '<S5>/Switch2' */
    ScpAp_SpeedSup_SafeTorqueCmd_L2 = ScpAp_SpeedSuper_OverSpdFlg_Chk;
  }

  /* End of Switch: '<S5>/Switch2' */

  /* RelationalOperator: '<S5>/Relational Operator6' */
  ScpAp_NominalTrq_Equal_SafeTrq =
    (ScpAp_SpeedSupervision_ARID_DEF.NominalTorquecmd_L2p ==
     ScpAp_SpeedSup_SafeTorqueCmd_L2);

  /* Switch: '<S5>/Switch7' */
  ScpAp_S_SpeedMonitorFault_Flg_3 = !ScpAp_NominalTrq_Equal_SafeTrq;

  /* Logic: '<S5>/OR1' incorporates:
   *  UnitDelay: '<S5>/Unit Delay'
   */
  SpeedMonitorFaultFlag = ((ScpAp_S_SpeedMonitorFaultFlag_1 != 0.0) ||
    (ScpAp_S_SpeedMonitorFault_Flg_2 != 0.0) || (ScpAp_S_SpeedMonitorFault_Flg_3
    != 0.0));

  /* Switch: '<S5>/Switch6' */
  ScpAp_SpeedS_OverSpeedFlg_Raw_2 = ScpAp_S_SpeedMonitorFault_Flg_3;

  /* Outputs for Enabled SubSystem: '<S5>/Autonomous_Mode_Cal' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  /* RelationalOperator: '<S5>/Relational Operator4' */
  if (ScpAp_SpeedSupervisi_Autonomous) {
    /* Switch: '<S6>/Switch2' incorporates:
     *  Constant: '<S6>/Constant5'
     *  Constant: '<S6>/Constant6'
     *  RelationalOperator: '<S6>/Relational Operator3'
     *  Sum: '<S6>/Add'
     */
    ScpAp_SpeedS_OverSpeedFlg_Raw_1 =
      (ScpAp_SpeedSupervision_ARID_DEF.Vechilespeed_L2p > (float64)WhlSpd_Max +
       TH_Speed_Limit_Margin);

    /* Switch: '<S6>/Switch3' */
    if (ScpAp_SpeedS_OverSpeedFlg_Raw_1) {
      /* Switch: '<S6>/Switch3' incorporates:
       *  Constant: '<S6>/Constant9'
       */
      ScpAp_Spe_OverspeedFlag_Latched = TRUE;
    } else {
      /* Switch: '<S6>/Switch3' incorporates:
       *  Constant: '<S6>/Constant10'
       *  Constant: '<S6>/Constant11'
       *  RelationalOperator: '<S6>/Relational Operator4'
       *  Sum: '<S6>/Subtract1'
       */
      ScpAp_Spe_OverspeedFlag_Latched =
        (ScpAp_SpeedSupervision_ARID_DEF.Vechilespeed_L2p > (float64)WhlSpd_Max
         - TH_Hystersis);
    }

    /* End of Switch: '<S6>/Switch3' */

    /* Switch: '<S6>/Switch5' */
    ScpAp_SpeedSuperv_OverSpeed_Flg = ScpAp_Spe_OverspeedFlag_Latched;
  }

  /* End of RelationalOperator: '<S5>/Relational Operator4' */
  /* End of Outputs for SubSystem: '<S5>/Autonomous_Mode_Cal' */

  /* Logic: '<S5>/OR3' incorporates:
   *  UnitDelay: '<S5>/Unit Delay1'
   */
  OverSpeedFlg_Raw = (ScpAp_SpeedS_OverSpeedFlg_Raw_1 ||
                      (ScpAp_SpeedS_OverSpeedFlg_Raw_2 != 0.0));

  /* End of Outputs for SubSystem: '<S1>/SWC5_Control' */

  /* Outputs for Atomic SubSystem: '<S1>/Comm_Tx' */
  /* SignalConversion generated from: '<S4>/SafeTorquecmd_L2p' */
  ScpAp_SpeedSupervision_ARID_DEF.SafeTorquecmd_L2p =
    ScpAp_SpeedSup_SafeTorqueCmd_L2;

  /* SignalConversion generated from: '<S4>/SafetyOverspeedFlag' */
  ScpAp_SpeedSupervision_ARID_DEF.SafetyOverspeedFlag =
    ScpAp_SpeedSuperv_OverSpeed_Flg;

  /* SignalConversion generated from: '<S4>/SafetySpeedMonitorFaultFlag' */
  ScpAp_SpeedSupervision_ARID_DEF.SafetySpeedMonitorFaultFlag =
    ScpAp_Spe_SpeedMonitorFaultFlag;

  /* End of Outputs for SubSystem: '<S1>/Comm_Tx' */
  /* End of Outputs for SubSystem: '<Root>/SafetySpeedSuperv_Main_sys' */

  /* Outport: '<Root>/PP_SafeTorquecmd_L2p_IF_SafeTorquecmd_L2p' */
  (void)Rte_Write_PP_SafeTorquecmd_L2p_IF_SafeTorquecmd_L2p
    (ScpAp_SpeedSupervision_ARID_DEF.SafeTorquecmd_L2p);

  /* Outport: '<Root>/PP_SafetyOverspeedFlag_IF_SafetyOverspeedFlag' */
  (void)Rte_Write_PP_SafetyOverspeedFlag_IF_SafetyOverspeedFlag
    (ScpAp_SpeedSupervision_ARID_DEF.SafetyOverspeedFlag);

  /* Outport: '<Root>/PP_SafetySpeedMonitorFaultFlag_IF_SafetySpeedMonitorFaultFlag' */
  (void)Rte_Write_PP_SafetySpeedMonitorFaultFlag_IF_SafetySpeedMonitorFaultFlag
    (ScpAp_SpeedSupervision_ARID_DEF.SafetySpeedMonitorFaultFlag);
}

#define ScpAp_SpeedSupervision_STOP_SEC_CODE
#include "ScpAp_SpeedSupervision_MemMap.h"

/* Model initialize function */

/* SwAddrMethod CODE for Runnable */
#define ScpAp_SpeedSupervision_START_SEC_CODE
#include "ScpAp_SpeedSupervision_MemMap.h"

void ScpAp_SpeedSupervision_Init(void)
{
  /* Registration code */
  ScpAp_SpeedSupervision_ARID_DEF.SafetyMode_L2p = AUTONOMOUS;
}

#define ScpAp_SpeedSupervision_STOP_SEC_CODE
#include "ScpAp_SpeedSupervision_MemMap.h"

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
