#define S_FUNCTION_NAME sf_sfun
#include "covrt.h"
#include "cgxert.h"
#include "emlrt.h"
#include "sfrtif/sfc_sf.h"
#include "sfrtif/MessageServiceLayer.h"
#include "sfrtif/DebuggerRuntimeInterface.h"
#include "sfrtif/sfc_mex.h"
#include "sfrtif/sf_runtime_errors.h"
#include "sfrtif/sf_partitioning_execution_bridge.h"
#include "rtwtypes.h"
#include "simtarget/slSimTgtClientServerAPIBridge.h"
#include "sfrtif/sfc_sdi.h"
#include "sfrtif/sf_test_language.h"
#include "simlogCIntrf.h"
#include "half_type.h"
#include "multiword_types.h"
#include "sfrtif/sfc_messages.h"
#include "slccrt.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"
#include "mwstringutil.h"
#include "blas.h"
#include "lapacke.h"
#include "sNrVzTk7uaUhl4OhNnCSwi.h"

#define rtInf (mxGetInf())
#define rtMinusInf (-(mxGetInf()))
#define rtNaN (mxGetNaN())
#define rtInfF ((real32_T)mxGetInf())
#define rtMinusInfF (-(real32_T)mxGetInf())
#define rtNaNF ((real32_T)mxGetNaN())
#define rtIsNaN(X) ((int)mxIsNaN(X))
#define rtIsInf(X) ((int)mxIsInf(X))
#ifdef utFree
#undef utFree
#endif
#ifdef utMalloc
#undef utMalloc
#endif
#ifdef __cplusplus
extern "C" void* utMalloc(size_t size);
extern "C" void utFree(void*);
#else
extern void* utMalloc(size_t size);
extern void utFree(void*);
#endif


/* Type Definitions */

/* Named Constants */
#define c3_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define c3_IN_NO_ACTIVE_LEAF ((uint8_T)0U)
#define CALL_EVENT (-1)
#define c3_IN_Degrade (1U)
#define c3_IN_Energency_Stop (2U)
#define c3_IN_Normal (3U)
#define c3_IN_OverSpeed_Handling (4U)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
void initSimStructsc3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    (void)S;
    (void)ptr_gvar_instance;
}

void initSubchartIOPointersc3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    (void)S;
    (void)ptr_gvar_instance;
}

void initialize_c3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    sf_is_first_init_cond(S);
    sim_mode_is_external(S);
    ptr_gvar_instance->c3_doSetSimStateSideEffects = 0U;
    ptr_gvar_instance->c3_setSimStateSideEffectsInfo = NULL;
    ptr_gvar_instance->c3_temporalCounter_i1 = 0U;
    sf_get_time(S);
    if (sf_get_output_port_reusable(S, 1) == 0) {
        *ptr_gvar_instance->c3_BrkTrqRq = 0.0F;
    }
    if (sf_get_output_port_reusable(S, 2) == 0) {
        *ptr_gvar_instance->c3_TrqCmd = 0.0F;
    }
    ptr_gvar_instance->c3_Brake_Decel_Level = 500.0F;
    ptr_gvar_instance->c3_Brake_Limp = 600.0F;
    ptr_gvar_instance->c3_Brake_Max_Safe = 800.0F;
    ptr_gvar_instance->c3_Torque_Decel_Limit = 500.0F;
    if (sf_get_output_port_reusable(S, 3) == 0) {
        *ptr_gvar_instance->c3_VechSafetyStatus_L2p = NORMAL;
    }
    ptr_gvar_instance->c3_is_active_c3_ScpAp_SafetyStateManager = 0U;
    ptr_gvar_instance->c3_is_c3_ScpAp_SafetyStateManager = (uint32_T)c3_IN_NO_ACTIVE_CHILD;
}

void initialize_params_c3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    (void)S;
    (void)ptr_gvar_instance;
}

void mdl_start_c3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    (void)ptr_gvar_instance;
    sim_mode_is_external(S);
}

void mdl_terminate_c3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    (void)S;
    (void)ptr_gvar_instance;
}

void mdl_setup_runtime_resources_c3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    setDataBrowseFcn(S, (void *)&chart_data_browse_helper);
    ptr_gvar_instance->c3_RuntimeVar = sfListenerCacheSimStruct(S);
    sfListenerInitializeRuntimeVars(ptr_gvar_instance->c3_RuntimeVar, &ptr_gvar_instance->c3_IsDebuggerActive, &ptr_gvar_instance->c3_IsSequenceViewerPresent, 0, 0, &ptr_gvar_instance->c3_mlFcnLineNumber, &ptr_gvar_instance->c3_IsHeatMapPresent, 0);
    sfSetAnimationVectors(S, &ptr_gvar_instance->c3_JITStateAnimation[0], &ptr_gvar_instance->c3_JITTransitionAnimation[0]);
}

void mdl_cleanup_runtime_resources_c3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    (void)S;
    sfListenerLightTerminate(ptr_gvar_instance->c3_RuntimeVar);
    sf_mex_destroy(&ptr_gvar_instance->c3_setSimStateSideEffectsInfo);
}

void enable_c3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    (void)ptr_gvar_instance;
    sf_get_time(S);
    sf_call_output_fcn_enable(S, 0, (const char_T *)"Minimum", 0);
}

void disable_c3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    (void)ptr_gvar_instance;
    sf_get_time(S);
    sf_call_output_fcn_disable(S, 0, (const char_T *)"Minimum", 0);
}

void c3_set_sim_state_side_effects_c3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    (void)S;
    if ((int32_T)ptr_gvar_instance->c3_doSetSimStateSideEffects != 0) {
        if ((ptr_gvar_instance->c3_is_c3_ScpAp_SafetyStateManager == c3_IN_Degrade) && (sf_mex_sub(ptr_gvar_instance->c3_setSimStateSideEffectsInfo, "setSimStateSideEffectsInfo", 1U, 2U) == 0.0)) {
            ptr_gvar_instance->c3_temporalCounter_i1 = 0U;
        }
        ptr_gvar_instance->c3_doSetSimStateSideEffects = 0U;
    }
}

void sf_gateway_c3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    c3_set_sim_state_side_effects_c3_ScpAp_SafetyStateManager(S, ptr_gvar_instance);
    sf_get_time(S);
    if ((int32_T)ptr_gvar_instance->c3_temporalCounter_i1 < 31) {
        ptr_gvar_instance->c3_temporalCounter_i1 = (uint8_T)((int32_T)ptr_gvar_instance->c3_temporalCounter_i1 + 1);
    }
    ptr_gvar_instance->c3_JITTransitionAnimation[0] = 0U;
    ptr_gvar_instance->c3_JITTransitionAnimation[1] = 0U;
    ptr_gvar_instance->c3_JITTransitionAnimation[2] = 0U;
    ptr_gvar_instance->c3_JITTransitionAnimation[3] = 0U;
    ptr_gvar_instance->c3_JITTransitionAnimation[4] = 0U;
    ptr_gvar_instance->c3_JITTransitionAnimation[5] = 0U;
    ptr_gvar_instance->c3_JITTransitionAnimation[6] = 0U;
    if ((int32_T)ptr_gvar_instance->c3_is_active_c3_ScpAp_SafetyStateManager == 0) {
        ptr_gvar_instance->c3_is_active_c3_ScpAp_SafetyStateManager = 1U;
        ptr_gvar_instance->c3_JITTransitionAnimation[0U] = 1U;
        ptr_gvar_instance->c3_is_c3_ScpAp_SafetyStateManager = c3_IN_Normal;
        *ptr_gvar_instance->c3_TrqCmd = *ptr_gvar_instance->c3_SafeTorquecmd_L2p;
        ptr_gvar_instance->c3_dataWrittenToVector[1U] = true;
        *ptr_gvar_instance->c3_BrkTrqRq = 0.0F;
        ptr_gvar_instance->c3_dataWrittenToVector[0U] = true;
    } else {
        switch (ptr_gvar_instance->c3_is_c3_ScpAp_SafetyStateManager) {
          case c3_IN_Degrade:
            sf_temporal_value_range_check_min(S, 20U, 25.0, 0.0);
            if ((int32_T)ptr_gvar_instance->c3_temporalCounter_i1 >= 25) {
                ptr_gvar_instance->c3_JITTransitionAnimation[5U] = 1U;
                ptr_gvar_instance->c3_is_c3_ScpAp_SafetyStateManager = c3_IN_Energency_Stop;
                *ptr_gvar_instance->c3_TrqCmd = 0.0F;
                ptr_gvar_instance->c3_dataWrittenToVector[1U] = true;
                *ptr_gvar_instance->c3_BrkTrqRq = ptr_gvar_instance->c3_Brake_Max_Safe;
                ptr_gvar_instance->c3_dataWrittenToVector[0U] = true;
            } else if ((!*ptr_gvar_instance->c3_SafetySpeedMonitorFaultFlag) || (!*ptr_gvar_instance->c3_SafetyOverspeedFlag) || ((!*ptr_gvar_instance->c3_Accel_Fault) && (!*ptr_gvar_instance->c3_MotorRPM_Fault) && (!*ptr_gvar_instance->c3_WSS_Fault) && (!*ptr_gvar_instance->c3_VechSpeedEst_Fault))) {
                ptr_gvar_instance->c3_JITTransitionAnimation[6U] = 1U;
                ptr_gvar_instance->c3_is_c3_ScpAp_SafetyStateManager = c3_IN_Normal;
                *ptr_gvar_instance->c3_TrqCmd = *ptr_gvar_instance->c3_SafeTorquecmd_L2p;
                ptr_gvar_instance->c3_dataWrittenToVector[1U] = true;
                *ptr_gvar_instance->c3_BrkTrqRq = 0.0F;
                ptr_gvar_instance->c3_dataWrittenToVector[0U] = true;
            }
            break;
          case c3_IN_Energency_Stop:
            break;
          case c3_IN_Normal:
            if (*ptr_gvar_instance->c3_SafetyOverspeedFlag) {
                ptr_gvar_instance->c3_JITTransitionAnimation[1U] = 1U;
                ptr_gvar_instance->c3_is_c3_ScpAp_SafetyStateManager = c3_IN_OverSpeed_Handling;
                *ptr_gvar_instance->c3_In1 = *ptr_gvar_instance->c3_SafeTorquecmd_L2p;
                *ptr_gvar_instance->c3_In2 = ptr_gvar_instance->c3_Torque_Decel_Limit;
                sf_call_output_fcn_call(S, 0, (const char_T *)"Minimum", 0);
                *ptr_gvar_instance->c3_TrqCmd = *ptr_gvar_instance->c3_Out1;
                ptr_gvar_instance->c3_dataWrittenToVector[3U] = true;
                ptr_gvar_instance->c3_dataWrittenToVector[1U] = true;
                *ptr_gvar_instance->c3_BrkTrqRq = ptr_gvar_instance->c3_Brake_Decel_Level;
                ptr_gvar_instance->c3_dataWrittenToVector[0U] = true;
            } else if ((*ptr_gvar_instance->c3_SafetySpeedMonitorFaultFlag) || ((*ptr_gvar_instance->c3_Accel_Fault) && (*ptr_gvar_instance->c3_MotorRPM_Fault) && (*ptr_gvar_instance->c3_WSS_Fault) && (*ptr_gvar_instance->c3_VechSpeedEst_Fault))) {
                ptr_gvar_instance->c3_JITTransitionAnimation[3U] = 1U;
                ptr_gvar_instance->c3_temporalCounter_i1 = 0U;
                ptr_gvar_instance->c3_is_c3_ScpAp_SafetyStateManager = c3_IN_Degrade;
                *ptr_gvar_instance->c3_TrqCmd = 0.0F;
                ptr_gvar_instance->c3_dataWrittenToVector[1U] = true;
                *ptr_gvar_instance->c3_BrkTrqRq = ptr_gvar_instance->c3_Brake_Limp;
                ptr_gvar_instance->c3_dataWrittenToVector[0U] = true;
            } else {
                *ptr_gvar_instance->c3_VechSafetyStatus_L2p = NORMAL;
                ptr_gvar_instance->c3_dataWrittenToVector[2U] = true;
            }
            break;
          case c3_IN_OverSpeed_Handling:
            if ((!*ptr_gvar_instance->c3_SafetyOverspeedFlag) || ((!*ptr_gvar_instance->c3_Accel_Fault) && (!*ptr_gvar_instance->c3_MotorRPM_Fault) && (!*ptr_gvar_instance->c3_WSS_Fault) && (!*ptr_gvar_instance->c3_VechSpeedEst_Fault))) {
                ptr_gvar_instance->c3_JITTransitionAnimation[2U] = 1U;
                ptr_gvar_instance->c3_is_c3_ScpAp_SafetyStateManager = c3_IN_Normal;
                *ptr_gvar_instance->c3_TrqCmd = *ptr_gvar_instance->c3_SafeTorquecmd_L2p;
                ptr_gvar_instance->c3_dataWrittenToVector[1U] = true;
                *ptr_gvar_instance->c3_BrkTrqRq = 0.0F;
                ptr_gvar_instance->c3_dataWrittenToVector[0U] = true;
            } else if ((*ptr_gvar_instance->c3_SafetySpeedMonitorFaultFlag) || ((*ptr_gvar_instance->c3_Accel_Fault) && (*ptr_gvar_instance->c3_MotorRPM_Fault) && (*ptr_gvar_instance->c3_WSS_Fault) && (*ptr_gvar_instance->c3_VechSpeedEst_Fault))) {
                ptr_gvar_instance->c3_JITTransitionAnimation[4U] = 1U;
                ptr_gvar_instance->c3_temporalCounter_i1 = 0U;
                ptr_gvar_instance->c3_is_c3_ScpAp_SafetyStateManager = c3_IN_Degrade;
                *ptr_gvar_instance->c3_TrqCmd = 0.0F;
                ptr_gvar_instance->c3_dataWrittenToVector[1U] = true;
                *ptr_gvar_instance->c3_BrkTrqRq = ptr_gvar_instance->c3_Brake_Limp;
                ptr_gvar_instance->c3_dataWrittenToVector[0U] = true;
            }
            break;
          default:
            /* Unreachable state, for coverage only */
            ptr_gvar_instance->c3_is_c3_ScpAp_SafetyStateManager = (uint32_T)c3_IN_NO_ACTIVE_CHILD;
            break;
        }
    }
    c3_update_jit_animation_c3_ScpAp_SafetyStateManager(S, ptr_gvar_instance);
}

void ext_mode_exec_c3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    (void)S;
    (void)ptr_gvar_instance;
}

void c3_update_jit_animation_c3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    (void)S;
    ptr_gvar_instance->c3_JITStateAnimation[0U] = (uint8_T)(ptr_gvar_instance->c3_is_c3_ScpAp_SafetyStateManager == c3_IN_Normal);
    ptr_gvar_instance->c3_JITStateAnimation[1U] = (uint8_T)(ptr_gvar_instance->c3_is_c3_ScpAp_SafetyStateManager == c3_IN_OverSpeed_Handling);
    ptr_gvar_instance->c3_JITStateAnimation[2U] = (uint8_T)(ptr_gvar_instance->c3_is_c3_ScpAp_SafetyStateManager == c3_IN_Degrade);
    ptr_gvar_instance->c3_JITStateAnimation[3U] = (uint8_T)(ptr_gvar_instance->c3_is_c3_ScpAp_SafetyStateManager == c3_IN_Energency_Stop);
}

const mxArray *get_sim_state_c3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    static const int32_T c3_enumValues[4] = { 0, 1, 2, 3 };
    static const char_T *c3_enumNames[4] = { "NORMAL", "DEGRADED", "FAULT_STOP", "OVERSPEED_HANDLING" };
    const mxArray *c3_b = NULL;
    const mxArray *c3_b_y = NULL;
    const mxArray *c3_c_y = NULL;
    const mxArray *c3_d_y = NULL;
    const mxArray *c3_e_y = NULL;
    const mxArray *c3_f_y = NULL;
    const mxArray *c3_g_y = NULL;
    const mxArray *c3_h_y = NULL;
    const mxArray *c3_i_y = NULL;
    const mxArray *c3_j_y = NULL;
    const mxArray *c3_k_y = NULL;
    const mxArray *c3_l_y = NULL;
    const mxArray *c3_m_y = NULL;
    const mxArray *c3_st;
    const mxArray *c3_y = NULL;
    uint8_T c3_u;
    (void)S;
    c3_st = NULL;
    c3_st = NULL;
    c3_y = NULL;
    sf_mex_assign(&c3_y, sf_mex_createcellmatrix(11, 1), false);
    c3_b_y = NULL;
    sf_mex_assign(&c3_b_y, sf_mex_create("y", ptr_gvar_instance->c3_BrkTrqRq, 1, 0U, 0, 0U, 0), false);
    sf_mex_setcell(c3_y, 0, c3_b_y);
    c3_c_y = NULL;
    sf_mex_assign(&c3_c_y, sf_mex_create("y", ptr_gvar_instance->c3_TrqCmd, 1, 0U, 0, 0U, 0), false);
    sf_mex_setcell(c3_y, 1, c3_c_y);
    c3_d_y = NULL;
    sf_mex_check_enum("VechSafetyStatus_L2p_IDT", 4, &c3_enumNames[0], &c3_enumValues[0]);
    c3_u = (uint8_T)(int32_T)*ptr_gvar_instance->c3_VechSafetyStatus_L2p;
    c3_m_y = NULL;
    sf_mex_assign(&c3_m_y, sf_mex_create("y", &c3_u, 3, 0U, 0, 0U, 0), false);
    sf_mex_assign(&c3_b, c3_m_y, false);
    sf_mex_assign(&c3_d_y, sf_mex_create_enum("VechSafetyStatus_L2p_IDT", c3_b), false);
    sf_mex_destroy(&c3_b);
    sf_mex_setcell(c3_y, 2, c3_d_y);
    c3_e_y = NULL;
    sf_mex_assign(&c3_e_y, sf_mex_create("y", &ptr_gvar_instance->c3_Brake_Decel_Level, 1, 0U, 0, 0U, 0), false);
    sf_mex_setcell(c3_y, 3, c3_e_y);
    c3_f_y = NULL;
    sf_mex_assign(&c3_f_y, sf_mex_create("y", &ptr_gvar_instance->c3_Brake_Limp, 1, 0U, 0, 0U, 0), false);
    sf_mex_setcell(c3_y, 4, c3_f_y);
    c3_g_y = NULL;
    sf_mex_assign(&c3_g_y, sf_mex_create("y", &ptr_gvar_instance->c3_Brake_Max_Safe, 1, 0U, 0, 0U, 0), false);
    sf_mex_setcell(c3_y, 5, c3_g_y);
    c3_h_y = NULL;
    sf_mex_assign(&c3_h_y, sf_mex_create("y", &ptr_gvar_instance->c3_Torque_Decel_Limit, 1, 0U, 0, 0U, 0), false);
    sf_mex_setcell(c3_y, 6, c3_h_y);
    c3_i_y = NULL;
    sf_mex_assign(&c3_i_y, sf_mex_create("y", &ptr_gvar_instance->c3_is_active_c3_ScpAp_SafetyStateManager, 3, 0U, 0, 0U, 0), false);
    sf_mex_setcell(c3_y, 7, c3_i_y);
    c3_j_y = NULL;
    sf_mex_assign(&c3_j_y, sf_mex_create("y", &ptr_gvar_instance->c3_is_c3_ScpAp_SafetyStateManager, 7, 0U, 0, 0U, 0), false);
    sf_mex_setcell(c3_y, 8, c3_j_y);
    c3_k_y = NULL;
    sf_mex_assign(&c3_k_y, sf_mex_create("y", &ptr_gvar_instance->c3_temporalCounter_i1, 3, 0U, 0, 0U, 0), false);
    sf_mex_setcell(c3_y, 9, c3_k_y);
    c3_l_y = NULL;
    sf_mex_assign(&c3_l_y, sf_mex_create("y", ptr_gvar_instance->c3_dataWrittenToVector, 11, 0U, 1, 0U, 1, 4), false);
    sf_mex_setcell(c3_y, 10, c3_l_y);
    sf_mex_assign(&c3_st, c3_y, false);
    return c3_st;
}

void set_sim_state_c3_ScpAp_SafetyStateManager(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c3_st)
{
    const mxArray *c3_u;
    c3_u = sf_mex_dup(c3_st);
    *ptr_gvar_instance->c3_BrkTrqRq = c3_emlrt_marshallIn(S, ptr_gvar_instance, sf_mex_dup(sf_mex_getcell(c3_u, 0)), "BrkTrqRq");
    *ptr_gvar_instance->c3_TrqCmd = c3_emlrt_marshallIn(S, ptr_gvar_instance, sf_mex_dup(sf_mex_getcell(c3_u, 1)), "TrqCmd");
    *ptr_gvar_instance->c3_VechSafetyStatus_L2p = c3_c_emlrt_marshallIn(S, ptr_gvar_instance, sf_mex_dup(sf_mex_getcell(c3_u, 2)), "VechSafetyStatus_L2p");
    ptr_gvar_instance->c3_Brake_Decel_Level = c3_emlrt_marshallIn(S, ptr_gvar_instance, sf_mex_dup(sf_mex_getcell(c3_u, 3)), "Brake_Decel_Level");
    ptr_gvar_instance->c3_Brake_Limp = c3_emlrt_marshallIn(S, ptr_gvar_instance, sf_mex_dup(sf_mex_getcell(c3_u, 4)), "Brake_Limp");
    ptr_gvar_instance->c3_Brake_Max_Safe = c3_emlrt_marshallIn(S, ptr_gvar_instance, sf_mex_dup(sf_mex_getcell(c3_u, 5)), "Brake_Max_Safe");
    ptr_gvar_instance->c3_Torque_Decel_Limit = c3_emlrt_marshallIn(S, ptr_gvar_instance, sf_mex_dup(sf_mex_getcell(c3_u, 6)), "Torque_Decel_Limit");
    ptr_gvar_instance->c3_is_active_c3_ScpAp_SafetyStateManager = c3_e_emlrt_marshallIn(S, ptr_gvar_instance, sf_mex_dup(sf_mex_getcell(c3_u, 7)), "is_active_c3_ScpAp_SafetyStateManager");
    ptr_gvar_instance->c3_is_c3_ScpAp_SafetyStateManager = c3_g_emlrt_marshallIn(S, ptr_gvar_instance, sf_mex_dup(sf_mex_getcell(c3_u, 8)), "is_c3_ScpAp_SafetyStateManager");
    ptr_gvar_instance->c3_temporalCounter_i1 = c3_e_emlrt_marshallIn(S, ptr_gvar_instance, sf_mex_dup(sf_mex_getcell(c3_u, 9)), "temporalCounter_i1");
    c3_i_emlrt_marshallIn(S, ptr_gvar_instance, sf_mex_dup(sf_mex_getcell(c3_u, 10)), "dataWrittenToVector", ptr_gvar_instance->c3_dataWrittenToVector);
    sf_mex_assign(&ptr_gvar_instance->c3_setSimStateSideEffectsInfo, c3_k_emlrt_marshallIn(S, ptr_gvar_instance, sf_mex_dup(sf_mex_getcell(c3_u, 11)), "setSimStateSideEffectsInfo"), true);
    sf_mex_destroy(&c3_u);
    ptr_gvar_instance->c3_doSetSimStateSideEffects = 1U;
    c3_update_jit_animation_c3_ScpAp_SafetyStateManager(S, ptr_gvar_instance);
    sf_mex_destroy(&c3_st);
}

const mxArray *c3_sfAfterOrElapsed(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    const mxArray *c3_b = NULL;
    real_T c3_c;
    (void)S;
    c3_b = NULL;
    if (ptr_gvar_instance->c3_is_c3_ScpAp_SafetyStateManager == c3_IN_Degrade) {
        c3_c = 0.02 * (real_T)ptr_gvar_instance->c3_temporalCounter_i1;
        sf_mex_assign(&c3_b, sf_mex_create("unnamed temp", &c3_c, 0, 0U, 0, 0U, 0), false);
    } else {
        c3_c = -1.0;
        sf_mex_assign(&c3_b, sf_mex_create("unnamed temp", &c3_c, 0, 0U, 0, 0U, 0), false);
    }
    return c3_b;
}

real32_T c3_emlrt_marshallIn(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c3_nullptr, const char_T *c3_identifier)
{
    emlrtMsgIdentifier c3_thisId;
    real32_T c3_y;
    c3_thisId.fIdentifier = (const char_T *)c3_identifier;
    c3_thisId.fParent = NULL;
    c3_thisId.bParentIsCell = false;
    c3_y = c3_b_emlrt_marshallIn(S, ptr_gvar_instance, sf_mex_dup(c3_nullptr), &c3_thisId);
    sf_mex_destroy(&c3_nullptr);
    return c3_y;
}

real32_T c3_b_emlrt_marshallIn(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
    real32_T c3_b;
    real32_T c3_y;
    (void)S;
    (void)ptr_gvar_instance;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b, 0, 1, 0U, 0, 0U, 0);
    c3_y = c3_b;
    sf_mex_destroy(&c3_u);
    return c3_y;
}

uint8_T c3_c_emlrt_marshallIn(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c3_nullptr, const char_T *c3_identifier)
{
    emlrtMsgIdentifier c3_thisId;
    uint8_T c3_y;
    c3_thisId.fIdentifier = (const char_T *)c3_identifier;
    c3_thisId.fParent = NULL;
    c3_thisId.bParentIsCell = false;
    c3_y = c3_d_emlrt_marshallIn(S, ptr_gvar_instance, sf_mex_dup(c3_nullptr), &c3_thisId);
    sf_mex_destroy(&c3_nullptr);
    return c3_y;
}

uint8_T c3_d_emlrt_marshallIn(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
    static const int32_T c3_enumValues[4] = { 0, 1, 2, 3 };
    static const char_T *c3_enumNames[4] = { "NORMAL", "DEGRADED", "FAULT_STOP", "OVERSPEED_HANDLING" };
    uint8_T c3_y;
    (void)S;
    (void)ptr_gvar_instance;
    sf_mex_check_enum("VechSafetyStatus_L2p_IDT", 4, &c3_enumNames[0], &c3_enumValues[0]);
    sf_mex_check_builtin(c3_parentId, c3_u, "VechSafetyStatus_L2p_IDT", 0U, 0U, NULL);
    c3_y = (uint8_T)sf_mex_get_enum_element(c3_u, 0);
    sf_mex_destroy(&c3_u);
    return c3_y;
}

uint8_T c3_e_emlrt_marshallIn(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c3_nullptr, const char_T *c3_identifier)
{
    emlrtMsgIdentifier c3_thisId;
    uint8_T c3_y;
    c3_thisId.fIdentifier = (const char_T *)c3_identifier;
    c3_thisId.fParent = NULL;
    c3_thisId.bParentIsCell = false;
    c3_y = c3_f_emlrt_marshallIn(S, ptr_gvar_instance, sf_mex_dup(c3_nullptr), &c3_thisId);
    sf_mex_destroy(&c3_nullptr);
    return c3_y;
}

uint8_T c3_f_emlrt_marshallIn(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
    uint8_T c3_b;
    uint8_T c3_y;
    (void)S;
    (void)ptr_gvar_instance;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b, 1, 3, 0U, 0, 0U, 0);
    c3_y = c3_b;
    sf_mex_destroy(&c3_u);
    return c3_y;
}

uint32_T c3_g_emlrt_marshallIn(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c3_nullptr, const char_T *c3_identifier)
{
    emlrtMsgIdentifier c3_thisId;
    uint32_T c3_y;
    c3_thisId.fIdentifier = (const char_T *)c3_identifier;
    c3_thisId.fParent = NULL;
    c3_thisId.bParentIsCell = false;
    c3_y = c3_h_emlrt_marshallIn(S, ptr_gvar_instance, sf_mex_dup(c3_nullptr), &c3_thisId);
    sf_mex_destroy(&c3_nullptr);
    return c3_y;
}

uint32_T c3_h_emlrt_marshallIn(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
    uint32_T c3_b;
    uint32_T c3_y;
    (void)S;
    (void)ptr_gvar_instance;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b, 1, 7, 0U, 0, 0U, 0);
    c3_y = c3_b;
    sf_mex_destroy(&c3_u);
    return c3_y;
}

void c3_i_emlrt_marshallIn(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c3_nullptr, const char_T *c3_identifier, boolean_T c3_y[4])
{
    emlrtMsgIdentifier c3_thisId;
    c3_thisId.fIdentifier = (const char_T *)c3_identifier;
    c3_thisId.fParent = NULL;
    c3_thisId.bParentIsCell = false;
    c3_j_emlrt_marshallIn(S, ptr_gvar_instance, sf_mex_dup(c3_nullptr), &c3_thisId, c3_y);
    sf_mex_destroy(&c3_nullptr);
}

void c3_j_emlrt_marshallIn(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T c3_y[4])
{
    int32_T c3_c;
    boolean_T c3_b[4];
    (void)S;
    (void)ptr_gvar_instance;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_b, 1, 11, 0U, 1, 0U, 1, 4);
    for (c3_c = 0; c3_c < 4; c3_c++) {
        c3_y[c3_c] = c3_b[c3_c];
    }
    sf_mex_destroy(&c3_u);
}

const mxArray *c3_k_emlrt_marshallIn(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c3_nullptr, const char_T *c3_identifier)
{
    emlrtMsgIdentifier c3_thisId;
    const mxArray *c3_y = NULL;
    c3_y = NULL;
    c3_thisId.fIdentifier = (const char_T *)c3_identifier;
    c3_thisId.fParent = NULL;
    c3_thisId.bParentIsCell = false;
    sf_mex_assign(&c3_y, c3_l_emlrt_marshallIn(S, ptr_gvar_instance, sf_mex_dup(c3_nullptr), &c3_thisId), true);
    sf_mex_destroy(&c3_nullptr);
    return c3_y;
}

const mxArray *c3_l_emlrt_marshallIn(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
    const mxArray *c3_y = NULL;
    (void)S;
    (void)ptr_gvar_instance;
    (void)c3_parentId;
    c3_y = NULL;
    sf_mex_assign(&c3_y, sf_mex_duplicatearraysafe(&c3_u), true);
    sf_mex_destroy(&c3_u);
    return c3_y;
}

mxArray *getDebuggerHoverDataFor(SimStruct *S, gvar_instance *ptr_gvar_instance, uint32_T c3_b)
{
    const mxArray *c3_d = NULL;
    mxArray *c3_c = NULL;
    c3_c = NULL;
    if (c3_b == 20U) {
        sf_mex_assign(&c3_d, c3_sfAfterOrElapsed(S, ptr_gvar_instance), false);
        sfAppendHoverData(&c3_c, sf_mex_dup(c3_d), 20U, "afterOrElapsed", "", 4U, -1, -1);
    }
    sf_mex_destroy(&c3_d);
    return c3_c;
}

void chart_data_browse_helper(SimStruct *S, gvar_instance *ptr_gvar_instance, int32_T c3_ssIdNumber, const mxArray **c3_mxData, uint8_T *c3_isValueBrowsable)
{
    const mxArray *c3_b = NULL;
    uint8_T c3_c;
    (void)S;
    *c3_mxData = NULL;
    *c3_mxData = NULL;
    *c3_isValueBrowsable = 1U;
    switch (c3_ssIdNumber) {
      case 9U:
        sf_mex_assign(c3_mxData, sf_mex_create("mxData", ptr_gvar_instance->c3_SafetyOverspeedFlag, 11, 0U, 0, 0U, 0), false);
        break;
      case 8U:
        sf_mex_assign(c3_mxData, sf_mex_create("mxData", ptr_gvar_instance->c3_Accel_Fault, 11, 0U, 0, 0U, 0), false);
        break;
      case 10U:
        sf_mex_assign(c3_mxData, sf_mex_create("mxData", ptr_gvar_instance->c3_MotorRPM_Fault, 11, 0U, 0, 0U, 0), false);
        break;
      case 11U:
        sf_mex_assign(c3_mxData, sf_mex_create("mxData", ptr_gvar_instance->c3_VechSpeedEst_Fault, 11, 0U, 0, 0U, 0), false);
        break;
      case 12U:
        sf_mex_assign(c3_mxData, sf_mex_create("mxData", ptr_gvar_instance->c3_WSS_Fault, 11, 0U, 0, 0U, 0), false);
        break;
      case 18U:
        sf_mex_assign(c3_mxData, sf_mex_create("mxData", ptr_gvar_instance->c3_SafetySpeedMonitorFaultFlag, 11, 0U, 0, 0U, 0), false);
        break;
      case 24U:
        sf_mex_assign(c3_mxData, sf_mex_create("mxData", ptr_gvar_instance->c3_BrkTrqRq, 1, 0U, 0, 0U, 0), false);
        break;
      case 25U:
        sf_mex_assign(c3_mxData, sf_mex_create("mxData", ptr_gvar_instance->c3_TrqCmd, 1, 0U, 0, 0U, 0), false);
        break;
      case 26U:
        sf_mex_assign(c3_mxData, sf_mex_create("mxData", ptr_gvar_instance->c3_SafeTorquecmd_L2p, 1, 0U, 0, 0U, 0), false);
        break;
      case 28U:
        sf_mex_assign(c3_mxData, sf_mex_create("mxData", &ptr_gvar_instance->c3_Brake_Decel_Level, 1, 0U, 0, 0U, 0), false);
        break;
      case 29U:
        sf_mex_assign(c3_mxData, sf_mex_create("mxData", &ptr_gvar_instance->c3_Brake_Limp, 1, 0U, 0, 0U, 0), false);
        break;
      case 30U:
        sf_mex_assign(c3_mxData, sf_mex_create("mxData", &ptr_gvar_instance->c3_Brake_Max_Safe, 1, 0U, 0, 0U, 0), false);
        break;
      case 42U:
        sf_mex_assign(c3_mxData, sf_mex_create("mxData", &ptr_gvar_instance->c3_Torque_Decel_Limit, 1, 0U, 0, 0U, 0), false);
        break;
      case 43U:
        c3_c = (uint8_T)(int32_T)*ptr_gvar_instance->c3_VechSafetyStatus_L2p;
        sf_mex_assign(&c3_b, sf_mex_create("unnamed temp", &c3_c, 3, 0U, 0, 0U, 0), false);
        sf_mex_assign(c3_mxData, sf_mex_create_enum("VechSafetyStatus_L2p_IDT", c3_b), false);
        break;
    }
    sf_mex_destroy(&c3_b);
}

void init_dsm_address_info(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    (void)S;
    (void)ptr_gvar_instance;
}

void init_simulink_io_address(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    ptr_gvar_instance->c3_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(S);
    ptr_gvar_instance->c3_SafetyOverspeedFlag = (boolean_T *)ssGetInputPortSignal_wrapper(S, 0);
    ptr_gvar_instance->c3_Accel_Fault = (boolean_T *)ssGetInputPortSignal_wrapper(S, 1);
    ptr_gvar_instance->c3_MotorRPM_Fault = (boolean_T *)ssGetInputPortSignal_wrapper(S, 2);
    ptr_gvar_instance->c3_VechSpeedEst_Fault = (boolean_T *)ssGetInputPortSignal_wrapper(S, 3);
    ptr_gvar_instance->c3_WSS_Fault = (boolean_T *)ssGetInputPortSignal_wrapper(S, 4);
    ptr_gvar_instance->c3_SafetySpeedMonitorFaultFlag = (boolean_T *)ssGetInputPortSignal_wrapper(S, 5);
    ptr_gvar_instance->c3_BrkTrqRq = (real32_T *)ssGetOutputPortSignal_wrapper(S, 1);
    ptr_gvar_instance->c3_TrqCmd = (real32_T *)ssGetOutputPortSignal_wrapper(S, 2);
    ptr_gvar_instance->c3_SafeTorquecmd_L2p = (real32_T *)ssGetInputPortSignal_wrapper(S, 6);
    ptr_gvar_instance->c3_VechSafetyStatus_L2p = (uint8_T *)ssGetOutputPortSignal_wrapper(S, 3);
    ptr_gvar_instance->c3_In1 = (real32_T *)ssGetOutputPortSignal_wrapper(S, 4);
    ptr_gvar_instance->c3_In2 = (real32_T *)ssGetOutputPortSignal_wrapper(S, 5);
    ptr_gvar_instance->c3_Out1 = (real32_T *)ssGetInputPortSignal_wrapper(S, 7);
}

void JIT_release_mem_fcn(gvar_instance *ptr_gvar_instance)
{
    free(ptr_gvar_instance);
}

gvar_instance *JIT_init_mem_fcn(void)
{
    return (gvar_instance *)calloc((size_t)1U, sizeof(gvar_instance));
}


