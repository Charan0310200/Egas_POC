/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ScpAp_SafetyStateManager.c
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

#include "ScpAp_SafetyStateManager.h"
#include "Platform_Types.h"
#include "ScpAp_SafetyStateManager_private.h"
#include <math.h>
#include "Rte_Type.h"

/* Named constants for Chart: '<S1>/EGAS_StateMachine' */
#define ScpAp_Saf_IN_OverSpeed_Handling ((uint8)4U)
#define ScpAp_SafetyS_IN_Energency_Stop ((uint8)2U)
#define ScpAp_SafetyStateMan_IN_Degrade ((uint8)1U)
#define ScpAp_SafetyStateMana_IN_Normal ((uint8)3U)

/* PublicStructure Variables for Internal Data */
ARID_DEF_ScpAp_SafetyStateMan_T ScpAp_SafetyStateManag_ARID_DEF;
                                   /* '<Root>/PP_SG_mWhdCtrl_SG_mWhdCtrl_VDP' */

/* Static Memory for Internal Data */

/* SwAddrMethod ASW_Variables for Internal Data */
#define ScpAp_SafetyStateManager_START_SEC_ASW_Variables
#include "ScpAp_SafetyStateManager_MemMap.h"

float32 ScpAp_SafetyStateManag_BrkTrqRq;/* '<S1>/EGAS_StateMachine' */
float32 ScpAp_SafetyStateManager_TrqCmd;/* '<S1>/EGAS_StateMachine' */
float32 ScpAp_SafetyStateManager_SpdCmd;/* '<S4>/Constant18' */
float32 ScpAp_SafetyStateMan_SpdSlewLmt;/* '<S4>/Constant19' */
float32 ScpAp_SafetyStateMan_TrqSlewLmt;/* '<S4>/Constant20' */
float32 ScpAp_SafetyS_SafeTorquecmd_L2p;/* '<S3>/Data Type Conversion' */
uint8 ScpAp_SafetySta_MsgCrc_mBrkCtrl; /* '<S4>/Constant10' */
uint8 ScpAp_SafetyStateManager_EPBCmd; /* '<S4>/Constant7' */
uint8 ScpAp_SafetySt_MsgCntr_mBrkCtrl; /* '<S4>/Constant9' */
uint8 ScpAp_SafetyStateM_CtrlMode_Whd; /* '<S4>/Constant12' */
uint8 ScpAp_SafetySt_MsgCntr_mWhdCtrl; /* '<S4>/Constant15' */
uint8 ScpAp_SafetySta_MsgCrc_mWhdCtrl; /* '<S4>/Constant16' */
uint8 ScpAp_SafetyStateManage_MtrMode; /* '<S4>/Constant17' */
VechSafetyStatus_L2p_IDT ScpAp_SafetySta_MultiportSwitch;/* '<S1>/Multiport Switch' */
boolean ScpAp_SafetySta_Aeb_Active_Ebcm;/* '<S4>/Constant' */
boolean ScpAp_SafetyStat_BrkEnbl_EBCM2L;/* '<S4>/Constant1' */
boolean ScpAp_SafetySta_ClearFltRq_Ebcm;/* '<S4>/Constant2' */
boolean ScpAp_SafetyStateManage_DsblTCS;/* '<S4>/Constant3' */
boolean ScpAp_SafetySta_EbcmMaintModeRq;/* '<S4>/Constant4' */
boolean ScpAp_SafetyStateM_EbcmShtdwnRq;/* '<S4>/Constant5' */
boolean ScpAp_SafetyStateMana_EpbCalCmd;/* '<S4>/Constant6' */
boolean ScpAp_SafetyStateManager_HoldRq;/* '<S4>/Constant8' */
boolean ScpAp_SafetyStateManager_Boot; /* '<S4>/Constant11' */
boolean ScpAp_SafetyStateManager_Debug;/* '<S4>/Constant13' */
boolean ScpAp_SafetyStateManage_EnblCmd;/* '<S4>/Constant14' */

#define ScpAp_SafetyStateManager_STOP_SEC_ASW_Variables
#include "ScpAp_SafetyStateManager_MemMap.h"

/* Output and update for function-call system: '<S5>/Minimum' */
float32 ScpAp_SafetyStateManage_Minimum(float32 rtu_In1, float32 rtu_In2)
{
  /* MinMax: '<S6>/Min' */
  return fminf(rtu_In1, rtu_In2);
}

/* Model step function */

/* SwAddrMethod CODE for Runnable */
#define ScpAp_SafetyStateManager_START_SEC_CODE
#include "ScpAp_SafetyStateManager_MemMap.h"

void SafetyState_Main(void)
{
  IF_SensorFaultFlgs_L2p_IDT rtb_TmpSignalConversionAtRP_Scp;
  sint16 tmpRead;
  sint8 rtb_SafetyStatus;

  /* SignalConversion generated from: '<S3>/RP_ScpAP_SafetySpeedMonitorFaultFlag_IF_SafetySpeedMonitorFaultFlag' incorporates:
   *  Inport: '<Root>/RP_ScpAP_SafetySpeedMonitorFaultFlag_IF_SafetySpeedMonitorFaultFlag'
   */
  (void)
    Rte_Read_RP_ScpAP_SafetySpeedMonitorFaultFlag_IF_SafetySpeedMonitorFaultFlag
    (&ScpAp_SafetyStateManag_ARID_DEF.SafetySpeedMonitorFaultFlag);

  /* SignalConversion generated from: '<S3>/RP_ScpAp_SafetyOverspeedFlag_IF_SafetyOverspeedFlag' incorporates:
   *  Inport: '<Root>/RP_ScpAp_SafetyOverspeedFlag_IF_SafetyOverspeedFlag'
   */
  (void)Rte_Read_RP_ScpAp_SafetyOverspeedFlag_IF_SafetyOverspeedFlag
    (&ScpAp_SafetyStateManag_ARID_DEF.SafetyOverspeedFlag);

  /* Inport: '<Root>/RP_ScpAp_SafeTorquecmd_L2p_IF_SafeTorquecmd_L2p' */
  (void)Rte_Read_RP_ScpAp_SafeTorquecmd_L2p_IF_SafeTorquecmd_L2p(&tmpRead);

  /* SignalConversion generated from: '<Root>/RP_ScpAp_SensorValidityFlag_L2p_IF_SensorFaultFlags_L2p' incorporates:
   *  Inport: '<Root>/RP_ScpAp_SensorValidityFlag_L2p_IF_SensorFaultFlags_L2p'
   */
  (void)Rte_Read_RP_ScpAp_SensorValidityFlag_L2p_IF_SensorFaultFlags_L2p
    (&rtb_TmpSignalConversionAtRP_Scp);

  /* Outputs for Atomic SubSystem: '<Root>/SafetyState_Main_sys' */
  /* Outputs for Atomic SubSystem: '<S1>/Comm_Rx' */
  /* DataTypeConversion: '<S3>/Data Type Conversion' */
  ScpAp_SafetyS_SafeTorquecmd_L2p = tmpRead;

  /* End of Outputs for SubSystem: '<S1>/Comm_Rx' */

  /* Chart: '<S1>/EGAS_StateMachine' incorporates:
   *  SignalConversion generated from: '<S3>/Bus Selector'
   * */
  if (ScpAp_SafetyStateManag_ARID_DEF.temporalCounter_i1 < 3) {
    ScpAp_SafetyStateManag_ARID_DEF.temporalCounter_i1++;
  }

  if (ScpAp_SafetyStateManag_ARID_DEF.is_active_c1_ScpAp_SafetyStateM == 0) {
    ScpAp_SafetyStateManag_ARID_DEF.is_active_c1_ScpAp_SafetyStateM = 1U;
    ScpAp_SafetyStateManag_ARID_DEF.is_c1_ScpAp_SafetyStateManager =
      ScpAp_SafetyStateMana_IN_Normal;
    rtb_SafetyStatus = 0;
    ScpAp_SafetyStateManag_BrkTrqRq = 0.0F;
    ScpAp_SafetyStateManager_TrqCmd = ScpAp_SafetyS_SafeTorquecmd_L2p;
  } else {
    switch (ScpAp_SafetyStateManag_ARID_DEF.is_c1_ScpAp_SafetyStateManager) {
     case ScpAp_SafetyStateMan_IN_Degrade:
      if (ScpAp_SafetyStateManag_ARID_DEF.temporalCounter_i1 >= 3) {
        ScpAp_SafetyStateManag_ARID_DEF.is_c1_ScpAp_SafetyStateManager =
          ScpAp_SafetyS_IN_Energency_Stop;
        ScpAp_SafetyStateManager_TrqCmd = 0.0F;
        ScpAp_SafetyStateManag_BrkTrqRq =
          ScpAp_SafetyStateManag_ARID_DEF.Brake_Max_Safe;
        rtb_SafetyStatus = 2;

        /* Outputs for Atomic SubSystem: '<S1>/Comm_Rx' */
      } else if ((!ScpAp_SafetyStateManag_ARID_DEF.SafetySpeedMonitorFaultFlag) &&
                 (!ScpAp_SafetyStateManag_ARID_DEF.SafetyOverspeedFlag) &&
                 (!rtb_TmpSignalConversionAtRP_Scp.Accel_Fault) &&
                 (!rtb_TmpSignalConversionAtRP_Scp.MotorRPM_Fault) &&
                 (!rtb_TmpSignalConversionAtRP_Scp.WSS_Fault) &&
                 (!rtb_TmpSignalConversionAtRP_Scp.VechSpeedEst_Fault)) {
        ScpAp_SafetyStateManag_ARID_DEF.is_c1_ScpAp_SafetyStateManager =
          ScpAp_SafetyStateMana_IN_Normal;
        rtb_SafetyStatus = 0;
        ScpAp_SafetyStateManag_BrkTrqRq = 0.0F;
        ScpAp_SafetyStateManager_TrqCmd = ScpAp_SafetyS_SafeTorquecmd_L2p;
      } else {
        ScpAp_SafetyStateManager_TrqCmd = 0.0F;
        ScpAp_SafetyStateManag_BrkTrqRq =
          ScpAp_SafetyStateManag_ARID_DEF.Brake_Limp;
        rtb_SafetyStatus = 1;

        /* End of Outputs for SubSystem: '<S1>/Comm_Rx' */
      }
      break;

     case ScpAp_SafetyS_IN_Energency_Stop:
      ScpAp_SafetyStateManager_TrqCmd = 0.0F;
      ScpAp_SafetyStateManag_BrkTrqRq =
        ScpAp_SafetyStateManag_ARID_DEF.Brake_Max_Safe;
      rtb_SafetyStatus = 2;
      break;

     case ScpAp_SafetyStateMana_IN_Normal:
      if (ScpAp_SafetyStateManag_ARID_DEF.SafetyOverspeedFlag) {
        ScpAp_SafetyStateManag_ARID_DEF.is_c1_ScpAp_SafetyStateManager =
          ScpAp_Saf_IN_OverSpeed_Handling;
        ScpAp_SafetyStateManag_ARID_DEF.In1 = ScpAp_SafetyS_SafeTorquecmd_L2p;
        ScpAp_SafetyStateManag_ARID_DEF.In2 =
          ScpAp_SafetyStateManag_ARID_DEF.Torque_Decel_Limit;

        /* Outputs for Function Call SubSystem: '<S5>/Minimum' */
        ScpAp_SafetyStateManag_ARID_DEF.Min = ScpAp_SafetyStateManage_Minimum
          (ScpAp_SafetyStateManag_ARID_DEF.In1,
           ScpAp_SafetyStateManag_ARID_DEF.In2);

        /* End of Outputs for SubSystem: '<S5>/Minimum' */
        ScpAp_SafetyStateManager_TrqCmd = ScpAp_SafetyStateManag_ARID_DEF.Min;
        ScpAp_SafetyStateManag_BrkTrqRq =
          ScpAp_SafetyStateManag_ARID_DEF.Brake_Decel_Level;
        rtb_SafetyStatus = 3;

        /* Outputs for Atomic SubSystem: '<S1>/Comm_Rx' */
      } else if (ScpAp_SafetyStateManag_ARID_DEF.SafetySpeedMonitorFaultFlag ||
                 (rtb_TmpSignalConversionAtRP_Scp.Accel_Fault &&
                  rtb_TmpSignalConversionAtRP_Scp.MotorRPM_Fault &&
                  rtb_TmpSignalConversionAtRP_Scp.WSS_Fault &&
                  rtb_TmpSignalConversionAtRP_Scp.VechSpeedEst_Fault)) {
        ScpAp_SafetyStateManag_ARID_DEF.temporalCounter_i1 = 0U;
        ScpAp_SafetyStateManag_ARID_DEF.is_c1_ScpAp_SafetyStateManager =
          ScpAp_SafetyStateMan_IN_Degrade;
        ScpAp_SafetyStateManager_TrqCmd = 0.0F;
        ScpAp_SafetyStateManag_BrkTrqRq =
          ScpAp_SafetyStateManag_ARID_DEF.Brake_Limp;
        rtb_SafetyStatus = 1;
      } else {
        rtb_SafetyStatus = 0;
        ScpAp_SafetyStateManag_BrkTrqRq = 0.0F;
        ScpAp_SafetyStateManager_TrqCmd = ScpAp_SafetyS_SafeTorquecmd_L2p;

        /* End of Outputs for SubSystem: '<S1>/Comm_Rx' */
      }
      break;

     default:
      /* Outputs for Atomic SubSystem: '<S1>/Comm_Rx' */
      /* case IN_OverSpeed_Handling: */
      if ((!ScpAp_SafetyStateManag_ARID_DEF.SafetyOverspeedFlag) &&
          (!rtb_TmpSignalConversionAtRP_Scp.Accel_Fault) &&
          (!rtb_TmpSignalConversionAtRP_Scp.MotorRPM_Fault) &&
          (!rtb_TmpSignalConversionAtRP_Scp.WSS_Fault) &&
          (!rtb_TmpSignalConversionAtRP_Scp.VechSpeedEst_Fault)) {
        ScpAp_SafetyStateManag_ARID_DEF.is_c1_ScpAp_SafetyStateManager =
          ScpAp_SafetyStateMana_IN_Normal;
        rtb_SafetyStatus = 0;
        ScpAp_SafetyStateManag_BrkTrqRq = 0.0F;
        ScpAp_SafetyStateManager_TrqCmd = ScpAp_SafetyS_SafeTorquecmd_L2p;
      } else if (ScpAp_SafetyStateManag_ARID_DEF.SafetySpeedMonitorFaultFlag ||
                 (rtb_TmpSignalConversionAtRP_Scp.Accel_Fault &&
                  rtb_TmpSignalConversionAtRP_Scp.MotorRPM_Fault &&
                  rtb_TmpSignalConversionAtRP_Scp.WSS_Fault &&
                  rtb_TmpSignalConversionAtRP_Scp.VechSpeedEst_Fault)) {
        ScpAp_SafetyStateManag_ARID_DEF.temporalCounter_i1 = 0U;
        ScpAp_SafetyStateManag_ARID_DEF.is_c1_ScpAp_SafetyStateManager =
          ScpAp_SafetyStateMan_IN_Degrade;
        ScpAp_SafetyStateManager_TrqCmd = 0.0F;
        ScpAp_SafetyStateManag_BrkTrqRq =
          ScpAp_SafetyStateManag_ARID_DEF.Brake_Limp;
        rtb_SafetyStatus = 1;
      } else {
        ScpAp_SafetyStateManag_ARID_DEF.In1 = ScpAp_SafetyS_SafeTorquecmd_L2p;
        ScpAp_SafetyStateManag_ARID_DEF.In2 =
          ScpAp_SafetyStateManag_ARID_DEF.Torque_Decel_Limit;

        /* Outputs for Function Call SubSystem: '<S5>/Minimum' */
        ScpAp_SafetyStateManag_ARID_DEF.Min = ScpAp_SafetyStateManage_Minimum
          (ScpAp_SafetyStateManag_ARID_DEF.In1,
           ScpAp_SafetyStateManag_ARID_DEF.In2);

        /* End of Outputs for SubSystem: '<S5>/Minimum' */
        ScpAp_SafetyStateManager_TrqCmd = ScpAp_SafetyStateManag_ARID_DEF.Min;
        ScpAp_SafetyStateManag_BrkTrqRq =
          ScpAp_SafetyStateManag_ARID_DEF.Brake_Decel_Level;
        rtb_SafetyStatus = 3;
      }

      /* End of Outputs for SubSystem: '<S1>/Comm_Rx' */
      break;
    }
  }

  /* End of Chart: '<S1>/EGAS_StateMachine' */

  /* MultiPortSwitch: '<S1>/Multiport Switch' */
  switch (rtb_SafetyStatus) {
   case 0:
    /* MultiPortSwitch: '<S1>/Multiport Switch' incorporates:
     *  Constant: '<S1>/Constant'
     */
    ScpAp_SafetySta_MultiportSwitch = NORMAL;
    break;

   case 1:
    /* MultiPortSwitch: '<S1>/Multiport Switch' incorporates:
     *  Constant: '<S1>/Constant1'
     */
    ScpAp_SafetySta_MultiportSwitch = DEGRADED;
    break;

   case 2:
    /* MultiPortSwitch: '<S1>/Multiport Switch' incorporates:
     *  Constant: '<S1>/Constant2'
     */
    ScpAp_SafetySta_MultiportSwitch = FAULT_STOP;
    break;

   default:
    /* MultiPortSwitch: '<S1>/Multiport Switch' incorporates:
     *  Constant: '<S1>/Constant3'
     */
    ScpAp_SafetySta_MultiportSwitch = OVERSPEED_HANDLING;
    break;
  }

  /* End of MultiPortSwitch: '<S1>/Multiport Switch' */

  /* Outputs for Atomic SubSystem: '<S1>/Comm_Tx' */
  /* Constant: '<S4>/Constant' */
  ScpAp_SafetySta_Aeb_Active_Ebcm = FALSE;

  /* Constant: '<S4>/Constant1' */
  ScpAp_SafetyStat_BrkEnbl_EBCM2L = FALSE;

  /* Constant: '<S4>/Constant10' */
  ScpAp_SafetySta_MsgCrc_mBrkCtrl = 0U;

  /* Constant: '<S4>/Constant2' */
  ScpAp_SafetySta_ClearFltRq_Ebcm = FALSE;

  /* Constant: '<S4>/Constant3' */
  ScpAp_SafetyStateManage_DsblTCS = FALSE;

  /* Constant: '<S4>/Constant4' */
  ScpAp_SafetySta_EbcmMaintModeRq = FALSE;

  /* Constant: '<S4>/Constant5' */
  ScpAp_SafetyStateM_EbcmShtdwnRq = FALSE;

  /* Constant: '<S4>/Constant6' */
  ScpAp_SafetyStateMana_EpbCalCmd = FALSE;

  /* Constant: '<S4>/Constant7' */
  ScpAp_SafetyStateManager_EPBCmd = 0U;

  /* Constant: '<S4>/Constant8' */
  ScpAp_SafetyStateManager_HoldRq = FALSE;

  /* Constant: '<S4>/Constant9' */
  ScpAp_SafetySt_MsgCntr_mBrkCtrl = 0U;

  /* Constant: '<S4>/Constant11' */
  ScpAp_SafetyStateManager_Boot = FALSE;

  /* Constant: '<S4>/Constant12' */
  ScpAp_SafetyStateM_CtrlMode_Whd = 0U;

  /* Constant: '<S4>/Constant13' */
  ScpAp_SafetyStateManager_Debug = FALSE;

  /* Constant: '<S4>/Constant14' */
  ScpAp_SafetyStateManage_EnblCmd = FALSE;

  /* Constant: '<S4>/Constant15' */
  ScpAp_SafetySt_MsgCntr_mWhdCtrl = 0U;

  /* Constant: '<S4>/Constant16' */
  ScpAp_SafetySta_MsgCrc_mWhdCtrl = 0U;

  /* Constant: '<S4>/Constant17' */
  ScpAp_SafetyStateManage_MtrMode = 0U;

  /* Constant: '<S4>/Constant18' */
  ScpAp_SafetyStateManager_SpdCmd = 0.0F;

  /* Constant: '<S4>/Constant19' */
  ScpAp_SafetyStateMan_SpdSlewLmt = 0.0F;

  /* Constant: '<S4>/Constant20' */
  ScpAp_SafetyStateMan_TrqSlewLmt = 0.0F;

  /* SignalConversion generated from: '<S4>/VechSafetyStatus_L2p' incorporates:
   *  MultiPortSwitch: '<S1>/Multiport Switch'
   */
  ScpAp_SafetyStateManag_ARID_DEF.VechSafetyStatus_L2p =
    ScpAp_SafetySta_MultiportSwitch;

  /* End of Outputs for SubSystem: '<S1>/Comm_Tx' */
  /* End of Outputs for SubSystem: '<Root>/SafetyState_Main_sys' */

  /* Outport: '<Root>/PP_SG_mBrkCtrl_SG_mBrkCtrl_VDP' incorporates:
   *  BusCreator generated from: '<Root>/PP_SG_mBrkCtrl_SG_mBrkCtrl_VDP'
   *  SignalConversion generated from: '<S4>/PP_SG_mBrkCtrl_SG_mBrkCtrl_VDP'
   */
  ScpAp_SafetyStateManag_ARID_DEF.PP_SG_mBrkCtrl_SG_mBrkCtrl_VDP.Aeb_Active_Ebcm
    = FALSE;
  ScpAp_SafetyStateManag_ARID_DEF.PP_SG_mBrkCtrl_SG_mBrkCtrl_VDP.BrkEnbl_EBCM2L =
    FALSE;

  /* Outputs for Atomic SubSystem: '<Root>/SafetyState_Main_sys' */
  /* Outputs for Atomic SubSystem: '<S1>/Comm_Tx' */
  ScpAp_SafetyStateManag_ARID_DEF.PP_SG_mBrkCtrl_SG_mBrkCtrl_VDP.BrkTrqRq =
    ScpAp_SafetyStateManag_BrkTrqRq;

  /* End of Outputs for SubSystem: '<S1>/Comm_Tx' */
  /* End of Outputs for SubSystem: '<Root>/SafetyState_Main_sys' */
  ScpAp_SafetyStateManag_ARID_DEF.PP_SG_mBrkCtrl_SG_mBrkCtrl_VDP.ClearFltRq_Ebcm
    = FALSE;
  ScpAp_SafetyStateManag_ARID_DEF.PP_SG_mBrkCtrl_SG_mBrkCtrl_VDP.DsblTCS = FALSE;
  ScpAp_SafetyStateManag_ARID_DEF.PP_SG_mBrkCtrl_SG_mBrkCtrl_VDP.EbcmMaintModeRq
    = FALSE;
  ScpAp_SafetyStateManag_ARID_DEF.PP_SG_mBrkCtrl_SG_mBrkCtrl_VDP.EbcmShtdwnRq =
    FALSE;
  ScpAp_SafetyStateManag_ARID_DEF.PP_SG_mBrkCtrl_SG_mBrkCtrl_VDP.EpbCalCmd =
    FALSE;
  ScpAp_SafetyStateManag_ARID_DEF.PP_SG_mBrkCtrl_SG_mBrkCtrl_VDP.EPBCmd = 0U;
  ScpAp_SafetyStateManag_ARID_DEF.PP_SG_mBrkCtrl_SG_mBrkCtrl_VDP.HoldRq = FALSE;
  ScpAp_SafetyStateManag_ARID_DEF.PP_SG_mBrkCtrl_SG_mBrkCtrl_VDP.MsgCntr_mBrkCtrl
    = 0U;
  ScpAp_SafetyStateManag_ARID_DEF.PP_SG_mBrkCtrl_SG_mBrkCtrl_VDP.MsgCrc_mBrkCtrl
    = 0U;

  /* Outport: '<Root>/PP_SG_mWhdCtrl_SG_mWhdCtrl_VDP' incorporates:
   *  BusCreator generated from: '<Root>/PP_SG_mWhdCtrl_SG_mWhdCtrl_VDP'
   *  SignalConversion generated from: '<S4>/PP_SG_mWhdCtrl_SG_mWhdCtrl_VDP'
   */
  ScpAp_SafetyStateManag_ARID_DEF.PP_SG_mWhdCtrl_SG_mWhdCtrl_VDP.Boot = FALSE;
  ScpAp_SafetyStateManag_ARID_DEF.PP_SG_mWhdCtrl_SG_mWhdCtrl_VDP.CtrlMode_Whd =
    0U;
  ScpAp_SafetyStateManag_ARID_DEF.PP_SG_mWhdCtrl_SG_mWhdCtrl_VDP.Debug = FALSE;
  ScpAp_SafetyStateManag_ARID_DEF.PP_SG_mWhdCtrl_SG_mWhdCtrl_VDP.EnblCmd = FALSE;
  ScpAp_SafetyStateManag_ARID_DEF.PP_SG_mWhdCtrl_SG_mWhdCtrl_VDP.MsgCntr_mWhdCtrl
    = 0U;
  ScpAp_SafetyStateManag_ARID_DEF.PP_SG_mWhdCtrl_SG_mWhdCtrl_VDP.MsgCrc_mWhdCtrl
    = 0U;
  ScpAp_SafetyStateManag_ARID_DEF.PP_SG_mWhdCtrl_SG_mWhdCtrl_VDP.MtrMode = 0U;
  ScpAp_SafetyStateManag_ARID_DEF.PP_SG_mWhdCtrl_SG_mWhdCtrl_VDP.SpdCmd = 0.0F;
  ScpAp_SafetyStateManag_ARID_DEF.PP_SG_mWhdCtrl_SG_mWhdCtrl_VDP.SpdSlewLmt =
    0.0F;

  /* Outputs for Atomic SubSystem: '<Root>/SafetyState_Main_sys' */
  /* Outputs for Atomic SubSystem: '<S1>/Comm_Tx' */
  ScpAp_SafetyStateManag_ARID_DEF.PP_SG_mWhdCtrl_SG_mWhdCtrl_VDP.TrqCmd =
    ScpAp_SafetyStateManager_TrqCmd;

  /* End of Outputs for SubSystem: '<S1>/Comm_Tx' */
  /* End of Outputs for SubSystem: '<Root>/SafetyState_Main_sys' */
  ScpAp_SafetyStateManag_ARID_DEF.PP_SG_mWhdCtrl_SG_mWhdCtrl_VDP.TrqSlewLmt =
    0.0F;

  /* Outport: '<Root>/PP_VechSafetyStatus_L2p_IF_VechSafetyStatus_L2p' incorporates:
   *  SignalConversion generated from: '<S4>/VechSafetyStatus_L2p'
   */
  (void)Rte_Write_PP_VechSafetyStatus_L2p_IF_VechSafetyStatus_L2p
    (ScpAp_SafetyStateManag_ARID_DEF.VechSafetyStatus_L2p);
  (void)Rte_Write_PP_SG_mBrkCtrl_SG_mBrkCtrl_VDP
    (&ScpAp_SafetyStateManag_ARID_DEF.PP_SG_mBrkCtrl_SG_mBrkCtrl_VDP);
  (void)Rte_Write_PP_SG_mWhdCtrl_SG_mWhdCtrl_VDP
    (&ScpAp_SafetyStateManag_ARID_DEF.PP_SG_mWhdCtrl_SG_mWhdCtrl_VDP);
}

#define ScpAp_SafetyStateManager_STOP_SEC_CODE
#include "ScpAp_SafetyStateManager_MemMap.h"

/* Model initialize function */

/* SwAddrMethod CODE for Runnable */
#define ScpAp_SafetyStateManager_START_SEC_CODE
#include "ScpAp_SafetyStateManager_MemMap.h"

void ScpAp_SafetyStateManager_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<Root>/SafetyState_Main_sys' */
  /* SystemInitialize for Chart: '<S1>/EGAS_StateMachine' */
  ScpAp_SafetyStateManag_ARID_DEF.Brake_Decel_Level = 500.0F;
  ScpAp_SafetyStateManag_ARID_DEF.Brake_Limp = 600.0F;
  ScpAp_SafetyStateManag_ARID_DEF.Brake_Max_Safe = 800.0F;
  ScpAp_SafetyStateManag_ARID_DEF.Torque_Decel_Limit = 500.0F;

  /* End of SystemInitialize for SubSystem: '<Root>/SafetyState_Main_sys' */
}

#define ScpAp_SafetyStateManager_STOP_SEC_CODE
#include "ScpAp_SafetyStateManager_MemMap.h"

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
