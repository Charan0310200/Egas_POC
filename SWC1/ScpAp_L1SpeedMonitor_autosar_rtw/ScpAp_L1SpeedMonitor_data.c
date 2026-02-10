/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ScpAp_L1SpeedMonitor_data.c
 *
 * Code generated for Simulink model 'ScpAp_L1SpeedMonitor'.
 *
 * Model version                  : 1.177
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Tue Feb 10 15:17:05 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ScpAp_L1SpeedMonitor.h"

/* Constant memory autosar model workspace parameters */

/* SwAddrMethod CALIB for Model Work Space Parameters */
#define ScpAp_L1SpeedMonitor_START_SEC_CALIB
#include "ScpAp_L1SpeedMonitor_MemMap.h"

const float64 Accel_Max = 32.767;      /* Variable: Accel_Max
                                        * Referenced by: '<S13>/Constant2'
                                        */
const float64 Alpha_Accel_IMU = 0.15;  /* Variable: Alpha_Accel_IMU
                                        * Referenced by: '<S10>/Constant2'
                                        */
const float64 Alpha_Motor = 0.45;      /* Variable: Alpha_Motor
                                        * Referenced by: '<S10>/Constant'
                                        */
const float64 Alpha_WSS = 0.35;        /* Variable: Alpha_WSS
                                        * Referenced by: '<S10>/Constant1'
                                        */
const uint16 Motor_Spd_Max = 1023U;    /* Variable: Motor_Spd_Max
                                        * Referenced by: '<S14>/Motor_Max_Spd'
                                        */
const uint16 Motor_Spd_Min = 0U;       /* Variable: Motor_Spd_Min
                                        * Referenced by: '<S14>/Motor_Min_Spd'
                                        */

#define ScpAp_L1SpeedMonitor_STOP_SEC_CALIB
#include "ScpAp_L1SpeedMonitor_MemMap.h"

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
