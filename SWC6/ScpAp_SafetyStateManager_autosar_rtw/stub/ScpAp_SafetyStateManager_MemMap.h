/* This file contains stub implementations of the AUTOSAR RTE functions.
   The stub implementations can be used for testing the generated code in
   Simulink, for example, in SIL/PIL simulations of the component under
   test. Note that this file should be replaced with an appropriate RTE
   file when deploying the generated code outside of Simulink.

   This file is generated for:
   Atomic software component:  "ScpAp_SafetyStateManager"
   ARXML schema: "R20-11"
   File generated on: "Thu Feb 19 12:25:17 2026"  */

#define MEMMAP_ERROR

/* START_SEC Symbols */
#ifdef ScpAp_SafetyStateManager_START_SEC_CODE
#undef ScpAp_SafetyStateManager_START_SEC_CODE
#undef MEMMAP_ERROR
#elif defined( ScpAp_SafetyStateManager_START_SEC_ASW_Variables)
#undef ScpAp_SafetyStateManager_START_SEC_ASW_Variables
#undef MEMMAP_ERROR
#endif

/* STOP_SEC symbols */
#ifdef ScpAp_SafetyStateManager_STOP_SEC_CODE
#undef ScpAp_SafetyStateManager_STOP_SEC_CODE
#undef MEMMAP_ERROR
#elif defined( ScpAp_SafetyStateManager_STOP_SEC_ASW_Variables)
#undef ScpAp_SafetyStateManager_STOP_SEC_ASW_Variables
#undef MEMMAP_ERROR

/* Error out if none of the expected Memory Section keywords are defined */
#ifdef MEMMAP_ERROR
#error "ScpAp_SafetyStateManager_MemMap.h wrong pragma command"
#endif
#endif
