#include "precomp.h"
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
extern char * __tzname [2 ] ; 
extern char * tzname [2 ] ; 
extern long int timezone ; 
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
extern int setitimer (__itimer_which_t __which , __const struct itimerval * __restrict __new , struct itimerval * __restrict __old ) __attribute__ ((__nothrow__ ) ) ; 
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
typedef __intptr_t intptr_t ; 
extern int close (int __fd ) ; 
extern ssize_t read (int __fd , void * __buf , size_t __nbytes ) ; 
extern ssize_t write (int __fd , __const void * __buf , size_t __n ) ; 
enum {
  _PC_LINK_MAX , _PC_MAX_CANON , _PC_MAX_INPUT , _PC_NAME_MAX , _PC_PATH_MAX , _PC_PIPE_BUF , _PC_CHOWN_RESTRICTED , _PC_NO_TRUNC , _PC_VDISABLE , _PC_SYNC_IO , _PC_ASYNC_IO , _PC_PRIO_IO , _PC_SOCK_MAXBUF , _PC_FILESIZEBITS , _PC_REC_INCR_XFER_SIZE , _PC_REC_MAX_XFER_SIZE , _PC_REC_MIN_XFER_SIZE , _PC_REC_XFER_ALIGN , _PC_ALLOC_SIZE_MIN , _PC_SYMLINK_MAX , _PC_2_SYMLINKS }
; 
enum {
  _SC_ARG_MAX , _SC_CHILD_MAX , _SC_CLK_TCK , _SC_NGROUPS_MAX , _SC_OPEN_MAX , _SC_STREAM_MAX , _SC_TZNAME_MAX , _SC_JOB_CONTROL , _SC_SAVED_IDS , _SC_REALTIME_SIGNALS , _SC_PRIORITY_SCHEDULING , _SC_TIMERS , _SC_ASYNCHRONOUS_IO , _SC_PRIORITIZED_IO , _SC_SYNCHRONIZED_IO , _SC_FSYNC , _SC_MAPPED_FILES , _SC_MEMLOCK , _SC_MEMLOCK_RANGE , _SC_MEMORY_PROTECTION , _SC_MESSAGE_PASSING , _SC_SEMAPHORES , _SC_SHARED_MEMORY_OBJECTS , _SC_AIO_LISTIO_MAX , _SC_AIO_MAX , _SC_AIO_PRIO_DELTA_MAX , _SC_DELAYTIMER_MAX , _SC_MQ_OPEN_MAX , _SC_MQ_PRIO_MAX , _SC_VERSION , _SC_PAGESIZE , _SC_RTSIG_MAX , _SC_SEM_NSEMS_MAX , _SC_SEM_VALUE_MAX , _SC_SIGQUEUE_MAX , _SC_TIMER_MAX , _SC_BC_BASE_MAX , _SC_BC_DIM_MAX , _SC_BC_SCALE_MAX , _SC_BC_STRING_MAX , _SC_COLL_WEIGHTS_MAX , _SC_EQUIV_CLASS_MAX , _SC_EXPR_NEST_MAX , _SC_LINE_MAX , _SC_RE_DUP_MAX , _SC_CHARCLASS_NAME_MAX , _SC_2_VERSION , _SC_2_C_BIND , _SC_2_C_DEV , _SC_2_FORT_DEV , _SC_2_FORT_RUN , _SC_2_SW_DEV , _SC_2_LOCALEDEF , _SC_PII , _SC_PII_XTI , _SC_PII_SOCKET , _SC_PII_INTERNET , _SC_PII_OSI , _SC_POLL , _SC_SELECT , _SC_UIO_MAXIOV , _SC_IOV_MAX = _SC_UIO_MAXIOV , _SC_PII_INTERNET_STREAM , _SC_PII_INTERNET_DGRAM , _SC_PII_OSI_COTS , _SC_PII_OSI_CLTS , _SC_PII_OSI_M , _SC_T_IOV_MAX , _SC_THREADS , _SC_THREAD_SAFE_FUNCTIONS , _SC_GETGR_R_SIZE_MAX , _SC_GETPW_R_SIZE_MAX , _SC_LOGIN_NAME_MAX , _SC_TTY_NAME_MAX , _SC_THREAD_DESTRUCTOR_ITERATIONS , _SC_THREAD_KEYS_MAX , _SC_THREAD_STACK_MIN , _SC_THREAD_THREADS_MAX , _SC_THREAD_ATTR_STACKADDR , _SC_THREAD_ATTR_STACKSIZE , _SC_THREAD_PRIORITY_SCHEDULING , _SC_THREAD_PRIO_INHERIT , _SC_THREAD_PRIO_PROTECT , _SC_THREAD_PROCESS_SHARED , _SC_NPROCESSORS_CONF , _SC_NPROCESSORS_ONLN , _SC_PHYS_PAGES , _SC_AVPHYS_PAGES , _SC_ATEXIT_MAX , _SC_PASS_MAX , _SC_XOPEN_VERSION , _SC_XOPEN_XCU_VERSION , _SC_XOPEN_UNIX , _SC_XOPEN_CRYPT , _SC_XOPEN_ENH_I18N , _SC_XOPEN_SHM , _SC_2_CHAR_TERM , _SC_2_C_VERSION , _SC_2_UPE , _SC_XOPEN_XPG2 , _SC_XOPEN_XPG3 , _SC_XOPEN_XPG4 , _SC_CHAR_BIT , _SC_CHAR_MAX , _SC_CHAR_MIN , _SC_INT_MAX , _SC_INT_MIN , _SC_LONG_BIT , _SC_WORD_BIT , _SC_MB_LEN_MAX , _SC_NZERO , _SC_SSIZE_MAX , _SC_SCHAR_MAX , _SC_SCHAR_MIN , _SC_SHRT_MAX , _SC_SHRT_MIN , _SC_UCHAR_MAX , _SC_UINT_MAX , _SC_ULONG_MAX , _SC_USHRT_MAX , _SC_NL_ARGMAX , _SC_NL_LANGMAX , _SC_NL_MSGMAX , _SC_NL_NMAX , _SC_NL_SETMAX , _SC_NL_TEXTMAX , _SC_XBS5_ILP32_OFF32 , _SC_XBS5_ILP32_OFFBIG , _SC_XBS5_LP64_OFF64 , _SC_XBS5_LPBIG_OFFBIG , _SC_XOPEN_LEGACY , _SC_XOPEN_REALTIME , _SC_XOPEN_REALTIME_THREADS , _SC_ADVISORY_INFO , _SC_BARRIERS , _SC_BASE , _SC_C_LANG_SUPPORT , _SC_C_LANG_SUPPORT_R , _SC_CLOCK_SELECTION , _SC_CPUTIME , _SC_THREAD_CPUTIME , _SC_DEVICE_IO , _SC_DEVICE_SPECIFIC , _SC_DEVICE_SPECIFIC_R , _SC_FD_MGMT , _SC_FIFO , _SC_PIPE , _SC_FILE_ATTRIBUTES , _SC_FILE_LOCKING , _SC_FILE_SYSTEM , _SC_MONOTONIC_CLOCK , _SC_MULTI_PROCESS , _SC_SINGLE_PROCESS , _SC_NETWORKING , _SC_READER_WRITER_LOCKS , _SC_SPIN_LOCKS , _SC_REGEXP , _SC_REGEX_VERSION , _SC_SHELL , _SC_SIGNALS , _SC_SPAWN , _SC_SPORADIC_SERVER , _SC_THREAD_SPORADIC_SERVER , _SC_SYSTEM_DATABASE , _SC_SYSTEM_DATABASE_R , _SC_TIMEOUTS , _SC_TYPED_MEMORY_OBJECTS , _SC_USER_GROUPS , _SC_USER_GROUPS_R , _SC_2_PBS , _SC_2_PBS_ACCOUNTING , _SC_2_PBS_LOCATE , _SC_2_PBS_MESSAGE , _SC_2_PBS_TRACK , _SC_SYMLOOP_MAX , _SC_STREAMS , _SC_2_PBS_CHECKPOINT , _SC_V6_ILP32_OFF32 , _SC_V6_ILP32_OFFBIG , _SC_V6_LP64_OFF64 , _SC_V6_LPBIG_OFFBIG , _SC_HOST_NAME_MAX , _SC_TRACE , _SC_TRACE_EVENT_FILTER , _SC_TRACE_INHERIT , _SC_TRACE_LOG , _SC_LEVEL1_ICACHE_SIZE , _SC_LEVEL1_ICACHE_ASSOC , _SC_LEVEL1_ICACHE_LINESIZE , _SC_LEVEL1_DCACHE_SIZE , _SC_LEVEL1_DCACHE_ASSOC , _SC_LEVEL1_DCACHE_LINESIZE , _SC_LEVEL2_CACHE_SIZE , _SC_LEVEL2_CACHE_ASSOC , _SC_LEVEL2_CACHE_LINESIZE , _SC_LEVEL3_CACHE_SIZE , _SC_LEVEL3_CACHE_ASSOC , _SC_LEVEL3_CACHE_LINESIZE , _SC_LEVEL4_CACHE_SIZE , _SC_LEVEL4_CACHE_ASSOC , _SC_LEVEL4_CACHE_LINESIZE , _SC_IPV6 = _SC_LEVEL1_ICACHE_SIZE + 50 , _SC_RAW_SOCKETS }
; 
enum {
  _CS_PATH , _CS_V6_WIDTH_RESTRICTED_ENVS , _CS_GNU_LIBC_VERSION , _CS_GNU_LIBPTHREAD_VERSION , _CS_LFS_CFLAGS = 1000 , _CS_LFS_LDFLAGS , _CS_LFS_LIBS , _CS_LFS_LINTFLAGS , _CS_LFS64_CFLAGS , _CS_LFS64_LDFLAGS , _CS_LFS64_LIBS , _CS_LFS64_LINTFLAGS , _CS_XBS5_ILP32_OFF32_CFLAGS = 1100 , _CS_XBS5_ILP32_OFF32_LDFLAGS , _CS_XBS5_ILP32_OFF32_LIBS , _CS_XBS5_ILP32_OFF32_LINTFLAGS , _CS_XBS5_ILP32_OFFBIG_CFLAGS , _CS_XBS5_ILP32_OFFBIG_LDFLAGS , _CS_XBS5_ILP32_OFFBIG_LIBS , _CS_XBS5_ILP32_OFFBIG_LINTFLAGS , _CS_XBS5_LP64_OFF64_CFLAGS , _CS_XBS5_LP64_OFF64_LDFLAGS , _CS_XBS5_LP64_OFF64_LIBS , _CS_XBS5_LP64_OFF64_LINTFLAGS , _CS_XBS5_LPBIG_OFFBIG_CFLAGS , _CS_XBS5_LPBIG_OFFBIG_LDFLAGS , _CS_XBS5_LPBIG_OFFBIG_LIBS , _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS , _CS_POSIX_V6_ILP32_OFF32_CFLAGS , _CS_POSIX_V6_ILP32_OFF32_LDFLAGS , _CS_POSIX_V6_ILP32_OFF32_LIBS , _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS , _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS , _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS , _CS_POSIX_V6_ILP32_OFFBIG_LIBS , _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS , _CS_POSIX_V6_LP64_OFF64_CFLAGS , _CS_POSIX_V6_LP64_OFF64_LDFLAGS , _CS_POSIX_V6_LP64_OFF64_LIBS , _CS_POSIX_V6_LP64_OFF64_LINTFLAGS , _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS , _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS , _CS_POSIX_V6_LPBIG_OFFBIG_LIBS , _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS }
; 
extern void scheme_gmp_tls_init (long * s ) ; 
extern void scheme_gmp_tls_load (long * s ) ; 
extern void scheme_gmp_tls_unload (long * s ) ; 
extern void scheme_gmp_tls_snapshot (long * s , long * save ) ; 
extern void scheme_gmp_tls_restore_snapshot (long * s , long * save , int do_free ) ; 
extern int scheme_num_read_syntax_objects ; 
extern int scheme_hash_request_count ; 
extern int scheme_hash_iteration_count ; 
static int buffer_init_size = 20 ; 
Scheme_Thread * scheme_current_thread = ((void * ) 0 ) ; 
Scheme_Thread * scheme_main_thread = ((void * ) 0 ) ; 
Scheme_Thread * scheme_first_thread = ((void * ) 0 ) ; 
Scheme_Thread * scheme_get_current_thread () {
  /* No conversion */
  return scheme_current_thread ; 
}
typedef struct Scheme_Thread_Set {
  Scheme_Object so ; 
  struct Scheme_Thread_Set * parent ; 
  Scheme_Object * first ; 
  Scheme_Object * next ; 
  Scheme_Object * prev ; 
  Scheme_Object * search_start ; 
  Scheme_Object * current ; 
}
Scheme_Thread_Set ; 
Scheme_Thread_Set * thread_set_top ; 
static int num_running_threads = 1 ; 
void * scheme_deepest_stack_start ; 
static int swap_no_setjmp = 0 ; 
static int thread_swap_count ; 
static int did_gc_count ; 
Scheme_Object * * scheme_current_runstack_start ; 
Scheme_Object * * scheme_current_runstack ; 
long scheme_current_cont_mark_stack ; 
long scheme_current_cont_mark_pos ; 
static Scheme_Custodian * main_custodian ; 
static Scheme_Custodian * last_custodian ; 
static Scheme_Hash_Table * limited_custodians = ((void * ) 0 ) ; 
static Scheme_Thread * swap_target ; 
static Scheme_Object * scheduled_kills ; 
Scheme_Object * scheme_parameterization_key ; 
Scheme_Object * scheme_exn_handler_key ; 
Scheme_Object * scheme_break_enabled_key ; 
long scheme_total_gc_time ; 
static long start_this_gc_time ; 
extern void (* GC_collect_start_callback ) (void ) ; 
extern void (* GC_collect_end_callback ) (void ) ; 
static void get_ready_for_GC (void ) ; 
static void done_with_GC (void ) ; 
static short delay_breaks = 0 , delayed_break_ready = 0 ; 
void (* scheme_sleep ) (float seconds , void * fds ) ; 
void (* scheme_notify_multithread ) (int on ) ; 
void (* scheme_wakeup_on_input ) (void * fds ) ; 
int (* scheme_check_for_break ) (void ) ; 
void (* scheme_on_atomic_timeout ) (void ) ; 
static int do_atomic = 0 ; 
static int missed_context_switch = 0 ; 
static int have_activity = 0 ; 
int scheme_active_but_sleeping = 0 ; 
static int thread_ended_with_activity ; 
static int needs_sleep_cancelled ; 
static int tls_pos = 0 ; 
extern long GC_get_memory_use (void * c ) ; 
typedef struct Thread_Cell {
  Scheme_Object so ; 
  char inherited , assigned ; 
  Scheme_Object * def_val ; 
  Scheme_Bucket_Table * vals ; 
}
Thread_Cell ; 
static Scheme_Object * empty_symbol , * initial_symbol ; 
static Scheme_Object * read_symbol , * write_symbol , * execute_symbol , * delete_symbol , * exists_symbol ; 
static Scheme_Object * client_symbol , * server_symbol ; 
static Scheme_Object * nested_exn_handler ; 
static Scheme_Object * closers ; 
static Scheme_Object * thread_swap_callbacks ; 
static Scheme_Object * recycle_cell ; 
static Scheme_Object * maybe_recycle_cell ; 
static int recycle_cc_count ; 
static mz_jmp_buf main_init_error_buf ; 
typedef struct {
  short type ; 
  short hash_key ; 
  Scheme_Custodian * val ; 
}
Scheme_Custodian_Weak_Box ; 
static void register_traversers (void ) ; 
static void prepare_this_thread_for_GC (Scheme_Thread * t ) ; 
static Scheme_Object * custodian_require_mem (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * custodian_limit_mem (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * custodian_can_mem (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * new_tracking_fun (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * union_tracking_val (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * collect_garbage (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * current_memory_use (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * sch_thread (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * sch_thread_nokill (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * sch_sleep (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * thread_p (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * thread_running_p (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * thread_dead_p (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * thread_wait (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * sch_current (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * kill_thread (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * break_thread (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * thread_suspend (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * thread_resume (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * make_thread_suspend (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * make_thread_resume (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * make_thread_dead (int argc , Scheme_Object * args [] ) ; 
static void register_thread_sync () ; 
static Scheme_Object * sch_sync (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * sch_sync_timeout (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * sch_sync_enable_break (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * sch_sync_timeout_enable_break (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * evt_p (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * evts_to_evt (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * make_custodian (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * custodian_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * custodian_close_all (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * custodian_to_list (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * current_custodian (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * make_custodian_box (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * custodian_box_value (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * custodian_box_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * call_as_nested_thread (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * current_namespace (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * namespace_p (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * parameter_p (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * parameter_procedure_eq (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * make_parameter (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * make_derived_parameter (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * extend_parameterization (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * parameterization_p (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * make_thread_cell (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * thread_cell_p (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * thread_cell_get (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * thread_cell_set (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * thread_cell_values (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * make_security_guard (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * security_guard_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * current_security_guard (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * make_thread_set (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * thread_set_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * current_thread_set (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * current_thread_initial_stack_size (int argc , Scheme_Object * argv [] ) ; 
static void adjust_custodian_family (void * pr , void * ignored ) ; 
static Scheme_Object * make_will_executor (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * will_executor_p (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * register_will (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * will_executor_try (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * will_executor_go (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * will_executor_sema (Scheme_Object * w , int * repost ) ; 
static Scheme_Object * check_break_now (int argc , Scheme_Object * args [] ) ; 
static void make_initial_config (Scheme_Thread * p ) ; 
static int do_kill_thread (Scheme_Thread * p ) ; 
static void suspend_thread (Scheme_Thread * p ) ; 
static void wait_until_suspend_ok () ; 
static int check_sleep (int need_activity , int sleep_now ) ; 
static void remove_thread (Scheme_Thread * r ) ; 
static void exit_or_escape (Scheme_Thread * p ) ; 
static int resume_suspend_ready (Scheme_Object * o , Scheme_Schedule_Info * sinfo ) ; 
static int dead_ready (Scheme_Object * o , Scheme_Schedule_Info * sinfo ) ; 
static int can_break_param (Scheme_Thread * p ) ; 
static int post_system_idle () ; 
static Scheme_Object * current_stats (int argc , Scheme_Object * args [] ) ; 
static Scheme_Object * * config_map ; 
Scheme_Object * mtrace_cmark_key = ((void * ) 0 ) ; 
typedef struct {
  Scheme_Type type ; 
  short is_derived ; 
  Scheme_Object * key ; 
  Scheme_Object * guard ; 
  Scheme_Object * extract_guard ; 
  Scheme_Object * defcell ; 
}
ParamData ; 
enum {
  CONFIG_DIRECT , CONFIG_INDIRECT }
; 
typedef struct Scheme_Thread_Custodian_Hop {
  Scheme_Object so ; 
  Scheme_Thread * p ; 
}
Scheme_Thread_Custodian_Hop ; 
static Scheme_Custodian_Extractor * extractors ; 
typedef struct {
  Scheme_Type type ; 
  Scheme_Object * key ; 
  void (* f ) (Scheme_Env * ) ; 
}
Scheme_NSO ; 
static int num_nsos = 0 ; 
static Scheme_NSO * namespace_options = ((void * ) 0 ) ; 
static unsigned long get_current_stack_start (void ) ; 
void scheme_init_thread (Scheme_Env * env ) {
  Scheme_Object * __funcarg68 = NULLED_OUT ; 
  Scheme_Object * __funcarg67 = NULLED_OUT ; 
  Scheme_Object * __funcarg66 = NULLED_OUT ; 
  Scheme_Object * __funcarg65 = NULLED_OUT ; 
  Scheme_Object * __funcarg64 = NULLED_OUT ; 
  Scheme_Object * __funcarg63 = NULLED_OUT ; 
  Scheme_Object * __funcarg62 = NULLED_OUT ; 
  Scheme_Object * __funcarg61 = NULLED_OUT ; 
  Scheme_Object * __funcarg60 = NULLED_OUT ; 
  Scheme_Object * __funcarg59 = NULLED_OUT ; 
  Scheme_Object * __funcarg58 = NULLED_OUT ; 
  Scheme_Object * __funcarg57 = NULLED_OUT ; 
  Scheme_Object * __funcarg56 = NULLED_OUT ; 
  Scheme_Object * __funcarg55 = NULLED_OUT ; 
  Scheme_Object * __funcarg54 = NULLED_OUT ; 
  Scheme_Object * __funcarg53 = NULLED_OUT ; 
  Scheme_Object * __funcarg52 = NULLED_OUT ; 
  Scheme_Object * __funcarg51 = NULLED_OUT ; 
  Scheme_Object * __funcarg50 = NULLED_OUT ; 
  Scheme_Object * __funcarg49 = NULLED_OUT ; 
  Scheme_Object * __funcarg48 = NULLED_OUT ; 
  Scheme_Object * __funcarg47 = NULLED_OUT ; 
  Scheme_Object * __funcarg46 = NULLED_OUT ; 
  Scheme_Object * __funcarg45 = NULLED_OUT ; 
  Scheme_Object * __funcarg44 = NULLED_OUT ; 
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
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(env, 0)));
# define XfOrM2_COUNT (1)
# define SETUP_XfOrM2(x) SETUP(XfOrM2_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  (__funcarg68 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (scheme_dump_gc_stats , "dump-memory-stats" , 0 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("dump-memory-stats" , __funcarg68 , env ) )) ; 
  (__funcarg67 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (current_stats , "vector-set-performance-stats!" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("vector-set-performance-stats!" , __funcarg67 , env ) )) ; 
  (__funcarg66 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (scheme_make_namespace , "make-namespace" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-namespace" , __funcarg66 , env ) )) ; 
  (__funcarg65 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (sch_thread , "thread" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("thread" , __funcarg65 , env ) )) ; 
  (__funcarg64 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (sch_thread_nokill , "thread/suspend-to-kill" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("thread/suspend-to-kill" , __funcarg64 , env ) )) ; 
  (__funcarg63 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (sch_sleep , "sleep" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("sleep" , __funcarg63 , env ) )) ; 
  (__funcarg62 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_folding_prim (thread_p , "thread?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("thread?" , __funcarg62 , env ) )) ; 
  (__funcarg61 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (thread_running_p , "thread-running?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("thread-running?" , __funcarg61 , env ) )) ; 
  (__funcarg60 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (thread_dead_p , "thread-dead?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("thread-dead?" , __funcarg60 , env ) )) ; 
  (__funcarg59 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (thread_wait , "thread-wait" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("thread-wait" , __funcarg59 , env ) )) ; 
  (__funcarg58 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (sch_current , "current-thread" , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-thread" , __funcarg58 , env ) )) ; 
  (__funcarg57 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (kill_thread , "kill-thread" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("kill-thread" , __funcarg57 , env ) )) ; 
  (__funcarg56 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (break_thread , "break-thread" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("break-thread" , __funcarg56 , env ) )) ; 
  (__funcarg55 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (thread_suspend , "thread-suspend" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("thread-suspend" , __funcarg55 , env ) )) ; 
  (__funcarg54 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (thread_resume , "thread-resume" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("thread-resume" , __funcarg54 , env ) )) ; 
  (__funcarg53 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (make_thread_resume , "thread-resume-evt" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("thread-resume-evt" , __funcarg53 , env ) )) ; 
  (__funcarg52 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (make_thread_suspend , "thread-suspend-evt" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("thread-suspend-evt" , __funcarg52 , env ) )) ; 
  (__funcarg51 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (make_thread_dead , "thread-dead-evt" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("thread-dead-evt" , __funcarg51 , env ) )) ; 
  FUNCCALL_AGAIN(register_thread_sync () ); 
  FUNCCALL_AGAIN(scheme_add_evt (scheme_thread_suspend_type , (Scheme_Ready_Fun ) resume_suspend_ready , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ); 
  FUNCCALL_AGAIN(scheme_add_evt (scheme_thread_resume_type , (Scheme_Ready_Fun ) resume_suspend_ready , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ); 
  FUNCCALL_AGAIN(scheme_add_evt (scheme_thread_dead_type , (Scheme_Ready_Fun ) dead_ready , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ); 
  (__funcarg50 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (make_custodian , "make-custodian" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-custodian" , __funcarg50 , env ) )) ; 
  (__funcarg49 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_folding_prim (custodian_p , "custodian?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("custodian?" , __funcarg49 , env ) )) ; 
  (__funcarg48 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (custodian_close_all , "custodian-shutdown-all" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("custodian-shutdown-all" , __funcarg48 , env ) )) ; 
  (__funcarg47 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (custodian_to_list , "custodian-managed-list" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("custodian-managed-list" , __funcarg47 , env ) )) ; 
  (__funcarg46 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (current_custodian , "current-custodian" , MZCONFIG_CUSTODIAN ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-custodian" , __funcarg46 , env ) )) ; 
  (__funcarg45 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (make_custodian_box , "make-custodian-box" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-custodian-box" , __funcarg45 , env ) )) ; 
  (__funcarg44 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (custodian_box_value , "custodian-box-value" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("custodian-box-value" , __funcarg44 , env ) )) ; 
  (__funcarg43 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_folding_prim (custodian_box_p , "custodian-box?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("custodian-box?" , __funcarg43 , env ) )) ; 
  (__funcarg42 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (call_as_nested_thread , "call-in-nested-thread" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("call-in-nested-thread" , __funcarg42 , env ) )) ; 
  (__funcarg41 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (current_namespace , "current-namespace" , MZCONFIG_ENV ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-namespace" , __funcarg41 , env ) )) ; 
  (__funcarg40 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (namespace_p , "namespace?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("namespace?" , __funcarg40 , env ) )) ; 
  (__funcarg39 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (security_guard_p , "security-guard?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("security-guard?" , __funcarg39 , env ) )) ; 
  (__funcarg38 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (make_security_guard , "make-security-guard" , 3 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-security-guard" , __funcarg38 , env ) )) ; 
  (__funcarg37 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (current_security_guard , "current-security-guard" , MZCONFIG_SECURITY_GUARD ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-security-guard" , __funcarg37 , env ) )) ; 
  (__funcarg36 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (thread_set_p , "thread-group?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("thread-group?" , __funcarg36 , env ) )) ; 
  (__funcarg35 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (make_thread_set , "make-thread-group" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-thread-group" , __funcarg35 , env ) )) ; 
  (__funcarg34 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (current_thread_set , "current-thread-group" , MZCONFIG_THREAD_SET ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-thread-group" , __funcarg34 , env ) )) ; 
  (__funcarg33 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (parameter_p , "parameter?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("parameter?" , __funcarg33 , env ) )) ; 
  (__funcarg32 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (make_parameter , "make-parameter" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-parameter" , __funcarg32 , env ) )) ; 
  (__funcarg31 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (make_derived_parameter , "make-derived-parameter" , 3 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-derived-parameter" , __funcarg31 , env ) )) ; 
  (__funcarg30 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (parameter_procedure_eq , "parameter-procedure=?" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("parameter-procedure=?" , __funcarg30 , env ) )) ; 
  (__funcarg29 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (parameterization_p , "parameterization?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("parameterization?" , __funcarg29 , env ) )) ; 
  (__funcarg28 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (thread_cell_p , "thread-cell?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("thread-cell?" , __funcarg28 , env ) )) ; 
  (__funcarg27 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (make_thread_cell , "make-thread-cell" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-thread-cell" , __funcarg27 , env ) )) ; 
  (__funcarg26 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (thread_cell_get , "thread-cell-ref" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("thread-cell-ref" , __funcarg26 , env ) )) ; 
  (__funcarg25 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (thread_cell_set , "thread-cell-set!" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("thread-cell-set!" , __funcarg25 , env ) )) ; 
  (__funcarg24 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (thread_cell_values , "current-preserved-thread-cell-values" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-preserved-thread-cell-values" , __funcarg24 , env ) )) ; 
  (__funcarg23 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (make_will_executor , "make-will-executor" , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-will-executor" , __funcarg23 , env ) )) ; 
  (__funcarg22 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (will_executor_p , "will-executor?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("will-executor?" , __funcarg22 , env ) )) ; 
  (__funcarg21 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (register_will , "will-register" , 3 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("will-register" , __funcarg21 , env ) )) ; 
  (__funcarg20 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (will_executor_try , "will-try-execute" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("will-try-execute" , __funcarg20 , env ) )) ; 
  (__funcarg19 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (will_executor_go , "will-execute" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("will-execute" , __funcarg19 , env ) )) ; 
  FUNCCALL_AGAIN(scheme_add_evt_through_sema (scheme_will_executor_type , will_executor_sema , ((void * ) 0 ) ) ); 
  (__funcarg18 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (collect_garbage , "collect-garbage" , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("collect-garbage" , __funcarg18 , env ) )) ; 
  (__funcarg17 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (current_memory_use , "current-memory-use" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-memory-use" , __funcarg17 , env ) )) ; 
  (__funcarg16 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (custodian_require_mem , "custodian-require-memory" , 3 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("custodian-require-memory" , __funcarg16 , env ) )) ; 
  (__funcarg15 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (custodian_limit_mem , "custodian-limit-memory" , 2 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("custodian-limit-memory" , __funcarg15 , env ) )) ; 
  (__funcarg14 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (custodian_can_mem , "custodian-memory-accounting-available?" , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("custodian-memory-accounting-available?" , __funcarg14 , env ) )) ; 
  (__funcarg13 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_folding_prim (evt_p , "evt?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("evt?" , __funcarg13 , env ) )) ; 
  (__funcarg12 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_everything (sch_sync , 0 , "sync" , 1 , - 1 , 0 , 0 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("sync" , __funcarg12 , env ) )) ; 
  (__funcarg11 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_everything (sch_sync_timeout , 0 , "sync/timeout" , 2 , - 1 , 0 , 0 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("sync/timeout" , __funcarg11 , env ) )) ; 
  (__funcarg10 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_everything (sch_sync_enable_break , 0 , "sync/enable-break" , 1 , - 1 , 0 , 0 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("sync/enable-break" , __funcarg10 , env ) )) ; 
  (__funcarg9 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_everything (sch_sync_timeout_enable_break , 0 , "sync/timeout/enable-break" , 2 , - 1 , 0 , 0 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("sync/timeout/enable-break" , __funcarg9 , env ) )) ; 
  (__funcarg8 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (evts_to_evt , "choice-evt" , 0 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("choice-evt" , __funcarg8 , env ) )) ; 
  (__funcarg7 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (current_thread_initial_stack_size , "current-thread-initial-stack-size" , MZCONFIG_THREAD_INIT_STACK_SIZE ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-thread-initial-stack-size" , __funcarg7 , env ) )) ; 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & namespace_options , sizeof (namespace_options ) ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & empty_symbol , sizeof (empty_symbol ) ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & initial_symbol , sizeof (initial_symbol ) ) ); 
  empty_symbol = FUNCCALL_EMPTY(scheme_intern_symbol ("empty" ) ); 
  initial_symbol = FUNCCALL_EMPTY(scheme_intern_symbol ("initial" ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_init_memtrace (Scheme_Env * env ) {
  Scheme_Object * v ; 
  Scheme_Env * newenv ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(newenv, 0), PUSH(v, 1), PUSH(env, 2)));
# define XfOrM3_COUNT (3)
# define SETUP_XfOrM3(x) SETUP(XfOrM3_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  newenv = NULLED_OUT ; 
  v = FUNCCALL(SETUP_XfOrM3(_), scheme_intern_symbol ("#%memtrace" ) ); 
  newenv = FUNCCALL_AGAIN(scheme_primitive_module (v , env ) ); 
  mtrace_cmark_key = FUNCCALL_AGAIN(scheme_make_symbol ("memory-trace-continuation-mark" ) ); 
  FUNCCALL_AGAIN(scheme_add_global ("memory-trace-continuation-mark" , mtrace_cmark_key , newenv ) ); 
  v = FUNCCALL_AGAIN(scheme_make_prim_w_arity (new_tracking_fun , "new-memtrace-tracking-function" , 1 , 1 ) ); 
  FUNCCALL_AGAIN(scheme_add_global ("new-memtrace-tracking-function" , v , newenv ) ); 
  v = FUNCCALL_AGAIN(scheme_make_prim_w_arity (union_tracking_val , "unioned-memtrace-tracking-value" , 1 , 1 ) ); 
  FUNCCALL_AGAIN(scheme_add_global ("unioned-memtrace-tracking-value" , v , newenv ) ); 
  FUNCCALL_EMPTY(scheme_finish_primitive_module (newenv ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_init_parameterization (Scheme_Env * env ) {
  Scheme_Object * v ; 
  Scheme_Env * newenv ; 
  Scheme_Object * __funcarg70 = NULLED_OUT ; 
  Scheme_Object * __funcarg69 = NULLED_OUT ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(newenv, 0), PUSH(v, 1), PUSH(env, 2)));
# define XfOrM4_COUNT (3)
# define SETUP_XfOrM4(x) SETUP(XfOrM4_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  newenv = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM4(_), scheme_register_static ((void * ) & scheme_exn_handler_key , sizeof (scheme_exn_handler_key ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_parameterization_key , sizeof (scheme_parameterization_key ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_break_enabled_key , sizeof (scheme_break_enabled_key ) ) ); 
  scheme_exn_handler_key = FUNCCALL_AGAIN(scheme_make_symbol ("exnh" ) ); 
  scheme_parameterization_key = FUNCCALL_AGAIN(scheme_make_symbol ("paramz" ) ); 
  scheme_break_enabled_key = FUNCCALL_AGAIN(scheme_make_symbol ("break-on?" ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & recycle_cell , sizeof (recycle_cell ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & maybe_recycle_cell , sizeof (maybe_recycle_cell ) ) ); 
  v = FUNCCALL_AGAIN(scheme_intern_symbol ("#%paramz" ) ); 
  newenv = FUNCCALL_AGAIN(scheme_primitive_module (v , env ) ); 
  FUNCCALL_AGAIN(scheme_add_global_constant ("exception-handler-key" , scheme_exn_handler_key , newenv ) ); 
  FUNCCALL_AGAIN(scheme_add_global_constant ("parameterization-key" , scheme_parameterization_key , newenv ) ); 
  FUNCCALL_AGAIN(scheme_add_global_constant ("break-enabled-key" , scheme_break_enabled_key , newenv ) ); 
  (__funcarg70 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_arity (extend_parameterization , "extend-parameterization" , 1 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("extend-parameterization" , __funcarg70 , newenv ) )) ; 
  (__funcarg69 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_arity (check_break_now , "check-for-break" , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("check-for-break" , __funcarg69 , newenv ) )) ; 
  FUNCCALL_AGAIN(scheme_finish_primitive_module (newenv ) ); 
  FUNCCALL_EMPTY(scheme_protect_primitive_provide (newenv , ((void * ) 0 ) ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * collect_garbage (int c , Scheme_Object * p [] ) {
  /* No conversion */
  scheme_collect_garbage () ; 
  return scheme_void ; 
}
static Scheme_Object * current_memory_use (int argc , Scheme_Object * args [] ) {
  /* No conversion */
  Scheme_Object * arg = ((void * ) 0 ) ; 
  long retval = 0 ; 
  if (argc ) {
    if (((Scheme_Type ) (((((long ) (args [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_custodian_type ) ) ) {
      arg = args [0 ] ; 
    }
    else if ((! (((long ) (args [0 ] ) ) & 0x1 ) && ((((args [0 ] ) -> type ) >= scheme_prim_type ) && (((args [0 ] ) -> type ) <= scheme_native_closure_type ) ) ) ) {
      arg = args [0 ] ; 
    }
    else {
      scheme_wrong_type ("current-memory-use" , "custodian or memory-trace-function" , 0 , argc , args ) ; 
    }
  }
  retval = GC_get_memory_use (arg ) ; 
  return scheme_make_integer_value (retval ) ; 
}
static Scheme_Object * custodian_require_mem (int argc , Scheme_Object * args [] ) {
  /* No conversion */
  long lim ; 
  Scheme_Custodian * c1 , * c2 , * cx ; 
  if (((Scheme_Type ) (((((long ) (args [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args [0 ] ) ) -> type ) ) != (Scheme_Type ) (scheme_custodian_type ) ) ) {
    scheme_wrong_type ("custodian-require-memory" , "custodian" , 0 , argc , args ) ; 
    return ((void * ) 0 ) ; 
  }
  if ((((long ) (args [1 ] ) ) & 0x1 ) && ((((long ) (args [1 ] ) ) >> 1 ) > 0 ) ) {
    lim = (((long ) (args [1 ] ) ) >> 1 ) ; 
  }
  else if (((Scheme_Type ) (((((long ) (args [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) && ((& ((Scheme_Bignum * ) args [1 ] ) -> iso ) -> so . keyex & 0x1 ) ) {
    lim = 0x3fffffff ; 
  }
  else {
    scheme_wrong_type ("custodian-require-memory" , "positive exact integer" , 1 , argc , args ) ; 
    return ((void * ) 0 ) ; 
  }
  if (((Scheme_Type ) (((((long ) (args [2 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args [2 ] ) ) -> type ) ) != (Scheme_Type ) (scheme_custodian_type ) ) ) {
    scheme_wrong_type ("custodian-require-memory" , "custodian" , 2 , argc , args ) ; 
    return ((void * ) 0 ) ; 
  }
  c1 = (Scheme_Custodian * ) args [0 ] ; 
  c2 = (Scheme_Custodian * ) args [2 ] ; 
  if (c1 == c2 ) {
    cx = ((void * ) 0 ) ; 
  }
  else {
    for (cx = c2 ; cx && ((cx ) != (c1 ) ) ; ) {
      cx = ((Scheme_Custodian_Weak_Box * ) cx -> parent ) -> val ; 
    }
  }
  if (! cx ) {
    scheme_raise_exn (MZEXN_FAIL_CONTRACT , "custodian-require-memory: second custodian is not a sub-custodian of the first custodian" ) ; 
  }
  if (GC_set_account_hook (0 , c1 , lim , c2 ) )
    return scheme_void ; 
  scheme_raise_exn (MZEXN_FAIL_UNSUPPORTED , "custodian-require-memory: not supported" ) ; 
  return ((void * ) 0 ) ; 
}
static Scheme_Object * custodian_limit_mem (int argc , Scheme_Object * args [] ) {
  long lim ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(args, 0)));
# define XfOrM22_COUNT (1)
# define SETUP_XfOrM22(x) SETUP(XfOrM22_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (((Scheme_Type ) (((((long ) (args [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args [0 ] ) ) -> type ) ) != (Scheme_Type ) (scheme_custodian_type ) ) ) {
#   define XfOrM29_COUNT (0+XfOrM22_COUNT)
#   define SETUP_XfOrM29(x) SETUP_XfOrM22(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("custodian-limit-memory" , "custodian" , 0 , argc , args ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if ((((long ) (args [1 ] ) ) & 0x1 ) && ((((long ) (args [1 ] ) ) >> 1 ) > 0 ) ) {
    lim = (((long ) (args [1 ] ) ) >> 1 ) ; 
  }
  else if (((Scheme_Type ) (((((long ) (args [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) && ((& ((Scheme_Bignum * ) args [1 ] ) -> iso ) -> so . keyex & 0x1 ) ) {
    lim = 0x3fffffff ; 
  }
  else {
#   define XfOrM26_COUNT (0+XfOrM22_COUNT)
#   define SETUP_XfOrM26(x) SETUP_XfOrM22(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("custodian-limit-memory" , "positive exact integer" , 1 , argc , args ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (argc > 2 ) {
#   define XfOrM24_COUNT (0+XfOrM22_COUNT)
#   define SETUP_XfOrM24(x) SETUP_XfOrM22(x)
    if (((Scheme_Type ) (((((long ) (args [2 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args [2 ] ) ) -> type ) ) != (Scheme_Type ) (scheme_custodian_type ) ) ) {
#     define XfOrM25_COUNT (0+XfOrM24_COUNT)
#     define SETUP_XfOrM25(x) SETUP_XfOrM24(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("custodian-require-memory" , "custodian" , 2 , argc , args ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  if (! limited_custodians )
    limited_custodians = FUNCCALL(SETUP_XfOrM22(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  FUNCCALL(SETUP_XfOrM22(_), scheme_hash_set (limited_custodians , args [0 ] , scheme_true ) ); 
  ((Scheme_Custodian * ) args [0 ] ) -> has_limit = 1 ; 
  if (argc > 2 ) {
#   define XfOrM23_COUNT (0+XfOrM22_COUNT)
#   define SETUP_XfOrM23(x) SETUP_XfOrM22(x)
    FUNCCALL(SETUP_XfOrM23(_), scheme_hash_set (limited_custodians , args [2 ] , scheme_true ) ); 
    ((Scheme_Custodian * ) args [2 ] ) -> has_limit = 1 ; 
  }
  if (FUNCCALL_EMPTY(GC_set_account_hook (1 , args [0 ] , lim , (argc > 2 ) ? args [2 ] : args [0 ] ) ))
    RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
  FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_UNSUPPORTED , "custodian-limit-memory: not supported" ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * custodian_can_mem (int argc , Scheme_Object * args [] ) {
  /* No conversion */
  return scheme_true ; 
}
static Scheme_Object * new_tracking_fun (int argc , Scheme_Object * args [] ) {
  /* No conversion */
  int retval = 0 ; 
  retval = GC_mtrace_new_id (args [0 ] ) ; 
  return ((Scheme_Object * ) (void * ) (long ) ((((long ) (retval ) ) << 1 ) | 0x1 ) ) ; 
}
static Scheme_Object * union_tracking_val (int argc , Scheme_Object * args [] ) {
  /* No conversion */
  int retval = 0 ; 
  retval = GC_mtrace_union_current_with ((((long ) (args [0 ] ) ) >> 1 ) ) ; 
  return ((Scheme_Object * ) (void * ) (long ) ((((long ) (retval ) ) << 1 ) | 0x1 ) ) ; 
}
static void ensure_custodian_space (Scheme_Custodian * m , int k ) {
  int i ; 
  PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(m, 0)));
# define XfOrM33_COUNT (1)
# define SETUP_XfOrM33(x) SETUP(XfOrM33_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (m -> count + k >= m -> alloc ) {
    Scheme_Object * * * naya_boxes ; 
    Scheme_Custodian_Reference * * naya_mrefs ; 
    Scheme_Close_Custodian_Client * * naya_closers ; 
    void * * naya_data ; 
    BLOCK_SETUP((PUSH(naya_data, 0+XfOrM33_COUNT), PUSH(naya_closers, 1+XfOrM33_COUNT), PUSH(naya_mrefs, 2+XfOrM33_COUNT), PUSH(naya_boxes, 3+XfOrM33_COUNT)));
#   define XfOrM34_COUNT (4+XfOrM33_COUNT)
#   define SETUP_XfOrM34(x) SETUP(XfOrM34_COUNT)
    naya_boxes = NULLED_OUT ; 
    naya_mrefs = NULLED_OUT ; 
    naya_closers = NULLED_OUT ; 
    naya_data = NULLED_OUT ; 
    m -> alloc = (m -> alloc ? (2 * m -> alloc ) : 4 ) ; 
    if (m -> alloc < k )
      m -> alloc += k ; 
    naya_boxes = ((Scheme_Object * * * ) FUNCCALL(SETUP_XfOrM34(_), GC_malloc (sizeof (Scheme_Object * * ) * (m -> alloc ) ) )) ; 
    naya_closers = ((Scheme_Close_Custodian_Client * * ) FUNCCALL(SETUP_XfOrM34(_), GC_malloc (sizeof (Scheme_Close_Custodian_Client * ) * (m -> alloc ) ) )) ; 
    naya_data = ((void * * ) FUNCCALL(SETUP_XfOrM34(_), GC_malloc (sizeof (void * ) * (m -> alloc ) ) )) ; 
    naya_mrefs = ((Scheme_Custodian_Reference * * ) FUNCCALL(SETUP_XfOrM34(_), GC_malloc (sizeof (Scheme_Custodian_Reference * ) * (m -> alloc ) ) )) ; 
    for (i = m -> count ; i -- ; ) {
      naya_boxes [i ] = m -> boxes [i ] ; 
      m -> boxes [i ] = ((void * ) 0 ) ; 
      naya_closers [i ] = m -> closers [i ] ; 
      m -> closers [i ] = ((void * ) 0 ) ; 
      naya_data [i ] = m -> data [i ] ; 
      m -> data [i ] = ((void * ) 0 ) ; 
      naya_mrefs [i ] = m -> mrefs [i ] ; 
      m -> mrefs [i ] = ((void * ) 0 ) ; 
    }
    m -> boxes = naya_boxes ; 
    m -> closers = naya_closers ; 
    m -> data = naya_data ; 
    m -> mrefs = naya_mrefs ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void add_managed_box (Scheme_Custodian * m , Scheme_Object * * box , Scheme_Custodian_Reference * mref , Scheme_Close_Custodian_Client * f , void * data ) {
  int i ; 
  PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(mref, 0), PUSH(m, 1), PUSH(f, 2), PUSH(data, 3), PUSH(box, 4)));
# define XfOrM37_COUNT (5)
# define SETUP_XfOrM37(x) SETUP(XfOrM37_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  for (i = m -> count ; i -- ; ) {
    if (! m -> boxes [i ] ) {
      m -> boxes [i ] = box ; 
      m -> closers [i ] = f ; 
      m -> data [i ] = data ; 
      m -> mrefs [i ] = mref ; 
      RET_NOTHING ; 
    }
  }
  FUNCCALL(SETUP_XfOrM37(_), ensure_custodian_space (m , 1 ) ); 
  m -> boxes [m -> count ] = box ; 
  m -> closers [m -> count ] = f ; 
  m -> data [m -> count ] = data ; 
  m -> mrefs [m -> count ] = mref ; 
  m -> count ++ ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void remove_managed (Scheme_Custodian_Reference * mr , Scheme_Object * o , Scheme_Close_Custodian_Client * * old_f , void * * old_data ) {
  /* No conversion */
  Scheme_Custodian * m ; 
  int i ; 
  if (! mr )
    return ; 
  m = ((Scheme_Custodian_Weak_Box * ) mr ) -> val ; 
  if (! m )
    return ; 
  for (i = m -> count ; i -- ; ) {
    if (m -> boxes [i ] && ((((((Scheme_Small_Object * ) (m -> boxes [i ] ) ) -> u . ptr_val ) ) ) == (o ) ) ) {
      (((Scheme_Small_Object * ) (m -> boxes [i ] ) ) -> u . ptr_val ) = 0 ; 
      m -> boxes [i ] = ((void * ) 0 ) ; 
      ((Scheme_Custodian_Weak_Box * ) m -> mrefs [i ] ) -> val = 0 ; 
      m -> mrefs [i ] = ((void * ) 0 ) ; 
      if (old_f )
        * old_f = m -> closers [i ] ; 
      if (old_data )
        * old_data = m -> data [i ] ; 
      m -> data [i ] = ((void * ) 0 ) ; 
      break ; 
    }
  }
  while (m -> count && ! m -> boxes [m -> count - 1 ] ) {
    -- m -> count ; 
  }
}
static void adjust_custodian_family (void * mgr , void * skip_move ) {
  Scheme_Custodian * r = (Scheme_Custodian * ) mgr , * parent , * m ; 
  int i ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(skip_move, 0), PUSH(r, 1), PUSH(parent, 2)));
# define XfOrM49_COUNT (3)
# define SETUP_XfOrM49(x) SETUP(XfOrM49_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  parent = NULLED_OUT ; 
  m = NULLED_OUT ; 
  parent = ((Scheme_Custodian_Weak_Box * ) r -> parent ) -> val ; 
  if (parent ) {
#   define XfOrM50_COUNT (0+XfOrM49_COUNT)
#   define SETUP_XfOrM50(x) SETUP_XfOrM49(x)
    if (((Scheme_Custodian_Weak_Box * ) parent -> children ) -> val == r ) {
      ((Scheme_Custodian_Weak_Box * ) parent -> children ) -> val = ((Scheme_Custodian_Weak_Box * ) r -> sibling ) -> val ; 
    }
    else {
      m = ((Scheme_Custodian_Weak_Box * ) parent -> children ) -> val ; 
      while (m && ((Scheme_Custodian_Weak_Box * ) m -> sibling ) -> val != r ) {
        m = ((Scheme_Custodian_Weak_Box * ) m -> sibling ) -> val ; 
      }
      if (m )
        ((Scheme_Custodian_Weak_Box * ) m -> sibling ) -> val = ((Scheme_Custodian_Weak_Box * ) r -> sibling ) -> val ; 
    }
    if (((Scheme_Custodian_Weak_Box * ) r -> global_next ) -> val )
      ((Scheme_Custodian_Weak_Box * ) ((Scheme_Custodian_Weak_Box * ) r -> global_next ) -> val -> global_prev ) -> val = ((Scheme_Custodian_Weak_Box * ) r -> global_prev ) -> val ; 
    else last_custodian = ((Scheme_Custodian_Weak_Box * ) r -> global_prev ) -> val ; 
    ((Scheme_Custodian_Weak_Box * ) ((Scheme_Custodian_Weak_Box * ) r -> global_prev ) -> val -> global_next ) -> val = ((Scheme_Custodian_Weak_Box * ) r -> global_next ) -> val ; 
    for (m = ((Scheme_Custodian_Weak_Box * ) r -> children ) -> val ; m ; ) {
      Scheme_Custodian * next = ((Scheme_Custodian_Weak_Box * ) m -> sibling ) -> val ; 
      ((Scheme_Custodian_Weak_Box * ) m -> parent ) -> val = parent ; 
      ((Scheme_Custodian_Weak_Box * ) m -> sibling ) -> val = ((Scheme_Custodian_Weak_Box * ) parent -> children ) -> val ; 
      ((Scheme_Custodian_Weak_Box * ) parent -> children ) -> val = m ; 
      m = next ; 
    }
    if (! skip_move ) {
#     define XfOrM51_COUNT (0+XfOrM50_COUNT)
#     define SETUP_XfOrM51(x) SETUP_XfOrM50(x)
      for (i = 0 ; i < r -> count ; i ++ ) {
#       define XfOrM56_COUNT (0+XfOrM51_COUNT)
#       define SETUP_XfOrM56(x) SETUP_XfOrM51(x)
        if (r -> boxes [i ] ) {
#         define XfOrM57_COUNT (0+XfOrM56_COUNT)
#         define SETUP_XfOrM57(x) SETUP_XfOrM56(x)
          ((Scheme_Custodian_Weak_Box * ) r -> mrefs [i ] ) -> val = parent ; 
          FUNCCALL(SETUP_XfOrM57(_), add_managed_box (parent , r -> boxes [i ] , r -> mrefs [i ] , r -> closers [i ] , r -> data [i ] ) ); 
          {
            Scheme_Object * o ; 
#           define XfOrM58_COUNT (0+XfOrM57_COUNT)
#           define SETUP_XfOrM58(x) SETUP_XfOrM57(x)
            o = NULLED_OUT ; 
            o = (((Scheme_Small_Object * ) (r -> boxes [i ] ) ) -> u . ptr_val ) ; 
            if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_hop_type ) ) ) {
#             define XfOrM59_COUNT (0+XfOrM58_COUNT)
#             define SETUP_XfOrM59(x) SETUP_XfOrM58(x)
              o = (((Scheme_Small_Object * ) (((Scheme_Thread_Custodian_Hop * ) o ) -> p ) ) -> u . ptr_val ) ; 
              if (o )
                FUNCCALL(SETUP_XfOrM59(_), GC_register_thread (o , parent ) ); 
            }
          }
        }
      }
    }
  }
  ((Scheme_Custodian_Weak_Box * ) r -> parent ) -> val = ((void * ) 0 ) ; 
  ((Scheme_Custodian_Weak_Box * ) r -> sibling ) -> val = ((void * ) 0 ) ; 
  if (! skip_move )
    ((Scheme_Custodian_Weak_Box * ) r -> children ) -> val = ((void * ) 0 ) ; 
  ((Scheme_Custodian_Weak_Box * ) r -> global_prev ) -> val = ((void * ) 0 ) ; 
  ((Scheme_Custodian_Weak_Box * ) r -> global_next ) -> val = ((void * ) 0 ) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void insert_custodian (Scheme_Custodian * m , Scheme_Custodian * parent ) {
  /* No conversion */
  ((Scheme_Custodian_Weak_Box * ) m -> parent ) -> val = parent ; 
  if (parent ) {
    ((Scheme_Custodian_Weak_Box * ) m -> sibling ) -> val = ((Scheme_Custodian_Weak_Box * ) parent -> children ) -> val ; 
    ((Scheme_Custodian_Weak_Box * ) parent -> children ) -> val = m ; 
  }
  else ((Scheme_Custodian_Weak_Box * ) m -> sibling ) -> val = ((void * ) 0 ) ; 
  if (parent ) {
    Scheme_Custodian * next ; 
    next = ((Scheme_Custodian_Weak_Box * ) parent -> global_next ) -> val ; 
    ((Scheme_Custodian_Weak_Box * ) m -> global_next ) -> val = next ; 
    ((Scheme_Custodian_Weak_Box * ) m -> global_prev ) -> val = parent ; 
    ((Scheme_Custodian_Weak_Box * ) parent -> global_next ) -> val = m ; 
    if (next )
      ((Scheme_Custodian_Weak_Box * ) next -> global_prev ) -> val = m ; 
    else last_custodian = m ; 
  }
  else {
    ((Scheme_Custodian_Weak_Box * ) m -> global_next ) -> val = ((void * ) 0 ) ; 
    ((Scheme_Custodian_Weak_Box * ) m -> global_prev ) -> val = ((void * ) 0 ) ; 
  }
}
Scheme_Custodian * scheme_make_custodian (Scheme_Custodian * parent ) {
  Scheme_Custodian * m ; 
  Scheme_Custodian_Reference * mw ; 
  DECL_RET_SAVE (Scheme_Custodian * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(m, 0), PUSH(mw, 1), PUSH(parent, 2)));
# define XfOrM70_COUNT (3)
# define SETUP_XfOrM70(x) SETUP(XfOrM70_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  m = NULLED_OUT ; 
  mw = NULLED_OUT ; 
  if (! parent )
    parent = main_custodian ; 
  m = ((Scheme_Custodian * ) FUNCCALL(SETUP_XfOrM70(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Custodian ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  m -> so . type = scheme_custodian_type ; 
  m -> alloc = m -> count = 0 ; 
  mw = (Scheme_Custodian_Reference * ) FUNCCALL(SETUP_XfOrM70(_), scheme_make_weak_box (((void * ) 0 ) ) ); 
  m -> parent = mw ; 
  mw = (Scheme_Custodian_Reference * ) FUNCCALL(SETUP_XfOrM70(_), scheme_make_weak_box (((void * ) 0 ) ) ); 
  m -> children = mw ; 
  mw = (Scheme_Custodian_Reference * ) FUNCCALL(SETUP_XfOrM70(_), scheme_make_weak_box (((void * ) 0 ) ) ); 
  m -> sibling = mw ; 
  mw = (Scheme_Custodian_Reference * ) FUNCCALL(SETUP_XfOrM70(_), scheme_make_weak_box (((void * ) 0 ) ) ); 
  m -> global_next = mw ; 
  mw = (Scheme_Custodian_Reference * ) FUNCCALL(SETUP_XfOrM70(_), scheme_make_weak_box (((void * ) 0 ) ) ); 
  m -> global_prev = mw ; 
  ((Scheme_Custodian_Weak_Box * ) m -> children ) -> val = ((void * ) 0 ) ; 
  FUNCCALL(SETUP_XfOrM70(_), insert_custodian (m , parent ) ); 
  FUNCCALL_AGAIN(scheme_add_finalizer (m , adjust_custodian_family , ((void * ) 0 ) ) ); 
  RET_VALUE_START (m ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void rebox_willdone_object (void * o , void * mr ) {
  Scheme_Custodian * m = ((Scheme_Custodian_Weak_Box * ) (Scheme_Custodian_Reference * ) mr ) -> val ; 
  Scheme_Close_Custodian_Client * f ; 
  void * data ; 
  PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(m, 0), PUSH(mr, 1), PUSH(f, 2), PUSH(data, 3), PUSH(o, 4)));
# define XfOrM71_COUNT (5)
# define SETUP_XfOrM71(x) SETUP(XfOrM71_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  f = NULLED_OUT ; 
  data = NULLED_OUT ; 
  if (m ) {
    Scheme_Object * b ; 
    BLOCK_SETUP((PUSH(b, 0+XfOrM71_COUNT)));
#   define XfOrM72_COUNT (1+XfOrM71_COUNT)
#   define SETUP_XfOrM72(x) SETUP(XfOrM72_COUNT)
    b = NULLED_OUT ; 
    FUNCCALL(SETUP_XfOrM72(_), remove_managed (mr , o , & f , & data ) ); 
    b = FUNCCALL_AGAIN(scheme_box (((void * ) 0 ) ) ); 
    (((Scheme_Small_Object * ) (b ) ) -> u . ptr_val ) = o ; 
    ((Scheme_Custodian_Weak_Box * ) (Scheme_Custodian_Reference * ) mr ) -> val = m ; 
    FUNCCALL(SETUP_XfOrM72(_), add_managed_box (m , (Scheme_Object * * ) b , (Scheme_Custodian_Reference * ) mr , f , data ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void managed_object_gone (void * o , void * mr ) {
  /* No conversion */
  Scheme_Custodian * m = ((Scheme_Custodian_Weak_Box * ) (Scheme_Custodian_Reference * ) mr ) -> val ; 
  if (m )
    remove_managed (mr , o , ((void * ) 0 ) , ((void * ) 0 ) ) ; 
}
void scheme_custodian_check_available (Scheme_Custodian * m , const char * who , const char * what ) {
  Scheme_Config * __funcarg71 = NULLED_OUT ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(m, 0), PUSH(who, 1)));
# define XfOrM74_COUNT (2)
# define SETUP_XfOrM74(x) SETUP(XfOrM74_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! m )
    m = (Scheme_Custodian * ) (__funcarg71 = FUNCCALL(SETUP_XfOrM74(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg71 , MZCONFIG_CUSTODIAN ) )) ; 
  if (m -> shut_down ) {
#   define XfOrM75_COUNT (0+XfOrM74_COUNT)
#   define SETUP_XfOrM75(x) SETUP_XfOrM74(x)
    FUNCCALL_EMPTY(scheme_arg_mismatch (who , "the custodian has been shut down: " , (Scheme_Object * ) m ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Custodian_Reference * scheme_add_managed (Scheme_Custodian * m , Scheme_Object * o , Scheme_Close_Custodian_Client * f , void * data , int must_close ) {
  Scheme_Object * b ; 
  Scheme_Custodian_Reference * mr ; 
  Scheme_Config * __funcarg72 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Custodian_Reference * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(m, 0), PUSH(f, 1), PUSH(data, 2), PUSH(b, 3), PUSH(mr, 4), PUSH(o, 5)));
# define XfOrM76_COUNT (6)
# define SETUP_XfOrM76(x) SETUP(XfOrM76_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  b = NULLED_OUT ; 
  mr = NULLED_OUT ; 
  if (! m )
    m = (Scheme_Custodian * ) (__funcarg72 = FUNCCALL(SETUP_XfOrM76(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg72 , MZCONFIG_CUSTODIAN ) )) ; 
  if (m -> shut_down ) {
#   define XfOrM77_COUNT (0+XfOrM76_COUNT)
#   define SETUP_XfOrM77(x) SETUP_XfOrM76(x)
    if (f )
      FUNCCALL(SETUP_XfOrM77(_), f (o , data ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  b = FUNCCALL(SETUP_XfOrM76(_), scheme_make_weak_box (((void * ) 0 ) ) ); 
  (((Scheme_Small_Object * ) (b ) ) -> u . ptr_val ) = o ; 
  mr = (Scheme_Custodian_Reference * ) FUNCCALL(SETUP_XfOrM76(_), scheme_make_weak_box (((void * ) 0 ) ) ); 
  ((Scheme_Custodian_Weak_Box * ) mr ) -> val = m ; 
  if (must_close )
    FUNCCALL(SETUP_XfOrM76(_), scheme_add_finalizer (o , rebox_willdone_object , mr ) ); 
  else FUNCCALL(SETUP_XfOrM76(_), scheme_add_finalizer (o , managed_object_gone , mr ) ); 
  FUNCCALL(SETUP_XfOrM76(_), add_managed_box (m , (Scheme_Object * * ) b , mr , f , data ) ); 
  RET_VALUE_START (mr ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_remove_managed (Scheme_Custodian_Reference * mr , Scheme_Object * o ) {
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(mr, 0), PUSH(o, 1)));
# define XfOrM78_COUNT (2)
# define SETUP_XfOrM78(x) SETUP(XfOrM78_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM78(_), scheme_subtract_finalizer (o , managed_object_gone , mr ) ); 
  FUNCCALL(SETUP_XfOrM78(_), scheme_subtract_finalizer (o , rebox_willdone_object , mr ) ); 
  FUNCCALL_EMPTY(remove_managed (mr , o , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Thread * scheme_do_close_managed (Scheme_Custodian * m , Scheme_Exit_Closer_Func cf ) {
  Scheme_Thread * kill_self = ((void * ) 0 ) ; 
  Scheme_Custodian * c , * start , * next_m ; 
  int i , is_thread ; 
  Scheme_Thread * the_thread ; 
  Scheme_Object * o ; 
  Scheme_Close_Custodian_Client * f ; 
  void * data ; 
  DECL_RET_SAVE (Scheme_Thread * ) PREPARE_VAR_STACK(9);
  BLOCK_SETUP_TOP((PUSH(m, 0), PUSH(data, 1), PUSH(next_m, 2), PUSH(o, 3), PUSH(the_thread, 4), PUSH(f, 5), PUSH(kill_self, 6), PUSH(start, 7)));
# define XfOrM79_COUNT (8)
# define SETUP_XfOrM79(x) SETUP(XfOrM79_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  c = NULLED_OUT ; 
  start = NULLED_OUT ; 
  next_m = NULLED_OUT ; 
  the_thread = NULLED_OUT ; 
  o = NULLED_OUT ; 
  f = NULLED_OUT ; 
  data = NULLED_OUT ; 
  if (! m )
    m = main_custodian ; 
  if (m -> shut_down )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  m -> shut_down = 1 ; 
  for (c = m ; ((Scheme_Custodian_Weak_Box * ) c -> children ) -> val ; ) {
    for (c = ((Scheme_Custodian_Weak_Box * ) c -> children ) -> val ; ((Scheme_Custodian_Weak_Box * ) c -> sibling ) -> val ; ) {
      c = ((Scheme_Custodian_Weak_Box * ) c -> sibling ) -> val ; 
    }
  }
  start = m ; 
  m = c ; 
  while (1 ) {
#   define XfOrM118_COUNT (0+XfOrM79_COUNT)
#   define SETUP_XfOrM118(x) SETUP_XfOrM79(x)
    for (i = m -> count ; i -- ; ) {
#     define XfOrM138_COUNT (0+XfOrM118_COUNT)
#     define SETUP_XfOrM138(x) SETUP_XfOrM118(x)
      if (m -> boxes [i ] ) {
#       define XfOrM139_COUNT (0+XfOrM138_COUNT)
#       define SETUP_XfOrM139(x) SETUP_XfOrM138(x)
        o = (((Scheme_Small_Object * ) (m -> boxes [i ] ) ) -> u . ptr_val ) ; 
        f = m -> closers [i ] ; 
        data = m -> data [i ] ; 
        if (! cf && (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_hop_type ) ) ) ) {
          is_thread = 1 ; 
          the_thread = (Scheme_Thread * ) (((Scheme_Small_Object * ) (((Scheme_Thread_Custodian_Hop * ) o ) -> p ) ) -> u . ptr_val ) ; 
        }
        else {
          is_thread = 0 ; 
          the_thread = ((void * ) 0 ) ; 
        }
        (((Scheme_Small_Object * ) (m -> boxes [i ] ) ) -> u . ptr_val ) = ((void * ) 0 ) ; 
        ((Scheme_Custodian_Weak_Box * ) m -> mrefs [i ] ) -> val = ((void * ) 0 ) ; 
        m -> count = i ; 
        if (is_thread && ! the_thread ) {
        }
        else if (cf ) {
#         define XfOrM152_COUNT (0+XfOrM139_COUNT)
#         define SETUP_XfOrM152(x) SETUP_XfOrM139(x)
          FUNCCALL(SETUP_XfOrM152(_), cf (o , f , data ) ); 
        }
        else {
#         define XfOrM140_COUNT (0+XfOrM139_COUNT)
#         define SETUP_XfOrM140(x) SETUP_XfOrM139(x)
          if (is_thread ) {
#           define XfOrM142_COUNT (0+XfOrM140_COUNT)
#           define SETUP_XfOrM142(x) SETUP_XfOrM140(x)
            if (the_thread ) {
#             define XfOrM143_COUNT (0+XfOrM142_COUNT)
#             define SETUP_XfOrM143(x) SETUP_XfOrM142(x)
              if (((the_thread -> extra_mrefs ) == (scheme_null ) ) ) {
#               define XfOrM151_COUNT (0+XfOrM143_COUNT)
#               define SETUP_XfOrM151(x) SETUP_XfOrM143(x)
                if (FUNCCALL(SETUP_XfOrM151(_), do_kill_thread (the_thread ) ))
                  kill_self = the_thread ; 
              }
              else {
                Scheme_Custodian_Reference * mref ; 
                BLOCK_SETUP((PUSH(mref, 0+XfOrM143_COUNT)));
#               define XfOrM144_COUNT (1+XfOrM143_COUNT)
#               define SETUP_XfOrM144(x) SETUP(XfOrM144_COUNT)
                mref = NULLED_OUT ; 
                mref = m -> mrefs [i ] ; 
                if (mref == the_thread -> mref ) {
#                 define XfOrM150_COUNT (0+XfOrM144_COUNT)
#                 define SETUP_XfOrM150(x) SETUP_XfOrM144(x)
                  mref = (Scheme_Custodian_Reference * ) (((Scheme_Simple_Object * ) (the_thread -> extra_mrefs ) ) -> u . pair_val . car ) ; 
                  the_thread -> mref = mref ; 
                  the_thread -> extra_mrefs = (((Scheme_Simple_Object * ) (the_thread -> extra_mrefs ) ) -> u . pair_val . cdr ) ; 
                  FUNCCALL(SETUP_XfOrM150(_), GC_register_thread (the_thread , ((Scheme_Custodian_Weak_Box * ) mref ) -> val ) ); 
                }
                else {
                  Scheme_Object * l , * prev = ((void * ) 0 ) ; 
                  l = NULLED_OUT ; 
                  for (l = the_thread -> extra_mrefs ; 1 ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
                    if ((((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ) == ((Scheme_Object * ) mref ) ) ) {
                      if (prev )
                        (((Scheme_Simple_Object * ) (prev ) ) -> u . pair_val . cdr ) = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
                      else the_thread -> extra_mrefs = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
                      break ; 
                    }
                    prev = l ; 
                  }
                }
              }
            }
          }
          else {
#           define XfOrM141_COUNT (0+XfOrM140_COUNT)
#           define SETUP_XfOrM141(x) SETUP_XfOrM140(x)
            FUNCCALL(SETUP_XfOrM141(_), f (o , data ) ); 
          }
        }
      }
    }
    m -> count = 0 ; 
    m -> alloc = 0 ; 
    m -> boxes = ((void * ) 0 ) ; 
    m -> closers = ((void * ) 0 ) ; 
    m -> data = ((void * ) 0 ) ; 
    m -> mrefs = ((void * ) 0 ) ; 
    if (((m ) == (start ) ) )
      break ; 
    next_m = ((Scheme_Custodian_Weak_Box * ) m -> global_prev ) -> val ; 
    FUNCCALL(SETUP_XfOrM118(_), adjust_custodian_family (m , m ) ); 
    if (m -> has_limit ) {
#     define XfOrM119_COUNT (0+XfOrM118_COUNT)
#     define SETUP_XfOrM119(x) SETUP_XfOrM118(x)
      FUNCCALL(SETUP_XfOrM119(_), scheme_hash_set (limited_custodians , (Scheme_Object * ) m , ((void * ) 0 ) ) ); 
    }
    m = next_m ; 
  }
  RET_VALUE_START (kill_self ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
typedef void (* Scheme_For_Each_Func ) (Scheme_Object * ) ; 
static void for_each_managed (Scheme_Type type , Scheme_For_Each_Func cf ) {
  Scheme_Custodian * m ; 
  int i ; 
  if (((Scheme_Type ) (type ) == (Scheme_Type ) (scheme_thread_type ) ) )
    type = scheme_thread_hop_type ; 
  m = last_custodian ; 
  while (m ) {
    for (i = m -> count ; i -- ; ) {
      if (m -> boxes [i ] ) {
        Scheme_Object * o ; 
        o = (((Scheme_Small_Object * ) (m -> boxes [i ] ) ) -> u . ptr_val ) ; 
        if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (type ) ) ) {
          if (((Scheme_Type ) (type ) == (Scheme_Type ) (scheme_thread_hop_type ) ) ) {
            Scheme_Thread * t ; 
            t = (Scheme_Thread * ) (((Scheme_Small_Object * ) (((Scheme_Thread_Custodian_Hop * ) o ) -> p ) ) -> u . ptr_val ) ; 
            if (! t ) {
              continue ; 
            }
            else if (((t -> mref ) == (m -> mrefs [i ] ) ) )
              o = (Scheme_Object * ) t ; 
            else {
              continue ; 
            }
          }
          cf (o ) ; 
        }
      }
    }
    m = ((Scheme_Custodian_Weak_Box * ) m -> global_prev ) -> val ; 
  }
}
void scheme_close_managed (Scheme_Custodian * m ) {
  /* No conversion */
  if (scheme_do_close_managed (m , ((void * ) 0 ) ) ) {
    if (scheme_current_thread -> suspend_to_kill )
      suspend_thread (scheme_current_thread ) ; 
    else scheme_thread_block (0.0 ) ; 
  }
  scheme_thread_block (0 ) ; 
  scheme_current_thread -> ran_some = 1 ; 
}
static Scheme_Object * make_custodian (int argc , Scheme_Object * argv [] ) {
  Scheme_Custodian * m ; 
  Scheme_Config * __funcarg73 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(m, 0)));
# define XfOrM164_COUNT (1)
# define SETUP_XfOrM164(x) SETUP(XfOrM164_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  m = NULLED_OUT ; 
  if (argc ) {
#   define XfOrM165_COUNT (0+XfOrM164_COUNT)
#   define SETUP_XfOrM165(x) SETUP_XfOrM164(x)
    if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_custodian_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("make-custodian" , "custodian" , 0 , argc , argv ) ); 
    m = (Scheme_Custodian * ) argv [0 ] ; 
  }
  else m = (Scheme_Custodian * ) (__funcarg73 = FUNCCALL(SETUP_XfOrM164(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg73 , MZCONFIG_CUSTODIAN ) )) ; 
  if (m -> shut_down )
    FUNCCALL(SETUP_XfOrM164(_), scheme_arg_mismatch ("make-custodian" , "the custodian has been shut down: " , (Scheme_Object * ) m ) ); 
  RET_VALUE_START ((Scheme_Object * ) FUNCCALL_EMPTY(scheme_make_custodian (m ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * custodian_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_custodian_type ) ) ? scheme_true : scheme_false ; 
}
static Scheme_Object * custodian_close_all (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_custodian_type ) ) )
    scheme_wrong_type ("custodian-shutdown-all" , "custodian" , 0 , argc , argv ) ; 
  scheme_close_managed ((Scheme_Custodian * ) argv [0 ] ) ; 
  return scheme_void ; 
}
static Scheme_Object * extract_thread (Scheme_Object * o ) {
  /* No conversion */
  return (Scheme_Object * ) (((Scheme_Small_Object * ) (((Scheme_Thread_Custodian_Hop * ) o ) -> p ) ) -> u . ptr_val ) ; 
}
void scheme_add_custodian_extractor (Scheme_Type t , Scheme_Custodian_Extractor e ) {
  /* No conversion */
  if (! extractors ) {
    int n ; 
    n = scheme_num_types () ; 
    scheme_register_static ((void * ) & extractors , sizeof (extractors ) ) ; 
    extractors = ((Scheme_Custodian_Extractor * ) GC_malloc_atomic (sizeof (Scheme_Custodian_Extractor ) * (n ) ) ) ; 
    memset (extractors , 0 , sizeof (Scheme_Custodian_Extractor ) * n ) ; 
    extractors [scheme_thread_hop_type ] = extract_thread ; 
  }
  if (t ) {
    extractors [t ] = e ; 
  }
}
static Scheme_Object * custodian_to_list (int argc , Scheme_Object * argv [] ) {
  Scheme_Custodian * m , * m2 , * c ; 
  Scheme_Object * * hold , * o ; 
  int i , j , cnt , kids ; 
  Scheme_Type type ; 
  Scheme_Custodian_Extractor ex ; 
  PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(hold, 0), PUSH(m, 1), PUSH(c, 2), PUSH(o, 3)));
# define XfOrM172_COUNT (4)
# define SETUP_XfOrM172(x) SETUP(XfOrM172_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  m = NULLED_OUT ; 
  m2 = NULLED_OUT ; 
  c = NULLED_OUT ; 
  hold = NULLED_OUT ; 
  o = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_custodian_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("custodian-managed-list" , "custodian" , 0 , argc , argv ) ); 
  if (! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_custodian_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("custodian-managed-list" , "custodian" , 1 , argc , argv ) ); 
  m = (Scheme_Custodian * ) argv [0 ] ; 
  m2 = (Scheme_Custodian * ) argv [1 ] ; 
  c = ((Scheme_Custodian_Weak_Box * ) m -> parent ) -> val ; 
  while (c && ((m2 ) != (c ) ) ) {
    c = ((Scheme_Custodian_Weak_Box * ) c -> parent ) -> val ; 
  }
  if (! c ) {
#   define XfOrM187_COUNT (0+XfOrM172_COUNT)
#   define SETUP_XfOrM187(x) SETUP_XfOrM172(x)
    FUNCCALL(SETUP_XfOrM187(_), scheme_arg_mismatch ("custodian-managed-list" , "the second custodian does not " "manage the first custodian: " , argv [0 ] ) ); 
  }
  FUNCCALL(SETUP_XfOrM172(_), scheme_add_custodian_extractor (0 , ((void * ) 0 ) ) ); 
  kids = 0 ; 
  for (c = ((Scheme_Custodian_Weak_Box * ) m -> children ) -> val ; c ; c = ((Scheme_Custodian_Weak_Box * ) c -> sibling ) -> val ) {
    kids ++ ; 
  }
  do {
#   define XfOrM184_COUNT (0+XfOrM172_COUNT)
#   define SETUP_XfOrM184(x) SETUP_XfOrM172(x)
    cnt = m -> count ; 
    hold = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM184(_), GC_malloc (sizeof (Scheme_Object * ) * (cnt + kids ) ) )) ; 
  }
  while (cnt < m -> count ) ; 
  for (i = m -> count , j = 0 ; i -- ; ) {
#   define XfOrM179_COUNT (0+XfOrM172_COUNT)
#   define SETUP_XfOrM179(x) SETUP_XfOrM172(x)
    if (m -> boxes [i ] ) {
#     define XfOrM180_COUNT (0+XfOrM179_COUNT)
#     define SETUP_XfOrM180(x) SETUP_XfOrM179(x)
      o = (((Scheme_Small_Object * ) (m -> boxes [i ] ) ) -> u . ptr_val ) ; 
      type = ((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ; 
      ex = extractors [type ] ; 
      if (ex ) {
#       define XfOrM182_COUNT (0+XfOrM180_COUNT)
#       define SETUP_XfOrM182(x) SETUP_XfOrM180(x)
        o = FUNCCALL(SETUP_XfOrM182(_), ex (o ) ); 
      }
      if (o ) {
        hold [j ] = o ; 
        j ++ ; 
      }
    }
  }
  for (c = ((Scheme_Custodian_Weak_Box * ) m -> children ) -> val ; c ; c = ((Scheme_Custodian_Weak_Box * ) c -> sibling ) -> val ) {
    hold [j ] = (Scheme_Object * ) c ; 
    j ++ ; 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_build_list (j , hold ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * current_custodian (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("current-custodian" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_CUSTODIAN ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , custodian_p , "custodian" , 0 ) ; 
}
static Scheme_Object * make_custodian_box (int argc , Scheme_Object * argv [] ) {
  Scheme_Custodian_Box * cb ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(cb, 0), PUSH(argv, 1)));
# define XfOrM191_COUNT (2)
# define SETUP_XfOrM191(x) SETUP(XfOrM191_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  cb = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_custodian_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("make-custodian-box" , "custodian" , 0 , argc , argv ) ); 
  cb = ((Scheme_Custodian_Box * ) FUNCCALL(SETUP_XfOrM191(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Custodian_Box ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  cb -> so . type = scheme_cust_box_type ; 
  cb -> cust = (Scheme_Custodian * ) argv [0 ] ; 
  cb -> v = argv [1 ] ; 
  {
    Scheme_Object * wb , * pr ; 
    BLOCK_SETUP((PUSH(pr, 0+XfOrM191_COUNT), PUSH(wb, 1+XfOrM191_COUNT)));
#   define XfOrM192_COUNT (2+XfOrM191_COUNT)
#   define SETUP_XfOrM192(x) SETUP(XfOrM192_COUNT)
    wb = NULLED_OUT ; 
    pr = NULLED_OUT ; 
    wb = FUNCCALL(SETUP_XfOrM192(_), GC_malloc_weak_box (cb , ((void * ) 0 ) , 0 ) ); 
    pr = FUNCCALL_AGAIN(scheme_make_raw_pair (wb , cb -> cust -> cust_boxes ) ); 
    cb -> cust -> cust_boxes = pr ; 
  }
  RET_VALUE_START ((Scheme_Object * ) cb ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * custodian_box_value (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Custodian_Box * cb ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cust_box_type ) ) )
    scheme_wrong_type ("custodian-box-value" , "custodian-box" , 0 , argc , argv ) ; 
  cb = (Scheme_Custodian_Box * ) argv [0 ] ; 
  if (cb -> cust -> shut_down )
    return scheme_false ; 
  return cb -> v ; 
}
static Scheme_Object * custodian_box_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cust_box_type ) ) )
    return scheme_true ; 
  else return scheme_false ; 
}
static void run_closers (Scheme_Object * o , Scheme_Close_Custodian_Client * f , void * data ) {
  Scheme_Object * l ; 
  PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(f, 1), PUSH(data, 2), PUSH(l, 3)));
# define XfOrM195_COUNT (4)
# define SETUP_XfOrM195(x) SETUP(XfOrM195_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  l = NULLED_OUT ; 
  for (l = closers ; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
    Scheme_Exit_Closer_Func cf ; 
#   define XfOrM197_COUNT (0+XfOrM195_COUNT)
#   define SETUP_XfOrM197(x) SETUP_XfOrM195(x)
    cf = (Scheme_Exit_Closer_Func ) (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
    FUNCCALL(SETUP_XfOrM197(_), cf (o , f , data ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void run_atexit_closers (void ) {
  mz_jmp_buf newbuf , * savebuf ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(savebuf, 0)));
# define XfOrM198_COUNT (1)
# define SETUP_XfOrM198(x) SETUP(XfOrM198_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  savebuf = NULLED_OUT ; 
  savebuf = scheme_current_thread -> error_buf ; 
  scheme_current_thread -> error_buf = & newbuf ; 
  if (! ((newbuf ) . gcvs = (long ) __gc_var_stack__ , (newbuf ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((newbuf ) . jb ) , (_setjmp (((newbuf ) . jb ) -> jb ) ) ) ) ) {
#   define XfOrM199_COUNT (0+XfOrM198_COUNT)
#   define SETUP_XfOrM199(x) SETUP_XfOrM198(x)
    FUNCCALL(SETUP_XfOrM199(_), scheme_do_close_managed (((void * ) 0 ) , run_closers ) ); 
  }
  scheme_current_thread -> error_buf = savebuf ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_add_atexit_closer (Scheme_Exit_Closer_Func f ) {
  /* No conversion */
  if (! closers ) {
    atexit (run_atexit_closers ) ; 
    scheme_register_static ((void * ) & closers , sizeof (closers ) ) ; 
    closers = scheme_null ; 
  }
  closers = scheme_make_raw_pair ((Scheme_Object * ) f , closers ) ; 
}
void scheme_schedule_custodian_close (Scheme_Custodian * c ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(c, 0)));
# define XfOrM202_COUNT (1)
# define SETUP_XfOrM202(x) SETUP(XfOrM202_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! scheduled_kills ) {
#   define XfOrM203_COUNT (0+XfOrM202_COUNT)
#   define SETUP_XfOrM203(x) SETUP_XfOrM202(x)
    FUNCCALL(SETUP_XfOrM203(_), scheme_register_static ((void * ) & scheduled_kills , sizeof (scheduled_kills ) ) ); 
    scheduled_kills = scheme_null ; 
  }
  scheduled_kills = FUNCCALL_EMPTY(scheme_make_pair ((Scheme_Object * ) c , scheduled_kills ) ); 
  scheme_fuel_counter = 0 ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void check_scheduled_kills () {
  PREPARE_VAR_STACK(1);
# define XfOrM204_COUNT (0)
# define SETUP_XfOrM204(x) SETUP(XfOrM204_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  while (scheduled_kills && ! ((scheduled_kills ) == (scheme_null ) ) ) {
    Scheme_Object * k ; 
    BLOCK_SETUP((PUSH(k, 0+XfOrM204_COUNT)));
#   define XfOrM206_COUNT (1+XfOrM204_COUNT)
#   define SETUP_XfOrM206(x) SETUP(XfOrM206_COUNT)
    k = NULLED_OUT ; 
    k = (((Scheme_Simple_Object * ) (scheduled_kills ) ) -> u . pair_val . car ) ; 
    scheduled_kills = (((Scheme_Simple_Object * ) (scheduled_kills ) ) -> u . pair_val . cdr ) ; 
    FUNCCALL(SETUP_XfOrM206(_), scheme_close_managed ((Scheme_Custodian * ) k ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void check_current_custodian_allows (const char * who , Scheme_Thread * p ) {
  Scheme_Object * l ; 
  Scheme_Custodian_Reference * mref ; 
  Scheme_Custodian * m , * current ; 
  Scheme_Config * __funcarg74 = NULLED_OUT ; 
  PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(m, 0), PUSH(mref, 1), PUSH(current, 2), PUSH(l, 3), PUSH(p, 4), PUSH(who, 5)));
# define XfOrM207_COUNT (6)
# define SETUP_XfOrM207(x) SETUP(XfOrM207_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  l = NULLED_OUT ; 
  mref = NULLED_OUT ; 
  m = NULLED_OUT ; 
  current = NULLED_OUT ; 
  current = (Scheme_Custodian * ) (__funcarg74 = FUNCCALL(SETUP_XfOrM207(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg74 , MZCONFIG_CUSTODIAN ) )) ; 
  for (l = p -> extra_mrefs ; ! ((l ) == (scheme_null ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
    mref = (Scheme_Custodian_Reference * ) (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
    m = ((Scheme_Custodian_Weak_Box * ) mref ) -> val ; 
    while (((m ) != (current ) ) ) {
      m = ((Scheme_Custodian_Weak_Box * ) m -> parent ) -> val ; 
      if (! m )
        goto bad ; 
    }
  }
  mref = p -> mref ; 
  if (! mref )
    RET_NOTHING ; 
  m = ((Scheme_Custodian_Weak_Box * ) mref ) -> val ; 
  if (! m )
    RET_NOTHING ; 
  while (((m ) != (current ) ) ) {
    m = ((Scheme_Custodian_Weak_Box * ) m -> parent ) -> val ; 
    if (! m )
      goto bad ; 
  }
  RET_NOTHING ; 
  bad : FUNCCALL_EMPTY(scheme_arg_mismatch (who , "the current custodian does not " "solely manage the specified thread: " , (Scheme_Object * ) p ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Thread_Set * create_thread_set (Scheme_Thread_Set * parent ) {
  Scheme_Thread_Set * t_set ; 
  DECL_RET_SAVE (Scheme_Thread_Set * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(t_set, 0), PUSH(parent, 1)));
# define XfOrM216_COUNT (2)
# define SETUP_XfOrM216(x) SETUP(XfOrM216_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  t_set = NULLED_OUT ; 
  t_set = ((Scheme_Thread_Set * ) FUNCCALL(SETUP_XfOrM216(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Thread_Set ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  t_set -> so . type = scheme_thread_set_type ; 
  t_set -> parent = parent ; 
  RET_VALUE_START (t_set ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_thread_set (int argc , Scheme_Object * argv [] ) {
  Scheme_Thread_Set * parent ; 
  Scheme_Config * __funcarg75 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(parent, 0)));
# define XfOrM217_COUNT (1)
# define SETUP_XfOrM217(x) SETUP(XfOrM217_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  parent = NULLED_OUT ; 
  if (argc ) {
#   define XfOrM218_COUNT (0+XfOrM217_COUNT)
#   define SETUP_XfOrM218(x) SETUP_XfOrM217(x)
    if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_set_type ) ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("make-thread-group" , "thread-group" , 0 , argc , argv ) ); 
    parent = (Scheme_Thread_Set * ) argv [0 ] ; 
  }
  else parent = (Scheme_Thread_Set * ) (__funcarg75 = FUNCCALL(SETUP_XfOrM217(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg75 , MZCONFIG_THREAD_SET ) )) ; 
  RET_VALUE_START ((Scheme_Object * ) FUNCCALL_EMPTY(create_thread_set (parent ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * thread_set_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_set_type ) ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * current_thread_set (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("current-thread-group" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_THREAD_SET ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , thread_set_p , "thread-group" , 0 ) ; 
}
static inline void set_t_set_next (Scheme_Object * o , Scheme_Object * n ) {
  /* No conversion */
  if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_type ) ) )
    ((Scheme_Thread * ) o ) -> t_set_next = n ; 
  else ((Scheme_Thread_Set * ) o ) -> next = n ; 
}
static inline void set_t_set_prev (Scheme_Object * o , Scheme_Object * n ) {
  /* No conversion */
  if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_type ) ) )
    ((Scheme_Thread * ) o ) -> t_set_prev = n ; 
  else ((Scheme_Thread_Set * ) o ) -> prev = n ; 
}
static inline Scheme_Object * get_t_set_next (Scheme_Object * o ) {
  /* No conversion */
  if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_type ) ) )
    return ((Scheme_Thread * ) o ) -> t_set_next ; 
  else return ((Scheme_Thread_Set * ) o ) -> next ; 
}
static inline Scheme_Object * get_t_set_prev (Scheme_Object * o ) {
  /* No conversion */
  if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_type ) ) )
    return ((Scheme_Thread * ) o ) -> t_set_prev ; 
  else return ((Scheme_Thread_Set * ) o ) -> prev ; 
}
static void schedule_in_set (Scheme_Object * s , Scheme_Thread_Set * t_set ) {
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(t_set, 0), PUSH(s, 1)));
# define XfOrM225_COUNT (2)
# define SETUP_XfOrM225(x) SETUP(XfOrM225_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  num_running_threads += 1 ; 
  while (1 ) {
#   define XfOrM227_COUNT (0+XfOrM225_COUNT)
#   define SETUP_XfOrM227(x) SETUP_XfOrM225(x)
    FUNCCALL(SETUP_XfOrM227(_), set_t_set_next (s , t_set -> first ) ); 
    if (t_set -> first )
      FUNCCALL(SETUP_XfOrM227(_), set_t_set_prev (t_set -> first , s ) ); 
    t_set -> first = s ; 
    if (t_set -> current )
      break ; 
    t_set -> current = s ; 
    s = (Scheme_Object * ) t_set ; 
    t_set = t_set -> parent ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void unschedule_in_set (Scheme_Object * s , Scheme_Thread_Set * t_set ) {
  Scheme_Object * prev ; 
  Scheme_Object * next ; 
  PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(t_set, 0), PUSH(s, 1), PUSH(next, 2), PUSH(prev, 3)));
# define XfOrM228_COUNT (4)
# define SETUP_XfOrM228(x) SETUP(XfOrM228_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  prev = NULLED_OUT ; 
  next = NULLED_OUT ; 
  num_running_threads -= 1 ; 
  while (1 ) {
#   define XfOrM233_COUNT (0+XfOrM228_COUNT)
#   define SETUP_XfOrM233(x) SETUP_XfOrM228(x)
    prev = FUNCCALL(SETUP_XfOrM233(_), get_t_set_prev (s ) ); 
    next = FUNCCALL(SETUP_XfOrM233(_), get_t_set_next (s ) ); 
    if (! prev )
      t_set -> first = next ; 
    else FUNCCALL(SETUP_XfOrM233(_), set_t_set_next (prev , next ) ); 
    if (next )
      FUNCCALL(SETUP_XfOrM233(_), set_t_set_prev (next , prev ) ); 
    FUNCCALL(SETUP_XfOrM233(_), set_t_set_prev (s , ((void * ) 0 ) ) ); 
    FUNCCALL_AGAIN(set_t_set_next (s , ((void * ) 0 ) ) ); 
    if (t_set -> current == s ) {
      if (next ) {
        t_set -> current = next ; 
      }
      else {
        t_set -> current = t_set -> first ; 
      }
    }
    if (t_set -> current )
      break ; 
    s = (Scheme_Object * ) t_set ; 
    t_set = t_set -> parent ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Thread * make_thread (Scheme_Config * config , Scheme_Thread_Cell_Table * cells , Scheme_Object * init_break_cell , Scheme_Custodian * mgr ) {
  Scheme_Thread * process ; 
  int prefix = 0 ; 
  DECL_RET_SAVE (Scheme_Thread * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(init_break_cell, 0), PUSH(config, 1), PUSH(process, 2), PUSH(mgr, 3), PUSH(cells, 4)));
# define XfOrM237_COUNT (5)
# define SETUP_XfOrM237(x) SETUP(XfOrM237_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  process = NULLED_OUT ; 
  process = ((Scheme_Thread * ) FUNCCALL(SETUP_XfOrM237(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Thread ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  process -> so . type = scheme_thread_type ; 
  process -> stack_start = 0 ; 
  if (! scheme_main_thread ) {
#   define XfOrM252_COUNT (0+XfOrM237_COUNT)
#   define SETUP_XfOrM252(x) SETUP_XfOrM237(x)
    FUNCCALL(SETUP_XfOrM252(_), register_traversers () ); 
    FUNCCALL(SETUP_XfOrM252(_), scheme_register_static ((void * ) & scheme_current_thread , sizeof (scheme_current_thread ) ) ); 
    FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_main_thread , sizeof (scheme_main_thread ) ) ); 
    FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_first_thread , sizeof (scheme_first_thread ) ) ); 
    FUNCCALL_AGAIN(scheme_register_static ((void * ) & thread_swap_callbacks , sizeof (thread_swap_callbacks ) ) ); 
    FUNCCALL_AGAIN(scheme_register_static ((void * ) & swap_target , sizeof (swap_target ) ) ); 
    scheme_current_thread = process ; 
    scheme_first_thread = scheme_main_thread = process ; 
    process -> prev = ((void * ) 0 ) ; 
    process -> next = ((void * ) 0 ) ; 
    process -> error_buf = & main_init_error_buf ; 
    thread_swap_callbacks = scheme_null ; 
    GC_collect_start_callback = get_ready_for_GC ; 
    GC_collect_end_callback = done_with_GC ; 
    {
      void * ss ; 
      BLOCK_SETUP((PUSH(ss, 0+XfOrM252_COUNT)));
#     define XfOrM253_COUNT (1+XfOrM252_COUNT)
#     define SETUP_XfOrM253(x) SETUP(XfOrM253_COUNT)
      ss = NULLED_OUT ; 
      ss = (void * ) FUNCCALL(SETUP_XfOrM253(_), GC_get_stack_base () ); 
      process -> stack_start = ss ; 
    }
    GC_get_thread_stack_base = get_current_stack_start ; 
  }
  else {
    prefix = 1 ; 
  }
  process -> engine_weight = 10000 ; 
  process -> cont_mark_pos = (long ) 1 ; 
  process -> cont_mark_stack = 0 ; 
  process -> cont_mark_stack_segments = ((void * ) 0 ) ; 
  process -> cont_mark_seg_count = 0 ; 
  if (! config ) {
#   define XfOrM250_COUNT (0+XfOrM237_COUNT)
#   define SETUP_XfOrM250(x) SETUP_XfOrM237(x)
    FUNCCALL(SETUP_XfOrM250(_), make_initial_config (process ) ); 
    config = process -> init_config ; 
  }
  else {
    process -> init_config = config ; 
    process -> cell_values = cells ; 
  }
  if (init_break_cell ) {
    process -> init_break_cell = init_break_cell ; 
  }
  else {
    Scheme_Object * v ; 
    BLOCK_SETUP((PUSH(v, 0+XfOrM237_COUNT)));
#   define XfOrM247_COUNT (1+XfOrM237_COUNT)
#   define SETUP_XfOrM247(x) SETUP(XfOrM247_COUNT)
    v = NULLED_OUT ; 
    v = FUNCCALL(SETUP_XfOrM247(_), scheme_make_thread_cell (scheme_false , 1 ) ); 
    process -> init_break_cell = v ; 
  }
  if (! mgr )
    mgr = (Scheme_Custodian * ) FUNCCALL(SETUP_XfOrM237(_), scheme_get_param (config , MZCONFIG_CUSTODIAN ) ); 
  FUNCCALL(SETUP_XfOrM237(_), GC_register_new_thread (process , mgr ) ); 
  {
    Scheme_Object * t_set ; 
    BLOCK_SETUP((PUSH(t_set, 0+XfOrM237_COUNT)));
#   define XfOrM246_COUNT (1+XfOrM237_COUNT)
#   define SETUP_XfOrM246(x) SETUP(XfOrM246_COUNT)
    t_set = NULLED_OUT ; 
    t_set = FUNCCALL(SETUP_XfOrM246(_), scheme_get_param (config , MZCONFIG_THREAD_SET ) ); 
    process -> t_set_parent = (Scheme_Thread_Set * ) t_set ; 
  }
  if (((process ) == (scheme_first_thread ) ) ) {
#   define XfOrM245_COUNT (0+XfOrM237_COUNT)
#   define SETUP_XfOrM245(x) SETUP_XfOrM237(x)
    FUNCCALL(SETUP_XfOrM245(_), scheme_register_static ((void * ) & thread_set_top , sizeof (thread_set_top ) ) ); 
    thread_set_top = process -> t_set_parent ; 
    thread_set_top -> first = (Scheme_Object * ) process ; 
    thread_set_top -> current = (Scheme_Object * ) process ; 
  }
  else FUNCCALL(SETUP_XfOrM237(_), schedule_in_set ((Scheme_Object * ) process , process -> t_set_parent ) ); 
  FUNCCALL(SETUP_XfOrM237(_), scheme_init_jmpup_buf (& process -> jmpup_buf ) ); 
  process -> running = 0x1 ; 
  process -> dw = ((void * ) 0 ) ; 
  process -> block_descriptor = 0 ; 
  process -> block_check = ((void * ) 0 ) ; 
  process -> block_needs_wakeup = ((void * ) 0 ) ; 
  process -> sleep_end = 0 ; 
  process -> current_local_env = ((void * ) 0 ) ; 
  process -> suspend_break = 0 ; 
  process -> external_break = 0 ; 
  process -> ran_some = 1 ; 
  process -> list_stack = ((void * ) 0 ) ; 
  FUNCCALL(SETUP_XfOrM237(_), scheme_gmp_tls_init (process -> gmp_tls ) ); 
  if (prefix ) {
    process -> next = scheme_first_thread ; 
    process -> prev = ((void * ) 0 ) ; 
    process -> next -> prev = process ; 
    scheme_first_thread = process ; 
  }
  {
    Scheme_Object * * tb ; 
    BLOCK_SETUP((PUSH(tb, 0+XfOrM237_COUNT)));
#   define XfOrM243_COUNT (1+XfOrM237_COUNT)
#   define SETUP_XfOrM243(x) SETUP(XfOrM243_COUNT)
    tb = NULLED_OUT ; 
    tb = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM243(_), GC_malloc (sizeof (Scheme_Object * ) * (buffer_init_size ) ) )) ; 
    process -> tail_buffer = tb ; 
  }
  process -> tail_buffer_size = buffer_init_size ; 
  {
    int init_stack_size ; 
    Scheme_Object * iss ; 
    BLOCK_SETUP((PUSH(iss, 0+XfOrM237_COUNT)));
#   define XfOrM241_COUNT (1+XfOrM237_COUNT)
#   define SETUP_XfOrM241(x) SETUP(XfOrM241_COUNT)
    iss = NULLED_OUT ; 
    iss = FUNCCALL(SETUP_XfOrM241(_), scheme_get_thread_param (config , cells , MZCONFIG_THREAD_INIT_STACK_SIZE ) ); 
    if ((((long ) (iss ) ) & 0x1 ) )
      init_stack_size = (((long ) (iss ) ) >> 1 ) ; 
    else if (((Scheme_Type ) (((((long ) (iss ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (iss ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
      init_stack_size = 0x7FFFFFFF ; 
    else init_stack_size = 1000 ; 
    if (init_stack_size > 100000 )
      init_stack_size = 100000 ; 
    if (init_stack_size < 5 )
      init_stack_size = 5 ; 
    process -> runstack_size = init_stack_size ; 
    {
      Scheme_Object * * sa ; 
      BLOCK_SETUP((PUSH(sa, 0+XfOrM241_COUNT)));
#     define XfOrM242_COUNT (1+XfOrM241_COUNT)
#     define SETUP_XfOrM242(x) SETUP(XfOrM242_COUNT)
      sa = NULLED_OUT ; 
      sa = FUNCCALL(SETUP_XfOrM242(_), scheme_alloc_runstack (init_stack_size ) ); 
      process -> runstack_start = sa ; 
    }
    process -> runstack = process -> runstack_start + init_stack_size ; 
  }
  process -> runstack_saved = ((void * ) 0 ) ; 
  if (! prefix ) {
#   define XfOrM240_COUNT (0+XfOrM237_COUNT)
#   define SETUP_XfOrM240(x) SETUP_XfOrM237(x)
    FUNCCALL(SETUP_XfOrM240(_), scheme_register_static ((void * ) & scheme_current_runstack_start , sizeof (scheme_current_runstack_start ) ) ); 
    scheme_current_runstack = process -> runstack ; 
    scheme_current_runstack_start = process -> runstack_start ; 
    scheme_current_cont_mark_stack = process -> cont_mark_stack ; 
    scheme_current_cont_mark_pos = process -> cont_mark_pos ; 
  }
  process -> on_kill = ((void * ) 0 ) ; 
  process -> user_tls = ((void * ) 0 ) ; 
  process -> user_tls_size = 0 ; 
  process -> nester = process -> nestee = ((void * ) 0 ) ; 
  {
    Scheme_Thread_Custodian_Hop * hop ; 
    Scheme_Custodian_Reference * mref ; 
    BLOCK_SETUP((PUSH(mref, 0+XfOrM237_COUNT), PUSH(hop, 1+XfOrM237_COUNT)));
#   define XfOrM238_COUNT (2+XfOrM237_COUNT)
#   define SETUP_XfOrM238(x) SETUP(XfOrM238_COUNT)
    hop = NULLED_OUT ; 
    mref = NULLED_OUT ; 
    hop = ((Scheme_Thread_Custodian_Hop * ) FUNCCALL(SETUP_XfOrM238(_), GC_malloc_one_tagged (sizeof (Scheme_Thread_Custodian_Hop ) * (1 ) ) )) ; 
    process -> mr_hop = hop ; 
    hop -> so . type = scheme_thread_hop_type ; 
    {
      Scheme_Thread * wp ; 
      BLOCK_SETUP((PUSH(wp, 0+XfOrM238_COUNT)));
#     define XfOrM239_COUNT (1+XfOrM238_COUNT)
#     define SETUP_XfOrM239(x) SETUP(XfOrM239_COUNT)
      wp = NULLED_OUT ; 
      wp = (Scheme_Thread * ) FUNCCALL(SETUP_XfOrM239(_), scheme_make_weak_box ((Scheme_Object * ) process ) ); 
      hop -> p = wp ; 
    }
    mref = FUNCCALL(SETUP_XfOrM238(_), scheme_add_managed (mgr , (Scheme_Object * ) hop , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ); 
    process -> mref = mref ; 
    process -> extra_mrefs = scheme_null ; 
  }
  RET_VALUE_START (process ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Thread * scheme_make_thread () {
  /* No conversion */
  return make_thread (((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) ) ; 
}
static void scheme_check_tail_buffer_size (Scheme_Thread * p ) {
  PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(p, 0)));
# define XfOrM255_COUNT (1)
# define SETUP_XfOrM255(x) SETUP(XfOrM255_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (p -> tail_buffer_size < buffer_init_size ) {
    Scheme_Object * * tb ; 
    BLOCK_SETUP((PUSH(tb, 0+XfOrM255_COUNT)));
#   define XfOrM256_COUNT (1+XfOrM255_COUNT)
#   define SETUP_XfOrM256(x) SETUP(XfOrM256_COUNT)
    tb = NULLED_OUT ; 
    tb = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM256(_), GC_malloc (sizeof (Scheme_Object * ) * (buffer_init_size ) ) )) ; 
    p -> tail_buffer = tb ; 
    p -> tail_buffer_size = buffer_init_size ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_set_tail_buffer_size (int s ) {
  PREPARE_VAR_STACK(1);
# define XfOrM257_COUNT (0)
# define SETUP_XfOrM257(x) SETUP(XfOrM257_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (s > buffer_init_size ) {
    Scheme_Thread * p ; 
    BLOCK_SETUP((PUSH(p, 0+XfOrM257_COUNT)));
#   define XfOrM258_COUNT (1+XfOrM257_COUNT)
#   define SETUP_XfOrM258(x) SETUP(XfOrM258_COUNT)
    p = NULLED_OUT ; 
    buffer_init_size = s ; 
    for (p = scheme_first_thread ; p ; p = p -> next ) {
#     define XfOrM260_COUNT (0+XfOrM258_COUNT)
#     define SETUP_XfOrM260(x) SETUP_XfOrM258(x)
      FUNCCALL(SETUP_XfOrM260(_), scheme_check_tail_buffer_size (p ) ); 
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_tls_allocate () {
  /* No conversion */
  return tls_pos ++ ; 
}
void scheme_tls_set (int pos , void * v ) {
  Scheme_Thread * p = scheme_current_thread ; 
  PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(p, 1)));
# define XfOrM262_COUNT (2)
# define SETUP_XfOrM262(x) SETUP(XfOrM262_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (p -> user_tls_size <= pos ) {
    int oldc = p -> user_tls_size ; 
    void * * old_tls = p -> user_tls , * * va ; 
    BLOCK_SETUP((PUSH(old_tls, 0+XfOrM262_COUNT), PUSH(va, 1+XfOrM262_COUNT)));
#   define XfOrM263_COUNT (2+XfOrM262_COUNT)
#   define SETUP_XfOrM263(x) SETUP(XfOrM263_COUNT)
    va = NULLED_OUT ; 
    p -> user_tls_size = tls_pos ; 
    va = ((void * * ) FUNCCALL(SETUP_XfOrM263(_), GC_malloc (sizeof (void * ) * (tls_pos ) ) )) ; 
    p -> user_tls = va ; 
    while (oldc -- ) {
      p -> user_tls [oldc ] = old_tls [oldc ] ; 
    }
  }
  p -> user_tls [pos ] = v ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void * scheme_tls_get (int pos ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  if (p -> user_tls_size <= pos )
    return ((void * ) 0 ) ; 
  else return p -> user_tls [pos ] ; 
}
Scheme_Object * * scheme_alloc_runstack (long len ) {
  long sz ; 
  void * * p ; 
  sz = sizeof (Scheme_Object * ) * (len + 4 ) ; 
  p = (void * * ) GC_malloc_tagged_allow_interior (sz ) ; 
  * (Scheme_Type * ) (void * ) p = scheme_rt_runstack ; 
  ((long * ) (void * ) p ) [1 ] = ((sz + (1 << 3 ) - 1 ) >> 3 ) ; 
  ((long * ) (void * ) p ) [2 ] = 0 ; 
  ((long * ) (void * ) p ) [3 ] = len ; 
  return (Scheme_Object * * ) (p + 4 ) ; 
}
void scheme_set_runstack_limits (Scheme_Object * * rs , long len , long start , long end ) {
  if (((long * ) (void * ) rs ) [- 2 ] != start )
    ((long * ) (void * ) rs ) [- 2 ] = start ; 
  if (((long * ) (void * ) rs ) [- 1 ] != end )
    ((long * ) (void * ) rs ) [- 1 ] = end ; 
}
int scheme_in_main_thread (void ) {
  /* No conversion */
  return ! scheme_current_thread -> next ; 
}
static void do_swap_thread () {
  PREPARE_VAR_STACK(2);
# define XfOrM268_COUNT (0)
# define SETUP_XfOrM268(x) SETUP(XfOrM268_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  FUNCCALL(SETUP_XfOrM268(_), scheme_zero_unneeded_rands (scheme_current_thread ) ); 
  if (! swap_no_setjmp && FUNCCALL(SETUP_XfOrM268(_), scheme_setjmpup_relative (& scheme_current_thread -> jmpup_buf , scheme_current_thread , (scheme_current_thread -> stack_start ) , ((void * ) 0 ) ) )) {
    thread_swap_count ++ ; 
#   define XfOrM274_COUNT (0+XfOrM268_COUNT)
#   define SETUP_XfOrM274(x) SETUP_XfOrM268(x)
    scheme_current_runstack = scheme_current_thread -> runstack ; 
    scheme_current_runstack_start = scheme_current_thread -> runstack_start ; 
    scheme_current_cont_mark_stack = scheme_current_thread -> cont_mark_stack ; 
    scheme_current_cont_mark_pos = scheme_current_thread -> cont_mark_pos ; 
    FUNCCALL(SETUP_XfOrM274(_), scheme_reset_jmpup_buf (& scheme_current_thread -> jmpup_buf ) ); 
    FUNCCALL_AGAIN(scheme_gmp_tls_unload (scheme_current_thread -> gmp_tls ) ); 
    {
      Scheme_Object * l , * o ; 
      Scheme_Closure_Func f ; 
      BLOCK_SETUP((PUSH(o, 0+XfOrM274_COUNT), PUSH(l, 1+XfOrM274_COUNT)));
#     define XfOrM276_COUNT (2+XfOrM274_COUNT)
#     define SETUP_XfOrM276(x) SETUP(XfOrM276_COUNT)
      l = NULLED_OUT ; 
      o = NULLED_OUT ; 
      for (l = thread_swap_callbacks ; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#       define XfOrM278_COUNT (0+XfOrM276_COUNT)
#       define SETUP_XfOrM278(x) SETUP_XfOrM276(x)
        o = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
        f = ((Scheme_Closure_Func ) (((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . car ) ) ; 
        o = (((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . cdr ) ; 
        FUNCCALL(SETUP_XfOrM278(_), f (o ) ); 
      }
    }
    if ((scheme_current_thread -> runstack_owner && ((* scheme_current_thread -> runstack_owner ) != scheme_current_thread ) ) || (scheme_current_thread -> cont_mark_stack_owner && ((* scheme_current_thread -> cont_mark_stack_owner ) != scheme_current_thread ) ) ) {
#     define XfOrM275_COUNT (0+XfOrM274_COUNT)
#     define SETUP_XfOrM275(x) SETUP_XfOrM274(x)
      FUNCCALL(SETUP_XfOrM275(_), scheme_takeover_stacks (scheme_current_thread ) ); 
    }
  }
  else {
    Scheme_Thread * new_thread = swap_target ; 
    BLOCK_SETUP((PUSH(new_thread, 0+XfOrM268_COUNT)));
#   define XfOrM269_COUNT (1+XfOrM268_COUNT)
#   define SETUP_XfOrM269(x) SETUP(XfOrM269_COUNT)
    swap_target = ((void * ) 0 ) ; 
    swap_no_setjmp = 0 ; 
    if (scheme_current_thread -> init_break_cell ) {
      int cb ; 
#     define XfOrM273_COUNT (0+XfOrM269_COUNT)
#     define SETUP_XfOrM273(x) SETUP_XfOrM269(x)
      cb = FUNCCALL(SETUP_XfOrM273(_), can_break_param (scheme_current_thread ) ); 
      scheme_current_thread -> can_break_at_swap = cb ; 
    }
    FUNCCALL(SETUP_XfOrM269(_), scheme_gmp_tls_load (scheme_current_thread -> gmp_tls ) ); 
    scheme_current_thread -> runstack = scheme_current_runstack ; 
    scheme_current_thread -> runstack_start = scheme_current_runstack_start ; 
    scheme_current_thread -> cont_mark_stack = scheme_current_cont_mark_stack ; 
    scheme_current_thread -> cont_mark_pos = scheme_current_cont_mark_pos ; 
    scheme_current_thread = new_thread ; 
    {
      Scheme_Thread_Set * t_set = new_thread -> t_set_parent ; 
      t_set -> current = (Scheme_Object * ) new_thread ; 
      while (t_set -> parent ) {
        t_set -> parent -> current = (Scheme_Object * ) t_set ; 
        t_set = t_set -> parent ; 
      }
    }
    FUNCCALL_EMPTY(scheme_longjmpup (& scheme_current_thread -> jmpup_buf ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_swap_thread (Scheme_Thread * new_thread ) {
  /* No conversion */
  swap_target = new_thread ; 
  new_thread = ((void * ) 0 ) ; 
  do_swap_thread () ; 
}
static void select_thread () {
  Scheme_Thread * new_thread ; 
  Scheme_Object * o ; 
  Scheme_Thread_Set * t_set ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(new_thread, 0), PUSH(t_set, 1), PUSH(o, 2)));
# define XfOrM280_COUNT (3)
# define SETUP_XfOrM280(x) SETUP(XfOrM280_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  new_thread = NULLED_OUT ; 
  o = NULLED_OUT ; 
  t_set = NULLED_OUT ; 
  o = (Scheme_Object * ) thread_set_top ; 
  while (! ((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_type ) ) ) {
#   define XfOrM302_COUNT (0+XfOrM280_COUNT)
#   define SETUP_XfOrM302(x) SETUP_XfOrM280(x)
    t_set = (Scheme_Thread_Set * ) o ; 
    o = FUNCCALL(SETUP_XfOrM302(_), get_t_set_next (t_set -> current ) ); 
    if (! o )
      o = t_set -> first ; 
  }
  new_thread = (Scheme_Thread * ) o ; 
  do {
#   define XfOrM291_COUNT (0+XfOrM280_COUNT)
#   define SETUP_XfOrM291(x) SETUP_XfOrM280(x)
    if (! new_thread )
      new_thread = scheme_first_thread ; 
    while (new_thread && (new_thread -> nestee || (new_thread -> running & 0x2 ) || ((new_thread -> running & 0x10 ) && ! (new_thread -> running & 0x20 ) ) ) ) {
      new_thread = new_thread -> next ; 
    }
    if (! new_thread && ! o ) {
#     define XfOrM292_COUNT (0+XfOrM291_COUNT)
#     define SETUP_XfOrM292(x) SETUP_XfOrM291(x)
      new_thread = scheme_main_thread ; 
      while (new_thread -> nestee ) {
        new_thread = new_thread -> nestee ; 
      }
      if ((new_thread -> running & 0x10 ) && ! (new_thread -> running & 0x20 ) ) {
#       define XfOrM294_COUNT (0+XfOrM292_COUNT)
#       define SETUP_XfOrM294(x) SETUP_XfOrM292(x)
        if (FUNCCALL(SETUP_XfOrM294(_), post_system_idle () )) {
        }
        else {
#         define XfOrM295_COUNT (0+XfOrM294_COUNT)
#         define SETUP_XfOrM295(x) SETUP_XfOrM294(x)
          FUNCCALL(SETUP_XfOrM295(_), scheme_console_printf ("unbreakable deadlock\n" ) ); 
          if (scheme_exit )
            FUNCCALL(SETUP_XfOrM295(_), scheme_exit (1 ) ); 
          FUNCCALL_EMPTY(exit (1 ) ); 
        }
      }
      else {
#       define XfOrM293_COUNT (0+XfOrM292_COUNT)
#       define SETUP_XfOrM293(x) SETUP_XfOrM292(x)
        FUNCCALL(SETUP_XfOrM293(_), scheme_weak_resume_thread (new_thread ) ); 
      }
      break ; 
    }
    o = ((void * ) 0 ) ; 
  }
  while (! new_thread ) ; 
  swap_target = new_thread ; 
  new_thread = ((void * ) 0 ) ; 
  o = ((void * ) 0 ) ; 
  t_set = ((void * ) 0 ) ; 
  FUNCCALL_EMPTY(do_swap_thread () ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void thread_is_dead (Scheme_Thread * r ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(r, 0)));
# define XfOrM303_COUNT (1)
# define SETUP_XfOrM303(x) SETUP(XfOrM303_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (r -> dead_box ) {
    Scheme_Object * o ; 
#   define XfOrM305_COUNT (0+XfOrM303_COUNT)
#   define SETUP_XfOrM305(x) SETUP_XfOrM303(x)
    o = NULLED_OUT ; 
    o = (((Scheme_Small_Object * ) (r -> dead_box ) ) -> u . ptr_val ) ; 
    FUNCCALL(SETUP_XfOrM305(_), scheme_post_sema_all (o ) ); 
  }
  if (r -> running_box ) {
    (((Scheme_Small_Object * ) (r -> running_box ) ) -> u . ptr_val ) = ((void * ) 0 ) ; 
    r -> running_box = ((void * ) 0 ) ; 
  }
  r -> suspended_box = ((void * ) 0 ) ; 
  r -> resumed_box = ((void * ) 0 ) ; 
  r -> list_stack = ((void * ) 0 ) ; 
  r -> dw = ((void * ) 0 ) ; 
  r -> init_config = ((void * ) 0 ) ; 
  r -> cell_values = ((void * ) 0 ) ; 
  r -> init_break_cell = ((void * ) 0 ) ; 
  r -> cont_mark_stack_segments = ((void * ) 0 ) ; 
  r -> overflow = ((void * ) 0 ) ; 
  r -> blocker = ((void * ) 0 ) ; 
  r -> transitive_resumes = ((void * ) 0 ) ; 
  r -> error_buf = ((void * ) 0 ) ; 
  r -> spare_runstack = ((void * ) 0 ) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 2633 */
/* this far 2633 */
/* this far 2626 */
static void remove_thread (Scheme_Thread * r ) {
  Scheme_Saved_Stack * saved ; 
  Scheme_Object * l ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(saved, 0), PUSH(r, 1), PUSH(l, 2)));
# define XfOrM306_COUNT (3)
# define SETUP_XfOrM306(x) SETUP(XfOrM306_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  saved = NULLED_OUT ; 
  l = NULLED_OUT ; 
  r -> running = 0 ; 
  if (r -> prev ) {
    r -> prev -> next = r -> next ; 
    r -> next -> prev = r -> prev ; 
  }
  else if (r -> next ) {
    r -> next -> prev = ((void * ) 0 ) ; 
    scheme_first_thread = r -> next ; 
  }
  r -> next = r -> prev = ((void * ) 0 ) ; 
  FUNCCALL(SETUP_XfOrM306(_), unschedule_in_set ((Scheme_Object * ) r , r -> t_set_parent ) ); 
  if (r == scheme_current_thread ) {
    r -> runstack = scheme_current_runstack ; 
    scheme_current_runstack = ((void * ) 0 ) ; 
    r -> runstack_start = scheme_current_runstack_start ; 
    scheme_current_runstack_start = ((void * ) 0 ) ; 
    r -> cont_mark_stack = scheme_current_cont_mark_stack ; 
    r -> cont_mark_pos = scheme_current_cont_mark_pos ; 
  }
  if (r -> runstack_owner ) {
#   define XfOrM314_COUNT (0+XfOrM306_COUNT)
#   define SETUP_XfOrM314(x) SETUP_XfOrM306(x)
    if (r == * (r -> runstack_owner ) ) {
#     define XfOrM315_COUNT (0+XfOrM314_COUNT)
#     define SETUP_XfOrM315(x) SETUP_XfOrM314(x)
      if (r -> runstack_start ) {
#       define XfOrM318_COUNT (0+XfOrM315_COUNT)
#       define SETUP_XfOrM318(x) SETUP_XfOrM315(x)
        FUNCCALL(SETUP_XfOrM318(_), scheme_set_runstack_limits (r -> runstack_start , r -> runstack_size , 0 , 0 ) ); 
        r -> runstack_start = ((void * ) 0 ) ; 
      }
      for (saved = r -> runstack_saved ; saved ; saved = saved -> prev ) {
#       define XfOrM317_COUNT (0+XfOrM315_COUNT)
#       define SETUP_XfOrM317(x) SETUP_XfOrM315(x)
        FUNCCALL(SETUP_XfOrM317(_), scheme_set_runstack_limits (saved -> runstack_start , saved -> runstack_size , 0 , 0 ) ); 
      }
      r -> runstack_saved = ((void * ) 0 ) ; 
      * (r -> runstack_owner ) = ((void * ) 0 ) ; 
      r -> runstack_owner = ((void * ) 0 ) ; 
    }
  }
  else {
#   define XfOrM311_COUNT (0+XfOrM306_COUNT)
#   define SETUP_XfOrM311(x) SETUP_XfOrM306(x)
    (memset (r -> runstack_start , 0 , r -> runstack_size * sizeof (Scheme_Object * ) ) ) ; 
    r -> runstack_start = ((void * ) 0 ) ; 
    for (saved = r -> runstack_saved ; saved ; saved = saved -> prev ) {
#     define XfOrM313_COUNT (0+XfOrM311_COUNT)
#     define SETUP_XfOrM313(x) SETUP_XfOrM311(x)
      (memset (saved -> runstack_start , 0 , saved -> runstack_size * sizeof (Scheme_Object * ) ) ) ; 
      saved -> runstack_start = ((void * ) 0 ) ; 
    }
  }
  r -> runstack = ((void * ) 0 ) ; 
  r -> runstack_swapped = ((void * ) 0 ) ; 
  if (r -> cont_mark_stack_owner && ((* r -> cont_mark_stack_owner ) == r ) ) {
    * r -> cont_mark_stack_owner = ((void * ) 0 ) ; 
  }
  r -> cont_mark_stack = 0 ; 
  r -> cont_mark_stack_owner = ((void * ) 0 ) ; 
  r -> cont_mark_stack_swapped = ((void * ) 0 ) ; 
  r -> ku . apply . tail_rator = ((void * ) 0 ) ; 
  r -> ku . apply . tail_rands = ((void * ) 0 ) ; 
  r -> tail_buffer = ((void * ) 0 ) ; 
  r -> ku . multiple . array = ((void * ) 0 ) ; 
  r -> values_buffer = ((void * ) 0 ) ; 
  if (r -> list_stack )
    FUNCCALL(SETUP_XfOrM306(_), GC_free (r -> list_stack ) ); 
  FUNCCALL(SETUP_XfOrM306(_), thread_is_dead (r ) ); 
  FUNCCALL_AGAIN(scheme_gmp_tls_restore_snapshot (r -> gmp_tls , ((void * ) 0 ) , ((r == scheme_current_thread ) ? 1 : 2 ) ) ); 
  if (r == scheme_current_thread ) {
    swap_no_setjmp = 1 ; 
  }
  else FUNCCALL(SETUP_XfOrM306(_), scheme_reset_jmpup_buf (& r -> jmpup_buf ) ); 
  FUNCCALL(SETUP_XfOrM306(_), scheme_remove_managed (r -> mref , (Scheme_Object * ) r -> mr_hop ) ); 
  for (l = r -> extra_mrefs ; ! ((l ) == (scheme_null ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#   define XfOrM308_COUNT (0+XfOrM306_COUNT)
#   define SETUP_XfOrM308(x) SETUP_XfOrM306(x)
    FUNCCALL(SETUP_XfOrM308(_), scheme_remove_managed ((Scheme_Custodian_Reference * ) (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) , (Scheme_Object * ) r -> mr_hop ) ); 
  }
  r -> extra_mrefs = scheme_null ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_end_current_thread (void ) {
  /* No conversion */
  remove_thread (scheme_current_thread ) ; 
  thread_ended_with_activity = 1 ; 
  if (scheme_notify_multithread && ! scheme_first_thread -> next ) {
    scheme_notify_multithread (0 ) ; 
    have_activity = 0 ; 
  }
  select_thread () ; 
}
static void start_child (Scheme_Thread * volatile child , Scheme_Object * volatile child_eval ) {
  PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(child, 0), PUSH(child_eval, 1)));
# define XfOrM324_COUNT (2)
# define SETUP_XfOrM324(x) SETUP(XfOrM324_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (FUNCCALL(SETUP_XfOrM324(_), scheme_setjmpup_relative (& child -> jmpup_buf , child , (child -> stack_start ) , ((void * ) 0 ) ) )) {
    Scheme_Object * volatile result = ((void * ) 0 ) ; 
    thread_swap_count ++ ; 
    BLOCK_SETUP((PUSH(result, 0+XfOrM324_COUNT)));
#   define XfOrM325_COUNT (1+XfOrM324_COUNT)
#   define SETUP_XfOrM325(x) SETUP(XfOrM325_COUNT)
    scheme_current_runstack = scheme_current_thread -> runstack ; 
    scheme_current_runstack_start = scheme_current_thread -> runstack_start ; 
    scheme_current_cont_mark_stack = scheme_current_thread -> cont_mark_stack ; 
    scheme_current_cont_mark_pos = scheme_current_thread -> cont_mark_pos ; 
    FUNCCALL(SETUP_XfOrM325(_), scheme_gmp_tls_unload (scheme_current_thread -> gmp_tls ) ); 
    {
      Scheme_Object * l , * o ; 
      Scheme_Closure_Func f ; 
      BLOCK_SETUP((PUSH(o, 0+XfOrM325_COUNT), PUSH(l, 1+XfOrM325_COUNT)));
#     define XfOrM337_COUNT (2+XfOrM325_COUNT)
#     define SETUP_XfOrM337(x) SETUP(XfOrM337_COUNT)
      l = NULLED_OUT ; 
      o = NULLED_OUT ; 
      for (l = thread_swap_callbacks ; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#       define XfOrM339_COUNT (0+XfOrM337_COUNT)
#       define SETUP_XfOrM339(x) SETUP_XfOrM337(x)
        o = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
        f = ((Scheme_Closure_Func ) (((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . car ) ) ; 
        o = (((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . cdr ) ; 
        FUNCCALL(SETUP_XfOrM339(_), f (o ) ); 
      }
    }
    FUNCCALL(SETUP_XfOrM325(_), scheme_reset_jmpup_buf (& child -> jmpup_buf ) ); 
    if (scheme_current_thread -> running & 0x4 ) {
#     define XfOrM336_COUNT (0+XfOrM325_COUNT)
#     define SETUP_XfOrM336(x) SETUP_XfOrM325(x)
      FUNCCALL(SETUP_XfOrM336(_), exit_or_escape (scheme_current_thread ) ); 
    }
    {
      mz_jmp_buf newbuf ; 
#     define XfOrM334_COUNT (0+XfOrM325_COUNT)
#     define SETUP_XfOrM334(x) SETUP_XfOrM325(x)
      scheme_current_thread -> error_buf = & newbuf ; 
      if (! ((newbuf ) . gcvs = (long ) __gc_var_stack__ , (newbuf ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((newbuf ) . jb ) , (_setjmp (((newbuf ) . jb ) -> jb ) ) ) ) ) {
#       define XfOrM335_COUNT (0+XfOrM334_COUNT)
#       define SETUP_XfOrM335(x) SETUP_XfOrM334(x)
        result = FUNCCALL(SETUP_XfOrM335(_), scheme_apply_thread_thunk (child_eval ) ); 
      }
    }
    while (scheme_current_thread -> meta_continuation ) {
      Scheme_Thread * p = scheme_current_thread ; 
      Scheme_Overflow * oflow ; 
      BLOCK_SETUP((PUSH(oflow, 0+XfOrM325_COUNT), PUSH(p, 1+XfOrM325_COUNT)));
#     define XfOrM330_COUNT (2+XfOrM325_COUNT)
#     define SETUP_XfOrM330(x) SETUP(XfOrM330_COUNT)
      oflow = NULLED_OUT ; 
      p -> cjs . val = result ; 
      if (! ((p -> meta_continuation -> prompt_tag ) == (scheme_default_prompt_tag ) ) ) {
#       define XfOrM333_COUNT (0+XfOrM330_COUNT)
#       define SETUP_XfOrM333(x) SETUP_XfOrM330(x)
        FUNCCALL(SETUP_XfOrM333(_), scheme_signal_error ("thread ended with meta continuation that isn't for the default prompt" ) ); 
      }
      else {
#       define XfOrM331_COUNT (0+XfOrM330_COUNT)
#       define SETUP_XfOrM331(x) SETUP_XfOrM330(x)
        oflow = p -> meta_continuation -> overflow ; 
        p -> meta_continuation = p -> meta_continuation -> next ; 
        if (! oflow -> eot ) {
#         define XfOrM332_COUNT (0+XfOrM331_COUNT)
#         define SETUP_XfOrM332(x) SETUP_XfOrM331(x)
          p -> stack_start = oflow -> stack_start ; 
          FUNCCALL(SETUP_XfOrM332(_), scheme_longjmpup (& oflow -> jmp -> cont ) ); 
        }
      }
    }
    FUNCCALL(SETUP_XfOrM325(_), scheme_end_current_thread () ); 
    FUNCCALL(SETUP_XfOrM325(_), scheme_signal_error ("bad thread switch" ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_ensure_stack_start (void * d ) {
  /* No conversion */
  if (! scheme_deepest_stack_start || ((((unsigned long ) scheme_deepest_stack_start ) < ((unsigned long ) d ) ) ) )
    scheme_deepest_stack_start = d ; 
}
static Scheme_Object * make_subprocess (Scheme_Object * child_thunk , void * child_start , Scheme_Config * config , Scheme_Thread_Cell_Table * cells , Scheme_Object * break_cell , Scheme_Custodian * mgr , int normal_kill ) {
  Scheme_Thread * child ; 
  int turn_on_multi ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(9);
  BLOCK_SETUP_TOP((PUSH(child_thunk, 0), PUSH(child_start, 1), PUSH(break_cell, 2), PUSH(cells, 3), PUSH(child, 4), PUSH(config, 5), PUSH(mgr, 6)));
# define XfOrM341_COUNT (7)
# define SETUP_XfOrM341(x) SETUP(XfOrM341_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  child = NULLED_OUT ; 
  turn_on_multi = ! scheme_first_thread -> next ; 
  FUNCCALL(SETUP_XfOrM341(_), scheme_ensure_stack_start (child_start ) ); 
  if (! config )
    config = FUNCCALL(SETUP_XfOrM341(_), scheme_current_config () ); 
  if (! cells )
    cells = FUNCCALL(SETUP_XfOrM341(_), scheme_inherit_cells (((void * ) 0 ) ) ); 
  if (! break_cell ) {
#   define XfOrM348_COUNT (0+XfOrM341_COUNT)
#   define SETUP_XfOrM348(x) SETUP_XfOrM341(x)
    break_cell = FUNCCALL(SETUP_XfOrM348(_), scheme_current_break_cell () ); 
    if (((break_cell ) == (maybe_recycle_cell ) ) )
      maybe_recycle_cell = ((void * ) 0 ) ; 
  }
  child = FUNCCALL(SETUP_XfOrM341(_), make_thread (config , cells , break_cell , mgr ) ); 
  {
    Scheme_Object * sym ; 
    const char * s ; 
    int len ; 
    BLOCK_SETUP((PUSH(sym, 0+XfOrM341_COUNT), PUSH(s, 1+XfOrM341_COUNT)));
#   define XfOrM346_COUNT (2+XfOrM341_COUNT)
#   define SETUP_XfOrM346(x) SETUP(XfOrM346_COUNT)
    sym = NULLED_OUT ; 
    s = NULLED_OUT ; 
    s = FUNCCALL(SETUP_XfOrM346(_), scheme_get_proc_name (child_thunk , & len , - 1 ) ); 
    if (s ) {
#     define XfOrM347_COUNT (0+XfOrM346_COUNT)
#     define SETUP_XfOrM347(x) SETUP_XfOrM346(x)
      if (len < 0 )
        sym = (Scheme_Object * ) s ; 
      else sym = FUNCCALL(SETUP_XfOrM347(_), scheme_intern_exact_symbol (s , len ) ); 
      child -> name = sym ; 
    }
  }
  {
    Scheme_Object * v ; 
    BLOCK_SETUP((PUSH(v, 0+XfOrM341_COUNT)));
#   define XfOrM345_COUNT (1+XfOrM341_COUNT)
#   define SETUP_XfOrM345(x) SETUP(XfOrM345_COUNT)
    v = NULLED_OUT ; 
    v = FUNCCALL(SETUP_XfOrM345(_), scheme_thread_cell_get (break_cell , cells ) ); 
    child -> can_break_at_swap = (! (((v ) ) == (scheme_false ) ) ) ; 
  }
  if (! normal_kill )
    child -> suspend_to_kill = 1 ; 
  child -> stack_start = child_start ; 
  FUNCCALL(SETUP_XfOrM341(_), start_child (child , child_thunk ) ); 
  if (scheme_notify_multithread && turn_on_multi ) {
#   define XfOrM344_COUNT (0+XfOrM341_COUNT)
#   define SETUP_XfOrM344(x) SETUP_XfOrM341(x)
    FUNCCALL(SETUP_XfOrM344(_), scheme_notify_multithread (1 ) ); 
    have_activity = 1 ; 
  }
  {
#   define XfOrM342_COUNT (0+XfOrM341_COUNT)
#   define SETUP_XfOrM342(x) SETUP_XfOrM341(x)
    if ((scheme_fuel_counter ) <= 0 ) {
#     define XfOrM343_COUNT (0+XfOrM342_COUNT)
#     define SETUP_XfOrM343(x) SETUP_XfOrM342(x)
      FUNCCALL(SETUP_XfOrM343(_), scheme_out_of_fuel () ); 
    }
  }
  ; 
  RET_VALUE_START ((Scheme_Object * ) child ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_thread (Scheme_Object * thunk ) {
  /* No conversion */
  return scheme_thread_w_details (thunk , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ; 
}
static Scheme_Object * sch_thread (int argc , Scheme_Object * args [] ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(args, 0)));
# define XfOrM350_COUNT (1)
# define SETUP_XfOrM350(x) SETUP(XfOrM350_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM350(_), scheme_check_proc_arity ("thread" , 0 , 0 , argc , args ) ); 
  FUNCCALL(SETUP_XfOrM350(_), scheme_custodian_check_available (((void * ) 0 ) , "thread" , "thread" ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_thread (args [0 ] ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * sch_thread_nokill (int argc , Scheme_Object * args [] ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(args, 0)));
# define XfOrM351_COUNT (1)
# define SETUP_XfOrM351(x) SETUP(XfOrM351_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM351(_), scheme_check_proc_arity ("thread/suspend-to-kill" , 0 , 0 , argc , args ) ); 
  FUNCCALL(SETUP_XfOrM351(_), scheme_custodian_check_available (((void * ) 0 ) , "thread/suspend-to-kill" , "thread" ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_thread_w_details (args [0 ] , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * sch_current (int argc , Scheme_Object * args [] ) {
  /* No conversion */
  return (Scheme_Object * ) scheme_current_thread ; 
}
static Scheme_Object * thread_p (int argc , Scheme_Object * args [] ) {
  /* No conversion */
  return ((Scheme_Type ) (((((long ) (args [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_type ) ) ? scheme_true : scheme_false ; 
}
static Scheme_Object * thread_running_p (int argc , Scheme_Object * args [] ) {
  /* No conversion */
  int running ; 
  if (! ((Scheme_Type ) (((((long ) (args [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_type ) ) )
    scheme_wrong_type ("thread-running?" , "thread" , 0 , argc , args ) ; 
  running = ((Scheme_Thread * ) args [0 ] ) -> running ; 
  return ((((running ) && ! ((running ) & 0x4 ) ) && ! (running & 0x10 ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * thread_dead_p (int argc , Scheme_Object * args [] ) {
  /* No conversion */
  int running ; 
  if (! ((Scheme_Type ) (((((long ) (args [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_type ) ) )
    scheme_wrong_type ("thread-running?" , "thread" , 0 , argc , args ) ; 
  running = ((Scheme_Thread * ) args [0 ] ) -> running ; 
  return ((running ) && ! ((running ) & 0x4 ) ) ? scheme_false : scheme_true ; 
}
static int thread_wait_done (Scheme_Object * p , Scheme_Schedule_Info * sinfo ) {
  int running = ((Scheme_Thread * ) p ) -> running ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(p, 0), PUSH(sinfo, 1)));
# define XfOrM356_COUNT (2)
# define SETUP_XfOrM356(x) SETUP(XfOrM356_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (((running ) && ! ((running ) & 0x4 ) ) ) {
    Scheme_Object * evt ; 
    BLOCK_SETUP((PUSH(evt, 0+XfOrM356_COUNT)));
#   define XfOrM357_COUNT (1+XfOrM356_COUNT)
#   define SETUP_XfOrM357(x) SETUP(XfOrM357_COUNT)
    evt = NULLED_OUT ; 
    evt = FUNCCALL(SETUP_XfOrM357(_), scheme_get_thread_dead ((Scheme_Thread * ) p ) ); 
    FUNCCALL_EMPTY(scheme_set_sync_target (sinfo , evt , p , ((void * ) 0 ) , 0 , 0 ) ); 
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (1 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * thread_wait (int argc , Scheme_Object * args [] ) {
  /* No conversion */
  Scheme_Thread * p ; 
  if (! ((Scheme_Type ) (((((long ) (args [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_type ) ) )
    scheme_wrong_type ("thread-wait" , "thread" , 0 , argc , args ) ; 
  p = (Scheme_Thread * ) args [0 ] ; 
  if (((p -> running ) && ! ((p -> running ) & 0x4 ) ) ) {
    sch_sync (1 , args ) ; 
  }
  return scheme_void ; 
}
static void register_thread_sync () {
  /* No conversion */
  scheme_add_evt (scheme_thread_type , (Scheme_Ready_Fun ) thread_wait_done , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ; 
}
void scheme_add_swap_callback (Scheme_Closure_Func f , Scheme_Object * data ) {
  Scheme_Object * p ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(p, 0)));
# define XfOrM361_COUNT (1)
# define SETUP_XfOrM361(x) SETUP(XfOrM361_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  p = NULLED_OUT ; 
  p = FUNCCALL(SETUP_XfOrM361(_), scheme_make_raw_pair ((Scheme_Object * ) f , data ) ); 
  thread_swap_callbacks = FUNCCALL_EMPTY(scheme_make_pair (p , thread_swap_callbacks ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_check_stack_ok (char * s ) ; 
void scheme_check_stack_ok (char * s ) {
  /* No conversion */
  unsigned long _stk_pos ; 
  _stk_pos = (unsigned long ) & _stk_pos ; 
  if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
    s [(50000 / 2 ) ] = 1 ; 
  }
  else {
    s [(50000 / 2 ) ] = 0 ; 
  }
}
static int is_stack_too_shallow2 (void ) {
  /* No conversion */
  char s [(50000 / 2 ) + 1 ] ; 
  scheme_check_stack_ok (s ) ; 
  return s [(50000 / 2 ) ] ; 
}
int scheme_is_stack_too_shallow (void ) {
  /* No conversion */
  unsigned long _stk_pos ; 
  _stk_pos = (unsigned long ) & _stk_pos ; 
  if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
    return 1 ; 
  }
  return is_stack_too_shallow2 () ; 
}
static Scheme_Object * thread_k (void ) {
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * thunk , * result , * break_cell ; 
  Scheme_Config * config ; 
  Scheme_Custodian * mgr ; 
  Scheme_Thread_Cell_Table * cells ; 
  int suspend_to_kill = p -> ku . k . i1 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(result, 0)));
# define XfOrM368_COUNT (1)
# define SETUP_XfOrM368(x) SETUP(XfOrM368_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  thunk = NULLED_OUT ; 
  result = NULLED_OUT ; 
  break_cell = NULLED_OUT ; 
  config = NULLED_OUT ; 
  mgr = NULLED_OUT ; 
  cells = NULLED_OUT ; 
  thunk = (Scheme_Object * ) p -> ku . k . p1 ; 
  config = (Scheme_Config * ) p -> ku . k . p2 ; 
  mgr = (Scheme_Custodian * ) p -> ku . k . p3 ; 
  cells = (Scheme_Thread_Cell_Table * ) (((Scheme_Simple_Object * ) ((Scheme_Object * ) p -> ku . k . p4 ) ) -> u . pair_val . car ) ; 
  break_cell = (((Scheme_Simple_Object * ) ((Scheme_Object * ) p -> ku . k . p4 ) ) -> u . pair_val . cdr ) ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  p -> ku . k . p2 = ((void * ) 0 ) ; 
  p -> ku . k . p3 = ((void * ) 0 ) ; 
  p -> ku . k . p4 = ((void * ) 0 ) ; 
  result = FUNCCALL(SETUP_XfOrM368(_), make_subprocess (thunk , & __gc_var_stack__ , config , cells , break_cell , mgr , ! suspend_to_kill ) ); 
  RET_VALUE_START (result ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_thread_w_details (Scheme_Object * thunk , Scheme_Config * config , Scheme_Thread_Cell_Table * cells , Scheme_Object * break_cell , Scheme_Custodian * mgr , int suspend_to_kill ) {
  Scheme_Object * result ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(cells, 0), PUSH(config, 1), PUSH(result, 2), PUSH(break_cell, 3), PUSH(mgr, 4), PUSH(thunk, 5)));
# define XfOrM369_COUNT (6)
# define SETUP_XfOrM369(x) SETUP(XfOrM369_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  result = NULLED_OUT ; 
  if (FUNCCALL(SETUP_XfOrM369(_), scheme_is_stack_too_shallow () )) {
    Scheme_Thread * p = scheme_current_thread ; 
    BLOCK_SETUP((PUSH(p, 0+XfOrM369_COUNT)));
#   define XfOrM370_COUNT (1+XfOrM369_COUNT)
#   define SETUP_XfOrM370(x) SETUP(XfOrM370_COUNT)
    FUNCCALL(SETUP_XfOrM370(_), wait_until_suspend_ok () ); 
    p -> ku . k . p1 = thunk ; 
    p -> ku . k . p2 = config ; 
    p -> ku . k . p3 = mgr ; 
    result = FUNCCALL(SETUP_XfOrM370(_), scheme_make_pair ((Scheme_Object * ) cells , break_cell ) ); 
    p -> ku . k . p4 = result ; 
    p -> ku . k . i1 = suspend_to_kill ; 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_handle_stack_overflow (thread_k ) )) RET_VALUE_EMPTY_END ; 
  }
  result = FUNCCALL(SETUP_XfOrM369(_), make_subprocess (thunk , (void * ) & __gc_var_stack__ , config , cells , break_cell , mgr , ! suspend_to_kill ) ); 
  RET_VALUE_START (result ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * def_nested_exn_handler (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (scheme_current_thread -> nester ) {
    Scheme_Thread * p = scheme_current_thread ; 
    p -> cjs . jumping_to_continuation = (Scheme_Object * ) scheme_current_thread ; 
    p -> cjs . val = argv [0 ] ; 
    p -> cjs . is_kill = 0 ; 
    (((long * ) (void * ) ((* p -> error_buf ) . gcvs ) ) [1 ] = (* p -> error_buf ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* p -> error_buf ) . gcvs , scheme_jit_longjmp ((* p -> error_buf ) . jb , 1 ) ) ; 
  }
  return scheme_void ; 
}
Scheme_Object * scheme_call_as_nested_thread (int argc , Scheme_Object * argv [] , void * max_bottom ) {
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Thread * volatile np ; 
  Scheme_Custodian * mgr ; 
  Scheme_Object * volatile v ; 
  mz_jmp_buf newbuf ; 
  volatile int failure ; 
  Scheme_Config * __funcarg76 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(9);
  BLOCK_SETUP_TOP((PUSH(max_bottom, 0), PUSH(v, 1), PUSH(p, 2), PUSH(np, 3), PUSH(argv, 4), PUSH(mgr, 5)));
# define XfOrM373_COUNT (6)
# define SETUP_XfOrM373(x) SETUP(XfOrM373_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  np = NULLED_OUT ; 
  mgr = NULLED_OUT ; 
  v = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM373(_), scheme_check_proc_arity ("call-in-nested-thread" , 0 , 0 , argc , argv ) ); 
  if (argc > 1 ) {
#   define XfOrM390_COUNT (0+XfOrM373_COUNT)
#   define SETUP_XfOrM390(x) SETUP_XfOrM373(x)
    if (((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_custodian_type ) ) )
      mgr = (Scheme_Custodian * ) argv [1 ] ; 
    else {
#     define XfOrM391_COUNT (0+XfOrM390_COUNT)
#     define SETUP_XfOrM391(x) SETUP_XfOrM390(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("call-in-nested-thread" , "custodian" , 1 , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  else mgr = (Scheme_Custodian * ) (__funcarg76 = FUNCCALL(SETUP_XfOrM373(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg76 , MZCONFIG_CUSTODIAN ) )) ; 
  FUNCCALL(SETUP_XfOrM373(_), scheme_custodian_check_available (mgr , "call-in-nested-thread" , "thread" ) ); 
  {
#   define XfOrM388_COUNT (0+XfOrM373_COUNT)
#   define SETUP_XfOrM388(x) SETUP_XfOrM373(x)
    if ((scheme_fuel_counter ) <= 0 ) {
#     define XfOrM389_COUNT (0+XfOrM388_COUNT)
#     define SETUP_XfOrM389(x) SETUP_XfOrM388(x)
      FUNCCALL(SETUP_XfOrM389(_), scheme_out_of_fuel () ); 
    }
  }
  ; 
  FUNCCALL(SETUP_XfOrM373(_), wait_until_suspend_ok () ); 
  np = ((Scheme_Thread * ) FUNCCALL(SETUP_XfOrM373(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Thread ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  np -> so . type = scheme_thread_type ; 
  FUNCCALL(SETUP_XfOrM373(_), GC_register_new_thread (np , mgr ) ); 
  np -> running = 0x1 ; 
  np -> ran_some = 1 ; 
  p -> runstack = scheme_current_runstack ; 
  p -> runstack_start = scheme_current_runstack_start ; 
  p -> cont_mark_stack = scheme_current_cont_mark_stack ; 
  p -> cont_mark_pos = scheme_current_cont_mark_pos ; 
  if (! p -> runstack_owner ) {
    Scheme_Thread * * owner ; 
    BLOCK_SETUP((PUSH(owner, 0+XfOrM373_COUNT)));
#   define XfOrM387_COUNT (1+XfOrM373_COUNT)
#   define SETUP_XfOrM387(x) SETUP(XfOrM387_COUNT)
    owner = NULLED_OUT ; 
    owner = ((Scheme_Thread * * ) FUNCCALL(SETUP_XfOrM387(_), GC_malloc (sizeof (Scheme_Thread * ) * (1 ) ) )) ; 
    p -> runstack_owner = owner ; 
    * owner = p ; 
  }
  np -> runstack = p -> runstack ; 
  np -> runstack_start = p -> runstack_start ; 
  np -> runstack_size = p -> runstack_size ; 
  np -> runstack_saved = p -> runstack_saved ; 
  np -> runstack_owner = p -> runstack_owner ; 
  * np -> runstack_owner = np ; 
  np -> stack_start = p -> stack_start ; 
  np -> engine_weight = p -> engine_weight ; 
  {
    Scheme_Object * * tb ; 
    BLOCK_SETUP((PUSH(tb, 0+XfOrM373_COUNT)));
#   define XfOrM386_COUNT (1+XfOrM373_COUNT)
#   define SETUP_XfOrM386(x) SETUP(XfOrM386_COUNT)
    tb = NULLED_OUT ; 
    tb = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM386(_), GC_malloc (sizeof (Scheme_Object * ) * (p -> tail_buffer_size ) ) )) ; 
    np -> tail_buffer = tb ; 
  }
  np -> tail_buffer_size = p -> tail_buffer_size ; 
  FUNCCALL(SETUP_XfOrM373(_), scheme_ensure_stack_start (max_bottom ) ); 
  np -> list_stack = p -> list_stack ; 
  np -> list_stack_pos = p -> list_stack_pos ; 
  FUNCCALL(SETUP_XfOrM373(_), scheme_gmp_tls_init (np -> gmp_tls ) ); 
  np -> next = scheme_first_thread ; 
  scheme_first_thread -> prev = np ; 
  scheme_first_thread = np ; 
  np -> t_set_parent = p -> t_set_parent ; 
  FUNCCALL(SETUP_XfOrM373(_), schedule_in_set ((Scheme_Object * ) np , np -> t_set_parent ) ); 
  {
    Scheme_Thread_Cell_Table * cells ; 
    BLOCK_SETUP((PUSH(cells, 0+XfOrM373_COUNT)));
#   define XfOrM385_COUNT (1+XfOrM373_COUNT)
#   define SETUP_XfOrM385(x) SETUP(XfOrM385_COUNT)
    cells = NULLED_OUT ; 
    cells = FUNCCALL(SETUP_XfOrM385(_), scheme_inherit_cells (p -> cell_values ) ); 
    np -> cell_values = cells ; 
  }
  {
    Scheme_Config * config ; 
    BLOCK_SETUP((PUSH(config, 0+XfOrM373_COUNT)));
#   define XfOrM384_COUNT (1+XfOrM373_COUNT)
#   define SETUP_XfOrM384(x) SETUP(XfOrM384_COUNT)
    config = NULLED_OUT ; 
    config = FUNCCALL(SETUP_XfOrM384(_), scheme_current_config () ); 
    np -> init_config = config ; 
  }
  {
    int cb ; 
    Scheme_Object * bc ; 
    BLOCK_SETUP((PUSH(bc, 0+XfOrM373_COUNT)));
#   define XfOrM383_COUNT (1+XfOrM373_COUNT)
#   define SETUP_XfOrM383(x) SETUP(XfOrM383_COUNT)
    bc = NULLED_OUT ; 
    cb = FUNCCALL(SETUP_XfOrM383(_), scheme_can_break (p ) ); 
    p -> can_break_at_swap = cb ; 
    bc = FUNCCALL(SETUP_XfOrM383(_), scheme_current_break_cell () ); 
    np -> init_break_cell = bc ; 
    if (((bc ) == (maybe_recycle_cell ) ) )
      maybe_recycle_cell = ((void * ) 0 ) ; 
  }
  np -> cont_mark_pos = (long ) 1 ; 
  FUNCCALL(SETUP_XfOrM373(_), prepare_this_thread_for_GC (p ) ); 
  np -> nester = p ; 
  p -> nestee = np ; 
  np -> external_break = p -> external_break ; 
  p -> external_break = 0 ; 
  {
    Scheme_Thread_Custodian_Hop * hop ; 
    Scheme_Custodian_Reference * mref ; 
    BLOCK_SETUP((PUSH(mref, 0+XfOrM373_COUNT), PUSH(hop, 1+XfOrM373_COUNT)));
#   define XfOrM381_COUNT (2+XfOrM373_COUNT)
#   define SETUP_XfOrM381(x) SETUP(XfOrM381_COUNT)
    hop = NULLED_OUT ; 
    mref = NULLED_OUT ; 
    hop = ((Scheme_Thread_Custodian_Hop * ) FUNCCALL(SETUP_XfOrM381(_), GC_malloc_one_tagged (sizeof (Scheme_Thread_Custodian_Hop ) * (1 ) ) )) ; 
    np -> mr_hop = hop ; 
    hop -> so . type = scheme_thread_hop_type ; 
    {
      Scheme_Thread * wp ; 
      BLOCK_SETUP((PUSH(wp, 0+XfOrM381_COUNT)));
#     define XfOrM382_COUNT (1+XfOrM381_COUNT)
#     define SETUP_XfOrM382(x) SETUP(XfOrM382_COUNT)
      wp = NULLED_OUT ; 
      wp = (Scheme_Thread * ) FUNCCALL(SETUP_XfOrM382(_), scheme_make_weak_box ((Scheme_Object * ) np ) ); 
      hop -> p = wp ; 
    }
    mref = FUNCCALL(SETUP_XfOrM381(_), scheme_add_managed (mgr , (Scheme_Object * ) hop , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ); 
    np -> mref = mref ; 
    np -> extra_mrefs = scheme_null ; 
  }
  scheme_current_cont_mark_stack = np -> cont_mark_stack ; 
  scheme_current_cont_mark_pos = np -> cont_mark_pos ; 
  scheme_current_thread = np ; 
  if (p != scheme_main_thread )
    FUNCCALL(SETUP_XfOrM373(_), scheme_weak_suspend_thread (p ) ); 
  if (! nested_exn_handler ) {
#   define XfOrM380_COUNT (0+XfOrM373_COUNT)
#   define SETUP_XfOrM380(x) SETUP_XfOrM373(x)
    FUNCCALL(SETUP_XfOrM380(_), scheme_register_static ((void * ) & nested_exn_handler , sizeof (nested_exn_handler ) ) ); 
    nested_exn_handler = FUNCCALL(SETUP_XfOrM380(_), scheme_make_prim_w_arity (def_nested_exn_handler , "nested-thread-exception-handler" , 1 , 1 ) ); 
  }
  FUNCCALL(SETUP_XfOrM373(_), scheme_set_cont_mark (scheme_exn_handler_key , nested_exn_handler ) ); 
  np -> error_buf = & newbuf ; 
  if (((newbuf ) . gcvs = (long ) __gc_var_stack__ , (newbuf ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((newbuf ) . jb ) , (_setjmp (((newbuf ) . jb ) -> jb ) ) ) ) ) {
    if (! np -> cjs . is_kill )
      v = np -> cjs . val ; 
    else v = ((void * ) 0 ) ; 
    failure = 1 ; 
  }
  else {
#   define XfOrM378_COUNT (0+XfOrM373_COUNT)
#   define SETUP_XfOrM378(x) SETUP_XfOrM373(x)
    v = FUNCCALL(SETUP_XfOrM378(_), scheme_apply (argv [0 ] , 0 , ((void * ) 0 ) ) ); 
    failure = 0 ; 
  }
  FUNCCALL(SETUP_XfOrM373(_), scheme_remove_managed (np -> mref , (Scheme_Object * ) np -> mr_hop ) ); 
  {
    Scheme_Object * l ; 
    BLOCK_SETUP((PUSH(l, 0+XfOrM373_COUNT)));
#   define XfOrM375_COUNT (1+XfOrM373_COUNT)
#   define SETUP_XfOrM375(x) SETUP(XfOrM375_COUNT)
    l = NULLED_OUT ; 
    for (l = np -> extra_mrefs ; ! ((l ) == (scheme_null ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#     define XfOrM377_COUNT (0+XfOrM375_COUNT)
#     define SETUP_XfOrM377(x) SETUP_XfOrM375(x)
      FUNCCALL(SETUP_XfOrM377(_), scheme_remove_managed ((Scheme_Custodian_Reference * ) (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) , (Scheme_Object * ) np -> mr_hop ) ); 
    }
  }
  np -> extra_mrefs = scheme_null ; 
  (((Scheme_Small_Object * ) (np -> mr_hop -> p ) ) -> u . ptr_val ) = ((void * ) 0 ) ; 
  FUNCCALL(SETUP_XfOrM373(_), scheme_remove_all_finalization (np -> mr_hop ) ); 
  if (np -> prev )
    np -> prev -> next = np -> next ; 
  else scheme_first_thread = np -> next ; 
  np -> next -> prev = np -> prev ; 
  np -> next = ((void * ) 0 ) ; 
  np -> prev = ((void * ) 0 ) ; 
  FUNCCALL(SETUP_XfOrM373(_), unschedule_in_set ((Scheme_Object * ) np , np -> t_set_parent ) ); 
  np -> running = 0 ; 
  * p -> runstack_owner = p ; 
  p -> external_break = np -> external_break ; 
  p -> nestee = ((void * ) 0 ) ; 
  np -> nester = ((void * ) 0 ) ; 
  FUNCCALL(SETUP_XfOrM373(_), thread_is_dead (np ) ); 
  scheme_current_thread = p ; 
  if (p != scheme_main_thread )
    FUNCCALL(SETUP_XfOrM373(_), scheme_weak_resume_thread (p ) ); 
  scheme_current_cont_mark_stack = p -> cont_mark_stack ; 
  scheme_current_cont_mark_pos = p -> cont_mark_pos ; 
  if ((p -> running & 0x4 ) || (p -> running & 0x10 ) )
    FUNCCALL(SETUP_XfOrM373(_), scheme_thread_block (0.0 ) ); 
  if (failure ) {
#   define XfOrM374_COUNT (0+XfOrM373_COUNT)
#   define SETUP_XfOrM374(x) SETUP_XfOrM373(x)
    if (! v )
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL , "call-in-nested-thread: the thread was killed, or it exited via the default error escape handler" ) ); 
    else FUNCCALL(SETUP_XfOrM374(_), scheme_raise (v ) ); 
  }
  FUNCCALL(SETUP_XfOrM373(_), scheme_check_break_now () ); 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * call_as_nested_thread (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * result ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(result, 0)));
# define XfOrM392_COUNT (1)
# define SETUP_XfOrM392(x) SETUP(XfOrM392_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  result = NULLED_OUT ; 
  result = FUNCCALL(SETUP_XfOrM392(_), scheme_call_as_nested_thread (argc , argv , & __gc_var_stack__ ) ); 
  RET_VALUE_START (result ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int check_sleep (int need_activity , int sleep_now ) {
  Scheme_Thread * p , * p2 ; 
  int end_with_act ; 
  static fd_set * set ; 
  fd_set * set1 , * set2 ; 
  void * fds ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(set1, 0), PUSH(fds, 1), PUSH(p, 2), PUSH(set2, 3)));
# define XfOrM393_COUNT (4)
# define SETUP_XfOrM393(x) SETUP(XfOrM393_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  p = NULLED_OUT ; 
  p2 = NULLED_OUT ; 
  set1 = NULLED_OUT ; 
  set2 = NULLED_OUT ; 
  fds = NULLED_OUT ; 
  if (! do_atomic ) {
    p = scheme_first_thread ; 
    while (p ) {
      if (! p -> nestee && (p -> ran_some || p -> block_descriptor == 0 ) && (p -> next || ! (p -> running & 0x10 ) ) )
        break ; 
      p = p -> next ; 
    }
  }
  else p = ((void * ) 0 ) ; 
  p2 = scheme_first_thread ; 
  while (p2 ) {
    p2 -> ran_some = 0 ; 
    p2 = p2 -> next ; 
  }
  end_with_act = thread_ended_with_activity ; 
  thread_ended_with_activity = 0 ; 
  if (need_activity && ! end_with_act && (do_atomic || (! p && ((! sleep_now && scheme_wakeup_on_input ) || (sleep_now && scheme_sleep ) ) ) ) ) {
    double max_sleep_time = 0 ; 
#   define XfOrM394_COUNT (0+XfOrM393_COUNT)
#   define SETUP_XfOrM394(x) SETUP_XfOrM393(x)
    if (have_activity )
      scheme_active_but_sleeping = 1 ; 
    if (have_activity && scheme_notify_multithread )
      FUNCCALL(SETUP_XfOrM394(_), scheme_notify_multithread (0 ) ); 
    (set = (set ? (fd_set * ) FUNCCALL(SETUP_XfOrM394(_), scheme_init_fdset_array (set , 3 ) ): (fd_set * ) FUNCCALL(SETUP_XfOrM394(_), scheme_alloc_fdset_array (3 , 1 ) )) ) ; 
    set1 = (fd_set * ) FUNCCALL(SETUP_XfOrM394(_), scheme_get_fdset (set , 1 ) ); 
    set2 = (fd_set * ) FUNCCALL(SETUP_XfOrM394(_), scheme_get_fdset (set , 2 ) ); 
    fds = (void * ) set ; 
    FUNCCALL(SETUP_XfOrM394(_), scheme_fdzero (set ) ); 
    FUNCCALL_AGAIN(scheme_fdzero (set1 ) ); 
    FUNCCALL_AGAIN(scheme_fdzero (set2 ) ); 
    needs_sleep_cancelled = 0 ; 
    p = scheme_first_thread ; 
    while (p ) {
      int merge_time = 0 ; 
#     define XfOrM405_COUNT (0+XfOrM394_COUNT)
#     define SETUP_XfOrM405(x) SETUP_XfOrM394(x)
      if (p -> nestee ) {
      }
      else if (p -> block_descriptor == - 1 ) {
#       define XfOrM409_COUNT (0+XfOrM405_COUNT)
#       define SETUP_XfOrM409(x) SETUP_XfOrM405(x)
        if (p -> block_needs_wakeup ) {
          Scheme_Needs_Wakeup_Fun f = p -> block_needs_wakeup ; 
#         define XfOrM410_COUNT (0+XfOrM409_COUNT)
#         define SETUP_XfOrM410(x) SETUP_XfOrM409(x)
          FUNCCALL(SETUP_XfOrM410(_), f (p -> blocker , fds ) ); 
        }
        merge_time = (p -> sleep_end > 0.0 ) ; 
      }
      else if (p -> block_descriptor == 1 ) {
        merge_time = 1 ; 
      }
      if (merge_time ) {
        double d = p -> sleep_end ; 
        double t ; 
#       define XfOrM406_COUNT (0+XfOrM405_COUNT)
#       define SETUP_XfOrM406(x) SETUP_XfOrM405(x)
        d = (d - FUNCCALL(SETUP_XfOrM406(_), scheme_get_inexact_milliseconds () )) ; 
        t = (d / 1000 ) ; 
        if (t <= 0 ) {
          t = (float ) 0.00001 ; 
          needs_sleep_cancelled = 1 ; 
        }
        if (! max_sleep_time || (t < max_sleep_time ) )
          max_sleep_time = t ; 
      }
      p = p -> next ; 
    }
    if (needs_sleep_cancelled )
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    if (FUNCCALL(SETUP_XfOrM394(_), post_system_idle () )) {
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    if (sleep_now ) {
      float mst = (float ) max_sleep_time ; 
#     define XfOrM395_COUNT (0+XfOrM394_COUNT)
#     define SETUP_XfOrM395(x) SETUP_XfOrM394(x)
      if ((double ) mst > (2 * max_sleep_time ) ) {
        mst = 100000000.0 ; 
      }
      FUNCCALL(SETUP_XfOrM395(_), scheme_sleep (mst , fds ) ); 
    }
    else if (scheme_wakeup_on_input )
      FUNCCALL_EMPTY(scheme_wakeup_on_input (fds ) ); 
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  }
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int post_system_idle () {
  /* No conversion */
  return scheme_try_channel_get (scheme_system_idle_channel ) ; 
}
void scheme_cancel_sleep () {
  /* No conversion */
  needs_sleep_cancelled = 1 ; 
}
void scheme_check_threads (void ) {
  /* No conversion */
  scheme_current_thread -> suspend_break ++ ; 
  scheme_thread_block ((float ) 0 ) ; 
  -- scheme_current_thread -> suspend_break ; 
  check_sleep (have_activity , 0 ) ; 
}
void scheme_wake_up (void ) {
  /* No conversion */
  scheme_active_but_sleeping = 0 ; 
  if (have_activity && scheme_notify_multithread )
    scheme_notify_multithread (1 ) ; 
}
void scheme_out_of_fuel (void ) {
  /* No conversion */
  scheme_thread_block ((float ) 0 ) ; 
  scheme_current_thread -> ran_some = 1 ; 
}
static int itimer_handler_installed = 0 ; 
static void timer_expired (int ignored ) {
  scheme_fuel_counter = 0 ; 
  signal (27 , timer_expired ) ; 
}
static void init_schedule_info (Scheme_Schedule_Info * sinfo , Scheme_Thread * false_pos_ok , double sleep_end ) {
  /* No conversion */
  sinfo -> false_positive_ok = false_pos_ok ; 
  sinfo -> potentially_false_positive = 0 ; 
  sinfo -> current_syncing = ((void * ) 0 ) ; 
  sinfo -> spin = 0 ; 
  sinfo -> is_poll = 0 ; 
  sinfo -> sleep_end = sleep_end ; 
}
Scheme_Object * scheme_current_break_cell () {
  /* No conversion */
  return scheme_extract_one_cc_mark (((void * ) 0 ) , scheme_break_enabled_key ) ; 
}
static int can_break_param (Scheme_Thread * p ) {
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(p, 0)));
# define XfOrM424_COUNT (1)
# define SETUP_XfOrM424(x) SETUP(XfOrM424_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (p == scheme_current_thread ) {
    Scheme_Object * v ; 
    BLOCK_SETUP((PUSH(v, 0+XfOrM424_COUNT)));
#   define XfOrM425_COUNT (1+XfOrM424_COUNT)
#   define SETUP_XfOrM425(x) SETUP(XfOrM425_COUNT)
    v = NULLED_OUT ; 
    v = FUNCCALL(SETUP_XfOrM425(_), scheme_extract_one_cc_mark (((void * ) 0 ) , scheme_break_enabled_key ) ); 
    v = FUNCCALL_AGAIN(scheme_thread_cell_get (v , p -> cell_values ) ); 
    RET_VALUE_START ((! (((v ) ) == (scheme_false ) ) ) ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (p -> can_break_at_swap ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_can_break (Scheme_Thread * p ) {
  /* No conversion */
  if (! p -> suspend_break ) {
    return can_break_param (p ) ; 
  }
  else return 0 ; 
}
void scheme_set_can_break (int on ) {
  Scheme_Object * v ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(v, 0)));
# define XfOrM428_COUNT (1)
# define SETUP_XfOrM428(x) SETUP(XfOrM428_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  v = FUNCCALL(SETUP_XfOrM428(_), scheme_extract_one_cc_mark (((void * ) 0 ) , scheme_break_enabled_key ) ); 
  FUNCCALL_AGAIN(scheme_thread_cell_set (v , scheme_current_thread -> cell_values , (on ? scheme_true : scheme_false ) ) ); 
  if (((v ) == (maybe_recycle_cell ) ) )
    maybe_recycle_cell = ((void * ) 0 ) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_check_break_now (void ) {
  Scheme_Thread * p = scheme_current_thread ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(p, 0)));
# define XfOrM429_COUNT (1)
# define SETUP_XfOrM429(x) SETUP(XfOrM429_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (p -> external_break && FUNCCALL(SETUP_XfOrM429(_), scheme_can_break (p ) )) {
#   define XfOrM430_COUNT (0+XfOrM429_COUNT)
#   define SETUP_XfOrM430(x) SETUP_XfOrM429(x)
    FUNCCALL(SETUP_XfOrM430(_), scheme_thread_block (0.0 ) ); 
    p -> ran_some = 1 ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * check_break_now (int argc , Scheme_Object * args [] ) {
  /* No conversion */
  scheme_check_break_now () ; 
  return scheme_void ; 
}
void scheme_push_break_enable (Scheme_Cont_Frame_Data * cframe , int on , int post_check ) {
  Scheme_Object * v = ((void * ) 0 ) ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(cframe, 1)));
# define XfOrM432_COUNT (2)
# define SETUP_XfOrM432(x) SETUP(XfOrM432_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (recycle_cell ) {
    if (! (! (((((Thread_Cell * ) recycle_cell ) -> def_val ) ) == (scheme_false ) ) ) == ! on ) {
      v = recycle_cell ; 
      recycle_cell = ((void * ) 0 ) ; 
    }
  }
  if (! v )
    v = FUNCCALL(SETUP_XfOrM432(_), scheme_make_thread_cell (on ? scheme_true : scheme_false , 1 ) ); 
  FUNCCALL(SETUP_XfOrM432(_), scheme_push_continuation_frame (cframe ) ); 
  FUNCCALL_AGAIN(scheme_set_cont_mark (scheme_break_enabled_key , v ) ); 
  if (post_check )
    FUNCCALL(SETUP_XfOrM432(_), scheme_check_break_now () ); 
  cframe -> cache = v ; 
  maybe_recycle_cell = v ; 
  recycle_cc_count = scheme_cont_capture_count ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_pop_break_enable (Scheme_Cont_Frame_Data * cframe , int post_check ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(cframe, 0)));
# define XfOrM435_COUNT (1)
# define SETUP_XfOrM435(x) SETUP(XfOrM435_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM435(_), scheme_pop_continuation_frame (cframe ) ); 
  if (post_check )
    FUNCCALL(SETUP_XfOrM435(_), scheme_check_break_now () ); 
  if (cframe -> cache == maybe_recycle_cell ) {
    if (recycle_cc_count == scheme_cont_capture_count ) {
      recycle_cell = maybe_recycle_cell ; 
    }
    maybe_recycle_cell = ((void * ) 0 ) ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * raise_user_break (int argc , Scheme_Object * * volatile argv ) {
  mz_jmp_buf * savebuf , newbuf ; 
  long save [4 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(savebuf, 0), PUSH(argv, 1)));
# define XfOrM438_COUNT (2)
# define SETUP_XfOrM438(x) SETUP(XfOrM438_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  savebuf = NULLED_OUT ; 
  savebuf = scheme_current_thread -> error_buf ; 
  scheme_current_thread -> error_buf = & newbuf ; 
  FUNCCALL(SETUP_XfOrM438(_), scheme_gmp_tls_snapshot (scheme_current_thread -> gmp_tls , save ) ); 
  if (! ((newbuf ) . gcvs = (long ) __gc_var_stack__ , (newbuf ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((newbuf ) . jb ) , (_setjmp (((newbuf ) . jb ) -> jb ) ) ) ) ) {
#   define XfOrM440_COUNT (0+XfOrM438_COUNT)
#   define SETUP_XfOrM440(x) SETUP_XfOrM438(x)
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_BREAK , argv [0 ] , "user break" ) ); 
  }
  else {
    int cont ; 
#   define XfOrM439_COUNT (0+XfOrM438_COUNT)
#   define SETUP_XfOrM439(x) SETUP_XfOrM438(x)
    cont = (((Scheme_Object * ) (scheme_current_thread -> cjs . jumping_to_continuation ) ) == (argv [0 ] ) ) ; 
    FUNCCALL(SETUP_XfOrM439(_), scheme_gmp_tls_restore_snapshot (scheme_current_thread -> gmp_tls , save , ! cont ) ); 
    (((long * ) (void * ) ((* savebuf ) . gcvs ) ) [1 ] = (* savebuf ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* savebuf ) . gcvs , scheme_jit_longjmp ((* savebuf ) . jb , 1 ) ) ; 
  }
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void raise_break (Scheme_Thread * p ) {
  int block_descriptor ; 
  Scheme_Object * blocker ; 
  Scheme_Ready_Fun block_check ; 
  Scheme_Needs_Wakeup_Fun block_needs_wakeup ; 
  Scheme_Object * a [1 ] ; 
  Scheme_Cont_Frame_Data cframe ; 
  PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(blocker, 0), PUSHARRAY(a, 1, 1), PUSH(cframe.cache, 4), PUSH(p, 5)));
# define XfOrM441_COUNT (6)
# define SETUP_XfOrM441(x) SETUP(XfOrM441_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  blocker = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  cframe.cache = NULLED_OUT ; 
  p -> external_break = 0 ; 
  block_descriptor = p -> block_descriptor ; 
  blocker = p -> blocker ; 
  block_check = p -> block_check ; 
  block_needs_wakeup = p -> block_needs_wakeup ; 
  p -> block_descriptor = 0 ; 
  p -> blocker = ((void * ) 0 ) ; 
  p -> block_check = ((void * ) 0 ) ; 
  p -> block_needs_wakeup = ((void * ) 0 ) ; 
  p -> ran_some = 1 ; 
  a [0 ] = FUNCCALL(SETUP_XfOrM441(_), scheme_make_prim ((Scheme_Prim * ) raise_user_break ) ); 
  FUNCCALL(SETUP_XfOrM441(_), scheme_push_continuation_frame (& cframe ) ); 
  FUNCCALL_AGAIN(scheme_call_ec (1 , a ) ); 
  FUNCCALL_AGAIN(scheme_pop_continuation_frame (& cframe ) ); 
  p -> block_descriptor = block_descriptor ; 
  p -> blocker = blocker ; 
  p -> block_check = block_check ; 
  p -> block_needs_wakeup = block_needs_wakeup ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void exit_or_escape (Scheme_Thread * p ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(p, 0)));
# define XfOrM442_COUNT (1)
# define SETUP_XfOrM442(x) SETUP(XfOrM442_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (p -> nester ) {
    if (p -> running & 0x4 )
      p -> running -= 0x4 ; 
    p -> cjs . jumping_to_continuation = (Scheme_Object * ) p ; 
    p -> cjs . is_kill = 1 ; 
    (((long * ) (void * ) ((* p -> error_buf ) . gcvs ) ) [1 ] = (* p -> error_buf ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* p -> error_buf ) . gcvs , scheme_jit_longjmp ((* p -> error_buf ) . jb , 1 ) ) ; 
  }
  if (((p ) == (scheme_main_thread ) ) ) {
#   define XfOrM443_COUNT (0+XfOrM442_COUNT)
#   define SETUP_XfOrM443(x) SETUP_XfOrM442(x)
    if (scheme_exit )
      FUNCCALL(SETUP_XfOrM443(_), scheme_exit (0 ) ); 
    FUNCCALL_EMPTY(exit (0 ) ); 
  }
  FUNCCALL_EMPTY(remove_thread (p ) ); 
  FUNCCALL_EMPTY(select_thread () ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_break_thread (Scheme_Thread * p ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(p, 0)));
# define XfOrM445_COUNT (1)
# define SETUP_XfOrM445(x) SETUP(XfOrM445_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (delay_breaks ) {
    delayed_break_ready = 1 ; 
    RET_NOTHING ; 
  }
  if (! p ) {
    p = scheme_main_thread ; 
    if (! p )
      RET_NOTHING ; 
  }
  while (p -> nestee ) {
    p = p -> nestee ; 
  }
  p -> external_break = 1 ; 
  if (p == scheme_current_thread ) {
#   define XfOrM446_COUNT (0+XfOrM445_COUNT)
#   define SETUP_XfOrM446(x) SETUP_XfOrM445(x)
    if (FUNCCALL(SETUP_XfOrM446(_), scheme_can_break (p ) ))
      scheme_fuel_counter = 0 ; 
  }
  FUNCCALL_EMPTY(scheme_weak_resume_thread (p ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_thread_block (float sleep_time ) {
  double sleep_end ; 
  Scheme_Thread * next , * p = scheme_current_thread ; 
  Scheme_Object * next_in_set ; 
  Scheme_Thread_Set * t_set ; 
  PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(next_in_set, 0), PUSH(t_set, 1), PUSH(p, 2), PUSH(next, 3)));
# define XfOrM451_COUNT (4)
# define SETUP_XfOrM451(x) SETUP(XfOrM451_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  next = NULLED_OUT ; 
  next_in_set = NULLED_OUT ; 
  t_set = NULLED_OUT ; 
  if (p -> running & 0x4 ) {
#   define XfOrM531_COUNT (0+XfOrM451_COUNT)
#   define SETUP_XfOrM531(x) SETUP_XfOrM451(x)
    if (! do_atomic )
      FUNCCALL(SETUP_XfOrM531(_), exit_or_escape (p ) ); 
  }
  if ((p -> running & 0x10 ) && ! (p -> running & 0x20 ) ) {
#   define XfOrM529_COUNT (0+XfOrM451_COUNT)
#   define SETUP_XfOrM529(x) SETUP_XfOrM451(x)
    FUNCCALL(SETUP_XfOrM529(_), wait_until_suspend_ok () ); 
    if (! p -> next ) {
#     define XfOrM530_COUNT (0+XfOrM529_COUNT)
#     define SETUP_XfOrM530(x) SETUP_XfOrM529(x)
      FUNCCALL(SETUP_XfOrM530(_), select_thread () ); 
    }
    else FUNCCALL(SETUP_XfOrM529(_), scheme_weak_suspend_thread (p ) ); 
  }
  FUNCCALL(SETUP_XfOrM451(_), check_scheduled_kills () ); 
  ; 
  if (scheme_active_but_sleeping )
    FUNCCALL(SETUP_XfOrM451(_), scheme_wake_up () ); 
  if (sleep_time > 0 ) {
#   define XfOrM528_COUNT (0+XfOrM451_COUNT)
#   define SETUP_XfOrM528(x) SETUP_XfOrM451(x)
    sleep_end = FUNCCALL(SETUP_XfOrM528(_), scheme_get_inexact_milliseconds () ); 
    sleep_end += (sleep_time * 1000.0 ) ; 
  }
  else sleep_end = 0 ; 
  start_sleep_check : if (! p -> external_break && ! p -> next && scheme_check_for_break && FUNCCALL(SETUP_XfOrM451(_), scheme_check_for_break () ))
    p -> external_break = 1 ; 
  if (p -> external_break && ! p -> suspend_break && FUNCCALL(SETUP_XfOrM451(_), scheme_can_break (p ) )) {
#   define XfOrM527_COUNT (0+XfOrM451_COUNT)
#   define SETUP_XfOrM527(x) SETUP_XfOrM451(x)
    FUNCCALL(SETUP_XfOrM527(_), raise_break (p ) ); 
    goto start_sleep_check ; 
  }
  swap_or_sleep : FUNCCALL(SETUP_XfOrM451(_), check_scheduled_kills () ); 
  if (! do_atomic && (sleep_end >= 0.0 ) ) {
    double msecs = 0.0 ; 
#   define XfOrM476_COUNT (0+XfOrM451_COUNT)
#   define SETUP_XfOrM476(x) SETUP_XfOrM451(x)
    next_in_set = (Scheme_Object * ) thread_set_top ; 
    t_set = ((void * ) 0 ) ; 
    while (1 ) {
#     define XfOrM502_COUNT (0+XfOrM476_COUNT)
#     define SETUP_XfOrM502(x) SETUP_XfOrM476(x)
      while (! ((Scheme_Type ) (((((long ) (next_in_set ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (next_in_set ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_type ) ) ) {
#       define XfOrM526_COUNT (0+XfOrM502_COUNT)
#       define SETUP_XfOrM526(x) SETUP_XfOrM502(x)
        t_set = (Scheme_Thread_Set * ) next_in_set ; 
        next_in_set = FUNCCALL(SETUP_XfOrM526(_), get_t_set_next (t_set -> current ) ); 
        if (! next_in_set )
          next_in_set = t_set -> first ; 
        t_set -> current = next_in_set ; 
        t_set -> search_start = next_in_set ; 
      }
      next = (Scheme_Thread * ) next_in_set ; 
      if (((next ) == (p ) ) ) {
        next = ((void * ) 0 ) ; 
        break ; 
      }
      if (next -> nestee ) {
      }
      else if (next -> running & 0x10 ) {
        if (next -> next || (next -> running & 0x20 ) ) {
          break ; 
        }
      }
      else if (next -> running & 0x4 ) {
#       define XfOrM519_COUNT (0+XfOrM502_COUNT)
#       define SETUP_XfOrM519(x) SETUP_XfOrM502(x)
        if ((next -> running & 0x8 ) || next -> nester || ! next -> next ) {
          break ; 
        }
        else FUNCCALL(SETUP_XfOrM519(_), remove_thread (next ) ); 
        break ; 
      }
      else if (next -> external_break && FUNCCALL(SETUP_XfOrM502(_), scheme_can_break (next ) )) {
        break ; 
      }
      else {
#       define XfOrM514_COUNT (0+XfOrM502_COUNT)
#       define SETUP_XfOrM514(x) SETUP_XfOrM502(x)
        if (next -> block_descriptor == - 1 ) {
#         define XfOrM516_COUNT (0+XfOrM514_COUNT)
#         define SETUP_XfOrM516(x) SETUP_XfOrM514(x)
          if (next -> block_check ) {
            Scheme_Ready_Fun_FPC f = (Scheme_Ready_Fun_FPC ) next -> block_check ; 
            Scheme_Schedule_Info sinfo ; 
            BLOCK_SETUP((PUSH(sinfo.false_positive_ok, 0+XfOrM516_COUNT), PUSH(sinfo.current_syncing, 1+XfOrM516_COUNT)));
#           define XfOrM517_COUNT (2+XfOrM516_COUNT)
#           define SETUP_XfOrM517(x) SETUP(XfOrM517_COUNT)
            sinfo.false_positive_ok = NULLED_OUT ; 
            sinfo.current_syncing = NULLED_OUT ; 
            FUNCCALL(SETUP_XfOrM517(_), init_schedule_info (& sinfo , next , next -> sleep_end ) ); 
            if (FUNCCALL(SETUP_XfOrM517(_), f (next -> blocker , & sinfo ) ))
              break ; 
            next -> sleep_end = sinfo . sleep_end ; 
            msecs = 0.0 ; 
          }
        }
        else if (next -> block_descriptor == 1 ) {
#         define XfOrM515_COUNT (0+XfOrM514_COUNT)
#         define SETUP_XfOrM515(x) SETUP_XfOrM514(x)
          if (! msecs )
            msecs = FUNCCALL(SETUP_XfOrM515(_), scheme_get_inexact_milliseconds () ); 
          if (next -> sleep_end <= msecs )
            break ; 
        }
        else break ; 
      }
      if (next -> t_set_next )
        next_in_set = next -> t_set_next ; 
      else next_in_set = t_set -> first ; 
      if (((next_in_set ) == (t_set -> search_start ) ) ) {
#       define XfOrM504_COUNT (0+XfOrM502_COUNT)
#       define SETUP_XfOrM504(x) SETUP_XfOrM502(x)
        while (1 ) {
#         define XfOrM510_COUNT (0+XfOrM504_COUNT)
#         define SETUP_XfOrM510(x) SETUP_XfOrM504(x)
          t_set -> search_start = ((void * ) 0 ) ; 
          t_set = t_set -> parent ; 
          if (t_set ) {
#           define XfOrM511_COUNT (0+XfOrM510_COUNT)
#           define SETUP_XfOrM511(x) SETUP_XfOrM510(x)
            next_in_set = FUNCCALL(SETUP_XfOrM511(_), get_t_set_next (t_set -> current ) ); 
            if (! next_in_set )
              next_in_set = t_set -> first ; 
            if (((next_in_set ) == (t_set -> search_start ) ) ) {
              t_set -> search_start = ((void * ) 0 ) ; 
            }
            else {
              t_set -> current = next_in_set ; 
              break ; 
            }
          }
          else break ; 
        }
        if (! t_set ) {
          next = ((void * ) 0 ) ; 
          break ; 
        }
      }
      else {
        t_set -> current = next_in_set ; 
      }
    }
  }
  else next = ((void * ) 0 ) ; 
  if (next ) {
    t_set = next -> t_set_parent ; 
    while (t_set ) {
      t_set -> search_start = ((void * ) 0 ) ; 
      t_set = t_set -> parent ; 
    }
  }
  if ((sleep_end > 0.0 ) && (p -> block_descriptor == 0 ) ) {
    p -> block_descriptor = 1 ; 
    p -> sleep_end = sleep_end ; 
  }
  else if ((sleep_end > 0.0 ) && (p -> block_descriptor == - 1 ) ) {
    p -> sleep_end = sleep_end ; 
  }
  if (next && (! next -> running || (next -> running & 0x2 ) ) ) {
    next = ((void * ) 0 ) ; 
  }
  if (next ) {
#   define XfOrM469_COUNT (0+XfOrM451_COUNT)
#   define SETUP_XfOrM469(x) SETUP_XfOrM451(x)
    next_in_set = ((void * ) 0 ) ; 
    t_set = ((void * ) 0 ) ; 
    swap_target = next ; 
    next = ((void * ) 0 ) ; 
    FUNCCALL(SETUP_XfOrM469(_), do_swap_thread () ); 
  }
  else if (do_atomic && scheme_on_atomic_timeout ) {
#   define XfOrM468_COUNT (0+XfOrM451_COUNT)
#   define SETUP_XfOrM468(x) SETUP_XfOrM451(x)
    FUNCCALL(SETUP_XfOrM468(_), scheme_on_atomic_timeout () ); 
  }
  else {
#   define XfOrM466_COUNT (0+XfOrM451_COUNT)
#   define SETUP_XfOrM466(x) SETUP_XfOrM451(x)
    if (p -> block_descriptor != 0 ) {
#     define XfOrM467_COUNT (0+XfOrM466_COUNT)
#     define SETUP_XfOrM467(x) SETUP_XfOrM466(x)
      FUNCCALL(SETUP_XfOrM467(_), check_sleep (1 , 1 ) ); 
    }
  }
  if (p -> block_descriptor == 1 ) {
    p -> block_descriptor = 0 ; 
  }
  p -> sleep_end = 0.0 ; 
  if (p -> running & 0x4 ) {
#   define XfOrM462_COUNT (0+XfOrM451_COUNT)
#   define SETUP_XfOrM462(x) SETUP_XfOrM451(x)
    if (p -> running & 0x8 ) {
      RET_NOTHING ; 
    }
    else {
#     define XfOrM463_COUNT (0+XfOrM462_COUNT)
#     define SETUP_XfOrM463(x) SETUP_XfOrM462(x)
      if (! do_atomic )
        FUNCCALL(SETUP_XfOrM463(_), exit_or_escape (p ) ); 
    }
  }
  if ((p -> running & 0x10 ) && ! (p -> running & 0x20 ) ) {
#   define XfOrM461_COUNT (0+XfOrM451_COUNT)
#   define SETUP_XfOrM461(x) SETUP_XfOrM451(x)
    FUNCCALL(SETUP_XfOrM461(_), wait_until_suspend_ok () ); 
    if (! p -> next )
      FUNCCALL(SETUP_XfOrM461(_), scheme_thread_block (0.0 ) ); 
    else FUNCCALL(SETUP_XfOrM461(_), scheme_weak_suspend_thread (p ) ); 
  }
  if (p -> external_break && ! p -> suspend_break && FUNCCALL(SETUP_XfOrM451(_), scheme_can_break (p ) )) {
#   define XfOrM460_COUNT (0+XfOrM451_COUNT)
#   define SETUP_XfOrM460(x) SETUP_XfOrM451(x)
    FUNCCALL(SETUP_XfOrM460(_), raise_break (p ) ); 
  }
  if (sleep_end > 0 ) {
#   define XfOrM454_COUNT (0+XfOrM451_COUNT)
#   define SETUP_XfOrM454(x) SETUP_XfOrM451(x)
    if (sleep_end > FUNCCALL(SETUP_XfOrM454(_), scheme_get_inexact_milliseconds () )) {
#     define XfOrM455_COUNT (0+XfOrM454_COUNT)
#     define SETUP_XfOrM455(x) SETUP_XfOrM454(x)
      if (p -> block_descriptor == - 1 ) {
#       define XfOrM456_COUNT (0+XfOrM455_COUNT)
#       define SETUP_XfOrM456(x) SETUP_XfOrM455(x)
        if (p -> block_check ) {
          Scheme_Ready_Fun_FPC f = (Scheme_Ready_Fun_FPC ) p -> block_check ; 
          Scheme_Schedule_Info sinfo ; 
          BLOCK_SETUP((PUSH(sinfo.false_positive_ok, 0+XfOrM456_COUNT), PUSH(sinfo.current_syncing, 1+XfOrM456_COUNT)));
#         define XfOrM457_COUNT (2+XfOrM456_COUNT)
#         define SETUP_XfOrM457(x) SETUP(XfOrM457_COUNT)
          sinfo.false_positive_ok = NULLED_OUT ; 
          sinfo.current_syncing = NULLED_OUT ; 
          FUNCCALL(SETUP_XfOrM457(_), init_schedule_info (& sinfo , p , sleep_end ) ); 
          if (FUNCCALL(SETUP_XfOrM457(_), f (p -> blocker , & sinfo ) )) {
            sleep_end = 0 ; 
          }
          else {
            sleep_end = sinfo . sleep_end ; 
          }
        }
      }
      if (sleep_end > 0 )
        goto swap_or_sleep ; 
    }
  }
  if (do_atomic )
    missed_context_switch = 1 ; 
  scheme_fuel_counter = p -> engine_weight ; 
  {
    struct itimerval t , old ; 
#   define XfOrM452_COUNT (0+XfOrM451_COUNT)
#   define SETUP_XfOrM452(x) SETUP_XfOrM451(x)
    if (! itimer_handler_installed ) {
#     define XfOrM453_COUNT (0+XfOrM452_COUNT)
#     define SETUP_XfOrM453(x) SETUP_XfOrM452(x)
      itimer_handler_installed = 1 ; 
      FUNCCALL_EMPTY(signal (27 , timer_expired ) ); 
    }
    t . it_value . tv_sec = 0 ; 
    t . it_value . tv_usec = 10000 ; 
    t . it_interval . tv_sec = 0 ; 
    t . it_interval . tv_usec = 0 ; 
    FUNCCALL_EMPTY(setitimer (ITIMER_PROF , & t , & old ) ); 
  }
  FUNCCALL_EMPTY(check_scheduled_kills () ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_making_progress () {
  /* No conversion */
  scheme_current_thread -> ran_some = 1 ; 
}
int scheme_block_until (Scheme_Ready_Fun _f , Scheme_Needs_Wakeup_Fun fdf , Scheme_Object * data , float delay ) {
  int result ; 
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Ready_Fun_FPC f = (Scheme_Ready_Fun_FPC ) _f ; 
  Scheme_Schedule_Info sinfo ; 
  double sleep_end ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(data, 0), PUSH(p, 1), PUSH(sinfo.false_positive_ok, 2), PUSH(sinfo.current_syncing, 3)));
# define XfOrM533_COUNT (4)
# define SETUP_XfOrM533(x) SETUP(XfOrM533_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sinfo.false_positive_ok = NULLED_OUT ; 
  sinfo.current_syncing = NULLED_OUT ; 
  if (! delay )
    sleep_end = 0.0 ; 
  else {
#   define XfOrM542_COUNT (0+XfOrM533_COUNT)
#   define SETUP_XfOrM542(x) SETUP_XfOrM533(x)
    sleep_end = FUNCCALL(SETUP_XfOrM542(_), scheme_get_inexact_milliseconds () ); 
    sleep_end += (delay * 1000.0 ) ; 
  }
  FUNCCALL(SETUP_XfOrM533(_), init_schedule_info (& sinfo , ((void * ) 0 ) , sleep_end ) ); 
  while (! (result = FUNCCALL(SETUP_XfOrM533(_), f ((Scheme_Object * ) data , & sinfo ) )) ) {
#   define XfOrM538_COUNT (0+XfOrM533_COUNT)
#   define SETUP_XfOrM538(x) SETUP_XfOrM533(x)
    sleep_end = sinfo . sleep_end ; 
    if (sinfo . spin ) {
#     define XfOrM541_COUNT (0+XfOrM538_COUNT)
#     define SETUP_XfOrM541(x) SETUP_XfOrM538(x)
      FUNCCALL(SETUP_XfOrM541(_), init_schedule_info (& sinfo , ((void * ) 0 ) , 0.0 ) ); 
      FUNCCALL(SETUP_XfOrM541(_), scheme_thread_block (0.0 ) ); 
      scheme_current_thread -> ran_some = 1 ; 
    }
    else {
#     define XfOrM539_COUNT (0+XfOrM538_COUNT)
#     define SETUP_XfOrM539(x) SETUP_XfOrM538(x)
      if (sleep_end ) {
#       define XfOrM540_COUNT (0+XfOrM539_COUNT)
#       define SETUP_XfOrM540(x) SETUP_XfOrM539(x)
        delay = (float ) (sleep_end - FUNCCALL(SETUP_XfOrM540(_), scheme_get_inexact_milliseconds () )) ; 
        delay /= 1000.0 ; 
        if (delay < 0 )
          delay = (float ) 0.00001 ; 
      }
      else delay = 0.0 ; 
      p -> block_descriptor = - 1 ; 
      p -> blocker = (Scheme_Object * ) data ; 
      p -> block_check = (Scheme_Ready_Fun ) f ; 
      p -> block_needs_wakeup = fdf ; 
      FUNCCALL(SETUP_XfOrM539(_), scheme_thread_block (delay ) ); 
      p -> block_descriptor = 0 ; 
      p -> blocker = ((void * ) 0 ) ; 
      p -> block_check = ((void * ) 0 ) ; 
      p -> block_needs_wakeup = ((void * ) 0 ) ; 
    }
  }
  p -> ran_some = 1 ; 
  RET_VALUE_START (result ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_block_until_enable_break (Scheme_Ready_Fun _f , Scheme_Needs_Wakeup_Fun fdf , Scheme_Object * data , float delay , int enable_break ) {
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(data, 0)));
# define XfOrM543_COUNT (1)
# define SETUP_XfOrM543(x) SETUP(XfOrM543_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (enable_break ) {
    int v ; 
    Scheme_Cont_Frame_Data cframe ; 
    BLOCK_SETUP((PUSH(cframe.cache, 0+XfOrM543_COUNT)));
#   define XfOrM544_COUNT (1+XfOrM543_COUNT)
#   define SETUP_XfOrM544(x) SETUP(XfOrM544_COUNT)
    cframe.cache = NULLED_OUT ; 
    FUNCCALL(SETUP_XfOrM544(_), scheme_push_break_enable (& cframe , 1 , 1 ) ); 
    v = FUNCCALL_AGAIN(scheme_block_until (_f , fdf , data , delay ) ); 
    FUNCCALL_AGAIN(scheme_pop_break_enable (& cframe , 0 ) ); 
    RET_VALUE_START (v ) RET_VALUE_END ; 
  }
  else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_block_until (_f , fdf , data , delay ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int ready_unless (Scheme_Object * o ) {
  /* No conversion */
  Scheme_Object * unless_evt , * data ; 
  Scheme_Ready_Fun f ; 
  data = (Scheme_Object * ) ((void * * ) o ) [0 ] ; 
  unless_evt = (Scheme_Object * ) ((void * * ) o ) [1 ] ; 
  f = (Scheme_Ready_Fun ) ((void * * ) o ) [2 ] ; 
  return f (data ) ; 
}
static void needs_wakeup_unless (Scheme_Object * o , void * fds ) {
  /* No conversion */
  Scheme_Object * data ; 
  Scheme_Needs_Wakeup_Fun fdf ; 
  data = (Scheme_Object * ) ((void * * ) o ) [0 ] ; 
  fdf = (Scheme_Needs_Wakeup_Fun ) ((void * * ) o ) [3 ] ; 
  fdf (data , fds ) ; 
}
int scheme_block_until_unless (Scheme_Ready_Fun f , Scheme_Needs_Wakeup_Fun fdf , Scheme_Object * data , float delay , Scheme_Object * unless , int enable_break ) {
  PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(unless, 0), PUSH(data, 1)));
# define XfOrM547_COUNT (2)
# define SETUP_XfOrM547(x) SETUP(XfOrM547_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (unless ) {
    void * * a ; 
    BLOCK_SETUP((PUSH(a, 0+XfOrM547_COUNT)));
#   define XfOrM548_COUNT (1+XfOrM547_COUNT)
#   define SETUP_XfOrM548(x) SETUP(XfOrM548_COUNT)
    a = NULLED_OUT ; 
    a = ((void * * ) FUNCCALL(SETUP_XfOrM548(_), GC_malloc (sizeof (void * ) * (4 ) ) )) ; 
    a [0 ] = data ; 
    a [1 ] = unless ; 
    a [2 ] = f ; 
    a [3 ] = fdf ; 
    data = (Scheme_Object * ) (void * ) a ; 
    f = ready_unless ; 
    if (fdf )
      fdf = needs_wakeup_unless ; 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_block_until_enable_break (f , fdf , data , delay , enable_break ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_thread_block_enable_break (float sleep_time , int enable_break ) {
  PREPARE_VAR_STACK(1);
# define XfOrM549_COUNT (0)
# define SETUP_XfOrM549(x) SETUP(XfOrM549_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (enable_break ) {
    Scheme_Cont_Frame_Data cframe ; 
    BLOCK_SETUP((PUSH(cframe.cache, 0+XfOrM549_COUNT)));
#   define XfOrM550_COUNT (1+XfOrM549_COUNT)
#   define SETUP_XfOrM550(x) SETUP(XfOrM550_COUNT)
    cframe.cache = NULLED_OUT ; 
    FUNCCALL(SETUP_XfOrM550(_), scheme_push_break_enable (& cframe , 1 , 1 ) ); 
    FUNCCALL_AGAIN(scheme_thread_block (sleep_time ) ); 
    FUNCCALL_AGAIN(scheme_pop_break_enable (& cframe , 0 ) ); 
  }
  else FUNCCALL_EMPTY(scheme_thread_block (sleep_time ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_start_atomic (void ) {
  /* No conversion */
  if (! do_atomic )
    missed_context_switch = 0 ; 
  do_atomic ++ ; 
}
void scheme_end_atomic_no_swap (void ) {
  /* No conversion */
  -- do_atomic ; 
}
void scheme_end_atomic (void ) {
  /* No conversion */
  scheme_end_atomic_no_swap () ; 
  if (! do_atomic && missed_context_switch ) {
    scheme_thread_block (0.0 ) ; 
    scheme_current_thread -> ran_some = 1 ; 
  }
}
static void wait_until_suspend_ok () {
  /* No conversion */
  while (do_atomic && scheme_on_atomic_timeout ) {
    scheme_on_atomic_timeout () ; 
  }
}
void scheme_weak_suspend_thread (Scheme_Thread * r ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(r, 0)));
# define XfOrM558_COUNT (1)
# define SETUP_XfOrM558(x) SETUP(XfOrM558_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (r -> running & 0x2 )
    RET_NOTHING ; 
  if (r == scheme_current_thread ) {
#   define XfOrM562_COUNT (0+XfOrM558_COUNT)
#   define SETUP_XfOrM562(x) SETUP_XfOrM558(x)
    FUNCCALL(SETUP_XfOrM562(_), wait_until_suspend_ok () ); 
  }
  if (r -> prev ) {
    r -> prev -> next = r -> next ; 
    r -> next -> prev = r -> prev ; 
  }
  else {
    r -> next -> prev = ((void * ) 0 ) ; 
    scheme_first_thread = r -> next ; 
  }
  r -> next = r -> prev = ((void * ) 0 ) ; 
  FUNCCALL(SETUP_XfOrM558(_), unschedule_in_set ((Scheme_Object * ) r , r -> t_set_parent ) ); 
  r -> running |= 0x2 ; 
  FUNCCALL(SETUP_XfOrM558(_), prepare_this_thread_for_GC (r ) ); 
  if (r == scheme_current_thread ) {
#   define XfOrM559_COUNT (0+XfOrM558_COUNT)
#   define SETUP_XfOrM559(x) SETUP_XfOrM558(x)
    FUNCCALL(SETUP_XfOrM559(_), select_thread () ); 
    if ((r -> running & 0x4 ) && ! (r -> running & 0x8 ) )
      FUNCCALL_EMPTY(scheme_thread_block (0 ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_weak_resume_thread (Scheme_Thread * r ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(r, 0)));
# define XfOrM563_COUNT (1)
# define SETUP_XfOrM563(x) SETUP(XfOrM563_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! (r -> running & 0x10 ) ) {
#   define XfOrM564_COUNT (0+XfOrM563_COUNT)
#   define SETUP_XfOrM564(x) SETUP_XfOrM563(x)
    if (r -> running & 0x2 ) {
#     define XfOrM565_COUNT (0+XfOrM564_COUNT)
#     define SETUP_XfOrM565(x) SETUP_XfOrM564(x)
      r -> running -= 0x2 ; 
      r -> next = scheme_first_thread ; 
      r -> prev = ((void * ) 0 ) ; 
      scheme_first_thread = r ; 
      r -> next -> prev = r ; 
      r -> ran_some = 1 ; 
      FUNCCALL(SETUP_XfOrM565(_), schedule_in_set ((Scheme_Object * ) r , r -> t_set_parent ) ); 
      FUNCCALL_EMPTY(scheme_check_tail_buffer_size (r ) ); 
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_about_to_move_C_stack (void ) {
  /* No conversion */
  wait_until_suspend_ok () ; 
}
static Scheme_Object * sch_sleep (int argc , Scheme_Object * args [] ) {
  /* No conversion */
  float t ; 
  if (argc && ! ((((long ) (args [0 ] ) ) & 0x1 ) || ((((args [0 ] ) -> type ) >= scheme_bignum_type ) && (((args [0 ] ) -> type ) <= scheme_complex_izi_type ) ) ) )
    scheme_wrong_type ("sleep" , "non-negative real number" , 0 , argc , args ) ; 
  if (argc ) {
    t = (float ) scheme_real_to_double (args [0 ] ) ; 
    if (t < 0 )
      scheme_wrong_type ("sleep" , "non-negative real number" , 0 , argc , args ) ; 
  }
  else t = 0 ; 
  scheme_thread_block (t ) ; 
  scheme_current_thread -> ran_some = 1 ; 
  return scheme_void ; 
}
static Scheme_Object * break_thread (int argc , Scheme_Object * args [] ) {
  /* No conversion */
  Scheme_Thread * p ; 
  if (! ((Scheme_Type ) (((((long ) (args [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_type ) ) )
    scheme_wrong_type ("break-thread" , "thread" , 0 , argc , args ) ; 
  p = (Scheme_Thread * ) args [0 ] ; 
  scheme_break_thread (p ) ; 
  if (! scheme_fuel_counter ) {
    scheme_thread_block (0.0 ) ; 
    scheme_current_thread -> ran_some = 1 ; 
  }
  return scheme_void ; 
}
static int do_kill_thread (Scheme_Thread * p ) {
  int kill_self = 0 ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(p, 0)));
# define XfOrM571_COUNT (1)
# define SETUP_XfOrM571(x) SETUP(XfOrM571_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! ((p -> running ) && ! ((p -> running ) & 0x4 ) ) ) {
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  if (p -> suspend_to_kill ) {
#   define XfOrM584_COUNT (0+XfOrM571_COUNT)
#   define SETUP_XfOrM584(x) SETUP_XfOrM571(x)
    if (p == scheme_current_thread )
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    FUNCCALL(SETUP_XfOrM584(_), suspend_thread (p ) ); 
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  if (p -> nestee )
    FUNCCALL(SETUP_XfOrM571(_), scheme_break_thread (p -> nestee ) ); 
  while (p -> private_on_kill ) {
#   define XfOrM581_COUNT (0+XfOrM571_COUNT)
#   define SETUP_XfOrM581(x) SETUP_XfOrM571(x)
    FUNCCALL(SETUP_XfOrM581(_), p -> private_on_kill (p -> private_kill_data ) ); 
    if (p -> private_kill_next ) {
      p -> private_on_kill = (Scheme_Kill_Action_Func ) p -> private_kill_next [0 ] ; 
      p -> private_kill_data = p -> private_kill_next [1 ] ; 
      p -> private_kill_next = (void * * ) p -> private_kill_next [2 ] ; 
    }
    else {
      p -> private_on_kill = ((void * ) 0 ) ; 
      p -> private_kill_data = ((void * ) 0 ) ; 
    }
  }
  if (p -> on_kill )
    FUNCCALL(SETUP_XfOrM571(_), p -> on_kill (p ) ); 
  FUNCCALL(SETUP_XfOrM571(_), scheme_remove_managed (p -> mref , (Scheme_Object * ) p -> mr_hop ) ); 
  {
    Scheme_Object * l ; 
    BLOCK_SETUP((PUSH(l, 0+XfOrM571_COUNT)));
#   define XfOrM575_COUNT (1+XfOrM571_COUNT)
#   define SETUP_XfOrM575(x) SETUP(XfOrM575_COUNT)
    l = NULLED_OUT ; 
    for (l = p -> extra_mrefs ; ! ((l ) == (scheme_null ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#     define XfOrM577_COUNT (0+XfOrM575_COUNT)
#     define SETUP_XfOrM577(x) SETUP_XfOrM575(x)
      FUNCCALL(SETUP_XfOrM577(_), scheme_remove_managed ((Scheme_Custodian_Reference * ) (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) , (Scheme_Object * ) p -> mr_hop ) ); 
    }
  }
  if (p -> running ) {
#   define XfOrM572_COUNT (0+XfOrM571_COUNT)
#   define SETUP_XfOrM572(x) SETUP_XfOrM571(x)
    if (p -> running & 0x10 ) {
      p -> running -= 0x10 ; 
    }
    p -> running |= 0x4 ; 
    if ((p -> running & 0x8 ) || p -> nester )
      FUNCCALL(SETUP_XfOrM572(_), scheme_weak_resume_thread (p ) ); 
    else if (p != scheme_current_thread ) {
#     define XfOrM573_COUNT (0+XfOrM572_COUNT)
#     define SETUP_XfOrM573(x) SETUP_XfOrM572(x)
      if (p -> next )
        FUNCCALL(SETUP_XfOrM573(_), remove_thread (p ) ); 
    }
  }
  if (p == scheme_current_thread )
    kill_self = 1 ; 
  RET_VALUE_START (kill_self ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_kill_thread (Scheme_Thread * p ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(p, 0)));
# define XfOrM586_COUNT (1)
# define SETUP_XfOrM586(x) SETUP(XfOrM586_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (FUNCCALL(SETUP_XfOrM586(_), do_kill_thread (p ) )) {
#   define XfOrM587_COUNT (0+XfOrM586_COUNT)
#   define SETUP_XfOrM587(x) SETUP_XfOrM586(x)
    FUNCCALL(SETUP_XfOrM587(_), wait_until_suspend_ok () ); 
    if (p -> suspend_to_kill )
      FUNCCALL_EMPTY(suspend_thread (p ) ); 
    else FUNCCALL_EMPTY(scheme_thread_block (0.0 ) ); 
  }
  FUNCCALL_EMPTY(scheme_thread_block (0.0 ) ); 
  scheme_current_thread -> ran_some = 1 ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * kill_thread (int argc , Scheme_Object * argv [] ) {
  Scheme_Thread * p = (Scheme_Thread * ) argv [0 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(p, 0)));
# define XfOrM588_COUNT (1)
# define SETUP_XfOrM588(x) SETUP(XfOrM588_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("kill-thread" , "thread" , 0 , argc , argv ) ); 
  if (! ((p -> running ) && ! ((p -> running ) & 0x4 ) ) )
    RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
  FUNCCALL(SETUP_XfOrM588(_), check_current_custodian_allows ("kill-thread" , p ) ); 
  FUNCCALL_EMPTY(scheme_kill_thread (p ) ); 
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_push_kill_action (Scheme_Kill_Action_Func f , void * d ) {
  Scheme_Thread * p = scheme_current_thread ; 
  PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(d, 0), PUSH(p, 1)));
# define XfOrM589_COUNT (2)
# define SETUP_XfOrM589(x) SETUP(XfOrM589_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (p -> private_on_kill ) {
    void * * next ; 
    BLOCK_SETUP((PUSH(next, 0+XfOrM589_COUNT)));
#   define XfOrM590_COUNT (1+XfOrM589_COUNT)
#   define SETUP_XfOrM590(x) SETUP(XfOrM590_COUNT)
    next = NULLED_OUT ; 
    next = ((void * * ) FUNCCALL(SETUP_XfOrM590(_), GC_malloc (sizeof (void * ) * (3 ) ) )) ; 
    next [0 ] = (void * ) p -> private_on_kill ; 
    next [1 ] = p -> private_kill_data ; 
    next [2 ] = (void * ) p -> private_kill_next ; 
    p -> private_kill_next = next ; 
  }
  p -> private_on_kill = f ; 
  p -> private_kill_data = d ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_pop_kill_action () {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  if (p -> private_kill_next ) {
    p -> private_on_kill = (Scheme_Kill_Action_Func ) p -> private_kill_next [0 ] ; 
    p -> private_kill_data = p -> private_kill_next [1 ] ; 
    p -> private_kill_next = (void * * ) p -> private_kill_next [2 ] ; 
  }
  else {
    p -> private_on_kill = ((void * ) 0 ) ; 
    p -> private_kill_data = ((void * ) 0 ) ; 
  }
}
static void transitive_resume (Scheme_Object * resumes ) ; 
static void transitive_promote (Scheme_Thread * p , Scheme_Custodian * c ) ; 
static void promote_thread (Scheme_Thread * p , Scheme_Custodian * to_c ) ; 
static Scheme_Object * thread_suspend (int argc , Scheme_Object * argv [] ) {
  Scheme_Thread * p ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(p, 0)));
# define XfOrM594_COUNT (1)
# define SETUP_XfOrM594(x) SETUP(XfOrM594_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  p = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("thread-suspend" , "thread" , 0 , argc , argv ) ); 
  p = (Scheme_Thread * ) argv [0 ] ; 
  FUNCCALL(SETUP_XfOrM594(_), check_current_custodian_allows ("thread-suspend" , p ) ); 
  FUNCCALL_EMPTY(suspend_thread (p ) ); 
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void suspend_thread (Scheme_Thread * p ) {
  int running ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(p, 0)));
# define XfOrM595_COUNT (1)
# define SETUP_XfOrM595(x) SETUP(XfOrM595_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! ((p -> running ) && ! ((p -> running ) & 0x4 ) ) )
    RET_NOTHING ; 
  if (p -> running & 0x10 )
    RET_NOTHING ; 
  running = p -> running ; 
  p -> resumed_box = ((void * ) 0 ) ; 
  if (p -> suspended_box ) {
#   define XfOrM602_COUNT (0+XfOrM595_COUNT)
#   define SETUP_XfOrM602(x) SETUP_XfOrM595(x)
    (((Scheme_Simple_Object * ) (p -> suspended_box ) ) -> u . two_ptr_val . ptr2 ) = (Scheme_Object * ) p ; 
    FUNCCALL(SETUP_XfOrM602(_), scheme_post_sema_all ((((Scheme_Simple_Object * ) (p -> suspended_box ) ) -> u . two_ptr_val . ptr1 ) ) ); 
  }
  if (((p ) == (scheme_main_thread ) ) ) {
#   define XfOrM600_COUNT (0+XfOrM595_COUNT)
#   define SETUP_XfOrM600(x) SETUP_XfOrM595(x)
    p -> running |= 0x10 ; 
    scheme_main_was_once_suspended = 1 ; 
    if (p == scheme_current_thread ) {
#     define XfOrM601_COUNT (0+XfOrM600_COUNT)
#     define SETUP_XfOrM601(x) SETUP_XfOrM600(x)
      FUNCCALL(SETUP_XfOrM601(_), scheme_thread_block (0.0 ) ); 
      p -> ran_some = 1 ; 
    }
  }
  else if ((running & (0x8 | 0x20 ) ) && (running & 0x2 ) ) {
#   define XfOrM599_COUNT (0+XfOrM595_COUNT)
#   define SETUP_XfOrM599(x) SETUP_XfOrM595(x)
    FUNCCALL(SETUP_XfOrM599(_), scheme_weak_resume_thread (p ) ); 
    p -> running |= 0x10 ; 
  }
  else {
#   define XfOrM596_COUNT (0+XfOrM595_COUNT)
#   define SETUP_XfOrM596(x) SETUP_XfOrM595(x)
    if (p == scheme_current_thread ) {
#     define XfOrM598_COUNT (0+XfOrM596_COUNT)
#     define SETUP_XfOrM598(x) SETUP_XfOrM596(x)
      FUNCCALL(SETUP_XfOrM598(_), wait_until_suspend_ok () ); 
    }
    p -> running |= 0x10 ; 
    FUNCCALL(SETUP_XfOrM596(_), scheme_weak_suspend_thread (p ) ); 
    if (p == scheme_current_thread ) {
#     define XfOrM597_COUNT (0+XfOrM596_COUNT)
#     define SETUP_XfOrM597(x) SETUP_XfOrM596(x)
      FUNCCALL_EMPTY(scheme_check_break_now () ); 
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void add_transitive_resume (Scheme_Thread * promote_to , Scheme_Thread * p ) {
  Scheme_Object * running_box ; 
  Scheme_Hash_Table * ht ; 
  PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(ht, 0), PUSH(promote_to, 1), PUSH(running_box, 2), PUSH(p, 3)));
# define XfOrM603_COUNT (4)
# define SETUP_XfOrM603(x) SETUP(XfOrM603_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  running_box = NULLED_OUT ; 
  ht = NULLED_OUT ; 
  if (! p -> running_box ) {
    Scheme_Object * b ; 
    BLOCK_SETUP((PUSH(b, 0+XfOrM603_COUNT)));
#   define XfOrM617_COUNT (1+XfOrM603_COUNT)
#   define SETUP_XfOrM617(x) SETUP(XfOrM617_COUNT)
    b = NULLED_OUT ; 
    b = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM617(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    b -> type = scheme_thread_dead_type ; 
    (((Scheme_Small_Object * ) (b ) ) -> u . ptr_val ) = (Scheme_Object * ) p ; 
    p -> running_box = b ; 
  }
  running_box = p -> running_box ; 
  if (! promote_to -> transitive_resumes ) {
#   define XfOrM616_COUNT (0+XfOrM603_COUNT)
#   define SETUP_XfOrM616(x) SETUP_XfOrM603(x)
    ht = FUNCCALL(SETUP_XfOrM616(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
    promote_to -> transitive_resumes = (Scheme_Object * ) ht ; 
  }
  else {
    Scheme_Hash_Table * gone = ((void * ) 0 ) ; 
    int i ; 
    BLOCK_SETUP((PUSH(gone, 0+XfOrM603_COUNT)));
#   define XfOrM604_COUNT (1+XfOrM603_COUNT)
#   define SETUP_XfOrM604(x) SETUP(XfOrM604_COUNT)
    ht = (Scheme_Hash_Table * ) promote_to -> transitive_resumes ; 
    for (i = ht -> size ; i -- ; ) {
#     define XfOrM613_COUNT (0+XfOrM604_COUNT)
#     define SETUP_XfOrM613(x) SETUP_XfOrM604(x)
      if (ht -> vals [i ] ) {
#       define XfOrM614_COUNT (0+XfOrM613_COUNT)
#       define SETUP_XfOrM614(x) SETUP_XfOrM613(x)
        if (! (((Scheme_Small_Object * ) (ht -> keys [i ] ) ) -> u . ptr_val ) ) {
#         define XfOrM615_COUNT (0+XfOrM614_COUNT)
#         define SETUP_XfOrM615(x) SETUP_XfOrM614(x)
          if (! gone )
            gone = FUNCCALL(SETUP_XfOrM615(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
          FUNCCALL(SETUP_XfOrM615(_), scheme_hash_set (gone , ht -> keys [i ] , scheme_true ) ); 
        }
      }
    }
    if (gone ) {
#     define XfOrM605_COUNT (0+XfOrM604_COUNT)
#     define SETUP_XfOrM605(x) SETUP_XfOrM604(x)
      for (i = gone -> size ; i -- ; ) {
#       define XfOrM608_COUNT (0+XfOrM605_COUNT)
#       define SETUP_XfOrM608(x) SETUP_XfOrM605(x)
        if (gone -> vals [i ] ) {
#         define XfOrM609_COUNT (0+XfOrM608_COUNT)
#         define SETUP_XfOrM609(x) SETUP_XfOrM608(x)
          FUNCCALL(SETUP_XfOrM609(_), scheme_hash_set (ht , gone -> keys [i ] , ((void * ) 0 ) ) ); 
        }
      }
    }
  }
  FUNCCALL_EMPTY(scheme_hash_set (ht , running_box , scheme_true ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * transitive_resume_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * r = (Scheme_Object * ) p -> ku . k . p1 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  transitive_resume (r ) ; 
  return scheme_true ; 
}
static void transitive_resume (Scheme_Object * resumes ) {
  Scheme_Hash_Table * ht ; 
  Scheme_Object * a [1 ] ; 
  int i ; 
  unsigned long _stk_pos ; 
  PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(ht, 0), PUSHARRAY(a, 1, 1), PUSH(resumes, 4)));
# define XfOrM619_COUNT (5)
# define SETUP_XfOrM619(x) SETUP(XfOrM619_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  ht = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  _stk_pos = (unsigned long ) & _stk_pos ; 
  if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
    Scheme_Thread * p = scheme_current_thread ; 
    BLOCK_SETUP((PUSH(p, 0+XfOrM619_COUNT)));
#   define XfOrM624_COUNT (1+XfOrM619_COUNT)
#   define SETUP_XfOrM624(x) SETUP(XfOrM624_COUNT)
    p -> ku . k . p1 = resumes ; 
    p -> suspend_break ++ ; 
    FUNCCALL(SETUP_XfOrM624(_), scheme_start_atomic () ); 
    FUNCCALL_AGAIN(scheme_handle_stack_overflow (transitive_resume_k ) ); 
    FUNCCALL_AGAIN(scheme_end_atomic_no_swap () ); 
    -- p -> suspend_break ; 
    RET_NOTHING ; 
  }
  ht = (Scheme_Hash_Table * ) resumes ; 
  for (i = ht -> size ; i -- ; ) {
#   define XfOrM622_COUNT (0+XfOrM619_COUNT)
#   define SETUP_XfOrM622(x) SETUP_XfOrM619(x)
    if (ht -> vals [i ] ) {
#     define XfOrM623_COUNT (0+XfOrM622_COUNT)
#     define SETUP_XfOrM623(x) SETUP_XfOrM622(x)
      a [0 ] = (((Scheme_Small_Object * ) (ht -> keys [i ] ) ) -> u . ptr_val ) ; 
      if (a [0 ] )
        FUNCCALL(SETUP_XfOrM623(_), thread_resume (1 , a ) ); 
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * transitive_promote_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Thread * pp = (Scheme_Thread * ) p -> ku . k . p1 ; 
  Scheme_Custodian * c = (Scheme_Custodian * ) p -> ku . k . p2 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  p -> ku . k . p2 = ((void * ) 0 ) ; 
  transitive_promote (pp , c ) ; 
  return scheme_true ; 
}
static void transitive_promote (Scheme_Thread * p , Scheme_Custodian * c ) {
  Scheme_Hash_Table * ht ; 
  Scheme_Object * t ; 
  int i ; 
  unsigned long _stk_pos ; 
  PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(c, 0), PUSH(ht, 1), PUSH(t, 2), PUSH(p, 3)));
# define XfOrM626_COUNT (4)
# define SETUP_XfOrM626(x) SETUP(XfOrM626_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  ht = NULLED_OUT ; 
  t = NULLED_OUT ; 
  _stk_pos = (unsigned long ) & _stk_pos ; 
  if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
    Scheme_Thread * pp = scheme_current_thread ; 
    BLOCK_SETUP((PUSH(pp, 0+XfOrM626_COUNT)));
#   define XfOrM631_COUNT (1+XfOrM626_COUNT)
#   define SETUP_XfOrM631(x) SETUP(XfOrM631_COUNT)
    pp -> ku . k . p1 = p ; 
    pp -> ku . k . p2 = c ; 
    pp -> suspend_break ++ ; 
    FUNCCALL(SETUP_XfOrM631(_), scheme_start_atomic () ); 
    FUNCCALL_AGAIN(scheme_handle_stack_overflow (transitive_promote_k ) ); 
    FUNCCALL_AGAIN(scheme_end_atomic_no_swap () ); 
    -- pp -> suspend_break ; 
    RET_NOTHING ; 
  }
  if (! p -> transitive_resumes )
    RET_NOTHING ; 
  ht = (Scheme_Hash_Table * ) p -> transitive_resumes ; 
  for (i = ht -> size ; i -- ; ) {
#   define XfOrM629_COUNT (0+XfOrM626_COUNT)
#   define SETUP_XfOrM629(x) SETUP_XfOrM626(x)
    if (ht -> vals [i ] ) {
#     define XfOrM630_COUNT (0+XfOrM629_COUNT)
#     define SETUP_XfOrM630(x) SETUP_XfOrM629(x)
      t = (((Scheme_Small_Object * ) (ht -> keys [i ] ) ) -> u . ptr_val ) ; 
      if (t )
        FUNCCALL(SETUP_XfOrM630(_), promote_thread ((Scheme_Thread * ) t , c ) ); 
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void promote_thread (Scheme_Thread * p , Scheme_Custodian * to_c ) {
  Scheme_Custodian * c , * cx ; 
  Scheme_Custodian_Reference * mref ; 
  Scheme_Object * l ; 
  PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(mref, 0), PUSH(c, 1), PUSH(to_c, 2), PUSH(p, 3), PUSH(l, 4), PUSH(cx, 5)));
# define XfOrM632_COUNT (6)
# define SETUP_XfOrM632(x) SETUP(XfOrM632_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  c = NULLED_OUT ; 
  cx = NULLED_OUT ; 
  mref = NULLED_OUT ; 
  l = NULLED_OUT ; 
  if (! p -> mref || ! ((Scheme_Custodian_Weak_Box * ) p -> mref ) -> val ) {
  }
  else {
#   define XfOrM633_COUNT (0+XfOrM632_COUNT)
#   define SETUP_XfOrM633(x) SETUP_XfOrM632(x)
    c = ((Scheme_Custodian_Weak_Box * ) p -> mref ) -> val ; 
    for (cx = to_c ; cx && ((cx ) != (c ) ) ; ) {
      cx = ((Scheme_Custodian_Weak_Box * ) cx -> parent ) -> val ; 
    }
    if (cx )
      RET_NOTHING ; 
    for (l = p -> extra_mrefs ; ! ((l ) == (scheme_null ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
      mref = (Scheme_Custodian_Reference * ) (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
      c = ((Scheme_Custodian_Weak_Box * ) mref ) -> val ; 
      for (cx = to_c ; cx && ((cx ) != (c ) ) ; ) {
        cx = ((Scheme_Custodian_Weak_Box * ) cx -> parent ) -> val ; 
      }
      if (cx )
        RET_NOTHING ; 
    }
    for (cx = c ; cx && ((cx ) != (to_c ) ) ; ) {
      cx = ((Scheme_Custodian_Weak_Box * ) cx -> parent ) -> val ; 
    }
    if (! cx ) {
#     define XfOrM634_COUNT (0+XfOrM633_COUNT)
#     define SETUP_XfOrM634(x) SETUP_XfOrM633(x)
      for (l = p -> extra_mrefs ; ! ((l ) == (scheme_null ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#       define XfOrM646_COUNT (0+XfOrM634_COUNT)
#       define SETUP_XfOrM646(x) SETUP_XfOrM634(x)
        for (cx = c ; cx && ((cx ) != (to_c ) ) ; ) {
          cx = ((Scheme_Custodian_Weak_Box * ) cx -> parent ) -> val ; 
        }
        if (cx ) {
#         define XfOrM647_COUNT (0+XfOrM646_COUNT)
#         define SETUP_XfOrM647(x) SETUP_XfOrM646(x)
          mref = (Scheme_Custodian_Reference * ) (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
          FUNCCALL(SETUP_XfOrM647(_), scheme_remove_managed (mref , (Scheme_Object * ) p -> mr_hop ) ); 
          mref = FUNCCALL_AGAIN(scheme_add_managed (to_c , (Scheme_Object * ) p -> mr_hop , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ); 
          (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) = (Scheme_Object * ) mref ; 
          {
            Scheme_Object * prev ; 
            prev = NULLED_OUT ; 
            prev = l ; 
            for (l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; ! ((l ) == (scheme_null ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
              mref = (Scheme_Custodian_Reference * ) (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
              c = ((Scheme_Custodian_Weak_Box * ) mref ) -> val ; 
              for (cx = c ; cx && ((cx ) != (to_c ) ) ; ) {
                cx = ((Scheme_Custodian_Weak_Box * ) cx -> parent ) -> val ; 
              }
              if (cx )
                (((Scheme_Simple_Object * ) (prev ) ) -> u . pair_val . cdr ) = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
            }
          }
          FUNCCALL(SETUP_XfOrM647(_), transitive_promote (p , to_c ) ); 
          RET_NOTHING ; 
        }
      }
      mref = FUNCCALL(SETUP_XfOrM634(_), scheme_add_managed (to_c , (Scheme_Object * ) p -> mr_hop , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ); 
      l = FUNCCALL(SETUP_XfOrM634(_), scheme_make_raw_pair ((Scheme_Object * ) mref , p -> extra_mrefs ) ); 
      p -> extra_mrefs = l ; 
      FUNCCALL(SETUP_XfOrM634(_), transitive_promote (p , to_c ) ); 
      RET_NOTHING ; 
    }
  }
  FUNCCALL(SETUP_XfOrM632(_), scheme_remove_managed (p -> mref , (Scheme_Object * ) p -> mr_hop ) ); 
  mref = FUNCCALL(SETUP_XfOrM632(_), scheme_add_managed (to_c , (Scheme_Object * ) p -> mr_hop , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ); 
  p -> mref = mref ; 
  FUNCCALL(SETUP_XfOrM632(_), GC_register_thread (p , to_c ) ); 
  FUNCCALL_EMPTY(transitive_promote (p , to_c ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * thread_resume (int argc , Scheme_Object * argv [] ) {
  Scheme_Thread * p , * promote_to = ((void * ) 0 ) ; 
  Scheme_Custodian * promote_c = ((void * ) 0 ) ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(promote_to, 0), PUSH(p, 1), PUSH(promote_c, 2)));
# define XfOrM668_COUNT (3)
# define SETUP_XfOrM668(x) SETUP(XfOrM668_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  p = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("thread-resume" , "thread" , 0 , argc , argv ) ); 
  p = (Scheme_Thread * ) argv [0 ] ; 
  if (argc > 1 ) {
#   define XfOrM676_COUNT (0+XfOrM668_COUNT)
#   define SETUP_XfOrM676(x) SETUP_XfOrM668(x)
    if (((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_type ) ) )
      promote_to = (Scheme_Thread * ) argv [1 ] ; 
    else if (((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_custodian_type ) ) ) {
      promote_c = (Scheme_Custodian * ) argv [1 ] ; 
      if (promote_c -> shut_down )
        promote_c = ((void * ) 0 ) ; 
    }
    else {
#     define XfOrM677_COUNT (0+XfOrM676_COUNT)
#     define SETUP_XfOrM677(x) SETUP_XfOrM676(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("thread-resume" , "thread or custodian" , 1 , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  if (! ((p -> running ) && ! ((p -> running ) & 0x4 ) ) )
    RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
  if (promote_to ) {
    Scheme_Object * l ; 
    Scheme_Custodian_Reference * mref ; 
    BLOCK_SETUP((PUSH(mref, 0+XfOrM668_COUNT), PUSH(l, 1+XfOrM668_COUNT)));
#   define XfOrM672_COUNT (2+XfOrM668_COUNT)
#   define SETUP_XfOrM672(x) SETUP(XfOrM672_COUNT)
    l = NULLED_OUT ; 
    mref = NULLED_OUT ; 
    if (promote_to -> mref && ((Scheme_Custodian_Weak_Box * ) promote_to -> mref ) -> val ) {
#     define XfOrM673_COUNT (0+XfOrM672_COUNT)
#     define SETUP_XfOrM673(x) SETUP_XfOrM672(x)
      FUNCCALL(SETUP_XfOrM673(_), promote_thread (p , ((Scheme_Custodian_Weak_Box * ) promote_to -> mref ) -> val ) ); 
      for (l = p -> extra_mrefs ; ! ((l ) == (scheme_null ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#       define XfOrM675_COUNT (0+XfOrM673_COUNT)
#       define SETUP_XfOrM675(x) SETUP_XfOrM673(x)
        mref = (Scheme_Custodian_Reference * ) (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
        FUNCCALL(SETUP_XfOrM675(_), promote_thread (p , ((Scheme_Custodian_Weak_Box * ) mref ) -> val ) ); 
      }
    }
  }
  if (promote_c )
    FUNCCALL(SETUP_XfOrM668(_), promote_thread (p , promote_c ) ); 
  if (promote_to && ((promote_to -> running ) && ! ((promote_to -> running ) & 0x4 ) ) && ! ((promote_to ) == (p ) ) )
    FUNCCALL(SETUP_XfOrM668(_), add_transitive_resume (promote_to , p ) ); 
  {
    Scheme_Custodian * c ; 
    c = NULLED_OUT ; 
    if (p -> mref )
      c = ((Scheme_Custodian_Weak_Box * ) p -> mref ) -> val ; 
    else c = ((void * ) 0 ) ; 
    if (! c || c -> shut_down )
      RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
  }
  if (p -> running & 0x10 ) {
#   define XfOrM669_COUNT (0+XfOrM668_COUNT)
#   define SETUP_XfOrM669(x) SETUP_XfOrM668(x)
    p -> suspended_box = ((void * ) 0 ) ; 
    if (p -> resumed_box ) {
#     define XfOrM670_COUNT (0+XfOrM669_COUNT)
#     define SETUP_XfOrM670(x) SETUP_XfOrM669(x)
      (((Scheme_Simple_Object * ) (p -> resumed_box ) ) -> u . two_ptr_val . ptr2 ) = (Scheme_Object * ) p ; 
      FUNCCALL(SETUP_XfOrM670(_), scheme_post_sema_all ((((Scheme_Simple_Object * ) (p -> resumed_box ) ) -> u . two_ptr_val . ptr1 ) ) ); 
    }
    p -> running -= 0x10 ; 
    FUNCCALL(SETUP_XfOrM669(_), scheme_weak_resume_thread (p ) ); 
    if (p -> transitive_resumes )
      FUNCCALL_EMPTY(transitive_resume (p -> transitive_resumes ) ); 
  }
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_thread_suspend (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Thread * p ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_type ) ) )
    scheme_wrong_type ("thread-suspend-evt" , "thread" , 0 , argc , argv ) ; 
  p = (Scheme_Thread * ) argv [0 ] ; 
  return scheme_get_thread_suspend (p ) ; 
}
Scheme_Object * scheme_get_thread_suspend (Scheme_Thread * p ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(p, 0)));
# define XfOrM680_COUNT (1)
# define SETUP_XfOrM680(x) SETUP(XfOrM680_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! p -> suspended_box ) {
    Scheme_Object * b ; 
    BLOCK_SETUP((PUSH(b, 0+XfOrM680_COUNT)));
#   define XfOrM681_COUNT (1+XfOrM680_COUNT)
#   define SETUP_XfOrM681(x) SETUP(XfOrM681_COUNT)
    b = NULLED_OUT ; 
    b = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM681(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    b -> type = scheme_thread_suspend_type ; 
    if (((p -> running ) && ! ((p -> running ) & 0x4 ) ) && (p -> running & 0x10 ) )
      (((Scheme_Simple_Object * ) (b ) ) -> u . two_ptr_val . ptr2 ) = (Scheme_Object * ) p ; 
    else {
      Scheme_Object * sema ; 
      BLOCK_SETUP((PUSH(sema, 0+XfOrM681_COUNT)));
#     define XfOrM682_COUNT (1+XfOrM681_COUNT)
#     define SETUP_XfOrM682(x) SETUP(XfOrM682_COUNT)
      sema = NULLED_OUT ; 
      sema = FUNCCALL(SETUP_XfOrM682(_), scheme_make_sema (0 ) ); 
      (((Scheme_Simple_Object * ) (b ) ) -> u . two_ptr_val . ptr1 ) = sema ; 
    }
    p -> suspended_box = b ; 
  }
  RET_VALUE_START (p -> suspended_box ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_thread_resume (int argc , Scheme_Object * argv [] ) {
  Scheme_Thread * p ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(p, 0)));
# define XfOrM683_COUNT (1)
# define SETUP_XfOrM683(x) SETUP(XfOrM683_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  p = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("thread-resume-evt" , "thread" , 0 , argc , argv ) ); 
  p = (Scheme_Thread * ) argv [0 ] ; 
  if (! p -> resumed_box ) {
    Scheme_Object * b ; 
    BLOCK_SETUP((PUSH(b, 0+XfOrM683_COUNT)));
#   define XfOrM684_COUNT (1+XfOrM683_COUNT)
#   define SETUP_XfOrM684(x) SETUP(XfOrM684_COUNT)
    b = NULLED_OUT ; 
    b = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM684(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    b -> type = scheme_thread_resume_type ; 
    if (((p -> running ) && ! ((p -> running ) & 0x4 ) ) && ! (p -> running & 0x10 ) )
      (((Scheme_Simple_Object * ) (b ) ) -> u . two_ptr_val . ptr2 ) = (Scheme_Object * ) p ; 
    else {
      Scheme_Object * sema ; 
      BLOCK_SETUP((PUSH(sema, 0+XfOrM684_COUNT)));
#     define XfOrM685_COUNT (1+XfOrM684_COUNT)
#     define SETUP_XfOrM685(x) SETUP(XfOrM685_COUNT)
      sema = NULLED_OUT ; 
      sema = FUNCCALL(SETUP_XfOrM685(_), scheme_make_sema (0 ) ); 
      (((Scheme_Simple_Object * ) (b ) ) -> u . two_ptr_val . ptr1 ) = sema ; 
    }
    p -> resumed_box = b ; 
  }
  RET_VALUE_START (p -> resumed_box ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int resume_suspend_ready (Scheme_Object * o , Scheme_Schedule_Info * sinfo ) {
  Scheme_Object * t ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(sinfo, 1)));
# define XfOrM686_COUNT (2)
# define SETUP_XfOrM686(x) SETUP(XfOrM686_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  t = NULLED_OUT ; 
  t = (((Scheme_Simple_Object * ) (o ) ) -> u . two_ptr_val . ptr2 ) ; 
  if (t ) {
#   define XfOrM687_COUNT (0+XfOrM686_COUNT)
#   define SETUP_XfOrM687(x) SETUP_XfOrM686(x)
    FUNCCALL(SETUP_XfOrM687(_), scheme_set_sync_target (sinfo , o , t , ((void * ) 0 ) , 0 , 0 ) ); 
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  }
  FUNCCALL_EMPTY(scheme_set_sync_target (sinfo , (((Scheme_Simple_Object * ) (o ) ) -> u . two_ptr_val . ptr1 ) , o , ((void * ) 0 ) , 0 , 1 ) ); 
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_thread_dead (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_type ) ) )
    scheme_wrong_type ("thread-dead-evt" , "thread" , 0 , argc , argv ) ; 
  return scheme_get_thread_dead ((Scheme_Thread * ) argv [0 ] ) ; 
}
Scheme_Object * scheme_get_thread_dead (Scheme_Thread * p ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(p, 0)));
# define XfOrM689_COUNT (1)
# define SETUP_XfOrM689(x) SETUP(XfOrM689_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! p -> dead_box ) {
    Scheme_Object * b ; 
    Scheme_Object * sema ; 
    BLOCK_SETUP((PUSH(b, 0+XfOrM689_COUNT), PUSH(sema, 1+XfOrM689_COUNT)));
#   define XfOrM690_COUNT (2+XfOrM689_COUNT)
#   define SETUP_XfOrM690(x) SETUP(XfOrM690_COUNT)
    b = NULLED_OUT ; 
    sema = NULLED_OUT ; 
    b = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM690(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    b -> type = scheme_thread_dead_type ; 
    sema = FUNCCALL(SETUP_XfOrM690(_), scheme_make_sema (0 ) ); 
    (((Scheme_Small_Object * ) (b ) ) -> u . ptr_val ) = sema ; 
    if (! ((p -> running ) && ! ((p -> running ) & 0x4 ) ) )
      FUNCCALL(SETUP_XfOrM690(_), scheme_post_sema_all (sema ) ); 
    p -> dead_box = b ; 
  }
  RET_VALUE_START (p -> dead_box ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int dead_ready (Scheme_Object * o , Scheme_Schedule_Info * sinfo ) {
  /* No conversion */
  scheme_set_sync_target (sinfo , (((Scheme_Small_Object * ) (o ) ) -> u . ptr_val ) , o , ((void * ) 0 ) , 0 , 1 ) ; 
  return 0 ; 
}
static void syncing_needs_wakeup (Scheme_Object * s , void * fds ) ; 
typedef struct Evt {
  Scheme_Type type ; 
  Scheme_Type sync_type ; 
  Scheme_Ready_Fun_FPC ready ; 
  Scheme_Needs_Wakeup_Fun needs_wakeup ; 
  Scheme_Sync_Sema_Fun get_sema ; 
  Scheme_Sync_Filter_Fun filter ; 
  int can_redirect ; 
}
Evt ; 
static int evts_array_size ; 
static Evt * * evts ; 
void scheme_add_evt (Scheme_Type type , Scheme_Ready_Fun ready , Scheme_Needs_Wakeup_Fun wakeup , Scheme_Sync_Filter_Fun filter , int can_redirect ) {
  Evt * naya ; 
  PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(naya, 0)));
# define XfOrM692_COUNT (1)
# define SETUP_XfOrM692(x) SETUP(XfOrM692_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  naya = NULLED_OUT ; 
  if (! evts ) {
#   define XfOrM694_COUNT (0+XfOrM692_COUNT)
#   define SETUP_XfOrM694(x) SETUP_XfOrM692(x)
    FUNCCALL(SETUP_XfOrM694(_), scheme_register_static ((void * ) & evts , sizeof (evts ) ) ); 
  }
  if (evts_array_size <= type ) {
    Evt * * nevts ; 
    int new_size ; 
    BLOCK_SETUP((PUSH(nevts, 0+XfOrM692_COUNT)));
#   define XfOrM693_COUNT (1+XfOrM692_COUNT)
#   define SETUP_XfOrM693(x) SETUP(XfOrM693_COUNT)
    nevts = NULLED_OUT ; 
    new_size = type + 1 ; 
    if (new_size < _scheme_last_type_ )
      new_size = _scheme_last_type_ ; 
    nevts = ((Evt * * ) FUNCCALL(SETUP_XfOrM693(_), GC_malloc (sizeof (Evt * ) * (new_size ) ) )) ; 
    (memcpy (nevts , evts , evts_array_size * sizeof (Evt * ) ) ) ; 
    evts = nevts ; 
    evts_array_size = new_size ; 
  }
  naya = ((Evt * ) FUNCCALL(SETUP_XfOrM692(_), GC_malloc_one_small_tagged ((((sizeof (Evt ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  naya -> type = scheme_rt_evt ; 
  naya -> sync_type = type ; 
  naya -> ready = (Scheme_Ready_Fun_FPC ) ready ; 
  naya -> needs_wakeup = wakeup ; 
  naya -> filter = filter ; 
  naya -> can_redirect = can_redirect ; 
  evts [type ] = naya ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_add_evt_through_sema (Scheme_Type type , Scheme_Sync_Sema_Fun get_sema , Scheme_Sync_Filter_Fun filter ) {
  /* No conversion */
  scheme_add_evt (type , ((void * ) 0 ) , ((void * ) 0 ) , filter , 0 ) ; 
  evts [type ] -> get_sema = get_sema ; 
}
static Evt * find_evt (Scheme_Object * o ) {
  Scheme_Type t ; 
  Evt * w ; 
  DECL_RET_SAVE (Evt * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(w, 0)));
# define XfOrM696_COUNT (1)
# define SETUP_XfOrM696(x) SETUP(XfOrM696_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  w = NULLED_OUT ; 
  t = ((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ; 
  w = evts [t ] ; 
  if (w ) {
#   define XfOrM697_COUNT (0+XfOrM696_COUNT)
#   define SETUP_XfOrM697(x) SETUP_XfOrM696(x)
    if (w -> filter ) {
      Scheme_Sync_Filter_Fun filter ; 
#     define XfOrM698_COUNT (0+XfOrM697_COUNT)
#     define SETUP_XfOrM698(x) SETUP_XfOrM697(x)
      filter = w -> filter ; 
      if (! FUNCCALL(SETUP_XfOrM698(_), filter (o ) ))
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    RET_VALUE_START (w ) RET_VALUE_END ; 
  }
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_is_evt (Scheme_Object * o ) {
  /* No conversion */
  if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_evt_set_type ) ) )
    return 1 ; 
  return ! ! find_evt (o ) ; 
}
static Syncing * make_syncing (Evt_Set * evt_set , float timeout , double start_time ) {
  Syncing * syncing ; 
  int pos ; 
  DECL_RET_SAVE (Syncing * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(evt_set, 0), PUSH(syncing, 1)));
# define XfOrM700_COUNT (2)
# define SETUP_XfOrM700(x) SETUP(XfOrM700_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  syncing = NULLED_OUT ; 
  syncing = ((Syncing * ) FUNCCALL(SETUP_XfOrM700(_), GC_malloc_one_small_tagged ((((sizeof (Syncing ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  syncing -> type = scheme_rt_syncing ; 
  syncing -> set = evt_set ; 
  syncing -> timeout = timeout ; 
  if (timeout >= 0 )
    syncing -> sleep_end = start_time + (timeout * 1000 ) ; 
  else syncing -> sleep_end = 0.0 ; 
  if (evt_set -> argc > 1 ) {
    Scheme_Config * config ; 
    Scheme_Object * rand_state ; 
    BLOCK_SETUP((PUSH(config, 0+XfOrM700_COUNT), PUSH(rand_state, 1+XfOrM700_COUNT)));
#   define XfOrM701_COUNT (2+XfOrM700_COUNT)
#   define SETUP_XfOrM701(x) SETUP(XfOrM701_COUNT)
    config = NULLED_OUT ; 
    rand_state = NULLED_OUT ; 
    config = FUNCCALL(SETUP_XfOrM701(_), scheme_current_config () ); 
    rand_state = FUNCCALL_AGAIN(scheme_get_param (config , MZCONFIG_SCHEDULER_RANDOM_STATE ) ); 
    pos = FUNCCALL_AGAIN(scheme_rand ((Scheme_Random_State * ) rand_state ) ); 
    syncing -> start_pos = (pos % evt_set -> argc ) ; 
  }
  RET_VALUE_START (syncing ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 5086 */
static void * splice_ptr_array (void * * a , int al , void * * b , int bl , int i ) {
  void * * r ; 
  int j ; 
  DECL_RET_SAVE (void * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(a, 0), PUSH(r, 1), PUSH(b, 2)));
# define XfOrM702_COUNT (3)
# define SETUP_XfOrM702(x) SETUP(XfOrM702_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  r = NULLED_OUT ; 
  r = ((void * * ) FUNCCALL(SETUP_XfOrM702(_), GC_malloc (sizeof (void * ) * (al + bl - 1 ) ) )) ; 
  if (a )
    (memcpy (r , a , i * sizeof (void * ) ) ) ; 
  if (b )
    (memcpy (r + i , b , bl * sizeof (void * ) ) ) ; 
  else {
    for (j = 0 ; j < bl ; j ++ ) {
      r [i + j ] = a [i ] ; 
    }
  }
  if (a )
    (memcpy (r + (i + bl ) , a + (i + 1 ) , (al - i - 1 ) * sizeof (void * ) ) ) ; 
  RET_VALUE_START (r ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 5184 */
/* this far 5184 */
static void set_sync_target (Syncing * syncing , int i , Scheme_Object * target , Scheme_Object * wrap , Scheme_Object * nack , int repost , int retry ) {
  Evt_Set * evt_set = syncing -> set ; 
  PREPARE_VAR_STACK(9);
  BLOCK_SETUP_TOP((PUSH(syncing, 0), PUSH(evt_set, 1), PUSH(target, 2), PUSH(nack, 3), PUSH(wrap, 4)));
# define XfOrM706_COUNT (5)
# define SETUP_XfOrM706(x) SETUP(XfOrM706_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (wrap ) {
#   define XfOrM722_COUNT (0+XfOrM706_COUNT)
#   define SETUP_XfOrM722(x) SETUP_XfOrM706(x)
    if (! syncing -> wrapss ) {
      Scheme_Object * * wrapss ; 
      BLOCK_SETUP((PUSH(wrapss, 0+XfOrM722_COUNT)));
#     define XfOrM723_COUNT (1+XfOrM722_COUNT)
#     define SETUP_XfOrM723(x) SETUP(XfOrM723_COUNT)
      wrapss = NULLED_OUT ; 
      wrapss = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM723(_), GC_malloc (sizeof (Scheme_Object * ) * (evt_set -> argc ) ) )) ; 
      syncing -> wrapss = wrapss ; 
    }
    if (! syncing -> wrapss [i ] )
      syncing -> wrapss [i ] = scheme_null ; 
    wrap = FUNCCALL(SETUP_XfOrM722(_), scheme_make_pair (wrap , syncing -> wrapss [i ] ) ); 
    syncing -> wrapss [i ] = wrap ; 
  }
  if (nack ) {
#   define XfOrM720_COUNT (0+XfOrM706_COUNT)
#   define SETUP_XfOrM720(x) SETUP_XfOrM706(x)
    if (! syncing -> nackss ) {
      Scheme_Object * * nackss ; 
      BLOCK_SETUP((PUSH(nackss, 0+XfOrM720_COUNT)));
#     define XfOrM721_COUNT (1+XfOrM720_COUNT)
#     define SETUP_XfOrM721(x) SETUP(XfOrM721_COUNT)
      nackss = NULLED_OUT ; 
      nackss = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM721(_), GC_malloc (sizeof (Scheme_Object * ) * (evt_set -> argc ) ) )) ; 
      syncing -> nackss = nackss ; 
    }
    if (! syncing -> nackss [i ] )
      syncing -> nackss [i ] = scheme_null ; 
    nack = FUNCCALL(SETUP_XfOrM720(_), scheme_make_pair (nack , syncing -> nackss [i ] ) ); 
    syncing -> nackss [i ] = nack ; 
  }
  if (repost ) {
#   define XfOrM718_COUNT (0+XfOrM706_COUNT)
#   define SETUP_XfOrM718(x) SETUP_XfOrM706(x)
    if (! syncing -> reposts ) {
      char * s ; 
      BLOCK_SETUP((PUSH(s, 0+XfOrM718_COUNT)));
#     define XfOrM719_COUNT (1+XfOrM718_COUNT)
#     define SETUP_XfOrM719(x) SETUP(XfOrM719_COUNT)
      s = NULLED_OUT ; 
      s = (char * ) FUNCCALL(SETUP_XfOrM719(_), GC_malloc_atomic (evt_set -> argc ) ); 
      (memset (s , 0 , evt_set -> argc ) ) ; 
      syncing -> reposts = s ; 
    }
    syncing -> reposts [i ] = 1 ; 
  }
  if (((Scheme_Type ) (((((long ) (target ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (target ) ) -> type ) ) == (Scheme_Type ) (scheme_evt_set_type ) ) && retry ) {
    Evt_Set * wts = (Evt_Set * ) target ; 
    BLOCK_SETUP((PUSH(wts, 0+XfOrM706_COUNT)));
#   define XfOrM708_COUNT (1+XfOrM706_COUNT)
#   define SETUP_XfOrM708(x) SETUP(XfOrM708_COUNT)
    if (wts -> argc == 1 ) {
      evt_set -> argv [i ] = wts -> argv [0 ] ; 
      evt_set -> ws [i ] = wts -> ws [0 ] ; 
    }
    else {
      Scheme_Object * * argv ; 
      Evt * * ws ; 
      BLOCK_SETUP((PUSH(ws, 0+XfOrM708_COUNT), PUSH(argv, 1+XfOrM708_COUNT)));
#     define XfOrM709_COUNT (2+XfOrM708_COUNT)
#     define SETUP_XfOrM709(x) SETUP(XfOrM709_COUNT)
      argv = NULLED_OUT ; 
      ws = NULLED_OUT ; 
      argv = (Scheme_Object * * ) FUNCCALL(SETUP_XfOrM709(_), splice_ptr_array ((void * * ) evt_set -> argv , evt_set -> argc , (void * * ) wts -> argv , wts -> argc , i ) ); 
      ws = (Evt * * ) FUNCCALL(SETUP_XfOrM709(_), splice_ptr_array ((void * * ) evt_set -> ws , evt_set -> argc , (void * * ) wts -> ws , wts -> argc , i ) ); 
      evt_set -> argv = argv ; 
      evt_set -> ws = ws ; 
      if (syncing -> wrapss ) {
#       define XfOrM716_COUNT (0+XfOrM709_COUNT)
#       define SETUP_XfOrM716(x) SETUP_XfOrM709(x)
        argv = (Scheme_Object * * ) FUNCCALL(SETUP_XfOrM716(_), splice_ptr_array ((void * * ) syncing -> wrapss , evt_set -> argc , (void * * ) ((void * ) 0 ) , wts -> argc , i ) ); 
        syncing -> wrapss = argv ; 
      }
      if (syncing -> nackss ) {
#       define XfOrM715_COUNT (0+XfOrM709_COUNT)
#       define SETUP_XfOrM715(x) SETUP_XfOrM709(x)
        argv = (Scheme_Object * * ) FUNCCALL(SETUP_XfOrM715(_), splice_ptr_array ((void * * ) syncing -> nackss , evt_set -> argc , (void * * ) ((void * ) 0 ) , wts -> argc , i ) ); 
        syncing -> nackss = argv ; 
      }
      if (syncing -> reposts ) {
        char * s ; 
        int len ; 
        BLOCK_SETUP((PUSH(s, 0+XfOrM709_COUNT)));
#       define XfOrM714_COUNT (1+XfOrM709_COUNT)
#       define SETUP_XfOrM714(x) SETUP(XfOrM714_COUNT)
        s = NULLED_OUT ; 
        len = evt_set -> argc + wts -> argc - 1 ; 
        s = (char * ) FUNCCALL(SETUP_XfOrM714(_), GC_malloc_atomic (len ) ); 
        (memset (s , 0 , len ) ) ; 
        (memcpy (s , syncing -> reposts , i ) ) ; 
        (memcpy (s + i + wts -> argc , syncing -> reposts + i + 1 , evt_set -> argc - i - 1 ) ) ; 
        syncing -> reposts = s ; 
      }
      evt_set -> argc += (wts -> argc - 1 ) ; 
      argv = evt_set -> argv ; 
      for (i = evt_set -> argc ; i -- ; ) {
        if (((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_channel_syncer_type ) ) ) {
          ((Scheme_Channel_Syncer * ) argv [i ] ) -> syncing_i = i ; 
        }
      }
    }
  }
  else {
    Evt * ww ; 
    BLOCK_SETUP((PUSH(ww, 0+XfOrM706_COUNT)));
#   define XfOrM707_COUNT (1+XfOrM706_COUNT)
#   define SETUP_XfOrM707(x) SETUP(XfOrM707_COUNT)
    ww = NULLED_OUT ; 
    evt_set -> argv [i ] = target ; 
    ww = FUNCCALL(SETUP_XfOrM707(_), find_evt (target ) ); 
    evt_set -> ws [i ] = ww ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_set_sync_target (Scheme_Schedule_Info * sinfo , Scheme_Object * target , Scheme_Object * wrap , Scheme_Object * nack , int repost , int retry ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(sinfo, 0)));
# define XfOrM724_COUNT (1)
# define SETUP_XfOrM724(x) SETUP(XfOrM724_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM724(_), set_sync_target ((Syncing * ) sinfo -> current_syncing , sinfo -> w_i , target , wrap , nack , repost , retry ) ); 
  if (retry ) {
    sinfo -> w_i -- ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int syncing_ready (Scheme_Object * s , Scheme_Schedule_Info * sinfo ) {
  int i , redirections = 0 , all_semas = 1 , j , result = 0 ; 
  Evt * w ; 
  Scheme_Object * o ; 
  Scheme_Schedule_Info r_sinfo ; 
  Syncing * syncing = (Syncing * ) s ; 
  Evt_Set * evt_set ; 
  int is_poll ; 
  double sleep_end ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(9);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(w, 1), PUSH(sinfo, 2), PUSH(r_sinfo.false_positive_ok, 3), PUSH(r_sinfo.current_syncing, 4), PUSH(syncing, 5), PUSH(evt_set, 6), PUSH(s, 7)));
# define XfOrM726_COUNT (8)
# define SETUP_XfOrM726(x) SETUP(XfOrM726_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  w = NULLED_OUT ; 
  o = NULLED_OUT ; 
  r_sinfo.false_positive_ok = NULLED_OUT ; 
  r_sinfo.current_syncing = NULLED_OUT ; 
  evt_set = NULLED_OUT ; 
  sleep_end = syncing -> sleep_end ; 
  if (syncing -> result ) {
    result = 1 ; 
    goto set_sleep_end_and_return ; 
  }
  evt_set = syncing -> set ; 
  is_poll = (syncing -> timeout == 0.0 ) ; 
  for (j = 0 ; j < evt_set -> argc ; j ++ ) {
    Scheme_Ready_Fun_FPC ready ; 
#   define XfOrM740_COUNT (0+XfOrM726_COUNT)
#   define SETUP_XfOrM740(x) SETUP_XfOrM726(x)
    i = (j + syncing -> start_pos ) % evt_set -> argc ; 
    o = evt_set -> argv [i ] ; 
    w = evt_set -> ws [i ] ; 
    ready = w -> ready ; 
    if (! ((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_sema_type ) ) && ! ((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_channel_type ) ) && ! ((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_channel_put_type ) ) && ! ((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_channel_syncer_type ) ) && ! ((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_never_evt_type ) ) )
      all_semas = 0 ; 
    if (ready ) {
      int yep ; 
#     define XfOrM742_COUNT (0+XfOrM740_COUNT)
#     define SETUP_XfOrM742(x) SETUP_XfOrM740(x)
      FUNCCALL(SETUP_XfOrM742(_), init_schedule_info (& r_sinfo , sinfo -> false_positive_ok , sleep_end ) ); 
      r_sinfo . current_syncing = (Scheme_Object * ) syncing ; 
      r_sinfo . w_i = i ; 
      r_sinfo . is_poll = is_poll ; 
      yep = FUNCCALL(SETUP_XfOrM742(_), ready (o , & r_sinfo ) ); 
      sleep_end = r_sinfo . sleep_end ; 
      if ((i > r_sinfo . w_i ) && sinfo -> false_positive_ok ) {
        redirections ++ ; 
        if (redirections > 10 ) {
          sinfo -> potentially_false_positive = 1 ; 
          result = 1 ; 
          goto set_sleep_end_and_return ; 
        }
      }
      j += (r_sinfo . w_i - i ) ; 
      if (yep ) {
#       define XfOrM744_COUNT (0+XfOrM742_COUNT)
#       define SETUP_XfOrM744(x) SETUP_XfOrM742(x)
        if (! r_sinfo . potentially_false_positive ) {
#         define XfOrM746_COUNT (0+XfOrM744_COUNT)
#         define SETUP_XfOrM746(x) SETUP_XfOrM744(x)
          syncing -> result = i + 1 ; 
          if (syncing -> disable_break )
            syncing -> disable_break -> suspend_break ++ ; 
          if (syncing -> reposts && syncing -> reposts [i ] )
            FUNCCALL(SETUP_XfOrM746(_), scheme_post_sema (o ) ); 
          FUNCCALL(SETUP_XfOrM746(_), scheme_post_syncing_nacks (syncing ) ); 
          result = 1 ; 
          goto set_sleep_end_and_return ; 
        }
        else {
          sinfo -> potentially_false_positive = 1 ; 
          result = 1 ; 
          goto set_sleep_end_and_return ; 
        }
      }
      else if (r_sinfo . spin ) {
        sinfo -> spin = 1 ; 
      }
    }
    else if (w -> get_sema ) {
      int repost = 0 ; 
      Scheme_Sync_Sema_Fun get_sema = w -> get_sema ; 
      Scheme_Object * sema ; 
      BLOCK_SETUP((PUSH(sema, 0+XfOrM740_COUNT)));
#     define XfOrM741_COUNT (1+XfOrM740_COUNT)
#     define SETUP_XfOrM741(x) SETUP(XfOrM741_COUNT)
      sema = NULLED_OUT ; 
      sema = FUNCCALL(SETUP_XfOrM741(_), get_sema (o , & repost ) ); 
      FUNCCALL_AGAIN(set_sync_target (syncing , i , sema , o , ((void * ) 0 ) , repost , 1 ) ); 
      j -- ; 
    }
  }
  if (syncing -> timeout >= 0.0 ) {
#   define XfOrM730_COUNT (0+XfOrM726_COUNT)
#   define SETUP_XfOrM730(x) SETUP_XfOrM726(x)
    if (syncing -> sleep_end <= FUNCCALL(SETUP_XfOrM730(_), scheme_get_inexact_milliseconds () ))
      result = 1 ; 
  }
  else if (all_semas ) {
#   define XfOrM727_COUNT (0+XfOrM726_COUNT)
#   define SETUP_XfOrM727(x) SETUP_XfOrM726(x)
    if (sinfo -> false_positive_ok ) {
      sinfo -> potentially_false_positive = 1 ; 
      result = 1 ; 
    }
    else {
#     define XfOrM728_COUNT (0+XfOrM727_COUNT)
#     define SETUP_XfOrM728(x) SETUP_XfOrM727(x)
      FUNCCALL(SETUP_XfOrM728(_), scheme_wait_semas_chs (syncing -> set -> argc , syncing -> set -> argv , 0 , syncing ) ); 
      FUNCCALL(SETUP_XfOrM728(_), scheme_check_break_now () ); 
      result = 1 ; 
    }
  }
  set_sleep_end_and_return : syncing -> sleep_end = sleep_end ; 
  if (syncing -> sleep_end && (! sinfo -> sleep_end || (sinfo -> sleep_end > syncing -> sleep_end ) ) )
    sinfo -> sleep_end = syncing -> sleep_end ; 
  RET_VALUE_START (result ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void syncing_needs_wakeup (Scheme_Object * s , void * fds ) {
  int i ; 
  Scheme_Object * o ; 
  Evt * w ; 
  Evt_Set * evt_set = ((Syncing * ) s ) -> set ; 
  PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(evt_set, 1), PUSH(fds, 2), PUSH(w, 3)));
# define XfOrM750_COUNT (4)
# define SETUP_XfOrM750(x) SETUP(XfOrM750_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  o = NULLED_OUT ; 
  w = NULLED_OUT ; 
  for (i = 0 ; i < evt_set -> argc ; i ++ ) {
#   define XfOrM753_COUNT (0+XfOrM750_COUNT)
#   define SETUP_XfOrM753(x) SETUP_XfOrM750(x)
    o = evt_set -> argv [i ] ; 
    w = evt_set -> ws [i ] ; 
    if (w -> needs_wakeup ) {
      Scheme_Needs_Wakeup_Fun nw = w -> needs_wakeup ; 
#     define XfOrM754_COUNT (0+XfOrM753_COUNT)
#     define SETUP_XfOrM754(x) SETUP_XfOrM753(x)
      FUNCCALL(SETUP_XfOrM754(_), nw (o , fds ) ); 
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * evt_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (scheme_is_evt (argv [0 ] ) ? scheme_true : scheme_false ) ; 
}
Evt_Set * make_evt_set (const char * name , int argc , Scheme_Object * * argv , int delta ) {
  Evt * w , * * iws , * * ws ; 
  Evt_Set * evt_set , * subset ; 
  Scheme_Object * * args ; 
  int i , j , count = 0 ; 
  DECL_RET_SAVE (Evt_Set * ) PREPARE_VAR_STACK_ONCE(8);
  BLOCK_SETUP_TOP((PUSH(ws, 0), PUSH(iws, 1), PUSH(evt_set, 2), PUSH(name, 3), PUSH(args, 4), PUSH(subset, 5), PUSH(argv, 6), PUSH(w, 7)));
# define XfOrM756_COUNT (8)
# define SETUP_XfOrM756(x) SETUP(XfOrM756_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  w = NULLED_OUT ; 
  iws = NULLED_OUT ; 
  ws = NULLED_OUT ; 
  evt_set = NULLED_OUT ; 
  subset = NULLED_OUT ; 
  args = NULLED_OUT ; 
  iws = ((Evt * * ) FUNCCALL(SETUP_XfOrM756(_), GC_malloc (sizeof (Evt * ) * (argc - delta ) ) )) ; 
  for (i = 0 ; i < (argc - delta ) ; i ++ ) {
#   define XfOrM771_COUNT (0+XfOrM756_COUNT)
#   define SETUP_XfOrM771(x) SETUP_XfOrM756(x)
    if (! ((Scheme_Type ) (((((long ) (argv [i + delta ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i + delta ] ) ) -> type ) ) == (Scheme_Type ) (scheme_evt_set_type ) ) ) {
#     define XfOrM773_COUNT (0+XfOrM771_COUNT)
#     define SETUP_XfOrM773(x) SETUP_XfOrM771(x)
      w = FUNCCALL(SETUP_XfOrM773(_), find_evt (argv [i + delta ] ) ); 
      if (! w ) {
#       define XfOrM774_COUNT (0+XfOrM773_COUNT)
#       define SETUP_XfOrM774(x) SETUP_XfOrM773(x)
        FUNCCALL_EMPTY(scheme_wrong_type (name , "evt" , i + delta , argc , argv ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      iws [i ] = w ; 
      count ++ ; 
    }
    else {
      count += ((Evt_Set * ) argv [i + delta ] ) -> argc ; 
    }
  }
  evt_set = ((Evt_Set * ) FUNCCALL(SETUP_XfOrM756(_), GC_malloc_one_small_tagged ((((sizeof (Evt_Set ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  evt_set -> so . type = scheme_evt_set_type ; 
  evt_set -> argc = count ; 
  if (count == (argc - delta ) )
    ws = iws ; 
  else ws = ((Evt * * ) FUNCCALL(SETUP_XfOrM756(_), GC_malloc (sizeof (Evt * ) * (count ) ) )) ; 
  args = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM756(_), GC_malloc (sizeof (Scheme_Object * ) * (count ) ) )) ; 
  for (i = delta , j = 0 ; i < argc ; i ++ , j ++ ) {
    if (((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_evt_set_type ) ) ) {
      int k , n ; 
      subset = (Evt_Set * ) argv [i ] ; 
      n = subset -> argc ; 
      for (k = 0 ; k < n ; k ++ , j ++ ) {
        args [j ] = subset -> argv [k ] ; 
        ws [j ] = subset -> ws [k ] ; 
      }
      -- j ; 
    }
    else {
      ws [j ] = iws [i - delta ] ; 
      args [j ] = argv [i ] ; 
    }
  }
  evt_set -> ws = ws ; 
  evt_set -> argv = args ; 
  RET_VALUE_START (evt_set ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_evt_set (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return (Scheme_Object * ) make_evt_set ("internal-make-evt-set" , argc , argv , 0 ) ; 
}
void scheme_post_syncing_nacks (Syncing * syncing ) {
  int i , c ; 
  Scheme_Object * l ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(syncing, 0), PUSH(l, 1)));
# define XfOrM776_COUNT (2)
# define SETUP_XfOrM776(x) SETUP(XfOrM776_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  l = NULLED_OUT ; 
  if (syncing -> set ) {
#   define XfOrM777_COUNT (0+XfOrM776_COUNT)
#   define SETUP_XfOrM777(x) SETUP_XfOrM776(x)
    c = syncing -> set -> argc ; 
    for (i = 0 ; i < c ; i ++ ) {
#     define XfOrM784_COUNT (0+XfOrM777_COUNT)
#     define SETUP_XfOrM784(x) SETUP_XfOrM777(x)
      if (((Scheme_Type ) (((((long ) (syncing -> set -> argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (syncing -> set -> argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_channel_syncer_type ) ) )
        FUNCCALL(SETUP_XfOrM784(_), scheme_get_outof_line ((Scheme_Channel_Syncer * ) syncing -> set -> argv [i ] ) ); 
      if (syncing -> nackss ) {
#       define XfOrM785_COUNT (0+XfOrM784_COUNT)
#       define SETUP_XfOrM785(x) SETUP_XfOrM784(x)
        if ((i + 1 ) != syncing -> result ) {
#         define XfOrM786_COUNT (0+XfOrM785_COUNT)
#         define SETUP_XfOrM786(x) SETUP_XfOrM785(x)
          l = syncing -> nackss [i ] ; 
          if (l ) {
#           define XfOrM787_COUNT (0+XfOrM786_COUNT)
#           define SETUP_XfOrM787(x) SETUP_XfOrM786(x)
            for (; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#             define XfOrM789_COUNT (0+XfOrM787_COUNT)
#             define SETUP_XfOrM789(x) SETUP_XfOrM787(x)
              FUNCCALL(SETUP_XfOrM789(_), scheme_post_sema_all ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ) ); 
            }
          }
          syncing -> nackss [i ] = ((void * ) 0 ) ; 
        }
      }
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_sync (const char * name , int argc , Scheme_Object * argv [] , int with_break , int with_timeout , int _tailok ) {
  volatile int tailok = _tailok ; 
  Evt_Set * volatile evt_set ; 
  Syncing * volatile syncing ; 
  volatile float timeout = - 1.0 ; 
  double start_time ; 
  Scheme_Cont_Frame_Data cframe ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(12);
  BLOCK_SETUP_TOP((PUSH(syncing, 0), PUSH(evt_set, 1), PUSH(cframe.cache, 2), PUSH(argv, 3), PUSH(name, 4)));
# define XfOrM790_COUNT (5)
# define SETUP_XfOrM790(x) SETUP(XfOrM790_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  evt_set = NULLED_OUT ; 
  syncing = NULLED_OUT ; 
  cframe.cache = NULLED_OUT ; 
  if (with_timeout ) {
#   define XfOrM827_COUNT (0+XfOrM790_COUNT)
#   define SETUP_XfOrM827(x) SETUP_XfOrM790(x)
    if (! (((argv [0 ] ) ) == (scheme_false ) ) ) {
#     define XfOrM828_COUNT (0+XfOrM827_COUNT)
#     define SETUP_XfOrM828(x) SETUP_XfOrM827(x)
      if (((((long ) (argv [0 ] ) ) & 0x1 ) || ((((argv [0 ] ) -> type ) >= scheme_bignum_type ) && (((argv [0 ] ) -> type ) <= scheme_complex_izi_type ) ) ) )
        timeout = (float ) (scheme_real_to_double (argv [0 ] ) ) ; 
      if (timeout < 0.0 ) {
#       define XfOrM829_COUNT (0+XfOrM828_COUNT)
#       define SETUP_XfOrM829(x) SETUP_XfOrM828(x)
        FUNCCALL(SETUP_XfOrM829(_), scheme_wrong_type (name , "non-negative real number" , 0 , argc , argv ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      start_time = FUNCCALL(SETUP_XfOrM828(_), scheme_get_inexact_milliseconds () ); 
    }
    else start_time = 0 ; 
  }
  else {
    start_time = 0 ; 
  }
  if (argc == (with_timeout + 1 ) && ! start_time && ((Scheme_Type ) (((((long ) (argv [with_timeout ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [with_timeout ] ) ) -> type ) ) == (Scheme_Type ) (scheme_sema_type ) ) ) {
#   define XfOrM825_COUNT (0+XfOrM790_COUNT)
#   define SETUP_XfOrM825(x) SETUP_XfOrM790(x)
    FUNCCALL(SETUP_XfOrM825(_), scheme_wait_sema (argv [with_timeout ] , with_break ? - 1 : 0 ) ); 
    RET_VALUE_START (argv [with_timeout ] ) RET_VALUE_END ; 
  }
  evt_set = ((void * ) 0 ) ; 
  if ((argc == (with_timeout + 1 ) ) && ((Scheme_Type ) (((((long ) (argv [with_timeout ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [with_timeout ] ) ) -> type ) ) == (Scheme_Type ) (scheme_evt_set_type ) ) ) {
    int i ; 
    evt_set = (Evt_Set * ) argv [with_timeout ] ; 
    for (i = evt_set -> argc ; i -- ; ) {
      if (evt_set -> ws [i ] -> can_redirect ) {
        evt_set = ((void * ) 0 ) ; 
        break ; 
      }
    }
  }
  if (! evt_set )
    evt_set = FUNCCALL(SETUP_XfOrM790(_), make_evt_set (name , argc , argv , with_timeout ) ); 
  if (with_break ) {
#   define XfOrM819_COUNT (0+XfOrM790_COUNT)
#   define SETUP_XfOrM819(x) SETUP_XfOrM790(x)
    FUNCCALL(SETUP_XfOrM819(_), scheme_push_break_enable (& cframe , 1 , 1 ) ); 
  }
  if (timeout < 0.0 ) {
    int i ; 
#   define XfOrM813_COUNT (0+XfOrM790_COUNT)
#   define SETUP_XfOrM813(x) SETUP_XfOrM790(x)
    for (i = evt_set -> argc ; i -- ; ) {
      if (! ((Scheme_Type ) (((((long ) (evt_set -> argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (evt_set -> argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_sema_type ) ) )
        break ; 
    }
    if (i < 0 ) {
#     define XfOrM814_COUNT (0+XfOrM813_COUNT)
#     define SETUP_XfOrM814(x) SETUP_XfOrM813(x)
      i = FUNCCALL(SETUP_XfOrM814(_), scheme_wait_semas_chs (evt_set -> argc , evt_set -> argv , 0 , ((void * ) 0 ) ) ); 
      if (with_break ) {
#       define XfOrM816_COUNT (0+XfOrM814_COUNT)
#       define SETUP_XfOrM816(x) SETUP_XfOrM814(x)
        FUNCCALL(SETUP_XfOrM816(_), scheme_pop_break_enable (& cframe , 1 ) ); 
      }
      else {
#       define XfOrM815_COUNT (0+XfOrM814_COUNT)
#       define SETUP_XfOrM815(x) SETUP_XfOrM814(x)
        FUNCCALL(SETUP_XfOrM815(_), scheme_check_break_now () ); 
      }
      if (i )
        RET_VALUE_START (evt_set -> argv [i - 1 ] ) RET_VALUE_END ; 
      else RET_VALUE_START ((tailok ? scheme_false : ((void * ) 0 ) ) ) RET_VALUE_END ; 
    }
  }
  syncing = FUNCCALL(SETUP_XfOrM790(_), make_syncing (evt_set , timeout , start_time ) ); 
  if (timeout < 0.0 )
    timeout = 0.0 ; 
  if (with_break ) {
    syncing -> disable_break = scheme_current_thread ; 
  }
  {
    mz_jmp_buf * volatile savebuf , newbuf ; 
    BLOCK_SETUP((PUSH(savebuf, 0+XfOrM790_COUNT)));
#   define XfOrM809_COUNT (1+XfOrM790_COUNT)
#   define SETUP_XfOrM809(x) SETUP(XfOrM809_COUNT)
    savebuf = NULLED_OUT ; 
    FUNCCALL(SETUP_XfOrM809(_), scheme_push_kill_action ((Scheme_Kill_Action_Func ) scheme_post_syncing_nacks , (void * ) syncing ) ); 
    savebuf = scheme_current_thread -> error_buf ; 
    scheme_current_thread -> error_buf = & newbuf ; 
    if (((newbuf ) . gcvs = (long ) __gc_var_stack__ , (newbuf ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((newbuf ) . jb ) , (_setjmp (((newbuf ) . jb ) -> jb ) ) ) ) ) {
#     define XfOrM811_COUNT (0+XfOrM809_COUNT)
#     define SETUP_XfOrM811(x) SETUP_XfOrM809(x)
      FUNCCALL(SETUP_XfOrM811(_), scheme_pop_kill_action () ); 
      FUNCCALL(SETUP_XfOrM811(_), scheme_post_syncing_nacks (syncing ) ); 
      (((long * ) (void * ) ((* savebuf ) . gcvs ) ) [1 ] = (* savebuf ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* savebuf ) . gcvs , scheme_jit_longjmp ((* savebuf ) . jb , 1 ) ) ; 
    }
    else {
#     define XfOrM810_COUNT (0+XfOrM809_COUNT)
#     define SETUP_XfOrM810(x) SETUP_XfOrM809(x)
      ; 
      FUNCCALL(SETUP_XfOrM810(_), scheme_block_until ((Scheme_Ready_Fun ) syncing_ready , syncing_needs_wakeup , (Scheme_Object * ) syncing , timeout ) ); 
      FUNCCALL_AGAIN(scheme_pop_kill_action () ); 
      scheme_current_thread -> error_buf = savebuf ; 
    }
  }
  ; 
  if (! syncing -> result )
    FUNCCALL(SETUP_XfOrM790(_), scheme_post_syncing_nacks (syncing ) ); 
  if (with_break ) {
#   define XfOrM808_COUNT (0+XfOrM790_COUNT)
#   define SETUP_XfOrM808(x) SETUP_XfOrM790(x)
    FUNCCALL(SETUP_XfOrM808(_), scheme_pop_break_enable (& cframe , 0 ) ); 
  }
  if (with_break ) {
    -- syncing -> disable_break -> suspend_break ; 
  }
  if (syncing -> result ) {
    Scheme_Object * o , * l , * a , * to_call = ((void * ) 0 ) , * args [1 ] ; 
    int to_call_is_cont = 0 ; 
    BLOCK_SETUP((PUSHARRAY(args, 1, 0+XfOrM790_COUNT), PUSH(o, 3+XfOrM790_COUNT), PUSH(a, 4+XfOrM790_COUNT), PUSH(to_call, 5+XfOrM790_COUNT), PUSH(l, 6+XfOrM790_COUNT)));
#   define XfOrM791_COUNT (7+XfOrM790_COUNT)
#   define SETUP_XfOrM791(x) SETUP(XfOrM791_COUNT)
    o = NULLED_OUT ; 
    l = NULLED_OUT ; 
    a = NULLED_OUT ; 
    args[0] = NULLED_OUT ; 
    o = evt_set -> argv [syncing -> result - 1 ] ; 
    if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_channel_syncer_type ) ) ) {
      o = ((Scheme_Channel_Syncer * ) o ) -> obj ; 
    }
    if (syncing -> wrapss ) {
#     define XfOrM792_COUNT (0+XfOrM791_COUNT)
#     define SETUP_XfOrM792(x) SETUP_XfOrM791(x)
      l = syncing -> wrapss [syncing -> result - 1 ] ; 
      if (l ) {
#       define XfOrM793_COUNT (0+XfOrM792_COUNT)
#       define SETUP_XfOrM793(x) SETUP_XfOrM792(x)
        for (; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#         define XfOrM802_COUNT (0+XfOrM793_COUNT)
#         define SETUP_XfOrM802(x) SETUP_XfOrM793(x)
          a = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
          if (to_call ) {
#           define XfOrM805_COUNT (0+XfOrM802_COUNT)
#           define SETUP_XfOrM805(x) SETUP_XfOrM802(x)
            args [0 ] = o ; 
            FUNCCALL(SETUP_XfOrM805(_), scheme_push_break_enable (& cframe , 0 , 0 ) ); 
            o = FUNCCALL_AGAIN(scheme_apply (to_call , 1 , args ) ); 
            FUNCCALL_AGAIN(scheme_pop_break_enable (& cframe , 0 ) ); 
            to_call = ((void * ) 0 ) ; 
          }
          if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) || (! (((long ) (a ) ) & 0x1 ) && ((((a ) -> type ) >= scheme_prim_type ) && (((a ) -> type ) <= scheme_native_closure_type ) ) ) ) {
            if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) {
              a = (((Scheme_Small_Object * ) (a ) ) -> u . ptr_val ) ; 
              to_call_is_cont = 1 ; 
            }
            to_call = a ; 
          }
          else if (((Scheme_Type ) (scheme_thread_suspend_type ) == (Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) ) || ((Scheme_Type ) (scheme_thread_resume_type ) == (Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) ) )
            o = (((Scheme_Simple_Object * ) (a ) ) -> u . two_ptr_val . ptr2 ) ; 
          else o = a ; 
        }
        if (to_call ) {
#         define XfOrM794_COUNT (0+XfOrM793_COUNT)
#         define SETUP_XfOrM794(x) SETUP_XfOrM793(x)
          args [0 ] = o ; 
          if (! to_call_is_cont ) {
#           define XfOrM797_COUNT (0+XfOrM794_COUNT)
#           define SETUP_XfOrM797(x) SETUP_XfOrM794(x)
            FUNCCALL(SETUP_XfOrM797(_), scheme_push_break_enable (& cframe , 0 , 0 ) ); 
            tailok = 0 ; 
          }
          if (tailok ) {
#           define XfOrM796_COUNT (0+XfOrM794_COUNT)
#           define SETUP_XfOrM796(x) SETUP_XfOrM794(x)
            RET_VALUE_START (FUNCCALL(SETUP_XfOrM796(_), scheme_tail_apply (to_call , 1 , args ) )) RET_VALUE_END ; 
          }
          else {
#           define XfOrM795_COUNT (0+XfOrM794_COUNT)
#           define SETUP_XfOrM795(x) SETUP_XfOrM794(x)
            o = FUNCCALL(SETUP_XfOrM795(_), scheme_apply (to_call , 1 , args ) ); 
            if (! to_call_is_cont )
              FUNCCALL(SETUP_XfOrM795(_), scheme_pop_break_enable (& cframe , 1 ) ); 
            RET_VALUE_START (o ) RET_VALUE_END ; 
          }
        }
      }
    }
    RET_VALUE_START (o ) RET_VALUE_END ; 
  }
  else if (tailok )
    RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
  else RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * sch_sync (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_sync ("sync" , argc , argv , 0 , 0 , 1 ) ; 
}
static Scheme_Object * sch_sync_timeout (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_sync ("sync/timeout" , argc , argv , 0 , 1 , 1 ) ; 
}
Scheme_Object * scheme_sync (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_sync ("sync" , argc , argv , 0 , 0 , 0 ) ; 
}
Scheme_Object * scheme_sync_timeout (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_sync ("sync/timeout" , argc , argv , 0 , 1 , 0 ) ; 
}
static Scheme_Object * do_scheme_sync_enable_break (const char * who , int with_timeout , int tailok , int argc , Scheme_Object * argv [] ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(who, 1)));
# define XfOrM834_COUNT (2)
# define SETUP_XfOrM834(x) SETUP(XfOrM834_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (argc == 2 && (((argv [0 ] ) ) == (scheme_false ) ) && ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_sema_type ) ) ) {
#   define XfOrM835_COUNT (0+XfOrM834_COUNT)
#   define SETUP_XfOrM835(x) SETUP_XfOrM834(x)
    FUNCCALL(SETUP_XfOrM835(_), scheme_wait_sema (argv [1 ] , - 1 ) ); 
    RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(do_sync (who , argc , argv , 1 , with_timeout , tailok ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_sync_enable_break (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_scheme_sync_enable_break ("sync/enable-break" , 0 , 0 , argc , argv ) ; 
}
static Scheme_Object * sch_sync_enable_break (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_scheme_sync_enable_break ("sync/enable-break" , 0 , 1 , argc , argv ) ; 
}
static Scheme_Object * sch_sync_timeout_enable_break (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_scheme_sync_enable_break ("sync/timeout/enable-break" , 1 , 1 , argc , argv ) ; 
}
static Scheme_Object * evts_to_evt (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (Scheme_Object * ) make_evt_set ("choice-evt" , argc , argv , 0 ) ; 
}
Scheme_Object * scheme_make_thread_cell (Scheme_Object * def_val , int inherited ) {
  Thread_Cell * c ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(c, 0), PUSH(def_val, 1)));
# define XfOrM840_COUNT (2)
# define SETUP_XfOrM840(x) SETUP(XfOrM840_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  c = NULLED_OUT ; 
  c = ((Thread_Cell * ) FUNCCALL(SETUP_XfOrM840(_), GC_malloc_one_small_tagged ((((sizeof (Thread_Cell ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  c -> so . type = scheme_thread_cell_type ; 
  c -> def_val = def_val ; 
  c -> inherited = ! ! inherited ; 
  RET_VALUE_START ((Scheme_Object * ) c ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_thread_cell_get (Scheme_Object * cell , Scheme_Thread_Cell_Table * cells ) {
  Scheme_Object * v ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(cell, 0), PUSH(v, 1)));
# define XfOrM841_COUNT (2)
# define SETUP_XfOrM841(x) SETUP(XfOrM841_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  if (((Thread_Cell * ) cell ) -> assigned ) {
#   define XfOrM842_COUNT (0+XfOrM841_COUNT)
#   define SETUP_XfOrM842(x) SETUP_XfOrM841(x)
    v = FUNCCALL(SETUP_XfOrM842(_), scheme_lookup_in_table (cells , (const char * ) cell ) ); 
    if (v )
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_ephemeron_value (v ) )) RET_VALUE_EMPTY_END ; 
  }
  RET_VALUE_START (((Thread_Cell * ) cell ) -> def_val ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_thread_cell_set (Scheme_Object * cell , Scheme_Thread_Cell_Table * cells , Scheme_Object * v ) {
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(cell, 1), PUSH(cells, 2)));
# define XfOrM843_COUNT (3)
# define SETUP_XfOrM843(x) SETUP(XfOrM843_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! ((Thread_Cell * ) cell ) -> assigned )
    ((Thread_Cell * ) cell ) -> assigned = 1 ; 
  v = FUNCCALL(SETUP_XfOrM843(_), scheme_make_ephemeron (cell , v ) ); 
  FUNCCALL_EMPTY(scheme_add_to_table (cells , (const char * ) cell , (void * ) v , 0 ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Thread_Cell_Table * inherit_cells (Scheme_Thread_Cell_Table * cells , Scheme_Thread_Cell_Table * t , int inherited ) {
  Scheme_Bucket * bucket ; 
  Scheme_Object * cell , * v ; 
  int i ; 
  DECL_RET_SAVE (Scheme_Thread_Cell_Table * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(bucket, 1), PUSH(cell, 2), PUSH(t, 3), PUSH(cells, 4)));
# define XfOrM844_COUNT (5)
# define SETUP_XfOrM844(x) SETUP(XfOrM844_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  bucket = NULLED_OUT ; 
  cell = NULLED_OUT ; 
  v = NULLED_OUT ; 
  if (! cells )
    cells = scheme_current_thread -> cell_values ; 
  if (! t )
    t = FUNCCALL(SETUP_XfOrM844(_), scheme_make_bucket_table (20 , SCHEME_hash_weak_ptr ) ); 
  for (i = cells -> size ; i -- ; ) {
#   define XfOrM848_COUNT (0+XfOrM844_COUNT)
#   define SETUP_XfOrM848(x) SETUP_XfOrM844(x)
    bucket = cells -> buckets [i ] ; 
    if (bucket && bucket -> val && bucket -> key ) {
#     define XfOrM849_COUNT (0+XfOrM848_COUNT)
#     define SETUP_XfOrM849(x) SETUP_XfOrM848(x)
      cell = (Scheme_Object * ) (((Scheme_Small_Object * ) (bucket -> key ) ) -> u . ptr_val ) ; 
      if (cell && (((Thread_Cell * ) cell ) -> inherited == inherited ) ) {
#       define XfOrM850_COUNT (0+XfOrM849_COUNT)
#       define SETUP_XfOrM850(x) SETUP_XfOrM849(x)
        v = (Scheme_Object * ) bucket -> val ; 
        FUNCCALL(SETUP_XfOrM850(_), scheme_add_to_table (t , (char * ) cell , v , 0 ) ); 
      }
    }
  }
  RET_VALUE_START (t ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Thread_Cell_Table * scheme_inherit_cells (Scheme_Thread_Cell_Table * cells ) {
  /* No conversion */
  return inherit_cells (cells , ((void * ) 0 ) , 1 ) ; 
}
static Scheme_Object * thread_cell_values (int argc , Scheme_Object * argv [] ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM852_COUNT (1)
# define SETUP_XfOrM852(x) SETUP(XfOrM852_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (argc == 1 ) {
    Scheme_Thread_Cell_Table * naya ; 
    BLOCK_SETUP((PUSH(naya, 0+XfOrM852_COUNT)));
#   define XfOrM854_COUNT (1+XfOrM852_COUNT)
#   define SETUP_XfOrM854(x) SETUP(XfOrM854_COUNT)
    naya = NULLED_OUT ; 
    if (! ((Scheme_Type ) (scheme_thread_cell_values_type ) == (Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) ) ) {
#     define XfOrM855_COUNT (0+XfOrM854_COUNT)
#     define SETUP_XfOrM855(x) SETUP_XfOrM854(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("current-preserved-thread-cell-values" , "thread cell values" , 0 , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    naya = FUNCCALL(SETUP_XfOrM854(_), inherit_cells (((void * ) 0 ) , ((void * ) 0 ) , 0 ) ); 
    FUNCCALL(SETUP_XfOrM854(_), inherit_cells ((Scheme_Thread_Cell_Table * ) (((Scheme_Small_Object * ) (argv [0 ] ) ) -> u . ptr_val ) , naya , 1 ) ); 
    scheme_current_thread -> cell_values = naya ; 
    RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
  }
  else {
    Scheme_Object * o , * ht ; 
    BLOCK_SETUP((PUSH(o, 0+XfOrM852_COUNT), PUSH(ht, 1+XfOrM852_COUNT)));
#   define XfOrM853_COUNT (2+XfOrM852_COUNT)
#   define SETUP_XfOrM853(x) SETUP(XfOrM853_COUNT)
    o = NULLED_OUT ; 
    ht = NULLED_OUT ; 
    ht = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM853(_), inherit_cells (((void * ) 0 ) , ((void * ) 0 ) , 1 ) ); 
    o = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM853(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    o -> type = scheme_thread_cell_values_type ; 
    (((Scheme_Small_Object * ) (o ) ) -> u . ptr_val ) = ht ; 
    RET_VALUE_START (o ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_thread_cell (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_make_thread_cell (argv [0 ] , (argc > 1 ) && (! (((argv [1 ] ) ) == (scheme_false ) ) ) ) ; 
}
static Scheme_Object * thread_cell_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_cell_type ) ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * thread_cell_get (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_cell_type ) ) ) )
    scheme_wrong_type ("thread-cell-ref" , "thread cell" , 0 , argc , argv ) ; 
  return scheme_thread_cell_get (argv [0 ] , scheme_current_thread -> cell_values ) ; 
}
static Scheme_Object * thread_cell_set (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_cell_type ) ) ) )
    scheme_wrong_type ("thread-cell-set!" , "thread cell" , 0 , argc , argv ) ; 
  scheme_thread_cell_set (argv [0 ] , scheme_current_thread -> cell_values , argv [1 ] ) ; 
  return scheme_void ; 
}
static int max_configs = __MZCONFIG_BUILTIN_COUNT__ ; 
static Scheme_Object * do_param (void * data , int argc , Scheme_Object * argv [] ) ; 
Scheme_Config * scheme_current_config () {
  Scheme_Object * v ; 
  DECL_RET_SAVE (Scheme_Config * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(v, 0)));
# define XfOrM860_COUNT (1)
# define SETUP_XfOrM860(x) SETUP(XfOrM860_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  v = FUNCCALL(SETUP_XfOrM860(_), scheme_extract_one_cc_mark (((void * ) 0 ) , scheme_parameterization_key ) ); 
  if (! ((Scheme_Type ) (scheme_config_type ) == (Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) ) ) {
    (((long * ) (void * ) ((* (scheme_current_thread -> error_buf ) ) . gcvs ) ) [1 ] = (* (scheme_current_thread -> error_buf ) ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* (scheme_current_thread -> error_buf ) ) . gcvs , scheme_jit_longjmp ((* (scheme_current_thread -> error_buf ) ) . jb , 1 ) ) ; 
  }
  RET_VALUE_START ((Scheme_Config * ) v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Config * do_extend_config (Scheme_Config * c , Scheme_Object * key , Scheme_Object * cell ) {
  Scheme_Config * naya ; 
  DECL_RET_SAVE (Scheme_Config * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(c, 0), PUSH(naya, 1), PUSH(cell, 2), PUSH(key, 3)));
# define XfOrM862_COUNT (4)
# define SETUP_XfOrM862(x) SETUP(XfOrM862_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  naya = NULLED_OUT ; 
  if (c -> depth > 50 )
    FUNCCALL(SETUP_XfOrM862(_), scheme_flatten_config (c ) ); 
  naya = ((Scheme_Config * ) FUNCCALL(SETUP_XfOrM862(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Config ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  naya -> so . type = scheme_config_type ; 
  naya -> depth = c -> depth + 1 ; 
  naya -> key = key ; 
  naya -> cell = cell ; 
  naya -> next = c ; 
  RET_VALUE_START (naya ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Config * scheme_extend_config (Scheme_Config * c , int pos , Scheme_Object * init_val ) {
  /* No conversion */
  return do_extend_config (c , ((Scheme_Object * ) (void * ) (long ) ((((long ) (pos ) ) << 1 ) | 0x1 ) ) , init_val ) ; 
}
void scheme_install_config (Scheme_Config * config ) {
  /* No conversion */
  scheme_set_cont_mark (scheme_parameterization_key , (Scheme_Object * ) config ) ; 
}
Scheme_Object * find_param_cell (Scheme_Config * c , Scheme_Object * k , int force_cell ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(c, 0), PUSH(k, 1)));
# define XfOrM865_COUNT (2)
# define SETUP_XfOrM865(x) SETUP(XfOrM865_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  while (1 ) {
#   define XfOrM871_COUNT (0+XfOrM865_COUNT)
#   define SETUP_XfOrM871(x) SETUP_XfOrM865(x)
    if (((c -> key ) == (k ) ) ) {
#     define XfOrM874_COUNT (0+XfOrM871_COUNT)
#     define SETUP_XfOrM874(x) SETUP_XfOrM871(x)
      if (force_cell && ! (((Scheme_Type ) (((((long ) (c -> cell ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (c -> cell ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_cell_type ) ) ) ) {
        Scheme_Object * cell ; 
        BLOCK_SETUP((PUSH(cell, 0+XfOrM874_COUNT)));
#       define XfOrM875_COUNT (1+XfOrM874_COUNT)
#       define SETUP_XfOrM875(x) SETUP(XfOrM875_COUNT)
        cell = NULLED_OUT ; 
        cell = FUNCCALL(SETUP_XfOrM875(_), scheme_make_thread_cell (c -> cell , 1 ) ); 
        c -> cell = cell ; 
      }
      RET_VALUE_START (c -> cell ) RET_VALUE_END ; 
    }
    else if (! c -> next ) {
      Scheme_Parameterization * p = (Scheme_Parameterization * ) c -> cell ; 
#     define XfOrM872_COUNT (0+XfOrM871_COUNT)
#     define SETUP_XfOrM872(x) SETUP_XfOrM871(x)
      if ((((long ) (k ) ) & 0x1 ) )
        RET_VALUE_START (p -> prims [(((long ) (k ) ) >> 1 ) ] ) RET_VALUE_END ; 
      else {
#       define XfOrM873_COUNT (0+XfOrM872_COUNT)
#       define SETUP_XfOrM873(x) SETUP_XfOrM872(x)
        if (p -> extensions )
          RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_lookup_in_table (p -> extensions , (const char * ) k ) )) RET_VALUE_EMPTY_END ; 
        else RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
    }
    else c = c -> next ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_get_thread_param (Scheme_Config * c , Scheme_Thread_Cell_Table * cells , int pos ) {
  Scheme_Object * cell ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(cell, 0), PUSH(cells, 1)));
# define XfOrM876_COUNT (2)
# define SETUP_XfOrM876(x) SETUP(XfOrM876_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  cell = NULLED_OUT ; 
  cell = FUNCCALL(SETUP_XfOrM876(_), find_param_cell (c , ((Scheme_Object * ) (void * ) (long ) ((((long ) (pos ) ) << 1 ) | 0x1 ) ) , 0 ) ); 
  if ((((Scheme_Type ) (((((long ) (cell ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (cell ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_cell_type ) ) ) )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_thread_cell_get (cell , cells ) )) RET_VALUE_EMPTY_END ; 
  RET_VALUE_START (cell ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_get_param (Scheme_Config * c , int pos ) {
  /* No conversion */
  return scheme_get_thread_param (c , scheme_current_thread -> cell_values , pos ) ; 
}
void scheme_set_thread_param (Scheme_Config * c , Scheme_Thread_Cell_Table * cells , int pos , Scheme_Object * o ) {
  Scheme_Object * __funcarg77 = NULLED_OUT ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(cells, 1)));
# define XfOrM878_COUNT (2)
# define SETUP_XfOrM878(x) SETUP(XfOrM878_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  (__funcarg77 = FUNCCALL(SETUP_XfOrM878(_), find_param_cell (c , ((Scheme_Object * ) (void * ) (long ) ((((long ) (pos ) ) << 1 ) | 0x1 ) ) , 1 ) ), FUNCCALL_AGAIN(scheme_thread_cell_set (__funcarg77 , cells , o ) )) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_set_param (Scheme_Config * c , int pos , Scheme_Object * o ) {
  Scheme_Object * __funcarg78 = NULLED_OUT ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(o, 0)));
# define XfOrM879_COUNT (1)
# define SETUP_XfOrM879(x) SETUP(XfOrM879_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  (__funcarg78 = FUNCCALL(SETUP_XfOrM879(_), find_param_cell (c , ((Scheme_Object * ) (void * ) (long ) ((((long ) (pos ) ) << 1 ) | 0x1 ) ) , 1 ) ), FUNCCALL_AGAIN(scheme_thread_cell_set (__funcarg78 , scheme_current_thread -> cell_values , o ) )) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 5951 */
void scheme_flatten_config (Scheme_Config * orig_c ) {
  int pos , i ; 
  Scheme_Parameterization * paramz , * paramz2 ; 
  Scheme_Object * key ; 
  Scheme_Bucket * b , * b2 ; 
  Scheme_Config * c ; 
  PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(paramz2, 0), PUSH(orig_c, 1), PUSH(b2, 2), PUSH(b, 3), PUSH(c, 4), PUSH(key, 5), PUSH(paramz, 6)));
# define XfOrM880_COUNT (7)
# define SETUP_XfOrM880(x) SETUP(XfOrM880_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  paramz = NULLED_OUT ; 
  paramz2 = NULLED_OUT ; 
  key = NULLED_OUT ; 
  b = NULLED_OUT ; 
  b2 = NULLED_OUT ; 
  c = NULLED_OUT ; 
  if (orig_c -> next ) {
#   define XfOrM881_COUNT (0+XfOrM880_COUNT)
#   define SETUP_XfOrM881(x) SETUP_XfOrM880(x)
    paramz = (Scheme_Parameterization * ) FUNCCALL(SETUP_XfOrM881(_), GC_malloc_one_tagged (sizeof (Scheme_Parameterization ) + (max_configs - 1 ) * sizeof (Scheme_Object * ) ) ); 
    paramz -> type = scheme_rt_parameterization ; 
    c = orig_c ; 
    while (1 ) {
#     define XfOrM903_COUNT (0+XfOrM881_COUNT)
#     define SETUP_XfOrM903(x) SETUP_XfOrM881(x)
      if (c -> key ) {
#       define XfOrM916_COUNT (0+XfOrM903_COUNT)
#       define SETUP_XfOrM916(x) SETUP_XfOrM903(x)
        if ((((long ) (c -> key ) ) & 0x1 ) ) {
#         define XfOrM921_COUNT (0+XfOrM916_COUNT)
#         define SETUP_XfOrM921(x) SETUP_XfOrM916(x)
          pos = (((long ) (c -> key ) ) >> 1 ) ; 
          if (! paramz -> prims [pos ] ) {
#           define XfOrM922_COUNT (0+XfOrM921_COUNT)
#           define SETUP_XfOrM922(x) SETUP_XfOrM921(x)
            if (! (((Scheme_Type ) (((((long ) (c -> cell ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (c -> cell ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_cell_type ) ) ) ) {
              Scheme_Object * cell ; 
              BLOCK_SETUP((PUSH(cell, 0+XfOrM922_COUNT)));
#             define XfOrM923_COUNT (1+XfOrM922_COUNT)
#             define SETUP_XfOrM923(x) SETUP(XfOrM923_COUNT)
              cell = NULLED_OUT ; 
              cell = FUNCCALL(SETUP_XfOrM923(_), scheme_make_thread_cell (c -> cell , 1 ) ); 
              c -> cell = cell ; 
            }
            paramz -> prims [pos ] = c -> cell ; 
          }
        }
        else {
#         define XfOrM917_COUNT (0+XfOrM916_COUNT)
#         define SETUP_XfOrM917(x) SETUP_XfOrM916(x)
          if (! paramz -> extensions ) {
            Scheme_Bucket_Table * t ; 
            BLOCK_SETUP((PUSH(t, 0+XfOrM917_COUNT)));
#           define XfOrM920_COUNT (1+XfOrM917_COUNT)
#           define SETUP_XfOrM920(x) SETUP(XfOrM920_COUNT)
            t = NULLED_OUT ; 
            t = FUNCCALL(SETUP_XfOrM920(_), scheme_make_bucket_table (20 , SCHEME_hash_weak_ptr ) ); 
            paramz -> extensions = t ; 
          }
          b = FUNCCALL(SETUP_XfOrM917(_), scheme_bucket_from_table (paramz -> extensions , (const char * ) c -> key ) ); 
          if (! b -> val ) {
#           define XfOrM918_COUNT (0+XfOrM917_COUNT)
#           define SETUP_XfOrM918(x) SETUP_XfOrM917(x)
            if (! (((Scheme_Type ) (((((long ) (c -> cell ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (c -> cell ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_cell_type ) ) ) ) {
              Scheme_Object * cell ; 
              BLOCK_SETUP((PUSH(cell, 0+XfOrM918_COUNT)));
#             define XfOrM919_COUNT (1+XfOrM918_COUNT)
#             define SETUP_XfOrM919(x) SETUP(XfOrM919_COUNT)
              cell = NULLED_OUT ; 
              cell = FUNCCALL(SETUP_XfOrM919(_), scheme_make_thread_cell (c -> cell , 1 ) ); 
              c -> cell = cell ; 
            }
            b -> val = c -> cell ; 
          }
        }
        c = c -> next ; 
      }
      else {
#       define XfOrM904_COUNT (0+XfOrM903_COUNT)
#       define SETUP_XfOrM904(x) SETUP_XfOrM903(x)
        paramz2 = (Scheme_Parameterization * ) c -> cell ; 
        for (i = 0 ; i < max_configs ; i ++ ) {
          if (! paramz -> prims [i ] )
            paramz -> prims [i ] = paramz2 -> prims [i ] ; 
        }
        if (paramz2 -> extensions ) {
#         define XfOrM905_COUNT (0+XfOrM904_COUNT)
#         define SETUP_XfOrM905(x) SETUP_XfOrM904(x)
          if (! paramz -> extensions ) {
            paramz -> extensions = paramz2 -> extensions ; 
          }
          else {
#           define XfOrM906_COUNT (0+XfOrM905_COUNT)
#           define SETUP_XfOrM906(x) SETUP_XfOrM905(x)
            for (i = paramz2 -> extensions -> size ; i -- ; ) {
#             define XfOrM910_COUNT (0+XfOrM906_COUNT)
#             define SETUP_XfOrM910(x) SETUP_XfOrM906(x)
              b = paramz2 -> extensions -> buckets [i ] ; 
              if (b && b -> val && b -> key ) {
#               define XfOrM911_COUNT (0+XfOrM910_COUNT)
#               define SETUP_XfOrM911(x) SETUP_XfOrM910(x)
                key = (Scheme_Object * ) (((Scheme_Small_Object * ) (b -> key ) ) -> u . ptr_val ) ; 
                if (key ) {
#                 define XfOrM912_COUNT (0+XfOrM911_COUNT)
#                 define SETUP_XfOrM912(x) SETUP_XfOrM911(x)
                  b2 = FUNCCALL(SETUP_XfOrM912(_), scheme_bucket_from_table (paramz -> extensions , (const char * ) key ) ); 
                  if (! b2 -> val )
                    b2 -> val = b -> val ; 
                }
              }
            }
          }
        }
        break ; 
      }
    }
    orig_c -> cell = (Scheme_Object * ) paramz ; 
    orig_c -> key = ((void * ) 0 ) ; 
    orig_c -> next = ((void * ) 0 ) ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * parameterization_p (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  Scheme_Object * v = argv [0 ] ; 
  return (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_config_type ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * extend_parameterization (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * key , * a [2 ] , * param ; 
  Scheme_Config * c ; 
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSH(c, 0), PUSH(param, 1), PUSHARRAY(a, 2, 2), PUSH(key, 5), PUSH(argv, 6)));
# define XfOrM925_COUNT (7)
# define SETUP_XfOrM925(x) SETUP(XfOrM925_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  key = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  param = NULLED_OUT ; 
  c = NULLED_OUT ; 
  c = (Scheme_Config * ) argv [0 ] ; 
  if (argc < 2 ) {
#   define XfOrM947_COUNT (0+XfOrM925_COUNT)
#   define SETUP_XfOrM947(x) SETUP_XfOrM925(x)
    FUNCCALL(SETUP_XfOrM947(_), scheme_flatten_config (c ) ); 
  }
  else if (((Scheme_Type ) (((((long ) (c ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (c ) ) -> type ) ) == (Scheme_Type ) (scheme_config_type ) ) && (argc & 1 ) ) {
#   define XfOrM926_COUNT (0+XfOrM925_COUNT)
#   define SETUP_XfOrM926(x) SETUP_XfOrM925(x)
    for (i = 1 ; i < argc ; i += 2 ) {
#     define XfOrM937_COUNT (0+XfOrM926_COUNT)
#     define SETUP_XfOrM937(x) SETUP_XfOrM926(x)
      if (! ((((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_prim_type ) ) || ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_closed_prim_type ) ) ) && (((Scheme_Primitive_Proc * ) argv [i ] ) -> pp . flags & 16 ) ) ) {
#       define XfOrM946_COUNT (0+XfOrM937_COUNT)
#       define SETUP_XfOrM946(x) SETUP_XfOrM937(x)
        FUNCCALL(SETUP_XfOrM946(_), scheme_wrong_type ("parameterize" , "parameter" , i , argc , argv ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      a [0 ] = argv [i + 1 ] ; 
      a [1 ] = scheme_false ; 
      param = argv [i ] ; 
      while (1 ) {
#       define XfOrM942_COUNT (0+XfOrM937_COUNT)
#       define SETUP_XfOrM942(x) SETUP_XfOrM937(x)
        if (((Scheme_Type ) (((((long ) (param ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (param ) ) -> type ) ) == (Scheme_Type ) (scheme_prim_type ) ) ) {
          Scheme_Prim * proc ; 
#         define XfOrM945_COUNT (0+XfOrM942_COUNT)
#         define SETUP_XfOrM945(x) SETUP_XfOrM942(x)
          proc = NULLED_OUT ; 
          proc = (Scheme_Prim * ) ((Scheme_Primitive_Proc * ) param ) -> prim_val ; 
          key = FUNCCALL(SETUP_XfOrM945(_), proc (2 , a ) ); 
          break ; 
        }
        else {
#         define XfOrM943_COUNT (0+XfOrM942_COUNT)
#         define SETUP_XfOrM943(x) SETUP_XfOrM942(x)
          key = FUNCCALL(SETUP_XfOrM943(_), do_param (((Scheme_Closed_Primitive_Proc * ) param ) -> data , 2 , a ) ); 
          if (((((Scheme_Type ) (((((long ) (key ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (key ) ) -> type ) ) == (Scheme_Type ) (scheme_prim_type ) ) || ((Scheme_Type ) (((((long ) (key ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (key ) ) -> type ) ) == (Scheme_Type ) (scheme_closed_prim_type ) ) ) && (((Scheme_Primitive_Proc * ) key ) -> pp . flags & 16 ) ) ) {
            param = key ; 
            a [0 ] = a [1 ] ; 
          }
          else break ; 
        }
      }
      c = FUNCCALL(SETUP_XfOrM937(_), do_extend_config (c , key , a [1 ] ) ); 
    }
  }
  RET_VALUE_START ((Scheme_Object * ) c ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * parameter_p (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  Scheme_Object * v = argv [0 ] ; 
  return (((((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_prim_type ) ) || ((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_closed_prim_type ) ) ) && (((Scheme_Primitive_Proc * ) v ) -> pp . flags & 16 ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * do_param (void * _data , int argc , Scheme_Object * argv [] ) {
  Scheme_Object * guard , * * argv2 , * pos [2 ] ; 
  ParamData * data = (ParamData * ) _data ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSHARRAY(pos, 2, 0), PUSH(data, 3), PUSH(argv2, 4), PUSH(argv, 5)));
# define XfOrM949_COUNT (6)
# define SETUP_XfOrM949(x) SETUP(XfOrM949_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  guard = NULLED_OUT ; 
  argv2 = NULLED_OUT ; 
  pos[0] = NULLED_OUT ; 
  pos[1] = NULLED_OUT ; 
  if (argc && argv [0 ] ) {
#   define XfOrM953_COUNT (0+XfOrM949_COUNT)
#   define SETUP_XfOrM953(x) SETUP_XfOrM949(x)
    guard = data -> guard ; 
    if (guard ) {
      Scheme_Object * v ; 
      BLOCK_SETUP((PUSH(v, 0+XfOrM953_COUNT)));
#     define XfOrM955_COUNT (1+XfOrM953_COUNT)
#     define SETUP_XfOrM955(x) SETUP(XfOrM955_COUNT)
      v = NULLED_OUT ; 
      v = FUNCCALL(SETUP_XfOrM955(_), scheme_apply (guard , 1 , argv ) ); 
      if (argc == 2 ) {
        argv [1 ] = v ; 
        RET_VALUE_START (data -> key ) RET_VALUE_END ; 
      }
      argv2 = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM955(_), GC_malloc (sizeof (Scheme_Object * ) * (argc ) ) )) ; 
      (memcpy (argv2 , argv , argc * sizeof (Scheme_Object * ) ) ) ; 
      argv2 [0 ] = v ; 
    }
    else if (argc == 2 ) {
      argv [1 ] = argv [0 ] ; 
      RET_VALUE_START (data -> key ) RET_VALUE_END ; 
    }
    else argv2 = argv ; 
  }
  else argv2 = argv ; 
  if (data -> is_derived ) {
#   define XfOrM950_COUNT (0+XfOrM949_COUNT)
#   define SETUP_XfOrM950(x) SETUP_XfOrM949(x)
    if (! argc ) {
      Scheme_Object * v ; 
      BLOCK_SETUP((PUSH(v, 0+XfOrM950_COUNT)));
#     define XfOrM952_COUNT (1+XfOrM950_COUNT)
#     define SETUP_XfOrM952(x) SETUP(XfOrM952_COUNT)
      v = NULLED_OUT ; 
      v = FUNCCALL(SETUP_XfOrM952(_), scheme_do_eval (data -> key , argc , argv2 , 1 ) ); 
      pos [0 ] = v ; 
      RET_VALUE_START (FUNCCALL(SETUP_XfOrM952(_), scheme_tail_apply (data -> extract_guard , 1 , pos ) )) RET_VALUE_END ; 
    }
    else {
#     define XfOrM951_COUNT (0+XfOrM950_COUNT)
#     define SETUP_XfOrM951(x) SETUP_XfOrM950(x)
      RET_VALUE_START (FUNCCALL(SETUP_XfOrM951(_), scheme_tail_apply (data -> key , argc , argv2 ) )) RET_VALUE_END ; 
    }
  }
  pos [0 ] = data -> key ; 
  pos [1 ] = data -> defcell ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM949(_), scheme_param_config ("parameter-procedure" , (Scheme_Object * ) (void * ) pos , argc , argv2 , - 2 , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_parameter (int argc , Scheme_Object * * argv ) {
  Scheme_Object * p , * cell ; 
  ParamData * data ; 
  void * k ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(cell, 0), PUSH(data, 1), PUSH(p, 2), PUSH(argv, 3), PUSH(k, 4)));
# define XfOrM957_COUNT (5)
# define SETUP_XfOrM957(x) SETUP(XfOrM957_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  p = NULLED_OUT ; 
  cell = NULLED_OUT ; 
  data = NULLED_OUT ; 
  k = NULLED_OUT ; 
  k = FUNCCALL(SETUP_XfOrM957(_), scheme_make_pair (scheme_true , scheme_false ) ); 
  if (argc > 1 )
    FUNCCALL(SETUP_XfOrM957(_), scheme_check_proc_arity ("make-parameter" , 1 , 1 , argc , argv ) ); 
  data = ((ParamData * ) FUNCCALL(SETUP_XfOrM957(_), GC_malloc_one_small_tagged ((((sizeof (ParamData ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  data -> type = scheme_rt_param_data ; 
  data -> key = (Scheme_Object * ) k ; 
  cell = FUNCCALL(SETUP_XfOrM957(_), scheme_make_thread_cell (argv [0 ] , 1 ) ); 
  data -> defcell = cell ; 
  data -> guard = ((argc > 1 ) ? argv [1 ] : ((void * ) 0 ) ) ; 
  p = FUNCCALL(SETUP_XfOrM957(_), scheme_make_closed_prim_w_arity (do_param , (void * ) data , "parameter-procedure" , 0 , 1 ) ); 
  ((Scheme_Primitive_Proc * ) p ) -> pp . flags |= 16 ; 
  RET_VALUE_START (p ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_derived_parameter (int argc , Scheme_Object * * argv ) {
  Scheme_Object * p ; 
  ParamData * data ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(data, 0), PUSH(p, 1), PUSH(argv, 2)));
# define XfOrM958_COUNT (3)
# define SETUP_XfOrM958(x) SETUP(XfOrM958_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  p = NULLED_OUT ; 
  data = NULLED_OUT ; 
  if (! ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_prim_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_closed_prim_type ) ) ) && (((Scheme_Primitive_Proc * ) argv [0 ] ) -> pp . flags & 16 ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("make-derived-parameter" , "parameter" , 0 , argc , argv ) ); 
  FUNCCALL(SETUP_XfOrM958(_), scheme_check_proc_arity ("make-derived-parameter" , 1 , 1 , argc , argv ) ); 
  FUNCCALL_AGAIN(scheme_check_proc_arity ("make-derived-parameter" , 1 , 2 , argc , argv ) ); 
  data = ((ParamData * ) FUNCCALL(SETUP_XfOrM958(_), GC_malloc_one_small_tagged ((((sizeof (ParamData ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  data -> type = scheme_rt_param_data ; 
  data -> is_derived = 1 ; 
  data -> key = argv [0 ] ; 
  data -> guard = argv [1 ] ; 
  data -> extract_guard = argv [2 ] ; 
  p = FUNCCALL(SETUP_XfOrM958(_), scheme_make_closed_prim_w_arity (do_param , (void * ) data , "parameter-procedure" , 0 , 1 ) ); 
  ((Scheme_Primitive_Proc * ) p ) -> pp . flags |= 16 ; 
  RET_VALUE_START (p ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * parameter_procedure_eq (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  Scheme_Object * a , * b ; 
  a = argv [0 ] ; 
  b = argv [1 ] ; 
  if (! ((((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_prim_type ) ) || ((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_closed_prim_type ) ) ) && (((Scheme_Primitive_Proc * ) a ) -> pp . flags & 16 ) ) )
    scheme_wrong_type ("parameter-procedure=?" , "parameter-procedure" , 0 , argc , argv ) ; 
  if (! ((((Scheme_Type ) (((((long ) (b ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (b ) ) -> type ) ) == (Scheme_Type ) (scheme_prim_type ) ) || ((Scheme_Type ) (((((long ) (b ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (b ) ) -> type ) ) == (Scheme_Type ) (scheme_closed_prim_type ) ) ) && (((Scheme_Primitive_Proc * ) b ) -> pp . flags & 16 ) ) )
    scheme_wrong_type ("parameter-procedure=?" , "parameter-procedure" , 1 , argc , argv ) ; 
  return (((a ) == (b ) ) ? scheme_true : scheme_false ) ; 
}
int scheme_new_param (void ) {
  /* No conversion */
  return max_configs ++ ; 
}
static void init_param (Scheme_Thread_Cell_Table * cells , Scheme_Parameterization * params , int pos , Scheme_Object * v ) {
  Scheme_Object * cell ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(cell, 0), PUSH(params, 1)));
# define XfOrM961_COUNT (2)
# define SETUP_XfOrM961(x) SETUP(XfOrM961_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  cell = NULLED_OUT ; 
  cell = FUNCCALL(SETUP_XfOrM961(_), scheme_make_thread_cell (v , 1 ) ); 
  params -> prims [pos ] = cell ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_set_root_param (int p , Scheme_Object * v ) {
  /* No conversion */
  Scheme_Parameterization * paramz ; 
  paramz = (Scheme_Parameterization * ) scheme_current_thread -> init_config -> cell ; 
  ((Thread_Cell * ) (paramz -> prims [p ] ) ) -> def_val = v ; 
}
/* this far 6242 */
static void make_initial_config (Scheme_Thread * p ) {
  Scheme_Thread_Cell_Table * cells ; 
  Scheme_Parameterization * paramz ; 
  Scheme_Config * config ; 
  Scheme_Object * __funcarg80 = NULLED_OUT ; 
  char * __funcarg79 = NULLED_OUT ; 
  PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(cells, 0), PUSH(config, 1), PUSH(paramz, 2), PUSH(p, 3)));
# define XfOrM963_COUNT (4)
# define SETUP_XfOrM963(x) SETUP(XfOrM963_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  cells = NULLED_OUT ; 
  paramz = NULLED_OUT ; 
  config = NULLED_OUT ; 
  cells = FUNCCALL(SETUP_XfOrM963(_), scheme_make_bucket_table (5 , SCHEME_hash_weak_ptr ) ); 
  p -> cell_values = cells ; 
  paramz = (Scheme_Parameterization * ) FUNCCALL(SETUP_XfOrM963(_), GC_malloc_one_tagged (sizeof (Scheme_Parameterization ) + (max_configs - 1 ) * sizeof (Scheme_Object * ) ) ); 
  paramz -> type = scheme_rt_parameterization ; 
  config = ((Scheme_Config * ) FUNCCALL(SETUP_XfOrM963(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Config ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  config -> so . type = scheme_config_type ; 
  config -> cell = (Scheme_Object * ) paramz ; 
  p -> init_config = config ; 
  (__funcarg80 = FUNCCALL(SETUP_XfOrM963(_), scheme_make_default_readtable () ), FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_READTABLE , __funcarg80 ) )) ; 
  FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_CAN_READ_GRAPH , scheme_true ) ); 
  FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_CAN_READ_COMPILED , scheme_false ) ); 
  FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_CAN_READ_BOX , scheme_true ) ); 
  FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_CAN_READ_PIPE_QUOTE , scheme_true ) ); 
  FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_CAN_READ_DOT , scheme_true ) ); 
  FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_CAN_READ_INFIX_DOT , scheme_true ) ); 
  FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_CAN_READ_QUASI , scheme_true ) ); 
  FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_READ_DECIMAL_INEXACT , scheme_true ) ); 
  FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_CAN_READ_READER , scheme_false ) ); 
  FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_LOAD_DELAY_ENABLED , scheme_false ) ); 
  FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_DELAY_LOAD_INFO , scheme_false ) ); 
  FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_PRINT_GRAPH , scheme_false ) ); 
  FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_PRINT_STRUCT , scheme_true ) ); 
  FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_PRINT_BOX , scheme_true ) ); 
  FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_PRINT_VEC_SHORTHAND , scheme_true ) ); 
  FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_PRINT_HASH_TABLE , scheme_false ) ); 
  FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_PRINT_UNREADABLE , scheme_true ) ); 
  FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_HONU_MODE , scheme_false ) ); 
  FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_COMPILE_MODULE_CONSTS , scheme_true ) ); 
  FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_USE_JIT , scheme_startup_use_jit ? scheme_true : scheme_false ) ); 
  {
    Scheme_Object * s ; 
    BLOCK_SETUP((PUSH(s, 0+XfOrM963_COUNT)));
#   define XfOrM977_COUNT (1+XfOrM963_COUNT)
#   define SETUP_XfOrM977(x) SETUP(XfOrM977_COUNT)
    s = NULLED_OUT ; 
    s = FUNCCALL(SETUP_XfOrM977(_), scheme_make_immutable_sized_utf8_string ("" , 0 ) ); 
    FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_LOCALE , s ) ); 
  }
  FUNCCALL(SETUP_XfOrM963(_), init_param (cells , paramz , MZCONFIG_CASE_SENS , (scheme_case_sensitive ? scheme_true : scheme_false ) ) ); 
  FUNCCALL(SETUP_XfOrM963(_), init_param (cells , paramz , MZCONFIG_SQUARE_BRACKETS_ARE_PARENS , (scheme_square_brackets_are_parens ? scheme_true : scheme_false ) ) ); 
  FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_CURLY_BRACES_ARE_PARENS , (scheme_curly_braces_are_parens ? scheme_true : scheme_false ) ) ); 
  FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_ERROR_PRINT_WIDTH , ((Scheme_Object * ) (void * ) (long ) ((((long ) (256 ) ) << 1 ) | 0x1 ) ) ) ); 
  FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_ERROR_PRINT_CONTEXT_LENGTH , ((Scheme_Object * ) (void * ) (long ) ((((long ) (16 ) ) << 1 ) | 0x1 ) ) ) ); 
  FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_ERROR_PRINT_SRCLOC , scheme_true ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & main_custodian , sizeof (main_custodian ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & last_custodian , sizeof (last_custodian ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & limited_custodians , sizeof (limited_custodians ) ) ); 
  main_custodian = FUNCCALL_AGAIN(scheme_make_custodian (((void * ) 0 ) ) ); 
  last_custodian = main_custodian ; 
  FUNCCALL(SETUP_XfOrM963(_), init_param (cells , paramz , MZCONFIG_CUSTODIAN , (Scheme_Object * ) main_custodian ) ); 
  FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_ALLOW_SET_UNDEFINED , (scheme_allow_set_undefined ? scheme_true : scheme_false ) ) ); 
  FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_COLLECTION_PATHS , scheme_null ) ); 
  {
    Scheme_Object * s ; 
    BLOCK_SETUP((PUSH(s, 0+XfOrM963_COUNT)));
#   define XfOrM976_COUNT (1+XfOrM963_COUNT)
#   define SETUP_XfOrM976(x) SETUP(XfOrM976_COUNT)
    s = NULLED_OUT ; 
    s = (__funcarg79 = FUNCCALL(SETUP_XfOrM976(_), scheme_os_getcwd (((void * ) 0 ) , 0 , ((void * ) 0 ) , 1 ) ), FUNCCALL_AGAIN(scheme_make_path (__funcarg79 ) )) ; 
    s = FUNCCALL_AGAIN(scheme_path_to_directory_path (s ) ); 
    FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_CURRENT_DIRECTORY , s ) ); 
    FUNCCALL_AGAIN(scheme_set_original_dir (s ) ); 
  }
  {
    Scheme_Object * rs ; 
    BLOCK_SETUP((PUSH(rs, 0+XfOrM963_COUNT)));
#   define XfOrM975_COUNT (1+XfOrM963_COUNT)
#   define SETUP_XfOrM975(x) SETUP(XfOrM975_COUNT)
    rs = NULLED_OUT ; 
    rs = FUNCCALL(SETUP_XfOrM975(_), scheme_make_random_state (scheme_get_milliseconds () ) ); 
    FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_RANDOM_STATE , rs ) ); 
    rs = FUNCCALL_AGAIN(scheme_make_random_state (scheme_get_milliseconds () ) ); 
    FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_SCHEDULER_RANDOM_STATE , rs ) ); 
  }
  {
    Scheme_Object * eh ; 
    BLOCK_SETUP((PUSH(eh, 0+XfOrM963_COUNT)));
#   define XfOrM974_COUNT (1+XfOrM963_COUNT)
#   define SETUP_XfOrM974(x) SETUP(XfOrM974_COUNT)
    eh = NULLED_OUT ; 
    eh = FUNCCALL(SETUP_XfOrM974(_), scheme_make_prim_w_everything (scheme_default_eval_handler , 0 , "default-eval-handler" , 1 , 1 , 0 , 0 , - 1 ) ); 
    FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_EVAL_HANDLER , eh ) ); 
  }
  {
    Scheme_Object * eh ; 
    BLOCK_SETUP((PUSH(eh, 0+XfOrM963_COUNT)));
#   define XfOrM973_COUNT (1+XfOrM963_COUNT)
#   define SETUP_XfOrM973(x) SETUP(XfOrM973_COUNT)
    eh = NULLED_OUT ; 
    eh = FUNCCALL(SETUP_XfOrM973(_), scheme_make_prim_w_arity (scheme_default_compile_handler , "default-compile-handler" , 2 , 2 ) ); 
    FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_COMPILE_HANDLER , eh ) ); 
  }
  {
    Scheme_Object * ph , * prh ; 
    BLOCK_SETUP((PUSH(prh, 0+XfOrM963_COUNT), PUSH(ph, 1+XfOrM963_COUNT)));
#   define XfOrM972_COUNT (2+XfOrM963_COUNT)
#   define SETUP_XfOrM972(x) SETUP(XfOrM972_COUNT)
    ph = NULLED_OUT ; 
    prh = NULLED_OUT ; 
    ph = FUNCCALL(SETUP_XfOrM972(_), scheme_make_prim_w_arity (scheme_default_print_handler , "default-print-handler" , 1 , 1 ) ); 
    FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_PRINT_HANDLER , ph ) ); 
    prh = FUNCCALL_AGAIN(scheme_make_prim_w_arity (scheme_default_prompt_read_handler , "default-prompt-read-handler" , 0 , 0 ) ); 
    FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_PROMPT_READ_HANDLER , prh ) ); 
  }
  FUNCCALL(SETUP_XfOrM963(_), init_param (cells , paramz , MZCONFIG_PORT_COUNT_LINES , scheme_false ) ); 
  {
    Scheme_Object * lh ; 
    BLOCK_SETUP((PUSH(lh, 0+XfOrM963_COUNT)));
#   define XfOrM971_COUNT (1+XfOrM963_COUNT)
#   define SETUP_XfOrM971(x) SETUP(XfOrM971_COUNT)
    lh = NULLED_OUT ; 
    lh = FUNCCALL(SETUP_XfOrM971(_), scheme_make_prim_w_everything (scheme_default_load_extension , 0 , "default-load-extension-handler" , 2 , 2 , 0 , 0 , - 1 ) ); 
    FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_LOAD_EXTENSION_HANDLER , lh ) ); 
  }
  {
    Scheme_Object * ins ; 
    BLOCK_SETUP((PUSH(ins, 0+XfOrM963_COUNT)));
#   define XfOrM970_COUNT (1+XfOrM963_COUNT)
#   define SETUP_XfOrM970(x) SETUP(XfOrM970_COUNT)
    ins = NULLED_OUT ; 
    ins = FUNCCALL(SETUP_XfOrM970(_), scheme_make_initial_inspectors () ); 
    FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_INSPECTOR , ins ) ); 
    FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_CODE_INSPECTOR , ins ) ); 
  }
  {
    Scheme_Object * zlv ; 
    BLOCK_SETUP((PUSH(zlv, 0+XfOrM963_COUNT)));
#   define XfOrM969_COUNT (1+XfOrM963_COUNT)
#   define SETUP_XfOrM969(x) SETUP(XfOrM969_COUNT)
    zlv = NULLED_OUT ; 
    zlv = FUNCCALL(SETUP_XfOrM969(_), scheme_make_vector (0 , ((void * ) 0 ) ) ); 
    FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_CMDLINE_ARGS , zlv ) ); 
  }
  {
    Scheme_Security_Guard * sg ; 
    BLOCK_SETUP((PUSH(sg, 0+XfOrM963_COUNT)));
#   define XfOrM968_COUNT (1+XfOrM963_COUNT)
#   define SETUP_XfOrM968(x) SETUP(XfOrM968_COUNT)
    sg = NULLED_OUT ; 
    sg = ((Scheme_Security_Guard * ) FUNCCALL(SETUP_XfOrM968(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Security_Guard ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    sg -> so . type = scheme_security_guard_type ; 
    FUNCCALL(SETUP_XfOrM968(_), init_param (cells , paramz , MZCONFIG_SECURITY_GUARD , (Scheme_Object * ) sg ) ); 
  }
  {
    Scheme_Thread_Set * t_set ; 
    BLOCK_SETUP((PUSH(t_set, 0+XfOrM963_COUNT)));
#   define XfOrM967_COUNT (1+XfOrM963_COUNT)
#   define SETUP_XfOrM967(x) SETUP(XfOrM967_COUNT)
    t_set = NULLED_OUT ; 
    t_set = FUNCCALL(SETUP_XfOrM967(_), create_thread_set (((void * ) 0 ) ) ); 
    FUNCCALL_AGAIN(init_param (cells , paramz , MZCONFIG_THREAD_SET , (Scheme_Object * ) t_set ) ); 
  }
  FUNCCALL(SETUP_XfOrM963(_), init_param (cells , paramz , MZCONFIG_THREAD_INIT_STACK_SIZE , ((Scheme_Object * ) (void * ) (long ) ((((long ) (1000 ) ) << 1 ) | 0x1 ) ) ) ); 
  {
    int i ; 
#   define XfOrM964_COUNT (0+XfOrM963_COUNT)
#   define SETUP_XfOrM964(x) SETUP_XfOrM963(x)
    for (i = 0 ; i < max_configs ; i ++ ) {
#     define XfOrM966_COUNT (0+XfOrM964_COUNT)
#     define SETUP_XfOrM966(x) SETUP_XfOrM964(x)
      if (! paramz -> prims [i ] )
        FUNCCALL(SETUP_XfOrM966(_), init_param (cells , paramz , i , scheme_false ) ); 
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_register_parameter (Scheme_Prim * function , char * name , int which ) {
  Scheme_Object * o ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(function, 1), PUSH(name, 2)));
# define XfOrM978_COUNT (3)
# define SETUP_XfOrM978(x) SETUP(XfOrM978_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  o = NULLED_OUT ; 
  if (! config_map ) {
#   define XfOrM979_COUNT (0+XfOrM978_COUNT)
#   define SETUP_XfOrM979(x) SETUP_XfOrM978(x)
    FUNCCALL(SETUP_XfOrM979(_), scheme_register_static ((void * ) & config_map , sizeof (config_map ) ) ); 
    config_map = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM979(_), GC_malloc (sizeof (Scheme_Object * ) * (max_configs ) ) )) ; 
  }
  if (config_map [which ] )
    RET_VALUE_START (config_map [which ] ) RET_VALUE_END ; 
  o = FUNCCALL(SETUP_XfOrM978(_), scheme_make_prim_w_arity (function , name , 0 , 1 ) ); 
  ((Scheme_Primitive_Proc * ) o ) -> pp . flags |= 16 ; 
  config_map [which ] = o ; 
  RET_VALUE_START (o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
typedef Scheme_Object * (* PCheck_Proc ) (int , Scheme_Object * * , Scheme_Config * ) ; 
Scheme_Object * scheme_param_config (char * name , Scheme_Object * pos , int argc , Scheme_Object * * argv , int arity , Scheme_Object * (* check ) (int , Scheme_Object * * ) , char * expected , int isboolorfilter ) {
  Scheme_Config * config ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(9);
  BLOCK_SETUP_TOP((PUSH(pos, 0), PUSH(expected, 1), PUSH(config, 2), PUSH(argv, 3), PUSH(name, 4)));
# define XfOrM980_COUNT (5)
# define SETUP_XfOrM980(x) SETUP(XfOrM980_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  config = NULLED_OUT ; 
  config = FUNCCALL(SETUP_XfOrM980(_), scheme_current_config () ); 
  if (argc == 0 ) {
#   define XfOrM988_COUNT (0+XfOrM980_COUNT)
#   define SETUP_XfOrM988(x) SETUP_XfOrM980(x)
    if (arity == - 2 ) {
      Scheme_Object * cell ; 
      BLOCK_SETUP((PUSH(cell, 0+XfOrM988_COUNT)));
#     define XfOrM991_COUNT (1+XfOrM988_COUNT)
#     define SETUP_XfOrM991(x) SETUP(XfOrM991_COUNT)
      cell = NULLED_OUT ; 
      cell = FUNCCALL(SETUP_XfOrM991(_), find_param_cell (config , ((Scheme_Object * * ) pos ) [0 ] , 0 ) ); 
      if (! cell )
        cell = ((Scheme_Object * * ) pos ) [1 ] ; 
      if ((((Scheme_Type ) (((((long ) (cell ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (cell ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_cell_type ) ) ) )
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_thread_cell_get (cell , scheme_current_thread -> cell_values ) )) RET_VALUE_EMPTY_END ; 
      else RET_VALUE_START (cell ) RET_VALUE_END ; 
    }
    else {
      Scheme_Object * s ; 
      BLOCK_SETUP((PUSH(s, 0+XfOrM988_COUNT)));
#     define XfOrM989_COUNT (1+XfOrM988_COUNT)
#     define SETUP_XfOrM989(x) SETUP(XfOrM989_COUNT)
      s = NULLED_OUT ; 
      s = FUNCCALL(SETUP_XfOrM989(_), scheme_get_param (config , (((long ) (pos ) ) >> 1 ) ) ); 
      if (arity == - 3 ) {
        Scheme_Object * a [1 ] ; 
        PCheck_Proc checkp = (PCheck_Proc ) check ; 
        BLOCK_SETUP((PUSHARRAY(a, 1, 0+XfOrM989_COUNT)));
#       define XfOrM990_COUNT (3+XfOrM989_COUNT)
#       define SETUP_XfOrM990(x) SETUP(XfOrM990_COUNT)
        a[0] = NULLED_OUT ; 
        a [0 ] = s ; 
        s = FUNCCALL(SETUP_XfOrM990(_), checkp (1 , a , config ) ); 
      }
      RET_VALUE_START (s ) RET_VALUE_END ; 
    }
  }
  else {
    Scheme_Object * naya = argv [0 ] ; 
    BLOCK_SETUP((PUSH(naya, 0+XfOrM980_COUNT)));
#   define XfOrM981_COUNT (1+XfOrM980_COUNT)
#   define SETUP_XfOrM981(x) SETUP(XfOrM981_COUNT)
    if (arity != - 2 ) {
#     define XfOrM983_COUNT (0+XfOrM981_COUNT)
#     define SETUP_XfOrM983(x) SETUP_XfOrM981(x)
      if (arity < 0 ) {
#       define XfOrM985_COUNT (0+XfOrM983_COUNT)
#       define SETUP_XfOrM985(x) SETUP_XfOrM983(x)
        if (check ) {
          PCheck_Proc checkp = (PCheck_Proc ) check ; 
          Scheme_Object * r ; 
          BLOCK_SETUP((PUSH(r, 0+XfOrM985_COUNT)));
#         define XfOrM986_COUNT (1+XfOrM985_COUNT)
#         define SETUP_XfOrM986(x) SETUP(XfOrM986_COUNT)
          r = NULLED_OUT ; 
          r = FUNCCALL(SETUP_XfOrM986(_), checkp (1 , argv , config ) ); 
          if (! isboolorfilter && (((r ) ) == (scheme_false ) ) )
            r = ((void * ) 0 ) ; 
          if (! r ) {
#           define XfOrM987_COUNT (0+XfOrM986_COUNT)
#           define SETUP_XfOrM987(x) SETUP_XfOrM986(x)
            FUNCCALL_EMPTY(scheme_wrong_type (name , expected , 0 , 1 , argv ) ); 
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          }
          if (isboolorfilter )
            naya = r ; 
        }
      }
      else FUNCCALL(SETUP_XfOrM983(_), scheme_check_proc_arity (name , arity , 0 , argc , argv ) ); 
      if (isboolorfilter && ! check )
        naya = (((! (((naya ) ) == (scheme_false ) ) ) ) ? scheme_true : scheme_false ) ; 
      if (argc == 2 ) {
        argv [1 ] = naya ; 
        RET_VALUE_START (pos ) RET_VALUE_END ; 
      }
      else FUNCCALL(SETUP_XfOrM983(_), scheme_set_param (config , (((long ) (pos ) ) >> 1 ) , naya ) ); 
    }
    else {
      Scheme_Object * cell ; 
      BLOCK_SETUP((PUSH(cell, 0+XfOrM981_COUNT)));
#     define XfOrM982_COUNT (1+XfOrM981_COUNT)
#     define SETUP_XfOrM982(x) SETUP(XfOrM982_COUNT)
      cell = NULLED_OUT ; 
      cell = FUNCCALL(SETUP_XfOrM982(_), find_param_cell (config , ((Scheme_Object * * ) pos ) [0 ] , 1 ) ); 
      if (! cell )
        cell = ((Scheme_Object * * ) pos ) [1 ] ; 
      FUNCCALL_EMPTY(scheme_thread_cell_set (cell , scheme_current_thread -> cell_values , naya ) ); 
    }
    RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * exact_positive_integer_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * n = argv [0 ] ; 
  if ((((long ) (n ) ) & 0x1 ) && ((((long ) (n ) ) >> 1 ) > 0 ) )
    return scheme_true ; 
  if (((Scheme_Type ) (((((long ) (n ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) && ((& ((Scheme_Bignum * ) n ) -> iso ) -> so . keyex & 0x1 ) )
    return scheme_true ; 
  return scheme_false ; 
}
static Scheme_Object * current_thread_initial_stack_size (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("current-thread-initial-stack-size" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_THREAD_INIT_STACK_SIZE ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , exact_positive_integer_p , "exact positive integer" , 0 ) ; 
}
Scheme_Env * scheme_get_env (Scheme_Config * c ) {
  Scheme_Object * o ; 
  if (! c )
    c = scheme_current_config () ; 
  o = scheme_get_param (c , MZCONFIG_ENV ) ; 
  return (Scheme_Env * ) o ; 
}
void scheme_add_namespace_option (Scheme_Object * key , void (* f ) (Scheme_Env * ) ) {
  Scheme_NSO * old = namespace_options ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(key, 0), PUSH(old, 1)));
# define XfOrM994_COUNT (2)
# define SETUP_XfOrM994(x) SETUP(XfOrM994_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  namespace_options = ((Scheme_NSO * ) FUNCCALL(SETUP_XfOrM994(_), GC_malloc_array_tagged (sizeof (Scheme_NSO ) * ((num_nsos + 1 ) ) ) )) ; 
  (memcpy (namespace_options , old , num_nsos * sizeof (Scheme_NSO ) ) ) ; 
  namespace_options [num_nsos ] . type = scheme_rt_namespace_option ; 
  namespace_options [num_nsos ] . key = key ; 
  namespace_options [num_nsos ] . f = f ; 
  num_nsos ++ ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_namespace (int argc , Scheme_Object * argv [] ) {
  int empty = 0 ; 
  Scheme_Env * env ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(env, 0)));
# define XfOrM995_COUNT (1)
# define SETUP_XfOrM995(x) SETUP(XfOrM995_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  env = NULLED_OUT ; 
  if (argc ) {
#   define XfOrM997_COUNT (0+XfOrM995_COUNT)
#   define SETUP_XfOrM997(x) SETUP_XfOrM995(x)
    if (((argv [0 ] ) == (empty_symbol ) ) )
      empty = 1 ; 
    else if (((argv [0 ] ) == (initial_symbol ) ) )
      empty = 0 ; 
    else FUNCCALL_EMPTY(scheme_wrong_type ("make-namespace" , "'empty or 'initial" , 0 , argc , argv ) ); 
  }
  env = FUNCCALL(SETUP_XfOrM995(_), scheme_make_empty_env () ); 
  if (! empty ) {
#   define XfOrM996_COUNT (0+XfOrM995_COUNT)
#   define SETUP_XfOrM996(x) SETUP_XfOrM995(x)
    FUNCCALL(SETUP_XfOrM996(_), scheme_install_initial_module_set (env ) ); 
  }
  RET_VALUE_START ((Scheme_Object * ) env ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * namespace_p (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_namespace_type ) ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * current_namespace (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("current-namespace" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_ENV ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , namespace_p , "namespace" , 0 ) ; 
}
static Scheme_Object * make_security_guard (int argc , Scheme_Object * argv [] ) {
  Scheme_Security_Guard * sg ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sg, 0), PUSH(argv, 1)));
# define XfOrM1000_COUNT (2)
# define SETUP_XfOrM1000(x) SETUP(XfOrM1000_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sg = NULLED_OUT ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_security_guard_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("make-security-guard" , "security-guard" , 0 , argc , argv ) ); 
  FUNCCALL(SETUP_XfOrM1000(_), scheme_check_proc_arity ("make-security-guard" , 3 , 1 , argc , argv ) ); 
  FUNCCALL_AGAIN(scheme_check_proc_arity ("make-security-guard" , 4 , 2 , argc , argv ) ); 
  if (argc > 3 )
    FUNCCALL(SETUP_XfOrM1000(_), scheme_check_proc_arity2 ("make-security-guard" , 3 , 3 , argc , argv , 1 ) ); 
  sg = ((Scheme_Security_Guard * ) FUNCCALL(SETUP_XfOrM1000(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Security_Guard ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  sg -> so . type = scheme_security_guard_type ; 
  sg -> parent = (Scheme_Security_Guard * ) argv [0 ] ; 
  sg -> file_proc = argv [1 ] ; 
  sg -> network_proc = argv [2 ] ; 
  if ((argc > 3 ) && (! (((argv [3 ] ) ) == (scheme_false ) ) ) )
    sg -> link_proc = argv [3 ] ; 
  RET_VALUE_START ((Scheme_Object * ) sg ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * security_guard_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_security_guard_type ) ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * current_security_guard (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("current-security-guard" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_SECURITY_GUARD ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , security_guard_p , "security-guard" , 0 ) ; 
}
void scheme_security_check_file (const char * who , const char * filename , int guards ) {
  Scheme_Security_Guard * sg ; 
  Scheme_Config * __funcarg81 = NULLED_OUT ; 
  PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(filename, 0), PUSH(sg, 1), PUSH(who, 2)));
# define XfOrM1003_COUNT (3)
# define SETUP_XfOrM1003(x) SETUP(XfOrM1003_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  sg = NULLED_OUT ; 
  sg = (Scheme_Security_Guard * ) (__funcarg81 = FUNCCALL(SETUP_XfOrM1003(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg81 , MZCONFIG_SECURITY_GUARD ) )) ; 
  if (sg -> file_proc ) {
    Scheme_Object * l = scheme_null , * a [3 ] ; 
    BLOCK_SETUP((PUSHARRAY(a, 3, 0+XfOrM1003_COUNT), PUSH(l, 3+XfOrM1003_COUNT)));
#   define XfOrM1004_COUNT (4+XfOrM1003_COUNT)
#   define SETUP_XfOrM1004(x) SETUP(XfOrM1004_COUNT)
    a[0] = NULLED_OUT ; 
    a[1] = NULLED_OUT ; 
    a[2] = NULLED_OUT ; 
    if (! read_symbol ) {
#     define XfOrM1007_COUNT (0+XfOrM1004_COUNT)
#     define SETUP_XfOrM1007(x) SETUP_XfOrM1004(x)
      FUNCCALL(SETUP_XfOrM1007(_), scheme_register_static ((void * ) & read_symbol , sizeof (read_symbol ) ) ); 
      FUNCCALL(SETUP_XfOrM1007(_), scheme_register_static ((void * ) & write_symbol , sizeof (write_symbol ) ) ); 
      FUNCCALL_AGAIN(scheme_register_static ((void * ) & execute_symbol , sizeof (execute_symbol ) ) ); 
      FUNCCALL_AGAIN(scheme_register_static ((void * ) & delete_symbol , sizeof (delete_symbol ) ) ); 
      FUNCCALL_AGAIN(scheme_register_static ((void * ) & exists_symbol , sizeof (exists_symbol ) ) ); 
      read_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("read" ) ); 
      write_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("write" ) ); 
      execute_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("execute" ) ); 
      delete_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("delete" ) ); 
      exists_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("exists" ) ); 
    }
    if (guards & 0x10 )
      l = FUNCCALL(SETUP_XfOrM1004(_), scheme_make_immutable_pair (exists_symbol , l ) ); 
    if (guards & 0x8 )
      l = FUNCCALL(SETUP_XfOrM1004(_), scheme_make_immutable_pair (delete_symbol , l ) ); 
    if (guards & 0x4 )
      l = FUNCCALL(SETUP_XfOrM1004(_), scheme_make_immutable_pair (execute_symbol , l ) ); 
    if (guards & 0x2 )
      l = FUNCCALL(SETUP_XfOrM1004(_), scheme_make_immutable_pair (write_symbol , l ) ); 
    if (guards & 0x1 )
      l = FUNCCALL(SETUP_XfOrM1004(_), scheme_make_immutable_pair (read_symbol , l ) ); 
    a [0 ] = FUNCCALL(SETUP_XfOrM1004(_), scheme_intern_symbol (who ) ); 
    a [1 ] = (filename ? FUNCCALL(SETUP_XfOrM1004(_), scheme_make_sized_path ((char * ) filename , - 1 , 1 ) ): scheme_false ) ; 
    a [2 ] = l ; 
    while (sg -> parent ) {
#     define XfOrM1006_COUNT (0+XfOrM1004_COUNT)
#     define SETUP_XfOrM1006(x) SETUP_XfOrM1004(x)
      FUNCCALL(SETUP_XfOrM1006(_), scheme_apply (sg -> file_proc , 3 , a ) ); 
      sg = sg -> parent ; 
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_security_check_file_link (const char * who , const char * filename , const char * content ) {
  Scheme_Security_Guard * sg ; 
  Scheme_Config * __funcarg82 = NULLED_OUT ; 
  PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(sg, 0), PUSH(filename, 1), PUSH(content, 2), PUSH(who, 3)));
# define XfOrM1008_COUNT (4)
# define SETUP_XfOrM1008(x) SETUP(XfOrM1008_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  sg = NULLED_OUT ; 
  sg = (Scheme_Security_Guard * ) (__funcarg82 = FUNCCALL(SETUP_XfOrM1008(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg82 , MZCONFIG_SECURITY_GUARD ) )) ; 
  if (sg -> file_proc ) {
    Scheme_Object * a [3 ] ; 
    BLOCK_SETUP((PUSHARRAY(a, 3, 0+XfOrM1008_COUNT)));
#   define XfOrM1009_COUNT (3+XfOrM1008_COUNT)
#   define SETUP_XfOrM1009(x) SETUP(XfOrM1009_COUNT)
    a[0] = NULLED_OUT ; 
    a[1] = NULLED_OUT ; 
    a[2] = NULLED_OUT ; 
    a [0 ] = FUNCCALL(SETUP_XfOrM1009(_), scheme_intern_symbol (who ) ); 
    a [1 ] = FUNCCALL(SETUP_XfOrM1009(_), scheme_make_sized_path ((char * ) filename , - 1 , 1 ) ); 
    a [2 ] = FUNCCALL(SETUP_XfOrM1009(_), scheme_make_sized_path ((char * ) content , - 1 , 1 ) ); 
    while (sg -> parent ) {
#     define XfOrM1012_COUNT (0+XfOrM1009_COUNT)
#     define SETUP_XfOrM1012(x) SETUP_XfOrM1009(x)
      if (sg -> link_proc )
        FUNCCALL(SETUP_XfOrM1012(_), scheme_apply (sg -> link_proc , 3 , a ) ); 
      else {
#       define XfOrM1013_COUNT (0+XfOrM1012_COUNT)
#       define SETUP_XfOrM1013(x) SETUP_XfOrM1012(x)
        FUNCCALL(SETUP_XfOrM1013(_), scheme_signal_error ("%s: security guard does not allow any link operation; attempted from: %s to: %s" , who , filename , content ) ); 
      }
      sg = sg -> parent ; 
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_security_check_network (const char * who , const char * host , int port , int client ) {
  Scheme_Security_Guard * sg ; 
  Scheme_Config * __funcarg83 = NULLED_OUT ; 
  PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(sg, 0), PUSH(host, 1), PUSH(who, 2)));
# define XfOrM1014_COUNT (3)
# define SETUP_XfOrM1014(x) SETUP(XfOrM1014_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  sg = NULLED_OUT ; 
  sg = (Scheme_Security_Guard * ) (__funcarg83 = FUNCCALL(SETUP_XfOrM1014(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg83 , MZCONFIG_SECURITY_GUARD ) )) ; 
  if (sg -> network_proc ) {
    Scheme_Object * a [4 ] ; 
    BLOCK_SETUP((PUSHARRAY(a, 4, 0+XfOrM1014_COUNT)));
#   define XfOrM1015_COUNT (3+XfOrM1014_COUNT)
#   define SETUP_XfOrM1015(x) SETUP(XfOrM1015_COUNT)
    NULL_OUT_ARRAY (a ) ; 
    if (! client_symbol ) {
#     define XfOrM1018_COUNT (0+XfOrM1015_COUNT)
#     define SETUP_XfOrM1018(x) SETUP_XfOrM1015(x)
      FUNCCALL(SETUP_XfOrM1018(_), scheme_register_static ((void * ) & client_symbol , sizeof (client_symbol ) ) ); 
      FUNCCALL(SETUP_XfOrM1018(_), scheme_register_static ((void * ) & server_symbol , sizeof (server_symbol ) ) ); 
      client_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("client" ) ); 
      server_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("server" ) ); 
    }
    a [0 ] = FUNCCALL(SETUP_XfOrM1015(_), scheme_intern_symbol (who ) ); 
    a [1 ] = (host ? FUNCCALL(SETUP_XfOrM1015(_), scheme_make_sized_utf8_string ((char * ) host , - 1 ) ): scheme_false ) ; 
    a [2 ] = ((port < 1 ) ? scheme_false : ((Scheme_Object * ) (void * ) (long ) ((((long ) (port ) ) << 1 ) | 0x1 ) ) ) ; 
    a [3 ] = (client ? client_symbol : server_symbol ) ; 
    while (sg -> parent ) {
#     define XfOrM1017_COUNT (0+XfOrM1015_COUNT)
#     define SETUP_XfOrM1017(x) SETUP_XfOrM1015(x)
      FUNCCALL(SETUP_XfOrM1017(_), scheme_apply (sg -> network_proc , 4 , a ) ); 
      sg = sg -> parent ; 
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
typedef struct ActiveWill {
  Scheme_Type type ; 
  Scheme_Object * o ; 
  Scheme_Object * proc ; 
  struct WillExecutor * w ; 
  struct ActiveWill * next ; 
}
ActiveWill ; 
typedef struct WillExecutor {
  Scheme_Object so ; 
  Scheme_Object * sema ; 
  ActiveWill * first , * last ; 
}
WillExecutor ; 
typedef struct WillRegistration {
  Scheme_Type type ; 
  Scheme_Object * proc ; 
  WillExecutor * w ; 
}
WillRegistration ; 
static void activate_will (void * o , void * data ) {
  WillRegistration * r = (WillRegistration * ) data ; 
  ActiveWill * a ; 
  WillExecutor * w ; 
  PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(r, 0), PUSH(a, 1), PUSH(w, 2), PUSH(o, 3)));
# define XfOrM1019_COUNT (4)
# define SETUP_XfOrM1019(x) SETUP(XfOrM1019_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a = NULLED_OUT ; 
  w = NULLED_OUT ; 
  a = ((ActiveWill * ) FUNCCALL(SETUP_XfOrM1019(_), GC_malloc_one_small_tagged ((((sizeof (ActiveWill ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  a -> type = scheme_rt_will ; 
  a -> o = (Scheme_Object * ) o ; 
  a -> proc = r -> proc ; 
  w = r -> w ; 
  if (w -> last )
    w -> last -> next = a ; 
  else w -> first = a ; 
  w -> last = a ; 
  FUNCCALL_EMPTY(scheme_post_sema (w -> sema ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_next_will (WillExecutor * w ) {
  ActiveWill * a ; 
  Scheme_Object * o [1 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSHARRAY(o, 1, 0)));
# define XfOrM1020_COUNT (3)
# define SETUP_XfOrM1020(x) SETUP(XfOrM1020_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a = NULLED_OUT ; 
  o[0] = NULLED_OUT ; 
  a = w -> first ; 
  w -> first = a -> next ; 
  if (! w -> first )
    w -> last = ((void * ) 0 ) ; 
  o [0 ] = a -> o ; 
  a -> o = ((void * ) 0 ) ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM1020(_), scheme_apply_multi (a -> proc , 1 , o ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_will_executor (int argc , Scheme_Object * * argv ) {
  WillExecutor * w ; 
  Scheme_Object * sema ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(w, 0), PUSH(sema, 1)));
# define XfOrM1021_COUNT (2)
# define SETUP_XfOrM1021(x) SETUP(XfOrM1021_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  w = NULLED_OUT ; 
  sema = NULLED_OUT ; 
  w = ((WillExecutor * ) FUNCCALL(SETUP_XfOrM1021(_), GC_malloc_one_small_tagged ((((sizeof (WillExecutor ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  sema = FUNCCALL(SETUP_XfOrM1021(_), scheme_make_sema (0 ) ); 
  w -> so . type = scheme_will_executor_type ; 
  w -> first = ((void * ) 0 ) ; 
  w -> last = ((void * ) 0 ) ; 
  w -> sema = sema ; 
  RET_VALUE_START ((Scheme_Object * ) w ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * will_executor_p (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_will_executor_type ) ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * register_will (int argc , Scheme_Object * * argv ) {
  WillRegistration * r ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(r, 0), PUSH(argv, 1)));
# define XfOrM1023_COUNT (2)
# define SETUP_XfOrM1023(x) SETUP(XfOrM1023_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  r = NULLED_OUT ; 
  if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) != (Scheme_Type ) (scheme_will_executor_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("will-register" , "will-executor" , 0 , argc , argv ) ); 
  FUNCCALL(SETUP_XfOrM1023(_), scheme_check_proc_arity ("will-register" , 1 , 2 , argc , argv ) ); 
  r = ((WillRegistration * ) FUNCCALL(SETUP_XfOrM1023(_), GC_malloc_one_small_tagged ((((sizeof (WillRegistration ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  r -> type = scheme_rt_will_registration ; 
  r -> proc = argv [2 ] ; 
  r -> w = (WillExecutor * ) argv [0 ] ; 
  FUNCCALL_EMPTY(scheme_add_scheme_finalizer (argv [1 ] , activate_will , (void * ) r ) ); 
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * will_executor_try (int argc , Scheme_Object * * argv ) {
  WillExecutor * w ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(w, 0)));
# define XfOrM1024_COUNT (1)
# define SETUP_XfOrM1024(x) SETUP(XfOrM1024_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  w = NULLED_OUT ; 
  if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) != (Scheme_Type ) (scheme_will_executor_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("will-try-execute" , "will-executor" , 0 , argc , argv ) ); 
  w = (WillExecutor * ) argv [0 ] ; 
  if (FUNCCALL(SETUP_XfOrM1024(_), scheme_wait_sema (w -> sema , 1 ) ))
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(do_next_will (w ) )) RET_VALUE_EMPTY_END ; 
  else RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * will_executor_go (int argc , Scheme_Object * * argv ) {
  WillExecutor * w ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(w, 0)));
# define XfOrM1025_COUNT (1)
# define SETUP_XfOrM1025(x) SETUP(XfOrM1025_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  w = NULLED_OUT ; 
  if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) != (Scheme_Type ) (scheme_will_executor_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("will-execute" , "will-executor" , 0 , argc , argv ) ); 
  w = (WillExecutor * ) argv [0 ] ; 
  FUNCCALL(SETUP_XfOrM1025(_), scheme_wait_sema (w -> sema , 0 ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(do_next_will (w ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * will_executor_sema (Scheme_Object * w , int * repost ) {
  /* No conversion */
  * repost = 1 ; 
  return ((WillExecutor * ) w ) -> sema ; 
}
void scheme_zero_unneeded_rands (Scheme_Thread * p ) {
}
static void prepare_thread_for_GC (Scheme_Object * t ) {
  Scheme_Thread * p = (Scheme_Thread * ) t ; 
  if (! p -> nestee ) {
    Scheme_Saved_Stack * saved ; 
    ; 
    if ((! p -> runstack_owner || (p == * p -> runstack_owner ) ) && p -> runstack_start ) {
      long rs_end ; 
      Scheme_Object * * rs_start ; 
      if (p -> meta_prompt && (p -> meta_prompt -> runstack_boundary_start == p -> runstack_start ) ) {
        rs_end = p -> meta_prompt -> runstack_boundary_offset ; 
      }
      else {
        rs_end = p -> runstack_size ; 
      }
      if ((p -> runstack_tmp_keep >= p -> runstack_start ) && (p -> runstack_tmp_keep < p -> runstack ) )
        rs_start = p -> runstack_tmp_keep ; 
      else rs_start = p -> runstack ; 
      scheme_set_runstack_limits (p -> runstack_start , p -> runstack_size , rs_start - p -> runstack_start , rs_end ) ; 
      ; 
      for (saved = p -> runstack_saved ; saved ; saved = saved -> prev ) {
        ; 
        if (p -> meta_prompt && (p -> meta_prompt -> runstack_boundary_start == saved -> runstack_start ) ) {
          rs_end = p -> meta_prompt -> runstack_boundary_offset ; 
        }
        else {
          rs_end = saved -> runstack_size ; 
        }
        scheme_set_runstack_limits (saved -> runstack_start , saved -> runstack_size , saved -> runstack_offset , rs_end ) ; 
      }
    }
    ; 
    if (p -> tail_buffer && (p -> tail_buffer != p -> runstack_tmp_keep ) ) {
      int i ; 
      for (i = 0 ; i < p -> tail_buffer_size ; i ++ ) {
        p -> tail_buffer [i ] = ((void * ) 0 ) ; 
      }
    }
  }
  if ((! p -> cont_mark_stack_owner || (p == * p -> cont_mark_stack_owner ) ) && p -> cont_mark_stack ) {
    int segcount , i , segpos ; 
    if (p -> cont_mark_stack )
      segcount = ((long ) (p -> cont_mark_stack - 1 ) >> 8 ) + 1 ; 
    else segcount = 0 ; 
    for (i = segcount ; i < p -> cont_mark_seg_count ; i ++ ) {
      p -> cont_mark_stack_segments [i ] = ((void * ) 0 ) ; 
    }
    if (segcount < p -> cont_mark_seg_count )
      p -> cont_mark_seg_count = segcount ; 
    segpos = ((long ) p -> cont_mark_stack >> 8 ) ; 
    if (segpos < p -> cont_mark_seg_count ) {
      Scheme_Cont_Mark * seg = p -> cont_mark_stack_segments [segpos ] ; 
      int stackpos = ((long ) p -> cont_mark_stack & ((1 << 8 ) - 1 ) ) ; 
      if (seg ) {
        for (i = stackpos ; i < (1 << 8 ) ; i ++ ) {
          if (seg [i ] . key ) {
            seg [i ] . key = ((void * ) 0 ) ; 
            seg [i ] . val = ((void * ) 0 ) ; 
            seg [i ] . cache = ((void * ) 0 ) ; 
          }
          else {
            break ; 
          }
        }
      }
    }
    {
      long pos ; 
      for (pos = 0 ; pos < p -> cont_mark_stack_bottom ; pos ++ ) {
        Scheme_Cont_Mark * seg ; 
        int stackpos ; 
        segpos = ((long ) pos >> 8 ) ; 
        seg = p -> cont_mark_stack_segments [segpos ] ; 
        if (seg ) {
          stackpos = ((long ) pos & ((1 << 8 ) - 1 ) ) ; 
          seg [stackpos ] . key = ((void * ) 0 ) ; 
          seg [stackpos ] . val = ((void * ) 0 ) ; 
          seg [stackpos ] . cache = ((void * ) 0 ) ; 
        }
      }
    }
  }
  if (p -> values_buffer ) {
    if (p -> values_buffer_size > 128 )
      p -> values_buffer = ((void * ) 0 ) ; 
    else {
      memset (p -> values_buffer , 0 , sizeof (Scheme_Object * ) * p -> values_buffer_size ) ; 
    }
  }
  p -> spare_runstack = ((void * ) 0 ) ; 
  scheme_clean_list_stack (p ) ; 
}
static void prepare_this_thread_for_GC (Scheme_Thread * p ) {
  if (p == scheme_current_thread ) {
    scheme_current_thread -> runstack = scheme_current_runstack ; 
    scheme_current_thread -> runstack_start = scheme_current_runstack_start ; 
    scheme_current_thread -> cont_mark_stack = scheme_current_cont_mark_stack ; 
    scheme_current_thread -> cont_mark_pos = scheme_current_cont_mark_pos ; 
  }
  prepare_thread_for_GC ((Scheme_Object * ) p ) ; 
}
static void get_ready_for_GC () {
  start_this_gc_time = scheme_get_process_milliseconds () ; 
  scheme_zero_unneeded_rands (scheme_current_thread ) ; 
  scheme_clear_modidx_cache () ; 
  scheme_clear_shift_cache () ; 
  scheme_clear_prompt_cache () ; 
  scheme_clear_rx_buffers () ; 
  scheme_clear_bignum_cache () ; 
  if (scheme_current_thread -> running ) {
    scheme_current_thread -> runstack = scheme_current_runstack ; 
    scheme_current_thread -> runstack_start = scheme_current_runstack_start ; 
    scheme_current_thread -> cont_mark_stack = scheme_current_cont_mark_stack ; 
    scheme_current_thread -> cont_mark_pos = scheme_current_cont_mark_pos ; 
  }
  for_each_managed (scheme_thread_type , prepare_thread_for_GC ) ; 
  scheme_flush_stack_copy_cache () ; 
  scheme_fuel_counter = 0 ; 
  scheme_block_child_signals (1 ) ; 
  did_gc_count ++ ; 
  delayed_break_ready = 0 ; 
  delay_breaks = 1 ; 
}
extern int GC_words_allocd ; 
static void done_with_GC () {
  if (scheme_current_thread -> running ) {
    scheme_current_runstack = scheme_current_thread -> runstack ; 
    scheme_current_runstack_start = scheme_current_thread -> runstack_start ; 
  }
  scheme_block_child_signals (0 ) ; 
  delay_breaks = 0 ; 
  if (delayed_break_ready )
    scheme_break_thread (((void * ) 0 ) ) ; 
  scheme_total_gc_time += (scheme_get_process_milliseconds () - start_this_gc_time ) ; 
}
static Scheme_Object * current_stats (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * v ; 
  Scheme_Thread * t = ((void * ) 0 ) ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(t, 1), PUSH(argv, 2)));
# define XfOrM1027_COUNT (3)
# define SETUP_XfOrM1027(x) SETUP(XfOrM1027_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  v = NULLED_OUT ; 
  v = argv [0 ] ; 
  if (! (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) && (! (((Scheme_Inclhash_Object * ) (v ) ) -> so . keyex & 0x1 ) ) ) )
    FUNCCALL(SETUP_XfOrM1027(_), scheme_wrong_type ("vector-set-performance-stats!" , "mutable vector" , 0 , argc , argv ) ); 
  if (argc > 1 ) {
#   define XfOrM1047_COUNT (0+XfOrM1027_COUNT)
#   define SETUP_XfOrM1047(x) SETUP_XfOrM1027(x)
    if (! (((argv [1 ] ) ) == (scheme_false ) ) ) {
#     define XfOrM1048_COUNT (0+XfOrM1047_COUNT)
#     define SETUP_XfOrM1048(x) SETUP_XfOrM1047(x)
      if (! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_type ) ) )
        FUNCCALL(SETUP_XfOrM1048(_), scheme_wrong_type ("vector-set-performance-stats!" , "thread or #f" , 0 , argc , argv ) ); 
      t = (Scheme_Thread * ) argv [1 ] ; 
    }
  }
  if (t ) {
#   define XfOrM1030_COUNT (0+XfOrM1027_COUNT)
#   define SETUP_XfOrM1030(x) SETUP_XfOrM1027(x)
    switch ((((Scheme_Vector * ) (v ) ) -> size ) ) {
#     define XfOrM1031_COUNT (0+XfOrM1030_COUNT)
#     define SETUP_XfOrM1031(x) SETUP_XfOrM1030(x)
      default : case 4 : {
        long sz = 0 ; 
        if (((t -> running ) && ! ((t -> running ) & 0x4 ) ) ) {
          Scheme_Overflow * overflow ; 
          Scheme_Saved_Stack * runstack_saved ; 
          overflow = NULLED_OUT ; 
          runstack_saved = NULLED_OUT ; 
          if (t == scheme_current_thread ) {
            void * stk_start , * stk_end ; 
            stk_start = NULLED_OUT ; 
            stk_end = NULLED_OUT ; 
            stk_start = (t -> stack_start ) ; 
            stk_end = (void * ) & stk_end ; 
            sz = (long ) stk_start XFORM_OK_MINUS (long ) stk_end ; 
          }
          else {
            if (t -> jmpup_buf . stack_copy )
              sz = t -> jmpup_buf . stack_size ; 
          }
          for (overflow = t -> overflow ; overflow ; overflow = overflow -> prev ) {
            sz += overflow -> jmp -> cont . stack_size ; 
          }
          {
            int ssz ; 
            if (t == scheme_current_thread ) {
              ssz = (scheme_current_runstack_start + t -> runstack_size ) - scheme_current_runstack ; 
            }
            else {
              ssz = (t -> runstack_start + t -> runstack_size ) - t -> runstack ; 
            }
            for (runstack_saved = t -> runstack_saved ; runstack_saved ; runstack_saved = runstack_saved -> prev ) {
              ssz += runstack_saved -> runstack_size ; 
            }
            sz += sizeof (Scheme_Object * ) * ssz ; 
          }
          if (t == scheme_current_thread ) {
            sz += ((long ) scheme_current_cont_mark_pos >> 1 ) * sizeof (Scheme_Cont_Mark ) ; 
          }
          else {
            sz += ((long ) t -> cont_mark_pos >> 1 ) * sizeof (Scheme_Cont_Mark ) ; 
          }
        }
        (((Scheme_Vector * ) (v ) ) -> els ) [3 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (sz ) ) << 1 ) | 0x1 ) ) ; 
      }
      case 3 : (((Scheme_Vector * ) (v ) ) -> els ) [2 ] = (t -> block_descriptor ? scheme_true : ((t -> running & 0x2 ) ? scheme_true : scheme_false ) ) ; 
      case 2 : {
        Scheme_Object * dp ; 
        BLOCK_SETUP((PUSH(dp, 0+XfOrM1031_COUNT)));
#       define XfOrM1033_COUNT (1+XfOrM1031_COUNT)
#       define SETUP_XfOrM1033(x) SETUP(XfOrM1033_COUNT)
        dp = NULLED_OUT ; 
        dp = FUNCCALL(SETUP_XfOrM1033(_), thread_dead_p (1 , (Scheme_Object * * ) (void * ) & t ) ); 
        (((Scheme_Vector * ) (v ) ) -> els ) [1 ] = dp ; 
      }
      case 1 : {
        Scheme_Object * rp ; 
        BLOCK_SETUP((PUSH(rp, 0+XfOrM1031_COUNT)));
#       define XfOrM1032_COUNT (1+XfOrM1031_COUNT)
#       define SETUP_XfOrM1032(x) SETUP(XfOrM1032_COUNT)
        rp = NULLED_OUT ; 
        rp = FUNCCALL(SETUP_XfOrM1032(_), thread_running_p (1 , (Scheme_Object * * ) (void * ) & t ) ); 
        (((Scheme_Vector * ) (v ) ) -> els ) [0 ] = rp ; 
      }
      case 0 : break ; 
    }
  }
  else {
    long cpuend , end , gcend ; 
    cpuend = scheme_get_process_milliseconds () ; 
    end = scheme_get_milliseconds () ; 
    gcend = scheme_total_gc_time ; 
    switch ((((Scheme_Vector * ) (v ) ) -> size ) ) {
      default : case 10 : (((Scheme_Vector * ) (v ) ) -> els ) [9 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (scheme_hash_iteration_count ) ) << 1 ) | 0x1 ) ) ; 
      case 9 : (((Scheme_Vector * ) (v ) ) -> els ) [8 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (scheme_hash_request_count ) ) << 1 ) | 0x1 ) ) ; 
      case 8 : (((Scheme_Vector * ) (v ) ) -> els ) [7 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (scheme_num_read_syntax_objects ) ) << 1 ) | 0x1 ) ) ; 
      case 7 : (((Scheme_Vector * ) (v ) ) -> els ) [6 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (num_running_threads ) ) << 1 ) | 0x1 ) ) ; 
      case 6 : (((Scheme_Vector * ) (v ) ) -> els ) [5 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (scheme_overflow_count ) ) << 1 ) | 0x1 ) ) ; 
      case 5 : (((Scheme_Vector * ) (v ) ) -> els ) [4 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (thread_swap_count ) ) << 1 ) | 0x1 ) ) ; 
      case 4 : (((Scheme_Vector * ) (v ) ) -> els ) [3 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (did_gc_count ) ) << 1 ) | 0x1 ) ) ; 
      case 3 : (((Scheme_Vector * ) (v ) ) -> els ) [2 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (gcend ) ) << 1 ) | 0x1 ) ) ; 
      case 2 : (((Scheme_Vector * ) (v ) ) -> els ) [1 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (end ) ) << 1 ) | 0x1 ) ) ; 
      case 1 : (((Scheme_Vector * ) (v ) ) -> els ) [0 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (cpuend ) ) << 1 ) | 0x1 ) ) ; 
      case 0 : break ; 
    }
  }
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Jumpup_Buf_Holder * scheme_new_jmpupbuf_holder (void ) {
  Scheme_Jumpup_Buf_Holder * h ; 
  DECL_RET_SAVE (Scheme_Jumpup_Buf_Holder * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(h, 0)));
# define XfOrM1049_COUNT (1)
# define SETUP_XfOrM1049(x) SETUP(XfOrM1049_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  h = NULLED_OUT ; 
  h = ((Scheme_Jumpup_Buf_Holder * ) FUNCCALL(SETUP_XfOrM1049(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Jumpup_Buf_Holder ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  h -> type = scheme_rt_buf_holder ; 
  RET_VALUE_START (h ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static unsigned long get_current_stack_start (void ) {
  /* No conversion */
  Scheme_Thread * p ; 
  p = scheme_current_thread ; 
  return (unsigned long ) (p -> stack_start ) ; 
}
static int mark_parameterization_SIZE (void * p ) {
  return (((sizeof (Scheme_Parameterization ) + ((max_configs - 1 ) * sizeof (Scheme_Object * ) ) ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_parameterization_MARK (void * p ) {
  Scheme_Parameterization * c = (Scheme_Parameterization * ) p ; 
  int i ; 
  for (i = max_configs ; i -- ; ) {
    GC_mark (c -> prims [i ] ) ; 
  }
  GC_mark (c -> extensions ) ; 
  return (((sizeof (Scheme_Parameterization ) + ((max_configs - 1 ) * sizeof (Scheme_Object * ) ) ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_parameterization_FIXUP (void * p ) {
  Scheme_Parameterization * c = (Scheme_Parameterization * ) p ; 
  int i ; 
  for (i = max_configs ; i -- ; ) {
    GC_fixup (& (c -> prims [i ] ) ) ; 
  }
  GC_fixup (& (c -> extensions ) ) ; 
  return (((sizeof (Scheme_Parameterization ) + ((max_configs - 1 ) * sizeof (Scheme_Object * ) ) ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_config_SIZE (void * p ) {
  return ((sizeof (Scheme_Config ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_config_MARK (void * p ) {
  Scheme_Config * config = (Scheme_Config * ) p ; 
  GC_mark (config -> key ) ; 
  GC_mark (config -> cell ) ; 
  GC_mark (config -> next ) ; 
  return ((sizeof (Scheme_Config ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_config_FIXUP (void * p ) {
  Scheme_Config * config = (Scheme_Config * ) p ; 
  GC_fixup (& (config -> key ) ) ; 
  GC_fixup (& (config -> cell ) ) ; 
  GC_fixup (& (config -> next ) ) ; 
  return ((sizeof (Scheme_Config ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_will_executor_val_SIZE (void * p ) {
  return ((sizeof (WillExecutor ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_will_executor_val_MARK (void * p ) {
  WillExecutor * e = (WillExecutor * ) p ; 
  GC_mark (e -> sema ) ; 
  GC_mark (e -> first ) ; 
  GC_mark (e -> last ) ; 
  return ((sizeof (WillExecutor ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_will_executor_val_FIXUP (void * p ) {
  WillExecutor * e = (WillExecutor * ) p ; 
  GC_fixup (& (e -> sema ) ) ; 
  GC_fixup (& (e -> first ) ) ; 
  GC_fixup (& (e -> last ) ) ; 
  return ((sizeof (WillExecutor ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_custodian_val_SIZE (void * p ) {
  return ((sizeof (Scheme_Custodian ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_custodian_val_MARK (void * p ) {
  Scheme_Custodian * m = (Scheme_Custodian * ) p ; 
  GC_mark (m -> boxes ) ; 
  GC_mark (m -> mrefs ) ; 
  GC_mark (m -> closers ) ; 
  GC_mark (m -> data ) ; 
  GC_mark (m -> parent ) ; 
  GC_mark (m -> sibling ) ; 
  GC_mark (m -> children ) ; 
  GC_mark (m -> global_next ) ; 
  GC_mark (m -> global_prev ) ; 
  GC_mark (m -> cust_boxes ) ; 
  return ((sizeof (Scheme_Custodian ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_custodian_val_FIXUP (void * p ) {
  Scheme_Custodian * m = (Scheme_Custodian * ) p ; 
  GC_fixup (& (m -> boxes ) ) ; 
  GC_fixup (& (m -> mrefs ) ) ; 
  GC_fixup (& (m -> closers ) ) ; 
  GC_fixup (& (m -> data ) ) ; 
  GC_fixup (& (m -> parent ) ) ; 
  GC_fixup (& (m -> sibling ) ) ; 
  GC_fixup (& (m -> children ) ) ; 
  GC_fixup (& (m -> global_next ) ) ; 
  GC_fixup (& (m -> global_prev ) ) ; 
  GC_fixup (& (m -> cust_boxes ) ) ; 
  return ((sizeof (Scheme_Custodian ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_custodian_box_val_SIZE (void * p ) {
  return ((sizeof (Scheme_Custodian_Box ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_custodian_box_val_MARK (void * p ) {
  Scheme_Custodian_Box * b = (Scheme_Custodian_Box * ) p ; 
  int sd = ((Scheme_Custodian * ) GC_resolve (b -> cust ) ) -> shut_down ; 
  GC_mark (b -> cust ) ; 
  if (! sd ) {
    GC_mark (b -> v ) ; 
  }
  return ((sizeof (Scheme_Custodian_Box ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_custodian_box_val_FIXUP (void * p ) {
  Scheme_Custodian_Box * b = (Scheme_Custodian_Box * ) p ; 
  int sd = ((Scheme_Custodian * ) GC_resolve (b -> cust ) ) -> shut_down ; 
  GC_fixup (& (b -> cust ) ) ; 
  if (! sd ) {
    GC_fixup (& (b -> v ) ) ; 
  }
  return ((sizeof (Scheme_Custodian_Box ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_thread_hop_SIZE (void * p ) {
  return ((sizeof (Scheme_Thread_Custodian_Hop ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_thread_hop_MARK (void * p ) {
  Scheme_Thread_Custodian_Hop * hop = (Scheme_Thread_Custodian_Hop * ) p ; 
  GC_mark (hop -> p ) ; 
  return ((sizeof (Scheme_Thread_Custodian_Hop ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_thread_hop_FIXUP (void * p ) {
  Scheme_Thread_Custodian_Hop * hop = (Scheme_Thread_Custodian_Hop * ) p ; 
  GC_fixup (& (hop -> p ) ) ; 
  return ((sizeof (Scheme_Thread_Custodian_Hop ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_namespace_option_SIZE (void * p ) {
  return ((sizeof (Scheme_NSO ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_namespace_option_MARK (void * p ) {
  Scheme_NSO * o = (Scheme_NSO * ) p ; 
  GC_mark (o -> key ) ; 
  return ((sizeof (Scheme_NSO ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_namespace_option_FIXUP (void * p ) {
  Scheme_NSO * o = (Scheme_NSO * ) p ; 
  GC_fixup (& (o -> key ) ) ; 
  return ((sizeof (Scheme_NSO ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_param_data_SIZE (void * p ) {
  return ((sizeof (ParamData ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_param_data_MARK (void * p ) {
  ParamData * d = (ParamData * ) p ; 
  GC_mark (d -> key ) ; 
  GC_mark (d -> guard ) ; 
  GC_mark (d -> extract_guard ) ; 
  GC_mark (d -> defcell ) ; 
  return ((sizeof (ParamData ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_param_data_FIXUP (void * p ) {
  ParamData * d = (ParamData * ) p ; 
  GC_fixup (& (d -> key ) ) ; 
  GC_fixup (& (d -> guard ) ) ; 
  GC_fixup (& (d -> extract_guard ) ) ; 
  GC_fixup (& (d -> defcell ) ) ; 
  return ((sizeof (ParamData ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_will_SIZE (void * p ) {
  return ((sizeof (ActiveWill ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_will_MARK (void * p ) {
  ActiveWill * w = (ActiveWill * ) p ; 
  GC_mark (w -> o ) ; 
  GC_mark (w -> proc ) ; 
  GC_mark (w -> w ) ; 
  GC_mark (w -> next ) ; 
  return ((sizeof (ActiveWill ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_will_FIXUP (void * p ) {
  ActiveWill * w = (ActiveWill * ) p ; 
  GC_fixup (& (w -> o ) ) ; 
  GC_fixup (& (w -> proc ) ) ; 
  GC_fixup (& (w -> w ) ) ; 
  GC_fixup (& (w -> next ) ) ; 
  return ((sizeof (ActiveWill ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_will_registration_SIZE (void * p ) {
  return ((sizeof (WillRegistration ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_will_registration_MARK (void * p ) {
  WillRegistration * r = (WillRegistration * ) p ; 
  GC_mark (r -> proc ) ; 
  GC_mark (r -> w ) ; 
  return ((sizeof (WillRegistration ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_will_registration_FIXUP (void * p ) {
  WillRegistration * r = (WillRegistration * ) p ; 
  GC_fixup (& (r -> proc ) ) ; 
  GC_fixup (& (r -> w ) ) ; 
  return ((sizeof (WillRegistration ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_evt_SIZE (void * p ) {
  return ((sizeof (Evt ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_evt_MARK (void * p ) {
  return ((sizeof (Evt ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_evt_FIXUP (void * p ) {
  return ((sizeof (Evt ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_syncing_SIZE (void * p ) {
  return ((sizeof (Syncing ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_syncing_MARK (void * p ) {
  Syncing * w = (Syncing * ) p ; 
  GC_mark (w -> set ) ; 
  GC_mark (w -> wrapss ) ; 
  GC_mark (w -> nackss ) ; 
  GC_mark (w -> reposts ) ; 
  GC_mark (w -> disable_break ) ; 
  return ((sizeof (Syncing ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_syncing_FIXUP (void * p ) {
  Syncing * w = (Syncing * ) p ; 
  GC_fixup (& (w -> set ) ) ; 
  GC_fixup (& (w -> wrapss ) ) ; 
  GC_fixup (& (w -> nackss ) ) ; 
  GC_fixup (& (w -> reposts ) ) ; 
  GC_fixup (& (w -> disable_break ) ) ; 
  return ((sizeof (Syncing ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_evt_set_SIZE (void * p ) {
  return ((sizeof (Evt_Set ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_evt_set_MARK (void * p ) {
  Evt_Set * w = (Evt_Set * ) p ; 
  GC_mark (w -> ws ) ; 
  GC_mark (w -> argv ) ; 
  return ((sizeof (Evt_Set ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_evt_set_FIXUP (void * p ) {
  Evt_Set * w = (Evt_Set * ) p ; 
  GC_fixup (& (w -> ws ) ) ; 
  GC_fixup (& (w -> argv ) ) ; 
  return ((sizeof (Evt_Set ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_thread_set_SIZE (void * p ) {
  return ((sizeof (Scheme_Thread_Set ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_thread_set_MARK (void * p ) {
  Scheme_Thread_Set * ts = (Scheme_Thread_Set * ) p ; 
  GC_mark (ts -> parent ) ; 
  GC_mark (ts -> first ) ; 
  GC_mark (ts -> next ) ; 
  GC_mark (ts -> prev ) ; 
  GC_mark (ts -> search_start ) ; 
  GC_mark (ts -> current ) ; 
  return ((sizeof (Scheme_Thread_Set ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_thread_set_FIXUP (void * p ) {
  Scheme_Thread_Set * ts = (Scheme_Thread_Set * ) p ; 
  GC_fixup (& (ts -> parent ) ) ; 
  GC_fixup (& (ts -> first ) ) ; 
  GC_fixup (& (ts -> next ) ) ; 
  GC_fixup (& (ts -> prev ) ) ; 
  GC_fixup (& (ts -> search_start ) ) ; 
  GC_fixup (& (ts -> current ) ) ; 
  return ((sizeof (Scheme_Thread_Set ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_thread_cell_SIZE (void * p ) {
  return ((sizeof (Thread_Cell ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_thread_cell_MARK (void * p ) {
  Thread_Cell * c = (Thread_Cell * ) p ; 
  GC_mark (c -> def_val ) ; 
  return ((sizeof (Thread_Cell ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_thread_cell_FIXUP (void * p ) {
  Thread_Cell * c = (Thread_Cell * ) p ; 
  GC_fixup (& (c -> def_val ) ) ; 
  return ((sizeof (Thread_Cell ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static void register_traversers (void ) {
  GC_register_traversers (scheme_will_executor_type , mark_will_executor_val_SIZE , mark_will_executor_val_MARK , mark_will_executor_val_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_custodian_type , mark_custodian_val_SIZE , mark_custodian_val_MARK , mark_custodian_val_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_cust_box_type , mark_custodian_box_val_SIZE , mark_custodian_box_val_MARK , mark_custodian_box_val_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_thread_hop_type , mark_thread_hop_SIZE , mark_thread_hop_MARK , mark_thread_hop_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_evt_set_type , mark_evt_set_SIZE , mark_evt_set_MARK , mark_evt_set_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_thread_set_type , mark_thread_set_SIZE , mark_thread_set_MARK , mark_thread_set_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_config_type , mark_config_SIZE , mark_config_MARK , mark_config_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_thread_cell_type , mark_thread_cell_SIZE , mark_thread_cell_MARK , mark_thread_cell_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_namespace_option , mark_namespace_option_SIZE , mark_namespace_option_MARK , mark_namespace_option_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_param_data , mark_param_data_SIZE , mark_param_data_MARK , mark_param_data_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_will , mark_will_SIZE , mark_will_MARK , mark_will_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_will_registration , mark_will_registration_SIZE , mark_will_registration_MARK , mark_will_registration_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_evt , mark_evt_SIZE , mark_evt_MARK , mark_evt_FIXUP , 1 , 1 ) ; 
  GC_register_traversers (scheme_rt_syncing , mark_syncing_SIZE , mark_syncing_MARK , mark_syncing_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_parameterization , mark_parameterization_SIZE , mark_parameterization_MARK , mark_parameterization_FIXUP , 0 , 0 ) ; 
}
