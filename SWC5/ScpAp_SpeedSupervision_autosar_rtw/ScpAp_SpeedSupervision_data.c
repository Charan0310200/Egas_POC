/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ScpAp_SpeedSupervision_data.c
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

/* Constant memory autosar model workspace parameters */

/* SwAddrMethod CALIB for Model Work Space Parameters */
#define ScpAp_SpeedSupervision_START_SEC_CALIB
#include "ScpAp_SpeedSupervision_MemMap.h"

const float64 K_Pred = 0.003;          /* Variable: K_Pred
                                        * Referenced by: '<S5>/Constant10'
                                        */
const float64 TH_Hystersis = 3.0;      /* Variable: TH_Hystersis
                                        * Referenced by: '<S6>/Constant11'
                                        */
const float64 TH_Mon_Accel_Diff = 2.0; /* Variable: TH_Mon_Accel_Diff
                                        * Referenced by: '<S5>/Constant'
                                        */
const float64 TH_Mon_Speed_Diff = 2.0; /* Variable: TH_Mon_Speed_Diff
                                        * Referenced by: '<S7>/Constant16'
                                        */
const float64 TH_Pred_Margin = 2.0;    /* Variable: TH_Pred_Margin
                                        * Referenced by: '<S5>/Constant12'
                                        */
const float64 TH_Speed_Limit_Margin = 3.0;/* Variable: TH_Speed_Limit_Margin
                                           * Referenced by: '<S6>/Constant6'
                                           */
const sint16 Torque_Decel_Limit = 500; /* Variable: Torque_Decel_Limit
                                        * Referenced by: '<S5>/Constant15'
                                        */
const sint16 Torque_PreLimit = 600;    /* Variable: Torque_PreLimit
                                        * Referenced by: '<S5>/Constant16'
                                        */

#define ScpAp_SpeedSupervision_STOP_SEC_CALIB
#include "ScpAp_SpeedSupervision_MemMap.h"

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
