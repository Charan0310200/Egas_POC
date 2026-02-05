/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ScpAp_L1SpeedMonitor.c
 *
 * Code generated for Simulink model 'ScpAp_L1SpeedMonitor'.
 *
 * Model version                  : 1.158
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Wed Feb  4 11:29:08 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ScpAp_L1SpeedMonitor.h"
#include <math.h>
#include "Rte_Type.h"
#include "Platform_Types.h"

/* PublicStructure Variables for Internal Data */
ARID_DEF_ScpAp_L1SpeedMonitor_T ScpAp_L1SpeedMonitor_ARID_DEF;
                          /* '<Root>/PP_ValidityFlag_L1p_IF_ValidityFlag_L1p' */

/* Static Memory for Internal Data */

/* SwAddrMethod AswVariable for Internal Data */
#define ScpAp_L1SpeedMonitor_START_SEC_AswVariable
#include "ScpAp_L1SpeedMonitor_MemMap.h"

float64 ScpAp_L1SpeedMonitor_Output;   /* '<S12>/Switch1' */
float64 StuckCntOutput_Prev;           /* '<S12>/Unit Delay' */
float32 ScpAp_L1SpeedMon_X_Accel_L1_Phy;/* '<S13>/Abs' */
float32 ScpAp_L1SpeedMon_IMU_AccelX_L1p;/* '<S13>/Switch1' */
float32 ScpAp_L1SpeedMo_IMU_AccelX_Diff;/* '<S11>/Subtract3' */
float32 IMU_AccelX_L1p_Prev;           /* '<S13>/Unit Delay' */
float32 STC_IMU_Accel_XL1p_Prev;       /* '<S11>/Unit Delay3' */
uint16 ScpAp_L1SpeedM_WhlSpdFR_Phy_Kph;/* '<S21>/Data Type Conversion' */
uint16 ScpAp_L1SpeedMonitor_WSS_R_L1p; /* '<S21>/Switch1' */
uint16 ScpAp_L1SpeedMonitor_WhlSpd_Min;/* '<S20>/Constant' */
uint16 ScpAp_L1Spee_WhlSpdFR_Phy_Kph_n;/* '<S20>/Data Type Conversion' */
uint16 ScpAp_L1SpeedMonitor_WSS_FR_L1p;/* '<S20>/Switch1' */
uint16 ScpAp_L1Spe_WhlSpdFR_Phy_Kph_nw;/* '<S19>/Data Type Conversion' */
uint16 ScpAp_L1SpeedMonitor_WSS_FL_L1p;/* '<S19>/Switch1' */
uint16 ScpAp_L1SpeedMonito_WSS_FR_Diff;/* '<S11>/Subtract' */
uint16 ScpAp_L1SpeedMonito_WSS_FL_Diff;/* '<S11>/Subtract1' */
uint16 ScpAp_L1SpeedMonitor_WSS_R_Diff;/* '<S11>/Subtract2' */
uint16 WSS_R_L1p_Prev;                 /* '<S21>/Unit Delay' */
uint16 WSS_FR_L1p_Prev;                /* '<S20>/Unit Delay' */
uint16 WSS_FL_L1p_Prev;                /* '<S19>/Unit Delay' */
uint16 STC_WSS_FR_L1p_Prev;            /* '<S11>/Unit Delay' */
uint16 STC_WSS_FL_L1p_Prev;            /* '<S11>/Unit Delay1' */
uint16 STC_WSS_R_L1p_Prev;             /* '<S11>/Unit Delay2' */
uint8 ScpAp_L1Spee_MotorSpd_Equiv_L1p; /* '<S14>/Switch1' */
uint8 ScpAp_L1SpeedMonit_MotorSpd_kph; /* '<S18>/Data Type Conversion' */
uint8 ScpAp_L1Spe_MotorSpd_Equiv_Diff; /* '<S11>/Subtract4' */
uint8 MotorSpd_Equiv_L1p_Prev;         /* '<S14>/Unit Delay' */
uint8 STC_MotorSpd_Equiv_L1p_Prev;     /* '<S11>/Unit Delay4' */
boolean ScpAp_L1Speed_WhlSpdR_Valid_Chk;/* '<S21>/OR' */
boolean ScpAp_L1SpeedMo_WSS_R_Valid_Flg;/* '<S21>/Switch' */
boolean ScpAp_L1Spee_WhlSpdFR_Valid_Chk;/* '<S20>/WSS_FR_OR_Op' */
boolean ScpAp_L1SpeedM_WSS_FR_Valid_Flg;/* '<S20>/Switch' */
boolean ScpAp_L1Spee_WhlSpdFL_Valid_Chk;/* '<S19>/OR' */
boolean ScpAp_L1SpeedM_WSS_FL_Valid_Flg;/* '<S19>/Switch' */
boolean ScpAp_L1Sp_Motor_Spd_ValidCheck;/* '<S14>/OR' */
boolean ScpAp_L1Spe_Motor_RPM_Valid_Flg;/* '<S14>/Switch' */
boolean ScpAp_L1SpeedMo_IMU_Accel_Valid;/* '<S13>/Relational Operator' */
boolean ScpAp_L1Sp_IMU_AccelX_Valid_Flg;/* '<S13>/Switch' */
boolean ScpAp_L1SpeedMoni_Chk_Stuck_Cnt;/* '<S9>/Switch' */
boolean ScpAp_L1SpeedMoni_Trg_Stuck_Cnt;/* '<S11>/OR' */
boolean ScpAp_L1S_SensorStuck_Valid_Flg;/* '<S11>/Switch' */

#define ScpAp_L1SpeedMonitor_STOP_SEC_AswVariable
#include "ScpAp_L1SpeedMonitor_MemMap.h"

/* Model step function */

/* SwAddrMethod CODE for Runnable */
#define ScpAp_L1SpeedMonitor_START_SEC_CODE
#include "ScpAp_L1SpeedMonitor_MemMap.h"

void SensorIFL1_Main_10(void)
{
  SG_mEbcm2L_WhlSpd_IDT_E2E rtb_TmpSignalConversionAtRP_SCp;
  SG_mVcuImuLinAccel_IDT tmpRead;
  SG_mWhdStat_IDT_E2E tmpRead_0;
  float64 tmp;
  float64 tmp_0;
  float32 tmp_1;
  sint32 tmp_2;
  sint32 tmp_3;

  /* SignalConversion generated from: '<Root>/RP_SCpApVmEbcm2LRx_SG_mEbcm2L_WhlSpd_SG_mEbcm2L_WhlSpd' incorporates:
   *  Inport: '<Root>/RP_SCpApVmEbcm2LRx_SG_mEbcm2L_WhlSpd_SG_mEbcm2L_WhlSpd'
   */
  (void)Rte_Read_RP_SCpApVmEbcm2LRx_SG_mEbcm2L_WhlSpd_SG_mEbcm2L_WhlSpd
    (&rtb_TmpSignalConversionAtRP_SCp);

  /* Outputs for Atomic SubSystem: '<Root>/SensorIFL1_Main_10_sys' */
  /* Outputs for Atomic SubSystem: '<S2>/SWC_1_Control' */
  /* Outputs for Atomic SubSystem: '<S5>/WSS_IMU_Motor' */
  /* Outputs for Atomic SubSystem: '<S10>/WSS' */
  /* Outputs for Atomic SubSystem: '<S15>/WSS_FL' */
  /* DataTypeConversion: '<S19>/Data Type Conversion' incorporates:
   *  Gain: '<S19>/m//s to Kmph'
   */
  tmp_1 = fmodf(floorf(3.6F * rtb_TmpSignalConversionAtRP_SCp.WhlSpdFL),
                65536.0F);
  if (tmp_1 < 0.0F) {
    /* DataTypeConversion: '<S19>/Data Type Conversion' */
    ScpAp_L1Spe_WhlSpdFR_Phy_Kph_nw = (uint16)-(sint16)(uint16)-tmp_1;
  } else {
    /* DataTypeConversion: '<S19>/Data Type Conversion' */
    ScpAp_L1Spe_WhlSpdFR_Phy_Kph_nw = (uint16)tmp_1;
  }

  /* End of DataTypeConversion: '<S19>/Data Type Conversion' */

  /* Logic: '<S19>/OR' incorporates:
   *  Constant: '<S19>/Constant'
   *  Constant: '<S19>/Constant1'
   *  RelationalOperator: '<S19>/Relational Operator'
   *  RelationalOperator: '<S19>/Relational Operator1'
   */
  ScpAp_L1Spee_WhlSpdFL_Valid_Chk = ((ScpAp_L1Spe_WhlSpdFR_Phy_Kph_nw <
    WhlSpd_Min) || (ScpAp_L1Spe_WhlSpdFR_Phy_Kph_nw > WhlSpd_Max));

  /* Switch: '<S19>/Switch' */
  ScpAp_L1SpeedM_WSS_FL_Valid_Flg = !ScpAp_L1Spee_WhlSpdFL_Valid_Chk;

  /* Switch: '<S19>/Switch1' */
  if (ScpAp_L1Spee_WhlSpdFL_Valid_Chk) {
    /* Switch: '<S19>/Switch1' incorporates:
     *  UnitDelay: '<S19>/Unit Delay'
     */
    ScpAp_L1SpeedMonitor_WSS_FL_L1p = WSS_FL_L1p_Prev;
  } else {
    /* Outputs for Atomic SubSystem: '<S19>/WSS_FL_L1p_Calculation' */
    /* Product: '<S22>/Product' incorporates:
     *  Constant: '<S10>/Constant1'
     */
    tmp = fmod(floor((float64)ScpAp_L1Spe_WhlSpdFR_Phy_Kph_nw * Alpha_WSS),
               65536.0);

    /* Sum: '<S22>/Subtract' incorporates:
     *  Constant: '<S10>/Constant1'
     *  Constant: '<S22>/Constant'
     */
    tmp_0 = fmod(floor(1.0 - Alpha_WSS), 65536.0);
    if (tmp_0 < 0.0) {
      tmp_2 = (uint16)-(sint16)(uint16)-tmp_0;
    } else {
      tmp_2 = (uint16)tmp_0;
    }

    /* Product: '<S22>/Product' */
    if (tmp < 0.0) {
      tmp_3 = (uint16)-(sint16)(uint16)-tmp;
    } else {
      tmp_3 = (uint16)tmp;
    }

    /* Switch: '<S19>/Switch1' incorporates:
     *  Product: '<S22>/Product'
     *  Product: '<S22>/Product1'
     *  Sum: '<S22>/Add'
     *  Sum: '<S22>/Subtract'
     *  UnitDelay: '<S19>/Unit Delay'
     */
    ScpAp_L1SpeedMonitor_WSS_FL_L1p = (uint16)((uint16)((uint32)tmp_2 *
      WSS_FL_L1p_Prev) + (uint32)tmp_3);

    /* End of Outputs for SubSystem: '<S19>/WSS_FL_L1p_Calculation' */
  }

  /* End of Switch: '<S19>/Switch1' */

  /* Update for UnitDelay: '<S19>/Unit Delay' */
  WSS_FL_L1p_Prev = ScpAp_L1SpeedMonitor_WSS_FL_L1p;

  /* End of Outputs for SubSystem: '<S15>/WSS_FL' */

  /* Outputs for Atomic SubSystem: '<S15>/WSS_FR' */
  /* Constant: '<S20>/Constant' */
  ScpAp_L1SpeedMonitor_WhlSpd_Min = WhlSpd_Min;

  /* DataTypeConversion: '<S20>/Data Type Conversion' incorporates:
   *  Gain: '<S20>/m//s to Kmph'
   */
  tmp_1 = fmodf(floorf(3.6F * rtb_TmpSignalConversionAtRP_SCp.WhlSpdFR),
                65536.0F);
  if (tmp_1 < 0.0F) {
    /* DataTypeConversion: '<S20>/Data Type Conversion' */
    ScpAp_L1Spee_WhlSpdFR_Phy_Kph_n = (uint16)-(sint16)(uint16)-tmp_1;
  } else {
    /* DataTypeConversion: '<S20>/Data Type Conversion' */
    ScpAp_L1Spee_WhlSpdFR_Phy_Kph_n = (uint16)tmp_1;
  }

  /* End of DataTypeConversion: '<S20>/Data Type Conversion' */

  /* Logic: '<S20>/WSS_FR_OR_Op' incorporates:
   *  Constant: '<S20>/Constant1'
   *  RelationalOperator: '<S20>/Relational Operator'
   *  RelationalOperator: '<S20>/Relational Operator1'
   */
  ScpAp_L1Spee_WhlSpdFR_Valid_Chk = ((ScpAp_L1Spee_WhlSpdFR_Phy_Kph_n <
    ScpAp_L1SpeedMonitor_WhlSpd_Min) || (ScpAp_L1Spee_WhlSpdFR_Phy_Kph_n >
    WhlSpd_Max));

  /* Switch: '<S20>/Switch' */
  ScpAp_L1SpeedM_WSS_FR_Valid_Flg = !ScpAp_L1Spee_WhlSpdFR_Valid_Chk;

  /* Switch: '<S20>/Switch1' */
  if (ScpAp_L1Spee_WhlSpdFR_Valid_Chk) {
    /* Switch: '<S20>/Switch1' incorporates:
     *  UnitDelay: '<S20>/Unit Delay'
     */
    ScpAp_L1SpeedMonitor_WSS_FR_L1p = WSS_FR_L1p_Prev;
  } else {
    /* Outputs for Atomic SubSystem: '<S20>/WSS_FR_L1p_Calculation' */
    /* Product: '<S23>/Product' incorporates:
     *  Constant: '<S10>/Constant1'
     */
    tmp = fmod(floor((float64)ScpAp_L1Spee_WhlSpdFR_Phy_Kph_n * Alpha_WSS),
               65536.0);

    /* Sum: '<S23>/Subtract' incorporates:
     *  Constant: '<S10>/Constant1'
     *  Constant: '<S23>/Constant'
     */
    tmp_0 = fmod(floor(1.0 - Alpha_WSS), 65536.0);
    if (tmp_0 < 0.0) {
      tmp_2 = (uint16)-(sint16)(uint16)-tmp_0;
    } else {
      tmp_2 = (uint16)tmp_0;
    }

    /* Product: '<S23>/Product' */
    if (tmp < 0.0) {
      tmp_3 = (uint16)-(sint16)(uint16)-tmp;
    } else {
      tmp_3 = (uint16)tmp;
    }

    /* Switch: '<S20>/Switch1' incorporates:
     *  Product: '<S23>/Product'
     *  Product: '<S23>/Product1'
     *  Sum: '<S23>/Add'
     *  Sum: '<S23>/Subtract'
     *  UnitDelay: '<S20>/Unit Delay'
     */
    ScpAp_L1SpeedMonitor_WSS_FR_L1p = (uint16)((uint16)((uint32)tmp_2 *
      WSS_FR_L1p_Prev) + (uint32)tmp_3);

    /* End of Outputs for SubSystem: '<S20>/WSS_FR_L1p_Calculation' */
  }

  /* End of Switch: '<S20>/Switch1' */

  /* Update for UnitDelay: '<S20>/Unit Delay' */
  WSS_FR_L1p_Prev = ScpAp_L1SpeedMonitor_WSS_FR_L1p;

  /* End of Outputs for SubSystem: '<S15>/WSS_FR' */

  /* Outputs for Atomic SubSystem: '<S15>/WSS_R' */
  /* DataTypeConversion: '<S21>/Data Type Conversion' incorporates:
   *  Gain: '<S21>/m//s to Kmph'
   */
  tmp_1 = fmodf(floorf(3.6F * rtb_TmpSignalConversionAtRP_SCp.WhlSpdR), 65536.0F);
  if (tmp_1 < 0.0F) {
    /* DataTypeConversion: '<S21>/Data Type Conversion' */
    ScpAp_L1SpeedM_WhlSpdFR_Phy_Kph = (uint16)-(sint16)(uint16)-tmp_1;
  } else {
    /* DataTypeConversion: '<S21>/Data Type Conversion' */
    ScpAp_L1SpeedM_WhlSpdFR_Phy_Kph = (uint16)tmp_1;
  }

  /* End of DataTypeConversion: '<S21>/Data Type Conversion' */

  /* Logic: '<S21>/OR' incorporates:
   *  Constant: '<S21>/Constant'
   *  Constant: '<S21>/Constant1'
   *  RelationalOperator: '<S21>/Relational Operator'
   *  RelationalOperator: '<S21>/Relational Operator1'
   */
  ScpAp_L1Speed_WhlSpdR_Valid_Chk = ((ScpAp_L1SpeedM_WhlSpdFR_Phy_Kph <
    WhlSpd_Min) || (ScpAp_L1SpeedM_WhlSpdFR_Phy_Kph > WhlSpd_Max));

  /* Switch: '<S21>/Switch' */
  ScpAp_L1SpeedMo_WSS_R_Valid_Flg = !ScpAp_L1Speed_WhlSpdR_Valid_Chk;

  /* Switch: '<S21>/Switch1' */
  if (ScpAp_L1Speed_WhlSpdR_Valid_Chk) {
    /* Switch: '<S21>/Switch1' incorporates:
     *  UnitDelay: '<S21>/Unit Delay'
     */
    ScpAp_L1SpeedMonitor_WSS_R_L1p = WSS_R_L1p_Prev;
  } else {
    /* Outputs for Atomic SubSystem: '<S21>/WSS_R_L1p_Calculation' */
    /* Product: '<S24>/Product' incorporates:
     *  Constant: '<S10>/Constant1'
     */
    tmp = fmod(floor((float64)ScpAp_L1SpeedM_WhlSpdFR_Phy_Kph * Alpha_WSS),
               65536.0);

    /* Sum: '<S24>/Subtract' incorporates:
     *  Constant: '<S10>/Constant1'
     *  Constant: '<S24>/Constant'
     */
    tmp_0 = fmod(floor(1.0 - Alpha_WSS), 65536.0);
    if (tmp_0 < 0.0) {
      tmp_2 = (uint16)-(sint16)(uint16)-tmp_0;
    } else {
      tmp_2 = (uint16)tmp_0;
    }

    /* Product: '<S24>/Product' */
    if (tmp < 0.0) {
      tmp_3 = (uint16)-(sint16)(uint16)-tmp;
    } else {
      tmp_3 = (uint16)tmp;
    }

    /* Switch: '<S21>/Switch1' incorporates:
     *  Product: '<S24>/Product'
     *  Product: '<S24>/Product1'
     *  Sum: '<S24>/Add'
     *  Sum: '<S24>/Subtract'
     *  UnitDelay: '<S21>/Unit Delay'
     */
    ScpAp_L1SpeedMonitor_WSS_R_L1p = (uint16)((uint16)((uint32)tmp_2 *
      WSS_R_L1p_Prev) + (uint32)tmp_3);

    /* End of Outputs for SubSystem: '<S21>/WSS_R_L1p_Calculation' */
  }

  /* End of Switch: '<S21>/Switch1' */
  /* End of Outputs for SubSystem: '<S15>/WSS_R' */
  /* End of Outputs for SubSystem: '<S10>/WSS' */
  /* End of Outputs for SubSystem: '<S5>/WSS_IMU_Motor' */
  /* End of Outputs for SubSystem: '<S2>/SWC_1_Control' */
  /* End of Outputs for SubSystem: '<Root>/SensorIFL1_Main_10_sys' */

  /* Inport: '<Root>/RP_SCpAPSG_mVcuImuLinAccel_SG_mVcuImuLinAccel_VDP' */
  (void)Rte_Read_RP_SCpAPSG_mVcuImuLinAccel_SG_mVcuImuLinAccel_VDP(&tmpRead);

  /* Outputs for Atomic SubSystem: '<Root>/SensorIFL1_Main_10_sys' */
  /* Outputs for Atomic SubSystem: '<S2>/SWC_1_Control' */
  /* Outputs for Atomic SubSystem: '<S5>/WSS_IMU_Motor' */
  /* Outputs for Atomic SubSystem: '<S10>/WSS' */
  /* Outputs for Atomic SubSystem: '<S15>/WSS_R' */
  /* Update for UnitDelay: '<S21>/Unit Delay' */
  WSS_R_L1p_Prev = ScpAp_L1SpeedMonitor_WSS_R_L1p;

  /* End of Outputs for SubSystem: '<S15>/WSS_R' */
  /* End of Outputs for SubSystem: '<S10>/WSS' */

  /* Outputs for Atomic SubSystem: '<S10>/IMU' */
  /* Abs: '<S13>/Abs' */
  ScpAp_L1SpeedMon_X_Accel_L1_Phy = fabsf(tmpRead.X_Accel);

  /* RelationalOperator: '<S13>/Relational Operator' incorporates:
   *  Constant: '<S13>/Constant2'
   */
  ScpAp_L1SpeedMo_IMU_Accel_Valid = (ScpAp_L1SpeedMon_X_Accel_L1_Phy > Accel_Max);

  /* Switch: '<S13>/Switch1' */
  if (ScpAp_L1SpeedMo_IMU_Accel_Valid) {
    /* Switch: '<S13>/Switch1' incorporates:
     *  UnitDelay: '<S13>/Unit Delay'
     */
    ScpAp_L1SpeedMon_IMU_AccelX_L1p = IMU_AccelX_L1p_Prev;
  } else {
    /* Outputs for Atomic SubSystem: '<S13>/IMU_AccelX_L1p_Calculation' */
    /* Switch: '<S13>/Switch1' incorporates:
     *  Constant: '<S10>/Constant2'
     *  Constant: '<S16>/Constant'
     *  Product: '<S16>/Product'
     *  Product: '<S16>/Product1'
     *  Sum: '<S16>/Add'
     *  Sum: '<S16>/Subtract'
     *  UnitDelay: '<S13>/Unit Delay'
     */
    ScpAp_L1SpeedMon_IMU_AccelX_L1p = (float32)((1.0 - Alpha_Accel_IMU) *
      IMU_AccelX_L1p_Prev + Alpha_Accel_IMU * ScpAp_L1SpeedMon_X_Accel_L1_Phy);

    /* End of Outputs for SubSystem: '<S13>/IMU_AccelX_L1p_Calculation' */
  }

  /* End of Switch: '<S13>/Switch1' */
  /* End of Outputs for SubSystem: '<S10>/IMU' */
  /* End of Outputs for SubSystem: '<S5>/WSS_IMU_Motor' */
  /* End of Outputs for SubSystem: '<S2>/SWC_1_Control' */
  /* End of Outputs for SubSystem: '<Root>/SensorIFL1_Main_10_sys' */

  /* Inport: '<Root>/RP_SCpApVmRx_SG_mWhdStat_SG_mWhdStat' */
  (void)Rte_Read_RP_SCpApVmRx_SG_mWhdStat_SG_mWhdStat(&tmpRead_0);

  /* Outputs for Atomic SubSystem: '<Root>/SensorIFL1_Main_10_sys' */
  /* Outputs for Atomic SubSystem: '<S2>/SWC_1_Control' */
  /* Outputs for Atomic SubSystem: '<S5>/WSS_IMU_Motor' */
  /* Outputs for Atomic SubSystem: '<S10>/IMU' */
  /* Switch: '<S13>/Switch' */
  ScpAp_L1Sp_IMU_AccelX_Valid_Flg = !ScpAp_L1SpeedMo_IMU_Accel_Valid;

  /* Update for UnitDelay: '<S13>/Unit Delay' */
  IMU_AccelX_L1p_Prev = ScpAp_L1SpeedMon_IMU_AccelX_L1p;

  /* End of Outputs for SubSystem: '<S10>/IMU' */

  /* Outputs for Atomic SubSystem: '<S10>/Motor' */
  /* Outputs for Atomic SubSystem: '<S14>/RPM_to_Kph' */
  /* DataTypeConversion: '<S18>/Data Type Conversion' incorporates:
   *  Constant: '<S18>/Constant'
   *  Constant: '<S18>/Constant1'
   *  Constant: '<S18>/Constant2'
   *  Constant: '<S18>/Radius_in_mm'
   *  Product: '<S18>/Divide'
   *  Product: '<S18>/Product'
   */
  tmp = fmod(floor(1570.7963267948965 * tmpRead_0.MtrSpd * 60.0 / 1000.0), 256.0);
  if (tmp < 0.0) {
    /* DataTypeConversion: '<S18>/Data Type Conversion' */
    ScpAp_L1SpeedMonit_MotorSpd_kph = (uint8)-(sint8)(uint8)-tmp;
  } else {
    /* DataTypeConversion: '<S18>/Data Type Conversion' */
    ScpAp_L1SpeedMonit_MotorSpd_kph = (uint8)tmp;
  }

  /* End of DataTypeConversion: '<S18>/Data Type Conversion' */
  /* End of Outputs for SubSystem: '<S14>/RPM_to_Kph' */

  /* Logic: '<S14>/OR' incorporates:
   *  Constant: '<S14>/Motor_Max_Spd'
   *  Constant: '<S14>/Motor_Min_Spd'
   *  RelationalOperator: '<S14>/Relational Operator'
   *  RelationalOperator: '<S14>/Relational Operator1'
   */
  ScpAp_L1Sp_Motor_Spd_ValidCheck = ((ScpAp_L1SpeedMonit_MotorSpd_kph <
    Motor_Spd_Min) || (ScpAp_L1SpeedMonit_MotorSpd_kph > Motor_Spd_Max));

  /* Switch: '<S14>/Switch' */
  ScpAp_L1Spe_Motor_RPM_Valid_Flg = !ScpAp_L1Sp_Motor_Spd_ValidCheck;

  /* Switch: '<S14>/Switch1' */
  if (ScpAp_L1Sp_Motor_Spd_ValidCheck) {
    /* Switch: '<S14>/Switch1' incorporates:
     *  UnitDelay: '<S14>/Unit Delay'
     */
    ScpAp_L1Spee_MotorSpd_Equiv_L1p = MotorSpd_Equiv_L1p_Prev;
  } else {
    /* Outputs for Atomic SubSystem: '<S14>/MotorSpd_Equiv_L1p_Calculation' */
    /* Product: '<S17>/Product' incorporates:
     *  Constant: '<S10>/Constant'
     */
    tmp = fmod(floor(Alpha_Motor * (float64)ScpAp_L1SpeedMonit_MotorSpd_kph),
               256.0);

    /* Sum: '<S17>/Subtract' incorporates:
     *  Constant: '<S10>/Constant'
     *  Constant: '<S17>/Constant'
     */
    tmp_0 = fmod(floor(1.0 - Alpha_Motor), 256.0);
    if (tmp_0 < 0.0) {
      tmp_2 = (uint8)-(sint8)(uint8)-tmp_0;
    } else {
      tmp_2 = (uint8)tmp_0;
    }

    /* Product: '<S17>/Product' */
    if (tmp < 0.0) {
      tmp_3 = (uint8)-(sint8)(uint8)-tmp;
    } else {
      tmp_3 = (uint8)tmp;
    }

    /* Switch: '<S14>/Switch1' incorporates:
     *  Product: '<S17>/Product'
     *  Product: '<S17>/Product1'
     *  Sum: '<S17>/Add'
     *  Sum: '<S17>/Subtract'
     *  UnitDelay: '<S14>/Unit Delay'
     */
    ScpAp_L1Spee_MotorSpd_Equiv_L1p = (uint8)((uint8)((uint32)tmp_2 *
      MotorSpd_Equiv_L1p_Prev) + (uint32)tmp_3);

    /* End of Outputs for SubSystem: '<S14>/MotorSpd_Equiv_L1p_Calculation' */
  }

  /* End of Switch: '<S14>/Switch1' */

  /* Update for UnitDelay: '<S14>/Unit Delay' */
  MotorSpd_Equiv_L1p_Prev = ScpAp_L1Spee_MotorSpd_Equiv_L1p;

  /* End of Outputs for SubSystem: '<S10>/Motor' */
  /* End of Outputs for SubSystem: '<S5>/WSS_IMU_Motor' */

  /* Outputs for Atomic SubSystem: '<S5>/Stuck_Counter' */
  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant1'
   *  Product: '<S9>/Divide'
   *  RelationalOperator: '<S9>/Relational Operator'
   *  Sum: '<S9>/Sum'
   */
  ScpAp_L1SpeedMoni_Chk_Stuck_Cnt = ((float64)(uint16)((uint16)
    (ScpAp_L1SpeedMonitor_WSS_FR_L1p + ScpAp_L1SpeedMonitor_WSS_FL_L1p) +
    ScpAp_L1SpeedMonitor_WSS_R_L1p) / 3.0 > 3.0);

  /* Outputs for Atomic SubSystem: '<S9>/Stuck_Cnt_Validity_Check' */
  /* Sum: '<S11>/Subtract3' incorporates:
   *  UnitDelay: '<S11>/Unit Delay3'
   */
  ScpAp_L1SpeedMo_IMU_AccelX_Diff = ScpAp_L1SpeedMon_IMU_AccelX_L1p -
    STC_IMU_Accel_XL1p_Prev;

  /* Sum: '<S11>/Subtract' incorporates:
   *  UnitDelay: '<S11>/Unit Delay'
   */
  ScpAp_L1SpeedMonito_WSS_FR_Diff = (uint16)(ScpAp_L1SpeedMonitor_WSS_FR_L1p -
    STC_WSS_FR_L1p_Prev);

  /* Sum: '<S11>/Subtract1' incorporates:
   *  UnitDelay: '<S11>/Unit Delay1'
   */
  ScpAp_L1SpeedMonito_WSS_FL_Diff = (uint16)(ScpAp_L1SpeedMonitor_WSS_FL_L1p -
    STC_WSS_FL_L1p_Prev);

  /* Sum: '<S11>/Subtract2' incorporates:
   *  UnitDelay: '<S11>/Unit Delay2'
   */
  ScpAp_L1SpeedMonitor_WSS_R_Diff = (uint16)(ScpAp_L1SpeedMonitor_WSS_R_L1p -
    STC_WSS_R_L1p_Prev);

  /* Sum: '<S11>/Subtract4' incorporates:
   *  UnitDelay: '<S11>/Unit Delay4'
   */
  ScpAp_L1Spe_MotorSpd_Equiv_Diff = (uint8)(ScpAp_L1Spee_MotorSpd_Equiv_L1p -
    STC_MotorSpd_Equiv_L1p_Prev);

  /* Logic: '<S11>/OR' incorporates:
   *  Constant: '<S11>/0.05 Kph'
   *  Constant: '<S11>/0.05 m//s2'
   *  Constant: '<S11>/0.08 Kph'
   *  Constant: '<S11>/0.08 Kph_1'
   *  Constant: '<S11>/0.08 Kph_2'
   *  RelationalOperator: '<S11>/Relational Operator'
   *  RelationalOperator: '<S11>/Relational Operator1'
   *  RelationalOperator: '<S11>/Relational Operator2'
   *  RelationalOperator: '<S11>/Relational Operator3'
   *  RelationalOperator: '<S11>/Relational Operator4'
   */
  ScpAp_L1SpeedMoni_Trg_Stuck_Cnt = ((ScpAp_L1SpeedMonito_WSS_FR_Diff < 0.08) ||
    (ScpAp_L1SpeedMonito_WSS_FL_Diff < 0.08) || (ScpAp_L1SpeedMonitor_WSS_R_Diff
    < 0.08) || (ScpAp_L1SpeedMo_IMU_AccelX_Diff < 0.05) ||
    (ScpAp_L1Spe_MotorSpd_Equiv_Diff < 0.05));

  /* Outputs for Atomic SubSystem: '<S11>/UpCounter' */
  /* Switch: '<S12>/Switch1' incorporates:
   *  Constant: '<S12>/Constant1'
   *  Logic: '<S12>/OR'
   *  RelationalOperator: '<S12>/Relational Operator'
   *  RelationalOperator: '<S12>/Relational Operator1'
   *  RelationalOperator: '<S12>/Relational Operator6'
   *  Sum: '<S12>/Add'
   *  Switch: '<S12>/Switch'
   *  UnitDelay: '<S12>/Unit Delay'
   */
  if ((!ScpAp_L1SpeedMoni_Trg_Stuck_Cnt) || (!ScpAp_L1SpeedMoni_Chk_Stuck_Cnt))
  {
    /* Switch: '<S12>/Switch1' incorporates:
     *  Constant: '<S12>/Constant'
     */
    ScpAp_L1SpeedMonitor_Output = 0.0;
  } else if (StuckCntOutput_Prev + 1.0 < 150.0) {
    /* Switch: '<S12>/Switch' incorporates:
     *  Sum: '<S12>/Add'
     *  Switch: '<S12>/Switch1'
     *  UnitDelay: '<S12>/Unit Delay'
     */
    ScpAp_L1SpeedMonitor_Output = StuckCntOutput_Prev + 1.0;
  } else {
    /* Switch: '<S12>/Switch1' incorporates:
     *  Constant: '<S12>/Constant2'
     *  Switch: '<S12>/Switch'
     */
    ScpAp_L1SpeedMonitor_Output = 150.0;
  }

  /* End of Switch: '<S12>/Switch1' */

  /* Update for UnitDelay: '<S12>/Unit Delay' */
  StuckCntOutput_Prev = ScpAp_L1SpeedMonitor_Output;

  /* End of Outputs for SubSystem: '<S11>/UpCounter' */

  /* Switch: '<S11>/Switch' incorporates:
   *  Constant: '<S11>/Constant'
   *  RelationalOperator: '<S11>/Relational Operator5'
   */
  ScpAp_L1S_SensorStuck_Valid_Flg = (ScpAp_L1SpeedMonitor_Output > 100.0);

  /* Update for UnitDelay: '<S11>/Unit Delay3' */
  STC_IMU_Accel_XL1p_Prev = ScpAp_L1SpeedMon_IMU_AccelX_L1p;

  /* Update for UnitDelay: '<S11>/Unit Delay' */
  STC_WSS_FR_L1p_Prev = ScpAp_L1SpeedMonitor_WSS_FR_L1p;

  /* Update for UnitDelay: '<S11>/Unit Delay1' */
  STC_WSS_FL_L1p_Prev = ScpAp_L1SpeedMonitor_WSS_FL_L1p;

  /* Update for UnitDelay: '<S11>/Unit Delay2' */
  STC_WSS_R_L1p_Prev = ScpAp_L1SpeedMonitor_WSS_R_L1p;

  /* Update for UnitDelay: '<S11>/Unit Delay4' */
  STC_MotorSpd_Equiv_L1p_Prev = ScpAp_L1Spee_MotorSpd_Equiv_L1p;

  /* End of Outputs for SubSystem: '<S9>/Stuck_Cnt_Validity_Check' */
  /* End of Outputs for SubSystem: '<S5>/Stuck_Counter' */
  /* End of Outputs for SubSystem: '<S2>/SWC_1_Control' */
  /* End of Outputs for SubSystem: '<Root>/SensorIFL1_Main_10_sys' */

  /* Outport: '<Root>/PP_IMU_AccelX_L1_IF_IMU_AccelX_L1p' */
  (void)Rte_Write_PP_IMU_AccelX_L1_IF_IMU_AccelX_L1p
    (ScpAp_L1SpeedMon_IMU_AccelX_L1p);

  /* Outport: '<Root>/PP_MotorSpeed_L1p_IF_MotorSpeed_L1p' */
  (void)Rte_Write_PP_MotorSpeed_L1p_IF_MotorSpeed_L1p
    (ScpAp_L1Spee_MotorSpd_Equiv_L1p);

  /* Outport: '<Root>/PP_ValidityFlag_L1p_IF_ValidityFlag_L1p' incorporates:
   *  BusCreator generated from: '<Root>/PP_ValidityFlag_L1p_IF_ValidityFlag_L1p'
   */
  ScpAp_L1SpeedMonitor_ARID_DEF.PP_ValidityFlag_L1p_IF_Validity.Motor_RPM_Valid_Flg
    = ScpAp_L1Spe_Motor_RPM_Valid_Flg;
  ScpAp_L1SpeedMonitor_ARID_DEF.PP_ValidityFlag_L1p_IF_Validity.WSS_FR_Valid_Flg
    = ScpAp_L1SpeedM_WSS_FR_Valid_Flg;
  ScpAp_L1SpeedMonitor_ARID_DEF.PP_ValidityFlag_L1p_IF_Validity.WSS_FL_Valid_Flg
    = ScpAp_L1SpeedM_WSS_FL_Valid_Flg;
  ScpAp_L1SpeedMonitor_ARID_DEF.PP_ValidityFlag_L1p_IF_Validity.WSS_R_Valid_Flg =
    ScpAp_L1SpeedMo_WSS_R_Valid_Flg;
  ScpAp_L1SpeedMonitor_ARID_DEF.PP_ValidityFlag_L1p_IF_Validity.IMU_AccelX_Valid_Flg
    = ScpAp_L1Sp_IMU_AccelX_Valid_Flg;
  ScpAp_L1SpeedMonitor_ARID_DEF.PP_ValidityFlag_L1p_IF_Validity.SensorStuck_Valid_Flg
    = ScpAp_L1S_SensorStuck_Valid_Flg;

  /* Outport: '<Root>/PP_Wheelspeed_FL_L1p_IF_Wheelspeed_Fx_L1p' */
  (void)Rte_Write_PP_Wheelspeed_FL_L1p_IF_Wheelspeed_Fx_L1p
    (ScpAp_L1SpeedMonitor_WSS_FL_L1p);

  /* Outport: '<Root>/PP_Wheelspeed_FR_L1p_IF_Wheelspeed_Fx_L1p' */
  (void)Rte_Write_PP_Wheelspeed_FR_L1p_IF_Wheelspeed_Fx_L1p
    (ScpAp_L1SpeedMonitor_WSS_FR_L1p);

  /* Outport: '<Root>/PP_Wheelspeed_R_L1p_IF_Wheelspeed_Fx_L1p' */
  (void)Rte_Write_PP_Wheelspeed_R_L1p_IF_Wheelspeed_Fx_L1p
    (ScpAp_L1SpeedMonitor_WSS_R_L1p);
  (void)Rte_Write_PP_ValidityFlag_L1p_IF_ValidityFlag_L1p
    (&ScpAp_L1SpeedMonitor_ARID_DEF.PP_ValidityFlag_L1p_IF_Validity);
}

#define ScpAp_L1SpeedMonitor_STOP_SEC_CODE
#include "ScpAp_L1SpeedMonitor_MemMap.h"

/* Model initialize function */

/* SwAddrMethod CODE for Runnable */
#define ScpAp_L1SpeedMonitor_START_SEC_CODE
#include "ScpAp_L1SpeedMonitor_MemMap.h"

void ScpAp_L1SpeedMonitor_Init(void)
{
  /* (no initialization code required) */
}

#define ScpAp_L1SpeedMonitor_STOP_SEC_CODE
#include "ScpAp_L1SpeedMonitor_MemMap.h"

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
