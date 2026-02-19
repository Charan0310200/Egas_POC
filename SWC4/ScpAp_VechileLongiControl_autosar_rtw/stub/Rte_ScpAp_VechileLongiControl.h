/* This file contains stub implementations of the AUTOSAR RTE functions.
   The stub implementations can be used for testing the generated code in
   Simulink, for example, in SIL/PIL simulations of the component under
   test. Note that this file should be replaced with an appropriate RTE
   file when deploying the generated code outside of Simulink.

   This file is generated for:
   Atomic software component:  "ScpAp_VechileLongiControl"
   ARXML schema: "R20-11"
   File generated on: "Tue Feb 17 16:18:47 2026"  */

#ifndef Rte_ScpAp_VechileLongiControl_h
#define Rte_ScpAp_VechileLongiControl_h
#include "Rte_Type.h"
#include "Compiler.h"

/* Data access functions */
#define Rte_Read_RP_ScpAp_Mode_L2p_IF_SafetyMode_L2p Rte_Read_ScpAp_VechileLongiControl_RP_ScpAp_Mode_L2p_IF_SafetyMode_L2p

Std_ReturnType Rte_Read_RP_ScpAp_Mode_L2p_IF_SafetyMode_L2p(SafetyMode_L2p_IDT*
  u);

#define Rte_Read_RP_ScpAp_Vechilespeed_L2p_IF_Vechilespeed_L2p Rte_Read_ScpAp_VechileLongiControl_RP_ScpAp_Vechilespeed_L2p_IF_Vechilespeed_L2p

Std_ReturnType Rte_Read_RP_ScpAp_Vechilespeed_L2p_IF_Vechilespeed_L2p(uint16* u);

#define Rte_Write_PP_NominalTorquecmd_L2p_IF_NominalTorquecmd_L2p Rte_Write_ScpAp_VechileLongiControl_PP_NominalTorquecmd_L2p_IF_NominalTorquecmd_L2p

Std_ReturnType Rte_Write_PP_NominalTorquecmd_L2p_IF_NominalTorquecmd_L2p(sint16
  u);

#define Rte_Invalidate_PP_NominalTorquecmd_L2p_IF_NominalTorquecmd_L2p Rte_Invalidate_ScpAp_VechileLongiControl_PP_NominalTorquecmd_L2p_IF_NominalTorquecmd_L2p

Std_ReturnType Rte_Invalidate_PP_NominalTorquecmd_L2p_IF_NominalTorquecmd_L2p
  (void);

#define Rte_Read_RP_ScpApADRx_SG_mVehCtrlADRq_SG_mVehCtrlADRq Rte_Read_ScpAp_VechileLongiControl_RP_ScpApADRx_SG_mVehCtrlADRq_SG_mVehCtrlADRq

Std_ReturnType Rte_Read_RP_ScpApADRx_SG_mVehCtrlADRq_SG_mVehCtrlADRq
  (SG_mVehCtrlADRq_IDT_E2E* u);

/* Entry point functions */
extern FUNC(void, ScpAp_VechileLongiControl_CODE) ScpAp_VechileLongiControl_Init
  (void);
extern FUNC(void, ScpAp_VechileLongiControl_CODE) VechileLongiControl_Main(void);

#endif
