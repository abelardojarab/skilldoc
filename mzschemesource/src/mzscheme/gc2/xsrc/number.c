#include "precomp.h"
extern double acos (double __x ) __attribute__ ((__nothrow__ ) ) ; 
extern double asin (double __x ) __attribute__ ((__nothrow__ ) ) ; 
extern double atan (double __x ) __attribute__ ((__nothrow__ ) ) ; 
extern double atan2 (double __y , double __x ) __attribute__ ((__nothrow__ ) ) ; 
extern double cos (double __x ) __attribute__ ((__nothrow__ ) ) ; 
extern double sin (double __x ) __attribute__ ((__nothrow__ ) ) ; 
extern double tan (double __x ) __attribute__ ((__nothrow__ ) ) ; 
extern double exp (double __x ) __attribute__ ((__nothrow__ ) ) ; 
extern double log (double __x ) __attribute__ ((__nothrow__ ) ) ; 
extern double modf (double __x , double * __iptr ) __attribute__ ((__nothrow__ ) ) ; 
extern double pow (double __x , double __y ) __attribute__ ((__nothrow__ ) ) ; 
extern double sqrt (double __x ) __attribute__ ((__nothrow__ ) ) ; 
extern double ceil (double __x ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__const__ ) ) ; 
extern double floor (double __x ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__const__ ) ) ; 
extern double fmod (double __x , double __y ) __attribute__ ((__nothrow__ ) ) ; 
extern int isinf (double __value ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__const__ ) ) ; 
extern double significand (double __x ) __attribute__ ((__nothrow__ ) ) ; 
extern int isnan (double __value ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__const__ ) ) ; 
typedef enum {
  _IEEE_ = - 1 , _SVID_ , _XOPEN_ , _POSIX_ , _ISOC_ }
_LIB_VERSION_TYPE ; 
struct exception {
  int type ; 
  char * name ; 
  double arg1 ; 
  double arg2 ; 
  double retval ; 
}
; 
enum {
  _ISupper = ((0 ) < 8 ? ((1 << (0 ) ) << 8 ) : ((1 << (0 ) ) >> 8 ) ) , _ISlower = ((1 ) < 8 ? ((1 << (1 ) ) << 8 ) : ((1 << (1 ) ) >> 8 ) ) , _ISalpha = ((2 ) < 8 ? ((1 << (2 ) ) << 8 ) : ((1 << (2 ) ) >> 8 ) ) , _ISdigit = ((3 ) < 8 ? ((1 << (3 ) ) << 8 ) : ((1 << (3 ) ) >> 8 ) ) , _ISxdigit = ((4 ) < 8 ? ((1 << (4 ) ) << 8 ) : ((1 << (4 ) ) >> 8 ) ) , _ISspace = ((5 ) < 8 ? ((1 << (5 ) ) << 8 ) : ((1 << (5 ) ) >> 8 ) ) , _ISprint = ((6 ) < 8 ? ((1 << (6 ) ) << 8 ) : ((1 << (6 ) ) >> 8 ) ) , _ISgraph = ((7 ) < 8 ? ((1 << (7 ) ) << 8 ) : ((1 << (7 ) ) >> 8 ) ) , _ISblank = ((8 ) < 8 ? ((1 << (8 ) ) << 8 ) : ((1 << (8 ) ) >> 8 ) ) , _IScntrl = ((9 ) < 8 ? ((1 << (9 ) ) << 8 ) : ((1 << (9 ) ) >> 8 ) ) , _ISpunct = ((10 ) < 8 ? ((1 << (10 ) ) << 8 ) : ((1 << (10 ) ) >> 8 ) ) , _ISalnum = ((11 ) < 8 ? ((1 << (11 ) ) << 8 ) : ((1 << (11 ) ) >> 8 ) ) }
; 
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
double scheme_infinity_val , scheme_minus_infinity_val ; 
static Scheme_Object * number_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * complex_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * real_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * rational_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * integer_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * exact_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * even_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * bitwise_or (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * bitwise_xor (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * bitwise_not (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * integer_length (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * gcd (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * lcm (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * floor_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * ceiling (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * sch_truncate (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * sch_round (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * numerator (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * denominator (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * exp_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * log_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * sin_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * cos_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * tan_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * asin_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * acos_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * atan_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * make_rectangular (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * real_part (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * imag_part (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * magnitude (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * angle (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * int_sqrt (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * int_sqrt_rem (int argc , Scheme_Object * argv [] ) ; 
static double not_a_number_val ; 
Scheme_Object * scheme_inf_object , * scheme_minus_inf_object , * scheme_nan_object ; 
Scheme_Object * scheme_zerod , * scheme_nzerod , * scheme_pi , * scheme_half_pi , * scheme_plus_i , * scheme_minus_i ; 
double scheme_floating_point_zero = 0.0 ; 
double scheme_floating_point_nzero = 0.0 ; 
void scheme_init_number (Scheme_Env * env ) {
  Scheme_Object * p ; 
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
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(p, 1)));
# define XfOrM1_COUNT (2)
# define SETUP_XfOrM1(x) SETUP(XfOrM1_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  p = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_register_static ((void * ) & scheme_pi , sizeof (scheme_pi ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_half_pi , sizeof (scheme_half_pi ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_zerod , sizeof (scheme_zerod ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_nzerod , sizeof (scheme_nzerod ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_plus_i , sizeof (scheme_plus_i ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_minus_i , sizeof (scheme_minus_i ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_inf_object , sizeof (scheme_inf_object ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_minus_inf_object , sizeof (scheme_minus_inf_object ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_nan_object , sizeof (scheme_nan_object ) ) ); 
  signal (8 , ((__sighandler_t ) 1 ) ) ; 
  scheme_infinity_val = (FUNCCALL(SETUP_XfOrM1(_), __builtin_huge_val () )) ; 
  scheme_floating_point_nzero = - scheme_floating_point_nzero ; 
  scheme_minus_infinity_val = - scheme_infinity_val ; 
  not_a_number_val = scheme_infinity_val + scheme_minus_infinity_val ; 
  scheme_zerod = FUNCCALL(SETUP_XfOrM1(_), scheme_make_double (1.0 ) ); 
  (((Scheme_Double * ) (scheme_zerod ) ) -> double_val ) = 0.0 ; 
  scheme_nzerod = FUNCCALL(SETUP_XfOrM1(_), scheme_make_double (- 1.0 ) ); 
  (((Scheme_Double * ) (scheme_nzerod ) ) -> double_val ) = scheme_floating_point_nzero ; 
  scheme_pi = FUNCCALL(SETUP_XfOrM1(_), scheme_make_double (atan2 (0.0 , - 1.0 ) ) ); 
  scheme_half_pi = FUNCCALL_AGAIN(scheme_make_double (atan2 (0.0 , - 1.0 ) / 2 ) ); 
  scheme_plus_i = FUNCCALL_AGAIN(scheme_make_complex (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) , ((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) ) ); 
  scheme_minus_i = FUNCCALL_AGAIN(scheme_make_complex (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) , ((Scheme_Object * ) (void * ) (long ) ((((long ) (- 1 ) ) << 1 ) | 0x1 ) ) ) ); 
  scheme_inf_object = FUNCCALL_AGAIN(scheme_make_double (scheme_infinity_val ) ); 
  scheme_minus_inf_object = FUNCCALL_AGAIN(scheme_make_double (scheme_minus_infinity_val ) ); 
  scheme_nan_object = FUNCCALL_AGAIN(scheme_make_double (not_a_number_val ) ); 
  p = FUNCCALL_AGAIN(scheme_make_folding_prim (number_p , "number?" , 1 , 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 16384 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("number?" , p , env ) ); 
  (__funcarg39 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (complex_p , "complex?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("complex?" , __funcarg39 , env ) )) ; 
  p = FUNCCALL_AGAIN(scheme_make_folding_prim (real_p , "real?" , 1 , 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 16384 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("real?" , p , env ) ); 
  (__funcarg38 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (rational_p , "rational?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("rational?" , __funcarg38 , env ) )) ; 
  (__funcarg37 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (integer_p , "integer?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("integer?" , __funcarg37 , env ) )) ; 
  (__funcarg36 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (exact_p , "exact?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("exact?" , __funcarg36 , env ) )) ; 
  (__funcarg35 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (scheme_inexact_p , "inexact?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("inexact?" , __funcarg35 , env ) )) ; 
  (__funcarg34 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (scheme_odd_p , "odd?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("odd?" , __funcarg34 , env ) )) ; 
  (__funcarg33 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (even_p , "even?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("even?" , __funcarg33 , env ) )) ; 
  p = FUNCCALL_AGAIN(scheme_make_folding_prim (scheme_bitwise_and , "bitwise-and" , 0 , - 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 512 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("bitwise-and" , p , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_folding_prim (bitwise_or , "bitwise-ior" , 0 , - 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 512 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("bitwise-ior" , p , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_folding_prim (bitwise_xor , "bitwise-xor" , 0 , - 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 512 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("bitwise-xor" , p , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_folding_prim (bitwise_not , "bitwise-not" , 1 , 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 16384 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("bitwise-not" , p , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_folding_prim (scheme_bitwise_shift , "arithmetic-shift" , 2 , 2 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 512 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("arithmetic-shift" , p , env ) ); 
  (__funcarg32 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (integer_length , "integer-length" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("integer-length" , __funcarg32 , env ) )) ; 
  (__funcarg31 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (gcd , "gcd" , 0 , - 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("gcd" , __funcarg31 , env ) )) ; 
  (__funcarg30 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (lcm , "lcm" , 0 , - 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("lcm" , __funcarg30 , env ) )) ; 
  (__funcarg29 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (floor_prim , "floor" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("floor" , __funcarg29 , env ) )) ; 
  (__funcarg28 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (ceiling , "ceiling" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("ceiling" , __funcarg28 , env ) )) ; 
  (__funcarg27 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (sch_truncate , "truncate" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("truncate" , __funcarg27 , env ) )) ; 
  (__funcarg26 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (sch_round , "round" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("round" , __funcarg26 , env ) )) ; 
  (__funcarg25 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (numerator , "numerator" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("numerator" , __funcarg25 , env ) )) ; 
  (__funcarg24 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (denominator , "denominator" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("denominator" , __funcarg24 , env ) )) ; 
  (__funcarg23 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (exp_prim , "exp" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("exp" , __funcarg23 , env ) )) ; 
  (__funcarg22 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (log_prim , "log" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("log" , __funcarg22 , env ) )) ; 
  (__funcarg21 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (sin_prim , "sin" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("sin" , __funcarg21 , env ) )) ; 
  (__funcarg20 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (cos_prim , "cos" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("cos" , __funcarg20 , env ) )) ; 
  (__funcarg19 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (tan_prim , "tan" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("tan" , __funcarg19 , env ) )) ; 
  (__funcarg18 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (asin_prim , "asin" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("asin" , __funcarg18 , env ) )) ; 
  (__funcarg17 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (acos_prim , "acos" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("acos" , __funcarg17 , env ) )) ; 
  (__funcarg16 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (atan_prim , "atan" , 1 , 2 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("atan" , __funcarg16 , env ) )) ; 
  (__funcarg15 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (scheme_sqrt , "sqrt" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("sqrt" , __funcarg15 , env ) )) ; 
  (__funcarg14 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (int_sqrt , "integer-sqrt" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("integer-sqrt" , __funcarg14 , env ) )) ; 
  (__funcarg13 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_everything (int_sqrt_rem , 0 , "integer-sqrt/remainder" , 1 , 1 , 0 , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("integer-sqrt/remainder" , __funcarg13 , env ) )) ; 
  (__funcarg12 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (scheme_expt , "expt" , 2 , 2 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("expt" , __funcarg12 , env ) )) ; 
  (__funcarg11 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (make_rectangular , "make-rectangular" , 2 , 2 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-rectangular" , __funcarg11 , env ) )) ; 
  (__funcarg10 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (scheme_make_polar , "make-polar" , 2 , 2 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-polar" , __funcarg10 , env ) )) ; 
  (__funcarg9 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (real_part , "real-part" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("real-part" , __funcarg9 , env ) )) ; 
  (__funcarg8 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (imag_part , "imag-part" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("imag-part" , __funcarg8 , env ) )) ; 
  (__funcarg7 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (angle , "angle" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("angle" , __funcarg7 , env ) )) ; 
  (__funcarg6 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (magnitude , "magnitude" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("magnitude" , __funcarg6 , env ) )) ; 
  (__funcarg5 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (scheme_exact_to_inexact , "exact->inexact" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("exact->inexact" , __funcarg5 , env ) )) ; 
  (__funcarg4 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (scheme_inexact_to_exact , "inexact->exact" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("inexact->exact" , __funcarg4 , env ) )) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_integer_value (long i ) {
  /* No conversion */
  Scheme_Object * o = ((Scheme_Object * ) (void * ) (long ) ((((long ) (i ) ) << 1 ) | 0x1 ) ) ; 
  if ((((long ) (o ) ) >> 1 ) == i )
    return o ; 
  else return scheme_make_bignum (i ) ; 
}
Scheme_Object * scheme_make_integer_value_from_unsigned (unsigned long i ) {
  /* No conversion */
  Scheme_Object * o = ((Scheme_Object * ) (void * ) (long ) ((((long ) (i ) ) << 1 ) | 0x1 ) ) ; 
  if (((((long ) (o ) ) >> 1 ) >= 0 ) && ((unsigned long ) (((long ) (o ) ) >> 1 ) ) == i )
    return o ; 
  else return scheme_make_bignum_from_unsigned (i ) ; 
}
Scheme_Object * scheme_make_integer_value_from_long_long (mzlonglong i ) {
  /* No conversion */
  return scheme_make_integer_value (i ) ; 
}
Scheme_Object * scheme_make_integer_value_from_unsigned_long_long (umzlonglong i ) {
  /* No conversion */
  return scheme_make_integer_value_from_unsigned (i ) ; 
}
static Scheme_Object * fixnum_expt (long x , long y ) ; 
Scheme_Object * scheme_make_integer_value_from_unsigned_long_halves (unsigned long lowhalf , unsigned long hihalf ) {
  /* No conversion */
  umzlonglong v ; 
  v = ((umzlonglong ) lowhalf ) | ((umzlonglong ) hihalf << 32 ) ; 
  return scheme_make_integer_value_from_unsigned_long_long (v ) ; 
}
Scheme_Object * scheme_make_integer_value_from_long_halves (unsigned long lowhalf , unsigned long hihalf ) {
  /* No conversion */
  mzlonglong v ; 
  v = (mzlonglong ) lowhalf | ((mzlonglong ) hihalf << 32 ) ; 
  return scheme_make_integer_value_from_long_long (v ) ; 
}
int scheme_get_int_val (Scheme_Object * o , long * v ) {
  /* No conversion */
  if ((((long ) (o ) ) & 0x1 ) ) {
    * v = (((long ) (o ) ) >> 1 ) ; 
    return 1 ; 
  }
  else if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
    return scheme_bignum_get_int_val (o , v ) ; 
  else return 0 ; 
}
int scheme_get_unsigned_int_val (Scheme_Object * o , unsigned long * v ) {
  /* No conversion */
  if ((((long ) (o ) ) & 0x1 ) ) {
    long i = (((long ) (o ) ) >> 1 ) ; 
    if (i < 0 )
      return 0 ; 
    * v = i ; 
    return 1 ; 
  }
  else if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
    return scheme_bignum_get_unsigned_int_val (o , v ) ; 
  else return 0 ; 
}
int scheme_get_long_long_val (Scheme_Object * o , mzlonglong * v ) {
  /* No conversion */
  if ((((long ) (o ) ) & 0x1 ) ) {
    * v = (((long ) (o ) ) >> 1 ) ; 
    return 1 ; 
  }
  else if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
    return scheme_bignum_get_long_long_val (o , v ) ; 
  else return 0 ; 
}
int scheme_get_unsigned_long_long_val (Scheme_Object * o , umzlonglong * v ) {
  /* No conversion */
  if ((((long ) (o ) ) & 0x1 ) ) {
    long i = (((long ) (o ) ) >> 1 ) ; 
    if (i < 0 )
      return 0 ; 
    * v = i ; 
    return 1 ; 
  }
  else if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
    return scheme_bignum_get_unsigned_long_long_val (o , v ) ; 
  else return 0 ; 
}
int scheme_nonneg_exact_p (Scheme_Object * n ) {
  /* No conversion */
  return (((((long ) (n ) ) & 0x1 ) && ((((long ) (n ) ) >> 1 ) >= 0 ) ) || (((Scheme_Type ) (((((long ) (n ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) && ((& ((Scheme_Bignum * ) n ) -> iso ) -> so . keyex & 0x1 ) ) ) ; 
}
double scheme_real_to_double (Scheme_Object * r ) {
  /* No conversion */
  if ((((long ) (r ) ) & 0x1 ) )
    return (double ) (((long ) (r ) ) >> 1 ) ; 
  else if (((Scheme_Type ) (((((long ) (r ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (r ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) )
    return (((Scheme_Double * ) (r ) ) -> double_val ) ; 
  else if (((Scheme_Type ) (((((long ) (r ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (r ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
    return scheme_bignum_to_double (r ) ; 
  else if (((Scheme_Type ) (((((long ) (r ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (r ) ) -> type ) ) == (Scheme_Type ) (scheme_rational_type ) ) )
    return scheme_rational_to_double (r ) ; 
  else if ((((((long ) (r ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (r ) ) -> type ) == scheme_complex_izi_type ) )
    return scheme_real_to_double ((((Scheme_Complex * ) (r ) ) -> r ) ) ; 
  else return 0.0 ; 
}
__xform_nongcing__ static inline int minus_zero_p (double d ) {
  /* No conversion */
  return (1 / d ) < 0 ; 
}
int scheme_minus_zero_p (double d ) {
  /* No conversion */
  return minus_zero_p (d ) ; 
}
Scheme_Object * scheme_make_double (double d ) {
  /* No conversion */
  GC_CAN_IGNORE Scheme_Double * sd ; 
  if (d == 0.0 ) {
    if (minus_zero_p (d ) )
      return scheme_nzerod ; 
    else return scheme_zerod ; 
  }
  sd = (Scheme_Double * ) GC_malloc_one_small_dirty_tagged ((((sizeof (Scheme_Double ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) ; 
  ((& sd -> so ) -> keyex = 0 ) ; 
  sd -> so . type = scheme_double_type ; 
  (((Scheme_Double * ) (sd ) ) -> double_val ) = d ; 
  return (Scheme_Object * ) sd ; 
}
static Scheme_Object * number_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * o = argv [0 ] ; 
  return (((((long ) (o ) ) & 0x1 ) || ((((o ) -> type ) >= scheme_bignum_type ) && (((o ) -> type ) <= scheme_complex_type ) ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * complex_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * o = argv [0 ] ; 
  return (((((long ) (o ) ) & 0x1 ) || ((((o ) -> type ) >= scheme_bignum_type ) && (((o ) -> type ) <= scheme_complex_type ) ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * real_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * o = argv [0 ] ; 
  return (((((long ) (o ) ) & 0x1 ) || ((((o ) -> type ) >= scheme_bignum_type ) && (((o ) -> type ) <= scheme_complex_izi_type ) ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * rational_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * o = argv [0 ] ; 
  return (((((long ) (o ) ) & 0x1 ) || ((((o ) -> type ) >= scheme_bignum_type ) && (((o ) -> type ) <= scheme_complex_izi_type ) ) ) ? scheme_true : scheme_false ) ; 
}
int scheme_is_integer (const Scheme_Object * o ) {
  /* No conversion */
  if ((((long ) (o ) ) & 0x1 ) || ((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
    return 1 ; 
  if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ) {
    double d ; 
    d = (((Scheme_Double * ) (o ) ) -> double_val ) ; 
    if (floor (d ) == d )
      return 1 ; 
  }
  if ((((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) == scheme_complex_izi_type ) )
    return scheme_is_integer ((((Scheme_Complex * ) (o ) ) -> r ) ) ; 
  return 0 ; 
}
static Scheme_Object * integer_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_is_integer (argv [0 ] ) ? scheme_true : scheme_false ; 
}
int scheme_is_exact (const Scheme_Object * n ) {
  /* No conversion */
  if ((((long ) (n ) ) & 0x1 ) ) {
    return 1 ; 
  }
  else {
    Scheme_Type type = ((n ) -> type ) ; 
    if ((type == scheme_bignum_type ) || (type == scheme_rational_type ) )
      return 1 ; 
    else if (type == scheme_complex_type ) {
      return scheme_is_complex_exact (n ) ; 
    }
    else if (type == scheme_double_type )
      return 0 ; 
    else if (type == scheme_complex_izi_type )
      return 0 ; 
    else {
      return - 1 ; 
    }
  }
}
Scheme_Object * exact_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  int v ; 
  v = scheme_is_exact (argv [0 ] ) ; 
  if (v < 0 ) {
    scheme_wrong_type ("exact?" , "number" , 0 , argc , argv ) ; 
    return ((void * ) 0 ) ; 
  }
  return (v ? scheme_true : scheme_false ) ; 
}
int scheme_is_inexact (const Scheme_Object * n ) {
  /* No conversion */
  if ((((long ) (n ) ) & 0x1 ) ) {
    return 0 ; 
  }
  else {
    Scheme_Type type = ((n ) -> type ) ; 
    if ((type == scheme_bignum_type ) || (type == scheme_rational_type ) )
      return 0 ; 
    else if (type == scheme_complex_type ) {
      return ! scheme_is_complex_exact (n ) ; 
    }
    else if (type == scheme_double_type )
      return 1 ; 
    else if (type == scheme_complex_izi_type )
      return 1 ; 
    else {
      return - 1 ; 
    }
  }
}
Scheme_Object * scheme_inexact_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  int v ; 
  v = scheme_is_inexact (argv [0 ] ) ; 
  if (v < 0 ) {
    scheme_wrong_type ("inexact?" , "number" , 0 , argc , argv ) ; 
    return ((void * ) 0 ) ; 
  }
  return (v ? scheme_true : scheme_false ) ; 
}
Scheme_Object * scheme_odd_p (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * v = argv [0 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(argv, 1)));
# define XfOrM43_COUNT (2)
# define SETUP_XfOrM43(x) SETUP(XfOrM43_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((((long ) (v ) ) & 0x1 ) )
    RET_VALUE_START (((((long ) (v ) ) >> 1 ) & 0x1 ) ? scheme_true : scheme_false ) RET_VALUE_END ; 
  if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
    RET_VALUE_START (((((Scheme_Bignum * ) v ) -> digits ) [0 ] & 0x1 ) ? scheme_true : scheme_false ) RET_VALUE_END ; 
  if ((((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) == scheme_complex_izi_type ) ) {
    Scheme_Object * r = (((Scheme_Complex * ) (v ) ) -> r ) ; 
    BLOCK_SETUP((PUSH(r, 0+XfOrM43_COUNT)));
#   define XfOrM45_COUNT (1+XfOrM43_COUNT)
#   define SETUP_XfOrM45(x) SETUP(XfOrM45_COUNT)
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM45(_), scheme_odd_p (1 , & r ) )) RET_VALUE_END ; 
  }
  if ((scheme_is_integer (v ) ) ) {
    double d = (((Scheme_Double * ) (v ) ) -> double_val ) ; 
    if ((isinf (d ) && (d > 0 ) ) || (isinf (d ) && (d < 0 ) ) )
      RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
    RET_VALUE_START ((fmod (d , 2.0 ) == 0.0 ) ? scheme_false : scheme_true ) RET_VALUE_END ; 
  }
  FUNCCALL_EMPTY(scheme_wrong_type ("odd?" , "integer" , 0 , argc , argv ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * even_p (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * v = argv [0 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(argv, 1)));
# define XfOrM46_COUNT (2)
# define SETUP_XfOrM46(x) SETUP(XfOrM46_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((((long ) (v ) ) & 0x1 ) )
    RET_VALUE_START (((((long ) (v ) ) >> 1 ) & 0x1 ) ? scheme_false : scheme_true ) RET_VALUE_END ; 
  if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
    RET_VALUE_START (((((Scheme_Bignum * ) v ) -> digits ) [0 ] & 0x1 ) ? scheme_false : scheme_true ) RET_VALUE_END ; 
  if ((((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) == scheme_complex_izi_type ) ) {
    Scheme_Object * r = (((Scheme_Complex * ) (v ) ) -> r ) ; 
    BLOCK_SETUP((PUSH(r, 0+XfOrM46_COUNT)));
#   define XfOrM48_COUNT (1+XfOrM46_COUNT)
#   define SETUP_XfOrM48(x) SETUP(XfOrM48_COUNT)
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM48(_), even_p (1 , & r ) )) RET_VALUE_END ; 
  }
  if ((scheme_is_integer (v ) ) ) {
    double d = (((Scheme_Double * ) (v ) ) -> double_val ) ; 
    if ((isinf (d ) && (d > 0 ) ) || (isinf (d ) && (d < 0 ) ) )
      RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
    RET_VALUE_START ((fmod (d , 2.0 ) == 0.0 ) ? scheme_true : scheme_false ) RET_VALUE_END ; 
  }
  FUNCCALL_EMPTY(scheme_wrong_type ("even?" , "integer" , 0 , argc , argv ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * bin_lcm (Scheme_Object * n1 , Scheme_Object * n2 ) ; 
static Scheme_Object * gcd (int argc , Scheme_Object * argv [] ) ; 
static inline Scheme_Object * gcd__slow (Scheme_Object * ret , int argc , Scheme_Object * argv [] ) {
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(ret, 0), PUSH(argv, 1)));
# define XfOrM49_COUNT (2)
# define SETUP_XfOrM49(x) SETUP(XfOrM49_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  for (i = 1 ; i < argc ; ++ i ) {
    Scheme_Object * o ; 
    BLOCK_SETUP((PUSH(o, 0+XfOrM49_COUNT)));
#   define XfOrM52_COUNT (1+XfOrM49_COUNT)
#   define SETUP_XfOrM52(x) SETUP(XfOrM52_COUNT)
    o = NULLED_OUT ; 
    o = argv [i ] ; 
    if (! (scheme_is_integer (o ) ) ) {
#     define XfOrM53_COUNT (0+XfOrM52_COUNT)
#     define SETUP_XfOrM53(x) SETUP_XfOrM52(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("gcd" , "integer" , i , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    ret = FUNCCALL(SETUP_XfOrM52(_), scheme_bin_gcd (ret , o ) ); 
  }
  RET_VALUE_START ((ret ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * gcd (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * ret ; 
  if (! argc )
    return ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
  ret = argv [0 ] ; 
  if (! scheme_is_integer (ret ) ) {
    scheme_wrong_type ("gcd" , "integer" , 0 , argc , argv ) ; 
    return ((void * ) 0 ) ; 
  }
  if (argc == 2 ) {
    Scheme_Object * b ; 
    b = argv [1 ] ; 
    if (! scheme_is_integer (b ) ) {
      scheme_wrong_type ("gcd" , "integer" , 1 , argc , argv ) ; 
      return ((void * ) 0 ) ; 
    }
    return scheme_bin_gcd (ret , b ) ; 
  }
  return gcd__slow (ret , argc , argv ) ; 
}
static Scheme_Object * lcm (int argc , Scheme_Object * argv [] ) ; 
static inline Scheme_Object * lcm__slow (Scheme_Object * ret , int argc , Scheme_Object * argv [] ) {
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(ret, 0), PUSH(argv, 1)));
# define XfOrM58_COUNT (2)
# define SETUP_XfOrM58(x) SETUP(XfOrM58_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  for (i = 1 ; i < argc ; ++ i ) {
    Scheme_Object * o ; 
    BLOCK_SETUP((PUSH(o, 0+XfOrM58_COUNT)));
#   define XfOrM61_COUNT (1+XfOrM58_COUNT)
#   define SETUP_XfOrM61(x) SETUP(XfOrM61_COUNT)
    o = NULLED_OUT ; 
    o = argv [i ] ; 
    if (! (scheme_is_integer (o ) ) ) {
#     define XfOrM62_COUNT (0+XfOrM61_COUNT)
#     define SETUP_XfOrM62(x) SETUP_XfOrM61(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("lcm" , "integer" , i , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    ret = FUNCCALL(SETUP_XfOrM61(_), bin_lcm (ret , o ) ); 
  }
  RET_VALUE_START ((ret ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * lcm (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * ret ; 
  if (! argc )
    return ((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) ; 
  ret = argv [0 ] ; 
  if (! scheme_is_integer (ret ) ) {
    scheme_wrong_type ("lcm" , "integer" , 0 , argc , argv ) ; 
    return ((void * ) 0 ) ; 
  }
  if (argc == 2 ) {
    Scheme_Object * b ; 
    b = argv [1 ] ; 
    if (! scheme_is_integer (b ) ) {
      scheme_wrong_type ("lcm" , "integer" , 1 , argc , argv ) ; 
      return ((void * ) 0 ) ; 
    }
    return bin_lcm (ret , b ) ; 
  }
  return lcm__slow (ret , argc , argv ) ; 
}
Scheme_Object * scheme_bin_gcd (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(n1, 0), PUSH(n2, 1)));
# define XfOrM67_COUNT (2)
# define SETUP_XfOrM67(x) SETUP(XfOrM67_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if ((((((long ) (n1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n1 ) ) -> type ) == scheme_complex_izi_type ) )
    n1 = (((Scheme_Complex * ) (n1 ) ) -> r ) ; 
  if ((((((long ) (n2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n2 ) ) -> type ) == scheme_complex_izi_type ) )
    n2 = (((Scheme_Complex * ) (n2 ) ) -> r ) ; 
  if ((((long ) (n1 ) ) & 0x1 ) && (((long ) (n2 ) ) & 0x1 ) ) {
    long i1 , i2 , a , b , r ; 
    i1 = (((long ) (n1 ) ) >> 1 ) ; 
    i2 = (((long ) (n2 ) ) >> 1 ) ; 
    if (i1 < 0 )
      i1 = - i1 ; 
    if (i2 < 0 )
      i2 = - i2 ; 
    if (i1 > i2 ) {
      a = i1 ; 
      b = i2 ; 
    }
    else {
      a = i2 ; 
      b = i1 ; 
    }
    while (b > 0 ) {
      r = a % b ; 
      a = b ; 
      b = r ; 
    }
    RET_VALUE_START ((((Scheme_Object * ) (void * ) (long ) ((((long ) (a ) ) << 1 ) | 0x1 ) ) ) ) RET_VALUE_END ; 
  }
  else if (((Scheme_Type ) (((((long ) (n1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n1 ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) || ((Scheme_Type ) (((((long ) (n2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n2 ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ) {
    double i1 , i2 , a , b , r ; 
#   define XfOrM69_COUNT (0+XfOrM67_COUNT)
#   define SETUP_XfOrM69(x) SETUP_XfOrM67(x)
    if ((((long ) (n1 ) ) & 0x1 ) )
      i1 = (((long ) (n1 ) ) >> 1 ) ; 
    else if (((Scheme_Type ) (((((long ) (n1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n1 ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) )
      i1 = (((Scheme_Double * ) (n1 ) ) -> double_val ) ; 
    else i1 = scheme_bignum_to_double (n1 ) ; 
    if ((((long ) (n2 ) ) & 0x1 ) )
      i2 = (((long ) (n2 ) ) >> 1 ) ; 
    else if (((Scheme_Type ) (((((long ) (n2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n2 ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) )
      i2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
    else i2 = scheme_bignum_to_double (n2 ) ; 
    if (i1 < 0 )
      i1 = - i1 ; 
    if (i2 < 0 )
      i2 = - i2 ; 
    if (i1 > i2 ) {
      a = i1 ; 
      b = i2 ; 
    }
    else {
      a = i2 ; 
      b = i1 ; 
    }
    if ((isinf (a ) && (a > 0 ) ) ) {
#     define XfOrM72_COUNT (0+XfOrM69_COUNT)
#     define SETUP_XfOrM72(x) SETUP_XfOrM69(x)
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_double (b ) )) RET_VALUE_EMPTY_END ; 
    }
    while (b > 0 ) {
      r = fmod (a , b ) ; 
      a = b ; 
      b = r ; 
    }
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_double (a ) )) RET_VALUE_EMPTY_END ; 
  }
  else {
#   define XfOrM68_COUNT (0+XfOrM67_COUNT)
#   define SETUP_XfOrM68(x) SETUP_XfOrM67(x)
    n1 = FUNCCALL(SETUP_XfOrM68(_), scheme_to_bignum (n1 ) ); 
    n2 = FUNCCALL(SETUP_XfOrM68(_), scheme_to_bignum (n2 ) ); 
    if (! ((& ((Scheme_Bignum * ) n1 ) -> iso ) -> so . keyex & 0x1 ) )
      n1 = FUNCCALL(SETUP_XfOrM68(_), scheme_bignum_negate (n1 ) ); 
    if (! ((& ((Scheme_Bignum * ) n2 ) -> iso ) -> so . keyex & 0x1 ) )
      n2 = FUNCCALL(SETUP_XfOrM68(_), scheme_bignum_negate (n2 ) ); 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_bignum_gcd (n1 , n2 ) )) RET_VALUE_EMPTY_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * bin_lcm (Scheme_Object * n1 , Scheme_Object * n2 ) {
  Scheme_Object * d , * ret ; 
  Scheme_Object * __funcarg40 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(d, 0), PUSH(n1, 1), PUSH(ret, 2), PUSH(n2, 3)));
# define XfOrM80_COUNT (4)
# define SETUP_XfOrM80(x) SETUP(XfOrM80_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  d = NULLED_OUT ; 
  ret = NULLED_OUT ; 
  d = FUNCCALL(SETUP_XfOrM80(_), scheme_bin_gcd (n1 , n2 ) ); 
  ret = (__funcarg40 = FUNCCALL(SETUP_XfOrM80(_), scheme_bin_quotient (n2 , d ) ), FUNCCALL_AGAIN(scheme_bin_mult (n1 , __funcarg40 ) )) ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM80(_), scheme_abs (1 , & ret ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * floor_prim (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * o = argv [0 ] ; 
  Scheme_Type t ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM81_COUNT (1)
# define SETUP_XfOrM81(x) SETUP(XfOrM81_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((((long ) (o ) ) & 0x1 ) )
    RET_VALUE_START (o ) RET_VALUE_END ; 
  t = ((o ) -> type ) ; 
  if (t == scheme_double_type )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_double (floor ((((Scheme_Double * ) (o ) ) -> double_val ) ) ) )) RET_VALUE_EMPTY_END ; 
  if (t == scheme_bignum_type )
    RET_VALUE_START (o ) RET_VALUE_END ; 
  if (t == scheme_rational_type )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_rational_floor (o ) )) RET_VALUE_EMPTY_END ; 
  if (t == scheme_complex_izi_type ) {
    Scheme_Object * r = (((Scheme_Complex * ) (o ) ) -> r ) ; 
    BLOCK_SETUP((PUSH(r, 0+XfOrM81_COUNT)));
#   define XfOrM82_COUNT (1+XfOrM81_COUNT)
#   define SETUP_XfOrM82(x) SETUP(XfOrM82_COUNT)
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM82(_), floor_prim (1 , & r ) )) RET_VALUE_END ; 
  }
  FUNCCALL_EMPTY(scheme_wrong_type ("floor" , "real number" , 0 , argc , argv ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * ceiling (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * o = argv [0 ] ; 
  Scheme_Type t ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM83_COUNT (1)
# define SETUP_XfOrM83(x) SETUP(XfOrM83_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((((long ) (o ) ) & 0x1 ) )
    RET_VALUE_START (o ) RET_VALUE_END ; 
  t = ((o ) -> type ) ; 
  if (t == scheme_double_type )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_double (ceil ((((Scheme_Double * ) (o ) ) -> double_val ) ) ) )) RET_VALUE_EMPTY_END ; 
  if (t == scheme_bignum_type )
    RET_VALUE_START (o ) RET_VALUE_END ; 
  if (t == scheme_rational_type )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_rational_ceiling (o ) )) RET_VALUE_EMPTY_END ; 
  if (t == scheme_complex_izi_type ) {
    Scheme_Object * r = (((Scheme_Complex * ) (o ) ) -> r ) ; 
    BLOCK_SETUP((PUSH(r, 0+XfOrM83_COUNT)));
#   define XfOrM84_COUNT (1+XfOrM83_COUNT)
#   define SETUP_XfOrM84(x) SETUP(XfOrM84_COUNT)
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM84(_), ceiling (1 , & r ) )) RET_VALUE_END ; 
  }
  FUNCCALL_EMPTY(scheme_wrong_type ("ceiling" , "real number" , 0 , argc , argv ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * sch_truncate (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * o = argv [0 ] ; 
  Scheme_Type t ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM85_COUNT (1)
# define SETUP_XfOrM85(x) SETUP(XfOrM85_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((((long ) (o ) ) & 0x1 ) )
    RET_VALUE_START (o ) RET_VALUE_END ; 
  t = ((o ) -> type ) ; 
  if (t == scheme_double_type ) {
    double v = (((Scheme_Double * ) (o ) ) -> double_val ) ; 
#   define XfOrM87_COUNT (0+XfOrM85_COUNT)
#   define SETUP_XfOrM87(x) SETUP_XfOrM85(x)
    if (v > 0 )
      v = floor (v ) ; 
    else v = ceil (v ) ; 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_double (v ) )) RET_VALUE_EMPTY_END ; 
  }
  if (t == scheme_bignum_type )
    RET_VALUE_START (o ) RET_VALUE_END ; 
  if (t == scheme_rational_type )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_rational_truncate (o ) )) RET_VALUE_EMPTY_END ; 
  if (t == scheme_complex_izi_type ) {
    Scheme_Object * r = (((Scheme_Complex * ) (o ) ) -> r ) ; 
    BLOCK_SETUP((PUSH(r, 0+XfOrM85_COUNT)));
#   define XfOrM86_COUNT (1+XfOrM85_COUNT)
#   define SETUP_XfOrM86(x) SETUP(XfOrM86_COUNT)
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM86(_), sch_truncate (1 , & r ) )) RET_VALUE_END ; 
  }
  FUNCCALL_EMPTY(scheme_wrong_type ("truncate" , "real number" , 0 , argc , argv ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * sch_round (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * o = argv [0 ] ; 
  Scheme_Type t ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(o, 1)));
# define XfOrM88_COUNT (2)
# define SETUP_XfOrM88(x) SETUP(XfOrM88_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((((long ) (o ) ) & 0x1 ) )
    RET_VALUE_START (o ) RET_VALUE_END ; 
  t = ((o ) -> type ) ; 
  if (t == scheme_double_type ) {
    double d = (((Scheme_Double * ) (o ) ) -> double_val ) ; 
    double i , frac ; 
    int invert ; 
#   define XfOrM90_COUNT (0+XfOrM88_COUNT)
#   define SETUP_XfOrM90(x) SETUP_XfOrM88(x)
    if (d < 0 ) {
      d = - d ; 
      invert = 1 ; 
    }
    else invert = 0 ; 
    frac = FUNCCALL(SETUP_XfOrM90(_), modf (d , & i ) ); 
    if (frac < 0.5 )
      d = i ; 
    else if (frac > 0.5 )
      d = i + 1 ; 
    else if (fmod (i , 2.0 ) != 0.0 )
      d = i + 1 ; 
    else d = i ; 
    if (invert )
      d = - d ; 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_double (d ) )) RET_VALUE_EMPTY_END ; 
  }
  if (t == scheme_bignum_type )
    RET_VALUE_START (o ) RET_VALUE_END ; 
  if (t == scheme_rational_type )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_rational_round (o ) )) RET_VALUE_EMPTY_END ; 
  if (t == scheme_complex_izi_type ) {
    Scheme_Object * r = (((Scheme_Complex * ) (o ) ) -> r ) ; 
    BLOCK_SETUP((PUSH(r, 0+XfOrM88_COUNT)));
#   define XfOrM89_COUNT (1+XfOrM88_COUNT)
#   define SETUP_XfOrM89(x) SETUP(XfOrM89_COUNT)
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM89(_), sch_round (1 , & r ) )) RET_VALUE_END ; 
  }
  FUNCCALL_EMPTY(scheme_wrong_type ("round" , "real number" , 0 , argc , argv ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_TO_DOUBLE (const Scheme_Object * n ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(n, 0)));
# define XfOrM92_COUNT (1)
# define SETUP_XfOrM92(x) SETUP(XfOrM92_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if ((((((long ) (n ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n ) ) -> type ) == scheme_complex_izi_type ) )
    n = (((Scheme_Complex * ) (n ) ) -> r ) ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM92(_), scheme_exact_to_inexact (1 , (Scheme_Object * * ) & n ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
double scheme_get_val_as_double (const Scheme_Object * n ) {
  /* No conversion */
  return (((Scheme_Double * ) (scheme_TO_DOUBLE (n ) ) ) -> double_val ) ; 
}
Scheme_Object * scheme_to_bignum (const Scheme_Object * o ) {
  /* No conversion */
  if ((((long ) (o ) ) & 0x1 ) )
    return scheme_make_bignum ((((long ) (o ) ) >> 1 ) ) ; 
  else return (Scheme_Object * ) o ; 
}
static Scheme_Object * get_frac (char * name , int low_p , int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * get_frac (char * name , int low_p , int argc , Scheme_Object * argv [] ) {
  Scheme_Object * n = argv [0 ] , * orig ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(orig, 0), PUSH(n, 1), PUSH(argv, 2), PUSH(name, 3)));
# define XfOrM95_COUNT (4)
# define SETUP_XfOrM95(x) SETUP(XfOrM95_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  orig = NULLED_OUT ; 
  if ((((((long ) (n ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n ) ) -> type ) == scheme_complex_izi_type ) )
    n = (((Scheme_Complex * ) (n ) ) -> r ) ; 
  orig = n ; 
  if (((Scheme_Type ) (((((long ) (n ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ) {
    double d = (((Scheme_Double * ) (n ) ) -> double_val ) ; 
#   define XfOrM98_COUNT (0+XfOrM95_COUNT)
#   define SETUP_XfOrM98(x) SETUP_XfOrM95(x)
    if (isnan (d ) )
      RET_VALUE_START (n ) RET_VALUE_END ; 
    else if ((isinf (d ) && (d > 0 ) ) || (isinf (d ) && (d < 0 ) ) ) {
#     define XfOrM99_COUNT (0+XfOrM98_COUNT)
#     define SETUP_XfOrM99(x) SETUP_XfOrM98(x)
      if (low_p ) {
#       define XfOrM100_COUNT (0+XfOrM99_COUNT)
#       define SETUP_XfOrM100(x) SETUP_XfOrM99(x)
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_double (1.0 ) )) RET_VALUE_EMPTY_END ; 
      }
      else RET_VALUE_START (n ) RET_VALUE_END ; 
    }
    n = FUNCCALL(SETUP_XfOrM98(_), scheme_rational_from_double (d ) ); 
  }
  if ((((long ) (n ) ) & 0x1 ) || ((Scheme_Type ) (((((long ) (n ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
    n = low_p ? ((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) : n ; 
  else if (((Scheme_Type ) (((((long ) (n ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n ) ) -> type ) ) == (Scheme_Type ) (scheme_rational_type ) ) ) {
#   define XfOrM97_COUNT (0+XfOrM95_COUNT)
#   define SETUP_XfOrM97(x) SETUP_XfOrM95(x)
    if (low_p )
      n = FUNCCALL(SETUP_XfOrM97(_), scheme_rational_denominator (n ) ); 
    else n = FUNCCALL(SETUP_XfOrM97(_), scheme_rational_numerator (n ) ); 
  }
  else {
#   define XfOrM96_COUNT (0+XfOrM95_COUNT)
#   define SETUP_XfOrM96(x) SETUP_XfOrM95(x)
    FUNCCALL_EMPTY(scheme_wrong_type (name , "real number" , 0 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (((Scheme_Type ) (((((long ) (orig ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (orig ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_TO_DOUBLE (n ) )) RET_VALUE_EMPTY_END ; 
  else RET_VALUE_START (n ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * un_exp (Scheme_Object * o ) ; 
static Scheme_Object * un_log (Scheme_Object * o ) ; 
static Scheme_Object * un_exp (Scheme_Object * o ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(o, 0)));
# define XfOrM101_COUNT (1)
# define SETUP_XfOrM101(x) SETUP(XfOrM101_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM101(_), exp_prim (1 , & o ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * un_log (Scheme_Object * o ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(o, 0)));
# define XfOrM102_COUNT (1)
# define SETUP_XfOrM102(x) SETUP(XfOrM102_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM102(_), log_prim (1 , & o ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * numerator (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return get_frac ("numerator" , 0 , argc , argv ) ; 
}
static Scheme_Object * denominator (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return get_frac ("denominator" , 1 , argc , argv ) ; 
}
static Scheme_Object * complex_exp (Scheme_Object * c ) ; 
static Scheme_Object * complex_exp (Scheme_Object * c ) {
  Scheme_Object * r = (((Scheme_Complex * ) (c ) ) -> r ) ; 
  Scheme_Object * i = (((Scheme_Complex * ) (c ) ) -> i ) ; 
  Scheme_Object * cos_a , * sin_a ; 
  Scheme_Object * __funcarg42 = NULLED_OUT ; 
  Scheme_Object * __funcarg41 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(i, 0), PUSH(sin_a, 1), PUSH(r, 2), PUSH(cos_a, 3)));
# define XfOrM105_COUNT (4)
# define SETUP_XfOrM105(x) SETUP(XfOrM105_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  cos_a = NULLED_OUT ; 
  sin_a = NULLED_OUT ; 
  r = FUNCCALL(SETUP_XfOrM105(_), exp_prim (1 , & r ) ); 
  cos_a = FUNCCALL_AGAIN(cos_prim (1 , & i ) ); 
  sin_a = FUNCCALL_AGAIN(sin_prim (1 , & i ) ); 
  RET_VALUE_START ((__funcarg41 = (__funcarg42 = FUNCCALL(SETUP_XfOrM105(_), scheme_bin_mult (sin_a , scheme_plus_i ) ), FUNCCALL_AGAIN(scheme_bin_plus (cos_a , __funcarg42 ) )) , FUNCCALL_AGAIN(scheme_bin_mult (r , __funcarg41 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * complex_log (Scheme_Object * c ) ; 
static Scheme_Object * complex_log (Scheme_Object * c ) {
  Scheme_Object * m , * theta ; 
  Scheme_Object * __funcarg44 = NULLED_OUT ; 
  Scheme_Object * __funcarg43 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(c, 0), PUSH(__funcarg43, 1), PUSH(theta, 2), PUSH(m, 3)));
# define XfOrM106_COUNT (4)
# define SETUP_XfOrM106(x) SETUP(XfOrM106_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  m = NULLED_OUT ; 
  theta = NULLED_OUT ; 
  m = FUNCCALL(SETUP_XfOrM106(_), magnitude (1 , & c ) ); 
  theta = FUNCCALL_AGAIN(angle (1 , & c ) ); 
  RET_VALUE_START ((__funcarg43 = FUNCCALL(SETUP_XfOrM106(_), log_prim (1 , & m ) ), __funcarg44 = FUNCCALL(SETUP_XfOrM106(_), scheme_bin_mult (scheme_plus_i , theta ) ), FUNCCALL_AGAIN(scheme_bin_plus (__funcarg43 , __funcarg44 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * bignum_log (Scheme_Object * b ) {
  Scheme_Object * rem ; 
  int d_count = 0 ; 
  double d ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(rem, 0), PUSH(b, 1)));
# define XfOrM107_COUNT (2)
# define SETUP_XfOrM107(x) SETUP(XfOrM107_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  rem = NULLED_OUT ; 
  if (! ((& ((Scheme_Bignum * ) b ) -> iso ) -> so . keyex & 0x1 ) )
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM107(_), complex_log (b ) )) RET_VALUE_END ; 
  while ((((Scheme_Bignum * ) b ) -> len ) >= 15 ) {
#   define XfOrM111_COUNT (0+XfOrM107_COUNT)
#   define SETUP_XfOrM111(x) SETUP_XfOrM107(x)
    b = FUNCCALL(SETUP_XfOrM111(_), scheme_integer_sqrt_rem (b , & rem ) ); 
    d_count ++ ; 
  }
  if (((Scheme_Type ) (((((long ) (b ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (b ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
    d = scheme_bignum_to_double (b ) ; 
  else d = (((long ) (b ) ) >> 1 ) ; 
  d = log (d ) ; 
  while (d_count -- ) {
    d = d * 2 ; 
  }
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM107(_), scheme_make_double (d ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * complex_sin (Scheme_Object * c ) ; 
static Scheme_Object * complex_sin (Scheme_Object * c ) {
  Scheme_Object * i_c ; 
  Scheme_Object * __funcarg49 = NULLED_OUT ; 
  Scheme_Object * __funcarg48 = NULLED_OUT ; 
  Scheme_Object * __funcarg47 = NULLED_OUT ; 
  Scheme_Object * __funcarg46 = NULLED_OUT ; 
  Scheme_Object * __funcarg45 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(__funcarg47, 0), PUSH(__funcarg45, 1), PUSH(i_c, 2)));
# define XfOrM112_COUNT (3)
# define SETUP_XfOrM112(x) SETUP(XfOrM112_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  i_c = NULLED_OUT ; 
  i_c = FUNCCALL(SETUP_XfOrM112(_), scheme_bin_mult (c , scheme_plus_i ) ); 
  RET_VALUE_START ((__funcarg45 = (__funcarg47 = FUNCCALL(SETUP_XfOrM112(_), un_exp (i_c ) ), __funcarg48 = (__funcarg49 = FUNCCALL(SETUP_XfOrM112(_), scheme_bin_minus (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) , i_c ) ), FUNCCALL_AGAIN(un_exp (__funcarg49 ) )) , FUNCCALL_AGAIN(scheme_bin_minus (__funcarg47 , __funcarg48 ) )) , __funcarg46 = FUNCCALL(SETUP_XfOrM112(_), scheme_bin_mult (((Scheme_Object * ) (void * ) (long ) ((((long ) (2 ) ) << 1 ) | 0x1 ) ) , scheme_plus_i ) ), FUNCCALL_EMPTY(scheme_bin_div (__funcarg45 , __funcarg46 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * complex_cos (Scheme_Object * c ) ; 
static Scheme_Object * complex_cos (Scheme_Object * c ) {
  Scheme_Object * i_c ; 
  Scheme_Object * __funcarg53 = NULLED_OUT ; 
  Scheme_Object * __funcarg52 = NULLED_OUT ; 
  Scheme_Object * __funcarg51 = NULLED_OUT ; 
  Scheme_Object * __funcarg50 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(__funcarg51, 0), PUSH(i_c, 1)));
# define XfOrM113_COUNT (2)
# define SETUP_XfOrM113(x) SETUP(XfOrM113_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  i_c = NULLED_OUT ; 
  i_c = FUNCCALL(SETUP_XfOrM113(_), scheme_bin_mult (c , scheme_plus_i ) ); 
  RET_VALUE_START ((__funcarg50 = (__funcarg51 = FUNCCALL(SETUP_XfOrM113(_), un_exp (i_c ) ), __funcarg52 = (__funcarg53 = FUNCCALL(SETUP_XfOrM113(_), scheme_bin_minus (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) , i_c ) ), FUNCCALL_AGAIN(un_exp (__funcarg53 ) )) , FUNCCALL_AGAIN(scheme_bin_plus (__funcarg51 , __funcarg52 ) )) , FUNCCALL_EMPTY(scheme_bin_div (__funcarg50 , ((Scheme_Object * ) (void * ) (long ) ((((long ) (2 ) ) << 1 ) | 0x1 ) ) ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * complex_tan (Scheme_Object * c ) ; 
static Scheme_Object * complex_tan (Scheme_Object * c ) {
  Scheme_Object * __funcarg55 = NULLED_OUT ; 
  Scheme_Object * __funcarg54 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(c, 0), PUSH(__funcarg54, 1)));
# define XfOrM114_COUNT (2)
# define SETUP_XfOrM114(x) SETUP(XfOrM114_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg54 = FUNCCALL(SETUP_XfOrM114(_), complex_sin (c ) ), __funcarg55 = FUNCCALL(SETUP_XfOrM114(_), complex_cos (c ) ), FUNCCALL_EMPTY(scheme_bin_div (__funcarg54 , __funcarg55 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * complex_asin (Scheme_Object * c ) ; 
static Scheme_Object * complex_asin (Scheme_Object * c ) {
  Scheme_Object * one_minus_c_sq , * sqrt_1_minus_c_sq ; 
  Scheme_Object * __funcarg59 = NULLED_OUT ; 
  Scheme_Object * __funcarg58 = NULLED_OUT ; 
  Scheme_Object * __funcarg57 = NULLED_OUT ; 
  Scheme_Object * __funcarg56 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(c, 0), PUSH(one_minus_c_sq, 1), PUSH(sqrt_1_minus_c_sq, 2)));
# define XfOrM115_COUNT (3)
# define SETUP_XfOrM115(x) SETUP(XfOrM115_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  one_minus_c_sq = NULLED_OUT ; 
  sqrt_1_minus_c_sq = NULLED_OUT ; 
  one_minus_c_sq = (__funcarg59 = FUNCCALL(SETUP_XfOrM115(_), scheme_bin_mult (c , c ) ), FUNCCALL_AGAIN(scheme_bin_minus (((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) , __funcarg59 ) )) ; 
  sqrt_1_minus_c_sq = FUNCCALL_AGAIN(scheme_sqrt (1 , & one_minus_c_sq ) ); 
  RET_VALUE_START ((__funcarg56 = (__funcarg57 = (__funcarg58 = FUNCCALL(SETUP_XfOrM115(_), scheme_bin_mult (c , scheme_plus_i ) ), FUNCCALL_AGAIN(scheme_bin_plus (__funcarg58 , sqrt_1_minus_c_sq ) )) , FUNCCALL_AGAIN(un_log (__funcarg57 ) )) , FUNCCALL_AGAIN(scheme_bin_mult (scheme_minus_i , __funcarg56 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * complex_acos (Scheme_Object * c ) ; 
static Scheme_Object * complex_acos (Scheme_Object * c ) {
  Scheme_Object * one_minus_c_sq , * sqrt_1_minus_c_sq ; 
  Scheme_Object * __funcarg63 = NULLED_OUT ; 
  Scheme_Object * __funcarg62 = NULLED_OUT ; 
  Scheme_Object * __funcarg61 = NULLED_OUT ; 
  Scheme_Object * __funcarg60 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(c, 0), PUSH(one_minus_c_sq, 1), PUSH(sqrt_1_minus_c_sq, 2)));
# define XfOrM116_COUNT (3)
# define SETUP_XfOrM116(x) SETUP(XfOrM116_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  one_minus_c_sq = NULLED_OUT ; 
  sqrt_1_minus_c_sq = NULLED_OUT ; 
  one_minus_c_sq = (__funcarg63 = FUNCCALL(SETUP_XfOrM116(_), scheme_bin_mult (c , c ) ), FUNCCALL_AGAIN(scheme_bin_minus (((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) , __funcarg63 ) )) ; 
  sqrt_1_minus_c_sq = FUNCCALL_AGAIN(scheme_sqrt (1 , & one_minus_c_sq ) ); 
  RET_VALUE_START ((__funcarg60 = (__funcarg61 = (__funcarg62 = FUNCCALL(SETUP_XfOrM116(_), scheme_bin_mult (scheme_plus_i , sqrt_1_minus_c_sq ) ), FUNCCALL_AGAIN(scheme_bin_plus (c , __funcarg62 ) )) , FUNCCALL_AGAIN(un_log (__funcarg61 ) )) , FUNCCALL_AGAIN(scheme_bin_mult (scheme_minus_i , __funcarg60 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * complex_atan (Scheme_Object * c ) ; 
static Scheme_Object * complex_atan (Scheme_Object * c ) {
  Scheme_Object * __funcarg70 = NULLED_OUT ; 
  Scheme_Object * __funcarg69 = NULLED_OUT ; 
  Scheme_Object * __funcarg68 = NULLED_OUT ; 
  Scheme_Object * __funcarg67 = NULLED_OUT ; 
  Scheme_Object * __funcarg66 = NULLED_OUT ; 
  Scheme_Object * __funcarg65 = NULLED_OUT ; 
  Scheme_Object * __funcarg64 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(__funcarg65, 0), PUSH(c, 1), PUSH(__funcarg68, 2)));
# define XfOrM117_COUNT (3)
# define SETUP_XfOrM117(x) SETUP(XfOrM117_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (FUNCCALL(SETUP_XfOrM117(_), scheme_complex_eq (c , scheme_plus_i ) )|| FUNCCALL(SETUP_XfOrM117(_), scheme_complex_eq (c , scheme_minus_i ) ))
    RET_VALUE_START (scheme_minus_inf_object ) RET_VALUE_END ; 
  RET_VALUE_START ((__funcarg64 = (__funcarg65 = FUNCCALL(SETUP_XfOrM117(_), scheme_make_double (0.5 ) ), __funcarg66 = (__funcarg67 = (__funcarg68 = FUNCCALL(SETUP_XfOrM117(_), scheme_bin_plus (scheme_plus_i , c ) ), __funcarg69 = (__funcarg70 = FUNCCALL(SETUP_XfOrM117(_), scheme_bin_minus (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) , c ) ), FUNCCALL_AGAIN(scheme_bin_plus (scheme_plus_i , __funcarg70 ) )) , FUNCCALL_AGAIN(scheme_bin_div (__funcarg68 , __funcarg69 ) )) , FUNCCALL_AGAIN(un_log (__funcarg67 ) )) , FUNCCALL_AGAIN(scheme_bin_mult (__funcarg65 , __funcarg66 ) )) , FUNCCALL_EMPTY(scheme_bin_mult (scheme_plus_i , __funcarg64 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * exp_prim (int argc , Scheme_Object * argv [] ) {
  Scheme_Type t ; 
  double d ; 
  Scheme_Object * o = argv [0 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(o, 0)));
# define XfOrM118_COUNT (1)
# define SETUP_XfOrM118(x) SETUP(XfOrM118_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (o == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) )
    RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
  if ((((long ) (o ) ) & 0x1 ) )
    d = (((long ) (o ) ) >> 1 ) ; 
  else {
#   define XfOrM123_COUNT (0+XfOrM118_COUNT)
#   define SETUP_XfOrM123(x) SETUP_XfOrM118(x)
    t = ((o ) -> type ) ; 
    if (t == scheme_double_type ) {
      d = (((Scheme_Double * ) (o ) ) -> double_val ) ; 
    }
    else if (t == scheme_bignum_type ) {
      d = scheme_bignum_to_double (o ) ; 
    }
    else if (t == scheme_rational_type ) {
      d = scheme_rational_to_double (o ) ; 
    }
    else if ((t == scheme_complex_type ) || (t == scheme_complex_izi_type ) )
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(complex_exp (o ) )) RET_VALUE_EMPTY_END ; 
    else {
#     define XfOrM124_COUNT (0+XfOrM123_COUNT)
#     define SETUP_XfOrM124(x) SETUP_XfOrM123(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("exp" , "number" , 0 , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  if (isnan (d ) ) {
    RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
  }
  if ((isinf (d ) && (d > 0 ) ) ) {
    RET_VALUE_START (scheme_inf_object ) RET_VALUE_END ; 
  }
  if ((isinf (d ) && (d < 0 ) ) ) {
    RET_VALUE_START (scheme_zerod ) RET_VALUE_END ; 
  }
  if (0 ) {
    Small_Complex sc ; 
    Scheme_Object * o ; 
    BLOCK_SETUP((PUSH(sc.r, 0+XfOrM118_COUNT), PUSH(sc.i, 1+XfOrM118_COUNT), PUSH(o, 2+XfOrM118_COUNT)));
#   define XfOrM119_COUNT (3+XfOrM118_COUNT)
#   define SETUP_XfOrM119(x) SETUP(XfOrM119_COUNT)
    sc.r = NULLED_OUT ; 
    sc.i = NULLED_OUT ; 
    o = NULLED_OUT ; 
    o = FUNCCALL(SETUP_XfOrM119(_), scheme_make_double (d ) ); 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM119(_), complex_exp (scheme_make_small_complex (o , & sc ) ) )) RET_VALUE_END ; 
  }
  d = exp (d ) ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_double (d ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * log_prim (int argc , Scheme_Object * argv [] ) {
  Scheme_Type t ; 
  double d ; 
  Scheme_Object * o = argv [0 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(o, 0)));
# define XfOrM128_COUNT (1)
# define SETUP_XfOrM128(x) SETUP(XfOrM128_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (o == ((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) )
    RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
  else if (o == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) )
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT_DIVIDE_BY_ZERO , "log: undefined for 0" ) ); 
  if ((((long ) (o ) ) & 0x1 ) )
    d = (((long ) (o ) ) >> 1 ) ; 
  else {
#   define XfOrM133_COUNT (0+XfOrM128_COUNT)
#   define SETUP_XfOrM133(x) SETUP_XfOrM128(x)
    t = ((o ) -> type ) ; 
    if (t == scheme_double_type ) {
      d = (((Scheme_Double * ) (o ) ) -> double_val ) ; 
    }
    else if (t == scheme_bignum_type ) {
#     define XfOrM136_COUNT (0+XfOrM133_COUNT)
#     define SETUP_XfOrM136(x) SETUP_XfOrM133(x)
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(bignum_log (o ) )) RET_VALUE_EMPTY_END ; 
    }
    else if (t == scheme_rational_type ) {
      d = scheme_rational_to_double (o ) ; 
    }
    else if ((t == scheme_complex_type ) || (t == scheme_complex_izi_type ) )
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(complex_log (o ) )) RET_VALUE_EMPTY_END ; 
    else {
#     define XfOrM134_COUNT (0+XfOrM133_COUNT)
#     define SETUP_XfOrM134(x) SETUP_XfOrM133(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("log" , "number" , 0 , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  if (isnan (d ) ) {
    RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
  }
  if ((isinf (d ) && (d > 0 ) ) ) {
    RET_VALUE_START (scheme_inf_object ) RET_VALUE_END ; 
  }
  if ((isinf (d ) && (d < 0 ) ) ) {
    RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
  }
  if (d < 0.0 ) {
    Small_Complex sc ; 
    Scheme_Object * o ; 
    BLOCK_SETUP((PUSH(sc.r, 0+XfOrM128_COUNT), PUSH(sc.i, 1+XfOrM128_COUNT), PUSH(o, 2+XfOrM128_COUNT)));
#   define XfOrM129_COUNT (3+XfOrM128_COUNT)
#   define SETUP_XfOrM129(x) SETUP(XfOrM129_COUNT)
    sc.r = NULLED_OUT ; 
    sc.i = NULLED_OUT ; 
    o = NULLED_OUT ; 
    o = FUNCCALL(SETUP_XfOrM129(_), scheme_make_double (d ) ); 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM129(_), complex_log (scheme_make_small_complex (o , & sc ) ) )) RET_VALUE_END ; 
  }
  d = log (d ) ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_double (d ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * sin_prim (int argc , Scheme_Object * argv [] ) {
  Scheme_Type t ; 
  double d ; 
  Scheme_Object * o = argv [0 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(o, 0)));
# define XfOrM138_COUNT (1)
# define SETUP_XfOrM138(x) SETUP(XfOrM138_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (o == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) )
    RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
  if ((((long ) (o ) ) & 0x1 ) )
    d = (((long ) (o ) ) >> 1 ) ; 
  else {
#   define XfOrM143_COUNT (0+XfOrM138_COUNT)
#   define SETUP_XfOrM143(x) SETUP_XfOrM138(x)
    t = ((o ) -> type ) ; 
    if (t == scheme_double_type ) {
      d = (((Scheme_Double * ) (o ) ) -> double_val ) ; 
    }
    else if (t == scheme_bignum_type ) {
      d = scheme_bignum_to_double (o ) ; 
    }
    else if (t == scheme_rational_type ) {
      d = scheme_rational_to_double (o ) ; 
    }
    else if ((t == scheme_complex_type ) || (t == scheme_complex_izi_type ) )
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(complex_sin (o ) )) RET_VALUE_EMPTY_END ; 
    else {
#     define XfOrM144_COUNT (0+XfOrM143_COUNT)
#     define SETUP_XfOrM144(x) SETUP_XfOrM143(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("sin" , "number" , 0 , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  if (isnan (d ) ) {
    RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
  }
  if ((isinf (d ) && (d > 0 ) ) ) {
    RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
  }
  if ((isinf (d ) && (d < 0 ) ) ) {
    RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
  }
  if (0 ) {
    Small_Complex sc ; 
    Scheme_Object * o ; 
    BLOCK_SETUP((PUSH(sc.r, 0+XfOrM138_COUNT), PUSH(sc.i, 1+XfOrM138_COUNT), PUSH(o, 2+XfOrM138_COUNT)));
#   define XfOrM139_COUNT (3+XfOrM138_COUNT)
#   define SETUP_XfOrM139(x) SETUP(XfOrM139_COUNT)
    sc.r = NULLED_OUT ; 
    sc.i = NULLED_OUT ; 
    o = NULLED_OUT ; 
    o = FUNCCALL(SETUP_XfOrM139(_), scheme_make_double (d ) ); 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM139(_), complex_sin (scheme_make_small_complex (o , & sc ) ) )) RET_VALUE_END ; 
  }
  d = sin (d ) ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_double (d ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * cos_prim (int argc , Scheme_Object * argv [] ) {
  Scheme_Type t ; 
  double d ; 
  Scheme_Object * o = argv [0 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(o, 0)));
# define XfOrM148_COUNT (1)
# define SETUP_XfOrM148(x) SETUP(XfOrM148_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (o == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) )
    RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
  if ((((long ) (o ) ) & 0x1 ) )
    d = (((long ) (o ) ) >> 1 ) ; 
  else {
#   define XfOrM153_COUNT (0+XfOrM148_COUNT)
#   define SETUP_XfOrM153(x) SETUP_XfOrM148(x)
    t = ((o ) -> type ) ; 
    if (t == scheme_double_type ) {
      d = (((Scheme_Double * ) (o ) ) -> double_val ) ; 
    }
    else if (t == scheme_bignum_type ) {
      d = scheme_bignum_to_double (o ) ; 
    }
    else if (t == scheme_rational_type ) {
      d = scheme_rational_to_double (o ) ; 
    }
    else if ((t == scheme_complex_type ) || (t == scheme_complex_izi_type ) )
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(complex_cos (o ) )) RET_VALUE_EMPTY_END ; 
    else {
#     define XfOrM154_COUNT (0+XfOrM153_COUNT)
#     define SETUP_XfOrM154(x) SETUP_XfOrM153(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("cos" , "number" , 0 , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  if (isnan (d ) ) {
    RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
  }
  if ((isinf (d ) && (d > 0 ) ) ) {
    RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
  }
  if ((isinf (d ) && (d < 0 ) ) ) {
    RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
  }
  if (0 ) {
    Small_Complex sc ; 
    Scheme_Object * o ; 
    BLOCK_SETUP((PUSH(sc.r, 0+XfOrM148_COUNT), PUSH(sc.i, 1+XfOrM148_COUNT), PUSH(o, 2+XfOrM148_COUNT)));
#   define XfOrM149_COUNT (3+XfOrM148_COUNT)
#   define SETUP_XfOrM149(x) SETUP(XfOrM149_COUNT)
    sc.r = NULLED_OUT ; 
    sc.i = NULLED_OUT ; 
    o = NULLED_OUT ; 
    o = FUNCCALL(SETUP_XfOrM149(_), scheme_make_double (d ) ); 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM149(_), complex_cos (scheme_make_small_complex (o , & sc ) ) )) RET_VALUE_END ; 
  }
  d = cos (d ) ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_double (d ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * tan_prim (int argc , Scheme_Object * argv [] ) {
  Scheme_Type t ; 
  double d ; 
  Scheme_Object * o = argv [0 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(o, 0)));
# define XfOrM158_COUNT (1)
# define SETUP_XfOrM158(x) SETUP(XfOrM158_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (o == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) )
    RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
  if ((((long ) (o ) ) & 0x1 ) )
    d = (((long ) (o ) ) >> 1 ) ; 
  else {
#   define XfOrM163_COUNT (0+XfOrM158_COUNT)
#   define SETUP_XfOrM163(x) SETUP_XfOrM158(x)
    t = ((o ) -> type ) ; 
    if (t == scheme_double_type ) {
      d = (((Scheme_Double * ) (o ) ) -> double_val ) ; 
    }
    else if (t == scheme_bignum_type ) {
      d = scheme_bignum_to_double (o ) ; 
    }
    else if (t == scheme_rational_type ) {
      d = scheme_rational_to_double (o ) ; 
    }
    else if ((t == scheme_complex_type ) || (t == scheme_complex_izi_type ) )
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(complex_tan (o ) )) RET_VALUE_EMPTY_END ; 
    else {
#     define XfOrM164_COUNT (0+XfOrM163_COUNT)
#     define SETUP_XfOrM164(x) SETUP_XfOrM163(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("tan" , "number" , 0 , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  if (isnan (d ) ) {
    RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
  }
  if ((isinf (d ) && (d > 0 ) ) ) {
    RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
  }
  if ((isinf (d ) && (d < 0 ) ) ) {
    RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
  }
  if (0 ) {
    Small_Complex sc ; 
    Scheme_Object * o ; 
    BLOCK_SETUP((PUSH(sc.r, 0+XfOrM158_COUNT), PUSH(sc.i, 1+XfOrM158_COUNT), PUSH(o, 2+XfOrM158_COUNT)));
#   define XfOrM159_COUNT (3+XfOrM158_COUNT)
#   define SETUP_XfOrM159(x) SETUP(XfOrM159_COUNT)
    sc.r = NULLED_OUT ; 
    sc.i = NULLED_OUT ; 
    o = NULLED_OUT ; 
    o = FUNCCALL(SETUP_XfOrM159(_), scheme_make_double (d ) ); 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM159(_), complex_tan (scheme_make_small_complex (o , & sc ) ) )) RET_VALUE_END ; 
  }
  d = FUNCCALL_EMPTY(tan (d ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_double (d ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * asin_prim (int argc , Scheme_Object * argv [] ) {
  Scheme_Type t ; 
  double d ; 
  Scheme_Object * o = argv [0 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(o, 0)));
# define XfOrM168_COUNT (1)
# define SETUP_XfOrM168(x) SETUP(XfOrM168_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (o == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) )
    RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
  if ((((long ) (o ) ) & 0x1 ) )
    d = (((long ) (o ) ) >> 1 ) ; 
  else {
#   define XfOrM173_COUNT (0+XfOrM168_COUNT)
#   define SETUP_XfOrM173(x) SETUP_XfOrM168(x)
    t = ((o ) -> type ) ; 
    if (t == scheme_double_type ) {
      d = (((Scheme_Double * ) (o ) ) -> double_val ) ; 
    }
    else if (t == scheme_bignum_type ) {
      d = scheme_bignum_to_double (o ) ; 
    }
    else if (t == scheme_rational_type ) {
      d = scheme_rational_to_double (o ) ; 
    }
    else if ((t == scheme_complex_type ) || (t == scheme_complex_izi_type ) )
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(complex_asin (o ) )) RET_VALUE_EMPTY_END ; 
    else {
#     define XfOrM174_COUNT (0+XfOrM173_COUNT)
#     define SETUP_XfOrM174(x) SETUP_XfOrM173(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("asin" , "number" , 0 , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  if (isnan (d ) ) {
    RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
  }
  if ((isinf (d ) && (d > 0 ) ) ) {
    RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
  }
  if ((isinf (d ) && (d < 0 ) ) ) {
    RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
  }
  if ((d > 1.0 ) || (d < - 1.0 ) ) {
    Small_Complex sc ; 
    Scheme_Object * o ; 
    BLOCK_SETUP((PUSH(sc.r, 0+XfOrM168_COUNT), PUSH(sc.i, 1+XfOrM168_COUNT), PUSH(o, 2+XfOrM168_COUNT)));
#   define XfOrM169_COUNT (3+XfOrM168_COUNT)
#   define SETUP_XfOrM169(x) SETUP(XfOrM169_COUNT)
    sc.r = NULLED_OUT ; 
    sc.i = NULLED_OUT ; 
    o = NULLED_OUT ; 
    o = FUNCCALL(SETUP_XfOrM169(_), scheme_make_double (d ) ); 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM169(_), complex_asin (scheme_make_small_complex (o , & sc ) ) )) RET_VALUE_END ; 
  }
  d = FUNCCALL_EMPTY(asin (d ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_double (d ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * acos_prim (int argc , Scheme_Object * argv [] ) {
  Scheme_Type t ; 
  double d ; 
  Scheme_Object * o = argv [0 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(o, 0)));
# define XfOrM178_COUNT (1)
# define SETUP_XfOrM178(x) SETUP(XfOrM178_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (o == ((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) )
    RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
  if ((((long ) (o ) ) & 0x1 ) )
    d = (((long ) (o ) ) >> 1 ) ; 
  else {
#   define XfOrM183_COUNT (0+XfOrM178_COUNT)
#   define SETUP_XfOrM183(x) SETUP_XfOrM178(x)
    t = ((o ) -> type ) ; 
    if (t == scheme_double_type ) {
      d = (((Scheme_Double * ) (o ) ) -> double_val ) ; 
    }
    else if (t == scheme_bignum_type ) {
      d = scheme_bignum_to_double (o ) ; 
    }
    else if (t == scheme_rational_type ) {
      d = scheme_rational_to_double (o ) ; 
    }
    else if ((t == scheme_complex_type ) || (t == scheme_complex_izi_type ) )
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(complex_acos (o ) )) RET_VALUE_EMPTY_END ; 
    else {
#     define XfOrM184_COUNT (0+XfOrM183_COUNT)
#     define SETUP_XfOrM184(x) SETUP_XfOrM183(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("acos" , "number" , 0 , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  if (isnan (d ) ) {
    RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
  }
  if ((isinf (d ) && (d > 0 ) ) ) {
    RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
  }
  if ((isinf (d ) && (d < 0 ) ) ) {
    RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
  }
  if ((d > 1.0 ) || (d < - 1.0 ) ) {
    Small_Complex sc ; 
    Scheme_Object * o ; 
    BLOCK_SETUP((PUSH(sc.r, 0+XfOrM178_COUNT), PUSH(sc.i, 1+XfOrM178_COUNT), PUSH(o, 2+XfOrM178_COUNT)));
#   define XfOrM179_COUNT (3+XfOrM178_COUNT)
#   define SETUP_XfOrM179(x) SETUP(XfOrM179_COUNT)
    sc.r = NULLED_OUT ; 
    sc.i = NULLED_OUT ; 
    o = NULLED_OUT ; 
    o = FUNCCALL(SETUP_XfOrM179(_), scheme_make_double (d ) ); 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM179(_), complex_acos (scheme_make_small_complex (o , & sc ) ) )) RET_VALUE_END ; 
  }
  d = FUNCCALL_EMPTY(acos (d ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_double (d ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * atan_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  double v ; 
  Scheme_Object * n1 ; 
  n1 = argv [0 ] ; 
  if ((((((long ) (n1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n1 ) ) -> type ) == scheme_complex_izi_type ) )
    n1 = (((Scheme_Complex * ) (n1 ) ) -> r ) ; 
  if ((((long ) (n1 ) ) & 0x1 ) )
    v = (((long ) (n1 ) ) >> 1 ) ; 
  else if (((Scheme_Type ) (((((long ) (n1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n1 ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ) {
    v = (((Scheme_Double * ) (n1 ) ) -> double_val ) ; 
  }
  else if (((Scheme_Type ) (((((long ) (n1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n1 ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
    v = scheme_bignum_to_double (n1 ) ; 
  else if (((Scheme_Type ) (((((long ) (n1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n1 ) ) -> type ) ) == (Scheme_Type ) (scheme_rational_type ) ) )
    v = scheme_rational_to_double (n1 ) ; 
  else if ((! (((long ) (n1 ) ) & 0x1 ) && ((((n1 ) -> type ) >= scheme_complex_izi_type ) && (((n1 ) -> type ) <= scheme_complex_type ) ) ) ) {
    if (argc > 1 ) {
      scheme_wrong_type ("atan (with two arguments)" , "real number" , 0 , argc , argv ) ; 
      return ((void * ) 0 ) ; 
    }
    else return complex_atan (n1 ) ; 
  }
  else {
    scheme_wrong_type ("atan" , "number" , 0 , argc , argv ) ; 
    return ((void * ) 0 ) ; 
  }
  if (argc == 2 ) {
    double v2 ; 
    Scheme_Object * n2 ; 
    n2 = argv [1 ] ; 
    if ((n1 == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) && (n2 == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) ) {
      scheme_raise_exn (MZEXN_FAIL_CONTRACT_DIVIDE_BY_ZERO , "atan: undefined for 0 and 0" ) ; 
      return ((void * ) 0 ) ; 
    }
    if ((((((long ) (n2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n2 ) ) -> type ) == scheme_complex_izi_type ) )
      n2 = (((Scheme_Complex * ) (n2 ) ) -> r ) ; 
    if ((((long ) (n2 ) ) & 0x1 ) )
      v2 = (((long ) (n2 ) ) >> 1 ) ; 
    else if (((Scheme_Type ) (((((long ) (n2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n2 ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ) {
      v2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
    }
    else if (((Scheme_Type ) (((((long ) (n2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n2 ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
      v2 = scheme_bignum_to_double (n2 ) ; 
    else if (((Scheme_Type ) (((((long ) (n2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n2 ) ) -> type ) ) == (Scheme_Type ) (scheme_rational_type ) ) )
      v2 = scheme_rational_to_double (n2 ) ; 
    else {
      scheme_wrong_type ("atan" , "real number" , 1 , argc , argv ) ; 
      return ((void * ) 0 ) ; 
    }
    if ((v == 0.0 ) && (v2 == 0.0 ) ) {
      return scheme_zerod ; 
    }
    v = atan2 (v , v2 ) ; 
  }
  else {
    if (argv [0 ] == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) )
      return ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
    v = atan (v ) ; 
  }
  return scheme_make_double (v ) ; 
}
Scheme_Object * scheme_sqrt (int argc , Scheme_Object * argv [] ) {
  int imaginary = 0 ; 
  Scheme_Object * n ; 
  Scheme_Object * __funcarg71 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(n, 0), PUSH(argv, 1)));
# define XfOrM199_COUNT (2)
# define SETUP_XfOrM199(x) SETUP(XfOrM199_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  n = NULLED_OUT ; 
  n = argv [0 ] ; 
  if ((((((long ) (n ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n ) ) -> type ) == scheme_complex_izi_type ) ) {
    Scheme_Object * r = (((Scheme_Complex * ) (n ) ) -> r ) , * v ; 
    BLOCK_SETUP((PUSH(v, 0+XfOrM199_COUNT), PUSH(r, 1+XfOrM199_COUNT)));
#   define XfOrM202_COUNT (2+XfOrM199_COUNT)
#   define SETUP_XfOrM202(x) SETUP(XfOrM202_COUNT)
    v = NULLED_OUT ; 
    v = FUNCCALL(SETUP_XfOrM202(_), scheme_sqrt (1 , & r ) ); 
    if (! (! (((long ) (v ) ) & 0x1 ) && ((((v ) -> type ) >= scheme_complex_izi_type ) && (((v ) -> type ) <= scheme_complex_type ) ) ) )
      RET_VALUE_START ((__funcarg71 = FUNCCALL(SETUP_XfOrM202(_), scheme_complex_imaginary_part (n ) ), FUNCCALL_AGAIN(scheme_make_complex (v , __funcarg71 ) )) ) RET_VALUE_END ; 
    else RET_VALUE_START (v ) RET_VALUE_END ; 
  }
  if ((! (((long ) (n ) ) & 0x1 ) && ((((n ) -> type ) >= scheme_complex_izi_type ) && (((n ) -> type ) <= scheme_complex_type ) ) ) )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_complex_sqrt (n ) )) RET_VALUE_EMPTY_END ; 
  if (! ((((long ) (n ) ) & 0x1 ) || ((((n ) -> type ) >= scheme_bignum_type ) && (((n ) -> type ) <= scheme_complex_izi_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("sqrt" , "number" , 0 , argc , argv ) ); 
  if ((scheme_is_negative (n ) ) ) {
#   define XfOrM201_COUNT (0+XfOrM199_COUNT)
#   define SETUP_XfOrM201(x) SETUP_XfOrM199(x)
    n = FUNCCALL(SETUP_XfOrM201(_), scheme_bin_minus (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) , n ) ); 
    imaginary = 1 ; 
  }
  if ((((long ) (n ) ) & 0x1 ) || ((Scheme_Type ) (((((long ) (n ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
    n = FUNCCALL(SETUP_XfOrM199(_), scheme_integer_sqrt (n ) ); 
  else if (((Scheme_Type ) (((((long ) (n ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ) {
    double d = (((Scheme_Double * ) (n ) ) -> double_val ) ; 
#   define XfOrM200_COUNT (0+XfOrM199_COUNT)
#   define SETUP_XfOrM200(x) SETUP_XfOrM199(x)
    n = FUNCCALL(SETUP_XfOrM200(_), scheme_make_double (sqrt (d ) ) ); 
  }
  else if (((Scheme_Type ) (((((long ) (n ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n ) ) -> type ) ) == (Scheme_Type ) (scheme_rational_type ) ) )
    n = FUNCCALL(SETUP_XfOrM199(_), scheme_rational_sqrt (n ) ); 
  if (imaginary )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_complex (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) , n ) )) RET_VALUE_EMPTY_END ; 
  else RET_VALUE_START (n ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * do_int_sqrt (const char * name , int argc , Scheme_Object * argv [] , int w_rem ) {
  Scheme_Object * v = argv [0 ] , * rem = ((void * ) 0 ) ; 
  Scheme_Object * __funcarg74 = NULLED_OUT ; 
  Scheme_Object * __funcarg73 = NULLED_OUT ; 
  Scheme_Object * __funcarg72 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(rem, 0), PUSH(v, 1), PUSH(name, 2)));
# define XfOrM203_COUNT (3)
# define SETUP_XfOrM203(x) SETUP(XfOrM203_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! (scheme_is_integer (v ) ) ) {
#   define XfOrM213_COUNT (0+XfOrM203_COUNT)
#   define SETUP_XfOrM213(x) SETUP_XfOrM203(x)
    FUNCCALL(SETUP_XfOrM213(_), scheme_wrong_type (name , "integer" , 0 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if ((((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) == scheme_complex_izi_type ) ) {
    Scheme_Object * r = (((Scheme_Complex * ) (v ) ) -> r ) , * orig = v ; 
    BLOCK_SETUP((PUSH(r, 0+XfOrM203_COUNT), PUSH(orig, 1+XfOrM203_COUNT)));
#   define XfOrM211_COUNT (2+XfOrM203_COUNT)
#   define SETUP_XfOrM211(x) SETUP(XfOrM211_COUNT)
    v = FUNCCALL(SETUP_XfOrM211(_), do_int_sqrt (name , 1 , & r , w_rem ) ); 
    if (w_rem ) {
      Scheme_Thread * p = scheme_current_thread ; 
      v = p -> ku . multiple . array [0 ] ; 
      rem = p -> ku . multiple . array [1 ] ; 
    }
    if (! (! (((long ) (v ) ) & 0x1 ) && ((((v ) -> type ) >= scheme_complex_izi_type ) && (((v ) -> type ) <= scheme_complex_type ) ) ) )
      v = (__funcarg74 = FUNCCALL(SETUP_XfOrM211(_), scheme_complex_imaginary_part (orig ) ), FUNCCALL_AGAIN(scheme_make_complex (v , __funcarg74 ) )) ; 
    if (w_rem && ! (! (((long ) (rem ) ) & 0x1 ) && ((((rem ) -> type ) >= scheme_complex_izi_type ) && (((rem ) -> type ) <= scheme_complex_type ) ) ) )
      rem = (__funcarg73 = FUNCCALL(SETUP_XfOrM211(_), scheme_complex_imaginary_part (orig ) ), FUNCCALL_AGAIN(scheme_make_complex (rem , __funcarg73 ) )) ; 
  }
  else if ((((long ) (v ) ) & 0x1 ) || ((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) {
    int imaginary = 0 ; 
#   define XfOrM208_COUNT (0+XfOrM203_COUNT)
#   define SETUP_XfOrM208(x) SETUP_XfOrM203(x)
    if ((scheme_is_negative (v ) ) ) {
#     define XfOrM210_COUNT (0+XfOrM208_COUNT)
#     define SETUP_XfOrM210(x) SETUP_XfOrM208(x)
      v = FUNCCALL(SETUP_XfOrM210(_), scheme_bin_minus (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) , v ) ); 
      imaginary = 1 ; 
    }
    v = FUNCCALL(SETUP_XfOrM208(_), scheme_integer_sqrt_rem (v , & rem ) ); 
    if (imaginary ) {
#     define XfOrM209_COUNT (0+XfOrM208_COUNT)
#     define SETUP_XfOrM209(x) SETUP_XfOrM208(x)
      v = FUNCCALL(SETUP_XfOrM209(_), scheme_make_complex (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) , v ) ); 
      rem = FUNCCALL(SETUP_XfOrM209(_), scheme_bin_minus (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) , rem ) ); 
    }
  }
  else {
#   define XfOrM205_COUNT (0+XfOrM203_COUNT)
#   define SETUP_XfOrM205(x) SETUP_XfOrM203(x)
    rem = v ; 
    v = FUNCCALL(SETUP_XfOrM205(_), scheme_sqrt (1 , & v ) ); 
    if ((! (((long ) (v ) ) & 0x1 ) && ((((v ) -> type ) >= scheme_complex_izi_type ) && (((v ) -> type ) <= scheme_complex_type ) ) ) ) {
#     define XfOrM207_COUNT (0+XfOrM205_COUNT)
#     define SETUP_XfOrM207(x) SETUP_XfOrM205(x)
      v = FUNCCALL(SETUP_XfOrM207(_), scheme_complex_imaginary_part (v ) ); 
      v = FUNCCALL(SETUP_XfOrM207(_), floor_prim (1 , & v ) ); 
      v = FUNCCALL_AGAIN(scheme_make_complex (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) , v ) ); 
    }
    else v = FUNCCALL(SETUP_XfOrM205(_), floor_prim (1 , & v ) ); 
    if (w_rem ) {
#     define XfOrM206_COUNT (0+XfOrM205_COUNT)
#     define SETUP_XfOrM206(x) SETUP_XfOrM205(x)
      rem = (__funcarg72 = FUNCCALL(SETUP_XfOrM206(_), scheme_bin_mult (v , v ) ), FUNCCALL_AGAIN(scheme_bin_minus (rem , __funcarg72 ) )) ; 
    }
  }
  if (w_rem ) {
    Scheme_Object * a [2 ] ; 
    BLOCK_SETUP((PUSHARRAY(a, 2, 0+XfOrM203_COUNT)));
#   define XfOrM204_COUNT (3+XfOrM203_COUNT)
#   define SETUP_XfOrM204(x) SETUP(XfOrM204_COUNT)
    a[0] = NULLED_OUT ; 
    a[1] = NULLED_OUT ; 
    a [0 ] = v ; 
    a [1 ] = rem ; 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM204(_), scheme_values (2 , a ) )) RET_VALUE_END ; 
  }
  else RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * int_sqrt (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_int_sqrt ("integer-sqrt" , argc , argv , 0 ) ; 
}
Scheme_Object * int_sqrt_rem (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_int_sqrt ("integer-sqrt/remainder" , argc , argv , 1 ) ; 
}
static Scheme_Object * fixnum_expt (long x , long y ) {
  int orig_x = x ; 
  int orig_y = y ; 
  Scheme_Object * __funcarg82 = NULLED_OUT ; 
  Scheme_Object * __funcarg81 = NULLED_OUT ; 
  Scheme_Object * __funcarg80 = NULLED_OUT ; 
  Scheme_Object * __funcarg79 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(__funcarg81, 0), PUSH(__funcarg79, 1)));
# define XfOrM216_COUNT (2)
# define SETUP_XfOrM216(x) SETUP(XfOrM216_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if ((x == 2 ) && (y <= 61 ) )
    RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) ((long ) 1 << y ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
  else {
    long result = 1 ; 
    int odd_result = (x < 0 ) && (y & 0x1 ) ; 
#   define XfOrM217_COUNT (0+XfOrM216_COUNT)
#   define SETUP_XfOrM217(x) SETUP_XfOrM216(x)
    if (x < 0 )
      x = - x ; 
    while (y > 0 ) {
#     define XfOrM220_COUNT (0+XfOrM217_COUNT)
#     define SETUP_XfOrM220(x) SETUP_XfOrM217(x)
      if (x > 46339 && y > 1 )
        RET_VALUE_START ((__funcarg81 = FUNCCALL(SETUP_XfOrM220(_), scheme_make_integer_value (orig_x ) ), __funcarg82 = FUNCCALL(SETUP_XfOrM220(_), scheme_make_integer_value (orig_y ) ), FUNCCALL_EMPTY(scheme_generic_integer_power (__funcarg81 , __funcarg82 ) )) ) RET_VALUE_END ; 
      if (y & 0x1 ) {
        long next_result = x * result ; 
#       define XfOrM221_COUNT (0+XfOrM220_COUNT)
#       define SETUP_XfOrM221(x) SETUP_XfOrM220(x)
        if (y == 1 && x > 46339 && ! (next_result / x == result ) )
          RET_VALUE_START ((__funcarg79 = FUNCCALL(SETUP_XfOrM221(_), scheme_make_integer_value (orig_x ) ), __funcarg80 = FUNCCALL(SETUP_XfOrM221(_), scheme_make_integer_value (orig_y ) ), FUNCCALL_EMPTY(scheme_generic_integer_power (__funcarg79 , __funcarg80 ) )) ) RET_VALUE_END ; 
        else result = next_result ; 
      }
      y = y >> 1 ; 
      x = x * x ; 
    }
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_integer_value (odd_result ? - result : result ) )) RET_VALUE_EMPTY_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static double sch_pow (double x , double y ) {
  /* No conversion */
  if ((isinf (y ) && (y > 0 ) ) ) {
    if ((x == 1.0 ) || (x == - 1.0 ) )
      return not_a_number_val ; 
    else if ((x < 1.0 ) && (x > - 1.0 ) )
      return 0.0 ; 
    else return scheme_infinity_val ; 
  }
  else if ((isinf (y ) && (y < 0 ) ) ) {
    if ((x == 1.0 ) || (x == - 1.0 ) )
      return not_a_number_val ; 
    else if ((x < 1.0 ) && (x > - 1.0 ) )
      return scheme_infinity_val ; 
    else return 0.0 ; 
  }
  else if ((isinf (x ) && (x > 0 ) ) ) {
    if (y == 0.0 )
      return 1.0 ; 
    else if (y < 0 )
      return 0.0 ; 
    else return scheme_infinity_val ; 
  }
  else if ((isinf (x ) && (x < 0 ) ) ) {
    if (y == 0.0 )
      return 1.0 ; 
    else {
      int neg = 0 ; 
      if (y < 0 ) {
        neg = 1 ; 
        y = - y ; 
      }
      if (fmod (y , 2.0 ) == 1.0 ) {
        if (neg )
          return scheme_floating_point_nzero ; 
        else return scheme_minus_infinity_val ; 
      }
      else {
        if (neg )
          return 0.0 ; 
        else return scheme_infinity_val ; 
      }
    }
  }
  else return pow (x , y ) ; 
}
static Scheme_Object * bin_expt (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
static Scheme_Object * bin_expt (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
static Scheme_Object * bin_expt__wrong_type (const Scheme_Object * v ) {
  Scheme_Object * a [1 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 1, 0)));
# define XfOrM231_COUNT (3)
# define SETUP_XfOrM231(x) SETUP(XfOrM231_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a [0 ] = (Scheme_Object * ) v ; 
  FUNCCALL(SETUP_XfOrM231(_), scheme_wrong_type ("expt" , "number" , - 1 , 0 , a ) ); 
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_expt__int_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Bignum sb ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(sb.o.digits, 0)));
# define XfOrM232_COUNT (1)
# define SETUP_XfOrM232(x) SETUP(XfOrM232_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sb.o.digits = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM232(_), scheme_generic_integer_power ((scheme_make_small_bignum ((((long ) (n1 ) ) >> 1 ) , & sb ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_expt__int_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr1 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sr1.num, 0), PUSH(sr1.denom, 1)));
# define XfOrM233_COUNT (2)
# define SETUP_XfOrM233(x) SETUP(XfOrM233_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr1.num = NULLED_OUT ; 
  sr1.denom = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM233(_), scheme_rational_power ((scheme_make_small_rational ((((long ) (n1 ) ) >> 1 ) , & sr1 ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_expt__int_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM234_COUNT (2)
# define SETUP_XfOrM234(x) SETUP(XfOrM234_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM234(_), scheme_complex_power ((scheme_make_small_complex (n1 , & sc ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_expt__dbl_big (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Scheme_Object * __funcarg87 = NULLED_OUT ; 
  Scheme_Object * __funcarg86 = NULLED_OUT ; 
  Scheme_Object * __funcarg85 = NULLED_OUT ; 
  Scheme_Object * __funcarg84 = NULLED_OUT ; 
  double __funcarg83 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(__funcarg84, 0), PUSH(n2, 1)));
# define XfOrM235_COUNT (2)
# define SETUP_XfOrM235(x) SETUP(XfOrM235_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ; 
  if (isnan (d1 ) )
    RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
  RET_VALUE_START ((((d1 < 0.0 ) && (scheme_bignum_to_double (n2 ) != floor (scheme_bignum_to_double (n2 ) ) ) ) ? (__funcarg84 = (__funcarg87 = FUNCCALL(SETUP_XfOrM235(_), scheme_make_double (d1 ) ), FUNCCALL_AGAIN(scheme_real_to_complex (__funcarg87 ) )) , __funcarg85 = (__funcarg86 = FUNCCALL(SETUP_XfOrM235(_), scheme_make_double (scheme_bignum_to_double (n2 ) ) ), FUNCCALL_AGAIN(scheme_real_to_complex (__funcarg86 ) )) , FUNCCALL_AGAIN(scheme_complex_power (__funcarg84 , __funcarg85 ) )) : (__funcarg83 = FUNCCALL_EMPTY(sch_pow ((double ) d1 , (double ) scheme_bignum_to_double (n2 ) ) ), FUNCCALL_EMPTY(scheme_make_double (__funcarg83 ) )) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_expt__dbl_rat (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Scheme_Object * __funcarg92 = NULLED_OUT ; 
  Scheme_Object * __funcarg91 = NULLED_OUT ; 
  Scheme_Object * __funcarg90 = NULLED_OUT ; 
  Scheme_Object * __funcarg89 = NULLED_OUT ; 
  double __funcarg88 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(__funcarg89, 0), PUSH(n2, 1)));
# define XfOrM236_COUNT (2)
# define SETUP_XfOrM236(x) SETUP(XfOrM236_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ; 
  if (isnan (d1 ) )
    RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
  RET_VALUE_START ((((d1 < 0.0 ) && (scheme_rational_to_double (n2 ) != floor (scheme_rational_to_double (n2 ) ) ) ) ? (__funcarg89 = (__funcarg92 = FUNCCALL(SETUP_XfOrM236(_), scheme_make_double (d1 ) ), FUNCCALL_AGAIN(scheme_real_to_complex (__funcarg92 ) )) , __funcarg90 = (__funcarg91 = FUNCCALL(SETUP_XfOrM236(_), scheme_make_double (scheme_rational_to_double (n2 ) ) ), FUNCCALL_AGAIN(scheme_real_to_complex (__funcarg91 ) )) , FUNCCALL_AGAIN(scheme_complex_power (__funcarg89 , __funcarg90 ) )) : (__funcarg88 = FUNCCALL_EMPTY(sch_pow ((double ) d1 , (double ) scheme_rational_to_double (n2 ) ) ), FUNCCALL_EMPTY(scheme_make_double (__funcarg88 ) )) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_expt__dbl_comp (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM237_COUNT (2)
# define SETUP_XfOrM237(x) SETUP(XfOrM237_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  if (isnan (d1 ) )
    RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM237(_), scheme_complex_power ((scheme_make_small_complex (n1 , & sc ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_expt__big_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Bignum sb ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(sb.o.digits, 0)));
# define XfOrM238_COUNT (1)
# define SETUP_XfOrM238(x) SETUP(XfOrM238_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sb.o.digits = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM238(_), scheme_generic_integer_power ((n1 ) , (scheme_make_small_bignum ((((long ) (n2 ) ) >> 1 ) , & sb ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_expt__big_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  double d2 ; 
  Scheme_Object * __funcarg97 = NULLED_OUT ; 
  Scheme_Object * __funcarg96 = NULLED_OUT ; 
  Scheme_Object * __funcarg95 = NULLED_OUT ; 
  Scheme_Object * __funcarg94 = NULLED_OUT ; 
  double __funcarg93 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(n1, 0), PUSH(__funcarg94, 1)));
# define XfOrM239_COUNT (2)
# define SETUP_XfOrM239(x) SETUP(XfOrM239_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ; 
  d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
  if (isnan (d2 ) )
    RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
  RET_VALUE_START ((((scheme_bignum_to_double (n1 ) < 0.0 ) && (d2 != floor (d2 ) ) ) ? (__funcarg94 = (__funcarg97 = FUNCCALL(SETUP_XfOrM239(_), scheme_make_double (scheme_bignum_to_double (n1 ) ) ), FUNCCALL_AGAIN(scheme_real_to_complex (__funcarg97 ) )) , __funcarg95 = (__funcarg96 = FUNCCALL(SETUP_XfOrM239(_), scheme_make_double (d2 ) ), FUNCCALL_AGAIN(scheme_real_to_complex (__funcarg96 ) )) , FUNCCALL_AGAIN(scheme_complex_power (__funcarg94 , __funcarg95 ) )) : (__funcarg93 = FUNCCALL_EMPTY(sch_pow ((double ) scheme_bignum_to_double (n1 ) , (double ) d2 ) ), FUNCCALL_EMPTY(scheme_make_double (__funcarg93 ) )) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_expt__big_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Scheme_Object * __funcarg98 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(n2, 0)));
# define XfOrM240_COUNT (1)
# define SETUP_XfOrM240(x) SETUP(XfOrM240_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg98 = FUNCCALL(SETUP_XfOrM240(_), scheme_integer_to_rational (n1 ) ), FUNCCALL_EMPTY(scheme_rational_power (__funcarg98 , (n2 ) ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_expt__big_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM241_COUNT (2)
# define SETUP_XfOrM241(x) SETUP(XfOrM241_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM241(_), scheme_complex_power ((scheme_make_small_complex (n1 , & sc ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_expt__rat_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr8 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sr8.num, 0), PUSH(sr8.denom, 1)));
# define XfOrM242_COUNT (2)
# define SETUP_XfOrM242(x) SETUP(XfOrM242_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr8.num = NULLED_OUT ; 
  sr8.denom = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM242(_), scheme_rational_power ((n1 ) , (scheme_make_small_rational ((((long ) (n2 ) ) >> 1 ) , & sr8 ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_expt__rat_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  double d2 ; 
  Scheme_Object * __funcarg103 = NULLED_OUT ; 
  Scheme_Object * __funcarg102 = NULLED_OUT ; 
  Scheme_Object * __funcarg101 = NULLED_OUT ; 
  Scheme_Object * __funcarg100 = NULLED_OUT ; 
  double __funcarg99 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(n1, 0), PUSH(__funcarg100, 1)));
# define XfOrM243_COUNT (2)
# define SETUP_XfOrM243(x) SETUP(XfOrM243_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ; 
  d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
  if (isnan (d2 ) )
    RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
  RET_VALUE_START ((((scheme_rational_to_double (n1 ) < 0.0 ) && (d2 != floor (d2 ) ) ) ? (__funcarg100 = (__funcarg103 = FUNCCALL(SETUP_XfOrM243(_), scheme_make_double (scheme_rational_to_double (n1 ) ) ), FUNCCALL_AGAIN(scheme_real_to_complex (__funcarg103 ) )) , __funcarg101 = (__funcarg102 = FUNCCALL(SETUP_XfOrM243(_), scheme_make_double (d2 ) ), FUNCCALL_AGAIN(scheme_real_to_complex (__funcarg102 ) )) , FUNCCALL_AGAIN(scheme_complex_power (__funcarg100 , __funcarg101 ) )) : (__funcarg99 = FUNCCALL_EMPTY(sch_pow ((double ) scheme_rational_to_double (n1 ) , (double ) d2 ) ), FUNCCALL_EMPTY(scheme_make_double (__funcarg99 ) )) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_expt__rat_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Scheme_Object * __funcarg104 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(n1, 0)));
# define XfOrM244_COUNT (1)
# define SETUP_XfOrM244(x) SETUP(XfOrM244_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg104 = FUNCCALL(SETUP_XfOrM244(_), scheme_integer_to_rational (n2 ) ), FUNCCALL_EMPTY(scheme_rational_power ((n1 ) , __funcarg104 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_expt__rat_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM245_COUNT (2)
# define SETUP_XfOrM245(x) SETUP(XfOrM245_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM245(_), scheme_complex_power ((scheme_make_small_complex (n1 , & sc ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_expt__comp_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM246_COUNT (2)
# define SETUP_XfOrM246(x) SETUP(XfOrM246_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM246(_), scheme_complex_power ((n1 ) , (scheme_make_small_complex (n2 , & sc ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_expt__comp_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM247_COUNT (2)
# define SETUP_XfOrM247(x) SETUP(XfOrM247_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  if (isnan ((((Scheme_Double * ) (n2 ) ) -> double_val ) ) )
    RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM247(_), scheme_complex_power ((n1 ) , (scheme_make_small_complex (n2 , & sc ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_expt__comp_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM248_COUNT (2)
# define SETUP_XfOrM248(x) SETUP(XfOrM248_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM248(_), scheme_complex_power ((n1 ) , (scheme_make_small_complex (n2 , & sc ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_expt__comp_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM249_COUNT (2)
# define SETUP_XfOrM249(x) SETUP(XfOrM249_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM249(_), scheme_complex_power ((n1 ) , (scheme_make_small_complex (n2 , & sc ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * bin_expt (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Scheme_Type t1 , t2 ; 
  Scheme_Object * __funcarg119 = NULLED_OUT ; 
  Scheme_Object * __funcarg118 = NULLED_OUT ; 
  Scheme_Object * __funcarg117 = NULLED_OUT ; 
  Scheme_Object * __funcarg116 = NULLED_OUT ; 
  double __funcarg115 ; 
  Scheme_Object * __funcarg114 = NULLED_OUT ; 
  Scheme_Object * __funcarg113 = NULLED_OUT ; 
  Scheme_Object * __funcarg112 = NULLED_OUT ; 
  Scheme_Object * __funcarg111 = NULLED_OUT ; 
  double __funcarg110 ; 
  Scheme_Object * __funcarg109 = NULLED_OUT ; 
  Scheme_Object * __funcarg108 = NULLED_OUT ; 
  Scheme_Object * __funcarg107 = NULLED_OUT ; 
  Scheme_Object * __funcarg106 = NULLED_OUT ; 
  double __funcarg105 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(n1, 0), PUSH(__funcarg116, 1), PUSH(__funcarg111, 2), PUSH(__funcarg106, 3), PUSH(n2, 4)));
# define XfOrM250_COUNT (5)
# define SETUP_XfOrM250(x) SETUP(XfOrM250_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (n2 == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) )
    RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
  if ((((long ) (n1 ) ) & 0x1 ) ) {
#   define XfOrM268_COUNT (0+XfOrM250_COUNT)
#   define SETUP_XfOrM268(x) SETUP_XfOrM250(x)
    if (n1 == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) )
      if (! ((Scheme_Type ) (((((long ) (n2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n2 ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) || 0 || ((((Scheme_Double * ) (n2 ) ) -> double_val ) != 0 ) )
      RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
    if ((((long ) (n2 ) ) & 0x1 ) )
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(fixnum_expt ((((long ) (n1 ) ) >> 1 ) , (((long ) (n2 ) ) >> 1 ) ) )) RET_VALUE_EMPTY_END ; 
    t2 = ((n2 ) -> type ) ; 
    if (t2 == scheme_double_type ) {
      double d = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
#     define XfOrM272_COUNT (0+XfOrM268_COUNT)
#     define SETUP_XfOrM272(x) SETUP_XfOrM268(x)
      if (isnan (d ) )
        RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
      RET_VALUE_START (((((((long ) (n1 ) ) >> 1 ) < 0.0 ) && (d != floor (d ) ) ) ? (__funcarg116 = (__funcarg119 = FUNCCALL(SETUP_XfOrM272(_), scheme_make_double ((((long ) (n1 ) ) >> 1 ) ) ), FUNCCALL_AGAIN(scheme_real_to_complex (__funcarg119 ) )) , __funcarg117 = (__funcarg118 = FUNCCALL(SETUP_XfOrM272(_), scheme_make_double (d ) ), FUNCCALL_AGAIN(scheme_real_to_complex (__funcarg118 ) )) , FUNCCALL_AGAIN(scheme_complex_power (__funcarg116 , __funcarg117 ) )) : (__funcarg115 = FUNCCALL(SETUP_XfOrM272(_), sch_pow ((double ) (((long ) (n1 ) ) >> 1 ) , (double ) d ) ), FUNCCALL_AGAIN(scheme_make_double (__funcarg115 ) )) ) ) RET_VALUE_END ; 
    }
    if (t2 == scheme_bignum_type ) {
#     define XfOrM271_COUNT (0+XfOrM268_COUNT)
#     define SETUP_XfOrM271(x) SETUP_XfOrM268(x)
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(bin_expt__int_big (n1 , n2 ) )) RET_VALUE_EMPTY_END ; 
    }
    if (t2 == scheme_rational_type ) {
#     define XfOrM270_COUNT (0+XfOrM268_COUNT)
#     define SETUP_XfOrM270(x) SETUP_XfOrM268(x)
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(bin_expt__int_rat (n1 , n2 ) )) RET_VALUE_EMPTY_END ; 
    }
    if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
#     define XfOrM269_COUNT (0+XfOrM268_COUNT)
#     define SETUP_XfOrM269(x) SETUP_XfOrM268(x)
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(bin_expt__int_comp (n1 , n2 ) )) RET_VALUE_EMPTY_END ; 
    }
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(bin_expt__wrong_type (n2 ) )) RET_VALUE_EMPTY_END ; 
  }
  else {
#   define XfOrM251_COUNT (0+XfOrM250_COUNT)
#   define SETUP_XfOrM251(x) SETUP_XfOrM250(x)
    t1 = ((n1 ) -> type ) ; 
    if (t1 == scheme_double_type ) {
      double d1 = (((Scheme_Double * ) (n1 ) ) -> double_val ) ; 
#     define XfOrM262_COUNT (0+XfOrM251_COUNT)
#     define SETUP_XfOrM262(x) SETUP_XfOrM251(x)
      if ((((long ) (n2 ) ) & 0x1 ) ) {
#       define XfOrM267_COUNT (0+XfOrM262_COUNT)
#       define SETUP_XfOrM267(x) SETUP_XfOrM262(x)
        if (isnan (d1 ) )
          RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
        RET_VALUE_START ((((d1 < 0.0 ) && ((((long ) (n2 ) ) >> 1 ) != floor ((((long ) (n2 ) ) >> 1 ) ) ) ) ? (__funcarg111 = (__funcarg114 = FUNCCALL(SETUP_XfOrM267(_), scheme_make_double (d1 ) ), FUNCCALL_AGAIN(scheme_real_to_complex (__funcarg114 ) )) , __funcarg112 = (__funcarg113 = FUNCCALL(SETUP_XfOrM267(_), scheme_make_double ((((long ) (n2 ) ) >> 1 ) ) ), FUNCCALL_AGAIN(scheme_real_to_complex (__funcarg113 ) )) , FUNCCALL_AGAIN(scheme_complex_power (__funcarg111 , __funcarg112 ) )) : (__funcarg110 = FUNCCALL(SETUP_XfOrM267(_), sch_pow ((double ) d1 , (double ) (((long ) (n2 ) ) >> 1 ) ) ), FUNCCALL_AGAIN(scheme_make_double (__funcarg110 ) )) ) ) RET_VALUE_END ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        double d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
#       define XfOrM266_COUNT (0+XfOrM262_COUNT)
#       define SETUP_XfOrM266(x) SETUP_XfOrM262(x)
        if (isnan (d1 ) )
          RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
        if (isnan (d2 ) )
          RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
        RET_VALUE_START ((((d1 < 0.0 ) && (d2 != floor (d2 ) ) ) ? (__funcarg106 = (__funcarg109 = FUNCCALL(SETUP_XfOrM266(_), scheme_make_double (d1 ) ), FUNCCALL_AGAIN(scheme_real_to_complex (__funcarg109 ) )) , __funcarg107 = (__funcarg108 = FUNCCALL(SETUP_XfOrM266(_), scheme_make_double (d2 ) ), FUNCCALL_AGAIN(scheme_real_to_complex (__funcarg108 ) )) , FUNCCALL_AGAIN(scheme_complex_power (__funcarg106 , __funcarg107 ) )) : (__funcarg105 = FUNCCALL(SETUP_XfOrM266(_), sch_pow ((double ) d1 , (double ) d2 ) ), FUNCCALL_AGAIN(scheme_make_double (__funcarg105 ) )) ) ) RET_VALUE_END ; 
      }
      if (t2 == scheme_bignum_type ) {
#       define XfOrM265_COUNT (0+XfOrM262_COUNT)
#       define SETUP_XfOrM265(x) SETUP_XfOrM262(x)
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(bin_expt__dbl_big (d1 , n1 , n2 ) )) RET_VALUE_EMPTY_END ; 
      }
      if (t2 == scheme_rational_type ) {
#       define XfOrM264_COUNT (0+XfOrM262_COUNT)
#       define SETUP_XfOrM264(x) SETUP_XfOrM262(x)
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(bin_expt__dbl_rat (d1 , n1 , n2 ) )) RET_VALUE_EMPTY_END ; 
      }
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
#       define XfOrM263_COUNT (0+XfOrM262_COUNT)
#       define SETUP_XfOrM263(x) SETUP_XfOrM262(x)
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(bin_expt__dbl_comp (d1 , n1 , n2 ) )) RET_VALUE_EMPTY_END ; 
      }
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(bin_expt__wrong_type (n2 ) )) RET_VALUE_EMPTY_END ; 
    }
    else if (t1 == scheme_bignum_type ) {
#     define XfOrM258_COUNT (0+XfOrM251_COUNT)
#     define SETUP_XfOrM258(x) SETUP_XfOrM251(x)
      if ((((long ) (n2 ) ) & 0x1 ) ) {
#       define XfOrM261_COUNT (0+XfOrM258_COUNT)
#       define SETUP_XfOrM261(x) SETUP_XfOrM258(x)
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(bin_expt__big_int (n1 , n2 ) )) RET_VALUE_EMPTY_END ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
#       define XfOrM260_COUNT (0+XfOrM258_COUNT)
#       define SETUP_XfOrM260(x) SETUP_XfOrM258(x)
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(bin_expt__big_dbl (n1 , n2 ) )) RET_VALUE_EMPTY_END ; 
      }
      if (t2 == scheme_bignum_type )
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_generic_integer_power ((n1 ) , (n2 ) ) )) RET_VALUE_EMPTY_END ; 
      if (t2 == scheme_rational_type )
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(bin_expt__big_rat (n1 , n2 ) )) RET_VALUE_EMPTY_END ; 
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
#       define XfOrM259_COUNT (0+XfOrM258_COUNT)
#       define SETUP_XfOrM259(x) SETUP_XfOrM258(x)
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(bin_expt__big_comp (n1 , n2 ) )) RET_VALUE_EMPTY_END ; 
      }
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(bin_expt__wrong_type (n2 ) )) RET_VALUE_EMPTY_END ; 
    }
    else if (t1 == scheme_rational_type ) {
#     define XfOrM254_COUNT (0+XfOrM251_COUNT)
#     define SETUP_XfOrM254(x) SETUP_XfOrM251(x)
      if ((((long ) (n2 ) ) & 0x1 ) ) {
#       define XfOrM257_COUNT (0+XfOrM254_COUNT)
#       define SETUP_XfOrM257(x) SETUP_XfOrM254(x)
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(bin_expt__rat_int (n1 , n2 ) )) RET_VALUE_EMPTY_END ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
#       define XfOrM256_COUNT (0+XfOrM254_COUNT)
#       define SETUP_XfOrM256(x) SETUP_XfOrM254(x)
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(bin_expt__rat_dbl (n1 , n2 ) )) RET_VALUE_EMPTY_END ; 
      }
      if (t2 == scheme_bignum_type )
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(bin_expt__rat_big (n1 , n2 ) )) RET_VALUE_EMPTY_END ; 
      if (t2 == scheme_rational_type )
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_rational_power ((n1 ) , (n2 ) ) )) RET_VALUE_EMPTY_END ; 
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
#       define XfOrM255_COUNT (0+XfOrM254_COUNT)
#       define SETUP_XfOrM255(x) SETUP_XfOrM254(x)
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(bin_expt__rat_comp (n1 , n2 ) )) RET_VALUE_EMPTY_END ; 
      }
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(bin_expt__wrong_type (n2 ) )) RET_VALUE_EMPTY_END ; 
    }
    else if ((t1 == scheme_complex_type ) || (t1 == scheme_complex_izi_type ) ) {
#     define XfOrM252_COUNT (0+XfOrM251_COUNT)
#     define SETUP_XfOrM252(x) SETUP_XfOrM251(x)
      if ((((long ) (n2 ) ) & 0x1 ) )
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(bin_expt__comp_int (n1 , n2 ) )) RET_VALUE_EMPTY_END ; 
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
#       define XfOrM253_COUNT (0+XfOrM252_COUNT)
#       define SETUP_XfOrM253(x) SETUP_XfOrM252(x)
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(bin_expt__comp_dbl (n1 , n2 ) )) RET_VALUE_EMPTY_END ; 
      }
      if (t2 == scheme_bignum_type )
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(bin_expt__comp_big (n1 , n2 ) )) RET_VALUE_EMPTY_END ; 
      if (t2 == scheme_rational_type )
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(bin_expt__comp_rat (n1 , n2 ) )) RET_VALUE_EMPTY_END ; 
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) )
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_complex_power ((n1 ) , (n2 ) ) )) RET_VALUE_EMPTY_END ; 
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(bin_expt__wrong_type (n2 ) )) RET_VALUE_EMPTY_END ; 
    }
    else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(bin_expt__wrong_type (n1 ) )) RET_VALUE_EMPTY_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_expt (int argc , Scheme_Object * argv [] ) {
  int invert = 0 ; 
  Scheme_Object * e , * r , * n ; 
  Scheme_Object * __funcarg121 = NULLED_OUT ; 
  char * __funcarg120 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(e, 0), PUSH(n, 1), PUSH(r, 2), PUSH(argv, 3)));
# define XfOrM273_COUNT (4)
# define SETUP_XfOrM273(x) SETUP(XfOrM273_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  e = NULLED_OUT ; 
  r = NULLED_OUT ; 
  n = NULLED_OUT ; 
  n = argv [0 ] ; 
  e = argv [1 ] ; 
  if (! ((((long ) (n ) ) & 0x1 ) || ((((n ) -> type ) >= scheme_bignum_type ) && (((n ) -> type ) <= scheme_complex_type ) ) ) )
    FUNCCALL(SETUP_XfOrM273(_), scheme_wrong_type ("expt" , "number" , 0 , argc , argv ) ); 
  if (e == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) )
    RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
  if (e == ((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) )
    RET_VALUE_START (n ) RET_VALUE_END ; 
  if (n == ((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) ) {
    if (((((long ) (e ) ) & 0x1 ) || ((((e ) -> type ) >= scheme_bignum_type ) && (((e ) -> type ) <= scheme_complex_type ) ) ) )
      RET_VALUE_START (n ) RET_VALUE_END ; 
  }
  if (((Scheme_Type ) (((((long ) (e ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e ) ) -> type ) ) == (Scheme_Type ) (scheme_rational_type ) ) && (((Scheme_Rational * ) e ) -> num == ((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) ) && (((Scheme_Rational * ) e ) -> denom == ((Scheme_Object * ) (void * ) (long ) ((((long ) (2 ) ) << 1 ) | 0x1 ) ) ) ) {
#   define XfOrM296_COUNT (0+XfOrM273_COUNT)
#   define SETUP_XfOrM296(x) SETUP_XfOrM273(x)
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM296(_), scheme_sqrt (1 , argv ) )) RET_VALUE_END ; 
  }
  if (n == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) {
    int neg ; 
#   define XfOrM290_COUNT (0+XfOrM273_COUNT)
#   define SETUP_XfOrM290(x) SETUP_XfOrM273(x)
    if (((Scheme_Type ) (((((long ) (e ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ) {
      double d = (((Scheme_Double * ) (e ) ) -> double_val ) ; 
      if (isnan (d ) ) {
        RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
      }
    }
    if (! (! (((long ) (e ) ) & 0x1 ) && ((((e ) -> type ) >= scheme_complex_izi_type ) && (((e ) -> type ) <= scheme_complex_type ) ) ) ) {
#     define XfOrM293_COUNT (0+XfOrM290_COUNT)
#     define SETUP_XfOrM293(x) SETUP_XfOrM290(x)
      neg = (scheme_is_negative (e ) ) ; 
    }
    else {
#     define XfOrM292_COUNT (0+XfOrM290_COUNT)
#     define SETUP_XfOrM292(x) SETUP_XfOrM290(x)
      neg = ! (__funcarg121 = FUNCCALL(SETUP_XfOrM292(_), scheme_complex_real_part (e ) ), (scheme_is_positive (__funcarg121 ) ) ) ; 
    }
    if (neg ) {
#     define XfOrM291_COUNT (0+XfOrM290_COUNT)
#     define SETUP_XfOrM291(x) SETUP_XfOrM290(x)
      (__funcarg120 = FUNCCALL(SETUP_XfOrM291(_), scheme_make_provided_string (e , 0 , ((void * ) 0 ) ) ), FUNCCALL_AGAIN(scheme_raise_exn (MZEXN_FAIL_CONTRACT_DIVIDE_BY_ZERO , "expt: undefined for 0 and %s" , __funcarg120 ) )) ; 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  if (! ((Scheme_Type ) (((((long ) (n ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ) {
#   define XfOrM287_COUNT (0+XfOrM273_COUNT)
#   define SETUP_XfOrM287(x) SETUP_XfOrM273(x)
    if ((((long ) (e ) ) & 0x1 ) || ((Scheme_Type ) (((((long ) (e ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) {
#     define XfOrM288_COUNT (0+XfOrM287_COUNT)
#     define SETUP_XfOrM288(x) SETUP_XfOrM287(x)
      if (! (scheme_is_positive (e ) ) ) {
#       define XfOrM289_COUNT (0+XfOrM288_COUNT)
#       define SETUP_XfOrM289(x) SETUP_XfOrM288(x)
        e = FUNCCALL(SETUP_XfOrM289(_), scheme_bin_minus (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) , e ) ); 
        invert = 1 ; 
      }
    }
  }
  else {
    double d = (((Scheme_Double * ) (n ) ) -> double_val ) ; 
#   define XfOrM274_COUNT (0+XfOrM273_COUNT)
#   define SETUP_XfOrM274(x) SETUP_XfOrM273(x)
    if ((d == 0.0 ) ) {
#     define XfOrM275_COUNT (0+XfOrM274_COUNT)
#     define SETUP_XfOrM275(x) SETUP_XfOrM274(x)
      if (((((long ) (e ) ) & 0x1 ) || ((((e ) -> type ) >= scheme_bignum_type ) && (((e ) -> type ) <= scheme_complex_izi_type ) ) ) ) {
        int norm = 0 ; 
#       define XfOrM276_COUNT (0+XfOrM275_COUNT)
#       define SETUP_XfOrM276(x) SETUP_XfOrM275(x)
        if (((Scheme_Type ) (((((long ) (e ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ) {
          double d2 ; 
          d2 = (((Scheme_Double * ) (e ) ) -> double_val ) ; 
          if ((d2 == 0.0 ) || (isinf (d2 ) && (d2 > 0 ) ) || (isinf (d2 ) && (d2 < 0 ) ) || isnan (d2 ) )
            norm = 1 ; 
        }
        if (! norm ) {
          int isnonneg , iseven , negz ; 
#         define XfOrM277_COUNT (0+XfOrM276_COUNT)
#         define SETUP_XfOrM277(x) SETUP_XfOrM276(x)
          if ((scheme_is_integer (e ) ) ) {
#           define XfOrM285_COUNT (0+XfOrM277_COUNT)
#           define SETUP_XfOrM285(x) SETUP_XfOrM277(x)
            iseven = (((FUNCCALL(SETUP_XfOrM285(_), scheme_odd_p (1 , & e ) )) ) == (scheme_false ) ) ; 
          }
          else {
            iseven = 1 ; 
          }
          isnonneg = ! (scheme_is_negative (e ) ) ; 
          negz = (scheme_minus_zero_p (d ) ) ; 
          if (isnonneg ) {
            if (iseven || ! negz ) {
              RET_VALUE_START (scheme_zerod ) RET_VALUE_END ; 
            }
            else {
              RET_VALUE_START (scheme_nzerod ) RET_VALUE_END ; 
            }
          }
          else {
            if (iseven || ! negz ) {
              RET_VALUE_START (scheme_inf_object ) RET_VALUE_END ; 
            }
            else {
              RET_VALUE_START (scheme_minus_inf_object ) RET_VALUE_END ; 
            }
          }
        }
      }
    }
  }
  r = FUNCCALL(SETUP_XfOrM273(_), bin_expt (argv [0 ] , e ) ); 
  if (invert )
    r = FUNCCALL(SETUP_XfOrM273(_), scheme_bin_div (((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) , r ) ); 
  RET_VALUE_START (r ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_rectangular (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * a , * b ; 
  int af , bf ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(b, 0), PUSH(a, 1), PUSH(argv, 2)));
# define XfOrM298_COUNT (3)
# define SETUP_XfOrM298(x) SETUP(XfOrM298_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a = NULLED_OUT ; 
  b = NULLED_OUT ; 
  a = argv [0 ] ; 
  b = argv [1 ] ; 
  if (! ((((long ) (a ) ) & 0x1 ) || ((((a ) -> type ) >= scheme_bignum_type ) && (((a ) -> type ) <= scheme_complex_izi_type ) ) ) )
    FUNCCALL(SETUP_XfOrM298(_), scheme_wrong_type ("make-rectangular" , "real number" , 0 , argc , argv ) ); 
  if (! ((((long ) (b ) ) & 0x1 ) || ((((b ) -> type ) >= scheme_bignum_type ) && (((b ) -> type ) <= scheme_complex_izi_type ) ) ) )
    FUNCCALL(SETUP_XfOrM298(_), scheme_wrong_type ("make-rectangular" , "real number" , 1 , argc , argv ) ); 
  if ((((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) == scheme_complex_izi_type ) )
    a = (((Scheme_Complex * ) (a ) ) -> r ) ; 
  if ((((((long ) (b ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (b ) ) -> type ) == scheme_complex_izi_type ) )
    b = (((Scheme_Complex * ) (b ) ) -> r ) ; 
  af = ((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ; 
  bf = ((Scheme_Type ) (((((long ) (b ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (b ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ; 
  if (af && ! bf ) {
#   define XfOrM300_COUNT (0+XfOrM298_COUNT)
#   define SETUP_XfOrM300(x) SETUP_XfOrM298(x)
    if (b != ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) )
      b = FUNCCALL(SETUP_XfOrM300(_), scheme_exact_to_inexact (1 , & b ) ); 
  }
  if (bf && ! af ) {
#   define XfOrM299_COUNT (0+XfOrM298_COUNT)
#   define SETUP_XfOrM299(x) SETUP_XfOrM298(x)
    if (a != ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) )
      a = FUNCCALL(SETUP_XfOrM299(_), scheme_exact_to_inexact (1 , & a ) ); 
  }
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM298(_), scheme_make_complex (a , b ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_polar (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * a , * b , * r , * i , * v ; 
  Scheme_Object * __funcarg123 = NULLED_OUT ; 
  Scheme_Object * __funcarg122 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(b, 1), PUSH(a, 2), PUSH(r, 3), PUSH(i, 4), PUSH(argv, 5)));
# define XfOrM301_COUNT (6)
# define SETUP_XfOrM301(x) SETUP(XfOrM301_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a = NULLED_OUT ; 
  b = NULLED_OUT ; 
  r = NULLED_OUT ; 
  i = NULLED_OUT ; 
  v = NULLED_OUT ; 
  a = argv [0 ] ; 
  b = argv [1 ] ; 
  if (! ((((long ) (a ) ) & 0x1 ) || ((((a ) -> type ) >= scheme_bignum_type ) && (((a ) -> type ) <= scheme_complex_izi_type ) ) ) )
    FUNCCALL(SETUP_XfOrM301(_), scheme_wrong_type ("make-polar" , "real number" , 0 , argc , argv ) ); 
  if (! ((((long ) (b ) ) & 0x1 ) || ((((b ) -> type ) >= scheme_bignum_type ) && (((b ) -> type ) <= scheme_complex_izi_type ) ) ) )
    FUNCCALL(SETUP_XfOrM301(_), scheme_wrong_type ("make-polar" , "real number" , 1 , argc , argv ) ); 
  if (b == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) )
    RET_VALUE_START (a ) RET_VALUE_END ; 
  if ((((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) == scheme_complex_izi_type ) )
    a = (((Scheme_Complex * ) (a ) ) -> r ) ; 
  if ((((((long ) (b ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (b ) ) -> type ) == scheme_complex_izi_type ) )
    b = (((Scheme_Complex * ) (b ) ) -> r ) ; 
  v = b ; 
  r = (__funcarg123 = FUNCCALL(SETUP_XfOrM301(_), cos_prim (1 , & v ) ), FUNCCALL_AGAIN(scheme_bin_mult (a , __funcarg123 ) )) ; 
  i = (__funcarg122 = FUNCCALL(SETUP_XfOrM301(_), sin_prim (1 , & v ) ), FUNCCALL_AGAIN(scheme_bin_mult (a , __funcarg122 ) )) ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM301(_), scheme_make_complex (r , i ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * real_part (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * o = argv [0 ] ; 
  if (! ((((long ) (o ) ) & 0x1 ) || ((((o ) -> type ) >= scheme_bignum_type ) && (((o ) -> type ) <= scheme_complex_type ) ) ) )
    scheme_wrong_type ("real-part" , "number" , 0 , argc , argv ) ; 
  if ((! (((long ) (o ) ) & 0x1 ) && ((((o ) -> type ) >= scheme_complex_izi_type ) && (((o ) -> type ) <= scheme_complex_type ) ) ) )
    return (((Scheme_Complex * ) (o ) ) -> r ) ; 
  else return argv [0 ] ; 
}
static Scheme_Object * imag_part (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * o = argv [0 ] ; 
  if (! ((((long ) (o ) ) & 0x1 ) || ((((o ) -> type ) >= scheme_bignum_type ) && (((o ) -> type ) <= scheme_complex_type ) ) ) )
    scheme_wrong_type ("imag-part" , "number" , 0 , argc , argv ) ; 
  if ((! (((long ) (o ) ) & 0x1 ) && ((((o ) -> type ) >= scheme_complex_izi_type ) && (((o ) -> type ) <= scheme_complex_type ) ) ) )
    return scheme_complex_imaginary_part (o ) ; 
  return ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
}
static Scheme_Object * magnitude (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * o = argv [0 ] ; 
  Scheme_Object * __funcarg125 = NULLED_OUT ; 
  Scheme_Object * __funcarg124 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM304_COUNT (1)
# define SETUP_XfOrM304(x) SETUP(XfOrM304_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! ((((long ) (o ) ) & 0x1 ) || ((((o ) -> type ) >= scheme_bignum_type ) && (((o ) -> type ) <= scheme_complex_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("magnitude" , "number" , 0 , argc , argv ) ); 
  if ((! (((long ) (o ) ) & 0x1 ) && ((((o ) -> type ) >= scheme_complex_izi_type ) && (((o ) -> type ) <= scheme_complex_type ) ) ) ) {
    Scheme_Object * r = (((Scheme_Complex * ) (o ) ) -> r ) ; 
    Scheme_Object * i = (((Scheme_Complex * ) (o ) ) -> i ) ; 
    Scheme_Object * a [1 ] , * q ; 
    BLOCK_SETUP((PUSH(r, 0+XfOrM304_COUNT), PUSH(q, 1+XfOrM304_COUNT), PUSHARRAY(a, 1, 2+XfOrM304_COUNT), PUSH(i, 5+XfOrM304_COUNT)));
#   define XfOrM305_COUNT (6+XfOrM304_COUNT)
#   define SETUP_XfOrM305(x) SETUP(XfOrM305_COUNT)
    a[0] = NULLED_OUT ; 
    q = NULLED_OUT ; 
    a [0 ] = r ; 
    r = FUNCCALL(SETUP_XfOrM305(_), scheme_abs (1 , a ) ); 
    a [0 ] = i ; 
    i = FUNCCALL(SETUP_XfOrM305(_), scheme_abs (1 , a ) ); 
    if (((r ) == (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) ) )
      RET_VALUE_START (i ) RET_VALUE_END ; 
    if (FUNCCALL(SETUP_XfOrM305(_), scheme_bin_lt (i , r ) )) {
      Scheme_Object * tmp ; 
      tmp = NULLED_OUT ; 
      tmp = i ; 
      i = r ; 
      r = tmp ; 
    }
    if ((scheme_is_zero (r ) ) ) {
#     define XfOrM309_COUNT (0+XfOrM305_COUNT)
#     define SETUP_XfOrM309(x) SETUP_XfOrM305(x)
      a [0 ] = i ; 
      RET_VALUE_START (FUNCCALL(SETUP_XfOrM309(_), scheme_exact_to_inexact (1 , a ) )) RET_VALUE_END ; 
    }
    if (((Scheme_Type ) (((((long ) (i ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (i ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ) {
      double d ; 
      d = (((Scheme_Double * ) (i ) ) -> double_val ) ; 
      if ((isinf (d ) && (d > 0 ) ) ) {
        if (((Scheme_Type ) (((((long ) (r ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (r ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ) {
          d = (((Scheme_Double * ) (r ) ) -> double_val ) ; 
          if (isnan (d ) )
            RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
        }
        RET_VALUE_START (scheme_inf_object ) RET_VALUE_END ; 
      }
    }
    q = FUNCCALL(SETUP_XfOrM305(_), scheme_bin_div (r , i ) ); 
    q = (__funcarg125 = FUNCCALL(SETUP_XfOrM305(_), scheme_bin_mult (q , q ) ), FUNCCALL_AGAIN(scheme_bin_plus (((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) , __funcarg125 ) )) ; 
    a [0 ] = q ; 
    RET_VALUE_START ((__funcarg124 = FUNCCALL(SETUP_XfOrM305(_), scheme_sqrt (1 , a ) ), FUNCCALL_AGAIN(scheme_bin_mult (i , __funcarg124 ) )) ) RET_VALUE_END ; 
  }
  else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_abs (1 , argv ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * angle (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * o = argv [0 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(o, 0)));
# define XfOrM311_COUNT (1)
# define SETUP_XfOrM311(x) SETUP(XfOrM311_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! ((((long ) (o ) ) & 0x1 ) || ((((o ) -> type ) >= scheme_bignum_type ) && (((o ) -> type ) <= scheme_complex_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("angle" , "number" , 0 , argc , argv ) ); 
  if ((! (((long ) (o ) ) & 0x1 ) && ((((o ) -> type ) >= scheme_complex_izi_type ) && (((o ) -> type ) <= scheme_complex_type ) ) ) ) {
    Scheme_Object * r = (Scheme_Object * ) (((Scheme_Complex * ) (o ) ) -> r ) ; 
    Scheme_Object * i = (Scheme_Object * ) (((Scheme_Complex * ) (o ) ) -> i ) ; 
    double rd , id , v ; 
    BLOCK_SETUP((PUSH(r, 0+XfOrM311_COUNT)));
#   define XfOrM317_COUNT (1+XfOrM311_COUNT)
#   define SETUP_XfOrM317(x) SETUP(XfOrM317_COUNT)
    id = FUNCCALL(SETUP_XfOrM317(_), scheme_get_val_as_double (i ) ); 
    rd = FUNCCALL(SETUP_XfOrM317(_), scheme_get_val_as_double (r ) ); 
    v = atan2 (id , rd ) ; 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_double (v ) )) RET_VALUE_EMPTY_END ; 
  }
  else {
#   define XfOrM312_COUNT (0+XfOrM311_COUNT)
#   define SETUP_XfOrM312(x) SETUP_XfOrM311(x)
    if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ) {
      double v = (((Scheme_Double * ) (o ) ) -> double_val ) ; 
#     define XfOrM315_COUNT (0+XfOrM312_COUNT)
#     define SETUP_XfOrM315(x) SETUP_XfOrM312(x)
      if (isnan (v ) )
        RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
      else if (v == 0.0 ) {
        int neg ; 
#       define XfOrM316_COUNT (0+XfOrM315_COUNT)
#       define SETUP_XfOrM316(x) SETUP_XfOrM315(x)
        neg = (minus_zero_p (v ) ) ; 
        v = (neg ? - 1.0 : 1.0 ) ; 
      }
      if (v > 0 )
        RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
      else RET_VALUE_START (scheme_pi ) RET_VALUE_END ; 
    }
    else if (o == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) {
#     define XfOrM314_COUNT (0+XfOrM312_COUNT)
#     define SETUP_XfOrM314(x) SETUP_XfOrM312(x)
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT_DIVIDE_BY_ZERO , "angle: undefined for 0" ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else if ((scheme_is_positive (o ) ) )
      RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
    else {
      RET_VALUE_START (scheme_pi ) RET_VALUE_END ; 
    }
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_exact_to_inexact (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * o = argv [0 ] ; 
  Scheme_Type t ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM318_COUNT (1)
# define SETUP_XfOrM318(x) SETUP(XfOrM318_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((((long ) (o ) ) & 0x1 ) ) {
#   define XfOrM322_COUNT (0+XfOrM318_COUNT)
#   define SETUP_XfOrM322(x) SETUP_XfOrM318(x)
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_double ((((long ) (o ) ) >> 1 ) ) )) RET_VALUE_EMPTY_END ; 
  }
  t = ((o ) -> type ) ; 
  if (t == scheme_double_type )
    RET_VALUE_START (o ) RET_VALUE_END ; 
  if (t == scheme_bignum_type ) {
#   define XfOrM321_COUNT (0+XfOrM318_COUNT)
#   define SETUP_XfOrM321(x) SETUP_XfOrM318(x)
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_double (scheme_bignum_to_double (o ) ) )) RET_VALUE_EMPTY_END ; 
  }
  if (t == scheme_rational_type ) {
#   define XfOrM320_COUNT (0+XfOrM318_COUNT)
#   define SETUP_XfOrM320(x) SETUP_XfOrM318(x)
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_double (scheme_rational_to_double (o ) ) )) RET_VALUE_EMPTY_END ; 
  }
  if ((t == scheme_complex_type ) || (t == scheme_complex_izi_type ) ) {
    Scheme_Object * realpart , * imaginarypart ; 
    BLOCK_SETUP((PUSH(imaginarypart, 0+XfOrM318_COUNT), PUSH(realpart, 1+XfOrM318_COUNT)));
#   define XfOrM319_COUNT (2+XfOrM318_COUNT)
#   define SETUP_XfOrM319(x) SETUP(XfOrM319_COUNT)
    realpart = NULLED_OUT ; 
    imaginarypart = NULLED_OUT ; 
    realpart = (((Scheme_Complex * ) (o ) ) -> r ) ; 
    imaginarypart = (((Scheme_Complex * ) (o ) ) -> i ) ; 
    realpart = FUNCCALL(SETUP_XfOrM319(_), scheme_exact_to_inexact (1 , & realpart ) ); 
    imaginarypart = FUNCCALL_AGAIN(scheme_exact_to_inexact (1 , & imaginarypart ) ); 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM319(_), scheme_make_complex (realpart , imaginarypart ) )) RET_VALUE_END ; 
  }
  FUNCCALL_EMPTY(scheme_wrong_type ("exact->inexact" , "number" , 0 , argc , argv ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_inexact_to_exact (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * o = argv [0 ] ; 
  Scheme_Type t ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM323_COUNT (1)
# define SETUP_XfOrM323(x) SETUP(XfOrM323_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((((long ) (o ) ) & 0x1 ) )
    RET_VALUE_START (o ) RET_VALUE_END ; 
  t = ((o ) -> type ) ; 
  if (t == scheme_double_type ) {
    double d = (((Scheme_Double * ) (o ) ) -> double_val ) ; 
    Scheme_Object * i = ((Scheme_Object * ) (void * ) (long ) ((((long ) ((long ) d ) ) << 1 ) | 0x1 ) ) ; 
#   define XfOrM325_COUNT (0+XfOrM323_COUNT)
#   define SETUP_XfOrM325(x) SETUP_XfOrM323(x)
    if ((double ) (((long ) (i ) ) >> 1 ) == d ) {
      RET_VALUE_START (i ) RET_VALUE_END ; 
    }
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_rational_from_double (d ) )) RET_VALUE_EMPTY_END ; 
  }
  if (t == scheme_bignum_type )
    RET_VALUE_START (o ) RET_VALUE_END ; 
  if (t == scheme_rational_type )
    RET_VALUE_START (o ) RET_VALUE_END ; 
  if ((t == scheme_complex_type ) || (t == scheme_complex_izi_type ) ) {
    Scheme_Object * realpart , * imaginarypart ; 
    BLOCK_SETUP((PUSH(imaginarypart, 0+XfOrM323_COUNT), PUSH(realpart, 1+XfOrM323_COUNT)));
#   define XfOrM324_COUNT (2+XfOrM323_COUNT)
#   define SETUP_XfOrM324(x) SETUP(XfOrM324_COUNT)
    realpart = NULLED_OUT ; 
    imaginarypart = NULLED_OUT ; 
    realpart = (((Scheme_Complex * ) (o ) ) -> r ) ; 
    imaginarypart = (((Scheme_Complex * ) (o ) ) -> i ) ; 
    realpart = FUNCCALL(SETUP_XfOrM324(_), scheme_inexact_to_exact (1 , & realpart ) ); 
    imaginarypart = FUNCCALL_AGAIN(scheme_inexact_to_exact (1 , & imaginarypart ) ); 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM324(_), scheme_make_complex (realpart , imaginarypart ) )) RET_VALUE_END ; 
  }
  FUNCCALL_EMPTY(scheme_wrong_type ("inexact->exact" , "number" , 0 , argc , argv ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * bin_bitwise_and (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
static Scheme_Object * bin_bitwise_or (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
static Scheme_Object * bin_bitwise_xor (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
static Scheme_Object * bin_bitwise_and (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
static Scheme_Object * bin_bitwise_and__wrong_type (const Scheme_Object * v ) {
  Scheme_Object * a [1 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 1, 0)));
# define XfOrM327_COUNT (3)
# define SETUP_XfOrM327(x) SETUP(XfOrM327_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a [0 ] = (Scheme_Object * ) v ; 
  FUNCCALL(SETUP_XfOrM327(_), scheme_wrong_type ("bitwise-and" , "exact integer" , - 1 , 0 , a ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_bitwise_and__int_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Bignum sb ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(sb.o.digits, 0)));
# define XfOrM328_COUNT (1)
# define SETUP_XfOrM328(x) SETUP(XfOrM328_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sb.o.digits = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM328(_), scheme_bignum_and ((scheme_make_small_bignum ((((long ) (n1 ) ) >> 1 ) , & sb ) ) , n2 ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_bitwise_and__big_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Bignum sb ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(sb.o.digits, 0)));
# define XfOrM329_COUNT (1)
# define SETUP_XfOrM329(x) SETUP(XfOrM329_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sb.o.digits = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM329(_), scheme_bignum_and (n1 , (scheme_make_small_bignum ((((long ) (n2 ) ) >> 1 ) , & sb ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * bin_bitwise_and (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  if ((((long ) (n1 ) ) & 0x1 ) ) {
    if ((((long ) (n2 ) ) & 0x1 ) ) {
      long a , b ; 
      a = (((long ) (n1 ) ) >> 1 ) ; 
      b = (((long ) (n2 ) ) >> 1 ) ; 
      return ((Scheme_Object * ) (void * ) (long ) ((((long ) (a & b ) ) << 1 ) | 0x1 ) ) ; 
    }
    else if (((Scheme_Type ) (((((long ) (n2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n2 ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) {
      return bin_bitwise_and__int_big (n1 , n2 ) ; 
    }
  }
  else if (((Scheme_Type ) (((((long ) (n1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n1 ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) {
    if ((((long ) (n2 ) ) & 0x1 ) ) {
      return bin_bitwise_and__big_int (n1 , n2 ) ; 
    }
    if (((Scheme_Type ) (((((long ) (n2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n2 ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
      return scheme_bignum_and (n1 , n2 ) ; 
  }
  else {
    return bin_bitwise_and__wrong_type (n1 ) ; 
  }
  return bin_bitwise_and__wrong_type (n2 ) ; 
}
static Scheme_Object * bin_bitwise_or (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
static Scheme_Object * bin_bitwise_or__wrong_type (const Scheme_Object * v ) {
  Scheme_Object * a [1 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 1, 0)));
# define XfOrM337_COUNT (3)
# define SETUP_XfOrM337(x) SETUP(XfOrM337_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a [0 ] = (Scheme_Object * ) v ; 
  FUNCCALL(SETUP_XfOrM337(_), scheme_wrong_type ("bitwise-ior" , "exact integer" , - 1 , 0 , a ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_bitwise_or__int_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Bignum sb ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(sb.o.digits, 0)));
# define XfOrM338_COUNT (1)
# define SETUP_XfOrM338(x) SETUP(XfOrM338_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sb.o.digits = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM338(_), scheme_bignum_or ((scheme_make_small_bignum ((((long ) (n1 ) ) >> 1 ) , & sb ) ) , n2 ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_bitwise_or__big_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Bignum sb ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(sb.o.digits, 0)));
# define XfOrM339_COUNT (1)
# define SETUP_XfOrM339(x) SETUP(XfOrM339_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sb.o.digits = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM339(_), scheme_bignum_or (n1 , (scheme_make_small_bignum ((((long ) (n2 ) ) >> 1 ) , & sb ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * bin_bitwise_or (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  if ((((long ) (n1 ) ) & 0x1 ) ) {
    if ((((long ) (n2 ) ) & 0x1 ) ) {
      long a , b ; 
      a = (((long ) (n1 ) ) >> 1 ) ; 
      b = (((long ) (n2 ) ) >> 1 ) ; 
      return ((Scheme_Object * ) (void * ) (long ) ((((long ) (a | b ) ) << 1 ) | 0x1 ) ) ; 
    }
    else if (((Scheme_Type ) (((((long ) (n2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n2 ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) {
      return bin_bitwise_or__int_big (n1 , n2 ) ; 
    }
  }
  else if (((Scheme_Type ) (((((long ) (n1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n1 ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) {
    if ((((long ) (n2 ) ) & 0x1 ) ) {
      return bin_bitwise_or__big_int (n1 , n2 ) ; 
    }
    if (((Scheme_Type ) (((((long ) (n2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n2 ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
      return scheme_bignum_or (n1 , n2 ) ; 
  }
  else {
    return bin_bitwise_or__wrong_type (n1 ) ; 
  }
  return bin_bitwise_or__wrong_type (n2 ) ; 
}
static Scheme_Object * bin_bitwise_xor (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
static Scheme_Object * bin_bitwise_xor__wrong_type (const Scheme_Object * v ) {
  Scheme_Object * a [1 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 1, 0)));
# define XfOrM347_COUNT (3)
# define SETUP_XfOrM347(x) SETUP(XfOrM347_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a [0 ] = (Scheme_Object * ) v ; 
  FUNCCALL(SETUP_XfOrM347(_), scheme_wrong_type ("bitwise-xor" , "exact integer" , - 1 , 0 , a ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_bitwise_xor__int_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Bignum sb ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(sb.o.digits, 0)));
# define XfOrM348_COUNT (1)
# define SETUP_XfOrM348(x) SETUP(XfOrM348_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sb.o.digits = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM348(_), scheme_bignum_xor ((scheme_make_small_bignum ((((long ) (n1 ) ) >> 1 ) , & sb ) ) , n2 ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_bitwise_xor__big_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Bignum sb ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(sb.o.digits, 0)));
# define XfOrM349_COUNT (1)
# define SETUP_XfOrM349(x) SETUP(XfOrM349_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sb.o.digits = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM349(_), scheme_bignum_xor (n1 , (scheme_make_small_bignum ((((long ) (n2 ) ) >> 1 ) , & sb ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * bin_bitwise_xor (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  if ((((long ) (n1 ) ) & 0x1 ) ) {
    if ((((long ) (n2 ) ) & 0x1 ) ) {
      long a , b ; 
      a = (((long ) (n1 ) ) >> 1 ) ; 
      b = (((long ) (n2 ) ) >> 1 ) ; 
      return ((Scheme_Object * ) (void * ) (long ) ((((long ) (a ^ b ) ) << 1 ) | 0x1 ) ) ; 
    }
    else if (((Scheme_Type ) (((((long ) (n2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n2 ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) {
      return bin_bitwise_xor__int_big (n1 , n2 ) ; 
    }
  }
  else if (((Scheme_Type ) (((((long ) (n1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n1 ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) {
    if ((((long ) (n2 ) ) & 0x1 ) ) {
      return bin_bitwise_xor__big_int (n1 , n2 ) ; 
    }
    if (((Scheme_Type ) (((((long ) (n2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n2 ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
      return scheme_bignum_xor (n1 , n2 ) ; 
  }
  else {
    return bin_bitwise_xor__wrong_type (n1 ) ; 
  }
  return bin_bitwise_xor__wrong_type (n2 ) ; 
}
Scheme_Object * scheme_bitwise_and (int argc , Scheme_Object * argv [] ) ; 
static inline Scheme_Object * scheme_bitwise_and__slow (Scheme_Object * ret , int argc , Scheme_Object * argv [] ) {
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(ret, 0), PUSH(argv, 1)));
# define XfOrM357_COUNT (2)
# define SETUP_XfOrM357(x) SETUP(XfOrM357_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  for (i = 1 ; i < argc ; ++ i ) {
    Scheme_Object * o ; 
    BLOCK_SETUP((PUSH(o, 0+XfOrM357_COUNT)));
#   define XfOrM360_COUNT (1+XfOrM357_COUNT)
#   define SETUP_XfOrM360(x) SETUP(XfOrM360_COUNT)
    o = NULLED_OUT ; 
    o = argv [i ] ; 
    if (! ((((long ) (o ) ) & 0x1 ) || (((o ) -> type ) == scheme_bignum_type ) ) ) {
#     define XfOrM361_COUNT (0+XfOrM360_COUNT)
#     define SETUP_XfOrM361(x) SETUP_XfOrM360(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("bitwise-and" , "exact integer" , i , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    ret = FUNCCALL(SETUP_XfOrM360(_), bin_bitwise_and (ret , o ) ); 
  }
  RET_VALUE_START ((ret ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_bitwise_and (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * ret ; 
  if (! argc )
    return ((Scheme_Object * ) (void * ) (long ) ((((long ) (- 1 ) ) << 1 ) | 0x1 ) ) ; 
  ret = argv [0 ] ; 
  if (! ((((long ) (ret ) ) & 0x1 ) || (((ret ) -> type ) == scheme_bignum_type ) ) ) {
    scheme_wrong_type ("bitwise-and" , "exact integer" , 0 , argc , argv ) ; 
    return ((void * ) 0 ) ; 
  }
  if (argc == 2 ) {
    Scheme_Object * b ; 
    b = argv [1 ] ; 
    if (! ((((long ) (b ) ) & 0x1 ) || (((b ) -> type ) == scheme_bignum_type ) ) ) {
      scheme_wrong_type ("bitwise-and" , "exact integer" , 1 , argc , argv ) ; 
      return ((void * ) 0 ) ; 
    }
    return bin_bitwise_and (ret , b ) ; 
  }
  return scheme_bitwise_and__slow (ret , argc , argv ) ; 
}
static Scheme_Object * bitwise_or (int argc , Scheme_Object * argv [] ) ; 
static inline Scheme_Object * bitwise_or__slow (Scheme_Object * ret , int argc , Scheme_Object * argv [] ) {
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(ret, 0), PUSH(argv, 1)));
# define XfOrM366_COUNT (2)
# define SETUP_XfOrM366(x) SETUP(XfOrM366_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  for (i = 1 ; i < argc ; ++ i ) {
    Scheme_Object * o ; 
    BLOCK_SETUP((PUSH(o, 0+XfOrM366_COUNT)));
#   define XfOrM369_COUNT (1+XfOrM366_COUNT)
#   define SETUP_XfOrM369(x) SETUP(XfOrM369_COUNT)
    o = NULLED_OUT ; 
    o = argv [i ] ; 
    if (! ((((long ) (o ) ) & 0x1 ) || (((o ) -> type ) == scheme_bignum_type ) ) ) {
#     define XfOrM370_COUNT (0+XfOrM369_COUNT)
#     define SETUP_XfOrM370(x) SETUP_XfOrM369(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("bitwise-ior" , "exact integer" , i , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    ret = FUNCCALL(SETUP_XfOrM369(_), bin_bitwise_or (ret , o ) ); 
  }
  RET_VALUE_START ((ret ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * bitwise_or (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * ret ; 
  if (! argc )
    return ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
  ret = argv [0 ] ; 
  if (! ((((long ) (ret ) ) & 0x1 ) || (((ret ) -> type ) == scheme_bignum_type ) ) ) {
    scheme_wrong_type ("bitwise-ior" , "exact integer" , 0 , argc , argv ) ; 
    return ((void * ) 0 ) ; 
  }
  if (argc == 2 ) {
    Scheme_Object * b ; 
    b = argv [1 ] ; 
    if (! ((((long ) (b ) ) & 0x1 ) || (((b ) -> type ) == scheme_bignum_type ) ) ) {
      scheme_wrong_type ("bitwise-ior" , "exact integer" , 1 , argc , argv ) ; 
      return ((void * ) 0 ) ; 
    }
    return bin_bitwise_or (ret , b ) ; 
  }
  return bitwise_or__slow (ret , argc , argv ) ; 
}
static Scheme_Object * bitwise_xor (int argc , Scheme_Object * argv [] ) ; 
static inline Scheme_Object * bitwise_xor__slow (Scheme_Object * ret , int argc , Scheme_Object * argv [] ) {
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(ret, 0), PUSH(argv, 1)));
# define XfOrM375_COUNT (2)
# define SETUP_XfOrM375(x) SETUP(XfOrM375_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  for (i = 1 ; i < argc ; ++ i ) {
    Scheme_Object * o ; 
    BLOCK_SETUP((PUSH(o, 0+XfOrM375_COUNT)));
#   define XfOrM378_COUNT (1+XfOrM375_COUNT)
#   define SETUP_XfOrM378(x) SETUP(XfOrM378_COUNT)
    o = NULLED_OUT ; 
    o = argv [i ] ; 
    if (! ((((long ) (o ) ) & 0x1 ) || (((o ) -> type ) == scheme_bignum_type ) ) ) {
#     define XfOrM379_COUNT (0+XfOrM378_COUNT)
#     define SETUP_XfOrM379(x) SETUP_XfOrM378(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("bitwise-xor" , "exact integer" , i , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    ret = FUNCCALL(SETUP_XfOrM378(_), bin_bitwise_xor (ret , o ) ); 
  }
  RET_VALUE_START ((ret ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * bitwise_xor (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * ret ; 
  if (! argc )
    return ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
  ret = argv [0 ] ; 
  if (! ((((long ) (ret ) ) & 0x1 ) || (((ret ) -> type ) == scheme_bignum_type ) ) ) {
    scheme_wrong_type ("bitwise-xor" , "exact integer" , 0 , argc , argv ) ; 
    return ((void * ) 0 ) ; 
  }
  if (argc == 2 ) {
    Scheme_Object * b ; 
    b = argv [1 ] ; 
    if (! ((((long ) (b ) ) & 0x1 ) || (((b ) -> type ) == scheme_bignum_type ) ) ) {
      scheme_wrong_type ("bitwise-xor" , "exact integer" , 1 , argc , argv ) ; 
      return ((void * ) 0 ) ; 
    }
    return bin_bitwise_xor (ret , b ) ; 
  }
  return bitwise_xor__slow (ret , argc , argv ) ; 
}
static Scheme_Object * bitwise_not (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * o = argv [0 ] ; 
  if ((((long ) (o ) ) & 0x1 ) ) {
    long a = (((long ) (o ) ) >> 1 ) ; 
    a = ~ a ; 
    return ((Scheme_Object * ) (void * ) (long ) ((((long ) (a ) ) << 1 ) | 0x1 ) ) ; 
  }
  else if (((o ) -> type ) == scheme_bignum_type )
    return scheme_bignum_not (o ) ; 
  scheme_wrong_type ("bitwise-not" , "exact integer" , 0 , argc , argv ) ; 
  return ((void * ) 0 ) ; 
}
Scheme_Object * scheme_bitwise_shift (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * v , * so ; 
  long shift ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(v, 0)));
# define XfOrM386_COUNT (1)
# define SETUP_XfOrM386(x) SETUP(XfOrM386_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  so = NULLED_OUT ; 
  v = argv [0 ] ; 
  if (! ((((long ) (v ) ) & 0x1 ) || (((v ) -> type ) == scheme_bignum_type ) ) ) {
#   define XfOrM395_COUNT (0+XfOrM386_COUNT)
#   define SETUP_XfOrM395(x) SETUP_XfOrM386(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("arithmetic-shift" , "exact integer" , 0 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  so = argv [1 ] ; 
  if (! (((long ) (so ) ) & 0x1 ) ) {
#   define XfOrM392_COUNT (0+XfOrM386_COUNT)
#   define SETUP_XfOrM392(x) SETUP_XfOrM386(x)
    if (((Scheme_Type ) (((((long ) (so ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (so ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) {
#     define XfOrM393_COUNT (0+XfOrM392_COUNT)
#     define SETUP_XfOrM393(x) SETUP_XfOrM392(x)
      if (! ((& ((Scheme_Bignum * ) so ) -> iso ) -> so . keyex & 0x1 ) ) {
#       define XfOrM394_COUNT (0+XfOrM393_COUNT)
#       define SETUP_XfOrM394(x) SETUP_XfOrM393(x)
        if ((scheme_is_negative (v ) ) )
          RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (- 1 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
        else RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
      }
      else FUNCCALL_EMPTY(scheme_raise_out_of_memory ("arithmetic-shift" , ((void * ) 0 ) ) ); 
    }
    else FUNCCALL_EMPTY(scheme_wrong_type ("arithmetic-shift" , "exact integer" , 1 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  shift = (((long ) (so ) ) >> 1 ) ; 
  if (! shift )
    RET_VALUE_START (v ) RET_VALUE_END ; 
  if ((((long ) (v ) ) & 0x1 ) ) {
    long i = (((long ) (v ) ) >> 1 ) ; 
#   define XfOrM387_COUNT (0+XfOrM386_COUNT)
#   define SETUP_XfOrM387(x) SETUP_XfOrM386(x)
    if (! i )
      RET_VALUE_START (v ) RET_VALUE_END ; 
    if (i > 0 ) {
      if (shift < 0 ) {
        int shft = - shift ; 
        if (shft < 64 ) {
          i = i >> shft ; 
          RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (i ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
        }
        else RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
      }
      else if (shift <= 61 ) {
        long n ; 
        n = i << shift ; 
        if ((n > 0 ) && ((((long ) (((Scheme_Object * ) (void * ) (long ) ((((long ) (n ) ) << 1 ) | 0x1 ) ) ) ) >> 1 ) >> shift == i ) )
          RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (n ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
      }
    }
    v = FUNCCALL(SETUP_XfOrM387(_), scheme_make_bignum (i ) ); 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_bignum_shift (v , shift ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * integer_length (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * o = argv [0 ] ; 
  unsigned long n ; 
  int base ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(o, 1)));
# define XfOrM396_COUNT (2)
# define SETUP_XfOrM396(x) SETUP(XfOrM396_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if ((((long ) (o ) ) & 0x1 ) ) {
    long a = (((long ) (o ) ) >> 1 ) ; 
    if (a < 0 )
      a = ~ a ; 
    n = a ; 
    base = 0 ; 
  }
  else if (((o ) -> type ) == scheme_bignum_type ) {
    bigdig d ; 
#   define XfOrM400_COUNT (0+XfOrM396_COUNT)
#   define SETUP_XfOrM400(x) SETUP_XfOrM396(x)
    if (! ((& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex & 0x1 ) ) {
#     define XfOrM401_COUNT (0+XfOrM400_COUNT)
#     define SETUP_XfOrM401(x) SETUP_XfOrM400(x)
      o = FUNCCALL(SETUP_XfOrM401(_), scheme_bignum_not (o ) ); 
    }
    base = ((Scheme_Bignum * ) o ) -> len ; 
    d = ((Scheme_Bignum * ) o ) -> digits [base - 1 ] ; 
    base = (base - 1 ) * (sizeof (bigdig ) * 8 ) ; 
    n = d ; 
  }
  else {
#   define XfOrM399_COUNT (0+XfOrM396_COUNT)
#   define SETUP_XfOrM399(x) SETUP_XfOrM396(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("integer-length" , "exact integer" , 0 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  while (n ) {
    n >>= 1 ; 
    base ++ ; 
  }
  RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (base ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
