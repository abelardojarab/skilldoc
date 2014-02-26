#include "precomp.h"
extern void scheme_call_expand_observe (Scheme_Object * obs , int signal , Scheme_Object * argument ) ; 
typedef __clock_t clock_t ; 
struct tm {
  int tm_sec ; 
  int tm_min ; 
  int tm_hour ; 
  int tm_mday ; 
  int tm_mon ; 
  int tm_year ; 
  int tm_wday ; 
  int tm_yday ; 
  int tm_isdst ; 
  long int tm_gmtoff ; 
  __const char * tm_zone ; 
}
; 
struct itimerspec {
  struct timespec it_interval ; 
  struct timespec it_value ; 
}
; 
struct sigevent ; 
extern struct tm * localtime (__const time_t * __timer ) __attribute__ ((__nothrow__ ) ) ; 
extern char * __tzname [2 ] ; 
extern char * tzname [2 ] ; 
extern long int timezone ; 
struct timezone {
  int tz_minuteswest ; 
  int tz_dsttime ; 
}
; 
typedef struct timezone * __restrict __timezone_ptr_t ; 
extern int gettimeofday (struct timeval * __restrict __tv , __timezone_ptr_t __tz ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
enum __itimer_which {
  ITIMER_REAL = 0 , ITIMER_VIRTUAL = 1 , ITIMER_PROF = 2 }
; 
struct itimerval {
  struct timeval it_interval ; 
  struct timeval it_value ; 
}
; 
typedef int __itimer_which_t ; 
enum __rlimit_resource {
  RLIMIT_CPU = 0 , RLIMIT_FSIZE = 1 , RLIMIT_DATA = 2 , RLIMIT_STACK = 3 , RLIMIT_CORE = 4 , __RLIMIT_RSS = 5 , RLIMIT_NOFILE = 7 , __RLIMIT_OFILE = RLIMIT_NOFILE , RLIMIT_AS = 9 , __RLIMIT_NPROC = 6 , __RLIMIT_MEMLOCK = 8 , __RLIMIT_LOCKS = 10 , __RLIMIT_SIGPENDING = 11 , __RLIMIT_MSGQUEUE = 12 , __RLIMIT_NICE = 13 , __RLIMIT_RTPRIO = 14 , __RLIMIT_NLIMITS = 15 , __RLIM_NLIMITS = __RLIMIT_NLIMITS }
; 
typedef __rlim_t rlim_t ; 
struct rlimit {
  rlim_t rlim_cur ; 
  rlim_t rlim_max ; 
}
; 
enum __rusage_who {
  RUSAGE_SELF = 0 , RUSAGE_CHILDREN = - 1 }
; 
struct rusage {
  struct timeval ru_utime ; 
  struct timeval ru_stime ; 
  long int ru_maxrss ; 
  long int ru_ixrss ; 
  long int ru_idrss ; 
  long int ru_isrss ; 
  long int ru_minflt ; 
  long int ru_majflt ; 
  long int ru_nswap ; 
  long int ru_inblock ; 
  long int ru_oublock ; 
  long int ru_msgsnd ; 
  long int ru_msgrcv ; 
  long int ru_nsignals ; 
  long int ru_nvcsw ; 
  long int ru_nivcsw ; 
}
; 
enum __priority_which {
  PRIO_PROCESS = 0 , PRIO_PGRP = 1 , PRIO_USER = 2 }
; 
typedef int __rlimit_resource_t ; 
typedef int __rusage_who_t ; 
typedef int __priority_which_t ; 
extern int getrusage (__rusage_who_t __who , struct rusage * __usage ) __attribute__ ((__nothrow__ ) ) ; 
static void ASSERT_SUSPEND_BREAK_ZERO () {
  /* No conversion */
}
int scheme_defining_primitives ; 
Scheme_Object scheme_void [1 ] ; 
Scheme_Object * scheme_values_func ; 
Scheme_Object * scheme_procedure_p_proc ; 
Scheme_Object * scheme_void_proc ; 
Scheme_Object * scheme_call_with_values_proc ; 
Scheme_Object * scheme_tail_call_waiting ; 
Scheme_Object * scheme_inferred_name_symbol ; 
int scheme_cont_capture_count ; 
int scheme_prompt_capture_count ; 
Scheme_Object * scheme_default_prompt_tag ; 
static Scheme_Object * procedure_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * apply (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * map (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * for_each (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * andmap (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * ormap (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * call_cc (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * internal_call_cc (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * continuation_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * call_with_continuation_barrier (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * call_with_prompt (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * call_with_control (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * make_prompt_tag (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * abort_continuation (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * continuation_prompt_available (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * get_default_prompt_tag (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * prompt_tag_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * call_with_sema (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * call_with_sema_enable_break (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * cc_marks (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * cont_marks (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * cc_marks_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * extract_cc_marks (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * extract_cc_markses (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * extract_cc_proc_marks (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * extract_one_cc_mark (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * void_func (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * void_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * dynamic_wind (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * time_apply (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * current_milliseconds (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * current_inexact_milliseconds (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * current_process_milliseconds (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * current_gc_milliseconds (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * current_seconds (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * seconds_to_date (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * object_name (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * procedure_arity (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * procedure_arity_includes (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * procedure_reduce_arity (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * procedure_equal_closure_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * primitive_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * primitive_closure_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * primitive_result_arity (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * call_with_values (int argc , Scheme_Object * argv [] ) ; 
Scheme_Object * scheme_values (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * current_print (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * current_prompt_read (int , Scheme_Object * * ) ; 
static Scheme_Object * write_compiled_closure (Scheme_Object * obj ) ; 
static Scheme_Object * read_compiled_closure (Scheme_Object * obj ) ; 
static int top_next_registered ; 
static Scheme_Comp_Env * top_next_env ; 
static Scheme_Object * top_next_mark ; 
static Scheme_Object * top_next_name ; 
static Scheme_Object * top_next_certs ; 
static Scheme_Object * top_next_modidx ; 
static Scheme_Env * top_next_menv ; 
static int top_next_use_thread_cc_ok ; 
static Scheme_Prompt * original_default_prompt ; 
static Scheme_Object * certify_mode_symbol , * transparent_symbol , * transparent_binding_symbol , * opaque_symbol ; 
static Scheme_Object * cont_key , * barrier_prompt_key ; 
static Scheme_Object * is_method_symbol ; 
static Scheme_Object * call_with_prompt_proc , * abort_continuation_proc ; 
static Scheme_Prompt * available_prompt , * available_cws_prompt , * available_regular_prompt ; 
static Scheme_Dynamic_Wind * available_prompt_dw ; 
static Scheme_Meta_Continuation * available_prompt_mc ; 
static Scheme_Object * reduced_procedure_struct ; 
typedef void (* DW_PrePost_Proc ) (void * ) ; 
static void register_traversers (void ) ; 
static Scheme_Object * internal_call_cc_prim ; 
typedef struct Scheme_Dynamic_Wind_List {
  Scheme_Type type ; 
  Scheme_Dynamic_Wind * dw ; 
  int meta_depth ; 
  struct Scheme_Dynamic_Wind_List * next ; 
}
Scheme_Dynamic_Wind_List ; 
static Scheme_Object * cached_beg_stx , * cached_dv_stx , * cached_ds_stx ; 
int cached_stx_phase ; 
void scheme_init_fun (Scheme_Env * env ) {
  Scheme_Object * o ; 
  Scheme_Object * __funcarg43 = NULLED_OUT ; 
  Scheme_Object * __funcarg42 = NULLED_OUT ; 
  Scheme_Object * __funcarg41 = NULLED_OUT ; 
  Scheme_Object * __funcarg40 = NULLED_OUT ; 
  Scheme_Object * __funcarg39 = NULLED_OUT ; 
  Scheme_Object * __funcarg38 = NULLED_OUT ; 
  Scheme_Object * __funcarg37 = NULLED_OUT ; 
  Scheme_Object * __funcarg36 = NULLED_OUT ; 
  Scheme_Object * __funcarg35 = NULLED_OUT ; 
  Scheme_Object * __funcarg34 = NULLED_OUT ; 
  Scheme_Object * __funcarg33 = NULLED_OUT ; 
  Scheme_Object * __funcarg32 = NULLED_OUT ; 
  Scheme_Object * __funcarg31 = NULLED_OUT ; 
  Scheme_Object * __funcarg30 = NULLED_OUT ; 
  Scheme_Object * __funcarg29 = NULLED_OUT ; 
  Scheme_Object * __funcarg28 = NULLED_OUT ; 
  Scheme_Object * __funcarg27 = NULLED_OUT ; 
  Scheme_Object * __funcarg26 = NULLED_OUT ; 
  Scheme_Object * __funcarg25 = NULLED_OUT ; 
  Scheme_Object * __funcarg24 = NULLED_OUT ; 
  Scheme_Object * __funcarg23 = NULLED_OUT ; 
  Scheme_Object * __funcarg22 = NULLED_OUT ; 
  Scheme_Object * __funcarg21 = NULLED_OUT ; 
  Scheme_Object * __funcarg20 = NULLED_OUT ; 
  Scheme_Object * __funcarg19 = NULLED_OUT ; 
  Scheme_Object * __funcarg18 = NULLED_OUT ; 
  Scheme_Object * __funcarg17 = NULLED_OUT ; 
  Scheme_Object * __funcarg16 = NULLED_OUT ; 
  Scheme_Object * __funcarg15 = NULLED_OUT ; 
  Scheme_Object * __funcarg14 = NULLED_OUT ; 
  Scheme_Object * __funcarg13 = NULLED_OUT ; 
  Scheme_Object * __funcarg12 = NULLED_OUT ; 
  Scheme_Object * __funcarg11 = NULLED_OUT ; 
  Scheme_Object * __funcarg10 = NULLED_OUT ; 
  Scheme_Object * __funcarg9 = NULLED_OUT ; 
  Scheme_Object * __funcarg8 = NULLED_OUT ; 
  Scheme_Object * __funcarg7 = NULLED_OUT ; 
  Scheme_Object * __funcarg6 = NULLED_OUT ; 
  Scheme_Object * __funcarg5 = NULLED_OUT ; 
  Scheme_Object * __funcarg4 = NULLED_OUT ; 
  PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(o, 1)));
# define XfOrM2_COUNT (2)
# define SETUP_XfOrM2(x) SETUP(XfOrM2_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  o = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM2(_), register_traversers () ); 
  scheme_tail_call_waiting = ((Scheme_Object * ) 0x4 ) ; 
  FUNCCALL(SETUP_XfOrM2(_), scheme_register_static ((void * ) & cached_beg_stx , sizeof (cached_beg_stx ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & cached_dv_stx , sizeof (cached_dv_stx ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & cached_ds_stx , sizeof (cached_ds_stx ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_procedure_p_proc , sizeof (scheme_procedure_p_proc ) ) ); 
  o = FUNCCALL_AGAIN(scheme_make_folding_prim (procedure_p , "procedure?" , 1 , 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) o ) -> flags ) |= 16384 ; 
  FUNCCALL(SETUP_XfOrM2(_), scheme_add_global_constant ("procedure?" , o , env ) ); 
  scheme_procedure_p_proc = o ; 
  (__funcarg43 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_everything (apply , 0 , "apply" , 2 , - 1 , 0 , 0 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("apply" , __funcarg43 , env ) )) ; 
  (__funcarg42 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (map , "map" , 2 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("map" , __funcarg42 , env ) )) ; 
  (__funcarg41 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (for_each , "for-each" , 2 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("for-each" , __funcarg41 , env ) )) ; 
  (__funcarg40 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (andmap , "andmap" , 2 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("andmap" , __funcarg40 , env ) )) ; 
  (__funcarg39 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (ormap , "ormap" , 2 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("ormap" , __funcarg39 , env ) )) ; 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_call_with_values_proc , sizeof (scheme_call_with_values_proc ) ) ); 
  scheme_call_with_values_proc = FUNCCALL_AGAIN(scheme_make_prim_w_everything (call_with_values , 0 , "call-with-values" , 2 , 2 , 0 , 0 , - 1 ) ); 
  FUNCCALL_AGAIN(scheme_add_global_constant ("call-with-values" , scheme_call_with_values_proc , env ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_values_func , sizeof (scheme_values_func ) ) ); 
  scheme_values_func = FUNCCALL_AGAIN(scheme_make_prim_w_everything (scheme_values , 0 , "values" , 0 , - 1 , 0 , 0 , - 1 ) ); 
  FUNCCALL_AGAIN(scheme_add_global_constant ("values" , scheme_values_func , env ) ); 
  o = FUNCCALL_AGAIN(scheme_make_prim_w_everything (scheme_call_ec , 0 , "call-with-escape-continuation" , 1 , 1 , 0 , 0 , - 1 ) ); 
  FUNCCALL_AGAIN(scheme_add_global_constant ("call-with-escape-continuation" , o , env ) ); 
  FUNCCALL_AGAIN(scheme_add_global_constant ("call/ec" , o , env ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & internal_call_cc_prim , sizeof (internal_call_cc_prim ) ) ); 
  internal_call_cc_prim = FUNCCALL_AGAIN(scheme_make_prim_w_everything (internal_call_cc , 0 , "call-with-current-continuation" , 1 , 3 , 0 , 0 , - 1 ) ); 
  o = FUNCCALL_AGAIN(scheme_make_prim_w_everything (call_cc , 0 , "call-with-current-continuation" , 1 , 2 , 0 , 0 , - 1 ) ); 
  FUNCCALL_AGAIN(scheme_add_global_constant ("call-with-current-continuation" , o , env ) ); 
  FUNCCALL_AGAIN(scheme_add_global_constant ("call/cc" , o , env ) ); 
  (__funcarg38 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_folding_prim (continuation_p , "continuation?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("continuation?" , __funcarg38 , env ) )) ; 
  (__funcarg37 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_everything (call_with_continuation_barrier , 0 , "call-with-continuation-barrier" , 1 , 1 , 0 , 0 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("call-with-continuation-barrier" , __funcarg37 , env ) )) ; 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & call_with_prompt_proc , sizeof (call_with_prompt_proc ) ) ); 
  call_with_prompt_proc = FUNCCALL_AGAIN(scheme_make_prim_w_everything (call_with_prompt , 0 , "call-with-continuation-prompt" , 1 , 3 , 0 , 0 , - 1 ) ); 
  FUNCCALL_AGAIN(scheme_add_global_constant ("call-with-continuation-prompt" , call_with_prompt_proc , env ) ); 
  (__funcarg36 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_everything (call_with_control , 0 , "call-with-composable-continuation" , 1 , 2 , 0 , 0 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("call-with-composable-continuation" , __funcarg36 , env ) )) ; 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & abort_continuation_proc , sizeof (abort_continuation_proc ) ) ); 
  abort_continuation_proc = FUNCCALL_AGAIN(scheme_make_prim_w_arity (abort_continuation , "abort-current-continuation" , 1 , - 1 ) ); 
  FUNCCALL_AGAIN(scheme_add_global_constant ("abort-current-continuation" , abort_continuation_proc , env ) ); 
  (__funcarg35 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (continuation_prompt_available , "continuation-prompt-available?" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("continuation-prompt-available?" , __funcarg35 , env ) )) ; 
  (__funcarg34 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (make_prompt_tag , "make-continuation-prompt-tag" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-continuation-prompt-tag" , __funcarg34 , env ) )) ; 
  (__funcarg33 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (get_default_prompt_tag , "default-continuation-prompt-tag" , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("default-continuation-prompt-tag" , __funcarg33 , env ) )) ; 
  (__funcarg32 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_folding_prim (prompt_tag_p , "continuation-prompt-tag?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("continuation-prompt-tag?" , __funcarg32 , env ) )) ; 
  (__funcarg31 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_everything (call_with_sema , 0 , "call-with-semaphore" , 2 , - 1 , 0 , 0 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("call-with-semaphore" , __funcarg31 , env ) )) ; 
  (__funcarg30 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_everything (call_with_sema_enable_break , 0 , "call-with-semaphore/enable-break" , 2 , - 1 , 0 , 0 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("call-with-semaphore/enable-break" , __funcarg30 , env ) )) ; 
  (__funcarg29 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (cc_marks , "current-continuation-marks" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-continuation-marks" , __funcarg29 , env ) )) ; 
  (__funcarg28 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (cont_marks , "continuation-marks" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("continuation-marks" , __funcarg28 , env ) )) ; 
  (__funcarg27 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (extract_cc_marks , "continuation-mark-set->list" , 2 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("continuation-mark-set->list" , __funcarg27 , env ) )) ; 
  (__funcarg26 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (extract_cc_markses , "continuation-mark-set->list*" , 2 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("continuation-mark-set->list*" , __funcarg26 , env ) )) ; 
  (__funcarg25 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (extract_one_cc_mark , "continuation-mark-set-first" , 2 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("continuation-mark-set-first" , __funcarg25 , env ) )) ; 
  (__funcarg24 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (cc_marks_p , "continuation-mark-set?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("continuation-mark-set?" , __funcarg24 , env ) )) ; 
  (__funcarg23 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (extract_cc_proc_marks , "continuation-mark-set->context" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("continuation-mark-set->context" , __funcarg23 , env ) )) ; 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_void_proc , sizeof (scheme_void_proc ) ) ); 
  scheme_void_proc = FUNCCALL_AGAIN(scheme_make_folding_prim (void_func , "void" , 0 , - 1 , 1 ) ); 
  FUNCCALL_AGAIN(scheme_add_global_constant ("void" , scheme_void_proc , env ) ); 
  (__funcarg22 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_folding_prim (void_p , "void?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("void?" , __funcarg22 , env ) )) ; 
  (__funcarg21 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_everything (time_apply , 0 , "time-apply" , 2 , 2 , 0 , 4 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("time-apply" , __funcarg21 , env ) )) ; 
  (__funcarg20 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (current_milliseconds , "current-milliseconds" , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-milliseconds" , __funcarg20 , env ) )) ; 
  (__funcarg19 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (current_inexact_milliseconds , "current-inexact-milliseconds" , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-inexact-milliseconds" , __funcarg19 , env ) )) ; 
  (__funcarg18 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (current_process_milliseconds , "current-process-milliseconds" , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-process-milliseconds" , __funcarg18 , env ) )) ; 
  (__funcarg17 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (current_gc_milliseconds , "current-gc-milliseconds" , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-gc-milliseconds" , __funcarg17 , env ) )) ; 
  (__funcarg16 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (current_seconds , "current-seconds" , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-seconds" , __funcarg16 , env ) )) ; 
  (__funcarg15 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (seconds_to_date , "seconds->date" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("seconds->date" , __funcarg15 , env ) )) ; 
  (__funcarg14 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (dynamic_wind , "dynamic-wind" , 3 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("dynamic-wind" , __funcarg14 , env ) )) ; 
  (__funcarg13 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_folding_prim (object_name , "object-name" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("object-name" , __funcarg13 , env ) )) ; 
  (__funcarg12 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_folding_prim (procedure_arity , "procedure-arity" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("procedure-arity" , __funcarg12 , env ) )) ; 
  (__funcarg11 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_folding_prim (procedure_arity_includes , "procedure-arity-includes?" , 2 , 2 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("procedure-arity-includes?" , __funcarg11 , env ) )) ; 
  (__funcarg10 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (procedure_reduce_arity , "procedure-reduce-arity" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("procedure-reduce-arity" , __funcarg10 , env ) )) ; 
  (__funcarg9 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_folding_prim (procedure_equal_closure_p , "procedure-closure-contents-eq?" , 2 , 2 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("procedure-closure-contents-eq?" , __funcarg9 , env ) )) ; 
  (__funcarg8 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_folding_prim (primitive_p , "primitive?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("primitive?" , __funcarg8 , env ) )) ; 
  (__funcarg7 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_folding_prim (primitive_closure_p , "primitive-closure?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("primitive-closure?" , __funcarg7 , env ) )) ; 
  (__funcarg6 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_folding_prim (primitive_result_arity , "primitive-result-arity" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("primitive-result-arity" , __funcarg6 , env ) )) ; 
  (__funcarg5 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (current_print , "current-print" , MZCONFIG_PRINT_HANDLER ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-print" , __funcarg5 , env ) )) ; 
  (__funcarg4 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (current_prompt_read , "current-prompt-read" , MZCONFIG_PROMPT_READ_HANDLER ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-prompt-read" , __funcarg4 , env ) )) ; 
  FUNCCALL_AGAIN(scheme_install_type_writer (scheme_unclosed_procedure_type , write_compiled_closure ) ); 
  FUNCCALL_AGAIN(scheme_install_type_reader (scheme_unclosed_procedure_type , read_compiled_closure ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & is_method_symbol , sizeof (is_method_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_inferred_name_symbol , sizeof (scheme_inferred_name_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & cont_key , sizeof (cont_key ) ) ); 
  is_method_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("method-arity-error" ) ); 
  scheme_inferred_name_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("inferred-name" ) ); 
  cont_key = FUNCCALL_AGAIN(scheme_make_symbol ("k" ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_default_prompt_tag , sizeof (scheme_default_prompt_tag ) ) ); 
  {
    Scheme_Object * a [1 ] ; 
    BLOCK_SETUP((PUSHARRAY(a, 1, 0+XfOrM2_COUNT)));
#   define XfOrM3_COUNT (3+XfOrM2_COUNT)
#   define SETUP_XfOrM3(x) SETUP(XfOrM3_COUNT)
    a[0] = NULLED_OUT ; 
    a [0 ] = FUNCCALL(SETUP_XfOrM3(_), scheme_intern_symbol ("default" ) ); 
    scheme_default_prompt_tag = FUNCCALL(SETUP_XfOrM3(_), make_prompt_tag (1 , a ) ); 
  }
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & original_default_prompt , sizeof (original_default_prompt ) ) ); 
  original_default_prompt = ((Scheme_Prompt * ) FUNCCALL_EMPTY(GC_malloc_one_small_tagged ((((sizeof (Scheme_Prompt ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  original_default_prompt -> so . type = scheme_prompt_type ; 
  original_default_prompt -> tag = scheme_default_prompt_tag ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_void (void ) {
  /* No conversion */
  return scheme_void ; 
}
static Scheme_Object * make_prim_closure (Scheme_Prim * fun , int eternal , const char * name , mzshort mina , mzshort maxa , int flags , mzshort minr , mzshort maxr , int closed , int count , Scheme_Object * * vals ) {
  Scheme_Primitive_Proc * prim ; 
  int hasr , size ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(name, 0), PUSH(vals, 1), PUSH(prim, 2), PUSH(fun, 3)));
# define XfOrM5_COUNT (4)
# define SETUP_XfOrM5(x) SETUP(XfOrM5_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  prim = NULLED_OUT ; 
  hasr = ((minr != 1 ) || (maxr != 1 ) ) ; 
  size = (hasr ? sizeof (Scheme_Prim_W_Result_Arity ) : (closed ? (sizeof (Scheme_Primitive_Closure ) + ((count - 1 ) * sizeof (Scheme_Object * ) ) ) : sizeof (Scheme_Primitive_Proc ) ) ) ; 
  if (eternal && scheme_starting_up && ! closed )
    prim = (Scheme_Primitive_Proc * ) FUNCCALL(SETUP_XfOrM5(_), GC_malloc_atomic_uncollectable (size ) ); 
  else prim = (Scheme_Primitive_Proc * ) FUNCCALL(SETUP_XfOrM5(_), GC_malloc_one_tagged (size ) ); 
  prim -> pp . so . type = scheme_prim_type ; 
  prim -> prim_val = (Scheme_Primitive_Closure_Proc * ) fun ; 
  prim -> name = name ; 
  prim -> mina = mina ; 
  if (maxa < 0 )
    maxa = 0x3FFFFFFE + 1 ; 
  prim -> mu . maxa = maxa ; 
  prim -> pp . flags = (flags | (scheme_defining_primitives ? 2 : 0 ) | (hasr ? 256 : 0 ) | (closed ? 4096 : 0 ) ) ; 
  if (hasr ) {
    ((Scheme_Prim_W_Result_Arity * ) prim ) -> minr = minr ; 
    ((Scheme_Prim_W_Result_Arity * ) prim ) -> maxr = maxr ; 
  }
  if (closed ) {
#   define XfOrM6_COUNT (0+XfOrM5_COUNT)
#   define SETUP_XfOrM6(x) SETUP_XfOrM5(x)
    ((Scheme_Primitive_Closure * ) prim ) -> count = count ; 
    (memcpy (((Scheme_Primitive_Closure * ) prim ) -> val , vals , count * sizeof (Scheme_Object * ) ) ) ; 
  }
  RET_VALUE_START ((Scheme_Object * ) prim ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_prim_w_everything (Scheme_Prim * fun , int eternal , const char * name , mzshort mina , mzshort maxa , int flags , mzshort minr , mzshort maxr ) {
  /* No conversion */
  return make_prim_closure (fun , eternal , name , mina , maxa , flags , minr , maxr , 0 , 0 , ((void * ) 0 ) ) ; 
}
Scheme_Object * scheme_make_prim (Scheme_Prim * fun ) {
  /* No conversion */
  return make_prim_closure (fun , 1 , ((void * ) 0 ) , 0 , - 1 , 0 , 1 , 1 , 0 , 0 , ((void * ) 0 ) ) ; 
}
Scheme_Object * scheme_make_noneternal_prim (Scheme_Prim * fun ) {
  /* No conversion */
  return make_prim_closure (fun , 0 , ((void * ) 0 ) , 0 , - 1 , 0 , 1 , 1 , 0 , 0 , ((void * ) 0 ) ) ; 
}
Scheme_Object * scheme_make_prim_w_arity (Scheme_Prim * fun , const char * name , mzshort mina , mzshort maxa ) {
  /* No conversion */
  return make_prim_closure (fun , 1 , name , mina , maxa , 0 , 1 , 1 , 0 , 0 , ((void * ) 0 ) ) ; 
}
Scheme_Object * scheme_make_folding_prim (Scheme_Prim * fun , const char * name , mzshort mina , mzshort maxa , short folding ) {
  /* No conversion */
  return make_prim_closure (fun , 1 , name , mina , maxa , (folding ? (1 | 8192 ) : 0 ) , 1 , 1 , 0 , 0 , ((void * ) 0 ) ) ; 
}
Scheme_Object * scheme_make_noncm_prim (Scheme_Prim * fun , const char * name , mzshort mina , mzshort maxa ) {
  /* No conversion */
  return make_prim_closure (fun , 1 , name , mina , maxa , 8192 , 1 , 1 , 0 , 0 , ((void * ) 0 ) ) ; 
}
Scheme_Object * scheme_make_noneternal_prim_w_arity (Scheme_Prim * fun , const char * name , mzshort mina , mzshort maxa ) {
  /* No conversion */
  return make_prim_closure (fun , 0 , name , mina , maxa , 0 , 1 , 1 , 0 , 0 , ((void * ) 0 ) ) ; 
}
Scheme_Object * scheme_make_prim_closure_w_arity (Scheme_Primitive_Closure_Proc * prim , int size , Scheme_Object * * vals , const char * name , mzshort mina , mzshort maxa ) {
  /* No conversion */
  return make_prim_closure ((Scheme_Prim * ) prim , 1 , name , mina , maxa , 0 , 1 , 1 , 1 , size , vals ) ; 
}
Scheme_Object * scheme_make_folding_prim_closure (Scheme_Primitive_Closure_Proc * prim , int size , Scheme_Object * * vals , const char * name , mzshort mina , mzshort maxa , short functional ) {
  /* No conversion */
  return make_prim_closure ((Scheme_Prim * ) prim , 1 , name , mina , maxa , (functional ? 1 : 0 ) , 1 , 1 , 1 , size , vals ) ; 
}
Scheme_Object * scheme_make_closed_prim_w_everything (Scheme_Closed_Prim * fun , void * data , const char * name , mzshort mina , mzshort maxa , short folding , mzshort minr , mzshort maxr ) {
  Scheme_Closed_Primitive_Proc * prim ; 
  int hasr , size ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(data, 0), PUSH(prim, 1), PUSH(name, 2), PUSH(fun, 3)));
# define XfOrM17_COUNT (4)
# define SETUP_XfOrM17(x) SETUP(XfOrM17_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  prim = NULLED_OUT ; 
  hasr = ((minr != 1 ) || (maxr != 1 ) ) ; 
  size = hasr ? sizeof (Scheme_Closed_Prim_W_Result_Arity ) : sizeof (Scheme_Closed_Primitive_Proc ) ; 
  prim = (Scheme_Closed_Primitive_Proc * ) FUNCCALL(SETUP_XfOrM17(_), GC_malloc_one_tagged (size ) ); 
  prim -> pp . so . type = scheme_closed_prim_type ; 
  (((Scheme_Closed_Primitive_Proc * ) (prim ) ) -> prim_val ) = fun ; 
  (((Scheme_Closed_Primitive_Proc * ) (prim ) ) -> data ) = data ; 
  prim -> name = name ; 
  prim -> mina = mina ; 
  prim -> maxa = maxa ; 
  prim -> pp . flags = ((folding ? 1 : 0 ) | (scheme_defining_primitives ? 2 : 0 ) | (hasr ? 256 : 0 ) ) ; 
  if (hasr ) {
    ((Scheme_Closed_Prim_W_Result_Arity * ) prim ) -> minr = minr ; 
    ((Scheme_Closed_Prim_W_Result_Arity * ) prim ) -> maxr = maxr ; 
  }
  RET_VALUE_START ((Scheme_Object * ) prim ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_folding_closed_prim (Scheme_Closed_Prim * fun , void * data , const char * name , mzshort mina , mzshort maxa , short folding ) {
  /* No conversion */
  return scheme_make_closed_prim_w_everything (fun , data , name , mina , maxa , folding , 1 , 1 ) ; 
}
Scheme_Object * scheme_make_closed_prim_w_arity (Scheme_Closed_Prim * fun , void * data , const char * name , mzshort mina , mzshort maxa ) {
  /* No conversion */
  return scheme_make_closed_prim_w_everything (fun , data , name , mina , maxa , 0 , 1 , 1 ) ; 
}
Scheme_Object * scheme_make_closed_prim (Scheme_Closed_Prim * fun , void * data ) {
  /* No conversion */
  return scheme_make_closed_prim_w_everything (fun , data , ((void * ) 0 ) , 0 , - 1 , 0 , 1 , 1 ) ; 
}
void scheme_prim_is_method (Scheme_Object * o ) {
  /* No conversion */
  if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_closed_prim_type ) ) )
    ((Scheme_Closed_Primitive_Proc * ) o ) -> pp . flags |= 2048 ; 
  else ((Scheme_Primitive_Proc * ) o ) -> pp . flags |= 2048 ; 
}
int scheme_has_method_property (Scheme_Object * code ) {
  /* No conversion */
  return (! (((scheme_stx_property (code , is_method_symbol , ((void * ) 0 ) ) ) ) == (scheme_false ) ) ) ; 
}
/* this far 809 */
Scheme_Object * scheme_make_closure (Scheme_Thread * p , Scheme_Object * code , int close ) {
  Scheme_Closure_Data * data ; 
  Scheme_Closure * closure ; 
  GC_CAN_IGNORE Scheme_Object * * runstack ; 
  GC_CAN_IGNORE Scheme_Object * * dest ; 
  GC_CAN_IGNORE mzshort * map ; 
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(closure, 0), PUSH(code, 1), PUSH(data, 2)));
# define XfOrM24_COUNT (3)
# define SETUP_XfOrM24(x) SETUP(XfOrM24_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  data = NULLED_OUT ; 
  closure = NULLED_OUT ; 
  data = (Scheme_Closure_Data * ) code ; 
  if (data -> u . native_code ) {
    Scheme_Object * nc ; 
    BLOCK_SETUP((PUSH(nc, 0+XfOrM24_COUNT)));
#   define XfOrM27_COUNT (1+XfOrM24_COUNT)
#   define SETUP_XfOrM27(x) SETUP(XfOrM27_COUNT)
    nc = NULLED_OUT ; 
    nc = FUNCCALL(SETUP_XfOrM27(_), scheme_make_native_closure (data -> u . native_code ) ); 
    if (close ) {
      runstack = scheme_current_runstack ; 
      dest = ((Scheme_Native_Closure * ) nc ) -> vals ; 
      map = data -> closure_map ; 
      i = data -> closure_size ; 
      while (i -- ) {
        dest [i ] = runstack [map [i ] ] ; 
      }
    }
    RET_VALUE_START (nc ) RET_VALUE_END ; 
  }
  i = data -> closure_size ; 
  closure = (Scheme_Closure * ) FUNCCALL(SETUP_XfOrM24(_), GC_malloc_one_tagged (sizeof (Scheme_Closure ) + (i - 1 ) * sizeof (Scheme_Object * ) ) ); 
  closure -> so . type = scheme_closure_type ; 
  ((Scheme_Closure * ) closure ) -> code = data ; 
  if (! close || ! i )
    RET_VALUE_START ((Scheme_Object * ) closure ) RET_VALUE_END ; 
  runstack = scheme_current_runstack ; 
  dest = closure -> vals ; 
  map = data -> closure_map ; 
  while (i -- ) {
    dest [i ] = runstack [map [i ] ] ; 
  }
  RET_VALUE_START ((Scheme_Object * ) closure ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 834 */
Scheme_Closure * scheme_malloc_empty_closure () {
  Scheme_Closure * cl ; 
  DECL_RET_SAVE (Scheme_Closure * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(cl, 0)));
# define XfOrM31_COUNT (1)
# define SETUP_XfOrM31(x) SETUP(XfOrM31_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  cl = NULLED_OUT ; 
  cl = (Scheme_Closure * ) FUNCCALL(SETUP_XfOrM31(_), GC_malloc_one_tagged (sizeof (Scheme_Closure ) - sizeof (Scheme_Object * ) ) ); 
  cl -> so . type = scheme_closure_type ; 
  RET_VALUE_START (cl ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_jit_closure (Scheme_Object * code , Scheme_Object * context ) {
  Scheme_Closure_Data * data = (Scheme_Closure_Data * ) code , * data2 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(code, 0), PUSH(data, 1), PUSH(data2, 2), PUSH(context, 3)));
# define XfOrM32_COUNT (4)
# define SETUP_XfOrM32(x) SETUP(XfOrM32_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  data2 = NULLED_OUT ; 
  if (! context )
    data2 = data -> u . jit_clone ; 
  else data2 = ((void * ) 0 ) ; 
  if (! data2 ) {
    Scheme_Native_Closure_Data * ndata ; 
    BLOCK_SETUP((PUSH(ndata, 0+XfOrM32_COUNT)));
#   define XfOrM33_COUNT (1+XfOrM32_COUNT)
#   define SETUP_XfOrM33(x) SETUP(XfOrM33_COUNT)
    ndata = NULLED_OUT ; 
    data2 = ((Scheme_Closure_Data * ) FUNCCALL(SETUP_XfOrM33(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Closure_Data ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    (memcpy (data2 , code , sizeof (Scheme_Closure_Data ) ) ) ; 
    data2 -> context = context ; 
    ndata = FUNCCALL(SETUP_XfOrM33(_), scheme_generate_lambda (data2 , 1 , ((void * ) 0 ) ) ); 
    data2 -> u . native_code = ndata ; 
    if (! context )
      data -> u . jit_clone = data2 ; 
  }
  if (! data2 -> closure_size )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_native_closure (data2 -> u . native_code ) )) RET_VALUE_EMPTY_END ; 
  RET_VALUE_START ((Scheme_Object * ) data2 ) RET_VALUE_END ; 
  RET_VALUE_START (code ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
typedef struct {
  Scheme_Type type ; 
  int * local_flags ; 
  mzshort base_closure_size ; 
  mzshort * base_closure_map ; 
  short has_tl , body_size ; 
}
Closure_Info ; 
Scheme_Object * scheme_optimize_closure_compilation (Scheme_Object * _data , Optimize_Info * info ) {
  Scheme_Closure_Data * data ; 
  Scheme_Object * code ; 
  Closure_Info * cl ; 
  mzshort dcs , * dcm ; 
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(info, 0), PUSH(code, 1), PUSH(dcm, 2), PUSH(data, 3), PUSH(cl, 4)));
# define XfOrM34_COUNT (5)
# define SETUP_XfOrM34(x) SETUP(XfOrM34_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  data = NULLED_OUT ; 
  code = NULLED_OUT ; 
  cl = NULLED_OUT ; 
  dcm = NULLED_OUT ; 
  data = (Scheme_Closure_Data * ) _data ; 
  info -> single_result = 1 ; 
  info -> preserves_marks = 1 ; 
  info = FUNCCALL(SETUP_XfOrM34(_), scheme_optimize_info_add_frame (info , data -> num_params , data -> num_params , 8 ) ); 
  cl = (Closure_Info * ) data -> closure_map ; 
  for (i = 0 ; i < data -> num_params ; i ++ ) {
#   define XfOrM36_COUNT (0+XfOrM34_COUNT)
#   define SETUP_XfOrM36(x) SETUP_XfOrM34(x)
    if (cl -> local_flags [i ] & 0x2 )
      FUNCCALL(SETUP_XfOrM36(_), scheme_optimize_mutated (info , i ) ); 
  }
  code = FUNCCALL(SETUP_XfOrM34(_), scheme_optimize_expr (data -> code , info ) ); 
  if (info -> single_result )
    (& (data ) -> iso ) -> so . keyex |= 32 ; 
  else if ((& (data ) -> iso ) -> so . keyex & 32 )
    (& (data ) -> iso ) -> so . keyex -= 32 ; 
  if (info -> preserves_marks )
    (& (data ) -> iso ) -> so . keyex |= 4 ; 
  else if ((& (data ) -> iso ) -> so . keyex & 4 )
    (& (data ) -> iso ) -> so . keyex -= 4 ; 
  data -> code = code ; 
  FUNCCALL(SETUP_XfOrM34(_), scheme_env_make_closure_map (info , & dcs , & dcm ) ); 
  cl -> base_closure_size = dcs ; 
  cl -> base_closure_map = dcm ; 
  if (FUNCCALL(SETUP_XfOrM34(_), scheme_env_uses_toplevel (info ) ))
    cl -> has_tl = 1 ; 
  else cl -> has_tl = 0 ; 
  cl -> body_size = info -> size ; 
  info -> size ++ ; 
  info -> inline_fuel ++ ; 
  data -> closure_size = (cl -> base_closure_size + (cl -> has_tl ? 1 : 0 ) ) ; 
  FUNCCALL(SETUP_XfOrM34(_), scheme_optimize_info_done (info ) ); 
  RET_VALUE_START ((Scheme_Object * ) data ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_clone_closure_compilation (int dup_ok , Scheme_Object * _data , Optimize_Info * info , int delta , int closure_depth ) {
  Scheme_Closure_Data * data , * data2 ; 
  Scheme_Object * body ; 
  Closure_Info * cl ; 
  int * flags , sz ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(data, 0), PUSH(data2, 1), PUSH(cl, 2), PUSH(flags, 3), PUSH(body, 4)));
# define XfOrM37_COUNT (5)
# define SETUP_XfOrM37(x) SETUP(XfOrM37_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  data = NULLED_OUT ; 
  data2 = NULLED_OUT ; 
  body = NULLED_OUT ; 
  cl = NULLED_OUT ; 
  flags = NULLED_OUT ; 
  data = (Scheme_Closure_Data * ) _data ; 
  body = FUNCCALL(SETUP_XfOrM37(_), scheme_optimize_clone (dup_ok , data -> code , info , delta , closure_depth + data -> num_params ) ); 
  if (! body )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  data2 = ((Scheme_Closure_Data * ) FUNCCALL(SETUP_XfOrM37(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Closure_Data ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  (memcpy (data2 , data , sizeof (Scheme_Closure_Data ) ) ) ; 
  data2 -> code = body ; 
  cl = ((Closure_Info * ) FUNCCALL(SETUP_XfOrM37(_), GC_malloc_one_small_tagged ((((sizeof (Closure_Info ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  (memcpy (cl , data -> closure_map , sizeof (Closure_Info ) ) ) ; 
  data2 -> closure_map = (mzshort * ) cl ; 
  sz = sizeof (int ) * data2 -> num_params ; 
  flags = (int * ) FUNCCALL(SETUP_XfOrM37(_), GC_malloc_atomic (sz ) ); 
  (memcpy (flags , cl -> local_flags , sz ) ) ; 
  cl -> local_flags = flags ; 
  RET_VALUE_START ((Scheme_Object * ) data2 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_shift_closure_compilation (Scheme_Object * _data , int delta , int after_depth ) {
  Scheme_Object * expr ; 
  Scheme_Closure_Data * data = (Scheme_Closure_Data * ) _data ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(expr, 0), PUSH(_data, 1), PUSH(data, 2)));
# define XfOrM38_COUNT (3)
# define SETUP_XfOrM38(x) SETUP(XfOrM38_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  expr = NULLED_OUT ; 
  expr = FUNCCALL(SETUP_XfOrM38(_), scheme_optimize_shift (data -> code , delta , after_depth + data -> num_params ) ); 
  data -> code = expr ; 
  RET_VALUE_START (_data ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_closure_body_size (Scheme_Closure_Data * data , int check_assign ) {
  /* No conversion */
  int i ; 
  Closure_Info * cl ; 
  cl = (Closure_Info * ) data -> closure_map ; 
  if (check_assign ) {
    if ((& (data ) -> iso ) -> so . keyex & 1 )
      return - 1 ; 
    for (i = data -> num_params ; i -- ; ) {
      if (cl -> local_flags [i ] & 0x2 )
        return - 1 ; 
    }
  }
  return cl -> body_size ; 
}
int scheme_closure_has_top_level (Scheme_Closure_Data * data ) {
  /* No conversion */
  Closure_Info * cl ; 
  cl = (Closure_Info * ) data -> closure_map ; 
  return cl -> has_tl ; 
}
int scheme_closure_argument_flags (Scheme_Closure_Data * data , int i ) {
  /* No conversion */
  return ((Closure_Info * ) data -> closure_map ) -> local_flags [i ] ; 
}
__xform_nongcing__ static int boxmap_size (int n ) {
  /* No conversion */
  return (n + ((8 * sizeof (mzshort ) ) - 1 ) ) / (8 * sizeof (mzshort ) ) ; 
}
static mzshort * allocate_boxmap (int n ) {
  mzshort * boxmap ; 
  int size ; 
  DECL_RET_SAVE (mzshort * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(boxmap, 0)));
# define XfOrM46_COUNT (1)
# define SETUP_XfOrM46(x) SETUP(XfOrM46_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  boxmap = NULLED_OUT ; 
  size = (boxmap_size (n ) ) ; 
  boxmap = ((mzshort * ) FUNCCALL(SETUP_XfOrM46(_), GC_malloc_atomic (sizeof (mzshort ) * (size ) ) )) ; 
  (memset (boxmap , 0 , size * sizeof (mzshort ) ) ) ; 
  RET_VALUE_START (boxmap ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
__xform_nongcing__ static void boxmap_set (mzshort * boxmap , int j ) {
  /* No conversion */
  boxmap [j / (8 * sizeof (mzshort ) ) ] |= ((mzshort ) 1 << (j & ((8 * sizeof (mzshort ) ) - 1 ) ) ) ; 
}
__xform_nongcing__ static int boxmap_get (mzshort * boxmap , int j ) {
  /* No conversion */
  if (boxmap [j / (8 * sizeof (mzshort ) ) ] & ((mzshort ) 1 << (j & ((8 * sizeof (mzshort ) ) - 1 ) ) ) )
    return 1 ; 
  else return 0 ; 
}
Scheme_Object * scheme_resolve_closure_compilation (Scheme_Object * _data , Resolve_Info * info , int can_lift , int convert , int just_compute_lift , Scheme_Object * precomputed_lift ) {
  Scheme_Closure_Data * data ; 
  int i , closure_size , offset , np , num_params ; 
  int has_tl , convert_size , need_lift ; 
  mzshort * oldpos , * closure_map ; 
  Closure_Info * cl ; 
  Resolve_Info * new_info ; 
  Scheme_Object * lifted , * result , * lifteds = ((void * ) 0 ) ; 
  Scheme_Hash_Table * captured = ((void * ) 0 ) ; 
  mzshort * convert_map , * convert_boxes = ((void * ) 0 ) ; 
  Scheme_Object * __funcarg46 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(18);
  BLOCK_SETUP_TOP((PUSH(cl, 0), PUSH(convert_boxes, 1), PUSH(info, 2), PUSH(closure_map, 3), PUSH(lifteds, 4), PUSH(new_info, 5), PUSH(result, 6), PUSH(data, 7), PUSH(lifted, 8), PUSH(oldpos, 9), PUSH(convert_map, 10), PUSH(captured, 11), PUSH(precomputed_lift, 12)));
# define XfOrM49_COUNT (13)
# define SETUP_XfOrM49(x) SETUP(XfOrM49_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  data = NULLED_OUT ; 
  oldpos = NULLED_OUT ; 
  closure_map = NULLED_OUT ; 
  cl = NULLED_OUT ; 
  new_info = NULLED_OUT ; 
  lifted = NULLED_OUT ; 
  result = NULLED_OUT ; 
  convert_map = NULLED_OUT ; 
  data = (Scheme_Closure_Data * ) _data ; 
  cl = (Closure_Info * ) data -> closure_map ; 
  if (! just_compute_lift )
    data -> iso . so . type = scheme_unclosed_procedure_type ; 
  if (convert || can_lift ) {
#   define XfOrM133_COUNT (0+XfOrM49_COUNT)
#   define SETUP_XfOrM133(x) SETUP_XfOrM49(x)
    if (! FUNCCALL(SETUP_XfOrM133(_), scheme_resolving_in_procedure (info ) )) {
      convert = 0 ; 
      can_lift = 0 ; 
    }
    if (! info -> lifts )
      can_lift = 0 ; 
  }
  closure_size = data -> closure_size ; 
  closure_map = (mzshort * ) FUNCCALL(SETUP_XfOrM49(_), GC_malloc_atomic (sizeof (mzshort ) * closure_size ) ); 
  has_tl = cl -> has_tl ; 
  if (has_tl && ! can_lift )
    convert = 0 ; 
  oldpos = cl -> base_closure_map ; 
  offset = 0 ; 
  for (i = 0 ; i < cl -> base_closure_size ; i ++ ) {
    int li , flags ; 
#   define XfOrM127_COUNT (0+XfOrM49_COUNT)
#   define SETUP_XfOrM127(x) SETUP_XfOrM49(x)
    li = FUNCCALL(SETUP_XfOrM127(_), scheme_resolve_info_lookup (info , oldpos [i ] , & flags , & lifted , 0 ) ); 
    if (lifted ) {
#     define XfOrM130_COUNT (0+XfOrM127_COUNT)
#     define SETUP_XfOrM130(x) SETUP_XfOrM127(x)
      if (((Scheme_Type ) (((((long ) (lifted ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lifted ) ) -> type ) ) == (Scheme_Type ) (scheme_toplevel_type ) ) || ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (lifted ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (lifted ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_toplevel_type ) ) ) {
        has_tl = 1 ; 
        if (! can_lift )
          convert = 0 ; 
      }
      if (((Scheme_Type ) (((((long ) (lifted ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lifted ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ) {
#       define XfOrM131_COUNT (0+XfOrM130_COUNT)
#       define SETUP_XfOrM131(x) SETUP_XfOrM130(x)
        lifteds = FUNCCALL(SETUP_XfOrM131(_), scheme_make_raw_pair (lifted , lifteds ) ); 
      }
    }
    else {
#     define XfOrM128_COUNT (0+XfOrM127_COUNT)
#     define SETUP_XfOrM128(x) SETUP_XfOrM127(x)
      closure_map [offset ] = li ; 
      if (convert && (flags & 1 ) ) {
#       define XfOrM129_COUNT (0+XfOrM128_COUNT)
#       define SETUP_XfOrM129(x) SETUP_XfOrM128(x)
        if (! convert_boxes )
          convert_boxes = FUNCCALL(SETUP_XfOrM129(_), allocate_boxmap (cl -> base_closure_size ) ); 
        (boxmap_set (convert_boxes , offset ) ) ; 
      }
      offset ++ ; 
    }
  }
  while (lifteds ) {
    int j , cnt , boxed ; 
    Scheme_Object * vec , * loc ; 
    BLOCK_SETUP((PUSH(loc, 0+XfOrM49_COUNT), PUSH(vec, 1+XfOrM49_COUNT)));
#   define XfOrM111_COUNT (2+XfOrM49_COUNT)
#   define SETUP_XfOrM111(x) SETUP(XfOrM111_COUNT)
    vec = NULLED_OUT ; 
    loc = NULLED_OUT ; 
    if (! captured ) {
#     define XfOrM118_COUNT (0+XfOrM111_COUNT)
#     define SETUP_XfOrM118(x) SETUP_XfOrM111(x)
      captured = FUNCCALL(SETUP_XfOrM118(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
      for (i = 0 ; i < offset ; i ++ ) {
        int cp ; 
#       define XfOrM120_COUNT (0+XfOrM118_COUNT)
#       define SETUP_XfOrM120(x) SETUP_XfOrM118(x)
        cp = i ; 
        if (convert_boxes && (boxmap_get (convert_boxes , i ) ) )
          cp = - (cp + 1 ) ; 
        FUNCCALL(SETUP_XfOrM120(_), scheme_hash_set (captured , ((Scheme_Object * ) (void * ) (long ) ((((long ) (closure_map [i ] ) ) << 1 ) | 0x1 ) ) , ((Scheme_Object * ) (void * ) (long ) ((((long ) (cp ) ) << 1 ) | 0x1 ) ) ) ); 
      }
    }
    lifted = (((Scheme_Simple_Object * ) (lifteds ) ) -> u . pair_val . car ) ; 
    vec = (((Scheme_Simple_Object * ) (lifted ) ) -> u . pair_val . cdr ) ; 
    cnt = (((Scheme_Vector * ) (vec ) ) -> size ) ; 
    -- cnt ; 
    for (j = 0 ; j < cnt ; j ++ ) {
#     define XfOrM115_COUNT (0+XfOrM111_COUNT)
#     define SETUP_XfOrM115(x) SETUP_XfOrM111(x)
      loc = (((Scheme_Vector * ) (vec ) ) -> els ) [j + 1 ] ; 
      if (((Scheme_Type ) (((((long ) (loc ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (loc ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) {
        loc = (((Scheme_Small_Object * ) (loc ) ) -> u . ptr_val ) ; 
        boxed = 1 ; 
      }
      else boxed = 0 ; 
      i = (((Scheme_Local * ) (loc ) ) -> position ) ; 
      if (! FUNCCALL(SETUP_XfOrM115(_), scheme_hash_get (captured , ((Scheme_Object * ) (void * ) (long ) ((((long ) (i ) ) << 1 ) | 0x1 ) ) ) )) {
        int cp ; 
#       define XfOrM116_COUNT (0+XfOrM115_COUNT)
#       define SETUP_XfOrM116(x) SETUP_XfOrM115(x)
        cp = captured -> count ; 
        if (boxed )
          cp = - (cp + 1 ) ; 
        FUNCCALL(SETUP_XfOrM116(_), scheme_hash_set (captured , ((Scheme_Object * ) (void * ) (long ) ((((long ) (i ) ) << 1 ) | 0x1 ) ) , ((Scheme_Object * ) (void * ) (long ) ((((long ) (cp ) ) << 1 ) | 0x1 ) ) ) ); 
      }
    }
    lifteds = (((Scheme_Simple_Object * ) (lifteds ) ) -> u . pair_val . cdr ) ; 
  }
  if (captured && (captured -> count > offset ) ) {
    int old_pos , j ; 
#   define XfOrM94_COUNT (0+XfOrM49_COUNT)
#   define SETUP_XfOrM94(x) SETUP_XfOrM49(x)
    closure_map = (mzshort * ) FUNCCALL(SETUP_XfOrM94(_), GC_malloc_atomic (sizeof (mzshort ) * (captured -> count + (has_tl ? 1 : 0 ) ) ) ); 
    offset = captured -> count ; 
    convert_boxes = ((void * ) 0 ) ; 
    for (j = captured -> size ; j -- ; ) {
#     define XfOrM98_COUNT (0+XfOrM94_COUNT)
#     define SETUP_XfOrM98(x) SETUP_XfOrM94(x)
      if (captured -> vals [j ] ) {
        int cp ; 
#       define XfOrM99_COUNT (0+XfOrM98_COUNT)
#       define SETUP_XfOrM99(x) SETUP_XfOrM98(x)
        cp = (((long ) (captured -> vals [j ] ) ) >> 1 ) ; 
        old_pos = (((long ) (captured -> keys [j ] ) ) >> 1 ) ; 
        if (cp < 0 ) {
#         define XfOrM100_COUNT (0+XfOrM99_COUNT)
#         define SETUP_XfOrM100(x) SETUP_XfOrM99(x)
          cp = - (cp + 1 ) ; 
          if (! convert_boxes )
            convert_boxes = FUNCCALL(SETUP_XfOrM100(_), allocate_boxmap (offset ) ); 
          (boxmap_set (convert_boxes , cp ) ) ; 
        }
        closure_map [cp ] = old_pos ; 
      }
    }
  }
  if (convert && (offset || ! has_tl ) ) {
    int new_boxes_size ; 
#   define XfOrM91_COUNT (0+XfOrM49_COUNT)
#   define SETUP_XfOrM91(x) SETUP_XfOrM49(x)
    convert_map = closure_map ; 
    convert_size = offset ; 
    if (convert_boxes )
      new_boxes_size = (boxmap_size (convert_size + data -> num_params ) ) ; 
    else new_boxes_size = 0 ; 
    if (has_tl || convert_boxes ) {
      int sz ; 
#     define XfOrM92_COUNT (0+XfOrM91_COUNT)
#     define SETUP_XfOrM92(x) SETUP_XfOrM91(x)
      sz = ((has_tl ? sizeof (mzshort ) : 0 ) + new_boxes_size * sizeof (mzshort ) ) ; 
      closure_map = (mzshort * ) FUNCCALL(SETUP_XfOrM92(_), GC_malloc_atomic (sz ) ); 
      (memset (closure_map , 0 , sz ) ) ; 
      if (convert_boxes ) {
        int bsz ; 
#       define XfOrM93_COUNT (0+XfOrM92_COUNT)
#       define SETUP_XfOrM93(x) SETUP_XfOrM92(x)
        bsz = (boxmap_size (convert_size ) ) ; 
        (memcpy (closure_map XFORM_OK_PLUS (has_tl ? 1 : 0 ) , convert_boxes , bsz * sizeof (mzshort ) ) ) ; 
      }
    }
    else closure_map = ((void * ) 0 ) ; 
    offset = 0 ; 
  }
  else {
    convert = 0 ; 
    convert_map = ((void * ) 0 ) ; 
    convert_size = 0 ; 
    convert_boxes = ((void * ) 0 ) ; 
  }
  if (has_tl ) {
    int li ; 
#   define XfOrM89_COUNT (0+XfOrM49_COUNT)
#   define SETUP_XfOrM89(x) SETUP_XfOrM49(x)
    li = FUNCCALL(SETUP_XfOrM89(_), scheme_resolve_toplevel_pos (info ) ); 
    closure_map [offset ] = li ; 
    offset ++ ; 
  }
  closure_size = offset ; 
  if (! just_compute_lift ) {
    data -> closure_size = closure_size ; 
    if (convert && convert_boxes )
      (& (data ) -> iso ) -> so . keyex |= 2 ; 
  }
  np = num_params = data -> num_params ; 
  if ((data -> num_params == 1 ) && ((& (data ) -> iso ) -> so . keyex & 1 ) && ! (cl -> local_flags [0 ] & 0x1 ) && ! convert ) {
#   define XfOrM87_COUNT (0+XfOrM49_COUNT)
#   define SETUP_XfOrM87(x) SETUP_XfOrM49(x)
    new_info = FUNCCALL(SETUP_XfOrM87(_), scheme_resolve_info_extend (info , 0 , 1 , cl -> base_closure_size ) ); 
    num_params = 0 ; 
    if (! just_compute_lift )
      data -> num_params = 0 ; 
  }
  else {
#   define XfOrM84_COUNT (0+XfOrM49_COUNT)
#   define SETUP_XfOrM84(x) SETUP_XfOrM49(x)
    new_info = FUNCCALL(SETUP_XfOrM84(_), scheme_resolve_info_extend (info , data -> num_params , data -> num_params , cl -> base_closure_size + data -> num_params ) ); 
    for (i = 0 ; i < data -> num_params ; i ++ ) {
#     define XfOrM86_COUNT (0+XfOrM84_COUNT)
#     define SETUP_XfOrM86(x) SETUP_XfOrM84(x)
      FUNCCALL(SETUP_XfOrM86(_), scheme_resolve_info_add_mapping (new_info , i , i + closure_size + convert_size , ((cl -> local_flags [i ] & 0x2 ) ? 1 : 0 ) , ((void * ) 0 ) ) ); 
    }
  }
  if (has_tl && convert ) {
    offset = 1 ; 
  }
  else {
    offset = 0 ; 
  }
  for (i = 0 ; i < cl -> base_closure_size ; i ++ ) {
    int p = oldpos [i ] , flags ; 
#   define XfOrM76_COUNT (0+XfOrM49_COUNT)
#   define SETUP_XfOrM76(x) SETUP_XfOrM49(x)
    if (p < 0 )
      p -= np ; 
    else p += np ; 
    flags = FUNCCALL(SETUP_XfOrM76(_), scheme_resolve_info_flags (info , oldpos [i ] , & lifted ) ); 
    if (lifted && ((Scheme_Type ) (((((long ) (lifted ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lifted ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ) {
      Scheme_Object * vec , * loc , * * ca ; 
      mzshort * cmap , * boxmap = ((void * ) 0 ) ; 
      int sz , j , cp ; 
      BLOCK_SETUP((PUSH(boxmap, 0+XfOrM76_COUNT), PUSH(loc, 1+XfOrM76_COUNT), PUSH(cmap, 2+XfOrM76_COUNT), PUSH(ca, 3+XfOrM76_COUNT), PUSH(vec, 4+XfOrM76_COUNT)));
#     define XfOrM77_COUNT (5+XfOrM76_COUNT)
#     define SETUP_XfOrM77(x) SETUP(XfOrM77_COUNT)
      vec = NULLED_OUT ; 
      loc = NULLED_OUT ; 
      ca = NULLED_OUT ; 
      cmap = NULLED_OUT ; 
      vec = (((Scheme_Simple_Object * ) (lifted ) ) -> u . pair_val . cdr ) ; 
      sz = (((Scheme_Vector * ) (vec ) ) -> size ) ; 
      -- sz ; 
      cmap = ((mzshort * ) FUNCCALL(SETUP_XfOrM77(_), GC_malloc_atomic (sizeof (mzshort ) * (sz ) ) )) ; 
      for (j = 0 ; j < sz ; j ++ ) {
#       define XfOrM80_COUNT (0+XfOrM77_COUNT)
#       define SETUP_XfOrM80(x) SETUP_XfOrM77(x)
        loc = (((Scheme_Vector * ) (vec ) ) -> els ) [j + 1 ] ; 
        if (((Scheme_Type ) (((((long ) (loc ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (loc ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) {
#         define XfOrM81_COUNT (0+XfOrM80_COUNT)
#         define SETUP_XfOrM81(x) SETUP_XfOrM80(x)
          if (! boxmap )
            boxmap = FUNCCALL(SETUP_XfOrM81(_), allocate_boxmap (sz ) ); 
          (boxmap_set (boxmap , j ) ) ; 
          loc = (((Scheme_Small_Object * ) (loc ) ) -> u . ptr_val ) ; 
        }
        loc = FUNCCALL(SETUP_XfOrM80(_), scheme_hash_get (captured , ((Scheme_Object * ) (void * ) (long ) ((((long ) ((((Scheme_Local * ) (loc ) ) -> position ) ) ) << 1 ) | 0x1 ) ) ) ); 
        cp = (((long ) (loc ) ) >> 1 ) ; 
        if (cp < 0 )
          cp = - (cp + 1 ) ; 
        cmap [j ] = cp + (has_tl && convert ? 1 : 0 ) ; 
      }
      ca = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM77(_), GC_malloc (sizeof (Scheme_Object * ) * (4 ) ) )) ; 
      ca [0 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (sz ) ) << 1 ) | 0x1 ) ) ; 
      ca [1 ] = (Scheme_Object * ) cmap ; 
      ca [2 ] = (((Scheme_Vector * ) (vec ) ) -> els ) [0 ] ; 
      ca [3 ] = (Scheme_Object * ) boxmap ; 
      lifted = FUNCCALL(SETUP_XfOrM77(_), scheme_make_raw_pair ((((Scheme_Simple_Object * ) (lifted ) ) -> u . pair_val . car ) , (Scheme_Object * ) ca ) ); 
    }
    FUNCCALL(SETUP_XfOrM76(_), scheme_resolve_info_add_mapping (new_info , p , lifted ? 0 : offset ++ , flags , lifted ) ); 
  }
  if (has_tl ) {
#   define XfOrM69_COUNT (0+XfOrM49_COUNT)
#   define SETUP_XfOrM69(x) SETUP_XfOrM49(x)
    if (convert )
      offset = 0 ; 
    else offset = closure_size - 1 ; 
    FUNCCALL(SETUP_XfOrM69(_), scheme_resolve_info_set_toplevel_pos (new_info , offset ) ); 
  }
  if (! just_compute_lift )
    data -> closure_map = closure_map ; 
  new_info -> in_proc = 1 ; 
  if (! just_compute_lift ) {
    Scheme_Object * code ; 
    BLOCK_SETUP((PUSH(code, 0+XfOrM49_COUNT)));
#   define XfOrM64_COUNT (1+XfOrM49_COUNT)
#   define SETUP_XfOrM64(x) SETUP(XfOrM64_COUNT)
    code = NULLED_OUT ; 
    code = FUNCCALL(SETUP_XfOrM64(_), scheme_resolve_expr (data -> code , new_info ) ); 
    data -> code = code ; 
    data -> max_let_depth = (new_info -> max_let_depth + num_params + closure_size + convert_size + 5 ) ; 
    for (i = 0 ; i < num_params ; i ++ ) {
#     define XfOrM67_COUNT (0+XfOrM64_COUNT)
#     define SETUP_XfOrM67(x) SETUP_XfOrM64(x)
      if (cl -> local_flags [i ] & 0x2 ) {
        int j = i + closure_size + convert_size ; 
        Scheme_Object * bcode ; 
        BLOCK_SETUP((PUSH(bcode, 0+XfOrM67_COUNT)));
#       define XfOrM68_COUNT (1+XfOrM67_COUNT)
#       define SETUP_XfOrM68(x) SETUP(XfOrM68_COUNT)
        bcode = NULLED_OUT ; 
        bcode = (__funcarg46 = FUNCCALL(SETUP_XfOrM68(_), scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (j ) ) << 1 ) | 0x1 ) ) , data -> code ) ), FUNCCALL_AGAIN(scheme_make_syntax_resolved (5 , __funcarg46 ) )) ; 
        data -> code = bcode ; 
      }
    }
    if (((((long ) (data -> code ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (data -> code ) ) -> type ) > _scheme_compiled_values_types_ )
      (& (data ) -> iso ) -> so . keyex |= 8 ; 
  }
  if ((closure_size == 1 ) && can_lift && has_tl && info -> lifts ) {
    need_lift = 1 ; 
  }
  else need_lift = 0 ; 
  if (convert ) {
    num_params += convert_size ; 
    if (! just_compute_lift )
      data -> num_params = num_params ; 
  }
  if (! closure_size ) {
#   define XfOrM59_COUNT (0+XfOrM49_COUNT)
#   define SETUP_XfOrM59(x) SETUP_XfOrM49(x)
    if (precomputed_lift ) {
      result = (((Scheme_Simple_Object * ) (precomputed_lift ) ) -> u . pair_val . car ) ; 
      if (! just_compute_lift )
        ((Scheme_Closure * ) result ) -> code = data ; 
    }
    else {
#     define XfOrM60_COUNT (0+XfOrM59_COUNT)
#     define SETUP_XfOrM60(x) SETUP_XfOrM59(x)
      if (just_compute_lift )
        result = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM60(_), scheme_malloc_empty_closure () ); 
      else result = FUNCCALL(SETUP_XfOrM60(_), scheme_make_closure (((void * ) 0 ) , (Scheme_Object * ) data , 0 ) ); 
    }
  }
  else result = (Scheme_Object * ) data ; 
  if (need_lift ) {
#   define XfOrM54_COUNT (0+XfOrM49_COUNT)
#   define SETUP_XfOrM54(x) SETUP_XfOrM49(x)
    if (just_compute_lift ) {
#     define XfOrM58_COUNT (0+XfOrM54_COUNT)
#     define SETUP_XfOrM58(x) SETUP_XfOrM54(x)
      if (just_compute_lift > 1 )
        result = FUNCCALL(SETUP_XfOrM58(_), scheme_resolve_invent_toplevel (info ) ); 
      else result = FUNCCALL(SETUP_XfOrM58(_), scheme_resolve_generate_stub_lift () ); 
    }
    else {
      Scheme_Object * tl , * defn_tl ; 
      BLOCK_SETUP((PUSH(tl, 0+XfOrM54_COUNT), PUSH(defn_tl, 1+XfOrM54_COUNT)));
#     define XfOrM55_COUNT (2+XfOrM54_COUNT)
#     define SETUP_XfOrM55(x) SETUP(XfOrM55_COUNT)
      tl = NULLED_OUT ; 
      defn_tl = NULLED_OUT ; 
      if (precomputed_lift ) {
        tl = precomputed_lift ; 
        if (((Scheme_Type ) (((((long ) (tl ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (tl ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) )
          tl = (((Scheme_Simple_Object * ) (tl ) ) -> u . pair_val . car ) ; 
      }
      else {
#       define XfOrM56_COUNT (0+XfOrM55_COUNT)
#       define SETUP_XfOrM56(x) SETUP_XfOrM55(x)
        tl = FUNCCALL(SETUP_XfOrM56(_), scheme_resolve_invent_toplevel (info ) ); 
      }
      defn_tl = FUNCCALL(SETUP_XfOrM55(_), scheme_resolve_invented_toplevel_to_defn (info , tl ) ); 
      FUNCCALL(SETUP_XfOrM55(_), scheme_resolve_lift_definition (info , defn_tl , result ) ); 
      if (has_tl )
        closure_map [0 ] = 0 ; 
      result = tl ; 
    }
  }
  if (convert ) {
    Scheme_Object * * ca , * arity ; 
    BLOCK_SETUP((PUSH(arity, 0+XfOrM49_COUNT), PUSH(ca, 1+XfOrM49_COUNT)));
#   define XfOrM50_COUNT (2+XfOrM49_COUNT)
#   define SETUP_XfOrM50(x) SETUP(XfOrM50_COUNT)
    ca = NULLED_OUT ; 
    arity = NULLED_OUT ; 
    if (((& (data ) -> iso ) -> so . keyex & 1 ) ) {
#     define XfOrM53_COUNT (0+XfOrM50_COUNT)
#     define SETUP_XfOrM53(x) SETUP_XfOrM50(x)
      arity = FUNCCALL(SETUP_XfOrM53(_), scheme_box (((Scheme_Object * ) (void * ) (long ) ((((long ) (num_params - convert_size - 1 ) ) << 1 ) | 0x1 ) ) ) ); 
    }
    else {
      arity = ((Scheme_Object * ) (void * ) (long ) ((((long ) (num_params - convert_size ) ) << 1 ) | 0x1 ) ) ; 
    }
    ca = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM50(_), GC_malloc (sizeof (Scheme_Object * ) * (4 ) ) )) ; 
    ca [0 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (convert_size ) ) << 1 ) | 0x1 ) ) ; 
    ca [1 ] = (Scheme_Object * ) convert_map ; 
    ca [2 ] = arity ; 
    ca [3 ] = (Scheme_Object * ) convert_boxes ; 
    if (precomputed_lift ) {
      (((Scheme_Simple_Object * ) (precomputed_lift ) ) -> u . pair_val . car ) = result ; 
      (((Scheme_Simple_Object * ) (precomputed_lift ) ) -> u . pair_val . cdr ) = (Scheme_Object * ) ca ; 
      result = precomputed_lift ; 
    }
    else result = FUNCCALL(SETUP_XfOrM50(_), scheme_make_raw_pair (result , (Scheme_Object * ) ca ) ); 
  }
  RET_VALUE_START (result ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 1473 */
Scheme_Object * scheme_source_to_name (Scheme_Object * code ) {
  Scheme_Stx * cstx = (Scheme_Stx * ) code ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(1);
# define XfOrM135_COUNT (0)
# define SETUP_XfOrM135(x) SETUP(XfOrM135_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((cstx -> srcloc -> col >= 0 ) || (cstx -> srcloc -> pos >= 0 ) ) {
    char buf [50 ] , src [20 ] ; 
    Scheme_Object * name ; 
    BLOCK_SETUP((PUSH(name, 0+XfOrM135_COUNT)));
#   define XfOrM136_COUNT (1+XfOrM135_COUNT)
#   define SETUP_XfOrM136(x) SETUP(XfOrM136_COUNT)
    name = NULLED_OUT ; 
    if (cstx -> srcloc -> src && ((Scheme_Type ) (((((long ) (cstx -> srcloc -> src ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (cstx -> srcloc -> src ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) {
#     define XfOrM140_COUNT (0+XfOrM136_COUNT)
#     define SETUP_XfOrM140(x) SETUP_XfOrM136(x)
      if ((((Scheme_Simple_Object * ) (cstx -> srcloc -> src ) ) -> u . byte_str_val . tag_val ) < 20 )
        (memcpy (src , (((Scheme_Simple_Object * ) (cstx -> srcloc -> src ) ) -> u . byte_str_val . string_val ) , (((Scheme_Simple_Object * ) (cstx -> srcloc -> src ) ) -> u . byte_str_val . tag_val ) + 1 ) ) ; 
      else {
#       define XfOrM141_COUNT (0+XfOrM140_COUNT)
#       define SETUP_XfOrM141(x) SETUP_XfOrM140(x)
        (memcpy (src , (((Scheme_Simple_Object * ) (cstx -> srcloc -> src ) ) -> u . byte_str_val . string_val ) + (((Scheme_Simple_Object * ) (cstx -> srcloc -> src ) ) -> u . byte_str_val . tag_val ) - 19 , 20 ) ) ; 
        src [0 ] = '.' ; 
        src [1 ] = '.' ; 
        src [2 ] = '.' ; 
      }
    }
    else {
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    if (cstx -> srcloc -> line >= 0 ) {
#     define XfOrM138_COUNT (0+XfOrM136_COUNT)
#     define SETUP_XfOrM138(x) SETUP_XfOrM136(x)
      (sprintf (buf , "%s%s%ld:%ld" , src , (src [0 ] ? ":" : "" ) , cstx -> srcloc -> line , cstx -> srcloc -> col - 1 ) ) ; 
    }
    else {
#     define XfOrM137_COUNT (0+XfOrM136_COUNT)
#     define SETUP_XfOrM137(x) SETUP_XfOrM136(x)
      (sprintf (buf , "%s%s%ld" , src , (src [0 ] ? "::" : "" ) , cstx -> srcloc -> pos ) ) ; 
    }
    name = FUNCCALL(SETUP_XfOrM136(_), scheme_intern_exact_symbol (buf , strlen (buf ) ) ); 
    RET_VALUE_START (name ) RET_VALUE_END ; 
  }
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * combine_name_with_srcloc (Scheme_Object * name , Scheme_Object * code , int src_based_name ) {
  Scheme_Stx * cstx = (Scheme_Stx * ) code ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(name, 0), PUSH(cstx, 1)));
# define XfOrM142_COUNT (2)
# define SETUP_XfOrM142(x) SETUP(XfOrM142_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (((cstx -> srcloc -> col >= 0 ) || (cstx -> srcloc -> pos >= 0 ) ) && cstx -> srcloc -> src ) {
    Scheme_Object * vec ; 
    BLOCK_SETUP((PUSH(vec, 0+XfOrM142_COUNT)));
#   define XfOrM143_COUNT (1+XfOrM142_COUNT)
#   define SETUP_XfOrM143(x) SETUP(XfOrM143_COUNT)
    vec = NULLED_OUT ; 
    vec = FUNCCALL(SETUP_XfOrM143(_), scheme_make_vector (7 , ((void * ) 0 ) ) ); 
    (((Scheme_Vector * ) (vec ) ) -> els ) [0 ] = name ; 
    (((Scheme_Vector * ) (vec ) ) -> els ) [1 ] = cstx -> srcloc -> src ; 
    if (cstx -> srcloc -> line >= 0 ) {
      (((Scheme_Vector * ) (vec ) ) -> els ) [2 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (cstx -> srcloc -> line ) ) << 1 ) | 0x1 ) ) ; 
      (((Scheme_Vector * ) (vec ) ) -> els ) [3 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (cstx -> srcloc -> col - 1 ) ) << 1 ) | 0x1 ) ) ; 
    }
    else {
      (((Scheme_Vector * ) (vec ) ) -> els ) [2 ] = scheme_false ; 
      (((Scheme_Vector * ) (vec ) ) -> els ) [3 ] = scheme_false ; 
    }
    if (cstx -> srcloc -> pos >= 0 )
      (((Scheme_Vector * ) (vec ) ) -> els ) [4 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (cstx -> srcloc -> pos ) ) << 1 ) | 0x1 ) ) ; 
    else (((Scheme_Vector * ) (vec ) ) -> els ) [4 ] = scheme_false ; 
    if (cstx -> srcloc -> span >= 0 )
      (((Scheme_Vector * ) (vec ) ) -> els ) [5 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (cstx -> srcloc -> span ) ) << 1 ) | 0x1 ) ) ; 
    else (((Scheme_Vector * ) (vec ) ) -> els ) [5 ] = scheme_false ; 
    (((Scheme_Vector * ) (vec ) ) -> els ) [6 ] = (src_based_name ? scheme_true : scheme_false ) ; 
    RET_VALUE_START (vec ) RET_VALUE_END ; 
  }
  RET_VALUE_START (name ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_build_closure_name (Scheme_Object * code , Scheme_Compile_Info * rec , int drec ) {
  Scheme_Object * name ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(name, 0), PUSH(code, 1), PUSH(rec, 2)));
# define XfOrM146_COUNT (3)
# define SETUP_XfOrM146(x) SETUP(XfOrM146_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  name = NULLED_OUT ; 
  name = FUNCCALL(SETUP_XfOrM146(_), scheme_stx_property (code , scheme_inferred_name_symbol , ((void * ) 0 ) ) ); 
  if (name && ((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
#   define XfOrM150_COUNT (0+XfOrM146_COUNT)
#   define SETUP_XfOrM150(x) SETUP_XfOrM146(x)
    name = FUNCCALL(SETUP_XfOrM150(_), combine_name_with_srcloc (name , code , 0 ) ); 
  }
  else {
#   define XfOrM147_COUNT (0+XfOrM146_COUNT)
#   define SETUP_XfOrM147(x) SETUP_XfOrM146(x)
    name = rec [drec ] . value_name ; 
    if (! name || (((name ) ) == (scheme_false ) ) ) {
#     define XfOrM149_COUNT (0+XfOrM147_COUNT)
#     define SETUP_XfOrM149(x) SETUP_XfOrM147(x)
      name = FUNCCALL(SETUP_XfOrM149(_), scheme_source_to_name (code ) ); 
      if (name )
        name = FUNCCALL(SETUP_XfOrM149(_), combine_name_with_srcloc (name , code , 1 ) ); 
    }
    else {
#     define XfOrM148_COUNT (0+XfOrM147_COUNT)
#     define SETUP_XfOrM148(x) SETUP_XfOrM147(x)
      name = FUNCCALL(SETUP_XfOrM148(_), combine_name_with_srcloc (name , code , 0 ) ); 
    }
  }
  RET_VALUE_START (name ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_closure_compilation (Scheme_Comp_Env * env , Scheme_Object * code , Scheme_Compile_Info * rec , int drec ) {
  Scheme_Object * allparams , * params , * forms , * param , * name ; 
  Scheme_Closure_Data * data ; 
  Scheme_Compile_Info lam ; 
  Scheme_Comp_Env * frame ; 
  int i ; 
  long num_params ; 
  Closure_Info * cl ; 
  Scheme_Comp_Env * __funcarg47 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(15);
  BLOCK_SETUP_TOP((PUSH(forms, 0), PUSH(params, 1), PUSH(lam.value_name, 2), PUSH(lam.certs, 3), PUSH(lam.observer, 4), PUSH(code, 5), PUSH(env, 6), PUSH(name, 7), PUSH(frame, 8), PUSH(data, 9), PUSH(param, 10), PUSH(rec, 11), PUSH(cl, 12), PUSH(allparams, 13)));
# define XfOrM151_COUNT (14)
# define SETUP_XfOrM151(x) SETUP(XfOrM151_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  allparams = NULLED_OUT ; 
  params = NULLED_OUT ; 
  forms = NULLED_OUT ; 
  param = NULLED_OUT ; 
  name = NULLED_OUT ; 
  data = NULLED_OUT ; 
  lam.value_name = NULLED_OUT ; 
  lam.certs = NULLED_OUT ; 
  lam.observer = NULLED_OUT ; 
  frame = NULLED_OUT ; 
  cl = NULLED_OUT ; 
  data = ((Scheme_Closure_Data * ) FUNCCALL(SETUP_XfOrM151(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Closure_Data ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  data -> iso . so . type = scheme_compiled_unclosed_procedure_type ; 
  params = (((Scheme_Type ) (((((long ) (code ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (code ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (code ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM151(_), scheme_stx_content (code ) )) ) -> u . pair_val . cdr ) ) ; 
  params = (((Scheme_Type ) (((((long ) (params ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (params ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (params ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM151(_), scheme_stx_content (params ) )) ) -> u . pair_val . car ) ) ; 
  allparams = params ; 
  num_params = 0 ; 
  for (; (((Scheme_Type ) (((((long ) (params ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (params ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (params ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (params ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) params ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) params ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ; params = (((Scheme_Type ) (((((long ) (params ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (params ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (params ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM151(_), scheme_stx_content (params ) )) ) -> u . pair_val . cdr ) ) ) {
    num_params ++ ; 
  }
  (& (data ) -> iso ) -> so . keyex = 0 ; 
  if (! (((params ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (params ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (params ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) params ) -> val ) == (scheme_null ) ) ) ) ) {
    (& (data ) -> iso ) -> so . keyex |= 1 ; 
    num_params ++ ; 
  }
  data -> num_params = num_params ; 
  if ((data -> num_params > 0 ) && FUNCCALL(SETUP_XfOrM151(_), scheme_has_method_property (code ) ))
    (& (data ) -> iso ) -> so . keyex |= 16 ; 
  forms = (((Scheme_Type ) (((((long ) (code ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (code ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (code ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM151(_), scheme_stx_content (code ) )) ) -> u . pair_val . cdr ) ) ; 
  forms = (((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (forms ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM151(_), scheme_stx_content (forms ) )) ) -> u . pair_val . cdr ) ) ; 
  frame = FUNCCALL(SETUP_XfOrM151(_), scheme_new_compilation_frame (data -> num_params , 8 , env , rec [drec ] . certs ) ); 
  params = allparams ; 
  for (i = 0 ; i < data -> num_params ; i ++ ) {
#   define XfOrM155_COUNT (0+XfOrM151_COUNT)
#   define SETUP_XfOrM155(x) SETUP_XfOrM151(x)
    if (! (((Scheme_Type ) (((((long ) (params ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (params ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (params ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (params ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) params ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) params ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
      param = params ; 
    else param = (((Scheme_Type ) (((((long ) (params ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (params ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (params ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM155(_), scheme_stx_content (params ) )) ) -> u . pair_val . car ) ) ; 
    FUNCCALL(SETUP_XfOrM155(_), scheme_add_compilation_binding (i , param , frame ) ); 
    if ((((Scheme_Type ) (((((long ) (params ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (params ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (params ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (params ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) params ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) params ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
      params = (((Scheme_Type ) (((((long ) (params ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (params ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (params ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM155(_), scheme_stx_content (params ) )) ) -> u . pair_val . cdr ) ) ; 
  }
  if ((((forms ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) forms ) -> val ) == (scheme_null ) ) ) ) )
    FUNCCALL(SETUP_XfOrM151(_), scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , code , "bad syntax (empty body)" ) ); 
  forms = FUNCCALL(SETUP_XfOrM151(_), scheme_datum_to_syntax (forms , code , code , 0 , 0 ) ); 
  forms = FUNCCALL_AGAIN(scheme_add_env_renames (forms , frame , env ) ); 
  name = FUNCCALL_AGAIN(scheme_build_closure_name (code , rec , drec ) ); 
  data -> name = name ; 
  FUNCCALL(SETUP_XfOrM151(_), scheme_compile_rec_done_local (rec , drec ) ); 
  FUNCCALL_AGAIN(scheme_init_lambda_rec (rec , drec , & lam , 0 ) ); 
  {
    Scheme_Object * datacode ; 
    BLOCK_SETUP((PUSH(datacode, 0+XfOrM151_COUNT)));
#   define XfOrM153_COUNT (1+XfOrM151_COUNT)
#   define SETUP_XfOrM153(x) SETUP(XfOrM153_COUNT)
    datacode = NULLED_OUT ; 
    datacode = (__funcarg47 = FUNCCALL(SETUP_XfOrM153(_), scheme_no_defines (frame ) ), FUNCCALL_AGAIN(scheme_compile_sequence (forms , __funcarg47 , & lam , 0 ) )) ; 
    data -> code = datacode ; 
  }
  FUNCCALL(SETUP_XfOrM151(_), scheme_merge_lambda_rec (rec , drec , & lam , 0 ) ); 
  cl = ((Closure_Info * ) FUNCCALL(SETUP_XfOrM151(_), GC_malloc_one_small_tagged ((((sizeof (Closure_Info ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  cl -> type = scheme_rt_closure_info ; 
  {
    int * local_flags ; 
    BLOCK_SETUP((PUSH(local_flags, 0+XfOrM151_COUNT)));
#   define XfOrM152_COUNT (1+XfOrM151_COUNT)
#   define SETUP_XfOrM152(x) SETUP(XfOrM152_COUNT)
    local_flags = NULLED_OUT ; 
    local_flags = FUNCCALL(SETUP_XfOrM152(_), scheme_env_get_flags (frame , 0 , data -> num_params ) ); 
    cl -> local_flags = local_flags ; 
  }
  data -> closure_map = (mzshort * ) cl ; 
  RET_VALUE_START ((Scheme_Object * ) data ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void initialize_prompt (Scheme_Thread * p , Scheme_Prompt * prompt , void * stack_boundary ) {
  /* No conversion */
  prompt -> is_barrier = 0 ; 
  prompt -> stack_boundary = stack_boundary ; 
  prompt -> runstack_boundary_start = scheme_current_runstack_start ; 
  prompt -> runstack_boundary_offset = (scheme_current_runstack - scheme_current_runstack_start ) ; 
  prompt -> mark_boundary = scheme_current_cont_mark_stack ; 
  prompt -> boundary_mark_pos = scheme_current_cont_mark_pos ; 
}
typedef Scheme_Object * (* Overflow_K_Proc ) (void ) ; 
Scheme_Overflow_Jmp * scheme_overflow_jmp ; 
void * scheme_overflow_stack_start ; 
void scheme_really_create_overflow (void * stack_base ) {
  Scheme_Overflow_Jmp * jmp ; 
  PREPARE_VAR_STACK(10);
  BLOCK_SETUP_TOP((PUSH(jmp, 0), PUSH(stack_base, 1)));
# define XfOrM160_COUNT (2)
# define SETUP_XfOrM160(x) SETUP(XfOrM160_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  jmp = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM160(_), scheme_ensure_stack_start (stack_base ) ); 
  if (scheme_overflow_jmp )
    RET_NOTHING ; 
  scheme_overflow_stack_start = stack_base ; 
  jmp = ((Scheme_Overflow_Jmp * ) FUNCCALL(SETUP_XfOrM160(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Overflow_Jmp ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  jmp -> type = scheme_rt_overflow_jmp ; 
  FUNCCALL(SETUP_XfOrM160(_), scheme_init_jmpup_buf (& jmp -> cont ) ); 
  if (FUNCCALL(SETUP_XfOrM160(_), scheme_setjmpup_relative (& jmp -> cont , jmp , stack_base , ((void * ) 0 ) ) )) {
    Scheme_Thread * volatile p ; 
    Scheme_Overflow * volatile overflow ; 
    mz_jmp_buf nestedbuf ; 
    BLOCK_SETUP((PUSH(overflow, 0+XfOrM160_COUNT), PUSH(p, 1+XfOrM160_COUNT)));
#   define XfOrM162_COUNT (2+XfOrM160_COUNT)
#   define SETUP_XfOrM162(x) SETUP(XfOrM162_COUNT)
    p = NULLED_OUT ; 
    overflow = NULLED_OUT ; 
    p = scheme_current_thread ; 
    overflow = p -> overflow ; 
    overflow -> jmp -> savebuf = p -> error_buf ; 
    p -> error_buf = & nestedbuf ; 
    if (((nestedbuf ) . gcvs = (long ) __gc_var_stack__ , (nestedbuf ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((nestedbuf ) . jb ) , (_setjmp (((nestedbuf ) . jb ) -> jb ) ) ) ) ) {
      p = scheme_current_thread ; 
      p -> overflow_reply = ((void * ) 0 ) ; 
    }
    else {
      void * p1 , * p2 , * p3 , * p4 , * p5 ; 
      long i1 , i2 , i3 , i4 ; 
      Overflow_K_Proc f = (scheme_current_thread -> overflow_k ) ; 
      Scheme_Object * reply ; 
      BLOCK_SETUP((PUSH(p3, 0+XfOrM162_COUNT), PUSH(p5, 1+XfOrM162_COUNT), PUSH(p1, 2+XfOrM162_COUNT), PUSH(p2, 3+XfOrM162_COUNT), PUSH(p4, 4+XfOrM162_COUNT), PUSH(reply, 5+XfOrM162_COUNT)));
#     define XfOrM163_COUNT (6+XfOrM162_COUNT)
#     define SETUP_XfOrM163(x) SETUP(XfOrM163_COUNT)
      p1 = NULLED_OUT ; 
      p2 = NULLED_OUT ; 
      p3 = NULLED_OUT ; 
      p4 = NULLED_OUT ; 
      p5 = NULLED_OUT ; 
      reply = NULLED_OUT ; 
      p1 = p -> ku . k . p1 ; 
      p2 = p -> ku . k . p2 ; 
      p3 = p -> ku . k . p3 ; 
      p4 = p -> ku . k . p4 ; 
      p5 = p -> ku . k . p5 ; 
      i1 = p -> ku . k . i1 ; 
      i2 = p -> ku . k . i2 ; 
      i3 = p -> ku . k . i3 ; 
      i4 = p -> ku . k . i4 ; 
      FUNCCALL(SETUP_XfOrM163(_), scheme_thread_block (0 ) ); 
      p -> ran_some = 1 ; 
      p -> ku . k . p1 = p1 ; 
      p -> ku . k . p2 = p2 ; 
      p -> ku . k . p3 = p3 ; 
      p -> ku . k . p4 = p4 ; 
      p -> ku . k . p5 = p5 ; 
      p -> ku . k . i1 = i1 ; 
      p -> ku . k . i2 = i2 ; 
      p -> ku . k . i3 = i3 ; 
      p -> ku . k . i4 = i4 ; 
      reply = FUNCCALL(SETUP_XfOrM163(_), f () ); 
      (scheme_current_thread -> overflow_reply ) = reply ; 
    }
    p = scheme_current_thread ; 
    overflow = p -> overflow ; 
    p -> stack_start = overflow -> stack_start ; 
    FUNCCALL(SETUP_XfOrM162(_), scheme_longjmpup (& overflow -> jmp -> cont ) ); 
  }
  if (scheme_overflow_jmp ) {
#   define XfOrM161_COUNT (0+XfOrM160_COUNT)
#   define SETUP_XfOrM161(x) SETUP_XfOrM160(x)
    FUNCCALL(SETUP_XfOrM161(_), scheme_signal_error ("shouldn't get here!" ) ); 
  }
  scheme_overflow_jmp = jmp ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_create_overflow (void ) {
  void * dummy ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(dummy, 0)));
# define XfOrM165_COUNT (1)
# define SETUP_XfOrM165(x) SETUP(XfOrM165_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  dummy = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM165(_), scheme_really_create_overflow (& __gc_var_stack__ ) ); 
  dummy = ((void * ) 0 ) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_init_overflow (void ) {
  /* No conversion */
  scheme_register_static ((void * ) & scheme_overflow_jmp , sizeof (scheme_overflow_jmp ) ) ; 
}
void scheme_reset_overflow (void ) {
  /* No conversion */
  scheme_overflow_jmp = ((void * ) 0 ) ; 
}
void scheme_on_next_top (Scheme_Comp_Env * env , Scheme_Object * mark , Scheme_Object * name , Scheme_Object * certs , Scheme_Env * menv , Scheme_Object * modidx ) {
  PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(modidx, 0), PUSH(mark, 1), PUSH(certs, 2), PUSH(menv, 3), PUSH(name, 4), PUSH(env, 5)));
# define XfOrM168_COUNT (6)
# define SETUP_XfOrM168(x) SETUP(XfOrM168_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! top_next_registered ) {
#   define XfOrM169_COUNT (0+XfOrM168_COUNT)
#   define SETUP_XfOrM169(x) SETUP_XfOrM168(x)
    top_next_registered = 1 ; 
    FUNCCALL(SETUP_XfOrM169(_), scheme_register_static ((void * ) & top_next_env , sizeof (top_next_env ) ) ); 
    FUNCCALL_AGAIN(scheme_register_static ((void * ) & top_next_mark , sizeof (top_next_mark ) ) ); 
    FUNCCALL_AGAIN(scheme_register_static ((void * ) & top_next_name , sizeof (top_next_name ) ) ); 
    FUNCCALL_AGAIN(scheme_register_static ((void * ) & top_next_certs , sizeof (top_next_certs ) ) ); 
    FUNCCALL_AGAIN(scheme_register_static ((void * ) & top_next_modidx , sizeof (top_next_modidx ) ) ); 
    FUNCCALL_AGAIN(scheme_register_static ((void * ) & top_next_menv , sizeof (top_next_menv ) ) ); 
  }
  top_next_env = env ; 
  top_next_mark = mark ; 
  top_next_name = name ; 
  top_next_certs = certs ; 
  top_next_modidx = modidx ; 
  top_next_menv = menv ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void * top_level_do (void * (* k ) (void ) , int eb , void * sj_start ) {
  void * v ; 
  Scheme_Prompt * volatile prompt ; 
  volatile long save_list_stack_pos ; 
  mz_jmp_buf * save , newbuf ; 
  Scheme_Stack_State envss ; 
  Scheme_Comp_Env * volatile save_current_local_env ; 
  Scheme_Object * volatile save_mark , * volatile save_name , * volatile save_certs , * volatile save_modidx ; 
  Scheme_Env * volatile save_menv ; 
  Scheme_Simple_Object * volatile save_list_stack ; 
  Scheme_Thread * volatile p = scheme_current_thread ; 
  int thread_cc = top_next_use_thread_cc_ok ; 
  volatile int old_pcc = scheme_prompt_capture_count ; 
  Scheme_Cont_Frame_Data cframe ; 
  void * external_stack ; 
  DECL_RET_SAVE (void * ) PREPARE_VAR_STACK_ONCE(13);
  BLOCK_SETUP_TOP((PUSH(save_name, 0), PUSH(prompt, 1), PUSH(save_certs, 2), PUSH(v, 3), PUSH(save_modidx, 4), PUSH(p, 5), PUSH(save, 6), PUSH(save_menv, 7), PUSH(cframe.cache, 8), PUSH(save_current_local_env, 9), PUSH(save_mark, 10), PUSH(external_stack, 11), PUSH(save_list_stack, 12)));
# define XfOrM170_COUNT (13)
# define SETUP_XfOrM170(x) SETUP(XfOrM170_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  prompt = NULLED_OUT ; 
  save = NULLED_OUT ; 
  save_current_local_env = NULLED_OUT ; 
  save_mark = NULLED_OUT ; 
  save_name = NULLED_OUT ; 
  save_certs = NULLED_OUT ; 
  save_modidx = NULLED_OUT ; 
  save_menv = NULLED_OUT ; 
  save_list_stack = NULLED_OUT ; 
  cframe.cache = NULLED_OUT ; 
  external_stack = NULLED_OUT ; 
  top_next_use_thread_cc_ok = 0 ; 
  if (scheme_active_but_sleeping )
    FUNCCALL(SETUP_XfOrM170(_), scheme_wake_up () ); 
  if (eb ) {
#   define XfOrM182_COUNT (0+XfOrM170_COUNT)
#   define SETUP_XfOrM182(x) SETUP_XfOrM170(x)
    if (available_prompt ) {
      prompt = available_prompt ; 
      available_prompt = ((void * ) 0 ) ; 
    }
    else {
#     define XfOrM185_COUNT (0+XfOrM182_COUNT)
#     define SETUP_XfOrM185(x) SETUP_XfOrM182(x)
      prompt = ((Scheme_Prompt * ) FUNCCALL(SETUP_XfOrM185(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Prompt ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
      prompt -> so . type = scheme_prompt_type ; 
    }
    FUNCCALL(SETUP_XfOrM182(_), initialize_prompt (p , prompt , & __gc_var_stack__ ) ); 
    if (! thread_cc ) {
      prompt -> is_barrier = 1 ; 
    }
    if (! barrier_prompt_key ) {
#     define XfOrM183_COUNT (0+XfOrM182_COUNT)
#     define SETUP_XfOrM183(x) SETUP_XfOrM182(x)
      FUNCCALL(SETUP_XfOrM183(_), scheme_register_static ((void * ) & barrier_prompt_key , sizeof (barrier_prompt_key ) ) ); 
      barrier_prompt_key = FUNCCALL(SETUP_XfOrM183(_), scheme_make_symbol ("bar" ) ); 
    }
  }
  else {
    prompt = ((void * ) 0 ) ; 
  }
  if (scheme_get_external_stack_val )
    external_stack = FUNCCALL(SETUP_XfOrM170(_), scheme_get_external_stack_val () ); 
  else external_stack = ((void * ) 0 ) ; 
  (envss . runstack_offset = scheme_current_runstack - scheme_current_runstack_start , envss . cont_mark_stack = scheme_current_cont_mark_stack , envss . cont_mark_pos = scheme_current_cont_mark_pos ) ; 
  save_current_local_env = p -> current_local_env ; 
  save_mark = p -> current_local_mark ; 
  save_name = p -> current_local_name ; 
  save_certs = p -> current_local_certs ; 
  save_modidx = p -> current_local_modidx ; 
  save_menv = p -> current_local_menv ; 
  save_list_stack = p -> list_stack ; 
  save_list_stack_pos = p -> list_stack_pos ; 
  if (top_next_env ) {
    p -> current_local_env = top_next_env ; 
    p -> current_local_mark = top_next_mark ; 
    p -> current_local_name = top_next_name ; 
    p -> current_local_certs = top_next_certs ; 
    p -> current_local_modidx = top_next_modidx ; 
    p -> current_local_menv = top_next_menv ; 
    top_next_env = ((void * ) 0 ) ; 
    top_next_mark = ((void * ) 0 ) ; 
    top_next_name = ((void * ) 0 ) ; 
    top_next_certs = ((void * ) 0 ) ; 
    top_next_modidx = ((void * ) 0 ) ; 
    top_next_menv = ((void * ) 0 ) ; 
  }
  FUNCCALL(SETUP_XfOrM170(_), scheme_create_overflow () ); 
  if (prompt ) {
#   define XfOrM179_COUNT (0+XfOrM170_COUNT)
#   define SETUP_XfOrM179(x) SETUP_XfOrM170(x)
    FUNCCALL(SETUP_XfOrM179(_), scheme_push_continuation_frame (& cframe ) ); 
    FUNCCALL(SETUP_XfOrM179(_), scheme_set_cont_mark (barrier_prompt_key , (Scheme_Object * ) prompt ) ); 
  }
  save = p -> error_buf ; 
  p -> error_buf = & newbuf ; 
  if (((newbuf ) . gcvs = (long ) __gc_var_stack__ , (newbuf ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((newbuf ) . jb ) , (_setjmp (((newbuf ) . jb ) -> jb ) ) ) ) ) {
#   define XfOrM175_COUNT (0+XfOrM170_COUNT)
#   define SETUP_XfOrM175(x) SETUP_XfOrM170(x)
    if (! thread_cc ) {
#     define XfOrM176_COUNT (0+XfOrM175_COUNT)
#     define SETUP_XfOrM176(x) SETUP_XfOrM175(x)
      p = scheme_current_thread ; 
      (scheme_current_runstack = scheme_current_runstack_start + envss . runstack_offset , scheme_current_cont_mark_stack = envss . cont_mark_stack , scheme_current_cont_mark_pos = envss . cont_mark_pos ) ; 
      if (scheme_set_external_stack_val )
        FUNCCALL(SETUP_XfOrM176(_), scheme_set_external_stack_val (external_stack ) ); 
      if (prompt ) {
#       define XfOrM177_COUNT (0+XfOrM176_COUNT)
#       define SETUP_XfOrM177(x) SETUP_XfOrM176(x)
        FUNCCALL(SETUP_XfOrM177(_), scheme_pop_continuation_frame (& cframe ) ); 
        if (old_pcc == scheme_prompt_capture_count ) {
          available_prompt = prompt ; 
        }
      }
      p -> current_local_env = save_current_local_env ; 
      p -> current_local_mark = save_mark ; 
      p -> current_local_name = save_name ; 
      p -> current_local_certs = save_certs ; 
      p -> current_local_modidx = save_modidx ; 
      p -> current_local_menv = save_menv ; 
      p -> list_stack = save_list_stack ; 
      p -> list_stack_pos = save_list_stack_pos ; 
    }
    (((long * ) (void * ) ((* save ) . gcvs ) ) [1 ] = (* save ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* save ) . gcvs , scheme_jit_longjmp ((* save ) . jb , 1 ) ) ; 
  }
  if (thread_cc ) {
#   define XfOrM174_COUNT (0+XfOrM170_COUNT)
#   define SETUP_XfOrM174(x) SETUP_XfOrM170(x)
    FUNCCALL(SETUP_XfOrM174(_), scheme_check_break_now () ); 
  }
  v = FUNCCALL(SETUP_XfOrM170(_), k () ); 
  if (! thread_cc ) {
    p = scheme_current_thread ; 
    p -> current_local_env = save_current_local_env ; 
    p -> current_local_mark = save_mark ; 
    p -> current_local_name = save_name ; 
    p -> current_local_certs = save_certs ; 
    p -> current_local_modidx = save_modidx ; 
    p -> current_local_menv = save_menv ; 
    p -> error_buf = save ; 
  }
  if (prompt ) {
#   define XfOrM171_COUNT (0+XfOrM170_COUNT)
#   define SETUP_XfOrM171(x) SETUP_XfOrM170(x)
    FUNCCALL(SETUP_XfOrM171(_), scheme_pop_continuation_frame (& cframe ) ); 
    if (old_pcc == scheme_prompt_capture_count ) {
      available_prompt = prompt ; 
    }
  }
  if (scheme_active_but_sleeping )
    FUNCCALL(SETUP_XfOrM170(_), scheme_wake_up () ); 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void * scheme_top_level_do (void * (* k ) (void ) , int eb ) {
  void * sj_start ; 
  DECL_RET_SAVE (void * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(sj_start, 0)));
# define XfOrM187_COUNT (1)
# define SETUP_XfOrM187(x) SETUP(XfOrM187_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sj_start = NULLED_OUT ; 
  sj_start = (void * ) & __gc_var_stack__ ; 
  sj_start = FUNCCALL(SETUP_XfOrM187(_), top_level_do (k , eb , sj_start ) ); 
  if (0 ) {
#   define XfOrM188_COUNT (0+XfOrM187_COUNT)
#   define SETUP_XfOrM188(x) SETUP_XfOrM187(x)
    sj_start = FUNCCALL(SETUP_XfOrM188(_), GC_malloc_atomic (0 ) ); 
  }
  RET_VALUE_START (sj_start ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_clear_prompt_cache () {
  /* No conversion */
  available_prompt = ((void * ) 0 ) ; 
  available_cws_prompt = ((void * ) 0 ) ; 
  available_regular_prompt = ((void * ) 0 ) ; 
  available_prompt_dw = ((void * ) 0 ) ; 
  available_prompt_mc = ((void * ) 0 ) ; 
}
static void ensure_overflow_id (Scheme_Overflow * overflow ) {
  void * id ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(overflow, 0), PUSH(id, 1)));
# define XfOrM190_COUNT (2)
# define SETUP_XfOrM190(x) SETUP(XfOrM190_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  id = NULLED_OUT ; 
  if (! overflow -> id ) {
#   define XfOrM191_COUNT (0+XfOrM190_COUNT)
#   define SETUP_XfOrM191(x) SETUP_XfOrM190(x)
    if (overflow -> jmp ) {
      overflow -> id = overflow -> jmp ; 
    }
    else {
#     define XfOrM192_COUNT (0+XfOrM191_COUNT)
#     define SETUP_XfOrM192(x) SETUP_XfOrM191(x)
      id = FUNCCALL(SETUP_XfOrM192(_), GC_malloc_atomic (4 ) ); 
      overflow -> id = id ; 
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_ensure_dw_id (Scheme_Dynamic_Wind * dw ) {
  void * id ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(dw, 0), PUSH(id, 1)));
# define XfOrM194_COUNT (2)
# define SETUP_XfOrM194(x) SETUP(XfOrM194_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  id = NULLED_OUT ; 
  if (! dw -> id ) {
#   define XfOrM195_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM195(x) SETUP_XfOrM194(x)
    id = FUNCCALL(SETUP_XfOrM195(_), GC_malloc_atomic (4 ) ); 
    dw -> id = id ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * force_values (Scheme_Object * obj , int multi_ok ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(obj, 0)));
# define XfOrM196_COUNT (1)
# define SETUP_XfOrM196(x) SETUP(XfOrM196_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (((obj ) == (((Scheme_Object * ) 0x4 ) ) ) ) {
    Scheme_Thread * p = scheme_current_thread ; 
    GC_CAN_IGNORE Scheme_Object * rator ; 
    GC_CAN_IGNORE Scheme_Object * * rands ; 
    BLOCK_SETUP((PUSH(p, 0+XfOrM196_COUNT)));
#   define XfOrM198_COUNT (1+XfOrM196_COUNT)
#   define SETUP_XfOrM198(x) SETUP(XfOrM198_COUNT)
    if (p -> ku . apply . tail_rands == p -> tail_buffer ) {
      GC_CAN_IGNORE Scheme_Object * * tb ; 
#     define XfOrM201_COUNT (0+XfOrM198_COUNT)
#     define SETUP_XfOrM201(x) SETUP_XfOrM198(x)
      p -> tail_buffer = ((void * ) 0 ) ; 
      tb = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM201(_), GC_malloc (sizeof (Scheme_Object * ) * (p -> tail_buffer_size ) ) )) ; 
      p -> tail_buffer = tb ; 
    }
    rator = p -> ku . apply . tail_rator ; 
    rands = p -> ku . apply . tail_rands ; 
    p -> ku . apply . tail_rator = ((void * ) 0 ) ; 
    p -> ku . apply . tail_rands = ((void * ) 0 ) ; 
    if (multi_ok ) {
#     define XfOrM200_COUNT (0+XfOrM198_COUNT)
#     define SETUP_XfOrM200(x) SETUP_XfOrM198(x)
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_do_eval (rator , p -> ku . apply . tail_num_rands , rands , - 1 ) )) RET_VALUE_EMPTY_END ; 
    }
    else {
#     define XfOrM199_COUNT (0+XfOrM198_COUNT)
#     define SETUP_XfOrM199(x) SETUP_XfOrM198(x)
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_do_eval (rator , p -> ku . apply . tail_num_rands , rands , 1 ) )) RET_VALUE_EMPTY_END ; 
    }
  }
  else if (((obj ) == (((Scheme_Object * ) 0x2 ) ) ) ) {
    Scheme_Thread * p = scheme_current_thread ; 
#   define XfOrM197_COUNT (0+XfOrM196_COUNT)
#   define SETUP_XfOrM197(x) SETUP_XfOrM196(x)
    if (multi_ok )
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_do_eval (p -> ku . eval . wait_expr , - 1 , ((void * ) 0 ) , - 1 ) )) RET_VALUE_EMPTY_END ; 
    else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_do_eval (p -> ku . eval . wait_expr , - 1 , ((void * ) 0 ) , 1 ) )) RET_VALUE_EMPTY_END ; 
  }
  else if (obj )
    RET_VALUE_START (obj ) RET_VALUE_END ; 
  else RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_force_value (Scheme_Object * obj ) {
  /* No conversion */
  return force_values (obj , 1 ) ; 
}
Scheme_Object * scheme_force_one_value (Scheme_Object * obj ) {
  /* No conversion */
  return force_values (obj , 0 ) ; 
}
Scheme_Object * scheme_force_value_same_mark (Scheme_Object * obj ) {
  Scheme_Object * v ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(v, 0)));
# define XfOrM204_COUNT (1)
# define SETUP_XfOrM204(x) SETUP(XfOrM204_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  scheme_current_cont_mark_pos -= 2 ; 
  v = FUNCCALL(SETUP_XfOrM204(_), force_values (obj , 1 ) ); 
  scheme_current_cont_mark_pos += 2 ; 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_force_one_value_same_mark (Scheme_Object * obj ) {
  Scheme_Object * v ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(v, 0)));
# define XfOrM205_COUNT (1)
# define SETUP_XfOrM205(x) SETUP(XfOrM205_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  scheme_current_cont_mark_pos -= 2 ; 
  v = FUNCCALL(SETUP_XfOrM205(_), force_values (obj , 0 ) ); 
  scheme_current_cont_mark_pos += 2 ; 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void * apply_k (void ) {
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * rator ; 
  int num_rands ; 
  Scheme_Object * * rands ; 
  DECL_RET_SAVE (void * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(rands, 0), PUSH(rator, 1)));
# define XfOrM206_COUNT (2)
# define SETUP_XfOrM206(x) SETUP(XfOrM206_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  rator = NULLED_OUT ; 
  rands = NULLED_OUT ; 
  rator = (Scheme_Object * ) p -> ku . k . p1 ; 
  rands = (Scheme_Object * * ) p -> ku . k . p2 ; 
  num_rands = p -> ku . k . i1 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  p -> ku . k . p2 = ((void * ) 0 ) ; 
  if (p -> ku . k . i2 )
    RET_VALUE_START ((void * ) FUNCCALL(SETUP_XfOrM206(_), scheme_do_eval (rator , num_rands , rands , - 1 ) )) RET_VALUE_END ; 
  else RET_VALUE_START ((void * ) FUNCCALL_EMPTY(scheme_do_eval (rator , num_rands , rands , 1 ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * _apply (Scheme_Object * rator , int num_rands , Scheme_Object * * rands , int multi , int eb ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  p -> ku . k . p1 = rator ; 
  p -> ku . k . p2 = rands ; 
  p -> ku . k . i1 = num_rands ; 
  p -> ku . k . i2 = multi ; 
  return (Scheme_Object * ) scheme_top_level_do (apply_k , eb ) ; 
}
Scheme_Object * scheme_apply (Scheme_Object * rator , int num_rands , Scheme_Object * * rands ) {
  /* No conversion */
  return _apply (rator , num_rands , rands , 0 , 1 ) ; 
}
Scheme_Object * scheme_apply_multi (Scheme_Object * rator , int num_rands , Scheme_Object * * rands ) {
  /* No conversion */
  return _apply (rator , num_rands , rands , 1 , 1 ) ; 
}
Scheme_Object * scheme_apply_thread_thunk (Scheme_Object * rator ) {
  /* No conversion */
  top_next_use_thread_cc_ok = 1 ; 
  return _apply (rator , 0 , ((void * ) 0 ) , 1 , 1 ) ; 
}
Scheme_Object * scheme_apply_no_eb (Scheme_Object * rator , int num_rands , Scheme_Object * * rands ) {
  /* No conversion */
  return _apply (rator , num_rands , rands , 0 , 0 ) ; 
}
Scheme_Object * scheme_apply_multi_no_eb (Scheme_Object * rator , int num_rands , Scheme_Object * * rands ) {
  /* No conversion */
  return _apply (rator , num_rands , rands , 1 , 0 ) ; 
}
static Scheme_Object * finish_apply_with_prompt (void * _data , int argc , Scheme_Object * * argv ) {
  /* No conversion */
  void * * data = (void * * ) _data ; 
  Scheme_Object * rator , * is_multi ; 
  argv = (Scheme_Object * * ) _data ; 
  for (argc = 0 ; data [argc ] ; argc ++ ) {
  }
  rator = (Scheme_Object * ) data [argc + 1 ] ; 
  is_multi = (Scheme_Object * ) data [argc + 2 ] ; 
  if ((! (((is_multi ) ) == (scheme_false ) ) ) )
    return scheme_do_eval (rator , argc , argv , - 1 ) ; 
  else return scheme_do_eval (rator , argc , argv , 1 ) ; 
}
static Scheme_Object * do_apply_with_prompt (Scheme_Object * rator , int num_rands , Scheme_Object * * rands , int multi , int top_level ) {
  void * * a ; 
  int i ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(rands, 0), PUSH(a, 1), PUSH(rator, 2)));
# define XfOrM216_COUNT (3)
# define SETUP_XfOrM216(x) SETUP(XfOrM216_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a = NULLED_OUT ; 
  a = ((void * * ) FUNCCALL(SETUP_XfOrM216(_), GC_malloc (sizeof (void * ) * (3 + num_rands ) ) )) ; 
  for (i = 0 ; i < num_rands ; i ++ ) {
    a [i ] = rands [i ] ; 
  }
  a [num_rands ] = ((void * ) 0 ) ; 
  a [num_rands + 1 ] = rator ; 
  a [num_rands + 2 ] = (multi ? scheme_true : scheme_false ) ; 
  if (top_level ) {
#   define XfOrM218_COUNT (0+XfOrM216_COUNT)
#   define SETUP_XfOrM218(x) SETUP_XfOrM216(x)
    if (multi )
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_call_with_prompt_multi (finish_apply_with_prompt , a ) )) RET_VALUE_EMPTY_END ; 
    else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_call_with_prompt (finish_apply_with_prompt , a ) )) RET_VALUE_EMPTY_END ; 
  }
  else {
#   define XfOrM217_COUNT (0+XfOrM216_COUNT)
#   define SETUP_XfOrM217(x) SETUP_XfOrM216(x)
    if (multi )
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(_scheme_call_with_prompt_multi (finish_apply_with_prompt , a ) )) RET_VALUE_EMPTY_END ; 
    else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(_scheme_call_with_prompt (finish_apply_with_prompt , a ) )) RET_VALUE_EMPTY_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_apply_with_prompt (Scheme_Object * rator , int num_rands , Scheme_Object * * rands ) {
  /* No conversion */
  return do_apply_with_prompt (rator , num_rands , rands , 0 , 1 ) ; 
}
Scheme_Object * scheme_apply_multi_with_prompt (Scheme_Object * rator , int num_rands , Scheme_Object * * rands ) {
  /* No conversion */
  return do_apply_with_prompt (rator , num_rands , rands , 1 , 1 ) ; 
}
Scheme_Object * _scheme_apply_with_prompt (Scheme_Object * rator , int num_rands , Scheme_Object * * rands ) {
  /* No conversion */
  return do_apply_with_prompt (rator , num_rands , rands , 0 , 0 ) ; 
}
Scheme_Object * _scheme_apply_multi_with_prompt (Scheme_Object * rator , int num_rands , Scheme_Object * * rands ) {
  /* No conversion */
  return do_apply_with_prompt (rator , num_rands , rands , 1 , 0 ) ; 
}
Scheme_Object * scheme_tail_apply (Scheme_Object * rator , int num_rands , Scheme_Object * * rands ) {
  int i ; 
  Scheme_Thread * p = scheme_current_thread ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(rands, 0), PUSH(p, 1)));
# define XfOrM225_COUNT (2)
# define SETUP_XfOrM225(x) SETUP(XfOrM225_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  p -> ku . apply . tail_rator = rator ; 
  p -> ku . apply . tail_num_rands = num_rands ; 
  if (num_rands ) {
    Scheme_Object * * a ; 
    BLOCK_SETUP((PUSH(a, 0+XfOrM225_COUNT)));
#   define XfOrM226_COUNT (1+XfOrM225_COUNT)
#   define SETUP_XfOrM226(x) SETUP(XfOrM226_COUNT)
    a = NULLED_OUT ; 
    if (num_rands > p -> tail_buffer_size ) {
#     define XfOrM229_COUNT (0+XfOrM226_COUNT)
#     define SETUP_XfOrM229(x) SETUP_XfOrM226(x)
      {
        Scheme_Object * * tb ; 
        BLOCK_SETUP((PUSH(tb, 0+XfOrM229_COUNT)));
#       define XfOrM230_COUNT (1+XfOrM229_COUNT)
#       define SETUP_XfOrM230(x) SETUP(XfOrM230_COUNT)
        tb = NULLED_OUT ; 
        tb = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM230(_), GC_malloc (sizeof (Scheme_Object * ) * (num_rands ) ) )) ; 
        p -> tail_buffer = tb ; 
        p -> tail_buffer_size = num_rands ; 
      }
    }
    a = p -> tail_buffer ; 
    p -> ku . apply . tail_rands = a ; 
    for (i = num_rands ; i -- ; ) {
      a [i ] = rands [i ] ; 
    }
  }
  else p -> ku . apply . tail_rands = ((void * ) 0 ) ; 
  RET_VALUE_START (((Scheme_Object * ) 0x4 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_tail_apply_no_copy (Scheme_Object * rator , int num_rands , Scheme_Object * * rands ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  p -> ku . apply . tail_rator = rator ; 
  p -> ku . apply . tail_num_rands = num_rands ; 
  p -> ku . apply . tail_rands = rands ; 
  return ((Scheme_Object * ) 0x4 ) ; 
}
static Scheme_Object * X_scheme_apply_to_list (Scheme_Object * rator , Scheme_Object * rands , int force , int top_level ) {
  int num_rands , i ; 
  Scheme_Object * * rands_vec ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(rands, 0), PUSH(rands_vec, 1), PUSH(rator, 2)));
# define XfOrM232_COUNT (3)
# define SETUP_XfOrM232(x) SETUP(XfOrM232_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  rands_vec = NULLED_OUT ; 
  num_rands = FUNCCALL(SETUP_XfOrM232(_), scheme_list_length (rands ) ); 
  rands_vec = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM232(_), GC_malloc (sizeof (Scheme_Object * ) * (num_rands ) ) )) ; 
  for (i = 0 ; i < num_rands ; i ++ ) {
#   define XfOrM237_COUNT (0+XfOrM232_COUNT)
#   define SETUP_XfOrM237(x) SETUP_XfOrM232(x)
    if (! ((Scheme_Type ) (((((long ) (rands ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rands ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#     define XfOrM238_COUNT (0+XfOrM237_COUNT)
#     define SETUP_XfOrM238(x) SETUP_XfOrM237(x)
      FUNCCALL_EMPTY(scheme_signal_error ("bad application form" ) ); 
    }
    rands_vec [i ] = (((Scheme_Simple_Object * ) (rands ) ) -> u . pair_val . car ) ; 
    rands = (((Scheme_Simple_Object * ) (rands ) ) -> u . pair_val . cdr ) ; 
  }
  if (top_level ) {
#   define XfOrM234_COUNT (0+XfOrM232_COUNT)
#   define SETUP_XfOrM234(x) SETUP_XfOrM232(x)
    if (force )
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_apply (rator , num_rands , rands_vec ) )) RET_VALUE_EMPTY_END ; 
    else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_tail_apply (rator , num_rands , rands_vec ) )) RET_VALUE_EMPTY_END ; 
  }
  else {
#   define XfOrM233_COUNT (0+XfOrM232_COUNT)
#   define SETUP_XfOrM233(x) SETUP_XfOrM232(x)
    if (force )
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_do_eval (rator , num_rands , rands_vec , 1 ) )) RET_VALUE_EMPTY_END ; 
    else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_tail_apply (rator , num_rands , rands_vec ) )) RET_VALUE_EMPTY_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_apply_to_list (Scheme_Object * rator , Scheme_Object * rands ) {
  /* No conversion */
  return X_scheme_apply_to_list (rator , rands , 1 , 1 ) ; 
}
Scheme_Object * scheme_tail_apply_to_list (Scheme_Object * rator , Scheme_Object * rands ) {
  /* No conversion */
  return X_scheme_apply_to_list (rator , rands , 0 , 1 ) ; 
}
Scheme_Object * _scheme_apply_to_list (Scheme_Object * rator , Scheme_Object * rands ) {
  /* No conversion */
  return X_scheme_apply_to_list (rator , rands , 1 , 0 ) ; 
}
Scheme_Object * _scheme_tail_apply_to_list (Scheme_Object * rator , Scheme_Object * rands ) {
  /* No conversion */
  return X_scheme_apply_to_list (rator , rands , 0 , 0 ) ; 
}
static Scheme_Object * cert_with_specials (Scheme_Object * code , Scheme_Object * mark , Scheme_Env * menv , Scheme_Object * orig_code , Scheme_Object * closest_code , Scheme_Comp_Env * cenv , int phase , int deflt , int cadr_deflt ) {
  Scheme_Object * prop ; 
  int next_cadr_deflt = 0 ; 
  Scheme_Object * __funcarg50 = NULLED_OUT ; 
  Scheme_Object * __funcarg49 = NULLED_OUT ; 
  Scheme_Object * __funcarg48 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(11);
  BLOCK_SETUP_TOP((PUSH(closest_code, 0), PUSH(mark, 1), PUSH(menv, 2), PUSH(prop, 3), PUSH(orig_code, 4), PUSH(cenv, 5), PUSH(code, 6)));
# define XfOrM243_COUNT (7)
# define SETUP_XfOrM243(x) SETUP(XfOrM243_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  prop = NULLED_OUT ; 
  if (! certify_mode_symbol ) {
#   define XfOrM257_COUNT (0+XfOrM243_COUNT)
#   define SETUP_XfOrM257(x) SETUP_XfOrM243(x)
    FUNCCALL(SETUP_XfOrM257(_), scheme_register_static ((void * ) & certify_mode_symbol , sizeof (certify_mode_symbol ) ) ); 
    FUNCCALL(SETUP_XfOrM257(_), scheme_register_static ((void * ) & transparent_symbol , sizeof (transparent_symbol ) ) ); 
    FUNCCALL_AGAIN(scheme_register_static ((void * ) & transparent_binding_symbol , sizeof (transparent_binding_symbol ) ) ); 
    FUNCCALL_AGAIN(scheme_register_static ((void * ) & opaque_symbol , sizeof (opaque_symbol ) ) ); 
    certify_mode_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("certify-mode" ) ); 
    transparent_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("transparent" ) ); 
    transparent_binding_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("transparent-binding" ) ); 
    opaque_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("opaque" ) ); 
  }
  if (((Scheme_Type ) (((((long ) (code ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (code ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ) {
#   define XfOrM245_COUNT (0+XfOrM243_COUNT)
#   define SETUP_XfOrM245(x) SETUP_XfOrM243(x)
    prop = FUNCCALL(SETUP_XfOrM245(_), scheme_stx_property (code , certify_mode_symbol , ((void * ) 0 ) ) ); 
    if (((prop ) == (opaque_symbol ) ) ) {
#     define XfOrM256_COUNT (0+XfOrM245_COUNT)
#     define SETUP_XfOrM256(x) SETUP_XfOrM245(x)
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_stx_cert (code , mark , menv , orig_code , ((void * ) 0 ) , 1 ) )) RET_VALUE_EMPTY_END ; 
    }
    else if (((prop ) == (transparent_symbol ) ) ) {
      cadr_deflt = 0 ; 
    }
    else if (((prop ) == (transparent_binding_symbol ) ) ) {
      cadr_deflt = 0 ; 
      next_cadr_deflt = 1 ; 
    }
    else {
      int trans = deflt ; 
#     define XfOrM246_COUNT (0+XfOrM245_COUNT)
#     define SETUP_XfOrM246(x) SETUP_XfOrM245(x)
      if ((((Scheme_Type ) (((((long ) (code ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (code ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (code ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (code ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) code ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) code ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
        Scheme_Object * name ; 
        BLOCK_SETUP((PUSH(name, 0+XfOrM246_COUNT)));
#       define XfOrM247_COUNT (1+XfOrM246_COUNT)
#       define SETUP_XfOrM247(x) SETUP(XfOrM247_COUNT)
        name = NULLED_OUT ; 
        name = (((Scheme_Type ) (((((long ) (code ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (code ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (code ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM247(_), scheme_stx_content (code ) )) ) -> u . pair_val . car ) ) ; 
        if ((((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) name ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) name ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) ) {
          Scheme_Object * beg_stx , * dv_stx , * ds_stx ; 
          BLOCK_SETUP((PUSH(ds_stx, 0+XfOrM247_COUNT), PUSH(dv_stx, 1+XfOrM247_COUNT), PUSH(beg_stx, 2+XfOrM247_COUNT)));
#         define XfOrM248_COUNT (3+XfOrM247_COUNT)
#         define SETUP_XfOrM248(x) SETUP(XfOrM248_COUNT)
          beg_stx = NULLED_OUT ; 
          dv_stx = NULLED_OUT ; 
          ds_stx = NULLED_OUT ; 
          if (! phase ) {
            beg_stx = scheme_begin_stx ; 
            dv_stx = scheme_define_values_stx ; 
            ds_stx = scheme_define_syntaxes_stx ; 
          }
          else if (phase == cached_stx_phase ) {
            beg_stx = cached_beg_stx ; 
            dv_stx = cached_dv_stx ; 
            ds_stx = cached_ds_stx ; 
          }
          else {
#           define XfOrM251_COUNT (0+XfOrM248_COUNT)
#           define SETUP_XfOrM251(x) SETUP_XfOrM248(x)
            beg_stx = (__funcarg50 = FUNCCALL(SETUP_XfOrM251(_), scheme_sys_wraps (cenv ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (((Scheme_Stx * ) scheme_begin_stx ) -> val , scheme_false , __funcarg50 , 0 , 0 ) )) ; 
            dv_stx = (__funcarg49 = FUNCCALL(SETUP_XfOrM251(_), scheme_sys_wraps (cenv ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (((Scheme_Stx * ) scheme_define_values_stx ) -> val , scheme_false , __funcarg49 , 0 , 0 ) )) ; 
            ds_stx = (__funcarg48 = FUNCCALL(SETUP_XfOrM251(_), scheme_sys_wraps (cenv ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (((Scheme_Stx * ) scheme_define_syntaxes_stx ) -> val , scheme_false , __funcarg48 , 0 , 0 ) )) ; 
            cached_beg_stx = beg_stx ; 
            cached_dv_stx = dv_stx ; 
            cached_ds_stx = ds_stx ; 
            cached_stx_phase = phase ; 
          }
          if (FUNCCALL(SETUP_XfOrM248(_), scheme_stx_module_eq (beg_stx , name , phase ) )) {
            trans = 1 ; 
            next_cadr_deflt = 0 ; 
          }
          else if (FUNCCALL(SETUP_XfOrM248(_), scheme_stx_module_eq (dv_stx , name , phase ) )|| FUNCCALL(SETUP_XfOrM248(_), scheme_stx_module_eq (ds_stx , name , phase ) )) {
            trans = 1 ; 
            next_cadr_deflt = 1 ; 
          }
        }
      }
      if (! trans )
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_stx_cert (code , mark , menv , orig_code , ((void * ) 0 ) , 1 ) )) RET_VALUE_EMPTY_END ; 
    }
  }
  if ((((Scheme_Type ) (((((long ) (code ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (code ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (code ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (code ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) code ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) code ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
    Scheme_Object * a , * d , * v ; 
    BLOCK_SETUP((PUSH(v, 0+XfOrM243_COUNT), PUSH(a, 1+XfOrM243_COUNT), PUSH(d, 2+XfOrM243_COUNT)));
#   define XfOrM244_COUNT (3+XfOrM243_COUNT)
#   define SETUP_XfOrM244(x) SETUP(XfOrM244_COUNT)
    a = NULLED_OUT ; 
    d = NULLED_OUT ; 
    v = NULLED_OUT ; 
    if (((Scheme_Type ) (((((long ) (code ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (code ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
      closest_code = code ; 
    a = (((Scheme_Type ) (((((long ) (code ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (code ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (code ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM244(_), scheme_stx_content (code ) )) ) -> u . pair_val . car ) ) ; 
    a = FUNCCALL(SETUP_XfOrM244(_), scheme_stx_propagate_inactive_certs (a , closest_code ) ); 
    a = FUNCCALL_AGAIN(cert_with_specials (a , mark , menv , orig_code , closest_code , cenv , phase , cadr_deflt , 0 ) ); 
    d = (((Scheme_Type ) (((((long ) (code ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (code ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (code ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM244(_), scheme_stx_content (code ) )) ) -> u . pair_val . cdr ) ) ; 
    if (((Scheme_Type ) (((((long ) (d ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (d ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
      d = FUNCCALL(SETUP_XfOrM244(_), scheme_stx_propagate_inactive_certs (d , closest_code ) ); 
    d = FUNCCALL(SETUP_XfOrM244(_), cert_with_specials (d , mark , menv , orig_code , closest_code , cenv , phase , 1 , next_cadr_deflt ) ); 
    v = FUNCCALL_AGAIN(scheme_make_pair (a , d ) ); 
    if (((Scheme_Type ) (((((long ) (code ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (code ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
      RET_VALUE_START (v ) RET_VALUE_END ; 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_datum_to_syntax (v , code , code , 0 , 2 ) )) RET_VALUE_EMPTY_END ; 
  }
  else if ((((code ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (code ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (code ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) code ) -> val ) == (scheme_null ) ) ) ) )
    RET_VALUE_START (code ) RET_VALUE_END ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_stx_cert (code , mark , menv , orig_code , ((void * ) 0 ) , 1 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_apply_macro (Scheme_Object * name , Scheme_Env * menv , Scheme_Object * rator , Scheme_Object * code , Scheme_Comp_Env * env , Scheme_Object * boundname , Scheme_Compile_Expand_Info * rec , int drec , int for_set ) {
  Scheme_Object * orig_code = code ; 
  Scheme_Object * certs ; 
  Scheme_Object * __funcarg52 = NULLED_OUT ; 
  Scheme_Object * __funcarg51 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(13);
  BLOCK_SETUP_TOP((PUSH(code, 0), PUSH(name, 1), PUSH(menv, 2), PUSH(boundname, 3), PUSH(env, 4), PUSH(rator, 5), PUSH(orig_code, 6), PUSH(certs, 7), PUSH(rec, 8)));
# define XfOrM258_COUNT (9)
# define SETUP_XfOrM258(x) SETUP(XfOrM258_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  certs = NULLED_OUT ; 
  certs = rec [drec ] . certs ; 
  if (((Scheme_Type ) (((((long ) (rator ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rator ) ) -> type ) ) == (Scheme_Type ) (scheme_id_macro_type ) ) ) {
    Scheme_Object * mark ; 
    BLOCK_SETUP((PUSH(mark, 0+XfOrM258_COUNT)));
#   define XfOrM265_COUNT (1+XfOrM258_COUNT)
#   define SETUP_XfOrM265(x) SETUP(XfOrM265_COUNT)
    mark = NULLED_OUT ; 
    rator = (((Scheme_Simple_Object * ) (rator ) ) -> u . two_ptr_val . ptr1 ) ; 
    mark = FUNCCALL(SETUP_XfOrM265(_), scheme_new_mark () ); 
    rator = FUNCCALL_AGAIN(scheme_add_remove_mark (rator , mark ) ); 
    if (for_set ) {
      Scheme_Object * tail , * setkw ; 
      BLOCK_SETUP((PUSH(setkw, 0+XfOrM265_COUNT), PUSH(tail, 1+XfOrM265_COUNT)));
#     define XfOrM267_COUNT (2+XfOrM265_COUNT)
#     define SETUP_XfOrM267(x) SETUP(XfOrM267_COUNT)
      tail = NULLED_OUT ; 
      setkw = NULLED_OUT ; 
      tail = (((Scheme_Type ) (((((long ) (code ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (code ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (code ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM267(_), scheme_stx_content (code ) )) ) -> u . pair_val . cdr ) ) ; 
      setkw = (((Scheme_Type ) (((((long ) (code ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (code ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (code ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM267(_), scheme_stx_content (code ) )) ) -> u . pair_val . car ) ) ; 
      tail = (((Scheme_Type ) (((((long ) (tail ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (tail ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (tail ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM267(_), scheme_stx_content (tail ) )) ) -> u . pair_val . cdr ) ) ; 
      code = (__funcarg52 = FUNCCALL(SETUP_XfOrM267(_), scheme_make_immutable_pair (rator , tail ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (setkw , __funcarg52 ) )) ; 
      code = FUNCCALL_AGAIN(scheme_datum_to_syntax (code , orig_code , orig_code , 0 , 0 ) ); 
    }
    else if (((Scheme_Type ) (((((long ) (((Scheme_Stx * ) code ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) code ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
      code = rator ; 
    else {
#     define XfOrM266_COUNT (0+XfOrM265_COUNT)
#     define SETUP_XfOrM266(x) SETUP_XfOrM265(x)
      code = (((Scheme_Type ) (((((long ) (code ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (code ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (code ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM266(_), scheme_stx_content (code ) )) ) -> u . pair_val . cdr ) ) ; 
      code = FUNCCALL(SETUP_XfOrM266(_), scheme_make_immutable_pair (rator , code ) ); 
      code = (__funcarg51 = FUNCCALL(SETUP_XfOrM266(_), scheme_sys_wraps (env ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (code , orig_code , __funcarg51 , 0 , 0 ) )) ; 
    }
    code = FUNCCALL(SETUP_XfOrM265(_), cert_with_specials (code , mark , menv , orig_code , orig_code , env , env -> genv -> phase , 0 , 0 ) ); 
    code = FUNCCALL(SETUP_XfOrM265(_), scheme_stx_track (code , orig_code , name ) ); 
    RET_VALUE_START (code ) RET_VALUE_END ; 
  }
  else {
    Scheme_Object * mark , * rands_vec [1 ] ; 
    BLOCK_SETUP((PUSHARRAY(rands_vec, 1, 0+XfOrM258_COUNT), PUSH(mark, 3+XfOrM258_COUNT)));
#   define XfOrM259_COUNT (4+XfOrM258_COUNT)
#   define SETUP_XfOrM259(x) SETUP(XfOrM259_COUNT)
    mark = NULLED_OUT ; 
    rands_vec[0] = NULLED_OUT ; 
    certs = FUNCCALL(SETUP_XfOrM259(_), scheme_stx_extract_certs (code , certs ) ); 
    if (((Scheme_Type ) (((((long ) (rator ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rator ) ) -> type ) ) == (Scheme_Type ) (scheme_set_macro_type ) ) )
      rator = (((Scheme_Small_Object * ) (rator ) ) -> u . ptr_val ) ; 
    mark = FUNCCALL(SETUP_XfOrM259(_), scheme_new_mark () ); 
    code = FUNCCALL_AGAIN(scheme_add_remove_mark (code , mark ) ); 
    if (rec [drec ] . observer ) {
#     define XfOrM264_COUNT (0+XfOrM259_COUNT)
#     define SETUP_XfOrM264(x) SETUP_XfOrM259(x)
      FUNCCALL(SETUP_XfOrM264(_), scheme_call_expand_observe (rec [drec ] . observer , 21 , code ) ); 
    }
    else {
    }
    ; 
    FUNCCALL(SETUP_XfOrM259(_), scheme_on_next_top (env , mark , boundname , certs , menv , menv ? menv -> link_midx : env -> genv -> link_midx ) ); 
    rands_vec [0 ] = code ; 
    code = FUNCCALL(SETUP_XfOrM259(_), scheme_apply (rator , 1 , rands_vec ) ); 
    if (rec [drec ] . observer ) {
#     define XfOrM262_COUNT (0+XfOrM259_COUNT)
#     define SETUP_XfOrM262(x) SETUP_XfOrM259(x)
      FUNCCALL(SETUP_XfOrM262(_), scheme_call_expand_observe (rec [drec ] . observer , 22 , code ) ); 
    }
    else {
    }
    ; 
    if (! ((Scheme_Type ) (((((long ) (code ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (code ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ) {
#     define XfOrM260_COUNT (0+XfOrM259_COUNT)
#     define SETUP_XfOrM260(x) SETUP_XfOrM259(x)
      FUNCCALL(SETUP_XfOrM260(_), scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%S: return value from syntax expander was not syntax: %V" , (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ? ((Scheme_Stx * ) name ) -> val : name ) , code ) ); 
    }
    code = FUNCCALL(SETUP_XfOrM259(_), scheme_add_remove_mark (code , mark ) ); 
    code = FUNCCALL(SETUP_XfOrM259(_), cert_with_specials (code , mark , menv , orig_code , orig_code , env , env -> genv -> phase , 0 , 0 ) ); 
    code = FUNCCALL_AGAIN(scheme_stx_track (code , orig_code , name ) ); 
    RET_VALUE_START (code ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_arity (mzshort mina , mzshort maxa ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
# define XfOrM268_COUNT (0)
# define SETUP_XfOrM268(x) SETUP(XfOrM268_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (mina == maxa )
    RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (mina ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
  else if (maxa == - 1 ) {
    Scheme_Object * p [1 ] ; 
    BLOCK_SETUP((PUSHARRAY(p, 1, 0+XfOrM268_COUNT)));
#   define XfOrM272_COUNT (3+XfOrM268_COUNT)
#   define SETUP_XfOrM272(x) SETUP(XfOrM272_COUNT)
    p[0] = NULLED_OUT ; 
    p [0 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (mina ) ) << 1 ) | 0x1 ) ) ; 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM272(_), scheme_make_struct_instance (scheme_arity_at_least , 1 , p ) )) RET_VALUE_END ; 
  }
  else {
    int i ; 
    Scheme_Object * l = scheme_null ; 
    BLOCK_SETUP((PUSH(l, 0+XfOrM268_COUNT)));
#   define XfOrM269_COUNT (1+XfOrM268_COUNT)
#   define SETUP_XfOrM269(x) SETUP(XfOrM269_COUNT)
    for (i = maxa ; i >= mina ; -- i ) {
#     define XfOrM271_COUNT (0+XfOrM269_COUNT)
#     define SETUP_XfOrM271(x) SETUP_XfOrM269(x)
      l = FUNCCALL(SETUP_XfOrM271(_), scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (i ) ) << 1 ) | 0x1 ) ) , l ) ); 
    }
    RET_VALUE_START (l ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * clone_arity (Scheme_Object * a ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(a, 0)));
# define XfOrM273_COUNT (1)
# define SETUP_XfOrM273(x) SETUP(XfOrM273_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
    Scheme_Object * m , * l ; 
    BLOCK_SETUP((PUSH(m, 0+XfOrM273_COUNT), PUSH(l, 1+XfOrM273_COUNT)));
#   define XfOrM275_COUNT (2+XfOrM273_COUNT)
#   define SETUP_XfOrM275(x) SETUP(XfOrM275_COUNT)
    m = NULLED_OUT ; 
    l = NULLED_OUT ; 
    m = FUNCCALL(SETUP_XfOrM275(_), scheme_copy_list (a ) ); 
    for (l = m ; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#     define XfOrM277_COUNT (0+XfOrM275_COUNT)
#     define SETUP_XfOrM277(x) SETUP_XfOrM275(x)
      a = FUNCCALL(SETUP_XfOrM277(_), clone_arity ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ) ); 
      (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) = a ; 
    }
    RET_VALUE_START (m ) RET_VALUE_END ; 
  }
  else if ((((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) ) {
    Scheme_Object * p [1 ] ; 
    BLOCK_SETUP((PUSHARRAY(p, 1, 0+XfOrM273_COUNT)));
#   define XfOrM274_COUNT (3+XfOrM273_COUNT)
#   define SETUP_XfOrM274(x) SETUP(XfOrM274_COUNT)
    p[0] = NULLED_OUT ; 
    p [0 ] = ((Scheme_Structure * ) a ) -> slots [0 ] ; 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM274(_), scheme_make_struct_instance (scheme_arity_at_least , 1 , p ) )) RET_VALUE_END ; 
  }
  else RET_VALUE_START (a ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * get_or_check_arity (Scheme_Object * p , long a , Scheme_Object * bign ) {
  Scheme_Type type ; 
  mzshort mina , maxa ; 
  int drop = 0 , cases_count = 0 ; 
  mzshort * cases = ((void * ) 0 ) ; 
  Scheme_Object * __funcarg54 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(cases, 0), PUSH(p, 1), PUSH(bign, 2)));
# define XfOrM278_COUNT (3)
# define SETUP_XfOrM278(x) SETUP(XfOrM278_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  top : type = ((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ; 
  if (type == scheme_prim_type ) {
    mina = ((Scheme_Primitive_Proc * ) p ) -> mina ; 
    maxa = ((Scheme_Primitive_Proc * ) p ) -> mu . maxa ; 
    if (mina < 0 ) {
      cases = ((Scheme_Primitive_Proc * ) p ) -> mu . cases ; 
      cases_count = - (mina + 1 ) ; 
    }
    else {
      if (maxa > 0x3FFFFFFE )
        maxa = - 1 ; 
    }
  }
  else if (type == scheme_closed_prim_type ) {
    mina = ((Scheme_Closed_Primitive_Proc * ) p ) -> mina ; 
    maxa = ((Scheme_Closed_Primitive_Proc * ) p ) -> maxa ; 
    if (mina == - 2 ) {
      cases_count = - maxa ; 
      cases = ((Scheme_Closed_Case_Primitive_Proc * ) p ) -> cases ; 
    }
  }
  else if (type == scheme_cont_type || type == scheme_escaping_cont_type ) {
    mina = 0 ; 
    maxa = - 1 ; 
  }
  else if (type == scheme_case_closure_type ) {
    Scheme_Case_Lambda * seq ; 
    Scheme_Closure_Data * data ; 
    int i ; 
    Scheme_Object * first , * last = ((void * ) 0 ) , * v ; 
    BLOCK_SETUP((PUSH(v, 0+XfOrM278_COUNT), PUSH(last, 1+XfOrM278_COUNT), PUSH(seq, 2+XfOrM278_COUNT), PUSH(first, 3+XfOrM278_COUNT), PUSH(data, 4+XfOrM278_COUNT)));
#   define XfOrM340_COUNT (5+XfOrM278_COUNT)
#   define SETUP_XfOrM340(x) SETUP(XfOrM340_COUNT)
    seq = NULLED_OUT ; 
    data = NULLED_OUT ; 
    first = NULLED_OUT ; 
    v = NULLED_OUT ; 
    if (a == - 1 )
      first = scheme_null ; 
    else first = scheme_false ; 
    seq = (Scheme_Case_Lambda * ) p ; 
    for (i = 0 ; i < seq -> count ; i ++ ) {
#     define XfOrM347_COUNT (0+XfOrM340_COUNT)
#     define SETUP_XfOrM347(x) SETUP_XfOrM340(x)
      data = ((Scheme_Closure * ) seq -> array [i ] ) -> code ; 
      mina = maxa = data -> num_params ; 
      if ((& (data ) -> iso ) -> so . keyex & 1 ) {
        if (mina )
          -- mina ; 
        maxa = - 1 ; 
      }
      if (a >= 0 ) {
        if ((a + drop ) >= mina && (maxa < 0 || (a + drop ) <= maxa ) )
          RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
      }
      else if (a == - 2 ) {
        if (maxa < 0 )
          RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
      }
      else {
#       define XfOrM348_COUNT (0+XfOrM347_COUNT)
#       define SETUP_XfOrM348(x) SETUP_XfOrM347(x)
        if (mina >= drop ) {
#         define XfOrM349_COUNT (0+XfOrM348_COUNT)
#         define SETUP_XfOrM349(x) SETUP_XfOrM348(x)
          mina -= drop ; 
          if (maxa > 0 )
            maxa -= drop ; 
          v = (__funcarg54 = FUNCCALL(SETUP_XfOrM349(_), scheme_make_arity (mina , maxa ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg54 , scheme_null ) )) ; 
          if (! last )
            first = v ; 
          else (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = v ; 
          last = v ; 
        }
      }
    }
    RET_VALUE_START (first ) RET_VALUE_END ; 
  }
  else if (type == scheme_proc_struct_type ) {
    int is_method ; 
#   define XfOrM324_COUNT (0+XfOrM278_COUNT)
#   define SETUP_XfOrM324(x) SETUP_XfOrM278(x)
    if (reduced_procedure_struct && (scheme_is_struct_instance (reduced_procedure_struct , p ) ) ) {
#     define XfOrM329_COUNT (0+XfOrM324_COUNT)
#     define SETUP_XfOrM329(x) SETUP_XfOrM324(x)
      if (a >= 0 )
        bign = ((Scheme_Object * ) (void * ) (long ) ((((long ) (a ) ) << 1 ) | 0x1 ) ) ; 
      if (a == - 1 )
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(clone_arity (((Scheme_Structure * ) p ) -> slots [1 ] ) )) RET_VALUE_EMPTY_END ; 
      else {
        Scheme_Object * v ; 
        BLOCK_SETUP((PUSH(v, 0+XfOrM329_COUNT)));
#       define XfOrM330_COUNT (1+XfOrM329_COUNT)
#       define SETUP_XfOrM330(x) SETUP(XfOrM330_COUNT)
        v = NULLED_OUT ; 
        v = ((Scheme_Structure * ) p ) -> slots [1 ] ; 
        if ((((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) ) {
#         define XfOrM339_COUNT (0+XfOrM330_COUNT)
#         define SETUP_XfOrM339(x) SETUP_XfOrM330(x)
          v = ((Scheme_Structure * ) v ) -> slots [0 ] ; 
          RET_VALUE_START ((FUNCCALL(SETUP_XfOrM339(_), scheme_bin_lt_eq (v , bign ) )? scheme_true : scheme_false ) ) RET_VALUE_END ; 
        }
        else if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
          Scheme_Object * x ; 
          BLOCK_SETUP((PUSH(x, 0+XfOrM330_COUNT)));
#         define XfOrM332_COUNT (1+XfOrM330_COUNT)
#         define SETUP_XfOrM332(x) SETUP(XfOrM332_COUNT)
          x = NULLED_OUT ; 
          while (! ((v ) == (scheme_null ) ) ) {
#           define XfOrM336_COUNT (0+XfOrM332_COUNT)
#           define SETUP_XfOrM336(x) SETUP_XfOrM332(x)
            x = (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) ; 
            if ((((Scheme_Type ) (((((long ) (x ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (x ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (x ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (x ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) ) {
#             define XfOrM338_COUNT (0+XfOrM336_COUNT)
#             define SETUP_XfOrM338(x) SETUP_XfOrM336(x)
              x = ((Scheme_Structure * ) x ) -> slots [0 ] ; 
              if (FUNCCALL(SETUP_XfOrM338(_), scheme_bin_lt_eq (x , bign ) ))
                RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
            }
            else {
#             define XfOrM337_COUNT (0+XfOrM336_COUNT)
#             define SETUP_XfOrM337(x) SETUP_XfOrM336(x)
              if (FUNCCALL(SETUP_XfOrM337(_), scheme_bin_eq (x , bign ) ))
                RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
            }
            v = (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) ; 
          }
          RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
        }
        else {
#         define XfOrM331_COUNT (0+XfOrM330_COUNT)
#         define SETUP_XfOrM331(x) SETUP_XfOrM330(x)
          RET_VALUE_START ((FUNCCALL(SETUP_XfOrM331(_), scheme_bin_eq (v , bign ) )? scheme_true : scheme_false ) ) RET_VALUE_END ; 
        }
      }
    }
    else {
#     define XfOrM327_COUNT (0+XfOrM324_COUNT)
#     define SETUP_XfOrM327(x) SETUP_XfOrM324(x)
      p = FUNCCALL(SETUP_XfOrM327(_), scheme_extract_struct_procedure (p , - 1 , ((void * ) 0 ) , & is_method ) ); 
      if (! (! (((long ) (p ) ) & 0x1 ) && ((((p ) -> type ) >= scheme_prim_type ) && (((p ) -> type ) <= scheme_native_closure_type ) ) ) ) {
        if (a == - 1 )
          RET_VALUE_START (scheme_null ) RET_VALUE_END ; 
        else RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      }
      if (is_method )
        drop ++ ; 
    }
    {
#     define XfOrM325_COUNT (0+XfOrM324_COUNT)
#     define SETUP_XfOrM325(x) SETUP_XfOrM324(x)
      if ((scheme_fuel_counter ) <= 0 ) {
#       define XfOrM326_COUNT (0+XfOrM325_COUNT)
#       define SETUP_XfOrM326(x) SETUP_XfOrM325(x)
        FUNCCALL(SETUP_XfOrM326(_), scheme_out_of_fuel () ); 
      }
    }
    ; 
    goto top ; 
  }
  else if (type == scheme_native_closure_type ) {
#   define XfOrM294_COUNT (0+XfOrM278_COUNT)
#   define SETUP_XfOrM294(x) SETUP_XfOrM278(x)
    if (a < 0 ) {
      Scheme_Object * pa ; 
      BLOCK_SETUP((PUSH(pa, 0+XfOrM294_COUNT)));
#     define XfOrM296_COUNT (1+XfOrM294_COUNT)
#     define SETUP_XfOrM296(x) SETUP(XfOrM296_COUNT)
      pa = NULLED_OUT ; 
      pa = FUNCCALL(SETUP_XfOrM296(_), scheme_get_native_arity (p ) ); 
      if (((Scheme_Type ) (((((long ) (pa ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (pa ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) {
        pa = (((Scheme_Small_Object * ) (pa ) ) -> u . ptr_val ) ; 
      }
      if ((((Scheme_Type ) (((((long ) (pa ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (pa ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (pa ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (pa ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) ) {
        int v ; 
        pa = ((Scheme_Structure * ) pa ) -> slots [0 ] ; 
        v = - ((((long ) (pa ) ) >> 1 ) + 1 ) ; 
        pa = ((Scheme_Object * ) (void * ) (long ) ((((long ) (v ) ) << 1 ) | 0x1 ) ) ; 
      }
      if ((((long ) (pa ) ) & 0x1 ) ) {
        mina = (((long ) (pa ) ) >> 1 ) ; 
        if (mina < 0 ) {
          if (a == - 2 ) {
            RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
          }
          mina = (- mina ) - 1 ; 
          maxa = - 1 ; 
        }
        else {
          if (a == - 2 ) {
            RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
          }
          maxa = mina ; 
        }
      }
      else {
#       define XfOrM297_COUNT (0+XfOrM296_COUNT)
#       define SETUP_XfOrM297(x) SETUP_XfOrM296(x)
        if (a == - 2 ) {
          Scheme_Object * a ; 
          a = NULLED_OUT ; 
          while (! ((pa ) == (scheme_null ) ) ) {
            a = (((Scheme_Simple_Object * ) (pa ) ) -> u . pair_val . car ) ; 
            if ((((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) )
              RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
            pa = (((Scheme_Simple_Object * ) (pa ) ) -> u . pair_val . cdr ) ; 
          }
          RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
        }
        else {
#         define XfOrM298_COUNT (0+XfOrM297_COUNT)
#         define SETUP_XfOrM298(x) SETUP_XfOrM297(x)
          if (drop ) {
            Scheme_Object * first = scheme_null , * last = ((void * ) 0 ) , * a ; 
            int v ; 
            BLOCK_SETUP((PUSH(first, 0+XfOrM298_COUNT), PUSH(a, 1+XfOrM298_COUNT), PUSH(last, 2+XfOrM298_COUNT)));
#           define XfOrM299_COUNT (3+XfOrM298_COUNT)
#           define SETUP_XfOrM299(x) SETUP(XfOrM299_COUNT)
            a = NULLED_OUT ; 
            while (((Scheme_Type ) (((((long ) (pa ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (pa ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#             define XfOrM307_COUNT (0+XfOrM299_COUNT)
#             define SETUP_XfOrM307(x) SETUP_XfOrM299(x)
              a = (((Scheme_Simple_Object * ) (pa ) ) -> u . pair_val . car ) ; 
              if ((((long ) (a ) ) & 0x1 ) ) {
                v = (((long ) (a ) ) >> 1 ) ; 
                if (v < drop )
                  a = ((void * ) 0 ) ; 
                else {
                  v -= drop ; 
                  a = ((Scheme_Object * ) (void * ) (long ) ((((long ) (v ) ) << 1 ) | 0x1 ) ) ; 
                }
              }
              else {
#               define XfOrM309_COUNT (0+XfOrM307_COUNT)
#               define SETUP_XfOrM309(x) SETUP_XfOrM307(x)
                a = ((Scheme_Structure * ) a ) -> slots [0 ] ; 
                v = (((long ) (a ) ) >> 1 ) ; 
                if (v >= drop ) {
#                 define XfOrM311_COUNT (0+XfOrM309_COUNT)
#                 define SETUP_XfOrM311(x) SETUP_XfOrM309(x)
                  a = FUNCCALL(SETUP_XfOrM311(_), scheme_make_arity (v - drop , - 1 ) ); 
                }
                else {
#                 define XfOrM310_COUNT (0+XfOrM309_COUNT)
#                 define SETUP_XfOrM310(x) SETUP_XfOrM309(x)
                  a = FUNCCALL(SETUP_XfOrM310(_), scheme_make_arity (0 , - 1 ) ); 
                }
              }
              if (a ) {
#               define XfOrM308_COUNT (0+XfOrM307_COUNT)
#               define SETUP_XfOrM308(x) SETUP_XfOrM307(x)
                a = FUNCCALL(SETUP_XfOrM308(_), scheme_make_pair (a , scheme_null ) ); 
                if (last )
                  (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = a ; 
                else first = a ; 
                last = a ; 
              }
              pa = (((Scheme_Simple_Object * ) (pa ) ) -> u . pair_val . cdr ) ; 
            }
            RET_VALUE_START (first ) RET_VALUE_END ; 
          }
          RET_VALUE_START (pa ) RET_VALUE_END ; 
        }
      }
    }
    else {
#     define XfOrM295_COUNT (0+XfOrM294_COUNT)
#     define SETUP_XfOrM295(x) SETUP_XfOrM294(x)
      if (FUNCCALL(SETUP_XfOrM295(_), scheme_native_arity_check (p , a + drop ) ))
        RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
      else RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    }
  }
  else {
    Scheme_Closure_Data * data ; 
    data = NULLED_OUT ; 
    data = ((Scheme_Closure * ) p ) -> code ; 
    mina = maxa = data -> num_params ; 
    if ((& (data ) -> iso ) -> so . keyex & 1 ) {
      if (mina )
        -- mina ; 
      maxa = - 1 ; 
    }
  }
  if (cases ) {
    int count = cases_count , i ; 
#   define XfOrM280_COUNT (0+XfOrM278_COUNT)
#   define SETUP_XfOrM280(x) SETUP_XfOrM278(x)
    if (a == - 1 ) {
      Scheme_Object * arity , * a , * last = ((void * ) 0 ) ; 
      BLOCK_SETUP((PUSH(a, 0+XfOrM280_COUNT), PUSH(arity, 1+XfOrM280_COUNT), PUSH(last, 2+XfOrM280_COUNT)));
#     define XfOrM286_COUNT (3+XfOrM280_COUNT)
#     define SETUP_XfOrM286(x) SETUP(XfOrM286_COUNT)
      arity = NULLED_OUT ; 
      a = NULLED_OUT ; 
      arity = FUNCCALL(SETUP_XfOrM286(_), scheme_alloc_list (count ) ); 
      for (i = 0 , a = arity ; i < count ; i ++ ) {
        Scheme_Object * av ; 
        int mn , mx ; 
        BLOCK_SETUP((PUSH(av, 0+XfOrM286_COUNT)));
#       define XfOrM290_COUNT (1+XfOrM286_COUNT)
#       define SETUP_XfOrM290(x) SETUP(XfOrM290_COUNT)
        av = NULLED_OUT ; 
        mn = cases [2 * i ] ; 
        mx = cases [(2 * i ) + 1 ] ; 
        if (mn >= drop ) {
#         define XfOrM291_COUNT (0+XfOrM290_COUNT)
#         define SETUP_XfOrM291(x) SETUP_XfOrM290(x)
          mn -= drop ; 
          if (mx > 0 )
            mx -= drop ; 
          av = FUNCCALL(SETUP_XfOrM291(_), scheme_make_arity (mn , mx ) ); 
          (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) = av ; 
          last = a ; 
          a = (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) ; 
        }
      }
      if (! ((a ) == (scheme_null ) ) ) {
        if (last )
          (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = scheme_null ; 
        else arity = scheme_null ; 
      }
      RET_VALUE_START (arity ) RET_VALUE_END ; 
    }
    if (a == - 2 ) {
      for (i = 0 ; i < count ; i ++ ) {
        if (cases [(2 * i ) + 1 ] < 0 )
          RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
      }
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    }
    a += drop ; 
    for (i = 0 ; i < count ; i ++ ) {
      int na , xa ; 
      na = cases [2 * i ] ; 
      xa = cases [(2 * i ) + 1 ] ; 
      if ((a >= na ) && ((xa < 0 ) || (a <= xa ) ) )
        RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
    }
    RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
  }
  if (a == - 1 ) {
#   define XfOrM279_COUNT (0+XfOrM278_COUNT)
#   define SETUP_XfOrM279(x) SETUP_XfOrM278(x)
    if (mina < drop )
      RET_VALUE_START (scheme_null ) RET_VALUE_END ; 
    else mina -= drop ; 
    if (maxa > 0 )
      maxa -= drop ; 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_arity (mina , maxa ) )) RET_VALUE_EMPTY_END ; 
  }
  if (a == - 2 )
    RET_VALUE_START ((maxa < 0 ) ? scheme_true : scheme_false ) RET_VALUE_END ; 
  a += drop ; 
  if (a < mina || (maxa >= 0 && a > maxa ) )
    RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
  RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_get_or_check_arity (Scheme_Object * p , long a ) {
  /* No conversion */
  return get_or_check_arity (p , a , ((void * ) 0 ) ) ; 
}
int scheme_check_proc_arity2 (const char * where , int a , int which , int argc , Scheme_Object * * argv , int false_ok ) {
  Scheme_Object * p ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(where, 0), PUSH(argv, 1)));
# define XfOrM360_COUNT (2)
# define SETUP_XfOrM360(x) SETUP(XfOrM360_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  p = NULLED_OUT ; 
  if (which < 0 )
    p = argv [0 ] ; 
  else p = argv [which ] ; 
  if (false_ok && (((p ) ) == (scheme_false ) ) )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  if (! (! (((long ) (p ) ) & 0x1 ) && ((((p ) -> type ) >= scheme_prim_type ) && (((p ) -> type ) <= scheme_native_closure_type ) ) ) || (((FUNCCALL(SETUP_XfOrM360(_), get_or_check_arity (p , a , ((void * ) 0 ) ) )) ) == (scheme_false ) ) ) {
#   define XfOrM361_COUNT (0+XfOrM360_COUNT)
#   define SETUP_XfOrM361(x) SETUP_XfOrM360(x)
    if (where ) {
      char buffer [60 ] ; 
#     define XfOrM362_COUNT (0+XfOrM361_COUNT)
#     define SETUP_XfOrM362(x) SETUP_XfOrM361(x)
      (sprintf (buffer , "procedure (arity %d)%s" , a , false_ok ? " or #f" : "" ) ) ; 
      FUNCCALL_EMPTY(scheme_wrong_type (where , buffer , which , argc , argv ) ); 
    }
    else RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  RET_VALUE_START (1 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_check_proc_arity (const char * where , int a , int which , int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return scheme_check_proc_arity2 (where , a , which , argc , argv , 0 ) ; 
}
static Scheme_Object * void_func (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_void ; 
}
static Scheme_Object * void_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return ((argv [0 ] ) == (scheme_void ) ) ? scheme_true : scheme_false ; 
}
static Scheme_Object * procedure_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return ((! (((long ) (argv [0 ] ) ) & 0x1 ) && ((((argv [0 ] ) -> type ) >= scheme_prim_type ) && (((argv [0 ] ) -> type ) <= scheme_native_closure_type ) ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * primitive_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  int isprim ; 
  if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_prim_type ) ) )
    isprim = (((Scheme_Primitive_Proc * ) argv [0 ] ) -> pp . flags & 2 ) ; 
  else if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_closed_prim_type ) ) )
    isprim = (((Scheme_Closed_Primitive_Proc * ) argv [0 ] ) -> pp . flags & 2 ) ; 
  else isprim = 0 ; 
  return isprim ? scheme_true : scheme_false ; 
}
static Scheme_Object * primitive_closure_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  int isprim ; 
  if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_closed_prim_type ) ) )
    isprim = (((Scheme_Closed_Primitive_Proc * ) argv [0 ] ) -> pp . flags & 2 ) ; 
  else isprim = 0 ; 
  return isprim ? scheme_true : scheme_false ; 
}
Scheme_Object * scheme_proc_struct_name_source (Scheme_Object * a ) {
  Scheme_Object * b ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(a, 0), PUSH(b, 1)));
# define XfOrM369_COUNT (2)
# define SETUP_XfOrM369(x) SETUP(XfOrM369_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  b = NULLED_OUT ; 
  while (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) {
    int is_method ; 
#   define XfOrM374_COUNT (0+XfOrM369_COUNT)
#   define SETUP_XfOrM374(x) SETUP_XfOrM369(x)
    b = FUNCCALL(SETUP_XfOrM374(_), scheme_extract_struct_procedure (a , - 1 , ((void * ) 0 ) , & is_method ) ); 
    if (! is_method && (! (((long ) (b ) ) & 0x1 ) && ((((b ) -> type ) >= scheme_prim_type ) && (((b ) -> type ) <= scheme_native_closure_type ) ) ) ) {
#     define XfOrM375_COUNT (0+XfOrM374_COUNT)
#     define SETUP_XfOrM375(x) SETUP_XfOrM374(x)
      a = b ; 
      {
#       define XfOrM376_COUNT (0+XfOrM375_COUNT)
#       define SETUP_XfOrM376(x) SETUP_XfOrM375(x)
        if ((scheme_fuel_counter ) <= 0 ) {
#         define XfOrM377_COUNT (0+XfOrM376_COUNT)
#         define SETUP_XfOrM377(x) SETUP_XfOrM376(x)
          FUNCCALL(SETUP_XfOrM377(_), scheme_out_of_fuel () ); 
        }
      }
      ; 
    }
    else break ; 
  }
  RET_VALUE_START (a ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
const char * scheme_get_proc_name (Scheme_Object * p , int * len , int for_error ) {
  Scheme_Type type ; 
  int dummy ; 
  char * s ; 
  char * __funcarg55 = NULLED_OUT ; 
  DECL_RET_SAVE (const char * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(len, 0), PUSH(s, 1), PUSH(p, 2)));
# define XfOrM378_COUNT (3)
# define SETUP_XfOrM378(x) SETUP(XfOrM378_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  s = NULLED_OUT ; 
  if (! len )
    len = & dummy ; 
  top : type = ((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ; 
  if (type == scheme_prim_type ) {
    if (((Scheme_Primitive_Proc * ) p ) -> name )
      * len = strlen (((Scheme_Primitive_Proc * ) p ) -> name ) ; 
    RET_VALUE_START (((Scheme_Primitive_Proc * ) p ) -> name ) RET_VALUE_END ; 
  }
  else if (type == scheme_closed_prim_type ) {
    if (((Scheme_Closed_Primitive_Proc * ) p ) -> name )
      * len = strlen (((Scheme_Closed_Primitive_Proc * ) p ) -> name ) ; 
    RET_VALUE_START (((Scheme_Closed_Primitive_Proc * ) p ) -> name ) RET_VALUE_END ; 
  }
  else if (type == scheme_cont_type || type == scheme_escaping_cont_type ) {
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  else if (type == scheme_case_closure_type ) {
    Scheme_Object * n ; 
#   define XfOrM390_COUNT (0+XfOrM378_COUNT)
#   define SETUP_XfOrM390(x) SETUP_XfOrM378(x)
    n = NULLED_OUT ; 
    n = ((Scheme_Case_Lambda * ) p ) -> name ; 
    if (n ) {
#     define XfOrM391_COUNT (0+XfOrM390_COUNT)
#     define SETUP_XfOrM391(x) SETUP_XfOrM390(x)
      if (((Scheme_Type ) (((((long ) (n ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) {
        n = (((Scheme_Small_Object * ) (n ) ) -> u . ptr_val ) ; 
        if ((((n ) ) == (scheme_false ) ) )
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      if (((Scheme_Type ) (((((long ) (n ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) )
        n = (((Scheme_Vector * ) (n ) ) -> els ) [0 ] ; 
      if (for_error < 0 ) {
        s = (char * ) n ; 
        * len = - 1 ; 
      }
      else {
#       define XfOrM392_COUNT (0+XfOrM391_COUNT)
#       define SETUP_XfOrM392(x) SETUP_XfOrM391(x)
        * len = (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (n ) ) ) -> len ) ; 
        s = FUNCCALL(SETUP_XfOrM392(_), scheme_symbol_val (n ) ); 
      }
    }
    else RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  else if (type == scheme_proc_struct_type ) {
    Scheme_Object * other ; 
    BLOCK_SETUP((PUSH(other, 0+XfOrM378_COUNT)));
#   define XfOrM387_COUNT (1+XfOrM378_COUNT)
#   define SETUP_XfOrM387(x) SETUP(XfOrM387_COUNT)
    other = NULLED_OUT ; 
    other = FUNCCALL(SETUP_XfOrM387(_), scheme_proc_struct_name_source (p ) ); 
    if (((other ) == (p ) ) ) {
      Scheme_Object * sym ; 
      BLOCK_SETUP((PUSH(sym, 0+XfOrM387_COUNT)));
#     define XfOrM389_COUNT (1+XfOrM387_COUNT)
#     define SETUP_XfOrM389(x) SETUP(XfOrM389_COUNT)
      sym = NULLED_OUT ; 
      sym = ((((Scheme_Structure * ) p ) -> stype ) -> name ) ; 
      * len = (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (sym ) ) ) -> len ) ; 
      s = (char * ) FUNCCALL(SETUP_XfOrM389(_), GC_malloc_atomic ((* len ) + 8 ) ); 
      (memcpy (s , "struct " , 7 ) ) ; 
      (__funcarg55 = FUNCCALL(SETUP_XfOrM389(_), scheme_symbol_val (sym ) ), (memcpy (s + 7 , __funcarg55 , * len ) ) ) ; 
      (* len ) += 7 ; 
      s [* len ] = 0 ; 
      RET_VALUE_START (s ) RET_VALUE_END ; 
    }
    else {
      p = other ; 
      goto top ; 
    }
  }
  else {
    Scheme_Object * name ; 
#   define XfOrM380_COUNT (0+XfOrM378_COUNT)
#   define SETUP_XfOrM380(x) SETUP_XfOrM378(x)
    name = NULLED_OUT ; 
    if (type == scheme_closure_type ) {
      name = ((Scheme_Closure * ) p ) -> code -> name ; 
    }
    else {
      name = ((Scheme_Native_Closure * ) p ) -> code -> u2 . name ; 
      if (name && ((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_unclosed_procedure_type ) ) ) {
        name = ((Scheme_Closure_Data * ) name ) -> name ; 
      }
    }
    if (name ) {
#     define XfOrM381_COUNT (0+XfOrM380_COUNT)
#     define SETUP_XfOrM381(x) SETUP_XfOrM380(x)
      if (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) )
        name = (((Scheme_Vector * ) (name ) ) -> els ) [0 ] ; 
      if (for_error < 0 ) {
        s = (char * ) name ; 
        * len = - 1 ; 
      }
      else {
#       define XfOrM382_COUNT (0+XfOrM381_COUNT)
#       define SETUP_XfOrM382(x) SETUP_XfOrM381(x)
        * len = (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (name ) ) ) -> len ) ; 
        s = FUNCCALL(SETUP_XfOrM382(_), scheme_symbol_val (name ) ); 
      }
    }
    else RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (for_error > 0 ) {
    char * r ; 
    BLOCK_SETUP((PUSH(r, 0+XfOrM378_COUNT)));
#   define XfOrM379_COUNT (1+XfOrM378_COUNT)
#   define SETUP_XfOrM379(x) SETUP(XfOrM379_COUNT)
    r = NULLED_OUT ; 
    r = (char * ) FUNCCALL(SETUP_XfOrM379(_), GC_malloc_atomic ((* len ) + 11 ) ); 
    (memcpy (r , "procedure " , 10 ) ) ; 
    (memcpy (r + 10 , s , * len + 1 ) ) ; 
    * len += 10 ; 
    RET_VALUE_START (r ) RET_VALUE_END ; 
  }
  RET_VALUE_START (s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * primitive_result_arity (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * o ; 
  o = argv [0 ] ; 
  if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_prim_type ) ) && (((Scheme_Primitive_Proc * ) o ) -> pp . flags & 2 ) ) {
    if (((Scheme_Primitive_Proc * ) o ) -> pp . flags & 256 ) {
      Scheme_Prim_W_Result_Arity * p = (Scheme_Prim_W_Result_Arity * ) o ; 
      return scheme_make_arity (p -> minr , p -> maxr ) ; 
    }
  }
  else if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_closed_prim_type ) ) && (((Scheme_Closed_Primitive_Proc * ) o ) -> pp . flags & 2 ) ) {
    if (((Scheme_Closed_Primitive_Proc * ) o ) -> pp . flags & 256 ) {
      Scheme_Closed_Prim_W_Result_Arity * p = (Scheme_Closed_Prim_W_Result_Arity * ) o ; 
      return scheme_make_arity (p -> minr , p -> maxr ) ; 
    }
  }
  else {
    scheme_wrong_type ("primitive-result_arity" , "primitive" , 0 , argc , argv ) ; 
    return ((void * ) 0 ) ; 
  }
  return ((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) ; 
}
static Scheme_Object * object_name (int argc , Scheme_Object * * argv ) {
  Scheme_Object * a = argv [0 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(a, 0)));
# define XfOrM404_COUNT (1)
# define SETUP_XfOrM404(x) SETUP(XfOrM404_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) )
    a = FUNCCALL(SETUP_XfOrM404(_), scheme_proc_struct_name_source (a ) ); 
  if ((((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) ) {
    RET_VALUE_START (((((Scheme_Structure * ) a ) -> stype ) -> name ) ) RET_VALUE_END ; 
  }
  else if ((! (((long ) (a ) ) & 0x1 ) && ((((a ) -> type ) >= scheme_prim_type ) && (((a ) -> type ) <= scheme_native_closure_type ) ) ) ) {
    const char * s ; 
    int len ; 
    BLOCK_SETUP((PUSH(s, 0+XfOrM404_COUNT)));
#   define XfOrM412_COUNT (1+XfOrM404_COUNT)
#   define SETUP_XfOrM412(x) SETUP(XfOrM412_COUNT)
    s = NULLED_OUT ; 
    s = FUNCCALL(SETUP_XfOrM412(_), scheme_get_proc_name (a , & len , - 1 ) ); 
    if (s ) {
#     define XfOrM413_COUNT (0+XfOrM412_COUNT)
#     define SETUP_XfOrM413(x) SETUP_XfOrM412(x)
      if (len < 0 )
        RET_VALUE_START ((Scheme_Object * ) s ) RET_VALUE_END ; 
      else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_intern_exact_symbol (s , len ) )) RET_VALUE_EMPTY_END ; 
    }
  }
  else if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_struct_type_type ) ) ) {
    RET_VALUE_START (((Scheme_Struct_Type * ) a ) -> name ) RET_VALUE_END ; 
  }
  else if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_struct_property_type ) ) ) {
    RET_VALUE_START (((Scheme_Struct_Property * ) a ) -> name ) RET_VALUE_END ; 
  }
  else if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_regexp_type ) ) ) {
    Scheme_Object * s ; 
    BLOCK_SETUP((PUSH(s, 0+XfOrM404_COUNT)));
#   define XfOrM409_COUNT (1+XfOrM404_COUNT)
#   define SETUP_XfOrM409(x) SETUP(XfOrM409_COUNT)
    s = NULLED_OUT ; 
    s = FUNCCALL(SETUP_XfOrM409(_), scheme_regexp_source (a ) ); 
    if (s )
      RET_VALUE_START (s ) RET_VALUE_END ; 
  }
  else if ((scheme_is_input_port (a ) ) ) {
    Scheme_Input_Port * ip ; 
    BLOCK_SETUP((PUSH(ip, 0+XfOrM404_COUNT)));
#   define XfOrM408_COUNT (1+XfOrM404_COUNT)
#   define SETUP_XfOrM408(x) SETUP(XfOrM408_COUNT)
    ip = NULLED_OUT ; 
    ip = FUNCCALL(SETUP_XfOrM408(_), scheme_input_port_record (a ) ); 
    RET_VALUE_START (ip -> name ) RET_VALUE_END ; 
  }
  else if ((scheme_is_output_port (a ) ) ) {
    Scheme_Output_Port * op ; 
    BLOCK_SETUP((PUSH(op, 0+XfOrM404_COUNT)));
#   define XfOrM407_COUNT (1+XfOrM404_COUNT)
#   define SETUP_XfOrM407(x) SETUP(XfOrM407_COUNT)
    op = NULLED_OUT ; 
    op = FUNCCALL(SETUP_XfOrM407(_), scheme_output_port_record (a ) ); 
    RET_VALUE_START (op -> name ) RET_VALUE_END ; 
  }
  else if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_type ) ) ) {
    Scheme_Thread * t = (Scheme_Thread * ) a ; 
    if (t -> name ) {
      RET_VALUE_START (t -> name ) RET_VALUE_END ; 
    }
  }
  RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_arity (Scheme_Object * p ) {
  /* No conversion */
  return get_or_check_arity (p , - 1 , ((void * ) 0 ) ) ; 
}
static Scheme_Object * procedure_arity (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (! (((long ) (argv [0 ] ) ) & 0x1 ) && ((((argv [0 ] ) -> type ) >= scheme_prim_type ) && (((argv [0 ] ) -> type ) <= scheme_native_closure_type ) ) ) )
    scheme_wrong_type ("procedure-arity" , "procedure" , 0 , argc , argv ) ; 
  return get_or_check_arity (argv [0 ] , - 1 , ((void * ) 0 ) ) ; 
}
static Scheme_Object * procedure_arity_includes (int argc , Scheme_Object * argv [] ) {
  long n ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM417_COUNT (1)
# define SETUP_XfOrM417(x) SETUP(XfOrM417_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! (! (((long ) (argv [0 ] ) ) & 0x1 ) && ((((argv [0 ] ) -> type ) >= scheme_prim_type ) && (((argv [0 ] ) -> type ) <= scheme_native_closure_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("procedure-arity-includes?" , "procedure" , 0 , argc , argv ) ); 
  n = FUNCCALL(SETUP_XfOrM417(_), scheme_extract_index ("procedure-arity-includes?" , 1 , argc , argv , - 2 , 0 ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(get_or_check_arity (argv [0 ] , n , argv [1 ] ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int is_arity (Scheme_Object * a , int at_least_ok , int list_ok ) {
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(a, 0)));
# define XfOrM418_COUNT (1)
# define SETUP_XfOrM418(x) SETUP(XfOrM418_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if ((((long ) (a ) ) & 0x1 ) ) {
    RET_VALUE_START (((((long ) (a ) ) >> 1 ) >= 0 ) ) RET_VALUE_END ; 
  }
  else if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) {
    RET_VALUE_START (((& ((Scheme_Bignum * ) a ) -> iso ) -> so . keyex & 0x1 ) ) RET_VALUE_END ; 
  }
  else if (at_least_ok && (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) && (scheme_is_struct_instance (scheme_arity_at_least , a ) ) ) {
#   define XfOrM421_COUNT (0+XfOrM418_COUNT)
#   define SETUP_XfOrM421(x) SETUP_XfOrM418(x)
    a = ((Scheme_Structure * ) a ) -> slots [0 ] ; 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(is_arity (a , 0 , 0 ) )) RET_VALUE_EMPTY_END ; 
  }
  if (! list_ok )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  while (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#   define XfOrM420_COUNT (0+XfOrM418_COUNT)
#   define SETUP_XfOrM420(x) SETUP_XfOrM418(x)
    if (! FUNCCALL(SETUP_XfOrM420(_), is_arity ((((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) , 1 , 0 ) ))
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    a = (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) ; 
  }
  if (((a ) == (scheme_null ) ) )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * procedure_reduce_arity (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * orig , * req , * oa , * ra , * ol , * lra , * ara , * prev , * pr , * tmp , * a [3 ] ; 
  Scheme_Config * __funcarg74 = NULLED_OUT ; 
  Scheme_Object * __funcarg73 = NULLED_OUT ; 
  Scheme_Object * __funcarg72 = NULLED_OUT ; 
  Scheme_Object * __funcarg71 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(14);
  BLOCK_SETUP_TOP((PUSH(ra, 0), PUSH(ol, 1), PUSH(tmp, 2), PUSH(oa, 3), PUSH(argv, 4), PUSHARRAY(a, 3, 5), PUSH(orig, 8), PUSH(req, 9), PUSH(ara, 10), PUSH(prev, 11), PUSH(pr, 12), PUSH(lra, 13)));
# define XfOrM424_COUNT (14)
# define SETUP_XfOrM424(x) SETUP(XfOrM424_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  orig = NULLED_OUT ; 
  req = NULLED_OUT ; 
  oa = NULLED_OUT ; 
  ra = NULLED_OUT ; 
  ol = NULLED_OUT ; 
  lra = NULLED_OUT ; 
  ara = NULLED_OUT ; 
  prev = NULLED_OUT ; 
  pr = NULLED_OUT ; 
  tmp = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  a[2] = NULLED_OUT ; 
  if (! (! (((long ) (argv [0 ] ) ) & 0x1 ) && ((((argv [0 ] ) -> type ) >= scheme_prim_type ) && (((argv [0 ] ) -> type ) <= scheme_native_closure_type ) ) ) )
    FUNCCALL(SETUP_XfOrM424(_), scheme_wrong_type ("procedure-reduce-arity" , "procedure" , 0 , argc , argv ) ); 
  if (! FUNCCALL(SETUP_XfOrM424(_), is_arity (argv [1 ] , 1 , 1 ) )) {
#   define XfOrM566_COUNT (0+XfOrM424_COUNT)
#   define SETUP_XfOrM566(x) SETUP_XfOrM424(x)
    FUNCCALL(SETUP_XfOrM566(_), scheme_wrong_type ("procedure-reduce-arity" , "arity" , 1 , argc , argv ) ); 
  }
  if (! reduced_procedure_struct ) {
#   define XfOrM563_COUNT (0+XfOrM424_COUNT)
#   define SETUP_XfOrM563(x) SETUP_XfOrM424(x)
    FUNCCALL(SETUP_XfOrM563(_), scheme_register_static ((void * ) & reduced_procedure_struct , sizeof (reduced_procedure_struct ) ) ); 
    pr = (__funcarg74 = FUNCCALL(SETUP_XfOrM563(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg74 , MZCONFIG_INSPECTOR ) )) ; 
    while (((Scheme_Inspector * ) pr ) -> superior -> superior ) {
      pr = (Scheme_Object * ) ((Scheme_Inspector * ) pr ) -> superior ; 
    }
    orig = FUNCCALL(SETUP_XfOrM563(_), scheme_builtin_value ("prop:procedure" ) ); 
    reduced_procedure_struct = FUNCCALL(SETUP_XfOrM563(_), scheme_make_proc_struct_type (((void * ) 0 ) , ((void * ) 0 ) , pr , 2 , 0 , scheme_false , ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) , ((void * ) 0 ) ) ); 
  }
  orig = FUNCCALL(SETUP_XfOrM424(_), get_or_check_arity (argv [0 ] , - 1 , ((void * ) 0 ) ) ); 
  req = argv [1 ] ; 
  if (! ((Scheme_Type ) (((((long ) (orig ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (orig ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ! ((orig ) == (scheme_null ) ) )
    orig = FUNCCALL(SETUP_XfOrM424(_), scheme_make_pair (orig , scheme_null ) ); 
  if (! ((Scheme_Type ) (((((long ) (req ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (req ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ! ((req ) == (scheme_null ) ) )
    req = FUNCCALL(SETUP_XfOrM424(_), scheme_make_pair (req , scheme_null ) ); 
  while (! ((req ) == (scheme_null ) ) ) {
#   define XfOrM494_COUNT (0+XfOrM424_COUNT)
#   define SETUP_XfOrM494(x) SETUP_XfOrM424(x)
    ra = (((Scheme_Simple_Object * ) (req ) ) -> u . pair_val . car ) ; 
    if ((((Scheme_Type ) (((((long ) (ra ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ra ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (ra ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ra ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) && (scheme_is_struct_instance (scheme_arity_at_least , ra ) ) ) {
#     define XfOrM562_COUNT (0+XfOrM494_COUNT)
#     define SETUP_XfOrM562(x) SETUP_XfOrM494(x)
      ra = (__funcarg73 = FUNCCALL(SETUP_XfOrM562(_), scheme_make_pair (((Scheme_Structure * ) ra ) -> slots [0 ] , scheme_false ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg73 , scheme_null ) )) ; 
    }
    for (ol = orig ; ! ((ol ) == (scheme_null ) ) ; ol = (((Scheme_Simple_Object * ) (ol ) ) -> u . pair_val . cdr ) ) {
#     define XfOrM529_COUNT (0+XfOrM494_COUNT)
#     define SETUP_XfOrM529(x) SETUP_XfOrM494(x)
      oa = (((Scheme_Simple_Object * ) (ol ) ) -> u . pair_val . car ) ; 
      if ((((long ) (ra ) ) & 0x1 ) || ((Scheme_Type ) (((((long ) (ra ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ra ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) {
#       define XfOrM559_COUNT (0+XfOrM529_COUNT)
#       define SETUP_XfOrM559(x) SETUP_XfOrM529(x)
        if ((((long ) (oa ) ) & 0x1 ) || ((Scheme_Type ) (((((long ) (oa ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (oa ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) {
#         define XfOrM561_COUNT (0+XfOrM559_COUNT)
#         define SETUP_XfOrM561(x) SETUP_XfOrM559(x)
          if (FUNCCALL(SETUP_XfOrM561(_), scheme_equal (ra , oa ) ))
            break ; 
        }
        else {
#         define XfOrM560_COUNT (0+XfOrM559_COUNT)
#         define SETUP_XfOrM560(x) SETUP_XfOrM559(x)
          oa = ((Scheme_Structure * ) oa ) -> slots [0 ] ; 
          if (FUNCCALL(SETUP_XfOrM560(_), scheme_bin_lt_eq (oa , ra ) ))
            break ; 
        }
      }
      else {
        int at_least ; 
#       define XfOrM530_COUNT (0+XfOrM529_COUNT)
#       define SETUP_XfOrM530(x) SETUP_XfOrM529(x)
        if ((((long ) (oa ) ) & 0x1 ) || ((Scheme_Type ) (((((long ) (oa ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (oa ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) {
          at_least = 0 ; 
        }
        else {
          at_least = 1 ; 
          oa = ((Scheme_Structure * ) oa ) -> slots [0 ] ; 
        }
        lra = ra ; 
        prev = ((void * ) 0 ) ; 
        while (! ((lra ) == (scheme_null ) ) ) {
#         define XfOrM544_COUNT (0+XfOrM530_COUNT)
#         define SETUP_XfOrM544(x) SETUP_XfOrM530(x)
          ara = (((Scheme_Simple_Object * ) (lra ) ) -> u . pair_val . car ) ; 
          if (((((((Scheme_Simple_Object * ) (ara ) ) -> u . pair_val . cdr ) ) ) == (scheme_false ) ) || FUNCCALL(SETUP_XfOrM544(_), scheme_bin_lt_eq (oa , (((Scheme_Simple_Object * ) (ara ) ) -> u . pair_val . cdr ) ) )) {
#           define XfOrM545_COUNT (0+XfOrM544_COUNT)
#           define SETUP_XfOrM545(x) SETUP_XfOrM544(x)
            if (FUNCCALL(SETUP_XfOrM545(_), scheme_bin_gt_eq (oa , (((Scheme_Simple_Object * ) (ara ) ) -> u . pair_val . car ) ) )) {
#             define XfOrM547_COUNT (0+XfOrM545_COUNT)
#             define SETUP_XfOrM547(x) SETUP_XfOrM545(x)
              if (FUNCCALL(SETUP_XfOrM547(_), scheme_equal (oa , (((Scheme_Simple_Object * ) (ara ) ) -> u . pair_val . car ) ) )) {
#               define XfOrM552_COUNT (0+XfOrM547_COUNT)
#               define SETUP_XfOrM552(x) SETUP_XfOrM547(x)
                if (at_least ) {
                  if (prev )
                    (((Scheme_Simple_Object * ) (prev ) ) -> u . pair_val . cdr ) = scheme_null ; 
                  else ra = scheme_null ; 
                }
                else {
#                 define XfOrM553_COUNT (0+XfOrM552_COUNT)
#                 define SETUP_XfOrM553(x) SETUP_XfOrM552(x)
                  if (FUNCCALL(SETUP_XfOrM553(_), scheme_equal (oa , (((Scheme_Simple_Object * ) (ara ) ) -> u . pair_val . cdr ) ) )) {
                    if (prev )
                      (((Scheme_Simple_Object * ) (prev ) ) -> u . pair_val . cdr ) = (((Scheme_Simple_Object * ) (lra ) ) -> u . pair_val . cdr ) ; 
                    else ra = (((Scheme_Simple_Object * ) (lra ) ) -> u . pair_val . cdr ) ; 
                  }
                  else {
#                   define XfOrM554_COUNT (0+XfOrM553_COUNT)
#                   define SETUP_XfOrM554(x) SETUP_XfOrM553(x)
                    tmp = FUNCCALL(SETUP_XfOrM554(_), scheme_bin_plus (oa , ((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) ) ); 
                    (((Scheme_Simple_Object * ) (ara ) ) -> u . pair_val . car ) = tmp ; 
                  }
                }
              }
              else if (FUNCCALL(SETUP_XfOrM547(_), scheme_equal (oa , (((Scheme_Simple_Object * ) (ara ) ) -> u . pair_val . car ) ) )) {
#               define XfOrM551_COUNT (0+XfOrM547_COUNT)
#               define SETUP_XfOrM551(x) SETUP_XfOrM547(x)
                tmp = FUNCCALL(SETUP_XfOrM551(_), scheme_bin_minus (oa , ((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) ) ); 
                (((Scheme_Simple_Object * ) (ara ) ) -> u . pair_val . cdr ) = tmp ; 
                if (at_least )
                  (((Scheme_Simple_Object * ) (lra ) ) -> u . pair_val . cdr ) = scheme_null ; 
              }
              else {
#               define XfOrM548_COUNT (0+XfOrM547_COUNT)
#               define SETUP_XfOrM548(x) SETUP_XfOrM547(x)
                if (at_least ) {
#                 define XfOrM550_COUNT (0+XfOrM548_COUNT)
#                 define SETUP_XfOrM550(x) SETUP_XfOrM548(x)
                  tmp = FUNCCALL(SETUP_XfOrM550(_), scheme_bin_minus (oa , ((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) ) ); 
                  (((Scheme_Simple_Object * ) (ara ) ) -> u . pair_val . cdr ) = tmp ; 
                  (((Scheme_Simple_Object * ) (lra ) ) -> u . pair_val . cdr ) = scheme_null ; 
                }
                else {
#                 define XfOrM549_COUNT (0+XfOrM548_COUNT)
#                 define SETUP_XfOrM549(x) SETUP_XfOrM548(x)
                  pr = (__funcarg71 = (__funcarg72 = FUNCCALL(SETUP_XfOrM549(_), scheme_bin_plus (oa , ((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg72 , (((Scheme_Simple_Object * ) (ara ) ) -> u . pair_val . cdr ) ) )) , FUNCCALL_AGAIN(scheme_make_pair (__funcarg71 , (((Scheme_Simple_Object * ) (lra ) ) -> u . pair_val . cdr ) ) )) ; 
                  tmp = FUNCCALL(SETUP_XfOrM549(_), scheme_bin_minus (oa , ((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) ) ); 
                  (((Scheme_Simple_Object * ) (ara ) ) -> u . pair_val . cdr ) = tmp ; 
                  (((Scheme_Simple_Object * ) (lra ) ) -> u . pair_val . cdr ) = pr ; 
                }
              }
              break ; 
            }
            else if (at_least ) {
              if (prev )
                (((Scheme_Simple_Object * ) (prev ) ) -> u . pair_val . cdr ) = scheme_null ; 
              else ra = scheme_null ; 
              break ; 
            }
          }
          prev = lra ; 
          lra = (((Scheme_Simple_Object * ) (lra ) ) -> u . pair_val . cdr ) ; 
        }
        if (((ra ) == (scheme_null ) ) )
          break ; 
      }
    }
    if (((ol ) == (scheme_null ) ) ) {
#     define XfOrM495_COUNT (0+XfOrM494_COUNT)
#     define SETUP_XfOrM495(x) SETUP_XfOrM494(x)
      FUNCCALL(SETUP_XfOrM495(_), scheme_raise_exn (MZEXN_FAIL_CONTRACT_CONTINUATION , "procedure-reduce-arity: arity of procedre: %V" " does not include requested arity: %V : %V" , argv [0 ] , argv [1 ] , ra ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    req = (((Scheme_Simple_Object * ) (req ) ) -> u . pair_val . cdr ) ; 
  }
  a [0 ] = argv [0 ] ; 
  pr = FUNCCALL(SETUP_XfOrM424(_), clone_arity (argv [1 ] ) ); 
  a [1 ] = pr ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM424(_), scheme_make_struct_instance (reduced_procedure_struct , 2 , a ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * procedure_equal_closure_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * v1 = argv [0 ] , * v2 = argv [1 ] ; 
  if (! (! (((long ) (v1 ) ) & 0x1 ) && ((((v1 ) -> type ) >= scheme_prim_type ) && (((v1 ) -> type ) <= scheme_native_closure_type ) ) ) )
    scheme_wrong_type ("procedure-closure-contents-eq?" , "procedure" , 0 , argc , argv ) ; 
  if (! (! (((long ) (v2 ) ) & 0x1 ) && ((((v2 ) -> type ) >= scheme_prim_type ) && (((v2 ) -> type ) <= scheme_native_closure_type ) ) ) )
    scheme_wrong_type ("procedure-closure-contents-eq?" , "procedure" , 1 , argc , argv ) ; 
  if (((v1 ) == (v2 ) ) )
    return scheme_true ; 
  if (! ((Scheme_Type ) (((((long ) (v1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v1 ) ) -> type ) ) == (Scheme_Type ) (((((long ) (v2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v2 ) ) -> type ) ) ) )
    return scheme_false ; 
  switch (((((long ) (v1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v1 ) ) -> type ) ) {
    case scheme_prim_type : {
      Scheme_Primitive_Proc * p1 = (Scheme_Primitive_Proc * ) v1 ; 
      Scheme_Primitive_Proc * p2 = (Scheme_Primitive_Proc * ) v2 ; 
      if (p1 -> prim_val == p2 -> prim_val ) {
        if (p1 -> pp . flags & 4096 ) {
          if (! (p2 -> pp . flags & 4096 ) )
            return scheme_false ; 
          return scheme_false ; 
        }
        else if (! (p2 -> pp . flags & 4096 ) )
          return scheme_true ; 
      }
    }
    break ; 
    case scheme_closure_type : {
      Scheme_Closure * c1 = (Scheme_Closure * ) v1 ; 
      Scheme_Closure * c2 = (Scheme_Closure * ) v2 ; 
      if (((c1 -> code ) == (c2 -> code ) ) ) {
        int i ; 
        for (i = c1 -> code -> closure_size ; i -- ; ) {
          if (! ((c1 -> vals [i ] ) == (c2 -> vals [i ] ) ) )
            return scheme_false ; 
        }
        return scheme_true ; 
      }
    }
    break ; 
    case scheme_native_closure_type : {
      Scheme_Native_Closure * c1 = (Scheme_Native_Closure * ) v1 ; 
      Scheme_Native_Closure * c2 = (Scheme_Native_Closure * ) v2 ; 
      if (((c1 -> code ) == (c2 -> code ) ) ) {
        int i ; 
        i = c1 -> code -> closure_size ; 
        if (i < 0 ) {
          Scheme_Native_Closure * sc1 , * sc2 ; 
          int j ; 
          i = - (i + 1 ) ; 
          while (i -- ) {
            sc1 = (Scheme_Native_Closure * ) c1 -> vals [i ] ; 
            sc2 = (Scheme_Native_Closure * ) c2 -> vals [i ] ; 
            j = sc1 -> code -> closure_size ; 
            while (j -- ) {
              if (! ((sc1 -> vals [j ] ) == (sc2 -> vals [j ] ) ) )
                return scheme_false ; 
            }
          }
        }
        else {
          while (i -- ) {
            if (! ((c1 -> vals [i ] ) == (c2 -> vals [i ] ) ) )
              return scheme_false ; 
          }
        }
        return scheme_true ; 
      }
    }
    break ; 
    case scheme_case_closure_type : {
      Scheme_Case_Lambda * c1 = (Scheme_Case_Lambda * ) v1 ; 
      Scheme_Case_Lambda * c2 = (Scheme_Case_Lambda * ) v2 ; 
      if (c1 -> count == c2 -> count ) {
        Scheme_Closure * sc1 , * sc2 ; 
        int i , j ; 
        for (i = c1 -> count ; i -- ; ) {
          sc1 = (Scheme_Closure * ) c1 -> array [i ] ; 
          sc2 = (Scheme_Closure * ) c2 -> array [i ] ; 
          if (! ((sc1 -> code ) == (sc2 -> code ) ) )
            return scheme_false ; 
          for (j = sc1 -> code -> closure_size ; j -- ; ) {
            if (! ((sc1 -> vals [j ] ) == (sc2 -> vals [j ] ) ) )
              return scheme_false ; 
          }
        }
        return scheme_true ; 
      }
    }
    break ; 
  }
  return scheme_false ; 
}
static Scheme_Object * apply (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * rands ; 
  Scheme_Object * * rand_vec ; 
  int i , num_rands ; 
  Scheme_Thread * p = scheme_current_thread ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(rand_vec, 0), PUSH(rands, 1), PUSH(argv, 2), PUSH(p, 3)));
# define XfOrM596_COUNT (4)
# define SETUP_XfOrM596(x) SETUP(XfOrM596_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  rands = NULLED_OUT ; 
  rand_vec = NULLED_OUT ; 
  if (! (! (((long ) (argv [0 ] ) ) & 0x1 ) && ((((argv [0 ] ) -> type ) >= scheme_prim_type ) && (((argv [0 ] ) -> type ) <= scheme_native_closure_type ) ) ) ) {
#   define XfOrM603_COUNT (0+XfOrM596_COUNT)
#   define SETUP_XfOrM603(x) SETUP_XfOrM596(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("apply" , "procedure" , 0 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  rands = argv [argc - 1 ] ; 
  num_rands = FUNCCALL(SETUP_XfOrM596(_), scheme_proper_list_length (rands ) ); 
  if (num_rands < 0 ) {
#   define XfOrM602_COUNT (0+XfOrM596_COUNT)
#   define SETUP_XfOrM602(x) SETUP_XfOrM596(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("apply" , "proper list" , argc - 1 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  num_rands += (argc - 2 ) ; 
  if (num_rands > p -> tail_buffer_size ) {
#   define XfOrM601_COUNT (0+XfOrM596_COUNT)
#   define SETUP_XfOrM601(x) SETUP_XfOrM596(x)
    rand_vec = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM601(_), GC_malloc (sizeof (Scheme_Object * ) * (num_rands ) ) )) ; 
  }
  else rand_vec = p -> tail_buffer ; 
  for (i = argc - 2 ; i -- ; ) {
    rand_vec [i ] = argv [i + 1 ] ; 
  }
  for (i = argc - 2 ; ((Scheme_Type ) (((((long ) (rands ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rands ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; i ++ , rands = (((Scheme_Simple_Object * ) (rands ) ) -> u . pair_val . cdr ) ) {
    rand_vec [i ] = (((Scheme_Simple_Object * ) (rands ) ) -> u . pair_val . car ) ; 
  }
  p -> ku . apply . tail_rator = argv [0 ] ; 
  p -> ku . apply . tail_rands = rand_vec ; 
  p -> ku . apply . tail_num_rands = num_rands ; 
  RET_VALUE_START (((Scheme_Object * ) 0x4 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * map (int argc , Scheme_Object * argv [] ) {
  int i , size = 0 , l , pos ; 
  Scheme_Object * quick1 [3 ] , * quick2 [3 ] ; 
  Scheme_Object * * working , * * args ; 
  Scheme_Object * quick3 [5 ] , * * resarray ; 
  Scheme_Object * v ; 
  int cc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(15);
  BLOCK_SETUP_TOP((PUSH(working, 0), PUSH(argv, 1), PUSHARRAY(quick3, 5, 2), PUSHARRAY(quick1, 3, 5), PUSH(args, 8), PUSH(v, 9), PUSHARRAY(quick2, 3, 10), PUSH(resarray, 13)));
# define XfOrM604_COUNT (14)
# define SETUP_XfOrM604(x) SETUP(XfOrM604_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  quick1[0] = NULLED_OUT ; 
  quick1[1] = NULLED_OUT ; 
  quick1[2] = NULLED_OUT ; 
  quick2[0] = NULLED_OUT ; 
  quick2[1] = NULLED_OUT ; 
  quick2[2] = NULLED_OUT ; 
  working = NULLED_OUT ; 
  args = NULLED_OUT ; 
  NULL_OUT_ARRAY (quick3 ) ; 
  resarray = NULLED_OUT ; 
  v = NULLED_OUT ; 
  if (! (! (((long ) (argv [0 ] ) ) & 0x1 ) && ((((argv [0 ] ) -> type ) >= scheme_prim_type ) && (((argv [0 ] ) -> type ) <= scheme_native_closure_type ) ) ) )
    FUNCCALL(SETUP_XfOrM604(_), scheme_wrong_type ("map" , "procedure" , 0 , argc , argv ) ); 
  for (i = 1 ; i < argc ; i ++ ) {
#   define XfOrM628_COUNT (0+XfOrM604_COUNT)
#   define SETUP_XfOrM628(x) SETUP_XfOrM604(x)
    l = FUNCCALL(SETUP_XfOrM628(_), scheme_proper_list_length (argv [i ] ) ); 
    if (l < 0 )
      FUNCCALL(SETUP_XfOrM628(_), scheme_wrong_type ("map" , "proper list" , i , argc , argv ) ); 
    if (i == 1 )
      size = l ; 
    else if (size != l ) {
      char * argstr ; 
      long alen ; 
      BLOCK_SETUP((PUSH(argstr, 0+XfOrM628_COUNT)));
#     define XfOrM629_COUNT (1+XfOrM628_COUNT)
#     define SETUP_XfOrM629(x) SETUP(XfOrM629_COUNT)
      argstr = NULLED_OUT ; 
      argstr = FUNCCALL(SETUP_XfOrM629(_), scheme_make_args_string ("" , - 1 , argc , argv , & alen ) ); 
      FUNCCALL_AGAIN(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: all lists must have same size%t" , "map" , argstr , alen ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  if ((((FUNCCALL(SETUP_XfOrM604(_), scheme_get_or_check_arity (argv [0 ] , argc - 1 ) )) ) == (scheme_false ) ) ) {
    char * s ; 
    long aelen ; 
    BLOCK_SETUP((PUSH(s, 0+XfOrM604_COUNT)));
#   define XfOrM625_COUNT (1+XfOrM604_COUNT)
#   define SETUP_XfOrM625(x) SETUP(XfOrM625_COUNT)
    s = NULLED_OUT ; 
    s = FUNCCALL(SETUP_XfOrM625(_), scheme_make_arity_expect_string (argv [0 ] , argc - 1 , ((void * ) 0 ) , & aelen ) ); 
    FUNCCALL_AGAIN(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: arity mismatch for %t" , "map" , s , aelen ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (argc <= (3 + 1 ) ) {
    args = quick1 ; 
    working = quick2 ; 
  }
  else {
#   define XfOrM623_COUNT (0+XfOrM604_COUNT)
#   define SETUP_XfOrM623(x) SETUP_XfOrM604(x)
    args = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM623(_), GC_malloc (sizeof (Scheme_Object * ) * (argc - 1 ) ) )) ; 
    working = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM623(_), GC_malloc (sizeof (Scheme_Object * ) * (argc - 1 ) ) )) ; 
  }
  if (size <= 5 )
    resarray = quick3 ; 
  else resarray = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM604(_), GC_malloc (sizeof (Scheme_Object * ) * (size ) ) )) ; 
  for (i = 1 ; i < argc ; i ++ ) {
    working [i - 1 ] = argv [i ] ; 
  }
  -- argc ; 
  pos = 0 ; 
  while (pos < size ) {
#   define XfOrM613_COUNT (0+XfOrM604_COUNT)
#   define SETUP_XfOrM613(x) SETUP_XfOrM604(x)
    for (i = 0 ; i < argc ; i ++ ) {
#     define XfOrM619_COUNT (0+XfOrM613_COUNT)
#     define SETUP_XfOrM619(x) SETUP_XfOrM613(x)
      if (! ((Scheme_Type ) (((((long ) (working [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (working [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#       define XfOrM620_COUNT (0+XfOrM619_COUNT)
#       define SETUP_XfOrM620(x) SETUP_XfOrM619(x)
        FUNCCALL(SETUP_XfOrM620(_), scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: argument list mutated" , "map" ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      args [i ] = (((Scheme_Simple_Object * ) (working [i ] ) ) -> u . pair_val . car ) ; 
      working [i ] = (((Scheme_Simple_Object * ) (working [i ] ) ) -> u . pair_val . cdr ) ; 
    }
    cc = scheme_cont_capture_count ; 
    v = FUNCCALL(SETUP_XfOrM613(_), scheme_do_eval (argv [0 ] , argc , args , 1 ) ); 
    if (cc != scheme_cont_capture_count ) {
#     define XfOrM614_COUNT (0+XfOrM613_COUNT)
#     define SETUP_XfOrM614(x) SETUP_XfOrM613(x)
      if (size > 5 ) {
        Scheme_Object * * naya ; 
        BLOCK_SETUP((PUSH(naya, 0+XfOrM614_COUNT)));
#       define XfOrM616_COUNT (1+XfOrM614_COUNT)
#       define SETUP_XfOrM616(x) SETUP(XfOrM616_COUNT)
        naya = NULLED_OUT ; 
        naya = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM616(_), GC_malloc (sizeof (Scheme_Object * ) * (size ) ) )) ; 
        (memcpy (naya , resarray , pos * sizeof (Scheme_Object * ) ) ) ; 
        resarray = naya ; 
      }
      if ((argc > 3 ) && (pos + 1 < size ) ) {
        Scheme_Object * * naya ; 
        BLOCK_SETUP((PUSH(naya, 0+XfOrM614_COUNT)));
#       define XfOrM615_COUNT (1+XfOrM614_COUNT)
#       define SETUP_XfOrM615(x) SETUP(XfOrM615_COUNT)
        naya = NULLED_OUT ; 
        args = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM615(_), GC_malloc (sizeof (Scheme_Object * ) * (argc ) ) )) ; 
        naya = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM615(_), GC_malloc (sizeof (Scheme_Object * ) * (argc ) ) )) ; 
        (memcpy (naya , working , argc * sizeof (Scheme_Object * ) ) ) ; 
        working = naya ; 
      }
    }
    resarray [pos ] = v ; 
    pos ++ ; 
  }
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM604(_), scheme_build_list (size , resarray ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * for_each (int argc , Scheme_Object * argv [] ) {
  int i , size = 0 , l , pos ; 
  Scheme_Object * quick1 [3 ] , * quick2 [3 ] ; 
  Scheme_Object * * working , * * args ; 
  int cc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(10);
  BLOCK_SETUP_TOP((PUSH(args, 0), PUSH(argv, 1), PUSH(working, 2), PUSHARRAY(quick2, 3, 3), PUSHARRAY(quick1, 3, 6)));
# define XfOrM630_COUNT (9)
# define SETUP_XfOrM630(x) SETUP(XfOrM630_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  quick1[0] = NULLED_OUT ; 
  quick1[1] = NULLED_OUT ; 
  quick1[2] = NULLED_OUT ; 
  quick2[0] = NULLED_OUT ; 
  quick2[1] = NULLED_OUT ; 
  quick2[2] = NULLED_OUT ; 
  working = NULLED_OUT ; 
  args = NULLED_OUT ; 
  if (! (! (((long ) (argv [0 ] ) ) & 0x1 ) && ((((argv [0 ] ) -> type ) >= scheme_prim_type ) && (((argv [0 ] ) -> type ) <= scheme_native_closure_type ) ) ) )
    FUNCCALL(SETUP_XfOrM630(_), scheme_wrong_type ("for-each" , "procedure" , 0 , argc , argv ) ); 
  for (i = 1 ; i < argc ; i ++ ) {
#   define XfOrM652_COUNT (0+XfOrM630_COUNT)
#   define SETUP_XfOrM652(x) SETUP_XfOrM630(x)
    l = FUNCCALL(SETUP_XfOrM652(_), scheme_proper_list_length (argv [i ] ) ); 
    if (l < 0 )
      FUNCCALL(SETUP_XfOrM652(_), scheme_wrong_type ("for-each" , "proper list" , i , argc , argv ) ); 
    if (i == 1 )
      size = l ; 
    else if (size != l ) {
      char * argstr ; 
      long alen ; 
      BLOCK_SETUP((PUSH(argstr, 0+XfOrM652_COUNT)));
#     define XfOrM653_COUNT (1+XfOrM652_COUNT)
#     define SETUP_XfOrM653(x) SETUP(XfOrM653_COUNT)
      argstr = NULLED_OUT ; 
      argstr = FUNCCALL(SETUP_XfOrM653(_), scheme_make_args_string ("" , - 1 , argc , argv , & alen ) ); 
      FUNCCALL_AGAIN(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: all lists must have same size%t" , "for-each" , argstr , alen ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  if ((((FUNCCALL(SETUP_XfOrM630(_), scheme_get_or_check_arity (argv [0 ] , argc - 1 ) )) ) == (scheme_false ) ) ) {
    char * s ; 
    long aelen ; 
    BLOCK_SETUP((PUSH(s, 0+XfOrM630_COUNT)));
#   define XfOrM649_COUNT (1+XfOrM630_COUNT)
#   define SETUP_XfOrM649(x) SETUP(XfOrM649_COUNT)
    s = NULLED_OUT ; 
    s = FUNCCALL(SETUP_XfOrM649(_), scheme_make_arity_expect_string (argv [0 ] , argc - 1 , ((void * ) 0 ) , & aelen ) ); 
    FUNCCALL_AGAIN(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: arity mismatch for %t" , "for-each" , s , aelen ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (argc <= (3 + 1 ) ) {
    args = quick1 ; 
    working = quick2 ; 
  }
  else {
#   define XfOrM647_COUNT (0+XfOrM630_COUNT)
#   define SETUP_XfOrM647(x) SETUP_XfOrM630(x)
    args = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM647(_), GC_malloc (sizeof (Scheme_Object * ) * (argc - 1 ) ) )) ; 
    working = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM647(_), GC_malloc (sizeof (Scheme_Object * ) * (argc - 1 ) ) )) ; 
  }
  for (i = 1 ; i < argc ; i ++ ) {
    working [i - 1 ] = argv [i ] ; 
  }
  -- argc ; 
  pos = 0 ; 
  while (pos < size ) {
#   define XfOrM638_COUNT (0+XfOrM630_COUNT)
#   define SETUP_XfOrM638(x) SETUP_XfOrM630(x)
    for (i = 0 ; i < argc ; i ++ ) {
#     define XfOrM643_COUNT (0+XfOrM638_COUNT)
#     define SETUP_XfOrM643(x) SETUP_XfOrM638(x)
      if (! ((Scheme_Type ) (((((long ) (working [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (working [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#       define XfOrM644_COUNT (0+XfOrM643_COUNT)
#       define SETUP_XfOrM644(x) SETUP_XfOrM643(x)
        FUNCCALL(SETUP_XfOrM644(_), scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: argument list mutated" , "for-each" ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      args [i ] = (((Scheme_Simple_Object * ) (working [i ] ) ) -> u . pair_val . car ) ; 
      working [i ] = (((Scheme_Simple_Object * ) (working [i ] ) ) -> u . pair_val . cdr ) ; 
    }
    cc = scheme_cont_capture_count ; 
    FUNCCALL(SETUP_XfOrM638(_), scheme_do_eval (argv [0 ] , argc , args , - 1 ) ); 
    if (cc != scheme_cont_capture_count ) {
#     define XfOrM639_COUNT (0+XfOrM638_COUNT)
#     define SETUP_XfOrM639(x) SETUP_XfOrM638(x)
      if ((argc > 3 ) && (pos + 1 < size ) ) {
        Scheme_Object * * naya ; 
        BLOCK_SETUP((PUSH(naya, 0+XfOrM639_COUNT)));
#       define XfOrM640_COUNT (1+XfOrM639_COUNT)
#       define SETUP_XfOrM640(x) SETUP(XfOrM640_COUNT)
        naya = NULLED_OUT ; 
        args = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM640(_), GC_malloc (sizeof (Scheme_Object * ) * (argc ) ) )) ; 
        naya = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM640(_), GC_malloc (sizeof (Scheme_Object * ) * (argc ) ) )) ; 
        (memcpy (naya , working , argc * sizeof (Scheme_Object * ) ) ) ; 
        working = naya ; 
      }
    }
    pos ++ ; 
  }
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * andmap (int argc , Scheme_Object * argv [] ) {
  int i , size = 0 , l , pos ; 
  Scheme_Object * quick1 [3 ] , * quick2 [3 ] ; 
  Scheme_Object * * working , * * args ; 
  Scheme_Object * v ; 
  int cc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(11);
  BLOCK_SETUP_TOP((PUSH(args, 0), PUSH(argv, 1), PUSH(working, 2), PUSH(v, 3), PUSHARRAY(quick2, 3, 4), PUSHARRAY(quick1, 3, 7)));
# define XfOrM654_COUNT (10)
# define SETUP_XfOrM654(x) SETUP(XfOrM654_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  quick1[0] = NULLED_OUT ; 
  quick1[1] = NULLED_OUT ; 
  quick1[2] = NULLED_OUT ; 
  quick2[0] = NULLED_OUT ; 
  quick2[1] = NULLED_OUT ; 
  quick2[2] = NULLED_OUT ; 
  working = NULLED_OUT ; 
  args = NULLED_OUT ; 
  v = NULLED_OUT ; 
  if (! (! (((long ) (argv [0 ] ) ) & 0x1 ) && ((((argv [0 ] ) -> type ) >= scheme_prim_type ) && (((argv [0 ] ) -> type ) <= scheme_native_closure_type ) ) ) )
    FUNCCALL(SETUP_XfOrM654(_), scheme_wrong_type ("andmap" , "procedure" , 0 , argc , argv ) ); 
  for (i = 1 ; i < argc ; i ++ ) {
#   define XfOrM680_COUNT (0+XfOrM654_COUNT)
#   define SETUP_XfOrM680(x) SETUP_XfOrM654(x)
    l = FUNCCALL(SETUP_XfOrM680(_), scheme_proper_list_length (argv [i ] ) ); 
    if (l < 0 )
      FUNCCALL(SETUP_XfOrM680(_), scheme_wrong_type ("andmap" , "proper list" , i , argc , argv ) ); 
    if (i == 1 )
      size = l ; 
    else if (size != l ) {
      char * argstr ; 
      long alen ; 
      BLOCK_SETUP((PUSH(argstr, 0+XfOrM680_COUNT)));
#     define XfOrM681_COUNT (1+XfOrM680_COUNT)
#     define SETUP_XfOrM681(x) SETUP(XfOrM681_COUNT)
      argstr = NULLED_OUT ; 
      argstr = FUNCCALL(SETUP_XfOrM681(_), scheme_make_args_string ("" , - 1 , argc , argv , & alen ) ); 
      FUNCCALL_AGAIN(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: all lists must have same size%t" , "andmap" , argstr , alen ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  if ((((FUNCCALL(SETUP_XfOrM654(_), scheme_get_or_check_arity (argv [0 ] , argc - 1 ) )) ) == (scheme_false ) ) ) {
    char * s ; 
    long aelen ; 
    BLOCK_SETUP((PUSH(s, 0+XfOrM654_COUNT)));
#   define XfOrM677_COUNT (1+XfOrM654_COUNT)
#   define SETUP_XfOrM677(x) SETUP(XfOrM677_COUNT)
    s = NULLED_OUT ; 
    s = FUNCCALL(SETUP_XfOrM677(_), scheme_make_arity_expect_string (argv [0 ] , argc - 1 , ((void * ) 0 ) , & aelen ) ); 
    FUNCCALL_AGAIN(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: arity mismatch for %t" , "andmap" , s , aelen ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (argc <= (3 + 1 ) ) {
    args = quick1 ; 
    working = quick2 ; 
  }
  else {
#   define XfOrM675_COUNT (0+XfOrM654_COUNT)
#   define SETUP_XfOrM675(x) SETUP_XfOrM654(x)
    args = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM675(_), GC_malloc (sizeof (Scheme_Object * ) * (argc - 1 ) ) )) ; 
    working = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM675(_), GC_malloc (sizeof (Scheme_Object * ) * (argc - 1 ) ) )) ; 
  }
  for (i = 1 ; i < argc ; i ++ ) {
    working [i - 1 ] = argv [i ] ; 
  }
  -- argc ; 
  pos = 0 ; 
  while (pos < size ) {
#   define XfOrM664_COUNT (0+XfOrM654_COUNT)
#   define SETUP_XfOrM664(x) SETUP_XfOrM654(x)
    for (i = 0 ; i < argc ; i ++ ) {
#     define XfOrM671_COUNT (0+XfOrM664_COUNT)
#     define SETUP_XfOrM671(x) SETUP_XfOrM664(x)
      if (! ((Scheme_Type ) (((((long ) (working [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (working [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#       define XfOrM672_COUNT (0+XfOrM671_COUNT)
#       define SETUP_XfOrM672(x) SETUP_XfOrM671(x)
        FUNCCALL(SETUP_XfOrM672(_), scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: argument list mutated" , "andmap" ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      args [i ] = (((Scheme_Simple_Object * ) (working [i ] ) ) -> u . pair_val . car ) ; 
      working [i ] = (((Scheme_Simple_Object * ) (working [i ] ) ) -> u . pair_val . cdr ) ; 
    }
    cc = scheme_cont_capture_count ; 
    if (pos + 1 == size ) {
#     define XfOrM668_COUNT (0+XfOrM664_COUNT)
#     define SETUP_XfOrM668(x) SETUP_XfOrM664(x)
      RET_VALUE_START (FUNCCALL(SETUP_XfOrM668(_), scheme_tail_apply (argv [0 ] , argc , args ) )) RET_VALUE_END ; 
    }
    else {
#     define XfOrM667_COUNT (0+XfOrM664_COUNT)
#     define SETUP_XfOrM667(x) SETUP_XfOrM664(x)
      v = FUNCCALL(SETUP_XfOrM667(_), scheme_do_eval (argv [0 ] , argc , args , 1 ) ); 
    }
    if (cc != scheme_cont_capture_count ) {
#     define XfOrM665_COUNT (0+XfOrM664_COUNT)
#     define SETUP_XfOrM665(x) SETUP_XfOrM664(x)
      if ((argc > 3 ) && (pos + 1 < size ) ) {
        Scheme_Object * * naya ; 
        BLOCK_SETUP((PUSH(naya, 0+XfOrM665_COUNT)));
#       define XfOrM666_COUNT (1+XfOrM665_COUNT)
#       define SETUP_XfOrM666(x) SETUP(XfOrM666_COUNT)
        naya = NULLED_OUT ; 
        args = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM666(_), GC_malloc (sizeof (Scheme_Object * ) * (argc ) ) )) ; 
        naya = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM666(_), GC_malloc (sizeof (Scheme_Object * ) * (argc ) ) )) ; 
        (memcpy (naya , working , argc * sizeof (Scheme_Object * ) ) ) ; 
        working = naya ; 
      }
    }
    if ((((v ) ) == (scheme_false ) ) )
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    pos ++ ; 
  }
  RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * ormap (int argc , Scheme_Object * argv [] ) {
  int i , size = 0 , l , pos ; 
  Scheme_Object * quick1 [3 ] , * quick2 [3 ] ; 
  Scheme_Object * * working , * * args ; 
  Scheme_Object * v ; 
  int cc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(11);
  BLOCK_SETUP_TOP((PUSH(args, 0), PUSH(argv, 1), PUSH(working, 2), PUSH(v, 3), PUSHARRAY(quick2, 3, 4), PUSHARRAY(quick1, 3, 7)));
# define XfOrM682_COUNT (10)
# define SETUP_XfOrM682(x) SETUP(XfOrM682_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  quick1[0] = NULLED_OUT ; 
  quick1[1] = NULLED_OUT ; 
  quick1[2] = NULLED_OUT ; 
  quick2[0] = NULLED_OUT ; 
  quick2[1] = NULLED_OUT ; 
  quick2[2] = NULLED_OUT ; 
  working = NULLED_OUT ; 
  args = NULLED_OUT ; 
  v = NULLED_OUT ; 
  if (! (! (((long ) (argv [0 ] ) ) & 0x1 ) && ((((argv [0 ] ) -> type ) >= scheme_prim_type ) && (((argv [0 ] ) -> type ) <= scheme_native_closure_type ) ) ) )
    FUNCCALL(SETUP_XfOrM682(_), scheme_wrong_type ("ormap" , "procedure" , 0 , argc , argv ) ); 
  for (i = 1 ; i < argc ; i ++ ) {
#   define XfOrM708_COUNT (0+XfOrM682_COUNT)
#   define SETUP_XfOrM708(x) SETUP_XfOrM682(x)
    l = FUNCCALL(SETUP_XfOrM708(_), scheme_proper_list_length (argv [i ] ) ); 
    if (l < 0 )
      FUNCCALL(SETUP_XfOrM708(_), scheme_wrong_type ("ormap" , "proper list" , i , argc , argv ) ); 
    if (i == 1 )
      size = l ; 
    else if (size != l ) {
      char * argstr ; 
      long alen ; 
      BLOCK_SETUP((PUSH(argstr, 0+XfOrM708_COUNT)));
#     define XfOrM709_COUNT (1+XfOrM708_COUNT)
#     define SETUP_XfOrM709(x) SETUP(XfOrM709_COUNT)
      argstr = NULLED_OUT ; 
      argstr = FUNCCALL(SETUP_XfOrM709(_), scheme_make_args_string ("" , - 1 , argc , argv , & alen ) ); 
      FUNCCALL_AGAIN(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: all lists must have same size%t" , "ormap" , argstr , alen ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  if ((((FUNCCALL(SETUP_XfOrM682(_), scheme_get_or_check_arity (argv [0 ] , argc - 1 ) )) ) == (scheme_false ) ) ) {
    char * s ; 
    long aelen ; 
    BLOCK_SETUP((PUSH(s, 0+XfOrM682_COUNT)));
#   define XfOrM705_COUNT (1+XfOrM682_COUNT)
#   define SETUP_XfOrM705(x) SETUP(XfOrM705_COUNT)
    s = NULLED_OUT ; 
    s = FUNCCALL(SETUP_XfOrM705(_), scheme_make_arity_expect_string (argv [0 ] , argc - 1 , ((void * ) 0 ) , & aelen ) ); 
    FUNCCALL_AGAIN(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: arity mismatch for %t" , "ormap" , s , aelen ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (argc <= (3 + 1 ) ) {
    args = quick1 ; 
    working = quick2 ; 
  }
  else {
#   define XfOrM703_COUNT (0+XfOrM682_COUNT)
#   define SETUP_XfOrM703(x) SETUP_XfOrM682(x)
    args = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM703(_), GC_malloc (sizeof (Scheme_Object * ) * (argc - 1 ) ) )) ; 
    working = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM703(_), GC_malloc (sizeof (Scheme_Object * ) * (argc - 1 ) ) )) ; 
  }
  for (i = 1 ; i < argc ; i ++ ) {
    working [i - 1 ] = argv [i ] ; 
  }
  -- argc ; 
  pos = 0 ; 
  while (pos < size ) {
#   define XfOrM692_COUNT (0+XfOrM682_COUNT)
#   define SETUP_XfOrM692(x) SETUP_XfOrM682(x)
    for (i = 0 ; i < argc ; i ++ ) {
#     define XfOrM699_COUNT (0+XfOrM692_COUNT)
#     define SETUP_XfOrM699(x) SETUP_XfOrM692(x)
      if (! ((Scheme_Type ) (((((long ) (working [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (working [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#       define XfOrM700_COUNT (0+XfOrM699_COUNT)
#       define SETUP_XfOrM700(x) SETUP_XfOrM699(x)
        FUNCCALL(SETUP_XfOrM700(_), scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: argument list mutated" , "ormap" ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      args [i ] = (((Scheme_Simple_Object * ) (working [i ] ) ) -> u . pair_val . car ) ; 
      working [i ] = (((Scheme_Simple_Object * ) (working [i ] ) ) -> u . pair_val . cdr ) ; 
    }
    cc = scheme_cont_capture_count ; 
    if (pos + 1 == size ) {
#     define XfOrM696_COUNT (0+XfOrM692_COUNT)
#     define SETUP_XfOrM696(x) SETUP_XfOrM692(x)
      RET_VALUE_START (FUNCCALL(SETUP_XfOrM696(_), scheme_tail_apply (argv [0 ] , argc , args ) )) RET_VALUE_END ; 
    }
    else {
#     define XfOrM695_COUNT (0+XfOrM692_COUNT)
#     define SETUP_XfOrM695(x) SETUP_XfOrM692(x)
      v = FUNCCALL(SETUP_XfOrM695(_), scheme_do_eval (argv [0 ] , argc , args , 1 ) ); 
    }
    if (cc != scheme_cont_capture_count ) {
#     define XfOrM693_COUNT (0+XfOrM692_COUNT)
#     define SETUP_XfOrM693(x) SETUP_XfOrM692(x)
      if ((argc > 3 ) && (pos + 1 < size ) ) {
        Scheme_Object * * naya ; 
        BLOCK_SETUP((PUSH(naya, 0+XfOrM693_COUNT)));
#       define XfOrM694_COUNT (1+XfOrM693_COUNT)
#       define SETUP_XfOrM694(x) SETUP(XfOrM694_COUNT)
        naya = NULLED_OUT ; 
        args = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM694(_), GC_malloc (sizeof (Scheme_Object * ) * (argc ) ) )) ; 
        naya = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM694(_), GC_malloc (sizeof (Scheme_Object * ) * (argc ) ) )) ; 
        (memcpy (naya , working , argc * sizeof (Scheme_Object * ) ) ) ; 
        working = naya ; 
      }
    }
    if ((! (((v ) ) == (scheme_false ) ) ) )
      RET_VALUE_START (v ) RET_VALUE_END ; 
    pos ++ ; 
  }
  RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * call_with_values (int argc , Scheme_Object * argv [] ) {
  Scheme_Thread * p ; 
  Scheme_Object * v ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(argv, 1), PUSH(p, 2)));
# define XfOrM710_COUNT (3)
# define SETUP_XfOrM710(x) SETUP(XfOrM710_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  p = NULLED_OUT ; 
  v = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM710(_), scheme_check_proc_arity ("call-with-values" , 0 , 0 , argc , argv ) ); 
  if (! (! (((long ) (argv [1 ] ) ) & 0x1 ) && ((((argv [1 ] ) -> type ) >= scheme_prim_type ) && (((argv [1 ] ) -> type ) <= scheme_native_closure_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("call-with-values" , "procedure" , 1 , argc , argv ) ); 
  v = FUNCCALL(SETUP_XfOrM710(_), scheme_do_eval (argv [0 ] , 0 , ((void * ) 0 ) , - 1 ) ); 
  p = scheme_current_thread ; 
  if (((v ) == (((Scheme_Object * ) 0x6 ) ) ) ) {
    int n ; 
    Scheme_Object * * a ; 
    a = NULLED_OUT ; 
    if (((p -> ku . multiple . array ) == (p -> values_buffer ) ) )
      p -> values_buffer = ((void * ) 0 ) ; 
    n = p -> ku . multiple . count ; 
    a = p -> ku . multiple . array ; 
    p -> ku . apply . tail_num_rands = n ; 
    p -> ku . apply . tail_rands = a ; 
  }
  else {
    p -> ku . apply . tail_num_rands = 1 ; 
    p -> ku . apply . tail_rands = p -> tail_buffer ; 
    p -> ku . apply . tail_rands [0 ] = v ; 
  }
  p -> ku . apply . tail_rator = argv [1 ] ; 
  RET_VALUE_START (((Scheme_Object * ) 0x4 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * values_slow (int argc , Scheme_Object * argv [] ) {
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * * a ; 
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(a, 0), PUSH(argv, 1), PUSH(p, 2)));
# define XfOrM713_COUNT (3)
# define SETUP_XfOrM713(x) SETUP(XfOrM713_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a = NULLED_OUT ; 
  a = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM713(_), GC_malloc (sizeof (Scheme_Object * ) * (argc ) ) )) ; 
  p -> values_buffer = a ; 
  p -> values_buffer_size = argc ; 
  p -> ku . multiple . array = a ; 
  for (i = 0 ; i < argc ; i ++ ) {
    a [i ] = argv [i ] ; 
  }
  RET_VALUE_START (((Scheme_Object * ) 0x6 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_values (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Thread * p ; 
  int i ; 
  Scheme_Object * * a ; 
  if (argc == 1 )
    return argv [0 ] ; 
  p = scheme_current_thread ; 
  p -> ku . multiple . count = argc ; 
  if (p -> values_buffer && (p -> values_buffer_size >= argc ) ) {
    a = p -> values_buffer ; 
  }
  else {
    return values_slow (argc , argv ) ; 
  }
  p -> ku . multiple . array = a ; 
  for (i = 0 ; i < argc ; i ++ ) {
    a [i ] = argv [i ] ; 
  }
  return ((Scheme_Object * ) 0x6 ) ; 
}
static void reset_cjs (Scheme_Continuation_Jump_State * a ) {
  /* No conversion */
  a -> jumping_to_continuation = ((void * ) 0 ) ; 
  a -> val = ((void * ) 0 ) ; 
  a -> num_vals = 0 ; 
  a -> is_kill = 0 ; 
  a -> is_escape = 0 ; 
}
void scheme_clear_escape (void ) {
  Scheme_Thread * p = scheme_current_thread ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(p, 0)));
# define XfOrM722_COUNT (1)
# define SETUP_XfOrM722(x) SETUP(XfOrM722_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM722(_), reset_cjs (& p -> cjs ) ); 
  p -> suspend_break = 0 ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void copy_cjs (Scheme_Continuation_Jump_State * a , Scheme_Continuation_Jump_State * b ) {
  /* No conversion */
  a -> jumping_to_continuation = b -> jumping_to_continuation ; 
  a -> val = b -> val ; 
  a -> num_vals = b -> num_vals ; 
  a -> is_kill = b -> is_kill ; 
  a -> is_escape = b -> is_escape ; 
}
Scheme_Object * scheme_call_ec (int argc , Scheme_Object * argv [] ) {
  mz_jmp_buf newbuf ; 
  Scheme_Escaping_Cont * volatile cont ; 
  Scheme_Thread * p1 = scheme_current_thread ; 
  Scheme_Object * volatile v ; 
  Scheme_Object * a [1 ] ; 
  Scheme_Cont_Frame_Data cframe ; 
  Scheme_Prompt * barrier_prompt ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(10);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSHARRAY(a, 1, 1), PUSH(argv, 4), PUSH(cframe.cache, 5), PUSH(p1, 6), PUSH(barrier_prompt, 7), PUSH(cont, 8)));
# define XfOrM724_COUNT (9)
# define SETUP_XfOrM724(x) SETUP(XfOrM724_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  cont = NULLED_OUT ; 
  v = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  cframe.cache = NULLED_OUT ; 
  barrier_prompt = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM724(_), scheme_check_proc_arity ("call-with-escape-continuation" , 1 , 0 , argc , argv ) ); 
  cont = ((Scheme_Escaping_Cont * ) FUNCCALL(SETUP_XfOrM724(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Escaping_Cont ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  cont -> so . type = scheme_escaping_cont_type ; 
  FUNCCALL(SETUP_XfOrM724(_), ASSERT_SUSPEND_BREAK_ZERO () ); 
  cont -> saveerr = p1 -> error_buf ; 
  p1 -> error_buf = & newbuf ; 
  (cont -> envss . runstack_offset = scheme_current_runstack - scheme_current_runstack_start , cont -> envss . cont_mark_stack = scheme_current_cont_mark_stack , cont -> envss . cont_mark_pos = scheme_current_cont_mark_pos ) ; 
  barrier_prompt = FUNCCALL(SETUP_XfOrM724(_), scheme_get_barrier_prompt (((void * ) 0 ) , ((void * ) 0 ) ) ); 
  cont -> barrier_prompt = barrier_prompt ; 
  scheme_prompt_capture_count ++ ; 
  FUNCCALL(SETUP_XfOrM724(_), scheme_push_continuation_frame (& cframe ) ); 
  FUNCCALL_AGAIN(scheme_set_cont_mark ((Scheme_Object * ) cont , scheme_true ) ); 
  if (((newbuf ) . gcvs = (long ) __gc_var_stack__ , (newbuf ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((newbuf ) . jb ) , (_setjmp (((newbuf ) . jb ) -> jb ) ) ) ) ) {
    Scheme_Thread * p2 = scheme_current_thread ; 
    BLOCK_SETUP((PUSH(p2, 0+XfOrM724_COUNT)));
#   define XfOrM726_COUNT (1+XfOrM724_COUNT)
#   define SETUP_XfOrM726(x) SETUP(XfOrM726_COUNT)
    if (p2 -> cjs . jumping_to_continuation && ((p2 -> cjs . jumping_to_continuation ) == ((Scheme_Object * ) cont ) ) ) {
      int n = p2 -> cjs . num_vals ; 
#     define XfOrM728_COUNT (0+XfOrM726_COUNT)
#     define SETUP_XfOrM728(x) SETUP_XfOrM726(x)
      v = p2 -> cjs . val ; 
      FUNCCALL(SETUP_XfOrM728(_), reset_cjs (& p2 -> cjs ) ); 
      (scheme_current_runstack = scheme_current_runstack_start + cont -> envss . runstack_offset , scheme_current_cont_mark_stack = cont -> envss . cont_mark_stack , scheme_current_cont_mark_pos = cont -> envss . cont_mark_pos ) ; 
      p2 -> suspend_break = 0 ; 
      if (n != 1 )
        v = FUNCCALL(SETUP_XfOrM728(_), scheme_values (n , (Scheme_Object * * ) v ) ); 
    }
    else {
      (((long * ) (void * ) ((* cont -> saveerr ) . gcvs ) ) [1 ] = (* cont -> saveerr ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* cont -> saveerr ) . gcvs , scheme_jit_longjmp ((* cont -> saveerr ) . jb , 1 ) ) ; 
    }
  }
  else {
#   define XfOrM725_COUNT (0+XfOrM724_COUNT)
#   define SETUP_XfOrM725(x) SETUP_XfOrM724(x)
    a [0 ] = (Scheme_Object * ) cont ; 
    v = FUNCCALL(SETUP_XfOrM725(_), scheme_do_eval (argv [0 ] , 1 , a , - 1 ) ); 
  }
  p1 = scheme_current_thread ; 
  p1 -> error_buf = cont -> saveerr ; 
  FUNCCALL(SETUP_XfOrM724(_), scheme_pop_continuation_frame (& cframe ) ); 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_escape_continuation_ok (Scheme_Object * ec ) {
  /* No conversion */
  Scheme_Escaping_Cont * cont = (Scheme_Escaping_Cont * ) ec ; 
  if (scheme_extract_one_cc_mark (((void * ) 0 ) , (Scheme_Object * ) cont ) )
    return 1 ; 
  else return 0 ; 
}
static Scheme_Object * do_call_with_sema (const char * who , int enable_break , int argc , Scheme_Object * argv [] ) {
  mz_jmp_buf newbuf , * volatile savebuf ; 
  Scheme_Prompt * volatile prompt ; 
  int i , just_try ; 
  int volatile extra ; 
  Scheme_Object * volatile sema ; 
  Scheme_Object * v , * quick_args [4 ] , * * extra_args ; 
  Scheme_Cont_Frame_Data cframe ; 
  int old_pcc = scheme_prompt_capture_count ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(12);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(cframe.cache, 1), PUSH(sema, 2), PUSH(argv, 3), PUSH(prompt, 4), PUSHARRAY(quick_args, 4, 5), PUSH(savebuf, 8), PUSH(extra_args, 9), PUSH(who, 10)));
# define XfOrM730_COUNT (11)
# define SETUP_XfOrM730(x) SETUP(XfOrM730_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  savebuf = NULLED_OUT ; 
  prompt = NULLED_OUT ; 
  sema = NULLED_OUT ; 
  v = NULLED_OUT ; 
  NULL_OUT_ARRAY (quick_args ) ; 
  extra_args = NULLED_OUT ; 
  cframe.cache = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_sema_type ) ) ) {
#   define XfOrM742_COUNT (0+XfOrM730_COUNT)
#   define SETUP_XfOrM742(x) SETUP_XfOrM730(x)
    FUNCCALL(SETUP_XfOrM742(_), scheme_wrong_type (who , "semaphore" , 0 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (argc > 2 )
    extra = argc - 3 ; 
  else extra = 0 ; 
  if (! FUNCCALL(SETUP_XfOrM730(_), scheme_check_proc_arity (((void * ) 0 ) , extra , 1 , argc , argv ) )) {
#   define XfOrM741_COUNT (0+XfOrM730_COUNT)
#   define SETUP_XfOrM741(x) SETUP_XfOrM730(x)
    FUNCCALL(SETUP_XfOrM741(_), scheme_wrong_type (who , "procedure (arity matching extra args)" , 1 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if ((argc > 2 ) && (! (((argv [2 ] ) ) == (scheme_false ) ) ) ) {
#   define XfOrM739_COUNT (0+XfOrM730_COUNT)
#   define SETUP_XfOrM739(x) SETUP_XfOrM730(x)
    if (! FUNCCALL(SETUP_XfOrM739(_), scheme_check_proc_arity (((void * ) 0 ) , 0 , 2 , argc , argv ) )) {
#     define XfOrM740_COUNT (0+XfOrM739_COUNT)
#     define SETUP_XfOrM740(x) SETUP_XfOrM739(x)
      FUNCCALL(SETUP_XfOrM740(_), scheme_wrong_type (who , "procedure (arity 0) or #f" , 1 , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    just_try = 1 ; 
  }
  else just_try = 0 ; 
  sema = argv [0 ] ; 
  if (just_try && enable_break && scheme_current_thread -> external_break ) {
    Scheme_Cont_Frame_Data bcframe ; 
    BLOCK_SETUP((PUSH(bcframe.cache, 0+XfOrM730_COUNT)));
#   define XfOrM738_COUNT (1+XfOrM730_COUNT)
#   define SETUP_XfOrM738(x) SETUP(XfOrM738_COUNT)
    bcframe.cache = NULLED_OUT ; 
    FUNCCALL(SETUP_XfOrM738(_), scheme_push_break_enable (& bcframe , 1 , 1 ) ); 
    FUNCCALL_AGAIN(scheme_check_break_now () ); 
    FUNCCALL_AGAIN(scheme_pop_break_enable (& bcframe , 0 ) ); 
  }
  if (! FUNCCALL(SETUP_XfOrM730(_), scheme_wait_sema (sema , just_try ? 1 : (enable_break ? - 1 : 0 ) ) )) {
#   define XfOrM737_COUNT (0+XfOrM730_COUNT)
#   define SETUP_XfOrM737(x) SETUP_XfOrM730(x)
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM737(_), scheme_tail_apply (argv [2 ] , 0 , ((void * ) 0 ) ) )) RET_VALUE_END ; 
  }
  savebuf = scheme_current_thread -> error_buf ; 
  scheme_current_thread -> error_buf = & newbuf ; 
  if (available_cws_prompt ) {
    prompt = available_cws_prompt ; 
    available_cws_prompt = ((void * ) 0 ) ; 
  }
  else {
#   define XfOrM735_COUNT (0+XfOrM730_COUNT)
#   define SETUP_XfOrM735(x) SETUP_XfOrM730(x)
    prompt = ((Scheme_Prompt * ) FUNCCALL(SETUP_XfOrM735(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Prompt ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    prompt -> so . type = scheme_prompt_type ; 
  }
  FUNCCALL(SETUP_XfOrM730(_), scheme_push_continuation_frame (& cframe ) ); 
  FUNCCALL(SETUP_XfOrM730(_), scheme_set_cont_mark (barrier_prompt_key , (Scheme_Object * ) prompt ) ); 
  if (((newbuf ) . gcvs = (long ) __gc_var_stack__ , (newbuf ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((newbuf ) . jb ) , (_setjmp (((newbuf ) . jb ) -> jb ) ) ) ) ) {
    v = ((void * ) 0 ) ; 
  }
  else {
#   define XfOrM731_COUNT (0+XfOrM730_COUNT)
#   define SETUP_XfOrM731(x) SETUP_XfOrM730(x)
    if (extra > 4 )
      extra_args = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM731(_), GC_malloc (sizeof (Scheme_Object * ) * (extra ) ) )) ; 
    else extra_args = quick_args ; 
    for (i = 3 ; i < argc ; i ++ ) {
      extra_args [i - 3 ] = argv [i ] ; 
    }
    v = FUNCCALL(SETUP_XfOrM731(_), scheme_do_eval (argv [1 ] , extra , extra_args , - 1 ) ); 
  }
  FUNCCALL(SETUP_XfOrM730(_), scheme_pop_continuation_frame (& cframe ) ); 
  FUNCCALL(SETUP_XfOrM730(_), scheme_post_sema (sema ) ); 
  if (old_pcc != scheme_prompt_capture_count )
    available_cws_prompt = prompt ; 
  if (! v )
    (((long * ) (void * ) ((* savebuf ) . gcvs ) ) [1 ] = (* savebuf ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* savebuf ) . gcvs , scheme_jit_longjmp ((* savebuf ) . jb , 1 ) ) ; 
  scheme_current_thread -> error_buf = savebuf ; 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * call_with_sema (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_call_with_sema ("call-with-semaphore" , 0 , argc , argv ) ; 
}
static Scheme_Object * call_with_sema_enable_break (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_call_with_sema ("call-with-semaphore/enable-break" , 1 , argc , argv ) ; 
}
static Scheme_Saved_Stack * copy_out_runstack (Scheme_Thread * p , Scheme_Object * * runstack , Scheme_Object * * runstack_start , Scheme_Cont * share_from , Scheme_Prompt * effective_prompt ) {
  Scheme_Saved_Stack * saved , * isaved , * csaved , * share_saved , * share_csaved , * ss ; 
  Scheme_Object * * start ; 
  long size ; 
  int done ; 
  DECL_RET_SAVE (Scheme_Saved_Stack * ) PREPARE_VAR_STACK_ONCE(12);
  BLOCK_SETUP_TOP((PUSH(isaved, 0), PUSH(runstack_start, 1), PUSH(csaved, 2), PUSH(runstack, 3), PUSH(effective_prompt, 4), PUSH(share_saved, 5), PUSH(saved, 6), PUSH(start, 7), PUSH(ss, 8), PUSH(share_csaved, 9), PUSH(p, 10), PUSH(share_from, 11)));
# define XfOrM745_COUNT (12)
# define SETUP_XfOrM745(x) SETUP(XfOrM745_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  saved = NULLED_OUT ; 
  isaved = NULLED_OUT ; 
  csaved = NULLED_OUT ; 
  share_saved = NULLED_OUT ; 
  share_csaved = NULLED_OUT ; 
  ss = NULLED_OUT ; 
  start = NULLED_OUT ; 
  saved = ((Scheme_Saved_Stack * ) FUNCCALL(SETUP_XfOrM745(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Saved_Stack ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  saved -> type = scheme_rt_saved_stack ; 
  if (share_from && (share_from -> runstack_start == runstack_start ) ) {
    size = (share_from -> ss . runstack_offset - (runstack XFORM_OK_MINUS runstack_start ) ) ; 
    if (share_from -> ss . runstack_offset < p -> runstack_size )
      size ++ ; 
  }
  else if (effective_prompt && (effective_prompt -> runstack_boundary_start == runstack_start ) ) {
    size = effective_prompt -> runstack_boundary_offset - (runstack XFORM_OK_MINUS runstack_start ) ; 
  }
  else {
    size = p -> runstack_size - (runstack XFORM_OK_MINUS runstack_start ) ; 
  }
  saved -> runstack_size = size ; 
  start = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM745(_), GC_malloc (sizeof (Scheme_Object * ) * (size ) ) )) ; 
  saved -> runstack_start = start ; 
  (memcpy (saved -> runstack_start , runstack , size * sizeof (Scheme_Object * ) ) ) ; 
  if (! effective_prompt || (effective_prompt -> runstack_boundary_start != runstack_start ) ) {
#   define XfOrM746_COUNT (0+XfOrM745_COUNT)
#   define SETUP_XfOrM746(x) SETUP_XfOrM745(x)
    if (share_from ) {
      share_csaved = share_from -> runstack_saved ; 
      share_saved = share_from -> runstack_copied -> prev ; 
    }
    else {
      share_saved = ((void * ) 0 ) ; 
      share_csaved = ((void * ) 0 ) ; 
    }
    isaved = saved ; 
    for (csaved = p -> runstack_saved ; csaved ; csaved = csaved -> prev ) {
#     define XfOrM751_COUNT (0+XfOrM746_COUNT)
#     define SETUP_XfOrM751(x) SETUP_XfOrM746(x)
      if (share_csaved && (csaved -> runstack_start == share_csaved -> runstack_start ) ) {
        isaved -> prev = share_saved ; 
        break ; 
      }
      ss = ((Scheme_Saved_Stack * ) FUNCCALL(SETUP_XfOrM751(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Saved_Stack ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
      ss -> type = scheme_rt_saved_stack ; 
      isaved -> prev = ss ; 
      isaved = ss ; 
      if (effective_prompt && (effective_prompt -> runstack_boundary_start == csaved -> runstack_start ) ) {
        size = effective_prompt -> runstack_boundary_offset - csaved -> runstack_offset ; 
        done = 1 ; 
      }
      else {
        size = csaved -> runstack_size - csaved -> runstack_offset ; 
        done = 0 ; 
      }
      isaved -> runstack_size = size ; 
      start = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM751(_), GC_malloc (sizeof (Scheme_Object * ) * (size ) ) )) ; 
      isaved -> runstack_start = start ; 
      (memcpy (isaved -> runstack_start , csaved -> runstack_start XFORM_OK_PLUS csaved -> runstack_offset , size * sizeof (Scheme_Object * ) ) ) ; 
      isaved -> runstack_offset = csaved -> runstack_offset ; 
      if (done )
        break ; 
    }
  }
  RET_VALUE_START (saved ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Cont_Mark * copy_out_mark_stack (Scheme_Thread * p , long pos , Scheme_Cont * sub_cont , long * _offset , Scheme_Prompt * effective_prompt , int clear_caches ) {
  long cmcount , offset = 0 , sub_count = 0 ; 
  Scheme_Cont_Mark * cont_mark_stack_copied ; 
  DECL_RET_SAVE (Scheme_Cont_Mark * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(cont_mark_stack_copied, 0), PUSH(p, 1)));
# define XfOrM760_COUNT (2)
# define SETUP_XfOrM760(x) SETUP(XfOrM760_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  cont_mark_stack_copied = NULLED_OUT ; 
  cmcount = (long ) pos ; 
  offset = 0 ; 
  if (sub_cont ) {
    sub_count = sub_cont -> cont_mark_total - sub_cont -> cont_mark_nonshare ; 
    if (sub_count < 0 )
      sub_count = 0 ; 
  }
  else if (effective_prompt ) {
    sub_count = effective_prompt -> mark_boundary ; 
  }
  cmcount -= sub_count ; 
  offset += sub_count ; 
  if (_offset )
    * _offset = offset ; 
  if (cmcount ) {
#   define XfOrM761_COUNT (0+XfOrM760_COUNT)
#   define SETUP_XfOrM761(x) SETUP_XfOrM760(x)
    cont_mark_stack_copied = ((Scheme_Cont_Mark * ) FUNCCALL(SETUP_XfOrM761(_), GC_malloc (sizeof (Scheme_Cont_Mark ) * (cmcount ) ) )) ; 
    while (cmcount -- ) {
      int cms = cmcount + offset ; 
      Scheme_Cont_Mark * seg = p -> cont_mark_stack_segments [cms >> 8 ] ; 
      long pos = cms & ((1 << 8 ) - 1 ) ; 
      Scheme_Cont_Mark * cm = seg + pos ; 
#     define XfOrM763_COUNT (0+XfOrM761_COUNT)
#     define SETUP_XfOrM763(x) SETUP_XfOrM761(x)
      (memcpy (cont_mark_stack_copied + cmcount , cm , sizeof (Scheme_Cont_Mark ) ) ) ; 
      if (clear_caches )
        cont_mark_stack_copied [cmcount ] . cache = ((void * ) 0 ) ; 
    }
    RET_VALUE_START (cont_mark_stack_copied ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void copy_in_runstack (Scheme_Thread * p , Scheme_Saved_Stack * isaved , int set_runstack ) {
  /* No conversion */
  Scheme_Saved_Stack * csaved ; 
  long size ; 
  size = isaved -> runstack_size ; 
  if (set_runstack ) {
    scheme_current_runstack = scheme_current_runstack_start + (p -> runstack_size - size ) ; 
  }
  memcpy (scheme_current_runstack , isaved -> runstack_start , size * sizeof (Scheme_Object * ) ) ; 
  for (csaved = p -> runstack_saved ; csaved ; csaved = csaved -> prev ) {
    isaved = isaved -> prev ; 
    if (! isaved ) {
      break ; 
    }
    size = isaved -> runstack_size ; 
    csaved -> runstack_offset = isaved -> runstack_offset ; 
    memcpy (csaved -> runstack_start XFORM_OK_PLUS csaved -> runstack_offset , isaved -> runstack_start , size * sizeof (Scheme_Object * ) ) ; 
  }
}
static void copy_in_mark_stack (Scheme_Thread * p , Scheme_Cont_Mark * cont_mark_stack_copied , long cms , long base_cms , long copied_offset , Scheme_Object * * _sub_conts , int clear_caches ) {
  long cmcount , base_cmcount , cmoffset ; 
  Scheme_Cont_Mark * cm_src ; 
  Scheme_Cont * sub_cont = ((void * ) 0 ) ; 
  PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(sub_cont, 0), PUSH(cont_mark_stack_copied, 1), PUSH(_sub_conts, 2), PUSH(cm_src, 3), PUSH(p, 4)));
# define XfOrM772_COUNT (5)
# define SETUP_XfOrM772(x) SETUP(XfOrM772_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  cm_src = NULLED_OUT ; 
  cmcount = (long ) cms ; 
  base_cmcount = (long ) base_cms ; 
  if (cmcount ) {
    long needed = ((cmcount - 1 ) >> 8 ) + 1 ; 
#   define XfOrM795_COUNT (0+XfOrM772_COUNT)
#   define SETUP_XfOrM795(x) SETUP_XfOrM772(x)
    if (needed > p -> cont_mark_seg_count ) {
      Scheme_Cont_Mark * * segs , * * old_segs = p -> cont_mark_stack_segments ; 
      int newcount = needed , oldcount = p -> cont_mark_seg_count , npos ; 
      BLOCK_SETUP((PUSH(old_segs, 0+XfOrM795_COUNT), PUSH(segs, 1+XfOrM795_COUNT)));
#     define XfOrM796_COUNT (2+XfOrM795_COUNT)
#     define SETUP_XfOrM796(x) SETUP(XfOrM796_COUNT)
      segs = NULLED_OUT ; 
      segs = ((Scheme_Cont_Mark * * ) FUNCCALL(SETUP_XfOrM796(_), GC_malloc (sizeof (Scheme_Cont_Mark * ) * (needed ) ) )) ; 
      for (npos = needed ; npos -- ; ) {
#       define XfOrM799_COUNT (0+XfOrM796_COUNT)
#       define SETUP_XfOrM799(x) SETUP_XfOrM796(x)
        if (npos < oldcount )
          segs [npos ] = old_segs [npos ] ; 
        else segs [npos ] = ((void * ) 0 ) ; 
        if (! segs [npos ] ) {
          Scheme_Cont_Mark * cm ; 
          BLOCK_SETUP((PUSH(cm, 0+XfOrM799_COUNT)));
#         define XfOrM800_COUNT (1+XfOrM799_COUNT)
#         define SETUP_XfOrM800(x) SETUP(XfOrM800_COUNT)
          cm = NULLED_OUT ; 
          cm = FUNCCALL(SETUP_XfOrM800(_), GC_malloc_allow_interior (sizeof (Scheme_Cont_Mark ) * (1 << 8 ) ) ); 
          segs [npos ] = cm ; 
        }
      }
      p -> cont_mark_seg_count = newcount ; 
      p -> cont_mark_stack_segments = segs ; 
    }
  }
  if (_sub_conts ) {
    if (* _sub_conts ) {
      sub_cont = (Scheme_Cont * ) (((Scheme_Simple_Object * ) (* _sub_conts ) ) -> u . pair_val . car ) ; 
    }
  }
  while (base_cmcount < cmcount ) {
    Scheme_Cont_Mark * seg = p -> cont_mark_stack_segments [base_cmcount >> 8 ] ; 
    long pos = base_cmcount & ((1 << 8 ) - 1 ) ; 
    GC_CAN_IGNORE Scheme_Cont_Mark * cm = seg + pos ; 
#   define XfOrM783_COUNT (0+XfOrM772_COUNT)
#   define SETUP_XfOrM783(x) SETUP_XfOrM772(x)
    cm_src = cont_mark_stack_copied ; 
    cmoffset = base_cmcount - copied_offset ; 
    if (sub_cont ) {
      while (base_cmcount >= (sub_cont -> cont_mark_total - sub_cont -> cont_mark_nonshare ) ) {
        * _sub_conts = (((Scheme_Simple_Object * ) (* _sub_conts ) ) -> u . pair_val . cdr ) ; 
        if (* _sub_conts ) {
          sub_cont = (Scheme_Cont * ) (((Scheme_Simple_Object * ) (* _sub_conts ) ) -> u . pair_val . car ) ; 
        }
        else {
          sub_cont = ((void * ) 0 ) ; 
          break ; 
        }
      }
      if (sub_cont ) {
        cm_src = sub_cont -> cont_mark_stack_copied ; 
        cmoffset = base_cmcount - sub_cont -> cont_mark_offset ; 
      }
    }
    (memcpy (cm , cm_src + cmoffset , sizeof (Scheme_Cont_Mark ) ) ) ; 
    if (clear_caches ) {
      cm -> cache = ((void * ) 0 ) ; 
    }
    base_cmcount ++ ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static long find_shareable_marks () {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  long cmcount , delta = 0 ; 
  cmcount = (long ) scheme_current_cont_mark_stack ; 
  while (cmcount -- ) {
    Scheme_Cont_Mark * seg = p -> cont_mark_stack_segments [cmcount >> 8 ] ; 
    long pos = cmcount & ((1 << 8 ) - 1 ) ; 
    if (seg [pos ] . pos < scheme_current_cont_mark_pos )
      break ; 
    if (((seg [pos ] . key ) == (cont_key ) ) )
      delta = 1 ; 
    else delta = 0 ; 
  }
  return cmcount + 1 + delta ; 
}
static Scheme_Overflow * clone_overflows (Scheme_Overflow * overflow , void * limit , Scheme_Overflow * tail ) {
  Scheme_Overflow * naya , * first = ((void * ) 0 ) , * prev = ((void * ) 0 ) ; 
  DECL_RET_SAVE (Scheme_Overflow * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(first, 0), PUSH(overflow, 1), PUSH(prev, 2), PUSH(tail, 3), PUSH(naya, 4), PUSH(limit, 5)));
# define XfOrM804_COUNT (6)
# define SETUP_XfOrM804(x) SETUP(XfOrM804_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  naya = NULLED_OUT ; 
  for (; overflow && (! limit || (overflow -> id != limit ) ) ; overflow = overflow -> prev ) {
#   define XfOrM807_COUNT (0+XfOrM804_COUNT)
#   define SETUP_XfOrM807(x) SETUP_XfOrM804(x)
    naya = ((Scheme_Overflow * ) FUNCCALL(SETUP_XfOrM807(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Overflow ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    (memcpy (naya , overflow , sizeof (Scheme_Overflow ) ) ) ; 
    if (prev )
      prev -> prev = naya ; 
    else first = naya ; 
    prev = naya ; 
  }
  if (first ) {
    prev -> prev = tail ; 
    RET_VALUE_START (first ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (tail ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Dynamic_Wind * clone_dyn_wind (Scheme_Dynamic_Wind * dw , Scheme_Object * limit_prompt_tag , int limit_depth , Scheme_Dynamic_Wind * tail , int keep_tail , int composable ) {
  Scheme_Dynamic_Wind * naya , * first = ((void * ) 0 ) , * prev = ((void * ) 0 ) ; 
  int cnt = 0 ; 
  DECL_RET_SAVE (Scheme_Dynamic_Wind * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(first, 0), PUSH(prev, 1), PUSH(dw, 2), PUSH(tail, 3), PUSH(limit_prompt_tag, 4), PUSH(naya, 5)));
# define XfOrM808_COUNT (6)
# define SETUP_XfOrM808(x) SETUP(XfOrM808_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  naya = NULLED_OUT ; 
  for (; dw ; dw = dw -> prev ) {
#   define XfOrM814_COUNT (0+XfOrM808_COUNT)
#   define SETUP_XfOrM814(x) SETUP_XfOrM808(x)
    if (dw -> depth == limit_depth )
      break ; 
    if (composable && limit_prompt_tag && (dw -> prompt_tag == limit_prompt_tag ) )
      break ; 
    FUNCCALL(SETUP_XfOrM814(_), scheme_ensure_dw_id (dw ) ); 
    naya = ((Scheme_Dynamic_Wind * ) FUNCCALL(SETUP_XfOrM814(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Dynamic_Wind ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    (memcpy (naya , dw , sizeof (Scheme_Dynamic_Wind ) ) ) ; 
    if (prev )
      prev -> prev = naya ; 
    else first = naya ; 
    prev = naya ; 
    cnt ++ ; 
    if (limit_prompt_tag && (dw -> prompt_tag == limit_prompt_tag ) ) {
      dw = dw -> prev ; 
      break ; 
    }
  }
  if (keep_tail )
    tail = dw ; 
  if (first ) {
    prev -> prev = tail ; 
    if (tail )
      cnt += tail -> depth + 1 ; 
    for (dw = first ; dw != tail ; dw = dw -> prev ) {
      dw -> depth = -- cnt ; 
    }
    RET_VALUE_START (first ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (tail ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void clear_cm_copy_caches (Scheme_Cont_Mark * cp , int cnt ) {
  /* No conversion */
  int i ; 
  for (i = 0 ; i < cnt ; i ++ ) {
    cp [i ] . cache = ((void * ) 0 ) ; 
  }
}
/* this far 4226 */
/* this far 4208 */
/* this far 4208 */
/* this far 4226 */
/* this far 4208 */
/* this far 4208 */
static Scheme_Meta_Continuation * clone_meta_cont (Scheme_Meta_Continuation * mc , Scheme_Object * limit_tag , int limit_depth , Scheme_Meta_Continuation * prompt_cont , Scheme_Prompt * prompt , Scheme_Meta_Continuation * tail , int for_composable ) {
  Scheme_Meta_Continuation * naya , * first = ((void * ) 0 ) , * prev = ((void * ) 0 ) ; 
  int cnt = 0 , depth ; 
  DECL_RET_SAVE (Scheme_Meta_Continuation * ) PREPARE_VAR_STACK(9);
  BLOCK_SETUP_TOP((PUSH(first, 0), PUSH(limit_tag, 1), PUSH(tail, 2), PUSH(prompt_cont, 3), PUSH(prev, 4), PUSH(naya, 5), PUSH(mc, 6), PUSH(prompt, 7)));
# define XfOrM819_COUNT (8)
# define SETUP_XfOrM819(x) SETUP(XfOrM819_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  naya = NULLED_OUT ; 
  for (; mc ; mc = mc -> next ) {
#   define XfOrM832_COUNT (0+XfOrM819_COUNT)
#   define SETUP_XfOrM832(x) SETUP_XfOrM819(x)
    if (! limit_depth -- )
      break ; 
    if (! mc -> pseudo && ((mc -> prompt_tag ) == (limit_tag ) ) )
      break ; 
    if (for_composable && mc -> pseudo && mc -> empty_to_next && mc -> next && ((mc -> next -> prompt_tag ) == (limit_tag ) ) ) {
      break ; 
    }
    naya = ((Scheme_Meta_Continuation * ) FUNCCALL(SETUP_XfOrM832(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Meta_Continuation ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    cnt ++ ; 
    (memcpy (naya , mc , sizeof (Scheme_Meta_Continuation ) ) ) ; 
    if (((mc ) == (prompt_cont ) ) ) {
      long delta ; 
#     define XfOrM836_COUNT (0+XfOrM832_COUNT)
#     define SETUP_XfOrM836(x) SETUP_XfOrM832(x)
      delta = prompt -> mark_boundary - naya -> cont_mark_offset ; 
      if (delta ) {
#       define XfOrM837_COUNT (0+XfOrM836_COUNT)
#       define SETUP_XfOrM837(x) SETUP_XfOrM836(x)
        naya -> cont_mark_total -= delta ; 
        naya -> cont_mark_offset += delta ; 
        if (naya -> cont_mark_total ) {
          Scheme_Cont_Mark * cp ; 
          BLOCK_SETUP((PUSH(cp, 0+XfOrM837_COUNT)));
#         define XfOrM838_COUNT (1+XfOrM837_COUNT)
#         define SETUP_XfOrM838(x) SETUP(XfOrM838_COUNT)
          cp = NULLED_OUT ; 
          cp = ((Scheme_Cont_Mark * ) FUNCCALL(SETUP_XfOrM838(_), GC_malloc (sizeof (Scheme_Cont_Mark ) * (naya -> cont_mark_total ) ) )) ; 
          (memcpy (cp , mc -> cont_mark_stack_copied + delta , naya -> cont_mark_total * sizeof (Scheme_Cont_Mark ) ) ) ; 
          if (mc -> cm_caches ) {
#           define XfOrM839_COUNT (0+XfOrM838_COUNT)
#           define SETUP_XfOrM839(x) SETUP_XfOrM838(x)
            FUNCCALL(SETUP_XfOrM839(_), clear_cm_copy_caches (cp , naya -> cont_mark_total ) ); 
          }
          naya -> cont_mark_stack_copied = cp ; 
          naya -> cm_caches = 0 ; 
          naya -> cm_shared = 0 ; 
        }
        else naya -> cont_mark_stack_copied = ((void * ) 0 ) ; 
      }
      naya -> cont_mark_pos_bottom = prompt -> boundary_mark_pos ; 
    }
    else {
#     define XfOrM833_COUNT (0+XfOrM832_COUNT)
#     define SETUP_XfOrM833(x) SETUP_XfOrM832(x)
      if (! mc -> cm_caches ) {
        mc -> cm_shared = 1 ; 
        naya -> cm_shared = 1 ; 
      }
      else {
        Scheme_Cont_Mark * cp ; 
        BLOCK_SETUP((PUSH(cp, 0+XfOrM833_COUNT)));
#       define XfOrM834_COUNT (1+XfOrM833_COUNT)
#       define SETUP_XfOrM834(x) SETUP(XfOrM834_COUNT)
        cp = NULLED_OUT ; 
        cp = ((Scheme_Cont_Mark * ) FUNCCALL(SETUP_XfOrM834(_), GC_malloc (sizeof (Scheme_Cont_Mark ) * (naya -> cont_mark_total ) ) )) ; 
        (memcpy (cp , mc -> cont_mark_stack_copied , naya -> cont_mark_total * sizeof (Scheme_Cont_Mark ) ) ) ; 
        FUNCCALL(SETUP_XfOrM834(_), clear_cm_copy_caches (cp , naya -> cont_mark_total ) ); 
        naya -> cont_mark_stack_copied = cp ; 
        naya -> cm_caches = 0 ; 
        naya -> cm_shared = 0 ; 
      }
    }
    if (prev )
      prev -> next = naya ; 
    else first = naya ; 
    prev = naya ; 
  }
  if (first ) {
    prev -> next = tail ; 
  }
  else first = tail ; 
  if (tail )
    depth = tail -> depth + 1 ; 
  else depth = 0 ; 
  for (naya = first ; cnt -- ; naya = naya -> next ) {
    naya -> depth = depth + cnt ; 
  }
  RET_VALUE_START (first ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void prune_cont_marks (Scheme_Meta_Continuation * resume_mc , Scheme_Cont * cont , Scheme_Object * extra_marks ) {
  Scheme_Object * val ; 
  Scheme_Hash_Table * ht ; 
  long pos , num_overlap , num_coverlap , new_overlap , base , i ; 
  Scheme_Cont_Mark * cp ; 
  PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(val, 0), PUSH(extra_marks, 1), PUSH(cont, 2), PUSH(cp, 3), PUSH(resume_mc, 4), PUSH(ht, 5)));
# define XfOrM841_COUNT (6)
# define SETUP_XfOrM841(x) SETUP(XfOrM841_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  val = NULLED_OUT ; 
  ht = NULLED_OUT ; 
  cp = NULLED_OUT ; 
  for (pos = resume_mc -> cont_mark_total , num_overlap = 0 ; pos -- ; num_overlap ++ ) {
    if (resume_mc -> cont_mark_stack_copied [pos ] . pos != resume_mc -> cont_mark_pos )
      break ; 
  }
  if (! num_overlap && (! extra_marks || ! (((Scheme_Vector * ) (extra_marks ) ) -> size ) ) ) {
    RET_NOTHING ; 
  }
  for (pos = cont -> cont_mark_total , num_coverlap = 0 ; pos -- ; num_coverlap ++ ) {
    if (cont -> cont_mark_stack_copied [pos ] . pos != (cont -> cont_mark_pos_bottom + 2 ) )
      break ; 
  }
  if (! num_coverlap && (! extra_marks || ! (((Scheme_Vector * ) (extra_marks ) ) -> size ) ) ) {
    RET_NOTHING ; 
  }
  ht = FUNCCALL(SETUP_XfOrM841(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  for (pos = resume_mc -> cont_mark_total - 1 , i = 0 ; i < num_overlap ; i ++ , pos -- ) {
#   define XfOrM852_COUNT (0+XfOrM841_COUNT)
#   define SETUP_XfOrM852(x) SETUP_XfOrM841(x)
    val = resume_mc -> cont_mark_stack_copied [pos ] . val ; 
    if (! val )
      val = cont_key ; 
    FUNCCALL(SETUP_XfOrM852(_), scheme_hash_set (ht , resume_mc -> cont_mark_stack_copied [pos ] . key , val ) ); 
  }
  if (extra_marks ) {
#   define XfOrM848_COUNT (0+XfOrM841_COUNT)
#   define SETUP_XfOrM848(x) SETUP_XfOrM841(x)
    for (i = 0 ; i < (((Scheme_Vector * ) (extra_marks ) ) -> size ) ; i += 2 ) {
#     define XfOrM850_COUNT (0+XfOrM848_COUNT)
#     define SETUP_XfOrM850(x) SETUP_XfOrM848(x)
      val = (((Scheme_Vector * ) (extra_marks ) ) -> els ) [i + 1 ] ; 
      if (! val )
        val = cont_key ; 
      FUNCCALL(SETUP_XfOrM850(_), scheme_hash_set (ht , (((Scheme_Vector * ) (extra_marks ) ) -> els ) [i ] , val ) ); 
    }
  }
  for (pos = cont -> cont_mark_total - 1 , i = 0 ; i < num_coverlap ; i ++ , pos -- ) {
#   define XfOrM847_COUNT (0+XfOrM841_COUNT)
#   define SETUP_XfOrM847(x) SETUP_XfOrM841(x)
    FUNCCALL(SETUP_XfOrM847(_), scheme_hash_set (ht , cont -> cont_mark_stack_copied [pos ] . key , ((void * ) 0 ) ) ); 
  }
  new_overlap = ht -> count ; 
  base = resume_mc -> cont_mark_total - num_overlap ; 
  cp = ((Scheme_Cont_Mark * ) FUNCCALL(SETUP_XfOrM841(_), GC_malloc (sizeof (Scheme_Cont_Mark ) * (base + new_overlap ) ) )) ; 
  (memcpy (cp , resume_mc -> cont_mark_stack_copied , base * sizeof (Scheme_Cont_Mark ) ) ) ; 
  resume_mc -> cont_mark_stack_copied = cp ; 
  resume_mc -> cont_mark_total = base + new_overlap ; 
  resume_mc -> cm_shared = 0 ; 
  resume_mc -> cont_mark_stack += (new_overlap - num_overlap ) ; 
  for (i = 0 ; i < ht -> size ; i ++ ) {
    if (ht -> vals [i ] ) {
      cp [base ] . key = ht -> keys [i ] ; 
      val = ht -> vals [i ] ; 
      if (((val ) == (cont_key ) ) )
        val = ((void * ) 0 ) ; 
      cp [base ] . val = val ; 
      cp [base ] . pos = resume_mc -> cont_mark_pos ; 
      cp [base ] . cache = ((void * ) 0 ) ; 
      base ++ ; 
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Saved_Stack * clone_runstack_saved (Scheme_Saved_Stack * saved , Scheme_Object * * boundary_start , Scheme_Saved_Stack * last ) {
  Scheme_Saved_Stack * naya , * first = last , * prev = ((void * ) 0 ) ; 
  DECL_RET_SAVE (Scheme_Saved_Stack * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(last, 0), PUSH(boundary_start, 1), PUSH(prev, 2), PUSH(first, 3), PUSH(saved, 4), PUSH(naya, 5)));
# define XfOrM859_COUNT (6)
# define SETUP_XfOrM859(x) SETUP(XfOrM859_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  naya = NULLED_OUT ; 
  while (saved ) {
#   define XfOrM861_COUNT (0+XfOrM859_COUNT)
#   define SETUP_XfOrM861(x) SETUP_XfOrM859(x)
    naya = ((Scheme_Saved_Stack * ) FUNCCALL(SETUP_XfOrM861(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Saved_Stack ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    (memcpy (naya , saved , sizeof (Scheme_Saved_Stack ) ) ) ; 
    if (prev )
      prev -> prev = naya ; 
    else first = naya ; 
    prev = naya ; 
    if (saved -> runstack_start == boundary_start )
      break ; 
    saved = saved -> prev ; 
  }
  if (prev )
    prev -> prev = last ; 
  RET_VALUE_START (first ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static long exec_dyn_wind_pres (Scheme_Dynamic_Wind_List * dwl , int dwl_len , Scheme_Cont * cont , long copied_cms , int clear_cm_caches , Scheme_Object * * _sub_conts ) {
  Scheme_Thread * p = scheme_current_thread ; 
  int old_cac = scheme_continuation_application_count ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(_sub_conts, 0), PUSH(cont, 1), PUSH(p, 2), PUSH(dwl, 3)));
# define XfOrM862_COUNT (4)
# define SETUP_XfOrM862(x) SETUP(XfOrM862_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  for (; dwl ; dwl = dwl -> next ) {
#   define XfOrM868_COUNT (0+XfOrM862_COUNT)
#   define SETUP_XfOrM868(x) SETUP_XfOrM862(x)
    if (dwl -> dw -> pre ) {
#     define XfOrM869_COUNT (0+XfOrM868_COUNT)
#     define SETUP_XfOrM869(x) SETUP_XfOrM868(x)
      p -> dw = dwl -> dw -> prev ; 
      p -> next_meta = dwl -> meta_depth + dwl -> dw -> next_meta ; 
      if (dwl -> meta_depth > 0 ) {
#       define XfOrM872_COUNT (0+XfOrM869_COUNT)
#       define SETUP_XfOrM872(x) SETUP_XfOrM869(x)
        FUNCCALL(SETUP_XfOrM872(_), scheme_apply_dw_in_meta (dwl -> dw , 0 , dwl -> meta_depth , cont ) ); 
      }
      else {
        DW_PrePost_Proc pre = dwl -> dw -> pre ; 
#       define XfOrM870_COUNT (0+XfOrM869_COUNT)
#       define SETUP_XfOrM870(x) SETUP_XfOrM869(x)
        scheme_current_cont_mark_pos = dwl -> dw -> envss . cont_mark_pos ; 
        scheme_current_cont_mark_stack = dwl -> dw -> envss . cont_mark_stack ; 
        FUNCCALL(SETUP_XfOrM870(_), copy_in_mark_stack (p , cont -> cont_mark_stack_copied , scheme_current_cont_mark_stack , copied_cms , cont -> cont_mark_offset , _sub_conts , clear_cm_caches ) ); 
        copied_cms = scheme_current_cont_mark_stack ; 
        FUNCCALL(SETUP_XfOrM870(_), pre (dwl -> dw -> data ) ); 
        if (scheme_continuation_application_count != old_cac ) {
#         define XfOrM871_COUNT (0+XfOrM870_COUNT)
#         define SETUP_XfOrM871(x) SETUP_XfOrM870(x)
          old_cac = scheme_continuation_application_count ; 
          FUNCCALL(SETUP_XfOrM871(_), scheme_recheck_prompt_and_barrier (cont ) ); 
        }
      }
      p = scheme_current_thread ; 
    }
  }
  RET_VALUE_START (copied_cms ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * call_cc (int argc , Scheme_Object * argv [] ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM873_COUNT (1)
# define SETUP_XfOrM873(x) SETUP(XfOrM873_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM873(_), scheme_check_proc_arity ("call-with-current-continuation" , 1 , 0 , argc , argv ) ); 
  if (argc > 1 ) {
#   define XfOrM874_COUNT (0+XfOrM873_COUNT)
#   define SETUP_XfOrM874(x) SETUP_XfOrM873(x)
    if (! ((Scheme_Type ) (scheme_prompt_tag_type ) == (Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) ) ) {
#     define XfOrM875_COUNT (0+XfOrM874_COUNT)
#     define SETUP_XfOrM875(x) SETUP_XfOrM874(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("call-with-current-continuation" , "continuation-prompt-tag" , 1 , argc , argv ) ); 
    }
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_tail_apply (internal_call_cc_prim , argc , argv ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Cont * grab_continuation (Scheme_Thread * p , int for_prompt , int composable , Scheme_Object * prompt_tag , Scheme_Cont * sub_cont , Scheme_Prompt * prompt , Scheme_Meta_Continuation * prompt_cont , long prompt_pos , Scheme_Prompt * barrier_prompt , Scheme_Prompt * effective_barrier_prompt , Scheme_Meta_Continuation * barrier_cont , long barrier_pos ) {
  Scheme_Cont * cont ; 
  DECL_RET_SAVE (Scheme_Cont * ) PREPARE_VAR_STACK(10);
  BLOCK_SETUP_TOP((PUSH(prompt_tag, 0), PUSH(cont, 1), PUSH(sub_cont, 2), PUSH(effective_barrier_prompt, 3), PUSH(prompt_cont, 4), PUSH(barrier_prompt, 5), PUSH(prompt, 6), PUSH(p, 7)));
# define XfOrM876_COUNT (8)
# define SETUP_XfOrM876(x) SETUP(XfOrM876_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  cont = NULLED_OUT ; 
  cont = ((Scheme_Cont * ) FUNCCALL(SETUP_XfOrM876(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Cont ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  cont -> so . type = scheme_cont_type ; 
  if (! for_prompt && ! composable ) {
#   define XfOrM896_COUNT (0+XfOrM876_COUNT)
#   define SETUP_XfOrM896(x) SETUP_XfOrM876(x)
    FUNCCALL(SETUP_XfOrM896(_), scheme_set_cont_mark (cont_key , (Scheme_Object * ) cont ) ); 
  }
  if (composable )
    cont -> composable = 1 ; 
  FUNCCALL(SETUP_XfOrM876(_), scheme_init_jmpup_buf (& cont -> buf ) ); 
  cont -> prompt_tag = prompt_tag ; 
  if (for_prompt )
    cont -> dw = ((void * ) 0 ) ; 
  else if (prompt ) {
    Scheme_Dynamic_Wind * dw ; 
    BLOCK_SETUP((PUSH(dw, 0+XfOrM876_COUNT)));
#   define XfOrM894_COUNT (1+XfOrM876_COUNT)
#   define SETUP_XfOrM894(x) SETUP(XfOrM894_COUNT)
    dw = NULLED_OUT ; 
    if (p -> dw ) {
#     define XfOrM895_COUNT (0+XfOrM894_COUNT)
#     define SETUP_XfOrM895(x) SETUP_XfOrM894(x)
      dw = FUNCCALL(SETUP_XfOrM895(_), clone_dyn_wind (p -> dw , prompt_tag , - 1 , ((void * ) 0 ) , 0 , composable ) ); 
      cont -> dw = dw ; 
      cont -> next_meta = p -> next_meta ; 
    }
    else cont -> dw = ((void * ) 0 ) ; 
  }
  else {
    cont -> dw = p -> dw ; 
    cont -> next_meta = p -> next_meta ; 
  }
  if (! for_prompt )
    FUNCCALL(SETUP_XfOrM876(_), ASSERT_SUSPEND_BREAK_ZERO () ); 
  FUNCCALL(SETUP_XfOrM876(_), copy_cjs (& cont -> cjs , & p -> cjs ) ); 
  cont -> save_overflow = p -> overflow ; 
  (cont -> ss . runstack_offset = scheme_current_runstack - scheme_current_runstack_start , cont -> ss . cont_mark_stack = scheme_current_cont_mark_stack , cont -> ss . cont_mark_pos = scheme_current_cont_mark_pos ) ; 
  cont -> runstack_size = p -> runstack_size ; 
  cont -> runstack_start = scheme_current_runstack_start ; 
  cont -> runstack_saved = p -> runstack_saved ; 
  cont -> meta_tail_pos = (prompt ? prompt -> boundary_mark_pos + 2 : 0 ) ; 
  cont -> init_config = p -> init_config ; 
  cont -> init_break_cell = p -> init_break_cell ; 
  if (for_prompt ) {
    cont -> meta_continuation = ((void * ) 0 ) ; 
  }
  else if (prompt ) {
    Scheme_Meta_Continuation * mc ; 
    Scheme_Object * id ; 
    BLOCK_SETUP((PUSH(id, 0+XfOrM876_COUNT), PUSH(mc, 1+XfOrM876_COUNT)));
#   define XfOrM889_COUNT (2+XfOrM876_COUNT)
#   define SETUP_XfOrM889(x) SETUP(XfOrM889_COUNT)
    mc = NULLED_OUT ; 
    id = NULLED_OUT ; 
    mc = FUNCCALL(SETUP_XfOrM889(_), clone_meta_cont (p -> meta_continuation , prompt_tag , - 1 , prompt_cont , prompt , ((void * ) 0 ) , composable ) ); 
    cont -> meta_continuation = mc ; 
    if (! prompt_cont ) {
#     define XfOrM890_COUNT (0+XfOrM889_COUNT)
#     define SETUP_XfOrM890(x) SETUP_XfOrM889(x)
      if (! prompt -> id ) {
#       define XfOrM891_COUNT (0+XfOrM890_COUNT)
#       define SETUP_XfOrM891(x) SETUP_XfOrM890(x)
        id = FUNCCALL(SETUP_XfOrM891(_), scheme_make_pair (scheme_false , scheme_false ) ); 
        prompt -> id = id ; 
      }
      cont -> prompt_id = prompt -> id ; 
    }
    cont -> has_prompt_dw = 1 ; 
  }
  else cont -> meta_continuation = p -> meta_continuation ; 
  if (effective_barrier_prompt ) {
    cont -> barrier_prompt = effective_barrier_prompt ; 
    scheme_prompt_capture_count ++ ; 
  }
  if (p -> meta_prompt && prompt_cont )
    prompt = p -> meta_prompt ; 
  {
    Scheme_Overflow * overflow ; 
    BLOCK_SETUP((PUSH(overflow, 0+XfOrM876_COUNT)));
#   define XfOrM884_COUNT (1+XfOrM876_COUNT)
#   define SETUP_XfOrM884(x) SETUP(XfOrM884_COUNT)
    overflow = NULLED_OUT ; 
    for (overflow = p -> overflow ; overflow ; overflow = overflow -> prev ) {
      overflow -> jmp -> captured = 1 ; 
    }
    if (prompt ) {
#     define XfOrM885_COUNT (0+XfOrM884_COUNT)
#     define SETUP_XfOrM885(x) SETUP_XfOrM884(x)
      overflow = FUNCCALL(SETUP_XfOrM885(_), clone_overflows (p -> overflow , prompt -> boundary_overflow_id , ((void * ) 0 ) ) ); 
      cont -> save_overflow = overflow ; 
    }
  }
  scheme_cont_capture_count ++ ; 
  if (! effective_barrier_prompt || ! effective_barrier_prompt -> is_barrier ) {
#   define XfOrM881_COUNT (0+XfOrM876_COUNT)
#   define SETUP_XfOrM881(x) SETUP_XfOrM876(x)
    if (! p -> runstack_owner ) {
      Scheme_Thread * * owner ; 
      BLOCK_SETUP((PUSH(owner, 0+XfOrM881_COUNT)));
#     define XfOrM883_COUNT (1+XfOrM881_COUNT)
#     define SETUP_XfOrM883(x) SETUP(XfOrM883_COUNT)
      owner = NULLED_OUT ; 
      owner = ((Scheme_Thread * * ) FUNCCALL(SETUP_XfOrM883(_), GC_malloc (sizeof (Scheme_Thread * ) * (1 ) ) )) ; 
      p -> runstack_owner = owner ; 
      * owner = p ; 
    }
    if (p -> cont_mark_stack && ! p -> cont_mark_stack_owner ) {
      Scheme_Thread * * owner ; 
      BLOCK_SETUP((PUSH(owner, 0+XfOrM881_COUNT)));
#     define XfOrM882_COUNT (1+XfOrM881_COUNT)
#     define SETUP_XfOrM882(x) SETUP(XfOrM882_COUNT)
      owner = NULLED_OUT ; 
      owner = ((Scheme_Thread * * ) FUNCCALL(SETUP_XfOrM882(_), GC_malloc (sizeof (Scheme_Thread * ) * (1 ) ) )) ; 
      p -> cont_mark_stack_owner = owner ; 
      * owner = p ; 
    }
  }
  {
    Scheme_Object * tr ; 
    BLOCK_SETUP((PUSH(tr, 0+XfOrM876_COUNT)));
#   define XfOrM880_COUNT (1+XfOrM876_COUNT)
#   define SETUP_XfOrM880(x) SETUP(XfOrM880_COUNT)
    tr = NULLED_OUT ; 
    tr = FUNCCALL(SETUP_XfOrM880(_), scheme_native_stack_trace () ); 
    cont -> native_trace = tr ; 
  }
  {
    Scheme_Saved_Stack * saved ; 
    BLOCK_SETUP((PUSH(saved, 0+XfOrM876_COUNT)));
#   define XfOrM878_COUNT (1+XfOrM876_COUNT)
#   define SETUP_XfOrM878(x) SETUP(XfOrM878_COUNT)
    saved = NULLED_OUT ; 
    saved = FUNCCALL(SETUP_XfOrM878(_), copy_out_runstack (p , scheme_current_runstack , scheme_current_runstack_start , sub_cont , (for_prompt ? p -> meta_prompt : prompt ) ) ); 
    cont -> runstack_copied = saved ; 
    if (! for_prompt && prompt ) {
#     define XfOrM879_COUNT (0+XfOrM878_COUNT)
#     define SETUP_XfOrM879(x) SETUP_XfOrM878(x)
      if (((prompt -> runstack_boundary_start ) == (scheme_current_runstack_start ) ) )
        saved = ((void * ) 0 ) ; 
      else saved = FUNCCALL(SETUP_XfOrM879(_), clone_runstack_saved (cont -> runstack_saved , prompt -> runstack_boundary_start , ((void * ) 0 ) ) ); 
      cont -> runstack_saved = saved ; 
    }
  }
  {
    Scheme_Prompt * effective_prompt ; 
    Scheme_Cont_Mark * msaved ; 
    long offset ; 
    BLOCK_SETUP((PUSH(effective_prompt, 0+XfOrM876_COUNT), PUSH(msaved, 1+XfOrM876_COUNT)));
#   define XfOrM877_COUNT (2+XfOrM876_COUNT)
#   define SETUP_XfOrM877(x) SETUP(XfOrM877_COUNT)
    effective_prompt = NULLED_OUT ; 
    msaved = NULLED_OUT ; 
    effective_prompt = (for_prompt ? p -> meta_prompt : prompt ) ; 
    msaved = FUNCCALL(SETUP_XfOrM877(_), copy_out_mark_stack (p , cont -> ss . cont_mark_stack , sub_cont , & offset , effective_prompt , ! ! prompt ) ); 
    cont -> cont_mark_stack_copied = msaved ; 
    cont -> cont_mark_offset = offset ; 
    if (effective_prompt )
      cont -> cont_mark_total = cont -> ss . cont_mark_stack - effective_prompt -> mark_boundary ; 
    else cont -> cont_mark_total = cont -> ss . cont_mark_stack ; 
    offset = FUNCCALL(SETUP_XfOrM877(_), find_shareable_marks () ); 
    cont -> cont_mark_nonshare = cont -> ss . cont_mark_stack - offset ; 
    cont -> cont_mark_pos_bottom = (effective_prompt ? effective_prompt -> boundary_mark_pos : 1 ) ; 
  }
  cont -> runstack_owner = p -> runstack_owner ; 
  cont -> cont_mark_stack_owner = p -> cont_mark_stack_owner ; 
  cont -> stack_start = p -> stack_start ; 
  cont -> savebuf = p -> error_buf ; 
  if (prompt )
    cont -> prompt_buf = prompt -> prompt_buf ; 
  RET_VALUE_START (cont ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 4745 */
/* this far 4746 */
/* this far 4745 */
/* this far 4746 */
static void restore_continuation (Scheme_Cont * cont , Scheme_Thread * p , int for_prompt , Scheme_Object * result , Scheme_Overflow * resume , int empty_to_next_mc , Scheme_Object * prompt_tag , Scheme_Cont * sub_cont , Scheme_Dynamic_Wind * common_dw , int common_next_meta , Scheme_Prompt * shortcut_prompt , int clear_cm_caches , int do_reset_cjs , Scheme_Cont * cm_cont , Scheme_Object * extra_marks ) {
  long copied_cms = 0 ; 
  Scheme_Object * * mv , * sub_conts = ((void * ) 0 ) ; 
  int mc ; 
  PREPARE_VAR_STACK(16);
  BLOCK_SETUP_TOP((PUSH(sub_conts, 0), PUSH(prompt_tag, 1), PUSH(common_dw, 2), PUSH(shortcut_prompt, 3), PUSH(cm_cont, 4), PUSH(sub_cont, 5), PUSH(resume, 6), PUSH(p, 7), PUSH(cont, 8), PUSH(mv, 9), PUSH(extra_marks, 10), PUSH(result, 11)));
# define XfOrM897_COUNT (12)
# define SETUP_XfOrM897(x) SETUP(XfOrM897_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  mv = NULLED_OUT ; 
  if (((result ) == (((Scheme_Object * ) 0x6 ) ) ) ) {
    mv = p -> ku . multiple . array ; 
    mc = p -> ku . multiple . count ; 
    if (((mv ) == (p -> values_buffer ) ) )
      p -> values_buffer = ((void * ) 0 ) ; 
  }
  else {
    mv = ((void * ) 0 ) ; 
    mc = 0 ; 
  }
  p -> error_buf = cont -> savebuf ; 
  p -> init_config = cont -> init_config ; 
  p -> init_break_cell = cont -> init_break_cell ; 
  if (do_reset_cjs )
    FUNCCALL(SETUP_XfOrM897(_), copy_cjs (& p -> cjs , & cont -> cjs ) ); 
  if (shortcut_prompt ) {
    Scheme_Overflow * overflow ; 
    BLOCK_SETUP((PUSH(overflow, 0+XfOrM897_COUNT)));
#   define XfOrM956_COUNT (1+XfOrM897_COUNT)
#   define SETUP_XfOrM956(x) SETUP(XfOrM956_COUNT)
    overflow = NULLED_OUT ; 
    overflow = FUNCCALL(SETUP_XfOrM956(_), clone_overflows (cont -> save_overflow , ((void * ) 0 ) , p -> overflow ) ); 
    p -> overflow = overflow ; 
  }
  else {
    p -> overflow = cont -> save_overflow ; 
  }
  if (! for_prompt ) {
    Scheme_Meta_Continuation * mc , * resume_mc ; 
    BLOCK_SETUP((PUSH(resume_mc, 0+XfOrM897_COUNT), PUSH(mc, 1+XfOrM897_COUNT)));
#   define XfOrM948_COUNT (2+XfOrM897_COUNT)
#   define SETUP_XfOrM948(x) SETUP(XfOrM948_COUNT)
    mc = NULLED_OUT ; 
    resume_mc = NULLED_OUT ; 
    if (resume ) {
#     define XfOrM952_COUNT (0+XfOrM948_COUNT)
#     define SETUP_XfOrM952(x) SETUP_XfOrM948(x)
      resume_mc = ((Scheme_Meta_Continuation * ) FUNCCALL(SETUP_XfOrM952(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Meta_Continuation ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
      resume_mc -> type = scheme_rt_meta_cont ; 
      resume_mc -> overflow = resume ; 
      resume_mc -> prompt_tag = prompt_tag ; 
      resume_mc -> pseudo = cont -> composable ; 
      resume_mc -> empty_to_next = empty_to_next_mc ; 
      resume_mc -> meta_tail_pos = cont -> meta_tail_pos ; 
      if (! cm_cont ) {
      }
      else {
        resume_mc -> cont_mark_stack = cm_cont -> ss . cont_mark_stack ; 
        resume_mc -> cont_mark_pos = cm_cont -> ss . cont_mark_pos ; 
        resume_mc -> cont_mark_total = cm_cont -> cont_mark_total ; 
        resume_mc -> cont_mark_offset = cm_cont -> cont_mark_offset ; 
        resume_mc -> cont_mark_pos_bottom = cm_cont -> cont_mark_pos_bottom ; 
        resume_mc -> cont_mark_stack_copied = cm_cont -> cont_mark_stack_copied ; 
        resume_mc -> cm_caches = 1 ; 
        resume_mc -> next = p -> meta_continuation ; 
        if (p -> meta_continuation )
          resume_mc -> depth = p -> meta_continuation -> depth + 1 ; 
      }
    }
    else resume_mc = ((void * ) 0 ) ; 
    if (resume_mc ) {
#     define XfOrM950_COUNT (0+XfOrM948_COUNT)
#     define SETUP_XfOrM950(x) SETUP_XfOrM948(x)
      if (cont -> composable ) {
#       define XfOrM951_COUNT (0+XfOrM950_COUNT)
#       define SETUP_XfOrM951(x) SETUP_XfOrM950(x)
        FUNCCALL(SETUP_XfOrM951(_), prune_cont_marks (resume_mc , cont , extra_marks ) ); 
      }
      mc = FUNCCALL(SETUP_XfOrM950(_), clone_meta_cont (cont -> meta_continuation , ((void * ) 0 ) , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , resume_mc , 0 ) ); 
    }
    else if (shortcut_prompt ) {
#     define XfOrM949_COUNT (0+XfOrM948_COUNT)
#     define SETUP_XfOrM949(x) SETUP_XfOrM948(x)
      mc = FUNCCALL(SETUP_XfOrM949(_), clone_meta_cont (cont -> meta_continuation , ((void * ) 0 ) , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , p -> meta_continuation , 0 ) ); 
    }
    else mc = cont -> meta_continuation ; 
    p -> meta_continuation = mc ; 
  }
  if (shortcut_prompt ) {
    Scheme_Saved_Stack * rs ; 
    BLOCK_SETUP((PUSH(rs, 0+XfOrM897_COUNT)));
#   define XfOrM944_COUNT (1+XfOrM897_COUNT)
#   define SETUP_XfOrM944(x) SETUP(XfOrM944_COUNT)
    rs = NULLED_OUT ; 
    if (shortcut_prompt -> runstack_boundary_start == scheme_current_runstack_start )
      rs = p -> runstack_saved ; 
    else {
      rs = p -> runstack_saved ; 
      while (rs && (rs -> runstack_start != shortcut_prompt -> runstack_boundary_start ) ) {
        rs = rs -> prev ; 
      }
      if (rs )
        rs = rs -> prev ; 
    }
    if (rs )
      rs = FUNCCALL(SETUP_XfOrM944(_), clone_runstack_saved (cont -> runstack_saved , ((void * ) 0 ) , rs ) ); 
    else rs = cont -> runstack_saved ; 
    p -> runstack_saved = rs ; 
  }
  else p -> runstack_saved = cont -> runstack_saved ; 
  scheme_current_runstack_start = cont -> runstack_start ; 
  p -> runstack_size = cont -> runstack_size ; 
  (scheme_current_runstack = scheme_current_runstack_start + cont -> ss . runstack_offset , scheme_current_cont_mark_stack = cont -> ss . cont_mark_stack , scheme_current_cont_mark_pos = cont -> ss . cont_mark_pos ) ; 
  if (p -> runstack_owner && (* p -> runstack_owner == p ) ) {
    * p -> runstack_owner = ((void * ) 0 ) ; 
  }
  if (resume )
    p -> meta_prompt = ((void * ) 0 ) ; 
  p -> runstack_owner = cont -> runstack_owner ; 
  if (p -> runstack_owner && (* p -> runstack_owner != p ) ) {
    Scheme_Thread * op ; 
    BLOCK_SETUP((PUSH(op, 0+XfOrM897_COUNT)));
#   define XfOrM941_COUNT (1+XfOrM897_COUNT)
#   define SETUP_XfOrM941(x) SETUP(XfOrM941_COUNT)
    op = NULLED_OUT ; 
    op = * p -> runstack_owner ; 
    if (op ) {
      Scheme_Saved_Stack * saved ; 
      BLOCK_SETUP((PUSH(saved, 0+XfOrM941_COUNT)));
#     define XfOrM942_COUNT (1+XfOrM941_COUNT)
#     define SETUP_XfOrM942(x) SETUP(XfOrM942_COUNT)
      saved = NULLED_OUT ; 
      saved = FUNCCALL(SETUP_XfOrM942(_), copy_out_runstack (op , op -> runstack , op -> runstack_start , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
      op -> runstack_swapped = saved ; 
    }
    * p -> runstack_owner = p ; 
  }
  FUNCCALL(SETUP_XfOrM897(_), copy_in_runstack (p , cont -> runstack_copied , 0 ) ); 
  {
    long done = cont -> runstack_copied -> runstack_size , size ; 
#   define XfOrM934_COUNT (0+XfOrM897_COUNT)
#   define SETUP_XfOrM934(x) SETUP_XfOrM897(x)
    sub_cont = cont ; 
    while (sub_cont ) {
#     define XfOrM938_COUNT (0+XfOrM934_COUNT)
#     define SETUP_XfOrM938(x) SETUP_XfOrM934(x)
      if (sub_cont -> buf . cont && (sub_cont -> runstack_start == sub_cont -> buf . cont -> runstack_start ) ) {
#       define XfOrM939_COUNT (0+XfOrM938_COUNT)
#       define SETUP_XfOrM939(x) SETUP_XfOrM938(x)
        sub_cont = sub_cont -> buf . cont ; 
        size = sub_cont -> runstack_copied -> runstack_size ; 
        if (size ) {
#         define XfOrM940_COUNT (0+XfOrM939_COUNT)
#         define SETUP_XfOrM940(x) SETUP_XfOrM939(x)
          (memcpy (scheme_current_runstack XFORM_OK_PLUS done , sub_cont -> runstack_copied -> runstack_start + 1 , (size - 1 ) * sizeof (Scheme_Object * ) ) ) ; 
          done += (size - 1 ) ; 
        }
      }
      else break ; 
    }
  }
  if (p -> cont_mark_stack_owner && (* p -> cont_mark_stack_owner == p ) )
    * p -> cont_mark_stack_owner = ((void * ) 0 ) ; 
  p -> cont_mark_stack_owner = cont -> cont_mark_stack_owner ; 
  if (p -> cont_mark_stack_owner && (* p -> cont_mark_stack_owner != p ) ) {
    Scheme_Thread * op ; 
    BLOCK_SETUP((PUSH(op, 0+XfOrM897_COUNT)));
#   define XfOrM932_COUNT (1+XfOrM897_COUNT)
#   define SETUP_XfOrM932(x) SETUP(XfOrM932_COUNT)
    op = NULLED_OUT ; 
    op = * p -> cont_mark_stack_owner ; 
    if (op ) {
      Scheme_Cont_Mark * msaved ; 
      BLOCK_SETUP((PUSH(msaved, 0+XfOrM932_COUNT)));
#     define XfOrM933_COUNT (1+XfOrM932_COUNT)
#     define SETUP_XfOrM933(x) SETUP(XfOrM933_COUNT)
      msaved = NULLED_OUT ; 
      msaved = FUNCCALL(SETUP_XfOrM933(_), copy_out_mark_stack (op , op -> cont_mark_stack , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ); 
      op -> cont_mark_stack_swapped = msaved ; 
    }
    * p -> cont_mark_stack_owner = p ; 
    scheme_current_cont_mark_stack = 0 ; 
  }
  if (resume ) {
    Scheme_Prompt * meta_prompt ; 
    BLOCK_SETUP((PUSH(meta_prompt, 0+XfOrM897_COUNT)));
#   define XfOrM919_COUNT (1+XfOrM897_COUNT)
#   define SETUP_XfOrM919(x) SETUP(XfOrM919_COUNT)
    meta_prompt = NULLED_OUT ; 
    meta_prompt = ((Scheme_Prompt * ) FUNCCALL(SETUP_XfOrM919(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Prompt ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    meta_prompt -> so . type = scheme_prompt_type ; 
    meta_prompt -> stack_boundary = cont -> prompt_stack_start ; 
    meta_prompt -> boundary_overflow_id = ((void * ) 0 ) ; 
    {
      Scheme_Cont * tc ; 
      tc = NULLED_OUT ; 
      for (tc = cont ; tc -> buf . cont ; tc = tc -> buf . cont ) {
      }
      meta_prompt -> mark_boundary = tc -> cont_mark_offset ; 
    }
    meta_prompt -> prompt_buf = cont -> prompt_buf ; 
    {
      Scheme_Cont * rs_cont = cont ; 
      Scheme_Saved_Stack * saved , * actual ; 
      int delta = 0 ; 
      saved = NULLED_OUT ; 
      actual = NULLED_OUT ; 
      while (rs_cont -> buf . cont ) {
        delta += rs_cont -> runstack_copied -> runstack_size ; 
        rs_cont = rs_cont -> buf . cont ; 
        if (rs_cont -> runstack_copied -> runstack_size ) {
          delta -= 1 ; 
        }
      }
      actual = ((void * ) 0 ) ; 
      for (saved = rs_cont -> runstack_copied ; saved -> prev ; saved = saved -> prev ) {
        if (! actual )
          actual = p -> runstack_saved ; 
        else actual = actual -> prev ; 
      }
      if (actual ) {
        meta_prompt -> runstack_boundary_start = actual -> runstack_start ; 
        meta_prompt -> runstack_boundary_offset = actual -> runstack_offset + saved -> runstack_size ; 
      }
      else {
        meta_prompt -> runstack_boundary_start = scheme_current_runstack_start ; 
        meta_prompt -> runstack_boundary_offset = (scheme_current_runstack - scheme_current_runstack_start ) + saved -> runstack_size + delta ; 
      }
    }
    p -> meta_prompt = meta_prompt ; 
  }
  copied_cms = cont -> cont_mark_offset ; 
  for (sub_cont = cont -> buf . cont ; sub_cont ; sub_cont = sub_cont -> buf . cont ) {
#   define XfOrM918_COUNT (0+XfOrM897_COUNT)
#   define SETUP_XfOrM918(x) SETUP_XfOrM897(x)
    copied_cms = sub_cont -> cont_mark_offset ; 
    sub_conts = FUNCCALL(SETUP_XfOrM918(_), scheme_make_raw_pair ((Scheme_Object * ) sub_cont , sub_conts ) ); 
  }
  if (! shortcut_prompt ) {
    Scheme_Cont * tc ; 
    tc = NULLED_OUT ; 
    for (tc = cont ; tc -> buf . cont ; tc = tc -> buf . cont ) {
    }
    p -> cont_mark_stack_bottom = tc -> cont_mark_offset ; 
    p -> cont_mark_pos_bottom = tc -> cont_mark_pos_bottom ; 
  }
  if (for_prompt ) {
  }
  else {
    Scheme_Dynamic_Wind * dw , * all_dw ; 
    Scheme_Dynamic_Wind_List * dwl = ((void * ) 0 ) ; 
    int common_depth , dwl_len = 0 ; 
    BLOCK_SETUP((PUSH(dw, 0+XfOrM897_COUNT), PUSH(all_dw, 1+XfOrM897_COUNT), PUSH(dwl, 2+XfOrM897_COUNT)));
#   define XfOrM899_COUNT (3+XfOrM897_COUNT)
#   define SETUP_XfOrM899(x) SETUP(XfOrM899_COUNT)
    dw = NULLED_OUT ; 
    all_dw = NULLED_OUT ; 
    if (resume ) {
#     define XfOrM907_COUNT (0+XfOrM899_COUNT)
#     define SETUP_XfOrM907(x) SETUP_XfOrM899(x)
      if (cont -> composable ) {
        p -> next_meta ++ ; 
      }
      else {
#       define XfOrM908_COUNT (0+XfOrM907_COUNT)
#       define SETUP_XfOrM908(x) SETUP_XfOrM907(x)
        p -> dw = common_dw ; 
        p -> next_meta = common_next_meta ; 
        if (p -> dw ) {
#         define XfOrM909_COUNT (0+XfOrM908_COUNT)
#         define SETUP_XfOrM909(x) SETUP_XfOrM908(x)
          all_dw = FUNCCALL(SETUP_XfOrM909(_), clone_dyn_wind (p -> dw , cont -> prompt_tag , - 1 , ((void * ) 0 ) , 1 , 0 ) ); 
          for (dw = all_dw ; dw && ! ((dw -> prompt_tag ) == (cont -> prompt_tag ) ) ; dw = dw -> prev ) {
            p -> dw = p -> dw -> prev ; 
          }
          if (dw )
            dw -> next_meta += 1 ; 
          p -> dw = all_dw ; 
        }
      }
    }
    else {
      p -> dw = common_dw ; 
      p -> next_meta = common_next_meta ; 
    }
    if (cont -> dw ) {
      int meta_depth ; 
#     define XfOrM900_COUNT (0+XfOrM899_COUNT)
#     define SETUP_XfOrM900(x) SETUP_XfOrM899(x)
      common_depth = (p -> dw ? p -> dw -> depth : - 1 ) ; 
      all_dw = FUNCCALL(SETUP_XfOrM900(_), clone_dyn_wind (cont -> dw , ((void * ) 0 ) , cont -> common_dw_depth , p -> dw , 0 , 0 ) ); 
      if ((common_depth != - 1 ) && (common_depth != all_dw -> depth ) ) {
        for (dw = all_dw ; dw -> prev -> depth != common_depth ; dw = dw -> prev ) {
        }
        dw -> next_meta = p -> next_meta ; 
      }
      meta_depth = cont -> next_meta ; 
      for (dw = all_dw ; dw && (dw -> depth != common_depth ) ; dw = dw -> prev ) {
        Scheme_Dynamic_Wind_List * cell ; 
        BLOCK_SETUP((PUSH(cell, 0+XfOrM900_COUNT)));
#       define XfOrM902_COUNT (1+XfOrM900_COUNT)
#       define SETUP_XfOrM902(x) SETUP(XfOrM902_COUNT)
        cell = NULLED_OUT ; 
        cell = ((Scheme_Dynamic_Wind_List * ) FUNCCALL(SETUP_XfOrM902(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Dynamic_Wind_List ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
        cell -> type = scheme_rt_dyn_wind_cell ; 
        cell -> dw = dw ; 
        cell -> meta_depth = meta_depth ; 
        cell -> next = dwl ; 
        dwl = cell ; 
        dwl_len ++ ; 
        meta_depth += dw -> next_meta ; 
      }
      copied_cms = FUNCCALL(SETUP_XfOrM900(_), exec_dyn_wind_pres (dwl , dwl_len , cont , copied_cms , clear_cm_caches , & sub_conts ) ); 
      p = scheme_current_thread ; 
      p -> dw = all_dw ; 
      p -> next_meta = cont -> next_meta ; 
    }
  }
  if (! for_prompt )
    p -> suspend_break = 0 ; 
  scheme_current_cont_mark_pos = cont -> ss . cont_mark_pos ; 
  scheme_current_cont_mark_stack = cont -> ss . cont_mark_stack ; 
  FUNCCALL(SETUP_XfOrM897(_), copy_in_mark_stack (p , cont -> cont_mark_stack_copied , scheme_current_cont_mark_stack , copied_cms , cont -> cont_mark_offset , & sub_conts , clear_cm_caches ) ); 
  if (((result ) == (((Scheme_Object * ) 0x6 ) ) ) ) {
    p -> ku . multiple . array = mv ; 
    p -> ku . multiple . count = mc ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * internal_call_cc (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * ret , * volatile prompt_tag ; 
  Scheme_Cont * volatile cont ; 
  Scheme_Cont * sub_cont ; 
  Scheme_Meta_Continuation * prompt_cont , * barrier_cont ; 
  long prompt_pos , barrier_pos ; 
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Prompt * prompt , * barrier_prompt , * effective_barrier_prompt ; 
  GC_CAN_IGNORE void * stack_start ; 
  int composable ; 
  Scheme_Config * __funcarg75 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(15);
  BLOCK_SETUP_TOP((PUSH(prompt_tag, 0), PUSH(ret, 1), PUSH(argv, 2), PUSH(prompt_cont, 3), PUSH(effective_barrier_prompt, 4), PUSH(barrier_cont, 5), PUSH(sub_cont, 6), PUSH(barrier_prompt, 7), PUSH(cont, 8), PUSH(p, 9), PUSH(prompt, 10)));
# define XfOrM959_COUNT (11)
# define SETUP_XfOrM959(x) SETUP(XfOrM959_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  ret = NULLED_OUT ; 
  prompt_tag = NULLED_OUT ; 
  cont = NULLED_OUT ; 
  sub_cont = NULLED_OUT ; 
  prompt_cont = NULLED_OUT ; 
  barrier_cont = NULLED_OUT ; 
  prompt = NULLED_OUT ; 
  barrier_prompt = NULLED_OUT ; 
  effective_barrier_prompt = NULLED_OUT ; 
  if (argc > 1 )
    prompt_tag = argv [1 ] ; 
  else prompt_tag = scheme_default_prompt_tag ; 
  composable = (argc > 2 ) ; 
  prompt = (Scheme_Prompt * ) FUNCCALL(SETUP_XfOrM959(_), scheme_extract_one_cc_mark_with_meta (((void * ) 0 ) , (((Scheme_Small_Object * ) (prompt_tag ) ) -> u . ptr_val ) , ((void * ) 0 ) , & prompt_cont , & prompt_pos ) ); 
  if (! prompt && ! ((scheme_default_prompt_tag ) == (prompt_tag ) ) ) {
#   define XfOrM975_COUNT (0+XfOrM959_COUNT)
#   define SETUP_XfOrM975(x) SETUP_XfOrM959(x)
    FUNCCALL(SETUP_XfOrM975(_), scheme_arg_mismatch ((composable ? "call-with-composable-continuation" : "call-with-current-continuation" ) , "continuation includes no prompt with the given tag: " , prompt_tag ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  barrier_prompt = FUNCCALL(SETUP_XfOrM959(_), scheme_get_barrier_prompt (& barrier_cont , & barrier_pos ) ); 
  if (composable ) {
#   define XfOrM971_COUNT (0+XfOrM959_COUNT)
#   define SETUP_XfOrM971(x) SETUP_XfOrM959(x)
    if (! prompt && ! barrier_prompt -> is_barrier ) {
    }
    else {
#     define XfOrM972_COUNT (0+XfOrM971_COUNT)
#     define SETUP_XfOrM972(x) SETUP_XfOrM971(x)
      if (! prompt || FUNCCALL(SETUP_XfOrM972(_), scheme_is_cm_deeper (prompt_cont , prompt_pos , barrier_cont , barrier_pos ) )) {
#       define XfOrM973_COUNT (0+XfOrM972_COUNT)
#       define SETUP_XfOrM973(x) SETUP_XfOrM972(x)
        FUNCCALL(SETUP_XfOrM973(_), scheme_raise_exn (MZEXN_FAIL_CONTRACT_CONTINUATION , "call-with-composable-continuation: cannot capture past continuation barrier" ) ); 
      }
    }
  }
  effective_barrier_prompt = barrier_prompt ; 
  if (effective_barrier_prompt && prompt ) {
#   define XfOrM970_COUNT (0+XfOrM959_COUNT)
#   define SETUP_XfOrM970(x) SETUP_XfOrM959(x)
    if (FUNCCALL(SETUP_XfOrM970(_), scheme_is_cm_deeper (barrier_cont , barrier_pos , prompt_cont , prompt_pos ) ))
      effective_barrier_prompt = ((void * ) 0 ) ; 
  }
  if (composable )
    sub_cont = ((void * ) 0 ) ; 
  else sub_cont = (Scheme_Cont * ) FUNCCALL(SETUP_XfOrM959(_), scheme_extract_one_cc_mark (((void * ) 0 ) , cont_key ) ); 
  if (sub_cont && ((sub_cont -> save_overflow != p -> overflow ) || (sub_cont -> prompt_tag != prompt_tag ) || (sub_cont -> barrier_prompt != effective_barrier_prompt ) ) ) {
    sub_cont = ((void * ) 0 ) ; 
  }
  if (sub_cont && (sub_cont -> ss . cont_mark_pos == scheme_current_cont_mark_pos ) ) {
    Scheme_Object * argv2 [1 ] ; 
    BLOCK_SETUP((PUSHARRAY(argv2, 1, 0+XfOrM959_COUNT)));
#   define XfOrM966_COUNT (3+XfOrM959_COUNT)
#   define SETUP_XfOrM966(x) SETUP(XfOrM966_COUNT)
    argv2[0] = NULLED_OUT ; 
    ret = FUNCCALL(SETUP_XfOrM966(_), scheme_native_stack_trace () ); 
    if (! sub_cont -> cont_mark_nonshare && (FUNCCALL(SETUP_XfOrM966(_), find_shareable_marks () )== scheme_current_cont_mark_stack ) && (((ret ) == (sub_cont -> native_trace ) ) || (ret && sub_cont -> native_trace && ((Scheme_Type ) (((((long ) (ret ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ret ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) (sub_cont -> native_trace ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (sub_cont -> native_trace ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && (((((Scheme_Simple_Object * ) (ret ) ) -> u . pair_val . car ) ) == ((((Scheme_Simple_Object * ) (sub_cont -> native_trace ) ) -> u . pair_val . car ) ) ) && (((((Scheme_Simple_Object * ) (ret ) ) -> u . pair_val . cdr ) ) == ((((Scheme_Simple_Object * ) (sub_cont -> native_trace ) ) -> u . pair_val . cdr ) ) ) ) ) ) {
      cont = sub_cont ; 
    }
    else {
      long offset ; 
      Scheme_Cont_Mark * msaved ; 
      BLOCK_SETUP((PUSH(msaved, 0+XfOrM966_COUNT)));
#     define XfOrM967_COUNT (1+XfOrM966_COUNT)
#     define SETUP_XfOrM967(x) SETUP(XfOrM967_COUNT)
      msaved = NULLED_OUT ; 
      cont = ((Scheme_Cont * ) FUNCCALL(SETUP_XfOrM967(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Cont ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
      cont -> so . type = scheme_cont_type ; 
      cont -> buf . cont = sub_cont ; 
      sub_cont = sub_cont -> buf . cont ; 
      cont -> ss . cont_mark_stack = scheme_current_cont_mark_stack ; 
      msaved = FUNCCALL(SETUP_XfOrM967(_), copy_out_mark_stack (p , cont -> ss . cont_mark_stack , sub_cont , & offset , ((void * ) 0 ) , 0 ) ); 
      cont -> cont_mark_stack_copied = msaved ; 
      cont -> cont_mark_offset = offset ; 
      cont -> cont_mark_total = cont -> ss . cont_mark_stack ; 
      offset = FUNCCALL(SETUP_XfOrM967(_), find_shareable_marks () ); 
      cont -> cont_mark_nonshare = cont -> ss . cont_mark_stack - offset ; 
      cont -> native_trace = ret ; 
    }
    argv2 [0 ] = (Scheme_Object * ) cont ; 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM966(_), scheme_tail_apply (argv [0 ] , 1 , argv2 ) )) RET_VALUE_END ; 
  }
  cont = FUNCCALL(SETUP_XfOrM959(_), grab_continuation (p , 0 , composable , prompt_tag , sub_cont , prompt , prompt_cont , prompt_pos , barrier_prompt , effective_barrier_prompt , barrier_cont , barrier_pos ) ); 
  FUNCCALL(SETUP_XfOrM959(_), scheme_zero_unneeded_rands (p ) ); 
  (__funcarg75 = FUNCCALL(SETUP_XfOrM959(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_flatten_config (__funcarg75 ) )) ; 
  {
    void * overflow_id ; 
    overflow_id = NULLED_OUT ; 
    overflow_id = (p -> overflow ? (p -> overflow -> id ? p -> overflow -> id : p -> overflow ) : ((void * ) 0 ) ) ; 
    if (prompt && ! prompt_cont && (prompt -> boundary_overflow_id == overflow_id ) ) {
      stack_start = prompt -> stack_boundary ; 
    }
    else {
      Scheme_Prompt * meta_prompt ; 
      meta_prompt = NULLED_OUT ; 
      if (! barrier_prompt -> is_barrier )
        barrier_prompt = ((void * ) 0 ) ; 
      else if (barrier_prompt -> boundary_overflow_id != overflow_id )
        barrier_prompt = ((void * ) 0 ) ; 
      meta_prompt = p -> meta_prompt ; 
      if (meta_prompt )
        if (meta_prompt -> boundary_overflow_id != overflow_id )
        meta_prompt = ((void * ) 0 ) ; 
      if (barrier_prompt && meta_prompt ) {
        barrier_prompt = ((void * ) 0 ) ; 
      }
      if (barrier_prompt )
        stack_start = barrier_prompt -> stack_boundary ; 
      else if (meta_prompt )
        stack_start = meta_prompt -> stack_boundary ; 
      else stack_start = (p -> stack_start ) ; 
    }
  }
  cont -> prompt_stack_start = stack_start ; 
  prompt_cont = ((void * ) 0 ) ; 
  barrier_cont = ((void * ) 0 ) ; 
  if (FUNCCALL(SETUP_XfOrM959(_), scheme_setjmpup_relative (& cont -> buf , cont , stack_start , sub_cont ) )) {
    Scheme_Object * result , * extra_marks ; 
    Scheme_Overflow * resume ; 
    Scheme_Cont * use_next_cont ; 
    Scheme_Dynamic_Wind * common_dw ; 
    Scheme_Prompt * shortcut_prompt ; 
    int common_next_meta , empty_to_next_mc ; 
    BLOCK_SETUP((PUSH(result, 0+XfOrM959_COUNT)));
#   define XfOrM961_COUNT (1+XfOrM959_COUNT)
#   define SETUP_XfOrM961(x) SETUP(XfOrM961_COUNT)
    result = NULLED_OUT ; 
    extra_marks = NULLED_OUT ; 
    resume = NULLED_OUT ; 
    use_next_cont = NULLED_OUT ; 
    common_dw = NULLED_OUT ; 
    shortcut_prompt = NULLED_OUT ; 
    p = scheme_current_thread ; 
    result = cont -> value ; 
    cont -> value = ((void * ) 0 ) ; 
    resume = cont -> resume_to ; 
    cont -> resume_to = ((void * ) 0 ) ; 
    use_next_cont = cont -> use_next_cont ; 
    cont -> use_next_cont = ((void * ) 0 ) ; 
    extra_marks = cont -> extra_marks ; 
    cont -> extra_marks = ((void * ) 0 ) ; 
    common_dw = cont -> common_dw ; 
    cont -> common_dw = ((void * ) 0 ) ; 
    common_next_meta = cont -> common_next_meta ; 
    cont -> common_next_meta = 0 ; 
    shortcut_prompt = cont -> shortcut_prompt ; 
    cont -> shortcut_prompt = ((void * ) 0 ) ; 
    empty_to_next_mc = cont -> empty_to_next_mc ; 
    cont -> empty_to_next_mc = 0 ; 
    FUNCCALL(SETUP_XfOrM961(_), restore_continuation (cont , p , 0 , result , resume , empty_to_next_mc , prompt_tag , sub_cont , common_dw , common_next_meta , shortcut_prompt , ! ! resume , 1 , use_next_cont , extra_marks ) ); 
    FUNCCALL_AGAIN(scheme_check_break_now () ); 
    RET_VALUE_START (result ) RET_VALUE_END ; 
  }
  else {
    Scheme_Object * argv2 [1 ] ; 
    BLOCK_SETUP((PUSHARRAY(argv2, 1, 0+XfOrM959_COUNT)));
#   define XfOrM960_COUNT (3+XfOrM959_COUNT)
#   define SETUP_XfOrM960(x) SETUP(XfOrM960_COUNT)
    argv2[0] = NULLED_OUT ; 
    argv2 [0 ] = (Scheme_Object * ) cont ; 
    ret = FUNCCALL(SETUP_XfOrM960(_), scheme_tail_apply (argv [0 ] , 1 , argv2 ) ); 
    RET_VALUE_START (ret ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * continuation_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cont_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_escaping_cont_type ) ) ) ? scheme_true : scheme_false ) ; 
}
void scheme_takeover_stacks (Scheme_Thread * p ) {
  PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(p, 0)));
# define XfOrM977_COUNT (1)
# define SETUP_XfOrM977(x) SETUP(XfOrM977_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (p -> runstack_owner && ((* p -> runstack_owner ) != p ) ) {
    Scheme_Thread * op ; 
    Scheme_Saved_Stack * swapped ; 
    BLOCK_SETUP((PUSH(op, 0+XfOrM977_COUNT), PUSH(swapped, 1+XfOrM977_COUNT)));
#   define XfOrM980_COUNT (2+XfOrM977_COUNT)
#   define SETUP_XfOrM980(x) SETUP(XfOrM980_COUNT)
    op = NULLED_OUT ; 
    swapped = NULLED_OUT ; 
    op = * p -> runstack_owner ; 
    if (op ) {
#     define XfOrM981_COUNT (0+XfOrM980_COUNT)
#     define SETUP_XfOrM981(x) SETUP_XfOrM980(x)
      swapped = FUNCCALL(SETUP_XfOrM981(_), copy_out_runstack (op , op -> runstack , op -> runstack_start , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
      op -> runstack_swapped = swapped ; 
    }
    * (p -> runstack_owner ) = p ; 
    FUNCCALL(SETUP_XfOrM980(_), copy_in_runstack (p , p -> runstack_swapped , 1 ) ); 
    p -> runstack_swapped = ((void * ) 0 ) ; 
  }
  if (p -> cont_mark_stack_owner && ((* p -> cont_mark_stack_owner ) != p ) ) {
    Scheme_Thread * op ; 
    Scheme_Cont_Mark * swapped ; 
    BLOCK_SETUP((PUSH(op, 0+XfOrM977_COUNT), PUSH(swapped, 1+XfOrM977_COUNT)));
#   define XfOrM978_COUNT (2+XfOrM977_COUNT)
#   define SETUP_XfOrM978(x) SETUP(XfOrM978_COUNT)
    op = NULLED_OUT ; 
    swapped = NULLED_OUT ; 
    op = * p -> cont_mark_stack_owner ; 
    if (op ) {
#     define XfOrM979_COUNT (0+XfOrM978_COUNT)
#     define SETUP_XfOrM979(x) SETUP_XfOrM978(x)
      swapped = FUNCCALL(SETUP_XfOrM979(_), copy_out_mark_stack (op , op -> cont_mark_stack , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ); 
      op -> cont_mark_stack_swapped = swapped ; 
    }
    * (p -> cont_mark_stack_owner ) = p ; 
    FUNCCALL(SETUP_XfOrM978(_), copy_in_mark_stack (p , p -> cont_mark_stack_swapped , scheme_current_cont_mark_stack , 0 , 0 , ((void * ) 0 ) , 0 ) ); 
    p -> cont_mark_stack_swapped = ((void * ) 0 ) ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * call_with_continuation_barrier (int argc , Scheme_Object * argv [] ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM982_COUNT (1)
# define SETUP_XfOrM982(x) SETUP(XfOrM982_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM982(_), scheme_check_proc_arity ("call-with-continuation-barrier" , 0 , 0 , argc , argv ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_apply (argv [0 ] , 0 , ((void * ) 0 ) ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Prompt * scheme_get_barrier_prompt (Scheme_Meta_Continuation * * _meta_cont , long * _pos ) {
  /* No conversion */
  return (Scheme_Prompt * ) scheme_extract_one_cc_mark_with_meta (((void * ) 0 ) , barrier_prompt_key , ((void * ) 0 ) , _meta_cont , _pos ) ; 
}
static Scheme_Object * make_prompt_tag (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * o , * key ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(argv, 1), PUSH(key, 2)));
# define XfOrM984_COUNT (3)
# define SETUP_XfOrM984(x) SETUP(XfOrM984_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  o = NULLED_OUT ; 
  key = NULLED_OUT ; 
  if (argc && ! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("make-continuation-prompt-tag" , "symbol" , 0 , argc , argv ) ); 
  key = FUNCCALL(SETUP_XfOrM984(_), scheme_make_pair (scheme_false , scheme_false ) ); 
  o = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM984(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  o -> type = scheme_prompt_tag_type ; 
  (((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . car ) = key ; 
  (((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . cdr ) = (argc ? argv [0 ] : ((void * ) 0 ) ) ; 
  RET_VALUE_START (o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * get_default_prompt_tag (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_default_prompt_tag ; 
}
static Scheme_Object * prompt_tag_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (((Scheme_Type ) (scheme_prompt_tag_type ) == (Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) ) ? scheme_true : scheme_false ) ; 
}
Scheme_Overflow * scheme_get_thread_end_overflow (void ) {
  Scheme_Overflow * overflow ; 
  DECL_RET_SAVE (Scheme_Overflow * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(overflow, 0)));
# define XfOrM987_COUNT (1)
# define SETUP_XfOrM987(x) SETUP(XfOrM987_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  overflow = NULLED_OUT ; 
  overflow = ((Scheme_Overflow * ) FUNCCALL(SETUP_XfOrM987(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Overflow ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  overflow -> type = scheme_rt_overflow ; 
  overflow -> eot = 1 ; 
  RET_VALUE_START (overflow ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_drop_prompt_meta_continuations (Scheme_Object * prompt_tag ) {
  /* No conversion */
  Scheme_Meta_Continuation * mc ; 
  mc = scheme_current_thread -> meta_continuation ; 
  while (! ((mc -> prompt_tag ) == (prompt_tag ) ) ) {
    if (mc -> overflow ) {
      scheme_signal_error ("meta-continuation to drop is not just a placeholder?!" ) ; 
    }
    mc = mc -> next ; 
  }
  scheme_current_thread -> meta_continuation = mc ; 
}
Scheme_Object * scheme_finish_apply_for_prompt (Scheme_Prompt * prompt , Scheme_Object * _prompt_tag , Scheme_Object * proc , int argc , Scheme_Object * * argv ) {
  Scheme_Thread * p ; 
  Scheme_Object * volatile prompt_tag = _prompt_tag ; 
  mz_jmp_buf newbuf , * volatile savebuf ; 
  Scheme_Object * val ; 
  int cc_count = scheme_cont_capture_count ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(val, 0), PUSH(prompt_tag, 1), PUSH(argv, 2), PUSH(p, 3), PUSH(savebuf, 4), PUSH(proc, 5)));
# define XfOrM993_COUNT (6)
# define SETUP_XfOrM993(x) SETUP(XfOrM993_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  p = NULLED_OUT ; 
  savebuf = NULLED_OUT ; 
  val = NULLED_OUT ; 
  prompt -> prompt_buf = & newbuf ; 
  prompt = ((void * ) 0 ) ; 
  p = scheme_current_thread ; 
  savebuf = p -> error_buf ; 
  p -> error_buf = & newbuf ; 
  {
    Scheme_Meta_Continuation * resume_mc ; 
    BLOCK_SETUP((PUSH(resume_mc, 0+XfOrM993_COUNT)));
#   define XfOrM1003_COUNT (1+XfOrM993_COUNT)
#   define SETUP_XfOrM1003(x) SETUP(XfOrM1003_COUNT)
    resume_mc = NULLED_OUT ; 
    if (available_prompt_mc ) {
      resume_mc = available_prompt_mc ; 
      available_prompt_mc = ((void * ) 0 ) ; 
    }
    else resume_mc = ((Scheme_Meta_Continuation * ) FUNCCALL(SETUP_XfOrM1003(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Meta_Continuation ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    resume_mc -> type = scheme_rt_meta_cont ; 
    resume_mc -> prompt_tag = prompt_tag ; 
    if (p -> meta_continuation ) {
      resume_mc -> next = p -> meta_continuation ; 
      resume_mc -> depth = p -> meta_continuation -> depth + 1 ; 
    }
    resume_mc -> meta_tail_pos = scheme_current_cont_mark_pos + 2 ; 
    p -> meta_continuation = resume_mc ; 
  }
  if (((newbuf ) . gcvs = (long ) __gc_var_stack__ , (newbuf ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((newbuf ) . jb ) , (_setjmp (((newbuf ) . jb ) -> jb ) ) ) ) ) {
    val = ((void * ) 0 ) ; 
  }
  else {
#   define XfOrM1001_COUNT (0+XfOrM993_COUNT)
#   define SETUP_XfOrM1001(x) SETUP_XfOrM993(x)
    val = FUNCCALL(SETUP_XfOrM1001(_), scheme_do_eval (proc , argc , argv , - 1 ) ); 
  }
  p = scheme_current_thread ; 
  p -> error_buf = savebuf ; 
  {
    Scheme_Meta_Continuation * resume_mc ; 
    Scheme_Overflow * resume ; 
    BLOCK_SETUP((PUSH(resume, 0+XfOrM993_COUNT)));
#   define XfOrM994_COUNT (1+XfOrM993_COUNT)
#   define SETUP_XfOrM994(x) SETUP(XfOrM994_COUNT)
    resume_mc = NULLED_OUT ; 
    resume = NULLED_OUT ; 
    resume = p -> meta_continuation -> overflow ; 
    resume_mc = p -> meta_continuation ; 
    p -> meta_continuation = p -> meta_continuation -> next ; 
    if (cc_count == scheme_cont_capture_count ) {
#     define XfOrM1000_COUNT (0+XfOrM994_COUNT)
#     define SETUP_XfOrM1000(x) SETUP_XfOrM994(x)
      (memset (resume_mc , 0 , sizeof (Scheme_Meta_Continuation ) ) ) ; 
      resume_mc -> type = scheme_rt_meta_cont ; 
      available_prompt_mc = resume_mc ; 
    }
    if (! resume ) {
      RET_VALUE_START (val ) RET_VALUE_END ; 
    }
    else if (resume -> eot ) {
#     define XfOrM998_COUNT (0+XfOrM994_COUNT)
#     define SETUP_XfOrM998(x) SETUP_XfOrM994(x)
      scheme_current_runstack = ((void * ) 0 ) ; 
      scheme_current_runstack_start = ((void * ) 0 ) ; 
      scheme_current_cont_mark_stack = 0 ; 
      p -> runstack_start = ((void * ) 0 ) ; 
      p -> runstack = ((void * ) 0 ) ; 
      p -> runstack_size = 0 ; 
      p -> runstack_saved = ((void * ) 0 ) ; 
      p -> cont_mark_stack_segments = ((void * ) 0 ) ; 
      FUNCCALL(SETUP_XfOrM998(_), scheme_end_current_thread () ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else {
#     define XfOrM995_COUNT (0+XfOrM994_COUNT)
#     define SETUP_XfOrM995(x) SETUP_XfOrM994(x)
      p -> next_meta -= 1 ; 
      if (val ) {
        if (val == ((Scheme_Object * ) 0x6 ) ) {
          if (((p -> ku . multiple . array ) == (p -> values_buffer ) ) )
            p -> values_buffer = ((void * ) 0 ) ; 
        }
        p -> cjs . val = val ; 
      }
      p -> stack_start = resume -> stack_start ; 
      FUNCCALL(SETUP_XfOrM995(_), scheme_longjmpup (& resume -> jmp -> cont ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_apply_for_prompt (Scheme_Prompt * prompt , Scheme_Object * prompt_tag , Scheme_Object * proc , int argc , Scheme_Object * * argv ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(prompt_tag, 0), PUSH(proc, 1), PUSH(argv, 2), PUSH(prompt, 3)));
# define XfOrM1006_COUNT (4)
# define SETUP_XfOrM1006(x) SETUP(XfOrM1006_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  prompt -> stack_boundary = & __gc_var_stack__ ; 
  FUNCCALL(SETUP_XfOrM1006(_), scheme_ensure_stack_start (prompt -> stack_boundary ) ); 
  proc = FUNCCALL_AGAIN(scheme_finish_apply_for_prompt (prompt , prompt_tag , proc , argc , argv ) ); 
  RET_VALUE_START (proc ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * compose_continuation (Scheme_Cont * cont , int exec_chain , Scheme_Object * loop_prompt , int empty_to_next_mc ) {
  Scheme_Overflow * overflow ; 
  Scheme_Overflow_Jmp * jmp ; 
  Scheme_Cont * saved ; 
  Scheme_Prompt * saved_meta_prompt ; 
  Scheme_Thread * p = scheme_current_thread ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(9);
  BLOCK_SETUP_TOP((PUSH(overflow, 0), PUSH(cont, 1), PUSH(saved_meta_prompt, 2), PUSH(saved, 3), PUSH(jmp, 4), PUSH(loop_prompt, 5), PUSH(p, 6)));
# define XfOrM1007_COUNT (7)
# define SETUP_XfOrM1007(x) SETUP(XfOrM1007_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  overflow = NULLED_OUT ; 
  jmp = NULLED_OUT ; 
  saved = NULLED_OUT ; 
  saved_meta_prompt = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM1007(_), scheme_about_to_move_C_stack () ); 
  FUNCCALL_AGAIN(reset_cjs (& p -> cjs ) ); 
  saved_meta_prompt = p -> meta_prompt ; 
  saved = FUNCCALL(SETUP_XfOrM1007(_), grab_continuation (p , 1 , 0 , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , 0 , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ); 
  overflow = ((Scheme_Overflow * ) FUNCCALL(SETUP_XfOrM1007(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Overflow ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  overflow -> type = scheme_rt_overflow ; 
  overflow -> prev = p -> overflow ; 
  overflow -> stack_start = p -> stack_start ; 
  jmp = ((Scheme_Overflow_Jmp * ) FUNCCALL(SETUP_XfOrM1007(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Overflow_Jmp ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  jmp -> type = scheme_rt_overflow_jmp ; 
  overflow -> jmp = jmp ; 
  FUNCCALL(SETUP_XfOrM1007(_), scheme_init_jmpup_buf (& overflow -> jmp -> cont ) ); 
  if (FUNCCALL(SETUP_XfOrM1007(_), scheme_setjmpup_relative (& overflow -> jmp -> cont , overflow -> jmp , (p -> stack_start ) , ((void * ) 0 ) ) )) {
    Scheme_Object * v ; 
    Scheme_Meta_Continuation * mc ; 
    BLOCK_SETUP((PUSH(v, 0+XfOrM1007_COUNT), PUSH(mc, 1+XfOrM1007_COUNT)));
#   define XfOrM1008_COUNT (2+XfOrM1007_COUNT)
#   define SETUP_XfOrM1008(x) SETUP(XfOrM1008_COUNT)
    v = NULLED_OUT ; 
    mc = NULLED_OUT ; 
    p = scheme_current_thread ; 
    if (! p -> cjs . jumping_to_continuation ) {
      v = p -> cjs . val ; 
      p -> cjs . val = ((void * ) 0 ) ; 
      if (((v ) == (((Scheme_Object * ) 0x6 ) ) ) ) {
        if (((p -> ku . multiple . array ) == (p -> values_buffer ) ) )
          p -> values_buffer = ((void * ) 0 ) ; 
      }
    }
    else {
      v = ((void * ) 0 ) ; 
    }
    mc = p -> meta_continuation ; 
    p -> meta_prompt = saved_meta_prompt ; 
    FUNCCALL(SETUP_XfOrM1008(_), restore_continuation (saved , p , 1 , v , ((void * ) 0 ) , 0 , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , 0 , ((void * ) 0 ) , 0 , ! p -> cjs . jumping_to_continuation , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
    p -> meta_continuation = mc ; 
    if (! v && ((loop_prompt && (((Scheme_Object * ) p -> cjs . jumping_to_continuation ) == (loop_prompt ) ) && p -> cjs . is_escape ) || (! loop_prompt && p -> cjs . jumping_to_continuation && ((Scheme_Type ) (((((long ) ((Scheme_Object * ) p -> cjs . jumping_to_continuation ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((Scheme_Object * ) p -> cjs . jumping_to_continuation ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) ) ) {
#     define XfOrM1010_COUNT (0+XfOrM1008_COUNT)
#     define SETUP_XfOrM1010(x) SETUP_XfOrM1008(x)
      cont = (Scheme_Cont * ) p -> cjs . val ; 
      if (((Scheme_Type ) (((((long ) ((Scheme_Object * ) p -> cjs . jumping_to_continuation ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((Scheme_Object * ) p -> cjs . jumping_to_continuation ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
        cont -> extra_marks = (Scheme_Object * ) p -> cjs . jumping_to_continuation ; 
      }
      FUNCCALL(SETUP_XfOrM1010(_), reset_cjs (& p -> cjs ) ); 
      saved -> meta_continuation = p -> meta_continuation ; 
    }
    else {
      RET_VALUE_START (v ) RET_VALUE_END ; 
    }
  }
  scheme_current_thread -> suspend_break ++ ; 
  saved -> resume_to = overflow ; 
  cont -> use_next_cont = saved ; 
  cont -> resume_to = overflow ; 
  cont -> empty_to_next_mc = (char ) empty_to_next_mc ; 
  scheme_current_thread -> stack_start = cont -> prompt_stack_start ; 
  FUNCCALL(SETUP_XfOrM1007(_), scheme_longjmpup (& cont -> buf ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void continue_prompt_escape () {
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Prompt * targetc = (Scheme_Prompt * ) p -> cjs . jumping_to_continuation ; 
  PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(targetc, 0), PUSH(p, 1)));
# define XfOrM1015_COUNT (2)
# define SETUP_XfOrM1015(x) SETUP(XfOrM1015_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  FUNCCALL(SETUP_XfOrM1015(_), scheme_drop_prompt_meta_continuations (targetc -> tag ) ); 
  if ((! targetc -> boundary_overflow_id && ! p -> overflow ) || (targetc -> boundary_overflow_id == p -> overflow -> id ) ) {
    (((long * ) (void * ) ((* targetc -> prompt_buf ) . gcvs ) ) [1 ] = (* targetc -> prompt_buf ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* targetc -> prompt_buf ) . gcvs , scheme_jit_longjmp ((* targetc -> prompt_buf ) . jb , 1 ) ) ; 
  }
  else {
    Scheme_Overflow * overflow = p -> overflow ; 
    BLOCK_SETUP((PUSH(overflow, 0+XfOrM1015_COUNT)));
#   define XfOrM1016_COUNT (1+XfOrM1015_COUNT)
#   define SETUP_XfOrM1016(x) SETUP(XfOrM1016_COUNT)
    while (overflow -> prev && (! overflow -> prev -> id || (overflow -> prev -> id != targetc -> boundary_overflow_id ) ) ) {
      overflow = overflow -> prev ; 
    }
    p -> overflow = overflow ; 
    p -> stack_start = overflow -> stack_start ; 
    FUNCCALL(SETUP_XfOrM1016(_), scheme_longjmpup (& overflow -> jmp -> cont ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void restore_from_prompt (Scheme_Prompt * prompt ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  while (scheme_current_runstack_start != prompt -> runstack_boundary_start ) {
    scheme_current_runstack_start = p -> runstack_saved -> runstack_start ; 
    p -> runstack_saved = p -> runstack_saved -> prev ; 
  }
  scheme_current_runstack = scheme_current_runstack_start + prompt -> runstack_boundary_offset ; 
  scheme_current_cont_mark_stack = prompt -> mark_boundary ; 
  scheme_current_cont_mark_pos = prompt -> boundary_mark_pos ; 
  p -> runstack_size = prompt -> runstack_size ; 
  if (prompt -> boundary_overflow_id ) {
    while (p -> overflow -> id != prompt -> boundary_overflow_id ) {
      p -> overflow = p -> overflow -> prev ; 
    }
  }
  else p -> overflow = ((void * ) 0 ) ; 
}
static void prompt_unwind_dw (Scheme_Object * prompt_tag ) {
  /* No conversion */
  int delta = 0 ; 
  Scheme_Thread * p = scheme_current_thread ; 
  while (p -> dw && ! ((p -> dw -> prompt_tag ) == (prompt_tag ) ) ) {
    delta += p -> dw -> next_meta ; 
    p -> dw = p -> dw -> prev ; 
  }
  if (! p -> dw ) {
    scheme_signal_error ("Lost prompt dynamic-wind record!\n" ) ; 
  }
  else {
    delta += p -> dw -> next_meta ; 
    p -> dw = p -> dw -> prev ; 
    p -> next_meta += delta ; 
  }
}
static void prompt_unwind_one_dw (Scheme_Object * prompt_tag ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  if (! p -> dw || ! ((p -> dw -> prompt_tag ) == (prompt_tag ) ) ) {
    scheme_signal_error ("Dynamic-wind record doesn't match prompt!\n" ) ; 
  }
  else prompt_unwind_dw (prompt_tag ) ; 
}
static Scheme_Object * call_with_prompt (int in_argc , Scheme_Object * in_argv [] ) {
  Scheme_Object * v ; 
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * proc = in_argv [0 ] , * prompt_tag ; 
  Scheme_Prompt * prompt ; 
  int argc , handler_argument_error = 0 ; 
  Scheme_Object * * argv , * a [1 ] , * handler ; 
  Scheme_Cont_Frame_Data cframe ; 
  Scheme_Dynamic_Wind * prompt_dw ; 
  int cc_count = scheme_cont_capture_count ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(14);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(prompt_tag, 1), PUSH(cframe.cache, 2), PUSH(argv, 3), PUSHARRAY(a, 1, 4), PUSH(prompt, 7), PUSH(proc, 8), PUSH(prompt_dw, 9), PUSH(p, 10), PUSH(handler, 11), PUSH(in_argv, 12)));
# define XfOrM1033_COUNT (13)
# define SETUP_XfOrM1033(x) SETUP(XfOrM1033_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  v = NULLED_OUT ; 
  prompt_tag = NULLED_OUT ; 
  prompt = NULLED_OUT ; 
  argv = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  handler = NULLED_OUT ; 
  cframe.cache = NULLED_OUT ; 
  prompt_dw = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM1033(_), scheme_check_proc_arity ("call-with-continuation-prompt" , 0 , 0 , in_argc , in_argv ) ); 
  if (in_argc > 1 ) {
#   define XfOrM1101_COUNT (0+XfOrM1033_COUNT)
#   define SETUP_XfOrM1101(x) SETUP_XfOrM1033(x)
    if (! ((Scheme_Type ) (scheme_prompt_tag_type ) == (Scheme_Type ) (((((long ) (in_argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (in_argv [1 ] ) ) -> type ) ) ) ) {
#     define XfOrM1102_COUNT (0+XfOrM1101_COUNT)
#     define SETUP_XfOrM1102(x) SETUP_XfOrM1101(x)
      FUNCCALL(SETUP_XfOrM1102(_), scheme_wrong_type ("call-with-continuation-prompt" , "continuation-prompt-tag" , 1 , in_argc , in_argv ) ); 
    }
    prompt_tag = in_argv [1 ] ; 
  }
  else prompt_tag = scheme_default_prompt_tag ; 
  if (in_argc > 2 ) {
#   define XfOrM1100_COUNT (0+XfOrM1033_COUNT)
#   define SETUP_XfOrM1100(x) SETUP_XfOrM1033(x)
    if ((! (((in_argv [2 ] ) ) == (scheme_false ) ) ) && ! (! (((long ) (in_argv [2 ] ) ) & 0x1 ) && ((((in_argv [2 ] ) -> type ) >= scheme_prim_type ) && (((in_argv [2 ] ) -> type ) <= scheme_native_closure_type ) ) ) )
      FUNCCALL(SETUP_XfOrM1100(_), scheme_wrong_type ("call-with-continuation-prompt" , "procedure or #f" , 2 , in_argc , in_argv ) ); 
    handler = in_argv [2 ] ; 
  }
  else handler = scheme_false ; 
  argv = ((void * ) 0 ) ; 
  argc = 0 ; 
  do {
#   define XfOrM1069_COUNT (0+XfOrM1033_COUNT)
#   define SETUP_XfOrM1069(x) SETUP_XfOrM1033(x)
    if (available_regular_prompt ) {
      prompt = available_regular_prompt ; 
      available_regular_prompt = ((void * ) 0 ) ; 
    }
    else prompt = ((Scheme_Prompt * ) FUNCCALL(SETUP_XfOrM1069(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Prompt ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    prompt -> so . type = scheme_prompt_type ; 
    prompt -> tag = prompt_tag ; 
    FUNCCALL(SETUP_XfOrM1069(_), scheme_push_continuation_frame (& cframe ) ); 
    FUNCCALL_AGAIN(scheme_set_cont_mark ((((Scheme_Small_Object * ) (prompt_tag ) ) -> u . ptr_val ) , (Scheme_Object * ) prompt ) ); 
    FUNCCALL_AGAIN(ASSERT_SUSPEND_BREAK_ZERO () ); 
    FUNCCALL_AGAIN(initialize_prompt (p , prompt , ((void * ) 0 ) ) ); 
    if (p -> overflow ) {
#     define XfOrM1098_COUNT (0+XfOrM1069_COUNT)
#     define SETUP_XfOrM1098(x) SETUP_XfOrM1069(x)
      FUNCCALL(SETUP_XfOrM1098(_), ensure_overflow_id (p -> overflow ) ); 
      prompt -> boundary_overflow_id = p -> overflow -> id ; 
    }
    prompt -> runstack_size = p -> runstack_size ; 
    if (available_prompt_dw ) {
      prompt_dw = available_prompt_dw ; 
      available_prompt_dw = ((void * ) 0 ) ; 
    }
    else prompt_dw = ((Scheme_Dynamic_Wind * ) FUNCCALL(SETUP_XfOrM1069(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Dynamic_Wind ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    prompt_dw -> type = scheme_rt_dyn_wind ; 
    prompt_dw -> prompt_tag = prompt_tag ; 
    if (p -> dw ) {
      prompt_dw -> next_meta = p -> next_meta ; 
      prompt_dw -> prev = p -> dw ; 
      prompt_dw -> depth = p -> dw -> depth + 1 ; 
    }
    p -> next_meta = 0 ; 
    p -> dw = prompt_dw ; 
    v = FUNCCALL(SETUP_XfOrM1069(_), scheme_apply_for_prompt (prompt , prompt_tag , proc , argc , argv ) ); 
    p = scheme_current_thread ; 
    FUNCCALL(SETUP_XfOrM1069(_), restore_from_prompt (prompt ) ); 
    p -> suspend_break = 0 ; 
    if (! v ) {
#     define XfOrM1074_COUNT (0+XfOrM1069_COUNT)
#     define SETUP_XfOrM1074(x) SETUP_XfOrM1069(x)
      if ((((Scheme_Object * ) p -> cjs . jumping_to_continuation ) == ((Scheme_Object * ) prompt ) ) ) {
#       define XfOrM1077_COUNT (0+XfOrM1074_COUNT)
#       define SETUP_XfOrM1077(x) SETUP_XfOrM1074(x)
        if (p -> cjs . is_escape ) {
          Scheme_Cont * target ; 
          BLOCK_SETUP((PUSH(target, 0+XfOrM1077_COUNT)));
#         define XfOrM1088_COUNT (1+XfOrM1077_COUNT)
#         define SETUP_XfOrM1088(x) SETUP(XfOrM1088_COUNT)
          target = NULLED_OUT ; 
          target = (Scheme_Cont * ) p -> cjs . val ; 
          FUNCCALL(SETUP_XfOrM1088(_), reset_cjs (& p -> cjs ) ); 
          v = FUNCCALL_AGAIN(compose_continuation (target , 1 , (Scheme_Object * ) prompt , 0 ) ); 
          if (v ) {
#           define XfOrM1095_COUNT (0+XfOrM1088_COUNT)
#           define SETUP_XfOrM1095(x) SETUP_XfOrM1088(x)
            FUNCCALL(SETUP_XfOrM1095(_), prompt_unwind_one_dw (prompt_tag ) ); 
            handler = ((void * ) 0 ) ; 
          }
          else {
#           define XfOrM1089_COUNT (0+XfOrM1088_COUNT)
#           define SETUP_XfOrM1089(x) SETUP_XfOrM1088(x)
            p = scheme_current_thread ; 
            if ((((Scheme_Object * ) p -> cjs . jumping_to_continuation ) == ((Scheme_Object * ) prompt ) ) ) {
#             define XfOrM1092_COUNT (0+XfOrM1089_COUNT)
#             define SETUP_XfOrM1092(x) SETUP_XfOrM1089(x)
              if (p -> cjs . is_escape ) {
#               define XfOrM1094_COUNT (0+XfOrM1092_COUNT)
#               define SETUP_XfOrM1094(x) SETUP_XfOrM1092(x)
                FUNCCALL(SETUP_XfOrM1094(_), scheme_signal_error ("escape-to-prompt escaped!" ) ); 
                RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
              }
              else {
#               define XfOrM1093_COUNT (0+XfOrM1092_COUNT)
#               define SETUP_XfOrM1093(x) SETUP_XfOrM1092(x)
                FUNCCALL(SETUP_XfOrM1093(_), prompt_unwind_one_dw (prompt_tag ) ); 
                v = ((void * ) 0 ) ; 
              }
            }
            else if (p -> cjs . is_escape ) {
#             define XfOrM1091_COUNT (0+XfOrM1089_COUNT)
#             define SETUP_XfOrM1091(x) SETUP_XfOrM1089(x)
              FUNCCALL(SETUP_XfOrM1091(_), continue_prompt_escape () ); 
              RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
            }
            else {
#             define XfOrM1090_COUNT (0+XfOrM1089_COUNT)
#             define SETUP_XfOrM1090(x) SETUP_XfOrM1089(x)
              FUNCCALL(SETUP_XfOrM1090(_), restore_from_prompt (prompt ) ); 
              FUNCCALL(SETUP_XfOrM1090(_), prompt_unwind_one_dw (prompt_tag ) ); 
              (((long * ) (void * ) ((* p -> error_buf ) . gcvs ) ) [1 ] = (* p -> error_buf ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* p -> error_buf ) . gcvs , scheme_jit_longjmp ((* p -> error_buf ) . jb , 1 ) ) ; 
              RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
            }
          }
        }
        else {
#         define XfOrM1087_COUNT (0+XfOrM1077_COUNT)
#         define SETUP_XfOrM1087(x) SETUP_XfOrM1077(x)
          FUNCCALL(SETUP_XfOrM1087(_), prompt_unwind_one_dw (prompt_tag ) ); 
          v = ((void * ) 0 ) ; 
        }
        if (! v ) {
#         define XfOrM1079_COUNT (0+XfOrM1077_COUNT)
#         define SETUP_XfOrM1079(x) SETUP_XfOrM1077(x)
          argc = p -> cjs . num_vals ; 
          if (argc == 1 ) {
            a [0 ] = p -> cjs . val ; 
            argv = a ; 
          }
          else argv = (Scheme_Object * * ) p -> cjs . val ; 
          FUNCCALL(SETUP_XfOrM1079(_), reset_cjs (& p -> cjs ) ); 
          if (((handler ) == (scheme_values_func ) ) ) {
#           define XfOrM1085_COUNT (0+XfOrM1079_COUNT)
#           define SETUP_XfOrM1085(x) SETUP_XfOrM1079(x)
            v = FUNCCALL(SETUP_XfOrM1085(_), scheme_values (argc , argv ) ); 
            handler = ((void * ) 0 ) ; 
          }
          else if ((((handler ) ) == (scheme_false ) ) ) {
#           define XfOrM1080_COUNT (0+XfOrM1079_COUNT)
#           define SETUP_XfOrM1080(x) SETUP_XfOrM1079(x)
            if (argc == 1 ) {
#             define XfOrM1082_COUNT (0+XfOrM1080_COUNT)
#             define SETUP_XfOrM1082(x) SETUP_XfOrM1080(x)
              if (! FUNCCALL(SETUP_XfOrM1082(_), scheme_check_proc_arity (((void * ) 0 ) , 0 , 0 , argc , argv ) )) {
                handler_argument_error = 1 ; 
                handler = ((void * ) 0 ) ; 
              }
              else {
                proc = a [0 ] ; 
                argc = 0 ; 
                argv = ((void * ) 0 ) ; 
              }
            }
            else {
              handler_argument_error = 1 ; 
              handler = ((void * ) 0 ) ; 
            }
          }
        }
        else {
          argc = 0 ; 
          argv = ((void * ) 0 ) ; 
        }
      }
      else {
#       define XfOrM1075_COUNT (0+XfOrM1074_COUNT)
#       define SETUP_XfOrM1075(x) SETUP_XfOrM1074(x)
        if ((p -> dw != prompt_dw ) && (! p -> dw || ! prompt_dw -> id || (p -> dw -> id != prompt_dw -> id ) ) ) {
        }
        else FUNCCALL(SETUP_XfOrM1075(_), prompt_unwind_one_dw (prompt_tag ) ); 
        (((long * ) (void * ) ((* p -> error_buf ) . gcvs ) ) [1 ] = (* p -> error_buf ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* p -> error_buf ) . gcvs , scheme_jit_longjmp ((* p -> error_buf ) . jb , 1 ) ) ; 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
    }
    else {
#     define XfOrM1073_COUNT (0+XfOrM1069_COUNT)
#     define SETUP_XfOrM1073(x) SETUP_XfOrM1069(x)
      FUNCCALL(SETUP_XfOrM1073(_), prompt_unwind_one_dw (prompt_tag ) ); 
      handler = ((void * ) 0 ) ; 
      argc = 0 ; 
      argv = ((void * ) 0 ) ; 
    }
    FUNCCALL(SETUP_XfOrM1069(_), scheme_pop_continuation_frame (& cframe ) ); 
    if (cc_count == scheme_cont_capture_count ) {
#     define XfOrM1070_COUNT (0+XfOrM1069_COUNT)
#     define SETUP_XfOrM1070(x) SETUP_XfOrM1069(x)
      if (! available_regular_prompt ) {
#       define XfOrM1072_COUNT (0+XfOrM1070_COUNT)
#       define SETUP_XfOrM1072(x) SETUP_XfOrM1070(x)
        (memset (prompt , 0 , sizeof (Scheme_Prompt ) ) ) ; 
        prompt -> so . type = scheme_prompt_type ; 
        available_regular_prompt = prompt ; 
      }
      if (! available_prompt_dw ) {
#       define XfOrM1071_COUNT (0+XfOrM1070_COUNT)
#       define SETUP_XfOrM1071(x) SETUP_XfOrM1070(x)
        (memset (prompt_dw , 0 , sizeof (Scheme_Dynamic_Wind ) ) ) ; 
        prompt_dw -> type = scheme_rt_dyn_wind ; 
        available_prompt_dw = prompt_dw ; 
      }
    }
  }
  while (handler && (((handler ) ) == (scheme_false ) ) ) ; 
  if (handler_argument_error ) {
#   define XfOrM1035_COUNT (0+XfOrM1033_COUNT)
#   define SETUP_XfOrM1035(x) SETUP_XfOrM1033(x)
    if (argc == 1 ) {
#     define XfOrM1037_COUNT (0+XfOrM1035_COUNT)
#     define SETUP_XfOrM1037(x) SETUP_XfOrM1035(x)
      FUNCCALL(SETUP_XfOrM1037(_), scheme_check_proc_arity ("default-continuation-prompt-handler" , 0 , 0 , argc , argv ) ); 
    }
    else {
#     define XfOrM1036_COUNT (0+XfOrM1035_COUNT)
#     define SETUP_XfOrM1036(x) SETUP_XfOrM1035(x)
      FUNCCALL(SETUP_XfOrM1036(_), scheme_wrong_return_arity ("call-with-continuation-prompt" , 1 , argc , argv , "application of default prompt handler" ) ); 
    }
  }
  if (handler ) {
#   define XfOrM1034_COUNT (0+XfOrM1033_COUNT)
#   define SETUP_XfOrM1034(x) SETUP_XfOrM1033(x)
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM1034(_), scheme_tail_apply (handler , argc , argv ) )) RET_VALUE_END ; 
  }
  else RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * propagate_abort (int argc , Scheme_Object * * argv ) {
  Scheme_Object * * argv2 ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv2, 0), PUSH(argv, 1)));
# define XfOrM1103_COUNT (2)
# define SETUP_XfOrM1103(x) SETUP(XfOrM1103_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  argv2 = NULLED_OUT ; 
  argv2 = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM1103(_), GC_malloc (sizeof (Scheme_Object * ) * (argc + 1 ) ) )) ; 
  (memcpy (argv2 XFORM_OK_PLUS 1 , argv , sizeof (Scheme_Object * ) * argc ) ) ; 
  argv2 [0 ] = scheme_default_prompt_tag ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_do_eval (abort_continuation_proc , argc + 1 , argv2 , 1 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_call_with_prompt (Scheme_Closed_Prim f , void * data , int multi , int top_level ) {
  Scheme_Object * prim , * a [3 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(prim, 0), PUSHARRAY(a, 3, 1)));
# define XfOrM1104_COUNT (4)
# define SETUP_XfOrM1104(x) SETUP(XfOrM1104_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  prim = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  a[2] = NULLED_OUT ; 
  prim = FUNCCALL(SETUP_XfOrM1104(_), scheme_make_closed_prim (f , data ) ); 
  a [0 ] = prim ; 
  a [1 ] = scheme_default_prompt_tag ; 
  a [2 ] = FUNCCALL(SETUP_XfOrM1104(_), scheme_make_prim (propagate_abort ) ); 
  if (multi ) {
#   define XfOrM1106_COUNT (0+XfOrM1104_COUNT)
#   define SETUP_XfOrM1106(x) SETUP_XfOrM1104(x)
    if (top_level )
      RET_VALUE_START (FUNCCALL(SETUP_XfOrM1106(_), scheme_apply_multi (call_with_prompt_proc , 3 , a ) )) RET_VALUE_END ; 
    else RET_VALUE_START (FUNCCALL(SETUP_XfOrM1106(_), scheme_do_eval (call_with_prompt_proc , 3 , a , - 1 ) )) RET_VALUE_END ; 
  }
  else {
#   define XfOrM1105_COUNT (0+XfOrM1104_COUNT)
#   define SETUP_XfOrM1105(x) SETUP_XfOrM1104(x)
    if (top_level )
      RET_VALUE_START (FUNCCALL(SETUP_XfOrM1105(_), scheme_apply (call_with_prompt_proc , 3 , a ) )) RET_VALUE_END ; 
    else RET_VALUE_START (FUNCCALL(SETUP_XfOrM1105(_), scheme_do_eval (call_with_prompt_proc , 3 , a , 1 ) )) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_call_with_prompt (Scheme_Closed_Prim f , void * data ) {
  /* No conversion */
  return do_call_with_prompt (f , data , 0 , 1 ) ; 
}
Scheme_Object * scheme_call_with_prompt_multi (Scheme_Closed_Prim f , void * data ) {
  /* No conversion */
  return do_call_with_prompt (f , data , 1 , 1 ) ; 
}
Scheme_Object * _scheme_call_with_prompt (Scheme_Closed_Prim f , void * data ) {
  /* No conversion */
  return do_call_with_prompt (f , data , 0 , 0 ) ; 
}
Scheme_Object * _scheme_call_with_prompt_multi (Scheme_Closed_Prim f , void * data ) {
  /* No conversion */
  return do_call_with_prompt (f , data , 1 , 0 ) ; 
}
/* this far 5977 */
Scheme_Object * scheme_compose_continuation (Scheme_Cont * cont , int num_rands , Scheme_Object * value ) {
  Scheme_Meta_Continuation * mc ; 
  int empty_to_next_mc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(cont, 0), PUSH(value, 1), PUSH(mc, 2)));
# define XfOrM1111_COUNT (3)
# define SETUP_XfOrM1111(x) SETUP(XfOrM1111_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  mc = NULLED_OUT ; 
  if (num_rands != 1 ) {
#   define XfOrM1126_COUNT (0+XfOrM1111_COUNT)
#   define SETUP_XfOrM1126(x) SETUP_XfOrM1111(x)
    value = FUNCCALL(SETUP_XfOrM1126(_), scheme_values (num_rands , (Scheme_Object * * ) value ) ); 
    {
      Scheme_Thread * p = scheme_current_thread ; 
      if (((p -> ku . multiple . array ) == (p -> values_buffer ) ) )
        p -> values_buffer = ((void * ) 0 ) ; 
    }
  }
  cont -> value = value ; 
  cont -> common_dw_depth = - 1 ; 
  mc = scheme_current_thread -> meta_continuation ; 
  if (mc && mc -> pseudo && mc -> meta_tail_pos == scheme_current_cont_mark_pos ) {
    Scheme_Thread * p = scheme_current_thread ; 
    Scheme_Object * cm_info ; 
    long findpos , bottom , pos ; 
    int count , mcount , i ; 
    BLOCK_SETUP((PUSH(cm_info, 0+XfOrM1111_COUNT), PUSH(p, 1+XfOrM1111_COUNT)));
#   define XfOrM1117_COUNT (2+XfOrM1111_COUNT)
#   define SETUP_XfOrM1117(x) SETUP(XfOrM1117_COUNT)
    cm_info = NULLED_OUT ; 
    p -> meta_continuation = mc -> next ; 
    bottom = (long ) p -> cont_mark_stack_bottom ; 
    count = 0 ; 
    for (findpos = (long ) scheme_current_cont_mark_stack - 1 ; findpos >= bottom ; findpos -- ) {
      GC_CAN_IGNORE Scheme_Cont_Mark * seg ; 
      seg = p -> cont_mark_stack_segments [findpos >> 8 ] ; 
      pos = findpos & ((1 << 8 ) - 1 ) ; 
      if (seg [pos ] . pos != scheme_current_cont_mark_pos )
        break ; 
      count ++ ; 
    }
    mcount = 0 ; 
    for (findpos = (long ) mc -> cont_mark_total ; findpos -- ; ) {
      if (mc -> cont_mark_stack_copied [findpos ] . pos != mc -> cont_mark_pos )
        break ; 
      mcount ++ ; 
    }
    cm_info = FUNCCALL(SETUP_XfOrM1117(_), scheme_make_vector ((count + mcount ) * 2 , ((void * ) 0 ) ) ); 
    for (findpos = (long ) scheme_current_cont_mark_stack - 1 , i = 0 ; i < count ; findpos -- , i ++ ) {
      GC_CAN_IGNORE Scheme_Cont_Mark * seg ; 
      seg = p -> cont_mark_stack_segments [findpos >> 8 ] ; 
      pos = findpos & ((1 << 8 ) - 1 ) ; 
      (((Scheme_Vector * ) (cm_info ) ) -> els ) [2 * i ] = seg [pos ] . key ; 
      (((Scheme_Vector * ) (cm_info ) ) -> els ) [(2 * i ) + 1 ] = seg [pos ] . val ; 
    }
    for (findpos = (long ) mc -> cont_mark_total - 1 , i = 0 ; i < mcount ; findpos -- , i ++ ) {
      (((Scheme_Vector * ) (cm_info ) ) -> els ) [2 * (count + i ) ] = mc -> cont_mark_stack_copied [findpos ] . key ; 
      (((Scheme_Vector * ) (cm_info ) ) -> els ) [(2 * (count + i ) ) + 1 ] = mc -> cont_mark_stack_copied [findpos ] . val ; 
    }
    p -> cjs . jumping_to_continuation = cm_info ; 
    p -> cjs . val = (Scheme_Object * ) cont ; 
    p -> cjs . num_vals = 1 ; 
    p -> cjs . is_escape = 1 ; 
    p -> stack_start = mc -> overflow -> stack_start ; 
    FUNCCALL(SETUP_XfOrM1117(_), scheme_longjmpup (& mc -> overflow -> jmp -> cont ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  else if (mc && mc -> meta_tail_pos == scheme_current_cont_mark_pos ) {
    empty_to_next_mc = 1 ; 
  }
  else {
    empty_to_next_mc = 0 ; 
  }
  value = FUNCCALL(SETUP_XfOrM1111(_), compose_continuation (cont , 0 , ((void * ) 0 ) , empty_to_next_mc ) ); 
  scheme_current_thread -> next_meta -= 1 ; 
  if (! value ) {
    Scheme_Thread * p = scheme_current_thread ; 
#   define XfOrM1112_COUNT (0+XfOrM1111_COUNT)
#   define SETUP_XfOrM1112(x) SETUP_XfOrM1111(x)
    if (p -> cjs . is_escape ) {
#     define XfOrM1114_COUNT (0+XfOrM1112_COUNT)
#     define SETUP_XfOrM1114(x) SETUP_XfOrM1112(x)
      FUNCCALL(SETUP_XfOrM1114(_), continue_prompt_escape () ); 
    }
    else {
      (((long * ) (void * ) ((* scheme_current_thread -> error_buf ) . gcvs ) ) [1 ] = (* scheme_current_thread -> error_buf ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* scheme_current_thread -> error_buf ) . gcvs , scheme_jit_longjmp ((* scheme_current_thread -> error_buf ) . jb , 1 ) ) ; 
    }
  }
  RET_VALUE_START (value ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * abort_continuation (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * prompt_tag ; 
  Scheme_Prompt * prompt ; 
  Scheme_Thread * p = scheme_current_thread ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(prompt_tag, 0), PUSH(argv, 1), PUSH(p, 2), PUSH(prompt, 3)));
# define XfOrM1128_COUNT (4)
# define SETUP_XfOrM1128(x) SETUP(XfOrM1128_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  prompt_tag = NULLED_OUT ; 
  prompt = NULLED_OUT ; 
  prompt_tag = argv [0 ] ; 
  if (! ((Scheme_Type ) (scheme_prompt_tag_type ) == (Scheme_Type ) (((((long ) (prompt_tag ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (prompt_tag ) ) -> type ) ) ) ) {
#   define XfOrM1134_COUNT (0+XfOrM1128_COUNT)
#   define SETUP_XfOrM1134(x) SETUP_XfOrM1128(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("abort-current-continuation" , "continuation-prompt-tag" , 0 , argc , argv ) ); 
  }
  prompt = (Scheme_Prompt * ) FUNCCALL(SETUP_XfOrM1128(_), scheme_extract_one_cc_mark (((void * ) 0 ) , (((Scheme_Small_Object * ) (prompt_tag ) ) -> u . ptr_val ) ) ); 
  if (! prompt && ((scheme_default_prompt_tag ) == (prompt_tag ) ) )
    prompt = original_default_prompt ; 
  if (! prompt ) {
#   define XfOrM1133_COUNT (0+XfOrM1128_COUNT)
#   define SETUP_XfOrM1133(x) SETUP_XfOrM1128(x)
    FUNCCALL(SETUP_XfOrM1133(_), scheme_arg_mismatch ("abort-current-continuation" , "continuation includes no prompt with the given tag: " , prompt_tag ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (argc == 2 ) {
    p -> cjs . num_vals = 1 ; 
    p -> cjs . val = argv [1 ] ; 
  }
  else {
    Scheme_Object * * vals ; 
    int i ; 
    BLOCK_SETUP((PUSH(vals, 0+XfOrM1128_COUNT)));
#   define XfOrM1129_COUNT (1+XfOrM1128_COUNT)
#   define SETUP_XfOrM1129(x) SETUP(XfOrM1129_COUNT)
    vals = NULLED_OUT ; 
    vals = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM1129(_), GC_malloc (sizeof (Scheme_Object * ) * (argc - 1 ) ) )) ; 
    for (i = argc ; i -- > 1 ; ) {
      vals [i - 1 ] = argv [i ] ; 
    }
    p -> cjs . num_vals = argc - 1 ; 
    p -> cjs . val = (Scheme_Object * ) vals ; 
  }
  p -> cjs . jumping_to_continuation = (Scheme_Object * ) prompt ; 
  (((long * ) (void * ) ((* p -> error_buf ) . gcvs ) ) [1 ] = (* p -> error_buf ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* p -> error_buf ) . gcvs , scheme_jit_longjmp ((* p -> error_buf ) . jb , 1 ) ) ; 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * call_with_control (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * prompt_tag ; 
  Scheme_Object * a [3 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(prompt_tag, 0), PUSH(argv, 1), PUSHARRAY(a, 3, 2)));
# define XfOrM1135_COUNT (5)
# define SETUP_XfOrM1135(x) SETUP(XfOrM1135_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  prompt_tag = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  a[2] = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM1135(_), scheme_check_proc_arity ("call-with-composable-continuation" , 1 , 0 , argc , argv ) ); 
  if (argc > 1 ) {
#   define XfOrM1136_COUNT (0+XfOrM1135_COUNT)
#   define SETUP_XfOrM1136(x) SETUP_XfOrM1135(x)
    if (! ((Scheme_Type ) (scheme_prompt_tag_type ) == (Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) ) ) {
#     define XfOrM1137_COUNT (0+XfOrM1136_COUNT)
#     define SETUP_XfOrM1137(x) SETUP_XfOrM1136(x)
      FUNCCALL(SETUP_XfOrM1137(_), scheme_wrong_type ("call-with-composable-continuation" , "continuation-prompt-tag" , 1 , argc , argv ) ); 
    }
    prompt_tag = argv [1 ] ; 
  }
  else prompt_tag = scheme_default_prompt_tag ; 
  a [0 ] = argv [0 ] ; 
  a [1 ] = prompt_tag ; 
  a [2 ] = scheme_true ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM1135(_), scheme_tail_apply (internal_call_cc_prim , 3 , a ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 6248 */
/* this far 6248 */
/* this far 6248 */
/* this far 6248 */
static Scheme_Object * continuation_marks (Scheme_Thread * p , Scheme_Object * _cont , Scheme_Object * econt , Scheme_Meta_Continuation * mc , Scheme_Object * prompt_tag , char * who , int just_chain ) {
  Scheme_Cont * cont = (Scheme_Cont * ) _cont , * top_cont ; 
  Scheme_Cont_Mark_Chain * first = ((void * ) 0 ) , * last = ((void * ) 0 ) ; 
  Scheme_Cont_Mark_Set * set ; 
  Scheme_Object * cache , * nt ; 
  long findpos , bottom ; 
  long cmpos , cdelta = 0 ; 
  int found_tag = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(17);
  BLOCK_SETUP_TOP((PUSH(cache, 0), PUSH(econt, 1), PUSH(first, 2), PUSH(cont, 3), PUSH(mc, 4), PUSH(who, 5), PUSH(prompt_tag, 6), PUSH(top_cont, 7), PUSH(nt, 8), PUSH(last, 9), PUSH(set, 10), PUSH(_cont, 11), PUSH(p, 12)));
# define XfOrM1138_COUNT (13)
# define SETUP_XfOrM1138(x) SETUP(XfOrM1138_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  top_cont = NULLED_OUT ; 
  set = NULLED_OUT ; 
  cache = NULLED_OUT ; 
  nt = NULLED_OUT ; 
  if (cont && ((cont -> prompt_tag ) == (prompt_tag ) ) )
    found_tag = 1 ; 
  if (! prompt_tag )
    found_tag = 1 ; 
  do {
#   define XfOrM1207_COUNT (0+XfOrM1138_COUNT)
#   define SETUP_XfOrM1207(x) SETUP_XfOrM1138(x)
    if (econt ) {
      findpos = (long ) ((Scheme_Escaping_Cont * ) econt ) -> envss . cont_mark_stack ; 
      cmpos = (long ) ((Scheme_Escaping_Cont * ) econt ) -> envss . cont_mark_pos ; 
      if (mc ) {
        cdelta = mc -> cont_mark_offset ; 
        bottom = 0 ; 
      }
      else bottom = p -> cont_mark_stack_bottom ; 
    }
    else if (cont ) {
      findpos = (long ) cont -> ss . cont_mark_stack ; 
      cmpos = (long ) cont -> ss . cont_mark_pos ; 
      cdelta = cont -> cont_mark_offset ; 
      bottom = 0 ; 
    }
    else if (mc ) {
      findpos = (long ) mc -> cont_mark_stack ; 
      cmpos = (long ) mc -> cont_mark_pos ; 
      cdelta = mc -> cont_mark_offset ; 
      bottom = 0 ; 
    }
    else {
      findpos = (long ) scheme_current_cont_mark_stack ; 
      cmpos = (long ) scheme_current_cont_mark_pos ; 
      if (! p -> cont_mark_stack_segments )
        findpos = 0 ; 
      bottom = p -> cont_mark_stack_bottom ; 
    }
    top_cont = cont ; 
    while (findpos -- > bottom ) {
      Scheme_Cont_Mark * find ; 
      long pos ; 
      BLOCK_SETUP((PUSH(find, 0+XfOrM1207_COUNT)));
#     define XfOrM1239_COUNT (1+XfOrM1207_COUNT)
#     define SETUP_XfOrM1239(x) SETUP(XfOrM1239_COUNT)
      find = NULLED_OUT ; 
      if (cont ) {
        while (findpos < cdelta ) {
          if (! cont -> runstack_copied ) {
            cont = cont -> buf . cont ; 
          }
          cont = cont -> buf . cont ; 
          if (cont )
            cdelta = cont -> cont_mark_offset ; 
          else break ; 
        }
        if (! cont )
          break ; 
        find = cont -> cont_mark_stack_copied ; 
        pos = findpos - cdelta ; 
      }
      else if (mc ) {
        if (findpos < cdelta )
          break ; 
        find = mc -> cont_mark_stack_copied ; 
        pos = findpos - cdelta ; 
      }
      else {
        GC_CAN_IGNORE Scheme_Cont_Mark * seg ; 
        seg = p -> cont_mark_stack_segments [findpos >> 8 ] ; 
        pos = findpos & ((1 << 8 ) - 1 ) ; 
        find = seg ; 
      }
      if (prompt_tag && (find [pos ] . key == (((Scheme_Small_Object * ) (prompt_tag ) ) -> u . ptr_val ) ) ) {
        found_tag = 1 ; 
        mc = ((void * ) 0 ) ; 
        p = ((void * ) 0 ) ; 
        econt = ((void * ) 0 ) ; 
        cont = ((void * ) 0 ) ; 
        break ; 
      }
      cache = find [pos ] . cache ; 
      if (cache ) {
#       define XfOrM1255_COUNT (0+XfOrM1239_COUNT)
#       define SETUP_XfOrM1255(x) SETUP_XfOrM1239(x)
        if ((((cache ) ) == (scheme_false ) ) )
          cache = ((void * ) 0 ) ; 
        if (cache ) {
#         define XfOrM1257_COUNT (0+XfOrM1255_COUNT)
#         define SETUP_XfOrM1257(x) SETUP_XfOrM1255(x)
          if (((Scheme_Type ) (((((long ) (cache ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (cache ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) )
            cache = FUNCCALL(SETUP_XfOrM1257(_), scheme_hash_get ((Scheme_Hash_Table * ) cache , prompt_tag ? prompt_tag : scheme_false ) ); 
          else if (prompt_tag != scheme_default_prompt_tag )
            cache = ((void * ) 0 ) ; 
        }
        if (cache && ((Scheme_Type ) (((((long ) (cache ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (cache ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
          cache = (((Scheme_Vector * ) (cache ) ) -> els ) [0 ] ; 
        }
      }
      if (cache ) {
        if (((Scheme_Cont_Mark_Chain * ) cache ) -> key ) {
          if (last )
            last -> next = (Scheme_Cont_Mark_Chain * ) cache ; 
          else first = (Scheme_Cont_Mark_Chain * ) cache ; 
          found_tag = 1 ; 
        }
        else {
        }
        mc = ((void * ) 0 ) ; 
        p = ((void * ) 0 ) ; 
        econt = ((void * ) 0 ) ; 
        cont = ((void * ) 0 ) ; 
        break ; 
      }
      else {
        Scheme_Cont_Mark_Chain * pr ; 
        BLOCK_SETUP((PUSH(pr, 0+XfOrM1239_COUNT)));
#       define XfOrM1240_COUNT (1+XfOrM1239_COUNT)
#       define SETUP_XfOrM1240(x) SETUP(XfOrM1240_COUNT)
        pr = NULLED_OUT ; 
        pr = ((Scheme_Cont_Mark_Chain * ) FUNCCALL(SETUP_XfOrM1240(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Cont_Mark_Chain ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
        pr -> so . type = scheme_cont_mark_chain_type ; 
        pr -> key = find [pos ] . key ; 
        pr -> val = find [pos ] . val ; 
        pr -> pos = find [pos ] . pos ; 
        pr -> next = ((void * ) 0 ) ; 
        if (mc ) {
#         define XfOrM1250_COUNT (0+XfOrM1240_COUNT)
#         define SETUP_XfOrM1250(x) SETUP_XfOrM1240(x)
          if (mc -> cm_shared ) {
            Scheme_Cont_Mark * cp ; 
            BLOCK_SETUP((PUSH(cp, 0+XfOrM1250_COUNT)));
#           define XfOrM1251_COUNT (1+XfOrM1250_COUNT)
#           define SETUP_XfOrM1251(x) SETUP(XfOrM1251_COUNT)
            cp = NULLED_OUT ; 
            cp = ((Scheme_Cont_Mark * ) FUNCCALL(SETUP_XfOrM1251(_), GC_malloc (sizeof (Scheme_Cont_Mark ) * (mc -> cont_mark_total ) ) )) ; 
            (memcpy (cp , mc -> cont_mark_stack_copied , mc -> cont_mark_total * sizeof (Scheme_Cont_Mark ) ) ) ; 
            mc -> cont_mark_stack_copied = cp ; 
            find = cp ; 
            mc -> cm_shared = 0 ; 
          }
          mc -> cm_caches = 1 ; 
        }
        cache = find [pos ] . cache ; 
        if (cache && ! (((cache ) ) == (scheme_false ) ) ) {
#         define XfOrM1243_COUNT (0+XfOrM1240_COUNT)
#         define SETUP_XfOrM1243(x) SETUP_XfOrM1240(x)
          if (((Scheme_Type ) (((((long ) (cache ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (cache ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) ) {
            Scheme_Hash_Table * ht = (Scheme_Hash_Table * ) cache ; 
            BLOCK_SETUP((PUSH(ht, 0+XfOrM1243_COUNT)));
#           define XfOrM1247_COUNT (1+XfOrM1243_COUNT)
#           define SETUP_XfOrM1247(x) SETUP(XfOrM1247_COUNT)
            cache = FUNCCALL(SETUP_XfOrM1247(_), scheme_hash_get (ht , prompt_tag ? prompt_tag : scheme_false ) ); 
            if (! cache ) {
#             define XfOrM1249_COUNT (0+XfOrM1247_COUNT)
#             define SETUP_XfOrM1249(x) SETUP_XfOrM1247(x)
              FUNCCALL(SETUP_XfOrM1249(_), scheme_hash_set (ht , prompt_tag ? prompt_tag : scheme_false , (Scheme_Object * ) pr ) ); 
            }
            else {
              (((Scheme_Vector * ) (cache ) ) -> els ) [0 ] = (Scheme_Object * ) pr ; 
            }
          }
          else if (! ((Scheme_Type ) (((((long ) (cache ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (cache ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
            Scheme_Hash_Table * ht ; 
            BLOCK_SETUP((PUSH(ht, 0+XfOrM1243_COUNT)));
#           define XfOrM1246_COUNT (1+XfOrM1243_COUNT)
#           define SETUP_XfOrM1246(x) SETUP(XfOrM1246_COUNT)
            ht = NULLED_OUT ; 
            ht = FUNCCALL(SETUP_XfOrM1246(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
            FUNCCALL_AGAIN(scheme_hash_set (ht , scheme_default_prompt_tag , cache ) ); 
            FUNCCALL_AGAIN(scheme_hash_set (ht , prompt_tag ? prompt_tag : scheme_false , (Scheme_Object * ) pr ) ); 
            find [pos ] . cache = (Scheme_Object * ) ht ; 
          }
          else {
#           define XfOrM1244_COUNT (0+XfOrM1243_COUNT)
#           define SETUP_XfOrM1244(x) SETUP_XfOrM1243(x)
            if (prompt_tag == scheme_default_prompt_tag )
              (((Scheme_Vector * ) (cache ) ) -> els ) [0 ] = (Scheme_Object * ) pr ; 
            else {
              Scheme_Hash_Table * ht ; 
              Scheme_Object * vec ; 
              BLOCK_SETUP((PUSH(ht, 0+XfOrM1244_COUNT), PUSH(vec, 1+XfOrM1244_COUNT)));
#             define XfOrM1245_COUNT (2+XfOrM1244_COUNT)
#             define SETUP_XfOrM1245(x) SETUP(XfOrM1245_COUNT)
              ht = NULLED_OUT ; 
              vec = NULLED_OUT ; 
              ht = FUNCCALL(SETUP_XfOrM1245(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
              vec = FUNCCALL_AGAIN(scheme_make_vector (4 , ((void * ) 0 ) ) ); 
              (((Scheme_Vector * ) (vec ) ) -> els ) [1 ] = (((Scheme_Vector * ) (cache ) ) -> els ) [1 ] ; 
              (((Scheme_Vector * ) (vec ) ) -> els ) [2 ] = (((Scheme_Vector * ) (cache ) ) -> els ) [2 ] ; 
              (((Scheme_Vector * ) (vec ) ) -> els ) [3 ] = (((Scheme_Vector * ) (cache ) ) -> els ) [3 ] ; 
              FUNCCALL(SETUP_XfOrM1245(_), scheme_hash_set (ht , scheme_false , vec ) ); 
              if (! prompt_tag )
                (((Scheme_Vector * ) (vec ) ) -> els ) [0 ] = (Scheme_Object * ) pr ; 
              else FUNCCALL(SETUP_XfOrM1245(_), scheme_hash_set (ht , prompt_tag , (Scheme_Object * ) pr ) ); 
              find [pos ] . cache = (Scheme_Object * ) ht ; 
            }
          }
        }
        else if (prompt_tag == scheme_default_prompt_tag ) {
          find [pos ] . cache = (Scheme_Object * ) pr ; 
        }
        else {
#         define XfOrM1241_COUNT (0+XfOrM1240_COUNT)
#         define SETUP_XfOrM1241(x) SETUP_XfOrM1240(x)
          cache = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM1241(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
          FUNCCALL(SETUP_XfOrM1241(_), scheme_hash_set ((Scheme_Hash_Table * ) cache , prompt_tag ? prompt_tag : scheme_false , (Scheme_Object * ) pr ) ); 
          find [pos ] . cache = cache ; 
        }
        if (last )
          last -> next = pr ; 
        else first = pr ; 
        last = pr ; 
      }
    }
    if (mc ) {
      mc = mc -> next ; 
    }
    else if (top_cont ) {
      mc = top_cont -> meta_continuation ; 
    }
    else if (econt ) {
      mc = p -> meta_continuation ; 
    }
    else if (p ) {
      mc = p -> meta_continuation ; 
    }
    cont = ((void * ) 0 ) ; 
    econt = ((void * ) 0 ) ; 
    p = ((void * ) 0 ) ; 
  }
  while (mc ) ; 
  if (! found_tag ) {
#   define XfOrM1139_COUNT (0+XfOrM1138_COUNT)
#   define SETUP_XfOrM1139(x) SETUP_XfOrM1138(x)
    if (! ((prompt_tag ) == (scheme_default_prompt_tag ) ) ) {
#     define XfOrM1140_COUNT (0+XfOrM1139_COUNT)
#     define SETUP_XfOrM1140(x) SETUP_XfOrM1139(x)
      while (first ) {
        first -> key = ((void * ) 0 ) ; 
        first = first -> next ; 
      }
      if (! who )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      FUNCCALL(SETUP_XfOrM1140(_), scheme_arg_mismatch (who , "no corresponding prompt in the continuation: " , prompt_tag ) ); 
    }
  }
  if (just_chain )
    RET_VALUE_START ((Scheme_Object * ) first ) RET_VALUE_END ; 
  if (_cont )
    nt = ((Scheme_Cont * ) _cont ) -> native_trace ; 
  else if (econt )
    nt = ((Scheme_Escaping_Cont * ) econt ) -> native_trace ; 
  else nt = FUNCCALL(SETUP_XfOrM1138(_), scheme_native_stack_trace () ); 
  set = ((Scheme_Cont_Mark_Set * ) FUNCCALL(SETUP_XfOrM1138(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Cont_Mark_Set ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  set -> so . type = scheme_cont_mark_set_type ; 
  set -> chain = first ; 
  set -> cmpos = cmpos ; 
  set -> native_stack_trace = nt ; 
  RET_VALUE_START ((Scheme_Object * ) set ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_current_continuation_marks (Scheme_Object * prompt_tag ) {
  /* No conversion */
  return continuation_marks (scheme_current_thread , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , prompt_tag ? prompt_tag : scheme_default_prompt_tag , "continuation-marks" , 0 ) ; 
}
Scheme_Object * scheme_all_current_continuation_marks () {
  /* No conversion */
  return continuation_marks (scheme_current_thread , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , "continuation-marks" , 0 ) ; 
}
static Scheme_Object * cc_marks (int argc , Scheme_Object * argv [] ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM1273_COUNT (1)
# define SETUP_XfOrM1273(x) SETUP(XfOrM1273_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (argc ) {
#   define XfOrM1274_COUNT (0+XfOrM1273_COUNT)
#   define SETUP_XfOrM1274(x) SETUP_XfOrM1273(x)
    if (! ((Scheme_Type ) (scheme_prompt_tag_type ) == (Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) ) ) {
#     define XfOrM1275_COUNT (0+XfOrM1274_COUNT)
#     define SETUP_XfOrM1275(x) SETUP_XfOrM1274(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("current-continuation-marks" , "continuation-prompt-tag" , 0 , argc , argv ) ); 
    }
    if (! ((scheme_default_prompt_tag ) == (argv [0 ] ) ) )
      if (! FUNCCALL(SETUP_XfOrM1274(_), scheme_extract_one_cc_mark (((void * ) 0 ) , (((Scheme_Small_Object * ) (argv [0 ] ) ) -> u . ptr_val ) ) ))
      FUNCCALL(SETUP_XfOrM1274(_), scheme_arg_mismatch ("current-continuation-marks" , "no corresponding prompt in the continuation: " , argv [0 ] ) ); 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_current_continuation_marks (argc ? argv [0 ] : ((void * ) 0 ) ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * cont_marks (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * prompt_tag ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(prompt_tag, 0), PUSH(argv, 1)));
# define XfOrM1276_COUNT (2)
# define SETUP_XfOrM1276(x) SETUP(XfOrM1276_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  prompt_tag = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cont_type ) ) && ! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_escaping_cont_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("continuation-marks" , "continuation" , 0 , argc , argv ) ); 
  if (argc > 1 ) {
#   define XfOrM1281_COUNT (0+XfOrM1276_COUNT)
#   define SETUP_XfOrM1281(x) SETUP_XfOrM1276(x)
    if (! ((Scheme_Type ) (scheme_prompt_tag_type ) == (Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) ) ) {
#     define XfOrM1282_COUNT (0+XfOrM1281_COUNT)
#     define SETUP_XfOrM1282(x) SETUP_XfOrM1281(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("continuation-marks" , "continuation-prompt-tag" , 1 , argc , argv ) ); 
    }
    prompt_tag = argv [1 ] ; 
  }
  else prompt_tag = scheme_default_prompt_tag ; 
  if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_escaping_cont_type ) ) ) {
#   define XfOrM1278_COUNT (0+XfOrM1276_COUNT)
#   define SETUP_XfOrM1278(x) SETUP_XfOrM1276(x)
    if (! FUNCCALL(SETUP_XfOrM1278(_), scheme_escape_continuation_ok (argv [0 ] ) )) {
#     define XfOrM1280_COUNT (0+XfOrM1278_COUNT)
#     define SETUP_XfOrM1280(x) SETUP_XfOrM1278(x)
      FUNCCALL(SETUP_XfOrM1280(_), scheme_arg_mismatch ("continuation-marks" , "escape continuation not in the current thread's continuation: " , argv [0 ] ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else {
      Scheme_Meta_Continuation * mc ; 
      BLOCK_SETUP((PUSH(mc, 0+XfOrM1278_COUNT)));
#     define XfOrM1279_COUNT (1+XfOrM1278_COUNT)
#     define SETUP_XfOrM1279(x) SETUP(XfOrM1279_COUNT)
      mc = NULLED_OUT ; 
      FUNCCALL(SETUP_XfOrM1279(_), scheme_extract_one_cc_mark_with_meta (((void * ) 0 ) , argv [0 ] , ((void * ) 0 ) , & mc , ((void * ) 0 ) ) ); 
      RET_VALUE_START (FUNCCALL(SETUP_XfOrM1279(_), continuation_marks (scheme_current_thread , ((void * ) 0 ) , argv [0 ] , mc , prompt_tag , "continuation-marks" , 0 ) )) RET_VALUE_END ; 
    }
  }
  else {
#   define XfOrM1277_COUNT (0+XfOrM1276_COUNT)
#   define SETUP_XfOrM1277(x) SETUP_XfOrM1276(x)
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(continuation_marks (((void * ) 0 ) , argv [0 ] , ((void * ) 0 ) , ((void * ) 0 ) , prompt_tag , "continuation-marks" , 0 ) )) RET_VALUE_EMPTY_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * cc_marks_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cont_mark_set_type ) ) )
    return scheme_false ; 
  else return scheme_true ; 
}
static Scheme_Object * extract_cc_marks (int argc , Scheme_Object * argv [] ) {
  Scheme_Cont_Mark_Chain * chain ; 
  Scheme_Object * first = scheme_null , * last = ((void * ) 0 ) , * key , * prompt_tag ; 
  Scheme_Object * pr ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(prompt_tag, 0), PUSH(pr, 1), PUSH(first, 2), PUSH(chain, 3), PUSH(key, 4), PUSH(last, 5)));
# define XfOrM1284_COUNT (6)
# define SETUP_XfOrM1284(x) SETUP(XfOrM1284_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  chain = NULLED_OUT ; 
  key = NULLED_OUT ; 
  prompt_tag = NULLED_OUT ; 
  pr = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cont_mark_set_type ) ) ) {
#   define XfOrM1292_COUNT (0+XfOrM1284_COUNT)
#   define SETUP_XfOrM1292(x) SETUP_XfOrM1284(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("continuation-mark-set->list" , "continuation-mark-set" , 0 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (argc > 2 ) {
#   define XfOrM1290_COUNT (0+XfOrM1284_COUNT)
#   define SETUP_XfOrM1290(x) SETUP_XfOrM1284(x)
    if (! ((Scheme_Type ) (scheme_prompt_tag_type ) == (Scheme_Type ) (((((long ) (argv [2 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [2 ] ) ) -> type ) ) ) ) {
#     define XfOrM1291_COUNT (0+XfOrM1290_COUNT)
#     define SETUP_XfOrM1291(x) SETUP_XfOrM1290(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("continuation-mark-set->list" , "continuation-prompt-tag" , 2 , argc , argv ) ); 
    }
    prompt_tag = argv [2 ] ; 
  }
  else prompt_tag = scheme_default_prompt_tag ; 
  chain = ((Scheme_Cont_Mark_Set * ) argv [0 ] ) -> chain ; 
  key = argv [1 ] ; 
  if ((key == scheme_parameterization_key ) || (key == scheme_break_enabled_key ) || (key == scheme_exn_handler_key ) ) {
#   define XfOrM1289_COUNT (0+XfOrM1284_COUNT)
#   define SETUP_XfOrM1289(x) SETUP_XfOrM1284(x)
    FUNCCALL_EMPTY(scheme_signal_error ("continuation-mark-set->list: secret key leaked!" ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  prompt_tag = (((Scheme_Small_Object * ) (prompt_tag ) ) -> u . ptr_val ) ; 
  while (chain ) {
#   define XfOrM1287_COUNT (0+XfOrM1284_COUNT)
#   define SETUP_XfOrM1287(x) SETUP_XfOrM1284(x)
    if (chain -> key == key ) {
#     define XfOrM1288_COUNT (0+XfOrM1287_COUNT)
#     define SETUP_XfOrM1288(x) SETUP_XfOrM1287(x)
      pr = FUNCCALL(SETUP_XfOrM1288(_), scheme_make_pair (chain -> val , scheme_null ) ); 
      if (last )
        (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = pr ; 
      else first = pr ; 
      last = pr ; 
    }
    else if (chain -> key == prompt_tag )
      break ; 
    chain = chain -> next ; 
  }
  RET_VALUE_START (first ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * extract_cc_markses (int argc , Scheme_Object * argv [] ) {
  Scheme_Cont_Mark_Chain * chain ; 
  Scheme_Object * first = scheme_null , * last = ((void * ) 0 ) ; 
  Scheme_Object * pr , * * keys , * vals , * none , * prompt_tag ; 
  int len , i ; 
  long last_pos ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(9);
  BLOCK_SETUP_TOP((PUSH(first, 0), PUSH(prompt_tag, 1), PUSH(none, 2), PUSH(argv, 3), PUSH(keys, 4), PUSH(last, 5), PUSH(vals, 6), PUSH(pr, 7), PUSH(chain, 8)));
# define XfOrM1293_COUNT (9)
# define SETUP_XfOrM1293(x) SETUP(XfOrM1293_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  chain = NULLED_OUT ; 
  pr = NULLED_OUT ; 
  keys = NULLED_OUT ; 
  vals = NULLED_OUT ; 
  none = NULLED_OUT ; 
  prompt_tag = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cont_mark_set_type ) ) ) {
#   define XfOrM1315_COUNT (0+XfOrM1293_COUNT)
#   define SETUP_XfOrM1315(x) SETUP_XfOrM1293(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("continuation-mark-set->list*" , "continuation-mark-set" , 0 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  len = FUNCCALL(SETUP_XfOrM1293(_), scheme_proper_list_length (argv [1 ] ) ); 
  if (len < 0 ) {
#   define XfOrM1314_COUNT (0+XfOrM1293_COUNT)
#   define SETUP_XfOrM1314(x) SETUP_XfOrM1293(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("continuation-mark-set->list*" , "list" , 1 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (argc > 2 )
    none = argv [2 ] ; 
  else none = scheme_false ; 
  if (argc > 3 ) {
#   define XfOrM1312_COUNT (0+XfOrM1293_COUNT)
#   define SETUP_XfOrM1312(x) SETUP_XfOrM1293(x)
    if (! ((Scheme_Type ) (scheme_prompt_tag_type ) == (Scheme_Type ) (((((long ) (argv [3 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [3 ] ) ) -> type ) ) ) ) {
#     define XfOrM1313_COUNT (0+XfOrM1312_COUNT)
#     define SETUP_XfOrM1313(x) SETUP_XfOrM1312(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("continuation-mark-set->list*" , "continuation-prompt-tag" , 3 , argc , argv ) ); 
    }
    prompt_tag = argv [3 ] ; 
  }
  else prompt_tag = scheme_default_prompt_tag ; 
  keys = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM1293(_), GC_malloc (sizeof (Scheme_Object * ) * (len ) ) )) ; 
  for (pr = argv [1 ] , i = 0 ; ((Scheme_Type ) (((((long ) (pr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (pr ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; pr = (((Scheme_Simple_Object * ) (pr ) ) -> u . pair_val . cdr ) , i ++ ) {
#   define XfOrM1310_COUNT (0+XfOrM1293_COUNT)
#   define SETUP_XfOrM1310(x) SETUP_XfOrM1293(x)
    keys [i ] = (((Scheme_Simple_Object * ) (pr ) ) -> u . pair_val . car ) ; 
    if ((keys [i ] == scheme_parameterization_key ) || (keys [i ] == scheme_break_enabled_key ) || (keys [i ] == scheme_exn_handler_key ) ) {
#     define XfOrM1311_COUNT (0+XfOrM1310_COUNT)
#     define SETUP_XfOrM1311(x) SETUP_XfOrM1310(x)
      FUNCCALL_EMPTY(scheme_signal_error ("continuation-mark-set->list: secret key leaked!" ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  prompt_tag = (((Scheme_Small_Object * ) (prompt_tag ) ) -> u . ptr_val ) ; 
  chain = ((Scheme_Cont_Mark_Set * ) argv [0 ] ) -> chain ; 
  last_pos = ((Scheme_Cont_Mark_Set * ) argv [0 ] ) -> cmpos + 2 ; 
  while (chain ) {
#   define XfOrM1301_COUNT (0+XfOrM1293_COUNT)
#   define SETUP_XfOrM1301(x) SETUP_XfOrM1293(x)
    for (i = 0 ; i < len ; i ++ ) {
#     define XfOrM1305_COUNT (0+XfOrM1301_COUNT)
#     define SETUP_XfOrM1305(x) SETUP_XfOrM1301(x)
      if (((chain -> key ) == (keys [i ] ) ) ) {
        long pos ; 
#       define XfOrM1306_COUNT (0+XfOrM1305_COUNT)
#       define SETUP_XfOrM1306(x) SETUP_XfOrM1305(x)
        pos = (long ) chain -> pos ; 
        if (pos != last_pos ) {
#         define XfOrM1307_COUNT (0+XfOrM1306_COUNT)
#         define SETUP_XfOrM1307(x) SETUP_XfOrM1306(x)
          vals = FUNCCALL(SETUP_XfOrM1307(_), scheme_make_vector (len , none ) ); 
          last_pos = pos ; 
          pr = FUNCCALL(SETUP_XfOrM1307(_), scheme_make_pair (vals , scheme_null ) ); 
          if (last )
            (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = pr ; 
          else first = pr ; 
          last = pr ; 
        }
        else vals = (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . car ) ; 
        (((Scheme_Vector * ) (vals ) ) -> els ) [i ] = chain -> val ; 
      }
    }
    if (((chain -> key ) == (prompt_tag ) ) )
      break ; 
    chain = chain -> next ; 
  }
  RET_VALUE_START (first ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_get_stack_trace (Scheme_Object * mark_set ) {
  Scheme_Object * l , * n , * m , * name , * loc ; 
  Scheme_Object * a [2 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(10);
  BLOCK_SETUP_TOP((PUSH(n, 0), PUSH(name, 1), PUSH(loc, 2), PUSHARRAY(a, 2, 3), PUSH(l, 6), PUSH(m, 7)));
# define XfOrM1316_COUNT (8)
# define SETUP_XfOrM1316(x) SETUP(XfOrM1316_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  l = NULLED_OUT ; 
  n = NULLED_OUT ; 
  m = NULLED_OUT ; 
  name = NULLED_OUT ; 
  loc = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  l = ((Scheme_Cont_Mark_Set * ) mark_set ) -> native_stack_trace ; 
  if (! l ) {
#   define XfOrM1334_COUNT (0+XfOrM1316_COUNT)
#   define SETUP_XfOrM1334(x) SETUP_XfOrM1316(x)
    a [0 ] = mark_set ; 
    a [1 ] = scheme_stack_dump_key ; 
    l = FUNCCALL(SETUP_XfOrM1334(_), extract_cc_marks (2 , a ) ); 
  }
  else {
    Scheme_Object * first = scheme_null , * last = ((void * ) 0 ) ; 
    BLOCK_SETUP((PUSH(first, 0+XfOrM1316_COUNT), PUSH(last, 1+XfOrM1316_COUNT)));
#   define XfOrM1331_COUNT (2+XfOrM1316_COUNT)
#   define SETUP_XfOrM1331(x) SETUP(XfOrM1331_COUNT)
    while (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#     define XfOrM1333_COUNT (0+XfOrM1331_COUNT)
#     define SETUP_XfOrM1333(x) SETUP_XfOrM1331(x)
      n = FUNCCALL(SETUP_XfOrM1333(_), scheme_make_pair ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) , scheme_null ) ); 
      if (last )
        (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = n ; 
      else first = n ; 
      last = n ; 
      l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
    }
    l = first ; 
  }
  while (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ! (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ) {
    l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
  }
  for (n = l ; ((Scheme_Type ) (((((long ) (n ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; ) {
    m = (((Scheme_Simple_Object * ) (n ) ) -> u . pair_val . cdr ) ; 
    if (((m ) == (scheme_null ) ) )
      break ; 
    if ((((Scheme_Simple_Object * ) (m ) ) -> u . pair_val . car ) ) {
      n = m ; 
    }
    else {
      (((Scheme_Simple_Object * ) (n ) ) -> u . pair_val . cdr ) = (((Scheme_Simple_Object * ) (m ) ) -> u . pair_val . cdr ) ; 
    }
  }
  for (n = l ; ((Scheme_Type ) (((((long ) (n ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; n = (((Scheme_Simple_Object * ) (n ) ) -> u . pair_val . cdr ) ) {
#   define XfOrM1320_COUNT (0+XfOrM1316_COUNT)
#   define SETUP_XfOrM1320(x) SETUP_XfOrM1316(x)
    name = (((Scheme_Simple_Object * ) (n ) ) -> u . pair_val . car ) ; 
    if (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
#     define XfOrM1322_COUNT (0+XfOrM1320_COUNT)
#     define SETUP_XfOrM1322(x) SETUP_XfOrM1320(x)
      loc = FUNCCALL(SETUP_XfOrM1322(_), scheme_make_location ((((Scheme_Vector * ) (name ) ) -> els ) [1 ] , (((Scheme_Vector * ) (name ) ) -> els ) [2 ] , (((Scheme_Vector * ) (name ) ) -> els ) [3 ] , (((Scheme_Vector * ) (name ) ) -> els ) [4 ] , (((Scheme_Vector * ) (name ) ) -> els ) [5 ] ) ); 
      if ((! ((((((Scheme_Vector * ) (name ) ) -> els ) [6 ] ) ) == (scheme_false ) ) ) )
        name = FUNCCALL(SETUP_XfOrM1322(_), scheme_make_pair (scheme_false , loc ) ); 
      else name = FUNCCALL(SETUP_XfOrM1322(_), scheme_make_pair ((((Scheme_Vector * ) (name ) ) -> els ) [0 ] , loc ) ); 
    }
    else {
#     define XfOrM1321_COUNT (0+XfOrM1320_COUNT)
#     define SETUP_XfOrM1321(x) SETUP_XfOrM1320(x)
      name = FUNCCALL(SETUP_XfOrM1321(_), scheme_make_pair (name , scheme_false ) ); 
    }
    (((Scheme_Simple_Object * ) (n ) ) -> u . pair_val . car ) = name ; 
  }
  RET_VALUE_START (l ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * extract_cc_proc_marks (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cont_mark_set_type ) ) ) {
    scheme_wrong_type ("continuation-mark-set->context" , "continuation-mark-set" , 0 , argc , argv ) ; 
    return ((void * ) 0 ) ; 
  }
  return scheme_get_stack_trace (argv [0 ] ) ; 
}
Scheme_Object * scheme_extract_one_cc_mark_with_meta (Scheme_Object * mark_set , Scheme_Object * key , Scheme_Object * prompt_tag , Scheme_Meta_Continuation * * _meta , long * _vpos ) {
  Scheme_Object * __funcarg81 = NULLED_OUT ; 
  Scheme_Object * __funcarg80 = NULLED_OUT ; 
  Scheme_Object * __funcarg79 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(11);
  BLOCK_SETUP_TOP((PUSH(prompt_tag, 0), PUSH(_meta, 1), PUSH(key, 2), PUSH(_vpos, 3)));
# define XfOrM1337_COUNT (4)
# define SETUP_XfOrM1337(x) SETUP(XfOrM1337_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (mark_set ) {
    Scheme_Cont_Mark_Chain * chain ; 
    chain = NULLED_OUT ; 
    chain = ((Scheme_Cont_Mark_Set * ) mark_set ) -> chain ; 
    while (chain ) {
      if (chain -> key == key )
        RET_VALUE_START (chain -> val ) RET_VALUE_END ; 
      else chain = chain -> next ; 
    }
  }
  else {
    long findpos , bottom , startpos ; 
    long pos ; 
    Scheme_Object * val = ((void * ) 0 ) ; 
    long vpos = 0 ; 
    Scheme_Object * cache ; 
    Scheme_Meta_Continuation * mc = ((void * ) 0 ) ; 
    Scheme_Cont_Mark * seg ; 
    Scheme_Thread * p = scheme_current_thread ; 
    BLOCK_SETUP((PUSH(val, 0+XfOrM1337_COUNT), PUSH(seg, 1+XfOrM1337_COUNT), PUSH(cache, 2+XfOrM1337_COUNT), PUSH(mc, 3+XfOrM1337_COUNT), PUSH(p, 4+XfOrM1337_COUNT)));
#   define XfOrM1340_COUNT (5+XfOrM1337_COUNT)
#   define SETUP_XfOrM1340(x) SETUP(XfOrM1340_COUNT)
    cache = NULLED_OUT ; 
    seg = NULLED_OUT ; 
    do {
#     define XfOrM1382_COUNT (0+XfOrM1340_COUNT)
#     define SETUP_XfOrM1382(x) SETUP_XfOrM1340(x)
      if (mc ) {
        startpos = mc -> cont_mark_total ; 
        bottom = 0 ; 
      }
      else {
        startpos = (long ) scheme_current_cont_mark_stack ; 
        if (! p -> cont_mark_stack_segments )
          findpos = 0 ; 
        bottom = p -> cont_mark_stack_bottom ; 
      }
      findpos = startpos ; 
      while (findpos -- > bottom ) {
#       define XfOrM1411_COUNT (0+XfOrM1382_COUNT)
#       define SETUP_XfOrM1411(x) SETUP_XfOrM1382(x)
        if (mc ) {
          seg = mc -> cont_mark_stack_copied ; 
          pos = findpos ; 
        }
        else {
          seg = p -> cont_mark_stack_segments [findpos >> 8 ] ; 
          pos = findpos & ((1 << 8 ) - 1 ) ; 
        }
        if (((seg [pos ] . key ) == (key ) ) ) {
          val = seg [pos ] . val ; 
          vpos = seg [pos ] . pos ; 
          break ; 
        }
        else {
#         define XfOrM1412_COUNT (0+XfOrM1411_COUNT)
#         define SETUP_XfOrM1412(x) SETUP_XfOrM1411(x)
          cache = seg [pos ] . cache ; 
          if (cache && ((Scheme_Type ) (((((long ) (cache ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (cache ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) )
            cache = FUNCCALL(SETUP_XfOrM1412(_), scheme_hash_get ((Scheme_Hash_Table * ) cache , prompt_tag ? prompt_tag : scheme_false ) ); 
          else if (prompt_tag )
            cache = ((void * ) 0 ) ; 
          if (cache && ((Scheme_Type ) (((((long ) (cache ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (cache ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
#           define XfOrM1413_COUNT (0+XfOrM1412_COUNT)
#           define SETUP_XfOrM1413(x) SETUP_XfOrM1412(x)
            if ((((Scheme_Vector * ) (cache ) ) -> els ) [1 ] ) {
              if ((((((Scheme_Vector * ) (cache ) ) -> els ) [1 ] ) == (key ) ) ) {
                val = (((Scheme_Vector * ) (cache ) ) -> els ) [2 ] ; 
                vpos = (long ) (((Scheme_Vector * ) (cache ) ) -> els ) [3 ] ; 
                break ; 
              }
            }
            else {
              Scheme_Hash_Table * ht ; 
#             define XfOrM1414_COUNT (0+XfOrM1413_COUNT)
#             define SETUP_XfOrM1414(x) SETUP_XfOrM1413(x)
              ht = NULLED_OUT ; 
              ht = (Scheme_Hash_Table * ) (((Scheme_Vector * ) (cache ) ) -> els ) [2 ] ; 
              val = FUNCCALL(SETUP_XfOrM1414(_), scheme_hash_get (ht , key ) ); 
              if (val ) {
                vpos = (long ) (((Scheme_Simple_Object * ) (val ) ) -> u . pair_val . cdr ) ; 
                val = (((Scheme_Simple_Object * ) (val ) ) -> u . pair_val . car ) ; 
                break ; 
              }
            }
          }
        }
      }
      pos = startpos - findpos ; 
      if (pos > 16 ) {
        pos >>= 1 ; 
#       define XfOrM1386_COUNT (0+XfOrM1382_COUNT)
#       define SETUP_XfOrM1386(x) SETUP_XfOrM1382(x)
        findpos = findpos + pos ; 
        if (mc ) {
          seg = mc -> cont_mark_stack_copied ; 
          pos = findpos ; 
        }
        else {
          seg = p -> cont_mark_stack_segments [findpos >> 8 ] ; 
          pos = findpos & ((1 << 8 ) - 1 ) ; 
        }
        cache = seg [pos ] . cache ; 
        {
          Scheme_Hash_Table * cht ; 
          BLOCK_SETUP((PUSH(cht, 0+XfOrM1386_COUNT)));
#         define XfOrM1387_COUNT (1+XfOrM1386_COUNT)
#         define SETUP_XfOrM1387(x) SETUP(XfOrM1387_COUNT)
          cht = NULLED_OUT ; 
          if (cache && ((Scheme_Type ) (((((long ) (cache ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (cache ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) ) {
#           define XfOrM1398_COUNT (0+XfOrM1387_COUNT)
#           define SETUP_XfOrM1398(x) SETUP_XfOrM1387(x)
            cht = (Scheme_Hash_Table * ) cache ; 
            cache = FUNCCALL(SETUP_XfOrM1398(_), scheme_hash_get (cht , prompt_tag ? prompt_tag : scheme_false ) ); 
          }
          else if (prompt_tag ) {
#           define XfOrM1394_COUNT (0+XfOrM1387_COUNT)
#           define SETUP_XfOrM1394(x) SETUP_XfOrM1387(x)
            cht = FUNCCALL(SETUP_XfOrM1394(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
            if (cache ) {
#             define XfOrM1395_COUNT (0+XfOrM1394_COUNT)
#             define SETUP_XfOrM1395(x) SETUP_XfOrM1394(x)
              if (((Scheme_Type ) (((((long ) (cache ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (cache ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
                Scheme_Object * vec ; 
                BLOCK_SETUP((PUSH(vec, 0+XfOrM1395_COUNT)));
#               define XfOrM1397_COUNT (1+XfOrM1395_COUNT)
#               define SETUP_XfOrM1397(x) SETUP(XfOrM1397_COUNT)
                vec = NULLED_OUT ; 
                if ((((Scheme_Vector * ) (cache ) ) -> els ) [0 ] )
                  FUNCCALL(SETUP_XfOrM1397(_), scheme_hash_set (cht , scheme_default_prompt_tag , (((Scheme_Vector * ) (cache ) ) -> els ) [0 ] ) ); 
                vec = FUNCCALL(SETUP_XfOrM1397(_), scheme_make_vector (4 , ((void * ) 0 ) ) ); 
                (((Scheme_Vector * ) (vec ) ) -> els ) [1 ] = (((Scheme_Vector * ) (cache ) ) -> els ) [1 ] ; 
                (((Scheme_Vector * ) (vec ) ) -> els ) [2 ] = (((Scheme_Vector * ) (cache ) ) -> els ) [2 ] ; 
                (((Scheme_Vector * ) (vec ) ) -> els ) [3 ] = (((Scheme_Vector * ) (cache ) ) -> els ) [3 ] ; 
                FUNCCALL(SETUP_XfOrM1397(_), scheme_hash_set (cht , scheme_false , vec ) ); 
              }
              else {
#               define XfOrM1396_COUNT (0+XfOrM1395_COUNT)
#               define SETUP_XfOrM1396(x) SETUP_XfOrM1395(x)
                FUNCCALL(SETUP_XfOrM1396(_), scheme_hash_set (cht , scheme_default_prompt_tag , cache ) ); 
              }
              cache = ((void * ) 0 ) ; 
            }
            seg [pos ] . cache = (Scheme_Object * ) cht ; 
          }
          else cht = ((void * ) 0 ) ; 
          if (! cache || ! ((Scheme_Type ) (((((long ) (cache ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (cache ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
#           define XfOrM1391_COUNT (0+XfOrM1387_COUNT)
#           define SETUP_XfOrM1391(x) SETUP_XfOrM1387(x)
            cache = FUNCCALL(SETUP_XfOrM1391(_), scheme_make_vector (4 , ((void * ) 0 ) ) ); 
            (((Scheme_Vector * ) (cache ) ) -> els ) [1 ] = key ; 
            (((Scheme_Vector * ) (cache ) ) -> els ) [2 ] = val ; 
            (((Scheme_Vector * ) (cache ) ) -> els ) [3 ] = (Scheme_Object * ) vpos ; 
            if (cht ) {
#             define XfOrM1393_COUNT (0+XfOrM1391_COUNT)
#             define SETUP_XfOrM1393(x) SETUP_XfOrM1391(x)
              FUNCCALL(SETUP_XfOrM1393(_), scheme_hash_set (cht , prompt_tag ? prompt_tag : scheme_false , cache ) ); 
            }
            else {
              if (seg [pos ] . cache && ! (((seg [pos ] . cache ) ) == (scheme_false ) ) )
                (((Scheme_Vector * ) (cache ) ) -> els ) [0 ] = seg [pos ] . cache ; 
              seg [pos ] . cache = cache ; 
            }
          }
          else {
#           define XfOrM1388_COUNT (0+XfOrM1387_COUNT)
#           define SETUP_XfOrM1388(x) SETUP_XfOrM1387(x)
            if ((((Scheme_Vector * ) (cache ) ) -> els ) [1 ] ) {
              Scheme_Hash_Table * ht ; 
              BLOCK_SETUP((PUSH(ht, 0+XfOrM1388_COUNT)));
#             define XfOrM1390_COUNT (1+XfOrM1388_COUNT)
#             define SETUP_XfOrM1390(x) SETUP(XfOrM1390_COUNT)
              ht = NULLED_OUT ; 
              ht = FUNCCALL(SETUP_XfOrM1390(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
              (__funcarg81 = FUNCCALL(SETUP_XfOrM1390(_), scheme_make_raw_pair (val , (Scheme_Object * ) vpos ) ), FUNCCALL_AGAIN(scheme_hash_set (ht , key , __funcarg81 ) )) ; 
              (__funcarg80 = FUNCCALL(SETUP_XfOrM1390(_), scheme_make_raw_pair ((((Scheme_Vector * ) (cache ) ) -> els ) [2 ] , (((Scheme_Vector * ) (cache ) ) -> els ) [3 ] ) ), FUNCCALL_AGAIN(scheme_hash_set (ht , (((Scheme_Vector * ) (cache ) ) -> els ) [1 ] , __funcarg80 ) )) ; 
              (((Scheme_Vector * ) (cache ) ) -> els ) [1 ] = ((void * ) 0 ) ; 
              (((Scheme_Vector * ) (cache ) ) -> els ) [2 ] = (Scheme_Object * ) ht ; 
            }
            else {
              Scheme_Hash_Table * ht ; 
              BLOCK_SETUP((PUSH(ht, 0+XfOrM1388_COUNT)));
#             define XfOrM1389_COUNT (1+XfOrM1388_COUNT)
#             define SETUP_XfOrM1389(x) SETUP(XfOrM1389_COUNT)
              ht = NULLED_OUT ; 
              ht = (Scheme_Hash_Table * ) (((Scheme_Vector * ) (cache ) ) -> els ) [2 ] ; 
              (__funcarg79 = FUNCCALL(SETUP_XfOrM1389(_), scheme_make_raw_pair (val , (Scheme_Object * ) vpos ) ), FUNCCALL_AGAIN(scheme_hash_set (ht , key , __funcarg79 ) )) ; 
            }
          }
        }
      }
      if (val ) {
        if (_meta )
          * _meta = mc ; 
        if (_vpos )
          * _vpos = vpos ; 
        RET_VALUE_START (val ) RET_VALUE_END ; 
      }
      if (mc ) {
        mc = mc -> next ; 
      }
      else {
        mc = p -> meta_continuation ; 
      }
    }
    while (mc ) ; 
  }
  if (key == scheme_parameterization_key ) {
    RET_VALUE_START ((Scheme_Object * ) scheme_current_thread -> init_config ) RET_VALUE_END ; 
  }
  if (key == scheme_break_enabled_key ) {
    RET_VALUE_START (scheme_current_thread -> init_break_cell ) RET_VALUE_END ; 
  }
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_extract_one_cc_mark (Scheme_Object * mark_set , Scheme_Object * key ) {
  /* No conversion */
  return scheme_extract_one_cc_mark_with_meta (mark_set , key , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) ) ; 
}
Scheme_Object * scheme_extract_one_cc_mark_to_tag (Scheme_Object * mark_set , Scheme_Object * key , Scheme_Object * prompt_tag ) {
  /* No conversion */
  return scheme_extract_one_cc_mark_with_meta (mark_set , key , prompt_tag , ((void * ) 0 ) , ((void * ) 0 ) ) ; 
}
static Scheme_Object * extract_one_cc_mark (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * r ; 
  Scheme_Object * prompt_tag ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(prompt_tag, 0), PUSH(argv, 1), PUSH(r, 2)));
# define XfOrM1428_COUNT (3)
# define SETUP_XfOrM1428(x) SETUP(XfOrM1428_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  r = NULLED_OUT ; 
  prompt_tag = NULLED_OUT ; 
  if ((! (((argv [0 ] ) ) == (scheme_false ) ) ) && ! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cont_mark_set_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("continuation-mark-set-first" , "continuation-mark-set or #f" , 0 , argc , argv ) ); 
  if ((argv [1 ] == scheme_parameterization_key ) || (argv [1 ] == scheme_break_enabled_key ) ) {
    prompt_tag = ((void * ) 0 ) ; 
  }
  else prompt_tag = scheme_default_prompt_tag ; 
  if (argc > 3 ) {
#   define XfOrM1430_COUNT (0+XfOrM1428_COUNT)
#   define SETUP_XfOrM1430(x) SETUP_XfOrM1428(x)
    if (! ((Scheme_Type ) (scheme_prompt_tag_type ) == (Scheme_Type ) (((((long ) (argv [3 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [3 ] ) ) -> type ) ) ) ) {
#     define XfOrM1433_COUNT (0+XfOrM1430_COUNT)
#     define SETUP_XfOrM1433(x) SETUP_XfOrM1430(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("continuation-mark-set-first" , "continuation-prompt-tag" , 3 , argc , argv ) ); 
    }
    prompt_tag = argv [3 ] ; 
    if (! ((scheme_default_prompt_tag ) == (prompt_tag ) ) ) {
#     define XfOrM1431_COUNT (0+XfOrM1430_COUNT)
#     define SETUP_XfOrM1431(x) SETUP_XfOrM1430(x)
      if ((((argv [0 ] ) ) == (scheme_false ) ) ) {
#       define XfOrM1432_COUNT (0+XfOrM1431_COUNT)
#       define SETUP_XfOrM1432(x) SETUP_XfOrM1431(x)
        if (! FUNCCALL(SETUP_XfOrM1432(_), scheme_extract_one_cc_mark (((void * ) 0 ) , (((Scheme_Small_Object * ) (prompt_tag ) ) -> u . ptr_val ) ) ))
          FUNCCALL(SETUP_XfOrM1432(_), scheme_arg_mismatch ("continuation-mark-set-first" , "no corresponding prompt in the current continuation: " , prompt_tag ) ); 
      }
    }
  }
  r = FUNCCALL(SETUP_XfOrM1428(_), scheme_extract_one_cc_mark_with_meta ((! (((argv [0 ] ) ) == (scheme_false ) ) ) ? argv [0 ] : ((void * ) 0 ) , argv [1 ] , prompt_tag , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
  if (! r ) {
    if (argc > 2 )
      r = argv [2 ] ; 
    else r = scheme_false ; 
  }
  RET_VALUE_START (r ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_is_cm_deeper (Scheme_Meta_Continuation * m1 , long p1 , Scheme_Meta_Continuation * m2 , long p2 ) {
  /* No conversion */
  if (m1 != m2 ) {
    if (! m1 )
      return 0 ; 
    if (! m2 )
      return 1 ; 
    return (m1 -> depth < m2 -> depth ) ; 
  }
  return p1 < p2 ; 
}
static Scheme_Object * continuation_prompt_available (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * prompt_tag ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(prompt_tag, 0), PUSH(argv, 1)));
# define XfOrM1437_COUNT (2)
# define SETUP_XfOrM1437(x) SETUP(XfOrM1437_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  prompt_tag = NULLED_OUT ; 
  prompt_tag = argv [0 ] ; 
  if (! ((Scheme_Type ) (scheme_prompt_tag_type ) == (Scheme_Type ) (((((long ) (prompt_tag ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (prompt_tag ) ) -> type ) ) ) ) {
#   define XfOrM1445_COUNT (0+XfOrM1437_COUNT)
#   define SETUP_XfOrM1445(x) SETUP_XfOrM1437(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("continuation-prompt-available?" , "continuation-prompt-tag" , 0 , argc , argv ) ); 
  }
  if (argc > 1 ) {
#   define XfOrM1439_COUNT (0+XfOrM1437_COUNT)
#   define SETUP_XfOrM1439(x) SETUP_XfOrM1437(x)
    if (((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_escaping_cont_type ) ) ) {
#     define XfOrM1442_COUNT (0+XfOrM1439_COUNT)
#     define SETUP_XfOrM1442(x) SETUP_XfOrM1439(x)
      if (! FUNCCALL(SETUP_XfOrM1442(_), scheme_escape_continuation_ok (argv [1 ] ) )) {
#       define XfOrM1444_COUNT (0+XfOrM1442_COUNT)
#       define SETUP_XfOrM1444(x) SETUP_XfOrM1442(x)
        FUNCCALL(SETUP_XfOrM1444(_), scheme_arg_mismatch ("continuation-prompt-available?" , "escape continuation not in the current thread's continuation: " , argv [1 ] ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      else {
        Scheme_Meta_Continuation * mc ; 
        BLOCK_SETUP((PUSH(mc, 0+XfOrM1442_COUNT)));
#       define XfOrM1443_COUNT (1+XfOrM1442_COUNT)
#       define SETUP_XfOrM1443(x) SETUP(XfOrM1443_COUNT)
        mc = NULLED_OUT ; 
        if (((scheme_default_prompt_tag ) == (prompt_tag ) ) )
          RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
        FUNCCALL(SETUP_XfOrM1443(_), scheme_extract_one_cc_mark_with_meta (((void * ) 0 ) , argv [1 ] , ((void * ) 0 ) , & mc , ((void * ) 0 ) ) ); 
        if (FUNCCALL(SETUP_XfOrM1443(_), continuation_marks (scheme_current_thread , ((void * ) 0 ) , argv [1 ] , mc , prompt_tag , ((void * ) 0 ) , 0 ) ))
          RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
      }
    }
    else if (((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cont_type ) ) ) {
#     define XfOrM1441_COUNT (0+XfOrM1439_COUNT)
#     define SETUP_XfOrM1441(x) SETUP_XfOrM1439(x)
      if (FUNCCALL(SETUP_XfOrM1441(_), continuation_marks (((void * ) 0 ) , argv [1 ] , ((void * ) 0 ) , ((void * ) 0 ) , prompt_tag , ((void * ) 0 ) , 0 ) ))
        RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
    }
    else {
#     define XfOrM1440_COUNT (0+XfOrM1439_COUNT)
#     define SETUP_XfOrM1440(x) SETUP_XfOrM1439(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("continuation-prompt-available?" , "continuation" , 1 , argc , argv ) ); 
    }
  }
  else {
#   define XfOrM1438_COUNT (0+XfOrM1437_COUNT)
#   define SETUP_XfOrM1438(x) SETUP_XfOrM1437(x)
    if (((scheme_default_prompt_tag ) == (prompt_tag ) ) )
      RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
    if (FUNCCALL_EMPTY(scheme_extract_one_cc_mark (((void * ) 0 ) , (((Scheme_Small_Object * ) (prompt_tag ) ) -> u . ptr_val ) ) ))
      RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
  }
  RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
typedef struct {
  Scheme_Type type ; 
  Scheme_Object * pre , * act , * post ; 
}
Dyn_Wind ; 
static void pre_post_dyn_wind (Scheme_Object * prepost ) {
  Scheme_Cont_Frame_Data cframe ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(prepost, 0), PUSH(cframe.cache, 1)));
# define XfOrM1446_COUNT (2)
# define SETUP_XfOrM1446(x) SETUP(XfOrM1446_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  cframe.cache = NULLED_OUT ; 
  -- scheme_current_thread -> suspend_break ; 
  FUNCCALL(SETUP_XfOrM1446(_), ASSERT_SUSPEND_BREAK_ZERO () ); 
  FUNCCALL_AGAIN(scheme_push_break_enable (& cframe , 0 , 0 ) ); 
  (void ) FUNCCALL(SETUP_XfOrM1446(_), scheme_do_eval (prepost , 0 , ((void * ) 0 ) , - 1 ) ); 
  FUNCCALL(SETUP_XfOrM1446(_), scheme_pop_break_enable (& cframe , 0 ) ); 
  scheme_current_thread -> suspend_break ++ ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_dyn_wind (void * d ) {
  /* No conversion */
  Dyn_Wind * dw ; 
  dw = (Dyn_Wind * ) d ; 
  return scheme_do_eval (dw -> act , 0 , ((void * ) 0 ) , - 1 ) ; 
}
static void pre_dyn_wind (void * d ) {
  /* No conversion */
  pre_post_dyn_wind (((Dyn_Wind * ) d ) -> pre ) ; 
}
static void post_dyn_wind (void * d ) {
  /* No conversion */
  pre_post_dyn_wind (((Dyn_Wind * ) d ) -> post ) ; 
}
static Scheme_Object * dynamic_wind (int c , Scheme_Object * argv [] ) {
  Dyn_Wind * dw ; 
  Scheme_Object * v ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(argv, 1), PUSH(dw, 2)));
# define XfOrM1450_COUNT (3)
# define SETUP_XfOrM1450(x) SETUP(XfOrM1450_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  dw = NULLED_OUT ; 
  v = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM1450(_), scheme_check_proc_arity ("dynamic-wind" , 0 , 0 , c , argv ) ); 
  FUNCCALL_AGAIN(scheme_check_proc_arity ("dynamic-wind" , 0 , 1 , c , argv ) ); 
  FUNCCALL_AGAIN(scheme_check_proc_arity ("dynamic-wind" , 0 , 2 , c , argv ) ); 
  dw = ((Dyn_Wind * ) FUNCCALL(SETUP_XfOrM1450(_), GC_malloc_one_small_tagged ((((sizeof (Dyn_Wind ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  dw -> type = scheme_rt_dyn_wind_info ; 
  dw -> pre = argv [0 ] ; 
  dw -> act = argv [1 ] ; 
  dw -> post = argv [2 ] ; 
  v = FUNCCALL(SETUP_XfOrM1450(_), scheme_dynamic_wind (pre_dyn_wind , do_dyn_wind , post_dyn_wind , ((void * ) 0 ) , (void * ) dw ) ); 
  {
    Scheme_Thread * p = scheme_current_thread ; 
    BLOCK_SETUP((PUSH(p, 0+XfOrM1450_COUNT)));
#   define XfOrM1451_COUNT (1+XfOrM1450_COUNT)
#   define SETUP_XfOrM1451(x) SETUP(XfOrM1451_COUNT)
    if (p -> external_break && FUNCCALL(SETUP_XfOrM1451(_), scheme_can_break (p ) )) {
      Scheme_Object * * save_values ; 
      int save_count ; 
      BLOCK_SETUP((PUSH(save_values, 0+XfOrM1451_COUNT)));
#     define XfOrM1452_COUNT (1+XfOrM1451_COUNT)
#     define SETUP_XfOrM1452(x) SETUP(XfOrM1452_COUNT)
      save_values = NULLED_OUT ; 
      if (((v ) == (((Scheme_Object * ) 0x6 ) ) ) ) {
        save_count = p -> ku . multiple . count ; 
        save_values = p -> ku . multiple . array ; 
        p -> ku . multiple . array = ((void * ) 0 ) ; 
        if (((save_values ) == (p -> values_buffer ) ) )
          p -> values_buffer = ((void * ) 0 ) ; 
      }
      else {
        save_count = 0 ; 
        save_values = ((void * ) 0 ) ; 
      }
      FUNCCALL(SETUP_XfOrM1452(_), scheme_thread_block (0.0 ) ); 
      p -> ran_some = 1 ; 
      if (save_values ) {
        p -> ku . multiple . count = save_count ; 
        p -> ku . multiple . array = save_values ; 
      }
    }
  }
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_dynamic_wind (void (* pre ) (void * ) , Scheme_Object * (* volatile act ) (void * ) , void (* volatile post ) (void * ) , Scheme_Object * (* jmp_handler ) (void * ) , void * volatile data ) {
  mz_jmp_buf newbuf ; 
  Scheme_Object * volatile v , * * volatile save_values ; 
  volatile int err ; 
  Scheme_Dynamic_Wind * volatile dw ; 
  volatile int save_count , old_cac ; 
  Scheme_Thread * p ; 
  int delta ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(dw, 1), PUSH(save_values, 2), PUSH(p, 3), PUSH(data, 4)));
# define XfOrM1456_COUNT (5)
# define SETUP_XfOrM1456(x) SETUP(XfOrM1456_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  v = NULLED_OUT ; 
  save_values = NULLED_OUT ; 
  dw = NULLED_OUT ; 
  p = NULLED_OUT ; 
  p = scheme_current_thread ; 
  dw = ((Scheme_Dynamic_Wind * ) FUNCCALL(SETUP_XfOrM1456(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Dynamic_Wind ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  dw -> type = scheme_rt_dyn_wind ; 
  dw -> data = data ; 
  dw -> pre = pre ; 
  dw -> post = post ; 
  dw -> prev = p -> dw ; 
  if (dw -> prev )
    dw -> depth = dw -> prev -> depth + 1 ; 
  else dw -> depth = 0 ; 
  dw -> next_meta = p -> next_meta ; 
  if (pre ) {
#   define XfOrM1476_COUNT (0+XfOrM1456_COUNT)
#   define SETUP_XfOrM1476(x) SETUP_XfOrM1456(x)
    FUNCCALL(SETUP_XfOrM1476(_), ASSERT_SUSPEND_BREAK_ZERO () ); 
    p -> suspend_break ++ ; 
    FUNCCALL(SETUP_XfOrM1476(_), pre (data ) ); 
    p = scheme_current_thread ; 
    -- p -> suspend_break ; 
  }
  p -> next_meta = 0 ; 
  p -> dw = dw ; 
  dw -> saveerr = scheme_current_thread -> error_buf ; 
  scheme_current_thread -> error_buf = & newbuf ; 
  (dw -> envss . runstack_offset = scheme_current_runstack - scheme_current_runstack_start , dw -> envss . cont_mark_stack = scheme_current_cont_mark_stack , dw -> envss . cont_mark_pos = scheme_current_cont_mark_pos ) ; 
  if (((newbuf ) . gcvs = (long ) __gc_var_stack__ , (newbuf ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((newbuf ) . jb ) , (_setjmp (((newbuf ) . jb ) -> jb ) ) ) ) ) {
#   define XfOrM1473_COUNT (0+XfOrM1456_COUNT)
#   define SETUP_XfOrM1473(x) SETUP_XfOrM1456(x)
    p = scheme_current_thread ; 
    (scheme_current_runstack = scheme_current_runstack_start + dw -> envss . runstack_offset , scheme_current_cont_mark_stack = dw -> envss . cont_mark_stack , scheme_current_cont_mark_pos = dw -> envss . cont_mark_pos ) ; 
    if ((p -> dw != dw ) && (! p -> dw || ! dw -> id || (p -> dw -> id != dw -> id ) ) ) {
      (((long * ) (void * ) ((* dw -> saveerr ) . gcvs ) ) [1 ] = (* dw -> saveerr ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* dw -> saveerr ) . gcvs , scheme_jit_longjmp ((* dw -> saveerr ) . jb , 1 ) ) ; 
    }
    else {
#     define XfOrM1474_COUNT (0+XfOrM1473_COUNT)
#     define SETUP_XfOrM1474(x) SETUP_XfOrM1473(x)
      if (jmp_handler )
        v = FUNCCALL(SETUP_XfOrM1474(_), jmp_handler (data ) ); 
      else v = ((void * ) 0 ) ; 
      err = ! v ; 
    }
  }
  else {
#   define XfOrM1471_COUNT (0+XfOrM1456_COUNT)
#   define SETUP_XfOrM1471(x) SETUP_XfOrM1456(x)
    if (pre ) {
#     define XfOrM1472_COUNT (0+XfOrM1471_COUNT)
#     define SETUP_XfOrM1472(x) SETUP_XfOrM1471(x)
      FUNCCALL(SETUP_XfOrM1472(_), scheme_check_break_now () ); 
    }
    v = FUNCCALL(SETUP_XfOrM1471(_), act (data ) ); 
    err = 0 ; 
  }
  p = scheme_current_thread ; 
  if (((v ) == (((Scheme_Object * ) 0x6 ) ) ) ) {
    save_count = p -> ku . multiple . count ; 
    save_values = p -> ku . multiple . array ; 
    p -> ku . multiple . array = ((void * ) 0 ) ; 
    if (((save_values ) == (p -> values_buffer ) ) )
      p -> values_buffer = ((void * ) 0 ) ; 
  }
  else {
    save_count = 0 ; 
    save_values = ((void * ) 0 ) ; 
  }
  delta = p -> dw -> next_meta ; 
  p -> dw = p -> dw -> prev ; 
  p -> next_meta += delta ; 
  if (err && p -> cjs . is_kill && (post == post_dyn_wind ) )
    post = ((void * ) 0 ) ; 
  old_cac = scheme_continuation_application_count ; 
  if (post ) {
#   define XfOrM1466_COUNT (0+XfOrM1456_COUNT)
#   define SETUP_XfOrM1466(x) SETUP_XfOrM1456(x)
    p -> error_buf = & newbuf ; 
    if (((newbuf ) . gcvs = (long ) __gc_var_stack__ , (newbuf ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((newbuf ) . jb ) , (_setjmp (((newbuf ) . jb ) -> jb ) ) ) ) ) {
      p = scheme_current_thread ; 
      (scheme_current_runstack = scheme_current_runstack_start + dw -> envss . runstack_offset , scheme_current_cont_mark_stack = dw -> envss . cont_mark_stack , scheme_current_cont_mark_pos = dw -> envss . cont_mark_pos ) ; 
      err = 1 ; 
    }
    else {
      Scheme_Continuation_Jump_State cjs ; 
      BLOCK_SETUP((PUSH(cjs.jumping_to_continuation, 0+XfOrM1466_COUNT), PUSH(cjs.val, 1+XfOrM1466_COUNT)));
#     define XfOrM1467_COUNT (2+XfOrM1466_COUNT)
#     define SETUP_XfOrM1467(x) SETUP(XfOrM1467_COUNT)
      cjs.jumping_to_continuation = NULLED_OUT ; 
      cjs.val = NULLED_OUT ; 
      p = scheme_current_thread ; 
      FUNCCALL(SETUP_XfOrM1467(_), ASSERT_SUSPEND_BREAK_ZERO () ); 
      p -> suspend_break ++ ; 
      FUNCCALL(SETUP_XfOrM1467(_), copy_cjs (& cjs , & p -> cjs ) ); 
      FUNCCALL_AGAIN(reset_cjs (& p -> cjs ) ); 
      FUNCCALL_AGAIN(post (data ) ); 
      FUNCCALL_AGAIN(copy_cjs (& p -> cjs , & cjs ) ); 
      p = scheme_current_thread ; 
      -- p -> suspend_break ; 
    }
  }
  if (err ) {
#   define XfOrM1459_COUNT (0+XfOrM1456_COUNT)
#   define SETUP_XfOrM1459(x) SETUP_XfOrM1456(x)
    if ((old_cac != scheme_continuation_application_count ) && p -> cjs . jumping_to_continuation ) {
#     define XfOrM1460_COUNT (0+XfOrM1459_COUNT)
#     define SETUP_XfOrM1460(x) SETUP_XfOrM1459(x)
      p -> error_buf = dw -> saveerr ; 
      if (((Scheme_Type ) (((((long ) (p -> cjs . jumping_to_continuation ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p -> cjs . jumping_to_continuation ) ) -> type ) ) == (Scheme_Type ) (scheme_prompt_type ) ) ) {
        Scheme_Object * tag ; 
        Scheme_Prompt * prompt ; 
        BLOCK_SETUP((PUSH(prompt, 0+XfOrM1460_COUNT), PUSH(tag, 1+XfOrM1460_COUNT)));
#       define XfOrM1463_COUNT (2+XfOrM1460_COUNT)
#       define SETUP_XfOrM1463(x) SETUP(XfOrM1463_COUNT)
        tag = NULLED_OUT ; 
        prompt = NULLED_OUT ; 
        tag = ((Scheme_Prompt * ) p -> cjs . jumping_to_continuation ) -> tag ; 
        prompt = (Scheme_Prompt * ) FUNCCALL(SETUP_XfOrM1463(_), scheme_extract_one_cc_mark (((void * ) 0 ) , (((Scheme_Small_Object * ) (tag ) ) -> u . ptr_val ) ) ); 
        if (! prompt && ((scheme_default_prompt_tag ) == (tag ) ) ) {
          prompt = original_default_prompt ; 
        }
        if (! prompt ) {
#         define XfOrM1464_COUNT (0+XfOrM1463_COUNT)
#         define SETUP_XfOrM1464(x) SETUP_XfOrM1463(x)
          FUNCCALL(SETUP_XfOrM1464(_), scheme_arg_mismatch ("abort-current-continuation" , "abort in progress, but current continuation includes" " no prompt with the given tag" " after a `dynamic-wind' post-thunk return: " , tag ) ); 
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        }
        p -> cjs . jumping_to_continuation = (Scheme_Object * ) prompt ; 
      }
      else if (((Scheme_Type ) (((((long ) (p -> cjs . jumping_to_continuation ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p -> cjs . jumping_to_continuation ) ) -> type ) ) == (Scheme_Type ) (scheme_escaping_cont_type ) ) ) {
#       define XfOrM1461_COUNT (0+XfOrM1460_COUNT)
#       define SETUP_XfOrM1461(x) SETUP_XfOrM1460(x)
        if (! FUNCCALL(SETUP_XfOrM1461(_), scheme_escape_continuation_ok (p -> cjs . jumping_to_continuation ) )) {
#         define XfOrM1462_COUNT (0+XfOrM1461_COUNT)
#         define SETUP_XfOrM1462(x) SETUP_XfOrM1461(x)
          FUNCCALL(SETUP_XfOrM1462(_), scheme_raise_exn (MZEXN_FAIL_CONTRACT_CONTINUATION , "jump to escape continuation in progress," " but the target is not in the current continuation" " after a `dynamic-wind' post-thunk return" ) ); 
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        }
      }
    }
    (((long * ) (void * ) ((* dw -> saveerr ) . gcvs ) ) [1 ] = (* dw -> saveerr ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* dw -> saveerr ) . gcvs , scheme_jit_longjmp ((* dw -> saveerr ) . jb , 1 ) ) ; 
  }
  p -> error_buf = dw -> saveerr ; 
  if (post ) {
#   define XfOrM1458_COUNT (0+XfOrM1456_COUNT)
#   define SETUP_XfOrM1458(x) SETUP_XfOrM1456(x)
    FUNCCALL(SETUP_XfOrM1458(_), scheme_check_break_now () ); 
  }
  if (v == ((Scheme_Object * ) 0x6 ) ) {
    p -> ku . multiple . count = save_count ; 
    p -> ku . multiple . array = save_values ; 
  }
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 7294 */
void scheme_apply_dw_in_meta (Scheme_Dynamic_Wind * dw , int post_part , int meta_depth , Scheme_Cont * recheck ) {
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Meta_Continuation * mc , * old_mc , * rest ; 
  long delta ; 
  int i , actual_depth ; 
  int old_cac ; 
  PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(old_mc, 0), PUSH(dw, 1), PUSH(p, 2), PUSH(rest, 3), PUSH(recheck, 4), PUSH(mc, 5)));
# define XfOrM1477_COUNT (6)
# define SETUP_XfOrM1477(x) SETUP(XfOrM1477_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  mc = NULLED_OUT ; 
  old_mc = NULLED_OUT ; 
  rest = NULLED_OUT ; 
  scheme_current_cont_mark_stack = p -> cont_mark_stack_bottom ; 
  scheme_current_cont_mark_pos = p -> meta_continuation -> meta_tail_pos + 2 ; 
  old_mc = p -> meta_continuation ; 
  for (i = 0 , actual_depth = 0 , rest = old_mc ; i < meta_depth ; actual_depth ++ ) {
    if (rest -> overflow )
      i ++ ; 
    rest = rest -> next ; 
  }
  mc = FUNCCALL(SETUP_XfOrM1477(_), clone_meta_cont (p -> meta_continuation , ((void * ) 0 ) , actual_depth , ((void * ) 0 ) , ((void * ) 0 ) , rest , 0 ) ); 
  p -> meta_continuation = mc ; 
  rest = mc ; 
  for (i = 0 ; i < actual_depth - 1 ; i ++ ) {
    rest -> cont_mark_total = 0 ; 
    rest -> cont_mark_offset = 0 ; 
    rest -> cont_mark_stack_copied = ((void * ) 0 ) ; 
    rest = rest -> next ; 
  }
  delta = rest -> cont_mark_stack - dw -> envss . cont_mark_stack ; 
  if (delta ) {
#   define XfOrM1484_COUNT (0+XfOrM1477_COUNT)
#   define SETUP_XfOrM1484(x) SETUP_XfOrM1477(x)
    rest -> cont_mark_total -= delta ; 
    rest -> cont_mark_stack -= delta ; 
    if (rest -> cont_mark_total ) {
      Scheme_Cont_Mark * cp ; 
      BLOCK_SETUP((PUSH(cp, 0+XfOrM1484_COUNT)));
#     define XfOrM1485_COUNT (1+XfOrM1484_COUNT)
#     define SETUP_XfOrM1485(x) SETUP(XfOrM1485_COUNT)
      cp = NULLED_OUT ; 
      cp = ((Scheme_Cont_Mark * ) FUNCCALL(SETUP_XfOrM1485(_), GC_malloc (sizeof (Scheme_Cont_Mark ) * (rest -> cont_mark_total ) ) )) ; 
      (memcpy (cp , rest -> cont_mark_stack_copied , rest -> cont_mark_total * sizeof (Scheme_Cont_Mark ) ) ) ; 
      rest -> cont_mark_stack_copied = cp ; 
    }
    else rest -> cont_mark_stack_copied = ((void * ) 0 ) ; 
  }
  old_cac = scheme_continuation_application_count ; 
  if (post_part ) {
    DW_PrePost_Proc post = dw -> post ; 
#   define XfOrM1483_COUNT (0+XfOrM1477_COUNT)
#   define SETUP_XfOrM1483(x) SETUP_XfOrM1477(x)
    FUNCCALL(SETUP_XfOrM1483(_), post (dw -> data ) ); 
  }
  else {
    DW_PrePost_Proc pre = dw -> pre ; 
#   define XfOrM1482_COUNT (0+XfOrM1477_COUNT)
#   define SETUP_XfOrM1482(x) SETUP_XfOrM1477(x)
    FUNCCALL(SETUP_XfOrM1482(_), pre (dw -> data ) ); 
  }
  p = scheme_current_thread ; 
  if (recheck ) {
#   define XfOrM1480_COUNT (0+XfOrM1477_COUNT)
#   define SETUP_XfOrM1480(x) SETUP_XfOrM1477(x)
    if (scheme_continuation_application_count != old_cac ) {
#     define XfOrM1481_COUNT (0+XfOrM1480_COUNT)
#     define SETUP_XfOrM1481(x) SETUP_XfOrM1480(x)
      FUNCCALL(SETUP_XfOrM1481(_), scheme_recheck_prompt_and_barrier (recheck ) ); 
    }
  }
  for (i = 0 , rest = p -> meta_continuation ; i < actual_depth ; i ++ ) {
    rest = rest -> next ; 
  }
  old_mc = FUNCCALL(SETUP_XfOrM1477(_), clone_meta_cont (old_mc , ((void * ) 0 ) , actual_depth , ((void * ) 0 ) , ((void * ) 0 ) , rest , 0 ) ); 
  p -> meta_continuation = old_mc ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
long scheme_get_milliseconds (void ) {
  struct timeval now ; 
  gettimeofday (& now , ((void * ) 0 ) ) ; 
  return now . tv_sec * 1000 + now . tv_usec / 1000 ; 
}
double scheme_get_inexact_milliseconds (void ) {
  struct timeval now ; 
  gettimeofday (& now , ((void * ) 0 ) ) ; 
  return (double ) now . tv_sec * 1000.0 + (double ) now . tv_usec / 1000 ; 
}
long scheme_get_process_milliseconds (void ) {
  struct rusage use ; 
  long s , u ; 
  getrusage (RUSAGE_SELF , & use ) ; 
  s = use . ru_utime . tv_sec + use . ru_stime . tv_sec ; 
  u = use . ru_utime . tv_usec + use . ru_stime . tv_usec ; 
  return s * 1000 + u / 1000 ; 
}
long scheme_get_seconds (void ) {
  /* No conversion */
  struct timeval now ; 
  gettimeofday (& now , ((void * ) 0 ) ) ; 
  return now . tv_sec ; 
}
static Scheme_Object * seconds_to_date (int argc , Scheme_Object * * argv ) {
  long lnow ; 
  int hour , min , sec , month , day , year , wday , yday , dst ; 
  long tzoffset ; 
  struct tm * localTime ; 
  time_t now ; 
  Scheme_Object * p [10 ] , * secs ; 
  char * __funcarg83 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSHARRAY(p, 10, 0), PUSH(secs, 3), PUSH(localTime, 4)));
# define XfOrM1491_COUNT (5)
# define SETUP_XfOrM1491(x) SETUP(XfOrM1491_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  localTime = NULLED_OUT ; 
  NULL_OUT_ARRAY (p ) ; 
  secs = NULLED_OUT ; 
  secs = argv [0 ] ; 
  if (! (((long ) (secs ) ) & 0x1 ) && ! ((Scheme_Type ) (((((long ) (secs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (secs ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) {
#   define XfOrM1494_COUNT (0+XfOrM1491_COUNT)
#   define SETUP_XfOrM1494(x) SETUP_XfOrM1491(x)
    FUNCCALL(SETUP_XfOrM1494(_), scheme_wrong_type ("seconds->date" , "exact integer" , 0 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if ((scheme_get_int_val (secs , & lnow ) ) && ((long ) (now = (time_t ) lnow ) ) == lnow ) {
    int success ; 
#   define XfOrM1492_COUNT (0+XfOrM1491_COUNT)
#   define SETUP_XfOrM1492(x) SETUP_XfOrM1491(x)
    localTime = FUNCCALL(SETUP_XfOrM1492(_), localtime (& now ) ); 
    success = ! ! localTime ; 
    if (success ) {
#     define XfOrM1493_COUNT (0+XfOrM1492_COUNT)
#     define SETUP_XfOrM1493(x) SETUP_XfOrM1492(x)
      hour = localTime -> tm_hour ; 
      min = localTime -> tm_min ; 
      sec = localTime -> tm_sec ; 
      month = localTime -> tm_mon + 1 ; 
      day = localTime -> tm_mday ; 
      year = localTime -> tm_year + 1900 ; 
      wday = localTime -> tm_wday ; 
      yday = localTime -> tm_yday ; 
      dst = localTime -> tm_isdst ; 
      tzoffset = 0 ; 
      tzoffset = - (timezone - (dst ? 3600 : 0 ) ) ; 
      p [0 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (sec ) ) << 1 ) | 0x1 ) ) ; 
      p [1 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (min ) ) << 1 ) | 0x1 ) ) ; 
      p [2 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (hour ) ) << 1 ) | 0x1 ) ) ; 
      p [3 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (day ) ) << 1 ) | 0x1 ) ) ; 
      p [4 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (month ) ) << 1 ) | 0x1 ) ) ; 
      p [5 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (year ) ) << 1 ) | 0x1 ) ) ; 
      p [6 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (wday ) ) << 1 ) | 0x1 ) ) ; 
      p [7 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (yday ) ) << 1 ) | 0x1 ) ) ; 
      p [8 ] = dst ? scheme_true : scheme_false ; 
      p [9 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (tzoffset ) ) << 1 ) | 0x1 ) ) ; 
      RET_VALUE_START (FUNCCALL(SETUP_XfOrM1493(_), scheme_make_struct_instance (scheme_date , 10 , p ) )) RET_VALUE_END ; 
    }
  }
  (__funcarg83 = FUNCCALL(SETUP_XfOrM1491(_), scheme_make_provided_string (secs , 0 , ((void * ) 0 ) ) ), FUNCCALL_AGAIN(scheme_raise_exn (MZEXN_FAIL , "seconds->date: integer %s is out-of-range" , __funcarg83 ) )) ; 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * time_apply (int argc , Scheme_Object * argv [] ) {
  long start , end ; 
  long cpustart , cpuend ; 
  long gcstart , gcend ; 
  long dur , cpudur , gcdur ; 
  int i , num_rands ; 
  Scheme_Object * v , * p [4 ] , * * rand_vec , * rands , * r ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(9);
  BLOCK_SETUP_TOP((PUSH(rand_vec, 0), PUSH(v, 1), PUSH(r, 2), PUSH(rands, 3), PUSH(argv, 4), PUSHARRAY(p, 4, 5)));
# define XfOrM1495_COUNT (8)
# define SETUP_XfOrM1495(x) SETUP(XfOrM1495_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  v = NULLED_OUT ; 
  NULL_OUT_ARRAY (p ) ; 
  rand_vec = NULLED_OUT ; 
  rands = NULLED_OUT ; 
  r = NULLED_OUT ; 
  if (! (! (((long ) (argv [0 ] ) ) & 0x1 ) && ((((argv [0 ] ) -> type ) >= scheme_prim_type ) && (((argv [0 ] ) -> type ) <= scheme_native_closure_type ) ) ) )
    FUNCCALL(SETUP_XfOrM1495(_), scheme_wrong_type ("time-apply" , "procedure" , 0 , argc , argv ) ); 
  rands = argv [1 ] ; 
  num_rands = 0 ; 
  r = rands ; 
  while (! ((r ) == (scheme_null ) ) ) {
#   define XfOrM1501_COUNT (0+XfOrM1495_COUNT)
#   define SETUP_XfOrM1501(x) SETUP_XfOrM1495(x)
    if (! ((Scheme_Type ) (((((long ) (r ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (r ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
      FUNCCALL(SETUP_XfOrM1501(_), scheme_wrong_type ("time-apply" , "proper list" , 1 , argc , argv ) ); 
    r = (((Scheme_Simple_Object * ) (r ) ) -> u . pair_val . cdr ) ; 
    num_rands ++ ; 
  }
  if ((((FUNCCALL(SETUP_XfOrM1495(_), get_or_check_arity (argv [0 ] , num_rands , ((void * ) 0 ) ) )) ) == (scheme_false ) ) ) {
    char * s ; 
    long aelen ; 
    BLOCK_SETUP((PUSH(s, 0+XfOrM1495_COUNT)));
#   define XfOrM1499_COUNT (1+XfOrM1495_COUNT)
#   define SETUP_XfOrM1499(x) SETUP(XfOrM1499_COUNT)
    s = NULLED_OUT ; 
    s = FUNCCALL(SETUP_XfOrM1499(_), scheme_make_arity_expect_string (argv [0 ] , num_rands , ((void * ) 0 ) , & aelen ) ); 
    FUNCCALL_AGAIN(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "time-apply: arity mismatch for %t" , s , aelen ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  rand_vec = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM1495(_), GC_malloc (sizeof (Scheme_Object * ) * (num_rands ) ) )) ; 
  for (i = 0 ; ((Scheme_Type ) (((((long ) (rands ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rands ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; i ++ , rands = (((Scheme_Simple_Object * ) (rands ) ) -> u . pair_val . cdr ) ) {
    rand_vec [i ] = (((Scheme_Simple_Object * ) (rands ) ) -> u . pair_val . car ) ; 
  }
  gcstart = scheme_total_gc_time ; 
  start = scheme_get_milliseconds () ; 
  cpustart = scheme_get_process_milliseconds () ; 
  v = FUNCCALL(SETUP_XfOrM1495(_), scheme_do_eval (argv [0 ] , num_rands , rand_vec , - 1 ) ); 
  cpuend = scheme_get_process_milliseconds () ; 
  end = scheme_get_milliseconds () ; 
  gcend = scheme_total_gc_time ; 
  dur = end - start ; 
  cpudur = cpuend - cpustart ; 
  gcdur = gcend - gcstart ; 
  if (v == ((Scheme_Object * ) 0x6 ) ) {
    Scheme_Thread * cp = scheme_current_thread ; 
#   define XfOrM1496_COUNT (0+XfOrM1495_COUNT)
#   define SETUP_XfOrM1496(x) SETUP_XfOrM1495(x)
    if (((cp -> ku . multiple . array ) == (cp -> values_buffer ) ) )
      cp -> values_buffer = ((void * ) 0 ) ; 
    v = FUNCCALL(SETUP_XfOrM1496(_), scheme_build_list (cp -> ku . multiple . count , cp -> ku . multiple . array ) ); 
  }
  else v = FUNCCALL(SETUP_XfOrM1495(_), scheme_make_pair (v , scheme_null ) ); 
  p [0 ] = v ; 
  p [1 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (cpudur ) ) << 1 ) | 0x1 ) ) ; 
  p [2 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (dur ) ) << 1 ) | 0x1 ) ) ; 
  p [3 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (gcdur ) ) << 1 ) | 0x1 ) ) ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM1495(_), scheme_values (4 , p ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * current_milliseconds (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return ((Scheme_Object * ) (void * ) (long ) ((((long ) (scheme_get_milliseconds () ) ) << 1 ) | 0x1 ) ) ; 
}
static Scheme_Object * current_inexact_milliseconds (int argc , Scheme_Object * * argv ) {
  double __funcarg84 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(0);
# define XfOrM1503_COUNT (0)
# define SETUP_XfOrM1503(x) SETUP(XfOrM1503_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg84 = FUNCCALL_EMPTY(scheme_get_inexact_milliseconds () ), FUNCCALL_EMPTY(scheme_make_double (__funcarg84 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * current_process_milliseconds (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return ((Scheme_Object * ) (void * ) (long ) ((((long ) (scheme_get_process_milliseconds () ) ) << 1 ) | 0x1 ) ) ; 
}
static Scheme_Object * current_gc_milliseconds (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return ((Scheme_Object * ) (void * ) (long ) ((((long ) (scheme_total_gc_time ) ) << 1 ) | 0x1 ) ) ; 
}
static Scheme_Object * current_seconds (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  long secs ; 
  secs = scheme_get_seconds () ; 
  return scheme_make_integer_value ((long ) secs ) ; 
}
static Scheme_Object * current_print (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return scheme_param_config ("current-print" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_PRINT_HANDLER ) ) << 1 ) | 0x1 ) ) , argc , argv , 1 , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ; 
}
static Scheme_Object * current_prompt_read (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return scheme_param_config ("current-prompt-read" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_PROMPT_READ_HANDLER ) ) << 1 ) | 0x1 ) ) , argc , argv , 0 , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ; 
}
Scheme_Object * scheme_default_print_handler (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * obj = argv [0 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(9);
  BLOCK_SETUP_TOP((PUSH(obj, 0), PUSHARRAY(argv, 2, 1)));
# define XfOrM1509_COUNT (4)
# define SETUP_XfOrM1509(x) SETUP(XfOrM1509_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! ((obj ) == (scheme_void ) ) ) {
    Scheme_Config * config ; 
    Scheme_Object * port ; 
    Scheme_Object * argv [2 ] ; 
    BLOCK_SETUP((PUSH(config, 0+XfOrM1509_COUNT), PUSHARRAY(argv, 2, 1+XfOrM1509_COUNT), PUSH(port, 4+XfOrM1509_COUNT)));
#   define XfOrM1510_COUNT (5+XfOrM1509_COUNT)
#   define SETUP_XfOrM1510(x) SETUP(XfOrM1510_COUNT)
    config = NULLED_OUT ; 
    port = NULLED_OUT ; 
    argv[0] = NULLED_OUT ; 
    argv[1] = NULLED_OUT ; 
    config = FUNCCALL(SETUP_XfOrM1510(_), scheme_current_config () ); 
    port = FUNCCALL_AGAIN(scheme_get_param (config , MZCONFIG_OUTPUT_PORT ) ); 
    argv [0 ] = obj ; 
    argv [1 ] = port ; 
    FUNCCALL(SETUP_XfOrM1510(_), scheme_do_eval (scheme_print_proc , 2 , argv , 1 ) ); 
    FUNCCALL_AGAIN(scheme_write_byte_string ("\n" , 1 , port ) ); 
  }
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_default_prompt_read_handler (int argc , Scheme_Object * argv [] ) {
  Scheme_Config * config ; 
  Scheme_Object * port ; 
  Scheme_Object * inport ; 
  Scheme_Object * name ; 
  Scheme_Object * stx ; 
  Scheme_Cont_Frame_Data cframe ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(stx, 0), PUSH(name, 1), PUSH(config, 2), PUSH(inport, 3), PUSH(cframe.cache, 4), PUSH(port, 5)));
# define XfOrM1511_COUNT (6)
# define SETUP_XfOrM1511(x) SETUP(XfOrM1511_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  config = NULLED_OUT ; 
  port = NULLED_OUT ; 
  inport = NULLED_OUT ; 
  name = NULLED_OUT ; 
  stx = NULLED_OUT ; 
  cframe.cache = NULLED_OUT ; 
  config = FUNCCALL(SETUP_XfOrM1511(_), scheme_current_config () ); 
  port = FUNCCALL_AGAIN(scheme_get_param (config , MZCONFIG_OUTPUT_PORT ) ); 
  inport = FUNCCALL_AGAIN(scheme_get_param (config , MZCONFIG_INPUT_PORT ) ); 
  FUNCCALL_AGAIN(scheme_write_byte_string ("> " , 2 , port ) ); 
  FUNCCALL_AGAIN(scheme_flush_output (port ) ); 
  name = ((Scheme_Input_Port * ) inport ) -> name ; 
  if (inport == scheme_orig_stdin_port )
    FUNCCALL(SETUP_XfOrM1511(_), scheme_flush_orig_outputs () ); 
  config = FUNCCALL(SETUP_XfOrM1511(_), scheme_extend_config (config , MZCONFIG_CAN_READ_READER , scheme_true ) ); 
  FUNCCALL_AGAIN(scheme_push_continuation_frame (& cframe ) ); 
  FUNCCALL_AGAIN(scheme_install_config (config ) ); 
  stx = FUNCCALL_AGAIN(scheme_read_syntax (inport , name ) ); 
  FUNCCALL_AGAIN(scheme_pop_continuation_frame (& cframe ) ); 
  RET_VALUE_START (stx ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * write_compiled_closure (Scheme_Object * obj ) {
  Scheme_Closure_Data * data ; 
  Scheme_Object * name , * l ; 
  int svec_size ; 
  Scheme_Object * __funcarg89 = NULLED_OUT ; 
  Scheme_Object * __funcarg88 = NULLED_OUT ; 
  Scheme_Object * __funcarg87 = NULLED_OUT ; 
  Scheme_Object * __funcarg86 = NULLED_OUT ; 
  Scheme_Object * __funcarg85 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(__funcarg88, 0), PUSH(data, 1), PUSH(l, 2), PUSH(name, 3)));
# define XfOrM1512_COUNT (4)
# define SETUP_XfOrM1512(x) SETUP(XfOrM1512_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  data = NULLED_OUT ; 
  name = NULLED_OUT ; 
  l = NULLED_OUT ; 
  data = (Scheme_Closure_Data * ) obj ; 
  if (data -> name ) {
    name = data -> name ; 
    if (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
      Scheme_Object * src ; 
      src = NULLED_OUT ; 
      src = (((Scheme_Vector * ) (name ) ) -> els ) [1 ] ; 
      if (! ((Scheme_Type ) (((((long ) (src ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (src ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) && ! ((Scheme_Type ) (((((long ) (src ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (src ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) && ! ((Scheme_Type ) (((((long ) (src ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (src ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
        name = (((Scheme_Vector * ) (name ) ) -> els ) [0 ] ; 
      }
    }
  }
  else {
    name = scheme_null ; 
  }
  svec_size = data -> closure_size ; 
  if ((& (data ) -> iso ) -> so . keyex & 2 ) {
    svec_size += (data -> num_params + (8 * sizeof (mzshort ) ) - 1 ) / (8 * sizeof (mzshort ) ) ; 
  }
  l = (__funcarg88 = FUNCCALL(SETUP_XfOrM1512(_), scheme_make_svector (svec_size , data -> closure_map ) ), __funcarg89 = FUNCCALL(SETUP_XfOrM1512(_), scheme_protect_quote (data -> code ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg88 , __funcarg89 ) )) ; 
  if ((& (data ) -> iso ) -> so . keyex & 2 )
    l = FUNCCALL(SETUP_XfOrM1512(_), scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (data -> closure_size ) ) << 1 ) | 0x1 ) ) , l ) ); 
  RET_VALUE_START ((__funcarg85 = (__funcarg86 = (__funcarg87 = FUNCCALL(SETUP_XfOrM1512(_), scheme_make_pair (name , l ) ), FUNCCALL_AGAIN(scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (data -> max_let_depth ) ) << 1 ) | 0x1 ) ) , __funcarg87 ) )) , FUNCCALL_AGAIN(scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (data -> num_params ) ) << 1 ) | 0x1 ) ) , __funcarg86 ) )) , FUNCCALL_EMPTY(scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) ((& (data ) -> iso ) -> so . keyex ) ) << 1 ) | 0x1 ) ) , __funcarg85 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * read_compiled_closure (Scheme_Object * obj ) {
  Scheme_Closure_Data * data ; 
  Scheme_Object * v ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(obj, 1), PUSH(data, 2)));
# define XfOrM1518_COUNT (3)
# define SETUP_XfOrM1518(x) SETUP(XfOrM1518_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  data = NULLED_OUT ; 
  v = NULLED_OUT ; 
  data = (Scheme_Closure_Data * ) FUNCCALL(SETUP_XfOrM1518(_), GC_malloc_one_tagged (sizeof (Scheme_Closure_Data ) ) ); 
  data -> iso . so . type = scheme_unclosed_procedure_type ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  v = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  (& (data ) -> iso ) -> so . keyex = (short ) ((((long ) (v ) ) >> 1 ) ) ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  v = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  data -> num_params = (((long ) (v ) ) >> 1 ) ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  data -> max_let_depth = (((long ) ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ) ) >> 1 ) ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  data -> name = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  if (((data -> name ) == (scheme_null ) ) )
    data -> name = ((void * ) 0 ) ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  v = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  if ((& (data ) -> iso ) -> so . keyex & 2 ) {
    if (! (((long ) (v ) ) & 0x1 ) )
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    data -> closure_size = (((long ) (v ) ) >> 1 ) ; 
    if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    v = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
    obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  }
  data -> code = obj ; 
  if (! ((Scheme_Type ) (scheme_svector_type ) == (Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  if (! ((& (data ) -> iso ) -> so . keyex & 2 ) )
    data -> closure_size = (((Scheme_Simple_Object * ) (v ) ) -> u . svector_val . len ) ; 
  data -> closure_map = (((Scheme_Simple_Object * ) (v ) ) -> u . svector_val . vec ) ; 
  if ((& (data ) -> iso ) -> so . keyex & 8 )
    (& (data ) -> iso ) -> so . keyex -= 8 ; 
  if (((((long ) (data -> code ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (data -> code ) ) -> type ) > _scheme_values_types_ )
    (& (data ) -> iso ) -> so . keyex |= 8 ; 
  if (! data -> closure_size )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_closure (((void * ) 0 ) , (Scheme_Object * ) data , 0 ) )) RET_VALUE_EMPTY_END ; 
  else RET_VALUE_START ((Scheme_Object * ) data ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int mark_closure_info_SIZE (void * p ) {
  return ((sizeof (Closure_Info ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_closure_info_MARK (void * p ) {
  Closure_Info * i = (Closure_Info * ) p ; 
  GC_mark (i -> local_flags ) ; 
  GC_mark (i -> base_closure_map ) ; 
  return ((sizeof (Closure_Info ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_closure_info_FIXUP (void * p ) {
  Closure_Info * i = (Closure_Info * ) p ; 
  GC_fixup (& (i -> local_flags ) ) ; 
  GC_fixup (& (i -> base_closure_map ) ) ; 
  return ((sizeof (Closure_Info ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_dyn_wind_cell_SIZE (void * p ) {
  return ((sizeof (Scheme_Dynamic_Wind_List ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_dyn_wind_cell_MARK (void * p ) {
  Scheme_Dynamic_Wind_List * l = (Scheme_Dynamic_Wind_List * ) p ; 
  GC_mark (l -> dw ) ; 
  GC_mark (l -> next ) ; 
  return ((sizeof (Scheme_Dynamic_Wind_List ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_dyn_wind_cell_FIXUP (void * p ) {
  Scheme_Dynamic_Wind_List * l = (Scheme_Dynamic_Wind_List * ) p ; 
  GC_fixup (& (l -> dw ) ) ; 
  GC_fixup (& (l -> next ) ) ; 
  return ((sizeof (Scheme_Dynamic_Wind_List ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_dyn_wind_info_SIZE (void * p ) {
  return ((sizeof (Dyn_Wind ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_dyn_wind_info_MARK (void * p ) {
  Dyn_Wind * d = (Dyn_Wind * ) p ; 
  GC_mark (d -> pre ) ; 
  GC_mark (d -> act ) ; 
  GC_mark (d -> post ) ; 
  return ((sizeof (Dyn_Wind ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_dyn_wind_info_FIXUP (void * p ) {
  Dyn_Wind * d = (Dyn_Wind * ) p ; 
  GC_fixup (& (d -> pre ) ) ; 
  GC_fixup (& (d -> act ) ) ; 
  GC_fixup (& (d -> post ) ) ; 
  return ((sizeof (Dyn_Wind ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_cont_mark_chain_SIZE (void * p ) {
  return ((sizeof (Scheme_Cont_Mark_Chain ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_cont_mark_chain_MARK (void * p ) {
  Scheme_Cont_Mark_Chain * c = (Scheme_Cont_Mark_Chain * ) p ; 
  GC_mark (c -> key ) ; 
  GC_mark (c -> val ) ; 
  GC_mark (c -> next ) ; 
  return ((sizeof (Scheme_Cont_Mark_Chain ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_cont_mark_chain_FIXUP (void * p ) {
  Scheme_Cont_Mark_Chain * c = (Scheme_Cont_Mark_Chain * ) p ; 
  GC_fixup (& (c -> key ) ) ; 
  GC_fixup (& (c -> val ) ) ; 
  GC_fixup (& (c -> next ) ) ; 
  return ((sizeof (Scheme_Cont_Mark_Chain ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static void register_traversers (void ) {
  GC_register_traversers (scheme_rt_closure_info , mark_closure_info_SIZE , mark_closure_info_MARK , mark_closure_info_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_dyn_wind_cell , mark_dyn_wind_cell_SIZE , mark_dyn_wind_cell_MARK , mark_dyn_wind_cell_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_dyn_wind_info , mark_dyn_wind_info_SIZE , mark_dyn_wind_info_MARK , mark_dyn_wind_info_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_cont_mark_chain_type , mark_cont_mark_chain_SIZE , mark_cont_mark_chain_MARK , mark_cont_mark_chain_FIXUP , 1 , 0 ) ; 
}
