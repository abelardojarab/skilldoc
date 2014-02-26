#include "precomp.h"
enum {
  _ISupper = ((0 ) < 8 ? ((1 << (0 ) ) << 8 ) : ((1 << (0 ) ) >> 8 ) ) , _ISlower = ((1 ) < 8 ? ((1 << (1 ) ) << 8 ) : ((1 << (1 ) ) >> 8 ) ) , _ISalpha = ((2 ) < 8 ? ((1 << (2 ) ) << 8 ) : ((1 << (2 ) ) >> 8 ) ) , _ISdigit = ((3 ) < 8 ? ((1 << (3 ) ) << 8 ) : ((1 << (3 ) ) >> 8 ) ) , _ISxdigit = ((4 ) < 8 ? ((1 << (4 ) ) << 8 ) : ((1 << (4 ) ) >> 8 ) ) , _ISspace = ((5 ) < 8 ? ((1 << (5 ) ) << 8 ) : ((1 << (5 ) ) >> 8 ) ) , _ISprint = ((6 ) < 8 ? ((1 << (6 ) ) << 8 ) : ((1 << (6 ) ) >> 8 ) ) , _ISgraph = ((7 ) < 8 ? ((1 << (7 ) ) << 8 ) : ((1 << (7 ) ) >> 8 ) ) , _ISblank = ((8 ) < 8 ? ((1 << (8 ) ) << 8 ) : ((1 << (8 ) ) >> 8 ) ) , _IScntrl = ((9 ) < 8 ? ((1 << (9 ) ) << 8 ) : ((1 << (9 ) ) >> 8 ) ) , _ISpunct = ((10 ) < 8 ? ((1 << (10 ) ) << 8 ) : ((1 << (10 ) ) >> 8 ) ) , _ISalnum = ((11 ) < 8 ? ((1 << (11 ) ) << 8 ) : ((1 << (11 ) ) >> 8 ) ) }
; 
typedef __intptr_t intptr_t ; 
typedef __socklen_t socklen_t ; 
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
extern int * __errno_location (void ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__const__ ) ) ; 
typedef unsigned char uint8_t ; 
typedef unsigned short int uint16_t ; 
typedef unsigned int uint32_t ; 
struct iovec {
  void * iov_base ; 
  size_t iov_len ; 
}
; 
enum __socket_type {
  SOCK_STREAM = 1 , SOCK_DGRAM = 2 , SOCK_RAW = 3 , SOCK_RDM = 4 , SOCK_SEQPACKET = 5 , SOCK_PACKET = 10 }
; 
typedef unsigned short int sa_family_t ; 
struct sockaddr {
  sa_family_t sa_family ; 
  char sa_data [14 ] ; 
}
; 
struct sockaddr_storage {
  sa_family_t ss_family ; 
  __uint64_t __ss_align ; 
  char __ss_padding [(128 - (2 * sizeof (__uint64_t ) ) ) ] ; 
}
; 
enum {
  MSG_OOB = 0x01 , MSG_PEEK = 0x02 , MSG_DONTROUTE = 0x04 , MSG_CTRUNC = 0x08 , MSG_PROXY = 0x10 , MSG_TRUNC = 0x20 , MSG_DONTWAIT = 0x40 , MSG_EOR = 0x80 , MSG_WAITALL = 0x100 , MSG_FIN = 0x200 , MSG_SYN = 0x400 , MSG_CONFIRM = 0x800 , MSG_RST = 0x1000 , MSG_ERRQUEUE = 0x2000 , MSG_NOSIGNAL = 0x4000 , MSG_MORE = 0x8000 }
; 
struct msghdr {
  void * msg_name ; 
  socklen_t msg_namelen ; 
  struct iovec * msg_iov ; 
  size_t msg_iovlen ; 
  void * msg_control ; 
  size_t msg_controllen ; 
  int msg_flags ; 
}
; 
struct cmsghdr {
  size_t cmsg_len ; 
  int cmsg_level ; 
  int cmsg_type ; 
  __extension__ unsigned char __cmsg_data [] ; 
}
; 
enum {
  SCM_RIGHTS = 0x01 , SCM_CREDENTIALS = 0x02 }
; 
struct ucred {
  pid_t pid ; 
  uid_t uid ; 
  gid_t gid ; 
}
; 
struct linger {
  int l_onoff ; 
  int l_linger ; 
}
; 
struct osockaddr {
  unsigned short int sa_family ; 
  unsigned char sa_data [14 ] ; 
}
; 
enum {
  SHUT_RD = 0 , SHUT_WR , SHUT_RDWR }
; 
extern int socket (int __domain , int __type , int __protocol ) __attribute__ ((__nothrow__ ) ) ; 
extern int bind (int __fd , __const struct sockaddr * __addr , socklen_t __len ) __attribute__ ((__nothrow__ ) ) ; 
extern int getsockname (int __fd , struct sockaddr * __restrict __addr , socklen_t * __restrict __len ) __attribute__ ((__nothrow__ ) ) ; 
extern int connect (int __fd , __const struct sockaddr * __addr , socklen_t __len ) ; 
extern int getpeername (int __fd , struct sockaddr * __restrict __addr , socklen_t * __restrict __len ) __attribute__ ((__nothrow__ ) ) ; 
extern ssize_t send (int __fd , __const void * __buf , size_t __n , int __flags ) ; 
extern ssize_t recv (int __fd , void * __buf , size_t __n , int __flags ) ; 
extern ssize_t sendto (int __fd , __const void * __buf , size_t __n , int __flags , __const struct sockaddr * __addr , socklen_t __addr_len ) ; 
extern ssize_t recvfrom (int __fd , void * __restrict __buf , size_t __n , int __flags , struct sockaddr * __restrict __addr , socklen_t * __restrict __addr_len ) ; 
extern int getsockopt (int __fd , int __level , int __optname , void * __restrict __optval , socklen_t * __restrict __optlen ) __attribute__ ((__nothrow__ ) ) ; 
extern int setsockopt (int __fd , int __level , int __optname , __const void * __optval , socklen_t __optlen ) __attribute__ ((__nothrow__ ) ) ; 
extern int listen (int __fd , int __n ) __attribute__ ((__nothrow__ ) ) ; 
extern int accept (int __fd , struct sockaddr * __restrict __addr , socklen_t * __restrict __addr_len ) ; 
extern int shutdown (int __fd , int __how ) __attribute__ ((__nothrow__ ) ) ; 
enum {
  IPPROTO_IP = 0 , IPPROTO_HOPOPTS = 0 , IPPROTO_ICMP = 1 , IPPROTO_IGMP = 2 , IPPROTO_IPIP = 4 , IPPROTO_TCP = 6 , IPPROTO_EGP = 8 , IPPROTO_PUP = 12 , IPPROTO_UDP = 17 , IPPROTO_IDP = 22 , IPPROTO_TP = 29 , IPPROTO_IPV6 = 41 , IPPROTO_ROUTING = 43 , IPPROTO_FRAGMENT = 44 , IPPROTO_RSVP = 46 , IPPROTO_GRE = 47 , IPPROTO_ESP = 50 , IPPROTO_AH = 51 , IPPROTO_ICMPV6 = 58 , IPPROTO_NONE = 59 , IPPROTO_DSTOPTS = 60 , IPPROTO_MTP = 92 , IPPROTO_ENCAP = 98 , IPPROTO_PIM = 103 , IPPROTO_COMP = 108 , IPPROTO_SCTP = 132 , IPPROTO_RAW = 255 , IPPROTO_MAX }
; 
typedef uint16_t in_port_t ; 
enum {
  IPPORT_ECHO = 7 , IPPORT_DISCARD = 9 , IPPORT_SYSTAT = 11 , IPPORT_DAYTIME = 13 , IPPORT_NETSTAT = 15 , IPPORT_FTP = 21 , IPPORT_TELNET = 23 , IPPORT_SMTP = 25 , IPPORT_TIMESERVER = 37 , IPPORT_NAMESERVER = 42 , IPPORT_WHOIS = 43 , IPPORT_MTP = 57 , IPPORT_TFTP = 69 , IPPORT_RJE = 77 , IPPORT_FINGER = 79 , IPPORT_TTYLINK = 87 , IPPORT_SUPDUP = 95 , IPPORT_EXECSERVER = 512 , IPPORT_LOGINSERVER = 513 , IPPORT_CMDSERVER = 514 , IPPORT_EFSSERVER = 520 , IPPORT_BIFFUDP = 512 , IPPORT_WHOSERVER = 513 , IPPORT_ROUTESERVER = 520 , IPPORT_RESERVED = 1024 , IPPORT_USERRESERVED = 5000 }
; 
typedef uint32_t in_addr_t ; 
struct in_addr {
  in_addr_t s_addr ; 
}
; 
struct in6_addr {
  union {
    uint8_t u6_addr8 [16 ] ; 
    uint16_t u6_addr16 [8 ] ; 
    uint32_t u6_addr32 [4 ] ; 
  }
  in6_u ; 
}
; 
struct sockaddr_in {
  sa_family_t sin_family ; 
  in_port_t sin_port ; 
  struct in_addr sin_addr ; 
  unsigned char sin_zero [sizeof (struct sockaddr ) - (sizeof (unsigned short int ) ) - sizeof (in_port_t ) - sizeof (struct in_addr ) ] ; 
}
; 
struct sockaddr_in6 {
  sa_family_t sin6_family ; 
  in_port_t sin6_port ; 
  uint32_t sin6_flowinfo ; 
  struct in6_addr sin6_addr ; 
  uint32_t sin6_scope_id ; 
}
; 
struct ip_mreq {
  struct in_addr imr_multiaddr ; 
  struct in_addr imr_interface ; 
}
; 
struct ip_mreq_source {
  struct in_addr imr_multiaddr ; 
  struct in_addr imr_interface ; 
  struct in_addr imr_sourceaddr ; 
}
; 
struct ipv6_mreq {
  struct in6_addr ipv6mr_multiaddr ; 
  unsigned int ipv6mr_interface ; 
}
; 
struct group_req {
  uint32_t gr_interface ; 
  struct sockaddr_storage gr_group ; 
}
; 
struct group_source_req {
  uint32_t gsr_interface ; 
  struct sockaddr_storage gsr_group ; 
  struct sockaddr_storage gsr_source ; 
}
; 
struct ip_msfilter {
  struct in_addr imsf_multiaddr ; 
  struct in_addr imsf_interface ; 
  uint32_t imsf_fmode ; 
  uint32_t imsf_numsrc ; 
  struct in_addr imsf_slist [1 ] ; 
}
; 
struct group_filter {
  uint32_t gf_interface ; 
  struct sockaddr_storage gf_group ; 
  uint32_t gf_fmode ; 
  uint32_t gf_numsrc ; 
  struct sockaddr_storage gf_slist [1 ] ; 
}
; 
struct ip_opts {
  struct in_addr ip_dst ; 
  char ip_opts [40 ] ; 
}
; 
struct ip_mreqn {
  struct in_addr imr_multiaddr ; 
  struct in_addr imr_address ; 
  int imr_ifindex ; 
}
; 
struct in_pktinfo {
  int ipi_ifindex ; 
  struct in_addr ipi_spec_dst ; 
  struct in_addr ipi_addr ; 
}
; 
struct in6_pktinfo {
  struct in6_addr ipi6_addr ; 
  unsigned int ipi6_ifindex ; 
}
; 
struct rpcent {
  char * r_name ; 
  char * * r_aliases ; 
  int r_number ; 
}
; 
struct netent {
  char * n_name ; 
  char * * n_aliases ; 
  int n_addrtype ; 
  uint32_t n_net ; 
}
; 
struct hostent {
  char * h_name ; 
  char * * h_aliases ; 
  int h_addrtype ; 
  int h_length ; 
  char * * h_addr_list ; 
}
; 
struct servent {
  char * s_name ; 
  char * * s_aliases ; 
  int s_port ; 
  char * s_proto ; 
}
; 
struct protoent {
  char * p_name ; 
  char * * p_aliases ; 
  int p_proto ; 
}
; 
extern struct protoent * getprotobyname (__const char * __name ) ; 
struct addrinfo {
  int ai_flags ; 
  int ai_family ; 
  int ai_socktype ; 
  int ai_protocol ; 
  socklen_t ai_addrlen ; 
  struct sockaddr * ai_addr ; 
  char * ai_canonname ; 
  struct addrinfo * ai_next ; 
}
; 
extern int getaddrinfo (__const char * __restrict __name , __const char * __restrict __service , __const struct addrinfo * __restrict __req , struct addrinfo * * __restrict __pai ) ; 
extern void freeaddrinfo (struct addrinfo * __ai ) __attribute__ ((__nothrow__ ) ) ; 
extern __const char * gai_strerror (int __ecode ) __attribute__ ((__nothrow__ ) ) ; 
extern int getnameinfo (__const struct sockaddr * __restrict __sa , socklen_t __salen , char * __restrict __host , socklen_t __hostlen , char * __restrict __serv , socklen_t __servlen , unsigned int __flags ) ; 
struct flock {
  short int l_type ; 
  short int l_whence ; 
  __off_t l_start ; 
  __off_t l_len ; 
  __pid_t l_pid ; 
}
; 
extern int fcntl (int __fd , int __cmd , ... ) ; 
typedef long tcp_t ; 
static void closesocket (long s ) {
  /* No conversion */
  int cr ; 
  do {
    cr = close (s ) ; 
  }
  while ((cr == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
}
typedef struct {
  Scheme_Object so ; 
  Scheme_Custodian_Reference * mref ; 
  int count ; 
  tcp_t s [1 ] ; 
}
listener_t ; 
typedef struct Scheme_Tcp_Buf {
  Scheme_Type type ; 
  short refcount ; 
  char * buffer , * out_buffer ; 
  short bufpos , bufmax ; 
  short hiteof , bufmode ; 
  short out_bufpos , out_bufmax ; 
  short out_bufmode ; 
}
Scheme_Tcp_Buf ; 
typedef struct Scheme_Tcp {
  Scheme_Tcp_Buf b ; 
  tcp_t tcp ; 
  int flags ; 
}
Scheme_Tcp ; 
typedef struct Scheme_UDP {
  Scheme_Object so ; 
  short keyex ; 
  tcp_t s ; 
  char bound , connected ; 
  Scheme_Object * previous_from_addr ; 
  Scheme_Custodian_Reference * mref ; 
}
Scheme_UDP ; 
static Scheme_Object * tcp_connect (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * tcp_connect_break (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * tcp_listen (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * tcp_stop (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * tcp_accept_ready (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * tcp_accept (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * tcp_accept_evt (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * tcp_accept_break (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * tcp_listener_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * tcp_addresses (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * tcp_abandon_port (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * tcp_port_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * make_udp (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * udp_close (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * udp_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * udp_bound_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * udp_connected_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * udp_bind (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * udp_connect (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * udp_send_to (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * udp_send (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * udp_send_to_star (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * udp_send_star (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * udp_send_to_enable_break (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * udp_send_enable_break (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * udp_receive (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * udp_receive_star (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * udp_receive_enable_break (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * udp_read_ready_evt (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * udp_write_ready_evt (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * udp_read_evt (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * udp_write_evt (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * udp_write_to_evt (int argc , Scheme_Object * argv [] ) ; 
static int tcp_check_accept_evt (Scheme_Object * ae , Scheme_Schedule_Info * sinfo ) ; 
static void tcp_accept_evt_needs_wakeup (Scheme_Object * _ae , void * fds ) ; 
static int udp_evt_check_ready (Scheme_Object * uw , Scheme_Schedule_Info * sinfo ) ; 
static void udp_evt_needs_wakeup (Scheme_Object * _uw , void * fds ) ; 
static void register_tcp_listener_sync () ; 
static void register_traversers (void ) ; 
void scheme_init_network (Scheme_Env * env ) {
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
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(env, 0)));
# define XfOrM4_COUNT (1)
# define SETUP_XfOrM4(x) SETUP(XfOrM4_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM4(_), register_traversers () ); 
  (__funcarg37 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_everything (tcp_connect , 0 , "tcp-connect" , 2 , 4 , 0 , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("tcp-connect" , __funcarg37 , env ) )) ; 
  (__funcarg36 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_everything (tcp_connect_break , 0 , "tcp-connect/enable-break" , 2 , 4 , 0 , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("tcp-connect/enable-break" , __funcarg36 , env ) )) ; 
  (__funcarg35 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_arity (tcp_listen , "tcp-listen" , 1 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("tcp-listen" , __funcarg35 , env ) )) ; 
  (__funcarg34 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_arity (tcp_stop , "tcp-close" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("tcp-close" , __funcarg34 , env ) )) ; 
  (__funcarg33 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_arity (tcp_accept_ready , "tcp-accept-ready?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("tcp-accept-ready?" , __funcarg33 , env ) )) ; 
  (__funcarg32 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_everything (tcp_accept , 0 , "tcp-accept" , 1 , 1 , 0 , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("tcp-accept" , __funcarg32 , env ) )) ; 
  (__funcarg31 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_arity (tcp_accept_evt , "tcp-accept-evt" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("tcp-accept-evt" , __funcarg31 , env ) )) ; 
  (__funcarg30 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_everything (tcp_accept_break , 0 , "tcp-accept/enable-break" , 1 , 1 , 0 , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("tcp-accept/enable-break" , __funcarg30 , env ) )) ; 
  (__funcarg29 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_folding_prim (tcp_listener_p , "tcp-listener?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("tcp-listener?" , __funcarg29 , env ) )) ; 
  (__funcarg28 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_everything (tcp_addresses , 0 , "tcp-addresses" , 1 , 2 , 0 , 2 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("tcp-addresses" , __funcarg28 , env ) )) ; 
  (__funcarg27 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_arity (tcp_abandon_port , "tcp-abandon-port" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("tcp-abandon-port" , __funcarg27 , env ) )) ; 
  (__funcarg26 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_folding_prim (tcp_port_p , "tcp-port?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("tcp-port?" , __funcarg26 , env ) )) ; 
  (__funcarg25 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_arity (make_udp , "udp-open-socket" , 0 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("udp-open-socket" , __funcarg25 , env ) )) ; 
  (__funcarg24 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_arity (udp_close , "udp-close" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("udp-close" , __funcarg24 , env ) )) ; 
  (__funcarg23 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_folding_prim (udp_p , "udp?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("udp?" , __funcarg23 , env ) )) ; 
  (__funcarg22 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_arity (udp_bound_p , "udp-bound?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("udp-bound?" , __funcarg22 , env ) )) ; 
  (__funcarg21 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_arity (udp_connected_p , "udp-connected?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("udp-connected?" , __funcarg21 , env ) )) ; 
  (__funcarg20 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_arity (udp_bind , "udp-bind!" , 3 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("udp-bind!" , __funcarg20 , env ) )) ; 
  (__funcarg19 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_arity (udp_connect , "udp-connect!" , 3 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("udp-connect!" , __funcarg19 , env ) )) ; 
  (__funcarg18 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_arity (udp_send_to , "udp-send-to" , 4 , 6 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("udp-send-to" , __funcarg18 , env ) )) ; 
  (__funcarg17 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_arity (udp_send , "udp-send" , 2 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("udp-send" , __funcarg17 , env ) )) ; 
  (__funcarg16 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_arity (udp_send_to_star , "udp-send-to*" , 4 , 6 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("udp-send-to*" , __funcarg16 , env ) )) ; 
  (__funcarg15 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_arity (udp_send_star , "udp-send*" , 2 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("udp-send*" , __funcarg15 , env ) )) ; 
  (__funcarg14 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_arity (udp_send_to_enable_break , "udp-send-to/enable-break" , 4 , 6 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("udp-send-to/enable-break" , __funcarg14 , env ) )) ; 
  (__funcarg13 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_arity (udp_send_enable_break , "udp-send/enable-break" , 2 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("udp-send/enable-break" , __funcarg13 , env ) )) ; 
  (__funcarg12 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_arity (udp_receive , "udp-receive!" , 2 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("udp-receive!" , __funcarg12 , env ) )) ; 
  (__funcarg11 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_arity (udp_receive_star , "udp-receive!*" , 2 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("udp-receive!*" , __funcarg11 , env ) )) ; 
  (__funcarg10 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_arity (udp_receive_enable_break , "udp-receive!/enable-break" , 2 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("udp-receive!/enable-break" , __funcarg10 , env ) )) ; 
  (__funcarg9 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_arity (udp_read_ready_evt , "udp-receive-ready-evt" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("udp-receive-ready-evt" , __funcarg9 , env ) )) ; 
  (__funcarg8 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_arity (udp_write_ready_evt , "udp-send-ready-evt" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("udp-send-ready-evt" , __funcarg8 , env ) )) ; 
  (__funcarg7 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_arity (udp_read_evt , "udp-receive!-evt" , 2 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("udp-receive!-evt" , __funcarg7 , env ) )) ; 
  (__funcarg6 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_arity (udp_write_evt , "udp-send-evt" , 2 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("udp-send-evt" , __funcarg6 , env ) )) ; 
  (__funcarg5 = FUNCCALL(SETUP_XfOrM4(_), scheme_make_prim_w_arity (udp_write_to_evt , "udp-send-to-evt" , 4 , 6 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("udp-send-to-evt" , __funcarg5 , env ) )) ; 
  FUNCCALL_EMPTY(register_tcp_listener_sync () ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
typedef struct sockaddr_in mz_unspec_address ; 
static struct protoent * proto ; 
struct addrinfo * scheme_get_host_address (const char * address , int id , int * err , int family , int passive , int tcp ) {
  char buf [32 ] , * service ; 
  int ok ; 
  GC_CAN_IGNORE struct addrinfo * r , hints ; 
  if (id ) {
    service = buf ; 
    sprintf (buf , "%d" , id ) ; 
  }
  else service = ((void * ) 0 ) ; 
  if (! address && ! service ) {
    * err = - 1 ; 
    return ((void * ) 0 ) ; 
  }
  memset (& hints , 0 , sizeof (struct addrinfo ) ) ; 
  hints . ai_family = ((family < 0 ) ? 0 : family ) ; 
  if (passive ) {
    hints . ai_flags |= 0x0001 ; 
  }
  if (tcp ) {
    hints . ai_socktype = SOCK_STREAM ; 
    if (! proto ) {
      proto = getprotobyname ("tcp" ) ; 
    }
    hints . ai_protocol = (proto ? proto -> p_proto : 0 ) ; 
  }
  else {
    hints . ai_socktype = SOCK_DGRAM ; 
  }
  ok = getaddrinfo (address , service , & hints , & r ) ; 
  * err = ok ; 
  if (! ok )
    return r ; 
  else return ((void * ) 0 ) ; 
}
void scheme_free_host_address (struct addrinfo * a ) {
  /* No conversion */
  freeaddrinfo (a ) ; 
}
const char * scheme_host_address_strerror (int errnum ) {
  /* No conversion */
  return gai_strerror (errnum ) ; 
}
static int stop_listener (Scheme_Object * o ) ; 
static int tcp_check_accept (Scheme_Object * _listener ) {
  tcp_t s , mx ; 
  listener_t * listener = (listener_t * ) _listener ; 
  static fd_set * readfds ; 
  static fd_set * exnfds ; 
  struct timeval time = {
    0 , 0 }
  ; 
  int sr , i ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(listener, 0)));
# define XfOrM7_COUNT (1)
# define SETUP_XfOrM7(x) SETUP(XfOrM7_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  (readfds = (readfds ? (fd_set * ) FUNCCALL(SETUP_XfOrM7(_), scheme_init_fdset_array (readfds , 1 ) ): (fd_set * ) FUNCCALL(SETUP_XfOrM7(_), scheme_alloc_fdset_array (1 , 1 ) )) ) ; 
  (exnfds = (exnfds ? (fd_set * ) FUNCCALL(SETUP_XfOrM7(_), scheme_init_fdset_array (exnfds , 1 ) ): (fd_set * ) FUNCCALL(SETUP_XfOrM7(_), scheme_alloc_fdset_array (1 , 1 ) )) ) ; 
  if ((((listener_t * ) (listener ) ) -> s [0 ] == (- 1 ) ) )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  FUNCCALL(SETUP_XfOrM7(_), scheme_fdzero (readfds ) ); 
  FUNCCALL_AGAIN(scheme_fdzero (exnfds ) ); 
  mx = 0 ; 
  for (i = 0 ; i < listener -> count ; i ++ ) {
#   define XfOrM14_COUNT (0+XfOrM7_COUNT)
#   define SETUP_XfOrM14(x) SETUP_XfOrM7(x)
    s = listener -> s [i ] ; 
    FUNCCALL(SETUP_XfOrM14(_), scheme_fdset (readfds , s ) ); 
    FUNCCALL_AGAIN(scheme_fdset (exnfds , s ) ); 
    if (s > mx )
      mx = s ; 
  }
  do {
#   define XfOrM12_COUNT (0+XfOrM7_COUNT)
#   define SETUP_XfOrM12(x) SETUP_XfOrM7(x)
    sr = FUNCCALL(SETUP_XfOrM12(_), select (mx + 1 , readfds , ((void * ) 0 ) , exnfds , & time ) ); 
  }
  while ((sr == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
  if (sr ) {
    for (i = 0 ; i < listener -> count ; i ++ ) {
      s = listener -> s [i ] ; 
      if (((((readfds ) -> __fds_bits ) [((s ) / (8 * sizeof (__fd_mask ) ) ) ] & ((__fd_mask ) 1 << ((s ) % (8 * sizeof (__fd_mask ) ) ) ) ) != 0 ) || ((((exnfds ) -> __fds_bits ) [((s ) / (8 * sizeof (__fd_mask ) ) ) ] & ((__fd_mask ) 1 << ((s ) % (8 * sizeof (__fd_mask ) ) ) ) ) != 0 ) )
        RET_VALUE_START (i + 1 ) RET_VALUE_END ; 
    }
  }
  RET_VALUE_START (sr ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void tcp_accept_needs_wakeup (Scheme_Object * _listener , void * fds ) {
  PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(fds, 0)));
# define XfOrM15_COUNT (1)
# define SETUP_XfOrM15(x) SETUP(XfOrM15_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! (((listener_t * ) (_listener ) ) -> s [0 ] == (- 1 ) ) ) {
    listener_t * listener = (listener_t * ) _listener ; 
    int i ; 
    tcp_t s ; 
    void * fds2 ; 
    BLOCK_SETUP((PUSH(fds2, 0+XfOrM15_COUNT), PUSH(listener, 1+XfOrM15_COUNT)));
#   define XfOrM16_COUNT (2+XfOrM15_COUNT)
#   define SETUP_XfOrM16(x) SETUP(XfOrM16_COUNT)
    fds2 = NULLED_OUT ; 
    fds2 = FUNCCALL(SETUP_XfOrM16(_), scheme_get_fdset (fds , 2 ) ); 
    for (i = 0 ; i < listener -> count ; i ++ ) {
#     define XfOrM18_COUNT (0+XfOrM16_COUNT)
#     define SETUP_XfOrM18(x) SETUP_XfOrM16(x)
      s = listener -> s [i ] ; 
      FUNCCALL(SETUP_XfOrM18(_), scheme_fdset ((fd_set * ) fds , s ) ); 
      FUNCCALL_AGAIN(scheme_fdset ((fd_set * ) fds2 , s ) ); 
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int tcp_check_connect (Scheme_Object * connector_p ) {
  tcp_t s ; 
  static fd_set * writefds ; 
  static fd_set * exnfds ; 
  struct timeval time = {
    0 , 0 }
  ; 
  int sr ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(connector_p, 0)));
# define XfOrM19_COUNT (1)
# define SETUP_XfOrM19(x) SETUP(XfOrM19_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  (writefds = (writefds ? (fd_set * ) FUNCCALL(SETUP_XfOrM19(_), scheme_init_fdset_array (writefds , 1 ) ): (fd_set * ) FUNCCALL(SETUP_XfOrM19(_), scheme_alloc_fdset_array (1 , 1 ) )) ) ; 
  (exnfds = (exnfds ? (fd_set * ) FUNCCALL(SETUP_XfOrM19(_), scheme_init_fdset_array (exnfds , 1 ) ): (fd_set * ) FUNCCALL(SETUP_XfOrM19(_), scheme_alloc_fdset_array (1 , 1 ) )) ) ; 
  s = * (tcp_t * ) connector_p ; 
  FUNCCALL_EMPTY(scheme_fdzero (writefds ) ); 
  FUNCCALL_EMPTY(scheme_fdzero (exnfds ) ); 
  FUNCCALL_EMPTY(scheme_fdset (writefds , s ) ); 
  FUNCCALL_EMPTY(scheme_fdset (exnfds , s ) ); 
  do {
#   define XfOrM21_COUNT (0+XfOrM19_COUNT)
#   define SETUP_XfOrM21(x) SETUP_XfOrM19(x)
    sr = FUNCCALL_EMPTY(select (s + 1 , ((void * ) 0 ) , writefds , exnfds , & time ) ); 
  }
  while ((sr == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
  if (! sr )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  if (((((exnfds ) -> __fds_bits ) [((s ) / (8 * sizeof (__fd_mask ) ) ) ] & ((__fd_mask ) 1 << ((s ) % (8 * sizeof (__fd_mask ) ) ) ) ) != 0 ) )
    RET_VALUE_START (- 1 ) RET_VALUE_END ; 
  else RET_VALUE_START (1 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void tcp_connect_needs_wakeup (Scheme_Object * connector_p , void * fds ) {
  void * fds1 , * fds2 ; 
  tcp_t s = * (tcp_t * ) connector_p ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(fds2, 0), PUSH(fds1, 1), PUSH(fds, 2)));
# define XfOrM22_COUNT (3)
# define SETUP_XfOrM22(x) SETUP(XfOrM22_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  fds1 = NULLED_OUT ; 
  fds2 = NULLED_OUT ; 
  fds1 = FUNCCALL(SETUP_XfOrM22(_), scheme_get_fdset (fds , 1 ) ); 
  fds2 = FUNCCALL_AGAIN(scheme_get_fdset (fds , 2 ) ); 
  FUNCCALL_AGAIN(scheme_fdset ((fd_set * ) fds1 , s ) ); 
  FUNCCALL_EMPTY(scheme_fdset ((fd_set * ) fds2 , s ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int tcp_check_write (Scheme_Object * port ) {
  Scheme_Tcp * data = (Scheme_Tcp * ) ((Scheme_Output_Port * ) port ) -> port_data ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(data, 0)));
# define XfOrM23_COUNT (1)
# define SETUP_XfOrM23(x) SETUP(XfOrM23_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (((Scheme_Output_Port * ) port ) -> closed )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  {
    tcp_t s ; 
    static fd_set * writefds ; 
    static fd_set * exnfds ; 
    struct timeval time = {
      0 , 0 }
    ; 
    int sr ; 
#   define XfOrM24_COUNT (0+XfOrM23_COUNT)
#   define SETUP_XfOrM24(x) SETUP_XfOrM23(x)
    (writefds = (writefds ? (fd_set * ) FUNCCALL(SETUP_XfOrM24(_), scheme_init_fdset_array (writefds , 1 ) ): (fd_set * ) FUNCCALL(SETUP_XfOrM24(_), scheme_alloc_fdset_array (1 , 1 ) )) ) ; 
    (exnfds = (exnfds ? (fd_set * ) FUNCCALL(SETUP_XfOrM24(_), scheme_init_fdset_array (exnfds , 1 ) ): (fd_set * ) FUNCCALL(SETUP_XfOrM24(_), scheme_alloc_fdset_array (1 , 1 ) )) ) ; 
    s = data -> tcp ; 
    FUNCCALL_EMPTY(scheme_fdzero (writefds ) ); 
    FUNCCALL_EMPTY(scheme_fdset (writefds , s ) ); 
    FUNCCALL_EMPTY(scheme_fdzero (exnfds ) ); 
    FUNCCALL_EMPTY(scheme_fdset (exnfds , s ) ); 
    do {
#     define XfOrM26_COUNT (0+XfOrM24_COUNT)
#     define SETUP_XfOrM26(x) SETUP_XfOrM24(x)
      sr = FUNCCALL_EMPTY(select (s + 1 , ((void * ) 0 ) , writefds , exnfds , & time ) ); 
    }
    while ((sr == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
    RET_VALUE_START (sr ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void tcp_write_needs_wakeup (Scheme_Object * port , void * fds ) {
  Scheme_Object * conn = ((Scheme_Output_Port * ) port ) -> port_data ; 
  void * fds1 , * fds2 ; 
  tcp_t s = ((Scheme_Tcp * ) conn ) -> tcp ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(fds2, 0), PUSH(fds1, 1), PUSH(fds, 2)));
# define XfOrM27_COUNT (3)
# define SETUP_XfOrM27(x) SETUP(XfOrM27_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  fds1 = NULLED_OUT ; 
  fds2 = NULLED_OUT ; 
  fds1 = FUNCCALL(SETUP_XfOrM27(_), scheme_get_fdset (fds , 1 ) ); 
  fds2 = FUNCCALL_AGAIN(scheme_get_fdset (fds , 2 ) ); 
  FUNCCALL_AGAIN(scheme_fdset ((fd_set * ) fds1 , s ) ); 
  FUNCCALL_EMPTY(scheme_fdset ((fd_set * ) fds2 , s ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Tcp * make_tcp_port_data (tcp_t tcp , int refcount ) {
  Scheme_Tcp * data ; 
  char * bfr ; 
  DECL_RET_SAVE (Scheme_Tcp * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(bfr, 0), PUSH(data, 1)));
# define XfOrM28_COUNT (2)
# define SETUP_XfOrM28(x) SETUP(XfOrM28_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  data = NULLED_OUT ; 
  bfr = NULLED_OUT ; 
  data = ((Scheme_Tcp * ) FUNCCALL(SETUP_XfOrM28(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Tcp ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  data -> b . type = scheme_rt_tcp ; 
  data -> tcp = tcp ; 
  bfr = (char * ) FUNCCALL(SETUP_XfOrM28(_), GC_malloc_atomic (4096 ) ); 
  data -> b . buffer = bfr ; 
  bfr = (char * ) FUNCCALL(SETUP_XfOrM28(_), GC_malloc_atomic (4096 ) ); 
  data -> b . out_buffer = bfr ; 
  data -> b . bufpos = 0 ; 
  data -> b . bufmax = 0 ; 
  data -> b . hiteof = 0 ; 
  data -> b . refcount = refcount ; 
  fcntl (tcp , 4 , 2048 ) ; 
  RET_VALUE_START (data ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 1177 */
/* this far 1177 */
static int tcp_byte_ready (Scheme_Input_Port * port ) {
  Scheme_Tcp * data ; 
  int sr ; 
  static fd_set * readfds ; 
  static fd_set * exfds ; 
  struct timeval time = {
    0 , 0 }
  ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(data, 0), PUSH(port, 1)));
# define XfOrM29_COUNT (2)
# define SETUP_XfOrM29(x) SETUP(XfOrM29_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  data = NULLED_OUT ; 
  (readfds = (readfds ? (fd_set * ) FUNCCALL(SETUP_XfOrM29(_), scheme_init_fdset_array (readfds , 1 ) ): (fd_set * ) FUNCCALL(SETUP_XfOrM29(_), scheme_alloc_fdset_array (1 , 1 ) )) ) ; 
  (exfds = (exfds ? (fd_set * ) FUNCCALL(SETUP_XfOrM29(_), scheme_init_fdset_array (exfds , 1 ) ): (fd_set * ) FUNCCALL(SETUP_XfOrM29(_), scheme_alloc_fdset_array (1 , 1 ) )) ) ; 
  if (port -> closed )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  data = (Scheme_Tcp * ) port -> port_data ; 
  if (data -> b . hiteof )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  if (data -> b . bufpos < data -> b . bufmax )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  FUNCCALL(SETUP_XfOrM29(_), scheme_fdzero (readfds ) ); 
  FUNCCALL_AGAIN(scheme_fdzero (exfds ) ); 
  FUNCCALL_AGAIN(scheme_fdset (readfds , data -> tcp ) ); 
  FUNCCALL_AGAIN(scheme_fdset (exfds , data -> tcp ) ); 
  do {
#   define XfOrM31_COUNT (0+XfOrM29_COUNT)
#   define SETUP_XfOrM31(x) SETUP_XfOrM29(x)
    sr = FUNCCALL(SETUP_XfOrM31(_), select (data -> tcp + 1 , readfds , ((void * ) 0 ) , exfds , & time ) ); 
  }
  while ((sr == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
  RET_VALUE_START (sr ) RET_VALUE_END ; 
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static long tcp_get_string (Scheme_Input_Port * port , char * buffer , long offset , long size , int nonblock , Scheme_Object * unless ) {
  int errid ; 
  int read_amt ; 
  Scheme_Tcp * data ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(unless, 0), PUSH(buffer, 1), PUSH(data, 2), PUSH(port, 3)));
# define XfOrM32_COUNT (4)
# define SETUP_XfOrM32(x) SETUP(XfOrM32_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  data = NULLED_OUT ; 
  data = (Scheme_Tcp * ) port -> port_data ; 
  top : if ((scheme_unless_ready (unless ) ) )
    RET_VALUE_START ((- 3 ) ) RET_VALUE_END ; 
  if (data -> b . hiteof )
    RET_VALUE_START ((- 1 ) ) RET_VALUE_END ; 
  if (data -> b . bufpos < data -> b . bufmax ) {
    int n ; 
#   define XfOrM42_COUNT (0+XfOrM32_COUNT)
#   define SETUP_XfOrM42(x) SETUP_XfOrM32(x)
    n = data -> b . bufmax - data -> b . bufpos ; 
    n = ((size <= n ) ? size : n ) ; 
    (memcpy (buffer + offset , data -> b . buffer + data -> b . bufpos , n ) ) ; 
    data -> b . bufpos += n ; 
    RET_VALUE_START (n ) RET_VALUE_END ; 
  }
  while (! FUNCCALL(SETUP_XfOrM32(_), tcp_byte_ready (port ) )) {
#   define XfOrM41_COUNT (0+XfOrM32_COUNT)
#   define SETUP_XfOrM41(x) SETUP_XfOrM32(x)
    if (nonblock > 0 )
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    FUNCCALL(SETUP_XfOrM41(_), scheme_block_until_unless ((Scheme_Ready_Fun ) tcp_byte_ready , scheme_need_wakeup , (Scheme_Object * ) port , 0.0 , unless , nonblock ) ); 
    FUNCCALL_AGAIN(scheme_wait_input_allowed (port , nonblock ) ); 
    if ((scheme_unless_ready (unless ) ) )
      RET_VALUE_START ((- 3 ) ) RET_VALUE_END ; 
  }
  if (port -> closed ) {
#   define XfOrM39_COUNT (0+XfOrM32_COUNT)
#   define SETUP_XfOrM39(x) SETUP_XfOrM32(x)
    FUNCCALL(SETUP_XfOrM39(_), scheme_get_byte ((Scheme_Object * ) port ) ); 
  }
  if (! data -> b . bufmode || (size > 4096 ) )
    read_amt = 4096 ; 
  else read_amt = size ; 
  {
    int rn ; 
    do {
      rn = recv (data -> tcp , data -> b . buffer , read_amt , 0 ) ; 
    }
    while ((rn == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
    data -> b . bufmax = rn ; 
  }
  errid = (* __errno_location () ) ; 
  if ((data -> b . bufmax == - 1 ) && ((errid == 11 ) || (errid == 11 ) || (errid == 115 ) || (errid == 114 ) ) )
    goto top ; 
  if (data -> b . bufmax == - 1 ) {
#   define XfOrM35_COUNT (0+XfOrM32_COUNT)
#   define SETUP_XfOrM35(x) SETUP_XfOrM32(x)
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_NETWORK , "tcp-read: error reading (%e)" , errid ) ); 
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  else if (! data -> b . bufmax ) {
    data -> b . hiteof = 1 ; 
    RET_VALUE_START ((- 1 ) ) RET_VALUE_END ; 
  }
  {
    int n ; 
#   define XfOrM33_COUNT (0+XfOrM32_COUNT)
#   define SETUP_XfOrM33(x) SETUP_XfOrM32(x)
    n = data -> b . bufmax ; 
    if (size < n )
      n = size ; 
    (memcpy (buffer + offset , data -> b . buffer , n ) ) ; 
    data -> b . bufpos = n ; 
    RET_VALUE_START (n ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void tcp_need_wakeup (Scheme_Input_Port * port , void * fds ) {
  Scheme_Tcp * data ; 
  PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(data, 0), PUSH(fds, 1)));
# define XfOrM43_COUNT (2)
# define SETUP_XfOrM43(x) SETUP(XfOrM43_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  data = NULLED_OUT ; 
  data = (Scheme_Tcp * ) port -> port_data ; 
  {
    void * fds2 ; 
    BLOCK_SETUP((PUSH(fds2, 0+XfOrM43_COUNT)));
#   define XfOrM44_COUNT (1+XfOrM43_COUNT)
#   define SETUP_XfOrM44(x) SETUP(XfOrM44_COUNT)
    fds2 = NULLED_OUT ; 
    fds2 = FUNCCALL(SETUP_XfOrM44(_), scheme_get_fdset (fds , 2 ) ); 
    FUNCCALL_AGAIN(scheme_fdset ((fd_set * ) fds , data -> tcp ) ); 
    FUNCCALL_EMPTY(scheme_fdset ((fd_set * ) fds2 , data -> tcp ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void tcp_close_input (Scheme_Input_Port * port ) {
  Scheme_Tcp * data ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(data, 0)));
# define XfOrM45_COUNT (1)
# define SETUP_XfOrM45(x) SETUP(XfOrM45_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  data = NULLED_OUT ; 
  data = (Scheme_Tcp * ) port -> port_data ; 
  if (! (data -> flags & 0x2 ) )
    FUNCCALL(SETUP_XfOrM45(_), shutdown (data -> tcp , 0 ) ); 
  if (-- data -> b . refcount )
    RET_NOTHING ; 
  ; 
  FUNCCALL_EMPTY(closesocket (data -> tcp ) ); 
  -- scheme_file_open_count ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int tcp_in_buffer_mode (Scheme_Port * p , int mode ) {
  /* No conversion */
  Scheme_Tcp * data ; 
  data = (Scheme_Tcp * ) ((Scheme_Input_Port * ) p ) -> port_data ; 
  if (mode < 0 )
    return data -> b . bufmode ; 
  else {
    data -> b . bufmode = mode ; 
    return mode ; 
  }
}
static long tcp_do_write_string (Scheme_Output_Port * port , const char * s , long offset , long len , int rarely_block , int enable_break ) {
  Scheme_Tcp * data ; 
  int errid , would_block = 0 ; 
  long sent ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(data, 0), PUSH(s, 1), PUSH(port, 2)));
# define XfOrM48_COUNT (3)
# define SETUP_XfOrM48(x) SETUP(XfOrM48_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  data = NULLED_OUT ; 
  data = (Scheme_Tcp * ) port -> port_data ; 
  top : do {
    sent = send (data -> tcp , s XFORM_OK_PLUS offset , len , 0 ) ; 
  }
  while ((sent == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
  if (sent != len ) {
#   define XfOrM51_COUNT (0+XfOrM48_COUNT)
#   define SETUP_XfOrM51(x) SETUP_XfOrM48(x)
    errid = (* __errno_location () ) ; 
    if (sent > 0 ) {
#     define XfOrM54_COUNT (0+XfOrM51_COUNT)
#     define SETUP_XfOrM54(x) SETUP_XfOrM51(x)
      if (rarely_block )
        RET_VALUE_START (sent ) RET_VALUE_END ; 
      else sent += FUNCCALL(SETUP_XfOrM54(_), tcp_do_write_string (port , s , offset + sent , len - sent , 0 , enable_break ) ); 
      errid = 0 ; 
    }
    else if ((len > 1 ) && (errid == 90 ) ) {
      int half = (len / 2 ) ; 
#     define XfOrM53_COUNT (0+XfOrM51_COUNT)
#     define SETUP_XfOrM53(x) SETUP_XfOrM51(x)
      sent = FUNCCALL(SETUP_XfOrM53(_), tcp_do_write_string (port , s , offset , half , rarely_block , enable_break ) ); 
      if (rarely_block )
        RET_VALUE_START (sent ) RET_VALUE_END ; 
      sent += FUNCCALL(SETUP_XfOrM53(_), tcp_do_write_string (port , s , offset + half , len - half , 0 , enable_break ) ); 
      errid = 0 ; 
    }
    else if (((errid == 11 ) || (errid == 11 ) || (errid == 115 ) || (errid == 114 ) ) ) {
      errid = 0 ; 
      would_block = 1 ; 
    }
  }
  else errid = 0 ; 
  if (would_block ) {
#   define XfOrM49_COUNT (0+XfOrM48_COUNT)
#   define SETUP_XfOrM49(x) SETUP_XfOrM48(x)
    if (rarely_block == 2 )
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    FUNCCALL(SETUP_XfOrM49(_), scheme_block_until_enable_break (tcp_check_write , tcp_write_needs_wakeup , (Scheme_Object * ) port , (float ) 0.0 , enable_break ) ); 
    if (((Scheme_Output_Port * ) port ) -> closed ) {
#     define XfOrM50_COUNT (0+XfOrM49_COUNT)
#     define SETUP_XfOrM50(x) SETUP_XfOrM49(x)
      FUNCCALL(SETUP_XfOrM50(_), scheme_put_byte_string ("tcp-write-string" , (Scheme_Object * ) port , s , offset , len , 0 ) ); 
      RET_VALUE_START (sent + len ) RET_VALUE_END ; 
    }
    would_block = 0 ; 
    goto top ; 
  }
  if (errid )
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_NETWORK , "tcp-write: error writing (%e)" , errid ) ); 
  RET_VALUE_START (sent ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int tcp_flush (Scheme_Output_Port * port , int rarely_block , int enable_break ) {
  Scheme_Tcp * data ; 
  int amt , flushed = 0 ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(data, 0), PUSH(port, 1)));
# define XfOrM57_COUNT (2)
# define SETUP_XfOrM57(x) SETUP(XfOrM57_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  data = NULLED_OUT ; 
  data = (Scheme_Tcp * ) port -> port_data ; 
  while (1 ) {
#   define XfOrM60_COUNT (0+XfOrM57_COUNT)
#   define SETUP_XfOrM60(x) SETUP_XfOrM57(x)
    if (data -> b . out_bufpos == data -> b . out_bufmax ) {
      data -> b . out_bufpos = 0 ; 
      data -> b . out_bufmax = 0 ; 
      RET_VALUE_START (flushed ) RET_VALUE_END ; 
    }
    amt = FUNCCALL(SETUP_XfOrM60(_), tcp_do_write_string (port , data -> b . out_buffer , data -> b . out_bufpos , data -> b . out_bufmax - data -> b . out_bufpos , rarely_block , enable_break ) ); 
    flushed += amt ; 
    data -> b . out_bufpos += amt ; 
    if (rarely_block && (data -> b . out_bufpos < data -> b . out_bufmax ) )
      RET_VALUE_START (flushed ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static long tcp_write_string (Scheme_Output_Port * port , const char * s , long offset , long len , int rarely_block , int enable_break ) {
  Scheme_Tcp * data ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(data, 0), PUSH(s, 1), PUSH(port, 2)));
# define XfOrM62_COUNT (3)
# define SETUP_XfOrM62(x) SETUP(XfOrM62_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  data = NULLED_OUT ; 
  data = (Scheme_Tcp * ) port -> port_data ; 
  if (! len ) {
#   define XfOrM70_COUNT (0+XfOrM62_COUNT)
#   define SETUP_XfOrM70(x) SETUP_XfOrM62(x)
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(tcp_flush (port , rarely_block , enable_break ) )) RET_VALUE_EMPTY_END ; 
  }
  if (rarely_block ) {
#   define XfOrM69_COUNT (0+XfOrM62_COUNT)
#   define SETUP_XfOrM69(x) SETUP_XfOrM62(x)
    FUNCCALL(SETUP_XfOrM69(_), tcp_flush (port , rarely_block , enable_break ) ); 
    if (data -> b . out_bufmax )
      RET_VALUE_START (- 1 ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM63_COUNT (0+XfOrM62_COUNT)
#   define SETUP_XfOrM63(x) SETUP_XfOrM62(x)
    if (data -> b . out_bufmode < 2 ) {
#     define XfOrM64_COUNT (0+XfOrM63_COUNT)
#     define SETUP_XfOrM64(x) SETUP_XfOrM63(x)
      if (data -> b . out_bufmax + len < 4096 ) {
#       define XfOrM65_COUNT (0+XfOrM64_COUNT)
#       define SETUP_XfOrM65(x) SETUP_XfOrM64(x)
        (memcpy (data -> b . out_buffer + data -> b . out_bufmax , s + offset , len ) ) ; 
        data -> b . out_bufmax += (short ) len ; 
        if (data -> b . out_bufmode == 1 ) {
          int i ; 
#         define XfOrM66_COUNT (0+XfOrM65_COUNT)
#         define SETUP_XfOrM66(x) SETUP_XfOrM65(x)
          for (i = 0 ; i < len ; i ++ ) {
            if ((s [offset + i ] == '\r' ) || (s [offset + i ] == '\n' ) )
              break ; 
          }
          if (i < len )
            FUNCCALL(SETUP_XfOrM66(_), tcp_flush (port , rarely_block , enable_break ) ); 
        }
        RET_VALUE_START (len ) RET_VALUE_END ; 
      }
    }
    FUNCCALL(SETUP_XfOrM63(_), tcp_flush (port , rarely_block , enable_break ) ); 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(tcp_do_write_string (port , s , offset , len , rarely_block , enable_break ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void tcp_close_output (Scheme_Output_Port * port ) {
  Scheme_Tcp * data ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(data, 0)));
# define XfOrM71_COUNT (1)
# define SETUP_XfOrM71(x) SETUP(XfOrM71_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  data = NULLED_OUT ; 
  data = (Scheme_Tcp * ) port -> port_data ; 
  if (data -> b . out_bufmax && ! scheme_force_port_closed )
    FUNCCALL(SETUP_XfOrM71(_), tcp_flush (port , 0 , 0 ) ); 
  if (! (data -> flags & 0x1 ) )
    FUNCCALL(SETUP_XfOrM71(_), shutdown (data -> tcp , 1 ) ); 
  if (-- data -> b . refcount )
    RET_NOTHING ; 
  ; 
  FUNCCALL_EMPTY(closesocket (data -> tcp ) ); 
  -- scheme_file_open_count ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int tcp_out_buffer_mode (Scheme_Port * p , int mode ) {
  /* No conversion */
  Scheme_Tcp * data ; 
  data = (Scheme_Tcp * ) ((Scheme_Output_Port * ) p ) -> port_data ; 
  if (mode < 0 )
    return data -> b . out_bufmode ; 
  else {
    int go ; 
    go = (mode > data -> b . out_bufmode ) ; 
    data -> b . out_bufmode = mode ; 
    if (go )
      tcp_flush ((Scheme_Output_Port * ) p , 0 , 0 ) ; 
    return mode ; 
  }
}
static Scheme_Object * make_tcp_input_port (void * data , const char * name ) {
  Scheme_Input_Port * ip ; 
  Scheme_Object * __funcarg38 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(data, 0), PUSH(ip, 1)));
# define XfOrM74_COUNT (2)
# define SETUP_XfOrM74(x) SETUP(XfOrM74_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ip = NULLED_OUT ; 
  ip = (__funcarg38 = FUNCCALL(SETUP_XfOrM74(_), scheme_make_immutable_sized_utf8_string ((char * ) name , - 1 ) ), FUNCCALL_AGAIN(scheme_make_input_port (scheme_tcp_input_port_type , data , __funcarg38 , tcp_get_string , ((void * ) 0 ) , scheme_progress_evt_via_get , scheme_peeked_read_via_get , tcp_byte_ready , tcp_close_input , tcp_need_wakeup , 1 ) )) ; 
  ip -> p . buffer_mode_fun = tcp_in_buffer_mode ; 
  RET_VALUE_START ((Scheme_Object * ) ip ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_tcp_output_port (void * data , const char * name ) {
  Scheme_Output_Port * op ; 
  Scheme_Object * __funcarg39 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(op, 0), PUSH(data, 1)));
# define XfOrM75_COUNT (2)
# define SETUP_XfOrM75(x) SETUP(XfOrM75_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  op = NULLED_OUT ; 
  op = (__funcarg39 = FUNCCALL(SETUP_XfOrM75(_), scheme_make_immutable_sized_utf8_string ((char * ) name , - 1 ) ), FUNCCALL_AGAIN(scheme_make_output_port (scheme_tcp_output_port_type , data , __funcarg39 , scheme_write_evt_via_write , tcp_write_string , (Scheme_Out_Ready_Fun ) tcp_check_write , tcp_close_output , (Scheme_Need_Wakeup_Output_Fun ) tcp_write_needs_wakeup , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) )) ; 
  op -> p . buffer_mode_fun = tcp_out_buffer_mode ; 
  RET_VALUE_START ((Scheme_Object * ) op ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
typedef struct Close_Socket_Data {
  tcp_t s ; 
  struct addrinfo * src_addr , * dest_addr ; 
}
Close_Socket_Data ; 
static void closesocket_w_decrement (Close_Socket_Data * csd ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(csd, 0)));
# define XfOrM76_COUNT (1)
# define SETUP_XfOrM76(x) SETUP(XfOrM76_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM76(_), closesocket (csd -> s ) ); 
  if (csd -> src_addr )
    FUNCCALL(SETUP_XfOrM76(_), freeaddrinfo (csd -> src_addr ) ); 
  FUNCCALL_EMPTY(freeaddrinfo (csd -> dest_addr ) ); 
  -- scheme_file_open_count ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
const char * scheme_hostname_error (int err ) {
  /* No conversion */
  return gai_strerror (err ) ; 
}
static Scheme_Object * tcp_connect (int argc , Scheme_Object * argv [] ) {
  char * volatile address = "" , * volatile src_address , * volatile errmsg = "" ; 
  unsigned short origid , id , src_origid , src_id ; 
  int errpart = 0 , errid = 0 ; 
  volatile int nameerr = 0 , no_local_spec ; 
  Scheme_Object * bs , * src_bs ; 
  GC_CAN_IGNORE struct addrinfo * tcp_connect_dest ; 
  GC_CAN_IGNORE struct addrinfo * volatile tcp_connect_src ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(10);
  BLOCK_SETUP_TOP((PUSH(src_address, 0), PUSH(address, 1), PUSH(bs, 2), PUSH(errmsg, 3), PUSH(argv, 4), PUSH(src_bs, 5)));
# define XfOrM78_COUNT (6)
# define SETUP_XfOrM78(x) SETUP(XfOrM78_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  src_address = NULLED_OUT ; 
  bs = NULLED_OUT ; 
  src_bs = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("tcp-connect" , "string" , 0 , argc , argv ) ); 
  if (! ((((long ) (argv [1 ] ) ) & 0x1 ) && ((((long ) (argv [1 ] ) ) >> 1 ) >= 1 ) && ((((long ) (argv [1 ] ) ) >> 1 ) <= 65535 ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("tcp-connect" , "exact integer in [1, 65535]" , 1 , argc , argv ) ); 
  if (argc > 2 )
    if (! ((Scheme_Type ) (((((long ) (argv [2 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [2 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) && ! (((argv [2 ] ) ) == (scheme_false ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("tcp-connect" , "string or #f" , 2 , argc , argv ) ); 
  if (argc > 3 )
    if ((! (((argv [3 ] ) ) == (scheme_false ) ) ) && ! ((((long ) (argv [3 ] ) ) & 0x1 ) && ((((long ) (argv [3 ] ) ) >> 1 ) >= 1 ) && ((((long ) (argv [3 ] ) ) >> 1 ) <= 65535 ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("tcp-connect" , "exact integer in [1, 65535]" " or #f" , 3 , argc , argv ) ); 
  ; 
  bs = argv [0 ] ; 
  if (((Scheme_Type ) (((((long ) (bs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (bs ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    bs = FUNCCALL(SETUP_XfOrM78(_), scheme_char_string_to_byte_string (bs ) ); 
  address = (((Scheme_Simple_Object * ) (bs ) ) -> u . byte_str_val . string_val ) ; 
  origid = (unsigned short ) (((long ) (argv [1 ] ) ) >> 1 ) ; 
  if ((argc > 2 ) && (! (((argv [2 ] ) ) == (scheme_false ) ) ) ) {
#   define XfOrM112_COUNT (0+XfOrM78_COUNT)
#   define SETUP_XfOrM112(x) SETUP_XfOrM78(x)
    src_bs = FUNCCALL(SETUP_XfOrM112(_), scheme_char_string_to_byte_string (argv [2 ] ) ); 
    src_address = (((Scheme_Simple_Object * ) (src_bs ) ) -> u . byte_str_val . string_val ) ; 
  }
  else src_address = ((void * ) 0 ) ; 
  if ((argc > 3 ) && (! (((argv [3 ] ) ) == (scheme_false ) ) ) ) {
    no_local_spec = 0 ; 
    src_origid = (unsigned short ) (((long ) (argv [3 ] ) ) >> 1 ) ; 
  }
  else {
#   define XfOrM109_COUNT (0+XfOrM78_COUNT)
#   define SETUP_XfOrM109(x) SETUP_XfOrM78(x)
    no_local_spec = 1 ; 
    src_origid = 0 ; 
    if (src_address ) {
#     define XfOrM110_COUNT (0+XfOrM109_COUNT)
#     define SETUP_XfOrM110(x) SETUP_XfOrM109(x)
      FUNCCALL(SETUP_XfOrM110(_), scheme_arg_mismatch ("tcp-connect" , "no local port number supplied when local hostname was supplied: " , argv [2 ] ) ); 
    }
  }
  FUNCCALL(SETUP_XfOrM78(_), scheme_security_check_network ("tcp-connect" , address , origid , 1 ) ); 
  FUNCCALL(SETUP_XfOrM78(_), scheme_custodian_check_available (((void * ) 0 ) , "tcp-connect" , "network" ) ); 
  id = origid ; 
  src_id = src_origid ; 
  tcp_connect_dest = FUNCCALL(SETUP_XfOrM78(_), scheme_get_host_address (address , id , & errid , - 1 , 0 , 1 ) ); 
  if (tcp_connect_dest ) {
#   define XfOrM80_COUNT (0+XfOrM78_COUNT)
#   define SETUP_XfOrM80(x) SETUP_XfOrM78(x)
    if (no_local_spec )
      tcp_connect_src = ((void * ) 0 ) ; 
    else tcp_connect_src = FUNCCALL(SETUP_XfOrM80(_), scheme_get_host_address (src_address , src_id , & errid , - 1 , 1 , 1 ) ); 
    if (no_local_spec || tcp_connect_src ) {
      GC_CAN_IGNORE struct addrinfo * volatile addr ; 
#     define XfOrM82_COUNT (0+XfOrM80_COUNT)
#     define SETUP_XfOrM82(x) SETUP_XfOrM80(x)
      for (addr = tcp_connect_dest ; addr ; addr = addr -> ai_next ) {
        tcp_t s ; 
#       define XfOrM96_COUNT (0+XfOrM82_COUNT)
#       define SETUP_XfOrM96(x) SETUP_XfOrM82(x)
        s = socket (addr -> ai_family , addr -> ai_socktype , addr -> ai_protocol ) ; 
        if (s != (- 1 ) ) {
          int status , inprogress ; 
#         define XfOrM98_COUNT (0+XfOrM96_COUNT)
#         define SETUP_XfOrM98(x) SETUP_XfOrM96(x)
          if (no_local_spec || ! FUNCCALL(SETUP_XfOrM98(_), bind (s , tcp_connect_src -> ai_addr , tcp_connect_src -> ai_addrlen ) )) {
            int size = 32768 ; 
#           define XfOrM100_COUNT (0+XfOrM98_COUNT)
#           define SETUP_XfOrM100(x) SETUP_XfOrM98(x)
            fcntl (s , 4 , 2048 ) ; 
            setsockopt (s , 1 , 7 , (char * ) & size , sizeof (int ) ) ; 
            status = connect (s , addr -> ai_addr , addr -> ai_addrlen ) ; 
            if (status )
              status = (* __errno_location () ) ; 
            if (status == 4 )
              status = 115 ; 
            inprogress = (status == 115 ) ; 
            scheme_file_open_count ++ ; 
            if (inprogress ) {
              tcp_t * sptr ; 
              Close_Socket_Data * csd ; 
              BLOCK_SETUP((PUSH(csd, 0+XfOrM100_COUNT), PUSH(sptr, 1+XfOrM100_COUNT)));
#             define XfOrM103_COUNT (2+XfOrM100_COUNT)
#             define SETUP_XfOrM103(x) SETUP(XfOrM103_COUNT)
              sptr = NULLED_OUT ; 
              csd = NULLED_OUT ; 
              sptr = (tcp_t * ) FUNCCALL(SETUP_XfOrM103(_), GC_malloc_atomic (sizeof (tcp_t ) ) ); 
              * sptr = s ; 
              csd = (Close_Socket_Data * ) FUNCCALL(SETUP_XfOrM103(_), GC_malloc_atomic (sizeof (Close_Socket_Data ) ) ); 
              csd -> s = s ; 
              csd -> src_addr = tcp_connect_src ; 
              csd -> dest_addr = tcp_connect_dest ; 
              {
                mz_jmp_buf * volatile savebuf , newbuf ; 
                BLOCK_SETUP((PUSH(savebuf, 0+XfOrM103_COUNT)));
#               define XfOrM106_COUNT (1+XfOrM103_COUNT)
#               define SETUP_XfOrM106(x) SETUP(XfOrM106_COUNT)
                savebuf = NULLED_OUT ; 
                FUNCCALL(SETUP_XfOrM106(_), scheme_push_kill_action ((Scheme_Kill_Action_Func ) closesocket_w_decrement , (void * ) csd ) ); 
                savebuf = scheme_current_thread -> error_buf ; 
                scheme_current_thread -> error_buf = & newbuf ; 
                if (((newbuf ) . gcvs = (long ) __gc_var_stack__ , (newbuf ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((newbuf ) . jb ) , (_setjmp (((newbuf ) . jb ) -> jb ) ) ) ) ) {
#                 define XfOrM108_COUNT (0+XfOrM106_COUNT)
#                 define SETUP_XfOrM108(x) SETUP_XfOrM106(x)
                  FUNCCALL(SETUP_XfOrM108(_), scheme_pop_kill_action () ); 
                  FUNCCALL(SETUP_XfOrM108(_), closesocket_w_decrement (csd ) ); 
                  (((long * ) (void * ) ((* savebuf ) . gcvs ) ) [1 ] = (* savebuf ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* savebuf ) . gcvs , scheme_jit_longjmp ((* savebuf ) . jb , 1 ) ) ; 
                }
                else {
#                 define XfOrM107_COUNT (0+XfOrM106_COUNT)
#                 define SETUP_XfOrM107(x) SETUP_XfOrM106(x)
                  ; 
                  FUNCCALL(SETUP_XfOrM107(_), scheme_block_until (tcp_check_connect , tcp_connect_needs_wakeup , (void * ) sptr , (float ) 0.0 ) ); 
                  FUNCCALL_AGAIN(scheme_pop_kill_action () ); 
                  scheme_current_thread -> error_buf = savebuf ; 
                }
              }
              ; 
              {
                unsigned int so_len = sizeof (status ) ; 
#               define XfOrM104_COUNT (0+XfOrM103_COUNT)
#               define SETUP_XfOrM104(x) SETUP_XfOrM103(x)
                if (FUNCCALL(SETUP_XfOrM104(_), getsockopt (s , 1 , 4 , (void * ) & status , & so_len ) )!= 0 ) {
                  status = (* __errno_location () ) ; 
                }
                (* __errno_location () ) = status ; 
              }
            }
            if (! status ) {
              Scheme_Object * v [2 ] ; 
              Scheme_Tcp * tcp ; 
              BLOCK_SETUP((PUSHARRAY(v, 2, 0+XfOrM100_COUNT), PUSH(tcp, 3+XfOrM100_COUNT)));
#             define XfOrM102_COUNT (4+XfOrM100_COUNT)
#             define SETUP_XfOrM102(x) SETUP(XfOrM102_COUNT)
              v[0] = NULLED_OUT ; 
              v[1] = NULLED_OUT ; 
              tcp = NULLED_OUT ; 
              if (tcp_connect_src )
                FUNCCALL(SETUP_XfOrM102(_), freeaddrinfo (tcp_connect_src ) ); 
              FUNCCALL(SETUP_XfOrM102(_), freeaddrinfo (tcp_connect_dest ) ); 
              tcp = FUNCCALL_AGAIN(make_tcp_port_data (s , 2 ) ); 
              v [0 ] = FUNCCALL(SETUP_XfOrM102(_), make_tcp_input_port (tcp , address ) ); 
              v [1 ] = FUNCCALL(SETUP_XfOrM102(_), make_tcp_output_port (tcp , address ) ); 
              ; 
              RET_VALUE_START (FUNCCALL(SETUP_XfOrM102(_), scheme_values (2 , v ) )) RET_VALUE_END ; 
            }
            else {
#             define XfOrM101_COUNT (0+XfOrM100_COUNT)
#             define SETUP_XfOrM101(x) SETUP_XfOrM100(x)
              errid = (* __errno_location () ) ; 
              FUNCCALL(SETUP_XfOrM101(_), closesocket (s ) ); 
              -- scheme_file_open_count ; 
              errpart = 6 ; 
            }
          }
          else {
            errpart = 5 ; 
            errid = (* __errno_location () ) ; 
          }
        }
        else {
          errpart = 4 ; 
          errid = (* __errno_location () ) ; 
        }
      }
      if (tcp_connect_src )
        FUNCCALL(SETUP_XfOrM82(_), freeaddrinfo (tcp_connect_src ) ); 
    }
    else {
      errpart = 2 ; 
      nameerr = 1 ; 
      errmsg = "; local host not found" ; 
    }
    if (tcp_connect_dest )
      FUNCCALL(SETUP_XfOrM80(_), freeaddrinfo (tcp_connect_dest ) ); 
  }
  else {
    errpart = 1 ; 
    nameerr = 1 ; 
    errmsg = "; host not found" ; 
  }
  FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_NETWORK , "tcp-connect: connection to %s, port %d failed%s (at step %d: %N)" , address , origid , errmsg , errpart , nameerr , errid ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * tcp_connect_break (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_call_enable_break (tcp_connect , argc , argv ) ; 
}
/* this far 1894 */
static Scheme_Object * tcp_listen (int argc , Scheme_Object * argv [] ) {
  unsigned short id , origid ; 
  int backlog , errid ; 
  int reuse = 0 ; 
  int no_ipv6 = 0 ; 
  const char * address ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(address, 0), PUSH(argv, 1)));
# define XfOrM114_COUNT (2)
# define SETUP_XfOrM114(x) SETUP(XfOrM114_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  address = NULLED_OUT ; 
  if (! ((((long ) (argv [0 ] ) ) & 0x1 ) && ((((long ) (argv [0 ] ) ) >> 1 ) >= 1 ) && ((((long ) (argv [0 ] ) ) >> 1 ) <= 65535 ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("tcp-listen" , "exact integer in [1, 65535]" , 0 , argc , argv ) ); 
  if (argc > 1 ) {
#   define XfOrM168_COUNT (0+XfOrM114_COUNT)
#   define SETUP_XfOrM168(x) SETUP_XfOrM114(x)
    if (! (((long ) (argv [1 ] ) ) & 0x1 ) || ((((long ) (argv [1 ] ) ) >> 1 ) < 1 ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("tcp-listen" , "small positive integer" , 1 , argc , argv ) ); 
  }
  if (argc > 2 )
    reuse = (! (((argv [2 ] ) ) == (scheme_false ) ) ) ; 
  if (argc > 3 ) {
#   define XfOrM167_COUNT (0+XfOrM114_COUNT)
#   define SETUP_XfOrM167(x) SETUP_XfOrM114(x)
    if (! ((Scheme_Type ) (((((long ) (argv [3 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [3 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) && ! (((argv [3 ] ) ) == (scheme_false ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("tcp-listen" , "string or #f" , 3 , argc , argv ) ); 
  }
  ; 
  origid = (unsigned short ) (((long ) (argv [0 ] ) ) >> 1 ) ; 
  if (argc > 1 )
    backlog = (((long ) (argv [1 ] ) ) >> 1 ) ; 
  else backlog = 4 ; 
  if ((argc > 3 ) && (! (((argv [3 ] ) ) == (scheme_false ) ) ) ) {
    Scheme_Object * bs ; 
    BLOCK_SETUP((PUSH(bs, 0+XfOrM114_COUNT)));
#   define XfOrM166_COUNT (1+XfOrM114_COUNT)
#   define SETUP_XfOrM166(x) SETUP(XfOrM166_COUNT)
    bs = NULLED_OUT ; 
    bs = FUNCCALL(SETUP_XfOrM166(_), scheme_char_string_to_byte_string (argv [3 ] ) ); 
    address = (((Scheme_Simple_Object * ) (bs ) ) -> u . byte_str_val . string_val ) ; 
  }
  else address = ((void * ) 0 ) ; 
  FUNCCALL(SETUP_XfOrM114(_), scheme_security_check_network ("tcp-listen" , address , origid , 0 ) ); 
  FUNCCALL_AGAIN(scheme_custodian_check_available (((void * ) 0 ) , "tcp-listen" , "network" ) ); 
  id = origid ; 
  retry : {
    GC_CAN_IGNORE struct addrinfo * tcp_listen_addr , * addr ; 
    int err , count = 0 , pos = 0 , i ; 
    listener_t * l = ((void * ) 0 ) ; 
    int any_v4 = 0 , any_v6 = 0 ; 
    BLOCK_SETUP((PUSH(l, 0+XfOrM114_COUNT)));
#   define XfOrM115_COUNT (1+XfOrM114_COUNT)
#   define SETUP_XfOrM115(x) SETUP(XfOrM115_COUNT)
    tcp_listen_addr = FUNCCALL(SETUP_XfOrM115(_), scheme_get_host_address (address , id , & err , no_ipv6 ? 2 : - 1 , 1 , 1 ) ); 
    for (addr = tcp_listen_addr ; addr ; addr = addr -> ai_next ) {
      if (addr -> ai_family == 2 )
        any_v4 = 1 ; 
      else if (addr -> ai_family == 10 )
        any_v6 = 1 ; 
      count ++ ; 
    }
    if (tcp_listen_addr ) {
      tcp_t s ; 
      int v6_loop = (any_v6 && any_v4 ) , skip_v6 = 0 ; 
#     define XfOrM117_COUNT (0+XfOrM115_COUNT)
#     define SETUP_XfOrM117(x) SETUP_XfOrM115(x)
      errid = 0 ; 
      for (addr = tcp_listen_addr ; addr ; ) {
#       define XfOrM142_COUNT (0+XfOrM117_COUNT)
#       define SETUP_XfOrM142(x) SETUP_XfOrM117(x)
        if ((v6_loop && (addr -> ai_family != 10 ) ) || (skip_v6 && (addr -> ai_family == 10 ) ) ) {
          addr = addr -> ai_next ; 
          if (v6_loop && ! addr ) {
            v6_loop = 0 ; 
            skip_v6 = 1 ; 
            addr = tcp_listen_addr ; 
          }
          continue ; 
        }
        s = socket (addr -> ai_family , addr -> ai_socktype , addr -> ai_protocol ) ; 
        if (s == (- 1 ) ) {
#         define XfOrM159_COUNT (0+XfOrM142_COUNT)
#         define SETUP_XfOrM159(x) SETUP_XfOrM142(x)
          if ((addr -> ai_family == 10 ) && ((* __errno_location () ) == 97 ) ) {
#           define XfOrM160_COUNT (0+XfOrM159_COUNT)
#           define SETUP_XfOrM160(x) SETUP_XfOrM159(x)
            if (any_v4 && ! pos ) {
#             define XfOrM161_COUNT (0+XfOrM160_COUNT)
#             define SETUP_XfOrM161(x) SETUP_XfOrM160(x)
              no_ipv6 = 1 ; 
              FUNCCALL(SETUP_XfOrM161(_), freeaddrinfo (tcp_listen_addr ) ); 
              goto retry ; 
            }
          }
        }
        if (s != (- 1 ) ) {
#         define XfOrM154_COUNT (0+XfOrM142_COUNT)
#         define SETUP_XfOrM154(x) SETUP_XfOrM142(x)
          if (any_v4 && (addr -> ai_family == 10 ) ) {
            int ok ; 
            int on = 1 ; 
#           define XfOrM155_COUNT (0+XfOrM154_COUNT)
#           define SETUP_XfOrM155(x) SETUP_XfOrM154(x)
            ok = setsockopt (s , IPPROTO_IPV6 , 26 , & on , sizeof (on ) ) ; 
            if (ok ) {
#             define XfOrM156_COUNT (0+XfOrM155_COUNT)
#             define SETUP_XfOrM156(x) SETUP_XfOrM155(x)
              if (! pos ) {
#               define XfOrM158_COUNT (0+XfOrM156_COUNT)
#               define SETUP_XfOrM158(x) SETUP_XfOrM156(x)
                no_ipv6 = 1 ; 
                FUNCCALL(SETUP_XfOrM158(_), freeaddrinfo (tcp_listen_addr ) ); 
                goto retry ; 
              }
              else {
#               define XfOrM157_COUNT (0+XfOrM156_COUNT)
#               define SETUP_XfOrM157(x) SETUP_XfOrM156(x)
                errid = (* __errno_location () ) ; 
                FUNCCALL(SETUP_XfOrM157(_), closesocket (s ) ); 
                (* __errno_location () ) = errid ; 
                s = (- 1 ) ; 
              }
            }
          }
        }
        if (s != (- 1 ) ) {
#         define XfOrM145_COUNT (0+XfOrM142_COUNT)
#         define SETUP_XfOrM145(x) SETUP_XfOrM142(x)
          fcntl (s , 4 , 2048 ) ; 
          if (reuse ) {
            setsockopt (s , 1 , 2 , (char * ) (& reuse ) , sizeof (int ) ) ; 
          }
          if (! FUNCCALL(SETUP_XfOrM145(_), bind (s , addr -> ai_addr , addr -> ai_addrlen ) )) {
#           define XfOrM147_COUNT (0+XfOrM145_COUNT)
#           define SETUP_XfOrM147(x) SETUP_XfOrM145(x)
            if (! FUNCCALL(SETUP_XfOrM147(_), listen (s , backlog ) )) {
#             define XfOrM149_COUNT (0+XfOrM147_COUNT)
#             define SETUP_XfOrM149(x) SETUP_XfOrM147(x)
              if (! pos ) {
#               define XfOrM151_COUNT (0+XfOrM149_COUNT)
#               define SETUP_XfOrM151(x) SETUP_XfOrM149(x)
                l = FUNCCALL(SETUP_XfOrM151(_), GC_malloc_one_tagged (sizeof (listener_t ) + ((count - 1 ) * sizeof (tcp_t ) ) ) ); 
                l -> so . type = scheme_listener_type ; 
                l -> count = count ; 
                {
                  Scheme_Custodian_Reference * mref ; 
                  BLOCK_SETUP((PUSH(mref, 0+XfOrM151_COUNT)));
#                 define XfOrM152_COUNT (1+XfOrM151_COUNT)
#                 define SETUP_XfOrM152(x) SETUP(XfOrM152_COUNT)
                  mref = NULLED_OUT ; 
                  mref = FUNCCALL(SETUP_XfOrM152(_), scheme_add_managed (((void * ) 0 ) , (Scheme_Object * ) l , (Scheme_Close_Custodian_Client * ) stop_listener , ((void * ) 0 ) , 1 ) ); 
                  l -> mref = mref ; 
                }
              }
              l -> s [pos ++ ] = s ; 
              scheme_file_open_count ++ ; 
              ; 
              if (pos == count ) {
#               define XfOrM150_COUNT (0+XfOrM149_COUNT)
#               define SETUP_XfOrM150(x) SETUP_XfOrM149(x)
                FUNCCALL(SETUP_XfOrM150(_), freeaddrinfo (tcp_listen_addr ) ); 
                RET_VALUE_START ((Scheme_Object * ) l ) RET_VALUE_END ; 
              }
            }
            else {
#             define XfOrM148_COUNT (0+XfOrM147_COUNT)
#             define SETUP_XfOrM148(x) SETUP_XfOrM147(x)
              errid = (* __errno_location () ) ; 
              FUNCCALL(SETUP_XfOrM148(_), closesocket (s ) ); 
              break ; 
            }
          }
          else {
#           define XfOrM146_COUNT (0+XfOrM145_COUNT)
#           define SETUP_XfOrM146(x) SETUP_XfOrM145(x)
            errid = (* __errno_location () ) ; 
            FUNCCALL(SETUP_XfOrM146(_), closesocket (s ) ); 
            break ; 
          }
        }
        else {
          errid = (* __errno_location () ) ; 
          break ; 
        }
        addr = addr -> ai_next ; 
        if (! addr && v6_loop ) {
          v6_loop = 0 ; 
          skip_v6 = 1 ; 
          addr = tcp_listen_addr ; 
        }
      }
      for (i = 0 ; i < pos ; i ++ ) {
#       define XfOrM119_COUNT (0+XfOrM117_COUNT)
#       define SETUP_XfOrM119(x) SETUP_XfOrM117(x)
        s = l -> s [i ] ; 
        ; 
        FUNCCALL(SETUP_XfOrM119(_), closesocket (s ) ); 
        -- scheme_file_open_count ; 
      }
      FUNCCALL(SETUP_XfOrM117(_), freeaddrinfo (tcp_listen_addr ) ); 
    }
    else {
#     define XfOrM116_COUNT (0+XfOrM115_COUNT)
#     define SETUP_XfOrM116(x) SETUP_XfOrM115(x)
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_NETWORK , "tcp-listen: host not found: %s (%N)" , address , 1 , err ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_NETWORK , "tcp-listen: listen on %d failed (%E)" , origid , errid ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int stop_listener (Scheme_Object * o ) {
  int was_closed = 0 ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(o, 0)));
# define XfOrM169_COUNT (1)
# define SETUP_XfOrM169(x) SETUP(XfOrM169_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  {
    listener_t * listener = (listener_t * ) o ; 
    int i ; 
    tcp_t s ; 
    BLOCK_SETUP((PUSH(listener, 0+XfOrM169_COUNT)));
#   define XfOrM170_COUNT (1+XfOrM169_COUNT)
#   define SETUP_XfOrM170(x) SETUP(XfOrM170_COUNT)
    s = listener -> s [0 ] ; 
    if (s == (- 1 ) )
      was_closed = 1 ; 
    else {
#     define XfOrM171_COUNT (0+XfOrM170_COUNT)
#     define SETUP_XfOrM171(x) SETUP_XfOrM170(x)
      for (i = 0 ; i < listener -> count ; i ++ ) {
#       define XfOrM173_COUNT (0+XfOrM171_COUNT)
#       define SETUP_XfOrM173(x) SETUP_XfOrM171(x)
        s = listener -> s [i ] ; 
        ; 
        FUNCCALL(SETUP_XfOrM173(_), closesocket (s ) ); 
        listener -> s [i ] = (- 1 ) ; 
        -- scheme_file_open_count ; 
      }
      FUNCCALL_EMPTY(scheme_remove_managed (((listener_t * ) o ) -> mref , o ) ); 
    }
  }
  RET_VALUE_START (was_closed ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * tcp_stop (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  int was_closed ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_listener_type ) ) )
    scheme_wrong_type ("tcp-close" , "tcp-listener" , 0 , argc , argv ) ; 
  ; 
  was_closed = stop_listener (argv [0 ] ) ; 
  if (was_closed ) {
    scheme_raise_exn (MZEXN_FAIL_NETWORK , "tcp-close: listener was already closed" ) ; 
    return ((void * ) 0 ) ; 
  }
  return scheme_void ; 
}
static Scheme_Object * tcp_accept_ready (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  int ready ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_listener_type ) ) )
    scheme_wrong_type ("tcp-accept-ready?" , "tcp-listener" , 0 , argc , argv ) ; 
  ; 
  if ((((listener_t * ) (argv [0 ] ) ) -> s [0 ] == (- 1 ) ) ) {
    scheme_raise_exn (MZEXN_FAIL_NETWORK , "tcp-accept-ready?: listener is closed" ) ; 
    return ((void * ) 0 ) ; 
  }
  ready = tcp_check_accept (argv [0 ] ) ; 
  return (ready ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * tcp_accept (int argc , Scheme_Object * argv [] ) {
  int was_closed = 0 , errid , ready_pos ; 
  Scheme_Object * listener ; 
  tcp_t s ; 
  unsigned int l ; 
  GC_CAN_IGNORE char tcp_accept_addr [256 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(listener, 0)));
# define XfOrM178_COUNT (1)
# define SETUP_XfOrM178(x) SETUP(XfOrM178_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  listener = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_listener_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("tcp-accept" , "tcp-listener" , 0 , argc , argv ) ); 
  ; 
  listener = argv [0 ] ; 
  was_closed = (((listener_t * ) (listener ) ) -> s [0 ] == (- 1 ) ) ; 
  if (! was_closed ) {
#   define XfOrM183_COUNT (0+XfOrM178_COUNT)
#   define SETUP_XfOrM183(x) SETUP_XfOrM178(x)
    ready_pos = FUNCCALL(SETUP_XfOrM183(_), tcp_check_accept (listener ) ); 
    if (! ready_pos ) {
#     define XfOrM184_COUNT (0+XfOrM183_COUNT)
#     define SETUP_XfOrM184(x) SETUP_XfOrM183(x)
      FUNCCALL(SETUP_XfOrM184(_), scheme_block_until (tcp_check_accept , tcp_accept_needs_wakeup , listener , 0.0 ) ); 
      ready_pos = FUNCCALL(SETUP_XfOrM184(_), tcp_check_accept (listener ) ); 
    }
    was_closed = (((listener_t * ) (listener ) ) -> s [0 ] == (- 1 ) ) ; 
  }
  else ready_pos = 0 ; 
  if (was_closed ) {
#   define XfOrM182_COUNT (0+XfOrM178_COUNT)
#   define SETUP_XfOrM182(x) SETUP_XfOrM178(x)
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_NETWORK , "tcp-accept: listener is closed" ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  FUNCCALL(SETUP_XfOrM178(_), scheme_custodian_check_available (((void * ) 0 ) , "tcp-accept" , "network" ) ); 
  s = ((listener_t * ) listener ) -> s [ready_pos - 1 ] ; 
  l = sizeof (tcp_accept_addr ) ; 
  do {
#   define XfOrM181_COUNT (0+XfOrM178_COUNT)
#   define SETUP_XfOrM181(x) SETUP_XfOrM178(x)
    s = FUNCCALL(SETUP_XfOrM181(_), accept (s , (struct sockaddr * ) tcp_accept_addr , & l ) ); 
  }
  while ((s == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
  if (s != (- 1 ) ) {
    Scheme_Object * v [2 ] ; 
    Scheme_Tcp * tcp ; 
    int size = 32768 ; 
    BLOCK_SETUP((PUSHARRAY(v, 2, 0+XfOrM178_COUNT), PUSH(tcp, 3+XfOrM178_COUNT)));
#   define XfOrM179_COUNT (4+XfOrM178_COUNT)
#   define SETUP_XfOrM179(x) SETUP(XfOrM179_COUNT)
    v[0] = NULLED_OUT ; 
    v[1] = NULLED_OUT ; 
    tcp = NULLED_OUT ; 
    setsockopt (s , 1 , 7 , (char * ) & size , sizeof (int ) ) ; 
    tcp = FUNCCALL(SETUP_XfOrM179(_), make_tcp_port_data (s , 2 ) ); 
    v [0 ] = FUNCCALL(SETUP_XfOrM179(_), make_tcp_input_port (tcp , "[accepted]" ) ); 
    v [1 ] = FUNCCALL(SETUP_XfOrM179(_), make_tcp_output_port (tcp , "[accepted]" ) ); 
    scheme_file_open_count ++ ; 
    ; 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM179(_), scheme_values (2 , v ) )) RET_VALUE_END ; 
  }
  errid = (* __errno_location () ) ; 
  FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_NETWORK , "tcp-accept: accept from listener failed (%E)" , errid ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * tcp_accept_break (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_call_enable_break (tcp_accept , argc , argv ) ; 
}
static void register_tcp_listener_sync () {
  /* No conversion */
  scheme_add_evt (scheme_listener_type , tcp_check_accept , tcp_accept_needs_wakeup , ((void * ) 0 ) , 0 ) ; 
  scheme_add_evt (scheme_tcp_accept_evt_type , (Scheme_Ready_Fun ) tcp_check_accept_evt , tcp_accept_evt_needs_wakeup , ((void * ) 0 ) , 0 ) ; 
  scheme_add_evt (scheme_udp_evt_type , (Scheme_Ready_Fun ) udp_evt_check_ready , udp_evt_needs_wakeup , ((void * ) 0 ) , 0 ) ; 
}
static Scheme_Object * tcp_listener_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_listener_type ) ) ? scheme_true : scheme_false ) ; 
}
void scheme_getnameinfo (void * sa , int salen , char * host , int hostlen , char * serv , int servlen ) {
  /* No conversion */
  getnameinfo (sa , salen , host , hostlen , serv , servlen , 1 | 2 ) ; 
}
static int extract_svc_value (char * svc_buf ) {
  /* No conversion */
  int id = 0 , j ; 
  for (j = 0 ; svc_buf [j ] ; j ++ ) {
    id = (id * 10 ) + (svc_buf [j ] - '0' ) ; 
  }
  return id ; 
}
static Scheme_Object * tcp_addresses (int argc , Scheme_Object * argv [] ) {
  Scheme_Tcp * tcp = ((void * ) 0 ) ; 
  int closed = 0 ; 
  Scheme_Object * result [4 ] ; 
  int with_ports = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(tcp, 0), PUSHARRAY(result, 4, 1), PUSH(argv, 4)));
# define XfOrM192_COUNT (5)
# define SETUP_XfOrM192(x) SETUP(XfOrM192_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  NULL_OUT_ARRAY (result ) ; 
  if ((scheme_is_output_port (argv [0 ] ) ) ) {
    Scheme_Output_Port * op ; 
    BLOCK_SETUP((PUSH(op, 0+XfOrM192_COUNT)));
#   define XfOrM199_COUNT (1+XfOrM192_COUNT)
#   define SETUP_XfOrM199(x) SETUP(XfOrM199_COUNT)
    op = NULLED_OUT ; 
    op = FUNCCALL(SETUP_XfOrM199(_), scheme_output_port_record (argv [0 ] ) ); 
    if (op -> sub_type == scheme_tcp_output_port_type )
      tcp = op -> port_data ; 
    closed = op -> closed ; 
  }
  else if ((scheme_is_input_port (argv [0 ] ) ) ) {
    Scheme_Input_Port * ip ; 
    BLOCK_SETUP((PUSH(ip, 0+XfOrM192_COUNT)));
#   define XfOrM198_COUNT (1+XfOrM192_COUNT)
#   define SETUP_XfOrM198(x) SETUP(XfOrM198_COUNT)
    ip = NULLED_OUT ; 
    ip = FUNCCALL(SETUP_XfOrM198(_), scheme_input_port_record (argv [0 ] ) ); 
    if (ip -> sub_type == scheme_tcp_input_port_type )
      tcp = ip -> port_data ; 
    closed = ip -> closed ; 
  }
  if (argc > 1 )
    with_ports = (! (((argv [1 ] ) ) == (scheme_false ) ) ) ; 
  if (! tcp )
    FUNCCALL(SETUP_XfOrM192(_), scheme_wrong_type ("tcp-addresses" , "tcp-port" , 0 , argc , argv ) ); 
  if (closed )
    FUNCCALL(SETUP_XfOrM192(_), scheme_raise_exn (MZEXN_FAIL_NETWORK , "tcp-addresses: port is closed" ) ); 
  {
    unsigned int l ; 
    char here [256 ] , there [256 ] ; 
    char host_buf [64 ] ; 
    char svc_buf [32 ] ; 
    unsigned int here_len , there_len ; 
#   define XfOrM193_COUNT (0+XfOrM192_COUNT)
#   define SETUP_XfOrM193(x) SETUP_XfOrM192(x)
    l = sizeof (here ) ; 
    if (FUNCCALL(SETUP_XfOrM193(_), getsockname (tcp -> tcp , (struct sockaddr * ) here , & l ) )) {
#     define XfOrM197_COUNT (0+XfOrM193_COUNT)
#     define SETUP_XfOrM197(x) SETUP_XfOrM193(x)
      FUNCCALL(SETUP_XfOrM197(_), scheme_raise_exn (MZEXN_FAIL_NETWORK , "tcp-addresses: could not get local address (%e)" , (* __errno_location () ) ) ); 
    }
    here_len = l ; 
    l = sizeof (there ) ; 
    if (FUNCCALL(SETUP_XfOrM193(_), getpeername (tcp -> tcp , (struct sockaddr * ) there , & l ) )) {
#     define XfOrM196_COUNT (0+XfOrM193_COUNT)
#     define SETUP_XfOrM196(x) SETUP_XfOrM193(x)
      FUNCCALL(SETUP_XfOrM196(_), scheme_raise_exn (MZEXN_FAIL_NETWORK , "tcp-addresses: could not get peer address (%e)" , (* __errno_location () ) ) ); 
    }
    there_len = l ; 
    FUNCCALL(SETUP_XfOrM193(_), scheme_getnameinfo ((struct sockaddr * ) here , here_len , host_buf , sizeof (host_buf ) , (with_ports ? svc_buf : ((void * ) 0 ) ) , (with_ports ? sizeof (svc_buf ) : 0 ) ) ); 
    result [0 ] = FUNCCALL(SETUP_XfOrM193(_), scheme_make_utf8_string (host_buf ) ); 
    if (with_ports ) {
#     define XfOrM195_COUNT (0+XfOrM193_COUNT)
#     define SETUP_XfOrM195(x) SETUP_XfOrM193(x)
      l = FUNCCALL(SETUP_XfOrM195(_), extract_svc_value (svc_buf ) ); 
      result [1 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (l ) ) << 1 ) | 0x1 ) ) ; 
    }
    FUNCCALL(SETUP_XfOrM193(_), scheme_getnameinfo ((struct sockaddr * ) there , there_len , host_buf , sizeof (host_buf ) , (with_ports ? svc_buf : ((void * ) 0 ) ) , (with_ports ? sizeof (svc_buf ) : 0 ) ) ); 
    result [with_ports ? 2 : 1 ] = FUNCCALL(SETUP_XfOrM193(_), scheme_make_utf8_string (host_buf ) ); 
    if (with_ports ) {
#     define XfOrM194_COUNT (0+XfOrM193_COUNT)
#     define SETUP_XfOrM194(x) SETUP_XfOrM193(x)
      l = FUNCCALL(SETUP_XfOrM194(_), extract_svc_value (svc_buf ) ); 
      result [3 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (l ) ) << 1 ) | 0x1 ) ) ; 
    }
  }
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM192(_), scheme_values (with_ports ? 4 : 2 , result ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * tcp_abandon_port (int argc , Scheme_Object * argv [] ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM200_COUNT (1)
# define SETUP_XfOrM200(x) SETUP(XfOrM200_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((scheme_is_output_port (argv [0 ] ) ) ) {
    Scheme_Output_Port * op ; 
    BLOCK_SETUP((PUSH(op, 0+XfOrM200_COUNT)));
#   define XfOrM204_COUNT (1+XfOrM200_COUNT)
#   define SETUP_XfOrM204(x) SETUP(XfOrM204_COUNT)
    op = NULLED_OUT ; 
    op = FUNCCALL(SETUP_XfOrM204(_), scheme_output_port_record (argv [0 ] ) ); 
    if (op -> sub_type == scheme_tcp_output_port_type ) {
#     define XfOrM205_COUNT (0+XfOrM204_COUNT)
#     define SETUP_XfOrM205(x) SETUP_XfOrM204(x)
      if (! op -> closed ) {
#       define XfOrM206_COUNT (0+XfOrM205_COUNT)
#       define SETUP_XfOrM206(x) SETUP_XfOrM205(x)
        ((Scheme_Tcp * ) op -> port_data ) -> flags |= 0x1 ; 
        FUNCCALL(SETUP_XfOrM206(_), scheme_close_output_port (argv [0 ] ) ); 
      }
      RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
    }
  }
  else if ((scheme_is_input_port (argv [0 ] ) ) ) {
    Scheme_Input_Port * ip ; 
    BLOCK_SETUP((PUSH(ip, 0+XfOrM200_COUNT)));
#   define XfOrM201_COUNT (1+XfOrM200_COUNT)
#   define SETUP_XfOrM201(x) SETUP(XfOrM201_COUNT)
    ip = NULLED_OUT ; 
    ip = FUNCCALL(SETUP_XfOrM201(_), scheme_input_port_record (argv [0 ] ) ); 
    if (ip -> sub_type == scheme_tcp_input_port_type ) {
#     define XfOrM202_COUNT (0+XfOrM201_COUNT)
#     define SETUP_XfOrM202(x) SETUP_XfOrM201(x)
      if (! ip -> closed ) {
#       define XfOrM203_COUNT (0+XfOrM202_COUNT)
#       define SETUP_XfOrM203(x) SETUP_XfOrM202(x)
        ((Scheme_Tcp * ) ip -> port_data ) -> flags |= 0x2 ; 
        FUNCCALL(SETUP_XfOrM203(_), scheme_close_input_port (argv [0 ] ) ); 
      }
      RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
    }
  }
  FUNCCALL_EMPTY(scheme_wrong_type ("tcp-abandon-port" , "tcp-port" , 0 , argc , argv ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * tcp_port_p (int argc , Scheme_Object * argv [] ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM207_COUNT (1)
# define SETUP_XfOrM207(x) SETUP(XfOrM207_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((scheme_is_output_port (argv [0 ] ) ) ) {
    Scheme_Output_Port * op ; 
    BLOCK_SETUP((PUSH(op, 0+XfOrM207_COUNT)));
#   define XfOrM210_COUNT (1+XfOrM207_COUNT)
#   define SETUP_XfOrM210(x) SETUP(XfOrM210_COUNT)
    op = NULLED_OUT ; 
    op = FUNCCALL(SETUP_XfOrM210(_), scheme_output_port_record (argv [0 ] ) ); 
    if (op -> sub_type == scheme_tcp_output_port_type ) {
      RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
    }
  }
  else if ((scheme_is_input_port (argv [0 ] ) ) ) {
    Scheme_Input_Port * ip ; 
    BLOCK_SETUP((PUSH(ip, 0+XfOrM207_COUNT)));
#   define XfOrM208_COUNT (1+XfOrM207_COUNT)
#   define SETUP_XfOrM208(x) SETUP(XfOrM208_COUNT)
    ip = NULLED_OUT ; 
    ip = FUNCCALL(SETUP_XfOrM208(_), scheme_input_port_record (argv [0 ] ) ); 
    if (ip -> sub_type == scheme_tcp_input_port_type ) {
      RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
    }
  }
  RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * tcp_accept_evt (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * r ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(r, 0), PUSH(argv, 1)));
# define XfOrM212_COUNT (2)
# define SETUP_XfOrM212(x) SETUP(XfOrM212_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  r = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_listener_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("tcp-accept-evt" , "tcp-listener" , 0 , argc , argv ) ); 
  r = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM212(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  r -> type = scheme_tcp_accept_evt_type ; 
  (((Scheme_Small_Object * ) (r ) ) -> u . ptr_val ) = argv [0 ] ; 
  RET_VALUE_START (r ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int tcp_check_accept_evt (Scheme_Object * ae , Scheme_Schedule_Info * sinfo ) {
  Scheme_Object * __funcarg40 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(sinfo, 0), PUSH(ae, 1)));
# define XfOrM213_COUNT (2)
# define SETUP_XfOrM213(x) SETUP(XfOrM213_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (FUNCCALL(SETUP_XfOrM213(_), tcp_check_accept ((((Scheme_Small_Object * ) (ae ) ) -> u . ptr_val ) ) )) {
    Scheme_Object * a [2 ] ; 
    BLOCK_SETUP((PUSHARRAY(a, 2, 0+XfOrM213_COUNT)));
#   define XfOrM214_COUNT (3+XfOrM213_COUNT)
#   define SETUP_XfOrM214(x) SETUP(XfOrM214_COUNT)
    a[0] = NULLED_OUT ; 
    a[1] = NULLED_OUT ; 
    a [0 ] = (((Scheme_Small_Object * ) (ae ) ) -> u . ptr_val ) ; 
    FUNCCALL(SETUP_XfOrM214(_), tcp_accept (1 , a ) ); 
    a [0 ] = scheme_current_thread -> ku . multiple . array [0 ] ; 
    a [1 ] = scheme_current_thread -> ku . multiple . array [1 ] ; 
    (__funcarg40 = FUNCCALL(SETUP_XfOrM214(_), scheme_build_list (2 , a ) ), FUNCCALL_AGAIN(scheme_set_sync_target (sinfo , __funcarg40 , ((void * ) 0 ) , ((void * ) 0 ) , 0 , 0 ) )) ; 
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void tcp_accept_evt_needs_wakeup (Scheme_Object * ae , void * fds ) {
  /* No conversion */
  tcp_accept_needs_wakeup ((((Scheme_Small_Object * ) (ae ) ) -> u . ptr_val ) , fds ) ; 
}
int scheme_get_port_socket (Scheme_Object * p , long * _s ) {
  tcp_t s = 0 ; 
  int s_ok = 0 ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(_s, 0), PUSH(p, 1)));
# define XfOrM216_COUNT (2)
# define SETUP_XfOrM216(x) SETUP(XfOrM216_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((scheme_is_output_port (p ) ) ) {
    Scheme_Output_Port * op ; 
    BLOCK_SETUP((PUSH(op, 0+XfOrM216_COUNT)));
#   define XfOrM221_COUNT (1+XfOrM216_COUNT)
#   define SETUP_XfOrM221(x) SETUP(XfOrM221_COUNT)
    op = NULLED_OUT ; 
    op = FUNCCALL(SETUP_XfOrM221(_), scheme_output_port_record (p ) ); 
    if (op -> sub_type == scheme_tcp_output_port_type ) {
      if (! op -> closed ) {
        s = ((Scheme_Tcp * ) op -> port_data ) -> tcp ; 
        s_ok = 1 ; 
      }
    }
  }
  else if ((scheme_is_input_port (p ) ) ) {
    Scheme_Input_Port * ip ; 
    BLOCK_SETUP((PUSH(ip, 0+XfOrM216_COUNT)));
#   define XfOrM218_COUNT (1+XfOrM216_COUNT)
#   define SETUP_XfOrM218(x) SETUP(XfOrM218_COUNT)
    ip = NULLED_OUT ; 
    ip = FUNCCALL(SETUP_XfOrM218(_), scheme_input_port_record (p ) ); 
    if (ip -> sub_type == scheme_tcp_input_port_type ) {
      if (! ip -> closed ) {
        s = ((Scheme_Tcp * ) ip -> port_data ) -> tcp ; 
        s_ok = 1 ; 
      }
    }
  }
  if (s_ok ) {
    * _s = (long ) s ; 
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_socket_to_ports (long s , const char * name , int takeover , Scheme_Object * * _inp , Scheme_Object * * _outp ) {
  Scheme_Tcp * tcp ; 
  Scheme_Object * v ; 
  PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(tcp, 0), PUSH(v, 1), PUSH(_inp, 2), PUSH(_outp, 3), PUSH(name, 4)));
# define XfOrM224_COUNT (5)
# define SETUP_XfOrM224(x) SETUP(XfOrM224_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  tcp = NULLED_OUT ; 
  v = NULLED_OUT ; 
  tcp = FUNCCALL(SETUP_XfOrM224(_), make_tcp_port_data (s , takeover ? 2 : 3 ) ); 
  v = FUNCCALL_AGAIN(make_tcp_input_port (tcp , name ) ); 
  * _inp = v ; 
  v = FUNCCALL(SETUP_XfOrM224(_), make_tcp_output_port (tcp , name ) ); 
  * _outp = v ; 
  if (takeover ) {
    scheme_file_open_count ++ ; 
    ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
typedef struct Scheme_UDP_Evt {
  Scheme_Object so ; 
  Scheme_UDP * udp ; 
  short for_read , with_addr ; 
  int offset , len ; 
  char * str ; 
  char * dest_addr ; 
  int dest_addr_len ; 
}
Scheme_UDP_Evt ; 
static int udp_close_it (Scheme_Object * _udp ) {
  Scheme_UDP * udp = (Scheme_UDP * ) _udp ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(udp, 0)));
# define XfOrM226_COUNT (1)
# define SETUP_XfOrM226(x) SETUP(XfOrM226_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (udp -> s != (- 1 ) ) {
#   define XfOrM227_COUNT (0+XfOrM226_COUNT)
#   define SETUP_XfOrM227(x) SETUP_XfOrM226(x)
    FUNCCALL(SETUP_XfOrM227(_), closesocket (udp -> s ) ); 
    udp -> s = (- 1 ) ; 
    FUNCCALL_EMPTY(scheme_remove_managed (udp -> mref , (Scheme_Object * ) udp ) ); 
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  RET_VALUE_START (1 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_udp (int argc , Scheme_Object * argv [] ) {
  Scheme_UDP * udp ; 
  tcp_t s ; 
  char * address = "" ; 
  unsigned short origid , id ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(address, 0), PUSH(udp, 1), PUSH(argv, 2)));
# define XfOrM228_COUNT (3)
# define SETUP_XfOrM228(x) SETUP(XfOrM228_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  udp = NULLED_OUT ; 
  ; 
  if ((argc > 0 ) && ! (((argv [0 ] ) ) == (scheme_false ) ) && ! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("udp-open-socket" , "string or #f" , 0 , argc , argv ) ); 
  if ((argc > 1 ) && ! (((argv [1 ] ) ) == (scheme_false ) ) && ! ((((long ) (argv [1 ] ) ) & 0x1 ) && ((((long ) (argv [1 ] ) ) >> 1 ) >= 1 ) && ((((long ) (argv [1 ] ) ) >> 1 ) <= 65535 ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("udp-open-socket" , "exact integer in [1, 65535]" " or #f" , 1 , argc , argv ) ); 
  if ((argc > 0 ) && (! (((argv [0 ] ) ) == (scheme_false ) ) ) ) {
    Scheme_Object * bs ; 
    BLOCK_SETUP((PUSH(bs, 0+XfOrM228_COUNT)));
#   define XfOrM235_COUNT (1+XfOrM228_COUNT)
#   define SETUP_XfOrM235(x) SETUP(XfOrM235_COUNT)
    bs = NULLED_OUT ; 
    bs = FUNCCALL(SETUP_XfOrM235(_), scheme_char_string_to_byte_string (argv [0 ] ) ); 
    address = (((Scheme_Simple_Object * ) (bs ) ) -> u . byte_str_val . string_val ) ; 
  }
  else address = ((void * ) 0 ) ; 
  if ((argc > 1 ) && (! (((argv [1 ] ) ) == (scheme_false ) ) ) )
    origid = (unsigned short ) (((long ) (argv [1 ] ) ) >> 1 ) ; 
  else origid = 0 ; 
  FUNCCALL(SETUP_XfOrM228(_), scheme_security_check_network ("udp-open-socket" , address , origid , 0 ) ); 
  FUNCCALL_AGAIN(scheme_custodian_check_available (((void * ) 0 ) , "udp-open-socket" , "network" ) ); 
  if (address || origid ) {
    int err ; 
    GC_CAN_IGNORE struct addrinfo * udp_bind_addr = ((void * ) 0 ) ; 
#   define XfOrM233_COUNT (0+XfOrM228_COUNT)
#   define SETUP_XfOrM233(x) SETUP_XfOrM228(x)
    if (! origid )
      origid = 1025 ; 
    id = origid ; 
    udp_bind_addr = FUNCCALL(SETUP_XfOrM233(_), scheme_get_host_address (address , id , & err , - 1 , 1 , 0 ) ); 
    if (! udp_bind_addr ) {
#     define XfOrM234_COUNT (0+XfOrM233_COUNT)
#     define SETUP_XfOrM234(x) SETUP_XfOrM233(x)
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_NETWORK , "udp-open-socket: can't resolve address: %s (%N)" , address ? address : "<unspec>" , 1 , err ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    s = socket (udp_bind_addr -> ai_family , udp_bind_addr -> ai_socktype , udp_bind_addr -> ai_protocol ) ; 
    FUNCCALL(SETUP_XfOrM233(_), freeaddrinfo (udp_bind_addr ) ); 
  }
  else {
    s = socket (2 , SOCK_DGRAM , 0 ) ; 
  }
  if (s == (- 1 ) ) {
    int errid ; 
#   define XfOrM231_COUNT (0+XfOrM228_COUNT)
#   define SETUP_XfOrM231(x) SETUP_XfOrM228(x)
    errid = (* __errno_location () ) ; 
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_NETWORK , "udp-open-socket: creation failed (%E)" , errid ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  udp = ((Scheme_UDP * ) FUNCCALL(SETUP_XfOrM228(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_UDP ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  udp -> so . type = scheme_udp_type ; 
  udp -> s = s ; 
  udp -> bound = 0 ; 
  udp -> connected = 0 ; 
  udp -> previous_from_addr = ((void * ) 0 ) ; 
  fcntl (s , 4 , 2048 ) ; 
  {
    int bc = 1 ; 
    setsockopt (s , 1 , 6 , & bc , sizeof (bc ) ) ; 
  }
  {
    Scheme_Custodian_Reference * mref ; 
    BLOCK_SETUP((PUSH(mref, 0+XfOrM228_COUNT)));
#   define XfOrM229_COUNT (1+XfOrM228_COUNT)
#   define SETUP_XfOrM229(x) SETUP(XfOrM229_COUNT)
    mref = NULLED_OUT ; 
    mref = FUNCCALL(SETUP_XfOrM229(_), scheme_add_managed (((void * ) 0 ) , (Scheme_Object * ) udp , (Scheme_Close_Custodian_Client * ) udp_close_it , ((void * ) 0 ) , 1 ) ); 
    udp -> mref = mref ; 
  }
  RET_VALUE_START ((Scheme_Object * ) udp ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * udp_close (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_udp_type ) ) )
    scheme_wrong_type ("udp-close" , "udp socket" , 0 , argc , argv ) ; 
  if (udp_close_it (argv [0 ] ) ) {
    scheme_raise_exn (MZEXN_FAIL_NETWORK , "udp-close: udp socket was already closed" ) ; 
    return ((void * ) 0 ) ; 
  }
  return scheme_void ; 
}
static Scheme_Object * udp_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_udp_type ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * udp_bound_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_udp_type ) ) )
    scheme_wrong_type ("udp-bound?" , "udp socket" , 0 , argc , argv ) ; 
  return (((Scheme_UDP * ) argv [0 ] ) -> bound ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * udp_connected_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_udp_type ) ) )
    scheme_wrong_type ("udp-connected?" , "udp socket" , 0 , argc , argv ) ; 
  return (((Scheme_UDP * ) argv [0 ] ) -> connected ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * udp_bind_or_connect (const char * name , int argc , Scheme_Object * argv [] , int do_bind ) {
  Scheme_UDP * udp ; 
  char * address = "" ; 
  unsigned short origid , id ; 
  GC_CAN_IGNORE struct addrinfo * udp_bind_addr ; 
  int errid , err ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(name, 0), PUSH(udp, 1), PUSH(address, 2), PUSH(argv, 3)));
# define XfOrM241_COUNT (4)
# define SETUP_XfOrM241(x) SETUP(XfOrM241_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  udp = NULLED_OUT ; 
  udp = (Scheme_UDP * ) argv [0 ] ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_udp_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type (name , "udp socket" , 0 , argc , argv ) ); 
  if (! (((argv [1 ] ) ) == (scheme_false ) ) && ! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type (name , "string or #f" , 1 , argc , argv ) ); 
  if ((do_bind || ! (((argv [2 ] ) ) == (scheme_false ) ) ) && ! ((((long ) (argv [2 ] ) ) & 0x1 ) && ((((long ) (argv [2 ] ) ) >> 1 ) >= 1 ) && ((((long ) (argv [2 ] ) ) >> 1 ) <= 65535 ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type (name , (do_bind ? "exact integer in [1, 65535]" : "exact integer in [1, 65535]" " or #f" ) , 2 , argc , argv ) ); 
  if ((! (((argv [1 ] ) ) == (scheme_false ) ) ) ) {
    Scheme_Object * bs ; 
    BLOCK_SETUP((PUSH(bs, 0+XfOrM241_COUNT)));
#   define XfOrM254_COUNT (1+XfOrM241_COUNT)
#   define SETUP_XfOrM254(x) SETUP(XfOrM254_COUNT)
    bs = NULLED_OUT ; 
    bs = FUNCCALL(SETUP_XfOrM254(_), scheme_char_string_to_byte_string (argv [1 ] ) ); 
    address = (((Scheme_Simple_Object * ) (bs ) ) -> u . byte_str_val . string_val ) ; 
  }
  else address = ((void * ) 0 ) ; 
  if ((! (((argv [2 ] ) ) == (scheme_false ) ) ) )
    origid = (unsigned short ) (((long ) (argv [2 ] ) ) >> 1 ) ; 
  else origid = 0 ; 
  if (! do_bind && ((! (((argv [1 ] ) ) == (scheme_false ) ) ) != (! (((argv [2 ] ) ) == (scheme_false ) ) ) ) ) {
#   define XfOrM253_COUNT (0+XfOrM241_COUNT)
#   define SETUP_XfOrM253(x) SETUP_XfOrM241(x)
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: last two arguments must be both #f or both non-#f, given: %V %V" , name , argv [1 ] , argv [2 ] ) ); 
  }
  FUNCCALL(SETUP_XfOrM241(_), scheme_security_check_network (name , address , origid , ! do_bind ) ); 
  if (udp -> s == (- 1 ) ) {
#   define XfOrM252_COUNT (0+XfOrM241_COUNT)
#   define SETUP_XfOrM252(x) SETUP_XfOrM241(x)
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_NETWORK , "%s: udp socket was already closed: %V" , name , udp ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (do_bind && udp -> bound ) {
#   define XfOrM251_COUNT (0+XfOrM241_COUNT)
#   define SETUP_XfOrM251(x) SETUP_XfOrM241(x)
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_NETWORK , "%s: udp socket is already bound: %V" , name , udp ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  id = origid ; 
  if (address || id )
    udp_bind_addr = FUNCCALL(SETUP_XfOrM241(_), scheme_get_host_address (address , id , & err , - 1 , do_bind , 0 ) ); 
  else udp_bind_addr = ((void * ) 0 ) ; 
  if (udp_bind_addr || ! origid ) {
#   define XfOrM243_COUNT (0+XfOrM241_COUNT)
#   define SETUP_XfOrM243(x) SETUP_XfOrM241(x)
    if (do_bind ) {
#     define XfOrM249_COUNT (0+XfOrM243_COUNT)
#     define SETUP_XfOrM249(x) SETUP_XfOrM243(x)
      if (! FUNCCALL(SETUP_XfOrM249(_), bind (udp -> s , udp_bind_addr -> ai_addr , udp_bind_addr -> ai_addrlen ) )) {
#       define XfOrM250_COUNT (0+XfOrM249_COUNT)
#       define SETUP_XfOrM250(x) SETUP_XfOrM249(x)
        udp -> bound = 1 ; 
        FUNCCALL(SETUP_XfOrM250(_), freeaddrinfo (udp_bind_addr ) ); 
        RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
      }
      errid = (* __errno_location () ) ; 
    }
    else {
      int ok = 1 ; 
#     define XfOrM244_COUNT (0+XfOrM243_COUNT)
#     define SETUP_XfOrM244(x) SETUP_XfOrM243(x)
      {
#       define XfOrM247_COUNT (0+XfOrM244_COUNT)
#       define SETUP_XfOrM247(x) SETUP_XfOrM244(x)
        if (udp_bind_addr )
          ok = ! connect (udp -> s , udp_bind_addr -> ai_addr , udp_bind_addr -> ai_addrlen ) ; 
        else {
          GC_CAN_IGNORE mz_unspec_address ua ; 
#         define XfOrM248_COUNT (0+XfOrM247_COUNT)
#         define SETUP_XfOrM248(x) SETUP_XfOrM247(x)
          ua . sin_family = 0 ; 
          ua . sin_port = 0 ; 
          (memset (& (ua . sin_addr ) , 0 , sizeof (ua . sin_addr ) ) ) ; 
          (memset (& (ua . sin_zero ) , 0 , sizeof (ua . sin_zero ) ) ) ; 
          ok = ! connect (udp -> s , (struct sockaddr * ) & ua , sizeof (ua ) ) ; 
        }
      }
      if (! ok )
        errid = (* __errno_location () ) ; 
      else errid = 0 ; 
      if (! ok && ((errid ) == 97 ) && ! origid ) {
        ok = 1 ; 
      }
      if (ok ) {
#       define XfOrM245_COUNT (0+XfOrM244_COUNT)
#       define SETUP_XfOrM245(x) SETUP_XfOrM244(x)
        if (origid )
          udp -> connected = 1 ; 
        else udp -> connected = 0 ; 
        if (udp_bind_addr )
          FUNCCALL(SETUP_XfOrM245(_), freeaddrinfo (udp_bind_addr ) ); 
        RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
      }
    }
    if (udp_bind_addr )
      FUNCCALL(SETUP_XfOrM243(_), freeaddrinfo (udp_bind_addr ) ); 
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_NETWORK , "%s: can't %s to port: %d on address: %s (%E)" , name , do_bind ? "bind" : "connect" , origid , address ? address : "#f" , errid ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM242_COUNT (0+XfOrM241_COUNT)
#   define SETUP_XfOrM242(x) SETUP_XfOrM241(x)
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_NETWORK , "%s: can't resolve address: %s (%N)" , name , address , 1 , err ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * udp_bind (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return udp_bind_or_connect ("udp-bind!" , argc , argv , 1 ) ; 
}
static Scheme_Object * udp_connect (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return udp_bind_or_connect ("udp-connect!" , argc , argv , 0 ) ; 
}
/* this far 2882 */
/* this far 2882 */
static int udp_check_send (Scheme_Object * _udp ) {
  Scheme_UDP * udp = (Scheme_UDP * ) _udp ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(udp, 0)));
# define XfOrM257_COUNT (1)
# define SETUP_XfOrM257(x) SETUP(XfOrM257_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (udp -> s == (- 1 ) )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  {
    static fd_set * writefds ; 
    static fd_set * exnfds ; 
    struct timeval time = {
      0 , 0 }
    ; 
    int sr ; 
#   define XfOrM258_COUNT (0+XfOrM257_COUNT)
#   define SETUP_XfOrM258(x) SETUP_XfOrM257(x)
    (writefds = (writefds ? (fd_set * ) FUNCCALL(SETUP_XfOrM258(_), scheme_init_fdset_array (writefds , 1 ) ): (fd_set * ) FUNCCALL(SETUP_XfOrM258(_), scheme_alloc_fdset_array (1 , 1 ) )) ) ; 
    (exnfds = (exnfds ? (fd_set * ) FUNCCALL(SETUP_XfOrM258(_), scheme_init_fdset_array (exnfds , 1 ) ): (fd_set * ) FUNCCALL(SETUP_XfOrM258(_), scheme_alloc_fdset_array (1 , 1 ) )) ) ; 
    FUNCCALL(SETUP_XfOrM258(_), scheme_fdzero (writefds ) ); 
    FUNCCALL_AGAIN(scheme_fdset (writefds , udp -> s ) ); 
    FUNCCALL_AGAIN(scheme_fdzero (exnfds ) ); 
    FUNCCALL_AGAIN(scheme_fdset (exnfds , udp -> s ) ); 
    do {
#     define XfOrM260_COUNT (0+XfOrM258_COUNT)
#     define SETUP_XfOrM260(x) SETUP_XfOrM258(x)
      sr = FUNCCALL(SETUP_XfOrM260(_), select (udp -> s + 1 , ((void * ) 0 ) , writefds , exnfds , & time ) ); 
    }
    while ((sr == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
    RET_VALUE_START (sr ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void udp_send_needs_wakeup (Scheme_Object * _udp , void * fds ) {
  Scheme_UDP * udp = (Scheme_UDP * ) _udp ; 
  void * fds1 , * fds2 ; 
  tcp_t s = udp -> s ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(fds2, 0), PUSH(fds1, 1), PUSH(fds, 2)));
# define XfOrM261_COUNT (3)
# define SETUP_XfOrM261(x) SETUP(XfOrM261_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  fds1 = NULLED_OUT ; 
  fds2 = NULLED_OUT ; 
  fds1 = FUNCCALL(SETUP_XfOrM261(_), scheme_get_fdset (fds , 1 ) ); 
  fds2 = FUNCCALL_AGAIN(scheme_get_fdset (fds , 2 ) ); 
  FUNCCALL_AGAIN(scheme_fdset ((fd_set * ) fds1 , s ) ); 
  FUNCCALL_EMPTY(scheme_fdset ((fd_set * ) fds2 , s ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_udp_send_it (const char * name , Scheme_UDP * udp , char * bstr , long start , long end , char * dest_addr , int dest_addr_len , int can_block ) {
  long x ; 
  int errid = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(name, 0), PUSH(udp, 1), PUSH(bstr, 2), PUSH(dest_addr, 3)));
# define XfOrM262_COUNT (4)
# define SETUP_XfOrM262(x) SETUP(XfOrM262_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  while (1 ) {
#   define XfOrM272_COUNT (0+XfOrM262_COUNT)
#   define SETUP_XfOrM272(x) SETUP_XfOrM262(x)
    if (udp -> s == (- 1 ) ) {
#     define XfOrM278_COUNT (0+XfOrM272_COUNT)
#     define SETUP_XfOrM278(x) SETUP_XfOrM272(x)
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_NETWORK , "%s: udp socket is closed: %V" , name , udp ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    if ((! dest_addr && ! udp -> connected ) || (dest_addr && udp -> connected ) ) {
#     define XfOrM277_COUNT (0+XfOrM272_COUNT)
#     define SETUP_XfOrM277(x) SETUP_XfOrM272(x)
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_NETWORK , "%s: udp socket is%s connected: %V" , name , dest_addr ? "" : " not" , udp ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    udp -> bound = 1 ; 
    if (dest_addr )
      x = FUNCCALL(SETUP_XfOrM272(_), sendto (udp -> s , bstr XFORM_OK_PLUS start , end - start , 0 , (struct sockaddr * ) dest_addr , dest_addr_len ) ); 
    else x = send (udp -> s , bstr XFORM_OK_PLUS start , end - start , 0 ) ; 
    if (x == - 1 ) {
#     define XfOrM274_COUNT (0+XfOrM272_COUNT)
#     define SETUP_XfOrM274(x) SETUP_XfOrM272(x)
      errid = (* __errno_location () ) ; 
      if (((errid == 11 ) || (errid == 11 ) || (errid == 115 ) || (errid == 114 ) ) ) {
#       define XfOrM275_COUNT (0+XfOrM274_COUNT)
#       define SETUP_XfOrM275(x) SETUP_XfOrM274(x)
        if (can_block ) {
#         define XfOrM276_COUNT (0+XfOrM275_COUNT)
#         define SETUP_XfOrM276(x) SETUP_XfOrM275(x)
          FUNCCALL(SETUP_XfOrM276(_), scheme_block_until (udp_check_send , udp_send_needs_wakeup , (Scheme_Object * ) udp , 0 ) ); 
        }
        else RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      }
      else if (errid != 4 )
        break ; 
    }
    else if (x != (end - start ) ) {
#     define XfOrM273_COUNT (0+XfOrM272_COUNT)
#     define SETUP_XfOrM273(x) SETUP_XfOrM272(x)
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_NETWORK , "%s: didn't send enough (%d != %d)" , name , x , end - start ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else break ; 
  }
  if (x > - 1 ) {
    RET_VALUE_START ((can_block ? scheme_void : scheme_true ) ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM263_COUNT (0+XfOrM262_COUNT)
#   define SETUP_XfOrM263(x) SETUP_XfOrM262(x)
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_NETWORK , "%s: send failed (%E)" , name , errid ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * udp_send_it (const char * name , int argc , Scheme_Object * argv [] , int with_addr , int can_block , Scheme_UDP_Evt * fill_evt ) {
  Scheme_UDP * udp ; 
  char * address = "" ; 
  long start , end ; 
  int delta , err ; 
  unsigned short origid , id ; 
  GC_CAN_IGNORE struct addrinfo * udp_dest_addr ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(name, 0), PUSH(udp, 1), PUSH(address, 2), PUSH(argv, 3), PUSH(fill_evt, 4)));
# define XfOrM279_COUNT (5)
# define SETUP_XfOrM279(x) SETUP(XfOrM279_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  udp = NULLED_OUT ; 
  udp = (Scheme_UDP * ) argv [0 ] ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_udp_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type (name , "udp socket" , 0 , argc , argv ) ); 
  if (with_addr ) {
#   define XfOrM287_COUNT (0+XfOrM279_COUNT)
#   define SETUP_XfOrM287(x) SETUP_XfOrM279(x)
    if (! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type (name , "string" , 1 , argc , argv ) ); 
    if (! ((((long ) (argv [2 ] ) ) & 0x1 ) && ((((long ) (argv [2 ] ) ) >> 1 ) >= 1 ) && ((((long ) (argv [2 ] ) ) >> 1 ) <= 65535 ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type (name , "exact integer in [1, 65535]" , 2 , argc , argv ) ); 
    delta = 0 ; 
  }
  else delta = - 2 ; 
  if (! ((Scheme_Type ) (((((long ) (argv [3 + delta ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [3 + delta ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type (name , "byte string" , 3 + delta , argc , argv ) ); 
  FUNCCALL(SETUP_XfOrM279(_), scheme_get_substring_indices (name , argv [3 + delta ] , argc , argv , 4 + delta , 5 + delta , & start , & end ) ); 
  if (with_addr ) {
    Scheme_Object * bs ; 
    BLOCK_SETUP((PUSH(bs, 0+XfOrM279_COUNT)));
#   define XfOrM286_COUNT (1+XfOrM279_COUNT)
#   define SETUP_XfOrM286(x) SETUP(XfOrM286_COUNT)
    bs = NULLED_OUT ; 
    bs = FUNCCALL(SETUP_XfOrM286(_), scheme_char_string_to_byte_string (argv [1 ] ) ); 
    address = (((Scheme_Simple_Object * ) (bs ) ) -> u . byte_str_val . string_val ) ; 
    origid = (unsigned short ) (((long ) (argv [2 ] ) ) >> 1 ) ; 
    FUNCCALL(SETUP_XfOrM286(_), scheme_security_check_network (name , address , origid , 1 ) ); 
    id = origid ; 
  }
  else {
    address = ((void * ) 0 ) ; 
    id = origid = 0 ; 
  }
  if (with_addr )
    udp_dest_addr = FUNCCALL(SETUP_XfOrM279(_), scheme_get_host_address (address , id , & err , - 1 , 0 , 0 ) ); 
  else udp_dest_addr = ((void * ) 0 ) ; 
  if (! with_addr || udp_dest_addr ) {
#   define XfOrM281_COUNT (0+XfOrM279_COUNT)
#   define SETUP_XfOrM281(x) SETUP_XfOrM279(x)
    if (fill_evt ) {
      char * s ; 
      BLOCK_SETUP((PUSH(s, 0+XfOrM281_COUNT)));
#     define XfOrM283_COUNT (1+XfOrM281_COUNT)
#     define SETUP_XfOrM283(x) SETUP(XfOrM283_COUNT)
      s = NULLED_OUT ; 
      fill_evt -> str = (((Scheme_Simple_Object * ) (argv [3 + delta ] ) ) -> u . byte_str_val . string_val ) ; 
      fill_evt -> offset = start ; 
      fill_evt -> len = end - start ; 
      if (udp_dest_addr ) {
#       define XfOrM284_COUNT (0+XfOrM283_COUNT)
#       define SETUP_XfOrM284(x) SETUP_XfOrM283(x)
        s = (char * ) FUNCCALL(SETUP_XfOrM284(_), GC_malloc_atomic (udp_dest_addr -> ai_addrlen ) ); 
        (memcpy (s , udp_dest_addr -> ai_addr , udp_dest_addr -> ai_addrlen ) ) ; 
        fill_evt -> dest_addr = s ; 
        fill_evt -> dest_addr_len = udp_dest_addr -> ai_addrlen ; 
        FUNCCALL(SETUP_XfOrM284(_), freeaddrinfo (udp_dest_addr ) ); 
      }
      RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
    }
    else {
      Scheme_Object * r ; 
      BLOCK_SETUP((PUSH(r, 0+XfOrM281_COUNT)));
#     define XfOrM282_COUNT (1+XfOrM281_COUNT)
#     define SETUP_XfOrM282(x) SETUP(XfOrM282_COUNT)
      r = NULLED_OUT ; 
      r = FUNCCALL(SETUP_XfOrM282(_), do_udp_send_it (name , udp , (((Scheme_Simple_Object * ) (argv [3 + delta ] ) ) -> u . byte_str_val . string_val ) , start , end , (udp_dest_addr ? (char * ) udp_dest_addr -> ai_addr : ((void * ) 0 ) ) , (udp_dest_addr ? udp_dest_addr -> ai_addrlen : 0 ) , can_block ) ); 
      if (udp_dest_addr )
        FUNCCALL(SETUP_XfOrM282(_), freeaddrinfo (udp_dest_addr ) ); 
      RET_VALUE_START (r ) RET_VALUE_END ; 
    }
  }
  else {
#   define XfOrM280_COUNT (0+XfOrM279_COUNT)
#   define SETUP_XfOrM280(x) SETUP_XfOrM279(x)
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_NETWORK , "%s: can't resolve address: %s (%N)" , name , address , 1 , err ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * udp_send_to (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return udp_send_it ("udp-send-to" , argc , argv , 1 , 1 , ((void * ) 0 ) ) ; 
}
static Scheme_Object * udp_send (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return udp_send_it ("udp-send" , argc , argv , 0 , 1 , ((void * ) 0 ) ) ; 
}
static Scheme_Object * udp_send_to_star (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return udp_send_it ("udp-send-to*" , argc , argv , 1 , 0 , ((void * ) 0 ) ) ; 
}
static Scheme_Object * udp_send_star (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return udp_send_it ("udp-send*" , argc , argv , 0 , 0 , ((void * ) 0 ) ) ; 
}
static Scheme_Object * udp_send_to_enable_break (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_call_enable_break (udp_send_to , argc , argv ) ; 
}
static Scheme_Object * udp_send_enable_break (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_call_enable_break (udp_send , argc , argv ) ; 
}
/* this far 3114 */
/* this far 3114 */
static int udp_check_recv (Scheme_Object * _udp ) {
  Scheme_UDP * udp = (Scheme_UDP * ) _udp ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(udp, 0)));
# define XfOrM294_COUNT (1)
# define SETUP_XfOrM294(x) SETUP(XfOrM294_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (udp -> s == (- 1 ) )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  {
    static fd_set * readfds ; 
    static fd_set * exnfds ; 
    struct timeval time = {
      0 , 0 }
    ; 
    int sr ; 
#   define XfOrM295_COUNT (0+XfOrM294_COUNT)
#   define SETUP_XfOrM295(x) SETUP_XfOrM294(x)
    (readfds = (readfds ? (fd_set * ) FUNCCALL(SETUP_XfOrM295(_), scheme_init_fdset_array (readfds , 1 ) ): (fd_set * ) FUNCCALL(SETUP_XfOrM295(_), scheme_alloc_fdset_array (1 , 1 ) )) ) ; 
    (exnfds = (exnfds ? (fd_set * ) FUNCCALL(SETUP_XfOrM295(_), scheme_init_fdset_array (exnfds , 1 ) ): (fd_set * ) FUNCCALL(SETUP_XfOrM295(_), scheme_alloc_fdset_array (1 , 1 ) )) ) ; 
    FUNCCALL(SETUP_XfOrM295(_), scheme_fdzero (readfds ) ); 
    FUNCCALL_AGAIN(scheme_fdset (readfds , udp -> s ) ); 
    FUNCCALL_AGAIN(scheme_fdzero (exnfds ) ); 
    FUNCCALL_AGAIN(scheme_fdset (exnfds , udp -> s ) ); 
    do {
#     define XfOrM297_COUNT (0+XfOrM295_COUNT)
#     define SETUP_XfOrM297(x) SETUP_XfOrM295(x)
      sr = FUNCCALL(SETUP_XfOrM297(_), select (udp -> s + 1 , readfds , ((void * ) 0 ) , exnfds , & time ) ); 
    }
    while ((sr == - 1 ) && ((* __errno_location () ) == 4 ) ) ; 
    RET_VALUE_START (sr ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void udp_recv_needs_wakeup (Scheme_Object * _udp , void * fds ) {
  Scheme_UDP * udp = (Scheme_UDP * ) _udp ; 
  void * fds1 , * fds2 ; 
  tcp_t s = udp -> s ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(fds2, 0), PUSH(fds1, 1), PUSH(fds, 2)));
# define XfOrM298_COUNT (3)
# define SETUP_XfOrM298(x) SETUP(XfOrM298_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  fds1 = NULLED_OUT ; 
  fds2 = NULLED_OUT ; 
  fds1 = FUNCCALL(SETUP_XfOrM298(_), scheme_get_fdset (fds , 0 ) ); 
  fds2 = FUNCCALL_AGAIN(scheme_get_fdset (fds , 2 ) ); 
  FUNCCALL_AGAIN(scheme_fdset ((fd_set * ) fds1 , s ) ); 
  FUNCCALL_EMPTY(scheme_fdset ((fd_set * ) fds2 , s ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int do_udp_recv (const char * name , Scheme_UDP * udp , char * bstr , long start , long end , int can_block , Scheme_Object * * v ) {
  long x ; 
  int errid = 0 ; 
  char src_addr [256 ] ; 
  unsigned int asize = sizeof (src_addr ) ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(name, 1), PUSH(udp, 2), PUSH(bstr, 3)));
# define XfOrM299_COUNT (4)
# define SETUP_XfOrM299(x) SETUP(XfOrM299_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! udp -> bound ) {
#   define XfOrM323_COUNT (0+XfOrM299_COUNT)
#   define SETUP_XfOrM323(x) SETUP_XfOrM299(x)
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_NETWORK , "%s: udp socket is not bound: %V" , name , udp ) ); 
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  while (1 ) {
#   define XfOrM315_COUNT (0+XfOrM299_COUNT)
#   define SETUP_XfOrM315(x) SETUP_XfOrM299(x)
    if (udp -> s == (- 1 ) ) {
#     define XfOrM322_COUNT (0+XfOrM315_COUNT)
#     define SETUP_XfOrM322(x) SETUP_XfOrM315(x)
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_NETWORK , "%s: udp socket is closed: %V" , name , udp ) ); 
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    {
#     define XfOrM321_COUNT (0+XfOrM315_COUNT)
#     define SETUP_XfOrM321(x) SETUP_XfOrM315(x)
      x = FUNCCALL(SETUP_XfOrM321(_), recvfrom (udp -> s , bstr XFORM_OK_PLUS start , end - start , 0 , (struct sockaddr * ) src_addr , & asize ) ); 
    }
    if (x == - 1 ) {
#     define XfOrM316_COUNT (0+XfOrM315_COUNT)
#     define SETUP_XfOrM316(x) SETUP_XfOrM315(x)
      errid = (* __errno_location () ) ; 
      if (0 ) {
        x = end - start ; 
        errid = 0 ; 
      }
      if (((errid == 11 ) || (errid == 11 ) || (errid == 115 ) || (errid == 114 ) ) ) {
#       define XfOrM317_COUNT (0+XfOrM316_COUNT)
#       define SETUP_XfOrM317(x) SETUP_XfOrM316(x)
        if (can_block ) {
#         define XfOrM319_COUNT (0+XfOrM317_COUNT)
#         define SETUP_XfOrM319(x) SETUP_XfOrM317(x)
          FUNCCALL(SETUP_XfOrM319(_), scheme_block_until (udp_check_recv , udp_recv_needs_wakeup , (Scheme_Object * ) udp , 0 ) ); 
        }
        else {
          v [0 ] = scheme_false ; 
          v [1 ] = scheme_false ; 
          v [2 ] = scheme_false ; 
          RET_VALUE_START (0 ) RET_VALUE_END ; 
        }
      }
      else if (errid != 4 )
        break ; 
    }
    else break ; 
  }
  if (x > - 1 ) {
    char host_buf [64 ] ; 
    char prev_buf [64 ] ; 
    char svc_buf [32 ] ; 
    int j , id ; 
#   define XfOrM301_COUNT (0+XfOrM299_COUNT)
#   define SETUP_XfOrM301(x) SETUP_XfOrM299(x)
    v [0 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (x ) ) << 1 ) | 0x1 ) ) ; 
    FUNCCALL(SETUP_XfOrM301(_), scheme_getnameinfo ((struct sockaddr * ) src_addr , asize , host_buf , sizeof (host_buf ) , svc_buf , sizeof (svc_buf ) ) ); 
    if (udp -> previous_from_addr ) {
      mzchar * s ; 
      s = NULLED_OUT ; 
      s = (((Scheme_Simple_Object * ) (udp -> previous_from_addr ) ) -> u . char_str_val . string_val ) ; 
      for (j = 0 ; s [j ] ; j ++ ) {
        prev_buf [j ] = (char ) s [j ] ; 
      }
      prev_buf [j ] = 0 ; 
    }
    if (udp -> previous_from_addr && ! (strcmp (prev_buf , host_buf ) ) ) {
      v [1 ] = udp -> previous_from_addr ; 
    }
    else {
      Scheme_Object * vv ; 
      BLOCK_SETUP((PUSH(vv, 0+XfOrM301_COUNT)));
#     define XfOrM302_COUNT (1+XfOrM301_COUNT)
#     define SETUP_XfOrM302(x) SETUP(XfOrM302_COUNT)
      vv = NULLED_OUT ; 
      vv = FUNCCALL(SETUP_XfOrM302(_), scheme_make_immutable_sized_utf8_string (host_buf , - 1 ) ); 
      v [1 ] = vv ; 
      udp -> previous_from_addr = v [1 ] ; 
    }
    id = FUNCCALL(SETUP_XfOrM301(_), extract_svc_value (svc_buf ) ); 
    v [2 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (id ) ) << 1 ) | 0x1 ) ) ; 
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM300_COUNT (0+XfOrM299_COUNT)
#   define SETUP_XfOrM300(x) SETUP_XfOrM299(x)
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_NETWORK , "%s: receive failed (%E)" , name , errid ) ); 
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * udp_recv (const char * name , int argc , Scheme_Object * argv [] , int can_block , Scheme_UDP_Evt * fill_evt ) {
  Scheme_UDP * udp ; 
  long start , end ; 
  Scheme_Object * v [3 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSHARRAY(v, 3, 0), PUSH(name, 3), PUSH(udp, 4), PUSH(argv, 5), PUSH(fill_evt, 6)));
# define XfOrM324_COUNT (7)
# define SETUP_XfOrM324(x) SETUP(XfOrM324_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  udp = NULLED_OUT ; 
  v[0] = NULLED_OUT ; 
  v[1] = NULLED_OUT ; 
  v[2] = NULLED_OUT ; 
  udp = (Scheme_UDP * ) argv [0 ] ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_udp_type ) ) )
    FUNCCALL(SETUP_XfOrM324(_), scheme_wrong_type (name , "udp socket" , 0 , argc , argv ) ); 
  if (! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) || ! (! (((Scheme_Inclhash_Object * ) (argv [1 ] ) ) -> so . keyex & 0x1 ) ) )
    FUNCCALL(SETUP_XfOrM324(_), scheme_wrong_type (name , "mutable byte string" , 1 , argc , argv ) ); 
  FUNCCALL(SETUP_XfOrM324(_), scheme_get_substring_indices (name , argv [1 ] , argc , argv , 2 , 3 , & start , & end ) ); 
  if (fill_evt ) {
    fill_evt -> str = (((Scheme_Simple_Object * ) (argv [1 ] ) ) -> u . byte_str_val . string_val ) ; 
    fill_evt -> offset = start ; 
    fill_evt -> len = end - start ; 
    RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM325_COUNT (0+XfOrM324_COUNT)
#   define SETUP_XfOrM325(x) SETUP_XfOrM324(x)
    FUNCCALL(SETUP_XfOrM325(_), do_udp_recv (name , udp , (((Scheme_Simple_Object * ) (argv [1 ] ) ) -> u . byte_str_val . string_val ) , start , end , can_block , v ) ); 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM325(_), scheme_values (3 , v ) )) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * udp_receive (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return udp_recv ("udp-receive!" , argc , argv , 1 , ((void * ) 0 ) ) ; 
}
static Scheme_Object * udp_receive_star (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return udp_recv ("udp-receive!*" , argc , argv , 0 , ((void * ) 0 ) ) ; 
}
static Scheme_Object * udp_receive_enable_break (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_call_enable_break (udp_receive , argc , argv ) ; 
}
static Scheme_Object * make_udp_evt (const char * name , int argc , Scheme_Object * * argv , int for_read ) {
  Scheme_UDP_Evt * uw ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(uw, 0), PUSH(argv, 1)));
# define XfOrM330_COUNT (2)
# define SETUP_XfOrM330(x) SETUP(XfOrM330_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  uw = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_udp_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type (name , "udp socket" , 0 , argc , argv ) ); 
  uw = ((Scheme_UDP_Evt * ) FUNCCALL(SETUP_XfOrM330(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_UDP_Evt ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  uw -> so . type = scheme_udp_evt_type ; 
  uw -> udp = (Scheme_UDP * ) argv [0 ] ; 
  uw -> for_read = for_read ; 
  RET_VALUE_START ((Scheme_Object * ) uw ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * udp_read_ready_evt (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return make_udp_evt ("udp-receive-ready-evt" , argc , argv , 1 ) ; 
}
static Scheme_Object * udp_write_ready_evt (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return make_udp_evt ("udp-send-ready-evt" , argc , argv , 0 ) ; 
}
static Scheme_Object * udp_read_evt (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * evt ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(evt, 0), PUSH(argv, 1)));
# define XfOrM333_COUNT (2)
# define SETUP_XfOrM333(x) SETUP(XfOrM333_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  evt = NULLED_OUT ; 
  evt = FUNCCALL(SETUP_XfOrM333(_), make_udp_evt ("udp-receive!-evt" , argc , argv , 1 ) ); 
  FUNCCALL_AGAIN(udp_recv ("udp-receive!-evt" , argc , argv , 0 , (Scheme_UDP_Evt * ) evt ) ); 
  RET_VALUE_START (evt ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * udp_write_evt (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * evt ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(evt, 0), PUSH(argv, 1)));
# define XfOrM334_COUNT (2)
# define SETUP_XfOrM334(x) SETUP(XfOrM334_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  evt = NULLED_OUT ; 
  evt = FUNCCALL(SETUP_XfOrM334(_), make_udp_evt ("udp-send-evt" , argc , argv , 0 ) ); 
  FUNCCALL_AGAIN(udp_send_it ("udp-send-evt" , argc , argv , 0 , 0 , (Scheme_UDP_Evt * ) evt ) ); 
  RET_VALUE_START (evt ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * udp_write_to_evt (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * evt ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(evt, 0), PUSH(argv, 1)));
# define XfOrM335_COUNT (2)
# define SETUP_XfOrM335(x) SETUP(XfOrM335_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  evt = NULLED_OUT ; 
  evt = FUNCCALL(SETUP_XfOrM335(_), make_udp_evt ("udp-send-to-evt" , argc , argv , 0 ) ); 
  FUNCCALL_AGAIN(udp_send_it ("udp-send-to-evt" , argc , argv , 1 , 0 , (Scheme_UDP_Evt * ) evt ) ); 
  ((Scheme_UDP_Evt * ) evt ) -> with_addr = 1 ; 
  RET_VALUE_START (evt ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int udp_evt_check_ready (Scheme_Object * _uw , Scheme_Schedule_Info * sinfo ) {
  Scheme_UDP_Evt * uw = (Scheme_UDP_Evt * ) _uw ; 
  Scheme_Object * __funcarg41 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(sinfo, 0), PUSH(uw, 1)));
# define XfOrM336_COUNT (2)
# define SETUP_XfOrM336(x) SETUP(XfOrM336_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (uw -> for_read ) {
#   define XfOrM340_COUNT (0+XfOrM336_COUNT)
#   define SETUP_XfOrM340(x) SETUP_XfOrM336(x)
    if (uw -> str ) {
      Scheme_Object * v [3 ] ; 
      BLOCK_SETUP((PUSHARRAY(v, 3, 0+XfOrM340_COUNT)));
#     define XfOrM342_COUNT (3+XfOrM340_COUNT)
#     define SETUP_XfOrM342(x) SETUP(XfOrM342_COUNT)
      v[0] = NULLED_OUT ; 
      v[1] = NULLED_OUT ; 
      v[2] = NULLED_OUT ; 
      if (FUNCCALL(SETUP_XfOrM342(_), do_udp_recv ("udp-receive!-evt" , uw -> udp , uw -> str , uw -> offset , uw -> offset + uw -> len , 0 , v ) )) {
#       define XfOrM343_COUNT (0+XfOrM342_COUNT)
#       define SETUP_XfOrM343(x) SETUP_XfOrM342(x)
        (__funcarg41 = FUNCCALL(SETUP_XfOrM343(_), scheme_build_list (3 , v ) ), FUNCCALL_AGAIN(scheme_set_sync_target (sinfo , __funcarg41 , ((void * ) 0 ) , ((void * ) 0 ) , 0 , 0 ) )) ; 
        RET_VALUE_START (1 ) RET_VALUE_END ; 
      }
      else RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    else {
#     define XfOrM341_COUNT (0+XfOrM340_COUNT)
#     define SETUP_XfOrM341(x) SETUP_XfOrM340(x)
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(udp_check_recv ((Scheme_Object * ) uw -> udp ) )) RET_VALUE_EMPTY_END ; 
    }
  }
  else {
#   define XfOrM337_COUNT (0+XfOrM336_COUNT)
#   define SETUP_XfOrM337(x) SETUP_XfOrM336(x)
    if (uw -> str ) {
      Scheme_Object * r ; 
      BLOCK_SETUP((PUSH(r, 0+XfOrM337_COUNT)));
#     define XfOrM338_COUNT (1+XfOrM337_COUNT)
#     define SETUP_XfOrM338(x) SETUP(XfOrM338_COUNT)
      r = NULLED_OUT ; 
      r = FUNCCALL(SETUP_XfOrM338(_), do_udp_send_it ("udp-send-evt" , uw -> udp , uw -> str , uw -> offset , uw -> offset + uw -> len , uw -> dest_addr , uw -> dest_addr_len , 0 ) ); 
      if ((! (((r ) ) == (scheme_false ) ) ) ) {
#       define XfOrM339_COUNT (0+XfOrM338_COUNT)
#       define SETUP_XfOrM339(x) SETUP_XfOrM338(x)
        FUNCCALL(SETUP_XfOrM339(_), scheme_set_sync_target (sinfo , scheme_void , ((void * ) 0 ) , ((void * ) 0 ) , 0 , 0 ) ); 
        RET_VALUE_START (1 ) RET_VALUE_END ; 
      }
      else RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(udp_check_send ((Scheme_Object * ) uw -> udp ) )) RET_VALUE_EMPTY_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void udp_evt_needs_wakeup (Scheme_Object * _uw , void * fds ) {
  Scheme_UDP_Evt * uw = (Scheme_UDP_Evt * ) _uw ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(fds, 0), PUSH(uw, 1)));
# define XfOrM344_COUNT (2)
# define SETUP_XfOrM344(x) SETUP(XfOrM344_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (uw -> for_read )
    FUNCCALL(SETUP_XfOrM344(_), udp_recv_needs_wakeup ((Scheme_Object * ) uw -> udp , fds ) ); 
  else FUNCCALL_EMPTY(udp_send_needs_wakeup ((Scheme_Object * ) uw -> udp , fds ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int mark_listener_SIZE (void * p ) {
  listener_t * l = (listener_t * ) p ; 
  return ((sizeof (listener_t ) + ((l -> count - 1 ) * sizeof (tcp_t ) ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_listener_MARK (void * p ) {
  listener_t * l = (listener_t * ) p ; 
  GC_mark (l -> mref ) ; 
  return ((sizeof (listener_t ) + ((l -> count - 1 ) * sizeof (tcp_t ) ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_listener_FIXUP (void * p ) {
  listener_t * l = (listener_t * ) p ; 
  GC_fixup (& (l -> mref ) ) ; 
  return ((sizeof (listener_t ) + ((l -> count - 1 ) * sizeof (tcp_t ) ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_tcp_SIZE (void * p ) {
  return ((sizeof (Scheme_Tcp ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_tcp_MARK (void * p ) {
  Scheme_Tcp * tcp = (Scheme_Tcp * ) p ; 
  GC_mark (tcp -> b . buffer ) ; 
  GC_mark (tcp -> b . out_buffer ) ; 
  return ((sizeof (Scheme_Tcp ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_tcp_FIXUP (void * p ) {
  Scheme_Tcp * tcp = (Scheme_Tcp * ) p ; 
  GC_fixup (& (tcp -> b . buffer ) ) ; 
  GC_fixup (& (tcp -> b . out_buffer ) ) ; 
  return ((sizeof (Scheme_Tcp ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_udp_SIZE (void * p ) {
  return ((sizeof (Scheme_UDP ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_udp_MARK (void * p ) {
  Scheme_UDP * udp = (Scheme_UDP * ) p ; 
  GC_mark (udp -> previous_from_addr ) ; 
  GC_mark (udp -> mref ) ; 
  return ((sizeof (Scheme_UDP ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_udp_FIXUP (void * p ) {
  Scheme_UDP * udp = (Scheme_UDP * ) p ; 
  GC_fixup (& (udp -> previous_from_addr ) ) ; 
  GC_fixup (& (udp -> mref ) ) ; 
  return ((sizeof (Scheme_UDP ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_udp_evt_SIZE (void * p ) {
  return ((sizeof (Scheme_UDP_Evt ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_udp_evt_MARK (void * p ) {
  Scheme_UDP_Evt * uw = (Scheme_UDP_Evt * ) p ; 
  GC_mark (uw -> udp ) ; 
  GC_mark (uw -> str ) ; 
  GC_mark (uw -> dest_addr ) ; 
  return ((sizeof (Scheme_UDP_Evt ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_udp_evt_FIXUP (void * p ) {
  Scheme_UDP_Evt * uw = (Scheme_UDP_Evt * ) p ; 
  GC_fixup (& (uw -> udp ) ) ; 
  GC_fixup (& (uw -> str ) ) ; 
  GC_fixup (& (uw -> dest_addr ) ) ; 
  return ((sizeof (Scheme_UDP_Evt ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static void register_traversers (void ) {
  GC_register_traversers (scheme_rt_tcp , mark_tcp_SIZE , mark_tcp_MARK , mark_tcp_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_udp_type , mark_udp_SIZE , mark_udp_MARK , mark_udp_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_udp_evt_type , mark_udp_evt_SIZE , mark_udp_evt_MARK , mark_udp_evt_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_listener_type , mark_listener_SIZE , mark_listener_MARK , mark_listener_FIXUP , 0 , 0 ) ; 
}
