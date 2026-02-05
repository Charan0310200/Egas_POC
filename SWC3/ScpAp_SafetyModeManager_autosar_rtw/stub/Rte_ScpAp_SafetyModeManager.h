/* This file contains stub implementations of the AUTOSAR RTE functions.
   The stub implementations can be used for testing the generated code in
   Simulink, for example, in SIL/PIL simulations of the component under
   test. Note that this file should be replaced with an appropriate RTE
   file when deploying the generated code outside of Simulink.

   This file is generated for:
   Atomic software component:  "ScpAp_SafetyModeManager"
   ARXML schema: "R20-11"
   File generated on: "Wed Feb 04 15:06:25 2026"  */

#ifndef Rte_ScpAp_SafetyModeManager_h
#define Rte_ScpAp_SafetyModeManager_h
#include "Rte_Type.h"
#include "Compiler.h"

/* Data access functions */
#define Rte_Write_PP_AutonomousAllowed_IF_AutonomousAllowed Rte_Write_ScpAp_SafetyModeManager_PP_AutonomousAllowed_IF_AutonomousAllowed

Std_ReturnType Rte_Write_PP_AutonomousAllowed_IF_AutonomousAllowed
  (SafetyMode_L2p_IDT u);

#define Rte_Invalidate_PP_AutonomousAllowed_IF_AutonomousAllowed Rte_Invalidate_ScpAp_SafetyModeManager_PP_AutonomousAllowed_IF_AutonomousAllowed

Std_ReturnType Rte_Invalidate_PP_AutonomousAllowed_IF_AutonomousAllowed(void);

#define Rte_Write_PP_Mode_L2p_IF_SafetyMode_L2p Rte_Write_ScpAp_SafetyModeManager_PP_Mode_L2p_IF_SafetyMode_L2p

Std_ReturnType Rte_Write_PP_Mode_L2p_IF_SafetyMode_L2p(SafetyMode_L2p_IDT u);

#define Rte_Invalidate_PP_Mode_L2p_IF_SafetyMode_L2p Rte_Invalidate_ScpAp_SafetyModeManager_PP_Mode_L2p_IF_SafetyMode_L2p

Std_ReturnType Rte_Invalidate_PP_Mode_L2p_IF_SafetyMode_L2p(void);

#define Rte_Read_RP_ScpAp_VechSafetyStatus_L2p_IF_VechSafetyStatus_L2p Rte_Read_ScpAp_SafetyModeManager_RP_ScpAp_VechSafetyStatus_L2p_IF_VechSafetyStatus_L2p

Std_ReturnType Rte_Read_RP_ScpAp_VechSafetyStatus_L2p_IF_VechSafetyStatus_L2p
  (VechSafetyStatus_L2p_IDT* u);

/* Entry point functions */
extern FUNC(void, ScpAp_SafetyModeManager_CODE) SafetyModeManager_Main(void);
extern FUNC(void, ScpAp_SafetyModeManager_CODE) ScpAp_SafetyModeManager_Init
  (void);

#endif
