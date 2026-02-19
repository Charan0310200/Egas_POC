/* This file contains stub implementations of the AUTOSAR RTE functions.
   The stub implementations can be used for testing the generated code in
   Simulink, for example, in SIL/PIL simulations of the component under
   test. Note that this file should be replaced with an appropriate RTE
   file when deploying the generated code outside of Simulink.

   This file is generated for:
   Atomic software component:  "ScpAp_SafetyStateManager"
   ARXML schema: "R20-11"
   File generated on: "Thu Feb 19 12:25:17 2026"  */

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

/* AUTOSAR Structure Types */
#ifndef DEFINED_TYPEDEF_FOR_IF_SensorFaultFlgs_L2p_IDT_
#define DEFINED_TYPEDEF_FOR_IF_SensorFaultFlgs_L2p_IDT_

typedef struct {
  boolean MotorRPM_Fault;
  boolean Accel_Fault;
  boolean WSS_Fault;
  boolean VechSpeedEst_Fault;
} IF_SensorFaultFlgs_L2p_IDT;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SG_mBrkCtrl_IDT_
#define DEFINED_TYPEDEF_FOR_SG_mBrkCtrl_IDT_

typedef struct {
  boolean Aeb_Active_Ebcm;
  boolean BrkEnbl_EBCM2L;
  float32 BrkTrqRq;
  boolean ClearFltRq_Ebcm;
  boolean DsblTCS;
  boolean EbcmMaintModeRq;
  boolean EbcmShtdwnRq;
  boolean EpbCalCmd;
  uint8 EPBCmd;
  boolean HoldRq;
  uint8 MsgCntr_mBrkCtrl;
  uint8 MsgCrc_mBrkCtrl;
} SG_mBrkCtrl_IDT;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SG_mWhdCtrl_IDT_
#define DEFINED_TYPEDEF_FOR_SG_mWhdCtrl_IDT_

typedef struct {
  boolean Boot;
  uint8 CtrlMode_Whd;
  boolean Debug;
  boolean EnblCmd;
  uint8 MsgCntr_mWhdCtrl;
  uint8 MsgCrc_mWhdCtrl;
  uint8 MtrMode;
  float32 SpdCmd;
  float32 SpdSlewLmt;
  float32 TrqCmd;
  float32 TrqSlewLmt;
} SG_mWhdCtrl_IDT;

#endif

typedef void* Rte_Instance;

#endif
