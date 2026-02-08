/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ScpAp_VechilestateEstimation_L2p.c
 *
 * Code generated for Simulink model 'ScpAp_VechilestateEstimation_L2p'.
 *
 * Model version                  : 1.117
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Sun Feb  8 17:48:14 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ScpAp_VechilestateEstimation_L2p.h"
#include <math.h>
#include "Platform_Types.h"
#include "Rte_Type.h"

/* Exported data definition */

/* Const memory section */
/* Definition for custom storage class: Const */
const uint16 WhlSpd_Max = 32U;         /* Referenced by:
                                        * '<S7>/Constant12'
                                        * '<S9>/Constant3'
                                        */

/* PublicStructure Variables for Internal Data */
ARID_DEF_ScpAp_VechilestateEs_T ScpAp_VechilestateEsti_ARID_DEF;
                /* '<Root>/PP_SensorValidityFlag_L2p_IF_SensorFaultFlags_L2p' */

/* Static Memory for Internal Data */

/* SwAddrMethod ASW_Variables for Internal Data */
#define ScpAp_VechilestateEstimation_L2p_START_SEC_ASW_Variables
#include "ScpAp_VechilestateEstimation_L2p_MemMap.h"

float64 ScpAp_VechilestateE_Valid_Wheel;/* '<S10>/Sum' */
float64 ScpAp_Vechilestat_Valid_Wheel_R;/* '<S15>/Switch' */
float64 ScpAp_Vechilesta_Valid_Wheel_FR;/* '<S14>/Switch' */
float64 ScpAp_Vechilesta_Valid_Wheel_FL;/* '<S13>/Switch' */
float32 ScpAp_Vechilesta_IMU_AccelX_L1p;/* '<S3>/Data Type Conversion' */
sint16 ScpAp_Vechilest_Wheel_Speed_Avg;/* '<S10>/Data Type Conversion' */
sint16 ScpAp_VehicleSpeed_Weighted_L2; /* '<S9>/Sum' */
sint16 ScpAp_Vechilest_VehicleSpeed_L2;/* '<S9>/Switch' */
sint16 ScpAp_VechilestateEst_Motor_Spd;/* '<S6>/Switch' */
sint16 VehicleSpeed_L2_Prev;           /* '<S5>/Unit Delay' */
uint16 ScpAp_Vechile_Wheelspeed_FL_L1p;/* '<S3>/Data Type Conversion2' */
uint16 ScpAp_Vechile_Wheelspeed_FR_L1p;/* '<S3>/Data Type Conversion3' */
uint16 ScpAp_Vechiles_Wheelspeed_R_L1p;/* '<S3>/Data Type Conversion4' */
uint16 ScpAp_V_VehicleAccel_from_speed;/* '<S8>/Data Type Conversion' */
uint16 ScpAp_Vechilest_VehicleAccel_L2;/* '<S8>/Switch1' */
uint16 ScpAp_Vechi_Cal_VehicleAccel_L2;/* '<S11>/Data Type Conversion' */
uint16 ScpAp_Vechilestat_WSS_x_L1p_Max;/* '<S7>/Max' */
uint16 ScpAp_Vechilestat_WSS_x_L1p_Min;/* '<S7>/Max1' */
uint8 ScpAp_Vechilesta_MotorSpeed_L1p; /* '<S3>/Data Type Conversion1' */
uint8 ScpAp_Vechilest_Valid_Wheel_Cnt; /* '<S12>/Sum' */
boolean ScpAp_Vech_VhlSpd_Wgt_L2_Switch;/* '<S9>/OR' */
boolean ScpAp_Vechilesta_MotorRPM_Fault;/* '<S7>/Switch' */
boolean ScpAp_VechilestateE_Accel_Fault;/* '<S7>/Switch1' */
boolean ScpAp_VechilestateEst_WSS_fault;/* '<S7>/Switch2' */
boolean ScpAp_Vechile_VehSpeedEst_Fault;/* '<S7>/Switch3' */

#define ScpAp_VechilestateEstimation_L2p_STOP_SEC_ASW_Variables
#include "ScpAp_VechilestateEstimation_L2p_MemMap.h"

/* Model step function */

/* SwAddrMethod CODE for Runnable */
#define ScpAp_VechilestateEstimation_L2p_START_SEC_CODE
#include "ScpAp_VechilestateEstimation_L2p_MemMap.h"

void VehstateEst_Main(void)
{
  IF_ValidityFlag_L1p_IDT rtb_TmpSignalConversionAtRP_Scp;
  float64 rtb_Sum;
  sint16 u;

  /* DataTypeConversion: '<S3>/Data Type Conversion4' incorporates:
   *  Inport: '<Root>/RP_ScpAp_Wheelspeed_R_L1p_IF_Wheelspeed_Fx_L1p'
   */
  (void)Rte_Read_RP_ScpAp_Wheelspeed_R_L1p_IF_Wheelspeed_Fx_L1p
    (&ScpAp_Vechiles_Wheelspeed_R_L1p);

  /* DataTypeConversion: '<S3>/Data Type Conversion3' incorporates:
   *  Inport: '<Root>/RP_ScpAp_Wheelspeed_FR_L1p_IF_Wheelspeed_Fx_L1p'
   */
  (void)Rte_Read_RP_ScpAp_Wheelspeed_FR_L1p_IF_Wheelspeed_Fx_L1p
    (&ScpAp_Vechile_Wheelspeed_FR_L1p);

  /* DataTypeConversion: '<S3>/Data Type Conversion2' incorporates:
   *  Inport: '<Root>/RP_ScpAp_Wheelspeed_FL_L1p_IF_Wheelspeed_Fx_L1p'
   */
  (void)Rte_Read_RP_ScpAp_Wheelspeed_FL_L1p_IF_Wheelspeed_Fx_L1p
    (&ScpAp_Vechile_Wheelspeed_FL_L1p);

  /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/RP_ScpAp_IMU_AccelX_L1_IF_IMU_AccelX_L1p'
   */
  (void)Rte_Read_RP_ScpAp_IMU_AccelX_L1_IF_IMU_AccelX_L1p
    (&ScpAp_Vechilesta_IMU_AccelX_L1p);

  /* SignalConversion generated from: '<Root>/RP_ScpAp_ValidityFlag_L1p_IF_ValidityFlag_L1p' incorporates:
   *  Inport: '<Root>/RP_ScpAp_ValidityFlag_L1p_IF_ValidityFlag_L1p'
   */
  (void)Rte_Read_RP_ScpAp_ValidityFlag_L1p_IF_ValidityFlag_L1p
    (&rtb_TmpSignalConversionAtRP_Scp);

  /* Outputs for Atomic SubSystem: '<Root>/VehstateEst_Main_sys' */
  /* DataTypeConversion: '<S3>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/RP_ScpAp_MotorSpeed_L1p_IF_MotorSpeed_L1p'
   */
  ScpAp_Vechilesta_MotorSpeed_L1p =
    Rte_IRead_VehstateEst_Main_RP_ScpAp_MotorSpeed_L1p_IF_MotorSpeed_L1p_RP_ScpAp_MotorSpeed_L1p_IF_MotorSpeed_L1p
    ();

  /* Outputs for Atomic SubSystem: '<S2>/SWC2_Control' */
  /* Outputs for Atomic SubSystem: '<S5>/Wheel_Spd_Avg' */
  /* Outputs for Atomic SubSystem: '<S10>/Valid_Wheels_Chk' */
  /* Outputs for Atomic SubSystem: '<S12>/Chk_Valid_Wheel_FL' */
  /* Switch: '<S13>/Switch' */
  if (rtb_TmpSignalConversionAtRP_Scp.WSS_FL_Valid_Flg) {
    /* Switch: '<S13>/Switch' */
    ScpAp_Vechilesta_Valid_Wheel_FL = ScpAp_Vechile_Wheelspeed_FL_L1p;
  } else {
    /* Switch: '<S13>/Switch' incorporates:
     *  Constant: '<S13>/Constant'
     */
    ScpAp_Vechilesta_Valid_Wheel_FL = 0.0;
  }

  /* End of Switch: '<S13>/Switch' */
  /* End of Outputs for SubSystem: '<S12>/Chk_Valid_Wheel_FL' */

  /* Outputs for Atomic SubSystem: '<S12>/Chk_Valid_Wheel_FR' */
  /* Switch: '<S14>/Switch' */
  if (rtb_TmpSignalConversionAtRP_Scp.WSS_FR_Valid_Flg) {
    /* Switch: '<S14>/Switch' */
    ScpAp_Vechilesta_Valid_Wheel_FR = ScpAp_Vechile_Wheelspeed_FR_L1p;
  } else {
    /* Switch: '<S14>/Switch' incorporates:
     *  Constant: '<S14>/Constant'
     */
    ScpAp_Vechilesta_Valid_Wheel_FR = 0.0;
  }

  /* End of Switch: '<S14>/Switch' */
  /* End of Outputs for SubSystem: '<S12>/Chk_Valid_Wheel_FR' */

  /* Outputs for Atomic SubSystem: '<S12>/Chk_Valid_Wheel_R' */
  /* Switch: '<S15>/Switch' */
  if (rtb_TmpSignalConversionAtRP_Scp.WSS_R_Valid_Flg) {
    /* Switch: '<S15>/Switch' */
    ScpAp_Vechilestat_Valid_Wheel_R = ScpAp_Vechiles_Wheelspeed_R_L1p;
  } else {
    /* Switch: '<S15>/Switch' incorporates:
     *  Constant: '<S15>/Constant'
     */
    ScpAp_Vechilestat_Valid_Wheel_R = 0.0;
  }

  /* End of Switch: '<S15>/Switch' */
  /* End of Outputs for SubSystem: '<S12>/Chk_Valid_Wheel_R' */

  /* Sum: '<S12>/Sum' */
  ScpAp_Vechilest_Valid_Wheel_Cnt = (uint8)(((uint32)
    rtb_TmpSignalConversionAtRP_Scp.WSS_FR_Valid_Flg +
    rtb_TmpSignalConversionAtRP_Scp.WSS_FL_Valid_Flg) +
    rtb_TmpSignalConversionAtRP_Scp.WSS_R_Valid_Flg);

  /* End of Outputs for SubSystem: '<S10>/Valid_Wheels_Chk' */

  /* Sum: '<S10>/Sum' */
  ScpAp_VechilestateE_Valid_Wheel = (ScpAp_Vechilesta_Valid_Wheel_FR +
    ScpAp_Vechilesta_Valid_Wheel_FL) + ScpAp_Vechilestat_Valid_Wheel_R;

  /* Switch: '<S10>/Switch1' */
  if (ScpAp_VechilestateE_Valid_Wheel != 0.0) {
    /* Sum: '<S11>/Sum' incorporates:
     *  Product: '<S10>/Divide'
     */
    rtb_Sum = ScpAp_VechilestateE_Valid_Wheel / (float64)
      ScpAp_Vechilest_Valid_Wheel_Cnt;
  } else {
    /* Sum: '<S11>/Sum' incorporates:
     *  UnitDelay: '<S5>/Unit Delay'
     */
    rtb_Sum = VehicleSpeed_L2_Prev;
  }

  /* End of Switch: '<S10>/Switch1' */

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  rtb_Sum = fmod(floor(rtb_Sum), 65536.0);
  if (rtb_Sum < 0.0) {
    /* DataTypeConversion: '<S10>/Data Type Conversion' */
    ScpAp_Vechilest_Wheel_Speed_Avg = (sint16)-(sint16)(uint16)-rtb_Sum;
  } else {
    /* DataTypeConversion: '<S10>/Data Type Conversion' */
    ScpAp_Vechilest_Wheel_Speed_Avg = (sint16)(uint16)rtb_Sum;
  }

  /* End of DataTypeConversion: '<S10>/Data Type Conversion' */
  /* End of Outputs for SubSystem: '<S5>/Wheel_Spd_Avg' */

  /* Outputs for Atomic SubSystem: '<S5>/Motor_Speed' */
  /* Switch: '<S6>/Switch' */
  if (rtb_TmpSignalConversionAtRP_Scp.Motor_RPM_Valid_Flg) {
    /* Switch: '<S6>/Switch' */
    ScpAp_VechilestateEst_Motor_Spd = ScpAp_Vechilesta_MotorSpeed_L1p;
  } else {
    /* Switch: '<S6>/Switch' */
    ScpAp_VechilestateEst_Motor_Spd = ScpAp_Vechilest_Wheel_Speed_Avg;
  }

  /* End of Switch: '<S6>/Switch' */
  /* End of Outputs for SubSystem: '<S5>/Motor_Speed' */

  /* Outputs for Atomic SubSystem: '<S5>/Vehicle_Speed_L2' */
  /* Sum: '<S9>/Sum' incorporates:
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant1'
   *  Product: '<S9>/Product'
   *  Product: '<S9>/Product1'
   */
  ScpAp_VehicleSpeed_Weighted_L2 = (sint16)((sint16)(W1 *
    ScpAp_Vechilest_Wheel_Speed_Avg) + (sint16)(W2 *
    ScpAp_VechilestateEst_Motor_Spd));

  /* Outputs for Atomic SubSystem: '<S5>/SensorFault' */
  /* Logic: '<S9>/OR' incorporates:
   *  Constant: '<S9>/Constant3'
   *  Logic: '<S7>/OR'
   *  RelationalOperator: '<S9>/Relational Operator'
   *  RelationalOperator: '<S9>/Relational Operator1'
   */
  ScpAp_Vech_VhlSpd_Wgt_L2_Switch = ((ScpAp_VehicleSpeed_Weighted_L2 < 0) ||
    (ScpAp_VehicleSpeed_Weighted_L2 > WhlSpd_Max));

  /* End of Outputs for SubSystem: '<S5>/SensorFault' */

  /* Switch: '<S9>/Switch' */
  if (ScpAp_Vech_VhlSpd_Wgt_L2_Switch) {
    /* Saturate: '<S9>/Saturation' */
    if (ScpAp_VehicleSpeed_Weighted_L2 > 32) {
      /* Switch: '<S9>/Switch' */
      ScpAp_Vechilest_VehicleSpeed_L2 = 32;
    } else if (ScpAp_VehicleSpeed_Weighted_L2 < 0) {
      /* Switch: '<S9>/Switch' */
      ScpAp_Vechilest_VehicleSpeed_L2 = 0;
    } else {
      /* Switch: '<S9>/Switch' */
      ScpAp_Vechilest_VehicleSpeed_L2 = ScpAp_VehicleSpeed_Weighted_L2;
    }
  } else {
    /* Switch: '<S9>/Switch' incorporates:
     *  Saturate: '<S9>/Saturation'
     */
    ScpAp_Vechilest_VehicleSpeed_L2 = ScpAp_VehicleSpeed_Weighted_L2;
  }

  /* End of Switch: '<S9>/Switch' */
  /* End of Outputs for SubSystem: '<S5>/Vehicle_Speed_L2' */

  /* Outputs for Atomic SubSystem: '<S5>/SensorFault' */
  /* Sum: '<S7>/Subtract' */
  u = (sint16)(ScpAp_Vechilest_VehicleSpeed_L2 - ScpAp_Vechilesta_MotorSpeed_L1p);

  /* Abs: '<S7>/Abs' */
  if (u < 0) {
    u = (sint16)-u;
  }

  /* Switch: '<S7>/Switch' incorporates:
   *  Abs: '<S7>/Abs'
   *  Constant: '<S7>/Constant1'
   *  Logic: '<S7>/AND'
   *  RelationalOperator: '<S7>/Relational Operator'
   *  RelationalOperator: '<S7>/Relational Operator1'
   */
  ScpAp_Vechilesta_MotorRPM_Fault =
    (rtb_TmpSignalConversionAtRP_Scp.Motor_RPM_Valid_Flg && (u > Speed_Diff_Th));

  /* Switch: '<S7>/Switch1' incorporates:
   *  Abs: '<S7>/Abs1'
   *  Constant: '<S7>/Constant5'
   *  Logic: '<S7>/AND2'
   *  RelationalOperator: '<S7>/Relational Operator2'
   *  RelationalOperator: '<S7>/Relational Operator3'
   *  Sum: '<S7>/Subtract1'
   */
  if (rtb_TmpSignalConversionAtRP_Scp.IMU_AccelX_Valid_Flg && (fabsf((float32)
        ScpAp_Vechilest_VehicleSpeed_L2 - ScpAp_Vechilesta_IMU_AccelX_L1p) >
       Accel_Diff_Th)) {
    /* Switch: '<S7>/Switch1' incorporates:
     *  Constant: '<S7>/Constant6'
     */
    ScpAp_VechilestateE_Accel_Fault = TRUE;
  } else {
    /* Switch: '<S7>/Switch1' incorporates:
     *  RelationalOperator: '<S7>/Relational Operator8'
     */
    ScpAp_VechilestateE_Accel_Fault =
      !rtb_TmpSignalConversionAtRP_Scp.IMU_AccelX_Valid_Flg;
  }

  /* End of Switch: '<S7>/Switch1' */

  /* MinMax: '<S7>/Max' */
  if (ScpAp_Vechile_Wheelspeed_FR_L1p >= ScpAp_Vechile_Wheelspeed_FL_L1p) {
    ScpAp_Vechilestat_WSS_x_L1p_Max = ScpAp_Vechile_Wheelspeed_FR_L1p;
  } else {
    ScpAp_Vechilestat_WSS_x_L1p_Max = ScpAp_Vechile_Wheelspeed_FL_L1p;
  }

  if (ScpAp_Vechilestat_WSS_x_L1p_Max < ScpAp_Vechiles_Wheelspeed_R_L1p) {
    /* MinMax: '<S7>/Max' */
    ScpAp_Vechilestat_WSS_x_L1p_Max = ScpAp_Vechiles_Wheelspeed_R_L1p;
  }

  /* End of MinMax: '<S7>/Max' */

  /* MinMax: '<S7>/Max1' */
  if (ScpAp_Vechile_Wheelspeed_FR_L1p <= ScpAp_Vechile_Wheelspeed_FL_L1p) {
    ScpAp_Vechilestat_WSS_x_L1p_Min = ScpAp_Vechile_Wheelspeed_FR_L1p;
  } else {
    ScpAp_Vechilestat_WSS_x_L1p_Min = ScpAp_Vechile_Wheelspeed_FL_L1p;
  }

  if (ScpAp_Vechilestat_WSS_x_L1p_Min > ScpAp_Vechiles_Wheelspeed_R_L1p) {
    /* MinMax: '<S7>/Max1' */
    ScpAp_Vechilestat_WSS_x_L1p_Min = ScpAp_Vechiles_Wheelspeed_R_L1p;
  }

  /* End of MinMax: '<S7>/Max1' */

  /* Switch: '<S7>/Switch2' incorporates:
   *  Constant: '<S7>/Constant8'
   *  RelationalOperator: '<S7>/Relational Operator4'
   *  Sum: '<S7>/Subtract2'
   */
  if ((uint16)(ScpAp_Vechilestat_WSS_x_L1p_Max - ScpAp_Vechilestat_WSS_x_L1p_Min)
      > Wheel_Diff_Th) {
    /* Switch: '<S7>/Switch2' incorporates:
     *  Constant: '<S7>/Constant9'
     */
    ScpAp_VechilestateEst_WSS_fault = TRUE;
  } else {
    /* Switch: '<S7>/Switch2' incorporates:
     *  Constant: '<S7>/Constant10'
     *  RelationalOperator: '<S7>/Relational Operator7'
     */
    ScpAp_VechilestateEst_WSS_fault = (ScpAp_VechilestateE_Valid_Wheel == 0.0);
  }

  /* End of Switch: '<S7>/Switch2' */

  /* Switch: '<S7>/Switch3' */
  ScpAp_Vechile_VehSpeedEst_Fault = ScpAp_Vech_VhlSpd_Wgt_L2_Switch;

  /* End of Outputs for SubSystem: '<S5>/SensorFault' */

  /* Outputs for Atomic SubSystem: '<S5>/VehAccel_L2' */
  /* DataTypeConversion: '<S8>/Data Type Conversion' incorporates:
   *  Constant: '<S8>/Constant'
   *  Product: '<S8>/Divide'
   *  Sum: '<S8>/Subtract'
   *  UnitDelay: '<S5>/Unit Delay'
   */
  rtb_Sum = fmod(floor((float64)(sint16)(ScpAp_Vechilest_VehicleSpeed_L2 -
    VehicleSpeed_L2_Prev) / DT), 65536.0);
  if (rtb_Sum < 0.0) {
    /* DataTypeConversion: '<S8>/Data Type Conversion' */
    ScpAp_V_VehicleAccel_from_speed = (uint16)-(sint16)(uint16)-rtb_Sum;
  } else {
    /* DataTypeConversion: '<S8>/Data Type Conversion' */
    ScpAp_V_VehicleAccel_from_speed = (uint16)rtb_Sum;
  }

  /* End of DataTypeConversion: '<S8>/Data Type Conversion' */

  /* Outputs for Atomic SubSystem: '<S8>/Cal_VehicleAccel_L2 ' */
  /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/Constant1'
   *  Product: '<S11>/Product'
   *  Product: '<S11>/Product1'
   *  Sum: '<S11>/Sum'
   */
  rtb_Sum = fmod(floor((float64)ScpAp_V_VehicleAccel_from_speed * 0.75 + 0.25 *
                       ScpAp_Vechilesta_IMU_AccelX_L1p), 65536.0);
  if (rtb_Sum < 0.0) {
    /* DataTypeConversion: '<S11>/Data Type Conversion' */
    ScpAp_Vechi_Cal_VehicleAccel_L2 = (uint16)-(sint16)(uint16)-rtb_Sum;
  } else {
    /* DataTypeConversion: '<S11>/Data Type Conversion' */
    ScpAp_Vechi_Cal_VehicleAccel_L2 = (uint16)rtb_Sum;
  }

  /* End of DataTypeConversion: '<S11>/Data Type Conversion' */
  /* End of Outputs for SubSystem: '<S8>/Cal_VehicleAccel_L2 ' */

  /* Switch: '<S8>/Switch1' */
  if (rtb_TmpSignalConversionAtRP_Scp.IMU_AccelX_Valid_Flg) {
    /* Switch: '<S8>/Switch1' */
    ScpAp_Vechilest_VehicleAccel_L2 = ScpAp_Vechi_Cal_VehicleAccel_L2;
  } else {
    /* Switch: '<S8>/Switch1' */
    ScpAp_Vechilest_VehicleAccel_L2 = ScpAp_V_VehicleAccel_from_speed;
  }

  /* End of Switch: '<S8>/Switch1' */
  /* End of Outputs for SubSystem: '<S5>/VehAccel_L2' */

  /* Update for UnitDelay: '<S5>/Unit Delay' */
  VehicleSpeed_L2_Prev = ScpAp_Vechilest_VehicleSpeed_L2;

  /* End of Outputs for SubSystem: '<S2>/SWC2_Control' */
  /* End of Outputs for SubSystem: '<Root>/VehstateEst_Main_sys' */

  /* Outport: '<Root>/PP_SensorValidityFlag_L2p_IF_SensorFaultFlags_L2p' incorporates:
   *  BusCreator generated from: '<Root>/PP_SensorValidityFlag_L2p_IF_SensorFaultFlags_L2p'
   */
  ScpAp_VechilestateEsti_ARID_DEF.PP_SensorValidityFlag_L2p_IF_Se.MotorRPM_Fault
    = ScpAp_Vechilesta_MotorRPM_Fault;
  ScpAp_VechilestateEsti_ARID_DEF.PP_SensorValidityFlag_L2p_IF_Se.Accel_Fault =
    ScpAp_VechilestateE_Accel_Fault;
  ScpAp_VechilestateEsti_ARID_DEF.PP_SensorValidityFlag_L2p_IF_Se.WSS_Fault =
    ScpAp_VechilestateEst_WSS_fault;
  ScpAp_VechilestateEsti_ARID_DEF.PP_SensorValidityFlag_L2p_IF_Se.VechSpeedEst_Fault
    = ScpAp_Vechile_VehSpeedEst_Fault;

  /* Outport: '<Root>/PP_VechileAccel_L2p_IF_VechileAccel_L2p' */
  (void)Rte_Write_PP_VechileAccel_L2p_IF_VechileAccel_L2p
    (ScpAp_Vechilest_VehicleSpeed_L2);

  /* Outport: '<Root>/PP_Vechilespeed_L2p_IF_Vechilespeed_L2p' */
  (void)Rte_Write_PP_Vechilespeed_L2p_IF_Vechilespeed_L2p
    (ScpAp_Vechilest_VehicleAccel_L2);
  (void)Rte_Write_PP_SensorValidityFlag_L2p_IF_SensorFaultFlags_L2p
    (&ScpAp_VechilestateEsti_ARID_DEF.PP_SensorValidityFlag_L2p_IF_Se);
}

#define ScpAp_VechilestateEstimation_L2p_STOP_SEC_CODE
#include "ScpAp_VechilestateEstimation_L2p_MemMap.h"

/* Model initialize function */

/* SwAddrMethod CODE for Runnable */
#define ScpAp_VechilestateEstimation_L2p_START_SEC_CODE
#include "ScpAp_VechilestateEstimation_L2p_MemMap.h"

void ScpAp_VechilestateEstimation_L2p_Init(void)
{
  /* (no initialization code required) */
}

#define ScpAp_VechilestateEstimation_L2p_STOP_SEC_CODE
#include "ScpAp_VechilestateEstimation_L2p_MemMap.h"

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
