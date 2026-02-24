/* This file contains stub implementations of the AUTOSAR RTE functions.
   The stub implementations can be used for testing the generated code in
   Simulink, for example, in SIL/PIL simulations of the component under
   test. Note that this file should be replaced with an appropriate RTE
   file when deploying the generated code outside of Simulink.

   This file is generated for:
   Atomic software component:  "ScpAp_L1SpeedMonitor"
   ARXML schema: "R23-11"
   File generated on: "Tue Feb 10 15:17:32 2026"  */

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
typedef uint16 uint16_const;

/* AUTOSAR Structure Types */
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

#ifndef DEFINED_TYPEDEF_FOR_SG_mEbcm2L_WhlSpd_IDT_E2E_
#define DEFINED_TYPEDEF_FOR_SG_mEbcm2L_WhlSpd_IDT_E2E_

typedef struct {
  uint8 MsgCntr_mEbcm2L_WhlSpd;
  uint8 MsgCrc_mEbcm2L_WhlSpd;
  float32 WhlSpdFL;
  float32 WhlSpdFR;
  float32 WhlSpdR;
  uint8 CanVm7FFltCod;
} SG_mEbcm2L_WhlSpd_IDT_E2E;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SG_mVcuImuLinAccel_IDT_
#define DEFINED_TYPEDEF_FOR_SG_mVcuImuLinAccel_IDT_

typedef struct {
  uint8 MsgCntr_ImuLin;
  uint8 MsgCrc_ImuLin;
  float32 X_Accel;
  float32 Y_Accel;
  float32 Z_Accel;
} SG_mVcuImuLinAccel_IDT;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SG_mWhdStat_IDT_E2E_
#define DEFINED_TYPEDEF_FOR_SG_mWhdStat_IDT_E2E_

typedef struct {
  boolean HwEnblStat;
  uint8 MsgCntr_mWhdStat;
  uint8 MsgCrc_mWhdStat;
  float32 MtrSpd;
  float32 MtrTrqEst;
  float32 MvCurrEst;
  float32 MvVolt;
  boolean TrqEnblStat;
  uint8 CanVm64FltCod;
} SG_mWhdStat_IDT_E2E;

#endif

typedef void* Rte_Instance;

#endif
