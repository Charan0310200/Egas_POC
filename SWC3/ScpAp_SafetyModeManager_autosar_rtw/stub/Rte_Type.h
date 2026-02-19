/* This file contains stub implementations of the AUTOSAR RTE functions.
   The stub implementations can be used for testing the generated code in
   Simulink, for example, in SIL/PIL simulations of the component under
   test. Note that this file should be replaced with an appropriate RTE
   file when deploying the generated code outside of Simulink.

   This file is generated for:
   Atomic software component:  "ScpAp_SafetyModeManager"
   ARXML schema: "R20-11"
   File generated on: "Tue Feb 17 17:07:32 2026"  */

#ifndef Rte_Type_h
#define Rte_Type_h
#include "Std_Types.h"

/* AUTOSAR RTE Status Types */
#ifndef RTE_E_OK
#define RTE_E_OK                       (0x00)
#endif

#ifndef RTE_E_LOST_DATA
#define RTE_E_LOST_DATA                (0x40)
#endif

#ifndef RTE_E_LIMIT
#define RTE_E_LIMIT                    (0x82)
#endif

#ifndef E2E_E_OK
#define E2E_E_OK                       (0x00)
#endif

#ifndef E2EPW_STATUS_OK
#define E2EPW_STATUS_OK                (0x00)
#endif

#ifndef E2EPW_STATUS_OKSOMELOST
#define E2EPW_STATUS_OKSOMELOST        (0x20)
#endif

/* AUTOSAR Implementation data types, specific to software component */
/* AUTOSAR Enumeration Types */
typedef uint8 SafetyMode_L2p_IDT;

#ifndef AUTONOMOUS
#define AUTONOMOUS                     (1)
#endif

#ifndef MANUAL
#define MANUAL                         (0)
#endif

#ifndef TELEOPS
#define TELEOPS                        (3)
#endif

typedef uint8 VechSafetyStatus_L2p_IDT;

#ifndef NORMAL
#define NORMAL                         (0)
#endif

#ifndef DEGRADED
#define DEGRADED                       (1)
#endif

#ifndef FAULT_STOP
#define FAULT_STOP                     (2)
#endif

#ifndef OVERSPEED_HANDLING
#define OVERSPEED_HANDLING             (3)
#endif

typedef void* Rte_Instance;

#endif
