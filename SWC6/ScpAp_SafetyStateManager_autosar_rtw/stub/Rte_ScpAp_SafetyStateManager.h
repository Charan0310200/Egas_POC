/* This file contains stub implementations of the AUTOSAR RTE functions.
   The stub implementations can be used for testing the generated code in
   Simulink, for example, in SIL/PIL simulations of the component under
   test. Note that this file should be replaced with an appropriate RTE
   file when deploying the generated code outside of Simulink.

   This file is generated for:
   Atomic software component:  "ScpAp_SafetyStateManager"
   ARXML schema: "R20-11"
   File generated on: "Thu Feb 19 12:25:17 2026"  */

#ifndef Rte_ScpAp_SafetyStateManager_h
#define Rte_ScpAp_SafetyStateManager_h
#include "Rte_Type.h"
#include "Compiler.h"

/* Data access functions */
#define Rte_Read_RP_ScpAP_SafetySpeedMonitorFaultFlag_IF_SafetySpeedMonitorFaultFlag Rte_Read_ScpAp_SafetyStateManager_RP_ScpAP_SafetySpeedMonitorFaultFlag_IF_SafetySpeedMonitorFaultFlag

Std_ReturnType
  Rte_Read_RP_ScpAP_SafetySpeedMonitorFaultFlag_IF_SafetySpeedMonitorFaultFlag
  (boolean* u);

#define Rte_Read_RP_ScpAp_SafeTorquecmd_L2p_IF_SafeTorquecmd_L2p Rte_Read_ScpAp_SafetyStateManager_RP_ScpAp_SafeTorquecmd_L2p_IF_SafeTorquecmd_L2p

Std_ReturnType Rte_Read_RP_ScpAp_SafeTorquecmd_L2p_IF_SafeTorquecmd_L2p(sint16*
  u);

#define Rte_Read_RP_ScpAp_SafetyOverspeedFlag_IF_SafetyOverspeedFlag Rte_Read_ScpAp_SafetyStateManager_RP_ScpAp_SafetyOverspeedFlag_IF_SafetyOverspeedFlag

Std_ReturnType Rte_Read_RP_ScpAp_SafetyOverspeedFlag_IF_SafetyOverspeedFlag
  (boolean* u);

#define Rte_Read_RP_ScpAp_SensorValidityFlag_L2p_IF_SensorFaultFlags_L2p Rte_Read_ScpAp_SafetyStateManager_RP_ScpAp_SensorValidityFlag_L2p_IF_SensorFaultFlags_L2p

Std_ReturnType Rte_Read_RP_ScpAp_SensorValidityFlag_L2p_IF_SensorFaultFlags_L2p
  (IF_SensorFaultFlgs_L2p_IDT* u);

#define Rte_Write_PP_SG_mBrkCtrl_SG_mBrkCtrl_VDP Rte_Write_ScpAp_SafetyStateManager_PP_SG_mBrkCtrl_SG_mBrkCtrl_VDP

Std_ReturnType Rte_Write_PP_SG_mBrkCtrl_SG_mBrkCtrl_VDP(const SG_mBrkCtrl_IDT* u);

#define Rte_Invalidate_PP_SG_mBrkCtrl_SG_mBrkCtrl_VDP Rte_Invalidate_ScpAp_SafetyStateManager_PP_SG_mBrkCtrl_SG_mBrkCtrl_VDP

Std_ReturnType Rte_Invalidate_PP_SG_mBrkCtrl_SG_mBrkCtrl_VDP(void);

#define Rte_Write_PP_SG_mWhdCtrl_SG_mWhdCtrl_VDP Rte_Write_ScpAp_SafetyStateManager_PP_SG_mWhdCtrl_SG_mWhdCtrl_VDP

Std_ReturnType Rte_Write_PP_SG_mWhdCtrl_SG_mWhdCtrl_VDP(const SG_mWhdCtrl_IDT* u);

#define Rte_Invalidate_PP_SG_mWhdCtrl_SG_mWhdCtrl_VDP Rte_Invalidate_ScpAp_SafetyStateManager_PP_SG_mWhdCtrl_SG_mWhdCtrl_VDP

Std_ReturnType Rte_Invalidate_PP_SG_mWhdCtrl_SG_mWhdCtrl_VDP(void);

#define Rte_Write_PP_VechSafetyStatus_L2p_IF_VechSafetyStatus_L2p Rte_Write_ScpAp_SafetyStateManager_PP_VechSafetyStatus_L2p_IF_VechSafetyStatus_L2p

Std_ReturnType Rte_Write_PP_VechSafetyStatus_L2p_IF_VechSafetyStatus_L2p
  (VechSafetyStatus_L2p_IDT u);

#define Rte_Invalidate_PP_VechSafetyStatus_L2p_IF_VechSafetyStatus_L2p Rte_Invalidate_ScpAp_SafetyStateManager_PP_VechSafetyStatus_L2p_IF_VechSafetyStatus_L2p

Std_ReturnType Rte_Invalidate_PP_VechSafetyStatus_L2p_IF_VechSafetyStatus_L2p
  (void);

/* Entry point functions */
extern FUNC(void, ScpAp_SafetyStateManager_CODE) SafetyState_Main(void);
extern FUNC(void, ScpAp_SafetyStateManager_CODE) ScpAp_SafetyStateManager_Init
  (void);

#endif
