/* This file contains stub implementations of the AUTOSAR RTE functions.
   The stub implementations can be used for testing the generated code in
   Simulink, for example, in SIL/PIL simulations of the component under
   test. Note that this file should be replaced with an appropriate RTE
   file when deploying the generated code outside of Simulink.

   This file is generated for:
   Atomic software component:  "ScpAp_VechileLongiControl"
   ARXML schema: "R20-11"
   File generated on: "Mon Feb 23 14:17:27 2026"  */

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

/* AUTOSAR Structure Types */
#ifndef DEFINED_TYPEDEF_FOR_SG_mVehCtrlADRq_IDT_E2E_
#define DEFINED_TYPEDEF_FOR_SG_mVehCtrlADRq_IDT_E2E_

typedef struct {
  boolean AebEvent;
  uint8 AebSrcAD;
  boolean b_High_Deceleration_Flag;
  uint8 MsgCntrmVehCtrlADRq;
  uint8 MsgCrc_mVehCtrlADRq;
  float32 VehAccelLongCmd;
  uint8 VehDirCmd;
  float32 VehRoadWhlAngleCmd;
  float32 VehSpdCmd;
  uint8 CanAd78FltCod;
} SG_mVehCtrlADRq_IDT_E2E;

#endif

typedef void* Rte_Instance;

#endif
