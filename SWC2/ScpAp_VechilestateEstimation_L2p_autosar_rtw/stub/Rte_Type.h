/* This file contains stub implementations of the AUTOSAR RTE functions.
   The stub implementations can be used for testing the generated code in
   Simulink, for example, in SIL/PIL simulations of the component under
   test. Note that this file should be replaced with an appropriate RTE
   file when deploying the generated code outside of Simulink.

   This file is generated for:
   Atomic software component:  "ScpAp_VechilestateEstimation_L2p"
   ARXML schema: "R23-11"
   File generated on: "Tue Feb 10 13:11:22 2026"  */

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
typedef float64 float64_const;
typedef sint16 sint16_const;

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

#ifndef DEFINED_TYPEDEF_FOR_IF_ValidityFlag_L1p_IDT_
#define DEFINED_TYPEDEF_FOR_IF_ValidityFlag_L1p_IDT_

typedef struct {
  boolean Motor_RPM_Valid_Flg;
  boolean WSS_FR_Valid_Flg;
  boolean WSS_FL_Valid_Flg;
  boolean WSS_R_Valid_Flg;
  boolean IMU_AccelX_Valid_Flg;
  boolean SensorStuck_Valid_Flg;
} IF_ValidityFlag_L1p_IDT;

#endif

typedef void* Rte_Instance;

#endif
