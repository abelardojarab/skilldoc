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
typedef signed int __int32_t ; 
typedef long int __quad_t ; 
typedef unsigned long int __u_quad_t ; 
typedef unsigned long int __dev_t ; 
typedef unsigned int __uid_t ; 
typedef unsigned int __gid_t ; 
typedef unsigned long int __ino_t ; 
typedef unsigned int __mode_t ; 
typedef unsigned long int __nlink_t ; 
typedef long int __off_t ; 
typedef long int __off64_t ; 
typedef int __pid_t ; 
typedef struct {
  int __val [2 ] ; 
}
__fsid_t ; 
typedef unsigned int __id_t ; 
typedef long int __time_t ; 
typedef long int __suseconds_t ; 
typedef int __daddr_t ; 
typedef int __key_t ; 
typedef int __clockid_t ; 
typedef void * __timer_t ; 
typedef long int __blkcnt_t ; 
typedef unsigned long int __fsblkcnt_t ; 
typedef unsigned long int __fsfilcnt_t ; 
typedef long int __ssize_t ; 
typedef __off64_t __loff_t ; 
typedef char * __caddr_t ; 
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
typedef __ssize_t __io_read_fn (void * __cookie , char * __buf , size_t __nbytes ) ; 
typedef __ssize_t __io_write_fn (void * __cookie , __const char * __buf , size_t __n ) ; 
typedef int __io_seek_fn (void * __cookie , __off64_t * __pos , int __w ) ; 
typedef int __io_close_fn (void * __cookie ) ; 
typedef _G_fpos_t fpos_t ; 
extern int rename (__const char * __old , __const char * __new ) __attribute__ ((__nothrow__ ) ) ; 
extern int sprintf (char * __restrict __s , __const char * __restrict __format , ... ) __attribute__ ((__nothrow__ ) ) ; 
extern __const char * __const sys_errlist [] ; 
typedef long int __jmp_buf [8 ] ; 
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
extern int _setjmp (struct __jmp_buf_tag __env [1 ] ) __attribute__ ((__nothrow__ ) ) ; 
typedef struct __jmp_buf_tag sigjmp_buf [1 ] ; 
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
typedef int int8_t __attribute__ ((__mode__ (__QI__ ) ) ) ; 
typedef int int16_t __attribute__ ((__mode__ (__HI__ ) ) ) ; 
typedef int int32_t __attribute__ ((__mode__ (__SI__ ) ) ) ; 
typedef int int64_t __attribute__ ((__mode__ (__DI__ ) ) ) ; 
typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__ ) ) ) ; 
typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__ ) ) ) ; 
typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__ ) ) ) ; 
typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__ ) ) ) ; 
typedef int register_t __attribute__ ((__mode__ (__word__ ) ) ) ; 
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
typedef long int __fd_mask ; 
typedef struct {
  __fd_mask __fds_bits [1024 / (8 * sizeof (__fd_mask ) ) ] ; 
}
fd_set ; 
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
extern int rand (void ) __attribute__ ((__nothrow__ ) ) ; 
struct drand48_data {
  unsigned short int __x [3 ] ; 
  unsigned short int __old_x [3 ] ; 
  unsigned short int __c ; 
  unsigned short int __init ; 
  unsigned long long int __a ; 
}
; 
extern void * malloc (size_t __size ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__malloc__ ) ) ; 
extern void free (void * __ptr ) __attribute__ ((__nothrow__ ) ) ; 
extern char * getenv (__const char * __name ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern int putenv (char * __string ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
typedef int (* __compar_fn_t ) (__const void * , __const void * ) ; 
extern void * memcpy (void * __restrict __dest , __const void * __restrict __src , size_t __n ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern void * memmove (void * __dest , __const void * __src , size_t __n ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern void * memset (void * __s , int __c , size_t __n ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern char * strcpy (char * __restrict __dest , __const char * __restrict __src ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern int strcmp (__const char * __s1 , __const char * __s2 ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__pure__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern int strcoll (__const char * __s1 , __const char * __s2 ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__pure__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern size_t strlen (__const char * __s ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__pure__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern char * index (__const char * __s , int __c ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__pure__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
typedef short Scheme_Type ; 
typedef int mzshort ; 
typedef unsigned int mzchar ; 
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
extern void scheme_jit_setjmp_prepare (mz_jit_jmp_buf b ) ; 
typedef int (* Size_Proc ) (void * obj ) ; 
typedef int (* Mark_Proc ) (void * obj ) ; 
typedef int (* Fixup_Proc ) (void * obj ) ; 
extern unsigned long (* GC_get_thread_stack_base ) (void ) ; 
extern void (* GC_collect_start_callback ) (void ) ; 
extern void (* GC_collect_end_callback ) (void ) ; 
extern void (* GC_out_of_memory ) (void ) ; 
extern void * GC_malloc (size_t size_in_bytes ) ; 
extern void * GC_malloc_one_tagged (size_t ) ; 
extern void * GC_malloc_one_small_tagged (size_t ) ; 
extern void (* GC_mark_xtagged ) (void * obj ) ; 
extern void (* GC_fixup_xtagged ) (void * obj ) ; 
extern void * GC_malloc_array_tagged (size_t ) ; 
extern void * GC_malloc_atomic (size_t size_in_bytes ) ; 
extern void * GC_malloc_atomic_uncollectable (size_t size_in_bytes ) ; 
extern void * GC_malloc_allow_interior (size_t size_in_bytes ) ; 
extern void * GC_malloc_atomic_allow_interior (size_t size_in_bytes ) ; 
extern void * GC_malloc_tagged_allow_interior (size_t size_in_bytes ) ; 
typedef void (* GC_finalization_proc ) (void * p , void * data ) ; 
extern void * * GC_variable_stack ; 
extern void * * GC_get_variable_stack () ; 
extern void GC_set_variable_stack (void * * p ) ; 
extern void GC_register_traversers (short tag , Size_Proc size , Mark_Proc mark , Fixup_Proc fixup , int is_constant_size , int is_atomic ) ; 
extern void * GC_resolve (void * p ) ; 
extern void GC_mark (const void * p ) ; 
extern void GC_fixup (void * p ) ; 
extern void scheme_set_startup_use_jit (int ) ; 
extern Scheme_Thread * scheme_current_thread ; 
typedef void (* Scheme_Exit_Proc ) (int v ) ; 
typedef void (* scheme_console_printf_t ) (char * str , ... ) ; 
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
extern int (* scheme_actual_main ) (int argc , char * * argv ) ; 
extern void scheme_register_static (void * ptr , long size ) ; 
extern void (* scheme_on_atomic_timeout ) (void ) ; 
extern Scheme_Object * scheme_param_config (char * name , Scheme_Object * pos , int argc , Scheme_Object * * argv , int arity , Scheme_Prim * check , char * expected , int isbool ) ; 
extern Scheme_Object * scheme_register_parameter (Scheme_Prim * function , char * name , int which ) ; 
extern void scheme_clear_escape (void ) ; 
extern Scheme_Config * scheme_current_config (void ) ; 
extern Scheme_Object * scheme_get_param (Scheme_Config * c , int pos ) ; 
extern Scheme_Thread * scheme_current_thread ; 
extern volatile int scheme_fuel_counter ; 
extern void scheme_out_of_fuel (void ) ; 
extern Scheme_Custodian_Reference * scheme_add_managed (Scheme_Custodian * m , Scheme_Object * o , Scheme_Close_Custodian_Client * f , void * data , int strong ) ; 
extern void scheme_custodian_check_available (Scheme_Custodian * m , const char * who , const char * what ) ; 
extern void scheme_remove_managed (Scheme_Custodian_Reference * m , Scheme_Object * o ) ; 
extern void scheme_raise_exn (int exnid , ... ) ; 
extern void scheme_wrong_type (const char * name , const char * expected , int which , int argc , Scheme_Object * * argv ) ; 
extern void scheme_arg_mismatch (const char * name , const char * msg , Scheme_Object * o ) ; 
extern Scheme_Object scheme_eof [1 ] ; 
extern Scheme_Object scheme_null [1 ] ; 
extern Scheme_Object scheme_true [1 ] ; 
extern Scheme_Object scheme_false [1 ] ; 
extern Scheme_Object scheme_void [1 ] ; 
extern Scheme_Object scheme_undefined [1 ] ; 
extern unsigned short * scheme_uchar_table [] ; 
extern unsigned char * scheme_uchar_cases_table [] ; 
extern unsigned char * scheme_uchar_cats_table [] ; 
extern int scheme_uchar_ups [] ; 
extern int scheme_uchar_downs [] ; 
extern int scheme_uchar_titles [] ; 
extern int scheme_uchar_folds [] ; 
extern unsigned char scheme_uchar_combining_classes [] ; 
extern Scheme_Object * scheme_values (int c , Scheme_Object * * v ) ; 
extern Scheme_Object * scheme_do_eval (Scheme_Object * obj , int _num_rands , Scheme_Object * * rands , int val ) ; 
extern void * GC_malloc (size_t size_in_bytes ) ; 
extern void * GC_malloc_atomic (size_t size_in_bytes ) ; 
extern void * GC_malloc_one_tagged (size_t size_in_bytes ) ; 
extern void * GC_malloc_atomic_uncollectable (size_t size_in_bytes ) ; 
extern void * GC_malloc_array_tagged (size_t size_in_bytes ) ; 
extern void * GC_malloc_allow_interior (size_t size_in_bytes ) ; 
extern void * GC_malloc_atomic_allow_interior (size_t size_in_bytes ) ; 
extern void * GC_malloc_tagged_allow_interior (size_t size_in_bytes ) ; 
extern void * scheme_malloc_fail_ok (void * (* f ) (size_t ) , size_t ) ; 
extern void * * GC_variable_stack ; 
extern void GC_register_traversers (short tag , Size_Proc size , Mark_Proc mark , Fixup_Proc fixup , int is_constant_size , int is_atomic ) ; 
extern void * GC_resolve (void * p ) ; 
extern void GC_mark (const void * p ) ; 
extern void GC_fixup (void * p ) ; 
extern Scheme_Hash_Table * scheme_make_hash_table (int type ) ; 
extern void scheme_hash_set (Scheme_Hash_Table * table , Scheme_Object * key , Scheme_Object * val ) ; 
extern Scheme_Object * scheme_hash_get (Scheme_Hash_Table * table , Scheme_Object * key ) ; 
extern Scheme_Object * scheme_make_folding_prim (Scheme_Prim * prim , const char * name , mzshort mina , mzshort maxa , short functional ) ; 
extern Scheme_Object * scheme_make_noncm_prim (Scheme_Prim * prim , const char * name , mzshort mina , mzshort maxa ) ; 
extern Scheme_Object * scheme_make_prim_w_everything (Scheme_Prim * fun , int eternal , const char * name , mzshort mina , mzshort maxa , int folding , mzshort minr , mzshort maxr ) ; 
extern Scheme_Object * scheme_make_pair (Scheme_Object * car , Scheme_Object * cdr ) ; 
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
extern Scheme_Object * scheme_make_char (mzchar ch ) ; 
extern Scheme_Object * * scheme_char_constants ; 
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
extern Scheme_Object * scheme_complex_real_part (const Scheme_Object * n ) ; 
extern void scheme_write_byte_string (const char * str , long len , Scheme_Object * port ) ; 
extern long scheme_put_char_string (const char * who , Scheme_Object * port , const mzchar * str , long d , long len ) ; 
extern char * scheme_format (mzchar * format , int flen , int argc , Scheme_Object * * argv , long * rlen ) ; 
extern void scheme_printf (mzchar * format , int flen , int argc , Scheme_Object * * argv ) ; 
extern char * scheme_format_utf8 (char * format , int flen , int argc , Scheme_Object * * argv , long * rlen ) ; 
extern void scheme_printf_utf8 (char * format , int flen , int argc , Scheme_Object * * argv ) ; 
extern long scheme_get_bytes (Scheme_Object * port , long size , char * buffer , int offset ) ; 
extern void scheme_close_input_port (Scheme_Object * port ) ; 
extern void scheme_close_output_port (Scheme_Object * port ) ; 
__xform_nongcing__ extern int scheme_is_output_port (Scheme_Object * port ) ; 
extern Scheme_Object * scheme_make_byte_string_output_port () ; 
extern char * scheme_get_sized_byte_string_output (Scheme_Object * port , long * len ) ; 
extern int scheme_file_exists (char * filename ) ; 
extern Scheme_Object * scheme_make_path (const char * chars ) ; 
extern void scheme_require_from_original_env (Scheme_Env * env , int syntax_only ) ; 
extern Scheme_Object * scheme_builtin_value (const char * name ) ; 
extern Scheme_Object * scheme_intern_symbol (const char * name ) ; 
__xform_nongcing__ extern long scheme_hash_key (Scheme_Object * o ) ; 
extern int scheme_list_length (Scheme_Object * list ) ; 
extern char * scheme_banner (void ) ; 
extern char * scheme_version (void ) ; 
extern char * scheme_make_provided_string (Scheme_Object * o , int count , int * len ) ; 
extern char * scheme_make_args_string (char * s , int which , int argc , Scheme_Object * * argv , long * len ) ; 
extern const char * scheme_system_library_subpath () ; 
extern int scheme_char_strlen (const mzchar * s ) ; 
long scheme_hash_key (Scheme_Object * o ) ; 
typedef int (* Compare_Proc ) (void * v1 , void * v2 ) ; 
void scheme_init_string (Scheme_Env * env ) ; 
void scheme_init_getenv (void ) ; 
typedef Scheme_Object * (* Scheme_Type_Reader ) (Scheme_Object * list ) ; 
typedef Scheme_Object * (* Scheme_Type_Writer ) (Scheme_Object * obj ) ; 
extern Scheme_Object * scheme_define_values_syntax , * scheme_define_syntaxes_syntax ; 
extern Scheme_Object * scheme_arity_at_least , * scheme_make_arity_at_least ; 
extern Scheme_Object * scheme_write_proc , * scheme_display_proc , * scheme_print_proc ; 
extern Scheme_Object * scheme_recur_symbol , * scheme_display_symbol , * scheme_write_special_symbol ; 
extern Scheme_Object * scheme_none_symbol , * scheme_line_symbol , * scheme_block_symbol ; 
extern Scheme_Object * scheme_input_port_property , * scheme_output_port_property ; 
extern volatile int scheme_fuel_counter ; 
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
typedef int (* Scheme_Ready_Fun_FPC ) (Scheme_Object * o , Scheme_Schedule_Info * sinfo ) ; 
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
char * scheme_number_to_string (int radix , Scheme_Object * obj ) ; 
typedef struct {
  Scheme_Object so ; 
  Scheme_Object * num ; 
  Scheme_Object * denom ; 
}
Scheme_Rational ; 
typedef Scheme_Rational Small_Rational ; 
typedef struct {
  Scheme_Object so ; 
  Scheme_Object * r ; 
  Scheme_Object * i ; 
}
Scheme_Complex ; 
typedef Scheme_Complex Small_Complex ; 
extern double scheme_infinity_val , scheme_minus_infinity_val ; 
extern Scheme_Object * scheme_zerod , * scheme_nzerod , * scheme_pi , * scheme_half_pi , * scheme_plus_i , * scheme_minus_i ; 
extern Scheme_Object * scheme_inf_object , * scheme_minus_inf_object , * scheme_nan_object ; 
Scheme_Object * scheme_bin_minus (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
int scheme_bin_lt (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
typedef struct {
  Scheme_Object so ; 
  double x10 , x11 , x12 , x20 , x21 , x22 ; 
}
Scheme_Random_State ; 
__xform_nongcing__ int scheme_strncmp (const char * a , const char * b , int len ) ; 
struct Scheme_Load_Delay ; 
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
extern Scheme_Object * scheme_local [64 ] [2 ] ; 
typedef Scheme_Object * (* Scheme_Lift_Capture_Proc ) (Scheme_Object * , Scheme_Object * * , Scheme_Object * , Scheme_Comp_Env * ) ; 
extern Scheme_Syntax_Optimizer scheme_syntax_optimizers [12 ] ; 
extern Scheme_Syntax_Resolver scheme_syntax_resolvers [12 ] ; 
extern Scheme_Syntax_Validater scheme_syntax_validaters [12 ] ; 
extern Scheme_Syntax_Executer scheme_syntax_executers [12 ] ; 
extern Scheme_Syntax_Jitter scheme_syntax_jitters [12 ] ; 
extern Scheme_Syntax_Cloner scheme_syntax_cloners [12 ] ; 
extern Scheme_Syntax_Shifter scheme_syntax_shifters [12 ] ; 
extern int scheme_syntax_protect_afters [12 ] ; 
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
typedef struct Scheme_Unmarshal_Tables {
  Scheme_Type type ; 
  Scheme_Hash_Table * rns ; 
  struct CPort * rp ; 
  char * decoded ; 
}
Scheme_Unmarshal_Tables ; 
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
void scheme_add_global_constant (const char * name , Scheme_Object * v , Scheme_Env * env ) ; 
void scheme_raise_out_of_memory (const char * where , const char * msg , ... ) ; 
long scheme_extract_index (const char * name , int pos , int argc , Scheme_Object * * argv , long top , int false_ok ) ; 
void scheme_get_substring_indices (const char * name , Scheme_Object * str , int argc , Scheme_Object * * argv , int spos , int fpos , long * _start , long * _finish ) ; 
void scheme_out_of_string_range (const char * name , const char * which , Scheme_Object * i , Scheme_Object * s , long start , long len ) ; 
char * scheme_make_args_string (char * s , int which , int argc , Scheme_Object * * argv , long * olen ) ; 
int scheme_byte_string_has_null (Scheme_Object * o ) ; 
int scheme_any_string_has_null (Scheme_Object * o ) ; 
typedef struct {
  Scheme_Type type ; 
  Scheme_Object * syms [5 ] ; 
  int count ; 
  long phase ; 
  Scheme_Hash_Table * ht ; 
}
DupCheckRecord ; 
void scheme_do_format (const char * procname , Scheme_Object * port , const mzchar * format , int flen , int fpos , int offset , int argc , Scheme_Object * * argv ) ; 
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
Scheme_Object * scheme_checked_string_ref (int argc , Scheme_Object * argv [] ) ; 
Scheme_Object * scheme_checked_string_set (int argc , Scheme_Object * argv [] ) ; 
Scheme_Object * scheme_checked_byte_string_ref (int argc , Scheme_Object * argv [] ) ; 
Scheme_Object * scheme_checked_byte_string_set (int argc , Scheme_Object * argv [] ) ; 
unsigned short * scheme_ucs4_to_utf16 (const mzchar * text , int start , int end , unsigned short * buf , int bufsize , long * ulen , int term_size ) ; 
enum {
  _ISupper = ((0 ) < 8 ? ((1 << (0 ) ) << 8 ) : ((1 << (0 ) ) >> 8 ) ) , _ISlower = ((1 ) < 8 ? ((1 << (1 ) ) << 8 ) : ((1 << (1 ) ) >> 8 ) ) , _ISalpha = ((2 ) < 8 ? ((1 << (2 ) ) << 8 ) : ((1 << (2 ) ) >> 8 ) ) , _ISdigit = ((3 ) < 8 ? ((1 << (3 ) ) << 8 ) : ((1 << (3 ) ) >> 8 ) ) , _ISxdigit = ((4 ) < 8 ? ((1 << (4 ) ) << 8 ) : ((1 << (4 ) ) >> 8 ) ) , _ISspace = ((5 ) < 8 ? ((1 << (5 ) ) << 8 ) : ((1 << (5 ) ) >> 8 ) ) , _ISprint = ((6 ) < 8 ? ((1 << (6 ) ) << 8 ) : ((1 << (6 ) ) >> 8 ) ) , _ISgraph = ((7 ) < 8 ? ((1 << (7 ) ) << 8 ) : ((1 << (7 ) ) >> 8 ) ) , _ISblank = ((8 ) < 8 ? ((1 << (8 ) ) << 8 ) : ((1 << (8 ) ) >> 8 ) ) , _IScntrl = ((9 ) < 8 ? ((1 << (9 ) ) << 8 ) : ((1 << (9 ) ) >> 8 ) ) , _ISpunct = ((10 ) < 8 ? ((1 << (10 ) ) << 8 ) : ((1 << (10 ) ) >> 8 ) ) , _ISalnum = ((11 ) < 8 ? ((1 << (11 ) ) << 8 ) : ((1 << (11 ) ) >> 8 ) ) }
; 
extern __const unsigned short int * * __ctype_b_loc (void ) __attribute__ ((__const ) ) ; 
enum {
  __LC_CTYPE = 0 , __LC_NUMERIC = 1 , __LC_TIME = 2 , __LC_COLLATE = 3 , __LC_MONETARY = 4 , __LC_MESSAGES = 5 , __LC_ALL = 6 , __LC_PAPER = 7 , __LC_NAME = 8 , __LC_ADDRESS = 9 , __LC_TELEPHONE = 10 , __LC_MEASUREMENT = 11 , __LC_IDENTIFICATION = 12 }
; 
struct lconv {
  char * decimal_point ; 
  char * thousands_sep ; 
  char * grouping ; 
  char * int_curr_symbol ; 
  char * currency_symbol ; 
  char * mon_decimal_point ; 
  char * mon_thousands_sep ; 
  char * mon_grouping ; 
  char * positive_sign ; 
  char * negative_sign ; 
  char int_frac_digits ; 
  char frac_digits ; 
  char p_cs_precedes ; 
  char p_sep_by_space ; 
  char n_cs_precedes ; 
  char n_sep_by_space ; 
  char p_sign_posn ; 
  char n_sign_posn ; 
  char __int_p_cs_precedes ; 
  char __int_p_sep_by_space ; 
  char __int_n_cs_precedes ; 
  char __int_n_sep_by_space ; 
  char __int_p_sign_posn ; 
  char __int_n_sign_posn ; 
}
; 
extern char * setlocale (int __category , __const char * __locale ) __attribute__ ((__nothrow__ ) ) ; 
typedef void * iconv_t ; 
extern iconv_t iconv_open (__const char * __tocode , __const char * __fromcode ) ; 
extern size_t iconv (iconv_t __cd , char * * __restrict __inbuf , size_t * __restrict __inbytesleft , char * * __restrict __outbuf , size_t * __restrict __outbytesleft ) ; 
extern int iconv_close (iconv_t __cd ) ; 
typedef void * nl_catd ; 
typedef int nl_item ; 
enum {
  ABDAY_1 = (((__LC_TIME ) << 16 ) | (0 ) ) , ABDAY_2 , ABDAY_3 , ABDAY_4 , ABDAY_5 , ABDAY_6 , ABDAY_7 , DAY_1 , DAY_2 , DAY_3 , DAY_4 , DAY_5 , DAY_6 , DAY_7 , ABMON_1 , ABMON_2 , ABMON_3 , ABMON_4 , ABMON_5 , ABMON_6 , ABMON_7 , ABMON_8 , ABMON_9 , ABMON_10 , ABMON_11 , ABMON_12 , MON_1 , MON_2 , MON_3 , MON_4 , MON_5 , MON_6 , MON_7 , MON_8 , MON_9 , MON_10 , MON_11 , MON_12 , AM_STR , PM_STR , D_T_FMT , D_FMT , T_FMT , T_FMT_AMPM , ERA , __ERA_YEAR , ERA_D_FMT , ALT_DIGITS , ERA_D_T_FMT , ERA_T_FMT , _NL_TIME_ERA_NUM_ENTRIES , _NL_TIME_ERA_ENTRIES , _NL_WABDAY_1 , _NL_WABDAY_2 , _NL_WABDAY_3 , _NL_WABDAY_4 , _NL_WABDAY_5 , _NL_WABDAY_6 , _NL_WABDAY_7 , _NL_WDAY_1 , _NL_WDAY_2 , _NL_WDAY_3 , _NL_WDAY_4 , _NL_WDAY_5 , _NL_WDAY_6 , _NL_WDAY_7 , _NL_WABMON_1 , _NL_WABMON_2 , _NL_WABMON_3 , _NL_WABMON_4 , _NL_WABMON_5 , _NL_WABMON_6 , _NL_WABMON_7 , _NL_WABMON_8 , _NL_WABMON_9 , _NL_WABMON_10 , _NL_WABMON_11 , _NL_WABMON_12 , _NL_WMON_1 , _NL_WMON_2 , _NL_WMON_3 , _NL_WMON_4 , _NL_WMON_5 , _NL_WMON_6 , _NL_WMON_7 , _NL_WMON_8 , _NL_WMON_9 , _NL_WMON_10 , _NL_WMON_11 , _NL_WMON_12 , _NL_WAM_STR , _NL_WPM_STR , _NL_WD_T_FMT , _NL_WD_FMT , _NL_WT_FMT , _NL_WT_FMT_AMPM , _NL_WERA_YEAR , _NL_WERA_D_FMT , _NL_WALT_DIGITS , _NL_WERA_D_T_FMT , _NL_WERA_T_FMT , _NL_TIME_WEEK_NDAYS , _NL_TIME_WEEK_1STDAY , _NL_TIME_WEEK_1STWEEK , _NL_TIME_FIRST_WEEKDAY , _NL_TIME_FIRST_WORKDAY , _NL_TIME_CAL_DIRECTION , _NL_TIME_TIMEZONE , _DATE_FMT , _NL_W_DATE_FMT , _NL_TIME_CODESET , _NL_NUM_LC_TIME , _NL_COLLATE_NRULES = (((__LC_COLLATE ) << 16 ) | (0 ) ) , _NL_COLLATE_RULESETS , _NL_COLLATE_TABLEMB , _NL_COLLATE_WEIGHTMB , _NL_COLLATE_EXTRAMB , _NL_COLLATE_INDIRECTMB , _NL_COLLATE_GAP1 , _NL_COLLATE_GAP2 , _NL_COLLATE_GAP3 , _NL_COLLATE_TABLEWC , _NL_COLLATE_WEIGHTWC , _NL_COLLATE_EXTRAWC , _NL_COLLATE_INDIRECTWC , _NL_COLLATE_SYMB_HASH_SIZEMB , _NL_COLLATE_SYMB_TABLEMB , _NL_COLLATE_SYMB_EXTRAMB , _NL_COLLATE_COLLSEQMB , _NL_COLLATE_COLLSEQWC , _NL_COLLATE_CODESET , _NL_NUM_LC_COLLATE , _NL_CTYPE_CLASS = (((__LC_CTYPE ) << 16 ) | (0 ) ) , _NL_CTYPE_TOUPPER , _NL_CTYPE_GAP1 , _NL_CTYPE_TOLOWER , _NL_CTYPE_GAP2 , _NL_CTYPE_CLASS32 , _NL_CTYPE_GAP3 , _NL_CTYPE_GAP4 , _NL_CTYPE_GAP5 , _NL_CTYPE_GAP6 , _NL_CTYPE_CLASS_NAMES , _NL_CTYPE_MAP_NAMES , _NL_CTYPE_WIDTH , _NL_CTYPE_MB_CUR_MAX , _NL_CTYPE_CODESET_NAME , CODESET = _NL_CTYPE_CODESET_NAME , _NL_CTYPE_TOUPPER32 , _NL_CTYPE_TOLOWER32 , _NL_CTYPE_CLASS_OFFSET , _NL_CTYPE_MAP_OFFSET , _NL_CTYPE_INDIGITS_MB_LEN , _NL_CTYPE_INDIGITS0_MB , _NL_CTYPE_INDIGITS1_MB , _NL_CTYPE_INDIGITS2_MB , _NL_CTYPE_INDIGITS3_MB , _NL_CTYPE_INDIGITS4_MB , _NL_CTYPE_INDIGITS5_MB , _NL_CTYPE_INDIGITS6_MB , _NL_CTYPE_INDIGITS7_MB , _NL_CTYPE_INDIGITS8_MB , _NL_CTYPE_INDIGITS9_MB , _NL_CTYPE_INDIGITS_WC_LEN , _NL_CTYPE_INDIGITS0_WC , _NL_CTYPE_INDIGITS1_WC , _NL_CTYPE_INDIGITS2_WC , _NL_CTYPE_INDIGITS3_WC , _NL_CTYPE_INDIGITS4_WC , _NL_CTYPE_INDIGITS5_WC , _NL_CTYPE_INDIGITS6_WC , _NL_CTYPE_INDIGITS7_WC , _NL_CTYPE_INDIGITS8_WC , _NL_CTYPE_INDIGITS9_WC , _NL_CTYPE_OUTDIGIT0_MB , _NL_CTYPE_OUTDIGIT1_MB , _NL_CTYPE_OUTDIGIT2_MB , _NL_CTYPE_OUTDIGIT3_MB , _NL_CTYPE_OUTDIGIT4_MB , _NL_CTYPE_OUTDIGIT5_MB , _NL_CTYPE_OUTDIGIT6_MB , _NL_CTYPE_OUTDIGIT7_MB , _NL_CTYPE_OUTDIGIT8_MB , _NL_CTYPE_OUTDIGIT9_MB , _NL_CTYPE_OUTDIGIT0_WC , _NL_CTYPE_OUTDIGIT1_WC , _NL_CTYPE_OUTDIGIT2_WC , _NL_CTYPE_OUTDIGIT3_WC , _NL_CTYPE_OUTDIGIT4_WC , _NL_CTYPE_OUTDIGIT5_WC , _NL_CTYPE_OUTDIGIT6_WC , _NL_CTYPE_OUTDIGIT7_WC , _NL_CTYPE_OUTDIGIT8_WC , _NL_CTYPE_OUTDIGIT9_WC , _NL_CTYPE_TRANSLIT_TAB_SIZE , _NL_CTYPE_TRANSLIT_FROM_IDX , _NL_CTYPE_TRANSLIT_FROM_TBL , _NL_CTYPE_TRANSLIT_TO_IDX , _NL_CTYPE_TRANSLIT_TO_TBL , _NL_CTYPE_TRANSLIT_DEFAULT_MISSING_LEN , _NL_CTYPE_TRANSLIT_DEFAULT_MISSING , _NL_CTYPE_TRANSLIT_IGNORE_LEN , _NL_CTYPE_TRANSLIT_IGNORE , _NL_CTYPE_MAP_TO_NONASCII , _NL_CTYPE_EXTRA_MAP_1 , _NL_CTYPE_EXTRA_MAP_2 , _NL_CTYPE_EXTRA_MAP_3 , _NL_CTYPE_EXTRA_MAP_4 , _NL_CTYPE_EXTRA_MAP_5 , _NL_CTYPE_EXTRA_MAP_6 , _NL_CTYPE_EXTRA_MAP_7 , _NL_CTYPE_EXTRA_MAP_8 , _NL_CTYPE_EXTRA_MAP_9 , _NL_CTYPE_EXTRA_MAP_10 , _NL_CTYPE_EXTRA_MAP_11 , _NL_CTYPE_EXTRA_MAP_12 , _NL_CTYPE_EXTRA_MAP_13 , _NL_CTYPE_EXTRA_MAP_14 , _NL_NUM_LC_CTYPE , __INT_CURR_SYMBOL = (((__LC_MONETARY ) << 16 ) | (0 ) ) , __CURRENCY_SYMBOL , __MON_DECIMAL_POINT , __MON_THOUSANDS_SEP , __MON_GROUPING , __POSITIVE_SIGN , __NEGATIVE_SIGN , __INT_FRAC_DIGITS , __FRAC_DIGITS , __P_CS_PRECEDES , __P_SEP_BY_SPACE , __N_CS_PRECEDES , __N_SEP_BY_SPACE , __P_SIGN_POSN , __N_SIGN_POSN , _NL_MONETARY_CRNCYSTR , __INT_P_CS_PRECEDES , __INT_P_SEP_BY_SPACE , __INT_N_CS_PRECEDES , __INT_N_SEP_BY_SPACE , __INT_P_SIGN_POSN , __INT_N_SIGN_POSN , _NL_MONETARY_DUO_INT_CURR_SYMBOL , _NL_MONETARY_DUO_CURRENCY_SYMBOL , _NL_MONETARY_DUO_INT_FRAC_DIGITS , _NL_MONETARY_DUO_FRAC_DIGITS , _NL_MONETARY_DUO_P_CS_PRECEDES , _NL_MONETARY_DUO_P_SEP_BY_SPACE , _NL_MONETARY_DUO_N_CS_PRECEDES , _NL_MONETARY_DUO_N_SEP_BY_SPACE , _NL_MONETARY_DUO_INT_P_CS_PRECEDES , _NL_MONETARY_DUO_INT_P_SEP_BY_SPACE , _NL_MONETARY_DUO_INT_N_CS_PRECEDES , _NL_MONETARY_DUO_INT_N_SEP_BY_SPACE , _NL_MONETARY_DUO_P_SIGN_POSN , _NL_MONETARY_DUO_N_SIGN_POSN , _NL_MONETARY_DUO_INT_P_SIGN_POSN , _NL_MONETARY_DUO_INT_N_SIGN_POSN , _NL_MONETARY_UNO_VALID_FROM , _NL_MONETARY_UNO_VALID_TO , _NL_MONETARY_DUO_VALID_FROM , _NL_MONETARY_DUO_VALID_TO , _NL_MONETARY_CONVERSION_RATE , _NL_MONETARY_DECIMAL_POINT_WC , _NL_MONETARY_THOUSANDS_SEP_WC , _NL_MONETARY_CODESET , _NL_NUM_LC_MONETARY , __DECIMAL_POINT = (((__LC_NUMERIC ) << 16 ) | (0 ) ) , RADIXCHAR = __DECIMAL_POINT , __THOUSANDS_SEP , THOUSEP = __THOUSANDS_SEP , __GROUPING , _NL_NUMERIC_DECIMAL_POINT_WC , _NL_NUMERIC_THOUSANDS_SEP_WC , _NL_NUMERIC_CODESET , _NL_NUM_LC_NUMERIC , __YESEXPR = (((__LC_MESSAGES ) << 16 ) | (0 ) ) , __NOEXPR , __YESSTR , __NOSTR , _NL_MESSAGES_CODESET , _NL_NUM_LC_MESSAGES , _NL_PAPER_HEIGHT = (((__LC_PAPER ) << 16 ) | (0 ) ) , _NL_PAPER_WIDTH , _NL_PAPER_CODESET , _NL_NUM_LC_PAPER , _NL_NAME_NAME_FMT = (((__LC_NAME ) << 16 ) | (0 ) ) , _NL_NAME_NAME_GEN , _NL_NAME_NAME_MR , _NL_NAME_NAME_MRS , _NL_NAME_NAME_MISS , _NL_NAME_NAME_MS , _NL_NAME_CODESET , _NL_NUM_LC_NAME , _NL_ADDRESS_POSTAL_FMT = (((__LC_ADDRESS ) << 16 ) | (0 ) ) , _NL_ADDRESS_COUNTRY_NAME , _NL_ADDRESS_COUNTRY_POST , _NL_ADDRESS_COUNTRY_AB2 , _NL_ADDRESS_COUNTRY_AB3 , _NL_ADDRESS_COUNTRY_CAR , _NL_ADDRESS_COUNTRY_NUM , _NL_ADDRESS_COUNTRY_ISBN , _NL_ADDRESS_LANG_NAME , _NL_ADDRESS_LANG_AB , _NL_ADDRESS_LANG_TERM , _NL_ADDRESS_LANG_LIB , _NL_ADDRESS_CODESET , _NL_NUM_LC_ADDRESS , _NL_TELEPHONE_TEL_INT_FMT = (((__LC_TELEPHONE ) << 16 ) | (0 ) ) , _NL_TELEPHONE_TEL_DOM_FMT , _NL_TELEPHONE_INT_SELECT , _NL_TELEPHONE_INT_PREFIX , _NL_TELEPHONE_CODESET , _NL_NUM_LC_TELEPHONE , _NL_MEASUREMENT_MEASUREMENT = (((__LC_MEASUREMENT ) << 16 ) | (0 ) ) , _NL_MEASUREMENT_CODESET , _NL_NUM_LC_MEASUREMENT , _NL_IDENTIFICATION_TITLE = (((__LC_IDENTIFICATION ) << 16 ) | (0 ) ) , _NL_IDENTIFICATION_SOURCE , _NL_IDENTIFICATION_ADDRESS , _NL_IDENTIFICATION_CONTACT , _NL_IDENTIFICATION_EMAIL , _NL_IDENTIFICATION_TEL , _NL_IDENTIFICATION_FAX , _NL_IDENTIFICATION_LANGUAGE , _NL_IDENTIFICATION_TERRITORY , _NL_IDENTIFICATION_AUDIENCE , _NL_IDENTIFICATION_APPLICATION , _NL_IDENTIFICATION_ABBREVIATION , _NL_IDENTIFICATION_REVISION , _NL_IDENTIFICATION_DATE , _NL_IDENTIFICATION_CATEGORY , _NL_IDENTIFICATION_CODESET , _NL_NUM_LC_IDENTIFICATION , _NL_NUM }
; 
extern char * nl_langinfo (nl_item __item ) __attribute__ ((__nothrow__ ) ) ; 
typedef __mbstate_t mbstate_t ; 
struct tm ; 
extern size_t mbsrtowcs (wchar_t * __restrict __dst , __const char * * __restrict __src , size_t __len , mbstate_t * __restrict __ps ) __attribute__ ((__nothrow__ ) ) ; 
extern size_t wcsrtombs (char * __restrict __dst , __const wchar_t * * __restrict __src , size_t __len , mbstate_t * __restrict __ps ) __attribute__ ((__nothrow__ ) ) ; 
typedef unsigned long int wctype_t ; 
enum {
  __ISwupper = 0 , __ISwlower = 1 , __ISwalpha = 2 , __ISwdigit = 3 , __ISwxdigit = 4 , __ISwspace = 5 , __ISwprint = 6 , __ISwgraph = 7 , __ISwblank = 8 , __ISwcntrl = 9 , __ISwpunct = 10 , __ISwalnum = 11 , _ISwupper = ((__ISwupper ) < 8 ? (int ) ((1UL << (__ISwupper ) ) << 24 ) : ((__ISwupper ) < 16 ? (int ) ((1UL << (__ISwupper ) ) << 8 ) : ((__ISwupper ) < 24 ? (int ) ((1UL << (__ISwupper ) ) >> 8 ) : (int ) ((1UL << (__ISwupper ) ) >> 24 ) ) ) ) , _ISwlower = ((__ISwlower ) < 8 ? (int ) ((1UL << (__ISwlower ) ) << 24 ) : ((__ISwlower ) < 16 ? (int ) ((1UL << (__ISwlower ) ) << 8 ) : ((__ISwlower ) < 24 ? (int ) ((1UL << (__ISwlower ) ) >> 8 ) : (int ) ((1UL << (__ISwlower ) ) >> 24 ) ) ) ) , _ISwalpha = ((__ISwalpha ) < 8 ? (int ) ((1UL << (__ISwalpha ) ) << 24 ) : ((__ISwalpha ) < 16 ? (int ) ((1UL << (__ISwalpha ) ) << 8 ) : ((__ISwalpha ) < 24 ? (int ) ((1UL << (__ISwalpha ) ) >> 8 ) : (int ) ((1UL << (__ISwalpha ) ) >> 24 ) ) ) ) , _ISwdigit = ((__ISwdigit ) < 8 ? (int ) ((1UL << (__ISwdigit ) ) << 24 ) : ((__ISwdigit ) < 16 ? (int ) ((1UL << (__ISwdigit ) ) << 8 ) : ((__ISwdigit ) < 24 ? (int ) ((1UL << (__ISwdigit ) ) >> 8 ) : (int ) ((1UL << (__ISwdigit ) ) >> 24 ) ) ) ) , _ISwxdigit = ((__ISwxdigit ) < 8 ? (int ) ((1UL << (__ISwxdigit ) ) << 24 ) : ((__ISwxdigit ) < 16 ? (int ) ((1UL << (__ISwxdigit ) ) << 8 ) : ((__ISwxdigit ) < 24 ? (int ) ((1UL << (__ISwxdigit ) ) >> 8 ) : (int ) ((1UL << (__ISwxdigit ) ) >> 24 ) ) ) ) , _ISwspace = ((__ISwspace ) < 8 ? (int ) ((1UL << (__ISwspace ) ) << 24 ) : ((__ISwspace ) < 16 ? (int ) ((1UL << (__ISwspace ) ) << 8 ) : ((__ISwspace ) < 24 ? (int ) ((1UL << (__ISwspace ) ) >> 8 ) : (int ) ((1UL << (__ISwspace ) ) >> 24 ) ) ) ) , _ISwprint = ((__ISwprint ) < 8 ? (int ) ((1UL << (__ISwprint ) ) << 24 ) : ((__ISwprint ) < 16 ? (int ) ((1UL << (__ISwprint ) ) << 8 ) : ((__ISwprint ) < 24 ? (int ) ((1UL << (__ISwprint ) ) >> 8 ) : (int ) ((1UL << (__ISwprint ) ) >> 24 ) ) ) ) , _ISwgraph = ((__ISwgraph ) < 8 ? (int ) ((1UL << (__ISwgraph ) ) << 24 ) : ((__ISwgraph ) < 16 ? (int ) ((1UL << (__ISwgraph ) ) << 8 ) : ((__ISwgraph ) < 24 ? (int ) ((1UL << (__ISwgraph ) ) >> 8 ) : (int ) ((1UL << (__ISwgraph ) ) >> 24 ) ) ) ) , _ISwblank = ((__ISwblank ) < 8 ? (int ) ((1UL << (__ISwblank ) ) << 24 ) : ((__ISwblank ) < 16 ? (int ) ((1UL << (__ISwblank ) ) << 8 ) : ((__ISwblank ) < 24 ? (int ) ((1UL << (__ISwblank ) ) >> 8 ) : (int ) ((1UL << (__ISwblank ) ) >> 24 ) ) ) ) , _ISwcntrl = ((__ISwcntrl ) < 8 ? (int ) ((1UL << (__ISwcntrl ) ) << 24 ) : ((__ISwcntrl ) < 16 ? (int ) ((1UL << (__ISwcntrl ) ) << 8 ) : ((__ISwcntrl ) < 24 ? (int ) ((1UL << (__ISwcntrl ) ) >> 8 ) : (int ) ((1UL << (__ISwcntrl ) ) >> 24 ) ) ) ) , _ISwpunct = ((__ISwpunct ) < 8 ? (int ) ((1UL << (__ISwpunct ) ) << 24 ) : ((__ISwpunct ) < 16 ? (int ) ((1UL << (__ISwpunct ) ) << 8 ) : ((__ISwpunct ) < 24 ? (int ) ((1UL << (__ISwpunct ) ) >> 8 ) : (int ) ((1UL << (__ISwpunct ) ) >> 24 ) ) ) ) , _ISwalnum = ((__ISwalnum ) < 8 ? (int ) ((1UL << (__ISwalnum ) ) << 24 ) : ((__ISwalnum ) < 16 ? (int ) ((1UL << (__ISwalnum ) ) << 8 ) : ((__ISwalnum ) < 24 ? (int ) ((1UL << (__ISwalnum ) ) >> 8 ) : (int ) ((1UL << (__ISwalnum ) ) >> 24 ) ) ) ) }
; 
typedef __const __int32_t * wctrans_t ; 
extern wint_t towlower (wint_t __wc ) __attribute__ ((__nothrow__ ) ) ; 
extern wint_t towupper (wint_t __wc ) __attribute__ ((__nothrow__ ) ) ; 
extern int * __errno_location (void ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__const__ ) ) ; 
static int uchar_special_casings [] = {
  223 , 1 , 0 , 2 , 1 , 2 , 3 , 2 , 5 , 0 , 304 , 2 , 7 , 1 , 9 , 1 , 9 , 2 , 10 , 0 , 329 , 1 , 12 , 2 , 13 , 2 , 13 , 2 , 15 , 0 , 496 , 1 , 17 , 2 , 18 , 2 , 18 , 2 , 20 , 0 , 912 , 1 , 22 , 3 , 23 , 3 , 23 , 3 , 26 , 0 , 931 , 1 , 29 , 1 , 30 , 1 , 30 , 1 , 31 , 1 , 944 , 1 , 32 , 3 , 33 , 3 , 33 , 3 , 36 , 0 , 1415 , 1 , 39 , 2 , 40 , 2 , 42 , 2 , 44 , 0 , 7830 , 1 , 46 , 2 , 47 , 2 , 47 , 2 , 49 , 0 , 7831 , 1 , 51 , 2 , 52 , 2 , 52 , 2 , 54 , 0 , 7832 , 1 , 56 , 2 , 57 , 2 , 57 , 2 , 59 , 0 , 7833 , 1 , 61 , 2 , 62 , 2 , 62 , 2 , 64 , 0 , 7834 , 1 , 66 , 2 , 67 , 2 , 67 , 2 , 69 , 0 , 8016 , 1 , 71 , 2 , 72 , 2 , 72 , 2 , 74 , 0 , 8018 , 1 , 76 , 3 , 77 , 3 , 77 , 3 , 80 , 0 , 8020 , 1 , 83 , 3 , 84 , 3 , 84 , 3 , 87 , 0 , 8022 , 1 , 90 , 3 , 91 , 3 , 91 , 3 , 94 , 0 , 8064 , 1 , 97 , 2 , 98 , 1 , 100 , 2 , 101 , 0 , 8065 , 1 , 103 , 2 , 104 , 1 , 106 , 2 , 107 , 0 , 8066 , 1 , 109 , 2 , 110 , 1 , 112 , 2 , 113 , 0 , 8067 , 1 , 115 , 2 , 116 , 1 , 118 , 2 , 119 , 0 , 8068 , 1 , 121 , 2 , 122 , 1 , 124 , 2 , 125 , 0 , 8069 , 1 , 127 , 2 , 128 , 1 , 130 , 2 , 131 , 0 , 8070 , 1 , 133 , 2 , 134 , 1 , 136 , 2 , 137 , 0 , 8071 , 1 , 139 , 2 , 140 , 1 , 142 , 2 , 143 , 0 , 8072 , 1 , 145 , 2 , 146 , 1 , 148 , 2 , 149 , 0 , 8073 , 1 , 151 , 2 , 152 , 1 , 154 , 2 , 155 , 0 , 8074 , 1 , 157 , 2 , 158 , 1 , 160 , 2 , 161 , 0 , 8075 , 1 , 163 , 2 , 164 , 1 , 166 , 2 , 167 , 0 , 8076 , 1 , 169 , 2 , 170 , 1 , 172 , 2 , 173 , 0 , 8077 , 1 , 175 , 2 , 176 , 1 , 178 , 2 , 179 , 0 , 8078 , 1 , 181 , 2 , 182 , 1 , 184 , 2 , 185 , 0 , 8079 , 1 , 187 , 2 , 188 , 1 , 190 , 2 , 191 , 0 , 8080 , 1 , 193 , 2 , 194 , 1 , 196 , 2 , 197 , 0 , 8081 , 1 , 199 , 2 , 200 , 1 , 202 , 2 , 203 , 0 , 8082 , 1 , 205 , 2 , 206 , 1 , 208 , 2 , 209 , 0 , 8083 , 1 , 211 , 2 , 212 , 1 , 214 , 2 , 215 , 0 , 8084 , 1 , 217 , 2 , 218 , 1 , 220 , 2 , 221 , 0 , 8085 , 1 , 223 , 2 , 224 , 1 , 226 , 2 , 227 , 0 , 8086 , 1 , 229 , 2 , 230 , 1 , 232 , 2 , 233 , 0 , 8087 , 1 , 235 , 2 , 236 , 1 , 238 , 2 , 239 , 0 , 8088 , 1 , 241 , 2 , 242 , 1 , 244 , 2 , 245 , 0 , 8089 , 1 , 247 , 2 , 248 , 1 , 250 , 2 , 251 , 0 , 8090 , 1 , 253 , 2 , 254 , 1 , 256 , 2 , 257 , 0 , 8091 , 1 , 259 , 2 , 260 , 1 , 262 , 2 , 263 , 0 , 8092 , 1 , 265 , 2 , 266 , 1 , 268 , 2 , 269 , 0 , 8093 , 1 , 271 , 2 , 272 , 1 , 274 , 2 , 275 , 0 , 8094 , 1 , 277 , 2 , 278 , 1 , 280 , 2 , 281 , 0 , 8095 , 1 , 283 , 2 , 284 , 1 , 286 , 2 , 287 , 0 , 8096 , 1 , 289 , 2 , 290 , 1 , 292 , 2 , 293 , 0 , 8097 , 1 , 295 , 2 , 296 , 1 , 298 , 2 , 299 , 0 , 8098 , 1 , 301 , 2 , 302 , 1 , 304 , 2 , 305 , 0 , 8099 , 1 , 307 , 2 , 308 , 1 , 310 , 2 , 311 , 0 , 8100 , 1 , 313 , 2 , 314 , 1 , 316 , 2 , 317 , 0 , 8101 , 1 , 319 , 2 , 320 , 1 , 322 , 2 , 323 , 0 , 8102 , 1 , 325 , 2 , 326 , 1 , 328 , 2 , 329 , 0 , 8103 , 1 , 331 , 2 , 332 , 1 , 334 , 2 , 335 , 0 , 8104 , 1 , 337 , 2 , 338 , 1 , 340 , 2 , 341 , 0 , 8105 , 1 , 343 , 2 , 344 , 1 , 346 , 2 , 347 , 0 , 8106 , 1 , 349 , 2 , 350 , 1 , 352 , 2 , 353 , 0 , 8107 , 1 , 355 , 2 , 356 , 1 , 358 , 2 , 359 , 0 , 8108 , 1 , 361 , 2 , 362 , 1 , 364 , 2 , 365 , 0 , 8109 , 1 , 367 , 2 , 368 , 1 , 370 , 2 , 371 , 0 , 8110 , 1 , 373 , 2 , 374 , 1 , 376 , 2 , 377 , 0 , 8111 , 1 , 379 , 2 , 380 , 1 , 382 , 2 , 383 , 0 , 8114 , 1 , 385 , 2 , 386 , 2 , 388 , 2 , 390 , 0 , 8115 , 1 , 392 , 2 , 393 , 1 , 395 , 2 , 396 , 0 , 8116 , 1 , 398 , 2 , 399 , 2 , 401 , 2 , 403 , 0 , 8118 , 1 , 405 , 2 , 406 , 2 , 406 , 2 , 408 , 0 , 8119 , 1 , 410 , 3 , 411 , 3 , 414 , 3 , 417 , 0 , 8124 , 1 , 420 , 2 , 421 , 1 , 423 , 2 , 424 , 0 , 8130 , 1 , 426 , 2 , 427 , 2 , 429 , 2 , 431 , 0 , 8131 , 1 , 433 , 2 , 434 , 1 , 436 , 2 , 437 , 0 , 8132 , 1 , 439 , 2 , 440 , 2 , 442 , 2 , 444 , 0 , 8134 , 1 , 446 , 2 , 447 , 2 , 447 , 2 , 449 , 0 , 8135 , 1 , 451 , 3 , 452 , 3 , 455 , 3 , 458 , 0 , 8140 , 1 , 461 , 2 , 462 , 1 , 464 , 2 , 465 , 0 , 8146 , 1 , 467 , 3 , 468 , 3 , 468 , 3 , 471 , 0 , 8147 , 1 , 474 , 3 , 475 , 3 , 475 , 3 , 478 , 0 , 8150 , 1 , 481 , 2 , 482 , 2 , 482 , 2 , 484 , 0 , 8151 , 1 , 486 , 3 , 487 , 3 , 487 , 3 , 490 , 0 , 8162 , 1 , 493 , 3 , 494 , 3 , 494 , 3 , 497 , 0 , 8163 , 1 , 500 , 3 , 501 , 3 , 501 , 3 , 504 , 0 , 8164 , 1 , 507 , 2 , 508 , 2 , 508 , 2 , 510 , 0 , 8166 , 1 , 512 , 2 , 513 , 2 , 513 , 2 , 515 , 0 , 8167 , 1 , 517 , 3 , 518 , 3 , 518 , 3 , 521 , 0 , 8178 , 1 , 524 , 2 , 525 , 2 , 527 , 2 , 529 , 0 , 8179 , 1 , 531 , 2 , 532 , 1 , 534 , 2 , 535 , 0 , 8180 , 1 , 537 , 2 , 538 , 2 , 540 , 2 , 542 , 0 , 8182 , 1 , 544 , 2 , 545 , 2 , 545 , 2 , 547 , 0 , 8183 , 1 , 549 , 3 , 550 , 3 , 553 , 3 , 556 , 0 , 8188 , 1 , 559 , 2 , 560 , 1 , 562 , 2 , 563 , 0 , 64256 , 1 , 565 , 2 , 566 , 2 , 568 , 2 , 570 , 0 , 64257 , 1 , 572 , 2 , 573 , 2 , 575 , 2 , 577 , 0 , 64258 , 1 , 579 , 2 , 580 , 2 , 582 , 2 , 584 , 0 , 64259 , 1 , 586 , 3 , 587 , 3 , 590 , 3 , 593 , 0 , 64260 , 1 , 596 , 3 , 597 , 3 , 600 , 3 , 603 , 0 , 64261 , 1 , 606 , 2 , 607 , 2 , 609 , 2 , 611 , 0 , 64262 , 1 , 613 , 2 , 614 , 2 , 616 , 2 , 618 , 0 , 64275 , 1 , 620 , 2 , 621 , 2 , 623 , 2 , 625 , 0 , 64276 , 1 , 627 , 2 , 628 , 2 , 630 , 2 , 632 , 0 , 64277 , 1 , 634 , 2 , 635 , 2 , 637 , 2 , 639 , 0 , 64278 , 1 , 641 , 2 , 642 , 2 , 644 , 2 , 646 , 0 , 64279 , 1 , 648 , 2 , 649 , 2 , 651 , 2 , 653 , 0 }
; 
static int uchar_special_casing_data [] = {
  223 , 83 , 83 , 83 , 115 , 115 , 115 , 105 , 775 , 304 , 105 , 775 , 329 , 700 , 78 , 700 , 110 , 496 , 74 , 780 , 106 , 780 , 912 , 921 , 776 , 769 , 953 , 776 , 769 , 962 , 931 , 963 , 944 , 933 , 776 , 769 , 965 , 776 , 769 , 1415 , 1333 , 1362 , 1333 , 1410 , 1381 , 1410 , 7830 , 72 , 817 , 104 , 817 , 7831 , 84 , 776 , 116 , 776 , 7832 , 87 , 778 , 119 , 778 , 7833 , 89 , 778 , 121 , 778 , 7834 , 65 , 702 , 97 , 702 , 8016 , 933 , 787 , 965 , 787 , 8018 , 933 , 787 , 768 , 965 , 787 , 768 , 8020 , 933 , 787 , 769 , 965 , 787 , 769 , 8022 , 933 , 787 , 834 , 965 , 787 , 834 , 8064 , 7944 , 921 , 8072 , 7936 , 953 , 8065 , 7945 , 921 , 8073 , 7937 , 953 , 8066 , 7946 , 921 , 8074 , 7938 , 953 , 8067 , 7947 , 921 , 8075 , 7939 , 953 , 8068 , 7948 , 921 , 8076 , 7940 , 953 , 8069 , 7949 , 921 , 8077 , 7941 , 953 , 8070 , 7950 , 921 , 8078 , 7942 , 953 , 8071 , 7951 , 921 , 8079 , 7943 , 953 , 8064 , 7944 , 921 , 8072 , 7936 , 953 , 8065 , 7945 , 921 , 8073 , 7937 , 953 , 8066 , 7946 , 921 , 8074 , 7938 , 953 , 8067 , 7947 , 921 , 8075 , 7939 , 953 , 8068 , 7948 , 921 , 8076 , 7940 , 953 , 8069 , 7949 , 921 , 8077 , 7941 , 953 , 8070 , 7950 , 921 , 8078 , 7942 , 953 , 8071 , 7951 , 921 , 8079 , 7943 , 953 , 8080 , 7976 , 921 , 8088 , 7968 , 953 , 8081 , 7977 , 921 , 8089 , 7969 , 953 , 8082 , 7978 , 921 , 8090 , 7970 , 953 , 8083 , 7979 , 921 , 8091 , 7971 , 953 , 8084 , 7980 , 921 , 8092 , 7972 , 953 , 8085 , 7981 , 921 , 8093 , 7973 , 953 , 8086 , 7982 , 921 , 8094 , 7974 , 953 , 8087 , 7983 , 921 , 8095 , 7975 , 953 , 8080 , 7976 , 921 , 8088 , 7968 , 953 , 8081 , 7977 , 921 , 8089 , 7969 , 953 , 8082 , 7978 , 921 , 8090 , 7970 , 953 , 8083 , 7979 , 921 , 8091 , 7971 , 953 , 8084 , 7980 , 921 , 8092 , 7972 , 953 , 8085 , 7981 , 921 , 8093 , 7973 , 953 , 8086 , 7982 , 921 , 8094 , 7974 , 953 , 8087 , 7983 , 921 , 8095 , 7975 , 953 , 8096 , 8040 , 921 , 8104 , 8032 , 953 , 8097 , 8041 , 921 , 8105 , 8033 , 953 , 8098 , 8042 , 921 , 8106 , 8034 , 953 , 8099 , 8043 , 921 , 8107 , 8035 , 953 , 8100 , 8044 , 921 , 8108 , 8036 , 953 , 8101 , 8045 , 921 , 8109 , 8037 , 953 , 8102 , 8046 , 921 , 8110 , 8038 , 953 , 8103 , 8047 , 921 , 8111 , 8039 , 953 , 8096 , 8040 , 921 , 8104 , 8032 , 953 , 8097 , 8041 , 921 , 8105 , 8033 , 953 , 8098 , 8042 , 921 , 8106 , 8034 , 953 , 8099 , 8043 , 921 , 8107 , 8035 , 953 , 8100 , 8044 , 921 , 8108 , 8036 , 953 , 8101 , 8045 , 921 , 8109 , 8037 , 953 , 8102 , 8046 , 921 , 8110 , 8038 , 953 , 8103 , 8047 , 921 , 8111 , 8039 , 953 , 8114 , 8122 , 921 , 8122 , 837 , 8048 , 953 , 8115 , 913 , 921 , 8124 , 945 , 953 , 8116 , 902 , 921 , 902 , 837 , 940 , 953 , 8118 , 913 , 834 , 945 , 834 , 8119 , 913 , 834 , 921 , 913 , 834 , 837 , 945 , 834 , 953 , 8115 , 913 , 921 , 8124 , 945 , 953 , 8130 , 8138 , 921 , 8138 , 837 , 8052 , 953 , 8131 , 919 , 921 , 8140 , 951 , 953 , 8132 , 905 , 921 , 905 , 837 , 942 , 953 , 8134 , 919 , 834 , 951 , 834 , 8135 , 919 , 834 , 921 , 919 , 834 , 837 , 951 , 834 , 953 , 8131 , 919 , 921 , 8140 , 951 , 953 , 8146 , 921 , 776 , 768 , 953 , 776 , 768 , 8147 , 921 , 776 , 769 , 953 , 776 , 769 , 8150 , 921 , 834 , 953 , 834 , 8151 , 921 , 776 , 834 , 953 , 776 , 834 , 8162 , 933 , 776 , 768 , 965 , 776 , 768 , 8163 , 933 , 776 , 769 , 965 , 776 , 769 , 8164 , 929 , 787 , 961 , 787 , 8166 , 933 , 834 , 965 , 834 , 8167 , 933 , 776 , 834 , 965 , 776 , 834 , 8178 , 8186 , 921 , 8186 , 837 , 8060 , 953 , 8179 , 937 , 921 , 8188 , 969 , 953 , 8180 , 911 , 921 , 911 , 837 , 974 , 953 , 8182 , 937 , 834 , 969 , 834 , 8183 , 937 , 834 , 921 , 937 , 834 , 837 , 969 , 834 , 953 , 8179 , 937 , 921 , 8188 , 969 , 953 , 64256 , 70 , 70 , 70 , 102 , 102 , 102 , 64257 , 70 , 73 , 70 , 105 , 102 , 105 , 64258 , 70 , 76 , 70 , 108 , 102 , 108 , 64259 , 70 , 70 , 73 , 70 , 102 , 105 , 102 , 102 , 105 , 64260 , 70 , 70 , 76 , 70 , 102 , 108 , 102 , 102 , 108 , 64261 , 83 , 84 , 83 , 116 , 115 , 116 , 64262 , 83 , 84 , 83 , 116 , 115 , 116 , 64275 , 1348 , 1350 , 1348 , 1398 , 1396 , 1398 , 64276 , 1348 , 1333 , 1348 , 1381 , 1396 , 1381 , 64277 , 1348 , 1339 , 1348 , 1387 , 1396 , 1387 , 64278 , 1358 , 1350 , 1358 , 1398 , 1406 , 1398 , 64279 , 1348 , 1341 , 1348 , 1389 , 1396 , 1389 }
; 
static unsigned int utable_compose_pairs [] = {
  0x3c0338 , 0x3d0338 , 0x3e0338 , 0x410300 , 0x410301 , 0x410302 , 0x410303 , 0x410304 , 0x410306 , 0x410307 , 0x410308 , 0x410309 , 0x41030a , 0x41030c , 0x41030f , 0x410311 , 0x410323 , 0x410325 , 0x410328 , 0x420307 , 0x420323 , 0x420331 , 0x430301 , 0x430302 , 0x430307 , 0x43030c , 0x430327 , 0x440307 , 0x44030c , 0x440323 , 0x440327 , 0x44032d , 0x440331 , 0x450300 , 0x450301 , 0x450302 , 0x450303 , 0x450304 , 0x450306 , 0x450307 , 0x450308 , 0x450309 , 0x45030c , 0x45030f , 0x450311 , 0x450323 , 0x450327 , 0x450328 , 0x45032d , 0x450330 , 0x460307 , 0x470301 , 0x470302 , 0x470304 , 0x470306 , 0x470307 , 0x47030c , 0x470327 , 0x480302 , 0x480307 , 0x480308 , 0x48030c , 0x480323 , 0x480327 , 0x48032e , 0x490300 , 0x490301 , 0x490302 , 0x490303 , 0x490304 , 0x490306 , 0x490307 , 0x490308 , 0x490309 , 0x49030c , 0x49030f , 0x490311 , 0x490323 , 0x490328 , 0x490330 , 0x4a0302 , 0x4b0301 , 0x4b030c , 0x4b0323 , 0x4b0327 , 0x4b0331 , 0x4c0301 , 0x4c030c , 0x4c0323 , 0x4c0327 , 0x4c032d , 0x4c0331 , 0x4d0301 , 0x4d0307 , 0x4d0323 , 0x4e0300 , 0x4e0301 , 0x4e0303 , 0x4e0307 , 0x4e030c , 0x4e0323 , 0x4e0327 , 0x4e032d , 0x4e0331 , 0x4f0300 , 0x4f0301 , 0x4f0302 , 0x4f0303 , 0x4f0304 , 0x4f0306 , 0x4f0307 , 0x4f0308 , 0x4f0309 , 0x4f030b , 0x4f030c , 0x4f030f , 0x4f0311 , 0x4f031b , 0x4f0323 , 0x4f0328 , 0x500301 , 0x500307 , 0x520301 , 0x520307 , 0x52030c , 0x52030f , 0x520311 , 0x520323 , 0x520327 , 0x520331 , 0x530301 , 0x530302 , 0x530307 , 0x53030c , 0x530323 , 0x530326 , 0x530327 , 0x540307 , 0x54030c , 0x540323 , 0x540326 , 0x540327 , 0x54032d , 0x540331 , 0x550300 , 0x550301 , 0x550302 , 0x550303 , 0x550304 , 0x550306 , 0x550308 , 0x550309 , 0x55030a , 0x55030b , 0x55030c , 0x55030f , 0x550311 , 0x55031b , 0x550323 , 0x550324 , 0x550328 , 0x55032d , 0x550330 , 0x560303 , 0x560323 , 0x570300 , 0x570301 , 0x570302 , 0x570307 , 0x570308 , 0x570323 , 0x580307 , 0x580308 , 0x590300 , 0x590301 , 0x590302 , 0x590303 , 0x590304 , 0x590307 , 0x590308 , 0x590309 , 0x590323 , 0x5a0301 , 0x5a0302 , 0x5a0307 , 0x5a030c , 0x5a0323 , 0x5a0331 , 0x610300 , 0x610301 , 0x610302 , 0x610303 , 0x610304 , 0x610306 , 0x610307 , 0x610308 , 0x610309 , 0x61030a , 0x61030c , 0x61030f , 0x610311 , 0x610323 , 0x610325 , 0x610328 , 0x620307 , 0x620323 , 0x620331 , 0x630301 , 0x630302 , 0x630307 , 0x63030c , 0x630327 , 0x640307 , 0x64030c , 0x640323 , 0x640327 , 0x64032d , 0x640331 , 0x650300 , 0x650301 , 0x650302 , 0x650303 , 0x650304 , 0x650306 , 0x650307 , 0x650308 , 0x650309 , 0x65030c , 0x65030f , 0x650311 , 0x650323 , 0x650327 , 0x650328 , 0x65032d , 0x650330 , 0x660307 , 0x670301 , 0x670302 , 0x670304 , 0x670306 , 0x670307 , 0x67030c , 0x670327 , 0x680302 , 0x680307 , 0x680308 , 0x68030c , 0x680323 , 0x680327 , 0x68032e , 0x680331 , 0x690300 , 0x690301 , 0x690302 , 0x690303 , 0x690304 , 0x690306 , 0x690308 , 0x690309 , 0x69030c , 0x69030f , 0x690311 , 0x690323 , 0x690328 , 0x690330 , 0x6a0302 , 0x6a030c , 0x6b0301 , 0x6b030c , 0x6b0323 , 0x6b0327 , 0x6b0331 , 0x6c0301 , 0x6c030c , 0x6c0323 , 0x6c0327 , 0x6c032d , 0x6c0331 , 0x6d0301 , 0x6d0307 , 0x6d0323 , 0x6e0300 , 0x6e0301 , 0x6e0303 , 0x6e0307 , 0x6e030c , 0x6e0323 , 0x6e0327 , 0x6e032d , 0x6e0331 , 0x6f0300 , 0x6f0301 , 0x6f0302 , 0x6f0303 , 0x6f0304 , 0x6f0306 , 0x6f0307 , 0x6f0308 , 0x6f0309 , 0x6f030b , 0x6f030c , 0x6f030f , 0x6f0311 , 0x6f031b , 0x6f0323 , 0x6f0328 , 0x700301 , 0x700307 , 0x720301 , 0x720307 , 0x72030c , 0x72030f , 0x720311 , 0x720323 , 0x720327 , 0x720331 , 0x730301 , 0x730302 , 0x730307 , 0x73030c , 0x730323 , 0x730326 , 0x730327 , 0x740307 , 0x740308 , 0x74030c , 0x740323 , 0x740326 , 0x740327 , 0x74032d , 0x740331 , 0x750300 , 0x750301 , 0x750302 , 0x750303 , 0x750304 , 0x750306 , 0x750308 , 0x750309 , 0x75030a , 0x75030b , 0x75030c , 0x75030f , 0x750311 , 0x75031b , 0x750323 , 0x750324 , 0x750328 , 0x75032d , 0x750330 , 0x760303 , 0x760323 , 0x770300 , 0x770301 , 0x770302 , 0x770307 , 0x770308 , 0x77030a , 0x770323 , 0x780307 , 0x780308 , 0x790300 , 0x790301 , 0x790302 , 0x790303 , 0x790304 , 0x790307 , 0x790308 , 0x790309 , 0x79030a , 0x790323 , 0x7a0301 , 0x7a0302 , 0x7a0307 , 0x7a030c , 0x7a0323 , 0x7a0331 , 0xa80300 , 0xa80301 , 0xa80342 , 0xc20300 , 0xc20301 , 0xc20303 , 0xc20309 , 0xc40304 , 0xc50301 , 0xc60301 , 0xc60304 , 0xc70301 , 0xca0300 , 0xca0301 , 0xca0303 , 0xca0309 , 0xcf0301 , 0xd40300 , 0xd40301 , 0xd40303 , 0xd40309 , 0xd50301 , 0xd50304 , 0xd50308 , 0xd60304 , 0xd80301 , 0xdc0300 , 0xdc0301 , 0xdc0304 , 0xdc030c , 0xe20300 , 0xe20301 , 0xe20303 , 0xe20309 , 0xe40304 , 0xe50301 , 0xe60301 , 0xe60304 , 0xe70301 , 0xea0300 , 0xea0301 , 0xea0303 , 0xea0309 , 0xef0301 , 0xf40300 , 0xf40301 , 0xf40303 , 0xf40309 , 0xf50301 , 0xf50304 , 0xf50308 , 0xf60304 , 0xf80301 , 0xfc0300 , 0xfc0301 , 0xfc0304 , 0xfc030c , 0x1020300 , 0x1020301 , 0x1020303 , 0x1020309 , 0x1030300 , 0x1030301 , 0x1030303 , 0x1030309 , 0x1120300 , 0x1120301 , 0x1130300 , 0x1130301 , 0x14c0300 , 0x14c0301 , 0x14d0300 , 0x14d0301 , 0x15a0307 , 0x15b0307 , 0x1600307 , 0x1610307 , 0x1680301 , 0x1690301 , 0x16a0308 , 0x16b0308 , 0x17f0307 , 0x1a00300 , 0x1a00301 , 0x1a00303 , 0x1a00309 , 0x1a00323 , 0x1a10300 , 0x1a10301 , 0x1a10303 , 0x1a10309 , 0x1a10323 , 0x1af0300 , 0x1af0301 , 0x1af0303 , 0x1af0309 , 0x1af0323 , 0x1b00300 , 0x1b00301 , 0x1b00303 , 0x1b00309 , 0x1b00323 , 0x1b7030c , 0x1ea0304 , 0x1eb0304 , 0x2260304 , 0x2270304 , 0x2280306 , 0x2290306 , 0x22e0304 , 0x22f0304 , 0x292030c , 0x3910300 , 0x3910301 , 0x3910304 , 0x3910306 , 0x3910313 , 0x3910314 , 0x3910345 , 0x3950300 , 0x3950301 , 0x3950313 , 0x3950314 , 0x3970300 , 0x3970301 , 0x3970313 , 0x3970314 , 0x3970345 , 0x3990300 , 0x3990301 , 0x3990304 , 0x3990306 , 0x3990308 , 0x3990313 , 0x3990314 , 0x39f0300 , 0x39f0301 , 0x39f0313 , 0x39f0314 , 0x3a10314 , 0x3a50300 , 0x3a50301 , 0x3a50304 , 0x3a50306 , 0x3a50308 , 0x3a50314 , 0x3a90300 , 0x3a90301 , 0x3a90313 , 0x3a90314 , 0x3a90345 , 0x3ac0345 , 0x3ae0345 , 0x3b10300 , 0x3b10301 , 0x3b10304 , 0x3b10306 , 0x3b10313 , 0x3b10314 , 0x3b10342 , 0x3b10345 , 0x3b50300 , 0x3b50301 , 0x3b50313 , 0x3b50314 , 0x3b70300 , 0x3b70301 , 0x3b70313 , 0x3b70314 , 0x3b70342 , 0x3b70345 , 0x3b90300 , 0x3b90301 , 0x3b90304 , 0x3b90306 , 0x3b90308 , 0x3b90313 , 0x3b90314 , 0x3b90342 , 0x3bf0300 , 0x3bf0301 , 0x3bf0313 , 0x3bf0314 , 0x3c10313 , 0x3c10314 , 0x3c50300 , 0x3c50301 , 0x3c50304 , 0x3c50306 , 0x3c50308 , 0x3c50313 , 0x3c50314 , 0x3c50342 , 0x3c90300 , 0x3c90301 , 0x3c90313 , 0x3c90314 , 0x3c90342 , 0x3c90345 , 0x3ca0300 , 0x3ca0301 , 0x3ca0342 , 0x3cb0300 , 0x3cb0301 , 0x3cb0342 , 0x3ce0345 , 0x3d20301 , 0x3d20308 , 0x4060308 , 0x4100306 , 0x4100308 , 0x4130301 , 0x4150300 , 0x4150306 , 0x4150308 , 0x4160306 , 0x4160308 , 0x4170308 , 0x4180300 , 0x4180304 , 0x4180306 , 0x4180308 , 0x41a0301 , 0x41e0308 , 0x4230304 , 0x4230306 , 0x4230308 , 0x423030b , 0x4270308 , 0x42b0308 , 0x42d0308 , 0x4300306 , 0x4300308 , 0x4330301 , 0x4350300 , 0x4350306 , 0x4350308 , 0x4360306 , 0x4360308 , 0x4370308 , 0x4380300 , 0x4380304 , 0x4380306 , 0x4380308 , 0x43a0301 , 0x43e0308 , 0x4430304 , 0x4430306 , 0x4430308 , 0x443030b , 0x4470308 , 0x44b0308 , 0x44d0308 , 0x4560308 , 0x474030f , 0x475030f , 0x4d80308 , 0x4d90308 , 0x4e80308 , 0x4e90308 , 0x6270653 , 0x6270654 , 0x6270655 , 0x6480654 , 0x64a0654 , 0x6c10654 , 0x6d20654 , 0x6d50654 , 0x928093c , 0x930093c , 0x933093c , 0x9c709be , 0x9c709d7 , 0xb470b3e , 0xb470b56 , 0xb470b57 , 0xb920bd7 , 0xbc60bbe , 0xbc60bd7 , 0xbc70bbe , 0xc460c56 , 0xcbf0cd5 , 0xcc60cc2 , 0xcc60cd5 , 0xcc60cd6 , 0xcca0cd5 , 0xd460d3e , 0xd460d57 , 0xd470d3e , 0xdd90dca , 0xdd90dcf , 0xdd90ddf , 0xddc0dca , 0x1025102e , 0x1e360304 , 0x1e370304 , 0x1e5a0304 , 0x1e5b0304 , 0x1e620307 , 0x1e630307 , 0x1ea00302 , 0x1ea00306 , 0x1ea10302 , 0x1ea10306 , 0x1eb80302 , 0x1eb90302 , 0x1ecc0302 , 0x1ecd0302 , 0x1f000300 , 0x1f000301 , 0x1f000342 , 0x1f000345 , 0x1f010300 , 0x1f010301 , 0x1f010342 , 0x1f010345 , 0x1f020345 , 0x1f030345 , 0x1f040345 , 0x1f050345 , 0x1f060345 , 0x1f070345 , 0x1f080300 , 0x1f080301 , 0x1f080342 , 0x1f080345 , 0x1f090300 , 0x1f090301 , 0x1f090342 , 0x1f090345 , 0x1f0a0345 , 0x1f0b0345 , 0x1f0c0345 , 0x1f0d0345 , 0x1f0e0345 , 0x1f0f0345 , 0x1f100300 , 0x1f100301 , 0x1f110300 , 0x1f110301 , 0x1f180300 , 0x1f180301 , 0x1f190300 , 0x1f190301 , 0x1f200300 , 0x1f200301 , 0x1f200342 , 0x1f200345 , 0x1f210300 , 0x1f210301 , 0x1f210342 , 0x1f210345 , 0x1f220345 , 0x1f230345 , 0x1f240345 , 0x1f250345 , 0x1f260345 , 0x1f270345 , 0x1f280300 , 0x1f280301 , 0x1f280342 , 0x1f280345 , 0x1f290300 , 0x1f290301 , 0x1f290342 , 0x1f290345 , 0x1f2a0345 , 0x1f2b0345 , 0x1f2c0345 , 0x1f2d0345 , 0x1f2e0345 , 0x1f2f0345 , 0x1f300300 , 0x1f300301 , 0x1f300342 , 0x1f310300 , 0x1f310301 , 0x1f310342 , 0x1f380300 , 0x1f380301 , 0x1f380342 , 0x1f390300 , 0x1f390301 , 0x1f390342 , 0x1f400300 , 0x1f400301 , 0x1f410300 , 0x1f410301 , 0x1f480300 , 0x1f480301 , 0x1f490300 , 0x1f490301 , 0x1f500300 , 0x1f500301 , 0x1f500342 , 0x1f510300 , 0x1f510301 , 0x1f510342 , 0x1f590300 , 0x1f590301 , 0x1f590342 , 0x1f600300 , 0x1f600301 , 0x1f600342 , 0x1f600345 , 0x1f610300 , 0x1f610301 , 0x1f610342 , 0x1f610345 , 0x1f620345 , 0x1f630345 , 0x1f640345 , 0x1f650345 , 0x1f660345 , 0x1f670345 , 0x1f680300 , 0x1f680301 , 0x1f680342 , 0x1f680345 , 0x1f690300 , 0x1f690301 , 0x1f690342 , 0x1f690345 , 0x1f6a0345 , 0x1f6b0345 , 0x1f6c0345 , 0x1f6d0345 , 0x1f6e0345 , 0x1f6f0345 , 0x1f700345 , 0x1f740345 , 0x1f7c0345 , 0x1fb60345 , 0x1fbf0300 , 0x1fbf0301 , 0x1fbf0342 , 0x1fc60345 , 0x1ff60345 , 0x1ffe0300 , 0x1ffe0301 , 0x1ffe0342 , 0x21900338 , 0x21920338 , 0x21940338 , 0x21d00338 , 0x21d20338 , 0x21d40338 , 0x22030338 , 0x22080338 , 0x220b0338 , 0x22230338 , 0x22250338 , 0x223c0338 , 0x22430338 , 0x22450338 , 0x22480338 , 0x224d0338 , 0x22610338 , 0x22640338 , 0x22650338 , 0x22720338 , 0x22730338 , 0x22760338 , 0x22770338 , 0x227a0338 , 0x227b0338 , 0x227c0338 , 0x227d0338 , 0x22820338 , 0x22830338 , 0x22860338 , 0x22870338 , 0x22910338 , 0x22920338 , 0x22a20338 , 0x22a80338 , 0x22a90338 , 0x22ab0338 , 0x22b20338 , 0x22b30338 , 0x22b40338 , 0x22b50338 , 0x30463099 , 0x304b3099 , 0x304d3099 , 0x304f3099 , 0x30513099 , 0x30533099 , 0x30553099 , 0x30573099 , 0x30593099 , 0x305b3099 , 0x305d3099 , 0x305f3099 , 0x30613099 , 0x30643099 , 0x30663099 , 0x30683099 , 0x306f3099 , 0x306f309a , 0x30723099 , 0x3072309a , 0x30753099 , 0x3075309a , 0x30783099 , 0x3078309a , 0x307b3099 , 0x307b309a , 0x309d3099 , 0x30a63099 , 0x30ab3099 , 0x30ad3099 , 0x30af3099 , 0x30b13099 , 0x30b33099 , 0x30b53099 , 0x30b73099 , 0x30b93099 , 0x30bb3099 , 0x30bd3099 , 0x30bf3099 , 0x30c13099 , 0x30c43099 , 0x30c63099 , 0x30c83099 , 0x30cf3099 , 0x30cf309a , 0x30d23099 , 0x30d2309a , 0x30d53099 , 0x30d5309a , 0x30d83099 , 0x30d8309a , 0x30db3099 , 0x30db309a , 0x30ef3099 , 0x30f03099 , 0x30f13099 , 0x30f23099 , 0x30fd3099 , 0xb40000 , 0x38f0000 , 0x38c0000 , 0x600000 , 0x38e0000 , 0x3b00000 , 0x38a0000 , 0x3900000 , 0x3890000 , 0x3880000 , 0x3b90000 , 0x3860000 , 0x3ce0000 , 0x3cd0000 , 0x3cc0000 , 0x3af0000 , 0x3ae0000 , 0x3ad0000 , 0x3ac0000 , 0x5e405bf , 0x5d105bf , 0x5ea05bc , 0x5e805bc , 0x5e605bc , 0x5e405bc , 0x5e305bc , 0x5e005bc , 0x5de05bc , 0x5dc05bc , 0x5db05bc , 0x5d905bc , 0x5d605bc , 0x5d505bc , 0x5d305bc , 0x5d105bc , 0x5d005b8 , 0xfb4905c2 , 0x5e905c2 , 0x5f205b7 , 0x5d905b4 , 0x9f8e0000 , 0x40180000 , 0x9b120000 , 0x980b0000 , 0x97db0000 , 0x96e30000 , 0x92760000 , 0x90720000 , 0x8d080000 , 0x8b390000 , 0x8afe0000 , 0x8acb0000 , 0x8abf0000 , 0x89860000 , 0x87790000 , 0x83520000 , 0x7f3e0000 , 0x7d5b0000 , 0x7bc00000 , 0x78cc0000 , 0x774a0000 , 0x76db0000 , 0x761f0000 , 0x753b0000 , 0x74710000 , 0x72af0000 , 0x77a70000 , 0x701e0000 , 0x6ecb0000 , 0x6d410000 , 0x6b790000 , 0x671b0000 , 0x66740000 , 0x64520000 , 0x63c40000 , 0x61f20000 , 0x618e0000 , 0x614e0000 , 0x5fad0000 , 0x5ed90000 , 0x5b280000 , 0x59540000 , 0x58b30000 , 0x55e20000 , 0x55550000 , 0x52fa0000 , 0x51800000 , 0x4f800000 , 0x51b50000 , 0x983b0000 , 0x97ff0000 , 0x90380000 , 0x8d080000 , 0x8b390000 , 0x89960000 , 0x84570000 , 0x82790000 , 0x80050000 , 0x7e410000 , 0x7df40000 , 0x7a810000 , 0x798e0000 , 0x795d0000 , 0x79500000 , 0x79490000 , 0x78910000 , 0x722b0000 , 0x6e1a0000 , 0x6d770000 , 0x66910000 , 0x654f0000 , 0x618e0000 , 0x60940000 , 0x58a80000 , 0x58400000 , 0x56060000 , 0x53510000 , 0x52c90000 , 0x50e70000 , 0x9db40000 , 0x98ef0000 , 0x90fd0000 , 0x90380000 , 0x8af80000 , 0x86120000 , 0x7fbd0000 , 0x7cbe0000 , 0x798f0000 , 0x795e0000 , 0x76ca0000 , 0x51de0000 , 0x66740000 , 0x585a0000 , 0x4ced0000 , 0x55c00000 , 0x5ed30000 , 0x964d0000 , 0x8f3b0000 , 0x6d1e0000 , 0x7cd60000 , 0x5ea60000 , 0x83360000 , 0x4ec00000 , 0x70990000 , 0x7c920000 , 0x7acb0000 , 0x6dcb0000 , 0x9e9f0000 , 0x96a30000 , 0x71d00000 , 0x541d0000 , 0x533f0000 , 0x91cc0000 , 0x88cf0000 , 0x75e20000 , 0x6ce50000 , 0x674e0000 , 0x5c650000 , 0x52290000 , 0x73870000 , 0x61440000 , 0x6dea0000 , 0x5d190000 , 0x96780000 , 0x516d0000 , 0x7d100000 , 0x75590000 , 0x6d410000 , 0x677b0000 , 0x52890000 , 0x66880000 , 0x907c0000 , 0x76420000 , 0x6a020000 , 0x5c3f0000 , 0x50da0000 , 0x60e10000 , 0x91b40000 , 0x4f8b0000 , 0x97480000 , 0x92340000 , 0x7f9a0000 , 0x73b20000 , 0x5dba0000 , 0x56f90000 , 0x73750000 , 0x6bae0000 , 0x5ff50000 , 0x8aaa0000 , 0x70c80000 , 0x52a30000 , 0x934a0000 , 0x84ee0000 , 0x806f0000 , 0x79ca0000 , 0x71490000 , 0x649a0000 , 0x61900000 , 0x8f620000 , 0x66c60000 , 0x9ece0000 , 0x9a6a0000 , 0x792a0000 , 0x65c50000 , 0x59730000 , 0x52f50000 , 0x826f0000 , 0x7ce70000 , 0x51c90000 , 0x4eae0000 , 0x63a00000 , 0x62fe0000 , 0x6bba0000 , 0x84490000 , 0x77010000 , 0x53c30000 , 0x6ccc0000 , 0x4e0d0000 , 0x4fbf0000 , 0x53170000 , 0x60120000 , 0x4e390000 , 0x6a020000 , 0x8b800000 , 0x83f10000 , 0x7dbe0000 , 0x51cc0000 , 0x808b0000 , 0x964b0000 , 0x7d2f0000 , 0x6dda0000 , 0x5c620000 , 0x96f70000 , 0x78ca0000 , 0x807e0000 , 0x5f040000 , 0x9e7f0000 , 0x83c90000 , 0x797f0000 , 0x788c0000 , 0x97320000 , 0x865c0000 , 0x80010000 , 0x76e70000 , 0x6ad30000 , 0x51b70000 , 0x4f860000 , 0x72fc0000 , 0x67170000 , 0x81d80000 , 0x89640000 , 0x6feb0000 , 0x9e1e0000 , 0x862d0000 , 0x6b040000 , 0x4e820000 , 0x916a0000 , 0x73de0000 , 0x6d1b0000 , 0x908f0000 , 0x87ba0000 , 0x7f850000 , 0x61f60000 , 0x55870000 , 0x59510000 , 0x9f9c0000 , 0x4e320000 , 0x8eca0000 , 0x8c480000 , 0x6c670000 , 0x6cbf0000 , 0x6c4e0000 , 0x6bbb0000 , 0x6b9f0000 , 0x5db05bf , 0x5d505b9 , 0x5e905bc , 0x69ea0000 , 0x5e705bc , 0x69140000 , 0x688e0000 , 0x5e105bc , 0x67850000 , 0x3b490000 , 0x67530000 , 0x67210000 , 0x5da05bc , 0x5d805bc , 0x67000000 , 0x51920000 , 0x3b080000 , 0x5d405bc , 0x5d205bc , 0x5d005bc , 0x654f0000 , 0x64770000 , 0x5d005b7 , 0xfb4905c1 , 0x5e905c1 , 0x63830000 , 0x62fc0000 , 0x62d40000 , 0x625d0000 , 0x62100000 , 0x61f20000 , 0x61af0000 , 0x61b20000 , 0x617a0000 , 0x614e0000 , 0x61480000 , 0x391c0000 , 0x60810000 , 0x5fd70000 , 0x5f9a0000 , 0x5f6b0000 , 0x38c70000 , 0x5f220000 , 0x5efe0000 , 0x5eca0000 , 0x5eb30000 , 0x387c0000 , 0x38620000 , 0x5e3d0000 , 0x5dfd0000 , 0x5de20000 , 0x5d7c0000 , 0x5d6e0000 , 0x5d430000 , 0x5c8d0000 , 0x5c6e0000 , 0x37810000 , 0x5f530000 , 0x5bff0000 , 0x5bf30000 , 0x5bd80000 , 0x5b3e0000 , 0x36fc0000 , 0x5a660000 , 0x5a270000 , 0x59ec0000 , 0x59220000 , 0x59060000 , 0x58f20000 , 0x58ac0000 , 0x58320000 , 0x580d0000 , 0x57ce0000 , 0x52070000 , 0x56510000 , 0x56060000 , 0x55c20000 , 0x55ab0000 , 0x9f430000 , 0x55630000 , 0x55100000 , 0x40390000 , 0x3b9d0000 , 0x53ca0000 , 0x9f9c0000 , 0x983b0000 , 0x97ff0000 , 0x97560000 , 0x53490000 , 0x53060000 , 0x967c0000 , 0x91990000 , 0x8f380000 , 0x8b8a0000 , 0x523b0000 , 0x52030000 , 0x8aed0000 , 0x8b010000 , 0x8af80000 , 0x89960000 , 0x51670000 , 0x89410000 , 0x83ef0000 , 0x80050000 , 0x7df40000 , 0x507a0000 , 0x4fbb0000 , 0x7c7b0000 , 0x7ab10000 , 0x77400000 , 0x76f40000 , 0x76ca0000 , 0x761d0000 , 0x75060000 , 0x732a0000 , 0x72350000 , 0x716e0000 , 0x6f220000 , 0x6edb0000 , 0x6bba0000 , 0x67560000 , 0x67170000 , 0x65560000 , 0x641c0000 , 0x62340000 , 0x61600000 , 0x61080000 , 0x60d80000 , 0x5f690000 , 0x5ed20000 , 0x5a620000 , 0x59440000 , 0x585a0000 , 0x55990000 , 0x559d0000 , 0x52c70000 , 0x51450000 , 0x51680000 , 0x4e260000 , 0x96e30000 , 0x8fb60000 , 0x8cd30000 , 0x8b010000 , 0x89100000 , 0x82790000 , 0x81ed0000 , 0x7f720000 , 0x7e090000 , 0x7bc00000 , 0x7a400000 , 0x798d0000 , 0x79560000 , 0x79480000 , 0x793e0000 , 0x74220000 , 0x716e0000 , 0x6f220000 , 0x68850000 , 0x65e20000 , 0x61f20000 , 0x61680000 , 0x5c6e0000 , 0x5c640000 , 0x56680000 , 0x559d0000 , 0x52e40000 , 0x514d0000 , 0x4fae0000 , 0x99280000 , 0x98fc0000 , 0xfb30f80 , 0xf710f74 , 0x97560000 , 0x79650000 , 0x793c0000 , 0x732a0000 , 0x9d670000 , 0x51400000 , 0x898b0000 , 0x884c0000 , 0x66b40000 , 0x5b850000 , 0x62d30000 , 0x52070000 , 0x523a0000 , 0x8b580000 , 0x72c00000 , 0x7b200000 , 0x81e80000 , 0x67970000 , 0x9c570000 , 0x85fa0000 , 0x74980000 , 0x6eba0000 , 0x96e20000 , 0x88e10000 , 0x7f790000 , 0x74060000 , 0x68a80000 , 0x66130000 , 0x540f0000 , 0x96860000 , 0x68170000 , 0x5f8b0000 , 0x8f2a0000 , 0x502b0000 , 0x622e0000 , 0x985e0000 , 0x786b0000 , 0x74090000 , 0x6e9c0000 , 0x67f30000 , 0x962e0000 , 0x9f8d0000 , 0x84fc0000 , 0x71ce0000 , 0x65990000 , 0x5bee0000 , 0x4e860000 , 0x96b80000 , 0x79ae0000 , 0x98180000 , 0x96f60000 , 0x80460000 , 0x74690000 , 0x601c0000 , 0x5be70000 , 0x4ee40000 , 0x7c3e0000 , 0x637b0000 , 0x5ec90000 , 0x88c20000 , 0x54bd0000 , 0x52170000 , 0x90230000 , 0x8f260000 , 0x7df40000 , 0x74890000 , 0x6f230000 , 0x62000000 , 0x5e740000 , 0x6b770000 , 0x529b0000 , 0x9e970000 , 0x95ad0000 , 0x6ffe0000 , 0x5eec0000 , 0x54420000 , 0x91cf0000 , 0x8ad20000 , 0x68810000 , 0x51690000 , 0x75650000 , 0x82e50000 , 0x6c880000 , 0x8fb00000 , 0x8aaa0000 , 0x585e0000 , 0x7d220000 , 0x65780000 , 0x5fa90000 , 0x78fb0000 , 0x75700000 , 0x73870000 , 0x5be70000 , 0x8afe0000 , 0x62cf0000 , 0x96750000 , 0x7a1c0000 , 0x51dc0000 , 0x52d20000 , 0x7e370000 , 0x6f0f0000 , 0x6a130000 , 0x58d80000 , 0x8cc20000 , 0x72620000 , 0x7c600000 , 0x58df0000 , 0x8ad60000 , 0x93040000 , 0x7da00000 , 0x9dfa0000 , 0x9b6f0000 , 0x8def0000 , 0x86060000 , 0x72100000 , 0x64c40000 , 0x52de0000 , 0x90ce0000 , 0x6d6a0000 , 0x5eca0000 , 0x881f0000 , 0x62c90000 , 0x85cd0000 , 0x5d500000 , 0x721b0000 , 0x53750000 , 0x99f10000 , 0x843d0000 , 0x70d90000 , 0x6a020000 , 0x88f80000 , 0x863f0000 , 0x76690000 , 0x59480000 , 0x91d10000 , 0x9f9c0000 , 0x53e50000 , 0x6ed10000 , 0x8cc80000 , 0x66f40000 , 0x6d160000 , 0x6ccd0000 , 0x6bba0000 , 0x3c4e0000 , 0x3c180000 , 0x6adb0000 , 0x6aa80000 , 0x69420000 , 0x3b9d0000 , 0x681f0000 , 0x68850000 , 0x68520000 , 0x67fa0000 , 0x675e0000 , 0x67170000 , 0x80ad0000 , 0x669c0000 , 0x51950000 , 0x3ae40000 , 0x3b190000 , 0x66f80000 , 0x656c0000 , 0x3a6c0000 , 0x647e0000 , 0x3a2e0000 , 0x63c50000 , 0x64220000 , 0x63e40000 , 0x63680000 , 0x633d0000 , 0x63500000 , 0x62b10000 , 0x621b0000 , 0x61f60000 , 0x61de0000 , 0x61a40000 , 0x618e0000 , 0x614c0000 , 0x614c0000 , 0x60c70000 , 0x60940000 , 0x393a0000 , 0x5ff90000 , 0x5fcd0000 , 0x38e30000 , 0x5f620000 , 0x5f220000 , 0x82010000 , 0x5eb60000 , 0x5eb00000 , 0x5e690000 , 0x5e280000 , 0x382f0000 , 0x5de10000 , 0x30080000 , 0x5d6b0000 , 0x5cc00000 , 0x5c600000 , 0x5c220000 , 0x5c060000 , 0x5be70000 , 0x5bc30000 , 0x5b3e0000 , 0x5b080000 , 0x36ee0000 , 0x59d80000 , 0x5a1b0000 , 0x59620000 , 0x591a0000 , 0x58f70000 , 0x578b0000 , 0x57f40000 , 0x58ee0000 , 0x56740000 , 0x57170000 , 0x57160000 , 0x55b30000 , 0x55840000 , 0x55840000 , 0x55530000 , 0x54480000 , 0x549e0000 , 0x53f10000 , 0x53eb0000 , 0x53df0000 , 0x537f0000 , 0x537d0000 , 0x535a0000 , 0x53510000 , 0x53170000 , 0x52fa0000 , 0x52c90000 , 0x35150000 , 0x52720000 , 0x52460000 , 0x34df0000 , 0x51ac0000 , 0x51a40000 , 0x4cf80000 , 0x518d0000 , 0x34b90000 , 0x51640000 , 0x9cfd0000 , 0x9b120000 , 0x514d0000 , 0x349e0000 , 0x50e70000 , 0x50990000 , 0x99c20000 , 0x50020000 , 0x4f600000 , 0x980b0000 , 0x4ab20000 , 0x97e00000 , 0x4a6e0000 , 0x5db20000 , 0x49e60000 , 0x95b70000 , 0x958b0000 , 0x94150000 , 0x927c0000 , 0x92d70000 , 0x911b0000 , 0x91110000 , 0x8ed40000 , 0x8df00000 , 0x8cab0000 , 0x8c550000 , 0x46c70000 , 0x34bb0000 , 0x88d70000 , 0x88630000 , 0x45f90000 , 0x87e10000 , 0x87860000 , 0x87280000 , 0x86e20000 , 0x86880000 , 0x86690000 , 0x865c0000 , 0x456b0000 , 0x455d0000 , 0x85640000 , 0x85160000 , 0x84f10000 , 0x83cc0000 , 0x83530000 , 0x83e70000 , 0x82e50000 , 0x82e60000 , 0x82b30000 , 0x52b30000 , 0x828b0000 , 0x446b0000 , 0x82040000 , 0x5ab50000 , 0x440b0000 , 0x80050000 , 0x7f950000 , 0x7f7a0000 , 0x43590000 , 0x7e450000 , 0x7dc70000 , 0x7d630000 , 0x7d000000 , 0x7ce80000 , 0x7cd20000 , 0x42270000 , 0x7bc60000 , 0x42020000 , 0x7a4a0000 , 0x798f0000 , 0x78cc0000 , 0x784e0000 , 0x40960000 , 0x778b0000 , 0x774a0000 , 0x771f0000 , 0x3ffc0000 , 0x76100000 , 0x75700000 , 0x753e0000 , 0x74ca0000 , 0x74710000 , 0x74470000 , 0x3eb80000 , 0x3eac0000 , 0x737a0000 , 0x72800000 , 0x72500000 , 0x72280000 , 0x719c0000 , 0x71450000 , 0x70ad0000 , 0x707d0000 , 0x3d960000 , 0x701e0000 , 0x6fc60000 , 0x6df90000 , 0x6ec70000 , 0x3d330000 , 0x6e2f0000 , 0x6d780000 , 0x6d410000 , 0x6d3e0000 , 0x6b720000 , 0x6b540000 , 0x6b210000 , 0x69a30000 , 0x4b0000 , 0x3a90000 , 0x671b0000 , 0x43d90000 , 0x66910000 , 0x66490000 , 0x65e30000 , 0x649d0000 , 0x64690000 , 0x63a90000 , 0x9f3b0000 , 0x9f0f0000 , 0x9efe0000 , 0x4d560000 , 0x9ebb0000 , 0x4cce0000 , 0x9c400000 , 0x4bce0000 , 0x99fe0000 , 0xb210b3c , 0x98e20000 , 0x98290000 , 0x4a760000 , 0x97230000 , 0x96c30000 , 0x93f90000 , 0x92d80000 , 0x58310000 , 0x8f380000 , 0x8dcb0000 , 0x8cc10000 , 0x8aed0000 , 0x55990000 , 0x54a20000 , 0x8aa00000 , 0x46be0000 , 0x88de0000 , 0x52e40000 , 0x52c70000 , 0x52770000 , 0x86a90000 , 0x86670000 , 0x86500000 , 0x51f50000 , 0x51b50000 , 0x4ecc0000 , 0x45610000 , 0x51970000 , 0x51770000 , 0x452b0000 , 0x51540000 , 0x50cf0000 , 0x4fae0000 , 0x4e410000 , 0x4e3d0000 , 0x20030000 , 0x82bd0000 , 0x829d0000 , 0x3850000 , 0x82010000 , 0x813e0000 , 0xf900fb5 , 0x80600000 , 0xfab0fb7 , 0xfa60fb7 , 0xfa10fb7 , 0x43340000 , 0xf9c0fb7 , 0xf920fb7 , 0x43010000 , 0xa170a3c , 0xf710f80 , 0x42a00000 , 0xfb20f80 , 0xf710f72 , 0xf400fb5 , 0x7a4f0000 , 0x412f0000 , 0xf5b0fb7 , 0xf560fb7 , 0xf510fb7 , 0xf4c0fb7 , 0xf420fb7 , 0x788c0000 , 0x40460000 , 0x76f40000 , 0x75240000 , 0x73a50000 , 0x738b0000 , 0x9a209bc , 0x70390000 , 0x6f6e0000 , 0x6d340000 , 0x6d850000 , 0x9f050000 , 0x92f093c , 0x921093c , 0x91c093c , 0x915093c , 0x8b8a0000 , 0x46350000 , 0x88010000 , 0x870e0000 , 0x84f30000 , 0x83dc0000 , 0x83ca0000 , 0x84570000 , 0x83230000 , 0x83630000 , 0x831d0000 , 0x82b10000 , 0x54f60000 , 0x8f9e0000 , 0x54680000 , 0x54380000 , 0x54060000 , 0x80b20000 , 0x43d50000 , 0x70700000 , 0x537f0000 , 0x537f0000 , 0x80700000 , 0x53730000 , 0x53050000 , 0x7ce30000 , 0x7bc90000 , 0x7aee0000 , 0x7a400000 , 0x4e380000 , 0x79eb0000 , 0x79560000 , 0x40e30000 , 0x40390000 , 0x771f0000 , 0x40080000 , 0x3f1b0000 , 0x74850000 , 0x745c0000 , 0x3eb80000 , 0x72950000 , 0x9f160000 , 0xb220b3c , 0x70770000 , 0x704a0000 , 0x701b0000 , 0x6ecb0000 , 0x6e6e0000 , 0x99290000 , 0x4b330000 , 0x6d690000 , 0x6d770000 , 0x980b0000 , 0x2add0338 , 0x49950000 , 0x92380000 , 0x90940000 , 0x8dbc0000 , 0x8d1b0000 , 0xa2b0a3c , 0xa1c0a3c , 0xa160a3c , 0x88fa0000 , 0xa380a3c , 0xa320a3c , 0x88600000 , 0x45d70000 , 0x876b0000 , 0x87790000 , 0x9af09bc , 0x9a109bc , 0x83bd0000 , 0x83ad0000 , 0x82910000 , 0x92b093c , 0x922093c , 0x917093c , 0x916093c , 0x81030000 , 0x7ffa0000 , 0x7e020000 , 0x771e0000 , 0x9ef90000 , 0x99a70000 , 0x72350000 , 0x90f10000 , 0x8d770000 , 0x3010000 , 0xb70000 , 0x3b0000 , 0x2b90000 , 0x3080301 , 0x3130000 , 0x3000000 , 0x30090000 , 0xc50000 , 0x20020000 }
; 
static unsigned int utable_compose_result [] = {
  0x226e , 0x2260 , 0x226f , 0xc0 , 0xc1 , 0xc2 , 0xc3 , 0x100 , 0x102 , 0x226 , 0xc4 , 0x1ea2 , 0xc5 , 0x1cd , 0x200 , 0x202 , 0x1ea0 , 0x1e00 , 0x104 , 0x1e02 , 0x1e04 , 0x1e06 , 0x106 , 0x108 , 0x10a , 0x10c , 0xc7 , 0x1e0a , 0x10e , 0x1e0c , 0x1e10 , 0x1e12 , 0x1e0e , 0xc8 , 0xc9 , 0xca , 0x1ebc , 0x112 , 0x114 , 0x116 , 0xcb , 0x1eba , 0x11a , 0x204 , 0x206 , 0x1eb8 , 0x228 , 0x118 , 0x1e18 , 0x1e1a , 0x1e1e , 0x1f4 , 0x11c , 0x1e20 , 0x11e , 0x120 , 0x1e6 , 0x122 , 0x124 , 0x1e22 , 0x1e26 , 0x21e , 0x1e24 , 0x1e28 , 0x1e2a , 0xcc , 0xcd , 0xce , 0x128 , 0x12a , 0x12c , 0x130 , 0xcf , 0x1ec8 , 0x1cf , 0x208 , 0x20a , 0x1eca , 0x12e , 0x1e2c , 0x134 , 0x1e30 , 0x1e8 , 0x1e32 , 0x136 , 0x1e34 , 0x139 , 0x13d , 0x1e36 , 0x13b , 0x1e3c , 0x1e3a , 0x1e3e , 0x1e40 , 0x1e42 , 0x1f8 , 0x143 , 0xd1 , 0x1e44 , 0x147 , 0x1e46 , 0x145 , 0x1e4a , 0x1e48 , 0xd2 , 0xd3 , 0xd4 , 0xd5 , 0x14c , 0x14e , 0x22e , 0xd6 , 0x1ece , 0x150 , 0x1d1 , 0x20c , 0x20e , 0x1a0 , 0x1ecc , 0x1ea , 0x1e54 , 0x1e56 , 0x154 , 0x1e58 , 0x158 , 0x210 , 0x212 , 0x1e5a , 0x156 , 0x1e5e , 0x15a , 0x15c , 0x1e60 , 0x160 , 0x1e62 , 0x218 , 0x15e , 0x1e6a , 0x164 , 0x1e6c , 0x21a , 0x162 , 0x1e70 , 0x1e6e , 0xd9 , 0xda , 0xdb , 0x168 , 0x16a , 0x16c , 0xdc , 0x1ee6 , 0x16e , 0x170 , 0x1d3 , 0x214 , 0x216 , 0x1af , 0x1ee4 , 0x1e72 , 0x172 , 0x1e76 , 0x1e74 , 0x1e7c , 0x1e7e , 0x1e80 , 0x1e82 , 0x174 , 0x1e86 , 0x1e84 , 0x1e88 , 0x1e8a , 0x1e8c , 0x1ef2 , 0xdd , 0x176 , 0x1ef8 , 0x232 , 0x1e8e , 0x178 , 0x1ef6 , 0x1ef4 , 0x179 , 0x1e90 , 0x17b , 0x17d , 0x1e92 , 0x1e94 , 0xe0 , 0xe1 , 0xe2 , 0xe3 , 0x101 , 0x103 , 0x227 , 0xe4 , 0x1ea3 , 0xe5 , 0x1ce , 0x201 , 0x203 , 0x1ea1 , 0x1e01 , 0x105 , 0x1e03 , 0x1e05 , 0x1e07 , 0x107 , 0x109 , 0x10b , 0x10d , 0xe7 , 0x1e0b , 0x10f , 0x1e0d , 0x1e11 , 0x1e13 , 0x1e0f , 0xe8 , 0xe9 , 0xea , 0x1ebd , 0x113 , 0x115 , 0x117 , 0xeb , 0x1ebb , 0x11b , 0x205 , 0x207 , 0x1eb9 , 0x229 , 0x119 , 0x1e19 , 0x1e1b , 0x1e1f , 0x1f5 , 0x11d , 0x1e21 , 0x11f , 0x121 , 0x1e7 , 0x123 , 0x125 , 0x1e23 , 0x1e27 , 0x21f , 0x1e25 , 0x1e29 , 0x1e2b , 0x1e96 , 0xec , 0xed , 0xee , 0x129 , 0x12b , 0x12d , 0xef , 0x1ec9 , 0x1d0 , 0x209 , 0x20b , 0x1ecb , 0x12f , 0x1e2d , 0x135 , 0x1f0 , 0x1e31 , 0x1e9 , 0x1e33 , 0x137 , 0x1e35 , 0x13a , 0x13e , 0x1e37 , 0x13c , 0x1e3d , 0x1e3b , 0x1e3f , 0x1e41 , 0x1e43 , 0x1f9 , 0x144 , 0xf1 , 0x1e45 , 0x148 , 0x1e47 , 0x146 , 0x1e4b , 0x1e49 , 0xf2 , 0xf3 , 0xf4 , 0xf5 , 0x14d , 0x14f , 0x22f , 0xf6 , 0x1ecf , 0x151 , 0x1d2 , 0x20d , 0x20f , 0x1a1 , 0x1ecd , 0x1eb , 0x1e55 , 0x1e57 , 0x155 , 0x1e59 , 0x159 , 0x211 , 0x213 , 0x1e5b , 0x157 , 0x1e5f , 0x15b , 0x15d , 0x1e61 , 0x161 , 0x1e63 , 0x219 , 0x15f , 0x1e6b , 0x1e97 , 0x165 , 0x1e6d , 0x21b , 0x163 , 0x1e71 , 0x1e6f , 0xf9 , 0xfa , 0xfb , 0x169 , 0x16b , 0x16d , 0xfc , 0x1ee7 , 0x16f , 0x171 , 0x1d4 , 0x215 , 0x217 , 0x1b0 , 0x1ee5 , 0x1e73 , 0x173 , 0x1e77 , 0x1e75 , 0x1e7d , 0x1e7f , 0x1e81 , 0x1e83 , 0x175 , 0x1e87 , 0x1e85 , 0x1e98 , 0x1e89 , 0x1e8b , 0x1e8d , 0x1ef3 , 0xfd , 0x177 , 0x1ef9 , 0x233 , 0x1e8f , 0xff , 0x1ef7 , 0x1e99 , 0x1ef5 , 0x17a , 0x1e91 , 0x17c , 0x17e , 0x1e93 , 0x1e95 , 0x1fed , 0x385 , 0x1fc1 , 0x1ea6 , 0x1ea4 , 0x1eaa , 0x1ea8 , 0x1de , 0x1fa , 0x1fc , 0x1e2 , 0x1e08 , 0x1ec0 , 0x1ebe , 0x1ec4 , 0x1ec2 , 0x1e2e , 0x1ed2 , 0x1ed0 , 0x1ed6 , 0x1ed4 , 0x1e4c , 0x22c , 0x1e4e , 0x22a , 0x1fe , 0x1db , 0x1d7 , 0x1d5 , 0x1d9 , 0x1ea7 , 0x1ea5 , 0x1eab , 0x1ea9 , 0x1df , 0x1fb , 0x1fd , 0x1e3 , 0x1e09 , 0x1ec1 , 0x1ebf , 0x1ec5 , 0x1ec3 , 0x1e2f , 0x1ed3 , 0x1ed1 , 0x1ed7 , 0x1ed5 , 0x1e4d , 0x22d , 0x1e4f , 0x22b , 0x1ff , 0x1dc , 0x1d8 , 0x1d6 , 0x1da , 0x1eb0 , 0x1eae , 0x1eb4 , 0x1eb2 , 0x1eb1 , 0x1eaf , 0x1eb5 , 0x1eb3 , 0x1e14 , 0x1e16 , 0x1e15 , 0x1e17 , 0x1e50 , 0x1e52 , 0x1e51 , 0x1e53 , 0x1e64 , 0x1e65 , 0x1e66 , 0x1e67 , 0x1e78 , 0x1e79 , 0x1e7a , 0x1e7b , 0x1e9b , 0x1edc , 0x1eda , 0x1ee0 , 0x1ede , 0x1ee2 , 0x1edd , 0x1edb , 0x1ee1 , 0x1edf , 0x1ee3 , 0x1eea , 0x1ee8 , 0x1eee , 0x1eec , 0x1ef0 , 0x1eeb , 0x1ee9 , 0x1eef , 0x1eed , 0x1ef1 , 0x1ee , 0x1ec , 0x1ed , 0x1e0 , 0x1e1 , 0x1e1c , 0x1e1d , 0x230 , 0x231 , 0x1ef , 0x1fba , 0x386 , 0x1fb9 , 0x1fb8 , 0x1f08 , 0x1f09 , 0x1fbc , 0x1fc8 , 0x388 , 0x1f18 , 0x1f19 , 0x1fca , 0x389 , 0x1f28 , 0x1f29 , 0x1fcc , 0x1fda , 0x38a , 0x1fd9 , 0x1fd8 , 0x3aa , 0x1f38 , 0x1f39 , 0x1ff8 , 0x38c , 0x1f48 , 0x1f49 , 0x1fec , 0x1fea , 0x38e , 0x1fe9 , 0x1fe8 , 0x3ab , 0x1f59 , 0x1ffa , 0x38f , 0x1f68 , 0x1f69 , 0x1ffc , 0x1fb4 , 0x1fc4 , 0x1f70 , 0x3ac , 0x1fb1 , 0x1fb0 , 0x1f00 , 0x1f01 , 0x1fb6 , 0x1fb3 , 0x1f72 , 0x3ad , 0x1f10 , 0x1f11 , 0x1f74 , 0x3ae , 0x1f20 , 0x1f21 , 0x1fc6 , 0x1fc3 , 0x1f76 , 0x3af , 0x1fd1 , 0x1fd0 , 0x3ca , 0x1f30 , 0x1f31 , 0x1fd6 , 0x1f78 , 0x3cc , 0x1f40 , 0x1f41 , 0x1fe4 , 0x1fe5 , 0x1f7a , 0x3cd , 0x1fe1 , 0x1fe0 , 0x3cb , 0x1f50 , 0x1f51 , 0x1fe6 , 0x1f7c , 0x3ce , 0x1f60 , 0x1f61 , 0x1ff6 , 0x1ff3 , 0x1fd2 , 0x390 , 0x1fd7 , 0x1fe2 , 0x3b0 , 0x1fe7 , 0x1ff4 , 0x3d3 , 0x3d4 , 0x407 , 0x4d0 , 0x4d2 , 0x403 , 0x400 , 0x4d6 , 0x401 , 0x4c1 , 0x4dc , 0x4de , 0x40d , 0x4e2 , 0x419 , 0x4e4 , 0x40c , 0x4e6 , 0x4ee , 0x40e , 0x4f0 , 0x4f2 , 0x4f4 , 0x4f8 , 0x4ec , 0x4d1 , 0x4d3 , 0x453 , 0x450 , 0x4d7 , 0x451 , 0x4c2 , 0x4dd , 0x4df , 0x45d , 0x4e3 , 0x439 , 0x4e5 , 0x45c , 0x4e7 , 0x4ef , 0x45e , 0x4f1 , 0x4f3 , 0x4f5 , 0x4f9 , 0x4ed , 0x457 , 0x476 , 0x477 , 0x4da , 0x4db , 0x4ea , 0x4eb , 0x622 , 0x623 , 0x625 , 0x624 , 0x626 , 0x6c2 , 0x6d3 , 0x6c0 , 0x929 , 0x931 , 0x934 , 0x9cb , 0x9cc , 0xb4b , 0xb48 , 0xb4c , 0xb94 , 0xbca , 0xbcc , 0xbcb , 0xc48 , 0xcc0 , 0xcca , 0xcc7 , 0xcc8 , 0xccb , 0xd4a , 0xd4c , 0xd4b , 0xdda , 0xddc , 0xdde , 0xddd , 0x1026 , 0x1e38 , 0x1e39 , 0x1e5c , 0x1e5d , 0x1e68 , 0x1e69 , 0x1eac , 0x1eb6 , 0x1ead , 0x1eb7 , 0x1ec6 , 0x1ec7 , 0x1ed8 , 0x1ed9 , 0x1f02 , 0x1f04 , 0x1f06 , 0x1f80 , 0x1f03 , 0x1f05 , 0x1f07 , 0x1f81 , 0x1f82 , 0x1f83 , 0x1f84 , 0x1f85 , 0x1f86 , 0x1f87 , 0x1f0a , 0x1f0c , 0x1f0e , 0x1f88 , 0x1f0b , 0x1f0d , 0x1f0f , 0x1f89 , 0x1f8a , 0x1f8b , 0x1f8c , 0x1f8d , 0x1f8e , 0x1f8f , 0x1f12 , 0x1f14 , 0x1f13 , 0x1f15 , 0x1f1a , 0x1f1c , 0x1f1b , 0x1f1d , 0x1f22 , 0x1f24 , 0x1f26 , 0x1f90 , 0x1f23 , 0x1f25 , 0x1f27 , 0x1f91 , 0x1f92 , 0x1f93 , 0x1f94 , 0x1f95 , 0x1f96 , 0x1f97 , 0x1f2a , 0x1f2c , 0x1f2e , 0x1f98 , 0x1f2b , 0x1f2d , 0x1f2f , 0x1f99 , 0x1f9a , 0x1f9b , 0x1f9c , 0x1f9d , 0x1f9e , 0x1f9f , 0x1f32 , 0x1f34 , 0x1f36 , 0x1f33 , 0x1f35 , 0x1f37 , 0x1f3a , 0x1f3c , 0x1f3e , 0x1f3b , 0x1f3d , 0x1f3f , 0x1f42 , 0x1f44 , 0x1f43 , 0x1f45 , 0x1f4a , 0x1f4c , 0x1f4b , 0x1f4d , 0x1f52 , 0x1f54 , 0x1f56 , 0x1f53 , 0x1f55 , 0x1f57 , 0x1f5b , 0x1f5d , 0x1f5f , 0x1f62 , 0x1f64 , 0x1f66 , 0x1fa0 , 0x1f63 , 0x1f65 , 0x1f67 , 0x1fa1 , 0x1fa2 , 0x1fa3 , 0x1fa4 , 0x1fa5 , 0x1fa6 , 0x1fa7 , 0x1f6a , 0x1f6c , 0x1f6e , 0x1fa8 , 0x1f6b , 0x1f6d , 0x1f6f , 0x1fa9 , 0x1faa , 0x1fab , 0x1fac , 0x1fad , 0x1fae , 0x1faf , 0x1fb2 , 0x1fc2 , 0x1ff2 , 0x1fb7 , 0x1fcd , 0x1fce , 0x1fcf , 0x1fc7 , 0x1ff7 , 0x1fdd , 0x1fde , 0x1fdf , 0x219a , 0x219b , 0x21ae , 0x21cd , 0x21cf , 0x21ce , 0x2204 , 0x2209 , 0x220c , 0x2224 , 0x2226 , 0x2241 , 0x2244 , 0x2247 , 0x2249 , 0x226d , 0x2262 , 0x2270 , 0x2271 , 0x2274 , 0x2275 , 0x2278 , 0x2279 , 0x2280 , 0x2281 , 0x22e0 , 0x22e1 , 0x2284 , 0x2285 , 0x2288 , 0x2289 , 0x22e2 , 0x22e3 , 0x22ac , 0x22ad , 0x22ae , 0x22af , 0x22ea , 0x22eb , 0x22ec , 0x22ed , 0x3094 , 0x304c , 0x304e , 0x3050 , 0x3052 , 0x3054 , 0x3056 , 0x3058 , 0x305a , 0x305c , 0x305e , 0x3060 , 0x3062 , 0x3065 , 0x3067 , 0x3069 , 0x3070 , 0x3071 , 0x3073 , 0x3074 , 0x3076 , 0x3077 , 0x3079 , 0x307a , 0x307c , 0x307d , 0x309e , 0x30f4 , 0x30ac , 0x30ae , 0x30b0 , 0x30b2 , 0x30b4 , 0x30b6 , 0x30b8 , 0x30ba , 0x30bc , 0x30be , 0x30c0 , 0x30c2 , 0x30c5 , 0x30c7 , 0x30c9 , 0x30d0 , 0x30d1 , 0x30d3 , 0x30d4 , 0x30d6 , 0x30d7 , 0x30d9 , 0x30da , 0x30dc , 0x30dd , 0x30f7 , 0x30f8 , 0x30f9 , 0x30fa , 0x30fe }
; 
static unsigned int utable_compose_long_pairs [] = {
  0x27ed3 , 0x0 , 0x25249 , 0x0 , 0x233d5 , 0x0 , 0x2284a , 0x0 , 0x21d0b , 0x0 , 0x236a3 , 0x0 , 0x22bf1 , 0x0 , 0x22b0c , 0x0 , 0x226d4 , 0x0 , 0x261da , 0x0 , 0x22331 , 0x0 , 0x219c8 , 0x0 , 0x216a8 , 0x0 , 0x25cd0 , 0x0 , 0x22844 , 0x0 , 0x20b63 , 0x0 , 0x2051c , 0x0 , 0x2a291 , 0x0 , 0x2a105 , 0x0 , 0x2a0ce , 0x0 , 0x23cbc , 0x0 , 0x23afa , 0x0 , 0x23a8d , 0x0 , 0x238a7 , 0x0 , 0x233c3 , 0x0 , 0x2300a , 0x0 , 0x232b8 , 0x0 , 0x22331 , 0x0 , 0x2a392 , 0x0 , 0x22183 , 0x0 , 0x21de6 , 0x0 , 0x21de4 , 0x0 , 0x21b18 , 0x0 , 0x216ea , 0x0 , 0x214e4 , 0x0 , 0x20a2c , 0x0 , 0x291df , 0x0 , 0x2054b , 0x0 , 0x29145 , 0x0 , 0x285d2 , 0x0 , 0x27f2f , 0x0 , 0x27966 , 0x0 , 0x26fb1 , 0x0 , 0x26cd5 , 0x0 , 0x26c36 , 0x0 , 0x2339c , 0x0 , 0x267b5 , 0x0 , 0x2335f , 0x0 , 0x265a8 , 0x0 , 0x26523 , 0x0 , 0x26228 , 0x0 , 0x25aa7 , 0x0 , 0x2597c , 0x0 , 0x2569a , 0x0 , 0x25626 , 0x0 , 0x25133 , 0x0 , 0x250f2 , 0x0 , 0x24fb8 , 0x0 , 0x24735 , 0x0 , 0x23f5e , 0x0 , 0x23d1e , 0x0 , 0x2346d , 0x0 , 0x1d1bc , 0x1d16e , 0x1d1ba , 0x1d165 , 0x1d1b9 , 0x1d165 , 0x1d15f , 0x1d172 , 0x1d15f , 0x1d170 , 0x1d15f , 0x1d16e , 0x1d157 , 0x1d165 , 0x2a20e , 0x0 , 0x2921a , 0x0 , 0x28d77 , 0x0 , 0x28bfa , 0x0 , 0x208de , 0x0 , 0x20804 , 0x0 , 0x27ca8 , 0x0 , 0x27667 , 0x0 , 0x270d2 , 0x0 , 0x26f2c , 0x0 , 0x273ca , 0x0 , 0x2063a , 0x0 , 0x26b3c , 0x0 , 0x23393 , 0x0 , 0x26247 , 0x0 , 0x25c80 , 0x0 , 0x2541d , 0x0 , 0x25119 , 0x0 , 0x243ab , 0x0 , 0x23f8e , 0x0 , 0x29b30 , 0x0 , 0x285ed , 0x0 , 0x26d6b , 0x0 , 0x267a7 , 0x0 , 0x264da , 0x0 , 0x1d1bc , 0x1d16f , 0x2633e , 0x0 , 0x262d9 , 0x0 , 0x25f86 , 0x0 , 0x25bab , 0x0 , 0x25aa7 , 0x0 , 0x20122 , 0x0 , 0x256c5 , 0x0 , 0x250f3 , 0x0 , 0x25044 , 0x0 , 0x24fa1 , 0x0 , 0x2219f , 0x0 , 0x24c92 , 0x0 , 0x24c36 , 0x0 , 0x1d15f , 0x1d171 , 0x1d15f , 0x1d16f , 0x24814 , 0x0 , 0x24608 , 0x0 , 0x1d158 , 0x1d165 , 0x2a600 , 0x0 , 0x24263 , 0x0 , 0x20525 , 0x0 , 0x23ed1 , 0x0 , 0x29496 , 0x0 , 0x2940a , 0x0 , 0x2872e , 0x0 , 0x278ae , 0x0 , 0x295b6 , 0x0 , 0x1d1bb , 0x1d16f , 0x1d1bb , 0x1d16e }
; 
static unsigned int utable_decomp_keys [] = {
  0xc0 , 0xc1 , 0xc2 , 0xc3 , 0xc4 , 0xc5 , 0xc7 , 0xc8 , 0xc9 , 0xca , 0xcb , 0xcc , 0xcd , 0xce , 0xcf , 0xd1 , 0xd2 , 0xd3 , 0xd4 , 0xd5 , 0xd6 , 0xd9 , 0xda , 0xdb , 0xdc , 0xdd , 0xe0 , 0xe1 , 0xe2 , 0xe3 , 0xe4 , 0xe5 , 0xe7 , 0xe8 , 0xe9 , 0xea , 0xeb , 0xec , 0xed , 0xee , 0xef , 0xf1 , 0xf2 , 0xf3 , 0xf4 , 0xf5 , 0xf6 , 0xf9 , 0xfa , 0xfb , 0xfc , 0xfd , 0xff , 0x100 , 0x101 , 0x102 , 0x103 , 0x104 , 0x105 , 0x106 , 0x107 , 0x108 , 0x109 , 0x10a , 0x10b , 0x10c , 0x10d , 0x10e , 0x10f , 0x112 , 0x113 , 0x114 , 0x115 , 0x116 , 0x117 , 0x118 , 0x119 , 0x11a , 0x11b , 0x11c , 0x11d , 0x11e , 0x11f , 0x120 , 0x121 , 0x122 , 0x123 , 0x124 , 0x125 , 0x128 , 0x129 , 0x12a , 0x12b , 0x12c , 0x12d , 0x12e , 0x12f , 0x130 , 0x134 , 0x135 , 0x136 , 0x137 , 0x139 , 0x13a , 0x13b , 0x13c , 0x13d , 0x13e , 0x143 , 0x144 , 0x145 , 0x146 , 0x147 , 0x148 , 0x14c , 0x14d , 0x14e , 0x14f , 0x150 , 0x151 , 0x154 , 0x155 , 0x156 , 0x157 , 0x158 , 0x159 , 0x15a , 0x15b , 0x15c , 0x15d , 0x15e , 0x15f , 0x160 , 0x161 , 0x162 , 0x163 , 0x164 , 0x165 , 0x168 , 0x169 , 0x16a , 0x16b , 0x16c , 0x16d , 0x16e , 0x16f , 0x170 , 0x171 , 0x172 , 0x173 , 0x174 , 0x175 , 0x176 , 0x177 , 0x178 , 0x179 , 0x17a , 0x17b , 0x17c , 0x17d , 0x17e , 0x1a0 , 0x1a1 , 0x1af , 0x1b0 , 0x1cd , 0x1ce , 0x1cf , 0x1d0 , 0x1d1 , 0x1d2 , 0x1d3 , 0x1d4 , 0x1d5 , 0x1d6 , 0x1d7 , 0x1d8 , 0x1d9 , 0x1da , 0x1db , 0x1dc , 0x1de , 0x1df , 0x1e0 , 0x1e1 , 0x1e2 , 0x1e3 , 0x1e6 , 0x1e7 , 0x1e8 , 0x1e9 , 0x1ea , 0x1eb , 0x1ec , 0x1ed , 0x1ee , 0x1ef , 0x1f0 , 0x1f4 , 0x1f5 , 0x1f8 , 0x1f9 , 0x1fa , 0x1fb , 0x1fc , 0x1fd , 0x1fe , 0x1ff , 0x200 , 0x201 , 0x202 , 0x203 , 0x204 , 0x205 , 0x206 , 0x207 , 0x208 , 0x209 , 0x20a , 0x20b , 0x20c , 0x20d , 0x20e , 0x20f , 0x210 , 0x211 , 0x212 , 0x213 , 0x214 , 0x215 , 0x216 , 0x217 , 0x218 , 0x219 , 0x21a , 0x21b , 0x21e , 0x21f , 0x226 , 0x227 , 0x228 , 0x229 , 0x22a , 0x22b , 0x22c , 0x22d , 0x22e , 0x22f , 0x230 , 0x231 , 0x232 , 0x233 , 0x340 , 0x341 , 0x343 , 0x344 , 0x374 , 0x37e , 0x385 , 0x386 , 0x387 , 0x388 , 0x389 , 0x38a , 0x38c , 0x38e , 0x38f , 0x390 , 0x3aa , 0x3ab , 0x3ac , 0x3ad , 0x3ae , 0x3af , 0x3b0 , 0x3ca , 0x3cb , 0x3cc , 0x3cd , 0x3ce , 0x3d3 , 0x3d4 , 0x400 , 0x401 , 0x403 , 0x407 , 0x40c , 0x40d , 0x40e , 0x419 , 0x439 , 0x450 , 0x451 , 0x453 , 0x457 , 0x45c , 0x45d , 0x45e , 0x476 , 0x477 , 0x4c1 , 0x4c2 , 0x4d0 , 0x4d1 , 0x4d2 , 0x4d3 , 0x4d6 , 0x4d7 , 0x4da , 0x4db , 0x4dc , 0x4dd , 0x4de , 0x4df , 0x4e2 , 0x4e3 , 0x4e4 , 0x4e5 , 0x4e6 , 0x4e7 , 0x4ea , 0x4eb , 0x4ec , 0x4ed , 0x4ee , 0x4ef , 0x4f0 , 0x4f1 , 0x4f2 , 0x4f3 , 0x4f4 , 0x4f5 , 0x4f8 , 0x4f9 , 0x622 , 0x623 , 0x624 , 0x625 , 0x626 , 0x6c0 , 0x6c2 , 0x6d3 , 0x929 , 0x931 , 0x934 , 0x958 , 0x959 , 0x95a , 0x95b , 0x95c , 0x95d , 0x95e , 0x95f , 0x9cb , 0x9cc , 0x9dc , 0x9dd , 0x9df , 0xa33 , 0xa36 , 0xa59 , 0xa5a , 0xa5b , 0xa5e , 0xb48 , 0xb4b , 0xb4c , 0xb5c , 0xb5d , 0xb94 , 0xbca , 0xbcb , 0xbcc , 0xc48 , 0xcc0 , 0xcc7 , 0xcc8 , 0xcca , 0xccb , 0xd4a , 0xd4b , 0xd4c , 0xdda , 0xddc , 0xddd , 0xdde , 0xf43 , 0xf4d , 0xf52 , 0xf57 , 0xf5c , 0xf69 , 0xf73 , 0xf75 , 0xf76 , 0xf78 , 0xf81 , 0xf93 , 0xf9d , 0xfa2 , 0xfa7 , 0xfac , 0xfb9 , 0x1026 , 0x1e00 , 0x1e01 , 0x1e02 , 0x1e03 , 0x1e04 , 0x1e05 , 0x1e06 , 0x1e07 , 0x1e08 , 0x1e09 , 0x1e0a , 0x1e0b , 0x1e0c , 0x1e0d , 0x1e0e , 0x1e0f , 0x1e10 , 0x1e11 , 0x1e12 , 0x1e13 , 0x1e14 , 0x1e15 , 0x1e16 , 0x1e17 , 0x1e18 , 0x1e19 , 0x1e1a , 0x1e1b , 0x1e1c , 0x1e1d , 0x1e1e , 0x1e1f , 0x1e20 , 0x1e21 , 0x1e22 , 0x1e23 , 0x1e24 , 0x1e25 , 0x1e26 , 0x1e27 , 0x1e28 , 0x1e29 , 0x1e2a , 0x1e2b , 0x1e2c , 0x1e2d , 0x1e2e , 0x1e2f , 0x1e30 , 0x1e31 , 0x1e32 , 0x1e33 , 0x1e34 , 0x1e35 , 0x1e36 , 0x1e37 , 0x1e38 , 0x1e39 , 0x1e3a , 0x1e3b , 0x1e3c , 0x1e3d , 0x1e3e , 0x1e3f , 0x1e40 , 0x1e41 , 0x1e42 , 0x1e43 , 0x1e44 , 0x1e45 , 0x1e46 , 0x1e47 , 0x1e48 , 0x1e49 , 0x1e4a , 0x1e4b , 0x1e4c , 0x1e4d , 0x1e4e , 0x1e4f , 0x1e50 , 0x1e51 , 0x1e52 , 0x1e53 , 0x1e54 , 0x1e55 , 0x1e56 , 0x1e57 , 0x1e58 , 0x1e59 , 0x1e5a , 0x1e5b , 0x1e5c , 0x1e5d , 0x1e5e , 0x1e5f , 0x1e60 , 0x1e61 , 0x1e62 , 0x1e63 , 0x1e64 , 0x1e65 , 0x1e66 , 0x1e67 , 0x1e68 , 0x1e69 , 0x1e6a , 0x1e6b , 0x1e6c , 0x1e6d , 0x1e6e , 0x1e6f , 0x1e70 , 0x1e71 , 0x1e72 , 0x1e73 , 0x1e74 , 0x1e75 , 0x1e76 , 0x1e77 , 0x1e78 , 0x1e79 , 0x1e7a , 0x1e7b , 0x1e7c , 0x1e7d , 0x1e7e , 0x1e7f , 0x1e80 , 0x1e81 , 0x1e82 , 0x1e83 , 0x1e84 , 0x1e85 , 0x1e86 , 0x1e87 , 0x1e88 , 0x1e89 , 0x1e8a , 0x1e8b , 0x1e8c , 0x1e8d , 0x1e8e , 0x1e8f , 0x1e90 , 0x1e91 , 0x1e92 , 0x1e93 , 0x1e94 , 0x1e95 , 0x1e96 , 0x1e97 , 0x1e98 , 0x1e99 , 0x1e9b , 0x1ea0 , 0x1ea1 , 0x1ea2 , 0x1ea3 , 0x1ea4 , 0x1ea5 , 0x1ea6 , 0x1ea7 , 0x1ea8 , 0x1ea9 , 0x1eaa , 0x1eab , 0x1eac , 0x1ead , 0x1eae , 0x1eaf , 0x1eb0 , 0x1eb1 , 0x1eb2 , 0x1eb3 , 0x1eb4 , 0x1eb5 , 0x1eb6 , 0x1eb7 , 0x1eb8 , 0x1eb9 , 0x1eba , 0x1ebb , 0x1ebc , 0x1ebd , 0x1ebe , 0x1ebf , 0x1ec0 , 0x1ec1 , 0x1ec2 , 0x1ec3 , 0x1ec4 , 0x1ec5 , 0x1ec6 , 0x1ec7 , 0x1ec8 , 0x1ec9 , 0x1eca , 0x1ecb , 0x1ecc , 0x1ecd , 0x1ece , 0x1ecf , 0x1ed0 , 0x1ed1 , 0x1ed2 , 0x1ed3 , 0x1ed4 , 0x1ed5 , 0x1ed6 , 0x1ed7 , 0x1ed8 , 0x1ed9 , 0x1eda , 0x1edb , 0x1edc , 0x1edd , 0x1ede , 0x1edf , 0x1ee0 , 0x1ee1 , 0x1ee2 , 0x1ee3 , 0x1ee4 , 0x1ee5 , 0x1ee6 , 0x1ee7 , 0x1ee8 , 0x1ee9 , 0x1eea , 0x1eeb , 0x1eec , 0x1eed , 0x1eee , 0x1eef , 0x1ef0 , 0x1ef1 , 0x1ef2 , 0x1ef3 , 0x1ef4 , 0x1ef5 , 0x1ef6 , 0x1ef7 , 0x1ef8 , 0x1ef9 , 0x1f00 , 0x1f01 , 0x1f02 , 0x1f03 , 0x1f04 , 0x1f05 , 0x1f06 , 0x1f07 , 0x1f08 , 0x1f09 , 0x1f0a , 0x1f0b , 0x1f0c , 0x1f0d , 0x1f0e , 0x1f0f , 0x1f10 , 0x1f11 , 0x1f12 , 0x1f13 , 0x1f14 , 0x1f15 , 0x1f18 , 0x1f19 , 0x1f1a , 0x1f1b , 0x1f1c , 0x1f1d , 0x1f20 , 0x1f21 , 0x1f22 , 0x1f23 , 0x1f24 , 0x1f25 , 0x1f26 , 0x1f27 , 0x1f28 , 0x1f29 , 0x1f2a , 0x1f2b , 0x1f2c , 0x1f2d , 0x1f2e , 0x1f2f , 0x1f30 , 0x1f31 , 0x1f32 , 0x1f33 , 0x1f34 , 0x1f35 , 0x1f36 , 0x1f37 , 0x1f38 , 0x1f39 , 0x1f3a , 0x1f3b , 0x1f3c , 0x1f3d , 0x1f3e , 0x1f3f , 0x1f40 , 0x1f41 , 0x1f42 , 0x1f43 , 0x1f44 , 0x1f45 , 0x1f48 , 0x1f49 , 0x1f4a , 0x1f4b , 0x1f4c , 0x1f4d , 0x1f50 , 0x1f51 , 0x1f52 , 0x1f53 , 0x1f54 , 0x1f55 , 0x1f56 , 0x1f57 , 0x1f59 , 0x1f5b , 0x1f5d , 0x1f5f , 0x1f60 , 0x1f61 , 0x1f62 , 0x1f63 , 0x1f64 , 0x1f65 , 0x1f66 , 0x1f67 , 0x1f68 , 0x1f69 , 0x1f6a , 0x1f6b , 0x1f6c , 0x1f6d , 0x1f6e , 0x1f6f , 0x1f70 , 0x1f71 , 0x1f72 , 0x1f73 , 0x1f74 , 0x1f75 , 0x1f76 , 0x1f77 , 0x1f78 , 0x1f79 , 0x1f7a , 0x1f7b , 0x1f7c , 0x1f7d , 0x1f80 , 0x1f81 , 0x1f82 , 0x1f83 , 0x1f84 , 0x1f85 , 0x1f86 , 0x1f87 , 0x1f88 , 0x1f89 , 0x1f8a , 0x1f8b , 0x1f8c , 0x1f8d , 0x1f8e , 0x1f8f , 0x1f90 , 0x1f91 , 0x1f92 , 0x1f93 , 0x1f94 , 0x1f95 , 0x1f96 , 0x1f97 , 0x1f98 , 0x1f99 , 0x1f9a , 0x1f9b , 0x1f9c , 0x1f9d , 0x1f9e , 0x1f9f , 0x1fa0 , 0x1fa1 , 0x1fa2 , 0x1fa3 , 0x1fa4 , 0x1fa5 , 0x1fa6 , 0x1fa7 , 0x1fa8 , 0x1fa9 , 0x1faa , 0x1fab , 0x1fac , 0x1fad , 0x1fae , 0x1faf , 0x1fb0 , 0x1fb1 , 0x1fb2 , 0x1fb3 , 0x1fb4 , 0x1fb6 , 0x1fb7 , 0x1fb8 , 0x1fb9 , 0x1fba , 0x1fbb , 0x1fbc , 0x1fbe , 0x1fc1 , 0x1fc2 , 0x1fc3 , 0x1fc4 , 0x1fc6 , 0x1fc7 , 0x1fc8 , 0x1fc9 , 0x1fca , 0x1fcb , 0x1fcc , 0x1fcd , 0x1fce , 0x1fcf , 0x1fd0 , 0x1fd1 , 0x1fd2 , 0x1fd3 , 0x1fd6 , 0x1fd7 , 0x1fd8 , 0x1fd9 , 0x1fda , 0x1fdb , 0x1fdd , 0x1fde , 0x1fdf , 0x1fe0 , 0x1fe1 , 0x1fe2 , 0x1fe3 , 0x1fe4 , 0x1fe5 , 0x1fe6 , 0x1fe7 , 0x1fe8 , 0x1fe9 , 0x1fea , 0x1feb , 0x1fec , 0x1fed , 0x1fee , 0x1fef , 0x1ff2 , 0x1ff3 , 0x1ff4 , 0x1ff6 , 0x1ff7 , 0x1ff8 , 0x1ff9 , 0x1ffa , 0x1ffb , 0x1ffc , 0x1ffd , 0x2000 , 0x2001 , 0x2126 , 0x212a , 0x212b , 0x219a , 0x219b , 0x21ae , 0x21cd , 0x21ce , 0x21cf , 0x2204 , 0x2209 , 0x220c , 0x2224 , 0x2226 , 0x2241 , 0x2244 , 0x2247 , 0x2249 , 0x2260 , 0x2262 , 0x226d , 0x226e , 0x226f , 0x2270 , 0x2271 , 0x2274 , 0x2275 , 0x2278 , 0x2279 , 0x2280 , 0x2281 , 0x2284 , 0x2285 , 0x2288 , 0x2289 , 0x22ac , 0x22ad , 0x22ae , 0x22af , 0x22e0 , 0x22e1 , 0x22e2 , 0x22e3 , 0x22ea , 0x22eb , 0x22ec , 0x22ed , 0x2329 , 0x232a , 0x2adc , 0x304c , 0x304e , 0x3050 , 0x3052 , 0x3054 , 0x3056 , 0x3058 , 0x305a , 0x305c , 0x305e , 0x3060 , 0x3062 , 0x3065 , 0x3067 , 0x3069 , 0x3070 , 0x3071 , 0x3073 , 0x3074 , 0x3076 , 0x3077 , 0x3079 , 0x307a , 0x307c , 0x307d , 0x3094 , 0x309e , 0x30ac , 0x30ae , 0x30b0 , 0x30b2 , 0x30b4 , 0x30b6 , 0x30b8 , 0x30ba , 0x30bc , 0x30be , 0x30c0 , 0x30c2 , 0x30c5 , 0x30c7 , 0x30c9 , 0x30d0 , 0x30d1 , 0x30d3 , 0x30d4 , 0x30d6 , 0x30d7 , 0x30d9 , 0x30da , 0x30dc , 0x30dd , 0x30f4 , 0x30f7 , 0x30f8 , 0x30f9 , 0x30fa , 0x30fe , 0xf900 , 0xf901 , 0xf902 , 0xf903 , 0xf904 , 0xf905 , 0xf906 , 0xf907 , 0xf908 , 0xf909 , 0xf90a , 0xf90b , 0xf90c , 0xf90d , 0xf90e , 0xf90f , 0xf910 , 0xf911 , 0xf912 , 0xf913 , 0xf914 , 0xf915 , 0xf916 , 0xf917 , 0xf918 , 0xf919 , 0xf91a , 0xf91b , 0xf91c , 0xf91d , 0xf91e , 0xf91f , 0xf920 , 0xf921 , 0xf922 , 0xf923 , 0xf924 , 0xf925 , 0xf926 , 0xf927 , 0xf928 , 0xf929 , 0xf92a , 0xf92b , 0xf92c , 0xf92d , 0xf92e , 0xf92f , 0xf930 , 0xf931 , 0xf932 , 0xf933 , 0xf934 , 0xf935 , 0xf936 , 0xf937 , 0xf938 , 0xf939 , 0xf93a , 0xf93b , 0xf93c , 0xf93d , 0xf93e , 0xf93f , 0xf940 , 0xf941 , 0xf942 , 0xf943 , 0xf944 , 0xf945 , 0xf946 , 0xf947 , 0xf948 , 0xf949 , 0xf94a , 0xf94b , 0xf94c , 0xf94d , 0xf94e , 0xf94f , 0xf950 , 0xf951 , 0xf952 , 0xf953 , 0xf954 , 0xf955 , 0xf956 , 0xf957 , 0xf958 , 0xf959 , 0xf95a , 0xf95b , 0xf95c , 0xf95d , 0xf95e , 0xf95f , 0xf960 , 0xf961 , 0xf962 , 0xf963 , 0xf964 , 0xf965 , 0xf966 , 0xf967 , 0xf968 , 0xf969 , 0xf96a , 0xf96b , 0xf96c , 0xf96d , 0xf96e , 0xf96f , 0xf970 , 0xf971 , 0xf972 , 0xf973 , 0xf974 , 0xf975 , 0xf976 , 0xf977 , 0xf978 , 0xf979 , 0xf97a , 0xf97b , 0xf97c , 0xf97d , 0xf97e , 0xf97f , 0xf980 , 0xf981 , 0xf982 , 0xf983 , 0xf984 , 0xf985 , 0xf986 , 0xf987 , 0xf988 , 0xf989 , 0xf98a , 0xf98b , 0xf98c , 0xf98d , 0xf98e , 0xf98f , 0xf990 , 0xf991 , 0xf992 , 0xf993 , 0xf994 , 0xf995 , 0xf996 , 0xf997 , 0xf998 , 0xf999 , 0xf99a , 0xf99b , 0xf99c , 0xf99d , 0xf99e , 0xf99f , 0xf9a0 , 0xf9a1 , 0xf9a2 , 0xf9a3 , 0xf9a4 , 0xf9a5 , 0xf9a6 , 0xf9a7 , 0xf9a8 , 0xf9a9 , 0xf9aa , 0xf9ab , 0xf9ac , 0xf9ad , 0xf9ae , 0xf9af , 0xf9b0 , 0xf9b1 , 0xf9b2 , 0xf9b3 , 0xf9b4 , 0xf9b5 , 0xf9b6 , 0xf9b7 , 0xf9b8 , 0xf9b9 , 0xf9ba , 0xf9bb , 0xf9bc , 0xf9bd , 0xf9be , 0xf9bf , 0xf9c0 , 0xf9c1 , 0xf9c2 , 0xf9c3 , 0xf9c4 , 0xf9c5 , 0xf9c6 , 0xf9c7 , 0xf9c8 , 0xf9c9 , 0xf9ca , 0xf9cb , 0xf9cc , 0xf9cd , 0xf9ce , 0xf9cf , 0xf9d0 , 0xf9d1 , 0xf9d2 , 0xf9d3 , 0xf9d4 , 0xf9d5 , 0xf9d6 , 0xf9d7 , 0xf9d8 , 0xf9d9 , 0xf9da , 0xf9db , 0xf9dc , 0xf9dd , 0xf9de , 0xf9df , 0xf9e0 , 0xf9e1 , 0xf9e2 , 0xf9e3 , 0xf9e4 , 0xf9e5 , 0xf9e6 , 0xf9e7 , 0xf9e8 , 0xf9e9 , 0xf9ea , 0xf9eb , 0xf9ec , 0xf9ed , 0xf9ee , 0xf9ef , 0xf9f0 , 0xf9f1 , 0xf9f2 , 0xf9f3 , 0xf9f4 , 0xf9f5 , 0xf9f6 , 0xf9f7 , 0xf9f8 , 0xf9f9 , 0xf9fa , 0xf9fb , 0xf9fc , 0xf9fd , 0xf9fe , 0xf9ff , 0xfa00 , 0xfa01 , 0xfa02 , 0xfa03 , 0xfa04 , 0xfa05 , 0xfa06 , 0xfa07 , 0xfa08 , 0xfa09 , 0xfa0a , 0xfa0b , 0xfa0c , 0xfa0d , 0xfa10 , 0xfa12 , 0xfa15 , 0xfa16 , 0xfa17 , 0xfa18 , 0xfa19 , 0xfa1a , 0xfa1b , 0xfa1c , 0xfa1d , 0xfa1e , 0xfa20 , 0xfa22 , 0xfa25 , 0xfa26 , 0xfa2a , 0xfa2b , 0xfa2c , 0xfa2d , 0xfa30 , 0xfa31 , 0xfa32 , 0xfa33 , 0xfa34 , 0xfa35 , 0xfa36 , 0xfa37 , 0xfa38 , 0xfa39 , 0xfa3a , 0xfa3b , 0xfa3c , 0xfa3d , 0xfa3e , 0xfa3f , 0xfa40 , 0xfa41 , 0xfa42 , 0xfa43 , 0xfa44 , 0xfa45 , 0xfa46 , 0xfa47 , 0xfa48 , 0xfa49 , 0xfa4a , 0xfa4b , 0xfa4c , 0xfa4d , 0xfa4e , 0xfa4f , 0xfa50 , 0xfa51 , 0xfa52 , 0xfa53 , 0xfa54 , 0xfa55 , 0xfa56 , 0xfa57 , 0xfa58 , 0xfa59 , 0xfa5a , 0xfa5b , 0xfa5c , 0xfa5d , 0xfa5e , 0xfa5f , 0xfa60 , 0xfa61 , 0xfa62 , 0xfa63 , 0xfa64 , 0xfa65 , 0xfa66 , 0xfa67 , 0xfa68 , 0xfa69 , 0xfa6a , 0xfa70 , 0xfa71 , 0xfa72 , 0xfa73 , 0xfa74 , 0xfa75 , 0xfa76 , 0xfa77 , 0xfa78 , 0xfa79 , 0xfa7a , 0xfa7b , 0xfa7c , 0xfa7d , 0xfa7e , 0xfa7f , 0xfa80 , 0xfa81 , 0xfa82 , 0xfa83 , 0xfa84 , 0xfa85 , 0xfa86 , 0xfa87 , 0xfa88 , 0xfa89 , 0xfa8a , 0xfa8b , 0xfa8c , 0xfa8d , 0xfa8e , 0xfa8f , 0xfa90 , 0xfa91 , 0xfa92 , 0xfa93 , 0xfa94 , 0xfa95 , 0xfa96 , 0xfa97 , 0xfa98 , 0xfa99 , 0xfa9a , 0xfa9b , 0xfa9c , 0xfa9d , 0xfa9e , 0xfa9f , 0xfaa0 , 0xfaa1 , 0xfaa2 , 0xfaa3 , 0xfaa4 , 0xfaa5 , 0xfaa6 , 0xfaa7 , 0xfaa8 , 0xfaa9 , 0xfaaa , 0xfaab , 0xfaac , 0xfaad , 0xfaae , 0xfaaf , 0xfab0 , 0xfab1 , 0xfab2 , 0xfab3 , 0xfab4 , 0xfab5 , 0xfab6 , 0xfab7 , 0xfab8 , 0xfab9 , 0xfaba , 0xfabb , 0xfabc , 0xfabd , 0xfabe , 0xfabf , 0xfac0 , 0xfac1 , 0xfac2 , 0xfac3 , 0xfac4 , 0xfac5 , 0xfac6 , 0xfac7 , 0xfac8 , 0xfac9 , 0xfaca , 0xfacb , 0xfacc , 0xfacd , 0xface , 0xfacf , 0xfad0 , 0xfad1 , 0xfad2 , 0xfad3 , 0xfad4 , 0xfad5 , 0xfad6 , 0xfad7 , 0xfad8 , 0xfad9 , 0xfb1d , 0xfb1f , 0xfb2a , 0xfb2b , 0xfb2c , 0xfb2d , 0xfb2e , 0xfb2f , 0xfb30 , 0xfb31 , 0xfb32 , 0xfb33 , 0xfb34 , 0xfb35 , 0xfb36 , 0xfb38 , 0xfb39 , 0xfb3a , 0xfb3b , 0xfb3c , 0xfb3e , 0xfb40 , 0xfb41 , 0xfb43 , 0xfb44 , 0xfb46 , 0xfb47 , 0xfb48 , 0xfb49 , 0xfb4a , 0xfb4b , 0xfb4c , 0xfb4d , 0xfb4e , 0x1d15e , 0x1d15f , 0x1d160 , 0x1d161 , 0x1d162 , 0x1d163 , 0x1d164 , 0x1d1bb , 0x1d1bc , 0x1d1bd , 0x1d1be , 0x1d1bf , 0x1d1c0 , 0x2f800 , 0x2f801 , 0x2f802 , 0x2f803 , 0x2f804 , 0x2f805 , 0x2f806 , 0x2f807 , 0x2f808 , 0x2f809 , 0x2f80a , 0x2f80b , 0x2f80c , 0x2f80d , 0x2f80e , 0x2f80f , 0x2f810 , 0x2f811 , 0x2f812 , 0x2f813 , 0x2f814 , 0x2f815 , 0x2f816 , 0x2f817 , 0x2f818 , 0x2f819 , 0x2f81a , 0x2f81b , 0x2f81c , 0x2f81d , 0x2f81e , 0x2f81f , 0x2f820 , 0x2f821 , 0x2f822 , 0x2f823 , 0x2f824 , 0x2f825 , 0x2f826 , 0x2f827 , 0x2f828 , 0x2f829 , 0x2f82a , 0x2f82b , 0x2f82c , 0x2f82d , 0x2f82e , 0x2f82f , 0x2f830 , 0x2f831 , 0x2f832 , 0x2f833 , 0x2f834 , 0x2f835 , 0x2f836 , 0x2f837 , 0x2f838 , 0x2f839 , 0x2f83a , 0x2f83b , 0x2f83c , 0x2f83d , 0x2f83e , 0x2f83f , 0x2f840 , 0x2f841 , 0x2f842 , 0x2f843 , 0x2f844 , 0x2f845 , 0x2f846 , 0x2f847 , 0x2f848 , 0x2f849 , 0x2f84a , 0x2f84b , 0x2f84c , 0x2f84d , 0x2f84e , 0x2f84f , 0x2f850 , 0x2f851 , 0x2f852 , 0x2f853 , 0x2f854 , 0x2f855 , 0x2f856 , 0x2f857 , 0x2f858 , 0x2f859 , 0x2f85a , 0x2f85b , 0x2f85c , 0x2f85d , 0x2f85e , 0x2f85f , 0x2f860 , 0x2f861 , 0x2f862 , 0x2f863 , 0x2f864 , 0x2f865 , 0x2f866 , 0x2f867 , 0x2f868 , 0x2f869 , 0x2f86a , 0x2f86b , 0x2f86c , 0x2f86d , 0x2f86e , 0x2f86f , 0x2f870 , 0x2f871 , 0x2f872 , 0x2f873 , 0x2f874 , 0x2f875 , 0x2f876 , 0x2f877 , 0x2f878 , 0x2f879 , 0x2f87a , 0x2f87b , 0x2f87c , 0x2f87d , 0x2f87e , 0x2f87f , 0x2f880 , 0x2f881 , 0x2f882 , 0x2f883 , 0x2f884 , 0x2f885 , 0x2f886 , 0x2f887 , 0x2f888 , 0x2f889 , 0x2f88a , 0x2f88b , 0x2f88c , 0x2f88d , 0x2f88e , 0x2f88f , 0x2f890 , 0x2f891 , 0x2f892 , 0x2f893 , 0x2f894 , 0x2f895 , 0x2f896 , 0x2f897 , 0x2f898 , 0x2f899 , 0x2f89a , 0x2f89b , 0x2f89c , 0x2f89d , 0x2f89e , 0x2f89f , 0x2f8a0 , 0x2f8a1 , 0x2f8a2 , 0x2f8a3 , 0x2f8a4 , 0x2f8a5 , 0x2f8a6 , 0x2f8a7 , 0x2f8a8 , 0x2f8a9 , 0x2f8aa , 0x2f8ab , 0x2f8ac , 0x2f8ad , 0x2f8ae , 0x2f8af , 0x2f8b0 , 0x2f8b1 , 0x2f8b2 , 0x2f8b3 , 0x2f8b4 , 0x2f8b5 , 0x2f8b6 , 0x2f8b7 , 0x2f8b8 , 0x2f8b9 , 0x2f8ba , 0x2f8bb , 0x2f8bc , 0x2f8bd , 0x2f8be , 0x2f8bf , 0x2f8c0 , 0x2f8c1 , 0x2f8c2 , 0x2f8c3 , 0x2f8c4 , 0x2f8c5 , 0x2f8c6 , 0x2f8c7 , 0x2f8c8 , 0x2f8c9 , 0x2f8ca , 0x2f8cb , 0x2f8cc , 0x2f8cd , 0x2f8ce , 0x2f8cf , 0x2f8d0 , 0x2f8d1 , 0x2f8d2 , 0x2f8d3 , 0x2f8d4 , 0x2f8d5 , 0x2f8d6 , 0x2f8d7 , 0x2f8d8 , 0x2f8d9 , 0x2f8da , 0x2f8db , 0x2f8dc , 0x2f8dd , 0x2f8de , 0x2f8df , 0x2f8e0 , 0x2f8e1 , 0x2f8e2 , 0x2f8e3 , 0x2f8e4 , 0x2f8e5 , 0x2f8e6 , 0x2f8e7 , 0x2f8e8 , 0x2f8e9 , 0x2f8ea , 0x2f8eb , 0x2f8ec , 0x2f8ed , 0x2f8ee , 0x2f8ef , 0x2f8f0 , 0x2f8f1 , 0x2f8f2 , 0x2f8f3 , 0x2f8f4 , 0x2f8f5 , 0x2f8f6 , 0x2f8f7 , 0x2f8f8 , 0x2f8f9 , 0x2f8fa , 0x2f8fb , 0x2f8fc , 0x2f8fd , 0x2f8fe , 0x2f8ff , 0x2f900 , 0x2f901 , 0x2f902 , 0x2f903 , 0x2f904 , 0x2f905 , 0x2f906 , 0x2f907 , 0x2f908 , 0x2f909 , 0x2f90a , 0x2f90b , 0x2f90c , 0x2f90d , 0x2f90e , 0x2f90f , 0x2f910 , 0x2f911 , 0x2f912 , 0x2f913 , 0x2f914 , 0x2f915 , 0x2f916 , 0x2f917 , 0x2f918 , 0x2f919 , 0x2f91a , 0x2f91b , 0x2f91c , 0x2f91d , 0x2f91e , 0x2f91f , 0x2f920 , 0x2f921 , 0x2f922 , 0x2f923 , 0x2f924 , 0x2f925 , 0x2f926 , 0x2f927 , 0x2f928 , 0x2f929 , 0x2f92a , 0x2f92b , 0x2f92c , 0x2f92d , 0x2f92e , 0x2f92f , 0x2f930 , 0x2f931 , 0x2f932 , 0x2f933 , 0x2f934 , 0x2f935 , 0x2f936 , 0x2f937 , 0x2f938 , 0x2f939 , 0x2f93a , 0x2f93b , 0x2f93c , 0x2f93d , 0x2f93e , 0x2f93f , 0x2f940 , 0x2f941 , 0x2f942 , 0x2f943 , 0x2f944 , 0x2f945 , 0x2f946 , 0x2f947 , 0x2f948 , 0x2f949 , 0x2f94a , 0x2f94b , 0x2f94c , 0x2f94d , 0x2f94e , 0x2f94f , 0x2f950 , 0x2f951 , 0x2f952 , 0x2f953 , 0x2f954 , 0x2f955 , 0x2f956 , 0x2f957 , 0x2f958 , 0x2f959 , 0x2f95a , 0x2f95b , 0x2f95c , 0x2f95d , 0x2f95e , 0x2f95f , 0x2f960 , 0x2f961 , 0x2f962 , 0x2f963 , 0x2f964 , 0x2f965 , 0x2f966 , 0x2f967 , 0x2f968 , 0x2f969 , 0x2f96a , 0x2f96b , 0x2f96c , 0x2f96d , 0x2f96e , 0x2f96f , 0x2f970 , 0x2f971 , 0x2f972 , 0x2f973 , 0x2f974 , 0x2f975 , 0x2f976 , 0x2f977 , 0x2f978 , 0x2f979 , 0x2f97a , 0x2f97b , 0x2f97c , 0x2f97d , 0x2f97e , 0x2f97f , 0x2f980 , 0x2f981 , 0x2f982 , 0x2f983 , 0x2f984 , 0x2f985 , 0x2f986 , 0x2f987 , 0x2f988 , 0x2f989 , 0x2f98a , 0x2f98b , 0x2f98c , 0x2f98d , 0x2f98e , 0x2f98f , 0x2f990 , 0x2f991 , 0x2f992 , 0x2f993 , 0x2f994 , 0x2f995 , 0x2f996 , 0x2f997 , 0x2f998 , 0x2f999 , 0x2f99a , 0x2f99b , 0x2f99c , 0x2f99d , 0x2f99e , 0x2f99f , 0x2f9a0 , 0x2f9a1 , 0x2f9a2 , 0x2f9a3 , 0x2f9a4 , 0x2f9a5 , 0x2f9a6 , 0x2f9a7 , 0x2f9a8 , 0x2f9a9 , 0x2f9aa , 0x2f9ab , 0x2f9ac , 0x2f9ad , 0x2f9ae , 0x2f9af , 0x2f9b0 , 0x2f9b1 , 0x2f9b2 , 0x2f9b3 , 0x2f9b4 , 0x2f9b5 , 0x2f9b6 , 0x2f9b7 , 0x2f9b8 , 0x2f9b9 , 0x2f9ba , 0x2f9bb , 0x2f9bc , 0x2f9bd , 0x2f9be , 0x2f9bf , 0x2f9c0 , 0x2f9c1 , 0x2f9c2 , 0x2f9c3 , 0x2f9c4 , 0x2f9c5 , 0x2f9c6 , 0x2f9c7 , 0x2f9c8 , 0x2f9c9 , 0x2f9ca , 0x2f9cb , 0x2f9cc , 0x2f9cd , 0x2f9ce , 0x2f9cf , 0x2f9d0 , 0x2f9d1 , 0x2f9d2 , 0x2f9d3 , 0x2f9d4 , 0x2f9d5 , 0x2f9d6 , 0x2f9d7 , 0x2f9d8 , 0x2f9d9 , 0x2f9da , 0x2f9db , 0x2f9dc , 0x2f9dd , 0x2f9de , 0x2f9df , 0x2f9e0 , 0x2f9e1 , 0x2f9e2 , 0x2f9e3 , 0x2f9e4 , 0x2f9e5 , 0x2f9e6 , 0x2f9e7 , 0x2f9e8 , 0x2f9e9 , 0x2f9ea , 0x2f9eb , 0x2f9ec , 0x2f9ed , 0x2f9ee , 0x2f9ef , 0x2f9f0 , 0x2f9f1 , 0x2f9f2 , 0x2f9f3 , 0x2f9f4 , 0x2f9f5 , 0x2f9f6 , 0x2f9f7 , 0x2f9f8 , 0x2f9f9 , 0x2f9fa , 0x2f9fb , 0x2f9fc , 0x2f9fd , 0x2f9fe , 0x2f9ff , 0x2fa00 , 0x2fa01 , 0x2fa02 , 0x2fa03 , 0x2fa04 , 0x2fa05 , 0x2fa06 , 0x2fa07 , 0x2fa08 , 0x2fa09 , 0x2fa0a , 0x2fa0b , 0x2fa0c , 0x2fa0d , 0x2fa0e , 0x2fa0f , 0x2fa10 , 0x2fa11 , 0x2fa12 , 0x2fa13 , 0x2fa14 , 0x2fa15 , 0x2fa16 , 0x2fa17 , 0x2fa18 , 0x2fa19 , 0x2fa1a , 0x2fa1b , 0x2fa1c , 0x2fa1d }
; 
static short utable_decomp_indices [] = {
  3 , 4 , 5 , 6 , 10 , 12 , 26 , 33 , 34 , 35 , 40 , 65 , 66 , 67 , 72 , 97 , 104 , 105 , 106 , 107 , 111 , 144 , 145 , 146 , 150 , 174 , 188 , 189 , 190 , 191 , 195 , 197 , 211 , 218 , 219 , 220 , 225 , 251 , 252 , 253 , 257 , 283 , 290 , 291 , 292 , 293 , 297 , 331 , 332 , 333 , 337 , 362 , 367 , 7 , 192 , 8 , 193 , 18 , 203 , 22 , 207 , 23 , 208 , 24 , 209 , 25 , 210 , 28 , 213 , 37 , 222 , 38 , 223 , 39 , 224 , 47 , 232 , 42 , 227 , 52 , 237 , 54 , 239 , 55 , 240 , 57 , 242 , 58 , 243 , 68 , 254 , 69 , 255 , 70 , 256 , 78 , 263 , 71 , 80 , 265 , 84 , 270 , 86 , 272 , 89 , 275 , 87 , 273 , 96 , 282 , 101 , 287 , 99 , 285 , 108 , 294 , 109 , 295 , 113 , 299 , 122 , 308 , 128 , 314 , 124 , 310 , 130 , 316 , 131 , 317 , 136 , 322 , 133 , 319 , 141 , 328 , 138 , 325 , 147 , 334 , 148 , 335 , 149 , 336 , 152 , 339 , 153 , 340 , 160 , 347 , 167 , 354 , 175 , 363 , 179 , 182 , 371 , 184 , 373 , 185 , 374 , 117 , 303 , 157 , 344 , 13 , 198 , 74 , 259 , 114 , 300 , 154 , 341 , 405 , 432 , 404 , 431 , 406 , 433 , 403 , 430 , 384 , 411 , 482 , 483 , 387 , 414 , 56 , 241 , 82 , 268 , 119 , 305 , 480 , 481 , 479 , 488 , 266 , 51 , 236 , 95 , 281 , 385 , 412 , 386 , 413 , 402 , 429 , 14 , 199 , 15 , 200 , 43 , 228 , 44 , 229 , 75 , 260 , 76 , 261 , 115 , 301 , 116 , 302 , 125 , 311 , 126 , 312 , 155 , 342 , 156 , 343 , 135 , 321 , 140 , 327 , 61 , 246 , 9 , 194 , 46 , 231 , 401 , 428 , 399 , 426 , 110 , 296 , 486 , 487 , 177 , 365 , 1904 , 1898 , 1903 , 1902 , 1901 , 1900 , 378 , 490 , 1899 , 497 , 501 , 506 , 513 , 518 , 524 , 577 , 509 , 521 , 531 , 539 , 543 , 549 , 580 , 552 , 566 , 557 , 563 , 571 , 583 , 584 , 589 , 591 , 588 , 585 , 599 , 595 , 602 , 597 , 619 , 611 , 613 , 610 , 630 , 621 , 617 , 624 , 631 , 632 , 592 , 614 , 586 , 608 , 587 , 609 , 590 , 612 , 633 , 634 , 593 , 615 , 594 , 616 , 596 , 618 , 598 , 620 , 600 , 622 , 635 , 636 , 607 , 629 , 601 , 623 , 603 , 625 , 604 , 626 , 605 , 627 , 606 , 628 , 637 , 638 , 640 , 639 , 641 , 644 , 642 , 643 , 645 , 646 , 647 , 1810 , 1888 , 1887 , 1809 , 1808 , 1886 , 1885 , 1807 , 648 , 649 , 1881 , 1801 , 1880 , 1875 , 1874 , 1872 , 1782 , 1871 , 1870 , 651 , 650 , 652 , 1731 , 1853 , 653 , 654 , 656 , 655 , 657 , 658 , 660 , 661 , 659 , 662 , 663 , 665 , 664 , 666 , 667 , 669 , 668 , 1794 , 1793 , 1792 , 1791 , 1790 , 1787 , 1786 , 1362 , 1785 , 1361 , 1783 , 1780 , 1779 , 1777 , 1776 , 1775 , 1773 , 670 , 17 , 202 , 19 , 204 , 20 , 205 , 21 , 206 , 388 , 415 , 27 , 212 , 29 , 214 , 32 , 217 , 30 , 215 , 31 , 216 , 442 , 444 , 443 , 445 , 48 , 233 , 49 , 234 , 484 , 485 , 50 , 235 , 53 , 238 , 59 , 244 , 62 , 247 , 60 , 245 , 63 , 248 , 64 , 249 , 79 , 264 , 393 , 420 , 81 , 267 , 83 , 269 , 85 , 271 , 88 , 274 , 671 , 672 , 91 , 277 , 90 , 276 , 92 , 278 , 93 , 279 , 94 , 280 , 98 , 284 , 100 , 286 , 103 , 289 , 102 , 288 , 398 , 425 , 400 , 427 , 446 , 448 , 447 , 449 , 120 , 306 , 121 , 307 , 123 , 309 , 127 , 313 , 673 , 674 , 129 , 315 , 132 , 318 , 134 , 320 , 450 , 451 , 452 , 453 , 675 , 676 , 137 , 323 , 139 , 326 , 143 , 330 , 142 , 329 , 159 , 346 , 162 , 349 , 161 , 348 , 454 , 455 , 456 , 457 , 163 , 350 , 164 , 351 , 165 , 352 , 166 , 353 , 169 , 356 , 168 , 355 , 170 , 358 , 171 , 359 , 172 , 360 , 178 , 366 , 183 , 372 , 186 , 375 , 187 , 376 , 250 , 324 , 357 , 369 , 458 , 16 , 201 , 11 , 196 , 381 , 408 , 380 , 407 , 383 , 410 , 382 , 409 , 677 , 679 , 435 , 439 , 434 , 438 , 437 , 441 , 436 , 440 , 678 , 680 , 45 , 230 , 41 , 226 , 36 , 221 , 390 , 417 , 389 , 416 , 392 , 419 , 391 , 418 , 681 , 682 , 73 , 258 , 77 , 262 , 118 , 304 , 112 , 298 , 395 , 422 , 394 , 421 , 397 , 424 , 396 , 423 , 683 , 684 , 460 , 465 , 459 , 464 , 462 , 467 , 461 , 466 , 463 , 468 , 158 , 345 , 151 , 338 , 470 , 475 , 469 , 474 , 472 , 477 , 471 , 476 , 473 , 478 , 173 , 361 , 181 , 370 , 180 , 368 , 176 , 364 , 534 , 535 , 685 , 689 , 686 , 690 , 687 , 691 , 493 , 494 , 699 , 703 , 700 , 704 , 701 , 705 , 540 , 541 , 713 , 715 , 714 , 716 , 498 , 499 , 717 , 719 , 718 , 720 , 544 , 545 , 721 , 725 , 722 , 726 , 723 , 727 , 502 , 503 , 735 , 739 , 736 , 740 , 737 , 741 , 553 , 554 , 749 , 752 , 750 , 753 , 751 , 754 , 510 , 511 , 755 , 758 , 756 , 759 , 757 , 760 , 558 , 559 , 761 , 763 , 762 , 764 , 514 , 515 , 765 , 767 , 766 , 768 , 567 , 568 , 769 , 772 , 770 , 773 , 771 , 774 , 522 , 775 , 776 , 777 , 572 , 573 , 778 , 782 , 779 , 783 , 780 , 784 , 525 , 526 , 792 , 796 , 793 , 797 , 794 , 798 , 530 , 935 , 538 , 934 , 542 , 933 , 548 , 932 , 556 , 931 , 562 , 930 , 570 , 929 , 688 , 692 , 693 , 694 , 695 , 696 , 697 , 698 , 702 , 706 , 707 , 708 , 709 , 710 , 711 , 712 , 724 , 728 , 729 , 730 , 731 , 732 , 733 , 734 , 738 , 742 , 743 , 744 , 745 , 746 , 747 , 748 , 781 , 785 , 786 , 787 , 788 , 789 , 790 , 791 , 795 , 799 , 800 , 801 , 802 , 803 , 804 , 805 , 533 , 532 , 806 , 537 , 528 , 536 , 809 , 492 , 491 , 489 , 928 , 495 , 927 , 379 , 807 , 547 , 529 , 546 , 813 , 496 , 926 , 500 , 925 , 504 , 810 , 811 , 812 , 551 , 550 , 576 , 924 , 555 , 578 , 508 , 507 , 505 , 923 , 815 , 816 , 817 , 565 , 564 , 579 , 922 , 560 , 561 , 569 , 581 , 520 , 519 , 517 , 921 , 516 , 377 , 1770 , 920 , 808 , 575 , 582 , 574 , 814 , 512 , 919 , 523 , 918 , 527 , 917 , 1907 , 1767 , 1713 , 1712 , 1906 , 818 , 819 , 820 , 821 , 823 , 822 , 824 , 825 , 826 , 827 , 828 , 829 , 830 , 831 , 832 , 1 , 834 , 833 , 0 , 2 , 835 , 836 , 837 , 838 , 839 , 840 , 841 , 842 , 845 , 846 , 847 , 848 , 851 , 852 , 853 , 854 , 843 , 844 , 849 , 850 , 855 , 856 , 857 , 858 , 1557 , 1905 , 1864 , 860 , 861 , 862 , 863 , 864 , 865 , 866 , 867 , 868 , 869 , 870 , 871 , 872 , 873 , 874 , 875 , 876 , 877 , 878 , 879 , 880 , 881 , 882 , 883 , 884 , 859 , 885 , 887 , 888 , 889 , 890 , 891 , 892 , 893 , 894 , 895 , 896 , 897 , 898 , 899 , 900 , 901 , 902 , 903 , 904 , 905 , 906 , 907 , 908 , 909 , 910 , 911 , 886 , 912 , 913 , 914 , 915 , 916 , 1185 , 1502 , 1184 , 1501 , 1500 , 1183 , 1499 , 1182 , 1498 , 1181 , 1497 , 1180 , 1496 , 1179 , 1495 , 1178 , 1494 , 1177 , 1493 , 1176 , 1492 , 1175 , 1491 , 1174 , 1490 , 1173 , 1489 , 1172 , 1488 , 1171 , 1487 , 1170 , 1169 , 1486 , 1168 , 1485 , 1167 , 1484 , 1166 , 1483 , 1482 , 1165 , 1481 , 1164 , 1480 , 1163 , 1162 , 1479 , 1478 , 1161 , 1477 , 1160 , 1159 , 1476 , 1158 , 1475 , 1157 , 1474 , 1473 , 1156 , 1155 , 1472 , 1154 , 1471 , 1153 , 1470 , 1469 , 1152 , 1468 , 1151 , 1467 , 1150 , 1466 , 1149 , 1465 , 1148 , 1464 , 1147 , 1463 , 1146 , 1462 , 1145 , 1461 , 1144 , 1460 , 1143 , 1459 , 1142 , 1141 , 1458 , 1140 , 1457 , 1139 , 1456 , 1138 , 1455 , 1137 , 1454 , 1453 , 1136 , 1452 , 1135 , 1451 , 1134 , 1133 , 1450 , 1449 , 1132 , 1448 , 1131 , 1130 , 1447 , 1129 , 1446 , 1445 , 1128 , 1444 , 1127 , 1443 , 1126 , 1442 , 1125 , 1441 , 1124 , 1123 , 1440 , 1439 , 1122 , 1438 , 1121 , 1437 , 1120 , 1436 , 1119 , 1435 , 1118 , 1434 , 1117 , 1433 , 1116 , 1432 , 1115 , 1431 , 1114 , 1430 , 1113 , 1429 , 1112 , 1428 , 1111 , 1427 , 1110 , 1426 , 1109 , 1425 , 1108 , 1424 , 1107 , 1423 , 1106 , 1422 , 1105 , 1421 , 1104 , 1420 , 1103 , 1419 , 1102 , 1418 , 1101 , 1417 , 1100 , 1416 , 1099 , 1415 , 1098 , 1414 , 1097 , 1413 , 1096 , 1412 , 1095 , 1411 , 1094 , 1410 , 1093 , 1409 , 1092 , 1408 , 1091 , 1407 , 1090 , 1406 , 1089 , 1405 , 1088 , 1404 , 1087 , 1403 , 1086 , 1085 , 1402 , 1084 , 1401 , 1400 , 1083 , 1399 , 1082 , 1398 , 1081 , 1397 , 1080 , 1396 , 1079 , 1078 , 1395 , 1394 , 1077 , 1393 , 1076 , 1392 , 1075 , 1391 , 1074 , 1390 , 1073 , 1389 , 1072 , 1388 , 1071 , 1387 , 1070 , 1386 , 1069 , 1385 , 1068 , 1384 , 1067 , 1066 , 1383 , 1382 , 1065 , 1381 , 1064 , 1380 , 1063 , 1379 , 1062 , 1378 , 1061 , 1377 , 1060 , 1376 , 1059 , 1058 , 1375 , 1374 , 1057 , 1373 , 1056 , 1372 , 1055 , 1371 , 1054 , 1370 , 1053 , 1369 , 1052 , 1368 , 1051 , 1049 , 1048 , 1047 , 1366 , 1046 , 1365 , 1045 , 1364 , 1044 , 1363 , 1043 , 1042 , 1041 , 1040 , 1039 , 1038 , 1037 , 1360 , 1359 , 1036 , 1358 , 1035 , 1357 , 1034 , 1356 , 1033 , 1355 , 1032 , 1354 , 1031 , 1030 , 1353 , 1352 , 1029 , 1351 , 1028 , 1350 , 1027 , 1349 , 1026 , 1348 , 1025 , 1024 , 1347 , 1346 , 1023 , 1345 , 1022 , 1344 , 1021 , 1343 , 1020 , 1342 , 1019 , 1341 , 1018 , 1340 , 1017 , 1339 , 1016 , 1338 , 1015 , 1337 , 1014 , 1336 , 1013 , 1335 , 1012 , 1334 , 1011 , 1333 , 1010 , 1332 , 1009 , 1331 , 1008 , 1330 , 1007 , 1006 , 1329 , 1005 , 1328 , 1004 , 1327 , 1003 , 1326 , 1002 , 1325 , 1001 , 1324 , 1000 , 1323 , 999 , 1322 , 998 , 1321 , 997 , 1320 , 996 , 1319 , 995 , 1318 , 994 , 1317 , 993 , 1316 , 992 , 1315 , 991 , 1314 , 990 , 1313 , 989 , 1312 , 988 , 1311 , 987 , 1310 , 986 , 1309 , 985 , 1308 , 984 , 1307 , 983 , 1306 , 982 , 1305 , 981 , 1304 , 980 , 1303 , 979 , 1302 , 978 , 1301 , 977 , 1300 , 976 , 1299 , 975 , 1298 , 974 , 1295 , 973 , 1294 , 972 , 1293 , 971 , 1292 , 970 , 1290 , 969 , 1289 , 968 , 1288 , 967 , 1287 , 966 , 1284 , 965 , 1283 , 964 , 1282 , 963 , 1281 , 962 , 1278 , 961 , 1277 , 960 , 1276 , 959 , 1275 , - 4 , - 15 , - 3 , 1273 , 958 , 1272 , - 2 , - 14 , - 1 , 1269 , 957 , 956 , 955 , 1215 , 954 , 1214 , 953 , 1213 , 952 , 1210 , 951 , 1209 , 950 , 1208 , 949 , 948 , 1204 , 947 , 1203 , 946 , 945 , 944 , 943 , 1198 , 942 , 941 , 940 , 1195 , 939 , 1193 , 938 , 1192 , 937 , 1191 , 936 , - 69 , - 113 , - 68 , - 110 , - 67 , - 109 , - 66 , - 65 , - 64 , - 124 , - 63 , - 123 , - 95 , 1766 , 1840 , 1765 , - 101 , 1613 , 1764 , 1297 , 1612 , 1296 , 1610 , 1609 , 1763 , 1608 , - 81 , 1607 , 1762 , 1604 , 1760 , - 17 , 1603 , 1291 , 1602 , - 38 , 1759 , 1600 , 1757 , 1599 , 1756 , - 37 , 1755 , 1286 , 1598 , 1285 , 1597 , 1596 , 1751 , 1595 , 1750 , 1594 , 1749 , 1593 , 1835 , 1280 , 1592 , 1279 , 1591 , 1590 , 1834 , 1589 , 1832 , 1588 , 1831 , - 36 , 1830 , 1274 , 1587 , - 16 , 1586 , 1585 , 1827 , 1584 , 1826 , 1583 , 1825 , 1745 , 1823 , 1271 , 1582 , 1270 , 1581 , 1580 , 1744 , 1268 , 1579 , 1267 , 1578 , 1266 , 1577 , 1265 , 1576 , 1264 , 1575 , 1263 , 1574 , 1262 , 1573 , 1261 , 1739 , 1260 , - 35 , 1259 , 1572 , 1258 , 1571 , 1257 , 1570 , - 13 , - 34 , 1256 , 1569 , 1255 , 1568 , 1254 , 1567 , 1253 , 1566 , 1252 , 1565 , - 12 , 1564 , 1251 , 1563 , 1250 , - 33 , 1249 , 1562 , 1248 , 1561 , 1247 , 1560 , 1246 , 1559 , 1245 , - 32 , 1244 , - 31 , 1243 , 1558 , 1242 , 1556 , 1241 , 1555 , 1240 , 1554 , 1239 , 1553 , 1238 , - 30 , 1237 , 1552 , 1236 , 1551 , 1235 , - 29 , 1234 , - 28 , - 11 , 1550 , 1233 , 1549 , 1232 , - 27 , - 10 , 1548 , 1231 , 1547 , 1230 , 1546 , 1229 , 1545 , 1228 , 1544 , 1227 , 1543 , - 9 , 1542 , 1226 , 1541 , 1225 , 1540 , 1224 , 1539 , 1223 , 1538 , 1222 , 1537 , 1221 , 1536 , 1220 , 1535 , 1219 , 1534 , 1218 , 1533 , - 8 , 1532 , 1217 , 1531 , 1216 , 1530 , - 7 , 1529 , 1528 , 1721 , 1527 , 1720 , 1526 , 1719 , 1212 , 1525 , 1211 , 1524 , - 26 , 1718 , 1523 , 1717 , 1522 , 1716 , 1207 , 1521 , 1206 , 1520 , 1205 , 1519 , 1518 , 1715 , 1517 , 1714 , 1202 , 1516 , 1201 , - 25 , 1200 , 1515 , 1199 , 1514 , 1513 , - 62 , 1197 , 1512 , 1196 , 1511 , 1510 , 1711 , 1194 , 1509 , - 6 , 1508 , 1507 , 1710 , - 24 , 1709 , 1506 , 1708 , 1190 , 1505 , 1189 , - 23 , - 5 , - 22 , 1188 , - 21 , 1187 , 1504 , 1186 , 1503 , 1707 , 1862 , 1706 , 1861 , 1705 , 1805 , - 61 , 1804 , 1704 , 1858 , 1703 , 1857 , 1702 , - 117 , 1701 , 1803 , - 60 , - 89 , 1700 , 1802 , 1699 , 1856 , 1698 , 1855 , 1697 , 1854 , 1696 , - 116 , 1695 , - 115 , 1694 , - 88 , 1693 , 1895 , 1692 , - 112 , 1691 , 1851 , - 59 , - 111 , 1690 , 1800 , 1689 , 1799 , 1688 , 1850 , 1687 , 1849 , 1686 , 1848 , 1685 , 1847 , 1798 , - 108 , 1684 , - 107 , 1683 , - 106 , 1682 , - 105 , - 58 , - 104 , 1681 , 1846 , 1797 , - 103 , - 57 , - 87 , - 56 , 1892 , 1680 , 1845 , 1679 , 1844 , 1678 , 1796 , 1677 , - 86 , 1676 , 1795 , 1675 , 1843 , - 55 , 1842 , - 54 , - 102 , 1674 , 1841 , 1789 , 1839 , 1673 , 1788 , - 53 , - 100 , - 52 , 1838 , 1672 , - 99 , 1671 , 1837 , 1670 , - 85 , 1669 , 1784 , 1668 , 1836 , 1667 , - 98 , 1666 , 1781 , 1665 , 1891 , 1664 , 1778 , - 51 , - 84 , 1663 , - 97 , 1662 , - 96 , 1661 , 1890 , 1660 , - 94 , - 50 , 1774 , - 49 , 1833 , - 48 , 1829 , 1828 , 1889 , 1659 , 1772 , 1658 , - 93 , - 47 , - 83 , - 46 , 1771 , 1657 , 1824 , 1656 , 1884 , 1655 , 1769 , 1654 , 1822 , 1653 , 1768 , 1652 , - 82 , 1651 , 1821 , 1820 , 1883 , 1819 , 1882 , 1650 , 1818 , 1649 , 1817 , 1648 , 1816 , - 45 , - 92 , - 44 , 1761 , 1647 , 1815 , 1646 , - 80 , 1645 , - 79 , 1644 , 1758 , - 43 , - 78 , 1643 , 1754 , 1642 , 1753 , 1641 , 1752 , 1640 , 1814 , 1639 , 1879 , 1638 , 1878 , 1637 , 1877 , 1636 , 1813 , 1635 , 1876 , 1634 , - 77 , 1633 , 1748 , 1812 , 1873 , 1632 , - 121 , - 42 , 1747 , 1631 , 1746 , 1743 , 1811 , 1630 , - 76 , 1629 , 1742 , 1869 , 1897 , - 41 , - 75 , 1741 , 1868 , 1628 , - 74 , 1627 , 1740 , - 40 , - 91 , 1867 , 1896 , 1626 , - 120 , 1625 , 1866 , 1624 , 1738 , 1623 , 1737 , 1622 , - 73 , 1621 , 1865 , 1620 , - 72 , 1619 , 1736 , 1618 , 1735 , - 39 , - 71 , 1617 , 1734 , 1616 , - 119 , 1615 , - 118 , 1614 , 1863 , 1733 , - 122 , 1732 , 1860 , 1859 , 1894 , 1611 , 1730 , 1729 , - 90 , 1606 , 1728 , 1605 , 1727 , 1050 , 1367 , - 20 , 1601 , - 19 , - 70 , - 18 , 1726 , 1725 , 1893 , 1724 , 1806 , 1723 , 1852 , 1722 , - 114 }
; 
static unsigned int utable_kompat_decomp_keys [] = {
  0xa0 , 0xa8 , 0xaa , 0xaf , 0xb2 , 0xb3 , 0xb4 , 0xb5 , 0xb8 , 0xb9 , 0xba , 0xbc , 0xbd , 0xbe , 0x132 , 0x133 , 0x13f , 0x140 , 0x149 , 0x17f , 0x1c4 , 0x1c5 , 0x1c6 , 0x1c7 , 0x1c8 , 0x1c9 , 0x1ca , 0x1cb , 0x1cc , 0x1f1 , 0x1f2 , 0x1f3 , 0x2b0 , 0x2b1 , 0x2b2 , 0x2b3 , 0x2b4 , 0x2b5 , 0x2b6 , 0x2b7 , 0x2b8 , 0x2d8 , 0x2d9 , 0x2da , 0x2db , 0x2dc , 0x2dd , 0x2e0 , 0x2e1 , 0x2e2 , 0x2e3 , 0x2e4 , 0x37a , 0x384 , 0x3d0 , 0x3d1 , 0x3d2 , 0x3d5 , 0x3d6 , 0x3f0 , 0x3f1 , 0x3f2 , 0x3f4 , 0x3f5 , 0x3f9 , 0x587 , 0x675 , 0x676 , 0x677 , 0x678 , 0xe33 , 0xeb3 , 0xedc , 0xedd , 0xf0c , 0xf77 , 0xf79 , 0x10fc , 0x1d2c , 0x1d2d , 0x1d2e , 0x1d30 , 0x1d31 , 0x1d32 , 0x1d33 , 0x1d34 , 0x1d35 , 0x1d36 , 0x1d37 , 0x1d38 , 0x1d39 , 0x1d3a , 0x1d3c , 0x1d3d , 0x1d3e , 0x1d3f , 0x1d40 , 0x1d41 , 0x1d42 , 0x1d43 , 0x1d44 , 0x1d45 , 0x1d46 , 0x1d47 , 0x1d48 , 0x1d49 , 0x1d4a , 0x1d4b , 0x1d4c , 0x1d4d , 0x1d4f , 0x1d50 , 0x1d51 , 0x1d52 , 0x1d53 , 0x1d54 , 0x1d55 , 0x1d56 , 0x1d57 , 0x1d58 , 0x1d59 , 0x1d5a , 0x1d5b , 0x1d5c , 0x1d5d , 0x1d5e , 0x1d5f , 0x1d60 , 0x1d61 , 0x1d62 , 0x1d63 , 0x1d64 , 0x1d65 , 0x1d66 , 0x1d67 , 0x1d68 , 0x1d69 , 0x1d6a , 0x1d78 , 0x1d9b , 0x1d9c , 0x1d9d , 0x1d9e , 0x1d9f , 0x1da0 , 0x1da1 , 0x1da2 , 0x1da3 , 0x1da4 , 0x1da5 , 0x1da6 , 0x1da7 , 0x1da8 , 0x1da9 , 0x1daa , 0x1dab , 0x1dac , 0x1dad , 0x1dae , 0x1daf , 0x1db0 , 0x1db1 , 0x1db2 , 0x1db3 , 0x1db4 , 0x1db5 , 0x1db6 , 0x1db7 , 0x1db8 , 0x1db9 , 0x1dba , 0x1dbb , 0x1dbc , 0x1dbd , 0x1dbe , 0x1dbf , 0x1e9a , 0x1fbd , 0x1fbf , 0x1fc0 , 0x1ffe , 0x2002 , 0x2003 , 0x2004 , 0x2005 , 0x2006 , 0x2007 , 0x2008 , 0x2009 , 0x200a , 0x2011 , 0x2017 , 0x2024 , 0x2025 , 0x2026 , 0x202f , 0x2033 , 0x2034 , 0x2036 , 0x2037 , 0x203c , 0x203e , 0x2047 , 0x2048 , 0x2049 , 0x2057 , 0x205f , 0x2070 , 0x2071 , 0x2074 , 0x2075 , 0x2076 , 0x2077 , 0x2078 , 0x2079 , 0x207a , 0x207b , 0x207c , 0x207d , 0x207e , 0x207f , 0x2080 , 0x2081 , 0x2082 , 0x2083 , 0x2084 , 0x2085 , 0x2086 , 0x2087 , 0x2088 , 0x2089 , 0x208a , 0x208b , 0x208c , 0x208d , 0x208e , 0x2090 , 0x2091 , 0x2092 , 0x2093 , 0x2094 , 0x20a8 , 0x2100 , 0x2101 , 0x2102 , 0x2103 , 0x2105 , 0x2106 , 0x2107 , 0x2109 , 0x210a , 0x210b , 0x210c , 0x210d , 0x210e , 0x210f , 0x2110 , 0x2111 , 0x2112 , 0x2113 , 0x2115 , 0x2116 , 0x2119 , 0x211a , 0x211b , 0x211c , 0x211d , 0x2120 , 0x2121 , 0x2122 , 0x2124 , 0x2128 , 0x212c , 0x212d , 0x212f , 0x2130 , 0x2131 , 0x2133 , 0x2134 , 0x2135 , 0x2136 , 0x2137 , 0x2138 , 0x2139 , 0x213b , 0x213c , 0x213d , 0x213e , 0x213f , 0x2140 , 0x2145 , 0x2146 , 0x2147 , 0x2148 , 0x2149 , 0x2153 , 0x2154 , 0x2155 , 0x2156 , 0x2157 , 0x2158 , 0x2159 , 0x215a , 0x215b , 0x215c , 0x215d , 0x215e , 0x215f , 0x2160 , 0x2161 , 0x2162 , 0x2163 , 0x2164 , 0x2165 , 0x2166 , 0x2167 , 0x2168 , 0x2169 , 0x216a , 0x216b , 0x216c , 0x216d , 0x216e , 0x216f , 0x2170 , 0x2171 , 0x2172 , 0x2173 , 0x2174 , 0x2175 , 0x2176 , 0x2177 , 0x2178 , 0x2179 , 0x217a , 0x217b , 0x217c , 0x217d , 0x217e , 0x217f , 0x222c , 0x222d , 0x222f , 0x2230 , 0x2460 , 0x2461 , 0x2462 , 0x2463 , 0x2464 , 0x2465 , 0x2466 , 0x2467 , 0x2468 , 0x2469 , 0x246a , 0x246b , 0x246c , 0x246d , 0x246e , 0x246f , 0x2470 , 0x2471 , 0x2472 , 0x2473 , 0x2474 , 0x2475 , 0x2476 , 0x2477 , 0x2478 , 0x2479 , 0x247a , 0x247b , 0x247c , 0x247d , 0x247e , 0x247f , 0x2480 , 0x2481 , 0x2482 , 0x2483 , 0x2484 , 0x2485 , 0x2486 , 0x2487 , 0x2488 , 0x2489 , 0x248a , 0x248b , 0x248c , 0x248d , 0x248e , 0x248f , 0x2490 , 0x2491 , 0x2492 , 0x2493 , 0x2494 , 0x2495 , 0x2496 , 0x2497 , 0x2498 , 0x2499 , 0x249a , 0x249b , 0x249c , 0x249d , 0x249e , 0x249f , 0x24a0 , 0x24a1 , 0x24a2 , 0x24a3 , 0x24a4 , 0x24a5 , 0x24a6 , 0x24a7 , 0x24a8 , 0x24a9 , 0x24aa , 0x24ab , 0x24ac , 0x24ad , 0x24ae , 0x24af , 0x24b0 , 0x24b1 , 0x24b2 , 0x24b3 , 0x24b4 , 0x24b5 , 0x24b6 , 0x24b7 , 0x24b8 , 0x24b9 , 0x24ba , 0x24bb , 0x24bc , 0x24bd , 0x24be , 0x24bf , 0x24c0 , 0x24c1 , 0x24c2 , 0x24c3 , 0x24c4 , 0x24c5 , 0x24c6 , 0x24c7 , 0x24c8 , 0x24c9 , 0x24ca , 0x24cb , 0x24cc , 0x24cd , 0x24ce , 0x24cf , 0x24d0 , 0x24d1 , 0x24d2 , 0x24d3 , 0x24d4 , 0x24d5 , 0x24d6 , 0x24d7 , 0x24d8 , 0x24d9 , 0x24da , 0x24db , 0x24dc , 0x24dd , 0x24de , 0x24df , 0x24e0 , 0x24e1 , 0x24e2 , 0x24e3 , 0x24e4 , 0x24e5 , 0x24e6 , 0x24e7 , 0x24e8 , 0x24e9 , 0x24ea , 0x2a0c , 0x2a74 , 0x2a75 , 0x2a76 , 0x2d6f , 0x2e9f , 0x2ef3 , 0x2f00 , 0x2f01 , 0x2f02 , 0x2f03 , 0x2f04 , 0x2f05 , 0x2f06 , 0x2f07 , 0x2f08 , 0x2f09 , 0x2f0a , 0x2f0b , 0x2f0c , 0x2f0d , 0x2f0e , 0x2f0f , 0x2f10 , 0x2f11 , 0x2f12 , 0x2f13 , 0x2f14 , 0x2f15 , 0x2f16 , 0x2f17 , 0x2f18 , 0x2f19 , 0x2f1a , 0x2f1b , 0x2f1c , 0x2f1d , 0x2f1e , 0x2f1f , 0x2f20 , 0x2f21 , 0x2f22 , 0x2f23 , 0x2f24 , 0x2f25 , 0x2f26 , 0x2f27 , 0x2f28 , 0x2f29 , 0x2f2a , 0x2f2b , 0x2f2c , 0x2f2d , 0x2f2e , 0x2f2f , 0x2f30 , 0x2f31 , 0x2f32 , 0x2f33 , 0x2f34 , 0x2f35 , 0x2f36 , 0x2f37 , 0x2f38 , 0x2f39 , 0x2f3a , 0x2f3b , 0x2f3c , 0x2f3d , 0x2f3e , 0x2f3f , 0x2f40 , 0x2f41 , 0x2f42 , 0x2f43 , 0x2f44 , 0x2f45 , 0x2f46 , 0x2f47 , 0x2f48 , 0x2f49 , 0x2f4a , 0x2f4b , 0x2f4c , 0x2f4d , 0x2f4e , 0x2f4f , 0x2f50 , 0x2f51 , 0x2f52 , 0x2f53 , 0x2f54 , 0x2f55 , 0x2f56 , 0x2f57 , 0x2f58 , 0x2f59 , 0x2f5a , 0x2f5b , 0x2f5c , 0x2f5d , 0x2f5e , 0x2f5f , 0x2f60 , 0x2f61 , 0x2f62 , 0x2f63 , 0x2f64 , 0x2f65 , 0x2f66 , 0x2f67 , 0x2f68 , 0x2f69 , 0x2f6a , 0x2f6b , 0x2f6c , 0x2f6d , 0x2f6e , 0x2f6f , 0x2f70 , 0x2f71 , 0x2f72 , 0x2f73 , 0x2f74 , 0x2f75 , 0x2f76 , 0x2f77 , 0x2f78 , 0x2f79 , 0x2f7a , 0x2f7b , 0x2f7c , 0x2f7d , 0x2f7e , 0x2f7f , 0x2f80 , 0x2f81 , 0x2f82 , 0x2f83 , 0x2f84 , 0x2f85 , 0x2f86 , 0x2f87 , 0x2f88 , 0x2f89 , 0x2f8a , 0x2f8b , 0x2f8c , 0x2f8d , 0x2f8e , 0x2f8f , 0x2f90 , 0x2f91 , 0x2f92 , 0x2f93 , 0x2f94 , 0x2f95 , 0x2f96 , 0x2f97 , 0x2f98 , 0x2f99 , 0x2f9a , 0x2f9b , 0x2f9c , 0x2f9d , 0x2f9e , 0x2f9f , 0x2fa0 , 0x2fa1 , 0x2fa2 , 0x2fa3 , 0x2fa4 , 0x2fa5 , 0x2fa6 , 0x2fa7 , 0x2fa8 , 0x2fa9 , 0x2faa , 0x2fab , 0x2fac , 0x2fad , 0x2fae , 0x2faf , 0x2fb0 , 0x2fb1 , 0x2fb2 , 0x2fb3 , 0x2fb4 , 0x2fb5 , 0x2fb6 , 0x2fb7 , 0x2fb8 , 0x2fb9 , 0x2fba , 0x2fbb , 0x2fbc , 0x2fbd , 0x2fbe , 0x2fbf , 0x2fc0 , 0x2fc1 , 0x2fc2 , 0x2fc3 , 0x2fc4 , 0x2fc5 , 0x2fc6 , 0x2fc7 , 0x2fc8 , 0x2fc9 , 0x2fca , 0x2fcb , 0x2fcc , 0x2fcd , 0x2fce , 0x2fcf , 0x2fd0 , 0x2fd1 , 0x2fd2 , 0x2fd3 , 0x2fd4 , 0x2fd5 , 0x3000 , 0x3036 , 0x3038 , 0x3039 , 0x303a , 0x309b , 0x309c , 0x309f , 0x30ff , 0x3131 , 0x3132 , 0x3133 , 0x3134 , 0x3135 , 0x3136 , 0x3137 , 0x3138 , 0x3139 , 0x313a , 0x313b , 0x313c , 0x313d , 0x313e , 0x313f , 0x3140 , 0x3141 , 0x3142 , 0x3143 , 0x3144 , 0x3145 , 0x3146 , 0x3147 , 0x3148 , 0x3149 , 0x314a , 0x314b , 0x314c , 0x314d , 0x314e , 0x314f , 0x3150 , 0x3151 , 0x3152 , 0x3153 , 0x3154 , 0x3155 , 0x3156 , 0x3157 , 0x3158 , 0x3159 , 0x315a , 0x315b , 0x315c , 0x315d , 0x315e , 0x315f , 0x3160 , 0x3161 , 0x3162 , 0x3163 , 0x3164 , 0x3165 , 0x3166 , 0x3167 , 0x3168 , 0x3169 , 0x316a , 0x316b , 0x316c , 0x316d , 0x316e , 0x316f , 0x3170 , 0x3171 , 0x3172 , 0x3173 , 0x3174 , 0x3175 , 0x3176 , 0x3177 , 0x3178 , 0x3179 , 0x317a , 0x317b , 0x317c , 0x317d , 0x317e , 0x317f , 0x3180 , 0x3181 , 0x3182 , 0x3183 , 0x3184 , 0x3185 , 0x3186 , 0x3187 , 0x3188 , 0x3189 , 0x318a , 0x318b , 0x318c , 0x318d , 0x318e , 0x3192 , 0x3193 , 0x3194 , 0x3195 , 0x3196 , 0x3197 , 0x3198 , 0x3199 , 0x319a , 0x319b , 0x319c , 0x319d , 0x319e , 0x319f , 0x3200 , 0x3201 , 0x3202 , 0x3203 , 0x3204 , 0x3205 , 0x3206 , 0x3207 , 0x3208 , 0x3209 , 0x320a , 0x320b , 0x320c , 0x320d , 0x320e , 0x320f , 0x3210 , 0x3211 , 0x3212 , 0x3213 , 0x3214 , 0x3215 , 0x3216 , 0x3217 , 0x3218 , 0x3219 , 0x321a , 0x321b , 0x321c , 0x321d , 0x321e , 0x3220 , 0x3221 , 0x3222 , 0x3223 , 0x3224 , 0x3225 , 0x3226 , 0x3227 , 0x3228 , 0x3229 , 0x322a , 0x322b , 0x322c , 0x322d , 0x322e , 0x322f , 0x3230 , 0x3231 , 0x3232 , 0x3233 , 0x3234 , 0x3235 , 0x3236 , 0x3237 , 0x3238 , 0x3239 , 0x323a , 0x323b , 0x323c , 0x323d , 0x323e , 0x323f , 0x3240 , 0x3241 , 0x3242 , 0x3243 , 0x3250 , 0x3251 , 0x3252 , 0x3253 , 0x3254 , 0x3255 , 0x3256 , 0x3257 , 0x3258 , 0x3259 , 0x325a , 0x325b , 0x325c , 0x325d , 0x325e , 0x325f , 0x3260 , 0x3261 , 0x3262 , 0x3263 , 0x3264 , 0x3265 , 0x3266 , 0x3267 , 0x3268 , 0x3269 , 0x326a , 0x326b , 0x326c , 0x326d , 0x326e , 0x326f , 0x3270 , 0x3271 , 0x3272 , 0x3273 , 0x3274 , 0x3275 , 0x3276 , 0x3277 , 0x3278 , 0x3279 , 0x327a , 0x327b , 0x327c , 0x327d , 0x327e , 0x3280 , 0x3281 , 0x3282 , 0x3283 , 0x3284 , 0x3285 , 0x3286 , 0x3287 , 0x3288 , 0x3289 , 0x328a , 0x328b , 0x328c , 0x328d , 0x328e , 0x328f , 0x3290 , 0x3291 , 0x3292 , 0x3293 , 0x3294 , 0x3295 , 0x3296 , 0x3297 , 0x3298 , 0x3299 , 0x329a , 0x329b , 0x329c , 0x329d , 0x329e , 0x329f , 0x32a0 , 0x32a1 , 0x32a2 , 0x32a3 , 0x32a4 , 0x32a5 , 0x32a6 , 0x32a7 , 0x32a8 , 0x32a9 , 0x32aa , 0x32ab , 0x32ac , 0x32ad , 0x32ae , 0x32af , 0x32b0 , 0x32b1 , 0x32b2 , 0x32b3 , 0x32b4 , 0x32b5 , 0x32b6 , 0x32b7 , 0x32b8 , 0x32b9 , 0x32ba , 0x32bb , 0x32bc , 0x32bd , 0x32be , 0x32bf , 0x32c0 , 0x32c1 , 0x32c2 , 0x32c3 , 0x32c4 , 0x32c5 , 0x32c6 , 0x32c7 , 0x32c8 , 0x32c9 , 0x32ca , 0x32cb , 0x32cc , 0x32cd , 0x32ce , 0x32cf , 0x32d0 , 0x32d1 , 0x32d2 , 0x32d3 , 0x32d4 , 0x32d5 , 0x32d6 , 0x32d7 , 0x32d8 , 0x32d9 , 0x32da , 0x32db , 0x32dc , 0x32dd , 0x32de , 0x32df , 0x32e0 , 0x32e1 , 0x32e2 , 0x32e3 , 0x32e4 , 0x32e5 , 0x32e6 , 0x32e7 , 0x32e8 , 0x32e9 , 0x32ea , 0x32eb , 0x32ec , 0x32ed , 0x32ee , 0x32ef , 0x32f0 , 0x32f1 , 0x32f2 , 0x32f3 , 0x32f4 , 0x32f5 , 0x32f6 , 0x32f7 , 0x32f8 , 0x32f9 , 0x32fa , 0x32fb , 0x32fc , 0x32fd , 0x32fe , 0x3300 , 0x3301 , 0x3302 , 0x3303 , 0x3304 , 0x3305 , 0x3306 , 0x3307 , 0x3308 , 0x3309 , 0x330a , 0x330b , 0x330c , 0x330d , 0x330e , 0x330f , 0x3310 , 0x3311 , 0x3312 , 0x3313 , 0x3314 , 0x3315 , 0x3316 , 0x3317 , 0x3318 , 0x3319 , 0x331a , 0x331b , 0x331c , 0x331d , 0x331e , 0x331f , 0x3320 , 0x3321 , 0x3322 , 0x3323 , 0x3324 , 0x3325 , 0x3326 , 0x3327 , 0x3328 , 0x3329 , 0x332a , 0x332b , 0x332c , 0x332d , 0x332e , 0x332f , 0x3330 , 0x3331 , 0x3332 , 0x3333 , 0x3334 , 0x3335 , 0x3336 , 0x3337 , 0x3338 , 0x3339 , 0x333a , 0x333b , 0x333c , 0x333d , 0x333e , 0x333f , 0x3340 , 0x3341 , 0x3342 , 0x3343 , 0x3344 , 0x3345 , 0x3346 , 0x3347 , 0x3348 , 0x3349 , 0x334a , 0x334b , 0x334c , 0x334d , 0x334e , 0x334f , 0x3350 , 0x3351 , 0x3352 , 0x3353 , 0x3354 , 0x3355 , 0x3356 , 0x3357 , 0x3358 , 0x3359 , 0x335a , 0x335b , 0x335c , 0x335d , 0x335e , 0x335f , 0x3360 , 0x3361 , 0x3362 , 0x3363 , 0x3364 , 0x3365 , 0x3366 , 0x3367 , 0x3368 , 0x3369 , 0x336a , 0x336b , 0x336c , 0x336d , 0x336e , 0x336f , 0x3370 , 0x3371 , 0x3372 , 0x3373 , 0x3374 , 0x3375 , 0x3376 , 0x3377 , 0x3378 , 0x3379 , 0x337a , 0x337b , 0x337c , 0x337d , 0x337e , 0x337f , 0x3380 , 0x3381 , 0x3382 , 0x3383 , 0x3384 , 0x3385 , 0x3386 , 0x3387 , 0x3388 , 0x3389 , 0x338a , 0x338b , 0x338c , 0x338d , 0x338e , 0x338f , 0x3390 , 0x3391 , 0x3392 , 0x3393 , 0x3394 , 0x3395 , 0x3396 , 0x3397 , 0x3398 , 0x3399 , 0x339a , 0x339b , 0x339c , 0x339d , 0x339e , 0x339f , 0x33a0 , 0x33a1 , 0x33a2 , 0x33a3 , 0x33a4 , 0x33a5 , 0x33a6 , 0x33a7 , 0x33a8 , 0x33a9 , 0x33aa , 0x33ab , 0x33ac , 0x33ad , 0x33ae , 0x33af , 0x33b0 , 0x33b1 , 0x33b2 , 0x33b3 , 0x33b4 , 0x33b5 , 0x33b6 , 0x33b7 , 0x33b8 , 0x33b9 , 0x33ba , 0x33bb , 0x33bc , 0x33bd , 0x33be , 0x33bf , 0x33c0 , 0x33c1 , 0x33c2 , 0x33c3 , 0x33c4 , 0x33c5 , 0x33c6 , 0x33c7 , 0x33c8 , 0x33c9 , 0x33ca , 0x33cb , 0x33cc , 0x33cd , 0x33ce , 0x33cf , 0x33d0 , 0x33d1 , 0x33d2 , 0x33d3 , 0x33d4 , 0x33d5 , 0x33d6 , 0x33d7 , 0x33d8 , 0x33d9 , 0x33da , 0x33db , 0x33dc , 0x33dd , 0x33de , 0x33df , 0x33e0 , 0x33e1 , 0x33e2 , 0x33e3 , 0x33e4 , 0x33e5 , 0x33e6 , 0x33e7 , 0x33e8 , 0x33e9 , 0x33ea , 0x33eb , 0x33ec , 0x33ed , 0x33ee , 0x33ef , 0x33f0 , 0x33f1 , 0x33f2 , 0x33f3 , 0x33f4 , 0x33f5 , 0x33f6 , 0x33f7 , 0x33f8 , 0x33f9 , 0x33fa , 0x33fb , 0x33fc , 0x33fd , 0x33fe , 0x33ff , 0xfb00 , 0xfb01 , 0xfb02 , 0xfb03 , 0xfb04 , 0xfb05 , 0xfb06 , 0xfb13 , 0xfb14 , 0xfb15 , 0xfb16 , 0xfb17 , 0xfb20 , 0xfb21 , 0xfb22 , 0xfb23 , 0xfb24 , 0xfb25 , 0xfb26 , 0xfb27 , 0xfb28 , 0xfb29 , 0xfb4f , 0xfb50 , 0xfb51 , 0xfb52 , 0xfb53 , 0xfb54 , 0xfb55 , 0xfb56 , 0xfb57 , 0xfb58 , 0xfb59 , 0xfb5a , 0xfb5b , 0xfb5c , 0xfb5d , 0xfb5e , 0xfb5f , 0xfb60 , 0xfb61 , 0xfb62 , 0xfb63 , 0xfb64 , 0xfb65 , 0xfb66 , 0xfb67 , 0xfb68 , 0xfb69 , 0xfb6a , 0xfb6b , 0xfb6c , 0xfb6d , 0xfb6e , 0xfb6f , 0xfb70 , 0xfb71 , 0xfb72 , 0xfb73 , 0xfb74 , 0xfb75 , 0xfb76 , 0xfb77 , 0xfb78 , 0xfb79 , 0xfb7a , 0xfb7b , 0xfb7c , 0xfb7d , 0xfb7e , 0xfb7f , 0xfb80 , 0xfb81 , 0xfb82 , 0xfb83 , 0xfb84 , 0xfb85 , 0xfb86 , 0xfb87 , 0xfb88 , 0xfb89 , 0xfb8a , 0xfb8b , 0xfb8c , 0xfb8d , 0xfb8e , 0xfb8f , 0xfb90 , 0xfb91 , 0xfb92 , 0xfb93 , 0xfb94 , 0xfb95 , 0xfb96 , 0xfb97 , 0xfb98 , 0xfb99 , 0xfb9a , 0xfb9b , 0xfb9c , 0xfb9d , 0xfb9e , 0xfb9f , 0xfba0 , 0xfba1 , 0xfba2 , 0xfba3 , 0xfba4 , 0xfba5 , 0xfba6 , 0xfba7 , 0xfba8 , 0xfba9 , 0xfbaa , 0xfbab , 0xfbac , 0xfbad , 0xfbae , 0xfbaf , 0xfbb0 , 0xfbb1 , 0xfbd3 , 0xfbd4 , 0xfbd5 , 0xfbd6 , 0xfbd7 , 0xfbd8 , 0xfbd9 , 0xfbda , 0xfbdb , 0xfbdc , 0xfbdd , 0xfbde , 0xfbdf , 0xfbe0 , 0xfbe1 , 0xfbe2 , 0xfbe3 , 0xfbe4 , 0xfbe5 , 0xfbe6 , 0xfbe7 , 0xfbe8 , 0xfbe9 , 0xfbea , 0xfbeb , 0xfbec , 0xfbed , 0xfbee , 0xfbef , 0xfbf0 , 0xfbf1 , 0xfbf2 , 0xfbf3 , 0xfbf4 , 0xfbf5 , 0xfbf6 , 0xfbf7 , 0xfbf8 , 0xfbf9 , 0xfbfa , 0xfbfb , 0xfbfc , 0xfbfd , 0xfbfe , 0xfbff , 0xfc00 , 0xfc01 , 0xfc02 , 0xfc03 , 0xfc04 , 0xfc05 , 0xfc06 , 0xfc07 , 0xfc08 , 0xfc09 , 0xfc0a , 0xfc0b , 0xfc0c , 0xfc0d , 0xfc0e , 0xfc0f , 0xfc10 , 0xfc11 , 0xfc12 , 0xfc13 , 0xfc14 , 0xfc15 , 0xfc16 , 0xfc17 , 0xfc18 , 0xfc19 , 0xfc1a , 0xfc1b , 0xfc1c , 0xfc1d , 0xfc1e , 0xfc1f , 0xfc20 , 0xfc21 , 0xfc22 , 0xfc23 , 0xfc24 , 0xfc25 , 0xfc26 , 0xfc27 , 0xfc28 , 0xfc29 , 0xfc2a , 0xfc2b , 0xfc2c , 0xfc2d , 0xfc2e , 0xfc2f , 0xfc30 , 0xfc31 , 0xfc32 , 0xfc33 , 0xfc34 , 0xfc35 , 0xfc36 , 0xfc37 , 0xfc38 , 0xfc39 , 0xfc3a , 0xfc3b , 0xfc3c , 0xfc3d , 0xfc3e , 0xfc3f , 0xfc40 , 0xfc41 , 0xfc42 , 0xfc43 , 0xfc44 , 0xfc45 , 0xfc46 , 0xfc47 , 0xfc48 , 0xfc49 , 0xfc4a , 0xfc4b , 0xfc4c , 0xfc4d , 0xfc4e , 0xfc4f , 0xfc50 , 0xfc51 , 0xfc52 , 0xfc53 , 0xfc54 , 0xfc55 , 0xfc56 , 0xfc57 , 0xfc58 , 0xfc59 , 0xfc5a , 0xfc5b , 0xfc5c , 0xfc5d , 0xfc5e , 0xfc5f , 0xfc60 , 0xfc61 , 0xfc62 , 0xfc63 , 0xfc64 , 0xfc65 , 0xfc66 , 0xfc67 , 0xfc68 , 0xfc69 , 0xfc6a , 0xfc6b , 0xfc6c , 0xfc6d , 0xfc6e , 0xfc6f , 0xfc70 , 0xfc71 , 0xfc72 , 0xfc73 , 0xfc74 , 0xfc75 , 0xfc76 , 0xfc77 , 0xfc78 , 0xfc79 , 0xfc7a , 0xfc7b , 0xfc7c , 0xfc7d , 0xfc7e , 0xfc7f , 0xfc80 , 0xfc81 , 0xfc82 , 0xfc83 , 0xfc84 , 0xfc85 , 0xfc86 , 0xfc87 , 0xfc88 , 0xfc89 , 0xfc8a , 0xfc8b , 0xfc8c , 0xfc8d , 0xfc8e , 0xfc8f , 0xfc90 , 0xfc91 , 0xfc92 , 0xfc93 , 0xfc94 , 0xfc95 , 0xfc96 , 0xfc97 , 0xfc98 , 0xfc99 , 0xfc9a , 0xfc9b , 0xfc9c , 0xfc9d , 0xfc9e , 0xfc9f , 0xfca0 , 0xfca1 , 0xfca2 , 0xfca3 , 0xfca4 , 0xfca5 , 0xfca6 , 0xfca7 , 0xfca8 , 0xfca9 , 0xfcaa , 0xfcab , 0xfcac , 0xfcad , 0xfcae , 0xfcaf , 0xfcb0 , 0xfcb1 , 0xfcb2 , 0xfcb3 , 0xfcb4 , 0xfcb5 , 0xfcb6 , 0xfcb7 , 0xfcb8 , 0xfcb9 , 0xfcba , 0xfcbb , 0xfcbc , 0xfcbd , 0xfcbe , 0xfcbf , 0xfcc0 , 0xfcc1 , 0xfcc2 , 0xfcc3 , 0xfcc4 , 0xfcc5 , 0xfcc6 , 0xfcc7 , 0xfcc8 , 0xfcc9 , 0xfcca , 0xfccb , 0xfccc , 0xfccd , 0xfcce , 0xfccf , 0xfcd0 , 0xfcd1 , 0xfcd2 , 0xfcd3 , 0xfcd4 , 0xfcd5 , 0xfcd6 , 0xfcd7 , 0xfcd8 , 0xfcd9 , 0xfcda , 0xfcdb , 0xfcdc , 0xfcdd , 0xfcde , 0xfcdf , 0xfce0 , 0xfce1 , 0xfce2 , 0xfce3 , 0xfce4 , 0xfce5 , 0xfce6 , 0xfce7 , 0xfce8 , 0xfce9 , 0xfcea , 0xfceb , 0xfcec , 0xfced , 0xfcee , 0xfcef , 0xfcf0 , 0xfcf1 , 0xfcf2 , 0xfcf3 , 0xfcf4 , 0xfcf5 , 0xfcf6 , 0xfcf7 , 0xfcf8 , 0xfcf9 , 0xfcfa , 0xfcfb , 0xfcfc , 0xfcfd , 0xfcfe , 0xfcff , 0xfd00 , 0xfd01 , 0xfd02 , 0xfd03 , 0xfd04 , 0xfd05 , 0xfd06 , 0xfd07 , 0xfd08 , 0xfd09 , 0xfd0a , 0xfd0b , 0xfd0c , 0xfd0d , 0xfd0e , 0xfd0f , 0xfd10 , 0xfd11 , 0xfd12 , 0xfd13 , 0xfd14 , 0xfd15 , 0xfd16 , 0xfd17 , 0xfd18 , 0xfd19 , 0xfd1a , 0xfd1b , 0xfd1c , 0xfd1d , 0xfd1e , 0xfd1f , 0xfd20 , 0xfd21 , 0xfd22 , 0xfd23 , 0xfd24 , 0xfd25 , 0xfd26 , 0xfd27 , 0xfd28 , 0xfd29 , 0xfd2a , 0xfd2b , 0xfd2c , 0xfd2d , 0xfd2e , 0xfd2f , 0xfd30 , 0xfd31 , 0xfd32 , 0xfd33 , 0xfd34 , 0xfd35 , 0xfd36 , 0xfd37 , 0xfd38 , 0xfd39 , 0xfd3a , 0xfd3b , 0xfd3c , 0xfd3d , 0xfd50 , 0xfd51 , 0xfd52 , 0xfd53 , 0xfd54 , 0xfd55 , 0xfd56 , 0xfd57 , 0xfd58 , 0xfd59 , 0xfd5a , 0xfd5b , 0xfd5c , 0xfd5d , 0xfd5e , 0xfd5f , 0xfd60 , 0xfd61 , 0xfd62 , 0xfd63 , 0xfd64 , 0xfd65 , 0xfd66 , 0xfd67 , 0xfd68 , 0xfd69 , 0xfd6a , 0xfd6b , 0xfd6c , 0xfd6d , 0xfd6e , 0xfd6f , 0xfd70 , 0xfd71 , 0xfd72 , 0xfd73 , 0xfd74 , 0xfd75 , 0xfd76 , 0xfd77 , 0xfd78 , 0xfd79 , 0xfd7a , 0xfd7b , 0xfd7c , 0xfd7d , 0xfd7e , 0xfd7f , 0xfd80 , 0xfd81 , 0xfd82 , 0xfd83 , 0xfd84 , 0xfd85 , 0xfd86 , 0xfd87 , 0xfd88 , 0xfd89 , 0xfd8a , 0xfd8b , 0xfd8c , 0xfd8d , 0xfd8e , 0xfd8f , 0xfd92 , 0xfd93 , 0xfd94 , 0xfd95 , 0xfd96 , 0xfd97 , 0xfd98 , 0xfd99 , 0xfd9a , 0xfd9b , 0xfd9c , 0xfd9d , 0xfd9e , 0xfd9f , 0xfda0 , 0xfda1 , 0xfda2 , 0xfda3 , 0xfda4 , 0xfda5 , 0xfda6 , 0xfda7 , 0xfda8 , 0xfda9 , 0xfdaa , 0xfdab , 0xfdac , 0xfdad , 0xfdae , 0xfdaf , 0xfdb0 , 0xfdb1 , 0xfdb2 , 0xfdb3 , 0xfdb4 , 0xfdb5 , 0xfdb6 , 0xfdb7 , 0xfdb8 , 0xfdb9 , 0xfdba , 0xfdbb , 0xfdbc , 0xfdbd , 0xfdbe , 0xfdbf , 0xfdc0 , 0xfdc1 , 0xfdc2 , 0xfdc3 , 0xfdc4 , 0xfdc5 , 0xfdc6 , 0xfdc7 , 0xfdf0 , 0xfdf1 , 0xfdf2 , 0xfdf3 , 0xfdf4 , 0xfdf5 , 0xfdf6 , 0xfdf7 , 0xfdf8 , 0xfdf9 , 0xfdfa , 0xfdfb , 0xfdfc , 0xfe10 , 0xfe11 , 0xfe12 , 0xfe13 , 0xfe14 , 0xfe15 , 0xfe16 , 0xfe17 , 0xfe18 , 0xfe19 , 0xfe30 , 0xfe31 , 0xfe32 , 0xfe33 , 0xfe34 , 0xfe35 , 0xfe36 , 0xfe37 , 0xfe38 , 0xfe39 , 0xfe3a , 0xfe3b , 0xfe3c , 0xfe3d , 0xfe3e , 0xfe3f , 0xfe40 , 0xfe41 , 0xfe42 , 0xfe43 , 0xfe44 , 0xfe47 , 0xfe48 , 0xfe49 , 0xfe4a , 0xfe4b , 0xfe4c , 0xfe4d , 0xfe4e , 0xfe4f , 0xfe50 , 0xfe51 , 0xfe52 , 0xfe54 , 0xfe55 , 0xfe56 , 0xfe57 , 0xfe58 , 0xfe59 , 0xfe5a , 0xfe5b , 0xfe5c , 0xfe5d , 0xfe5e , 0xfe5f , 0xfe60 , 0xfe61 , 0xfe62 , 0xfe63 , 0xfe64 , 0xfe65 , 0xfe66 , 0xfe68 , 0xfe69 , 0xfe6a , 0xfe6b , 0xfe70 , 0xfe71 , 0xfe72 , 0xfe74 , 0xfe76 , 0xfe77 , 0xfe78 , 0xfe79 , 0xfe7a , 0xfe7b , 0xfe7c , 0xfe7d , 0xfe7e , 0xfe7f , 0xfe80 , 0xfe81 , 0xfe82 , 0xfe83 , 0xfe84 , 0xfe85 , 0xfe86 , 0xfe87 , 0xfe88 , 0xfe89 , 0xfe8a , 0xfe8b , 0xfe8c , 0xfe8d , 0xfe8e , 0xfe8f , 0xfe90 , 0xfe91 , 0xfe92 , 0xfe93 , 0xfe94 , 0xfe95 , 0xfe96 , 0xfe97 , 0xfe98 , 0xfe99 , 0xfe9a , 0xfe9b , 0xfe9c , 0xfe9d , 0xfe9e , 0xfe9f , 0xfea0 , 0xfea1 , 0xfea2 , 0xfea3 , 0xfea4 , 0xfea5 , 0xfea6 , 0xfea7 , 0xfea8 , 0xfea9 , 0xfeaa , 0xfeab , 0xfeac , 0xfead , 0xfeae , 0xfeaf , 0xfeb0 , 0xfeb1 , 0xfeb2 , 0xfeb3 , 0xfeb4 , 0xfeb5 , 0xfeb6 , 0xfeb7 , 0xfeb8 , 0xfeb9 , 0xfeba , 0xfebb , 0xfebc , 0xfebd , 0xfebe , 0xfebf , 0xfec0 , 0xfec1 , 0xfec2 , 0xfec3 , 0xfec4 , 0xfec5 , 0xfec6 , 0xfec7 , 0xfec8 , 0xfec9 , 0xfeca , 0xfecb , 0xfecc , 0xfecd , 0xfece , 0xfecf , 0xfed0 , 0xfed1 , 0xfed2 , 0xfed3 , 0xfed4 , 0xfed5 , 0xfed6 , 0xfed7 , 0xfed8 , 0xfed9 , 0xfeda , 0xfedb , 0xfedc , 0xfedd , 0xfede , 0xfedf , 0xfee0 , 0xfee1 , 0xfee2 , 0xfee3 , 0xfee4 , 0xfee5 , 0xfee6 , 0xfee7 , 0xfee8 , 0xfee9 , 0xfeea , 0xfeeb , 0xfeec , 0xfeed , 0xfeee , 0xfeef , 0xfef0 , 0xfef1 , 0xfef2 , 0xfef3 , 0xfef4 , 0xfef5 , 0xfef6 , 0xfef7 , 0xfef8 , 0xfef9 , 0xfefa , 0xfefb , 0xfefc , 0xff01 , 0xff02 , 0xff03 , 0xff04 , 0xff05 , 0xff06 , 0xff07 , 0xff08 , 0xff09 , 0xff0a , 0xff0b , 0xff0c , 0xff0d , 0xff0e , 0xff0f , 0xff10 , 0xff11 , 0xff12 , 0xff13 , 0xff14 , 0xff15 , 0xff16 , 0xff17 , 0xff18 , 0xff19 , 0xff1a , 0xff1b , 0xff1c , 0xff1d , 0xff1e , 0xff1f , 0xff20 , 0xff21 , 0xff22 , 0xff23 , 0xff24 , 0xff25 , 0xff26 , 0xff27 , 0xff28 , 0xff29 , 0xff2a , 0xff2b , 0xff2c , 0xff2d , 0xff2e , 0xff2f , 0xff30 , 0xff31 , 0xff32 , 0xff33 , 0xff34 , 0xff35 , 0xff36 , 0xff37 , 0xff38 , 0xff39 , 0xff3a , 0xff3b , 0xff3c , 0xff3d , 0xff3e , 0xff3f , 0xff40 , 0xff41 , 0xff42 , 0xff43 , 0xff44 , 0xff45 , 0xff46 , 0xff47 , 0xff48 , 0xff49 , 0xff4a , 0xff4b , 0xff4c , 0xff4d , 0xff4e , 0xff4f , 0xff50 , 0xff51 , 0xff52 , 0xff53 , 0xff54 , 0xff55 , 0xff56 , 0xff57 , 0xff58 , 0xff59 , 0xff5a , 0xff5b , 0xff5c , 0xff5d , 0xff5e , 0xff5f , 0xff60 , 0xff61 , 0xff62 , 0xff63 , 0xff64 , 0xff65 , 0xff66 , 0xff67 , 0xff68 , 0xff69 , 0xff6a , 0xff6b , 0xff6c , 0xff6d , 0xff6e , 0xff6f , 0xff70 , 0xff71 , 0xff72 , 0xff73 , 0xff74 , 0xff75 , 0xff76 , 0xff77 , 0xff78 , 0xff79 , 0xff7a , 0xff7b , 0xff7c , 0xff7d , 0xff7e , 0xff7f , 0xff80 , 0xff81 , 0xff82 , 0xff83 , 0xff84 , 0xff85 , 0xff86 , 0xff87 , 0xff88 , 0xff89 , 0xff8a , 0xff8b , 0xff8c , 0xff8d , 0xff8e , 0xff8f , 0xff90 , 0xff91 , 0xff92 , 0xff93 , 0xff94 , 0xff95 , 0xff96 , 0xff97 , 0xff98 , 0xff99 , 0xff9a , 0xff9b , 0xff9c , 0xff9d , 0xff9e , 0xff9f , 0xffa0 , 0xffa1 , 0xffa2 , 0xffa3 , 0xffa4 , 0xffa5 , 0xffa6 , 0xffa7 , 0xffa8 , 0xffa9 , 0xffaa , 0xffab , 0xffac , 0xffad , 0xffae , 0xffaf , 0xffb0 , 0xffb1 , 0xffb2 , 0xffb3 , 0xffb4 , 0xffb5 , 0xffb6 , 0xffb7 , 0xffb8 , 0xffb9 , 0xffba , 0xffbb , 0xffbc , 0xffbd , 0xffbe , 0xffc2 , 0xffc3 , 0xffc4 , 0xffc5 , 0xffc6 , 0xffc7 , 0xffca , 0xffcb , 0xffcc , 0xffcd , 0xffce , 0xffcf , 0xffd2 , 0xffd3 , 0xffd4 , 0xffd5 , 0xffd6 , 0xffd7 , 0xffda , 0xffdb , 0xffdc , 0xffe0 , 0xffe1 , 0xffe2 , 0xffe3 , 0xffe4 , 0xffe5 , 0xffe6 , 0xffe8 , 0xffe9 , 0xffea , 0xffeb , 0xffec , 0xffed , 0xffee , 0x1d400 , 0x1d401 , 0x1d402 , 0x1d403 , 0x1d404 , 0x1d405 , 0x1d406 , 0x1d407 , 0x1d408 , 0x1d409 , 0x1d40a , 0x1d40b , 0x1d40c , 0x1d40d , 0x1d40e , 0x1d40f , 0x1d410 , 0x1d411 , 0x1d412 , 0x1d413 , 0x1d414 , 0x1d415 , 0x1d416 , 0x1d417 , 0x1d418 , 0x1d419 , 0x1d41a , 0x1d41b , 0x1d41c , 0x1d41d , 0x1d41e , 0x1d41f , 0x1d420 , 0x1d421 , 0x1d422 , 0x1d423 , 0x1d424 , 0x1d425 , 0x1d426 , 0x1d427 , 0x1d428 , 0x1d429 , 0x1d42a , 0x1d42b , 0x1d42c , 0x1d42d , 0x1d42e , 0x1d42f , 0x1d430 , 0x1d431 , 0x1d432 , 0x1d433 , 0x1d434 , 0x1d435 , 0x1d436 , 0x1d437 , 0x1d438 , 0x1d439 , 0x1d43a , 0x1d43b , 0x1d43c , 0x1d43d , 0x1d43e , 0x1d43f , 0x1d440 , 0x1d441 , 0x1d442 , 0x1d443 , 0x1d444 , 0x1d445 , 0x1d446 , 0x1d447 , 0x1d448 , 0x1d449 , 0x1d44a , 0x1d44b , 0x1d44c , 0x1d44d , 0x1d44e , 0x1d44f , 0x1d450 , 0x1d451 , 0x1d452 , 0x1d453 , 0x1d454 , 0x1d456 , 0x1d457 , 0x1d458 , 0x1d459 , 0x1d45a , 0x1d45b , 0x1d45c , 0x1d45d , 0x1d45e , 0x1d45f , 0x1d460 , 0x1d461 , 0x1d462 , 0x1d463 , 0x1d464 , 0x1d465 , 0x1d466 , 0x1d467 , 0x1d468 , 0x1d469 , 0x1d46a , 0x1d46b , 0x1d46c , 0x1d46d , 0x1d46e , 0x1d46f , 0x1d470 , 0x1d471 , 0x1d472 , 0x1d473 , 0x1d474 , 0x1d475 , 0x1d476 , 0x1d477 , 0x1d478 , 0x1d479 , 0x1d47a , 0x1d47b , 0x1d47c , 0x1d47d , 0x1d47e , 0x1d47f , 0x1d480 , 0x1d481 , 0x1d482 , 0x1d483 , 0x1d484 , 0x1d485 , 0x1d486 , 0x1d487 , 0x1d488 , 0x1d489 , 0x1d48a , 0x1d48b , 0x1d48c , 0x1d48d , 0x1d48e , 0x1d48f , 0x1d490 , 0x1d491 , 0x1d492 , 0x1d493 , 0x1d494 , 0x1d495 , 0x1d496 , 0x1d497 , 0x1d498 , 0x1d499 , 0x1d49a , 0x1d49b , 0x1d49c , 0x1d49e , 0x1d49f , 0x1d4a2 , 0x1d4a5 , 0x1d4a6 , 0x1d4a9 , 0x1d4aa , 0x1d4ab , 0x1d4ac , 0x1d4ae , 0x1d4af , 0x1d4b0 , 0x1d4b1 , 0x1d4b2 , 0x1d4b3 , 0x1d4b4 , 0x1d4b5 , 0x1d4b6 , 0x1d4b7 , 0x1d4b8 , 0x1d4b9 , 0x1d4bb , 0x1d4bd , 0x1d4be , 0x1d4bf , 0x1d4c0 , 0x1d4c1 , 0x1d4c2 , 0x1d4c3 , 0x1d4c5 , 0x1d4c6 , 0x1d4c7 , 0x1d4c8 , 0x1d4c9 , 0x1d4ca , 0x1d4cb , 0x1d4cc , 0x1d4cd , 0x1d4ce , 0x1d4cf , 0x1d4d0 , 0x1d4d1 , 0x1d4d2 , 0x1d4d3 , 0x1d4d4 , 0x1d4d5 , 0x1d4d6 , 0x1d4d7 , 0x1d4d8 , 0x1d4d9 , 0x1d4da , 0x1d4db , 0x1d4dc , 0x1d4dd , 0x1d4de , 0x1d4df , 0x1d4e0 , 0x1d4e1 , 0x1d4e2 , 0x1d4e3 , 0x1d4e4 , 0x1d4e5 , 0x1d4e6 , 0x1d4e7 , 0x1d4e8 , 0x1d4e9 , 0x1d4ea , 0x1d4eb , 0x1d4ec , 0x1d4ed , 0x1d4ee , 0x1d4ef , 0x1d4f0 , 0x1d4f1 , 0x1d4f2 , 0x1d4f3 , 0x1d4f4 , 0x1d4f5 , 0x1d4f6 , 0x1d4f7 , 0x1d4f8 , 0x1d4f9 , 0x1d4fa , 0x1d4fb , 0x1d4fc , 0x1d4fd , 0x1d4fe , 0x1d4ff , 0x1d500 , 0x1d501 , 0x1d502 , 0x1d503 , 0x1d504 , 0x1d505 , 0x1d507 , 0x1d508 , 0x1d509 , 0x1d50a , 0x1d50d , 0x1d50e , 0x1d50f , 0x1d510 , 0x1d511 , 0x1d512 , 0x1d513 , 0x1d514 , 0x1d516 , 0x1d517 , 0x1d518 , 0x1d519 , 0x1d51a , 0x1d51b , 0x1d51c , 0x1d51e , 0x1d51f , 0x1d520 , 0x1d521 , 0x1d522 , 0x1d523 , 0x1d524 , 0x1d525 , 0x1d526 , 0x1d527 , 0x1d528 , 0x1d529 , 0x1d52a , 0x1d52b , 0x1d52c , 0x1d52d , 0x1d52e , 0x1d52f , 0x1d530 , 0x1d531 , 0x1d532 , 0x1d533 , 0x1d534 , 0x1d535 , 0x1d536 , 0x1d537 , 0x1d538 , 0x1d539 , 0x1d53b , 0x1d53c , 0x1d53d , 0x1d53e , 0x1d540 , 0x1d541 , 0x1d542 , 0x1d543 , 0x1d544 , 0x1d546 , 0x1d54a , 0x1d54b , 0x1d54c , 0x1d54d , 0x1d54e , 0x1d54f , 0x1d550 , 0x1d552 , 0x1d553 , 0x1d554 , 0x1d555 , 0x1d556 , 0x1d557 , 0x1d558 , 0x1d559 , 0x1d55a , 0x1d55b , 0x1d55c , 0x1d55d , 0x1d55e , 0x1d55f , 0x1d560 , 0x1d561 , 0x1d562 , 0x1d563 , 0x1d564 , 0x1d565 , 0x1d566 , 0x1d567 , 0x1d568 , 0x1d569 , 0x1d56a , 0x1d56b , 0x1d56c , 0x1d56d , 0x1d56e , 0x1d56f , 0x1d570 , 0x1d571 , 0x1d572 , 0x1d573 , 0x1d574 , 0x1d575 , 0x1d576 , 0x1d577 , 0x1d578 , 0x1d579 , 0x1d57a , 0x1d57b , 0x1d57c , 0x1d57d , 0x1d57e , 0x1d57f , 0x1d580 , 0x1d581 , 0x1d582 , 0x1d583 , 0x1d584 , 0x1d585 , 0x1d586 , 0x1d587 , 0x1d588 , 0x1d589 , 0x1d58a , 0x1d58b , 0x1d58c , 0x1d58d , 0x1d58e , 0x1d58f , 0x1d590 , 0x1d591 , 0x1d592 , 0x1d593 , 0x1d594 , 0x1d595 , 0x1d596 , 0x1d597 , 0x1d598 , 0x1d599 , 0x1d59a , 0x1d59b , 0x1d59c , 0x1d59d , 0x1d59e , 0x1d59f , 0x1d5a0 , 0x1d5a1 , 0x1d5a2 , 0x1d5a3 , 0x1d5a4 , 0x1d5a5 , 0x1d5a6 , 0x1d5a7 , 0x1d5a8 , 0x1d5a9 , 0x1d5aa , 0x1d5ab , 0x1d5ac , 0x1d5ad , 0x1d5ae , 0x1d5af , 0x1d5b0 , 0x1d5b1 , 0x1d5b2 , 0x1d5b3 , 0x1d5b4 , 0x1d5b5 , 0x1d5b6 , 0x1d5b7 , 0x1d5b8 , 0x1d5b9 , 0x1d5ba , 0x1d5bb , 0x1d5bc , 0x1d5bd , 0x1d5be , 0x1d5bf , 0x1d5c0 , 0x1d5c1 , 0x1d5c2 , 0x1d5c3 , 0x1d5c4 , 0x1d5c5 , 0x1d5c6 , 0x1d5c7 , 0x1d5c8 , 0x1d5c9 , 0x1d5ca , 0x1d5cb , 0x1d5cc , 0x1d5cd , 0x1d5ce , 0x1d5cf , 0x1d5d0 , 0x1d5d1 , 0x1d5d2 , 0x1d5d3 , 0x1d5d4 , 0x1d5d5 , 0x1d5d6 , 0x1d5d7 , 0x1d5d8 , 0x1d5d9 , 0x1d5da , 0x1d5db , 0x1d5dc , 0x1d5dd , 0x1d5de , 0x1d5df , 0x1d5e0 , 0x1d5e1 , 0x1d5e2 , 0x1d5e3 , 0x1d5e4 , 0x1d5e5 , 0x1d5e6 , 0x1d5e7 , 0x1d5e8 , 0x1d5e9 , 0x1d5ea , 0x1d5eb , 0x1d5ec , 0x1d5ed , 0x1d5ee , 0x1d5ef , 0x1d5f0 , 0x1d5f1 , 0x1d5f2 , 0x1d5f3 , 0x1d5f4 , 0x1d5f5 , 0x1d5f6 , 0x1d5f7 , 0x1d5f8 , 0x1d5f9 , 0x1d5fa , 0x1d5fb , 0x1d5fc , 0x1d5fd , 0x1d5fe , 0x1d5ff , 0x1d600 , 0x1d601 , 0x1d602 , 0x1d603 , 0x1d604 , 0x1d605 , 0x1d606 , 0x1d607 , 0x1d608 , 0x1d609 , 0x1d60a , 0x1d60b , 0x1d60c , 0x1d60d , 0x1d60e , 0x1d60f , 0x1d610 , 0x1d611 , 0x1d612 , 0x1d613 , 0x1d614 , 0x1d615 , 0x1d616 , 0x1d617 , 0x1d618 , 0x1d619 , 0x1d61a , 0x1d61b , 0x1d61c , 0x1d61d , 0x1d61e , 0x1d61f , 0x1d620 , 0x1d621 , 0x1d622 , 0x1d623 , 0x1d624 , 0x1d625 , 0x1d626 , 0x1d627 , 0x1d628 , 0x1d629 , 0x1d62a , 0x1d62b , 0x1d62c , 0x1d62d , 0x1d62e , 0x1d62f , 0x1d630 , 0x1d631 , 0x1d632 , 0x1d633 , 0x1d634 , 0x1d635 , 0x1d636 , 0x1d637 , 0x1d638 , 0x1d639 , 0x1d63a , 0x1d63b , 0x1d63c , 0x1d63d , 0x1d63e , 0x1d63f , 0x1d640 , 0x1d641 , 0x1d642 , 0x1d643 , 0x1d644 , 0x1d645 , 0x1d646 , 0x1d647 , 0x1d648 , 0x1d649 , 0x1d64a , 0x1d64b , 0x1d64c , 0x1d64d , 0x1d64e , 0x1d64f , 0x1d650 , 0x1d651 , 0x1d652 , 0x1d653 , 0x1d654 , 0x1d655 , 0x1d656 , 0x1d657 , 0x1d658 , 0x1d659 , 0x1d65a , 0x1d65b , 0x1d65c , 0x1d65d , 0x1d65e , 0x1d65f , 0x1d660 , 0x1d661 , 0x1d662 , 0x1d663 , 0x1d664 , 0x1d665 , 0x1d666 , 0x1d667 , 0x1d668 , 0x1d669 , 0x1d66a , 0x1d66b , 0x1d66c , 0x1d66d , 0x1d66e , 0x1d66f , 0x1d670 , 0x1d671 , 0x1d672 , 0x1d673 , 0x1d674 , 0x1d675 , 0x1d676 , 0x1d677 , 0x1d678 , 0x1d679 , 0x1d67a , 0x1d67b , 0x1d67c , 0x1d67d , 0x1d67e , 0x1d67f , 0x1d680 , 0x1d681 , 0x1d682 , 0x1d683 , 0x1d684 , 0x1d685 , 0x1d686 , 0x1d687 , 0x1d688 , 0x1d689 , 0x1d68a , 0x1d68b , 0x1d68c , 0x1d68d , 0x1d68e , 0x1d68f , 0x1d690 , 0x1d691 , 0x1d692 , 0x1d693 , 0x1d694 , 0x1d695 , 0x1d696 , 0x1d697 , 0x1d698 , 0x1d699 , 0x1d69a , 0x1d69b , 0x1d69c , 0x1d69d , 0x1d69e , 0x1d69f , 0x1d6a0 , 0x1d6a1 , 0x1d6a2 , 0x1d6a3 , 0x1d6a4 , 0x1d6a5 , 0x1d6a8 , 0x1d6a9 , 0x1d6aa , 0x1d6ab , 0x1d6ac , 0x1d6ad , 0x1d6ae , 0x1d6af , 0x1d6b0 , 0x1d6b1 , 0x1d6b2 , 0x1d6b3 , 0x1d6b4 , 0x1d6b5 , 0x1d6b6 , 0x1d6b7 , 0x1d6b8 , 0x1d6b9 , 0x1d6ba , 0x1d6bb , 0x1d6bc , 0x1d6bd , 0x1d6be , 0x1d6bf , 0x1d6c0 , 0x1d6c1 , 0x1d6c2 , 0x1d6c3 , 0x1d6c4 , 0x1d6c5 , 0x1d6c6 , 0x1d6c7 , 0x1d6c8 , 0x1d6c9 , 0x1d6ca , 0x1d6cb , 0x1d6cc , 0x1d6cd , 0x1d6ce , 0x1d6cf , 0x1d6d0 , 0x1d6d1 , 0x1d6d2 , 0x1d6d3 , 0x1d6d4 , 0x1d6d5 , 0x1d6d6 , 0x1d6d7 , 0x1d6d8 , 0x1d6d9 , 0x1d6da , 0x1d6db , 0x1d6dc , 0x1d6dd , 0x1d6de , 0x1d6df , 0x1d6e0 , 0x1d6e1 , 0x1d6e2 , 0x1d6e3 , 0x1d6e4 , 0x1d6e5 , 0x1d6e6 , 0x1d6e7 , 0x1d6e8 , 0x1d6e9 , 0x1d6ea , 0x1d6eb , 0x1d6ec , 0x1d6ed , 0x1d6ee , 0x1d6ef , 0x1d6f0 , 0x1d6f1 , 0x1d6f2 , 0x1d6f3 , 0x1d6f4 , 0x1d6f5 , 0x1d6f6 , 0x1d6f7 , 0x1d6f8 , 0x1d6f9 , 0x1d6fa , 0x1d6fb , 0x1d6fc , 0x1d6fd , 0x1d6fe , 0x1d6ff , 0x1d700 , 0x1d701 , 0x1d702 , 0x1d703 , 0x1d704 , 0x1d705 , 0x1d706 , 0x1d707 , 0x1d708 , 0x1d709 , 0x1d70a , 0x1d70b , 0x1d70c , 0x1d70d , 0x1d70e , 0x1d70f , 0x1d710 , 0x1d711 , 0x1d712 , 0x1d713 , 0x1d714 , 0x1d715 , 0x1d716 , 0x1d717 , 0x1d718 , 0x1d719 , 0x1d71a , 0x1d71b , 0x1d71c , 0x1d71d , 0x1d71e , 0x1d71f , 0x1d720 , 0x1d721 , 0x1d722 , 0x1d723 , 0x1d724 , 0x1d725 , 0x1d726 , 0x1d727 , 0x1d728 , 0x1d729 , 0x1d72a , 0x1d72b , 0x1d72c , 0x1d72d , 0x1d72e , 0x1d72f , 0x1d730 , 0x1d731 , 0x1d732 , 0x1d733 , 0x1d734 , 0x1d735 , 0x1d736 , 0x1d737 , 0x1d738 , 0x1d739 , 0x1d73a , 0x1d73b , 0x1d73c , 0x1d73d , 0x1d73e , 0x1d73f , 0x1d740 , 0x1d741 , 0x1d742 , 0x1d743 , 0x1d744 , 0x1d745 , 0x1d746 , 0x1d747 , 0x1d748 , 0x1d749 , 0x1d74a , 0x1d74b , 0x1d74c , 0x1d74d , 0x1d74e , 0x1d74f , 0x1d750 , 0x1d751 , 0x1d752 , 0x1d753 , 0x1d754 , 0x1d755 , 0x1d756 , 0x1d757 , 0x1d758 , 0x1d759 , 0x1d75a , 0x1d75b , 0x1d75c , 0x1d75d , 0x1d75e , 0x1d75f , 0x1d760 , 0x1d761 , 0x1d762 , 0x1d763 , 0x1d764 , 0x1d765 , 0x1d766 , 0x1d767 , 0x1d768 , 0x1d769 , 0x1d76a , 0x1d76b , 0x1d76c , 0x1d76d , 0x1d76e , 0x1d76f , 0x1d770 , 0x1d771 , 0x1d772 , 0x1d773 , 0x1d774 , 0x1d775 , 0x1d776 , 0x1d777 , 0x1d778 , 0x1d779 , 0x1d77a , 0x1d77b , 0x1d77c , 0x1d77d , 0x1d77e , 0x1d77f , 0x1d780 , 0x1d781 , 0x1d782 , 0x1d783 , 0x1d784 , 0x1d785 , 0x1d786 , 0x1d787 , 0x1d788 , 0x1d789 , 0x1d78a , 0x1d78b , 0x1d78c , 0x1d78d , 0x1d78e , 0x1d78f , 0x1d790 , 0x1d791 , 0x1d792 , 0x1d793 , 0x1d794 , 0x1d795 , 0x1d796 , 0x1d797 , 0x1d798 , 0x1d799 , 0x1d79a , 0x1d79b , 0x1d79c , 0x1d79d , 0x1d79e , 0x1d79f , 0x1d7a0 , 0x1d7a1 , 0x1d7a2 , 0x1d7a3 , 0x1d7a4 , 0x1d7a5 , 0x1d7a6 , 0x1d7a7 , 0x1d7a8 , 0x1d7a9 , 0x1d7aa , 0x1d7ab , 0x1d7ac , 0x1d7ad , 0x1d7ae , 0x1d7af , 0x1d7b0 , 0x1d7b1 , 0x1d7b2 , 0x1d7b3 , 0x1d7b4 , 0x1d7b5 , 0x1d7b6 , 0x1d7b7 , 0x1d7b8 , 0x1d7b9 , 0x1d7ba , 0x1d7bb , 0x1d7bc , 0x1d7bd , 0x1d7be , 0x1d7bf , 0x1d7c0 , 0x1d7c1 , 0x1d7c2 , 0x1d7c3 , 0x1d7c4 , 0x1d7c5 , 0x1d7c6 , 0x1d7c7 , 0x1d7c8 , 0x1d7c9 , 0x1d7ce , 0x1d7cf , 0x1d7d0 , 0x1d7d1 , 0x1d7d2 , 0x1d7d3 , 0x1d7d4 , 0x1d7d5 , 0x1d7d6 , 0x1d7d7 , 0x1d7d8 , 0x1d7d9 , 0x1d7da , 0x1d7db , 0x1d7dc , 0x1d7dd , 0x1d7de , 0x1d7df , 0x1d7e0 , 0x1d7e1 , 0x1d7e2 , 0x1d7e3 , 0x1d7e4 , 0x1d7e5 , 0x1d7e6 , 0x1d7e7 , 0x1d7e8 , 0x1d7e9 , 0x1d7ea , 0x1d7eb , 0x1d7ec , 0x1d7ed , 0x1d7ee , 0x1d7ef , 0x1d7f0 , 0x1d7f1 , 0x1d7f2 , 0x1d7f3 , 0x1d7f4 , 0x1d7f5 , 0x1d7f6 , 0x1d7f7 , 0x1d7f8 , 0x1d7f9 , 0x1d7fa , 0x1d7fb , 0x1d7fc , 0x1d7fd , 0x1d7fe , 0x1d7ff }
; 
static char utable_kompat_decomp_lens [] = {
  1 , 2 , 1 , 2 , 1 , 1 , 2 , 1 , 2 , 1 , 1 , 3 , 3 , 3 , 2 , 2 , 2 , 2 , 2 , 1 , 3 , 3 , 3 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 2 , 2 , 2 , 2 , 2 , 2 , 1 , 1 , 1 , 1 , 1 , 2 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 1 , 3 , 3 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 2 , 2 , 2 , 2 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 2 , 1 , 2 , 3 , 1 , 2 , 3 , 2 , 3 , 2 , 2 , 2 , 2 , 2 , 4 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 2 , 3 , 3 , 1 , 2 , 3 , 3 , 1 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 2 , 1 , 1 , 1 , 1 , 1 , 2 , 3 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 3 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 2 , 1 , 2 , 3 , 2 , 1 , 2 , 3 , 4 , 2 , 1 , 2 , 3 , 1 , 1 , 1 , 1 , 1 , 2 , 3 , 2 , 1 , 2 , 3 , 4 , 2 , 1 , 2 , 3 , 1 , 1 , 1 , 1 , 2 , 3 , 2 , 3 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 4 , 3 , 2 , 3 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 2 , 2 , 2 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 7 , 6 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 5 , 4 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 3 , 3 , 3 , 2 , 3 , 2 , 3 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 5 , 4 , 5 , 3 , 5 , 3 , 3 , 6 , 4 , 3 , 3 , 3 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 6 , 2 , 6 , 6 , 5 , 4 , 6 , 6 , 4 , 3 , 3 , 4 , 4 , 5 , 5 , 3 , 3 , 4 , 3 , 3 , 2 , 2 , 3 , 3 , 6 , 4 , 5 , 6 , 4 , 3 , 3 , 6 , 4 , 6 , 3 , 5 , 3 , 4 , 3 , 4 , 5 , 4 , 5 , 4 , 2 , 5 , 3 , 3 , 4 , 3 , 3 , 3 , 5 , 4 , 2 , 6 , 3 , 5 , 4 , 4 , 3 , 3 , 4 , 2 , 4 , 5 , 2 , 6 , 3 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 2 , 2 , 3 , 2 , 2 , 2 , 3 , 3 , 2 , 2 , 2 , 2 , 2 , 4 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 3 , 4 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 3 , 3 , 3 , 3 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 3 , 3 , 2 , 3 , 3 , 3 , 2 , 3 , 3 , 4 , 2 , 3 , 3 , 3 , 3 , 5 , 6 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 4 , 2 , 2 , 2 , 4 , 3 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 3 , 2 , 2 , 3 , 3 , 2 , 4 , 3 , 2 , 2 , 2 , 2 , 3 , 3 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 2 , 2 , 2 , 3 , 3 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 2 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 2 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 1 , 1 , 1 , 1 , 3 , 3 , 3 , 3 , 3 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 3 , 3 , 3 , 3 , 3 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 3 , 3 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 3 , 3 , 3 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 3 , 18 , 8 , 4 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 3 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 2 , 2 , 2 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 1 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 3 , 3 , 3 , 3 , 3 , 3 , 2 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 }
; 
static short utable_kompat_decomp_indices [] = {
  0 , 1 , 3 , 4 , 6 , 7 , 8 , 10 , 11 , 13 , 14 , 15 , 18 , 21 , 24 , 26 , 28 , 30 , 32 , 34 , 35 , 38 , 41 , 44 , 46 , 48 , 50 , 52 , 54 , 56 , 58 , 60 , 62 , 63 , 64 , 65 , 66 , 67 , 68 , 69 , 70 , 71 , 73 , 75 , 77 , 79 , 81 , 83 , 84 , 34 , 85 , 86 , 87 , 8 , 89 , 90 , 91 , 92 , 93 , 94 , 95 , 96 , 97 , 98 , 99 , 100 , 102 , 104 , 106 , 108 , 110 , 112 , 114 , 116 , 118 , 119 , 122 , 125 , 126 , 127 , 128 , 129 , 130 , 131 , 132 , 133 , 134 , 135 , 136 , 137 , 138 , 139 , 140 , 141 , 142 , 143 , 144 , 145 , 146 , 3 , 147 , 148 , 149 , 150 , 151 , 152 , 153 , 154 , 155 , 156 , 157 , 158 , 159 , 14 , 160 , 161 , 162 , 163 , 164 , 165 , 166 , 167 , 168 , 169 , 89 , 170 , 171 , 92 , 172 , 173 , 65 , 165 , 168 , 89 , 170 , 95 , 92 , 172 , 174 , 175 , 176 , 177 , 178 , 155 , 179 , 180 , 181 , 182 , 183 , 184 , 185 , 186 , 187 , 188 , 189 , 190 , 191 , 192 , 193 , 194 , 195 , 196 , 197 , 198 , 199 , 200 , 201 , 202 , 203 , 204 , 205 , 206 , 207 , 208 , 209 , 90 , 210 , 212 , 212 , 214 , 216 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 218 , 219 , 221 , 222 , 224 , 0 , 227 , 229 , 232 , 234 , 237 , 239 , 241 , 243 , 245 , 247 , 0 , 251 , 173 , 252 , 253 , 254 , 255 , 256 , 257 , 258 , 259 , 260 , 261 , 262 , 263 , 251 , 13 , 6 , 7 , 252 , 253 , 254 , 255 , 256 , 257 , 258 , 259 , 260 , 261 , 262 , 3 , 152 , 14 , 85 , 153 , 264 , 266 , 269 , 272 , 273 , 275 , 278 , 281 , 282 , 156 , 133 , 133 , 133 , 62 , 284 , 134 , 134 , 137 , 84 , 139 , 285 , 142 , 287 , 143 , 143 , 143 , 288 , 290 , 293 , 295 , 295 , 128 , 272 , 152 , 130 , 296 , 138 , 14 , 297 , 298 , 299 , 300 , 173 , 301 , 93 , 170 , 304 , 305 , 306 , 129 , 151 , 152 , 173 , 64 , 307 , 310 , 313 , 316 , 319 , 322 , 325 , 328 , 331 , 334 , 337 , 340 , 343 , 134 , 345 , 347 , 350 , 352 , 353 , 355 , 358 , 362 , 364 , 365 , 367 , 137 , 272 , 129 , 138 , 173 , 370 , 372 , 375 , 168 , 377 , 379 , 382 , 386 , 85 , 388 , 390 , 84 , 176 , 151 , 158 , 393 , 395 , 398 , 400 , 13 , 6 , 7 , 252 , 253 , 254 , 255 , 256 , 257 , 403 , 405 , 407 , 409 , 411 , 413 , 415 , 417 , 419 , 421 , 423 , 425 , 428 , 431 , 434 , 437 , 440 , 443 , 446 , 449 , 452 , 456 , 460 , 464 , 468 , 472 , 476 , 480 , 484 , 488 , 492 , 496 , 498 , 500 , 502 , 504 , 506 , 508 , 510 , 512 , 514 , 517 , 520 , 523 , 526 , 529 , 532 , 535 , 538 , 541 , 544 , 547 , 550 , 553 , 556 , 559 , 562 , 565 , 568 , 571 , 574 , 577 , 580 , 583 , 586 , 589 , 592 , 595 , 598 , 601 , 604 , 607 , 610 , 613 , 616 , 619 , 622 , 126 , 128 , 272 , 129 , 130 , 296 , 132 , 133 , 134 , 135 , 136 , 137 , 138 , 139 , 140 , 142 , 287 , 143 , 625 , 144 , 145 , 352 , 146 , 364 , 626 , 295 , 3 , 150 , 176 , 151 , 152 , 179 , 156 , 62 , 173 , 64 , 157 , 84 , 158 , 263 , 14 , 163 , 627 , 65 , 34 , 164 , 165 , 168 , 69 , 85 , 70 , 206 , 251 , 628 , 632 , 635 , 637 , 640 , 641 , 642 , 643 , 644 , 645 , 646 , 647 , 648 , 649 , 650 , 651 , 652 , 653 , 654 , 655 , 656 , 657 , 658 , 659 , 660 , 661 , 662 , 663 , 664 , 665 , 666 , 667 , 668 , 669 , 670 , 671 , 672 , 673 , 674 , 675 , 676 , 677 , 678 , 679 , 680 , 681 , 682 , 683 , 684 , 685 , 686 , 687 , 688 , 689 , 690 , 691 , 692 , 693 , 694 , 695 , 696 , 697 , 698 , 699 , 700 , 701 , 702 , 703 , 704 , 705 , 706 , 707 , 708 , 709 , 710 , 711 , 712 , 713 , 714 , 715 , 716 , 717 , 718 , 719 , 720 , 721 , 722 , 723 , 724 , 725 , 726 , 727 , 728 , 729 , 730 , 731 , 732 , 733 , 734 , 735 , 736 , 737 , 738 , 739 , 740 , 741 , 742 , 743 , 744 , 745 , 746 , 747 , 748 , 749 , 750 , 751 , 752 , 753 , 754 , 755 , 756 , 757 , 758 , 759 , 760 , 761 , 762 , 763 , 764 , 765 , 766 , 767 , 768 , 769 , 770 , 771 , 772 , 773 , 774 , 775 , 776 , 777 , 778 , 779 , 780 , 781 , 782 , 783 , 784 , 785 , 786 , 787 , 788 , 789 , 790 , 791 , 792 , 793 , 794 , 795 , 796 , 797 , 798 , 799 , 800 , 801 , 802 , 803 , 804 , 805 , 806 , 807 , 808 , 809 , 810 , 811 , 812 , 813 , 814 , 815 , 816 , 817 , 818 , 819 , 820 , 821 , 822 , 823 , 824 , 825 , 826 , 827 , 828 , 829 , 830 , 831 , 832 , 833 , 834 , 835 , 836 , 837 , 838 , 839 , 840 , 841 , 842 , 843 , 844 , 845 , 846 , 847 , 848 , 849 , 850 , 851 , 852 , 853 , 854 , 855 , 856 , 0 , 857 , 666 , 858 , 859 , 860 , 862 , 864 , 866 , 868 , 869 , 870 , 871 , 872 , 873 , 874 , 875 , 876 , 877 , 878 , 879 , 880 , 881 , 882 , 883 , 884 , 885 , 886 , 887 , 888 , 889 , 890 , 891 , 892 , 893 , 894 , 895 , 896 , 897 , 898 , 899 , 900 , 901 , 902 , 903 , 904 , 905 , 906 , 907 , 908 , 909 , 910 , 911 , 912 , 913 , 914 , 915 , 916 , 917 , 918 , 919 , 920 , 921 , 922 , 923 , 924 , 925 , 926 , 927 , 928 , 929 , 930 , 931 , 932 , 933 , 934 , 935 , 936 , 937 , 938 , 939 , 940 , 941 , 942 , 943 , 944 , 945 , 946 , 947 , 948 , 949 , 950 , 951 , 952 , 953 , 954 , 955 , 956 , 957 , 958 , 959 , 960 , 961 , 643 , 649 , 962 , 963 , 964 , 965 , 966 , 967 , 647 , 968 , 969 , 970 , 971 , 651 , 972 , 975 , 978 , 981 , 984 , 987 , 990 , 993 , 996 , 999 , 1002 , 1005 , 1008 , 1011 , 1014 , 1018 , 1022 , 1026 , 1030 , 1034 , 1038 , 1042 , 1046 , 1050 , 1054 , 1058 , 1062 , 1066 , 1070 , 1074 , 1081 , 1087 , 1090 , 1093 , 1096 , 1099 , 1102 , 1105 , 1108 , 1111 , 1114 , 1117 , 1120 , 1123 , 1126 , 1129 , 1132 , 1135 , 1138 , 1141 , 1144 , 1147 , 1150 , 1153 , 1156 , 1159 , 1162 , 1165 , 1168 , 1171 , 1174 , 1177 , 1180 , 1183 , 1186 , 1189 , 1192 , 1195 , 1198 , 1200 , 1202 , 1204 , 1206 , 1208 , 1210 , 1212 , 1214 , 1216 , 1218 , 1220 , 1222 , 1224 , 1226 , 868 , 871 , 874 , 876 , 884 , 885 , 888 , 890 , 891 , 893 , 894 , 895 , 896 , 897 , 1228 , 1230 , 1232 , 1234 , 1236 , 1238 , 1240 , 1242 , 1244 , 1246 , 1248 , 1250 , 1252 , 1254 , 1256 , 1261 , 1265 , 643 , 649 , 962 , 963 , 1267 , 1268 , 1269 , 654 , 1270 , 666 , 716 , 728 , 727 , 717 , 809 , 674 , 714 , 1271 , 1272 , 1273 , 1274 , 1275 , 1276 , 1277 , 1278 , 1279 , 1280 , 680 , 1281 , 1282 , 1283 , 1284 , 1285 , 1286 , 1287 , 1288 , 964 , 965 , 966 , 1289 , 1290 , 1291 , 1292 , 1293 , 1294 , 1295 , 1296 , 1297 , 1298 , 1299 , 1301 , 1303 , 1305 , 1307 , 1309 , 1311 , 1313 , 1315 , 1317 , 1319 , 1321 , 1323 , 1325 , 1327 , 1329 , 1331 , 1333 , 1335 , 1337 , 1339 , 1341 , 1343 , 1345 , 1347 , 1350 , 1353 , 1356 , 1358 , 1361 , 1363 , 1366 , 1367 , 1368 , 1369 , 1370 , 1371 , 1372 , 1373 , 1374 , 1375 , 1376 , 1377 , 1378 , 1379 , 1380 , 1381 , 1382 , 1383 , 1384 , 1385 , 1386 , 1387 , 1388 , 1389 , 1390 , 1391 , 1392 , 1393 , 1394 , 1395 , 1396 , 1397 , 1398 , 1399 , 1400 , 1401 , 1402 , 1403 , 1404 , 1405 , 1406 , 1407 , 1408 , 1409 , 1410 , 1411 , 1412 , 1413 , 1418 , 1422 , 1427 , 1430 , 1435 , 1438 , 1441 , 1447 , 1451 , 1454 , 1457 , 1460 , 1464 , 1468 , 1472 , 1476 , 1480 , 1484 , 1488 , 1494 , 1496 , 1502 , 1508 , 1513 , 1517 , 1523 , 1529 , 1533 , 1536 , 1539 , 1543 , 1547 , 1552 , 1557 , 1560 , 1563 , 1567 , 1570 , 1573 , 1575 , 1577 , 1580 , 1583 , 1589 , 1593 , 1598 , 1604 , 1608 , 1611 , 1614 , 1620 , 1624 , 1630 , 1633 , 1638 , 1641 , 1645 , 1648 , 1652 , 1657 , 1661 , 1666 , 1670 , 1672 , 1677 , 1680 , 1683 , 1687 , 1690 , 1693 , 1696 , 1701 , 1705 , 1707 , 1713 , 1716 , 1721 , 1725 , 1729 , 1732 , 1735 , 1739 , 1741 , 1745 , 1750 , 1752 , 1758 , 1761 , 1763 , 1765 , 1767 , 1769 , 1771 , 1773 , 1775 , 1777 , 1779 , 1781 , 1784 , 1787 , 1790 , 1793 , 1796 , 1799 , 1802 , 1805 , 1808 , 1811 , 1814 , 1817 , 1820 , 1823 , 1826 , 1829 , 1831 , 1833 , 1836 , 1838 , 1840 , 1842 , 1845 , 1848 , 1850 , 1852 , 1854 , 1856 , 1858 , 1862 , 1864 , 1866 , 1868 , 1870 , 1872 , 1874 , 1876 , 1878 , 1881 , 1885 , 1887 , 1889 , 1891 , 1893 , 1895 , 1897 , 1899 , 1902 , 1905 , 1908 , 1911 , 1913 , 1915 , 1917 , 1919 , 1921 , 1923 , 1925 , 1927 , 1929 , 1931 , 1934 , 1937 , 1939 , 1942 , 1945 , 1948 , 1950 , 1953 , 1956 , 1960 , 1962 , 1965 , 1968 , 1971 , 1974 , 1979 , 1985 , 1987 , 1989 , 1991 , 1993 , 1995 , 1997 , 1999 , 2001 , 2003 , 2005 , 2007 , 2009 , 2011 , 2013 , 2015 , 2017 , 2019 , 2021 , 2025 , 2027 , 2029 , 2031 , 2035 , 2038 , 2040 , 2042 , 2044 , 2046 , 2048 , 2050 , 2052 , 2054 , 2056 , 2058 , 2061 , 2063 , 2065 , 2068 , 2071 , 2073 , 2077 , 2080 , 2082 , 2084 , 2086 , 2088 , 2091 , 2094 , 2096 , 2098 , 2100 , 2102 , 2104 , 2106 , 2108 , 2110 , 2112 , 2115 , 2118 , 2121 , 2124 , 2127 , 2130 , 2133 , 2136 , 2139 , 2142 , 2145 , 2148 , 2151 , 2154 , 2157 , 2160 , 2163 , 2166 , 2169 , 2172 , 2175 , 2178 , 2181 , 2183 , 2185 , 2187 , 2190 , 2193 , 2193 , 2195 , 2197 , 2199 , 2201 , 2203 , 2205 , 297 , 300 , 2206 , 2207 , 2208 , 2209 , 2210 , 2211 , 258 , 2212 , 2214 , 2214 , 2215 , 2215 , 2215 , 2215 , 2216 , 2216 , 2216 , 2216 , 2217 , 2217 , 2217 , 2217 , 2218 , 2218 , 2218 , 2218 , 2219 , 2219 , 2219 , 2219 , 2220 , 2220 , 2220 , 2220 , 2221 , 2221 , 2221 , 2221 , 2222 , 2222 , 2222 , 2222 , 2223 , 2223 , 2223 , 2223 , 2224 , 2224 , 2224 , 2224 , 2225 , 2225 , 2225 , 2225 , 2226 , 2226 , 2226 , 2226 , 2227 , 2227 , 2228 , 2228 , 2229 , 2229 , 2230 , 2230 , 2231 , 2231 , 2232 , 2232 , 2233 , 2233 , 2233 , 2233 , 2234 , 2234 , 2234 , 2234 , 2235 , 2235 , 2235 , 2235 , 2236 , 2236 , 2236 , 2236 , 2237 , 2237 , 2238 , 2238 , 2238 , 2238 , 2239 , 2239 , 2241 , 2241 , 2241 , 2241 , 2242 , 2242 , 2242 , 2242 , 2243 , 2243 , 2244 , 2244 , 2246 , 2246 , 2246 , 2246 , 2247 , 2247 , 2248 , 2248 , 2249 , 2249 , 106 , 2250 , 2250 , 2251 , 2251 , 2252 , 2252 , 2253 , 2253 , 2253 , 2253 , 2254 , 2254 , 2255 , 2255 , 2258 , 2258 , 2261 , 2261 , 2264 , 2264 , 2267 , 2267 , 2270 , 2270 , 2273 , 2273 , 2273 , 2276 , 2276 , 2276 , 2279 , 2279 , 2279 , 2279 , 2280 , 2283 , 2286 , 2276 , 2289 , 2292 , 2294 , 2296 , 2298 , 2300 , 2302 , 2304 , 2306 , 2308 , 2310 , 2312 , 2314 , 2316 , 2318 , 2320 , 2322 , 2324 , 2326 , 2328 , 2330 , 2332 , 2334 , 2336 , 2338 , 2340 , 2342 , 2344 , 2346 , 2348 , 2350 , 2352 , 2354 , 2356 , 2358 , 2360 , 2362 , 2364 , 2366 , 2368 , 2370 , 2372 , 2374 , 2376 , 2378 , 2380 , 2382 , 2384 , 2386 , 2388 , 2390 , 2392 , 2394 , 2396 , 2398 , 2400 , 2402 , 2404 , 2406 , 2408 , 2410 , 2412 , 2414 , 2416 , 2418 , 2420 , 2422 , 2424 , 2426 , 2428 , 2430 , 2432 , 2434 , 2436 , 2438 , 2440 , 2442 , 2444 , 2446 , 2448 , 2450 , 2452 , 2454 , 2456 , 2458 , 2460 , 2462 , 2464 , 2466 , 2468 , 2470 , 2473 , 2476 , 2479 , 2482 , 2485 , 2488 , 2491 , 2286 , 2494 , 2276 , 2289 , 2497 , 2499 , 2298 , 2501 , 2300 , 2302 , 2503 , 2505 , 2310 , 2507 , 2312 , 2314 , 2509 , 2511 , 2318 , 2513 , 2320 , 2322 , 2380 , 2382 , 2388 , 2390 , 2392 , 2400 , 2402 , 2404 , 2406 , 2414 , 2416 , 2418 , 2515 , 2426 , 2517 , 2519 , 2438 , 2521 , 2440 , 2442 , 2468 , 2523 , 2525 , 2458 , 2527 , 2460 , 2462 , 2280 , 2283 , 2529 , 2286 , 2532 , 2292 , 2294 , 2296 , 2298 , 2535 , 2304 , 2306 , 2308 , 2310 , 2537 , 2318 , 2324 , 2326 , 2328 , 2330 , 2332 , 2336 , 2338 , 2340 , 2342 , 2344 , 2346 , 2539 , 2348 , 2350 , 2352 , 2354 , 2356 , 2358 , 2362 , 2364 , 2366 , 2368 , 2370 , 2372 , 2374 , 2376 , 2378 , 2384 , 2386 , 2394 , 2396 , 2398 , 2400 , 2402 , 2408 , 2410 , 2412 , 2414 , 2541 , 2420 , 2422 , 2424 , 2426 , 2432 , 2434 , 2436 , 2438 , 2543 , 2444 , 2446 , 2545 , 2452 , 2454 , 2456 , 2458 , 2547 , 2286 , 2532 , 2298 , 2535 , 2310 , 2537 , 2318 , 2549 , 2344 , 2551 , 2553 , 2555 , 2400 , 2402 , 2414 , 2438 , 2543 , 2458 , 2547 , 2557 , 2560 , 2563 , 2566 , 2568 , 2570 , 2572 , 2574 , 2576 , 2578 , 2580 , 2582 , 2584 , 2586 , 2588 , 2590 , 2592 , 2594 , 2596 , 2598 , 2600 , 2602 , 2604 , 2606 , 2608 , 2610 , 2553 , 2612 , 2614 , 2616 , 2618 , 2566 , 2568 , 2570 , 2572 , 2574 , 2576 , 2578 , 2580 , 2582 , 2584 , 2586 , 2588 , 2590 , 2592 , 2594 , 2596 , 2598 , 2600 , 2602 , 2604 , 2606 , 2608 , 2610 , 2553 , 2612 , 2614 , 2616 , 2618 , 2606 , 2608 , 2610 , 2553 , 2551 , 2555 , 2360 , 2338 , 2340 , 2342 , 2606 , 2608 , 2610 , 2360 , 2362 , 2620 , 2620 , 2622 , 2625 , 2625 , 2628 , 2631 , 2634 , 2637 , 2640 , 2643 , 2643 , 2646 , 2649 , 2652 , 2655 , 2658 , 2661 , 2661 , 2664 , 2667 , 2667 , 2670 , 2670 , 2673 , 2676 , 2676 , 2679 , 2682 , 2682 , 2685 , 2685 , 2688 , 2691 , 2691 , 2694 , 2694 , 2697 , 2700 , 2703 , 2706 , 2706 , 2709 , 2712 , 2715 , 2718 , 2721 , 2721 , 2724 , 2727 , 2730 , 2733 , 2736 , 2739 , 2739 , 2742 , 2742 , 2745 , 2745 , 2748 , 2751 , 2754 , 2757 , 2760 , 2763 , 2766 , 2769 , 2772 , 2775 , 2778 , 2781 , 2784 , 2784 , 2787 , 2790 , 2793 , 2796 , 2796 , 2799 , 2802 , 2805 , 2808 , 2811 , 2814 , 2817 , 2820 , 2823 , 2826 , 2829 , 2832 , 2835 , 2838 , 2841 , 2844 , 2847 , 2850 , 2853 , 2856 , 2859 , 2862 , 2724 , 2730 , 2865 , 2868 , 2871 , 2874 , 2877 , 2880 , 2877 , 2871 , 2883 , 2886 , 2889 , 2892 , 2895 , 2880 , 2703 , 2673 , 2898 , 2901 , 2904 , 2907 , 2910 , 2914 , 2918 , 2922 , 2926 , 2930 , 2934 , 2938 , 2941 , 2959 , 2967 , 2971 , 2972 , 2973 , 2974 , 2975 , 2976 , 2977 , 2978 , 2979 , 224 , 222 , 2980 , 2981 , 2982 , 2982 , 261 , 262 , 2983 , 2984 , 2985 , 2986 , 2987 , 2988 , 2989 , 2990 , 2991 , 2992 , 2993 , 2994 , 2995 , 2996 , 2997 , 2998 , 239 , 239 , 239 , 239 , 2982 , 2982 , 2982 , 2971 , 2972 , 221 , 2975 , 2974 , 2977 , 2976 , 2980 , 261 , 262 , 2983 , 2984 , 2985 , 2986 , 2999 , 3000 , 3001 , 258 , 3002 , 3003 , 3004 , 260 , 3005 , 3006 , 3007 , 3008 , 3009 , 3011 , 3013 , 3015 , 3017 , 3019 , 3021 , 3023 , 3025 , 3027 , 3029 , 3031 , 3033 , 3035 , 3037 , 3038 , 3038 , 3040 , 3040 , 3042 , 3042 , 3044 , 3044 , 3046 , 3046 , 3046 , 3046 , 3048 , 3048 , 3049 , 3049 , 3049 , 3049 , 3050 , 3050 , 3051 , 3051 , 3051 , 3051 , 3052 , 3052 , 3052 , 3052 , 3053 , 3053 , 3053 , 3053 , 3054 , 3054 , 3054 , 3054 , 3055 , 3055 , 3055 , 3055 , 3056 , 3056 , 3057 , 3057 , 3058 , 3058 , 3059 , 3059 , 3060 , 3060 , 3060 , 3060 , 3061 , 3061 , 3061 , 3061 , 3062 , 3062 , 3062 , 3062 , 3063 , 3063 , 3063 , 3063 , 3064 , 3064 , 3064 , 3064 , 3065 , 3065 , 3065 , 3065 , 3066 , 3066 , 3066 , 3066 , 3067 , 3067 , 3067 , 3067 , 3068 , 3068 , 3068 , 3068 , 3069 , 3069 , 3069 , 3069 , 3070 , 3070 , 3070 , 3070 , 3071 , 3071 , 3071 , 3071 , 3072 , 3072 , 3072 , 3072 , 3073 , 3073 , 3073 , 3073 , 3074 , 3074 , 3074 , 3074 , 3075 , 3075 , 2254 , 2254 , 3076 , 3076 , 3076 , 3076 , 3077 , 3077 , 3080 , 3080 , 3083 , 3083 , 3086 , 3086 , 2976 , 3088 , 2999 , 3006 , 3007 , 3000 , 3089 , 261 , 262 , 3001 , 258 , 2971 , 3002 , 221 , 3090 , 251 , 13 , 6 , 7 , 252 , 253 , 254 , 255 , 256 , 257 , 2974 , 2975 , 3003 , 260 , 3004 , 2977 , 3008 , 126 , 128 , 272 , 129 , 130 , 296 , 132 , 133 , 134 , 135 , 136 , 137 , 138 , 139 , 140 , 142 , 287 , 143 , 625 , 144 , 145 , 352 , 146 , 364 , 626 , 295 , 2997 , 3005 , 2998 , 3091 , 2982 , 3092 , 3 , 150 , 176 , 151 , 152 , 179 , 156 , 62 , 173 , 64 , 157 , 84 , 158 , 263 , 14 , 163 , 627 , 65 , 34 , 164 , 165 , 168 , 69 , 85 , 70 , 206 , 2983 , 3093 , 2984 , 3094 , 3095 , 3096 , 2973 , 2993 , 2994 , 2972 , 3097 , 1412 , 3098 , 3099 , 3100 , 3101 , 3102 , 3103 , 3104 , 3105 , 3106 , 3107 , 1366 , 1367 , 1368 , 1369 , 1370 , 1371 , 1372 , 1373 , 1374 , 1375 , 1376 , 1377 , 1378 , 1379 , 1380 , 1381 , 1382 , 1383 , 1384 , 1385 , 1386 , 1387 , 1388 , 1389 , 1390 , 1391 , 1392 , 1393 , 1394 , 1395 , 1396 , 1397 , 1398 , 1399 , 1400 , 1401 , 1402 , 1403 , 1404 , 1405 , 1406 , 1407 , 1408 , 1409 , 3108 , 3109 , 3110 , 919 , 868 , 869 , 870 , 871 , 872 , 873 , 874 , 875 , 876 , 877 , 878 , 879 , 880 , 881 , 882 , 883 , 884 , 885 , 886 , 887 , 888 , 889 , 890 , 891 , 892 , 893 , 894 , 895 , 896 , 897 , 898 , 899 , 900 , 901 , 902 , 903 , 904 , 905 , 906 , 907 , 908 , 909 , 910 , 911 , 912 , 913 , 914 , 915 , 916 , 917 , 918 , 3111 , 3112 , 3113 , 4 , 3114 , 3115 , 3116 , 3117 , 3118 , 3119 , 3120 , 3121 , 3122 , 3123 , 126 , 128 , 272 , 129 , 130 , 296 , 132 , 133 , 134 , 135 , 136 , 137 , 138 , 139 , 140 , 142 , 287 , 143 , 625 , 144 , 145 , 352 , 146 , 364 , 626 , 295 , 3 , 150 , 176 , 151 , 152 , 179 , 156 , 62 , 173 , 64 , 157 , 84 , 158 , 263 , 14 , 163 , 627 , 65 , 34 , 164 , 165 , 168 , 69 , 85 , 70 , 206 , 126 , 128 , 272 , 129 , 130 , 296 , 132 , 133 , 134 , 135 , 136 , 137 , 138 , 139 , 140 , 142 , 287 , 143 , 625 , 144 , 145 , 352 , 146 , 364 , 626 , 295 , 3 , 150 , 176 , 151 , 152 , 179 , 156 , 173 , 64 , 157 , 84 , 158 , 263 , 14 , 163 , 627 , 65 , 34 , 164 , 165 , 168 , 69 , 85 , 70 , 206 , 126 , 128 , 272 , 129 , 130 , 296 , 132 , 133 , 134 , 135 , 136 , 137 , 138 , 139 , 140 , 142 , 287 , 143 , 625 , 144 , 145 , 352 , 146 , 364 , 626 , 295 , 3 , 150 , 176 , 151 , 152 , 179 , 156 , 62 , 173 , 64 , 157 , 84 , 158 , 263 , 14 , 163 , 627 , 65 , 34 , 164 , 165 , 168 , 69 , 85 , 70 , 206 , 126 , 272 , 129 , 132 , 135 , 136 , 139 , 140 , 142 , 287 , 625 , 144 , 145 , 352 , 146 , 364 , 626 , 295 , 3 , 150 , 176 , 151 , 179 , 62 , 173 , 64 , 157 , 84 , 158 , 263 , 163 , 627 , 65 , 34 , 164 , 165 , 168 , 69 , 85 , 70 , 206 , 126 , 128 , 272 , 129 , 130 , 296 , 132 , 133 , 134 , 135 , 136 , 137 , 138 , 139 , 140 , 142 , 287 , 143 , 625 , 144 , 145 , 352 , 146 , 364 , 626 , 295 , 3 , 150 , 176 , 151 , 152 , 179 , 156 , 62 , 173 , 64 , 157 , 84 , 158 , 263 , 14 , 163 , 627 , 65 , 34 , 164 , 165 , 168 , 69 , 85 , 70 , 206 , 126 , 128 , 129 , 130 , 296 , 132 , 135 , 136 , 137 , 138 , 139 , 140 , 142 , 287 , 625 , 144 , 145 , 352 , 146 , 364 , 626 , 3 , 150 , 176 , 151 , 152 , 179 , 156 , 62 , 173 , 64 , 157 , 84 , 158 , 263 , 14 , 163 , 627 , 65 , 34 , 164 , 165 , 168 , 69 , 85 , 70 , 206 , 126 , 128 , 129 , 130 , 296 , 132 , 134 , 135 , 136 , 137 , 138 , 140 , 625 , 144 , 145 , 352 , 146 , 364 , 626 , 3 , 150 , 176 , 151 , 152 , 179 , 156 , 62 , 173 , 64 , 157 , 84 , 158 , 263 , 14 , 163 , 627 , 65 , 34 , 164 , 165 , 168 , 69 , 85 , 70 , 206 , 126 , 128 , 272 , 129 , 130 , 296 , 132 , 133 , 134 , 135 , 136 , 137 , 138 , 139 , 140 , 142 , 287 , 143 , 625 , 144 , 145 , 352 , 146 , 364 , 626 , 295 , 3 , 150 , 176 , 151 , 152 , 179 , 156 , 62 , 173 , 64 , 157 , 84 , 158 , 263 , 14 , 163 , 627 , 65 , 34 , 164 , 165 , 168 , 69 , 85 , 70 , 206 , 126 , 128 , 272 , 129 , 130 , 296 , 132 , 133 , 134 , 135 , 136 , 137 , 138 , 139 , 140 , 142 , 287 , 143 , 625 , 144 , 145 , 352 , 146 , 364 , 626 , 295 , 3 , 150 , 176 , 151 , 152 , 179 , 156 , 62 , 173 , 64 , 157 , 84 , 158 , 263 , 14 , 163 , 627 , 65 , 34 , 164 , 165 , 168 , 69 , 85 , 70 , 206 , 126 , 128 , 272 , 129 , 130 , 296 , 132 , 133 , 134 , 135 , 136 , 137 , 138 , 139 , 140 , 142 , 287 , 143 , 625 , 144 , 145 , 352 , 146 , 364 , 626 , 295 , 3 , 150 , 176 , 151 , 152 , 179 , 156 , 62 , 173 , 64 , 157 , 84 , 158 , 263 , 14 , 163 , 627 , 65 , 34 , 164 , 165 , 168 , 69 , 85 , 70 , 206 , 126 , 128 , 272 , 129 , 130 , 296 , 132 , 133 , 134 , 135 , 136 , 137 , 138 , 139 , 140 , 142 , 287 , 143 , 625 , 144 , 145 , 352 , 146 , 364 , 626 , 295 , 3 , 150 , 176 , 151 , 152 , 179 , 156 , 62 , 173 , 64 , 157 , 84 , 158 , 263 , 14 , 163 , 627 , 65 , 34 , 164 , 165 , 168 , 69 , 85 , 70 , 206 , 126 , 128 , 272 , 129 , 130 , 296 , 132 , 133 , 134 , 135 , 136 , 137 , 138 , 139 , 140 , 142 , 287 , 143 , 625 , 144 , 145 , 352 , 146 , 364 , 626 , 295 , 3 , 150 , 176 , 151 , 152 , 179 , 156 , 62 , 173 , 64 , 157 , 84 , 158 , 263 , 14 , 163 , 627 , 65 , 34 , 164 , 165 , 168 , 69 , 85 , 70 , 206 , 126 , 128 , 272 , 129 , 130 , 296 , 132 , 133 , 134 , 135 , 136 , 137 , 138 , 139 , 140 , 142 , 287 , 143 , 625 , 144 , 145 , 352 , 146 , 364 , 626 , 295 , 3 , 150 , 176 , 151 , 152 , 179 , 156 , 62 , 173 , 64 , 157 , 84 , 158 , 263 , 14 , 163 , 627 , 65 , 34 , 164 , 165 , 168 , 69 , 85 , 70 , 206 , 3124 , 3125 , 3126 , 3127 , 304 , 3128 , 3129 , 3130 , 3131 , 97 , 3132 , 3133 , 3134 , 3135 , 3136 , 3137 , 3138 , 305 , 3139 , 97 , 99 , 3140 , 91 , 3141 , 3142 , 3143 , 3144 , 3145 , 3146 , 89 , 170 , 171 , 98 , 3147 , 3148 , 90 , 3149 , 94 , 3150 , 10 , 3151 , 3152 , 3153 , 93 , 95 , 96 , 3154 , 3155 , 3156 , 92 , 172 , 3157 , 3158 , 3159 , 98 , 90 , 94 , 92 , 95 , 93 , 3126 , 3127 , 304 , 3128 , 3129 , 3130 , 3131 , 97 , 3132 , 3133 , 3134 , 3135 , 3136 , 3137 , 3138 , 305 , 3139 , 97 , 99 , 3140 , 91 , 3141 , 3142 , 3143 , 3144 , 3145 , 3146 , 89 , 170 , 171 , 98 , 3147 , 3148 , 90 , 3149 , 94 , 3150 , 10 , 3151 , 3152 , 3153 , 93 , 95 , 96 , 3154 , 3155 , 3156 , 92 , 172 , 3157 , 3158 , 3159 , 98 , 90 , 94 , 92 , 95 , 93 , 3126 , 3127 , 304 , 3128 , 3129 , 3130 , 3131 , 97 , 3132 , 3133 , 3134 , 3135 , 3136 , 3137 , 3138 , 305 , 3139 , 97 , 99 , 3140 , 91 , 3141 , 3142 , 3143 , 3144 , 3145 , 3146 , 89 , 170 , 171 , 98 , 3147 , 3148 , 90 , 3149 , 94 , 3150 , 10 , 3151 , 3152 , 3153 , 93 , 95 , 96 , 3154 , 3155 , 3156 , 92 , 172 , 3157 , 3158 , 3159 , 98 , 90 , 94 , 92 , 95 , 93 , 3126 , 3127 , 304 , 3128 , 3129 , 3130 , 3131 , 97 , 3132 , 3133 , 3134 , 3135 , 3136 , 3137 , 3138 , 305 , 3139 , 97 , 99 , 3140 , 91 , 3141 , 3142 , 3143 , 3144 , 3145 , 3146 , 89 , 170 , 171 , 98 , 3147 , 3148 , 90 , 3149 , 94 , 3150 , 10 , 3151 , 3152 , 3153 , 93 , 95 , 96 , 3154 , 3155 , 3156 , 92 , 172 , 3157 , 3158 , 3159 , 98 , 90 , 94 , 92 , 95 , 93 , 3126 , 3127 , 304 , 3128 , 3129 , 3130 , 3131 , 97 , 3132 , 3133 , 3134 , 3135 , 3136 , 3137 , 3138 , 305 , 3139 , 97 , 99 , 3140 , 91 , 3141 , 3142 , 3143 , 3144 , 3145 , 3146 , 89 , 170 , 171 , 98 , 3147 , 3148 , 90 , 3149 , 94 , 3150 , 10 , 3151 , 3152 , 3153 , 93 , 95 , 96 , 3154 , 3155 , 3156 , 92 , 172 , 3157 , 3158 , 3159 , 98 , 90 , 94 , 92 , 95 , 93 , 251 , 13 , 6 , 7 , 252 , 253 , 254 , 255 , 256 , 257 , 251 , 13 , 6 , 7 , 252 , 253 , 254 , 255 , 256 , 257 , 251 , 13 , 6 , 7 , 252 , 253 , 254 , 255 , 256 , 257 , 251 , 13 , 6 , 7 , 252 , 253 , 254 , 255 , 256 , 257 , 251 , 13 , 6 , 7 , 252 , 253 , 254 , 255 , 256 , 257 }
; 
static unsigned short utable_kompat_decomp_strs [] = {
  0x20 , 0x20 , 0x308 , 0x61 , 0x20 , 0x304 , 0x32 , 0x33 , 0x20 , 0x301 , 0x3bc , 0x20 , 0x327 , 0x31 , 0x6f , 0x31 , 0x2044 , 0x34 , 0x31 , 0x2044 , 0x32 , 0x33 , 0x2044 , 0x34 , 0x49 , 0x4a , 0x69 , 0x6a , 0x4c , 0xb7 , 0x6c , 0xb7 , 0x2bc , 0x6e , 0x73 , 0x44 , 0x5a , 0x30c , 0x44 , 0x7a , 0x30c , 0x64 , 0x7a , 0x30c , 0x4c , 0x4a , 0x4c , 0x6a , 0x6c , 0x6a , 0x4e , 0x4a , 0x4e , 0x6a , 0x6e , 0x6a , 0x44 , 0x5a , 0x44 , 0x7a , 0x64 , 0x7a , 0x68 , 0x266 , 0x6a , 0x72 , 0x279 , 0x27b , 0x281 , 0x77 , 0x79 , 0x20 , 0x306 , 0x20 , 0x307 , 0x20 , 0x30a , 0x20 , 0x328 , 0x20 , 0x303 , 0x20 , 0x30b , 0x263 , 0x6c , 0x78 , 0x295 , 0x20 , 0x345 , 0x3b2 , 0x3b8 , 0x3a5 , 0x3c6 , 0x3c0 , 0x3ba , 0x3c1 , 0x3c2 , 0x398 , 0x3b5 , 0x3a3 , 0x565 , 0x582 , 0x627 , 0x674 , 0x648 , 0x674 , 0x6c7 , 0x674 , 0x64a , 0x674 , 0xe4d , 0xe32 , 0xecd , 0xeb2 , 0xeab , 0xe99 , 0xeab , 0xea1 , 0xf0b , 0xfb2 , 0xf71 , 0xf80 , 0xfb3 , 0xf71 , 0xf80 , 0x10dc , 0x41 , 0xc6 , 0x42 , 0x44 , 0x45 , 0x18e , 0x47 , 0x48 , 0x49 , 0x4a , 0x4b , 0x4c , 0x4d , 0x4e , 0x4f , 0x222 , 0x50 , 0x52 , 0x54 , 0x55 , 0x57 , 0x250 , 0x251 , 0x1d02 , 0x62 , 0x64 , 0x65 , 0x259 , 0x25b , 0x25c , 0x67 , 0x6b , 0x6d , 0x14b , 0x254 , 0x1d16 , 0x1d17 , 0x70 , 0x74 , 0x75 , 0x1d1d , 0x26f , 0x76 , 0x1d25 , 0x3b3 , 0x3b4 , 0x3c7 , 0x69 , 0x43d , 0x252 , 0x63 , 0x255 , 0xf0 , 0x66 , 0x25f , 0x261 , 0x265 , 0x268 , 0x269 , 0x26a , 0x1d7b , 0x29d , 0x26d , 0x1d85 , 0x29f , 0x271 , 0x270 , 0x272 , 0x273 , 0x274 , 0x275 , 0x278 , 0x282 , 0x283 , 0x1ab , 0x289 , 0x28a , 0x1d1c , 0x28b , 0x28c , 0x7a , 0x290 , 0x291 , 0x292 , 0x61 , 0x2be , 0x20 , 0x313 , 0x20 , 0x342 , 0x20 , 0x314 , 0x2010 , 0x20 , 0x333 , 0x2e , 0x2e , 0x2e , 0x2e , 0x2e , 0x2e , 0x2032 , 0x2032 , 0x2032 , 0x2032 , 0x2032 , 0x2035 , 0x2035 , 0x2035 , 0x2035 , 0x2035 , 0x21 , 0x21 , 0x20 , 0x305 , 0x3f , 0x3f , 0x3f , 0x21 , 0x21 , 0x3f , 0x2032 , 0x2032 , 0x2032 , 0x2032 , 0x30 , 0x34 , 0x35 , 0x36 , 0x37 , 0x38 , 0x39 , 0x2b , 0x2212 , 0x3d , 0x28 , 0x29 , 0x6e , 0x52 , 0x73 , 0x61 , 0x2f , 0x63 , 0x61 , 0x2f , 0x73 , 0x43 , 0xb0 , 0x43 , 0x63 , 0x2f , 0x6f , 0x63 , 0x2f , 0x75 , 0x190 , 0xb0 , 0x46 , 0x127 , 0x4e , 0x6f , 0x51 , 0x53 , 0x4d , 0x54 , 0x45 , 0x4c , 0x54 , 0x4d , 0x5a , 0x46 , 0x5d0 , 0x5d1 , 0x5d2 , 0x5d3 , 0x46 , 0x41 , 0x58 , 0x393 , 0x3a0 , 0x2211 , 0x31 , 0x2044 , 0x33 , 0x32 , 0x2044 , 0x33 , 0x31 , 0x2044 , 0x35 , 0x32 , 0x2044 , 0x35 , 0x33 , 0x2044 , 0x35 , 0x34 , 0x2044 , 0x35 , 0x31 , 0x2044 , 0x36 , 0x35 , 0x2044 , 0x36 , 0x31 , 0x2044 , 0x38 , 0x33 , 0x2044 , 0x38 , 0x35 , 0x2044 , 0x38 , 0x37 , 0x2044 , 0x38 , 0x31 , 0x2044 , 0x49 , 0x49 , 0x49 , 0x49 , 0x49 , 0x49 , 0x56 , 0x56 , 0x56 , 0x49 , 0x56 , 0x49 , 0x49 , 0x56 , 0x49 , 0x49 , 0x49 , 0x49 , 0x58 , 0x58 , 0x58 , 0x49 , 0x58 , 0x49 , 0x49 , 0x69 , 0x69 , 0x69 , 0x69 , 0x69 , 0x69 , 0x76 , 0x76 , 0x69 , 0x76 , 0x69 , 0x69 , 0x76 , 0x69 , 0x69 , 0x69 , 0x69 , 0x78 , 0x78 , 0x69 , 0x78 , 0x69 , 0x69 , 0x222b , 0x222b , 0x222b , 0x222b , 0x222b , 0x222e , 0x222e , 0x222e , 0x222e , 0x222e , 0x31 , 0x30 , 0x31 , 0x31 , 0x31 , 0x32 , 0x31 , 0x33 , 0x31 , 0x34 , 0x31 , 0x35 , 0x31 , 0x36 , 0x31 , 0x37 , 0x31 , 0x38 , 0x31 , 0x39 , 0x32 , 0x30 , 0x28 , 0x31 , 0x29 , 0x28 , 0x32 , 0x29 , 0x28 , 0x33 , 0x29 , 0x28 , 0x34 , 0x29 , 0x28 , 0x35 , 0x29 , 0x28 , 0x36 , 0x29 , 0x28 , 0x37 , 0x29 , 0x28 , 0x38 , 0x29 , 0x28 , 0x39 , 0x29 , 0x28 , 0x31 , 0x30 , 0x29 , 0x28 , 0x31 , 0x31 , 0x29 , 0x28 , 0x31 , 0x32 , 0x29 , 0x28 , 0x31 , 0x33 , 0x29 , 0x28 , 0x31 , 0x34 , 0x29 , 0x28 , 0x31 , 0x35 , 0x29 , 0x28 , 0x31 , 0x36 , 0x29 , 0x28 , 0x31 , 0x37 , 0x29 , 0x28 , 0x31 , 0x38 , 0x29 , 0x28 , 0x31 , 0x39 , 0x29 , 0x28 , 0x32 , 0x30 , 0x29 , 0x31 , 0x2e , 0x32 , 0x2e , 0x33 , 0x2e , 0x34 , 0x2e , 0x35 , 0x2e , 0x36 , 0x2e , 0x37 , 0x2e , 0x38 , 0x2e , 0x39 , 0x2e , 0x31 , 0x30 , 0x2e , 0x31 , 0x31 , 0x2e , 0x31 , 0x32 , 0x2e , 0x31 , 0x33 , 0x2e , 0x31 , 0x34 , 0x2e , 0x31 , 0x35 , 0x2e , 0x31 , 0x36 , 0x2e , 0x31 , 0x37 , 0x2e , 0x31 , 0x38 , 0x2e , 0x31 , 0x39 , 0x2e , 0x32 , 0x30 , 0x2e , 0x28 , 0x61 , 0x29 , 0x28 , 0x62 , 0x29 , 0x28 , 0x63 , 0x29 , 0x28 , 0x64 , 0x29 , 0x28 , 0x65 , 0x29 , 0x28 , 0x66 , 0x29 , 0x28 , 0x67 , 0x29 , 0x28 , 0x68 , 0x29 , 0x28 , 0x69 , 0x29 , 0x28 , 0x6a , 0x29 , 0x28 , 0x6b , 0x29 , 0x28 , 0x6c , 0x29 , 0x28 , 0x6d , 0x29 , 0x28 , 0x6e , 0x29 , 0x28 , 0x6f , 0x29 , 0x28 , 0x70 , 0x29 , 0x28 , 0x71 , 0x29 , 0x28 , 0x72 , 0x29 , 0x28 , 0x73 , 0x29 , 0x28 , 0x74 , 0x29 , 0x28 , 0x75 , 0x29 , 0x28 , 0x76 , 0x29 , 0x28 , 0x77 , 0x29 , 0x28 , 0x78 , 0x29 , 0x28 , 0x79 , 0x29 , 0x28 , 0x7a , 0x29 , 0x53 , 0x59 , 0x71 , 0x222b , 0x222b , 0x222b , 0x222b , 0x3a , 0x3a , 0x3d , 0x3d , 0x3d , 0x3d , 0x3d , 0x3d , 0x2d61 , 0x6bcd , 0x9f9f , 0x4e00 , 0x4e28 , 0x4e36 , 0x4e3f , 0x4e59 , 0x4e85 , 0x4e8c , 0x4ea0 , 0x4eba , 0x513f , 0x5165 , 0x516b , 0x5182 , 0x5196 , 0x51ab , 0x51e0 , 0x51f5 , 0x5200 , 0x529b , 0x52f9 , 0x5315 , 0x531a , 0x5338 , 0x5341 , 0x535c , 0x5369 , 0x5382 , 0x53b6 , 0x53c8 , 0x53e3 , 0x56d7 , 0x571f , 0x58eb , 0x5902 , 0x590a , 0x5915 , 0x5927 , 0x5973 , 0x5b50 , 0x5b80 , 0x5bf8 , 0x5c0f , 0x5c22 , 0x5c38 , 0x5c6e , 0x5c71 , 0x5ddb , 0x5de5 , 0x5df1 , 0x5dfe , 0x5e72 , 0x5e7a , 0x5e7f , 0x5ef4 , 0x5efe , 0x5f0b , 0x5f13 , 0x5f50 , 0x5f61 , 0x5f73 , 0x5fc3 , 0x6208 , 0x6236 , 0x624b , 0x652f , 0x6534 , 0x6587 , 0x6597 , 0x65a4 , 0x65b9 , 0x65e0 , 0x65e5 , 0x66f0 , 0x6708 , 0x6728 , 0x6b20 , 0x6b62 , 0x6b79 , 0x6bb3 , 0x6bcb , 0x6bd4 , 0x6bdb , 0x6c0f , 0x6c14 , 0x6c34 , 0x706b , 0x722a , 0x7236 , 0x723b , 0x723f , 0x7247 , 0x7259 , 0x725b , 0x72ac , 0x7384 , 0x7389 , 0x74dc , 0x74e6 , 0x7518 , 0x751f , 0x7528 , 0x7530 , 0x758b , 0x7592 , 0x7676 , 0x767d , 0x76ae , 0x76bf , 0x76ee , 0x77db , 0x77e2 , 0x77f3 , 0x793a , 0x79b8 , 0x79be , 0x7a74 , 0x7acb , 0x7af9 , 0x7c73 , 0x7cf8 , 0x7f36 , 0x7f51 , 0x7f8a , 0x7fbd , 0x8001 , 0x800c , 0x8012 , 0x8033 , 0x807f , 0x8089 , 0x81e3 , 0x81ea , 0x81f3 , 0x81fc , 0x820c , 0x821b , 0x821f , 0x826e , 0x8272 , 0x8278 , 0x864d , 0x866b , 0x8840 , 0x884c , 0x8863 , 0x897e , 0x898b , 0x89d2 , 0x8a00 , 0x8c37 , 0x8c46 , 0x8c55 , 0x8c78 , 0x8c9d , 0x8d64 , 0x8d70 , 0x8db3 , 0x8eab , 0x8eca , 0x8f9b , 0x8fb0 , 0x8fb5 , 0x9091 , 0x9149 , 0x91c6 , 0x91cc , 0x91d1 , 0x9577 , 0x9580 , 0x961c , 0x96b6 , 0x96b9 , 0x96e8 , 0x9751 , 0x975e , 0x9762 , 0x9769 , 0x97cb , 0x97ed , 0x97f3 , 0x9801 , 0x98a8 , 0x98db , 0x98df , 0x9996 , 0x9999 , 0x99ac , 0x9aa8 , 0x9ad8 , 0x9adf , 0x9b25 , 0x9b2f , 0x9b32 , 0x9b3c , 0x9b5a , 0x9ce5 , 0x9e75 , 0x9e7f , 0x9ea5 , 0x9ebb , 0x9ec3 , 0x9ecd , 0x9ed1 , 0x9ef9 , 0x9efd , 0x9f0e , 0x9f13 , 0x9f20 , 0x9f3b , 0x9f4a , 0x9f52 , 0x9f8d , 0x9f9c , 0x9fa0 , 0x3012 , 0x5344 , 0x5345 , 0x20 , 0x3099 , 0x20 , 0x309a , 0x3088 , 0x308a , 0x30b3 , 0x30c8 , 0x1100 , 0x1101 , 0x11aa , 0x1102 , 0x11ac , 0x11ad , 0x1103 , 0x1104 , 0x1105 , 0x11b0 , 0x11b1 , 0x11b2 , 0x11b3 , 0x11b4 , 0x11b5 , 0x111a , 0x1106 , 0x1107 , 0x1108 , 0x1121 , 0x1109 , 0x110a , 0x110b , 0x110c , 0x110d , 0x110e , 0x110f , 0x1110 , 0x1111 , 0x1112 , 0x1161 , 0x1162 , 0x1163 , 0x1164 , 0x1165 , 0x1166 , 0x1167 , 0x1168 , 0x1169 , 0x116a , 0x116b , 0x116c , 0x116d , 0x116e , 0x116f , 0x1170 , 0x1171 , 0x1172 , 0x1173 , 0x1174 , 0x1175 , 0x1160 , 0x1114 , 0x1115 , 0x11c7 , 0x11c8 , 0x11cc , 0x11ce , 0x11d3 , 0x11d7 , 0x11d9 , 0x111c , 0x11dd , 0x11df , 0x111d , 0x111e , 0x1120 , 0x1122 , 0x1123 , 0x1127 , 0x1129 , 0x112b , 0x112c , 0x112d , 0x112e , 0x112f , 0x1132 , 0x1136 , 0x1140 , 0x1147 , 0x114c , 0x11f1 , 0x11f2 , 0x1157 , 0x1158 , 0x1159 , 0x1184 , 0x1185 , 0x1188 , 0x1191 , 0x1192 , 0x1194 , 0x119e , 0x11a1 , 0x4e09 , 0x56db , 0x4e0a , 0x4e2d , 0x4e0b , 0x7532 , 0x4e19 , 0x4e01 , 0x5929 , 0x5730 , 0x28 , 0x1100 , 0x29 , 0x28 , 0x1102 , 0x29 , 0x28 , 0x1103 , 0x29 , 0x28 , 0x1105 , 0x29 , 0x28 , 0x1106 , 0x29 , 0x28 , 0x1107 , 0x29 , 0x28 , 0x1109 , 0x29 , 0x28 , 0x110b , 0x29 , 0x28 , 0x110c , 0x29 , 0x28 , 0x110e , 0x29 , 0x28 , 0x110f , 0x29 , 0x28 , 0x1110 , 0x29 , 0x28 , 0x1111 , 0x29 , 0x28 , 0x1112 , 0x29 , 0x28 , 0x1100 , 0x1161 , 0x29 , 0x28 , 0x1102 , 0x1161 , 0x29 , 0x28 , 0x1103 , 0x1161 , 0x29 , 0x28 , 0x1105 , 0x1161 , 0x29 , 0x28 , 0x1106 , 0x1161 , 0x29 , 0x28 , 0x1107 , 0x1161 , 0x29 , 0x28 , 0x1109 , 0x1161 , 0x29 , 0x28 , 0x110b , 0x1161 , 0x29 , 0x28 , 0x110c , 0x1161 , 0x29 , 0x28 , 0x110e , 0x1161 , 0x29 , 0x28 , 0x110f , 0x1161 , 0x29 , 0x28 , 0x1110 , 0x1161 , 0x29 , 0x28 , 0x1111 , 0x1161 , 0x29 , 0x28 , 0x1112 , 0x1161 , 0x29 , 0x28 , 0x110c , 0x116e , 0x29 , 0x28 , 0x110b , 0x1169 , 0x110c , 0x1165 , 0x11ab , 0x29 , 0x28 , 0x110b , 0x1169 , 0x1112 , 0x116e , 0x29 , 0x28 , 0x4e00 , 0x29 , 0x28 , 0x4e8c , 0x29 , 0x28 , 0x4e09 , 0x29 , 0x28 , 0x56db , 0x29 , 0x28 , 0x4e94 , 0x29 , 0x28 , 0x516d , 0x29 , 0x28 , 0x4e03 , 0x29 , 0x28 , 0x516b , 0x29 , 0x28 , 0x4e5d , 0x29 , 0x28 , 0x5341 , 0x29 , 0x28 , 0x6708 , 0x29 , 0x28 , 0x706b , 0x29 , 0x28 , 0x6c34 , 0x29 , 0x28 , 0x6728 , 0x29 , 0x28 , 0x91d1 , 0x29 , 0x28 , 0x571f , 0x29 , 0x28 , 0x65e5 , 0x29 , 0x28 , 0x682a , 0x29 , 0x28 , 0x6709 , 0x29 , 0x28 , 0x793e , 0x29 , 0x28 , 0x540d , 0x29 , 0x28 , 0x7279 , 0x29 , 0x28 , 0x8ca1 , 0x29 , 0x28 , 0x795d , 0x29 , 0x28 , 0x52b4 , 0x29 , 0x28 , 0x4ee3 , 0x29 , 0x28 , 0x547c , 0x29 , 0x28 , 0x5b66 , 0x29 , 0x28 , 0x76e3 , 0x29 , 0x28 , 0x4f01 , 0x29 , 0x28 , 0x8cc7 , 0x29 , 0x28 , 0x5354 , 0x29 , 0x28 , 0x796d , 0x29 , 0x28 , 0x4f11 , 0x29 , 0x28 , 0x81ea , 0x29 , 0x28 , 0x81f3 , 0x29 , 0x50 , 0x54 , 0x45 , 0x32 , 0x31 , 0x32 , 0x32 , 0x32 , 0x33 , 0x32 , 0x34 , 0x32 , 0x35 , 0x32 , 0x36 , 0x32 , 0x37 , 0x32 , 0x38 , 0x32 , 0x39 , 0x33 , 0x30 , 0x33 , 0x31 , 0x33 , 0x32 , 0x33 , 0x33 , 0x33 , 0x34 , 0x33 , 0x35 , 0x1100 , 0x1161 , 0x1102 , 0x1161 , 0x1103 , 0x1161 , 0x1105 , 0x1161 , 0x1106 , 0x1161 , 0x1107 , 0x1161 , 0x1109 , 0x1161 , 0x110b , 0x1161 , 0x110c , 0x1161 , 0x110e , 0x1161 , 0x110f , 0x1161 , 0x1110 , 0x1161 , 0x1111 , 0x1161 , 0x1112 , 0x1161 , 0x110e , 0x1161 , 0x11b7 , 0x1100 , 0x1169 , 0x110c , 0x116e , 0x110b , 0x1174 , 0x110b , 0x116e , 0x4e94 , 0x516d , 0x4e03 , 0x4e5d , 0x682a , 0x6709 , 0x793e , 0x540d , 0x7279 , 0x8ca1 , 0x795d , 0x52b4 , 0x79d8 , 0x7537 , 0x9069 , 0x512a , 0x5370 , 0x6ce8 , 0x9805 , 0x4f11 , 0x5199 , 0x6b63 , 0x5de6 , 0x53f3 , 0x533b , 0x5b97 , 0x5b66 , 0x76e3 , 0x4f01 , 0x8cc7 , 0x5354 , 0x591c , 0x33 , 0x36 , 0x33 , 0x37 , 0x33 , 0x38 , 0x33 , 0x39 , 0x34 , 0x30 , 0x34 , 0x31 , 0x34 , 0x32 , 0x34 , 0x33 , 0x34 , 0x34 , 0x34 , 0x35 , 0x34 , 0x36 , 0x34 , 0x37 , 0x34 , 0x38 , 0x34 , 0x39 , 0x35 , 0x30 , 0x31 , 0x6708 , 0x32 , 0x6708 , 0x33 , 0x6708 , 0x34 , 0x6708 , 0x35 , 0x6708 , 0x36 , 0x6708 , 0x37 , 0x6708 , 0x38 , 0x6708 , 0x39 , 0x6708 , 0x31 , 0x30 , 0x6708 , 0x31 , 0x31 , 0x6708 , 0x31 , 0x32 , 0x6708 , 0x48 , 0x67 , 0x65 , 0x72 , 0x67 , 0x65 , 0x56 , 0x4c , 0x54 , 0x44 , 0x30a2 , 0x30a4 , 0x30a6 , 0x30a8 , 0x30aa , 0x30ab , 0x30ad , 0x30af , 0x30b1 , 0x30b3 , 0x30b5 , 0x30b7 , 0x30b9 , 0x30bb , 0x30bd , 0x30bf , 0x30c1 , 0x30c4 , 0x30c6 , 0x30c8 , 0x30ca , 0x30cb , 0x30cc , 0x30cd , 0x30ce , 0x30cf , 0x30d2 , 0x30d5 , 0x30d8 , 0x30db , 0x30de , 0x30df , 0x30e0 , 0x30e1 , 0x30e2 , 0x30e4 , 0x30e6 , 0x30e8 , 0x30e9 , 0x30ea , 0x30eb , 0x30ec , 0x30ed , 0x30ef , 0x30f0 , 0x30f1 , 0x30f2 , 0x30a2 , 0x30cf , 0x309a , 0x30fc , 0x30c8 , 0x30a2 , 0x30eb , 0x30d5 , 0x30a1 , 0x30a2 , 0x30f3 , 0x30d8 , 0x309a , 0x30a2 , 0x30a2 , 0x30fc , 0x30eb , 0x30a4 , 0x30cb , 0x30f3 , 0x30af , 0x3099 , 0x30a4 , 0x30f3 , 0x30c1 , 0x30a6 , 0x30a9 , 0x30f3 , 0x30a8 , 0x30b9 , 0x30af , 0x30fc , 0x30c8 , 0x3099 , 0x30a8 , 0x30fc , 0x30ab , 0x30fc , 0x30aa , 0x30f3 , 0x30b9 , 0x30aa , 0x30fc , 0x30e0 , 0x30ab , 0x30a4 , 0x30ea , 0x30ab , 0x30e9 , 0x30c3 , 0x30c8 , 0x30ab , 0x30ed , 0x30ea , 0x30fc , 0x30ab , 0x3099 , 0x30ed , 0x30f3 , 0x30ab , 0x3099 , 0x30f3 , 0x30de , 0x30ad , 0x3099 , 0x30ab , 0x3099 , 0x30ad , 0x3099 , 0x30cb , 0x30fc , 0x30ad , 0x30e5 , 0x30ea , 0x30fc , 0x30ad , 0x3099 , 0x30eb , 0x30bf , 0x3099 , 0x30fc , 0x30ad , 0x30ed , 0x30ad , 0x30ed , 0x30af , 0x3099 , 0x30e9 , 0x30e0 , 0x30ad , 0x30ed , 0x30e1 , 0x30fc , 0x30c8 , 0x30eb , 0x30ad , 0x30ed , 0x30ef , 0x30c3 , 0x30c8 , 0x30af , 0x3099 , 0x30e9 , 0x30e0 , 0x30af , 0x3099 , 0x30e9 , 0x30e0 , 0x30c8 , 0x30f3 , 0x30af , 0x30eb , 0x30bb , 0x3099 , 0x30a4 , 0x30ed , 0x30af , 0x30ed , 0x30fc , 0x30cd , 0x30b1 , 0x30fc , 0x30b9 , 0x30b3 , 0x30eb , 0x30ca , 0x30b3 , 0x30fc , 0x30db , 0x309a , 0x30b5 , 0x30a4 , 0x30af , 0x30eb , 0x30b5 , 0x30f3 , 0x30c1 , 0x30fc , 0x30e0 , 0x30b7 , 0x30ea , 0x30f3 , 0x30af , 0x3099 , 0x30bb , 0x30f3 , 0x30c1 , 0x30bb , 0x30f3 , 0x30c8 , 0x30bf , 0x3099 , 0x30fc , 0x30b9 , 0x30c6 , 0x3099 , 0x30b7 , 0x30c8 , 0x3099 , 0x30eb , 0x30c8 , 0x30f3 , 0x30ca , 0x30ce , 0x30ce , 0x30c3 , 0x30c8 , 0x30cf , 0x30a4 , 0x30c4 , 0x30cf , 0x309a , 0x30fc , 0x30bb , 0x30f3 , 0x30c8 , 0x30cf , 0x309a , 0x30fc , 0x30c4 , 0x30cf , 0x3099 , 0x30fc , 0x30ec , 0x30eb , 0x30d2 , 0x309a , 0x30a2 , 0x30b9 , 0x30c8 , 0x30eb , 0x30d2 , 0x309a , 0x30af , 0x30eb , 0x30d2 , 0x309a , 0x30b3 , 0x30d2 , 0x3099 , 0x30eb , 0x30d5 , 0x30a1 , 0x30e9 , 0x30c3 , 0x30c8 , 0x3099 , 0x30d5 , 0x30a3 , 0x30fc , 0x30c8 , 0x30d5 , 0x3099 , 0x30c3 , 0x30b7 , 0x30a7 , 0x30eb , 0x30d5 , 0x30e9 , 0x30f3 , 0x30d8 , 0x30af , 0x30bf , 0x30fc , 0x30eb , 0x30d8 , 0x309a , 0x30bd , 0x30d8 , 0x309a , 0x30cb , 0x30d2 , 0x30d8 , 0x30eb , 0x30c4 , 0x30d8 , 0x309a , 0x30f3 , 0x30b9 , 0x30d8 , 0x309a , 0x30fc , 0x30b7 , 0x3099 , 0x30d8 , 0x3099 , 0x30fc , 0x30bf , 0x30db , 0x309a , 0x30a4 , 0x30f3 , 0x30c8 , 0x30db , 0x3099 , 0x30eb , 0x30c8 , 0x30db , 0x30f3 , 0x30db , 0x309a , 0x30f3 , 0x30c8 , 0x3099 , 0x30db , 0x30fc , 0x30eb , 0x30db , 0x30fc , 0x30f3 , 0x30de , 0x30a4 , 0x30af , 0x30ed , 0x30de , 0x30a4 , 0x30eb , 0x30de , 0x30c3 , 0x30cf , 0x30de , 0x30eb , 0x30af , 0x30de , 0x30f3 , 0x30b7 , 0x30e7 , 0x30f3 , 0x30df , 0x30af , 0x30ed , 0x30f3 , 0x30df , 0x30ea , 0x30df , 0x30ea , 0x30cf , 0x3099 , 0x30fc , 0x30eb , 0x30e1 , 0x30ab , 0x3099 , 0x30e1 , 0x30ab , 0x3099 , 0x30c8 , 0x30f3 , 0x30e1 , 0x30fc , 0x30c8 , 0x30eb , 0x30e4 , 0x30fc , 0x30c8 , 0x3099 , 0x30e4 , 0x30fc , 0x30eb , 0x30e6 , 0x30a2 , 0x30f3 , 0x30ea , 0x30c3 , 0x30c8 , 0x30eb , 0x30ea , 0x30e9 , 0x30eb , 0x30d2 , 0x309a , 0x30fc , 0x30eb , 0x30fc , 0x30d5 , 0x3099 , 0x30eb , 0x30ec , 0x30e0 , 0x30ec , 0x30f3 , 0x30c8 , 0x30b1 , 0x3099 , 0x30f3 , 0x30ef , 0x30c3 , 0x30c8 , 0x30 , 0x70b9 , 0x31 , 0x70b9 , 0x32 , 0x70b9 , 0x33 , 0x70b9 , 0x34 , 0x70b9 , 0x35 , 0x70b9 , 0x36 , 0x70b9 , 0x37 , 0x70b9 , 0x38 , 0x70b9 , 0x39 , 0x70b9 , 0x31 , 0x30 , 0x70b9 , 0x31 , 0x31 , 0x70b9 , 0x31 , 0x32 , 0x70b9 , 0x31 , 0x33 , 0x70b9 , 0x31 , 0x34 , 0x70b9 , 0x31 , 0x35 , 0x70b9 , 0x31 , 0x36 , 0x70b9 , 0x31 , 0x37 , 0x70b9 , 0x31 , 0x38 , 0x70b9 , 0x31 , 0x39 , 0x70b9 , 0x32 , 0x30 , 0x70b9 , 0x32 , 0x31 , 0x70b9 , 0x32 , 0x32 , 0x70b9 , 0x32 , 0x33 , 0x70b9 , 0x32 , 0x34 , 0x70b9 , 0x68 , 0x50 , 0x61 , 0x64 , 0x61 , 0x41 , 0x55 , 0x62 , 0x61 , 0x72 , 0x6f , 0x56 , 0x70 , 0x63 , 0x64 , 0x6d , 0x64 , 0x6d , 0x32 , 0x64 , 0x6d , 0x33 , 0x49 , 0x55 , 0x5e73 , 0x6210 , 0x662d , 0x548c , 0x5927 , 0x6b63 , 0x660e , 0x6cbb , 0x682a , 0x5f0f , 0x4f1a , 0x793e , 0x70 , 0x41 , 0x6e , 0x41 , 0x3bc , 0x41 , 0x6d , 0x41 , 0x6b , 0x41 , 0x4b , 0x42 , 0x4d , 0x42 , 0x47 , 0x42 , 0x63 , 0x61 , 0x6c , 0x6b , 0x63 , 0x61 , 0x6c , 0x70 , 0x46 , 0x6e , 0x46 , 0x3bc , 0x46 , 0x3bc , 0x67 , 0x6d , 0x67 , 0x6b , 0x67 , 0x48 , 0x7a , 0x6b , 0x48 , 0x7a , 0x4d , 0x48 , 0x7a , 0x47 , 0x48 , 0x7a , 0x54 , 0x48 , 0x7a , 0x3bc , 0x6c , 0x6d , 0x6c , 0x64 , 0x6c , 0x6b , 0x6c , 0x66 , 0x6d , 0x6e , 0x6d , 0x3bc , 0x6d , 0x6d , 0x6d , 0x63 , 0x6d , 0x6b , 0x6d , 0x6d , 0x6d , 0x32 , 0x63 , 0x6d , 0x32 , 0x6d , 0x32 , 0x6b , 0x6d , 0x32 , 0x6d , 0x6d , 0x33 , 0x63 , 0x6d , 0x33 , 0x6d , 0x33 , 0x6b , 0x6d , 0x33 , 0x6d , 0x2215 , 0x73 , 0x6d , 0x2215 , 0x73 , 0x32 , 0x50 , 0x61 , 0x6b , 0x50 , 0x61 , 0x4d , 0x50 , 0x61 , 0x47 , 0x50 , 0x61 , 0x72 , 0x61 , 0x64 , 0x72 , 0x61 , 0x64 , 0x2215 , 0x73 , 0x72 , 0x61 , 0x64 , 0x2215 , 0x73 , 0x32 , 0x70 , 0x73 , 0x6e , 0x73 , 0x3bc , 0x73 , 0x6d , 0x73 , 0x70 , 0x56 , 0x6e , 0x56 , 0x3bc , 0x56 , 0x6d , 0x56 , 0x6b , 0x56 , 0x4d , 0x56 , 0x70 , 0x57 , 0x6e , 0x57 , 0x3bc , 0x57 , 0x6d , 0x57 , 0x6b , 0x57 , 0x4d , 0x57 , 0x6b , 0x3a9 , 0x4d , 0x3a9 , 0x61 , 0x2e , 0x6d , 0x2e , 0x42 , 0x71 , 0x63 , 0x63 , 0x63 , 0x64 , 0x43 , 0x2215 , 0x6b , 0x67 , 0x43 , 0x6f , 0x2e , 0x64 , 0x42 , 0x47 , 0x79 , 0x68 , 0x61 , 0x48 , 0x50 , 0x69 , 0x6e , 0x4b , 0x4b , 0x4b , 0x4d , 0x6b , 0x74 , 0x6c , 0x6d , 0x6c , 0x6e , 0x6c , 0x6f , 0x67 , 0x6c , 0x78 , 0x6d , 0x62 , 0x6d , 0x69 , 0x6c , 0x6d , 0x6f , 0x6c , 0x50 , 0x48 , 0x70 , 0x2e , 0x6d , 0x2e , 0x50 , 0x50 , 0x4d , 0x50 , 0x52 , 0x73 , 0x72 , 0x53 , 0x76 , 0x57 , 0x62 , 0x56 , 0x2215 , 0x6d , 0x41 , 0x2215 , 0x6d , 0x31 , 0x65e5 , 0x32 , 0x65e5 , 0x33 , 0x65e5 , 0x34 , 0x65e5 , 0x35 , 0x65e5 , 0x36 , 0x65e5 , 0x37 , 0x65e5 , 0x38 , 0x65e5 , 0x39 , 0x65e5 , 0x31 , 0x30 , 0x65e5 , 0x31 , 0x31 , 0x65e5 , 0x31 , 0x32 , 0x65e5 , 0x31 , 0x33 , 0x65e5 , 0x31 , 0x34 , 0x65e5 , 0x31 , 0x35 , 0x65e5 , 0x31 , 0x36 , 0x65e5 , 0x31 , 0x37 , 0x65e5 , 0x31 , 0x38 , 0x65e5 , 0x31 , 0x39 , 0x65e5 , 0x32 , 0x30 , 0x65e5 , 0x32 , 0x31 , 0x65e5 , 0x32 , 0x32 , 0x65e5 , 0x32 , 0x33 , 0x65e5 , 0x32 , 0x34 , 0x65e5 , 0x32 , 0x35 , 0x65e5 , 0x32 , 0x36 , 0x65e5 , 0x32 , 0x37 , 0x65e5 , 0x32 , 0x38 , 0x65e5 , 0x32 , 0x39 , 0x65e5 , 0x33 , 0x30 , 0x65e5 , 0x33 , 0x31 , 0x65e5 , 0x67 , 0x61 , 0x6c , 0x66 , 0x66 , 0x66 , 0x69 , 0x66 , 0x6c , 0x66 , 0x66 , 0x69 , 0x66 , 0x66 , 0x6c , 0x73 , 0x74 , 0x574 , 0x576 , 0x574 , 0x565 , 0x574 , 0x56b , 0x57e , 0x576 , 0x574 , 0x56d , 0x5e2 , 0x5d4 , 0x5db , 0x5dc , 0x5dd , 0x5e8 , 0x5ea , 0x5d0 , 0x5dc , 0x671 , 0x67b , 0x67e , 0x680 , 0x67a , 0x67f , 0x679 , 0x6a4 , 0x6a6 , 0x684 , 0x683 , 0x686 , 0x687 , 0x68d , 0x68c , 0x68e , 0x688 , 0x698 , 0x691 , 0x6a9 , 0x6af , 0x6b3 , 0x6b1 , 0x6ba , 0x6bb , 0x6d5 , 0x654 , 0x6c1 , 0x6be , 0x6d2 , 0x6d2 , 0x654 , 0x6ad , 0x6c7 , 0x6c6 , 0x6c8 , 0x6cb , 0x6c5 , 0x6c9 , 0x6d0 , 0x649 , 0x64a , 0x654 , 0x627 , 0x64a , 0x654 , 0x6d5 , 0x64a , 0x654 , 0x648 , 0x64a , 0x654 , 0x6c7 , 0x64a , 0x654 , 0x6c6 , 0x64a , 0x654 , 0x6c8 , 0x64a , 0x654 , 0x6d0 , 0x64a , 0x654 , 0x649 , 0x6cc , 0x64a , 0x654 , 0x62c , 0x64a , 0x654 , 0x62d , 0x64a , 0x654 , 0x645 , 0x64a , 0x654 , 0x64a , 0x628 , 0x62c , 0x628 , 0x62d , 0x628 , 0x62e , 0x628 , 0x645 , 0x628 , 0x649 , 0x628 , 0x64a , 0x62a , 0x62c , 0x62a , 0x62d , 0x62a , 0x62e , 0x62a , 0x645 , 0x62a , 0x649 , 0x62a , 0x64a , 0x62b , 0x62c , 0x62b , 0x645 , 0x62b , 0x649 , 0x62b , 0x64a , 0x62c , 0x62d , 0x62c , 0x645 , 0x62d , 0x62c , 0x62d , 0x645 , 0x62e , 0x62c , 0x62e , 0x62d , 0x62e , 0x645 , 0x633 , 0x62c , 0x633 , 0x62d , 0x633 , 0x62e , 0x633 , 0x645 , 0x635 , 0x62d , 0x635 , 0x645 , 0x636 , 0x62c , 0x636 , 0x62d , 0x636 , 0x62e , 0x636 , 0x645 , 0x637 , 0x62d , 0x637 , 0x645 , 0x638 , 0x645 , 0x639 , 0x62c , 0x639 , 0x645 , 0x63a , 0x62c , 0x63a , 0x645 , 0x641 , 0x62c , 0x641 , 0x62d , 0x641 , 0x62e , 0x641 , 0x645 , 0x641 , 0x649 , 0x641 , 0x64a , 0x642 , 0x62d , 0x642 , 0x645 , 0x642 , 0x649 , 0x642 , 0x64a , 0x643 , 0x627 , 0x643 , 0x62c , 0x643 , 0x62d , 0x643 , 0x62e , 0x643 , 0x644 , 0x643 , 0x645 , 0x643 , 0x649 , 0x643 , 0x64a , 0x644 , 0x62c , 0x644 , 0x62d , 0x644 , 0x62e , 0x644 , 0x645 , 0x644 , 0x649 , 0x644 , 0x64a , 0x645 , 0x62c , 0x645 , 0x62d , 0x645 , 0x62e , 0x645 , 0x645 , 0x645 , 0x649 , 0x645 , 0x64a , 0x646 , 0x62c , 0x646 , 0x62d , 0x646 , 0x62e , 0x646 , 0x645 , 0x646 , 0x649 , 0x646 , 0x64a , 0x647 , 0x62c , 0x647 , 0x645 , 0x647 , 0x649 , 0x647 , 0x64a , 0x64a , 0x62c , 0x64a , 0x62d , 0x64a , 0x62e , 0x64a , 0x645 , 0x64a , 0x649 , 0x64a , 0x64a , 0x630 , 0x670 , 0x631 , 0x670 , 0x649 , 0x670 , 0x20 , 0x64c , 0x651 , 0x20 , 0x64d , 0x651 , 0x20 , 0x64e , 0x651 , 0x20 , 0x64f , 0x651 , 0x20 , 0x650 , 0x651 , 0x20 , 0x651 , 0x670 , 0x64a , 0x654 , 0x631 , 0x64a , 0x654 , 0x632 , 0x64a , 0x654 , 0x646 , 0x628 , 0x631 , 0x628 , 0x632 , 0x628 , 0x646 , 0x62a , 0x631 , 0x62a , 0x632 , 0x62a , 0x646 , 0x62b , 0x631 , 0x62b , 0x632 , 0x62b , 0x646 , 0x645 , 0x627 , 0x646 , 0x631 , 0x646 , 0x632 , 0x646 , 0x646 , 0x64a , 0x631 , 0x64a , 0x632 , 0x64a , 0x646 , 0x64a , 0x654 , 0x62e , 0x64a , 0x654 , 0x647 , 0x628 , 0x647 , 0x62a , 0x647 , 0x635 , 0x62e , 0x644 , 0x647 , 0x646 , 0x647 , 0x647 , 0x670 , 0x64a , 0x647 , 0x62b , 0x647 , 0x633 , 0x647 , 0x634 , 0x645 , 0x634 , 0x647 , 0x640 , 0x64e , 0x651 , 0x640 , 0x64f , 0x651 , 0x640 , 0x650 , 0x651 , 0x637 , 0x649 , 0x637 , 0x64a , 0x639 , 0x649 , 0x639 , 0x64a , 0x63a , 0x649 , 0x63a , 0x64a , 0x633 , 0x649 , 0x633 , 0x64a , 0x634 , 0x649 , 0x634 , 0x64a , 0x62d , 0x649 , 0x62d , 0x64a , 0x62c , 0x649 , 0x62c , 0x64a , 0x62e , 0x649 , 0x62e , 0x64a , 0x635 , 0x649 , 0x635 , 0x64a , 0x636 , 0x649 , 0x636 , 0x64a , 0x634 , 0x62c , 0x634 , 0x62d , 0x634 , 0x62e , 0x634 , 0x631 , 0x633 , 0x631 , 0x635 , 0x631 , 0x636 , 0x631 , 0x627 , 0x64b , 0x62a , 0x62c , 0x645 , 0x62a , 0x62d , 0x62c , 0x62a , 0x62d , 0x645 , 0x62a , 0x62e , 0x645 , 0x62a , 0x645 , 0x62c , 0x62a , 0x645 , 0x62d , 0x62a , 0x645 , 0x62e , 0x62c , 0x645 , 0x62d , 0x62d , 0x645 , 0x64a , 0x62d , 0x645 , 0x649 , 0x633 , 0x62d , 0x62c , 0x633 , 0x62c , 0x62d , 0x633 , 0x62c , 0x649 , 0x633 , 0x645 , 0x62d , 0x633 , 0x645 , 0x62c , 0x633 , 0x645 , 0x645 , 0x635 , 0x62d , 0x62d , 0x635 , 0x645 , 0x645 , 0x634 , 0x62d , 0x645 , 0x634 , 0x62c , 0x64a , 0x634 , 0x645 , 0x62e , 0x634 , 0x645 , 0x645 , 0x636 , 0x62d , 0x649 , 0x636 , 0x62e , 0x645 , 0x637 , 0x645 , 0x62d , 0x637 , 0x645 , 0x645 , 0x637 , 0x645 , 0x64a , 0x639 , 0x62c , 0x645 , 0x639 , 0x645 , 0x645 , 0x639 , 0x645 , 0x649 , 0x63a , 0x645 , 0x645 , 0x63a , 0x645 , 0x64a , 0x63a , 0x645 , 0x649 , 0x641 , 0x62e , 0x645 , 0x642 , 0x645 , 0x62d , 0x642 , 0x645 , 0x645 , 0x644 , 0x62d , 0x645 , 0x644 , 0x62d , 0x64a , 0x644 , 0x62d , 0x649 , 0x644 , 0x62c , 0x62c , 0x644 , 0x62e , 0x645 , 0x644 , 0x645 , 0x62d , 0x645 , 0x62d , 0x62c , 0x645 , 0x62d , 0x645 , 0x645 , 0x62d , 0x64a , 0x645 , 0x62c , 0x62d , 0x645 , 0x62c , 0x645 , 0x645 , 0x62e , 0x62c , 0x645 , 0x62e , 0x645 , 0x645 , 0x62c , 0x62e , 0x647 , 0x645 , 0x62c , 0x647 , 0x645 , 0x645 , 0x646 , 0x62d , 0x645 , 0x646 , 0x62d , 0x649 , 0x646 , 0x62c , 0x645 , 0x646 , 0x62c , 0x649 , 0x646 , 0x645 , 0x64a , 0x646 , 0x645 , 0x649 , 0x64a , 0x645 , 0x645 , 0x628 , 0x62e , 0x64a , 0x62a , 0x62c , 0x64a , 0x62a , 0x62c , 0x649 , 0x62a , 0x62e , 0x64a , 0x62a , 0x62e , 0x649 , 0x62a , 0x645 , 0x64a , 0x62a , 0x645 , 0x649 , 0x62c , 0x645 , 0x64a , 0x62c , 0x62d , 0x649 , 0x62c , 0x645 , 0x649 , 0x633 , 0x62e , 0x649 , 0x635 , 0x62d , 0x64a , 0x634 , 0x62d , 0x64a , 0x636 , 0x62d , 0x64a , 0x644 , 0x62c , 0x64a , 0x644 , 0x645 , 0x64a , 0x64a , 0x62d , 0x64a , 0x64a , 0x62c , 0x64a , 0x64a , 0x645 , 0x64a , 0x645 , 0x645 , 0x64a , 0x642 , 0x645 , 0x64a , 0x646 , 0x62d , 0x64a , 0x639 , 0x645 , 0x64a , 0x643 , 0x645 , 0x64a , 0x646 , 0x62c , 0x62d , 0x645 , 0x62e , 0x64a , 0x644 , 0x62c , 0x645 , 0x643 , 0x645 , 0x645 , 0x62c , 0x62d , 0x64a , 0x62d , 0x62c , 0x64a , 0x645 , 0x62c , 0x64a , 0x641 , 0x645 , 0x64a , 0x628 , 0x62d , 0x64a , 0x633 , 0x62e , 0x64a , 0x646 , 0x62c , 0x64a , 0x635 , 0x644 , 0x6d2 , 0x642 , 0x644 , 0x6d2 , 0x627 , 0x644 , 0x644 , 0x647 , 0x627 , 0x643 , 0x628 , 0x631 , 0x645 , 0x62d , 0x645 , 0x62f , 0x635 , 0x644 , 0x639 , 0x645 , 0x631 , 0x633 , 0x648 , 0x644 , 0x639 , 0x644 , 0x64a , 0x647 , 0x648 , 0x633 , 0x644 , 0x645 , 0x635 , 0x644 , 0x649 , 0x635 , 0x644 , 0x649 , 0x20 , 0x627 , 0x644 , 0x644 , 0x647 , 0x20 , 0x639 , 0x644 , 0x64a , 0x647 , 0x20 , 0x648 , 0x633 , 0x644 , 0x645 , 0x62c , 0x644 , 0x20 , 0x62c , 0x644 , 0x627 , 0x644 , 0x647 , 0x631 , 0x6cc , 0x627 , 0x644 , 0x2c , 0x3001 , 0x3002 , 0x3a , 0x3b , 0x21 , 0x3f , 0x3016 , 0x3017 , 0x2014 , 0x2013 , 0x5f , 0x7b , 0x7d , 0x3014 , 0x3015 , 0x3010 , 0x3011 , 0x300a , 0x300b , 0x3008 , 0x3009 , 0x300c , 0x300d , 0x300e , 0x300f , 0x5b , 0x5d , 0x23 , 0x26 , 0x2a , 0x2d , 0x3c , 0x3e , 0x5c , 0x24 , 0x25 , 0x40 , 0x20 , 0x64b , 0x640 , 0x64b , 0x20 , 0x64c , 0x20 , 0x64d , 0x20 , 0x64e , 0x640 , 0x64e , 0x20 , 0x64f , 0x640 , 0x64f , 0x20 , 0x650 , 0x640 , 0x650 , 0x20 , 0x651 , 0x640 , 0x651 , 0x20 , 0x652 , 0x640 , 0x652 , 0x621 , 0x627 , 0x653 , 0x627 , 0x654 , 0x648 , 0x654 , 0x627 , 0x655 , 0x64a , 0x654 , 0x627 , 0x628 , 0x629 , 0x62a , 0x62b , 0x62c , 0x62d , 0x62e , 0x62f , 0x630 , 0x631 , 0x632 , 0x633 , 0x634 , 0x635 , 0x636 , 0x637 , 0x638 , 0x639 , 0x63a , 0x641 , 0x642 , 0x643 , 0x644 , 0x645 , 0x646 , 0x647 , 0x648 , 0x64a , 0x644 , 0x627 , 0x653 , 0x644 , 0x627 , 0x654 , 0x644 , 0x627 , 0x655 , 0x644 , 0x627 , 0x22 , 0x27 , 0x2f , 0x5e , 0x60 , 0x7c , 0x7e , 0x2985 , 0x2986 , 0x30fb , 0x30a1 , 0x30a3 , 0x30a5 , 0x30a7 , 0x30a9 , 0x30e3 , 0x30e5 , 0x30e7 , 0x30c3 , 0x30fc , 0x30f3 , 0x3099 , 0x309a , 0xa2 , 0xa3 , 0xac , 0xa6 , 0xa5 , 0x20a9 , 0x2502 , 0x2190 , 0x2191 , 0x2192 , 0x2193 , 0x25a0 , 0x25cb , 0x131 , 0x237 , 0x391 , 0x392 , 0x394 , 0x395 , 0x396 , 0x397 , 0x399 , 0x39a , 0x39b , 0x39c , 0x39d , 0x39e , 0x39f , 0x3a1 , 0x3a4 , 0x3a6 , 0x3a7 , 0x3a8 , 0x3a9 , 0x2207 , 0x3b1 , 0x3b6 , 0x3b7 , 0x3b9 , 0x3bb , 0x3bd , 0x3be , 0x3bf , 0x3c3 , 0x3c4 , 0x3c5 , 0x3c8 , 0x3c9 , 0x2202 }
; 
static void init_iconv () {
  /* No conversion */
}
typedef struct Scheme_Converter {
  Scheme_Object so ; 
  short closed ; 
  short kind ; 
  iconv_t cd ; 
  int permissive ; 
  Scheme_Custodian_Reference * mref ; 
}
Scheme_Converter ; 
static int locale_on ; 
static const mzchar * current_locale_name = (mzchar * ) "xxxx\0\0\0\0" ; 
static void reset_locale (void ) ; 
static const char * const STRING_IS_NOT_UTF_8 = "string is not a well-formed UTF-8 encoding: " ; 
static Scheme_Object * make_string (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_length (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_eq (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_locale_eq (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_ci_eq (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_locale_ci_eq (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_lt (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_locale_lt (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_gt (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_locale_gt (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_lt_eq (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_gt_eq (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_ci_lt (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_locale_ci_lt (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_ci_gt (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_locale_ci_gt (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_ci_lt_eq (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_ci_gt_eq (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_upcase (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_downcase (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_titlecase (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_foldcase (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_locale_upcase (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_locale_downcase (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * substring (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_append (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_to_list (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * list_to_string (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_copy (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_copy_bang (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_fill (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_to_immutable (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_normalize_c (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_normalize_kc (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_normalize_d (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_normalize_kd (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * make_byte_string (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * byte_string (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * byte_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * byte_string_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * byte_string_length (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * byte_string_eq (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * byte_string_lt (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * byte_string_gt (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * byte_substring (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * byte_string_append (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * byte_string_to_list (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * list_to_byte_string (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * byte_string_copy (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * byte_string_copy_bang (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * byte_string_fill (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * byte_string_to_immutable (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * byte_string_utf8_index (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * byte_string_utf8_ref (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * byte_string_utf8_length (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * byte_string_to_char_string (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * byte_string_to_char_string_locale (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * byte_string_to_char_string_latin1 (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * char_string_to_byte_string (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * char_string_to_byte_string_locale (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * char_string_to_byte_string_latin1 (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * char_string_utf8_length (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * version (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * format (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * sch_printf (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * sch_fprintf (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * banner (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * sch_getenv (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * sch_putenv (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * system_type (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * system_library_subpath (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * cmdline_args (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * current_locale (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * locale_string_encoding (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * system_language_country (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * byte_string_open_converter (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * byte_string_close_converter (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * byte_string_convert (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * byte_string_convert_end (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * byte_converter_p (int argc , Scheme_Object * argv [] ) ; 
static void register_traversers (void ) ; 
static int mz_char_strcmp (const char * who , const mzchar * str1 , int l1 , const mzchar * str2 , int l2 , int locale , int size_shortcut ) ; 
static int mz_char_strcmp_ci (const char * who , const mzchar * str1 , int l1 , const mzchar * str2 , int l2 , int locale , int size_shortcut ) ; 
static int mz_strcmp (const char * who , unsigned char * str1 , int l1 , unsigned char * str2 , int l2 ) ; 
__xform_nongcing__ static int utf8_decode_x (const unsigned char * s , int start , int end , unsigned int * us , int dstart , int dend , long * ipos , long * jpos , char compact , char utf16 , int * state , int might_continue , int permissive ) ; 
__xform_nongcing__ static int utf8_encode_x (const unsigned int * us , int start , int end , unsigned char * s , int dstart , int dend , long * _ipos , long * _opos , char utf16 ) ; 
static char * string_to_from_locale (int to_bytes , char * in , int delta , int len , long * olen , int perm , int * no_cvt ) ; 
static Scheme_Object * sys_symbol ; 
static Scheme_Object * platform_3m_path , * platform_cgc_path ; 
static Scheme_Object * zero_length_char_string ; 
static Scheme_Object * zero_length_byte_string ; 
static Scheme_Hash_Table * putenv_str_table ; 
static char * embedding_banner ; 
static Scheme_Object * vers_str , * banner_str ; 
static Scheme_Object * complete_symbol , * continues_symbol , * aborts_symbol , * error_symbol ; 
void scheme_init_string (Scheme_Env * env ) {
  Scheme_Object * p ; 
  Scheme_Object * __funcarg126 = NULLED_OUT ; 
  Scheme_Object * __funcarg125 = NULLED_OUT ; 
  Scheme_Object * __funcarg124 = NULLED_OUT ; 
  Scheme_Object * __funcarg123 = NULLED_OUT ; 
  Scheme_Object * __funcarg122 = NULLED_OUT ; 
  Scheme_Object * __funcarg121 = NULLED_OUT ; 
  Scheme_Object * __funcarg120 = NULLED_OUT ; 
  Scheme_Object * __funcarg119 = NULLED_OUT ; 
  Scheme_Object * __funcarg118 = NULLED_OUT ; 
  Scheme_Object * __funcarg117 = NULLED_OUT ; 
  Scheme_Object * __funcarg116 = NULLED_OUT ; 
  Scheme_Object * __funcarg115 = NULLED_OUT ; 
  Scheme_Object * __funcarg114 = NULLED_OUT ; 
  Scheme_Object * __funcarg113 = NULLED_OUT ; 
  Scheme_Object * __funcarg112 = NULLED_OUT ; 
  Scheme_Object * __funcarg111 = NULLED_OUT ; 
  Scheme_Object * __funcarg110 = NULLED_OUT ; 
  Scheme_Object * __funcarg109 = NULLED_OUT ; 
  Scheme_Object * __funcarg108 = NULLED_OUT ; 
  Scheme_Object * __funcarg107 = NULLED_OUT ; 
  Scheme_Object * __funcarg106 = NULLED_OUT ; 
  Scheme_Object * __funcarg105 = NULLED_OUT ; 
  Scheme_Object * __funcarg104 = NULLED_OUT ; 
  Scheme_Object * __funcarg103 = NULLED_OUT ; 
  Scheme_Object * __funcarg102 = NULLED_OUT ; 
  Scheme_Object * __funcarg101 = NULLED_OUT ; 
  Scheme_Object * __funcarg100 = NULLED_OUT ; 
  Scheme_Object * __funcarg99 = NULLED_OUT ; 
  Scheme_Object * __funcarg98 = NULLED_OUT ; 
  Scheme_Object * __funcarg97 = NULLED_OUT ; 
  Scheme_Object * __funcarg96 = NULLED_OUT ; 
  Scheme_Object * __funcarg95 = NULLED_OUT ; 
  Scheme_Object * __funcarg94 = NULLED_OUT ; 
  Scheme_Object * __funcarg93 = NULLED_OUT ; 
  Scheme_Object * __funcarg92 = NULLED_OUT ; 
  Scheme_Object * __funcarg91 = NULLED_OUT ; 
  Scheme_Object * __funcarg90 = NULLED_OUT ; 
  Scheme_Object * __funcarg89 = NULLED_OUT ; 
  Scheme_Object * __funcarg88 = NULLED_OUT ; 
  Scheme_Object * __funcarg87 = NULLED_OUT ; 
  Scheme_Object * __funcarg86 = NULLED_OUT ; 
  Scheme_Object * __funcarg85 = NULLED_OUT ; 
  Scheme_Object * __funcarg84 = NULLED_OUT ; 
  Scheme_Object * __funcarg83 = NULLED_OUT ; 
  Scheme_Object * __funcarg82 = NULLED_OUT ; 
  Scheme_Object * __funcarg81 = NULLED_OUT ; 
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
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(p, 1)));
# define XfOrM2_COUNT (2)
# define SETUP_XfOrM2(x) SETUP(XfOrM2_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  p = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM2(_), scheme_register_static ((void * ) & sys_symbol , sizeof (sys_symbol ) ) ); 
  sys_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("unix" ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & zero_length_char_string , sizeof (zero_length_char_string ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & zero_length_byte_string , sizeof (zero_length_byte_string ) ) ); 
  zero_length_char_string = FUNCCALL_AGAIN(scheme_alloc_char_string (0 , 0 ) ); 
  zero_length_byte_string = FUNCCALL_AGAIN(scheme_alloc_byte_string (0 , 0 ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & complete_symbol , sizeof (complete_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & continues_symbol , sizeof (continues_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & aborts_symbol , sizeof (aborts_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & error_symbol , sizeof (error_symbol ) ) ); 
  complete_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("complete" ) ); 
  continues_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("continues" ) ); 
  aborts_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("aborts" ) ); 
  error_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("error" ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & platform_3m_path , sizeof (platform_3m_path ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & platform_3m_path , sizeof (platform_3m_path ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & platform_cgc_path , sizeof (platform_cgc_path ) ) ); 
  platform_cgc_path = FUNCCALL_AGAIN(scheme_make_path ("x86_64-linux" ) ); 
  platform_3m_path = FUNCCALL_AGAIN(scheme_make_path ("x86_64-linux" "/3m" ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & putenv_str_table , sizeof (putenv_str_table ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & embedding_banner , sizeof (embedding_banner ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & current_locale_name , sizeof (current_locale_name ) ) ); 
  p = FUNCCALL_AGAIN(scheme_make_folding_prim (string_p , "string?" , 1 , 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 16384 ; 
  FUNCCALL(SETUP_XfOrM2(_), scheme_add_global_constant ("string?" , p , env ) ); 
  (__funcarg126 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (make_string , "make-string" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-string" , __funcarg126 , env ) )) ; 
  (__funcarg125 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string , "string" , 0 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string" , __funcarg125 , env ) )) ; 
  (__funcarg124 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_folding_prim (string_length , "string-length" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string-length" , __funcarg124 , env ) )) ; 
  p = FUNCCALL_AGAIN(scheme_make_noncm_prim (scheme_checked_string_ref , "string-ref" , 2 , 2 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 512 ; 
  FUNCCALL(SETUP_XfOrM2(_), scheme_add_global_constant ("string-ref" , p , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_noncm_prim (scheme_checked_string_set , "string-set!" , 3 , 3 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 32768 ; 
  FUNCCALL(SETUP_XfOrM2(_), scheme_add_global_constant ("string-set!" , p , env ) ); 
  (__funcarg123 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_eq , "string=?" , 2 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string=?" , __funcarg123 , env ) )) ; 
  (__funcarg122 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_locale_eq , "string-locale=?" , 2 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string-locale=?" , __funcarg122 , env ) )) ; 
  (__funcarg121 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_ci_eq , "string-ci=?" , 2 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string-ci=?" , __funcarg121 , env ) )) ; 
  (__funcarg120 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_locale_ci_eq , "string-locale-ci=?" , 2 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string-locale-ci=?" , __funcarg120 , env ) )) ; 
  (__funcarg119 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_lt , "string<?" , 2 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string<?" , __funcarg119 , env ) )) ; 
  (__funcarg118 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_locale_lt , "string-locale<?" , 2 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string-locale<?" , __funcarg118 , env ) )) ; 
  (__funcarg117 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_gt , "string>?" , 2 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string>?" , __funcarg117 , env ) )) ; 
  (__funcarg116 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_locale_gt , "string-locale>?" , 2 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string-locale>?" , __funcarg116 , env ) )) ; 
  (__funcarg115 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_lt_eq , "string<=?" , 2 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string<=?" , __funcarg115 , env ) )) ; 
  (__funcarg114 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_gt_eq , "string>=?" , 2 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string>=?" , __funcarg114 , env ) )) ; 
  (__funcarg113 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_ci_lt , "string-ci<?" , 2 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string-ci<?" , __funcarg113 , env ) )) ; 
  (__funcarg112 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_locale_ci_lt , "string-locale-ci<?" , 2 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string-locale-ci<?" , __funcarg112 , env ) )) ; 
  (__funcarg111 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_ci_gt , "string-ci>?" , 2 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string-ci>?" , __funcarg111 , env ) )) ; 
  (__funcarg110 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_locale_ci_gt , "string-locale-ci>?" , 2 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string-locale-ci>?" , __funcarg110 , env ) )) ; 
  (__funcarg109 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_ci_lt_eq , "string-ci<=?" , 2 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string-ci<=?" , __funcarg109 , env ) )) ; 
  (__funcarg108 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_ci_gt_eq , "string-ci>=?" , 2 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string-ci>=?" , __funcarg108 , env ) )) ; 
  (__funcarg107 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (substring , "substring" , 2 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("substring" , __funcarg107 , env ) )) ; 
  (__funcarg106 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_append , "string-append" , 0 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string-append" , __funcarg106 , env ) )) ; 
  (__funcarg105 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_to_list , "string->list" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string->list" , __funcarg105 , env ) )) ; 
  (__funcarg104 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (list_to_string , "list->string" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("list->string" , __funcarg104 , env ) )) ; 
  (__funcarg103 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_copy , "string-copy" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string-copy" , __funcarg103 , env ) )) ; 
  (__funcarg102 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_copy_bang , "string-copy!" , 3 , 5 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string-copy!" , __funcarg102 , env ) )) ; 
  (__funcarg101 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_fill , "string-fill!" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string-fill!" , __funcarg101 , env ) )) ; 
  (__funcarg100 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_to_immutable , "string->immutable-string" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string->immutable-string" , __funcarg100 , env ) )) ; 
  (__funcarg99 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_normalize_c , "string-normalize-nfc" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string-normalize-nfc" , __funcarg99 , env ) )) ; 
  (__funcarg98 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_normalize_kc , "string-normalize-nfkc" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string-normalize-nfkc" , __funcarg98 , env ) )) ; 
  (__funcarg97 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_normalize_d , "string-normalize-nfd" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string-normalize-nfd" , __funcarg97 , env ) )) ; 
  (__funcarg96 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_normalize_kd , "string-normalize-nfkd" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string-normalize-nfkd" , __funcarg96 , env ) )) ; 
  (__funcarg95 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_upcase , "string-upcase" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string-upcase" , __funcarg95 , env ) )) ; 
  (__funcarg94 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_downcase , "string-downcase" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string-downcase" , __funcarg94 , env ) )) ; 
  (__funcarg93 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_titlecase , "string-titlecase" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string-titlecase" , __funcarg93 , env ) )) ; 
  (__funcarg92 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_foldcase , "string-foldcase" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string-foldcase" , __funcarg92 , env ) )) ; 
  (__funcarg91 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_locale_upcase , "string-locale-upcase" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string-locale-upcase" , __funcarg91 , env ) )) ; 
  (__funcarg90 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (string_locale_downcase , "string-locale-downcase" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string-locale-downcase" , __funcarg90 , env ) )) ; 
  (__funcarg89 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (current_locale , "current-locale" , MZCONFIG_LOCALE ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-locale" , __funcarg89 , env ) )) ; 
  (__funcarg88 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (locale_string_encoding , "locale-string-encoding" , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("locale-string-encoding" , __funcarg88 , env ) )) ; 
  (__funcarg87 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (system_language_country , "system-language+country" , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("system-language+country" , __funcarg87 , env ) )) ; 
  (__funcarg86 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (byte_converter_p , "bytes-converter?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("bytes-converter?" , __funcarg86 , env ) )) ; 
  (__funcarg85 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_everything (byte_string_convert , 0 , "bytes-convert" , 1 , 7 , 0 , 3 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("bytes-convert" , __funcarg85 , env ) )) ; 
  (__funcarg84 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_everything (byte_string_convert_end , 0 , "bytes-convert-end" , 0 , 3 , 0 , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("bytes-convert-end" , __funcarg84 , env ) )) ; 
  (__funcarg83 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (byte_string_open_converter , "bytes-open-converter" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("bytes-open-converter" , __funcarg83 , env ) )) ; 
  (__funcarg82 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (byte_string_close_converter , "bytes-close-converter" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("bytes-close-converter" , __funcarg82 , env ) )) ; 
  (__funcarg81 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (format , "format" , 1 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("format" , __funcarg81 , env ) )) ; 
  (__funcarg80 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (sch_printf , "printf" , 1 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("printf" , __funcarg80 , env ) )) ; 
  (__funcarg79 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (sch_fprintf , "fprintf" , 2 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("fprintf" , __funcarg79 , env ) )) ; 
  (__funcarg78 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_folding_prim (byte_p , "byte?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("byte?" , __funcarg78 , env ) )) ; 
  p = FUNCCALL_AGAIN(scheme_make_folding_prim (byte_string_p , "bytes?" , 1 , 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 32768 ; 
  FUNCCALL(SETUP_XfOrM2(_), scheme_add_global_constant ("bytes?" , p , env ) ); 
  (__funcarg77 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (make_byte_string , "make-bytes" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-bytes" , __funcarg77 , env ) )) ; 
  (__funcarg76 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (byte_string , "bytes" , 0 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("bytes" , __funcarg76 , env ) )) ; 
  (__funcarg75 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_folding_prim (byte_string_length , "bytes-length" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("bytes-length" , __funcarg75 , env ) )) ; 
  p = FUNCCALL_AGAIN(scheme_make_noncm_prim (scheme_checked_byte_string_ref , "bytes-ref" , 2 , 2 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 512 ; 
  FUNCCALL(SETUP_XfOrM2(_), scheme_add_global_constant ("bytes-ref" , p , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_noncm_prim (scheme_checked_byte_string_set , "bytes-set!" , 3 , 3 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 32768 ; 
  FUNCCALL(SETUP_XfOrM2(_), scheme_add_global_constant ("bytes-set!" , p , env ) ); 
  (__funcarg74 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (byte_string_eq , "bytes=?" , 2 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("bytes=?" , __funcarg74 , env ) )) ; 
  (__funcarg73 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (byte_string_lt , "bytes<?" , 2 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("bytes<?" , __funcarg73 , env ) )) ; 
  (__funcarg72 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (byte_string_gt , "bytes>?" , 2 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("bytes>?" , __funcarg72 , env ) )) ; 
  (__funcarg71 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (byte_substring , "subbytes" , 2 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("subbytes" , __funcarg71 , env ) )) ; 
  (__funcarg70 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (byte_string_append , "bytes-append" , 0 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("bytes-append" , __funcarg70 , env ) )) ; 
  (__funcarg69 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (byte_string_to_list , "bytes->list" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("bytes->list" , __funcarg69 , env ) )) ; 
  (__funcarg68 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (list_to_byte_string , "list->bytes" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("list->bytes" , __funcarg68 , env ) )) ; 
  (__funcarg67 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (byte_string_copy , "bytes-copy" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("bytes-copy" , __funcarg67 , env ) )) ; 
  (__funcarg66 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (byte_string_copy_bang , "bytes-copy!" , 3 , 5 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("bytes-copy!" , __funcarg66 , env ) )) ; 
  (__funcarg65 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (byte_string_fill , "bytes-fill!" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("bytes-fill!" , __funcarg65 , env ) )) ; 
  (__funcarg64 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (byte_string_to_immutable , "bytes->immutable-bytes" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("bytes->immutable-bytes" , __funcarg64 , env ) )) ; 
  (__funcarg63 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (byte_string_utf8_index , "bytes-utf-8-index" , 2 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("bytes-utf-8-index" , __funcarg63 , env ) )) ; 
  (__funcarg62 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (byte_string_utf8_length , "bytes-utf-8-length" , 1 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("bytes-utf-8-length" , __funcarg62 , env ) )) ; 
  (__funcarg61 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (byte_string_utf8_ref , "bytes-utf-8-ref" , 2 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("bytes-utf-8-ref" , __funcarg61 , env ) )) ; 
  (__funcarg60 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (byte_string_to_char_string , "bytes->string/utf-8" , 1 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("bytes->string/utf-8" , __funcarg60 , env ) )) ; 
  (__funcarg59 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (byte_string_to_char_string_locale , "bytes->string/locale" , 1 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("bytes->string/locale" , __funcarg59 , env ) )) ; 
  (__funcarg58 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (byte_string_to_char_string_latin1 , "bytes->string/latin-1" , 1 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("bytes->string/latin-1" , __funcarg58 , env ) )) ; 
  (__funcarg57 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (char_string_to_byte_string , "string->bytes/utf-8" , 1 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string->bytes/utf-8" , __funcarg57 , env ) )) ; 
  (__funcarg56 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (char_string_to_byte_string_locale , "string->bytes/locale" , 1 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string->bytes/locale" , __funcarg56 , env ) )) ; 
  (__funcarg55 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (char_string_to_byte_string_latin1 , "string->bytes/latin-1" , 1 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string->bytes/latin-1" , __funcarg55 , env ) )) ; 
  (__funcarg54 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (char_string_utf8_length , "string-utf-8-length" , 1 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string-utf-8-length" , __funcarg54 , env ) )) ; 
  (__funcarg53 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (version , "version" , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("version" , __funcarg53 , env ) )) ; 
  (__funcarg52 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (banner , "banner" , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("banner" , __funcarg52 , env ) )) ; 
  (__funcarg51 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (sch_getenv , "getenv" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("getenv" , __funcarg51 , env ) )) ; 
  (__funcarg50 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (sch_putenv , "putenv" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("putenv" , __funcarg50 , env ) )) ; 
  (__funcarg49 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (system_type , "system-type" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("system-type" , __funcarg49 , env ) )) ; 
  (__funcarg48 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_noncm_prim (system_library_subpath , "system-library-subpath" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("system-library-subpath" , __funcarg48 , env ) )) ; 
  (__funcarg47 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (cmdline_args , "current-command-line-arguments" , MZCONFIG_CMDLINE_ARGS ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-command-line-arguments" , __funcarg47 , env ) )) ; 
  FUNCCALL_EMPTY(register_traversers () ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_sized_offset_utf8_string (char * chars , long d , long len ) {
  long ulen ; 
  mzchar * us ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(us, 0), PUSH(chars, 1)));
# define XfOrM3_COUNT (2)
# define SETUP_XfOrM3(x) SETUP(XfOrM3_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  us = NULLED_OUT ; 
  if (len ) {
#   define XfOrM5_COUNT (0+XfOrM3_COUNT)
#   define SETUP_XfOrM5(x) SETUP_XfOrM3(x)
    ulen = FUNCCALL(SETUP_XfOrM5(_), scheme_utf8_decode ((unsigned char * ) chars , d , d + len , ((void * ) 0 ) , 0 , - 1 , ((void * ) 0 ) , 0 , '?' ) ); 
    us = FUNCCALL(SETUP_XfOrM5(_), GC_malloc_atomic (sizeof (mzchar ) * (ulen + 1 ) ) ); 
    FUNCCALL_AGAIN(scheme_utf8_decode ((unsigned char * ) chars , d , d + len , us , 0 , - 1 , ((void * ) 0 ) , 0 , '?' ) ); 
    us [ulen ] = 0 ; 
  }
  else {
    us = (mzchar * ) "\0\0\0" ; 
    ulen = 0 ; 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_offset_char_string (us , 0 , ulen , 0 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_sized_utf8_string (char * chars , long len ) {
  /* No conversion */
  return scheme_make_sized_offset_utf8_string (chars , 0 , len ) ; 
}
Scheme_Object * scheme_make_immutable_sized_utf8_string (char * chars , long len ) {
  Scheme_Object * s ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(s, 0)));
# define XfOrM7_COUNT (1)
# define SETUP_XfOrM7(x) SETUP(XfOrM7_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  s = FUNCCALL(SETUP_XfOrM7(_), scheme_make_sized_offset_utf8_string (chars , 0 , len ) ); 
  if (len )
    ((((Scheme_Inclhash_Object * ) (s ) ) -> so . keyex |= 0x1 ) ) ; 
  RET_VALUE_START (s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_utf8_string (const char * chars ) {
  /* No conversion */
  return scheme_make_sized_offset_utf8_string ((char * ) chars , 0 , - 1 ) ; 
}
Scheme_Object * scheme_make_locale_string (const char * chars ) {
  Scheme_Object * __funcarg127 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(0);
# define XfOrM9_COUNT (0)
# define SETUP_XfOrM9(x) SETUP(XfOrM9_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg127 = FUNCCALL_EMPTY(scheme_make_byte_string ((char * ) chars ) ), FUNCCALL_EMPTY(scheme_byte_string_to_char_string_locale (__funcarg127 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_out_of_string_range (const char * name , const char * which , Scheme_Object * i , Scheme_Object * s , long start , long len ) {
  int is_byte ; 
  char * __funcarg129 = NULLED_OUT ; 
  char * __funcarg128 = NULLED_OUT ; 
  PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(i, 0), PUSH(which, 1), PUSH(name, 2)));
# define XfOrM10_COUNT (3)
# define SETUP_XfOrM10(x) SETUP(XfOrM10_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  is_byte = ((Scheme_Type ) (((((long ) (s ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (s ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ; 
  if ((is_byte ? (((Scheme_Simple_Object * ) (s ) ) -> u . byte_str_val . tag_val ) : (((Scheme_Simple_Object * ) (s ) ) -> u . char_str_val . tag_val ) ) ) {
    char * sstr ; 
    int slen ; 
    BLOCK_SETUP((PUSH(sstr, 0+XfOrM10_COUNT)));
#   define XfOrM12_COUNT (1+XfOrM10_COUNT)
#   define SETUP_XfOrM12(x) SETUP(XfOrM12_COUNT)
    sstr = NULLED_OUT ; 
    sstr = FUNCCALL(SETUP_XfOrM12(_), scheme_make_provided_string (s , 2 , & slen ) ); 
    (__funcarg129 = FUNCCALL(SETUP_XfOrM12(_), scheme_make_provided_string (i , 2 , ((void * ) 0 ) ) ), FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: %sindex %s out of range [%d, %d] for %sstring: %t" , name , which , __funcarg129 , start , len , is_byte ? "byte-" : "" , sstr , slen ) )) ; 
  }
  else {
#   define XfOrM11_COUNT (0+XfOrM10_COUNT)
#   define SETUP_XfOrM11(x) SETUP_XfOrM10(x)
    (__funcarg128 = FUNCCALL(SETUP_XfOrM11(_), scheme_make_provided_string (i , 0 , ((void * ) 0 ) ) ), FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: %sindex %s out of range for empty %sstring" , name , which , __funcarg128 , is_byte ? "byte-" : "" ) )) ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
long scheme_extract_index (const char * name , int pos , int argc , Scheme_Object * * argv , long top , int false_ok ) {
  /* No conversion */
  long i ; 
  int is_top = 0 ; 
  if ((((long ) (argv [pos ] ) ) & 0x1 ) ) {
    i = (((long ) (argv [pos ] ) ) >> 1 ) ; 
  }
  else if (((Scheme_Type ) (((((long ) (argv [pos ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [pos ] ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) {
    if (((& ((Scheme_Bignum * ) argv [pos ] ) -> iso ) -> so . keyex & 0x1 ) ) {
      i = top ; 
      is_top = 1 ; 
    }
    else i = - 1 ; 
  }
  else i = - 1 ; 
  if (! is_top && (i < 0 ) )
    scheme_wrong_type (name , (false_ok ? "non-negative exact integer or #f" : "non-negative exact integer" ) , pos , argc , argv ) ; 
  return i ; 
}
void scheme_get_substring_indices (const char * name , Scheme_Object * str , int argc , Scheme_Object * * argv , int spos , int fpos , long * _start , long * _finish ) {
  long len ; 
  long start , finish ; 
  PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(str, 0), PUSH(_finish, 1), PUSH(_start, 2), PUSH(argv, 3), PUSH(name, 4)));
# define XfOrM17_COUNT (5)
# define SETUP_XfOrM17(x) SETUP(XfOrM17_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (((Scheme_Type ) (((((long ) (str ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (str ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    len = (((Scheme_Simple_Object * ) (str ) ) -> u . char_str_val . tag_val ) ; 
  else len = (((Scheme_Simple_Object * ) (str ) ) -> u . byte_str_val . tag_val ) ; 
  if (argc > spos )
    start = FUNCCALL(SETUP_XfOrM17(_), scheme_extract_index (name , spos , argc , argv , len + 1 , 0 ) ); 
  else start = 0 ; 
  if (argc > fpos )
    finish = FUNCCALL(SETUP_XfOrM17(_), scheme_extract_index (name , fpos , argc , argv , len + 1 , 0 ) ); 
  else finish = len ; 
  if (! (start <= len ) ) {
#   define XfOrM19_COUNT (0+XfOrM17_COUNT)
#   define SETUP_XfOrM19(x) SETUP_XfOrM17(x)
    FUNCCALL(SETUP_XfOrM19(_), scheme_out_of_string_range (name , (fpos < 100 ) ? "starting " : "" , argv [spos ] , str , 0 , len ) ); 
  }
  if (! (finish >= start && finish <= len ) ) {
#   define XfOrM18_COUNT (0+XfOrM17_COUNT)
#   define SETUP_XfOrM18(x) SETUP_XfOrM17(x)
    FUNCCALL(SETUP_XfOrM18(_), scheme_out_of_string_range (name , "ending " , argv [fpos ] , str , start , len ) ); 
  }
  * _start = start ; 
  * _finish = finish ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void get_substring_indices (const char * name , Scheme_Object * str , int argc , Scheme_Object * * argv , int spos , int fpos , long * _start , long * _finish , long len ) {
  /* No conversion */
  if (argc > spos ) {
    if ((((long ) (argv [spos ] ) ) & 0x1 ) ) {
      long start = (((long ) (argv [spos ] ) ) >> 1 ) ; 
      if ((start >= 0 ) && (start < len ) ) {
        * _start = start ; 
        if (argc > fpos ) {
          long finish = (((long ) (argv [fpos ] ) ) >> 1 ) ; 
          if ((finish >= start ) && (finish <= len ) ) {
            * _finish = finish ; 
            return ; 
          }
        }
        else {
          * _finish = len ; 
          return ; 
        }
      }
    }
  }
  else {
    * _start = 0 ; 
    * _finish = len ; 
    return ; 
  }
  scheme_get_substring_indices (name , str , argc , argv , spos , fpos , _start , _finish ) ; 
}
/* this far 21 */
Scheme_Object * scheme_make_sized_offset_char_string (mzchar * chars , long d , long len , int copy ) {
  Scheme_Object * str ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(str, 0), PUSH(chars, 1)));
# define XfOrM28_COUNT (2)
# define SETUP_XfOrM28(x) SETUP(XfOrM28_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  str = NULLED_OUT ; 
  if (! chars )
    chars = (mzchar * ) "\0\0\0" ; 
  str = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM28(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  str -> type = scheme_char_string_type ; 
  if (len < 0 )
    len = FUNCCALL(SETUP_XfOrM28(_), scheme_char_strlen (chars XFORM_OK_PLUS d ) ); 
  if (copy ) {
    mzchar * naya ; 
    BLOCK_SETUP((PUSH(naya, 0+XfOrM28_COUNT)));
#   define XfOrM29_COUNT (1+XfOrM28_COUNT)
#   define SETUP_XfOrM29(x) SETUP(XfOrM29_COUNT)
    naya = NULLED_OUT ; 
    naya = (mzchar * ) FUNCCALL(SETUP_XfOrM29(_), scheme_malloc_fail_ok (GC_malloc_atomic , (len + 1 ) * sizeof (mzchar ) ) ); 
    (((Scheme_Simple_Object * ) (str ) ) -> u . char_str_val . string_val ) = naya ; 
    (memcpy (naya , chars + d , len * sizeof (mzchar ) ) ) ; 
    naya [len ] = 0 ; 
  }
  else (((Scheme_Simple_Object * ) (str ) ) -> u . char_str_val . string_val ) = chars + d ; 
  (((Scheme_Simple_Object * ) (str ) ) -> u . char_str_val . tag_val ) = len ; 
  RET_VALUE_START (str ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_sized_char_string (mzchar * chars , long len , int copy ) {
  /* No conversion */
  return scheme_make_sized_offset_char_string (chars , 0 , len , copy ) ; 
}
Scheme_Object * scheme_make_immutable_sized_char_string (mzchar * chars , long len , int copy ) {
  Scheme_Object * s ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(s, 0)));
# define XfOrM31_COUNT (1)
# define SETUP_XfOrM31(x) SETUP(XfOrM31_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  s = FUNCCALL(SETUP_XfOrM31(_), scheme_make_sized_offset_char_string (chars , 0 , len , copy ) ); 
  ((((Scheme_Inclhash_Object * ) (s ) ) -> so . keyex |= 0x1 ) ) ; 
  RET_VALUE_START (s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_char_string_without_copying (mzchar * chars ) {
  /* No conversion */
  return scheme_make_sized_offset_char_string (chars , 0 , - 1 , 0 ) ; 
}
Scheme_Object * scheme_make_char_string (const mzchar * chars ) {
  /* No conversion */
  return scheme_make_sized_offset_char_string ((mzchar * ) chars , 0 , - 1 , 1 ) ; 
}
Scheme_Object * scheme_alloc_char_string (int size , mzchar fill ) {
  Scheme_Object * str ; 
  mzchar * s ; 
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(str, 1)));
# define XfOrM34_COUNT (2)
# define SETUP_XfOrM34(x) SETUP(XfOrM34_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  str = NULLED_OUT ; 
  s = NULLED_OUT ; 
  if (size < 0 ) {
#   define XfOrM37_COUNT (0+XfOrM34_COUNT)
#   define SETUP_XfOrM37(x) SETUP_XfOrM34(x)
    str = ((Scheme_Object * ) (void * ) (long ) ((((long ) (size ) ) << 1 ) | 0x1 ) ) ; 
    FUNCCALL(SETUP_XfOrM37(_), scheme_wrong_type ("make-" "string" , "non-negative exact integer" , - 1 , 0 , & str ) ); 
  }
  str = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM34(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  str -> type = scheme_char_string_type ; 
  s = (mzchar * ) FUNCCALL(SETUP_XfOrM34(_), scheme_malloc_fail_ok (GC_malloc_atomic , sizeof (mzchar ) * (size + 1 ) ) ); 
  for (i = size ; i -- ; ) {
    s [i ] = fill ; 
  }
  s [size ] = 0 ; 
  (((Scheme_Simple_Object * ) (str ) ) -> u . char_str_val . string_val ) = s ; 
  (((Scheme_Simple_Object * ) (str ) ) -> u . char_str_val . tag_val ) = size ; 
  RET_VALUE_START (str ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * string_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * make_string (int argc , Scheme_Object * argv [] ) {
  long len ; 
  mzchar fill ; 
  Scheme_Object * str ; 
  char * __funcarg130 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(str, 0), PUSH(argv, 1)));
# define XfOrM39_COUNT (2)
# define SETUP_XfOrM39(x) SETUP(XfOrM39_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  str = NULLED_OUT ; 
  len = FUNCCALL(SETUP_XfOrM39(_), scheme_extract_index ("make-" "string" , 0 , argc , argv , - 1 , 0 ) ); 
  if (argc == 2 ) {
#   define XfOrM41_COUNT (0+XfOrM39_COUNT)
#   define SETUP_XfOrM41(x) SETUP_XfOrM39(x)
    if (! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("make-" "string" , "character" , 1 , argc , argv ) ); 
    fill = (mzchar ) (((Scheme_Small_Object * ) (argv [1 ] ) ) -> u . char_val ) ; 
  }
  else fill = 0 ; 
  if (len == - 1 ) {
#   define XfOrM40_COUNT (0+XfOrM39_COUNT)
#   define SETUP_XfOrM40(x) SETUP_XfOrM39(x)
    (__funcarg130 = FUNCCALL(SETUP_XfOrM40(_), scheme_make_provided_string (argv [0 ] , 0 , ((void * ) 0 ) ) ), FUNCCALL_EMPTY(scheme_raise_out_of_memory ("make-" "string" , "making " "" "string of length %s" , __funcarg130 ) )) ; 
  }
  str = FUNCCALL(SETUP_XfOrM39(_), scheme_alloc_char_string (len , fill ) ); 
  RET_VALUE_START (str ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * string (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * str ; 
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(str, 0), PUSH(argv, 1)));
# define XfOrM42_COUNT (2)
# define SETUP_XfOrM42(x) SETUP(XfOrM42_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  str = NULLED_OUT ; 
  str = FUNCCALL(SETUP_XfOrM42(_), scheme_alloc_char_string (argc , 0 ) ); 
  for (i = 0 ; i < argc ; ++ i ) {
#   define XfOrM44_COUNT (0+XfOrM42_COUNT)
#   define SETUP_XfOrM44(x) SETUP_XfOrM42(x)
    if (! ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("string" , "character" , i , argc , argv ) ); 
    (((Scheme_Simple_Object * ) (str ) ) -> u . char_str_val . string_val ) [i ] = (mzchar ) (((Scheme_Small_Object * ) (argv [i ] ) ) -> u . char_val ) ; 
  }
  RET_VALUE_START (str ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * string_length (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    scheme_wrong_type ("string" "-length" , "" "string" , 0 , argc , argv ) ; 
  return ((Scheme_Object * ) (void * ) (long ) ((((long ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) ) ) << 1 ) | 0x1 ) ) ; 
}
Scheme_Object * scheme_checked_string_ref (int argc , Scheme_Object * argv [] ) {
  long i , len ; 
  int c ; 
  mzchar * str ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(str, 0), PUSH(argv, 1)));
# define XfOrM46_COUNT (2)
# define SETUP_XfOrM46(x) SETUP(XfOrM46_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  str = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("string" "-ref" , "" "string" , 0 , argc , argv ) ); 
  str = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) ; 
  len = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) ; 
  i = FUNCCALL(SETUP_XfOrM46(_), scheme_extract_index ("string" "-ref" , 1 , argc , argv , len , 0 ) ); 
  if (i >= len ) {
#   define XfOrM47_COUNT (0+XfOrM46_COUNT)
#   define SETUP_XfOrM47(x) SETUP_XfOrM46(x)
    FUNCCALL(SETUP_XfOrM47(_), scheme_out_of_string_range ("string" "-ref" , "" , argv [1 ] , argv [0 ] , 0 , len - 1 ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  c = ((mzchar * ) str ) [i ] ; 
  RET_VALUE_START (((((mzchar ) c ) < 256 ) ? scheme_char_constants [(unsigned char ) (c ) ] : FUNCCALL_EMPTY(scheme_make_char (c ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_checked_string_set (int argc , Scheme_Object * argv [] ) {
  long i , len ; 
  mzchar * str ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(str, 1)));
# define XfOrM48_COUNT (2)
# define SETUP_XfOrM48(x) SETUP(XfOrM48_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  str = NULLED_OUT ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) && (! (((Scheme_Inclhash_Object * ) (argv [0 ] ) ) -> so . keyex & 0x1 ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("string" "-set!" , "mutable " "" "string" , 0 , argc , argv ) ); 
  str = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) ; 
  len = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) ; 
  i = FUNCCALL(SETUP_XfOrM48(_), scheme_extract_index ("string" "-set!" , 1 , argc , argv , len , 0 ) ); 
  if (! ((Scheme_Type ) (((((long ) (argv [2 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [2 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("string" "-set!" , "character" , 2 , argc , argv ) ); 
  if (i >= len ) {
#   define XfOrM49_COUNT (0+XfOrM48_COUNT)
#   define SETUP_XfOrM49(x) SETUP_XfOrM48(x)
    FUNCCALL(SETUP_XfOrM49(_), scheme_out_of_string_range ("string" "-set!" , "" , argv [1 ] , argv [0 ] , 0 , len - 1 ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  str [i ] = (mzchar ) (((Scheme_Small_Object * ) (argv [2 ] ) ) -> u . char_val ) ; 
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 215 */
static Scheme_Object * substring (int argc , Scheme_Object * argv [] ) {
  long start , finish ; 
  mzchar * chars ; 
  Scheme_Object * str ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(str, 0), PUSH(chars, 1)));
# define XfOrM50_COUNT (2)
# define SETUP_XfOrM50(x) SETUP(XfOrM50_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  chars = NULLED_OUT ; 
  str = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("substring" , "" "string" , 0 , argc , argv ) ); 
  chars = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) ; 
  FUNCCALL(SETUP_XfOrM50(_), get_substring_indices ("substring" , argv [0 ] , argc , argv , 1 , 2 , & start , & finish , (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) ) ); 
  str = FUNCCALL_AGAIN(scheme_alloc_char_string (finish - start , 0 ) ); 
  (memcpy ((((Scheme_Simple_Object * ) (str ) ) -> u . char_str_val . string_val ) , chars + start , (finish - start ) * sizeof (mzchar ) ) ) ; 
  RET_VALUE_START (str ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * string_append (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * naya , * s ; 
  mzchar * chars ; 
  int i ; 
  long len ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(chars, 0), PUSH(naya, 1), PUSH(s, 2), PUSH(argv, 3)));
# define XfOrM51_COUNT (4)
# define SETUP_XfOrM51(x) SETUP(XfOrM51_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  naya = NULLED_OUT ; 
  s = NULLED_OUT ; 
  chars = NULLED_OUT ; 
  len = 0 ; 
  for (i = 0 ; i < argc ; i ++ ) {
#   define XfOrM55_COUNT (0+XfOrM51_COUNT)
#   define SETUP_XfOrM55(x) SETUP_XfOrM51(x)
    s = argv [i ] ; 
    if (! ((Scheme_Type ) (((((long ) (s ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (s ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("string" "-append" , "" "string" , i , argc , argv ) ); 
    len += (((Scheme_Simple_Object * ) (s ) ) -> u . char_str_val . tag_val ) ; 
  }
  if (! len )
    RET_VALUE_START (zero_length_char_string ) RET_VALUE_END ; 
  naya = FUNCCALL(SETUP_XfOrM51(_), scheme_alloc_char_string (len , 0 ) ); 
  chars = (((Scheme_Simple_Object * ) (naya ) ) -> u . char_str_val . string_val ) ; 
  for (i = 0 ; i < argc ; i ++ ) {
#   define XfOrM53_COUNT (0+XfOrM51_COUNT)
#   define SETUP_XfOrM53(x) SETUP_XfOrM51(x)
    s = argv [i ] ; 
    len = (((Scheme_Simple_Object * ) (s ) ) -> u . char_str_val . tag_val ) ; 
    (memcpy (chars , (((Scheme_Simple_Object * ) (s ) ) -> u . char_str_val . string_val ) , len * sizeof (mzchar ) ) ) ; 
    chars = chars XFORM_OK_PLUS len ; 
  }
  RET_VALUE_START (naya ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_append_char_string (Scheme_Object * str1 , Scheme_Object * str2 ) {
  int len1 , len2 ; 
  mzchar * r ; 
  Scheme_Object * naya ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(str1, 0), PUSH(str2, 1), PUSH(r, 2), PUSH(naya, 3)));
# define XfOrM56_COUNT (4)
# define SETUP_XfOrM56(x) SETUP(XfOrM56_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  r = NULLED_OUT ; 
  naya = NULLED_OUT ; 
  len1 = (((Scheme_Simple_Object * ) (str1 ) ) -> u . char_str_val . tag_val ) ; 
  len2 = (((Scheme_Simple_Object * ) (str2 ) ) -> u . char_str_val . tag_val ) ; 
  naya = FUNCCALL(SETUP_XfOrM56(_), scheme_alloc_char_string (len1 + len2 , 0 ) ); 
  r = (((Scheme_Simple_Object * ) (naya ) ) -> u . char_str_val . string_val ) ; 
  (memcpy (r , (((Scheme_Simple_Object * ) (str1 ) ) -> u . char_str_val . string_val ) , len1 * sizeof (mzchar ) ) ) ; 
  (memcpy (r + len1 , (((Scheme_Simple_Object * ) (str2 ) ) -> u . char_str_val . string_val ) , len2 * sizeof (mzchar ) ) ) ; 
  r [len1 + len2 ] = 0 ; 
  RET_VALUE_START (naya ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * string_to_list (int argc , Scheme_Object * argv [] ) {
  int len , i ; 
  mzchar * chars ; 
  Scheme_Object * pair = scheme_null , * v ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(pair, 0), PUSH(v, 1), PUSH(chars, 2)));
# define XfOrM57_COUNT (3)
# define SETUP_XfOrM57(x) SETUP(XfOrM57_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  chars = NULLED_OUT ; 
  v = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("string" "->list" , "" "string" , 0 , argc , argv ) ); 
  chars = (mzchar * ) (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) ; 
  len = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) ; 
  if (len < 0xFFF ) {
#   define XfOrM65_COUNT (0+XfOrM57_COUNT)
#   define SETUP_XfOrM65(x) SETUP_XfOrM57(x)
    for (i = len ; i -- ; ) {
#     define XfOrM67_COUNT (0+XfOrM65_COUNT)
#     define SETUP_XfOrM67(x) SETUP_XfOrM65(x)
      v = ((((mzchar ) chars [i ] ) < 256 ) ? scheme_char_constants [(unsigned char ) (chars [i ] ) ] : FUNCCALL(SETUP_XfOrM67(_), scheme_make_char (chars [i ] ) )) ; 
      pair = FUNCCALL(SETUP_XfOrM67(_), scheme_make_pair (v , pair ) ); 
    }
  }
  else {
#   define XfOrM58_COUNT (0+XfOrM57_COUNT)
#   define SETUP_XfOrM58(x) SETUP_XfOrM57(x)
    for (i = len ; i -- ; ) {
#     define XfOrM62_COUNT (0+XfOrM58_COUNT)
#     define SETUP_XfOrM62(x) SETUP_XfOrM58(x)
      if (! (i & 0xFFF ) ) {
#       define XfOrM63_COUNT (0+XfOrM62_COUNT)
#       define SETUP_XfOrM63(x) SETUP_XfOrM62(x)
        if ((scheme_fuel_counter ) <= 0 ) {
#         define XfOrM64_COUNT (0+XfOrM63_COUNT)
#         define SETUP_XfOrM64(x) SETUP_XfOrM63(x)
          FUNCCALL(SETUP_XfOrM64(_), scheme_out_of_fuel () ); 
        }
      }
      ; 
      v = ((((mzchar ) chars [i ] ) < 256 ) ? scheme_char_constants [(unsigned char ) (chars [i ] ) ] : FUNCCALL(SETUP_XfOrM62(_), scheme_make_char (chars [i ] ) )) ; 
      pair = FUNCCALL(SETUP_XfOrM62(_), scheme_make_pair (v , pair ) ); 
    }
  }
  RET_VALUE_START (pair ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * list_to_string (int argc , Scheme_Object * argv [] ) {
  int len , i ; 
  Scheme_Object * list , * str , * ch ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(list, 0), PUSH(str, 1), PUSH(argv, 2), PUSH(ch, 3)));
# define XfOrM68_COUNT (4)
# define SETUP_XfOrM68(x) SETUP(XfOrM68_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  list = NULLED_OUT ; 
  str = NULLED_OUT ; 
  ch = NULLED_OUT ; 
  list = argv [0 ] ; 
  len = FUNCCALL(SETUP_XfOrM68(_), scheme_list_length (list ) ); 
  str = FUNCCALL_AGAIN(scheme_alloc_char_string (len , 0 ) ); 
  i = 0 ; 
  while (((Scheme_Type ) (((((long ) (list ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (list ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#   define XfOrM70_COUNT (0+XfOrM68_COUNT)
#   define SETUP_XfOrM70(x) SETUP_XfOrM68(x)
    ch = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . car ) ; 
    if (! ((Scheme_Type ) (((((long ) (ch ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ch ) ) -> type ) ) == (Scheme_Type ) (scheme_char_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("list->" "string" , "list of " "character" , 0 , argc , argv ) ); 
    (((Scheme_Simple_Object * ) (str ) ) -> u . char_str_val . string_val ) [i ] = (mzchar ) (((Scheme_Small_Object * ) (ch ) ) -> u . char_val ) ; 
    i ++ ; 
    list = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . cdr ) ; 
  }
  if (! ((list ) == (scheme_null ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("list->" "string" , "list of " "character" , 0 , argc , argv ) ); 
  RET_VALUE_START (str ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * string_copy (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    scheme_wrong_type ("string" "-copy" , "" "string" , 0 , argc , argv ) ; 
  return scheme_make_sized_char_string ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) , (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) , 1 ) ; 
}
/* this far 371 */
/* this far 372 */
/* this far 373 */
static Scheme_Object * string_copy_bang (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * s1 , * s2 ; 
  long istart , ifinish ; 
  long ostart , ofinish ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(s1, 0), PUSH(s2, 1), PUSH(argv, 2)));
# define XfOrM72_COUNT (3)
# define SETUP_XfOrM72(x) SETUP(XfOrM72_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s1 = NULLED_OUT ; 
  s2 = NULLED_OUT ; 
  s1 = argv [0 ] ; 
  if (! (((Scheme_Type ) (((((long ) (s1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (s1 ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) && (! (((Scheme_Inclhash_Object * ) (s1 ) ) -> so . keyex & 0x1 ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("string" "-copy!" , "mutable " "" "string" , 0 , argc , argv ) ); 
  FUNCCALL(SETUP_XfOrM72(_), get_substring_indices ("string" "-copy!" , s1 , argc , argv , 1 , 5 , & ostart , & ofinish , (((Scheme_Simple_Object * ) (s1 ) ) -> u . char_str_val . tag_val ) ) ); 
  s2 = argv [2 ] ; 
  if (! ((Scheme_Type ) (((((long ) (s2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (s2 ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("string" "-copy!" , "" "string" , 2 , argc , argv ) ); 
  FUNCCALL(SETUP_XfOrM72(_), get_substring_indices ("string" "-copy!" , s2 , argc , argv , 3 , 4 , & istart , & ifinish , (((Scheme_Simple_Object * ) (s2 ) ) -> u . char_str_val . tag_val ) ) ); 
  if ((ofinish - ostart ) < (ifinish - istart ) ) {
#   define XfOrM73_COUNT (0+XfOrM72_COUNT)
#   define SETUP_XfOrM73(x) SETUP_XfOrM72(x)
    FUNCCALL(SETUP_XfOrM73(_), scheme_arg_mismatch ("string" "-copy!" , "not enough room in target " "" "string: " , argv [2 ] ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  (memmove ((((Scheme_Simple_Object * ) (s1 ) ) -> u . char_str_val . string_val ) + ostart , (((Scheme_Simple_Object * ) (s2 ) ) -> u . char_str_val . string_val ) + istart , (ifinish - istart ) * sizeof (mzchar ) ) ) ; 
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * string_fill (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  int len , i ; 
  mzchar * chars , ch ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) && (! (((Scheme_Inclhash_Object * ) (argv [0 ] ) ) -> so . keyex & 0x1 ) ) ) )
    scheme_wrong_type ("string" "-fill!" , "mutable " "" "string" , 0 , argc , argv ) ; 
  if (! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_type ) ) )
    scheme_wrong_type ("string" "-fill!" , "character" , 1 , argc , argv ) ; 
  chars = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) ; 
  ch = (mzchar ) (((Scheme_Small_Object * ) (argv [1 ] ) ) -> u . char_val ) ; 
  len = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) ; 
  for (i = 0 ; i < len ; i ++ ) {
    chars [i ] = ch ; 
  }
  return scheme_void ; 
}
static Scheme_Object * string_to_immutable (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * s = argv [0 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(s, 0)));
# define XfOrM77_COUNT (1)
# define SETUP_XfOrM77(x) SETUP(XfOrM77_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! ((Scheme_Type ) (((((long ) (s ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (s ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("string" "->immutable-" "string" , "" "string" , 0 , argc , argv ) ); 
  if ((((Scheme_Type ) (((((long ) (s ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (s ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) && (! (((Scheme_Inclhash_Object * ) (s ) ) -> so . keyex & 0x1 ) ) ) ) {
    Scheme_Object * s2 ; 
    BLOCK_SETUP((PUSH(s2, 0+XfOrM77_COUNT)));
#   define XfOrM78_COUNT (1+XfOrM77_COUNT)
#   define SETUP_XfOrM78(x) SETUP(XfOrM78_COUNT)
    s2 = NULLED_OUT ; 
    s2 = FUNCCALL(SETUP_XfOrM78(_), scheme_make_sized_char_string ((((Scheme_Simple_Object * ) (s ) ) -> u . char_str_val . string_val ) , (((Scheme_Simple_Object * ) (s ) ) -> u . char_str_val . tag_val ) , 1 ) ); 
    ((((Scheme_Inclhash_Object * ) (s2 ) ) -> so . keyex |= 0x1 ) ) ; 
    RET_VALUE_START (s2 ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * append_all_strings_backwards (Scheme_Object * l ) {
  int i , len ; 
  Scheme_Object * * a ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(a, 0), PUSH(l, 1)));
# define XfOrM79_COUNT (2)
# define SETUP_XfOrM79(x) SETUP(XfOrM79_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a = NULLED_OUT ; 
  len = FUNCCALL(SETUP_XfOrM79(_), scheme_list_length (l ) ); 
  a = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM79(_), GC_malloc (sizeof (Scheme_Object * ) * (len ) ) )) ; 
  for (i = len ; i -- ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
    a [i ] = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(string_append (len , a ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * string_eq (int argc , Scheme_Object * argv [] ) {
  mzchar * s , * prev ; 
  int i , sl , pl ; 
  int falz = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(prev, 1), PUSH(argv, 2)));
# define XfOrM82_COUNT (3)
# define SETUP_XfOrM82(x) SETUP(XfOrM82_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  prev = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("string=?" , "string" , 0 , argc , argv ) ); 
  prev = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) ; 
  pl = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) ; 
  for (i = 1 ; i < argc ; i ++ ) {
#   define XfOrM84_COUNT (0+XfOrM82_COUNT)
#   define SETUP_XfOrM84(x) SETUP_XfOrM82(x)
    if (! ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("string=?" , "string" , i , argc , argv ) ); 
    s = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . string_val ) ; 
    sl = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . tag_val ) ; 
    if (! falz )
      if (! (FUNCCALL(SETUP_XfOrM84(_), mz_char_strcmp ("string=?" , prev , pl , s , sl , 0 , 1 ) )== 0 ) )
      falz = 1 ; 
    prev = s ; 
    pl = sl ; 
  }
  RET_VALUE_START (falz ? scheme_false : scheme_true ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * string_lt (int argc , Scheme_Object * argv [] ) {
  mzchar * s , * prev ; 
  int i , sl , pl ; 
  int falz = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(prev, 1), PUSH(argv, 2)));
# define XfOrM85_COUNT (3)
# define SETUP_XfOrM85(x) SETUP(XfOrM85_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  prev = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("string<?" , "string" , 0 , argc , argv ) ); 
  prev = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) ; 
  pl = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) ; 
  for (i = 1 ; i < argc ; i ++ ) {
#   define XfOrM87_COUNT (0+XfOrM85_COUNT)
#   define SETUP_XfOrM87(x) SETUP_XfOrM85(x)
    if (! ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("string<?" , "string" , i , argc , argv ) ); 
    s = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . string_val ) ; 
    sl = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . tag_val ) ; 
    if (! falz )
      if (! (FUNCCALL(SETUP_XfOrM87(_), mz_char_strcmp ("string<?" , prev , pl , s , sl , 0 , 0 ) )< 0 ) )
      falz = 1 ; 
    prev = s ; 
    pl = sl ; 
  }
  RET_VALUE_START (falz ? scheme_false : scheme_true ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * string_gt (int argc , Scheme_Object * argv [] ) {
  mzchar * s , * prev ; 
  int i , sl , pl ; 
  int falz = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(prev, 1), PUSH(argv, 2)));
# define XfOrM88_COUNT (3)
# define SETUP_XfOrM88(x) SETUP(XfOrM88_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  prev = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("string>?" , "string" , 0 , argc , argv ) ); 
  prev = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) ; 
  pl = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) ; 
  for (i = 1 ; i < argc ; i ++ ) {
#   define XfOrM90_COUNT (0+XfOrM88_COUNT)
#   define SETUP_XfOrM90(x) SETUP_XfOrM88(x)
    if (! ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("string>?" , "string" , i , argc , argv ) ); 
    s = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . string_val ) ; 
    sl = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . tag_val ) ; 
    if (! falz )
      if (! (FUNCCALL(SETUP_XfOrM90(_), mz_char_strcmp ("string>?" , prev , pl , s , sl , 0 , 0 ) )> 0 ) )
      falz = 1 ; 
    prev = s ; 
    pl = sl ; 
  }
  RET_VALUE_START (falz ? scheme_false : scheme_true ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * string_lt_eq (int argc , Scheme_Object * argv [] ) {
  mzchar * s , * prev ; 
  int i , sl , pl ; 
  int falz = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(prev, 1), PUSH(argv, 2)));
# define XfOrM91_COUNT (3)
# define SETUP_XfOrM91(x) SETUP(XfOrM91_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  prev = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("string<=?" , "string" , 0 , argc , argv ) ); 
  prev = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) ; 
  pl = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) ; 
  for (i = 1 ; i < argc ; i ++ ) {
#   define XfOrM93_COUNT (0+XfOrM91_COUNT)
#   define SETUP_XfOrM93(x) SETUP_XfOrM91(x)
    if (! ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("string<=?" , "string" , i , argc , argv ) ); 
    s = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . string_val ) ; 
    sl = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . tag_val ) ; 
    if (! falz )
      if (! (FUNCCALL(SETUP_XfOrM93(_), mz_char_strcmp ("string<=?" , prev , pl , s , sl , 0 , 0 ) )<= 0 ) )
      falz = 1 ; 
    prev = s ; 
    pl = sl ; 
  }
  RET_VALUE_START (falz ? scheme_false : scheme_true ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * string_gt_eq (int argc , Scheme_Object * argv [] ) {
  mzchar * s , * prev ; 
  int i , sl , pl ; 
  int falz = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(prev, 1), PUSH(argv, 2)));
# define XfOrM94_COUNT (3)
# define SETUP_XfOrM94(x) SETUP(XfOrM94_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  prev = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("string>=?" , "string" , 0 , argc , argv ) ); 
  prev = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) ; 
  pl = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) ; 
  for (i = 1 ; i < argc ; i ++ ) {
#   define XfOrM96_COUNT (0+XfOrM94_COUNT)
#   define SETUP_XfOrM96(x) SETUP_XfOrM94(x)
    if (! ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("string>=?" , "string" , i , argc , argv ) ); 
    s = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . string_val ) ; 
    sl = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . tag_val ) ; 
    if (! falz )
      if (! (FUNCCALL(SETUP_XfOrM96(_), mz_char_strcmp ("string>=?" , prev , pl , s , sl , 0 , 0 ) )>= 0 ) )
      falz = 1 ; 
    prev = s ; 
    pl = sl ; 
  }
  RET_VALUE_START (falz ? scheme_false : scheme_true ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * string_ci_eq (int argc , Scheme_Object * argv [] ) {
  mzchar * s , * prev ; 
  int i , sl , pl ; 
  int falz = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(prev, 1), PUSH(argv, 2)));
# define XfOrM97_COUNT (3)
# define SETUP_XfOrM97(x) SETUP(XfOrM97_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  prev = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("string-ci=?" , "string" , 0 , argc , argv ) ); 
  prev = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) ; 
  pl = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) ; 
  for (i = 1 ; i < argc ; i ++ ) {
#   define XfOrM99_COUNT (0+XfOrM97_COUNT)
#   define SETUP_XfOrM99(x) SETUP_XfOrM97(x)
    if (! ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("string-ci=?" , "string" , i , argc , argv ) ); 
    s = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . string_val ) ; 
    sl = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . tag_val ) ; 
    if (! falz )
      if (! (FUNCCALL(SETUP_XfOrM99(_), mz_char_strcmp_ci ("string-ci=?" , prev , pl , s , sl , 0 , 0 ) )== 0 ) )
      falz = 1 ; 
    prev = s ; 
    pl = sl ; 
  }
  RET_VALUE_START (falz ? scheme_false : scheme_true ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * string_ci_lt (int argc , Scheme_Object * argv [] ) {
  mzchar * s , * prev ; 
  int i , sl , pl ; 
  int falz = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(prev, 1), PUSH(argv, 2)));
# define XfOrM100_COUNT (3)
# define SETUP_XfOrM100(x) SETUP(XfOrM100_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  prev = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("string-ci<?" , "string" , 0 , argc , argv ) ); 
  prev = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) ; 
  pl = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) ; 
  for (i = 1 ; i < argc ; i ++ ) {
#   define XfOrM102_COUNT (0+XfOrM100_COUNT)
#   define SETUP_XfOrM102(x) SETUP_XfOrM100(x)
    if (! ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("string-ci<?" , "string" , i , argc , argv ) ); 
    s = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . string_val ) ; 
    sl = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . tag_val ) ; 
    if (! falz )
      if (! (FUNCCALL(SETUP_XfOrM102(_), mz_char_strcmp_ci ("string-ci<?" , prev , pl , s , sl , 0 , 0 ) )< 0 ) )
      falz = 1 ; 
    prev = s ; 
    pl = sl ; 
  }
  RET_VALUE_START (falz ? scheme_false : scheme_true ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * string_ci_gt (int argc , Scheme_Object * argv [] ) {
  mzchar * s , * prev ; 
  int i , sl , pl ; 
  int falz = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(prev, 1), PUSH(argv, 2)));
# define XfOrM103_COUNT (3)
# define SETUP_XfOrM103(x) SETUP(XfOrM103_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  prev = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("string-ci>?" , "string" , 0 , argc , argv ) ); 
  prev = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) ; 
  pl = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) ; 
  for (i = 1 ; i < argc ; i ++ ) {
#   define XfOrM105_COUNT (0+XfOrM103_COUNT)
#   define SETUP_XfOrM105(x) SETUP_XfOrM103(x)
    if (! ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("string-ci>?" , "string" , i , argc , argv ) ); 
    s = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . string_val ) ; 
    sl = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . tag_val ) ; 
    if (! falz )
      if (! (FUNCCALL(SETUP_XfOrM105(_), mz_char_strcmp_ci ("string-ci>?" , prev , pl , s , sl , 0 , 0 ) )> 0 ) )
      falz = 1 ; 
    prev = s ; 
    pl = sl ; 
  }
  RET_VALUE_START (falz ? scheme_false : scheme_true ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * string_ci_lt_eq (int argc , Scheme_Object * argv [] ) {
  mzchar * s , * prev ; 
  int i , sl , pl ; 
  int falz = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(prev, 1), PUSH(argv, 2)));
# define XfOrM106_COUNT (3)
# define SETUP_XfOrM106(x) SETUP(XfOrM106_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  prev = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("string-ci<=?" , "string" , 0 , argc , argv ) ); 
  prev = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) ; 
  pl = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) ; 
  for (i = 1 ; i < argc ; i ++ ) {
#   define XfOrM108_COUNT (0+XfOrM106_COUNT)
#   define SETUP_XfOrM108(x) SETUP_XfOrM106(x)
    if (! ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("string-ci<=?" , "string" , i , argc , argv ) ); 
    s = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . string_val ) ; 
    sl = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . tag_val ) ; 
    if (! falz )
      if (! (FUNCCALL(SETUP_XfOrM108(_), mz_char_strcmp_ci ("string-ci<=?" , prev , pl , s , sl , 0 , 0 ) )<= 0 ) )
      falz = 1 ; 
    prev = s ; 
    pl = sl ; 
  }
  RET_VALUE_START (falz ? scheme_false : scheme_true ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * string_ci_gt_eq (int argc , Scheme_Object * argv [] ) {
  mzchar * s , * prev ; 
  int i , sl , pl ; 
  int falz = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(prev, 1), PUSH(argv, 2)));
# define XfOrM109_COUNT (3)
# define SETUP_XfOrM109(x) SETUP(XfOrM109_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  prev = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("string-ci>=?" , "string" , 0 , argc , argv ) ); 
  prev = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) ; 
  pl = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) ; 
  for (i = 1 ; i < argc ; i ++ ) {
#   define XfOrM111_COUNT (0+XfOrM109_COUNT)
#   define SETUP_XfOrM111(x) SETUP_XfOrM109(x)
    if (! ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("string-ci>=?" , "string" , i , argc , argv ) ); 
    s = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . string_val ) ; 
    sl = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . tag_val ) ; 
    if (! falz )
      if (! (FUNCCALL(SETUP_XfOrM111(_), mz_char_strcmp_ci ("string-ci>=?" , prev , pl , s , sl , 0 , 0 ) )>= 0 ) )
      falz = 1 ; 
    prev = s ; 
    pl = sl ; 
  }
  RET_VALUE_START (falz ? scheme_false : scheme_true ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * string_locale_eq (int argc , Scheme_Object * argv [] ) {
  mzchar * s , * prev ; 
  int i , sl , pl ; 
  int falz = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(prev, 1), PUSH(argv, 2)));
# define XfOrM112_COUNT (3)
# define SETUP_XfOrM112(x) SETUP(XfOrM112_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  prev = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("string-locale=?" , "string" , 0 , argc , argv ) ); 
  prev = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) ; 
  pl = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) ; 
  for (i = 1 ; i < argc ; i ++ ) {
#   define XfOrM114_COUNT (0+XfOrM112_COUNT)
#   define SETUP_XfOrM114(x) SETUP_XfOrM112(x)
    if (! ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("string-locale=?" , "string" , i , argc , argv ) ); 
    s = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . string_val ) ; 
    sl = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . tag_val ) ; 
    if (! falz )
      if (! (FUNCCALL(SETUP_XfOrM114(_), mz_char_strcmp ("string-locale=?" , prev , pl , s , sl , 1 , 0 ) )== 0 ) )
      falz = 1 ; 
    prev = s ; 
    pl = sl ; 
  }
  RET_VALUE_START (falz ? scheme_false : scheme_true ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * string_locale_lt (int argc , Scheme_Object * argv [] ) {
  mzchar * s , * prev ; 
  int i , sl , pl ; 
  int falz = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(prev, 1), PUSH(argv, 2)));
# define XfOrM115_COUNT (3)
# define SETUP_XfOrM115(x) SETUP(XfOrM115_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  prev = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("string-locale<?" , "string" , 0 , argc , argv ) ); 
  prev = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) ; 
  pl = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) ; 
  for (i = 1 ; i < argc ; i ++ ) {
#   define XfOrM117_COUNT (0+XfOrM115_COUNT)
#   define SETUP_XfOrM117(x) SETUP_XfOrM115(x)
    if (! ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("string-locale<?" , "string" , i , argc , argv ) ); 
    s = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . string_val ) ; 
    sl = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . tag_val ) ; 
    if (! falz )
      if (! (FUNCCALL(SETUP_XfOrM117(_), mz_char_strcmp ("string-locale<?" , prev , pl , s , sl , 1 , 0 ) )< 0 ) )
      falz = 1 ; 
    prev = s ; 
    pl = sl ; 
  }
  RET_VALUE_START (falz ? scheme_false : scheme_true ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * string_locale_gt (int argc , Scheme_Object * argv [] ) {
  mzchar * s , * prev ; 
  int i , sl , pl ; 
  int falz = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(prev, 1), PUSH(argv, 2)));
# define XfOrM118_COUNT (3)
# define SETUP_XfOrM118(x) SETUP(XfOrM118_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  prev = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("string-locale>?" , "string" , 0 , argc , argv ) ); 
  prev = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) ; 
  pl = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) ; 
  for (i = 1 ; i < argc ; i ++ ) {
#   define XfOrM120_COUNT (0+XfOrM118_COUNT)
#   define SETUP_XfOrM120(x) SETUP_XfOrM118(x)
    if (! ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("string-locale>?" , "string" , i , argc , argv ) ); 
    s = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . string_val ) ; 
    sl = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . tag_val ) ; 
    if (! falz )
      if (! (FUNCCALL(SETUP_XfOrM120(_), mz_char_strcmp ("string-locale>?" , prev , pl , s , sl , 1 , 0 ) )> 0 ) )
      falz = 1 ; 
    prev = s ; 
    pl = sl ; 
  }
  RET_VALUE_START (falz ? scheme_false : scheme_true ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * string_locale_ci_eq (int argc , Scheme_Object * argv [] ) {
  mzchar * s , * prev ; 
  int i , sl , pl ; 
  int falz = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(prev, 1), PUSH(argv, 2)));
# define XfOrM121_COUNT (3)
# define SETUP_XfOrM121(x) SETUP(XfOrM121_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  prev = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("string-locale-ci=?" , "string" , 0 , argc , argv ) ); 
  prev = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) ; 
  pl = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) ; 
  for (i = 1 ; i < argc ; i ++ ) {
#   define XfOrM123_COUNT (0+XfOrM121_COUNT)
#   define SETUP_XfOrM123(x) SETUP_XfOrM121(x)
    if (! ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("string-locale-ci=?" , "string" , i , argc , argv ) ); 
    s = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . string_val ) ; 
    sl = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . tag_val ) ; 
    if (! falz )
      if (! (FUNCCALL(SETUP_XfOrM123(_), mz_char_strcmp_ci ("string-locale-ci=?" , prev , pl , s , sl , 1 , 0 ) )== 0 ) )
      falz = 1 ; 
    prev = s ; 
    pl = sl ; 
  }
  RET_VALUE_START (falz ? scheme_false : scheme_true ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * string_locale_ci_lt (int argc , Scheme_Object * argv [] ) {
  mzchar * s , * prev ; 
  int i , sl , pl ; 
  int falz = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(prev, 1), PUSH(argv, 2)));
# define XfOrM124_COUNT (3)
# define SETUP_XfOrM124(x) SETUP(XfOrM124_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  prev = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("string-locale-ci<?" , "string" , 0 , argc , argv ) ); 
  prev = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) ; 
  pl = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) ; 
  for (i = 1 ; i < argc ; i ++ ) {
#   define XfOrM126_COUNT (0+XfOrM124_COUNT)
#   define SETUP_XfOrM126(x) SETUP_XfOrM124(x)
    if (! ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("string-locale-ci<?" , "string" , i , argc , argv ) ); 
    s = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . string_val ) ; 
    sl = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . tag_val ) ; 
    if (! falz )
      if (! (FUNCCALL(SETUP_XfOrM126(_), mz_char_strcmp_ci ("string-locale-ci<?" , prev , pl , s , sl , 1 , 0 ) )< 0 ) )
      falz = 1 ; 
    prev = s ; 
    pl = sl ; 
  }
  RET_VALUE_START (falz ? scheme_false : scheme_true ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * string_locale_ci_gt (int argc , Scheme_Object * argv [] ) {
  mzchar * s , * prev ; 
  int i , sl , pl ; 
  int falz = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(prev, 1), PUSH(argv, 2)));
# define XfOrM127_COUNT (3)
# define SETUP_XfOrM127(x) SETUP(XfOrM127_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  prev = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("string-locale-ci>?" , "string" , 0 , argc , argv ) ); 
  prev = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) ; 
  pl = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) ; 
  for (i = 1 ; i < argc ; i ++ ) {
#   define XfOrM129_COUNT (0+XfOrM127_COUNT)
#   define SETUP_XfOrM129(x) SETUP_XfOrM127(x)
    if (! ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("string-locale-ci>?" , "string" , i , argc , argv ) ); 
    s = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . string_val ) ; 
    sl = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . char_str_val . tag_val ) ; 
    if (! falz )
      if (! (FUNCCALL(SETUP_XfOrM129(_), mz_char_strcmp_ci ("string-locale-ci>?" , prev , pl , s , sl , 1 , 0 ) )> 0 ) )
      falz = 1 ; 
    prev = s ; 
    pl = sl ; 
  }
  RET_VALUE_START (falz ? scheme_false : scheme_true ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * byte_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return ((((((long ) (argv [0 ] ) ) & 0x1 ) ) && ((((long ) (argv [0 ] ) ) >> 1 ) >= 0 ) && ((((long ) (argv [0 ] ) ) >> 1 ) <= 255 ) ) ? scheme_true : scheme_false ) ; 
}
/* this far 21 */
Scheme_Object * scheme_make_sized_offset_byte_string (char * chars , long d , long len , int copy ) {
  Scheme_Object * str ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(str, 0), PUSH(chars, 1)));
# define XfOrM131_COUNT (2)
# define SETUP_XfOrM131(x) SETUP(XfOrM131_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  str = NULLED_OUT ; 
  if (! chars )
    chars = "" ; 
  str = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM131(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  str -> type = scheme_byte_string_type ; 
  if (len < 0 )
    len = strlen (chars XFORM_OK_PLUS d ) ; 
  if (copy ) {
    char * naya ; 
    BLOCK_SETUP((PUSH(naya, 0+XfOrM131_COUNT)));
#   define XfOrM132_COUNT (1+XfOrM131_COUNT)
#   define SETUP_XfOrM132(x) SETUP(XfOrM132_COUNT)
    naya = NULLED_OUT ; 
    naya = (char * ) FUNCCALL(SETUP_XfOrM132(_), scheme_malloc_fail_ok (GC_malloc_atomic , (len + 1 ) * sizeof (char ) ) ); 
    (((Scheme_Simple_Object * ) (str ) ) -> u . byte_str_val . string_val ) = naya ; 
    (memcpy (naya , chars + d , len * sizeof (char ) ) ) ; 
    naya [len ] = 0 ; 
  }
  else (((Scheme_Simple_Object * ) (str ) ) -> u . byte_str_val . string_val ) = chars + d ; 
  (((Scheme_Simple_Object * ) (str ) ) -> u . byte_str_val . tag_val ) = len ; 
  RET_VALUE_START (str ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_sized_byte_string (char * chars , long len , int copy ) {
  /* No conversion */
  return scheme_make_sized_offset_byte_string (chars , 0 , len , copy ) ; 
}
Scheme_Object * scheme_make_immutable_sized_byte_string (char * chars , long len , int copy ) {
  Scheme_Object * s ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(s, 0)));
# define XfOrM134_COUNT (1)
# define SETUP_XfOrM134(x) SETUP(XfOrM134_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  s = FUNCCALL(SETUP_XfOrM134(_), scheme_make_sized_offset_byte_string (chars , 0 , len , copy ) ); 
  ((((Scheme_Inclhash_Object * ) (s ) ) -> so . keyex |= 0x1 ) ) ; 
  RET_VALUE_START (s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_byte_string_without_copying (char * chars ) {
  /* No conversion */
  return scheme_make_sized_offset_byte_string (chars , 0 , - 1 , 0 ) ; 
}
Scheme_Object * scheme_make_byte_string (const char * chars ) {
  /* No conversion */
  return scheme_make_sized_offset_byte_string ((char * ) chars , 0 , - 1 , 1 ) ; 
}
Scheme_Object * scheme_alloc_byte_string (int size , char fill ) {
  Scheme_Object * str ; 
  char * s ; 
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(str, 1)));
# define XfOrM137_COUNT (2)
# define SETUP_XfOrM137(x) SETUP(XfOrM137_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  str = NULLED_OUT ; 
  s = NULLED_OUT ; 
  if (size < 0 ) {
#   define XfOrM140_COUNT (0+XfOrM137_COUNT)
#   define SETUP_XfOrM140(x) SETUP_XfOrM137(x)
    str = ((Scheme_Object * ) (void * ) (long ) ((((long ) (size ) ) << 1 ) | 0x1 ) ) ; 
    FUNCCALL(SETUP_XfOrM140(_), scheme_wrong_type ("make-" "bytes" , "non-negative exact integer" , - 1 , 0 , & str ) ); 
  }
  str = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM137(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  str -> type = scheme_byte_string_type ; 
  s = (char * ) FUNCCALL(SETUP_XfOrM137(_), scheme_malloc_fail_ok (GC_malloc_atomic , sizeof (char ) * (size + 1 ) ) ); 
  for (i = size ; i -- ; ) {
    s [i ] = fill ; 
  }
  s [size ] = 0 ; 
  (((Scheme_Simple_Object * ) (str ) ) -> u . byte_str_val . string_val ) = s ; 
  (((Scheme_Simple_Object * ) (str ) ) -> u . byte_str_val . tag_val ) = size ; 
  RET_VALUE_START (str ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * byte_string_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * make_byte_string (int argc , Scheme_Object * argv [] ) {
  long len ; 
  char fill ; 
  Scheme_Object * str ; 
  char * __funcarg131 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(str, 0), PUSH(argv, 1)));
# define XfOrM142_COUNT (2)
# define SETUP_XfOrM142(x) SETUP(XfOrM142_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  str = NULLED_OUT ; 
  len = FUNCCALL(SETUP_XfOrM142(_), scheme_extract_index ("make-" "bytes" , 0 , argc , argv , - 1 , 0 ) ); 
  if (argc == 2 ) {
#   define XfOrM144_COUNT (0+XfOrM142_COUNT)
#   define SETUP_XfOrM144(x) SETUP_XfOrM142(x)
    if (! (((((long ) (argv [1 ] ) ) & 0x1 ) ) && ((((long ) (argv [1 ] ) ) >> 1 ) >= 0 ) && ((((long ) (argv [1 ] ) ) >> 1 ) <= 255 ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("make-" "bytes" , "exact integer in [0,255]" , 1 , argc , argv ) ); 
    fill = (char ) (((long ) (argv [1 ] ) ) >> 1 ) ; 
  }
  else fill = 0 ; 
  if (len == - 1 ) {
#   define XfOrM143_COUNT (0+XfOrM142_COUNT)
#   define SETUP_XfOrM143(x) SETUP_XfOrM142(x)
    (__funcarg131 = FUNCCALL(SETUP_XfOrM143(_), scheme_make_provided_string (argv [0 ] , 0 , ((void * ) 0 ) ) ), FUNCCALL_EMPTY(scheme_raise_out_of_memory ("make-" "bytes" , "making " "byte " "string of length %s" , __funcarg131 ) )) ; 
  }
  str = FUNCCALL(SETUP_XfOrM142(_), scheme_alloc_byte_string (len , fill ) ); 
  RET_VALUE_START (str ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * byte_string (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * str ; 
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(str, 0), PUSH(argv, 1)));
# define XfOrM145_COUNT (2)
# define SETUP_XfOrM145(x) SETUP(XfOrM145_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  str = NULLED_OUT ; 
  str = FUNCCALL(SETUP_XfOrM145(_), scheme_alloc_byte_string (argc , 0 ) ); 
  for (i = 0 ; i < argc ; ++ i ) {
#   define XfOrM147_COUNT (0+XfOrM145_COUNT)
#   define SETUP_XfOrM147(x) SETUP_XfOrM145(x)
    if (! (((((long ) (argv [i ] ) ) & 0x1 ) ) && ((((long ) (argv [i ] ) ) >> 1 ) >= 0 ) && ((((long ) (argv [i ] ) ) >> 1 ) <= 255 ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("bytes" , "exact integer in [0,255]" , i , argc , argv ) ); 
    (((Scheme_Simple_Object * ) (str ) ) -> u . byte_str_val . string_val ) [i ] = (char ) (((long ) (argv [i ] ) ) >> 1 ) ; 
  }
  RET_VALUE_START (str ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * byte_string_length (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
    scheme_wrong_type ("bytes" "-length" , "byte " "string" , 0 , argc , argv ) ; 
  return ((Scheme_Object * ) (void * ) (long ) ((((long ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . tag_val ) ) ) << 1 ) | 0x1 ) ) ; 
}
Scheme_Object * scheme_checked_byte_string_ref (int argc , Scheme_Object * argv [] ) {
  long i , len ; 
  int c ; 
  char * str ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(str, 0), PUSH(argv, 1)));
# define XfOrM149_COUNT (2)
# define SETUP_XfOrM149(x) SETUP(XfOrM149_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  str = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("bytes" "-ref" , "byte " "string" , 0 , argc , argv ) ); 
  str = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) ; 
  len = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . tag_val ) ; 
  i = FUNCCALL(SETUP_XfOrM149(_), scheme_extract_index ("bytes" "-ref" , 1 , argc , argv , len , 0 ) ); 
  if (i >= len ) {
#   define XfOrM150_COUNT (0+XfOrM149_COUNT)
#   define SETUP_XfOrM150(x) SETUP_XfOrM149(x)
    FUNCCALL(SETUP_XfOrM150(_), scheme_out_of_string_range ("bytes" "-ref" , "" , argv [1 ] , argv [0 ] , 0 , len - 1 ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  c = ((unsigned char * ) str ) [i ] ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_integer_value (c ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_checked_byte_string_set (int argc , Scheme_Object * argv [] ) {
  long i , len ; 
  char * str ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(str, 1)));
# define XfOrM151_COUNT (2)
# define SETUP_XfOrM151(x) SETUP(XfOrM151_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  str = NULLED_OUT ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) && (! (((Scheme_Inclhash_Object * ) (argv [0 ] ) ) -> so . keyex & 0x1 ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("bytes" "-set!" , "mutable " "byte " "string" , 0 , argc , argv ) ); 
  str = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) ; 
  len = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . tag_val ) ; 
  i = FUNCCALL(SETUP_XfOrM151(_), scheme_extract_index ("bytes" "-set!" , 1 , argc , argv , len , 0 ) ); 
  if (! (((((long ) (argv [2 ] ) ) & 0x1 ) ) && ((((long ) (argv [2 ] ) ) >> 1 ) >= 0 ) && ((((long ) (argv [2 ] ) ) >> 1 ) <= 255 ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("bytes" "-set!" , "exact integer in [0,255]" , 2 , argc , argv ) ); 
  if (i >= len ) {
#   define XfOrM152_COUNT (0+XfOrM151_COUNT)
#   define SETUP_XfOrM152(x) SETUP_XfOrM151(x)
    FUNCCALL(SETUP_XfOrM152(_), scheme_out_of_string_range ("bytes" "-set!" , "" , argv [1 ] , argv [0 ] , 0 , len - 1 ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  str [i ] = (char ) (((long ) (argv [2 ] ) ) >> 1 ) ; 
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 215 */
static Scheme_Object * byte_substring (int argc , Scheme_Object * argv [] ) {
  long start , finish ; 
  char * chars ; 
  Scheme_Object * str ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(str, 0), PUSH(chars, 1)));
# define XfOrM153_COUNT (2)
# define SETUP_XfOrM153(x) SETUP(XfOrM153_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  chars = NULLED_OUT ; 
  str = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("subbytes" , "byte " "string" , 0 , argc , argv ) ); 
  chars = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) ; 
  FUNCCALL(SETUP_XfOrM153(_), get_substring_indices ("subbytes" , argv [0 ] , argc , argv , 1 , 2 , & start , & finish , (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . tag_val ) ) ); 
  str = FUNCCALL_AGAIN(scheme_alloc_byte_string (finish - start , 0 ) ); 
  (memcpy ((((Scheme_Simple_Object * ) (str ) ) -> u . byte_str_val . string_val ) , chars + start , (finish - start ) * sizeof (char ) ) ) ; 
  RET_VALUE_START (str ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * byte_string_append (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * naya , * s ; 
  char * chars ; 
  int i ; 
  long len ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(chars, 0), PUSH(naya, 1), PUSH(s, 2), PUSH(argv, 3)));
# define XfOrM154_COUNT (4)
# define SETUP_XfOrM154(x) SETUP(XfOrM154_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  naya = NULLED_OUT ; 
  s = NULLED_OUT ; 
  chars = NULLED_OUT ; 
  len = 0 ; 
  for (i = 0 ; i < argc ; i ++ ) {
#   define XfOrM158_COUNT (0+XfOrM154_COUNT)
#   define SETUP_XfOrM158(x) SETUP_XfOrM154(x)
    s = argv [i ] ; 
    if (! ((Scheme_Type ) (((((long ) (s ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (s ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("bytes" "-append" , "byte " "string" , i , argc , argv ) ); 
    len += (((Scheme_Simple_Object * ) (s ) ) -> u . byte_str_val . tag_val ) ; 
  }
  if (! len )
    RET_VALUE_START (zero_length_byte_string ) RET_VALUE_END ; 
  naya = FUNCCALL(SETUP_XfOrM154(_), scheme_alloc_byte_string (len , 0 ) ); 
  chars = (((Scheme_Simple_Object * ) (naya ) ) -> u . byte_str_val . string_val ) ; 
  for (i = 0 ; i < argc ; i ++ ) {
#   define XfOrM156_COUNT (0+XfOrM154_COUNT)
#   define SETUP_XfOrM156(x) SETUP_XfOrM154(x)
    s = argv [i ] ; 
    len = (((Scheme_Simple_Object * ) (s ) ) -> u . byte_str_val . tag_val ) ; 
    (memcpy (chars , (((Scheme_Simple_Object * ) (s ) ) -> u . byte_str_val . string_val ) , len * sizeof (char ) ) ) ; 
    chars = chars XFORM_OK_PLUS len ; 
  }
  RET_VALUE_START (naya ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_append_byte_string (Scheme_Object * str1 , Scheme_Object * str2 ) {
  int len1 , len2 ; 
  char * r ; 
  Scheme_Object * naya ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(str1, 0), PUSH(str2, 1), PUSH(r, 2), PUSH(naya, 3)));
# define XfOrM159_COUNT (4)
# define SETUP_XfOrM159(x) SETUP(XfOrM159_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  r = NULLED_OUT ; 
  naya = NULLED_OUT ; 
  len1 = (((Scheme_Simple_Object * ) (str1 ) ) -> u . byte_str_val . tag_val ) ; 
  len2 = (((Scheme_Simple_Object * ) (str2 ) ) -> u . byte_str_val . tag_val ) ; 
  naya = FUNCCALL(SETUP_XfOrM159(_), scheme_alloc_byte_string (len1 + len2 , 0 ) ); 
  r = (((Scheme_Simple_Object * ) (naya ) ) -> u . byte_str_val . string_val ) ; 
  (memcpy (r , (((Scheme_Simple_Object * ) (str1 ) ) -> u . byte_str_val . string_val ) , len1 * sizeof (char ) ) ) ; 
  (memcpy (r + len1 , (((Scheme_Simple_Object * ) (str2 ) ) -> u . byte_str_val . string_val ) , len2 * sizeof (char ) ) ) ; 
  r [len1 + len2 ] = 0 ; 
  RET_VALUE_START (naya ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * byte_string_to_list (int argc , Scheme_Object * argv [] ) {
  int len , i ; 
  unsigned char * chars ; 
  Scheme_Object * pair = scheme_null , * v ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(pair, 0), PUSH(v, 1), PUSH(chars, 2)));
# define XfOrM160_COUNT (3)
# define SETUP_XfOrM160(x) SETUP(XfOrM160_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  chars = NULLED_OUT ; 
  v = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("bytes" "->list" , "byte " "string" , 0 , argc , argv ) ); 
  chars = (unsigned char * ) (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) ; 
  len = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . tag_val ) ; 
  if (len < 0xFFF ) {
#   define XfOrM168_COUNT (0+XfOrM160_COUNT)
#   define SETUP_XfOrM168(x) SETUP_XfOrM160(x)
    for (i = len ; i -- ; ) {
#     define XfOrM170_COUNT (0+XfOrM168_COUNT)
#     define SETUP_XfOrM170(x) SETUP_XfOrM168(x)
      v = FUNCCALL(SETUP_XfOrM170(_), scheme_make_integer_value (chars [i ] ) ); 
      pair = FUNCCALL(SETUP_XfOrM170(_), scheme_make_pair (v , pair ) ); 
    }
  }
  else {
#   define XfOrM161_COUNT (0+XfOrM160_COUNT)
#   define SETUP_XfOrM161(x) SETUP_XfOrM160(x)
    for (i = len ; i -- ; ) {
#     define XfOrM165_COUNT (0+XfOrM161_COUNT)
#     define SETUP_XfOrM165(x) SETUP_XfOrM161(x)
      if (! (i & 0xFFF ) ) {
#       define XfOrM166_COUNT (0+XfOrM165_COUNT)
#       define SETUP_XfOrM166(x) SETUP_XfOrM165(x)
        if ((scheme_fuel_counter ) <= 0 ) {
#         define XfOrM167_COUNT (0+XfOrM166_COUNT)
#         define SETUP_XfOrM167(x) SETUP_XfOrM166(x)
          FUNCCALL(SETUP_XfOrM167(_), scheme_out_of_fuel () ); 
        }
      }
      ; 
      v = FUNCCALL(SETUP_XfOrM165(_), scheme_make_integer_value (chars [i ] ) ); 
      pair = FUNCCALL_AGAIN(scheme_make_pair (v , pair ) ); 
    }
  }
  RET_VALUE_START (pair ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * list_to_byte_string (int argc , Scheme_Object * argv [] ) {
  int len , i ; 
  Scheme_Object * list , * str , * ch ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(list, 0), PUSH(str, 1), PUSH(argv, 2), PUSH(ch, 3)));
# define XfOrM171_COUNT (4)
# define SETUP_XfOrM171(x) SETUP(XfOrM171_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  list = NULLED_OUT ; 
  str = NULLED_OUT ; 
  ch = NULLED_OUT ; 
  list = argv [0 ] ; 
  len = FUNCCALL(SETUP_XfOrM171(_), scheme_list_length (list ) ); 
  str = FUNCCALL_AGAIN(scheme_alloc_byte_string (len , 0 ) ); 
  i = 0 ; 
  while (((Scheme_Type ) (((((long ) (list ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (list ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#   define XfOrM173_COUNT (0+XfOrM171_COUNT)
#   define SETUP_XfOrM173(x) SETUP_XfOrM171(x)
    ch = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . car ) ; 
    if (! (((((long ) (ch ) ) & 0x1 ) ) && ((((long ) (ch ) ) >> 1 ) >= 0 ) && ((((long ) (ch ) ) >> 1 ) <= 255 ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("list->" "bytes" , "list of " "exact integer in [0,255]" , 0 , argc , argv ) ); 
    (((Scheme_Simple_Object * ) (str ) ) -> u . byte_str_val . string_val ) [i ] = (char ) (((long ) (ch ) ) >> 1 ) ; 
    i ++ ; 
    list = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . cdr ) ; 
  }
  if (! ((list ) == (scheme_null ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("list->" "bytes" , "list of " "exact integer in [0,255]" , 0 , argc , argv ) ); 
  RET_VALUE_START (str ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * byte_string_copy (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
    scheme_wrong_type ("bytes" "-copy" , "byte " "string" , 0 , argc , argv ) ; 
  return scheme_make_sized_byte_string ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) , (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . tag_val ) , 1 ) ; 
}
/* this far 371 */
/* this far 372 */
/* this far 373 */
static Scheme_Object * byte_string_copy_bang (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * s1 , * s2 ; 
  long istart , ifinish ; 
  long ostart , ofinish ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(s1, 0), PUSH(s2, 1), PUSH(argv, 2)));
# define XfOrM175_COUNT (3)
# define SETUP_XfOrM175(x) SETUP(XfOrM175_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s1 = NULLED_OUT ; 
  s2 = NULLED_OUT ; 
  s1 = argv [0 ] ; 
  if (! (((Scheme_Type ) (((((long ) (s1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (s1 ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) && (! (((Scheme_Inclhash_Object * ) (s1 ) ) -> so . keyex & 0x1 ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("bytes" "-copy!" , "mutable " "byte " "string" , 0 , argc , argv ) ); 
  FUNCCALL(SETUP_XfOrM175(_), get_substring_indices ("bytes" "-copy!" , s1 , argc , argv , 1 , 5 , & ostart , & ofinish , (((Scheme_Simple_Object * ) (s1 ) ) -> u . byte_str_val . tag_val ) ) ); 
  s2 = argv [2 ] ; 
  if (! ((Scheme_Type ) (((((long ) (s2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (s2 ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("bytes" "-copy!" , "byte " "string" , 2 , argc , argv ) ); 
  FUNCCALL(SETUP_XfOrM175(_), get_substring_indices ("bytes" "-copy!" , s2 , argc , argv , 3 , 4 , & istart , & ifinish , (((Scheme_Simple_Object * ) (s2 ) ) -> u . byte_str_val . tag_val ) ) ); 
  if ((ofinish - ostart ) < (ifinish - istart ) ) {
#   define XfOrM176_COUNT (0+XfOrM175_COUNT)
#   define SETUP_XfOrM176(x) SETUP_XfOrM175(x)
    FUNCCALL(SETUP_XfOrM176(_), scheme_arg_mismatch ("bytes" "-copy!" , "not enough room in target " "byte " "string: " , argv [2 ] ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  (memmove ((((Scheme_Simple_Object * ) (s1 ) ) -> u . byte_str_val . string_val ) + ostart , (((Scheme_Simple_Object * ) (s2 ) ) -> u . byte_str_val . string_val ) + istart , (ifinish - istart ) * sizeof (char ) ) ) ; 
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * byte_string_fill (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  int len , i ; 
  char * chars , ch ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) && (! (((Scheme_Inclhash_Object * ) (argv [0 ] ) ) -> so . keyex & 0x1 ) ) ) )
    scheme_wrong_type ("bytes" "-fill!" , "mutable " "byte " "string" , 0 , argc , argv ) ; 
  if (! (((((long ) (argv [1 ] ) ) & 0x1 ) ) && ((((long ) (argv [1 ] ) ) >> 1 ) >= 0 ) && ((((long ) (argv [1 ] ) ) >> 1 ) <= 255 ) ) )
    scheme_wrong_type ("bytes" "-fill!" , "exact integer in [0,255]" , 1 , argc , argv ) ; 
  chars = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) ; 
  ch = (char ) (((long ) (argv [1 ] ) ) >> 1 ) ; 
  len = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . tag_val ) ; 
  for (i = 0 ; i < len ; i ++ ) {
    chars [i ] = ch ; 
  }
  return scheme_void ; 
}
static Scheme_Object * byte_string_to_immutable (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * s = argv [0 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(s, 0)));
# define XfOrM180_COUNT (1)
# define SETUP_XfOrM180(x) SETUP(XfOrM180_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! ((Scheme_Type ) (((((long ) (s ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (s ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("bytes" "->immutable-" "bytes" , "byte " "string" , 0 , argc , argv ) ); 
  if ((((Scheme_Type ) (((((long ) (s ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (s ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) && (! (((Scheme_Inclhash_Object * ) (s ) ) -> so . keyex & 0x1 ) ) ) ) {
    Scheme_Object * s2 ; 
    BLOCK_SETUP((PUSH(s2, 0+XfOrM180_COUNT)));
#   define XfOrM181_COUNT (1+XfOrM180_COUNT)
#   define SETUP_XfOrM181(x) SETUP(XfOrM181_COUNT)
    s2 = NULLED_OUT ; 
    s2 = FUNCCALL(SETUP_XfOrM181(_), scheme_make_sized_byte_string ((((Scheme_Simple_Object * ) (s ) ) -> u . byte_str_val . string_val ) , (((Scheme_Simple_Object * ) (s ) ) -> u . byte_str_val . tag_val ) , 1 ) ); 
    ((((Scheme_Inclhash_Object * ) (s2 ) ) -> so . keyex |= 0x1 ) ) ; 
    RET_VALUE_START (s2 ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * append_all_byte_strings_backwards (Scheme_Object * l ) {
  int i , len ; 
  Scheme_Object * * a ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(a, 0), PUSH(l, 1)));
# define XfOrM182_COUNT (2)
# define SETUP_XfOrM182(x) SETUP(XfOrM182_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a = NULLED_OUT ; 
  len = FUNCCALL(SETUP_XfOrM182(_), scheme_list_length (l ) ); 
  a = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM182(_), GC_malloc (sizeof (Scheme_Object * ) * (len ) ) )) ; 
  for (i = len ; i -- ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
    a [i ] = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(byte_string_append (len , a ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * byte_string_eq (int argc , Scheme_Object * argv [] ) {
  char * s , * prev ; 
  int i , sl , pl ; 
  int falz = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(prev, 1), PUSH(argv, 2)));
# define XfOrM185_COUNT (3)
# define SETUP_XfOrM185(x) SETUP(XfOrM185_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  prev = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("bytes=?" , "byte string" , 0 , argc , argv ) ); 
  prev = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) ; 
  pl = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . tag_val ) ; 
  for (i = 1 ; i < argc ; i ++ ) {
#   define XfOrM187_COUNT (0+XfOrM185_COUNT)
#   define SETUP_XfOrM187(x) SETUP_XfOrM185(x)
    if (! ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("bytes=?" , "byte string" , i , argc , argv ) ); 
    s = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . byte_str_val . string_val ) ; 
    sl = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . byte_str_val . tag_val ) ; 
    if (! falz )
      if (! (FUNCCALL(SETUP_XfOrM187(_), mz_strcmp ("bytes=?" , (unsigned char * ) prev , pl , (unsigned char * ) s , sl ) )== 0 ) )
      falz = 1 ; 
    prev = s ; 
    pl = sl ; 
  }
  RET_VALUE_START (falz ? scheme_false : scheme_true ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * byte_string_lt (int argc , Scheme_Object * argv [] ) {
  char * s , * prev ; 
  int i , sl , pl ; 
  int falz = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(prev, 1), PUSH(argv, 2)));
# define XfOrM188_COUNT (3)
# define SETUP_XfOrM188(x) SETUP(XfOrM188_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  prev = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("bytes<?" , "byte string" , 0 , argc , argv ) ); 
  prev = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) ; 
  pl = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . tag_val ) ; 
  for (i = 1 ; i < argc ; i ++ ) {
#   define XfOrM190_COUNT (0+XfOrM188_COUNT)
#   define SETUP_XfOrM190(x) SETUP_XfOrM188(x)
    if (! ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("bytes<?" , "byte string" , i , argc , argv ) ); 
    s = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . byte_str_val . string_val ) ; 
    sl = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . byte_str_val . tag_val ) ; 
    if (! falz )
      if (! (FUNCCALL(SETUP_XfOrM190(_), mz_strcmp ("bytes<?" , (unsigned char * ) prev , pl , (unsigned char * ) s , sl ) )< 0 ) )
      falz = 1 ; 
    prev = s ; 
    pl = sl ; 
  }
  RET_VALUE_START (falz ? scheme_false : scheme_true ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * byte_string_gt (int argc , Scheme_Object * argv [] ) {
  char * s , * prev ; 
  int i , sl , pl ; 
  int falz = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(prev, 1), PUSH(argv, 2)));
# define XfOrM191_COUNT (3)
# define SETUP_XfOrM191(x) SETUP(XfOrM191_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  prev = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("bytes>?" , "byte string" , 0 , argc , argv ) ); 
  prev = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) ; 
  pl = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . tag_val ) ; 
  for (i = 1 ; i < argc ; i ++ ) {
#   define XfOrM193_COUNT (0+XfOrM191_COUNT)
#   define SETUP_XfOrM193(x) SETUP_XfOrM191(x)
    if (! ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("bytes>?" , "byte string" , i , argc , argv ) ); 
    s = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . byte_str_val . string_val ) ; 
    sl = (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . byte_str_val . tag_val ) ; 
    if (! falz )
      if (! (FUNCCALL(SETUP_XfOrM193(_), mz_strcmp ("bytes>?" , (unsigned char * ) prev , pl , (unsigned char * ) s , sl ) )> 0 ) )
      falz = 1 ; 
    prev = s ; 
    pl = sl ; 
  }
  RET_VALUE_START (falz ? scheme_false : scheme_true ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 1154 */
static Scheme_Object * do_byte_string_to_char_string (const char * who , Scheme_Object * bstr , long istart , long ifinish , int perm , int as_locale ) {
  int i , ulen ; 
  char * chars ; 
  unsigned int * v ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(chars, 1)));
# define XfOrM194_COUNT (2)
# define SETUP_XfOrM194(x) SETUP(XfOrM194_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  chars = NULLED_OUT ; 
  v = NULLED_OUT ; 
  chars = (((Scheme_Simple_Object * ) (bstr ) ) -> u . byte_str_val . string_val ) ; 
  ulen = (utf8_decode_x ((unsigned char * ) chars , istart , ifinish , ((void * ) 0 ) , 0 , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 0 , 0 , ((void * ) 0 ) , 0 , (perm > - 1 ) ? 0xD800 : 0 ) ) ; 
  if (ulen < 0 ) {
#   define XfOrM198_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM198(x) SETUP_XfOrM194(x)
    FUNCCALL(SETUP_XfOrM198(_), scheme_arg_mismatch (who , STRING_IS_NOT_UTF_8 , bstr ) ); 
  }
  v = (unsigned int * ) FUNCCALL(SETUP_XfOrM194(_), GC_malloc_atomic ((ulen + 1 ) * sizeof (unsigned int ) ) ); 
  (utf8_decode_x ((unsigned char * ) chars , istart , ifinish , v , 0 , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 0 , 0 , ((void * ) 0 ) , 0 , (perm > - 1 ) ? 0xD800 : 0 ) ) ; 
  if (perm > - 1 ) {
    for (i = 0 ; i < ulen ; i ++ ) {
      if (v [i ] == 0xD800 )
        v [i ] = perm ; 
    }
  }
  v [ulen ] = 0 ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_char_string (v , ulen , 0 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_byte_string_to_char_string_locale (const char * who , Scheme_Object * bstr , long istart , long ifinish , int perm ) {
  char * us ; 
  long olen ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(us, 0), PUSH(bstr, 1), PUSH(who, 2)));
# define XfOrM199_COUNT (3)
# define SETUP_XfOrM199(x) SETUP(XfOrM199_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  us = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM199(_), reset_locale () ); 
  if (! 1 )
    FUNCCALL(SETUP_XfOrM199(_), init_iconv () ); 
  if (! 1 || ! locale_on || ! 1 )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(do_byte_string_to_char_string (who , bstr , istart , ifinish , perm , 1 ) )) RET_VALUE_EMPTY_END ; 
  if (istart < ifinish ) {
    int no_cvt ; 
#   define XfOrM201_COUNT (0+XfOrM199_COUNT)
#   define SETUP_XfOrM201(x) SETUP_XfOrM199(x)
    us = FUNCCALL(SETUP_XfOrM201(_), string_to_from_locale (0 , (((Scheme_Simple_Object * ) (bstr ) ) -> u . byte_str_val . string_val ) , istart , ifinish - istart , & olen , perm , & no_cvt ) ); 
    if (! us ) {
#     define XfOrM202_COUNT (0+XfOrM201_COUNT)
#     define SETUP_XfOrM202(x) SETUP_XfOrM201(x)
      if (no_cvt ) {
#       define XfOrM204_COUNT (0+XfOrM202_COUNT)
#       define SETUP_XfOrM204(x) SETUP_XfOrM202(x)
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(do_byte_string_to_char_string (who , bstr , istart , ifinish , perm , 1 ) )) RET_VALUE_EMPTY_END ; 
      }
      else {
#       define XfOrM203_COUNT (0+XfOrM202_COUNT)
#       define SETUP_XfOrM203(x) SETUP_XfOrM202(x)
        FUNCCALL(SETUP_XfOrM203(_), scheme_arg_mismatch (who , "byte string is not a valid encoding for the current locale: " , bstr ) ); 
      }
    }
    ((mzchar * ) us ) [olen ] = 0 ; 
  }
  else {
    us = "\0\0\0" ; 
    olen = 0 ; 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_char_string ((mzchar * ) us , olen , 0 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 1244 */
static Scheme_Object * do_string_to_vector (const char * who , int mode , int argc , Scheme_Object * argv [] ) {
  int permc ; 
  long istart , ifinish ; 
  PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(who, 1)));
# define XfOrM205_COUNT (2)
# define SETUP_XfOrM205(x) SETUP(XfOrM205_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type (who , "byte string" , 0 , argc , argv ) ); 
  if ((argc < 2 ) || (((argv [1 ] ) ) == (scheme_false ) ) )
    permc = - 1 ; 
  else {
#   define XfOrM209_COUNT (0+XfOrM205_COUNT)
#   define SETUP_XfOrM209(x) SETUP_XfOrM205(x)
    if (! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type (who , "character or #f" , 1 , argc , argv ) ); 
    permc = (((Scheme_Small_Object * ) (argv [1 ] ) ) -> u . char_val ) ; 
  }
  FUNCCALL(SETUP_XfOrM205(_), scheme_get_substring_indices (who , argv [0 ] , argc , argv , 2 , 3 , & istart , & ifinish ) ); 
  if (mode == 0 )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(do_byte_string_to_char_string (who , argv [0 ] , istart , ifinish , permc , 0 ) )) RET_VALUE_EMPTY_END ; 
  else if (mode == 1 )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(do_byte_string_to_char_string_locale (who , argv [0 ] , istart , ifinish , permc ) )) RET_VALUE_EMPTY_END ; 
  else {
    mzchar * us ; 
    unsigned char * s ; 
    long i , len ; 
    BLOCK_SETUP((PUSH(us, 0+XfOrM205_COUNT), PUSH(s, 1+XfOrM205_COUNT)));
#   define XfOrM206_COUNT (2+XfOrM205_COUNT)
#   define SETUP_XfOrM206(x) SETUP(XfOrM206_COUNT)
    us = NULLED_OUT ; 
    s = NULLED_OUT ; 
    len = ifinish - istart ; 
    s = (unsigned char * ) (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) ; 
    us = (mzchar * ) FUNCCALL(SETUP_XfOrM206(_), GC_malloc_atomic ((len + 1 ) * sizeof (mzchar ) ) ); 
    for (i = istart ; i < ifinish ; i ++ ) {
      us [i - istart ] = s [i ] ; 
    }
    us [len ] = 0 ; 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_char_string (us , len , 0 ) )) RET_VALUE_EMPTY_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * byte_string_to_char_string (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_string_to_vector ("bytes->string/utf-8" , 0 , argc , argv ) ; 
}
static Scheme_Object * byte_string_to_char_string_locale (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_string_to_vector ("bytes->string/locale" , 1 , argc , argv ) ; 
}
static Scheme_Object * byte_string_to_char_string_latin1 (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_string_to_vector ("bytes->string/latin-1" , 2 , argc , argv ) ; 
}
Scheme_Object * scheme_byte_string_to_char_string (Scheme_Object * o ) {
  /* No conversion */
  return do_byte_string_to_char_string ("s->s" , o , 0 , (((Scheme_Simple_Object * ) (o ) ) -> u . byte_str_val . tag_val ) , '?' , 0 ) ; 
}
Scheme_Object * scheme_byte_string_to_char_string_locale (Scheme_Object * o ) {
  /* No conversion */
  return do_byte_string_to_char_string_locale ("s->s" , o , 0 , (((Scheme_Simple_Object * ) (o ) ) -> u . byte_str_val . tag_val ) , '?' ) ; 
}
static Scheme_Object * do_char_string_to_byte_string (Scheme_Object * s , long istart , long ifinish , int as_locale ) {
  char * bs ; 
  int slen ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(bs, 0), PUSH(s, 1)));
# define XfOrM215_COUNT (2)
# define SETUP_XfOrM215(x) SETUP(XfOrM215_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  bs = NULLED_OUT ; 
  slen = FUNCCALL(SETUP_XfOrM215(_), scheme_utf8_encode ((((Scheme_Simple_Object * ) (s ) ) -> u . char_str_val . string_val ) , istart , ifinish , ((void * ) 0 ) , 0 , 0 ) ); 
  bs = (char * ) FUNCCALL(SETUP_XfOrM215(_), GC_malloc_atomic (slen + 1 ) ); 
  FUNCCALL(SETUP_XfOrM215(_), scheme_utf8_encode ((((Scheme_Simple_Object * ) (s ) ) -> u . char_str_val . string_val ) , istart , ifinish , (unsigned char * ) bs , 0 , 0 ) ); 
  bs [slen ] = 0 ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_byte_string (bs , slen , 0 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_char_string_to_byte_string_locale (const char * who , Scheme_Object * cstr , long istart , long ifinish , int perm ) {
  char * s ; 
  long olen ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(cstr, 1), PUSH(who, 2)));
# define XfOrM216_COUNT (3)
# define SETUP_XfOrM216(x) SETUP(XfOrM216_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM216(_), reset_locale () ); 
  if (! 1 )
    FUNCCALL(SETUP_XfOrM216(_), init_iconv () ); 
  if (! 1 || ! locale_on || ! 1 )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(do_char_string_to_byte_string (cstr , istart , ifinish , 1 ) )) RET_VALUE_EMPTY_END ; 
  if (istart < ifinish ) {
    int no_cvt ; 
#   define XfOrM218_COUNT (0+XfOrM216_COUNT)
#   define SETUP_XfOrM218(x) SETUP_XfOrM216(x)
    s = FUNCCALL(SETUP_XfOrM218(_), string_to_from_locale (1 , (char * ) (((Scheme_Simple_Object * ) (cstr ) ) -> u . char_str_val . string_val ) , istart , ifinish - istart , & olen , perm , & no_cvt ) ); 
    if (! s ) {
#     define XfOrM219_COUNT (0+XfOrM218_COUNT)
#     define SETUP_XfOrM219(x) SETUP_XfOrM218(x)
      if (no_cvt ) {
#       define XfOrM221_COUNT (0+XfOrM219_COUNT)
#       define SETUP_XfOrM221(x) SETUP_XfOrM219(x)
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(do_char_string_to_byte_string (cstr , istart , ifinish , 1 ) )) RET_VALUE_EMPTY_END ; 
      }
      else {
#       define XfOrM220_COUNT (0+XfOrM219_COUNT)
#       define SETUP_XfOrM220(x) SETUP_XfOrM219(x)
        FUNCCALL(SETUP_XfOrM220(_), scheme_arg_mismatch (who , "string cannot be encoded for the current locale: " , cstr ) ); 
      }
    }
    s [olen ] = 0 ; 
  }
  else {
    s = "" ; 
    olen = 0 ; 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_byte_string (s , olen , 0 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_char_string_to_byte_string (Scheme_Object * s ) {
  /* No conversion */
  return do_char_string_to_byte_string (s , 0 , (((Scheme_Simple_Object * ) (s ) ) -> u . char_str_val . tag_val ) , 0 ) ; 
}
Scheme_Object * scheme_char_string_to_byte_string_locale (Scheme_Object * s ) {
  /* No conversion */
  return do_char_string_to_byte_string_locale ("s->s" , s , 0 , (((Scheme_Simple_Object * ) (s ) ) -> u . char_str_val . tag_val ) , '?' ) ; 
}
static Scheme_Object * do_chars_to_bytes (const char * who , int mode , int argc , Scheme_Object * argv [] ) {
  long istart , ifinish ; 
  int permc ; 
  PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(who, 1)));
# define XfOrM224_COUNT (2)
# define SETUP_XfOrM224(x) SETUP(XfOrM224_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type (who , "string" , 0 , argc , argv ) ); 
  if ((argc < 2 ) || (((argv [1 ] ) ) == (scheme_false ) ) )
    permc = - 1 ; 
  else {
#   define XfOrM232_COUNT (0+XfOrM224_COUNT)
#   define SETUP_XfOrM232(x) SETUP_XfOrM224(x)
    if (! (((((long ) (argv [1 ] ) ) & 0x1 ) ) && ((((long ) (argv [1 ] ) ) >> 1 ) >= 0 ) && ((((long ) (argv [1 ] ) ) >> 1 ) <= 255 ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type (who , "byte or #f" , 1 , argc , argv ) ); 
    permc = (((long ) (argv [1 ] ) ) >> 1 ) ; 
  }
  FUNCCALL(SETUP_XfOrM224(_), scheme_get_substring_indices (who , argv [0 ] , argc , argv , 2 , 3 , & istart , & ifinish ) ); 
  if (mode == 1 )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(do_char_string_to_byte_string_locale (who , argv [0 ] , istart , ifinish , permc ) )) RET_VALUE_EMPTY_END ; 
  else if (mode == 0 )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(do_char_string_to_byte_string (argv [0 ] , istart , ifinish , 0 ) )) RET_VALUE_EMPTY_END ; 
  else {
    mzchar * us ; 
    unsigned char * s ; 
    long i , len ; 
    BLOCK_SETUP((PUSH(s, 0+XfOrM224_COUNT), PUSH(us, 1+XfOrM224_COUNT)));
#   define XfOrM225_COUNT (2+XfOrM224_COUNT)
#   define SETUP_XfOrM225(x) SETUP(XfOrM225_COUNT)
    us = NULLED_OUT ; 
    s = NULLED_OUT ; 
    len = ifinish - istart ; 
    us = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) ; 
    s = (unsigned char * ) FUNCCALL(SETUP_XfOrM225(_), GC_malloc_atomic (len + 1 ) ); 
    for (i = istart ; i < ifinish ; i ++ ) {
#     define XfOrM229_COUNT (0+XfOrM225_COUNT)
#     define SETUP_XfOrM229(x) SETUP_XfOrM225(x)
      if (us [i ] < 256 )
        s [i - istart ] = us [i ] ; 
      else if (permc >= 0 ) {
        s [i - istart ] = permc ; 
      }
      else {
#       define XfOrM230_COUNT (0+XfOrM229_COUNT)
#       define SETUP_XfOrM230(x) SETUP_XfOrM229(x)
        FUNCCALL(SETUP_XfOrM230(_), scheme_arg_mismatch (who , "string cannot be encoded in Latin-1: " , argv [0 ] ) ); 
      }
    }
    s [len ] = 0 ; 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_byte_string ((char * ) s , len , 0 ) )) RET_VALUE_EMPTY_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * char_string_to_byte_string (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_chars_to_bytes ("string->bytes/utf-8" , 0 , argc , argv ) ; 
}
static Scheme_Object * char_string_to_byte_string_locale (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_chars_to_bytes ("string->bytes/locale" , 1 , argc , argv ) ; 
}
static Scheme_Object * char_string_to_byte_string_latin1 (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_chars_to_bytes ("string->bytes/latin-1" , 2 , argc , argv ) ; 
}
static Scheme_Object * char_string_utf8_length (int argc , Scheme_Object * argv [] ) {
  long istart , ifinish , len ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM236_COUNT (1)
# define SETUP_XfOrM236(x) SETUP(XfOrM236_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("string-utf-8-length" , "string" , 0 , argc , argv ) ); 
  FUNCCALL(SETUP_XfOrM236(_), scheme_get_substring_indices ("string-utf-8-length" , argv [0 ] , argc , argv , 1 , 2 , & istart , & ifinish ) ); 
  len = FUNCCALL_EMPTY(scheme_utf8_encode ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) , istart , ifinish , ((void * ) 0 ) , 0 , 0 ) ); 
  RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (len ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * byte_string_utf8_length (int argc , Scheme_Object * argv [] ) {
  int len , perm ; 
  long istart , ifinish ; 
  char * chars ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(chars, 0)));
# define XfOrM237_COUNT (1)
# define SETUP_XfOrM237(x) SETUP(XfOrM237_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  chars = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("bytes-utf-8-length" , "string" , 0 , argc , argv ) ); 
  chars = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) ; 
  if ((argc > 1 ) && ! (((argv [1 ] ) ) == (scheme_false ) ) ) {
#   define XfOrM238_COUNT (0+XfOrM237_COUNT)
#   define SETUP_XfOrM238(x) SETUP_XfOrM237(x)
    if (! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("bytes-utf-8-length" , "character or #f" , 1 , argc , argv ) ); 
    perm = 1 ; 
  }
  else perm = 0 ; 
  FUNCCALL(SETUP_XfOrM237(_), scheme_get_substring_indices ("bytes-utf-8-length" , argv [0 ] , argc , argv , 2 , 3 , & istart , & ifinish ) ); 
  len = FUNCCALL_EMPTY(scheme_utf8_decode ((unsigned char * ) chars , istart , ifinish , ((void * ) 0 ) , 0 , - 1 , ((void * ) 0 ) , 0 , perm ) ); 
  if (len < 0 )
    RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
  else RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (len ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * byte_string_utf8_index (int argc , Scheme_Object * argv [] ) {
  long istart , ifinish , pos = - 1 , opos , ipos ; 
  int result , perm ; 
  char * chars ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(chars, 0)));
# define XfOrM239_COUNT (1)
# define SETUP_XfOrM239(x) SETUP(XfOrM239_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  chars = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("bytes-utf-8-index" , "byte string" , 0 , argc , argv ) ); 
  chars = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) ; 
  if ((((long ) (argv [1 ] ) ) & 0x1 ) ) {
    pos = (((long ) (argv [1 ] ) ) >> 1 ) ; 
  }
  else if (((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) {
    if (((& ((Scheme_Bignum * ) argv [1 ] ) -> iso ) -> so . keyex & 0x1 ) )
      pos = 0x7FFFFFFF ; 
  }
  if (pos < 0 ) {
#   define XfOrM241_COUNT (0+XfOrM239_COUNT)
#   define SETUP_XfOrM241(x) SETUP_XfOrM239(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("bytes-utf-8-index" , "non-negative exact integer" , 1 , argc , argv ) ); 
  }
  if ((argc > 2 ) && ! (((argv [2 ] ) ) == (scheme_false ) ) ) {
#   define XfOrM240_COUNT (0+XfOrM239_COUNT)
#   define SETUP_XfOrM240(x) SETUP_XfOrM239(x)
    if (! ((Scheme_Type ) (((((long ) (argv [2 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [2 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("bytes-utf-8-index" , "character or #f" , 1 , argc , argv ) ); 
    perm = 1 ; 
  }
  else perm = 0 ; 
  FUNCCALL(SETUP_XfOrM239(_), scheme_get_substring_indices ("bytes-utf-8-index" , argv [0 ] , argc , argv , 3 , 4 , & istart , & ifinish ) ); 
  result = (utf8_decode_x ((unsigned char * ) chars , istart , ifinish , ((void * ) 0 ) , 0 , pos , & ipos , & opos , 0 , 0 , ((void * ) 0 ) , 0 , perm ? 1 : 0 ) ) ; 
  if (((result < 0 ) && (result != - 3 ) ) || ((ipos == ifinish ) && (opos <= pos ) ) )
    RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
  else RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (ipos ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * byte_string_utf8_ref (int argc , Scheme_Object * argv [] ) {
  long istart , ifinish , pos = - 1 , opos , ipos ; 
  char * chars ; 
  unsigned int us [1 ] ; 
  Scheme_Object * perm ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(perm, 0), PUSH(chars, 1)));
# define XfOrM244_COUNT (2)
# define SETUP_XfOrM244(x) SETUP(XfOrM244_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  chars = NULLED_OUT ; 
  perm = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("bytes-utf-8-ref" , "byte string" , 0 , argc , argv ) ); 
  chars = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) ; 
  if ((((long ) (argv [1 ] ) ) & 0x1 ) ) {
    pos = (((long ) (argv [1 ] ) ) >> 1 ) ; 
  }
  else if (((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) {
    if (((& ((Scheme_Bignum * ) argv [1 ] ) -> iso ) -> so . keyex & 0x1 ) )
      pos = 0x7FFFFFFF ; 
  }
  if (pos < 0 ) {
#   define XfOrM247_COUNT (0+XfOrM244_COUNT)
#   define SETUP_XfOrM247(x) SETUP_XfOrM244(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("bytes-utf-8-ref" , "non-negative exact integer" , 1 , argc , argv ) ); 
  }
  if ((argc > 2 ) && ! (((argv [2 ] ) ) == (scheme_false ) ) ) {
#   define XfOrM246_COUNT (0+XfOrM244_COUNT)
#   define SETUP_XfOrM246(x) SETUP_XfOrM244(x)
    if (! ((Scheme_Type ) (((((long ) (argv [2 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [2 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("bytes-utf-8-ref" , "character or #f" , 1 , argc , argv ) ); 
    perm = argv [2 ] ; 
  }
  else perm = 0 ; 
  FUNCCALL(SETUP_XfOrM244(_), scheme_get_substring_indices ("bytes-utf-8-ref" , argv [0 ] , argc , argv , 3 , 4 , & istart , & ifinish ) ); 
  if (pos > 0 ) {
#   define XfOrM245_COUNT (0+XfOrM244_COUNT)
#   define SETUP_XfOrM245(x) SETUP_XfOrM244(x)
    (utf8_decode_x ((unsigned char * ) chars , istart , ifinish , ((void * ) 0 ) , 0 , pos , & ipos , & opos , 0 , 0 , ((void * ) 0 ) , 0 , perm ? 1 : 0 ) ) ; 
    if (opos < pos )
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    istart = ipos ; 
  }
  (utf8_decode_x ((unsigned char * ) chars , istart , ifinish , us , 0 , 1 , & ipos , & opos , 0 , 0 , ((void * ) 0 ) , 0 , perm ? 0xFFFF : 0 ) ) ; 
  if (opos < 1 )
    RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
  else if (us [0 ] == 0xFFFF )
    RET_VALUE_START (perm ) RET_VALUE_END ; 
  else RET_VALUE_START (((((mzchar ) us [0 ] ) < 256 ) ? scheme_char_constants [(unsigned char ) (us [0 ] ) ] : FUNCCALL_EMPTY(scheme_make_char (us [0 ] ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_do_format (const char * procname , Scheme_Object * port , const mzchar * format , int flen , int fpos , int offset , int argc , Scheme_Object * * argv ) {
  int i , start , end ; 
  int used = offset ; 
  int num_err = 0 , char_err = 0 , end_ok = 0 ; 
  Scheme_Object * a [2 ] ; 
  PREPARE_VAR_STACK(11);
  BLOCK_SETUP_TOP((PUSH(port, 0), PUSH(format, 1), PUSH(procname, 2), PUSHARRAY(a, 2, 3), PUSH(argv, 6)));
# define XfOrM250_COUNT (7)
# define SETUP_XfOrM250(x) SETUP(XfOrM250_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  if (! format ) {
#   define XfOrM309_COUNT (0+XfOrM250_COUNT)
#   define SETUP_XfOrM309(x) SETUP_XfOrM250(x)
    if (! ((Scheme_Type ) (((((long ) (argv [fpos ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [fpos ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) ) {
#     define XfOrM310_COUNT (0+XfOrM309_COUNT)
#     define SETUP_XfOrM310(x) SETUP_XfOrM309(x)
      FUNCCALL(SETUP_XfOrM310(_), scheme_wrong_type (procname , "format-string" , fpos , argc , argv ) ); 
      RET_NOTHING ; 
    }
    format = (((Scheme_Simple_Object * ) (argv [fpos ] ) ) -> u . char_str_val . string_val ) ; 
    flen = (((Scheme_Simple_Object * ) (argv [fpos ] ) ) -> u . char_str_val . tag_val ) ; 
  }
  else if (flen == - 1 )
    flen = strlen ((char * ) format ) ; 
  end = flen - 1 ; 
  for (i = 0 ; i < end ; i ++ ) {
#   define XfOrM302_COUNT (0+XfOrM250_COUNT)
#   define SETUP_XfOrM302(x) SETUP_XfOrM250(x)
    if (format [i ] == '~' ) {
      i ++ ; 
#     define XfOrM303_COUNT (0+XfOrM302_COUNT)
#     define SETUP_XfOrM303(x) SETUP_XfOrM302(x)
      if ((((scheme_uchar_table [(format [i ] >> 8 ) & 0x1FFF ] [format [i ] & 0xFF ] ) ) & 0x10 ) ) {
      }
      else switch (format [i ] ) {
#       define XfOrM304_COUNT (0+XfOrM303_COUNT)
#       define SETUP_XfOrM304(x) SETUP_XfOrM303(x)
        case '~' : if (i == end )
          end_ok = 1 ; 
        break ; 
        case '%' : case 'n' : case 'N' : break ; 
        case 'a' : case 'A' : case 's' : case 'S' : case 'v' : case 'V' : case 'e' : case 'E' : used ++ ; 
        break ; 
        case 'x' : case 'X' : case 'o' : case 'O' : case 'b' : case 'B' : if (! num_err && ! char_err && (used < argc ) ) {
          Scheme_Object * o = argv [used ] ; 
          BLOCK_SETUP((PUSH(o, 0+XfOrM304_COUNT)));
#         define XfOrM307_COUNT (1+XfOrM304_COUNT)
#         define SETUP_XfOrM307(x) SETUP(XfOrM307_COUNT)
          if (! ((((long ) (o ) ) & 0x1 ) || (((o ) -> type ) == scheme_bignum_type ) || (((o ) -> type ) == scheme_rational_type ) ) && (! (! (((long ) (o ) ) & 0x1 ) && ((((o ) -> type ) >= scheme_complex_izi_type ) && (((o ) -> type ) <= scheme_complex_type ) ) ) || ! ((((long ) (FUNCCALL(SETUP_XfOrM307(_), scheme_complex_real_part (o ) )) ) & 0x1 ) || (((FUNCCALL(SETUP_XfOrM307(_), scheme_complex_real_part (o ) )) -> type ) == scheme_bignum_type ) || (((FUNCCALL(SETUP_XfOrM307(_), scheme_complex_real_part (o ) )) -> type ) == scheme_rational_type ) ) ) )
            num_err = used + 1 ; 
        }
        used ++ ; 
        break ; 
        case 'c' : case 'C' : if (! num_err && ! char_err && (used < argc ) ) {
          if (! ((Scheme_Type ) (((((long ) (argv [used ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [used ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_type ) ) )
            char_err = used + 1 ; 
        }
        used ++ ; 
        break ; 
        default : {
          char buffer [64 ] ; 
#         define XfOrM305_COUNT (0+XfOrM304_COUNT)
#         define SETUP_XfOrM305(x) SETUP_XfOrM304(x)
          (sprintf (buffer , "pattern-string (tag ~%c not allowed)" , format [i ] ) ) ; 
          FUNCCALL(SETUP_XfOrM305(_), scheme_wrong_type (procname , buffer , fpos , argc , argv ) ); 
          RET_NOTHING ; 
        }
      }
    }
  }
  if ((format [end ] == '~' ) && ! end_ok ) {
#   define XfOrM294_COUNT (0+XfOrM250_COUNT)
#   define SETUP_XfOrM294(x) SETUP_XfOrM250(x)
    FUNCCALL(SETUP_XfOrM294(_), scheme_wrong_type (procname , "pattern-string (cannot end in ~)" , fpos , argc , argv ) ); 
    RET_NOTHING ; 
  }
  if (used != argc ) {
    char * args ; 
    long alen ; 
    BLOCK_SETUP((PUSH(args, 0+XfOrM250_COUNT)));
#   define XfOrM291_COUNT (1+XfOrM250_COUNT)
#   define SETUP_XfOrM291(x) SETUP(XfOrM291_COUNT)
    args = NULLED_OUT ; 
    args = FUNCCALL(SETUP_XfOrM291(_), scheme_make_args_string ("" , - 1 , argc , argv , & alen ) ); 
    if (used > argc ) {
#     define XfOrM293_COUNT (0+XfOrM291_COUNT)
#     define SETUP_XfOrM293(x) SETUP_XfOrM291(x)
      FUNCCALL(SETUP_XfOrM293(_), scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: format string requires %d arguments, given %d%t" , procname , used - offset , argc - offset , args , alen ) ); 
    }
    else {
#     define XfOrM292_COUNT (0+XfOrM291_COUNT)
#     define SETUP_XfOrM292(x) SETUP_XfOrM291(x)
      FUNCCALL(SETUP_XfOrM292(_), scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: format string requires %d arguments, given %d%t" , procname , used - offset , argc - offset , args , alen ) ); 
    }
    RET_NOTHING ; 
  }
  if (num_err || char_err ) {
    int pos = (num_err ? num_err : char_err ) - 1 ; 
    char * args , * bstr ; 
    long alen ; 
    int blen ; 
    char * type = (num_err ? "exact-number" : "character" ) ; 
    Scheme_Object * bad = argv [pos ] ; 
    BLOCK_SETUP((PUSH(args, 0+XfOrM250_COUNT), PUSH(bad, 1+XfOrM250_COUNT), PUSH(type, 2+XfOrM250_COUNT), PUSH(bstr, 3+XfOrM250_COUNT)));
#   define XfOrM290_COUNT (4+XfOrM250_COUNT)
#   define SETUP_XfOrM290(x) SETUP(XfOrM290_COUNT)
    args = NULLED_OUT ; 
    bstr = NULLED_OUT ; 
    args = FUNCCALL(SETUP_XfOrM290(_), scheme_make_args_string ("other " , pos , argc , argv , & alen ) ); 
    bstr = FUNCCALL_AGAIN(scheme_make_provided_string (bad , 1 , & blen ) ); 
    FUNCCALL_AGAIN(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: format string requires argument of type <%s>, given %t%t" , procname , type , bstr , blen , args , alen ) ); 
    RET_NOTHING ; 
  }
  for (used = offset , i = start = 0 ; i < flen ; i ++ ) {
#   define XfOrM272_COUNT (0+XfOrM250_COUNT)
#   define SETUP_XfOrM272(x) SETUP_XfOrM250(x)
    if (format [i ] == '~' ) {
#     define XfOrM273_COUNT (0+XfOrM272_COUNT)
#     define SETUP_XfOrM273(x) SETUP_XfOrM272(x)
      if (start < i ) {
#       define XfOrM289_COUNT (0+XfOrM273_COUNT)
#       define SETUP_XfOrM289(x) SETUP_XfOrM273(x)
        (void ) FUNCCALL(SETUP_XfOrM289(_), scheme_put_char_string (procname , port , format , start , i - start ) ); 
      }
      i ++ ; 
      if ((((scheme_uchar_table [(format [i ] >> 8 ) & 0x1FFF ] [format [i ] & 0xFF ] ) ) & 0x10 ) ) {
#       define XfOrM280_COUNT (0+XfOrM273_COUNT)
#       define SETUP_XfOrM280(x) SETUP_XfOrM273(x)
        do {
#         define XfOrM285_COUNT (0+XfOrM280_COUNT)
#         define SETUP_XfOrM285(x) SETUP_XfOrM280(x)
          if ((format [i ] == '\n' ) || (format [i ] == '\r' ) ) {
#           define XfOrM286_COUNT (0+XfOrM285_COUNT)
#           define SETUP_XfOrM286(x) SETUP_XfOrM285(x)
            if ((format [i ] == '\r' ) && (format [i + 1 ] == '\n' ) )
              i ++ ; 
            i ++ ; 
            while ((((format [i ] ) < 128 ) && ((* FUNCCALL(SETUP_XfOrM286(_), __ctype_b_loc () )) [(int ) ((format [i ] ) ) ] & (unsigned short int ) _ISspace ) ) && ! ((format [i ] == '\n' ) || (format [i ] == '\r' ) ) ) {
              i ++ ; 
            }
            break ; 
          }
          else i ++ ; 
        }
        while ((((scheme_uchar_table [(format [i ] >> 8 ) & 0x1FFF ] [format [i ] & 0xFF ] ) ) & 0x10 ) ) ; 
        -- i ; 
      }
      else switch (format [i ] ) {
#       define XfOrM276_COUNT (0+XfOrM273_COUNT)
#       define SETUP_XfOrM276(x) SETUP_XfOrM273(x)
        case '~' : FUNCCALL(SETUP_XfOrM276(_), scheme_write_byte_string ("~" , 1 , port ) ); 
        break ; 
        case '%' : case 'n' : case 'N' : FUNCCALL(SETUP_XfOrM276(_), scheme_write_byte_string ("\n" , 1 , port ) ); 
        break ; 
        case 'c' : case 'C' : case 'a' : case 'A' : a [0 ] = argv [used ++ ] ; 
        a [1 ] = port ; 
        FUNCCALL(SETUP_XfOrM276(_), scheme_do_eval (scheme_display_proc , 2 , a , 1 ) ); 
        break ; 
        case 's' : case 'S' : a [0 ] = argv [used ++ ] ; 
        a [1 ] = port ; 
        FUNCCALL(SETUP_XfOrM276(_), scheme_do_eval (scheme_write_proc , 2 , a , 1 ) ); 
        break ; 
        case 'v' : case 'V' : a [0 ] = argv [used ++ ] ; 
        a [1 ] = port ; 
        FUNCCALL(SETUP_XfOrM276(_), scheme_do_eval (scheme_print_proc , 2 , a , 1 ) ); 
        break ; 
        case 'e' : case 'E' : {
          int len ; 
          char * s ; 
          BLOCK_SETUP((PUSH(s, 0+XfOrM276_COUNT)));
#         define XfOrM279_COUNT (1+XfOrM276_COUNT)
#         define SETUP_XfOrM279(x) SETUP(XfOrM279_COUNT)
          s = NULLED_OUT ; 
          s = FUNCCALL(SETUP_XfOrM279(_), scheme_make_provided_string (argv [used ++ ] , 0 , & len ) ); 
          FUNCCALL_AGAIN(scheme_write_byte_string (s , len , port ) ); 
        }
        break ; 
        case 'x' : case 'X' : case 'o' : case 'O' : case 'b' : case 'B' : {
          char * s ; 
          int radix ; 
          BLOCK_SETUP((PUSH(s, 0+XfOrM276_COUNT)));
#         define XfOrM277_COUNT (1+XfOrM276_COUNT)
#         define SETUP_XfOrM277(x) SETUP(XfOrM277_COUNT)
          s = NULLED_OUT ; 
          switch (format [i ] ) {
            case 'x' : case 'X' : radix = 16 ; 
            break ; 
            case 'o' : case 'O' : radix = 8 ; 
            break ; 
            default : case 'b' : case 'B' : radix = 2 ; 
            break ; 
          }
          s = FUNCCALL(SETUP_XfOrM277(_), scheme_number_to_string (radix , argv [used ++ ] ) ); 
          FUNCCALL(SETUP_XfOrM277(_), scheme_write_byte_string (s , strlen (s ) , port ) ); 
        }
        break ; 
      }
      {
#       define XfOrM274_COUNT (0+XfOrM273_COUNT)
#       define SETUP_XfOrM274(x) SETUP_XfOrM273(x)
        if ((scheme_fuel_counter ) <= 0 ) {
#         define XfOrM275_COUNT (0+XfOrM274_COUNT)
#         define SETUP_XfOrM275(x) SETUP_XfOrM274(x)
          FUNCCALL(SETUP_XfOrM275(_), scheme_out_of_fuel () ); 
        }
      }
      ; 
      start = i + 1 ; 
    }
  }
  {
#   define XfOrM252_COUNT (0+XfOrM250_COUNT)
#   define SETUP_XfOrM252(x) SETUP_XfOrM250(x)
    if ((scheme_fuel_counter ) <= 0 ) {
#     define XfOrM253_COUNT (0+XfOrM252_COUNT)
#     define SETUP_XfOrM253(x) SETUP_XfOrM252(x)
      FUNCCALL(SETUP_XfOrM253(_), scheme_out_of_fuel () ); 
    }
  }
  ; 
  if (start < i ) {
#   define XfOrM251_COUNT (0+XfOrM250_COUNT)
#   define SETUP_XfOrM251(x) SETUP_XfOrM250(x)
    (void ) FUNCCALL(SETUP_XfOrM251(_), scheme_put_char_string (procname , port , format , start , i - start ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
char * scheme_format (mzchar * format , int flen , int argc , Scheme_Object * * argv , long * rlen ) {
  Scheme_Object * port ; 
  PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(port, 0), PUSH(rlen, 1), PUSH(argv, 2), PUSH(format, 3)));
# define XfOrM311_COUNT (4)
# define SETUP_XfOrM311(x) SETUP(XfOrM311_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  port = NULLED_OUT ; 
  port = FUNCCALL(SETUP_XfOrM311(_), scheme_make_byte_string_output_port () ); 
  FUNCCALL_AGAIN(scheme_do_format ("format" , port , format , flen , 0 , 0 , argc , argv ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_get_sized_byte_string_output (port , rlen ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_printf (mzchar * format , int flen , int argc , Scheme_Object * * argv ) {
  Scheme_Config * __funcarg133 = NULLED_OUT ; 
  Scheme_Object * __funcarg132 = NULLED_OUT ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(format, 1)));
# define XfOrM312_COUNT (2)
# define SETUP_XfOrM312(x) SETUP(XfOrM312_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  (__funcarg132 = (__funcarg133 = FUNCCALL(SETUP_XfOrM312(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg133 , MZCONFIG_OUTPUT_PORT ) )) , FUNCCALL_AGAIN(scheme_do_format ("printf" , __funcarg132 , format , flen , 0 , 0 , argc , argv ) )) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
char * scheme_format_utf8 (char * format , int flen , int argc , Scheme_Object * * argv , long * rlen ) {
  mzchar * s ; 
  long srlen ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(rlen, 0), PUSH(argv, 1), PUSH(s, 2)));
# define XfOrM313_COUNT (3)
# define SETUP_XfOrM313(x) SETUP(XfOrM313_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  if (flen == - 1 )
    flen = strlen (format ) ; 
  s = FUNCCALL(SETUP_XfOrM313(_), scheme_utf8_decode_to_buffer_len ((unsigned char * ) format , flen , ((void * ) 0 ) , 0 , & srlen ) ); 
  if (s )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_format (s , srlen , argc , argv , rlen ) )) RET_VALUE_EMPTY_END ; 
  else RET_VALUE_START ("" ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_printf_utf8 (char * format , int flen , int argc , Scheme_Object * * argv ) {
  mzchar * s ; 
  long srlen ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(s, 1)));
# define XfOrM314_COUNT (2)
# define SETUP_XfOrM314(x) SETUP(XfOrM314_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  if (flen == - 1 )
    flen = strlen (format ) ; 
  s = FUNCCALL(SETUP_XfOrM314(_), scheme_utf8_decode_to_buffer_len ((unsigned char * ) format , flen , ((void * ) 0 ) , 0 , & srlen ) ); 
  if (s )
    FUNCCALL_EMPTY(scheme_printf (s , srlen , argc , argv ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * format (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * port ; 
  char * s ; 
  long len ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(port, 0), PUSH(s, 1), PUSH(argv, 2)));
# define XfOrM315_COUNT (3)
# define SETUP_XfOrM315(x) SETUP(XfOrM315_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  port = NULLED_OUT ; 
  s = NULLED_OUT ; 
  port = FUNCCALL(SETUP_XfOrM315(_), scheme_make_byte_string_output_port () ); 
  FUNCCALL_AGAIN(scheme_do_format ("format" , port , ((void * ) 0 ) , 0 , 0 , 1 , argc , argv ) ); 
  s = FUNCCALL_AGAIN(scheme_get_sized_byte_string_output (port , & len ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_utf8_string (s , len ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * sch_printf (int argc , Scheme_Object * argv [] ) {
  Scheme_Config * __funcarg135 = NULLED_OUT ; 
  Scheme_Object * __funcarg134 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM316_COUNT (1)
# define SETUP_XfOrM316(x) SETUP(XfOrM316_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  (__funcarg134 = (__funcarg135 = FUNCCALL(SETUP_XfOrM316(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg135 , MZCONFIG_OUTPUT_PORT ) )) , FUNCCALL_AGAIN(scheme_do_format ("printf" , __funcarg134 , ((void * ) 0 ) , 0 , 0 , 1 , argc , argv ) )) ; 
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * sch_fprintf (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! scheme_is_output_port (argv [0 ] ) )
    scheme_wrong_type ("fprintf" , "output-port" , 0 , argc , argv ) ; 
  scheme_do_format ("fprintf" , argv [0 ] , ((void * ) 0 ) , 0 , 1 , 2 , argc , argv ) ; 
  return scheme_void ; 
}
static Scheme_Object * version (int argc , Scheme_Object * argv [] ) {
  char * __funcarg136 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(0);
# define XfOrM318_COUNT (0)
# define SETUP_XfOrM318(x) SETUP(XfOrM318_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! vers_str ) {
#   define XfOrM319_COUNT (0+XfOrM318_COUNT)
#   define SETUP_XfOrM319(x) SETUP_XfOrM318(x)
    FUNCCALL_EMPTY(scheme_register_static ((void * ) & vers_str , sizeof (vers_str ) ) ); 
    vers_str = (__funcarg136 = FUNCCALL_EMPTY(scheme_version () ), FUNCCALL_EMPTY(scheme_make_utf8_string (__funcarg136 ) )) ; 
    ((((Scheme_Inclhash_Object * ) (vers_str ) ) -> so . keyex |= 0x1 ) ) ; 
  }
  RET_VALUE_START (vers_str ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * banner (int argc , Scheme_Object * argv [] ) {
  char * __funcarg137 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(0);
# define XfOrM320_COUNT (0)
# define SETUP_XfOrM320(x) SETUP(XfOrM320_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! banner_str ) {
#   define XfOrM321_COUNT (0+XfOrM320_COUNT)
#   define SETUP_XfOrM321(x) SETUP_XfOrM320(x)
    FUNCCALL_EMPTY(scheme_register_static ((void * ) & banner_str , sizeof (banner_str ) ) ); 
    banner_str = (__funcarg137 = FUNCCALL_EMPTY(scheme_banner () ), FUNCCALL_EMPTY(scheme_make_utf8_string (__funcarg137 ) )) ; 
    ((((Scheme_Inclhash_Object * ) (banner_str ) ) -> so . keyex |= 0x1 ) ) ; 
  }
  RET_VALUE_START (banner_str ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
char * scheme_version (void ) {
  /* No conversion */
  return "372" "" ; 
}
char * scheme_banner (void ) {
  /* No conversion */
  if (embedding_banner )
    return embedding_banner ; 
  else return "Welcome to MzScheme" " v" "372" "" " [3m]" ", Copyright (c) 2004-2007 PLT Scheme Inc.\n" ; 
}
void scheme_set_banner (char * s ) {
  /* No conversion */
  embedding_banner = s ; 
}
int scheme_byte_string_has_null (Scheme_Object * o ) {
  /* No conversion */
  const char * s = (((Scheme_Simple_Object * ) (o ) ) -> u . byte_str_val . string_val ) ; 
  int i = (((Scheme_Simple_Object * ) (o ) ) -> u . byte_str_val . tag_val ) ; 
  while (i -- ) {
    if (! s [i ] )
      return 1 ; 
  }
  return 0 ; 
}
int scheme_any_string_has_null (Scheme_Object * o ) {
  /* No conversion */
  if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
    return scheme_byte_string_has_null (o ) ; 
  else {
    const mzchar * s = (((Scheme_Simple_Object * ) (o ) ) -> u . char_str_val . string_val ) ; 
    int i = (((Scheme_Simple_Object * ) (o ) ) -> u . char_str_val . tag_val ) ; 
    while (i -- ) {
      if (! s [i ] )
        return 1 ; 
    }
    return 0 ; 
  }
}
void scheme_init_getenv (void ) {
  /* No conversion */
  if (getenv ("PLTNOMZJIT" ) ) {
    scheme_set_startup_use_jit (0 ) ; 
  }
}
static Scheme_Object * sch_getenv (int argc , Scheme_Object * argv [] ) {
  char * s ; 
  Scheme_Object * bs ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(bs, 1), PUSH(argv, 2)));
# define XfOrM334_COUNT (3)
# define SETUP_XfOrM334(x) SETUP(XfOrM334_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  bs = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || FUNCCALL(SETUP_XfOrM334(_), scheme_any_string_has_null (argv [0 ] ) ))
    FUNCCALL_EMPTY(scheme_wrong_type ("getenv" , "string (with no nul characters)" , 0 , argc , argv ) ); 
  bs = FUNCCALL(SETUP_XfOrM334(_), scheme_char_string_to_byte_string_locale (argv [0 ] ) ); 
  s = FUNCCALL_AGAIN(getenv ((((Scheme_Simple_Object * ) (bs ) ) -> u . byte_str_val . string_val ) ) ); 
  if (s )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_locale_string (s ) )) RET_VALUE_EMPTY_END ; 
  RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * sch_putenv (int argc , Scheme_Object * argv [] ) {
  char * s , * var , * val ; 
  long varlen , vallen ; 
  Scheme_Object * bs ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(val, 0), PUSH(s, 1), PUSH(var, 2), PUSH(bs, 3), PUSH(argv, 4)));
# define XfOrM335_COUNT (5)
# define SETUP_XfOrM335(x) SETUP(XfOrM335_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  s = NULLED_OUT ; 
  var = NULLED_OUT ; 
  val = NULLED_OUT ; 
  bs = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || FUNCCALL(SETUP_XfOrM335(_), scheme_any_string_has_null (argv [0 ] ) ))
    FUNCCALL_EMPTY(scheme_wrong_type ("putenv" , "string (with no nul characters)" , 0 , argc , argv ) ); 
  if (! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || FUNCCALL(SETUP_XfOrM335(_), scheme_any_string_has_null (argv [1 ] ) ))
    FUNCCALL_EMPTY(scheme_wrong_type ("putenv" , "string (with no nul characters)" , 1 , argc , argv ) ); 
  bs = FUNCCALL(SETUP_XfOrM335(_), scheme_char_string_to_byte_string_locale (argv [0 ] ) ); 
  var = (((Scheme_Simple_Object * ) (bs ) ) -> u . byte_str_val . string_val ) ; 
  bs = FUNCCALL(SETUP_XfOrM335(_), scheme_char_string_to_byte_string_locale (argv [1 ] ) ); 
  val = (((Scheme_Simple_Object * ) (bs ) ) -> u . byte_str_val . string_val ) ; 
  varlen = strlen (var ) ; 
  vallen = strlen (val ) ; 
  s = (char * ) FUNCCALL(SETUP_XfOrM335(_), GC_malloc_atomic (varlen + vallen + 2 ) ); 
  (memcpy (s , var , varlen ) ) ; 
  (memcpy (s + varlen + 1 , val , vallen + 1 ) ) ; 
  s [varlen ] = '=' ; 
  {
    char * ss ; 
    BLOCK_SETUP((PUSH(ss, 0+XfOrM335_COUNT)));
#   define XfOrM336_COUNT (1+XfOrM335_COUNT)
#   define SETUP_XfOrM336(x) SETUP(XfOrM336_COUNT)
    ss = NULLED_OUT ; 
    ss = s ; 
    s = FUNCCALL(SETUP_XfOrM336(_), malloc (varlen + vallen + 2 ) ); 
    (memcpy (s , ss , varlen + vallen + 2 ) ) ; 
    if (putenv_str_table ) {
#     define XfOrM337_COUNT (0+XfOrM336_COUNT)
#     define SETUP_XfOrM337(x) SETUP_XfOrM336(x)
      ss = (char * ) FUNCCALL(SETUP_XfOrM337(_), scheme_hash_get (putenv_str_table , (Scheme_Object * ) var ) ); 
      if (ss )
        FUNCCALL(SETUP_XfOrM337(_), free (ss ) ); 
    }
  }
  if (! putenv_str_table )
    putenv_str_table = FUNCCALL(SETUP_XfOrM335(_), scheme_make_hash_table (SCHEME_hash_string ) ); 
  FUNCCALL(SETUP_XfOrM335(_), scheme_hash_set (putenv_str_table , (Scheme_Object * ) var , (Scheme_Object * ) s ) ); 
  RET_VALUE_START (FUNCCALL_EMPTY(putenv (s ) )? scheme_false : scheme_true ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void machine_details (char * s ) ; 
static Scheme_Object * system_type (int argc , Scheme_Object * argv [] ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM338_COUNT (1)
# define SETUP_XfOrM338(x) SETUP(XfOrM338_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (argc ) {
    Scheme_Object * sym ; 
    BLOCK_SETUP((PUSH(sym, 0+XfOrM338_COUNT)));
#   define XfOrM339_COUNT (1+XfOrM338_COUNT)
#   define SETUP_XfOrM339(x) SETUP(XfOrM339_COUNT)
    sym = NULLED_OUT ; 
    sym = FUNCCALL(SETUP_XfOrM339(_), scheme_intern_symbol ("link" ) ); 
    if (((argv [0 ] ) == (sym ) ) ) {
#     define XfOrM344_COUNT (0+XfOrM339_COUNT)
#     define SETUP_XfOrM344(x) SETUP_XfOrM339(x)
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_intern_symbol ("static" ) )) RET_VALUE_EMPTY_END ; 
    }
    sym = FUNCCALL(SETUP_XfOrM339(_), scheme_intern_symbol ("machine" ) ); 
    if (((argv [0 ] ) == (sym ) ) ) {
      char buff [1024 ] ; 
#     define XfOrM343_COUNT (0+XfOrM339_COUNT)
#     define SETUP_XfOrM343(x) SETUP_XfOrM339(x)
      FUNCCALL(SETUP_XfOrM343(_), machine_details (buff ) ); 
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_utf8_string (buff ) )) RET_VALUE_EMPTY_END ; 
    }
    sym = FUNCCALL(SETUP_XfOrM339(_), scheme_intern_symbol ("gc" ) ); 
    if (((argv [0 ] ) == (sym ) ) ) {
#     define XfOrM342_COUNT (0+XfOrM339_COUNT)
#     define SETUP_XfOrM342(x) SETUP_XfOrM339(x)
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_intern_symbol ("3m" ) )) RET_VALUE_EMPTY_END ; 
    }
    sym = FUNCCALL(SETUP_XfOrM339(_), scheme_intern_symbol ("so-suffix" ) ); 
    if (((argv [0 ] ) == (sym ) ) ) {
#     define XfOrM341_COUNT (0+XfOrM339_COUNT)
#     define SETUP_XfOrM341(x) SETUP_XfOrM339(x)
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_byte_string (".so" ) )) RET_VALUE_EMPTY_END ; 
    }
    sym = FUNCCALL(SETUP_XfOrM339(_), scheme_intern_symbol ("os" ) ); 
    if (! ((argv [0 ] ) == (sym ) ) ) {
#     define XfOrM340_COUNT (0+XfOrM339_COUNT)
#     define SETUP_XfOrM340(x) SETUP_XfOrM339(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("system-type" , "'os, 'link, 'machine, 'gc, or 'so-suffix" , 0 , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  RET_VALUE_START (sys_symbol ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * system_library_subpath (int argc , Scheme_Object * argv [] ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM345_COUNT (1)
# define SETUP_XfOrM345(x) SETUP(XfOrM345_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (argc > 0 ) {
    Scheme_Object * sym ; 
    BLOCK_SETUP((PUSH(sym, 0+XfOrM345_COUNT)));
#   define XfOrM347_COUNT (1+XfOrM345_COUNT)
#   define SETUP_XfOrM347(x) SETUP(XfOrM347_COUNT)
    sym = NULLED_OUT ; 
    if ((((argv [0 ] ) ) == (scheme_false ) ) )
      RET_VALUE_START (platform_cgc_path ) RET_VALUE_END ; 
    sym = FUNCCALL(SETUP_XfOrM347(_), scheme_intern_symbol ("cgc" ) ); 
    if (((sym ) == (argv [0 ] ) ) )
      RET_VALUE_START (platform_cgc_path ) RET_VALUE_END ; 
    sym = FUNCCALL(SETUP_XfOrM347(_), scheme_intern_symbol ("3m" ) ); 
    if (((sym ) == (argv [0 ] ) ) )
      RET_VALUE_START (platform_3m_path ) RET_VALUE_END ; 
    FUNCCALL_EMPTY(scheme_wrong_type ("system-library-subpath" , "'cgc, '3m, or #f" , 0 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  else {
    RET_VALUE_START (platform_3m_path ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
const char * scheme_system_library_subpath () {
  /* No conversion */
  return "x86_64-linux" ; 
}
int scheme_strncmp (const char * a , const char * b , int len ) {
  /* No conversion */
  while (len -- && (* a == * b ) && * a ) {
    a ++ ; 
    b ++ ; 
  }
  if (len < 0 )
    return 0 ; 
  else return * a - * b ; 
}
static Scheme_Object * ok_cmdline (int argc , Scheme_Object * * argv ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
# define XfOrM352_COUNT (0)
# define SETUP_XfOrM352(x) SETUP(XfOrM352_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
    Scheme_Object * vec = argv [0 ] , * vec2 , * str ; 
    int i , size = (((Scheme_Vector * ) (vec ) ) -> size ) ; 
    BLOCK_SETUP((PUSH(str, 0+XfOrM352_COUNT), PUSH(vec2, 1+XfOrM352_COUNT), PUSH(vec, 2+XfOrM352_COUNT)));
#   define XfOrM353_COUNT (3+XfOrM352_COUNT)
#   define SETUP_XfOrM353(x) SETUP(XfOrM353_COUNT)
    vec2 = NULLED_OUT ; 
    str = NULLED_OUT ; 
    if (! size )
      RET_VALUE_START (vec ) RET_VALUE_END ; 
    for (i = 0 ; i < size ; i ++ ) {
      if (! ((Scheme_Type ) (((((long ) ((((Scheme_Vector * ) (vec ) ) -> els ) [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Vector * ) (vec ) ) -> els ) [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    vec2 = FUNCCALL(SETUP_XfOrM353(_), scheme_make_vector (size , ((void * ) 0 ) ) ); 
    if (size )
      ((((Scheme_Inclhash_Object * ) (vec2 ) ) -> so . keyex |= 0x1 ) ) ; 
    for (i = 0 ; i < size ; i ++ ) {
#     define XfOrM356_COUNT (0+XfOrM353_COUNT)
#     define SETUP_XfOrM356(x) SETUP_XfOrM353(x)
      str = (((Scheme_Vector * ) (vec ) ) -> els ) [i ] ; 
      if (! (((Scheme_Type ) (((((long ) (str ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (str ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) && (((Scheme_Inclhash_Object * ) (str ) ) -> so . keyex & 0x1 ) ) ) {
#       define XfOrM357_COUNT (0+XfOrM356_COUNT)
#       define SETUP_XfOrM357(x) SETUP_XfOrM356(x)
        str = FUNCCALL(SETUP_XfOrM357(_), scheme_make_sized_char_string ((((Scheme_Simple_Object * ) (str ) ) -> u . char_str_val . string_val ) , (((Scheme_Simple_Object * ) (str ) ) -> u . char_str_val . tag_val ) , 0 ) ); 
        ((((Scheme_Inclhash_Object * ) (str ) ) -> so . keyex |= 0x1 ) ) ; 
      }
      (((Scheme_Vector * ) (vec2 ) ) -> els ) [i ] = str ; 
    }
    RET_VALUE_START (vec2 ) RET_VALUE_END ; 
  }
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * cmdline_args (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("current-command-line-arguments" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_CMDLINE_ARGS ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , ok_cmdline , "vector of strings" , 1 ) ; 
}
static Scheme_Object * ok_locale (int argc , Scheme_Object * * argv ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(1);
# define XfOrM361_COUNT (0)
# define SETUP_XfOrM361(x) SETUP(XfOrM361_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((((argv [0 ] ) ) == (scheme_false ) ) )
    RET_VALUE_START (argv [0 ] ) RET_VALUE_END ; 
  else if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) ) {
#   define XfOrM362_COUNT (0+XfOrM361_COUNT)
#   define SETUP_XfOrM362(x) SETUP_XfOrM361(x)
    if ((((Scheme_Inclhash_Object * ) (argv [0 ] ) ) -> so . keyex & 0x1 ) )
      RET_VALUE_START (argv [0 ] ) RET_VALUE_END ; 
    else {
      Scheme_Object * str = argv [0 ] ; 
      BLOCK_SETUP((PUSH(str, 0+XfOrM362_COUNT)));
#     define XfOrM363_COUNT (1+XfOrM362_COUNT)
#     define SETUP_XfOrM363(x) SETUP(XfOrM363_COUNT)
      str = FUNCCALL(SETUP_XfOrM363(_), scheme_make_immutable_sized_char_string ((((Scheme_Simple_Object * ) (str ) ) -> u . char_str_val . string_val ) , (((Scheme_Simple_Object * ) (str ) ) -> u . char_str_val . tag_val ) , 1 ) ); 
      RET_VALUE_START (str ) RET_VALUE_END ; 
    }
  }
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * current_locale (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * v ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(v, 0)));
# define XfOrM364_COUNT (1)
# define SETUP_XfOrM364(x) SETUP(XfOrM364_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  v = FUNCCALL(SETUP_XfOrM364(_), scheme_param_config ("current-locale" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_LOCALE ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , ok_locale , "#f or string" , 1 ) ); 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * locale_string_encoding (int argc , Scheme_Object * argv [] ) {
  char * __funcarg138 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(0);
# define XfOrM365_COUNT (0)
# define SETUP_XfOrM365(x) SETUP(XfOrM365_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL_EMPTY(reset_locale () ); 
  if (! 1 || ! locale_on )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_utf8_string ("UTF-8" ) )) RET_VALUE_EMPTY_END ; 
  RET_VALUE_START ((__funcarg138 = FUNCCALL_EMPTY(nl_langinfo (CODESET ) ), FUNCCALL_EMPTY(scheme_make_utf8_string (__funcarg138 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * system_language_country (int argc , Scheme_Object * argv [] ) {
  char * s ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(s, 0)));
# define XfOrM366_COUNT (1)
# define SETUP_XfOrM366(x) SETUP(XfOrM366_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  s = FUNCCALL(SETUP_XfOrM366(_), getenv ("LC_ALL" ) ); 
  if (! s )
    s = FUNCCALL(SETUP_XfOrM366(_), getenv ("LC_CTYPE" ) ); 
  if (! s )
    s = FUNCCALL(SETUP_XfOrM366(_), getenv ("LANG" ) ); 
  if (s ) {
    if ((s [0 ] >= 'a' ) && (s [0 ] <= 'z' ) && (s [1 ] >= 'a' ) && (s [1 ] <= 'z' ) && (s [2 ] == '_' ) && (s [3 ] >= 'A' ) && (s [3 ] <= 'Z' ) && (s [4 ] >= 'A' ) && (s [4 ] <= 'Z' ) && (! s [5 ] || s [5 ] == '.' ) ) {
    }
    else s = ((void * ) 0 ) ; 
  }
  if (! s )
    s = "en_US" ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_utf8_string (s , 5 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static char * do_convert (iconv_t cd , const char * from_e , const char * to_e , int to_from_utf8 , char * in , int id , int iilen , char * out , int od , int iolen , int grow , int add_end_shift , int extra , long * oilen , long * oolen , int * status ) {
  int dip , dop , close_it = 0 , mz_utf8 = 0 ; 
  size_t il , ol , r ; 
  GC_CAN_IGNORE char * ip , * op ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK(9);
  BLOCK_SETUP_TOP((PUSH(oolen, 0), PUSH(from_e, 1), PUSH(oilen, 2), PUSH(to_e, 3), PUSH(out, 4), PUSH(cd, 5), PUSH(status, 6), PUSH(in, 7)));
# define XfOrM369_COUNT (8)
# define SETUP_XfOrM369(x) SETUP(XfOrM369_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  * status = - 1 ; 
  if (oilen )
    * oilen = 0 ; 
  * oolen = 0 ; 
  if (cd == (iconv_t ) - 1 ) {
#   define XfOrM421_COUNT (0+XfOrM369_COUNT)
#   define SETUP_XfOrM421(x) SETUP_XfOrM369(x)
    if (! 1 )
      FUNCCALL(SETUP_XfOrM421(_), init_iconv () ); 
    if (1 ) {
#     define XfOrM423_COUNT (0+XfOrM421_COUNT)
#     define SETUP_XfOrM423(x) SETUP_XfOrM421(x)
      if (! from_e )
        from_e = "" ; 
      if (! to_e )
        to_e = "" ; 
      cd = FUNCCALL(SETUP_XfOrM423(_), iconv_open (to_e , from_e ) ); 
      close_it = 1 ; 
    }
    else if (to_from_utf8 ) {
      mz_utf8 = 1 ; 
    }
  }
  if ((cd == (iconv_t ) - 1 ) && ! mz_utf8 ) {
    if (out ) {
      while (extra -- ) {
        out [extra ] = 0 ; 
      }
    }
    RET_VALUE_START (out ) RET_VALUE_END ; 
  }
  if (! out ) {
#   define XfOrM416_COUNT (0+XfOrM369_COUNT)
#   define SETUP_XfOrM416(x) SETUP_XfOrM369(x)
    if (iolen <= 0 )
      iolen = iilen ; 
    out = (char * ) FUNCCALL(SETUP_XfOrM416(_), GC_malloc_atomic (iolen + extra ) ); 
    od = 0 ; 
  }
  il = iilen ; 
  ol = iolen ; 
  dip = 0 ; 
  dop = 0 ; 
  if (! in )
    add_end_shift = 0 ; 
  while (1 ) {
    int icerr ; 
#   define XfOrM393_COUNT (0+XfOrM369_COUNT)
#   define SETUP_XfOrM393(x) SETUP_XfOrM369(x)
    if (mz_utf8 ) {
#     define XfOrM409_COUNT (0+XfOrM393_COUNT)
#     define SETUP_XfOrM409(x) SETUP_XfOrM393(x)
      if (to_from_utf8 == 1 ) {
        int opos , uid , uilen ; 
#       define XfOrM413_COUNT (0+XfOrM409_COUNT)
#       define SETUP_XfOrM413(x) SETUP_XfOrM409(x)
        uid = (id + dip ) >> 2 ; 
        uilen = (iilen - dip ) >> 2 ; 
        opos = FUNCCALL(SETUP_XfOrM413(_), scheme_utf8_encode ((const unsigned int * ) in , uid , uilen , ((void * ) 0 ) , 0 , 0 ) ); 
        if (opos <= iolen ) {
#         define XfOrM415_COUNT (0+XfOrM413_COUNT)
#         define SETUP_XfOrM415(x) SETUP_XfOrM413(x)
          opos = FUNCCALL(SETUP_XfOrM415(_), scheme_utf8_encode ((const unsigned int * ) in , uid , uilen , (unsigned char * ) out , od + dop , 0 ) ); 
          dop += opos ; 
          dip += iilen ; 
          icerr = 0 ; 
          r = (size_t ) opos ; 
        }
        else {
          icerr = 7 ; 
          r = (size_t ) - 1 ; 
        }
      }
      else {
        long ipos , opos ; 
#       define XfOrM410_COUNT (0+XfOrM409_COUNT)
#       define SETUP_XfOrM410(x) SETUP_XfOrM409(x)
        r = (utf8_decode_x ((unsigned char * ) in , id + dip , iilen , (unsigned int * ) out , (od + dop ) >> 2 , iolen >> 2 , & ipos , & opos , 0 , 0 , ((void * ) 0 ) , 0 , 0 ) ) ; 
        opos <<= 2 ; 
        dop = (opos - od ) ; 
        dip = (ipos - id ) ; 
        if ((r == - 1 ) || (r == - 2 ) ) {
          r = (size_t ) - 1 ; 
          icerr = 84 ; 
        }
        else if (r == - 3 ) {
          icerr = 7 ; 
          r = (size_t ) - 1 ; 
        }
        else icerr = 0 ; 
      }
    }
    else {
#     define XfOrM408_COUNT (0+XfOrM393_COUNT)
#     define SETUP_XfOrM408(x) SETUP_XfOrM393(x)
      ip = in XFORM_OK_PLUS id + dip ; 
      op = out XFORM_OK_PLUS od + dop ; 
      r = FUNCCALL(SETUP_XfOrM408(_), iconv (cd , & ip , & il , & op , & ol ) ); 
      dip = ip - (in XFORM_OK_PLUS id ) ; 
      dop = op - (out XFORM_OK_PLUS od ) ; 
      ip = op = ((void * ) 0 ) ; 
      icerr = (* __errno_location () ) ; 
    }
    if (oilen )
      * oilen = dip ; 
    * oolen = dop ; 
    if (r == (size_t ) - 1 ) {
#     define XfOrM399_COUNT (0+XfOrM393_COUNT)
#     define SETUP_XfOrM399(x) SETUP_XfOrM393(x)
      if (icerr == 7 ) {
#       define XfOrM403_COUNT (0+XfOrM399_COUNT)
#       define SETUP_XfOrM403(x) SETUP_XfOrM399(x)
        if (grow ) {
          char * naya ; 
          BLOCK_SETUP((PUSH(naya, 0+XfOrM403_COUNT)));
#         define XfOrM407_COUNT (1+XfOrM403_COUNT)
#         define SETUP_XfOrM407(x) SETUP(XfOrM407_COUNT)
          naya = NULLED_OUT ; 
          naya = (char * ) FUNCCALL(SETUP_XfOrM407(_), GC_malloc_atomic ((iolen * 2 ) + extra ) ); 
          (memcpy (naya , out + od , * oolen ) ) ; 
          ol += iolen ; 
          iolen += iolen ; 
          out = naya ; 
          od = 0 ; 
        }
        else {
#         define XfOrM404_COUNT (0+XfOrM403_COUNT)
#         define SETUP_XfOrM404(x) SETUP_XfOrM403(x)
          * status = 1 ; 
          if (close_it )
            FUNCCALL(SETUP_XfOrM404(_), iconv_close (cd ) ); 
          while (extra -- ) {
            out [od + dop + extra ] = 0 ; 
          }
          RET_VALUE_START (out ) RET_VALUE_END ; 
        }
      }
      else {
#       define XfOrM400_COUNT (0+XfOrM399_COUNT)
#       define SETUP_XfOrM400(x) SETUP_XfOrM399(x)
        if (icerr == 84 )
          * status = - 2 ; 
        if (close_it )
          FUNCCALL(SETUP_XfOrM400(_), iconv_close (cd ) ); 
        while (extra -- ) {
          out [od + dop + extra ] = 0 ; 
        }
        RET_VALUE_START (out ) RET_VALUE_END ; 
      }
    }
    else {
#     define XfOrM394_COUNT (0+XfOrM393_COUNT)
#     define SETUP_XfOrM394(x) SETUP_XfOrM393(x)
      if (add_end_shift ) {
        add_end_shift = 0 ; 
        in = ((void * ) 0 ) ; 
        dip = 0 ; 
        id = 0 ; 
        il = 0 ; 
        oilen = ((void * ) 0 ) ; 
      }
      else {
#       define XfOrM395_COUNT (0+XfOrM394_COUNT)
#       define SETUP_XfOrM395(x) SETUP_XfOrM394(x)
        * status = 0 ; 
        if (close_it )
          FUNCCALL(SETUP_XfOrM395(_), iconv_close (cd ) ); 
        while (extra -- ) {
          out [od + dop + extra ] = 0 ; 
        }
        RET_VALUE_START (out ) RET_VALUE_END ; 
      }
    }
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 2632 */
/* this far 2632 */
/* this far 2632 */
/* this far 2632 */
static char * string_to_from_locale (int to_bytes , char * in , int delta , int len , long * olen , int perm , int * no_cvt ) {
  Scheme_Object * parts = scheme_null , * one ; 
  char * c ; 
  long clen , used ; 
  int status ; 
  iconv_t cd ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSH(one, 0), PUSH(olen, 1), PUSH(no_cvt, 2), PUSH(cd, 3), PUSH(parts, 4), PUSH(c, 5), PUSH(in, 6)));
# define XfOrM424_COUNT (7)
# define SETUP_XfOrM424(x) SETUP(XfOrM424_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  one = NULLED_OUT ; 
  c = NULLED_OUT ; 
  cd = NULLED_OUT ; 
  if (! 1 )
    FUNCCALL(SETUP_XfOrM424(_), init_iconv () ); 
  if (to_bytes )
    cd = FUNCCALL(SETUP_XfOrM424(_), iconv_open ("" , "UCS-4LE" ) ); 
  else cd = FUNCCALL(SETUP_XfOrM424(_), iconv_open ("UCS-4LE" , "" ) ); 
  if (cd == (iconv_t ) - 1 ) {
    * no_cvt = 1 ; 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  * no_cvt = 0 ; 
  while (len ) {
#   define XfOrM437_COUNT (0+XfOrM424_COUNT)
#   define SETUP_XfOrM437(x) SETUP_XfOrM424(x)
    c = FUNCCALL(SETUP_XfOrM437(_), do_convert (cd , ((void * ) 0 ) , ((void * ) 0 ) , 0 , (char * ) in , (to_bytes ? 4 : 1 ) * delta , (to_bytes ? 4 : 1 ) * len , ((void * ) 0 ) , 0 , (to_bytes ? 1 : 4 ) * (len + 1 ) , 1 , 1 , (to_bytes ? 1 : 4 ) , & used , & clen , & status ) ); 
    if (to_bytes )
      used >>= 2 ; 
    if ((perm < 0 ) && (used < len ) ) {
#     define XfOrM446_COUNT (0+XfOrM437_COUNT)
#     define SETUP_XfOrM446(x) SETUP_XfOrM437(x)
      FUNCCALL(SETUP_XfOrM446(_), iconv_close (cd ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    delta += used ; 
    len -= used ; 
    if (! len && ((parts ) == (scheme_null ) ) ) {
#     define XfOrM443_COUNT (0+XfOrM437_COUNT)
#     define SETUP_XfOrM443(x) SETUP_XfOrM437(x)
      if (to_bytes ) {
        * olen = clen ; 
        c [* olen ] = 0 ; 
      }
      else {
        * olen = (clen >> 2 ) ; 
        ((mzchar * ) c ) [* olen ] = 0 ; 
      }
      FUNCCALL(SETUP_XfOrM443(_), iconv_close (cd ) ); 
      RET_VALUE_START (c ) RET_VALUE_END ; 
    }
    if (to_bytes ) {
#     define XfOrM442_COUNT (0+XfOrM437_COUNT)
#     define SETUP_XfOrM442(x) SETUP_XfOrM437(x)
      one = FUNCCALL(SETUP_XfOrM442(_), scheme_make_sized_byte_string (c , clen , 0 ) ); 
    }
    else {
#     define XfOrM441_COUNT (0+XfOrM437_COUNT)
#     define SETUP_XfOrM441(x) SETUP_XfOrM437(x)
      one = FUNCCALL(SETUP_XfOrM441(_), scheme_make_sized_char_string ((mzchar * ) c , clen >> 2 , 0 ) ); 
    }
    parts = FUNCCALL(SETUP_XfOrM437(_), scheme_make_pair (one , parts ) ); 
    if (len ) {
#     define XfOrM438_COUNT (0+XfOrM437_COUNT)
#     define SETUP_XfOrM438(x) SETUP_XfOrM437(x)
      if (to_bytes ) {
        char bc [1 ] ; 
#       define XfOrM440_COUNT (0+XfOrM438_COUNT)
#       define SETUP_XfOrM440(x) SETUP_XfOrM438(x)
        bc [0 ] = perm ; 
        one = FUNCCALL(SETUP_XfOrM440(_), scheme_make_sized_byte_string (bc , 1 , 1 ) ); 
      }
      else {
        mzchar bc [1 ] ; 
#       define XfOrM439_COUNT (0+XfOrM438_COUNT)
#       define SETUP_XfOrM439(x) SETUP_XfOrM438(x)
        bc [0 ] = perm ; 
        one = FUNCCALL(SETUP_XfOrM439(_), scheme_make_sized_char_string (bc , 1 , 1 ) ); 
      }
      parts = FUNCCALL(SETUP_XfOrM438(_), scheme_make_pair (one , parts ) ); 
      delta += 1 ; 
      len -= 1 ; 
    }
  }
  FUNCCALL(SETUP_XfOrM424(_), iconv_close (cd ) ); 
  if (to_bytes ) {
#   define XfOrM426_COUNT (0+XfOrM424_COUNT)
#   define SETUP_XfOrM426(x) SETUP_XfOrM424(x)
    parts = FUNCCALL(SETUP_XfOrM426(_), append_all_byte_strings_backwards (parts ) ); 
    * olen = (((Scheme_Simple_Object * ) (parts ) ) -> u . byte_str_val . tag_val ) ; 
    RET_VALUE_START ((((Scheme_Simple_Object * ) (parts ) ) -> u . byte_str_val . string_val ) ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM425_COUNT (0+XfOrM424_COUNT)
#   define SETUP_XfOrM425(x) SETUP_XfOrM424(x)
    parts = FUNCCALL(SETUP_XfOrM425(_), append_all_strings_backwards (parts ) ); 
    * olen = (((Scheme_Simple_Object * ) (parts ) ) -> u . char_str_val . tag_val ) ; 
    RET_VALUE_START ((char * ) (((Scheme_Simple_Object * ) (parts ) ) -> u . char_str_val . string_val ) ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static char * locale_recase (int to_up , char * in , int id , int iilen , char * out , int od , int iolen , long * oolen ) {
  GC_CAN_IGNORE mbstate_t state ; 
  size_t wl , wl2 , ml , ml2 ; 
  wchar_t * wc , * ws , wcbuf [32 ] , cwc ; 
  const char * s ; 
  unsigned int j ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(out, 0), PUSH(oolen, 1), PUSH(wc, 2), PUSH(s, 3), PUSH(ws, 4), PUSH(in, 5)));
# define XfOrM448_COUNT (6)
# define SETUP_XfOrM448(x) SETUP(XfOrM448_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  wc = NULLED_OUT ; 
  ws = NULLED_OUT ; 
  s = NULLED_OUT ; 
  (memset (& state , 0 , sizeof (mbstate_t ) ) ) ; 
  s = in XFORM_OK_PLUS id ; 
  wl = FUNCCALL(SETUP_XfOrM448(_), mbsrtowcs (((void * ) 0 ) , & s , 0 , & state ) ); 
  s = ((void * ) 0 ) ; 
  if (wl < 0 )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  if (wl < 32 ) {
    wc = wcbuf ; 
  }
  else {
#   define XfOrM456_COUNT (0+XfOrM448_COUNT)
#   define SETUP_XfOrM456(x) SETUP_XfOrM448(x)
    wc = (wchar_t * ) FUNCCALL(SETUP_XfOrM456(_), GC_malloc_atomic (sizeof (wchar_t ) * (wl + 1 ) ) ); 
  }
  (memset (& state , 0 , sizeof (mbstate_t ) ) ) ; 
  s = in XFORM_OK_PLUS id ; 
  wl2 = FUNCCALL(SETUP_XfOrM448(_), mbsrtowcs (wc , & s , wl + 1 , & state ) ); 
  s = ((void * ) 0 ) ; 
  if (wl2 < 0 )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  wc [wl ] = 0 ; 
  if (to_up ) {
#   define XfOrM453_COUNT (0+XfOrM448_COUNT)
#   define SETUP_XfOrM453(x) SETUP_XfOrM448(x)
    for (j = 0 ; j < wl ; j ++ ) {
#     define XfOrM455_COUNT (0+XfOrM453_COUNT)
#     define SETUP_XfOrM455(x) SETUP_XfOrM453(x)
      cwc = FUNCCALL(SETUP_XfOrM455(_), towupper (wc [j ] ) ); 
      wc [j ] = cwc ; 
    }
  }
  else {
#   define XfOrM450_COUNT (0+XfOrM448_COUNT)
#   define SETUP_XfOrM450(x) SETUP_XfOrM448(x)
    for (j = 0 ; j < wl ; j ++ ) {
#     define XfOrM452_COUNT (0+XfOrM450_COUNT)
#     define SETUP_XfOrM452(x) SETUP_XfOrM450(x)
      cwc = FUNCCALL(SETUP_XfOrM452(_), towlower (wc [j ] ) ); 
      wc [j ] = cwc ; 
    }
  }
  (memset (& state , 0 , sizeof (mbstate_t ) ) ) ; 
  ws = wc ; 
  ml = FUNCCALL(SETUP_XfOrM448(_), wcsrtombs (((void * ) 0 ) , (const wchar_t * * ) & ws , 0 , & state ) ); 
  ws = ((void * ) 0 ) ; 
  if (ml < 0 )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  * oolen = ml ; 
  if (ml + 1 >= (unsigned int ) iolen ) {
#   define XfOrM449_COUNT (0+XfOrM448_COUNT)
#   define SETUP_XfOrM449(x) SETUP_XfOrM448(x)
    out = (char * ) FUNCCALL(SETUP_XfOrM449(_), GC_malloc_atomic (ml + 1 ) ); 
    od = 0 ; 
  }
  (memset (& state , 0 , sizeof (mbstate_t ) ) ) ; 
  ws = wc ; 
  ml2 = FUNCCALL(SETUP_XfOrM448(_), wcsrtombs (out + od , (const wchar_t * * ) & ws , ml + 1 , & state ) ); 
  ws = ((void * ) 0 ) ; 
  if (ml2 < 0 )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  out [od + ml ] = 0 ; 
  RET_VALUE_START (out ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 2857 */
/* this far 2851 */
/* this far 2857 */
/* this far 2851 */
/* this far 2857 */
/* this far 2851 */
/* this far 2857 */
/* this far 2851 */
int mz_locale_strcoll (char * s1 , int d1 , int l1 , char * s2 , int d2 , int l2 , int cvt_case ) {
  long clen1 , clen2 , used1 , used2 , origl1 , origl2 ; 
  char * c1 , * c2 , buf1 [32 ] , buf2 [32 ] ; 
  char case_buf1 [32 ] , case_buf2 [32 ] ; 
  int status , got_more ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(s1, 0), PUSH(c2, 1), PUSH(s2, 2), PUSH(c1, 3)));
# define XfOrM458_COUNT (4)
# define SETUP_XfOrM458(x) SETUP(XfOrM458_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  c1 = NULLED_OUT ; 
  c2 = NULLED_OUT ; 
  origl1 = l1 ; 
  origl2 = l2 ; 
  while (1 ) {
#   define XfOrM476_COUNT (0+XfOrM458_COUNT)
#   define SETUP_XfOrM476(x) SETUP_XfOrM458(x)
    if (! origl1 && ! origl2 )
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    if (! origl1 )
      RET_VALUE_START (- 1 ) RET_VALUE_END ; 
    if (! origl2 )
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    got_more = 0 ; 
    l1 = origl1 ; 
    l2 = origl2 ; 
    while (1 ) {
#     define XfOrM486_COUNT (0+XfOrM476_COUNT)
#     define SETUP_XfOrM486(x) SETUP_XfOrM476(x)
      c1 = FUNCCALL(SETUP_XfOrM486(_), do_convert ((iconv_t ) - 1 , "UCS-4LE" , ((void * ) 0 ) , 1 , s1 , d1 * 4 , 4 * l1 , buf1 , 0 , 32 - 1 , 1 , 0 , 1 , & used1 , & clen1 , & status ) ); 
      c2 = FUNCCALL(SETUP_XfOrM486(_), do_convert ((iconv_t ) - 1 , "UCS-4LE" , ((void * ) 0 ) , 1 , s2 , d2 * 4 , 4 * l2 , buf2 , 0 , 32 - 1 , 1 , 0 , 1 , & used2 , & clen2 , & status ) ); 
      if ((used1 < 4 * l1 ) || (used2 < 4 * l2 ) ) {
        if (got_more ) {
          clen1 = clen2 = 0 ; 
          break ; 
        }
        else if (used1 == used2 ) {
          break ; 
        }
        else {
          if (used2 < used1 ) {
            used1 = used2 ; 
            got_more = 1 ; 
          }
          else got_more = 2 ; 
          l2 = (used1 >> 2 ) ; 
          l1 = (used1 >> 2 ) ; 
          if (! l1 ) {
            clen1 = clen2 = 0 ; 
            c1 = c2 = "" ; 
            used1 = used2 = 0 ; 
            break ; 
          }
        }
      }
      else break ; 
    }
    if (cvt_case ) {
#     define XfOrM478_COUNT (0+XfOrM476_COUNT)
#     define SETUP_XfOrM478(x) SETUP_XfOrM476(x)
      if (clen1 )
        c1 = FUNCCALL(SETUP_XfOrM478(_), locale_recase (0 , c1 , 0 , clen1 , case_buf1 , 0 , 32 - 1 , & clen1 ) ); 
      else c1 = ((void * ) 0 ) ; 
      if (clen2 )
        c2 = FUNCCALL(SETUP_XfOrM478(_), locale_recase (0 , c2 , 0 , clen2 , case_buf2 , 0 , 32 - 1 , & clen2 ) ); 
      else c2 = ((void * ) 0 ) ; 
      if (! c1 )
        c1 = "" ; 
      if (! c2 )
        c2 = "" ; 
    }
    status = (strcoll (c1 , c2 ) ) ; 
    if (status )
      RET_VALUE_START (status ) RET_VALUE_END ; 
    origl1 -= (used1 >> 2 ) ; 
    origl2 -= (used2 >> 2 ) ; 
    d1 += (used1 >> 2 ) ; 
    d2 += (used2 >> 2 ) ; 
    if (! origl1 && ! origl2 )
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    if (got_more )
      RET_VALUE_START (((got_more == 2 ) ? 1 : - 1 ) ) RET_VALUE_END ; 
    if (! origl1 )
      RET_VALUE_START (- 1 ) RET_VALUE_END ; 
    if (((unsigned int * ) s1 ) [d1 ] > ((unsigned int * ) s2 ) [d2 ] )
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    else if (((unsigned int * ) s1 ) [d1 ] < ((unsigned int * ) s2 ) [d2 ] )
      RET_VALUE_START (- 1 ) RET_VALUE_END ; 
    else {
      origl1 -= 1 ; 
      origl2 -= 1 ; 
      d1 += 1 ; 
      d2 += 1 ; 
    }
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
typedef int (* strcoll_proc ) (char * s1 , int d1 , int l1 , char * s2 , int d2 , int l2 , int cvt_case ) ; 
int do_locale_comp (const char * who , const mzchar * us1 , long ul1 , const mzchar * us2 , long ul2 , int cvt_case ) {
  int xl1 ; 
  int v , endres , utf16 = 0 ; 
  GC_CAN_IGNORE strcoll_proc mz_strcoll = mz_locale_strcoll ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(us1, 0), PUSH(us2, 1)));
# define XfOrM493_COUNT (2)
# define SETUP_XfOrM493(x) SETUP(XfOrM493_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (utf16 ) {
#   define XfOrM506_COUNT (0+XfOrM493_COUNT)
#   define SETUP_XfOrM506(x) SETUP_XfOrM493(x)
    us1 = (mzchar * ) FUNCCALL(SETUP_XfOrM506(_), scheme_ucs4_to_utf16 (us1 , 0 , ul1 , ((void * ) 0 ) , 0 , & ul1 , 1 ) ); 
    us2 = (mzchar * ) FUNCCALL(SETUP_XfOrM506(_), scheme_ucs4_to_utf16 (us2 , 0 , ul2 , ((void * ) 0 ) , 0 , & ul2 , 1 ) ); 
    ((short * ) us1 ) [ul1 ] = 0 ; 
    ((short * ) us2 ) [ul2 ] = 0 ; 
  }
  if (ul1 > ul2 ) {
    ul1 = ul2 ; 
    endres = 1 ; 
  }
  else {
    if (ul2 > ul1 )
      endres = - 1 ; 
    else endres = 0 ; 
  }
  xl1 = 0 ; 
  while (ul1 -- ) {
#   define XfOrM499_COUNT (0+XfOrM493_COUNT)
#   define SETUP_XfOrM499(x) SETUP_XfOrM493(x)
    if ((utf16 && (! (((short * ) us1 ) [ul1 ] ) || ! (((short * ) us2 ) [ul1 ] ) ) ) || (! utf16 && (! (us1 [ul1 ] ) || ! (us2 [ul1 ] ) ) ) ) {
#     define XfOrM501_COUNT (0+XfOrM499_COUNT)
#     define SETUP_XfOrM501(x) SETUP_XfOrM499(x)
      if (utf16 ) {
        if (((short * ) us1 ) [ul1 ] )
          endres = 1 ; 
        else if (((short * ) us2 ) [ul1 ] )
          endres = - 1 ; 
      }
      else {
        if (us1 [ul1 ] )
          endres = 1 ; 
        else if (us2 [ul1 ] )
          endres = - 1 ; 
      }
      if (xl1 )
        v = FUNCCALL(SETUP_XfOrM501(_), mz_strcoll ((char * ) us1 , ul1 + 1 , xl1 , (char * ) us2 , ul1 + 1 , xl1 , cvt_case ) ); 
      else v = 0 ; 
      if (v )
        endres = v ; 
      xl1 = 0 ; 
    }
    else {
      xl1 ++ ; 
    }
  }
  v = FUNCCALL_EMPTY(mz_strcoll ((char * ) us1 , 0 , xl1 , (char * ) us2 , 0 , xl1 , cvt_case ) ); 
  if (v )
    endres = v ; 
  RET_VALUE_START (endres ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 3095 */
/* this far 3078 */
/* this far 3095 */
/* this far 3078 */
mzchar * do_locale_recase (int to_up , mzchar * in , int delta , int len , long * olen ) {
  Scheme_Object * parts = scheme_null ; 
  char * c , buf [32 ] , case_buf [32 ] ; 
  long clen , used ; 
  int status ; 
  Scheme_Object * __funcarg142 = NULLED_OUT ; 
  Scheme_Object * __funcarg141 = NULLED_OUT ; 
  DECL_RET_SAVE (mzchar * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(parts, 0), PUSH(c, 1), PUSH(olen, 2), PUSH(in, 3)));
# define XfOrM507_COUNT (4)
# define SETUP_XfOrM507(x) SETUP(XfOrM507_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  c = NULLED_OUT ; 
  while (len ) {
#   define XfOrM511_COUNT (0+XfOrM507_COUNT)
#   define SETUP_XfOrM511(x) SETUP_XfOrM507(x)
    c = FUNCCALL(SETUP_XfOrM511(_), do_convert ((iconv_t ) - 1 , "UCS-4LE" , ((void * ) 0 ) , 1 , (char * ) in , 4 * delta , 4 * len , buf , 0 , 32 - 1 , 1 , 0 , 1 , & used , & clen , & status ) ); 
    used >>= 2 ; 
    delta += used ; 
    len -= used ; 
    c = FUNCCALL(SETUP_XfOrM511(_), locale_recase (to_up , c , 0 , clen , case_buf , 0 , 32 - 1 , & clen ) ); 
    if (! c )
      clen = 0 ; 
    c = FUNCCALL(SETUP_XfOrM511(_), do_convert ((iconv_t ) - 1 , ((void * ) 0 ) , "UCS-4LE" , 2 , c , 0 , clen , ((void * ) 0 ) , 0 , 0 , 1 , 0 , sizeof (mzchar ) , & used , & clen , & status ) ); 
    if (! len && ((parts ) == (scheme_null ) ) ) {
      * olen = (clen >> 2 ) ; 
      ((mzchar * ) c ) [* olen ] = 0 ; 
      RET_VALUE_START ((mzchar * ) c ) RET_VALUE_END ; 
    }
    parts = (__funcarg142 = FUNCCALL(SETUP_XfOrM511(_), scheme_make_sized_char_string ((mzchar * ) c , clen >> 2 , 0 ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg142 , parts ) )) ; 
    if (len ) {
#     define XfOrM512_COUNT (0+XfOrM511_COUNT)
#     define SETUP_XfOrM512(x) SETUP_XfOrM511(x)
      parts = (__funcarg141 = FUNCCALL(SETUP_XfOrM512(_), scheme_make_sized_offset_char_string (in , delta , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg141 , parts ) )) ; 
      delta += 1 ; 
      len -= 1 ; 
    }
  }
  parts = FUNCCALL(SETUP_XfOrM507(_), append_all_strings_backwards (parts ) ); 
  * olen = (((Scheme_Simple_Object * ) (parts ) ) -> u . char_str_val . tag_val ) ; 
  RET_VALUE_START ((((Scheme_Simple_Object * ) (parts ) ) -> u . char_str_val . string_val ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
typedef mzchar * (* recase_proc ) (int to_up , mzchar * in , int delta , int len , long * olen ) ; 
static Scheme_Object * mz_recase (const char * who , int to_up , mzchar * us , long ulen ) {
  long ulen1 ; 
  int utf16 = 0 , i , delta = 0 ; 
  mzchar * us1 ; 
  recase_proc mz_do_recase = do_locale_recase ; 
  Scheme_Object * s , * parts = scheme_null ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(parts, 0), PUSH(us1, 1), PUSH(s, 2), PUSH(us, 3)));
# define XfOrM514_COUNT (4)
# define SETUP_XfOrM514(x) SETUP(XfOrM514_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  us1 = NULLED_OUT ; 
  s = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM514(_), reset_locale () ); 
  if (utf16 ) {
#   define XfOrM527_COUNT (0+XfOrM514_COUNT)
#   define SETUP_XfOrM527(x) SETUP_XfOrM514(x)
    us = (mzchar * ) FUNCCALL(SETUP_XfOrM527(_), scheme_ucs4_to_utf16 (us , 0 , ulen , ((void * ) 0 ) , 0 , & ulen , 1 ) ); 
    ((short * ) us ) [ulen ] = 0 ; 
  }
  i = 0 ; 
  while (1 ) {
#   define XfOrM521_COUNT (0+XfOrM514_COUNT)
#   define SETUP_XfOrM521(x) SETUP_XfOrM514(x)
    for (; i < ulen ; i ++ ) {
      if (utf16 ) {
        if (! ((short * ) us ) [i ] )
          break ; 
      }
      else if (! us [i ] )
        break ; 
    }
    us1 = FUNCCALL(SETUP_XfOrM521(_), mz_do_recase (to_up , us , delta , i - delta , & ulen1 ) ); 
    if (utf16 ) {
#     define XfOrM522_COUNT (0+XfOrM521_COUNT)
#     define SETUP_XfOrM522(x) SETUP_XfOrM521(x)
      us1 = FUNCCALL(SETUP_XfOrM522(_), scheme_utf16_to_ucs4 ((unsigned short * ) us1 , 0 , ulen1 , ((void * ) 0 ) , 0 , & ulen1 , 1 ) ); 
      us1 [ulen1 ] = 0 ; 
    }
    s = FUNCCALL(SETUP_XfOrM521(_), scheme_make_sized_char_string ((mzchar * ) us1 , ulen1 , 0 ) ); 
    if (((parts ) == (scheme_null ) ) && (i == ulen ) )
      RET_VALUE_START (s ) RET_VALUE_END ; 
    parts = FUNCCALL(SETUP_XfOrM521(_), scheme_make_pair (s , parts ) ); 
    if (i == ulen )
      break ; 
    s = FUNCCALL(SETUP_XfOrM521(_), scheme_make_sized_char_string ((mzchar * ) "\0\0\0\0" , 1 , 0 ) ); 
    parts = FUNCCALL_AGAIN(scheme_make_pair (s , parts ) ); 
    i ++ ; 
    delta = i ; 
    if (i == ulen )
      break ; 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(append_all_strings_backwards (parts ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * unicode_recase (const char * who , int to_up , int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  long len ; 
  mzchar * chars ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    scheme_wrong_type (who , "string" , 0 , argc , argv ) ; 
  chars = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) ; 
  len = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) ; 
  return mz_recase (who , to_up , chars , len ) ; 
}
static Scheme_Object * string_locale_upcase (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return unicode_recase ("string-locale-upcase" , 1 , argc , argv ) ; 
}
static Scheme_Object * string_locale_downcase (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return unicode_recase ("string-locale-downcase" , 0 , argc , argv ) ; 
}
static void reset_locale (void ) {
  Scheme_Object * v ; 
  const mzchar * name ; 
  Scheme_Config * __funcarg144 = NULLED_OUT ; 
  int __funcarg143 ; 
  PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(name, 1)));
# define XfOrM531_COUNT (2)
# define SETUP_XfOrM531(x) SETUP(XfOrM531_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  v = NULLED_OUT ; 
  name = NULLED_OUT ; 
  v = (__funcarg144 = FUNCCALL(SETUP_XfOrM531(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg144 , MZCONFIG_LOCALE ) )) ; 
  locale_on = (! (((v ) ) == (scheme_false ) ) ) ; 
  if (locale_on ) {
#   define XfOrM532_COUNT (0+XfOrM531_COUNT)
#   define SETUP_XfOrM532(x) SETUP_XfOrM531(x)
    name = (((Scheme_Simple_Object * ) (v ) ) -> u . char_str_val . string_val ) ; 
    if ((current_locale_name != name ) && (__funcarg143 = FUNCCALL(SETUP_XfOrM532(_), scheme_char_strlen (current_locale_name ) ), FUNCCALL_AGAIN(mz_char_strcmp ("result-locale" , current_locale_name , __funcarg143 , name , (((Scheme_Simple_Object * ) (v ) ) -> u . char_str_val . tag_val ) , 0 , 1 ) )) ) {
      char * n , buf [32 ] ; 
      BLOCK_SETUP((PUSH(n, 0+XfOrM532_COUNT)));
#     define XfOrM533_COUNT (1+XfOrM532_COUNT)
#     define SETUP_XfOrM533(x) SETUP(XfOrM533_COUNT)
      n = NULLED_OUT ; 
      n = FUNCCALL(SETUP_XfOrM533(_), scheme_utf8_encode_to_buffer (name , (((Scheme_Simple_Object * ) (v ) ) -> u . char_str_val . tag_val ) , buf , 32 ) ); 
      if (! FUNCCALL(SETUP_XfOrM533(_), setlocale (__LC_CTYPE , n ) ))
        FUNCCALL(SETUP_XfOrM533(_), setlocale (__LC_CTYPE , "C" ) ); 
      if (! FUNCCALL(SETUP_XfOrM533(_), setlocale (__LC_COLLATE , n ) ))
        FUNCCALL(SETUP_XfOrM533(_), setlocale (__LC_COLLATE , "C" ) ); 
    }
    current_locale_name = name ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int find_special_casing (int ch ) {
  /* No conversion */
  int i , lo , hi , j ; 
  i = 104 >> 1 ; 
  lo = i ; 
  hi = 104 - i - 1 ; 
  while (1 ) {
    if (uchar_special_casings [i * 10 ] == ch )
      return i * 10 ; 
    if (uchar_special_casings [i * 10 ] > ch ) {
      j = i - lo ; 
      i = j + (lo >> 1 ) ; 
      hi = lo - (i - j ) - 1 ; 
      lo = i - j ; 
    }
    else {
      j = i + 1 ; 
      i = j + (hi >> 1 ) ; 
      lo = i - j ; 
      hi = hi - (i - j ) - 1 ; 
    }
  }
}
static int is_final_sigma (int mode , mzchar * s , int d , int i , int len ) {
  /* No conversion */
  int j ; 
  if (mode == 3 )
    return 1 ; 
  for (j = i - 1 ; j >= d ; j -- ) {
    if (! (((scheme_uchar_table [(s [j ] >> 8 ) & 0x1FFF ] [s [j ] & 0xFF ] ) ) & 0x1000 ) ) {
      if ((((scheme_uchar_table [(s [j ] >> 8 ) & 0x1FFF ] [s [j ] & 0xFF ] ) ) & 0x700 ) )
        break ; 
      else return 0 ; 
    }
  }
  if (j < d )
    return 0 ; 
  for (j = i + 1 ; j < d + len ; j ++ ) {
    if (! (((scheme_uchar_table [(s [j ] >> 8 ) & 0x1FFF ] [s [j ] & 0xFF ] ) ) & 0x1000 ) ) {
      return ! (((scheme_uchar_table [(s [j ] >> 8 ) & 0x1FFF ] [s [j ] & 0xFF ] ) ) & 0x700 ) ; 
    }
  }
  return 1 ; 
}
mzchar * scheme_string_recase (mzchar * s , int d , int len , int mode , int inplace , int * _len ) {
  mzchar * t ; 
  int i , extra = 0 , pos , special = 0 , td , prev_was_cased = 0 , xmode = mode ; 
  DECL_RET_SAVE (mzchar * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(t, 0), PUSH(s, 1), PUSH(_len, 2)));
# define XfOrM550_COUNT (3)
# define SETUP_XfOrM550(x) SETUP(XfOrM550_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  t = NULLED_OUT ; 
  for (i = 0 ; i < len ; i ++ ) {
#   define XfOrM593_COUNT (0+XfOrM550_COUNT)
#   define SETUP_XfOrM593(x) SETUP_XfOrM550(x)
    if ((((scheme_uchar_table [(s [d + i ] >> 8 ) & 0x1FFF ] [s [d + i ] & 0xFF ] ) ) & 0x2000 ) ) {
#     define XfOrM595_COUNT (0+XfOrM593_COUNT)
#     define SETUP_XfOrM595(x) SETUP_XfOrM593(x)
      pos = FUNCCALL(SETUP_XfOrM595(_), find_special_casing (s [d + i ] ) ); 
      if (! uchar_special_casings [pos + 9 ] || FUNCCALL(SETUP_XfOrM595(_), is_final_sigma (xmode , s , d , i , len ) )) {
        special = 1 ; 
        extra += (uchar_special_casings [pos + 1 + (xmode << 1 ) ] - 1 ) ; 
      }
    }
    if (mode == 2 ) {
      if (! (((scheme_uchar_table [(s [d + i ] >> 8 ) & 0x1FFF ] [s [d + i ] & 0xFF ] ) ) & 0x1000 ) )
        prev_was_cased = (((scheme_uchar_table [(s [d + i ] >> 8 ) & 0x1FFF ] [s [d + i ] & 0xFF ] ) ) & 0x700 ) ; 
      xmode = (prev_was_cased ? 0 : 2 ) ; 
    }
  }
  if (_len )
    * _len = len + extra ; 
  if (! extra && inplace ) {
    t = s ; 
    td = d ; 
  }
  else {
#   define XfOrM587_COUNT (0+XfOrM550_COUNT)
#   define SETUP_XfOrM587(x) SETUP_XfOrM550(x)
    t = FUNCCALL(SETUP_XfOrM587(_), GC_malloc_atomic (sizeof (mzchar ) * (len + extra + 1 ) ) ); 
    td = 0 ; 
  }
  if (! special ) {
    if (mode == 0 ) {
      for (i = 0 ; i < len ; i ++ ) {
        t [i + td ] = (s [i + d ] + scheme_uchar_downs [(scheme_uchar_cases_table [(s [i + d ] >> 8 ) & 0x1FFF ] [s [i + d ] & 0xFF ] ) ] ) ; 
      }
    }
    else if (mode == 1 ) {
      for (i = 0 ; i < len ; i ++ ) {
        t [i + td ] = (s [i + d ] + scheme_uchar_ups [(scheme_uchar_cases_table [(s [i + d ] >> 8 ) & 0x1FFF ] [s [i + d ] & 0xFF ] ) ] ) ; 
      }
    }
    else if (mode == 2 ) {
      prev_was_cased = 0 ; 
      for (i = 0 ; i < len ; i ++ ) {
        if (! prev_was_cased )
          t [i + td ] = (s [i + d ] + scheme_uchar_titles [(scheme_uchar_cases_table [(s [i + d ] >> 8 ) & 0x1FFF ] [s [i + d ] & 0xFF ] ) ] ) ; 
        else t [i + td ] = (s [i + d ] + scheme_uchar_downs [(scheme_uchar_cases_table [(s [i + d ] >> 8 ) & 0x1FFF ] [s [i + d ] & 0xFF ] ) ] ) ; 
        if (! (((scheme_uchar_table [(s [i + d ] >> 8 ) & 0x1FFF ] [s [i + d ] & 0xFF ] ) ) & 0x1000 ) )
          prev_was_cased = (((scheme_uchar_table [(s [i + d ] >> 8 ) & 0x1FFF ] [s [i + d ] & 0xFF ] ) ) & 0x700 ) ; 
      }
    }
    else {
      for (i = 0 ; i < len ; i ++ ) {
        t [i + td ] = (s [i + d ] + scheme_uchar_folds [(scheme_uchar_cases_table [(s [i + d ] >> 8 ) & 0x1FFF ] [s [i + d ] & 0xFF ] ) ] ) ; 
      }
    }
  }
  else {
    int j = 0 , c ; 
#   define XfOrM551_COUNT (0+XfOrM550_COUNT)
#   define SETUP_XfOrM551(x) SETUP_XfOrM550(x)
    prev_was_cased = 0 ; 
    for (i = 0 ; i < len ; i ++ ) {
#     define XfOrM563_COUNT (0+XfOrM551_COUNT)
#     define SETUP_XfOrM563(x) SETUP_XfOrM551(x)
      if (mode == 0 ) {
        t [j + td ] = (s [i + d ] + scheme_uchar_downs [(scheme_uchar_cases_table [(s [i + d ] >> 8 ) & 0x1FFF ] [s [i + d ] & 0xFF ] ) ] ) ; 
      }
      else if (mode == 1 ) {
        t [j + td ] = (s [i + d ] + scheme_uchar_ups [(scheme_uchar_cases_table [(s [i + d ] >> 8 ) & 0x1FFF ] [s [i + d ] & 0xFF ] ) ] ) ; 
      }
      else if (mode == 2 ) {
        if (! prev_was_cased ) {
          xmode = 2 ; 
          t [j + td ] = (s [i + d ] + scheme_uchar_titles [(scheme_uchar_cases_table [(s [i + d ] >> 8 ) & 0x1FFF ] [s [i + d ] & 0xFF ] ) ] ) ; 
        }
        else {
          xmode = 0 ; 
          t [j + td ] = (s [i + d ] + scheme_uchar_downs [(scheme_uchar_cases_table [(s [i + d ] >> 8 ) & 0x1FFF ] [s [i + d ] & 0xFF ] ) ] ) ; 
        }
        if (! (((scheme_uchar_table [(s [i + d ] >> 8 ) & 0x1FFF ] [s [i + d ] & 0xFF ] ) ) & 0x1000 ) )
          prev_was_cased = (((scheme_uchar_table [(s [i + d ] >> 8 ) & 0x1FFF ] [s [i + d ] & 0xFF ] ) ) & 0x700 ) ; 
      }
      else {
        t [j + td ] = (s [i + d ] + scheme_uchar_folds [(scheme_uchar_cases_table [(s [i + d ] >> 8 ) & 0x1FFF ] [s [i + d ] & 0xFF ] ) ] ) ; 
      }
      if ((((scheme_uchar_table [(s [i + d ] >> 8 ) & 0x1FFF ] [s [i + d ] & 0xFF ] ) ) & 0x2000 ) ) {
#       define XfOrM564_COUNT (0+XfOrM563_COUNT)
#       define SETUP_XfOrM564(x) SETUP_XfOrM563(x)
        pos = FUNCCALL(SETUP_XfOrM564(_), find_special_casing (s [i + d ] ) ); 
        if (! uchar_special_casings [pos + 9 ] || FUNCCALL(SETUP_XfOrM564(_), is_final_sigma (xmode , s , d , i , len ) )) {
          c = uchar_special_casings [pos + 1 + (xmode << 1 ) ] ; 
          pos = uchar_special_casings [pos + 2 + (xmode << 1 ) ] ; 
          while (c -- ) {
            t [(j ++ ) + td ] = uchar_special_casing_data [pos ++ ] ; 
          }
        }
        else j ++ ; 
      }
      else j ++ ; 
    }
  }
  t [len + extra + td ] = 0 ; 
  RET_VALUE_START (t ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * string_recase (const char * name , int argc , Scheme_Object * argv [] , int mode ) {
  mzchar * s ; 
  int len ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(s, 0)));
# define XfOrM597_COUNT (1)
# define SETUP_XfOrM597(x) SETUP(XfOrM597_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type (name , "string" , 0 , argc , argv ) ); 
  s = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) ; 
  len = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) ; 
  s = FUNCCALL(SETUP_XfOrM597(_), scheme_string_recase (s , 0 , len , mode , 0 , & len ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_char_string (s , len , 0 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * string_upcase (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return string_recase ("string-upcase" , argc , argv , 1 ) ; 
}
static Scheme_Object * string_downcase (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return string_recase ("string-downcase" , argc , argv , 0 ) ; 
}
static Scheme_Object * string_titlecase (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return string_recase ("string-titlecase" , argc , argv , 2 ) ; 
}
static Scheme_Object * string_foldcase (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return string_recase ("string-foldcase" , argc , argv , 3 ) ; 
}
static mzchar get_composition (mzchar a , mzchar b ) {
  /* No conversion */
  unsigned long key = (a << 16 ) | b ; 
  int pos = (917 >> 1 ) , new_pos ; 
  int below_len = pos ; 
  int above_len = (917 - pos - 1 ) ; 
  if (a > 0xFFFF )
    return 0 ; 
  while (key != utable_compose_pairs [pos ] ) {
    if (key > utable_compose_pairs [pos ] ) {
      if (! above_len )
        return 0 ; 
      new_pos = pos + (above_len >> 1 ) + 1 ; 
      below_len = (new_pos - pos - 1 ) ; 
      above_len = (above_len - below_len - 1 ) ; 
      pos = new_pos ; 
    }
    else if (key < utable_compose_pairs [pos ] ) {
      if (! below_len )
        return 0 ; 
      new_pos = pos - ((below_len >> 1 ) + 1 ) ; 
      above_len = (pos - new_pos - 1 ) ; 
      below_len = (below_len - above_len - 1 ) ; 
      pos = new_pos ; 
    }
  }
  return utable_compose_result [pos ] ; 
}
mzchar get_canon_decomposition (mzchar key , mzchar * b ) {
  /* No conversion */
  int pos = (2032 >> 1 ) , new_pos ; 
  int below_len = pos ; 
  int above_len = (2032 - pos - 1 ) ; 
  while (key != utable_decomp_keys [pos ] ) {
    if (key > utable_decomp_keys [pos ] ) {
      if (! above_len )
        return 0 ; 
      new_pos = pos + (above_len >> 1 ) + 1 ; 
      below_len = (new_pos - pos - 1 ) ; 
      above_len = (above_len - below_len - 1 ) ; 
      pos = new_pos ; 
    }
    else if (key < utable_decomp_keys [pos ] ) {
      if (! below_len )
        return 0 ; 
      new_pos = pos - ((below_len >> 1 ) + 1 ) ; 
      above_len = (pos - new_pos - 1 ) ; 
      below_len = (below_len - above_len - 1 ) ; 
      pos = new_pos ; 
    }
  }
  pos = utable_decomp_indices [pos ] ; 
  if (pos < 0 ) {
    pos = - (pos + 1 ) ; 
    pos <<= 1 ; 
    * b = utable_compose_long_pairs [pos + 1 ] ; 
    return utable_compose_long_pairs [pos ] ; 
  }
  else {
    key = utable_compose_pairs [pos ] ; 
    * b = (key & 0xFFFF ) ; 
    return (key >> 16 ) ; 
  }
}
int get_kompat_decomposition (mzchar key , unsigned short * * chars ) {
  /* No conversion */
  int pos = (3357 >> 1 ) , new_pos ; 
  int below_len = pos ; 
  int above_len = (3357 - pos - 1 ) ; 
  while (key != utable_kompat_decomp_keys [pos ] ) {
    if (key > utable_kompat_decomp_keys [pos ] ) {
      if (! above_len )
        return 0 ; 
      new_pos = pos + (above_len >> 1 ) + 1 ; 
      below_len = (new_pos - pos - 1 ) ; 
      above_len = (above_len - below_len - 1 ) ; 
      pos = new_pos ; 
    }
    else if (key < utable_kompat_decomp_keys [pos ] ) {
      if (! below_len )
        return 0 ; 
      new_pos = pos - ((below_len >> 1 ) + 1 ) ; 
      above_len = (pos - new_pos - 1 ) ; 
      below_len = (below_len - above_len - 1 ) ; 
      pos = new_pos ; 
    }
  }
  * chars = utable_kompat_decomp_strs XFORM_OK_PLUS utable_kompat_decomp_indices [pos ] ; 
  return utable_kompat_decomp_lens [pos ] ; 
}
/* this far 3698 */
/* this far 3697 */
/* this far 3630 */
static Scheme_Object * normalize_c (Scheme_Object * o ) {
  mzchar * s , * s2 , tmp , last_c0 = 0 ; 
  int len , i , j = 0 , last_c0_pos = 0 , last_cc = 0 ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(s2, 0), PUSH(s, 1)));
# define XfOrM625_COUNT (2)
# define SETUP_XfOrM625(x) SETUP(XfOrM625_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  s2 = NULLED_OUT ; 
  s = (((Scheme_Simple_Object * ) (o ) ) -> u . char_str_val . string_val ) ; 
  len = (((Scheme_Simple_Object * ) (o ) ) -> u . char_str_val . tag_val ) ; 
  s2 = (mzchar * ) FUNCCALL(SETUP_XfOrM625(_), GC_malloc_atomic ((len + 1 ) * sizeof (mzchar ) ) ); 
  (memcpy (s2 , s , len * sizeof (mzchar ) ) ) ; 
  for (i = 0 ; i < len ; i ++ ) {
#   define XfOrM637_COUNT (0+XfOrM625_COUNT)
#   define SETUP_XfOrM637(x) SETUP_XfOrM625(x)
    if ((i + 1 < len ) && (s2 [i ] >= 0x1100 ) && (s2 [i ] <= (0x1100 + 19 - 1 ) ) && (s2 [i + 1 ] >= 0x1161 ) && (s2 [i + 1 ] <= (0x1161 + 21 - 1 ) ) ) {
      if ((i + 2 < len ) && (s2 [i + 2 ] > 0x11A7 ) && (s2 [i + 2 ] <= (0x11A7 + 28 - 1 ) ) ) {
        tmp = (0xAC00 + ((s2 [i ] - 0x1100 ) * 21 * 28 ) + ((s2 [i + 1 ] - 0x1161 ) * 28 ) + (s2 [i + 2 ] - 0x11A7 ) ) ; 
        i += 2 ; 
      }
      else {
        tmp = (0xAC00 + ((s2 [i ] - 0x1100 ) * 21 * 28 ) + ((s2 [i + 1 ] - 0x1161 ) * 28 ) ) ; 
        i ++ ; 
      }
      last_c0 = tmp ; 
      last_c0_pos = j ; 
      last_cc = 0 ; 
      s2 [j ++ ] = tmp ; 
    }
    else {
      int cc ; 
#     define XfOrM638_COUNT (0+XfOrM637_COUNT)
#     define SETUP_XfOrM638(x) SETUP_XfOrM637(x)
      cc = (scheme_uchar_combining_classes [(scheme_uchar_cases_table [(s2 [i ] >> 8 ) & 0x1FFF ] [s2 [i ] & 0xFF ] ) ] ) ; 
      if (last_c0 && (cc > last_cc ) )
        tmp = FUNCCALL(SETUP_XfOrM638(_), get_composition (last_c0 , s2 [i ] ) ); 
      else tmp = 0 ; 
      if (tmp ) {
        s2 [last_c0_pos ] = tmp ; 
        last_c0 = tmp ; 
      }
      else if (! cc ) {
        tmp = s2 [i ] ; 
        if ((((scheme_uchar_table [(tmp >> 8 ) & 0x1FFF ] [tmp & 0xFF ] ) ) & 0x8000 ) ) {
          last_c0 = tmp ; 
          last_c0_pos = j ; 
        }
        else {
          last_c0 = 0 ; 
        }
        last_cc = - 1 ; 
        s2 [j ++ ] = tmp ; 
      }
      else {
        s2 [j ++ ] = s2 [i ] ; 
        last_cc = cc ; 
      }
    }
  }
  s2 [j ] = 0 ; 
  if (len - j > 16 ) {
#   define XfOrM626_COUNT (0+XfOrM625_COUNT)
#   define SETUP_XfOrM626(x) SETUP_XfOrM625(x)
    s2 = (mzchar * ) FUNCCALL(SETUP_XfOrM626(_), GC_malloc_atomic ((j + 1 ) * sizeof (mzchar ) ) ); 
    (memcpy (s2 , s , (j + 1 ) * sizeof (mzchar ) ) ) ; 
    s2 = s ; 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_char_string (s2 , j , 0 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 3756 */
static Scheme_Object * normalize_d (Scheme_Object * o , int kompat ) {
  mzchar * s , tmp , * s2 ; 
  int len , i , delta , j , swapped ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(s2, 0), PUSH(s, 1)));
# define XfOrM647_COUNT (2)
# define SETUP_XfOrM647(x) SETUP(XfOrM647_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  s2 = NULLED_OUT ; 
  s = (((Scheme_Simple_Object * ) (o ) ) -> u . char_str_val . string_val ) ; 
  len = (((Scheme_Simple_Object * ) (o ) ) -> u . char_str_val . tag_val ) ; 
  delta = 0 ; 
  for (i = 0 ; i < len ; i ++ ) {
#   define XfOrM727_COUNT (0+XfOrM647_COUNT)
#   define SETUP_XfOrM727(x) SETUP_XfOrM647(x)
    if ((((scheme_uchar_table [(s [i ] >> 8 ) & 0x1FFF ] [s [i ] & 0xFF ] ) ) & 0x4000 ) ) {
      int klen ; 
      mzchar snd ; 
      GC_CAN_IGNORE unsigned short * start ; 
#     define XfOrM729_COUNT (0+XfOrM727_COUNT)
#     define SETUP_XfOrM729(x) SETUP_XfOrM727(x)
      tmp = s [i ] ; 
      while ((((scheme_uchar_table [(tmp >> 8 ) & 0x1FFF ] [tmp & 0xFF ] ) ) & 0x4000 ) ) {
#       define XfOrM736_COUNT (0+XfOrM729_COUNT)
#       define SETUP_XfOrM736(x) SETUP_XfOrM729(x)
        if (kompat )
          klen = FUNCCALL(SETUP_XfOrM736(_), get_kompat_decomposition (tmp , & start ) ); 
        else klen = 0 ; 
        if (klen ) {
          delta += (klen - 1 ) ; 
          break ; 
        }
        else {
#         define XfOrM737_COUNT (0+XfOrM736_COUNT)
#         define SETUP_XfOrM737(x) SETUP_XfOrM736(x)
          tmp = FUNCCALL(SETUP_XfOrM737(_), get_canon_decomposition (tmp , & snd ) ); 
          if (tmp ) {
#           define XfOrM738_COUNT (0+XfOrM737_COUNT)
#           define SETUP_XfOrM738(x) SETUP_XfOrM737(x)
            if (snd ) {
              delta ++ ; 
#             define XfOrM739_COUNT (0+XfOrM738_COUNT)
#             define SETUP_XfOrM739(x) SETUP_XfOrM738(x)
              if (kompat ) {
#               define XfOrM740_COUNT (0+XfOrM739_COUNT)
#               define SETUP_XfOrM740(x) SETUP_XfOrM739(x)
                klen = FUNCCALL(SETUP_XfOrM740(_), get_kompat_decomposition (snd , & start ) ); 
                if (klen )
                  delta += (klen - 1 ) ; 
              }
            }
          }
          else break ; 
        }
      }
    }
    else if ((s [i ] >= 0xAC00 ) && (s [i ] <= (0xAC00 + 11171 ) ) ) {
      tmp = s [i ] ; 
      tmp -= 0xAC00 ; 
      if (tmp % 28 )
        delta += 2 ; 
      else delta += 1 ; 
    }
  }
  s2 = (mzchar * ) FUNCCALL(SETUP_XfOrM647(_), GC_malloc_atomic ((len + delta + 1 ) * sizeof (mzchar ) ) ); 
  j = 0 ; 
  for (i = 0 ; i < len ; i ++ ) {
#   define XfOrM685_COUNT (0+XfOrM647_COUNT)
#   define SETUP_XfOrM685(x) SETUP_XfOrM647(x)
    if ((((scheme_uchar_table [(s [i ] >> 8 ) & 0x1FFF ] [s [i ] & 0xFF ] ) ) & 0x4000 ) ) {
      mzchar snd , tmp2 ; 
      int snds = 0 , klen = 0 , k ; 
      GC_CAN_IGNORE unsigned short * start ; 
#     define XfOrM689_COUNT (0+XfOrM685_COUNT)
#     define SETUP_XfOrM689(x) SETUP_XfOrM685(x)
      tmp = s [i ] ; 
      while ((((scheme_uchar_table [(tmp >> 8 ) & 0x1FFF ] [tmp & 0xFF ] ) ) & 0x4000 ) ) {
#       define XfOrM701_COUNT (0+XfOrM689_COUNT)
#       define SETUP_XfOrM701(x) SETUP_XfOrM689(x)
        if (kompat )
          klen = FUNCCALL(SETUP_XfOrM701(_), get_kompat_decomposition (tmp , & start ) ); 
        else klen = 0 ; 
        if (klen ) {
          for (k = 0 ; k < klen ; k ++ ) {
            s2 [j ++ ] = start [k ] ; 
          }
          break ; 
        }
        else {
#         define XfOrM702_COUNT (0+XfOrM701_COUNT)
#         define SETUP_XfOrM702(x) SETUP_XfOrM701(x)
          tmp2 = FUNCCALL(SETUP_XfOrM702(_), get_canon_decomposition (tmp , & snd ) ); 
          if (tmp2 ) {
#           define XfOrM703_COUNT (0+XfOrM702_COUNT)
#           define SETUP_XfOrM703(x) SETUP_XfOrM702(x)
            tmp = tmp2 ; 
            if (snd ) {
#             define XfOrM704_COUNT (0+XfOrM703_COUNT)
#             define SETUP_XfOrM704(x) SETUP_XfOrM703(x)
              if (kompat )
                klen = FUNCCALL(SETUP_XfOrM704(_), get_kompat_decomposition (snd , & start ) ); 
              else klen = 0 ; 
              if (klen ) {
                snds += klen ; 
                for (k = 0 ; k < klen ; k ++ ) {
                  s2 [len + delta - snds + k ] = start [k ] ; 
                }
                klen = 0 ; 
              }
              else {
                snds ++ ; 
                s2 [len + delta - snds ] = snd ; 
              }
            }
          }
          else break ; 
        }
      }
      if (! klen )
        s2 [j ++ ] = tmp ; 
      (memcpy (s2 + j , s2 + len + delta - snds , snds * sizeof (mzchar ) ) ) ; 
      j += snds ; 
    }
    else if ((s [i ] >= 0xAC00 ) && (s [i ] <= (0xAC00 + 11171 ) ) ) {
      int l , v , t ; 
      tmp = s [i ] ; 
      tmp -= 0xAC00 ; 
      l = tmp / (21 * 28 ) ; 
      v = (tmp % (21 * 28 ) ) / 28 ; 
      t = tmp % 28 ; 
      s2 [j ++ ] = 0x1100 + l ; 
      s2 [j ++ ] = 0x1161 + v ; 
      if (t ) {
        s2 [j ++ ] = 0x11A7 + t ; 
      }
    }
    else {
      s2 [j ++ ] = s [i ] ; 
    }
  }
  s2 [j ] = 0 ; 
  len += delta ; 
  do {
    swapped = 0 ; 
    for (i = 0 ; i < len ; i ++ ) {
      if ((i + 1 < len ) && (scheme_uchar_combining_classes [(scheme_uchar_cases_table [(s2 [i ] >> 8 ) & 0x1FFF ] [s2 [i ] & 0xFF ] ) ] ) && (scheme_uchar_combining_classes [(scheme_uchar_cases_table [(s2 [i + 1 ] >> 8 ) & 0x1FFF ] [s2 [i + 1 ] & 0xFF ] ) ] ) && ((scheme_uchar_combining_classes [(scheme_uchar_cases_table [(s2 [i + 1 ] >> 8 ) & 0x1FFF ] [s2 [i + 1 ] & 0xFF ] ) ] ) < (scheme_uchar_combining_classes [(scheme_uchar_cases_table [(s2 [i ] >> 8 ) & 0x1FFF ] [s2 [i ] & 0xFF ] ) ] ) ) ) {
        tmp = s2 [i + 1 ] ; 
        s2 [i + 1 ] = s2 [i ] ; 
        s2 [i ] = tmp ; 
        i -- ; 
        swapped = 1 ; 
      }
    }
  }
  while (swapped ) ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_char_string (s2 , len , 0 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_string_normalize_c (const char * who , int argc , Scheme_Object * argv [] , int kompat ) {
  Scheme_Object * o ; 
  mzchar * s , last_c0 = 0 , snd ; 
  int len , i , last_cc = 0 ; 
  Scheme_Object * __funcarg145 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(s, 1)));
# define XfOrM742_COUNT (2)
# define SETUP_XfOrM742(x) SETUP(XfOrM742_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  o = NULLED_OUT ; 
  s = NULLED_OUT ; 
  o = argv [0 ] ; 
  if (! ((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type (who , "string" , 0 , argc , argv ) ); 
  s = (((Scheme_Simple_Object * ) (o ) ) -> u . char_str_val . string_val ) ; 
  len = (((Scheme_Simple_Object * ) (o ) ) -> u . char_str_val . tag_val ) ; 
  for (i = 0 ; i < len ; i ++ ) {
#   define XfOrM751_COUNT (0+XfOrM742_COUNT)
#   define SETUP_XfOrM751(x) SETUP_XfOrM742(x)
    if ((((scheme_uchar_table [(s [i ] >> 8 ) & 0x1FFF ] [s [i ] & 0xFF ] ) ) & 0x4000 ) && (kompat || FUNCCALL(SETUP_XfOrM751(_), get_canon_decomposition (s [i ] , & snd ) )) ) {
      break ; 
    }
    else if ((i + 1 < len ) && (scheme_uchar_combining_classes [(scheme_uchar_cases_table [(s [i ] >> 8 ) & 0x1FFF ] [s [i ] & 0xFF ] ) ] ) && (scheme_uchar_combining_classes [(scheme_uchar_cases_table [(s [i + 1 ] >> 8 ) & 0x1FFF ] [s [i + 1 ] & 0xFF ] ) ] ) && ((scheme_uchar_combining_classes [(scheme_uchar_cases_table [(s [i + 1 ] >> 8 ) & 0x1FFF ] [s [i + 1 ] & 0xFF ] ) ] ) < (scheme_uchar_combining_classes [(scheme_uchar_cases_table [(s [i ] >> 8 ) & 0x1FFF ] [s [i ] & 0xFF ] ) ] ) ) ) {
      break ; 
    }
    else if ((s [i ] >= 0x1100 ) && (s [i ] <= (0x1100 + 19 - 1 ) ) && (s [i + 1 ] >= 0x1161 ) && (s [i + 1 ] <= (0x1161 + 21 - 1 ) ) ) {
      break ; 
    }
    else if (last_c0 && FUNCCALL(SETUP_XfOrM751(_), get_composition (last_c0 , s [i ] ) )&& ((scheme_uchar_combining_classes [(scheme_uchar_cases_table [(s [i ] >> 8 ) & 0x1FFF ] [s [i ] & 0xFF ] ) ] ) > last_cc ) ) {
      break ; 
    }
    else {
      int cc ; 
      cc = (scheme_uchar_combining_classes [(scheme_uchar_cases_table [(s [i ] >> 8 ) & 0x1FFF ] [s [i ] & 0xFF ] ) ] ) ; 
      if (! cc ) {
        if ((((scheme_uchar_table [(s [i ] >> 8 ) & 0x1FFF ] [s [i ] & 0xFF ] ) ) & 0x8000 ) )
          last_c0 = s [i ] ; 
        else last_c0 = 0 ; 
        last_cc = - 1 ; 
      }
      else last_cc = cc ; 
    }
  }
  if (i < len ) {
#   define XfOrM743_COUNT (0+XfOrM742_COUNT)
#   define SETUP_XfOrM743(x) SETUP_XfOrM742(x)
    o = (__funcarg145 = FUNCCALL(SETUP_XfOrM743(_), normalize_d (o , kompat ) ), FUNCCALL_AGAIN(normalize_c (__funcarg145 ) )) ; 
  }
  RET_VALUE_START (o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * string_normalize_c (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_string_normalize_c ("string-normalize-nfc" , argc , argv , 0 ) ; 
}
static Scheme_Object * string_normalize_kc (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_string_normalize_c ("string-normalize-nfkc" , argc , argv , 1 ) ; 
}
static Scheme_Object * do_string_normalize_d (const char * who , int argc , Scheme_Object * argv [] , int kompat ) {
  Scheme_Object * o ; 
  mzchar * s ; 
  int len , i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(s, 1)));
# define XfOrM760_COUNT (2)
# define SETUP_XfOrM760(x) SETUP(XfOrM760_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  o = NULLED_OUT ; 
  s = NULLED_OUT ; 
  o = argv [0 ] ; 
  if (! ((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type (who , "string" , 0 , argc , argv ) ); 
  s = (((Scheme_Simple_Object * ) (o ) ) -> u . char_str_val . string_val ) ; 
  len = (((Scheme_Simple_Object * ) (o ) ) -> u . char_str_val . tag_val ) ; 
  for (i = len ; i -- ; ) {
#   define XfOrM766_COUNT (0+XfOrM760_COUNT)
#   define SETUP_XfOrM766(x) SETUP_XfOrM760(x)
    if ((((scheme_uchar_table [(s [i ] >> 8 ) & 0x1FFF ] [s [i ] & 0xFF ] ) ) & 0x4000 ) ) {
      mzchar snd ; 
#     define XfOrM769_COUNT (0+XfOrM766_COUNT)
#     define SETUP_XfOrM769(x) SETUP_XfOrM766(x)
      if (kompat || FUNCCALL(SETUP_XfOrM769(_), get_canon_decomposition (s [i ] , & snd ) ))
        break ; 
    }
    else if ((i + 1 < len ) && (scheme_uchar_combining_classes [(scheme_uchar_cases_table [(s [i ] >> 8 ) & 0x1FFF ] [s [i ] & 0xFF ] ) ] ) && (scheme_uchar_combining_classes [(scheme_uchar_cases_table [(s [i + 1 ] >> 8 ) & 0x1FFF ] [s [i + 1 ] & 0xFF ] ) ] ) && ((scheme_uchar_combining_classes [(scheme_uchar_cases_table [(s [i + 1 ] >> 8 ) & 0x1FFF ] [s [i + 1 ] & 0xFF ] ) ] ) < (scheme_uchar_combining_classes [(scheme_uchar_cases_table [(s [i ] >> 8 ) & 0x1FFF ] [s [i ] & 0xFF ] ) ] ) ) ) {
      break ; 
    }
    else if ((s [i ] >= 0xAC00 ) && (s [i ] <= (0xAC00 + 11171 ) ) ) {
      break ; 
    }
  }
  if (i >= 0 ) {
#   define XfOrM761_COUNT (0+XfOrM760_COUNT)
#   define SETUP_XfOrM761(x) SETUP_XfOrM760(x)
    o = FUNCCALL(SETUP_XfOrM761(_), normalize_d (o , kompat ) ); 
  }
  RET_VALUE_START (o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * string_normalize_d (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_string_normalize_d ("string-normalize-nfd" , argc , argv , 0 ) ; 
}
static Scheme_Object * string_normalize_kd (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_string_normalize_d ("string-normalize-nfkd" , argc , argv , 1 ) ; 
}
int scheme_char_strlen (const mzchar * s ) {
  /* No conversion */
  int i ; 
  for (i = 0 ; s [i ] ; i ++ ) {
  }
  return i ; 
}
static int mz_char_strcmp (const char * who , const mzchar * str1 , int l1 , const mzchar * str2 , int l2 , int use_locale , int size_shortcut ) {
  int endres ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(str1, 0), PUSH(str2, 1), PUSH(who, 2)));
# define XfOrM775_COUNT (3)
# define SETUP_XfOrM775(x) SETUP(XfOrM775_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (size_shortcut && (l1 != l2 ) )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  if (use_locale ) {
#   define XfOrM780_COUNT (0+XfOrM775_COUNT)
#   define SETUP_XfOrM780(x) SETUP_XfOrM775(x)
    FUNCCALL(SETUP_XfOrM780(_), reset_locale () ); 
    if (locale_on ) {
#     define XfOrM781_COUNT (0+XfOrM780_COUNT)
#     define SETUP_XfOrM781(x) SETUP_XfOrM780(x)
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(do_locale_comp (who , str1 , l1 , str2 , l2 , 0 ) )) RET_VALUE_EMPTY_END ; 
    }
  }
  if (l1 > l2 ) {
    l1 = l2 ; 
    endres = 1 ; 
  }
  else {
    if (l2 > l1 )
      endres = - 1 ; 
    else endres = 0 ; 
  }
  while (l1 -- ) {
    unsigned int a , b ; 
    a = * (str1 ++ ) ; 
    b = * (str2 ++ ) ; 
    a = a - b ; 
    if (a )
      RET_VALUE_START (a ) RET_VALUE_END ; 
  }
  RET_VALUE_START (endres ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int mz_char_strcmp_ci (const char * who , const mzchar * str1 , int l1 , const mzchar * str2 , int l2 , int use_locale , int size_shortcut ) {
  int p1 , p2 , sp1 , sp2 , a , b ; 
  mzchar spec1 [3 ] , spec2 [3 ] ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(str1, 0), PUSH(str2, 1), PUSH(who, 2)));
# define XfOrM782_COUNT (3)
# define SETUP_XfOrM782(x) SETUP(XfOrM782_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (size_shortcut && (l1 != l2 ) )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  if (use_locale ) {
#   define XfOrM809_COUNT (0+XfOrM782_COUNT)
#   define SETUP_XfOrM809(x) SETUP_XfOrM782(x)
    FUNCCALL(SETUP_XfOrM809(_), reset_locale () ); 
    if (locale_on ) {
#     define XfOrM810_COUNT (0+XfOrM809_COUNT)
#     define SETUP_XfOrM810(x) SETUP_XfOrM809(x)
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(do_locale_comp (who , str1 , l1 , str2 , l2 , 1 ) )) RET_VALUE_EMPTY_END ; 
    }
  }
  p1 = sp1 = 0 ; 
  p2 = sp2 = 0 ; 
  while (((p1 < l1 ) || sp1 ) && ((p2 < l2 ) || sp2 ) ) {
#   define XfOrM796_COUNT (0+XfOrM782_COUNT)
#   define SETUP_XfOrM796(x) SETUP_XfOrM782(x)
    if (sp1 ) {
      a = spec1 [-- sp1 ] ; 
    }
    else {
#     define XfOrM803_COUNT (0+XfOrM796_COUNT)
#     define SETUP_XfOrM803(x) SETUP_XfOrM796(x)
      a = str1 [p1 ] ; 
      if ((((scheme_uchar_table [(a >> 8 ) & 0x1FFF ] [a & 0xFF ] ) ) & 0x2000 ) ) {
        int pos , i ; 
#       define XfOrM805_COUNT (0+XfOrM803_COUNT)
#       define SETUP_XfOrM805(x) SETUP_XfOrM803(x)
        pos = FUNCCALL(SETUP_XfOrM805(_), find_special_casing (a ) ); 
        sp1 = uchar_special_casings [pos + 7 ] ; 
        pos = uchar_special_casings [pos + 8 ] ; 
        for (i = sp1 ; i -- ; pos ++ ) {
          spec1 [i ] = uchar_special_casing_data [pos ] ; 
        }
        a = spec1 [-- sp1 ] ; 
      }
      else {
        a = (a + scheme_uchar_folds [(scheme_uchar_cases_table [(a >> 8 ) & 0x1FFF ] [a & 0xFF ] ) ] ) ; 
      }
      p1 ++ ; 
    }
    if (sp2 ) {
      b = spec2 [-- sp2 ] ; 
    }
    else {
#     define XfOrM797_COUNT (0+XfOrM796_COUNT)
#     define SETUP_XfOrM797(x) SETUP_XfOrM796(x)
      b = str2 [p2 ] ; 
      if ((((scheme_uchar_table [(b >> 8 ) & 0x1FFF ] [b & 0xFF ] ) ) & 0x2000 ) ) {
        int pos , i ; 
#       define XfOrM799_COUNT (0+XfOrM797_COUNT)
#       define SETUP_XfOrM799(x) SETUP_XfOrM797(x)
        pos = FUNCCALL(SETUP_XfOrM799(_), find_special_casing (b ) ); 
        sp2 = uchar_special_casings [pos + 7 ] ; 
        pos = uchar_special_casings [pos + 8 ] ; 
        for (i = sp2 ; i -- ; pos ++ ) {
          spec2 [i ] = uchar_special_casing_data [pos ] ; 
        }
        b = spec2 [-- sp2 ] ; 
      }
      else {
        b = (b + scheme_uchar_folds [(scheme_uchar_cases_table [(b >> 8 ) & 0x1FFF ] [b & 0xFF ] ) ] ) ; 
      }
      p2 ++ ; 
    }
    a = a - b ; 
    if (a )
      RET_VALUE_START (a ) RET_VALUE_END ; 
  }
  RET_VALUE_START (((p1 < l1 ) || sp1 ) - ((p2 < l2 ) || sp2 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int mz_strcmp (const char * who , unsigned char * str1 , int l1 , unsigned char * str2 , int l2 ) {
  /* No conversion */
  int endres ; 
  if (l1 > l2 ) {
    l1 = l2 ; 
    endres = 1 ; 
  }
  else {
    if (l2 > l1 )
      endres = - 1 ; 
    else endres = 0 ; 
  }
  while (l1 -- ) {
    unsigned int a , b ; 
    a = * (str1 ++ ) ; 
    b = * (str2 ++ ) ; 
    a = a - b ; 
    if (a )
      return a ; 
  }
  return endres ; 
}
static void close_converter (Scheme_Object * o , void * data ) {
  Scheme_Converter * c = (Scheme_Converter * ) o ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(c, 0)));
# define XfOrM816_COUNT (1)
# define SETUP_XfOrM816(x) SETUP(XfOrM816_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! c -> closed ) {
#   define XfOrM817_COUNT (0+XfOrM816_COUNT)
#   define SETUP_XfOrM817(x) SETUP_XfOrM816(x)
    c -> closed = 1 ; 
    if (c -> kind == 0 ) {
#     define XfOrM819_COUNT (0+XfOrM817_COUNT)
#     define SETUP_XfOrM819(x) SETUP_XfOrM817(x)
      FUNCCALL(SETUP_XfOrM819(_), iconv_close (c -> cd ) ); 
      c -> cd = (iconv_t ) - 1 ; 
    }
    if (c -> mref ) {
#     define XfOrM818_COUNT (0+XfOrM817_COUNT)
#     define SETUP_XfOrM818(x) SETUP_XfOrM817(x)
      FUNCCALL(SETUP_XfOrM818(_), scheme_remove_managed (c -> mref , (Scheme_Object * ) c ) ); 
      c -> mref = ((void * ) 0 ) ; 
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_open_converter (const char * from_e , const char * to_e ) {
  Scheme_Converter * c ; 
  iconv_t cd ; 
  int kind ; 
  int permissive ; 
  int need_regis = 1 ; 
  Scheme_Custodian_Reference * mref ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(cd, 0), PUSH(mref, 1), PUSH(from_e, 2), PUSH(c, 3), PUSH(to_e, 4)));
# define XfOrM820_COUNT (5)
# define SETUP_XfOrM820(x) SETUP(XfOrM820_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  c = NULLED_OUT ; 
  cd = NULLED_OUT ; 
  mref = NULLED_OUT ; 
  if (! 1 )
    FUNCCALL(SETUP_XfOrM820(_), init_iconv () ); 
  if (! * to_e || ! * from_e )
    FUNCCALL(SETUP_XfOrM820(_), reset_locale () ); 
  if ((! (strcmp (from_e , "UTF-8" ) ) || ! (strcmp (from_e , "UTF-8-permissive" ) ) || (! * from_e && ! 1 ) ) && (! (strcmp (to_e , "UTF-8" ) ) || (! * to_e && ! 1 ) ) ) {
#   define XfOrM824_COUNT (0+XfOrM820_COUNT)
#   define SETUP_XfOrM824(x) SETUP_XfOrM820(x)
    kind = 1 ; 
    if (! (strcmp (from_e , "UTF-8-permissive" ) ) )
      permissive = '?' ; 
    else permissive = 0 ; 
    cd = (iconv_t ) - 1 ; 
    need_regis = (* to_e && * from_e ) ; 
  }
  else if ((! (strcmp (from_e , "platform-UTF-8" ) ) || ! (strcmp (from_e , "platform-UTF-8-permissive" ) ) ) && ! (strcmp (to_e , "platform-UTF-16" ) ) ) {
#   define XfOrM823_COUNT (0+XfOrM820_COUNT)
#   define SETUP_XfOrM823(x) SETUP_XfOrM820(x)
    kind = 2 ; 
    if (! (strcmp (from_e , "platform-UTF-8-permissive" ) ) )
      permissive = '?' ; 
    else permissive = 0 ; 
    cd = (iconv_t ) - 1 ; 
    need_regis = 0 ; 
  }
  else if (! (strcmp (from_e , "platform-UTF-16" ) ) && ! (strcmp (to_e , "platform-UTF-8" ) ) ) {
    kind = 3 ; 
    permissive = 0 ; 
    cd = (iconv_t ) - 1 ; 
    need_regis = 0 ; 
  }
  else {
#   define XfOrM821_COUNT (0+XfOrM820_COUNT)
#   define SETUP_XfOrM821(x) SETUP_XfOrM820(x)
    if (! 1 )
      FUNCCALL(SETUP_XfOrM821(_), init_iconv () ); 
    if (! 1 )
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    if (! * from_e || ! * to_e )
      FUNCCALL(SETUP_XfOrM821(_), reset_locale () ); 
    if (! * from_e )
      from_e = "" ; 
    if (! * to_e )
      to_e = "" ; 
    cd = FUNCCALL(SETUP_XfOrM821(_), iconv_open (to_e , from_e ) ); 
    if (cd == (iconv_t ) - 1 )
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    kind = 0 ; 
    permissive = 0 ; 
  }
  c = ((Scheme_Converter * ) FUNCCALL(SETUP_XfOrM820(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Converter ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  c -> so . type = scheme_string_converter_type ; 
  c -> closed = 0 ; 
  c -> kind = kind ; 
  c -> permissive = permissive ; 
  c -> cd = cd ; 
  if (! need_regis )
    mref = ((void * ) 0 ) ; 
  else mref = FUNCCALL(SETUP_XfOrM820(_), scheme_add_managed (((void * ) 0 ) , (Scheme_Object * ) c , close_converter , ((void * ) 0 ) , 1 ) ); 
  c -> mref = mref ; 
  RET_VALUE_START ((Scheme_Object * ) c ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * byte_string_open_converter (int argc , Scheme_Object * * argv ) {
  Scheme_Object * s1 , * s2 ; 
  char * from_e , * to_e ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(s1, 0), PUSH(s2, 1), PUSH(from_e, 2), PUSH(to_e, 3), PUSH(argv, 4)));
# define XfOrM825_COUNT (5)
# define SETUP_XfOrM825(x) SETUP(XfOrM825_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s1 = NULLED_OUT ; 
  s2 = NULLED_OUT ; 
  from_e = NULLED_OUT ; 
  to_e = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("bytes-open-converter" , "byte string" , 0 , argc , argv ) ); 
  if (! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("bytes-open-converter" , "byte string" , 1 , argc , argv ) ); 
  FUNCCALL(SETUP_XfOrM825(_), scheme_custodian_check_available (((void * ) 0 ) , "bytes-open-converter" , "converter" ) ); 
  s1 = FUNCCALL_AGAIN(scheme_char_string_to_byte_string (argv [0 ] ) ); 
  s2 = FUNCCALL_AGAIN(scheme_char_string_to_byte_string (argv [1 ] ) ); 
  if (FUNCCALL(SETUP_XfOrM825(_), scheme_byte_string_has_null (s1 ) ))
    RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
  if (FUNCCALL(SETUP_XfOrM825(_), scheme_byte_string_has_null (s2 ) ))
    RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
  from_e = (((Scheme_Simple_Object * ) (s1 ) ) -> u . byte_str_val . string_val ) ; 
  to_e = (((Scheme_Simple_Object * ) (s2 ) ) -> u . byte_str_val . string_val ) ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_open_converter (from_e , to_e ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * convert_one (const char * who , int opos , int argc , Scheme_Object * argv [] ) {
  char * r , * instr ; 
  int status ; 
  long amt_read , amt_wrote ; 
  long istart , ifinish , ostart , ofinish ; 
  Scheme_Object * a [3 ] , * status_sym ; 
  Scheme_Converter * c ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(10);
  BLOCK_SETUP_TOP((PUSH(r, 0), PUSHARRAY(a, 3, 1), PUSH(status_sym, 4), PUSH(instr, 5), PUSH(c, 6), PUSH(argv, 7), PUSH(who, 8)));
# define XfOrM826_COUNT (9)
# define SETUP_XfOrM826(x) SETUP(XfOrM826_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  r = NULLED_OUT ; 
  instr = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  a[2] = NULLED_OUT ; 
  status_sym = NULLED_OUT ; 
  c = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_string_converter_type ) ) )
    FUNCCALL(SETUP_XfOrM826(_), scheme_wrong_type (who , "converter" , 0 , argc , argv ) ); 
  if (opos > 1 ) {
#   define XfOrM866_COUNT (0+XfOrM826_COUNT)
#   define SETUP_XfOrM866(x) SETUP_XfOrM826(x)
    if (! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
      FUNCCALL(SETUP_XfOrM866(_), scheme_wrong_type (who , "bytes" , 1 , argc , argv ) ); 
    FUNCCALL(SETUP_XfOrM866(_), scheme_get_substring_indices (who , argv [1 ] , argc , argv , 2 , 3 , & istart , & ifinish ) ); 
  }
  else {
    istart = 0 ; 
    ifinish = 4 ; 
  }
  if (argc > opos ) {
#   define XfOrM855_COUNT (0+XfOrM826_COUNT)
#   define SETUP_XfOrM855(x) SETUP_XfOrM826(x)
    if ((! (((argv [opos ] ) ) == (scheme_false ) ) ) ) {
#     define XfOrM864_COUNT (0+XfOrM855_COUNT)
#     define SETUP_XfOrM864(x) SETUP_XfOrM855(x)
      if (! (((Scheme_Type ) (((((long ) (argv [opos ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [opos ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) && (! (((Scheme_Inclhash_Object * ) (argv [opos ] ) ) -> so . keyex & 0x1 ) ) ) )
        FUNCCALL(SETUP_XfOrM864(_), scheme_wrong_type (who , "mutable byte string" , opos , argc , argv ) ); 
      r = (((Scheme_Simple_Object * ) (argv [opos ] ) ) -> u . byte_str_val . string_val ) ; 
      FUNCCALL(SETUP_XfOrM864(_), scheme_get_substring_indices (who , argv [opos ] , argc , argv , opos + 1 , opos + 2 , & ostart , & ofinish ) ); 
    }
    else {
      int ip ; 
#     define XfOrM856_COUNT (0+XfOrM855_COUNT)
#     define SETUP_XfOrM856(x) SETUP_XfOrM855(x)
      r = ((void * ) 0 ) ; 
      for (ip = opos + 1 ; ip <= opos + 2 ; ip ++ ) {
#       define XfOrM862_COUNT (0+XfOrM856_COUNT)
#       define SETUP_XfOrM862(x) SETUP_XfOrM856(x)
        if (argc > ip ) {
          int ok = 0 ; 
#         define XfOrM863_COUNT (0+XfOrM862_COUNT)
#         define SETUP_XfOrM863(x) SETUP_XfOrM862(x)
          if ((((long ) (argv [ip ] ) ) & 0x1 ) )
            ok = (((long ) (argv [ip ] ) ) >> 1 ) >= 0 ; 
          else if (((Scheme_Type ) (((((long ) (argv [ip ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [ip ] ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
            ok = ((& ((Scheme_Bignum * ) argv [ip ] ) -> iso ) -> so . keyex & 0x1 ) ; 
          else if ((ip == opos + 2 ) && (((argv [ip ] ) ) == (scheme_false ) ) )
            ok = 1 ; 
          if (! ok )
            FUNCCALL(SETUP_XfOrM863(_), scheme_wrong_type (who , ((ip == opos + 2 ) ? "non-negative exact integer or #f" : "non-negative exact integer" ) , ip , argc , argv ) ); 
        }
      }
      if ((argc > opos + 2 ) && (! (((argv [opos + 2 ] ) ) == (scheme_false ) ) ) ) {
        Scheme_Object * delta ; 
        BLOCK_SETUP((PUSH(delta, 0+XfOrM856_COUNT)));
#       define XfOrM858_COUNT (1+XfOrM856_COUNT)
#       define SETUP_XfOrM858(x) SETUP(XfOrM858_COUNT)
        delta = NULLED_OUT ; 
        if (FUNCCALL(SETUP_XfOrM858(_), scheme_bin_lt (argv [opos + 2 ] , argv [opos + 1 ] ) )) {
#         define XfOrM859_COUNT (0+XfOrM858_COUNT)
#         define SETUP_XfOrM859(x) SETUP_XfOrM858(x)
          FUNCCALL(SETUP_XfOrM859(_), scheme_arg_mismatch (who , "ending index is less than the starting index: " , argv [opos + 2 ] ) ); 
        }
        delta = FUNCCALL(SETUP_XfOrM858(_), scheme_bin_minus (argv [opos + 2 ] , argv [opos + 1 ] ) ); 
        if (((Scheme_Type ) (((((long ) (delta ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (delta ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
          ofinish = - 1 ; 
        else ofinish = (((long ) (delta ) ) >> 1 ) ; 
        ostart = 0 ; 
      }
      else {
        ostart = 0 ; 
        ofinish = - 1 ; 
      }
    }
  }
  else {
    r = ((void * ) 0 ) ; 
    ostart = 0 ; 
    ofinish = - 1 ; 
  }
  c = (Scheme_Converter * ) argv [0 ] ; 
  if (c -> closed )
    FUNCCALL(SETUP_XfOrM826(_), scheme_arg_mismatch (who , "converter is closed: " , argv [0 ] ) ); 
  instr = ((opos > 1 ) ? (((Scheme_Simple_Object * ) (argv [1 ] ) ) -> u . byte_str_val . string_val ) : ((void * ) 0 ) ) ; 
  if (c -> kind == 3 ) {
#   define XfOrM847_COUNT (0+XfOrM826_COUNT)
#   define SETUP_XfOrM847(x) SETUP_XfOrM826(x)
    if (istart & 0x1 ) {
      char * c2 ; 
      BLOCK_SETUP((PUSH(c2, 0+XfOrM847_COUNT)));
#     define XfOrM853_COUNT (1+XfOrM847_COUNT)
#     define SETUP_XfOrM853(x) SETUP(XfOrM853_COUNT)
      c2 = NULLED_OUT ; 
      c2 = (char * ) FUNCCALL(SETUP_XfOrM853(_), GC_malloc_atomic (ifinish - istart ) ); 
      (memcpy (c2 , instr XFORM_OK_PLUS istart , ifinish - istart ) ) ; 
      ifinish = ifinish - istart ; 
      istart = 0 ; 
      instr = c2 ; 
    }
    status = (utf8_encode_x ((const unsigned int * ) instr , istart >> 1 , ifinish >> 1 , (unsigned char * ) r , ostart , ofinish , & amt_read , & amt_wrote , 1 ) ) ; 
    amt_read -= (istart >> 1 ) ; 
    if (amt_read ) {
#     define XfOrM851_COUNT (0+XfOrM847_COUNT)
#     define SETUP_XfOrM851(x) SETUP_XfOrM847(x)
      if (! r ) {
#       define XfOrM852_COUNT (0+XfOrM851_COUNT)
#       define SETUP_XfOrM852(x) SETUP_XfOrM851(x)
        r = (char * ) FUNCCALL(SETUP_XfOrM852(_), GC_malloc_atomic (amt_wrote + 1 ) ); 
        (utf8_encode_x ((const unsigned int * ) instr , istart >> 1 , ifinish >> 1 , (unsigned char * ) r , ostart , ofinish , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ) ; 
        r [amt_wrote ] = 0 ; 
      }
      amt_read <<= 1 ; 
    }
    if (status != - 1 ) {
      if (amt_read < ((ifinish - istart ) & ~ 0x1 ) ) {
        status = 1 ; 
      }
      else {
        if ((ifinish - istart ) & 0x1 )
          status = - 1 ; 
        else status = 0 ; 
      }
    }
  }
  else if (c -> kind != 0 ) {
#   define XfOrM836_COUNT (0+XfOrM826_COUNT)
#   define SETUP_XfOrM836(x) SETUP_XfOrM826(x)
    if (instr ) {
      long _ostart , _ofinish ; 
      int utf16 ; 
#     define XfOrM838_COUNT (0+XfOrM836_COUNT)
#     define SETUP_XfOrM838(x) SETUP_XfOrM836(x)
      if (c -> kind == 2 ) {
        _ostart = ostart ; 
        _ofinish = ofinish ; 
        if (_ostart & 0x1 )
          _ostart ++ ; 
        _ostart >>= 1 ; 
        if (_ofinish > 0 )
          _ofinish >>= 1 ; 
        utf16 = 1 ; 
      }
      else {
        _ostart = ostart ; 
        _ofinish = ofinish ; 
        utf16 = 0 ; 
      }
      status = (utf8_decode_x ((unsigned char * ) instr , istart , ifinish , (unsigned int * ) r , _ostart , _ofinish , & amt_read , & amt_wrote , 1 , utf16 , ((void * ) 0 ) , 1 , c -> permissive ) ) ; 
      if (utf16 ) {
        _ostart <<= 1 ; 
        amt_wrote <<= 1 ; 
#       define XfOrM843_COUNT (0+XfOrM838_COUNT)
#       define SETUP_XfOrM843(x) SETUP_XfOrM838(x)
        if ((ostart & 0x1 ) && (amt_wrote > _ostart ) ) {
#         define XfOrM844_COUNT (0+XfOrM843_COUNT)
#         define SETUP_XfOrM844(x) SETUP_XfOrM843(x)
          (memmove (r XFORM_OK_PLUS ostart , r XFORM_OK_PLUS _ostart , amt_wrote - _ostart ) ) ; 
        }
      }
      amt_read -= istart ; 
      amt_wrote -= _ostart ; 
      if (status == - 3 ) {
        status = 1 ; 
      }
      else {
#       define XfOrM839_COUNT (0+XfOrM838_COUNT)
#       define SETUP_XfOrM839(x) SETUP_XfOrM838(x)
        if (amt_wrote ) {
#         define XfOrM840_COUNT (0+XfOrM839_COUNT)
#         define SETUP_XfOrM840(x) SETUP_XfOrM839(x)
          if (! r ) {
#           define XfOrM841_COUNT (0+XfOrM840_COUNT)
#           define SETUP_XfOrM841(x) SETUP_XfOrM840(x)
            r = (char * ) FUNCCALL(SETUP_XfOrM841(_), GC_malloc_atomic (amt_wrote + 1 ) ); 
            (utf8_decode_x ((unsigned char * ) instr , istart , ifinish , (unsigned int * ) r , ostart , _ofinish , ((void * ) 0 ) , ((void * ) 0 ) , 1 , utf16 , ((void * ) 0 ) , 1 , c -> permissive ) ) ; 
            r [amt_wrote ] = 0 ; 
          }
        }
        else if (! r )
          r = "" ; 
        if (status > 0 )
          status = 0 ; 
      }
    }
    else {
      r = "" ; 
      status = 0 ; 
      amt_read = 0 ; 
      amt_wrote = 0 ; 
    }
  }
  else {
#   define XfOrM835_COUNT (0+XfOrM826_COUNT)
#   define SETUP_XfOrM835(x) SETUP_XfOrM826(x)
    r = FUNCCALL(SETUP_XfOrM835(_), do_convert (c -> cd , ((void * ) 0 ) , ((void * ) 0 ) , 0 , instr , istart , ifinish - istart , r , ostart , ofinish - ostart , ! r , 0 , (r ? 0 : 1 ) , & amt_read , & amt_wrote , & status ) ); 
  }
  if (status == 0 ) {
    status_sym = complete_symbol ; 
  }
  else if (status == 1 ) {
    status_sym = continues_symbol ; 
  }
  else if (status == - 1 ) {
    status_sym = aborts_symbol ; 
  }
  else {
    status_sym = error_symbol ; 
  }
  if (argc <= opos ) {
#   define XfOrM830_COUNT (0+XfOrM826_COUNT)
#   define SETUP_XfOrM830(x) SETUP_XfOrM826(x)
    a [0 ] = FUNCCALL(SETUP_XfOrM830(_), scheme_make_sized_byte_string (r , amt_wrote , 0 ) ); 
  }
  else {
    a [0 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (amt_wrote ) ) << 1 ) | 0x1 ) ) ; 
  }
  if (opos > 1 ) {
#   define XfOrM828_COUNT (0+XfOrM826_COUNT)
#   define SETUP_XfOrM828(x) SETUP_XfOrM826(x)
    a [1 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (amt_read ) ) << 1 ) | 0x1 ) ) ; 
    a [2 ] = status_sym ; 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM828(_), scheme_values (3 , a ) )) RET_VALUE_END ; 
  }
  else {
#   define XfOrM827_COUNT (0+XfOrM826_COUNT)
#   define SETUP_XfOrM827(x) SETUP_XfOrM826(x)
    a [1 ] = status_sym ; 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM827(_), scheme_values (2 , a ) )) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * byte_string_convert (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return convert_one ("bytes-convert" , 4 , argc , argv ) ; 
}
static Scheme_Object * byte_string_convert_end (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return convert_one ("bytes-convert-end" , 1 , argc , argv ) ; 
}
void scheme_close_converter (Scheme_Object * conv ) {
  /* No conversion */
  close_converter (conv , ((void * ) 0 ) ) ; 
}
static Scheme_Object * byte_string_close_converter (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_string_converter_type ) ) )
    scheme_wrong_type ("bytes-close-converter" , "converter" , 0 , argc , argv ) ; 
  scheme_close_converter (argv [0 ] ) ; 
  return scheme_void ; 
}
static Scheme_Object * byte_converter_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_string_converter_type ) ) ? scheme_true : scheme_false ) ; 
}
/* this far 4780 */
/* this far 4780 */
static int utf8_decode_x (const unsigned char * s , int start , int end , unsigned int * us , int dstart , int dend , long * ipos , long * jpos , char compact , char utf16 , int * _state , int might_continue , int permissive ) {
  /* No conversion */
  int i , j , oki , failmode = - 3 , state ; 
  int init_doki ; 
  int nextbits , v ; 
  unsigned int sc ; 
  if (_state ) {
    state = (* _state ) & 0x7 ; 
    init_doki = (((* _state ) >> 3 ) & 0x7 ) ; 
    nextbits = ((((* _state ) >> 6 ) & 0xF ) << 2 ) ; 
    v = ((* _state ) >> 10 ) ; 
  }
  else {
    state = 0 ; 
    init_doki = 0 ; 
    nextbits = 0 ; 
    v = 0 ; 
  }
  if (end < 0 )
    end = strlen ((char * ) s ) ; 
  if (dend < 0 )
    dend = 0x7FFFFFFF ; 
  oki = start ; 
  j = dstart ; 
  i = start ; 
  if (j < dend ) {
    while (i < end ) {
      sc = s [i ] ; 
      if (sc < 0x80 ) {
        if (state ) {
          state = 0 ; 
          nextbits = 0 ; 
          if (permissive ) {
            v = permissive ; 
            i = oki ; 
            j += init_doki ; 
          }
          else {
            i = oki ; 
            failmode = - 2 ; 
            break ; 
          }
        }
        else {
          v = sc ; 
        }
      }
      else if ((sc & 0xC0 ) == 0x80 ) {
        if (state ) {
          if (! nextbits || (sc & nextbits ) ) {
            v = (v << 6 ) + (sc & 0x3F ) ; 
            nextbits = 0 ; 
            -- state ; 
            if (state ) {
              i ++ ; 
              continue ; 
            }
            if ((((v >= 0xD800 ) && (v <= 0xDFFF ) ) || (v > 0x10FFFF ) ) ) {
              if (permissive ) {
                v = permissive ; 
                j += init_doki ; 
                i = oki ; 
              }
              else {
                i = oki ; 
                failmode = - 2 ; 
                break ; 
              }
            }
          }
          else {
            state = 0 ; 
            nextbits = 0 ; 
            if (permissive ) {
              v = permissive ; 
              j += init_doki ; 
              i = oki ; 
            }
            else {
              i = oki ; 
              failmode = - 2 ; 
              break ; 
            }
          }
        }
        else {
          if (permissive ) {
            v = permissive ; 
          }
          else {
            i = oki ; 
            failmode = - 2 ; 
            break ; 
          }
        }
      }
      else if (state ) {
        state = 0 ; 
        if (permissive ) {
          v = permissive ; 
          i = oki ; 
          j += init_doki ; 
        }
        else {
          i = oki ; 
          failmode = - 2 ; 
          break ; 
        }
      }
      else {
        if ((sc & 0xE0 ) == 0xC0 ) {
          if (sc & 0x1E ) {
            state = 1 ; 
            v = (sc & 0x1F ) ; 
            i ++ ; 
            continue ; 
          }
        }
        else if ((sc & 0xF0 ) == 0xE0 ) {
          state = 2 ; 
          v = (sc & 0xF ) ; 
          if (! v )
            nextbits = 0x20 ; 
          i ++ ; 
          continue ; 
        }
        else if ((sc & 0xF8 ) == 0xF0 ) {
          v = (sc & 0x7 ) ; 
          if (v <= 4 ) {
            state = 3 ; 
            if (! v )
              nextbits = 0x30 ; 
            i ++ ; 
            continue ; 
          }
        }
        if (permissive ) {
          v = permissive ; 
        }
        else {
          i = oki ; 
          failmode = - 2 ; 
          break ; 
        }
      }
      if (compact ) {
        if (utf16 ) {
          if (v > 0xFFFF ) {
            if (j + 1 >= dend )
              break ; 
            if (us ) {
              v -= 0x10000 ; 
              ((unsigned short * ) us ) [j ] = 0xD800 | ((v >> 10 ) & 0x3FF ) ; 
              ((unsigned short * ) us ) [j + 1 ] = 0xDC00 | (v & 0x3FF ) ; 
            }
            j ++ ; 
          }
          else {
            if (us )
              ((unsigned short * ) us ) [j ] = v ; 
          }
        }
        else {
          int delta ; 
          delta = (i - oki ) ; 
          if (delta ) {
            if (j + delta + 1 < dend ) {
              if (us )
                memcpy (((char * ) us ) + j , s + oki , delta + 1 ) ; 
              j += delta ; 
            }
            else break ; 
          }
          else if (us ) {
            ((unsigned char * ) us ) [j ] = v ; 
          }
        }
      }
      else if (us ) {
        us [j ] = v ; 
      }
      j ++ ; 
      i ++ ; 
      oki = i ; 
      init_doki = 0 ; 
      if (j >= dend )
        break ; 
    }
  }
  if (_state ) {
    if (! state )
      * _state = 0 ; 
    else * _state = (state | (((end - oki ) + init_doki ) << 3 ) | ((nextbits >> 2 ) << 6 ) | (v << 10 ) ) ; 
  }
  else if (state ) {
    if (might_continue || ! permissive ) {
      failmode = - 1 ; 
      i = end - 1 ; 
    }
    else if (permissive ) {
      for (i = oki ; i < end ; i ++ ) {
        if (j < dend ) {
          if (us ) {
            if (compact ) {
              if (utf16 )
                ((unsigned short * ) us ) [j ] = permissive ; 
              else ((unsigned char * ) us ) [j ] = permissive ; 
            }
            else us [j ] = permissive ; 
          }
          j ++ ; 
        }
        else break ; 
      }
      oki = i ; 
    }
  }
  if (ipos )
    * ipos = oki ; 
  if (jpos )
    * jpos = j ; 
  if (i < end )
    return failmode ; 
  return j - dstart ; 
}
int scheme_utf8_decode (const unsigned char * s , int start , int end , unsigned int * us , int dstart , int dend , long * ipos , char utf16 , int permissive ) {
  /* No conversion */
  return utf8_decode_x (s , start , end , us , dstart , dend , ipos , ((void * ) 0 ) , utf16 , utf16 , ((void * ) 0 ) , 0 , permissive ) ; 
}
int scheme_utf8_decode_as_prefix (const unsigned char * s , int start , int end , unsigned int * us , int dstart , int dend , long * ipos , char utf16 , int permissive ) {
  /* No conversion */
  long opos ; 
  utf8_decode_x (s , start , end , us , dstart , dend , ipos , & opos , utf16 , utf16 , ((void * ) 0 ) , 1 , permissive ) ; 
  return opos - dstart ; 
}
int scheme_utf8_decode_all (const unsigned char * s , int len , unsigned int * us , int permissive ) {
  /* No conversion */
  return utf8_decode_x (s , 0 , len , us , 0 , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 0 , 0 , ((void * ) 0 ) , 0 , permissive ) ; 
}
int scheme_utf8_decode_prefix (const unsigned char * s , int len , unsigned int * us , int permissive ) {
  /* No conversion */
  {
    int i ; 
    for (i = 0 ; i < len ; i ++ ) {
      if (s [i ] < 128 )
        us [i ] = s [i ] ; 
      else break ; 
    }
    if (i == len )
      return len ; 
  }
  return utf8_decode_x (s , 0 , len , us , 0 , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 0 , 0 , ((void * ) 0 ) , 1 , permissive ) ; 
}
/* this far 4909 */
mzchar * scheme_utf8_decode_to_buffer_len (const unsigned char * s , int len , mzchar * buf , int blen , long * _ulen ) {
  int ulen ; 
  DECL_RET_SAVE (mzchar * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(_ulen, 0), PUSH(buf, 1), PUSH(s, 2)));
# define XfOrM975_COUNT (3)
# define SETUP_XfOrM975(x) SETUP(XfOrM975_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ulen = (utf8_decode_x (s , 0 , len , ((void * ) 0 ) , 0 , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 0 , 0 , ((void * ) 0 ) , 0 , 0 ) ) ; 
  if (ulen < 0 )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  if (ulen + 1 > blen ) {
#   define XfOrM976_COUNT (0+XfOrM975_COUNT)
#   define SETUP_XfOrM976(x) SETUP_XfOrM975(x)
    buf = (mzchar * ) FUNCCALL(SETUP_XfOrM976(_), GC_malloc_atomic ((ulen + 1 ) * sizeof (mzchar ) ) ); 
  }
  (utf8_decode_x (s , 0 , len , buf , 0 , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 0 , 0 , ((void * ) 0 ) , 0 , 0 ) ) ; 
  buf [ulen ] = 0 ; 
  * _ulen = ulen ; 
  RET_VALUE_START (buf ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
mzchar * scheme_utf8_decode_to_buffer (const unsigned char * s , int len , mzchar * buf , int blen ) {
  /* No conversion */
  long ulen ; 
  return scheme_utf8_decode_to_buffer_len (s , len , buf , blen , & ulen ) ; 
}
int scheme_utf8_decode_count (const unsigned char * s , int start , int end , int * _state , int might_continue , int permissive ) {
  /* No conversion */
  long pos = 0 ; 
  if (! _state || ! * _state ) {
    int i ; 
    for (i = start ; i < end ; i ++ ) {
      if (s [i ] > 127 )
        break ; 
    }
    if (i == end )
      return end - start ; 
  }
  utf8_decode_x (s , start , end , ((void * ) 0 ) , 0 , - 1 , ((void * ) 0 ) , & pos , 0 , 0 , _state , might_continue , permissive ) ; 
  return pos ; 
}
static int utf8_encode_x (const unsigned int * us , int start , int end , unsigned char * s , int dstart , int dend , long * _ipos , long * _opos , char utf16 ) {
  /* No conversion */
  int i , j , done = start ; 
  if (dend < 0 )
    dend = 0x7FFFFFFF ; 
  if (! s ) {
    unsigned int wc ; 
    j = 0 ; 
    for (i = start ; i < end ; i ++ ) {
      if (utf16 ) {
        wc = ((unsigned short * ) us ) [i ] ; 
        if ((wc & 0xF800 ) == 0xD800 ) {
          if (((i + 1 ) == end ) && ((wc & 0xF800 ) == 0xD800 ) && _opos ) {
            * _opos = j ; 
            if (_ipos )
              * _ipos = i ; 
            return - 1 ; 
          }
          {
            i ++ ; 
            wc = ((wc & 0x3FF ) << 10 ) + ((((unsigned short * ) us ) [i ] ) & 0x3FF ) ; 
            wc += 0x10000 ; 
          }
        }
      }
      else {
        wc = us [i ] ; 
      }
      if (wc < 0x80 ) {
        j += 1 ; 
      }
      else if (wc < 0x800 ) {
        j += 2 ; 
      }
      else if (wc < 0x10000 ) {
        j += 3 ; 
      }
      else if (wc < 0x200000 ) {
        j += 4 ; 
      }
      else if (wc < 0x4000000 ) {
        j += 5 ; 
      }
      else {
        j += 6 ; 
      }
    }
    if (_ipos )
      * _ipos = i ; 
    if (_opos )
      * _opos = j + dstart ; 
    return j ; 
  }
  else {
    unsigned int wc ; 
    j = dstart ; 
    for (i = start ; i < end ; i ++ ) {
      if (utf16 ) {
        wc = ((unsigned short * ) us ) [i ] ; 
        if ((wc & 0xF800 ) == 0xD800 ) {
          if (((i + 1 ) == end ) && ((wc & 0xF800 ) == 0xD800 ) && _opos ) {
            * _opos = j ; 
            if (_ipos )
              * _ipos = i ; 
            return - 1 ; 
          }
          {
            i ++ ; 
            wc = ((wc & 0x3FF ) << 10 ) + ((((unsigned short * ) us ) [i ] ) & 0x3FF ) ; 
            wc += 0x10000 ; 
          }
        }
      }
      else {
        wc = us [i ] ; 
      }
      if (wc < 0x80 ) {
        if (j + 1 > dend )
          break ; 
        s [j ++ ] = wc ; 
      }
      else if (wc < 0x800 ) {
        if (j + 2 > dend )
          break ; 
        s [j ++ ] = 0xC0 | ((wc & 0x7C0 ) >> 6 ) ; 
        s [j ++ ] = 0x80 | (wc & 0x3F ) ; 
      }
      else if (wc < 0x10000 ) {
        if (j + 3 > dend )
          break ; 
        s [j ++ ] = 0xE0 | ((wc & 0xF000 ) >> 12 ) ; 
        s [j ++ ] = 0x80 | ((wc & 0x0FC0 ) >> 6 ) ; 
        s [j ++ ] = 0x80 | (wc & 0x3F ) ; 
      }
      else if (wc < 0x200000 ) {
        if (j + 4 > dend )
          break ; 
        s [j ++ ] = 0xF0 | ((wc & 0x1C0000 ) >> 18 ) ; 
        s [j ++ ] = 0x80 | ((wc & 0x03F000 ) >> 12 ) ; 
        s [j ++ ] = 0x80 | ((wc & 0x000FC0 ) >> 6 ) ; 
        s [j ++ ] = 0x80 | (wc & 0x3F ) ; 
      }
      else if (wc < 0x4000000 ) {
        if (j + 5 > dend )
          break ; 
        s [j ++ ] = 0xF8 | ((wc & 0x3000000 ) >> 24 ) ; 
        s [j ++ ] = 0x80 | ((wc & 0x0FC0000 ) >> 18 ) ; 
        s [j ++ ] = 0x80 | ((wc & 0x003F000 ) >> 12 ) ; 
        s [j ++ ] = 0x80 | ((wc & 0x0000FC0 ) >> 6 ) ; 
        s [j ++ ] = 0x80 | (wc & 0x3F ) ; 
      }
      else {
        if (j + 6 > dend )
          break ; 
        s [j ++ ] = 0xFC | ((wc & 0x40000000 ) >> 30 ) ; 
        s [j ++ ] = 0x80 | ((wc & 0x3F000000 ) >> 24 ) ; 
        s [j ++ ] = 0x80 | ((wc & 0x00FC0000 ) >> 18 ) ; 
        s [j ++ ] = 0x80 | ((wc & 0x0003F000 ) >> 12 ) ; 
        s [j ++ ] = 0x80 | ((wc & 0x00000FC0 ) >> 6 ) ; 
        s [j ++ ] = 0x80 | (wc & 0x3F ) ; 
      }
      done = i ; 
    }
    if (_ipos )
      * _ipos = done ; 
    if (_opos )
      * _opos = j ; 
    return j - dstart ; 
  }
}
int scheme_utf8_encode (const unsigned int * us , int start , int end , unsigned char * s , int dstart , char utf16 ) {
  /* No conversion */
  return utf8_encode_x (us , start , end , s , dstart , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , utf16 ) ; 
}
int scheme_utf8_encode_all (const unsigned int * us , int len , unsigned char * s ) {
  /* No conversion */
  return utf8_encode_x (us , 0 , len , s , 0 , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ; 
}
char * scheme_utf8_encode_to_buffer_len (const mzchar * s , int len , char * buf , int blen , long * _slen ) {
  int slen ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(_slen, 0), PUSH(buf, 1), PUSH(s, 2)));
# define XfOrM1035_COUNT (3)
# define SETUP_XfOrM1035(x) SETUP(XfOrM1035_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (len < blen ) {
    for (slen = 0 ; slen < len ; slen ++ ) {
      if (s [slen ] > 127 )
        break ; 
      else buf [slen ] = s [slen ] ; 
    }
    if (slen == len ) {
      buf [slen ] = 0 ; 
      * _slen = slen ; 
      RET_VALUE_START (buf ) RET_VALUE_END ; 
    }
  }
  slen = (utf8_encode_x (s , 0 , len , ((void * ) 0 ) , 0 , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ) ; 
  if (slen + 1 > blen ) {
#   define XfOrM1036_COUNT (0+XfOrM1035_COUNT)
#   define SETUP_XfOrM1036(x) SETUP_XfOrM1035(x)
    buf = (char * ) FUNCCALL(SETUP_XfOrM1036(_), GC_malloc_atomic (slen + 1 ) ); 
  }
  (utf8_encode_x (s , 0 , len , (unsigned char * ) buf , 0 , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ) ; 
  buf [slen ] = 0 ; 
  * _slen = slen ; 
  RET_VALUE_START (buf ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
char * scheme_utf8_encode_to_buffer (const mzchar * s , int len , char * buf , int blen ) {
  /* No conversion */
  long slen ; 
  return scheme_utf8_encode_to_buffer_len (s , len , buf , blen , & slen ) ; 
}
unsigned short * scheme_ucs4_to_utf16 (const mzchar * text , int start , int end , unsigned short * buf , int bufsize , long * ulen , int term_size ) {
  mzchar v ; 
  int extra , i , j ; 
  unsigned short * utf16 ; 
  DECL_RET_SAVE (unsigned short * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(utf16, 0), PUSH(ulen, 1), PUSH(text, 2)));
# define XfOrM1042_COUNT (3)
# define SETUP_XfOrM1042(x) SETUP(XfOrM1042_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  utf16 = NULLED_OUT ; 
  for (i = start , extra = 0 ; i < end ; i ++ ) {
    if (text [i ] > 0xFFFF )
      extra ++ ; 
  }
  if ((end - start ) + extra + term_size < bufsize )
    utf16 = buf ; 
  else utf16 = (unsigned short * ) FUNCCALL(SETUP_XfOrM1042(_), GC_malloc_atomic (sizeof (unsigned short ) * ((end - start ) + extra + term_size ) ) ); 
  for (i = start , j = 0 ; i < end ; i ++ ) {
    v = text [i ] ; 
    if (v > 0xFFFF ) {
      utf16 [j ++ ] = 0xD800 | ((v >> 10 ) & 0x3FF ) ; 
      utf16 [j ++ ] = 0xDC00 | (v & 0x3FF ) ; 
    }
    else utf16 [j ++ ] = v ; 
  }
  * ulen = j ; 
  RET_VALUE_START (utf16 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 5206 */
mzchar * scheme_utf16_to_ucs4 (const unsigned short * text , int start , int end , mzchar * buf , int bufsize , long * ulen , int term_size ) {
  int wc ; 
  int i , j ; 
  DECL_RET_SAVE (mzchar * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(ulen, 0), PUSH(buf, 1), PUSH(text, 2)));
# define XfOrM1049_COUNT (3)
# define SETUP_XfOrM1049(x) SETUP(XfOrM1049_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  for (i = start , j = 0 ; i < end ; i ++ ) {
    wc = text [i ] ; 
    if ((wc & 0xF800 ) == 0xD800 ) {
      i ++ ; 
    }
    j ++ ; 
  }
  if (j + term_size >= bufsize )
    buf = (mzchar * ) FUNCCALL(SETUP_XfOrM1049(_), GC_malloc_atomic ((j + term_size ) * sizeof (mzchar ) ) ); 
  for (i = start , j = 0 ; i < end ; i ++ ) {
    wc = text [i ] ; 
    if ((wc & 0xF800 ) == 0xD800 ) {
      i ++ ; 
      wc = ((wc & 0x3FF ) << 10 ) + ((((unsigned short * ) text ) [i ] ) & 0x3FF ) ; 
      wc += 0x10000 ; 
    }
    buf [j ++ ] = wc ; 
  }
  * ulen = j ; 
  RET_VALUE_START (buf ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static char * uname_locations [] = {
  "/bin/uname" , "/usr/bin/uname" , "/sbin/uname" , "/usr/sbin/uname" , "/usr/local/bin/uname" , "/usr/local/uname" , ((void * ) 0 ) }
; 
static int try_subproc (Scheme_Object * subprocess_proc , char * prog ) {
  Scheme_Object * a [5 ] ; 
  mz_jmp_buf * volatile savebuf , newbuf ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(savebuf, 0), PUSH(subprocess_proc, 1), PUSHARRAY(a, 5, 2), PUSH(prog, 5)));
# define XfOrM1058_COUNT (6)
# define SETUP_XfOrM1058(x) SETUP(XfOrM1058_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  NULL_OUT_ARRAY (a ) ; 
  savebuf = NULLED_OUT ; 
  savebuf = scheme_current_thread -> error_buf ; 
  scheme_current_thread -> error_buf = & newbuf ; 
  if (! ((newbuf ) . gcvs = (long ) __gc_var_stack__ , (newbuf ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((newbuf ) . jb ) , (_setjmp (((newbuf ) . jb ) -> jb ) ) ) ) ) {
#   define XfOrM1060_COUNT (0+XfOrM1058_COUNT)
#   define SETUP_XfOrM1060(x) SETUP_XfOrM1058(x)
    a [0 ] = scheme_false ; 
    a [1 ] = scheme_false ; 
    a [2 ] = scheme_false ; 
    a [3 ] = FUNCCALL(SETUP_XfOrM1060(_), scheme_make_locale_string (prog ) ); 
    a [4 ] = FUNCCALL(SETUP_XfOrM1060(_), scheme_make_locale_string ("-a" ) ); 
    FUNCCALL(SETUP_XfOrM1060(_), scheme_do_eval (subprocess_proc , 5 , a , - 1 ) ); 
    scheme_current_thread -> error_buf = savebuf ; 
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM1059_COUNT (0+XfOrM1058_COUNT)
#   define SETUP_XfOrM1059(x) SETUP_XfOrM1058(x)
    FUNCCALL(SETUP_XfOrM1059(_), scheme_clear_escape () ); 
    scheme_current_thread -> error_buf = savebuf ; 
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void machine_details (char * buff ) {
  Scheme_Object * subprocess_proc ; 
  int i ; 
  PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(subprocess_proc, 0), PUSH(buff, 1)));
# define XfOrM1061_COUNT (2)
# define SETUP_XfOrM1061(x) SETUP(XfOrM1061_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  subprocess_proc = NULLED_OUT ; 
  subprocess_proc = FUNCCALL(SETUP_XfOrM1061(_), scheme_builtin_value ("subprocess" ) ); 
  for (i = 0 ; uname_locations [i ] ; i ++ ) {
#   define XfOrM1067_COUNT (0+XfOrM1061_COUNT)
#   define SETUP_XfOrM1067(x) SETUP_XfOrM1061(x)
    if (FUNCCALL(SETUP_XfOrM1067(_), scheme_file_exists (uname_locations [i ] ) )) {
#     define XfOrM1068_COUNT (0+XfOrM1067_COUNT)
#     define SETUP_XfOrM1068(x) SETUP_XfOrM1067(x)
      if (FUNCCALL(SETUP_XfOrM1068(_), try_subproc (subprocess_proc , uname_locations [i ] ) )) {
        Scheme_Object * sout , * sin , * serr ; 
        long c ; 
        BLOCK_SETUP((PUSH(serr, 0+XfOrM1068_COUNT), PUSH(sout, 1+XfOrM1068_COUNT)));
#       define XfOrM1069_COUNT (2+XfOrM1068_COUNT)
#       define SETUP_XfOrM1069(x) SETUP(XfOrM1069_COUNT)
        sout = NULLED_OUT ; 
        sin = NULLED_OUT ; 
        serr = NULLED_OUT ; 
        sout = scheme_current_thread -> ku . multiple . array [1 ] ; 
        sin = scheme_current_thread -> ku . multiple . array [2 ] ; 
        serr = scheme_current_thread -> ku . multiple . array [3 ] ; 
        FUNCCALL(SETUP_XfOrM1069(_), scheme_close_output_port (sin ) ); 
        FUNCCALL_AGAIN(scheme_close_input_port (serr ) ); 
        (strcpy (buff , "<unknown machine>" ) ) ; 
        c = FUNCCALL(SETUP_XfOrM1069(_), scheme_get_bytes (sout , 1023 , buff , 0 ) ); 
        buff [c ] = 0 ; 
        FUNCCALL(SETUP_XfOrM1069(_), scheme_close_input_port (sout ) ); 
        while (c && (((((unsigned char * ) buff ) [c - 1 ] ) < 128 ) && ((* FUNCCALL(SETUP_XfOrM1069(_), __ctype_b_loc () )) [(int ) ((((unsigned char * ) buff ) [c - 1 ] ) ) ] & (unsigned short int ) _ISspace ) ) ) {
          buff [-- c ] = 0 ; 
        }
        RET_NOTHING ; 
      }
    }
  }
  (strcpy (buff , "<unknown machine>" ) ) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int mark_string_convert_SIZE (void * p ) {
  return ((sizeof (Scheme_Converter ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_string_convert_MARK (void * p ) {
  Scheme_Converter * c = (Scheme_Converter * ) p ; 
  GC_mark (c -> mref ) ; 
  return ((sizeof (Scheme_Converter ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_string_convert_FIXUP (void * p ) {
  Scheme_Converter * c = (Scheme_Converter * ) p ; 
  GC_fixup (& (c -> mref ) ) ; 
  return ((sizeof (Scheme_Converter ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static void register_traversers (void ) {
  GC_register_traversers (scheme_string_converter_type , mark_string_convert_SIZE , mark_string_convert_MARK , mark_string_convert_FIXUP , 1 , 0 ) ; 
}
