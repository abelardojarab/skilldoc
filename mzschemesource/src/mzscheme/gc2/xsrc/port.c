#include "precomp.h"
typedef __intptr_t intptr_t ; 
extern __off_t lseek (int __fd , __off_t __offset , int __whence ) __attribute__ ((__nothrow__ ) ) ; 
extern int close (int __fd ) ; 
extern ssize_t read (int __fd , void * __buf , size_t __nbytes ) ; 
extern ssize_t write (int __fd , __const void * __buf , size_t __n ) ; 
extern int pipe (int __pipedes [2 ] ) __attribute__ ((__nothrow__ ) ) ; 
extern int dup2 (int __fd , int __fd2 ) __attribute__ ((__nothrow__ ) ) ; 
extern int execv (__const char * __path , char * __const __argv [] ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern void _exit (int __status ) __attribute__ ((__noreturn__ ) ) ; 
enum {
  _PC_LINK_MAX , _PC_MAX_CANON , _PC_MAX_INPUT , _PC_NAME_MAX , _PC_PATH_MAX , _PC_PIPE_BUF , _PC_CHOWN_RESTRICTED , _PC_NO_TRUNC , _PC_VDISABLE , _PC_SYNC_IO , _PC_ASYNC_IO , _PC_PRIO_IO , _PC_SOCK_MAXBUF , _PC_FILESIZEBITS , _PC_REC_INCR_XFER_SIZE , _PC_REC_MAX_XFER_SIZE , _PC_REC_MIN_XFER_SIZE , _PC_REC_XFER_ALIGN , _PC_ALLOC_SIZE_MIN , _PC_SYMLINK_MAX , _PC_2_SYMLINKS }
; 
enum {
  _SC_ARG_MAX , _SC_CHILD_MAX , _SC_CLK_TCK , _SC_NGROUPS_MAX , _SC_OPEN_MAX , _SC_STREAM_MAX , _SC_TZNAME_MAX , _SC_JOB_CONTROL , _SC_SAVED_IDS , _SC_REALTIME_SIGNALS , _SC_PRIORITY_SCHEDULING , _SC_TIMERS , _SC_ASYNCHRONOUS_IO , _SC_PRIORITIZED_IO , _SC_SYNCHRONIZED_IO , _SC_FSYNC , _SC_MAPPED_FILES , _SC_MEMLOCK , _SC_MEMLOCK_RANGE , _SC_MEMORY_PROTECTION , _SC_MESSAGE_PASSING , _SC_SEMAPHORES , _SC_SHARED_MEMORY_OBJECTS , _SC_AIO_LISTIO_MAX , _SC_AIO_MAX , _SC_AIO_PRIO_DELTA_MAX , _SC_DELAYTIMER_MAX , _SC_MQ_OPEN_MAX , _SC_MQ_PRIO_MAX , _SC_VERSION , _SC_PAGESIZE , _SC_RTSIG_MAX , _SC_SEM_NSEMS_MAX , _SC_SEM_VALUE_MAX , _SC_SIGQUEUE_MAX , _SC_TIMER_MAX , _SC_BC_BASE_MAX , _SC_BC_DIM_MAX , _SC_BC_SCALE_MAX , _SC_BC_STRING_MAX , _SC_COLL_WEIGHTS_MAX , _SC_EQUIV_CLASS_MAX , _SC_EXPR_NEST_MAX , _SC_LINE_MAX , _SC_RE_DUP_MAX , _SC_CHARCLASS_NAME_MAX , _SC_2_VERSION , _SC_2_C_BIND , _SC_2_C_DEV , _SC_2_FORT_DEV , _SC_2_FORT_RUN , _SC_2_SW_DEV , _SC_2_LOCALEDEF , _SC_PII , _SC_PII_XTI , _SC_PII_SOCKET , _SC_PII_INTERNET , _SC_PII_OSI , _SC_POLL , _SC_SELECT , _SC_UIO_MAXIOV , _SC_IOV_MAX = _SC_UIO_MAXIOV , _SC_PII_INTERNET_STREAM , _SC_PII_INTERNET_DGRAM , _SC_PII_OSI_COTS , _SC_PII_OSI_CLTS , _SC_PII_OSI_M , _SC_T_IOV_MAX , _SC_THREADS , _SC_THREAD_SAFE_FUNCTIONS , _SC_GETGR_R_SIZE_MAX , _SC_GETPW_R_SIZE_MAX , _SC_LOGIN_NAME_MAX , _SC_TTY_NAME_MAX , _SC_THREAD_DESTRUCTOR_ITERATIONS , _SC_THREAD_KEYS_MAX , _SC_THREAD_STACK_MIN , _SC_THREAD_THREADS_MAX , _SC_THREAD_ATTR_STACKADDR , _SC_THREAD_ATTR_STACKSIZE , _SC_THREAD_PRIORITY_SCHEDULING , _SC_THREAD_PRIO_INHERIT , _SC_THREAD_PRIO_PROTECT , _SC_THREAD_PROCESS_SHARED , _SC_NPROCESSORS_CONF , _SC_NPROCESSORS_ONLN , _SC_PHYS_PAGES , _SC_AVPHYS_PAGES , _SC_ATEXIT_MAX , _SC_PASS_MAX , _SC_XOPEN_VERSION , _SC_XOPEN_XCU_VERSION , _SC_XOPEN_UNIX , _SC_XOPEN_CRYPT , _SC_XOPEN_ENH_I18N , _SC_XOPEN_SHM , _SC_2_CHAR_TERM , _SC_2_C_VERSION , _SC_2_UPE , _SC_XOPEN_XPG2 , _SC_XOPEN_XPG3 , _SC_XOPEN_XPG4 , _SC_CHAR_BIT , _SC_CHAR_MAX , _SC_CHAR_MIN , _SC_INT_MAX , _SC_INT_MIN , _SC_LONG_BIT , _SC_WORD_BIT , _SC_MB_LEN_MAX , _SC_NZERO , _SC_SSIZE_MAX , _SC_SCHAR_MAX , _SC_SCHAR_MIN , _SC_SHRT_MAX , _SC_SHRT_MIN , _SC_UCHAR_MAX , _SC_UINT_MAX , _SC_ULONG_MAX , _SC_USHRT_MAX , _SC_NL_ARGMAX , _SC_NL_LANGMAX , _SC_NL_MSGMAX , _SC_NL_NMAX , _SC_NL_SETMAX , _SC_NL_TEXTMAX , _SC_XBS5_ILP32_OFF32 , _SC_XBS5_ILP32_OFFBIG , _SC_XBS5_LP64_OFF64 , _SC_XBS5_LPBIG_OFFBIG , _SC_XOPEN_LEGACY , _SC_XOPEN_REALTIME , _SC_XOPEN_REALTIME_THREADS , _SC_ADVISORY_INFO , _SC_BARRIERS , _SC_BASE , _SC_C_LANG_SUPPORT , _SC_C_LANG_SUPPORT_R , _SC_CLOCK_SELECTION , _SC_CPUTIME , _SC_THREAD_CPUTIME , _SC_DEVICE_IO , _SC_DEVICE_SPECIFIC , _SC_DEVICE_SPECIFIC_R , _SC_FD_MGMT , _SC_FIFO , _SC_PIPE , _SC_FILE_ATTRIBUTES , _SC_FILE_LOCKING , _SC_FILE_SYSTEM , _SC_MONOTONIC_CLOCK , _SC_MULTI_PROCESS , _SC_SINGLE_PROCESS , _SC_NETWORKING , _SC_READER_WRITER_LOCKS , _SC_SPIN_LOCKS , _SC_REGEXP , _SC_REGEX_VERSION , _SC_SHELL , _SC_SIGNALS , _SC_SPAWN , _SC_SPORADIC_SERVER , _SC_THREAD_SPORADIC_SERVER , _SC_SYSTEM_DATABASE , _SC_SYSTEM_DATABASE_R , _SC_TIMEOUTS , _SC_TYPED_MEMORY_OBJECTS , _SC_USER_GROUPS , _SC_USER_GROUPS_R , _SC_2_PBS , _SC_2_PBS_ACCOUNTING , _SC_2_PBS_LOCATE , _SC_2_PBS_MESSAGE , _SC_2_PBS_TRACK , _SC_SYMLOOP_MAX , _SC_STREAMS , _SC_2_PBS_CHECKPOINT , _SC_V6_ILP32_OFF32 , _SC_V6_ILP32_OFFBIG , _SC_V6_LP64_OFF64 , _SC_V6_LPBIG_OFFBIG , _SC_HOST_NAME_MAX , _SC_TRACE , _SC_TRACE_EVENT_FILTER , _SC_TRACE_INHERIT , _SC_TRACE_LOG , _SC_LEVEL1_ICACHE_SIZE , _SC_LEVEL1_ICACHE_ASSOC , _SC_LEVEL1_ICACHE_LINESIZE , _SC_LEVEL1_DCACHE_SIZE , _SC_LEVEL1_DCACHE_ASSOC , _SC_LEVEL1_DCACHE_LINESIZE , _SC_LEVEL2_CACHE_SIZE , _SC_LEVEL2_CACHE_ASSOC , _SC_LEVEL2_CACHE_LINESIZE , _SC_LEVEL3_CACHE_SIZE , _SC_LEVEL3_CACHE_ASSOC , _SC_LEVEL3_CACHE_LINESIZE , _SC_LEVEL4_CACHE_SIZE , _SC_LEVEL4_CACHE_ASSOC , _SC_LEVEL4_CACHE_LINESIZE , _SC_IPV6 = _SC_LEVEL1_ICACHE_SIZE + 50 , _SC_RAW_SOCKETS }
; 
enum {
  _CS_PATH , _CS_V6_WIDTH_RESTRICTED_ENVS , _CS_GNU_LIBC_VERSION , _CS_GNU_LIBPTHREAD_VERSION , _CS_LFS_CFLAGS = 1000 , _CS_LFS_LDFLAGS , _CS_LFS_LIBS , _CS_LFS_LINTFLAGS , _CS_LFS64_CFLAGS , _CS_LFS64_LDFLAGS , _CS_LFS64_LIBS , _CS_LFS64_LINTFLAGS , _CS_XBS5_ILP32_OFF32_CFLAGS = 1100 , _CS_XBS5_ILP32_OFF32_LDFLAGS , _CS_XBS5_ILP32_OFF32_LIBS , _CS_XBS5_ILP32_OFF32_LINTFLAGS , _CS_XBS5_ILP32_OFFBIG_CFLAGS , _CS_XBS5_ILP32_OFFBIG_LDFLAGS , _CS_XBS5_ILP32_OFFBIG_LIBS , _CS_XBS5_ILP32_OFFBIG_LINTFLAGS , _CS_XBS5_LP64_OFF64_CFLAGS , _CS_XBS5_LP64_OFF64_LDFLAGS , _CS_XBS5_LP64_OFF64_LIBS , _CS_XBS5_LP64_OFF64_LINTFLAGS , _CS_XBS5_LPBIG_OFFBIG_CFLAGS , _CS_XBS5_LPBIG_OFFBIG_LDFLAGS , _CS_XBS5_LPBIG_OFFBIG_LIBS , _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS , _CS_POSIX_V6_ILP32_OFF32_CFLAGS , _CS_POSIX_V6_ILP32_OFF32_LDFLAGS , _CS_POSIX_V6_ILP32_OFF32_LIBS , _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS , _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS , _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS , _CS_POSIX_V6_ILP32_OFFBIG_LIBS , _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS , _CS_POSIX_V6_LP64_OFF64_CFLAGS , _CS_POSIX_V6_LP64_OFF64_LDFLAGS , _CS_POSIX_V6_LP64_OFF64_LIBS , _CS_POSIX_V6_LP64_OFF64_LINTFLAGS , _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS , _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS , _CS_POSIX_V6_LPBIG_OFFBIG_LIBS , _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS }
; 
extern __pid_t fork (void ) __attribute__ ((__nothrow__ ) ) ; 
extern int isatty (int __fd ) __attribute__ ((__nothrow__ ) ) ; 
extern int unlink (__const char * __name ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern int getdtablesize (void ) __attribute__ ((__nothrow__ ) ) ; 
struct flock {
  short int l_type ; 
  short int l_whence ; 
  __off_t l_start ; 
  __off_t l_len ; 
  __pid_t l_pid ; 
}
; 
extern int fcntl (int __fd , int __cmd , ... ) ; 
extern int open (__const char * __file , int __oflag , ... ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
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
extern int kill (__pid_t __pid , int __sig ) __attribute__ ((__nothrow__ ) ) ; 
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
extern int sigemptyset (sigset_t * __set ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern int sigaddset (sigset_t * __set , int __signo ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern int sigdelset (sigset_t * __set , int __signo ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern int sigismember (__const sigset_t * __set , int __signo ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
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
extern int sigprocmask (int __how , __const sigset_t * __restrict __set , sigset_t * __restrict __oset ) __attribute__ ((__nothrow__ ) ) ; 
extern int sigsuspend (__const sigset_t * __set ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern int sigaction (int __sig , __const struct sigaction * __restrict __act , struct sigaction * __restrict __oact ) __attribute__ ((__nothrow__ ) ) ; 
extern int sigpending (sigset_t * __set ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
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
typedef union {
  union wait * __uptr ; 
  int * __iptr ; 
}
__WAIT_STATUS __attribute__ ((__transparent_union__ ) ) ; 
union wait {
  int w_status ; 
  struct {
    unsigned int __w_termsig : 7 ; 
    unsigned int __w_coredump : 1 ; 
    unsigned int __w_retcode : 8 ; 
    unsigned int : 16 ; 
  }
  __wait_terminated ; 
  struct {
    unsigned int __w_stopval : 8 ; 
    unsigned int __w_stopsig : 8 ; 
    unsigned int : 16 ; 
  }
  __wait_stopped ; 
}
; 
typedef enum {
  P_ALL , P_PID , P_PGID }
idtype_t ; 
extern __pid_t wait (__WAIT_STATUS __stat_loc ) ; 
extern __pid_t waitpid (__pid_t __pid , int * __stat_loc , int __options ) ; 
struct rusage ; 
struct rusage ; 
extern int * __errno_location (void ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__const__ ) ) ; 
extern double exp (double __x ) __attribute__ ((__nothrow__ ) ) ; 
extern double fmod (double __x , double __y ) __attribute__ ((__nothrow__ ) ) ; 
extern double significand (double __x ) __attribute__ ((__nothrow__ ) ) ; 
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
typedef struct {
  Scheme_Type type ; 
  FILE * f ; 
}
Scheme_Input_File ; 
typedef struct {
  Scheme_Type type ; 
  FILE * f ; 
}
Scheme_Output_File ; 
typedef struct System_Child {
  Scheme_Type type ; 
  pid_t id ; 
  short done ; 
  int status ; 
  struct System_Child * next ; 
}
System_Child ; 
System_Child * scheme_system_children ; 
typedef struct Scheme_Subprocess {
  Scheme_Object so ; 
  void * handle ; 
  int pid ; 
}
Scheme_Subprocess ; 
struct stat {
  __dev_t st_dev ; 
  __ino_t st_ino ; 
  __nlink_t st_nlink ; 
  __mode_t st_mode ; 
  __uid_t st_uid ; 
  __gid_t st_gid ; 
  int pad0 ; 
  __dev_t st_rdev ; 
  __off_t st_size ; 
  __blksize_t st_blksize ; 
  __blkcnt_t st_blocks ; 
  struct timespec st_atim ; 
  struct timespec st_mtim ; 
  struct timespec st_ctim ; 
  long int __unused [3 ] ; 
}
; 
extern int stat (__const char * __restrict __file , struct stat * __restrict __buf ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern int fstat (int __fd , struct stat * __buf ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (2 ) ) ) ; 
extern int lstat (__const char * __restrict __file , struct stat * __restrict __buf ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern int mknod (__const char * __path , __mode_t __mode , __dev_t __dev ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern int __fxstat (int __ver , int __fildes , struct stat * __stat_buf ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (3 ) ) ) ; 
extern int __xstat (int __ver , __const char * __filename , struct stat * __stat_buf ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (2 , 3 ) ) ) ; 
extern int __lxstat (int __ver , __const char * __filename , struct stat * __stat_buf ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (2 , 3 ) ) ) ; 
extern int __xmknod (int __ver , __const char * __path , __mode_t __mode , __dev_t * __dev ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (2 , 4 ) ) ) ; 
extern __inline__ int __attribute__ ((__nothrow__ ) ) stat (__const char * __path , struct stat * __statbuf ) {
  return __xstat (1 , __path , __statbuf ) ; 
}
extern __inline__ int __attribute__ ((__nothrow__ ) ) lstat (__const char * __path , struct stat * __statbuf ) {
  return __lxstat (1 , __path , __statbuf ) ; 
}
extern __inline__ int __attribute__ ((__nothrow__ ) ) fstat (int __fd , struct stat * __statbuf ) {
  return __fxstat (1 , __fd , __statbuf ) ; 
}
extern __inline__ int __attribute__ ((__nothrow__ ) ) mknod (__const char * __path , __mode_t __mode , __dev_t __dev ) {
  return __xmknod (0 , __path , __mode , & __dev ) ; 
}
typedef struct Scheme_FD {
  Scheme_Type type ; 
  long fd ; 
  long bufcount , buffpos ; 
  char flushing , regfile , flush ; 
  char textmode ; 
  unsigned char * buffer ; 
  int * refcount ; 
}
Scheme_FD ; 
Scheme_Object scheme_eof [1 ] ; 
Scheme_Object * scheme_orig_stdout_port ; 
Scheme_Object * scheme_orig_stderr_port ; 
Scheme_Object * scheme_orig_stdin_port ; 
Scheme_Object * (* scheme_make_stdin ) (void ) = ((void * ) 0 ) ; 
Scheme_Object * (* scheme_make_stdout ) (void ) = ((void * ) 0 ) ; 
Scheme_Object * (* scheme_make_stderr ) (void ) = ((void * ) 0 ) ; 
int scheme_file_open_count ; 
int scheme_binary_mode_stdio ; 
void scheme_set_binary_mode_stdio (int v ) {
  /* No conversion */
  scheme_binary_mode_stdio = v ; 
}
static int special_is_ok ; 
static Scheme_Object * fd_input_port_type ; 
static Scheme_Object * file_input_port_type ; 
Scheme_Object * scheme_string_input_port_type ; 
Scheme_Object * scheme_tcp_input_port_type ; 
Scheme_Object * scheme_tcp_output_port_type ; 
static Scheme_Object * fd_output_port_type ; 
static Scheme_Object * file_output_port_type ; 
Scheme_Object * scheme_string_output_port_type ; 
Scheme_Object * scheme_user_input_port_type ; 
Scheme_Object * scheme_user_output_port_type ; 
Scheme_Object * scheme_pipe_read_port_type ; 
Scheme_Object * scheme_pipe_write_port_type ; 
Scheme_Object * scheme_null_output_port_type ; 
Scheme_Object * scheme_redirect_output_port_type ; 
int scheme_force_port_closed ; 
static int external_event_fd , put_external_event_fd , event_fd_set ; 
static void register_port_wait () ; 
static long flush_fd (Scheme_Output_Port * op , const char * volatile bufstr , volatile unsigned long buflen , volatile unsigned long offset , int immediate_only , int enable_break ) ; 
static void flush_if_output_fds (Scheme_Object * o , Scheme_Close_Custodian_Client * f , void * data ) ; 
static Scheme_Object * subprocess (int c , Scheme_Object * args [] ) ; 
static Scheme_Object * subprocess_status (int c , Scheme_Object * args [] ) ; 
static Scheme_Object * subprocess_kill (int c , Scheme_Object * args [] ) ; 
static Scheme_Object * subprocess_pid (int c , Scheme_Object * args [] ) ; 
static Scheme_Object * subprocess_p (int c , Scheme_Object * args [] ) ; 
static Scheme_Object * subprocess_wait (int c , Scheme_Object * args [] ) ; 
static Scheme_Object * sch_shell_execute (int c , Scheme_Object * args [] ) ; 
static void register_subprocess_wait () ; 
typedef struct Scheme_Read_Write_Evt {
  Scheme_Object so ; 
  Scheme_Object * port ; 
  Scheme_Object * v ; 
  char * str ; 
  long start , size ; 
}
Scheme_Read_Write_Evt ; 
static int rw_evt_ready (Scheme_Object * rww , Scheme_Schedule_Info * sinfo ) ; 
static void rw_evt_wakeup (Scheme_Object * rww , void * fds ) ; 
static int progress_evt_ready (Scheme_Object * rww , Scheme_Schedule_Info * sinfo ) ; 
static Scheme_Object * _scheme_make_named_file_input_port (FILE * fp , Scheme_Object * name , int regfile ) ; 
static void default_sleep (float v , void * fds ) ; 
static void register_traversers (void ) ; 
static Scheme_Object * make_fd_input_port (int fd , Scheme_Object * name , int regfile , int textmode , int * refcount ) ; 
static Scheme_Object * make_fd_output_port (int fd , Scheme_Object * name , int regfile , int textmode , int read_too ) ; 
static void force_close_output_port (Scheme_Object * port ) ; 
static void force_close_input_port (Scheme_Object * port ) ; 
static Scheme_Object * text_symbol , * binary_symbol ; 
static Scheme_Object * append_symbol , * error_symbol , * update_symbol ; 
static Scheme_Object * replace_symbol , * truncate_symbol , * truncate_replace_symbol ; 
Scheme_Object * scheme_none_symbol , * scheme_line_symbol , * scheme_block_symbol ; 
static Scheme_Object * exact_symbol ; 
static char * read_string_byte_buffer ; 
void scheme_init_port (Scheme_Env * env ) {
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
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(env, 0)));
# define XfOrM2_COUNT (1)
# define SETUP_XfOrM2(x) SETUP(XfOrM2_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM2(_), register_traversers () ); 
  FUNCCALL(SETUP_XfOrM2(_), scheme_register_static ((void * ) & text_symbol , sizeof (text_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & binary_symbol , sizeof (binary_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & append_symbol , sizeof (append_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & error_symbol , sizeof (error_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & replace_symbol , sizeof (replace_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & truncate_symbol , sizeof (truncate_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & truncate_replace_symbol , sizeof (truncate_replace_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & update_symbol , sizeof (update_symbol ) ) ); 
  text_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("text" ) ); 
  binary_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("binary" ) ); 
  append_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("append" ) ); 
  error_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("error" ) ); 
  replace_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("replace" ) ); 
  truncate_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("truncate" ) ); 
  truncate_replace_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("truncate/replace" ) ); 
  update_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("update" ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_none_symbol , sizeof (scheme_none_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_line_symbol , sizeof (scheme_line_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_block_symbol , sizeof (scheme_block_symbol ) ) ); 
  scheme_none_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("none" ) ); 
  scheme_line_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("line" ) ); 
  scheme_block_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("block" ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & exact_symbol , sizeof (exact_symbol ) ) ); 
  exact_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("exact" ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_orig_stdout_port , sizeof (scheme_orig_stdout_port ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_orig_stderr_port , sizeof (scheme_orig_stderr_port ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_orig_stdin_port , sizeof (scheme_orig_stdin_port ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & fd_input_port_type , sizeof (fd_input_port_type ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & fd_output_port_type , sizeof (fd_output_port_type ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & file_input_port_type , sizeof (file_input_port_type ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_string_input_port_type , sizeof (scheme_string_input_port_type ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_tcp_input_port_type , sizeof (scheme_tcp_input_port_type ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_tcp_output_port_type , sizeof (scheme_tcp_output_port_type ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & file_output_port_type , sizeof (file_output_port_type ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_string_output_port_type , sizeof (scheme_string_output_port_type ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_user_input_port_type , sizeof (scheme_user_input_port_type ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_user_output_port_type , sizeof (scheme_user_output_port_type ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_pipe_read_port_type , sizeof (scheme_pipe_read_port_type ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_pipe_write_port_type , sizeof (scheme_pipe_write_port_type ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_null_output_port_type , sizeof (scheme_null_output_port_type ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_redirect_output_port_type , sizeof (scheme_redirect_output_port_type ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_system_children , sizeof (scheme_system_children ) ) ); 
  signal (13 , ((__sighandler_t ) 1 ) ) ; 
  if (! scheme_sleep )
    scheme_sleep = default_sleep ; 
  scheme_eof -> type = scheme_eof_type ; 
  scheme_string_input_port_type = FUNCCALL(SETUP_XfOrM2(_), scheme_make_port_type ("<string-input-port>" ) ); 
  scheme_string_output_port_type = FUNCCALL_AGAIN(scheme_make_port_type ("<string-output-port>" ) ); 
  fd_input_port_type = FUNCCALL_AGAIN(scheme_make_port_type ("<stream-input-port>" ) ); 
  fd_output_port_type = FUNCCALL_AGAIN(scheme_make_port_type ("<stream-output-port>" ) ); 
  file_input_port_type = FUNCCALL_AGAIN(scheme_make_port_type ("<file-input-port>" ) ); 
  file_output_port_type = FUNCCALL_AGAIN(scheme_make_port_type ("<file-output-port>" ) ); 
  scheme_user_input_port_type = FUNCCALL_AGAIN(scheme_make_port_type ("<user-input-port>" ) ); 
  scheme_user_output_port_type = FUNCCALL_AGAIN(scheme_make_port_type ("<user-output-port>" ) ); 
  scheme_pipe_read_port_type = FUNCCALL_AGAIN(scheme_make_port_type ("<pipe-input-port>" ) ); 
  scheme_pipe_write_port_type = FUNCCALL_AGAIN(scheme_make_port_type ("<pipe-output-port>" ) ); 
  scheme_tcp_input_port_type = FUNCCALL_AGAIN(scheme_make_port_type ("<tcp-input-port>" ) ); 
  scheme_tcp_output_port_type = FUNCCALL_AGAIN(scheme_make_port_type ("<tcp-output-port>" ) ); 
  scheme_null_output_port_type = FUNCCALL_AGAIN(scheme_make_port_type ("<null-output-port>" ) ); 
  scheme_redirect_output_port_type = FUNCCALL_AGAIN(scheme_make_port_type ("<redirect-output-port>" ) ); 
  scheme_orig_stdin_port = (scheme_make_stdin ? FUNCCALL(SETUP_XfOrM2(_), scheme_make_stdin () ): (__funcarg15 = FUNCCALL(SETUP_XfOrM2(_), scheme_intern_symbol ("stdin" ) ), FUNCCALL_AGAIN(make_fd_input_port (0 , __funcarg15 , 0 , 0 , ((void * ) 0 ) ) )) ) ; 
  scheme_orig_stdout_port = (scheme_make_stdout ? FUNCCALL(SETUP_XfOrM2(_), scheme_make_stdout () ): (__funcarg14 = FUNCCALL(SETUP_XfOrM2(_), scheme_intern_symbol ("stdout" ) ), FUNCCALL_AGAIN(make_fd_output_port (1 , __funcarg14 , 0 , 0 , 0 ) )) ) ; 
  scheme_orig_stderr_port = (scheme_make_stderr ? FUNCCALL(SETUP_XfOrM2(_), scheme_make_stderr () ): (__funcarg13 = FUNCCALL(SETUP_XfOrM2(_), scheme_intern_symbol ("stderr" ) ), FUNCCALL_AGAIN(make_fd_output_port (2 , __funcarg13 , 0 , 0 , 0 ) )) ) ; 
  FUNCCALL(SETUP_XfOrM2(_), scheme_add_atexit_closer (flush_if_output_fds ) ); 
  {
    int fds [2 ] ; 
#   define XfOrM3_COUNT (0+XfOrM2_COUNT)
#   define SETUP_XfOrM3(x) SETUP_XfOrM2(x)
    if (! FUNCCALL(SETUP_XfOrM3(_), pipe (fds ) )) {
      external_event_fd = fds [0 ] ; 
      put_external_event_fd = fds [1 ] ; 
      fcntl (external_event_fd , 4 , 2048 ) ; 
      fcntl (put_external_event_fd , 4 , 2048 ) ; 
    }
  }
  FUNCCALL(SETUP_XfOrM2(_), scheme_init_port_config () ); 
  FUNCCALL(SETUP_XfOrM2(_), register_port_wait () ); 
  (__funcarg12 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_everything (subprocess , 0 , "subprocess" , 4 , - 1 , 0 , 4 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("subprocess" , __funcarg12 , env ) )) ; 
  (__funcarg11 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (subprocess_status , "subprocess-status" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("subprocess-status" , __funcarg11 , env ) )) ; 
  (__funcarg10 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (subprocess_kill , "subprocess-kill" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("subprocess-kill" , __funcarg10 , env ) )) ; 
  (__funcarg9 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (subprocess_pid , "subprocess-pid" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("subprocess-pid" , __funcarg9 , env ) )) ; 
  (__funcarg8 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (subprocess_p , "subprocess?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("subprocess?" , __funcarg8 , env ) )) ; 
  (__funcarg7 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (subprocess_wait , "subprocess-wait" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("subprocess-wait" , __funcarg7 , env ) )) ; 
  FUNCCALL_AGAIN(register_subprocess_wait () ); 
  (__funcarg6 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (sch_shell_execute , "shell-execute" , 5 , 5 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("shell-execute" , __funcarg6 , env ) )) ; 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & read_string_byte_buffer , sizeof (read_string_byte_buffer ) ) ); 
  FUNCCALL_EMPTY(scheme_add_evt (scheme_progress_evt_type , (Scheme_Ready_Fun ) progress_evt_ready , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ); 
  FUNCCALL_EMPTY(scheme_add_evt (scheme_write_evt_type , (Scheme_Ready_Fun ) rw_evt_ready , rw_evt_wakeup , ((void * ) 0 ) , 1 ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_init_port_config (void ) {
  Scheme_Config * config ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(config, 0)));
# define XfOrM5_COUNT (1)
# define SETUP_XfOrM5(x) SETUP(XfOrM5_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  config = NULLED_OUT ; 
  config = FUNCCALL(SETUP_XfOrM5(_), scheme_current_config () ); 
  FUNCCALL_AGAIN(scheme_set_param (config , MZCONFIG_INPUT_PORT , scheme_orig_stdin_port ) ); 
  FUNCCALL_AGAIN(scheme_set_param (config , MZCONFIG_OUTPUT_PORT , scheme_orig_stdout_port ) ); 
  FUNCCALL_EMPTY(scheme_set_param (config , MZCONFIG_ERROR_PORT , scheme_orig_stderr_port ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_eof (void ) {
  /* No conversion */
  return scheme_eof ; 
}
static int dynamic_fd_size ; 
void * scheme_alloc_fdset_array (int count , int permanent ) {
  if (! dynamic_fd_size ) {
    dynamic_fd_size = getdtablesize () ; 
    dynamic_fd_size = (dynamic_fd_size + 7 ) >> 3 ; 
    if (dynamic_fd_size % sizeof (void * ) )
      dynamic_fd_size += sizeof (void * ) - (dynamic_fd_size % sizeof (void * ) ) ; 
  }
  if (permanent )
    return scheme_malloc_eternal (count * dynamic_fd_size ) ; 
  else return GC_malloc_atomic (count * dynamic_fd_size ) ; 
}
void * scheme_init_fdset_array (void * fdarray , int count ) {
  /* No conversion */
  return fdarray ; 
}
void * scheme_get_fdset (void * fdarray , int pos ) {
  /* No conversion */
  return ((char * ) fdarray ) + (pos * dynamic_fd_size ) ; 
}
void scheme_fdzero (void * fd ) {
  /* No conversion */
  memset (fd , 0 , dynamic_fd_size ) ; 
}
void scheme_fdclr (void * fd , int n ) {
  /* No conversion */
  (((((fd_set * ) fd ) ) -> __fds_bits ) [(((unsigned ) n ) / (8 * sizeof (__fd_mask ) ) ) ] &= ~ ((__fd_mask ) 1 << (((unsigned ) n ) % (8 * sizeof (__fd_mask ) ) ) ) ) ; 
}
void scheme_fdset (void * fd , int n ) {
  /* No conversion */
  (((((fd_set * ) fd ) ) -> __fds_bits ) [((n ) / (8 * sizeof (__fd_mask ) ) ) ] |= ((__fd_mask ) 1 << ((n ) % (8 * sizeof (__fd_mask ) ) ) ) ) ; 
}
int scheme_fdisset (void * fd , int n ) {
  /* No conversion */
  return ((((((fd_set * ) fd ) ) -> __fds_bits ) [((n ) / (8 * sizeof (__fd_mask ) ) ) ] & ((__fd_mask ) 1 << ((n ) % (8 * sizeof (__fd_mask ) ) ) ) ) != 0 ) ; 
}
void scheme_add_fd_handle (void * h , void * fds , int repost ) {
  /* No conversion */
}
void scheme_add_fd_nosleep (void * fds ) {
  /* No conversion */
}
void scheme_add_fd_eventmask (void * fds , int mask ) {
  /* No conversion */
}
Scheme_Object * scheme_make_port_type (const char * name ) {
  /* No conversion */
  return scheme_make_symbol (name ) ; 
}
static void init_port_locations (Scheme_Port * ip ) {
  int cl ; 
  Scheme_Config * __funcarg16 = NULLED_OUT ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(ip, 0)));
# define XfOrM17_COUNT (1)
# define SETUP_XfOrM17(x) SETUP(XfOrM17_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ip -> position = 0 ; 
  ip -> readpos = 0 ; 
  ip -> lineNumber = 1 ; 
  ip -> oldColumn = 0 ; 
  ip -> column = 0 ; 
  ip -> charsSinceNewline = 1 ; 
  cl = (! ((((__funcarg16 = FUNCCALL(SETUP_XfOrM17(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg16 , MZCONFIG_PORT_COUNT_LINES ) )) ) ) == (scheme_false ) ) ) ; 
  ip -> count_lines = cl ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Input_Port * scheme_make_input_port (Scheme_Object * subtype , void * data , Scheme_Object * name , Scheme_Get_String_Fun get_string_fun , Scheme_Peek_String_Fun peek_string_fun , Scheme_Progress_Evt_Fun progress_evt_fun , Scheme_Peeked_Read_Fun peeked_read_fun , Scheme_In_Ready_Fun byte_ready_fun , Scheme_Close_Input_Fun close_fun , Scheme_Need_Wakeup_Input_Fun need_wakeup_fun , int must_close ) {
  Scheme_Input_Port * ip ; 
  DECL_RET_SAVE (Scheme_Input_Port * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(data, 0), PUSH(subtype, 1), PUSH(ip, 2), PUSH(name, 3)));
# define XfOrM18_COUNT (4)
# define SETUP_XfOrM18(x) SETUP(XfOrM18_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  ip = NULLED_OUT ; 
  ip = ((Scheme_Input_Port * ) FUNCCALL(SETUP_XfOrM18(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Input_Port ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  ip -> p . so . type = scheme_input_port_type ; 
  ip -> sub_type = subtype ; 
  ip -> port_data = data ; 
  ip -> get_string_fun = get_string_fun ; 
  ip -> peek_string_fun = peek_string_fun ; 
  ip -> progress_evt_fun = progress_evt_fun ; 
  ip -> peeked_read_fun = peeked_read_fun ; 
  ip -> byte_ready_fun = byte_ready_fun ; 
  ip -> need_wakeup_fun = need_wakeup_fun ; 
  ip -> close_fun = close_fun ; 
  ip -> name = name ; 
  ip -> ungotten_count = 0 ; 
  ip -> closed = 0 ; 
  ip -> read_handler = ((void * ) 0 ) ; 
  FUNCCALL(SETUP_XfOrM18(_), init_port_locations ((Scheme_Port * ) ip ) ); 
  if (progress_evt_fun == scheme_progress_evt_via_get )
    ip -> unless_cache = scheme_false ; 
  if (must_close ) {
    Scheme_Custodian_Reference * mref ; 
    BLOCK_SETUP((PUSH(mref, 0+XfOrM18_COUNT)));
#   define XfOrM19_COUNT (1+XfOrM18_COUNT)
#   define SETUP_XfOrM19(x) SETUP(XfOrM19_COUNT)
    mref = NULLED_OUT ; 
    mref = FUNCCALL(SETUP_XfOrM19(_), scheme_add_managed (((void * ) 0 ) , (Scheme_Object * ) ip , (Scheme_Close_Custodian_Client * ) force_close_input_port , ((void * ) 0 ) , must_close ) ); 
    ip -> mref = mref ; 
  }
  else ip -> mref = ((void * ) 0 ) ; 
  RET_VALUE_START ((ip ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_set_port_location_fun (Scheme_Port * port , Scheme_Location_Fun location_fun ) {
  /* No conversion */
  port -> location_fun = location_fun ; 
}
void scheme_set_port_count_lines_fun (Scheme_Port * port , Scheme_Count_Lines_Fun count_lines_fun ) {
  /* No conversion */
  port -> count_lines_fun = count_lines_fun ; 
}
static int evt_input_port_p (Scheme_Object * p ) {
  /* No conversion */
  return 1 ; 
}
Scheme_Output_Port * scheme_make_output_port (Scheme_Object * subtype , void * data , Scheme_Object * name , Scheme_Write_String_Evt_Fun write_string_evt_fun , Scheme_Write_String_Fun write_string_fun , Scheme_Out_Ready_Fun ready_fun , Scheme_Close_Output_Fun close_fun , Scheme_Need_Wakeup_Output_Fun need_wakeup_fun , Scheme_Write_Special_Evt_Fun write_special_evt_fun , Scheme_Write_Special_Fun write_special_fun , int must_close ) {
  Scheme_Output_Port * op ; 
  DECL_RET_SAVE (Scheme_Output_Port * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(data, 0), PUSH(subtype, 1), PUSH(op, 2), PUSH(name, 3)));
# define XfOrM23_COUNT (4)
# define SETUP_XfOrM23(x) SETUP(XfOrM23_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  op = NULLED_OUT ; 
  op = ((Scheme_Output_Port * ) FUNCCALL(SETUP_XfOrM23(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Output_Port ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  op -> p . so . type = scheme_output_port_type ; 
  op -> sub_type = subtype ; 
  op -> port_data = data ; 
  op -> name = name ; 
  op -> write_string_evt_fun = write_string_evt_fun ; 
  op -> write_string_fun = write_string_fun ; 
  op -> close_fun = close_fun ; 
  op -> ready_fun = ready_fun ; 
  op -> need_wakeup_fun = need_wakeup_fun ; 
  op -> write_special_evt_fun = write_special_evt_fun ; 
  op -> write_special_fun = write_special_fun ; 
  op -> closed = 0 ; 
  op -> display_handler = ((void * ) 0 ) ; 
  op -> write_handler = ((void * ) 0 ) ; 
  op -> print_handler = ((void * ) 0 ) ; 
  FUNCCALL(SETUP_XfOrM23(_), init_port_locations ((Scheme_Port * ) op ) ); 
  if (must_close ) {
    Scheme_Custodian_Reference * mref ; 
    BLOCK_SETUP((PUSH(mref, 0+XfOrM23_COUNT)));
#   define XfOrM24_COUNT (1+XfOrM23_COUNT)
#   define SETUP_XfOrM24(x) SETUP(XfOrM24_COUNT)
    mref = NULLED_OUT ; 
    mref = FUNCCALL(SETUP_XfOrM24(_), scheme_add_managed (((void * ) 0 ) , (Scheme_Object * ) op , (Scheme_Close_Custodian_Client * ) force_close_output_port , ((void * ) 0 ) , must_close ) ); 
    op -> mref = mref ; 
  }
  else op -> mref = ((void * ) 0 ) ; 
  RET_VALUE_START (op ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int evt_output_port_p (Scheme_Object * p ) {
  /* No conversion */
  return 1 ; 
}
static int output_ready (Scheme_Object * port , Scheme_Schedule_Info * sinfo ) {
  Scheme_Output_Port * op ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(op, 0), PUSH(sinfo, 1)));
# define XfOrM26_COUNT (2)
# define SETUP_XfOrM26(x) SETUP(XfOrM26_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  op = NULLED_OUT ; 
  op = FUNCCALL(SETUP_XfOrM26(_), scheme_output_port_record (port ) ); 
  if (op -> closed )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  if (((scheme_user_output_port_type ) == (op -> sub_type ) ) ) {
#   define XfOrM28_COUNT (0+XfOrM26_COUNT)
#   define SETUP_XfOrM28(x) SETUP_XfOrM26(x)
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_user_port_write_probably_ready (op , sinfo ) )) RET_VALUE_EMPTY_END ; 
  }
  if (op -> ready_fun ) {
    Scheme_Out_Ready_Fun rf ; 
#   define XfOrM27_COUNT (0+XfOrM26_COUNT)
#   define SETUP_XfOrM27(x) SETUP_XfOrM26(x)
    rf = op -> ready_fun ; 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(rf (op ) )) RET_VALUE_EMPTY_END ; 
  }
  RET_VALUE_START (1 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void output_need_wakeup (Scheme_Object * port , void * fds ) {
  Scheme_Output_Port * op ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(fds, 0), PUSH(op, 1)));
# define XfOrM29_COUNT (2)
# define SETUP_XfOrM29(x) SETUP(XfOrM29_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  op = NULLED_OUT ; 
  op = FUNCCALL(SETUP_XfOrM29(_), scheme_output_port_record (port ) ); 
  if (op -> need_wakeup_fun ) {
    Scheme_Need_Wakeup_Output_Fun f ; 
#   define XfOrM30_COUNT (0+XfOrM29_COUNT)
#   define SETUP_XfOrM30(x) SETUP_XfOrM29(x)
    f = op -> need_wakeup_fun ; 
    FUNCCALL_EMPTY(f (op , fds ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_byte_ready_or_user_port_ready (Scheme_Object * p , Scheme_Schedule_Info * sinfo ) {
  Scheme_Input_Port * ip ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(sinfo, 0), PUSH(p, 1), PUSH(ip, 2)));
# define XfOrM31_COUNT (3)
# define SETUP_XfOrM31(x) SETUP(XfOrM31_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ip = NULLED_OUT ; 
  ip = FUNCCALL(SETUP_XfOrM31(_), scheme_input_port_record (p ) ); 
  if (ip -> closed )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  if (((scheme_user_input_port_type ) == (ip -> sub_type ) ) ) {
#   define XfOrM32_COUNT (0+XfOrM31_COUNT)
#   define SETUP_XfOrM32(x) SETUP_XfOrM31(x)
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_user_port_byte_probably_ready (ip , sinfo ) )) RET_VALUE_EMPTY_END ; 
  }
  else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_byte_ready (p ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void register_port_wait () {
  /* No conversion */
  scheme_add_evt (scheme_input_port_type , (Scheme_Ready_Fun ) scheme_byte_ready_or_user_port_ready , scheme_need_wakeup , evt_input_port_p , 1 ) ; 
  scheme_add_evt (scheme_output_port_type , (Scheme_Ready_Fun ) output_ready , output_need_wakeup , evt_output_port_p , 1 ) ; 
}
__xform_nongcing__ static int pipe_char_count (Scheme_Object * p ) {
  /* No conversion */
  if (p ) {
    Scheme_Pipe * pipe ; 
    Scheme_Input_Port * ip ; 
    ip = (Scheme_Input_Port * ) p ; 
    pipe = (Scheme_Pipe * ) ip -> port_data ; 
    if (pipe -> bufstart <= pipe -> bufend )
      return pipe -> bufend - pipe -> bufstart ; 
    else return (pipe -> buflen - pipe -> bufstart ) + pipe -> bufend ; 
  }
  else return 0 ; 
}
static void post_progress (Scheme_Input_Port * ip ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(ip, 0)));
# define XfOrM36_COUNT (1)
# define SETUP_XfOrM36(x) SETUP(XfOrM36_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM36(_), scheme_post_sema_all (ip -> progress_evt ) ); 
  ip -> progress_evt = ((void * ) 0 ) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
__xform_nongcing__ static void inc_pos (Scheme_Port * ip , int a ) {
  /* No conversion */
  ip -> column += a ; 
  ip -> readpos += a ; 
  ip -> charsSinceNewline += a ; 
  ip -> utf8state = 0 ; 
}
static Scheme_Object * quick_plus (Scheme_Object * s , long v ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(s, 0)));
# define XfOrM38_COUNT (1)
# define SETUP_XfOrM38(x) SETUP(XfOrM38_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if ((((long ) (s ) ) & 0x1 ) ) {
    int k ; 
    k = (((long ) (s ) ) >> 1 ) ; 
    if ((k < 0x1000000 ) && (v < 0x1000000 ) ) {
      k += v ; 
      RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (k ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
    }
  }
  FUNCCALL(SETUP_XfOrM38(_), scheme_start_atomic () ); 
  s = FUNCCALL(SETUP_XfOrM38(_), scheme_bin_plus (s , ((Scheme_Object * ) (void * ) (long ) ((((long ) (v ) ) << 1 ) | 0x1 ) ) ) ); 
  FUNCCALL_AGAIN(scheme_end_atomic_no_swap () ); 
  RET_VALUE_START (s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
__xform_nongcing__ static void do_count_lines (Scheme_Port * ip , const char * buffer , long offset , long got ) {
  /* No conversion */
  long i ; 
  int c , degot = 0 ; 
  ; 
  ; 
  ; 
  ip -> oldColumn = ip -> column ; 
  ip -> readpos += got ; 
  for (i = got , c = 0 ; i -- ; c ++ ) {
    if (buffer [offset + i ] == '\n' || buffer [offset + i ] == '\r' ) {
      break ; 
    }
  }
  if (i >= 0 ) {
    int state = ip -> utf8state ; 
    int n ; 
    degot += ((state >> 3 ) & 0x7 ) ; 
    n = scheme_utf8_decode_count ((const unsigned char * ) buffer , offset , offset + i + 1 , & state , 0 , '?' ) ; 
    degot += (i + 1 - n ) ; 
    ip -> utf8state = 0 ; 
  }
  if (i >= 0 ) {
    int n = 0 ; 
    ip -> charsSinceNewline = c + 1 ; 
    i ++ ; 
    while (i -- ) {
      if (buffer [offset + i ] == '\n' ) {
        if (! (i && (buffer [offset + i - 1 ] == '\r' ) ) && ! (! i && ip -> was_cr ) ) {
          n ++ ; 
        }
        else degot ++ ; 
      }
      else if (buffer [offset + i ] == '\r' ) {
        n ++ ; 
      }
    }
    ; 
    ip -> lineNumber += n ; 
    ip -> was_cr = (buffer [offset + got - 1 ] == '\r' ) ; 
    ip -> column = 0 ; 
  }
  else {
    ip -> charsSinceNewline += c ; 
  }
  {
    int col = ip -> column , n ; 
    int prev_i = got - c ; 
    int state = ip -> utf8state ; 
    n = ((state >> 3 ) & 0x7 ) ; 
    degot += n ; 
    col -= n ; 
    for (i = prev_i ; i < got ; i ++ ) {
      if (buffer [offset + i ] == '\t' ) {
        n = scheme_utf8_decode_count ((const unsigned char * ) buffer , offset + prev_i , offset + i , & state , 0 , '?' ) ; 
        degot += ((i - prev_i ) - n ) ; 
        col += n ; 
        col = col - (col & 0x7 ) + 8 ; 
        prev_i = i + 1 ; 
      }
    }
    if (prev_i < i ) {
      n = scheme_utf8_decode_count ((const unsigned char * ) buffer , offset + prev_i , offset + i , & state , 1 , '?' ) ; 
      n += ((state >> 3 ) & 0x7 ) ; 
      col += n ; 
      degot += ((i - prev_i ) - n ) ; 
    }
    ip -> column = col ; 
    ip -> utf8state = state ; 
  }
  ip -> readpos -= degot ; 
  ; 
  ; 
  ; 
}
long scheme_get_byte_string_unless (const char * who , Scheme_Object * port , char * buffer , long offset , long size , int only_avail , int peek , Scheme_Object * peek_skip , Scheme_Object * unless_evt ) {
  Scheme_Input_Port * ip ; 
  long got = 0 , total_got = 0 , gc ; 
  int special_ok = special_is_ok , check_special ; 
  Scheme_Get_String_Fun gs ; 
  Scheme_Peek_String_Fun ps ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(port, 0), PUSH(unless_evt, 1), PUSH(buffer, 2), PUSH(peek_skip, 3), PUSH(ip, 4), PUSH(who, 5)));
# define XfOrM63_COUNT (6)
# define SETUP_XfOrM63(x) SETUP(XfOrM63_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  ip = NULLED_OUT ; 
  special_is_ok = 0 ; 
  if (! size ) {
#   define XfOrM192_COUNT (0+XfOrM63_COUNT)
#   define SETUP_XfOrM192(x) SETUP_XfOrM63(x)
    if (only_avail == - 1 ) {
#     define XfOrM193_COUNT (0+XfOrM192_COUNT)
#     define SETUP_XfOrM193(x) SETUP_XfOrM192(x)
      if (scheme_current_thread -> external_break ) {
#       define XfOrM194_COUNT (0+XfOrM193_COUNT)
#       define SETUP_XfOrM194(x) SETUP_XfOrM193(x)
        FUNCCALL(SETUP_XfOrM194(_), scheme_thread_block_enable_break (0.0 , 1 ) ); 
        scheme_current_thread -> ran_some = 1 ; 
      }
    }
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  if (! peek_skip )
    peek_skip = ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
  ip = FUNCCALL(SETUP_XfOrM63(_), scheme_input_port_record (port ) ); 
  gs = ip -> get_string_fun ; 
  ps = ip -> peek_string_fun ; 
  while (1 ) {
#   define XfOrM128_COUNT (0+XfOrM63_COUNT)
#   define SETUP_XfOrM128(x) SETUP_XfOrM63(x)
    {
#     define XfOrM190_COUNT (0+XfOrM128_COUNT)
#     define SETUP_XfOrM190(x) SETUP_XfOrM128(x)
      if ((scheme_fuel_counter ) <= 0 ) {
#       define XfOrM191_COUNT (0+XfOrM190_COUNT)
#       define SETUP_XfOrM191(x) SETUP_XfOrM190(x)
        FUNCCALL(SETUP_XfOrM191(_), scheme_out_of_fuel () ); 
      }
    }
    ; 
    if (ip -> closed )
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL , "%s: " "input" " port is closed" , who ) ); 
    ; 
    if (ip -> input_lock )
      FUNCCALL(SETUP_XfOrM128(_), scheme_wait_input_allowed (ip , only_avail ) ); 
    if (only_avail == - 1 ) {
#     define XfOrM188_COUNT (0+XfOrM128_COUNT)
#     define SETUP_XfOrM188(x) SETUP_XfOrM128(x)
      if (scheme_current_thread -> external_break ) {
#       define XfOrM189_COUNT (0+XfOrM188_COUNT)
#       define SETUP_XfOrM189(x) SETUP_XfOrM188(x)
        FUNCCALL(SETUP_XfOrM189(_), scheme_thread_block_enable_break (0.0 , 1 ) ); 
        scheme_current_thread -> ran_some = 1 ; 
      }
    }
    if ((ip -> ungotten_count || (pipe_char_count (ip -> peeked_read ) ) ) && (! total_got || ! peek ) ) {
      long l , i ; 
      unsigned char * s ; 
      BLOCK_SETUP((PUSH(s, 0+XfOrM128_COUNT)));
#     define XfOrM179_COUNT (1+XfOrM128_COUNT)
#     define SETUP_XfOrM179(x) SETUP(XfOrM179_COUNT)
      s = NULLED_OUT ; 
      i = ip -> ungotten_count ; 
      if (peek ) {
#       define XfOrM185_COUNT (0+XfOrM179_COUNT)
#       define SETUP_XfOrM185(x) SETUP_XfOrM179(x)
        if (! (((long ) (peek_skip ) ) & 0x1 ) || (i < (((long ) (peek_skip ) ) >> 1 ) ) ) {
#         define XfOrM187_COUNT (0+XfOrM185_COUNT)
#         define SETUP_XfOrM187(x) SETUP_XfOrM185(x)
          peek_skip = FUNCCALL(SETUP_XfOrM187(_), scheme_bin_minus (peek_skip , ((Scheme_Object * ) (void * ) (long ) ((((long ) (i ) ) << 1 ) | 0x1 ) ) ) ); 
          i = 0 ; 
        }
        else {
          i -= (((long ) (peek_skip ) ) >> 1 ) ; 
          peek_skip = ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
        }
      }
      if (i < size )
        l = i ; 
      else l = size ; 
      size -= l ; 
      s = (unsigned char * ) ip -> ungotten ; 
      while (l -- ) {
        buffer [offset + got ++ ] = s [-- i ] ; 
      }
      s = ((void * ) 0 ) ; 
      if (! peek )
        ip -> ungotten_count = i ; 
      l = (pipe_char_count (ip -> peeked_read ) ) ; 
      if (size && l ) {
#       define XfOrM180_COUNT (0+XfOrM179_COUNT)
#       define SETUP_XfOrM180(x) SETUP_XfOrM179(x)
        if ((((long ) (peek_skip ) ) & 0x1 ) && (l > (((long ) (peek_skip ) ) >> 1 ) ) ) {
#         define XfOrM181_COUNT (0+XfOrM180_COUNT)
#         define SETUP_XfOrM181(x) SETUP_XfOrM180(x)
          l -= (((long ) (peek_skip ) ) >> 1 ) ; 
          if (l > size )
            l = size ; 
          if (l ) {
#           define XfOrM182_COUNT (0+XfOrM181_COUNT)
#           define SETUP_XfOrM182(x) SETUP_XfOrM181(x)
            FUNCCALL(SETUP_XfOrM182(_), scheme_get_byte_string ("depipe" , ip -> peeked_read , buffer , offset + got , l , 1 , peek , peek_skip ) ); 
            size -= l ; 
            got += l ; 
            peek_skip = ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
            if (! peek && ip -> progress_evt )
              FUNCCALL(SETUP_XfOrM182(_), post_progress (ip ) ); 
          }
        }
        else peek_skip = FUNCCALL(SETUP_XfOrM180(_), scheme_bin_minus (peek_skip , ((Scheme_Object * ) (void * ) (long ) ((((long ) (l ) ) << 1 ) | 0x1 ) ) ) ); 
      }
      check_special = (! got || peek ) ; 
    }
    else check_special = 1 ; 
    if (check_special && ip -> ungotten_special ) {
#     define XfOrM173_COUNT (0+XfOrM128_COUNT)
#     define SETUP_XfOrM173(x) SETUP_XfOrM128(x)
      if (! special_ok ) {
#       define XfOrM177_COUNT (0+XfOrM173_COUNT)
#       define SETUP_XfOrM177(x) SETUP_XfOrM173(x)
        if (! peek ) {
#         define XfOrM178_COUNT (0+XfOrM177_COUNT)
#         define SETUP_XfOrM178(x) SETUP_XfOrM177(x)
          if (ip -> progress_evt )
            FUNCCALL(SETUP_XfOrM178(_), post_progress (ip ) ); 
          ip -> ungotten_special = ((void * ) 0 ) ; 
        }
        FUNCCALL(SETUP_XfOrM177(_), scheme_bad_time_for_special (who , port ) ); 
      }
      if (! peek ) {
        ip -> special = ip -> ungotten_special ; 
        ip -> ungotten_special = ((void * ) 0 ) ; 
      }
      else {
#       define XfOrM175_COUNT (0+XfOrM173_COUNT)
#       define SETUP_XfOrM175(x) SETUP_XfOrM173(x)
        if (peek_skip != ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) )
          FUNCCALL(SETUP_XfOrM175(_), scheme_bad_time_for_special (who , port ) ); 
      }
      if (! peek ) {
#       define XfOrM174_COUNT (0+XfOrM173_COUNT)
#       define SETUP_XfOrM174(x) SETUP_XfOrM173(x)
        if (ip -> p . position >= 0 )
          ip -> p . position ++ ; 
        if (ip -> p . count_lines )
          (inc_pos ((Scheme_Port * ) ip , 1 ) ) ; 
      }
      if (! peek && ip -> progress_evt )
        FUNCCALL(SETUP_XfOrM173(_), post_progress (ip ) ); 
      RET_VALUE_START ((- 2 ) ) RET_VALUE_END ; 
    }
    if (got && ((only_avail == 1 ) || (only_avail == - 1 ) ) )
      only_avail = 2 ; 
    while (peek && ! ps && (peek_skip != ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) && ! total_got && ! got && (ip -> pending_eof < 2 ) ) {
      char * tmp ; 
      int v , pcc ; 
      long skip ; 
      Scheme_Cont_Frame_Data cframe ; 
      BLOCK_SETUP((PUSH(tmp, 0+XfOrM128_COUNT), PUSH(cframe.cache, 1+XfOrM128_COUNT)));
#     define XfOrM166_COUNT (2+XfOrM128_COUNT)
#     define SETUP_XfOrM166(x) SETUP(XfOrM166_COUNT)
      tmp = NULLED_OUT ; 
      cframe.cache = NULLED_OUT ; 
      if ((((long ) (peek_skip ) ) & 0x1 ) ) {
        skip = (((long ) (peek_skip ) ) >> 1 ) ; 
        if (skip > 65536 )
          skip = 65536 ; 
      }
      else skip = 65536 ; 
      tmp = (char * ) FUNCCALL(SETUP_XfOrM166(_), GC_malloc_atomic (skip ) ); 
      pcc = (pipe_char_count (ip -> peeked_read ) ) ; 
      if (only_avail == - 1 ) {
#       define XfOrM171_COUNT (0+XfOrM166_COUNT)
#       define SETUP_XfOrM171(x) SETUP_XfOrM166(x)
        FUNCCALL(SETUP_XfOrM171(_), scheme_push_break_enable (& cframe , 1 , 1 ) ); 
      }
      v = FUNCCALL(SETUP_XfOrM166(_), scheme_get_byte_string_unless (who , port , tmp , 0 , skip , (only_avail == 2 ) ? 2 : 0 , 1 , ((Scheme_Object * ) (void * ) (long ) ((((long ) (ip -> ungotten_count + pcc ) ) << 1 ) | 0x1 ) ) , unless_evt ) ); 
      if (only_avail == - 1 ) {
#       define XfOrM170_COUNT (0+XfOrM166_COUNT)
#       define SETUP_XfOrM170(x) SETUP_XfOrM166(x)
        FUNCCALL(SETUP_XfOrM170(_), scheme_pop_break_enable (& cframe , 0 ) ); 
      }
      if (v == (- 1 ) ) {
        ip -> p . utf8state = 0 ; 
        RET_VALUE_START ((- 1 ) ) RET_VALUE_END ; 
      }
      else if (v == (- 2 ) ) {
#       define XfOrM168_COUNT (0+XfOrM166_COUNT)
#       define SETUP_XfOrM168(x) SETUP_XfOrM166(x)
        ip -> special = ((void * ) 0 ) ; 
        FUNCCALL(SETUP_XfOrM168(_), scheme_bad_time_for_special (who , port ) ); 
      }
      else if (v == skip ) {
#       define XfOrM167_COUNT (0+XfOrM166_COUNT)
#       define SETUP_XfOrM167(x) SETUP_XfOrM166(x)
        peek_skip = FUNCCALL(SETUP_XfOrM167(_), scheme_bin_minus (peek_skip , ((Scheme_Object * ) (void * ) (long ) ((((long ) (skip ) ) << 1 ) | 0x1 ) ) ) ); 
      }
      else RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    if (size ) {
      int nonblock ; 
#     define XfOrM135_COUNT (0+XfOrM128_COUNT)
#     define SETUP_XfOrM135(x) SETUP_XfOrM128(x)
      if (only_avail == 2 ) {
        if (got )
          nonblock = 2 ; 
        else nonblock = 1 ; 
      }
      else if (only_avail == - 1 )
        nonblock = - 1 ; 
      else nonblock = 0 ; 
      if (unless_evt && ((Scheme_Type ) (((((long ) (unless_evt ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (unless_evt ) ) -> type ) ) == (Scheme_Type ) (scheme_progress_evt_type ) ) )
        unless_evt = (((Scheme_Simple_Object * ) (unless_evt ) ) -> u . two_ptr_val . ptr2 ) ; 
      if (ip -> pending_eof > 1 ) {
        ip -> pending_eof = 1 ; 
        gc = (- 1 ) ; 
      }
      else {
        Scheme_Object * unless ; 
        BLOCK_SETUP((PUSH(unless, 0+XfOrM135_COUNT)));
#       define XfOrM144_COUNT (1+XfOrM135_COUNT)
#       define SETUP_XfOrM144(x) SETUP(XfOrM144_COUNT)
        unless = NULLED_OUT ; 
        if (nonblock > 0 ) {
          if (ip -> unless )
            unless = ip -> unless ; 
          else unless = ((void * ) 0 ) ; 
        }
        else if (ip -> unless_cache ) {
#         define XfOrM152_COUNT (0+XfOrM144_COUNT)
#         define SETUP_XfOrM152(x) SETUP_XfOrM144(x)
          if (ip -> unless ) {
            unless = ip -> unless ; 
            (((Scheme_Simple_Object * ) (unless ) ) -> u . pair_val . car ) = scheme_false ; 
          }
          else if ((! (((ip -> unless_cache ) ) == (scheme_false ) ) ) ) {
            unless = ip -> unless_cache ; 
            ip -> unless_cache = scheme_false ; 
            ip -> unless = unless ; 
          }
          else {
#           define XfOrM153_COUNT (0+XfOrM152_COUNT)
#           define SETUP_XfOrM153(x) SETUP_XfOrM152(x)
            unless = FUNCCALL(SETUP_XfOrM153(_), scheme_make_raw_pair (((void * ) 0 ) , ((void * ) 0 ) ) ); 
            ip -> unless = unless ; 
          }
          if (unless_evt )
            (((Scheme_Simple_Object * ) (unless ) ) -> u . pair_val . cdr ) = unless_evt ; 
        }
        else unless = unless_evt ; 
        if (peek && ps )
          gc = FUNCCALL(SETUP_XfOrM144(_), ps (ip , buffer , offset + got , size , peek_skip , nonblock , unless ) ); 
        else {
#         define XfOrM151_COUNT (0+XfOrM144_COUNT)
#         define SETUP_XfOrM151(x) SETUP_XfOrM144(x)
          gc = FUNCCALL(SETUP_XfOrM151(_), gs (ip , buffer , offset + got , size , nonblock , unless ) ); 
          if (! peek && gc && ip -> progress_evt && (gc != (- 1 ) ) && (gc != (- 3 ) ) )
            FUNCCALL(SETUP_XfOrM151(_), post_progress (ip ) ); 
        }
        if (unless && ip -> unless_cache ) {
          if (! (((Scheme_Simple_Object * ) (unless ) ) -> u . pair_val . car ) ) {
            ip -> unless_cache = unless ; 
            (((Scheme_Simple_Object * ) (unless ) ) -> u . pair_val . cdr ) = ((void * ) 0 ) ; 
          }
          else {
            if ((! ((((((Scheme_Simple_Object * ) (unless ) ) -> u . pair_val . car ) ) ) == (scheme_false ) ) ) ) {
              if (gc == (- 3 ) ) {
                gc = 0 ; 
              }
            }
            else if (gc ) {
              (((Scheme_Simple_Object * ) (unless ) ) -> u . pair_val . car ) = scheme_true ; 
            }
          }
          ip -> unless = ((void * ) 0 ) ; 
        }
      }
      if (gc == (- 2 ) ) {
#       define XfOrM139_COUNT (0+XfOrM135_COUNT)
#       define SETUP_XfOrM139(x) SETUP_XfOrM135(x)
        if (! got && ! total_got && special_ok ) {
#         define XfOrM142_COUNT (0+XfOrM139_COUNT)
#         define SETUP_XfOrM142(x) SETUP_XfOrM139(x)
          if (! peek ) {
#           define XfOrM143_COUNT (0+XfOrM142_COUNT)
#           define SETUP_XfOrM143(x) SETUP_XfOrM142(x)
            if (ip -> p . position >= 0 )
              ip -> p . position ++ ; 
            if (ip -> p . count_lines )
              (inc_pos ((Scheme_Port * ) ip , 1 ) ) ; 
          }
          RET_VALUE_START ((- 2 ) ) RET_VALUE_END ; 
        }
        if ((got || total_got ) && only_avail ) {
          ip -> ungotten_special = ip -> special ; 
          ip -> special = ((void * ) 0 ) ; 
          gc = 0 ; 
        }
        else {
#         define XfOrM140_COUNT (0+XfOrM139_COUNT)
#         define SETUP_XfOrM140(x) SETUP_XfOrM139(x)
          ip -> special = ((void * ) 0 ) ; 
          FUNCCALL(SETUP_XfOrM140(_), scheme_bad_time_for_special (who , port ) ); 
          RET_VALUE_START (0 ) RET_VALUE_END ; 
        }
      }
      else if (gc == (- 1 ) ) {
        ip -> p . utf8state = 0 ; 
        if (! got && ! total_got ) {
          if (peek && ip -> pending_eof )
            ip -> pending_eof = 2 ; 
          RET_VALUE_START ((- 1 ) ) RET_VALUE_END ; 
        }
        if (ip -> pending_eof )
          ip -> pending_eof = 2 ; 
        gc = 0 ; 
        size = 0 ; 
      }
      else if (gc == (- 3 ) ) {
        gc = 0 ; 
        size = 0 ; 
      }
      ; 
    }
    else gc = 0 ; 
    got += gc ; 
    if (peek )
      peek_skip = FUNCCALL(SETUP_XfOrM128(_), quick_plus (peek_skip , gc ) ); 
    size -= gc ; 
    if (! peek ) {
#     define XfOrM134_COUNT (0+XfOrM128_COUNT)
#     define SETUP_XfOrM134(x) SETUP_XfOrM128(x)
      if (ip -> p . position >= 0 )
        ip -> p . position += got ; 
      if (ip -> p . count_lines )
        (do_count_lines ((Scheme_Port * ) ip , buffer , offset , got ) ) ; 
    }
    else if (! ps ) {
#     define XfOrM129_COUNT (0+XfOrM128_COUNT)
#     define SETUP_XfOrM129(x) SETUP_XfOrM128(x)
      if (gc ) {
#       define XfOrM130_COUNT (0+XfOrM129_COUNT)
#       define SETUP_XfOrM130(x) SETUP_XfOrM129(x)
        if ((gc == 1 ) && ! ip -> ungotten_count && ! ip -> peeked_write ) {
          ip -> ungotten [ip -> ungotten_count ++ ] = buffer [offset ] ; 
        }
        else {
#         define XfOrM131_COUNT (0+XfOrM130_COUNT)
#         define SETUP_XfOrM131(x) SETUP_XfOrM130(x)
          if (! ip -> peeked_write ) {
            Scheme_Object * rd , * wt ; 
            BLOCK_SETUP((PUSH(wt, 0+XfOrM131_COUNT), PUSH(rd, 1+XfOrM131_COUNT)));
#           define XfOrM132_COUNT (2+XfOrM131_COUNT)
#           define SETUP_XfOrM132(x) SETUP(XfOrM132_COUNT)
            rd = NULLED_OUT ; 
            wt = NULLED_OUT ; 
            FUNCCALL(SETUP_XfOrM132(_), scheme_pipe (& rd , & wt ) ); 
            ip -> peeked_read = rd ; 
            ip -> peeked_write = wt ; 
          }
          FUNCCALL(SETUP_XfOrM131(_), scheme_put_byte_string ("peek" , ip -> peeked_write , buffer , offset + got - gc , gc , 0 ) ); 
        }
      }
    }
    offset += got ; 
    total_got += got ; 
    got = 0 ; 
    if (! size || (total_got && ((only_avail == 1 ) || (only_avail == - 1 ) ) ) || (only_avail == 2 ) )
      break ; 
  }
  RET_VALUE_START (total_got ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
long scheme_get_byte_string_special_ok_unless (const char * who , Scheme_Object * port , char * buffer , long offset , long size , int only_avail , int peek , Scheme_Object * peek_skip , Scheme_Object * unless_evt ) {
  /* No conversion */
  special_is_ok = 1 ; 
  return scheme_get_byte_string_unless (who , port , buffer , offset , size , only_avail , peek , peek_skip , unless_evt ) ; 
}
long scheme_get_byte_string (const char * who , Scheme_Object * port , char * buffer , long offset , long size , int only_avail , int peek , Scheme_Object * peek_skip ) {
  /* No conversion */
  return scheme_get_byte_string_unless (who , port , buffer , offset , size , only_avail , peek , peek_skip , ((void * ) 0 ) ) ; 
}
int scheme_unless_ready (Scheme_Object * unless ) {
  /* No conversion */
  if (! unless )
    return 0 ; 
  if ((((Scheme_Simple_Object * ) (unless ) ) -> u . pair_val . car ) && (! ((((((Scheme_Simple_Object * ) (unless ) ) -> u . pair_val . car ) ) ) == (scheme_false ) ) ) )
    return 1 ; 
  if ((((Scheme_Simple_Object * ) (unless ) ) -> u . pair_val . cdr ) )
    return scheme_try_plain_sema ((((Scheme_Simple_Object * ) (unless ) ) -> u . pair_val . cdr ) ) ; 
  return 0 ; 
}
void scheme_wait_input_allowed (Scheme_Input_Port * ip , int nonblock ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(ip, 0)));
# define XfOrM198_COUNT (1)
# define SETUP_XfOrM198(x) SETUP(XfOrM198_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  while (ip -> input_lock ) {
#   define XfOrM200_COUNT (0+XfOrM198_COUNT)
#   define SETUP_XfOrM200(x) SETUP_XfOrM198(x)
    FUNCCALL(SETUP_XfOrM200(_), scheme_post_sema_all (ip -> input_giveup ) ); 
    FUNCCALL(SETUP_XfOrM200(_), scheme_wait_sema (ip -> input_lock , nonblock ? - 1 : 0 ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void release_input_lock (Scheme_Input_Port * ip ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(ip, 0)));
# define XfOrM201_COUNT (1)
# define SETUP_XfOrM201(x) SETUP(XfOrM201_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM201(_), scheme_post_sema_all (ip -> input_lock ) ); 
  ip -> input_lock = ((void * ) 0 ) ; 
  ip -> input_giveup = ((void * ) 0 ) ; 
  if (scheme_current_thread -> running & 0x20 )
    scheme_current_thread -> running -= 0x20 ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void elect_new_main (Scheme_Input_Port * ip ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(ip, 0)));
# define XfOrM202_COUNT (1)
# define SETUP_XfOrM202(x) SETUP(XfOrM202_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (ip -> input_extras_ready ) {
#   define XfOrM203_COUNT (0+XfOrM202_COUNT)
#   define SETUP_XfOrM203(x) SETUP_XfOrM202(x)
    FUNCCALL(SETUP_XfOrM203(_), scheme_post_sema_all (ip -> input_extras_ready ) ); 
    ip -> input_extras = ((void * ) 0 ) ; 
    ip -> input_extras_ready = ((void * ) 0 ) ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void release_input_lock_and_elect_new_main (void * _ip ) {
  Scheme_Input_Port * ip ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(ip, 0)));
# define XfOrM204_COUNT (1)
# define SETUP_XfOrM204(x) SETUP(XfOrM204_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ip = NULLED_OUT ; 
  ip = FUNCCALL(SETUP_XfOrM204(_), scheme_input_port_record (_ip ) ); 
  FUNCCALL_AGAIN(release_input_lock (ip ) ); 
  FUNCCALL_EMPTY(elect_new_main (ip ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void check_suspended () {
  /* No conversion */
  if (scheme_current_thread -> running & 0x10 )
    scheme_thread_block (0.0 ) ; 
}
static void remove_extra (void * ip_v ) {
  Scheme_Input_Port * ip ; 
  Scheme_Object * v = (((Scheme_Simple_Object * ) (ip_v ) ) -> u . pair_val . cdr ) , * ll , * prev ; 
  PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(ll, 0), PUSH(v, 1), PUSH(ip, 2), PUSH(prev, 3)));
# define XfOrM206_COUNT (4)
# define SETUP_XfOrM206(x) SETUP(XfOrM206_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ip = NULLED_OUT ; 
  ll = NULLED_OUT ; 
  prev = NULLED_OUT ; 
  ip = FUNCCALL(SETUP_XfOrM206(_), scheme_input_port_record ((((Scheme_Simple_Object * ) (ip_v ) ) -> u . pair_val . car ) ) ); 
  prev = ((void * ) 0 ) ; 
  for (ll = ip -> input_extras ; ll ; prev = ll , ll = (((Scheme_Simple_Object * ) (ll ) ) -> u . pair_val . cdr ) ) {
    if (((ll ) == ((((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) ) ) ) {
      if (prev )
        (((Scheme_Simple_Object * ) (prev ) ) -> u . pair_val . cdr ) = (((Scheme_Simple_Object * ) (ll ) ) -> u . pair_val . cdr ) ; 
      else ip -> input_extras = (((Scheme_Simple_Object * ) (ll ) ) -> u . pair_val . cdr ) ; 
      (((Scheme_Simple_Object * ) (ll ) ) -> u . pair_val . cdr ) = ((void * ) 0 ) ; 
      break ; 
    }
  }
  if (ip -> input_giveup )
    FUNCCALL_EMPTY(scheme_post_sema_all (ip -> input_giveup ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int complete_peeked_read_via_get (Scheme_Input_Port * ip , long size ) {
  Scheme_Get_String_Fun gs ; 
  int did ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(ip, 0)));
# define XfOrM211_COUNT (1)
# define SETUP_XfOrM211(x) SETUP(XfOrM211_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  did = 0 ; 
  if (ip -> ungotten_count ) {
#   define XfOrM219_COUNT (0+XfOrM211_COUNT)
#   define SETUP_XfOrM219(x) SETUP_XfOrM211(x)
    if (ip -> ungotten_count > size )
      ip -> ungotten_count -= size ; 
    else {
      size -= ip -> ungotten_count ; 
      ip -> ungotten_count = 0 ; 
    }
    if (ip -> progress_evt )
      FUNCCALL(SETUP_XfOrM219(_), post_progress (ip ) ); 
    did = 1 ; 
  }
  if (size ) {
    Scheme_Input_Port * pip ; 
#   define XfOrM212_COUNT (0+XfOrM211_COUNT)
#   define SETUP_XfOrM212(x) SETUP_XfOrM211(x)
    pip = NULLED_OUT ; 
    if (ip -> peek_string_fun ) {
      gs = ip -> get_string_fun ; 
      pip = ip ; 
    }
    else {
#     define XfOrM215_COUNT (0+XfOrM212_COUNT)
#     define SETUP_XfOrM215(x) SETUP_XfOrM212(x)
      if (ip -> peeked_read ) {
        int cnt ; 
#       define XfOrM217_COUNT (0+XfOrM215_COUNT)
#       define SETUP_XfOrM217(x) SETUP_XfOrM215(x)
        cnt = (pipe_char_count (ip -> peeked_read ) ) ; 
        if ((cnt < size ) && (ip -> pending_eof == 2 ) )
          ip -> pending_eof = 1 ; 
        pip = (Scheme_Input_Port * ) ip -> peeked_read ; 
        gs = pip -> get_string_fun ; 
      }
      else {
        gs = ((void * ) 0 ) ; 
        pip = ((void * ) 0 ) ; 
      }
    }
    if (gs ) {
#     define XfOrM213_COUNT (0+XfOrM212_COUNT)
#     define SETUP_XfOrM213(x) SETUP_XfOrM212(x)
      size = FUNCCALL(SETUP_XfOrM213(_), gs (pip , ((void * ) 0 ) , 0 , size , 1 , ((void * ) 0 ) ) ); 
      if (size > 0 ) {
#       define XfOrM214_COUNT (0+XfOrM213_COUNT)
#       define SETUP_XfOrM214(x) SETUP_XfOrM213(x)
        if (ip -> progress_evt )
          FUNCCALL_EMPTY(post_progress (ip ) ); 
        did = 1 ; 
      }
    }
  }
  RET_VALUE_START (did ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * return_data (void * data , int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return (Scheme_Object * ) data ; 
}
int scheme_peeked_read_via_get (Scheme_Input_Port * ip , long _size , Scheme_Object * unless_evt , Scheme_Object * _target_evt ) {
  Scheme_Object * volatile v , * sema , * a [3 ] , * * volatile aa , * volatile l ; 
  volatile long size = _size ; 
  volatile int n , current_leader = 0 ; 
  volatile Scheme_Type t ; 
  Scheme_Object * volatile target_evt = _target_evt ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(11);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 3, 0), PUSH(l, 3), PUSH(sema, 4), PUSH(unless_evt, 5), PUSH(target_evt, 6), PUSH(v, 7), PUSH(ip, 8), PUSH(aa, 9)));
# define XfOrM222_COUNT (10)
# define SETUP_XfOrM222(x) SETUP(XfOrM222_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  v = NULLED_OUT ; 
  sema = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  a[2] = NULLED_OUT ; 
  aa = NULLED_OUT ; 
  l = NULLED_OUT ; 
  t = ((((long ) (target_evt ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (target_evt ) ) -> type ) ; 
  if (! ((Scheme_Type ) (t ) == (Scheme_Type ) (scheme_sema_type ) ) && ! ((Scheme_Type ) (t ) == (Scheme_Type ) (scheme_channel_put_type ) ) && ! ((Scheme_Type ) (t ) == (Scheme_Type ) (scheme_always_evt_type ) ) && ! ((Scheme_Type ) (t ) == (Scheme_Type ) (scheme_never_evt_type ) ) && ! ((Scheme_Type ) (t ) == (Scheme_Type ) (scheme_semaphore_repost_type ) ) ) {
#   define XfOrM279_COUNT (0+XfOrM222_COUNT)
#   define SETUP_XfOrM279(x) SETUP_XfOrM222(x)
    a [0 ] = target_evt ; 
    v = FUNCCALL(SETUP_XfOrM279(_), scheme_make_closed_prim (return_data , target_evt ) ); 
    a [1 ] = v ; 
    target_evt = FUNCCALL(SETUP_XfOrM279(_), scheme_wrap_evt (2 , a ) ); 
    ((Scheme_Closed_Primitive_Proc * ) v ) -> data = target_evt ; 
  }
  while (1 ) {
#   define XfOrM251_COUNT (0+XfOrM222_COUNT)
#   define SETUP_XfOrM251(x) SETUP_XfOrM222(x)
    if (FUNCCALL(SETUP_XfOrM251(_), scheme_wait_sema (unless_evt , 1 ) )) {
#     define XfOrM278_COUNT (0+XfOrM251_COUNT)
#     define SETUP_XfOrM278(x) SETUP_XfOrM251(x)
      if (current_leader )
        FUNCCALL(SETUP_XfOrM278(_), elect_new_main (ip ) ); 
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    if (! current_leader && ip -> input_giveup ) {
#     define XfOrM272_COUNT (0+XfOrM251_COUNT)
#     define SETUP_XfOrM272(x) SETUP_XfOrM251(x)
      v = FUNCCALL(SETUP_XfOrM272(_), scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (_size ) ) << 1 ) | 0x1 ) ) , target_evt ) ); 
      l = FUNCCALL(SETUP_XfOrM272(_), scheme_make_raw_pair (v , ip -> input_extras ) ); 
      ip -> input_extras = l ; 
      FUNCCALL(SETUP_XfOrM272(_), scheme_post_sema_all (ip -> input_giveup ) ); 
      if (! ip -> input_extras_ready ) {
#       define XfOrM277_COUNT (0+XfOrM272_COUNT)
#       define SETUP_XfOrM277(x) SETUP_XfOrM272(x)
        sema = FUNCCALL(SETUP_XfOrM277(_), scheme_make_sema (0 ) ); 
        ip -> input_extras_ready = sema ; 
      }
      a [0 ] = ip -> input_extras_ready ; 
      l = FUNCCALL(SETUP_XfOrM272(_), scheme_make_pair ((Scheme_Object * ) ip , v ) ); 
      {
        mz_jmp_buf * volatile savebuf , newbuf ; 
        BLOCK_SETUP((PUSH(savebuf, 0+XfOrM272_COUNT)));
#       define XfOrM274_COUNT (1+XfOrM272_COUNT)
#       define SETUP_XfOrM274(x) SETUP(XfOrM274_COUNT)
        savebuf = NULLED_OUT ; 
        FUNCCALL(SETUP_XfOrM274(_), scheme_push_kill_action ((Scheme_Kill_Action_Func ) remove_extra , (void * ) l ) ); 
        savebuf = scheme_current_thread -> error_buf ; 
        scheme_current_thread -> error_buf = & newbuf ; 
        if (((newbuf ) . gcvs = (long ) __gc_var_stack__ , (newbuf ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((newbuf ) . jb ) , (_setjmp (((newbuf ) . jb ) -> jb ) ) ) ) ) {
#         define XfOrM276_COUNT (0+XfOrM274_COUNT)
#         define SETUP_XfOrM276(x) SETUP_XfOrM274(x)
          FUNCCALL(SETUP_XfOrM276(_), scheme_pop_kill_action () ); 
          FUNCCALL(SETUP_XfOrM276(_), remove_extra (l ) ); 
          (((long * ) (void * ) ((* savebuf ) . gcvs ) ) [1 ] = (* savebuf ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* savebuf ) . gcvs , scheme_jit_longjmp ((* savebuf ) . jb , 1 ) ) ; 
        }
        else {
#         define XfOrM275_COUNT (0+XfOrM274_COUNT)
#         define SETUP_XfOrM275(x) SETUP_XfOrM274(x)
          ; 
          FUNCCALL(SETUP_XfOrM275(_), scheme_sync (1 , a ) ); 
          FUNCCALL_AGAIN(scheme_pop_kill_action () ); 
          scheme_current_thread -> error_buf = savebuf ; 
        }
      }
      ; 
      if (! (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) ) {
        RET_VALUE_START ((! ((((((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) ) ) == (scheme_false ) ) ) ? 1 : 0 ) RET_VALUE_END ; 
      }
    }
    else {
#     define XfOrM252_COUNT (0+XfOrM251_COUNT)
#     define SETUP_XfOrM252(x) SETUP_XfOrM251(x)
      if (((Scheme_Type ) (t ) == (Scheme_Type ) (scheme_always_evt_type ) ) ) {
#       define XfOrM271_COUNT (0+XfOrM252_COUNT)
#       define SETUP_XfOrM271(x) SETUP_XfOrM252(x)
        RET_VALUE_START (FUNCCALL(SETUP_XfOrM271(_), complete_peeked_read_via_get (ip , size ) )) RET_VALUE_END ; 
      }
      sema = FUNCCALL(SETUP_XfOrM252(_), scheme_make_sema (0 ) ); 
      ip -> input_lock = sema ; 
      sema = FUNCCALL(SETUP_XfOrM252(_), scheme_make_sema (0 ) ); 
      ip -> input_giveup = sema ; 
      if (ip -> input_extras ) {
#       define XfOrM266_COUNT (0+XfOrM252_COUNT)
#       define SETUP_XfOrM266(x) SETUP_XfOrM252(x)
        n = 3 ; 
        for (l = ip -> input_extras ; l ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
          n ++ ; 
        }
        aa = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM266(_), GC_malloc (sizeof (Scheme_Object * ) * (n ) ) )) ; 
        n = 3 ; 
        for (l = ip -> input_extras ; l ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
          aa [n ++ ] = (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ; 
        }
      }
      else {
        n = 3 ; 
        aa = a ; 
      }
      aa [0 ] = target_evt ; 
      aa [1 ] = ip -> input_giveup ; 
      v = FUNCCALL(SETUP_XfOrM252(_), scheme_get_thread_suspend (scheme_current_thread ) ); 
      aa [2 ] = v ; 
      scheme_current_thread -> running |= 0x20 ; 
      {
        mz_jmp_buf * volatile savebuf , newbuf ; 
        BLOCK_SETUP((PUSH(savebuf, 0+XfOrM252_COUNT)));
#       define XfOrM262_COUNT (1+XfOrM252_COUNT)
#       define SETUP_XfOrM262(x) SETUP(XfOrM262_COUNT)
        savebuf = NULLED_OUT ; 
        FUNCCALL(SETUP_XfOrM262(_), scheme_push_kill_action ((Scheme_Kill_Action_Func ) release_input_lock_and_elect_new_main , (void * ) ip ) ); 
        savebuf = scheme_current_thread -> error_buf ; 
        scheme_current_thread -> error_buf = & newbuf ; 
        if (((newbuf ) . gcvs = (long ) __gc_var_stack__ , (newbuf ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((newbuf ) . jb ) , (_setjmp (((newbuf ) . jb ) -> jb ) ) ) ) ) {
#         define XfOrM264_COUNT (0+XfOrM262_COUNT)
#         define SETUP_XfOrM264(x) SETUP_XfOrM262(x)
          FUNCCALL(SETUP_XfOrM264(_), scheme_pop_kill_action () ); 
          FUNCCALL(SETUP_XfOrM264(_), release_input_lock_and_elect_new_main (ip ) ); 
          (((long * ) (void * ) ((* savebuf ) . gcvs ) ) [1 ] = (* savebuf ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* savebuf ) . gcvs , scheme_jit_longjmp ((* savebuf ) . jb , 1 ) ) ; 
        }
        else {
#         define XfOrM263_COUNT (0+XfOrM262_COUNT)
#         define SETUP_XfOrM263(x) SETUP_XfOrM262(x)
          ; 
          v = FUNCCALL(SETUP_XfOrM263(_), scheme_sync (n , aa ) ); 
          FUNCCALL_AGAIN(scheme_pop_kill_action () ); 
          scheme_current_thread -> error_buf = savebuf ; 
        }
      }
      ; 
      FUNCCALL(SETUP_XfOrM252(_), release_input_lock (ip ) ); 
      if (((v ) == (target_evt ) ) ) {
        int r ; 
#       define XfOrM261_COUNT (0+XfOrM252_COUNT)
#       define SETUP_XfOrM261(x) SETUP_XfOrM252(x)
        FUNCCALL(SETUP_XfOrM261(_), elect_new_main (ip ) ); 
        r = FUNCCALL(SETUP_XfOrM261(_), complete_peeked_read_via_get (ip , size ) ); 
        FUNCCALL_AGAIN(check_suspended () ); 
        RET_VALUE_START (r ) RET_VALUE_END ; 
      }
      if (n > 3 ) {
#       define XfOrM256_COUNT (0+XfOrM252_COUNT)
#       define SETUP_XfOrM256(x) SETUP_XfOrM252(x)
        for (l = ip -> input_extras ; l ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#         define XfOrM259_COUNT (0+XfOrM256_COUNT)
#         define SETUP_XfOrM259(x) SETUP_XfOrM256(x)
          if (((v ) == ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) ) {
#           define XfOrM260_COUNT (0+XfOrM259_COUNT)
#           define SETUP_XfOrM260(x) SETUP_XfOrM259(x)
            v = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
            (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) = ((void * ) 0 ) ; 
            size = (((long ) ((((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) ) ) >> 1 ) ; 
            FUNCCALL(SETUP_XfOrM260(_), elect_new_main (ip ) ); 
            if (FUNCCALL(SETUP_XfOrM260(_), complete_peeked_read_via_get (ip , size ) ))
              (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) = scheme_true ; 
            else (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) = scheme_false ; 
            FUNCCALL(SETUP_XfOrM260(_), check_suspended () ); 
            RET_VALUE_START (0 ) RET_VALUE_END ; 
          }
        }
      }
      if (scheme_current_thread -> running & 0x10 ) {
#       define XfOrM255_COUNT (0+XfOrM252_COUNT)
#       define SETUP_XfOrM255(x) SETUP_XfOrM252(x)
        FUNCCALL(SETUP_XfOrM255(_), elect_new_main (ip ) ); 
        current_leader = 0 ; 
        FUNCCALL(SETUP_XfOrM255(_), check_suspended () ); 
      }
      else {
#       define XfOrM253_COUNT (0+XfOrM252_COUNT)
#       define SETUP_XfOrM253(x) SETUP_XfOrM252(x)
        current_leader = 1 ; 
        if (FUNCCALL(SETUP_XfOrM253(_), scheme_wait_sema (unless_evt , 1 ) )) {
#         define XfOrM254_COUNT (0+XfOrM253_COUNT)
#         define SETUP_XfOrM254(x) SETUP_XfOrM253(x)
          FUNCCALL(SETUP_XfOrM254(_), elect_new_main (ip ) ); 
          RET_VALUE_START (0 ) RET_VALUE_END ; 
        }
        FUNCCALL(SETUP_XfOrM253(_), scheme_thread_block (0.0 ) ); 
      }
    }
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_peeked_read (Scheme_Object * port , long size , Scheme_Object * unless_evt , Scheme_Object * target_evt ) {
  Scheme_Input_Port * ip ; 
  Scheme_Peeked_Read_Fun pr ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(target_evt, 0), PUSH(unless_evt, 1), PUSH(ip, 2)));
# define XfOrM280_COUNT (3)
# define SETUP_XfOrM280(x) SETUP(XfOrM280_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ip = NULLED_OUT ; 
  ip = FUNCCALL(SETUP_XfOrM280(_), scheme_input_port_record (port ) ); 
  unless_evt = (((Scheme_Simple_Object * ) (unless_evt ) ) -> u . two_ptr_val . ptr2 ) ; 
  pr = ip -> peeked_read_fun ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(pr (ip , size , unless_evt , target_evt ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_progress_evt_via_get (Scheme_Input_Port * port ) {
  Scheme_Object * sema ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sema, 0), PUSH(port, 1)));
# define XfOrM281_COUNT (2)
# define SETUP_XfOrM281(x) SETUP(XfOrM281_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sema = NULLED_OUT ; 
  if (port -> progress_evt )
    RET_VALUE_START (port -> progress_evt ) RET_VALUE_END ; 
  sema = FUNCCALL(SETUP_XfOrM281(_), scheme_make_sema (0 ) ); 
  port -> progress_evt = sema ; 
  RET_VALUE_START (sema ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_progress_evt (Scheme_Object * port ) {
  Scheme_Input_Port * ip ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(port, 0), PUSH(ip, 1)));
# define XfOrM282_COUNT (2)
# define SETUP_XfOrM282(x) SETUP(XfOrM282_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  ip = NULLED_OUT ; 
  ip = FUNCCALL(SETUP_XfOrM282(_), scheme_input_port_record (port ) ); 
  if (ip -> progress_evt_fun ) {
    Scheme_Progress_Evt_Fun ce ; 
    Scheme_Object * evt , * o ; 
    BLOCK_SETUP((PUSH(o, 0+XfOrM282_COUNT), PUSH(evt, 1+XfOrM282_COUNT)));
#   define XfOrM283_COUNT (2+XfOrM282_COUNT)
#   define SETUP_XfOrM283(x) SETUP(XfOrM283_COUNT)
    evt = NULLED_OUT ; 
    o = NULLED_OUT ; 
    ce = ip -> progress_evt_fun ; 
    evt = FUNCCALL(SETUP_XfOrM283(_), ce (ip ) ); 
    o = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM283(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    o -> type = scheme_progress_evt_type ; 
    (((Scheme_Simple_Object * ) (o ) ) -> u . two_ptr_val . ptr1 ) = (Scheme_Object * ) port ; 
    (((Scheme_Simple_Object * ) (o ) ) -> u . two_ptr_val . ptr2 ) = evt ; 
    RET_VALUE_START (o ) RET_VALUE_END ; 
  }
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int progress_evt_ready (Scheme_Object * evt , Scheme_Schedule_Info * sinfo ) {
  /* No conversion */
  scheme_set_sync_target (sinfo , (((Scheme_Simple_Object * ) (evt ) ) -> u . two_ptr_val . ptr2 ) , evt , ((void * ) 0 ) , 0 , 1 ) ; 
  return 0 ; 
}
long scheme_get_char_string (const char * who , Scheme_Object * port , mzchar * buffer , long offset , long size , int peek , Scheme_Object * peek_skip ) {
  int ahead_skip = 0 ; 
  char * s ; 
  int total_got = 0 , bsize , leftover = 0 , got ; 
  Scheme_Object * __funcarg18 = NULLED_OUT ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(port, 0), PUSH(buffer, 1), PUSH(peek_skip, 2), PUSH(s, 3), PUSH(who, 4)));
# define XfOrM285_COUNT (5)
# define SETUP_XfOrM285(x) SETUP(XfOrM285_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  if (read_string_byte_buffer ) {
    s = read_string_byte_buffer ; 
    read_string_byte_buffer = ((void * ) 0 ) ; 
  }
  else s = (char * ) FUNCCALL(SETUP_XfOrM285(_), GC_malloc_atomic (1024 ) ); 
  while (1 ) {
#   define XfOrM306_COUNT (0+XfOrM285_COUNT)
#   define SETUP_XfOrM306(x) SETUP_XfOrM285(x)
    bsize = size ; 
    if (leftover ) {
#     define XfOrM314_COUNT (0+XfOrM306_COUNT)
#     define SETUP_XfOrM314(x) SETUP_XfOrM306(x)
      bsize -= leftover ; 
      if (bsize < 1 ) {
#       define XfOrM315_COUNT (0+XfOrM314_COUNT)
#       define SETUP_XfOrM315(x) SETUP_XfOrM314(x)
        if (! peek_skip )
          peek_skip = ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
        special_is_ok = 1 ; 
        got = (__funcarg18 = FUNCCALL(SETUP_XfOrM315(_), quick_plus (peek_skip , ahead_skip ) ), FUNCCALL_AGAIN(scheme_get_byte_string_unless (who , port , s , leftover , 1 , 0 , 1 , __funcarg18 , ((void * ) 0 ) ) )) ; 
        if (got > 0 ) {
          long ulen , glen ; 
#         define XfOrM319_COUNT (0+XfOrM315_COUNT)
#         define SETUP_XfOrM319(x) SETUP_XfOrM315(x)
          glen = FUNCCALL(SETUP_XfOrM319(_), scheme_utf8_decode_as_prefix ((const unsigned char * ) s , 0 , got + leftover , buffer , offset , offset + size , & ulen , 0 , '?' ) ); 
          if (glen && (ulen < got + leftover ) ) {
            total_got ++ ; 
#           define XfOrM325_COUNT (0+XfOrM319_COUNT)
#           define SETUP_XfOrM325(x) SETUP_XfOrM319(x)
            bsize = 0 ; 
            ahead_skip ++ ; 
            size -- ; 
            offset ++ ; 
            (memmove (s , s + 1 , leftover ) ) ; 
          }
          else {
            ahead_skip ++ ; 
#           define XfOrM320_COUNT (0+XfOrM319_COUNT)
#           define SETUP_XfOrM320(x) SETUP_XfOrM319(x)
            if (! glen ) {
              leftover ++ ; 
            }
            else {
#             define XfOrM321_COUNT (0+XfOrM320_COUNT)
#             define SETUP_XfOrM321(x) SETUP_XfOrM320(x)
              leftover = 0 ; 
              offset ++ ; 
              -- size ; 
              total_got ++ ; 
              if (! peek ) {
#               define XfOrM323_COUNT (0+XfOrM321_COUNT)
#               define SETUP_XfOrM323(x) SETUP_XfOrM321(x)
                FUNCCALL(SETUP_XfOrM323(_), scheme_get_byte_string_unless (who , port , s , 0 , ahead_skip , 0 , 0 , ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) , ((void * ) 0 ) ) ); 
              }
              else {
#               define XfOrM322_COUNT (0+XfOrM321_COUNT)
#               define SETUP_XfOrM322(x) SETUP_XfOrM321(x)
                peek_skip = FUNCCALL(SETUP_XfOrM322(_), quick_plus (peek_skip , ahead_skip ) ); 
              }
              ahead_skip = 0 ; 
            }
            bsize = 0 ; 
          }
        }
        else {
          while (leftover && size ) {
            buffer [offset ++ ] = '?' ; 
            total_got ++ ; 
            -- leftover ; 
            -- size ; 
          }
          RET_VALUE_START (total_got ) RET_VALUE_END ; 
        }
      }
    }
    if (bsize ) {
#     define XfOrM313_COUNT (0+XfOrM306_COUNT)
#     define SETUP_XfOrM313(x) SETUP_XfOrM306(x)
      if (bsize + leftover > 1024 )
        bsize = 1024 - leftover ; 
      got = FUNCCALL(SETUP_XfOrM313(_), scheme_get_byte_string_unless (who , port , s , leftover , bsize , 0 , peek , peek_skip , ((void * ) 0 ) ) ); 
    }
    else got = 0 ; 
    if (got >= 0 ) {
      long ulen , glen ; 
#     define XfOrM310_COUNT (0+XfOrM306_COUNT)
#     define SETUP_XfOrM310(x) SETUP_XfOrM306(x)
      glen = FUNCCALL(SETUP_XfOrM310(_), scheme_utf8_decode_as_prefix ((const unsigned char * ) s , 0 , got + leftover , buffer , offset , offset + size , & ulen , 0 , '?' ) ); 
      total_got += glen ; 
      if (glen == size ) {
        read_string_byte_buffer = s ; 
        RET_VALUE_START (total_got ) RET_VALUE_END ; 
      }
      offset += glen ; 
      size -= glen ; 
      leftover = (got + leftover ) - ulen ; 
      (memmove (s , s + ulen , leftover ) ) ; 
      if (peek ) {
#       define XfOrM311_COUNT (0+XfOrM310_COUNT)
#       define SETUP_XfOrM311(x) SETUP_XfOrM310(x)
        peek_skip = FUNCCALL(SETUP_XfOrM311(_), quick_plus (peek_skip , got ) ); 
      }
    }
    else {
      read_string_byte_buffer = s ; 
      while (leftover ) {
        buffer [offset ++ ] = '?' ; 
        total_got ++ ; 
        -- leftover ; 
      }
      if (! total_got )
        RET_VALUE_START (got ) RET_VALUE_END ; 
      else RET_VALUE_START (total_got ) RET_VALUE_END ; 
    }
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline long get_one_byte (const char * who , Scheme_Object * port , char * buffer , long offset , int only_avail ) {
  Scheme_Input_Port * ip ; 
  long gc ; 
  int special_ok = special_is_ok ; 
  Scheme_Get_String_Fun gs ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(port, 0), PUSH(buffer, 1), PUSH(ip, 2), PUSH(who, 3)));
# define XfOrM327_COUNT (4)
# define SETUP_XfOrM327(x) SETUP(XfOrM327_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ip = NULLED_OUT ; 
  special_is_ok = 0 ; 
  ip = FUNCCALL(SETUP_XfOrM327(_), scheme_input_port_record (port ) ); 
  if (ip -> closed )
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL , "%s: " "input" " port is closed" , who ) ); 
  ; 
  if (ip -> input_lock )
    FUNCCALL(SETUP_XfOrM327(_), scheme_wait_input_allowed (ip , only_avail ) ); 
  if (ip -> ungotten_count ) {
    buffer [offset ] = ip -> ungotten [-- ip -> ungotten_count ] ; 
    gc = 1 ; 
  }
  else if (ip -> peeked_read && (pipe_char_count (ip -> peeked_read ) ) ) {
    int ch ; 
#   define XfOrM339_COUNT (0+XfOrM327_COUNT)
#   define SETUP_XfOrM339(x) SETUP_XfOrM327(x)
    ch = FUNCCALL(SETUP_XfOrM339(_), scheme_get_byte (ip -> peeked_read ) ); 
    buffer [offset ] = ch ; 
    gc = 1 ; 
  }
  else if (ip -> ungotten_special ) {
#   define XfOrM337_COUNT (0+XfOrM327_COUNT)
#   define SETUP_XfOrM337(x) SETUP_XfOrM327(x)
    if (ip -> progress_evt )
      FUNCCALL(SETUP_XfOrM337(_), post_progress (ip ) ); 
    if (! special_ok ) {
#     define XfOrM338_COUNT (0+XfOrM337_COUNT)
#     define SETUP_XfOrM338(x) SETUP_XfOrM337(x)
      ip -> ungotten_special = ((void * ) 0 ) ; 
      FUNCCALL(SETUP_XfOrM338(_), scheme_bad_time_for_special (who , port ) ); 
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    ip -> special = ip -> ungotten_special ; 
    ip -> ungotten_special = ((void * ) 0 ) ; 
    if (ip -> p . position >= 0 )
      ip -> p . position ++ ; 
    if (ip -> p . count_lines )
      (inc_pos ((Scheme_Port * ) ip , 1 ) ) ; 
    RET_VALUE_START ((- 2 ) ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM328_COUNT (0+XfOrM327_COUNT)
#   define SETUP_XfOrM328(x) SETUP_XfOrM327(x)
    if (ip -> pending_eof > 1 ) {
      ip -> pending_eof = 1 ; 
      RET_VALUE_START ((- 1 ) ) RET_VALUE_END ; 
    }
    else {
#     define XfOrM329_COUNT (0+XfOrM328_COUNT)
#     define SETUP_XfOrM329(x) SETUP_XfOrM328(x)
      gs = ip -> get_string_fun ; 
      gc = FUNCCALL(SETUP_XfOrM329(_), gs (ip , buffer , offset , 1 , 0 , ((void * ) 0 ) ) ); 
      if (ip -> progress_evt && (gc > 0 ) )
        FUNCCALL(SETUP_XfOrM329(_), post_progress (ip ) ); 
      if (gc < 1 ) {
#       define XfOrM330_COUNT (0+XfOrM329_COUNT)
#       define SETUP_XfOrM330(x) SETUP_XfOrM329(x)
        if (gc == (- 2 ) ) {
#         define XfOrM333_COUNT (0+XfOrM330_COUNT)
#         define SETUP_XfOrM333(x) SETUP_XfOrM330(x)
          if (special_ok ) {
#           define XfOrM335_COUNT (0+XfOrM333_COUNT)
#           define SETUP_XfOrM335(x) SETUP_XfOrM333(x)
            if (ip -> p . position >= 0 )
              ip -> p . position ++ ; 
            if (ip -> p . count_lines )
              (inc_pos ((Scheme_Port * ) ip , 1 ) ) ; 
            RET_VALUE_START ((- 2 ) ) RET_VALUE_END ; 
          }
          else {
#           define XfOrM334_COUNT (0+XfOrM333_COUNT)
#           define SETUP_XfOrM334(x) SETUP_XfOrM333(x)
            FUNCCALL(SETUP_XfOrM334(_), scheme_bad_time_for_special (who , port ) ); 
            RET_VALUE_START (0 ) RET_VALUE_END ; 
          }
        }
        else if (gc == (- 1 ) ) {
          ip -> p . utf8state = 0 ; 
          RET_VALUE_START ((- 1 ) ) RET_VALUE_END ; 
        }
        else {
#         define XfOrM331_COUNT (0+XfOrM330_COUNT)
#         define SETUP_XfOrM331(x) SETUP_XfOrM330(x)
          special_is_ok = special_ok ; 
          RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_get_byte_string_unless (who , port , buffer , offset , 1 , 0 , 0 , ((void * ) 0 ) , ((void * ) 0 ) ) )) RET_VALUE_EMPTY_END ; 
        }
      }
    }
  }
  if (ip -> p . position >= 0 )
    ip -> p . position ++ ; 
  if (ip -> p . count_lines )
    (do_count_lines ((Scheme_Port * ) ip , buffer , offset , 1 ) ) ; 
  RET_VALUE_START (gc ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_getc (Scheme_Object * port ) {
  char s [6 ] ; 
  unsigned int r [1 ] ; 
  int v , delta = 0 ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(port, 0)));
# define XfOrM341_COUNT (1)
# define SETUP_XfOrM341(x) SETUP(XfOrM341_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  while (1 ) {
#   define XfOrM352_COUNT (0+XfOrM341_COUNT)
#   define SETUP_XfOrM352(x) SETUP_XfOrM341(x)
    if (delta ) {
#     define XfOrM361_COUNT (0+XfOrM352_COUNT)
#     define SETUP_XfOrM361(x) SETUP_XfOrM352(x)
      v = FUNCCALL(SETUP_XfOrM361(_), scheme_get_byte_string_unless ("read-char" , port , s , delta , 1 , 0 , delta > 0 , ((Scheme_Object * ) (void * ) (long ) ((((long ) (delta - 1 ) ) << 1 ) | 0x1 ) ) , ((void * ) 0 ) ) ); 
    }
    else {
#     define XfOrM360_COUNT (0+XfOrM352_COUNT)
#     define SETUP_XfOrM360(x) SETUP_XfOrM352(x)
      v = FUNCCALL(SETUP_XfOrM360(_), get_one_byte ("read-char" , port , s , 0 , 0 ) ); 
    }
    if ((v == (- 1 ) ) || (v == (- 2 ) ) ) {
      if (! delta )
        RET_VALUE_START (v ) RET_VALUE_END ; 
      else {
        RET_VALUE_START ('?' ) RET_VALUE_END ; 
      }
    }
    else {
#     define XfOrM353_COUNT (0+XfOrM352_COUNT)
#     define SETUP_XfOrM353(x) SETUP_XfOrM352(x)
      v = FUNCCALL(SETUP_XfOrM353(_), scheme_utf8_decode_prefix ((const unsigned char * ) s , delta + 1 , r , 0 ) ); 
      if (v > 0 ) {
#       define XfOrM356_COUNT (0+XfOrM353_COUNT)
#       define SETUP_XfOrM356(x) SETUP_XfOrM353(x)
        if (delta ) {
#         define XfOrM357_COUNT (0+XfOrM356_COUNT)
#         define SETUP_XfOrM357(x) SETUP_XfOrM356(x)
          v = FUNCCALL(SETUP_XfOrM357(_), scheme_get_byte_string_unless ("read-char" , port , s , 0 , delta , 0 , 0 , 0 , ((void * ) 0 ) ) ); 
        }
        RET_VALUE_START (r [0 ] ) RET_VALUE_END ; 
      }
      else if (v == - 2 ) {
        RET_VALUE_START ('?' ) RET_VALUE_END ; 
      }
      else if (v == - 1 ) {
        delta ++ ; 
      }
    }
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_get_byte (Scheme_Object * port ) {
  /* No conversion */
  char s [1 ] ; 
  int v ; 
  v = get_one_byte ("read-byte" , port , s , 0 , 0 ) ; 
  if ((v == (- 1 ) ) || (v == (- 2 ) ) )
    return v ; 
  else return ((unsigned char * ) s ) [0 ] ; 
}
int scheme_getc_special_ok (Scheme_Object * port ) {
  /* No conversion */
  special_is_ok = 1 ; 
  return scheme_getc (port ) ; 
}
int scheme_get_byte_special_ok (Scheme_Object * port ) {
  /* No conversion */
  special_is_ok = 1 ; 
  return scheme_get_byte (port ) ; 
}
long scheme_get_bytes (Scheme_Object * port , long size , char * buffer , int offset ) {
  /* No conversion */
  int n ; 
  int only_avail = 0 ; 
  if (size < 0 ) {
    size = - size ; 
    only_avail = 1 ; 
  }
  n = scheme_get_byte_string_unless ("read-bytes" , port , buffer , offset , size , only_avail , 0 , 0 , ((void * ) 0 ) ) ; 
  if (n == (- 1 ) )
    n = 0 ; 
  ; 
  return n ; 
}
int scheme_peek_byte_skip (Scheme_Object * port , Scheme_Object * skip , Scheme_Object * unless_evt ) {
  /* No conversion */
  char s [1 ] ; 
  int v ; 
  v = scheme_get_byte_string_unless ("peek-byte" , port , s , 0 , 1 , 0 , 1 , skip , unless_evt ) ; 
  if ((v == (- 1 ) ) || (v == (- 2 ) ) )
    return v ; 
  else return ((unsigned char * ) s ) [0 ] ; 
}
int scheme_peek_byte (Scheme_Object * port ) {
  /* No conversion */
  return scheme_peek_byte_skip (port , ((void * ) 0 ) , ((void * ) 0 ) ) ; 
}
int scheme_peek_byte_special_ok_skip (Scheme_Object * port , Scheme_Object * skip , Scheme_Object * unless_evt ) {
  /* No conversion */
  special_is_ok = 1 ; 
  return scheme_peek_byte_skip (port , skip , unless_evt ) ; 
}
static int do_peekc_skip (Scheme_Object * port , Scheme_Object * skip , int only_avail , int * unavail ) {
  char s [6 ] ; 
  unsigned int r [1 ] ; 
  int v , delta = 0 ; 
  Scheme_Object * skip2 ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(skip, 0), PUSH(unavail, 1), PUSH(skip2, 2), PUSH(port, 3)));
# define XfOrM370_COUNT (4)
# define SETUP_XfOrM370(x) SETUP(XfOrM370_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  skip2 = NULLED_OUT ; 
  if (unavail )
    * unavail = 0 ; 
  while (1 ) {
#   define XfOrM379_COUNT (0+XfOrM370_COUNT)
#   define SETUP_XfOrM379(x) SETUP_XfOrM370(x)
    if (delta ) {
#     define XfOrM386_COUNT (0+XfOrM379_COUNT)
#     define SETUP_XfOrM386(x) SETUP_XfOrM379(x)
      if (! skip )
        skip = ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
      skip2 = FUNCCALL(SETUP_XfOrM386(_), quick_plus (skip , delta ) ); 
    }
    else skip2 = skip ; 
    v = FUNCCALL(SETUP_XfOrM379(_), scheme_get_byte_string_unless ("peek-char" , port , s , delta , 1 , only_avail , 1 , skip2 , ((void * ) 0 ) ) ); 
    if (! v ) {
      * unavail = 1 ; 
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    if ((v == (- 1 ) ) || (v == (- 2 ) ) ) {
      if (! delta )
        RET_VALUE_START (v ) RET_VALUE_END ; 
      else {
        RET_VALUE_START ('?' ) RET_VALUE_END ; 
      }
    }
    else {
#     define XfOrM380_COUNT (0+XfOrM379_COUNT)
#     define SETUP_XfOrM380(x) SETUP_XfOrM379(x)
      v = FUNCCALL(SETUP_XfOrM380(_), scheme_utf8_decode_prefix ((const unsigned char * ) s , delta + 1 , r , 0 ) ); 
      if (v > 0 )
        RET_VALUE_START (r [0 ] ) RET_VALUE_END ; 
      else if (v == - 2 ) {
        RET_VALUE_START ('?' ) RET_VALUE_END ; 
      }
      else if (v == - 1 ) {
        delta ++ ; 
      }
    }
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_peekc_skip (Scheme_Object * port , Scheme_Object * skip ) {
  /* No conversion */
  return do_peekc_skip (port , skip , 0 , ((void * ) 0 ) ) ; 
}
int scheme_peekc (Scheme_Object * port ) {
  /* No conversion */
  return scheme_peekc_skip (port , ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) ; 
}
int scheme_peekc_special_ok_skip (Scheme_Object * port , Scheme_Object * skip ) {
  /* No conversion */
  special_is_ok = 1 ; 
  return scheme_peekc_skip (port , skip ) ; 
}
int scheme_peekc_special_ok (Scheme_Object * port ) {
  /* No conversion */
  return scheme_peekc_special_ok_skip (port , ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) ; 
}
int scheme_peekc_is_ungetc (Scheme_Object * port ) {
  Scheme_Input_Port * ip ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(ip, 0)));
# define XfOrM391_COUNT (1)
# define SETUP_XfOrM391(x) SETUP(XfOrM391_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ip = NULLED_OUT ; 
  ip = FUNCCALL(SETUP_XfOrM391(_), scheme_input_port_record (port ) ); 
  RET_VALUE_START (! ip -> peek_string_fun ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * make_read_write_evt (Scheme_Type type , Scheme_Object * port , Scheme_Object * skip , char * str , long start , long size ) {
  Scheme_Read_Write_Evt * rww ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(skip, 0), PUSH(str, 1), PUSH(rww, 2), PUSH(port, 3)));
# define XfOrM392_COUNT (4)
# define SETUP_XfOrM392(x) SETUP(XfOrM392_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  rww = NULLED_OUT ; 
  rww = ((Scheme_Read_Write_Evt * ) FUNCCALL(SETUP_XfOrM392(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Read_Write_Evt ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  rww -> so . type = type ; 
  rww -> port = port ; 
  rww -> v = skip ; 
  rww -> str = str ; 
  rww -> start = start ; 
  rww -> size = size ; 
  RET_VALUE_START ((Scheme_Object * ) rww ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int rw_evt_ready (Scheme_Object * _rww , Scheme_Schedule_Info * sinfo ) {
  Scheme_Read_Write_Evt * rww = (Scheme_Read_Write_Evt * ) _rww ; 
  long v ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(sinfo, 0), PUSH(rww, 1)));
# define XfOrM393_COUNT (2)
# define SETUP_XfOrM393(x) SETUP(XfOrM393_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (sinfo -> false_positive_ok ) {
    sinfo -> potentially_false_positive = 1 ; 
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  }
  if (rww -> v ) {
    Scheme_Output_Port * op ; 
    Scheme_Write_Special_Fun ws ; 
    BLOCK_SETUP((PUSH(op, 0+XfOrM393_COUNT)));
#   define XfOrM396_COUNT (1+XfOrM393_COUNT)
#   define SETUP_XfOrM396(x) SETUP(XfOrM396_COUNT)
    op = NULLED_OUT ; 
    op = FUNCCALL(SETUP_XfOrM396(_), scheme_output_port_record (rww -> port ) ); 
    ws = op -> write_special_fun ; 
    v = FUNCCALL(SETUP_XfOrM396(_), ws (op , rww -> v , 1 ) ); 
    if (v ) {
#     define XfOrM397_COUNT (0+XfOrM396_COUNT)
#     define SETUP_XfOrM397(x) SETUP_XfOrM396(x)
      FUNCCALL(SETUP_XfOrM397(_), scheme_set_sync_target (sinfo , scheme_true , ((void * ) 0 ) , ((void * ) 0 ) , 0 , 0 ) ); 
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
    else RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM394_COUNT (0+XfOrM393_COUNT)
#   define SETUP_XfOrM394(x) SETUP_XfOrM393(x)
    v = FUNCCALL(SETUP_XfOrM394(_), scheme_put_byte_string ("write-evt" , rww -> port , rww -> str , rww -> start , rww -> size , 2 ) ); 
    if (v < 1 )
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    else if (! v && rww -> size )
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    else {
#     define XfOrM395_COUNT (0+XfOrM394_COUNT)
#     define SETUP_XfOrM395(x) SETUP_XfOrM394(x)
      FUNCCALL_EMPTY(scheme_set_sync_target (sinfo , ((Scheme_Object * ) (void * ) (long ) ((((long ) (v ) ) << 1 ) | 0x1 ) ) , ((void * ) 0 ) , ((void * ) 0 ) , 0 , 0 ) ); 
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void rw_evt_wakeup (Scheme_Object * _rww , void * fds ) {
  Scheme_Read_Write_Evt * rww = (Scheme_Read_Write_Evt * ) _rww ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(fds, 0), PUSH(rww, 1)));
# define XfOrM399_COUNT (2)
# define SETUP_XfOrM399(x) SETUP(XfOrM399_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (rww -> port ) {
#   define XfOrM400_COUNT (0+XfOrM399_COUNT)
#   define SETUP_XfOrM400(x) SETUP_XfOrM399(x)
    if (rww -> so . type == scheme_write_evt_type )
      FUNCCALL(SETUP_XfOrM400(_), output_need_wakeup (rww -> port , fds ) ); 
    else FUNCCALL_EMPTY(scheme_need_wakeup (rww -> port , fds ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_write_evt_via_write (Scheme_Output_Port * port , const char * str , long offset , long size ) {
  /* No conversion */
  return make_read_write_evt (scheme_write_evt_type , (Scheme_Object * ) port , ((void * ) 0 ) , (char * ) str , offset , size ) ; 
}
Scheme_Object * scheme_write_special_evt_via_write_special (Scheme_Output_Port * port , Scheme_Object * special ) {
  /* No conversion */
  return make_read_write_evt (scheme_write_evt_type , (Scheme_Object * ) port , special , ((void * ) 0 ) , 0 , 1 ) ; 
}
Scheme_Object * scheme_make_write_evt (const char * who , Scheme_Object * port , Scheme_Object * special , char * str , long start , long size ) {
  Scheme_Output_Port * op ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(op, 0), PUSH(port, 1), PUSH(str, 2), PUSH(special, 3)));
# define XfOrM403_COUNT (4)
# define SETUP_XfOrM403(x) SETUP(XfOrM403_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  op = NULLED_OUT ; 
  op = FUNCCALL(SETUP_XfOrM403(_), scheme_output_port_record (port ) ); 
  if (! special ) {
#   define XfOrM406_COUNT (0+XfOrM403_COUNT)
#   define SETUP_XfOrM406(x) SETUP_XfOrM403(x)
    if (op -> write_string_evt_fun ) {
      Scheme_Write_String_Evt_Fun wse ; 
#     define XfOrM407_COUNT (0+XfOrM406_COUNT)
#     define SETUP_XfOrM407(x) SETUP_XfOrM406(x)
      wse = op -> write_string_evt_fun ; 
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(wse (op , str , start , size ) )) RET_VALUE_EMPTY_END ; 
    }
  }
  else {
#   define XfOrM404_COUNT (0+XfOrM403_COUNT)
#   define SETUP_XfOrM404(x) SETUP_XfOrM403(x)
    if (op -> write_special_evt_fun ) {
      Scheme_Write_Special_Evt_Fun wse = op -> write_special_evt_fun ; 
#     define XfOrM405_COUNT (0+XfOrM404_COUNT)
#     define SETUP_XfOrM405(x) SETUP_XfOrM404(x)
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(wse (op , special ) )) RET_VALUE_EMPTY_END ; 
    }
  }
  FUNCCALL_EMPTY(scheme_arg_mismatch ("write-bytes-avail-evt" , "port does not support atomic writes: " , port ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_ungetc (int ch , Scheme_Object * port ) {
  Scheme_Input_Port * ip ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(ip, 0)));
# define XfOrM408_COUNT (1)
# define SETUP_XfOrM408(x) SETUP(XfOrM408_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ip = NULLED_OUT ; 
  ip = FUNCCALL(SETUP_XfOrM408(_), scheme_input_port_record (port ) ); 
  if (ip -> closed )
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL , "%s: " "input" " port is closed" , "#<primitive:peek-port-char>" ) ); 
  ; 
  if (ch == (- 1 ) ) {
    if (ip -> pending_eof )
      ip -> pending_eof = 2 ; 
    RET_NOTHING ; 
  }
  else if (ch == (- 2 ) ) {
    ip -> ungotten_special = ip -> special ; 
    ip -> special = ((void * ) 0 ) ; 
  }
  else if (ch > 127 ) {
    unsigned char e [6 ] ; 
    unsigned int us [1 ] ; 
    int len ; 
#   define XfOrM412_COUNT (0+XfOrM408_COUNT)
#   define SETUP_XfOrM412(x) SETUP_XfOrM408(x)
    us [0 ] = ch ; 
    len = FUNCCALL(SETUP_XfOrM412(_), scheme_utf8_encode_all (us , 1 , e ) ); 
    if (ip -> ungotten_count + len >= 24 )
      FUNCCALL_EMPTY(scheme_signal_error ("ungetc overflow" ) ); 
    while (len ) {
      ip -> ungotten [ip -> ungotten_count ++ ] = e [-- len ] ; 
    }
  }
  else {
#   define XfOrM411_COUNT (0+XfOrM408_COUNT)
#   define SETUP_XfOrM411(x) SETUP_XfOrM408(x)
    if (ip -> ungotten_count == 24 )
      FUNCCALL_EMPTY(scheme_signal_error ("ungetc overflow" ) ); 
    ip -> ungotten [ip -> ungotten_count ++ ] = ch ; 
  }
  if (ip -> p . position > 0 )
    -- ip -> p . position ; 
  if (ip -> p . count_lines ) {
    -- ip -> p . column ; 
    -- ip -> p . readpos ; 
    if (! (-- ip -> p . charsSinceNewline ) ) {
      ; 
      -- ip -> p . lineNumber ; 
      ip -> p . column = ip -> p . oldColumn ; 
    }
    else if (ch == '\t' )
      ip -> p . column = ip -> p . oldColumn ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_byte_ready (Scheme_Object * port ) {
  Scheme_Input_Port * ip ; 
  int retval ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(ip, 0)));
# define XfOrM417_COUNT (1)
# define SETUP_XfOrM417(x) SETUP(XfOrM417_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ip = NULLED_OUT ; 
  ip = FUNCCALL(SETUP_XfOrM417(_), scheme_input_port_record (port ) ); 
  if (ip -> closed )
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL , "%s: " "input" " port is closed" , "char-ready?" ) ); 
  ; 
  if (ip -> ungotten_count || ip -> ungotten_special || (ip -> pending_eof > 1 ) || (pipe_char_count (ip -> peeked_read ) ) )
    retval = 1 ; 
  else {
    Scheme_In_Ready_Fun f = ip -> byte_ready_fun ; 
#   define XfOrM418_COUNT (0+XfOrM417_COUNT)
#   define SETUP_XfOrM418(x) SETUP_XfOrM417(x)
    retval = FUNCCALL_EMPTY(f (ip ) ); 
  }
  RET_VALUE_START (retval ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_char_ready (Scheme_Object * port ) {
  int unavail ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(port, 0)));
# define XfOrM419_COUNT (1)
# define SETUP_XfOrM419(x) SETUP(XfOrM419_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! FUNCCALL(SETUP_XfOrM419(_), scheme_byte_ready (port ) ))
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  FUNCCALL_EMPTY(do_peekc_skip (port , ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) , 2 , & unavail ) ); 
  RET_VALUE_START (! unavail ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_get_special (Scheme_Object * port , Scheme_Object * src , long line , long col , long pos , int peek , Scheme_Hash_Table * * for_read ) {
  int cnt ; 
  Scheme_Object * a [4 ] , * special ; 
  Scheme_Input_Port * ip ; 
  Scheme_Cont_Frame_Data cframe ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(9);
  BLOCK_SETUP_TOP((PUSH(src, 0), PUSHARRAY(a, 4, 1), PUSH(for_read, 4), PUSH(port, 5), PUSH(special, 6), PUSH(cframe.cache, 7), PUSH(ip, 8)));
# define XfOrM420_COUNT (9)
# define SETUP_XfOrM420(x) SETUP(XfOrM420_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  NULL_OUT_ARRAY (a ) ; 
  special = NULLED_OUT ; 
  ip = NULLED_OUT ; 
  cframe.cache = NULLED_OUT ; 
  {
#   define XfOrM425_COUNT (0+XfOrM420_COUNT)
#   define SETUP_XfOrM425(x) SETUP_XfOrM420(x)
    if ((scheme_fuel_counter ) <= 0 ) {
#     define XfOrM426_COUNT (0+XfOrM425_COUNT)
#     define SETUP_XfOrM426(x) SETUP_XfOrM425(x)
      FUNCCALL(SETUP_XfOrM426(_), scheme_out_of_fuel () ); 
    }
  }
  ; 
  ip = FUNCCALL(SETUP_XfOrM420(_), scheme_input_port_record (port ) ); 
  if (ip -> ungotten_count ) {
#   define XfOrM424_COUNT (0+XfOrM420_COUNT)
#   define SETUP_XfOrM424(x) SETUP_XfOrM420(x)
    FUNCCALL(SETUP_XfOrM424(_), scheme_signal_error ("ungotten characters at get-special" ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (! ip -> special ) {
#   define XfOrM423_COUNT (0+XfOrM420_COUNT)
#   define SETUP_XfOrM423(x) SETUP_XfOrM420(x)
    FUNCCALL(SETUP_XfOrM423(_), scheme_signal_error ("no ready special" ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (ip -> closed )
    FUNCCALL(SETUP_XfOrM420(_), scheme_raise_exn (MZEXN_FAIL , "%s: " "input" " port is closed" , "#<primitive:get-special>" ) ); 
  ; 
  special = ip -> special ; 
  ip -> special = ((void * ) 0 ) ; 
  if (peek ) {
    if (line > 0 )
      line ++ ; 
    if (col >= 0 )
      col ++ ; 
    if (pos > 0 )
      pos ++ ; 
  }
  a [0 ] = special ; 
  if (! src && FUNCCALL(SETUP_XfOrM420(_), scheme_check_proc_arity (((void * ) 0 ) , 2 , 0 , 1 , a ) ))
    cnt = 0 ; 
  else {
    cnt = 4 ; 
    a [0 ] = (src ? src : scheme_false ) ; 
    a [1 ] = (line > 0 ) ? ((Scheme_Object * ) (void * ) (long ) ((((long ) (line ) ) << 1 ) | 0x1 ) ) : scheme_false ; 
    a [2 ] = (col > 0 ) ? ((Scheme_Object * ) (void * ) (long ) ((((long ) (col - 1 ) ) << 1 ) | 0x1 ) ) : scheme_false ; 
    a [3 ] = (pos > 0 ) ? ((Scheme_Object * ) (void * ) (long ) ((((long ) (pos ) ) << 1 ) | 0x1 ) ) : scheme_false ; 
  }
  FUNCCALL(SETUP_XfOrM420(_), scheme_push_continuation_frame (& cframe ) ); 
  FUNCCALL(SETUP_XfOrM420(_), scheme_set_in_read_mark (src , for_read ) ); 
  special = FUNCCALL_AGAIN(scheme_apply (special , cnt , a ) ); 
  FUNCCALL_AGAIN(scheme_pop_continuation_frame (& cframe ) ); 
  RET_VALUE_START (special ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_get_ready_special (Scheme_Object * port , Scheme_Object * stxsrc , int peek , Scheme_Hash_Table * * ht ) {
  long line , col , pos ; 
  PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(stxsrc, 0), PUSH(ht, 1), PUSH(port, 2)));
# define XfOrM427_COUNT (3)
# define SETUP_XfOrM427(x) SETUP(XfOrM427_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! stxsrc ) {
    Scheme_Input_Port * ip ; 
    BLOCK_SETUP((PUSH(ip, 0+XfOrM427_COUNT)));
#   define XfOrM428_COUNT (1+XfOrM427_COUNT)
#   define SETUP_XfOrM428(x) SETUP(XfOrM428_COUNT)
    ip = NULLED_OUT ; 
    ip = FUNCCALL(SETUP_XfOrM428(_), scheme_input_port_record (port ) ); 
    stxsrc = ip -> name ; 
  }
  line = FUNCCALL(SETUP_XfOrM427(_), scheme_tell_line (port ) ); 
  col = FUNCCALL(SETUP_XfOrM427(_), scheme_tell_column (port ) ); 
  pos = FUNCCALL_AGAIN(scheme_tell (port ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_get_special (port , stxsrc , line , col , pos , peek , ht ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_get_ready_read_special (Scheme_Object * port , Scheme_Object * stxsrc , Scheme_Hash_Table * * ht ) {
  /* No conversion */
  return do_get_ready_special (port , stxsrc , 0 , ht ) ; 
}
Scheme_Object * scheme_get_ready_special (Scheme_Object * port , Scheme_Object * stxsrc , int peek ) {
  /* No conversion */
  return do_get_ready_special (port , stxsrc , peek , ((void * ) 0 ) ) ; 
}
void scheme_bad_time_for_special (const char * who , Scheme_Object * port ) {
  /* No conversion */
  scheme_arg_mismatch (who , "non-character in an unsupported context, from port: " , port ) ; 
}
static Scheme_Object * check_special_args (void * sbox , int argc , Scheme_Object * * argv ) {
  Scheme_Object * special ; 
  Scheme_Cont_Frame_Data cframe ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(cframe.cache, 1), PUSH(special, 2), PUSH(sbox, 3)));
# define XfOrM432_COUNT (4)
# define SETUP_XfOrM432(x) SETUP(XfOrM432_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  special = NULLED_OUT ; 
  cframe.cache = NULLED_OUT ; 
  if ((! (((argv [1 ] ) ) == (scheme_false ) ) ) )
    if (! FUNCCALL(SETUP_XfOrM432(_), scheme_nonneg_exact_p (argv [1 ] ) )|| (((argv [1 ] ) == (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) ) ) )
    FUNCCALL(SETUP_XfOrM432(_), scheme_wrong_type ("read-special" , "positive exact integer or #f" , 1 , argc , argv ) ); 
  if ((! (((argv [2 ] ) ) == (scheme_false ) ) ) )
    if (! FUNCCALL(SETUP_XfOrM432(_), scheme_nonneg_exact_p (argv [2 ] ) ))
    FUNCCALL(SETUP_XfOrM432(_), scheme_wrong_type ("read-special" , "non-negative exact integer or #f" , 2 , argc , argv ) ); 
  if ((! (((argv [3 ] ) ) == (scheme_false ) ) ) )
    if (! FUNCCALL(SETUP_XfOrM432(_), scheme_nonneg_exact_p (argv [3 ] ) )|| (((argv [3 ] ) == (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) ) ) )
    FUNCCALL(SETUP_XfOrM432(_), scheme_wrong_type ("read-special" , "positive exact integer or #f" , 3 , argc , argv ) ); 
  special = * (Scheme_Object * * ) sbox ; 
  if (! special )
    FUNCCALL(SETUP_XfOrM432(_), scheme_raise_exn (MZEXN_FAIL_CONTRACT , "read-special: cannot be called a second time" ) ); 
  * (Scheme_Object * * ) sbox = ((void * ) 0 ) ; 
  FUNCCALL(SETUP_XfOrM432(_), scheme_push_continuation_frame (& cframe ) ); 
  FUNCCALL_AGAIN(scheme_set_in_read_mark (((void * ) 0 ) , ((void * ) 0 ) ) ); 
  special = FUNCCALL_AGAIN(scheme_do_eval (special , 4 , argv , 1 ) ); 
  FUNCCALL_AGAIN(scheme_pop_continuation_frame (& cframe ) ); 
  RET_VALUE_START (special ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_get_special_proc (Scheme_Object * inport ) {
  Scheme_Object * special , * * sbox ; 
  Scheme_Input_Port * ip ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(sbox, 0), PUSH(special, 1), PUSH(ip, 2)));
# define XfOrM433_COUNT (3)
# define SETUP_XfOrM433(x) SETUP(XfOrM433_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  special = NULLED_OUT ; 
  sbox = NULLED_OUT ; 
  ip = NULLED_OUT ; 
  ip = FUNCCALL(SETUP_XfOrM433(_), scheme_input_port_record (inport ) ); 
  special = ip -> special ; 
  ip -> special = ((void * ) 0 ) ; 
  sbox = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM433(_), GC_malloc (sizeof (Scheme_Object * ) * (1 ) ) )) ; 
  * sbox = special ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_closed_prim_w_arity (check_special_args , sbox , "read-special" , 4 , 4 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_need_wakeup (Scheme_Object * port , void * fds ) {
  Scheme_Input_Port * ip ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(fds, 0), PUSH(ip, 1)));
# define XfOrM434_COUNT (2)
# define SETUP_XfOrM434(x) SETUP(XfOrM434_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ip = NULLED_OUT ; 
  ip = FUNCCALL(SETUP_XfOrM434(_), scheme_input_port_record (port ) ); 
  if (ip -> need_wakeup_fun ) {
    Scheme_Need_Wakeup_Input_Fun f = ip -> need_wakeup_fun ; 
#   define XfOrM435_COUNT (0+XfOrM434_COUNT)
#   define SETUP_XfOrM435(x) SETUP_XfOrM434(x)
    FUNCCALL_EMPTY(f (ip , fds ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
long scheme_tell (Scheme_Object * port ) {
  Scheme_Port * ip ; 
  long pos ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(ip, 0)));
# define XfOrM436_COUNT (1)
# define SETUP_XfOrM436(x) SETUP(XfOrM436_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ip = NULLED_OUT ; 
  ip = FUNCCALL(SETUP_XfOrM436(_), scheme_port_record (port ) ); 
  if (((Scheme_Type ) (((((long ) ((Scheme_Object * ) ip ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((Scheme_Object * ) ip ) ) -> type ) ) == (Scheme_Type ) (scheme_input_port_type ) ) ) {
#   define XfOrM438_COUNT (0+XfOrM436_COUNT)
#   define SETUP_XfOrM438(x) SETUP_XfOrM436(x)
    if (((Scheme_Input_Port * ) ip ) -> closed )
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL , "%s: " "input" " port is closed" , "get-file-position" ) ); 
    ; 
  }
  else {
#   define XfOrM437_COUNT (0+XfOrM436_COUNT)
#   define SETUP_XfOrM437(x) SETUP_XfOrM436(x)
    if (((Scheme_Output_Port * ) ip ) -> closed )
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL , "%s: " "output" " port is closed" , "get-file-position" ) ); 
    ; 
  }
  ; 
  if (! ip -> count_lines || (ip -> position < 0 ) )
    pos = ip -> position ; 
  else pos = ip -> readpos ; 
  RET_VALUE_START (pos ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
long scheme_tell_line (Scheme_Object * port ) {
  Scheme_Port * ip ; 
  long line ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(ip, 0)));
# define XfOrM439_COUNT (1)
# define SETUP_XfOrM439(x) SETUP(XfOrM439_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ip = NULLED_OUT ; 
  ip = FUNCCALL(SETUP_XfOrM439(_), scheme_port_record (port ) ); 
  if (! ip -> count_lines || (ip -> position < 0 ) )
    RET_VALUE_START (- 1 ) RET_VALUE_END ; 
  if (((Scheme_Type ) (((((long ) ((Scheme_Object * ) ip ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((Scheme_Object * ) ip ) ) -> type ) ) == (Scheme_Type ) (scheme_input_port_type ) ) ) {
#   define XfOrM441_COUNT (0+XfOrM439_COUNT)
#   define SETUP_XfOrM441(x) SETUP_XfOrM439(x)
    if (((Scheme_Input_Port * ) ip ) -> closed )
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL , "%s: " "input" " port is closed" , "get-file-line" ) ); 
    ; 
  }
  else {
#   define XfOrM440_COUNT (0+XfOrM439_COUNT)
#   define SETUP_XfOrM440(x) SETUP_XfOrM439(x)
    if (((Scheme_Output_Port * ) ip ) -> closed )
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL , "%s: " "output" " port is closed" , "get-file-line" ) ); 
    ; 
  }
  ; 
  line = ip -> lineNumber ; 
  RET_VALUE_START (line ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
long scheme_tell_column (Scheme_Object * port ) {
  Scheme_Port * ip ; 
  long col ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(ip, 0)));
# define XfOrM442_COUNT (1)
# define SETUP_XfOrM442(x) SETUP(XfOrM442_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ip = NULLED_OUT ; 
  ip = FUNCCALL(SETUP_XfOrM442(_), scheme_port_record (port ) ); 
  if (! ip -> count_lines || (ip -> position < 0 ) )
    RET_VALUE_START (- 1 ) RET_VALUE_END ; 
  if (((Scheme_Type ) (((((long ) ((Scheme_Object * ) ip ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((Scheme_Object * ) ip ) ) -> type ) ) == (Scheme_Type ) (scheme_input_port_type ) ) ) {
#   define XfOrM444_COUNT (0+XfOrM442_COUNT)
#   define SETUP_XfOrM444(x) SETUP_XfOrM442(x)
    if (((Scheme_Input_Port * ) ip ) -> closed )
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL , "%s: " "input" " port is closed" , "get-file-column" ) ); 
    ; 
  }
  else {
#   define XfOrM443_COUNT (0+XfOrM442_COUNT)
#   define SETUP_XfOrM443(x) SETUP_XfOrM442(x)
    if (((Scheme_Output_Port * ) ip ) -> closed )
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL , "%s: " "output" " port is closed" , "get-file-column" ) ); 
    ; 
  }
  ; 
  col = ip -> column ; 
  RET_VALUE_START (col ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_tell_all (Scheme_Object * port , long * _line , long * _col , long * _pos ) {
  Scheme_Port * ip ; 
  long line = - 1 , col = - 1 , pos = - 1 ; 
  PREPARE_VAR_STACK(9);
  BLOCK_SETUP_TOP((PUSH(_pos, 0), PUSH(port, 1), PUSH(_col, 2), PUSH(_line, 3), PUSH(ip, 4)));
# define XfOrM445_COUNT (5)
# define SETUP_XfOrM445(x) SETUP(XfOrM445_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  ip = NULLED_OUT ; 
  ip = FUNCCALL(SETUP_XfOrM445(_), scheme_port_record (port ) ); 
  if (ip -> count_lines && ip -> location_fun ) {
    Scheme_Location_Fun location_fun ; 
    Scheme_Object * r , * a [3 ] ; 
    long v ; 
    int got , i ; 
    BLOCK_SETUP((PUSH(r, 0+XfOrM445_COUNT), PUSHARRAY(a, 3, 1+XfOrM445_COUNT)));
#   define XfOrM447_COUNT (4+XfOrM445_COUNT)
#   define SETUP_XfOrM447(x) SETUP(XfOrM447_COUNT)
    r = NULLED_OUT ; 
    a[0] = NULLED_OUT ; 
    a[1] = NULLED_OUT ; 
    a[2] = NULLED_OUT ; 
    location_fun = ip -> location_fun ; 
    r = FUNCCALL(SETUP_XfOrM447(_), location_fun (ip ) ); 
    got = (((r ) == (((Scheme_Object * ) 0x6 ) ) ) ? (scheme_current_thread -> ku . multiple . count ) : 1 ) ; 
    if (got != 3 ) {
#     define XfOrM460_COUNT (0+XfOrM447_COUNT)
#     define SETUP_XfOrM460(x) SETUP_XfOrM447(x)
      FUNCCALL(SETUP_XfOrM460(_), scheme_wrong_return_arity ("user port next-location" , 3 , got , (got == 1 ) ? (Scheme_Object * * ) r : (scheme_current_thread -> ku . multiple . array ) , "calling port-next-location procedure" ) ); 
      RET_NOTHING ; 
    }
    a [0 ] = (scheme_current_thread -> ku . multiple . array ) [0 ] ; 
    a [1 ] = (scheme_current_thread -> ku . multiple . array ) [1 ] ; 
    a [2 ] = (scheme_current_thread -> ku . multiple . array ) [2 ] ; 
    for (i = 0 ; i < 3 ; i ++ ) {
#     define XfOrM454_COUNT (0+XfOrM447_COUNT)
#     define SETUP_XfOrM454(x) SETUP_XfOrM447(x)
      v = - 1 ; 
      if ((! (((a [i ] ) ) == (scheme_false ) ) ) ) {
#       define XfOrM456_COUNT (0+XfOrM454_COUNT)
#       define SETUP_XfOrM456(x) SETUP_XfOrM454(x)
        if (FUNCCALL(SETUP_XfOrM456(_), scheme_nonneg_exact_p (a [i ] ) )) {
#         define XfOrM457_COUNT (0+XfOrM456_COUNT)
#         define SETUP_XfOrM457(x) SETUP_XfOrM456(x)
          if ((((long ) (a [i ] ) ) & 0x1 ) ) {
#           define XfOrM458_COUNT (0+XfOrM457_COUNT)
#           define SETUP_XfOrM458(x) SETUP_XfOrM457(x)
            v = (((long ) (a [i ] ) ) >> 1 ) ; 
            if ((i != 1 ) && ! v ) {
#             define XfOrM459_COUNT (0+XfOrM458_COUNT)
#             define SETUP_XfOrM459(x) SETUP_XfOrM458(x)
              a [0 ] = a [i ] ; 
              FUNCCALL(SETUP_XfOrM459(_), scheme_wrong_type ("user port next-location" , ((i == 1 ) ? "non-negative exact integer or #f" : "positive exact integer or #f" ) , - 1 , - 1 , a ) ); 
              RET_NOTHING ; 
            }
          }
        }
      }
      switch (i ) {
        case 0 : line = v ; 
        break ; 
        case 1 : col = v ; 
        break ; 
        case 2 : pos = v ; 
        break ; 
      }
    }
    if (pos > - 1 )
      pos -- ; 
  }
  else {
#   define XfOrM446_COUNT (0+XfOrM445_COUNT)
#   define SETUP_XfOrM446(x) SETUP_XfOrM445(x)
    line = FUNCCALL(SETUP_XfOrM446(_), scheme_tell_line (port ) ); 
    col = FUNCCALL(SETUP_XfOrM446(_), scheme_tell_column (port ) ); 
    pos = FUNCCALL_AGAIN(scheme_tell (port ) ); 
  }
  if (_line )
    * _line = line ; 
  if (_col )
    * _col = col ; 
  if (_pos )
    * _pos = pos ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_count_lines (Scheme_Object * port ) {
  Scheme_Port * ip ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(ip, 0)));
# define XfOrM461_COUNT (1)
# define SETUP_XfOrM461(x) SETUP(XfOrM461_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ip = NULLED_OUT ; 
  ip = FUNCCALL(SETUP_XfOrM461(_), scheme_port_record (port ) ); 
  if (! ip -> count_lines ) {
#   define XfOrM462_COUNT (0+XfOrM461_COUNT)
#   define SETUP_XfOrM462(x) SETUP_XfOrM461(x)
    ip -> count_lines = 1 ; 
    if (ip -> count_lines_fun ) {
      Scheme_Count_Lines_Fun cl = ip -> count_lines_fun ; 
#     define XfOrM463_COUNT (0+XfOrM462_COUNT)
#     define SETUP_XfOrM463(x) SETUP_XfOrM462(x)
      FUNCCALL_EMPTY(cl (ip ) ); 
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_close_input_port (Scheme_Object * port ) {
  Scheme_Input_Port * ip ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(ip, 0)));
# define XfOrM464_COUNT (1)
# define SETUP_XfOrM464(x) SETUP(XfOrM464_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ip = NULLED_OUT ; 
  ip = FUNCCALL(SETUP_XfOrM464(_), scheme_input_port_record (port ) ); 
  if (! ip -> closed ) {
#   define XfOrM465_COUNT (0+XfOrM464_COUNT)
#   define SETUP_XfOrM465(x) SETUP_XfOrM464(x)
    if (ip -> close_fun ) {
      Scheme_Close_Input_Fun f = ip -> close_fun ; 
#     define XfOrM468_COUNT (0+XfOrM465_COUNT)
#     define SETUP_XfOrM468(x) SETUP_XfOrM465(x)
      FUNCCALL(SETUP_XfOrM468(_), f (ip ) ); 
    }
    if (ip -> progress_evt ) {
#     define XfOrM467_COUNT (0+XfOrM465_COUNT)
#     define SETUP_XfOrM467(x) SETUP_XfOrM465(x)
      FUNCCALL(SETUP_XfOrM467(_), scheme_post_sema_all (ip -> progress_evt ) ); 
      ip -> progress_evt = ((void * ) 0 ) ; 
    }
    if (ip -> mref ) {
#     define XfOrM466_COUNT (0+XfOrM465_COUNT)
#     define SETUP_XfOrM466(x) SETUP_XfOrM465(x)
      FUNCCALL(SETUP_XfOrM466(_), scheme_remove_managed (ip -> mref , (Scheme_Object * ) ip ) ); 
      ip -> mref = ((void * ) 0 ) ; 
    }
    ip -> closed = 1 ; 
    ip -> ungotten_count = 0 ; 
    ip -> ungotten_special = ((void * ) 0 ) ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void force_close_input_port (Scheme_Object * port ) {
  /* No conversion */
  scheme_force_port_closed = 1 ; 
  scheme_close_input_port (port ) ; 
  scheme_force_port_closed = 0 ; 
}
int scheme_close_should_force_port_closed () {
  /* No conversion */
  return scheme_force_port_closed ; 
}
long scheme_put_byte_string (const char * who , Scheme_Object * port , const char * str , long d , long len , int rarely_block ) {
  Scheme_Output_Port * op ; 
  Scheme_Write_String_Fun ws ; 
  long out , llen , oout ; 
  int enable_break ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(op, 0), PUSH(str, 1), PUSH(who, 2)));
# define XfOrM471_COUNT (3)
# define SETUP_XfOrM471(x) SETUP(XfOrM471_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  op = NULLED_OUT ; 
  op = FUNCCALL(SETUP_XfOrM471(_), scheme_output_port_record (port ) ); 
  if (op -> closed )
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL , "%s: " "output" " port is closed" , who ) ); 
  ; 
  ws = op -> write_string_fun ; 
  if (rarely_block == - 1 ) {
    enable_break = 1 ; 
    rarely_block = 1 ; 
  }
  else enable_break = 0 ; 
  if (enable_break ) {
#   define XfOrM478_COUNT (0+XfOrM471_COUNT)
#   define SETUP_XfOrM478(x) SETUP_XfOrM471(x)
    if (scheme_current_thread -> external_break ) {
#     define XfOrM479_COUNT (0+XfOrM478_COUNT)
#     define SETUP_XfOrM479(x) SETUP_XfOrM478(x)
      FUNCCALL(SETUP_XfOrM479(_), scheme_thread_block_enable_break (0.0 , 1 ) ); 
      scheme_current_thread -> ran_some = 1 ; 
    }
  }
  if ((rarely_block == 1 ) && ! len )
    rarely_block = 0 ; 
  llen = len ; 
  oout = 0 ; 
  while (llen || ! len ) {
#   define XfOrM475_COUNT (0+XfOrM471_COUNT)
#   define SETUP_XfOrM475(x) SETUP_XfOrM471(x)
    out = FUNCCALL(SETUP_XfOrM475(_), ws (op , str , d , llen , rarely_block , enable_break ) ); 
    if (! out ) {
#     define XfOrM477_COUNT (0+XfOrM475_COUNT)
#     define SETUP_XfOrM477(x) SETUP_XfOrM475(x)
      if (op -> closed )
        FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL , "%s: " "output" " port is closed" , who ) ); 
      ; 
    }
    if (out > 0 ) {
#     define XfOrM476_COUNT (0+XfOrM475_COUNT)
#     define SETUP_XfOrM476(x) SETUP_XfOrM475(x)
      op -> p . position += out ; 
      oout += out ; 
      if (op -> p . count_lines )
        (do_count_lines ((Scheme_Port * ) op , str , d , out ) ) ; 
    }
    if (rarely_block || ! len )
      break ; 
    llen -= out ; 
    d += out ; 
  }
  ; 
  ; 
  RET_VALUE_START (oout ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_write_byte_string (const char * str , long len , Scheme_Object * port ) {
  /* No conversion */
  (void ) scheme_put_byte_string ("write-string" , port , str , 0 , len , 0 ) ; 
}
void scheme_write_char_string (const mzchar * str , long len , Scheme_Object * port ) {
  long blen ; 
  char * bstr , buf [64 ] ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(port, 0), PUSH(bstr, 1)));
# define XfOrM482_COUNT (2)
# define SETUP_XfOrM482(x) SETUP(XfOrM482_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  bstr = NULLED_OUT ; 
  bstr = FUNCCALL(SETUP_XfOrM482(_), scheme_utf8_encode_to_buffer_len (str , len , buf , 64 , & blen ) ); 
  FUNCCALL_EMPTY(scheme_write_byte_string (bstr , blen , port ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
long scheme_put_char_string (const char * who , Scheme_Object * port , const mzchar * str , long d , long len ) {
  long blen ; 
  char * bstr , buf [64 ] ; 
  PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(port, 0), PUSH(str, 1), PUSH(bstr, 2), PUSH(who, 3)));
# define XfOrM483_COUNT (4)
# define SETUP_XfOrM483(x) SETUP(XfOrM483_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  bstr = NULLED_OUT ; 
  blen = FUNCCALL(SETUP_XfOrM483(_), scheme_utf8_encode (str , d , d + len , ((void * ) 0 ) , 0 , 0 ) ); 
  if (blen < 64 )
    bstr = buf ; 
  else bstr = (char * ) FUNCCALL(SETUP_XfOrM483(_), GC_malloc_atomic (blen ) ); 
  FUNCCALL(SETUP_XfOrM483(_), scheme_utf8_encode (str , d , d + len , (unsigned char * ) bstr , 0 , 0 ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_put_byte_string (who , port , bstr , 0 , blen , 0 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
long scheme_output_tell (Scheme_Object * port ) {
  /* No conversion */
  return scheme_tell (port ) ; 
}
void scheme_close_output_port (Scheme_Object * port ) {
  Scheme_Output_Port * op ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(op, 0)));
# define XfOrM485_COUNT (1)
# define SETUP_XfOrM485(x) SETUP(XfOrM485_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  op = NULLED_OUT ; 
  op = FUNCCALL(SETUP_XfOrM485(_), scheme_output_port_record (port ) ); 
  if (! op -> closed ) {
#   define XfOrM486_COUNT (0+XfOrM485_COUNT)
#   define SETUP_XfOrM486(x) SETUP_XfOrM485(x)
    if (op -> close_fun ) {
      Scheme_Close_Output_Fun f = op -> close_fun ; 
#     define XfOrM488_COUNT (0+XfOrM486_COUNT)
#     define SETUP_XfOrM488(x) SETUP_XfOrM486(x)
      FUNCCALL(SETUP_XfOrM488(_), f (op ) ); 
    }
    if (op -> mref ) {
#     define XfOrM487_COUNT (0+XfOrM486_COUNT)
#     define SETUP_XfOrM487(x) SETUP_XfOrM486(x)
      FUNCCALL(SETUP_XfOrM487(_), scheme_remove_managed (op -> mref , (Scheme_Object * ) op ) ); 
      op -> mref = ((void * ) 0 ) ; 
    }
    op -> closed = 1 ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void force_close_output_port (Scheme_Object * port ) {
  /* No conversion */
  scheme_force_port_closed = 1 ; 
  scheme_close_output_port (port ) ; 
  scheme_force_port_closed = 0 ; 
}
void scheme_flush_orig_outputs (void ) {
  /* No conversion */
  scheme_flush_output (scheme_orig_stdout_port ) ; 
  scheme_flush_output (scheme_orig_stderr_port ) ; 
}
void scheme_flush_output (Scheme_Object * o ) {
  /* No conversion */
  scheme_put_byte_string ("flush-output" , o , ((void * ) 0 ) , 0 , 0 , 0 ) ; 
}
Scheme_Object * scheme_file_stream_port_p (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * p = argv [0 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(p, 1)));
# define XfOrM492_COUNT (2)
# define SETUP_XfOrM492(x) SETUP(XfOrM492_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((scheme_is_input_port (p ) ) ) {
    Scheme_Input_Port * ip ; 
    BLOCK_SETUP((PUSH(ip, 0+XfOrM492_COUNT)));
#   define XfOrM495_COUNT (1+XfOrM492_COUNT)
#   define SETUP_XfOrM495(x) SETUP(XfOrM495_COUNT)
    ip = NULLED_OUT ; 
    ip = FUNCCALL(SETUP_XfOrM495(_), scheme_input_port_record (p ) ); 
    if (((ip -> sub_type ) == (file_input_port_type ) ) )
      RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
    else if (((ip -> sub_type ) == (fd_input_port_type ) ) )
      RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
  }
  else if ((scheme_is_output_port (p ) ) ) {
    Scheme_Output_Port * op ; 
    BLOCK_SETUP((PUSH(op, 0+XfOrM492_COUNT)));
#   define XfOrM494_COUNT (1+XfOrM492_COUNT)
#   define SETUP_XfOrM494(x) SETUP(XfOrM494_COUNT)
    op = NULLED_OUT ; 
    op = FUNCCALL(SETUP_XfOrM494(_), scheme_output_port_record (p ) ); 
    if (((op -> sub_type ) == (file_output_port_type ) ) )
      RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
    else if (((op -> sub_type ) == (fd_output_port_type ) ) )
      RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM493_COUNT (0+XfOrM492_COUNT)
#   define SETUP_XfOrM493(x) SETUP_XfOrM492(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("file-stream-port?" , "port" , 0 , argc , argv ) ); 
  }
  RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_get_port_file_descriptor (Scheme_Object * p , long * _fd ) {
  long fd = 0 ; 
  int fd_ok = 0 ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(_fd, 0), PUSH(p, 1)));
# define XfOrM496_COUNT (2)
# define SETUP_XfOrM496(x) SETUP(XfOrM496_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((scheme_is_input_port (p ) ) ) {
    Scheme_Input_Port * ip ; 
    BLOCK_SETUP((PUSH(ip, 0+XfOrM496_COUNT)));
#   define XfOrM501_COUNT (1+XfOrM496_COUNT)
#   define SETUP_XfOrM501(x) SETUP(XfOrM501_COUNT)
    ip = NULLED_OUT ; 
    ip = FUNCCALL(SETUP_XfOrM501(_), scheme_input_port_record (p ) ); 
    if (! ip -> closed ) {
#     define XfOrM502_COUNT (0+XfOrM501_COUNT)
#     define SETUP_XfOrM502(x) SETUP_XfOrM501(x)
      if (((ip -> sub_type ) == (file_input_port_type ) ) ) {
#       define XfOrM504_COUNT (0+XfOrM502_COUNT)
#       define SETUP_XfOrM504(x) SETUP_XfOrM502(x)
        fd = FUNCCALL(SETUP_XfOrM504(_), fileno ((FILE * ) ((Scheme_Input_File * ) ip -> port_data ) -> f ) ); 
        fd_ok = 1 ; 
      }
      else if (((ip -> sub_type ) == (fd_input_port_type ) ) ) {
        fd = ((Scheme_FD * ) ip -> port_data ) -> fd ; 
        fd_ok = 1 ; 
      }
    }
  }
  else if ((scheme_is_output_port (p ) ) ) {
    Scheme_Output_Port * op ; 
    BLOCK_SETUP((PUSH(op, 0+XfOrM496_COUNT)));
#   define XfOrM497_COUNT (1+XfOrM496_COUNT)
#   define SETUP_XfOrM497(x) SETUP(XfOrM497_COUNT)
    op = NULLED_OUT ; 
    op = FUNCCALL(SETUP_XfOrM497(_), scheme_output_port_record (p ) ); 
    if (! op -> closed ) {
#     define XfOrM498_COUNT (0+XfOrM497_COUNT)
#     define SETUP_XfOrM498(x) SETUP_XfOrM497(x)
      if (((op -> sub_type ) == (file_output_port_type ) ) ) {
#       define XfOrM500_COUNT (0+XfOrM498_COUNT)
#       define SETUP_XfOrM500(x) SETUP_XfOrM498(x)
        fd = FUNCCALL(SETUP_XfOrM500(_), fileno ((FILE * ) ((Scheme_Output_File * ) op -> port_data ) -> f ) ); 
        fd_ok = 1 ; 
      }
      else if (((op -> sub_type ) == (fd_output_port_type ) ) ) {
        fd = ((Scheme_FD * ) op -> port_data ) -> fd ; 
        fd_ok = 1 ; 
      }
    }
  }
  if (! fd_ok )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  * _fd = fd ; 
  RET_VALUE_START (1 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
long scheme_get_port_fd (Scheme_Object * p ) {
  /* No conversion */
  long fd ; 
  if (scheme_get_port_file_descriptor (p , & fd ) )
    return fd ; 
  else return - 1 ; 
}
Scheme_Object * scheme_file_identity (int argc , Scheme_Object * argv [] ) {
  long fd = 0 ; 
  int fd_ok = 0 ; 
  Scheme_Object * p ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(p, 1)));
# define XfOrM506_COUNT (2)
# define SETUP_XfOrM506(x) SETUP(XfOrM506_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  p = NULLED_OUT ; 
  p = argv [0 ] ; 
  fd_ok = FUNCCALL(SETUP_XfOrM506(_), scheme_get_port_file_descriptor (p , & fd ) ); 
  if (! fd_ok ) {
#   define XfOrM507_COUNT (0+XfOrM506_COUNT)
#   define SETUP_XfOrM507(x) SETUP_XfOrM506(x)
    if ((scheme_is_input_port (p ) ) ) {
      Scheme_Input_Port * ip ; 
      BLOCK_SETUP((PUSH(ip, 0+XfOrM507_COUNT)));
#     define XfOrM509_COUNT (1+XfOrM507_COUNT)
#     define SETUP_XfOrM509(x) SETUP(XfOrM509_COUNT)
      ip = NULLED_OUT ; 
      ip = FUNCCALL(SETUP_XfOrM509(_), scheme_input_port_record (p ) ); 
      if (ip -> closed )
        FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL , "%s: " "input" " port is closed" , "port-file-identity" ) ); 
      ; 
    }
    else if ((scheme_is_output_port (p ) ) ) {
      Scheme_Output_Port * op ; 
      BLOCK_SETUP((PUSH(op, 0+XfOrM507_COUNT)));
#     define XfOrM508_COUNT (1+XfOrM507_COUNT)
#     define SETUP_XfOrM508(x) SETUP(XfOrM508_COUNT)
      op = NULLED_OUT ; 
      op = FUNCCALL(SETUP_XfOrM508(_), scheme_output_port_record (p ) ); 
      if (op -> closed )
        FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL , "%s: " "output" " port is closed" , "port-file-identity" ) ); 
      ; 
    }
    FUNCCALL_EMPTY(scheme_wrong_type ("port-file-identity" , "file-stream-port" , 0 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_get_fd_identity (p , fd ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int is_fd_terminal (int fd ) {
  /* No conversion */
  return isatty (fd ) ; 
}
Scheme_Object * scheme_terminal_port_p (int argc , Scheme_Object * argv [] ) {
  long fd = 0 ; 
  int fd_ok = 0 ; 
  Scheme_Object * p ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(p, 0)));
# define XfOrM511_COUNT (1)
# define SETUP_XfOrM511(x) SETUP(XfOrM511_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  p = NULLED_OUT ; 
  p = argv [0 ] ; 
  if ((scheme_is_input_port (p ) ) ) {
    Scheme_Input_Port * ip ; 
    BLOCK_SETUP((PUSH(ip, 0+XfOrM511_COUNT)));
#   define XfOrM515_COUNT (1+XfOrM511_COUNT)
#   define SETUP_XfOrM515(x) SETUP(XfOrM515_COUNT)
    ip = NULLED_OUT ; 
    ip = FUNCCALL(SETUP_XfOrM515(_), scheme_input_port_record (p ) ); 
    if (ip -> closed )
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    if (((ip -> sub_type ) == (file_input_port_type ) ) ) {
#     define XfOrM517_COUNT (0+XfOrM515_COUNT)
#     define SETUP_XfOrM517(x) SETUP_XfOrM515(x)
      fd = FUNCCALL(SETUP_XfOrM517(_), fileno ((FILE * ) ((Scheme_Input_File * ) ip -> port_data ) -> f ) ); 
      fd_ok = 1 ; 
    }
    else if (((ip -> sub_type ) == (fd_input_port_type ) ) ) {
      fd = ((Scheme_FD * ) ip -> port_data ) -> fd ; 
      fd_ok = 1 ; 
    }
  }
  else if ((scheme_is_output_port (p ) ) ) {
    Scheme_Output_Port * op ; 
    BLOCK_SETUP((PUSH(op, 0+XfOrM511_COUNT)));
#   define XfOrM512_COUNT (1+XfOrM511_COUNT)
#   define SETUP_XfOrM512(x) SETUP(XfOrM512_COUNT)
    op = NULLED_OUT ; 
    op = FUNCCALL(SETUP_XfOrM512(_), scheme_output_port_record (p ) ); 
    if (op -> closed )
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    if (((op -> sub_type ) == (file_output_port_type ) ) ) {
#     define XfOrM514_COUNT (0+XfOrM512_COUNT)
#     define SETUP_XfOrM514(x) SETUP_XfOrM512(x)
      fd = FUNCCALL(SETUP_XfOrM514(_), fileno ((FILE * ) ((Scheme_Output_File * ) op -> port_data ) -> f ) ); 
      fd_ok = 1 ; 
    }
    else if (((op -> sub_type ) == (fd_output_port_type ) ) ) {
      fd = ((Scheme_FD * ) op -> port_data ) -> fd ; 
      fd_ok = 1 ; 
    }
  }
  if (! fd_ok )
    RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
  RET_VALUE_START (FUNCCALL_EMPTY(is_fd_terminal (fd ) )? scheme_true : scheme_false ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void filename_exn (char * name , char * msg , char * filename , int err ) {
  char * dir , * drive ; 
  int len ; 
  char * pre , * rel , * post ; 
  PREPARE_VAR_STACK_ONCE(8);
  BLOCK_SETUP_TOP((PUSH(name, 0), PUSH(pre, 1), PUSH(msg, 2), PUSH(post, 3), PUSH(drive, 4), PUSH(filename, 5), PUSH(rel, 6), PUSH(dir, 7)));
# define XfOrM518_COUNT (8)
# define SETUP_XfOrM518(x) SETUP(XfOrM518_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  dir = NULLED_OUT ; 
  drive = NULLED_OUT ; 
  pre = NULLED_OUT ; 
  rel = NULLED_OUT ; 
  post = NULLED_OUT ; 
  len = strlen (filename ) ; 
  if (FUNCCALL(SETUP_XfOrM518(_), scheme_is_relative_path (filename , len , scheme_unix_path_type ) )) {
#   define XfOrM521_COUNT (0+XfOrM518_COUNT)
#   define SETUP_XfOrM521(x) SETUP_XfOrM518(x)
    dir = FUNCCALL(SETUP_XfOrM521(_), scheme_os_getcwd (((void * ) 0 ) , 0 , ((void * ) 0 ) , 1 ) ); 
    drive = ((void * ) 0 ) ; 
  }
  else if (FUNCCALL(SETUP_XfOrM518(_), scheme_is_complete_path (filename , len , scheme_unix_path_type ) )) {
    dir = ((void * ) 0 ) ; 
    drive = ((void * ) 0 ) ; 
  }
  else {
#   define XfOrM519_COUNT (0+XfOrM518_COUNT)
#   define SETUP_XfOrM519(x) SETUP_XfOrM518(x)
    dir = ((void * ) 0 ) ; 
    drive = FUNCCALL(SETUP_XfOrM519(_), scheme_getdrive () ); 
  }
  pre = dir ? " in directory \"" : (drive ? " on drive " : "" ) ; 
  rel = dir ? dir : (drive ? drive : "" ) ; 
  post = dir ? "\"" : "" ; 
  FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_FILESYSTEM , "%s: %s: \"%q\"%s%q%s (" "%e" ")" , name , msg , filename , pre , rel , post , err ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_do_open_input_file (char * name , int offset , int argc , Scheme_Object * argv [] ) {
  int fd ; 
  struct stat buf ; 
  char * mode = "rb" ; 
  char * filename ; 
  int regfile , i ; 
  int m_set = 0 ; 
  Scheme_Object * result ; 
  char * __funcarg21 = NULLED_OUT ; 
  Scheme_Object * __funcarg19 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(filename, 0), PUSH(mode, 1), PUSH(argv, 2), PUSH(result, 3), PUSH(name, 4)));
# define XfOrM522_COUNT (5)
# define SETUP_XfOrM522(x) SETUP(XfOrM522_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  filename = NULLED_OUT ; 
  result = NULLED_OUT ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type (name , "path or string" , 0 , argc , argv ) ); 
  for (i = 1 + offset ; argc > i ; i ++ ) {
#   define XfOrM538_COUNT (0+XfOrM522_COUNT)
#   define SETUP_XfOrM538(x) SETUP_XfOrM522(x)
    if (! ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type (name , "symbol" , i , argc , argv ) ); 
    if (((argv [i ] ) == (text_symbol ) ) ) {
      mode = "rt" ; 
      m_set ++ ; 
    }
    else if (((argv [i ] ) == (binary_symbol ) ) ) {
      m_set ++ ; 
    }
    else {
      char * astr ; 
      long alen ; 
      BLOCK_SETUP((PUSH(astr, 0+XfOrM538_COUNT)));
#     define XfOrM540_COUNT (1+XfOrM538_COUNT)
#     define SETUP_XfOrM540(x) SETUP(XfOrM540_COUNT)
      astr = NULLED_OUT ; 
      astr = FUNCCALL(SETUP_XfOrM540(_), scheme_make_args_string ("other " , i , argc , argv , & alen ) ); 
      (__funcarg21 = FUNCCALL(SETUP_XfOrM540(_), scheme_make_provided_string (argv [i ] , 1 , ((void * ) 0 ) ) ), FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: bad mode: %s%t" , name , __funcarg21 , astr , alen ) )) ; 
    }
    if (m_set > 1 ) {
      char * astr ; 
      long alen ; 
      BLOCK_SETUP((PUSH(astr, 0+XfOrM538_COUNT)));
#     define XfOrM539_COUNT (1+XfOrM538_COUNT)
#     define SETUP_XfOrM539(x) SETUP(XfOrM539_COUNT)
      astr = NULLED_OUT ; 
      astr = FUNCCALL(SETUP_XfOrM539(_), scheme_make_args_string ("" , - 1 , argc , argv , & alen ) ); 
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: conflicting or redundant " "file modes given%t" , name , astr , alen ) ); 
    }
  }
  filename = FUNCCALL(SETUP_XfOrM522(_), scheme_expand_string_filename (argv [0 ] , name , ((void * ) 0 ) , 0x1 ) ); 
  FUNCCALL(SETUP_XfOrM522(_), scheme_custodian_check_available (((void * ) 0 ) , name , "file-stream" ) ); 
  do {
#   define XfOrM532_COUNT (0+XfOrM522_COUNT)
#   define SETUP_XfOrM532(x) SETUP_XfOrM522(x)
    fd = FUNCCALL(SETUP_XfOrM532(_), open (filename , 0 | 2048 | 0 ) ); 
  }
  while ((fd == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
  if (fd == - 1 ) {
#   define XfOrM530_COUNT (0+XfOrM522_COUNT)
#   define SETUP_XfOrM530(x) SETUP_XfOrM522(x)
    FUNCCALL(SETUP_XfOrM530(_), filename_exn (name , "cannot open input file" , filename , (* __errno_location () ) ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  else {
    int ok ; 
#   define XfOrM523_COUNT (0+XfOrM522_COUNT)
#   define SETUP_XfOrM523(x) SETUP_XfOrM522(x)
    do {
#     define XfOrM529_COUNT (0+XfOrM523_COUNT)
#     define SETUP_XfOrM529(x) SETUP_XfOrM523(x)
      ok = FUNCCALL(SETUP_XfOrM529(_), fstat (fd , & buf ) ); 
    }
    while ((ok == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
    if (((((buf . st_mode ) ) & 61440 ) == (16384 ) ) ) {
      int cr ; 
#     define XfOrM525_COUNT (0+XfOrM523_COUNT)
#     define SETUP_XfOrM525(x) SETUP_XfOrM523(x)
      do {
        cr = close (fd ) ; 
      }
      while ((cr == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
      FUNCCALL(SETUP_XfOrM525(_), filename_exn (name , "cannot open directory as a file" , filename , 0 ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else {
#     define XfOrM524_COUNT (0+XfOrM523_COUNT)
#     define SETUP_XfOrM524(x) SETUP_XfOrM523(x)
      regfile = ((((buf . st_mode ) ) & 61440 ) == (32768 ) ) ; 
      scheme_file_open_count ++ ; 
      result = (__funcarg19 = FUNCCALL(SETUP_XfOrM524(_), scheme_make_path (filename ) ), FUNCCALL_AGAIN(make_fd_input_port (fd , __funcarg19 , regfile , 0 , ((void * ) 0 ) ) )) ; 
    }
  }
  RET_VALUE_START (result ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_do_open_output_file (char * name , int offset , int argc , Scheme_Object * argv [] , int and_read ) {
  int fd ; 
  int flags , regfile ; 
  struct stat buf ; 
  int ok ; 
  int e_set = 0 , m_set = 0 , i ; 
  int existsok = 0 ; 
  char * filename ; 
  char mode [4 ] ; 
  int typepos ; 
  char * __funcarg24 = NULLED_OUT ; 
  Scheme_Object * __funcarg22 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(filename, 0), PUSH(argv, 1), PUSH(name, 2)));
# define XfOrM543_COUNT (3)
# define SETUP_XfOrM543(x) SETUP(XfOrM543_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  filename = NULLED_OUT ; 
  mode [0 ] = 'w' ; 
  mode [1 ] = 'b' ; 
  mode [2 ] = 0 ; 
  mode [3 ] = 0 ; 
  typepos = 1 ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type (name , "path or string" , 0 , argc , argv ) ); 
  for (i = 1 + offset ; argc > i ; i ++ ) {
#   define XfOrM572_COUNT (0+XfOrM543_COUNT)
#   define SETUP_XfOrM572(x) SETUP_XfOrM543(x)
    if (! ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type (name , "symbol" , i , argc , argv ) ); 
    if (((argv [i ] ) == (append_symbol ) ) ) {
      mode [0 ] = 'a' ; 
      existsok = - 1 ; 
      e_set ++ ; 
    }
    else if (((argv [i ] ) == (replace_symbol ) ) ) {
      existsok = 1 ; 
      e_set ++ ; 
    }
    else if (((argv [i ] ) == (truncate_symbol ) ) ) {
      existsok = - 1 ; 
      e_set ++ ; 
    }
    else if (((argv [i ] ) == (truncate_replace_symbol ) ) ) {
      existsok = - 2 ; 
      e_set ++ ; 
    }
    else if (((argv [i ] ) == (update_symbol ) ) ) {
      existsok = 2 ; 
      if (typepos == 1 ) {
        mode [2 ] = mode [1 ] ; 
        typepos = 2 ; 
      }
      mode [0 ] = 'r' ; 
      mode [1 ] = '+' ; 
      e_set ++ ; 
    }
    else if (((argv [i ] ) == (error_symbol ) ) ) {
      e_set ++ ; 
    }
    else if (((argv [i ] ) == (text_symbol ) ) ) {
      mode [typepos ] = 't' ; 
      m_set ++ ; 
    }
    else if (((argv [i ] ) == (binary_symbol ) ) ) {
      m_set ++ ; 
    }
    else {
      char * astr ; 
      long alen ; 
      BLOCK_SETUP((PUSH(astr, 0+XfOrM572_COUNT)));
#     define XfOrM574_COUNT (1+XfOrM572_COUNT)
#     define SETUP_XfOrM574(x) SETUP(XfOrM574_COUNT)
      astr = NULLED_OUT ; 
      astr = FUNCCALL(SETUP_XfOrM574(_), scheme_make_args_string ("other " , i , argc , argv , & alen ) ); 
      (__funcarg24 = FUNCCALL(SETUP_XfOrM574(_), scheme_make_provided_string (argv [i ] , 1 , ((void * ) 0 ) ) ), FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: bad mode: %s%s" , name , __funcarg24 , astr , alen ) )) ; 
    }
    if (m_set > 1 || e_set > 1 ) {
      char * astr ; 
      long alen ; 
      BLOCK_SETUP((PUSH(astr, 0+XfOrM572_COUNT)));
#     define XfOrM573_COUNT (1+XfOrM572_COUNT)
#     define SETUP_XfOrM573(x) SETUP(XfOrM573_COUNT)
      astr = NULLED_OUT ; 
      astr = FUNCCALL(SETUP_XfOrM573(_), scheme_make_args_string ("" , - 1 , argc , argv , & alen ) ); 
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: conflicting or redundant " "file modes given%t" , name , astr , alen ) ); 
    }
  }
  filename = FUNCCALL(SETUP_XfOrM543(_), scheme_expand_string_filename (argv [0 ] , name , ((void * ) 0 ) , (0x2 | ((existsok && (existsok != - 1 ) ) ? 0x8 : 0 ) | ((mode [0 ] == 'a' ) ? 0x1 : 0 ) | ((existsok > 1 ) ? 0x1 : 0 ) ) ) ); 
  FUNCCALL(SETUP_XfOrM543(_), scheme_custodian_check_available (((void * ) 0 ) , name , "file-stream" ) ); 
  flags = (and_read ? 2 : 1 ) | 64 ; 
  if (mode [0 ] == 'a' )
    flags |= 1024 ; 
  else if (existsok < 0 )
    flags |= 512 ; 
  if (existsok > 1 )
    flags -= 64 ; 
  else if (existsok > - 1 )
    flags |= 128 ; 
  do {
#   define XfOrM559_COUNT (0+XfOrM543_COUNT)
#   define SETUP_XfOrM559(x) SETUP_XfOrM543(x)
    fd = FUNCCALL(SETUP_XfOrM559(_), open (filename , flags | 2048 | 0 , 438 ) ); 
  }
  while ((fd == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
  if ((* __errno_location () ) == 6 ) {
#   define XfOrM555_COUNT (0+XfOrM543_COUNT)
#   define SETUP_XfOrM555(x) SETUP_XfOrM543(x)
    flags -= 1 ; 
    flags |= 2 ; 
    do {
#     define XfOrM557_COUNT (0+XfOrM555_COUNT)
#     define SETUP_XfOrM557(x) SETUP_XfOrM555(x)
      fd = FUNCCALL(SETUP_XfOrM557(_), open (filename , flags | 2048 | 0 , 438 ) ); 
    }
    while ((fd == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
  }
  if (fd == - 1 ) {
#   define XfOrM546_COUNT (0+XfOrM543_COUNT)
#   define SETUP_XfOrM546(x) SETUP_XfOrM543(x)
    if ((* __errno_location () ) == 21 ) {
#     define XfOrM554_COUNT (0+XfOrM546_COUNT)
#     define SETUP_XfOrM554(x) SETUP_XfOrM546(x)
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_FILESYSTEM_EXISTS , "%s: \"%q\" exists as a directory" , name , filename ) ); 
    }
    else if ((* __errno_location () ) == 17 ) {
#     define XfOrM548_COUNT (0+XfOrM546_COUNT)
#     define SETUP_XfOrM548(x) SETUP_XfOrM546(x)
      if (! existsok )
        FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_FILESYSTEM_EXISTS , "%s: file \"%q\" exists" , name , filename ) ); 
      else {
#       define XfOrM549_COUNT (0+XfOrM548_COUNT)
#       define SETUP_XfOrM549(x) SETUP_XfOrM548(x)
        do {
#         define XfOrM553_COUNT (0+XfOrM549_COUNT)
#         define SETUP_XfOrM553(x) SETUP_XfOrM549(x)
          ok = FUNCCALL(SETUP_XfOrM553(_), unlink (filename ) ); 
        }
        while ((ok == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
        if (ok )
          FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_FILESYSTEM , "%s: error deleting \"%q\"" , name , filename ) ); 
        do {
#         define XfOrM551_COUNT (0+XfOrM549_COUNT)
#         define SETUP_XfOrM551(x) SETUP_XfOrM549(x)
          fd = FUNCCALL(SETUP_XfOrM551(_), open (filename , flags | 0 , 438 ) ); 
        }
        while ((fd == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
      }
    }
    if (fd == - 1 ) {
#     define XfOrM547_COUNT (0+XfOrM546_COUNT)
#     define SETUP_XfOrM547(x) SETUP_XfOrM546(x)
      FUNCCALL(SETUP_XfOrM547(_), filename_exn (name , "cannot open output file" , filename , (* __errno_location () ) ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  do {
#   define XfOrM545_COUNT (0+XfOrM543_COUNT)
#   define SETUP_XfOrM545(x) SETUP_XfOrM543(x)
    ok = FUNCCALL(SETUP_XfOrM545(_), fstat (fd , & buf ) ); 
  }
  while ((ok == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
  regfile = ((((buf . st_mode ) ) & 61440 ) == (32768 ) ) ; 
  scheme_file_open_count ++ ; 
  RET_VALUE_START ((__funcarg22 = FUNCCALL_EMPTY(scheme_make_path (filename ) ), FUNCCALL_EMPTY(make_fd_output_port (fd , __funcarg22 , regfile , 0 , and_read ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_open_input_file (const char * name , const char * who ) {
  Scheme_Object * a [1 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 1, 0), PUSH(who, 3)));
# define XfOrM584_COUNT (4)
# define SETUP_XfOrM584(x) SETUP(XfOrM584_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a [0 ] = FUNCCALL(SETUP_XfOrM584(_), scheme_make_path (name ) ); 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM584(_), scheme_do_open_input_file ((char * ) who , 0 , 1 , a ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_open_output_file (const char * name , const char * who ) {
  Scheme_Object * a [2 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 2, 0), PUSH(who, 3)));
# define XfOrM585_COUNT (4)
# define SETUP_XfOrM585(x) SETUP(XfOrM585_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  a [0 ] = FUNCCALL(SETUP_XfOrM585(_), scheme_make_path (name ) ); 
  a [1 ] = truncate_replace_symbol ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM585(_), scheme_do_open_output_file ((char * ) who , 0 , 2 , a , 0 ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_open_output_file_with_mode (const char * name , const char * who , int text ) {
  Scheme_Object * a [3 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 3, 0), PUSH(who, 3)));
# define XfOrM586_COUNT (4)
# define SETUP_XfOrM586(x) SETUP(XfOrM586_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  a[2] = NULLED_OUT ; 
  a [0 ] = FUNCCALL(SETUP_XfOrM586(_), scheme_make_path (name ) ); 
  a [1 ] = truncate_replace_symbol ; 
  a [2 ] = (text ? text_symbol : binary_symbol ) ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM586(_), scheme_do_open_output_file ((char * ) who , 0 , 3 , a , 0 ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_file_position (int argc , Scheme_Object * argv [] ) {
  FILE * f ; 
  Scheme_Indexed_String * is ; 
  int fd ; 
  int had_fd ; 
  int wis ; 
  char * __funcarg29 = NULLED_OUT ; 
  char * __funcarg28 = NULLED_OUT ; 
  char * __funcarg27 = NULLED_OUT ; 
  char * __funcarg26 = NULLED_OUT ; 
  Scheme_Output_Port * __funcarg25 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(__funcarg28, 0), PUSH(f, 1), PUSH(is, 2), PUSH(argv, 3), PUSH(__funcarg26, 4)));
# define XfOrM587_COUNT (5)
# define SETUP_XfOrM587(x) SETUP(XfOrM587_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  f = NULLED_OUT ; 
  is = NULLED_OUT ; 
  if (! (scheme_is_output_port (argv [0 ] ) ) && ! (scheme_is_input_port (argv [0 ] ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("file-position" , "port" , 0 , argc , argv ) ); 
  if (argc == 2 ) {
#   define XfOrM633_COUNT (0+XfOrM587_COUNT)
#   define SETUP_XfOrM633(x) SETUP_XfOrM587(x)
    if (! (((argv [1 ] ) ) == (scheme_eof ) ) ) {
      int ok = 0 ; 
#     define XfOrM634_COUNT (0+XfOrM633_COUNT)
#     define SETUP_XfOrM634(x) SETUP_XfOrM633(x)
      if ((((long ) (argv [1 ] ) ) & 0x1 ) ) {
        ok = ((((long ) (argv [1 ] ) ) >> 1 ) >= 0 ) ; 
      }
      if (((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) {
        ok = ((& ((Scheme_Bignum * ) argv [1 ] ) -> iso ) -> so . keyex & 0x1 ) ; 
      }
      if (! ok )
        FUNCCALL_EMPTY(scheme_wrong_type ("file-position" , "non-negative exact integer or eof" , 1 , argc , argv ) ); 
    }
  }
  f = ((void * ) 0 ) ; 
  is = ((void * ) 0 ) ; 
  wis = 0 ; 
  fd = 0 ; 
  had_fd = 0 ; 
  if (! (scheme_is_input_port (argv [0 ] ) ) ) {
    Scheme_Output_Port * op ; 
    BLOCK_SETUP((PUSH(op, 0+XfOrM587_COUNT)));
#   define XfOrM629_COUNT (1+XfOrM587_COUNT)
#   define SETUP_XfOrM629(x) SETUP(XfOrM629_COUNT)
    op = NULLED_OUT ; 
    op = FUNCCALL(SETUP_XfOrM629(_), scheme_output_port_record (argv [0 ] ) ); 
    if (((op -> sub_type ) == (file_output_port_type ) ) ) {
      f = ((Scheme_Output_File * ) op -> port_data ) -> f ; 
    }
    else if (((op -> sub_type ) == (fd_output_port_type ) ) ) {
      fd = ((Scheme_FD * ) op -> port_data ) -> fd ; 
      had_fd = 1 ; 
    }
    else if (((op -> sub_type ) == (scheme_string_output_port_type ) ) ) {
      is = (Scheme_Indexed_String * ) op -> port_data ; 
      wis = 1 ; 
    }
    else if (argc < 2 )
      RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (FUNCCALL(SETUP_XfOrM629(_), scheme_output_tell (argv [0 ] ) )) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
  }
  else {
    Scheme_Input_Port * ip ; 
    BLOCK_SETUP((PUSH(ip, 0+XfOrM587_COUNT)));
#   define XfOrM624_COUNT (1+XfOrM587_COUNT)
#   define SETUP_XfOrM624(x) SETUP(XfOrM624_COUNT)
    ip = NULLED_OUT ; 
    ip = FUNCCALL(SETUP_XfOrM624(_), scheme_input_port_record (argv [0 ] ) ); 
    if (((ip -> sub_type ) == (file_input_port_type ) ) ) {
      f = ((Scheme_Input_File * ) ip -> port_data ) -> f ; 
    }
    else if (((ip -> sub_type ) == (fd_input_port_type ) ) ) {
      fd = ((Scheme_FD * ) ip -> port_data ) -> fd ; 
      had_fd = 1 ; 
    }
    else if (((ip -> sub_type ) == (scheme_string_input_port_type ) ) )
      is = (Scheme_Indexed_String * ) ip -> port_data ; 
    else if (argc < 2 ) {
      long pos ; 
#     define XfOrM625_COUNT (0+XfOrM624_COUNT)
#     define SETUP_XfOrM625(x) SETUP_XfOrM624(x)
      pos = ip -> p . position ; 
      if (pos < 0 ) {
#       define XfOrM626_COUNT (0+XfOrM625_COUNT)
#       define SETUP_XfOrM626(x) SETUP_XfOrM625(x)
        FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL , "the port's current position is not known: %v" , ip ) ); 
      }
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_integer_value (pos ) )) RET_VALUE_EMPTY_END ; 
    }
  }
  if (! f && ! had_fd && ! is )
    (__funcarg28 = FUNCCALL(SETUP_XfOrM587(_), scheme_make_provided_string (argv [0 ] , 2 , ((void * ) 0 ) ) ), __funcarg29 = FUNCCALL(SETUP_XfOrM587(_), scheme_make_provided_string (argv [1 ] , 2 , ((void * ) 0 ) ) ), FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "file-position: setting position allowed for file-stream and string ports only;" " given %s and position %s" , __funcarg28 , __funcarg29 ) )) ; 
  if (argc > 1 ) {
    mzlonglong nll ; 
    int whence ; 
#   define XfOrM599_COUNT (0+XfOrM587_COUNT)
#   define SETUP_XfOrM599(x) SETUP_XfOrM587(x)
    if ((((argv [1 ] ) ) == (scheme_eof ) ) ) {
      nll = 0 ; 
      whence = 2 ; 
    }
    else if ((scheme_get_long_long_val (argv [1 ] , & nll ) ) ) {
      whence = 0 ; 
      if ((mzlonglong ) (off_t ) nll != nll ) {
        nll = - 1 ; 
      }
    }
    else {
      whence = 0 ; 
      nll = - 1 ; 
    }
    if (nll < 0 ) {
#     define XfOrM619_COUNT (0+XfOrM599_COUNT)
#     define SETUP_XfOrM619(x) SETUP_XfOrM599(x)
      (__funcarg26 = FUNCCALL(SETUP_XfOrM619(_), scheme_make_provided_string (argv [1 ] , 2 , ((void * ) 0 ) ) ), __funcarg27 = FUNCCALL(SETUP_XfOrM619(_), scheme_make_provided_string (argv [0 ] , 2 , ((void * ) 0 ) ) ), FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "file-position: new position is too large: %s for port: %s" , __funcarg26 , __funcarg27 ) )) ; 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    if (f ) {
#     define XfOrM617_COUNT (0+XfOrM599_COUNT)
#     define SETUP_XfOrM617(x) SETUP_XfOrM599(x)
      if (FUNCCALL(SETUP_XfOrM617(_), fseeko (f , nll , whence ) )) {
#       define XfOrM618_COUNT (0+XfOrM617_COUNT)
#       define SETUP_XfOrM618(x) SETUP_XfOrM617(x)
        FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_FILESYSTEM , "file-position: position change failed on file (%e)" , (* __errno_location () ) ) ); 
      }
    }
    else if (had_fd ) {
      long lv ; 
#     define XfOrM613_COUNT (0+XfOrM599_COUNT)
#     define SETUP_XfOrM613(x) SETUP_XfOrM599(x)
      if (! (scheme_is_input_port (argv [0 ] ) ) ) {
#       define XfOrM616_COUNT (0+XfOrM613_COUNT)
#       define SETUP_XfOrM616(x) SETUP_XfOrM613(x)
        (__funcarg25 = FUNCCALL(SETUP_XfOrM616(_), scheme_output_port_record (argv [0 ] ) ), FUNCCALL_AGAIN(flush_fd (__funcarg25 , ((void * ) 0 ) , 0 , 0 , 0 , 0 ) )) ; 
      }
      lv = FUNCCALL(SETUP_XfOrM613(_), lseek (fd , nll , whence ) ); 
      if (lv < 0 ) {
#       define XfOrM615_COUNT (0+XfOrM613_COUNT)
#       define SETUP_XfOrM615(x) SETUP_XfOrM613(x)
        FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_FILESYSTEM , "file-position: position change failed on stream (" "%e" ")" , (* __errno_location () ) ) ); 
      }
      if ((scheme_is_input_port (argv [0 ] ) ) ) {
        Scheme_FD * sfd ; 
        Scheme_Input_Port * ip ; 
        BLOCK_SETUP((PUSH(ip, 0+XfOrM613_COUNT), PUSH(sfd, 1+XfOrM613_COUNT)));
#       define XfOrM614_COUNT (2+XfOrM613_COUNT)
#       define SETUP_XfOrM614(x) SETUP(XfOrM614_COUNT)
        sfd = NULLED_OUT ; 
        ip = NULLED_OUT ; 
        ip = FUNCCALL(SETUP_XfOrM614(_), scheme_input_port_record (argv [0 ] ) ); 
        sfd = (Scheme_FD * ) ip -> port_data ; 
        sfd -> bufcount = 0 ; 
        sfd -> buffpos = 0 ; 
        ip -> pending_eof = 1 ; 
      }
    }
    else {
      long n ; 
#     define XfOrM602_COUNT (0+XfOrM599_COUNT)
#     define SETUP_XfOrM602(x) SETUP_XfOrM599(x)
      if (whence == 0 ) {
#       define XfOrM611_COUNT (0+XfOrM602_COUNT)
#       define SETUP_XfOrM611(x) SETUP_XfOrM602(x)
        if (! (scheme_get_int_val (argv [1 ] , & n ) ) ) {
#         define XfOrM612_COUNT (0+XfOrM611_COUNT)
#         define SETUP_XfOrM612(x) SETUP_XfOrM611(x)
          FUNCCALL_EMPTY(scheme_raise_out_of_memory (((void * ) 0 ) , ((void * ) 0 ) ) ); 
        }
      }
      else {
        n = 0 ; 
      }
      if (whence == 2 ) {
        if (wis )
          n = is -> u . hot ; 
        else n = is -> size ; 
      }
      if (wis ) {
#       define XfOrM605_COUNT (0+XfOrM602_COUNT)
#       define SETUP_XfOrM605(x) SETUP_XfOrM602(x)
        if (is -> index > is -> u . hot )
          is -> u . hot = is -> index ; 
        if (is -> size < n ) {
          char * old ; 
          BLOCK_SETUP((PUSH(old, 0+XfOrM605_COUNT)));
#         define XfOrM607_COUNT (1+XfOrM605_COUNT)
#         define SETUP_XfOrM607(x) SETUP(XfOrM607_COUNT)
          old = NULLED_OUT ; 
          old = is -> string ; 
          {
            char * ca ; 
            BLOCK_SETUP((PUSH(ca, 0+XfOrM607_COUNT)));
#           define XfOrM608_COUNT (1+XfOrM607_COUNT)
#           define SETUP_XfOrM608(x) SETUP(XfOrM608_COUNT)
            ca = NULLED_OUT ; 
            ca = (char * ) FUNCCALL(SETUP_XfOrM608(_), scheme_malloc_fail_ok (GC_malloc_atomic , n + 1 ) ); 
            is -> string = ca ; 
          }
          is -> size = n ; 
          (memcpy (is -> string , old , is -> u . hot ) ) ; 
        }
        if (n > is -> u . hot ) {
#         define XfOrM606_COUNT (0+XfOrM605_COUNT)
#         define SETUP_XfOrM606(x) SETUP_XfOrM605(x)
          (memset (is -> string + is -> u . hot , 0 , n - is -> u . hot ) ) ; 
          is -> u . hot = n ; 
        }
      }
      else {
        if (n > is -> size ) {
          is -> u . pos = n ; 
          n = is -> size ; 
        }
        else is -> u . pos = 0 ; 
      }
      is -> index = n ; 
    }
    if ((scheme_is_input_port (argv [0 ] ) ) ) {
      Scheme_Input_Port * ip ; 
      BLOCK_SETUP((PUSH(ip, 0+XfOrM599_COUNT)));
#     define XfOrM600_COUNT (1+XfOrM599_COUNT)
#     define SETUP_XfOrM600(x) SETUP(XfOrM600_COUNT)
      ip = NULLED_OUT ; 
      ip = FUNCCALL(SETUP_XfOrM600(_), scheme_input_port_record (argv [0 ] ) ); 
      ip -> ungotten_count = 0 ; 
      if ((pipe_char_count (ip -> peeked_read ) ) ) {
        ip -> peeked_read = ((void * ) 0 ) ; 
        ip -> peeked_write = ((void * ) 0 ) ; 
      }
    }
    RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
  }
  else {
    mzlonglong pll ; 
#   define XfOrM588_COUNT (0+XfOrM587_COUNT)
#   define SETUP_XfOrM588(x) SETUP_XfOrM587(x)
    if (f ) {
#     define XfOrM598_COUNT (0+XfOrM588_COUNT)
#     define SETUP_XfOrM598(x) SETUP_XfOrM588(x)
      pll = FUNCCALL(SETUP_XfOrM598(_), ftello (f ) ); 
    }
    else if (had_fd ) {
#     define XfOrM591_COUNT (0+XfOrM588_COUNT)
#     define SETUP_XfOrM591(x) SETUP_XfOrM588(x)
      pll = FUNCCALL(SETUP_XfOrM591(_), lseek (fd , 0 , 1 ) ); 
      if (pll < 0 ) {
#       define XfOrM595_COUNT (0+XfOrM591_COUNT)
#       define SETUP_XfOrM595(x) SETUP_XfOrM591(x)
        if ((scheme_is_input_port (argv [0 ] ) ) ) {
#         define XfOrM597_COUNT (0+XfOrM595_COUNT)
#         define SETUP_XfOrM597(x) SETUP_XfOrM595(x)
          pll = FUNCCALL(SETUP_XfOrM597(_), scheme_tell (argv [0 ] ) ); 
        }
        else {
#         define XfOrM596_COUNT (0+XfOrM595_COUNT)
#         define SETUP_XfOrM596(x) SETUP_XfOrM595(x)
          pll = FUNCCALL(SETUP_XfOrM596(_), scheme_output_tell (argv [0 ] ) ); 
        }
      }
      else {
#       define XfOrM592_COUNT (0+XfOrM591_COUNT)
#       define SETUP_XfOrM592(x) SETUP_XfOrM591(x)
        if ((scheme_is_input_port (argv [0 ] ) ) ) {
          Scheme_Input_Port * ip ; 
          BLOCK_SETUP((PUSH(ip, 0+XfOrM592_COUNT)));
#         define XfOrM594_COUNT (1+XfOrM592_COUNT)
#         define SETUP_XfOrM594(x) SETUP(XfOrM594_COUNT)
          ip = NULLED_OUT ; 
          ip = FUNCCALL(SETUP_XfOrM594(_), scheme_input_port_record (argv [0 ] ) ); 
          pll -= ((Scheme_FD * ) ip -> port_data ) -> bufcount ; 
        }
        else {
          Scheme_Output_Port * op ; 
          BLOCK_SETUP((PUSH(op, 0+XfOrM592_COUNT)));
#         define XfOrM593_COUNT (1+XfOrM592_COUNT)
#         define SETUP_XfOrM593(x) SETUP(XfOrM593_COUNT)
          op = NULLED_OUT ; 
          op = FUNCCALL(SETUP_XfOrM593(_), scheme_output_port_record (argv [0 ] ) ); 
          pll += ((Scheme_FD * ) op -> port_data ) -> bufcount ; 
        }
      }
    }
    else if (wis )
      pll = is -> index ; 
    else {
      if (is -> u . pos > is -> index )
        pll = is -> u . pos ; 
      else pll = is -> index ; 
    }
    if ((scheme_is_input_port (argv [0 ] ) ) ) {
      Scheme_Input_Port * ip ; 
      BLOCK_SETUP((PUSH(ip, 0+XfOrM588_COUNT)));
#     define XfOrM589_COUNT (1+XfOrM588_COUNT)
#     define SETUP_XfOrM589(x) SETUP(XfOrM589_COUNT)
      ip = NULLED_OUT ; 
      ip = FUNCCALL(SETUP_XfOrM589(_), scheme_input_port_record (argv [0 ] ) ); 
      pll -= ip -> ungotten_count ; 
      pll -= (pipe_char_count (ip -> peeked_read ) ) ; 
    }
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_integer_value_from_long_long (pll ) )) RET_VALUE_EMPTY_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
long scheme_set_file_position (Scheme_Object * port , long pos ) {
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(port, 0)));
# define XfOrM637_COUNT (1)
# define SETUP_XfOrM637(x) SETUP(XfOrM637_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (pos >= 0 ) {
    Scheme_Object * a [2 ] ; 
    BLOCK_SETUP((PUSHARRAY(a, 2, 0+XfOrM637_COUNT)));
#   define XfOrM639_COUNT (3+XfOrM637_COUNT)
#   define SETUP_XfOrM639(x) SETUP(XfOrM639_COUNT)
    a[0] = NULLED_OUT ; 
    a[1] = NULLED_OUT ; 
    a [0 ] = port ; 
    a [1 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (pos ) ) << 1 ) | 0x1 ) ) ; 
    (void ) FUNCCALL(SETUP_XfOrM639(_), scheme_file_position (2 , a ) ); 
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  else {
    Scheme_Object * n ; 
    BLOCK_SETUP((PUSH(n, 0+XfOrM637_COUNT)));
#   define XfOrM638_COUNT (1+XfOrM637_COUNT)
#   define SETUP_XfOrM638(x) SETUP(XfOrM638_COUNT)
    n = NULLED_OUT ; 
    n = FUNCCALL(SETUP_XfOrM638(_), scheme_file_position (1 , & port ) ); 
    RET_VALUE_START ((((long ) (n ) ) >> 1 ) ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_file_buffer (int argc , Scheme_Object * argv [] ) {
  Scheme_Port * p = ((void * ) 0 ) ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(p, 1)));
# define XfOrM640_COUNT (2)
# define SETUP_XfOrM640(x) SETUP(XfOrM640_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! (scheme_is_output_port (argv [0 ] ) ) && ! (scheme_is_input_port (argv [0 ] ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("file-stream-buffer-mode" , "port" , 0 , argc , argv ) ); 
  p = FUNCCALL(SETUP_XfOrM640(_), scheme_port_record (argv [0 ] ) ); 
  if (argc == 1 ) {
    Scheme_Buffer_Mode_Fun bm ; 
#   define XfOrM644_COUNT (0+XfOrM640_COUNT)
#   define SETUP_XfOrM644(x) SETUP_XfOrM640(x)
    bm = p -> buffer_mode_fun ; 
    if (bm ) {
#     define XfOrM645_COUNT (0+XfOrM644_COUNT)
#     define SETUP_XfOrM645(x) SETUP_XfOrM644(x)
      switch (FUNCCALL(SETUP_XfOrM645(_), bm (p , - 1 ) )) {
        case 0 : RET_VALUE_START (scheme_block_symbol ) RET_VALUE_END ; 
        case 1 : RET_VALUE_START (scheme_line_symbol ) RET_VALUE_END ; 
        case 2 : RET_VALUE_START (scheme_none_symbol ) RET_VALUE_END ; 
      }
    }
    RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
  }
  else {
    Scheme_Object * s = argv [1 ] ; 
    Scheme_Buffer_Mode_Fun bm ; 
    BLOCK_SETUP((PUSH(s, 0+XfOrM640_COUNT)));
#   define XfOrM641_COUNT (1+XfOrM640_COUNT)
#   define SETUP_XfOrM641(x) SETUP(XfOrM641_COUNT)
    if (! ((s ) == (scheme_block_symbol ) ) && ! ((s ) == (scheme_line_symbol ) ) && ! ((s ) == (scheme_none_symbol ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("file-stream-buffer-mode" , "'none, 'line, or 'block" , 1 , argc , argv ) ); 
    if ((scheme_is_input_port (argv [0 ] ) ) && ((s ) == (scheme_line_symbol ) ) )
      FUNCCALL(SETUP_XfOrM641(_), scheme_arg_mismatch ("file-stream-buffer-mode" , "'line buffering not supported for an input port: " , argv [0 ] ) ); 
    bm = p -> buffer_mode_fun ; 
    if (bm ) {
      int mode ; 
#     define XfOrM643_COUNT (0+XfOrM641_COUNT)
#     define SETUP_XfOrM643(x) SETUP_XfOrM641(x)
      if (((s ) == (scheme_block_symbol ) ) )
        mode = 0 ; 
      else if (((s ) == (scheme_line_symbol ) ) )
        mode = 1 ; 
      else mode = 2 ; 
      FUNCCALL(SETUP_XfOrM643(_), bm (p , mode ) ); 
    }
    else {
#     define XfOrM642_COUNT (0+XfOrM641_COUNT)
#     define SETUP_XfOrM642(x) SETUP_XfOrM641(x)
      FUNCCALL_EMPTY(scheme_arg_mismatch ("file-stream-buffer-mode" , "cannot set buffer mode on port: " , argv [0 ] ) ); 
    }
    RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int file_byte_ready (Scheme_Input_Port * port ) {
  /* No conversion */
  return 1 ; 
}
static long file_get_string (Scheme_Input_Port * port , char * buffer , long offset , long size , int nonblock , Scheme_Object * unless_evt ) {
  FILE * fp ; 
  Scheme_Input_File * fip ; 
  int c ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(fp, 0), PUSH(port, 1)));
# define XfOrM648_COUNT (2)
# define SETUP_XfOrM648(x) SETUP(XfOrM648_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  fp = NULLED_OUT ; 
  fip = NULLED_OUT ; 
  fip = (Scheme_Input_File * ) port -> port_data ; 
  fp = fip -> f ; 
  c = fread (buffer XFORM_OK_PLUS offset , 1 , size , fp ) ; 
  if (c <= 0 ) {
#   define XfOrM649_COUNT (0+XfOrM648_COUNT)
#   define SETUP_XfOrM649(x) SETUP_XfOrM648(x)
    if (! FUNCCALL(SETUP_XfOrM649(_), feof (fp ) )) {
#     define XfOrM650_COUNT (0+XfOrM649_COUNT)
#     define SETUP_XfOrM650(x) SETUP_XfOrM649(x)
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_FILESYSTEM , "error reading from file port %V (%e)" , port -> name , (* __errno_location () ) ) ); 
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    else c = (- 1 ) ; 
    FUNCCALL_EMPTY(clearerr (fp ) ); 
  }
  RET_VALUE_START (c ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void file_close_input (Scheme_Input_Port * port ) {
  /* No conversion */
  Scheme_Input_File * fip ; 
  fip = (Scheme_Input_File * ) port -> port_data ; 
  fclose (fip -> f ) ; 
  -- scheme_file_open_count ; 
}
static void file_need_wakeup (Scheme_Input_Port * port , void * fds ) {
  /* No conversion */
}
static int file_buffer_mode (Scheme_Port * p , int mode ) {
  FILE * f ; 
  int bad ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(f, 0)));
# define XfOrM653_COUNT (1)
# define SETUP_XfOrM653(x) SETUP(XfOrM653_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  f = NULLED_OUT ; 
  if (mode < 0 )
    RET_VALUE_START (- 1 ) RET_VALUE_END ; 
  if (((Scheme_Type ) (((((long ) ((Scheme_Object * ) p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((Scheme_Object * ) p ) ) -> type ) ) == (Scheme_Type ) (scheme_input_port_type ) ) ) {
    Scheme_Input_Port * ip = (Scheme_Input_Port * ) p ; 
    f = ((Scheme_Output_File * ) ip -> port_data ) -> f ; 
  }
  else {
    Scheme_Output_Port * op = (Scheme_Output_Port * ) p ; 
    f = ((Scheme_Output_File * ) op -> port_data ) -> f ; 
  }
  if (mode == 0 )
    bad = FUNCCALL(SETUP_XfOrM653(_), setvbuf (f , ((void * ) 0 ) , 0 , 0 ) ); 
  else if (mode == 1 )
    bad = FUNCCALL(SETUP_XfOrM653(_), setvbuf (f , ((void * ) 0 ) , 1 , 0 ) ); 
  else bad = FUNCCALL_EMPTY(setvbuf (f , ((void * ) 0 ) , 2 , 0 ) ); 
  if (bad ) {
#   define XfOrM654_COUNT (0+XfOrM653_COUNT)
#   define SETUP_XfOrM654(x) SETUP_XfOrM653(x)
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_FILESYSTEM , "file-stream-buffer-mode: error changing buffering (%e)" , (* __errno_location () ) ) ); 
  }
  RET_VALUE_START (mode ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * _scheme_make_named_file_input_port (FILE * fp , Scheme_Object * name , int regfile ) {
  Scheme_Input_Port * ip ; 
  Scheme_Input_File * fip ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(name, 0), PUSH(fip, 1), PUSH(ip, 2), PUSH(fp, 3)));
# define XfOrM657_COUNT (4)
# define SETUP_XfOrM657(x) SETUP(XfOrM657_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ip = NULLED_OUT ; 
  fip = NULLED_OUT ; 
  if (! fp )
    FUNCCALL_EMPTY(scheme_signal_error ("make-file-input-port(internal): " "null file pointer" ) ); 
  fip = ((Scheme_Input_File * ) FUNCCALL(SETUP_XfOrM657(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Input_File ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  fip -> type = scheme_rt_input_file ; 
  fip -> f = fp ; 
  ip = FUNCCALL(SETUP_XfOrM657(_), scheme_make_input_port (file_input_port_type , fip , name , file_get_string , ((void * ) 0 ) , scheme_progress_evt_via_get , scheme_peeked_read_via_get , file_byte_ready , file_close_input , file_need_wakeup , 1 ) ); 
  ip -> p . buffer_mode_fun = file_buffer_mode ; 
  RET_VALUE_START ((Scheme_Object * ) ip ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_named_file_input_port (FILE * fp , Scheme_Object * name ) {
  /* No conversion */
  return _scheme_make_named_file_input_port (fp , name , 0 ) ; 
}
Scheme_Object * scheme_make_file_input_port (FILE * fp ) {
  Scheme_Object * __funcarg30 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(fp, 0)));
# define XfOrM659_COUNT (1)
# define SETUP_XfOrM659(x) SETUP(XfOrM659_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg30 = FUNCCALL(SETUP_XfOrM659(_), scheme_intern_symbol ("file" ) ), FUNCCALL_EMPTY(scheme_make_named_file_input_port (fp , __funcarg30 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void fd_need_wakeup (Scheme_Input_Port * port , void * fds ) ; 
/* this far 4660 */
/* this far 4660 */
static int fd_byte_ready (Scheme_Input_Port * port ) {
  Scheme_FD * fip ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(fip, 0)));
# define XfOrM660_COUNT (1)
# define SETUP_XfOrM660(x) SETUP(XfOrM660_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  fip = NULLED_OUT ; 
  fip = (Scheme_FD * ) port -> port_data ; 
  if (fip -> regfile || port -> closed )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  if (fip -> bufcount )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  else {
    int r ; 
    static fd_set * readfds ; 
    static fd_set * exnfds ; 
    struct timeval time = {
      0 , 0 }
    ; 
#   define XfOrM661_COUNT (0+XfOrM660_COUNT)
#   define SETUP_XfOrM661(x) SETUP_XfOrM660(x)
    (readfds = (readfds ? (fd_set * ) FUNCCALL(SETUP_XfOrM661(_), scheme_init_fdset_array (readfds , 1 ) ): (fd_set * ) FUNCCALL(SETUP_XfOrM661(_), scheme_alloc_fdset_array (1 , 1 ) )) ) ; 
    (exnfds = (exnfds ? (fd_set * ) FUNCCALL(SETUP_XfOrM661(_), scheme_init_fdset_array (exnfds , 1 ) ): (fd_set * ) FUNCCALL(SETUP_XfOrM661(_), scheme_alloc_fdset_array (1 , 1 ) )) ) ; 
    FUNCCALL(SETUP_XfOrM661(_), scheme_fdzero (readfds ) ); 
    FUNCCALL_AGAIN(scheme_fdzero (exnfds ) ); 
    FUNCCALL_AGAIN(scheme_fdset (readfds , fip -> fd ) ); 
    FUNCCALL_AGAIN(scheme_fdset (exnfds , fip -> fd ) ); 
    do {
#     define XfOrM663_COUNT (0+XfOrM661_COUNT)
#     define SETUP_XfOrM663(x) SETUP_XfOrM661(x)
      r = FUNCCALL(SETUP_XfOrM663(_), select (fip -> fd + 1 , readfds , ((void * ) 0 ) , exnfds , & time ) ); 
    }
    while ((r == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
    RET_VALUE_START (r ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static long fd_get_string_slow (Scheme_Input_Port * port , char * buffer , long offset , long size , int nonblock , Scheme_Object * unless ) {
  Scheme_FD * fip ; 
  long bc ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(unless, 0), PUSH(buffer, 1), PUSH(fip, 2), PUSH(port, 3)));
# define XfOrM664_COUNT (4)
# define SETUP_XfOrM664(x) SETUP(XfOrM664_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  fip = NULLED_OUT ; 
  fip = (Scheme_FD * ) port -> port_data ; 
  while (1 ) {
    int none_avail = 0 ; 
    int target_size , target_offset , ext_target ; 
    char * target ; 
    BLOCK_SETUP((PUSH(target, 0+XfOrM664_COUNT)));
#   define XfOrM685_COUNT (1+XfOrM664_COUNT)
#   define SETUP_XfOrM685(x) SETUP(XfOrM685_COUNT)
    target = NULLED_OUT ; 
    while (! FUNCCALL(SETUP_XfOrM685(_), fd_byte_ready (port ) )) {
#     define XfOrM704_COUNT (0+XfOrM685_COUNT)
#     define SETUP_XfOrM704(x) SETUP_XfOrM685(x)
      if (nonblock > 0 )
        RET_VALUE_START (0 ) RET_VALUE_END ; 
      FUNCCALL(SETUP_XfOrM704(_), scheme_block_until_unless ((Scheme_Ready_Fun ) fd_byte_ready , (Scheme_Needs_Wakeup_Fun ) fd_need_wakeup , (Scheme_Object * ) port , 0.0 , unless , nonblock ) ); 
      FUNCCALL_AGAIN(scheme_wait_input_allowed (port , nonblock ) ); 
      if ((scheme_unless_ready (unless ) ) )
        RET_VALUE_START ((- 3 ) ) RET_VALUE_END ; 
    }
    if (port -> closed ) {
#     define XfOrM702_COUNT (0+XfOrM685_COUNT)
#     define SETUP_XfOrM702(x) SETUP_XfOrM685(x)
      FUNCCALL(SETUP_XfOrM702(_), scheme_get_byte ((Scheme_Object * ) port ) ); 
    }
    if (fip -> bufcount ) {
#     define XfOrM701_COUNT (0+XfOrM685_COUNT)
#     define SETUP_XfOrM701(x) SETUP_XfOrM685(x)
      bc = ((size <= fip -> bufcount ) ? size : fip -> bufcount ) ; 
      (memcpy (buffer + offset , fip -> buffer + fip -> buffpos , bc ) ) ; 
      fip -> buffpos += bc ; 
      fip -> bufcount -= bc ; 
      RET_VALUE_START (bc ) RET_VALUE_END ; 
    }
    if ((size >= 4096 ) && (fip -> flush != 2 ) ) {
      ext_target = 1 ; 
      target = buffer ; 
      target_offset = offset ; 
      target_size = size ; 
    }
    else {
      ext_target = 0 ; 
      target = (char * ) fip -> buffer ; 
      target_offset = 0 ; 
      if (fip -> flush == 2 )
        target_size = 1 ; 
      else target_size = 4096 ; 
    }
    if (fip -> regfile ) {
#     define XfOrM696_COUNT (0+XfOrM685_COUNT)
#     define SETUP_XfOrM696(x) SETUP_XfOrM685(x)
      do {
#       define XfOrM698_COUNT (0+XfOrM696_COUNT)
#       define SETUP_XfOrM698(x) SETUP_XfOrM696(x)
        bc = (read (fip -> fd , target + target_offset , target_size ) ) ; 
      }
      while ((bc == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
    }
    else {
      int old_flags ; 
#     define XfOrM692_COUNT (0+XfOrM685_COUNT)
#     define SETUP_XfOrM692(x) SETUP_XfOrM685(x)
      old_flags = fcntl (fip -> fd , 3 , 0 ) ; 
      fcntl (fip -> fd , 4 , old_flags | 2048 ) ; 
      do {
#       define XfOrM695_COUNT (0+XfOrM692_COUNT)
#       define SETUP_XfOrM695(x) SETUP_XfOrM692(x)
        bc = (read (fip -> fd , target + target_offset , target_size ) ) ; 
      }
      while ((bc == - 1 ) && (* __errno_location () ) == 4 ) ; 
      fcntl (fip -> fd , 4 , old_flags ) ; 
      if ((bc == - 1 ) && ((* __errno_location () ) == 11 ) ) {
        none_avail = 1 ; 
        bc = 0 ; 
      }
    }
    if (! none_avail ) {
#     define XfOrM687_COUNT (0+XfOrM685_COUNT)
#     define SETUP_XfOrM687(x) SETUP_XfOrM685(x)
      if (ext_target && (bc > 0 ) ) {
        RET_VALUE_START (bc ) RET_VALUE_END ; 
      }
      fip -> bufcount = bc ; 
      if (fip -> bufcount < 0 ) {
#       define XfOrM690_COUNT (0+XfOrM687_COUNT)
#       define SETUP_XfOrM690(x) SETUP_XfOrM687(x)
        fip -> bufcount = 0 ; 
        fip -> buffpos = 0 ; 
        FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_FILESYSTEM , "error reading from stream port %V (" "%e" ")" , port -> name , (* __errno_location () ) ) ); 
        RET_VALUE_START (0 ) RET_VALUE_END ; 
      }
      if (! fip -> bufcount ) {
        fip -> buffpos = 0 ; 
        RET_VALUE_START ((- 1 ) ) RET_VALUE_END ; 
      }
      else {
#       define XfOrM688_COUNT (0+XfOrM687_COUNT)
#       define SETUP_XfOrM688(x) SETUP_XfOrM687(x)
        bc = ((size <= fip -> bufcount ) ? size : fip -> bufcount ) ; 
        (memcpy (buffer + offset , fip -> buffer , bc ) ) ; 
        fip -> buffpos = bc ; 
        fip -> bufcount -= bc ; 
        RET_VALUE_START (bc ) RET_VALUE_END ; 
      }
    }
    else if (nonblock > 0 ) {
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static long fd_get_string (Scheme_Input_Port * port , char * buffer , long offset , long size , int nonblock , Scheme_Object * unless ) {
  /* No conversion */
  Scheme_FD * fip ; 
  long bc ; 
  if (unless && scheme_unless_ready (unless ) )
    return (- 3 ) ; 
  fip = (Scheme_FD * ) port -> port_data ; 
  if (fip -> bufcount ) {
    if (size == 1 ) {
      buffer [offset ] = fip -> buffer [fip -> buffpos ++ ] ; 
      -- fip -> bufcount ; 
      return 1 ; 
    }
    else {
      bc = ((size <= fip -> bufcount ) ? size : fip -> bufcount ) ; 
      memcpy (buffer + offset , fip -> buffer + fip -> buffpos , bc ) ; 
      fip -> buffpos += bc ; 
      fip -> bufcount -= bc ; 
      return bc ; 
    }
  }
  else {
    if ((nonblock == 2 ) && (fip -> flush == 2 ) )
      return 0 ; 
    return fd_get_string_slow (port , buffer , offset , size , nonblock , unless ) ; 
  }
}
static void fd_close_input (Scheme_Input_Port * port ) {
  /* No conversion */
  Scheme_FD * fip ; 
  fip = (Scheme_FD * ) port -> port_data ; 
  if (fip -> refcount )
    * fip -> refcount -= 1 ; 
  if (! fip -> refcount || ! * fip -> refcount ) {
    {
      int cr ; 
      do {
        cr = close (fip -> fd ) ; 
      }
      while ((cr == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
    }
  }
  -- scheme_file_open_count ; 
}
static void fd_need_wakeup (Scheme_Input_Port * port , void * fds ) {
  Scheme_FD * fip ; 
  void * fds2 ; 
  int n ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(fds, 0), PUSH(fds2, 1)));
# define XfOrM715_COUNT (2)
# define SETUP_XfOrM715(x) SETUP(XfOrM715_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  fip = NULLED_OUT ; 
  fds2 = NULLED_OUT ; 
  fip = (Scheme_FD * ) port -> port_data ; 
  n = fip -> fd ; 
  FUNCCALL(SETUP_XfOrM715(_), scheme_fdset ((fd_set * ) fds , n ) ); 
  fds2 = FUNCCALL_AGAIN(scheme_get_fdset (fds , 2 ) ); 
  FUNCCALL_EMPTY(scheme_fdset ((fd_set * ) fds2 , n ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int fd_input_buffer_mode (Scheme_Port * p , int mode ) {
  /* No conversion */
  Scheme_FD * fd ; 
  Scheme_Input_Port * ip = (Scheme_Input_Port * ) p ; 
  fd = (Scheme_FD * ) ip -> port_data ; 
  if (mode < 0 ) {
    return fd -> flush ; 
  }
  else {
    fd -> flush = mode ; 
    return mode ; 
  }
}
static Scheme_Object * make_fd_input_port (int fd , Scheme_Object * name , int regfile , int win_textmode , int * refcount ) {
  Scheme_Input_Port * ip ; 
  Scheme_FD * fip ; 
  unsigned char * bfr ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(name, 0), PUSH(refcount, 1), PUSH(fip, 2), PUSH(ip, 3), PUSH(bfr, 4)));
# define XfOrM719_COUNT (5)
# define SETUP_XfOrM719(x) SETUP(XfOrM719_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ip = NULLED_OUT ; 
  fip = NULLED_OUT ; 
  bfr = NULLED_OUT ; 
  fip = ((Scheme_FD * ) FUNCCALL(SETUP_XfOrM719(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_FD ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  fip -> type = scheme_rt_input_fd ; 
  bfr = (unsigned char * ) FUNCCALL(SETUP_XfOrM719(_), GC_malloc_atomic (4096 ) ); 
  fip -> buffer = bfr ; 
  fip -> fd = fd ; 
  fip -> bufcount = 0 ; 
  fip -> regfile = regfile ; 
  fip -> textmode = win_textmode ; 
  fip -> refcount = refcount ; 
  fip -> flush = 0 ; 
  ip = FUNCCALL(SETUP_XfOrM719(_), scheme_make_input_port (fd_input_port_type , fip , name , fd_get_string , ((void * ) 0 ) , scheme_progress_evt_via_get , scheme_peeked_read_via_get , fd_byte_ready , fd_close_input , fd_need_wakeup , 1 ) ); 
  ip -> p . buffer_mode_fun = fd_input_buffer_mode ; 
  ip -> pending_eof = 1 ; 
  RET_VALUE_START ((Scheme_Object * ) ip ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_fd_input_port (int fd , Scheme_Object * name , int regfile , int textmode ) {
  /* No conversion */
  return make_fd_input_port (fd , name , regfile , textmode , ((void * ) 0 ) ) ; 
}
static void file_flush (Scheme_Output_Port * port ) {
  /* No conversion */
  if (fflush (((Scheme_Output_File * ) port -> port_data ) -> f ) ) {
    scheme_raise_exn (MZEXN_FAIL_FILESYSTEM , "error flushing file port (%e)" , (* __errno_location () ) ) ; 
  }
}
static long file_write_string (Scheme_Output_Port * port , const char * str , long d , long llen , int rarely_block , int enable_break ) {
  FILE * fp ; 
  long len = llen ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(port, 0), PUSH(str, 1), PUSH(fp, 2)));
# define XfOrM723_COUNT (3)
# define SETUP_XfOrM723(x) SETUP(XfOrM723_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  fp = NULLED_OUT ; 
  fp = ((Scheme_Output_File * ) port -> port_data ) -> f ; 
  if (! len ) {
#   define XfOrM731_COUNT (0+XfOrM723_COUNT)
#   define SETUP_XfOrM731(x) SETUP_XfOrM723(x)
    FUNCCALL(SETUP_XfOrM731(_), file_flush (port ) ); 
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  if (fwrite (str XFORM_OK_PLUS d , len , 1 , fp ) != 1 ) {
#   define XfOrM730_COUNT (0+XfOrM723_COUNT)
#   define SETUP_XfOrM730(x) SETUP_XfOrM723(x)
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_FILESYSTEM , "error writing to file port (%e)" , (* __errno_location () ) ) ); 
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  if (rarely_block ) {
#   define XfOrM729_COUNT (0+XfOrM723_COUNT)
#   define SETUP_XfOrM729(x) SETUP_XfOrM723(x)
    FUNCCALL(SETUP_XfOrM729(_), file_flush (port ) ); 
  }
  else {
#   define XfOrM724_COUNT (0+XfOrM723_COUNT)
#   define SETUP_XfOrM724(x) SETUP_XfOrM723(x)
    while (len -- ) {
#     define XfOrM727_COUNT (0+XfOrM724_COUNT)
#     define SETUP_XfOrM727(x) SETUP_XfOrM724(x)
      if (str [d ] == '\n' || str [d ] == '\r' ) {
#       define XfOrM728_COUNT (0+XfOrM727_COUNT)
#       define SETUP_XfOrM728(x) SETUP_XfOrM727(x)
        FUNCCALL(SETUP_XfOrM728(_), file_flush (port ) ); 
        break ; 
      }
      d ++ ; 
    }
  }
  RET_VALUE_START (llen ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void file_close_output (Scheme_Output_Port * port ) {
  /* No conversion */
  Scheme_Output_File * fop = (Scheme_Output_File * ) port -> port_data ; 
  FILE * fp = fop -> f ; 
  fclose (fp ) ; 
  -- scheme_file_open_count ; 
}
Scheme_Object * scheme_make_file_output_port (FILE * fp ) {
  Scheme_Output_File * fop ; 
  Scheme_Output_Port * op ; 
  Scheme_Object * __funcarg31 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(fop, 0), PUSH(op, 1), PUSH(fp, 2)));
# define XfOrM733_COUNT (3)
# define SETUP_XfOrM733(x) SETUP(XfOrM733_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  fop = NULLED_OUT ; 
  op = NULLED_OUT ; 
  if (! fp )
    FUNCCALL_EMPTY(scheme_signal_error ("make-file-out-port(internal): " "null file pointer" ) ); 
  fop = ((Scheme_Output_File * ) FUNCCALL(SETUP_XfOrM733(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Output_File ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  fop -> type = scheme_rt_output_file ; 
  fop -> f = fp ; 
  op = (__funcarg31 = FUNCCALL(SETUP_XfOrM733(_), scheme_intern_symbol ("file" ) ), FUNCCALL_AGAIN(scheme_make_output_port (file_output_port_type , fop , __funcarg31 , scheme_write_evt_via_write , file_write_string , ((void * ) 0 ) , file_close_output , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) )) ; 
  op -> p . buffer_mode_fun = file_buffer_mode ; 
  RET_VALUE_START ((Scheme_Object * ) op ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int fd_flush_done (Scheme_Object * port ) {
  Scheme_FD * fop ; 
  Scheme_Output_Port * op ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(op, 0), PUSH(fop, 1)));
# define XfOrM734_COUNT (2)
# define SETUP_XfOrM734(x) SETUP(XfOrM734_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  fop = NULLED_OUT ; 
  op = NULLED_OUT ; 
  op = FUNCCALL(SETUP_XfOrM734(_), scheme_output_port_record (port ) ); 
  fop = (Scheme_FD * ) op -> port_data ; 
  RET_VALUE_START (! fop -> flushing ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void wait_until_fd_flushed (Scheme_Output_Port * op , int enable_break ) {
  /* No conversion */
  scheme_block_until_enable_break (fd_flush_done , ((void * ) 0 ) , (Scheme_Object * ) op , 0.0 , enable_break ) ; 
}
/* this far 5678 */
/* this far 5678 */
static int fd_write_ready (Scheme_Object * port ) {
  Scheme_FD * fop ; 
  Scheme_Output_Port * op ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(op, 0), PUSH(fop, 1)));
# define XfOrM736_COUNT (2)
# define SETUP_XfOrM736(x) SETUP(XfOrM736_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  fop = NULLED_OUT ; 
  op = NULLED_OUT ; 
  op = FUNCCALL(SETUP_XfOrM736(_), scheme_output_port_record (port ) ); 
  fop = (Scheme_FD * ) op -> port_data ; 
  if (fop -> regfile || op -> closed )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  {
    static fd_set * writefds ; 
    static fd_set * exnfds ; 
    struct timeval time = {
      0 , 0 }
    ; 
    int sr ; 
#   define XfOrM737_COUNT (0+XfOrM736_COUNT)
#   define SETUP_XfOrM737(x) SETUP_XfOrM736(x)
    (writefds = (writefds ? (fd_set * ) FUNCCALL(SETUP_XfOrM737(_), scheme_init_fdset_array (writefds , 1 ) ): (fd_set * ) FUNCCALL(SETUP_XfOrM737(_), scheme_alloc_fdset_array (1 , 1 ) )) ) ; 
    (exnfds = (exnfds ? (fd_set * ) FUNCCALL(SETUP_XfOrM737(_), scheme_init_fdset_array (exnfds , 1 ) ): (fd_set * ) FUNCCALL(SETUP_XfOrM737(_), scheme_alloc_fdset_array (1 , 1 ) )) ) ; 
    FUNCCALL(SETUP_XfOrM737(_), scheme_fdzero (writefds ) ); 
    FUNCCALL_AGAIN(scheme_fdzero (exnfds ) ); 
    FUNCCALL_AGAIN(scheme_fdset (writefds , fop -> fd ) ); 
    FUNCCALL_AGAIN(scheme_fdset (exnfds , fop -> fd ) ); 
    do {
#     define XfOrM739_COUNT (0+XfOrM737_COUNT)
#     define SETUP_XfOrM739(x) SETUP_XfOrM737(x)
      sr = FUNCCALL(SETUP_XfOrM739(_), select (fop -> fd + 1 , ((void * ) 0 ) , writefds , exnfds , & time ) ); 
    }
    while ((sr == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
    RET_VALUE_START (sr ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void fd_write_need_wakeup (Scheme_Object * port , void * fds ) {
  Scheme_Output_Port * op ; 
  Scheme_FD * fop ; 
  void * fds2 ; 
  int n ; 
  PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(fds, 0), PUSH(op, 1), PUSH(fds2, 2), PUSH(fop, 3)));
# define XfOrM740_COUNT (4)
# define SETUP_XfOrM740(x) SETUP(XfOrM740_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  op = NULLED_OUT ; 
  fop = NULLED_OUT ; 
  fds2 = NULLED_OUT ; 
  op = FUNCCALL(SETUP_XfOrM740(_), scheme_output_port_record (port ) ); 
  fop = (Scheme_FD * ) op -> port_data ; 
  n = fop -> fd ; 
  fds2 = FUNCCALL(SETUP_XfOrM740(_), scheme_get_fdset (fds , 1 ) ); 
  FUNCCALL_AGAIN(scheme_fdset ((fd_set * ) fds2 , n ) ); 
  fds2 = FUNCCALL_AGAIN(scheme_get_fdset (fds , 2 ) ); 
  FUNCCALL_EMPTY(scheme_fdset ((fd_set * ) fds2 , n ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void release_flushing_lock (void * _fop ) {
  /* No conversion */
  Scheme_FD * fop ; 
  fop = (Scheme_FD * ) _fop ; 
  fop -> flushing = 0 ; 
}
static long flush_fd (Scheme_Output_Port * op , const char * volatile bufstr , volatile unsigned long buflen , volatile unsigned long offset , int immediate_only , int enable_break ) {
  Scheme_FD * volatile fop = (Scheme_FD * ) op -> port_data ; 
  volatile long wrote = 0 ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(fop, 0), PUSH(op, 1), PUSH(bufstr, 2)));
# define XfOrM742_COUNT (3)
# define SETUP_XfOrM742(x) SETUP(XfOrM742_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (fop -> flushing ) {
#   define XfOrM771_COUNT (0+XfOrM742_COUNT)
#   define SETUP_XfOrM771(x) SETUP_XfOrM742(x)
    if (scheme_force_port_closed ) {
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    if (immediate_only == 2 )
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    FUNCCALL(SETUP_XfOrM771(_), wait_until_fd_flushed (op , enable_break ) ); 
    if (op -> closed )
      RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  if (! bufstr ) {
    bufstr = (char * ) fop -> buffer ; 
    buflen = fop -> bufcount ; 
  }
  if (buflen ) {
#   define XfOrM743_COUNT (0+XfOrM742_COUNT)
#   define SETUP_XfOrM743(x) SETUP_XfOrM742(x)
    fop -> flushing = 1 ; 
    fop -> bufcount = 0 ; 
    while (1 ) {
      long len ; 
      int errsaved , full_write_buffer ; 
      int flags ; 
#     define XfOrM757_COUNT (0+XfOrM743_COUNT)
#     define SETUP_XfOrM757(x) SETUP_XfOrM743(x)
      flags = fcntl (fop -> fd , 3 , 0 ) ; 
      fcntl (fop -> fd , 4 , flags | 2048 ) ; 
      do {
#       define XfOrM769_COUNT (0+XfOrM757_COUNT)
#       define SETUP_XfOrM769(x) SETUP_XfOrM757(x)
        len = (write (fop -> fd , bufstr + offset , buflen - offset ) ) ; 
      }
      while ((len == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
      errsaved = (* __errno_location () ) ; 
      fcntl (fop -> fd , 4 , flags ) ; 
      full_write_buffer = (errsaved == 11 ) ; 
      if (len < 0 ) {
#       define XfOrM760_COUNT (0+XfOrM757_COUNT)
#       define SETUP_XfOrM760(x) SETUP_XfOrM757(x)
        if (scheme_force_port_closed ) {
          RET_VALUE_START (wrote ) RET_VALUE_END ; 
        }
        else if (full_write_buffer ) {
#         define XfOrM762_COUNT (0+XfOrM760_COUNT)
#         define SETUP_XfOrM762(x) SETUP_XfOrM760(x)
          if (immediate_only == 2 ) {
            fop -> flushing = 0 ; 
            RET_VALUE_START (wrote ) RET_VALUE_END ; 
          }
          {
            mz_jmp_buf * volatile savebuf , newbuf ; 
            BLOCK_SETUP((PUSH(savebuf, 0+XfOrM762_COUNT)));
#           define XfOrM763_COUNT (1+XfOrM762_COUNT)
#           define SETUP_XfOrM763(x) SETUP(XfOrM763_COUNT)
            savebuf = NULLED_OUT ; 
            FUNCCALL(SETUP_XfOrM763(_), scheme_push_kill_action ((Scheme_Kill_Action_Func ) release_flushing_lock , (void * ) fop ) ); 
            savebuf = scheme_current_thread -> error_buf ; 
            scheme_current_thread -> error_buf = & newbuf ; 
            if (((newbuf ) . gcvs = (long ) __gc_var_stack__ , (newbuf ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((newbuf ) . jb ) , (_setjmp (((newbuf ) . jb ) -> jb ) ) ) ) ) {
#             define XfOrM765_COUNT (0+XfOrM763_COUNT)
#             define SETUP_XfOrM765(x) SETUP_XfOrM763(x)
              FUNCCALL(SETUP_XfOrM765(_), scheme_pop_kill_action () ); 
              FUNCCALL(SETUP_XfOrM765(_), release_flushing_lock (fop ) ); 
              (((long * ) (void * ) ((* savebuf ) . gcvs ) ) [1 ] = (* savebuf ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* savebuf ) . gcvs , scheme_jit_longjmp ((* savebuf ) . jb , 1 ) ) ; 
            }
            else {
#             define XfOrM764_COUNT (0+XfOrM763_COUNT)
#             define SETUP_XfOrM764(x) SETUP_XfOrM763(x)
              ; 
              FUNCCALL(SETUP_XfOrM764(_), scheme_block_until_enable_break (fd_write_ready , fd_write_need_wakeup , (Scheme_Object * ) op , 0.0 , enable_break ) ); 
              FUNCCALL_AGAIN(scheme_pop_kill_action () ); 
              scheme_current_thread -> error_buf = savebuf ; 
            }
          }
          ; 
        }
        else {
#         define XfOrM761_COUNT (0+XfOrM760_COUNT)
#         define SETUP_XfOrM761(x) SETUP_XfOrM760(x)
          fop -> flushing = 0 ; 
          FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_FILESYSTEM , "error writing to stream port (" "%e" ")" , errsaved ) ); 
          RET_VALUE_START (0 ) RET_VALUE_END ; 
        }
      }
      else if ((len + offset == buflen ) || immediate_only ) {
        fop -> flushing = 0 ; 
        RET_VALUE_START (wrote + len ) RET_VALUE_END ; 
      }
      else {
        offset += len ; 
        wrote += len ; 
      }
    }
  }
  RET_VALUE_START (wrote ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static long fd_write_string (Scheme_Output_Port * port , const char * str , long d , long len , int rarely_block , int enable_break ) {
  Scheme_FD * fop ; 
  long l ; 
  int flush = (! len || rarely_block ) ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(port, 0), PUSH(str, 1), PUSH(fop, 2)));
# define XfOrM773_COUNT (3)
# define SETUP_XfOrM773(x) SETUP(XfOrM773_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  fop = NULLED_OUT ; 
  fop = (Scheme_FD * ) port -> port_data ; 
  if (! len ) {
#   define XfOrM786_COUNT (0+XfOrM773_COUNT)
#   define SETUP_XfOrM786(x) SETUP_XfOrM773(x)
    if (fop -> bufcount )
      FUNCCALL(SETUP_XfOrM786(_), flush_fd (port , ((void * ) 0 ) , 0 , 0 , rarely_block , enable_break ) ); 
    if (fop -> bufcount )
      RET_VALUE_START (- 1 ) RET_VALUE_END ; 
    else RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  if (! fop -> bufcount && flush ) {
#   define XfOrM785_COUNT (0+XfOrM773_COUNT)
#   define SETUP_XfOrM785(x) SETUP_XfOrM773(x)
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(flush_fd (port , str , d + len , d , rarely_block , enable_break ) )) RET_VALUE_EMPTY_END ; 
  }
  if (fop -> flushing ) {
#   define XfOrM784_COUNT (0+XfOrM773_COUNT)
#   define SETUP_XfOrM784(x) SETUP_XfOrM773(x)
    if (rarely_block == 2 )
      RET_VALUE_START (- 1 ) RET_VALUE_END ; 
    FUNCCALL(SETUP_XfOrM784(_), wait_until_fd_flushed (port , enable_break ) ); 
  }
  if (port -> closed )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  l = 4096 - fop -> bufcount ; 
  if ((len <= l ) && (! flush || ! rarely_block ) ) {
#   define XfOrM783_COUNT (0+XfOrM773_COUNT)
#   define SETUP_XfOrM783(x) SETUP_XfOrM773(x)
    (memcpy (fop -> buffer + fop -> bufcount , str + d , len ) ) ; 
    fop -> bufcount += len ; 
  }
  else {
#   define XfOrM780_COUNT (0+XfOrM773_COUNT)
#   define SETUP_XfOrM780(x) SETUP_XfOrM773(x)
    if (fop -> bufcount ) {
#     define XfOrM782_COUNT (0+XfOrM780_COUNT)
#     define SETUP_XfOrM782(x) SETUP_XfOrM780(x)
      FUNCCALL(SETUP_XfOrM782(_), flush_fd (port , ((void * ) 0 ) , 0 , 0 , (rarely_block == 2 ) ? 2 : 0 , enable_break ) ); 
      if (rarely_block && fop -> bufcount )
        RET_VALUE_START (- 1 ) RET_VALUE_END ; 
    }
    if (! flush && (len <= 4096 ) ) {
#     define XfOrM781_COUNT (0+XfOrM780_COUNT)
#     define SETUP_XfOrM781(x) SETUP_XfOrM780(x)
      (memcpy (fop -> buffer , str + d , len ) ) ; 
      fop -> bufcount = len ; 
    }
    else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(flush_fd (port , str , len + d , d , rarely_block , enable_break ) )) RET_VALUE_EMPTY_END ; 
  }
  if ((flush || (fop -> flush == 2 ) ) && fop -> bufcount ) {
#   define XfOrM779_COUNT (0+XfOrM773_COUNT)
#   define SETUP_XfOrM779(x) SETUP_XfOrM773(x)
    FUNCCALL(SETUP_XfOrM779(_), flush_fd (port , ((void * ) 0 ) , 0 , 0 , 0 , enable_break ) ); 
  }
  else if (fop -> flush == 1 ) {
    long i ; 
#   define XfOrM774_COUNT (0+XfOrM773_COUNT)
#   define SETUP_XfOrM774(x) SETUP_XfOrM773(x)
    for (i = len ; i -- ; ) {
#     define XfOrM777_COUNT (0+XfOrM774_COUNT)
#     define SETUP_XfOrM777(x) SETUP_XfOrM774(x)
      if (str [d ] == '\n' || str [d ] == '\r' ) {
#       define XfOrM778_COUNT (0+XfOrM777_COUNT)
#       define SETUP_XfOrM778(x) SETUP_XfOrM777(x)
        FUNCCALL(SETUP_XfOrM778(_), flush_fd (port , ((void * ) 0 ) , 0 , 0 , 0 , enable_break ) ); 
        break ; 
      }
      d ++ ; 
    }
  }
  RET_VALUE_START (len ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void fd_close_output (Scheme_Output_Port * port ) {
  Scheme_FD * fop = (Scheme_FD * ) port -> port_data ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(fop, 0), PUSH(port, 1)));
# define XfOrM787_COUNT (2)
# define SETUP_XfOrM787(x) SETUP(XfOrM787_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (fop -> bufcount )
    FUNCCALL(SETUP_XfOrM787(_), flush_fd (port , ((void * ) 0 ) , 0 , 0 , 0 , 0 ) ); 
  if (fop -> flushing && ! scheme_force_port_closed )
    FUNCCALL(SETUP_XfOrM787(_), wait_until_fd_flushed (port , 0 ) ); 
  if (port -> closed )
    RET_NOTHING ; 
  if (fop -> refcount )
    * fop -> refcount -= 1 ; 
  if (! fop -> refcount || ! * fop -> refcount ) {
    {
      int cr ; 
      do {
        cr = close (fop -> fd ) ; 
      }
      while ((cr == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
    }
  }
  -- scheme_file_open_count ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int fd_output_buffer_mode (Scheme_Port * p , int mode ) {
  /* No conversion */
  Scheme_FD * fd ; 
  Scheme_Output_Port * op = (Scheme_Output_Port * ) p ; 
  fd = (Scheme_FD * ) op -> port_data ; 
  if (mode < 0 ) {
    return fd -> flush ; 
  }
  else {
    int go ; 
    go = (mode > fd -> flush ) ; 
    fd -> flush = mode ; 
    if (go )
      flush_fd (op , ((void * ) 0 ) , 0 , 0 , 0 , 0 ) ; 
    return mode ; 
  }
}
static Scheme_Object * make_fd_output_port (int fd , Scheme_Object * name , int regfile , int win_textmode , int and_read ) {
  Scheme_FD * fop ; 
  unsigned char * bfr ; 
  Scheme_Object * the_port ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(the_port, 0), PUSH(fop, 1), PUSH(name, 2), PUSH(bfr, 3)));
# define XfOrM795_COUNT (4)
# define SETUP_XfOrM795(x) SETUP(XfOrM795_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  fop = NULLED_OUT ; 
  bfr = NULLED_OUT ; 
  the_port = NULLED_OUT ; 
  fop = ((Scheme_FD * ) FUNCCALL(SETUP_XfOrM795(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_FD ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  fop -> type = scheme_rt_input_fd ; 
  bfr = (unsigned char * ) FUNCCALL(SETUP_XfOrM795(_), GC_malloc_atomic (4096 ) ); 
  fop -> buffer = bfr ; 
  fop -> fd = fd ; 
  fop -> bufcount = 0 ; 
  fop -> regfile = regfile ; 
  fop -> textmode = win_textmode ; 
  if (fd == 2 ) {
    fop -> flush = 2 ; 
  }
  else if (FUNCCALL(SETUP_XfOrM795(_), is_fd_terminal (fd ) )) {
    fop -> flush = 1 ; 
  }
  else {
    fop -> flush = 0 ; 
  }
  the_port = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM795(_), scheme_make_output_port (fd_output_port_type , fop , name , scheme_write_evt_via_write , fd_write_string , (Scheme_Out_Ready_Fun ) fd_write_ready , fd_close_output , (Scheme_Need_Wakeup_Output_Fun ) fd_write_need_wakeup , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ); 
  ((Scheme_Port * ) the_port ) -> buffer_mode_fun = fd_output_buffer_mode ; 
  if (and_read ) {
    int * rc ; 
    Scheme_Object * a [2 ] ; 
    BLOCK_SETUP((PUSHARRAY(a, 2, 0+XfOrM795_COUNT), PUSH(rc, 3+XfOrM795_COUNT)));
#   define XfOrM796_COUNT (4+XfOrM795_COUNT)
#   define SETUP_XfOrM796(x) SETUP(XfOrM796_COUNT)
    rc = NULLED_OUT ; 
    a[0] = NULLED_OUT ; 
    a[1] = NULLED_OUT ; 
    rc = (int * ) FUNCCALL(SETUP_XfOrM796(_), GC_malloc_atomic (sizeof (int ) ) ); 
    * rc = 2 ; 
    fop -> refcount = rc ; 
    a [1 ] = the_port ; 
    a [0 ] = FUNCCALL(SETUP_XfOrM796(_), make_fd_input_port (fd , name , regfile , win_textmode , rc ) ); 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM796(_), scheme_values (2 , a ) )) RET_VALUE_END ; 
  }
  else RET_VALUE_START (the_port ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void flush_if_output_fds (Scheme_Object * o , Scheme_Close_Custodian_Client * f , void * data ) {
  PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(o, 0)));
# define XfOrM800_COUNT (1)
# define SETUP_XfOrM800(x) SETUP(XfOrM800_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((scheme_is_output_port (o ) ) ) {
    Scheme_Output_Port * op ; 
    BLOCK_SETUP((PUSH(op, 0+XfOrM800_COUNT)));
#   define XfOrM801_COUNT (1+XfOrM800_COUNT)
#   define SETUP_XfOrM801(x) SETUP(XfOrM801_COUNT)
    op = NULLED_OUT ; 
    op = FUNCCALL(SETUP_XfOrM801(_), scheme_output_port_record (o ) ); 
    if (((op -> sub_type ) == (fd_output_port_type ) ) ) {
#     define XfOrM802_COUNT (0+XfOrM801_COUNT)
#     define SETUP_XfOrM802(x) SETUP_XfOrM801(x)
      FUNCCALL_EMPTY(scheme_flush_output (o ) ); 
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_fd_output_port (int fd , Scheme_Object * name , int regfile , int textmode , int read_too ) {
  /* No conversion */
  return make_fd_output_port (fd , name , regfile , textmode , read_too ) ; 
}
void scheme_block_child_signals (int block ) {
  sigset_t sigs ; 
  sigemptyset (& sigs ) ; 
  sigaddset (& sigs , 17 ) ; 
  sigaddset (& sigs , 27 ) ; 
  sigprocmask (block ? 0 : 1 , & sigs , ((void * ) 0 ) ) ; 
}
static void child_done (int ingored ) {
  pid_t result ; 
  int status ; 
  System_Child * sc , * prev ; 
  do {
    do {
      result = waitpid ((pid_t ) - 1 , & status , 1 ) ; 
    }
    while ((result == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
    if (result > 0 ) {
      if (((((__extension__ (((union {
        __typeof (status ) __in ; 
        int __i ; 
      }
      ) {
        . __in = (status ) }
      ) . __i ) ) ) & 0x7f ) == 0 ) )
        status = ((((__extension__ (((union {
        __typeof (status ) __in ; 
        int __i ; 
      }
      ) {
        . __in = (status ) }
      ) . __i ) ) ) & 0xff00 ) >> 8 ) ; 
      else status = - 1 ; 
      prev = ((void * ) 0 ) ; 
      for (sc = scheme_system_children ; sc ; prev = sc , sc = sc -> next ) {
        if (sc -> id == result ) {
          sc -> done = 1 ; 
          sc -> status = status ; 
          if (prev ) {
            prev -> next = sc -> next ; 
          }
          else scheme_system_children = sc -> next ; 
          scheme_signal_received () ; 
          break ; 
        }
      }
    }
  }
  while (result > 0 ) ; 
  signal (17 , child_done ) ; 
}
static int sigchld_installed = 0 ; 
static void init_sigchld (void ) {
  /* No conversion */
  if (! sigchld_installed ) {
    START_XFORM_SKIP ; 
    signal (17 , child_done ) ; 
    END_XFORM_SKIP ; 
    sigchld_installed = 1 ; 
  }
}
static long null_write_bytes (Scheme_Output_Port * port , const char * str , long d , long len , int rarely_block , int enable_break ) {
  /* No conversion */
  return len ; 
}
static void null_close_out (Scheme_Output_Port * port ) {
  /* No conversion */
}
static Scheme_Object * null_write_evt (Scheme_Output_Port * op , const char * str , long offset , long size ) {
  Scheme_Object * a [2 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 2, 0)));
# define XfOrM808_COUNT (3)
# define SETUP_XfOrM808(x) SETUP(XfOrM808_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  a [0 ] = scheme_always_ready_evt ; 
  a [1 ] = FUNCCALL(SETUP_XfOrM808(_), scheme_make_closed_prim (return_data , ((Scheme_Object * ) (void * ) (long ) ((((long ) (size ) ) << 1 ) | 0x1 ) ) ) ); 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM808(_), scheme_wrap_evt (2 , a ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * null_write_special_evt (Scheme_Output_Port * op , Scheme_Object * v ) {
  Scheme_Object * a [2 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 2, 0)));
# define XfOrM809_COUNT (3)
# define SETUP_XfOrM809(x) SETUP(XfOrM809_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  a [0 ] = scheme_always_ready_evt ; 
  a [1 ] = FUNCCALL(SETUP_XfOrM809(_), scheme_make_closed_prim (return_data , scheme_true ) ); 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM809(_), scheme_wrap_evt (2 , a ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int null_write_special (Scheme_Output_Port * op , Scheme_Object * v , int nonblock ) {
  /* No conversion */
  return 1 ; 
}
Scheme_Object * scheme_make_null_output_port (int can_write_special ) {
  Scheme_Output_Port * op ; 
  Scheme_Object * __funcarg32 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(op, 0)));
# define XfOrM811_COUNT (1)
# define SETUP_XfOrM811(x) SETUP(XfOrM811_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  op = NULLED_OUT ; 
  op = (__funcarg32 = FUNCCALL(SETUP_XfOrM811(_), scheme_intern_symbol ("null" ) ), FUNCCALL_AGAIN(scheme_make_output_port (scheme_null_output_port_type , ((void * ) 0 ) , __funcarg32 , null_write_evt , null_write_bytes , ((void * ) 0 ) , null_close_out , ((void * ) 0 ) , (can_write_special ? null_write_special_evt : ((void * ) 0 ) ) , (can_write_special ? null_write_special : ((void * ) 0 ) ) , 0 ) )) ; 
  RET_VALUE_START ((Scheme_Object * ) op ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static long redirect_write_bytes (Scheme_Output_Port * op , const char * str , long d , long len , int rarely_block , int enable_break ) {
  /* No conversion */
  return scheme_put_byte_string ("redirect-output" , (Scheme_Object * ) op -> port_data , str , d , len , rarely_block ) ; 
}
static void redirect_close_out (Scheme_Output_Port * port ) {
  /* No conversion */
}
static Scheme_Object * redirect_write_evt (Scheme_Output_Port * op , const char * str , long offset , long size ) {
  /* No conversion */
  return scheme_make_write_evt ("redirect-write-evt" , (Scheme_Object * ) op -> port_data , ((void * ) 0 ) , (char * ) str , offset , size ) ; 
}
static Scheme_Object * redirect_write_special_evt (Scheme_Output_Port * op , Scheme_Object * special ) {
  /* No conversion */
  return scheme_make_write_evt ("redirect-write-evt" , (Scheme_Object * ) op -> port_data , special , ((void * ) 0 ) , 0 , 0 ) ; 
}
static int redirect_write_special (Scheme_Output_Port * op , Scheme_Object * special , int nonblock ) {
  Scheme_Object * v , * a [2 ] ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSHARRAY(a, 2, 1)));
# define XfOrM816_COUNT (4)
# define SETUP_XfOrM816(x) SETUP(XfOrM816_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  a [0 ] = (Scheme_Object * ) op -> port_data ; 
  a [1 ] = special ; 
  if (nonblock )
    v = FUNCCALL(SETUP_XfOrM816(_), scheme_write_special (2 , a ) ); 
  else v = FUNCCALL(SETUP_XfOrM816(_), scheme_write_special (2 , a ) ); 
  RET_VALUE_START ((! (((v ) ) == (scheme_false ) ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_redirect_output_port (Scheme_Object * port ) {
  Scheme_Output_Port * op ; 
  int can_write_special ; 
  Scheme_Object * __funcarg33 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(op, 0), PUSH(port, 1)));
# define XfOrM817_COUNT (2)
# define SETUP_XfOrM817(x) SETUP(XfOrM817_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  op = NULLED_OUT ; 
  op = FUNCCALL(SETUP_XfOrM817(_), scheme_output_port_record (port ) ); 
  can_write_special = ! ! op -> write_special_fun ; 
  op = (__funcarg33 = FUNCCALL(SETUP_XfOrM817(_), scheme_intern_symbol ("redirect" ) ), FUNCCALL_AGAIN(scheme_make_output_port (scheme_redirect_output_port_type , port , __funcarg33 , redirect_write_evt , redirect_write_bytes , ((void * ) 0 ) , redirect_close_out , ((void * ) 0 ) , (can_write_special ? redirect_write_special_evt : ((void * ) 0 ) ) , (can_write_special ? redirect_write_special : ((void * ) 0 ) ) , 0 ) )) ; 
  RET_VALUE_START ((Scheme_Object * ) op ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int subp_done (Scheme_Object * sp ) {
  /* No conversion */
  void * sci = ((Scheme_Subprocess * ) sp ) -> handle ; 
  System_Child * sc = (System_Child * ) sci ; 
  return sc -> done ; 
}
static void subp_needs_wakeup (Scheme_Object * sp , void * fds ) {
  /* No conversion */
}
static Scheme_Object * subprocess_status (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  Scheme_Subprocess * sp = (Scheme_Subprocess * ) argv [0 ] ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_subprocess_type ) ) )
    scheme_wrong_type ("subprocess-status" , "subprocess" , 0 , argc , argv ) ; 
  {
    int going = 0 , status = - 1 ; 
    System_Child * sc = (System_Child * ) sp -> handle ; 
    if (sc -> done )
      status = sc -> status ; 
    else going = 1 ; 
    if (going )
      return scheme_intern_symbol ("running" ) ; 
    else return scheme_make_integer_value (status ) ; 
  }
}
static void register_subprocess_wait () {
  /* No conversion */
  scheme_add_evt (scheme_subprocess_type , subp_done , subp_needs_wakeup , ((void * ) 0 ) , 0 ) ; 
}
static Scheme_Object * subprocess_wait (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_subprocess_type ) ) )
    scheme_wrong_type ("subprocess-wait" , "subprocess" , 0 , argc , argv ) ; 
  {
    Scheme_Subprocess * sp = (Scheme_Subprocess * ) argv [0 ] ; 
    scheme_block_until (subp_done , subp_needs_wakeup , (Scheme_Object * ) sp , (float ) 0.0 ) ; 
    return scheme_void ; 
  }
}
static Scheme_Object * subprocess_kill (int argc , Scheme_Object * * argv ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM825_COUNT (1)
# define SETUP_XfOrM825(x) SETUP(XfOrM825_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_subprocess_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("subprocess-kill" , "subprocess" , 0 , argc , argv ) ); 
  {
    Scheme_Subprocess * sp = (Scheme_Subprocess * ) argv [0 ] ; 
    BLOCK_SETUP((PUSH(sp, 0+XfOrM825_COUNT)));
#   define XfOrM826_COUNT (1+XfOrM825_COUNT)
#   define SETUP_XfOrM826(x) SETUP(XfOrM826_COUNT)
    {
      System_Child * sc = (System_Child * ) sp -> handle ; 
      BLOCK_SETUP((PUSH(sc, 0+XfOrM826_COUNT)));
#     define XfOrM827_COUNT (1+XfOrM826_COUNT)
#     define SETUP_XfOrM827(x) SETUP(XfOrM827_COUNT)
      while (1 ) {
#       define XfOrM829_COUNT (0+XfOrM827_COUNT)
#       define SETUP_XfOrM829(x) SETUP_XfOrM827(x)
        if (sc -> done )
          RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
        if (! FUNCCALL(SETUP_XfOrM829(_), kill (sp -> pid , (! (((argv [1 ] ) ) == (scheme_false ) ) ) ? 9 : 2 ) ))
          RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
        if ((* __errno_location () ) != 4 )
          break ; 
      }
    }
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL , "subprocess-kill: failed (%E)" , (* __errno_location () ) ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * subprocess_pid (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_subprocess_type ) ) )
    scheme_wrong_type ("subprocess-pid" , "subprocess" , 0 , argc , argv ) ; 
  return scheme_make_integer_value (((Scheme_Subprocess * ) argv [0 ] ) -> pid ) ; 
}
static Scheme_Object * subprocess_p (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_subprocess_type ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * subprocess (int c , Scheme_Object * args [] ) {
  const char * name = "subprocess" ; 
  char * command ; 
  int to_subprocess [2 ] , from_subprocess [2 ] , err_subprocess [2 ] ; 
  int i , pid ; 
  char * * argv ; 
  Scheme_Object * in , * out , * err ; 
  System_Child * sc ; 
  Scheme_Object * inport ; 
  Scheme_Object * outport ; 
  Scheme_Object * errport ; 
  Scheme_Object * a [4 ] ; 
  Scheme_Subprocess * subproc ; 
  Scheme_Config * __funcarg37 = NULLED_OUT ; 
  Scheme_Object * __funcarg36 = NULLED_OUT ; 
  Scheme_Object * __funcarg35 = NULLED_OUT ; 
  Scheme_Object * __funcarg34 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(16);
  BLOCK_SETUP_TOP((PUSH(command, 0), PUSH(err, 1), PUSH(argv, 2), PUSH(subproc, 3), PUSH(sc, 4), PUSH(name, 5), PUSHARRAY(a, 4, 6), PUSH(outport, 9), PUSH(errport, 10), PUSH(out, 11), PUSH(args, 12), PUSH(inport, 13), PUSH(in, 14)));
# define XfOrM832_COUNT (15)
# define SETUP_XfOrM832(x) SETUP(XfOrM832_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  command = NULLED_OUT ; 
  argv = NULLED_OUT ; 
  in = NULLED_OUT ; 
  out = NULLED_OUT ; 
  err = NULLED_OUT ; 
  sc = NULLED_OUT ; 
  inport = NULLED_OUT ; 
  outport = NULLED_OUT ; 
  errport = NULLED_OUT ; 
  NULL_OUT_ARRAY (a ) ; 
  subproc = NULLED_OUT ; 
  if ((! (((args [0 ] ) ) == (scheme_false ) ) ) ) {
#   define XfOrM875_COUNT (0+XfOrM832_COUNT)
#   define SETUP_XfOrM875(x) SETUP_XfOrM832(x)
    outport = args [0 ] ; 
    if ((scheme_is_output_port (outport ) ) && (! (((FUNCCALL(SETUP_XfOrM875(_), scheme_file_stream_port_p (1 , & outport ) )) ) == (scheme_false ) ) ) ) {
      Scheme_Output_Port * op ; 
      BLOCK_SETUP((PUSH(op, 0+XfOrM875_COUNT)));
#     define XfOrM876_COUNT (1+XfOrM875_COUNT)
#     define SETUP_XfOrM876(x) SETUP(XfOrM876_COUNT)
      op = NULLED_OUT ; 
      op = FUNCCALL(SETUP_XfOrM876(_), scheme_output_port_record (outport ) ); 
      if (((op -> sub_type ) == (file_output_port_type ) ) ) {
        int tmp ; 
#       define XfOrM877_COUNT (0+XfOrM876_COUNT)
#       define SETUP_XfOrM877(x) SETUP_XfOrM876(x)
        tmp = FUNCCALL(SETUP_XfOrM877(_), fileno (((Scheme_Output_File * ) op -> port_data ) -> f ) ); 
        from_subprocess [1 ] = tmp ; 
      }
      else if (((op -> sub_type ) == (fd_output_port_type ) ) )
        from_subprocess [1 ] = ((Scheme_FD * ) op -> port_data ) -> fd ; 
    }
    else FUNCCALL(SETUP_XfOrM875(_), scheme_wrong_type (name , "file-stream-output-port" , 0 , c , args ) ); 
  }
  else outport = ((void * ) 0 ) ; 
  if ((! (((args [1 ] ) ) == (scheme_false ) ) ) ) {
#   define XfOrM872_COUNT (0+XfOrM832_COUNT)
#   define SETUP_XfOrM872(x) SETUP_XfOrM832(x)
    inport = args [1 ] ; 
    if ((scheme_is_input_port (inport ) ) && (! (((FUNCCALL(SETUP_XfOrM872(_), scheme_file_stream_port_p (1 , & inport ) )) ) == (scheme_false ) ) ) ) {
      Scheme_Input_Port * ip ; 
      BLOCK_SETUP((PUSH(ip, 0+XfOrM872_COUNT)));
#     define XfOrM873_COUNT (1+XfOrM872_COUNT)
#     define SETUP_XfOrM873(x) SETUP(XfOrM873_COUNT)
      ip = NULLED_OUT ; 
      ip = FUNCCALL(SETUP_XfOrM873(_), scheme_input_port_record (inport ) ); 
      if (((ip -> sub_type ) == (file_input_port_type ) ) ) {
        int tmp ; 
#       define XfOrM874_COUNT (0+XfOrM873_COUNT)
#       define SETUP_XfOrM874(x) SETUP_XfOrM873(x)
        tmp = FUNCCALL(SETUP_XfOrM874(_), fileno (((Scheme_Input_File * ) ip -> port_data ) -> f ) ); 
        to_subprocess [0 ] = tmp ; 
      }
      else if (((ip -> sub_type ) == (fd_input_port_type ) ) )
        to_subprocess [0 ] = ((Scheme_FD * ) ip -> port_data ) -> fd ; 
    }
    else FUNCCALL(SETUP_XfOrM872(_), scheme_wrong_type (name , "file-stream-input-port" , 1 , c , args ) ); 
  }
  else inport = ((void * ) 0 ) ; 
  if ((! (((args [2 ] ) ) == (scheme_false ) ) ) ) {
#   define XfOrM869_COUNT (0+XfOrM832_COUNT)
#   define SETUP_XfOrM869(x) SETUP_XfOrM832(x)
    errport = args [2 ] ; 
    if ((scheme_is_output_port (errport ) ) && (! (((FUNCCALL(SETUP_XfOrM869(_), scheme_file_stream_port_p (1 , & errport ) )) ) == (scheme_false ) ) ) ) {
      Scheme_Output_Port * op ; 
      BLOCK_SETUP((PUSH(op, 0+XfOrM869_COUNT)));
#     define XfOrM870_COUNT (1+XfOrM869_COUNT)
#     define SETUP_XfOrM870(x) SETUP(XfOrM870_COUNT)
      op = NULLED_OUT ; 
      op = FUNCCALL(SETUP_XfOrM870(_), scheme_output_port_record (errport ) ); 
      if (((op -> sub_type ) == (file_output_port_type ) ) ) {
        int tmp ; 
#       define XfOrM871_COUNT (0+XfOrM870_COUNT)
#       define SETUP_XfOrM871(x) SETUP_XfOrM870(x)
        tmp = FUNCCALL(SETUP_XfOrM871(_), fileno (((Scheme_Output_File * ) op -> port_data ) -> f ) ); 
        err_subprocess [1 ] = tmp ; 
      }
      else if (((op -> sub_type ) == (fd_output_port_type ) ) )
        err_subprocess [1 ] = ((Scheme_FD * ) op -> port_data ) -> fd ; 
    }
    else FUNCCALL(SETUP_XfOrM869(_), scheme_wrong_type (name , "file-stream-output-port" , 2 , c , args ) ); 
  }
  else errport = ((void * ) 0 ) ; 
  if (! (((Scheme_Type ) (((((long ) (args [3 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args [3 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (args [3 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args [3 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) )
    FUNCCALL(SETUP_XfOrM832(_), scheme_wrong_type (name , "path or string" , 3 , c , args ) ); 
  argv = ((char * * ) FUNCCALL(SETUP_XfOrM832(_), GC_malloc (sizeof (char * ) * (c - 3 + 1 ) ) )) ; 
  {
    char * ef ; 
    BLOCK_SETUP((PUSH(ef, 0+XfOrM832_COUNT)));
#   define XfOrM868_COUNT (1+XfOrM832_COUNT)
#   define SETUP_XfOrM868(x) SETUP(XfOrM868_COUNT)
    ef = NULLED_OUT ; 
    ef = FUNCCALL(SETUP_XfOrM868(_), scheme_expand_string_filename (args [3 ] , (char * ) name , ((void * ) 0 ) , 0x4 ) ); 
    argv [0 ] = ef ; 
  }
  {
    char * np ; 
    int nplen ; 
    BLOCK_SETUP((PUSH(np, 0+XfOrM832_COUNT)));
#   define XfOrM867_COUNT (1+XfOrM832_COUNT)
#   define SETUP_XfOrM867(x) SETUP(XfOrM867_COUNT)
    np = NULLED_OUT ; 
    nplen = strlen (argv [0 ] ) ; 
    np = FUNCCALL(SETUP_XfOrM867(_), scheme_normal_path_seps (argv [0 ] , & nplen , 0 ) ); 
    argv [0 ] = np ; 
  }
  if ((c == 6 ) && ((args [4 ] ) == (exact_symbol ) ) ) {
#   define XfOrM865_COUNT (0+XfOrM832_COUNT)
#   define SETUP_XfOrM865(x) SETUP_XfOrM832(x)
    argv [2 ] = ((void * ) 0 ) ; 
    if (! ((Scheme_Type ) (((((long ) (args [5 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args [5 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || FUNCCALL(SETUP_XfOrM865(_), scheme_any_string_has_null (args [5 ] ) ))
      FUNCCALL(SETUP_XfOrM865(_), scheme_wrong_type (name , "string (with no nul characters)" , 5 , c , args ) ); 
    {
      Scheme_Object * bs ; 
      BLOCK_SETUP((PUSH(bs, 0+XfOrM865_COUNT)));
#     define XfOrM866_COUNT (1+XfOrM865_COUNT)
#     define SETUP_XfOrM866(x) SETUP(XfOrM866_COUNT)
      bs = NULLED_OUT ; 
      bs = FUNCCALL(SETUP_XfOrM866(_), scheme_char_string_to_byte_string (args [5 ] ) ); 
      argv [1 ] = (((Scheme_Simple_Object * ) (bs ) ) -> u . byte_str_val . string_val ) ; 
    }
    FUNCCALL(SETUP_XfOrM865(_), scheme_arg_mismatch (name , "exact command line not supported on this platform: " , args [5 ] ) ); 
  }
  else {
#   define XfOrM860_COUNT (0+XfOrM832_COUNT)
#   define SETUP_XfOrM860(x) SETUP_XfOrM832(x)
    for (i = 4 ; i < c ; i ++ ) {
#     define XfOrM863_COUNT (0+XfOrM860_COUNT)
#     define SETUP_XfOrM863(x) SETUP_XfOrM860(x)
      if (! ((Scheme_Type ) (((((long ) (args [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || FUNCCALL(SETUP_XfOrM863(_), scheme_any_string_has_null (args [i ] ) ))
        FUNCCALL(SETUP_XfOrM863(_), scheme_wrong_type (name , "string (with no nul characters)" , i , c , args ) ); 
      {
        Scheme_Object * bs ; 
        BLOCK_SETUP((PUSH(bs, 0+XfOrM863_COUNT)));
#       define XfOrM864_COUNT (1+XfOrM863_COUNT)
#       define SETUP_XfOrM864(x) SETUP(XfOrM864_COUNT)
        bs = NULLED_OUT ; 
        bs = FUNCCALL(SETUP_XfOrM864(_), scheme_char_string_to_byte_string_locale (args [i ] ) ); 
        argv [i - 3 ] = (((Scheme_Simple_Object * ) (bs ) ) -> u . byte_str_val . string_val ) ; 
      }
    }
    argv [c - 3 ] = ((void * ) 0 ) ; 
  }
  command = argv [0 ] ; 
  if (! inport || ! outport || ! errport )
    FUNCCALL(SETUP_XfOrM832(_), scheme_custodian_check_available (((void * ) 0 ) , name , "file-stream" ) ); 
  if (! inport && FUNCCALL(SETUP_XfOrM832(_), pipe (to_subprocess ) ))
    FUNCCALL(SETUP_XfOrM832(_), scheme_raise_exn (MZEXN_FAIL , "%s: pipe failed (%e)" , name , (* __errno_location () ) ) ); 
  if (! outport && FUNCCALL(SETUP_XfOrM832(_), pipe (from_subprocess ) )) {
#   define XfOrM858_COUNT (0+XfOrM832_COUNT)
#   define SETUP_XfOrM858(x) SETUP_XfOrM832(x)
    if (! inport ) {
      close (to_subprocess [0 ] ) ; 
      close (to_subprocess [1 ] ) ; 
    }
    FUNCCALL(SETUP_XfOrM858(_), scheme_raise_exn (MZEXN_FAIL , "%s: pipe failed (%e)" , name , (* __errno_location () ) ) ); 
  }
  if (! errport && FUNCCALL(SETUP_XfOrM832(_), pipe (err_subprocess ) )) {
#   define XfOrM855_COUNT (0+XfOrM832_COUNT)
#   define SETUP_XfOrM855(x) SETUP_XfOrM832(x)
    if (! inport ) {
      close (to_subprocess [0 ] ) ; 
      close (to_subprocess [1 ] ) ; 
    }
    if (! outport ) {
      close (from_subprocess [0 ] ) ; 
      close (from_subprocess [1 ] ) ; 
    }
    FUNCCALL(SETUP_XfOrM855(_), scheme_raise_exn (MZEXN_FAIL , "%s: pipe failed (%e)" , name , (* __errno_location () ) ) ); 
  }
  {
#   define XfOrM852_COUNT (0+XfOrM832_COUNT)
#   define SETUP_XfOrM852(x) SETUP_XfOrM832(x)
    FUNCCALL(SETUP_XfOrM852(_), init_sigchld () ); 
    sc = ((System_Child * ) FUNCCALL(SETUP_XfOrM852(_), GC_malloc_one_small_tagged ((((sizeof (System_Child ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    sc -> type = scheme_rt_system_child ; 
    sc -> id = 0 ; 
    sc -> done = 0 ; 
    FUNCCALL(SETUP_XfOrM852(_), scheme_block_child_signals (1 ) ); 
    pid = FUNCCALL_AGAIN(fork () ); 
    if (pid > 0 ) {
      sc -> next = scheme_system_children ; 
      scheme_system_children = sc ; 
      sc -> id = pid ; 
    }
    else {
      struct itimerval t , old ; 
      sigset_t sigs ; 
#     define XfOrM853_COUNT (0+XfOrM852_COUNT)
#     define SETUP_XfOrM853(x) SETUP_XfOrM852(x)
      t . it_value . tv_sec = 0 ; 
      t . it_value . tv_usec = 0 ; 
      t . it_interval . tv_sec = 0 ; 
      t . it_interval . tv_usec = 0 ; 
      FUNCCALL(SETUP_XfOrM853(_), setitimer (ITIMER_PROF , & t , & old ) ); 
      sigemptyset (& sigs ) ; 
      while (! sigpending (& sigs ) ) {
        if (sigismember (& sigs , 27 ) ) {
          sigprocmask (2 , ((void * ) 0 ) , & sigs ) ; 
          sigdelset (& sigs , 27 ) ; 
          sigsuspend (& sigs ) ; 
          sigemptyset (& sigs ) ; 
        }
        else break ; 
      }
    }
    FUNCCALL(SETUP_XfOrM852(_), scheme_block_child_signals (0 ) ); 
  }
  switch (pid ) {
#   define XfOrM836_COUNT (0+XfOrM832_COUNT)
#   define SETUP_XfOrM836(x) SETUP_XfOrM832(x)
    case - 1 : if (! inport ) {
      close (to_subprocess [0 ] ) ; 
      close (to_subprocess [1 ] ) ; 
    }
    if (! outport ) {
      close (from_subprocess [0 ] ) ; 
      close (from_subprocess [1 ] ) ; 
    }
    if (! errport ) {
      close (err_subprocess [0 ] ) ; 
      close (err_subprocess [1 ] ) ; 
    }
    FUNCCALL(SETUP_XfOrM836(_), scheme_raise_exn (MZEXN_FAIL , "%s: fork failed" , name ) ); 
    RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    case 0 : {
#     define XfOrM839_COUNT (0+XfOrM836_COUNT)
#     define SETUP_XfOrM839(x) SETUP_XfOrM836(x)
      FUNCCALL(SETUP_XfOrM839(_), dup2 (to_subprocess [0 ] , 0 ) ); 
      FUNCCALL(SETUP_XfOrM839(_), dup2 (from_subprocess [1 ] , 1 ) ); 
      FUNCCALL_AGAIN(dup2 (err_subprocess [1 ] , 2 ) ); 
      if (! inport ) {
        close (to_subprocess [0 ] ) ; 
        close (to_subprocess [1 ] ) ; 
      }
      if (! outport ) {
        close (from_subprocess [0 ] ) ; 
        close (from_subprocess [1 ] ) ; 
      }
      if (! errport ) {
        close (err_subprocess [0 ] ) ; 
        close (err_subprocess [1 ] ) ; 
      }
      i = FUNCCALL(SETUP_XfOrM839(_), getdtablesize () ); 
      while (i -- > 3 ) {
        int cr ; 
        do {
          cr = close (i ) ; 
        }
        while ((cr == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
      }
    }
    {
      Scheme_Object * dir ; 
      BLOCK_SETUP((PUSH(dir, 0+XfOrM836_COUNT)));
#     define XfOrM838_COUNT (1+XfOrM836_COUNT)
#     define SETUP_XfOrM838(x) SETUP(XfOrM838_COUNT)
      dir = NULLED_OUT ; 
      dir = (__funcarg37 = FUNCCALL(SETUP_XfOrM838(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg37 , MZCONFIG_CURRENT_DIRECTORY ) )) ; 
      FUNCCALL_AGAIN(scheme_os_setcwd ((((Scheme_Simple_Object * ) (dir ) ) -> u . byte_str_val . string_val ) , 0 ) ); 
    }
    {
      int err ; 
#     define XfOrM837_COUNT (0+XfOrM836_COUNT)
#     define SETUP_XfOrM837(x) SETUP_XfOrM836(x)
      signal (8 , ((__sighandler_t ) 0 ) ) ; 
      signal (13 , ((__sighandler_t ) 0 ) ) ; 
      err = FUNCCALL(SETUP_XfOrM837(_), execv (command , argv ) ); 
      FUNCCALL_AGAIN(scheme_console_printf ("mzscheme: exec failed (%d)\n" , err ) ); 
      signal (8 , ((__sighandler_t ) 1 ) ) ; 
      signal (13 , ((__sighandler_t ) 1 ) ) ; 
      FUNCCALL(SETUP_XfOrM837(_), _exit (1 ) ); 
    }
    default : break ; 
  }
  if (! inport ) {
    close (to_subprocess [0 ] ) ; 
    out = ((void * ) 0 ) ; 
    scheme_file_open_count += 1 ; 
  }
  else out = scheme_false ; 
  if (! outport ) {
    close (from_subprocess [1 ] ) ; 
    in = ((void * ) 0 ) ; 
    scheme_file_open_count += 1 ; 
  }
  else in = scheme_false ; 
  if (! errport ) {
    close (err_subprocess [1 ] ) ; 
    err = ((void * ) 0 ) ; 
    scheme_file_open_count += 1 ; 
  }
  else err = scheme_false ; 
  in = (in ? in : (__funcarg36 = FUNCCALL(SETUP_XfOrM832(_), scheme_intern_symbol ("subprocess-stdout" ) ), FUNCCALL_AGAIN(make_fd_input_port (from_subprocess [0 ] , __funcarg36 , 0 , 0 , ((void * ) 0 ) ) )) ) ; 
  out = (out ? out : (__funcarg35 = FUNCCALL(SETUP_XfOrM832(_), scheme_intern_symbol ("subprocess-stdin" ) ), FUNCCALL_AGAIN(make_fd_output_port (to_subprocess [1 ] , __funcarg35 , 0 , 0 , 0 ) )) ) ; 
  err = (err ? err : (__funcarg34 = FUNCCALL(SETUP_XfOrM832(_), scheme_intern_symbol ("subprocess-stderr" ) ), FUNCCALL_AGAIN(make_fd_input_port (err_subprocess [0 ] , __funcarg34 , 0 , 0 , 0 ) )) ) ; 
  subproc = ((Scheme_Subprocess * ) FUNCCALL(SETUP_XfOrM832(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Subprocess ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  subproc -> so . type = scheme_subprocess_type ; 
  subproc -> handle = (void * ) sc ; 
  subproc -> pid = pid ; 
  a [0 ] = (Scheme_Object * ) subproc ; 
  a [1 ] = in ; 
  a [2 ] = out ; 
  a [3 ] = err ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM832(_), scheme_values (4 , a ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * sch_shell_execute (int c , Scheme_Object * argv [] ) {
  int show ; 
  char * dir ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(dir, 1)));
# define XfOrM878_COUNT (2)
# define SETUP_XfOrM878(x) SETUP(XfOrM878_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  dir = NULLED_OUT ; 
  if (! (((argv [0 ] ) ) == (scheme_false ) ) && ! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("shell-execute" , "string or #f" , 0 , c , argv ) ); 
  if (! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("shell-execute" , "string" , 1 , c , argv ) ); 
  if (! ((Scheme_Type ) (((((long ) (argv [2 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [2 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("shell-execute" , "string" , 2 , c , argv ) ); 
  if (! (((Scheme_Type ) (((((long ) (argv [3 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [3 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (argv [3 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [3 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("shell-execute" , "path or string" , 3 , c , argv ) ); 
  {
#   define XfOrM879_COUNT (0+XfOrM878_COUNT)
#   define SETUP_XfOrM879(x) SETUP_XfOrM878(x)
    show = 0 ; 
    if (((FUNCCALL(SETUP_XfOrM879(_), scheme_intern_symbol ("sw_hide" ) )) == (argv [4 ] ) ) || ((FUNCCALL(SETUP_XfOrM879(_), scheme_intern_symbol ("SW_HIDE" ) )) == (argv [4 ] ) ) )
      show = 1 ; 
    if (((FUNCCALL(SETUP_XfOrM879(_), scheme_intern_symbol ("sw_maximize" ) )) == (argv [4 ] ) ) || ((FUNCCALL(SETUP_XfOrM879(_), scheme_intern_symbol ("SW_MAXIMIZE" ) )) == (argv [4 ] ) ) )
      show = 1 ; 
    if (((FUNCCALL(SETUP_XfOrM879(_), scheme_intern_symbol ("sw_minimize" ) )) == (argv [4 ] ) ) || ((FUNCCALL(SETUP_XfOrM879(_), scheme_intern_symbol ("SW_MINIMIZE" ) )) == (argv [4 ] ) ) )
      show = 1 ; 
    if (((FUNCCALL(SETUP_XfOrM879(_), scheme_intern_symbol ("sw_restore" ) )) == (argv [4 ] ) ) || ((FUNCCALL(SETUP_XfOrM879(_), scheme_intern_symbol ("SW_RESTORE" ) )) == (argv [4 ] ) ) )
      show = 1 ; 
    if (((FUNCCALL(SETUP_XfOrM879(_), scheme_intern_symbol ("sw_show" ) )) == (argv [4 ] ) ) || ((FUNCCALL(SETUP_XfOrM879(_), scheme_intern_symbol ("SW_SHOW" ) )) == (argv [4 ] ) ) )
      show = 1 ; 
    if (((FUNCCALL(SETUP_XfOrM879(_), scheme_intern_symbol ("sw_showdefault" ) )) == (argv [4 ] ) ) || ((FUNCCALL(SETUP_XfOrM879(_), scheme_intern_symbol ("SW_SHOWDEFAULT" ) )) == (argv [4 ] ) ) )
      show = 1 ; 
    if (((FUNCCALL(SETUP_XfOrM879(_), scheme_intern_symbol ("sw_showmaximized" ) )) == (argv [4 ] ) ) || ((FUNCCALL(SETUP_XfOrM879(_), scheme_intern_symbol ("SW_SHOWMAXIMIZED" ) )) == (argv [4 ] ) ) )
      show = 1 ; 
    if (((FUNCCALL(SETUP_XfOrM879(_), scheme_intern_symbol ("sw_showminimized" ) )) == (argv [4 ] ) ) || ((FUNCCALL(SETUP_XfOrM879(_), scheme_intern_symbol ("SW_SHOWMINIMIZED" ) )) == (argv [4 ] ) ) )
      show = 1 ; 
    if (((FUNCCALL(SETUP_XfOrM879(_), scheme_intern_symbol ("sw_showminnoactive" ) )) == (argv [4 ] ) ) || ((FUNCCALL(SETUP_XfOrM879(_), scheme_intern_symbol ("SW_SHOWMINNOACTIVE" ) )) == (argv [4 ] ) ) )
      show = 1 ; 
    if (((FUNCCALL(SETUP_XfOrM879(_), scheme_intern_symbol ("sw_showna" ) )) == (argv [4 ] ) ) || ((FUNCCALL(SETUP_XfOrM879(_), scheme_intern_symbol ("SW_SHOWNA" ) )) == (argv [4 ] ) ) )
      show = 1 ; 
    if (((FUNCCALL(SETUP_XfOrM879(_), scheme_intern_symbol ("sw_shownoactivate" ) )) == (argv [4 ] ) ) || ((FUNCCALL(SETUP_XfOrM879(_), scheme_intern_symbol ("SW_SHOWNOACTIVATE" ) )) == (argv [4 ] ) ) )
      show = 1 ; 
    if (((FUNCCALL(SETUP_XfOrM879(_), scheme_intern_symbol ("sw_shownormal" ) )) == (argv [4 ] ) ) || ((FUNCCALL(SETUP_XfOrM879(_), scheme_intern_symbol ("SW_SHOWNORMAL" ) )) == (argv [4 ] ) ) )
      show = 1 ; 
    if (! show )
      FUNCCALL_EMPTY(scheme_wrong_type ("shell-execute" , "show-mode symbol" , 4 , c , argv ) ); 
  }
  dir = FUNCCALL_EMPTY(scheme_expand_string_filename (argv [3 ] , "shell-execute" , ((void * ) 0 ) , 0x10 ) ); 
  FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_UNSUPPORTED , "shell-execute: not supported on this platform" ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void default_sleep (float v , void * fds ) {
  PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(fds, 0)));
# define XfOrM880_COUNT (1)
# define SETUP_XfOrM880(x) SETUP(XfOrM880_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! fds ) {
    struct timeval time ; 
    long secs = (long ) v ; 
    long usecs = (long ) (fmod (v , 1.0 ) * 1000000 ) ; 
#   define XfOrM884_COUNT (0+XfOrM880_COUNT)
#   define SETUP_XfOrM884(x) SETUP_XfOrM880(x)
    if (v && (v > 100000 ) )
      secs = 100000 ; 
    if (usecs < 0 )
      usecs = 0 ; 
    if (usecs >= 1000000 )
      usecs = 999999 ; 
    time . tv_sec = secs ; 
    time . tv_usec = usecs ; 
    if (external_event_fd ) {
      static fd_set * readfds ; 
#     define XfOrM886_COUNT (0+XfOrM884_COUNT)
#     define SETUP_XfOrM886(x) SETUP_XfOrM884(x)
      (readfds = (readfds ? (fd_set * ) FUNCCALL(SETUP_XfOrM886(_), scheme_init_fdset_array (readfds , 1 ) ): (fd_set * ) FUNCCALL(SETUP_XfOrM886(_), scheme_alloc_fdset_array (1 , 1 ) )) ) ; 
      FUNCCALL(SETUP_XfOrM886(_), scheme_fdzero (readfds ) ); 
      FUNCCALL_AGAIN(scheme_fdset (readfds , external_event_fd ) ); 
      FUNCCALL_AGAIN(select (external_event_fd + 1 , readfds , ((void * ) 0 ) , ((void * ) 0 ) , & time ) ); 
    }
    else {
#     define XfOrM885_COUNT (0+XfOrM884_COUNT)
#     define SETUP_XfOrM885(x) SETUP_XfOrM884(x)
      FUNCCALL(SETUP_XfOrM885(_), select (0 , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , & time ) ); 
    }
  }
  else {
    int limit ; 
    fd_set * rd , * wr , * ex ; 
    struct timeval time ; 
    BLOCK_SETUP((PUSH(ex, 0+XfOrM880_COUNT), PUSH(wr, 1+XfOrM880_COUNT), PUSH(rd, 2+XfOrM880_COUNT)));
#   define XfOrM882_COUNT (3+XfOrM880_COUNT)
#   define SETUP_XfOrM882(x) SETUP(XfOrM882_COUNT)
    rd = NULLED_OUT ; 
    wr = NULLED_OUT ; 
    ex = NULLED_OUT ; 
    {
      long secs = (long ) v ; 
      long usecs = (long ) (fmod (v , 1.0 ) * 1000000 ) ; 
      if (v && (v > 100000 ) )
        secs = 100000 ; 
      if (usecs < 0 )
        usecs = 0 ; 
      if (usecs >= 1000000 )
        usecs = 999999 ; 
      time . tv_sec = secs ; 
      time . tv_usec = usecs ; 
    }
    limit = FUNCCALL(SETUP_XfOrM882(_), getdtablesize () ); 
    rd = (fd_set * ) fds ; 
    wr = (fd_set * ) FUNCCALL(SETUP_XfOrM882(_), scheme_get_fdset (fds , 1 ) ); 
    ex = (fd_set * ) FUNCCALL(SETUP_XfOrM882(_), scheme_get_fdset (fds , 2 ) ); 
    if (external_event_fd )
      FUNCCALL(SETUP_XfOrM882(_), scheme_fdset (rd , external_event_fd ) ); 
    FUNCCALL_EMPTY(select (limit , rd , wr , ex , v ? & time : ((void * ) 0 ) ) ); 
  }
  if (external_event_fd ) {
    char buf [10 ] ; 
#   define XfOrM881_COUNT (0+XfOrM880_COUNT)
#   define SETUP_XfOrM881(x) SETUP_XfOrM880(x)
    (read (external_event_fd , buf , 10 ) ) ; 
    event_fd_set = 0 ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_signal_received (void ) {
  if (put_external_event_fd && ! event_fd_set ) {
    event_fd_set = 1 ; 
    write (put_external_event_fd , "!" , 1 ) ; 
  }
}
int scheme_get_external_event_fd (void ) {
  /* No conversion */
  return external_event_fd ; 
}
static int mark_input_file_SIZE (void * p ) {
  return ((sizeof (Scheme_Input_File ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_input_file_MARK (void * p ) {
  Scheme_Input_File * i = (Scheme_Input_File * ) p ; 
  GC_mark (i -> f ) ; 
  return ((sizeof (Scheme_Input_File ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_input_file_FIXUP (void * p ) {
  Scheme_Input_File * i = (Scheme_Input_File * ) p ; 
  GC_fixup (& (i -> f ) ) ; 
  return ((sizeof (Scheme_Input_File ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_output_file_SIZE (void * p ) {
  return ((sizeof (Scheme_Output_File ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_output_file_MARK (void * p ) {
  Scheme_Output_File * o = (Scheme_Output_File * ) p ; 
  GC_mark (o -> f ) ; 
  return ((sizeof (Scheme_Output_File ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_output_file_FIXUP (void * p ) {
  Scheme_Output_File * o = (Scheme_Output_File * ) p ; 
  GC_fixup (& (o -> f ) ) ; 
  return ((sizeof (Scheme_Output_File ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_input_fd_SIZE (void * p ) {
  return ((sizeof (Scheme_FD ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_input_fd_MARK (void * p ) {
  Scheme_FD * fd = (Scheme_FD * ) p ; 
  GC_mark (fd -> buffer ) ; 
  GC_mark (fd -> refcount ) ; 
  return ((sizeof (Scheme_FD ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_input_fd_FIXUP (void * p ) {
  Scheme_FD * fd = (Scheme_FD * ) p ; 
  GC_fixup (& (fd -> buffer ) ) ; 
  GC_fixup (& (fd -> refcount ) ) ; 
  return ((sizeof (Scheme_FD ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_system_child_SIZE (void * p ) {
  return ((sizeof (System_Child ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_system_child_MARK (void * p ) {
  System_Child * sc = (System_Child * ) p ; 
  GC_mark (sc -> next ) ; 
  return ((sizeof (System_Child ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_system_child_FIXUP (void * p ) {
  System_Child * sc = (System_Child * ) p ; 
  GC_fixup (& (sc -> next ) ) ; 
  return ((sizeof (System_Child ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_subprocess_SIZE (void * p ) {
  return ((sizeof (Scheme_Subprocess ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_subprocess_MARK (void * p ) {
  Scheme_Subprocess * sp = (Scheme_Subprocess * ) p ; 
  GC_mark (sp -> handle ) ; 
  return ((sizeof (Scheme_Subprocess ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_subprocess_FIXUP (void * p ) {
  Scheme_Subprocess * sp = (Scheme_Subprocess * ) p ; 
  GC_fixup (& (sp -> handle ) ) ; 
  return ((sizeof (Scheme_Subprocess ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_read_write_evt_SIZE (void * p ) {
  return ((sizeof (Scheme_Read_Write_Evt ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_read_write_evt_MARK (void * p ) {
  Scheme_Read_Write_Evt * rww = (Scheme_Read_Write_Evt * ) p ; 
  GC_mark (rww -> port ) ; 
  GC_mark (rww -> v ) ; 
  GC_mark (rww -> str ) ; 
  return ((sizeof (Scheme_Read_Write_Evt ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_read_write_evt_FIXUP (void * p ) {
  Scheme_Read_Write_Evt * rww = (Scheme_Read_Write_Evt * ) p ; 
  GC_fixup (& (rww -> port ) ) ; 
  GC_fixup (& (rww -> v ) ) ; 
  GC_fixup (& (rww -> str ) ) ; 
  return ((sizeof (Scheme_Read_Write_Evt ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static void register_traversers (void ) {
  GC_register_traversers (scheme_rt_input_file , mark_input_file_SIZE , mark_input_file_MARK , mark_input_file_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_output_file , mark_output_file_SIZE , mark_output_file_MARK , mark_output_file_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_input_fd , mark_input_fd_SIZE , mark_input_fd_MARK , mark_input_fd_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_system_child , mark_system_child_SIZE , mark_system_child_MARK , mark_system_child_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_subprocess_type , mark_subprocess_SIZE , mark_subprocess_MARK , mark_subprocess_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_write_evt_type , mark_read_write_evt_SIZE , mark_read_write_evt_MARK , mark_read_write_evt_FIXUP , 1 , 0 ) ; 
}
