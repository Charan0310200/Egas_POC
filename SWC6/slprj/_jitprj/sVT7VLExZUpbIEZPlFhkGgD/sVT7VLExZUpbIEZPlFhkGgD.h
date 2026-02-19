#pragma once

#ifdef __cplusplus
#define EXTERN_C_CC extern "C"
#else
#define EXTERN_C_CC
#endif

#if defined _WIN32
#define DLL_EXPORT_CC EXTERN_C_CC __declspec(dllexport)
#elif __GNUC__ >= 4
#define DLL_EXPORT_CC EXTERN_C_CC  __attribute__ ((visibility ("default")))
#else
#define DLL_EXPORT_CC EXTERN_C_CC
#endif


/* Custom Headers */
#include "Rte_Type.h"
#include "mwmathutil.h"

/* Type Definitions */
#ifndef typedef_gvar_instance
#define typedef_gvar_instance
typedef struct
{
    uint8_T c3_is_active_c3_ScpAp_SafetyStateManager;
    uint32_T c3_is_c3_ScpAp_SafetyStateManager;
    uint8_T c3_JITStateAnimation[5];
    boolean_T *c3_Accel_Fault;
    boolean_T *c3_SafetyOverspeedFlag;
    boolean_T *c3_MotorRPM_Fault;
    boolean_T *c3_VechSpeedEst_Fault;
    boolean_T *c3_WSS_Fault;
    boolean_T *c3_SafetySpeedMonitorFaultFlag;
    uint8_T *c3_VechSafetyStatus_L2p;
    real32_T *c3_BrkTrqRq;
    real32_T *c3_TrqCmd;
    real32_T *c3_SafeTorquecmd_L2p;
    real_T c3_Torque_Decel_Limit;
    real32_T c3_Brake_Decel_Level;
    real32_T c3_Brake_Limp;
    real32_T c3_Brake_Max_Safe;
    int32_T c3_IsDebuggerActive;
    int32_T c3_IsHeatMapPresent;
    int32_T c3_IsSequenceViewerPresent;
    uint8_T c3_JITTransitionAnimation[7];
    void *c3_RuntimeVar;
    int32_T c3_SequenceViewerOptimization;
    boolean_T c3_dataWrittenToVector[3];
    uint8_T c3_doSetSimStateSideEffects;
    void *c3_fEmlrtCtx;
    uint32_T c3_mlFcnLineNumber;
    const mxArray *c3_setSimStateSideEffectsInfo;
    uint8_T c3_temporalCounter_i1;
} gvar_instance;
#endif /* typedef_gvar_instance */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
DLL_EXPORT_CC void initSimStructsc3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC void initSubchartIOPointersc3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC void initialize_c3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC void initialize_params_c3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC void mdl_start_c3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC void mdl_terminate_c3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC void mdl_setup_runtime_resources_c3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC void mdl_cleanup_runtime_resources_c3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC void enable_c3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC void disable_c3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC void c3_set_sim_state_side_effects_c3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC void sf_gateway_c3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC void ext_mode_exec_c3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC void c3_update_jit_animation_c3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC const mxArray *get_sim_state_c3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC void set_sim_state_c3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c3_st);
DLL_EXPORT_CC const mxArray *c3_sfAfterOrElapsed(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC real32_T c3_emlrt_marshallIn(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c3_nullptr, const char_T *c3_identifier);
DLL_EXPORT_CC real32_T c3_b_emlrt_marshallIn(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
DLL_EXPORT_CC uint8_T c3_c_emlrt_marshallIn(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c3_nullptr, const char_T *c3_identifier);
DLL_EXPORT_CC uint8_T c3_d_emlrt_marshallIn(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
DLL_EXPORT_CC real_T c3_e_emlrt_marshallIn(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c3_nullptr, const char_T *c3_identifier);
DLL_EXPORT_CC real_T c3_f_emlrt_marshallIn(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
DLL_EXPORT_CC uint8_T c3_g_emlrt_marshallIn(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c3_nullptr, const char_T *c3_identifier);
DLL_EXPORT_CC uint8_T c3_h_emlrt_marshallIn(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
DLL_EXPORT_CC uint32_T c3_i_emlrt_marshallIn(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c3_nullptr, const char_T *c3_identifier);
DLL_EXPORT_CC uint32_T c3_j_emlrt_marshallIn(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
DLL_EXPORT_CC void c3_k_emlrt_marshallIn(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c3_nullptr, const char_T *c3_identifier, boolean_T c3_y[3]);
DLL_EXPORT_CC void c3_l_emlrt_marshallIn(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T c3_y[3]);
DLL_EXPORT_CC const mxArray *c3_m_emlrt_marshallIn(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c3_nullptr, const char_T *c3_identifier);
DLL_EXPORT_CC const mxArray *c3_n_emlrt_marshallIn(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
DLL_EXPORT_CC mxArray *getDebuggerHoverDataFor(SimStruct *S, gvar_instance *ptr_gvar_instance, uint32_T c3_b);
DLL_EXPORT_CC void chart_data_browse_helper(SimStruct *S, gvar_instance *ptr_gvar_instance, int32_T c3_ssIdNumber, const mxArray **c3_mxData, uint8_T *c3_isValueBrowsable);
DLL_EXPORT_CC void init_dsm_address_info(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC void init_simulink_io_address(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC void JIT_release_mem_fcn(gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC gvar_instance *JIT_init_mem_fcn(void);

/* Function Definitions */

