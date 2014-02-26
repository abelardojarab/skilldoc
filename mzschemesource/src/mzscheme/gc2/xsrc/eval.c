#include "precomp.h"
extern void scheme_call_expand_observe (Scheme_Object * obs , int signal , Scheme_Object * argument ) ; 
extern Scheme_Object * scheme_get_expand_observe () ; 
typedef void (* __sighandler_t ) (int ) ; 
extern __sighandler_t signal (int __sig , __sighandler_t __handler ) __attribute__ ((__nothrow__ ) ) ; 
typedef union sigval {
  int sival_int ; 
  void * sival_ptr ; 
}
sigval_t ; 
typedef struct siginfo {
  int si_signo ; 
  int si_errno ; 
  int si_code ; 
  union {
    int _pad [((128 / sizeof (int ) ) - 4 ) ] ; 
    struct {
      __pid_t si_pid ; 
      __uid_t si_uid ; 
    }
    _kill ; 
    struct {
      int si_tid ; 
      int si_overrun ; 
      sigval_t si_sigval ; 
    }
    _timer ; 
    struct {
      __pid_t si_pid ; 
      __uid_t si_uid ; 
      sigval_t si_sigval ; 
    }
    _rt ; 
    struct {
      __pid_t si_pid ; 
      __uid_t si_uid ; 
      int si_status ; 
      __clock_t si_utime ; 
      __clock_t si_stime ; 
    }
    _sigchld ; 
    struct {
      void * si_addr ; 
    }
    _sigfault ; 
    struct {
      long int si_band ; 
      int si_fd ; 
    }
    _sigpoll ; 
  }
  _sifields ; 
}
siginfo_t ; 
enum {
  SI_ASYNCNL = - 60 , SI_TKILL = - 6 , SI_SIGIO , SI_ASYNCIO , SI_MESGQ , SI_TIMER , SI_QUEUE , SI_USER , SI_KERNEL = 0x80 }
; 
enum {
  ILL_ILLOPC = 1 , ILL_ILLOPN , ILL_ILLADR , ILL_ILLTRP , ILL_PRVOPC , ILL_PRVREG , ILL_COPROC , ILL_BADSTK }
; 
enum {
  FPE_INTDIV = 1 , FPE_INTOVF , FPE_FLTDIV , FPE_FLTOVF , FPE_FLTUND , FPE_FLTRES , FPE_FLTINV , FPE_FLTSUB }
; 
enum {
  SEGV_MAPERR = 1 , SEGV_ACCERR }
; 
enum {
  BUS_ADRALN = 1 , BUS_ADRERR , BUS_OBJERR }
; 
enum {
  TRAP_BRKPT = 1 , TRAP_TRACE }
; 
enum {
  CLD_EXITED = 1 , CLD_KILLED , CLD_DUMPED , CLD_TRAPPED , CLD_STOPPED , CLD_CONTINUED }
; 
enum {
  POLL_IN = 1 , POLL_OUT , POLL_MSG , POLL_ERR , POLL_PRI , POLL_HUP }
; 
typedef struct sigevent {
  sigval_t sigev_value ; 
  int sigev_signo ; 
  int sigev_notify ; 
  union {
    int _pad [((64 / sizeof (int ) ) - 4 ) ] ; 
    __pid_t _tid ; 
    struct {
      void (* _function ) (sigval_t ) ; 
      void * _attribute ; 
    }
    _sigev_thread ; 
  }
  _sigev_un ; 
}
sigevent_t ; 
enum {
  SIGEV_SIGNAL = 0 , SIGEV_NONE , SIGEV_THREAD , SIGEV_THREAD_ID = 4 }
; 
struct sigaction {
  union {
    __sighandler_t sa_handler ; 
    void (* sa_sigaction ) (int , siginfo_t * , void * ) ; 
  }
  __sigaction_handler ; 
  __sigset_t sa_mask ; 
  int sa_flags ; 
  void (* sa_restorer ) (void ) ; 
}
; 
extern int sigaction (int __sig , __const struct sigaction * __restrict __act , struct sigaction * __restrict __oact ) __attribute__ ((__nothrow__ ) ) ; 
extern __const char * __const _sys_siglist [65 ] ; 
extern __const char * __const sys_siglist [65 ] ; 
struct sigvec {
  __sighandler_t sv_handler ; 
  int sv_mask ; 
  int sv_flags ; 
}
; 
extern int sigvec (int __sig , __const struct sigvec * __vec , struct sigvec * __ovec ) __attribute__ ((__nothrow__ ) ) ; 
struct _fpreg {
  unsigned short significand [4 ] ; 
  unsigned short exponent ; 
}
; 
struct _fpxreg {
  unsigned short significand [4 ] ; 
  unsigned short exponent ; 
  unsigned short padding [3 ] ; 
}
; 
struct _xmmreg {
  __uint32_t element [4 ] ; 
}
; 
struct _fpstate {
  __uint16_t cwd ; 
  __uint16_t swd ; 
  __uint16_t ftw ; 
  __uint16_t fop ; 
  __uint64_t rip ; 
  __uint64_t rdp ; 
  __uint32_t mxcsr ; 
  __uint32_t mxcr_mask ; 
  struct _fpxreg _st [8 ] ; 
  struct _xmmreg _xmm [16 ] ; 
  __uint32_t padding [24 ] ; 
}
; 
struct sigcontext {
  unsigned long r8 ; 
  unsigned long r9 ; 
  unsigned long r10 ; 
  unsigned long r11 ; 
  unsigned long r12 ; 
  unsigned long r13 ; 
  unsigned long r14 ; 
  unsigned long r15 ; 
  unsigned long rdi ; 
  unsigned long rsi ; 
  unsigned long rbp ; 
  unsigned long rbx ; 
  unsigned long rdx ; 
  unsigned long rax ; 
  unsigned long rcx ; 
  unsigned long rsp ; 
  unsigned long rip ; 
  unsigned long eflags ; 
  unsigned short cs ; 
  unsigned short gs ; 
  unsigned short fs ; 
  unsigned short __pad0 ; 
  unsigned long err ; 
  unsigned long trapno ; 
  unsigned long oldmask ; 
  unsigned long cr2 ; 
  struct _fpstate * fpstate ; 
  unsigned long __reserved1 [8 ] ; 
}
; 
struct sigstack {
  void * ss_sp ; 
  int ss_onstack ; 
}
; 
enum {
  SS_ONSTACK = 1 , SS_DISABLE }
; 
typedef struct sigaltstack {
  void * ss_sp ; 
  int ss_flags ; 
  size_t ss_size ; 
}
stack_t ; 
extern int sigstack (struct sigstack * __ss , struct sigstack * __oss ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__deprecated__ ) ) ; 
extern int sigaltstack (__const struct sigaltstack * __restrict __ss , struct sigaltstack * __restrict __oss ) __attribute__ ((__nothrow__ ) ) ; 
struct timezone {
  int tz_minuteswest ; 
  int tz_dsttime ; 
}
; 
typedef struct timezone * __restrict __timezone_ptr_t ; 
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
extern int getrlimit (__rlimit_resource_t __resource , struct rlimit * __rlimits ) __attribute__ ((__nothrow__ ) ) ; 
Scheme_Object * scheme_eval_waiting ; 
Scheme_Object * scheme_multiple_values ; 
int scheme_continuation_application_count ; 
volatile int scheme_fuel_counter ; 
int scheme_startup_use_jit = 1 ; 
void scheme_set_startup_use_jit (int v ) {
  /* No conversion */
  scheme_startup_use_jit = v ; 
}
static Scheme_Object * app_symbol ; 
static Scheme_Object * datum_symbol ; 
static Scheme_Object * top_symbol ; 
static Scheme_Object * top_level_symbol ; 
static Scheme_Object * app_expander ; 
static Scheme_Object * datum_expander ; 
static Scheme_Object * top_expander ; 
static Scheme_Object * stop_expander ; 
static Scheme_Object * quick_stx ; 
static int taking_shortcut ; 
Scheme_Object * scheme_stack_dump_key ; 
static Scheme_Object * eval (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * compile (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * compiled_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * expand (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * local_expand (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * local_expand_expr (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * local_expand_catch_lifts (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * local_transformer_expand (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * local_transformer_expand_catch_lifts (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * local_eval (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * expand_once (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * expand_to_top_form (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * enable_break (int , Scheme_Object * [] ) ; 
static Scheme_Object * current_eval (int argc , Scheme_Object * [] ) ; 
static Scheme_Object * current_compile (int argc , Scheme_Object * [] ) ; 
static Scheme_Object * eval_stx (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * compile_stx (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * expand_stx (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * expand_stx_once (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * expand_stx_to_top_form (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * top_introduce_stx (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * allow_set_undefined (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * compile_module_constants (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * use_jit (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * app_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
static Scheme_Object * app_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
static Scheme_Object * datum_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
static Scheme_Object * datum_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
static Scheme_Object * top_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
static Scheme_Object * top_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
static Scheme_Object * write_application (Scheme_Object * obj ) ; 
static Scheme_Object * read_application (Scheme_Object * obj ) ; 
static Scheme_Object * write_sequence (Scheme_Object * obj ) ; 
static Scheme_Object * read_sequence (Scheme_Object * obj ) ; 
static Scheme_Object * read_sequence_save_first (Scheme_Object * obj ) ; 
static Scheme_Object * write_branch (Scheme_Object * obj ) ; 
static Scheme_Object * read_branch (Scheme_Object * obj ) ; 
static Scheme_Object * write_with_cont_mark (Scheme_Object * obj ) ; 
static Scheme_Object * read_with_cont_mark (Scheme_Object * obj ) ; 
static Scheme_Object * write_syntax (Scheme_Object * obj ) ; 
static Scheme_Object * read_syntax (Scheme_Object * obj ) ; 
static Scheme_Object * write_quote_syntax (Scheme_Object * obj ) ; 
static Scheme_Object * read_quote_syntax (Scheme_Object * obj ) ; 
static Scheme_Object * define_values_symbol , * letrec_values_symbol , * lambda_symbol ; 
static Scheme_Object * unknown_symbol , * void_link_symbol , * quote_symbol ; 
static Scheme_Object * letrec_syntaxes_symbol , * begin_symbol ; 
static Scheme_Object * let_values_symbol ; 
static Scheme_Object * internal_define_symbol ; 
static Scheme_Object * module_symbol ; 
static Scheme_Object * module_begin_symbol ; 
static Scheme_Object * expression_symbol ; 
static Scheme_Object * protected_symbol ; 
static Scheme_Object * zero_rands_ptr ; 
int scheme_overflow_count ; 
static Scheme_Object * scheme_compile_expand_expr (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Expand_Info * rec , int drec , int app_position ) ; 
static Scheme_Object * _eval_compiled_multi_with_prompt (Scheme_Object * obj , Scheme_Env * env ) ; 
typedef void (* DW_PrePost_Proc ) (void * ) ; 
unsigned long scheme_stack_boundary ; 
static void register_traversers (void ) ; 
enum {
  SCHEME_EVAL_CONSTANT = 0 , SCHEME_EVAL_GLOBAL , SCHEME_EVAL_LOCAL , SCHEME_EVAL_LOCAL_UNBOX , SCHEME_EVAL_GENERAL }
; 
void scheme_init_eval (Scheme_Env * env ) {
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
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(env, 0)));
# define XfOrM2_COUNT (1)
# define SETUP_XfOrM2(x) SETUP(XfOrM2_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM2(_), register_traversers () ); 
  scheme_eval_waiting = ((Scheme_Object * ) 0x2 ) ; 
  scheme_multiple_values = ((Scheme_Object * ) 0x6 ) ; 
  FUNCCALL(SETUP_XfOrM2(_), scheme_register_static ((void * ) & define_values_symbol , sizeof (define_values_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & letrec_values_symbol , sizeof (letrec_values_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & lambda_symbol , sizeof (lambda_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & unknown_symbol , sizeof (unknown_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & void_link_symbol , sizeof (void_link_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & quote_symbol , sizeof (quote_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & letrec_syntaxes_symbol , sizeof (letrec_syntaxes_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & begin_symbol , sizeof (begin_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & let_values_symbol , sizeof (let_values_symbol ) ) ); 
  define_values_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("define-values" ) ); 
  letrec_values_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("letrec-values" ) ); 
  let_values_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("let-values" ) ); 
  lambda_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("lambda" ) ); 
  unknown_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("unknown" ) ); 
  void_link_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("-v" ) ); 
  quote_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("quote" ) ); 
  letrec_syntaxes_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("letrec-syntaxes+values" ) ); 
  begin_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("begin" ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & module_symbol , sizeof (module_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & module_begin_symbol , sizeof (module_begin_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & internal_define_symbol , sizeof (internal_define_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & expression_symbol , sizeof (expression_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & top_level_symbol , sizeof (top_level_symbol ) ) ); 
  module_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("module" ) ); 
  module_begin_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("module-begin" ) ); 
  internal_define_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("internal-define" ) ); 
  expression_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("expression" ) ); 
  top_level_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("top-level" ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & protected_symbol , sizeof (protected_symbol ) ) ); 
  protected_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("protected" ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_stack_dump_key , sizeof (scheme_stack_dump_key ) ) ); 
  scheme_stack_dump_key = FUNCCALL_AGAIN(scheme_make_symbol ("stk" ) ); 
  FUNCCALL_AGAIN(scheme_install_type_writer (scheme_application_type , write_application ) ); 
  FUNCCALL_AGAIN(scheme_install_type_reader (scheme_application_type , read_application ) ); 
  FUNCCALL_AGAIN(scheme_install_type_writer (scheme_application2_type , write_application ) ); 
  FUNCCALL_AGAIN(scheme_install_type_reader (scheme_application2_type , read_application ) ); 
  FUNCCALL_AGAIN(scheme_install_type_writer (scheme_application3_type , write_application ) ); 
  FUNCCALL_AGAIN(scheme_install_type_reader (scheme_application3_type , read_application ) ); 
  FUNCCALL_AGAIN(scheme_install_type_writer (scheme_sequence_type , write_sequence ) ); 
  FUNCCALL_AGAIN(scheme_install_type_reader (scheme_sequence_type , read_sequence ) ); 
  FUNCCALL_AGAIN(scheme_install_type_writer (scheme_branch_type , write_branch ) ); 
  FUNCCALL_AGAIN(scheme_install_type_reader (scheme_branch_type , read_branch ) ); 
  FUNCCALL_AGAIN(scheme_install_type_writer (scheme_with_cont_mark_type , write_with_cont_mark ) ); 
  FUNCCALL_AGAIN(scheme_install_type_reader (scheme_with_cont_mark_type , read_with_cont_mark ) ); 
  FUNCCALL_AGAIN(scheme_install_type_writer (scheme_quote_syntax_type , write_quote_syntax ) ); 
  FUNCCALL_AGAIN(scheme_install_type_reader (scheme_quote_syntax_type , read_quote_syntax ) ); 
  FUNCCALL_AGAIN(scheme_install_type_writer (scheme_syntax_type , write_syntax ) ); 
  FUNCCALL_AGAIN(scheme_install_type_reader (scheme_syntax_type , read_syntax ) ); 
  FUNCCALL_AGAIN(scheme_install_type_writer (scheme_begin0_sequence_type , write_sequence ) ); 
  FUNCCALL_AGAIN(scheme_install_type_reader (scheme_begin0_sequence_type , read_sequence_save_first ) ); 
  (__funcarg27 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_everything (eval , 0 , "eval" , 1 , 2 , 0 , 0 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("eval" , __funcarg27 , env ) )) ; 
  (__funcarg26 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_everything (eval_stx , 0 , "eval-syntax" , 1 , 2 , 0 , 0 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("eval-syntax" , __funcarg26 , env ) )) ; 
  (__funcarg25 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (compile , "compile" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("compile" , __funcarg25 , env ) )) ; 
  (__funcarg24 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (compile_stx , "compile-syntax" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("compile-syntax" , __funcarg24 , env ) )) ; 
  (__funcarg23 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (compiled_p , "compiled-expression?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("compiled-expression?" , __funcarg23 , env ) )) ; 
  (__funcarg22 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (expand , "expand" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("expand" , __funcarg22 , env ) )) ; 
  (__funcarg21 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (expand_stx , "expand-syntax" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("expand-syntax" , __funcarg21 , env ) )) ; 
  (__funcarg20 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (local_expand , "local-expand" , 3 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("local-expand" , __funcarg20 , env ) )) ; 
  (__funcarg19 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (local_expand_expr , "syntax-local-expand-expression" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("syntax-local-expand-expression" , __funcarg19 , env ) )) ; 
  (__funcarg18 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (local_eval , "syntax-local-bind-syntaxes" , 3 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("syntax-local-bind-syntaxes" , __funcarg18 , env ) )) ; 
  (__funcarg17 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (local_expand_catch_lifts , "local-expand/capture-lifts" , 3 , 5 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("local-expand/capture-lifts" , __funcarg17 , env ) )) ; 
  (__funcarg16 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (local_transformer_expand , "local-transformer-expand" , 3 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("local-transformer-expand" , __funcarg16 , env ) )) ; 
  (__funcarg15 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (local_transformer_expand_catch_lifts , "local-transformer-expand/capture-lifts" , 3 , 5 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("local-transformer-expand/capture-lifts" , __funcarg15 , env ) )) ; 
  (__funcarg14 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (expand_once , "expand-once" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("expand-once" , __funcarg14 , env ) )) ; 
  (__funcarg13 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (expand_stx_once , "expand-syntax-once" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("expand-syntax-once" , __funcarg13 , env ) )) ; 
  (__funcarg12 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (expand_to_top_form , "expand-to-top-form" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("expand-to-top-form" , __funcarg12 , env ) )) ; 
  (__funcarg11 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (expand_stx_to_top_form , "expand-syntax-to-top-form" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("expand-syntax-to-top-form" , __funcarg11 , env ) )) ; 
  (__funcarg10 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (top_introduce_stx , "namespace-syntax-introduce" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("namespace-syntax-introduce" , __funcarg10 , env ) )) ; 
  (__funcarg9 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (enable_break , "break-enabled" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("break-enabled" , __funcarg9 , env ) )) ; 
  (__funcarg8 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (current_eval , "current-eval" , MZCONFIG_EVAL_HANDLER ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-eval" , __funcarg8 , env ) )) ; 
  (__funcarg7 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (current_compile , "current-compile" , MZCONFIG_COMPILE_HANDLER ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-compile" , __funcarg7 , env ) )) ; 
  (__funcarg6 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (allow_set_undefined , "compile-allow-set!-undefined" , MZCONFIG_ALLOW_SET_UNDEFINED ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("compile-allow-set!-undefined" , __funcarg6 , env ) )) ; 
  (__funcarg5 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (compile_module_constants , "compile-enforce-module-constants" , MZCONFIG_COMPILE_MODULE_CONSTS ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("compile-enforce-module-constants" , __funcarg5 , env ) )) ; 
  (__funcarg4 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (use_jit , "eval-jit-enabled" , MZCONFIG_USE_JIT ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("eval-jit-enabled" , __funcarg4 , env ) )) ; 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & app_symbol , sizeof (app_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & datum_symbol , sizeof (datum_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & top_symbol , sizeof (top_symbol ) ) ); 
  app_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("#%app" ) ); 
  datum_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("#%datum" ) ); 
  top_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("#%top" ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & app_expander , sizeof (app_expander ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & datum_expander , sizeof (datum_expander ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & top_expander , sizeof (top_expander ) ) ); 
  app_expander = FUNCCALL_AGAIN(scheme_make_compiled_syntax (app_syntax , app_expand ) ); 
  FUNCCALL_AGAIN(scheme_add_global_keyword ("#%app" , app_expander , env ) ); 
  datum_expander = FUNCCALL_AGAIN(scheme_make_compiled_syntax (datum_syntax , datum_expand ) ); 
  FUNCCALL_AGAIN(scheme_add_global_keyword ("#%datum" , datum_expander , env ) ); 
  top_expander = FUNCCALL_AGAIN(scheme_make_compiled_syntax (top_syntax , top_expand ) ); 
  FUNCCALL_EMPTY(scheme_add_global_keyword ("#%top" , top_expander , env ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & quick_stx , sizeof (quick_stx ) ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_handle_stack_overflow (Scheme_Object * (* k ) (void ) ) {
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Overflow * overflow ; 
  Scheme_Overflow_Jmp * jmp ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(overflow, 0), PUSH(jmp, 1), PUSH(p, 2)));
# define XfOrM3_COUNT (3)
# define SETUP_XfOrM3(x) SETUP(XfOrM3_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  overflow = NULLED_OUT ; 
  jmp = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM3(_), scheme_about_to_move_C_stack () ); 
  (scheme_current_thread -> overflow_k ) = k ; 
  scheme_overflow_count ++ ; 
  overflow = ((Scheme_Overflow * ) FUNCCALL(SETUP_XfOrM3(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Overflow ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  overflow -> type = scheme_rt_overflow ; 
  overflow -> prev = scheme_current_thread -> overflow ; 
  overflow -> stack_start = p -> stack_start ; 
  p -> overflow = overflow ; 
  jmp = ((Scheme_Overflow_Jmp * ) FUNCCALL(SETUP_XfOrM3(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Overflow_Jmp ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  jmp -> type = scheme_rt_overflow_jmp ; 
  overflow -> jmp = jmp ; 
  FUNCCALL(SETUP_XfOrM3(_), scheme_init_jmpup_buf (& overflow -> jmp -> cont ) ); 
  FUNCCALL_AGAIN(scheme_zero_unneeded_rands (scheme_current_thread ) ); 
  if (FUNCCALL(SETUP_XfOrM3(_), scheme_setjmpup_relative (& overflow -> jmp -> cont , overflow -> jmp , (p -> stack_start ) , ((void * ) 0 ) ) )) {
#   define XfOrM5_COUNT (0+XfOrM3_COUNT)
#   define SETUP_XfOrM5(x) SETUP_XfOrM3(x)
    p = scheme_current_thread ; 
    overflow = p -> overflow ; 
    p -> overflow = overflow -> prev ; 
    p -> error_buf = overflow -> jmp -> savebuf ; 
    if (! overflow -> jmp -> captured )
      FUNCCALL(SETUP_XfOrM5(_), scheme_reset_jmpup_buf (& overflow -> jmp -> cont ) ); 
    if (! (scheme_current_thread -> overflow_reply ) ) {
#     define XfOrM7_COUNT (0+XfOrM5_COUNT)
#     define SETUP_XfOrM7(x) SETUP_XfOrM5(x)
      if (p -> cjs . jumping_to_continuation && p -> cjs . is_escape ) {
        Scheme_Prompt * prompt = (Scheme_Prompt * ) p -> cjs . jumping_to_continuation ; 
        (((long * ) (void * ) ((* prompt -> prompt_buf ) . gcvs ) ) [1 ] = (* prompt -> prompt_buf ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* prompt -> prompt_buf ) . gcvs , scheme_jit_longjmp ((* prompt -> prompt_buf ) . jb , 1 ) ) ; 
      }
      else if (p -> cjs . jumping_to_continuation && ((Scheme_Type ) (((((long ) (p -> cjs . jumping_to_continuation ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p -> cjs . jumping_to_continuation ) ) -> type ) ) == (Scheme_Type ) (scheme_cont_type ) ) ) {
        Scheme_Cont * c = (Scheme_Cont * ) p -> cjs . jumping_to_continuation ; 
        BLOCK_SETUP((PUSH(c, 0+XfOrM7_COUNT)));
#       define XfOrM9_COUNT (1+XfOrM7_COUNT)
#       define SETUP_XfOrM9(x) SETUP(XfOrM9_COUNT)
        p -> cjs . jumping_to_continuation = ((void * ) 0 ) ; 
        FUNCCALL(SETUP_XfOrM9(_), scheme_longjmpup (& c -> buf ) ); 
      }
      else {
        (((long * ) (void * ) ((* (scheme_current_thread -> error_buf ) ) . gcvs ) ) [1 ] = (* (scheme_current_thread -> error_buf ) ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* (scheme_current_thread -> error_buf ) ) . gcvs , scheme_jit_longjmp ((* (scheme_current_thread -> error_buf ) ) . jb , 1 ) ) ; 
      }
    }
    else {
      Scheme_Object * reply = (scheme_current_thread -> overflow_reply ) ; 
      (scheme_current_thread -> overflow_reply ) = ((void * ) 0 ) ; 
      RET_VALUE_START (reply ) RET_VALUE_END ; 
    }
  }
  else {
#   define XfOrM4_COUNT (0+XfOrM3_COUNT)
#   define SETUP_XfOrM4(x) SETUP_XfOrM3(x)
    p -> stack_start = scheme_overflow_stack_start ; 
    FUNCCALL(SETUP_XfOrM4(_), scheme_longjmpup (& scheme_overflow_jmp -> cont ) ); 
  }
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_init_stack_check () {
  int * v , stack_grows_up ; 
  unsigned long deeper ; 
  struct rlimit rl ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(v, 0)));
# define XfOrM11_COUNT (1)
# define SETUP_XfOrM11(x) SETUP(XfOrM11_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  deeper = FUNCCALL(SETUP_XfOrM11(_), scheme_get_deeper_address () ); 
  stack_grows_up = (deeper > (unsigned long ) & v ) ; 
  if (stack_grows_up ) {
#   define XfOrM14_COUNT (0+XfOrM11_COUNT)
#   define SETUP_XfOrM14(x) SETUP_XfOrM11(x)
    if (scheme_console_printf )
      FUNCCALL(SETUP_XfOrM14(_), scheme_console_printf ("Stack grows UP, not DOWN.\n" ) ); 
    else (printf ("Stack grows UP, not DOWN.\n" ) ) ; 
    FUNCCALL(SETUP_XfOrM14(_), exit (1 ) ); 
  }
  if (! scheme_stack_boundary ) {
#   define XfOrM12_COUNT (0+XfOrM11_COUNT)
#   define SETUP_XfOrM12(x) SETUP_XfOrM11(x)
    FUNCCALL(SETUP_XfOrM12(_), getrlimit (RLIMIT_STACK , & rl ) ); 
    {
      unsigned long bnd , lim ; 
#     define XfOrM13_COUNT (0+XfOrM12_COUNT)
#     define SETUP_XfOrM13(x) SETUP_XfOrM12(x)
      bnd = (unsigned long ) FUNCCALL(SETUP_XfOrM13(_), scheme_get_stack_base () ); 
      lim = (unsigned long ) rl . rlim_cur ; 
      if (lim > 8388608 )
        lim = 8388608 ; 
      if (stack_grows_up )
        bnd += (lim - 50000 ) ; 
      else bnd += (50000 - lim ) ; 
      scheme_stack_boundary = bnd ; 
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_check_runstack (long size ) {
  /* No conversion */
  return ((scheme_current_runstack - scheme_current_runstack_start ) >= (size + 5 ) ) ; 
}
void * scheme_enlarge_runstack (long size , void * (* k ) () ) {
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Saved_Stack * saved ; 
  void * v ; 
  int cont_count ; 
  volatile int escape ; 
  mz_jmp_buf newbuf , * volatile savebuf ; 
  DECL_RET_SAVE (void * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(p, 1), PUSH(saved, 2), PUSH(savebuf, 3)));
# define XfOrM16_COUNT (4)
# define SETUP_XfOrM16(x) SETUP(XfOrM16_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  saved = NULLED_OUT ; 
  v = NULLED_OUT ; 
  savebuf = NULLED_OUT ; 
  saved = ((Scheme_Saved_Stack * ) FUNCCALL(SETUP_XfOrM16(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Saved_Stack ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  saved -> type = scheme_rt_saved_stack ; 
  saved -> prev = p -> runstack_saved ; 
  saved -> runstack_start = scheme_current_runstack_start ; 
  saved -> runstack_offset = (scheme_current_runstack - scheme_current_runstack_start ) ; 
  saved -> runstack_size = p -> runstack_size ; 
  size += 5 ; 
  if (size ) {
    long min_size ; 
    min_size = 2 * (p -> runstack_size ) ; 
    if (min_size > 128000 )
      min_size = 128000 ; 
    if (size < min_size )
      size = min_size ; 
  }
  else {
    size = p -> runstack_size ; 
    if (size > 1000 )
      size = 1000 ; 
  }
  if (p -> spare_runstack && (size <= p -> spare_runstack_size ) ) {
    size = p -> spare_runstack_size ; 
    scheme_current_runstack_start = p -> spare_runstack ; 
    p -> spare_runstack = ((void * ) 0 ) ; 
  }
  else {
#   define XfOrM22_COUNT (0+XfOrM16_COUNT)
#   define SETUP_XfOrM22(x) SETUP_XfOrM16(x)
    scheme_current_runstack_start = FUNCCALL(SETUP_XfOrM22(_), scheme_alloc_runstack (size ) ); 
  }
  p -> runstack_size = size ; 
  scheme_current_runstack = scheme_current_runstack_start + size ; 
  p -> runstack_saved = saved ; 
  cont_count = scheme_cont_capture_count ; 
  savebuf = p -> error_buf ; 
  p -> error_buf = & newbuf ; 
  if (((newbuf ) . gcvs = (long ) __gc_var_stack__ , (newbuf ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((newbuf ) . jb ) , (_setjmp (((newbuf ) . jb ) -> jb ) ) ) ) ) {
    v = ((void * ) 0 ) ; 
    escape = 1 ; 
    p = scheme_current_thread ; 
  }
  else {
#   define XfOrM18_COUNT (0+XfOrM16_COUNT)
#   define SETUP_XfOrM18(x) SETUP_XfOrM16(x)
    v = FUNCCALL(SETUP_XfOrM18(_), k () ); 
    escape = 0 ; 
    p = scheme_current_thread ; 
    if (cont_count == scheme_cont_capture_count ) {
      if (! p -> spare_runstack || (p -> runstack_size > p -> spare_runstack_size ) ) {
        p -> spare_runstack = scheme_current_runstack_start ; 
        p -> spare_runstack_size = p -> runstack_size ; 
      }
    }
  }
  p -> error_buf = savebuf ; 
  saved = p -> runstack_saved ; 
  p -> runstack_saved = saved -> prev ; 
  scheme_current_runstack_start = saved -> runstack_start ; 
  scheme_current_runstack = scheme_current_runstack_start + saved -> runstack_offset ; 
  p -> runstack_size = saved -> runstack_size ; 
  if (escape ) {
    (((long * ) (void * ) ((* p -> error_buf ) . gcvs ) ) [1 ] = (* p -> error_buf ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* p -> error_buf ) . gcvs , scheme_jit_longjmp ((* p -> error_buf ) . jb , 1 ) ) ; 
  }
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_omittable_expr (Scheme_Object * o , int vals ) {
  Scheme_Type vtype ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(o, 0)));
# define XfOrM26_COUNT (1)
# define SETUP_XfOrM26(x) SETUP(XfOrM26_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  try_again : vtype = ((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ; 
  if ((vtype > _scheme_compiled_values_types_ ) || (vtype == scheme_local_type ) || (vtype == scheme_local_unbox_type ) || (vtype == scheme_unclosed_procedure_type ) || (vtype == scheme_compiled_unclosed_procedure_type ) || (vtype == scheme_case_lambda_sequence_type ) || (vtype == scheme_quote_syntax_type ) || (vtype == scheme_compiled_quote_syntax_type ) )
    RET_VALUE_START (((vals == 1 ) || (vals < 0 ) ) ) RET_VALUE_END ; 
  if ((vtype == scheme_compiled_quote_syntax_type ) ) {
    RET_VALUE_START (((vals == 1 ) || (vals < 0 ) ) ) RET_VALUE_END ; 
  }
  if ((vtype == scheme_branch_type ) ) {
    Scheme_Branch_Rec * b ; 
    BLOCK_SETUP((PUSH(b, 0+XfOrM26_COUNT)));
#   define XfOrM43_COUNT (1+XfOrM26_COUNT)
#   define SETUP_XfOrM43(x) SETUP(XfOrM43_COUNT)
    b = NULLED_OUT ; 
    b = (Scheme_Branch_Rec * ) o ; 
    RET_VALUE_START ((FUNCCALL(SETUP_XfOrM43(_), scheme_omittable_expr (b -> test , 1 ) )&& FUNCCALL(SETUP_XfOrM43(_), scheme_omittable_expr (b -> tbranch , vals ) )&& FUNCCALL(SETUP_XfOrM43(_), scheme_omittable_expr (b -> fbranch , vals ) )) ) RET_VALUE_END ; 
  }
  if ((vtype == scheme_let_one_type ) ) {
    Scheme_Let_One * lo = (Scheme_Let_One * ) o ; 
    BLOCK_SETUP((PUSH(lo, 0+XfOrM26_COUNT)));
#   define XfOrM42_COUNT (1+XfOrM26_COUNT)
#   define SETUP_XfOrM42(x) SETUP(XfOrM42_COUNT)
    RET_VALUE_START ((FUNCCALL(SETUP_XfOrM42(_), scheme_omittable_expr (lo -> value , 1 ) )&& FUNCCALL(SETUP_XfOrM42(_), scheme_omittable_expr (lo -> body , vals ) )) ) RET_VALUE_END ; 
  }
  if ((vtype == scheme_let_void_type ) ) {
    o = ((Scheme_Let_Void * ) o ) -> body ; 
    goto try_again ; 
  }
  if ((vtype == scheme_letrec_type ) ) {
    o = ((Scheme_Letrec * ) o ) -> body ; 
    goto try_again ; 
  }
  if ((vtype == scheme_application_type ) ) {
    Scheme_App_Rec * app = (Scheme_App_Rec * ) o ; 
    BLOCK_SETUP((PUSH(app, 0+XfOrM26_COUNT)));
#   define XfOrM33_COUNT (1+XfOrM26_COUNT)
#   define SETUP_XfOrM33(x) SETUP(XfOrM33_COUNT)
    if (((vals == 5 ) || (vals < 0 ) ) && (app -> num_args >= 4 ) && (app -> num_args <= 10 ) && ((scheme_make_struct_type_proc ) == (app -> args [0 ] ) ) ) {
#     define XfOrM38_COUNT (0+XfOrM33_COUNT)
#     define SETUP_XfOrM38(x) SETUP_XfOrM33(x)
      if (((Scheme_Type ) (((((long ) (app -> args [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (app -> args [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) && (((app -> args [2 ] ) ) == (scheme_false ) ) && (((long ) (app -> args [3 ] ) ) & 0x1 ) && ((((long ) (app -> args [3 ] ) ) >> 1 ) >= 0 ) && (((long ) (app -> args [4 ] ) ) & 0x1 ) && ((((long ) (app -> args [4 ] ) ) >> 1 ) >= 0 ) && ((app -> num_args < 5 ) || FUNCCALL(SETUP_XfOrM38(_), scheme_omittable_expr (app -> args [5 ] , 1 ) )) && ((app -> num_args < 6 ) || ((app -> args [6 ] ) == (scheme_null ) ) ) && ((app -> num_args < 7 ) || (((app -> args [7 ] ) ) == (scheme_false ) ) ) && ((app -> num_args < 8 ) || (((app -> args [8 ] ) ) == (scheme_false ) ) ) && ((app -> num_args < 9 ) || ((app -> args [9 ] ) == (scheme_null ) ) ) ) {
        RET_VALUE_START (1 ) RET_VALUE_END ; 
      }
    }
    if ((app -> num_args == vals ) || (vals < 0 ) ) {
#     define XfOrM34_COUNT (0+XfOrM33_COUNT)
#     define SETUP_XfOrM34(x) SETUP_XfOrM33(x)
      if (((scheme_values_func ) == (app -> args [0 ] ) ) ) {
        int i ; 
#       define XfOrM35_COUNT (0+XfOrM34_COUNT)
#       define SETUP_XfOrM35(x) SETUP_XfOrM34(x)
        for (i = app -> num_args ; i -- ; ) {
#         define XfOrM37_COUNT (0+XfOrM35_COUNT)
#         define SETUP_XfOrM37(x) SETUP_XfOrM35(x)
          if (! FUNCCALL(SETUP_XfOrM37(_), scheme_omittable_expr (app -> args [i + 1 ] , 1 ) ))
            RET_VALUE_START (0 ) RET_VALUE_END ; 
        }
        RET_VALUE_START (1 ) RET_VALUE_END ; 
      }
    }
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  if ((vtype == scheme_application2_type ) ) {
#   define XfOrM30_COUNT (0+XfOrM26_COUNT)
#   define SETUP_XfOrM30(x) SETUP_XfOrM26(x)
    if ((vals == 1 ) || (vals < 0 ) ) {
      Scheme_App2_Rec * app = (Scheme_App2_Rec * ) o ; 
#     define XfOrM31_COUNT (0+XfOrM30_COUNT)
#     define SETUP_XfOrM31(x) SETUP_XfOrM30(x)
      if (((scheme_values_func ) == (app -> rator ) ) ) {
#       define XfOrM32_COUNT (0+XfOrM31_COUNT)
#       define SETUP_XfOrM32(x) SETUP_XfOrM31(x)
        if (FUNCCALL(SETUP_XfOrM32(_), scheme_omittable_expr (app -> rand , 1 ) ))
          RET_VALUE_START (1 ) RET_VALUE_END ; 
      }
    }
  }
  if ((vtype == scheme_application3_type ) ) {
#   define XfOrM27_COUNT (0+XfOrM26_COUNT)
#   define SETUP_XfOrM27(x) SETUP_XfOrM26(x)
    if ((vals == 2 ) || (vals < 0 ) ) {
      Scheme_App3_Rec * app = (Scheme_App3_Rec * ) o ; 
      BLOCK_SETUP((PUSH(app, 0+XfOrM27_COUNT)));
#     define XfOrM28_COUNT (1+XfOrM27_COUNT)
#     define SETUP_XfOrM28(x) SETUP(XfOrM28_COUNT)
      if (((scheme_values_func ) == (app -> rator ) ) ) {
#       define XfOrM29_COUNT (0+XfOrM28_COUNT)
#       define SETUP_XfOrM29(x) SETUP_XfOrM28(x)
        if (FUNCCALL(SETUP_XfOrM29(_), scheme_omittable_expr (app -> rand1 , 1 ) )&& FUNCCALL_EMPTY(scheme_omittable_expr (app -> rand2 , 1 ) ))
          RET_VALUE_START (1 ) RET_VALUE_END ; 
      }
    }
  }
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_is_compiled_procedure (Scheme_Object * o , int can_be_closed , int can_be_liftable ) {
  /* No conversion */
  if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_compiled_unclosed_procedure_type ) ) ) {
    if (! can_be_closed || ! can_be_liftable ) {
      Scheme_Closure_Data * data ; 
      data = (Scheme_Closure_Data * ) o ; 
      if (! can_be_closed && ! data -> closure_size )
        return 0 ; 
      if (! can_be_liftable && (data -> closure_size == 1 ) && scheme_closure_has_top_level (data ) )
        return 0 ; 
    }
    return 1 ; 
  }
  else return 0 ; 
}
int scheme_get_eval_type (Scheme_Object * obj ) {
  /* No conversion */
  Scheme_Type type ; 
  type = ((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ; 
  if (type > _scheme_values_types_ )
    return SCHEME_EVAL_CONSTANT ; 
  else if (((Scheme_Type ) (type ) == (Scheme_Type ) (scheme_local_type ) ) )
    return SCHEME_EVAL_LOCAL ; 
  else if (((Scheme_Type ) (type ) == (Scheme_Type ) (scheme_local_unbox_type ) ) )
    return SCHEME_EVAL_LOCAL_UNBOX ; 
  else if (((Scheme_Type ) (type ) == (Scheme_Type ) (scheme_toplevel_type ) ) )
    return SCHEME_EVAL_GLOBAL ; 
  else return SCHEME_EVAL_GENERAL ; 
}
static Scheme_Object * try_apply (Scheme_Object * f , Scheme_Object * args ) {
  Scheme_Object * volatile result ; 
  mz_jmp_buf * savebuf , newbuf ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(args, 0), PUSH(f, 1), PUSH(result, 2), PUSH(savebuf, 3)));
# define XfOrM49_COUNT (4)
# define SETUP_XfOrM49(x) SETUP(XfOrM49_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  result = NULLED_OUT ; 
  savebuf = NULLED_OUT ; 
  scheme_current_thread -> skip_error = 5 ; 
  savebuf = scheme_current_thread -> error_buf ; 
  scheme_current_thread -> error_buf = & newbuf ; 
  if (((newbuf ) . gcvs = (long ) __gc_var_stack__ , (newbuf ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((newbuf ) . jb ) , (_setjmp (((newbuf ) . jb ) -> jb ) ) ) ) )
    result = ((void * ) 0 ) ; 
  else result = FUNCCALL(SETUP_XfOrM49(_), _scheme_apply_to_list (f , args ) ); 
  scheme_current_thread -> error_buf = savebuf ; 
  scheme_current_thread -> skip_error = 0 ; 
  RET_VALUE_START (result ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_application (Scheme_Object * v ) {
  Scheme_Object * o ; 
  int i , nv ; 
  volatile int n ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(v, 0)));
# define XfOrM50_COUNT (1)
# define SETUP_XfOrM50(x) SETUP(XfOrM50_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  o = NULLED_OUT ; 
  o = v ; 
  n = 0 ; 
  nv = 0 ; 
  while (! ((o ) == (scheme_null ) ) ) {
    Scheme_Type type ; 
    n ++ ; 
    type = ((((long ) ((((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . car ) ) ) -> type ) ; 
    if (type < _scheme_compiled_values_types_ )
      nv = 1 ; 
    o = (((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . cdr ) ; 
  }
  if (! nv ) {
    Scheme_Object * f ; 
    BLOCK_SETUP((PUSH(f, 0+XfOrM50_COUNT)));
#   define XfOrM56_COUNT (1+XfOrM50_COUNT)
#   define SETUP_XfOrM56(x) SETUP(XfOrM56_COUNT)
    f = NULLED_OUT ; 
    f = (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) ; 
    if ((((Scheme_Type ) (((((long ) (f ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (f ) ) -> type ) ) == (Scheme_Type ) (scheme_prim_type ) ) && (((Scheme_Primitive_Proc * ) f ) -> pp . flags & 1 ) ) || (((Scheme_Type ) (((((long ) (f ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (f ) ) -> type ) ) == (Scheme_Type ) (scheme_closed_prim_type ) ) && (((Scheme_Closed_Primitive_Proc * ) f ) -> pp . flags & 1 ) ) || (((Scheme_Type ) (((((long ) (f ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (f ) ) -> type ) ) == (Scheme_Type ) (scheme_closure_type ) ) && (((& (((Scheme_Closure * ) f ) -> code ) -> iso ) -> so . keyex ) & 8 ) ) ) {
#     define XfOrM57_COUNT (0+XfOrM56_COUNT)
#     define SETUP_XfOrM57(x) SETUP_XfOrM56(x)
      f = FUNCCALL(SETUP_XfOrM57(_), try_apply (f , (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) ) ); 
      if (f )
        RET_VALUE_START (f ) RET_VALUE_END ; 
    }
  }
  if (n == 2 ) {
    Scheme_App2_Rec * app ; 
    BLOCK_SETUP((PUSH(app, 0+XfOrM50_COUNT)));
#   define XfOrM55_COUNT (1+XfOrM50_COUNT)
#   define SETUP_XfOrM55(x) SETUP(XfOrM55_COUNT)
    app = NULLED_OUT ; 
    app = ((Scheme_App2_Rec * ) FUNCCALL(SETUP_XfOrM55(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_App2_Rec ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    app -> iso . so . type = scheme_application2_type ; 
    app -> rator = (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) ; 
    v = (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) ; 
    app -> rand = (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) ; 
    RET_VALUE_START ((Scheme_Object * ) app ) RET_VALUE_END ; 
  }
  else if (n == 3 ) {
    Scheme_App3_Rec * app ; 
    BLOCK_SETUP((PUSH(app, 0+XfOrM50_COUNT)));
#   define XfOrM54_COUNT (1+XfOrM50_COUNT)
#   define SETUP_XfOrM54(x) SETUP(XfOrM54_COUNT)
    app = NULLED_OUT ; 
    app = ((Scheme_App3_Rec * ) FUNCCALL(SETUP_XfOrM54(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_App3_Rec ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    app -> iso . so . type = scheme_application3_type ; 
    app -> rator = (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) ; 
    v = (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) ; 
    app -> rand1 = (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) ; 
    v = (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) ; 
    app -> rand2 = (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) ; 
    RET_VALUE_START ((Scheme_Object * ) app ) RET_VALUE_END ; 
  }
  else {
    Scheme_App_Rec * app ; 
    BLOCK_SETUP((PUSH(app, 0+XfOrM50_COUNT)));
#   define XfOrM51_COUNT (1+XfOrM50_COUNT)
#   define SETUP_XfOrM51(x) SETUP(XfOrM51_COUNT)
    app = NULLED_OUT ; 
    app = FUNCCALL(SETUP_XfOrM51(_), scheme_malloc_application (n ) ); 
    for (i = 0 ; i < n ; i ++ , v = (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) ) {
      app -> args [i ] = (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) ; 
    }
    RET_VALUE_START ((Scheme_Object * ) app ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_App_Rec * scheme_malloc_application (int n ) {
  Scheme_App_Rec * app ; 
  int size ; 
  DECL_RET_SAVE (Scheme_App_Rec * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(app, 0)));
# define XfOrM60_COUNT (1)
# define SETUP_XfOrM60(x) SETUP(XfOrM60_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  app = NULLED_OUT ; 
  size = (sizeof (Scheme_App_Rec ) + ((n - 1 ) * sizeof (Scheme_Object * ) ) + n * sizeof (char ) ) ; 
  app = (Scheme_App_Rec * ) FUNCCALL(SETUP_XfOrM60(_), GC_malloc_one_tagged (size ) ); 
  app -> so . type = scheme_application_type ; 
  app -> num_args = n - 1 ; 
  RET_VALUE_START (app ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_finish_application (Scheme_App_Rec * app ) {
  int i , devals , n ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(app, 0)));
# define XfOrM61_COUNT (1)
# define SETUP_XfOrM61(x) SETUP(XfOrM61_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  n = app -> num_args + 1 ; 
  devals = sizeof (Scheme_App_Rec ) + (app -> num_args * sizeof (Scheme_Object * ) ) ; 
  for (i = 0 ; i < n ; i ++ ) {
    char etype ; 
#   define XfOrM63_COUNT (0+XfOrM61_COUNT)
#   define SETUP_XfOrM63(x) SETUP_XfOrM61(x)
    etype = FUNCCALL(SETUP_XfOrM63(_), scheme_get_eval_type (app -> args [i ] ) ); 
    ((char * ) app XFORM_OK_PLUS devals ) [i ] = etype ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * check_converted_rator (Scheme_Object * rator , Resolve_Info * info , Scheme_Object * * new_rator , int orig_arg_cnt , int * _rdelta ) {
  Scheme_Object * lifted ; 
  int flags ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(_rdelta, 0), PUSH(lifted, 1), PUSH(new_rator, 2), PUSH(rator, 3)));
# define XfOrM64_COUNT (4)
# define SETUP_XfOrM64(x) SETUP(XfOrM64_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  lifted = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (rator ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rator ) ) -> type ) ) == (Scheme_Type ) (scheme_local_type ) ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  (void ) FUNCCALL(SETUP_XfOrM64(_), scheme_resolve_info_lookup (info , (((Scheme_Local * ) (rator ) ) -> position ) , & flags , & lifted , orig_arg_cnt + 1 ) ); 
  if (lifted && ((Scheme_Type ) (((((long ) (lifted ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lifted ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ) {
    Scheme_Object * vec , * arity ; 
    BLOCK_SETUP((PUSH(arity, 0+XfOrM64_COUNT), PUSH(vec, 1+XfOrM64_COUNT)));
#   define XfOrM65_COUNT (2+XfOrM64_COUNT)
#   define SETUP_XfOrM65(x) SETUP(XfOrM65_COUNT)
    vec = NULLED_OUT ; 
    arity = NULLED_OUT ; 
    * new_rator = (((Scheme_Simple_Object * ) (lifted ) ) -> u . pair_val . car ) ; 
    vec = (((Scheme_Simple_Object * ) (lifted ) ) -> u . pair_val . cdr ) ; 
    * _rdelta = 0 ; 
    if ((((Scheme_Vector * ) (vec ) ) -> size ) > 1 ) {
#     define XfOrM66_COUNT (0+XfOrM65_COUNT)
#     define SETUP_XfOrM66(x) SETUP_XfOrM65(x)
      arity = (((Scheme_Vector * ) (vec ) ) -> els ) [0 ] ; 
      if ((((long ) (arity ) ) & 0x1 ) ) {
        if (orig_arg_cnt == (((long ) (arity ) ) >> 1 ) )
          arity = ((void * ) 0 ) ; 
      }
      else {
#       define XfOrM69_COUNT (0+XfOrM66_COUNT)
#       define SETUP_XfOrM69(x) SETUP_XfOrM66(x)
        arity = (((Scheme_Small_Object * ) (arity ) ) -> u . ptr_val ) ; 
        if (orig_arg_cnt >= (((long ) (arity ) ) >> 1 ) )
          arity = ((void * ) 0 ) ; 
        else {
          Scheme_App2_Rec * app ; 
          BLOCK_SETUP((PUSH(app, 0+XfOrM69_COUNT)));
#         define XfOrM70_COUNT (1+XfOrM69_COUNT)
#         define SETUP_XfOrM70(x) SETUP(XfOrM70_COUNT)
          app = NULLED_OUT ; 
          app = ((Scheme_App2_Rec * ) FUNCCALL(SETUP_XfOrM70(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_App2_Rec ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
          app -> iso . so . type = scheme_application2_type ; 
          app -> rator = scheme_make_arity_at_least ; 
          app -> rand = arity ; 
          arity = (Scheme_Object * ) app ; 
          * _rdelta = 1 ; 
        }
      }
      if (arity ) {
        Scheme_Object * old_rator = * new_rator ; 
        BLOCK_SETUP((PUSH(old_rator, 0+XfOrM66_COUNT)));
#       define XfOrM67_COUNT (1+XfOrM66_COUNT)
#       define SETUP_XfOrM67(x) SETUP(XfOrM67_COUNT)
        if (((Scheme_Type ) (((((long ) (old_rator ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (old_rator ) ) -> type ) ) == (Scheme_Type ) (scheme_toplevel_type ) ) ) {
          int delta ; 
#         define XfOrM68_COUNT (0+XfOrM67_COUNT)
#         define SETUP_XfOrM68(x) SETUP_XfOrM67(x)
          delta = 3 - (((Scheme_Vector * ) (vec ) ) -> size ) ; 
          if (delta )
            old_rator = FUNCCALL(SETUP_XfOrM68(_), scheme_shift_toplevel (old_rator , delta ) ); 
        }
        vec = FUNCCALL(SETUP_XfOrM67(_), scheme_make_vector (3 , ((void * ) 0 ) ) ); 
        (((Scheme_Vector * ) (vec ) ) -> els ) [0 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
        (((Scheme_Vector * ) (vec ) ) -> els ) [1 ] = old_rator ; 
        (((Scheme_Vector * ) (vec ) ) -> els ) [2 ] = arity ; 
        * new_rator = scheme_raise_arity_error_proc ; 
      }
    }
    RET_VALUE_START (vec ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * resolve_application (Scheme_Object * o , Resolve_Info * orig_info , int already_resolved_arg_count ) {
  Resolve_Info * info ; 
  Scheme_App_Rec * app ; 
  int i , n , devals ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(app, 0), PUSH(orig_info, 1), PUSH(info, 2)));
# define XfOrM72_COUNT (3)
# define SETUP_XfOrM72(x) SETUP(XfOrM72_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  info = NULLED_OUT ; 
  app = NULLED_OUT ; 
  app = (Scheme_App_Rec * ) o ; 
  n = app -> num_args + 1 ; 
  if (! already_resolved_arg_count ) {
    Scheme_Object * additions = ((void * ) 0 ) , * rator ; 
    int rdelta ; 
    BLOCK_SETUP((PUSH(additions, 0+XfOrM72_COUNT), PUSH(rator, 1+XfOrM72_COUNT)));
#   define XfOrM81_COUNT (2+XfOrM72_COUNT)
#   define SETUP_XfOrM81(x) SETUP(XfOrM81_COUNT)
    rator = NULLED_OUT ; 
    additions = FUNCCALL(SETUP_XfOrM81(_), check_converted_rator (app -> args [0 ] , orig_info , & rator , n - 1 , & rdelta ) ); 
    if (additions ) {
      Scheme_App_Rec * app2 ; 
      Scheme_Object * loc ; 
      int m ; 
      BLOCK_SETUP((PUSH(loc, 0+XfOrM81_COUNT), PUSH(app2, 1+XfOrM81_COUNT)));
#     define XfOrM82_COUNT (2+XfOrM81_COUNT)
#     define SETUP_XfOrM82(x) SETUP(XfOrM82_COUNT)
      app2 = NULLED_OUT ; 
      loc = NULLED_OUT ; 
      m = (((Scheme_Vector * ) (additions ) ) -> size ) - 1 ; 
      app2 = FUNCCALL(SETUP_XfOrM82(_), scheme_malloc_application (n + m ) ); 
      for (i = 0 ; i < m ; i ++ ) {
        loc = (((Scheme_Vector * ) (additions ) ) -> els ) [i + 1 ] ; 
        if (((Scheme_Type ) (((((long ) (loc ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (loc ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) )
          loc = (((Scheme_Small_Object * ) (loc ) ) -> u . ptr_val ) ; 
        app2 -> args [i + 1 ] = loc ; 
      }
      for (i = 1 ; i < n ; i ++ ) {
        app2 -> args [i + m ] = app -> args [i ] ; 
      }
      app2 -> args [0 ] = rator ; 
      n += m ; 
      app = app2 ; 
      already_resolved_arg_count = m + 1 + rdelta ; 
    }
  }
  devals = sizeof (Scheme_App_Rec ) + ((n - 1 ) * sizeof (Scheme_Object * ) ) ; 
  info = FUNCCALL(SETUP_XfOrM72(_), scheme_resolve_info_extend (orig_info , n - 1 , 0 , 0 ) ); 
  for (i = 0 ; i < n ; i ++ ) {
    Scheme_Object * le ; 
    BLOCK_SETUP((PUSH(le, 0+XfOrM72_COUNT)));
#   define XfOrM78_COUNT (1+XfOrM72_COUNT)
#   define SETUP_XfOrM78(x) SETUP(XfOrM78_COUNT)
    le = NULLED_OUT ; 
    if (already_resolved_arg_count ) {
      already_resolved_arg_count -- ; 
    }
    else {
#     define XfOrM79_COUNT (0+XfOrM78_COUNT)
#     define SETUP_XfOrM79(x) SETUP_XfOrM78(x)
      le = FUNCCALL(SETUP_XfOrM79(_), scheme_resolve_expr (app -> args [i ] , info ) ); 
      app -> args [i ] = le ; 
    }
  }
  info -> max_let_depth += (n - 1 ) ; 
  if (orig_info -> max_let_depth < info -> max_let_depth )
    orig_info -> max_let_depth = info -> max_let_depth ; 
  for (i = 0 ; i < n ; i ++ ) {
    char et ; 
#   define XfOrM74_COUNT (0+XfOrM72_COUNT)
#   define SETUP_XfOrM74(x) SETUP_XfOrM72(x)
    et = FUNCCALL(SETUP_XfOrM74(_), scheme_get_eval_type (app -> args [i ] ) ); 
    ((char * ) app XFORM_OK_PLUS devals ) [i ] = et ; 
  }
  RET_VALUE_START ((Scheme_Object * ) app ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * resolve_application3 (Scheme_Object * o , Resolve_Info * orig_info , int already_resolved_arg_count ) ; 
static Scheme_Object * resolve_application2 (Scheme_Object * o , Resolve_Info * orig_info , int already_resolved_arg_count ) {
  Resolve_Info * info ; 
  Scheme_App2_Rec * app ; 
  Scheme_Object * le ; 
  short et ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(app, 0), PUSH(le, 1), PUSH(orig_info, 2), PUSH(info, 3)));
# define XfOrM87_COUNT (4)
# define SETUP_XfOrM87(x) SETUP(XfOrM87_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  info = NULLED_OUT ; 
  app = NULLED_OUT ; 
  le = NULLED_OUT ; 
  app = (Scheme_App2_Rec * ) o ; 
  if (! already_resolved_arg_count ) {
    Scheme_Object * additions = ((void * ) 0 ) , * rator ; 
    int rdelta ; 
    BLOCK_SETUP((PUSH(additions, 0+XfOrM87_COUNT), PUSH(rator, 1+XfOrM87_COUNT)));
#   define XfOrM90_COUNT (2+XfOrM87_COUNT)
#   define SETUP_XfOrM90(x) SETUP(XfOrM90_COUNT)
    rator = NULLED_OUT ; 
    additions = FUNCCALL(SETUP_XfOrM90(_), check_converted_rator (app -> rator , orig_info , & rator , 1 , & rdelta ) ); 
    if (additions ) {
      int m ; 
#     define XfOrM91_COUNT (0+XfOrM90_COUNT)
#     define SETUP_XfOrM91(x) SETUP_XfOrM90(x)
      m = (((Scheme_Vector * ) (additions ) ) -> size ) - 1 ; 
      if (! m ) {
        app -> rator = rator ; 
        already_resolved_arg_count = 1 + rdelta ; 
      }
      else if (m > 1 ) {
        Scheme_App_Rec * app2 ; 
        Scheme_Object * loc ; 
        int i ; 
        BLOCK_SETUP((PUSH(loc, 0+XfOrM91_COUNT), PUSH(app2, 1+XfOrM91_COUNT)));
#       define XfOrM93_COUNT (2+XfOrM91_COUNT)
#       define SETUP_XfOrM93(x) SETUP(XfOrM93_COUNT)
        app2 = NULLED_OUT ; 
        loc = NULLED_OUT ; 
        app2 = FUNCCALL(SETUP_XfOrM93(_), scheme_malloc_application (2 + m ) ); 
        for (i = 0 ; i < m ; i ++ ) {
          loc = (((Scheme_Vector * ) (additions ) ) -> els ) [i + 1 ] ; 
          if (((Scheme_Type ) (((((long ) (loc ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (loc ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) )
            loc = (((Scheme_Small_Object * ) (loc ) ) -> u . ptr_val ) ; 
          app2 -> args [i + 1 ] = loc ; 
        }
        app2 -> args [0 ] = rator ; 
        app2 -> args [m + 1 ] = app -> rand ; 
        RET_VALUE_START (FUNCCALL(SETUP_XfOrM93(_), resolve_application ((Scheme_Object * ) app2 , orig_info , m + 1 + rdelta ) )) RET_VALUE_END ; 
      }
      else {
        Scheme_App3_Rec * app2 ; 
        Scheme_Object * loc ; 
        BLOCK_SETUP((PUSH(loc, 0+XfOrM91_COUNT), PUSH(app2, 1+XfOrM91_COUNT)));
#       define XfOrM92_COUNT (2+XfOrM91_COUNT)
#       define SETUP_XfOrM92(x) SETUP(XfOrM92_COUNT)
        app2 = NULLED_OUT ; 
        loc = NULLED_OUT ; 
        app2 = ((Scheme_App3_Rec * ) FUNCCALL(SETUP_XfOrM92(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_App3_Rec ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
        app2 -> iso . so . type = scheme_application3_type ; 
        app2 -> rator = rator ; 
        loc = (((Scheme_Vector * ) (additions ) ) -> els ) [1 ] ; 
        if (((Scheme_Type ) (((((long ) (loc ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (loc ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) )
          loc = (((Scheme_Small_Object * ) (loc ) ) -> u . ptr_val ) ; 
        app2 -> rand1 = loc ; 
        app2 -> rand2 = app -> rand ; 
        RET_VALUE_START (FUNCCALL(SETUP_XfOrM92(_), resolve_application3 ((Scheme_Object * ) app2 , orig_info , 2 + rdelta ) )) RET_VALUE_END ; 
      }
    }
  }
  info = FUNCCALL(SETUP_XfOrM87(_), scheme_resolve_info_extend (orig_info , 1 , 0 , 0 ) ); 
  if (! already_resolved_arg_count ) {
#   define XfOrM89_COUNT (0+XfOrM87_COUNT)
#   define SETUP_XfOrM89(x) SETUP_XfOrM87(x)
    le = FUNCCALL(SETUP_XfOrM89(_), scheme_resolve_expr (app -> rator , info ) ); 
    app -> rator = le ; 
  }
  else already_resolved_arg_count -- ; 
  if (! already_resolved_arg_count ) {
#   define XfOrM88_COUNT (0+XfOrM87_COUNT)
#   define SETUP_XfOrM88(x) SETUP_XfOrM87(x)
    le = FUNCCALL(SETUP_XfOrM88(_), scheme_resolve_expr (app -> rand , info ) ); 
    app -> rand = le ; 
  }
  else already_resolved_arg_count -- ; 
  et = FUNCCALL(SETUP_XfOrM87(_), scheme_get_eval_type (app -> rand ) ); 
  et = et << 3 ; 
  et += FUNCCALL(SETUP_XfOrM87(_), scheme_get_eval_type (app -> rator ) ); 
  (& app -> iso ) -> so . keyex = et ; 
  info -> max_let_depth += 1 ; 
  if (orig_info -> max_let_depth < info -> max_let_depth )
    orig_info -> max_let_depth = info -> max_let_depth ; 
  RET_VALUE_START ((Scheme_Object * ) app ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int eq_testable_constant (Scheme_Object * v ) {
  /* No conversion */
  if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((v ) ) == (scheme_false ) ) || ((v ) == (scheme_true ) ) || (((v ) ) == (scheme_void ) ) )
    return 1 ; 
  if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_char_type ) ) && ((((Scheme_Small_Object * ) (v ) ) -> u . char_val ) < 256 ) )
    return 1 ; 
  return 0 ; 
}
static Scheme_Object * resolve_application3 (Scheme_Object * o , Resolve_Info * orig_info , int already_resolved_arg_count ) {
  Resolve_Info * info ; 
  Scheme_App3_Rec * app ; 
  Scheme_Object * le ; 
  short et ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(app, 0), PUSH(le, 1), PUSH(orig_info, 2), PUSH(info, 3)));
# define XfOrM98_COUNT (4)
# define SETUP_XfOrM98(x) SETUP(XfOrM98_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  info = NULLED_OUT ; 
  app = NULLED_OUT ; 
  le = NULLED_OUT ; 
  app = (Scheme_App3_Rec * ) o ; 
  if (! already_resolved_arg_count ) {
    Scheme_Object * additions = ((void * ) 0 ) , * rator ; 
    int rdelta ; 
    BLOCK_SETUP((PUSH(additions, 0+XfOrM98_COUNT), PUSH(rator, 1+XfOrM98_COUNT)));
#   define XfOrM106_COUNT (2+XfOrM98_COUNT)
#   define SETUP_XfOrM106(x) SETUP(XfOrM106_COUNT)
    rator = NULLED_OUT ; 
    additions = FUNCCALL(SETUP_XfOrM106(_), check_converted_rator (app -> rator , orig_info , & rator , 2 , & rdelta ) ); 
    if (additions ) {
      int m , i ; 
#     define XfOrM107_COUNT (0+XfOrM106_COUNT)
#     define SETUP_XfOrM107(x) SETUP_XfOrM106(x)
      m = (((Scheme_Vector * ) (additions ) ) -> size ) - 1 ; 
      if (m ) {
        Scheme_App_Rec * app2 ; 
        Scheme_Object * loc ; 
        BLOCK_SETUP((PUSH(loc, 0+XfOrM107_COUNT), PUSH(app2, 1+XfOrM107_COUNT)));
#       define XfOrM109_COUNT (2+XfOrM107_COUNT)
#       define SETUP_XfOrM109(x) SETUP(XfOrM109_COUNT)
        app2 = NULLED_OUT ; 
        loc = NULLED_OUT ; 
        app2 = FUNCCALL(SETUP_XfOrM109(_), scheme_malloc_application (3 + m ) ); 
        for (i = 0 ; i < m ; i ++ ) {
          loc = (((Scheme_Vector * ) (additions ) ) -> els ) [i + 1 ] ; 
          if (((Scheme_Type ) (((((long ) (loc ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (loc ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) )
            loc = (((Scheme_Small_Object * ) (loc ) ) -> u . ptr_val ) ; 
          app2 -> args [i + 1 ] = loc ; 
        }
        app2 -> args [0 ] = rator ; 
        app2 -> args [m + 1 ] = app -> rand1 ; 
        app2 -> args [m + 2 ] = app -> rand2 ; 
        RET_VALUE_START (FUNCCALL(SETUP_XfOrM109(_), resolve_application ((Scheme_Object * ) app2 , orig_info , m + 1 + rdelta ) )) RET_VALUE_END ; 
      }
      else {
        app -> rator = rator ; 
        already_resolved_arg_count = 1 + rdelta ; 
      }
    }
  }
  info = FUNCCALL(SETUP_XfOrM98(_), scheme_resolve_info_extend (orig_info , 2 , 0 , 0 ) ); 
  if (already_resolved_arg_count ) {
    already_resolved_arg_count -- ; 
  }
  else {
#   define XfOrM104_COUNT (0+XfOrM98_COUNT)
#   define SETUP_XfOrM104(x) SETUP_XfOrM98(x)
    le = FUNCCALL(SETUP_XfOrM104(_), scheme_resolve_expr (app -> rator , info ) ); 
    app -> rator = le ; 
  }
  if (already_resolved_arg_count ) {
    already_resolved_arg_count -- ; 
  }
  else {
#   define XfOrM102_COUNT (0+XfOrM98_COUNT)
#   define SETUP_XfOrM102(x) SETUP_XfOrM98(x)
    le = FUNCCALL(SETUP_XfOrM102(_), scheme_resolve_expr (app -> rand1 , info ) ); 
    app -> rand1 = le ; 
  }
  if (already_resolved_arg_count ) {
    already_resolved_arg_count -- ; 
  }
  else {
#   define XfOrM100_COUNT (0+XfOrM98_COUNT)
#   define SETUP_XfOrM100(x) SETUP_XfOrM98(x)
    le = FUNCCALL(SETUP_XfOrM100(_), scheme_resolve_expr (app -> rand2 , info ) ); 
    app -> rand2 = le ; 
  }
  if ((((app -> rator ) == (scheme_equal_prim ) ) || ((app -> rator ) == (scheme_eqv_prim ) ) ) && (FUNCCALL(SETUP_XfOrM98(_), eq_testable_constant (app -> rand1 ) )|| FUNCCALL(SETUP_XfOrM98(_), eq_testable_constant (app -> rand2 ) )) ) {
    app -> rator = scheme_eq_prim ; 
  }
  et = FUNCCALL(SETUP_XfOrM98(_), scheme_get_eval_type (app -> rand2 ) ); 
  et = et << 3 ; 
  et += FUNCCALL(SETUP_XfOrM98(_), scheme_get_eval_type (app -> rand1 ) ); 
  et = et << 3 ; 
  et += FUNCCALL(SETUP_XfOrM98(_), scheme_get_eval_type (app -> rator ) ); 
  (& app -> iso ) -> so . keyex = et ; 
  info -> max_let_depth += 2 ; 
  if (orig_info -> max_let_depth < info -> max_let_depth )
    orig_info -> max_let_depth = info -> max_let_depth ; 
  RET_VALUE_START ((Scheme_Object * ) app ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_branch (Scheme_Object * test , Scheme_Object * thenp , Scheme_Object * elsep ) {
  Scheme_Branch_Rec * b ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(thenp, 0), PUSH(test, 1), PUSH(elsep, 2), PUSH(b, 3)));
# define XfOrM112_COUNT (4)
# define SETUP_XfOrM112(x) SETUP(XfOrM112_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  b = NULLED_OUT ; 
  if (((((long ) (test ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (test ) ) -> type ) > _scheme_compiled_values_types_ ) {
    if ((((test ) ) == (scheme_false ) ) )
      RET_VALUE_START (elsep ) RET_VALUE_END ; 
    else RET_VALUE_START (thenp ) RET_VALUE_END ; 
  }
  b = ((Scheme_Branch_Rec * ) FUNCCALL(SETUP_XfOrM112(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Branch_Rec ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  b -> so . type = scheme_branch_type ; 
  b -> test = test ; 
  b -> tbranch = thenp ; 
  b -> fbranch = elsep ; 
  RET_VALUE_START ((Scheme_Object * ) b ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * resolve_branch (Scheme_Object * o , Resolve_Info * info ) {
  Scheme_Branch_Rec * b ; 
  Scheme_Object * t , * tb , * fb ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(tb, 1), PUSH(t, 2), PUSH(b, 3), PUSH(fb, 4), PUSH(info, 5)));
# define XfOrM114_COUNT (6)
# define SETUP_XfOrM114(x) SETUP(XfOrM114_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  b = NULLED_OUT ; 
  t = NULLED_OUT ; 
  tb = NULLED_OUT ; 
  fb = NULLED_OUT ; 
  b = (Scheme_Branch_Rec * ) o ; 
  t = FUNCCALL(SETUP_XfOrM114(_), scheme_resolve_expr (b -> test , info ) ); 
  tb = FUNCCALL_AGAIN(scheme_resolve_expr (b -> tbranch , info ) ); 
  fb = FUNCCALL_AGAIN(scheme_resolve_expr (b -> fbranch , info ) ); 
  b -> test = t ; 
  b -> tbranch = tb ; 
  b -> fbranch = fb ; 
  RET_VALUE_START (o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * resolve_wcm (Scheme_Object * o , Resolve_Info * info ) {
  Scheme_With_Continuation_Mark * wcm = (Scheme_With_Continuation_Mark * ) o ; 
  Scheme_Object * k , * v , * b ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(k, 0), PUSH(v, 1), PUSH(b, 2), PUSH(wcm, 3), PUSH(info, 4)));
# define XfOrM115_COUNT (5)
# define SETUP_XfOrM115(x) SETUP(XfOrM115_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  k = NULLED_OUT ; 
  v = NULLED_OUT ; 
  b = NULLED_OUT ; 
  k = FUNCCALL(SETUP_XfOrM115(_), scheme_resolve_expr (wcm -> key , info ) ); 
  v = FUNCCALL_AGAIN(scheme_resolve_expr (wcm -> val , info ) ); 
  b = FUNCCALL_AGAIN(scheme_resolve_expr (wcm -> body , info ) ); 
  wcm -> key = k ; 
  wcm -> val = v ; 
  wcm -> body = b ; 
  RET_VALUE_START ((Scheme_Object * ) wcm ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 1441 */
static Scheme_Sequence * malloc_sequence (int count ) {
  /* No conversion */
  return (Scheme_Sequence * ) GC_malloc_one_tagged (sizeof (Scheme_Sequence ) + (count - 1 ) * sizeof (Scheme_Object * ) ) ; 
}
Scheme_Object * scheme_make_sequence_compilation (Scheme_Object * seq , int opt ) {
  Scheme_Object * list , * v , * good ; 
  Scheme_Sequence * o ; 
  int count , i , k , total , last , first , setgood , addconst ; 
  Scheme_Type type ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(o, 1), PUSH(good, 2), PUSH(seq, 3), PUSH(list, 4)));
# define XfOrM117_COUNT (5)
# define SETUP_XfOrM117(x) SETUP(XfOrM117_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  list = NULLED_OUT ; 
  v = NULLED_OUT ; 
  good = NULLED_OUT ; 
  o = NULLED_OUT ; 
  type = scheme_sequence_type ; 
  list = seq ; 
  count = i = 0 ; 
  good = ((void * ) 0 ) ; 
  total = 0 ; 
  first = 1 ; 
  setgood = 1 ; 
  while (((Scheme_Type ) (((((long ) (list ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (list ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#   define XfOrM135_COUNT (0+XfOrM117_COUNT)
#   define SETUP_XfOrM135(x) SETUP_XfOrM117(x)
    v = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . car ) ; 
    list = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . cdr ) ; 
    last = ((list ) == (scheme_null ) ) ; 
    if (((opt > 0 ) || ! first ) && ((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (type ) ) ) {
      count += ((Scheme_Sequence * ) v ) -> count ; 
      total ++ ; 
    }
    else if (opt && (((opt > 0 ) && ! last ) || ((opt < 0 ) && ! first ) ) && FUNCCALL(SETUP_XfOrM135(_), scheme_omittable_expr (v , - 1 ) )) {
      total ++ ; 
    }
    else {
      if (setgood )
        good = v ; 
      count ++ ; 
      total ++ ; 
    }
    i ++ ; 
    if (first ) {
      if (opt < 0 )
        setgood = 0 ; 
      first = 0 ; 
    }
  }
  if (! ((list ) == (scheme_null ) ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  if (! count )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_compiled_void () )) RET_VALUE_EMPTY_END ; 
  if (count == 1 ) {
#   define XfOrM128_COUNT (0+XfOrM117_COUNT)
#   define SETUP_XfOrM128(x) SETUP_XfOrM117(x)
    if ((opt < 0 ) && ! FUNCCALL(SETUP_XfOrM128(_), scheme_omittable_expr ((((Scheme_Simple_Object * ) (seq ) ) -> u . pair_val . car ) , 1 ) )) {
      addconst = 1 ; 
    }
    else RET_VALUE_START (good ) RET_VALUE_END ; 
  }
  else addconst = 0 ; 
  o = FUNCCALL(SETUP_XfOrM117(_), malloc_sequence (count + addconst ) ); 
  o -> so . type = ((opt < 0 ) ? scheme_begin0_sequence_type : scheme_sequence_type ) ; 
  o -> count = count + addconst ; 
  -- total ; 
  for (i = k = 0 ; i < count ; k ++ ) {
#   define XfOrM123_COUNT (0+XfOrM117_COUNT)
#   define SETUP_XfOrM123(x) SETUP_XfOrM117(x)
    v = (((Scheme_Simple_Object * ) (seq ) ) -> u . pair_val . car ) ; 
    seq = (((Scheme_Simple_Object * ) (seq ) ) -> u . pair_val . cdr ) ; 
    if (((opt > 0 ) || k ) && ((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (type ) ) ) {
      int c , j ; 
      Scheme_Object * * a ; 
      a = NULLED_OUT ; 
      c = ((Scheme_Sequence * ) v ) -> count ; 
      a = ((Scheme_Sequence * ) v ) -> array ; 
      for (j = 0 ; j < c ; j ++ ) {
        o -> array [i ++ ] = a [j ] ; 
      }
    }
    else if (opt && (((opt > 0 ) && (k < total ) ) || ((opt < 0 ) && k ) ) && FUNCCALL(SETUP_XfOrM123(_), scheme_omittable_expr (v , - 1 ) )) {
    }
    else o -> array [i ++ ] = v ; 
  }
  if (addconst )
    o -> array [i ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
  RET_VALUE_START ((Scheme_Object * ) o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * look_for_letv_change (Scheme_Sequence * s ) {
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(s, 0)));
# define XfOrM140_COUNT (1)
# define SETUP_XfOrM140(x) SETUP(XfOrM140_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  for (i = 0 ; i < s -> count - 1 ; i ++ ) {
    Scheme_Object * v ; 
    BLOCK_SETUP((PUSH(v, 0+XfOrM140_COUNT)));
#   define XfOrM150_COUNT (1+XfOrM140_COUNT)
#   define SETUP_XfOrM150(x) SETUP(XfOrM150_COUNT)
    v = NULLED_OUT ; 
    v = s -> array [i ] ; 
    if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_let_value_type ) ) ) {
      Scheme_Let_Value * lv = (Scheme_Let_Value * ) v ; 
      BLOCK_SETUP((PUSH(lv, 0+XfOrM150_COUNT)));
#     define XfOrM151_COUNT (1+XfOrM150_COUNT)
#     define SETUP_XfOrM151(x) SETUP(XfOrM151_COUNT)
      if (FUNCCALL(SETUP_XfOrM151(_), scheme_omittable_expr (lv -> body , 1 ) )) {
        int esize = s -> count - (i + 1 ) ; 
        int nsize = i + 1 ; 
        Scheme_Object * nv , * ev ; 
        BLOCK_SETUP((PUSH(nv, 0+XfOrM151_COUNT), PUSH(ev, 1+XfOrM151_COUNT)));
#       define XfOrM152_COUNT (2+XfOrM151_COUNT)
#       define SETUP_XfOrM152(x) SETUP(XfOrM152_COUNT)
        nv = NULLED_OUT ; 
        ev = NULLED_OUT ; 
        if (nsize > 1 ) {
          Scheme_Sequence * naya ; 
          BLOCK_SETUP((PUSH(naya, 0+XfOrM152_COUNT)));
#         define XfOrM156_COUNT (1+XfOrM152_COUNT)
#         define SETUP_XfOrM156(x) SETUP(XfOrM156_COUNT)
          naya = NULLED_OUT ; 
          naya = FUNCCALL(SETUP_XfOrM156(_), malloc_sequence (nsize ) ); 
          naya -> so . type = scheme_sequence_type ; 
          naya -> count = nsize ; 
          nv = (Scheme_Object * ) naya ; 
          for (i = 0 ; i < nsize ; i ++ ) {
            naya -> array [i ] = s -> array [i ] ; 
          }
        }
        else nv = (Scheme_Object * ) lv ; 
        if (esize > 1 ) {
          Scheme_Sequence * e ; 
          BLOCK_SETUP((PUSH(e, 0+XfOrM152_COUNT)));
#         define XfOrM153_COUNT (1+XfOrM152_COUNT)
#         define SETUP_XfOrM153(x) SETUP(XfOrM153_COUNT)
          e = NULLED_OUT ; 
          e = FUNCCALL(SETUP_XfOrM153(_), malloc_sequence (esize ) ); 
          e -> so . type = scheme_sequence_type ; 
          e -> count = esize ; 
          for (i = 0 ; i < esize ; i ++ ) {
            e -> array [i ] = s -> array [i + nsize ] ; 
          }
          ev = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM153(_), look_for_letv_change (e ) ); 
        }
        else ev = s -> array [nsize ] ; 
        lv -> body = ev ; 
        RET_VALUE_START (nv ) RET_VALUE_END ; 
      }
    }
  }
  RET_VALUE_START ((Scheme_Object * ) s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * resolve_sequence (Scheme_Object * o , Resolve_Info * info ) {
  Scheme_Sequence * s = (Scheme_Sequence * ) o ; 
  int i ; 
  PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(info, 1)));
# define XfOrM159_COUNT (2)
# define SETUP_XfOrM159(x) SETUP(XfOrM159_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  for (i = s -> count ; i -- ; ) {
    Scheme_Object * le ; 
    BLOCK_SETUP((PUSH(le, 0+XfOrM159_COUNT)));
#   define XfOrM161_COUNT (1+XfOrM159_COUNT)
#   define SETUP_XfOrM161(x) SETUP(XfOrM161_COUNT)
    le = NULLED_OUT ; 
    le = FUNCCALL(SETUP_XfOrM161(_), scheme_resolve_expr (s -> array [i ] , info ) ); 
    s -> array [i ] = le ; 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(look_for_letv_change (s ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_syntax_resolved (int idx , Scheme_Object * data ) {
  Scheme_Object * v ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(data, 1)));
# define XfOrM162_COUNT (2)
# define SETUP_XfOrM162(x) SETUP(XfOrM162_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  v = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM162(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  v -> type = scheme_syntax_type ; 
  (((Scheme_Simple_Object * ) (v ) ) -> u . ptr_int_val . pint ) = idx ; 
  (((Scheme_Simple_Object * ) (v ) ) -> u . ptr_int_val . ptr ) = (void * ) data ; 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_syntax_compiled (int idx , Scheme_Object * data ) {
  Scheme_Object * v ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(data, 1)));
# define XfOrM163_COUNT (2)
# define SETUP_XfOrM163(x) SETUP(XfOrM163_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  v = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM163(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  v -> type = scheme_compiled_syntax_type ; 
  (((Scheme_Simple_Object * ) (v ) ) -> u . ptr_int_val . pint ) = idx ; 
  (((Scheme_Simple_Object * ) (v ) ) -> u . ptr_int_val . ptr ) = (void * ) data ; 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * link_module_variable (Scheme_Object * modidx , Scheme_Object * varname , Scheme_Object * insp , int pos , int mod_phase , Scheme_Env * env ) {
  Scheme_Object * modname ; 
  Scheme_Env * menv ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(modname, 1), PUSH(menv, 2), PUSH(varname, 3), PUSH(insp, 4)));
# define XfOrM164_COUNT (5)
# define SETUP_XfOrM164(x) SETUP(XfOrM164_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  modname = NULLED_OUT ; 
  menv = NULLED_OUT ; 
  modname = FUNCCALL(SETUP_XfOrM164(_), scheme_module_resolve (modidx , 1 ) ); 
  if (env -> module && ((env -> module -> modname ) == (modname ) ) && (env -> mod_phase == mod_phase ) )
    menv = env ; 
  else {
#   define XfOrM165_COUNT (0+XfOrM164_COUNT)
#   define SETUP_XfOrM165(x) SETUP_XfOrM164(x)
    menv = FUNCCALL(SETUP_XfOrM165(_), scheme_module_access (modname , env , mod_phase ) ); 
    if (! menv && env -> phase ) {
#     define XfOrM168_COUNT (0+XfOrM165_COUNT)
#     define SETUP_XfOrM168(x) SETUP_XfOrM165(x)
      FUNCCALL(SETUP_XfOrM168(_), scheme_module_force_lazy (env , 1 ) ); 
      menv = FUNCCALL(SETUP_XfOrM168(_), scheme_module_access (modname , env , mod_phase ) ); 
    }
    if (! menv ) {
#     define XfOrM167_COUNT (0+XfOrM165_COUNT)
#     define SETUP_XfOrM167(x) SETUP_XfOrM165(x)
      FUNCCALL_EMPTY(scheme_wrong_syntax ("link" , ((void * ) 0 ) , varname , "broken compiled code (phase %d, defn-phase %d, in %V), no declaration for module" ": %S" , env -> phase , mod_phase , env -> module ? env -> module -> modname : scheme_false , modname ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    if (! ((menv ) == (env ) ) ) {
#     define XfOrM166_COUNT (0+XfOrM165_COUNT)
#     define SETUP_XfOrM166(x) SETUP_XfOrM165(x)
      varname = FUNCCALL(SETUP_XfOrM166(_), scheme_check_accessible_in_module (menv , insp , ((void * ) 0 ) , varname , ((void * ) 0 ) , ((void * ) 0 ) , insp , pos , 0 , ((void * ) 0 ) ) ); 
    }
  }
  RET_VALUE_START ((Scheme_Object * ) FUNCCALL_EMPTY(scheme_global_bucket (varname , menv ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * link_toplevel (Scheme_Object * expr , Scheme_Env * env , Scheme_Object * src_modidx , Scheme_Object * dest_modidx ) {
  Scheme_Object * __funcarg28 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(env, 0)));
# define XfOrM169_COUNT (1)
# define SETUP_XfOrM169(x) SETUP(XfOrM169_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (((Scheme_Type ) (((((long ) (expr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (expr ) ) -> type ) ) == (Scheme_Type ) (scheme_variable_type ) ) ) {
    Scheme_Bucket_With_Home * b = (Scheme_Bucket_With_Home * ) expr ; 
#   define XfOrM171_COUNT (0+XfOrM169_COUNT)
#   define SETUP_XfOrM171(x) SETUP_XfOrM169(x)
    if (! env || ! b -> home -> module )
      RET_VALUE_START ((Scheme_Object * ) b ) RET_VALUE_END ; 
    else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(link_module_variable (b -> home -> module -> modname , (Scheme_Object * ) b -> bucket . bucket . key , b -> home -> module -> insp , - 1 , b -> home -> mod_phase , env ) )) RET_VALUE_EMPTY_END ; 
  }
  else {
    Module_Variable * mv = (Module_Variable * ) expr ; 
    BLOCK_SETUP((PUSH(mv, 0+XfOrM169_COUNT)));
#   define XfOrM170_COUNT (1+XfOrM169_COUNT)
#   define SETUP_XfOrM170(x) SETUP(XfOrM170_COUNT)
    RET_VALUE_START ((__funcarg28 = FUNCCALL(SETUP_XfOrM170(_), scheme_modidx_shift (mv -> modidx , src_modidx , dest_modidx ) ), FUNCCALL_EMPTY(link_module_variable (__funcarg28 , mv -> sym , mv -> insp , mv -> pos , mv -> mod_phase , env ) )) ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * resolve_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * expr = (Scheme_Object * ) p -> ku . k . p1 ; 
  Resolve_Info * info = (Resolve_Info * ) p -> ku . k . p2 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  p -> ku . k . p2 = ((void * ) 0 ) ; 
  return scheme_resolve_expr (expr , info ) ; 
}
Scheme_Object * scheme_resolve_expr (Scheme_Object * expr , Resolve_Info * info ) {
  Scheme_Type type = ((((long ) (expr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (expr ) ) -> type ) ; 
  unsigned long _stk_pos ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(expr, 0), PUSH(info, 1)));
# define XfOrM173_COUNT (2)
# define SETUP_XfOrM173(x) SETUP(XfOrM173_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  _stk_pos = (unsigned long ) & _stk_pos ; 
  if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
    Scheme_Thread * p = scheme_current_thread ; 
#   define XfOrM180_COUNT (0+XfOrM173_COUNT)
#   define SETUP_XfOrM180(x) SETUP_XfOrM173(x)
    p -> ku . k . p1 = (void * ) expr ; 
    p -> ku . k . p2 = (void * ) info ; 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_handle_stack_overflow (resolve_k ) )) RET_VALUE_EMPTY_END ; 
  }
  switch (type ) {
#   define XfOrM174_COUNT (0+XfOrM173_COUNT)
#   define SETUP_XfOrM174(x) SETUP_XfOrM173(x)
    case scheme_local_type : {
      int pos , flags ; 
      Scheme_Object * lifted ; 
      BLOCK_SETUP((PUSH(lifted, 0+XfOrM174_COUNT)));
#     define XfOrM177_COUNT (1+XfOrM174_COUNT)
#     define SETUP_XfOrM177(x) SETUP(XfOrM177_COUNT)
      lifted = NULLED_OUT ; 
      pos = FUNCCALL(SETUP_XfOrM177(_), scheme_resolve_info_lookup (info , (((Scheme_Local * ) (expr ) ) -> position ) , & flags , & lifted , 0 ) ); 
      if (lifted ) {
        RET_VALUE_START (lifted ) RET_VALUE_END ; 
      }
      else {
#       define XfOrM178_COUNT (0+XfOrM177_COUNT)
#       define SETUP_XfOrM178(x) SETUP_XfOrM177(x)
        RET_VALUE_START (FUNCCALL(SETUP_XfOrM178(_), scheme_make_local ((flags & 1 ) ? scheme_local_unbox_type : scheme_local_type , pos ) )) RET_VALUE_END ; 
      }
    }
    case scheme_compiled_syntax_type : {
      Scheme_Syntax_Resolver f ; 
#     define XfOrM176_COUNT (0+XfOrM174_COUNT)
#     define SETUP_XfOrM176(x) SETUP_XfOrM174(x)
      f = scheme_syntax_resolvers [(((Scheme_Simple_Object * ) (expr ) ) -> u . ptr_int_val . pint ) ] ; 
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(f ((Scheme_Object * ) (((Scheme_Simple_Object * ) (expr ) ) -> u . ptr_int_val . ptr ) , info ) )) RET_VALUE_EMPTY_END ; 
    }
    case scheme_application_type : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(resolve_application (expr , info , 0 ) )) RET_VALUE_EMPTY_END ; 
    case scheme_application2_type : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(resolve_application2 (expr , info , 0 ) )) RET_VALUE_EMPTY_END ; 
    case scheme_application3_type : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(resolve_application3 (expr , info , 0 ) )) RET_VALUE_EMPTY_END ; 
    case scheme_sequence_type : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(resolve_sequence (expr , info ) )) RET_VALUE_EMPTY_END ; 
    case scheme_branch_type : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(resolve_branch (expr , info ) )) RET_VALUE_EMPTY_END ; 
    case scheme_with_cont_mark_type : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(resolve_wcm (expr , info ) )) RET_VALUE_EMPTY_END ; 
    case scheme_compiled_unclosed_procedure_type : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_resolve_closure_compilation (expr , info , 1 , 0 , 0 , ((void * ) 0 ) ) )) RET_VALUE_EMPTY_END ; 
    case scheme_compiled_let_void_type : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_resolve_lets (expr , info ) )) RET_VALUE_EMPTY_END ; 
    case scheme_compiled_toplevel_type : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_resolve_toplevel (info , expr ) )) RET_VALUE_EMPTY_END ; 
    case scheme_compiled_quote_syntax_type : {
      Scheme_Quote_Syntax * qs ; 
      int i , c , p ; 
      BLOCK_SETUP((PUSH(qs, 0+XfOrM174_COUNT)));
#     define XfOrM175_COUNT (1+XfOrM174_COUNT)
#     define SETUP_XfOrM175(x) SETUP(XfOrM175_COUNT)
      qs = NULLED_OUT ; 
      i = (((Scheme_Local * ) (expr ) ) -> position ) ; 
      i = FUNCCALL(SETUP_XfOrM175(_), scheme_resolve_quote_syntax_offset (i , info ) ); 
      c = FUNCCALL_AGAIN(scheme_resolve_toplevel_pos (info ) ); 
      p = FUNCCALL_AGAIN(scheme_resolve_quote_syntax_pos (info ) ); 
      qs = ((Scheme_Quote_Syntax * ) FUNCCALL(SETUP_XfOrM175(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Quote_Syntax ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
      qs -> so . type = scheme_quote_syntax_type ; 
      qs -> depth = c ; 
      qs -> position = i ; 
      qs -> midpoint = p ; 
      RET_VALUE_START ((Scheme_Object * ) qs ) RET_VALUE_END ; 
    }
    case scheme_variable_type : case scheme_module_variable_type : FUNCCALL_EMPTY(scheme_signal_error ("got top-level in wrong place" ) ); 
    RET_VALUE_START (0 ) RET_VALUE_END ; 
    default : RET_VALUE_START (expr ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_resolve_list (Scheme_Object * expr , Resolve_Info * info ) {
  Scheme_Object * first = scheme_null , * last = ((void * ) 0 ) ; 
  Scheme_Object * __funcarg30 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(first, 0), PUSH(last, 1), PUSH(expr, 2), PUSH(info, 3)));
# define XfOrM181_COUNT (4)
# define SETUP_XfOrM181(x) SETUP(XfOrM181_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  while (((Scheme_Type ) (((((long ) (expr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (expr ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
    Scheme_Object * pr ; 
    BLOCK_SETUP((PUSH(pr, 0+XfOrM181_COUNT)));
#   define XfOrM183_COUNT (1+XfOrM181_COUNT)
#   define SETUP_XfOrM183(x) SETUP(XfOrM183_COUNT)
    pr = NULLED_OUT ; 
    pr = (__funcarg30 = FUNCCALL(SETUP_XfOrM183(_), scheme_resolve_expr ((((Scheme_Simple_Object * ) (expr ) ) -> u . pair_val . car ) , info ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg30 , scheme_null ) )) ; 
    if (last )
      (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = pr ; 
    else first = pr ; 
    last = pr ; 
    expr = (((Scheme_Simple_Object * ) (expr ) ) -> u . pair_val . cdr ) ; 
  }
  RET_VALUE_START (first ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * try_optimize_fold (Scheme_Object * f , Scheme_Object * o , Optimize_Info * info ) {
  Scheme_Object * __funcarg31 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(f, 0), PUSH(o, 1)));
# define XfOrM184_COUNT (2)
# define SETUP_XfOrM184(x) SETUP(XfOrM184_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((((Scheme_Type ) (((((long ) (f ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (f ) ) -> type ) ) == (Scheme_Type ) (scheme_prim_type ) ) && (((Scheme_Primitive_Proc * ) f ) -> pp . flags & 1 ) ) || (((Scheme_Type ) (((((long ) (f ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (f ) ) -> type ) ) == (Scheme_Type ) (scheme_closed_prim_type ) ) && (((Scheme_Closed_Primitive_Proc * ) f ) -> pp . flags & 1 ) ) ) {
    Scheme_Object * args ; 
    BLOCK_SETUP((PUSH(args, 0+XfOrM184_COUNT)));
#   define XfOrM185_COUNT (1+XfOrM184_COUNT)
#   define SETUP_XfOrM185(x) SETUP(XfOrM185_COUNT)
    args = NULLED_OUT ; 
    switch (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) {
#     define XfOrM186_COUNT (0+XfOrM185_COUNT)
#     define SETUP_XfOrM186(x) SETUP_XfOrM185(x)
      case scheme_application_type : {
        Scheme_App_Rec * app = (Scheme_App_Rec * ) o ; 
        int i ; 
        BLOCK_SETUP((PUSH(app, 0+XfOrM186_COUNT)));
#       define XfOrM189_COUNT (1+XfOrM186_COUNT)
#       define SETUP_XfOrM189(x) SETUP(XfOrM189_COUNT)
        args = scheme_null ; 
        for (i = app -> num_args ; i -- ; ) {
#         define XfOrM191_COUNT (0+XfOrM189_COUNT)
#         define SETUP_XfOrM191(x) SETUP_XfOrM189(x)
          args = FUNCCALL(SETUP_XfOrM191(_), scheme_make_pair (app -> args [i + 1 ] , args ) ); 
        }
      }
      break ; 
      case scheme_application2_type : {
        Scheme_App2_Rec * app = (Scheme_App2_Rec * ) o ; 
#       define XfOrM188_COUNT (0+XfOrM186_COUNT)
#       define SETUP_XfOrM188(x) SETUP_XfOrM186(x)
        args = FUNCCALL(SETUP_XfOrM188(_), scheme_make_pair (app -> rand , scheme_null ) ); 
      }
      break ; 
      case scheme_application3_type : default : {
        Scheme_App3_Rec * app = (Scheme_App3_Rec * ) o ; 
        BLOCK_SETUP((PUSH(app, 0+XfOrM186_COUNT)));
#       define XfOrM187_COUNT (1+XfOrM186_COUNT)
#       define SETUP_XfOrM187(x) SETUP(XfOrM187_COUNT)
        args = (__funcarg31 = FUNCCALL(SETUP_XfOrM187(_), scheme_make_pair (app -> rand2 , scheme_null ) ), FUNCCALL_AGAIN(scheme_make_pair (app -> rand1 , __funcarg31 ) )) ; 
      }
      break ; 
    }
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(try_apply (f , args ) )) RET_VALUE_EMPTY_END ; 
  }
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * apply_inlined (Scheme_Object * p , Scheme_Closure_Data * data , Optimize_Info * info , int argc , Scheme_App_Rec * app , Scheme_App2_Rec * app2 , Scheme_App3_Rec * app3 ) {
  Scheme_Let_Header * lh ; 
  Scheme_Compiled_Let_Value * lv , * prev = ((void * ) 0 ) ; 
  int i ; 
  int * flags , flag ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(10);
  BLOCK_SETUP_TOP((PUSH(prev, 0), PUSH(app2, 1), PUSH(lh, 2), PUSH(app3, 3), PUSH(info, 4), PUSH(app, 5), PUSH(lv, 6), PUSH(p, 7), PUSH(flags, 8), PUSH(data, 9)));
# define XfOrM192_COUNT (10)
# define SETUP_XfOrM192(x) SETUP(XfOrM192_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  lh = NULLED_OUT ; 
  lv = NULLED_OUT ; 
  flags = NULLED_OUT ; 
  if (! argc ) {
#   define XfOrM195_COUNT (0+XfOrM192_COUNT)
#   define SETUP_XfOrM195(x) SETUP_XfOrM192(x)
    info = FUNCCALL(SETUP_XfOrM195(_), scheme_optimize_info_add_frame (info , 0 , 0 , 0 ) ); 
    info -> inline_fuel >>= 1 ; 
    p = FUNCCALL(SETUP_XfOrM195(_), scheme_optimize_expr (p , info ) ); 
    info -> next -> single_result = info -> single_result ; 
    info -> next -> preserves_marks = info -> preserves_marks ; 
    FUNCCALL(SETUP_XfOrM195(_), scheme_optimize_info_done (info ) ); 
    RET_VALUE_START (p ) RET_VALUE_END ; 
  }
  lh = ((Scheme_Let_Header * ) FUNCCALL(SETUP_XfOrM192(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Let_Header ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  lh -> iso . so . type = scheme_compiled_let_void_type ; 
  lh -> count = argc ; 
  lh -> num_clauses = argc ; 
  for (i = 0 ; i < argc ; i ++ ) {
#   define XfOrM194_COUNT (0+XfOrM192_COUNT)
#   define SETUP_XfOrM194(x) SETUP_XfOrM192(x)
    lv = ((Scheme_Compiled_Let_Value * ) FUNCCALL(SETUP_XfOrM194(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Compiled_Let_Value ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    lv -> so . type = scheme_compiled_let_value_type ; 
    lv -> count = 1 ; 
    lv -> position = i ; 
    if (app )
      lv -> value = app -> args [i + 1 ] ; 
    else if (app3 )
      lv -> value = (i ? app3 -> rand2 : app3 -> rand1 ) ; 
    else if (app2 )
      lv -> value = app2 -> rand ; 
    flag = FUNCCALL(SETUP_XfOrM194(_), scheme_closure_argument_flags (data , i ) ); 
    flags = (int * ) FUNCCALL(SETUP_XfOrM194(_), GC_malloc_atomic (sizeof (int ) ) ); 
    flags [0 ] = flag ; 
    lv -> flags = flags ; 
    if (prev )
      prev -> body = (Scheme_Object * ) lv ; 
    else lh -> body = (Scheme_Object * ) lv ; 
    prev = lv ; 
  }
  if (prev )
    prev -> body = p ; 
  else lh -> body = p ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_optimize_lets ((Scheme_Object * ) lh , info , 1 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * optimize_for_inline (Optimize_Info * info , Scheme_Object * le , int argc , Scheme_App_Rec * app , Scheme_App2_Rec * app2 , Scheme_App3_Rec * app3 , int * _flags ) {
  int offset = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(app3, 0), PUSH(app, 1), PUSH(app2, 2), PUSH(le, 3), PUSH(_flags, 4), PUSH(info, 5)));
# define XfOrM196_COUNT (6)
# define SETUP_XfOrM196(x) SETUP(XfOrM196_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (((Scheme_Type ) (((((long ) (le ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (le ) ) -> type ) ) == (Scheme_Type ) (scheme_local_type ) ) ) {
#   define XfOrM209_COUNT (0+XfOrM196_COUNT)
#   define SETUP_XfOrM209(x) SETUP_XfOrM196(x)
    le = FUNCCALL(SETUP_XfOrM209(_), scheme_optimize_info_lookup (info , (((Scheme_Local * ) (le ) ) -> position ) , & offset ) ); 
    if (! le )
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  while (((Scheme_Type ) (((((long ) (le ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (le ) ) -> type ) ) == (Scheme_Type ) (scheme_compiled_toplevel_type ) ) ) {
#   define XfOrM207_COUNT (0+XfOrM196_COUNT)
#   define SETUP_XfOrM207(x) SETUP_XfOrM196(x)
    if (info -> top_level_consts ) {
      int pos ; 
#     define XfOrM208_COUNT (0+XfOrM207_COUNT)
#     define SETUP_XfOrM208(x) SETUP_XfOrM207(x)
      pos = (((Scheme_Toplevel * ) (le ) ) -> position ) ; 
      le = FUNCCALL(SETUP_XfOrM208(_), scheme_hash_get (info -> top_level_consts , ((Scheme_Object * ) (void * ) (long ) ((((long ) (pos ) ) << 1 ) | 0x1 ) ) ) ); 
      if (! le )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (le && ((Scheme_Type ) (((((long ) (le ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (le ) ) -> type ) ) == (Scheme_Type ) (scheme_compiled_unclosed_procedure_type ) ) ) {
    Scheme_Closure_Data * data = (Scheme_Closure_Data * ) le ; 
    int sz ; 
    BLOCK_SETUP((PUSH(data, 0+XfOrM196_COUNT)));
#   define XfOrM198_COUNT (1+XfOrM196_COUNT)
#   define SETUP_XfOrM198(x) SETUP(XfOrM198_COUNT)
    if (! app && ! app2 && ! app3 ) {
      RET_VALUE_START (le ) RET_VALUE_END ; 
    }
    * _flags = (& (data ) -> iso ) -> so . keyex ; 
    if (data -> num_params == argc ) {
#     define XfOrM199_COUNT (0+XfOrM198_COUNT)
#     define SETUP_XfOrM199(x) SETUP_XfOrM198(x)
      sz = FUNCCALL(SETUP_XfOrM199(_), scheme_closure_body_size (data , 1 ) ); 
      if ((sz >= 0 ) && (sz <= (info -> inline_fuel * (argc + 2 ) ) ) ) {
#       define XfOrM201_COUNT (0+XfOrM199_COUNT)
#       define SETUP_XfOrM201(x) SETUP_XfOrM199(x)
        le = FUNCCALL(SETUP_XfOrM201(_), scheme_optimize_clone (0 , data -> code , info , offset , argc ) ); 
        if (le ) {
#         define XfOrM203_COUNT (0+XfOrM201_COUNT)
#         define SETUP_XfOrM203(x) SETUP_XfOrM201(x)
          ; 
          RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(apply_inlined (le , data , info , argc , app , app2 , app3 ) )) RET_VALUE_EMPTY_END ; 
        }
        else {
          ; 
        }
      }
      else {
        ; 
      }
    }
  }
  if (le && ((Scheme_Type ) (((((long ) (le ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (le ) ) -> type ) ) == (Scheme_Type ) (scheme_prim_type ) ) ) {
    if (((Scheme_Prim_Proc_Header * ) le ) -> flags & 8192 )
      * _flags = (4 | 32 ) ; 
  }
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void reset_rator (Scheme_Object * app , Scheme_Object * a ) {
  /* No conversion */
  switch (((((long ) (app ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (app ) ) -> type ) ) {
    case scheme_application_type : ((Scheme_App_Rec * ) app ) -> args [0 ] = a ; 
    break ; 
    case scheme_application2_type : ((Scheme_App2_Rec * ) app ) -> rator = a ; 
    break ; 
    case scheme_application3_type : ((Scheme_App3_Rec * ) app ) -> rator = a ; 
    break ; 
  }
}
static Scheme_Object * check_app_let_rator (Scheme_Object * app , Scheme_Object * rator , Optimize_Info * info , int argc ) {
  Scheme_Object * __funcarg32 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(info, 0), PUSH(app, 1), PUSH(rator, 2)));
# define XfOrM212_COUNT (3)
# define SETUP_XfOrM212(x) SETUP(XfOrM212_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (((Scheme_Type ) (((((long ) (rator ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rator ) ) -> type ) ) == (Scheme_Type ) (scheme_compiled_let_void_type ) ) ) {
    Scheme_Let_Header * head = (Scheme_Let_Header * ) rator ; 
#   define XfOrM213_COUNT (0+XfOrM212_COUNT)
#   define SETUP_XfOrM213(x) SETUP_XfOrM212(x)
    if ((head -> count == 1 ) && (head -> num_clauses == 1 ) ) {
      Scheme_Object * body ; 
      Scheme_Compiled_Let_Value * clv ; 
      BLOCK_SETUP((PUSH(clv, 0+XfOrM213_COUNT), PUSH(body, 1+XfOrM213_COUNT)));
#     define XfOrM214_COUNT (2+XfOrM213_COUNT)
#     define SETUP_XfOrM214(x) SETUP(XfOrM214_COUNT)
      body = NULLED_OUT ; 
      clv = NULLED_OUT ; 
      clv = (Scheme_Compiled_Let_Value * ) head -> body ; 
      body = clv -> body ; 
      if (((Scheme_Type ) (((((long ) (body ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (body ) ) -> type ) ) == (Scheme_Type ) (scheme_local_type ) ) && ((((Scheme_Local * ) (body ) ) -> position ) == 0 ) && FUNCCALL(SETUP_XfOrM214(_), scheme_is_compiled_procedure (clv -> value , 1 , 1 ) )) {
#       define XfOrM215_COUNT (0+XfOrM214_COUNT)
#       define SETUP_XfOrM215(x) SETUP_XfOrM214(x)
        FUNCCALL(SETUP_XfOrM215(_), reset_rator (app , scheme_false ) ); 
        app = FUNCCALL(SETUP_XfOrM215(_), scheme_optimize_shift (app , 1 , 0 ) ); 
        (__funcarg32 = FUNCCALL(SETUP_XfOrM215(_), scheme_make_local (scheme_local_type , 0 ) ), FUNCCALL_AGAIN(reset_rator (app , __funcarg32 ) )) ; 
        clv -> body = app ; 
        if (clv -> flags [0 ] & 0x8 ) {
          clv -> flags [0 ] -= 0x8 ; 
          clv -> flags [0 ] |= 0x4 ; 
        }
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_optimize_expr (rator , info ) )) RET_VALUE_EMPTY_END ; 
      }
    }
  }
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * optimize_application (Scheme_Object * o , Optimize_Info * info ) {
  Scheme_Object * le ; 
  Scheme_App_Rec * app ; 
  int i , n , all_vals = 1 , rator_flags = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(app, 0), PUSH(le, 1), PUSH(info, 2)));
# define XfOrM217_COUNT (3)
# define SETUP_XfOrM217(x) SETUP(XfOrM217_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  le = NULLED_OUT ; 
  app = NULLED_OUT ; 
  app = (Scheme_App_Rec * ) o ; 
  le = FUNCCALL(SETUP_XfOrM217(_), check_app_let_rator (o , app -> args [0 ] , info , app -> num_args ) ); 
  if (le )
    RET_VALUE_START (le ) RET_VALUE_END ; 
  n = app -> num_args + 1 ; 
  for (i = 0 ; i < n ; i ++ ) {
#   define XfOrM222_COUNT (0+XfOrM217_COUNT)
#   define SETUP_XfOrM222(x) SETUP_XfOrM217(x)
    if (! i ) {
#     define XfOrM223_COUNT (0+XfOrM222_COUNT)
#     define SETUP_XfOrM223(x) SETUP_XfOrM222(x)
      le = FUNCCALL(SETUP_XfOrM223(_), optimize_for_inline (info , app -> args [i ] , n - 1 , app , ((void * ) 0 ) , ((void * ) 0 ) , & rator_flags ) ); 
      if (le )
        RET_VALUE_START (le ) RET_VALUE_END ; 
    }
    le = FUNCCALL(SETUP_XfOrM222(_), scheme_optimize_expr (app -> args [i ] , info ) ); 
    app -> args [i ] = le ; 
    if (i && (((((long ) (le ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (le ) ) -> type ) < _scheme_compiled_values_types_ ) )
      all_vals = 0 ; 
  }
  if (all_vals ) {
#   define XfOrM219_COUNT (0+XfOrM217_COUNT)
#   define SETUP_XfOrM219(x) SETUP_XfOrM217(x)
    le = FUNCCALL(SETUP_XfOrM219(_), try_optimize_fold (app -> args [0 ] , (Scheme_Object * ) app , info ) ); 
    if (le )
      RET_VALUE_START (le ) RET_VALUE_END ; 
  }
  info -> size += 1 ; 
  info -> preserves_marks = ! ! (rator_flags & 4 ) ; 
  info -> single_result = ! ! (rator_flags & 32 ) ; 
  if (rator_flags & 64 ) {
    info -> preserves_marks = - info -> preserves_marks ; 
    info -> single_result = - info -> single_result ; 
  }
  RET_VALUE_START ((Scheme_Object * ) app ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * optimize_application2 (Scheme_Object * o , Optimize_Info * info ) {
  Scheme_App2_Rec * app ; 
  Scheme_Object * le ; 
  int rator_flags = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(app, 0), PUSH(le, 1), PUSH(info, 2)));
# define XfOrM224_COUNT (3)
# define SETUP_XfOrM224(x) SETUP(XfOrM224_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  app = NULLED_OUT ; 
  le = NULLED_OUT ; 
  app = (Scheme_App2_Rec * ) o ; 
  le = FUNCCALL(SETUP_XfOrM224(_), check_app_let_rator (o , app -> rator , info , 1 ) ); 
  if (le )
    RET_VALUE_START (le ) RET_VALUE_END ; 
  le = FUNCCALL(SETUP_XfOrM224(_), optimize_for_inline (info , app -> rator , 1 , ((void * ) 0 ) , app , ((void * ) 0 ) , & rator_flags ) ); 
  if (le )
    RET_VALUE_START (le ) RET_VALUE_END ; 
  le = FUNCCALL(SETUP_XfOrM224(_), scheme_optimize_expr (app -> rator , info ) ); 
  app -> rator = le ; 
  le = FUNCCALL(SETUP_XfOrM224(_), scheme_optimize_expr (app -> rand , info ) ); 
  app -> rand = le ; 
  if (((((long ) (le ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (le ) ) -> type ) > _scheme_compiled_values_types_ ) {
#   define XfOrM231_COUNT (0+XfOrM224_COUNT)
#   define SETUP_XfOrM231(x) SETUP_XfOrM224(x)
    le = FUNCCALL(SETUP_XfOrM231(_), try_optimize_fold (app -> rator , (Scheme_Object * ) app , info ) ); 
    if (le )
      RET_VALUE_START (le ) RET_VALUE_END ; 
  }
  if (((scheme_procedure_p_proc ) == (app -> rator ) ) ) {
#   define XfOrM227_COUNT (0+XfOrM224_COUNT)
#   define SETUP_XfOrM227(x) SETUP_XfOrM224(x)
    if (((Scheme_Type ) (scheme_compiled_unclosed_procedure_type ) == (Scheme_Type ) (((((long ) (app -> rand ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (app -> rand ) ) -> type ) ) ) ) {
      info -> preserves_marks = 1 ; 
      info -> single_result = 1 ; 
      RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
    }
    if (((Scheme_Type ) (((((long ) (app -> rand ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (app -> rand ) ) -> type ) ) == (Scheme_Type ) (scheme_local_type ) ) ) {
      int offset ; 
#     define XfOrM228_COUNT (0+XfOrM227_COUNT)
#     define SETUP_XfOrM228(x) SETUP_XfOrM227(x)
      if (FUNCCALL(SETUP_XfOrM228(_), scheme_optimize_info_lookup (info , (((Scheme_Local * ) (app -> rand ) ) -> position ) , & offset ) )) {
        info -> preserves_marks = 1 ; 
        info -> single_result = 1 ; 
        RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
      }
    }
  }
  if (((scheme_values_func ) == (app -> rator ) ) && FUNCCALL(SETUP_XfOrM224(_), scheme_omittable_expr (app -> rand , 1 ) )) {
    info -> preserves_marks = 1 ; 
    info -> single_result = 1 ; 
    RET_VALUE_START (app -> rand ) RET_VALUE_END ; 
  }
  info -> preserves_marks = ! ! (rator_flags & 4 ) ; 
  info -> single_result = ! ! (rator_flags & 32 ) ; 
  if (rator_flags & 64 ) {
    info -> preserves_marks = - info -> preserves_marks ; 
    info -> single_result = - info -> single_result ; 
  }
  RET_VALUE_START ((Scheme_Object * ) app ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * optimize_application3 (Scheme_Object * o , Optimize_Info * info ) {
  Scheme_App3_Rec * app ; 
  Scheme_Object * le ; 
  int all_vals = 1 ; 
  int rator_flags = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(app, 0), PUSH(le, 1), PUSH(info, 2)));
# define XfOrM232_COUNT (3)
# define SETUP_XfOrM232(x) SETUP(XfOrM232_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  app = NULLED_OUT ; 
  le = NULLED_OUT ; 
  app = (Scheme_App3_Rec * ) o ; 
  le = FUNCCALL(SETUP_XfOrM232(_), check_app_let_rator (o , app -> rator , info , 2 ) ); 
  if (le )
    RET_VALUE_START (le ) RET_VALUE_END ; 
  le = FUNCCALL(SETUP_XfOrM232(_), optimize_for_inline (info , app -> rator , 2 , ((void * ) 0 ) , ((void * ) 0 ) , app , & rator_flags ) ); 
  if (le )
    RET_VALUE_START (le ) RET_VALUE_END ; 
  le = FUNCCALL(SETUP_XfOrM232(_), scheme_optimize_expr (app -> rator , info ) ); 
  app -> rator = le ; 
  le = FUNCCALL(SETUP_XfOrM232(_), scheme_optimize_expr (app -> rand1 , info ) ); 
  app -> rand1 = le ; 
  if (((((long ) (le ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (le ) ) -> type ) < _scheme_compiled_values_types_ )
    all_vals = 0 ; 
  le = FUNCCALL(SETUP_XfOrM232(_), scheme_optimize_expr (app -> rand2 , info ) ); 
  app -> rand2 = le ; 
  if (((((long ) (le ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (le ) ) -> type ) < _scheme_compiled_values_types_ )
    all_vals = 0 ; 
  if (all_vals ) {
#   define XfOrM237_COUNT (0+XfOrM232_COUNT)
#   define SETUP_XfOrM237(x) SETUP_XfOrM232(x)
    le = FUNCCALL(SETUP_XfOrM237(_), try_optimize_fold (app -> rator , (Scheme_Object * ) app , info ) ); 
    if (le )
      RET_VALUE_START (le ) RET_VALUE_END ; 
  }
  info -> size += 1 ; 
  if (((app -> rator ) == (scheme_call_with_values_proc ) ) ) {
#   define XfOrM234_COUNT (0+XfOrM232_COUNT)
#   define SETUP_XfOrM234(x) SETUP_XfOrM232(x)
    if (((Scheme_Type ) (((((long ) (app -> rand1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (app -> rand1 ) ) -> type ) ) == (Scheme_Type ) (scheme_compiled_unclosed_procedure_type ) ) ) {
      Scheme_Closure_Data * data = (Scheme_Closure_Data * ) app -> rand1 ; 
#     define XfOrM235_COUNT (0+XfOrM234_COUNT)
#     define SETUP_XfOrM235(x) SETUP_XfOrM234(x)
      if (! data -> num_params ) {
#       define XfOrM236_COUNT (0+XfOrM235_COUNT)
#       define SETUP_XfOrM236(x) SETUP_XfOrM235(x)
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_optimize_apply_values (app -> rand2 , data -> code , info , (((& (data ) -> iso ) -> so . keyex & 32 ) ? (((& (data ) -> iso ) -> so . keyex & 64 ) ? - 1 : 1 ) : 0 ) ) )) RET_VALUE_EMPTY_END ; 
      }
    }
  }
  info -> preserves_marks = ! ! (rator_flags & 4 ) ; 
  info -> single_result = ! ! (rator_flags & 32 ) ; 
  if (rator_flags & 64 ) {
    info -> preserves_marks = - info -> preserves_marks ; 
    info -> single_result = - info -> single_result ; 
  }
  RET_VALUE_START ((Scheme_Object * ) app ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_optimize_apply_values (Scheme_Object * f , Scheme_Object * e , Optimize_Info * info , int e_single_result ) {
  Scheme_Object * f_is_proc = ((void * ) 0 ) ; 
  Scheme_Object * __funcarg33 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(e, 0), PUSH(f_is_proc, 1), PUSH(f, 2), PUSH(info, 3)));
# define XfOrM238_COUNT (4)
# define SETUP_XfOrM238(x) SETUP(XfOrM238_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  info -> preserves_marks = 0 ; 
  info -> single_result = 0 ; 
  {
    Scheme_Object * rev ; 
    BLOCK_SETUP((PUSH(rev, 0+XfOrM238_COUNT)));
#   define XfOrM243_COUNT (1+XfOrM238_COUNT)
#   define SETUP_XfOrM243(x) SETUP(XfOrM243_COUNT)
    rev = NULLED_OUT ; 
    if (((Scheme_Type ) (((((long ) (f ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (f ) ) -> type ) ) == (Scheme_Type ) (scheme_local_type ) ) ) {
#     define XfOrM249_COUNT (0+XfOrM243_COUNT)
#     define SETUP_XfOrM249(x) SETUP_XfOrM243(x)
      rev = FUNCCALL(SETUP_XfOrM249(_), scheme_optimize_reverse (info , (((Scheme_Local * ) (f ) ) -> position ) , 1 ) ); 
    }
    else rev = f ; 
    if (rev ) {
      int rator2_flags ; 
      Scheme_Object * o_f ; 
      BLOCK_SETUP((PUSH(o_f, 0+XfOrM243_COUNT)));
#     define XfOrM245_COUNT (1+XfOrM243_COUNT)
#     define SETUP_XfOrM245(x) SETUP(XfOrM245_COUNT)
      o_f = NULLED_OUT ; 
      o_f = FUNCCALL(SETUP_XfOrM245(_), optimize_for_inline (info , rev , 1 , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , & rator2_flags ) ); 
      if (o_f ) {
        f_is_proc = rev ; 
        if (((Scheme_Type ) (((((long ) (o_f ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o_f ) ) -> type ) ) == (Scheme_Type ) (scheme_compiled_unclosed_procedure_type ) ) ) {
          Scheme_Closure_Data * data2 = (Scheme_Closure_Data * ) o_f ; 
          int flags = (& (data2 ) -> iso ) -> so . keyex ; 
          info -> preserves_marks = ! ! (flags & 4 ) ; 
          info -> single_result = ! ! (flags & 32 ) ; 
          if (flags & 64 ) {
            info -> preserves_marks = - info -> preserves_marks ; 
            info -> single_result = - info -> single_result ; 
          }
        }
      }
    }
    if (! f_is_proc && (! (((long ) (f ) ) & 0x1 ) && ((((f ) -> type ) >= scheme_prim_type ) && (((f ) -> type ) <= scheme_native_closure_type ) ) ) ) {
      f_is_proc = f ; 
    }
  }
  if (f_is_proc && (e_single_result > 0 ) ) {
    Scheme_App2_Rec * app2 ; 
    Scheme_Object * cloned , * f_cloned ; 
    BLOCK_SETUP((PUSH(f_cloned, 0+XfOrM238_COUNT), PUSH(cloned, 1+XfOrM238_COUNT), PUSH(app2, 2+XfOrM238_COUNT)));
#   define XfOrM239_COUNT (3+XfOrM238_COUNT)
#   define SETUP_XfOrM239(x) SETUP(XfOrM239_COUNT)
    app2 = NULLED_OUT ; 
    cloned = NULLED_OUT ; 
    f_cloned = NULLED_OUT ; 
    app2 = ((Scheme_App2_Rec * ) FUNCCALL(SETUP_XfOrM239(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_App2_Rec ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    app2 -> iso . so . type = scheme_application2_type ; 
    cloned = FUNCCALL(SETUP_XfOrM239(_), scheme_optimize_clone (1 , e , info , 0 , 0 ) ); 
    if (cloned ) {
#     define XfOrM240_COUNT (0+XfOrM239_COUNT)
#     define SETUP_XfOrM240(x) SETUP_XfOrM239(x)
      if (((Scheme_Type ) (((((long ) (f_is_proc ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (f_is_proc ) ) -> type ) ) == (Scheme_Type ) (scheme_compiled_unclosed_procedure_type ) ) )
        f_cloned = FUNCCALL(SETUP_XfOrM240(_), scheme_optimize_clone (1 , f_is_proc , info , 0 , 0 ) ); 
      else {
        f_cloned = f_is_proc ; 
      }
      if (f_cloned ) {
#       define XfOrM241_COUNT (0+XfOrM240_COUNT)
#       define SETUP_XfOrM241(x) SETUP_XfOrM240(x)
        app2 -> rator = f_cloned ; 
        app2 -> rand = cloned ; 
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(optimize_application2 ((Scheme_Object * ) app2 , info ) )) RET_VALUE_EMPTY_END ; 
      }
    }
    app2 -> rator = f ; 
    app2 -> rand = e ; 
    RET_VALUE_START ((Scheme_Object * ) app2 ) RET_VALUE_END ; 
  }
  RET_VALUE_START ((__funcarg33 = FUNCCALL_EMPTY(scheme_make_pair (f , e ) ), FUNCCALL_EMPTY(scheme_make_syntax_compiled (10 , __funcarg33 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * optimize_sequence (Scheme_Object * o , Optimize_Info * info ) {
  Scheme_Sequence * s = (Scheme_Sequence * ) o ; 
  Scheme_Object * le ; 
  int i ; 
  int drop = 0 , preserves_marks = 0 , single_result = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(le, 0), PUSH(s, 1), PUSH(info, 2)));
# define XfOrM250_COUNT (3)
# define SETUP_XfOrM250(x) SETUP(XfOrM250_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  le = NULLED_OUT ; 
  for (i = s -> count ; i -- ; ) {
#   define XfOrM261_COUNT (0+XfOrM250_COUNT)
#   define SETUP_XfOrM261(x) SETUP_XfOrM250(x)
    le = FUNCCALL(SETUP_XfOrM261(_), scheme_optimize_expr (s -> array [i ] , info ) ); 
    if (i == s -> count - 1 ) {
      single_result = info -> single_result ; 
      preserves_marks = info -> preserves_marks ; 
    }
    if ((i + 1 != s -> count ) && FUNCCALL(SETUP_XfOrM261(_), scheme_omittable_expr (le , - 1 ) )) {
      drop ++ ; 
      s -> array [i ] = ((void * ) 0 ) ; 
    }
    else {
      s -> array [i ] = le ; 
    }
  }
  info -> preserves_marks = preserves_marks ; 
  info -> single_result = single_result ; 
  if (drop + 1 == s -> count ) {
    RET_VALUE_START (s -> array [drop ] ) RET_VALUE_END ; 
  }
  else if (drop ) {
    Scheme_Sequence * s2 ; 
    int j = 0 ; 
    BLOCK_SETUP((PUSH(s2, 0+XfOrM250_COUNT)));
#   define XfOrM251_COUNT (1+XfOrM250_COUNT)
#   define SETUP_XfOrM251(x) SETUP(XfOrM251_COUNT)
    s2 = NULLED_OUT ; 
    s2 = FUNCCALL(SETUP_XfOrM251(_), malloc_sequence (s -> count - drop ) ); 
    s2 -> so . type = scheme_sequence_type ; 
    s2 -> count = s -> count - drop ; 
    for (i = 0 ; i < s -> count ; i ++ ) {
      if (s -> array [i ] ) {
        s2 -> array [j ++ ] = s -> array [i ] ; 
      }
    }
    s = s2 ; 
  }
  info -> size += 1 ; 
  RET_VALUE_START ((Scheme_Object * ) s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_compiled_duplicate_ok (Scheme_Object * fb ) {
  /* No conversion */
  return ((((fb ) ) == (scheme_void ) ) || ((fb ) == (scheme_true ) ) || (((fb ) ) == (scheme_false ) ) || ((Scheme_Type ) (((((long ) (fb ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fb ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || ((Scheme_Type ) (((((long ) (fb ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fb ) ) -> type ) ) == (Scheme_Type ) (scheme_keyword_type ) ) || (((fb ) ) == (scheme_eof ) ) || (((long ) (fb ) ) & 0x1 ) || ((fb ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (fb ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fb ) ) -> type ) ) == (Scheme_Type ) (scheme_char_type ) ) && ((((Scheme_Small_Object * ) (fb ) ) -> u . char_val ) < 256 ) ) || ((Scheme_Type ) (((((long ) (fb ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fb ) ) -> type ) ) == (Scheme_Type ) (scheme_local_type ) ) || ((Scheme_Type ) (((((long ) (fb ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fb ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (fb ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fb ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) || ((Scheme_Type ) (((((long ) (fb ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fb ) ) -> type ) ) == (Scheme_Type ) (scheme_regexp_type ) ) || ((((long ) (fb ) ) & 0x1 ) || ((((fb ) -> type ) >= scheme_bignum_type ) && (((fb ) -> type ) <= scheme_complex_type ) ) ) || ((Scheme_Type ) (((((long ) (fb ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fb ) ) -> type ) ) == (Scheme_Type ) (scheme_prim_type ) ) ) ; 
}
static Scheme_Object * optimize_branch (Scheme_Object * o , Optimize_Info * info ) {
  Scheme_Branch_Rec * b ; 
  Scheme_Object * t , * tb , * fb ; 
  int preserves_marks = 1 , single_result = 1 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(b, 1), PUSH(t, 2), PUSH(info, 3), PUSH(fb, 4), PUSH(tb, 5)));
# define XfOrM266_COUNT (6)
# define SETUP_XfOrM266(x) SETUP(XfOrM266_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  b = NULLED_OUT ; 
  t = NULLED_OUT ; 
  tb = NULLED_OUT ; 
  fb = NULLED_OUT ; 
  b = (Scheme_Branch_Rec * ) o ; 
  t = b -> test ; 
  tb = b -> tbranch ; 
  fb = b -> fbranch ; 
  while (1 ) {
    if (((Scheme_Type ) (((((long ) (t ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (t ) ) -> type ) ) == (Scheme_Type ) (scheme_application2_type ) ) ) {
      Scheme_App2_Rec * app ; 
      app = NULLED_OUT ; 
      app = (Scheme_App2_Rec * ) t ; 
      if (((scheme_not_prim ) == (app -> rator ) ) ) {
        t = tb ; 
        tb = fb ; 
        fb = t ; 
        t = app -> rand ; 
      }
      else break ; 
    }
    else break ; 
  }
  if (((Scheme_Type ) (((((long ) (t ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (t ) ) -> type ) ) == (Scheme_Type ) (scheme_compiled_let_void_type ) ) ) {
#   define XfOrM271_COUNT (0+XfOrM266_COUNT)
#   define SETUP_XfOrM271(x) SETUP_XfOrM266(x)
    t = FUNCCALL(SETUP_XfOrM271(_), scheme_optimize_lets_for_test (t , info ) ); 
  }
  else t = FUNCCALL(SETUP_XfOrM266(_), scheme_optimize_expr (t , info ) ); 
  if (((((long ) (t ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (t ) ) -> type ) > _scheme_compiled_values_types_ ) {
#   define XfOrM270_COUNT (0+XfOrM266_COUNT)
#   define SETUP_XfOrM270(x) SETUP_XfOrM266(x)
    if ((((t ) ) == (scheme_false ) ) )
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_optimize_expr (fb , info ) )) RET_VALUE_EMPTY_END ; 
    else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_optimize_expr (tb , info ) )) RET_VALUE_EMPTY_END ; 
  }
  else if (((Scheme_Type ) (((((long ) (t ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (t ) ) -> type ) ) == (Scheme_Type ) (scheme_compiled_quote_syntax_type ) ) || ((Scheme_Type ) (((((long ) (t ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (t ) ) -> type ) ) == (Scheme_Type ) (scheme_compiled_unclosed_procedure_type ) ) )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_optimize_expr (tb , info ) )) RET_VALUE_EMPTY_END ; 
  tb = FUNCCALL(SETUP_XfOrM266(_), scheme_optimize_expr (tb , info ) ); 
  if (! info -> preserves_marks )
    preserves_marks = 0 ; 
  if (! info -> single_result )
    single_result = 0 ; 
  fb = FUNCCALL(SETUP_XfOrM266(_), scheme_optimize_expr (fb , info ) ); 
  if (! info -> preserves_marks )
    preserves_marks = 0 ; 
  if (! info -> single_result )
    single_result = 0 ; 
  info -> preserves_marks = preserves_marks ; 
  info -> single_result = single_result ; 
  if (((Scheme_Type ) (((((long ) (t ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (t ) ) -> type ) ) == (Scheme_Type ) (scheme_local_type ) ) && ((Scheme_Type ) (((((long ) (tb ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (tb ) ) -> type ) ) == (Scheme_Type ) (scheme_local_type ) ) && ((((Scheme_Local * ) (t ) ) -> position ) == (((Scheme_Local * ) (tb ) ) -> position ) ) && (((fb ) ) == (scheme_false ) ) ) {
    RET_VALUE_START (t ) RET_VALUE_END ; 
  }
  if (((Scheme_Type ) (((((long ) (t ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (t ) ) -> type ) ) == (Scheme_Type ) (scheme_branch_type ) ) && FUNCCALL(SETUP_XfOrM266(_), scheme_compiled_duplicate_ok (fb ) )) {
    Scheme_Branch_Rec * b2 = (Scheme_Branch_Rec * ) t ; 
    BLOCK_SETUP((PUSH(b2, 0+XfOrM266_COUNT)));
#   define XfOrM267_COUNT (1+XfOrM266_COUNT)
#   define SETUP_XfOrM267(x) SETUP(XfOrM267_COUNT)
    if ((((b2 -> fbranch ) ) == (scheme_false ) ) ) {
      Scheme_Branch_Rec * b3 ; 
      BLOCK_SETUP((PUSH(b3, 0+XfOrM267_COUNT)));
#     define XfOrM268_COUNT (1+XfOrM267_COUNT)
#     define SETUP_XfOrM268(x) SETUP(XfOrM268_COUNT)
      b3 = NULLED_OUT ; 
      b3 = ((Scheme_Branch_Rec * ) FUNCCALL(SETUP_XfOrM268(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Branch_Rec ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
      b3 -> so . type = scheme_branch_type ; 
      b3 -> test = b2 -> tbranch ; 
      b3 -> tbranch = tb ; 
      b3 -> fbranch = fb ; 
      t = b2 -> test ; 
      tb = (Scheme_Object * ) b3 ; 
    }
  }
  b -> test = t ; 
  b -> tbranch = tb ; 
  b -> fbranch = fb ; 
  info -> size += 1 ; 
  RET_VALUE_START (o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * optimize_wcm (Scheme_Object * o , Optimize_Info * info ) {
  Scheme_With_Continuation_Mark * wcm = (Scheme_With_Continuation_Mark * ) o ; 
  Scheme_Object * k , * v , * b ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(b, 0), PUSH(v, 1), PUSH(info, 2), PUSH(wcm, 3), PUSH(k, 4)));
# define XfOrM278_COUNT (5)
# define SETUP_XfOrM278(x) SETUP(XfOrM278_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  k = NULLED_OUT ; 
  v = NULLED_OUT ; 
  b = NULLED_OUT ; 
  k = FUNCCALL(SETUP_XfOrM278(_), scheme_optimize_expr (wcm -> key , info ) ); 
  v = FUNCCALL_AGAIN(scheme_optimize_expr (wcm -> val , info ) ); 
  b = FUNCCALL_AGAIN(scheme_optimize_expr (wcm -> body , info ) ); 
  info -> preserves_marks = 0 ; 
  wcm -> key = k ; 
  wcm -> val = v ; 
  wcm -> body = b ; 
  info -> size += 1 ; 
  RET_VALUE_START ((Scheme_Object * ) wcm ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * optimize_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * expr = (Scheme_Object * ) p -> ku . k . p1 ; 
  Optimize_Info * info = (Optimize_Info * ) p -> ku . k . p2 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  p -> ku . k . p2 = ((void * ) 0 ) ; 
  return scheme_optimize_expr (expr , info ) ; 
}
Scheme_Object * scheme_optimize_expr (Scheme_Object * expr , Optimize_Info * info ) {
  Scheme_Type type = ((((long ) (expr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (expr ) ) -> type ) ; 
  unsigned long _stk_pos ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(expr, 0), PUSH(info, 1)));
# define XfOrM280_COUNT (2)
# define SETUP_XfOrM280(x) SETUP(XfOrM280_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  _stk_pos = (unsigned long ) & _stk_pos ; 
  if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
    Scheme_Thread * p = scheme_current_thread ; 
#   define XfOrM292_COUNT (0+XfOrM280_COUNT)
#   define SETUP_XfOrM292(x) SETUP_XfOrM280(x)
    p -> ku . k . p1 = (void * ) expr ; 
    p -> ku . k . p2 = (void * ) info ; 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_handle_stack_overflow (optimize_k ) )) RET_VALUE_EMPTY_END ; 
  }
  info -> preserves_marks = 1 ; 
  info -> single_result = 1 ; 
  switch (type ) {
#   define XfOrM281_COUNT (0+XfOrM280_COUNT)
#   define SETUP_XfOrM281(x) SETUP_XfOrM280(x)
    case scheme_local_type : {
      Scheme_Object * val ; 
      int pos , delta ; 
      BLOCK_SETUP((PUSH(val, 0+XfOrM281_COUNT)));
#     define XfOrM290_COUNT (1+XfOrM281_COUNT)
#     define SETUP_XfOrM290(x) SETUP(XfOrM290_COUNT)
      val = NULLED_OUT ; 
      info -> size += 1 ; 
      pos = (((Scheme_Local * ) (expr ) ) -> position ) ; 
      val = FUNCCALL(SETUP_XfOrM290(_), scheme_optimize_info_lookup (info , pos , ((void * ) 0 ) ) ); 
      if (val ) {
#       define XfOrM291_COUNT (0+XfOrM290_COUNT)
#       define SETUP_XfOrM291(x) SETUP_XfOrM290(x)
        if (((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_compiled_toplevel_type ) ) )
          RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_optimize_expr (val , info ) )) RET_VALUE_EMPTY_END ; 
        RET_VALUE_START (val ) RET_VALUE_END ; 
      }
      delta = FUNCCALL(SETUP_XfOrM290(_), scheme_optimize_info_get_shift (info , pos ) ); 
      if (delta )
        expr = FUNCCALL(SETUP_XfOrM290(_), scheme_make_local (scheme_local_type , pos + delta ) ); 
      RET_VALUE_START (expr ) RET_VALUE_END ; 
    }
    case scheme_compiled_syntax_type : {
      Scheme_Syntax_Optimizer f ; 
#     define XfOrM289_COUNT (0+XfOrM281_COUNT)
#     define SETUP_XfOrM289(x) SETUP_XfOrM281(x)
      f = scheme_syntax_optimizers [(((Scheme_Simple_Object * ) (expr ) ) -> u . ptr_int_val . pint ) ] ; 
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(f ((Scheme_Object * ) (((Scheme_Simple_Object * ) (expr ) ) -> u . ptr_int_val . ptr ) , info ) )) RET_VALUE_EMPTY_END ; 
    }
    case scheme_application_type : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(optimize_application (expr , info ) )) RET_VALUE_EMPTY_END ; 
    case scheme_application2_type : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(optimize_application2 (expr , info ) )) RET_VALUE_EMPTY_END ; 
    case scheme_application3_type : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(optimize_application3 (expr , info ) )) RET_VALUE_EMPTY_END ; 
    case scheme_sequence_type : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(optimize_sequence (expr , info ) )) RET_VALUE_EMPTY_END ; 
    case scheme_branch_type : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(optimize_branch (expr , info ) )) RET_VALUE_EMPTY_END ; 
    case scheme_with_cont_mark_type : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(optimize_wcm (expr , info ) )) RET_VALUE_EMPTY_END ; 
    case scheme_compiled_unclosed_procedure_type : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_optimize_closure_compilation (expr , info ) )) RET_VALUE_EMPTY_END ; 
    case scheme_compiled_let_void_type : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_optimize_lets (expr , info , 0 ) )) RET_VALUE_EMPTY_END ; 
    case scheme_compiled_toplevel_type : if (info -> top_level_consts ) {
      int pos ; 
      Scheme_Object * c ; 
      BLOCK_SETUP((PUSH(c, 0+XfOrM281_COUNT)));
#     define XfOrM282_COUNT (1+XfOrM281_COUNT)
#     define SETUP_XfOrM282(x) SETUP(XfOrM282_COUNT)
      c = NULLED_OUT ; 
      while (1 ) {
#       define XfOrM288_COUNT (0+XfOrM282_COUNT)
#       define SETUP_XfOrM288(x) SETUP_XfOrM282(x)
        pos = (((Scheme_Toplevel * ) (expr ) ) -> position ) ; 
        c = FUNCCALL(SETUP_XfOrM288(_), scheme_hash_get (info -> top_level_consts , ((Scheme_Object * ) (void * ) (long ) ((((long ) (pos ) ) << 1 ) | 0x1 ) ) ) ); 
        if (c && ((Scheme_Type ) (((((long ) (c ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (c ) ) -> type ) ) == (Scheme_Type ) (scheme_compiled_toplevel_type ) ) )
          expr = c ; 
        else break ; 
      }
      if (c ) {
#       define XfOrM286_COUNT (0+XfOrM282_COUNT)
#       define SETUP_XfOrM286(x) SETUP_XfOrM282(x)
        if (FUNCCALL(SETUP_XfOrM286(_), scheme_compiled_duplicate_ok (c ) ))
          RET_VALUE_START (c ) RET_VALUE_END ; 
        expr = FUNCCALL(SETUP_XfOrM286(_), scheme_toplevel_to_flagged_toplevel (expr , 0x1 ) ); 
      }
      else {
#       define XfOrM283_COUNT (0+XfOrM282_COUNT)
#       define SETUP_XfOrM283(x) SETUP_XfOrM282(x)
        c = FUNCCALL(SETUP_XfOrM283(_), scheme_hash_get (info -> top_level_consts , scheme_false ) ); 
        if (c ) {
#         define XfOrM284_COUNT (0+XfOrM283_COUNT)
#         define SETUP_XfOrM284(x) SETUP_XfOrM283(x)
          c = FUNCCALL(SETUP_XfOrM284(_), scheme_hash_get ((Scheme_Hash_Table * ) c , ((Scheme_Object * ) (void * ) (long ) ((((long ) (pos ) ) << 1 ) | 0x1 ) ) ) ); 
          if (c ) {
#           define XfOrM285_COUNT (0+XfOrM284_COUNT)
#           define SETUP_XfOrM285(x) SETUP_XfOrM284(x)
            expr = FUNCCALL(SETUP_XfOrM285(_), scheme_toplevel_to_flagged_toplevel (expr , 0x2 ) ); 
          }
        }
      }
    }
    FUNCCALL(SETUP_XfOrM281(_), scheme_optimize_info_used_top (info ) ); 
    RET_VALUE_START (expr ) RET_VALUE_END ; 
    case scheme_compiled_quote_syntax_type : FUNCCALL(SETUP_XfOrM281(_), scheme_optimize_info_used_top (info ) ); 
    RET_VALUE_START (expr ) RET_VALUE_END ; 
    case scheme_variable_type : case scheme_module_variable_type : FUNCCALL_EMPTY(scheme_signal_error ("got top-level in wrong place" ) ); 
    RET_VALUE_START (0 ) RET_VALUE_END ; 
    default : info -> size += 1 ; 
    RET_VALUE_START (expr ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_optimize_clone (int dup_ok , Scheme_Object * expr , Optimize_Info * info , int delta , int closure_depth ) {
  int t ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(9);
  BLOCK_SETUP_TOP((PUSH(expr, 0), PUSH(info, 1)));
# define XfOrM293_COUNT (2)
# define SETUP_XfOrM293(x) SETUP(XfOrM293_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  t = ((((long ) (expr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (expr ) ) -> type ) ; 
  switch (t ) {
#   define XfOrM294_COUNT (0+XfOrM293_COUNT)
#   define SETUP_XfOrM294(x) SETUP_XfOrM293(x)
    case scheme_local_type : {
      int pos = (((Scheme_Local * ) (expr ) ) -> position ) ; 
#     define XfOrM309_COUNT (0+XfOrM294_COUNT)
#     define SETUP_XfOrM309(x) SETUP_XfOrM294(x)
      if (pos >= closure_depth ) {
#       define XfOrM310_COUNT (0+XfOrM309_COUNT)
#       define SETUP_XfOrM310(x) SETUP_XfOrM309(x)
        expr = FUNCCALL(SETUP_XfOrM310(_), scheme_optimize_reverse (info , pos + delta - closure_depth , 0 ) ); 
        if (closure_depth )
          expr = FUNCCALL(SETUP_XfOrM310(_), scheme_make_local (scheme_local_type , (((Scheme_Local * ) (expr ) ) -> position ) + closure_depth ) ); 
      }
      RET_VALUE_START (expr ) RET_VALUE_END ; 
    }
    case scheme_compiled_syntax_type : {
      Scheme_Syntax_Cloner f ; 
#     define XfOrM308_COUNT (0+XfOrM294_COUNT)
#     define SETUP_XfOrM308(x) SETUP_XfOrM294(x)
      f = scheme_syntax_cloners [(((Scheme_Simple_Object * ) (expr ) ) -> u . ptr_int_val . pint ) ] ; 
      if (! f )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(f (dup_ok , (Scheme_Object * ) (((Scheme_Simple_Object * ) (expr ) ) -> u . ptr_int_val . ptr ) , info , delta , closure_depth ) )) RET_VALUE_EMPTY_END ; 
    }
    case scheme_application2_type : {
      Scheme_App2_Rec * app = (Scheme_App2_Rec * ) expr , * app2 ; 
      BLOCK_SETUP((PUSH(app, 0+XfOrM294_COUNT), PUSH(app2, 1+XfOrM294_COUNT)));
#     define XfOrM307_COUNT (2+XfOrM294_COUNT)
#     define SETUP_XfOrM307(x) SETUP(XfOrM307_COUNT)
      app2 = NULLED_OUT ; 
      app2 = ((Scheme_App2_Rec * ) FUNCCALL(SETUP_XfOrM307(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_App2_Rec ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
      app2 -> iso . so . type = scheme_application2_type ; 
      expr = FUNCCALL(SETUP_XfOrM307(_), scheme_optimize_clone (dup_ok , app -> rator , info , delta , closure_depth ) ); 
      if (! expr )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      app2 -> rator = expr ; 
      expr = FUNCCALL(SETUP_XfOrM307(_), scheme_optimize_clone (dup_ok , app -> rand , info , delta , closure_depth ) ); 
      if (! expr )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      app2 -> rand = expr ; 
      RET_VALUE_START ((Scheme_Object * ) app2 ) RET_VALUE_END ; 
    }
    case scheme_application_type : {
      Scheme_App_Rec * app = (Scheme_App_Rec * ) expr , * app2 ; 
      int i ; 
      BLOCK_SETUP((PUSH(app, 0+XfOrM294_COUNT), PUSH(app2, 1+XfOrM294_COUNT)));
#     define XfOrM304_COUNT (2+XfOrM294_COUNT)
#     define SETUP_XfOrM304(x) SETUP(XfOrM304_COUNT)
      app2 = NULLED_OUT ; 
      app2 = FUNCCALL(SETUP_XfOrM304(_), scheme_malloc_application (app -> num_args + 1 ) ); 
      for (i = app -> num_args + 1 ; i -- ; ) {
#       define XfOrM306_COUNT (0+XfOrM304_COUNT)
#       define SETUP_XfOrM306(x) SETUP_XfOrM304(x)
        expr = FUNCCALL(SETUP_XfOrM306(_), scheme_optimize_clone (dup_ok , app -> args [i ] , info , delta , closure_depth ) ); 
        if (! expr )
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        app2 -> args [i ] = expr ; 
      }
      RET_VALUE_START ((Scheme_Object * ) app2 ) RET_VALUE_END ; 
    }
    case scheme_application3_type : {
      Scheme_App3_Rec * app = (Scheme_App3_Rec * ) expr , * app2 ; 
      BLOCK_SETUP((PUSH(app, 0+XfOrM294_COUNT), PUSH(app2, 1+XfOrM294_COUNT)));
#     define XfOrM303_COUNT (2+XfOrM294_COUNT)
#     define SETUP_XfOrM303(x) SETUP(XfOrM303_COUNT)
      app2 = NULLED_OUT ; 
      app2 = ((Scheme_App3_Rec * ) FUNCCALL(SETUP_XfOrM303(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_App3_Rec ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
      app2 -> iso . so . type = scheme_application3_type ; 
      expr = FUNCCALL(SETUP_XfOrM303(_), scheme_optimize_clone (dup_ok , app -> rator , info , delta , closure_depth ) ); 
      if (! expr )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      app2 -> rator = expr ; 
      expr = FUNCCALL(SETUP_XfOrM303(_), scheme_optimize_clone (dup_ok , app -> rand1 , info , delta , closure_depth ) ); 
      if (! expr )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      app2 -> rand1 = expr ; 
      expr = FUNCCALL(SETUP_XfOrM303(_), scheme_optimize_clone (dup_ok , app -> rand2 , info , delta , closure_depth ) ); 
      if (! expr )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      app2 -> rand2 = expr ; 
      RET_VALUE_START ((Scheme_Object * ) app2 ) RET_VALUE_END ; 
    }
    case scheme_compiled_let_void_type : {
      Scheme_Let_Header * head = (Scheme_Let_Header * ) expr , * head2 ; 
      Scheme_Object * body ; 
      Scheme_Compiled_Let_Value * lv , * lv2 , * prev = ((void * ) 0 ) ; 
      int i , * flags , sz ; 
      BLOCK_SETUP((PUSH(prev, 0+XfOrM294_COUNT), PUSH(head2, 1+XfOrM294_COUNT), PUSH(lv, 2+XfOrM294_COUNT), PUSH(head, 3+XfOrM294_COUNT), PUSH(body, 4+XfOrM294_COUNT), PUSH(lv2, 5+XfOrM294_COUNT), PUSH(flags, 6+XfOrM294_COUNT)));
#     define XfOrM300_COUNT (7+XfOrM294_COUNT)
#     define SETUP_XfOrM300(x) SETUP(XfOrM300_COUNT)
      head2 = NULLED_OUT ; 
      body = NULLED_OUT ; 
      lv = NULLED_OUT ; 
      lv2 = NULLED_OUT ; 
      flags = NULLED_OUT ; 
      head2 = ((Scheme_Let_Header * ) FUNCCALL(SETUP_XfOrM300(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Let_Header ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
      head2 -> iso . so . type = scheme_compiled_let_void_type ; 
      head2 -> count = head -> count ; 
      head2 -> num_clauses = head -> num_clauses ; 
      (& head2 -> iso ) -> so . keyex = (& head -> iso ) -> so . keyex ; 
      body = head -> body ; 
      for (i = head -> num_clauses ; i -- ; ) {
#       define XfOrM302_COUNT (0+XfOrM300_COUNT)
#       define SETUP_XfOrM302(x) SETUP_XfOrM300(x)
        lv = (Scheme_Compiled_Let_Value * ) body ; 
        sz = sizeof (int ) * lv -> count ; 
        flags = (int * ) FUNCCALL(SETUP_XfOrM302(_), GC_malloc_atomic (sz ) ); 
        (memcpy (flags , lv -> flags , sz ) ) ; 
        lv2 = ((Scheme_Compiled_Let_Value * ) FUNCCALL(SETUP_XfOrM302(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Compiled_Let_Value ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
        lv2 -> so . type = scheme_compiled_let_value_type ; 
        lv2 -> count = lv -> count ; 
        lv2 -> position = lv -> position ; 
        lv2 -> flags = flags ; 
        expr = FUNCCALL(SETUP_XfOrM302(_), scheme_optimize_clone (dup_ok , lv -> value , info , delta , closure_depth + head -> count ) ); 
        if (! expr )
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        lv2 -> value = expr ; 
        if (prev )
          prev -> body = (Scheme_Object * ) lv2 ; 
        else head2 -> body = (Scheme_Object * ) lv2 ; 
        prev = lv2 ; 
        body = lv -> body ; 
      }
      if (prev )
        prev -> body = body ; 
      else head2 -> body = body ; 
      expr = FUNCCALL(SETUP_XfOrM300(_), scheme_optimize_clone (dup_ok , body , info , delta , closure_depth + head -> count ) ); 
      if (! expr )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      if (prev )
        prev -> body = expr ; 
      else head2 -> body = expr ; 
      RET_VALUE_START ((Scheme_Object * ) head2 ) RET_VALUE_END ; 
    }
    case scheme_sequence_type : case scheme_begin0_sequence_type : {
      Scheme_Sequence * seq = (Scheme_Sequence * ) expr , * seq2 ; 
      int i ; 
      BLOCK_SETUP((PUSH(seq, 0+XfOrM294_COUNT), PUSH(seq2, 1+XfOrM294_COUNT)));
#     define XfOrM297_COUNT (2+XfOrM294_COUNT)
#     define SETUP_XfOrM297(x) SETUP(XfOrM297_COUNT)
      seq2 = NULLED_OUT ; 
      seq2 = FUNCCALL(SETUP_XfOrM297(_), malloc_sequence (seq -> count ) ); 
      seq2 -> so . type = seq -> so . type ; 
      seq2 -> count = seq -> count ; 
      for (i = seq -> count ; i -- ; ) {
#       define XfOrM299_COUNT (0+XfOrM297_COUNT)
#       define SETUP_XfOrM299(x) SETUP_XfOrM297(x)
        expr = FUNCCALL(SETUP_XfOrM299(_), scheme_optimize_clone (dup_ok , seq -> array [i ] , info , delta , closure_depth ) ); 
        if (! expr )
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        seq2 -> array [i ] = expr ; 
      }
      RET_VALUE_START ((Scheme_Object * ) seq2 ) RET_VALUE_END ; 
    }
    case scheme_branch_type : {
      Scheme_Branch_Rec * b = (Scheme_Branch_Rec * ) expr , * b2 ; 
      BLOCK_SETUP((PUSH(b2, 0+XfOrM294_COUNT), PUSH(b, 1+XfOrM294_COUNT)));
#     define XfOrM296_COUNT (2+XfOrM294_COUNT)
#     define SETUP_XfOrM296(x) SETUP(XfOrM296_COUNT)
      b2 = NULLED_OUT ; 
      b2 = ((Scheme_Branch_Rec * ) FUNCCALL(SETUP_XfOrM296(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Branch_Rec ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
      b2 -> so . type = scheme_branch_type ; 
      expr = FUNCCALL(SETUP_XfOrM296(_), scheme_optimize_clone (dup_ok , b -> test , info , delta , closure_depth ) ); 
      if (! expr )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      b2 -> test = expr ; 
      expr = FUNCCALL(SETUP_XfOrM296(_), scheme_optimize_clone (dup_ok , b -> tbranch , info , delta , closure_depth ) ); 
      if (! expr )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      b2 -> tbranch = expr ; 
      expr = FUNCCALL(SETUP_XfOrM296(_), scheme_optimize_clone (dup_ok , b -> fbranch , info , delta , closure_depth ) ); 
      if (! expr )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      b2 -> fbranch = expr ; 
      RET_VALUE_START ((Scheme_Object * ) b2 ) RET_VALUE_END ; 
    }
    case scheme_compiled_unclosed_procedure_type : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_clone_closure_compilation (dup_ok , expr , info , delta , closure_depth ) )) RET_VALUE_EMPTY_END ; 
    case scheme_compiled_toplevel_type : case scheme_compiled_quote_syntax_type : RET_VALUE_START (expr ) RET_VALUE_END ; 
    default : if (t > _scheme_compiled_values_types_ ) {
#     define XfOrM295_COUNT (0+XfOrM294_COUNT)
#     define SETUP_XfOrM295(x) SETUP_XfOrM294(x)
      if (dup_ok || FUNCCALL(SETUP_XfOrM295(_), scheme_compiled_duplicate_ok (expr ) ))
        RET_VALUE_START (expr ) RET_VALUE_END ; 
    }
  }
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_optimize_shift (Scheme_Object * expr , int delta , int after_depth ) {
  int t ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(expr, 0)));
# define XfOrM311_COUNT (1)
# define SETUP_XfOrM311(x) SETUP(XfOrM311_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  t = ((((long ) (expr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (expr ) ) -> type ) ; 
  switch (t ) {
#   define XfOrM312_COUNT (0+XfOrM311_COUNT)
#   define SETUP_XfOrM312(x) SETUP_XfOrM311(x)
    case scheme_local_type : case scheme_local_unbox_type : {
      int pos = (((Scheme_Local * ) (expr ) ) -> position ) ; 
#     define XfOrM328_COUNT (0+XfOrM312_COUNT)
#     define SETUP_XfOrM328(x) SETUP_XfOrM312(x)
      if (pos >= after_depth ) {
#       define XfOrM329_COUNT (0+XfOrM328_COUNT)
#       define SETUP_XfOrM329(x) SETUP_XfOrM328(x)
        expr = FUNCCALL(SETUP_XfOrM329(_), scheme_make_local (t , (((Scheme_Local * ) (expr ) ) -> position ) + delta ) ); 
      }
      RET_VALUE_START (expr ) RET_VALUE_END ; 
    }
    case scheme_compiled_syntax_type : {
      Scheme_Syntax_Shifter f ; 
#     define XfOrM326_COUNT (0+XfOrM312_COUNT)
#     define SETUP_XfOrM326(x) SETUP_XfOrM312(x)
      f = scheme_syntax_shifters [(((Scheme_Simple_Object * ) (expr ) ) -> u . ptr_int_val . pint ) ] ; 
      if (! f ) {
#       define XfOrM327_COUNT (0+XfOrM326_COUNT)
#       define SETUP_XfOrM327(x) SETUP_XfOrM326(x)
        FUNCCALL_EMPTY(scheme_signal_error ("scheme_optimize_shift: no shift available for %d" , (((Scheme_Simple_Object * ) (expr ) ) -> u . ptr_int_val . pint ) ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(f ((Scheme_Object * ) (((Scheme_Simple_Object * ) (expr ) ) -> u . ptr_int_val . ptr ) , delta , after_depth ) )) RET_VALUE_EMPTY_END ; 
    }
    case scheme_application_type : {
      Scheme_App_Rec * app = (Scheme_App_Rec * ) expr ; 
      int i ; 
      BLOCK_SETUP((PUSH(app, 0+XfOrM312_COUNT)));
#     define XfOrM323_COUNT (1+XfOrM312_COUNT)
#     define SETUP_XfOrM323(x) SETUP(XfOrM323_COUNT)
      for (i = app -> num_args + 1 ; i -- ; ) {
#       define XfOrM325_COUNT (0+XfOrM323_COUNT)
#       define SETUP_XfOrM325(x) SETUP_XfOrM323(x)
        expr = FUNCCALL(SETUP_XfOrM325(_), scheme_optimize_shift (app -> args [i ] , delta , after_depth ) ); 
        app -> args [i ] = expr ; 
      }
      RET_VALUE_START ((Scheme_Object * ) app ) RET_VALUE_END ; 
    }
    case scheme_application2_type : {
      Scheme_App2_Rec * app = (Scheme_App2_Rec * ) expr ; 
      BLOCK_SETUP((PUSH(app, 0+XfOrM312_COUNT)));
#     define XfOrM322_COUNT (1+XfOrM312_COUNT)
#     define SETUP_XfOrM322(x) SETUP(XfOrM322_COUNT)
      expr = FUNCCALL(SETUP_XfOrM322(_), scheme_optimize_shift (app -> rator , delta , after_depth ) ); 
      app -> rator = expr ; 
      expr = FUNCCALL(SETUP_XfOrM322(_), scheme_optimize_shift (app -> rand , delta , after_depth ) ); 
      app -> rand = expr ; 
      RET_VALUE_START ((Scheme_Object * ) app ) RET_VALUE_END ; 
    }
    case scheme_application3_type : {
      Scheme_App3_Rec * app = (Scheme_App3_Rec * ) expr ; 
      BLOCK_SETUP((PUSH(app, 0+XfOrM312_COUNT)));
#     define XfOrM321_COUNT (1+XfOrM312_COUNT)
#     define SETUP_XfOrM321(x) SETUP(XfOrM321_COUNT)
      expr = FUNCCALL(SETUP_XfOrM321(_), scheme_optimize_shift (app -> rator , delta , after_depth ) ); 
      app -> rator = expr ; 
      expr = FUNCCALL(SETUP_XfOrM321(_), scheme_optimize_shift (app -> rand1 , delta , after_depth ) ); 
      app -> rand1 = expr ; 
      expr = FUNCCALL(SETUP_XfOrM321(_), scheme_optimize_shift (app -> rand2 , delta , after_depth ) ); 
      app -> rand2 = expr ; 
      RET_VALUE_START ((Scheme_Object * ) app ) RET_VALUE_END ; 
    }
    case scheme_compiled_let_void_type : {
      Scheme_Let_Header * head = (Scheme_Let_Header * ) expr ; 
      Scheme_Object * body ; 
      Scheme_Compiled_Let_Value * lv = ((void * ) 0 ) ; 
      int i ; 
      BLOCK_SETUP((PUSH(lv, 0+XfOrM312_COUNT), PUSH(head, 1+XfOrM312_COUNT), PUSH(body, 2+XfOrM312_COUNT)));
#     define XfOrM318_COUNT (3+XfOrM312_COUNT)
#     define SETUP_XfOrM318(x) SETUP(XfOrM318_COUNT)
      body = NULLED_OUT ; 
      body = head -> body ; 
      for (i = head -> num_clauses ; i -- ; ) {
#       define XfOrM320_COUNT (0+XfOrM318_COUNT)
#       define SETUP_XfOrM320(x) SETUP_XfOrM318(x)
        lv = (Scheme_Compiled_Let_Value * ) body ; 
        expr = FUNCCALL(SETUP_XfOrM320(_), scheme_optimize_shift (lv -> value , delta , after_depth + head -> count ) ); 
        lv -> value = expr ; 
        body = lv -> body ; 
      }
      expr = FUNCCALL(SETUP_XfOrM318(_), scheme_optimize_shift (body , delta , after_depth + head -> count ) ); 
      if (head -> num_clauses )
        lv -> body = expr ; 
      else head -> body = expr ; 
      RET_VALUE_START ((Scheme_Object * ) head ) RET_VALUE_END ; 
    }
    case scheme_sequence_type : case scheme_begin0_sequence_type : {
      Scheme_Sequence * seq = (Scheme_Sequence * ) expr ; 
      int i ; 
      BLOCK_SETUP((PUSH(seq, 0+XfOrM312_COUNT)));
#     define XfOrM315_COUNT (1+XfOrM312_COUNT)
#     define SETUP_XfOrM315(x) SETUP(XfOrM315_COUNT)
      for (i = seq -> count ; i -- ; ) {
#       define XfOrM317_COUNT (0+XfOrM315_COUNT)
#       define SETUP_XfOrM317(x) SETUP_XfOrM315(x)
        expr = FUNCCALL(SETUP_XfOrM317(_), scheme_optimize_shift (seq -> array [i ] , delta , after_depth ) ); 
        seq -> array [i ] = expr ; 
      }
      RET_VALUE_START ((Scheme_Object * ) seq ) RET_VALUE_END ; 
    }
    case scheme_branch_type : {
      Scheme_Branch_Rec * b = (Scheme_Branch_Rec * ) expr ; 
      BLOCK_SETUP((PUSH(b, 0+XfOrM312_COUNT)));
#     define XfOrM314_COUNT (1+XfOrM312_COUNT)
#     define SETUP_XfOrM314(x) SETUP(XfOrM314_COUNT)
      expr = FUNCCALL(SETUP_XfOrM314(_), scheme_optimize_shift (b -> test , delta , after_depth ) ); 
      b -> test = expr ; 
      expr = FUNCCALL(SETUP_XfOrM314(_), scheme_optimize_shift (b -> tbranch , delta , after_depth ) ); 
      b -> tbranch = expr ; 
      expr = FUNCCALL(SETUP_XfOrM314(_), scheme_optimize_shift (b -> fbranch , delta , after_depth ) ); 
      b -> fbranch = expr ; 
      RET_VALUE_START ((Scheme_Object * ) b ) RET_VALUE_END ; 
    }
    case scheme_with_cont_mark_type : {
      Scheme_With_Continuation_Mark * wcm = (Scheme_With_Continuation_Mark * ) expr ; 
      BLOCK_SETUP((PUSH(wcm, 0+XfOrM312_COUNT)));
#     define XfOrM313_COUNT (1+XfOrM312_COUNT)
#     define SETUP_XfOrM313(x) SETUP(XfOrM313_COUNT)
      expr = FUNCCALL(SETUP_XfOrM313(_), scheme_optimize_shift (wcm -> key , delta , after_depth ) ); 
      wcm -> key = expr ; 
      expr = FUNCCALL(SETUP_XfOrM313(_), scheme_optimize_shift (wcm -> val , delta , after_depth ) ); 
      wcm -> val = expr ; 
      expr = FUNCCALL(SETUP_XfOrM313(_), scheme_optimize_shift (wcm -> body , delta , after_depth ) ); 
      wcm -> body = expr ; 
      RET_VALUE_START ((Scheme_Object * ) wcm ) RET_VALUE_END ; 
    }
    case scheme_compiled_unclosed_procedure_type : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_shift_closure_compilation (expr , delta , after_depth ) )) RET_VALUE_EMPTY_END ; 
    case scheme_compiled_toplevel_type : case scheme_compiled_quote_syntax_type : RET_VALUE_START (expr ) RET_VALUE_END ; 
    default : RET_VALUE_START (expr ) RET_VALUE_END ; 
  }
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * jit_application (Scheme_Object * o ) {
  Scheme_Object * orig , * naya = ((void * ) 0 ) ; 
  Scheme_App_Rec * app , * app2 ; 
  int i , n , size ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(orig, 0), PUSH(app, 1), PUSH(app2, 2), PUSH(naya, 3), PUSH(o, 4)));
# define XfOrM330_COUNT (5)
# define SETUP_XfOrM330(x) SETUP(XfOrM330_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  orig = NULLED_OUT ; 
  app = NULLED_OUT ; 
  app2 = NULLED_OUT ; 
  app = (Scheme_App_Rec * ) o ; 
  n = app -> num_args + 1 ; 
  for (i = 0 ; i < n ; i ++ ) {
#   define XfOrM334_COUNT (0+XfOrM330_COUNT)
#   define SETUP_XfOrM334(x) SETUP_XfOrM330(x)
    orig = app -> args [i ] ; 
    naya = FUNCCALL(SETUP_XfOrM334(_), scheme_jit_expr (orig ) ); 
    if (! ((orig ) == (naya ) ) )
      break ; 
  }
  if (i >= n )
    RET_VALUE_START (o ) RET_VALUE_END ; 
  size = (sizeof (Scheme_App_Rec ) + ((n - 1 ) * sizeof (Scheme_Object * ) ) + n * sizeof (char ) ) ; 
  app2 = (Scheme_App_Rec * ) FUNCCALL(SETUP_XfOrM330(_), GC_malloc_one_tagged (size ) ); 
  (memcpy (app2 , app , size ) ) ; 
  app2 -> args [i ] = naya ; 
  for (i ++ ; i < n ; i ++ ) {
#   define XfOrM332_COUNT (0+XfOrM330_COUNT)
#   define SETUP_XfOrM332(x) SETUP_XfOrM330(x)
    orig = app2 -> args [i ] ; 
    naya = FUNCCALL(SETUP_XfOrM332(_), scheme_jit_expr (orig ) ); 
    app2 -> args [i ] = naya ; 
  }
  RET_VALUE_START ((Scheme_Object * ) app2 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * jit_application2 (Scheme_Object * o ) {
  Scheme_App2_Rec * app ; 
  Scheme_Object * nrator , * nrand ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(app, 0), PUSH(nrand, 1), PUSH(nrator, 2), PUSH(o, 3)));
# define XfOrM335_COUNT (4)
# define SETUP_XfOrM335(x) SETUP(XfOrM335_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  app = NULLED_OUT ; 
  nrator = NULLED_OUT ; 
  nrand = NULLED_OUT ; 
  app = (Scheme_App2_Rec * ) o ; 
  nrator = FUNCCALL(SETUP_XfOrM335(_), scheme_jit_expr (app -> rator ) ); 
  nrand = FUNCCALL_AGAIN(scheme_jit_expr (app -> rand ) ); 
  if (((nrator ) == (app -> rator ) ) && ((nrand ) == (app -> rand ) ) )
    RET_VALUE_START (o ) RET_VALUE_END ; 
  app = ((Scheme_App2_Rec * ) FUNCCALL(SETUP_XfOrM335(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_App2_Rec ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  (memcpy (app , o , sizeof (Scheme_App2_Rec ) ) ) ; 
  app -> rator = nrator ; 
  app -> rand = nrand ; 
  RET_VALUE_START ((Scheme_Object * ) app ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * jit_application3 (Scheme_Object * o ) {
  Scheme_App3_Rec * app ; 
  Scheme_Object * nrator , * nrand1 , * nrand2 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(app, 0), PUSH(nrand1, 1), PUSH(nrator, 2), PUSH(nrand2, 3), PUSH(o, 4)));
# define XfOrM336_COUNT (5)
# define SETUP_XfOrM336(x) SETUP(XfOrM336_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  app = NULLED_OUT ; 
  nrator = NULLED_OUT ; 
  nrand1 = NULLED_OUT ; 
  nrand2 = NULLED_OUT ; 
  app = (Scheme_App3_Rec * ) o ; 
  nrator = FUNCCALL(SETUP_XfOrM336(_), scheme_jit_expr (app -> rator ) ); 
  nrand1 = FUNCCALL_AGAIN(scheme_jit_expr (app -> rand1 ) ); 
  nrand2 = FUNCCALL_AGAIN(scheme_jit_expr (app -> rand2 ) ); 
  if (((nrator ) == (app -> rator ) ) && ((nrand1 ) == (app -> rand1 ) ) && ((nrand2 ) == (app -> rand2 ) ) )
    RET_VALUE_START (o ) RET_VALUE_END ; 
  app = ((Scheme_App3_Rec * ) FUNCCALL(SETUP_XfOrM336(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_App3_Rec ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  (memcpy (app , o , sizeof (Scheme_App3_Rec ) ) ) ; 
  app -> rator = nrator ; 
  app -> rand1 = nrand1 ; 
  app -> rand2 = nrand2 ; 
  RET_VALUE_START ((Scheme_Object * ) app ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * jit_sequence (Scheme_Object * o ) {
  Scheme_Object * orig , * naya = ((void * ) 0 ) ; 
  Scheme_Sequence * seq , * seq2 ; 
  int i , n , size ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(orig, 0), PUSH(seq, 1), PUSH(seq2, 2), PUSH(naya, 3), PUSH(o, 4)));
# define XfOrM337_COUNT (5)
# define SETUP_XfOrM337(x) SETUP(XfOrM337_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  orig = NULLED_OUT ; 
  seq = NULLED_OUT ; 
  seq2 = NULLED_OUT ; 
  seq = (Scheme_Sequence * ) o ; 
  n = seq -> count ; 
  for (i = 0 ; i < n ; i ++ ) {
#   define XfOrM341_COUNT (0+XfOrM337_COUNT)
#   define SETUP_XfOrM341(x) SETUP_XfOrM337(x)
    orig = seq -> array [i ] ; 
    naya = FUNCCALL(SETUP_XfOrM341(_), scheme_jit_expr (orig ) ); 
    if (! ((orig ) == (naya ) ) )
      break ; 
  }
  if (i >= n )
    RET_VALUE_START (o ) RET_VALUE_END ; 
  size = (sizeof (Scheme_Sequence ) + ((n - 1 ) * sizeof (Scheme_Object * ) ) ) ; 
  seq2 = (Scheme_Sequence * ) FUNCCALL(SETUP_XfOrM337(_), GC_malloc_one_tagged (size ) ); 
  (memcpy (seq2 , seq , size ) ) ; 
  seq2 -> array [i ] = naya ; 
  for (i ++ ; i < n ; i ++ ) {
#   define XfOrM339_COUNT (0+XfOrM337_COUNT)
#   define SETUP_XfOrM339(x) SETUP_XfOrM337(x)
    orig = seq2 -> array [i ] ; 
    naya = FUNCCALL(SETUP_XfOrM339(_), scheme_jit_expr (orig ) ); 
    seq2 -> array [i ] = naya ; 
  }
  RET_VALUE_START ((Scheme_Object * ) seq2 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * jit_branch (Scheme_Object * o ) {
  Scheme_Branch_Rec * b ; 
  Scheme_Object * t , * tb , * fb ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(tb, 0), PUSH(t, 1), PUSH(b, 2), PUSH(fb, 3), PUSH(o, 4)));
# define XfOrM342_COUNT (5)
# define SETUP_XfOrM342(x) SETUP(XfOrM342_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  b = NULLED_OUT ; 
  t = NULLED_OUT ; 
  tb = NULLED_OUT ; 
  fb = NULLED_OUT ; 
  b = (Scheme_Branch_Rec * ) o ; 
  t = FUNCCALL(SETUP_XfOrM342(_), scheme_jit_expr (b -> test ) ); 
  tb = FUNCCALL_AGAIN(scheme_jit_expr (b -> tbranch ) ); 
  fb = FUNCCALL_AGAIN(scheme_jit_expr (b -> fbranch ) ); 
  if (((t ) == (b -> test ) ) && ((tb ) == (b -> tbranch ) ) && ((fb ) == (b -> fbranch ) ) )
    RET_VALUE_START (o ) RET_VALUE_END ; 
  b = ((Scheme_Branch_Rec * ) FUNCCALL(SETUP_XfOrM342(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Branch_Rec ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  (memcpy (b , o , sizeof (Scheme_Branch_Rec ) ) ) ; 
  b -> test = t ; 
  b -> tbranch = tb ; 
  b -> fbranch = fb ; 
  RET_VALUE_START ((Scheme_Object * ) b ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * jit_let_value (Scheme_Object * o ) {
  Scheme_Let_Value * lv = (Scheme_Let_Value * ) o ; 
  Scheme_Object * body , * rhs ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(lv, 0), PUSH(rhs, 1), PUSH(body, 2), PUSH(o, 3)));
# define XfOrM343_COUNT (4)
# define SETUP_XfOrM343(x) SETUP(XfOrM343_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  body = NULLED_OUT ; 
  rhs = NULLED_OUT ; 
  rhs = FUNCCALL(SETUP_XfOrM343(_), scheme_jit_expr (lv -> value ) ); 
  body = FUNCCALL_AGAIN(scheme_jit_expr (lv -> body ) ); 
  if (((rhs ) == (lv -> value ) ) && ((body ) == (lv -> body ) ) )
    RET_VALUE_START (o ) RET_VALUE_END ; 
  lv = ((Scheme_Let_Value * ) FUNCCALL(SETUP_XfOrM343(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Let_Value ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  (memcpy (lv , o , sizeof (Scheme_Let_Value ) ) ) ; 
  lv -> value = rhs ; 
  lv -> body = body ; 
  RET_VALUE_START ((Scheme_Object * ) lv ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * jit_let_one (Scheme_Object * o ) {
  Scheme_Let_One * lo = (Scheme_Let_One * ) o ; 
  Scheme_Object * body , * rhs ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(rhs, 0), PUSH(lo, 1), PUSH(body, 2), PUSH(o, 3)));
# define XfOrM344_COUNT (4)
# define SETUP_XfOrM344(x) SETUP(XfOrM344_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  body = NULLED_OUT ; 
  rhs = NULLED_OUT ; 
  rhs = FUNCCALL(SETUP_XfOrM344(_), scheme_jit_expr (lo -> value ) ); 
  body = FUNCCALL_AGAIN(scheme_jit_expr (lo -> body ) ); 
  if (((rhs ) == (lo -> value ) ) && ((body ) == (lo -> body ) ) )
    RET_VALUE_START (o ) RET_VALUE_END ; 
  lo = ((Scheme_Let_One * ) FUNCCALL(SETUP_XfOrM344(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Let_One ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  (memcpy (lo , o , sizeof (Scheme_Let_One ) ) ) ; 
  lo -> value = rhs ; 
  lo -> body = body ; 
  RET_VALUE_START ((Scheme_Object * ) lo ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * jit_let_void (Scheme_Object * o ) {
  Scheme_Let_Void * lv = (Scheme_Let_Void * ) o ; 
  Scheme_Object * body ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(lv, 0), PUSH(body, 1), PUSH(o, 2)));
# define XfOrM345_COUNT (3)
# define SETUP_XfOrM345(x) SETUP(XfOrM345_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  body = NULLED_OUT ; 
  body = FUNCCALL(SETUP_XfOrM345(_), scheme_jit_expr (lv -> body ) ); 
  if (((body ) == (lv -> body ) ) )
    RET_VALUE_START (o ) RET_VALUE_END ; 
  lv = ((Scheme_Let_Void * ) FUNCCALL(SETUP_XfOrM345(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Let_Void ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  (memcpy (lv , o , sizeof (Scheme_Let_Void ) ) ) ; 
  lv -> body = body ; 
  RET_VALUE_START ((Scheme_Object * ) lv ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * jit_letrec (Scheme_Object * o ) {
  Scheme_Letrec * lr = (Scheme_Letrec * ) o , * lr2 ; 
  Scheme_Object * * procs , * * procs2 , * v ; 
  int i , count ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(lr, 0), PUSH(procs2, 1), PUSH(lr2, 2), PUSH(v, 3), PUSH(procs, 4)));
# define XfOrM346_COUNT (5)
# define SETUP_XfOrM346(x) SETUP(XfOrM346_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  lr2 = NULLED_OUT ; 
  procs = NULLED_OUT ; 
  procs2 = NULLED_OUT ; 
  v = NULLED_OUT ; 
  count = lr -> count ; 
  lr2 = ((Scheme_Letrec * ) FUNCCALL(SETUP_XfOrM346(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Letrec ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  (memcpy (lr2 , lr , sizeof (Scheme_Letrec ) ) ) ; 
  procs = lr -> procs ; 
  procs2 = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM346(_), GC_malloc (sizeof (Scheme_Object * ) * (count ) ) )) ; 
  lr2 -> procs = procs2 ; 
  for (i = 0 ; i < count ; i ++ ) {
#   define XfOrM348_COUNT (0+XfOrM346_COUNT)
#   define SETUP_XfOrM348(x) SETUP_XfOrM346(x)
    v = FUNCCALL(SETUP_XfOrM348(_), scheme_jit_closure (procs [i ] , (Scheme_Object * ) lr2 ) ); 
    procs2 [i ] = v ; 
  }
  v = FUNCCALL(SETUP_XfOrM346(_), scheme_jit_expr (lr -> body ) ); 
  lr2 -> body = v ; 
  RET_VALUE_START ((Scheme_Object * ) lr2 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * jit_wcm (Scheme_Object * o ) {
  Scheme_With_Continuation_Mark * wcm = (Scheme_With_Continuation_Mark * ) o ; 
  Scheme_Object * k , * v , * b ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(k, 0), PUSH(v, 1), PUSH(b, 2), PUSH(wcm, 3), PUSH(o, 4)));
# define XfOrM349_COUNT (5)
# define SETUP_XfOrM349(x) SETUP(XfOrM349_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  k = NULLED_OUT ; 
  v = NULLED_OUT ; 
  b = NULLED_OUT ; 
  k = FUNCCALL(SETUP_XfOrM349(_), scheme_jit_expr (wcm -> key ) ); 
  v = FUNCCALL_AGAIN(scheme_jit_expr (wcm -> val ) ); 
  b = FUNCCALL_AGAIN(scheme_jit_expr (wcm -> body ) ); 
  if (((wcm -> key ) == (k ) ) && ((wcm -> val ) == (v ) ) && ((wcm -> body ) == (b ) ) )
    RET_VALUE_START (o ) RET_VALUE_END ; 
  wcm = ((Scheme_With_Continuation_Mark * ) FUNCCALL(SETUP_XfOrM349(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_With_Continuation_Mark ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  (memcpy (wcm , o , sizeof (Scheme_With_Continuation_Mark ) ) ) ; 
  wcm -> key = k ; 
  wcm -> val = v ; 
  wcm -> body = b ; 
  RET_VALUE_START ((Scheme_Object * ) wcm ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_jit_expr (Scheme_Object * expr ) {
  Scheme_Type type = ((((long ) (expr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (expr ) ) -> type ) ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(expr, 0)));
# define XfOrM350_COUNT (1)
# define SETUP_XfOrM350(x) SETUP(XfOrM350_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  switch (type ) {
#   define XfOrM351_COUNT (0+XfOrM350_COUNT)
#   define SETUP_XfOrM351(x) SETUP_XfOrM350(x)
    case scheme_syntax_type : {
      Scheme_Syntax_Jitter f ; 
      Scheme_Object * orig , * naya ; 
      BLOCK_SETUP((PUSH(naya, 0+XfOrM351_COUNT), PUSH(orig, 1+XfOrM351_COUNT)));
#     define XfOrM355_COUNT (2+XfOrM351_COUNT)
#     define SETUP_XfOrM355(x) SETUP(XfOrM355_COUNT)
      orig = NULLED_OUT ; 
      naya = NULLED_OUT ; 
      f = scheme_syntax_jitters [(((Scheme_Simple_Object * ) (expr ) ) -> u . ptr_int_val . pint ) ] ; 
      orig = (((Scheme_Simple_Object * ) (expr ) ) -> u . ptr_int_val . ptr ) ; 
      naya = FUNCCALL(SETUP_XfOrM355(_), f (orig ) ); 
      if (((orig ) == (naya ) ) )
        RET_VALUE_START (expr ) RET_VALUE_END ; 
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_syntax_resolved ((((Scheme_Simple_Object * ) (expr ) ) -> u . ptr_int_val . pint ) , naya ) )) RET_VALUE_EMPTY_END ; 
    }
    case scheme_application_type : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(jit_application (expr ) )) RET_VALUE_EMPTY_END ; 
    case scheme_application2_type : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(jit_application2 (expr ) )) RET_VALUE_EMPTY_END ; 
    case scheme_application3_type : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(jit_application3 (expr ) )) RET_VALUE_EMPTY_END ; 
    case scheme_sequence_type : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(jit_sequence (expr ) )) RET_VALUE_EMPTY_END ; 
    case scheme_branch_type : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(jit_branch (expr ) )) RET_VALUE_EMPTY_END ; 
    case scheme_with_cont_mark_type : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(jit_wcm (expr ) )) RET_VALUE_EMPTY_END ; 
    case scheme_unclosed_procedure_type : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_jit_closure (expr , ((void * ) 0 ) ) )) RET_VALUE_EMPTY_END ; 
    case scheme_let_value_type : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(jit_let_value (expr ) )) RET_VALUE_EMPTY_END ; 
    case scheme_let_void_type : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(jit_let_void (expr ) )) RET_VALUE_EMPTY_END ; 
    case scheme_letrec_type : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(jit_letrec (expr ) )) RET_VALUE_EMPTY_END ; 
    case scheme_let_one_type : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(jit_let_one (expr ) )) RET_VALUE_EMPTY_END ; 
    case scheme_closure_type : {
      Scheme_Closure * c = (Scheme_Closure * ) expr ; 
#     define XfOrM353_COUNT (0+XfOrM351_COUNT)
#     define SETUP_XfOrM353(x) SETUP_XfOrM351(x)
      if (! (c -> code -> closure_size ) ) {
#       define XfOrM354_COUNT (0+XfOrM353_COUNT)
#       define SETUP_XfOrM354(x) SETUP_XfOrM353(x)
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_jit_closure ((Scheme_Object * ) c -> code , ((void * ) 0 ) ) )) RET_VALUE_EMPTY_END ; 
      }
      else RET_VALUE_START (expr ) RET_VALUE_END ; 
    }
    case scheme_case_closure_type : {
#     define XfOrM352_COUNT (0+XfOrM351_COUNT)
#     define SETUP_XfOrM352(x) SETUP_XfOrM351(x)
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_unclose_case_lambda (expr , 1 ) )) RET_VALUE_EMPTY_END ; 
    }
    default : RET_VALUE_START (expr ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_default_compile_rec (Scheme_Compile_Info * rec , int drec ) {
  /* No conversion */
}
void scheme_init_compile_recs (Scheme_Compile_Info * src , int drec , Scheme_Compile_Info * dest , int n ) {
  /* No conversion */
  int i ; 
  for (i = 0 ; i < n ; i ++ ) {
    dest [i ] . type = scheme_rt_compile_info ; 
    dest [i ] . comp = 1 ; 
    dest [i ] . dont_mark_local_use = src [drec ] . dont_mark_local_use ; 
    dest [i ] . resolve_module_ids = src [drec ] . resolve_module_ids ; 
    dest [i ] . value_name = scheme_false ; 
    dest [i ] . certs = src [drec ] . certs ; 
    dest [i ] . observer = src [drec ] . observer ; 
  }
}
void scheme_init_expand_recs (Scheme_Expand_Info * src , int drec , Scheme_Expand_Info * dest , int n ) {
  /* No conversion */
  int i ; 
  for (i = 0 ; i < n ; i ++ ) {
    dest [i ] . type = scheme_rt_compile_info ; 
    dest [i ] . comp = 0 ; 
    dest [i ] . depth = src [drec ] . depth ; 
    dest [i ] . value_name = scheme_false ; 
    dest [i ] . certs = src [drec ] . certs ; 
    dest [i ] . observer = src [drec ] . observer ; 
  }
}
void scheme_merge_compile_recs (Scheme_Compile_Info * src , int drec , Scheme_Compile_Info * dest , int n ) {
  /* No conversion */
}
void scheme_init_lambda_rec (Scheme_Compile_Info * src , int drec , Scheme_Compile_Info * lam , int dlrec ) {
  /* No conversion */
  lam [dlrec ] . type = scheme_rt_compile_info ; 
  lam [dlrec ] . comp = 1 ; 
  lam [dlrec ] . dont_mark_local_use = src [drec ] . dont_mark_local_use ; 
  lam [dlrec ] . resolve_module_ids = src [drec ] . resolve_module_ids ; 
  lam [dlrec ] . value_name = scheme_false ; 
  lam [dlrec ] . certs = src [drec ] . certs ; 
  lam [dlrec ] . observer = src [drec ] . observer ; 
}
void scheme_merge_lambda_rec (Scheme_Compile_Info * src , int drec , Scheme_Compile_Info * lam , int dlrec ) {
  /* No conversion */
}
void scheme_compile_rec_done_local (Scheme_Compile_Info * rec , int drec ) {
  /* No conversion */
  rec [drec ] . value_name = scheme_false ; 
}
void scheme_rec_add_certs (Scheme_Compile_Expand_Info * src , int drec , Scheme_Object * stx ) {
  Scheme_Object * certs ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(src, 0), PUSH(certs, 1)));
# define XfOrM367_COUNT (2)
# define SETUP_XfOrM367(x) SETUP(XfOrM367_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  certs = NULLED_OUT ; 
  certs = FUNCCALL(SETUP_XfOrM367(_), scheme_stx_extract_certs (stx , src [drec ] . certs ) ); 
  src [drec ] . certs = certs ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * scheme_inner_compile_list (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec , int start_app_position ) {
  int len ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(26);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(rec, 1), PUSH(form, 2)));
# define XfOrM368_COUNT (3)
# define SETUP_XfOrM368(x) SETUP(XfOrM368_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  len = FUNCCALL(SETUP_XfOrM368(_), scheme_stx_proper_list_length (form ) ); 
  if (! len ) {
#   define XfOrM373_COUNT (0+XfOrM368_COUNT)
#   define SETUP_XfOrM373(x) SETUP_XfOrM368(x)
    FUNCCALL(SETUP_XfOrM373(_), scheme_compile_rec_done_local (rec , drec ) ); 
    FUNCCALL(SETUP_XfOrM373(_), scheme_default_compile_rec (rec , drec ) ); 
    RET_VALUE_START (scheme_null ) RET_VALUE_END ; 
  }
  else if (len > 0 ) {
    Scheme_Compile_Info * recs , quick [5 ] ; 
    int i ; 
    Scheme_Object * c , * p , * comp_first , * comp_last , * name , * first , * rest ; 
    BLOCK_SETUP((PUSH(first, 0+XfOrM368_COUNT), PUSH(name, 1+XfOrM368_COUNT), PUSH(c, 2+XfOrM368_COUNT), PUSH(comp_first, 3+XfOrM368_COUNT), PUSH(recs, 4+XfOrM368_COUNT), PUSH(comp_last, 5+XfOrM368_COUNT), PUSH(quick[0].value_name, 6+XfOrM368_COUNT), PUSH(quick[0].certs, 7+XfOrM368_COUNT), PUSH(quick[0].observer, 8+XfOrM368_COUNT), PUSH(quick[1].value_name, 9+XfOrM368_COUNT), PUSH(quick[1].certs, 10+XfOrM368_COUNT), PUSH(quick[1].observer, 11+XfOrM368_COUNT), PUSH(quick[2].value_name, 12+XfOrM368_COUNT), PUSH(quick[2].certs, 13+XfOrM368_COUNT), PUSH(quick[2].observer, 14+XfOrM368_COUNT), PUSH(quick[3].value_name, 15+XfOrM368_COUNT), PUSH(quick[3].certs, 16+XfOrM368_COUNT), PUSH(quick[3].observer, 17+XfOrM368_COUNT), PUSH(quick[4].value_name, 18+XfOrM368_COUNT), PUSH(quick[4].certs, 19+XfOrM368_COUNT), PUSH(quick[4].observer, 20+XfOrM368_COUNT), PUSH(p, 21+XfOrM368_COUNT), PUSH(rest, 22+XfOrM368_COUNT)));
#   define XfOrM370_COUNT (23+XfOrM368_COUNT)
#   define SETUP_XfOrM370(x) SETUP(XfOrM370_COUNT)
    recs = NULLED_OUT ; 
    quick[0].value_name = NULLED_OUT ; 
    quick[0].certs = NULLED_OUT ; 
    quick[0].observer = NULLED_OUT ; 
    quick[1].value_name = NULLED_OUT ; 
    quick[1].certs = NULLED_OUT ; 
    quick[1].observer = NULLED_OUT ; 
    quick[2].value_name = NULLED_OUT ; 
    quick[2].certs = NULLED_OUT ; 
    quick[2].observer = NULLED_OUT ; 
    quick[3].value_name = NULLED_OUT ; 
    quick[3].certs = NULLED_OUT ; 
    quick[3].observer = NULLED_OUT ; 
    quick[4].value_name = NULLED_OUT ; 
    quick[4].certs = NULLED_OUT ; 
    quick[4].observer = NULLED_OUT ; 
    c = NULLED_OUT ; 
    p = NULLED_OUT ; 
    comp_first = NULLED_OUT ; 
    comp_last = NULLED_OUT ; 
    name = NULLED_OUT ; 
    first = NULLED_OUT ; 
    rest = NULLED_OUT ; 
    name = rec [drec ] . value_name ; 
    FUNCCALL(SETUP_XfOrM370(_), scheme_compile_rec_done_local (rec , drec ) ); 
    if (len <= 5 )
      recs = quick ; 
    else recs = ((Scheme_Compile_Info * ) FUNCCALL(SETUP_XfOrM370(_), GC_malloc_array_tagged (sizeof (Scheme_Compile_Info ) * (len ) ) )) ; 
    FUNCCALL(SETUP_XfOrM370(_), scheme_init_compile_recs (rec , drec , recs , len ) ); 
    recs [len - 1 ] . value_name = name ; 
    comp_first = comp_last = ((void * ) 0 ) ; 
    for (i = 0 , rest = form ; i < len ; i ++ ) {
#     define XfOrM372_COUNT (0+XfOrM370_COUNT)
#     define SETUP_XfOrM372(x) SETUP_XfOrM370(x)
      first = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM372(_), scheme_stx_content (rest ) )) ) -> u . pair_val . car ) ) ; 
      rest = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM372(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ; 
      c = FUNCCALL(SETUP_XfOrM372(_), scheme_compile_expand_expr (first , env , recs , i , ! i && start_app_position ) ); 
      p = FUNCCALL_AGAIN(scheme_make_immutable_pair (c , scheme_null ) ); 
      if (comp_last )
        (((Scheme_Simple_Object * ) (comp_last ) ) -> u . pair_val . cdr ) = p ; 
      else comp_first = p ; 
      comp_last = p ; 
    }
    FUNCCALL(SETUP_XfOrM370(_), scheme_merge_compile_recs (rec , drec , recs , len ) ); 
    RET_VALUE_START (comp_first ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM369_COUNT (0+XfOrM368_COUNT)
#   define SETUP_XfOrM369(x) SETUP_XfOrM368(x)
    FUNCCALL_EMPTY(scheme_signal_error ("internal error: compile-list on non-list" ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * compile_application (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  Scheme_Object * result ; 
  int len ; 
  Scheme_Comp_Env * __funcarg34 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(result, 1), PUSH(form, 2), PUSH(rec, 3)));
# define XfOrM374_COUNT (4)
# define SETUP_XfOrM374(x) SETUP(XfOrM374_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  result = NULLED_OUT ; 
  len = FUNCCALL(SETUP_XfOrM374(_), scheme_stx_proper_list_length (form ) ); 
  if (len < 0 )
    FUNCCALL_EMPTY(scheme_wrong_syntax (scheme_application_stx_string , ((void * ) 0 ) , form , ((void * ) 0 ) ) ); 
  FUNCCALL(SETUP_XfOrM374(_), scheme_compile_rec_done_local (rec , drec ) ); 
  FUNCCALL_AGAIN(scheme_rec_add_certs (rec , drec , form ) ); 
  form = (__funcarg34 = FUNCCALL(SETUP_XfOrM374(_), scheme_no_defines (env ) ), FUNCCALL_AGAIN(scheme_inner_compile_list (form , __funcarg34 , rec , drec , 1 ) )) ; 
  result = FUNCCALL_AGAIN(make_application (form ) ); 
  RET_VALUE_START (result ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_compile_list (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  /* No conversion */
  return scheme_inner_compile_list (form , env , rec , drec , 0 ) ; 
}
static Scheme_Object * call_compile_handler (Scheme_Object * form , int immediate_eval ) {
  Scheme_Object * argv [2 ] , * o ; 
  Scheme_Config * __funcarg35 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSHARRAY(argv, 2, 0), PUSH(o, 3)));
# define XfOrM376_COUNT (4)
# define SETUP_XfOrM376(x) SETUP(XfOrM376_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  argv[0] = NULLED_OUT ; 
  argv[1] = NULLED_OUT ; 
  o = NULLED_OUT ; 
  argv [0 ] = form ; 
  argv [1 ] = (immediate_eval ? scheme_true : scheme_false ) ; 
  o = (__funcarg35 = FUNCCALL(SETUP_XfOrM376(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg35 , MZCONFIG_COMPILE_HANDLER ) )) ; 
  o = FUNCCALL_AGAIN(scheme_apply (o , 2 , argv ) ); 
  if (! ((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_compilation_top_type ) ) ) {
#   define XfOrM377_COUNT (0+XfOrM376_COUNT)
#   define SETUP_XfOrM377(x) SETUP_XfOrM376(x)
    argv [0 ] = o ; 
    FUNCCALL(SETUP_XfOrM377(_), scheme_wrong_type ("compile-handler" , "compiled code" , 0 , - 1 , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  RET_VALUE_START (o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * add_renames_unless_module (Scheme_Object * form , Scheme_Env * genv ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(genv, 0), PUSH(form, 1)));
# define XfOrM378_COUNT (2)
# define SETUP_XfOrM378(x) SETUP(XfOrM378_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (genv -> rename ) {
#   define XfOrM379_COUNT (0+XfOrM378_COUNT)
#   define SETUP_XfOrM379(x) SETUP_XfOrM378(x)
    if ((((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) form ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) form ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
      Scheme_Object * a , * d ; 
      BLOCK_SETUP((PUSH(a, 0+XfOrM379_COUNT), PUSH(d, 1+XfOrM379_COUNT)));
#     define XfOrM380_COUNT (2+XfOrM379_COUNT)
#     define SETUP_XfOrM380(x) SETUP(XfOrM380_COUNT)
      a = NULLED_OUT ; 
      d = NULLED_OUT ; 
      a = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM380(_), scheme_stx_content (form ) )) ) -> u . pair_val . car ) ) ; 
      if ((((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) a ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) a ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) ) {
#       define XfOrM381_COUNT (0+XfOrM380_COUNT)
#       define SETUP_XfOrM381(x) SETUP_XfOrM380(x)
        a = FUNCCALL(SETUP_XfOrM381(_), scheme_add_rename (a , genv -> rename ) ); 
        if (FUNCCALL(SETUP_XfOrM381(_), scheme_stx_module_eq (a , scheme_module_stx , 0 ) )) {
#         define XfOrM382_COUNT (0+XfOrM381_COUNT)
#         define SETUP_XfOrM382(x) SETUP_XfOrM381(x)
          d = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM382(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
          a = FUNCCALL(SETUP_XfOrM382(_), scheme_make_immutable_pair (a , d ) ); 
          form = FUNCCALL_AGAIN(scheme_datum_to_syntax (a , form , form , 1 , 0 ) ); 
          RET_VALUE_START (form ) RET_VALUE_END ; 
        }
      }
    }
  }
  if (genv -> rename )
    form = FUNCCALL(SETUP_XfOrM378(_), scheme_add_rename (form , genv -> rename ) ); 
  if (genv -> exp_env && genv -> exp_env -> rename )
    form = FUNCCALL(SETUP_XfOrM378(_), scheme_add_rename (form , genv -> exp_env -> rename ) ); 
  if (genv -> template_env && genv -> template_env -> rename )
    form = FUNCCALL(SETUP_XfOrM378(_), scheme_add_rename (form , genv -> template_env -> rename ) ); 
  if (genv -> dt_rename )
    form = FUNCCALL(SETUP_XfOrM378(_), scheme_add_rename (form , genv -> dt_rename ) ); 
  RET_VALUE_START (form ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_enable_expression_resolve_lifts (Resolve_Info * ri ) {
  Scheme_Object * lift_vec ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(lift_vec, 0), PUSH(ri, 1)));
# define XfOrM383_COUNT (2)
# define SETUP_XfOrM383(x) SETUP(XfOrM383_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  lift_vec = NULLED_OUT ; 
  lift_vec = FUNCCALL(SETUP_XfOrM383(_), scheme_make_vector (2 , ((void * ) 0 ) ) ); 
  (((Scheme_Vector * ) (lift_vec ) ) -> els ) [0 ] = scheme_null ; 
  (((Scheme_Vector * ) (lift_vec ) ) -> els ) [1 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
  ri -> lifts = lift_vec ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_merge_expression_resolve_lifts (Scheme_Object * expr , Resolve_Prefix * rp , Resolve_Info * ri ) {
  Scheme_Object * lift_vec , * lifts ; 
  Scheme_Sequence * s ; 
  int n , i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(lifts, 0), PUSH(expr, 1), PUSH(s, 2)));
# define XfOrM384_COUNT (3)
# define SETUP_XfOrM384(x) SETUP(XfOrM384_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  lift_vec = NULLED_OUT ; 
  lifts = NULLED_OUT ; 
  s = NULLED_OUT ; 
  lift_vec = ri -> lifts ; 
  n = (((long ) ((((Scheme_Vector * ) (lift_vec ) ) -> els ) [1 ] ) ) >> 1 ) ; 
  if (n ) {
#   define XfOrM385_COUNT (0+XfOrM384_COUNT)
#   define SETUP_XfOrM385(x) SETUP_XfOrM384(x)
    rp -> num_lifts = n ; 
    lifts = (((Scheme_Vector * ) (lift_vec ) ) -> els ) [0 ] ; 
    s = FUNCCALL(SETUP_XfOrM385(_), malloc_sequence (n + 1 ) ); 
    s -> so . type = scheme_sequence_type ; 
    s -> count = n + 1 ; 
    for (i = 0 ; i < n ; i ++ , lifts = (((Scheme_Simple_Object * ) (lifts ) ) -> u . pair_val . cdr ) ) {
      s -> array [i ] = (((Scheme_Simple_Object * ) (lifts ) ) -> u . pair_val . car ) ; 
    }
    s -> array [i ] = expr ; 
    RET_VALUE_START ((Scheme_Object * ) s ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (expr ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void * compile_k (void ) {
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * form ; 
  int writeable , for_eval , rename , enforce_consts ; 
  Scheme_Env * genv ; 
  Scheme_Compile_Info rec , rec2 ; 
  Scheme_Object * o , * tl_queue ; 
  Scheme_Compilation_Top * top ; 
  Resolve_Prefix * rp ; 
  Resolve_Info * ri ; 
  Optimize_Info * oi ; 
  Scheme_Object * gval , * insp ; 
  Scheme_Comp_Env * cenv ; 
  Scheme_Object * __funcarg61 = NULLED_OUT ; 
  Scheme_Object * __funcarg60 = NULLED_OUT ; 
  Scheme_Object * __funcarg59 = NULLED_OUT ; 
  Scheme_Object * __funcarg55 = NULLED_OUT ; 
  Scheme_Object * __funcarg54 = NULLED_OUT ; 
  Scheme_Object * __funcarg53 = NULLED_OUT ; 
  Scheme_Hash_Table * __funcarg49 = NULLED_OUT ; 
  DECL_RET_SAVE (void * ) PREPARE_VAR_STACK(20);
  BLOCK_SETUP_TOP((PUSH(genv, 0), PUSH(ri, 1), PUSH(top, 2), PUSH(rp, 3), PUSH(rec2.value_name, 4), PUSH(rec2.certs, 5), PUSH(rec2.observer, 6), PUSH(rec.value_name, 7), PUSH(rec.certs, 8), PUSH(rec.observer, 9), PUSH(tl_queue, 10), PUSH(oi, 11), PUSH(cenv, 12), PUSH(insp, 13), PUSH(o, 14), PUSH(gval, 15), PUSH(form, 16)));
# define XfOrM388_COUNT (17)
# define SETUP_XfOrM388(x) SETUP(XfOrM388_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  form = NULLED_OUT ; 
  genv = NULLED_OUT ; 
  rec.value_name = NULLED_OUT ; 
  rec.certs = NULLED_OUT ; 
  rec.observer = NULLED_OUT ; 
  rec2.value_name = NULLED_OUT ; 
  rec2.certs = NULLED_OUT ; 
  rec2.observer = NULLED_OUT ; 
  o = NULLED_OUT ; 
  tl_queue = NULLED_OUT ; 
  top = NULLED_OUT ; 
  rp = NULLED_OUT ; 
  ri = NULLED_OUT ; 
  oi = NULLED_OUT ; 
  gval = NULLED_OUT ; 
  insp = NULLED_OUT ; 
  cenv = NULLED_OUT ; 
  form = (Scheme_Object * ) p -> ku . k . p1 ; 
  genv = (Scheme_Env * ) p -> ku . k . p2 ; 
  writeable = p -> ku . k . i1 ; 
  for_eval = p -> ku . k . i2 ; 
  rename = p -> ku . k . i3 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  p -> ku . k . p2 = ((void * ) 0 ) ; 
  if (! ((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ) {
#   define XfOrM436_COUNT (0+XfOrM388_COUNT)
#   define SETUP_XfOrM436(x) SETUP_XfOrM388(x)
    form = FUNCCALL(SETUP_XfOrM436(_), scheme_datum_to_syntax (form , scheme_false , scheme_false , 1 , 0 ) ); 
    rename = 1 ; 
  }
  if (rename ) {
#   define XfOrM434_COUNT (0+XfOrM388_COUNT)
#   define SETUP_XfOrM434(x) SETUP_XfOrM388(x)
    form = FUNCCALL(SETUP_XfOrM434(_), add_renames_unless_module (form , genv ) ); 
    if (genv -> module ) {
#     define XfOrM435_COUNT (0+XfOrM434_COUNT)
#     define SETUP_XfOrM435(x) SETUP_XfOrM434(x)
      form = FUNCCALL(SETUP_XfOrM435(_), scheme_stx_phase_shift (form , 0 , genv -> module -> me -> src_modidx , genv -> module -> self_modidx , genv -> export_registry ) ); 
    }
  }
  tl_queue = scheme_null ; 
  {
    Scheme_Config * config ; 
    BLOCK_SETUP((PUSH(config, 0+XfOrM388_COUNT)));
#   define XfOrM433_COUNT (1+XfOrM388_COUNT)
#   define SETUP_XfOrM433(x) SETUP(XfOrM433_COUNT)
    config = NULLED_OUT ; 
    config = FUNCCALL(SETUP_XfOrM433(_), scheme_current_config () ); 
    insp = FUNCCALL_AGAIN(scheme_get_param (config , MZCONFIG_CODE_INSPECTOR ) ); 
    enforce_consts = (! (((FUNCCALL(SETUP_XfOrM433(_), scheme_get_param (config , MZCONFIG_COMPILE_MODULE_CONSTS ) )) ) == (scheme_false ) ) ) ; 
  }
  while (1 ) {
#   define XfOrM411_COUNT (0+XfOrM388_COUNT)
#   define SETUP_XfOrM411(x) SETUP_XfOrM388(x)
    rec . comp = 1 ; 
    rec . dont_mark_local_use = 0 ; 
    rec . resolve_module_ids = ! writeable && ! genv -> module ; 
    rec . value_name = scheme_false ; 
    rec . certs = ((void * ) 0 ) ; 
    rec . observer = ((void * ) 0 ) ; 
    cenv = FUNCCALL(SETUP_XfOrM411(_), scheme_new_comp_env (genv , insp , 1 ) ); 
    if (for_eval ) {
#     define XfOrM422_COUNT (0+XfOrM411_COUNT)
#     define SETUP_XfOrM422(x) SETUP_XfOrM411(x)
      while (1 ) {
#       define XfOrM428_COUNT (0+XfOrM422_COUNT)
#       define SETUP_XfOrM428(x) SETUP_XfOrM422(x)
        (__funcarg61 = FUNCCALL(SETUP_XfOrM428(_), scheme_sys_wraps (cenv ) ), FUNCCALL_AGAIN(scheme_frame_captures_lifts (cenv , scheme_make_lifted_defn , __funcarg61 , scheme_false , scheme_true ) )) ; 
        form = FUNCCALL(SETUP_XfOrM428(_), scheme_check_immediate_macro (form , cenv , & rec , 0 , 0 , & gval , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
        if (((gval ) == (scheme_begin_syntax ) ) ) {
#         define XfOrM431_COUNT (0+XfOrM428_COUNT)
#         define SETUP_XfOrM431(x) SETUP_XfOrM428(x)
          if (FUNCCALL(SETUP_XfOrM431(_), scheme_stx_proper_list_length (form ) )> 1 ) {
#           define XfOrM432_COUNT (0+XfOrM431_COUNT)
#           define SETUP_XfOrM432(x) SETUP_XfOrM431(x)
            form = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM432(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
            tl_queue = (__funcarg60 = FUNCCALL(SETUP_XfOrM432(_), scheme_flatten_syntax_list (form , ((void * ) 0 ) ) ), FUNCCALL_AGAIN(scheme_append (__funcarg60 , tl_queue ) )) ; 
            tl_queue = (__funcarg59 = FUNCCALL(SETUP_XfOrM432(_), scheme_frame_get_lifts (cenv ) ), FUNCCALL_AGAIN(scheme_append (__funcarg59 , tl_queue ) )) ; 
            form = (((Scheme_Simple_Object * ) (tl_queue ) ) -> u . pair_val . car ) ; 
            tl_queue = (((Scheme_Simple_Object * ) (tl_queue ) ) -> u . pair_val . cdr ) ; 
          }
          else break ; 
        }
        else {
#         define XfOrM429_COUNT (0+XfOrM428_COUNT)
#         define SETUP_XfOrM429(x) SETUP_XfOrM428(x)
          o = FUNCCALL(SETUP_XfOrM429(_), scheme_frame_get_lifts (cenv ) ); 
          if (! ((o ) == (scheme_null ) ) ) {
#           define XfOrM430_COUNT (0+XfOrM429_COUNT)
#           define SETUP_XfOrM430(x) SETUP_XfOrM429(x)
            tl_queue = FUNCCALL(SETUP_XfOrM430(_), scheme_make_pair (form , tl_queue ) ); 
            tl_queue = FUNCCALL(SETUP_XfOrM430(_), scheme_append (o , tl_queue ) ); 
            form = (((Scheme_Simple_Object * ) (tl_queue ) ) -> u . pair_val . car ) ; 
            tl_queue = (((Scheme_Simple_Object * ) (tl_queue ) ) -> u . pair_val . cdr ) ; 
          }
          break ; 
        }
      }
    }
    if (for_eval ) {
#     define XfOrM421_COUNT (0+XfOrM411_COUNT)
#     define SETUP_XfOrM421(x) SETUP_XfOrM411(x)
      o = FUNCCALL(SETUP_XfOrM421(_), call_compile_handler (form , 1 ) ); 
      top = (Scheme_Compilation_Top * ) o ; 
    }
    else {
      Scheme_Object * l , * prev_o = ((void * ) 0 ) ; 
      BLOCK_SETUP((PUSH(prev_o, 0+XfOrM411_COUNT), PUSH(l, 1+XfOrM411_COUNT)));
#     define XfOrM413_COUNT (2+XfOrM411_COUNT)
#     define SETUP_XfOrM413(x) SETUP(XfOrM413_COUNT)
      l = NULLED_OUT ; 
      while (1 ) {
#       define XfOrM418_COUNT (0+XfOrM413_COUNT)
#       define SETUP_XfOrM418(x) SETUP_XfOrM413(x)
        (__funcarg55 = FUNCCALL(SETUP_XfOrM418(_), scheme_sys_wraps (cenv ) ), FUNCCALL_AGAIN(scheme_frame_captures_lifts (cenv , scheme_make_lifted_defn , __funcarg55 , scheme_false , scheme_true ) )) ; 
        FUNCCALL(SETUP_XfOrM418(_), scheme_init_compile_recs (& rec , 0 , & rec2 , 1 ) ); 
        o = FUNCCALL_AGAIN(scheme_compile_expr (form , cenv , & rec2 , 0 ) ); 
        if (prev_o ) {
          Scheme_Sequence * seq ; 
          BLOCK_SETUP((PUSH(seq, 0+XfOrM418_COUNT)));
#         define XfOrM420_COUNT (1+XfOrM418_COUNT)
#         define SETUP_XfOrM420(x) SETUP(XfOrM420_COUNT)
          seq = NULLED_OUT ; 
          seq = FUNCCALL(SETUP_XfOrM420(_), malloc_sequence (2 ) ); 
          seq -> so . type = scheme_sequence_type ; 
          seq -> count = 2 ; 
          seq -> array [0 ] = o ; 
          seq -> array [1 ] = prev_o ; 
          o = (Scheme_Object * ) seq ; 
        }
        l = FUNCCALL(SETUP_XfOrM418(_), scheme_frame_get_lifts (cenv ) ); 
        if (! ((l ) == (scheme_null ) ) ) {
#         define XfOrM419_COUNT (0+XfOrM418_COUNT)
#         define SETUP_XfOrM419(x) SETUP_XfOrM418(x)
          l = (__funcarg53 = (__funcarg54 = FUNCCALL(SETUP_XfOrM419(_), scheme_sys_wraps (cenv ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (begin_symbol , scheme_false , __funcarg54 , 0 , 0 ) )) , FUNCCALL_AGAIN(scheme_make_immutable_pair (__funcarg53 , l ) )) ; 
          form = FUNCCALL(SETUP_XfOrM419(_), scheme_datum_to_syntax (l , scheme_false , scheme_false , 0 , 0 ) ); 
          prev_o = o ; 
        }
        else break ; 
      }
      oi = FUNCCALL(SETUP_XfOrM413(_), scheme_optimize_info_create () ); 
      oi -> enforce_const = enforce_consts ; 
      o = FUNCCALL(SETUP_XfOrM413(_), scheme_optimize_expr (o , oi ) ); 
      rp = FUNCCALL_AGAIN(scheme_resolve_prefix (0 , cenv -> prefix , 1 ) ); 
      ri = FUNCCALL_AGAIN(scheme_resolve_info_create (rp ) ); 
      ri -> enforce_const = enforce_consts ; 
      FUNCCALL(SETUP_XfOrM413(_), scheme_enable_expression_resolve_lifts (ri ) ); 
      o = FUNCCALL_AGAIN(scheme_resolve_expr (o , ri ) ); 
      o = FUNCCALL_AGAIN(scheme_merge_expression_resolve_lifts (o , rp , ri ) ); 
      rp = FUNCCALL_AGAIN(scheme_remap_prefix (rp , ri ) ); 
      top = ((Scheme_Compilation_Top * ) FUNCCALL(SETUP_XfOrM413(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Compilation_Top ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
      top -> so . type = scheme_compilation_top_type ; 
      top -> max_let_depth = ri -> max_let_depth ; 
      top -> code = o ; 
      top -> prefix = rp ; 
      if (0 ) {
#       define XfOrM414_COUNT (0+XfOrM413_COUNT)
#       define SETUP_XfOrM414(x) SETUP_XfOrM413(x)
        (__funcarg49 = FUNCCALL(SETUP_XfOrM414(_), scheme_make_hash_table (SCHEME_hash_ptr ) ), FUNCCALL_AGAIN(scheme_validate_code (((void * ) 0 ) , top -> code , __funcarg49 , top -> max_let_depth , top -> prefix -> num_toplevels , top -> prefix -> num_stxes , top -> prefix -> num_lifts ) )) ; 
      }
    }
    if (((Scheme_Type ) (((((long ) (tl_queue ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (tl_queue ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#     define XfOrM412_COUNT (0+XfOrM411_COUNT)
#     define SETUP_XfOrM412(x) SETUP_XfOrM411(x)
      FUNCCALL(SETUP_XfOrM412(_), _eval_compiled_multi_with_prompt ((Scheme_Object * ) top , genv ) ); 
      form = (((Scheme_Simple_Object * ) (tl_queue ) ) -> u . pair_val . car ) ; 
      tl_queue = (((Scheme_Simple_Object * ) (tl_queue ) ) -> u . pair_val . cdr ) ; 
    }
    else break ; 
  }
  RET_VALUE_START ((void * ) top ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * _compile (Scheme_Object * form , Scheme_Env * env , int writeable , int for_eval , int eb , int rename ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  if (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_compilation_top_type ) ) )
    return form ; 
  if (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ) {
    if (((Scheme_Type ) (((((long ) (((Scheme_Stx * ) form ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) form ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_compilation_top_type ) ) )
      return ((Scheme_Stx * ) form ) -> val ; 
  }
  p -> ku . k . p1 = form ; 
  p -> ku . k . p2 = env ; 
  p -> ku . k . i1 = writeable ; 
  p -> ku . k . i2 = for_eval ; 
  p -> ku . k . i3 = rename ; 
  return (Scheme_Object * ) scheme_top_level_do (compile_k , eb ) ; 
}
Scheme_Object * scheme_compile (Scheme_Object * form , Scheme_Env * env , int writeable ) {
  /* No conversion */
  return _compile (form , env , writeable , 0 , 1 , 1 ) ; 
}
Scheme_Object * scheme_compile_for_eval (Scheme_Object * form , Scheme_Env * env ) {
  /* No conversion */
  return _compile (form , env , 0 , 1 , 1 , 1 ) ; 
}
Scheme_Object * scheme_check_immediate_macro (Scheme_Object * first , Scheme_Comp_Env * env , Scheme_Compile_Expand_Info * rec , int drec , int internel_def_pos , Scheme_Object * * current_val , Scheme_Comp_Env * * _xenv , Scheme_Object * ctx ) {
  Scheme_Object * name , * val , * certs ; 
  Scheme_Comp_Env * xenv = (_xenv ? * _xenv : ((void * ) 0 ) ) ; 
  Scheme_Expand_Info erec1 ; 
  Scheme_Env * menv = ((void * ) 0 ) ; 
  int need_cert ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(14);
  BLOCK_SETUP_TOP((PUSH(_xenv, 0), PUSH(ctx, 1), PUSH(current_val, 2), PUSH(xenv, 3), PUSH(erec1.value_name, 4), PUSH(erec1.certs, 5), PUSH(erec1.observer, 6), PUSH(rec, 7), PUSH(name, 8), PUSH(menv, 9), PUSH(first, 10), PUSH(val, 11), PUSH(certs, 12), PUSH(env, 13)));
# define XfOrM441_COUNT (14)
# define SETUP_XfOrM441(x) SETUP(XfOrM441_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  name = NULLED_OUT ; 
  val = NULLED_OUT ; 
  certs = NULLED_OUT ; 
  erec1.value_name = NULLED_OUT ; 
  erec1.certs = NULLED_OUT ; 
  erec1.observer = NULLED_OUT ; 
  if (rec [drec ] . observer ) {
#   define XfOrM519_COUNT (0+XfOrM441_COUNT)
#   define SETUP_XfOrM519(x) SETUP_XfOrM441(x)
    FUNCCALL(SETUP_XfOrM519(_), scheme_call_expand_observe (rec [drec ] . observer , 126 , first ) ); 
  }
  else {
  }
  ; 
  while (1 ) {
#   define XfOrM480_COUNT (0+XfOrM441_COUNT)
#   define SETUP_XfOrM480(x) SETUP_XfOrM441(x)
    * current_val = ((void * ) 0 ) ; 
    if ((((Scheme_Type ) (((((long ) (first ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (first ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (first ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (first ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) first ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) first ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
#     define XfOrM517_COUNT (0+XfOrM480_COUNT)
#     define SETUP_XfOrM517(x) SETUP_XfOrM480(x)
      name = (((Scheme_Type ) (((((long ) (first ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (first ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (first ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM517(_), scheme_stx_content (first ) )) ) -> u . pair_val . car ) ) ; 
      need_cert = 1 ; 
    }
    else {
      name = first ; 
      need_cert = 0 ; 
    }
    if (! (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) name ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) name ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) ) {
#     define XfOrM513_COUNT (0+XfOrM480_COUNT)
#     define SETUP_XfOrM513(x) SETUP_XfOrM480(x)
      if (rec [drec ] . observer ) {
#       define XfOrM515_COUNT (0+XfOrM513_COUNT)
#       define SETUP_XfOrM515(x) SETUP_XfOrM513(x)
        FUNCCALL(SETUP_XfOrM515(_), scheme_call_expand_observe (rec [drec ] . observer , 127 , first ) ); 
      }
      else {
      }
      ; 
      RET_VALUE_START (first ) RET_VALUE_END ; 
    }
    while (1 ) {
#     define XfOrM497_COUNT (0+XfOrM480_COUNT)
#     define SETUP_XfOrM497(x) SETUP_XfOrM480(x)
      if (need_cert ) {
#       define XfOrM512_COUNT (0+XfOrM497_COUNT)
#       define SETUP_XfOrM512(x) SETUP_XfOrM497(x)
        FUNCCALL(SETUP_XfOrM512(_), scheme_init_expand_recs (rec , drec , & erec1 , 1 ) ); 
        FUNCCALL(SETUP_XfOrM512(_), scheme_rec_add_certs (& erec1 , 0 , first ) ); 
        certs = erec1 . certs ; 
      }
      else certs = rec [drec ] . certs ; 
      val = FUNCCALL(SETUP_XfOrM497(_), scheme_lookup_binding (name , env , 512 + 2 + 8 + ((rec [drec ] . comp && rec [drec ] . dont_mark_local_use ) ? 128 : 0 ) + ((rec [drec ] . comp && rec [drec ] . resolve_module_ids ) ? 1024 : 0 ) , certs , env -> in_modidx , & menv , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
      if ((((Scheme_Type ) (((((long ) (first ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (first ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (first ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (first ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) first ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) first ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
        * current_val = val ; 
      if (! val ) {
#       define XfOrM509_COUNT (0+XfOrM497_COUNT)
#       define SETUP_XfOrM509(x) SETUP_XfOrM497(x)
        if (rec [drec ] . observer ) {
#         define XfOrM511_COUNT (0+XfOrM509_COUNT)
#         define SETUP_XfOrM511(x) SETUP_XfOrM509(x)
          FUNCCALL(SETUP_XfOrM511(_), scheme_call_expand_observe (rec [drec ] . observer , 127 , first ) ); 
        }
        else {
        }
        ; 
        RET_VALUE_START (first ) RET_VALUE_END ; 
      }
      else if (((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_macro_type ) ) ) {
#       define XfOrM501_COUNT (0+XfOrM497_COUNT)
#       define SETUP_XfOrM501(x) SETUP_XfOrM497(x)
        if (((Scheme_Type ) (((((long ) ((((Scheme_Small_Object * ) (val ) ) -> u . ptr_val ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Small_Object * ) (val ) ) -> u . ptr_val ) ) ) -> type ) ) == (Scheme_Type ) (scheme_id_macro_type ) ) ) {
#         define XfOrM506_COUNT (0+XfOrM501_COUNT)
#         define SETUP_XfOrM506(x) SETUP_XfOrM501(x)
          name = FUNCCALL(SETUP_XfOrM506(_), scheme_stx_cert ((((Scheme_Small_Object * ) ((((Scheme_Small_Object * ) (val ) ) -> u . ptr_val ) ) ) -> u . ptr_val ) , scheme_false , menv , name , ((void * ) 0 ) , 1 ) ); 
          menv = ((void * ) 0 ) ; 
          {
#           define XfOrM507_COUNT (0+XfOrM506_COUNT)
#           define SETUP_XfOrM507(x) SETUP_XfOrM506(x)
            if ((scheme_fuel_counter ) <= 0 ) {
#             define XfOrM508_COUNT (0+XfOrM507_COUNT)
#             define SETUP_XfOrM508(x) SETUP_XfOrM507(x)
              FUNCCALL(SETUP_XfOrM508(_), scheme_out_of_fuel () ); 
            }
          }
          ; 
        }
        else {
#         define XfOrM502_COUNT (0+XfOrM501_COUNT)
#         define SETUP_XfOrM502(x) SETUP_XfOrM501(x)
          if (! xenv ) {
#           define XfOrM504_COUNT (0+XfOrM502_COUNT)
#           define SETUP_XfOrM504(x) SETUP_XfOrM502(x)
            if (internel_def_pos ) {
#             define XfOrM505_COUNT (0+XfOrM504_COUNT)
#             define SETUP_XfOrM505(x) SETUP_XfOrM504(x)
              xenv = FUNCCALL(SETUP_XfOrM505(_), scheme_new_compilation_frame (0 , 16 , env , ((void * ) 0 ) ) ); 
              if (ctx )
                xenv -> intdef_name = ctx ; 
              if (_xenv )
                * _xenv = xenv ; 
            }
            else xenv = env ; 
          }
          {
#           define XfOrM503_COUNT (0+XfOrM502_COUNT)
#           define SETUP_XfOrM503(x) SETUP_XfOrM502(x)
            FUNCCALL(SETUP_XfOrM503(_), scheme_init_expand_recs (rec , drec , & erec1 , 1 ) ); 
            erec1 . depth = 1 ; 
            erec1 . value_name = rec [drec ] . value_name ; 
            first = FUNCCALL(SETUP_XfOrM503(_), scheme_expand_expr (first , xenv , & erec1 , 0 ) ); 
          }
          break ; 
        }
      }
      else {
#       define XfOrM498_COUNT (0+XfOrM497_COUNT)
#       define SETUP_XfOrM498(x) SETUP_XfOrM497(x)
        if (rec [drec ] . observer ) {
#         define XfOrM500_COUNT (0+XfOrM498_COUNT)
#         define SETUP_XfOrM500(x) SETUP_XfOrM498(x)
          FUNCCALL(SETUP_XfOrM500(_), scheme_call_expand_observe (rec [drec ] . observer , 127 , first ) ); 
        }
        else {
        }
        ; 
        RET_VALUE_START (first ) RET_VALUE_END ; 
      }
    }
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * compile_expand_macro_app (Scheme_Object * name , Scheme_Env * menv , Scheme_Object * macro , Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Expand_Info * rec , int drec ) {
  Scheme_Object * xformer , * boundname ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSH(xformer, 0), PUSH(boundname, 1), PUSH(rec, 2), PUSH(name, 3), PUSH(env, 4), PUSH(menv, 5), PUSH(form, 6)));
# define XfOrM520_COUNT (7)
# define SETUP_XfOrM520(x) SETUP(XfOrM520_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  xformer = NULLED_OUT ; 
  boundname = NULLED_OUT ; 
  xformer = (Scheme_Object * ) (((Scheme_Small_Object * ) (macro ) ) -> u . ptr_val ) ; 
  if (((Scheme_Type ) (((((long ) (xformer ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (xformer ) ) -> type ) ) == (Scheme_Type ) (scheme_set_macro_type ) ) ) {
  }
  else {
#   define XfOrM521_COUNT (0+XfOrM520_COUNT)
#   define SETUP_XfOrM521(x) SETUP_XfOrM520(x)
    if (! FUNCCALL(SETUP_XfOrM521(_), scheme_check_proc_arity (((void * ) 0 ) , 1 , 0 , - 1 , & xformer ) )) {
#     define XfOrM522_COUNT (0+XfOrM521_COUNT)
#     define SETUP_XfOrM522(x) SETUP_XfOrM521(x)
      FUNCCALL(SETUP_XfOrM522(_), scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , form , "illegal use of syntax" ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  boundname = rec [drec ] . value_name ; 
  if (! boundname )
    boundname = scheme_false ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM520(_), scheme_apply_macro (name , menv , xformer , form , env , boundname , rec , drec , 0 ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int same_effective_env (Scheme_Comp_Env * orig , Scheme_Comp_Env * e ) {
  /* No conversion */
  while (1 ) {
    if (orig == e )
      return 1 ; 
    if (e && e -> flags & 128 )
      e = e -> next ; 
    else return 0 ; 
  }
}
static Scheme_Object * compile_expand_expr_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * form = (Scheme_Object * ) p -> ku . k . p1 ; 
  Scheme_Comp_Env * env = (Scheme_Comp_Env * ) p -> ku . k . p2 ; 
  Scheme_Compile_Info * rec = (Scheme_Compile_Info * ) p -> ku . k . p3 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  p -> ku . k . p2 = ((void * ) 0 ) ; 
  p -> ku . k . p3 = ((void * ) 0 ) ; 
  return scheme_compile_expand_expr (form , env , rec , p -> ku . k . i3 , p -> ku . k . i2 ) ; 
}
static Scheme_Object * scheme_compile_expand_expr (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Expand_Info * rec , int drec , int app_position ) {
  Scheme_Object * name , * var , * stx , * normal , * can_recycle_stx = ((void * ) 0 ) ; 
  Scheme_Env * menv = ((void * ) 0 ) ; 
  GC_CAN_IGNORE char * not_allowed ; 
  int looking_for_top ; 
  Scheme_Object * __funcarg64 = NULLED_OUT ; 
  Scheme_Object * __funcarg63 = NULLED_OUT ; 
  Scheme_Object * __funcarg62 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(14);
  BLOCK_SETUP_TOP((PUSH(normal, 0), PUSH(menv, 1), PUSH(var, 2), PUSH(name, 3), PUSH(stx, 4), PUSH(can_recycle_stx, 5), PUSH(env, 6), PUSH(form, 7), PUSH(rec, 8)));
# define XfOrM528_COUNT (9)
# define SETUP_XfOrM528(x) SETUP(XfOrM528_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  name = NULLED_OUT ; 
  var = NULLED_OUT ; 
  stx = NULLED_OUT ; 
  normal = NULLED_OUT ; 
  top : {
    unsigned long _stk_pos ; 
#   define XfOrM662_COUNT (0+XfOrM528_COUNT)
#   define SETUP_XfOrM662(x) SETUP_XfOrM528(x)
    _stk_pos = (unsigned long ) & _stk_pos ; 
    if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
      Scheme_Thread * p = scheme_current_thread ; 
      Scheme_Compile_Expand_Info * recx ; 
      BLOCK_SETUP((PUSH(recx, 0+XfOrM662_COUNT), PUSH(p, 1+XfOrM662_COUNT)));
#     define XfOrM663_COUNT (2+XfOrM662_COUNT)
#     define SETUP_XfOrM663(x) SETUP(XfOrM663_COUNT)
      recx = NULLED_OUT ; 
      recx = ((Scheme_Compile_Expand_Info * ) FUNCCALL(SETUP_XfOrM663(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Compile_Expand_Info ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
      (memcpy (recx , rec + drec , sizeof (Scheme_Compile_Expand_Info ) ) ) ; 
      recx -> type = scheme_rt_compile_info ; 
      p -> ku . k . p1 = (void * ) form ; 
      p -> ku . k . p2 = (void * ) env ; 
      p -> ku . k . p3 = (void * ) recx ; 
      p -> ku . k . i3 = 0 ; 
      p -> ku . k . i2 = app_position ; 
      var = FUNCCALL(SETUP_XfOrM663(_), scheme_handle_stack_overflow (compile_expand_expr_k ) ); 
      (memcpy (rec + drec , recx , sizeof (Scheme_Compile_Expand_Info ) ) ) ; 
      RET_VALUE_START (var ) RET_VALUE_END ; 
    }
  }
  if ((scheme_fuel_counter ) <= 0 ) {
#   define XfOrM661_COUNT (0+XfOrM528_COUNT)
#   define SETUP_XfOrM661(x) SETUP_XfOrM528(x)
    ; 
    FUNCCALL(SETUP_XfOrM661(_), scheme_thread_block (0 ) ); 
    (scheme_current_thread ) -> ran_some = 1 ; 
  }
  ; 
  if (! ((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    FUNCCALL(SETUP_XfOrM528(_), scheme_signal_error ("not syntax" ) ); 
  if (rec [drec ] . comp ) {
#   define XfOrM660_COUNT (0+XfOrM528_COUNT)
#   define SETUP_XfOrM660(x) SETUP_XfOrM528(x)
    FUNCCALL(SETUP_XfOrM660(_), scheme_default_compile_rec (rec , drec ) ); 
  }
  else {
#   define XfOrM657_COUNT (0+XfOrM528_COUNT)
#   define SETUP_XfOrM657(x) SETUP_XfOrM528(x)
    if (rec [drec ] . observer ) {
#     define XfOrM659_COUNT (0+XfOrM657_COUNT)
#     define SETUP_XfOrM659(x) SETUP_XfOrM657(x)
      FUNCCALL(SETUP_XfOrM659(_), scheme_call_expand_observe (rec [drec ] . observer , 0 , form ) ); 
    }
    else {
    }
    ; 
  }
  if (((Scheme_Type ) (((((long ) (((Scheme_Stx * ) form ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) form ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_expanded_syntax_type ) ) ) {
#   define XfOrM653_COUNT (0+XfOrM528_COUNT)
#   define SETUP_XfOrM653(x) SETUP_XfOrM528(x)
    var = ((Scheme_Stx * ) form ) -> val ; 
    if (FUNCCALL(SETUP_XfOrM653(_), scheme_stx_has_empty_wraps (form ) )&& FUNCCALL(SETUP_XfOrM653(_), same_effective_env ((((Scheme_Simple_Object * ) (var ) ) -> u . two_ptr_val . ptr2 ) , env ) )) {
#     define XfOrM655_COUNT (0+XfOrM653_COUNT)
#     define SETUP_XfOrM655(x) SETUP_XfOrM653(x)
      var = FUNCCALL(SETUP_XfOrM655(_), scheme_stx_track ((((Scheme_Simple_Object * ) (var ) ) -> u . two_ptr_val . ptr1 ) , form , form ) ); 
      form = FUNCCALL(SETUP_XfOrM655(_), scheme_stx_cert (var , scheme_false , ((void * ) 0 ) , form , ((void * ) 0 ) , 1 ) ); 
      if (! rec [drec ] . comp && (rec [drec ] . depth != - 1 ) ) {
        RET_VALUE_START (form ) RET_VALUE_END ; 
      }
    }
    else {
#     define XfOrM654_COUNT (0+XfOrM653_COUNT)
#     define SETUP_XfOrM654(x) SETUP_XfOrM653(x)
      FUNCCALL(SETUP_XfOrM654(_), scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , (((Scheme_Simple_Object * ) (var ) ) -> u . two_ptr_val . ptr1 ) , "expanded syntax not in its original context" ) ); 
    }
  }
  looking_for_top = 0 ; 
  if ((((form ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) form ) -> val ) == (scheme_null ) ) ) ) ) {
    stx = app_symbol ; 
    not_allowed = "function application" ; 
    normal = app_expander ; 
  }
  else if (! (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) form ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) form ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
#   define XfOrM612_COUNT (0+XfOrM528_COUNT)
#   define SETUP_XfOrM612(x) SETUP_XfOrM528(x)
    if ((((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) form ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) form ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) ) {
      Scheme_Object * find_name = form , * lexical_binding_id ; 
      int protected = 0 ; 
      BLOCK_SETUP((PUSH(find_name, 0+XfOrM612_COUNT), PUSH(lexical_binding_id, 1+XfOrM612_COUNT)));
#     define XfOrM615_COUNT (2+XfOrM612_COUNT)
#     define SETUP_XfOrM615(x) SETUP(XfOrM615_COUNT)
      lexical_binding_id = NULLED_OUT ; 
      while (1 ) {
#       define XfOrM645_COUNT (0+XfOrM615_COUNT)
#       define SETUP_XfOrM645(x) SETUP_XfOrM615(x)
        lexical_binding_id = ((void * ) 0 ) ; 
        var = FUNCCALL(SETUP_XfOrM645(_), scheme_lookup_binding (find_name , env , 512 + 8 + (rec [drec ] . comp ? 1 : 0 ) + (app_position ? 2 : 0 ) + ((rec [drec ] . comp && rec [drec ] . dont_mark_local_use ) ? 128 : 0 ) + ((rec [drec ] . comp && rec [drec ] . resolve_module_ids ) ? 1024 : 0 ) , rec [drec ] . certs , env -> in_modidx , & menv , & protected , & lexical_binding_id ) ); 
        if (rec [drec ] . observer ) {
#         define XfOrM651_COUNT (0+XfOrM645_COUNT)
#         define SETUP_XfOrM651(x) SETUP_XfOrM645(x)
          FUNCCALL(SETUP_XfOrM651(_), scheme_call_expand_observe (rec [drec ] . observer , 1 , find_name ) ); 
        }
        else {
        }
        ; 
        if (var && ((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_macro_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Small_Object * ) (var ) ) -> u . ptr_val ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Small_Object * ) (var ) ) -> u . ptr_val ) ) ) -> type ) ) == (Scheme_Type ) (scheme_id_macro_type ) ) ) {
          Scheme_Object * new_name ; 
          BLOCK_SETUP((PUSH(new_name, 0+XfOrM645_COUNT)));
#         define XfOrM646_COUNT (1+XfOrM645_COUNT)
#         define SETUP_XfOrM646(x) SETUP(XfOrM646_COUNT)
          new_name = NULLED_OUT ; 
          new_name = (((Scheme_Small_Object * ) ((((Scheme_Small_Object * ) (var ) ) -> u . ptr_val ) ) ) -> u . ptr_val ) ; 
          if (! rec [drec ] . comp ) {
#           define XfOrM649_COUNT (0+XfOrM646_COUNT)
#           define SETUP_XfOrM649(x) SETUP_XfOrM646(x)
            new_name = FUNCCALL(SETUP_XfOrM649(_), scheme_stx_track (new_name , find_name , find_name ) ); 
          }
          new_name = FUNCCALL(SETUP_XfOrM646(_), scheme_stx_cert (new_name , scheme_false , menv , find_name , ((void * ) 0 ) , 1 ) ); 
          find_name = new_name ; 
          {
#           define XfOrM647_COUNT (0+XfOrM646_COUNT)
#           define SETUP_XfOrM647(x) SETUP_XfOrM646(x)
            if ((scheme_fuel_counter ) <= 0 ) {
#             define XfOrM648_COUNT (0+XfOrM647_COUNT)
#             define SETUP_XfOrM648(x) SETUP_XfOrM647(x)
              FUNCCALL(SETUP_XfOrM648(_), scheme_out_of_fuel () ); 
            }
          }
          ; 
          menv = ((void * ) 0 ) ; 
          protected = 0 ; 
        }
        else break ; 
      }
      if (! var ) {
        stx = top_symbol ; 
        not_allowed = "reference to top-level identifier" ; 
        normal = top_expander ; 
        form = find_name ; 
        looking_for_top = 1 ; 
      }
      else {
#       define XfOrM616_COUNT (0+XfOrM615_COUNT)
#       define SETUP_XfOrM616(x) SETUP_XfOrM615(x)
        if (((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_syntax_compiler_type ) ) ) {
#         define XfOrM626_COUNT (0+XfOrM616_COUNT)
#         define SETUP_XfOrM626(x) SETUP_XfOrM616(x)
          if (var == stop_expander ) {
#           define XfOrM628_COUNT (0+XfOrM626_COUNT)
#           define SETUP_XfOrM628(x) SETUP_XfOrM626(x)
            if (rec [drec ] . observer ) {
#             define XfOrM636_COUNT (0+XfOrM628_COUNT)
#             define SETUP_XfOrM636(x) SETUP_XfOrM628(x)
              FUNCCALL(SETUP_XfOrM636(_), scheme_call_expand_observe (rec [drec ] . observer , 6 , form ) ); 
            }
            else {
            }
            ; 
            if (rec [drec ] . observer ) {
#             define XfOrM634_COUNT (0+XfOrM628_COUNT)
#             define SETUP_XfOrM634(x) SETUP_XfOrM628(x)
              FUNCCALL(SETUP_XfOrM634(_), scheme_call_expand_observe (rec [drec ] . observer , 100 , ((void * ) 0 ) ) ); 
            }
            else {
            }
            ; 
            if (rec [drec ] . observer ) {
#             define XfOrM632_COUNT (0+XfOrM628_COUNT)
#             define SETUP_XfOrM632(x) SETUP_XfOrM628(x)
              FUNCCALL(SETUP_XfOrM632(_), scheme_call_expand_observe (rec [drec ] . observer , 7 , form ) ); 
            }
            else {
            }
            ; 
            if (rec [drec ] . observer ) {
#             define XfOrM630_COUNT (0+XfOrM628_COUNT)
#             define SETUP_XfOrM630(x) SETUP_XfOrM628(x)
              FUNCCALL(SETUP_XfOrM630(_), scheme_call_expand_observe (rec [drec ] . observer , 2 , form ) ); 
            }
            else {
            }
            ; 
            RET_VALUE_START (form ) RET_VALUE_END ; 
          }
          else {
#           define XfOrM627_COUNT (0+XfOrM626_COUNT)
#           define SETUP_XfOrM627(x) SETUP_XfOrM626(x)
            FUNCCALL(SETUP_XfOrM627(_), scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , form , "bad syntax" ) ); 
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          }
        }
        else if (((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_macro_type ) ) ) {
          name = form ; 
          goto macro ; 
        }
        if (rec [drec ] . comp ) {
#         define XfOrM624_COUNT (0+XfOrM616_COUNT)
#         define SETUP_XfOrM624(x) SETUP_XfOrM616(x)
          FUNCCALL(SETUP_XfOrM624(_), scheme_compile_rec_done_local (rec , drec ) ); 
          if (((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_variable_type ) ) || ((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_module_variable_type ) ) )
            RET_VALUE_START (FUNCCALL(SETUP_XfOrM624(_), scheme_register_toplevel_in_prefix (var , env , rec , drec ) )) RET_VALUE_END ; 
          else RET_VALUE_START (var ) RET_VALUE_END ; 
        }
        else {
#         define XfOrM617_COUNT (0+XfOrM616_COUNT)
#         define SETUP_XfOrM617(x) SETUP_XfOrM616(x)
          if (rec [drec ] . observer ) {
#           define XfOrM623_COUNT (0+XfOrM617_COUNT)
#           define SETUP_XfOrM623(x) SETUP_XfOrM617(x)
            (__funcarg64 = FUNCCALL(SETUP_XfOrM623(_), scheme_make_pair (form , find_name ) ), FUNCCALL_AGAIN(scheme_call_expand_observe (rec [drec ] . observer , 125 , __funcarg64 ) )) ; 
          }
          else {
          }
          ; 
          if (lexical_binding_id ) {
            find_name = lexical_binding_id ; 
          }
          if (protected ) {
#           define XfOrM620_COUNT (0+XfOrM617_COUNT)
#           define SETUP_XfOrM620(x) SETUP_XfOrM617(x)
            find_name = FUNCCALL(SETUP_XfOrM620(_), scheme_stx_property (find_name , protected_symbol , scheme_true ) ); 
          }
          if (rec [drec ] . observer ) {
#           define XfOrM619_COUNT (0+XfOrM617_COUNT)
#           define SETUP_XfOrM619(x) SETUP_XfOrM617(x)
            FUNCCALL(SETUP_XfOrM619(_), scheme_call_expand_observe (rec [drec ] . observer , 2 , find_name ) ); 
          }
          else {
          }
          ; 
          RET_VALUE_START (find_name ) RET_VALUE_END ; 
        }
      }
    }
    else {
      if (((Scheme_Type ) (((((long ) (((Scheme_Stx * ) form ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) form ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_already_comp_type ) ) ) {
        form = ((Scheme_Stx * ) form ) -> val ; 
        RET_VALUE_START ((((Scheme_Simple_Object * ) (form ) ) -> u . ptr_int_val . ptr ) ) RET_VALUE_END ; 
      }
      stx = datum_symbol ; 
      not_allowed = "literal data" ; 
      normal = datum_expander ; 
    }
  }
  else {
#   define XfOrM582_COUNT (0+XfOrM528_COUNT)
#   define SETUP_XfOrM582(x) SETUP_XfOrM528(x)
    name = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM582(_), scheme_stx_content (form ) )) ) -> u . pair_val . car ) ) ; 
    if ((((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) name ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) name ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) ) {
      Scheme_Object * find_name = name ; 
      Scheme_Expand_Info erec1 ; 
      BLOCK_SETUP((PUSH(erec1.value_name, 0+XfOrM582_COUNT), PUSH(erec1.certs, 1+XfOrM582_COUNT), PUSH(erec1.observer, 2+XfOrM582_COUNT), PUSH(find_name, 3+XfOrM582_COUNT)));
#     define XfOrM583_COUNT (4+XfOrM582_COUNT)
#     define SETUP_XfOrM583(x) SETUP(XfOrM583_COUNT)
      erec1.value_name = NULLED_OUT ; 
      erec1.certs = NULLED_OUT ; 
      erec1.observer = NULLED_OUT ; 
      FUNCCALL(SETUP_XfOrM583(_), scheme_init_expand_recs (rec , drec , & erec1 , 1 ) ); 
      FUNCCALL_AGAIN(scheme_rec_add_certs (& erec1 , 0 , form ) ); 
      while (1 ) {
#       define XfOrM605_COUNT (0+XfOrM583_COUNT)
#       define SETUP_XfOrM605(x) SETUP_XfOrM583(x)
        var = FUNCCALL(SETUP_XfOrM605(_), scheme_lookup_binding (find_name , env , 2 + 512 + 8 + (rec [drec ] . comp ? 1 : 0 ) + ((rec [drec ] . comp && rec [drec ] . dont_mark_local_use ) ? 128 : 0 ) + ((rec [drec ] . comp && rec [drec ] . resolve_module_ids ) ? 1024 : 0 ) , erec1 . certs , env -> in_modidx , & menv , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
        if (rec [drec ] . observer ) {
#         define XfOrM611_COUNT (0+XfOrM605_COUNT)
#         define SETUP_XfOrM611(x) SETUP_XfOrM605(x)
          FUNCCALL(SETUP_XfOrM611(_), scheme_call_expand_observe (rec [drec ] . observer , 1 , find_name ) ); 
        }
        else {
        }
        ; 
        if (var && ((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_macro_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Small_Object * ) (var ) ) -> u . ptr_val ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Small_Object * ) (var ) ) -> u . ptr_val ) ) ) -> type ) ) == (Scheme_Type ) (scheme_id_macro_type ) ) ) {
          Scheme_Object * new_name ; 
          BLOCK_SETUP((PUSH(new_name, 0+XfOrM605_COUNT)));
#         define XfOrM606_COUNT (1+XfOrM605_COUNT)
#         define SETUP_XfOrM606(x) SETUP(XfOrM606_COUNT)
          new_name = NULLED_OUT ; 
          new_name = (((Scheme_Small_Object * ) ((((Scheme_Small_Object * ) (var ) ) -> u . ptr_val ) ) ) -> u . ptr_val ) ; 
          if (! rec [drec ] . comp ) {
#           define XfOrM609_COUNT (0+XfOrM606_COUNT)
#           define SETUP_XfOrM609(x) SETUP_XfOrM606(x)
            new_name = FUNCCALL(SETUP_XfOrM609(_), scheme_stx_track (new_name , find_name , find_name ) ); 
          }
          new_name = FUNCCALL(SETUP_XfOrM606(_), scheme_stx_cert (new_name , scheme_false , menv , find_name , ((void * ) 0 ) , 1 ) ); 
          find_name = new_name ; 
          {
#           define XfOrM607_COUNT (0+XfOrM606_COUNT)
#           define SETUP_XfOrM607(x) SETUP_XfOrM606(x)
            if ((scheme_fuel_counter ) <= 0 ) {
#             define XfOrM608_COUNT (0+XfOrM607_COUNT)
#             define SETUP_XfOrM608(x) SETUP_XfOrM607(x)
              FUNCCALL(SETUP_XfOrM608(_), scheme_out_of_fuel () ); 
            }
          }
          ; 
          menv = ((void * ) 0 ) ; 
        }
        else break ; 
      }
      if (! var ) {
      }
      else if (((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_local_type ) ) || ((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_local_unbox_type ) ) ) {
      }
      else {
#       define XfOrM585_COUNT (0+XfOrM583_COUNT)
#       define SETUP_XfOrM585(x) SETUP_XfOrM583(x)
        if (((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_macro_type ) ) ) {
          goto macro ; 
        }
        else if (((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_syntax_compiler_type ) ) ) {
#         define XfOrM586_COUNT (0+XfOrM585_COUNT)
#         define SETUP_XfOrM586(x) SETUP_XfOrM585(x)
          if (rec [drec ] . comp ) {
            Scheme_Syntax * f ; 
#           define XfOrM594_COUNT (0+XfOrM586_COUNT)
#           define SETUP_XfOrM594(x) SETUP_XfOrM586(x)
            f = NULLED_OUT ; 
            f = (Scheme_Syntax * ) (((Scheme_Simple_Object * ) (var ) ) -> u . two_ptr_val . ptr1 ) ; 
            RET_VALUE_START (FUNCCALL(SETUP_XfOrM594(_), f (form , env , rec , drec ) )) RET_VALUE_END ; 
          }
          else {
            Scheme_Syntax_Expander * f ; 
            BLOCK_SETUP((PUSH(f, 0+XfOrM586_COUNT)));
#           define XfOrM587_COUNT (1+XfOrM586_COUNT)
#           define SETUP_XfOrM587(x) SETUP(XfOrM587_COUNT)
            f = NULLED_OUT ; 
            f = (Scheme_Syntax_Expander * ) (((Scheme_Simple_Object * ) (var ) ) -> u . two_ptr_val . ptr2 ) ; 
            if (rec [drec ] . observer ) {
#             define XfOrM593_COUNT (0+XfOrM587_COUNT)
#             define SETUP_XfOrM593(x) SETUP_XfOrM587(x)
              FUNCCALL(SETUP_XfOrM593(_), scheme_call_expand_observe (rec [drec ] . observer , 6 , form ) ); 
            }
            else {
            }
            ; 
            form = FUNCCALL(SETUP_XfOrM587(_), f (form , env , rec , drec ) ); 
            if (rec [drec ] . observer ) {
#             define XfOrM591_COUNT (0+XfOrM587_COUNT)
#             define SETUP_XfOrM591(x) SETUP_XfOrM587(x)
              FUNCCALL(SETUP_XfOrM591(_), scheme_call_expand_observe (rec [drec ] . observer , 7 , form ) ); 
            }
            else {
            }
            ; 
            if (rec [drec ] . observer ) {
#             define XfOrM589_COUNT (0+XfOrM587_COUNT)
#             define SETUP_XfOrM589(x) SETUP_XfOrM587(x)
              FUNCCALL(SETUP_XfOrM589(_), scheme_call_expand_observe (rec [drec ] . observer , 2 , form ) ); 
            }
            else {
            }
            ; 
            RET_VALUE_START (form ) RET_VALUE_END ; 
          }
        }
      }
      if (! ((name ) == (find_name ) ) ) {
        Scheme_Object * code ; 
        BLOCK_SETUP((PUSH(code, 0+XfOrM583_COUNT)));
#       define XfOrM584_COUNT (1+XfOrM583_COUNT)
#       define SETUP_XfOrM584(x) SETUP(XfOrM584_COUNT)
        code = NULLED_OUT ; 
        code = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM584(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
        code = FUNCCALL(SETUP_XfOrM584(_), scheme_make_immutable_pair (find_name , code ) ); 
        form = FUNCCALL_AGAIN(scheme_datum_to_syntax (code , form , form , 0 , 0 ) ); 
      }
    }
    stx = app_symbol ; 
    not_allowed = "function application" ; 
    normal = app_expander ; 
  }
  if (quick_stx && rec [drec ] . comp ) {
    ((Scheme_Stx * ) quick_stx ) -> val = stx ; 
    ((Scheme_Stx * ) quick_stx ) -> wraps = ((Scheme_Stx * ) form ) -> wraps ; 
    ((Scheme_Stx * ) quick_stx ) -> u . modinfo_cache = ((void * ) 0 ) ; 
    stx = quick_stx ; 
    quick_stx = ((void * ) 0 ) ; 
  }
  else stx = FUNCCALL(SETUP_XfOrM528(_), scheme_datum_to_syntax (stx , scheme_false , form , 0 , 0 ) ); 
  if (rec [drec ] . comp )
    can_recycle_stx = stx ; 
  {
    Scheme_Object * find_name = stx ; 
    BLOCK_SETUP((PUSH(find_name, 0+XfOrM528_COUNT)));
#   define XfOrM566_COUNT (1+XfOrM528_COUNT)
#   define SETUP_XfOrM566(x) SETUP(XfOrM566_COUNT)
    while (1 ) {
#     define XfOrM574_COUNT (0+XfOrM566_COUNT)
#     define SETUP_XfOrM574(x) SETUP_XfOrM566(x)
      var = FUNCCALL(SETUP_XfOrM574(_), scheme_lookup_binding (find_name , env , 512 + 2 + 8 + 128 , rec [drec ] . certs , env -> in_modidx , & menv , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
      if (rec [drec ] . observer ) {
#       define XfOrM580_COUNT (0+XfOrM574_COUNT)
#       define SETUP_XfOrM580(x) SETUP_XfOrM574(x)
        FUNCCALL(SETUP_XfOrM580(_), scheme_call_expand_observe (rec [drec ] . observer , 1 , find_name ) ); 
      }
      else {
      }
      ; 
      if (var && ((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_macro_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Small_Object * ) (var ) ) -> u . ptr_val ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Small_Object * ) (var ) ) -> u . ptr_val ) ) ) -> type ) ) == (Scheme_Type ) (scheme_id_macro_type ) ) ) {
        Scheme_Object * new_name ; 
        BLOCK_SETUP((PUSH(new_name, 0+XfOrM574_COUNT)));
#       define XfOrM575_COUNT (1+XfOrM574_COUNT)
#       define SETUP_XfOrM575(x) SETUP(XfOrM575_COUNT)
        new_name = NULLED_OUT ; 
        new_name = (((Scheme_Small_Object * ) ((((Scheme_Small_Object * ) (var ) ) -> u . ptr_val ) ) ) -> u . ptr_val ) ; 
        if (! rec [drec ] . comp ) {
#         define XfOrM578_COUNT (0+XfOrM575_COUNT)
#         define SETUP_XfOrM578(x) SETUP_XfOrM575(x)
          new_name = FUNCCALL(SETUP_XfOrM578(_), scheme_stx_track (new_name , find_name , find_name ) ); 
        }
        new_name = FUNCCALL(SETUP_XfOrM575(_), scheme_stx_cert (new_name , scheme_false , menv , find_name , ((void * ) 0 ) , 1 ) ); 
        find_name = new_name ; 
        {
#         define XfOrM576_COUNT (0+XfOrM575_COUNT)
#         define SETUP_XfOrM576(x) SETUP_XfOrM575(x)
          if ((scheme_fuel_counter ) <= 0 ) {
#           define XfOrM577_COUNT (0+XfOrM576_COUNT)
#           define SETUP_XfOrM577(x) SETUP_XfOrM576(x)
            FUNCCALL(SETUP_XfOrM577(_), scheme_out_of_fuel () ); 
          }
        }
        ; 
        menv = ((void * ) 0 ) ; 
      }
      else break ; 
    }
  }
  if (! ((var ) == (normal ) ) ) {
    can_recycle_stx = ((void * ) 0 ) ; 
  }
  if (! var && looking_for_top ) {
    Scheme_Object * nm ; 
    BLOCK_SETUP((PUSH(nm, 0+XfOrM528_COUNT)));
#   define XfOrM563_COUNT (1+XfOrM528_COUNT)
#   define SETUP_XfOrM563(x) SETUP(XfOrM563_COUNT)
    nm = NULLED_OUT ; 
    nm = FUNCCALL(SETUP_XfOrM563(_), scheme_tl_id_sym (env -> genv , form , ((void * ) 0 ) , 0 ) ); 
    if (! ((nm ) == (((Scheme_Stx * ) form ) -> val ) ) ) {
#     define XfOrM564_COUNT (0+XfOrM563_COUNT)
#     define SETUP_XfOrM564(x) SETUP_XfOrM563(x)
      stx = (__funcarg63 = FUNCCALL(SETUP_XfOrM564(_), scheme_sys_wraps (env ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (top_symbol , scheme_false , __funcarg63 , 0 , 0 ) )) ; 
      var = FUNCCALL(SETUP_XfOrM564(_), scheme_lookup_binding (stx , env , 512 + 2 + 8 + 128 , rec [drec ] . certs , env -> in_modidx , & menv , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
    }
  }
  if (var && (((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_macro_type ) ) || ((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_syntax_compiler_type ) ) ) ) {
#   define XfOrM541_COUNT (0+XfOrM528_COUNT)
#   define SETUP_XfOrM541(x) SETUP_XfOrM528(x)
    if (((var ) == (stop_expander ) ) ) {
#     define XfOrM554_COUNT (0+XfOrM541_COUNT)
#     define SETUP_XfOrM554(x) SETUP_XfOrM541(x)
      if (rec [drec ] . observer ) {
#       define XfOrM562_COUNT (0+XfOrM554_COUNT)
#       define SETUP_XfOrM562(x) SETUP_XfOrM554(x)
        FUNCCALL(SETUP_XfOrM562(_), scheme_call_expand_observe (rec [drec ] . observer , 6 , form ) ); 
      }
      else {
      }
      ; 
      if (rec [drec ] . observer ) {
#       define XfOrM560_COUNT (0+XfOrM554_COUNT)
#       define SETUP_XfOrM560(x) SETUP_XfOrM554(x)
        FUNCCALL(SETUP_XfOrM560(_), scheme_call_expand_observe (rec [drec ] . observer , 100 , ((void * ) 0 ) ) ); 
      }
      else {
      }
      ; 
      if (rec [drec ] . observer ) {
#       define XfOrM558_COUNT (0+XfOrM554_COUNT)
#       define SETUP_XfOrM558(x) SETUP_XfOrM554(x)
        FUNCCALL(SETUP_XfOrM558(_), scheme_call_expand_observe (rec [drec ] . observer , 7 , form ) ); 
      }
      else {
      }
      ; 
      if (rec [drec ] . observer ) {
#       define XfOrM556_COUNT (0+XfOrM554_COUNT)
#       define SETUP_XfOrM556(x) SETUP_XfOrM554(x)
        FUNCCALL(SETUP_XfOrM556(_), scheme_call_expand_observe (rec [drec ] . observer , 2 , form ) ); 
      }
      else {
      }
      ; 
      RET_VALUE_START (form ) RET_VALUE_END ; 
    }
    else if (rec [drec ] . comp && ((var ) == (normal ) ) ) {
      Scheme_Syntax * f ; 
#     define XfOrM553_COUNT (0+XfOrM541_COUNT)
#     define SETUP_XfOrM553(x) SETUP_XfOrM541(x)
      f = NULLED_OUT ; 
      taking_shortcut = 1 ; 
      f = (Scheme_Syntax * ) (((Scheme_Simple_Object * ) (var ) ) -> u . two_ptr_val . ptr1 ) ; 
      if (can_recycle_stx && ! quick_stx )
        quick_stx = can_recycle_stx ; 
      RET_VALUE_START (FUNCCALL(SETUP_XfOrM553(_), f (form , env , rec , drec ) )) RET_VALUE_END ; 
    }
    else {
#     define XfOrM542_COUNT (0+XfOrM541_COUNT)
#     define SETUP_XfOrM542(x) SETUP_XfOrM541(x)
      form = (__funcarg62 = FUNCCALL(SETUP_XfOrM542(_), scheme_make_immutable_pair (stx , form ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg62 , form , form , 0 , 2 ) )) ; 
      if (((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_syntax_compiler_type ) ) ) {
#       define XfOrM544_COUNT (0+XfOrM542_COUNT)
#       define SETUP_XfOrM544(x) SETUP_XfOrM542(x)
        if (rec [drec ] . comp ) {
          Scheme_Syntax * f ; 
#         define XfOrM552_COUNT (0+XfOrM544_COUNT)
#         define SETUP_XfOrM552(x) SETUP_XfOrM544(x)
          f = NULLED_OUT ; 
          f = (Scheme_Syntax * ) (((Scheme_Simple_Object * ) (var ) ) -> u . two_ptr_val . ptr1 ) ; 
          RET_VALUE_START (FUNCCALL(SETUP_XfOrM552(_), f (form , env , rec , drec ) )) RET_VALUE_END ; 
        }
        else {
          Scheme_Syntax_Expander * f ; 
          BLOCK_SETUP((PUSH(f, 0+XfOrM544_COUNT)));
#         define XfOrM545_COUNT (1+XfOrM544_COUNT)
#         define SETUP_XfOrM545(x) SETUP(XfOrM545_COUNT)
          f = NULLED_OUT ; 
          f = (Scheme_Syntax_Expander * ) (((Scheme_Simple_Object * ) (var ) ) -> u . two_ptr_val . ptr2 ) ; 
          if (rec [drec ] . observer ) {
#           define XfOrM551_COUNT (0+XfOrM545_COUNT)
#           define SETUP_XfOrM551(x) SETUP_XfOrM545(x)
            FUNCCALL(SETUP_XfOrM551(_), scheme_call_expand_observe (rec [drec ] . observer , 6 , form ) ); 
          }
          else {
          }
          ; 
          form = FUNCCALL(SETUP_XfOrM545(_), f (form , env , rec , drec ) ); 
          if (rec [drec ] . observer ) {
#           define XfOrM549_COUNT (0+XfOrM545_COUNT)
#           define SETUP_XfOrM549(x) SETUP_XfOrM545(x)
            FUNCCALL(SETUP_XfOrM549(_), scheme_call_expand_observe (rec [drec ] . observer , 7 , form ) ); 
          }
          else {
          }
          ; 
          if (rec [drec ] . observer ) {
#           define XfOrM547_COUNT (0+XfOrM545_COUNT)
#           define SETUP_XfOrM547(x) SETUP_XfOrM545(x)
            FUNCCALL(SETUP_XfOrM547(_), scheme_call_expand_observe (rec [drec ] . observer , 2 , form ) ); 
          }
          else {
          }
          ; 
          RET_VALUE_START (form ) RET_VALUE_END ; 
        }
      }
      else {
        name = stx ; 
        goto macro ; 
      }
    }
  }
  else {
#   define XfOrM540_COUNT (0+XfOrM528_COUNT)
#   define SETUP_XfOrM540(x) SETUP_XfOrM528(x)
    FUNCCALL(SETUP_XfOrM540(_), scheme_wrong_syntax (scheme_compile_stx_string , ((void * ) 0 ) , form , "bad syntax; %s is not allowed, " "because no %S syntax transformer is bound" , not_allowed , ((Scheme_Stx * ) stx ) -> val ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  macro : if (! rec [drec ] . comp && ! rec [drec ] . depth ) {
#   define XfOrM537_COUNT (0+XfOrM528_COUNT)
#   define SETUP_XfOrM537(x) SETUP_XfOrM528(x)
    if (rec [drec ] . observer ) {
#     define XfOrM539_COUNT (0+XfOrM537_COUNT)
#     define SETUP_XfOrM539(x) SETUP_XfOrM537(x)
      FUNCCALL(SETUP_XfOrM539(_), scheme_call_expand_observe (rec [drec ] . observer , 2 , form ) ); 
    }
    else {
    }
    ; 
    RET_VALUE_START (form ) RET_VALUE_END ; 
  }
  if (rec [drec ] . observer ) {
#   define XfOrM536_COUNT (0+XfOrM528_COUNT)
#   define SETUP_XfOrM536(x) SETUP_XfOrM528(x)
    FUNCCALL(SETUP_XfOrM536(_), scheme_call_expand_observe (rec [drec ] . observer , 8 , form ) ); 
  }
  else {
  }
  ; 
  form = FUNCCALL(SETUP_XfOrM528(_), compile_expand_macro_app (name , menv , var , form , env , rec , drec ) ); 
  if (rec [drec ] . observer ) {
#   define XfOrM534_COUNT (0+XfOrM528_COUNT)
#   define SETUP_XfOrM534(x) SETUP_XfOrM528(x)
    FUNCCALL(SETUP_XfOrM534(_), scheme_call_expand_observe (rec [drec ] . observer , 9 , form ) ); 
  }
  else {
  }
  ; 
  if (rec [drec ] . comp )
    goto top ; 
  else {
#   define XfOrM529_COUNT (0+XfOrM528_COUNT)
#   define SETUP_XfOrM529(x) SETUP_XfOrM528(x)
    if (rec [drec ] . depth > 0 )
      -- rec [drec ] . depth ; 
    if (rec [drec ] . depth )
      goto top ; 
    else {
#     define XfOrM530_COUNT (0+XfOrM529_COUNT)
#     define SETUP_XfOrM530(x) SETUP_XfOrM529(x)
      if (rec [drec ] . observer ) {
#       define XfOrM532_COUNT (0+XfOrM530_COUNT)
#       define SETUP_XfOrM532(x) SETUP_XfOrM530(x)
        FUNCCALL(SETUP_XfOrM532(_), scheme_call_expand_observe (rec [drec ] . observer , 2 , form ) ); 
      }
      else {
      }
      ; 
      RET_VALUE_START (form ) RET_VALUE_END ; 
    }
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int arg_count (Scheme_Object * lam , Scheme_Comp_Env * env ) {
  Scheme_Object * l , * id , * form = lam ; 
  int cnt = 0 ; 
  DupCheckRecord r ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(9);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(lam, 1), PUSHARRAY(r.syms, 5, 2), PUSH(r.ht, 5), PUSH(l, 6), PUSH(form, 7), PUSH(id, 8)));
# define XfOrM664_COUNT (9)
# define SETUP_XfOrM664(x) SETUP(XfOrM664_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  l = NULLED_OUT ; 
  id = NULLED_OUT ; 
  NULL_OUT_ARRAY (r.syms ) ; 
  r.ht = NULLED_OUT ; 
  lam = (((Scheme_Type ) (((((long ) (lam ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lam ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (lam ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM664(_), scheme_stx_content (lam ) )) ) -> u . pair_val . cdr ) ) ; 
  if (! (((Scheme_Type ) (((((long ) (lam ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lam ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (lam ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lam ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) lam ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) lam ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
    RET_VALUE_START (- 1 ) RET_VALUE_END ; 
  l = (((Scheme_Type ) (((((long ) (lam ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lam ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (lam ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM664(_), scheme_stx_content (lam ) )) ) -> u . pair_val . car ) ) ; 
  lam = (((Scheme_Type ) (((((long ) (lam ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lam ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (lam ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM664(_), scheme_stx_content (lam ) )) ) -> u . pair_val . cdr ) ) ; 
  if (! (((Scheme_Type ) (((((long ) (lam ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lam ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (lam ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lam ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) lam ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) lam ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
    RET_VALUE_START (- 1 ) RET_VALUE_END ; 
  while ((((Scheme_Type ) (((((long ) (lam ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lam ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (lam ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lam ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) lam ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) lam ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
#   define XfOrM668_COUNT (0+XfOrM664_COUNT)
#   define SETUP_XfOrM668(x) SETUP_XfOrM664(x)
    lam = (((Scheme_Type ) (((((long ) (lam ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lam ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (lam ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM668(_), scheme_stx_content (lam ) )) ) -> u . pair_val . cdr ) ) ; 
  }
  if (! (((lam ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (lam ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lam ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) lam ) -> val ) == (scheme_null ) ) ) ) )
    RET_VALUE_START (- 1 ) RET_VALUE_END ; 
  FUNCCALL(SETUP_XfOrM664(_), scheme_begin_dup_symbol_check (& r , env ) ); 
  while ((((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) l ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) l ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
#   define XfOrM666_COUNT (0+XfOrM664_COUNT)
#   define SETUP_XfOrM666(x) SETUP_XfOrM664(x)
    id = (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM666(_), scheme_stx_content (l ) )) ) -> u . pair_val . car ) ) ; 
    FUNCCALL(SETUP_XfOrM666(_), scheme_check_identifier ("lambda" , id , ((void * ) 0 ) , env , form ) ); 
    FUNCCALL_AGAIN(scheme_dup_symbol_check (& r , ((void * ) 0 ) , id , "argument" , form ) ); 
    l = (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM666(_), scheme_stx_content (l ) )) ) -> u . pair_val . cdr ) ) ; 
    cnt ++ ; 
  }
  if (! (((l ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) l ) -> val ) == (scheme_null ) ) ) ) )
    RET_VALUE_START (- 1 ) RET_VALUE_END ; 
  RET_VALUE_START (cnt ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * compile_expand_app (Scheme_Object * forms , Scheme_Comp_Env * env , Scheme_Compile_Expand_Info * rec , int drec ) {
  Scheme_Object * form , * naya ; 
  int tsc = taking_shortcut ; 
  Scheme_Object * __funcarg90 = NULLED_OUT ; 
  Scheme_Object * __funcarg89 = NULLED_OUT ; 
  Scheme_Object * __funcarg88 = NULLED_OUT ; 
  Scheme_Comp_Env * __funcarg87 = NULLED_OUT ; 
  Scheme_Object * __funcarg86 = NULLED_OUT ; 
  Scheme_Object * __funcarg85 = NULLED_OUT ; 
  Scheme_Object * __funcarg84 = NULLED_OUT ; 
  Scheme_Object * __funcarg80 = NULLED_OUT ; 
  Scheme_Object * __funcarg79 = NULLED_OUT ; 
  Scheme_Object * __funcarg78 = NULLED_OUT ; 
  Scheme_Object * __funcarg77 = NULLED_OUT ; 
  Scheme_Object * __funcarg76 = NULLED_OUT ; 
  Scheme_Object * __funcarg75 = NULLED_OUT ; 
  Scheme_Object * __funcarg74 = NULLED_OUT ; 
  Scheme_Object * __funcarg73 = NULLED_OUT ; 
  Scheme_Object * __funcarg72 = NULLED_OUT ; 
  Scheme_Object * __funcarg71 = NULLED_OUT ; 
  Scheme_Object * __funcarg70 = NULLED_OUT ; 
  Scheme_Object * __funcarg69 = NULLED_OUT ; 
  Scheme_Object * __funcarg68 = NULLED_OUT ; 
  Scheme_Object * __funcarg67 = NULLED_OUT ; 
  Scheme_Comp_Env * __funcarg66 = NULLED_OUT ; 
  Scheme_Object * __funcarg65 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(26);
  BLOCK_SETUP_TOP((PUSH(naya, 0), PUSH(__funcarg85, 1), PUSH(__funcarg88, 2), PUSH(__funcarg78, 3), PUSH(__funcarg76, 4), PUSH(env, 5), PUSH(forms, 6), PUSH(form, 7), PUSH(rec, 8)));
# define XfOrM669_COUNT (9)
# define SETUP_XfOrM669(x) SETUP(XfOrM669_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  form = NULLED_OUT ; 
  naya = NULLED_OUT ; 
  taking_shortcut = 0 ; 
  FUNCCALL(SETUP_XfOrM669(_), scheme_rec_add_certs (rec , drec , forms ) ); 
  if (tsc ) {
    form = forms ; 
  }
  else {
#   define XfOrM695_COUNT (0+XfOrM669_COUNT)
#   define SETUP_XfOrM695(x) SETUP_XfOrM669(x)
    form = (((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (forms ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM695(_), scheme_stx_content (forms ) )) ) -> u . pair_val . cdr ) ) ; 
    form = FUNCCALL(SETUP_XfOrM695(_), scheme_datum_to_syntax (form , forms , forms , 0 , 0 ) ); 
  }
  if ((((form ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) form ) -> val ) == (scheme_null ) ) ) ) ) {
#   define XfOrM694_COUNT (0+XfOrM669_COUNT)
#   define SETUP_XfOrM694(x) SETUP_XfOrM669(x)
    if (rec [drec ] . comp )
      RET_VALUE_START (scheme_null ) RET_VALUE_END ; 
    else RET_VALUE_START ((__funcarg88 = (__funcarg90 = FUNCCALL(SETUP_XfOrM694(_), scheme_make_pair (form , scheme_null ) ), FUNCCALL_AGAIN(scheme_make_pair (quote_symbol , __funcarg90 ) )) , __funcarg89 = FUNCCALL(SETUP_XfOrM694(_), scheme_sys_wraps (env ) ), FUNCCALL_EMPTY(scheme_datum_to_syntax (__funcarg88 , form , __funcarg89 , 0 , 2 ) )) ) RET_VALUE_END ; 
  }
  else if (! (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) form ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) form ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
#   define XfOrM692_COUNT (0+XfOrM669_COUNT)
#   define SETUP_XfOrM692(x) SETUP_XfOrM669(x)
    if (rec [drec ] . comp )
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(compile_application (form , env , rec , drec ) )) RET_VALUE_EMPTY_END ; 
    else {
#     define XfOrM693_COUNT (0+XfOrM692_COUNT)
#     define SETUP_XfOrM693(x) SETUP_XfOrM692(x)
      rec [drec ] . value_name = scheme_false ; 
      naya = (__funcarg87 = FUNCCALL(SETUP_XfOrM693(_), scheme_no_defines (env ) ), FUNCCALL_AGAIN(scheme_expand_list (form , __funcarg87 , rec , drec ) )) ; 
    }
  }
  else if (rec [drec ] . comp ) {
    Scheme_Object * name , * origname , * gval , * orig_rest_form , * rest_form ; 
    BLOCK_SETUP((PUSH(gval, 0+XfOrM669_COUNT), PUSH(origname, 1+XfOrM669_COUNT), PUSH(rest_form, 2+XfOrM669_COUNT), PUSH(orig_rest_form, 3+XfOrM669_COUNT), PUSH(name, 4+XfOrM669_COUNT)));
#   define XfOrM672_COUNT (5+XfOrM669_COUNT)
#   define SETUP_XfOrM672(x) SETUP(XfOrM672_COUNT)
    name = NULLED_OUT ; 
    origname = NULLED_OUT ; 
    gval = NULLED_OUT ; 
    orig_rest_form = NULLED_OUT ; 
    rest_form = NULLED_OUT ; 
    name = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM672(_), scheme_stx_content (form ) )) ) -> u . pair_val . car ) ) ; 
    origname = name ; 
    name = FUNCCALL(SETUP_XfOrM672(_), scheme_check_immediate_macro (name , env , rec , drec , 0 , & gval , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
    if (((gval ) == (scheme_lambda_syntax ) ) ) {
      Scheme_Object * argsnbody ; 
      BLOCK_SETUP((PUSH(argsnbody, 0+XfOrM672_COUNT)));
#     define XfOrM684_COUNT (1+XfOrM672_COUNT)
#     define SETUP_XfOrM684(x) SETUP(XfOrM684_COUNT)
      argsnbody = NULLED_OUT ; 
      argsnbody = (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (name ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM684(_), scheme_stx_content (name ) )) ) -> u . pair_val . cdr ) ) ; 
      if ((((Scheme_Type ) (((((long ) (argsnbody ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argsnbody ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (argsnbody ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argsnbody ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) argsnbody ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) argsnbody ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
        Scheme_Object * args , * body ; 
        BLOCK_SETUP((PUSH(args, 0+XfOrM684_COUNT), PUSH(body, 1+XfOrM684_COUNT)));
#       define XfOrM685_COUNT (2+XfOrM684_COUNT)
#       define SETUP_XfOrM685(x) SETUP(XfOrM685_COUNT)
        args = NULLED_OUT ; 
        body = NULLED_OUT ; 
        args = (((Scheme_Type ) (((((long ) (argsnbody ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argsnbody ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (argsnbody ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM685(_), scheme_stx_content (argsnbody ) )) ) -> u . pair_val . car ) ) ; 
        body = (((Scheme_Type ) (((((long ) (argsnbody ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argsnbody ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (argsnbody ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM685(_), scheme_stx_content (argsnbody ) )) ) -> u . pair_val . cdr ) ) ; 
        if ((((Scheme_Type ) (((((long ) (body ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (body ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (body ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (body ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) body ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) body ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
          int pl ; 
#         define XfOrM686_COUNT (0+XfOrM685_COUNT)
#         define SETUP_XfOrM686(x) SETUP_XfOrM685(x)
          pl = FUNCCALL(SETUP_XfOrM686(_), scheme_stx_proper_list_length (args ) ); 
          if (pl >= 0 ) {
            Scheme_Object * bindings = scheme_null , * last = ((void * ) 0 ) ; 
            Scheme_Object * rest ; 
            int al ; 
            BLOCK_SETUP((PUSH(bindings, 0+XfOrM686_COUNT), PUSH(rest, 1+XfOrM686_COUNT), PUSH(last, 2+XfOrM686_COUNT)));
#           define XfOrM687_COUNT (3+XfOrM686_COUNT)
#           define SETUP_XfOrM687(x) SETUP(XfOrM687_COUNT)
            rest = NULLED_OUT ; 
            rest = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM687(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
            al = FUNCCALL(SETUP_XfOrM687(_), scheme_stx_proper_list_length (rest ) ); 
            if (al == pl ) {
              DupCheckRecord r ; 
              BLOCK_SETUP((PUSHARRAY(r.syms, 5, 0+XfOrM687_COUNT), PUSH(r.ht, 3+XfOrM687_COUNT)));
#             define XfOrM689_COUNT (4+XfOrM687_COUNT)
#             define SETUP_XfOrM689(x) SETUP(XfOrM689_COUNT)
              NULL_OUT_ARRAY (r.syms ) ; 
              r.ht = NULLED_OUT ; 
              FUNCCALL(SETUP_XfOrM689(_), scheme_begin_dup_symbol_check (& r , env ) ); 
              while (! (((args ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (args ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) args ) -> val ) == (scheme_null ) ) ) ) ) {
                Scheme_Object * v , * n ; 
                BLOCK_SETUP((PUSH(v, 0+XfOrM689_COUNT), PUSH(n, 1+XfOrM689_COUNT)));
#               define XfOrM691_COUNT (2+XfOrM689_COUNT)
#               define SETUP_XfOrM691(x) SETUP(XfOrM691_COUNT)
                v = NULLED_OUT ; 
                n = NULLED_OUT ; 
                n = (((Scheme_Type ) (((((long ) (args ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (args ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM691(_), scheme_stx_content (args ) )) ) -> u . pair_val . car ) ) ; 
                FUNCCALL(SETUP_XfOrM691(_), scheme_check_identifier ("lambda" , n , ((void * ) 0 ) , env , name ) ); 
                FUNCCALL_AGAIN(scheme_dup_symbol_check (& r , ((void * ) 0 ) , n , "argument" , name ) ); 
                v = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM691(_), scheme_stx_content (rest ) )) ) -> u . pair_val . car ) ) ; 
                v = (__funcarg84 = (__funcarg85 = FUNCCALL(SETUP_XfOrM691(_), scheme_make_pair (n , scheme_null ) ), __funcarg86 = FUNCCALL(SETUP_XfOrM691(_), scheme_make_pair (v , scheme_null ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg85 , __funcarg86 ) )) , FUNCCALL_AGAIN(scheme_make_pair (__funcarg84 , scheme_null ) )) ; 
                if (last )
                  (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = v ; 
                else bindings = v ; 
                last = v ; 
                args = (((Scheme_Type ) (((((long ) (args ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (args ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM691(_), scheme_stx_content (args ) )) ) -> u . pair_val . cdr ) ) ; 
                rest = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM691(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ; 
              }
              body = (__funcarg78 = (__funcarg80 = FUNCCALL(SETUP_XfOrM689(_), scheme_make_pair (bindings , body ) ), FUNCCALL_AGAIN(scheme_make_pair (let_values_symbol , __funcarg80 ) )) , __funcarg79 = FUNCCALL(SETUP_XfOrM689(_), scheme_sys_wraps (env ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg78 , form , __funcarg79 , 0 , 2 ) )) ; 
              body = FUNCCALL(SETUP_XfOrM689(_), scheme_stx_cert (body , ((void * ) 0 ) , ((void * ) 0 ) , name , ((void * ) 0 ) , 1 ) ); 
              RET_VALUE_START (FUNCCALL(SETUP_XfOrM689(_), scheme_compile_expand_expr (body , env , rec , drec , 0 ) )) RET_VALUE_END ; 
            }
            else {
            }
          }
        }
      }
    }
    orig_rest_form = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM672(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
    if ((((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) name ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) name ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) ) {
      Scheme_Object * at_first , * at_second , * the_end , * cwv_stx ; 
      BLOCK_SETUP((PUSH(at_second, 0+XfOrM672_COUNT), PUSH(the_end, 1+XfOrM672_COUNT), PUSH(at_first, 2+XfOrM672_COUNT), PUSH(cwv_stx, 3+XfOrM672_COUNT)));
#     define XfOrM675_COUNT (4+XfOrM672_COUNT)
#     define SETUP_XfOrM675(x) SETUP(XfOrM675_COUNT)
      at_first = NULLED_OUT ; 
      at_second = NULLED_OUT ; 
      the_end = NULLED_OUT ; 
      cwv_stx = NULLED_OUT ; 
      at_first = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM675(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
      if ((((Scheme_Type ) (((((long ) (at_first ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (at_first ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (at_first ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (at_first ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) at_first ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) at_first ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
#       define XfOrM676_COUNT (0+XfOrM675_COUNT)
#       define SETUP_XfOrM676(x) SETUP_XfOrM675(x)
        at_second = (((Scheme_Type ) (((((long ) (at_first ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (at_first ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (at_first ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM676(_), scheme_stx_content (at_first ) )) ) -> u . pair_val . cdr ) ) ; 
        if ((((Scheme_Type ) (((((long ) (at_second ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (at_second ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (at_second ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (at_second ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) at_second ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) at_second ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
#         define XfOrM677_COUNT (0+XfOrM676_COUNT)
#         define SETUP_XfOrM677(x) SETUP_XfOrM676(x)
          the_end = (((Scheme_Type ) (((((long ) (at_second ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (at_second ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (at_second ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM677(_), scheme_stx_content (at_second ) )) ) -> u . pair_val . cdr ) ) ; 
          if ((((the_end ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (the_end ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (the_end ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) the_end ) -> val ) == (scheme_null ) ) ) ) ) {
            Scheme_Object * orig_at_second = at_second ; 
            BLOCK_SETUP((PUSH(orig_at_second, 0+XfOrM677_COUNT)));
#           define XfOrM678_COUNT (1+XfOrM677_COUNT)
#           define SETUP_XfOrM678(x) SETUP(XfOrM678_COUNT)
            cwv_stx = (__funcarg76 = FUNCCALL(SETUP_XfOrM678(_), scheme_intern_symbol ("call-with-values" ) ), __funcarg77 = FUNCCALL(SETUP_XfOrM678(_), scheme_sys_wraps (env ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg76 , scheme_false , __funcarg77 , 0 , 0 ) )) ; 
            if (FUNCCALL(SETUP_XfOrM678(_), scheme_stx_module_eq (name , cwv_stx , 0 ) )) {
              Scheme_Object * first , * orig_first ; 
              BLOCK_SETUP((PUSH(first, 0+XfOrM678_COUNT), PUSH(orig_first, 1+XfOrM678_COUNT)));
#             define XfOrM679_COUNT (2+XfOrM678_COUNT)
#             define SETUP_XfOrM679(x) SETUP(XfOrM679_COUNT)
              first = NULLED_OUT ; 
              orig_first = NULLED_OUT ; 
              orig_first = (((Scheme_Type ) (((((long ) (at_first ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (at_first ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (at_first ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM679(_), scheme_stx_content (at_first ) )) ) -> u . pair_val . car ) ) ; 
              first = FUNCCALL(SETUP_XfOrM679(_), scheme_check_immediate_macro (orig_first , env , rec , drec , 0 , & gval , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
              if (((gval ) == (scheme_lambda_syntax ) ) && (((Scheme_Type ) (((((long ) (first ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (first ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (first ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (first ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) first ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) first ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) && (FUNCCALL(SETUP_XfOrM679(_), arg_count (first , env ) )== 0 ) ) {
                Scheme_Object * second , * orig_second ; 
                BLOCK_SETUP((PUSH(orig_second, 0+XfOrM679_COUNT), PUSH(second, 1+XfOrM679_COUNT)));
#               define XfOrM681_COUNT (2+XfOrM679_COUNT)
#               define SETUP_XfOrM681(x) SETUP(XfOrM681_COUNT)
                second = NULLED_OUT ; 
                orig_second = NULLED_OUT ; 
                orig_second = (((Scheme_Type ) (((((long ) (at_second ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (at_second ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (at_second ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM681(_), scheme_stx_content (at_second ) )) ) -> u . pair_val . car ) ) ; 
                second = FUNCCALL(SETUP_XfOrM681(_), scheme_check_immediate_macro (orig_second , env , rec , drec , 0 , & gval , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
                if (((gval ) == (scheme_lambda_syntax ) ) && (((Scheme_Type ) (((((long ) (second ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (second ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (second ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (second ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) second ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) second ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) && (FUNCCALL(SETUP_XfOrM681(_), arg_count (second , env ) )>= 0 ) ) {
                  Scheme_Object * lhs ; 
                  BLOCK_SETUP((PUSH(lhs, 0+XfOrM681_COUNT)));
#                 define XfOrM683_COUNT (1+XfOrM681_COUNT)
#                 define SETUP_XfOrM683(x) SETUP(XfOrM683_COUNT)
                  lhs = NULLED_OUT ; 
                  second = (((Scheme_Type ) (((((long ) (second ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (second ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (second ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM683(_), scheme_stx_content (second ) )) ) -> u . pair_val . cdr ) ) ; 
                  lhs = (((Scheme_Type ) (((((long ) (second ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (second ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (second ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM683(_), scheme_stx_content (second ) )) ) -> u . pair_val . car ) ) ; 
                  second = (((Scheme_Type ) (((((long ) (second ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (second ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (second ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM683(_), scheme_stx_content (second ) )) ) -> u . pair_val . cdr ) ) ; 
                  first = (((Scheme_Type ) (((((long ) (first ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (first ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (first ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM683(_), scheme_stx_content (first ) )) ) -> u . pair_val . cdr ) ) ; 
                  first = (((Scheme_Type ) (((((long ) (first ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (first ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (first ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM683(_), scheme_stx_content (first ) )) ) -> u . pair_val . cdr ) ) ; 
                  name = (__funcarg71 = (__funcarg72 = (__funcarg73 = (__funcarg74 = (__funcarg75 = FUNCCALL(SETUP_XfOrM683(_), scheme_make_immutable_pair (begin_symbol , first ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (__funcarg75 , scheme_null ) )) , FUNCCALL_AGAIN(scheme_make_immutable_pair (lhs , __funcarg74 ) )) , FUNCCALL_AGAIN(scheme_make_immutable_pair (__funcarg73 , scheme_null ) )) , FUNCCALL_AGAIN(scheme_make_immutable_pair (__funcarg72 , second ) )) , FUNCCALL_AGAIN(scheme_make_immutable_pair (let_values_symbol , __funcarg71 ) )) ; 
                  form = (__funcarg70 = FUNCCALL(SETUP_XfOrM683(_), scheme_sys_wraps (env ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (name , forms , __funcarg70 , 0 , 2 ) )) ; 
                  RET_VALUE_START (FUNCCALL(SETUP_XfOrM683(_), scheme_compile_expand_expr (form , env , rec , drec , 0 ) )) RET_VALUE_END ; 
                }
                if (! ((second ) == (orig_second ) ) ) {
#                 define XfOrM682_COUNT (0+XfOrM681_COUNT)
#                 define SETUP_XfOrM682(x) SETUP_XfOrM681(x)
                  at_second = (__funcarg69 = FUNCCALL(SETUP_XfOrM682(_), scheme_make_immutable_pair (second , the_end ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg69 , at_second , at_second , 0 , 2 ) )) ; 
                }
              }
              if (! ((first ) == (orig_first ) ) || ! ((at_second ) == (orig_at_second ) ) ) {
#               define XfOrM680_COUNT (0+XfOrM679_COUNT)
#               define SETUP_XfOrM680(x) SETUP_XfOrM679(x)
                at_first = (__funcarg68 = FUNCCALL(SETUP_XfOrM680(_), scheme_make_immutable_pair (first , at_second ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg68 , at_first , at_first , 0 , 2 ) )) ; 
              }
            }
          }
        }
      }
      rest_form = at_first ; 
    }
    else {
      rest_form = orig_rest_form ; 
    }
    if (((name ) != (origname ) ) || ((rest_form ) != (orig_rest_form ) ) ) {
#     define XfOrM673_COUNT (0+XfOrM672_COUNT)
#     define SETUP_XfOrM673(x) SETUP_XfOrM672(x)
      form = (__funcarg67 = FUNCCALL(SETUP_XfOrM673(_), scheme_make_immutable_pair (name , rest_form ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg67 , forms , forms , 0 , 2 ) )) ; 
    }
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM672(_), compile_application (form , env , rec , drec ) )) RET_VALUE_END ; 
  }
  else {
#   define XfOrM671_COUNT (0+XfOrM669_COUNT)
#   define SETUP_XfOrM671(x) SETUP_XfOrM669(x)
    FUNCCALL(SETUP_XfOrM671(_), scheme_rec_add_certs (rec , drec , form ) ); 
    rec [drec ] . value_name = scheme_false ; 
    naya = (__funcarg66 = FUNCCALL(SETUP_XfOrM671(_), scheme_no_defines (env ) ), FUNCCALL_AGAIN(scheme_expand_list (form , __funcarg66 , rec , drec ) )) ; 
  }
  if (((form ) == (naya ) ) )
    RET_VALUE_START (forms ) RET_VALUE_END ; 
  {
    Scheme_Object * first ; 
    BLOCK_SETUP((PUSH(first, 0+XfOrM669_COUNT)));
#   define XfOrM670_COUNT (1+XfOrM669_COUNT)
#   define SETUP_XfOrM670(x) SETUP(XfOrM670_COUNT)
    first = NULLED_OUT ; 
    first = (((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (forms ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM670(_), scheme_stx_content (forms ) )) ) -> u . pair_val . car ) ) ; 
    RET_VALUE_START ((__funcarg65 = FUNCCALL(SETUP_XfOrM670(_), scheme_make_immutable_pair (first , naya ) ), FUNCCALL_EMPTY(scheme_datum_to_syntax (__funcarg65 , forms , forms , 0 , 2 ) )) ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * app_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  /* No conversion */
  return compile_expand_app (form , env , rec , drec ) ; 
}
static Scheme_Object * app_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(erec, 1), PUSH(form, 2)));
# define XfOrM698_COUNT (3)
# define SETUP_XfOrM698(x) SETUP(XfOrM698_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (erec [drec ] . observer ) {
#   define XfOrM700_COUNT (0+XfOrM698_COUNT)
#   define SETUP_XfOrM700(x) SETUP_XfOrM698(x)
    FUNCCALL(SETUP_XfOrM700(_), scheme_call_expand_observe (erec [drec ] . observer , 109 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(compile_expand_app (form , env , erec , drec ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * datum_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  Scheme_Object * c ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(c, 0), PUSH(form, 1)));
# define XfOrM701_COUNT (2)
# define SETUP_XfOrM701(x) SETUP(XfOrM701_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  c = NULLED_OUT ; 
  if (taking_shortcut ) {
    c = form ; 
    taking_shortcut = 0 ; 
  }
  else {
#   define XfOrM702_COUNT (0+XfOrM701_COUNT)
#   define SETUP_XfOrM702(x) SETUP_XfOrM701(x)
    c = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM702(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
    c = FUNCCALL(SETUP_XfOrM702(_), scheme_datum_to_syntax (c , form , form , 0 , 2 ) ); 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_syntax_to_datum (c , 0 , ((void * ) 0 ) ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * datum_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(form, 0)));
# define XfOrM704_COUNT (1)
# define SETUP_XfOrM704(x) SETUP(XfOrM704_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (erec [drec ] . observer ) {
#   define XfOrM706_COUNT (0+XfOrM704_COUNT)
#   define SETUP_XfOrM706(x) SETUP_XfOrM704(x)
    FUNCCALL(SETUP_XfOrM706(_), scheme_call_expand_observe (erec [drec ] . observer , 115 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  RET_VALUE_START (form ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * check_top (const char * when , Scheme_Object * form , Scheme_Comp_Env * env ) {
  Scheme_Object * c ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(c, 0), PUSH(env, 1), PUSH(when, 2), PUSH(form, 3)));
# define XfOrM707_COUNT (4)
# define SETUP_XfOrM707(x) SETUP(XfOrM707_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  c = NULLED_OUT ; 
  if (taking_shortcut ) {
    c = form ; 
    taking_shortcut = 0 ; 
  }
  else c = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM707(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  if (! (((Scheme_Type ) (((((long ) (c ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (c ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (c ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (c ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) c ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) c ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , form , ((void * ) 0 ) ) ); 
  if (env -> genv -> module ) {
    Scheme_Object * modidx , * symbol = c , * tl_id ; 
    int bad ; 
    BLOCK_SETUP((PUSH(symbol, 0+XfOrM707_COUNT), PUSH(tl_id, 1+XfOrM707_COUNT), PUSH(modidx, 2+XfOrM707_COUNT)));
#   define XfOrM708_COUNT (3+XfOrM707_COUNT)
#   define SETUP_XfOrM708(x) SETUP(XfOrM708_COUNT)
    modidx = NULLED_OUT ; 
    tl_id = NULLED_OUT ; 
    tl_id = FUNCCALL(SETUP_XfOrM708(_), scheme_tl_id_sym (env -> genv , symbol , ((void * ) 0 ) , 0 ) ); 
    if (((tl_id ) != ((((Scheme_Type ) (((((long ) (symbol ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (symbol ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ? ((Scheme_Stx * ) symbol ) -> val : symbol ) ) ) ) {
    }
    else {
#     define XfOrM709_COUNT (0+XfOrM708_COUNT)
#     define SETUP_XfOrM709(x) SETUP_XfOrM708(x)
      modidx = FUNCCALL(SETUP_XfOrM709(_), scheme_stx_module_name (& symbol , env -> genv -> phase , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
      if (modidx ) {
#       define XfOrM712_COUNT (0+XfOrM709_COUNT)
#       define SETUP_XfOrM712(x) SETUP_XfOrM709(x)
        if (env -> genv -> module && ((FUNCCALL(SETUP_XfOrM712(_), scheme_module_resolve (modidx , 1 ) )) == (env -> genv -> module -> modname ) ) )
          bad = 0 ; 
        else bad = 1 ; 
      }
      else bad = 1 ; 
      if (! env -> genv -> rename ) {
#       define XfOrM710_COUNT (0+XfOrM709_COUNT)
#       define SETUP_XfOrM710(x) SETUP_XfOrM709(x)
        if (bad || ! FUNCCALL(SETUP_XfOrM710(_), scheme_lookup_in_table (env -> genv -> toplevel , (const char * ) (((Scheme_Type ) (((((long ) (c ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (c ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ? ((Scheme_Stx * ) c ) -> val : c ) ) )) {
#         define XfOrM711_COUNT (0+XfOrM710_COUNT)
#         define SETUP_XfOrM711(x) SETUP_XfOrM710(x)
          FUNCCALL(SETUP_XfOrM711(_), scheme_wrong_syntax (when , ((void * ) 0 ) , c , (env -> genv -> phase ? "unbound variable in module (transformer environment)" : "unbound variable in module" ) ) ); 
        }
      }
    }
  }
  RET_VALUE_START (c ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * top_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  Scheme_Object * c ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(c, 1), PUSH(rec, 2)));
# define XfOrM715_COUNT (3)
# define SETUP_XfOrM715(x) SETUP(XfOrM715_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  c = NULLED_OUT ; 
  c = FUNCCALL(SETUP_XfOrM715(_), check_top (scheme_compile_stx_string , form , env ) ); 
  c = FUNCCALL_AGAIN(scheme_tl_id_sym (env -> genv , c , ((void * ) 0 ) , 0 ) ); 
  if (env -> genv -> module && ! rec [drec ] . resolve_module_ids ) {
#   define XfOrM716_COUNT (0+XfOrM715_COUNT)
#   define SETUP_XfOrM716(x) SETUP_XfOrM715(x)
    c = FUNCCALL(SETUP_XfOrM716(_), scheme_hash_module_variable (env -> genv , env -> genv -> module -> self_modidx , c , env -> genv -> module -> insp , - 1 , env -> genv -> mod_phase ) ); 
  }
  else c = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM715(_), scheme_global_bucket (c , env -> genv ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_register_toplevel_in_prefix (c , env , rec , drec ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * top_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(form, 1)));
# define XfOrM717_COUNT (2)
# define SETUP_XfOrM717(x) SETUP(XfOrM717_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (erec [drec ] . observer ) {
#   define XfOrM719_COUNT (0+XfOrM717_COUNT)
#   define SETUP_XfOrM719(x) SETUP_XfOrM717(x)
    FUNCCALL(SETUP_XfOrM719(_), scheme_call_expand_observe (erec [drec ] . observer , 116 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  FUNCCALL(SETUP_XfOrM717(_), check_top (scheme_expand_stx_string , form , env ) ); 
  RET_VALUE_START (form ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_compile_expr (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  /* No conversion */
  return scheme_compile_expand_expr (form , env , rec , drec , 0 ) ; 
}
Scheme_Object * scheme_expand_expr (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  /* No conversion */
  return scheme_compile_expand_expr (form , env , erec , drec , 0 ) ; 
}
static Scheme_Object * pair_lifted (Scheme_Object * _ip , Scheme_Object * * _id , Scheme_Object * expr , Scheme_Comp_Env * env ) {
  Scheme_Comp_Env * * ip = (Scheme_Comp_Env * * ) _ip , * naya ; 
  Scheme_Object * __funcarg92 = NULLED_OUT ; 
  Scheme_Object * __funcarg91 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(__funcarg91, 0), PUSH(ip, 1), PUSH(_id, 2), PUSH(expr, 3), PUSH(naya, 4)));
# define XfOrM722_COUNT (5)
# define SETUP_XfOrM722(x) SETUP(XfOrM722_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  naya = NULLED_OUT ; 
  naya = FUNCCALL(SETUP_XfOrM722(_), scheme_new_compilation_frame (1 , 512 , (* ip ) -> next , ((void * ) 0 ) ) ); 
  (* ip ) -> next = naya ; 
  * ip = naya ; 
  FUNCCALL(SETUP_XfOrM722(_), scheme_add_compilation_binding (0 , * _id , naya ) ); 
  RET_VALUE_START ((__funcarg91 = FUNCCALL(SETUP_XfOrM722(_), scheme_make_immutable_pair (* _id , scheme_null ) ), __funcarg92 = FUNCCALL(SETUP_XfOrM722(_), scheme_make_immutable_pair (expr , scheme_null ) ), FUNCCALL_EMPTY(scheme_make_immutable_pair (__funcarg91 , __funcarg92 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * compile_expand_expr_lift_to_let_k (void ) ; 
static Scheme_Object * compile_expand_expr_lift_to_let (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * rec , int drec ) {
  Scheme_Expand_Info recs [2 ] ; 
  Scheme_Object * l , * orig_form = form , * context_key ; 
  Scheme_Comp_Env * inserted , * * ip ; 
  Scheme_Object * __funcarg102 = NULLED_OUT ; 
  Scheme_Object * __funcarg101 = NULLED_OUT ; 
  Scheme_Object * __funcarg100 = NULLED_OUT ; 
  Scheme_Object * __funcarg99 = NULLED_OUT ; 
  Scheme_Object * __funcarg98 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(18);
  BLOCK_SETUP_TOP((PUSH(__funcarg98, 0), PUSH(orig_form, 1), PUSH(rec, 2), PUSH(inserted, 3), PUSH(l, 4), PUSH(recs[0].value_name, 5), PUSH(recs[0].certs, 6), PUSH(recs[0].observer, 7), PUSH(recs[1].value_name, 8), PUSH(recs[1].certs, 9), PUSH(recs[1].observer, 10), PUSH(env, 11), PUSH(ip, 12), PUSH(__funcarg100, 13), PUSH(form, 14), PUSH(context_key, 15)));
# define XfOrM723_COUNT (16)
# define SETUP_XfOrM723(x) SETUP(XfOrM723_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  recs[0].value_name = NULLED_OUT ; 
  recs[0].certs = NULLED_OUT ; 
  recs[0].observer = NULLED_OUT ; 
  recs[1].value_name = NULLED_OUT ; 
  recs[1].certs = NULLED_OUT ; 
  recs[1].observer = NULLED_OUT ; 
  l = NULLED_OUT ; 
  context_key = NULLED_OUT ; 
  inserted = NULLED_OUT ; 
  ip = NULLED_OUT ; 
  {
    unsigned long _stk_pos ; 
#   define XfOrM735_COUNT (0+XfOrM723_COUNT)
#   define SETUP_XfOrM735(x) SETUP_XfOrM723(x)
    _stk_pos = (unsigned long ) & _stk_pos ; 
    if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
      Scheme_Thread * p = scheme_current_thread ; 
      Scheme_Compile_Expand_Info * recx ; 
      BLOCK_SETUP((PUSH(recx, 0+XfOrM735_COUNT), PUSH(p, 1+XfOrM735_COUNT)));
#     define XfOrM736_COUNT (2+XfOrM735_COUNT)
#     define SETUP_XfOrM736(x) SETUP(XfOrM736_COUNT)
      recx = NULLED_OUT ; 
      recx = ((Scheme_Compile_Expand_Info * ) FUNCCALL(SETUP_XfOrM736(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Compile_Expand_Info ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
      (memcpy (recx , rec + drec , sizeof (Scheme_Compile_Expand_Info ) ) ) ; 
      recx -> type = scheme_rt_compile_info ; 
      p -> ku . k . p1 = (void * ) form ; 
      p -> ku . k . p2 = (void * ) env ; 
      p -> ku . k . p3 = (void * ) recx ; 
      form = FUNCCALL(SETUP_XfOrM736(_), scheme_handle_stack_overflow (compile_expand_expr_lift_to_let_k ) ); 
      (memcpy (rec + drec , recx , sizeof (Scheme_Compile_Expand_Info ) ) ) ; 
      RET_VALUE_START (form ) RET_VALUE_END ; 
    }
  }
  inserted = FUNCCALL(SETUP_XfOrM723(_), scheme_new_compilation_frame (0 , 0 , env , ((void * ) 0 ) ) ); 
  ip = ((Scheme_Comp_Env * * ) FUNCCALL(SETUP_XfOrM723(_), GC_malloc (sizeof (Scheme_Comp_Env * ) * (1 ) ) )) ; 
  * ip = inserted ; 
  context_key = FUNCCALL(SETUP_XfOrM723(_), scheme_generate_lifts_key () ); 
  FUNCCALL_AGAIN(scheme_frame_captures_lifts (inserted , pair_lifted , (Scheme_Object * ) ip , scheme_false , context_key ) ); 
  if (rec [drec ] . comp ) {
#   define XfOrM734_COUNT (0+XfOrM723_COUNT)
#   define SETUP_XfOrM734(x) SETUP_XfOrM723(x)
    FUNCCALL(SETUP_XfOrM734(_), scheme_init_compile_recs (rec , drec , recs , 2 ) ); 
    form = FUNCCALL(SETUP_XfOrM734(_), scheme_compile_expr (form , inserted , recs , 0 ) ); 
  }
  else {
#   define XfOrM733_COUNT (0+XfOrM723_COUNT)
#   define SETUP_XfOrM733(x) SETUP_XfOrM723(x)
    FUNCCALL(SETUP_XfOrM733(_), scheme_init_expand_recs (rec , drec , recs , 2 ) ); 
    form = FUNCCALL(SETUP_XfOrM733(_), scheme_expand_expr (form , inserted , recs , 0 ) ); 
  }
  l = FUNCCALL(SETUP_XfOrM723(_), scheme_frame_get_lifts (inserted ) ); 
  if (((l ) == (scheme_null ) ) ) {
#   define XfOrM732_COUNT (0+XfOrM723_COUNT)
#   define SETUP_XfOrM732(x) SETUP_XfOrM723(x)
    if (rec [drec ] . comp )
      FUNCCALL(SETUP_XfOrM732(_), scheme_merge_compile_recs (rec , drec , recs , 1 ) ); 
    RET_VALUE_START (form ) RET_VALUE_END ; 
  }
  else {
    Scheme_Object * o , * revl ; 
    BLOCK_SETUP((PUSH(o, 0+XfOrM723_COUNT), PUSH(revl, 1+XfOrM723_COUNT)));
#   define XfOrM724_COUNT (2+XfOrM723_COUNT)
#   define SETUP_XfOrM724(x) SETUP(XfOrM724_COUNT)
    o = NULLED_OUT ; 
    revl = NULLED_OUT ; 
    if (rec [drec ] . comp ) {
#     define XfOrM731_COUNT (0+XfOrM724_COUNT)
#     define SETUP_XfOrM731(x) SETUP_XfOrM724(x)
      o = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM731(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
      o -> type = scheme_already_comp_type ; 
      (((Scheme_Simple_Object * ) (o ) ) -> u . ptr_int_val . ptr ) = form ; 
    }
    else o = form ; 
    for (revl = scheme_null ; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#     define XfOrM730_COUNT (0+XfOrM724_COUNT)
#     define SETUP_XfOrM730(x) SETUP_XfOrM724(x)
      revl = FUNCCALL(SETUP_XfOrM730(_), scheme_make_immutable_pair ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) , revl ) ); 
    }
    for (; ((Scheme_Type ) (((((long ) (revl ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (revl ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; revl = (((Scheme_Simple_Object * ) (revl ) ) -> u . pair_val . cdr ) ) {
#     define XfOrM728_COUNT (0+XfOrM724_COUNT)
#     define SETUP_XfOrM728(x) SETUP_XfOrM724(x)
      o = (__funcarg98 = (__funcarg102 = FUNCCALL(SETUP_XfOrM728(_), scheme_sys_wraps (env ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (let_values_symbol , scheme_false , __funcarg102 , 0 , 0 ) )) , __funcarg99 = (__funcarg100 = FUNCCALL(SETUP_XfOrM728(_), scheme_make_immutable_pair ((((Scheme_Simple_Object * ) (revl ) ) -> u . pair_val . car ) , scheme_null ) ), __funcarg101 = FUNCCALL(SETUP_XfOrM728(_), scheme_make_immutable_pair (o , scheme_null ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (__funcarg100 , __funcarg101 ) )) , FUNCCALL_AGAIN(scheme_make_immutable_pair (__funcarg98 , __funcarg99 ) )) ; 
    }
    form = FUNCCALL(SETUP_XfOrM724(_), scheme_datum_to_syntax (o , orig_form , scheme_false , 0 , 0 ) ); 
    if (rec [drec ] . observer ) {
#     define XfOrM726_COUNT (0+XfOrM724_COUNT)
#     define SETUP_XfOrM726(x) SETUP_XfOrM724(x)
      FUNCCALL(SETUP_XfOrM726(_), scheme_call_expand_observe (rec [drec ] . observer , 136 , form ) ); 
    }
    else {
    }
    ; 
    form = FUNCCALL(SETUP_XfOrM724(_), compile_expand_expr_lift_to_let (form , env , recs , 1 ) ); 
    if (rec [drec ] . comp )
      FUNCCALL(SETUP_XfOrM724(_), scheme_merge_compile_recs (rec , drec , recs , 2 ) ); 
    RET_VALUE_START (form ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * compile_expand_expr_lift_to_let_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * form = (Scheme_Object * ) p -> ku . k . p1 ; 
  Scheme_Comp_Env * env = (Scheme_Comp_Env * ) p -> ku . k . p2 ; 
  Scheme_Compile_Info * rec = (Scheme_Compile_Info * ) p -> ku . k . p3 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  p -> ku . k . p2 = ((void * ) 0 ) ; 
  p -> ku . k . p3 = ((void * ) 0 ) ; 
  return compile_expand_expr_lift_to_let (form , env , rec , 0 ) ; 
}
Scheme_Object * scheme_compile_expr_lift_to_let (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  /* No conversion */
  return compile_expand_expr_lift_to_let (form , env , rec , drec ) ; 
}
Scheme_Object * scheme_expand_expr_lift_to_let (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  /* No conversion */
  return compile_expand_expr_lift_to_let (form , env , erec , drec ) ; 
}
static Scheme_Object * scheme_compile_expand_block (Scheme_Object * forms , Scheme_Comp_Env * env , Scheme_Compile_Expand_Info * rec , int drec ) {
  Scheme_Object * first , * rib , * ctx , * ectx ; 
  Scheme_Comp_Env * xenv = ((void * ) 0 ) ; 
  Scheme_Compile_Info recs [2 ] ; 
  DupCheckRecord r ; 
  Scheme_Object * __funcarg109 = NULLED_OUT ; 
  Scheme_Object * __funcarg108 = NULLED_OUT ; 
  Scheme_Object * __funcarg106 = NULLED_OUT ; 
  Scheme_Object * __funcarg105 = NULLED_OUT ; 
  Scheme_Object * __funcarg104 = NULLED_OUT ; 
  Scheme_Object * __funcarg103 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(33);
  BLOCK_SETUP_TOP((PUSH(first, 0), PUSH(forms, 1), PUSH(rib, 2), PUSH(xenv, 3), PUSHARRAY(r.syms, 5, 4), PUSH(r.ht, 7), PUSH(ctx, 8), PUSH(ectx, 9), PUSH(recs[0].value_name, 10), PUSH(recs[0].certs, 11), PUSH(recs[0].observer, 12), PUSH(recs[1].value_name, 13), PUSH(recs[1].certs, 14), PUSH(recs[1].observer, 15), PUSH(env, 16), PUSH(rec, 17)));
# define XfOrM740_COUNT (18)
# define SETUP_XfOrM740(x) SETUP(XfOrM740_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  first = NULLED_OUT ; 
  rib = NULLED_OUT ; 
  ctx = NULLED_OUT ; 
  ectx = NULLED_OUT ; 
  recs[0].value_name = NULLED_OUT ; 
  recs[0].certs = NULLED_OUT ; 
  recs[0].observer = NULLED_OUT ; 
  recs[1].value_name = NULLED_OUT ; 
  recs[1].certs = NULLED_OUT ; 
  recs[1].observer = NULLED_OUT ; 
  NULL_OUT_ARRAY (r.syms ) ; 
  r.ht = NULLED_OUT ; 
  if (rec [drec ] . comp ) {
#   define XfOrM844_COUNT (0+XfOrM740_COUNT)
#   define SETUP_XfOrM844(x) SETUP_XfOrM740(x)
    FUNCCALL(SETUP_XfOrM844(_), scheme_default_compile_rec (rec , drec ) ); 
  }
  else {
#   define XfOrM841_COUNT (0+XfOrM740_COUNT)
#   define SETUP_XfOrM841(x) SETUP_XfOrM740(x)
    if (rec [drec ] . observer ) {
#     define XfOrM843_COUNT (0+XfOrM841_COUNT)
#     define SETUP_XfOrM843(x) SETUP_XfOrM841(x)
      FUNCCALL(SETUP_XfOrM843(_), scheme_call_expand_observe (rec [drec ] . observer , 10 , forms ) ); 
    }
    else {
    }
    ; 
  }
  if ((((forms ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) forms ) -> val ) == (scheme_null ) ) ) ) ) {
#   define XfOrM832_COUNT (0+XfOrM740_COUNT)
#   define SETUP_XfOrM832(x) SETUP_XfOrM740(x)
    if (rec [drec ] . comp ) {
#     define XfOrM840_COUNT (0+XfOrM832_COUNT)
#     define SETUP_XfOrM840(x) SETUP_XfOrM832(x)
      FUNCCALL(SETUP_XfOrM840(_), scheme_compile_rec_done_local (rec , drec ) ); 
      RET_VALUE_START (scheme_null ) RET_VALUE_END ; 
    }
    else {
#     define XfOrM833_COUNT (0+XfOrM832_COUNT)
#     define SETUP_XfOrM833(x) SETUP_XfOrM832(x)
      if (rec [drec ] . observer ) {
#       define XfOrM839_COUNT (0+XfOrM833_COUNT)
#       define SETUP_XfOrM839(x) SETUP_XfOrM833(x)
        FUNCCALL(SETUP_XfOrM839(_), scheme_call_expand_observe (rec [drec ] . observer , 12 , forms ) ); 
      }
      else {
      }
      ; 
      if (rec [drec ] . observer ) {
#       define XfOrM837_COUNT (0+XfOrM833_COUNT)
#       define SETUP_XfOrM837(x) SETUP_XfOrM833(x)
        FUNCCALL(SETUP_XfOrM837(_), scheme_call_expand_observe (rec [drec ] . observer , 4 , forms ) ); 
      }
      else {
      }
      ; 
      if (rec [drec ] . observer ) {
#       define XfOrM835_COUNT (0+XfOrM833_COUNT)
#       define SETUP_XfOrM835(x) SETUP_XfOrM833(x)
        FUNCCALL(SETUP_XfOrM835(_), scheme_call_expand_observe (rec [drec ] . observer , 5 , forms ) ); 
      }
      else {
      }
      ; 
      RET_VALUE_START (forms ) RET_VALUE_END ; 
    }
  }
  rib = FUNCCALL(SETUP_XfOrM740(_), scheme_make_rename_rib () ); 
  ctx = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM740(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  ctx -> type = scheme_intdef_context_type ; 
  (((Scheme_Simple_Object * ) (ctx ) ) -> u . two_ptr_val . ptr1 ) = env ; 
  (((Scheme_Simple_Object * ) (ctx ) ) -> u . two_ptr_val . ptr2 ) = rib ; 
  ectx = FUNCCALL(SETUP_XfOrM740(_), scheme_make_pair (ctx , scheme_null ) ); 
  FUNCCALL_AGAIN(scheme_begin_dup_symbol_check (& r , env ) ); 
  try_again : if (rec [drec ] . observer ) {
#   define XfOrM831_COUNT (0+XfOrM740_COUNT)
#   define SETUP_XfOrM831(x) SETUP_XfOrM740(x)
    FUNCCALL(SETUP_XfOrM831(_), scheme_call_expand_observe (rec [drec ] . observer , 3 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  if (! (((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) forms ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) forms ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
#   define XfOrM829_COUNT (0+XfOrM740_COUNT)
#   define SETUP_XfOrM829(x) SETUP_XfOrM740(x)
    FUNCCALL(SETUP_XfOrM829(_), scheme_wrong_syntax (scheme_begin_stx_string , ((void * ) 0 ) , forms , "bad syntax" ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  first = (((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (forms ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM740(_), scheme_stx_content (forms ) )) ) -> u . pair_val . car ) ) ; 
  {
    Scheme_Object * old_first ; 
    BLOCK_SETUP((PUSH(old_first, 0+XfOrM740_COUNT)));
#   define XfOrM826_COUNT (1+XfOrM740_COUNT)
#   define SETUP_XfOrM826(x) SETUP(XfOrM826_COUNT)
    old_first = NULLED_OUT ; 
    old_first = first ; 
    first = FUNCCALL(SETUP_XfOrM826(_), scheme_add_rename_rib (first , rib ) ); 
    if (rec [drec ] . observer ) {
#     define XfOrM828_COUNT (0+XfOrM826_COUNT)
#     define SETUP_XfOrM828(x) SETUP_XfOrM826(x)
      (__funcarg109 = FUNCCALL(SETUP_XfOrM828(_), scheme_make_immutable_pair (old_first , first ) ), FUNCCALL_AGAIN(scheme_call_expand_observe (rec [drec ] . observer , 24 , __funcarg109 ) )) ; 
    }
    else {
    }
    ; 
  }
  {
    Scheme_Object * gval , * result ; 
    int more = 1 ; 
    BLOCK_SETUP((PUSH(gval, 0+XfOrM740_COUNT), PUSH(result, 1+XfOrM740_COUNT)));
#   define XfOrM745_COUNT (2+XfOrM740_COUNT)
#   define SETUP_XfOrM745(x) SETUP(XfOrM745_COUNT)
    gval = NULLED_OUT ; 
    result = NULLED_OUT ; 
    result = forms ; 
    first = FUNCCALL(SETUP_XfOrM745(_), scheme_check_immediate_macro (first , env , rec , drec , 1 , & gval , & xenv , ectx ) ); 
    if (((gval ) == (scheme_begin_syntax ) ) ) {
      Scheme_Object * orig_forms = forms ; 
      BLOCK_SETUP((PUSH(orig_forms, 0+XfOrM745_COUNT)));
#     define XfOrM819_COUNT (1+XfOrM745_COUNT)
#     define SETUP_XfOrM819(x) SETUP(XfOrM819_COUNT)
      if (rec [drec ] . observer ) {
#       define XfOrM825_COUNT (0+XfOrM819_COUNT)
#       define SETUP_XfOrM825(x) SETUP_XfOrM819(x)
        FUNCCALL(SETUP_XfOrM825(_), scheme_call_expand_observe (rec [drec ] . observer , 107 , ((void * ) 0 ) ) ); 
      }
      else {
      }
      ; 
      if (FUNCCALL(SETUP_XfOrM819(_), scheme_stx_proper_list_length (first ) )< 0 )
        FUNCCALL(SETUP_XfOrM819(_), scheme_wrong_syntax (scheme_begin_stx_string , ((void * ) 0 ) , first , "bad syntax (" "illegal use of `.'" ")" ) ); 
      forms = (((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (forms ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM819(_), scheme_stx_content (forms ) )) ) -> u . pair_val . cdr ) ) ; 
      if ((((forms ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) forms ) -> val ) == (scheme_null ) ) ) ) ) {
        Scheme_Object * v ; 
        BLOCK_SETUP((PUSH(v, 0+XfOrM819_COUNT)));
#       define XfOrM823_COUNT (1+XfOrM819_COUNT)
#       define SETUP_XfOrM823(x) SETUP(XfOrM823_COUNT)
        v = NULLED_OUT ; 
        v = FUNCCALL(SETUP_XfOrM823(_), scheme_check_name_property (first , rec [drec ] . value_name ) ); 
        rec [drec ] . value_name = v ; 
      }
      forms = FUNCCALL(SETUP_XfOrM819(_), scheme_flatten_begin (first , forms ) ); 
      if (rec [drec ] . observer ) {
#       define XfOrM822_COUNT (0+XfOrM819_COUNT)
#       define SETUP_XfOrM822(x) SETUP_XfOrM819(x)
        FUNCCALL(SETUP_XfOrM822(_), scheme_call_expand_observe (rec [drec ] . observer , 11 , forms ) ); 
      }
      else {
      }
      ; 
      if ((((forms ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) forms ) -> val ) == (scheme_null ) ) ) ) ) {
#       define XfOrM820_COUNT (0+XfOrM819_COUNT)
#       define SETUP_XfOrM820(x) SETUP_XfOrM819(x)
        FUNCCALL(SETUP_XfOrM820(_), scheme_wrong_syntax (scheme_begin_stx_string , ((void * ) 0 ) , first , "bad syntax (empty form)" ) ); 
      }
      forms = FUNCCALL(SETUP_XfOrM819(_), scheme_datum_to_syntax (forms , orig_forms , orig_forms , 0 , 0 ) ); 
      goto try_again ; 
    }
    else if (((gval ) == (scheme_define_values_syntax ) ) || ((gval ) == (scheme_define_syntaxes_syntax ) ) ) {
      Scheme_Object * var , * vars , * v , * link ; 
      Scheme_Object * l = scheme_null , * start = ((void * ) 0 ) ; 
      Scheme_Object * stx_l = scheme_null , * stx_start = ((void * ) 0 ) ; 
      int is_val ; 
      BLOCK_SETUP((PUSH(stx_l, 0+XfOrM745_COUNT), PUSH(v, 1+XfOrM745_COUNT), PUSH(link, 2+XfOrM745_COUNT), PUSH(stx_start, 3+XfOrM745_COUNT), PUSH(vars, 4+XfOrM745_COUNT), PUSH(l, 5+XfOrM745_COUNT), PUSH(start, 6+XfOrM745_COUNT), PUSH(var, 7+XfOrM745_COUNT)));
#     define XfOrM752_COUNT (8+XfOrM745_COUNT)
#     define SETUP_XfOrM752(x) SETUP(XfOrM752_COUNT)
      var = NULLED_OUT ; 
      vars = NULLED_OUT ; 
      v = NULLED_OUT ; 
      link = NULLED_OUT ; 
      while (1 ) {
        int cnt ; 
#       define XfOrM788_COUNT (0+XfOrM752_COUNT)
#       define SETUP_XfOrM788(x) SETUP_XfOrM752(x)
        is_val = ((gval ) == (scheme_define_values_syntax ) ) ; 
        v = (((Scheme_Type ) (((((long ) (first ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (first ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (first ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM788(_), scheme_stx_content (first ) )) ) -> u . pair_val . cdr ) ) ; 
        if (is_val ) {
#         define XfOrM816_COUNT (0+XfOrM788_COUNT)
#         define SETUP_XfOrM816(x) SETUP_XfOrM788(x)
          if (rec [drec ] . observer ) {
#           define XfOrM818_COUNT (0+XfOrM816_COUNT)
#           define SETUP_XfOrM818(x) SETUP_XfOrM816(x)
            FUNCCALL(SETUP_XfOrM818(_), scheme_call_expand_observe (rec [drec ] . observer , 104 , ((void * ) 0 ) ) ); 
          }
          else {
          }
          ; 
        }
        else {
#         define XfOrM813_COUNT (0+XfOrM788_COUNT)
#         define SETUP_XfOrM813(x) SETUP_XfOrM788(x)
          if (rec [drec ] . observer ) {
#           define XfOrM815_COUNT (0+XfOrM813_COUNT)
#           define SETUP_XfOrM815(x) SETUP_XfOrM813(x)
            FUNCCALL(SETUP_XfOrM815(_), scheme_call_expand_observe (rec [drec ] . observer , 103 , ((void * ) 0 ) ) ); 
          }
          else {
          }
          ; 
        }
        if (! (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) v ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) v ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
          FUNCCALL(SETUP_XfOrM788(_), scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , first , "bad syntax (" "illegal use of `.'" ")" ) ); 
        var = ((void * ) 0 ) ; 
        vars = (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM788(_), scheme_stx_content (v ) )) ) -> u . pair_val . car ) ) ; 
        cnt = 0 ; 
        while ((((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) vars ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) vars ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
#         define XfOrM812_COUNT (0+XfOrM788_COUNT)
#         define SETUP_XfOrM812(x) SETUP_XfOrM788(x)
          var = (((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (vars ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM812(_), scheme_stx_content (vars ) )) ) -> u . pair_val . car ) ) ; 
          if (! (((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) var ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) var ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) )
            FUNCCALL(SETUP_XfOrM812(_), scheme_wrong_syntax (((void * ) 0 ) , var , first , "name must be an identifier" ) ); 
          FUNCCALL(SETUP_XfOrM812(_), scheme_dup_symbol_check (& r , "internal definition" , var , "binding" , first ) ); 
          vars = (((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (vars ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM812(_), scheme_stx_content (vars ) )) ) -> u . pair_val . cdr ) ) ; 
          cnt ++ ; 
        }
        if (! (((vars ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) vars ) -> val ) == (scheme_null ) ) ) ) ) {
#         define XfOrM810_COUNT (0+XfOrM788_COUNT)
#         define SETUP_XfOrM810(x) SETUP_XfOrM788(x)
          vars = (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM810(_), scheme_stx_content (v ) )) ) -> u . pair_val . car ) ) ; 
          FUNCCALL(SETUP_XfOrM810(_), scheme_wrong_syntax (((void * ) 0 ) , vars , first , "not a sequence of identifiers" ) ); 
        }
        v = FUNCCALL(SETUP_XfOrM788(_), scheme_datum_to_syntax (v , first , first , 0 , 0 ) ); 
        var = (((Scheme_Type ) (((((long ) (first ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (first ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (first ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM788(_), scheme_stx_content (first ) )) ) -> u . pair_val . car ) ) ; 
        v = FUNCCALL(SETUP_XfOrM788(_), scheme_stx_track (v , first , var ) ); 
        link = FUNCCALL_AGAIN(scheme_make_immutable_pair (v , scheme_null ) ); 
        if (is_val ) {
          if (! start )
            start = link ; 
          else (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) = link ; 
          l = link ; 
        }
        else {
          if (! stx_start )
            stx_start = link ; 
          else (((Scheme_Simple_Object * ) (stx_l ) ) -> u . pair_val . cdr ) = link ; 
          stx_l = link ; 
        }
        result = (((Scheme_Type ) (((((long ) (result ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (result ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (result ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM788(_), scheme_stx_content (result ) )) ) -> u . pair_val . cdr ) ) ; 
        if (! (((result ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (result ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (result ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) result ) -> val ) == (scheme_null ) ) ) ) && ! (((Scheme_Type ) (((((long ) (result ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (result ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (result ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (result ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) result ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) result ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
          FUNCCALL(SETUP_XfOrM788(_), scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , first , ((void * ) 0 ) ) ); 
        {
          Scheme_Comp_Env * new_env ; 
          Scheme_Object * names , * expr , * l , * a ; 
          int pos ; 
          BLOCK_SETUP((PUSH(names, 0+XfOrM788_COUNT), PUSH(a, 1+XfOrM788_COUNT), PUSH(expr, 2+XfOrM788_COUNT), PUSH(new_env, 3+XfOrM788_COUNT), PUSH(l, 4+XfOrM788_COUNT)));
#         define XfOrM802_COUNT (5+XfOrM788_COUNT)
#         define SETUP_XfOrM802(x) SETUP(XfOrM802_COUNT)
          new_env = NULLED_OUT ; 
          names = NULLED_OUT ; 
          expr = NULLED_OUT ; 
          l = NULLED_OUT ; 
          a = NULLED_OUT ; 
          new_env = FUNCCALL(SETUP_XfOrM802(_), scheme_new_compilation_frame (0 , 256 , env , rec [drec ] . certs ) ); 
          names = (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM802(_), scheme_stx_content (v ) )) ) -> u . pair_val . car ) ) ; 
          expr = (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM802(_), scheme_stx_content (v ) )) ) -> u . pair_val . cdr ) ) ; 
          if (! (((Scheme_Type ) (((((long ) (expr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (expr ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (expr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (expr ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) expr ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) expr ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
#           define XfOrM807_COUNT (0+XfOrM802_COUNT)
#           define SETUP_XfOrM807(x) SETUP_XfOrM802(x)
            if ((((expr ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (expr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (expr ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) expr ) -> val ) == (scheme_null ) ) ) ) )
              FUNCCALL(SETUP_XfOrM807(_), scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , first , "bad syntax (missing expression)" ) ); 
            else FUNCCALL(SETUP_XfOrM807(_), scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , first , "bad syntax (" "illegal use of `.'" ")" ) ); 
          }
          link = (((Scheme_Type ) (((((long ) (expr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (expr ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (expr ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM802(_), scheme_stx_content (expr ) )) ) -> u . pair_val . cdr ) ) ; 
          if (! (((link ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (link ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (link ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) link ) -> val ) == (scheme_null ) ) ) ) ) {
#           define XfOrM806_COUNT (0+XfOrM802_COUNT)
#           define SETUP_XfOrM806(x) SETUP_XfOrM802(x)
            FUNCCALL(SETUP_XfOrM806(_), scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , first , "bad syntax (extra data after expression)" ) ); 
          }
          expr = (((Scheme_Type ) (((((long ) (expr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (expr ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (expr ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM802(_), scheme_stx_content (expr ) )) ) -> u . pair_val . car ) ) ; 
          FUNCCALL(SETUP_XfOrM802(_), scheme_add_local_syntax (cnt , new_env ) ); 
          cnt = 0 ; 
          for (l = names ; (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) l ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) l ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ; l = (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM802(_), scheme_stx_content (l ) )) ) -> u . pair_val . cdr ) ) ) {
#           define XfOrM805_COUNT (0+XfOrM802_COUNT)
#           define SETUP_XfOrM805(x) SETUP_XfOrM802(x)
            a = (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM805(_), scheme_stx_content (l ) )) ) -> u . pair_val . car ) ) ; 
            FUNCCALL(SETUP_XfOrM805(_), scheme_set_local_syntax (cnt ++ , a , scheme_false , new_env ) ); 
          }
          if (! is_val ) {
#           define XfOrM803_COUNT (0+XfOrM802_COUNT)
#           define SETUP_XfOrM803(x) SETUP_XfOrM802(x)
            FUNCCALL(SETUP_XfOrM803(_), scheme_prepare_exp_env (new_env -> genv ) ); 
            pos = 0 ; 
            expr = FUNCCALL(SETUP_XfOrM803(_), scheme_add_rename_rib (expr , rib ) ); 
            FUNCCALL_AGAIN(scheme_bind_syntaxes ("local syntax definition" , names , expr , new_env -> genv -> exp_env , new_env -> insp , rec , drec , new_env , new_env , & pos ) ); 
          }
          FUNCCALL(SETUP_XfOrM802(_), scheme_add_env_renames (rib , new_env , env ) ); 
          (((Scheme_Simple_Object * ) (ctx ) ) -> u . two_ptr_val . ptr1 ) = new_env ; 
          env = new_env ; 
          xenv = ((void * ) 0 ) ; 
        }
        define_try_again : if (! (((result ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (result ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (result ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) result ) -> val ) == (scheme_null ) ) ) ) ) {
#         define XfOrM789_COUNT (0+XfOrM788_COUNT)
#         define SETUP_XfOrM789(x) SETUP_XfOrM788(x)
          first = (((Scheme_Type ) (((((long ) (result ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (result ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (result ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM789(_), scheme_stx_content (result ) )) ) -> u . pair_val . car ) ) ; 
          first = FUNCCALL(SETUP_XfOrM789(_), scheme_datum_to_syntax (first , forms , forms , 0 , 0 ) ); 
          {
            Scheme_Object * old_first ; 
            BLOCK_SETUP((PUSH(old_first, 0+XfOrM789_COUNT)));
#           define XfOrM797_COUNT (1+XfOrM789_COUNT)
#           define SETUP_XfOrM797(x) SETUP(XfOrM797_COUNT)
            old_first = NULLED_OUT ; 
            old_first = first ; 
            first = FUNCCALL(SETUP_XfOrM797(_), scheme_add_rename_rib (first , rib ) ); 
            if (rec [drec ] . observer ) {
#             define XfOrM801_COUNT (0+XfOrM797_COUNT)
#             define SETUP_XfOrM801(x) SETUP_XfOrM797(x)
              FUNCCALL(SETUP_XfOrM801(_), scheme_call_expand_observe (rec [drec ] . observer , 3 , ((void * ) 0 ) ) ); 
            }
            else {
            }
            ; 
            if (rec [drec ] . observer ) {
#             define XfOrM799_COUNT (0+XfOrM797_COUNT)
#             define SETUP_XfOrM799(x) SETUP_XfOrM797(x)
              (__funcarg108 = FUNCCALL(SETUP_XfOrM799(_), scheme_make_immutable_pair (old_first , first ) ), FUNCCALL_AGAIN(scheme_call_expand_observe (rec [drec ] . observer , 24 , __funcarg108 ) )) ; 
            }
            else {
            }
            ; 
          }
          first = FUNCCALL(SETUP_XfOrM789(_), scheme_check_immediate_macro (first , env , rec , drec , 1 , & gval , & xenv , ectx ) ); 
          more = 1 ; 
          if (((gval ) != (scheme_define_values_syntax ) ) && ((gval ) != (scheme_define_syntaxes_syntax ) ) ) {
#           define XfOrM790_COUNT (0+XfOrM789_COUNT)
#           define SETUP_XfOrM790(x) SETUP_XfOrM789(x)
            if (((gval ) == (scheme_begin_syntax ) ) ) {
#             define XfOrM792_COUNT (0+XfOrM790_COUNT)
#             define SETUP_XfOrM792(x) SETUP_XfOrM790(x)
              result = (((Scheme_Type ) (((((long ) (result ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (result ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (result ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM792(_), scheme_stx_content (result ) )) ) -> u . pair_val . cdr ) ) ; 
              if (rec [drec ] . observer ) {
#               define XfOrM796_COUNT (0+XfOrM792_COUNT)
#               define SETUP_XfOrM796(x) SETUP_XfOrM792(x)
                FUNCCALL(SETUP_XfOrM796(_), scheme_call_expand_observe (rec [drec ] . observer , 107 , ((void * ) 0 ) ) ); 
              }
              else {
              }
              ; 
              result = FUNCCALL(SETUP_XfOrM792(_), scheme_flatten_begin (first , result ) ); 
              if (rec [drec ] . observer ) {
#               define XfOrM794_COUNT (0+XfOrM792_COUNT)
#               define SETUP_XfOrM794(x) SETUP_XfOrM792(x)
                FUNCCALL(SETUP_XfOrM794(_), scheme_call_expand_observe (rec [drec ] . observer , 11 , result ) ); 
              }
              else {
              }
              ; 
              goto define_try_again ; 
            }
            else {
#             define XfOrM791_COUNT (0+XfOrM790_COUNT)
#             define SETUP_XfOrM791(x) SETUP_XfOrM790(x)
              result = (((Scheme_Type ) (((((long ) (result ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (result ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (result ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM791(_), scheme_stx_content (result ) )) ) -> u . pair_val . cdr ) ) ; 
              result = FUNCCALL(SETUP_XfOrM791(_), scheme_make_pair (first , result ) ); 
              break ; 
            }
          }
        }
        else break ; 
      }
      if ((((Scheme_Type ) (((((long ) (result ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (result ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (result ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (result ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) result ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) result ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
#       define XfOrM754_COUNT (0+XfOrM752_COUNT)
#       define SETUP_XfOrM754(x) SETUP_XfOrM752(x)
        if (! start )
          start = scheme_null ; 
        if (stx_start ) {
#         define XfOrM756_COUNT (0+XfOrM754_COUNT)
#         define SETUP_XfOrM756(x) SETUP_XfOrM754(x)
          result = (__funcarg105 = (__funcarg106 = FUNCCALL(SETUP_XfOrM756(_), scheme_make_immutable_pair (start , result ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (stx_start , __funcarg106 ) )) , FUNCCALL_AGAIN(scheme_make_immutable_pair (letrec_syntaxes_symbol , __funcarg105 ) )) ; 
        }
        else {
#         define XfOrM755_COUNT (0+XfOrM754_COUNT)
#         define SETUP_XfOrM755(x) SETUP_XfOrM754(x)
          result = (__funcarg104 = FUNCCALL(SETUP_XfOrM755(_), scheme_make_immutable_pair (start , result ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (letrec_values_symbol , __funcarg104 ) )) ; 
        }
        result = (__funcarg103 = FUNCCALL(SETUP_XfOrM754(_), scheme_sys_wraps (env ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (result , forms , __funcarg103 , 0 , 2 ) )) ; 
        result = FUNCCALL(SETUP_XfOrM754(_), scheme_add_rename_rib (result , rib ) ); 
        more = 0 ; 
      }
      else {
#       define XfOrM753_COUNT (0+XfOrM752_COUNT)
#       define SETUP_XfOrM753(x) SETUP_XfOrM752(x)
        FUNCCALL(SETUP_XfOrM753(_), scheme_wrong_syntax (scheme_begin_stx_string , ((void * ) 0 ) , forms , "no expression after a sequence of internal definitions" ) ); 
      }
    }
    if (! more ) {
#     define XfOrM746_COUNT (0+XfOrM745_COUNT)
#     define SETUP_XfOrM746(x) SETUP_XfOrM745(x)
      if (rec [drec ] . comp ) {
#       define XfOrM751_COUNT (0+XfOrM746_COUNT)
#       define SETUP_XfOrM751(x) SETUP_XfOrM746(x)
        result = FUNCCALL(SETUP_XfOrM751(_), scheme_compile_expr (result , env , rec , drec ) ); 
        RET_VALUE_START (FUNCCALL(SETUP_XfOrM751(_), scheme_make_immutable_pair (result , scheme_null ) )) RET_VALUE_END ; 
      }
      else {
#       define XfOrM747_COUNT (0+XfOrM746_COUNT)
#       define SETUP_XfOrM747(x) SETUP_XfOrM746(x)
        if (rec [drec ] . depth > 0 )
          -- rec [drec ] . depth ; 
        if (rec [drec ] . depth ) {
#         define XfOrM748_COUNT (0+XfOrM747_COUNT)
#         define SETUP_XfOrM748(x) SETUP_XfOrM747(x)
          result = FUNCCALL(SETUP_XfOrM748(_), scheme_make_immutable_pair (result , scheme_null ) ); 
          if (rec [drec ] . observer ) {
#           define XfOrM750_COUNT (0+XfOrM748_COUNT)
#           define SETUP_XfOrM750(x) SETUP_XfOrM748(x)
            FUNCCALL(SETUP_XfOrM750(_), scheme_call_expand_observe (rec [drec ] . observer , 14 , result ) ); 
          }
          else {
          }
          ; 
          RET_VALUE_START (FUNCCALL(SETUP_XfOrM748(_), scheme_expand_list (result , env , rec , drec ) )) RET_VALUE_END ; 
        }
      }
    }
  }
  if (rec [drec ] . comp ) {
    Scheme_Object * vname , * rest ; 
    BLOCK_SETUP((PUSH(rest, 0+XfOrM740_COUNT), PUSH(vname, 1+XfOrM740_COUNT)));
#   define XfOrM744_COUNT (2+XfOrM740_COUNT)
#   define SETUP_XfOrM744(x) SETUP(XfOrM744_COUNT)
    vname = NULLED_OUT ; 
    rest = NULLED_OUT ; 
    vname = rec [drec ] . value_name ; 
    FUNCCALL(SETUP_XfOrM744(_), scheme_compile_rec_done_local (rec , drec ) ); 
    FUNCCALL_AGAIN(scheme_init_compile_recs (rec , drec , recs , 2 ) ); 
    rest = (((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (forms ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM744(_), scheme_stx_content (forms ) )) ) -> u . pair_val . cdr ) ) ; 
    if ((((rest ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) rest ) -> val ) == (scheme_null ) ) ) ) )
      recs [0 ] . value_name = vname ; 
    else recs [1 ] . value_name = vname ; 
    rest = FUNCCALL(SETUP_XfOrM744(_), scheme_datum_to_syntax (rest , forms , forms , 0 , 0 ) ); 
    first = FUNCCALL_AGAIN(scheme_compile_expr (first , env , recs , 0 ) ); 
    forms = FUNCCALL_AGAIN(scheme_compile_list (rest , env , recs , 1 ) ); 
    FUNCCALL_AGAIN(scheme_merge_compile_recs (rec , drec , recs , 2 ) ); 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM744(_), scheme_make_immutable_pair (first , forms ) )) RET_VALUE_END ; 
  }
  else {
    Scheme_Object * newforms , * vname ; 
    BLOCK_SETUP((PUSH(newforms, 0+XfOrM740_COUNT), PUSH(vname, 1+XfOrM740_COUNT)));
#   define XfOrM741_COUNT (2+XfOrM740_COUNT)
#   define SETUP_XfOrM741(x) SETUP(XfOrM741_COUNT)
    newforms = NULLED_OUT ; 
    vname = NULLED_OUT ; 
    vname = rec [drec ] . value_name ; 
    rec [drec ] . value_name = scheme_false ; 
    FUNCCALL(SETUP_XfOrM741(_), scheme_init_expand_recs (rec , drec , recs , 2 ) ); 
    recs [0 ] . value_name = vname ; 
    newforms = (((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (forms ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM741(_), scheme_stx_content (forms ) )) ) -> u . pair_val . cdr ) ) ; 
    newforms = FUNCCALL(SETUP_XfOrM741(_), scheme_make_immutable_pair (first , newforms ) ); 
    forms = FUNCCALL_AGAIN(scheme_datum_to_syntax (newforms , forms , forms , 0 , - 1 ) ); 
    if (FUNCCALL(SETUP_XfOrM741(_), scheme_stx_proper_list_length (forms ) )< 0 )
      FUNCCALL(SETUP_XfOrM741(_), scheme_wrong_syntax (scheme_begin_stx_string , ((void * ) 0 ) , forms , "bad syntax" ) ); 
    if (rec [drec ] . observer ) {
#     define XfOrM743_COUNT (0+XfOrM741_COUNT)
#     define SETUP_XfOrM743(x) SETUP_XfOrM741(x)
      FUNCCALL(SETUP_XfOrM743(_), scheme_call_expand_observe (rec [drec ] . observer , 12 , forms ) ); 
    }
    else {
    }
    ; 
    forms = FUNCCALL(SETUP_XfOrM741(_), scheme_expand_list (forms , env , recs , 0 ) ); 
    RET_VALUE_START (forms ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_compile_block (Scheme_Object * forms , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  /* No conversion */
  return scheme_compile_expand_block (forms , env , rec , drec ) ; 
}
Scheme_Object * scheme_expand_block (Scheme_Object * forms , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  /* No conversion */
  return scheme_compile_expand_block (forms , env , erec , drec ) ; 
}
Scheme_Object * scheme_expand_list (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  Scheme_Object * first = ((void * ) 0 ) , * last = ((void * ) 0 ) , * fm ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(11);
  BLOCK_SETUP_TOP((PUSH(first, 0), PUSH(fm, 1), PUSH(env, 2), PUSH(form, 3), PUSH(erec, 4), PUSH(last, 5)));
# define XfOrM847_COUNT (6)
# define SETUP_XfOrM847(x) SETUP(XfOrM847_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  fm = NULLED_OUT ; 
  if (erec [drec ] . observer ) {
#   define XfOrM861_COUNT (0+XfOrM847_COUNT)
#   define SETUP_XfOrM861(x) SETUP_XfOrM847(x)
    FUNCCALL(SETUP_XfOrM861(_), scheme_call_expand_observe (erec [drec ] . observer , 4 , form ) ); 
  }
  else {
  }
  ; 
  if ((((form ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) form ) -> val ) == (scheme_null ) ) ) ) ) {
#   define XfOrM857_COUNT (0+XfOrM847_COUNT)
#   define SETUP_XfOrM857(x) SETUP_XfOrM847(x)
    if (erec [drec ] . observer ) {
#     define XfOrM859_COUNT (0+XfOrM857_COUNT)
#     define SETUP_XfOrM859(x) SETUP_XfOrM857(x)
      FUNCCALL(SETUP_XfOrM859(_), scheme_call_expand_observe (erec [drec ] . observer , 5 , form ) ); 
    }
    else {
    }
    ; 
    RET_VALUE_START (scheme_null ) RET_VALUE_END ; 
  }
  if (FUNCCALL(SETUP_XfOrM847(_), scheme_stx_proper_list_length (form ) )< 0 ) {
#   define XfOrM856_COUNT (0+XfOrM847_COUNT)
#   define SETUP_XfOrM856(x) SETUP_XfOrM847(x)
    FUNCCALL_EMPTY(scheme_wrong_syntax (scheme_application_stx_string , ((void * ) 0 ) , form , "bad syntax (" "illegal use of `.'" ")" ) ); 
  }
  fm = form ; 
  while ((((Scheme_Type ) (((((long ) (fm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fm ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (fm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fm ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) fm ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) fm ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
    Scheme_Object * r , * p ; 
    Scheme_Expand_Info erec1 ; 
    BLOCK_SETUP((PUSH(erec1.value_name, 0+XfOrM847_COUNT), PUSH(erec1.certs, 1+XfOrM847_COUNT), PUSH(erec1.observer, 2+XfOrM847_COUNT), PUSH(r, 3+XfOrM847_COUNT), PUSH(p, 4+XfOrM847_COUNT)));
#   define XfOrM853_COUNT (5+XfOrM847_COUNT)
#   define SETUP_XfOrM853(x) SETUP(XfOrM853_COUNT)
    r = NULLED_OUT ; 
    p = NULLED_OUT ; 
    erec1.value_name = NULLED_OUT ; 
    erec1.certs = NULLED_OUT ; 
    erec1.observer = NULLED_OUT ; 
    if (erec [drec ] . observer ) {
#     define XfOrM855_COUNT (0+XfOrM853_COUNT)
#     define SETUP_XfOrM855(x) SETUP_XfOrM853(x)
      FUNCCALL(SETUP_XfOrM855(_), scheme_call_expand_observe (erec [drec ] . observer , 3 , ((void * ) 0 ) ) ); 
    }
    else {
    }
    ; 
    p = (((Scheme_Type ) (((((long ) (fm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fm ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (fm ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM853(_), scheme_stx_content (fm ) )) ) -> u . pair_val . cdr ) ) ; 
    FUNCCALL(SETUP_XfOrM853(_), scheme_init_expand_recs (erec , drec , & erec1 , 1 ) ); 
    erec1 . value_name = ((((p ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) p ) -> val ) == (scheme_null ) ) ) ) ? erec [drec ] . value_name : scheme_false ) ; 
    r = (((Scheme_Type ) (((((long ) (fm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fm ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (fm ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM853(_), scheme_stx_content (fm ) )) ) -> u . pair_val . car ) ) ; 
    r = FUNCCALL(SETUP_XfOrM853(_), scheme_expand_expr (r , env , & erec1 , 0 ) ); 
    p = FUNCCALL_AGAIN(scheme_make_immutable_pair (r , scheme_null ) ); 
    if (last )
      (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = p ; 
    else first = p ; 
    last = p ; 
    fm = (((Scheme_Type ) (((((long ) (fm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fm ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (fm ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM853(_), scheme_stx_content (fm ) )) ) -> u . pair_val . cdr ) ) ; 
  }
  form = FUNCCALL(SETUP_XfOrM847(_), scheme_datum_to_syntax (first , form , form , 0 , 0 ) ); 
  if (erec [drec ] . observer ) {
#   define XfOrM849_COUNT (0+XfOrM847_COUNT)
#   define SETUP_XfOrM849(x) SETUP_XfOrM847(x)
    FUNCCALL(SETUP_XfOrM849(_), scheme_call_expand_observe (erec [drec ] . observer , 5 , form ) ); 
  }
  else {
  }
  ; 
  RET_VALUE_START (form ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_flatten_begin (Scheme_Object * expr , Scheme_Object * append_onto ) {
  Scheme_Object * l , * ll , * a , * name , * body ; 
  Scheme_Object * __funcarg110 = NULLED_OUT ; 
  PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSH(name, 0), PUSH(a, 1), PUSH(l, 2), PUSH(ll, 3), PUSH(expr, 4), PUSH(append_onto, 5), PUSH(body, 6)));
# define XfOrM862_COUNT (7)
# define SETUP_XfOrM862(x) SETUP(XfOrM862_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  l = NULLED_OUT ; 
  ll = NULLED_OUT ; 
  a = NULLED_OUT ; 
  name = NULLED_OUT ; 
  body = NULLED_OUT ; 
  if (FUNCCALL(SETUP_XfOrM862(_), scheme_stx_proper_list_length (expr ) )< 0 )
    FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , expr , "bad syntax (" "illegal use of `.'" ")" ) ); 
  name = (((Scheme_Type ) (((((long ) (expr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (expr ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (expr ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM862(_), scheme_stx_content (expr ) )) ) -> u . pair_val . car ) ) ; 
  body = (((Scheme_Type ) (((((long ) (expr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (expr ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (expr ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM862(_), scheme_stx_content (expr ) )) ) -> u . pair_val . cdr ) ) ; 
  l = (__funcarg110 = FUNCCALL(SETUP_XfOrM862(_), scheme_flatten_syntax_list (body , ((void * ) 0 ) ) ), FUNCCALL_AGAIN(scheme_copy_list (__funcarg110 ) )) ; 
  for (ll = l ; ! ((ll ) == (scheme_null ) ) ; ll = (((Scheme_Simple_Object * ) (ll ) ) -> u . pair_val . cdr ) ) {
#   define XfOrM864_COUNT (0+XfOrM862_COUNT)
#   define SETUP_XfOrM864(x) SETUP_XfOrM862(x)
    a = (((Scheme_Simple_Object * ) (ll ) ) -> u . pair_val . car ) ; 
    a = FUNCCALL(SETUP_XfOrM864(_), scheme_stx_track (a , expr , name ) ); 
    (((Scheme_Simple_Object * ) (ll ) ) -> u . pair_val . car ) = a ; 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_append (l , append_onto ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_push_continuation_frame (Scheme_Cont_Frame_Data * d ) {
  /* No conversion */
  d -> cont_mark_pos = scheme_current_cont_mark_pos ; 
  d -> cont_mark_stack = scheme_current_cont_mark_stack ; 
  scheme_current_cont_mark_pos += 2 ; 
}
void scheme_pop_continuation_frame (Scheme_Cont_Frame_Data * d ) {
  /* No conversion */
  scheme_current_cont_mark_pos = d -> cont_mark_pos ; 
  scheme_current_cont_mark_stack = d -> cont_mark_stack ; 
}
/* this far 5457 */
static long clone_meta_cont_set_mark (Scheme_Meta_Continuation * mc , Scheme_Object * val , long findpos ) {
  Scheme_Meta_Continuation * naya ; 
  Scheme_Cont_Mark * cp ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(val, 0), PUSH(cp, 1), PUSH(mc, 2), PUSH(naya, 3)));
# define XfOrM867_COUNT (4)
# define SETUP_XfOrM867(x) SETUP(XfOrM867_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  naya = NULLED_OUT ; 
  cp = NULLED_OUT ; 
  naya = ((Scheme_Meta_Continuation * ) FUNCCALL(SETUP_XfOrM867(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Meta_Continuation ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  (memcpy (naya , mc , sizeof (Scheme_Meta_Continuation ) ) ) ; 
  cp = ((Scheme_Cont_Mark * ) FUNCCALL(SETUP_XfOrM867(_), GC_malloc (sizeof (Scheme_Cont_Mark ) * (naya -> cont_mark_total ) ) )) ; 
  (memcpy (cp , mc -> cont_mark_stack_copied , naya -> cont_mark_total * sizeof (Scheme_Cont_Mark ) ) ) ; 
  naya -> cont_mark_stack_copied = cp ; 
  naya -> copy_after_captured = scheme_cont_capture_count ; 
  mc = naya ; 
  scheme_current_thread -> meta_continuation = mc ; 
  mc -> cont_mark_stack_copied [findpos ] . val = val ; 
  mc -> cont_mark_stack_copied [findpos ] . cache = ((void * ) 0 ) ; 
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static long new_segment_set_mark (long segpos , long pos , Scheme_Object * key , Scheme_Object * val ) {
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Cont_Mark * cm = ((void * ) 0 ) ; 
  int c = p -> cont_mark_seg_count ; 
  Scheme_Cont_Mark * * segs , * seg ; 
  long findpos ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(cm, 0), PUSH(val, 1), PUSH(key, 2), PUSH(seg, 3), PUSH(p, 4), PUSH(segs, 5)));
# define XfOrM868_COUNT (6)
# define SETUP_XfOrM868(x) SETUP(XfOrM868_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  segs = NULLED_OUT ; 
  seg = NULLED_OUT ; 
  segs = ((Scheme_Cont_Mark * * ) FUNCCALL(SETUP_XfOrM868(_), GC_malloc (sizeof (Scheme_Cont_Mark * ) * (c + 1 ) ) )) ; 
  seg = FUNCCALL(SETUP_XfOrM868(_), GC_malloc_allow_interior (sizeof (Scheme_Cont_Mark ) * (1 << 8 ) ) ); 
  segs [c ] = seg ; 
  (memcpy (segs , p -> cont_mark_stack_segments , c * sizeof (Scheme_Cont_Mark * ) ) ) ; 
  p -> cont_mark_seg_count ++ ; 
  p -> cont_mark_stack_segments = segs ; 
  seg = p -> cont_mark_stack_segments [segpos ] ; 
  cm = seg + pos ; 
  findpos = scheme_current_cont_mark_stack ; 
  scheme_current_cont_mark_stack ++ ; 
  cm -> key = key ; 
  cm -> val = val ; 
  cm -> pos = scheme_current_cont_mark_pos ; 
  cm -> cache = ((void * ) 0 ) ; 
  RET_VALUE_START (findpos ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
long scheme_set_cont_mark (Scheme_Object * key , Scheme_Object * val ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Cont_Mark * cm = ((void * ) 0 ) ; 
  long findpos , bottom ; 
  findpos = (long ) scheme_current_cont_mark_stack ; 
  bottom = (long ) p -> cont_mark_stack_bottom ; 
  while (1 ) {
    if (findpos -- > bottom ) {
      Scheme_Cont_Mark * seg = p -> cont_mark_stack_segments [findpos >> 8 ] ; 
      long pos = findpos & ((1 << 8 ) - 1 ) ; 
      Scheme_Cont_Mark * find = seg + pos ; 
      if ((long ) find -> pos < (long ) scheme_current_cont_mark_pos ) {
        break ; 
      }
      else {
        if (find -> key == key ) {
          cm = find ; 
          break ; 
        }
        else {
          find -> cache = ((void * ) 0 ) ; 
        }
      }
    }
    else {
      if (scheme_current_cont_mark_pos == p -> cont_mark_pos_bottom + 2 ) {
        if (p -> meta_continuation ) {
          if (key != scheme_stack_dump_key ) {
            Scheme_Meta_Continuation * mc = p -> meta_continuation ; 
            for (findpos = (long ) mc -> cont_mark_total ; findpos -- ; ) {
              if (mc -> cont_mark_stack_copied [findpos ] . pos != mc -> cont_mark_pos )
                break ; 
              if (mc -> cont_mark_stack_copied [findpos ] . key == key ) {
                if (mc -> copy_after_captured < scheme_cont_capture_count ) {
                  return clone_meta_cont_set_mark (mc , val , findpos ) ; 
                }
                mc -> cont_mark_stack_copied [findpos ] . val = val ; 
                mc -> cont_mark_stack_copied [findpos ] . cache = ((void * ) 0 ) ; 
                return 0 ; 
              }
              else {
                mc -> cont_mark_stack_copied [findpos ] . cache = ((void * ) 0 ) ; 
              }
            }
          }
        }
      }
      break ; 
    }
  }
  if (! cm ) {
    long segpos ; 
    long pos ; 
    Scheme_Cont_Mark * seg ; 
    findpos = scheme_current_cont_mark_stack ; 
    segpos = ((long ) findpos ) >> 8 ; 
    pos = ((long ) findpos ) & ((1 << 8 ) - 1 ) ; 
    if (segpos >= p -> cont_mark_seg_count ) {
      return new_segment_set_mark (segpos , pos , key , val ) ; 
    }
    seg = p -> cont_mark_stack_segments [segpos ] ; 
    cm = seg + pos ; 
    scheme_current_cont_mark_stack = findpos + 1 ; 
  }
  cm -> key = key ; 
  cm -> val = val ; 
  cm -> pos = scheme_current_cont_mark_pos ; 
  cm -> cache = ((void * ) 0 ) ; 
  return findpos ; 
}
void scheme_temp_dec_mark_depth () {
  /* No conversion */
  scheme_current_cont_mark_pos -= 2 ; 
}
void scheme_temp_inc_mark_depth () {
  /* No conversion */
  scheme_current_cont_mark_pos += 2 ; 
}
static Scheme_Object * do_apply_known_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * * argv = (Scheme_Object * * ) p -> ku . k . p2 ; 
  p -> ku . k . p2 = ((void * ) 0 ) ; 
  return _scheme_apply_known_prim_closure_multi ((Scheme_Object * ) p -> ku . k . p1 , p -> ku . k . i1 , argv ) ; 
}
Scheme_Object * _scheme_apply_known_prim_closure_multi (Scheme_Object * rator , int argc , Scheme_Object * * argv ) {
  long old_cont_mark_stack ; 
  GC_CAN_IGNORE Scheme_Object * v ; 
  GC_CAN_IGNORE Scheme_Primitive_Closure * prim ; 
  GC_CAN_IGNORE Scheme_Thread * p = scheme_current_thread ; 
  GC_CAN_IGNORE Scheme_Primitive_Closure_Proc * f ; 
  unsigned long _stk_pos ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(rator, 1)));
# define XfOrM911_COUNT (2)
# define SETUP_XfOrM911(x) SETUP(XfOrM911_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  _stk_pos = (unsigned long ) & _stk_pos ; 
  if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
    GC_CAN_IGNORE void * ra ; 
#   define XfOrM913_COUNT (0+XfOrM911_COUNT)
#   define SETUP_XfOrM913(x) SETUP_XfOrM911(x)
    if (argc ) {
      int i ; 
#     define XfOrM914_COUNT (0+XfOrM913_COUNT)
#     define SETUP_XfOrM914(x) SETUP_XfOrM913(x)
      ra = (void * ) ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM914(_), GC_malloc (sizeof (Scheme_Object * ) * (argc ) ) )) ; 
      for (i = argc ; i -- ; ) {
        ((Scheme_Object * * ) ra ) [i ] = argv [i ] ; 
      }
    }
    else ra = ((void * ) 0 ) ; 
    p -> ku . k . p1 = (void * ) rator ; 
    p -> ku . k . i1 = argc ; 
    p -> ku . k . p2 = (void * ) ra ; 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_handle_stack_overflow (do_apply_known_k ) )) RET_VALUE_EMPTY_END ; 
  }
  if ((scheme_fuel_counter ) <= 0 ) {
#   define XfOrM912_COUNT (0+XfOrM911_COUNT)
#   define SETUP_XfOrM912(x) SETUP_XfOrM911(x)
    ; 
    FUNCCALL(SETUP_XfOrM912(_), scheme_thread_block (0 ) ); 
    (p ) -> ran_some = 1 ; 
  }
  ; 
  prim = (Scheme_Primitive_Closure * ) rator ; 
  scheme_current_cont_mark_pos ++ ; 
  old_cont_mark_stack = scheme_current_cont_mark_stack ; 
  f = prim -> p . prim_val ; 
  v = FUNCCALL_EMPTY(f (argc , argv , (Scheme_Object * ) prim ) ); 
  v = ((v == ((Scheme_Object * ) 0x4 ) ) ? FUNCCALL_EMPTY(scheme_force_value (v ) ): v ) ; 
  -- scheme_current_cont_mark_pos ; 
  scheme_current_cont_mark_stack = old_cont_mark_stack ; 
  ; 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * _scheme_apply_prim_closure_multi (Scheme_Object * rator , int argc , Scheme_Object * * argv ) {
  long old_cont_mark_stack ; 
  GC_CAN_IGNORE Scheme_Object * v ; 
  GC_CAN_IGNORE Scheme_Primitive_Closure * prim ; 
  GC_CAN_IGNORE Scheme_Thread * p = scheme_current_thread ; 
  GC_CAN_IGNORE Scheme_Primitive_Closure_Proc * f ; 
  unsigned long _stk_pos ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(rator, 1)));
# define XfOrM917_COUNT (2)
# define SETUP_XfOrM917(x) SETUP(XfOrM917_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  _stk_pos = (unsigned long ) & _stk_pos ; 
  if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
    GC_CAN_IGNORE void * ra ; 
#   define XfOrM920_COUNT (0+XfOrM917_COUNT)
#   define SETUP_XfOrM920(x) SETUP_XfOrM917(x)
    if (argc ) {
      int i ; 
#     define XfOrM921_COUNT (0+XfOrM920_COUNT)
#     define SETUP_XfOrM921(x) SETUP_XfOrM920(x)
      ra = (void * ) ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM921(_), GC_malloc (sizeof (Scheme_Object * ) * (argc ) ) )) ; 
      for (i = argc ; i -- ; ) {
        ((Scheme_Object * * ) ra ) [i ] = argv [i ] ; 
      }
    }
    else ra = ((void * ) 0 ) ; 
    p -> ku . k . p1 = (void * ) rator ; 
    p -> ku . k . i1 = argc ; 
    p -> ku . k . p2 = (void * ) ra ; 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_handle_stack_overflow (do_apply_known_k ) )) RET_VALUE_EMPTY_END ; 
  }
  if ((scheme_fuel_counter ) <= 0 ) {
#   define XfOrM919_COUNT (0+XfOrM917_COUNT)
#   define SETUP_XfOrM919(x) SETUP_XfOrM917(x)
    ; 
    FUNCCALL(SETUP_XfOrM919(_), scheme_thread_block (0 ) ); 
    (p ) -> ran_some = 1 ; 
  }
  ; 
  prim = (Scheme_Primitive_Closure * ) rator ; 
  if (argc < prim -> p . mina || (argc > prim -> p . mu . maxa && prim -> p . mina >= 0 ) ) {
#   define XfOrM918_COUNT (0+XfOrM917_COUNT)
#   define SETUP_XfOrM918(x) SETUP_XfOrM917(x)
    FUNCCALL_EMPTY(scheme_wrong_count (prim -> p . name , prim -> p . mina , prim -> p . mu . maxa , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  scheme_current_cont_mark_pos ++ ; 
  old_cont_mark_stack = scheme_current_cont_mark_stack ; 
  f = prim -> p . prim_val ; 
  v = FUNCCALL_EMPTY(f (argc , argv , (Scheme_Object * ) prim ) ); 
  v = ((v == ((Scheme_Object * ) 0x4 ) ) ? FUNCCALL_EMPTY(scheme_force_value (v ) ): v ) ; 
  -- scheme_current_cont_mark_pos ; 
  scheme_current_cont_mark_stack = old_cont_mark_stack ; 
  ; 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * _scheme_apply_known_prim_closure (Scheme_Object * rator , int argc , Scheme_Object * * argv ) {
  long old_cont_mark_stack ; 
  GC_CAN_IGNORE Scheme_Object * v ; 
  GC_CAN_IGNORE Scheme_Primitive_Closure * prim ; 
  GC_CAN_IGNORE Scheme_Thread * p = scheme_current_thread ; 
  GC_CAN_IGNORE Scheme_Primitive_Closure_Proc * f ; 
  unsigned long _stk_pos ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(rator, 1)));
# define XfOrM924_COUNT (2)
# define SETUP_XfOrM924(x) SETUP(XfOrM924_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  _stk_pos = (unsigned long ) & _stk_pos ; 
  if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
    GC_CAN_IGNORE void * ra ; 
#   define XfOrM927_COUNT (0+XfOrM924_COUNT)
#   define SETUP_XfOrM927(x) SETUP_XfOrM924(x)
    if (argc ) {
      int i ; 
#     define XfOrM928_COUNT (0+XfOrM927_COUNT)
#     define SETUP_XfOrM928(x) SETUP_XfOrM927(x)
      ra = (void * ) ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM928(_), GC_malloc (sizeof (Scheme_Object * ) * (argc ) ) )) ; 
      for (i = argc ; i -- ; ) {
        ((Scheme_Object * * ) ra ) [i ] = argv [i ] ; 
      }
    }
    else ra = ((void * ) 0 ) ; 
    p -> ku . k . p1 = (void * ) rator ; 
    p -> ku . k . i1 = argc ; 
    p -> ku . k . p2 = (void * ) ra ; 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_handle_stack_overflow (do_apply_known_k ) )) RET_VALUE_EMPTY_END ; 
  }
  if ((scheme_fuel_counter ) <= 0 ) {
#   define XfOrM926_COUNT (0+XfOrM924_COUNT)
#   define SETUP_XfOrM926(x) SETUP_XfOrM924(x)
    ; 
    FUNCCALL(SETUP_XfOrM926(_), scheme_thread_block (0 ) ); 
    (p ) -> ran_some = 1 ; 
  }
  ; 
  prim = (Scheme_Primitive_Closure * ) rator ; 
  scheme_current_cont_mark_pos ++ ; 
  old_cont_mark_stack = scheme_current_cont_mark_stack ; 
  f = prim -> p . prim_val ; 
  v = FUNCCALL_EMPTY(f (argc , argv , (Scheme_Object * ) prim ) ); 
  v = ((v == ((Scheme_Object * ) 0x4 ) ) ? FUNCCALL_EMPTY(scheme_force_value (v ) ): v ) ; 
  if (v == ((Scheme_Object * ) 0x6 ) ) {
#   define XfOrM925_COUNT (0+XfOrM924_COUNT)
#   define SETUP_XfOrM925(x) SETUP_XfOrM924(x)
    FUNCCALL_EMPTY(scheme_wrong_return_arity (((void * ) 0 ) , 1 , (scheme_current_thread -> ku . multiple . count ) , (scheme_current_thread -> ku . multiple . array ) , ((void * ) 0 ) ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  -- scheme_current_cont_mark_pos ; 
  scheme_current_cont_mark_stack = old_cont_mark_stack ; 
  ; 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * _scheme_apply_prim_closure (Scheme_Object * rator , int argc , Scheme_Object * * argv ) {
  long old_cont_mark_stack ; 
  GC_CAN_IGNORE Scheme_Object * v ; 
  GC_CAN_IGNORE Scheme_Primitive_Closure * prim ; 
  GC_CAN_IGNORE Scheme_Thread * p = scheme_current_thread ; 
  GC_CAN_IGNORE Scheme_Primitive_Closure_Proc * f ; 
  unsigned long _stk_pos ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(rator, 1)));
# define XfOrM931_COUNT (2)
# define SETUP_XfOrM931(x) SETUP(XfOrM931_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  _stk_pos = (unsigned long ) & _stk_pos ; 
  if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
    GC_CAN_IGNORE void * ra ; 
#   define XfOrM935_COUNT (0+XfOrM931_COUNT)
#   define SETUP_XfOrM935(x) SETUP_XfOrM931(x)
    if (argc ) {
      int i ; 
#     define XfOrM936_COUNT (0+XfOrM935_COUNT)
#     define SETUP_XfOrM936(x) SETUP_XfOrM935(x)
      ra = (void * ) ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM936(_), GC_malloc (sizeof (Scheme_Object * ) * (argc ) ) )) ; 
      for (i = argc ; i -- ; ) {
        ((Scheme_Object * * ) ra ) [i ] = argv [i ] ; 
      }
    }
    else ra = ((void * ) 0 ) ; 
    p -> ku . k . p1 = (void * ) rator ; 
    p -> ku . k . i1 = argc ; 
    p -> ku . k . p2 = (void * ) ra ; 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_handle_stack_overflow (do_apply_known_k ) )) RET_VALUE_EMPTY_END ; 
  }
  if ((scheme_fuel_counter ) <= 0 ) {
#   define XfOrM934_COUNT (0+XfOrM931_COUNT)
#   define SETUP_XfOrM934(x) SETUP_XfOrM931(x)
    ; 
    FUNCCALL(SETUP_XfOrM934(_), scheme_thread_block (0 ) ); 
    (p ) -> ran_some = 1 ; 
  }
  ; 
  prim = (Scheme_Primitive_Closure * ) rator ; 
  if (argc < prim -> p . mina || (argc > prim -> p . mu . maxa && prim -> p . mina >= 0 ) ) {
#   define XfOrM933_COUNT (0+XfOrM931_COUNT)
#   define SETUP_XfOrM933(x) SETUP_XfOrM931(x)
    FUNCCALL_EMPTY(scheme_wrong_count (prim -> p . name , prim -> p . mina , prim -> p . mu . maxa , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  scheme_current_cont_mark_pos ++ ; 
  old_cont_mark_stack = scheme_current_cont_mark_stack ; 
  f = prim -> p . prim_val ; 
  v = FUNCCALL_EMPTY(f (argc , argv , (Scheme_Object * ) prim ) ); 
  v = ((v == ((Scheme_Object * ) 0x4 ) ) ? FUNCCALL_EMPTY(scheme_force_value (v ) ): v ) ; 
  if (v == ((Scheme_Object * ) 0x6 ) ) {
#   define XfOrM932_COUNT (0+XfOrM931_COUNT)
#   define SETUP_XfOrM932(x) SETUP_XfOrM931(x)
    FUNCCALL_EMPTY(scheme_wrong_return_arity (((void * ) 0 ) , 1 , (scheme_current_thread -> ku . multiple . count ) , (scheme_current_thread -> ku . multiple . array ) , ((void * ) 0 ) ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  -- scheme_current_cont_mark_pos ; 
  scheme_current_cont_mark_stack = old_cont_mark_stack ; 
  ; 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * _scheme_apply_from_native_fast (Scheme_Object * rator , int argc , Scheme_Object * * argv ) {
  /* No conversion */
  GC_CAN_IGNORE Scheme_Object * v ; 
  GC_CAN_IGNORE Scheme_Primitive_Proc * prim ; 
  GC_CAN_IGNORE Scheme_Primitive_Closure_Proc * f ; 
  prim = (Scheme_Primitive_Proc * ) rator ; 
  if (argc < prim -> mina || (argc > prim -> mu . maxa && prim -> mina >= 0 ) ) {
    scheme_wrong_count (prim -> name , prim -> mina , prim -> mu . maxa , argc , argv ) ; 
    return ((void * ) 0 ) ; 
  }
  f = (Scheme_Primitive_Closure_Proc * ) prim -> prim_val ; 
  v = f (argc , argv , (Scheme_Object * ) prim ) ; 
  if (v == ((Scheme_Object * ) 0x4 ) )
    v = scheme_force_value_same_mark (v ) ; 
  if (v == ((Scheme_Object * ) 0x6 ) ) {
    scheme_wrong_return_arity (((void * ) 0 ) , 1 , (scheme_current_thread -> ku . multiple . count ) , (scheme_current_thread -> ku . multiple . array ) , ((void * ) 0 ) ) ; 
    return ((void * ) 0 ) ; 
  }
  return v ; 
}
Scheme_Object * _scheme_apply_from_native (Scheme_Object * rator , int argc , Scheme_Object * * argv ) {
  /* No conversion */
  if (! (((long ) (rator ) ) & 0x1 ) ) {
    Scheme_Type t ; 
    t = ((rator ) -> type ) ; 
    if (t == scheme_prim_type ) {
      return _scheme_apply_from_native_fast (rator , argc , argv ) ; 
    }
  }
  {
    GC_CAN_IGNORE Scheme_Object * v ; 
    scheme_current_cont_mark_pos -= 2 ; 
    v = scheme_do_eval (rator , argc , argv , 1 ) ; 
    scheme_current_cont_mark_pos += 2 ; 
    return v ; 
  }
}
static inline Scheme_Object * _scheme_apply_multi_from_native_fast (Scheme_Object * rator , int argc , Scheme_Object * * argv ) {
  /* No conversion */
  GC_CAN_IGNORE Scheme_Object * v ; 
  GC_CAN_IGNORE Scheme_Primitive_Proc * prim ; 
  GC_CAN_IGNORE Scheme_Primitive_Closure_Proc * f ; 
  prim = (Scheme_Primitive_Proc * ) rator ; 
  if (argc < prim -> mina || (argc > prim -> mu . maxa && prim -> mina >= 0 ) ) {
    scheme_wrong_count (prim -> name , prim -> mina , prim -> mu . maxa , argc , argv ) ; 
    return ((void * ) 0 ) ; 
  }
  f = (Scheme_Primitive_Closure_Proc * ) prim -> prim_val ; 
  v = f (argc , argv , (Scheme_Object * ) prim ) ; 
  if (v == ((Scheme_Object * ) 0x4 ) )
    v = scheme_force_value_same_mark (v ) ; 
  return v ; 
}
Scheme_Object * _scheme_apply_multi_from_native (Scheme_Object * rator , int argc , Scheme_Object * * argv ) {
  /* No conversion */
  if (! (((long ) (rator ) ) & 0x1 ) ) {
    Scheme_Type t ; 
    t = ((rator ) -> type ) ; 
    if (t == scheme_prim_type ) {
      return _scheme_apply_multi_from_native_fast (rator , argc , argv ) ; 
    }
  }
  {
    GC_CAN_IGNORE Scheme_Object * v ; 
    scheme_current_cont_mark_pos -= 2 ; 
    v = scheme_do_eval (rator , argc , argv , - 1 ) ; 
    scheme_current_cont_mark_pos += 2 ; 
    return v ; 
  }
}
static inline Scheme_Object * _scheme_tail_apply_from_native_fast (Scheme_Object * rator , int argc , Scheme_Object * * argv ) {
  /* No conversion */
  GC_CAN_IGNORE Scheme_Object * v ; 
  GC_CAN_IGNORE Scheme_Primitive_Proc * prim ; 
  GC_CAN_IGNORE Scheme_Primitive_Closure_Proc * f ; 
  prim = (Scheme_Primitive_Proc * ) rator ; 
  if (argc < prim -> mina || (argc > prim -> mu . maxa && prim -> mina >= 0 ) ) {
    scheme_wrong_count (prim -> name , prim -> mina , prim -> mu . maxa , argc , argv ) ; 
    return ((void * ) 0 ) ; 
  }
  f = (Scheme_Primitive_Closure_Proc * ) prim -> prim_val ; 
  v = f (argc , argv , (Scheme_Object * ) prim ) ; 
  return v ; 
}
Scheme_Object * _scheme_tail_apply_from_native (Scheme_Object * rator , int argc , Scheme_Object * * argv ) {
  /* No conversion */
  if (! (((long ) (rator ) ) & 0x1 ) ) {
    Scheme_Type t ; 
    t = ((rator ) -> type ) ; 
    if (t == scheme_prim_type ) {
      return _scheme_tail_apply_from_native_fast (rator , argc , argv ) ; 
    }
  }
  return scheme_tail_apply (rator , argc , argv ) ; 
}
Scheme_Object * scheme_check_one_value (Scheme_Object * v ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(v, 0)));
# define XfOrM957_COUNT (1)
# define SETUP_XfOrM957(x) SETUP(XfOrM957_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (v == ((Scheme_Object * ) 0x6 ) )
    FUNCCALL(SETUP_XfOrM957(_), scheme_wrong_return_arity (((void * ) 0 ) , 1 , (scheme_current_thread -> ku . multiple . count ) , (scheme_current_thread -> ku . multiple . array ) , ((void * ) 0 ) ) ); 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_eval_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * obj = (Scheme_Object * ) p -> ku . k . p1 ; 
  Scheme_Object * * argv = (Scheme_Object * * ) p -> ku . k . p2 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  p -> ku . k . p2 = ((void * ) 0 ) ; 
  return scheme_do_eval (obj , p -> ku . k . i1 , argv , p -> ku . k . i2 ) ; 
}
static void unbound_global (Scheme_Object * obj ) {
  /* No conversion */
  Scheme_Object * tmp ; 
  tmp = scheme_current_runstack [(((Scheme_Toplevel * ) (obj ) ) -> depth ) ] ; 
  tmp = ((Scheme_Object * * ) tmp ) [(((Scheme_Toplevel * ) (obj ) ) -> position ) ] ; 
  scheme_unbound_global ((Scheme_Bucket * ) tmp ) ; 
}
static void make_tail_buffer_safe () {
  Scheme_Thread * p = scheme_current_thread ; 
  GC_CAN_IGNORE Scheme_Object * * tb ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(p, 0)));
# define XfOrM960_COUNT (1)
# define SETUP_XfOrM960(x) SETUP(XfOrM960_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  p -> tail_buffer = ((void * ) 0 ) ; 
  tb = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM960(_), GC_malloc (sizeof (Scheme_Object * ) * (p -> tail_buffer_size ) ) )) ; 
  p -> tail_buffer = tb ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Dynamic_Wind * intersect_dw (Scheme_Dynamic_Wind * a , Scheme_Dynamic_Wind * b , Scheme_Object * prompt_tag , int b_has_tag , int * _common_depth ) {
  /* No conversion */
  int alen = 0 , blen = 0 ; 
  int a_has_tag = 0 , a_prompt_delta = 0 , b_prompt_delta = 0 ; 
  Scheme_Dynamic_Wind * dw ; 
  for (dw = a ; dw && (dw -> prompt_tag != prompt_tag ) ; dw = dw -> prev ) {
  }
  if (dw ) {
    a_prompt_delta = dw -> depth ; 
    a_has_tag = 1 ; 
  }
  if (a_has_tag )
    a_prompt_delta += 1 ; 
  if (b_has_tag )
    b_prompt_delta += 1 ; 
  alen = (a ? a -> depth + 1 : 0 ) - a_prompt_delta ; 
  blen = (b ? b -> depth + 1 : 0 ) - b_prompt_delta ; 
  while (alen > blen ) {
    -- alen ; 
    a = a -> prev ; 
  }
  if (! alen ) {
    * _common_depth = b_prompt_delta - 1 ; 
    return a ; 
  }
  while (blen > alen ) {
    -- blen ; 
    b = b -> prev ; 
  }
  while (blen ) {
    if (((a -> id ? a -> id : (Scheme_Object * ) a ) == (b -> id ? b -> id : (Scheme_Object * ) b ) ) )
      break ; 
    a = a -> prev ; 
    b = b -> prev ; 
    blen -- ; 
  }
  * _common_depth = (b ? b -> depth : - 1 ) ; 
  return a ; 
}
static Scheme_Prompt * lookup_cont_prompt (Scheme_Cont * c , Scheme_Meta_Continuation * * _prompt_mc , long * _prompt_pos , const char * msg ) {
  Scheme_Prompt * prompt ; 
  DECL_RET_SAVE (Scheme_Prompt * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(msg, 0), PUSH(c, 1), PUSH(prompt, 2)));
# define XfOrM972_COUNT (3)
# define SETUP_XfOrM972(x) SETUP(XfOrM972_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  prompt = NULLED_OUT ; 
  prompt = (Scheme_Prompt * ) FUNCCALL(SETUP_XfOrM972(_), scheme_extract_one_cc_mark_with_meta (((void * ) 0 ) , (((Scheme_Small_Object * ) (c -> prompt_tag ) ) -> u . ptr_val ) , ((void * ) 0 ) , _prompt_mc , _prompt_pos ) ); 
  if (! prompt && ! ((scheme_default_prompt_tag ) == (c -> prompt_tag ) ) ) {
#   define XfOrM973_COUNT (0+XfOrM972_COUNT)
#   define SETUP_XfOrM973(x) SETUP_XfOrM972(x)
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT_CONTINUATION , msg ) ); 
  }
  RET_VALUE_START (prompt ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Prompt * check_barrier (Scheme_Prompt * prompt , Scheme_Meta_Continuation * prompt_cont , long prompt_pos , Scheme_Cont * c ) {
  Scheme_Prompt * barrier_prompt , * b1 , * b2 ; 
  Scheme_Meta_Continuation * barrier_cont ; 
  long barrier_pos ; 
  DECL_RET_SAVE (Scheme_Prompt * ) PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSH(b2, 0), PUSH(prompt, 1), PUSH(prompt_cont, 2), PUSH(barrier_prompt, 3), PUSH(c, 4), PUSH(b1, 5), PUSH(barrier_cont, 6)));
# define XfOrM974_COUNT (7)
# define SETUP_XfOrM974(x) SETUP(XfOrM974_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  barrier_prompt = NULLED_OUT ; 
  b1 = NULLED_OUT ; 
  b2 = NULLED_OUT ; 
  barrier_cont = NULLED_OUT ; 
  barrier_prompt = FUNCCALL(SETUP_XfOrM974(_), scheme_get_barrier_prompt (& barrier_cont , & barrier_pos ) ); 
  b1 = barrier_prompt ; 
  if (b1 ) {
#   define XfOrM977_COUNT (0+XfOrM974_COUNT)
#   define SETUP_XfOrM977(x) SETUP_XfOrM974(x)
    if (! b1 -> is_barrier )
      b1 = ((void * ) 0 ) ; 
    else if (prompt && FUNCCALL(SETUP_XfOrM977(_), scheme_is_cm_deeper (barrier_cont , barrier_pos , prompt_cont , prompt_pos ) ))
      b1 = ((void * ) 0 ) ; 
  }
  b2 = c -> barrier_prompt ; 
  if (b2 ) {
    if (! b2 -> is_barrier )
      b2 = ((void * ) 0 ) ; 
  }
  if (b1 != b2 ) {
#   define XfOrM975_COUNT (0+XfOrM974_COUNT)
#   define SETUP_XfOrM975(x) SETUP_XfOrM974(x)
    FUNCCALL(SETUP_XfOrM975(_), scheme_raise_exn (MZEXN_FAIL_CONTRACT_CONTINUATION , "continuation application: attempt to cross a continuation barrier" ) ); 
  }
  RET_VALUE_START (barrier_prompt ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_recheck_prompt_and_barrier (Scheme_Cont * c ) {
  Scheme_Prompt * prompt ; 
  Scheme_Meta_Continuation * prompt_cont ; 
  long prompt_pos ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(c, 0), PUSH(prompt, 1), PUSH(prompt_cont, 2)));
# define XfOrM978_COUNT (3)
# define SETUP_XfOrM978(x) SETUP(XfOrM978_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  prompt = NULLED_OUT ; 
  prompt_cont = NULLED_OUT ; 
  prompt = FUNCCALL(SETUP_XfOrM978(_), lookup_cont_prompt (c , & prompt_cont , & prompt_pos , "continuation application: no corresponding prompt in the current continuation" " on return from `dynamic-wind' post thunk" ) ); 
  FUNCCALL_AGAIN(check_barrier (prompt , prompt_cont , prompt_pos , c ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int exec_dyn_wind_posts (Scheme_Dynamic_Wind * common , Scheme_Cont * c , int common_depth , Scheme_Dynamic_Wind * * _common ) {
  int meta_depth ; 
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Dynamic_Wind * dw ; 
  int old_cac = scheme_continuation_application_count ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(_common, 0), PUSH(dw, 1), PUSH(c, 2), PUSH(common, 3), PUSH(p, 4)));
# define XfOrM979_COUNT (5)
# define SETUP_XfOrM979(x) SETUP(XfOrM979_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  dw = NULLED_OUT ; 
  * _common = common ; 
  for (dw = p -> dw ; (common ? dw -> depth != common -> depth : dw != common ) ; ) {
#   define XfOrM986_COUNT (0+XfOrM979_COUNT)
#   define SETUP_XfOrM986(x) SETUP_XfOrM979(x)
    meta_depth = p -> next_meta ; 
    p -> next_meta += dw -> next_meta ; 
    p -> dw = dw -> prev ; 
    if (dw -> post ) {
#     define XfOrM987_COUNT (0+XfOrM986_COUNT)
#     define SETUP_XfOrM987(x) SETUP_XfOrM986(x)
      if (meta_depth > 0 ) {
#       define XfOrM991_COUNT (0+XfOrM987_COUNT)
#       define SETUP_XfOrM991(x) SETUP_XfOrM987(x)
        FUNCCALL(SETUP_XfOrM991(_), scheme_apply_dw_in_meta (dw , 1 , meta_depth , c ) ); 
      }
      else {
        DW_PrePost_Proc post = dw -> post ; 
#       define XfOrM989_COUNT (0+XfOrM987_COUNT)
#       define SETUP_XfOrM989(x) SETUP_XfOrM987(x)
        scheme_current_cont_mark_pos = dw -> envss . cont_mark_pos ; 
        scheme_current_cont_mark_stack = dw -> envss . cont_mark_stack ; 
        FUNCCALL(SETUP_XfOrM989(_), post (dw -> data ) ); 
        if (scheme_continuation_application_count != old_cac ) {
#         define XfOrM990_COUNT (0+XfOrM989_COUNT)
#         define SETUP_XfOrM990(x) SETUP_XfOrM989(x)
          FUNCCALL(SETUP_XfOrM990(_), scheme_recheck_prompt_and_barrier (c ) ); 
        }
      }
      p = scheme_current_thread ; 
      dw = p -> dw ; 
      if (scheme_continuation_application_count != old_cac ) {
#       define XfOrM988_COUNT (0+XfOrM987_COUNT)
#       define SETUP_XfOrM988(x) SETUP_XfOrM987(x)
        old_cac = scheme_continuation_application_count ; 
        common = FUNCCALL(SETUP_XfOrM988(_), intersect_dw (p -> dw , c -> dw , c -> prompt_tag , c -> has_prompt_dw , & common_depth ) ); 
        * _common = common ; 
      }
    }
    else dw = dw -> prev ; 
  }
  RET_VALUE_START (common_depth ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_jump_to_continuation (Scheme_Object * obj , int num_rands , Scheme_Object * * rands , Scheme_Object * * old_runstack ) {
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Cont * c ; 
  Scheme_Dynamic_Wind * common , * new_common ; 
  Scheme_Object * value ; 
  Scheme_Meta_Continuation * prompt_mc ; 
  long prompt_pos ; 
  Scheme_Prompt * prompt , * barrier_prompt ; 
  int common_depth ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(12);
  BLOCK_SETUP_TOP((PUSH(common, 0), PUSH(old_runstack, 1), PUSH(rands, 2), PUSH(c, 3), PUSH(barrier_prompt, 4), PUSH(prompt_mc, 5), PUSH(obj, 6), PUSH(prompt, 7), PUSH(new_common, 8), PUSH(p, 9), PUSH(value, 10)));
# define XfOrM992_COUNT (11)
# define SETUP_XfOrM992(x) SETUP(XfOrM992_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  c = NULLED_OUT ; 
  common = NULLED_OUT ; 
  new_common = NULLED_OUT ; 
  value = NULLED_OUT ; 
  prompt_mc = NULLED_OUT ; 
  prompt = NULLED_OUT ; 
  barrier_prompt = NULLED_OUT ; 
  if (num_rands != 1 ) {
    GC_CAN_IGNORE Scheme_Object * * vals ; 
    int i ; 
#   define XfOrM1016_COUNT (0+XfOrM992_COUNT)
#   define SETUP_XfOrM1016(x) SETUP_XfOrM992(x)
    if (rands == p -> tail_buffer )
      FUNCCALL(SETUP_XfOrM1016(_), make_tail_buffer_safe () ); 
    vals = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM1016(_), GC_malloc (sizeof (Scheme_Object * ) * (num_rands ) ) )) ; 
    for (i = num_rands ; i -- ; ) {
      vals [i ] = rands [i ] ; 
    }
    value = (Scheme_Object * ) vals ; 
  }
  else value = rands [0 ] ; 
  c = (Scheme_Cont * ) obj ; 
  if ((scheme_fuel_counter ) <= 0 ) {
#   define XfOrM1015_COUNT (0+XfOrM992_COUNT)
#   define SETUP_XfOrM1015(x) SETUP_XfOrM992(x)
    ; 
    FUNCCALL(SETUP_XfOrM1015(_), scheme_thread_block (0 ) ); 
    (p ) -> ran_some = 1 ; 
  }
  ; 
  if (! c -> runstack_copied ) {
    c = c -> buf . cont ; 
  }
  if (c -> composable ) {
    scheme_continuation_application_count ++ ; 
#   define XfOrM1013_COUNT (0+XfOrM992_COUNT)
#   define SETUP_XfOrM1013(x) SETUP_XfOrM992(x)
    scheme_current_runstack = old_runstack ; 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM1013(_), scheme_compose_continuation (c , num_rands , value ) )) RET_VALUE_END ; 
  }
  else {
    int orig_cac = scheme_continuation_application_count ; 
#   define XfOrM993_COUNT (0+XfOrM992_COUNT)
#   define SETUP_XfOrM993(x) SETUP_XfOrM992(x)
    FUNCCALL(SETUP_XfOrM993(_), scheme_about_to_move_C_stack () ); 
    prompt = FUNCCALL(SETUP_XfOrM993(_), lookup_cont_prompt (c , & prompt_mc , & prompt_pos , "continuation application: no corresponding prompt in the current continuation" ) ); 
    barrier_prompt = FUNCCALL_AGAIN(check_barrier (prompt , prompt_mc , prompt_pos , c ) ); 
    p -> suspend_break ++ ; 
    common = FUNCCALL(SETUP_XfOrM993(_), intersect_dw (p -> dw , c -> dw , c -> prompt_tag , c -> has_prompt_dw , & common_depth ) ); 
    common_depth = FUNCCALL_AGAIN(exec_dyn_wind_posts (common , c , common_depth , & new_common ) ); 
    p = scheme_current_thread ; 
    if (orig_cac != scheme_continuation_application_count ) {
#     define XfOrM1012_COUNT (0+XfOrM993_COUNT)
#     define SETUP_XfOrM1012(x) SETUP_XfOrM993(x)
      prompt = FUNCCALL(SETUP_XfOrM1012(_), lookup_cont_prompt (c , & prompt_mc , & prompt_pos , "shouldn't fail!" ) ); 
      barrier_prompt = FUNCCALL(SETUP_XfOrM1012(_), scheme_get_barrier_prompt (((void * ) 0 ) , ((void * ) 0 ) ) ); 
      common = new_common ; 
    }
    c -> common_dw_depth = common_depth ; 
    if (num_rands == 1 )
      c -> value = value ; 
    else {
      GC_CAN_IGNORE Scheme_Object * vals ; 
#     define XfOrM1011_COUNT (0+XfOrM993_COUNT)
#     define SETUP_XfOrM1011(x) SETUP_XfOrM993(x)
      vals = FUNCCALL(SETUP_XfOrM1011(_), scheme_values (num_rands , (Scheme_Object * * ) value ) ); 
      c -> value = vals ; 
    }
    c -> common_dw = common ; 
    c -> common_next_meta = p -> next_meta ; 
    scheme_continuation_application_count ++ ; 
    if (! prompt ) {
#     define XfOrM1008_COUNT (0+XfOrM993_COUNT)
#     define SETUP_XfOrM1008(x) SETUP_XfOrM993(x)
      p -> meta_continuation = ((void * ) 0 ) ; 
      p -> meta_prompt = ((void * ) 0 ) ; 
      if ((c -> barrier_prompt == barrier_prompt ) && barrier_prompt ) {
        c -> resume_to = ((void * ) 0 ) ; 
        p -> stack_start = c -> stack_start ; 
      }
      else {
        Scheme_Overflow * oflow ; 
        BLOCK_SETUP((PUSH(oflow, 0+XfOrM1008_COUNT)));
#       define XfOrM1009_COUNT (1+XfOrM1008_COUNT)
#       define SETUP_XfOrM1009(x) SETUP(XfOrM1009_COUNT)
        oflow = NULLED_OUT ; 
        oflow = FUNCCALL(SETUP_XfOrM1009(_), scheme_get_thread_end_overflow () ); 
        c -> resume_to = oflow ; 
        p -> stack_start = c -> prompt_stack_start ; 
      }
      FUNCCALL(SETUP_XfOrM1008(_), scheme_longjmpup (& c -> buf ) ); 
    }
    else if (prompt -> id && (prompt -> id == c -> prompt_id ) && ! prompt_mc ) {
#     define XfOrM1003_COUNT (0+XfOrM993_COUNT)
#     define SETUP_XfOrM1003(x) SETUP_XfOrM993(x)
      FUNCCALL(SETUP_XfOrM1003(_), scheme_drop_prompt_meta_continuations (c -> prompt_tag ) ); 
      c -> shortcut_prompt = prompt ; 
      if ((! prompt -> boundary_overflow_id && ! p -> overflow ) || (prompt -> boundary_overflow_id && (prompt -> boundary_overflow_id == p -> overflow -> id ) ) ) {
#       define XfOrM1007_COUNT (0+XfOrM1003_COUNT)
#       define SETUP_XfOrM1007(x) SETUP_XfOrM1003(x)
        FUNCCALL(SETUP_XfOrM1007(_), scheme_longjmpup (& c -> buf ) ); 
      }
      else {
        Scheme_Overflow * overflow ; 
        BLOCK_SETUP((PUSH(overflow, 0+XfOrM1003_COUNT)));
#       define XfOrM1004_COUNT (1+XfOrM1003_COUNT)
#       define SETUP_XfOrM1004(x) SETUP(XfOrM1004_COUNT)
        overflow = NULLED_OUT ; 
        overflow = p -> overflow ; 
        while (overflow -> prev && (! overflow -> prev -> id || (overflow -> prev -> id != prompt -> boundary_overflow_id ) ) ) {
          overflow = overflow -> prev ; 
        }
        p -> cjs . jumping_to_continuation = (Scheme_Object * ) c ; 
        p -> overflow = overflow ; 
        p -> stack_start = overflow -> stack_start ; 
        FUNCCALL(SETUP_XfOrM1004(_), scheme_longjmpup (& overflow -> jmp -> cont ) ); 
      }
    }
    else {
#     define XfOrM994_COUNT (0+XfOrM993_COUNT)
#     define SETUP_XfOrM994(x) SETUP_XfOrM993(x)
      p -> cjs . jumping_to_continuation = (Scheme_Object * ) prompt ; 
      p -> cjs . num_vals = 1 ; 
      p -> cjs . val = (Scheme_Object * ) c ; 
      p -> cjs . is_escape = 1 ; 
      if (prompt_mc ) {
#       define XfOrM999_COUNT (0+XfOrM994_COUNT)
#       define SETUP_XfOrM999(x) SETUP_XfOrM994(x)
        {
          Scheme_Meta_Continuation * xmc ; 
          int offset = 1 ; 
          xmc = NULLED_OUT ; 
          for (xmc = p -> meta_continuation ; xmc -> prompt_tag != prompt_mc -> prompt_tag ; xmc = xmc -> next ) {
            if (xmc -> overflow )
              offset ++ ; 
          }
          c -> common_next_meta -= offset ; 
        }
        p -> meta_continuation = prompt_mc -> next ; 
        p -> stack_start = prompt_mc -> overflow -> stack_start ; 
        FUNCCALL(SETUP_XfOrM999(_), scheme_longjmpup (& prompt_mc -> overflow -> jmp -> cont ) ); 
      }
      else if ((! prompt -> boundary_overflow_id && ! p -> overflow ) || (prompt -> boundary_overflow_id && (prompt -> boundary_overflow_id == p -> overflow -> id ) ) ) {
#       define XfOrM998_COUNT (0+XfOrM994_COUNT)
#       define SETUP_XfOrM998(x) SETUP_XfOrM994(x)
        FUNCCALL(SETUP_XfOrM998(_), scheme_drop_prompt_meta_continuations (c -> prompt_tag ) ); 
        (((long * ) (void * ) ((* prompt -> prompt_buf ) . gcvs ) ) [1 ] = (* prompt -> prompt_buf ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* prompt -> prompt_buf ) . gcvs , scheme_jit_longjmp ((* prompt -> prompt_buf ) . jb , 1 ) ) ; 
      }
      else {
        Scheme_Overflow * overflow ; 
        BLOCK_SETUP((PUSH(overflow, 0+XfOrM994_COUNT)));
#       define XfOrM995_COUNT (1+XfOrM994_COUNT)
#       define SETUP_XfOrM995(x) SETUP(XfOrM995_COUNT)
        overflow = NULLED_OUT ; 
        FUNCCALL(SETUP_XfOrM995(_), scheme_drop_prompt_meta_continuations (c -> prompt_tag ) ); 
        overflow = p -> overflow ; 
        while (overflow -> prev && (! overflow -> prev -> id || (overflow -> prev -> id != prompt -> boundary_overflow_id ) ) ) {
          overflow = overflow -> prev ; 
        }
        p -> overflow = overflow ; 
        p -> stack_start = overflow -> stack_start ; 
        FUNCCALL(SETUP_XfOrM995(_), scheme_longjmpup (& overflow -> jmp -> cont ) ); 
      }
    }
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_escape_to_continuation (Scheme_Object * obj , int num_rands , Scheme_Object * * rands ) {
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * value ; 
  PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(obj, 0), PUSH(p, 1), PUSH(value, 2), PUSH(rands, 3)));
# define XfOrM1019_COUNT (4)
# define SETUP_XfOrM1019(x) SETUP(XfOrM1019_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  value = NULLED_OUT ; 
  if (num_rands != 1 ) {
    GC_CAN_IGNORE Scheme_Object * * vals ; 
    int i ; 
#   define XfOrM1022_COUNT (0+XfOrM1019_COUNT)
#   define SETUP_XfOrM1022(x) SETUP_XfOrM1019(x)
    if (rands == p -> tail_buffer )
      FUNCCALL(SETUP_XfOrM1022(_), make_tail_buffer_safe () ); 
    vals = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM1022(_), GC_malloc (sizeof (Scheme_Object * ) * (num_rands ) ) )) ; 
    for (i = num_rands ; i -- ; ) {
      vals [i ] = rands [i ] ; 
    }
    value = (Scheme_Object * ) vals ; 
    p -> cjs . num_vals = num_rands ; 
  }
  else {
    value = rands [0 ] ; 
    p -> cjs . num_vals = 1 ; 
  }
  if (! FUNCCALL(SETUP_XfOrM1019(_), scheme_escape_continuation_ok (obj ) )) {
#   define XfOrM1020_COUNT (0+XfOrM1019_COUNT)
#   define SETUP_XfOrM1020(x) SETUP_XfOrM1019(x)
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT_CONTINUATION , "continuation application: attempt to jump into an escape continuation" ) ); 
  }
  p -> cjs . val = value ; 
  p -> cjs . jumping_to_continuation = obj ; 
  (((long * ) (void * ) ((* (scheme_current_thread -> error_buf ) ) . gcvs ) ) [1 ] = (* (scheme_current_thread -> error_buf ) ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* (scheme_current_thread -> error_buf ) ) . gcvs , scheme_jit_longjmp ((* (scheme_current_thread -> error_buf ) ) . jb , 1 ) ) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_do_eval (Scheme_Object * obj , int num_rands , Scheme_Object * * rands , int get_value ) {
  Scheme_Type type ; 
  Scheme_Object * v ; 
  GC_CAN_IGNORE Scheme_Object * * old_runstack ; 
  GC_CAN_IGNORE long old_cont_mark_stack ; 
  long pmstack = - 1 ; 
  unsigned long _stk_pos ; 
  const char * __funcarg113 = NULLED_OUT ; 
  const char * __funcarg112 = NULLED_OUT ; 
  const char * __funcarg111 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(obj, 1), PUSH(rands, 2)));
# define XfOrM1025_COUNT (3)
# define SETUP_XfOrM1025(x) SETUP(XfOrM1025_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  v = NULLED_OUT ; 
  _stk_pos = (unsigned long ) & _stk_pos ; 
  if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
#   define XfOrM1202_COUNT (0+XfOrM1025_COUNT)
#   define SETUP_XfOrM1202(x) SETUP_XfOrM1025(x)
    scheme_current_thread -> ku . k . p1 = (void * ) obj ; 
    scheme_current_thread -> ku . k . i1 = num_rands ; 
    if (num_rands >= 0 ) {
      GC_CAN_IGNORE void * ra ; 
#     define XfOrM1203_COUNT (0+XfOrM1202_COUNT)
#     define SETUP_XfOrM1203(x) SETUP_XfOrM1202(x)
      if (rands == scheme_current_thread -> tail_buffer )
        FUNCCALL(SETUP_XfOrM1203(_), make_tail_buffer_safe () ); 
      ra = (void * ) ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM1203(_), GC_malloc (sizeof (Scheme_Object * ) * (num_rands ) ) )) ; 
      scheme_current_thread -> ku . k . p2 = ra ; 
      {
        int i ; 
        for (i = num_rands ; i -- ; ) {
          ((Scheme_Object * * ) ra ) [i ] = rands [i ] ; 
        }
      }
    }
    else scheme_current_thread -> ku . k . p2 = (void * ) rands ; 
    scheme_current_thread -> ku . k . i2 = get_value ; 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_handle_stack_overflow (do_eval_k ) )) RET_VALUE_EMPTY_END ; 
  }
  scheme_current_cont_mark_pos += 2 ; 
  old_runstack = scheme_current_runstack ; 
  old_cont_mark_stack = scheme_current_cont_mark_stack ; 
  if (num_rands >= 0 ) {
#   define XfOrM1102_COUNT (0+XfOrM1025_COUNT)
#   define SETUP_XfOrM1102(x) SETUP_XfOrM1025(x)
    if ((scheme_current_runstack - scheme_current_runstack_start ) < 5 ) {
#     define XfOrM1201_COUNT (0+XfOrM1102_COUNT)
#     define SETUP_XfOrM1201(x) SETUP_XfOrM1102(x)
      scheme_current_thread -> ku . k . p1 = (void * ) obj ; 
      scheme_current_thread -> ku . k . i1 = num_rands ; 
      scheme_current_thread -> ku . k . p2 = (void * ) rands ; 
      scheme_current_thread -> ku . k . i2 = - 1 ; 
      ; 
      if (rands == scheme_current_thread -> tail_buffer )
        FUNCCALL(SETUP_XfOrM1201(_), make_tail_buffer_safe () ); 
      scheme_current_cont_mark_pos -= 2 ; 
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_enlarge_runstack (5 , (void * (* ) (void ) ) do_eval_k ) )) RET_VALUE_EMPTY_END ; 
    }
    apply_top : type = ((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ; 
    if (type == scheme_prim_type ) {
      GC_CAN_IGNORE Scheme_Primitive_Proc * prim ; 
      GC_CAN_IGNORE Scheme_Primitive_Closure_Proc * f ; 
#     define XfOrM1194_COUNT (0+XfOrM1102_COUNT)
#     define SETUP_XfOrM1194(x) SETUP_XfOrM1102(x)
      if (rands == scheme_current_thread -> tail_buffer ) {
#       define XfOrM1196_COUNT (0+XfOrM1194_COUNT)
#       define SETUP_XfOrM1196(x) SETUP_XfOrM1194(x)
        if (num_rands < 5 ) {
          int i ; 
          GC_CAN_IGNORE Scheme_Object * * quick_rands ; 
          quick_rands = (scheme_current_runstack -= num_rands ) ; 
          ; 
          for (i = num_rands ; i -- ; ) {
            quick_rands [i ] = rands [i ] ; 
          }
          rands = quick_rands ; 
        }
        else {
#         define XfOrM1197_COUNT (0+XfOrM1196_COUNT)
#         define SETUP_XfOrM1197(x) SETUP_XfOrM1196(x)
          ; 
          FUNCCALL(SETUP_XfOrM1197(_), make_tail_buffer_safe () ); 
        }
      }
      ; 
      ; 
      prim = (Scheme_Primitive_Proc * ) obj ; 
      if (num_rands < prim -> mina || (num_rands > prim -> mu . maxa && prim -> mina >= 0 ) ) {
#       define XfOrM1195_COUNT (0+XfOrM1194_COUNT)
#       define SETUP_XfOrM1195(x) SETUP_XfOrM1194(x)
        FUNCCALL_EMPTY(scheme_wrong_count_m (prim -> name , prim -> mina , prim -> mu . maxa , num_rands , rands , prim -> pp . flags & 2048 ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      f = prim -> prim_val ; 
      v = FUNCCALL(SETUP_XfOrM1194(_), f (num_rands , rands , (Scheme_Object * ) prim ) ); 
      ; 
    }
    else if (type == scheme_closure_type ) {
      Scheme_Closure_Data * data ; 
      GC_CAN_IGNORE Scheme_Object * * stack , * * src ; 
      int i , has_rest , num_params ; 
      BLOCK_SETUP((PUSH(data, 0+XfOrM1102_COUNT)));
#     define XfOrM1157_COUNT (1+XfOrM1102_COUNT)
#     define SETUP_XfOrM1157(x) SETUP(XfOrM1157_COUNT)
      data = NULLED_OUT ; 
      if ((scheme_fuel_counter ) <= 0 ) {
#       define XfOrM1193_COUNT (0+XfOrM1157_COUNT)
#       define SETUP_XfOrM1193(x) SETUP_XfOrM1157(x)
        ; 
        if (rands == scheme_current_thread -> tail_buffer )
          FUNCCALL(SETUP_XfOrM1193(_), make_tail_buffer_safe () ); 
        FUNCCALL(SETUP_XfOrM1193(_), scheme_thread_block (0 ) ); 
        (scheme_current_thread ) -> ran_some = 1 ; 
      }
      ; 
      data = ((Scheme_Closure * ) obj ) -> code ; 
      if ((scheme_current_runstack - scheme_current_runstack_start ) < data -> max_let_depth ) {
#       define XfOrM1191_COUNT (0+XfOrM1157_COUNT)
#       define SETUP_XfOrM1191(x) SETUP_XfOrM1157(x)
        if (rands == scheme_current_thread -> tail_buffer ) {
#         define XfOrM1192_COUNT (0+XfOrM1191_COUNT)
#         define SETUP_XfOrM1192(x) SETUP_XfOrM1191(x)
          ; 
          FUNCCALL(SETUP_XfOrM1192(_), make_tail_buffer_safe () ); 
        }
        scheme_current_thread -> ku . k . p1 = (void * ) obj ; 
        scheme_current_thread -> ku . k . i1 = num_rands ; 
        scheme_current_thread -> ku . k . p2 = (void * ) rands ; 
        scheme_current_thread -> ku . k . i2 = - 1 ; 
        ; 
        scheme_current_cont_mark_pos -= 2 ; 
        v = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM1191(_), scheme_enlarge_runstack (data -> max_let_depth , (void * (* ) (void ) ) do_eval_k ) ); 
        scheme_current_cont_mark_pos += 2 ; 
        goto returnv ; 
      }
      num_params = data -> num_params ; 
      has_rest = (& (data ) -> iso ) -> so . keyex & 1 ; 
      if (num_params ) {
#       define XfOrM1171_COUNT (0+XfOrM1157_COUNT)
#       define SETUP_XfOrM1171(x) SETUP_XfOrM1157(x)
        if (has_rest ) {
          int extra , n ; 
#         define XfOrM1177_COUNT (0+XfOrM1171_COUNT)
#         define SETUP_XfOrM1177(x) SETUP_XfOrM1171(x)
          if (num_rands < (num_params - 1 ) ) {
#           define XfOrM1190_COUNT (0+XfOrM1177_COUNT)
#           define SETUP_XfOrM1190(x) SETUP_XfOrM1177(x)
            ; 
            (__funcarg113 = FUNCCALL(SETUP_XfOrM1190(_), scheme_get_proc_name (obj , ((void * ) 0 ) , 1 ) ), FUNCCALL_EMPTY(scheme_wrong_count_m (__funcarg113 , num_params - 1 , - 1 , num_rands , rands , (& (data ) -> iso ) -> so . keyex & 16 ) )) ; 
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          }
          n = num_params - has_rest ; 
          scheme_current_runstack = old_runstack - num_params ; 
          ; 
          ; 
          extra = num_rands - n ; 
          if (extra ) {
            Scheme_Object * rest_vals ; 
            GC_CAN_IGNORE Scheme_Object * pairs ; 
            BLOCK_SETUP((PUSH(rest_vals, 0+XfOrM1177_COUNT)));
#           define XfOrM1185_COUNT (1+XfOrM1177_COUNT)
#           define SETUP_XfOrM1185(x) SETUP(XfOrM1185_COUNT)
            rest_vals = NULLED_OUT ; 
            ; 
            scheme_current_thread -> runstack_tmp_keep = rands ; 
            rest_vals = scheme_null ; 
            for (i = num_rands - 1 ; i >= n ; -- i ) {
#             define XfOrM1189_COUNT (0+XfOrM1185_COUNT)
#             define SETUP_XfOrM1189(x) SETUP_XfOrM1185(x)
              pairs = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM1189(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
              pairs -> type = scheme_pair_type ; 
              (((Scheme_Simple_Object * ) (pairs ) ) -> u . pair_val . cdr ) = rest_vals ; 
              (((Scheme_Simple_Object * ) (pairs ) ) -> u . pair_val . car ) = rands [i ] ; 
              rest_vals = pairs ; 
            }
            scheme_current_thread -> runstack_tmp_keep = ((void * ) 0 ) ; 
            stack = scheme_current_runstack ; 
            stack [n ] = rest_vals ; 
            while (n -- ) {
              stack [n ] = rands [n ] ; 
            }
          }
          else {
            stack = scheme_current_runstack ; 
            if ((unsigned long ) rands > (unsigned long ) stack ) {
              int i ; 
              for (i = 0 ; i < n ; i ++ ) {
                stack [i ] = rands [i ] ; 
              }
              stack [n ] = scheme_null ; 
            }
            else {
              stack [n ] = scheme_null ; 
              while (n -- ) {
                stack [n ] = rands [n ] ; 
              }
            }
          }
        }
        else {
#         define XfOrM1172_COUNT (0+XfOrM1171_COUNT)
#         define SETUP_XfOrM1172(x) SETUP_XfOrM1171(x)
          if (num_rands != num_params ) {
#           define XfOrM1176_COUNT (0+XfOrM1172_COUNT)
#           define SETUP_XfOrM1176(x) SETUP_XfOrM1172(x)
            ; 
            (__funcarg112 = FUNCCALL(SETUP_XfOrM1176(_), scheme_get_proc_name (obj , ((void * ) 0 ) , 1 ) ), FUNCCALL_EMPTY(scheme_wrong_count_m (__funcarg112 , num_params , num_params , num_rands , rands , (& (data ) -> iso ) -> so . keyex & 16 ) )) ; 
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          }
          stack = scheme_current_runstack = old_runstack - num_params ; 
          ; 
          ; 
          if (rands != stack ) {
            int n = num_params ; 
            while (n -- ) {
              stack [n ] = rands [n ] ; 
            }
          }
        }
      }
      else {
#       define XfOrM1167_COUNT (0+XfOrM1157_COUNT)
#       define SETUP_XfOrM1167(x) SETUP_XfOrM1157(x)
        if (num_rands ) {
#         define XfOrM1168_COUNT (0+XfOrM1167_COUNT)
#         define SETUP_XfOrM1168(x) SETUP_XfOrM1167(x)
          if (has_rest ) {
          }
          else {
#           define XfOrM1169_COUNT (0+XfOrM1168_COUNT)
#           define SETUP_XfOrM1169(x) SETUP_XfOrM1168(x)
            ; 
            (__funcarg111 = FUNCCALL(SETUP_XfOrM1169(_), scheme_get_proc_name (obj , ((void * ) 0 ) , 1 ) ), FUNCCALL_EMPTY(scheme_wrong_count (__funcarg111 , 0 , 0 , num_rands , rands ) )) ; 
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          }
        }
        scheme_current_runstack = old_runstack ; 
        ; 
      }
      {
        int n = data -> closure_size ; 
        if (n ) {
          src = ((Scheme_Closure * ) obj ) -> vals ; 
          stack = (scheme_current_runstack -= n ) ; 
          ; 
          while (n -- ) {
            stack [n ] = src [n ] ; 
          }
        }
      }
      obj = data -> code ; 
      if (pmstack >= 0 ) {
        long segpos = ((long ) pmstack ) >> 8 ; 
        long pos = ((long ) pmstack ) & ((1 << 8 ) - 1 ) ; 
        GC_CAN_IGNORE Scheme_Cont_Mark * pm = ((void * ) 0 ) ; 
#       define XfOrM1161_COUNT (0+XfOrM1157_COUNT)
#       define SETUP_XfOrM1161(x) SETUP_XfOrM1157(x)
        pm = scheme_current_thread -> cont_mark_stack_segments [segpos ] + pos ; 
        if (! pm -> cache )
          pm -> val = data -> name ; 
        else {
#         define XfOrM1162_COUNT (0+XfOrM1161_COUNT)
#         define SETUP_XfOrM1162(x) SETUP_XfOrM1161(x)
          ; 
          pmstack = FUNCCALL(SETUP_XfOrM1162(_), scheme_set_cont_mark (scheme_stack_dump_key , data -> name ) ); 
        }
      }
      else {
        long segpos = ((long ) scheme_current_cont_mark_stack ) >> 8 ; 
#       define XfOrM1158_COUNT (0+XfOrM1157_COUNT)
#       define SETUP_XfOrM1158(x) SETUP_XfOrM1157(x)
        if (segpos >= scheme_current_thread -> cont_mark_seg_count ) {
#         define XfOrM1160_COUNT (0+XfOrM1158_COUNT)
#         define SETUP_XfOrM1160(x) SETUP_XfOrM1158(x)
          ; 
          pmstack = FUNCCALL(SETUP_XfOrM1160(_), scheme_set_cont_mark (scheme_stack_dump_key , data -> name ) ); 
        }
        else {
          long pos = ((long ) scheme_current_cont_mark_stack ) & ((1 << 8 ) - 1 ) ; 
          GC_CAN_IGNORE Scheme_Cont_Mark * pm ; 
          GC_CAN_IGNORE Scheme_Cont_Mark * seg ; 
          pmstack = scheme_current_cont_mark_stack ; 
          seg = scheme_current_thread -> cont_mark_stack_segments [segpos ] ; 
          pm = seg + pos ; 
          scheme_current_cont_mark_stack ++ ; 
          pm -> key = scheme_stack_dump_key ; 
          pm -> val = data -> name ; 
          pm -> pos = scheme_current_cont_mark_pos ; 
          pm -> cache = ((void * ) 0 ) ; 
        }
      }
      goto eval_top ; 
    }
    else if (type == scheme_case_closure_type ) {
      Scheme_Case_Lambda * seq ; 
      Scheme_Closure_Data * data ; 
      int i ; 
#     define XfOrM1152_COUNT (0+XfOrM1102_COUNT)
#     define SETUP_XfOrM1152(x) SETUP_XfOrM1102(x)
      seq = NULLED_OUT ; 
      data = NULLED_OUT ; 
      seq = (Scheme_Case_Lambda * ) obj ; 
      for (i = 0 ; i < seq -> count ; i ++ ) {
        data = ((Scheme_Closure * ) seq -> array [i ] ) -> code ; 
        if ((! ((& (data ) -> iso ) -> so . keyex & 1 ) && (data -> num_params == num_rands ) ) || (((& (data ) -> iso ) -> so . keyex & 1 ) && (data -> num_params - 1 <= num_rands ) ) ) {
          obj = seq -> array [i ] ; 
          goto apply_top ; 
        }
      }
      ; 
      FUNCCALL_EMPTY(scheme_wrong_count ((char * ) seq , - 1 , - 1 , num_rands , rands ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else if (type == scheme_native_closure_type ) {
      GC_CAN_IGNORE Scheme_Native_Closure_Data * data ; 
#     define XfOrM1143_COUNT (0+XfOrM1102_COUNT)
#     define SETUP_XfOrM1143(x) SETUP_XfOrM1102(x)
      if (rands == scheme_current_thread -> tail_buffer ) {
#       define XfOrM1147_COUNT (0+XfOrM1143_COUNT)
#       define SETUP_XfOrM1147(x) SETUP_XfOrM1143(x)
        if (num_rands < 5 ) {
          int i ; 
          GC_CAN_IGNORE Scheme_Object * * quick_rands ; 
          quick_rands = (scheme_current_runstack -= num_rands ) ; 
          ; 
          for (i = num_rands ; i -- ; ) {
            quick_rands [i ] = rands [i ] ; 
          }
          rands = quick_rands ; 
        }
        else {
#         define XfOrM1148_COUNT (0+XfOrM1147_COUNT)
#         define SETUP_XfOrM1148(x) SETUP_XfOrM1147(x)
          ; 
          FUNCCALL(SETUP_XfOrM1148(_), make_tail_buffer_safe () ); 
        }
      }
      ; 
      ; 
      if ((scheme_fuel_counter ) <= 0 ) {
#       define XfOrM1146_COUNT (0+XfOrM1143_COUNT)
#       define SETUP_XfOrM1146(x) SETUP_XfOrM1143(x)
        FUNCCALL(SETUP_XfOrM1146(_), scheme_thread_block (0 ) ); 
        (scheme_current_thread ) -> ran_some = 1 ; 
      }
      ; 
      if (! FUNCCALL(SETUP_XfOrM1143(_), scheme_native_arity_check (obj , num_rands ) )) {
#       define XfOrM1145_COUNT (0+XfOrM1143_COUNT)
#       define SETUP_XfOrM1145(x) SETUP_XfOrM1143(x)
        FUNCCALL_EMPTY(scheme_wrong_count_m ((const char * ) obj , - 1 , - 1 , num_rands , rands , 0 ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      data = ((Scheme_Native_Closure * ) obj ) -> code ; 
      if ((unsigned long ) data -> max_let_depth > ((unsigned long ) scheme_current_runstack - (unsigned long ) scheme_current_runstack_start ) ) {
#       define XfOrM1144_COUNT (0+XfOrM1143_COUNT)
#       define SETUP_XfOrM1144(x) SETUP_XfOrM1143(x)
        scheme_current_thread -> ku . k . p1 = (void * ) obj ; 
        scheme_current_thread -> ku . k . i1 = num_rands ; 
        scheme_current_thread -> ku . k . p2 = (void * ) rands ; 
        scheme_current_thread -> ku . k . i2 = - 1 ; 
        scheme_current_cont_mark_pos -= 2 ; 
        v = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM1144(_), scheme_enlarge_runstack (data -> max_let_depth / sizeof (void * ) , (void * (* ) (void ) ) do_eval_k ) ); 
        scheme_current_cont_mark_pos += 2 ; 
        goto returnv ; 
      }
      v = FUNCCALL(SETUP_XfOrM1143(_), data -> code (obj , num_rands , rands ) ); 
      ; 
    }
    else if (type == scheme_cont_type ) {
#     define XfOrM1142_COUNT (0+XfOrM1102_COUNT)
#     define SETUP_XfOrM1142(x) SETUP_XfOrM1102(x)
      ; 
      v = FUNCCALL(SETUP_XfOrM1142(_), scheme_jump_to_continuation (obj , num_rands , rands , old_runstack ) ); 
    }
    else if (type == scheme_escaping_cont_type ) {
#     define XfOrM1141_COUNT (0+XfOrM1102_COUNT)
#     define SETUP_XfOrM1141(x) SETUP_XfOrM1102(x)
      ; 
      FUNCCALL(SETUP_XfOrM1141(_), scheme_escape_to_continuation (obj , num_rands , rands ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else if (type == scheme_proc_struct_type ) {
      int is_method ; 
      int check_rands = num_rands ; 
#     define XfOrM1112_COUNT (0+XfOrM1102_COUNT)
#     define SETUP_XfOrM1112(x) SETUP_XfOrM1102(x)
      do {
#       define XfOrM1127_COUNT (0+XfOrM1112_COUNT)
#       define SETUP_XfOrM1127(x) SETUP_XfOrM1112(x)
        if (rands == scheme_current_thread -> tail_buffer ) {
#         define XfOrM1136_COUNT (0+XfOrM1127_COUNT)
#         define SETUP_XfOrM1136(x) SETUP_XfOrM1127(x)
          if (num_rands < 5 ) {
            int i ; 
            GC_CAN_IGNORE Scheme_Object * * quick_rands ; 
            quick_rands = (scheme_current_runstack -= num_rands ) ; 
            ; 
            for (i = num_rands ; i -- ; ) {
              quick_rands [i ] = rands [i ] ; 
            }
            rands = quick_rands ; 
          }
          else {
#           define XfOrM1137_COUNT (0+XfOrM1136_COUNT)
#           define SETUP_XfOrM1137(x) SETUP_XfOrM1136(x)
            ; 
            FUNCCALL(SETUP_XfOrM1137(_), make_tail_buffer_safe () ); 
          }
        }
        ; 
        ; 
        v = obj ; 
        obj = FUNCCALL(SETUP_XfOrM1127(_), scheme_extract_struct_procedure (obj , check_rands , rands , & is_method ) ); 
        if (is_method ) {
#         define XfOrM1129_COUNT (0+XfOrM1127_COUNT)
#         define SETUP_XfOrM1129(x) SETUP_XfOrM1127(x)
          if ((rands == scheme_current_runstack ) && (scheme_current_runstack != scheme_current_runstack_start ) ) {
            rands = (scheme_current_runstack -= 1 ) ; 
            rands [0 ] = v ; 
          }
          else {
            int i ; 
            Scheme_Object * * a ; 
            BLOCK_SETUP((PUSH(a, 0+XfOrM1129_COUNT)));
#           define XfOrM1130_COUNT (1+XfOrM1129_COUNT)
#           define SETUP_XfOrM1130(x) SETUP(XfOrM1130_COUNT)
            a = NULLED_OUT ; 
            if (scheme_current_thread -> tail_buffer && (num_rands < scheme_current_thread -> tail_buffer_size ) ) {
              a = scheme_current_thread -> tail_buffer ; 
            }
            else {
#             define XfOrM1133_COUNT (0+XfOrM1130_COUNT)
#             define SETUP_XfOrM1133(x) SETUP_XfOrM1130(x)
              ; 
              a = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM1133(_), GC_malloc (sizeof (Scheme_Object * ) * (num_rands + 1 ) ) )) ; 
            }
            for (i = num_rands ; i -- ; ) {
              a [i + 1 ] = rands [i ] ; 
            }
            a [0 ] = v ; 
            rands = a ; 
          }
          num_rands ++ ; 
        }
        check_rands = - 1 ; 
        if ((scheme_fuel_counter ) <= 0 ) {
#         define XfOrM1128_COUNT (0+XfOrM1127_COUNT)
#         define SETUP_XfOrM1128(x) SETUP_XfOrM1127(x)
          ; 
          if (rands == scheme_current_thread -> tail_buffer )
            FUNCCALL(SETUP_XfOrM1128(_), make_tail_buffer_safe () ); 
          FUNCCALL(SETUP_XfOrM1128(_), scheme_thread_block (0 ) ); 
          (scheme_current_thread ) -> ran_some = 1 ; 
        }
        ; 
      }
      while (((Scheme_Type ) (scheme_proc_struct_type ) == (Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) ) ) ; 
      goto apply_top ; 
    }
    else if (type == scheme_closed_prim_type ) {
      GC_CAN_IGNORE Scheme_Closed_Primitive_Proc * prim ; 
#     define XfOrM1104_COUNT (0+XfOrM1102_COUNT)
#     define SETUP_XfOrM1104(x) SETUP_XfOrM1102(x)
      if ((scheme_fuel_counter ) <= 0 ) {
#       define XfOrM1111_COUNT (0+XfOrM1104_COUNT)
#       define SETUP_XfOrM1111(x) SETUP_XfOrM1104(x)
        ; 
        if (rands == scheme_current_thread -> tail_buffer )
          FUNCCALL(SETUP_XfOrM1111(_), make_tail_buffer_safe () ); 
        FUNCCALL(SETUP_XfOrM1111(_), scheme_thread_block (0 ) ); 
        (scheme_current_thread ) -> ran_some = 1 ; 
      }
      ; 
      if (rands == scheme_current_thread -> tail_buffer ) {
#       define XfOrM1106_COUNT (0+XfOrM1104_COUNT)
#       define SETUP_XfOrM1106(x) SETUP_XfOrM1104(x)
        if (num_rands < 5 ) {
          int i ; 
          GC_CAN_IGNORE Scheme_Object * * quick_rands ; 
          quick_rands = (scheme_current_runstack -= num_rands ) ; 
          ; 
          for (i = num_rands ; i -- ; ) {
            quick_rands [i ] = rands [i ] ; 
          }
          rands = quick_rands ; 
        }
        else {
#         define XfOrM1107_COUNT (0+XfOrM1106_COUNT)
#         define SETUP_XfOrM1107(x) SETUP_XfOrM1106(x)
          ; 
          FUNCCALL(SETUP_XfOrM1107(_), make_tail_buffer_safe () ); 
        }
      }
      ; 
      ; 
      prim = (Scheme_Closed_Primitive_Proc * ) obj ; 
      if (num_rands < prim -> mina || (num_rands > prim -> maxa && prim -> maxa >= 0 ) ) {
#       define XfOrM1105_COUNT (0+XfOrM1104_COUNT)
#       define SETUP_XfOrM1105(x) SETUP_XfOrM1104(x)
        FUNCCALL_EMPTY(scheme_wrong_count_m (prim -> name , prim -> mina , prim -> maxa , num_rands , rands , prim -> pp . flags & 2048 ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      v = FUNCCALL(SETUP_XfOrM1104(_), prim -> prim_val (prim -> data , num_rands , rands ) ); 
      ; 
    }
    else {
#     define XfOrM1103_COUNT (0+XfOrM1102_COUNT)
#     define SETUP_XfOrM1103(x) SETUP_XfOrM1102(x)
      ; 
      if (rands == scheme_current_thread -> tail_buffer )
        FUNCCALL(SETUP_XfOrM1103(_), make_tail_buffer_safe () ); 
      FUNCCALL_EMPTY(scheme_wrong_rator (obj , num_rands , rands ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  else {
#   define XfOrM1029_COUNT (0+XfOrM1025_COUNT)
#   define SETUP_XfOrM1029(x) SETUP_XfOrM1025(x)
    eval_top : if ((((long ) (obj ) ) & 0x1 ) ) {
      v = obj ; 
      goto returnv_never_multi ; 
    }
    type = ((obj ) -> type ) ; 
    switch (type ) {
#     define XfOrM1030_COUNT (0+XfOrM1029_COUNT)
#     define SETUP_XfOrM1030(x) SETUP_XfOrM1029(x)
      case scheme_toplevel_type : {
#       define XfOrM1099_COUNT (0+XfOrM1030_COUNT)
#       define SETUP_XfOrM1099(x) SETUP_XfOrM1030(x)
        v = scheme_current_runstack [(((Scheme_Toplevel * ) (obj ) ) -> depth ) ] ; 
        v = ((Scheme_Object * * ) v ) [(((Scheme_Toplevel * ) (obj ) ) -> position ) ] ; 
        v = (Scheme_Object * ) (((Scheme_Bucket * ) (v ) ) ) -> val ; 
        if (! v ) {
#         define XfOrM1100_COUNT (0+XfOrM1099_COUNT)
#         define SETUP_XfOrM1100(x) SETUP_XfOrM1099(x)
          ; 
          FUNCCALL(SETUP_XfOrM1100(_), unbound_global (obj ) ); 
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        }
        v = v ; 
        goto returnv_never_multi ; 
      }
      case scheme_local_type : {
        v = scheme_current_runstack [(((Scheme_Local * ) (obj ) ) -> position ) ] ; 
        goto returnv_never_multi ; 
      }
      case scheme_local_unbox_type : {
        v = (* ((Scheme_Object * * ) (scheme_current_runstack [(((Scheme_Local * ) (obj ) ) -> position ) ] ) ) ) ; 
        goto returnv_never_multi ; 
      }
      case scheme_syntax_type : {
        Scheme_Syntax_Executer f ; 
#       define XfOrM1096_COUNT (0+XfOrM1030_COUNT)
#       define SETUP_XfOrM1096(x) SETUP_XfOrM1030(x)
        ; 
        f = scheme_syntax_executers [(((Scheme_Simple_Object * ) (obj ) ) -> u . ptr_int_val . pint ) ] ; 
        v = FUNCCALL(SETUP_XfOrM1096(_), f ((Scheme_Object * ) (((Scheme_Simple_Object * ) (obj ) ) -> u . ptr_int_val . ptr ) ) ); 
        break ; 
      }
      case scheme_application_type : {
        Scheme_App_Rec * app ; 
        GC_CAN_IGNORE Scheme_Object * tmpv ; 
        GC_CAN_IGNORE Scheme_Object * * randsp ; 
        Scheme_Object * * stack ; 
        int k ; 
        int d_evals ; 
        BLOCK_SETUP((PUSH(app, 0+XfOrM1030_COUNT), PUSH(stack, 1+XfOrM1030_COUNT)));
#       define XfOrM1084_COUNT (2+XfOrM1030_COUNT)
#       define SETUP_XfOrM1084(x) SETUP(XfOrM1084_COUNT)
        app = NULLED_OUT ; 
        stack = NULLED_OUT ; 
        app = (Scheme_App_Rec * ) obj ; 
        num_rands = app -> num_args ; 
        d_evals = sizeof (Scheme_App_Rec ) + (num_rands * sizeof (Scheme_Object * ) ) ; 
        obj = app -> args [0 ] ; 
        stack = (scheme_current_runstack -= num_rands ) ; 
        ; 
        ; 
        switch (((char * ) app ) [d_evals ] ) {
#         define XfOrM1094_COUNT (0+XfOrM1084_COUNT)
#         define SETUP_XfOrM1094(x) SETUP_XfOrM1084(x)
          case SCHEME_EVAL_CONSTANT : break ; 
          case SCHEME_EVAL_GLOBAL : tmpv = scheme_current_runstack [(((Scheme_Toplevel * ) (obj ) ) -> depth ) ] ; 
          tmpv = ((Scheme_Object * * ) tmpv ) [(((Scheme_Toplevel * ) (obj ) ) -> position ) ] ; 
          tmpv = (Scheme_Object * ) (((Scheme_Bucket * ) (tmpv ) ) ) -> val ; 
          if (! tmpv ) {
#           define XfOrM1095_COUNT (0+XfOrM1094_COUNT)
#           define SETUP_XfOrM1095(x) SETUP_XfOrM1094(x)
            ; 
            FUNCCALL(SETUP_XfOrM1095(_), unbound_global (obj ) ); 
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          }
          obj = tmpv ; 
          break ; 
          case SCHEME_EVAL_LOCAL : obj = stack [(((Scheme_Local * ) (obj ) ) -> position ) ] ; 
          break ; 
          case SCHEME_EVAL_LOCAL_UNBOX : obj = (* ((Scheme_Object * * ) (stack [(((Scheme_Local * ) (obj ) ) -> position ) ] ) ) ) ; 
          break ; 
          default : obj = FUNCCALL(SETUP_XfOrM1094(_), scheme_do_eval (obj , - 1 , ((void * ) 0 ) , 1 ) ); 
          break ; 
        }
        if (num_rands ) {
          int evalpos = 1 ; 
#         define XfOrM1085_COUNT (0+XfOrM1084_COUNT)
#         define SETUP_XfOrM1085(x) SETUP_XfOrM1084(x)
          rands = stack ; 
          randsp = rands ; 
          for (k = num_rands ; k -- ; ) {
#           define XfOrM1090_COUNT (0+XfOrM1085_COUNT)
#           define SETUP_XfOrM1090(x) SETUP_XfOrM1085(x)
            v = app -> args [evalpos ] ; 
            switch (((char * ) app ) [d_evals + evalpos ++ ] ) {
#             define XfOrM1091_COUNT (0+XfOrM1090_COUNT)
#             define SETUP_XfOrM1091(x) SETUP_XfOrM1090(x)
              case SCHEME_EVAL_CONSTANT : * (randsp ++ ) = v ; 
              break ; 
              case SCHEME_EVAL_GLOBAL : tmpv = scheme_current_runstack [(((Scheme_Toplevel * ) (v ) ) -> depth ) ] ; 
              tmpv = ((Scheme_Object * * ) tmpv ) [(((Scheme_Toplevel * ) (v ) ) -> position ) ] ; 
              tmpv = (Scheme_Object * ) (((Scheme_Bucket * ) (tmpv ) ) ) -> val ; 
              if (! tmpv ) {
#               define XfOrM1093_COUNT (0+XfOrM1091_COUNT)
#               define SETUP_XfOrM1093(x) SETUP_XfOrM1091(x)
                ; 
                FUNCCALL(SETUP_XfOrM1093(_), unbound_global (v ) ); 
                RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
              }
              * (randsp ++ ) = tmpv ; 
              break ; 
              case SCHEME_EVAL_LOCAL : * (randsp ++ ) = stack [(((Scheme_Local * ) (v ) ) -> position ) ] ; 
              break ; 
              case SCHEME_EVAL_LOCAL_UNBOX : * (randsp ++ ) = (* ((Scheme_Object * * ) (stack [(((Scheme_Local * ) (v ) ) -> position ) ] ) ) ) ; 
              break ; 
              default : {
                GC_CAN_IGNORE Scheme_Object * er ; 
#               define XfOrM1092_COUNT (0+XfOrM1091_COUNT)
#               define SETUP_XfOrM1092(x) SETUP_XfOrM1091(x)
                er = FUNCCALL(SETUP_XfOrM1092(_), scheme_do_eval (v , - 1 , ((void * ) 0 ) , 1 ) ); 
                * (randsp ++ ) = er ; 
              }
              break ; 
            }
            ; 
          }
        }
        else rands = & zero_rands_ptr ; 
        goto apply_top ; 
      }
      case scheme_application2_type : {
        Scheme_App2_Rec * app ; 
        GC_CAN_IGNORE Scheme_Object * arg ; 
        short flags ; 
        BLOCK_SETUP((PUSH(app, 0+XfOrM1030_COUNT)));
#       define XfOrM1077_COUNT (1+XfOrM1030_COUNT)
#       define SETUP_XfOrM1077(x) SETUP(XfOrM1077_COUNT)
        app = NULLED_OUT ; 
        app = (Scheme_App2_Rec * ) obj ; 
        obj = app -> rator ; 
        flags = (& app -> iso ) -> so . keyex ; 
        rands = (scheme_current_runstack -= 1 ) ; 
        ; 
        ; 
        switch (flags & 0x7 ) {
#         define XfOrM1081_COUNT (0+XfOrM1077_COUNT)
#         define SETUP_XfOrM1081(x) SETUP_XfOrM1077(x)
          case SCHEME_EVAL_CONSTANT : break ; 
          case SCHEME_EVAL_GLOBAL : {
            GC_CAN_IGNORE Scheme_Object * tmpv ; 
#           define XfOrM1082_COUNT (0+XfOrM1081_COUNT)
#           define SETUP_XfOrM1082(x) SETUP_XfOrM1081(x)
            tmpv = scheme_current_runstack [(((Scheme_Toplevel * ) (obj ) ) -> depth ) ] ; 
            tmpv = ((Scheme_Object * * ) tmpv ) [(((Scheme_Toplevel * ) (obj ) ) -> position ) ] ; 
            tmpv = (Scheme_Object * ) (((Scheme_Bucket * ) (tmpv ) ) ) -> val ; 
            if (! tmpv ) {
#             define XfOrM1083_COUNT (0+XfOrM1082_COUNT)
#             define SETUP_XfOrM1083(x) SETUP_XfOrM1082(x)
              ; 
              FUNCCALL(SETUP_XfOrM1083(_), unbound_global (obj ) ); 
              RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
            }
            obj = tmpv ; 
          }
          break ; 
          case SCHEME_EVAL_LOCAL : obj = rands [(((Scheme_Local * ) (obj ) ) -> position ) ] ; 
          break ; 
          case SCHEME_EVAL_LOCAL_UNBOX : obj = (* ((Scheme_Object * * ) (rands [(((Scheme_Local * ) (obj ) ) -> position ) ] ) ) ) ; 
          break ; 
          default : obj = FUNCCALL(SETUP_XfOrM1081(_), scheme_do_eval (obj , - 1 , ((void * ) 0 ) , 1 ) ); 
          break ; 
        }
        arg = app -> rand ; 
        switch (flags >> 3 ) {
#         define XfOrM1078_COUNT (0+XfOrM1077_COUNT)
#         define SETUP_XfOrM1078(x) SETUP_XfOrM1077(x)
          case SCHEME_EVAL_CONSTANT : break ; 
          case SCHEME_EVAL_GLOBAL : {
            GC_CAN_IGNORE Scheme_Object * tmpv ; 
#           define XfOrM1079_COUNT (0+XfOrM1078_COUNT)
#           define SETUP_XfOrM1079(x) SETUP_XfOrM1078(x)
            tmpv = scheme_current_runstack [(((Scheme_Toplevel * ) (arg ) ) -> depth ) ] ; 
            tmpv = ((Scheme_Object * * ) tmpv ) [(((Scheme_Toplevel * ) (arg ) ) -> position ) ] ; 
            tmpv = (Scheme_Object * ) (((Scheme_Bucket * ) (tmpv ) ) ) -> val ; 
            if (! tmpv ) {
#             define XfOrM1080_COUNT (0+XfOrM1079_COUNT)
#             define SETUP_XfOrM1080(x) SETUP_XfOrM1079(x)
              ; 
              FUNCCALL(SETUP_XfOrM1080(_), unbound_global (arg ) ); 
              RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
            }
            arg = tmpv ; 
          }
          break ; 
          case SCHEME_EVAL_LOCAL : arg = rands [(((Scheme_Local * ) (arg ) ) -> position ) ] ; 
          break ; 
          case SCHEME_EVAL_LOCAL_UNBOX : arg = (* ((Scheme_Object * * ) (rands [(((Scheme_Local * ) (arg ) ) -> position ) ] ) ) ) ; 
          break ; 
          default : arg = FUNCCALL(SETUP_XfOrM1078(_), scheme_do_eval (arg , - 1 , ((void * ) 0 ) , 1 ) ); 
          break ; 
        }
        rands [0 ] = arg ; 
        num_rands = 1 ; 
        goto apply_top ; 
      }
      case scheme_application3_type : {
        Scheme_App3_Rec * app ; 
        GC_CAN_IGNORE Scheme_Object * arg ; 
        short flags ; 
        GC_CAN_IGNORE Scheme_Object * tmpv ; 
        BLOCK_SETUP((PUSH(app, 0+XfOrM1030_COUNT)));
#       define XfOrM1070_COUNT (1+XfOrM1030_COUNT)
#       define SETUP_XfOrM1070(x) SETUP(XfOrM1070_COUNT)
        app = NULLED_OUT ; 
        app = (Scheme_App3_Rec * ) obj ; 
        obj = app -> rator ; 
        flags = (& app -> iso ) -> so . keyex ; 
        rands = (scheme_current_runstack -= 2 ) ; 
        ; 
        ; 
        switch (flags & 0x7 ) {
#         define XfOrM1075_COUNT (0+XfOrM1070_COUNT)
#         define SETUP_XfOrM1075(x) SETUP_XfOrM1070(x)
          case SCHEME_EVAL_CONSTANT : break ; 
          case SCHEME_EVAL_GLOBAL : tmpv = scheme_current_runstack [(((Scheme_Toplevel * ) (obj ) ) -> depth ) ] ; 
          tmpv = ((Scheme_Object * * ) tmpv ) [(((Scheme_Toplevel * ) (obj ) ) -> position ) ] ; 
          tmpv = (Scheme_Object * ) (((Scheme_Bucket * ) (tmpv ) ) ) -> val ; 
          if (! tmpv ) {
#           define XfOrM1076_COUNT (0+XfOrM1075_COUNT)
#           define SETUP_XfOrM1076(x) SETUP_XfOrM1075(x)
            ; 
            FUNCCALL(SETUP_XfOrM1076(_), unbound_global (obj ) ); 
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          }
          obj = tmpv ; 
          break ; 
          case SCHEME_EVAL_LOCAL : obj = rands [(((Scheme_Local * ) (obj ) ) -> position ) ] ; 
          break ; 
          case SCHEME_EVAL_LOCAL_UNBOX : obj = (* ((Scheme_Object * * ) (rands [(((Scheme_Local * ) (obj ) ) -> position ) ] ) ) ) ; 
          break ; 
          default : obj = FUNCCALL(SETUP_XfOrM1075(_), scheme_do_eval (obj , - 1 , ((void * ) 0 ) , 1 ) ); 
          break ; 
        }
        arg = app -> rand1 ; 
        switch ((flags >> 3 ) & 0x7 ) {
#         define XfOrM1073_COUNT (0+XfOrM1070_COUNT)
#         define SETUP_XfOrM1073(x) SETUP_XfOrM1070(x)
          case SCHEME_EVAL_CONSTANT : break ; 
          case SCHEME_EVAL_GLOBAL : tmpv = scheme_current_runstack [(((Scheme_Toplevel * ) (arg ) ) -> depth ) ] ; 
          tmpv = ((Scheme_Object * * ) tmpv ) [(((Scheme_Toplevel * ) (arg ) ) -> position ) ] ; 
          tmpv = (Scheme_Object * ) (((Scheme_Bucket * ) (tmpv ) ) ) -> val ; 
          if (! tmpv ) {
#           define XfOrM1074_COUNT (0+XfOrM1073_COUNT)
#           define SETUP_XfOrM1074(x) SETUP_XfOrM1073(x)
            ; 
            FUNCCALL(SETUP_XfOrM1074(_), unbound_global (arg ) ); 
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          }
          arg = tmpv ; 
          break ; 
          case SCHEME_EVAL_LOCAL : arg = rands [(((Scheme_Local * ) (arg ) ) -> position ) ] ; 
          break ; 
          case SCHEME_EVAL_LOCAL_UNBOX : arg = (* ((Scheme_Object * * ) (rands [(((Scheme_Local * ) (arg ) ) -> position ) ] ) ) ) ; 
          break ; 
          default : arg = FUNCCALL(SETUP_XfOrM1073(_), scheme_do_eval (arg , - 1 , ((void * ) 0 ) , 1 ) ); 
          break ; 
        }
        rands [0 ] = arg ; 
        arg = app -> rand2 ; 
        switch ((& app -> iso ) -> so . keyex >> 6 ) {
#         define XfOrM1071_COUNT (0+XfOrM1070_COUNT)
#         define SETUP_XfOrM1071(x) SETUP_XfOrM1070(x)
          case SCHEME_EVAL_CONSTANT : break ; 
          case SCHEME_EVAL_GLOBAL : tmpv = scheme_current_runstack [(((Scheme_Toplevel * ) (arg ) ) -> depth ) ] ; 
          tmpv = ((Scheme_Object * * ) tmpv ) [(((Scheme_Toplevel * ) (arg ) ) -> position ) ] ; 
          tmpv = (Scheme_Object * ) (((Scheme_Bucket * ) (tmpv ) ) ) -> val ; 
          if (! tmpv ) {
#           define XfOrM1072_COUNT (0+XfOrM1071_COUNT)
#           define SETUP_XfOrM1072(x) SETUP_XfOrM1071(x)
            ; 
            FUNCCALL(SETUP_XfOrM1072(_), unbound_global (arg ) ); 
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          }
          arg = tmpv ; 
          break ; 
          case SCHEME_EVAL_LOCAL : arg = rands [(((Scheme_Local * ) (arg ) ) -> position ) ] ; 
          break ; 
          case SCHEME_EVAL_LOCAL_UNBOX : arg = (* ((Scheme_Object * * ) (rands [(((Scheme_Local * ) (arg ) ) -> position ) ] ) ) ) ; 
          break ; 
          default : arg = FUNCCALL(SETUP_XfOrM1071(_), scheme_do_eval (arg , - 1 , ((void * ) 0 ) , 1 ) ); 
          break ; 
        }
        rands [1 ] = arg ; 
        num_rands = 2 ; 
        goto apply_top ; 
      }
      case scheme_sequence_type : {
        int cnt ; 
        int i ; 
#       define XfOrM1067_COUNT (0+XfOrM1030_COUNT)
#       define SETUP_XfOrM1067(x) SETUP_XfOrM1030(x)
        cnt = ((Scheme_Sequence * ) obj ) -> count - 1 ; 
        ; 
        for (i = 0 ; i < cnt ; i ++ ) {
#         define XfOrM1069_COUNT (0+XfOrM1067_COUNT)
#         define SETUP_XfOrM1069(x) SETUP_XfOrM1067(x)
          (void ) FUNCCALL(SETUP_XfOrM1069(_), scheme_do_eval (((Scheme_Sequence * ) obj ) -> array [i ] , - 1 , ((void * ) 0 ) , - 1 ) ); 
        }
        obj = ((Scheme_Sequence * ) obj ) -> array [cnt ] ; 
        goto eval_top ; 
      }
      case scheme_branch_type : {
#       define XfOrM1066_COUNT (0+XfOrM1030_COUNT)
#       define SETUP_XfOrM1066(x) SETUP_XfOrM1030(x)
        ; 
        obj = (((FUNCCALL(SETUP_XfOrM1066(_), scheme_do_eval (((Scheme_Branch_Rec * ) obj ) -> test , - 1 , ((void * ) 0 ) , 1 ) )) != (scheme_false ) ) ? ((Scheme_Branch_Rec * ) obj ) -> tbranch : ((Scheme_Branch_Rec * ) obj ) -> fbranch ) ; 
        goto eval_top ; 
      }
      case scheme_unclosed_procedure_type : ; 
      v = FUNCCALL(SETUP_XfOrM1030(_), scheme_make_closure (scheme_current_thread , obj , 1 ) ); 
      goto returnv_never_multi ; 
      case scheme_let_value_type : {
        GC_CAN_IGNORE Scheme_Let_Value * lv ; 
        GC_CAN_IGNORE Scheme_Object * value , * * values ; 
        int i , c , ab ; 
#       define XfOrM1056_COUNT (0+XfOrM1030_COUNT)
#       define SETUP_XfOrM1056(x) SETUP_XfOrM1030(x)
        lv = (Scheme_Let_Value * ) obj ; 
        c = lv -> count ; 
        i = lv -> position ; 
        ab = (& lv -> iso ) -> so . keyex ; 
        value = lv -> value ; 
        obj = lv -> body ; 
        ; 
        if (c == 1 ) {
#         define XfOrM1065_COUNT (0+XfOrM1056_COUNT)
#         define SETUP_XfOrM1065(x) SETUP_XfOrM1056(x)
          value = FUNCCALL(SETUP_XfOrM1065(_), scheme_do_eval (value , - 1 , ((void * ) 0 ) , 1 ) ); 
          if (ab )
            (* ((Scheme_Object * * ) (scheme_current_runstack [i ] ) ) ) = value ; 
          else scheme_current_runstack [i ] = value ; 
        }
        else {
          int c2 ; 
          GC_CAN_IGNORE Scheme_Object * * stack ; 
#         define XfOrM1057_COUNT (0+XfOrM1056_COUNT)
#         define SETUP_XfOrM1057(x) SETUP_XfOrM1056(x)
          value = FUNCCALL(SETUP_XfOrM1057(_), scheme_do_eval (value , - 1 , ((void * ) 0 ) , - 1 ) ); 
          c2 = (((value ) == (((Scheme_Object * ) 0x6 ) ) ) ? scheme_current_thread -> ku . multiple . count : 1 ) ; 
          if (c2 != c ) {
#           define XfOrM1064_COUNT (0+XfOrM1057_COUNT)
#           define SETUP_XfOrM1064(x) SETUP_XfOrM1057(x)
            FUNCCALL(SETUP_XfOrM1064(_), scheme_wrong_return_arity (((void * ) 0 ) , c , c2 , (c2 == 1 ) ? (Scheme_Object * * ) value : scheme_current_thread -> ku . multiple . array , "lexical binding" ) ); 
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          }
          values = scheme_current_thread -> ku . multiple . array ; 
          scheme_current_thread -> ku . multiple . array = ((void * ) 0 ) ; 
          stack = scheme_current_runstack ; 
          if (ab ) {
            while (c -- ) {
              (* ((Scheme_Object * * ) (stack [i ] ) ) ) = * values ; 
              values ++ ; 
              i ++ ; 
            }
          }
          else {
            while (c -- ) {
              stack [i ] = * values ; 
              values ++ ; 
              i ++ ; 
            }
          }
        }
        goto eval_top ; 
      }
      case scheme_let_void_type : {
        GC_CAN_IGNORE Scheme_Let_Void * lv ; 
        int c ; 
#       define XfOrM1052_COUNT (0+XfOrM1030_COUNT)
#       define SETUP_XfOrM1052(x) SETUP_XfOrM1030(x)
        lv = (Scheme_Let_Void * ) obj ; 
        c = lv -> count ; 
        obj = lv -> body ; 
        (scheme_current_runstack -= c ) ; 
        ; 
        if ((& lv -> iso ) -> so . keyex ) {
          Scheme_Object * * stack = scheme_current_runstack ; 
          BLOCK_SETUP((PUSH(stack, 0+XfOrM1052_COUNT)));
#         define XfOrM1053_COUNT (1+XfOrM1052_COUNT)
#         define SETUP_XfOrM1053(x) SETUP(XfOrM1053_COUNT)
          ; 
          while (c -- ) {
            GC_CAN_IGNORE Scheme_Object * ub ; 
#           define XfOrM1055_COUNT (0+XfOrM1053_COUNT)
#           define SETUP_XfOrM1055(x) SETUP_XfOrM1053(x)
            ub = FUNCCALL(SETUP_XfOrM1055(_), scheme_make_envunbox (scheme_undefined ) ); 
            stack [c ] = ub ; 
          }
        }
        goto eval_top ; 
      }
      case scheme_letrec_type : {
        Scheme_Letrec * l = (Scheme_Letrec * ) obj ; 
        Scheme_Object * * a , * * stack ; 
        int i ; 
        BLOCK_SETUP((PUSH(a, 0+XfOrM1030_COUNT), PUSH(stack, 1+XfOrM1030_COUNT), PUSH(l, 2+XfOrM1030_COUNT)));
#       define XfOrM1039_COUNT (3+XfOrM1030_COUNT)
#       define SETUP_XfOrM1039(x) SETUP(XfOrM1039_COUNT)
        a = NULLED_OUT ; 
        stack = NULLED_OUT ; 
        stack = scheme_current_runstack ; 
        a = l -> procs ; 
        i = l -> count ; 
        ; 
        while (i -- ) {
          Scheme_Object * uc ; 
          BLOCK_SETUP((PUSH(uc, 0+XfOrM1039_COUNT)));
#         define XfOrM1051_COUNT (1+XfOrM1039_COUNT)
#         define SETUP_XfOrM1051(x) SETUP(XfOrM1051_COUNT)
          uc = NULLED_OUT ; 
          uc = FUNCCALL(SETUP_XfOrM1051(_), scheme_make_closure (scheme_current_thread , a [i ] , 0 ) ); 
          stack [i ] = uc ; 
        }
        i = l -> count ; 
        while (i -- ) {
          GC_CAN_IGNORE Scheme_Object * clos ; 
          GC_CAN_IGNORE Scheme_Object * * dest ; 
          GC_CAN_IGNORE mzshort * map ; 
          GC_CAN_IGNORE Scheme_Closure_Data * data ; 
          int j ; 
          clos = stack [i ] ; 
          if (((Scheme_Type ) (((clos ) -> type ) ) == (Scheme_Type ) (scheme_closure_type ) ) ) {
            dest = ((Scheme_Closure * ) clos ) -> vals ; 
          }
          else {
            dest = ((Scheme_Native_Closure * ) clos ) -> vals ; 
          }
          data = (Scheme_Closure_Data * ) a [i ] ; 
          map = data -> closure_map ; 
          j = data -> closure_size ; 
          while (j -- ) {
            dest [j ] = stack [map [j ] ] ; 
          }
        }
        obj = l -> body ; 
        goto eval_top ; 
      }
      case scheme_let_one_type : {
#       define XfOrM1034_COUNT (0+XfOrM1030_COUNT)
#       define SETUP_XfOrM1034(x) SETUP_XfOrM1030(x)
        (scheme_current_runstack -= 1 ) ; 
        ; 
        switch ((& ((Scheme_Let_One * ) obj ) -> iso ) -> so . keyex ) {
#         define XfOrM1035_COUNT (0+XfOrM1034_COUNT)
#         define SETUP_XfOrM1035(x) SETUP_XfOrM1034(x)
          case SCHEME_EVAL_CONSTANT : scheme_current_runstack [0 ] = ((Scheme_Let_One * ) obj ) -> value ; 
          break ; 
          case SCHEME_EVAL_GLOBAL : {
            GC_CAN_IGNORE Scheme_Object * tmpv ; 
#           define XfOrM1037_COUNT (0+XfOrM1035_COUNT)
#           define SETUP_XfOrM1037(x) SETUP_XfOrM1035(x)
            tmpv = scheme_current_runstack [(((Scheme_Toplevel * ) (((Scheme_Let_One * ) obj ) -> value ) ) -> depth ) ] ; 
            tmpv = ((Scheme_Object * * ) tmpv ) [(((Scheme_Toplevel * ) (((Scheme_Let_One * ) obj ) -> value ) ) -> position ) ] ; 
            tmpv = (Scheme_Object * ) (((Scheme_Bucket * ) (tmpv ) ) ) -> val ; 
            if (! tmpv ) {
#             define XfOrM1038_COUNT (0+XfOrM1037_COUNT)
#             define SETUP_XfOrM1038(x) SETUP_XfOrM1037(x)
              ; 
              FUNCCALL(SETUP_XfOrM1038(_), unbound_global (((Scheme_Let_One * ) obj ) -> value ) ); 
              RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
            }
            scheme_current_runstack [0 ] = tmpv ; 
          }
          break ; 
          case SCHEME_EVAL_LOCAL : scheme_current_runstack [0 ] = scheme_current_runstack [(((Scheme_Local * ) (((Scheme_Let_One * ) obj ) -> value ) ) -> position ) ] ; 
          break ; 
          case SCHEME_EVAL_LOCAL_UNBOX : scheme_current_runstack [0 ] = (* ((Scheme_Object * * ) (scheme_current_runstack [(((Scheme_Local * ) (((Scheme_Let_One * ) obj ) -> value ) ) -> position ) ] ) ) ) ; 
          break ; 
          default : ; 
          {
            GC_CAN_IGNORE Scheme_Object * val ; 
#           define XfOrM1036_COUNT (0+XfOrM1035_COUNT)
#           define SETUP_XfOrM1036(x) SETUP_XfOrM1035(x)
            val = FUNCCALL(SETUP_XfOrM1036(_), scheme_do_eval (((Scheme_Let_One * ) obj ) -> value , - 1 , ((void * ) 0 ) , 1 ) ); 
            scheme_current_runstack [0 ] = val ; 
          }
          break ; 
        }
        obj = ((Scheme_Let_One * ) obj ) -> body ; 
        goto eval_top ; 
      }
      case scheme_with_cont_mark_type : {
        Scheme_With_Continuation_Mark * wcm = (Scheme_With_Continuation_Mark * ) obj ; 
        GC_CAN_IGNORE Scheme_Object * key , * val ; 
        BLOCK_SETUP((PUSH(wcm, 0+XfOrM1030_COUNT)));
#       define XfOrM1033_COUNT (1+XfOrM1030_COUNT)
#       define SETUP_XfOrM1033(x) SETUP(XfOrM1033_COUNT)
        ; 
        key = wcm -> key ; 
        if (((((long ) (key ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (key ) ) -> type ) < _scheme_values_types_ )
          key = FUNCCALL(SETUP_XfOrM1033(_), scheme_do_eval (wcm -> key , - 1 , ((void * ) 0 ) , 1 ) ); 
        val = wcm -> val ; 
        if (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) < _scheme_values_types_ )
          val = FUNCCALL(SETUP_XfOrM1033(_), scheme_do_eval (wcm -> val , - 1 , ((void * ) 0 ) , 1 ) ); 
        FUNCCALL(SETUP_XfOrM1033(_), scheme_set_cont_mark (key , val ) ); 
        obj = wcm -> body ; 
        goto eval_top ; 
      }
      case scheme_quote_syntax_type : {
        GC_CAN_IGNORE Scheme_Quote_Syntax * qs = (Scheme_Quote_Syntax * ) obj ; 
        Scheme_Object * * globs ; 
        int i , c , scheme_current_thread ; 
        BLOCK_SETUP((PUSH(globs, 0+XfOrM1030_COUNT)));
#       define XfOrM1031_COUNT (1+XfOrM1030_COUNT)
#       define SETUP_XfOrM1031(x) SETUP(XfOrM1031_COUNT)
        globs = NULLED_OUT ; 
        i = qs -> position ; 
        c = qs -> depth ; 
        scheme_current_thread = qs -> midpoint ; 
        globs = (Scheme_Object * * ) scheme_current_runstack [c ] ; 
        v = globs [i + scheme_current_thread + 1 ] ; 
        if (! v ) {
#         define XfOrM1032_COUNT (0+XfOrM1031_COUNT)
#         define SETUP_XfOrM1032(x) SETUP_XfOrM1031(x)
          v = globs [scheme_current_thread ] ; 
          v = FUNCCALL(SETUP_XfOrM1032(_), scheme_delayed_rename ((Scheme_Object * * ) v , i ) ); 
          globs [i + scheme_current_thread + 1 ] = v ; 
        }
        goto returnv_never_multi ; 
      }
      default : v = obj ; 
      goto returnv_never_multi ; 
    }
  }
  if (((v ) == (((Scheme_Object * ) 0x4 ) ) ) ) {
    obj = scheme_current_thread -> ku . apply . tail_rator ; 
    num_rands = scheme_current_thread -> ku . apply . tail_num_rands ; 
    rands = scheme_current_thread -> ku . apply . tail_rands ; 
    scheme_current_thread -> ku . apply . tail_rator = ((void * ) 0 ) ; 
    scheme_current_thread -> ku . apply . tail_rands = ((void * ) 0 ) ; 
    scheme_current_runstack = old_runstack ; 
    ; 
    goto apply_top ; 
  }
  if (((v ) == (((Scheme_Object * ) 0x2 ) ) ) ) {
    ; 
    obj = scheme_current_thread -> ku . eval . wait_expr ; 
    scheme_current_thread -> ku . eval . wait_expr = ((void * ) 0 ) ; 
    goto eval_top ; 
  }
  returnv : if (((v ) == (((Scheme_Object * ) 0x6 ) ) ) )
    if (get_value > 0 ) {
#   define XfOrM1026_COUNT (0+XfOrM1025_COUNT)
#   define SETUP_XfOrM1026(x) SETUP_XfOrM1025(x)
    FUNCCALL(SETUP_XfOrM1026(_), scheme_wrong_return_arity (((void * ) 0 ) , 1 , scheme_current_thread -> ku . multiple . count , scheme_current_thread -> ku . multiple . array , ((void * ) 0 ) ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  returnv_never_multi : scheme_current_runstack = old_runstack ; 
  scheme_current_cont_mark_stack = old_cont_mark_stack ; 
  scheme_current_cont_mark_pos -= 2 ; 
  ; 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_eval (Scheme_Object * obj , Scheme_Env * env ) {
  Scheme_Object * __funcarg114 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(env, 0)));
# define XfOrM1207_COUNT (1)
# define SETUP_XfOrM1207(x) SETUP(XfOrM1207_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg114 = FUNCCALL(SETUP_XfOrM1207(_), scheme_compile_for_eval (obj , env ) ), FUNCCALL_EMPTY(scheme_eval_compiled (__funcarg114 , env ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_eval_multi (Scheme_Object * obj , Scheme_Env * env ) {
  Scheme_Object * __funcarg115 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(env, 0)));
# define XfOrM1208_COUNT (1)
# define SETUP_XfOrM1208(x) SETUP(XfOrM1208_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg115 = FUNCCALL(SETUP_XfOrM1208(_), scheme_compile_for_eval (obj , env ) ), FUNCCALL_EMPTY(scheme_eval_compiled_multi (__funcarg115 , env ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * finish_eval_with_prompt (void * _data , int argc , Scheme_Object * * argv ) {
  /* No conversion */
  Scheme_Object * data = (Scheme_Object * ) _data ; 
  return _scheme_eval_compiled ((((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) , (Scheme_Env * ) (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ) ; 
}
Scheme_Object * scheme_eval_with_prompt (Scheme_Object * obj , Scheme_Env * env ) {
  Scheme_Object * expr ; 
  Scheme_Object * __funcarg116 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(expr, 1)));
# define XfOrM1210_COUNT (2)
# define SETUP_XfOrM1210(x) SETUP(XfOrM1210_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  expr = NULLED_OUT ; 
  expr = FUNCCALL(SETUP_XfOrM1210(_), scheme_compile_for_eval (obj , env ) ); 
  RET_VALUE_START ((__funcarg116 = FUNCCALL_EMPTY(scheme_make_pair (expr , (Scheme_Object * ) env ) ), FUNCCALL_EMPTY(scheme_call_with_prompt (finish_eval_with_prompt , __funcarg116 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * finish_eval_multi_with_prompt (void * _data , int argc , Scheme_Object * * argv ) {
  /* No conversion */
  Scheme_Object * data = (Scheme_Object * ) _data ; 
  return _scheme_eval_compiled_multi ((((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) , (Scheme_Env * ) (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ) ; 
}
Scheme_Object * scheme_eval_multi_with_prompt (Scheme_Object * obj , Scheme_Env * env ) {
  Scheme_Object * expr ; 
  Scheme_Object * __funcarg117 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(expr, 1)));
# define XfOrM1212_COUNT (2)
# define SETUP_XfOrM1212(x) SETUP(XfOrM1212_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  expr = NULLED_OUT ; 
  expr = FUNCCALL(SETUP_XfOrM1212(_), scheme_compile_for_eval (obj , env ) ); 
  RET_VALUE_START ((__funcarg117 = FUNCCALL_EMPTY(scheme_make_pair (expr , (Scheme_Object * ) env ) ), FUNCCALL_EMPTY(scheme_call_with_prompt (finish_eval_multi_with_prompt , __funcarg117 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void * eval_k (void ) {
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * v , * * save_runstack ; 
  Scheme_Env * env ; 
  int isexpr , multi , use_jit , as_tail ; 
  Scheme_Config * __funcarg118 = NULLED_OUT ; 
  DECL_RET_SAVE (void * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(save_runstack, 1), PUSH(env, 2), PUSH(p, 3)));
# define XfOrM1213_COUNT (4)
# define SETUP_XfOrM1213(x) SETUP(XfOrM1213_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  v = NULLED_OUT ; 
  save_runstack = NULLED_OUT ; 
  env = NULLED_OUT ; 
  v = (Scheme_Object * ) p -> ku . k . p1 ; 
  env = (Scheme_Env * ) p -> ku . k . p2 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  p -> ku . k . p2 = ((void * ) 0 ) ; 
  multi = p -> ku . k . i1 ; 
  isexpr = p -> ku . k . i2 ; 
  as_tail = p -> ku . k . i3 ; 
  {
    Scheme_Object * b ; 
    BLOCK_SETUP((PUSH(b, 0+XfOrM1213_COUNT)));
#   define XfOrM1221_COUNT (1+XfOrM1213_COUNT)
#   define SETUP_XfOrM1221(x) SETUP(XfOrM1221_COUNT)
    b = NULLED_OUT ; 
    b = (__funcarg118 = FUNCCALL(SETUP_XfOrM1221(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg118 , MZCONFIG_USE_JIT ) )) ; 
    use_jit = (! (((b ) ) == (scheme_false ) ) ) ; 
  }
  if (isexpr ) {
#   define XfOrM1220_COUNT (0+XfOrM1213_COUNT)
#   define SETUP_XfOrM1220(x) SETUP_XfOrM1213(x)
    if (multi )
      v = FUNCCALL(SETUP_XfOrM1220(_), scheme_do_eval (v , - 1 , ((void * ) 0 ) , - 1 ) ); 
    else v = FUNCCALL(SETUP_XfOrM1220(_), scheme_do_eval (v , - 1 , ((void * ) 0 ) , 1 ) ); 
  }
  else if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_compilation_top_type ) ) ) {
    Scheme_Compilation_Top * top = (Scheme_Compilation_Top * ) v ; 
    int depth ; 
    BLOCK_SETUP((PUSH(top, 0+XfOrM1213_COUNT)));
#   define XfOrM1215_COUNT (1+XfOrM1213_COUNT)
#   define SETUP_XfOrM1215(x) SETUP(XfOrM1215_COUNT)
    depth = top -> max_let_depth + FUNCCALL(SETUP_XfOrM1215(_), scheme_prefix_depth (top -> prefix ) ); 
    if (! FUNCCALL(SETUP_XfOrM1215(_), scheme_check_runstack (depth ) )) {
#     define XfOrM1219_COUNT (0+XfOrM1215_COUNT)
#     define SETUP_XfOrM1219(x) SETUP_XfOrM1215(x)
      p -> ku . k . p1 = top ; 
      p -> ku . k . p2 = env ; 
      p -> ku . k . i1 = multi ; 
      p -> ku . k . i2 = 0 ; 
      RET_VALUE_START ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM1219(_), scheme_enlarge_runstack (depth , eval_k ) )) RET_VALUE_END ; 
    }
    v = top -> code ; 
    if (use_jit )
      v = FUNCCALL(SETUP_XfOrM1215(_), scheme_jit_expr (v ) ); 
    save_runstack = FUNCCALL(SETUP_XfOrM1215(_), scheme_push_prefix (env , top -> prefix , ((void * ) 0 ) , ((void * ) 0 ) , 0 , env -> phase ) ); 
    if (as_tail ) {
      Scheme_Closure_Data * data ; 
      mzshort * map ; 
      int i , sz ; 
      BLOCK_SETUP((PUSH(map, 0+XfOrM1215_COUNT), PUSH(data, 1+XfOrM1215_COUNT)));
#     define XfOrM1216_COUNT (2+XfOrM1215_COUNT)
#     define SETUP_XfOrM1216(x) SETUP(XfOrM1216_COUNT)
      data = NULLED_OUT ; 
      map = NULLED_OUT ; 
      sz = (save_runstack XFORM_OK_MINUS scheme_current_runstack ) ; 
      map = (mzshort * ) FUNCCALL(SETUP_XfOrM1216(_), GC_malloc_atomic (sizeof (mzshort ) * sz ) ); 
      for (i = 0 ; i < sz ; i ++ ) {
        map [i ] = i ; 
      }
      data = ((Scheme_Closure_Data * ) FUNCCALL(SETUP_XfOrM1216(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Closure_Data ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
      data -> iso . so . type = scheme_compiled_unclosed_procedure_type ; 
      data -> num_params = 0 ; 
      data -> max_let_depth = top -> max_let_depth + sz ; 
      data -> closure_size = sz ; 
      data -> closure_map = map ; 
      data -> code = v ; 
      v = FUNCCALL(SETUP_XfOrM1216(_), scheme_make_closure (p , (Scheme_Object * ) data , 1 ) ); 
      v = FUNCCALL_AGAIN(scheme_tail_apply (v , 0 , ((void * ) 0 ) ) ); 
    }
    else if (multi )
      v = FUNCCALL(SETUP_XfOrM1215(_), scheme_do_eval (v , - 1 , ((void * ) 0 ) , - 1 ) ); 
    else v = FUNCCALL(SETUP_XfOrM1215(_), scheme_do_eval (v , - 1 , ((void * ) 0 ) , 1 ) ); 
    FUNCCALL(SETUP_XfOrM1215(_), scheme_pop_prefix (save_runstack ) ); 
  }
  else {
    v = scheme_void ; 
  }
  RET_VALUE_START ((void * ) v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * _eval (Scheme_Object * obj , Scheme_Env * env , int isexpr , int multi , int top , int as_tail ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  p -> ku . k . p1 = obj ; 
  p -> ku . k . p2 = env ; 
  p -> ku . k . i1 = multi ; 
  p -> ku . k . i2 = isexpr ; 
  p -> ku . k . i3 = as_tail ; 
  if (top )
    return (Scheme_Object * ) scheme_top_level_do (eval_k , 1 ) ; 
  else return (Scheme_Object * ) eval_k () ; 
}
Scheme_Object * scheme_eval_compiled (Scheme_Object * obj , Scheme_Env * env ) {
  /* No conversion */
  return _eval (obj , env , 0 , 0 , 1 , 0 ) ; 
}
Scheme_Object * scheme_eval_compiled_multi (Scheme_Object * obj , Scheme_Env * env ) {
  /* No conversion */
  return _eval (obj , env , 0 , 1 , 1 , 0 ) ; 
}
Scheme_Object * _scheme_eval_compiled (Scheme_Object * obj , Scheme_Env * env ) {
  /* No conversion */
  return _eval (obj , env , 0 , 0 , 0 , 0 ) ; 
}
Scheme_Object * _scheme_eval_compiled_multi (Scheme_Object * obj , Scheme_Env * env ) {
  /* No conversion */
  return _eval (obj , env , 0 , 1 , 0 , 0 ) ; 
}
static Scheme_Object * finish_compiled_multi_with_prompt (void * _data , int argc , Scheme_Object * * argv ) {
  /* No conversion */
  Scheme_Object * data = (Scheme_Object * ) _data ; 
  return _eval ((((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) , (Scheme_Env * ) (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) , 0 , 1 , 0 , 0 ) ; 
}
Scheme_Object * _eval_compiled_multi_with_prompt (Scheme_Object * obj , Scheme_Env * env ) {
  Scheme_Object * __funcarg119 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(0);
# define XfOrM1228_COUNT (0)
# define SETUP_XfOrM1228(x) SETUP(XfOrM1228_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg119 = FUNCCALL_EMPTY(scheme_make_pair (obj , (Scheme_Object * ) env ) ), FUNCCALL_EMPTY(_scheme_call_with_prompt_multi (finish_compiled_multi_with_prompt , __funcarg119 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_eval_linked_expr (Scheme_Object * obj ) {
  /* No conversion */
  return _eval (obj , ((void * ) 0 ) , 1 , 0 , 1 , 0 ) ; 
}
Scheme_Object * scheme_eval_linked_expr_multi (Scheme_Object * obj ) {
  /* No conversion */
  return _eval (obj , ((void * ) 0 ) , 1 , 1 , 1 , 0 ) ; 
}
Scheme_Object * scheme_load_compiled_stx_string (const char * str , long len ) {
  Scheme_Object * port , * expr ; 
  Scheme_Env * __funcarg120 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(expr, 0), PUSH(port, 1)));
# define XfOrM1231_COUNT (2)
# define SETUP_XfOrM1231(x) SETUP(XfOrM1231_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  port = NULLED_OUT ; 
  expr = NULLED_OUT ; 
  port = FUNCCALL(SETUP_XfOrM1231(_), scheme_make_sized_byte_string_input_port (str , - len ) ); 
  expr = FUNCCALL_AGAIN(scheme_internal_read (port , ((void * ) 0 ) , 1 , 0 , 0 , 0 , 0 , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
  expr = (__funcarg120 = FUNCCALL(SETUP_XfOrM1231(_), scheme_get_env (((void * ) 0 ) ) ), FUNCCALL_AGAIN(_scheme_eval_compiled (expr , __funcarg120 ) )) ; 
  expr = ((Scheme_Stx * ) expr ) -> val ; 
  RET_VALUE_START (expr ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_compiled_stx_symbol (Scheme_Object * stx ) {
  /* No conversion */
  return ((Scheme_Stx * ) stx ) -> val ; 
}
Scheme_Object * scheme_eval_compiled_stx_string (Scheme_Object * expr , Scheme_Env * env , long shift , Scheme_Object * modidx ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(expr, 1), PUSH(modidx, 2)));
# define XfOrM1233_COUNT (3)
# define SETUP_XfOrM1233(x) SETUP(XfOrM1233_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (modidx ) {
    int i , len = (((Scheme_Vector * ) (expr ) ) -> size ) ; 
    Scheme_Object * orig = (((Scheme_Vector * ) (expr ) ) -> els ) [len - 1 ] , * s , * result ; 
    BLOCK_SETUP((PUSH(result, 0+XfOrM1233_COUNT), PUSH(s, 1+XfOrM1233_COUNT), PUSH(orig, 2+XfOrM1233_COUNT)));
#   define XfOrM1234_COUNT (3+XfOrM1233_COUNT)
#   define SETUP_XfOrM1234(x) SETUP(XfOrM1234_COUNT)
    s = NULLED_OUT ; 
    result = NULLED_OUT ; 
    orig = ((Scheme_Stx * ) orig ) -> val ; 
    result = FUNCCALL(SETUP_XfOrM1234(_), scheme_make_vector (len - 1 , ((void * ) 0 ) ) ); 
    for (i = 0 ; i < len - 1 ; i ++ ) {
#     define XfOrM1236_COUNT (0+XfOrM1234_COUNT)
#     define SETUP_XfOrM1236(x) SETUP_XfOrM1234(x)
      s = FUNCCALL(SETUP_XfOrM1236(_), scheme_stx_phase_shift ((((Scheme_Vector * ) (expr ) ) -> els ) [i ] , shift , orig , modidx , env -> export_registry ) ); 
      (((Scheme_Vector * ) (result ) ) -> els ) [i ] = s ; 
    }
    RET_VALUE_START (result ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (expr ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void * expand_k (void ) {
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * obj , * certs , * observer , * catch_lifts_key ; 
  Scheme_Comp_Env * env ; 
  Scheme_Expand_Info erec1 ; 
  int depth , rename , just_to_top ; 
  Scheme_Object * __funcarg128 = NULLED_OUT ; 
  Scheme_Object * __funcarg127 = NULLED_OUT ; 
  Scheme_Object * __funcarg126 = NULLED_OUT ; 
  Scheme_Object * __funcarg125 = NULLED_OUT ; 
  DECL_RET_SAVE (void * ) PREPARE_VAR_STACK(9);
  BLOCK_SETUP_TOP((PUSH(catch_lifts_key, 0), PUSH(obj, 1), PUSH(erec1.value_name, 2), PUSH(erec1.certs, 3), PUSH(erec1.observer, 4), PUSH(certs, 5), PUSH(env, 6), PUSH(observer, 7)));
# define XfOrM1237_COUNT (8)
# define SETUP_XfOrM1237(x) SETUP(XfOrM1237_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  obj = NULLED_OUT ; 
  certs = NULLED_OUT ; 
  observer = NULLED_OUT ; 
  catch_lifts_key = NULLED_OUT ; 
  env = NULLED_OUT ; 
  erec1.value_name = NULLED_OUT ; 
  erec1.certs = NULLED_OUT ; 
  erec1.observer = NULLED_OUT ; 
  obj = (Scheme_Object * ) p -> ku . k . p1 ; 
  env = (Scheme_Comp_Env * ) p -> ku . k . p2 ; 
  depth = p -> ku . k . i1 ; 
  rename = p -> ku . k . i2 ; 
  just_to_top = p -> ku . k . i3 ; 
  catch_lifts_key = p -> ku . k . p4 ; 
  certs = (Scheme_Object * ) p -> ku . k . p3 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  p -> ku . k . p2 = ((void * ) 0 ) ; 
  p -> ku . k . p3 = ((void * ) 0 ) ; 
  p -> ku . k . p4 = ((void * ) 0 ) ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    obj = FUNCCALL(SETUP_XfOrM1237(_), scheme_datum_to_syntax (obj , scheme_false , scheme_false , 1 , 0 ) ); 
  if (rename > 0 ) {
#   define XfOrM1253_COUNT (0+XfOrM1237_COUNT)
#   define SETUP_XfOrM1253(x) SETUP_XfOrM1237(x)
    obj = FUNCCALL(SETUP_XfOrM1253(_), add_renames_unless_module (obj , env -> genv ) ); 
  }
  observer = FUNCCALL(SETUP_XfOrM1237(_), scheme_get_expand_observe () ); 
  if (observer ) {
#   define XfOrM1252_COUNT (0+XfOrM1237_COUNT)
#   define SETUP_XfOrM1252(x) SETUP_XfOrM1237(x)
    FUNCCALL(SETUP_XfOrM1252(_), scheme_call_expand_observe (observer , 141 , scheme_false ) ); 
  }
  else {
  }
  ; 
  while (1 ) {
#   define XfOrM1245_COUNT (0+XfOrM1237_COUNT)
#   define SETUP_XfOrM1245(x) SETUP_XfOrM1237(x)
    erec1 . comp = 0 ; 
    erec1 . depth = depth ; 
    erec1 . value_name = scheme_false ; 
    erec1 . certs = certs ; 
    erec1 . observer = observer ; 
    if (catch_lifts_key )
      (__funcarg128 = FUNCCALL(SETUP_XfOrM1245(_), scheme_sys_wraps (env ) ), FUNCCALL_AGAIN(scheme_frame_captures_lifts (env , scheme_make_lifted_defn , __funcarg128 , scheme_false , catch_lifts_key ) )) ; 
    if (just_to_top ) {
      Scheme_Object * gval ; 
      BLOCK_SETUP((PUSH(gval, 0+XfOrM1245_COUNT)));
#     define XfOrM1250_COUNT (1+XfOrM1245_COUNT)
#     define SETUP_XfOrM1250(x) SETUP(XfOrM1250_COUNT)
      gval = NULLED_OUT ; 
      obj = FUNCCALL(SETUP_XfOrM1250(_), scheme_check_immediate_macro (obj , env , & erec1 , 0 , 0 , & gval , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
    }
    else obj = FUNCCALL(SETUP_XfOrM1245(_), scheme_expand_expr (obj , env , & erec1 , 0 ) ); 
    if (catch_lifts_key ) {
      Scheme_Object * l ; 
      BLOCK_SETUP((PUSH(l, 0+XfOrM1245_COUNT)));
#     define XfOrM1246_COUNT (1+XfOrM1245_COUNT)
#     define SETUP_XfOrM1246(x) SETUP(XfOrM1246_COUNT)
      l = NULLED_OUT ; 
      l = FUNCCALL(SETUP_XfOrM1246(_), scheme_frame_get_lifts (env ) ); 
      if (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#       define XfOrM1247_COUNT (0+XfOrM1246_COUNT)
#       define SETUP_XfOrM1247(x) SETUP_XfOrM1246(x)
        obj = (__funcarg127 = FUNCCALL(SETUP_XfOrM1247(_), scheme_make_immutable_pair (obj , scheme_null ) ), FUNCCALL_AGAIN(scheme_append (l , __funcarg127 ) )) ; 
        obj = (__funcarg125 = (__funcarg126 = FUNCCALL(SETUP_XfOrM1247(_), scheme_sys_wraps (env ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (begin_symbol , scheme_false , __funcarg126 , 0 , 0 ) )) , FUNCCALL_AGAIN(scheme_make_immutable_pair (__funcarg125 , obj ) )) ; 
        obj = FUNCCALL_AGAIN(scheme_datum_to_syntax (obj , scheme_false , scheme_false , 0 , 0 ) ); 
        if (erec1 . observer ) {
#         define XfOrM1249_COUNT (0+XfOrM1247_COUNT)
#         define SETUP_XfOrM1249(x) SETUP_XfOrM1247(x)
          FUNCCALL(SETUP_XfOrM1249(_), scheme_call_expand_observe (erec1 . observer , 128 , obj ) ); 
        }
        else {
        }
        ; 
        if (depth >= 0 )
          break ; 
      }
      else break ; 
    }
    else break ; 
  }
  if (rename && ! just_to_top ) {
  }
  RET_VALUE_START (obj ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * _expand (Scheme_Object * obj , Scheme_Comp_Env * env , int depth , int rename , int just_to_top , Scheme_Object * catch_lifts_key , int eb , Scheme_Object * certs ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  p -> ku . k . p1 = obj ; 
  p -> ku . k . p2 = env ; 
  p -> ku . k . i1 = depth ; 
  p -> ku . k . i2 = rename ; 
  p -> ku . k . i3 = just_to_top ; 
  p -> ku . k . p4 = catch_lifts_key ; 
  p -> ku . k . p3 = certs ; 
  return (Scheme_Object * ) scheme_top_level_do (expand_k , eb ) ; 
}
Scheme_Object * scheme_expand (Scheme_Object * obj , Scheme_Env * env ) {
  Scheme_Comp_Env * __funcarg129 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(obj, 0)));
# define XfOrM1255_COUNT (1)
# define SETUP_XfOrM1255(x) SETUP(XfOrM1255_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg129 = FUNCCALL(SETUP_XfOrM1255(_), scheme_new_expand_env (env , ((void * ) 0 ) , 1 ) ), FUNCCALL_EMPTY(_expand (obj , __funcarg129 , - 1 , 1 , 0 , scheme_true , - 1 , ((void * ) 0 ) ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_tail_eval_expr (Scheme_Object * obj ) {
  /* No conversion */
  return ((scheme_current_thread -> ku . eval . wait_expr ) = obj , ((Scheme_Object * ) 0x2 ) ) ; 
}
static Scheme_Object * sch_eval (const char * who , int argc , Scheme_Object * argv [] ) {
  Scheme_Config * __funcarg133 = NULLED_OUT ; 
  Scheme_Object * __funcarg132 = NULLED_OUT ; 
  Scheme_Config * __funcarg131 = NULLED_OUT ; 
  Scheme_Object * __funcarg130 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(who, 1)));
# define XfOrM1257_COUNT (2)
# define SETUP_XfOrM1257(x) SETUP(XfOrM1257_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (argc == 1 ) {
#   define XfOrM1259_COUNT (0+XfOrM1257_COUNT)
#   define SETUP_XfOrM1259(x) SETUP_XfOrM1257(x)
    RET_VALUE_START ((__funcarg132 = (__funcarg133 = FUNCCALL(SETUP_XfOrM1259(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg133 , MZCONFIG_EVAL_HANDLER ) )) , FUNCCALL_EMPTY(scheme_tail_apply (__funcarg132 , 1 , argv ) )) ) RET_VALUE_END ; 
  }
  else {
    Scheme_Config * config ; 
    BLOCK_SETUP((PUSH(config, 0+XfOrM1257_COUNT)));
#   define XfOrM1258_COUNT (1+XfOrM1257_COUNT)
#   define SETUP_XfOrM1258(x) SETUP(XfOrM1258_COUNT)
    config = NULLED_OUT ; 
    if (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) != scheme_namespace_type )
      FUNCCALL_EMPTY(scheme_wrong_type (who , "namespace" , 1 , argc , argv ) ); 
    config = (__funcarg131 = FUNCCALL(SETUP_XfOrM1258(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_extend_config (__funcarg131 , MZCONFIG_ENV , argv [1 ] ) )) ; 
    FUNCCALL_AGAIN(scheme_set_cont_mark (scheme_parameterization_key , (Scheme_Object * ) config ) ); 
    RET_VALUE_START ((__funcarg130 = FUNCCALL(SETUP_XfOrM1258(_), scheme_get_param (config , MZCONFIG_EVAL_HANDLER ) ), FUNCCALL_EMPTY(scheme_tail_apply (__funcarg130 , 1 , argv ) )) ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * eval (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * a [2 ] , * form ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSHARRAY(a, 2, 1), PUSH(form, 4)));
# define XfOrM1260_COUNT (5)
# define SETUP_XfOrM1260(x) SETUP(XfOrM1260_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  form = NULLED_OUT ; 
  form = argv [0 ] ; 
  if (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ! ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) form ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) form ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_compilation_top_type ) ) ) {
    Scheme_Env * genv ; 
    BLOCK_SETUP((PUSH(genv, 0+XfOrM1260_COUNT)));
#   define XfOrM1261_COUNT (1+XfOrM1260_COUNT)
#   define SETUP_XfOrM1261(x) SETUP(XfOrM1261_COUNT)
    genv = NULLED_OUT ; 
    if (argc > 1 ) {
#     define XfOrM1262_COUNT (0+XfOrM1261_COUNT)
#     define SETUP_XfOrM1262(x) SETUP_XfOrM1261(x)
      if (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) != scheme_namespace_type )
        FUNCCALL(SETUP_XfOrM1262(_), scheme_wrong_type ("eval" , "namespace" , 1 , argc , argv ) ); 
      genv = (Scheme_Env * ) argv [1 ] ; 
    }
    else genv = FUNCCALL(SETUP_XfOrM1261(_), scheme_get_env (((void * ) 0 ) ) ); 
    form = FUNCCALL(SETUP_XfOrM1261(_), add_renames_unless_module (form , genv ) ); 
  }
  a [0 ] = form ; 
  if (argc > 1 )
    a [1 ] = argv [1 ] ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM1260(_), sch_eval ("eval" , argc , a ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * eval_stx (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ) {
    scheme_wrong_type ("eval-syntax" , "syntax" , 0 , argc , argv ) ; 
    return ((void * ) 0 ) ; 
  }
  return sch_eval ("eval-syntax" , argc , argv ) ; 
}
Scheme_Object * scheme_default_eval_handler (int argc , Scheme_Object * * argv ) {
  Scheme_Env * env ; 
  Scheme_Object * v ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(argv, 1), PUSH(env, 2)));
# define XfOrM1265_COUNT (3)
# define SETUP_XfOrM1265(x) SETUP(XfOrM1265_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  env = NULLED_OUT ; 
  v = NULLED_OUT ; 
  env = FUNCCALL(SETUP_XfOrM1265(_), scheme_get_env (((void * ) 0 ) ) ); 
  v = FUNCCALL_AGAIN(_compile (argv [0 ] , env , 0 , 1 , 0 , 0 ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(_eval (v , env , 0 , 1 , 0 , 1 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_default_compile_handler (int argc , Scheme_Object * * argv ) {
  Scheme_Env * env ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(argv, 1)));
# define XfOrM1266_COUNT (2)
# define SETUP_XfOrM1266(x) SETUP(XfOrM1266_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  env = NULLED_OUT ; 
  env = FUNCCALL(SETUP_XfOrM1266(_), scheme_get_env (((void * ) 0 ) ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(_compile (argv [0 ] , env , (((argv [1 ] ) ) == (scheme_false ) ) , 0 , 0 , 0 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * current_eval (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return scheme_param_config ("current-eval" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_EVAL_HANDLER ) ) << 1 ) | 0x1 ) ) , argc , argv , 1 , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ; 
}
static Scheme_Object * current_compile (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return scheme_param_config ("current-compile" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_COMPILE_HANDLER ) ) << 1 ) | 0x1 ) ) , argc , argv , 2 , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ; 
}
static Scheme_Object * top_introduce_stx (int argc , Scheme_Object * * argv ) {
  Scheme_Object * form ; 
  Scheme_Config * __funcarg134 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(form, 0)));
# define XfOrM1269_COUNT (1)
# define SETUP_XfOrM1269(x) SETUP(XfOrM1269_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  form = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ) {
#   define XfOrM1271_COUNT (0+XfOrM1269_COUNT)
#   define SETUP_XfOrM1271(x) SETUP_XfOrM1269(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("namespace-syntax-introduce" , "syntax" , 0 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  form = argv [0 ] ; 
  if (! ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) form ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) form ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_compilation_top_type ) ) ) {
    Scheme_Env * genv ; 
    BLOCK_SETUP((PUSH(genv, 0+XfOrM1269_COUNT)));
#   define XfOrM1270_COUNT (1+XfOrM1269_COUNT)
#   define SETUP_XfOrM1270(x) SETUP(XfOrM1270_COUNT)
    genv = NULLED_OUT ; 
    genv = (Scheme_Env * ) (__funcarg134 = FUNCCALL(SETUP_XfOrM1270(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg134 , MZCONFIG_ENV ) )) ; 
    form = FUNCCALL(SETUP_XfOrM1270(_), add_renames_unless_module (form , genv ) ); 
  }
  RET_VALUE_START (form ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * compile (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * form = argv [0 ] ; 
  Scheme_Env * genv ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(genv, 0), PUSH(form, 1)));
# define XfOrM1272_COUNT (2)
# define SETUP_XfOrM1272(x) SETUP(XfOrM1272_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  genv = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    form = FUNCCALL(SETUP_XfOrM1272(_), scheme_datum_to_syntax (form , scheme_false , scheme_false , 1 , 0 ) ); 
  genv = FUNCCALL(SETUP_XfOrM1272(_), scheme_get_env (((void * ) 0 ) ) ); 
  form = FUNCCALL_AGAIN(add_renames_unless_module (form , genv ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(call_compile_handler (form , 0 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * compile_stx (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    scheme_wrong_type ("compile-syntax" , "syntax" , 0 , argc , argv ) ; 
  return call_compile_handler (argv [0 ] , 0 ) ; 
}
static Scheme_Object * compiled_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_compilation_top_type ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * expand (int argc , Scheme_Object * * argv ) {
  Scheme_Env * env ; 
  Scheme_Comp_Env * __funcarg135 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(argv, 1)));
# define XfOrM1275_COUNT (2)
# define SETUP_XfOrM1275(x) SETUP(XfOrM1275_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  env = NULLED_OUT ; 
  env = FUNCCALL(SETUP_XfOrM1275(_), scheme_get_env (((void * ) 0 ) ) ); 
  RET_VALUE_START ((__funcarg135 = FUNCCALL(SETUP_XfOrM1275(_), scheme_new_expand_env (env , ((void * ) 0 ) , 1 ) ), FUNCCALL_EMPTY(_expand (argv [0 ] , __funcarg135 , - 1 , 1 , 0 , scheme_true , 0 , ((void * ) 0 ) ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * expand_stx (int argc , Scheme_Object * * argv ) {
  Scheme_Env * env ; 
  Scheme_Comp_Env * __funcarg136 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(argv, 1)));
# define XfOrM1276_COUNT (2)
# define SETUP_XfOrM1276(x) SETUP(XfOrM1276_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  env = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("expand-syntax" , "syntax" , 0 , argc , argv ) ); 
  env = FUNCCALL(SETUP_XfOrM1276(_), scheme_get_env (((void * ) 0 ) ) ); 
  RET_VALUE_START ((__funcarg136 = FUNCCALL(SETUP_XfOrM1276(_), scheme_new_expand_env (env , ((void * ) 0 ) , 1 ) ), FUNCCALL_EMPTY(_expand (argv [0 ] , __funcarg136 , - 1 , - 1 , 0 , scheme_true , 0 , ((void * ) 0 ) ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * stop_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  /* No conversion */
  scheme_signal_error ("internal error: shouldn't get to stop syntax" ) ; 
  return ((void * ) 0 ) ; 
}
static Scheme_Object * stop_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(form, 0)));
# define XfOrM1278_COUNT (1)
# define SETUP_XfOrM1278(x) SETUP(XfOrM1278_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (erec [drec ] . observer ) {
#   define XfOrM1280_COUNT (0+XfOrM1278_COUNT)
#   define SETUP_XfOrM1280(x) SETUP_XfOrM1278(x)
    FUNCCALL(SETUP_XfOrM1280(_), scheme_call_expand_observe (erec [drec ] . observer , 100 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  RET_VALUE_START (form ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_get_stop_expander (void ) {
  /* No conversion */
  if (! stop_expander ) {
    scheme_register_static ((void * ) & stop_expander , sizeof (stop_expander ) ) ; 
    stop_expander = scheme_make_compiled_syntax (stop_syntax , stop_expand ) ; 
  }
  return stop_expander ; 
}
Scheme_Object * scheme_generate_lifts_key (void ) {
  /* No conversion */
  static int cnt = 0 ; 
  char buf [20 ] ; 
  sprintf (buf , "lifts%d" , cnt ++ ) ; 
  return scheme_make_symbol (buf ) ; 
}
Scheme_Object * scheme_make_lifted_defn (Scheme_Object * sys_wraps , Scheme_Object * * _id , Scheme_Object * expr , Scheme_Comp_Env * env ) {
  Scheme_Object * l ; 
  Scheme_Object * __funcarg140 = NULLED_OUT ; 
  Scheme_Object * __funcarg139 = NULLED_OUT ; 
  Scheme_Object * __funcarg138 = NULLED_OUT ; 
  Scheme_Object * __funcarg137 = NULLED_OUT ; 
  PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(__funcarg139, 0), PUSH(_id, 1), PUSH(expr, 2), PUSH(__funcarg137, 3), PUSH(l, 4), PUSH(sys_wraps, 5)));
# define XfOrM1284_COUNT (6)
# define SETUP_XfOrM1284(x) SETUP(XfOrM1284_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  l = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM1284(_), scheme_tl_id_sym (env -> genv , * _id , scheme_false , 2 ) ); 
  l = (__funcarg137 = FUNCCALL(SETUP_XfOrM1284(_), scheme_datum_to_syntax (define_values_symbol , scheme_false , sys_wraps , 0 , 0 ) ), __funcarg138 = (__funcarg139 = FUNCCALL(SETUP_XfOrM1284(_), scheme_make_immutable_pair (* _id , scheme_null ) ), __funcarg140 = FUNCCALL(SETUP_XfOrM1284(_), scheme_make_immutable_pair (expr , scheme_null ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (__funcarg139 , __funcarg140 ) )) , FUNCCALL_AGAIN(scheme_make_immutable_pair (__funcarg137 , __funcarg138 ) )) ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_datum_to_syntax (l , scheme_false , scheme_false , 0 , 0 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_local_expand (const char * name , int for_stx , int catch_lifts , int for_expr , int argc , Scheme_Object * * argv ) {
  Scheme_Comp_Env * env , * orig_env ; 
  Scheme_Object * l , * local_mark , * renaming = ((void * ) 0 ) , * orig_l , * exp_expr = ((void * ) 0 ) ; 
  int cnt , pos , kind ; 
  int bad_sub_env = 0 ; 
  Scheme_Object * observer , * catch_lifts_key = ((void * ) 0 ) ; 
  Scheme_Object * __funcarg141 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(16);
  BLOCK_SETUP_TOP((PUSH(l, 0), PUSH(argv, 1), PUSH(observer, 2), PUSH(exp_expr, 3), PUSH(name, 4), PUSH(env, 5), PUSH(renaming, 6), PUSH(catch_lifts_key, 7), PUSH(local_mark, 8), PUSH(orig_env, 9), PUSH(orig_l, 10)));
# define XfOrM1285_COUNT (11)
# define SETUP_XfOrM1285(x) SETUP(XfOrM1285_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  env = NULLED_OUT ; 
  orig_env = NULLED_OUT ; 
  l = NULLED_OUT ; 
  local_mark = NULLED_OUT ; 
  orig_l = NULLED_OUT ; 
  observer = NULLED_OUT ; 
  env = scheme_current_thread -> current_local_env ; 
  orig_env = env ; 
  if (! env )
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: not currently transforming" , name ) ); 
  if (for_stx ) {
#   define XfOrM1329_COUNT (0+XfOrM1285_COUNT)
#   define SETUP_XfOrM1329(x) SETUP_XfOrM1285(x)
    FUNCCALL(SETUP_XfOrM1329(_), scheme_prepare_exp_env (env -> genv ) ); 
    env = FUNCCALL(SETUP_XfOrM1329(_), scheme_new_comp_env (env -> genv -> exp_env , env -> insp , 0 ) ); 
  }
  if (for_expr )
    kind = 0 ; 
  else if (((argv [1 ] ) == (module_symbol ) ) )
    kind = 4 ; 
  else if (((argv [1 ] ) == (module_begin_symbol ) ) )
    kind = 2 ; 
  else if (((argv [1 ] ) == (top_level_symbol ) ) )
    kind = 1 ; 
  else if (((argv [1 ] ) == (expression_symbol ) ) )
    kind = 0 ; 
  else if (FUNCCALL(SETUP_XfOrM1285(_), scheme_proper_list_length (argv [1 ] ) )> 0 )
    kind = 16 ; 
  else {
#   define XfOrM1328_COUNT (0+XfOrM1285_COUNT)
#   define SETUP_XfOrM1328(x) SETUP_XfOrM1285(x)
    FUNCCALL_EMPTY(scheme_wrong_type (name , "'expression, 'module, 'module-begin, 'top-level, or non-empty list" , 1 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (argc > 3 ) {
#   define XfOrM1324_COUNT (0+XfOrM1285_COUNT)
#   define SETUP_XfOrM1324(x) SETUP_XfOrM1285(x)
    if ((! (((argv [3 ] ) ) == (scheme_false ) ) ) ) {
#     define XfOrM1326_COUNT (0+XfOrM1324_COUNT)
#     define SETUP_XfOrM1326(x) SETUP_XfOrM1324(x)
      if (((Scheme_Type ) (scheme_intdef_context_type ) == (Scheme_Type ) (((((long ) (argv [3 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [3 ] ) ) -> type ) ) ) ) {
        Scheme_Comp_Env * stx_env ; 
        BLOCK_SETUP((PUSH(stx_env, 0+XfOrM1326_COUNT)));
#       define XfOrM1327_COUNT (1+XfOrM1326_COUNT)
#       define SETUP_XfOrM1327(x) SETUP(XfOrM1327_COUNT)
        stx_env = NULLED_OUT ; 
        stx_env = (Scheme_Comp_Env * ) (((Scheme_Simple_Object * ) (argv [3 ] ) ) -> u . two_ptr_val . ptr1 ) ; 
        renaming = (((Scheme_Simple_Object * ) (argv [3 ] ) ) -> u . two_ptr_val . ptr2 ) ; 
        if (! FUNCCALL(SETUP_XfOrM1327(_), scheme_is_sub_env (stx_env , env ) ))
          bad_sub_env = 1 ; 
        env = stx_env ; 
      }
    }
    if (argc > 4 ) {
      catch_lifts_key = argv [4 ] ; 
    }
  }
  if (catch_lifts && ! catch_lifts_key )
    catch_lifts_key = FUNCCALL(SETUP_XfOrM1285(_), scheme_generate_lifts_key () ); 
  (void ) FUNCCALL(SETUP_XfOrM1285(_), scheme_get_stop_expander () ); 
  env = FUNCCALL(SETUP_XfOrM1285(_), scheme_new_compilation_frame (0 , (64 | 128 | kind ) , env , ((void * ) 0 ) ) ); 
  if (kind == 16 )
    env -> intdef_name = argv [1 ] ; 
  env -> in_modidx = scheme_current_thread -> current_local_modidx ; 
  local_mark = scheme_current_thread -> current_local_mark ; 
  if (for_expr ) {
  }
  else if ((! (((argv [2 ] ) ) == (scheme_false ) ) ) ) {
#   define XfOrM1317_COUNT (0+XfOrM1285_COUNT)
#   define SETUP_XfOrM1317(x) SETUP_XfOrM1285(x)
    cnt = FUNCCALL(SETUP_XfOrM1317(_), scheme_stx_proper_list_length (argv [2 ] ) ); 
    if (cnt > 0 )
      FUNCCALL(SETUP_XfOrM1317(_), scheme_add_local_syntax (cnt , env ) ); 
    pos = 0 ; 
    for (l = argv [2 ] ; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
      Scheme_Object * i ; 
      BLOCK_SETUP((PUSH(i, 0+XfOrM1317_COUNT)));
#     define XfOrM1321_COUNT (1+XfOrM1317_COUNT)
#     define SETUP_XfOrM1321(x) SETUP(XfOrM1321_COUNT)
      i = NULLED_OUT ; 
      i = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
      if (! (((Scheme_Type ) (((((long ) (i ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (i ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (i ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (i ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) i ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) i ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) ) {
#       define XfOrM1322_COUNT (0+XfOrM1321_COUNT)
#       define SETUP_XfOrM1322(x) SETUP_XfOrM1321(x)
        FUNCCALL_EMPTY(scheme_wrong_type (name , "#f or list of identifier syntax" , 2 , argc , argv ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      if (cnt > 0 )
        FUNCCALL(SETUP_XfOrM1321(_), scheme_set_local_syntax (pos ++ , i , stop_expander , env ) ); 
    }
    if (! ((l ) == (scheme_null ) ) ) {
#     define XfOrM1318_COUNT (0+XfOrM1317_COUNT)
#     define SETUP_XfOrM1318(x) SETUP_XfOrM1317(x)
      FUNCCALL_EMPTY(scheme_wrong_type (name , "#f or list of identifier syntax" , 2 , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  if (argc > 3 ) {
#   define XfOrM1312_COUNT (0+XfOrM1285_COUNT)
#   define SETUP_XfOrM1312(x) SETUP_XfOrM1285(x)
    if ((! (((argv [3 ] ) ) == (scheme_false ) ) ) ) {
#     define XfOrM1313_COUNT (0+XfOrM1312_COUNT)
#     define SETUP_XfOrM1313(x) SETUP_XfOrM1312(x)
      if (((Scheme_Type ) (scheme_intdef_context_type ) == (Scheme_Type ) (((((long ) (argv [3 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [3 ] ) ) -> type ) ) ) ) {
#       define XfOrM1315_COUNT (0+XfOrM1313_COUNT)
#       define SETUP_XfOrM1315(x) SETUP_XfOrM1313(x)
        if (bad_sub_env ) {
#         define XfOrM1316_COUNT (0+XfOrM1315_COUNT)
#         define SETUP_XfOrM1316(x) SETUP_XfOrM1315(x)
          FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: transforming context does " "not match internal-definition context at the front of the context list" , name ) ); 
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        }
      }
      else {
#       define XfOrM1314_COUNT (0+XfOrM1313_COUNT)
#       define SETUP_XfOrM1314(x) SETUP_XfOrM1313(x)
        FUNCCALL_EMPTY(scheme_wrong_type (name , "internal-definition context or #f" , 3 , argc , argv ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
    }
  }
  l = argv [0 ] ; 
  if (! ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    l = FUNCCALL(SETUP_XfOrM1285(_), scheme_datum_to_syntax (l , scheme_false , scheme_false , 1 , 0 ) ); 
  orig_l = l ; 
  observer = FUNCCALL(SETUP_XfOrM1285(_), scheme_get_expand_observe () ); 
  if (observer ) {
#   define XfOrM1302_COUNT (0+XfOrM1285_COUNT)
#   define SETUP_XfOrM1302(x) SETUP_XfOrM1285(x)
    if (for_expr ) {
#     define XfOrM1309_COUNT (0+XfOrM1302_COUNT)
#     define SETUP_XfOrM1309(x) SETUP_XfOrM1302(x)
      if (observer ) {
#       define XfOrM1311_COUNT (0+XfOrM1309_COUNT)
#       define SETUP_XfOrM1311(x) SETUP_XfOrM1309(x)
        FUNCCALL(SETUP_XfOrM1311(_), scheme_call_expand_observe (observer , 139 , l ) ); 
      }
      else {
      }
      ; 
    }
    else {
#     define XfOrM1306_COUNT (0+XfOrM1302_COUNT)
#     define SETUP_XfOrM1306(x) SETUP_XfOrM1302(x)
      if (observer ) {
#       define XfOrM1308_COUNT (0+XfOrM1306_COUNT)
#       define SETUP_XfOrM1308(x) SETUP_XfOrM1306(x)
        FUNCCALL(SETUP_XfOrM1308(_), scheme_call_expand_observe (observer , 130 , l ) ); 
      }
      else {
      }
      ; 
    }
    if (for_stx ) {
#     define XfOrM1303_COUNT (0+XfOrM1302_COUNT)
#     define SETUP_XfOrM1303(x) SETUP_XfOrM1302(x)
      if (observer ) {
#       define XfOrM1305_COUNT (0+XfOrM1303_COUNT)
#       define SETUP_XfOrM1305(x) SETUP_XfOrM1303(x)
        FUNCCALL(SETUP_XfOrM1305(_), scheme_call_expand_observe (observer , 20 , ((void * ) 0 ) ) ); 
      }
      else {
      }
      ; 
    }
  }
  if (local_mark ) {
#   define XfOrM1301_COUNT (0+XfOrM1285_COUNT)
#   define SETUP_XfOrM1301(x) SETUP_XfOrM1285(x)
    l = FUNCCALL(SETUP_XfOrM1301(_), scheme_add_remove_mark (l , local_mark ) ); 
  }
  l = FUNCCALL(SETUP_XfOrM1285(_), scheme_stx_activate_certs (l ) ); 
  if (renaming )
    l = FUNCCALL(SETUP_XfOrM1285(_), scheme_add_rename (l , renaming ) ); 
  if (observer ) {
#   define XfOrM1300_COUNT (0+XfOrM1285_COUNT)
#   define SETUP_XfOrM1300(x) SETUP_XfOrM1285(x)
    FUNCCALL(SETUP_XfOrM1300(_), scheme_call_expand_observe (observer , 132 , l ) ); 
  }
  else {
  }
  ; 
  if ((((argv [2 ] ) ) == (scheme_false ) ) ) {
    Scheme_Object * xl , * gval ; 
    Scheme_Compile_Expand_Info drec [1 ] ; 
    BLOCK_SETUP((PUSH(gval, 0+XfOrM1285_COUNT), PUSH(xl, 1+XfOrM1285_COUNT), PUSH(drec[0].value_name, 2+XfOrM1285_COUNT), PUSH(drec[0].certs, 3+XfOrM1285_COUNT), PUSH(drec[0].observer, 4+XfOrM1285_COUNT)));
#   define XfOrM1298_COUNT (5+XfOrM1285_COUNT)
#   define SETUP_XfOrM1298(x) SETUP(XfOrM1298_COUNT)
    xl = NULLED_OUT ; 
    gval = NULLED_OUT ; 
    drec[0].value_name = NULLED_OUT ; 
    drec[0].certs = NULLED_OUT ; 
    drec[0].observer = NULLED_OUT ; 
    (memset (drec , 0 , sizeof (drec ) ) ) ; 
    drec [0 ] . value_name = scheme_false ; 
    drec [0 ] . certs = scheme_current_thread -> current_local_certs ; 
    drec [0 ] . depth = - 2 ; 
    xl = FUNCCALL(SETUP_XfOrM1298(_), scheme_check_immediate_macro (l , env , drec , 0 , 0 , & gval , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
    if (((xl ) == (l ) ) )
      RET_VALUE_START (orig_l ) RET_VALUE_END ; 
    l = xl ; 
  }
  else {
#   define XfOrM1297_COUNT (0+XfOrM1285_COUNT)
#   define SETUP_XfOrM1297(x) SETUP_XfOrM1285(x)
    l = FUNCCALL(SETUP_XfOrM1297(_), _expand (l , env , - 2 , 0 , 0 , catch_lifts_key , 0 , scheme_current_thread -> current_local_certs ) ); 
  }
  if (observer ) {
#   define XfOrM1296_COUNT (0+XfOrM1285_COUNT)
#   define SETUP_XfOrM1296(x) SETUP_XfOrM1285(x)
    FUNCCALL(SETUP_XfOrM1296(_), scheme_call_expand_observe (observer , 133 , l ) ); 
  }
  else {
  }
  ; 
  if (renaming )
    l = FUNCCALL(SETUP_XfOrM1285(_), scheme_add_rename (l , renaming ) ); 
  if (for_expr ) {
#   define XfOrM1292_COUNT (0+XfOrM1285_COUNT)
#   define SETUP_XfOrM1292(x) SETUP_XfOrM1285(x)
    while (1 ) {
      if (orig_env -> flags & 128 )
        orig_env = orig_env -> next ; 
      else if ((orig_env -> flags & 16 ) && ! orig_env -> num_bindings )
        orig_env = orig_env -> next ; 
      else break ; 
    }
    exp_expr = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM1292(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    exp_expr -> type = scheme_expanded_syntax_type ; 
    (((Scheme_Simple_Object * ) (exp_expr ) ) -> u . two_ptr_val . ptr1 ) = l ; 
    (((Scheme_Simple_Object * ) (exp_expr ) ) -> u . two_ptr_val . ptr2 ) = orig_env ; 
    exp_expr = FUNCCALL(SETUP_XfOrM1292(_), scheme_datum_to_syntax (exp_expr , l , scheme_false , 0 , 0 ) ); 
    exp_expr = FUNCCALL_AGAIN(scheme_add_remove_mark (exp_expr , local_mark ) ); 
  }
  if (local_mark ) {
#   define XfOrM1291_COUNT (0+XfOrM1285_COUNT)
#   define SETUP_XfOrM1291(x) SETUP_XfOrM1285(x)
    l = FUNCCALL(SETUP_XfOrM1291(_), scheme_add_remove_mark (l , local_mark ) ); 
  }
  if (for_expr ) {
    Scheme_Object * a [2 ] ; 
    BLOCK_SETUP((PUSHARRAY(a, 2, 0+XfOrM1285_COUNT)));
#   define XfOrM1288_COUNT (3+XfOrM1285_COUNT)
#   define SETUP_XfOrM1288(x) SETUP(XfOrM1288_COUNT)
    a[0] = NULLED_OUT ; 
    a[1] = NULLED_OUT ; 
    if (observer ) {
#     define XfOrM1290_COUNT (0+XfOrM1288_COUNT)
#     define SETUP_XfOrM1290(x) SETUP_XfOrM1288(x)
      (__funcarg141 = FUNCCALL(SETUP_XfOrM1290(_), scheme_make_pair (l , exp_expr ) ), FUNCCALL_AGAIN(scheme_call_expand_observe (observer , 140 , __funcarg141 ) )) ; 
    }
    else {
    }
    ; 
    a [0 ] = l ; 
    a [1 ] = exp_expr ; 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM1288(_), scheme_values (2 , a ) )) RET_VALUE_END ; 
  }
  else if (observer ) {
#   define XfOrM1287_COUNT (0+XfOrM1285_COUNT)
#   define SETUP_XfOrM1287(x) SETUP_XfOrM1285(x)
    FUNCCALL(SETUP_XfOrM1287(_), scheme_call_expand_observe (observer , 131 , l ) ); 
  }
  else {
  }
  ; 
  RET_VALUE_START (l ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * local_expand (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return do_local_expand ("local-expand" , 0 , 0 , 0 , argc , argv ) ; 
}
static Scheme_Object * local_expand_expr (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return do_local_expand ("syntax-local-expand-expression" , 0 , 0 , 1 , argc , argv ) ; 
}
static Scheme_Object * local_transformer_expand (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return do_local_expand ("local-transformer-expand" , 1 , 0 , 0 , argc , argv ) ; 
}
static Scheme_Object * local_expand_catch_lifts (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return do_local_expand ("local-expand/capture-lifts" , 0 , 1 , 0 , argc , argv ) ; 
}
static Scheme_Object * local_transformer_expand_catch_lifts (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return do_local_expand ("local-transformer-expand/capture-lifts" , 1 , 1 , 0 , argc , argv ) ; 
}
static Scheme_Object * expand_once (int argc , Scheme_Object * * argv ) {
  Scheme_Env * env ; 
  Scheme_Comp_Env * __funcarg142 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(argv, 1)));
# define XfOrM1335_COUNT (2)
# define SETUP_XfOrM1335(x) SETUP(XfOrM1335_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  env = NULLED_OUT ; 
  env = FUNCCALL(SETUP_XfOrM1335(_), scheme_get_env (((void * ) 0 ) ) ); 
  RET_VALUE_START ((__funcarg142 = FUNCCALL(SETUP_XfOrM1335(_), scheme_new_expand_env (env , ((void * ) 0 ) , 1 ) ), FUNCCALL_EMPTY(_expand (argv [0 ] , __funcarg142 , 1 , 1 , 0 , scheme_true , 0 , ((void * ) 0 ) ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * expand_stx_once (int argc , Scheme_Object * * argv ) {
  Scheme_Env * env ; 
  Scheme_Comp_Env * __funcarg143 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(argv, 1)));
# define XfOrM1336_COUNT (2)
# define SETUP_XfOrM1336(x) SETUP(XfOrM1336_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  env = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("expand-syntax-once" , "syntax" , 0 , argc , argv ) ); 
  env = FUNCCALL(SETUP_XfOrM1336(_), scheme_get_env (((void * ) 0 ) ) ); 
  RET_VALUE_START ((__funcarg143 = FUNCCALL(SETUP_XfOrM1336(_), scheme_new_expand_env (env , ((void * ) 0 ) , 1 ) ), FUNCCALL_EMPTY(_expand (argv [0 ] , __funcarg143 , 1 , - 1 , 0 , scheme_true , 0 , ((void * ) 0 ) ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * expand_to_top_form (int argc , Scheme_Object * * argv ) {
  Scheme_Env * env ; 
  Scheme_Comp_Env * __funcarg144 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(argv, 1)));
# define XfOrM1337_COUNT (2)
# define SETUP_XfOrM1337(x) SETUP(XfOrM1337_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  env = NULLED_OUT ; 
  env = FUNCCALL(SETUP_XfOrM1337(_), scheme_get_env (((void * ) 0 ) ) ); 
  RET_VALUE_START ((__funcarg144 = FUNCCALL(SETUP_XfOrM1337(_), scheme_new_expand_env (env , ((void * ) 0 ) , 1 ) ), FUNCCALL_EMPTY(_expand (argv [0 ] , __funcarg144 , 1 , 1 , 1 , scheme_true , 0 , ((void * ) 0 ) ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * expand_stx_to_top_form (int argc , Scheme_Object * * argv ) {
  Scheme_Env * env ; 
  Scheme_Comp_Env * __funcarg145 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(argv, 1)));
# define XfOrM1338_COUNT (2)
# define SETUP_XfOrM1338(x) SETUP(XfOrM1338_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  env = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("expand-syntax-to-top" , "syntax" , 0 , argc , argv ) ); 
  env = FUNCCALL(SETUP_XfOrM1338(_), scheme_get_env (((void * ) 0 ) ) ); 
  RET_VALUE_START ((__funcarg145 = FUNCCALL(SETUP_XfOrM1338(_), scheme_new_expand_env (env , ((void * ) 0 ) , 1 ) ), FUNCCALL_EMPTY(_expand (argv [0 ] , __funcarg145 , 1 , - 1 , 1 , scheme_true , 0 , ((void * ) 0 ) ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_eval_string_all (const char * str , Scheme_Env * env , int cont , int w_prompt ) {
  Scheme_Object * port , * expr , * result = scheme_void ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(expr, 1), PUSH(result, 2), PUSH(port, 3)));
# define XfOrM1339_COUNT (4)
# define SETUP_XfOrM1339(x) SETUP(XfOrM1339_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  port = NULLED_OUT ; 
  expr = NULLED_OUT ; 
  port = FUNCCALL(SETUP_XfOrM1339(_), scheme_make_byte_string_input_port (str ) ); 
  do {
#   define XfOrM1343_COUNT (0+XfOrM1339_COUNT)
#   define SETUP_XfOrM1343(x) SETUP_XfOrM1339(x)
    expr = FUNCCALL(SETUP_XfOrM1343(_), scheme_read_syntax (port , scheme_false ) ); 
    if (((expr ) == (scheme_eof ) ) )
      cont = 0 ; 
    else if (cont < 0 ) {
#     define XfOrM1345_COUNT (0+XfOrM1343_COUNT)
#     define SETUP_XfOrM1345(x) SETUP_XfOrM1343(x)
      if (w_prompt )
        result = FUNCCALL(SETUP_XfOrM1345(_), scheme_eval_with_prompt (expr , env ) ); 
      else result = FUNCCALL(SETUP_XfOrM1345(_), scheme_eval (expr , env ) ); 
    }
    else {
#     define XfOrM1344_COUNT (0+XfOrM1343_COUNT)
#     define SETUP_XfOrM1344(x) SETUP_XfOrM1343(x)
      if (w_prompt )
        result = FUNCCALL(SETUP_XfOrM1344(_), scheme_eval_multi_with_prompt (expr , env ) ); 
      else result = FUNCCALL(SETUP_XfOrM1344(_), scheme_eval_multi (expr , env ) ); 
    }
  }
  while (cont > 0 ) ; 
  RET_VALUE_START (result ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_eval_string_all (const char * str , Scheme_Env * env , int cont ) {
  /* No conversion */
  return do_eval_string_all (str , env , cont , 0 ) ; 
}
Scheme_Object * scheme_eval_string (const char * str , Scheme_Env * env ) {
  /* No conversion */
  return do_eval_string_all (str , env , - 1 , 0 ) ; 
}
Scheme_Object * scheme_eval_string_multi (const char * str , Scheme_Env * env ) {
  /* No conversion */
  return do_eval_string_all (str , env , 0 , 0 ) ; 
}
Scheme_Object * scheme_eval_string_all_with_prompt (const char * str , Scheme_Env * env , int cont ) {
  /* No conversion */
  return do_eval_string_all (str , env , cont , 1 ) ; 
}
Scheme_Object * scheme_eval_string_with_prompt (const char * str , Scheme_Env * env ) {
  /* No conversion */
  return do_eval_string_all (str , env , - 1 , 1 ) ; 
}
Scheme_Object * scheme_eval_string_multi_with_prompt (const char * str , Scheme_Env * env ) {
  /* No conversion */
  return do_eval_string_all (str , env , 0 , 1 ) ; 
}
static Scheme_Object * allow_set_undefined (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return scheme_param_config ("compile-allow-set!-undefined" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_ALLOW_SET_UNDEFINED ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ; 
}
static Scheme_Object * compile_module_constants (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return scheme_param_config ("compile-enforce-module-constants" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_COMPILE_MODULE_CONSTS ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ; 
}
static Scheme_Object * use_jit (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return scheme_param_config ("eval-jit-enabled" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_USE_JIT ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ; 
}
static Scheme_Object * enable_break (int argc , Scheme_Object * argv [] ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM1355_COUNT (1)
# define SETUP_XfOrM1355(x) SETUP(XfOrM1355_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (argc == 1 ) {
#   define XfOrM1357_COUNT (0+XfOrM1355_COUNT)
#   define SETUP_XfOrM1357(x) SETUP_XfOrM1355(x)
    FUNCCALL(SETUP_XfOrM1357(_), scheme_set_can_break ((! (((argv [0 ] ) ) == (scheme_false ) ) ) ) ); 
    if ((! (((argv [0 ] ) ) == (scheme_false ) ) ) ) {
#     define XfOrM1358_COUNT (0+XfOrM1357_COUNT)
#     define SETUP_XfOrM1358(x) SETUP_XfOrM1357(x)
      if (scheme_current_thread -> external_break && FUNCCALL_EMPTY(scheme_can_break (scheme_current_thread ) )) {
#       define XfOrM1359_COUNT (0+XfOrM1358_COUNT)
#       define SETUP_XfOrM1359(x) SETUP_XfOrM1358(x)
        FUNCCALL_EMPTY(scheme_thread_block (0.0 ) ); 
        scheme_current_thread -> ran_some = 1 ; 
      }
    }
    RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM1356_COUNT (0+XfOrM1355_COUNT)
#   define SETUP_XfOrM1356(x) SETUP_XfOrM1355(x)
    RET_VALUE_START (FUNCCALL_EMPTY(scheme_can_break (scheme_current_thread ) )? scheme_true : scheme_false ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * local_eval (int argc , Scheme_Object * * argv ) {
  Scheme_Comp_Env * env , * stx_env , * old_stx_env ; 
  Scheme_Object * l , * a , * rib , * expr , * certs , * names ; 
  int cnt = 0 , pos ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(11);
  BLOCK_SETUP_TOP((PUSH(old_stx_env, 0), PUSH(rib, 1), PUSH(argv, 2), PUSH(certs, 3), PUSH(stx_env, 4), PUSH(names, 5), PUSH(expr, 6), PUSH(l, 7)));
# define XfOrM1360_COUNT (8)
# define SETUP_XfOrM1360(x) SETUP(XfOrM1360_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  env = NULLED_OUT ; 
  stx_env = NULLED_OUT ; 
  old_stx_env = NULLED_OUT ; 
  l = NULLED_OUT ; 
  a = NULLED_OUT ; 
  rib = NULLED_OUT ; 
  expr = NULLED_OUT ; 
  certs = NULLED_OUT ; 
  names = NULLED_OUT ; 
  names = argv [0 ] ; 
  for (l = names ; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
    a = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
    if (! (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) a ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) a ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) )
      break ; 
    cnt ++ ; 
  }
  if (! ((l ) == (scheme_null ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("syntax-local-bind-syntaxes" , "list of syntax identifieres" , 0 , argc , argv ) ); 
  expr = argv [1 ] ; 
  if (! (((expr ) ) == (scheme_false ) ) && ! ((Scheme_Type ) (((((long ) (expr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (expr ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("syntax-local-bind-syntaxes" , "syntax or #f" , 1 , argc , argv ) ); 
  if (! ((Scheme_Type ) (scheme_intdef_context_type ) == (Scheme_Type ) (((((long ) (argv [2 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [2 ] ) ) -> type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("syntax-local-bind-syntaxes" , "internal-definition context" , 2 , argc , argv ) ); 
  env = scheme_current_thread -> current_local_env ; 
  if (! env )
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "syntax-local-bind-syntaxes: not currently transforming" ) ); 
  stx_env = (Scheme_Comp_Env * ) (((Scheme_Simple_Object * ) (argv [2 ] ) ) -> u . two_ptr_val . ptr1 ) ; 
  rib = (((Scheme_Simple_Object * ) (argv [2 ] ) ) -> u . two_ptr_val . ptr2 ) ; 
  if (! FUNCCALL(SETUP_XfOrM1360(_), scheme_is_sub_env (stx_env , env ) )) {
#   define XfOrM1364_COUNT (0+XfOrM1360_COUNT)
#   define SETUP_XfOrM1364(x) SETUP_XfOrM1360(x)
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "syntax-local-bind-syntaxes: transforming context does " "not match given internal-definition context" ) ); 
  }
  certs = scheme_current_thread -> current_local_certs ; 
  old_stx_env = stx_env ; 
  stx_env = FUNCCALL(SETUP_XfOrM1360(_), scheme_new_compilation_frame (0 , 256 , stx_env , certs ) ); 
  FUNCCALL_AGAIN(scheme_add_local_syntax (cnt , stx_env ) ); 
  names = FUNCCALL_AGAIN(scheme_named_map_1 (((void * ) 0 ) , scheme_add_remove_mark , names , scheme_current_thread -> current_local_mark ) ); 
  cnt = 0 ; 
  for (l = names ; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#   define XfOrM1363_COUNT (0+XfOrM1360_COUNT)
#   define SETUP_XfOrM1363(x) SETUP_XfOrM1360(x)
    FUNCCALL(SETUP_XfOrM1363(_), scheme_set_local_syntax (cnt ++ , (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) , scheme_false , stx_env ) ); 
  }
  stx_env -> in_modidx = scheme_current_thread -> current_local_modidx ; 
  if (! (((expr ) ) == (scheme_false ) ) ) {
    Scheme_Compile_Expand_Info rec ; 
    BLOCK_SETUP((PUSH(rec.value_name, 0+XfOrM1360_COUNT), PUSH(rec.certs, 1+XfOrM1360_COUNT), PUSH(rec.observer, 2+XfOrM1360_COUNT)));
#   define XfOrM1361_COUNT (3+XfOrM1360_COUNT)
#   define SETUP_XfOrM1361(x) SETUP(XfOrM1361_COUNT)
    rec.value_name = NULLED_OUT ; 
    rec.certs = NULLED_OUT ; 
    rec.observer = NULLED_OUT ; 
    rec . comp = 0 ; 
    rec . depth = - 1 ; 
    rec . value_name = scheme_false ; 
    rec . certs = certs ; 
    rec . observer = FUNCCALL(SETUP_XfOrM1361(_), scheme_get_expand_observe () ); 
    expr = FUNCCALL(SETUP_XfOrM1361(_), scheme_add_remove_mark (expr , scheme_current_thread -> current_local_mark ) ); 
    FUNCCALL_AGAIN(scheme_prepare_exp_env (stx_env -> genv ) ); 
    pos = 0 ; 
    expr = FUNCCALL(SETUP_XfOrM1361(_), scheme_add_rename_rib (expr , rib ) ); 
    FUNCCALL_AGAIN(scheme_bind_syntaxes ("local syntax definition" , names , expr , stx_env -> genv -> exp_env , stx_env -> insp , & rec , 0 , stx_env , stx_env , & pos ) ); 
  }
  FUNCCALL(SETUP_XfOrM1360(_), scheme_add_env_renames (rib , stx_env , old_stx_env ) ); 
  (((Scheme_Simple_Object * ) (argv [2 ] ) ) -> u . two_ptr_val . ptr1 ) = stx_env ; 
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_prefix_depth (Resolve_Prefix * rp ) {
  /* No conversion */
  if (rp -> num_toplevels || rp -> num_stxes || rp -> num_lifts )
    return 1 ; 
  else return 0 ; 
}
Scheme_Object * * scheme_push_prefix (Scheme_Env * genv , Resolve_Prefix * rp , Scheme_Object * src_modidx , Scheme_Object * now_modidx , int src_phase , int now_phase ) {
  Scheme_Object * * rs_save , * * rs , * v , * * a ; 
  int i , j ; 
  DECL_RET_SAVE (Scheme_Object * * ) PREPARE_VAR_STACK(9);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(rs_save, 1), PUSH(a, 2), PUSH(rs, 3), PUSH(now_modidx, 4), PUSH(src_modidx, 5), PUSH(rp, 6), PUSH(genv, 7)));
# define XfOrM1368_COUNT (8)
# define SETUP_XfOrM1368(x) SETUP(XfOrM1368_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  rs_save = NULLED_OUT ; 
  rs = NULLED_OUT ; 
  v = NULLED_OUT ; 
  a = NULLED_OUT ; 
  rs_save = rs = scheme_current_runstack ; 
  if (rp -> num_toplevels || rp -> num_stxes || rp -> num_lifts ) {
#   define XfOrM1369_COUNT (0+XfOrM1368_COUNT)
#   define SETUP_XfOrM1369(x) SETUP_XfOrM1368(x)
    i = rp -> num_toplevels ; 
    if (rp -> num_stxes ) {
      i += rp -> num_stxes + 1 ; 
    }
    i += rp -> num_lifts ; 
    a = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM1369(_), GC_malloc (sizeof (Scheme_Object * ) * (i ) ) )) ; 
    -- rs ; 
    scheme_current_runstack = rs ; 
    rs [0 ] = (Scheme_Object * ) a ; 
    for (i = 0 ; i < rp -> num_toplevels ; i ++ ) {
#     define XfOrM1379_COUNT (0+XfOrM1369_COUNT)
#     define SETUP_XfOrM1379(x) SETUP_XfOrM1369(x)
      v = rp -> toplevels [i ] ; 
      if (genv )
        v = FUNCCALL(SETUP_XfOrM1379(_), link_toplevel (rp -> toplevels [i ] , genv , src_modidx , now_modidx ) ); 
      a [i ] = v ; 
    }
    if (rp -> num_stxes ) {
#     define XfOrM1373_COUNT (0+XfOrM1369_COUNT)
#     define SETUP_XfOrM1373(x) SETUP_XfOrM1369(x)
      i = rp -> num_toplevels ; 
      v = FUNCCALL(SETUP_XfOrM1373(_), scheme_stx_phase_shift_as_rename (now_phase - src_phase , src_modidx , now_modidx , genv ? genv -> export_registry : ((void * ) 0 ) ) ); 
      if (v || rp -> delay_info ) {
        Scheme_Object * * ls ; 
        BLOCK_SETUP((PUSH(ls, 0+XfOrM1373_COUNT)));
#       define XfOrM1377_COUNT (1+XfOrM1373_COUNT)
#       define SETUP_XfOrM1377(x) SETUP(XfOrM1377_COUNT)
        ls = NULLED_OUT ; 
        ls = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM1377(_), GC_malloc (sizeof (Scheme_Object * ) * (2 ) ) )) ; 
        ls [0 ] = v ; 
        ls [1 ] = (Scheme_Object * ) rp ; 
        a [i ] = (Scheme_Object * ) ls ; 
      }
      else {
        i ++ ; 
        for (j = 0 ; j < rp -> num_stxes ; j ++ ) {
          a [i + j ] = rp -> stxes [j ] ; 
        }
      }
      j = rp -> num_stxes + 1 ; 
    }
    else j = 0 ; 
    if (rp -> num_lifts ) {
      Scheme_Object * sym ; 
      BLOCK_SETUP((PUSH(sym, 0+XfOrM1369_COUNT)));
#     define XfOrM1370_COUNT (1+XfOrM1369_COUNT)
#     define SETUP_XfOrM1370(x) SETUP(XfOrM1370_COUNT)
      sym = NULLED_OUT ; 
      sym = FUNCCALL(SETUP_XfOrM1370(_), scheme_make_symbol ("<lifted>" ) ); 
      j += rp -> num_toplevels ; 
      for (i = 0 ; i < rp -> num_lifts ; i ++ , j ++ ) {
#       define XfOrM1372_COUNT (0+XfOrM1370_COUNT)
#       define SETUP_XfOrM1372(x) SETUP_XfOrM1370(x)
        v = (Scheme_Object * ) ((Scheme_Bucket_With_Home * ) FUNCCALL(SETUP_XfOrM1372(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Bucket_With_Home ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
        v -> type = scheme_variable_type ; 
        ((Scheme_Bucket_With_Flags * ) v ) -> flags = 32 ; 
        ((Scheme_Bucket_With_Home * ) v ) -> home = genv ; 
        ((Scheme_Bucket * ) v ) -> key = (char * ) sym ; 
        a [j ] = v ; 
      }
    }
  }
  RET_VALUE_START (rs_save ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_pop_prefix (Scheme_Object * * rs ) {
  /* No conversion */
  scheme_current_runstack = rs ; 
}
void scheme_validate_code (Mz_CPort * port , Scheme_Object * code , Scheme_Hash_Table * ht , int depth , int num_toplevels , int num_stxes , int num_lifts ) {
  char * stack ; 
  int delta ; 
  Scheme_Object * * tls ; 
  PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(ht, 0), PUSH(code, 1), PUSH(tls, 2), PUSH(stack, 3), PUSH(port, 4)));
# define XfOrM1382_COUNT (5)
# define SETUP_XfOrM1382(x) SETUP(XfOrM1382_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  stack = NULLED_OUT ; 
  tls = NULLED_OUT ; 
  depth += ((num_toplevels || num_stxes || num_lifts ) ? 1 : 0 ) ; 
  stack = FUNCCALL(SETUP_XfOrM1382(_), GC_malloc_atomic (depth ) ); 
  if (num_toplevels || num_stxes || num_lifts ) {
    stack [depth - 1 ] = 3 ; 
  }
  delta = depth - ((num_toplevels || num_stxes || num_lifts ) ? 1 : 0 ) ; 
  tls = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM1382(_), GC_malloc (sizeof (Scheme_Object * ) * (num_toplevels + num_lifts ) ) )) ; 
  FUNCCALL_EMPTY(scheme_validate_expr (port , code , stack , ht , tls , depth , delta , delta , num_toplevels , num_stxes , num_lifts , ((void * ) 0 ) , 0 ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * validate_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Mz_CPort * port = (Mz_CPort * ) p -> ku . k . p1 ; 
  Scheme_Object * expr = (Scheme_Object * ) p -> ku . k . p2 ; 
  char * stack = (char * ) p -> ku . k . p3 ; 
  Scheme_Hash_Table * ht = (Scheme_Hash_Table * ) p -> ku . k . p4 ; 
  int * args = (int * ) (((void * * ) p -> ku . k . p5 ) [0 ] ) ; 
  Scheme_Object * app_rator = (Scheme_Object * ) (((void * * ) p -> ku . k . p5 ) [1 ] ) ; 
  Scheme_Object * * tls = (Scheme_Object * * ) (((void * * ) p -> ku . k . p5 ) [2 ] ) ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  p -> ku . k . p2 = ((void * ) 0 ) ; 
  p -> ku . k . p3 = ((void * ) 0 ) ; 
  p -> ku . k . p4 = ((void * ) 0 ) ; 
  p -> ku . k . p5 = ((void * ) 0 ) ; 
  scheme_validate_expr (port , expr , stack , ht , tls , args [0 ] , args [1 ] , args [2 ] , args [3 ] , args [4 ] , args [5 ] , app_rator , args [6 ] ) ; 
  return scheme_true ; 
}
int scheme_validate_rator_wants_box (Scheme_Object * app_rator , int pos , int hope , Scheme_Object * * tls , int num_toplevels , int num_stxes , int num_lifts ) {
  Scheme_Closure_Data * data = ((void * ) 0 ) ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(tls, 0), PUSH(app_rator, 1), PUSH(data, 2)));
# define XfOrM1385_COUNT (3)
# define SETUP_XfOrM1385(x) SETUP(XfOrM1385_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  while (1 ) {
#   define XfOrM1397_COUNT (0+XfOrM1385_COUNT)
#   define SETUP_XfOrM1397(x) SETUP_XfOrM1385(x)
    if (((Scheme_Type ) (((((long ) (app_rator ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (app_rator ) ) -> type ) ) == (Scheme_Type ) (scheme_closure_type ) ) ) {
      data = ((Scheme_Closure * ) app_rator ) -> code ; 
      break ; 
    }
    else if (((Scheme_Type ) (((((long ) (app_rator ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (app_rator ) ) -> type ) ) == (Scheme_Type ) (scheme_unclosed_procedure_type ) ) ) {
      data = (Scheme_Closure_Data * ) app_rator ; 
      break ; 
    }
    else if (((Scheme_Type ) (((((long ) (app_rator ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (app_rator ) ) -> type ) ) == (Scheme_Type ) (scheme_toplevel_type ) ) ) {
      int p ; 
#     define XfOrM1398_COUNT (0+XfOrM1397_COUNT)
#     define SETUP_XfOrM1398(x) SETUP_XfOrM1397(x)
      p = (((Scheme_Toplevel * ) (app_rator ) ) -> position ) ; 
      if (p >= (num_toplevels + num_stxes + (num_stxes ? 1 : 0 ) ) ) {
        int tp ; 
#       define XfOrM1399_COUNT (0+XfOrM1398_COUNT)
#       define SETUP_XfOrM1399(x) SETUP_XfOrM1398(x)
        tp = (p - (num_stxes + (num_stxes ? 1 : 0 ) ) ) ; 
        app_rator = tls [tp ] ; 
        if (! app_rator || ((Scheme_Type ) (((((long ) (app_rator ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (app_rator ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
          Scheme_Object * vec = app_rator ; 
          BLOCK_SETUP((PUSH(vec, 0+XfOrM1399_COUNT)));
#         define XfOrM1401_COUNT (1+XfOrM1399_COUNT)
#         define SETUP_XfOrM1401(x) SETUP(XfOrM1401_COUNT)
          if (! vec || ((((Scheme_Vector * ) (vec ) ) -> size ) < (pos + 1 ) ) ) {
            int sz ; 
            Scheme_Object * naya ; 
            BLOCK_SETUP((PUSH(naya, 0+XfOrM1401_COUNT)));
#           define XfOrM1403_COUNT (1+XfOrM1401_COUNT)
#           define SETUP_XfOrM1403(x) SETUP(XfOrM1403_COUNT)
            naya = NULLED_OUT ; 
            if (vec )
              sz = (((Scheme_Vector * ) (vec ) ) -> size ) ; 
            else sz = 3 ; 
            sz *= 2 ; 
            if (sz <= pos )
              sz = pos + 1 ; 
            naya = FUNCCALL(SETUP_XfOrM1403(_), scheme_make_vector (sz , scheme_null ) ); 
            if (vec )
              (memcpy ((((Scheme_Vector * ) (naya ) ) -> els ) , (((Scheme_Vector * ) (vec ) ) -> els ) , sizeof (Scheme_Object * ) * (((Scheme_Vector * ) (vec ) ) -> size ) ) ) ; 
            vec = naya ; 
            tls [tp ] = vec ; 
          }
          if ((((((Scheme_Vector * ) (vec ) ) -> els ) [pos ] ) == (scheme_null ) ) ) {
            (((Scheme_Vector * ) (vec ) ) -> els ) [pos ] = hope ? scheme_true : scheme_false ; 
            RET_VALUE_START (hope ) RET_VALUE_END ; 
          }
          else if ((! ((((((Scheme_Vector * ) (vec ) ) -> els ) [pos ] ) ) == (scheme_false ) ) ) )
            RET_VALUE_START (1 ) RET_VALUE_END ; 
          else RET_VALUE_START (0 ) RET_VALUE_END ; 
        }
        else if ((((app_rator ) ) == (scheme_false ) ) ) {
          RET_VALUE_START (0 ) RET_VALUE_END ; 
        }
      }
      else RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    else RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  if ((& (data ) -> iso ) -> so . keyex & 2 ) {
    if (pos < data -> num_params ) {
      int bit = ((mzshort ) 1 << (pos & ((8 * sizeof (mzshort ) ) - 1 ) ) ) ; 
      if (data -> closure_map [data -> closure_size + (pos / (8 * sizeof (mzshort ) ) ) ] & bit )
        RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
  }
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int argument_to_arity_error (Scheme_Object * app_rator , int proc_with_refs_ok ) {
  /* No conversion */
  return ((proc_with_refs_ok == 2 ) && ((app_rator ) == (scheme_raise_arity_error_proc ) ) ) ; 
}
void scheme_validate_expr (Mz_CPort * port , Scheme_Object * expr , char * stack , Scheme_Hash_Table * ht , Scheme_Object * * tls , int depth , int letlimit , int delta , int num_toplevels , int num_stxes , int num_lifts , Scheme_Object * app_rator , int proc_with_refs_ok ) {
  Scheme_Type type ; 
  int did_one = 0 ; 
  unsigned long _stk_pos ; 
  PREPARE_VAR_STACK(9);
  BLOCK_SETUP_TOP((PUSH(port, 0), PUSH(ht, 1), PUSH(expr, 2), PUSH(tls, 3), PUSH(app_rator, 4), PUSH(stack, 5)));
# define XfOrM1407_COUNT (6)
# define SETUP_XfOrM1407(x) SETUP(XfOrM1407_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  _stk_pos = (unsigned long ) & _stk_pos ; 
  if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
    Scheme_Thread * p = scheme_current_thread ; 
    void * * pr ; 
    int * args ; 
    BLOCK_SETUP((PUSH(pr, 0+XfOrM1407_COUNT), PUSH(args, 1+XfOrM1407_COUNT), PUSH(p, 2+XfOrM1407_COUNT)));
#   define XfOrM1466_COUNT (3+XfOrM1407_COUNT)
#   define SETUP_XfOrM1466(x) SETUP(XfOrM1466_COUNT)
    pr = NULLED_OUT ; 
    args = NULLED_OUT ; 
    args = ((int * ) FUNCCALL(SETUP_XfOrM1466(_), GC_malloc_atomic (sizeof (int ) * (7 ) ) )) ; 
    p -> ku . k . p1 = (void * ) port ; 
    p -> ku . k . p2 = (void * ) expr ; 
    p -> ku . k . p3 = (void * ) stack ; 
    p -> ku . k . p4 = (void * ) ht ; 
    args [0 ] = depth ; 
    args [1 ] = letlimit ; 
    args [2 ] = delta ; 
    args [3 ] = num_toplevels ; 
    args [4 ] = num_stxes ; 
    args [5 ] = num_lifts ; 
    args [6 ] = proc_with_refs_ok ; 
    pr = ((void * * ) FUNCCALL(SETUP_XfOrM1466(_), GC_malloc (sizeof (void * ) * (3 ) ) )) ; 
    pr [0 ] = (void * ) args ; 
    pr [1 ] = (void * ) app_rator ; 
    pr [2 ] = (void * ) tls ; 
    p -> ku . k . p5 = (void * ) pr ; 
    (void ) FUNCCALL(SETUP_XfOrM1466(_), scheme_handle_stack_overflow (validate_k ) ); 
    RET_NOTHING ; 
  }
  top : if (did_one ) {
#   define XfOrM1464_COUNT (0+XfOrM1407_COUNT)
#   define SETUP_XfOrM1464(x) SETUP_XfOrM1407(x)
    if (app_rator ) {
#     define XfOrM1465_COUNT (0+XfOrM1464_COUNT)
#     define SETUP_XfOrM1465(x) SETUP_XfOrM1464(x)
      if (FUNCCALL(SETUP_XfOrM1465(_), scheme_validate_rator_wants_box (app_rator , proc_with_refs_ok - 2 , 0 , tls , num_toplevels , num_stxes , num_lifts ) ))
        FUNCCALL(SETUP_XfOrM1465(_), scheme_ill_formed (port , "./../src/eval.c" , 8533 ) ); 
      app_rator = ((void * ) 0 ) ; 
    }
    proc_with_refs_ok = 0 ; 
  }
  else did_one = 1 ; 
  type = ((((long ) (expr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (expr ) ) -> type ) ; 
  switch (type ) {
#   define XfOrM1408_COUNT (0+XfOrM1407_COUNT)
#   define SETUP_XfOrM1408(x) SETUP_XfOrM1407(x)
    case scheme_toplevel_type : {
      int c = (((Scheme_Toplevel * ) (expr ) ) -> depth ) ; 
      int d = c + delta ; 
      int p = (((Scheme_Toplevel * ) (expr ) ) -> position ) ; 
#     define XfOrM1454_COUNT (0+XfOrM1408_COUNT)
#     define SETUP_XfOrM1454(x) SETUP_XfOrM1408(x)
      if ((c < 0 ) || (p < 0 ) || (d >= depth ) || (stack [d ] != 3 ) || (p >= (num_toplevels + num_lifts + num_stxes + (num_stxes ? 1 : 0 ) ) ) || ((p >= num_toplevels ) && (p < num_toplevels + num_stxes + (num_stxes ? 1 : 0 ) ) ) )
        FUNCCALL(SETUP_XfOrM1454(_), scheme_ill_formed (port , "./../src/eval.c" , 8553 ) ); 
      if ((proc_with_refs_ok != 1 ) && ! FUNCCALL(SETUP_XfOrM1454(_), argument_to_arity_error (app_rator , proc_with_refs_ok ) )) {
#       define XfOrM1455_COUNT (0+XfOrM1454_COUNT)
#       define SETUP_XfOrM1455(x) SETUP_XfOrM1454(x)
        if (p >= (num_toplevels + num_stxes + (num_stxes ? 1 : 0 ) ) ) {
          int tp ; 
          Scheme_Object * lift ; 
          BLOCK_SETUP((PUSH(lift, 0+XfOrM1455_COUNT)));
#         define XfOrM1456_COUNT (1+XfOrM1455_COUNT)
#         define SETUP_XfOrM1456(x) SETUP(XfOrM1456_COUNT)
          lift = NULLED_OUT ; 
          tp = p - (num_stxes + (num_stxes ? 1 : 0 ) ) ; 
          lift = tls [tp ] ; 
          if (lift ) {
#           define XfOrM1458_COUNT (0+XfOrM1456_COUNT)
#           define SETUP_XfOrM1458(x) SETUP_XfOrM1456(x)
            if (((Scheme_Type ) (((((long ) (lift ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lift ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
              int i ; 
#             define XfOrM1461_COUNT (0+XfOrM1458_COUNT)
#             define SETUP_XfOrM1461(x) SETUP_XfOrM1458(x)
              for (i = (((Scheme_Vector * ) (lift ) ) -> size ) ; i -- ; ) {
#               define XfOrM1463_COUNT (0+XfOrM1461_COUNT)
#               define SETUP_XfOrM1463(x) SETUP_XfOrM1461(x)
                if (! (((((Scheme_Vector * ) (lift ) ) -> els ) [i ] ) == (scheme_null ) ) )
                  if ((! ((((((Scheme_Vector * ) (lift ) ) -> els ) [i ] ) ) == (scheme_false ) ) ) )
                  FUNCCALL(SETUP_XfOrM1463(_), scheme_ill_formed (port , "./../src/eval.c" , 8570 ) ); 
              }
              tls [tp ] = scheme_false ; 
            }
            else {
#             define XfOrM1459_COUNT (0+XfOrM1458_COUNT)
#             define SETUP_XfOrM1459(x) SETUP_XfOrM1458(x)
              if (((Scheme_Type ) (((((long ) (lift ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lift ) ) -> type ) ) == (Scheme_Type ) (scheme_closure_type ) ) )
                lift = (Scheme_Object * ) ((Scheme_Closure * ) lift ) -> code ; 
              if (((Scheme_Type ) (((((long ) (lift ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lift ) ) -> type ) ) == (Scheme_Type ) (scheme_unclosed_procedure_type ) ) ) {
                Scheme_Closure_Data * data = (Scheme_Closure_Data * ) lift ; 
#               define XfOrM1460_COUNT (0+XfOrM1459_COUNT)
#               define SETUP_XfOrM1460(x) SETUP_XfOrM1459(x)
                if ((& (data ) -> iso ) -> so . keyex & 2 )
                  FUNCCALL(SETUP_XfOrM1460(_), scheme_ill_formed (port , "./../src/eval.c" , 8579 ) ); 
              }
            }
          }
          else {
            tls [tp ] = scheme_false ; 
          }
        }
      }
    }
    break ; 
    case scheme_local_type : {
      int q = (((Scheme_Local * ) (expr ) ) -> position ) ; 
      int p = q + delta ; 
#     define XfOrM1451_COUNT (0+XfOrM1408_COUNT)
#     define SETUP_XfOrM1451(x) SETUP_XfOrM1408(x)
      if ((q < 0 ) || (p >= depth ) )
        FUNCCALL(SETUP_XfOrM1451(_), scheme_ill_formed (port , "./../src/eval.c" , 8595 ) ); 
      if (stack [p ] != 1 ) {
#       define XfOrM1452_COUNT (0+XfOrM1451_COUNT)
#       define SETUP_XfOrM1452(x) SETUP_XfOrM1451(x)
        if ((proc_with_refs_ok >= 2 ) && (stack [p ] == 2 ) && FUNCCALL(SETUP_XfOrM1452(_), scheme_validate_rator_wants_box (app_rator , proc_with_refs_ok - 2 , 1 , tls , num_toplevels , num_stxes , num_lifts ) )) {
          app_rator = ((void * ) 0 ) ; 
        }
        else FUNCCALL(SETUP_XfOrM1452(_), scheme_ill_formed (port , "./../src/eval.c" , 8605 ) ); 
      }
    }
    break ; 
    case scheme_local_unbox_type : {
      int q = (((Scheme_Local * ) (expr ) ) -> position ) ; 
      int p = q + delta ; 
#     define XfOrM1450_COUNT (0+XfOrM1408_COUNT)
#     define SETUP_XfOrM1450(x) SETUP_XfOrM1408(x)
      if ((q < 0 ) || (p >= depth ) || (stack [p ] != 2 ) )
        FUNCCALL(SETUP_XfOrM1450(_), scheme_ill_formed (port , "./../src/eval.c" , 8615 ) ); 
    }
    break ; 
    case scheme_syntax_type : {
      Scheme_Syntax_Validater f ; 
      int p = (((Scheme_Simple_Object * ) (expr ) ) -> u . ptr_int_val . pint ) ; 
#     define XfOrM1449_COUNT (0+XfOrM1408_COUNT)
#     define SETUP_XfOrM1449(x) SETUP_XfOrM1408(x)
      if ((p < 0 ) || (p >= 12 ) )
        FUNCCALL(SETUP_XfOrM1449(_), scheme_ill_formed (port , "./../src/eval.c" , 8624 ) ); 
      f = scheme_syntax_validaters [p ] ; 
      FUNCCALL(SETUP_XfOrM1449(_), f ((Scheme_Object * ) (((Scheme_Simple_Object * ) (expr ) ) -> u . ptr_int_val . ptr ) , port , stack , ht , tls , depth , letlimit , delta , num_toplevels , num_stxes , num_lifts ) ); 
    }
    break ; 
    case scheme_application_type : {
      Scheme_App_Rec * app = (Scheme_App_Rec * ) expr ; 
      int i , n ; 
      BLOCK_SETUP((PUSH(app, 0+XfOrM1408_COUNT)));
#     define XfOrM1446_COUNT (1+XfOrM1408_COUNT)
#     define SETUP_XfOrM1446(x) SETUP(XfOrM1446_COUNT)
      n = app -> num_args + 1 ; 
      delta -= (n - 1 ) ; 
      if (delta < 0 )
        FUNCCALL(SETUP_XfOrM1446(_), scheme_ill_formed (port , "./../src/eval.c" , 8639 ) ); 
      (memset (stack + delta , 0 , n - 1 ) ) ; 
      for (i = 0 ; i < n ; i ++ ) {
#       define XfOrM1448_COUNT (0+XfOrM1446_COUNT)
#       define SETUP_XfOrM1448(x) SETUP_XfOrM1446(x)
        FUNCCALL(SETUP_XfOrM1448(_), scheme_validate_expr (port , app -> args [i ] , stack , ht , tls , depth , letlimit , delta , num_toplevels , num_stxes , num_lifts , i ? app -> args [0 ] : ((void * ) 0 ) , i + 1 ) ); 
      }
    }
    break ; 
    case scheme_application2_type : {
      Scheme_App2_Rec * app = (Scheme_App2_Rec * ) expr ; 
      BLOCK_SETUP((PUSH(app, 0+XfOrM1408_COUNT)));
#     define XfOrM1445_COUNT (1+XfOrM1408_COUNT)
#     define SETUP_XfOrM1445(x) SETUP(XfOrM1445_COUNT)
      delta -= 1 ; 
      if (delta < 0 )
        FUNCCALL(SETUP_XfOrM1445(_), scheme_ill_formed (port , "./../src/eval.c" , 8654 ) ); 
      stack [delta ] = 0 ; 
      FUNCCALL(SETUP_XfOrM1445(_), scheme_validate_expr (port , app -> rator , stack , ht , tls , depth , letlimit , delta , num_toplevels , num_stxes , num_lifts , ((void * ) 0 ) , 1 ) ); 
      FUNCCALL_AGAIN(scheme_validate_expr (port , app -> rand , stack , ht , tls , depth , letlimit , delta , num_toplevels , num_stxes , num_lifts , app -> rator , 2 ) ); 
    }
    break ; 
    case scheme_application3_type : {
      Scheme_App3_Rec * app = (Scheme_App3_Rec * ) expr ; 
      BLOCK_SETUP((PUSH(app, 0+XfOrM1408_COUNT)));
#     define XfOrM1444_COUNT (1+XfOrM1408_COUNT)
#     define SETUP_XfOrM1444(x) SETUP(XfOrM1444_COUNT)
      delta -= 2 ; 
      if (delta < 0 )
        FUNCCALL(SETUP_XfOrM1444(_), scheme_ill_formed (port , "./../src/eval.c" , 8669 ) ); 
      stack [delta ] = 0 ; 
      stack [delta + 1 ] = 0 ; 
      FUNCCALL(SETUP_XfOrM1444(_), scheme_validate_expr (port , app -> rator , stack , ht , tls , depth , letlimit , delta , num_toplevels , num_stxes , num_lifts , ((void * ) 0 ) , 1 ) ); 
      FUNCCALL_AGAIN(scheme_validate_expr (port , app -> rand1 , stack , ht , tls , depth , letlimit , delta , num_toplevels , num_stxes , num_lifts , app -> rator , 2 ) ); 
      FUNCCALL_AGAIN(scheme_validate_expr (port , app -> rand2 , stack , ht , tls , depth , letlimit , delta , num_toplevels , num_stxes , num_lifts , app -> rator , 3 ) ); 
    }
    break ; 
    case scheme_sequence_type : {
      Scheme_Sequence * seq = (Scheme_Sequence * ) expr ; 
      int cnt ; 
      int i ; 
      BLOCK_SETUP((PUSH(seq, 0+XfOrM1408_COUNT)));
#     define XfOrM1441_COUNT (1+XfOrM1408_COUNT)
#     define SETUP_XfOrM1441(x) SETUP(XfOrM1441_COUNT)
      cnt = seq -> count ; 
      for (i = 0 ; i < cnt - 1 ; i ++ ) {
#       define XfOrM1443_COUNT (0+XfOrM1441_COUNT)
#       define SETUP_XfOrM1443(x) SETUP_XfOrM1441(x)
        FUNCCALL(SETUP_XfOrM1443(_), scheme_validate_expr (port , seq -> array [i ] , stack , ht , tls , depth , letlimit , delta , num_toplevels , num_stxes , num_lifts , ((void * ) 0 ) , 0 ) ); 
      }
      expr = seq -> array [cnt - 1 ] ; 
      goto top ; 
    }
    break ; 
    case scheme_branch_type : {
      Scheme_Branch_Rec * b ; 
      BLOCK_SETUP((PUSH(b, 0+XfOrM1408_COUNT)));
#     define XfOrM1440_COUNT (1+XfOrM1408_COUNT)
#     define SETUP_XfOrM1440(x) SETUP(XfOrM1440_COUNT)
      b = NULLED_OUT ; 
      b = (Scheme_Branch_Rec * ) expr ; 
      FUNCCALL(SETUP_XfOrM1440(_), scheme_validate_expr (port , b -> test , stack , ht , tls , depth , letlimit , delta , num_toplevels , num_stxes , num_lifts , ((void * ) 0 ) , 0 ) ); 
      letlimit = delta ; 
      FUNCCALL(SETUP_XfOrM1440(_), scheme_validate_expr (port , b -> tbranch , stack , ht , tls , depth , letlimit , delta , num_toplevels , num_stxes , num_lifts , ((void * ) 0 ) , 0 ) ); 
      expr = b -> fbranch ; 
      goto top ; 
    }
    break ; 
    case scheme_with_cont_mark_type : {
      Scheme_With_Continuation_Mark * wcm = (Scheme_With_Continuation_Mark * ) expr ; 
      BLOCK_SETUP((PUSH(wcm, 0+XfOrM1408_COUNT)));
#     define XfOrM1439_COUNT (1+XfOrM1408_COUNT)
#     define SETUP_XfOrM1439(x) SETUP(XfOrM1439_COUNT)
      FUNCCALL(SETUP_XfOrM1439(_), scheme_validate_expr (port , wcm -> key , stack , ht , tls , depth , letlimit , delta , num_toplevels , num_stxes , num_lifts , ((void * ) 0 ) , 0 ) ); 
      FUNCCALL(SETUP_XfOrM1439(_), scheme_validate_expr (port , wcm -> val , stack , ht , tls , depth , letlimit , delta , num_toplevels , num_stxes , num_lifts , ((void * ) 0 ) , 0 ) ); 
      expr = wcm -> body ; 
      goto top ; 
    }
    break ; 
    case scheme_quote_syntax_type : {
      Scheme_Quote_Syntax * qs = (Scheme_Quote_Syntax * ) expr ; 
      int c = qs -> depth ; 
      int i = qs -> position ; 
      int p = qs -> midpoint ; 
      int d = c + delta ; 
#     define XfOrM1438_COUNT (0+XfOrM1408_COUNT)
#     define SETUP_XfOrM1438(x) SETUP_XfOrM1408(x)
      if ((c < 0 ) || (p < 0 ) || (d >= depth ) || (stack [d ] != 3 ) || (p != num_toplevels ) || (i >= num_stxes ) )
        FUNCCALL(SETUP_XfOrM1438(_), scheme_ill_formed (port , "./../src/eval.c" , 8738 ) ); 
    }
    break ; 
    case scheme_unclosed_procedure_type : {
      Scheme_Closure_Data * data = (Scheme_Closure_Data * ) expr ; 
      int i , cnt , q , p , sz , base , vld ; 
      mzshort * map ; 
      char * new_stack ; 
      BLOCK_SETUP((PUSH(new_stack, 0+XfOrM1408_COUNT), PUSH(map, 1+XfOrM1408_COUNT), PUSH(data, 2+XfOrM1408_COUNT)));
#     define XfOrM1430_COUNT (3+XfOrM1408_COUNT)
#     define SETUP_XfOrM1430(x) SETUP(XfOrM1430_COUNT)
      map = NULLED_OUT ; 
      new_stack = NULLED_OUT ; 
      if ((& (data ) -> iso ) -> so . keyex & 2 ) {
#       define XfOrM1437_COUNT (0+XfOrM1430_COUNT)
#       define SETUP_XfOrM1437(x) SETUP_XfOrM1430(x)
        if ((proc_with_refs_ok != 1 ) && ! FUNCCALL(SETUP_XfOrM1437(_), argument_to_arity_error (app_rator , proc_with_refs_ok ) ))
          FUNCCALL(SETUP_XfOrM1437(_), scheme_ill_formed (port , "./../src/eval.c" , 8751 ) ); 
      }
      sz = data -> max_let_depth ; 
      map = data -> closure_map ; 
      new_stack = FUNCCALL(SETUP_XfOrM1430(_), GC_malloc_atomic (sz ) ); 
      cnt = data -> num_params ; 
      base = sz - cnt ; 
      for (i = 0 ; i < cnt ; i ++ ) {
        vld = 1 ; 
        if ((& (data ) -> iso ) -> so . keyex & 2 ) {
          int bit = ((mzshort ) 1 << (i & ((8 * sizeof (mzshort ) ) - 1 ) ) ) ; 
          if (map [data -> closure_size + (i / (8 * sizeof (mzshort ) ) ) ] & bit )
            vld = 2 ; 
        }
        new_stack [i + base ] = vld ; 
      }
      cnt = data -> closure_size ; 
      base = base - cnt ; 
      for (i = 0 ; i < cnt ; i ++ ) {
#       define XfOrM1432_COUNT (0+XfOrM1430_COUNT)
#       define SETUP_XfOrM1432(x) SETUP_XfOrM1430(x)
        q = map [i ] ; 
        p = q + delta ; 
        if ((q < 0 ) || (p > depth ) || (stack [p ] == 0 ) )
          FUNCCALL(SETUP_XfOrM1432(_), scheme_ill_formed (port , "./../src/eval.c" , 8778 ) ); 
        new_stack [i + base ] = stack [p ] ; 
      }
      FUNCCALL(SETUP_XfOrM1430(_), scheme_validate_expr (port , data -> code , new_stack , ht , tls , sz , sz , base , num_toplevels , num_stxes , num_lifts , ((void * ) 0 ) , 0 ) ); 
    }
    break ; 
    case scheme_let_value_type : {
      Scheme_Let_Value * lv = (Scheme_Let_Value * ) expr ; 
      int q , p , c , i ; 
      BLOCK_SETUP((PUSH(lv, 0+XfOrM1408_COUNT)));
#     define XfOrM1425_COUNT (1+XfOrM1408_COUNT)
#     define SETUP_XfOrM1425(x) SETUP(XfOrM1425_COUNT)
      FUNCCALL(SETUP_XfOrM1425(_), scheme_validate_expr (port , lv -> value , stack , ht , tls , depth , letlimit , delta , num_toplevels , num_stxes , num_lifts , ((void * ) 0 ) , 0 ) ); 
      (memset (stack , 0 , delta ) ) ; 
      c = lv -> count ; 
      q = lv -> position ; 
      p = q + delta ; 
      for (i = 0 ; i < c ; i ++ , p ++ ) {
#       define XfOrM1428_COUNT (0+XfOrM1425_COUNT)
#       define SETUP_XfOrM1428(x) SETUP_XfOrM1425(x)
        if ((q < 0 ) || ((& lv -> iso ) -> so . keyex && ((p >= depth ) || (stack [p ] != 2 ) ) ) || (! (& lv -> iso ) -> so . keyex && ((p >= letlimit ) || ((stack [p ] != 1 ) && (stack [p ] != 0 ) ) ) ) )
          FUNCCALL(SETUP_XfOrM1428(_), scheme_ill_formed (port , "./../src/eval.c" , 8805 ) ); 
        if (! (& lv -> iso ) -> so . keyex ) {
          stack [p ] = 1 ; 
        }
      }
      expr = lv -> body ; 
      goto top ; 
    }
    break ; 
    case scheme_let_void_type : {
      Scheme_Let_Void * lv = (Scheme_Let_Void * ) expr ; 
      int c , i ; 
      BLOCK_SETUP((PUSH(lv, 0+XfOrM1408_COUNT)));
#     define XfOrM1420_COUNT (1+XfOrM1408_COUNT)
#     define SETUP_XfOrM1420(x) SETUP(XfOrM1420_COUNT)
      c = lv -> count ; 
      if ((c < 0 ) || (c > delta ) )
        FUNCCALL(SETUP_XfOrM1420(_), scheme_ill_formed (port , "./../src/eval.c" , 8824 ) ); 
      if ((& lv -> iso ) -> so . keyex ) {
        for (i = 0 ; i < c ; i ++ ) {
          stack [-- delta ] = 2 ; 
        }
      }
      else {
#       define XfOrM1421_COUNT (0+XfOrM1420_COUNT)
#       define SETUP_XfOrM1421(x) SETUP_XfOrM1420(x)
        delta -= c ; 
        (memset (stack + delta , 0 , c ) ) ; 
      }
      expr = lv -> body ; 
      goto top ; 
    }
    break ; 
    case scheme_letrec_type : {
      Scheme_Letrec * l = (Scheme_Letrec * ) expr ; 
      int i , c ; 
      BLOCK_SETUP((PUSH(l, 0+XfOrM1408_COUNT)));
#     define XfOrM1413_COUNT (1+XfOrM1408_COUNT)
#     define SETUP_XfOrM1413(x) SETUP(XfOrM1413_COUNT)
      c = l -> count ; 
      if ((c < 0 ) || (c + delta > depth ) )
        FUNCCALL(SETUP_XfOrM1413(_), scheme_ill_formed (port , "./../src/eval.c" , 8848 ) ); 
      for (i = 0 ; i < c ; i ++ ) {
#       define XfOrM1419_COUNT (0+XfOrM1413_COUNT)
#       define SETUP_XfOrM1419(x) SETUP_XfOrM1413(x)
        if (! ((Scheme_Type ) (((((long ) (l -> procs [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l -> procs [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unclosed_procedure_type ) ) )
          FUNCCALL(SETUP_XfOrM1419(_), scheme_ill_formed (port , "./../src/eval.c" , 8852 ) ); 
      }
      for (i = 0 ; i < c ; i ++ ) {
        stack [delta + i ] = 1 ; 
      }
      for (i = 0 ; i < c ; i ++ ) {
#       define XfOrM1415_COUNT (0+XfOrM1413_COUNT)
#       define SETUP_XfOrM1415(x) SETUP_XfOrM1413(x)
        FUNCCALL(SETUP_XfOrM1415(_), scheme_validate_expr (port , l -> procs [i ] , stack , ht , tls , depth , letlimit , delta , num_toplevels , num_stxes , num_lifts , ((void * ) 0 ) , 0 ) ); 
      }
      expr = l -> body ; 
      goto top ; 
    }
    break ; 
    case scheme_let_one_type : {
      Scheme_Let_One * lo = (Scheme_Let_One * ) expr ; 
      BLOCK_SETUP((PUSH(lo, 0+XfOrM1408_COUNT)));
#     define XfOrM1412_COUNT (1+XfOrM1408_COUNT)
#     define SETUP_XfOrM1412(x) SETUP(XfOrM1412_COUNT)
      -- delta ; 
      if (delta < 0 )
        FUNCCALL(SETUP_XfOrM1412(_), scheme_ill_formed (port , "./../src/eval.c" , 8874 ) ); 
      stack [delta ] = 0 ; 
      FUNCCALL(SETUP_XfOrM1412(_), scheme_validate_expr (port , lo -> value , stack , ht , tls , depth , letlimit , delta , num_toplevels , num_stxes , num_lifts , ((void * ) 0 ) , 0 ) ); 
      stack [delta ] = 1 ; 
      expr = lo -> body ; 
      goto top ; 
    }
    break ; 
    default : if (((Scheme_Type ) (type ) == (Scheme_Type ) (scheme_closure_type ) ) ) {
#     define XfOrM1409_COUNT (0+XfOrM1408_COUNT)
#     define SETUP_XfOrM1409(x) SETUP_XfOrM1408(x)
      if (FUNCCALL(SETUP_XfOrM1409(_), scheme_hash_get (ht , expr ) )) {
      }
      else {
#       define XfOrM1410_COUNT (0+XfOrM1409_COUNT)
#       define SETUP_XfOrM1410(x) SETUP_XfOrM1409(x)
        FUNCCALL(SETUP_XfOrM1410(_), scheme_hash_set (ht , expr , scheme_true ) ); 
        expr = (Scheme_Object * ) ((Scheme_Closure * ) expr ) -> code ; 
        did_one = 0 ; 
        goto top ; 
      }
    }
    break ; 
  }
  if (app_rator )
    if (FUNCCALL(SETUP_XfOrM1407(_), scheme_validate_rator_wants_box (app_rator , proc_with_refs_ok - 2 , 0 , tls , num_toplevels , num_stxes , num_lifts ) ))
    FUNCCALL_EMPTY(scheme_ill_formed (port , "./../src/eval.c" , 8903 ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_validate_toplevel (Scheme_Object * expr , Mz_CPort * port , char * stack , Scheme_Hash_Table * ht , Scheme_Object * * tls , int depth , int delta , int num_toplevels , int num_stxes , int num_lifts , int skip_refs_check ) {
  PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(ht, 0), PUSH(expr, 1), PUSH(tls, 2), PUSH(stack, 3), PUSH(port, 4)));
# define XfOrM1467_COUNT (5)
# define SETUP_XfOrM1467(x) SETUP(XfOrM1467_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! ((Scheme_Type ) (scheme_toplevel_type ) == (Scheme_Type ) (((((long ) (expr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (expr ) ) -> type ) ) ) )
    FUNCCALL(SETUP_XfOrM1467(_), scheme_ill_formed (port , "./../src/eval.c" , 8913 ) ); 
  FUNCCALL_EMPTY(scheme_validate_expr (port , expr , stack , ht , tls , depth , delta , delta , num_toplevels , num_stxes , num_lifts , ((void * ) 0 ) , skip_refs_check ? 1 : 0 ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_validate_boxenv (int p , Mz_CPort * port , char * stack , int depth , int delta ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(stack, 0)));
# define XfOrM1468_COUNT (1)
# define SETUP_XfOrM1468(x) SETUP(XfOrM1468_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  p += delta ; 
  if ((p < 0 ) || (p >= depth ) || (stack [p ] != 1 ) )
    FUNCCALL(SETUP_XfOrM1468(_), scheme_ill_formed (port , "./../src/eval.c" , 8926 ) ); 
  stack [p ] = 2 ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * write_application (Scheme_Object * obj ) {
  /* No conversion */
  scheme_signal_error ("app writer shouldn't be used" ) ; 
  return ((void * ) 0 ) ; 
}
static Scheme_Object * read_application (Scheme_Object * obj ) {
  /* No conversion */
  return ((void * ) 0 ) ; 
}
static Scheme_Object * write_sequence (Scheme_Object * obj ) {
  Scheme_Object * l ; 
  int i ; 
  Scheme_Object * __funcarg147 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(obj, 0), PUSH(l, 1)));
# define XfOrM1471_COUNT (2)
# define SETUP_XfOrM1471(x) SETUP(XfOrM1471_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  l = NULLED_OUT ; 
  i = ((Scheme_Sequence * ) obj ) -> count ; 
  l = scheme_null ; 
  for (; i -- ; ) {
#   define XfOrM1473_COUNT (0+XfOrM1471_COUNT)
#   define SETUP_XfOrM1473(x) SETUP_XfOrM1471(x)
    l = (__funcarg147 = FUNCCALL(SETUP_XfOrM1473(_), scheme_protect_quote (((Scheme_Sequence * ) obj ) -> array [i ] ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg147 , l ) )) ; 
  }
  RET_VALUE_START (l ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * read_sequence (Scheme_Object * obj ) {
  /* No conversion */
  return scheme_make_sequence_compilation (obj , 1 ) ; 
}
static Scheme_Object * read_sequence_save_first (Scheme_Object * obj ) {
  /* No conversion */
  return scheme_make_sequence_compilation (obj , - 1 ) ; 
}
static Scheme_Object * write_branch (Scheme_Object * obj ) {
  /* No conversion */
  scheme_signal_error ("branch writer shouldn't be used" ) ; 
  return ((void * ) 0 ) ; 
}
static Scheme_Object * read_branch (Scheme_Object * obj ) {
  /* No conversion */
  return ((void * ) 0 ) ; 
}
static Scheme_Object * write_with_cont_mark (Scheme_Object * obj ) {
  Scheme_With_Continuation_Mark * wcm ; 
  Scheme_Object * __funcarg151 = NULLED_OUT ; 
  Scheme_Object * __funcarg150 = NULLED_OUT ; 
  Scheme_Object * __funcarg149 = NULLED_OUT ; 
  Scheme_Object * __funcarg148 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(__funcarg148, 0), PUSH(__funcarg150, 1), PUSH(wcm, 2)));
# define XfOrM1478_COUNT (3)
# define SETUP_XfOrM1478(x) SETUP(XfOrM1478_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  wcm = NULLED_OUT ; 
  wcm = (Scheme_With_Continuation_Mark * ) obj ; 
  RET_VALUE_START ((__funcarg148 = FUNCCALL(SETUP_XfOrM1478(_), scheme_protect_quote (wcm -> key ) ), __funcarg149 = (__funcarg150 = FUNCCALL(SETUP_XfOrM1478(_), scheme_protect_quote (wcm -> val ) ), __funcarg151 = FUNCCALL(SETUP_XfOrM1478(_), scheme_protect_quote (wcm -> body ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg150 , __funcarg151 ) )) , FUNCCALL_EMPTY(scheme_make_pair (__funcarg148 , __funcarg149 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * read_with_cont_mark (Scheme_Object * obj ) {
  Scheme_With_Continuation_Mark * wcm ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(obj, 0), PUSH(wcm, 1)));
# define XfOrM1479_COUNT (2)
# define SETUP_XfOrM1479(x) SETUP(XfOrM1479_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  wcm = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || ! ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  wcm = ((Scheme_With_Continuation_Mark * ) FUNCCALL(SETUP_XfOrM1479(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_With_Continuation_Mark ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  wcm -> so . type = scheme_with_cont_mark_type ; 
  wcm -> key = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
  wcm -> val = ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ; 
  wcm -> body = (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ; 
  RET_VALUE_START ((Scheme_Object * ) wcm ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * write_syntax (Scheme_Object * obj ) {
  Scheme_Object * idx , * rest , * l ; 
  int protect_after , c ; 
  PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(idx, 0), PUSH(rest, 1), PUSH(l, 2)));
# define XfOrM1480_COUNT (3)
# define SETUP_XfOrM1480(x) SETUP(XfOrM1480_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  idx = NULLED_OUT ; 
  rest = NULLED_OUT ; 
  l = NULLED_OUT ; 
  c = (((Scheme_Simple_Object * ) (obj ) ) -> u . ptr_int_val . pint ) ; 
  idx = ((Scheme_Object * ) (void * ) (long ) ((((long ) (c ) ) << 1 ) | 0x1 ) ) ; 
  protect_after = scheme_syntax_protect_afters [c ] ; 
  l = rest = (Scheme_Object * ) (((Scheme_Simple_Object * ) (obj ) ) -> u . ptr_int_val . ptr ) ; 
  if (protect_after == - 2 ) {
#   define XfOrM1488_COUNT (0+XfOrM1480_COUNT)
#   define SETUP_XfOrM1488(x) SETUP_XfOrM1480(x)
    if (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
#     define XfOrM1490_COUNT (0+XfOrM1488_COUNT)
#     define SETUP_XfOrM1490(x) SETUP_XfOrM1488(x)
      l = FUNCCALL(SETUP_XfOrM1490(_), scheme_protect_quote ((((Scheme_Vector * ) (rest ) ) -> els ) [0 ] ) ); 
      if (! ((l ) == ((((Scheme_Vector * ) (rest ) ) -> els ) [0 ] ) ) ) {
        Scheme_Object * vec ; 
        long i , len ; 
        BLOCK_SETUP((PUSH(vec, 0+XfOrM1490_COUNT)));
#       define XfOrM1491_COUNT (1+XfOrM1490_COUNT)
#       define SETUP_XfOrM1491(x) SETUP(XfOrM1491_COUNT)
        vec = NULLED_OUT ; 
        len = (((Scheme_Vector * ) (rest ) ) -> size ) ; 
        vec = FUNCCALL(SETUP_XfOrM1491(_), scheme_make_vector (len , ((void * ) 0 ) ) ); 
        (((Scheme_Vector * ) (vec ) ) -> els ) [0 ] = l ; 
        for (i = 1 ; i < len ; i ++ ) {
          (((Scheme_Vector * ) (vec ) ) -> els ) [i ] = (((Scheme_Vector * ) (rest ) ) -> els ) [i ] ; 
        }
        rest = vec ; 
      }
    }
    else {
#     define XfOrM1489_COUNT (0+XfOrM1488_COUNT)
#     define SETUP_XfOrM1489(x) SETUP_XfOrM1488(x)
      FUNCCALL_EMPTY(scheme_signal_error ("expected a vector for syntax" ) ); 
    }
  }
  else {
#   define XfOrM1481_COUNT (0+XfOrM1480_COUNT)
#   define SETUP_XfOrM1481(x) SETUP_XfOrM1480(x)
    for (c = 0 ; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && (c < protect_after ) ; c ++ ) {
      l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
    }
    if (! ((l ) == (scheme_null ) ) && (c == protect_after ) ) {
      Scheme_Object * new_l ; 
      BLOCK_SETUP((PUSH(new_l, 0+XfOrM1481_COUNT)));
#     define XfOrM1482_COUNT (1+XfOrM1481_COUNT)
#     define SETUP_XfOrM1482(x) SETUP(XfOrM1482_COUNT)
      new_l = NULLED_OUT ; 
      new_l = FUNCCALL(SETUP_XfOrM1482(_), scheme_protect_quote (l ) ); 
      if (new_l != l ) {
        Scheme_Object * first = ((void * ) 0 ) , * last = ((void * ) 0 ) ; 
        BLOCK_SETUP((PUSH(first, 0+XfOrM1482_COUNT), PUSH(last, 1+XfOrM1482_COUNT)));
#       define XfOrM1483_COUNT (2+XfOrM1482_COUNT)
#       define SETUP_XfOrM1483(x) SETUP(XfOrM1483_COUNT)
        while (rest != l ) {
          Scheme_Object * p ; 
          BLOCK_SETUP((PUSH(p, 0+XfOrM1483_COUNT)));
#         define XfOrM1485_COUNT (1+XfOrM1483_COUNT)
#         define SETUP_XfOrM1485(x) SETUP(XfOrM1485_COUNT)
          p = NULLED_OUT ; 
          p = FUNCCALL(SETUP_XfOrM1485(_), scheme_make_pair ((((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . car ) , scheme_null ) ); 
          if (last )
            (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = p ; 
          else first = p ; 
          last = p ; 
          rest = (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) ; 
        }
        if (last )
          (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = new_l ; 
        else first = new_l ; 
        rest = first ; 
      }
    }
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_pair (idx , rest ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * read_syntax (Scheme_Object * obj ) {
  Scheme_Object * idx ; 
  Scheme_Object * first = ((void * ) 0 ) , * last = ((void * ) 0 ) ; 
  int limit ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(first, 0), PUSH(idx, 1), PUSH(obj, 2), PUSH(last, 3)));
# define XfOrM1494_COUNT (4)
# define SETUP_XfOrM1494(x) SETUP(XfOrM1494_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  idx = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || ! (((long ) ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ) ) & 0x1 ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  idx = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
  limit = scheme_syntax_protect_afters [(((long ) (idx ) ) >> 1 ) ] ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  while (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && (limit > 0 ) ) {
    Scheme_Object * p ; 
    BLOCK_SETUP((PUSH(p, 0+XfOrM1494_COUNT)));
#   define XfOrM1496_COUNT (1+XfOrM1494_COUNT)
#   define SETUP_XfOrM1496(x) SETUP(XfOrM1496_COUNT)
    p = NULLED_OUT ; 
    p = FUNCCALL(SETUP_XfOrM1496(_), scheme_make_pair ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) , scheme_null ) ); 
    if (last )
      (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = p ; 
    else first = p ; 
    last = p ; 
    obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
    limit -- ; 
  }
  if (last )
    (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = obj ; 
  else first = obj ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_syntax_resolved ((((long ) (idx ) ) >> 1 ) , first ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * write_quote_syntax (Scheme_Object * obj ) {
  Scheme_Quote_Syntax * qs = (Scheme_Quote_Syntax * ) obj ; 
  Scheme_Object * __funcarg152 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(qs, 0)));
# define XfOrM1497_COUNT (1)
# define SETUP_XfOrM1497(x) SETUP(XfOrM1497_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg152 = FUNCCALL(SETUP_XfOrM1497(_), scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (qs -> position ) ) << 1 ) | 0x1 ) ) , ((Scheme_Object * ) (void * ) (long ) ((((long ) (qs -> midpoint ) ) << 1 ) | 0x1 ) ) ) ), FUNCCALL_EMPTY(scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (qs -> depth ) ) << 1 ) | 0x1 ) ) , __funcarg152 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * read_quote_syntax (Scheme_Object * obj ) {
  Scheme_Quote_Syntax * qs ; 
  Scheme_Object * a ; 
  int c , i , p ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(qs, 0)));
# define XfOrM1498_COUNT (1)
# define SETUP_XfOrM1498(x) SETUP(XfOrM1498_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  qs = NULLED_OUT ; 
  a = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  a = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
  c = (((long ) (a ) ) >> 1 ) ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  a = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
  i = (((long ) (a ) ) >> 1 ) ; 
  a = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  p = (((long ) (a ) ) >> 1 ) ; 
  qs = ((Scheme_Quote_Syntax * ) FUNCCALL(SETUP_XfOrM1498(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Quote_Syntax ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  qs -> so . type = scheme_quote_syntax_type ; 
  qs -> depth = c ; 
  qs -> position = i ; 
  qs -> midpoint = p ; 
  RET_VALUE_START ((Scheme_Object * ) qs ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int mark_comp_info_SIZE (void * p ) {
  return ((sizeof (Scheme_Compile_Info ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_comp_info_MARK (void * p ) {
  Scheme_Compile_Info * i = (Scheme_Compile_Info * ) p ; 
  GC_mark (i -> value_name ) ; 
  GC_mark (i -> certs ) ; 
  GC_mark (i -> observer ) ; 
  return ((sizeof (Scheme_Compile_Info ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_comp_info_FIXUP (void * p ) {
  Scheme_Compile_Info * i = (Scheme_Compile_Info * ) p ; 
  GC_fixup (& (i -> value_name ) ) ; 
  GC_fixup (& (i -> certs ) ) ; 
  GC_fixup (& (i -> observer ) ) ; 
  return ((sizeof (Scheme_Compile_Info ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_saved_stack_SIZE (void * p ) {
  return ((sizeof (Scheme_Saved_Stack ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_saved_stack_MARK (void * p ) {
  Scheme_Saved_Stack * saved = (Scheme_Saved_Stack * ) p ; 
  GC_mark (saved -> prev ) ; 
  GC_mark (saved -> runstack_start ) ; 
  return ((sizeof (Scheme_Saved_Stack ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_saved_stack_FIXUP (void * p ) {
  Scheme_Saved_Stack * saved = (Scheme_Saved_Stack * ) p ; 
  GC_fixup (& (saved -> prev ) ) ; 
  GC_fixup (& (saved -> runstack_start ) ) ; 
  return ((sizeof (Scheme_Saved_Stack ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static void register_traversers (void ) {
  GC_register_traversers (scheme_rt_compile_info , mark_comp_info_SIZE , mark_comp_info_MARK , mark_comp_info_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_saved_stack , mark_saved_stack_SIZE , mark_saved_stack_MARK , mark_saved_stack_FIXUP , 1 , 0 ) ; 
}
