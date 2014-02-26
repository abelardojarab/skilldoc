#include "precomp.h"
typedef __intptr_t intptr_t ; 
extern int access (__const char * __name , int __type ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern int close (int __fd ) ; 
extern ssize_t read (int __fd , void * __buf , size_t __nbytes ) ; 
extern ssize_t write (int __fd , __const void * __buf , size_t __n ) ; 
extern int chdir (__const char * __path ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern char * getcwd (char * __buf , size_t __size ) __attribute__ ((__nothrow__ ) ) ; 
enum {
  _PC_LINK_MAX , _PC_MAX_CANON , _PC_MAX_INPUT , _PC_NAME_MAX , _PC_PATH_MAX , _PC_PIPE_BUF , _PC_CHOWN_RESTRICTED , _PC_NO_TRUNC , _PC_VDISABLE , _PC_SYNC_IO , _PC_ASYNC_IO , _PC_PRIO_IO , _PC_SOCK_MAXBUF , _PC_FILESIZEBITS , _PC_REC_INCR_XFER_SIZE , _PC_REC_MAX_XFER_SIZE , _PC_REC_MIN_XFER_SIZE , _PC_REC_XFER_ALIGN , _PC_ALLOC_SIZE_MIN , _PC_SYMLINK_MAX , _PC_2_SYMLINKS }
; 
enum {
  _SC_ARG_MAX , _SC_CHILD_MAX , _SC_CLK_TCK , _SC_NGROUPS_MAX , _SC_OPEN_MAX , _SC_STREAM_MAX , _SC_TZNAME_MAX , _SC_JOB_CONTROL , _SC_SAVED_IDS , _SC_REALTIME_SIGNALS , _SC_PRIORITY_SCHEDULING , _SC_TIMERS , _SC_ASYNCHRONOUS_IO , _SC_PRIORITIZED_IO , _SC_SYNCHRONIZED_IO , _SC_FSYNC , _SC_MAPPED_FILES , _SC_MEMLOCK , _SC_MEMLOCK_RANGE , _SC_MEMORY_PROTECTION , _SC_MESSAGE_PASSING , _SC_SEMAPHORES , _SC_SHARED_MEMORY_OBJECTS , _SC_AIO_LISTIO_MAX , _SC_AIO_MAX , _SC_AIO_PRIO_DELTA_MAX , _SC_DELAYTIMER_MAX , _SC_MQ_OPEN_MAX , _SC_MQ_PRIO_MAX , _SC_VERSION , _SC_PAGESIZE , _SC_RTSIG_MAX , _SC_SEM_NSEMS_MAX , _SC_SEM_VALUE_MAX , _SC_SIGQUEUE_MAX , _SC_TIMER_MAX , _SC_BC_BASE_MAX , _SC_BC_DIM_MAX , _SC_BC_SCALE_MAX , _SC_BC_STRING_MAX , _SC_COLL_WEIGHTS_MAX , _SC_EQUIV_CLASS_MAX , _SC_EXPR_NEST_MAX , _SC_LINE_MAX , _SC_RE_DUP_MAX , _SC_CHARCLASS_NAME_MAX , _SC_2_VERSION , _SC_2_C_BIND , _SC_2_C_DEV , _SC_2_FORT_DEV , _SC_2_FORT_RUN , _SC_2_SW_DEV , _SC_2_LOCALEDEF , _SC_PII , _SC_PII_XTI , _SC_PII_SOCKET , _SC_PII_INTERNET , _SC_PII_OSI , _SC_POLL , _SC_SELECT , _SC_UIO_MAXIOV , _SC_IOV_MAX = _SC_UIO_MAXIOV , _SC_PII_INTERNET_STREAM , _SC_PII_INTERNET_DGRAM , _SC_PII_OSI_COTS , _SC_PII_OSI_CLTS , _SC_PII_OSI_M , _SC_T_IOV_MAX , _SC_THREADS , _SC_THREAD_SAFE_FUNCTIONS , _SC_GETGR_R_SIZE_MAX , _SC_GETPW_R_SIZE_MAX , _SC_LOGIN_NAME_MAX , _SC_TTY_NAME_MAX , _SC_THREAD_DESTRUCTOR_ITERATIONS , _SC_THREAD_KEYS_MAX , _SC_THREAD_STACK_MIN , _SC_THREAD_THREADS_MAX , _SC_THREAD_ATTR_STACKADDR , _SC_THREAD_ATTR_STACKSIZE , _SC_THREAD_PRIORITY_SCHEDULING , _SC_THREAD_PRIO_INHERIT , _SC_THREAD_PRIO_PROTECT , _SC_THREAD_PROCESS_SHARED , _SC_NPROCESSORS_CONF , _SC_NPROCESSORS_ONLN , _SC_PHYS_PAGES , _SC_AVPHYS_PAGES , _SC_ATEXIT_MAX , _SC_PASS_MAX , _SC_XOPEN_VERSION , _SC_XOPEN_XCU_VERSION , _SC_XOPEN_UNIX , _SC_XOPEN_CRYPT , _SC_XOPEN_ENH_I18N , _SC_XOPEN_SHM , _SC_2_CHAR_TERM , _SC_2_C_VERSION , _SC_2_UPE , _SC_XOPEN_XPG2 , _SC_XOPEN_XPG3 , _SC_XOPEN_XPG4 , _SC_CHAR_BIT , _SC_CHAR_MAX , _SC_CHAR_MIN , _SC_INT_MAX , _SC_INT_MIN , _SC_LONG_BIT , _SC_WORD_BIT , _SC_MB_LEN_MAX , _SC_NZERO , _SC_SSIZE_MAX , _SC_SCHAR_MAX , _SC_SCHAR_MIN , _SC_SHRT_MAX , _SC_SHRT_MIN , _SC_UCHAR_MAX , _SC_UINT_MAX , _SC_ULONG_MAX , _SC_USHRT_MAX , _SC_NL_ARGMAX , _SC_NL_LANGMAX , _SC_NL_MSGMAX , _SC_NL_NMAX , _SC_NL_SETMAX , _SC_NL_TEXTMAX , _SC_XBS5_ILP32_OFF32 , _SC_XBS5_ILP32_OFFBIG , _SC_XBS5_LP64_OFF64 , _SC_XBS5_LPBIG_OFFBIG , _SC_XOPEN_LEGACY , _SC_XOPEN_REALTIME , _SC_XOPEN_REALTIME_THREADS , _SC_ADVISORY_INFO , _SC_BARRIERS , _SC_BASE , _SC_C_LANG_SUPPORT , _SC_C_LANG_SUPPORT_R , _SC_CLOCK_SELECTION , _SC_CPUTIME , _SC_THREAD_CPUTIME , _SC_DEVICE_IO , _SC_DEVICE_SPECIFIC , _SC_DEVICE_SPECIFIC_R , _SC_FD_MGMT , _SC_FIFO , _SC_PIPE , _SC_FILE_ATTRIBUTES , _SC_FILE_LOCKING , _SC_FILE_SYSTEM , _SC_MONOTONIC_CLOCK , _SC_MULTI_PROCESS , _SC_SINGLE_PROCESS , _SC_NETWORKING , _SC_READER_WRITER_LOCKS , _SC_SPIN_LOCKS , _SC_REGEXP , _SC_REGEX_VERSION , _SC_SHELL , _SC_SIGNALS , _SC_SPAWN , _SC_SPORADIC_SERVER , _SC_THREAD_SPORADIC_SERVER , _SC_SYSTEM_DATABASE , _SC_SYSTEM_DATABASE_R , _SC_TIMEOUTS , _SC_TYPED_MEMORY_OBJECTS , _SC_USER_GROUPS , _SC_USER_GROUPS_R , _SC_2_PBS , _SC_2_PBS_ACCOUNTING , _SC_2_PBS_LOCATE , _SC_2_PBS_MESSAGE , _SC_2_PBS_TRACK , _SC_SYMLOOP_MAX , _SC_STREAMS , _SC_2_PBS_CHECKPOINT , _SC_V6_ILP32_OFF32 , _SC_V6_ILP32_OFFBIG , _SC_V6_LP64_OFF64 , _SC_V6_LPBIG_OFFBIG , _SC_HOST_NAME_MAX , _SC_TRACE , _SC_TRACE_EVENT_FILTER , _SC_TRACE_INHERIT , _SC_TRACE_LOG , _SC_LEVEL1_ICACHE_SIZE , _SC_LEVEL1_ICACHE_ASSOC , _SC_LEVEL1_ICACHE_LINESIZE , _SC_LEVEL1_DCACHE_SIZE , _SC_LEVEL1_DCACHE_ASSOC , _SC_LEVEL1_DCACHE_LINESIZE , _SC_LEVEL2_CACHE_SIZE , _SC_LEVEL2_CACHE_ASSOC , _SC_LEVEL2_CACHE_LINESIZE , _SC_LEVEL3_CACHE_SIZE , _SC_LEVEL3_CACHE_ASSOC , _SC_LEVEL3_CACHE_LINESIZE , _SC_LEVEL4_CACHE_SIZE , _SC_LEVEL4_CACHE_ASSOC , _SC_LEVEL4_CACHE_LINESIZE , _SC_IPV6 = _SC_LEVEL1_ICACHE_SIZE + 50 , _SC_RAW_SOCKETS }
; 
enum {
  _CS_PATH , _CS_V6_WIDTH_RESTRICTED_ENVS , _CS_GNU_LIBC_VERSION , _CS_GNU_LIBPTHREAD_VERSION , _CS_LFS_CFLAGS = 1000 , _CS_LFS_LDFLAGS , _CS_LFS_LIBS , _CS_LFS_LINTFLAGS , _CS_LFS64_CFLAGS , _CS_LFS64_LDFLAGS , _CS_LFS64_LIBS , _CS_LFS64_LINTFLAGS , _CS_XBS5_ILP32_OFF32_CFLAGS = 1100 , _CS_XBS5_ILP32_OFF32_LDFLAGS , _CS_XBS5_ILP32_OFF32_LIBS , _CS_XBS5_ILP32_OFF32_LINTFLAGS , _CS_XBS5_ILP32_OFFBIG_CFLAGS , _CS_XBS5_ILP32_OFFBIG_LDFLAGS , _CS_XBS5_ILP32_OFFBIG_LIBS , _CS_XBS5_ILP32_OFFBIG_LINTFLAGS , _CS_XBS5_LP64_OFF64_CFLAGS , _CS_XBS5_LP64_OFF64_LDFLAGS , _CS_XBS5_LP64_OFF64_LIBS , _CS_XBS5_LP64_OFF64_LINTFLAGS , _CS_XBS5_LPBIG_OFFBIG_CFLAGS , _CS_XBS5_LPBIG_OFFBIG_LDFLAGS , _CS_XBS5_LPBIG_OFFBIG_LIBS , _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS , _CS_POSIX_V6_ILP32_OFF32_CFLAGS , _CS_POSIX_V6_ILP32_OFF32_LDFLAGS , _CS_POSIX_V6_ILP32_OFF32_LIBS , _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS , _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS , _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS , _CS_POSIX_V6_ILP32_OFFBIG_LIBS , _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS , _CS_POSIX_V6_LP64_OFF64_CFLAGS , _CS_POSIX_V6_LP64_OFF64_LDFLAGS , _CS_POSIX_V6_LP64_OFF64_LIBS , _CS_POSIX_V6_LP64_OFF64_LINTFLAGS , _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS , _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS , _CS_POSIX_V6_LPBIG_OFFBIG_LIBS , _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS }
; 
extern __uid_t getuid (void ) __attribute__ ((__nothrow__ ) ) ; 
extern __uid_t geteuid (void ) __attribute__ ((__nothrow__ ) ) ; 
extern __gid_t getgid (void ) __attribute__ ((__nothrow__ ) ) ; 
extern __gid_t getegid (void ) __attribute__ ((__nothrow__ ) ) ; 
extern int symlink (__const char * __from , __const char * __to ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern ssize_t readlink (__const char * __restrict __path , char * __restrict __buf , size_t __len ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern int unlink (__const char * __name ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern int rmdir (__const char * __path ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
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
extern int chmod (__const char * __file , __mode_t __mode ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern int mkdir (__const char * __path , __mode_t __mode ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
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
struct passwd {
  char * pw_name ; 
  char * pw_passwd ; 
  __uid_t pw_uid ; 
  __gid_t pw_gid ; 
  char * pw_gecos ; 
  char * pw_dir ; 
  char * pw_shell ; 
}
; 
extern struct passwd * getpwuid (__uid_t __uid ) ; 
extern struct passwd * getpwnam (__const char * __name ) ; 
enum {
  _ISupper = ((0 ) < 8 ? ((1 << (0 ) ) << 8 ) : ((1 << (0 ) ) >> 8 ) ) , _ISlower = ((1 ) < 8 ? ((1 << (1 ) ) << 8 ) : ((1 << (1 ) ) >> 8 ) ) , _ISalpha = ((2 ) < 8 ? ((1 << (2 ) ) << 8 ) : ((1 << (2 ) ) >> 8 ) ) , _ISdigit = ((3 ) < 8 ? ((1 << (3 ) ) << 8 ) : ((1 << (3 ) ) >> 8 ) ) , _ISxdigit = ((4 ) < 8 ? ((1 << (4 ) ) << 8 ) : ((1 << (4 ) ) >> 8 ) ) , _ISspace = ((5 ) < 8 ? ((1 << (5 ) ) << 8 ) : ((1 << (5 ) ) >> 8 ) ) , _ISprint = ((6 ) < 8 ? ((1 << (6 ) ) << 8 ) : ((1 << (6 ) ) >> 8 ) ) , _ISgraph = ((7 ) < 8 ? ((1 << (7 ) ) << 8 ) : ((1 << (7 ) ) >> 8 ) ) , _ISblank = ((8 ) < 8 ? ((1 << (8 ) ) << 8 ) : ((1 << (8 ) ) >> 8 ) ) , _IScntrl = ((9 ) < 8 ? ((1 << (9 ) ) << 8 ) : ((1 << (9 ) ) >> 8 ) ) , _ISpunct = ((10 ) < 8 ? ((1 << (10 ) ) << 8 ) : ((1 << (10 ) ) >> 8 ) ) , _ISalnum = ((11 ) < 8 ? ((1 << (11 ) ) << 8 ) : ((1 << (11 ) ) >> 8 ) ) }
; 
extern __const unsigned short int * * __ctype_b_loc (void ) __attribute__ ((__const ) ) ; 
struct dirent {
  __ino_t d_ino ; 
  __off_t d_off ; 
  unsigned short int d_reclen ; 
  unsigned char d_type ; 
  char d_name [256 ] ; 
}
; 
enum {
  DT_UNKNOWN = 0 , DT_FIFO = 1 , DT_CHR = 2 , DT_DIR = 4 , DT_BLK = 6 , DT_REG = 8 , DT_LNK = 10 , DT_SOCK = 12 , DT_WHT = 14 }
; 
typedef struct __dirstream DIR ; 
extern DIR * opendir (__const char * __name ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern int closedir (DIR * __dirp ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern struct dirent * readdir (DIR * __dirp ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
struct flock {
  short int l_type ; 
  short int l_whence ; 
  __off_t l_start ; 
  __off_t l_len ; 
  __pid_t l_pid ; 
}
; 
struct group {
  char * gr_name ; 
  char * gr_passwd ; 
  __gid_t gr_gid ; 
  char * * gr_mem ; 
}
; 
extern struct group * getgrgid (__gid_t __gid ) ; 
struct utimbuf {
  __time_t actime ; 
  __time_t modtime ; 
}
; 
extern int utime (__const char * __file , __const struct utimbuf * __file_times ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern int * __errno_location (void ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__const__ ) ) ; 
int scheme_ignore_user_paths ; 
void scheme_set_ignore_user_paths (int v ) {
  /* No conversion */
  scheme_ignore_user_paths = v ; 
}
static int check_dos_slashslash_drive (const char * next , int delta , int len , int * drive_end , int exact , int no_fw ) ; 
static int check_dos_slashslash_qm (const char * next , int len , int * drive_end , int * clean_start , int * add_sep ) ; 
static Scheme_Object * path_p (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * general_path_p (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * path_to_string (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * path_to_bytes (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * path_element_to_bytes (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * path_element_to_string (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * string_to_path (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * bytes_to_path (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * bytes_to_path_element (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * string_to_path_element (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * path_kind (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * platform_path_kind (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * file_exists (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * directory_exists (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * link_exists (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * build_path_kind (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * delete_file (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * rename_file (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * copy_file (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * path_to_directory_path (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * directory_list (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * filesystem_root_list (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * make_directory (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * delete_directory (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * make_link (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * split_path (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * relative_path_p (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * absolute_path_p (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * complete_path_p (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * path_to_complete_path (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * resolve_path (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * simplify_path (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * expand_path (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * current_drive (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * file_modify_seconds (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * file_or_dir_permissions (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * file_size (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * current_library_collection_paths (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * use_compiled_kind (int , Scheme_Object * [] ) ; 
static Scheme_Object * use_user_paths (int , Scheme_Object * [] ) ; 
static Scheme_Object * find_system_path (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * current_directory (int argc , Scheme_Object * argv [] ) ; 
static int has_null (const char * s , long l ) ; 
static void raise_null_error (const char * name , Scheme_Object * path , const char * mod ) ; 
static char * do_path_to_complete_path (char * filename , long ilen , const char * wrt , long wlen , int kind ) ; 
static Scheme_Object * do_simplify_path (Scheme_Object * path , Scheme_Object * cycle_check , int skip , int use_filesystem , int force_rel_up , int kind ) ; 
static char * do_normal_path_seps (char * si , int * _len , int delta , int strip_trail , int kind , int * _did ) ; 
static char * remove_redundant_slashes (char * filename , int * l , int delta , int * expanded , int kind ) ; 
static Scheme_Object * do_path_to_directory_path (char * s , long offset , long len , Scheme_Object * p , int just_check , int kind ) ; 
static Scheme_Object * up_symbol , * relative_symbol ; 
static Scheme_Object * same_symbol ; 
static Scheme_Object * read_symbol , * write_symbol , * execute_symbol ; 
static Scheme_Object * temp_dir_symbol , * home_dir_symbol , * pref_dir_symbol ; 
static Scheme_Object * doc_dir_symbol , * desk_dir_symbol ; 
static Scheme_Object * init_dir_symbol , * init_file_symbol , * sys_dir_symbol ; 
static Scheme_Object * exec_file_symbol , * run_file_symbol , * collects_dir_symbol ; 
static Scheme_Object * pref_file_symbol , * orig_dir_symbol , * addon_dir_symbol ; 
static Scheme_Object * exec_cmd , * run_cmd , * collects_path , * original_pwd ; 
static Scheme_Object * windows_symbol , * unix_symbol ; 
void scheme_init_file (Scheme_Env * env ) {
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
  FUNCCALL(SETUP_XfOrM2(_), scheme_register_static ((void * ) & up_symbol , sizeof (up_symbol ) ) ); 
  FUNCCALL(SETUP_XfOrM2(_), scheme_register_static ((void * ) & relative_symbol , sizeof (relative_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & same_symbol , sizeof (same_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & read_symbol , sizeof (read_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & write_symbol , sizeof (write_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & execute_symbol , sizeof (execute_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & temp_dir_symbol , sizeof (temp_dir_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & home_dir_symbol , sizeof (home_dir_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & pref_dir_symbol , sizeof (pref_dir_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & doc_dir_symbol , sizeof (doc_dir_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & desk_dir_symbol , sizeof (desk_dir_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & init_dir_symbol , sizeof (init_dir_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & init_file_symbol , sizeof (init_file_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & sys_dir_symbol , sizeof (sys_dir_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & pref_file_symbol , sizeof (pref_file_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & exec_file_symbol , sizeof (exec_file_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & run_file_symbol , sizeof (run_file_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & collects_dir_symbol , sizeof (collects_dir_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & orig_dir_symbol , sizeof (orig_dir_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & addon_dir_symbol , sizeof (addon_dir_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & windows_symbol , sizeof (windows_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & unix_symbol , sizeof (unix_symbol ) ) ); 
  up_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("up" ) ); 
  relative_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("relative" ) ); 
  same_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("same" ) ); 
  read_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("read" ) ); 
  write_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("write" ) ); 
  execute_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("execute" ) ); 
  temp_dir_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("temp-dir" ) ); 
  home_dir_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("home-dir" ) ); 
  doc_dir_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("doc-dir" ) ); 
  desk_dir_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("desk-dir" ) ); 
  pref_dir_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("pref-dir" ) ); 
  init_dir_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("init-dir" ) ); 
  init_file_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("init-file" ) ); 
  sys_dir_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("sys-dir" ) ); 
  pref_file_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("pref-file" ) ); 
  exec_file_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("exec-file" ) ); 
  run_file_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("run-file" ) ); 
  collects_dir_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("collects-dir" ) ); 
  orig_dir_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("orig-dir" ) ); 
  addon_dir_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("addon-dir" ) ); 
  windows_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("windows" ) ); 
  unix_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("unix" ) ); 
  (__funcarg46 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (path_p , "path?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("path?" , __funcarg46 , env ) )) ; 
  (__funcarg45 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_folding_prim (general_path_p , "path-for-some-system?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("path-for-some-system?" , __funcarg45 , env ) )) ; 
  (__funcarg44 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_folding_prim (path_kind , "path-convention-type" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("path-convention-type" , __funcarg44 , env ) )) ; 
  (__funcarg43 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (platform_path_kind , "system-path-convention-type" , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("system-path-convention-type" , __funcarg43 , env ) )) ; 
  (__funcarg42 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (path_to_string , "path->string" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("path->string" , __funcarg42 , env ) )) ; 
  (__funcarg41 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (path_to_bytes , "path->bytes" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("path->bytes" , __funcarg41 , env ) )) ; 
  (__funcarg40 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (path_element_to_bytes , "path-element->bytes" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("path-element->bytes" , __funcarg40 , env ) )) ; 
  (__funcarg39 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (path_element_to_string , "path-element->string" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("path-element->string" , __funcarg39 , env ) )) ; 
  (__funcarg38 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (string_to_path , "string->path" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string->path" , __funcarg38 , env ) )) ; 
  (__funcarg37 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (bytes_to_path , "bytes->path" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("bytes->path" , __funcarg37 , env ) )) ; 
  (__funcarg36 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (bytes_to_path_element , "bytes->path-element" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("bytes->path-element" , __funcarg36 , env ) )) ; 
  (__funcarg35 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (string_to_path_element , "string->path-element" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string->path-element" , __funcarg35 , env ) )) ; 
  (__funcarg34 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (file_exists , "file-exists?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("file-exists?" , __funcarg34 , env ) )) ; 
  (__funcarg33 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (directory_exists , "directory-exists?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("directory-exists?" , __funcarg33 , env ) )) ; 
  (__funcarg32 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (link_exists , "link-exists?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("link-exists?" , __funcarg32 , env ) )) ; 
  (__funcarg31 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (delete_file , "delete-file" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("delete-file" , __funcarg31 , env ) )) ; 
  (__funcarg30 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (rename_file , "rename-file-or-directory" , 2 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("rename-file-or-directory" , __funcarg30 , env ) )) ; 
  (__funcarg29 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (copy_file , "copy-file" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("copy-file" , __funcarg29 , env ) )) ; 
  (__funcarg28 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (scheme_build_path , "build-path" , 1 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("build-path" , __funcarg28 , env ) )) ; 
  (__funcarg27 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (build_path_kind , "build-path/convention-type" , 2 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("build-path/convention-type" , __funcarg27 , env ) )) ; 
  (__funcarg26 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (path_to_directory_path , "path->directory-path" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("path->directory-path" , __funcarg26 , env ) )) ; 
  (__funcarg25 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_everything (split_path , 0 , "split-path" , 1 , 1 , 0 , 3 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("split-path" , __funcarg25 , env ) )) ; 
  (__funcarg24 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (relative_path_p , "relative-path?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("relative-path?" , __funcarg24 , env ) )) ; 
  (__funcarg23 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (absolute_path_p , "absolute-path?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("absolute-path?" , __funcarg23 , env ) )) ; 
  (__funcarg22 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (complete_path_p , "complete-path?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("complete-path?" , __funcarg22 , env ) )) ; 
  (__funcarg21 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (path_to_complete_path , "path->complete-path" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("path->complete-path" , __funcarg21 , env ) )) ; 
  (__funcarg20 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (resolve_path , "resolve-path" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("resolve-path" , __funcarg20 , env ) )) ; 
  (__funcarg19 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (simplify_path , "simplify-path" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("simplify-path" , __funcarg19 , env ) )) ; 
  (__funcarg18 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (expand_path , "expand-path" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("expand-path" , __funcarg18 , env ) )) ; 
  (__funcarg17 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (directory_list , "directory-list" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("directory-list" , __funcarg17 , env ) )) ; 
  (__funcarg16 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (filesystem_root_list , "filesystem-root-list" , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("filesystem-root-list" , __funcarg16 , env ) )) ; 
  (__funcarg15 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (make_directory , "make-directory" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-directory" , __funcarg15 , env ) )) ; 
  (__funcarg14 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (delete_directory , "delete-directory" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("delete-directory" , __funcarg14 , env ) )) ; 
  (__funcarg13 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (make_link , "make-file-or-directory-link" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-file-or-directory-link" , __funcarg13 , env ) )) ; 
  (__funcarg12 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (file_modify_seconds , "file-or-directory-modify-seconds" , 1 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("file-or-directory-modify-seconds" , __funcarg12 , env ) )) ; 
  (__funcarg11 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (file_or_dir_permissions , "file-or-directory-permissions" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("file-or-directory-permissions" , __funcarg11 , env ) )) ; 
  (__funcarg10 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (file_size , "file-size" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("file-size" , __funcarg10 , env ) )) ; 
  (__funcarg9 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (current_drive , "current-drive" , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-drive" , __funcarg9 , env ) )) ; 
  (__funcarg8 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (find_system_path , "find-system-path" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("find-system-path" , __funcarg8 , env ) )) ; 
  (__funcarg7 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (current_directory , "current-directory" , MZCONFIG_CURRENT_DIRECTORY ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-directory" , __funcarg7 , env ) )) ; 
  (__funcarg6 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (current_library_collection_paths , "current-library-collection-paths" , MZCONFIG_COLLECTION_PATHS ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-library-collection-paths" , __funcarg6 , env ) )) ; 
  (__funcarg5 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (use_compiled_kind , "use-compiled-file-paths" , MZCONFIG_USE_COMPILED_KIND ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("use-compiled-file-paths" , __funcarg5 , env ) )) ; 
  (__funcarg4 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (use_user_paths , "use-user-specific-search-paths" , MZCONFIG_USE_USER_PATHS ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("use-user-specific-search-paths" , __funcarg4 , env ) )) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_sized_offset_kind_path (char * chars , long d , long len , int copy , int kind ) {
  Scheme_Object * s ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(s, 0)));
# define XfOrM3_COUNT (1)
# define SETUP_XfOrM3(x) SETUP(XfOrM3_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  s = FUNCCALL(SETUP_XfOrM3(_), scheme_make_sized_offset_byte_string (chars , d , len , copy ) ); 
  s -> type = kind ; 
  RET_VALUE_START (s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_sized_offset_path (char * chars , long d , long len , int copy ) {
  /* No conversion */
  return scheme_make_sized_offset_kind_path (chars , d , len , copy , scheme_unix_path_type ) ; 
}
static int is_special_filename (const char * _f , int offset , int len , int not_nul , int immediate ) ; 
static Scheme_Object * make_protected_sized_offset_path (int protect , char * chars , long d , long len , int copy , int just_check , int kind ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(chars, 0)));
# define XfOrM5_COUNT (1)
# define SETUP_XfOrM5(x) SETUP(XfOrM5_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (kind == scheme_windows_path_type ) {
#   define XfOrM9_COUNT (0+XfOrM5_COUNT)
#   define SETUP_XfOrM9(x) SETUP_XfOrM5(x)
    if (protect ) {
      int i ; 
#     define XfOrM10_COUNT (0+XfOrM9_COUNT)
#     define SETUP_XfOrM10(x) SETUP_XfOrM9(x)
      protect = 0 ; 
      if (! protect ) {
        int at_end = 1 ; 
        for (i = len ; i -- ; ) {
          if ((just_check != 2 ) && ((chars [i + d ] == '.' ) || (chars [i + d ] == ' ' ) ) ) {
            if (at_end ) {
              protect = 1 ; 
              break ; 
            }
          }
          else {
            at_end = 0 ; 
            if ((chars [i + d ] == '/' ) || (((((chars [i + d ] ) == '/' ) || ((chars [i + d ] ) == '\\' ) ) || ((chars [i + d ] ) == '"' ) || ((chars [i + d ] ) == '|' ) || ((chars [i + d ] ) == ':' ) || ((chars [i + d ] ) == '<' ) || ((chars [i + d ] ) == '>' ) ) ) ) {
              protect = 1 ; 
              break ; 
            }
          }
        }
      }
      if (! protect && (len == 1 ) && (chars [d ] == '.' ) )
        protect = 1 ; 
      if (! protect && (len == 2 ) && (chars [d ] == '.' ) && (chars [d + 1 ] == '.' ) )
        protect = 1 ; 
      if (! protect )
        protect = FUNCCALL(SETUP_XfOrM10(_), is_special_filename (chars , d , len , 0 , 1 ) ); 
      if (protect ) {
        char * s2 ; 
        BLOCK_SETUP((PUSH(s2, 0+XfOrM10_COUNT)));
#       define XfOrM11_COUNT (1+XfOrM10_COUNT)
#       define SETUP_XfOrM11(x) SETUP(XfOrM11_COUNT)
        s2 = NULLED_OUT ; 
        if (just_check )
          RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
        s2 = (char * ) FUNCCALL(SETUP_XfOrM11(_), GC_malloc_atomic (len + 9 + 1 ) ); 
        (memcpy (s2 , "\\\\?\\REL\\\\" , 9 ) ) ; 
        (memcpy (s2 + 9 , chars + d , len ) ) ; 
        s2 [9 + len ] = 0 ; 
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_offset_kind_path (s2 , 0 , len + 9 , 0 , scheme_windows_path_type ) )) RET_VALUE_EMPTY_END ; 
      }
    }
  }
  else {
#   define XfOrM6_COUNT (0+XfOrM5_COUNT)
#   define SETUP_XfOrM6(x) SETUP_XfOrM5(x)
    if (protect ) {
#     define XfOrM7_COUNT (0+XfOrM6_COUNT)
#     define SETUP_XfOrM7(x) SETUP_XfOrM6(x)
      if (chars [d ] == '~' ) {
        char * nm ; 
        BLOCK_SETUP((PUSH(nm, 0+XfOrM7_COUNT)));
#       define XfOrM8_COUNT (1+XfOrM7_COUNT)
#       define SETUP_XfOrM8(x) SETUP(XfOrM8_COUNT)
        nm = NULLED_OUT ; 
        if (just_check )
          RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
        nm = (char * ) FUNCCALL(SETUP_XfOrM8(_), GC_malloc_atomic (len + 3 ) ); 
        (memcpy (nm XFORM_OK_PLUS 2 , chars XFORM_OK_PLUS d , len ) ) ; 
        nm [0 ] = '.' ; 
        nm [1 ] = '/' ; 
        nm [len + 2 ] = 0 ; 
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_offset_kind_path (nm , 0 , len + 2 , 0 , kind ) )) RET_VALUE_EMPTY_END ; 
      }
    }
  }
  if (just_check )
    RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_offset_kind_path (chars , d , len , copy , kind ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * make_exposed_sized_offset_path (int already_protected , char * chars , long d , long len , int copy , int kind ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(chars, 0)));
# define XfOrM23_COUNT (1)
# define SETUP_XfOrM23(x) SETUP(XfOrM23_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (kind == scheme_windows_path_type ) {
#   define XfOrM26_COUNT (0+XfOrM23_COUNT)
#   define SETUP_XfOrM26(x) SETUP_XfOrM23(x)
    if (! already_protected ) {
      int i , name_end ; 
      int non_dot = 0 , trailing_dots = 0 , protect = 0 ; 
#     define XfOrM27_COUNT (0+XfOrM26_COUNT)
#     define SETUP_XfOrM27(x) SETUP_XfOrM26(x)
      for (i = d + len - 1 ; (i > d ) && (((chars [i ] ) == '/' ) || ((chars [i ] ) == '\\' ) ) ; -- i ) {
      }
      name_end = i + 1 ; 
      for (; (i > d ) && ! (((chars [i ] ) == '/' ) || ((chars [i ] ) == '\\' ) ) ; -- i ) {
        if ((chars [i ] != ' ' ) && (chars [i ] != '.' ) )
          non_dot = 1 ; 
        else if (! non_dot )
          trailing_dots = 1 ; 
      }
      if (non_dot && trailing_dots )
        protect = 1 ; 
      else if (name_end == (d + len ) )
        protect = FUNCCALL(SETUP_XfOrM27(_), is_special_filename (chars , i + 1 , name_end , 0 , 1 ) ); 
      if (protect ) {
        Scheme_Object * first , * last , * a [2 ] ; 
        char * s2 ; 
        int l ; 
        BLOCK_SETUP((PUSH(first, 0+XfOrM27_COUNT), PUSH(s2, 1+XfOrM27_COUNT), PUSHARRAY(a, 2, 2+XfOrM27_COUNT), PUSH(last, 5+XfOrM27_COUNT)));
#       define XfOrM28_COUNT (6+XfOrM27_COUNT)
#       define SETUP_XfOrM28(x) SETUP(XfOrM28_COUNT)
        first = NULLED_OUT ; 
        last = NULLED_OUT ; 
        a[0] = NULLED_OUT ; 
        a[1] = NULLED_OUT ; 
        s2 = NULLED_OUT ; 
        l = name_end - (i + 1 ) ; 
        s2 = (char * ) FUNCCALL(SETUP_XfOrM28(_), GC_malloc_atomic (l + 9 + 1 ) ); 
        (memcpy (s2 , "\\\\?\\REL\\\\" , 9 ) ) ; 
        (memcpy (s2 + 9 , chars + i + 1 , l ) ) ; 
        s2 [l + 9 ] = 0 ; 
        last = FUNCCALL(SETUP_XfOrM28(_), scheme_make_sized_offset_kind_path (s2 , 0 , l + 9 , 0 , scheme_windows_path_type ) ); 
        first = FUNCCALL_AGAIN(make_exposed_sized_offset_path (0 , chars , d , i - d + 1 , 1 , scheme_windows_path_type ) ); 
        a [0 ] = first ; 
        a [1 ] = last ; 
        RET_VALUE_START (FUNCCALL(SETUP_XfOrM28(_), scheme_build_path (2 , a ) )) RET_VALUE_END ; 
      }
    }
  }
  if (FUNCCALL(SETUP_XfOrM23(_), do_path_to_directory_path (chars , d , len - 1 , scheme_true , 1 , kind ) )) {
#   define XfOrM24_COUNT (0+XfOrM23_COUNT)
#   define SETUP_XfOrM24(x) SETUP_XfOrM23(x)
    if ((kind != scheme_windows_path_type ) || ! ((len == 3 ) && (((unsigned char ) chars [d ] < 128 ) && ((* FUNCCALL(SETUP_XfOrM24(_), __ctype_b_loc () )) [(int ) (((unsigned char ) chars [d ] ) ) ] & (unsigned short int ) _ISalpha ) ) && (chars [d + 1 ] == ':' ) ) ) {
      len -- ; 
      copy = 1 ; 
    }
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_offset_kind_path (chars , d , len , copy , kind ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_path (const char * chars ) {
  /* No conversion */
  return scheme_make_sized_offset_path ((char * ) chars , 0 , - 1 , 1 ) ; 
}
Scheme_Object * scheme_make_sized_path (char * chars , long len , int copy ) {
  /* No conversion */
  return scheme_make_sized_offset_path (chars , 0 , len , copy ) ; 
}
Scheme_Object * scheme_make_path_without_copying (char * chars ) {
  /* No conversion */
  return scheme_make_sized_offset_path (chars , 0 , - 1 , 0 ) ; 
}
static Scheme_Object * append_path (Scheme_Object * a , Scheme_Object * b ) {
  Scheme_Object * s ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(s, 0)));
# define XfOrM36_COUNT (1)
# define SETUP_XfOrM36(x) SETUP(XfOrM36_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  s = FUNCCALL(SETUP_XfOrM36(_), scheme_append_byte_string (a , b ) ); 
  s -> type = scheme_unix_path_type ; 
  RET_VALUE_START (s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_char_string_to_path (Scheme_Object * p ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(p, 0)));
# define XfOrM37_COUNT (1)
# define SETUP_XfOrM37(x) SETUP(XfOrM37_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  p = FUNCCALL(SETUP_XfOrM37(_), scheme_char_string_to_byte_string_locale (p ) ); 
  p -> type = scheme_unix_path_type ; 
  RET_VALUE_START (p ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * path_p (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * general_path_p (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return (((((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) <= scheme_windows_path_type ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * path_kind (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  if (((((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) <= scheme_windows_path_type ) ) ) {
    switch (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) {
      case scheme_windows_path_type : return windows_symbol ; 
      break ; 
      default : case scheme_unix_path_type : return unix_symbol ; 
      break ; 
    }
  }
  else {
    scheme_wrong_type ("path-system-type" , "path (for any system)" , 0 , argc , argv ) ; 
    return ((void * ) 0 ) ; 
  }
}
static Scheme_Object * platform_path_kind (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  switch (scheme_unix_path_type ) {
    case scheme_windows_path_type : return windows_symbol ; 
    break ; 
    default : case scheme_unix_path_type : return unix_symbol ; 
    break ; 
  }
}
/* this far 764 */
static Scheme_Object * drop_rel_prefix (Scheme_Object * p ) {
  int drive_end ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(p, 0)));
# define XfOrM46_COUNT (1)
# define SETUP_XfOrM46(x) SETUP(XfOrM46_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (FUNCCALL(SETUP_XfOrM46(_), check_dos_slashslash_qm ((((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . string_val ) , (((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . tag_val ) , & drive_end , ((void * ) 0 ) , ((void * ) 0 ) ) )) {
#   define XfOrM47_COUNT (0+XfOrM46_COUNT)
#   define SETUP_XfOrM47(x) SETUP_XfOrM46(x)
    if (drive_end < 0 ) {
      int delta ; 
#     define XfOrM48_COUNT (0+XfOrM47_COUNT)
#     define SETUP_XfOrM48(x) SETUP_XfOrM47(x)
      if ((((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . string_val ) [8 ] == '\\' )
        delta = 9 ; 
      else delta = 8 ; 
      p = FUNCCALL(SETUP_XfOrM48(_), scheme_make_sized_offset_kind_path ((((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . string_val ) , delta , (((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . tag_val ) - delta , 1 , scheme_windows_path_type ) ); 
    }
  }
  RET_VALUE_START (p ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_path_to_char_string (Scheme_Object * p ) {
  Scheme_Object * s ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(s, 0)));
# define XfOrM49_COUNT (1)
# define SETUP_XfOrM49(x) SETUP(XfOrM49_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  s = FUNCCALL(SETUP_XfOrM49(_), scheme_byte_string_to_char_string_locale (p ) ); 
  if (! (((Scheme_Simple_Object * ) (s ) ) -> u . char_str_val . tag_val ) )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_utf8_string ("?" ) )) RET_VALUE_EMPTY_END ; 
  else RET_VALUE_START (s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * path_to_string (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) )
    scheme_wrong_type ("path->string" , "path" , 0 , argc , argv ) ; 
  return scheme_path_to_char_string (argv [0 ] ) ; 
}
static Scheme_Object * path_to_bytes (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  if (! ((((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) <= scheme_windows_path_type ) ) )
    scheme_wrong_type ("path->bytes" , "path" , 0 , argc , argv ) ; 
  return scheme_make_sized_byte_string ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) , (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . tag_val ) , 1 ) ; 
}
static Scheme_Object * is_path_element (Scheme_Object * p ) {
  Scheme_Object * base , * fn ; 
  int isdir ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(base, 0), PUSH(fn, 1)));
# define XfOrM52_COUNT (2)
# define SETUP_XfOrM52(x) SETUP(XfOrM52_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  base = NULLED_OUT ; 
  fn = NULLED_OUT ; 
  fn = FUNCCALL(SETUP_XfOrM52(_), scheme_split_path ((((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . string_val ) , (((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . tag_val ) , & base , & isdir , ((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) ); 
  if (((Scheme_Type ) (((((long ) (base ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (base ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) && ((((((long ) (fn ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fn ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (fn ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fn ) ) -> type ) <= scheme_windows_path_type ) ) )
    RET_VALUE_START (fn ) RET_VALUE_END ; 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 854 */
static Scheme_Object * do_path_element_to_bytes (const char * name , int argc , Scheme_Object * * argv ) {
  Scheme_Object * p = argv [0 ] , * pe ; 
  int kind ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(pe, 0), PUSH(p, 1), PUSH(name, 2)));
# define XfOrM53_COUNT (3)
# define SETUP_XfOrM53(x) SETUP(XfOrM53_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  pe = NULLED_OUT ; 
  if (! ((((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) <= scheme_windows_path_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type (name , "path" , 0 , argc , argv ) ); 
  pe = FUNCCALL(SETUP_XfOrM53(_), is_path_element (p ) ); 
  if (! pe )
    FUNCCALL(SETUP_XfOrM53(_), scheme_arg_mismatch (name , "path can be split or is not relative: " , p ) ); 
  if (((Scheme_Type ) (((((long ) (pe ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (pe ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
#   define XfOrM57_COUNT (0+XfOrM53_COUNT)
#   define SETUP_XfOrM57(x) SETUP_XfOrM53(x)
    FUNCCALL(SETUP_XfOrM57(_), scheme_arg_mismatch (name , (((pe ) == (up_symbol ) ) ? "path is an up-directory indicator: " : "path is a same-directory indicator: " ) , p ) ); 
  }
  p = pe ; 
  kind = ((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ; 
  if (kind == scheme_unix_path_type ) {
#   define XfOrM55_COUNT (0+XfOrM53_COUNT)
#   define SETUP_XfOrM55(x) SETUP_XfOrM53(x)
    if (((((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . string_val ) [0 ] == '.' ) && ((((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . string_val ) [1 ] == '/' ) && ((((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . string_val ) [2 ] == '~' ) ) {
#     define XfOrM56_COUNT (0+XfOrM55_COUNT)
#     define SETUP_XfOrM56(x) SETUP_XfOrM55(x)
      p = FUNCCALL(SETUP_XfOrM56(_), scheme_make_sized_offset_byte_string ((((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . string_val ) , 2 , (((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . tag_val ) - 2 , 1 ) ); 
    }
  }
  if (kind == scheme_windows_path_type ) {
#   define XfOrM54_COUNT (0+XfOrM53_COUNT)
#   define SETUP_XfOrM54(x) SETUP_XfOrM53(x)
    p = FUNCCALL(SETUP_XfOrM54(_), drop_rel_prefix (p ) ); 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_byte_string ((((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . string_val ) , (((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . tag_val ) , 1 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * path_element_to_bytes (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return do_path_element_to_bytes ("path-element->bytes" , argc , argv ) ; 
}
static Scheme_Object * path_element_to_string (int argc , Scheme_Object * * argv ) {
  Scheme_Object * b ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(b, 0)));
# define XfOrM59_COUNT (1)
# define SETUP_XfOrM59(x) SETUP(XfOrM59_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  b = NULLED_OUT ; 
  b = FUNCCALL(SETUP_XfOrM59(_), do_path_element_to_bytes ("path-element->string" , argc , argv ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_byte_string_to_char_string_locale (b ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void check_path_ok (const char * who , Scheme_Object * p , Scheme_Object * o ) {
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(who, 1)));
# define XfOrM60_COUNT (2)
# define SETUP_XfOrM60(x) SETUP(XfOrM60_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (FUNCCALL(SETUP_XfOrM60(_), has_null ((((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . string_val ) , (((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . tag_val ) ) )) {
#   define XfOrM61_COUNT (0+XfOrM60_COUNT)
#   define SETUP_XfOrM61(x) SETUP_XfOrM60(x)
    FUNCCALL_EMPTY(raise_null_error (who , o , "" ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * string_to_path (int argc , Scheme_Object * * argv ) {
  Scheme_Object * p ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(p, 1)));
# define XfOrM62_COUNT (2)
# define SETUP_XfOrM62(x) SETUP(XfOrM62_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  p = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("string->path" , "string" , 0 , argc , argv ) ); 
  p = FUNCCALL(SETUP_XfOrM62(_), scheme_char_string_to_path (argv [0 ] ) ); 
  FUNCCALL_AGAIN(check_path_ok ("string->path" , p , argv [0 ] ) ); 
  RET_VALUE_START (p ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int extract_path_kind (const char * who , int which , int argc , Scheme_Object * * argv ) {
  /* No conversion */
  if (which >= argc )
    return scheme_unix_path_type ; 
  if (((argv [which ] ) == (windows_symbol ) ) )
    return scheme_windows_path_type ; 
  if (((argv [which ] ) == (unix_symbol ) ) )
    return scheme_unix_path_type ; 
  scheme_wrong_type (who , "'unix or 'windows" , which , argc , argv ) ; 
  return 0 ; 
}
static Scheme_Object * bytes_to_path (int argc , Scheme_Object * * argv ) {
  Scheme_Object * s ; 
  int kind ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(s, 1)));
# define XfOrM64_COUNT (2)
# define SETUP_XfOrM64(x) SETUP(XfOrM64_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("bytes->path" , "byte string" , 0 , argc , argv ) ); 
  kind = FUNCCALL(SETUP_XfOrM64(_), extract_path_kind ("bytes->path" , 1 , argc , argv ) ); 
  s = FUNCCALL_AGAIN(scheme_make_sized_byte_string ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) , (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . tag_val ) , (! (((Scheme_Inclhash_Object * ) (argv [0 ] ) ) -> so . keyex & 0x1 ) ) ) ); 
  s -> type = kind ; 
  FUNCCALL(SETUP_XfOrM64(_), check_path_ok ("bytes->path" , s , argv [0 ] ) ); 
  RET_VALUE_START (s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_bytes_to_path_element (const char * name , Scheme_Object * s , int argc , Scheme_Object * * argv ) {
  Scheme_Object * p ; 
  long i , len ; 
  int kind ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(name, 0), PUSH(argv, 1), PUSH(p, 2), PUSH(s, 3)));
# define XfOrM65_COUNT (4)
# define SETUP_XfOrM65(x) SETUP(XfOrM65_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  p = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (s ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (s ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type (name , "byte string" , 0 , argc , argv ) ); 
  kind = FUNCCALL(SETUP_XfOrM65(_), extract_path_kind (name , 1 , argc , argv ) ); 
  len = (((Scheme_Simple_Object * ) (s ) ) -> u . byte_str_val . tag_val ) ; 
  for (i = 0 ; i < len ; i ++ ) {
    if (((kind == scheme_unix_path_type ) ? (((((Scheme_Simple_Object * ) (s ) ) -> u . byte_str_val . string_val ) [i ] ) == '/' ) : (((((Scheme_Simple_Object * ) (s ) ) -> u . byte_str_val . string_val ) [i ] ) == '\\' ) ) ) {
      break ; 
    }
  }
  if (i >= len )
    p = FUNCCALL(SETUP_XfOrM65(_), make_protected_sized_offset_path (1 , (((Scheme_Simple_Object * ) (s ) ) -> u . byte_str_val . string_val ) , 0 , len , (! (((Scheme_Inclhash_Object * ) (s ) ) -> so . keyex & 0x1 ) ) , 0 , kind ) ); 
  else p = ((void * ) 0 ) ; 
  if (! p || ! FUNCCALL(SETUP_XfOrM65(_), is_path_element (p ) ))
    FUNCCALL(SETUP_XfOrM65(_), scheme_arg_mismatch (name , "cannot be converted to a path element (can be split, is not relative, or names a special element): " , argv [0 ] ) ); 
  RET_VALUE_START (p ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * bytes_to_path_element (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return do_bytes_to_path_element ("bytes->path-element" , argv [0 ] , argc , argv ) ; 
}
static Scheme_Object * string_to_path_element (int argc , Scheme_Object * * argv ) {
  Scheme_Object * b ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(b, 1)));
# define XfOrM71_COUNT (2)
# define SETUP_XfOrM71(x) SETUP(XfOrM71_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  b = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("string->path-element" , "string" , 0 , argc , argv ) ); 
  b = FUNCCALL(SETUP_XfOrM71(_), scheme_char_string_to_byte_string_locale (argv [0 ] ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(do_bytes_to_path_element ("string->path-element" , b , argc , argv ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
char * scheme_os_getcwd (char * buf , int buflen , int * actlen , int noexn ) {
  char buffer [1024 ] , * r , * gbuf ; 
  int obuflen = buflen ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(actlen, 0), PUSH(buf, 1), PUSH(r, 2)));
# define XfOrM72_COUNT (3)
# define SETUP_XfOrM72(x) SETUP(XfOrM72_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  r = NULLED_OUT ; 
  gbuf = NULLED_OUT ; 
  if (buflen < 1024 ) {
    gbuf = buffer ; 
    buflen = 1024 ; 
  }
  else gbuf = buf ; 
  r = FUNCCALL(SETUP_XfOrM72(_), getcwd (gbuf , buflen - 1 ) ); 
  if (! r ) {
    char * r2 ; 
    BLOCK_SETUP((PUSH(r2, 0+XfOrM72_COUNT)));
#   define XfOrM75_COUNT (1+XfOrM72_COUNT)
#   define SETUP_XfOrM75(x) SETUP(XfOrM75_COUNT)
    r2 = NULLED_OUT ; 
    r = FUNCCALL(SETUP_XfOrM75(_), getcwd (((void * ) 0 ) , 0 ) ); 
    if (! r ) {
#     define XfOrM76_COUNT (0+XfOrM75_COUNT)
#     define SETUP_XfOrM76(x) SETUP_XfOrM75(x)
      if (noexn ) {
        if (actlen )
          * actlen = 0 ; 
        if (buf ) {
          buf [0 ] = 0 ; 
          RET_VALUE_START (buf ) RET_VALUE_END ; 
        }
        else {
          RET_VALUE_START ("." ) RET_VALUE_END ; 
        }
      }
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_FILESYSTEM , "current-directory: unknown failure (%e)" , (* __errno_location () ) ) ); 
    }
    buflen = strlen (r ) + 1 ; 
    r2 = (char * ) FUNCCALL(SETUP_XfOrM75(_), GC_malloc_atomic (buflen ) ); 
    (memcpy (r2 , r , buflen ) ) ; 
    r2 [buflen ] = 0 ; 
    FUNCCALL(SETUP_XfOrM75(_), free (r ) ); 
    r = r2 ; 
    if (actlen )
      * actlen = buflen ; 
  }
  else {
    int slen = strlen (r ) + 1 ; 
#   define XfOrM73_COUNT (0+XfOrM72_COUNT)
#   define SETUP_XfOrM73(x) SETUP_XfOrM72(x)
    if (actlen )
      * actlen = slen ; 
    if (obuflen < slen )
      r = FUNCCALL(SETUP_XfOrM73(_), scheme_strdup (r ) ); 
    else if (r != buf ) {
#     define XfOrM74_COUNT (0+XfOrM73_COUNT)
#     define SETUP_XfOrM74(x) SETUP_XfOrM73(x)
      (memcpy (buf , r , slen ) ) ; 
      r = buf ; 
    }
  }
  RET_VALUE_START (r ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_os_setcwd (char * expanded , int noexn ) {
  int err ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(expanded, 0)));
# define XfOrM81_COUNT (1)
# define SETUP_XfOrM81(x) SETUP(XfOrM81_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  while (1 ) {
#   define XfOrM83_COUNT (0+XfOrM81_COUNT)
#   define SETUP_XfOrM83(x) SETUP_XfOrM81(x)
    err = FUNCCALL(SETUP_XfOrM83(_), chdir (expanded ) ); 
    if (! err || ((* __errno_location () ) != 4 ) )
      break ; 
  }
  if (err && ! noexn )
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_FILESYSTEM , "current-directory: unable to switch to directory: \"%q\"" , expanded ) ); 
  RET_VALUE_START (! err ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_get_file_directory (const char * filename ) {
  int isdir ; 
  Scheme_Object * base ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(base, 0)));
# define XfOrM84_COUNT (1)
# define SETUP_XfOrM84(x) SETUP(XfOrM84_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  base = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM84(_), scheme_split_path (filename , strlen (filename ) , & base , & isdir , scheme_unix_path_type ) ); 
  RET_VALUE_START (base ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 1179 */
Scheme_Object * scheme_remove_current_directory_prefix (Scheme_Object * fn ) {
  Scheme_Object * cwd ; 
  long len ; 
  Scheme_Config * __funcarg47 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(cwd, 0), PUSH(fn, 1)));
# define XfOrM85_COUNT (2)
# define SETUP_XfOrM85(x) SETUP(XfOrM85_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  cwd = NULLED_OUT ; 
  cwd = (__funcarg47 = FUNCCALL(SETUP_XfOrM85(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg47 , MZCONFIG_CURRENT_DIRECTORY ) )) ; 
  fn = (((((((long ) (fn ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fn ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (fn ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fn ) ) -> type ) <= scheme_windows_path_type ) ) ? fn : FUNCCALL(SETUP_XfOrM85(_), scheme_char_string_to_path (fn ) )) ; 
  len = (((Scheme_Simple_Object * ) (cwd ) ) -> u . byte_str_val . tag_val ) ; 
  if ((len < (((Scheme_Simple_Object * ) (fn ) ) -> u . byte_str_val . tag_val ) ) && ! (scheme_strncmp ((((Scheme_Simple_Object * ) (cwd ) ) -> u . byte_str_val . string_val ) , (((Scheme_Simple_Object * ) (fn ) ) -> u . byte_str_val . string_val ) , len ) ) ) {
#   define XfOrM86_COUNT (0+XfOrM85_COUNT)
#   define SETUP_XfOrM86(x) SETUP_XfOrM85(x)
    while (((scheme_unix_path_type == scheme_unix_path_type ) ? (((((Scheme_Simple_Object * ) (fn ) ) -> u . byte_str_val . string_val ) [len ] ) == '/' ) : ((((((Scheme_Simple_Object * ) (fn ) ) -> u . byte_str_val . string_val ) [len ] ) == '/' ) || (((((Scheme_Simple_Object * ) (fn ) ) -> u . byte_str_val . string_val ) [len ] ) == '\\' ) ) ) ) {
      len ++ ; 
    }
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_offset_path ((((Scheme_Simple_Object * ) (fn ) ) -> u . byte_str_val . string_val ) , len , (((Scheme_Simple_Object * ) (fn ) ) -> u . byte_str_val . tag_val ) - len , 1 ) )) RET_VALUE_EMPTY_END ; 
  }
  RET_VALUE_START (fn ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int has_null (const char * s , long l ) {
  /* No conversion */
  if (! l )
    return 1 ; 
  while (l -- ) {
    if (! s [l ] )
      return 1 ; 
  }
  return 0 ; 
}
static void raise_null_error (const char * name , Scheme_Object * path , const char * mod ) {
  /* No conversion */
  if (! (((Scheme_Type ) (((((long ) (path ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (path ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) ? (((Scheme_Simple_Object * ) (path ) ) -> u . char_str_val . tag_val ) : (((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . tag_val ) ) )
    scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: path string%s is empty" , name , mod ) ; 
  else scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: path string%s contains a null character: %Q" , name , mod , path ) ; 
}
static int check_dos_slashslash_qm (const char * next , int len , int * drive_end , int * clean_start , int * add_sep ) {
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(drive_end, 0), PUSH(clean_start, 1), PUSH(add_sep, 2), PUSH(next, 3)));
# define XfOrM93_COUNT (4)
# define SETUP_XfOrM93(x) SETUP(XfOrM93_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if ((len >= 4 ) && (next [0 ] == '\\' ) && (next [1 ] == '\\' ) && (next [2 ] == '?' ) && (next [3 ] == '\\' ) ) {
    int base ; 
#   define XfOrM94_COUNT (0+XfOrM93_COUNT)
#   define SETUP_XfOrM94(x) SETUP_XfOrM93(x)
    if (! drive_end && ! clean_start && ! add_sep )
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    if (next [4 ] == '\\' )
      base = 5 ; 
    else base = 4 ; 
    if ((len > 5 ) && (next [len - 1 ] == '\\' ) && (next [len - 2 ] == '\\' ) ) {
#     define XfOrM106_COUNT (0+XfOrM94_COUNT)
#     define SETUP_XfOrM106(x) SETUP_XfOrM94(x)
      if (len == 6 ) {
      }
      else if ((len != 8 ) || ! (((unsigned char ) next [base ] < 128 ) && ((* FUNCCALL(SETUP_XfOrM106(_), __ctype_b_loc () )) [(int ) (((unsigned char ) next [base ] ) ) ] & (unsigned short int ) _ISalpha ) ) || (next [base + 1 ] != ':' ) ) {
        if (drive_end )
          * drive_end = len ; 
        if (clean_start )
          * clean_start = len ; 
        if (add_sep )
          * add_sep = len ; 
        RET_VALUE_START (1 ) RET_VALUE_END ; 
      }
    }
    if (len > 6 ) {
      int i ; 
      for (i = len ; -- i > 5 ; ) {
        if ((next [i ] == '\\' ) && (next [i - 1 ] == '\\' ) && (next [i - 2 ] == '\\' ) ) {
          if (drive_end )
            * drive_end = i + 1 ; 
          if (clean_start )
            * clean_start = i + 1 ; 
          RET_VALUE_START (1 ) RET_VALUE_END ; 
        }
      }
    }
    if ((len > 6 ) && (((unsigned char ) next [base ] < 128 ) && ((* FUNCCALL(SETUP_XfOrM94(_), __ctype_b_loc () )) [(int ) (((unsigned char ) next [base ] ) ) ] & (unsigned short int ) _ISalpha ) ) && next [base + 1 ] == ':' && next [base + 2 ] == '\\' ) {
      if (clean_start )
        * clean_start = base + 2 ; 
      if (drive_end ) {
        if ((len > base + 3 ) && next [base + 3 ] == '\\' )
          * drive_end = base + 4 ; 
        else * drive_end = base + 3 ; 
      }
    }
    else if ((len > base + 3 ) && ((next [base ] == 'U' ) || (next [base ] == 'u' ) ) && ((next [base + 1 ] == 'N' ) || (next [base + 1 ] == 'n' ) ) && ((next [base + 2 ] == 'C' ) || (next [base + 2 ] == 'c' ) ) && (next [base + 3 ] == '\\' ) && FUNCCALL(SETUP_XfOrM94(_), check_dos_slashslash_drive (next , (((len > (base + 4 ) ) && (next [base + 4 ] == '\\' ) ) ? base + 5 : base + 4 ) , len , drive_end , 0 , 1 ) )) {
      if (clean_start )
        * clean_start = base + 3 ; 
    }
    else if ((base == 4 ) && (len > 8 ) && (next [4 ] == 'R' ) && (next [5 ] == 'E' ) && ((next [6 ] == 'L' ) || (next [6 ] == 'D' ) ) && (next [7 ] == '\\' ) && ((next [8 ] != '\\' ) || (len > 9 ) ) ) {
      if (drive_end )
        * drive_end = ((next [6 ] == 'L' ) ? - 1 : - 2 ) ; 
      if (clean_start )
        * clean_start = len ; 
    }
    else {
      if (drive_end )
        * drive_end = 4 ; 
      if (clean_start ) {
        if (((len == 5 ) && (next [4 ] == '\\' ) ) || ((len == 6 ) && (next [4 ] == '\\' ) && (next [5 ] == '\\' ) ) )
          * clean_start = 3 ; 
        else * clean_start = 4 ; 
      }
      if (add_sep )
        * add_sep = 4 ; 
    }
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  }
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int check_dos_slashslash_drive (const char * next , int delta , int len , int * drive_end , int exact , int no_fw ) {
  int j ; 
  int is_drive = 0 ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(drive_end, 0), PUSH(next, 1)));
# define XfOrM109_COUNT (2)
# define SETUP_XfOrM109(x) SETUP(XfOrM109_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (drive_end )
    * drive_end = len ; 
  if (! delta && FUNCCALL(SETUP_XfOrM109(_), check_dos_slashslash_qm (next , len , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) ) ))
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  if (delta || ((((next [0 ] ) == '/' ) || ((next [0 ] ) == '\\' ) ) && (((next [1 ] ) == '/' ) || ((next [1 ] ) == '\\' ) ) ) ) {
    j = delta ? delta : 2 ; 
    if (! (no_fw ? (next [j ] == '\\' ) : (((next [j ] ) == '/' ) || ((next [j ] ) == '\\' ) ) ) ) {
      for (; j < len ; j ++ ) {
        if ((no_fw ? (next [j ] == '\\' ) : (((next [j ] ) == '/' ) || ((next [j ] ) == '\\' ) ) ) ) {
          j ++ ; 
          if (no_fw && (j < len ) && (no_fw ? (next [j ] == '\\' ) : (((next [j ] ) == '/' ) || ((next [j ] ) == '\\' ) ) ) )
            j ++ ; 
          if ((j == (delta ? (delta + 2 ) : 4 ) ) && (next [j - 2 ] == '?' ) ) {
          }
          else if ((j < len ) && ! (no_fw ? (next [j ] == '\\' ) : (((next [j ] ) == '/' ) || ((next [j ] ) == '\\' ) ) ) ) {
            for (; j < len ; j ++ ) {
              if ((no_fw ? (next [j ] == '\\' ) : (((next [j ] ) == '/' ) || ((next [j ] ) == '\\' ) ) ) ) {
                if (drive_end )
                  * drive_end = j ; 
                if (exact ) {
                  for (; j < len ; j ++ ) {
                    if (! (no_fw ? (next [j ] == '\\' ) : (((next [j ] ) == '/' ) || ((next [j ] ) == '\\' ) ) ) ) {
                      break ; 
                    }
                  }
                }
                else is_drive = 1 ; 
                break ; 
              }
            }
            if (j >= len )
              is_drive = 1 ; 
            break ; 
          }
          break ; 
        }
        else if ((((next [j ] ) == '/' ) || ((next [j ] ) == '\\' ) ) ) {
          break ; 
        }
      }
    }
  }
  RET_VALUE_START (is_drive ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int get_slashslash_qm_dot_ups_end (const char * s , int len , int * _lit_start ) {
  /* No conversion */
  int pos = - 1 , j = 7 ; 
  if (s [6 ] == 'L' ) {
    while (1 ) {
      if (j + 3 > len ) {
        break ; 
      }
      else if ((s [j ] == '\\' ) && (s [j + 1 ] == '.' ) && (s [j + 2 ] == '.' ) && ((j + 3 == len ) || (s [j + 3 ] == '\\' ) ) ) {
        pos = j + 3 ; 
        j += 3 ; 
      }
      else {
        break ; 
      }
    }
  }
  if (pos > 0 ) {
    if (pos == len )
      * _lit_start = len ; 
    else if ((pos + 2 < len ) && s [pos + 1 ] == '\\' ) {
      * _lit_start = pos + 2 ; 
    }
    else {
      * _lit_start = pos + 1 ; 
    }
  }
  else if (len > 8 ) {
    if (s [8 ] == '\\' )
      * _lit_start = 9 ; 
    else * _lit_start = 8 ; 
  }
  else * _lit_start = len ; 
  return pos ; 
}
static char * convert_to_backslashbackslash_qm (char * cleaned , int * _clen , char * str , int * _alloc , int len ) {
  int clen = * _clen , pos ; 
  int alloc = * _alloc ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(_clen, 0), PUSH(cleaned, 1), PUSH(str, 2), PUSH(_alloc, 3)));
# define XfOrM164_COUNT (4)
# define SETUP_XfOrM164(x) SETUP(XfOrM164_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! str ) {
#   define XfOrM173_COUNT (0+XfOrM164_COUNT)
#   define SETUP_XfOrM173(x) SETUP_XfOrM164(x)
    alloc = clen + 10 ; 
    str = FUNCCALL(SETUP_XfOrM173(_), GC_malloc_atomic (alloc ) ); 
  }
  {
    int cde = 0 ; 
#   define XfOrM172_COUNT (0+XfOrM164_COUNT)
#   define SETUP_XfOrM172(x) SETUP_XfOrM164(x)
    if (! FUNCCALL(SETUP_XfOrM172(_), check_dos_slashslash_drive (cleaned , 0 , clen , & cde , 0 , 0 ) ))
      cde = 0 ; 
    cleaned = FUNCCALL(SETUP_XfOrM172(_), remove_redundant_slashes (cleaned , & clen , cde , ((void * ) 0 ) , scheme_windows_path_type ) ); 
  }
  cleaned = FUNCCALL(SETUP_XfOrM164(_), do_normal_path_seps (cleaned , & clen , 0 , 1 , scheme_windows_path_type , ((void * ) 0 ) ) ); 
  if (FUNCCALL(SETUP_XfOrM164(_), scheme_is_relative_path (cleaned , clen , scheme_windows_path_type ) )) {
#   define XfOrM171_COUNT (0+XfOrM164_COUNT)
#   define SETUP_XfOrM171(x) SETUP_XfOrM164(x)
    (memcpy (str , "\\\\?\\REL\\" , 8 ) ) ; 
    (memcpy (str + 8 , cleaned , clen ) ) ; 
    pos = clen + 8 ; 
  }
  else {
    int plen , xdel = 0 ; 
#   define XfOrM165_COUNT (0+XfOrM164_COUNT)
#   define SETUP_XfOrM165(x) SETUP_XfOrM164(x)
    if (cleaned [0 ] == '\\' ) {
#     define XfOrM168_COUNT (0+XfOrM165_COUNT)
#     define SETUP_XfOrM168(x) SETUP_XfOrM165(x)
      if (cleaned [1 ] == '\\' ) {
        xdel = 1 ; 
        plen = 7 ; 
        pos = 0 ; 
      }
      else {
#       define XfOrM169_COUNT (0+XfOrM168_COUNT)
#       define SETUP_XfOrM169(x) SETUP_XfOrM168(x)
        (memcpy (str , "\\\\?\\RED\\" , 8 ) ) ; 
        (memcpy (str + 8 , cleaned , clen ) ) ; 
        pos = clen + 8 ; 
        plen = 0 ; 
      }
    }
    else {
      plen = 4 ; 
      pos = 0 ; 
    }
    if (plen ) {
#     define XfOrM166_COUNT (0+XfOrM165_COUNT)
#     define SETUP_XfOrM166(x) SETUP_XfOrM165(x)
      (memcpy (str , "\\\\?\\UNC" , plen ) ) ; 
      (memcpy (str + plen , cleaned + xdel , clen - xdel ) ) ; 
      pos = clen + plen - xdel ; 
    }
  }
  * _alloc = alloc ; 
  * _clen = pos ; 
  RET_VALUE_START (str ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static char * get_drive_part (const char * wds , int wdlen ) {
  int dend , dstart = 0 ; 
  char * naya ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(naya, 0), PUSH(wds, 1)));
# define XfOrM174_COUNT (2)
# define SETUP_XfOrM174(x) SETUP(XfOrM174_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  naya = NULLED_OUT ; 
  if (FUNCCALL(SETUP_XfOrM174(_), check_dos_slashslash_qm (wds , wdlen , & dend , ((void * ) 0 ) , ((void * ) 0 ) ) )) {
  }
  else if (! FUNCCALL(SETUP_XfOrM174(_), check_dos_slashslash_drive (wds , 0 , wdlen , & dend , 0 , 0 ) ))
    dend = 3 ; 
  naya = FUNCCALL(SETUP_XfOrM174(_), GC_malloc_atomic (dend + 1 ) ); 
  (memcpy (naya + dstart , wds , dend ) ) ; 
  naya [dend ] = 0 ; 
  RET_VALUE_START (naya ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
char * scheme_getdrive () {
  /* No conversion */
  scheme_security_check_file ("current-drive" , ((void * ) 0 ) , 0x10 ) ; 
  return "" ; 
}
char * strip_trailing_spaces (const char * s , int * _len , int delta , int in_place ) {
  int len , skip_end = 0 ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(_len, 0), PUSH(s, 1)));
# define XfOrM177_COUNT (2)
# define SETUP_XfOrM177(x) SETUP(XfOrM177_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (_len )
    len = * _len ; 
  else len = strlen (s ) ; 
  if ((len - skip_end > delta ) && (((s [len - 1 - skip_end ] ) == '/' ) || ((s [len - 1 - skip_end ] ) == '\\' ) ) ) {
    skip_end ++ ; 
  }
  if ((len - skip_end > delta ) && ((s [len - 1 - skip_end ] == ' ' ) || (s [len - 1 - skip_end ] == '.' ) ) ) {
    char * t ; 
    int orig_len = len ; 
    BLOCK_SETUP((PUSH(t, 0+XfOrM177_COUNT)));
#   define XfOrM178_COUNT (1+XfOrM177_COUNT)
#   define SETUP_XfOrM178(x) SETUP(XfOrM178_COUNT)
    t = NULLED_OUT ; 
    while ((len - skip_end > delta ) && ((s [len - 1 - skip_end ] == ' ' ) || (s [len - 1 - skip_end ] == '.' ) ) ) {
      len -- ; 
    }
    if ((len - skip_end > delta ) && ! (((s [len - 1 - skip_end ] ) == '/' ) || ((s [len - 1 - skip_end ] ) == '\\' ) ) ) {
#     define XfOrM179_COUNT (0+XfOrM178_COUNT)
#     define SETUP_XfOrM179(x) SETUP_XfOrM178(x)
      if (in_place )
        t = (char * ) s ; 
      else {
#       define XfOrM180_COUNT (0+XfOrM179_COUNT)
#       define SETUP_XfOrM180(x) SETUP_XfOrM179(x)
        t = (char * ) FUNCCALL(SETUP_XfOrM180(_), GC_malloc_atomic (len + 1 ) ); 
        (memcpy (t , s , len - skip_end ) ) ; 
      }
      (memcpy (t + len - skip_end , t + orig_len - skip_end , skip_end ) ) ; 
      t [len ] = 0 ; 
      if (_len )
        * _len = len ; 
      RET_VALUE_START (t ) RET_VALUE_END ; 
    }
  }
  RET_VALUE_START ((char * ) s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static char * special_filenames [] = {
  "NUL" , "CON" , "PRN" , "AUX" , "COM1" , "COM2" , "COM3" , "COM4" , "COM5" , "COM6" , "COM7" , "COM8" , "COM9" , "LPT1" , "LPT2" , "LPT3" , "LPT4" , "LPT5" , "LPT6" , "LPT7" , "LPT8" , "LPT9" , ((void * ) 0 ) }
; 
static int is_special_filename (const char * f , int offset , int len , int not_nul , int immediate ) {
  int i , j , delta ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(f, 0)));
# define XfOrM184_COUNT (1)
# define SETUP_XfOrM184(x) SETUP(XfOrM184_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! len )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  if (! immediate ) {
#   define XfOrM197_COUNT (0+XfOrM184_COUNT)
#   define SETUP_XfOrM197(x) SETUP_XfOrM184(x)
    delta = len ; 
    if (FUNCCALL(SETUP_XfOrM197(_), check_dos_slashslash_qm (f , delta , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) ) ))
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    delta -= 1 ; 
    while (delta && ! (((f [delta ] ) == '/' ) || ((f [delta ] ) == '\\' ) ) ) {
      -- delta ; 
    }
    if (! delta && (((unsigned char ) f [0 ] < 128 ) && ((* FUNCCALL(SETUP_XfOrM197(_), __ctype_b_loc () )) [(int ) (((unsigned char ) f [0 ] ) ) ] & (unsigned short int ) _ISalpha ) ) && f [1 ] == ':' ) {
      delta = 2 ; 
    }
    else if ((((f [delta ] ) == '/' ) || ((f [delta ] ) == '\\' ) ) )
      delta ++ ; 
  }
  else delta = offset ; 
  for (i = not_nul ; special_filenames [i ] ; i ++ ) {
    const char * sf = special_filenames [i ] ; 
    for (j = 0 ; sf [j ] && f [delta + j ] ; j ++ ) {
      if (((mzchar ) (unsigned char ) f [delta + j ] + scheme_uchar_ups [(scheme_uchar_cases_table [((mzchar ) (unsigned char ) f [delta + j ] >> 8 ) & 0x1FFF ] [(mzchar ) (unsigned char ) f [delta + j ] & 0xFF ] ) ] ) != sf [j ] )
        break ; 
    }
    if (j && ! sf [j ] ) {
      j += delta ; 
      if ((j >= (len + delta ) ) || (f [j ] == '.' ) || (f [j ] == ':' ) )
        RET_VALUE_START (i + 1 ) RET_VALUE_END ; 
      while ((j < len + delta ) && ((f [j ] == ' ' ) || (f [j ] == '.' ) ) ) {
        j ++ ; 
      }
      if (j >= len + delta )
        RET_VALUE_START (i + 1 ) RET_VALUE_END ; 
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
  }
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static char * remove_redundant_slashes (char * filename , int * l , int delta , int * expanded , int kind ) {
  int extra = 0 , i , ilen = * l ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(expanded, 0), PUSH(filename, 1), PUSH(l, 2)));
# define XfOrM201_COUNT (3)
# define SETUP_XfOrM201(x) SETUP(XfOrM201_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  for (i = ilen ; -- i > delta ; ) {
    if (((kind == scheme_unix_path_type ) ? ((filename [i ] ) == '/' ) : (((filename [i ] ) == '/' ) || ((filename [i ] ) == '\\' ) ) ) ) {
      if (((kind == scheme_unix_path_type ) ? ((filename [i - 1 ] ) == '/' ) : (((filename [i - 1 ] ) == '/' ) || ((filename [i - 1 ] ) == '\\' ) ) ) ) {
        extra ++ ; 
      }
    }
  }
  if (extra ) {
    char * naya ; 
    BLOCK_SETUP((PUSH(naya, 0+XfOrM201_COUNT)));
#   define XfOrM202_COUNT (1+XfOrM201_COUNT)
#   define SETUP_XfOrM202(x) SETUP(XfOrM202_COUNT)
    naya = NULLED_OUT ; 
    naya = (char * ) FUNCCALL(SETUP_XfOrM202(_), GC_malloc_atomic (ilen + 1 - extra ) ); 
    extra = 0 ; 
    for (i = delta ; i < ilen ; i ++ ) {
      if (((kind == scheme_unix_path_type ) ? ((filename [i ] ) == '/' ) : (((filename [i ] ) == '/' ) || ((filename [i ] ) == '\\' ) ) ) && ((kind == scheme_unix_path_type ) ? ((filename [i + 1 ] ) == '/' ) : (((filename [i + 1 ] ) == '/' ) || ((filename [i + 1 ] ) == '\\' ) ) ) ) {
        extra ++ ; 
      }
      else {
        naya [i - extra ] = filename [i ] ; 
      }
    }
    (memcpy (naya , filename , delta ) ) ; 
    ilen -= extra ; 
    naya [ilen ] = 0 ; 
    filename = naya ; 
    if (expanded )
      * expanded = 1 ; 
  }
  * l = ilen ; 
  RET_VALUE_START (filename ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static char * do_expand_filename (Scheme_Object * o , char * filename , int ilen , const char * errorin , int * expanded , int report_bad_user , int fullpath , int guards , int kind ) {
  Scheme_Object * __funcarg49 = NULLED_OUT ; 
  __uid_t __funcarg48 ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(errorin, 0), PUSH(expanded, 1), PUSH(filename, 2), PUSH(o, 3)));
# define XfOrM215_COUNT (4)
# define SETUP_XfOrM215(x) SETUP(XfOrM215_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (expanded )
    * expanded = 0 ; 
  if (o ) {
#   define XfOrM257_COUNT (0+XfOrM215_COUNT)
#   define SETUP_XfOrM257(x) SETUP_XfOrM215(x)
    o = (((((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) <= scheme_windows_path_type ) ) ? o : FUNCCALL(SETUP_XfOrM257(_), scheme_char_string_to_path (o ) )) ; 
    filename = (((Scheme_Simple_Object * ) (o ) ) -> u . byte_str_val . string_val ) ; 
    ilen = (((Scheme_Simple_Object * ) (o ) ) -> u . byte_str_val . tag_val ) ; 
  }
  if (guards )
    FUNCCALL(SETUP_XfOrM215(_), scheme_security_check_file (errorin , filename , guards ) ); 
  if (ilen < 0 )
    ilen = strlen (filename ) ; 
  else {
#   define XfOrM255_COUNT (0+XfOrM215_COUNT)
#   define SETUP_XfOrM255(x) SETUP_XfOrM215(x)
    if (FUNCCALL(SETUP_XfOrM255(_), has_null (filename , ilen ) )) {
#     define XfOrM256_COUNT (0+XfOrM255_COUNT)
#     define SETUP_XfOrM256(x) SETUP_XfOrM255(x)
      if (errorin )
        (__funcarg49 = FUNCCALL(SETUP_XfOrM256(_), scheme_make_sized_path (filename , ilen , 1 ) ), FUNCCALL_AGAIN(raise_null_error (errorin , __funcarg49 , "" ) )) ; 
      else RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  if (kind == scheme_unix_path_type ) {
#   define XfOrM246_COUNT (0+XfOrM215_COUNT)
#   define SETUP_XfOrM246(x) SETUP_XfOrM215(x)
    if (filename [0 ] == '~' ) {
      char user [256 ] , * home = ((void * ) 0 ) , * naya ; 
      struct passwd * who = ((void * ) 0 ) ; 
      int u , f , len , flen ; 
      BLOCK_SETUP((PUSH(naya, 0+XfOrM246_COUNT), PUSH(home, 1+XfOrM246_COUNT), PUSH(who, 2+XfOrM246_COUNT)));
#     define XfOrM248_COUNT (3+XfOrM246_COUNT)
#     define SETUP_XfOrM248(x) SETUP(XfOrM248_COUNT)
      naya = NULLED_OUT ; 
      for (u = 0 , f = 1 ; u < 255 && filename [f ] && filename [f ] != '/' ; u ++ , f ++ ) {
        user [u ] = filename [f ] ; 
      }
      if (filename [f ] && filename [f ] != '/' ) {
#       define XfOrM252_COUNT (0+XfOrM248_COUNT)
#       define SETUP_XfOrM252(x) SETUP_XfOrM248(x)
        if (errorin && report_bad_user )
          FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_FILESYSTEM , "%s: bad username in path: \"%q\"" , errorin , filename ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      user [u ] = 0 ; 
      if (! user [0 ] ) {
#       define XfOrM250_COUNT (0+XfOrM248_COUNT)
#       define SETUP_XfOrM250(x) SETUP_XfOrM248(x)
        if (! (home = FUNCCALL(SETUP_XfOrM250(_), getenv ("HOME" ) )) ) {
          char * ptr ; 
          BLOCK_SETUP((PUSH(ptr, 0+XfOrM250_COUNT)));
#         define XfOrM251_COUNT (1+XfOrM250_COUNT)
#         define SETUP_XfOrM251(x) SETUP(XfOrM251_COUNT)
          ptr = NULLED_OUT ; 
          ptr = FUNCCALL(SETUP_XfOrM251(_), getenv ("USER" ) ); 
          if (! ptr )
            ptr = FUNCCALL(SETUP_XfOrM251(_), getenv ("LOGNAME" ) ); 
          who = ptr ? FUNCCALL(SETUP_XfOrM251(_), getpwnam (ptr ) ): ((void * ) 0 ) ; 
          if (! who )
            who = (__funcarg48 = FUNCCALL(SETUP_XfOrM251(_), getuid () ), FUNCCALL_AGAIN(getpwuid (__funcarg48 ) )) ; 
        }
      }
      else who = FUNCCALL(SETUP_XfOrM248(_), getpwnam (user ) ); 
      if (! home && who )
        home = who -> pw_dir ; 
      if (! home ) {
#       define XfOrM249_COUNT (0+XfOrM248_COUNT)
#       define SETUP_XfOrM249(x) SETUP_XfOrM248(x)
        if (errorin && report_bad_user )
          FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_FILESYSTEM , "%s: bad username in path: \"%q\"" , errorin , filename ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      len = strlen (home ) ; 
      if (f < ilen )
        flen = ilen - f - 1 ; 
      else flen = 0 ; 
      naya = (char * ) FUNCCALL(SETUP_XfOrM248(_), GC_malloc_atomic (len + flen + 2 ) ); 
      (memcpy (naya , home , len ) ) ; 
      naya [len ] = '/' ; 
      (memcpy (naya + len + 1 , filename + f + 1 , flen ) ) ; 
      naya [len + flen + 1 ] = 0 ; 
      if (expanded )
        * expanded = 1 ; 
      filename = naya ; 
      ilen = len + flen + 1 ; 
    }
    {
      int l = ilen ; 
#     define XfOrM247_COUNT (0+XfOrM246_COUNT)
#     define SETUP_XfOrM247(x) SETUP_XfOrM246(x)
      filename = FUNCCALL(SETUP_XfOrM247(_), remove_redundant_slashes (filename , & l , 0 , expanded , scheme_unix_path_type ) ); 
      ilen = l ; 
    }
  }
  else {
    int drive_end , clean_start ; 
    int fixit = 0 , i , insert_initial_sep = 0 ; 
#   define XfOrM221_COUNT (0+XfOrM215_COUNT)
#   define SETUP_XfOrM221(x) SETUP_XfOrM215(x)
    if (! FUNCCALL(SETUP_XfOrM221(_), check_dos_slashslash_qm (filename , ilen , & drive_end , & clean_start , ((void * ) 0 ) ) ))
      drive_end = 0 ; 
    else if (drive_end < 0 ) {
#     define XfOrM244_COUNT (0+XfOrM221_COUNT)
#     define SETUP_XfOrM244(x) SETUP_XfOrM221(x)
      FUNCCALL(SETUP_XfOrM244(_), get_slashslash_qm_dot_ups_end (filename , ilen , & drive_end ) ); 
      if ((drive_end != ilen ) && (filename [drive_end - 2 ] != '\\' ) ) {
        insert_initial_sep = 1 ; 
        fixit = 1 ; 
      }
    }
    else if (drive_end == 8 ) {
#     define XfOrM243_COUNT (0+XfOrM221_COUNT)
#     define SETUP_XfOrM243(x) SETUP_XfOrM221(x)
      if ((((unsigned char ) filename [4 ] < 128 ) && ((* FUNCCALL(SETUP_XfOrM243(_), __ctype_b_loc () )) [(int ) (((unsigned char ) filename [4 ] ) ) ] & (unsigned short int ) _ISalpha ) ) && (filename [5 ] == ':' ) )
        drive_end = 6 ; 
    }
    else if (drive_end == 9 ) {
#     define XfOrM242_COUNT (0+XfOrM221_COUNT)
#     define SETUP_XfOrM242(x) SETUP_XfOrM221(x)
      if ((filename [4 ] == '\\' ) && (((unsigned char ) filename [5 ] < 128 ) && ((* FUNCCALL(SETUP_XfOrM242(_), __ctype_b_loc () )) [(int ) (((unsigned char ) filename [5 ] ) ) ] & (unsigned short int ) _ISalpha ) ) && (filename [6 ] == ':' ) )
        drive_end = 7 ; 
    }
    else {
      drive_end = clean_start ; 
    }
    if (! drive_end && (((unsigned char ) filename [0 ] < 128 ) && ((* FUNCCALL(SETUP_XfOrM221(_), __ctype_b_loc () )) [(int ) (((unsigned char ) filename [0 ] ) ) ] & (unsigned short int ) _ISalpha ) ) && (filename [1 ] == ':' ) && ! (((filename [2 ] ) == '/' ) || ((filename [2 ] ) == '\\' ) ) ) {
      drive_end = 2 ; 
      insert_initial_sep = 1 ; 
      fixit = 1 ; 
    }
    else {
      int found_slash = 0 , prim_only = drive_end ; 
      for (i = ilen ; i -- > drive_end ; ) {
        if ((prim_only ? ((filename [i ] ) == '\\' ) : (((filename [i ] ) == '/' ) || ((filename [i ] ) == '\\' ) ) ) ) {
          if ((prim_only ? ((filename [i - 1 ] ) == '\\' ) : (((filename [i - 1 ] ) == '/' ) || ((filename [i - 1 ] ) == '\\' ) ) ) ) {
            if ((i > 1 ) || ! found_slash )
              fixit = 1 ; 
            break ; 
          }
          found_slash = 1 ; 
        }
      }
    }
    if (fixit ) {
      int pos , prim_only = drive_end ; 
      char * naya ; 
      BLOCK_SETUP((PUSH(naya, 0+XfOrM221_COUNT)));
#     define XfOrM222_COUNT (1+XfOrM221_COUNT)
#     define SETUP_XfOrM222(x) SETUP(XfOrM222_COUNT)
      naya = NULLED_OUT ; 
      if (expanded )
        * expanded = 1 ; 
      if (! drive_end ) {
#       define XfOrM232_COUNT (0+XfOrM222_COUNT)
#       define SETUP_XfOrM232(x) SETUP_XfOrM222(x)
        if (FUNCCALL(SETUP_XfOrM232(_), check_dos_slashslash_drive (filename , 0 , ilen , ((void * ) 0 ) , 0 , 0 ) ))
          drive_end = 2 ; 
      }
      naya = (char * ) FUNCCALL(SETUP_XfOrM222(_), GC_malloc_atomic (ilen + 2 ) ); 
      (memcpy (naya , filename , drive_end ) ) ; 
      pos = i = drive_end ; 
      if (insert_initial_sep ) {
        naya [pos ++ ] = '\\' ; 
      }
      while (i < ilen ) {
        if ((prim_only ? ((filename [i ] ) == '\\' ) : (((filename [i ] ) == '/' ) || ((filename [i ] ) == '\\' ) ) ) && ((i + 1 ) < ilen ) && (prim_only ? ((filename [i + 1 ] ) == '\\' ) : (((filename [i + 1 ] ) == '/' ) || ((filename [i + 1 ] ) == '\\' ) ) ) ) {
          i ++ ; 
        }
        else naya [pos ++ ] = filename [i ++ ] ; 
      }
      naya [pos ] = 0 ; 
      filename = naya ; 
      ilen = pos ; 
      if (drive_end == 4 ) {
#       define XfOrM223_COUNT (0+XfOrM222_COUNT)
#       define SETUP_XfOrM223(x) SETUP_XfOrM222(x)
        FUNCCALL(SETUP_XfOrM223(_), check_dos_slashslash_qm (filename , ilen , & drive_end , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
        if (drive_end != 4 ) {
#         define XfOrM224_COUNT (0+XfOrM223_COUNT)
#         define SETUP_XfOrM224(x) SETUP_XfOrM223(x)
          if (filename [4 ] == '\\' ) {
#           define XfOrM226_COUNT (0+XfOrM224_COUNT)
#           define SETUP_XfOrM226(x) SETUP_XfOrM224(x)
            (memmove (filename + 5 , filename + 4 , ilen - 3 ) ) ; 
            filename [4 ] = '\\' ; 
            ilen += 1 ; 
          }
          else {
#           define XfOrM225_COUNT (0+XfOrM224_COUNT)
#           define SETUP_XfOrM225(x) SETUP_XfOrM224(x)
            (memmove (filename + 6 , filename + 4 , ilen - 3 ) ) ; 
            filename [4 ] = '\\' ; 
            filename [5 ] = '\\' ; 
            ilen += 2 ; 
          }
        }
      }
    }
  }
  if (fullpath ) {
#   define XfOrM216_COUNT (0+XfOrM215_COUNT)
#   define SETUP_XfOrM216(x) SETUP_XfOrM215(x)
    if (! FUNCCALL(SETUP_XfOrM216(_), scheme_is_complete_path (filename , ilen , kind ) )) {
#     define XfOrM220_COUNT (0+XfOrM216_COUNT)
#     define SETUP_XfOrM220(x) SETUP_XfOrM216(x)
      if (expanded )
        * expanded = 1 ; 
      filename = FUNCCALL(SETUP_XfOrM220(_), do_path_to_complete_path (filename , ilen , ((void * ) 0 ) , 0 , kind ) ); 
      ilen = strlen (filename ) ; 
    }
    if (kind == scheme_windows_path_type ) {
#     define XfOrM217_COUNT (0+XfOrM216_COUNT)
#     define SETUP_XfOrM217(x) SETUP_XfOrM216(x)
      if (ilen > ((fullpath > 1 ) ? fullpath : 259 ) ) {
#       define XfOrM218_COUNT (0+XfOrM217_COUNT)
#       define SETUP_XfOrM218(x) SETUP_XfOrM217(x)
        if (! FUNCCALL(SETUP_XfOrM218(_), check_dos_slashslash_qm (filename , ilen , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) ) )) {
          int l = ilen , a = ilen + 1 ; 
          Scheme_Object * p ; 
          BLOCK_SETUP((PUSH(p, 0+XfOrM218_COUNT)));
#         define XfOrM219_COUNT (1+XfOrM218_COUNT)
#         define SETUP_XfOrM219(x) SETUP(XfOrM219_COUNT)
          p = NULLED_OUT ; 
          p = FUNCCALL(SETUP_XfOrM219(_), scheme_make_sized_path (filename , ilen , 0 ) ); 
          p = FUNCCALL_AGAIN(do_simplify_path (p , scheme_null , 0 , 1 , 0 , scheme_windows_path_type ) ); 
          filename = (((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . string_val ) ; 
          ilen = (((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . tag_val ) ; 
          filename = FUNCCALL(SETUP_XfOrM219(_), convert_to_backslashbackslash_qm (filename , & l , filename , & a , 0 ) ); 
          filename [l ] = 0 ; 
        }
      }
    }
  }
  RET_VALUE_START (filename ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
char * scheme_expand_filename (char * filename , int ilen , const char * errorin , int * expanded , int guards ) {
  /* No conversion */
  return do_expand_filename (((void * ) 0 ) , filename , ilen , errorin , expanded , 1 , 1 , guards , scheme_unix_path_type ) ; 
}
char * scheme_expand_string_filename (Scheme_Object * o , const char * errorin , int * expanded , int guards ) {
  /* No conversion */
  return do_expand_filename (o , ((void * ) 0 ) , 0 , errorin , expanded , 1 , 1 , guards , scheme_unix_path_type ) ; 
}
int scheme_file_exists (char * filename ) {
  struct stat buf ; 
  int ok ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(filename, 0)));
# define XfOrM260_COUNT (1)
# define SETUP_XfOrM260(x) SETUP(XfOrM260_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  do {
#   define XfOrM262_COUNT (0+XfOrM260_COUNT)
#   define SETUP_XfOrM262(x) SETUP_XfOrM260(x)
    ok = FUNCCALL(SETUP_XfOrM262(_), stat (filename , & buf ) ); 
  }
  while ((ok == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
  RET_VALUE_START (! ok && ! ((((buf . st_mode ) ) & 61440 ) == (16384 ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_directory_exists (char * dirname ) {
  struct stat buf ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(dirname, 0)));
# define XfOrM263_COUNT (1)
# define SETUP_XfOrM263(x) SETUP(XfOrM263_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  while (1 ) {
#   define XfOrM265_COUNT (0+XfOrM263_COUNT)
#   define SETUP_XfOrM265(x) SETUP_XfOrM263(x)
    if (! FUNCCALL(SETUP_XfOrM265(_), stat (dirname , & buf ) ))
      break ; 
    else if ((* __errno_location () ) != 4 )
      RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  RET_VALUE_START (((((buf . st_mode ) ) & 61440 ) == (16384 ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_is_regular_file (char * filename ) {
  struct stat buf ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(filename, 0)));
# define XfOrM266_COUNT (1)
# define SETUP_XfOrM266(x) SETUP(XfOrM266_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  while (1 ) {
#   define XfOrM268_COUNT (0+XfOrM266_COUNT)
#   define SETUP_XfOrM268(x) SETUP_XfOrM266(x)
    if (! FUNCCALL(SETUP_XfOrM268(_), stat (filename , & buf ) ))
      break ; 
    else if ((* __errno_location () ) != 4 )
      RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  RET_VALUE_START (((((buf . st_mode ) ) & 61440 ) == (32768 ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * file_exists (int argc , Scheme_Object * * argv ) {
  char * f ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(f, 0)));
# define XfOrM269_COUNT (1)
# define SETUP_XfOrM269(x) SETUP(XfOrM269_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  f = NULLED_OUT ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("file-exists?" , "path or string" , 0 , argc , argv ) ); 
  f = FUNCCALL(SETUP_XfOrM269(_), do_expand_filename (argv [0 ] , ((void * ) 0 ) , 0 , "file-exists?" , ((void * ) 0 ) , 0 , 1 , 0x10 , scheme_unix_path_type ) ); 
  RET_VALUE_START ((f && FUNCCALL_EMPTY(scheme_file_exists (f ) )) ? scheme_true : scheme_false ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * directory_exists (int argc , Scheme_Object * * argv ) {
  char * f ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(f, 0)));
# define XfOrM270_COUNT (1)
# define SETUP_XfOrM270(x) SETUP(XfOrM270_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  f = NULLED_OUT ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("directory-exists?" , "path or string" , 0 , argc , argv ) ); 
  f = FUNCCALL(SETUP_XfOrM270(_), do_expand_filename (argv [0 ] , ((void * ) 0 ) , 0 , "directory-exists?" , ((void * ) 0 ) , 0 , 1 , 0x10 , scheme_unix_path_type ) ); 
  RET_VALUE_START ((f && FUNCCALL_EMPTY(scheme_directory_exists (f ) )) ? scheme_true : scheme_false ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * link_exists (int argc , Scheme_Object * * argv ) {
  char * filename ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(filename, 0)));
# define XfOrM271_COUNT (1)
# define SETUP_XfOrM271(x) SETUP(XfOrM271_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  filename = NULLED_OUT ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("link-exists?" , "path or string" , 0 , argc , argv ) ); 
  {
    struct stat buf ; 
#   define XfOrM272_COUNT (0+XfOrM271_COUNT)
#   define SETUP_XfOrM272(x) SETUP_XfOrM271(x)
    filename = FUNCCALL(SETUP_XfOrM272(_), do_expand_filename (argv [0 ] , ((void * ) 0 ) , 0 , "link-exists?" , ((void * ) 0 ) , 0 , 1 , 0x10 , scheme_unix_path_type ) ); 
    while (1 ) {
#     define XfOrM274_COUNT (0+XfOrM272_COUNT)
#     define SETUP_XfOrM274(x) SETUP_XfOrM272(x)
      if (! FUNCCALL(SETUP_XfOrM274(_), lstat (filename , & buf ) ))
        break ; 
      else if ((* __errno_location () ) != 4 )
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    }
    if (((((buf . st_mode ) ) & 61440 ) == (40960 ) ) )
      RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
    else RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_get_fd_identity (Scheme_Object * port , long fd ) {
  int errid = 0 ; 
  unsigned long devi = 0 , inoi = 0 , inoi2 = 0 ; 
  int shift = 0 , shift2 = - 1 ; 
  Scheme_Object * devn , * inon , * a [2 ] ; 
  struct stat buf ; 
  Scheme_Object * __funcarg50 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(devn, 0), PUSHARRAY(a, 2, 1), PUSH(inon, 4)));
# define XfOrM275_COUNT (5)
# define SETUP_XfOrM275(x) SETUP(XfOrM275_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  devn = NULLED_OUT ; 
  inon = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  while (1 ) {
#   define XfOrM281_COUNT (0+XfOrM275_COUNT)
#   define SETUP_XfOrM281(x) SETUP_XfOrM275(x)
    if (! FUNCCALL(SETUP_XfOrM281(_), fstat (fd , & buf ) ))
      break ; 
    else if ((* __errno_location () ) != 4 ) {
      errid = (* __errno_location () ) ; 
      break ; 
    }
  }
  if (! errid ) {
    devi = (unsigned long ) buf . st_dev ; 
    inoi = (unsigned long ) buf . st_ino ; 
    shift = sizeof (dev_t ) ; 
  }
  if (! errid ) {
#   define XfOrM276_COUNT (0+XfOrM275_COUNT)
#   define SETUP_XfOrM276(x) SETUP_XfOrM275(x)
    devn = FUNCCALL(SETUP_XfOrM276(_), scheme_make_integer_value_from_unsigned (devi ) ); 
    inon = FUNCCALL(SETUP_XfOrM276(_), scheme_make_integer_value_from_unsigned (inoi ) ); 
    a [0 ] = inon ; 
    a [1 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (shift ) ) << 1 ) | 0x1 ) ) ; 
    inon = FUNCCALL(SETUP_XfOrM276(_), scheme_bitwise_shift (2 , a ) ); 
    if (shift2 > - 1 ) {
#     define XfOrM277_COUNT (0+XfOrM276_COUNT)
#     define SETUP_XfOrM277(x) SETUP_XfOrM276(x)
      a [0 ] = FUNCCALL(SETUP_XfOrM277(_), scheme_make_integer_value_from_unsigned (inoi2 ) ); 
      a [1 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (shift2 ) ) << 1 ) | 0x1 ) ) ; 
      inon = (__funcarg50 = FUNCCALL(SETUP_XfOrM277(_), scheme_bitwise_shift (2 , a ) ), FUNCCALL_AGAIN(scheme_bin_plus (inon , __funcarg50 ) )) ; 
    }
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM276(_), scheme_bin_plus (devn , inon ) )) RET_VALUE_END ; 
  }
  FUNCCALL(SETUP_XfOrM275(_), scheme_raise_exn (MZEXN_FAIL_FILESYSTEM , "port-file-identity: error obtaining identity (%E)" , errid ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int path_is_simple_dir_without_sep (Scheme_Object * path ) {
  int len ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(path, 0)));
# define XfOrM283_COUNT (1)
# define SETUP_XfOrM283(x) SETUP(XfOrM283_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  len = (((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . tag_val ) ; 
  if ((((((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . string_val ) [len - 1 ] == scheme_unix_path_type ) ? ((((((long ) (path ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (path ) ) -> type ) ) == '/' ) : (((((((long ) (path ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (path ) ) -> type ) ) == '/' ) || ((((((long ) (path ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (path ) ) -> type ) ) == '\\' ) ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  if ((((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . string_val ) [len - 1 ] == '.' ) {
    if (len == 1 )
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    if ((((((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . string_val ) [len - 2 ] == scheme_unix_path_type ) ? ((((((long ) (path ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (path ) ) -> type ) ) == '/' ) : (((((((long ) (path ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (path ) ) -> type ) ) == '/' ) || ((((((long ) (path ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (path ) ) -> type ) ) == '\\' ) ) ) )
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    if ((((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . string_val ) [len - 2 ] == '.' ) {
      if (len == 2 )
        RET_VALUE_START (1 ) RET_VALUE_END ; 
      if ((((((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . string_val ) [len - 3 ] == scheme_unix_path_type ) ? ((((((long ) (path ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (path ) ) -> type ) ) == '/' ) : (((((((long ) (path ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (path ) ) -> type ) ) == '/' ) || ((((((long ) (path ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (path ) ) -> type ) ) == '\\' ) ) ) )
        RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
  }
  if (((((long ) (path ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (path ) ) -> type ) == scheme_unix_path_type ) {
    if ((((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . string_val ) [0 ] == '~' ) {
      int i ; 
      for (i = 1 ; i < len ; i ++ ) {
        if ((((((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . string_val ) [i ] ) == '/' ) )
          break ; 
      }
      if (i == len )
        RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
  }
  if (((((long ) (path ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (path ) ) -> type ) == scheme_windows_path_type ) {
    int drive_end ; 
#   define XfOrM284_COUNT (0+XfOrM283_COUNT)
#   define SETUP_XfOrM284(x) SETUP_XfOrM283(x)
    if (FUNCCALL(SETUP_XfOrM284(_), check_dos_slashslash_drive ((((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . string_val ) , 0 , len , & drive_end , 1 , 0 ) ))
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    if (len == 2 && ((((unsigned char ) (((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . string_val ) [0 ] < 128 ) && ((* FUNCCALL(SETUP_XfOrM284(_), __ctype_b_loc () )) [(int ) (((unsigned char ) (((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . string_val ) [0 ] ) ) ] & (unsigned short int ) _ISalpha ) ) ) && ((((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . string_val ) [1 ] == ':' ) )
      RET_VALUE_START (1 ) RET_VALUE_END ; 
  }
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_path_to_directory_path (char * s , long offset , long len , Scheme_Object * p , int just_check , int kind ) {
  char * s2 ; 
  int not_a_sep = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(s2, 0), PUSH(s, 1), PUSH(p, 2)));
# define XfOrM291_COUNT (3)
# define SETUP_XfOrM291(x) SETUP(XfOrM291_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s2 = NULLED_OUT ; 
  if (kind == scheme_windows_path_type ) {
    int slash_dir_sep = 1 ; 
#   define XfOrM293_COUNT (0+XfOrM291_COUNT)
#   define SETUP_XfOrM293(x) SETUP_XfOrM291(x)
    {
      int drive_end ; 
#     define XfOrM295_COUNT (0+XfOrM293_COUNT)
#     define SETUP_XfOrM295(x) SETUP_XfOrM293(x)
      if (offset ) {
#       define XfOrM298_COUNT (0+XfOrM295_COUNT)
#       define SETUP_XfOrM298(x) SETUP_XfOrM295(x)
        FUNCCALL_EMPTY(scheme_signal_error ("path->directory-path currently assumes a 0 offset" ) ); 
      }
      if (FUNCCALL(SETUP_XfOrM295(_), check_dos_slashslash_qm (s , len , & drive_end , ((void * ) 0 ) , ((void * ) 0 ) ) )) {
        slash_dir_sep = 0 ; 
        not_a_sep = 1 ; 
      }
      else {
      }
    }
    {
      int cs = s [offset + len - 1 ] ; 
      if (slash_dir_sep ? (((cs ) == '/' ) || ((cs ) == '\\' ) ) : (cs == '\\' ) )
        RET_VALUE_START (p ) RET_VALUE_END ; 
    }
  }
  else {
    if (((s [offset + len - 1 ] ) == '/' ) )
      RET_VALUE_START (p ) RET_VALUE_END ; 
  }
  if (just_check )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  s2 = (char * ) FUNCCALL(SETUP_XfOrM291(_), GC_malloc_atomic (len + 2 ) ); 
  (memcpy (s2 , s XFORM_OK_PLUS offset , len ) ) ; 
  s2 [len ] = ((kind == scheme_unix_path_type ) ? '/' : '\\' ) ; 
  s2 [len + 1 ] = 0 ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_offset_kind_path (s2 , 0 , len + 1 , 0 , kind ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_path_to_directory_path (Scheme_Object * p ) {
  /* No conversion */
  return do_path_to_directory_path ((((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . string_val ) , 0 , (((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . tag_val ) , p , 0 , ((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) ; 
}
static char * do_normal_path_seps (char * si , int * _len , int delta , int strip_trail , int kind , int * _did ) {
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(_did, 0), PUSH(si, 1), PUSH(_len, 2)));
# define XfOrM300_COUNT (3)
# define SETUP_XfOrM300(x) SETUP(XfOrM300_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (kind == scheme_unix_path_type ) {
    RET_VALUE_START (si ) RET_VALUE_END ; 
  }
  else {
    int i ; 
    unsigned char * s ; 
    int len = * _len ; 
    BLOCK_SETUP((PUSH(s, 0+XfOrM300_COUNT)));
#   define XfOrM301_COUNT (1+XfOrM300_COUNT)
#   define SETUP_XfOrM301(x) SETUP(XfOrM301_COUNT)
    s = NULLED_OUT ; 
    if (kind == scheme_windows_path_type ) {
#     define XfOrM307_COUNT (0+XfOrM301_COUNT)
#     define SETUP_XfOrM307(x) SETUP_XfOrM301(x)
      if (! delta && FUNCCALL(SETUP_XfOrM307(_), check_dos_slashslash_qm (si , len , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) ) ))
        RET_VALUE_START (si ) RET_VALUE_END ; 
    }
    s = (unsigned char * ) ((char * ) FUNCCALL(SETUP_XfOrM301(_), GC_malloc_atomic (sizeof (char ) * (len + 1 ) ) )) ; 
    (memcpy (s , si , len + 1 ) ) ; 
    if (kind == scheme_windows_path_type ) {
#     define XfOrM302_COUNT (0+XfOrM301_COUNT)
#     define SETUP_XfOrM302(x) SETUP_XfOrM301(x)
      for (i = delta ; i < len ; i ++ ) {
        if (s [i ] == '/' ) {
          if (_did )
            * _did = 1 ; 
          s [i ] = '\\' ; 
        }
      }
      if (strip_trail )
        s = (unsigned char * ) FUNCCALL(SETUP_XfOrM302(_), strip_trailing_spaces ((char * ) s , _len , delta , 1 ) ); 
    }
    RET_VALUE_START ((char * ) s ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
char * scheme_normal_path_seps (char * si , int * _len , int delta ) {
  /* No conversion */
  return do_normal_path_seps (si , _len , delta , 1 , scheme_unix_path_type , ((void * ) 0 ) ) ; 
}
static Scheme_Object * do_build_path (int argc , Scheme_Object * * argv , int idelta , int no_final_simplify , int kind ) {
  int pos , i , len , no_sep ; 
  int alloc = 256 ; 
  char buffer [256 ] , * str , * next ; 
  int rel , next_off ; 
  int first_was_drive = 0 ; 
  int first_len = 0 ; 
  int needs_extra_slash = 0 ; 
  int pre_unc = 0 ; 
  int pre_qm = 0 ; 
  const char * who = (idelta ? "build-path/convention-type" : "build-path" ) ; 
  const char * __funcarg57 = NULLED_OUT ; 
  Scheme_Object * __funcarg56 = NULLED_OUT ; 
  Scheme_Object * __funcarg55 = NULLED_OUT ; 
  Scheme_Object * __funcarg51 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(str, 1), PUSH(who, 2), PUSH(next, 3)));
# define XfOrM310_COUNT (4)
# define SETUP_XfOrM310(x) SETUP(XfOrM310_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  str = NULLED_OUT ; 
  next = NULLED_OUT ; 
  str = buffer ; 
  pos = 0 ; 
  no_sep = 0 ; 
  for (i = 0 ; i < argc ; i ++ ) {
#   define XfOrM401_COUNT (0+XfOrM310_COUNT)
#   define SETUP_XfOrM401(x) SETUP_XfOrM310(x)
    if ((((Scheme_Type ) (((((long ) (argv [i + idelta ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i + idelta ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((((((long ) (argv [i + idelta ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i + idelta ] ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (argv [i + idelta ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i + idelta ] ) ) -> type ) <= scheme_windows_path_type ) ) ) || (((Scheme_Type ) (((((long ) (argv [i + idelta ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i + idelta ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) && (((argv [i + idelta ] ) == (up_symbol ) ) || ((argv [i + idelta ] ) == (same_symbol ) ) ) ) ) {
#     define XfOrM403_COUNT (0+XfOrM401_COUNT)
#     define SETUP_XfOrM403(x) SETUP_XfOrM401(x)
      next_off = 0 ; 
      if (((argv [i + idelta ] ) == (up_symbol ) ) ) {
        next = ".." ; 
        len = 2 ; 
      }
      else if (((argv [i + idelta ] ) == (same_symbol ) ) ) {
        next = "." ; 
        len = 1 ; 
      }
      else {
        Scheme_Object * bs ; 
        BLOCK_SETUP((PUSH(bs, 0+XfOrM403_COUNT)));
#       define XfOrM481_COUNT (1+XfOrM403_COUNT)
#       define SETUP_XfOrM481(x) SETUP(XfOrM481_COUNT)
        bs = NULLED_OUT ; 
        if (((Scheme_Type ) (((((long ) (argv [i + idelta ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i + idelta ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) ) {
#         define XfOrM485_COUNT (0+XfOrM481_COUNT)
#         define SETUP_XfOrM485(x) SETUP_XfOrM481(x)
          if (kind != scheme_unix_path_type ) {
#           define XfOrM486_COUNT (0+XfOrM485_COUNT)
#           define SETUP_XfOrM486(x) SETUP_XfOrM485(x)
            FUNCCALL(SETUP_XfOrM486(_), scheme_arg_mismatch (who , (idelta ? "specified convention incompatible with string path element: " : "preceding path's convention incompatible with string path element: " ) , argv [i + idelta ] ) ); 
          }
        }
        bs = (((((((long ) (argv [i + idelta ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i + idelta ] ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (argv [i + idelta ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i + idelta ] ) ) -> type ) <= scheme_windows_path_type ) ) ? argv [i + idelta ] : FUNCCALL(SETUP_XfOrM481(_), scheme_char_string_to_path (argv [i + idelta ] ) )) ; 
        if (kind != ((((long ) (bs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (bs ) ) -> type ) ) {
#         define XfOrM484_COUNT (0+XfOrM481_COUNT)
#         define SETUP_XfOrM484(x) SETUP_XfOrM481(x)
          FUNCCALL(SETUP_XfOrM484(_), scheme_arg_mismatch (who , (idelta ? "specified convention incompatible with given path element: " : "preceding path's convention incompatible from given path element: " ) , argv [i + idelta ] ) ); 
        }
        next = (((Scheme_Simple_Object * ) (bs ) ) -> u . byte_str_val . string_val ) ; 
        len = (((Scheme_Simple_Object * ) (bs ) ) -> u . byte_str_val . tag_val ) ; 
        if (! len ) {
          char * astr ; 
          long alen ; 
          BLOCK_SETUP((PUSH(astr, 0+XfOrM481_COUNT)));
#         define XfOrM483_COUNT (1+XfOrM481_COUNT)
#         define SETUP_XfOrM483(x) SETUP(XfOrM483_COUNT)
          astr = NULLED_OUT ; 
          astr = FUNCCALL(SETUP_XfOrM483(_), scheme_make_args_string ("other " , i + idelta , argc , argv , & alen ) ); 
          (__funcarg57 = FUNCCALL(SETUP_XfOrM483(_), scheme_number_suffix (i + 1 ) ), FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: %d%s path element is an empty string%t" , who , i + 1 , __funcarg57 , astr , alen ) )) ; 
          RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
        }
        if (FUNCCALL(SETUP_XfOrM481(_), has_null (next , len ) )) {
#         define XfOrM482_COUNT (0+XfOrM481_COUNT)
#         define SETUP_XfOrM482(x) SETUP_XfOrM481(x)
          FUNCCALL(SETUP_XfOrM482(_), raise_null_error (who , argv [i + idelta ] , " element" ) ); 
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        }
      }
      if (kind == scheme_windows_path_type ) {
        int p = pos ; 
#       define XfOrM480_COUNT (0+XfOrM403_COUNT)
#       define SETUP_XfOrM480(x) SETUP_XfOrM403(x)
        FUNCCALL(SETUP_XfOrM480(_), strip_trailing_spaces (str , & p , first_len , 1 ) ); 
        pos = p ; 
      }
      if (pos + len + 4 >= alloc ) {
        char * naya ; 
        int newalloc ; 
        BLOCK_SETUP((PUSH(naya, 0+XfOrM403_COUNT)));
#       define XfOrM479_COUNT (1+XfOrM403_COUNT)
#       define SETUP_XfOrM479(x) SETUP(XfOrM479_COUNT)
        naya = NULLED_OUT ; 
        newalloc = 2 * alloc + len + 1 ; 
        naya = (char * ) FUNCCALL(SETUP_XfOrM479(_), GC_malloc_atomic (newalloc ) ); 
        (memcpy (naya , str , pos ) ) ; 
        alloc = newalloc ; 
        str = naya ; 
      }
      if (kind == scheme_unix_path_type ) {
#       define XfOrM474_COUNT (0+XfOrM403_COUNT)
#       define SETUP_XfOrM474(x) SETUP_XfOrM403(x)
        if (next [0 ] == '/' ) {
#         define XfOrM477_COUNT (0+XfOrM474_COUNT)
#         define SETUP_XfOrM477(x) SETUP_XfOrM474(x)
          rel = 0 ; 
          if (i ) {
#           define XfOrM478_COUNT (0+XfOrM477_COUNT)
#           define SETUP_XfOrM478(x) SETUP_XfOrM477(x)
            FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: absolute path \"%q\" cannot be" " added to a path" , who , next ) ); 
            RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
          }
        }
        else {
          rel = 1 ; 
          if (i && (next [0 ] == '.' ) && (next [1 ] == '/' ) && (next [2 ] == '~' ) ) {
            next_off += 2 ; 
            len -= 2 ; 
          }
        }
      }
      else {
        int is_drive ; 
#       define XfOrM437_COUNT (0+XfOrM403_COUNT)
#       define SETUP_XfOrM437(x) SETUP_XfOrM403(x)
        needs_extra_slash = 0 ; 
        if ((((next [0 ] ) == '/' ) || ((next [0 ] ) == '\\' ) ) ) {
          int drive_end , plus_sep = 0 ; 
#         define XfOrM448_COUNT (0+XfOrM437_COUNT)
#         define SETUP_XfOrM448(x) SETUP_XfOrM437(x)
          rel = 0 ; 
          if (FUNCCALL(SETUP_XfOrM448(_), check_dos_slashslash_qm (next , len , & drive_end , ((void * ) 0 ) , & plus_sep ) )) {
#           define XfOrM449_COUNT (0+XfOrM448_COUNT)
#           define SETUP_XfOrM449(x) SETUP_XfOrM448(x)
            if (drive_end < 0 ) {
#             define XfOrM452_COUNT (0+XfOrM449_COUNT)
#             define SETUP_XfOrM452(x) SETUP_XfOrM449(x)
              rel = 1 ; 
              is_drive = 0 ; 
              if (i ) {
                int dots_end , lit_start ; 
                int new_rel_base , need_simplify ; 
                int base_is_here = 0 ; 
#               define XfOrM454_COUNT (0+XfOrM452_COUNT)
#               define SETUP_XfOrM454(x) SETUP_XfOrM452(x)
                if (! FUNCCALL(SETUP_XfOrM454(_), check_dos_slashslash_qm (str , pos , & drive_end , ((void * ) 0 ) , ((void * ) 0 ) ) )) {
                  Scheme_Object * simp ; 
                  BLOCK_SETUP((PUSH(simp, 0+XfOrM454_COUNT)));
#                 define XfOrM471_COUNT (1+XfOrM454_COUNT)
#                 define SETUP_XfOrM471(x) SETUP(XfOrM471_COUNT)
                  simp = NULLED_OUT ; 
                  str [pos ] = 0 ; 
                  simp = (__funcarg56 = FUNCCALL(SETUP_XfOrM471(_), scheme_make_sized_offset_kind_path (str , 0 , pos , 0 , scheme_windows_path_type ) ), FUNCCALL_AGAIN(do_simplify_path (__funcarg56 , scheme_null , first_len , 0 , 0 , scheme_windows_path_type ) )) ; 
                  if ((((simp ) ) == (scheme_false ) ) ) {
                    pos = 0 ; 
                    first_len = len ; 
                    if (next [len ] != '\\' )
                      first_len ++ ; 
                    no_sep = 1 ; 
                    new_rel_base = 0 ; 
                  }
                  else {
                    char * cleaned ; 
                    int clen ; 
                    int al = alloc ; 
#                   define XfOrM472_COUNT (0+XfOrM471_COUNT)
#                   define SETUP_XfOrM472(x) SETUP_XfOrM471(x)
                    cleaned = NULLED_OUT ; 
                    clen = (((Scheme_Simple_Object * ) (simp ) ) -> u . byte_str_val . tag_val ) ; 
                    cleaned = (((Scheme_Simple_Object * ) (simp ) ) -> u . byte_str_val . string_val ) ; 
                    str = FUNCCALL(SETUP_XfOrM472(_), convert_to_backslashbackslash_qm (cleaned , & clen , str , & al , len + 4 ) ); 
                    pos = clen ; 
                    alloc = al ; 
                    if ((pos > 5 ) && (str [4 ] == 'R' ) && (str [5 ] == 'E' ) )
                      new_rel_base = 1 ; 
                    else new_rel_base = 0 ; 
                    if (str [pos - 1 ] != '\\' )
                      str [pos ++ ] = '\\' ; 
                    no_sep = 1 ; 
                    first_len = pos ; 
                  }
                  need_simplify = 0 ; 
                }
                else {
                  new_rel_base = (drive_end < 0 ) ; 
                  need_simplify = 1 ; 
                }
                if (! pos ) {
                }
                else {
#                 define XfOrM455_COUNT (0+XfOrM454_COUNT)
#                 define SETUP_XfOrM455(x) SETUP_XfOrM454(x)
                  dots_end = FUNCCALL(SETUP_XfOrM455(_), get_slashslash_qm_dot_ups_end (next , len , & lit_start ) ); 
                  if (dots_end > 0 ) {
#                   define XfOrM468_COUNT (0+XfOrM455_COUNT)
#                   define SETUP_XfOrM468(x) SETUP_XfOrM455(x)
                    if (! no_sep )
                      str [pos ++ ] = '\\' ; 
                    (memcpy (str + pos , next + 8 , dots_end - 8 ) ) ; 
                    pos += dots_end - 8 ; 
                    str [pos ] = 0 ; 
                    need_simplify = 1 ; 
                  }
                  if (need_simplify ) {
                    Scheme_Object * simp ; 
                    BLOCK_SETUP((PUSH(simp, 0+XfOrM455_COUNT)));
#                   define XfOrM465_COUNT (1+XfOrM455_COUNT)
#                   define SETUP_XfOrM465(x) SETUP(XfOrM465_COUNT)
                    simp = NULLED_OUT ; 
                    simp = (__funcarg55 = FUNCCALL(SETUP_XfOrM465(_), scheme_make_sized_offset_kind_path (str , 0 , pos , 0 , scheme_windows_path_type ) ), FUNCCALL_AGAIN(do_simplify_path (__funcarg55 , scheme_null , first_len , 0 , 1 , scheme_windows_path_type ) )) ; 
                    if ((((simp ) ) == (scheme_false ) ) ) {
#                     define XfOrM467_COUNT (0+XfOrM465_COUNT)
#                     define SETUP_XfOrM467(x) SETUP_XfOrM465(x)
                      (memcpy (str , "\\\\?\\REL\\\\" , 9 ) ) ; 
                      pos = 9 ; 
                      no_sep = 1 ; 
                      base_is_here = 1 ; 
                    }
                    else {
#                     define XfOrM466_COUNT (0+XfOrM465_COUNT)
#                     define SETUP_XfOrM466(x) SETUP_XfOrM465(x)
                      pos = (((Scheme_Simple_Object * ) (simp ) ) -> u . byte_str_val . tag_val ) ; 
                      (memcpy (str , (((Scheme_Simple_Object * ) (simp ) ) -> u . byte_str_val . string_val ) , pos ) ) ; 
                      no_sep = (str [pos - 1 ] == '\\' ) ; 
                    }
                  }
                  if (new_rel_base && (lit_start < len ) ) {
                    int ls ; 
#                   define XfOrM460_COUNT (0+XfOrM455_COUNT)
#                   define SETUP_XfOrM460(x) SETUP_XfOrM455(x)
                    dots_end = FUNCCALL(SETUP_XfOrM460(_), get_slashslash_qm_dot_ups_end (str , pos , & ls ) ); 
                    if (dots_end > 0 ) {
                      if (ls == pos ) {
                        if (dots_end + 2 > pos ) {
                          if (dots_end + 1 > pos )
                            str [pos ++ ] = '\\' ; 
                          str [pos ++ ] = '\\' ; 
                          no_sep = 1 ; 
                        }
                      }
                    }
                    else if (ls == 8 ) {
#                     define XfOrM461_COUNT (0+XfOrM460_COUNT)
#                     define SETUP_XfOrM461(x) SETUP_XfOrM460(x)
                      (memmove (str + 9 , str + 8 , pos - 8 ) ) ; 
                      str [8 ] = '\\' ; 
                      pos ++ ; 
                      no_sep = 1 ; 
                    }
                  }
                  next_off = lit_start ; 
                  len -= next_off ; 
                  if (! len ) {
                    if (base_is_here ) {
                      pos = 0 ; 
                      no_sep = 1 ; 
                      next = "." ; 
                      len = 1 ; 
                      next_off = 0 ; 
                    }
                    else no_sep = 1 ; 
                  }
                  else {
                    if (! new_rel_base && (pos == 4 ) ) {
                      str [pos ++ ] = '\\' ; 
                      str [pos ++ ] = '\\' ; 
                    }
                  }
                  first_len = pos + len ; 
                  if (next [next_off + len ] != '\\' )
                    first_len ++ ; 
                }
              }
              else {
                first_len = len ; 
              }
            }
            else {
              is_drive = (drive_end == len ) ; 
              needs_extra_slash = plus_sep ; 
              if (! i ) {
                first_len = len ; 
                if (next [first_len - 1 ] != '\\' )
                  first_len ++ ; 
              }
            }
          }
          else is_drive = FUNCCALL(SETUP_XfOrM448(_), check_dos_slashslash_drive (next , 0 , len , ((void * ) 0 ) , 1 , 0 ) ); 
        }
        else if ((len >= 2 ) && (((unsigned char ) next [0 ] < 128 ) && ((* FUNCCALL(SETUP_XfOrM437(_), __ctype_b_loc () )) [(int ) (((unsigned char ) next [0 ] ) ) ] & (unsigned short int ) _ISalpha ) ) && (next [1 ] == ':' ) ) {
          int j ; 
          rel = 0 ; 
          for (j = 2 ; j < len ; j ++ ) {
            if (! (((next [j ] ) == '/' ) || ((next [j ] ) == '\\' ) ) )
              break ; 
          }
          is_drive = (j >= len ) ; 
        }
        else {
          rel = 1 ; 
          is_drive = 0 ; 
        }
        if (! rel ) {
#         define XfOrM438_COUNT (0+XfOrM437_COUNT)
#         define SETUP_XfOrM438(x) SETUP_XfOrM437(x)
          if (i && (! first_was_drive || (i > 1 ) || is_drive ) ) {
#           define XfOrM442_COUNT (0+XfOrM438_COUNT)
#           define SETUP_XfOrM442(x) SETUP_XfOrM438(x)
            if (pos > 30 ) {
              str [27 ] = '.' ; 
              str [28 ] = '.' ; 
              str [29 ] = '.' ; 
              str [30 ] = 0 ; 
            }
            else str [pos ] = 0 ; 
            FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: %s \"%s\" cannot be" " added to the path \"%q\"" , who , is_drive ? "drive" : "absolute path" , next , str ) ); 
            RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
          }
          if (i == 1 ) {
            while (len && (((next [next_off ] ) == '/' ) || ((next [next_off ] ) == '\\' ) ) ) {
              next_off ++ ; 
              len -- ; 
            }
          }
        }
        if (! i )
          first_was_drive = is_drive ; 
      }
      if (! i ) {
        no_sep = 1 ; 
      }
      if (kind == scheme_windows_path_type ) {
#       define XfOrM418_COUNT (0+XfOrM403_COUNT)
#       define SETUP_XfOrM418(x) SETUP_XfOrM403(x)
        if (i ) {
#         define XfOrM433_COUNT (0+XfOrM418_COUNT)
#         define SETUP_XfOrM433(x) SETUP_XfOrM418(x)
          pre_unc = FUNCCALL(SETUP_XfOrM433(_), check_dos_slashslash_drive (str , 0 , pos , ((void * ) 0 ) , 0 , 0 ) ); 
          if (! pre_unc ) {
            int de ; 
#           define XfOrM434_COUNT (0+XfOrM433_COUNT)
#           define SETUP_XfOrM434(x) SETUP_XfOrM433(x)
            if (FUNCCALL(SETUP_XfOrM434(_), check_dos_slashslash_qm (str , pos , & de , ((void * ) 0 ) , ((void * ) 0 ) ) )) {
              if (de == 4 )
                pre_qm = 1 ; 
            }
          }
          else pre_qm = 0 ; 
        }
        else {
          pre_unc = 1 ; 
          pre_qm = 0 ; 
        }
        if (no_final_simplify && (len == 2 ) && (next [next_off ] == '.' ) && (next [next_off + 1 ] == '.' ) && (first_len < pos + 2 ) ) {
          int de ; 
#         define XfOrM419_COUNT (0+XfOrM418_COUNT)
#         define SETUP_XfOrM419(x) SETUP_XfOrM418(x)
          if (FUNCCALL(SETUP_XfOrM419(_), check_dos_slashslash_qm (str , pos , & de , ((void * ) 0 ) , ((void * ) 0 ) ) )) {
#           define XfOrM420_COUNT (0+XfOrM419_COUNT)
#           define SETUP_XfOrM420(x) SETUP_XfOrM419(x)
            if (de < 0 ) {
              int ls , dots_end ; 
#             define XfOrM421_COUNT (0+XfOrM420_COUNT)
#             define SETUP_XfOrM421(x) SETUP_XfOrM420(x)
              dots_end = FUNCCALL(SETUP_XfOrM421(_), get_slashslash_qm_dot_ups_end (str , pos , & ls ) ); 
              if (ls == pos ) {
                if (dots_end < ls )
                  pos = dots_end + 1 ; 
              }
              else {
                int q ; 
                for (q = pos ; q -- > ls ; ) {
                  if (str [q ] == '\\' ) {
                    break ; 
                  }
                }
                pos = q ; 
                first_len = pos ; 
                len = 0 ; 
                while (q && (str [q - 1 ] == '\\' ) ) {
                  q -- ; 
                }
                if (q == 7 ) {
                  if (i + 1 == argc ) {
                    RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
                  }
                  str [0 ] = '.' ; 
                  pos = 1 ; 
                  no_sep = 1 ; 
                  first_len = 0 ; 
                }
              }
            }
          }
        }
      }
      if (! no_sep )
        str [pos ++ ] = ((kind == scheme_unix_path_type ) ? '/' : '\\' ) ; 
      (memcpy (str + pos , next + next_off , len ) ) ; 
      pos += len ; 
      if (kind == scheme_windows_path_type ) {
#       define XfOrM406_COUNT (0+XfOrM403_COUNT)
#       define SETUP_XfOrM406(x) SETUP_XfOrM403(x)
        if (! pre_unc && FUNCCALL(SETUP_XfOrM406(_), check_dos_slashslash_drive (str , 0 , pos , ((void * ) 0 ) , 0 , 0 ) )) {
#         define XfOrM417_COUNT (0+XfOrM406_COUNT)
#         define SETUP_XfOrM417(x) SETUP_XfOrM406(x)
          (memmove (str , str + 1 , pos - 1 ) ) ; 
          -- pos ; 
        }
        if (pre_qm ) {
          int de ; 
#         define XfOrM409_COUNT (0+XfOrM406_COUNT)
#         define SETUP_XfOrM409(x) SETUP_XfOrM406(x)
          {
            int i ; 
            for (i = first_len ; i < pos ; i ++ ) {
              if (str [i ] == '/' ) {
                str [i ] = '\\' ; 
              }
            }
          }
          FUNCCALL(SETUP_XfOrM409(_), check_dos_slashslash_qm (str , pos , & de , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
          if (de != 4 ) {
            int amt = ((str [4 ] == '\\' ) ? 1 : 2 ) ; 
#           define XfOrM410_COUNT (0+XfOrM409_COUNT)
#           define SETUP_XfOrM410(x) SETUP_XfOrM409(x)
            if (pos + amt >= alloc ) {
              char * naya ; 
              int newalloc ; 
              BLOCK_SETUP((PUSH(naya, 0+XfOrM410_COUNT)));
#             define XfOrM411_COUNT (1+XfOrM410_COUNT)
#             define SETUP_XfOrM411(x) SETUP(XfOrM411_COUNT)
              naya = NULLED_OUT ; 
              newalloc = 2 * alloc ; 
              naya = (char * ) FUNCCALL(SETUP_XfOrM411(_), GC_malloc_atomic (newalloc ) ); 
              (memcpy (naya , str , pos ) ) ; 
              alloc = newalloc ; 
              str = naya ; 
            }
            (memmove (str + 4 + amt , str + 4 , pos - 4 ) ) ; 
            str [4 ] = '\\' ; 
            if (amt == 2 )
              str [5 ] = '\\' ; 
            pos += amt ; 
            first_len += amt ; 
          }
        }
        if (needs_extra_slash ) {
#         define XfOrM407_COUNT (0+XfOrM406_COUNT)
#         define SETUP_XfOrM407(x) SETUP_XfOrM406(x)
          if (needs_extra_slash >= pos )
            str [pos ++ ] = '\\' ; 
          else if (str [needs_extra_slash ] != '\\' ) {
#           define XfOrM408_COUNT (0+XfOrM407_COUNT)
#           define SETUP_XfOrM408(x) SETUP_XfOrM407(x)
            (memmove (str + needs_extra_slash + 1 , str + needs_extra_slash , pos - needs_extra_slash ) ) ; 
            str [needs_extra_slash ] = '\\' ; 
            pos ++ ; 
          }
        }
      }
      if (len ) {
        no_sep = ((kind == scheme_unix_path_type ) ? ((next [next_off + len - 1 ] ) == '/' ) : (((next [next_off + len - 1 ] ) == '/' ) || ((next [next_off + len - 1 ] ) == '\\' ) ) ) ; 
      }
      else {
        no_sep = 0 ; 
      }
    }
    else {
#     define XfOrM402_COUNT (0+XfOrM401_COUNT)
#     define SETUP_XfOrM402(x) SETUP_XfOrM401(x)
      FUNCCALL_EMPTY(scheme_wrong_type (who , "path, string, 'up, 'same" , i + idelta , argc , argv ) ); 
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    }
  }
  str [pos ] = 0 ; 
  if (kind == scheme_windows_path_type ) {
#   define XfOrM311_COUNT (0+XfOrM310_COUNT)
#   define SETUP_XfOrM311(x) SETUP_XfOrM310(x)
    if (FUNCCALL(SETUP_XfOrM311(_), check_dos_slashslash_qm (str , pos , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) ) )&& ! no_final_simplify ) {
      int p ; 
      Scheme_Object * simp ; 
      BLOCK_SETUP((PUSH(simp, 0+XfOrM311_COUNT)));
#     define XfOrM312_COUNT (1+XfOrM311_COUNT)
#     define SETUP_XfOrM312(x) SETUP(XfOrM312_COUNT)
      simp = NULLED_OUT ; 
      p = pos ; 
      str = FUNCCALL(SETUP_XfOrM312(_), do_normal_path_seps (str , & p , first_len , 1 , scheme_windows_path_type , ((void * ) 0 ) ) ); 
      str = FUNCCALL_AGAIN(remove_redundant_slashes (str , & p , first_len , ((void * ) 0 ) , scheme_windows_path_type ) ); 
      simp = (__funcarg51 = FUNCCALL(SETUP_XfOrM312(_), scheme_make_sized_offset_kind_path (str , 0 , p , 0 , scheme_windows_path_type ) ), FUNCCALL_AGAIN(do_simplify_path (__funcarg51 , scheme_null , first_len , 0 , 1 , scheme_windows_path_type ) )) ; 
      if ((((simp ) ) == (scheme_false ) ) )
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_offset_kind_path (".\\" , 0 , 1 , 0 , scheme_windows_path_type ) )) RET_VALUE_EMPTY_END ; 
      else RET_VALUE_START (simp ) RET_VALUE_END ; 
    }
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_offset_kind_path (str , 0 , pos , alloc == 256 , kind ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_build_path (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  int kind = scheme_unix_path_type , i ; 
  for (i = 0 ; i < argc ; i ++ ) {
    if (((((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) <= scheme_windows_path_type ) ) ) {
      kind = ((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ; 
      break ; 
    }
    else if (((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) ) {
      kind = scheme_unix_path_type ; 
      break ; 
    }
  }
  return do_build_path (argc , argv , 0 , 0 , kind ) ; 
}
static Scheme_Object * build_path_kind (int argc , Scheme_Object * * argv ) {
  int kind ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM496_COUNT (1)
# define SETUP_XfOrM496(x) SETUP(XfOrM496_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  kind = FUNCCALL(SETUP_XfOrM496(_), extract_path_kind ("build-path/convention-type" , 0 , argc , argv ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(do_build_path (argc - 1 , argv , 1 , 0 , kind ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * path_to_directory_path (int argc , Scheme_Object * * argv ) {
  Scheme_Object * inpath ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(inpath, 0)));
# define XfOrM497_COUNT (1)
# define SETUP_XfOrM497(x) SETUP(XfOrM497_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  inpath = NULLED_OUT ; 
  inpath = argv [0 ] ; 
  if (! (((Scheme_Type ) (((((long ) (inpath ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (inpath ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((((((long ) (inpath ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (inpath ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (inpath ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (inpath ) ) -> type ) <= scheme_windows_path_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("path->directory-path" , "path (for any platform) or string" , 0 , argc , argv ) ); 
  inpath = (((((((long ) (inpath ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (inpath ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (inpath ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (inpath ) ) -> type ) <= scheme_windows_path_type ) ) ? inpath : FUNCCALL(SETUP_XfOrM497(_), scheme_char_string_to_path (inpath ) )) ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_path_to_directory_path (inpath ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_split_path (const char * path , int len , Scheme_Object * * base_out , int * id_out , int * cleaned_slashes , int kind ) {
  char * s ; 
  int p , last_was_sep = 0 , is_dir , no_up = 0 , not_same ; 
  Scheme_Object * file ; 
  int allow_double_before = 0 , drive_end , no_slash_sep = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(base_out, 0), PUSH(file, 1), PUSH(id_out, 2), PUSH(s, 3), PUSH(cleaned_slashes, 4)));
# define XfOrM498_COUNT (5)
# define SETUP_XfOrM498(x) SETUP(XfOrM498_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  s = NULLED_OUT ; 
  file = NULLED_OUT ; 
  s = (char * ) path ; 
  if (kind == scheme_windows_path_type ) {
#   define XfOrM539_COUNT (0+XfOrM498_COUNT)
#   define SETUP_XfOrM539(x) SETUP_XfOrM498(x)
    if ((len > 2 ) && (((s [0 ] ) == '/' ) || ((s [0 ] ) == '\\' ) ) && (((s [1 ] ) == '/' ) || ((s [1 ] ) == '\\' ) ) ) {
#     define XfOrM541_COUNT (0+XfOrM539_COUNT)
#     define SETUP_XfOrM541(x) SETUP_XfOrM539(x)
      if (FUNCCALL(SETUP_XfOrM541(_), check_dos_slashslash_qm (s , len , & drive_end , ((void * ) 0 ) , ((void * ) 0 ) ) )) {
#       define XfOrM543_COUNT (0+XfOrM541_COUNT)
#       define SETUP_XfOrM543(x) SETUP_XfOrM541(x)
        allow_double_before = drive_end ; 
        no_slash_sep = 1 ; 
        if (drive_end < 0 ) {
          int p , lit_start , dots_end ; 
#         define XfOrM546_COUNT (0+XfOrM543_COUNT)
#         define SETUP_XfOrM546(x) SETUP_XfOrM543(x)
          is_dir = 0 ; 
          if (s [len - 1 ] == '\\' ) {
            -- len ; 
            is_dir = 1 ; 
          }
          dots_end = FUNCCALL(SETUP_XfOrM546(_), get_slashslash_qm_dot_ups_end (s , len , & lit_start ) ); 
          if (lit_start < len ) {
#           define XfOrM553_COUNT (0+XfOrM546_COUNT)
#           define SETUP_XfOrM553(x) SETUP_XfOrM546(x)
            for (p = len ; -- p >= ((dots_end > 0 ) ? lit_start - 1 : lit_start ) ; ) {
#             define XfOrM561_COUNT (0+XfOrM553_COUNT)
#             define SETUP_XfOrM561(x) SETUP_XfOrM553(x)
              if (s [p ] == '\\' ) {
#               define XfOrM562_COUNT (0+XfOrM561_COUNT)
#               define SETUP_XfOrM562(x) SETUP_XfOrM561(x)
                {
                  int len2 , nsep ; 
                  char * s2 ; 
                  Scheme_Object * dir ; 
                  BLOCK_SETUP((PUSH(s2, 0+XfOrM562_COUNT), PUSH(dir, 1+XfOrM562_COUNT)));
#                 define XfOrM563_COUNT (2+XfOrM562_COUNT)
#                 define SETUP_XfOrM563(x) SETUP(XfOrM563_COUNT)
                  s2 = NULLED_OUT ; 
                  dir = NULLED_OUT ; 
                  len2 = len - p - 1 + 9 ; 
                  s2 = FUNCCALL(SETUP_XfOrM563(_), GC_malloc_atomic (len2 + 1 ) ); 
                  (memcpy (s2 , "\\\\?\\REL\\\\" , 9 ) ) ; 
                  (memcpy (s2 + 9 , s + p + 1 , len - p - 1 ) ) ; 
                  s2 [len2 ] = 0 ; 
                  if ((dots_end == p ) || (dots_end == p - 1 ) ) {
                    nsep = ((dots_end == p ) ? 0 : - 1 ) ; 
                  }
                  else {
                    if (s [6 ] == 'L' ) {
                      nsep = 1 ; 
                    }
                    else {
                      if (s [p - 1 ] == '\\' )
                        nsep = 0 ; 
                      else nsep = 1 ; 
                    }
                  }
                  dir = FUNCCALL(SETUP_XfOrM563(_), scheme_make_sized_offset_kind_path (s , 0 , p + nsep , 1 , scheme_windows_path_type ) ); 
                  file = FUNCCALL(SETUP_XfOrM563(_), scheme_make_sized_offset_kind_path (s2 , 0 , len2 , 0 , scheme_windows_path_type ) ); 
                  RET_VALUE_START ((* base_out = dir , * id_out = is_dir , file ) ) RET_VALUE_END ; 
                }
              }
            }
          }
          if (dots_end > 0 ) {
#           define XfOrM551_COUNT (0+XfOrM546_COUNT)
#           define SETUP_XfOrM551(x) SETUP_XfOrM546(x)
            if (dots_end - 3 > 8 ) {
#             define XfOrM552_COUNT (0+XfOrM551_COUNT)
#             define SETUP_XfOrM552(x) SETUP_XfOrM551(x)
              file = FUNCCALL(SETUP_XfOrM552(_), scheme_make_sized_offset_kind_path (s , 0 , dots_end - 3 , 1 , scheme_windows_path_type ) ); 
              RET_VALUE_START ((* base_out = file , * id_out = 1 , up_symbol ) ) RET_VALUE_END ; 
            }
            else RET_VALUE_START ((* base_out = relative_symbol , * id_out = 1 , up_symbol ) ) RET_VALUE_END ; 
          }
          else {
#           define XfOrM547_COUNT (0+XfOrM546_COUNT)
#           define SETUP_XfOrM547(x) SETUP_XfOrM546(x)
            if (s [6 ] == 'L' ) {
#             define XfOrM550_COUNT (0+XfOrM547_COUNT)
#             define SETUP_XfOrM550(x) SETUP_XfOrM547(x)
              RET_VALUE_START ((* base_out = relative_symbol , * id_out = is_dir , FUNCCALL(SETUP_XfOrM550(_), scheme_make_sized_offset_kind_path (s , 0 , len , 1 , scheme_windows_path_type ) )) ) RET_VALUE_END ; 
            }
            else {
              char * naya ; 
              Scheme_Object * dir ; 
              BLOCK_SETUP((PUSH(naya, 0+XfOrM547_COUNT), PUSH(dir, 1+XfOrM547_COUNT)));
#             define XfOrM548_COUNT (2+XfOrM547_COUNT)
#             define SETUP_XfOrM548(x) SETUP(XfOrM548_COUNT)
              naya = NULLED_OUT ; 
              dir = NULLED_OUT ; 
              naya = (char * ) FUNCCALL(SETUP_XfOrM548(_), GC_malloc_atomic (len + 2 ) ); 
              (memcpy (naya , s , len + 2 ) ) ; 
              naya [6 ] = 'L' ; 
              if (naya [8 ] != '\\' ) {
#               define XfOrM549_COUNT (0+XfOrM548_COUNT)
#               define SETUP_XfOrM549(x) SETUP_XfOrM548(x)
                (memmove (naya + 9 , naya + 8 , len + 1 - 8 ) ) ; 
                naya [8 ] = '\\' ; 
                len ++ ; 
              }
              dir = FUNCCALL(SETUP_XfOrM548(_), scheme_make_sized_offset_kind_path ("\\" , 0 , 1 , 0 , scheme_windows_path_type ) ); 
              RET_VALUE_START ((* base_out = dir , * id_out = is_dir , FUNCCALL(SETUP_XfOrM548(_), scheme_make_sized_offset_kind_path (naya , 0 , len , 0 , scheme_windows_path_type ) )) ) RET_VALUE_END ; 
            }
          }
        }
        else {
          no_up = 1 ; 
          if ((drive_end < len ) && s [drive_end ] == '\\' ) {
            drive_end ++ ; 
          }
        }
      }
      else if (FUNCCALL(SETUP_XfOrM541(_), check_dos_slashslash_drive (s , 0 , len , & drive_end , 0 , 0 ) )) {
        allow_double_before = 1 ; 
        if ((drive_end < len ) && (((s [drive_end ] ) == '/' ) || ((s [drive_end ] ) == '\\' ) ) )
          drive_end ++ ; 
      }
      else drive_end = 0 ; 
    }
    else if ((len > 1 ) && (((unsigned char ) s [0 ] < 128 ) && ((* FUNCCALL(SETUP_XfOrM539(_), __ctype_b_loc () )) [(int ) (((unsigned char ) s [0 ] ) ) ] & (unsigned short int ) _ISalpha ) ) && (s [1 ] == ':' ) ) {
      drive_end = 2 ; 
      if ((drive_end < len ) && (((s [drive_end ] ) == '/' ) || ((s [drive_end ] ) == '\\' ) ) )
        drive_end ++ ; 
    }
    else drive_end = 0 ; 
  }
  else {
    drive_end = 0 ; 
  }
  for (p = len ; p -- ; ) {
#   define XfOrM531_COUNT (0+XfOrM498_COUNT)
#   define SETUP_XfOrM531(x) SETUP_XfOrM498(x)
    if (p > allow_double_before ) {
#     define XfOrM532_COUNT (0+XfOrM531_COUNT)
#     define SETUP_XfOrM532(x) SETUP_XfOrM531(x)
      if (((kind == scheme_unix_path_type ) ? ((s [p ] ) == '/' ) : (((s [p ] ) == '/' ) || ((s [p ] ) == '\\' ) ) ) && ((kind == scheme_unix_path_type ) ? ((s [p - 1 ] ) == '/' ) : (((s [p - 1 ] ) == '/' ) || ((s [p - 1 ] ) == '\\' ) ) ) ) {
        int q ; 
        char * old = s ; 
        BLOCK_SETUP((PUSH(old, 0+XfOrM532_COUNT)));
#       define XfOrM533_COUNT (1+XfOrM532_COUNT)
#       define SETUP_XfOrM533(x) SETUP(XfOrM533_COUNT)
        if (cleaned_slashes )
          * cleaned_slashes = 1 ; 
        s = (char * ) FUNCCALL(SETUP_XfOrM533(_), GC_malloc_atomic (len ) ); 
        -- len ; 
        for (p = 0 , q = 0 ; p < allow_double_before ; p ++ ) {
          s [q ++ ] = old [p ] ; 
        }
        for (; p < len ; p ++ ) {
          if (! ((kind == scheme_unix_path_type ) ? ((old [p ] ) == '/' ) : (((old [p ] ) == '/' ) || ((old [p ] ) == '\\' ) ) ) || ! ((kind == scheme_unix_path_type ) ? ((old [p + 1 ] ) == '/' ) : (((old [p + 1 ] ) == '/' ) || ((old [p + 1 ] ) == '\\' ) ) ) )
            s [q ++ ] = old [p ] ; 
        }
        s [q ++ ] = old [len ] ; 
        len = q ; 
        break ; 
      }
    }
  }
  if ((kind == scheme_windows_path_type ) && (len <= drive_end ) )
    p = - 1 ; 
  else {
    for (p = len ; p -- ; ) {
      if ((((kind == scheme_windows_path_type ) && no_slash_sep ) ? (s [p ] == '\\' ) : ((kind == scheme_unix_path_type ) ? ((s [p ] ) == '/' ) : (((s [p ] ) == '/' ) || ((s [p ] ) == '\\' ) ) ) ) ) {
        if (p != len - 1 )
          break ; 
        else last_was_sep = 1 ; 
      }
      if (kind == scheme_windows_path_type ) {
        if (p < drive_end )
          break ; 
      }
    }
  }
  if (kind == scheme_unix_path_type ) {
    if ((p == 1 ) && s [0 ] == '.' && s [p + 1 ] == '~' ) {
      not_same = 1 ; 
      p -= 2 ; 
    }
    else not_same = 0 ; 
  }
  else not_same = 0 ; 
  if (p < 0 ) {
    Scheme_Object * dir ; 
    BLOCK_SETUP((PUSH(dir, 0+XfOrM498_COUNT)));
#   define XfOrM506_COUNT (1+XfOrM498_COUNT)
#   define SETUP_XfOrM506(x) SETUP(XfOrM506_COUNT)
    dir = NULLED_OUT ; 
    if (kind == scheme_unix_path_type ) {
#     define XfOrM511_COUNT (0+XfOrM506_COUNT)
#     define SETUP_XfOrM511(x) SETUP_XfOrM506(x)
      if (s [0 ] == '/' )
        RET_VALUE_START ((* base_out = scheme_false , * id_out = 1 , FUNCCALL(SETUP_XfOrM511(_), scheme_make_sized_offset_kind_path (s , 0 , len , 1 , kind ) )) ) RET_VALUE_END ; 
      if (s [0 ] == '~' ) {
#       define XfOrM512_COUNT (0+XfOrM511_COUNT)
#       define SETUP_XfOrM512(x) SETUP_XfOrM511(x)
        while (((s [len - 1 ] ) == '/' ) ) {
          -- len ; 
        }
        RET_VALUE_START ((* base_out = scheme_false , * id_out = 1 , FUNCCALL(SETUP_XfOrM512(_), scheme_make_sized_offset_kind_path (s , 0 , len , 1 , kind ) )) ) RET_VALUE_END ; 
      }
    }
    else {
#     define XfOrM510_COUNT (0+XfOrM506_COUNT)
#     define SETUP_XfOrM510(x) SETUP_XfOrM506(x)
      if ((((s [0 ] ) == '/' ) || ((s [0 ] ) == '\\' ) ) || drive_end )
        RET_VALUE_START ((* base_out = scheme_false , * id_out = 1 , FUNCCALL(SETUP_XfOrM510(_), scheme_make_sized_offset_kind_path (s , 0 , len , 1 , kind ) )) ) RET_VALUE_END ; 
    }
    dir = relative_symbol ; 
    if (! no_up && (s [0 ] == '.' ) && (s [1 ] == '.' ) && (2 >= len || ((kind == scheme_unix_path_type ) ? ((s [2 ] ) == '/' ) : (((s [2 ] ) == '/' ) || ((s [2 ] ) == '\\' ) ) ) ) ) {
      file = up_symbol ; 
      is_dir = 1 ; 
    }
    else if (! no_up && ! not_same && (s [0 ] == '.' ) && (1 >= len || ((kind == scheme_unix_path_type ) ? ((s [1 ] ) == '/' ) : (((s [1 ] ) == '/' ) || ((s [1 ] ) == '\\' ) ) ) ) ) {
      file = same_symbol ; 
      is_dir = 1 ; 
    }
    else {
      int delta ; 
#     define XfOrM507_COUNT (0+XfOrM506_COUNT)
#     define SETUP_XfOrM507(x) SETUP_XfOrM506(x)
      is_dir = last_was_sep ; 
      delta = 0 ; 
      file = FUNCCALL(SETUP_XfOrM507(_), make_protected_sized_offset_path (no_up || is_dir , s , 0 , len - last_was_sep + delta , 1 , 0 , kind ) ); 
    }
    RET_VALUE_START ((* base_out = dir , * id_out = is_dir , file ) ) RET_VALUE_END ; 
  }
  if (! no_up && (s [p + 1 ] == '.' ) && (s [p + 2 ] == '.' ) && (p + 3 >= len || ((kind == scheme_unix_path_type ) ? ((s [p + 3 ] ) == '/' ) : (((s [p + 3 ] ) == '/' ) || ((s [p + 3 ] ) == '\\' ) ) ) ) ) {
    file = up_symbol ; 
    is_dir = 1 ; 
  }
  else if (! no_up && (s [p + 1 ] == '.' ) && (p + 2 >= len || ((kind == scheme_unix_path_type ) ? ((s [p + 2 ] ) == '/' ) : (((s [p + 2 ] ) == '/' ) || ((s [p + 2 ] ) == '\\' ) ) ) ) ) {
    file = same_symbol ; 
    is_dir = 1 ; 
  }
  else {
    int protected ; 
#   define XfOrM501_COUNT (0+XfOrM498_COUNT)
#   define SETUP_XfOrM501(x) SETUP_XfOrM498(x)
    if (kind == scheme_windows_path_type ) {
      protected = no_up || last_was_sep ; 
    }
    else {
      protected = 1 ; 
    }
    file = FUNCCALL(SETUP_XfOrM501(_), make_protected_sized_offset_path (protected , s , p + 1 , len - p - last_was_sep - 1 , 1 , 0 , kind ) ); 
    is_dir = last_was_sep ; 
  }
  if (p > 0 ) {
    Scheme_Object * ss ; 
    BLOCK_SETUP((PUSH(ss, 0+XfOrM498_COUNT)));
#   define XfOrM500_COUNT (1+XfOrM498_COUNT)
#   define SETUP_XfOrM500(x) SETUP(XfOrM500_COUNT)
    ss = NULLED_OUT ; 
    ss = FUNCCALL(SETUP_XfOrM500(_), make_exposed_sized_offset_path (no_up , s , 0 , p + 1 , 1 , kind ) ); 
    RET_VALUE_START ((* base_out = ss , * id_out = is_dir , file ) ) RET_VALUE_END ; 
  }
  {
    Scheme_Object * ss ; 
    BLOCK_SETUP((PUSH(ss, 0+XfOrM498_COUNT)));
#   define XfOrM499_COUNT (1+XfOrM498_COUNT)
#   define SETUP_XfOrM499(x) SETUP(XfOrM499_COUNT)
    ss = NULLED_OUT ; 
    ss = FUNCCALL(SETUP_XfOrM499(_), scheme_make_sized_offset_kind_path (s , 0 , 1 , 1 , kind ) ); 
    RET_VALUE_START ((* base_out = ss , * id_out = is_dir , file ) ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_split_path (const char * path , int len , Scheme_Object * * base_out , int * id_out , int kind ) {
  /* No conversion */
  return do_split_path (path , len , base_out , id_out , ((void * ) 0 ) , kind ) ; 
}
static Scheme_Object * split_path (int argc , Scheme_Object * * argv ) {
  char * s ; 
  int is_dir , len ; 
  Scheme_Object * three [3 ] , * inpath ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(inpath, 0), PUSHARRAY(three, 3, 1), PUSH(s, 4)));
# define XfOrM570_COUNT (5)
# define SETUP_XfOrM570(x) SETUP(XfOrM570_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  three[0] = NULLED_OUT ; 
  three[1] = NULLED_OUT ; 
  three[2] = NULLED_OUT ; 
  inpath = NULLED_OUT ; 
  inpath = argv [0 ] ; 
  if (! (((Scheme_Type ) (((((long ) (inpath ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (inpath ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((((((long ) (inpath ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (inpath ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (inpath ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (inpath ) ) -> type ) <= scheme_windows_path_type ) ) ) )
    FUNCCALL(SETUP_XfOrM570(_), scheme_wrong_type ("split-path" , "path (for any platform) or string" , 0 , argc , argv ) ); 
  inpath = (((((((long ) (inpath ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (inpath ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (inpath ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (inpath ) ) -> type ) <= scheme_windows_path_type ) ) ? inpath : FUNCCALL(SETUP_XfOrM570(_), scheme_char_string_to_path (inpath ) )) ; 
  s = (((Scheme_Simple_Object * ) (inpath ) ) -> u . byte_str_val . string_val ) ; 
  len = (((Scheme_Simple_Object * ) (inpath ) ) -> u . byte_str_val . tag_val ) ; 
  if (! len ) {
#   define XfOrM571_COUNT (0+XfOrM570_COUNT)
#   define SETUP_XfOrM571(x) SETUP_XfOrM570(x)
    FUNCCALL(SETUP_XfOrM571(_), scheme_raise_exn (MZEXN_FAIL_CONTRACT , "split-path: path is an empty string" ) ); 
  }
  if (FUNCCALL(SETUP_XfOrM570(_), has_null (s , len ) ))
    FUNCCALL(SETUP_XfOrM570(_), raise_null_error ("split-path" , inpath , "" ) ); 
  three [1 ] = FUNCCALL(SETUP_XfOrM570(_), scheme_split_path (s , len , & three [0 ] , & is_dir , ((((long ) (inpath ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (inpath ) ) -> type ) ) ); 
  three [2 ] = is_dir ? scheme_true : scheme_false ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM570(_), scheme_values (3 , three ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_is_relative_path (const char * s , long len , int kind ) {
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(s, 0)));
# define XfOrM572_COUNT (1)
# define SETUP_XfOrM572(x) SETUP(XfOrM572_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! len )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  if (kind == scheme_unix_path_type ) {
    RET_VALUE_START (! ((s [0 ] == '/' ) || (s [0 ] == '~' ) ) ) RET_VALUE_END ; 
  }
  else {
    int dlen ; 
#   define XfOrM573_COUNT (0+XfOrM572_COUNT)
#   define SETUP_XfOrM573(x) SETUP_XfOrM572(x)
    if (FUNCCALL(SETUP_XfOrM573(_), check_dos_slashslash_qm (s , len , & dlen , ((void * ) 0 ) , ((void * ) 0 ) ) )&& (dlen < 0 ) ) {
      if (dlen == - 1 )
        RET_VALUE_START (1 ) RET_VALUE_END ; 
      else RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    if ((((s [0 ] ) == '/' ) || ((s [0 ] ) == '\\' ) ) || ((len >= 2 ) && (((unsigned char ) s [0 ] < 128 ) && ((* FUNCCALL(SETUP_XfOrM573(_), __ctype_b_loc () )) [(int ) (((unsigned char ) s [0 ] ) ) ] & (unsigned short int ) _ISalpha ) ) && (s [1 ] == ':' ) ) )
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    else RET_VALUE_START (1 ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_is_complete_path (const char * s , long len , int kind ) {
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(s, 0)));
# define XfOrM576_COUNT (1)
# define SETUP_XfOrM576(x) SETUP(XfOrM576_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! len )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  if (! kind )
    kind = scheme_unix_path_type ; 
  if (! FUNCCALL(SETUP_XfOrM576(_), scheme_is_relative_path (s , len , kind ) )) {
#   define XfOrM577_COUNT (0+XfOrM576_COUNT)
#   define SETUP_XfOrM577(x) SETUP_XfOrM576(x)
    if (kind == scheme_windows_path_type ) {
#     define XfOrM578_COUNT (0+XfOrM577_COUNT)
#     define SETUP_XfOrM578(x) SETUP_XfOrM577(x)
      if ((((s [0 ] ) == '/' ) || ((s [0 ] ) == '\\' ) ) && (((s [1 ] ) == '/' ) || ((s [1 ] ) == '\\' ) ) ) {
        int dlen ; 
#       define XfOrM580_COUNT (0+XfOrM578_COUNT)
#       define SETUP_XfOrM580(x) SETUP_XfOrM578(x)
        if (FUNCCALL(SETUP_XfOrM580(_), check_dos_slashslash_qm (s , len , & dlen , ((void * ) 0 ) , ((void * ) 0 ) ) )) {
          RET_VALUE_START ((dlen >= 0 ) ) RET_VALUE_END ; 
        }
        else if (FUNCCALL(SETUP_XfOrM580(_), check_dos_slashslash_drive (s , 0 , len , ((void * ) 0 ) , 0 , 0 ) ))
          RET_VALUE_START (1 ) RET_VALUE_END ; 
        else RET_VALUE_START (0 ) RET_VALUE_END ; 
      }
      else if ((len >= 2 ) && (((unsigned char ) s [0 ] < 128 ) && ((* FUNCCALL(SETUP_XfOrM578(_), __ctype_b_loc () )) [(int ) (((unsigned char ) s [0 ] ) ) ] & (unsigned short int ) _ISalpha ) ) && (s [1 ] == ':' ) ) {
        RET_VALUE_START (1 ) RET_VALUE_END ; 
      }
      else RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    else RET_VALUE_START (1 ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static char * do_path_to_complete_path (char * filename , long ilen , const char * wrt , long wlen , int kind ) {
  Scheme_Config * __funcarg58 = NULLED_OUT ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(wrt, 0), PUSH(filename, 1)));
# define XfOrM582_COUNT (2)
# define SETUP_XfOrM582(x) SETUP(XfOrM582_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! FUNCCALL(SETUP_XfOrM582(_), scheme_is_complete_path (filename , ilen , kind ) )) {
    char * naya ; 
    int skip_sep = 0 ; 
    BLOCK_SETUP((PUSH(naya, 0+XfOrM582_COUNT)));
#   define XfOrM583_COUNT (1+XfOrM582_COUNT)
#   define SETUP_XfOrM583(x) SETUP(XfOrM583_COUNT)
    naya = NULLED_OUT ; 
    if (! wrt ) {
      Scheme_Object * wd ; 
      BLOCK_SETUP((PUSH(wd, 0+XfOrM583_COUNT)));
#     define XfOrM589_COUNT (1+XfOrM583_COUNT)
#     define SETUP_XfOrM589(x) SETUP(XfOrM589_COUNT)
      wd = NULLED_OUT ; 
      wd = (__funcarg58 = FUNCCALL(SETUP_XfOrM589(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg58 , MZCONFIG_CURRENT_DIRECTORY ) )) ; 
      wrt = (((Scheme_Simple_Object * ) (wd ) ) -> u . byte_str_val . string_val ) ; 
      wlen = (((Scheme_Simple_Object * ) (wd ) ) -> u . byte_str_val . tag_val ) ; 
      FUNCCALL(SETUP_XfOrM589(_), scheme_security_check_file ("path->complete-path" , ((void * ) 0 ) , 0x10 ) ); 
    }
    if (kind == scheme_windows_path_type ) {
#     define XfOrM585_COUNT (0+XfOrM583_COUNT)
#     define SETUP_XfOrM585(x) SETUP_XfOrM583(x)
      if (! FUNCCALL(SETUP_XfOrM585(_), scheme_is_relative_path (filename , ilen , kind ) )) {
#       define XfOrM587_COUNT (0+XfOrM585_COUNT)
#       define SETUP_XfOrM587(x) SETUP_XfOrM585(x)
        wrt = FUNCCALL(SETUP_XfOrM587(_), get_drive_part (wrt , wlen ) ); 
        wlen = strlen (wrt ) ; 
        if ((((wrt [wlen - 1 ] ) == '/' ) || ((wrt [wlen - 1 ] ) == '\\' ) ) && ! FUNCCALL(SETUP_XfOrM587(_), check_dos_slashslash_qm (wrt , wlen , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) ) )) {
          wlen -- ; 
        }
        skip_sep = 1 ; 
      }
      if (FUNCCALL(SETUP_XfOrM585(_), check_dos_slashslash_qm (wrt , wlen , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) ) )|| FUNCCALL(SETUP_XfOrM585(_), check_dos_slashslash_qm (filename , ilen , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) ) )) {
        Scheme_Object * a [2 ] , * p ; 
        BLOCK_SETUP((PUSHARRAY(a, 2, 0+XfOrM585_COUNT), PUSH(p, 3+XfOrM585_COUNT)));
#       define XfOrM586_COUNT (4+XfOrM585_COUNT)
#       define SETUP_XfOrM586(x) SETUP(XfOrM586_COUNT)
        a[0] = NULLED_OUT ; 
        a[1] = NULLED_OUT ; 
        p = NULLED_OUT ; 
        p = FUNCCALL(SETUP_XfOrM586(_), scheme_make_sized_offset_kind_path ((char * ) wrt , 0 , wlen , 1 , scheme_windows_path_type ) ); 
        a [0 ] = p ; 
        p = FUNCCALL(SETUP_XfOrM586(_), scheme_make_sized_offset_kind_path (filename , 0 , ilen , 1 , scheme_windows_path_type ) ); 
        a [1 ] = p ; 
        p = FUNCCALL(SETUP_XfOrM586(_), do_build_path (2 , a , 0 , 0 , scheme_windows_path_type ) ); 
        RET_VALUE_START ((((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . string_val ) ) RET_VALUE_END ; 
      }
    }
    naya = (char * ) FUNCCALL(SETUP_XfOrM583(_), GC_malloc_atomic (ilen + wlen + 2 ) ); 
    (memcpy (naya , wrt , wlen ) ) ; 
    if (! skip_sep )
      if (! ((kind == scheme_unix_path_type ) ? ((naya [wlen - 1 ] ) == '/' ) : (((naya [wlen - 1 ] ) == '/' ) || ((naya [wlen - 1 ] ) == '\\' ) ) ) )
      naya [wlen ++ ] = ((kind == scheme_unix_path_type ) ? '/' : '\\' ) ; 
    if (kind == scheme_windows_path_type ) {
      int w = wlen ; 
#     define XfOrM584_COUNT (0+XfOrM583_COUNT)
#     define SETUP_XfOrM584(x) SETUP_XfOrM583(x)
      FUNCCALL(SETUP_XfOrM584(_), strip_trailing_spaces (naya , & w , 0 , 1 ) ); 
      wlen = w ; 
    }
    (memcpy (naya + wlen , filename , ilen ) ) ; 
    naya [wlen + ilen ] = 0 ; 
    RET_VALUE_START (naya ) RET_VALUE_END ; 
  }
  RET_VALUE_START (filename ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * path_to_complete_path (int argc , Scheme_Object * * argv ) {
  Scheme_Object * p , * wrt ; 
  char * s ; 
  int len , kind ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(wrt, 0), PUSH(argv, 1), PUSH(p, 2), PUSH(s, 3)));
# define XfOrM590_COUNT (4)
# define SETUP_XfOrM590(x) SETUP(XfOrM590_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  p = NULLED_OUT ; 
  wrt = NULLED_OUT ; 
  s = NULLED_OUT ; 
  p = argv [0 ] ; 
  if (! (((Scheme_Type ) (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) <= scheme_windows_path_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("path->complete-path" , "path (for any platform) or string" , 0 , argc , argv ) ); 
  p = (((((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) <= scheme_windows_path_type ) ) ? p : FUNCCALL(SETUP_XfOrM590(_), scheme_char_string_to_path (p ) )) ; 
  if (argc > 1 ) {
#   define XfOrM597_COUNT (0+XfOrM590_COUNT)
#   define SETUP_XfOrM597(x) SETUP_XfOrM590(x)
    wrt = argv [1 ] ; 
    if (! (((Scheme_Type ) (((((long ) (wrt ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (wrt ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((((((long ) (wrt ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (wrt ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (wrt ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (wrt ) ) -> type ) <= scheme_windows_path_type ) ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("path->complete-path" , "path (for any platform) or string" , 1 , argc , argv ) ); 
    wrt = (((((((long ) (wrt ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (wrt ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (wrt ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (wrt ) ) -> type ) <= scheme_windows_path_type ) ) ? wrt : FUNCCALL(SETUP_XfOrM597(_), scheme_char_string_to_path (wrt ) )) ; 
  }
  else wrt = ((void * ) 0 ) ; 
  kind = ((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ; 
  if (wrt ) {
#   define XfOrM595_COUNT (0+XfOrM590_COUNT)
#   define SETUP_XfOrM595(x) SETUP_XfOrM590(x)
    if (((((long ) (wrt ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (wrt ) ) -> type ) != kind ) {
#     define XfOrM596_COUNT (0+XfOrM595_COUNT)
#     define SETUP_XfOrM596(x) SETUP_XfOrM595(x)
      FUNCCALL(SETUP_XfOrM596(_), scheme_arg_mismatch ("path->complete-path" , "convention of first path incompatible with convention of second path: " , argv [1 ] ) ); 
    }
  }
  else if (kind != scheme_unix_path_type ) {
#   define XfOrM594_COUNT (0+XfOrM590_COUNT)
#   define SETUP_XfOrM594(x) SETUP_XfOrM590(x)
    FUNCCALL(SETUP_XfOrM594(_), scheme_arg_mismatch ("path->complete-path" , "no second path supplied, and given path is not for the current platform: " , argv [0 ] ) ); 
  }
  s = (((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . string_val ) ; 
  len = (((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . tag_val ) ; 
  if (FUNCCALL(SETUP_XfOrM590(_), has_null (s , len ) ))
    FUNCCALL(SETUP_XfOrM590(_), raise_null_error ("path->complete-path" , p , "" ) ); 
  if (wrt ) {
    char * ws ; 
    int wlen ; 
    BLOCK_SETUP((PUSH(ws, 0+XfOrM590_COUNT)));
#   define XfOrM592_COUNT (1+XfOrM590_COUNT)
#   define SETUP_XfOrM592(x) SETUP(XfOrM592_COUNT)
    ws = NULLED_OUT ; 
    ws = (((Scheme_Simple_Object * ) (wrt ) ) -> u . byte_str_val . string_val ) ; 
    wlen = (((Scheme_Simple_Object * ) (wrt ) ) -> u . byte_str_val . tag_val ) ; 
    if (FUNCCALL(SETUP_XfOrM592(_), has_null (ws , wlen ) ))
      FUNCCALL(SETUP_XfOrM592(_), raise_null_error ("path->complete-path" , p , "" ) ); 
    if (! FUNCCALL(SETUP_XfOrM592(_), scheme_is_complete_path (ws , wlen , kind ) ))
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "path->complete-path: second argument is not a complete path: \"%q\"" , ws ) ); 
    if (! FUNCCALL(SETUP_XfOrM592(_), scheme_is_complete_path (s , len , kind ) )) {
#     define XfOrM593_COUNT (0+XfOrM592_COUNT)
#     define SETUP_XfOrM593(x) SETUP_XfOrM592(x)
      s = FUNCCALL(SETUP_XfOrM593(_), do_path_to_complete_path (s , len , ws , wlen , kind ) ); 
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_offset_kind_path (s , 0 , strlen (s ) , 0 , kind ) )) RET_VALUE_EMPTY_END ; 
    }
  }
  else if (! FUNCCALL(SETUP_XfOrM590(_), scheme_is_complete_path (s , len , kind ) )) {
#   define XfOrM591_COUNT (0+XfOrM590_COUNT)
#   define SETUP_XfOrM591(x) SETUP_XfOrM590(x)
    s = FUNCCALL(SETUP_XfOrM591(_), do_path_to_complete_path (s , len , ((void * ) 0 ) , 0 , kind ) ); 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_offset_kind_path (s , 0 , strlen (s ) , 0 , kind ) )) RET_VALUE_EMPTY_END ; 
  }
  RET_VALUE_START (p ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_path_to_complete_path (Scheme_Object * path , Scheme_Object * relto_path ) {
  Scheme_Object * a [2 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 2, 0)));
# define XfOrM598_COUNT (3)
# define SETUP_XfOrM598(x) SETUP(XfOrM598_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  a [0 ] = path ; 
  a [1 ] = relto_path ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM598(_), path_to_complete_path (relto_path ? 2 : 1 , a ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static char * filename_for_error (Scheme_Object * p ) {
  /* No conversion */
  return do_expand_filename (p , ((void * ) 0 ) , 0 , ((void * ) 0 ) , ((void * ) 0 ) , 1 , 1 , 0 , scheme_unix_path_type ) ; 
}
static Scheme_Object * delete_file (int argc , Scheme_Object * * argv ) {
  int errid ; 
  char * __funcarg61 = NULLED_OUT ; 
  char * __funcarg59 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM600_COUNT (1)
# define SETUP_XfOrM600(x) SETUP(XfOrM600_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("delete-file" , "path or string" , 0 , argc , argv ) ); 
  while (1 ) {
#   define XfOrM602_COUNT (0+XfOrM600_COUNT)
#   define SETUP_XfOrM602(x) SETUP_XfOrM600(x)
    if (! (__funcarg61 = FUNCCALL(SETUP_XfOrM602(_), scheme_expand_string_filename (argv [0 ] , "delete-file" , ((void * ) 0 ) , 0x8 ) ), FUNCCALL_AGAIN(unlink (__funcarg61 ) )) )
      RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
    else if ((* __errno_location () ) != 4 )
      break ; 
  }
  errid = (* __errno_location () ) ; 
  (__funcarg59 = FUNCCALL_EMPTY(filename_for_error (argv [0 ] ) ), FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_FILESYSTEM , "delete-file: cannot delete file: \"%q\" (%e)" , __funcarg59 , errid ) )) ; 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * rename_file (int argc , Scheme_Object * * argv ) {
  int exists_ok = 0 ; 
  char * src , * dest ; 
  Scheme_Object * bss , * bsd ; 
  char * __funcarg63 = NULLED_OUT ; 
  char * __funcarg62 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(__funcarg62, 0), PUSH(bsd, 1), PUSH(src, 2), PUSH(argv, 3), PUSH(dest, 4), PUSH(bss, 5)));
# define XfOrM603_COUNT (6)
# define SETUP_XfOrM603(x) SETUP(XfOrM603_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  src = NULLED_OUT ; 
  dest = NULLED_OUT ; 
  bss = NULLED_OUT ; 
  bsd = NULLED_OUT ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("rename-file-or-directory" , "path or string" , 0 , argc , argv ) ); 
  if (! (((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("rename-file-or-directory" , "path or string" , 1 , argc , argv ) ); 
  if (argc > 2 )
    exists_ok = (! (((argv [2 ] ) ) == (scheme_false ) ) ) ; 
  bss = argv [0 ] ; 
  bsd = argv [1 ] ; 
  src = FUNCCALL(SETUP_XfOrM603(_), scheme_expand_string_filename (bss , "rename-file-or-directory" , ((void * ) 0 ) , 0x1 ) ); 
  dest = FUNCCALL_AGAIN(scheme_expand_string_filename (bsd , "rename-file-or-directory" , ((void * ) 0 ) , 0x2 ) ); 
  if (! exists_ok && (FUNCCALL(SETUP_XfOrM603(_), scheme_file_exists (dest ) )|| FUNCCALL(SETUP_XfOrM603(_), scheme_directory_exists (dest ) )) ) {
    exists_ok = - 1 ; 
    (* __errno_location () ) = 17 ; 
    goto failed ; 
  }
  while (1 ) {
#   define XfOrM605_COUNT (0+XfOrM603_COUNT)
#   define SETUP_XfOrM605(x) SETUP_XfOrM603(x)
    if (! FUNCCALL(SETUP_XfOrM605(_), rename (src , dest ) ))
      RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
    else if ((* __errno_location () ) != 4 )
      break ; 
  }
  failed : (__funcarg62 = FUNCCALL(SETUP_XfOrM603(_), filename_for_error (argv [0 ] ) ), __funcarg63 = FUNCCALL(SETUP_XfOrM603(_), filename_for_error (argv [1 ] ) ), FUNCCALL_EMPTY(scheme_raise_exn ((exists_ok < 0 ) ? MZEXN_FAIL_FILESYSTEM_EXISTS : MZEXN_FAIL_FILESYSTEM , "rename-file-or-directory: cannot rename file or directory: %q to: %q (" "%e" ")" , __funcarg62 , __funcarg63 , (* __errno_location () ) ) )) ; 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * copy_file (int argc , Scheme_Object * * argv ) {
  char * src , * dest , * reason = ((void * ) 0 ) ; 
  int pre_exists = 0 ; 
  Scheme_Object * bss , * bsd ; 
  char * __funcarg65 = NULLED_OUT ; 
  char * __funcarg64 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(9);
  BLOCK_SETUP_TOP((PUSH(bsd, 0), PUSH(argv, 1), PUSH(src, 2), PUSH(dest, 3), PUSH(__funcarg64, 4), PUSH(reason, 5), PUSH(bss, 6)));
# define XfOrM607_COUNT (7)
# define SETUP_XfOrM607(x) SETUP(XfOrM607_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  src = NULLED_OUT ; 
  dest = NULLED_OUT ; 
  bss = NULLED_OUT ; 
  bsd = NULLED_OUT ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("copy-file" , "path or string" , 0 , argc , argv ) ); 
  if (! (((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("copy-file" , "path or string" , 1 , argc , argv ) ); 
  bss = argv [0 ] ; 
  bsd = argv [1 ] ; 
  src = FUNCCALL(SETUP_XfOrM607(_), scheme_expand_string_filename (bss , "copy-file" , ((void * ) 0 ) , 0x1 ) ); 
  dest = FUNCCALL_AGAIN(scheme_expand_string_filename (bsd , "copy-file" , ((void * ) 0 ) , 0x2 | 0x8 ) ); 
  {
    FILE * s , * d ; 
    char b [2048 ] ; 
    long len ; 
    int ok ; 
    struct stat buf ; 
    BLOCK_SETUP((PUSH(d, 0+XfOrM607_COUNT), PUSH(s, 1+XfOrM607_COUNT)));
#   define XfOrM608_COUNT (2+XfOrM607_COUNT)
#   define SETUP_XfOrM608(x) SETUP(XfOrM608_COUNT)
    s = NULLED_OUT ; 
    d = NULLED_OUT ; 
    do {
#     define XfOrM623_COUNT (0+XfOrM608_COUNT)
#     define SETUP_XfOrM623(x) SETUP_XfOrM608(x)
      ok = FUNCCALL(SETUP_XfOrM623(_), stat (src , & buf ) ); 
    }
    while ((ok == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
    if (ok || ((((buf . st_mode ) ) & 61440 ) == (16384 ) ) ) {
      reason = "source file does not exist" ; 
      goto failed ; 
    }
    do {
#     define XfOrM620_COUNT (0+XfOrM608_COUNT)
#     define SETUP_XfOrM620(x) SETUP_XfOrM608(x)
      ok = FUNCCALL(SETUP_XfOrM620(_), stat (dest , & buf ) ); 
    }
    while ((ok == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
    if (! ok ) {
      reason = "destination already exists" ; 
      pre_exists = 1 ; 
      goto failed ; 
    }
    s = FUNCCALL(SETUP_XfOrM608(_), fopen (src , "rb" ) ); 
    if (! s ) {
      reason = "cannot open source file" ; 
      goto failed ; 
    }
    d = FUNCCALL(SETUP_XfOrM608(_), fopen (dest , "wb" ) ); 
    if (! d ) {
#     define XfOrM616_COUNT (0+XfOrM608_COUNT)
#     define SETUP_XfOrM616(x) SETUP_XfOrM608(x)
      FUNCCALL(SETUP_XfOrM616(_), fclose (s ) ); 
      reason = "cannot open destination file" ; 
      goto failed ; 
    }
    ok = 1 ; 
    while ((len = fread (b , 1 , 2048 , s ) ) ) {
      if (fwrite (b , 1 , len , d ) != len ) {
        ok = 0 ; 
        break ; 
      }
    }
    if (! FUNCCALL(SETUP_XfOrM608(_), feof (s ) ))
      ok = 0 ; 
    FUNCCALL(SETUP_XfOrM608(_), fclose (s ) ); 
    FUNCCALL_AGAIN(fclose (d ) ); 
    if (ok ) {
#     define XfOrM609_COUNT (0+XfOrM608_COUNT)
#     define SETUP_XfOrM609(x) SETUP_XfOrM608(x)
      while (1 ) {
#       define XfOrM611_COUNT (0+XfOrM609_COUNT)
#       define SETUP_XfOrM611(x) SETUP_XfOrM609(x)
        if (! FUNCCALL(SETUP_XfOrM611(_), chmod (dest , buf . st_mode ) ))
          RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
        else if ((* __errno_location () ) != 4 )
          break ; 
      }
      reason = "cannot set destination's mode" ; 
    }
    else reason = "read or write failed" ; 
  }
  failed : (__funcarg64 = FUNCCALL(SETUP_XfOrM607(_), filename_for_error (argv [0 ] ) ), __funcarg65 = FUNCCALL(SETUP_XfOrM607(_), filename_for_error (argv [1 ] ) ), FUNCCALL_EMPTY(scheme_raise_exn (pre_exists ? MZEXN_FAIL_FILESYSTEM_EXISTS : MZEXN_FAIL_FILESYSTEM , "copy-file: %s; cannot copy: %q to: %q" , reason , __funcarg64 , __funcarg65 ) )) ; 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * relative_path_p (int argc , Scheme_Object * * argv ) {
  char * s ; 
  int len ; 
  Scheme_Object * bs ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(bs, 0), PUSH(s, 1)));
# define XfOrM624_COUNT (2)
# define SETUP_XfOrM624(x) SETUP(XfOrM624_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  bs = NULLED_OUT ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) <= scheme_windows_path_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("relative-path?" , "path (for any platform) or string" , 0 , argc , argv ) ); 
  bs = (((((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) <= scheme_windows_path_type ) ) ? argv [0 ] : FUNCCALL(SETUP_XfOrM624(_), scheme_char_string_to_path (argv [0 ] ) )) ; 
  s = (((Scheme_Simple_Object * ) (bs ) ) -> u . byte_str_val . string_val ) ; 
  len = (((Scheme_Simple_Object * ) (bs ) ) -> u . byte_str_val . tag_val ) ; 
  if (FUNCCALL(SETUP_XfOrM624(_), has_null (s , len ) ))
    RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
  RET_VALUE_START ((FUNCCALL_EMPTY(scheme_is_relative_path (s , len , ((((long ) (bs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (bs ) ) -> type ) ) )? scheme_true : scheme_false ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * complete_path_p (int argc , Scheme_Object * * argv ) {
  char * s ; 
  int len ; 
  Scheme_Object * bs ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(bs, 0), PUSH(s, 1)));
# define XfOrM625_COUNT (2)
# define SETUP_XfOrM625(x) SETUP(XfOrM625_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  bs = NULLED_OUT ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) <= scheme_windows_path_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("complete-path?" , "path (for any platform) or string" , 0 , argc , argv ) ); 
  bs = (((((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) <= scheme_windows_path_type ) ) ? argv [0 ] : FUNCCALL(SETUP_XfOrM625(_), scheme_char_string_to_path (argv [0 ] ) )) ; 
  s = (((Scheme_Simple_Object * ) (bs ) ) -> u . byte_str_val . string_val ) ; 
  len = (((Scheme_Simple_Object * ) (bs ) ) -> u . byte_str_val . tag_val ) ; 
  if (FUNCCALL(SETUP_XfOrM625(_), has_null (s , len ) ))
    RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
  RET_VALUE_START ((FUNCCALL_EMPTY(scheme_is_complete_path (s , len , ((((long ) (bs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (bs ) ) -> type ) ) )? scheme_true : scheme_false ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * absolute_path_p (int argc , Scheme_Object * * argv ) {
  char * s ; 
  int len ; 
  Scheme_Object * bs ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(bs, 0), PUSH(s, 1)));
# define XfOrM626_COUNT (2)
# define SETUP_XfOrM626(x) SETUP(XfOrM626_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  bs = NULLED_OUT ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) <= scheme_windows_path_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("absolute-path?" , "path (for any platform) or string" , 0 , argc , argv ) ); 
  bs = (((((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) <= scheme_windows_path_type ) ) ? argv [0 ] : FUNCCALL(SETUP_XfOrM626(_), scheme_char_string_to_path (argv [0 ] ) )) ; 
  s = (((Scheme_Simple_Object * ) (bs ) ) -> u . byte_str_val . string_val ) ; 
  len = (((Scheme_Simple_Object * ) (bs ) ) -> u . byte_str_val . tag_val ) ; 
  if (FUNCCALL(SETUP_XfOrM626(_), has_null (s , len ) ))
    RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
  RET_VALUE_START ((! FUNCCALL_EMPTY(scheme_is_relative_path (s , len , ((((long ) (bs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (bs ) ) -> type ) ) )? scheme_true : scheme_false ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * resolve_path (int argc , Scheme_Object * argv [] ) {
  char buffer [2048 ] ; 
  long len ; 
  int copied = 0 ; 
  char * filename ; 
  int expanded ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(filename, 1)));
# define XfOrM627_COUNT (2)
# define SETUP_XfOrM627(x) SETUP(XfOrM627_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  filename = NULLED_OUT ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) <= scheme_windows_path_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("resolve-path" , "path (for any platform) or string" , 0 , argc , argv ) ); 
  filename = FUNCCALL(SETUP_XfOrM627(_), do_expand_filename (argv [0 ] , ((void * ) 0 ) , 0 , "resolve-path" , & expanded , 1 , 0 , 0x10 , scheme_unix_path_type ) ); 
  {
    char * fullfilename = filename ; 
    BLOCK_SETUP((PUSH(fullfilename, 0+XfOrM627_COUNT)));
#   define XfOrM628_COUNT (1+XfOrM627_COUNT)
#   define SETUP_XfOrM628(x) SETUP(XfOrM628_COUNT)
    len = strlen (fullfilename ) ; 
    if (! FUNCCALL(SETUP_XfOrM628(_), scheme_is_complete_path (fullfilename , len , scheme_unix_path_type ) )) {
#     define XfOrM637_COUNT (0+XfOrM628_COUNT)
#     define SETUP_XfOrM637(x) SETUP_XfOrM628(x)
      fullfilename = FUNCCALL(SETUP_XfOrM637(_), do_path_to_complete_path (fullfilename , len , ((void * ) 0 ) , 0 , scheme_unix_path_type ) ); 
      copied = 1 ; 
    }
    len = strlen (fullfilename ) ; 
    while (len && ((scheme_unix_path_type == scheme_unix_path_type ) ? ((fullfilename [len - 1 ] ) == '/' ) : (((fullfilename [len - 1 ] ) == '/' ) || ((fullfilename [len - 1 ] ) == '\\' ) ) ) ) {
#     define XfOrM635_COUNT (0+XfOrM628_COUNT)
#     define SETUP_XfOrM635(x) SETUP_XfOrM628(x)
      if (! expanded && ! copied ) {
#       define XfOrM636_COUNT (0+XfOrM635_COUNT)
#       define SETUP_XfOrM636(x) SETUP_XfOrM635(x)
        fullfilename = FUNCCALL(SETUP_XfOrM636(_), scheme_strdup (fullfilename ) ); 
        copied = 1 ; 
      }
      fullfilename [-- len ] = 0 ; 
    }
    while (1 ) {
#     define XfOrM631_COUNT (0+XfOrM628_COUNT)
#     define SETUP_XfOrM631(x) SETUP_XfOrM628(x)
      len = FUNCCALL(SETUP_XfOrM631(_), readlink (fullfilename , buffer , 2048 ) ); 
      if (len == - 1 ) {
        if ((* __errno_location () ) != 4 )
          break ; 
      }
      else break ; 
    }
    if (len > 0 )
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_path (buffer , len , 1 ) )) RET_VALUE_EMPTY_END ; 
  }
  if (! expanded )
    RET_VALUE_START (argv [0 ] ) RET_VALUE_END ; 
  else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_path (filename , strlen (filename ) , 1 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * convert_literal_relative (Scheme_Object * file ) {
  /* No conversion */
  int ln ; 
  char * f ; 
  f = (((Scheme_Simple_Object * ) (file ) ) -> u . byte_str_val . string_val ) ; 
  ln = (((Scheme_Simple_Object * ) (file ) ) -> u . byte_str_val . tag_val ) ; 
  if ((ln == 11 ) && ! strcmp (f , "\\\\?\\REL\\\\.." ) )
    return up_symbol ; 
  else if ((ln == 10 ) && ! strcmp (f , "\\\\?\\REL\\\\." ) )
    return same_symbol ; 
  return file ; 
}
static Scheme_Object * simplify_qm_path (Scheme_Object * path ) {
  char * s = (((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . string_val ) ; 
  int drive_end , clean_start , len = (((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . tag_val ) , fixed = 0 , i ; 
  int drop_extra_slash = - 1 , set_slash = - 1 , element_start ; 
  int found_bad = 0 , start_special_check = 0 , is_dir = 0 , norm_unc = 0 , drop_ss_slash = 0 ; 
  Scheme_Object * __funcarg66 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(path, 0), PUSH(s, 1)));
# define XfOrM639_COUNT (2)
# define SETUP_XfOrM639(x) SETUP(XfOrM639_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((s [len - 1 ] == '\\' ) && (s [len - 2 ] != '\\' ) && FUNCCALL(SETUP_XfOrM639(_), do_path_to_directory_path (s , 0 , len - 1 , scheme_true , 1 , scheme_windows_path_type ) )) {
    -- len ; 
    fixed = 1 ; 
  }
  FUNCCALL(SETUP_XfOrM639(_), check_dos_slashslash_qm (s , len , & drive_end , & clean_start , ((void * ) 0 ) ) ); 
  if ((drive_end == 7 ) && (((unsigned char ) s [4 ] < 128 ) && ((* FUNCCALL(SETUP_XfOrM639(_), __ctype_b_loc () )) [(int ) (((unsigned char ) s [4 ] ) ) ] & (unsigned short int ) _ISalpha ) ) && (s [5 ] == ':' ) ) {
    start_special_check = 7 ; 
    drive_end = 4 ; 
  }
  else if ((drive_end == 8 ) && (s [4 ] == '\\' ) && (((unsigned char ) s [5 ] < 128 ) && ((* FUNCCALL(SETUP_XfOrM639(_), __ctype_b_loc () )) [(int ) (((unsigned char ) s [5 ] ) ) ] & (unsigned short int ) _ISalpha ) ) && (s [6 ] == ':' ) ) {
    start_special_check = 8 ; 
    drive_end = 5 ; 
    drop_ss_slash = 1 ; 
  }
  else if (drive_end == - 2 ) {
    int lit_start ; 
#   define XfOrM674_COUNT (0+XfOrM639_COUNT)
#   define SETUP_XfOrM674(x) SETUP_XfOrM639(x)
    FUNCCALL(SETUP_XfOrM674(_), get_slashslash_qm_dot_ups_end (s , len , & lit_start ) ); 
    start_special_check = lit_start ; 
    drive_end = lit_start - 1 ; 
  }
  else if (drive_end < 0 ) {
    int lit_start , dots_end ; 
#   define XfOrM671_COUNT (0+XfOrM639_COUNT)
#   define SETUP_XfOrM671(x) SETUP_XfOrM639(x)
    dots_end = FUNCCALL(SETUP_XfOrM671(_), get_slashslash_qm_dot_ups_end (s , len , & lit_start ) ); 
    if (lit_start == len ) {
#     define XfOrM673_COUNT (0+XfOrM671_COUNT)
#     define SETUP_XfOrM673(x) SETUP_XfOrM671(x)
      RET_VALUE_START ((__funcarg66 = FUNCCALL(SETUP_XfOrM673(_), scheme_make_sized_offset_kind_path (s , 8 , dots_end - 8 , 1 , scheme_windows_path_type ) ), FUNCCALL_EMPTY(scheme_path_to_directory_path (__funcarg66 ) )) ) RET_VALUE_END ; 
    }
    start_special_check = lit_start ; 
    if (dots_end < 9 )
      drive_end = lit_start ; 
    else {
      drive_end = 8 ; 
      drop_extra_slash = dots_end ; 
      is_dir = 1 ; 
    }
  }
  else if ((clean_start == 7 ) && ((s [4 ] == 'U' ) || (s [4 ] == 'u' ) ) && ((s [5 ] == 'N' ) || (s [5 ] == 'n' ) ) && ((s [6 ] == 'C' ) || (s [6 ] == 'c' ) ) ) {
    if (drive_end == len ) {
      is_dir = 1 ; 
    }
    drive_end = 6 ; 
    start_special_check = 7 ; 
    set_slash = 6 ; 
    norm_unc = 1 ; 
  }
  else if ((clean_start == 8 ) && (s [4 ] == '\\' ) && ((s [5 ] == 'U' ) || (s [5 ] == 'u' ) ) && ((s [6 ] == 'N' ) || (s [6 ] == 'n' ) ) && ((s [7 ] == 'C' ) || (s [7 ] == 'c' ) ) ) {
    if (drive_end == len ) {
      is_dir = 1 ; 
    }
    drive_end = 7 ; 
    start_special_check = 8 ; 
    set_slash = 7 ; 
    norm_unc = 1 ; 
    drop_ss_slash = 1 ; 
  }
  else {
    found_bad = 1 ; 
    start_special_check = len ; 
  }
  if (! found_bad ) {
#   define XfOrM649_COUNT (0+XfOrM639_COUNT)
#   define SETUP_XfOrM649(x) SETUP_XfOrM639(x)
    element_start = start_special_check ; 
    for (i = element_start ; 1 ; i ++ ) {
#     define XfOrM658_COUNT (0+XfOrM649_COUNT)
#     define SETUP_XfOrM658(x) SETUP_XfOrM649(x)
      if ((i == len ) || (s [i ] == '\\' ) ) {
#       define XfOrM659_COUNT (0+XfOrM658_COUNT)
#       define SETUP_XfOrM659(x) SETUP_XfOrM658(x)
        if (element_start <= i - 1 ) {
          Scheme_Object * v ; 
          int any_more = 0 , j ; 
          BLOCK_SETUP((PUSH(v, 0+XfOrM659_COUNT)));
#         define XfOrM660_COUNT (1+XfOrM659_COUNT)
#         define SETUP_XfOrM660(x) SETUP(XfOrM660_COUNT)
          v = NULLED_OUT ; 
          for (j = i + 1 ; j < len ; j ++ ) {
            if (s [j ] != '\\' ) {
              any_more = 1 ; 
              break ; 
            }
          }
          v = FUNCCALL(SETUP_XfOrM660(_), make_protected_sized_offset_path (1 , s , element_start , i - element_start , 1 , (any_more ? 2 : 1 ) , scheme_windows_path_type ) ); 
          if ((! (((v ) ) == (scheme_false ) ) ) ) {
            found_bad = 1 ; 
            break ; 
          }
        }
        if (i == len )
          break ; 
        element_start = i + 1 ; 
      }
    }
  }
  if (found_bad ) {
#   define XfOrM643_COUNT (0+XfOrM639_COUNT)
#   define SETUP_XfOrM643(x) SETUP_XfOrM639(x)
    if (norm_unc ) {
      if ((s [4 + drop_ss_slash ] == 'U' ) && (s [5 + drop_ss_slash ] == 'N' ) && (s [6 + drop_ss_slash ] == 'C' ) )
        norm_unc = 0 ; 
    }
    if (norm_unc || drop_ss_slash ) {
#     define XfOrM644_COUNT (0+XfOrM643_COUNT)
#     define SETUP_XfOrM644(x) SETUP_XfOrM643(x)
      if (! fixed ) {
        char * naya ; 
        BLOCK_SETUP((PUSH(naya, 0+XfOrM644_COUNT)));
#       define XfOrM647_COUNT (1+XfOrM644_COUNT)
#       define SETUP_XfOrM647(x) SETUP(XfOrM647_COUNT)
        naya = NULLED_OUT ; 
        naya = (char * ) FUNCCALL(SETUP_XfOrM647(_), GC_malloc_atomic (len ) ); 
        (memcpy (naya , s , len ) ) ; 
        s = naya ; 
        fixed = 1 ; 
      }
      if (drop_ss_slash ) {
#       define XfOrM646_COUNT (0+XfOrM644_COUNT)
#       define SETUP_XfOrM646(x) SETUP_XfOrM644(x)
        (memmove (s + 3 , s + 4 , len - 4 ) ) ; 
        len -- ; 
      }
      if (norm_unc ) {
        s [4 ] = 'U' ; 
        s [5 ] = 'N' ; 
        s [6 ] = 'C' ; 
      }
    }
    if (fixed )
      path = FUNCCALL(SETUP_XfOrM643(_), scheme_make_sized_offset_kind_path (s , 0 , len , 1 , scheme_windows_path_type ) ); 
    RET_VALUE_START (path ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM640_COUNT (0+XfOrM639_COUNT)
#   define SETUP_XfOrM640(x) SETUP_XfOrM639(x)
    if (drop_extra_slash > - 1 ) {
      char * naya ; 
      BLOCK_SETUP((PUSH(naya, 0+XfOrM640_COUNT)));
#     define XfOrM642_COUNT (1+XfOrM640_COUNT)
#     define SETUP_XfOrM642(x) SETUP(XfOrM642_COUNT)
      naya = NULLED_OUT ; 
      naya = (char * ) FUNCCALL(SETUP_XfOrM642(_), GC_malloc_atomic (len ) ); 
      (memcpy (naya , s , drop_extra_slash ) ) ; 
      (memcpy (naya + drop_extra_slash , s + drop_extra_slash + 1 , len - drop_extra_slash - 1 ) ) ; 
      s = naya ; 
      -- len ; 
    }
    if (set_slash > - 1 ) {
      char * naya ; 
      BLOCK_SETUP((PUSH(naya, 0+XfOrM640_COUNT)));
#     define XfOrM641_COUNT (1+XfOrM640_COUNT)
#     define SETUP_XfOrM641(x) SETUP(XfOrM641_COUNT)
      naya = NULLED_OUT ; 
      naya = (char * ) FUNCCALL(SETUP_XfOrM641(_), GC_malloc_atomic (len ) ); 
      (memcpy (naya , s , len ) ) ; 
      naya [set_slash ] = '\\' ; 
      s = naya ; 
    }
    path = FUNCCALL(SETUP_XfOrM640(_), scheme_make_sized_offset_kind_path (s , drive_end , len - drive_end , 1 , scheme_windows_path_type ) ); 
    if (is_dir )
      path = FUNCCALL(SETUP_XfOrM640(_), scheme_path_to_directory_path (path ) ); 
    RET_VALUE_START (path ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_simplify_path (Scheme_Object * path , Scheme_Object * cycle_check , int skip , int use_filesystem , int force_rel_up , int kind ) {
  int isdir , cleaned_slashes = 0 , must_be_dir = 0 , last_was_dir = 0 , did_first = 0 ; 
  Scheme_Object * file = scheme_false , * base ; 
  Scheme_Object * __funcarg69 = NULLED_OUT ; 
  Scheme_Object * __funcarg68 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(15);
  BLOCK_SETUP_TOP((PUSH(base, 0), PUSH(cycle_check, 1), PUSH(path, 2), PUSH(file, 3)));
# define XfOrM678_COUNT (4)
# define SETUP_XfOrM678(x) SETUP(XfOrM678_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  base = NULLED_OUT ; 
  if (kind == scheme_windows_path_type ) {
    char * s ; 
    int expanded , add_sep = 0 ; 
    BLOCK_SETUP((PUSH(s, 0+XfOrM678_COUNT)));
#   define XfOrM780_COUNT (1+XfOrM678_COUNT)
#   define SETUP_XfOrM780(x) SETUP(XfOrM780_COUNT)
    s = NULLED_OUT ; 
    s = FUNCCALL(SETUP_XfOrM780(_), do_expand_filename (path , (((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . string_val ) , (((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . tag_val ) , ((void * ) 0 ) , & expanded , 0 , 0 , 0 , kind ) ); 
    {
      int slen ; 
#     define XfOrM786_COUNT (0+XfOrM780_COUNT)
#     define SETUP_XfOrM786(x) SETUP_XfOrM780(x)
      if (expanded )
        slen = strlen (s ) ; 
      else slen = (((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . tag_val ) ; 
      s = FUNCCALL(SETUP_XfOrM786(_), do_normal_path_seps (s , & slen , 0 , 0 , scheme_windows_path_type , & expanded ) ); 
    }
    if (expanded ) {
#     define XfOrM785_COUNT (0+XfOrM780_COUNT)
#     define SETUP_XfOrM785(x) SETUP_XfOrM780(x)
      path = FUNCCALL(SETUP_XfOrM785(_), scheme_make_sized_offset_kind_path (s , 0 , - 1 , 0 , scheme_windows_path_type ) ); 
    }
    if (! FUNCCALL(SETUP_XfOrM780(_), check_dos_slashslash_qm ((((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . string_val ) , (((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . tag_val ) , ((void * ) 0 ) , ((void * ) 0 ) , & add_sep ) )) {
      int len = (((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . tag_val ) ; 
#     define XfOrM784_COUNT (0+XfOrM780_COUNT)
#     define SETUP_XfOrM784(x) SETUP_XfOrM780(x)
      s = FUNCCALL(SETUP_XfOrM784(_), strip_trailing_spaces ((((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . string_val ) , & len , 0 , 0 ) ); 
      if (s != (((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . string_val ) )
        path = FUNCCALL(SETUP_XfOrM784(_), scheme_make_sized_offset_kind_path (s , 0 , - 1 , 0 , scheme_windows_path_type ) ); 
    }
    else if (add_sep ) {
      int len = (((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . tag_val ) ; 
#     define XfOrM781_COUNT (0+XfOrM780_COUNT)
#     define SETUP_XfOrM781(x) SETUP_XfOrM780(x)
      if ((add_sep < len ) && (s [add_sep ] != '\\' ) ) {
        char * naya ; 
        BLOCK_SETUP((PUSH(naya, 0+XfOrM781_COUNT)));
#       define XfOrM783_COUNT (1+XfOrM781_COUNT)
#       define SETUP_XfOrM783(x) SETUP(XfOrM783_COUNT)
        naya = NULLED_OUT ; 
        naya = (char * ) FUNCCALL(SETUP_XfOrM783(_), GC_malloc_atomic (len + 3 ) ); 
        (memcpy (naya , s , add_sep ) ) ; 
        naya [add_sep ] = '\\' ; 
        naya [add_sep + 1 ] = '\\' ; 
        (memcpy (naya + add_sep + 2 , s + add_sep , len + 1 - add_sep ) ) ; 
        len += 2 ; 
        path = FUNCCALL(SETUP_XfOrM783(_), scheme_make_sized_offset_kind_path (naya , 0 , len , 0 , scheme_windows_path_type ) ); 
      }
      else if (((add_sep + 1 ) < len ) && (s [add_sep ] == '\\' ) && (s [add_sep + 1 ] != '\\' ) ) {
        char * naya ; 
        BLOCK_SETUP((PUSH(naya, 0+XfOrM781_COUNT)));
#       define XfOrM782_COUNT (1+XfOrM781_COUNT)
#       define SETUP_XfOrM782(x) SETUP(XfOrM782_COUNT)
        naya = NULLED_OUT ; 
        naya = (char * ) FUNCCALL(SETUP_XfOrM782(_), GC_malloc_atomic (len + 2 ) ); 
        (memcpy (naya , s , add_sep ) ) ; 
        naya [add_sep ] = '\\' ; 
        (memcpy (naya + add_sep + 1 , s + add_sep , len + 1 - add_sep ) ) ; 
        len ++ ; 
        path = FUNCCALL(SETUP_XfOrM782(_), scheme_make_sized_offset_kind_path (naya , 0 , len , 0 , scheme_windows_path_type ) ); 
      }
    }
  }
  {
    char * s ; 
    int len , i , saw_dot = 0 ; 
    BLOCK_SETUP((PUSH(s, 0+XfOrM678_COUNT)));
#   define XfOrM754_COUNT (1+XfOrM678_COUNT)
#   define SETUP_XfOrM754(x) SETUP(XfOrM754_COUNT)
    s = NULLED_OUT ; 
    s = (((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . string_val ) ; 
    len = (((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . tag_val ) ; 
    if (kind == scheme_windows_path_type ) {
#     define XfOrM767_COUNT (0+XfOrM754_COUNT)
#     define SETUP_XfOrM767(x) SETUP_XfOrM754(x)
      if (! skip && FUNCCALL(SETUP_XfOrM767(_), check_dos_slashslash_qm (s , len , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) ) )) {
#       define XfOrM775_COUNT (0+XfOrM767_COUNT)
#       define SETUP_XfOrM775(x) SETUP_XfOrM767(x)
        if (! force_rel_up ) {
          int drive_end ; 
#         define XfOrM777_COUNT (0+XfOrM775_COUNT)
#         define SETUP_XfOrM777(x) SETUP_XfOrM775(x)
          path = FUNCCALL(SETUP_XfOrM777(_), simplify_qm_path (path ) ); 
          len = (((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . tag_val ) ; 
          if (FUNCCALL(SETUP_XfOrM777(_), check_dos_slashslash_qm ((((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . string_val ) , len , & drive_end , ((void * ) 0 ) , ((void * ) 0 ) ) )) {
#           define XfOrM778_COUNT (0+XfOrM777_COUNT)
#           define SETUP_XfOrM778(x) SETUP_XfOrM777(x)
            if (drive_end == len ) {
#             define XfOrM779_COUNT (0+XfOrM778_COUNT)
#             define SETUP_XfOrM779(x) SETUP_XfOrM778(x)
              path = FUNCCALL(SETUP_XfOrM779(_), scheme_path_to_directory_path (path ) ); 
            }
          }
          RET_VALUE_START (path ) RET_VALUE_END ; 
        }
        else {
#         define XfOrM776_COUNT (0+XfOrM775_COUNT)
#         define SETUP_XfOrM776(x) SETUP_XfOrM775(x)
          RET_VALUE_START (FUNCCALL(SETUP_XfOrM776(_), scheme_path_to_directory_path (path ) )) RET_VALUE_END ; 
        }
      }
      if (! skip && FUNCCALL(SETUP_XfOrM767(_), check_dos_slashslash_drive (s , 0 , len , ((void * ) 0 ) , 1 , 0 ) )) {
#       define XfOrM771_COUNT (0+XfOrM767_COUNT)
#       define SETUP_XfOrM771(x) SETUP_XfOrM767(x)
        for (i = len ; (((s [i - 1 ] ) == '/' ) || ((s [i - 1 ] ) == '\\' ) ) ; i -- ) {
        }
        if (i < len - 1 ) {
#         define XfOrM772_COUNT (0+XfOrM771_COUNT)
#         define SETUP_XfOrM772(x) SETUP_XfOrM771(x)
          path = FUNCCALL(SETUP_XfOrM772(_), scheme_make_sized_offset_kind_path (s , 0 , i , 1 , scheme_windows_path_type ) ); 
        }
        path = FUNCCALL(SETUP_XfOrM771(_), scheme_path_to_directory_path (path ) ); 
      }
      if (skip ) {
        while (s [skip ] == '\\' ) {
          skip ++ ; 
        }
      }
    }
    i = skip ; 
    if (kind == scheme_windows_path_type ) {
#     define XfOrM763_COUNT (0+XfOrM754_COUNT)
#     define SETUP_XfOrM763(x) SETUP_XfOrM754(x)
      if (! i && (len >= 2 ) && (((unsigned char ) s [0 ] < 128 ) && ((* FUNCCALL(SETUP_XfOrM763(_), __ctype_b_loc () )) [(int ) (((unsigned char ) s [0 ] ) ) ] & (unsigned short int ) _ISalpha ) ) && s [1 ] == ':' ) {
        i = 2 ; 
      }
      else if (! i ) {
        int drive_end ; 
#       define XfOrM764_COUNT (0+XfOrM763_COUNT)
#       define SETUP_XfOrM764(x) SETUP_XfOrM763(x)
        if (FUNCCALL(SETUP_XfOrM764(_), check_dos_slashslash_drive (s , 0 , len , & drive_end , 0 , 0 ) )) {
          i = drive_end ; 
        }
      }
    }
    for (; i < len ; i ++ ) {
      if (s [i ] == '.' )
        saw_dot ++ ; 
      else if (((kind == scheme_unix_path_type ) ? ((s [i ] ) == '/' ) : (((s [i ] ) == '/' ) || ((s [i ] ) == '\\' ) ) ) ) {
        if ((saw_dot == 1 ) || (saw_dot == 2 ) )
          break ; 
        if ((i + 1 < len ) && (((kind == scheme_unix_path_type ) ? ((s [i ] ) == '/' ) : (((s [i ] ) == '/' ) || ((s [i ] ) == '\\' ) ) ) ) ) {
          break ; 
        }
        saw_dot = 0 ; 
      }
      else saw_dot = 3 ; 
    }
    if (i == len ) {
#     define XfOrM755_COUNT (0+XfOrM754_COUNT)
#     define SETUP_XfOrM755(x) SETUP_XfOrM754(x)
      if ((saw_dot != 1 ) && (saw_dot != 2 ) ) {
#       define XfOrM756_COUNT (0+XfOrM755_COUNT)
#       define SETUP_XfOrM756(x) SETUP_XfOrM755(x)
        if (FUNCCALL(SETUP_XfOrM756(_), path_is_simple_dir_without_sep (path ) ))
          path = FUNCCALL(SETUP_XfOrM756(_), scheme_path_to_directory_path (path ) ); 
        RET_VALUE_START (path ) RET_VALUE_END ; 
      }
    }
  }
  if (! cleaned_slashes ) {
#   define XfOrM747_COUNT (0+XfOrM678_COUNT)
#   define SETUP_XfOrM747(x) SETUP_XfOrM678(x)
    base = path ; 
    do {
      char * s ; 
      int len ; 
      BLOCK_SETUP((PUSH(s, 0+XfOrM747_COUNT)));
#     define XfOrM751_COUNT (1+XfOrM747_COUNT)
#     define SETUP_XfOrM751(x) SETUP(XfOrM751_COUNT)
      s = NULLED_OUT ; 
      s = (((Scheme_Simple_Object * ) (base ) ) -> u . byte_str_val . string_val ) ; 
      len = (((Scheme_Simple_Object * ) (base ) ) -> u . byte_str_val . tag_val ) ; 
      if (len <= skip )
        break ; 
      file = FUNCCALL(SETUP_XfOrM751(_), do_split_path (s , len , & base , & isdir , & cleaned_slashes , kind ) ); 
      if (kind == scheme_windows_path_type ) {
#       define XfOrM752_COUNT (0+XfOrM751_COUNT)
#       define SETUP_XfOrM752(x) SETUP_XfOrM751(x)
        if (force_rel_up ) {
#         define XfOrM753_COUNT (0+XfOrM752_COUNT)
#         define SETUP_XfOrM753(x) SETUP_XfOrM752(x)
          file = FUNCCALL(SETUP_XfOrM753(_), convert_literal_relative (file ) ); 
        }
      }
      if (((Scheme_Type ) (((((long ) (file ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (file ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || cleaned_slashes )
        break ; 
    }
    while (((((((long ) (base ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (base ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (base ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (base ) ) -> type ) <= scheme_windows_path_type ) ) ) ; 
  }
  else file = scheme_false ; 
  if (((Scheme_Type ) (((((long ) (file ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (file ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || cleaned_slashes ) {
    char * s ; 
    int len ; 
    Scheme_Object * accum = scheme_null , * result ; 
    BLOCK_SETUP((PUSH(accum, 0+XfOrM678_COUNT), PUSH(result, 1+XfOrM678_COUNT), PUSH(s, 2+XfOrM678_COUNT)));
#   define XfOrM679_COUNT (3+XfOrM678_COUNT)
#   define SETUP_XfOrM679(x) SETUP(XfOrM679_COUNT)
    s = NULLED_OUT ; 
    result = NULLED_OUT ; 
    s = (((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . string_val ) ; 
    len = (((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . tag_val ) ; 
    if (use_filesystem && ! FUNCCALL(SETUP_XfOrM679(_), scheme_is_complete_path (s , len , kind ) )) {
#     define XfOrM746_COUNT (0+XfOrM679_COUNT)
#     define SETUP_XfOrM746(x) SETUP_XfOrM679(x)
      s = FUNCCALL(SETUP_XfOrM746(_), scheme_expand_string_filename (path , "simplify-path" , ((void * ) 0 ) , 0x10 ) ); 
      len = strlen (s ) ; 
    }
    if (use_filesystem ) {
#     define XfOrM740_COUNT (0+XfOrM679_COUNT)
#     define SETUP_XfOrM740(x) SETUP_XfOrM679(x)
      {
        Scheme_Object * l = cycle_check ; 
        BLOCK_SETUP((PUSH(l, 0+XfOrM740_COUNT)));
#       define XfOrM741_COUNT (1+XfOrM740_COUNT)
#       define SETUP_XfOrM741(x) SETUP(XfOrM741_COUNT)
        while (! ((l ) == (scheme_null ) ) ) {
          Scheme_Object * p = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
          BLOCK_SETUP((PUSH(p, 0+XfOrM741_COUNT)));
#         define XfOrM744_COUNT (1+XfOrM741_COUNT)
#         define SETUP_XfOrM744(x) SETUP(XfOrM744_COUNT)
          if ((len == (((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . tag_val ) ) && ! (strcmp (s , (((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . string_val ) ) ) ) {
#           define XfOrM745_COUNT (0+XfOrM744_COUNT)
#           define SETUP_XfOrM745(x) SETUP_XfOrM744(x)
            FUNCCALL(SETUP_XfOrM745(_), scheme_raise_exn (MZEXN_FAIL_FILESYSTEM , "simplify-path: cycle detected at link: \"%q\"" , s ) ); 
          }
          l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
        }
      }
      cycle_check = (__funcarg69 = FUNCCALL(SETUP_XfOrM740(_), scheme_make_sized_path (s , len , 0 ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg69 , cycle_check ) )) ; 
    }
    while (1 ) {
#     define XfOrM731_COUNT (0+XfOrM679_COUNT)
#     define SETUP_XfOrM731(x) SETUP_XfOrM679(x)
      if (len <= skip ) {
#       define XfOrM739_COUNT (0+XfOrM731_COUNT)
#       define SETUP_XfOrM739(x) SETUP_XfOrM731(x)
        accum = (__funcarg68 = FUNCCALL(SETUP_XfOrM739(_), scheme_make_sized_offset_kind_path (s , 0 , len , 0 , kind ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg68 , accum ) )) ; 
        break ; 
      }
      file = FUNCCALL(SETUP_XfOrM731(_), scheme_split_path (s , len , & base , & isdir , kind ) ); 
      if (kind == scheme_windows_path_type ) {
#       define XfOrM737_COUNT (0+XfOrM731_COUNT)
#       define SETUP_XfOrM737(x) SETUP_XfOrM731(x)
        if (force_rel_up ) {
#         define XfOrM738_COUNT (0+XfOrM737_COUNT)
#         define SETUP_XfOrM738(x) SETUP_XfOrM737(x)
          file = FUNCCALL(SETUP_XfOrM738(_), convert_literal_relative (file ) ); 
          if (((Scheme_Type ) (((((long ) (file ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (file ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
            isdir = 1 ; 
        }
      }
      if (! did_first ) {
        must_be_dir = isdir ; 
        did_first = 1 ; 
      }
      if (((file ) == (same_symbol ) ) ) {
      }
      else accum = FUNCCALL(SETUP_XfOrM731(_), scheme_make_pair (file , accum ) ); 
      if (((((((long ) (base ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (base ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (base ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (base ) ) -> type ) <= scheme_windows_path_type ) ) ) {
        s = (((Scheme_Simple_Object * ) (base ) ) -> u . byte_str_val . string_val ) ; 
        len = (((Scheme_Simple_Object * ) (base ) ) -> u . byte_str_val . tag_val ) ; 
      }
      else {
#       define XfOrM732_COUNT (0+XfOrM731_COUNT)
#       define SETUP_XfOrM732(x) SETUP_XfOrM731(x)
        if (use_filesystem ) {
#         define XfOrM733_COUNT (0+XfOrM732_COUNT)
#         define SETUP_XfOrM733(x) SETUP_XfOrM732(x)
          accum = FUNCCALL(SETUP_XfOrM733(_), scheme_make_pair (file , (((Scheme_Simple_Object * ) (accum ) ) -> u . pair_val . cdr ) ) ); 
        }
        break ; 
      }
    }
    if (((accum ) == (scheme_null ) ) ) {
      result = scheme_false ; 
    }
    else {
      result = (((Scheme_Simple_Object * ) (accum ) ) -> u . pair_val . car ) ; 
      if (((result ) == (up_symbol ) ) ) {
        result = scheme_false ; 
      }
      else accum = (((Scheme_Simple_Object * ) (accum ) ) -> u . pair_val . cdr ) ; 
    }
    while (! ((accum ) == (scheme_null ) ) ) {
#     define XfOrM700_COUNT (0+XfOrM679_COUNT)
#     define SETUP_XfOrM700(x) SETUP_XfOrM679(x)
      if ((((((Scheme_Simple_Object * ) (accum ) ) -> u . pair_val . car ) ) == (up_symbol ) ) ) {
#       define XfOrM703_COUNT (0+XfOrM700_COUNT)
#       define SETUP_XfOrM703(x) SETUP_XfOrM700(x)
        if (use_filesystem ) {
          Scheme_Object * new_result , * a [1 ] ; 
          BLOCK_SETUP((PUSH(new_result, 0+XfOrM703_COUNT), PUSHARRAY(a, 1, 1+XfOrM703_COUNT)));
#         define XfOrM712_COUNT (4+XfOrM703_COUNT)
#         define SETUP_XfOrM712(x) SETUP(XfOrM712_COUNT)
          new_result = NULLED_OUT ; 
          a[0] = NULLED_OUT ; 
          while (1 ) {
#           define XfOrM716_COUNT (0+XfOrM712_COUNT)
#           define SETUP_XfOrM716(x) SETUP_XfOrM712(x)
            a [0 ] = result ; 
            new_result = FUNCCALL(SETUP_XfOrM716(_), resolve_path (1 , a ) ); 
            if (result != new_result ) {
#             define XfOrM717_COUNT (0+XfOrM716_COUNT)
#             define SETUP_XfOrM717(x) SETUP_XfOrM716(x)
              if (! FUNCCALL(SETUP_XfOrM717(_), scheme_is_complete_path ((((Scheme_Simple_Object * ) (new_result ) ) -> u . byte_str_val . string_val ) , (((Scheme_Simple_Object * ) (new_result ) ) -> u . byte_str_val . tag_val ) , kind ) )) {
                Scheme_Object * aa [2 ] , * result_base ; 
                BLOCK_SETUP((PUSH(result_base, 0+XfOrM717_COUNT), PUSHARRAY(aa, 2, 1+XfOrM717_COUNT)));
#               define XfOrM718_COUNT (4+XfOrM717_COUNT)
#               define SETUP_XfOrM718(x) SETUP(XfOrM718_COUNT)
                aa[0] = NULLED_OUT ; 
                aa[1] = NULLED_OUT ; 
                result_base = NULLED_OUT ; 
                FUNCCALL(SETUP_XfOrM718(_), scheme_split_path ((((Scheme_Simple_Object * ) (result ) ) -> u . byte_str_val . string_val ) , (((Scheme_Simple_Object * ) (result ) ) -> u . byte_str_val . tag_val ) , & result_base , & isdir , kind ) ); 
                aa [0 ] = result_base ; 
                aa [1 ] = new_result ; 
                new_result = FUNCCALL(SETUP_XfOrM718(_), do_build_path (2 , aa , 0 , 0 , scheme_unix_path_type ) ); 
              }
              result = FUNCCALL(SETUP_XfOrM717(_), do_simplify_path (new_result , cycle_check , skip , use_filesystem , force_rel_up , kind ) ); 
              cycle_check = FUNCCALL(SETUP_XfOrM717(_), scheme_make_pair (new_result , cycle_check ) ); 
            }
            else break ; 
          }
        }
        {
#         define XfOrM704_COUNT (0+XfOrM703_COUNT)
#         define SETUP_XfOrM704(x) SETUP_XfOrM703(x)
          accum = (((Scheme_Simple_Object * ) (accum ) ) -> u . pair_val . cdr ) ; 
          if ((((result ) ) == (scheme_false ) ) ) {
#           define XfOrM711_COUNT (0+XfOrM704_COUNT)
#           define SETUP_XfOrM711(x) SETUP_XfOrM704(x)
            if (skip )
              result = FUNCCALL(SETUP_XfOrM711(_), scheme_make_sized_offset_kind_path ("\\\\?\\REL\\.." , 0 , 10 , 0 , scheme_windows_path_type ) ); 
            else result = FUNCCALL(SETUP_XfOrM711(_), scheme_make_sized_offset_kind_path (".." , 0 , 2 , 0 , kind ) ); 
          }
          else {
            Scheme_Object * next , * to_go ; 
            BLOCK_SETUP((PUSH(to_go, 0+XfOrM704_COUNT), PUSH(next, 1+XfOrM704_COUNT)));
#           define XfOrM705_COUNT (2+XfOrM704_COUNT)
#           define SETUP_XfOrM705(x) SETUP(XfOrM705_COUNT)
            next = NULLED_OUT ; 
            to_go = NULLED_OUT ; 
            to_go = FUNCCALL(SETUP_XfOrM705(_), scheme_split_path ((((Scheme_Simple_Object * ) (result ) ) -> u . byte_str_val . string_val ) , (((Scheme_Simple_Object * ) (result ) ) -> u . byte_str_val . tag_val ) , & next , & isdir , kind ) ); 
            if (((to_go ) == (up_symbol ) ) ) {
              Scheme_Object * a [2 ] ; 
              BLOCK_SETUP((PUSHARRAY(a, 2, 0+XfOrM705_COUNT)));
#             define XfOrM710_COUNT (3+XfOrM705_COUNT)
#             define SETUP_XfOrM710(x) SETUP(XfOrM710_COUNT)
              a[0] = NULLED_OUT ; 
              a[1] = NULLED_OUT ; 
              a [0 ] = result ; 
              a [1 ] = up_symbol ; 
              result = FUNCCALL(SETUP_XfOrM710(_), do_build_path (2 , a , 0 , 1 , kind ) ); 
            }
            else if ((kind == scheme_unix_path_type ) && (((next ) ) == (scheme_false ) ) && ((((((long ) (to_go ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (to_go ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (to_go ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (to_go ) ) -> type ) <= scheme_windows_path_type ) ) && (((Scheme_Simple_Object * ) (to_go ) ) -> u . byte_str_val . string_val ) [0 ] == '~' ) {
              Scheme_Object * a [2 ] ; 
              BLOCK_SETUP((PUSHARRAY(a, 2, 0+XfOrM705_COUNT)));
#             define XfOrM709_COUNT (3+XfOrM705_COUNT)
#             define SETUP_XfOrM709(x) SETUP(XfOrM709_COUNT)
              a[0] = NULLED_OUT ; 
              a[1] = NULLED_OUT ; 
              a [0 ] = result ; 
              a [1 ] = up_symbol ; 
              result = FUNCCALL(SETUP_XfOrM709(_), do_build_path (2 , a , 0 , 1 , kind ) ); 
            }
            else if (! (((Scheme_Type ) (((((long ) (next ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (next ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((((((long ) (next ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (next ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (next ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (next ) ) -> type ) <= scheme_windows_path_type ) ) ) ) {
              if ((((next ) ) == (scheme_false ) ) ) {
              }
              else {
                result = scheme_false ; 
              }
            }
            else result = next ; 
          }
        }
        last_was_dir = 1 ; 
      }
      else {
#       define XfOrM701_COUNT (0+XfOrM700_COUNT)
#       define SETUP_XfOrM701(x) SETUP_XfOrM700(x)
        if ((((result ) ) == (scheme_false ) ) )
          result = (((Scheme_Simple_Object * ) (accum ) ) -> u . pair_val . car ) ; 
        else {
          Scheme_Object * a [2 ] ; 
          BLOCK_SETUP((PUSHARRAY(a, 2, 0+XfOrM701_COUNT)));
#         define XfOrM702_COUNT (3+XfOrM701_COUNT)
#         define SETUP_XfOrM702(x) SETUP(XfOrM702_COUNT)
          a[0] = NULLED_OUT ; 
          a[1] = NULLED_OUT ; 
          a [0 ] = result ; 
          a [1 ] = (((Scheme_Simple_Object * ) (accum ) ) -> u . pair_val . car ) ; 
          result = FUNCCALL(SETUP_XfOrM702(_), do_build_path (2 , a , 0 , 0 , kind ) ); 
        }
        accum = (((Scheme_Simple_Object * ) (accum ) ) -> u . pair_val . cdr ) ; 
        last_was_dir = 0 ; 
      }
    }
    if ((must_be_dir || last_was_dir ) && ! (((result ) ) == (scheme_false ) ) ) {
#     define XfOrM680_COUNT (0+XfOrM679_COUNT)
#     define SETUP_XfOrM680(x) SETUP_XfOrM679(x)
      result = FUNCCALL(SETUP_XfOrM680(_), scheme_path_to_directory_path (result ) ); 
    }
    RET_VALUE_START (result ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (path ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * simplify_path (int argc , Scheme_Object * argv [] ) {
  char * s ; 
  int len , use_fs , kind ; 
  Scheme_Object * bs , * r ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(bs, 0), PUSH(argv, 1), PUSH(r, 2), PUSH(s, 3)));
# define XfOrM787_COUNT (4)
# define SETUP_XfOrM787(x) SETUP(XfOrM787_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  bs = NULLED_OUT ; 
  r = NULLED_OUT ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) <= scheme_windows_path_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("simplify-path" , "path (for any platform) or string" , 0 , argc , argv ) ); 
  bs = (((((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) <= scheme_windows_path_type ) ) ? argv [0 ] : FUNCCALL(SETUP_XfOrM787(_), scheme_char_string_to_path (argv [0 ] ) )) ; 
  s = (((Scheme_Simple_Object * ) (bs ) ) -> u . byte_str_val . string_val ) ; 
  len = (((Scheme_Simple_Object * ) (bs ) ) -> u . byte_str_val . tag_val ) ; 
  if (FUNCCALL(SETUP_XfOrM787(_), has_null (s , len ) ))
    FUNCCALL(SETUP_XfOrM787(_), raise_null_error ("simplify-path" , argv [0 ] , "" ) ); 
  use_fs = ((argc <= 1 ) || (! (((argv [1 ] ) ) == (scheme_false ) ) ) ) ; 
  kind = ((((long ) (bs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (bs ) ) -> type ) ; 
  if (use_fs && (kind != scheme_unix_path_type ) ) {
#   define XfOrM789_COUNT (0+XfOrM787_COUNT)
#   define SETUP_XfOrM789(x) SETUP_XfOrM787(x)
    FUNCCALL(SETUP_XfOrM789(_), scheme_arg_mismatch ("simplify-path" , "in use-filesystem mode, path is not for the current platform: " , argv [0 ] ) ); 
  }
  r = FUNCCALL(SETUP_XfOrM787(_), do_simplify_path (bs , scheme_null , 0 , use_fs , 0 , kind ) ); 
  if ((((r ) ) == (scheme_false ) ) ) {
#   define XfOrM788_COUNT (0+XfOrM787_COUNT)
#   define SETUP_XfOrM788(x) SETUP_XfOrM787(x)
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_offset_kind_path ((kind == scheme_windows_path_type ) ? ".\\" : "./" , 0 , 2 , 0 , kind ) )) RET_VALUE_EMPTY_END ; 
  }
  RET_VALUE_START (r ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * current_drive (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  scheme_raise_exn (MZEXN_FAIL_UNSUPPORTED , "current-drive: not supported" ) ; 
  return ((void * ) 0 ) ; 
}
static Scheme_Object * expand_path (int argc , Scheme_Object * argv [] ) {
  char * filename ; 
  int expanded ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(filename, 1)));
# define XfOrM791_COUNT (2)
# define SETUP_XfOrM791(x) SETUP(XfOrM791_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  filename = NULLED_OUT ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("expand-path" , "path or string" , 0 , argc , argv ) ); 
  filename = FUNCCALL(SETUP_XfOrM791(_), do_expand_filename (argv [0 ] , ((void * ) 0 ) , 0 , "expand-path" , & expanded , 1 , 0 , 0x10 , scheme_unix_path_type ) ); 
  if (! expanded && ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) )
    RET_VALUE_START (argv [0 ] ) RET_VALUE_END ; 
  else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_path (filename , strlen (filename ) , 1 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_directory_list (int break_ok , int argc , Scheme_Object * argv [] ) {
  char * filename ; 
  Scheme_Object * volatile first = scheme_null , * volatile last = ((void * ) 0 ) , * n , * elem ; 
  DIR * dir ; 
  int nlen ; 
  struct dirent * e ; 
  volatile int counter = 0 ; 
  Scheme_Config * __funcarg70 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(first, 0), PUSH(e, 1), PUSH(dir, 2), PUSH(last, 3), PUSH(n, 4), PUSH(elem, 5), PUSH(filename, 6)));
# define XfOrM792_COUNT (7)
# define SETUP_XfOrM792(x) SETUP(XfOrM792_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  filename = NULLED_OUT ; 
  n = NULLED_OUT ; 
  elem = NULLED_OUT ; 
  dir = NULLED_OUT ; 
  e = NULLED_OUT ; 
  if (argc && ! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("directory-list" , "path or string" , 0 , argc , argv ) ); 
  if (argc ) {
    Scheme_Object * path = argv [0 ] ; 
#   define XfOrM806_COUNT (0+XfOrM792_COUNT)
#   define SETUP_XfOrM806(x) SETUP_XfOrM792(x)
    filename = FUNCCALL(SETUP_XfOrM806(_), do_expand_filename (path , ((void * ) 0 ) , 0 , break_ok ? "directory-list" : ((void * ) 0 ) , ((void * ) 0 ) , 1 , 259 - 4 , break_ok ? 0x1 : 0 , scheme_unix_path_type ) ); 
    if (! filename )
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM804_COUNT (0+XfOrM792_COUNT)
#   define SETUP_XfOrM804(x) SETUP_XfOrM792(x)
    filename = (((Scheme_Simple_Object * ) ((__funcarg70 = FUNCCALL(SETUP_XfOrM804(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg70 , MZCONFIG_CURRENT_DIRECTORY ) )) ) ) -> u . byte_str_val . string_val ) ; 
    if (break_ok ) {
#     define XfOrM805_COUNT (0+XfOrM804_COUNT)
#     define SETUP_XfOrM805(x) SETUP_XfOrM804(x)
      FUNCCALL(SETUP_XfOrM805(_), scheme_security_check_file ("directory-list" , ((void * ) 0 ) , 0x10 ) ); 
      FUNCCALL(SETUP_XfOrM805(_), scheme_security_check_file ("directory-list" , filename , 0x1 ) ); 
    }
  }
  dir = FUNCCALL(SETUP_XfOrM792(_), opendir (filename ? filename : "." ) ); 
  if (! dir ) {
#   define XfOrM803_COUNT (0+XfOrM792_COUNT)
#   define SETUP_XfOrM803(x) SETUP_XfOrM792(x)
    if (! filename )
      RET_VALUE_START (scheme_null ) RET_VALUE_END ; 
    if (break_ok )
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_FILESYSTEM , "directory-list: could not open \"%q\" (%e)" , filename , (* __errno_location () ) ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  while ((e = FUNCCALL(SETUP_XfOrM792(_), readdir (dir ) )) ) {
#   define XfOrM798_COUNT (0+XfOrM792_COUNT)
#   define SETUP_XfOrM798(x) SETUP_XfOrM792(x)
    nlen = strlen (e -> d_name ) ; 
    if (nlen == 1 && e -> d_name [0 ] == '.' )
      continue ; 
    if (nlen == 2 && e -> d_name [0 ] == '.' && e -> d_name [1 ] == '.' )
      continue ; 
    n = FUNCCALL(SETUP_XfOrM798(_), make_protected_sized_offset_path (1 , e -> d_name , 0 , nlen , 1 , 0 , scheme_unix_path_type ) ); 
    elem = FUNCCALL_AGAIN(scheme_make_pair (n , scheme_null ) ); 
    if (last )
      (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = elem ; 
    else first = elem ; 
    last = elem ; 
    counter ++ ; 
    if (break_ok && ! (counter & 0xF ) ) {
#     define XfOrM799_COUNT (0+XfOrM798_COUNT)
#     define SETUP_XfOrM799(x) SETUP_XfOrM798(x)
      {
        mz_jmp_buf * volatile savebuf , newbuf ; 
        BLOCK_SETUP((PUSH(savebuf, 0+XfOrM799_COUNT)));
#       define XfOrM800_COUNT (1+XfOrM799_COUNT)
#       define SETUP_XfOrM800(x) SETUP(XfOrM800_COUNT)
        savebuf = NULLED_OUT ; 
        FUNCCALL(SETUP_XfOrM800(_), scheme_push_kill_action ((Scheme_Kill_Action_Func ) closedir , (void * ) dir ) ); 
        savebuf = scheme_current_thread -> error_buf ; 
        scheme_current_thread -> error_buf = & newbuf ; 
        if (((newbuf ) . gcvs = (long ) __gc_var_stack__ , (newbuf ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((newbuf ) . jb ) , (_setjmp (((newbuf ) . jb ) -> jb ) ) ) ) ) {
#         define XfOrM802_COUNT (0+XfOrM800_COUNT)
#         define SETUP_XfOrM802(x) SETUP_XfOrM800(x)
          FUNCCALL(SETUP_XfOrM802(_), scheme_pop_kill_action () ); 
          FUNCCALL(SETUP_XfOrM802(_), closedir (dir ) ); 
          (((long * ) (void * ) ((* savebuf ) . gcvs ) ) [1 ] = (* savebuf ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* savebuf ) . gcvs , scheme_jit_longjmp ((* savebuf ) . jb , 1 ) ) ; 
        }
        else {
#         define XfOrM801_COUNT (0+XfOrM800_COUNT)
#         define SETUP_XfOrM801(x) SETUP_XfOrM800(x)
          ; 
          FUNCCALL(SETUP_XfOrM801(_), scheme_thread_block (0 ) ); 
          FUNCCALL_AGAIN(scheme_pop_kill_action () ); 
          scheme_current_thread -> error_buf = savebuf ; 
        }
      }
      ; 
      scheme_current_thread -> ran_some = 1 ; 
    }
  }
  FUNCCALL(SETUP_XfOrM792(_), closedir (dir ) ); 
  RET_VALUE_START (first ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * directory_list (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_directory_list (1 , argc , argv ) ; 
}
char * scheme_find_completion (char * fn ) {
  int len ; 
  Scheme_Object * p , * l , * a [2 ] , * f , * matches , * fst ; 
  int isdir , max_match ; 
  Scheme_Object * base ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK(11);
  BLOCK_SETUP_TOP((PUSH(f, 0), PUSH(fst, 1), PUSHARRAY(a, 2, 2), PUSH(base, 5), PUSH(matches, 6), PUSH(fn, 7), PUSH(p, 8), PUSH(l, 9)));
# define XfOrM808_COUNT (10)
# define SETUP_XfOrM808(x) SETUP(XfOrM808_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  p = NULLED_OUT ; 
  l = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  f = NULLED_OUT ; 
  matches = NULLED_OUT ; 
  fst = NULLED_OUT ; 
  base = NULLED_OUT ; 
  len = strlen (fn ) ; 
  if (! len )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  f = FUNCCALL(SETUP_XfOrM808(_), scheme_split_path (fn , len , & base , & isdir , scheme_unix_path_type ) ); 
  if (isdir ) {
#   define XfOrM827_COUNT (0+XfOrM808_COUNT)
#   define SETUP_XfOrM827(x) SETUP_XfOrM808(x)
    base = FUNCCALL(SETUP_XfOrM827(_), scheme_make_sized_path (fn , len , 0 ) ); 
    f = FUNCCALL(SETUP_XfOrM827(_), scheme_make_sized_path ("" , 0 , 0 ) ); 
  }
  else {
    if (! ((Scheme_Type ) (((((long ) (base ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (base ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) )
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  a [0 ] = base ; 
  l = FUNCCALL(SETUP_XfOrM808(_), do_directory_list (0 , 1 , a ) ); 
  if (! l )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  matches = scheme_null ; 
  while (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#   define XfOrM824_COUNT (0+XfOrM808_COUNT)
#   define SETUP_XfOrM824(x) SETUP_XfOrM808(x)
    p = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
    if (((((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . tag_val ) >= (((Scheme_Simple_Object * ) (f ) ) -> u . byte_str_val . tag_val ) ) && ! (memcmp ((((Scheme_Simple_Object * ) (f ) ) -> u . byte_str_val . string_val ) , (((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . string_val ) , (((Scheme_Simple_Object * ) (f ) ) -> u . byte_str_val . tag_val ) ) ) ) {
#     define XfOrM825_COUNT (0+XfOrM824_COUNT)
#     define SETUP_XfOrM825(x) SETUP_XfOrM824(x)
      matches = FUNCCALL(SETUP_XfOrM825(_), scheme_make_pair (p , matches ) ); 
    }
    l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
  }
  if (((matches ) == (scheme_null ) ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  if ((((((Scheme_Simple_Object * ) (matches ) ) -> u . pair_val . cdr ) ) == (scheme_null ) ) ) {
#   define XfOrM819_COUNT (0+XfOrM808_COUNT)
#   define SETUP_XfOrM819(x) SETUP_XfOrM808(x)
    a [0 ] = base ; 
    a [1 ] = (((Scheme_Simple_Object * ) (matches ) ) -> u . pair_val . car ) ; 
    p = FUNCCALL(SETUP_XfOrM819(_), scheme_build_path (2 , a ) ); 
    a [0 ] = p ; 
    if ((! (((FUNCCALL(SETUP_XfOrM819(_), directory_exists (1 , a ) )) ) == (scheme_false ) ) ) ) {
#     define XfOrM820_COUNT (0+XfOrM819_COUNT)
#     define SETUP_XfOrM820(x) SETUP_XfOrM819(x)
      fn = (((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . string_val ) ; 
      len = (((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . tag_val ) ; 
      if (! ((scheme_unix_path_type == scheme_unix_path_type ) ? ((fn [len - 1 ] ) == '/' ) : (((fn [len - 1 ] ) == '/' ) || ((fn [len - 1 ] ) == '\\' ) ) ) ) {
        char * naya ; 
        BLOCK_SETUP((PUSH(naya, 0+XfOrM820_COUNT)));
#       define XfOrM821_COUNT (1+XfOrM820_COUNT)
#       define SETUP_XfOrM821(x) SETUP(XfOrM821_COUNT)
        naya = NULLED_OUT ; 
        naya = (char * ) FUNCCALL(SETUP_XfOrM821(_), GC_malloc_atomic (len + 2 ) ); 
        (memcpy (naya , fn , len ) ) ; 
        naya [len ++ ] = ((scheme_unix_path_type == scheme_unix_path_type ) ? '/' : '\\' ) ; 
        naya [len ] = 0 ; 
        fn = naya ; 
      }
    }
    else fn = (((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . string_val ) ; 
    RET_VALUE_START (fn ) RET_VALUE_END ; 
  }
  fst = (((Scheme_Simple_Object * ) (matches ) ) -> u . pair_val . car ) ; 
  max_match = (((Scheme_Simple_Object * ) (fst ) ) -> u . byte_str_val . tag_val ) ; 
  for (l = (((Scheme_Simple_Object * ) (matches ) ) -> u . pair_val . cdr ) ; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
    int i , l2 ; 
    p = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
    l2 = (((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . tag_val ) ; 
    if (max_match < l2 )
      l2 = max_match ; 
    else if (l2 < max_match )
      max_match = l2 ; 
    for (i = 0 ; i < l2 ; i ++ ) {
      if ((((Scheme_Simple_Object * ) (fst ) ) -> u . byte_str_val . string_val ) [i ] != (((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . string_val ) [i ] ) {
        max_match = i ; 
        break ; 
      }
    }
  }
  if (max_match <= (((Scheme_Simple_Object * ) (f ) ) -> u . byte_str_val . tag_val ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  a [0 ] = base ; 
  a [1 ] = FUNCCALL(SETUP_XfOrM808(_), scheme_make_sized_path ((((Scheme_Simple_Object * ) (fst ) ) -> u . byte_str_val . string_val ) , max_match , 0 ) ); 
  f = FUNCCALL(SETUP_XfOrM808(_), scheme_build_path (2 , a ) ); 
  RET_VALUE_START ((((Scheme_Simple_Object * ) (f ) ) -> u . byte_str_val . string_val ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * explode_path (Scheme_Object * p ) {
  Scheme_Object * l = scheme_null , * base , * name ; 
  int isdir ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(base, 0), PUSH(p, 1), PUSH(l, 2), PUSH(name, 3)));
# define XfOrM828_COUNT (4)
# define SETUP_XfOrM828(x) SETUP(XfOrM828_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  base = NULLED_OUT ; 
  name = NULLED_OUT ; 
  while (1 ) {
#   define XfOrM831_COUNT (0+XfOrM828_COUNT)
#   define SETUP_XfOrM831(x) SETUP_XfOrM828(x)
    name = FUNCCALL(SETUP_XfOrM831(_), scheme_split_path ((((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . string_val ) , (((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . tag_val ) , & base , & isdir , ((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) ); 
    l = FUNCCALL(SETUP_XfOrM831(_), scheme_make_pair (name , l ) ); 
    if (! ((Scheme_Type ) (((((long ) (base ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (base ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) {
#     define XfOrM832_COUNT (0+XfOrM831_COUNT)
#     define SETUP_XfOrM832(x) SETUP_XfOrM831(x)
      l = FUNCCALL(SETUP_XfOrM832(_), scheme_make_pair (base , l ) ); 
      RET_VALUE_START (l ) RET_VALUE_END ; 
    }
    p = base ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_extract_relative_to (Scheme_Object * obj , Scheme_Object * dir ) {
  Scheme_Object * de , * oe ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(oe, 0), PUSH(de, 1), PUSH(obj, 2)));
# define XfOrM833_COUNT (3)
# define SETUP_XfOrM833(x) SETUP(XfOrM833_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  de = NULLED_OUT ; 
  oe = NULLED_OUT ; 
  de = FUNCCALL(SETUP_XfOrM833(_), explode_path (dir ) ); 
  oe = FUNCCALL_AGAIN(explode_path (obj ) ); 
  while (((Scheme_Type ) (((((long ) (de ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (de ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) (oe ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (oe ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#   define XfOrM840_COUNT (0+XfOrM833_COUNT)
#   define SETUP_XfOrM840(x) SETUP_XfOrM833(x)
    if (! FUNCCALL(SETUP_XfOrM840(_), scheme_equal ((((Scheme_Simple_Object * ) (de ) ) -> u . pair_val . car ) , (((Scheme_Simple_Object * ) (oe ) ) -> u . pair_val . car ) ) ))
      RET_VALUE_START (obj ) RET_VALUE_END ; 
    de = (((Scheme_Simple_Object * ) (de ) ) -> u . pair_val . cdr ) ; 
    oe = (((Scheme_Simple_Object * ) (oe ) ) -> u . pair_val . cdr ) ; 
  }
  if (((de ) == (scheme_null ) ) ) {
    Scheme_Object * a [2 ] ; 
    BLOCK_SETUP((PUSHARRAY(a, 2, 0+XfOrM833_COUNT)));
#   define XfOrM834_COUNT (3+XfOrM833_COUNT)
#   define SETUP_XfOrM834(x) SETUP(XfOrM834_COUNT)
    a[0] = NULLED_OUT ; 
    a[1] = NULLED_OUT ; 
    if (((oe ) == (scheme_null ) ) ) {
#     define XfOrM838_COUNT (0+XfOrM834_COUNT)
#     define SETUP_XfOrM838(x) SETUP_XfOrM834(x)
      a [0 ] = same_symbol ; 
      obj = FUNCCALL(SETUP_XfOrM838(_), scheme_build_path (1 , a ) ); 
    }
    else {
      obj = (((Scheme_Simple_Object * ) (oe ) ) -> u . pair_val . car ) ; 
      oe = (((Scheme_Simple_Object * ) (oe ) ) -> u . pair_val . cdr ) ; 
    }
    while (((Scheme_Type ) (((((long ) (oe ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (oe ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#     define XfOrM836_COUNT (0+XfOrM834_COUNT)
#     define SETUP_XfOrM836(x) SETUP_XfOrM834(x)
      a [0 ] = obj ; 
      a [1 ] = (((Scheme_Simple_Object * ) (oe ) ) -> u . pair_val . car ) ; 
      obj = FUNCCALL(SETUP_XfOrM836(_), scheme_build_path (2 , a ) ); 
      oe = (((Scheme_Simple_Object * ) (oe ) ) -> u . pair_val . cdr ) ; 
    }
  }
  RET_VALUE_START (obj ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * filesystem_root_list (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * first = scheme_null ; 
  Scheme_Object * __funcarg71 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(first, 0)));
# define XfOrM841_COUNT (1)
# define SETUP_XfOrM841(x) SETUP(XfOrM841_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM841(_), scheme_security_check_file ("filesystem-root-list" , ((void * ) 0 ) , 0x10 ) ); 
  first = (__funcarg71 = FUNCCALL(SETUP_XfOrM841(_), scheme_make_path ("/" ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg71 , scheme_null ) )) ; 
  RET_VALUE_START (first ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_directory (int argc , Scheme_Object * argv [] ) {
  char * filename ; 
  int exists_already = 0 ; 
  int len , copied ; 
  char * __funcarg72 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(filename, 1)));
# define XfOrM842_COUNT (2)
# define SETUP_XfOrM842(x) SETUP(XfOrM842_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  filename = NULLED_OUT ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("make-directory" , "path or string" , 0 , argc , argv ) ); 
  filename = FUNCCALL(SETUP_XfOrM842(_), scheme_expand_string_filename (argv [0 ] , "make-directory" , & copied , 0x2 ) ); 
  len = strlen (filename ) ; 
  while (len && ((scheme_unix_path_type == scheme_unix_path_type ) ? ((filename [len - 1 ] ) == '/' ) : (((filename [len - 1 ] ) == '/' ) || ((filename [len - 1 ] ) == '\\' ) ) ) ) {
#   define XfOrM847_COUNT (0+XfOrM842_COUNT)
#   define SETUP_XfOrM847(x) SETUP_XfOrM842(x)
    if (! copied ) {
#     define XfOrM848_COUNT (0+XfOrM847_COUNT)
#     define SETUP_XfOrM848(x) SETUP_XfOrM847(x)
      filename = FUNCCALL(SETUP_XfOrM848(_), scheme_strdup (filename ) ); 
      copied = 1 ; 
    }
    filename [-- len ] = 0 ; 
  }
  while (1 ) {
#   define XfOrM844_COUNT (0+XfOrM842_COUNT)
#   define SETUP_XfOrM844(x) SETUP_XfOrM842(x)
    if (! FUNCCALL(SETUP_XfOrM844(_), mkdir (filename , 511 ) ))
      RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
    else if ((* __errno_location () ) != 4 )
      break ; 
  }
  exists_already = ((* __errno_location () ) == 17 ) ; 
  (__funcarg72 = FUNCCALL_EMPTY(filename_for_error (argv [0 ] ) ), FUNCCALL_EMPTY(scheme_raise_exn (exists_already ? MZEXN_FAIL_FILESYSTEM_EXISTS : MZEXN_FAIL_FILESYSTEM , "make-directory: cannot make directory: %q (" "%e" ")" , __funcarg72 , (* __errno_location () ) ) )) ; 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * delete_directory (int argc , Scheme_Object * argv [] ) {
  char * filename ; 
  char * __funcarg73 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(filename, 1)));
# define XfOrM849_COUNT (2)
# define SETUP_XfOrM849(x) SETUP(XfOrM849_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  filename = NULLED_OUT ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("delete-directory" , "path or string" , 0 , argc , argv ) ); 
  filename = FUNCCALL(SETUP_XfOrM849(_), scheme_expand_string_filename (argv [0 ] , "delete-directory" , ((void * ) 0 ) , 0x8 ) ); 
  while (1 ) {
#   define XfOrM851_COUNT (0+XfOrM849_COUNT)
#   define SETUP_XfOrM851(x) SETUP_XfOrM849(x)
    if (! FUNCCALL(SETUP_XfOrM851(_), rmdir (filename ) ))
      RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
    else if ((* __errno_location () ) != 4 )
      break ; 
  }
  (__funcarg73 = FUNCCALL_EMPTY(filename_for_error (argv [0 ] ) ), FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_FILESYSTEM , "delete-directory: cannot delete directory: %q (%e)" , __funcarg73 , (* __errno_location () ) ) )) ; 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_link (int argc , Scheme_Object * argv [] ) {
  char * src ; 
  Scheme_Object * dest ; 
  int copied ; 
  char * __funcarg74 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(src, 0), PUSH(argv, 1), PUSH(dest, 2)));
# define XfOrM852_COUNT (3)
# define SETUP_XfOrM852(x) SETUP(XfOrM852_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  src = NULLED_OUT ; 
  dest = NULLED_OUT ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("make-file-or-directory-link" , "path or string" , 0 , argc , argv ) ); 
  if (! (((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("make-file-or-directory-link" , "path or string" , 0 , argc , argv ) ); 
  dest = argv [0 ] ; 
  dest = (((((((long ) (dest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (dest ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (dest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (dest ) ) -> type ) <= scheme_windows_path_type ) ) ? dest : FUNCCALL(SETUP_XfOrM852(_), scheme_char_string_to_path (dest ) )) ; 
  if (FUNCCALL(SETUP_XfOrM852(_), has_null ((((Scheme_Simple_Object * ) (dest ) ) -> u . byte_str_val . string_val ) , (((Scheme_Simple_Object * ) (dest ) ) -> u . byte_str_val . tag_val ) ) )) {
#   define XfOrM855_COUNT (0+XfOrM852_COUNT)
#   define SETUP_XfOrM855(x) SETUP_XfOrM852(x)
    FUNCCALL(SETUP_XfOrM855(_), raise_null_error ("make-file-or-directory-link" , dest , "" ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  src = FUNCCALL(SETUP_XfOrM852(_), scheme_expand_string_filename (argv [1 ] , "make-file-or-directory-link" , & copied , 0x2 ) ); 
  FUNCCALL(SETUP_XfOrM852(_), scheme_security_check_file_link ("make-file-or-directory-link" , src , (((Scheme_Simple_Object * ) (dest ) ) -> u . byte_str_val . string_val ) ) ); 
  while (1 ) {
#   define XfOrM854_COUNT (0+XfOrM852_COUNT)
#   define SETUP_XfOrM854(x) SETUP_XfOrM852(x)
    if (! FUNCCALL(SETUP_XfOrM854(_), symlink ((((Scheme_Simple_Object * ) (dest ) ) -> u . byte_str_val . string_val ) , src ) ))
      RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
    else if ((* __errno_location () ) != 4 )
      break ; 
  }
  (__funcarg74 = FUNCCALL_EMPTY(filename_for_error (argv [1 ] ) ), FUNCCALL_EMPTY(scheme_raise_exn (((* __errno_location () ) == 17 ) ? MZEXN_FAIL_FILESYSTEM_EXISTS : MZEXN_FAIL_FILESYSTEM , "make-file-or-directory-link: cannot make link: %q (%e)" , __funcarg74 , (* __errno_location () ) ) )) ; 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * file_modify_seconds (int argc , Scheme_Object * * argv ) {
  char * file ; 
  int set_time = 0 ; 
  long mtime ; 
  struct stat buf ; 
  char * __funcarg76 = NULLED_OUT ; 
  char * __funcarg75 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(file, 1)));
# define XfOrM856_COUNT (2)
# define SETUP_XfOrM856(x) SETUP(XfOrM856_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  file = NULLED_OUT ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("file-or-directory-modify-seconds" , "path or string" , 0 , argc , argv ) ); 
  set_time = ((argc > 1 ) && (! (((argv [1 ] ) ) == (scheme_false ) ) ) ) ; 
  file = FUNCCALL(SETUP_XfOrM856(_), scheme_expand_string_filename (argv [0 ] , "file-or-directory-modify-seconds" , ((void * ) 0 ) , (set_time ? 0x2 : 0x1 ) ) ); 
  if (set_time ) {
#   define XfOrM866_COUNT (0+XfOrM856_COUNT)
#   define SETUP_XfOrM866(x) SETUP_XfOrM856(x)
    if (! (((long ) (argv [1 ] ) ) & 0x1 ) && ! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) {
#     define XfOrM868_COUNT (0+XfOrM866_COUNT)
#     define SETUP_XfOrM868(x) SETUP_XfOrM866(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("file-or-directory-modify-seconds" , "exact integer or #f" , 1 , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    if (! (scheme_get_int_val (argv [1 ] , & mtime ) ) ) {
#     define XfOrM867_COUNT (0+XfOrM866_COUNT)
#     define SETUP_XfOrM867(x) SETUP_XfOrM866(x)
      (__funcarg76 = FUNCCALL(SETUP_XfOrM867(_), scheme_make_provided_string (argv [1 ] , 0 , ((void * ) 0 ) ) ), FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "file-or-directory-modify-seconds: integer %s is out-of-range" , __funcarg76 ) )) ; 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  else mtime = 0 ; 
  if (argc > 2 ) {
#   define XfOrM865_COUNT (0+XfOrM856_COUNT)
#   define SETUP_XfOrM865(x) SETUP_XfOrM856(x)
    FUNCCALL(SETUP_XfOrM865(_), scheme_check_proc_arity ("file-or-directory-modify-seconds" , 0 , 2 , argc , argv ) ); 
  }
  {
#   define XfOrM858_COUNT (0+XfOrM856_COUNT)
#   define SETUP_XfOrM858(x) SETUP_XfOrM856(x)
    while (1 ) {
#     define XfOrM862_COUNT (0+XfOrM858_COUNT)
#     define SETUP_XfOrM862(x) SETUP_XfOrM858(x)
      if (set_time ) {
        struct utimbuf ut ; 
#       define XfOrM864_COUNT (0+XfOrM862_COUNT)
#       define SETUP_XfOrM864(x) SETUP_XfOrM862(x)
        ut . actime = mtime ; 
        ut . modtime = mtime ; 
        if (! FUNCCALL(SETUP_XfOrM864(_), utime (file , & ut ) ))
          RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
      }
      else {
#       define XfOrM863_COUNT (0+XfOrM862_COUNT)
#       define SETUP_XfOrM863(x) SETUP_XfOrM862(x)
        if (! FUNCCALL(SETUP_XfOrM863(_), stat (file , & buf ) ))
          RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_integer_value ((long ) buf . st_mtim . tv_sec ) )) RET_VALUE_EMPTY_END ; 
      }
      if ((* __errno_location () ) != 4 )
        break ; 
    }
  }
  if (argc > 2 ) {
#   define XfOrM857_COUNT (0+XfOrM856_COUNT)
#   define SETUP_XfOrM857(x) SETUP_XfOrM856(x)
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_tail_apply (argv [2 ] , 0 , ((void * ) 0 ) ) )) RET_VALUE_EMPTY_END ; 
  }
  (__funcarg75 = FUNCCALL_EMPTY(filename_for_error (argv [0 ] ) ), FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_FILESYSTEM , "file-or-directory-modify-seconds: error %s file/directory time: %q (%e)" , set_time ? "setting" : "getting" , __funcarg75 , (* __errno_location () ) ) )) ; 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
typedef struct {
  gid_t gid ; 
  char set , in ; 
}
Group_Mem_Cache ; 
static Group_Mem_Cache group_mem_cache [10 ] ; 
static int user_in_group (uid_t uid , gid_t gid ) {
  struct group * g ; 
  struct passwd * pw ; 
  int i , in ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(g, 0), PUSH(pw, 1)));
# define XfOrM869_COUNT (2)
# define SETUP_XfOrM869(x) SETUP(XfOrM869_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  g = NULLED_OUT ; 
  pw = NULLED_OUT ; 
  for (i = 0 ; i < 10 ; i ++ ) {
    if (group_mem_cache [i ] . set && (group_mem_cache [i ] . gid == gid ) )
      RET_VALUE_START (group_mem_cache [i ] . in ) RET_VALUE_END ; 
  }
  pw = FUNCCALL(SETUP_XfOrM869(_), getpwuid (uid ) ); 
  if (! pw )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  g = FUNCCALL(SETUP_XfOrM869(_), getgrgid (gid ) ); 
  if (! g )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  for (i = 0 ; g -> gr_mem [i ] ; i ++ ) {
#   define XfOrM875_COUNT (0+XfOrM869_COUNT)
#   define SETUP_XfOrM875(x) SETUP_XfOrM869(x)
    if (! (strcmp (g -> gr_mem [i ] , pw -> pw_name ) ) )
      break ; 
  }
  in = ! ! (g -> gr_mem [i ] ) ; 
  for (i = 0 ; i < 10 ; i ++ ) {
    if (! group_mem_cache [i ] . set ) {
      group_mem_cache [i ] . set = 1 ; 
      group_mem_cache [i ] . gid = gid ; 
      group_mem_cache [i ] . in = in ; 
    }
  }
  RET_VALUE_START (in ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int have_user_ids = 0 ; 
static uid_t uid , euid ; 
static gid_t gid , egid ; 
static Scheme_Object * file_or_dir_permissions (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * l = scheme_null ; 
  char * filename ; 
  char * __funcarg78 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(l, 1), PUSH(filename, 2)));
# define XfOrM878_COUNT (3)
# define SETUP_XfOrM878(x) SETUP(XfOrM878_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  filename = NULLED_OUT ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("file-or-directory-permissions" , "path or string" , 0 , argc , argv ) ); 
  filename = FUNCCALL(SETUP_XfOrM878(_), scheme_expand_string_filename (argv [0 ] , "file-or-directory-permissions" , ((void * ) 0 ) , 0x1 ) ); 
  if (have_user_ids == 0 ) {
#   define XfOrM897_COUNT (0+XfOrM878_COUNT)
#   define SETUP_XfOrM897(x) SETUP_XfOrM878(x)
    have_user_ids = 1 ; 
    uid = FUNCCALL(SETUP_XfOrM897(_), getuid () ); 
    gid = FUNCCALL_AGAIN(getgid () ); 
    euid = FUNCCALL_AGAIN(geteuid () ); 
    egid = FUNCCALL_AGAIN(getegid () ); 
  }
  if ((uid == euid ) && (gid == egid ) ) {
    int read , write , execute , ok ; 
#   define XfOrM886_COUNT (0+XfOrM878_COUNT)
#   define SETUP_XfOrM886(x) SETUP_XfOrM878(x)
    do {
#     define XfOrM896_COUNT (0+XfOrM886_COUNT)
#     define SETUP_XfOrM896(x) SETUP_XfOrM886(x)
      ok = FUNCCALL(SETUP_XfOrM896(_), access (filename , 4 ) ); 
    }
    while ((ok == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
    read = ! ok ; 
    if (ok && ((* __errno_location () ) != 13 ) )
      l = ((void * ) 0 ) ; 
    else {
#     define XfOrM887_COUNT (0+XfOrM886_COUNT)
#     define SETUP_XfOrM887(x) SETUP_XfOrM886(x)
      do {
#       define XfOrM894_COUNT (0+XfOrM887_COUNT)
#       define SETUP_XfOrM894(x) SETUP_XfOrM887(x)
        ok = FUNCCALL(SETUP_XfOrM894(_), access (filename , 2 ) ); 
      }
      while ((ok == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
      write = ! ok ; 
      if (ok && ((* __errno_location () ) != 13 ) )
        l = ((void * ) 0 ) ; 
      else {
#       define XfOrM888_COUNT (0+XfOrM887_COUNT)
#       define SETUP_XfOrM888(x) SETUP_XfOrM887(x)
        do {
#         define XfOrM892_COUNT (0+XfOrM888_COUNT)
#         define SETUP_XfOrM892(x) SETUP_XfOrM888(x)
          ok = FUNCCALL(SETUP_XfOrM892(_), access (filename , 1 ) ); 
        }
        while ((ok == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
        execute = ! ok ; 
        if (ok && ((* __errno_location () ) != 13 ) && (uid || gid || ((* __errno_location () ) != 1 ) ) ) {
          l = ((void * ) 0 ) ; 
        }
        else {
#         define XfOrM889_COUNT (0+XfOrM888_COUNT)
#         define SETUP_XfOrM889(x) SETUP_XfOrM888(x)
          if (read )
            l = FUNCCALL(SETUP_XfOrM889(_), scheme_make_pair (read_symbol , l ) ); 
          if (write )
            l = FUNCCALL(SETUP_XfOrM889(_), scheme_make_pair (write_symbol , l ) ); 
          if (execute )
            l = FUNCCALL(SETUP_XfOrM889(_), scheme_make_pair (execute_symbol , l ) ); 
        }
      }
    }
  }
  else {
    struct stat buf ; 
    int read , write , execute ; 
#   define XfOrM880_COUNT (0+XfOrM878_COUNT)
#   define SETUP_XfOrM880(x) SETUP_XfOrM878(x)
    if (FUNCCALL(SETUP_XfOrM880(_), stat (filename , & buf ) ))
      l = ((void * ) 0 ) ; 
    else {
#     define XfOrM881_COUNT (0+XfOrM880_COUNT)
#     define SETUP_XfOrM881(x) SETUP_XfOrM880(x)
      if (euid == 0 ) {
        read = 1 ; 
        write = 1 ; 
        execute = ! ! (buf . st_mode & (64 | (64 >> 3 ) | ((64 >> 3 ) >> 3 ) ) ) ; 
      }
      else if (buf . st_uid == euid ) {
        read = ! ! (buf . st_mode & 256 ) ; 
        write = ! ! (buf . st_mode & 128 ) ; 
        execute = ! ! (buf . st_mode & 64 ) ; 
      }
      else if ((egid == buf . st_gid ) || FUNCCALL(SETUP_XfOrM881(_), user_in_group (euid , buf . st_gid ) )) {
        read = ! ! (buf . st_mode & (256 >> 3 ) ) ; 
        write = ! ! (buf . st_mode & (128 >> 3 ) ) ; 
        execute = ! ! (buf . st_mode & (64 >> 3 ) ) ; 
      }
      else {
        read = ! ! (buf . st_mode & ((256 >> 3 ) >> 3 ) ) ; 
        write = ! ! (buf . st_mode & ((128 >> 3 ) >> 3 ) ) ; 
        execute = ! ! (buf . st_mode & ((64 >> 3 ) >> 3 ) ) ; 
      }
      if (read )
        l = FUNCCALL(SETUP_XfOrM881(_), scheme_make_pair (read_symbol , l ) ); 
      if (write )
        l = FUNCCALL(SETUP_XfOrM881(_), scheme_make_pair (write_symbol , l ) ); 
      if (execute )
        l = FUNCCALL(SETUP_XfOrM881(_), scheme_make_pair (execute_symbol , l ) ); 
    }
  }
  if (! l ) {
#   define XfOrM879_COUNT (0+XfOrM878_COUNT)
#   define SETUP_XfOrM879(x) SETUP_XfOrM878(x)
    (__funcarg78 = FUNCCALL(SETUP_XfOrM879(_), filename_for_error (argv [0 ] ) ), FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_FILESYSTEM , "file-or-directory-permissions: file or directory not found: \"%q\"" , __funcarg78 ) )) ; 
  }
  RET_VALUE_START (l ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * file_size (int argc , Scheme_Object * argv [] ) {
  char * filename ; 
  mzlonglong len = 0 ; 
  char * __funcarg79 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(filename, 1)));
# define XfOrM898_COUNT (2)
# define SETUP_XfOrM898(x) SETUP(XfOrM898_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  filename = NULLED_OUT ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("file-size" , "path or string" , 0 , argc , argv ) ); 
  filename = FUNCCALL(SETUP_XfOrM898(_), scheme_expand_string_filename (argv [0 ] , "file-size" , ((void * ) 0 ) , 0x1 ) ); 
  {
    struct stat buf ; 
#   define XfOrM899_COUNT (0+XfOrM898_COUNT)
#   define SETUP_XfOrM899(x) SETUP_XfOrM898(x)
    while (1 ) {
#     define XfOrM901_COUNT (0+XfOrM899_COUNT)
#     define SETUP_XfOrM901(x) SETUP_XfOrM899(x)
      if (! FUNCCALL(SETUP_XfOrM901(_), stat (filename , & buf ) ))
        break ; 
      else if ((* __errno_location () ) != 4 )
        goto failed ; 
    }
    if (((((buf . st_mode ) ) & 61440 ) == (16384 ) ) )
      goto failed ; 
    len = buf . st_size ; 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_integer_value_from_long_long (len ) )) RET_VALUE_EMPTY_END ; 
  failed : (__funcarg79 = FUNCCALL_EMPTY(filename_for_error (argv [0 ] ) ), FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_FILESYSTEM , "file-size: file not found: \"%q\"" , __funcarg79 ) )) ; 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * cwd_check (int argc , Scheme_Object * * argv ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(2);
# define XfOrM902_COUNT (0)
# define SETUP_XfOrM902(x) SETUP(XfOrM902_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) ) {
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  else {
    char * expanded ; 
    Scheme_Object * ed ; 
    BLOCK_SETUP((PUSH(ed, 0+XfOrM902_COUNT), PUSH(expanded, 1+XfOrM902_COUNT)));
#   define XfOrM903_COUNT (2+XfOrM902_COUNT)
#   define SETUP_XfOrM903(x) SETUP(XfOrM903_COUNT)
    expanded = NULLED_OUT ; 
    ed = NULLED_OUT ; 
    expanded = FUNCCALL(SETUP_XfOrM903(_), scheme_expand_string_filename (argv [0 ] , "current-directory" , ((void * ) 0 ) , 0x10 ) ); 
    ed = FUNCCALL_AGAIN(scheme_make_sized_path (expanded , strlen (expanded ) , 1 ) ); 
    ed = FUNCCALL_AGAIN(do_simplify_path (ed , scheme_null , 0 , 1 , 0 , scheme_unix_path_type ) ); 
    ed = FUNCCALL_AGAIN(scheme_path_to_directory_path (ed ) ); 
    RET_VALUE_START (ed ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * current_directory (int argc , Scheme_Object * * argv ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM905_COUNT (1)
# define SETUP_XfOrM905(x) SETUP(XfOrM905_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! argc )
    FUNCCALL(SETUP_XfOrM905(_), scheme_security_check_file ("current-directory" , ((void * ) 0 ) , 0x10 ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_param_config ("current-directory" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_CURRENT_DIRECTORY ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , cwd_check , "complete path or string" , 1 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * collpaths_gen_p (int argc , Scheme_Object * * argv , int rel ) {
  Scheme_Object * v = argv [0 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(argv, 1)));
# define XfOrM906_COUNT (2)
# define SETUP_XfOrM906(x) SETUP(XfOrM906_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (FUNCCALL(SETUP_XfOrM906(_), scheme_proper_list_length (v ) )< 0 )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  if (((v ) == (scheme_null ) ) )
    RET_VALUE_START (v ) RET_VALUE_END ; 
  while (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
    Scheme_Object * s ; 
    BLOCK_SETUP((PUSH(s, 0+XfOrM906_COUNT)));
#   define XfOrM911_COUNT (1+XfOrM906_COUNT)
#   define SETUP_XfOrM911(x) SETUP(XfOrM911_COUNT)
    s = NULLED_OUT ; 
    s = (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) ; 
    if (! (((Scheme_Type ) (((((long ) (s ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (s ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (s ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (s ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) )
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    s = (((((((long ) (s ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (s ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (s ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (s ) ) -> type ) <= scheme_windows_path_type ) ) ? s : FUNCCALL(SETUP_XfOrM911(_), scheme_char_string_to_path (s ) )) ; 
    if (rel && ! FUNCCALL(SETUP_XfOrM911(_), scheme_is_relative_path ((((Scheme_Simple_Object * ) (s ) ) -> u . byte_str_val . string_val ) , (((Scheme_Simple_Object * ) (s ) ) -> u . byte_str_val . tag_val ) , scheme_unix_path_type ) ))
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    if (! rel && ! FUNCCALL(SETUP_XfOrM911(_), scheme_is_complete_path ((((Scheme_Simple_Object * ) (s ) ) -> u . byte_str_val . string_val ) , (((Scheme_Simple_Object * ) (s ) ) -> u . byte_str_val . tag_val ) , scheme_unix_path_type ) ))
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    v = (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) ; 
  }
  if (! ((v ) == (scheme_null ) ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  {
    Scheme_Object * last = ((void * ) 0 ) , * first = ((void * ) 0 ) , * p , * s ; 
    BLOCK_SETUP((PUSH(last, 0+XfOrM906_COUNT), PUSH(first, 1+XfOrM906_COUNT), PUSH(p, 2+XfOrM906_COUNT), PUSH(s, 3+XfOrM906_COUNT)));
#   define XfOrM907_COUNT (4+XfOrM906_COUNT)
#   define SETUP_XfOrM907(x) SETUP(XfOrM907_COUNT)
    p = NULLED_OUT ; 
    s = NULLED_OUT ; 
    v = argv [0 ] ; 
    while (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#     define XfOrM909_COUNT (0+XfOrM907_COUNT)
#     define SETUP_XfOrM909(x) SETUP_XfOrM907(x)
      s = (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) ; 
      s = (((((((long ) (s ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (s ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (s ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (s ) ) -> type ) <= scheme_windows_path_type ) ) ? s : FUNCCALL(SETUP_XfOrM909(_), scheme_char_string_to_path (s ) )) ; 
      p = FUNCCALL(SETUP_XfOrM909(_), scheme_make_pair (s , scheme_null ) ); 
      ((((Scheme_Inclhash_Object * ) (p ) ) -> so . keyex |= 0x1 ) ) ; 
      if (! first )
        first = p ; 
      else (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = p ; 
      last = p ; 
      v = (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) ; 
    }
    RET_VALUE_START (first ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * collpaths_p (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return collpaths_gen_p (argc , argv , 0 ) ; 
}
static Scheme_Object * current_library_collection_paths (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("current-library-collection-paths" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_COLLECTION_PATHS ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , collpaths_p , "list of complete paths and strings" , 1 ) ; 
}
static Scheme_Object * compiled_kind_p (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return collpaths_gen_p (argc , argv , 1 ) ; 
}
static Scheme_Object * use_compiled_kind (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("use-compiled-file-paths" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_USE_COMPILED_KIND ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , compiled_kind_p , "list of relative paths and strings" , 1 ) ; 
}
static Scheme_Object * use_user_paths (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("use-user-specific-search-paths" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_USE_USER_PATHS ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ; 
}
enum {
  id_temp_dir , id_home_dir , id_doc_dir , id_desk_dir , id_pref_dir , id_pref_file , id_init_dir , id_init_file , id_sys_dir , id_addon_dir }
; 
static Scheme_Object * find_system_path (int argc , Scheme_Object * * argv ) {
  int which ; 
  Scheme_Config * __funcarg84 = NULLED_OUT ; 
  char * __funcarg83 = NULLED_OUT ; 
  char * __funcarg82 = NULLED_OUT ; 
  Scheme_Object * __funcarg81 = NULLED_OUT ; 
  Scheme_Object * __funcarg80 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM917_COUNT (1)
# define SETUP_XfOrM917(x) SETUP(XfOrM917_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (argv [0 ] == temp_dir_symbol )
    which = id_temp_dir ; 
  else if (argv [0 ] == home_dir_symbol )
    which = id_home_dir ; 
  else if (argv [0 ] == doc_dir_symbol )
    which = id_doc_dir ; 
  else if (argv [0 ] == desk_dir_symbol )
    which = id_desk_dir ; 
  else if (argv [0 ] == pref_dir_symbol )
    which = id_pref_dir ; 
  else if (argv [0 ] == init_dir_symbol )
    which = id_init_dir ; 
  else if (argv [0 ] == pref_file_symbol )
    which = id_pref_file ; 
  else if (argv [0 ] == init_file_symbol )
    which = id_init_file ; 
  else if (argv [0 ] == sys_dir_symbol )
    which = id_sys_dir ; 
  else if (argv [0 ] == exec_file_symbol ) {
#   define XfOrM932_COUNT (0+XfOrM917_COUNT)
#   define SETUP_XfOrM932(x) SETUP_XfOrM917(x)
    if (! exec_cmd ) {
#     define XfOrM933_COUNT (0+XfOrM932_COUNT)
#     define SETUP_XfOrM933(x) SETUP_XfOrM932(x)
      FUNCCALL(SETUP_XfOrM933(_), scheme_register_static ((void * ) & exec_cmd , sizeof (exec_cmd ) ) ); 
      exec_cmd = FUNCCALL(SETUP_XfOrM933(_), scheme_make_path ("mzscheme" ) ); 
    }
    RET_VALUE_START (exec_cmd ) RET_VALUE_END ; 
  }
  else if (argv [0 ] == run_file_symbol ) {
#   define XfOrM930_COUNT (0+XfOrM917_COUNT)
#   define SETUP_XfOrM930(x) SETUP_XfOrM917(x)
    if (! run_cmd ) {
#     define XfOrM931_COUNT (0+XfOrM930_COUNT)
#     define SETUP_XfOrM931(x) SETUP_XfOrM930(x)
      FUNCCALL(SETUP_XfOrM931(_), scheme_register_static ((void * ) & run_cmd , sizeof (run_cmd ) ) ); 
      run_cmd = FUNCCALL(SETUP_XfOrM931(_), scheme_make_path ("mzscheme" ) ); 
    }
    RET_VALUE_START (run_cmd ) RET_VALUE_END ; 
  }
  else if (argv [0 ] == collects_dir_symbol ) {
#   define XfOrM928_COUNT (0+XfOrM917_COUNT)
#   define SETUP_XfOrM928(x) SETUP_XfOrM917(x)
    if (! collects_path ) {
#     define XfOrM929_COUNT (0+XfOrM928_COUNT)
#     define SETUP_XfOrM929(x) SETUP_XfOrM928(x)
      FUNCCALL(SETUP_XfOrM929(_), scheme_register_static ((void * ) & collects_path , sizeof (collects_path ) ) ); 
      collects_path = FUNCCALL(SETUP_XfOrM929(_), scheme_make_path ("collects" ) ); 
    }
    RET_VALUE_START (collects_path ) RET_VALUE_END ; 
  }
  else if (argv [0 ] == orig_dir_symbol ) {
    RET_VALUE_START (original_pwd ) RET_VALUE_END ; 
  }
  else if (argv [0 ] == addon_dir_symbol ) {
    which = id_addon_dir ; 
  }
  else {
#   define XfOrM925_COUNT (0+XfOrM917_COUNT)
#   define SETUP_XfOrM925(x) SETUP_XfOrM917(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("find-system-path" , "system-path-symbol" , 0 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  FUNCCALL(SETUP_XfOrM917(_), scheme_security_check_file ("find-system-path" , ((void * ) 0 ) , 0x10 ) ); 
  if (which == id_sys_dir ) {
#   define XfOrM924_COUNT (0+XfOrM917_COUNT)
#   define SETUP_XfOrM924(x) SETUP_XfOrM917(x)
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_path ("/" ) )) RET_VALUE_EMPTY_END ; 
  }
  if (which == id_temp_dir ) {
    char * p ; 
    BLOCK_SETUP((PUSH(p, 0+XfOrM917_COUNT)));
#   define XfOrM922_COUNT (1+XfOrM917_COUNT)
#   define SETUP_XfOrM922(x) SETUP(XfOrM922_COUNT)
    p = NULLED_OUT ; 
    if ((p = FUNCCALL(SETUP_XfOrM922(_), getenv ("TMPDIR" ) )) ) {
#     define XfOrM923_COUNT (0+XfOrM922_COUNT)
#     define SETUP_XfOrM923(x) SETUP_XfOrM922(x)
      p = FUNCCALL(SETUP_XfOrM923(_), scheme_expand_filename (p , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ); 
      if (p && FUNCCALL(SETUP_XfOrM923(_), scheme_directory_exists (p ) ))
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_path (p ) )) RET_VALUE_EMPTY_END ; 
    }
    if (FUNCCALL(SETUP_XfOrM922(_), scheme_directory_exists ("/usr/tmp" ) ))
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_path ("/usr/tmp" ) )) RET_VALUE_EMPTY_END ; 
    if (FUNCCALL(SETUP_XfOrM922(_), scheme_directory_exists ("/tmp" ) ))
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_path ("/tmp" ) )) RET_VALUE_EMPTY_END ; 
    RET_VALUE_START ((__funcarg84 = FUNCCALL(SETUP_XfOrM922(_), scheme_current_config () ), FUNCCALL_EMPTY(scheme_get_param (__funcarg84 , MZCONFIG_CURRENT_DIRECTORY ) )) ) RET_VALUE_END ; 
  }
  {
    Scheme_Object * home ; 
    int ends_in_slash ; 
    BLOCK_SETUP((PUSH(home, 0+XfOrM917_COUNT)));
#   define XfOrM918_COUNT (1+XfOrM917_COUNT)
#   define SETUP_XfOrM918(x) SETUP(XfOrM918_COUNT)
    home = NULLED_OUT ; 
    if ((which == id_pref_dir ) || (which == id_pref_file ) || (which == id_addon_dir ) ) {
#     define XfOrM921_COUNT (0+XfOrM918_COUNT)
#     define SETUP_XfOrM921(x) SETUP_XfOrM918(x)
      home = (__funcarg83 = FUNCCALL(SETUP_XfOrM921(_), scheme_expand_filename ("~/.plt-scheme/" , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ), FUNCCALL_AGAIN(scheme_make_path (__funcarg83 ) )) ; 
    }
    else {
#     define XfOrM920_COUNT (0+XfOrM918_COUNT)
#     define SETUP_XfOrM920(x) SETUP_XfOrM918(x)
      home = (__funcarg82 = FUNCCALL(SETUP_XfOrM920(_), scheme_expand_filename ("~/" , 2 , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ), FUNCCALL_AGAIN(scheme_make_path (__funcarg82 ) )) ; 
    }
    if ((which == id_pref_dir ) || (which == id_init_dir ) || (which == id_home_dir ) || (which == id_addon_dir ) || (which == id_desk_dir ) || (which == id_doc_dir ) )
      RET_VALUE_START (home ) RET_VALUE_END ; 
    ends_in_slash = ((((Scheme_Simple_Object * ) (home ) ) -> u . byte_str_val . string_val ) ) [(((Scheme_Simple_Object * ) (home ) ) -> u . byte_str_val . tag_val ) - 1 ] == '/' ; 
    if (which == id_init_file )
      RET_VALUE_START ((__funcarg81 = FUNCCALL(SETUP_XfOrM918(_), scheme_make_path ("/.mzschemerc" + ends_in_slash ) ), FUNCCALL_EMPTY(append_path (home , __funcarg81 ) )) ) RET_VALUE_END ; 
    if (which == id_pref_file ) {
#     define XfOrM919_COUNT (0+XfOrM918_COUNT)
#     define SETUP_XfOrM919(x) SETUP_XfOrM918(x)
      RET_VALUE_START ((__funcarg80 = FUNCCALL(SETUP_XfOrM919(_), scheme_make_path ("/plt-prefs.ss" + ends_in_slash ) ), FUNCCALL_EMPTY(append_path (home , __funcarg80 ) )) ) RET_VALUE_END ; 
    }
  }
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_set_exec_cmd (char * s ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(s, 0)));
# define XfOrM934_COUNT (1)
# define SETUP_XfOrM934(x) SETUP(XfOrM934_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! exec_cmd ) {
#   define XfOrM935_COUNT (0+XfOrM934_COUNT)
#   define SETUP_XfOrM935(x) SETUP_XfOrM934(x)
    FUNCCALL(SETUP_XfOrM935(_), scheme_register_static ((void * ) & exec_cmd , sizeof (exec_cmd ) ) ); 
    exec_cmd = FUNCCALL_EMPTY(scheme_make_path (s ) ); 
  }
  RET_VALUE_START (exec_cmd ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_set_run_cmd (char * s ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(s, 0)));
# define XfOrM936_COUNT (1)
# define SETUP_XfOrM936(x) SETUP(XfOrM936_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! run_cmd ) {
#   define XfOrM937_COUNT (0+XfOrM936_COUNT)
#   define SETUP_XfOrM937(x) SETUP_XfOrM936(x)
    FUNCCALL(SETUP_XfOrM937(_), scheme_register_static ((void * ) & run_cmd , sizeof (run_cmd ) ) ); 
    run_cmd = FUNCCALL_EMPTY(scheme_make_path (s ) ); 
  }
  RET_VALUE_START (run_cmd ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
char * scheme_get_exec_path (void ) {
  /* No conversion */
  if (exec_cmd )
    return (((Scheme_Simple_Object * ) (exec_cmd ) ) -> u . byte_str_val . string_val ) ; 
  else return ((void * ) 0 ) ; 
}
void scheme_set_collects_path (Scheme_Object * p ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(p, 0)));
# define XfOrM939_COUNT (1)
# define SETUP_XfOrM939(x) SETUP(XfOrM939_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM939(_), scheme_register_static ((void * ) & collects_path , sizeof (collects_path ) ) ); 
  collects_path = p ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_set_original_dir (Scheme_Object * d ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(d, 0)));
# define XfOrM940_COUNT (1)
# define SETUP_XfOrM940(x) SETUP(XfOrM940_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! original_pwd ) {
#   define XfOrM941_COUNT (0+XfOrM940_COUNT)
#   define SETUP_XfOrM941(x) SETUP_XfOrM940(x)
    FUNCCALL(SETUP_XfOrM941(_), scheme_register_static ((void * ) & original_pwd , sizeof (original_pwd ) ) ); 
  }
  original_pwd = d ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
