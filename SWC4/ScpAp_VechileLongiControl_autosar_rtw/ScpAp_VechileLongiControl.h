/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ScpAp_VechileLongiControl.h
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

#ifndef ScpAp_VechileLongiControl_h_
#define ScpAp_VechileLongiControl_h_
#ifndef ScpAp_VechileLongiControl_COMMON_INCLUDES_
#define ScpAp_VechileLongiControl_COMMON_INCLUDES_
#include "Platform_Types.h"
#include "Rte_ScpAp_VechileLongiControl.h"
#endif                          /* ScpAp_VechileLongiControl_COMMON_INCLUDES_ */

#include "ScpAp_VechileLongiControl_types.h"
#include "Rte_Type.h"

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  uint16 Vechilespeed_L2p;
                      /* '<S3>/RP_ScpAp_Vechilespeed_L2p_IF_Vechilespeed_L2p' */
  SafetyMode_L2p_IDT Mode_L2p;  /* '<S3>/RP_ScpAp_Mode_L2p_IF_SafetyMode_L2p' */
} ARID_DEF_ScpAp_VechileLongiCo_T;

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_ScpAp_VechileLongiCo_T ScpAp_VechileLongiCont_ARID_DEF;
                      /* '<S3>/RP_ScpAp_Vechilespeed_L2p_IF_Vechilespeed_L2p' */

/* Static Memory for Internal Data */

/* SwAddrMethod ASW_Variables for Internal Data */
#define ScpAp_VechileLongiControl_START_SEC_ASW_Variables
#include "ScpAp_VechileLongiControl_MemMap.h"

extern float64 Integrator_State;       /* '<S6>/Unit Delay' */
extern float32 ScpAp_VechileLong_VehSpdCmd_Kph;/* '<S6>/m//s to Kmph' */
extern float32 ScpAp_VechileLongiC_Speed_Error;/* '<S6>/Subtract' */
extern sint16 ScpAp_Vech_NominalTorquecmd_L2p;/* '<S5>/Switch' */
extern sint16 ScpAp_Clamped_Integrator_State;/* '<S6>/Data Type Conversion' */
extern sint16 ScpAp_Vechile_proportional_term;/* '<S6>/Data Type Conversion1' */
extern sint16 ScpAp_VechileLongiC_Control_raw;/* '<S6>/Add1' */
extern sint16 ScpAp_Cal_NominalTorquecmd_L2p;/* '<S6>/Saturation2' */

#define ScpAp_VechileLongiControl_STOP_SEC_ASW_Variables
#include "ScpAp_VechileLongiControl_MemMap.h"

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
 * '<Root>' : 'ScpAp_VechileLongiControl'
 * '<S1>'   : 'ScpAp_VechileLongiControl/ScpAp_VechileLongiControl_Init'
 * '<S2>'   : 'ScpAp_VechileLongiControl/VechileLongiControl_Main_sys'
 * '<S3>'   : 'ScpAp_VechileLongiControl/VechileLongiControl_Main_sys/Comm_Rx'
 * '<S4>'   : 'ScpAp_VechileLongiControl/VechileLongiControl_Main_sys/Comm_Tx'
 * '<S5>'   : 'ScpAp_VechileLongiControl/VechileLongiControl_Main_sys/SWC4_Control'
 * '<S6>'   : 'ScpAp_VechileLongiControl/VechileLongiControl_Main_sys/SWC4_Control/Calculate_NominalTorquecmd_L2p'
 */
#endif                                 /* ScpAp_VechileLongiControl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
