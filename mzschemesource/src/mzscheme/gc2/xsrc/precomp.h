#define GC_VARIABLE_STACK GC_variable_stack
#define GET_GC_VARIABLE_STACK() GC_VARIABLE_STACK
#define SET_GC_VARIABLE_STACK(v) (GC_VARIABLE_STACK = (v))
#define PREPARE_VAR_STACK(size) void *__gc_var_stack__[size+2]; __gc_var_stack__[0] = GET_GC_VARIABLE_STACK(); SET_GC_VARIABLE_STACK(__gc_var_stack__);
#define PREPARE_VAR_STACK_ONCE(size) PREPARE_VAR_STACK(size); __gc_var_stack__[1] = (void *)size;
#define SETUP(x) (__gc_var_stack__[1] = (void *)x)
#ifdef MZ_3M_CHECK_VAR_STACK
static int _bad_var_stack_() { *(long *)0x0 = 1; return 0; }
# define CHECK_GC_V_S ((GC_VARIABLE_STACK == __gc_var_stack__) ? 0 : _bad_var_stack_()),
#else
# define CHECK_GC_V_S /*empty*/
#endif
#define FUNCCALL_each(setup, x) (CHECK_GC_V_S setup, x)
#define FUNCCALL_EMPTY_each(x) (SET_GC_VARIABLE_STACK((void **)__gc_var_stack__[0]), x)
#define FUNCCALL_AGAIN_each(x) (CHECK_GC_V_S x)
#define FUNCCALL_once(setup, x) FUNCCALL_AGAIN_each(x)
#define FUNCCALL_EMPTY_once(x) FUNCCALL_EMPTY_each(x)
#define FUNCCALL_AGAIN_once(x) FUNCCALL_AGAIN_each(x)
#define PUSH(v, x) (__gc_var_stack__[x+2] = (void *)&(v))
#define PUSHARRAY(v, l, x) (__gc_var_stack__[x+2] = (void *)0, __gc_var_stack__[x+3] = (void *)&(v), __gc_var_stack__[x+4] = (void *)l)
#define BLOCK_SETUP_TOP(x) x
#define BLOCK_SETUP_each(x) BLOCK_SETUP_TOP(x)
#define BLOCK_SETUP_once(x) /* no effect */
#define RET_VALUE_START return (__ret__val__ = 
#define RET_VALUE_END , SET_GC_VARIABLE_STACK((void **)__gc_var_stack__[0]), __ret__val__)
#define RET_VALUE_EMPTY_START return
#define RET_VALUE_EMPTY_END 
#define RET_NOTHING { SET_GC_VARIABLE_STACK((void **)__gc_var_stack__[0]); return; }
#define RET_NOTHING_AT_END RET_NOTHING
#define DECL_RET_SAVE(type) type __ret__val__;
#define NULLED_OUT 0
#define NULL_OUT_ARRAY(a) memset(a, 0, sizeof(a))
#define GC_CAN_IGNORE /**/
#define __xform_nongcing__ /**/
#define HIDE_FROM_XFORM(x) x
#define XFORM_HIDE_EXPR(x) x
#define HIDE_NOTHING_FROM_XFORM() /**/
#define START_XFORM_SKIP /**/
#define END_XFORM_SKIP /**/
#define START_XFORM_SUSPEND /**/
#define END_XFORM_SUSPEND /**/
#define XFORM_START_SKIP /**/
#define XFORM_END_SKIP /**/
#define XFORM_START_SUSPEND /**/
#define XFORM_END_SUSPEND /**/
#define XFORM_OK_PLUS +
#define XFORM_OK_MINUS -
#define XFORM_TRUST_PLUS +
#define XFORM_TRUST_MINUS -

#define NEW_OBJ(t) new (UseGC) t
#define NEW_ARRAY(t, array) (new (UseGC) t array)
#define NEW_ATOM(t) (new (AtomicGC) t)
#define NEW_PTR(t) (new (UseGC) t)
#define NEW_ATOM_ARRAY(t, array) (new (AtomicGC) t array)
#define NEW_PTR_ARRAY(t, array) (new (UseGC) t* array)
#define DELETE(x) (delete x)
#define DELETE_ARRAY(x) (delete[] x)
#define XFORM_RESET_VAR_STACK /* empty */

typedef long unsigned int size_t ; 
typedef unsigned char __u_char ; 
typedef unsigned short int __u_short ; 
typedef unsigned int __u_int ; 
typedef unsigned long int __u_long ; 
typedef signed char __int8_t ; 
typedef unsigned char __uint8_t ; 
typedef signed short int __int16_t ; 
typedef unsigned short int __uint16_t ; 
typedef signed int __int32_t ; 
typedef unsigned int __uint32_t ; 
typedef signed long int __int64_t ; 
typedef unsigned long int __uint64_t ; 
typedef long int __quad_t ; 
typedef unsigned long int __u_quad_t ; 
typedef unsigned long int __dev_t ; 
typedef unsigned int __uid_t ; 
typedef unsigned int __gid_t ; 
typedef unsigned long int __ino_t ; 
typedef unsigned long int __ino64_t ; 
typedef unsigned int __mode_t ; 
typedef unsigned long int __nlink_t ; 
typedef long int __off_t ; 
typedef long int __off64_t ; 
typedef int __pid_t ; 
typedef struct {
  int __val [2 ] ; 
}
__fsid_t ; 
typedef long int __clock_t ; 
typedef unsigned long int __rlim_t ; 
typedef unsigned long int __rlim64_t ; 
typedef unsigned int __id_t ; 
typedef long int __time_t ; 
typedef unsigned int __useconds_t ; 
typedef long int __suseconds_t ; 
typedef int __daddr_t ; 
typedef long int __swblk_t ; 
typedef int __key_t ; 
typedef int __clockid_t ; 
typedef void * __timer_t ; 
typedef long int __blksize_t ; 
typedef long int __blkcnt_t ; 
typedef long int __blkcnt64_t ; 
typedef unsigned long int __fsblkcnt_t ; 
typedef unsigned long int __fsblkcnt64_t ; 
typedef unsigned long int __fsfilcnt_t ; 
typedef unsigned long int __fsfilcnt64_t ; 
typedef long int __ssize_t ; 
typedef __off64_t __loff_t ; 
typedef __quad_t * __qaddr_t ; 
typedef char * __caddr_t ; 
typedef long int __intptr_t ; 
typedef unsigned int __socklen_t ; 
typedef struct _IO_FILE FILE ; 
typedef struct _IO_FILE __FILE ; 
typedef int wchar_t ; 
typedef unsigned int wint_t ; 
typedef struct {
  int __count ; 
  union {
    wint_t __wch ; 
    char __wchb [4 ] ; 
  }
  __value ; 
}
__mbstate_t ; 
typedef struct {
  __off_t __pos ; 
  __mbstate_t __state ; 
}
_G_fpos_t ; 
typedef struct {
  __off64_t __pos ; 
  __mbstate_t __state ; 
}
_G_fpos64_t ; 
enum {
  __GCONV_OK = 0 , __GCONV_NOCONV , __GCONV_NODB , __GCONV_NOMEM , __GCONV_EMPTY_INPUT , __GCONV_FULL_OUTPUT , __GCONV_ILLEGAL_INPUT , __GCONV_INCOMPLETE_INPUT , __GCONV_ILLEGAL_DESCRIPTOR , __GCONV_INTERNAL_ERROR }
; 
enum {
  __GCONV_IS_LAST = 0x0001 , __GCONV_IGNORE_ERRORS = 0x0002 }
; 
struct __gconv_step ; 
struct __gconv_step_data ; 
struct __gconv_loaded_object ; 
struct __gconv_trans_data ; 
typedef int (* __gconv_fct ) (struct __gconv_step * , struct __gconv_step_data * , __const unsigned char * * , __const unsigned char * , unsigned char * * , size_t * , int , int ) ; 
typedef wint_t (* __gconv_btowc_fct ) (struct __gconv_step * , unsigned char ) ; 
typedef int (* __gconv_init_fct ) (struct __gconv_step * ) ; 
typedef void (* __gconv_end_fct ) (struct __gconv_step * ) ; 
typedef int (* __gconv_trans_fct ) (struct __gconv_step * , struct __gconv_step_data * , void * , __const unsigned char * , __const unsigned char * * , __const unsigned char * , unsigned char * * , size_t * ) ; 
typedef int (* __gconv_trans_context_fct ) (void * , __const unsigned char * , __const unsigned char * , unsigned char * , unsigned char * ) ; 
typedef int (* __gconv_trans_query_fct ) (__const char * , __const char * * * , size_t * ) ; 
typedef int (* __gconv_trans_init_fct ) (void * * , const char * ) ; 
typedef void (* __gconv_trans_end_fct ) (void * ) ; 
struct __gconv_trans_data {
  __gconv_trans_fct __trans_fct ; 
  __gconv_trans_context_fct __trans_context_fct ; 
  __gconv_trans_end_fct __trans_end_fct ; 
  void * __data ; 
  struct __gconv_trans_data * __next ; 
}
; 
struct __gconv_step {
  struct __gconv_loaded_object * __shlib_handle ; 
  __const char * __modname ; 
  int __counter ; 
  char * __from_name ; 
  char * __to_name ; 
  __gconv_fct __fct ; 
  __gconv_btowc_fct __btowc_fct ; 
  __gconv_init_fct __init_fct ; 
  __gconv_end_fct __end_fct ; 
  int __min_needed_from ; 
  int __max_needed_from ; 
  int __min_needed_to ; 
  int __max_needed_to ; 
  int __stateful ; 
  void * __data ; 
}
; 
struct __gconv_step_data {
  unsigned char * __outbuf ; 
  unsigned char * __outbufend ; 
  int __flags ; 
  int __invocation_counter ; 
  int __internal_use ; 
  __mbstate_t * __statep ; 
  __mbstate_t __state ; 
  struct __gconv_trans_data * __trans ; 
}
; 
typedef struct __gconv_info {
  size_t __nsteps ; 
  struct __gconv_step * __steps ; 
  __extension__ struct __gconv_step_data __data [] ; 
}
* __gconv_t ; 
typedef union {
  struct __gconv_info __cd ; 
  struct {
    struct __gconv_info __cd ; 
    struct __gconv_step_data __data ; 
  }
  __combined ; 
}
_G_iconv_t ; 
typedef int _G_int16_t __attribute__ ((__mode__ (__HI__ ) ) ) ; 
typedef int _G_int32_t __attribute__ ((__mode__ (__SI__ ) ) ) ; 
typedef unsigned int _G_uint16_t __attribute__ ((__mode__ (__HI__ ) ) ) ; 
typedef unsigned int _G_uint32_t __attribute__ ((__mode__ (__SI__ ) ) ) ; 
typedef __builtin_va_list __gnuc_va_list ; 
struct _IO_jump_t ; 
struct _IO_FILE ; 
typedef void _IO_lock_t ; 
struct _IO_marker {
  struct _IO_marker * _next ; 
  struct _IO_FILE * _sbuf ; 
  int _pos ; 
}
; 
enum __codecvt_result {
  __codecvt_ok , __codecvt_partial , __codecvt_error , __codecvt_noconv }
; 
struct _IO_FILE {
  int _flags ; 
  char * _IO_read_ptr ; 
  char * _IO_read_end ; 
  char * _IO_read_base ; 
  char * _IO_write_base ; 
  char * _IO_write_ptr ; 
  char * _IO_write_end ; 
  char * _IO_buf_base ; 
  char * _IO_buf_end ; 
  char * _IO_save_base ; 
  char * _IO_backup_base ; 
  char * _IO_save_end ; 
  struct _IO_marker * _markers ; 
  struct _IO_FILE * _chain ; 
  int _fileno ; 
  int _flags2 ; 
  __off_t _old_offset ; 
  unsigned short _cur_column ; 
  signed char _vtable_offset ; 
  char _shortbuf [1 ] ; 
  _IO_lock_t * _lock ; 
  __off64_t _offset ; 
  void * __pad1 ; 
  void * __pad2 ; 
  void * __pad3 ; 
  void * __pad4 ; 
  size_t __pad5 ; 
  int _mode ; 
  char _unused2 [15 * sizeof (int ) - 4 * sizeof (void * ) - sizeof (size_t ) ] ; 
}
; 
typedef struct _IO_FILE _IO_FILE ; 
struct _IO_FILE_plus ; 
extern struct _IO_FILE_plus _IO_2_1_stdin_ ; 
extern struct _IO_FILE_plus _IO_2_1_stdout_ ; 
extern struct _IO_FILE_plus _IO_2_1_stderr_ ; 
typedef __ssize_t __io_read_fn (void * __cookie , char * __buf , size_t __nbytes ) ; 
typedef __ssize_t __io_write_fn (void * __cookie , __const char * __buf , size_t __n ) ; 
typedef int __io_seek_fn (void * __cookie , __off64_t * __pos , int __w ) ; 
typedef int __io_close_fn (void * __cookie ) ; 
extern int __underflow (_IO_FILE * ) __attribute__ ((__nothrow__ ) ) ; 
extern int __uflow (_IO_FILE * ) __attribute__ ((__nothrow__ ) ) ; 
extern int __overflow (_IO_FILE * , int ) __attribute__ ((__nothrow__ ) ) ; 
extern wint_t __wunderflow (_IO_FILE * ) __attribute__ ((__nothrow__ ) ) ; 
extern wint_t __wuflow (_IO_FILE * ) __attribute__ ((__nothrow__ ) ) ; 
extern wint_t __woverflow (_IO_FILE * , wint_t ) __attribute__ ((__nothrow__ ) ) ; 
extern int _IO_getc (_IO_FILE * __fp ) __attribute__ ((__nothrow__ ) ) ; 
extern int _IO_putc (int __c , _IO_FILE * __fp ) __attribute__ ((__nothrow__ ) ) ; 
extern int _IO_feof (_IO_FILE * __fp ) __attribute__ ((__nothrow__ ) ) ; 
extern int _IO_ferror (_IO_FILE * __fp ) __attribute__ ((__nothrow__ ) ) ; 
extern int _IO_peekc_locked (_IO_FILE * __fp ) __attribute__ ((__nothrow__ ) ) ; 
extern void _IO_flockfile (_IO_FILE * ) __attribute__ ((__nothrow__ ) ) ; 
extern void _IO_funlockfile (_IO_FILE * ) __attribute__ ((__nothrow__ ) ) ; 
extern int _IO_ftrylockfile (_IO_FILE * ) __attribute__ ((__nothrow__ ) ) ; 
extern int _IO_vfscanf (_IO_FILE * __restrict , const char * __restrict , __gnuc_va_list , int * __restrict ) ; 
extern int _IO_vfprintf (_IO_FILE * __restrict , const char * __restrict , __gnuc_va_list ) ; 
extern __ssize_t _IO_padn (_IO_FILE * , int , __ssize_t ) __attribute__ ((__nothrow__ ) ) ; 
extern size_t _IO_sgetn (_IO_FILE * , void * , size_t ) __attribute__ ((__nothrow__ ) ) ; 
extern __off64_t _IO_seekoff (_IO_FILE * , __off64_t , int , int ) __attribute__ ((__nothrow__ ) ) ; 
extern __off64_t _IO_seekpos (_IO_FILE * , __off64_t , int ) __attribute__ ((__nothrow__ ) ) ; 
extern void _IO_free_backup_area (_IO_FILE * ) __attribute__ ((__nothrow__ ) ) ; 
typedef _G_fpos_t fpos_t ; 
extern struct _IO_FILE * stdin ; 
extern struct _IO_FILE * stdout ; 
extern struct _IO_FILE * stderr ; 
extern int remove (__const char * __filename ) __attribute__ ((__nothrow__ ) ) ; 
extern int rename (__const char * __old , __const char * __new ) __attribute__ ((__nothrow__ ) ) ; 
extern FILE * tmpfile (void ) ; 
extern char * tmpnam (char * __s ) __attribute__ ((__nothrow__ ) ) ; 
extern char * tmpnam_r (char * __s ) __attribute__ ((__nothrow__ ) ) ; 
extern char * tempnam (__const char * __dir , __const char * __pfx ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__malloc__ ) ) ; 
extern int fclose (FILE * __stream ) ; 
extern int fflush (FILE * __stream ) ; 
extern int fflush_unlocked (FILE * __stream ) ; 
extern FILE * fopen (__const char * __restrict __filename , __const char * __restrict __modes ) ; 
extern FILE * freopen (__const char * __restrict __filename , __const char * __restrict __modes , FILE * __restrict __stream ) ; 
extern FILE * fdopen (int __fd , __const char * __modes ) __attribute__ ((__nothrow__ ) ) ; 
extern void setbuf (FILE * __restrict __stream , char * __restrict __buf ) __attribute__ ((__nothrow__ ) ) ; 
extern int setvbuf (FILE * __restrict __stream , char * __restrict __buf , int __modes , size_t __n ) __attribute__ ((__nothrow__ ) ) ; 
extern void setbuffer (FILE * __restrict __stream , char * __restrict __buf , size_t __size ) __attribute__ ((__nothrow__ ) ) ; 
extern void setlinebuf (FILE * __stream ) __attribute__ ((__nothrow__ ) ) ; 
extern int fprintf (FILE * __restrict __stream , __const char * __restrict __format , ... ) ; 
extern int printf (__const char * __restrict __format , ... ) ; 
extern int sprintf (char * __restrict __s , __const char * __restrict __format , ... ) __attribute__ ((__nothrow__ ) ) ; 
extern int vfprintf (FILE * __restrict __s , __const char * __restrict __format , __gnuc_va_list __arg ) ; 
extern int vprintf (__const char * __restrict __format , __gnuc_va_list __arg ) ; 
extern int vsprintf (char * __restrict __s , __const char * __restrict __format , __gnuc_va_list __arg ) __attribute__ ((__nothrow__ ) ) ; 
extern int snprintf (char * __restrict __s , size_t __maxlen , __const char * __restrict __format , ... ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__format__ (__printf__ , 3 , 4 ) ) ) ; 
extern int vsnprintf (char * __restrict __s , size_t __maxlen , __const char * __restrict __format , __gnuc_va_list __arg ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__format__ (__printf__ , 3 , 0 ) ) ) ; 
extern int fscanf (FILE * __restrict __stream , __const char * __restrict __format , ... ) ; 
extern int scanf (__const char * __restrict __format , ... ) ; 
extern int sscanf (__const char * __restrict __s , __const char * __restrict __format , ... ) __attribute__ ((__nothrow__ ) ) ; 
extern int fgetc (FILE * __stream ) ; 
extern int getc (FILE * __stream ) ; 
extern int getchar (void ) ; 
extern int getc_unlocked (FILE * __stream ) ; 
extern int getchar_unlocked (void ) ; 
extern int fgetc_unlocked (FILE * __stream ) ; 
extern int fputc (int __c , FILE * __stream ) ; 
extern int putc (int __c , FILE * __stream ) ; 
extern int putchar (int __c ) ; 
extern int fputc_unlocked (int __c , FILE * __stream ) ; 
extern int putc_unlocked (int __c , FILE * __stream ) ; 
extern int putchar_unlocked (int __c ) ; 
extern int getw (FILE * __stream ) ; 
extern int putw (int __w , FILE * __stream ) ; 
extern char * fgets (char * __restrict __s , int __n , FILE * __restrict __stream ) ; 
extern char * gets (char * __s ) ; 
extern int fputs (__const char * __restrict __s , FILE * __restrict __stream ) ; 
extern int puts (__const char * __s ) ; 
extern int ungetc (int __c , FILE * __stream ) ; 
extern size_t fread (void * __restrict __ptr , size_t __size , size_t __n , FILE * __restrict __stream ) ; 
extern size_t fwrite (__const void * __restrict __ptr , size_t __size , size_t __n , FILE * __restrict __s ) ; 
extern size_t fread_unlocked (void * __restrict __ptr , size_t __size , size_t __n , FILE * __restrict __stream ) ; 
extern size_t fwrite_unlocked (__const void * __restrict __ptr , size_t __size , size_t __n , FILE * __restrict __stream ) ; 
extern int fseek (FILE * __stream , long int __off , int __whence ) ; 
extern long int ftell (FILE * __stream ) ; 
extern void rewind (FILE * __stream ) ; 
extern int fseeko (FILE * __stream , __off_t __off , int __whence ) ; 
extern __off_t ftello (FILE * __stream ) ; 
extern int fgetpos (FILE * __restrict __stream , fpos_t * __restrict __pos ) ; 
extern int fsetpos (FILE * __stream , __const fpos_t * __pos ) ; 
extern void clearerr (FILE * __stream ) __attribute__ ((__nothrow__ ) ) ; 
extern int feof (FILE * __stream ) __attribute__ ((__nothrow__ ) ) ; 
extern int ferror (FILE * __stream ) __attribute__ ((__nothrow__ ) ) ; 
extern void clearerr_unlocked (FILE * __stream ) __attribute__ ((__nothrow__ ) ) ; 
extern int feof_unlocked (FILE * __stream ) __attribute__ ((__nothrow__ ) ) ; 
extern int ferror_unlocked (FILE * __stream ) __attribute__ ((__nothrow__ ) ) ; 
extern void perror (__const char * __s ) ; 
extern int sys_nerr ; 
extern __const char * __const sys_errlist [] ; 
extern int fileno (FILE * __stream ) __attribute__ ((__nothrow__ ) ) ; 
extern int fileno_unlocked (FILE * __stream ) __attribute__ ((__nothrow__ ) ) ; 
extern FILE * popen (__const char * __command , __const char * __modes ) ; 
extern int pclose (FILE * __stream ) ; 
extern char * ctermid (char * __s ) __attribute__ ((__nothrow__ ) ) ; 
extern void flockfile (FILE * __stream ) __attribute__ ((__nothrow__ ) ) ; 
extern int ftrylockfile (FILE * __stream ) __attribute__ ((__nothrow__ ) ) ; 
extern void funlockfile (FILE * __stream ) __attribute__ ((__nothrow__ ) ) ; 
typedef long int __jmp_buf [8 ] ; 
typedef int __sig_atomic_t ; 
typedef struct {
  unsigned long int __val [(1024 / (8 * sizeof (unsigned long int ) ) ) ] ; 
}
__sigset_t ; 
typedef struct __jmp_buf_tag {
  __jmp_buf __jmpbuf ; 
  int __mask_was_saved ; 
  __sigset_t __saved_mask ; 
}
jmp_buf [1 ] ; 
extern int setjmp (jmp_buf __env ) __attribute__ ((__nothrow__ ) ) ; 
extern int __sigsetjmp (struct __jmp_buf_tag __env [1 ] , int __savemask ) __attribute__ ((__nothrow__ ) ) ; 
extern int _setjmp (struct __jmp_buf_tag __env [1 ] ) __attribute__ ((__nothrow__ ) ) ; 
extern void longjmp (struct __jmp_buf_tag __env [1 ] , int __val ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__noreturn__ ) ) ; 
extern void _longjmp (struct __jmp_buf_tag __env [1 ] , int __val ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__noreturn__ ) ) ; 
typedef struct __jmp_buf_tag sigjmp_buf [1 ] ; 
extern void siglongjmp (sigjmp_buf __env , int __val ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__noreturn__ ) ) ; 
typedef __gnuc_va_list va_list ; 
typedef struct {
  int quot ; 
  int rem ; 
}
div_t ; 
typedef struct {
  long int quot ; 
  long int rem ; 
}
ldiv_t ; 
extern size_t __ctype_get_mb_cur_max (void ) __attribute__ ((__nothrow__ ) ) ; 
extern double atof (__const char * __nptr ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__pure__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern int atoi (__const char * __nptr ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__pure__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern long int atol (__const char * __nptr ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__pure__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
__extension__ extern long long int atoll (__const char * __nptr ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__pure__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern double strtod (__const char * __restrict __nptr , char * * __restrict __endptr ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern long int strtol (__const char * __restrict __nptr , char * * __restrict __endptr , int __base ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern unsigned long int strtoul (__const char * __restrict __nptr , char * * __restrict __endptr , int __base ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
__extension__ extern long long int strtoq (__const char * __restrict __nptr , char * * __restrict __endptr , int __base ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
__extension__ extern unsigned long long int strtouq (__const char * __restrict __nptr , char * * __restrict __endptr , int __base ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
__extension__ extern long long int strtoll (__const char * __restrict __nptr , char * * __restrict __endptr , int __base ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
__extension__ extern unsigned long long int strtoull (__const char * __restrict __nptr , char * * __restrict __endptr , int __base ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern double __strtod_internal (__const char * __restrict __nptr , char * * __restrict __endptr , int __group ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern float __strtof_internal (__const char * __restrict __nptr , char * * __restrict __endptr , int __group ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern long double __strtold_internal (__const char * __restrict __nptr , char * * __restrict __endptr , int __group ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern long int __strtol_internal (__const char * __restrict __nptr , char * * __restrict __endptr , int __base , int __group ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern unsigned long int __strtoul_internal (__const char * __restrict __nptr , char * * __restrict __endptr , int __base , int __group ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
__extension__ extern long long int __strtoll_internal (__const char * __restrict __nptr , char * * __restrict __endptr , int __base , int __group ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
__extension__ extern unsigned long long int __strtoull_internal (__const char * __restrict __nptr , char * * __restrict __endptr , int __base , int __group ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern char * l64a (long int __n ) __attribute__ ((__nothrow__ ) ) ; 
extern long int a64l (__const char * __s ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__pure__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
typedef __u_char u_char ; 
typedef __u_short u_short ; 
typedef __u_int u_int ; 
typedef __u_long u_long ; 
typedef __quad_t quad_t ; 
typedef __u_quad_t u_quad_t ; 
typedef __fsid_t fsid_t ; 
typedef __loff_t loff_t ; 
typedef __ino_t ino_t ; 
typedef __dev_t dev_t ; 
typedef __gid_t gid_t ; 
typedef __mode_t mode_t ; 
typedef __nlink_t nlink_t ; 
typedef __uid_t uid_t ; 
typedef __off_t off_t ; 
typedef __pid_t pid_t ; 
typedef __id_t id_t ; 
typedef __ssize_t ssize_t ; 
typedef __daddr_t daddr_t ; 
typedef __caddr_t caddr_t ; 
typedef __key_t key_t ; 
typedef __time_t time_t ; 
typedef __clockid_t clockid_t ; 
typedef __timer_t timer_t ; 
typedef unsigned long int ulong ; 
typedef unsigned short int ushort ; 
typedef unsigned int uint ; 
typedef int int8_t __attribute__ ((__mode__ (__QI__ ) ) ) ; 
typedef int int16_t __attribute__ ((__mode__ (__HI__ ) ) ) ; 
typedef int int32_t __attribute__ ((__mode__ (__SI__ ) ) ) ; 
typedef int int64_t __attribute__ ((__mode__ (__DI__ ) ) ) ; 
typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__ ) ) ) ; 
typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__ ) ) ) ; 
typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__ ) ) ) ; 
typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__ ) ) ) ; 
typedef int register_t __attribute__ ((__mode__ (__word__ ) ) ) ; 
typedef __sigset_t sigset_t ; 
struct timespec {
  __time_t tv_sec ; 
  long int tv_nsec ; 
}
; 
struct timeval {
  __time_t tv_sec ; 
  __suseconds_t tv_usec ; 
}
; 
typedef __suseconds_t suseconds_t ; 
typedef long int __fd_mask ; 
typedef struct {
  __fd_mask __fds_bits [1024 / (8 * sizeof (__fd_mask ) ) ] ; 
}
fd_set ; 
typedef __fd_mask fd_mask ; 
extern int select (int __nfds , fd_set * __restrict __readfds , fd_set * __restrict __writefds , fd_set * __restrict __exceptfds , struct timeval * __restrict __timeout ) ; 
extern int pselect (int __nfds , fd_set * __restrict __readfds , fd_set * __restrict __writefds , fd_set * __restrict __exceptfds , const struct timespec * __restrict __timeout , const __sigset_t * __restrict __sigmask ) ; 
__extension__ extern __inline unsigned int gnu_dev_major (unsigned long long int __dev ) __attribute__ ((__nothrow__ ) ) ; 
__extension__ extern __inline unsigned int gnu_dev_minor (unsigned long long int __dev ) __attribute__ ((__nothrow__ ) ) ; 
__extension__ extern __inline unsigned long long int gnu_dev_makedev (unsigned int __major , unsigned int __minor ) __attribute__ ((__nothrow__ ) ) ; 
__extension__ extern __inline unsigned int __attribute__ ((__nothrow__ ) ) gnu_dev_major (unsigned long long int __dev ) {
  return ((__dev >> 8 ) & 0xfff ) | ((unsigned int ) (__dev >> 32 ) & ~ 0xfff ) ; 
}
__extension__ extern __inline unsigned int __attribute__ ((__nothrow__ ) ) gnu_dev_minor (unsigned long long int __dev ) {
  return (__dev & 0xff ) | ((unsigned int ) (__dev >> 12 ) & ~ 0xff ) ; 
}
__extension__ extern __inline unsigned long long int __attribute__ ((__nothrow__ ) ) gnu_dev_makedev (unsigned int __major , unsigned int __minor ) {
  return ((__minor & 0xff ) | ((__major & 0xfff ) << 8 ) | (((unsigned long long int ) (__minor & ~ 0xff ) ) << 12 ) | (((unsigned long long int ) (__major & ~ 0xfff ) ) << 32 ) ) ; 
}
typedef __blkcnt_t blkcnt_t ; 
typedef __fsblkcnt_t fsblkcnt_t ; 
typedef __fsfilcnt_t fsfilcnt_t ; 
typedef unsigned long int pthread_t ; 
typedef union {
  char __size [56 ] ; 
  long int __align ; 
}
pthread_attr_t ; 
typedef struct __pthread_internal_list {
  struct __pthread_internal_list * __prev ; 
  struct __pthread_internal_list * __next ; 
}
__pthread_list_t ; 
typedef union {
  struct __pthread_mutex_s {
    int __lock ; 
    unsigned int __count ; 
    int __owner ; 
    unsigned int __nusers ; 
    int __kind ; 
    int __spins ; 
    __pthread_list_t __list ; 
  }
  __data ; 
  char __size [40 ] ; 
  long int __align ; 
}
pthread_mutex_t ; 
typedef union {
  char __size [4 ] ; 
  int __align ; 
}
pthread_mutexattr_t ; 
typedef union {
  struct {
    int __lock ; 
    unsigned int __futex ; 
    __extension__ unsigned long long int __total_seq ; 
    __extension__ unsigned long long int __wakeup_seq ; 
    __extension__ unsigned long long int __woken_seq ; 
    void * __mutex ; 
    unsigned int __nwaiters ; 
    unsigned int __broadcast_seq ; 
  }
  __data ; 
  char __size [48 ] ; 
  __extension__ long long int __align ; 
}
pthread_cond_t ; 
typedef union {
  char __size [4 ] ; 
  int __align ; 
}
pthread_condattr_t ; 
typedef unsigned int pthread_key_t ; 
typedef int pthread_once_t ; 
typedef union {
  struct {
    int __lock ; 
    unsigned int __nr_readers ; 
    unsigned int __readers_wakeup ; 
    unsigned int __writer_wakeup ; 
    unsigned int __nr_readers_queued ; 
    unsigned int __nr_writers_queued ; 
    int __writer ; 
    int __pad1 ; 
    unsigned long int __pad2 ; 
    unsigned long int __pad3 ; 
    unsigned int __flags ; 
  }
  __data ; 
  char __size [56 ] ; 
  long int __align ; 
}
pthread_rwlock_t ; 
typedef union {
  char __size [8 ] ; 
  long int __align ; 
}
pthread_rwlockattr_t ; 
typedef volatile int pthread_spinlock_t ; 
typedef union {
  char __size [32 ] ; 
  long int __align ; 
}
pthread_barrier_t ; 
typedef union {
  char __size [4 ] ; 
  int __align ; 
}
pthread_barrierattr_t ; 
extern long int random (void ) __attribute__ ((__nothrow__ ) ) ; 
extern void srandom (unsigned int __seed ) __attribute__ ((__nothrow__ ) ) ; 
extern char * initstate (unsigned int __seed , char * __statebuf , size_t __statelen ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (2 ) ) ) ; 
extern char * setstate (char * __statebuf ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
struct random_data {
  int32_t * fptr ; 
  int32_t * rptr ; 
  int32_t * state ; 
  int rand_type ; 
  int rand_deg ; 
  int rand_sep ; 
  int32_t * end_ptr ; 
}
; 
extern int random_r (struct random_data * __restrict __buf , int32_t * __restrict __result ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern int srandom_r (unsigned int __seed , struct random_data * __buf ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (2 ) ) ) ; 
extern int initstate_r (unsigned int __seed , char * __restrict __statebuf , size_t __statelen , struct random_data * __restrict __buf ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (2 , 4 ) ) ) ; 
extern int setstate_r (char * __restrict __statebuf , struct random_data * __restrict __buf ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern int rand (void ) __attribute__ ((__nothrow__ ) ) ; 
extern void srand (unsigned int __seed ) __attribute__ ((__nothrow__ ) ) ; 
extern int rand_r (unsigned int * __seed ) __attribute__ ((__nothrow__ ) ) ; 
extern double drand48 (void ) __attribute__ ((__nothrow__ ) ) ; 
extern double erand48 (unsigned short int __xsubi [3 ] ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern long int lrand48 (void ) __attribute__ ((__nothrow__ ) ) ; 
extern long int nrand48 (unsigned short int __xsubi [3 ] ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern long int mrand48 (void ) __attribute__ ((__nothrow__ ) ) ; 
extern long int jrand48 (unsigned short int __xsubi [3 ] ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern void srand48 (long int __seedval ) __attribute__ ((__nothrow__ ) ) ; 
extern unsigned short int * seed48 (unsigned short int __seed16v [3 ] ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern void lcong48 (unsigned short int __param [7 ] ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
struct drand48_data {
  unsigned short int __x [3 ] ; 
  unsigned short int __old_x [3 ] ; 
  unsigned short int __c ; 
  unsigned short int __init ; 
  unsigned long long int __a ; 
}
; 
extern int drand48_r (struct drand48_data * __restrict __buffer , double * __restrict __result ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern int erand48_r (unsigned short int __xsubi [3 ] , struct drand48_data * __restrict __buffer , double * __restrict __result ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern int lrand48_r (struct drand48_data * __restrict __buffer , long int * __restrict __result ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern int nrand48_r (unsigned short int __xsubi [3 ] , struct drand48_data * __restrict __buffer , long int * __restrict __result ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern int mrand48_r (struct drand48_data * __restrict __buffer , long int * __restrict __result ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern int jrand48_r (unsigned short int __xsubi [3 ] , struct drand48_data * __restrict __buffer , long int * __restrict __result ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern int srand48_r (long int __seedval , struct drand48_data * __buffer ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (2 ) ) ) ; 
extern int seed48_r (unsigned short int __seed16v [3 ] , struct drand48_data * __buffer ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern int lcong48_r (unsigned short int __param [7 ] , struct drand48_data * __buffer ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern void * malloc (size_t __size ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__malloc__ ) ) ; 
extern void * calloc (size_t __nmemb , size_t __size ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__malloc__ ) ) ; 
extern void * realloc (void * __ptr , size_t __size ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__malloc__ ) ) __attribute__ ((__warn_unused_result__ ) ) ; 
extern void free (void * __ptr ) __attribute__ ((__nothrow__ ) ) ; 
extern void cfree (void * __ptr ) __attribute__ ((__nothrow__ ) ) ; 
extern void * alloca (size_t __size ) __attribute__ ((__nothrow__ ) ) ; 
extern void * valloc (size_t __size ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__malloc__ ) ) ; 
extern int posix_memalign (void * * __memptr , size_t __alignment , size_t __size ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern void abort (void ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__noreturn__ ) ) ; 
extern int atexit (void (* __func ) (void ) ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern int on_exit (void (* __func ) (int __status , void * __arg ) , void * __arg ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern void exit (int __status ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__noreturn__ ) ) ; 
extern char * getenv (__const char * __name ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern char * __secure_getenv (__const char * __name ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern int putenv (char * __string ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern int setenv (__const char * __name , __const char * __value , int __replace ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (2 ) ) ) ; 
extern int unsetenv (__const char * __name ) __attribute__ ((__nothrow__ ) ) ; 
extern int clearenv (void ) __attribute__ ((__nothrow__ ) ) ; 
extern char * mktemp (char * __template ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern int mkstemp (char * __template ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern char * mkdtemp (char * __template ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern int system (__const char * __command ) ; 
extern char * realpath (__const char * __restrict __name , char * __restrict __resolved ) __attribute__ ((__nothrow__ ) ) ; 
typedef int (* __compar_fn_t ) (__const void * , __const void * ) ; 
extern void * bsearch (__const void * __key , __const void * __base , size_t __nmemb , size_t __size , __compar_fn_t __compar ) __attribute__ ((__nonnull__ (1 , 2 , 5 ) ) ) ; 
extern void qsort (void * __base , size_t __nmemb , size_t __size , __compar_fn_t __compar ) __attribute__ ((__nonnull__ (1 , 4 ) ) ) ; 
extern int abs (int __x ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__const__ ) ) ; 
extern long int labs (long int __x ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__const__ ) ) ; 
extern div_t div (int __numer , int __denom ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__const__ ) ) ; 
extern ldiv_t ldiv (long int __numer , long int __denom ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__const__ ) ) ; 
extern char * ecvt (double __value , int __ndigit , int * __restrict __decpt , int * __restrict __sign ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (3 , 4 ) ) ) ; 
extern char * fcvt (double __value , int __ndigit , int * __restrict __decpt , int * __restrict __sign ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (3 , 4 ) ) ) ; 
extern char * gcvt (double __value , int __ndigit , char * __buf ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (3 ) ) ) ; 
extern char * qecvt (long double __value , int __ndigit , int * __restrict __decpt , int * __restrict __sign ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (3 , 4 ) ) ) ; 
extern char * qfcvt (long double __value , int __ndigit , int * __restrict __decpt , int * __restrict __sign ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (3 , 4 ) ) ) ; 
extern char * qgcvt (long double __value , int __ndigit , char * __buf ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (3 ) ) ) ; 
extern int ecvt_r (double __value , int __ndigit , int * __restrict __decpt , int * __restrict __sign , char * __restrict __buf , size_t __len ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (3 , 4 , 5 ) ) ) ; 
extern int fcvt_r (double __value , int __ndigit , int * __restrict __decpt , int * __restrict __sign , char * __restrict __buf , size_t __len ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (3 , 4 , 5 ) ) ) ; 
extern int qecvt_r (long double __value , int __ndigit , int * __restrict __decpt , int * __restrict __sign , char * __restrict __buf , size_t __len ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (3 , 4 , 5 ) ) ) ; 
extern int qfcvt_r (long double __value , int __ndigit , int * __restrict __decpt , int * __restrict __sign , char * __restrict __buf , size_t __len ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (3 , 4 , 5 ) ) ) ; 
extern int mblen (__const char * __s , size_t __n ) __attribute__ ((__nothrow__ ) ) ; 
extern int mbtowc (wchar_t * __restrict __pwc , __const char * __restrict __s , size_t __n ) __attribute__ ((__nothrow__ ) ) ; 
extern int wctomb (char * __s , wchar_t __wchar ) __attribute__ ((__nothrow__ ) ) ; 
extern size_t mbstowcs (wchar_t * __restrict __pwcs , __const char * __restrict __s , size_t __n ) __attribute__ ((__nothrow__ ) ) ; 
extern size_t wcstombs (char * __restrict __s , __const wchar_t * __restrict __pwcs , size_t __n ) __attribute__ ((__nothrow__ ) ) ; 
extern int rpmatch (__const char * __response ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern int posix_openpt (int __oflag ) ; 
extern int getloadavg (double __loadavg [] , int __nelem ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern void * memcpy (void * __restrict __dest , __const void * __restrict __src , size_t __n ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern void * memmove (void * __dest , __const void * __src , size_t __n ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern void * memccpy (void * __restrict __dest , __const void * __restrict __src , int __c , size_t __n ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern void * memset (void * __s , int __c , size_t __n ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern int memcmp (__const void * __s1 , __const void * __s2 , size_t __n ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__pure__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern void * memchr (__const void * __s , int __c , size_t __n ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__pure__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern char * strcpy (char * __restrict __dest , __const char * __restrict __src ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern char * strncpy (char * __restrict __dest , __const char * __restrict __src , size_t __n ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern char * strcat (char * __restrict __dest , __const char * __restrict __src ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern char * strncat (char * __restrict __dest , __const char * __restrict __src , size_t __n ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern int strcmp (__const char * __s1 , __const char * __s2 ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__pure__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern int strncmp (__const char * __s1 , __const char * __s2 , size_t __n ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__pure__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern int strcoll (__const char * __s1 , __const char * __s2 ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__pure__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern size_t strxfrm (char * __restrict __dest , __const char * __restrict __src , size_t __n ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (2 ) ) ) ; 
extern char * strdup (__const char * __s ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__malloc__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern char * strchr (__const char * __s , int __c ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__pure__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern char * strrchr (__const char * __s , int __c ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__pure__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern size_t strcspn (__const char * __s , __const char * __reject ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__pure__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern size_t strspn (__const char * __s , __const char * __accept ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__pure__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern char * strpbrk (__const char * __s , __const char * __accept ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__pure__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern char * strstr (__const char * __haystack , __const char * __needle ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__pure__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern char * strtok (char * __restrict __s , __const char * __restrict __delim ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (2 ) ) ) ; 
extern char * __strtok_r (char * __restrict __s , __const char * __restrict __delim , char * * __restrict __save_ptr ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (2 , 3 ) ) ) ; 
extern char * strtok_r (char * __restrict __s , __const char * __restrict __delim , char * * __restrict __save_ptr ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (2 , 3 ) ) ) ; 
extern size_t strlen (__const char * __s ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__pure__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern char * strerror (int __errnum ) __attribute__ ((__nothrow__ ) ) ; 
extern int strerror_r (int __errnum , char * __buf , size_t __buflen ) __asm__ ("" "__xpg_strerror_r" ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (2 ) ) ) ; 
extern void __bzero (void * __s , size_t __n ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern void bcopy (__const void * __src , void * __dest , size_t __n ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern void bzero (void * __s , size_t __n ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern int bcmp (__const void * __s1 , __const void * __s2 , size_t __n ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__pure__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern char * index (__const char * __s , int __c ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__pure__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern char * rindex (__const char * __s , int __c ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__pure__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern int ffs (int __i ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__const__ ) ) ; 
extern int strcasecmp (__const char * __s1 , __const char * __s2 ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__pure__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern int strncasecmp (__const char * __s1 , __const char * __s2 , size_t __n ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__pure__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern char * strsep (char * * __restrict __stringp , __const char * __restrict __delim ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
typedef long int ptrdiff_t ; 
typedef short Scheme_Type ; 
typedef int mzshort ; 
typedef unsigned int mzchar ; 
typedef int mzchar_int ; 
typedef long mzlonglong ; 
typedef unsigned long umzlonglong ; 
typedef struct Scheme_Object {
  Scheme_Type type ; 
  short keyex ; 
}
Scheme_Object ; 
typedef struct Scheme_Inclhash_Object {
  Scheme_Object so ; 
}
Scheme_Inclhash_Object ; 
typedef struct Scheme_Simple_Object {
  Scheme_Inclhash_Object iso ; 
  union {
    struct {
      mzchar * string_val ; 
      int tag_val ; 
    }
    char_str_val ; 
    struct {
      char * string_val ; 
      int tag_val ; 
    }
    byte_str_val ; 
    struct {
      void * ptr1 , * ptr2 ; 
    }
    two_ptr_val ; 
    struct {
      int int1 ; 
      int int2 ; 
    }
    two_int_val ; 
    struct {
      void * ptr ; 
      int pint ; 
    }
    ptr_int_val ; 
    struct {
      void * ptr ; 
      long pint ; 
    }
    ptr_long_val ; 
    struct {
      struct Scheme_Object * car , * cdr ; 
    }
    pair_val ; 
    struct {
      mzshort len ; 
      mzshort * vec ; 
    }
    svector_val ; 
    struct {
      void * val ; 
      Scheme_Object * type ; 
    }
    cptr_val ; 
  }
  u ; 
}
Scheme_Simple_Object ; 
typedef struct Scheme_Object * (* Scheme_Closure_Func ) (struct Scheme_Object * ) ; 
typedef struct {
  Scheme_Object so ; 
  union {
    mzchar char_val ; 
    Scheme_Object * ptr_value ; 
    long int_val ; 
    Scheme_Object * ptr_val ; 
  }
  u ; 
}
Scheme_Small_Object ; 
typedef struct {
  Scheme_Object so ; 
  double double_val ; 
}
Scheme_Double ; 
typedef struct Scheme_Symbol {
  Scheme_Inclhash_Object iso ; 
  int len ; 
  char s [4 ] ; 
}
Scheme_Symbol ; 
typedef struct Scheme_Vector {
  Scheme_Inclhash_Object iso ; 
  int size ; 
  Scheme_Object * els [1 ] ; 
}
Scheme_Vector ; 
typedef struct Scheme_Print_Params Scheme_Print_Params ; 
typedef void (* Scheme_Type_Printer ) (Scheme_Object * v , int for_display , Scheme_Print_Params * pp ) ; 
typedef int (* Scheme_Equal_Proc ) (Scheme_Object * obj1 , Scheme_Object * obj2 ) ; 
typedef long (* Scheme_Primary_Hash_Proc ) (Scheme_Object * obj , long base ) ; 
typedef long (* Scheme_Secondary_Hash_Proc ) (Scheme_Object * obj ) ; 
enum {
  scheme_toplevel_type , scheme_local_type , scheme_local_unbox_type , scheme_syntax_type , scheme_application_type , scheme_application2_type , scheme_application3_type , scheme_sequence_type , scheme_branch_type , scheme_unclosed_procedure_type , scheme_let_value_type , scheme_let_void_type , scheme_letrec_type , scheme_let_one_type , scheme_with_cont_mark_type , scheme_quote_syntax_type , _scheme_values_types_ , scheme_compiled_unclosed_procedure_type , scheme_compiled_let_value_type , scheme_compiled_let_void_type , scheme_compiled_syntax_type , scheme_compiled_toplevel_type , scheme_compiled_quote_syntax_type , scheme_quote_compilation_type , scheme_variable_type , scheme_module_variable_type , _scheme_compiled_values_types_ , scheme_prim_type , scheme_closed_prim_type , scheme_closure_type , scheme_case_closure_type , scheme_cont_type , scheme_escaping_cont_type , scheme_proc_struct_type , scheme_native_closure_type , scheme_structure_type , scheme_char_type , scheme_integer_type , scheme_bignum_type , scheme_rational_type , scheme_float_type , scheme_double_type , scheme_complex_izi_type , scheme_complex_type , scheme_char_string_type , scheme_byte_string_type , scheme_unix_path_type , scheme_windows_path_type , scheme_symbol_type , scheme_keyword_type , scheme_null_type , scheme_pair_type , scheme_vector_type , scheme_inspector_type , scheme_input_port_type , scheme_output_port_type , scheme_eof_type , scheme_true_type , scheme_false_type , scheme_void_type , scheme_syntax_compiler_type , scheme_macro_type , scheme_box_type , scheme_thread_type , scheme_stx_offset_type , scheme_cont_mark_set_type , scheme_sema_type , scheme_hash_table_type , scheme_cpointer_type , scheme_offset_cpointer_type , scheme_weak_box_type , scheme_ephemeron_type , scheme_struct_type_type , scheme_module_index_type , scheme_set_macro_type , scheme_listener_type , scheme_namespace_type , scheme_config_type , scheme_stx_type , scheme_will_executor_type , scheme_custodian_type , scheme_random_state_type , scheme_regexp_type , scheme_bucket_type , scheme_bucket_table_type , scheme_subprocess_type , scheme_compilation_top_type , scheme_wrap_chunk_type , scheme_eval_waiting_type , scheme_tail_call_waiting_type , scheme_undefined_type , scheme_struct_property_type , scheme_multiple_values_type , scheme_placeholder_type , scheme_case_lambda_sequence_type , scheme_begin0_sequence_type , scheme_rename_table_type , scheme_module_type , scheme_svector_type , scheme_lazy_macro_type , scheme_resolve_prefix_type , scheme_security_guard_type , scheme_indent_type , scheme_udp_type , scheme_udp_evt_type , scheme_tcp_accept_evt_type , scheme_id_macro_type , scheme_evt_set_type , scheme_wrap_evt_type , scheme_handle_evt_type , scheme_nack_guard_evt_type , scheme_semaphore_repost_type , scheme_channel_type , scheme_channel_put_type , scheme_thread_resume_type , scheme_thread_suspend_type , scheme_thread_dead_type , scheme_poll_evt_type , scheme_nack_evt_type , scheme_module_registry_type , scheme_thread_set_type , scheme_string_converter_type , scheme_alarm_type , scheme_thread_cell_type , scheme_channel_syncer_type , scheme_special_comment_type , scheme_write_evt_type , scheme_always_evt_type , scheme_never_evt_type , scheme_progress_evt_type , scheme_certifications_type , scheme_already_comp_type , scheme_readtable_type , scheme_intdef_context_type , scheme_lexical_rib_type , scheme_thread_cell_values_type , scheme_global_ref_type , scheme_cont_mark_chain_type , scheme_raw_pair_type , scheme_prompt_type , scheme_prompt_tag_type , scheme_expanded_syntax_type , scheme_delay_syntax_type , scheme_cust_box_type , _scheme_last_normal_type_ , scheme_rt_weak_array , scheme_rt_comp_env , scheme_rt_constant_binding , scheme_rt_resolve_info , scheme_rt_optimize_info , scheme_rt_compile_info , scheme_rt_cont_mark , scheme_rt_saved_stack , scheme_rt_reply_item , scheme_rt_closure_info , scheme_rt_overflow , scheme_rt_overflow_jmp , scheme_rt_meta_cont , scheme_rt_dyn_wind_cell , scheme_rt_dyn_wind_info , scheme_rt_dyn_wind , scheme_rt_dup_check , scheme_rt_thread_memory , scheme_rt_input_file , scheme_rt_input_fd , scheme_rt_oskit_console_input , scheme_rt_tested_input_file , scheme_rt_tested_output_file , scheme_rt_indexed_string , scheme_rt_output_file , scheme_rt_load_handler_data , scheme_rt_pipe , scheme_rt_beos_process , scheme_rt_system_child , scheme_rt_tcp , scheme_rt_write_data , scheme_rt_tcp_select_info , scheme_rt_namespace_option , scheme_rt_param_data , scheme_rt_will , scheme_rt_will_registration , scheme_rt_struct_proc_info , scheme_rt_linker_name , scheme_rt_param_map , scheme_rt_finalization , scheme_rt_finalizations , scheme_rt_cpp_object , scheme_rt_cpp_array_object , scheme_rt_stack_object , scheme_rt_preallocated_object , scheme_thread_hop_type , scheme_rt_srcloc , scheme_rt_evt , scheme_rt_syncing , scheme_rt_comp_prefix , scheme_rt_user_input , scheme_rt_user_output , scheme_rt_compact_port , scheme_rt_read_special_dw , scheme_rt_regwork , scheme_rt_buf_holder , scheme_rt_parameterization , scheme_rt_print_params , scheme_rt_read_params , scheme_rt_native_code , scheme_rt_native_code_plus_case , scheme_rt_jitter_data , scheme_rt_module_exports , scheme_rt_module_phase_exports , scheme_rt_delay_load_info , scheme_rt_marshal_info , scheme_rt_unmarshal_info , scheme_rt_runstack , _scheme_last_type_ }
; 
typedef struct Scheme_Cptr {
  Scheme_Object so ; 
  void * val ; 
  Scheme_Object * type ; 
}
Scheme_Cptr ; 
typedef struct Scheme_Offset_Cptr {
  Scheme_Cptr cptr ; 
  long offset ; 
}
Scheme_Offset_Cptr ; 
typedef struct Scheme_Object * (Scheme_Prim ) (int argc , Scheme_Object * argv [] ) ; 
typedef struct Scheme_Object * (Scheme_Primitive_Closure_Proc ) (int argc , struct Scheme_Object * argv [] , Scheme_Object * p ) ; 
typedef struct {
  Scheme_Object so ; 
  unsigned short flags ; 
}
Scheme_Prim_Proc_Header ; 
typedef struct {
  Scheme_Prim_Proc_Header pp ; 
  Scheme_Primitive_Closure_Proc * prim_val ; 
  const char * name ; 
  mzshort mina ; 
  union {
    mzshort * cases ; 
    mzshort maxa ; 
  }
  mu ; 
}
Scheme_Primitive_Proc ; 
typedef struct {
  Scheme_Primitive_Proc pp ; 
  mzshort minr , maxr ; 
}
Scheme_Prim_W_Result_Arity ; 
typedef struct Scheme_Primitive_Closure {
  Scheme_Primitive_Proc p ; 
  mzshort count ; 
  Scheme_Object * val [1 ] ; 
}
Scheme_Primitive_Closure ; 
typedef struct Scheme_Object * (Scheme_Closed_Prim ) (void * d , int argc , struct Scheme_Object * argv [] ) ; 
typedef struct {
  Scheme_Prim_Proc_Header pp ; 
  Scheme_Closed_Prim * prim_val ; 
  void * data ; 
  const char * name ; 
  mzshort mina , maxa ; 
}
Scheme_Closed_Primitive_Proc ; 
typedef struct {
  Scheme_Closed_Primitive_Proc p ; 
  mzshort * cases ; 
}
Scheme_Closed_Case_Primitive_Proc ; 
typedef struct {
  Scheme_Closed_Primitive_Proc p ; 
  mzshort minr , maxr ; 
}
Scheme_Closed_Prim_W_Result_Arity ; 
typedef struct Scheme_Hash_Table {
  Scheme_Inclhash_Object iso ; 
  int size ; 
  int count ; 
  Scheme_Object * * keys ; 
  Scheme_Object * * vals ; 
  void (* make_hash_indices ) (void * v , long * h1 , long * h2 ) ; 
  int (* compare ) (void * v1 , void * v2 ) ; 
  Scheme_Object * mutex ; 
  int mcount ; 
}
Scheme_Hash_Table ; 
typedef struct Scheme_Bucket {
  Scheme_Object so ; 
  void * val ; 
  char * key ; 
}
Scheme_Bucket ; 
typedef struct Scheme_Bucket_Table {
  Scheme_Object so ; 
  int size ; 
  int count ; 
  Scheme_Bucket * * buckets ; 
  char weak , with_home ; 
  void (* make_hash_indices ) (void * v , long * h1 , long * h2 ) ; 
  int (* compare ) (void * v1 , void * v2 ) ; 
  Scheme_Object * mutex ; 
}
Scheme_Bucket_Table ; 
enum {
  SCHEME_hash_string , SCHEME_hash_ptr , SCHEME_hash_bound_id , SCHEME_hash_weak_ptr }
; 
typedef struct Scheme_Env Scheme_Env ; 
typedef struct {
  jmp_buf jb ; 
  unsigned long stack_frame ; 
}
mz_one_jit_jmp_buf ; 
typedef mz_one_jit_jmp_buf mz_jit_jmp_buf [1 ] ; 
typedef struct {
  mz_jit_jmp_buf jb ; 
  long gcvs ; 
  long gcvs_cnt ; 
}
mz_jmp_buf ; 
typedef struct Scheme_Jumpup_Buf {
  void * stack_from , * stack_copy ; 
  long stack_size , stack_max_size ; 
  struct Scheme_Cont * cont ; 
  mz_jmp_buf buf ; 
  void * gc_var_stack ; 
  void * external_stack ; 
}
Scheme_Jumpup_Buf ; 
typedef struct Scheme_Jumpup_Buf_Holder {
  Scheme_Type type ; 
  Scheme_Jumpup_Buf buf ; 
}
Scheme_Jumpup_Buf_Holder ; 
typedef struct Scheme_Continuation_Jump_State {
  struct Scheme_Object * jumping_to_continuation ; 
  Scheme_Object * val ; 
  mzshort num_vals ; 
  short is_kill , is_escape ; 
}
Scheme_Continuation_Jump_State ; 
typedef struct Scheme_Cont_Frame_Data {
  long cont_mark_pos ; 
  long cont_mark_stack ; 
  void * cache ; 
}
Scheme_Cont_Frame_Data ; 
typedef void (Scheme_Close_Custodian_Client ) (Scheme_Object * o , void * data ) ; 
typedef void (* Scheme_Exit_Closer_Func ) (Scheme_Object * , Scheme_Close_Custodian_Client * , void * ) ; 
typedef Scheme_Object * (* Scheme_Custodian_Extractor ) (Scheme_Object * o ) ; 
typedef struct Scheme_Object Scheme_Custodian_Reference ; 
typedef struct Scheme_Custodian Scheme_Custodian ; 
typedef Scheme_Bucket_Table Scheme_Thread_Cell_Table ; 
typedef struct Scheme_Config Scheme_Config ; 
typedef int (* Scheme_Ready_Fun ) (Scheme_Object * o ) ; 
typedef void (* Scheme_Needs_Wakeup_Fun ) (Scheme_Object * , void * ) ; 
typedef Scheme_Object * (* Scheme_Sync_Sema_Fun ) (Scheme_Object * , int * repost ) ; 
typedef int (* Scheme_Sync_Filter_Fun ) (Scheme_Object * ) ; 
typedef struct Scheme_Thread {
  Scheme_Object so ; 
  struct Scheme_Thread * next ; 
  struct Scheme_Thread * prev ; 
  struct Scheme_Thread_Set * t_set_parent ; 
  Scheme_Object * t_set_next ; 
  Scheme_Object * t_set_prev ; 
  mz_jmp_buf * error_buf ; 
  Scheme_Continuation_Jump_State cjs ; 
  Scheme_Thread_Cell_Table * cell_values ; 
  Scheme_Config * init_config ; 
  Scheme_Object * init_break_cell ; 
  int can_break_at_swap ; 
  Scheme_Object * * runstack ; 
  Scheme_Object * * runstack_start ; 
  long runstack_size ; 
  struct Scheme_Saved_Stack * runstack_saved ; 
  Scheme_Object * * runstack_tmp_keep ; 
  Scheme_Object * * spare_runstack ; 
  long spare_runstack_size ; 
  struct Scheme_Thread * * runstack_owner ; 
  struct Scheme_Saved_Stack * runstack_swapped ; 
  long cont_mark_pos ; 
  long cont_mark_stack ; 
  struct Scheme_Cont_Mark * * cont_mark_stack_segments ; 
  int cont_mark_seg_count ; 
  int cont_mark_stack_bottom ; 
  int cont_mark_pos_bottom ; 
  struct Scheme_Thread * * cont_mark_stack_owner ; 
  struct Scheme_Cont_Mark * cont_mark_stack_swapped ; 
  struct Scheme_Prompt * meta_prompt ; 
  struct Scheme_Meta_Continuation * meta_continuation ; 
  long engine_weight ; 
  void * stack_start ; 
  void * stack_end ; 
  Scheme_Jumpup_Buf jmpup_buf ; 
  struct Scheme_Dynamic_Wind * dw ; 
  int next_meta ; 
  int running ; 
  Scheme_Object * suspended_box ; 
  Scheme_Object * resumed_box ; 
  Scheme_Object * dead_box ; 
  Scheme_Object * running_box ; 
  struct Scheme_Thread * nester , * nestee ; 
  double sleep_end ; 
  int block_descriptor ; 
  Scheme_Object * blocker ; 
  Scheme_Ready_Fun block_check ; 
  Scheme_Needs_Wakeup_Fun block_needs_wakeup ; 
  char ran_some ; 
  char suspend_to_kill ; 
  struct Scheme_Overflow * overflow ; 
  struct Scheme_Comp_Env * current_local_env ; 
  Scheme_Object * current_local_mark ; 
  Scheme_Object * current_local_name ; 
  Scheme_Object * current_local_certs ; 
  Scheme_Object * current_local_modidx ; 
  Scheme_Env * current_local_menv ; 
  char skip_error ; 
  Scheme_Object * (* overflow_k ) (void ) ; 
  Scheme_Object * overflow_reply ; 
  Scheme_Object * * tail_buffer ; 
  int tail_buffer_size ; 
  Scheme_Object * * values_buffer ; 
  int values_buffer_size ; 
  struct {
    struct {
      Scheme_Object * wait_expr ; 
    }
    eval ; 
    struct {
      Scheme_Object * tail_rator ; 
      Scheme_Object * * tail_rands ; 
      long tail_num_rands ; 
    }
    apply ; 
    struct {
      Scheme_Object * * array ; 
      long count ; 
    }
    multiple ; 
    struct {
      void * p1 , * p2 , * p3 , * p4 , * p5 ; 
      long i1 , i2 , i3 , i4 ; 
    }
    k ; 
  }
  ku ; 
  short suspend_break ; 
  short external_break ; 
  Scheme_Simple_Object * list_stack ; 
  int list_stack_pos ; 
  void (* on_kill ) (struct Scheme_Thread * p ) ; 
  void * kill_data ; 
  void (* private_on_kill ) (void * ) ; 
  void * private_kill_data ; 
  void * * private_kill_next ; 
  void * * user_tls ; 
  int user_tls_size ; 
  long gmp_tls [6 ] ; 
  struct Scheme_Thread_Custodian_Hop * mr_hop ; 
  Scheme_Custodian_Reference * mref ; 
  Scheme_Object * extra_mrefs ; 
  Scheme_Object * transitive_resumes ; 
  Scheme_Object * name ; 
  int gc_owner_set ; 
}
Scheme_Thread ; 
typedef void (* Scheme_Kill_Action_Func ) (void * ) ; 
enum {
  MZCONFIG_ENV , MZCONFIG_INPUT_PORT , MZCONFIG_OUTPUT_PORT , MZCONFIG_ERROR_PORT , MZCONFIG_ERROR_DISPLAY_HANDLER , MZCONFIG_ERROR_PRINT_VALUE_HANDLER , MZCONFIG_EXIT_HANDLER , MZCONFIG_INIT_EXN_HANDLER , MZCONFIG_EVAL_HANDLER , MZCONFIG_COMPILE_HANDLER , MZCONFIG_LOAD_HANDLER , MZCONFIG_PRINT_HANDLER , MZCONFIG_PROMPT_READ_HANDLER , MZCONFIG_READTABLE , MZCONFIG_READER_GUARD , MZCONFIG_CAN_READ_GRAPH , MZCONFIG_CAN_READ_COMPILED , MZCONFIG_CAN_READ_BOX , MZCONFIG_CAN_READ_PIPE_QUOTE , MZCONFIG_CAN_READ_DOT , MZCONFIG_CAN_READ_INFIX_DOT , MZCONFIG_CAN_READ_QUASI , MZCONFIG_CAN_READ_READER , MZCONFIG_READ_DECIMAL_INEXACT , MZCONFIG_PRINT_GRAPH , MZCONFIG_PRINT_STRUCT , MZCONFIG_PRINT_BOX , MZCONFIG_PRINT_VEC_SHORTHAND , MZCONFIG_PRINT_HASH_TABLE , MZCONFIG_PRINT_UNREADABLE , MZCONFIG_CASE_SENS , MZCONFIG_SQUARE_BRACKETS_ARE_PARENS , MZCONFIG_CURLY_BRACES_ARE_PARENS , MZCONFIG_HONU_MODE , MZCONFIG_ERROR_PRINT_WIDTH , MZCONFIG_ERROR_PRINT_CONTEXT_LENGTH , MZCONFIG_ERROR_ESCAPE_HANDLER , MZCONFIG_ALLOW_SET_UNDEFINED , MZCONFIG_COMPILE_MODULE_CONSTS , MZCONFIG_USE_JIT , MZCONFIG_CUSTODIAN , MZCONFIG_INSPECTOR , MZCONFIG_CODE_INSPECTOR , MZCONFIG_USE_COMPILED_KIND , MZCONFIG_USE_USER_PATHS , MZCONFIG_LOAD_DIRECTORY , MZCONFIG_WRITE_DIRECTORY , MZCONFIG_COLLECTION_PATHS , MZCONFIG_PORT_PRINT_HANDLER , MZCONFIG_LOAD_EXTENSION_HANDLER , MZCONFIG_CURRENT_DIRECTORY , MZCONFIG_RANDOM_STATE , MZCONFIG_CURRENT_MODULE_RESOLVER , MZCONFIG_CURRENT_MODULE_PREFIX , MZCONFIG_ERROR_PRINT_SRCLOC , MZCONFIG_CMDLINE_ARGS , MZCONFIG_LOCALE , MZCONFIG_SECURITY_GUARD , MZCONFIG_PORT_COUNT_LINES , MZCONFIG_SCHEDULER_RANDOM_STATE , MZCONFIG_THREAD_SET , MZCONFIG_THREAD_INIT_STACK_SIZE , MZCONFIG_LOAD_DELAY_ENABLED , MZCONFIG_DELAY_LOAD_INFO , MZCONFIG_EXPAND_OBSERVE , __MZCONFIG_BUILTIN_COUNT__ }
; 
typedef struct Scheme_Input_Port Scheme_Input_Port ; 
typedef struct Scheme_Output_Port Scheme_Output_Port ; 
typedef struct Scheme_Port Scheme_Port ; 
typedef long (* Scheme_Get_String_Fun ) (Scheme_Input_Port * port , char * buffer , long offset , long size , int nonblock , Scheme_Object * unless ) ; 
typedef long (* Scheme_Peek_String_Fun ) (Scheme_Input_Port * port , char * buffer , long offset , long size , Scheme_Object * skip , int nonblock , Scheme_Object * unless ) ; 
typedef Scheme_Object * (* Scheme_Progress_Evt_Fun ) (Scheme_Input_Port * port ) ; 
typedef int (* Scheme_Peeked_Read_Fun ) (Scheme_Input_Port * port , long amount , Scheme_Object * unless_evt , Scheme_Object * target_ch ) ; 
typedef int (* Scheme_In_Ready_Fun ) (Scheme_Input_Port * port ) ; 
typedef void (* Scheme_Close_Input_Fun ) (Scheme_Input_Port * port ) ; 
typedef void (* Scheme_Need_Wakeup_Input_Fun ) (Scheme_Input_Port * , void * ) ; 
typedef Scheme_Object * (* Scheme_Location_Fun ) (Scheme_Port * ) ; 
typedef void (* Scheme_Count_Lines_Fun ) (Scheme_Port * ) ; 
typedef int (* Scheme_Buffer_Mode_Fun ) (Scheme_Port * , int m ) ; 
typedef Scheme_Object * (* Scheme_Write_String_Evt_Fun ) (Scheme_Output_Port * , const char * str , long offset , long size ) ; 
typedef long (* Scheme_Write_String_Fun ) (Scheme_Output_Port * , const char * str , long offset , long size , int rarely_block , int enable_break ) ; 
typedef int (* Scheme_Out_Ready_Fun ) (Scheme_Output_Port * port ) ; 
typedef void (* Scheme_Close_Output_Fun ) (Scheme_Output_Port * port ) ; 
typedef void (* Scheme_Need_Wakeup_Output_Fun ) (Scheme_Output_Port * , void * ) ; 
typedef Scheme_Object * (* Scheme_Write_Special_Evt_Fun ) (Scheme_Output_Port * , Scheme_Object * ) ; 
typedef int (* Scheme_Write_Special_Fun ) (Scheme_Output_Port * , Scheme_Object * , int nonblock ) ; 
struct Scheme_Port {
  Scheme_Object so ; 
  char count_lines , was_cr ; 
  long position , readpos , lineNumber , charsSinceNewline ; 
  long column , oldColumn ; 
  int utf8state ; 
  Scheme_Location_Fun location_fun ; 
  Scheme_Count_Lines_Fun count_lines_fun ; 
  Scheme_Buffer_Mode_Fun buffer_mode_fun ; 
}
; 
struct Scheme_Input_Port {
  struct Scheme_Port p ; 
  char closed , pending_eof ; 
  Scheme_Object * sub_type ; 
  Scheme_Custodian_Reference * mref ; 
  void * port_data ; 
  Scheme_Get_String_Fun get_string_fun ; 
  Scheme_Peek_String_Fun peek_string_fun ; 
  Scheme_Progress_Evt_Fun progress_evt_fun ; 
  Scheme_Peeked_Read_Fun peeked_read_fun ; 
  Scheme_In_Ready_Fun byte_ready_fun ; 
  Scheme_Close_Input_Fun close_fun ; 
  Scheme_Need_Wakeup_Input_Fun need_wakeup_fun ; 
  Scheme_Object * read_handler ; 
  Scheme_Object * name ; 
  Scheme_Object * peeked_read , * peeked_write ; 
  Scheme_Object * progress_evt , * input_lock , * input_giveup , * input_extras , * input_extras_ready ; 
  unsigned char ungotten [24 ] ; 
  int ungotten_count ; 
  Scheme_Object * special , * ungotten_special ; 
  Scheme_Object * unless , * unless_cache ; 
  struct Scheme_Output_Port * output_half ; 
}
; 
struct Scheme_Output_Port {
  struct Scheme_Port p ; 
  short closed ; 
  Scheme_Object * sub_type ; 
  Scheme_Custodian_Reference * mref ; 
  void * port_data ; 
  Scheme_Write_String_Evt_Fun write_string_evt_fun ; 
  Scheme_Write_String_Fun write_string_fun ; 
  Scheme_Close_Output_Fun close_fun ; 
  Scheme_Out_Ready_Fun ready_fun ; 
  Scheme_Need_Wakeup_Output_Fun need_wakeup_fun ; 
  Scheme_Write_Special_Evt_Fun write_special_evt_fun ; 
  Scheme_Write_Special_Fun write_special_fun ; 
  long pos ; 
  Scheme_Object * name ; 
  Scheme_Object * display_handler ; 
  Scheme_Object * write_handler ; 
  Scheme_Object * print_handler ; 
  struct Scheme_Input_Port * input_half ; 
}
; 
enum {
  MZEXN , MZEXN_FAIL , MZEXN_FAIL_CONTRACT , MZEXN_FAIL_CONTRACT_ARITY , MZEXN_FAIL_CONTRACT_DIVIDE_BY_ZERO , MZEXN_FAIL_CONTRACT_CONTINUATION , MZEXN_FAIL_CONTRACT_VARIABLE , MZEXN_FAIL_SYNTAX , MZEXN_FAIL_READ , MZEXN_FAIL_READ_EOF , MZEXN_FAIL_READ_NON_CHAR , MZEXN_FAIL_FILESYSTEM , MZEXN_FAIL_FILESYSTEM_EXISTS , MZEXN_FAIL_FILESYSTEM_VERSION , MZEXN_FAIL_NETWORK , MZEXN_FAIL_OUT_OF_MEMORY , MZEXN_FAIL_UNSUPPORTED , MZEXN_FAIL_USER , MZEXN_BREAK , MZEXN_OTHER }
; 
typedef void (* Scheme_Invoke_Proc ) (Scheme_Env * env , long phase_shift , Scheme_Object * self_modidx , void * data ) ; 
extern volatile int scheme_fuel_counter ; 
extern Scheme_Object * scheme_eval_waiting ; 
extern void scheme_jit_longjmp (mz_jit_jmp_buf b , int v ) ; 
extern void scheme_jit_setjmp_prepare (mz_jit_jmp_buf b ) ; 
typedef int (* Size_Proc ) (void * obj ) ; 
typedef int (* Mark_Proc ) (void * obj ) ; 
typedef int (* Fixup_Proc ) (void * obj ) ; 
extern unsigned long (* GC_get_thread_stack_base ) (void ) ; 
extern void GC_set_stack_base (void * base ) ; 
extern unsigned long GC_get_stack_base (void ) ; 
extern void GC_add_roots (void * start , void * end ) ; 
extern void GC_init_type_tags (int count , int pair , int weakbox , int ephemeron , int weakarray , int custbox ) ; 
extern void GC_register_new_thread (void * , void * ) ; 
extern void GC_register_thread (void * , void * ) ; 
extern void (* GC_collect_start_callback ) (void ) ; 
extern void (* GC_collect_end_callback ) (void ) ; 
extern void (* GC_out_of_memory ) (void ) ; 
extern void GC_dump (void ) ; 
extern long GC_get_memory_use (void * c ) ; 
extern int GC_set_account_hook (int type , void * c1 , unsigned long b , void * c2 ) ; 
extern void GC_gcollect (void ) ; 
extern void * GC_malloc (size_t size_in_bytes ) ; 
extern void * GC_malloc_one_tagged (size_t ) ; 
extern void * GC_malloc_one_small_tagged (size_t ) ; 
extern void * GC_malloc_one_small_dirty_tagged (size_t ) ; 
extern void * GC_malloc_pair (void * car , void * cdr ) ; 
extern void * GC_malloc_one_xtagged (size_t ) ; 
extern void (* GC_mark_xtagged ) (void * obj ) ; 
extern void (* GC_fixup_xtagged ) (void * obj ) ; 
extern void * GC_malloc_array_tagged (size_t ) ; 
extern void * GC_malloc_atomic (size_t size_in_bytes ) ; 
extern void * GC_malloc_atomic_uncollectable (size_t size_in_bytes ) ; 
extern void * GC_malloc_allow_interior (size_t size_in_bytes ) ; 
extern void * GC_malloc_atomic_allow_interior (size_t size_in_bytes ) ; 
extern void * GC_malloc_tagged_allow_interior (size_t size_in_bytes ) ; 
extern void * GC_malloc_weak_array (size_t size_in_bytes , void * replace_val ) ; 
extern void GC_free (void * ) ; 
extern void * GC_malloc_weak_box (void * p , void * * secondary , int soffset ) ; 
extern void * GC_malloc_ephemeron (void * p , void * p2 ) ; 
extern void * * GC_malloc_immobile_box (void * p ) ; 
extern void GC_free_immobile_box (void * * b ) ; 
extern long GC_malloc_stays_put_threshold () ; 
extern int GC_mtrace_new_id (void * f ) ; 
extern int GC_mtrace_union_current_with (int newval ) ; 
typedef void (* GC_finalization_proc ) (void * p , void * data ) ; 
extern void GC_set_finalizer (void * p , int tagged , int level , GC_finalization_proc f , void * data , GC_finalization_proc * oldf , void * * olddata ) ; 
extern void GC_finalization_weak_ptr (void * * p , int offset ) ; 
extern void * * GC_variable_stack ; 
extern void * * GC_get_variable_stack () ; 
extern void GC_set_variable_stack (void * * p ) ; 
extern void GC_register_traversers (short tag , Size_Proc size , Mark_Proc mark , Fixup_Proc fixup , int is_constant_size , int is_atomic ) ; 
extern void * GC_resolve (void * p ) ; 
extern void * GC_fixup_self (void * p ) ; 
extern void GC_mark (const void * p ) ; 
extern void GC_fixup (void * p ) ; 
extern void GC_mark_variable_stack (void * * var_stack , long delta , void * limit , void * stack_mem ) ; 
extern void GC_fixup_variable_stack (void * * var_stack , long delta , void * limit , void * stack_mem ) ; 
extern void GC_write_barrier (void * p ) ; 
extern int scheme_defining_primitives ; 
extern int scheme_case_sensitive ; 
extern int scheme_no_keywords ; 
extern int scheme_allow_set_undefined ; 
extern int scheme_square_brackets_are_parens ; 
extern int scheme_curly_braces_are_parens ; 
extern int scheme_hash_percent_syntax_only ; 
extern int scheme_hash_percent_globals_only ; 
extern int scheme_binary_mode_stdio ; 
extern int scheme_startup_use_jit ; 
extern int scheme_ignore_user_paths ; 
extern void scheme_set_case_sensitive (int ) ; 
extern void scheme_set_allow_set_undefined (int ) ; 
extern void scheme_set_binary_mode_stdio (int ) ; 
extern void scheme_set_startup_use_jit (int ) ; 
extern void scheme_set_ignore_user_paths (int ) ; 
extern int scheme_get_allow_set_undefined () ; 
extern Scheme_Thread * scheme_current_thread ; 
extern Scheme_Thread * scheme_first_thread ; 
typedef void (* Scheme_Exit_Proc ) (int v ) ; 
extern Scheme_Exit_Proc scheme_exit ; 
extern void scheme_set_exit (Scheme_Exit_Proc p ) ; 
typedef void (* scheme_console_printf_t ) (char * str , ... ) ; 
extern scheme_console_printf_t scheme_console_printf ; 
extern scheme_console_printf_t scheme_get_console_printf () ; 
extern void (* scheme_console_output ) (char * str , long len ) ; 
extern void (* scheme_sleep ) (float seconds , void * fds ) ; 
extern void (* scheme_notify_multithread ) (int on ) ; 
extern void (* scheme_wakeup_on_input ) (void * fds ) ; 
extern int (* scheme_check_for_break ) (void ) ; 
extern Scheme_Object * (* scheme_module_demand_hook ) (int c , Scheme_Object * * a ) ; 
extern void * (* scheme_get_external_stack_val ) (void ) ; 
extern void (* scheme_set_external_stack_val ) (void * ) ; 
extern Scheme_Object * (* scheme_make_stdin ) (void ) ; 
extern Scheme_Object * (* scheme_make_stdout ) (void ) ; 
extern Scheme_Object * (* scheme_make_stderr ) (void ) ; 
extern void scheme_set_banner (char * s ) ; 
extern Scheme_Object * scheme_set_exec_cmd (char * s ) ; 
extern Scheme_Object * scheme_set_run_cmd (char * s ) ; 
extern void scheme_set_collects_path (Scheme_Object * p ) ; 
extern void scheme_set_original_dir (Scheme_Object * d ) ; 
extern Scheme_Env * scheme_basic_env (void ) ; 
extern void scheme_reset_overflow (void ) ; 
extern void scheme_check_threads (void ) ; 
extern void scheme_wake_up (void ) ; 
extern int scheme_get_external_event_fd (void ) ; 
extern int scheme_image_main (int argc , char * * argv ) ; 
extern int (* scheme_actual_main ) (int argc , char * * argv ) ; 
extern void scheme_set_actual_main (int (* m ) (int argc , char * * argv ) ) ; 
extern void scheme_set_stack_base (void * base , int no_auto_statics ) ; 
extern void scheme_set_stack_bounds (void * base , void * deepest , int no_auto_statics ) ; 
extern void scheme_register_static (void * ptr , long size ) ; 
extern void (* scheme_on_atomic_timeout ) (void ) ; 
extern void scheme_immediate_exit (int status ) ; 
extern int scheme_new_param (void ) ; 
extern Scheme_Object * scheme_param_config (char * name , Scheme_Object * pos , int argc , Scheme_Object * * argv , int arity , Scheme_Prim * check , char * expected , int isbool ) ; 
extern Scheme_Object * scheme_register_parameter (Scheme_Prim * function , char * name , int which ) ; 
extern void scheme_init_jmpup_buf (Scheme_Jumpup_Buf * b ) ; 
extern int scheme_setjmpup_relative (Scheme_Jumpup_Buf * b , void * base , void * volatile start , struct Scheme_Cont * cont ) ; 
extern void scheme_longjmpup (Scheme_Jumpup_Buf * b ) ; 
extern void scheme_reset_jmpup_buf (Scheme_Jumpup_Buf * b ) ; 
extern void scheme_clear_escape (void ) ; 
extern Scheme_Jumpup_Buf_Holder * scheme_new_jmpupbuf_holder (void ) ; 
extern Scheme_Config * scheme_current_config (void ) ; 
extern Scheme_Config * scheme_extend_config (Scheme_Config * c , int pos , Scheme_Object * init_val ) ; 
extern void scheme_install_config (Scheme_Config * ) ; 
extern Scheme_Object * scheme_get_param (Scheme_Config * c , int pos ) ; 
extern void scheme_set_param (Scheme_Config * c , int pos , Scheme_Object * o ) ; 
extern Scheme_Object * scheme_get_thread_param (Scheme_Config * c , Scheme_Thread_Cell_Table * cells , int pos ) ; 
extern void scheme_set_thread_param (Scheme_Config * c , Scheme_Thread_Cell_Table * cells , int pos , Scheme_Object * o ) ; 
extern Scheme_Env * scheme_get_env (Scheme_Config * config ) ; 
extern Scheme_Thread_Cell_Table * scheme_inherit_cells (Scheme_Thread_Cell_Table * cells ) ; 
extern Scheme_Object * scheme_current_break_cell () ; 
extern Scheme_Thread * scheme_current_thread ; 
extern volatile int scheme_fuel_counter ; 
extern Scheme_Thread * scheme_get_current_thread () ; 
extern void scheme_start_atomic (void ) ; 
extern void scheme_end_atomic (void ) ; 
extern void scheme_end_atomic_no_swap (void ) ; 
extern void scheme_out_of_fuel (void ) ; 
extern Scheme_Object * scheme_thread (Scheme_Object * thunk ) ; 
extern Scheme_Object * scheme_thread_w_details (Scheme_Object * thunk , Scheme_Config * init_config , Scheme_Thread_Cell_Table * copy_from , Scheme_Object * break_cell , Scheme_Custodian * owning_custodian , int suspend_to_kill ) ; 
extern void scheme_kill_thread (Scheme_Thread * p ) ; 
extern void scheme_break_thread (Scheme_Thread * p ) ; 
extern void scheme_thread_block (float sleep_time ) ; 
extern void scheme_thread_block_enable_break (float sleep_time , int enable ) ; 
extern void scheme_swap_thread (Scheme_Thread * process ) ; 
extern void scheme_making_progress () ; 
extern void scheme_weak_suspend_thread (Scheme_Thread * p ) ; 
extern void scheme_weak_resume_thread (Scheme_Thread * p ) ; 
extern int scheme_block_until (Scheme_Ready_Fun f , Scheme_Needs_Wakeup_Fun , Scheme_Object * , float ) ; 
extern int scheme_block_until_enable_break (Scheme_Ready_Fun f , Scheme_Needs_Wakeup_Fun , Scheme_Object * , float , int enable ) ; 
extern int scheme_block_until_unless (Scheme_Ready_Fun f , Scheme_Needs_Wakeup_Fun fdf , Scheme_Object * data , float delay , Scheme_Object * unless , int enable_break ) ; 
extern void scheme_wait_input_allowed (Scheme_Input_Port * port , int nonblock ) ; 
__xform_nongcing__ extern int scheme_unless_ready (Scheme_Object * unless ) ; 
extern int scheme_in_main_thread (void ) ; 
extern void scheme_cancel_sleep (void ) ; 
extern Scheme_Object * scheme_make_thread_cell (Scheme_Object * def_val , int inherited ) ; 
extern Scheme_Object * scheme_thread_cell_get (Scheme_Object * cell , Scheme_Thread_Cell_Table * cells ) ; 
extern void scheme_thread_cell_set (Scheme_Object * cell , Scheme_Thread_Cell_Table * cells , Scheme_Object * v ) ; 
extern int scheme_tls_allocate () ; 
extern void scheme_tls_set (int pos , void * v ) ; 
extern void * scheme_tls_get (int pos ) ; 
extern Scheme_Custodian * scheme_make_custodian (Scheme_Custodian * ) ; 
extern Scheme_Custodian_Reference * scheme_add_managed (Scheme_Custodian * m , Scheme_Object * o , Scheme_Close_Custodian_Client * f , void * data , int strong ) ; 
extern void scheme_custodian_check_available (Scheme_Custodian * m , const char * who , const char * what ) ; 
extern void scheme_remove_managed (Scheme_Custodian_Reference * m , Scheme_Object * o ) ; 
extern void scheme_close_managed (Scheme_Custodian * m ) ; 
extern void scheme_schedule_custodian_close (Scheme_Custodian * c ) ; 
extern void scheme_add_custodian_extractor (Scheme_Type t , Scheme_Custodian_Extractor e ) ; 
extern void scheme_add_atexit_closer (Scheme_Exit_Closer_Func f ) ; 
extern void scheme_add_evt (Scheme_Type type , Scheme_Ready_Fun ready , Scheme_Needs_Wakeup_Fun wakeup , Scheme_Sync_Filter_Fun filter , int can_redirect ) ; 
extern void scheme_add_evt_through_sema (Scheme_Type type , Scheme_Sync_Sema_Fun sema , Scheme_Sync_Filter_Fun filter ) ; 
extern int scheme_is_evt (Scheme_Object * o ) ; 
extern Scheme_Object * scheme_sync (int argc , Scheme_Object * argv [] ) ; 
extern Scheme_Object * scheme_sync_enable_break (int argc , Scheme_Object * argv [] ) ; 
extern Scheme_Object * scheme_sync_timeout (int argc , Scheme_Object * argv [] ) ; 
extern Scheme_Object * scheme_make_evt_set (int argc , Scheme_Object * * argv ) ; 
extern void scheme_add_swap_callback (Scheme_Closure_Func f , Scheme_Object * data ) ; 
extern Scheme_Object * scheme_call_enable_break (Scheme_Prim * prim , int argc , Scheme_Object * argv [] ) ; 
extern int scheme_close_should_force_port_closed () ; 
extern void scheme_push_kill_action (Scheme_Kill_Action_Func f , void * d ) ; 
extern void scheme_pop_kill_action () ; 
extern void scheme_set_can_break (int on ) ; 
extern void scheme_push_break_enable (Scheme_Cont_Frame_Data * cframe , int on , int pre_check ) ; 
extern void scheme_pop_break_enable (Scheme_Cont_Frame_Data * cframe , int post_check ) ; 
extern void scheme_signal_error (const char * msg , ... ) ; 
extern void scheme_raise_exn (int exnid , ... ) ; 
extern void scheme_warning (char * msg , ... ) ; 
extern void scheme_raise (Scheme_Object * exn ) ; 
extern void scheme_wrong_count (const char * name , int minc , int maxc , int argc , Scheme_Object * * argv ) ; 
extern void scheme_wrong_count_m (const char * name , int minc , int maxc , int argc , Scheme_Object * * argv , int is_method ) ; 
extern void scheme_case_lambda_wrong_count (const char * name , int argc , Scheme_Object * * argv , int is_method , int count , ... ) ; 
extern void scheme_wrong_type (const char * name , const char * expected , int which , int argc , Scheme_Object * * argv ) ; 
extern void scheme_wrong_field_type (Scheme_Object * c_name , const char * expected , Scheme_Object * o ) ; 
extern void scheme_arg_mismatch (const char * name , const char * msg , Scheme_Object * o ) ; 
extern void scheme_wrong_return_arity (const char * where , int expected , int got , Scheme_Object * * argv , const char * context_detail , ... ) ; 
extern void scheme_unbound_global (Scheme_Bucket * b ) ; 
extern Scheme_Object * scheme_dynamic_wind (void (* pre ) (void * ) , Scheme_Object * (* volatile act ) (void * ) , void (* volatile post ) (void * ) , Scheme_Object * (* jmp_handler ) (void * ) , void * volatile data ) ; 
extern Scheme_Type scheme_make_type (const char * name ) ; 
extern char * scheme_get_type_name (Scheme_Type type ) ; 
extern Scheme_Object scheme_eof [1 ] ; 
extern Scheme_Object * scheme_make_eof (void ) ; 
extern Scheme_Object scheme_null [1 ] ; 
extern Scheme_Object * scheme_make_null (void ) ; 
extern Scheme_Object scheme_true [1 ] ; 
extern Scheme_Object * scheme_make_true (void ) ; 
extern Scheme_Object scheme_false [1 ] ; 
extern Scheme_Object * scheme_make_false (void ) ; 
extern Scheme_Object scheme_void [1 ] ; 
extern Scheme_Object * scheme_make_void (void ) ; 
extern Scheme_Object scheme_undefined [1 ] ; 
extern Scheme_Object * scheme_tail_call_waiting ; 
extern Scheme_Object * scheme_multiple_values ; 
extern unsigned short * scheme_uchar_table [] ; 
extern unsigned char * scheme_uchar_cases_table [] ; 
extern unsigned char * scheme_uchar_cats_table [] ; 
extern int scheme_uchar_ups [] ; 
extern int scheme_uchar_downs [] ; 
extern int scheme_uchar_titles [] ; 
extern int scheme_uchar_folds [] ; 
extern unsigned char scheme_uchar_combining_classes [] ; 
extern Scheme_Object * scheme_eval (Scheme_Object * obj , Scheme_Env * env ) ; 
extern Scheme_Object * scheme_eval_multi (Scheme_Object * obj , Scheme_Env * env ) ; 
extern Scheme_Object * scheme_eval_with_prompt (Scheme_Object * obj , Scheme_Env * env ) ; 
extern Scheme_Object * scheme_eval_multi_with_prompt (Scheme_Object * obj , Scheme_Env * env ) ; 
extern Scheme_Object * scheme_eval_compiled (Scheme_Object * obj , Scheme_Env * env ) ; 
extern Scheme_Object * scheme_eval_compiled_multi (Scheme_Object * obj , Scheme_Env * env ) ; 
extern Scheme_Object * _scheme_eval_compiled (Scheme_Object * obj , Scheme_Env * env ) ; 
extern Scheme_Object * _scheme_eval_compiled_multi (Scheme_Object * obj , Scheme_Env * env ) ; 
extern Scheme_Object * scheme_apply (Scheme_Object * rator , int num_rands , Scheme_Object * * rands ) ; 
extern Scheme_Object * scheme_apply_multi (Scheme_Object * rator , int num_rands , Scheme_Object * * rands ) ; 
extern Scheme_Object * scheme_apply_no_eb (Scheme_Object * rator , int num_rands , Scheme_Object * * rands ) ; 
extern Scheme_Object * scheme_apply_multi_no_eb (Scheme_Object * rator , int num_rands , Scheme_Object * * rands ) ; 
extern Scheme_Object * scheme_apply_to_list (Scheme_Object * rator , Scheme_Object * argss ) ; 
extern Scheme_Object * scheme_apply_with_prompt (Scheme_Object * rator , int num_rands , Scheme_Object * * rands ) ; 
extern Scheme_Object * scheme_apply_multi_with_prompt (Scheme_Object * rator , int num_rands , Scheme_Object * * rands ) ; 
extern Scheme_Object * _scheme_apply_with_prompt (Scheme_Object * rator , int num_rands , Scheme_Object * * rands ) ; 
extern Scheme_Object * _scheme_apply_multi_with_prompt (Scheme_Object * rator , int num_rands , Scheme_Object * * rands ) ; 
extern Scheme_Object * scheme_eval_string (const char * str , Scheme_Env * env ) ; 
extern Scheme_Object * scheme_eval_string_multi (const char * str , Scheme_Env * env ) ; 
extern Scheme_Object * scheme_eval_string_all (const char * str , Scheme_Env * env , int all ) ; 
extern Scheme_Object * scheme_eval_string_with_prompt (const char * str , Scheme_Env * env ) ; 
extern Scheme_Object * scheme_eval_string_multi_with_prompt (const char * str , Scheme_Env * env ) ; 
extern Scheme_Object * scheme_eval_string_all_with_prompt (const char * str , Scheme_Env * env , int all ) ; 
extern Scheme_Object * _scheme_apply_known_prim_closure (Scheme_Object * rator , int argc , Scheme_Object * * argv ) ; 
extern Scheme_Object * _scheme_apply_known_prim_closure_multi (Scheme_Object * rator , int argc , Scheme_Object * * argv ) ; 
extern Scheme_Object * _scheme_apply_prim_closure (Scheme_Object * rator , int argc , Scheme_Object * * argv ) ; 
extern Scheme_Object * _scheme_apply_prim_closure_multi (Scheme_Object * rator , int argc , Scheme_Object * * argv ) ; 
extern Scheme_Object * scheme_call_with_prompt (Scheme_Closed_Prim f , void * data ) ; 
extern Scheme_Object * scheme_call_with_prompt_multi (Scheme_Closed_Prim f , void * data ) ; 
extern Scheme_Object * _scheme_call_with_prompt (Scheme_Closed_Prim f , void * data ) ; 
extern Scheme_Object * _scheme_call_with_prompt_multi (Scheme_Closed_Prim f , void * data ) ; 
extern Scheme_Object * scheme_values (int c , Scheme_Object * * v ) ; 
extern Scheme_Object * scheme_check_one_value (Scheme_Object * v ) ; 
extern Scheme_Object * scheme_tail_apply (Scheme_Object * f , int n , Scheme_Object * * arg ) ; 
extern Scheme_Object * scheme_tail_apply_no_copy (Scheme_Object * f , int n , Scheme_Object * * arg ) ; 
extern Scheme_Object * scheme_tail_apply_to_list (Scheme_Object * f , Scheme_Object * l ) ; 
extern Scheme_Object * scheme_tail_eval_expr (Scheme_Object * obj ) ; 
extern void scheme_set_tail_buffer_size (int s ) ; 
extern Scheme_Object * scheme_force_value (Scheme_Object * ) ; 
extern Scheme_Object * scheme_force_one_value (Scheme_Object * ) ; 
extern long scheme_set_cont_mark (Scheme_Object * key , Scheme_Object * val ) ; 
extern void scheme_push_continuation_frame (Scheme_Cont_Frame_Data * ) ; 
extern void scheme_pop_continuation_frame (Scheme_Cont_Frame_Data * ) ; 
extern void scheme_temp_dec_mark_depth () ; 
extern void scheme_temp_inc_mark_depth () ; 
extern Scheme_Object * scheme_current_continuation_marks (Scheme_Object * prompt_tag ) ; 
extern Scheme_Object * scheme_extract_one_cc_mark (Scheme_Object * mark_set , Scheme_Object * key ) ; 
extern Scheme_Object * scheme_extract_one_cc_mark_to_tag (Scheme_Object * mark_set , Scheme_Object * key , Scheme_Object * prompt_tag ) ; 
extern Scheme_Object * scheme_do_eval (Scheme_Object * obj , int _num_rands , Scheme_Object * * rands , int val ) ; 
extern Scheme_Object * scheme_eval_compiled_stx_string (Scheme_Object * expr , Scheme_Env * env , long shift , Scheme_Object * modidx ) ; 
extern Scheme_Object * scheme_load_compiled_stx_string (const char * str , long len ) ; 
extern Scheme_Object * scheme_compiled_stx_symbol (Scheme_Object * stx ) ; 
extern Scheme_Object * scheme_eval_compiled_sized_string (const char * str , int len , Scheme_Env * env ) ; 
extern Scheme_Object * scheme_eval_compiled_sized_string_with_magic (const char * str , int len , Scheme_Env * env , Scheme_Object * magic_symbol , Scheme_Object * magic_val , int multi_ok ) ; 
extern void * GC_malloc (size_t size_in_bytes ) ; 
extern void * GC_malloc_atomic (size_t size_in_bytes ) ; 
extern void * GC_malloc_one_tagged (size_t size_in_bytes ) ; 
extern void * GC_malloc_atomic_uncollectable (size_t size_in_bytes ) ; 
extern void * scheme_malloc_uncollectable (size_t size_in_bytes ) ; 
extern void * GC_malloc_array_tagged (size_t size_in_bytes ) ; 
extern void * GC_malloc_allow_interior (size_t size_in_bytes ) ; 
extern void * GC_malloc_atomic_allow_interior (size_t size_in_bytes ) ; 
extern void * GC_malloc_tagged_allow_interior (size_t size_in_bytes ) ; 
extern void * scheme_malloc_eternal (size_t n ) ; 
extern void scheme_end_stubborn_change (void * p ) ; 
extern void * scheme_calloc (size_t num , size_t size ) ; 
extern char * scheme_strdup (const char * str ) ; 
extern char * scheme_strdup_eternal (const char * str ) ; 
extern void * scheme_malloc_fail_ok (void * (* f ) (size_t ) , size_t ) ; 
extern void scheme_add_finalizer (void * p , void (* f ) (void * p , void * data ) , void * data ) ; 
extern void scheme_add_finalizer_once (void * p , void (* f ) (void * p , void * data ) , void * data ) ; 
extern void scheme_subtract_finalizer (void * p , void (* f ) (void * p , void * data ) , void * data ) ; 
extern void scheme_add_scheme_finalizer (void * p , void (* f ) (void * p , void * data ) , void * data ) ; 
extern void scheme_add_scheme_finalizer_once (void * p , void (* f ) (void * p , void * data ) , void * data ) ; 
extern void scheme_register_finalizer (void * p , void (* f ) (void * p , void * data ) , void * data , void (* * oldf ) (void * p , void * data ) , void * * olddata ) ; 
extern void scheme_remove_all_finalization (void * p ) ; 
extern void scheme_dont_gc_ptr (void * p ) ; 
extern void scheme_gc_ptr_ok (void * p ) ; 
extern void scheme_collect_garbage (void ) ; 
extern void * * GC_variable_stack ; 
extern void GC_register_traversers (short tag , Size_Proc size , Mark_Proc mark , Fixup_Proc fixup , int is_constant_size , int is_atomic ) ; 
extern void * GC_resolve (void * p ) ; 
extern void GC_mark (const void * p ) ; 
extern void GC_fixup (void * p ) ; 
extern void * * scheme_malloc_immobile_box (void * p ) ; 
extern void scheme_free_immobile_box (void * * b ) ; 
extern Scheme_Bucket_Table * scheme_make_bucket_table (int size_hint , int type ) ; 
extern void scheme_add_to_table (Scheme_Bucket_Table * table , const char * key , void * val , int ) ; 
extern void scheme_change_in_table (Scheme_Bucket_Table * table , const char * key , void * new_val ) ; 
extern void * scheme_lookup_in_table (Scheme_Bucket_Table * table , const char * key ) ; 
extern Scheme_Bucket * scheme_bucket_from_table (Scheme_Bucket_Table * table , const char * key ) ; 
extern int scheme_bucket_table_equal (Scheme_Bucket_Table * t1 , Scheme_Bucket_Table * t2 ) ; 
extern Scheme_Bucket_Table * scheme_clone_bucket_table (Scheme_Bucket_Table * bt ) ; 
extern Scheme_Hash_Table * scheme_make_hash_table (int type ) ; 
extern Scheme_Hash_Table * scheme_make_hash_table_equal () ; 
extern void scheme_hash_set (Scheme_Hash_Table * table , Scheme_Object * key , Scheme_Object * val ) ; 
extern Scheme_Object * scheme_hash_get (Scheme_Hash_Table * table , Scheme_Object * key ) ; 
__xform_nongcing__ extern Scheme_Object * scheme_eq_hash_get (Scheme_Hash_Table * table , Scheme_Object * key ) ; 
extern void scheme_hash_set_atomic (Scheme_Hash_Table * table , Scheme_Object * key , Scheme_Object * val ) ; 
extern Scheme_Object * scheme_hash_get_atomic (Scheme_Hash_Table * table , Scheme_Object * key ) ; 
extern int scheme_hash_table_equal (Scheme_Hash_Table * t1 , Scheme_Hash_Table * t2 ) ; 
extern int scheme_is_hash_table_equal (Scheme_Object * o ) ; 
extern Scheme_Hash_Table * scheme_clone_hash_table (Scheme_Hash_Table * bt ) ; 
extern Scheme_Object * scheme_make_prim (Scheme_Prim * prim ) ; 
extern Scheme_Object * scheme_make_noneternal_prim (Scheme_Prim * prim ) ; 
extern Scheme_Object * scheme_make_prim_w_arity (Scheme_Prim * prim , const char * name , mzshort mina , mzshort maxa ) ; 
extern Scheme_Object * scheme_make_folding_prim (Scheme_Prim * prim , const char * name , mzshort mina , mzshort maxa , short functional ) ; 
extern Scheme_Object * scheme_make_noncm_prim (Scheme_Prim * prim , const char * name , mzshort mina , mzshort maxa ) ; 
extern Scheme_Object * scheme_make_noneternal_prim_w_arity (Scheme_Prim * prim , const char * name , mzshort mina , mzshort maxa ) ; 
extern Scheme_Object * scheme_make_prim_w_everything (Scheme_Prim * fun , int eternal , const char * name , mzshort mina , mzshort maxa , int folding , mzshort minr , mzshort maxr ) ; 
extern Scheme_Object * scheme_make_prim_closure_w_arity (Scheme_Primitive_Closure_Proc * prim , int size , Scheme_Object * * vals , const char * name , mzshort mina , mzshort maxa ) ; 
extern Scheme_Object * scheme_make_folding_prim_closure (Scheme_Primitive_Closure_Proc * prim , int size , Scheme_Object * * vals , const char * name , mzshort mina , mzshort maxa , short functional ) ; 
extern Scheme_Object * scheme_make_closed_prim (Scheme_Closed_Prim * prim , void * data ) ; 
extern Scheme_Object * scheme_make_closed_prim_w_arity (Scheme_Closed_Prim * prim , void * data , const char * name , mzshort mina , mzshort maxa ) ; 
extern Scheme_Object * scheme_make_folding_closed_prim (Scheme_Closed_Prim * prim , void * data , const char * name , mzshort mina , mzshort maxa , short functional ) ; 
extern Scheme_Object * scheme_make_closed_prim_w_everything (Scheme_Closed_Prim * fun , void * data , const char * name , mzshort mina , mzshort maxa , short folding , mzshort minr , mzshort maxr ) ; 
extern void scheme_prim_is_method (Scheme_Object * o ) ; 
extern Scheme_Object * scheme_make_pair (Scheme_Object * car , Scheme_Object * cdr ) ; 
extern Scheme_Object * scheme_make_immutable_pair (Scheme_Object * car , Scheme_Object * cdr ) ; 
extern Scheme_Object * scheme_make_raw_pair (Scheme_Object * , Scheme_Object * ) ; 
extern Scheme_Object * scheme_make_byte_string (const char * chars ) ; 
extern Scheme_Object * scheme_make_sized_byte_string (char * chars , long len , int copy ) ; 
extern Scheme_Object * scheme_make_sized_offset_byte_string (char * chars , long d , long len , int copy ) ; 
extern Scheme_Object * scheme_make_immutable_sized_byte_string (char * chars , long len , int copy ) ; 
extern Scheme_Object * scheme_make_byte_string_without_copying (char * chars ) ; 
extern Scheme_Object * scheme_alloc_byte_string (int size , char fill ) ; 
extern Scheme_Object * scheme_append_byte_string (Scheme_Object * , Scheme_Object * ) ; 
extern Scheme_Object * scheme_make_utf8_string (const char * chars ) ; 
extern Scheme_Object * scheme_make_sized_utf8_string (char * chars , long len ) ; 
extern Scheme_Object * scheme_make_sized_offset_utf8_string (char * chars , long d , long len ) ; 
extern Scheme_Object * scheme_make_immutable_sized_utf8_string (char * chars , long len ) ; 
extern Scheme_Object * scheme_make_locale_string (const char * chars ) ; 
extern Scheme_Object * scheme_char_string_to_byte_string (Scheme_Object * s ) ; 
extern Scheme_Object * scheme_byte_string_to_char_string (Scheme_Object * s ) ; 
extern Scheme_Object * scheme_char_string_to_byte_string_locale (Scheme_Object * s ) ; 
extern Scheme_Object * scheme_byte_string_to_char_string_locale (Scheme_Object * s ) ; 
extern Scheme_Object * scheme_char_string_to_path (Scheme_Object * p ) ; 
extern Scheme_Object * scheme_path_to_char_string (Scheme_Object * p ) ; 
extern Scheme_Object * scheme_make_char_string (const mzchar * chars ) ; 
extern Scheme_Object * scheme_make_sized_char_string (mzchar * chars , long len , int copy ) ; 
extern Scheme_Object * scheme_make_sized_offset_char_string (mzchar * chars , long d , long len , int copy ) ; 
extern Scheme_Object * scheme_make_immutable_sized_char_string (mzchar * chars , long len , int copy ) ; 
extern Scheme_Object * scheme_make_char_string_without_copying (mzchar * chars ) ; 
extern Scheme_Object * scheme_alloc_char_string (int size , mzchar fill ) ; 
extern Scheme_Object * scheme_append_char_string (Scheme_Object * , Scheme_Object * ) ; 
extern mzchar * scheme_string_recase (mzchar * s , int d , int len , int mode , int inplace , int * _len ) ; 
extern Scheme_Object * scheme_make_vector (int size , Scheme_Object * fill ) ; 
extern Scheme_Object * scheme_make_integer_value (long i ) ; 
extern Scheme_Object * scheme_make_integer_value_from_unsigned (unsigned long i ) ; 
extern Scheme_Object * scheme_make_integer_value_from_long_long (mzlonglong i ) ; 
extern Scheme_Object * scheme_make_integer_value_from_unsigned_long_long (umzlonglong i ) ; 
extern Scheme_Object * scheme_make_integer_value_from_long_halves (unsigned long lowhalf , unsigned long hihalf ) ; 
extern Scheme_Object * scheme_make_integer_value_from_unsigned_long_halves (unsigned long lowhalf , unsigned long hihalf ) ; 
extern Scheme_Object * scheme_make_double (double d ) ; 
extern Scheme_Object * scheme_make_char (mzchar ch ) ; 
extern Scheme_Object * scheme_make_char_or_nul (mzchar ch ) ; 
extern Scheme_Object * scheme_make_sema (long v ) ; 
extern void scheme_post_sema (Scheme_Object * o ) ; 
extern void scheme_post_sema_all (Scheme_Object * o ) ; 
extern int scheme_wait_sema (Scheme_Object * o , int just_try ) ; 
__xform_nongcing__ extern int scheme_try_plain_sema (Scheme_Object * o ) ; 
extern Scheme_Object * * scheme_char_constants ; 
extern Scheme_Object * scheme_make_channel () ; 
extern Scheme_Object * scheme_make_channel_put_evt (Scheme_Object * ch , Scheme_Object * v ) ; 
__xform_nongcing__ extern int scheme_get_int_val (Scheme_Object * o , long * v ) ; 
__xform_nongcing__ extern int scheme_get_unsigned_int_val (Scheme_Object * o , unsigned long * v ) ; 
__xform_nongcing__ extern int scheme_get_long_long_val (Scheme_Object * o , mzlonglong * v ) ; 
__xform_nongcing__ extern int scheme_get_unsigned_long_long_val (Scheme_Object * o , umzlonglong * v ) ; 
__xform_nongcing__ extern double scheme_real_to_double (Scheme_Object * r ) ; 
extern Scheme_Object * scheme_make_cptr (void * cptr , Scheme_Object * typetag ) ; 
extern Scheme_Object * scheme_make_offset_cptr (void * cptr , long offset , Scheme_Object * typetag ) ; 
extern const char * scheme_get_proc_name (Scheme_Object * p , int * len , int for_error ) ; 
extern int scheme_utf8_decode (const unsigned char * s , int start , int end , unsigned int * us , int dstart , int dend , long * ipos , char utf16 , int permissive ) ; 
extern int scheme_utf8_decode_as_prefix (const unsigned char * s , int start , int end , unsigned int * us , int dstart , int dend , long * ipos , char utf16 , int permissive ) ; 
extern int scheme_utf8_decode_all (const unsigned char * s , int len , unsigned int * us , int permissive ) ; 
extern int scheme_utf8_decode_prefix (const unsigned char * s , int len , unsigned int * us , int permissive ) ; 
extern mzchar * scheme_utf8_decode_to_buffer (const unsigned char * s , int len , mzchar * buf , int blen ) ; 
extern mzchar * scheme_utf8_decode_to_buffer_len (const unsigned char * s , int len , mzchar * buf , int blen , long * rlen ) ; 
__xform_nongcing__ extern int scheme_utf8_decode_count (const unsigned char * s , int start , int end , int * _state , int might_continue , int permissive ) ; 
extern int scheme_utf8_encode (const unsigned int * us , int start , int end , unsigned char * s , int dstart , char utf16 ) ; 
extern int scheme_utf8_encode_all (const unsigned int * us , int len , unsigned char * s ) ; 
extern char * scheme_utf8_encode_to_buffer (const mzchar * s , int len , char * buf , int blen ) ; 
extern char * scheme_utf8_encode_to_buffer_len (const mzchar * s , int len , char * buf , int blen , long * rlen ) ; 
extern unsigned short * scheme_ucs4_to_utf16 (const mzchar * text , int start , int end , unsigned short * buf , int bufsize , long * ulen , int term_size ) ; 
extern mzchar * scheme_utf16_to_ucs4 (const unsigned short * text , int start , int end , mzchar * buf , int bufsize , long * ulen , int term_size ) ; 
extern Scheme_Object * scheme_open_converter (const char * from_e , const char * to_e ) ; 
extern void scheme_close_converter (Scheme_Object * conv ) ; 
extern Scheme_Object * scheme_make_bignum (long v ) ; 
extern Scheme_Object * scheme_make_bignum_from_unsigned (unsigned long v ) ; 
extern Scheme_Object * scheme_make_bignum_from_long_long (mzlonglong v ) ; 
extern Scheme_Object * scheme_make_bignum_from_unsigned_long_long (umzlonglong v ) ; 
extern double scheme_bignum_to_double (const Scheme_Object * n ) ; 
extern Scheme_Object * scheme_bignum_from_double (double d ) ; 
extern char * scheme_bignum_to_string (const Scheme_Object * n , int radix ) ; 
extern char * scheme_bignum_to_allocated_string (const Scheme_Object * n , int radix , int alloc ) ; 
extern Scheme_Object * scheme_read_bignum (const mzchar * str , int offset , int radix ) ; 
extern Scheme_Object * scheme_read_bignum_bytes (const char * str , int offset , int radix ) ; 
__xform_nongcing__ extern Scheme_Object * scheme_bignum_normalize (const Scheme_Object * n ) ; 
extern Scheme_Object * scheme_make_rational (const Scheme_Object * r , const Scheme_Object * d ) ; 
__xform_nongcing__ extern double scheme_rational_to_double (const Scheme_Object * n ) ; 
extern Scheme_Object * scheme_rational_from_double (double d ) ; 
extern Scheme_Object * scheme_rational_normalize (const Scheme_Object * n ) ; 
extern Scheme_Object * scheme_rational_numerator (const Scheme_Object * n ) ; 
extern Scheme_Object * scheme_rational_denominator (const Scheme_Object * n ) ; 
extern Scheme_Object * scheme_make_complex (const Scheme_Object * r , const Scheme_Object * i ) ; 
extern Scheme_Object * scheme_complex_normalize (const Scheme_Object * n ) ; 
extern Scheme_Object * scheme_complex_real_part (const Scheme_Object * n ) ; 
extern Scheme_Object * scheme_complex_imaginary_part (const Scheme_Object * n ) ; 
__xform_nongcing__ extern int scheme_is_exact (const Scheme_Object * n ) ; 
__xform_nongcing__ extern int scheme_is_inexact (const Scheme_Object * n ) ; 
extern Scheme_Object * scheme_expand (Scheme_Object * form , Scheme_Env * env ) ; 
extern Scheme_Object * scheme_compile (Scheme_Object * form , Scheme_Env * env , int writeable ) ; 
extern Scheme_Object * scheme_read (Scheme_Object * port ) ; 
extern Scheme_Object * scheme_read_syntax (Scheme_Object * port , Scheme_Object * stxsrc ) ; 
extern void scheme_write (Scheme_Object * obj , Scheme_Object * port ) ; 
extern void scheme_display (Scheme_Object * obj , Scheme_Object * port ) ; 
extern void scheme_print (Scheme_Object * obj , Scheme_Object * port ) ; 
extern void scheme_write_w_max (Scheme_Object * obj , Scheme_Object * port , long maxl ) ; 
extern void scheme_display_w_max (Scheme_Object * obj , Scheme_Object * port , long maxl ) ; 
extern void scheme_print_w_max (Scheme_Object * obj , Scheme_Object * port , long maxl ) ; 
extern void scheme_write_byte_string (const char * str , long len , Scheme_Object * port ) ; 
extern void scheme_write_char_string (const mzchar * str , long len , Scheme_Object * port ) ; 
extern long scheme_put_byte_string (const char * who , Scheme_Object * port , const char * str , long d , long len , int rarely_block ) ; 
extern long scheme_put_char_string (const char * who , Scheme_Object * port , const mzchar * str , long d , long len ) ; 
extern char * scheme_write_to_string (Scheme_Object * obj , long * len ) ; 
extern char * scheme_display_to_string (Scheme_Object * obj , long * len ) ; 
extern char * scheme_print_to_string (Scheme_Object * obj , long * len ) ; 
extern char * scheme_write_to_string_w_max (Scheme_Object * obj , long * len , long maxl ) ; 
extern char * scheme_display_to_string_w_max (Scheme_Object * obj , long * len , long maxl ) ; 
extern char * scheme_print_to_string_w_max (Scheme_Object * obj , long * len , long maxl ) ; 
extern void scheme_debug_print (Scheme_Object * obj ) ; 
extern void scheme_flush_output (Scheme_Object * port ) ; 
extern char * scheme_format (mzchar * format , int flen , int argc , Scheme_Object * * argv , long * rlen ) ; 
extern void scheme_printf (mzchar * format , int flen , int argc , Scheme_Object * * argv ) ; 
extern char * scheme_format_utf8 (char * format , int flen , int argc , Scheme_Object * * argv , long * rlen ) ; 
extern void scheme_printf_utf8 (char * format , int flen , int argc , Scheme_Object * * argv ) ; 
extern int scheme_getc (Scheme_Object * port ) ; 
extern int scheme_get_byte (Scheme_Object * port ) ; 
extern int scheme_peekc (Scheme_Object * port ) ; 
extern int scheme_peek_byte (Scheme_Object * port ) ; 
extern int scheme_peekc_skip (Scheme_Object * port , Scheme_Object * skip ) ; 
extern int scheme_peek_byte_skip (Scheme_Object * port , Scheme_Object * skip , Scheme_Object * unless_evt ) ; 
extern int scheme_getc_special_ok (Scheme_Object * port ) ; 
extern int scheme_get_byte_special_ok (Scheme_Object * port ) ; 
extern int scheme_peekc_special_ok (Scheme_Object * port ) ; 
extern int scheme_peek_byte_special_ok_skip (Scheme_Object * port , Scheme_Object * skip , Scheme_Object * unless_evt ) ; 
extern int scheme_peekc_special_ok_skip (Scheme_Object * port , Scheme_Object * skip ) ; 
extern void scheme_ungetc (int ch , Scheme_Object * port ) ; 
extern int scheme_byte_ready (Scheme_Object * port ) ; 
extern int scheme_char_ready (Scheme_Object * port ) ; 
extern int scheme_peekc_is_ungetc (Scheme_Object * port ) ; 
extern void scheme_need_wakeup (Scheme_Object * port , void * fds ) ; 
extern long scheme_get_byte_string (const char * who , Scheme_Object * port , char * buffer , long offset , long size , int only_avail , int peek , Scheme_Object * peek_skip ) ; 
extern long scheme_get_byte_string_unless (const char * who , Scheme_Object * port , char * buffer , long offset , long size , int only_avail , int peek , Scheme_Object * peek_skip , Scheme_Object * unless_evt ) ; 
extern long scheme_get_byte_string_special_ok_unless (const char * who , Scheme_Object * port , char * buffer , long offset , long size , int only_avail , int peek , Scheme_Object * peek_skip , Scheme_Object * unless_evt ) ; 
extern Scheme_Object * scheme_progress_evt (Scheme_Object * port ) ; 
extern int scheme_peeked_read (Scheme_Object * port , long size , Scheme_Object * unless_evt , Scheme_Object * target_evt ) ; 
extern long scheme_get_char_string (const char * who , Scheme_Object * port , mzchar * buffer , long offset , long size , int peek , Scheme_Object * peek_skip ) ; 
extern long scheme_get_bytes (Scheme_Object * port , long size , char * buffer , int offset ) ; 
extern Scheme_Object * scheme_get_ready_special (Scheme_Object * port , Scheme_Object * stxsrc , int peek ) ; 
extern long scheme_tell (Scheme_Object * port ) ; 
extern long scheme_output_tell (Scheme_Object * port ) ; 
extern long scheme_tell_line (Scheme_Object * port ) ; 
extern long scheme_tell_column (Scheme_Object * port ) ; 
extern void scheme_tell_all (Scheme_Object * port , long * line , long * col , long * pos ) ; 
extern void scheme_count_lines (Scheme_Object * port ) ; 
extern void scheme_close_input_port (Scheme_Object * port ) ; 
extern void scheme_close_output_port (Scheme_Object * port ) ; 
extern Scheme_Object * scheme_write_special (int argc , Scheme_Object * argv [] ) ; 
extern Scheme_Object * scheme_write_special_nonblock (int argc , Scheme_Object * argv [] ) ; 
extern Scheme_Object * scheme_make_write_evt (const char * who , Scheme_Object * port , Scheme_Object * special , char * str , long start , long size ) ; 
extern Scheme_Port * scheme_port_record (Scheme_Object * port ) ; 
extern Scheme_Input_Port * scheme_input_port_record (Scheme_Object * port ) ; 
extern Scheme_Output_Port * scheme_output_port_record (Scheme_Object * port ) ; 
__xform_nongcing__ extern int scheme_is_input_port (Scheme_Object * port ) ; 
__xform_nongcing__ extern int scheme_is_output_port (Scheme_Object * port ) ; 
extern Scheme_Object * scheme_make_port_type (const char * name ) ; 
extern Scheme_Input_Port * scheme_make_input_port (Scheme_Object * subtype , void * data , Scheme_Object * name , Scheme_Get_String_Fun get_byte_string_fun , Scheme_Peek_String_Fun peek_string_fun , Scheme_Progress_Evt_Fun progress_evt_fun , Scheme_Peeked_Read_Fun peeked_read_fun , Scheme_In_Ready_Fun byte_ready_fun , Scheme_Close_Input_Fun close_fun , Scheme_Need_Wakeup_Input_Fun need_wakeup_fun , int must_close ) ; 
extern Scheme_Output_Port * scheme_make_output_port (Scheme_Object * subtype , void * data , Scheme_Object * name , Scheme_Write_String_Evt_Fun write_byte_string_evt_fun , Scheme_Write_String_Fun write_byte_string_fun , Scheme_Out_Ready_Fun ready_fun , Scheme_Close_Output_Fun close_fun , Scheme_Need_Wakeup_Output_Fun need_wakeup_fun , Scheme_Write_Special_Evt_Fun write_special_evt_fun , Scheme_Write_Special_Fun write_special_fun , int must_close ) ; 
extern void scheme_set_port_location_fun (Scheme_Port * port , Scheme_Location_Fun location_fun ) ; 
extern void scheme_set_port_count_lines_fun (Scheme_Port * port , Scheme_Count_Lines_Fun count_lines_fun ) ; 
extern Scheme_Object * scheme_progress_evt_via_get (Scheme_Input_Port * port ) ; 
extern int scheme_peeked_read_via_get (Scheme_Input_Port * port , long size , Scheme_Object * unless_evt , Scheme_Object * target_ch ) ; 
extern Scheme_Object * scheme_write_evt_via_write (Scheme_Output_Port * port , const char * str , long offset , long size ) ; 
extern Scheme_Object * scheme_write_special_evt_via_write_special (Scheme_Output_Port * port , Scheme_Object * special ) ; 
extern Scheme_Object * scheme_open_input_file (const char * name , const char * who ) ; 
extern Scheme_Object * scheme_open_output_file (const char * name , const char * who ) ; 
extern Scheme_Object * scheme_open_output_file_with_mode (const char * name , const char * who , int text ) ; 
extern Scheme_Object * scheme_make_file_input_port (FILE * fp ) ; 
extern Scheme_Object * scheme_make_named_file_input_port (FILE * fp , Scheme_Object * name ) ; 
extern Scheme_Object * scheme_make_file_output_port (FILE * fp ) ; 
extern Scheme_Object * scheme_make_fd_input_port (int fd , Scheme_Object * name , int regfile , int win_textmode ) ; 
extern Scheme_Object * scheme_make_fd_output_port (int fd , Scheme_Object * name , int regfile , int win_textmode , int read_too ) ; 
extern Scheme_Object * scheme_make_byte_string_input_port (const char * str ) ; 
extern Scheme_Object * scheme_make_sized_byte_string_input_port (const char * str , long len ) ; 
extern Scheme_Object * scheme_make_byte_string_output_port () ; 
extern char * scheme_get_sized_byte_string_output (Scheme_Object * port , long * len ) ; 
extern char * scheme_get_reset_sized_byte_string_output (Scheme_Object * port , long * len , int reset , long startpos , long endpos ) ; 
extern void scheme_pipe (Scheme_Object * * read , Scheme_Object * * write ) ; 
extern void scheme_pipe_with_limit (Scheme_Object * * write , Scheme_Object * * read , int maxsize ) ; 
extern Scheme_Object * scheme_make_null_output_port (int can_write_special ) ; 
extern Scheme_Object * scheme_make_redirect_output_port (Scheme_Object * port ) ; 
extern long scheme_set_file_position (Scheme_Object * port , long pos ) ; 
extern int scheme_file_exists (char * filename ) ; 
extern int scheme_directory_exists (char * dirname ) ; 
extern char * scheme_expand_filename (char * filename , int ilen , const char * errorin , int * ex , int guards ) ; 
extern char * scheme_expand_string_filename (Scheme_Object * f , const char * errorin , int * ex , int guards ) ; 
extern char * scheme_os_getcwd (char * buf , int buflen , int * actlen , int noexn ) ; 
extern int scheme_os_setcwd (char * buf , int noexn ) ; 
extern char * scheme_getdrive (void ) ; 
extern Scheme_Object * scheme_split_path (const char * path , int len , Scheme_Object * * base , int * isdir , int kind ) ; 
extern Scheme_Object * scheme_build_path (int argc , Scheme_Object * * argv ) ; 
extern Scheme_Object * scheme_path_to_directory_path (Scheme_Object * p ) ; 
extern Scheme_Object * scheme_path_to_complete_path (Scheme_Object * path , Scheme_Object * relto_path ) ; 
extern Scheme_Object * scheme_make_path (const char * chars ) ; 
extern Scheme_Object * scheme_make_sized_path (char * chars , long len , int copy ) ; 
extern Scheme_Object * scheme_make_sized_offset_path (char * chars , long d , long len , int copy ) ; 
extern Scheme_Object * scheme_make_sized_offset_kind_path (char * chars , long d , long len , int copy , int kind ) ; 
extern Scheme_Object * scheme_make_path_without_copying (char * chars ) ; 
extern void * scheme_alloc_fdset_array (int count , int permanent ) ; 
extern void * scheme_init_fdset_array (void * fdarray , int count ) ; 
extern void * scheme_get_fdset (void * fdarray , int pos ) ; 
extern void scheme_fdzero (void * fd ) ; 
extern void scheme_fdset (void * fd , int pos ) ; 
extern void scheme_fdclr (void * fd , int pos ) ; 
extern int scheme_fdisset (void * fd , int pos ) ; 
extern void scheme_add_fd_handle (void * h , void * fds , int repost ) ; 
extern void scheme_add_fd_eventmask (void * fds , int mask ) ; 
extern void scheme_security_check_file (const char * who , const char * filename , int guards ) ; 
extern void scheme_security_check_file_link (const char * who , const char * filename , const char * content ) ; 
extern void scheme_security_check_network (const char * who , const char * host , int port , int client ) ; 
extern struct addrinfo * scheme_get_host_address (const char * address , int id , int * err , int family , int passive , int tcp ) ; 
extern void scheme_free_host_address (struct addrinfo * a ) ; 
extern const char * scheme_host_address_strerror (int errnum ) ; 
extern void scheme_getnameinfo (void * sa , int salen , char * host , int hostlen , char * serv , int servlen ) ; 
extern int scheme_get_port_file_descriptor (Scheme_Object * p , long * _fd ) ; 
extern long scheme_get_port_fd (Scheme_Object * p ) ; 
extern int scheme_get_port_socket (Scheme_Object * p , long * _s ) ; 
extern void scheme_socket_to_ports (long s , const char * name , int takeover , Scheme_Object * * _inp , Scheme_Object * * _outp ) ; 
extern void scheme_set_type_printer (Scheme_Type stype , Scheme_Type_Printer printer ) ; 
extern void scheme_print_bytes (Scheme_Print_Params * pp , const char * str , int offset , int len ) ; 
extern void scheme_print_utf8 (Scheme_Print_Params * pp , const char * str , int offset , int len ) ; 
extern void scheme_print_string (Scheme_Print_Params * pp , const mzchar * str , int offset , int len ) ; 
extern Scheme_Object * scheme_read_byte_string (Scheme_Object * port ) ; 
extern Scheme_Object * scheme_make_namespace (int argc , Scheme_Object * argv [] ) ; 
extern void scheme_add_namespace_option (Scheme_Object * key , void (* f ) (Scheme_Env * ) ) ; 
extern void scheme_require_from_original_env (Scheme_Env * env , int syntax_only ) ; 
extern void scheme_add_global (const char * name , Scheme_Object * val , Scheme_Env * env ) ; 
extern void scheme_add_global_symbol (Scheme_Object * name , Scheme_Object * val , Scheme_Env * env ) ; 
extern Scheme_Object * scheme_make_envunbox (Scheme_Object * value ) ; 
extern Scheme_Object * scheme_lookup_global (Scheme_Object * symbol , Scheme_Env * env ) ; 
extern Scheme_Bucket * scheme_global_bucket (Scheme_Object * symbol , Scheme_Env * env ) ; 
extern Scheme_Bucket * scheme_global_keyword_bucket (Scheme_Object * symbol , Scheme_Env * env ) ; 
extern Scheme_Bucket * scheme_module_bucket (Scheme_Object * mod , Scheme_Object * var , int pos , Scheme_Env * env ) ; 
extern Scheme_Object * scheme_builtin_value (const char * name ) ; 
extern void scheme_set_global_bucket (char * proc , Scheme_Bucket * var , Scheme_Object * val , int set_undef ) ; 
extern void scheme_install_macro (Scheme_Bucket * b , Scheme_Object * v ) ; 
extern void scheme_save_initial_module_set (Scheme_Env * env ) ; 
extern Scheme_Env * scheme_primitive_module (Scheme_Object * name , Scheme_Env * for_env ) ; 
extern void scheme_finish_primitive_module (Scheme_Env * env ) ; 
extern void scheme_protect_primitive_provide (Scheme_Env * env , Scheme_Object * name ) ; 
extern Scheme_Object * scheme_make_modidx (Scheme_Object * path , Scheme_Object * base , Scheme_Object * resolved ) ; 
extern Scheme_Object * scheme_apply_for_syntax_in_env (Scheme_Object * proc , Scheme_Env * env ) ; 
extern Scheme_Object * scheme_dynamic_require (int argc , Scheme_Object * argv [] ) ; 
extern Scheme_Object * scheme_intern_symbol (const char * name ) ; 
extern Scheme_Object * scheme_intern_exact_symbol (const char * name , unsigned int len ) ; 
extern Scheme_Object * scheme_intern_exact_char_symbol (const mzchar * name , unsigned int len ) ; 
extern Scheme_Object * scheme_make_symbol (const char * name ) ; 
extern Scheme_Object * scheme_make_exact_symbol (const char * name , unsigned int len ) ; 
extern Scheme_Object * scheme_make_exact_char_symbol (const mzchar * name , unsigned int len ) ; 
extern const char * scheme_symbol_name (Scheme_Object * sym ) ; 
extern const char * scheme_symbol_name_and_size (Scheme_Object * sym , unsigned int * l , int flags ) ; 
extern char * scheme_symbol_val (Scheme_Object * sym ) ; 
extern Scheme_Object * scheme_intern_exact_keyword (const char * name , unsigned int len ) ; 
extern Scheme_Object * scheme_intern_exact_char_keyword (const mzchar * name , unsigned int len ) ; 
extern Scheme_Object * * scheme_make_struct_values (Scheme_Object * struct_type , Scheme_Object * * names , int count , int flags ) ; 
extern Scheme_Object * * scheme_make_struct_names (Scheme_Object * base , Scheme_Object * field_names , int flags , int * count_out ) ; 
extern Scheme_Object * scheme_make_struct_type (Scheme_Object * base , Scheme_Object * parent , Scheme_Object * inspector , int num_fields , int num_uninit_fields , Scheme_Object * uninit_val , Scheme_Object * properties , Scheme_Object * guard ) ; 
extern Scheme_Object * scheme_make_struct_instance (Scheme_Object * stype , int argc , Scheme_Object * * argv ) ; 
extern Scheme_Object * scheme_make_struct_exptime (Scheme_Object * * names , int count , Scheme_Object * super_sym , Scheme_Object * super_exptime , int flags ) ; 
__xform_nongcing__ extern int scheme_is_struct_instance (Scheme_Object * type , Scheme_Object * v ) ; 
extern Scheme_Object * scheme_struct_ref (Scheme_Object * s , int pos ) ; 
extern void scheme_struct_set (Scheme_Object * s , int pos , Scheme_Object * v ) ; 
extern Scheme_Object * scheme_make_struct_type_property (Scheme_Object * name ) ; 
extern Scheme_Object * scheme_make_struct_type_property_w_guard (Scheme_Object * name , Scheme_Object * guard ) ; 
__xform_nongcing__ extern Scheme_Object * scheme_struct_type_property_ref (Scheme_Object * prop , Scheme_Object * s ) ; 
extern Scheme_Object * scheme_make_location (Scheme_Object * src , Scheme_Object * line , Scheme_Object * col , Scheme_Object * pos , Scheme_Object * span ) ; 
extern int scheme_is_location (Scheme_Object * o ) ; 
extern Scheme_Object * scheme_make_inspector (Scheme_Object * superior ) ; 
__xform_nongcing__ extern int scheme_is_subinspector (Scheme_Object * i , Scheme_Object * sup ) ; 
__xform_nongcing__ extern int scheme_eq (Scheme_Object * obj1 , Scheme_Object * obj2 ) ; 
__xform_nongcing__ extern int scheme_eqv (Scheme_Object * obj1 , Scheme_Object * obj2 ) ; 
extern int scheme_equal (Scheme_Object * obj1 , Scheme_Object * obj2 ) ; 
__xform_nongcing__ extern long scheme_hash_key (Scheme_Object * o ) ; 
extern long scheme_equal_hash_key (Scheme_Object * o ) ; 
extern long scheme_equal_hash_key2 (Scheme_Object * o ) ; 
extern void scheme_set_type_equality (Scheme_Type type , Scheme_Equal_Proc f , Scheme_Primary_Hash_Proc hash1 , Scheme_Secondary_Hash_Proc hash2 ) ; 
extern Scheme_Object * scheme_build_list (int argc , Scheme_Object * * argv ) ; 
extern Scheme_Object * scheme_build_list_offset (int argc , Scheme_Object * * argv , int delta ) ; 
extern void scheme_make_list_immutable (Scheme_Object * l ) ; 
extern int scheme_list_length (Scheme_Object * list ) ; 
extern int scheme_proper_list_length (Scheme_Object * list ) ; 
extern Scheme_Object * scheme_alloc_list (int size ) ; 
extern Scheme_Object * scheme_map_1 (Scheme_Object * (* f ) (Scheme_Object * ) , Scheme_Object * l ) ; 
extern Scheme_Object * scheme_car (Scheme_Object * pair ) ; 
extern Scheme_Object * scheme_cdr (Scheme_Object * pair ) ; 
extern Scheme_Object * scheme_cadr (Scheme_Object * pair ) ; 
extern Scheme_Object * scheme_caddr (Scheme_Object * pair ) ; 
extern Scheme_Object * scheme_vector_to_list (Scheme_Object * vec ) ; 
extern Scheme_Object * scheme_list_to_vector (Scheme_Object * list ) ; 
extern Scheme_Object * scheme_append (Scheme_Object * lstx , Scheme_Object * lsty ) ; 
extern Scheme_Object * scheme_reverse (Scheme_Object * l ) ; 
extern Scheme_Object * scheme_box (Scheme_Object * v ) ; 
extern Scheme_Object * scheme_unbox (Scheme_Object * obj ) ; 
extern void scheme_set_box (Scheme_Object * b , Scheme_Object * v ) ; 
extern Scheme_Object * scheme_make_weak_box (Scheme_Object * v ) ; 
extern Scheme_Object * scheme_make_ephemeron (Scheme_Object * key , Scheme_Object * val ) ; 
extern Scheme_Object * scheme_ephemeron_value (Scheme_Object * o ) ; 
extern Scheme_Object * scheme_load (const char * file ) ; 
extern Scheme_Object * scheme_load_extension (const char * filename , Scheme_Env * env ) ; 
extern void scheme_register_extension_global (void * ptr , long size ) ; 
extern long scheme_get_seconds (void ) ; 
extern long scheme_get_milliseconds (void ) ; 
extern double scheme_get_inexact_milliseconds (void ) ; 
extern long scheme_get_process_milliseconds (void ) ; 
extern char * scheme_banner (void ) ; 
extern char * scheme_version (void ) ; 
extern int scheme_check_proc_arity (const char * where , int a , int which , int argc , Scheme_Object * * argv ) ; 
extern int scheme_check_proc_arity2 (const char * where , int a , int which , int argc , Scheme_Object * * argv , int false_ok ) ; 
extern char * scheme_make_provided_string (Scheme_Object * o , int count , int * len ) ; 
extern char * scheme_make_args_string (char * s , int which , int argc , Scheme_Object * * argv , long * len ) ; 
extern void scheme_no_dumps (char * why ) ; 
extern const char * scheme_system_library_subpath () ; 
extern void scheme_signal_received (void ) ; 
extern int scheme_char_strlen (const mzchar * s ) ; 
long scheme_hash_key (Scheme_Object * o ) ; 
typedef int (* Compare_Proc ) (void * v1 , void * v2 ) ; 
Scheme_Object * scheme_dump_gc_stats (int c , Scheme_Object * p [] ) ; 
extern long scheme_total_gc_time ; 
extern int scheme_cont_capture_count ; 
extern int scheme_continuation_application_count ; 
int scheme_num_types (void ) ; 
void scheme_reset_finalizations (void ) ; 
extern unsigned long scheme_get_stack_base (void ) ; 
int scheme_propagate_ephemeron_marks (void ) ; 
void scheme_clear_ephemerons (void ) ; 
extern int scheme_starting_up ; 
void scheme_init_portable_case (void ) ; 
void scheme_init_stack_check (void ) ; 
void scheme_init_overflow (void ) ; 
void scheme_register_traversers (void ) ; 
void scheme_init_hash_key_procs (void ) ; 
Scheme_Thread * scheme_make_thread (void ) ; 
void scheme_init_true_false (void ) ; 
void scheme_init_symbol_table (void ) ; 
void scheme_init_symbol_type (Scheme_Env * env ) ; 
void scheme_init_type (Scheme_Env * env ) ; 
void scheme_init_list (Scheme_Env * env ) ; 
void scheme_init_stx (Scheme_Env * env ) ; 
void scheme_init_module (Scheme_Env * env ) ; 
void scheme_init_port (Scheme_Env * env ) ; 
void scheme_init_port_fun (Scheme_Env * env ) ; 
void scheme_init_network (Scheme_Env * env ) ; 
void scheme_init_file (Scheme_Env * env ) ; 
void scheme_init_proc (Scheme_Env * env ) ; 
void scheme_init_vector (Scheme_Env * env ) ; 
void scheme_init_string (Scheme_Env * env ) ; 
void scheme_init_number (Scheme_Env * env ) ; 
void scheme_init_numarith (Scheme_Env * env ) ; 
void scheme_init_numcomp (Scheme_Env * env ) ; 
void scheme_init_numstr (Scheme_Env * env ) ; 
void scheme_init_eval (Scheme_Env * env ) ; 
void scheme_init_promise (Scheme_Env * env ) ; 
void scheme_init_struct (Scheme_Env * env ) ; 
void scheme_init_fun (Scheme_Env * env ) ; 
void scheme_init_symbol (Scheme_Env * env ) ; 
void scheme_init_char (Scheme_Env * env ) ; 
void scheme_init_bool (Scheme_Env * env ) ; 
void scheme_init_syntax (Scheme_Env * env ) ; 
void scheme_init_error (Scheme_Env * env ) ; 
void scheme_init_exn (Scheme_Env * env ) ; 
void scheme_init_debug (Scheme_Env * env ) ; 
void scheme_init_thread (Scheme_Env * env ) ; 
void scheme_init_read (Scheme_Env * env ) ; 
void scheme_init_print (Scheme_Env * env ) ; 
void scheme_init_sema (Scheme_Env * env ) ; 
void scheme_init_dynamic_extension (Scheme_Env * env ) ; 
extern void scheme_regexp_initialize (Scheme_Env * env ) ; 
void scheme_init_memtrace (Scheme_Env * env ) ; 
void scheme_init_parameterization (Scheme_Env * env ) ; 
void scheme_init_getenv (void ) ; 
void scheme_init_foreign (Scheme_Env * env ) ; 
typedef Scheme_Object * (* Scheme_Type_Reader ) (Scheme_Object * list ) ; 
typedef Scheme_Object * (* Scheme_Type_Writer ) (Scheme_Object * obj ) ; 
extern Scheme_Type_Reader * scheme_type_readers ; 
extern Scheme_Type_Writer * scheme_type_writers ; 
extern Scheme_Equal_Proc * scheme_type_equals ; 
extern Scheme_Primary_Hash_Proc * scheme_type_hash1s ; 
extern Scheme_Secondary_Hash_Proc * scheme_type_hash2s ; 
void scheme_init_port_config (void ) ; 
void scheme_init_port_fun_config (void ) ; 
Scheme_Config * scheme_init_error_escape_proc (Scheme_Config * c ) ; 
void scheme_init_error_config (void ) ; 
void scheme_init_exn_config (void ) ; 
void scheme_finish_kernel (Scheme_Env * env ) ; 
Scheme_Object * scheme_make_initial_inspectors (void ) ; 
extern int scheme_builtin_ref_counter ; 
Scheme_Object * * scheme_make_builtin_references_table (void ) ; 
Scheme_Object * scheme_make_local (Scheme_Type type , int pos ) ; 
void scheme_add_embedded_builtins (Scheme_Env * env ) ; 
void scheme_do_add_global_symbol (Scheme_Env * env , Scheme_Object * sym , Scheme_Object * obj , int constant , int primitive ) ; 
extern Scheme_Object * scheme_values_func ; 
extern Scheme_Object * scheme_procedure_p_proc ; 
extern Scheme_Object * scheme_void_proc ; 
extern Scheme_Object * scheme_call_with_values_proc ; 
extern Scheme_Object * scheme_make_struct_type_proc ; 
extern Scheme_Object * scheme_define_values_syntax , * scheme_define_syntaxes_syntax ; 
extern Scheme_Object * scheme_lambda_syntax ; 
extern Scheme_Object * scheme_begin_syntax ; 
extern Scheme_Object * scheme_not_prim ; 
extern Scheme_Object * scheme_eq_prim ; 
extern Scheme_Object * scheme_eqv_prim ; 
extern Scheme_Object * scheme_equal_prim ; 
extern Scheme_Object * scheme_def_exit_proc ; 
extern Scheme_Object * scheme_orig_stdout_port ; 
extern Scheme_Object * scheme_orig_stdin_port ; 
extern Scheme_Object * scheme_orig_stderr_port ; 
extern Scheme_Object * scheme_arity_at_least , * scheme_make_arity_at_least ; 
extern Scheme_Object * scheme_write_proc , * scheme_display_proc , * scheme_print_proc ; 
extern Scheme_Object * scheme_raise_arity_error_proc ; 
extern Scheme_Object * scheme_date ; 
extern Scheme_Object * scheme_module_stx ; 
extern Scheme_Object * scheme_begin_stx ; 
extern Scheme_Object * scheme_define_values_stx ; 
extern Scheme_Object * scheme_define_syntaxes_stx ; 
extern Scheme_Object * scheme_top_stx ; 
extern Scheme_Object * scheme_recur_symbol , * scheme_display_symbol , * scheme_write_special_symbol ; 
extern Scheme_Object * scheme_none_symbol , * scheme_line_symbol , * scheme_block_symbol ; 
extern Scheme_Object * scheme_stack_dump_key ; 
extern Scheme_Object * scheme_default_prompt_tag ; 
extern Scheme_Object * scheme_system_idle_channel ; 
extern Scheme_Object * scheme_input_port_property , * scheme_output_port_property ; 
extern Scheme_Object * * scheme_current_runstack ; 
extern Scheme_Object * * scheme_current_runstack_start ; 
extern long scheme_current_cont_mark_stack ; 
extern long scheme_current_cont_mark_pos ; 
extern volatile int scheme_fuel_counter ; 
extern Scheme_Thread * scheme_main_thread ; 
void scheme_block_child_signals (int block ) ; 
Scheme_Object * * scheme_alloc_runstack (long len ) ; 
void scheme_set_runstack_limits (Scheme_Object * * rs , long len , long start , long end ) ; 
void scheme_alloc_list_stack (Scheme_Thread * p ) ; 
void scheme_clean_list_stack (Scheme_Thread * p ) ; 
Scheme_Object * scheme_get_thread_dead (Scheme_Thread * p ) ; 
Scheme_Object * scheme_get_thread_suspend (Scheme_Thread * p ) ; 
void scheme_zero_unneeded_rands (Scheme_Thread * p ) ; 
int scheme_can_break (Scheme_Thread * p ) ; 
extern int scheme_overflow_count ; 
struct Scheme_Custodian {
  Scheme_Object so ; 
  char shut_down , has_limit ; 
  int count , alloc ; 
  Scheme_Object * * * boxes ; 
  Scheme_Custodian_Reference * * mrefs ; 
  Scheme_Close_Custodian_Client * * closers ; 
  void * * data ; 
  Scheme_Custodian_Reference * parent ; 
  Scheme_Custodian_Reference * sibling ; 
  Scheme_Custodian_Reference * children ; 
  Scheme_Custodian_Reference * global_next ; 
  Scheme_Custodian_Reference * global_prev ; 
  int gc_owner_set ; 
  Scheme_Object * cust_boxes ; 
}
; 
typedef struct Scheme_Custodian_Box {
  Scheme_Object so ; 
  Scheme_Custodian * cust ; 
  Scheme_Object * v ; 
}
Scheme_Custodian_Box ; 
Scheme_Thread * scheme_do_close_managed (Scheme_Custodian * m , Scheme_Exit_Closer_Func f ) ; 
typedef struct Scheme_Security_Guard {
  Scheme_Object so ; 
  struct Scheme_Security_Guard * parent ; 
  Scheme_Object * file_proc ; 
  Scheme_Object * network_proc ; 
  Scheme_Object * link_proc ; 
}
Scheme_Security_Guard ; 
typedef struct {
  Scheme_Thread * false_positive_ok ; 
  int potentially_false_positive ; 
  Scheme_Object * current_syncing ; 
  double sleep_end ; 
  int w_i ; 
  short spin ; 
  short is_poll ; 
}
Scheme_Schedule_Info ; 
void scheme_set_sync_target (Scheme_Schedule_Info * sinfo , Scheme_Object * target , Scheme_Object * wrap , Scheme_Object * nack , int repost , int retry ) ; 
typedef int (* Scheme_Ready_Fun_FPC ) (Scheme_Object * o , Scheme_Schedule_Info * sinfo ) ; 
void scheme_check_break_now (void ) ; 
extern int scheme_main_was_once_suspended ; 
typedef struct {
  Scheme_Type type ; 
  Scheme_Bucket_Table * extensions ; 
  Scheme_Object * prims [1 ] ; 
}
Scheme_Parameterization ; 
struct Scheme_Config {
  Scheme_Object so ; 
  Scheme_Object * key ; 
  Scheme_Object * cell ; 
  int depth ; 
  struct Scheme_Config * next ; 
}
; 
extern Scheme_Object * scheme_parameterization_key ; 
extern Scheme_Object * scheme_exn_handler_key ; 
extern Scheme_Object * scheme_break_enabled_key ; 
extern void scheme_flatten_config (Scheme_Config * c ) ; 
extern Scheme_Object * scheme_apply_thread_thunk (Scheme_Object * rator ) ; 
typedef struct {
  Scheme_Bucket bucket ; 
  short flags , id ; 
}
Scheme_Bucket_With_Flags ; 
typedef Scheme_Bucket_With_Flags Scheme_Bucket_With_Ref_Id ; 
typedef struct {
  Scheme_Bucket_With_Ref_Id bucket ; 
  Scheme_Env * home ; 
}
Scheme_Bucket_With_Home ; 
Scheme_Object * scheme_get_primitive_global (Scheme_Object * var , Scheme_Env * env , int bucket_ok , int can_opt , int signal ) ; 
void scheme_add_bucket_to_table (Scheme_Bucket_Table * table , Scheme_Bucket * b ) ; 
Scheme_Bucket * scheme_bucket_or_null_from_table (Scheme_Bucket_Table * table , const char * key , int add ) ; 
void scheme_require_from_original_env (Scheme_Env * env , int syntax_only ) ; 
typedef struct Scheme_Inspector {
  Scheme_Object so ; 
  int depth ; 
  struct Scheme_Inspector * superior ; 
}
Scheme_Inspector ; 
typedef struct Scheme_Struct_Property {
  Scheme_Object so ; 
  Scheme_Object * name ; 
  Scheme_Object * guard ; 
}
Scheme_Struct_Property ; 
int scheme_inspector_sees_part (Scheme_Object * s , Scheme_Object * insp , int pos ) ; 
typedef struct Scheme_Struct_Type {
  Scheme_Object so ; 
  mzshort num_slots , num_islots ; 
  mzshort name_pos ; 
  Scheme_Object * name ; 
  Scheme_Object * inspector ; 
  Scheme_Object * accessor , * mutator ; 
  Scheme_Object * uninit_val ; 
  Scheme_Object * * props ; 
  int num_props ; 
  Scheme_Object * proc_attr ; 
  char * immutables ; 
  Scheme_Object * guard ; 
  struct Scheme_Struct_Type * parent_types [1 ] ; 
}
Scheme_Struct_Type ; 
typedef struct Scheme_Structure {
  Scheme_Object so ; 
  Scheme_Struct_Type * stype ; 
  Scheme_Object * slots [1 ] ; 
}
Scheme_Structure ; 
typedef struct Struct_Proc_Info {
  Scheme_Type type ; 
  Scheme_Struct_Type * struct_type ; 
  char * func_name ; 
  mzshort field ; 
}
Struct_Proc_Info ; 
Scheme_Object * * scheme_make_struct_names_from_array (const char * base , int fcount , const char * * field_names , int flags , int * count_out ) ; 
Scheme_Object * scheme_make_struct_type_from_string (const char * base , Scheme_Object * parent , int num_fields , Scheme_Object * props , Scheme_Object * guard , int immutable ) ; 
Scheme_Object * scheme_make_proc_struct_type (Scheme_Object * base , Scheme_Object * parent , Scheme_Object * inspector , int num_fields , int num_uninit , Scheme_Object * uninit_val , Scheme_Object * proc_attr , Scheme_Object * guard ) ; 
Scheme_Object * scheme_struct_to_vector (Scheme_Object * _s , Scheme_Object * unknown_val , Scheme_Object * insp ) ; 
Scheme_Object * scheme_extract_struct_procedure (Scheme_Object * obj , int num_rands , Scheme_Object * * rands , int * is_method ) ; 
Scheme_Object * scheme_proc_struct_name_source (Scheme_Object * a ) ; 
Scheme_Object * scheme_is_writable_struct (Scheme_Object * s ) ; 
extern Scheme_Object * scheme_source_property ; 
typedef struct Scheme_Stx_Srcloc {
  Scheme_Type type ; 
  long line , col , pos , span ; 
  Scheme_Object * src ; 
}
Scheme_Stx_Srcloc ; 
typedef struct Scheme_Stx {
  Scheme_Inclhash_Object iso ; 
  Scheme_Object * val ; 
  Scheme_Stx_Srcloc * srcloc ; 
  Scheme_Object * wraps ; 
  union {
    long lazy_prefix ; 
    Scheme_Object * modinfo_cache ; 
  }
  u ; 
  Scheme_Object * certs ; 
  Scheme_Object * props ; 
}
Scheme_Stx ; 
typedef struct Scheme_Stx_Offset {
  Scheme_Object so ; 
  long line , col , pos ; 
  Scheme_Object * src ; 
}
Scheme_Stx_Offset ; 
struct Scheme_Marshal_Tables ; 
struct Scheme_Unmarshal_Tables ; 
Scheme_Object * scheme_make_stx (Scheme_Object * val , Scheme_Stx_Srcloc * srcloc , Scheme_Object * props ) ; 
Scheme_Object * scheme_make_stx_w_offset (Scheme_Object * val , long line , long col , long pos , long span , Scheme_Object * src , Scheme_Object * props ) ; 
Scheme_Object * scheme_make_graph_stx (Scheme_Object * stx , long line , long col , long pos ) ; 
Scheme_Object * scheme_make_renamed_stx (Scheme_Object * sym , Scheme_Object * rn ) ; 
Scheme_Object * scheme_new_stx_simplify_cache (void ) ; 
void scheme_simplify_stx (Scheme_Object * stx , Scheme_Object * simplify_cache ) ; 
Scheme_Object * scheme_datum_to_syntax (Scheme_Object * o , Scheme_Object * stx_src , Scheme_Object * stx_wraps , int cangraph , int copyprops ) ; 
Scheme_Object * scheme_syntax_to_datum (Scheme_Object * stx , int with_marks , struct Scheme_Marshal_Tables * mt ) ; 
Scheme_Object * scheme_unmarshal_datum_to_syntax (Scheme_Object * o , struct Scheme_Unmarshal_Tables * ut , int can_graph ) ; 
int scheme_syntax_is_graph (Scheme_Object * stx ) ; 
Scheme_Object * scheme_stx_track (Scheme_Object * naya , Scheme_Object * old , Scheme_Object * origin ) ; 
int scheme_stx_has_empty_wraps (Scheme_Object * ) ; 
Scheme_Object * scheme_new_mark (void ) ; 
Scheme_Object * scheme_add_remove_mark (Scheme_Object * o , Scheme_Object * m ) ; 
Scheme_Object * scheme_make_rename (Scheme_Object * newname , int c ) ; 
void scheme_set_rename (Scheme_Object * rnm , int pos , Scheme_Object * oldname ) ; 
Scheme_Object * scheme_make_rename_rib (void ) ; 
void scheme_add_rib_rename (Scheme_Object * ro , Scheme_Object * rename ) ; 
void scheme_drop_first_rib_rename (Scheme_Object * ro ) ; 
Scheme_Object * scheme_add_rename (Scheme_Object * o , Scheme_Object * rename ) ; 
Scheme_Object * scheme_add_rename_rib (Scheme_Object * o , Scheme_Object * rib ) ; 
Scheme_Object * scheme_stx_remove_extra_marks (Scheme_Object * o , Scheme_Object * relative_to , Scheme_Object * uid ) ; 
Scheme_Object * scheme_make_module_rename (long phase , int kind , Scheme_Hash_Table * mns ) ; 
void scheme_extend_module_rename (Scheme_Object * rn , Scheme_Object * modname , Scheme_Object * locname , Scheme_Object * exname , Scheme_Object * nominal_src , Scheme_Object * nominal_ex , int mod_phase , int drop_for_marshal ) ; 
void scheme_extend_module_rename_with_kernel (Scheme_Object * rn , Scheme_Object * nominal_src ) ; 
void scheme_save_module_rename_unmarshal (Scheme_Object * rn , Scheme_Object * info ) ; 
void scheme_do_module_rename_unmarshal (Scheme_Object * rn , Scheme_Object * info , Scheme_Object * modidx_shift_from , Scheme_Object * modidx_shift_to , Scheme_Hash_Table * export_registry ) ; 
void scheme_remove_module_rename (Scheme_Object * mrn , Scheme_Object * localname ) ; 
void scheme_append_module_rename (Scheme_Object * src , Scheme_Object * dest ) ; 
void scheme_list_module_rename (Scheme_Object * src , Scheme_Hash_Table * ht ) ; 
Scheme_Object * scheme_rename_to_stx (Scheme_Object * rn ) ; 
Scheme_Object * scheme_stx_to_rename (Scheme_Object * stx ) ; 
Scheme_Object * scheme_stx_shift_rename (Scheme_Object * mrn , Scheme_Object * old_midx , Scheme_Object * new_midx ) ; 
Scheme_Hash_Table * scheme_module_rename_marked_names (Scheme_Object * rn ) ; 
Scheme_Object * scheme_stx_content (Scheme_Object * o ) ; 
Scheme_Object * scheme_flatten_syntax_list (Scheme_Object * lst , int * islist ) ; 
int scheme_stx_free_eq (Scheme_Object * a , Scheme_Object * b , long phase ) ; 
int scheme_stx_module_eq (Scheme_Object * a , Scheme_Object * b , long phase ) ; 
Scheme_Object * scheme_stx_module_name (Scheme_Object * * name , long phase , Scheme_Object * * nominal_modidx , Scheme_Object * * nominal_name , int * mod_phase ) ; 
Scheme_Object * scheme_stx_moduleless_env (Scheme_Object * a , long phase ) ; 
int scheme_stx_parallel_is_used (Scheme_Object * sym , Scheme_Object * stx ) ; 
int scheme_stx_bound_eq (Scheme_Object * a , Scheme_Object * b , long phase ) ; 
int scheme_stx_env_bound_eq (Scheme_Object * a , Scheme_Object * b , Scheme_Object * uid , long phase ) ; 
Scheme_Object * scheme_stx_source_module (Scheme_Object * stx , int resolve ) ; 
Scheme_Object * scheme_stx_property (Scheme_Object * _stx , Scheme_Object * key , Scheme_Object * val ) ; 
Scheme_Object * scheme_stx_phase_shift (Scheme_Object * stx , long shift , Scheme_Object * old_midx , Scheme_Object * new_midx , Scheme_Hash_Table * export_registry ) ; 
Scheme_Object * scheme_stx_phase_shift_as_rename (long shift , Scheme_Object * old_midx , Scheme_Object * new_midx , Scheme_Hash_Table * export_registry ) ; 
int scheme_stx_list_length (Scheme_Object * list ) ; 
int scheme_stx_proper_list_length (Scheme_Object * list ) ; 
Scheme_Object * scheme_stx_extract_marks (Scheme_Object * stx ) ; 
Scheme_Object * scheme_resolve_placeholders (Scheme_Object * obj , int mkstx , Scheme_Type ph_type ) ; 
Scheme_Hash_Table * scheme_setup_datum_graph (Scheme_Object * o , void * for_print ) ; 
Scheme_Object * scheme_stx_strip_module_context (Scheme_Object * stx ) ; 
Scheme_Object * scheme_source_to_name (Scheme_Object * code ) ; 
Scheme_Object * scheme_stx_cert (Scheme_Object * o , Scheme_Object * mark , Scheme_Env * menv , Scheme_Object * plus_stx , Scheme_Object * mkey , int active ) ; 
int scheme_stx_certified (Scheme_Object * stx , Scheme_Object * extra_certs , Scheme_Object * modidx , Scheme_Object * home_insp ) ; 
int scheme_module_protected_wrt (Scheme_Object * home_insp , Scheme_Object * insp ) ; 
Scheme_Object * scheme_stx_activate_certs (Scheme_Object * stx ) ; 
Scheme_Object * scheme_stx_extract_certs (Scheme_Object * o , Scheme_Object * base_certs ) ; 
Scheme_Object * scheme_stx_add_inactive_certs (Scheme_Object * o , Scheme_Object * certs ) ; 
Scheme_Object * scheme_stx_propagate_inactive_certs (Scheme_Object * o , Scheme_Object * orig ) ; 
int scheme_stx_has_more_certs (Scheme_Object * id , Scheme_Object * certs , Scheme_Object * than_id , Scheme_Object * than_certs ) ; 
Scheme_Object * scheme_delayed_rename (Scheme_Object * * o , long i ) ; 
typedef struct {
  Scheme_Object so ; 
  mzshort num_args ; 
  Scheme_Object * args [1 ] ; 
}
Scheme_App_Rec ; 
typedef struct {
  Scheme_Inclhash_Object iso ; 
  Scheme_Object * rator ; 
  Scheme_Object * rand ; 
}
Scheme_App2_Rec ; 
typedef struct {
  Scheme_Inclhash_Object iso ; 
  Scheme_Object * rator ; 
  Scheme_Object * rand1 ; 
  Scheme_Object * rand2 ; 
}
Scheme_App3_Rec ; 
typedef struct {
  Scheme_Object so ; 
  Scheme_Object * test ; 
  Scheme_Object * tbranch ; 
  Scheme_Object * fbranch ; 
}
Scheme_Branch_Rec ; 
typedef struct {
  Scheme_Object so ; 
  mzshort max_let_depth ; 
  Scheme_Object * code ; 
  struct Resolve_Prefix * prefix ; 
}
Scheme_Compilation_Top ; 
typedef struct Scheme_Compiled_Let_Value {
  Scheme_Object so ; 
  mzshort count ; 
  mzshort position ; 
  int * flags ; 
  Scheme_Object * value ; 
  Scheme_Object * body ; 
}
Scheme_Compiled_Let_Value ; 
typedef struct Scheme_Let_Header {
  Scheme_Inclhash_Object iso ; 
  mzshort count ; 
  mzshort num_clauses ; 
  Scheme_Object * body ; 
}
Scheme_Let_Header ; 
typedef struct {
  Scheme_Object so ; 
  Scheme_Object * key ; 
  Scheme_Object * val ; 
  Scheme_Object * body ; 
}
Scheme_With_Continuation_Mark ; 
typedef struct Scheme_Local {
  Scheme_Object so ; 
  mzshort position ; 
}
Scheme_Local ; 
typedef struct Scheme_Toplevel {
  Scheme_Inclhash_Object iso ; 
  mzshort depth ; 
  int position ; 
}
Scheme_Toplevel ; 
typedef struct Scheme_Quote_Syntax {
  Scheme_Object so ; 
  mzshort depth ; 
  mzshort position ; 
  mzshort midpoint ; 
}
Scheme_Quote_Syntax ; 
typedef struct Scheme_Let_Value {
  Scheme_Inclhash_Object iso ; 
  mzshort count ; 
  mzshort position ; 
  Scheme_Object * value ; 
  Scheme_Object * body ; 
}
Scheme_Let_Value ; 
typedef struct Scheme_Let_One {
  Scheme_Inclhash_Object iso ; 
  Scheme_Object * value ; 
  Scheme_Object * body ; 
}
Scheme_Let_One ; 
typedef struct Scheme_Let_Void {
  Scheme_Inclhash_Object iso ; 
  mzshort count ; 
  Scheme_Object * body ; 
}
Scheme_Let_Void ; 
typedef struct Scheme_Letrec {
  Scheme_Object so ; 
  mzshort count ; 
  Scheme_Object * * procs ; 
  Scheme_Object * body ; 
}
Scheme_Letrec ; 
typedef struct {
  Scheme_Object so ; 
  mzshort count ; 
  Scheme_Object * array [1 ] ; 
}
Scheme_Sequence ; 
typedef struct {
  Scheme_Object so ; 
  mzshort count ; 
  Scheme_Object * name ; 
  struct Scheme_Native_Closure_Data * native_code ; 
  Scheme_Object * array [1 ] ; 
}
Scheme_Case_Lambda ; 
Scheme_Object * scheme_unclose_case_lambda (Scheme_Object * expr , int jit ) ; 
Scheme_Object * scheme_native_stack_trace (void ) ; 
void scheme_clean_native_symtab (void ) ; 
void scheme_clean_cust_box_list (void ) ; 
Scheme_Object * scheme_handle_stack_overflow (Scheme_Object * (* k ) (void ) ) ; 
extern struct Scheme_Overflow_Jmp * scheme_overflow_jmp ; 
extern void * scheme_overflow_stack_start ; 
void scheme_ensure_stack_start (void * d ) ; 
extern void * scheme_deepest_stack_start ; 
void scheme_jmpup_free (Scheme_Jumpup_Buf * ) ; 
void * scheme_enlarge_runstack (long size , void * (* k ) () ) ; 
int scheme_check_runstack (long size ) ; 
void scheme_flush_stack_copy_cache (void ) ; 
void * scheme_top_level_do (void * (* k ) (void ) , int eb ) ; 
void scheme_on_next_top (struct Scheme_Comp_Env * env , Scheme_Object * mark , Scheme_Object * name , Scheme_Object * certs , Scheme_Env * menv , Scheme_Object * in_modidx ) ; 
Scheme_Object * scheme_call_ec (int argc , Scheme_Object * argv [] ) ; 
unsigned long scheme_get_deeper_address (void ) ; 
void scheme_init_stack_limit (void ) ; 
typedef struct Scheme_Saved_Stack {
  Scheme_Type type ; 
  Scheme_Object * * runstack_start ; 
  long runstack_offset ; 
  long runstack_size ; 
  struct Scheme_Saved_Stack * prev ; 
}
Scheme_Saved_Stack ; 
typedef struct Scheme_Cont_Mark {
  Scheme_Object * key ; 
  Scheme_Object * val ; 
  Scheme_Object * cache ; 
  long pos ; 
}
Scheme_Cont_Mark ; 
typedef struct Scheme_Cont_Mark_Chain {
  Scheme_Object so ; 
  Scheme_Object * key ; 
  Scheme_Object * val ; 
  long pos ; 
  struct Scheme_Cont_Mark_Chain * next ; 
}
Scheme_Cont_Mark_Chain ; 
typedef struct Scheme_Cont_Mark_Set {
  Scheme_Object so ; 
  struct Scheme_Cont_Mark_Chain * chain ; 
  long cmpos ; 
  Scheme_Object * native_stack_trace ; 
}
Scheme_Cont_Mark_Set ; 
typedef struct Scheme_Stack_State {
  long runstack_offset ; 
  long cont_mark_pos ; 
  long cont_mark_stack ; 
}
Scheme_Stack_State ; 
typedef struct Scheme_Dynamic_Wind {
  Scheme_Type type ; 
  int depth ; 
  void * id ; 
  void * data ; 
  Scheme_Object * prompt_tag ; 
  void (* pre ) (void * ) ; 
  void (* post ) (void * ) ; 
  mz_jmp_buf * saveerr ; 
  int next_meta ; 
  struct Scheme_Stack_State envss ; 
  struct Scheme_Dynamic_Wind * prev ; 
}
Scheme_Dynamic_Wind ; 
typedef struct Scheme_Cont {
  Scheme_Object so ; 
  char composable , has_prompt_dw ; 
  struct Scheme_Meta_Continuation * meta_continuation ; 
  Scheme_Jumpup_Buf buf ; 
  Scheme_Dynamic_Wind * dw ; 
  int next_meta ; 
  Scheme_Continuation_Jump_State cjs ; 
  Scheme_Stack_State ss ; 
  struct Scheme_Prompt * barrier_prompt ; 
  Scheme_Object * * runstack_start ; 
  long runstack_size ; 
  Scheme_Saved_Stack * runstack_saved ; 
  Scheme_Object * prompt_tag ; 
  mz_jmp_buf * prompt_buf ; 
  long meta_tail_pos ; 
  long cont_mark_pos_bottom ; 
  void * prompt_stack_start ; 
  Scheme_Saved_Stack * runstack_copied ; 
  Scheme_Thread * * runstack_owner ; 
  Scheme_Cont_Mark * cont_mark_stack_copied ; 
  Scheme_Thread * * cont_mark_stack_owner ; 
  long cont_mark_total ; 
  long cont_mark_offset ; 
  long cont_mark_nonshare ; 
  void * stack_start ; 
  Scheme_Object * prompt_id ; 
  Scheme_Config * init_config ; 
  Scheme_Object * init_break_cell ; 
  Scheme_Object * native_trace ; 
  struct Scheme_Overflow * save_overflow ; 
  mz_jmp_buf * savebuf ; 
  Scheme_Object * value ; 
  struct Scheme_Overflow * resume_to ; 
  char empty_to_next_mc ; 
  struct Scheme_Cont * use_next_cont ; 
  int common_dw_depth ; 
  Scheme_Dynamic_Wind * common_dw ; 
  int common_next_meta ; 
  Scheme_Object * extra_marks ; 
  struct Scheme_Prompt * shortcut_prompt ; 
}
Scheme_Cont ; 
typedef struct Scheme_Escaping_Cont {
  Scheme_Object so ; 
  struct Scheme_Stack_State envss ; 
  struct Scheme_Prompt * barrier_prompt ; 
  Scheme_Object * native_trace ; 
  mz_jmp_buf * saveerr ; 
}
Scheme_Escaping_Cont ; 
int scheme_escape_continuation_ok (Scheme_Object * ) ; 
void scheme_takeover_stacks (Scheme_Thread * p ) ; 
typedef struct Scheme_Overflow_Jmp {
  Scheme_Type type ; 
  char captured ; 
  Scheme_Jumpup_Buf cont ; 
  mz_jmp_buf * savebuf ; 
}
Scheme_Overflow_Jmp ; 
typedef struct Scheme_Overflow {
  Scheme_Type type ; 
  char eot ; 
  Scheme_Overflow_Jmp * jmp ; 
  void * id ; 
  void * stack_start ; 
  struct Scheme_Overflow * prev ; 
}
Scheme_Overflow ; 
extern unsigned long scheme_stack_boundary ; 
typedef struct Scheme_Meta_Continuation {
  Scheme_Type type ; 
  char pseudo ; 
  char empty_to_next ; 
  char cm_caches ; 
  char cm_shared ; 
  int copy_after_captured ; 
  int depth ; 
  Scheme_Object * prompt_tag ; 
  Scheme_Overflow * overflow ; 
  long meta_tail_pos ; 
  long cont_mark_pos_bottom ; 
  long cont_mark_stack ; 
  long cont_mark_pos ; 
  long cont_mark_total , cont_mark_offset ; 
  Scheme_Cont_Mark * cont_mark_stack_copied ; 
  struct Scheme_Meta_Continuation * next ; 
}
Scheme_Meta_Continuation ; 
typedef struct Scheme_Prompt {
  Scheme_Object so ; 
  char is_barrier ; 
  Scheme_Object * tag ; 
  Scheme_Object * id ; 
  void * stack_boundary ; 
  void * boundary_overflow_id ; 
  long mark_boundary ; 
  long boundary_mark_pos ; 
  Scheme_Object * * runstack_boundary_start ; 
  long runstack_boundary_offset ; 
  mz_jmp_buf * prompt_buf ; 
  long runstack_size ; 
}
Scheme_Prompt ; 
Scheme_Object * scheme_extract_one_cc_mark_with_meta (Scheme_Object * mark_set , Scheme_Object * key , Scheme_Object * prompt_tag , Scheme_Meta_Continuation * * _meta_cont , long * _pos ) ; 
Scheme_Object * scheme_compose_continuation (Scheme_Cont * c , int num_rands , Scheme_Object * value ) ; 
Scheme_Overflow * scheme_get_thread_end_overflow (void ) ; 
void scheme_end_current_thread (void ) ; 
void scheme_ensure_dw_id (Scheme_Dynamic_Wind * dw ) ; 
void scheme_apply_dw_in_meta (Scheme_Dynamic_Wind * dw , int post , int mc_depth , struct Scheme_Cont * recheck ) ; 
void scheme_drop_prompt_meta_continuations (Scheme_Object * prompt_tag ) ; 
struct Scheme_Prompt * scheme_get_barrier_prompt (struct Scheme_Meta_Continuation * * _meta_cont , long * _pos ) ; 
int scheme_is_cm_deeper (struct Scheme_Meta_Continuation * m1 , long p1 , struct Scheme_Meta_Continuation * m2 , long p2 ) ; 
void scheme_recheck_prompt_and_barrier (struct Scheme_Cont * c ) ; 
Scheme_Object * scheme_all_current_continuation_marks (void ) ; 
void scheme_about_to_move_C_stack (void ) ; 
typedef struct Scheme_Channel_Syncer {
  Scheme_Object so ; 
  Scheme_Thread * p ; 
  char in_line , picked ; 
  struct Scheme_Channel_Syncer * prev , * next ; 
  struct Syncing * syncing ; 
  Scheme_Object * obj ; 
  int syncing_i ; 
}
Scheme_Channel_Syncer ; 
typedef struct Scheme_Sema {
  Scheme_Object so ; 
  Scheme_Channel_Syncer * first , * last ; 
  long value ; 
}
Scheme_Sema ; 
typedef struct Scheme_Channel {
  Scheme_Object so ; 
  Scheme_Channel_Syncer * put_first , * put_last ; 
  Scheme_Channel_Syncer * get_first , * get_last ; 
}
Scheme_Channel ; 
typedef struct Scheme_Channel_Put {
  Scheme_Object so ; 
  Scheme_Channel * ch ; 
  Scheme_Object * val ; 
}
Scheme_Channel_Put ; 
typedef struct Evt_Set {
  Scheme_Object so ; 
  int argc ; 
  Scheme_Object * * argv ; 
  struct Evt * * ws ; 
}
Evt_Set ; 
typedef struct Syncing {
  Scheme_Type type ; 
  Evt_Set * set ; 
  int result , start_pos ; 
  double sleep_end ; 
  float timeout ; 
  Scheme_Object * * wrapss ; 
  Scheme_Object * * nackss ; 
  char * reposts ; 
  Scheme_Thread * disable_break ; 
}
Syncing ; 
int scheme_wait_semas_chs (int n , Scheme_Object * * o , int just_try , Syncing * syncing ) ; 
Scheme_Object * scheme_make_sema_repost (Scheme_Object * sema ) ; 
Scheme_Object * scheme_wrap_evt (int argc , Scheme_Object * argv [] ) ; 
Scheme_Object * scheme_poll_evt (int argc , Scheme_Object * argv [] ) ; 
extern Scheme_Object * scheme_always_ready_evt ; 
void scheme_get_outof_line (Scheme_Channel_Syncer * ch_w ) ; 
void scheme_post_syncing_nacks (Syncing * syncing ) ; 
int scheme_try_channel_get (Scheme_Object * ch ) ; 
typedef unsigned long bigdig ; 
typedef struct {
  Scheme_Inclhash_Object iso ; 
  int len ; 
  bigdig * digits ; 
}
Scheme_Bignum ; 
typedef struct {
  Scheme_Bignum o ; 
  bigdig v [1 ] ; 
}
Small_Bignum ; 
__xform_nongcing__ Scheme_Object * scheme_make_small_bignum (long v , Small_Bignum * s ) ; 
char * scheme_number_to_string (int radix , Scheme_Object * obj ) ; 
__xform_nongcing__ int scheme_bignum_get_int_val (const Scheme_Object * o , long * v ) ; 
__xform_nongcing__ int scheme_bignum_get_unsigned_int_val (const Scheme_Object * o , unsigned long * v ) ; 
__xform_nongcing__ int scheme_bignum_get_long_long_val (const Scheme_Object * o , mzlonglong * v ) ; 
__xform_nongcing__ int scheme_bignum_get_unsigned_long_long_val (const Scheme_Object * o , umzlonglong * v ) ; 
__xform_nongcing__ int scheme_bignum_eq (const Scheme_Object * a , const Scheme_Object * b ) ; 
__xform_nongcing__ int scheme_bignum_lt (const Scheme_Object * a , const Scheme_Object * b ) ; 
__xform_nongcing__ int scheme_bignum_gt (const Scheme_Object * a , const Scheme_Object * b ) ; 
__xform_nongcing__ int scheme_bignum_le (const Scheme_Object * a , const Scheme_Object * b ) ; 
__xform_nongcing__ int scheme_bignum_ge (const Scheme_Object * a , const Scheme_Object * b ) ; 
Scheme_Object * scheme_bignum_negate (const Scheme_Object * n ) ; 
Scheme_Object * scheme_bignum_add (const Scheme_Object * a , const Scheme_Object * b ) ; 
Scheme_Object * scheme_bignum_subtract (const Scheme_Object * a , const Scheme_Object * b ) ; 
Scheme_Object * scheme_bignum_add1 (const Scheme_Object * n ) ; 
Scheme_Object * scheme_bignum_sub1 (const Scheme_Object * n ) ; 
Scheme_Object * scheme_bignum_multiply (const Scheme_Object * a , const Scheme_Object * b ) ; 
Scheme_Object * scheme_bignum_max (const Scheme_Object * a , const Scheme_Object * b ) ; 
Scheme_Object * scheme_bignum_min (const Scheme_Object * a , const Scheme_Object * b ) ; 
void scheme_bignum_divide (const Scheme_Object * n , const Scheme_Object * d , Scheme_Object * * qp , Scheme_Object * * rp , int norm ) ; 
Scheme_Object * scheme_generic_integer_power (const Scheme_Object * a , const Scheme_Object * b ) ; 
Scheme_Object * scheme_bignum_gcd (const Scheme_Object * a , const Scheme_Object * b ) ; 
Scheme_Object * scheme_integer_sqrt (const Scheme_Object * n ) ; 
Scheme_Object * scheme_integer_sqrt_rem (const Scheme_Object * n , Scheme_Object * * r ) ; 
Scheme_Object * scheme_bignum_and (const Scheme_Object * a , const Scheme_Object * b ) ; 
Scheme_Object * scheme_bignum_or (const Scheme_Object * a , const Scheme_Object * b ) ; 
Scheme_Object * scheme_bignum_xor (const Scheme_Object * a , const Scheme_Object * b ) ; 
Scheme_Object * scheme_bignum_not (const Scheme_Object * a ) ; 
Scheme_Object * scheme_bignum_shift (const Scheme_Object * a , long shift ) ; 
__xform_nongcing__ double scheme_bignum_to_double_inf_info (const Scheme_Object * n , int just_use , int * only_need ) ; 
void scheme_clear_bignum_cache (void ) ; 
typedef struct {
  Scheme_Object so ; 
  Scheme_Object * num ; 
  Scheme_Object * denom ; 
}
Scheme_Rational ; 
typedef Scheme_Rational Small_Rational ; 
__xform_nongcing__ Scheme_Object * scheme_make_small_rational (long n , Small_Rational * space ) ; 
__xform_nongcing__ Scheme_Object * scheme_make_small_bn_rational (Scheme_Object * n , Small_Rational * space ) ; 
Scheme_Object * scheme_integer_to_rational (const Scheme_Object * n ) ; 
Scheme_Object * scheme_make_fixnum_rational (long n , long d ) ; 
__xform_nongcing__ int scheme_rational_eq (const Scheme_Object * a , const Scheme_Object * b ) ; 
int scheme_rational_lt (const Scheme_Object * a , const Scheme_Object * b ) ; 
int scheme_rational_gt (const Scheme_Object * a , const Scheme_Object * b ) ; 
int scheme_rational_le (const Scheme_Object * a , const Scheme_Object * b ) ; 
int scheme_rational_ge (const Scheme_Object * a , const Scheme_Object * b ) ; 
Scheme_Object * scheme_rational_negate (const Scheme_Object * n ) ; 
Scheme_Object * scheme_rational_add (const Scheme_Object * a , const Scheme_Object * b ) ; 
Scheme_Object * scheme_rational_subtract (const Scheme_Object * a , const Scheme_Object * b ) ; 
Scheme_Object * scheme_rational_add1 (const Scheme_Object * n ) ; 
Scheme_Object * scheme_rational_sub1 (const Scheme_Object * n ) ; 
Scheme_Object * scheme_rational_multiply (const Scheme_Object * a , const Scheme_Object * b ) ; 
Scheme_Object * scheme_rational_max (const Scheme_Object * a , const Scheme_Object * b ) ; 
Scheme_Object * scheme_rational_min (const Scheme_Object * a , const Scheme_Object * b ) ; 
Scheme_Object * scheme_rational_divide (const Scheme_Object * n , const Scheme_Object * d ) ; 
Scheme_Object * scheme_rational_power (const Scheme_Object * a , const Scheme_Object * b ) ; 
__xform_nongcing__ int scheme_is_rational_positive (const Scheme_Object * o ) ; 
Scheme_Object * scheme_rational_floor (const Scheme_Object * a ) ; 
Scheme_Object * scheme_rational_truncate (const Scheme_Object * a ) ; 
Scheme_Object * scheme_rational_ceiling (const Scheme_Object * a ) ; 
Scheme_Object * scheme_rational_round (const Scheme_Object * a ) ; 
Scheme_Object * scheme_rational_sqrt (const Scheme_Object * n ) ; 
typedef struct {
  Scheme_Object so ; 
  Scheme_Object * r ; 
  Scheme_Object * i ; 
}
Scheme_Complex ; 
typedef Scheme_Complex Small_Complex ; 
Scheme_Object * scheme_make_small_complex (const Scheme_Object * n , Small_Complex * space ) ; 
Scheme_Object * scheme_real_to_complex (const Scheme_Object * n ) ; 
int scheme_complex_eq (const Scheme_Object * a , const Scheme_Object * b ) ; 
Scheme_Object * scheme_complex_negate (const Scheme_Object * n ) ; 
Scheme_Object * scheme_complex_add (const Scheme_Object * a , const Scheme_Object * b ) ; 
Scheme_Object * scheme_complex_subtract (const Scheme_Object * a , const Scheme_Object * b ) ; 
Scheme_Object * scheme_complex_add1 (const Scheme_Object * n ) ; 
Scheme_Object * scheme_complex_sub1 (const Scheme_Object * n ) ; 
Scheme_Object * scheme_complex_multiply (const Scheme_Object * a , const Scheme_Object * b ) ; 
Scheme_Object * scheme_complex_divide (const Scheme_Object * n , const Scheme_Object * d ) ; 
Scheme_Object * scheme_complex_power (const Scheme_Object * a , const Scheme_Object * b ) ; 
Scheme_Object * scheme_complex_sqrt (const Scheme_Object * a ) ; 
__xform_nongcing__ int scheme_is_complex_exact (const Scheme_Object * o ) ; 
int scheme_check_double (const char * where , double v , const char * dest ) ; 
double scheme_get_val_as_double (const Scheme_Object * n ) ; 
__xform_nongcing__ int scheme_minus_zero_p (double d ) ; 
extern double scheme_infinity_val , scheme_minus_infinity_val ; 
extern double scheme_floating_point_zero ; 
extern double scheme_floating_point_nzero ; 
extern Scheme_Object * scheme_zerod , * scheme_nzerod , * scheme_pi , * scheme_half_pi , * scheme_plus_i , * scheme_minus_i ; 
extern Scheme_Object * scheme_inf_object , * scheme_minus_inf_object , * scheme_nan_object ; 
Scheme_Object * scheme_read_number (const mzchar * str , long len , int is_float , int is_not_float , int decimal_means_float , int radix , int radix_set , Scheme_Object * port , int * div_by_zero , int test_only , Scheme_Object * stxsrc , long line , long col , long pos , long span , Scheme_Object * indentation ) ; 
Scheme_Object * scheme_bin_gcd (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
Scheme_Object * scheme_bin_quotient (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
Scheme_Object * scheme_bin_mult (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
Scheme_Object * scheme_bin_div (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
Scheme_Object * scheme_bin_plus (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
Scheme_Object * scheme_bin_minus (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
int scheme_bin_eq (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
int scheme_bin_lt (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
int scheme_bin_gt (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
int scheme_bin_gt_eq (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
int scheme_bin_lt_eq (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
Scheme_Object * scheme_sub1 (int argc , Scheme_Object * argv [] ) ; 
Scheme_Object * scheme_add1 (int argc , Scheme_Object * argv [] ) ; 
Scheme_Object * scheme_odd_p (int argc , Scheme_Object * argv [] ) ; 
Scheme_Object * scheme_expt (int argc , Scheme_Object * argv [] ) ; 
Scheme_Object * scheme_modulo (int argc , Scheme_Object * argv [] ) ; 
Scheme_Object * scheme_sqrt (int argc , Scheme_Object * argv [] ) ; 
Scheme_Object * scheme_abs (int argc , Scheme_Object * argv [] ) ; 
Scheme_Object * scheme_inexact_to_exact (int argc , Scheme_Object * argv [] ) ; 
Scheme_Object * scheme_exact_to_inexact (int argc , Scheme_Object * argv [] ) ; 
Scheme_Object * scheme_inexact_p (int argc , Scheme_Object * argv [] ) ; 
Scheme_Object * scheme_TO_DOUBLE (const Scheme_Object * n ) ; 
Scheme_Object * scheme_to_bignum (const Scheme_Object * o ) ; 
__xform_nongcing__ int scheme_is_integer (const Scheme_Object * o ) ; 
__xform_nongcing__ int scheme_is_zero (const Scheme_Object * o ) ; 
__xform_nongcing__ int scheme_is_negative (const Scheme_Object * o ) ; 
__xform_nongcing__ int scheme_is_positive (const Scheme_Object * o ) ; 
Scheme_Object * scheme_make_polar (int argc , Scheme_Object * argv [] ) ; 
Scheme_Object * scheme_bitwise_shift (int argc , Scheme_Object * argv [] ) ; 
Scheme_Object * scheme_bitwise_and (int argc , Scheme_Object * argv [] ) ; 
int scheme_nonneg_exact_p (Scheme_Object * n ) ; 
typedef struct {
  Scheme_Object so ; 
  double x10 , x11 , x12 , x20 , x21 , x22 ; 
}
Scheme_Random_State ; 
Scheme_Object * scheme_make_random_state (long seed ) ; 
long scheme_rand (Scheme_Random_State * rs ) ; 
Scheme_Object * scheme_eval_linked_expr (Scheme_Object * expr ) ; 
Scheme_Object * scheme_eval_linked_expr_multi (Scheme_Object * expr ) ; 
Scheme_Object * _scheme_apply_to_list (Scheme_Object * rator , Scheme_Object * rands ) ; 
Scheme_Object * _scheme_tail_apply_to_list (Scheme_Object * rator , Scheme_Object * rands ) ; 
Scheme_Object * scheme_internal_read (Scheme_Object * port , Scheme_Object * stxsrc , int crc , int cantfail , int honu_mode , int recur , int expose_comment , int pre_char , Scheme_Object * readtable , Scheme_Object * magic_sym , Scheme_Object * magic_val , Scheme_Object * delay_load_info ) ; 
void scheme_internal_display (Scheme_Object * obj , Scheme_Object * port ) ; 
void scheme_internal_write (Scheme_Object * obj , Scheme_Object * port ) ; 
void scheme_internal_print (Scheme_Object * obj , Scheme_Object * port ) ; 
Scheme_Object * scheme_named_map_1 (char * , Scheme_Object * (* fun ) (Scheme_Object * , Scheme_Object * form ) , Scheme_Object * lst , Scheme_Object * form ) ; 
__xform_nongcing__ int scheme_strncmp (const char * a , const char * b , int len ) ; 
Scheme_Object * scheme_default_eval_handler (int , Scheme_Object * [] ) ; 
Scheme_Object * scheme_default_compile_handler (int , Scheme_Object * [] ) ; 
Scheme_Object * scheme_default_print_handler (int , Scheme_Object * [] ) ; 
Scheme_Object * scheme_default_prompt_read_handler (int , Scheme_Object * [] ) ; 
extern Scheme_Object * scheme_default_global_print_handler ; 
void scheme_install_type_reader (Scheme_Type type , Scheme_Type_Reader f ) ; 
void scheme_install_type_writer (Scheme_Type type , Scheme_Type_Writer f ) ; 
Scheme_Object * scheme_make_default_readtable (void ) ; 
Scheme_Object * _scheme_apply_from_native (Scheme_Object * rator , int argc , Scheme_Object * * argv ) ; 
Scheme_Object * _scheme_apply_multi_from_native (Scheme_Object * rator , int argc , Scheme_Object * * argv ) ; 
Scheme_Object * _scheme_tail_apply_from_native (Scheme_Object * rator , int argc , Scheme_Object * * argv ) ; 
Scheme_Object * scheme_force_value_same_mark (Scheme_Object * ) ; 
Scheme_Object * scheme_force_one_value_same_mark (Scheme_Object * ) ; 
void scheme_flush_stack_cache (void ) ; 
struct Scheme_Load_Delay ; 
Scheme_Object * scheme_load_delayed_code (int pos , struct Scheme_Load_Delay * ld ) ; 
typedef struct Comp_Prefix {
  Scheme_Type type ; 
  int num_toplevels , num_stxes ; 
  Scheme_Hash_Table * toplevels ; 
  Scheme_Hash_Table * stxes ; 
}
Comp_Prefix ; 
typedef struct Scheme_Comp_Env {
  Scheme_Type type ; 
  short flags ; 
  mzshort num_bindings ; 
  Scheme_Env * genv ; 
  Scheme_Object * insp ; 
  Comp_Prefix * prefix ; 
  struct Scheme_Object * * values ; 
  Scheme_Object * certs ; 
  Scheme_Object * uid ; 
  struct Scheme_Object * * uids ; 
  struct Scheme_Object * renames ; 
  mzshort rename_var_count ; 
  mzshort rename_rstart ; 
  Scheme_Hash_Table * dup_check ; 
  Scheme_Object * intdef_name ; 
  Scheme_Object * in_modidx ; 
  Scheme_Hash_Table * skip_table ; 
  int skip_depth ; 
  struct Scheme_Comp_Env * next ; 
}
Scheme_Comp_Env ; 
typedef struct Scheme_Compile_Expand_Info {
  Scheme_Type type ; 
  int comp ; 
  Scheme_Object * value_name ; 
  Scheme_Object * certs ; 
  Scheme_Object * observer ; 
  char dont_mark_local_use ; 
  char resolve_module_ids ; 
  int depth ; 
}
Scheme_Compile_Expand_Info ; 
typedef Scheme_Compile_Expand_Info Scheme_Compile_Info ; 
typedef Scheme_Compile_Expand_Info Scheme_Expand_Info ; 
typedef struct Resolve_Prefix {
  Scheme_Object so ; 
  int num_toplevels , num_stxes , num_lifts ; 
  Scheme_Object * * toplevels ; 
  Scheme_Object * * stxes ; 
  int delay_refcount ; 
  struct Scheme_Load_Delay * delay_info ; 
}
Resolve_Prefix ; 
typedef struct Resolve_Info {
  Scheme_Type type ; 
  char use_jit , in_module , in_proc , enforce_const ; 
  int size , oldsize , count , pos ; 
  int max_let_depth ; 
  Resolve_Prefix * prefix ; 
  Scheme_Hash_Table * stx_map ; 
  mzshort toplevel_pos ; 
  mzshort * old_pos ; 
  mzshort * new_pos ; 
  int stx_count ; 
  mzshort * old_stx_pos ; 
  int * flags ; 
  Scheme_Object * * lifted ; 
  Scheme_Object * lifts ; 
  struct Resolve_Info * next ; 
}
Resolve_Info ; 
typedef struct Scheme_Object * (Scheme_Syntax ) (struct Scheme_Object * form , struct Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
typedef struct Scheme_Object * (Scheme_Syntax_Expander ) (struct Scheme_Object * form , struct Scheme_Comp_Env * env , Scheme_Expand_Info * rec , int drec ) ; 
typedef struct Scheme_Object * (* Scheme_Syntax_Resolver ) (Scheme_Object * data , Resolve_Info * info ) ; 
typedef struct Optimize_Info {
  Scheme_Type type ; 
  short flags ; 
  struct Optimize_Info * next ; 
  int original_frame , new_frame ; 
  Scheme_Object * consts ; 
  int size ; 
  short inline_fuel ; 
  char letrec_not_twice , enforce_const ; 
  Scheme_Hash_Table * top_level_consts ; 
  int single_result , preserves_marks ; 
  char * * stat_dists ; 
  int * sd_depths ; 
  int used_toplevel ; 
  char * use ; 
  int transitive_use_pos ; 
  mzshort * * transitive_use ; 
  int * transitive_use_len ; 
}
Optimize_Info ; 
typedef struct Scheme_Object * (* Scheme_Syntax_Optimizer ) (Scheme_Object * data , Optimize_Info * info ) ; 
typedef struct Scheme_Object * (* Scheme_Syntax_Cloner ) (int dup_ok , Scheme_Object * data , Optimize_Info * info , int delta , int closure_depth ) ; 
typedef struct Scheme_Object * (* Scheme_Syntax_Shifter ) (Scheme_Object * data , int delta , int after_depth ) ; 
typedef struct CPort Mz_CPort ; 
typedef void (* Scheme_Syntax_Validater ) (Scheme_Object * data , Mz_CPort * port , char * stack , Scheme_Hash_Table * ht , Scheme_Object * * tls , int depth , int letlimit , int delta , int num_toplevels , int num_stxes , int num_lifts ) ; 
typedef struct Scheme_Object * (* Scheme_Syntax_Executer ) (struct Scheme_Object * data ) ; 
typedef struct Scheme_Object * (* Scheme_Syntax_Jitter ) (struct Scheme_Object * data ) ; 
typedef struct Scheme_Closure_Data {
  Scheme_Inclhash_Object iso ; 
  mzshort num_params ; 
  mzshort max_let_depth ; 
  mzshort closure_size ; 
  mzshort * closure_map ; 
  Scheme_Object * code ; 
  Scheme_Object * name ; 
  union {
    struct Scheme_Closure_Data * jit_clone ; 
    struct Scheme_Native_Closure_Data * native_code ; 
  }
  u ; 
  Scheme_Object * context ; 
}
Scheme_Closure_Data ; 
int scheme_has_method_property (Scheme_Object * code ) ; 
typedef struct {
  Scheme_Object so ; 
  Scheme_Closure_Data * code ; 
  Scheme_Object * vals [1 ] ; 
}
Scheme_Closure ; 
typedef struct Scheme_Native_Closure_Data {
  Scheme_Inclhash_Object iso ; 
  Scheme_Closed_Prim * code ; 
  union {
    void * tail_code ; 
    mzshort * arities ; 
  }
  u ; 
  void * arity_code ; 
  mzshort max_let_depth ; 
  mzshort closure_size ; 
  union {
    struct Scheme_Closure_Data * orig_code ; 
    Scheme_Object * name ; 
  }
  u2 ; 
  void * * retained ; 
  mzshort retain_count ; 
}
Scheme_Native_Closure_Data ; 
typedef struct {
  Scheme_Object so ; 
  Scheme_Native_Closure_Data * code ; 
  Scheme_Object * vals [1 ] ; 
}
Scheme_Native_Closure ; 
Scheme_Native_Closure_Data * scheme_generate_lambda (Scheme_Closure_Data * obj , int drop_code , Scheme_Native_Closure_Data * case_lam ) ; 
extern Scheme_Object * scheme_local [64 ] [2 ] ; 
Scheme_Comp_Env * scheme_new_comp_env (Scheme_Env * genv , Scheme_Object * insp , int flags ) ; 
Scheme_Comp_Env * scheme_new_expand_env (Scheme_Env * genv , Scheme_Object * insp , int flags ) ; 
void scheme_check_identifier (const char * formname , Scheme_Object * id , const char * where , Scheme_Comp_Env * env , Scheme_Object * form ) ; 
int scheme_check_context (Scheme_Env * env , Scheme_Object * id , Scheme_Object * ok_modix ) ; 
Scheme_Object * scheme_check_immediate_macro (Scheme_Object * first , Scheme_Comp_Env * env , Scheme_Compile_Expand_Info * erec , int drec , int int_def_pos , Scheme_Object * * current_val , Scheme_Comp_Env * * _xenv , Scheme_Object * ctx ) ; 
Scheme_Object * scheme_apply_macro (Scheme_Object * name , Scheme_Env * menv , Scheme_Object * f , Scheme_Object * code , Scheme_Comp_Env * env , Scheme_Object * boundname , Scheme_Compile_Expand_Info * rec , int drec , int for_set ) ; 
Scheme_Comp_Env * scheme_new_compilation_frame (int num_bindings , int flags , Scheme_Comp_Env * env , Scheme_Object * certs ) ; 
void scheme_add_compilation_binding (int index , Scheme_Object * val , Scheme_Comp_Env * frame ) ; 
Scheme_Comp_Env * scheme_add_compilation_frame (Scheme_Object * vals , Scheme_Comp_Env * env , int flags , Scheme_Object * certs ) ; 
Scheme_Comp_Env * scheme_require_renames (Scheme_Comp_Env * env ) ; 
Scheme_Object * scheme_lookup_binding (Scheme_Object * symbol , Scheme_Comp_Env * env , int flags , Scheme_Object * certs , Scheme_Object * in_modidx , Scheme_Env * * _menv , int * _protected , Scheme_Object * * _lexical_binding_id ) ; 
Scheme_Object * scheme_add_env_renames (Scheme_Object * stx , Scheme_Comp_Env * env , Scheme_Comp_Env * upto ) ; 
Scheme_Object * scheme_env_frame_uid (Scheme_Comp_Env * env ) ; 
typedef Scheme_Object * (* Scheme_Lift_Capture_Proc ) (Scheme_Object * , Scheme_Object * * , Scheme_Object * , Scheme_Comp_Env * ) ; 
void scheme_frame_captures_lifts (Scheme_Comp_Env * env , Scheme_Lift_Capture_Proc cp , Scheme_Object * data , Scheme_Object * end_stmts , Scheme_Object * context_key ) ; 
Scheme_Object * scheme_frame_get_lifts (Scheme_Comp_Env * env ) ; 
Scheme_Object * scheme_frame_get_end_statement_lifts (Scheme_Comp_Env * env ) ; 
Scheme_Object * scheme_generate_lifts_key (void ) ; 
void scheme_add_local_syntax (int cnt , Scheme_Comp_Env * env ) ; 
void scheme_set_local_syntax (int pos , Scheme_Object * name , Scheme_Object * val , Scheme_Comp_Env * env ) ; 
Scheme_Object * scheme_make_closure (Scheme_Thread * p , Scheme_Object * compiled_code , int close ) ; 
Scheme_Closure * scheme_malloc_empty_closure (void ) ; 
Scheme_Object * scheme_make_native_closure (Scheme_Native_Closure_Data * code ) ; 
Scheme_Object * scheme_make_native_case_closure (Scheme_Native_Closure_Data * code ) ; 
Scheme_Native_Closure_Data * scheme_generate_case_lambda (Scheme_Case_Lambda * cl ) ; 
Scheme_Object * scheme_compiled_void (void ) ; 
Scheme_Object * scheme_register_toplevel_in_prefix (Scheme_Object * var , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
Scheme_Object * scheme_register_stx_in_prefix (Scheme_Object * var , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
void scheme_bind_syntaxes (const char * where , Scheme_Object * names , Scheme_Object * a , Scheme_Env * exp_env , Scheme_Object * insp , Scheme_Compile_Expand_Info * rec , int drec , Scheme_Comp_Env * stx_env , Scheme_Comp_Env * rhs_env , int * _pos ) ; 
int scheme_is_sub_env (Scheme_Comp_Env * stx_env , Scheme_Comp_Env * env ) ; 
extern Scheme_Syntax_Optimizer scheme_syntax_optimizers [12 ] ; 
extern Scheme_Syntax_Resolver scheme_syntax_resolvers [12 ] ; 
extern Scheme_Syntax_Validater scheme_syntax_validaters [12 ] ; 
extern Scheme_Syntax_Executer scheme_syntax_executers [12 ] ; 
extern Scheme_Syntax_Jitter scheme_syntax_jitters [12 ] ; 
extern Scheme_Syntax_Cloner scheme_syntax_cloners [12 ] ; 
extern Scheme_Syntax_Shifter scheme_syntax_shifters [12 ] ; 
extern int scheme_syntax_protect_afters [12 ] ; 
Scheme_Object * scheme_protect_quote (Scheme_Object * expr ) ; 
Scheme_Object * scheme_make_syntax_resolved (int idx , Scheme_Object * data ) ; 
Scheme_Object * scheme_make_syntax_compiled (int idx , Scheme_Object * data ) ; 
Scheme_Object * scheme_optimize_expr (Scheme_Object * , Optimize_Info * ) ; 
Scheme_Object * scheme_optimize_lets (Scheme_Object * form , Optimize_Info * info , int for_inline ) ; 
Scheme_Object * scheme_optimize_lets_for_test (Scheme_Object * form , Optimize_Info * info ) ; 
Scheme_Object * scheme_optimize_apply_values (Scheme_Object * f , Scheme_Object * e , Optimize_Info * info , int e_single_result ) ; 
int scheme_compiled_duplicate_ok (Scheme_Object * o ) ; 
int scheme_compiled_propagate_ok (Scheme_Object * o , Optimize_Info * info ) ; 
Scheme_Object * scheme_resolve_expr (Scheme_Object * , Resolve_Info * ) ; 
Scheme_Object * scheme_resolve_list (Scheme_Object * , Resolve_Info * ) ; 
int scheme_is_compiled_procedure (Scheme_Object * o , int can_be_closed , int can_be_liftable ) ; 
Scheme_Object * scheme_resolve_lets (Scheme_Object * form , Resolve_Info * info ) ; 
Resolve_Prefix * scheme_resolve_prefix (int phase , Comp_Prefix * cp , int simplify ) ; 
Resolve_Prefix * scheme_remap_prefix (Resolve_Prefix * rp , Resolve_Info * ri ) ; 
Resolve_Info * scheme_resolve_info_create (Resolve_Prefix * rp ) ; 
Resolve_Info * scheme_resolve_info_extend (Resolve_Info * info , int size , int oldsize , int mapcount ) ; 
void scheme_resolve_info_add_mapping (Resolve_Info * info , int oldp , int newp , int flags , Scheme_Object * lifted ) ; 
void scheme_resolve_info_adjust_mapping (Resolve_Info * info , int oldp , int newp , int flags , Scheme_Object * lifted ) ; 
int scheme_resolve_info_flags (Resolve_Info * info , int pos , Scheme_Object * * lifted ) ; 
int scheme_resolve_info_lookup (Resolve_Info * resolve , int pos , int * flags , Scheme_Object * * lifted , int convert_shift ) ; 
void scheme_resolve_info_set_toplevel_pos (Resolve_Info * info , int pos ) ; 
void scheme_enable_expression_resolve_lifts (Resolve_Info * ri ) ; 
Scheme_Object * scheme_merge_expression_resolve_lifts (Scheme_Object * expr , Resolve_Prefix * rp , Resolve_Info * ri ) ; 
Optimize_Info * scheme_optimize_info_create (void ) ; 
void scheme_optimize_propagate (Optimize_Info * info , int pos , Scheme_Object * value ) ; 
Scheme_Object * scheme_optimize_info_lookup (Optimize_Info * info , int pos , int * closure_offset ) ; 
void scheme_optimize_info_used_top (Optimize_Info * info ) ; 
void scheme_optimize_mutated (Optimize_Info * info , int pos ) ; 
Scheme_Object * scheme_optimize_reverse (Optimize_Info * info , int pos , int unless_mutated ) ; 
int scheme_optimize_is_used (Optimize_Info * info , int pos ) ; 
int scheme_optimize_any_uses (Optimize_Info * info , int start_pos , int end_pos ) ; 
Scheme_Object * scheme_optimize_clone (int dup_ok , Scheme_Object * obj , Optimize_Info * info , int delta , int closure_depth ) ; 
Scheme_Object * scheme_optimize_shift (Scheme_Object * obj , int delta , int after_depth ) ; 
Scheme_Object * scheme_clone_closure_compilation (int dup_ok , Scheme_Object * obj , Optimize_Info * info , int delta , int closure_depth ) ; 
Scheme_Object * scheme_shift_closure_compilation (Scheme_Object * obj , int delta , int after_depth ) ; 
int scheme_closure_body_size (Scheme_Closure_Data * closure_data , int check_assign ) ; 
int scheme_closure_argument_flags (Scheme_Closure_Data * closure_data , int i ) ; 
int scheme_closure_has_top_level (Scheme_Closure_Data * data ) ; 
Optimize_Info * scheme_optimize_info_add_frame (Optimize_Info * info , int orig , int current , int flags ) ; 
int scheme_optimize_info_get_shift (Optimize_Info * info , int pos ) ; 
void scheme_optimize_info_done (Optimize_Info * info ) ; 
Scheme_Object * scheme_toplevel_to_flagged_toplevel (Scheme_Object * tl , int flags ) ; 
void scheme_env_make_closure_map (Optimize_Info * frame , mzshort * size , mzshort * * map ) ; 
int scheme_env_uses_toplevel (Optimize_Info * frame ) ; 
int scheme_resolve_toplevel_pos (Resolve_Info * info ) ; 
int scheme_resolve_is_toplevel_available (Resolve_Info * info ) ; 
int scheme_resolve_quote_syntax_offset (int i , Resolve_Info * info ) ; 
int scheme_resolve_quote_syntax_pos (Resolve_Info * info ) ; 
Scheme_Object * scheme_resolve_toplevel (Resolve_Info * info , Scheme_Object * expr ) ; 
Scheme_Object * scheme_resolve_invent_toplevel (Resolve_Info * info ) ; 
Scheme_Object * scheme_resolve_invented_toplevel_to_defn (Resolve_Info * info , Scheme_Object * tl ) ; 
Scheme_Object * scheme_shift_toplevel (Scheme_Object * expr , int delta ) ; 
Scheme_Object * scheme_resolve_generate_stub_lift (void ) ; 
int scheme_resolve_quote_syntax (Resolve_Info * info , int oldpos ) ; 
int scheme_resolving_in_procedure (Resolve_Info * info ) ; 
void scheme_resolve_lift_definition (Resolve_Info * info , Scheme_Object * var , Scheme_Object * rhs ) ; 
Scheme_Object * scheme_make_compiled_syntax (Scheme_Syntax * syntax , Scheme_Syntax_Expander * exp ) ; 
Scheme_Object * scheme_compile_expr (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
Scheme_Object * scheme_compile_sequence (Scheme_Object * forms , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
Scheme_Object * scheme_compile_block (Scheme_Object * forms , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
Scheme_Object * scheme_compile_list (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
Scheme_Object * scheme_compile_expr_lift_to_let (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
void scheme_default_compile_rec (Scheme_Compile_Info * src , int drec ) ; 
void scheme_compile_rec_done_local (Scheme_Compile_Info * src , int drec ) ; 
void scheme_init_compile_recs (Scheme_Compile_Info * src , int drec , Scheme_Compile_Info * dest , int n ) ; 
void scheme_merge_compile_recs (Scheme_Compile_Info * src , int drec , Scheme_Compile_Info * dest , int n ) ; 
void scheme_init_lambda_rec (Scheme_Compile_Info * src , int drec , Scheme_Compile_Info * lam , int dlrec ) ; 
void scheme_merge_lambda_rec (Scheme_Compile_Info * src , int drec , Scheme_Compile_Info * lam , int dlrec ) ; 
void scheme_init_expand_recs (Scheme_Expand_Info * src , int drec , Scheme_Expand_Info * dest , int n ) ; 
void scheme_rec_add_certs (Scheme_Compile_Expand_Info * src , int drec , Scheme_Object * stx ) ; 
Scheme_Object * scheme_make_closure_compilation (Scheme_Comp_Env * env , Scheme_Object * uncompiled_code , Scheme_Compile_Info * rec , int drec ) ; 
Scheme_Object * scheme_make_sequence_compilation (Scheme_Object * compiled_list , int strip_values ) ; 
Scheme_Object * scheme_optimize_closure_compilation (Scheme_Object * _data , Optimize_Info * info ) ; 
Scheme_Object * scheme_resolve_closure_compilation (Scheme_Object * _data , Resolve_Info * info , int can_lift , int convert , int just_compute_lift , Scheme_Object * precomputed_lift ) ; 
Scheme_App_Rec * scheme_malloc_application (int n ) ; 
void scheme_finish_application (Scheme_App_Rec * app ) ; 
Scheme_Object * scheme_jit_expr (Scheme_Object * ) ; 
Scheme_Object * scheme_jit_closure (Scheme_Object * , Scheme_Object * context ) ; 
Scheme_Object * scheme_build_closure_name (Scheme_Object * code , Scheme_Compile_Info * rec , int drec ) ; 
int * scheme_env_get_flags (Scheme_Comp_Env * frame , int start , int count ) ; 
Scheme_Hash_Table * scheme_map_constants_to_globals (void ) ; 
Scheme_Object * scheme_expand_expr (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
Scheme_Object * scheme_expand_list (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
Scheme_Object * scheme_expand_block (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
Scheme_Object * scheme_expand_expr_lift_to_let (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
Scheme_Object * scheme_flatten_begin (Scheme_Object * expr , Scheme_Object * append_onto ) ; 
Scheme_Object * scheme_make_svector (mzshort v , mzshort * a ) ; 
Scheme_Object * scheme_hash_percent_name (const char * name , int len ) ; 
Scheme_Object * scheme_make_branch (Scheme_Object * test , Scheme_Object * tbranch , Scheme_Object * fbranch ) ; 
int scheme_is_toplevel (Scheme_Comp_Env * env ) ; 
Scheme_Comp_Env * scheme_extend_as_toplevel (Scheme_Comp_Env * env ) ; 
Scheme_Comp_Env * scheme_no_defines (Scheme_Comp_Env * env ) ; 
Scheme_Env * scheme_make_empty_env (void ) ; 
void scheme_prepare_exp_env (Scheme_Env * env ) ; 
void scheme_prepare_template_env (Scheme_Env * env ) ; 
int scheme_used_app_only (Scheme_Comp_Env * env , int which ) ; 
int scheme_used_ever (Scheme_Comp_Env * env , int which ) ; 
int scheme_omittable_expr (Scheme_Object * o , int vals ) ; 
int scheme_is_env_variable_boxed (Scheme_Comp_Env * env , int which ) ; 
int scheme_get_eval_type (Scheme_Object * obj ) ; 
Scheme_Object * scheme_get_stop_expander (void ) ; 
void scheme_define_parse (Scheme_Object * form , Scheme_Object * * vars , Scheme_Object * * val , int defmacro , Scheme_Comp_Env * env , int no_toplevel_check ) ; 
void scheme_shadow (Scheme_Env * env , Scheme_Object * n , int stxtoo ) ; 
int scheme_prefix_depth (Resolve_Prefix * rp ) ; 
Scheme_Object * * scheme_push_prefix (Scheme_Env * genv , Resolve_Prefix * rp , Scheme_Object * src_modix , Scheme_Object * now_modix , int src_phase , int now_phase ) ; 
void scheme_pop_prefix (Scheme_Object * * rs ) ; 
Scheme_Object * scheme_make_environment_dummy (Scheme_Comp_Env * env ) ; 
Scheme_Env * scheme_environment_from_dummy (Scheme_Object * dummy ) ; 
void scheme_validate_code (Mz_CPort * port , Scheme_Object * code , Scheme_Hash_Table * ht , int depth , int num_toplevels , int num_stxes , int num_lifts ) ; 
void scheme_validate_expr (Mz_CPort * port , Scheme_Object * expr , char * stack , Scheme_Hash_Table * ht , Scheme_Object * * tls , int depth , int letlimit , int delta , int num_toplevels , int num_stxes , int num_lifts , Scheme_Object * app_rator , int proc_with_refs_ok ) ; 
void scheme_validate_toplevel (Scheme_Object * expr , Mz_CPort * port , char * stack , Scheme_Hash_Table * ht , Scheme_Object * * tls , int depth , int delta , int num_toplevels , int num_stxes , int num_lifts , int skip_refs_check ) ; 
void scheme_validate_boxenv (int pos , Mz_CPort * port , char * stack , int depth , int delta ) ; 
int scheme_validate_rator_wants_box (Scheme_Object * app_rator , int pos , int hope , Scheme_Object * * tls , int num_toplevels , int num_stxes , int num_lifts ) ; 
void scheme_ill_formed (Mz_CPort * port , const char * file , int line ) ; 
extern Scheme_Object * scheme_inferred_name_symbol ; 
Scheme_Object * scheme_check_name_property (Scheme_Object * stx , Scheme_Object * current_name ) ; 
Scheme_Object * scheme_make_lifted_defn (Scheme_Object * sys_wraps , Scheme_Object * * _id , Scheme_Object * expr , Scheme_Comp_Env * env ) ; 
typedef struct Scheme_Marshal_Tables {
  Scheme_Type type ; 
  int pass , print_now ; 
  Scheme_Hash_Table * symtab ; 
  Scheme_Hash_Table * rns ; 
  Scheme_Hash_Table * rn_refs ; 
  Scheme_Hash_Table * st_refs ; 
  Scheme_Object * st_ref_stack ; 
  Scheme_Hash_Table * reverse_map ; 
  Scheme_Hash_Table * same_map ; 
  Scheme_Hash_Table * top_map ; 
  Scheme_Hash_Table * key_map ; 
  Scheme_Hash_Table * delay_map ; 
  Scheme_Hash_Table * rn_saved ; 
  long * shared_offsets ; 
  long sorted_keys_count ; 
  Scheme_Object * * sorted_keys ; 
}
Scheme_Marshal_Tables ; 
void scheme_marshal_using_key (Scheme_Marshal_Tables * mt , Scheme_Object * key ) ; 
Scheme_Object * scheme_marshal_lookup (Scheme_Marshal_Tables * mt , Scheme_Object * a ) ; 
Scheme_Object * scheme_marshal_wrap_set (Scheme_Marshal_Tables * mt , Scheme_Object * a , Scheme_Object * v ) ; 
void scheme_marshal_push_refs (Scheme_Marshal_Tables * mt ) ; 
void scheme_marshal_pop_refs (Scheme_Marshal_Tables * mt , int keep ) ; 
typedef struct Scheme_Unmarshal_Tables {
  Scheme_Type type ; 
  Scheme_Hash_Table * rns ; 
  struct CPort * rp ; 
  char * decoded ; 
}
Scheme_Unmarshal_Tables ; 
Scheme_Object * scheme_unmarshal_wrap_get (Scheme_Unmarshal_Tables * ut , Scheme_Object * wraps_key , int * _decoded ) ; 
void scheme_unmarshal_wrap_set (Scheme_Unmarshal_Tables * ut , Scheme_Object * wraps_key , Scheme_Object * v ) ; 
struct Scheme_Env {
  Scheme_Object so ; 
  struct Scheme_Module * module ; 
  Scheme_Hash_Table * module_registry ; 
  Scheme_Hash_Table * export_registry ; 
  Scheme_Object * insp ; 
  Scheme_Object * rename ; 
  Scheme_Object * et_rename ; 
  Scheme_Object * tt_rename ; 
  Scheme_Object * dt_rename ; 
  Scheme_Bucket_Table * syntax ; 
  struct Scheme_Env * exp_env ; 
  struct Scheme_Env * template_env ; 
  Scheme_Hash_Table * shadowed_syntax ; 
  long phase , mod_phase ; 
  Scheme_Object * link_midx ; 
  Scheme_Object * require_names , * et_require_names , * tt_require_names , * dt_require_names ; 
  char running , et_running , tt_running , lazy_syntax , attached ; 
  Scheme_Bucket_Table * toplevel ; 
  Scheme_Object * modchain ; 
  Scheme_Hash_Table * modvars ; 
  Scheme_Hash_Table * marked_names ; 
  int id_counter ; 
}
; 
typedef struct Scheme_Module {
  Scheme_Object so ; 
  Scheme_Object * modname ; 
  Scheme_Object * et_requires ; 
  Scheme_Object * requires ; 
  Scheme_Object * tt_requires ; 
  Scheme_Object * dt_requires ; 
  Scheme_Invoke_Proc prim_body ; 
  Scheme_Invoke_Proc prim_et_body ; 
  Scheme_Object * body ; 
  Scheme_Object * et_body ; 
  char functional , et_functional , tt_functional , no_cert ; 
  struct Scheme_Module_Exports * me ; 
  char * provide_protects ; 
  Scheme_Object * * indirect_provides ; 
  int num_indirect_provides ; 
  char * et_provide_protects ; 
  Scheme_Object * * et_indirect_provides ; 
  int num_indirect_et_provides ; 
  Scheme_Object * self_modidx ; 
  Scheme_Hash_Table * accessible ; 
  Scheme_Hash_Table * et_accessible ; 
  Scheme_Object * insp ; 
  Scheme_Object * hints ; 
  Scheme_Object * ii_src ; 
  Comp_Prefix * comp_prefix ; 
  int max_let_depth ; 
  Resolve_Prefix * prefix ; 
  Scheme_Object * dummy ; 
  Scheme_Env * primitive ; 
  Scheme_Object * rn_stx , * et_rn_stx , * tt_rn_stx , * dt_rn_stx ; 
}
Scheme_Module ; 
typedef struct Scheme_Module_Phase_Exports {
  Scheme_Type type ; 
  Scheme_Object * * provides ; 
  Scheme_Object * * provide_srcs ; 
  Scheme_Object * * provide_src_names ; 
  char * provide_src_phases ; 
  int num_provides ; 
  int num_var_provides ; 
  int reprovide_kernel ; 
  Scheme_Object * kernel_exclusion ; 
}
Scheme_Module_Phase_Exports ; 
typedef struct Scheme_Module_Exports {
  Scheme_Type type ; 
  Scheme_Module_Phase_Exports * rt , * et , * dt ; 
  Scheme_Object * src_modidx ; 
}
Scheme_Module_Exports ; 
typedef struct Scheme_Modidx {
  Scheme_Object so ; 
  Scheme_Object * path ; 
  Scheme_Object * base ; 
  Scheme_Object * resolved ; 
  Scheme_Object * shift_cache ; 
  struct Scheme_Modidx * cache_next ; 
}
Scheme_Modidx ; 
typedef struct Module_Variable {
  Scheme_Object so ; 
  Scheme_Object * modidx ; 
  Scheme_Object * sym ; 
  Scheme_Object * insp ; 
  int pos , mod_phase ; 
}
Module_Variable ; 
void scheme_add_global_keyword (const char * name , Scheme_Object * v , Scheme_Env * env ) ; 
void scheme_add_global_keyword_symbol (Scheme_Object * name , Scheme_Object * v , Scheme_Env * env ) ; 
void scheme_add_global_constant (const char * name , Scheme_Object * v , Scheme_Env * env ) ; 
void scheme_add_global_constant_symbol (Scheme_Object * name , Scheme_Object * v , Scheme_Env * env ) ; 
Scheme_Object * scheme_tl_id_sym (Scheme_Env * env , Scheme_Object * id , Scheme_Object * bdg , int is_def ) ; 
int scheme_tl_id_is_sym_used (Scheme_Hash_Table * marked_names , Scheme_Object * sym ) ; 
Scheme_Object * scheme_sys_wraps (Scheme_Comp_Env * env ) ; 
Scheme_Env * scheme_new_module_env (Scheme_Env * env , Scheme_Module * m , int new_exp_module_tree ) ; 
int scheme_is_module_env (Scheme_Comp_Env * env ) ; 
Scheme_Object * scheme_module_resolve (Scheme_Object * modidx , int load_it ) ; 
Scheme_Env * scheme_module_access (Scheme_Object * modname , Scheme_Env * env , int rev_mod_phase ) ; 
void scheme_module_force_lazy (Scheme_Env * env , int previous ) ; 
int scheme_module_export_position (Scheme_Object * modname , Scheme_Env * env , Scheme_Object * varname ) ; 
Scheme_Object * scheme_check_accessible_in_module (Scheme_Env * env , Scheme_Object * prot_insp , Scheme_Object * in_modidx , Scheme_Object * symbol , Scheme_Object * stx , Scheme_Object * certs , Scheme_Object * unexp_insp , int position , int want_pos , int * _protected ) ; 
Scheme_Object * scheme_module_syntax (Scheme_Object * modname , Scheme_Env * env , Scheme_Object * name ) ; 
Scheme_Object * scheme_modidx_shift (Scheme_Object * modidx , Scheme_Object * shift_from_modidx , Scheme_Object * shift_to_modidx ) ; 
Scheme_Object * scheme_hash_module_variable (Scheme_Env * env , Scheme_Object * modidx , Scheme_Object * stxsym , Scheme_Object * insp , int pos , int mod_phase ) ; 
extern Scheme_Env * scheme_initial_env ; 
void scheme_install_initial_module_set (Scheme_Env * env ) ; 
Scheme_Bucket_Table * scheme_clone_toplevel (Scheme_Bucket_Table * ht , Scheme_Env * home ) ; 
Scheme_Env * scheme_clone_module_env (Scheme_Env * menv , Scheme_Env * ns , Scheme_Object * modchain ) ; 
void scheme_clean_dead_env (Scheme_Env * env ) ; 
Scheme_Module * scheme_extract_compiled_module (Scheme_Object * o ) ; 
void scheme_clear_modidx_cache (void ) ; 
void scheme_clear_shift_cache (void ) ; 
void scheme_clear_prompt_cache (void ) ; 
void scheme_read_err (Scheme_Object * port , Scheme_Object * stxsrc , long line , long column , long pos , long span , int is_eof , Scheme_Object * indentation , const char * detail , ... ) ; 
char * scheme_extract_indentation_suggestions (Scheme_Object * indentation ) ; 
void scheme_wrong_syntax (const char * where , Scheme_Object * local_form , Scheme_Object * form , const char * detail , ... ) ; 
void scheme_wrong_syntax_with_more_sources (const char * where , Scheme_Object * detail_form , Scheme_Object * form , Scheme_Object * extra_sources , const char * detail , ... ) ; 
extern const char * scheme_compile_stx_string ; 
extern const char * scheme_expand_stx_string ; 
extern const char * scheme_application_stx_string ; 
extern const char * scheme_set_stx_string ; 
extern const char * scheme_var_ref_string ; 
extern const char * scheme_begin_stx_string ; 
void scheme_wrong_rator (Scheme_Object * rator , int argc , Scheme_Object * * argv ) ; 
void scheme_raise_out_of_memory (const char * where , const char * msg , ... ) ; 
extern unsigned long scheme_max_found_symbol_name ; 
char * scheme_make_arity_expect_string (Scheme_Object * proc , int argc , Scheme_Object * * argv , long * len ) ; 
long scheme_extract_index (const char * name , int pos , int argc , Scheme_Object * * argv , long top , int false_ok ) ; 
void scheme_get_substring_indices (const char * name , Scheme_Object * str , int argc , Scheme_Object * * argv , int spos , int fpos , long * _start , long * _finish ) ; 
void scheme_out_of_string_range (const char * name , const char * which , Scheme_Object * i , Scheme_Object * s , long start , long len ) ; 
const char * scheme_number_suffix (int ) ; 
void scheme_reset_prepared_error_buffer (void ) ; 
const char * scheme_hostname_error (int err ) ; 
char * scheme_make_args_string (char * s , int which , int argc , Scheme_Object * * argv , long * olen ) ; 
int scheme_byte_string_has_null (Scheme_Object * o ) ; 
int scheme_any_string_has_null (Scheme_Object * o ) ; 
Scheme_Object * scheme_do_exit (int argc , Scheme_Object * argv [] ) ; 
Scheme_Object * scheme_make_arity (mzshort minc , mzshort maxc ) ; 
Scheme_Object * scheme_arity (Scheme_Object * p ) ; 
typedef struct {
  Scheme_Type type ; 
  Scheme_Object * syms [5 ] ; 
  int count ; 
  long phase ; 
  Scheme_Hash_Table * ht ; 
}
DupCheckRecord ; 
void scheme_begin_dup_symbol_check (DupCheckRecord * r , Scheme_Comp_Env * e ) ; 
void scheme_dup_symbol_check (DupCheckRecord * r , const char * where , Scheme_Object * symbol , char * what , Scheme_Object * form ) ; 
extern int scheme_exiting_result ; 
Scheme_Object * scheme_special_comment_value (Scheme_Object * o ) ; 
Scheme_Object * scheme_get_stack_trace (Scheme_Object * mark_set ) ; 
Scheme_Object * scheme_get_or_check_arity (Scheme_Object * p , long a ) ; 
int scheme_native_arity_check (Scheme_Object * closure , int argc ) ; 
Scheme_Object * scheme_get_native_arity (Scheme_Object * closure ) ; 
int scheme_is_relative_path (const char * s , long len , int kind ) ; 
int scheme_is_complete_path (const char * s , long len , int kind ) ; 
Scheme_Object * scheme_get_file_directory (const char * filename ) ; 
char * scheme_normal_path_seps (char * s , int * _len , int delta ) ; 
int scheme_is_regular_file (char * filename ) ; 
void scheme_do_format (const char * procname , Scheme_Object * port , const mzchar * format , int flen , int fpos , int offset , int argc , Scheme_Object * * argv ) ; 
Scheme_Object * scheme_load_with_clrd (int argc , Scheme_Object * argv [] , char * who , int handler_param ) ; 
Scheme_Object * scheme_default_load_extension (int argc , Scheme_Object * * argv ) ; 
Scheme_Object * scheme_remove_current_directory_prefix (Scheme_Object * fn ) ; 
char * scheme_get_exec_path (void ) ; 
Scheme_Object * scheme_get_fd_identity (Scheme_Object * port , long fd ) ; 
Scheme_Object * scheme_extract_relative_to (Scheme_Object * obj , Scheme_Object * dir ) ; 
extern int scheme_active_but_sleeping ; 
extern int scheme_file_open_count ; 
typedef struct Scheme_Indexed_String {
  Scheme_Type type ; 
  char * string ; 
  int size ; 
  int index ; 
  union {
    int hot ; 
    int pos ; 
  }
  u ; 
}
Scheme_Indexed_String ; 
typedef struct Scheme_Pipe {
  Scheme_Type type ; 
  unsigned char * buf ; 
  long buflen , bufmax ; 
  long bufmaxextra ; 
  long bufstart , bufend ; 
  int eof ; 
  Scheme_Object * wakeup_on_read ; 
  Scheme_Object * wakeup_on_write ; 
}
Scheme_Pipe ; 
extern Scheme_Object * scheme_string_input_port_type ; 
extern Scheme_Object * scheme_string_output_port_type ; 
extern Scheme_Object * scheme_user_input_port_type ; 
extern Scheme_Object * scheme_user_output_port_type ; 
extern Scheme_Object * scheme_pipe_read_port_type ; 
extern Scheme_Object * scheme_pipe_write_port_type ; 
extern Scheme_Object * scheme_null_output_port_type ; 
extern Scheme_Object * scheme_tcp_input_port_type ; 
extern Scheme_Object * scheme_tcp_output_port_type ; 
extern int scheme_force_port_closed ; 
void scheme_flush_orig_outputs (void ) ; 
Scheme_Object * scheme_file_stream_port_p (int , Scheme_Object * [] ) ; 
Scheme_Object * scheme_terminal_port_p (int , Scheme_Object * [] ) ; 
Scheme_Object * scheme_do_open_input_file (char * name , int offset , int argc , Scheme_Object * argv [] ) ; 
Scheme_Object * scheme_do_open_output_file (char * name , int offset , int argc , Scheme_Object * argv [] , int and_read ) ; 
Scheme_Object * scheme_file_position (int argc , Scheme_Object * argv [] ) ; 
Scheme_Object * scheme_file_buffer (int argc , Scheme_Object * argv [] ) ; 
Scheme_Object * scheme_file_identity (int argc , Scheme_Object * argv [] ) ; 
long scheme_get_byte_string_or_ch_put (const char * who , Scheme_Object * port , char * buffer , long offset , long size , int only_avail , int peek , Scheme_Object * peek_skip , Scheme_Object * unless_evt , Scheme_Object * target_ch ) ; 
Scheme_Object * scheme_get_special (Scheme_Object * inport , Scheme_Object * stxsrc , long line , long col , long pos , int peek , Scheme_Hash_Table * * for_read ) ; 
Scheme_Object * scheme_get_ready_read_special (Scheme_Object * port , Scheme_Object * stxsrc , Scheme_Hash_Table * * ht ) ; 
void scheme_set_in_read_mark (Scheme_Object * stxsrc , Scheme_Hash_Table * * ht ) ; 
Scheme_Object * scheme_get_special_proc (Scheme_Object * inport ) ; 
void scheme_bad_time_for_special (const char * name , Scheme_Object * port ) ; 
extern int scheme_special_ok ; 
int scheme_user_port_byte_probably_ready (Scheme_Input_Port * ip , Scheme_Schedule_Info * sinfo ) ; 
int scheme_user_port_write_probably_ready (Scheme_Output_Port * op , Scheme_Schedule_Info * sinfo ) ; 
int scheme_is_user_port (Scheme_Object * port ) ; 
int scheme_byte_ready_or_user_port_ready (Scheme_Object * p , Scheme_Schedule_Info * sinfo ) ; 
Scheme_Object * scheme_checked_car (int argc , Scheme_Object * * argv ) ; 
Scheme_Object * scheme_checked_cdr (int argc , Scheme_Object * * argv ) ; 
Scheme_Object * scheme_checked_caar (int argc , Scheme_Object * * argv ) ; 
Scheme_Object * scheme_checked_cadr (int argc , Scheme_Object * * argv ) ; 
Scheme_Object * scheme_checked_cdar (int argc , Scheme_Object * * argv ) ; 
Scheme_Object * scheme_checked_cddr (int argc , Scheme_Object * * argv ) ; 
Scheme_Object * scheme_checked_set_car (int argc , Scheme_Object * argv [] ) ; 
Scheme_Object * scheme_checked_set_cdr (int argc , Scheme_Object * argv [] ) ; 
Scheme_Object * scheme_checked_vector_ref (int argc , Scheme_Object * * argv ) ; 
Scheme_Object * scheme_checked_vector_set (int argc , Scheme_Object * * argv ) ; 
Scheme_Object * scheme_checked_string_ref (int argc , Scheme_Object * argv [] ) ; 
Scheme_Object * scheme_checked_string_set (int argc , Scheme_Object * argv [] ) ; 
Scheme_Object * scheme_checked_byte_string_ref (int argc , Scheme_Object * argv [] ) ; 
Scheme_Object * scheme_checked_byte_string_set (int argc , Scheme_Object * argv [] ) ; 
Scheme_Object * scheme_checked_syntax_e (int argc , Scheme_Object * * argv ) ; 
void scheme_set_root_param (int p , Scheme_Object * v ) ; 
Scheme_Object * scheme_intern_exact_parallel_symbol (const char * name , unsigned int len ) ; 
Scheme_Object * scheme_symbol_append (Scheme_Object * s1 , Scheme_Object * s2 ) ; 
Scheme_Object * scheme_copy_list (Scheme_Object * l ) ; 
void scheme_reset_hash_table (Scheme_Hash_Table * ht , int * history ) ; 
Scheme_Object * scheme_regexp_source (Scheme_Object * re ) ; 
int scheme_regexp_is_byte (Scheme_Object * re ) ; 
Scheme_Object * scheme_make_regexp (Scheme_Object * str , int byte , int pcre , int * volatile result_is_err_string ) ; 
int scheme_is_pregexp (Scheme_Object * o ) ; 
void scheme_clear_rx_buffers (void ) ; 
unsigned short * scheme_ucs4_to_utf16 (const mzchar * text , int start , int end , unsigned short * buf , int bufsize , long * ulen , int term_size ) ; 
