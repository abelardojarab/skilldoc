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
typedef unsigned short int __uint16_t ; 
typedef unsigned int __uint32_t ; 
typedef unsigned long int __uint64_t ; 
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
typedef long int __clock_t ; 
typedef unsigned int __id_t ; 
typedef long int __time_t ; 
typedef unsigned int __useconds_t ; 
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
typedef long int __intptr_t ; 
typedef unsigned int __socklen_t ; 
typedef struct _IO_FILE FILE ; 
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
extern struct _IO_FILE * stdout ; 
extern int fflush (FILE * __stream ) ; 
extern int printf (__const char * __restrict __format , ... ) ; 
extern int sprintf (char * __restrict __s , __const char * __restrict __format , ... ) __attribute__ ((__nothrow__ ) ) ; 
extern __const char * __const sys_errlist [] ; 
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
typedef __ssize_t ssize_t ; 
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
struct drand48_data {
  unsigned short int __x [3 ] ; 
  unsigned short int __old_x [3 ] ; 
  unsigned short int __c ; 
  unsigned short int __init ; 
  unsigned long long int __a ; 
}
; 
extern void * malloc (size_t __size ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__malloc__ ) ) ; 
typedef int (* __compar_fn_t ) (__const void * , __const void * ) ; 
extern void * memcpy (void * __restrict __dest , __const void * __restrict __src , size_t __n ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern void * memset (void * __s , int __c , size_t __n ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern char * strcpy (char * __restrict __dest , __const char * __restrict __src ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern char * strcat (char * __restrict __dest , __const char * __restrict __src ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern int strcmp (__const char * __s1 , __const char * __s2 ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__pure__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern size_t strlen (__const char * __s ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__pure__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
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
extern void scheme_set_case_sensitive (int ) ; 
extern void scheme_set_allow_set_undefined (int ) ; 
extern void scheme_set_binary_mode_stdio (int ) ; 
extern void scheme_set_startup_use_jit (int ) ; 
extern void scheme_set_ignore_user_paths (int ) ; 
extern int scheme_get_allow_set_undefined () ; 
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
extern Scheme_Object * scheme_set_exec_cmd (char * s ) ; 
extern Scheme_Object * scheme_set_run_cmd (char * s ) ; 
extern void scheme_set_collects_path (Scheme_Object * p ) ; 
extern Scheme_Env * scheme_basic_env (void ) ; 
extern int scheme_image_main (int argc , char * * argv ) ; 
extern int (* scheme_actual_main ) (int argc , char * * argv ) ; 
extern void scheme_set_actual_main (int (* m ) (int argc , char * * argv ) ) ; 
extern void scheme_set_stack_base (void * base , int no_auto_statics ) ; 
extern void (* scheme_on_atomic_timeout ) (void ) ; 
extern void scheme_immediate_exit (int status ) ; 
extern Scheme_Config * scheme_current_config (void ) ; 
extern void scheme_set_param (Scheme_Config * c , int pos , Scheme_Object * o ) ; 
extern Scheme_Thread * scheme_current_thread ; 
extern volatile int scheme_fuel_counter ; 
extern Scheme_Thread * scheme_get_current_thread () ; 
extern void scheme_break_thread (Scheme_Thread * p ) ; 
extern void scheme_set_can_break (int on ) ; 
extern Scheme_Object scheme_eof [1 ] ; 
extern Scheme_Object scheme_null [1 ] ; 
extern Scheme_Object * scheme_make_null (void ) ; 
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
extern Scheme_Object * scheme_apply (Scheme_Object * rator , int num_rands , Scheme_Object * * rands ) ; 
extern Scheme_Object * scheme_apply_multi_with_prompt (Scheme_Object * rator , int num_rands , Scheme_Object * * rands ) ; 
extern Scheme_Object * scheme_eval_string (const char * str , Scheme_Env * env ) ; 
extern Scheme_Object * scheme_eval_string_with_prompt (const char * str , Scheme_Env * env ) ; 
extern Scheme_Object * scheme_eval_string_all_with_prompt (const char * str , Scheme_Env * env , int all ) ; 
extern Scheme_Object * scheme_do_eval (Scheme_Object * obj , int _num_rands , Scheme_Object * * rands , int val ) ; 
extern void * GC_malloc (size_t size_in_bytes ) ; 
extern void * GC_malloc_atomic (size_t size_in_bytes ) ; 
extern void * GC_malloc_one_tagged (size_t size_in_bytes ) ; 
extern void * GC_malloc_atomic_uncollectable (size_t size_in_bytes ) ; 
extern void * GC_malloc_array_tagged (size_t size_in_bytes ) ; 
extern void * GC_malloc_allow_interior (size_t size_in_bytes ) ; 
extern void * GC_malloc_atomic_allow_interior (size_t size_in_bytes ) ; 
extern void * GC_malloc_tagged_allow_interior (size_t size_in_bytes ) ; 
extern void * * GC_variable_stack ; 
extern void GC_register_traversers (short tag , Size_Proc size , Mark_Proc mark , Fixup_Proc fixup , int is_constant_size , int is_atomic ) ; 
extern void * GC_resolve (void * p ) ; 
extern void GC_mark (const void * p ) ; 
extern void GC_fixup (void * p ) ; 
extern Scheme_Object * scheme_make_pair (Scheme_Object * car , Scheme_Object * cdr ) ; 
extern Scheme_Object * scheme_make_locale_string (const char * chars ) ; 
extern Scheme_Object * scheme_make_vector (int size , Scheme_Object * fill ) ; 
extern int scheme_file_exists (char * filename ) ; 
extern char * scheme_expand_filename (char * filename , int ilen , const char * errorin , int * ex , int guards ) ; 
extern Scheme_Object * scheme_make_path (const char * chars ) ; 
extern void scheme_add_global (const char * name , Scheme_Object * val , Scheme_Env * env ) ; 
extern Scheme_Object * scheme_builtin_value (const char * name ) ; 
extern Scheme_Object * scheme_intern_symbol (const char * name ) ; 
extern Scheme_Object * scheme_vector_to_list (Scheme_Object * vec ) ; 
extern Scheme_Object * scheme_load (const char * file ) ; 
extern char * scheme_banner (void ) ; 
extern void scheme_signal_received (void ) ; 
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
static char * get_init_filename (Scheme_Env * env ) {
  Scheme_Object * f ; 
  Scheme_Thread * volatile p ; 
  mz_jmp_buf * volatile save , newbuf ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(save, 0), PUSH(f, 1), PUSH(p, 2)));
# define XfOrM1_COUNT (3)
# define SETUP_XfOrM1(x) SETUP(XfOrM1_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  f = NULLED_OUT ; 
  p = NULLED_OUT ; 
  save = NULLED_OUT ; 
  p = FUNCCALL(SETUP_XfOrM1(_), scheme_get_current_thread () ); 
  save = p -> error_buf ; 
  p -> error_buf = & newbuf ; 
  if (! ((newbuf ) . gcvs = (long ) __gc_var_stack__ , (newbuf ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((newbuf ) . jb ) , (_setjmp (((newbuf ) . jb ) -> jb ) ) ) ) ) {
#   define XfOrM2_COUNT (0+XfOrM1_COUNT)
#   define SETUP_XfOrM2(x) SETUP_XfOrM1(x)
    f = FUNCCALL(SETUP_XfOrM2(_), scheme_builtin_value ("find-system-path" ) ); 
    if (f ) {
      Scheme_Object * a [1 ] ; 
      BLOCK_SETUP((PUSHARRAY(a, 1, 0+XfOrM2_COUNT)));
#     define XfOrM3_COUNT (3+XfOrM2_COUNT)
#     define SETUP_XfOrM3(x) SETUP(XfOrM3_COUNT)
      a[0] = NULLED_OUT ; 
      a [0 ] = FUNCCALL(SETUP_XfOrM3(_), scheme_intern_symbol ("init-file" ) ); 
      f = FUNCCALL(SETUP_XfOrM3(_), scheme_do_eval (f , 1 , a , 1 ) ); 
      if (((Scheme_Type ) (((((long ) (f ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (f ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) {
        p -> error_buf = save ; 
        RET_VALUE_START ((((Scheme_Simple_Object * ) (f ) ) -> u . byte_str_val . string_val ) ) RET_VALUE_END ; 
      }
    }
  }
  p -> error_buf = save ; 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
char * cmdline_exe_hack = "[Replace me for EXE hack                                       ]" ; 
char * binary_type_hack = "bINARy tYPe:" "zi" "3" ; 
static char * _coldir = "coLLECTs dIRECTORy:" "/nfs/ltdn/disks/ltdn_lvd_disk27/advda/elisp/doctool/mz-372/collects" "\0\0" "****************************************************************" "****************************************************************" "****************************************************************" "****************************************************************" "****************************************************************" "****************************************************************" "****************************************************************" "****************************************************************" "****************************************************************" "****************************************************************" "****************************************************************" "****************************************************************" "****************************************************************" "****************************************************************" "****************************************************************" "****************************************************************" ; 
static int _coldir_offset = 19 ; 
static int is_number_arg (const char * s ) {
  /* No conversion */
  while (* s ) {
    if (* s < '0' || * s > '9' ) {
      if (* s == '.' ) {
        s ++ ; 
        while (* s ) {
          if (* s < '0' || * s > '9' )
            return 0 ; 
          else s ++ ; 
        }
        return 1 ; 
      }
      else return 0 ; 
    }
    else s ++ ; 
  }
  return 1 ; 
}
static char * protect_quote_backslash (const char * file ) {
  int i , c ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(file, 0)));
# define XfOrM16_COUNT (1)
# define SETUP_XfOrM16(x) SETUP(XfOrM16_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  for (i = c = 0 ; file [i ] ; i ++ ) {
    if ((file [i ] == '"' ) || (file [i ] == '\\' ) )
      c ++ ; 
  }
  if (c ) {
    char * s ; 
    BLOCK_SETUP((PUSH(s, 0+XfOrM16_COUNT)));
#   define XfOrM17_COUNT (1+XfOrM16_COUNT)
#   define SETUP_XfOrM17(x) SETUP(XfOrM17_COUNT)
    s = NULLED_OUT ; 
    s = (char * ) FUNCCALL(SETUP_XfOrM17(_), malloc (i + c + 1 ) ); 
    for (i = c = 0 ; file [i ] ; i ++ ) {
      if ((file [i ] == '"' ) || (file [i ] == '\\' ) )
        s [c ++ ] = '\\' ; 
      s [c ++ ] = file [i ] ; 
    }
    s [c ] = 0 ; 
    RET_VALUE_START (s ) RET_VALUE_END ; 
  }
  else RET_VALUE_START ((char * ) file ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static char * check_script_runner (char * prog ) {
  int i ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(prog, 0)));
# define XfOrM22_COUNT (1)
# define SETUP_XfOrM22(x) SETUP(XfOrM22_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  for (i = 0 ; prog [i ] ; i ++ ) {
#   define XfOrM29_COUNT (0+XfOrM22_COUNT)
#   define SETUP_XfOrM29(x) SETUP_XfOrM22(x)
    if ((prog [i ] == 's' ) && (prog [i + 1 ] == 'c' ) && (prog [i + 2 ] == 'h' ) && (prog [i + 3 ] == 'e' ) && (prog [i + 4 ] == 'm' ) && (prog [i + 5 ] == 'e' ) && (prog [i + 6 ] == '-' ) ) {
#     define XfOrM30_COUNT (0+XfOrM29_COUNT)
#     define SETUP_XfOrM30(x) SETUP_XfOrM29(x)
      if (! i || ((prog [i - 1 ] ) == '/' ) ) {
        int j ; 
#       define XfOrM31_COUNT (0+XfOrM30_COUNT)
#       define SETUP_XfOrM31(x) SETUP_XfOrM30(x)
        for (j = i + 7 ; prog [j ] ; j ++ ) {
          if (((prog [j ] ) == '/' ) )
            break ; 
        }
        if (! prog [j ] ) {
          char * lang ; 
          BLOCK_SETUP((PUSH(lang, 0+XfOrM31_COUNT)));
#         define XfOrM32_COUNT (1+XfOrM31_COUNT)
#         define SETUP_XfOrM32(x) SETUP(XfOrM32_COUNT)
          lang = NULLED_OUT ; 
          i += 7 ; 
          j -= i ; 
          lang = (char * ) FUNCCALL(SETUP_XfOrM32(_), malloc (j + 55 ) ); 
          (memcpy (lang , "(require (lib \"init.ss\" \"script-lang\" \"" , 39 ) ) ; 
          (memcpy (lang + 39 , prog + i , j ) ) ; 
          (memcpy (lang + 39 + j , "\"))" , 4 ) ) ; 
          RET_VALUE_START (lang ) RET_VALUE_END ; 
        }
      }
    }
  }
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static char * make_load_cd (char * file ) {
  char * s ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(file, 1)));
# define XfOrM35_COUNT (2)
# define SETUP_XfOrM35(x) SETUP(XfOrM35_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  file = FUNCCALL(SETUP_XfOrM35(_), protect_quote_backslash (file ) ); 
  s = (char * ) FUNCCALL(SETUP_XfOrM35(_), malloc (strlen (file ) + 13 ) ); 
  (strcpy (s , "(load/cd \"" ) ) ; 
  (strcat (s , file ) ) ; 
  (strcat (s , "\")" ) ) ; 
  RET_VALUE_START (s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static char * make_require (char * file ) {
  char * s ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(file, 1)));
# define XfOrM36_COUNT (2)
# define SETUP_XfOrM36(x) SETUP(XfOrM36_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  file = FUNCCALL(SETUP_XfOrM36(_), protect_quote_backslash (file ) ); 
  s = (char * ) FUNCCALL(SETUP_XfOrM36(_), malloc (strlen (file ) + 20 ) ); 
  (strcpy (s , "(require (file \"" ) ) ; 
  (strcat (s , file ) ) ; 
  (strcat (s , "\"))" ) ) ; 
  RET_VALUE_START (s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static char * make_require_lib (const char * file , const char * coll ) {
  char * s ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(coll, 0), PUSH(s, 1), PUSH(file, 2)));
# define XfOrM37_COUNT (3)
# define SETUP_XfOrM37(x) SETUP(XfOrM37_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  file = FUNCCALL(SETUP_XfOrM37(_), protect_quote_backslash (file ) ); 
  coll = FUNCCALL_AGAIN(protect_quote_backslash (coll ) ); 
  s = (char * ) FUNCCALL(SETUP_XfOrM37(_), malloc (strlen (file ) + strlen (coll ) + 31 ) ); 
  (strcpy (s , "(require (lib \"" ) ) ; 
  (strcat (s , file ) ) ; 
  (strcat (s , "\" \"" ) ) ; 
  (strcat (s , coll ) ) ; 
  (strcat (s , "\"))" ) ) ; 
  RET_VALUE_START (s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static char * make_require_coll (const char * coll ) {
  char * s ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(coll, 0), PUSH(s, 1)));
# define XfOrM38_COUNT (2)
# define SETUP_XfOrM38(x) SETUP(XfOrM38_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  s = (char * ) FUNCCALL(SETUP_XfOrM38(_), malloc (strlen (coll ) + 4 ) ); 
  (strcpy (s , coll ) ) ; 
  (strcat (s , ".ss" ) ) ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(make_require_lib (s , coll ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static char * make_require_planet (const char * file , const char * file_sfx , const char * user , const char * pkg , char * pkg_sfx ) {
  char * s ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(pkg_sfx, 0), PUSH(user, 1), PUSH(pkg, 2), PUSH(file_sfx, 3), PUSH(s, 4), PUSH(file, 5)));
# define XfOrM39_COUNT (6)
# define SETUP_XfOrM39(x) SETUP(XfOrM39_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  pkg = FUNCCALL(SETUP_XfOrM39(_), protect_quote_backslash (pkg ) ); 
  user = FUNCCALL_AGAIN(protect_quote_backslash (user ) ); 
  s = (char * ) FUNCCALL(SETUP_XfOrM39(_), malloc (strlen (file ) + strlen (file_sfx ) + strlen (user ) + strlen (pkg ) + strlen (pkg_sfx ) + 46 ) ); 
  (strcpy (s , "(require (planet \"" ) ) ; 
  (strcat (s , file ) ) ; 
  (strcat (s , file_sfx ) ) ; 
  (strcat (s , "\" (\"" ) ) ; 
  (strcat (s , user ) ) ; 
  (strcat (s , "\" \"" ) ) ; 
  (strcat (s , pkg ) ) ; 
  (strcat (s , pkg_sfx ) ) ; 
  (strcat (s , "\")))" ) ) ; 
  RET_VALUE_START (s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static char * make_embedded_load (const char * start , const char * end ) {
  char * s ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(end, 0), PUSH(start, 1), PUSH(s, 2)));
# define XfOrM40_COUNT (3)
# define SETUP_XfOrM40(x) SETUP(XfOrM40_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  s = (char * ) FUNCCALL(SETUP_XfOrM40(_), malloc ((2 * strlen (start ) ) + strlen (end ) + 512 ) ); 
  (sprintf (s , "%s %s %s %s %s %s" , "(let* ([sp (find-system-path 'exec-file)] [exe (find-executable-path sp #f)]" "[s (with-input-from-file exe (lambda () " "(file-position (current-input-port)" , start , ") " "(read-bytes (- " , end , start , "))))]" "[p (open-input-bytes s)])" "(when (and (> (bytes-length s) 2)" "(= (bytes-ref s 0) (char->integer #\\#))" "(= (bytes-ref s 1) (char->integer #\\!)))" "(read-bytes-line p))" "(let loop () (let ([e (parameterize ([read-accept-compiled #t]) (read p))])" "(unless (eof-object? e) (eval e) (loop)))))" ) ) ; 
  RET_VALUE_START (s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
typedef struct {
  int start_with_req ; 
  int num_enl ; 
  int no_init_file ; 
  int no_rep ; 
  int script_mode ; 
}
FinishArgsAtoms ; 
typedef struct {
  FinishArgsAtoms * a ; 
  char * * evals_and_loads ; 
  int * eval_kind ; 
  Scheme_Object * main_args ; 
  Scheme_Env * global_env ; 
}
FinishArgs ; 
typedef void (* Repl_Proc ) (Scheme_Env * ) ; 
static int finish_cmd_line_run (FinishArgs * fa , Repl_Proc repl ) {
  volatile int exit_val = 0 ; 
  Scheme_Object * __funcarg30 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(fa, 0)));
# define XfOrM41_COUNT (1)
# define SETUP_XfOrM41(x) SETUP(XfOrM41_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (fa -> a -> start_with_req ) {
#   define XfOrM64_COUNT (0+XfOrM41_COUNT)
#   define SETUP_XfOrM64(x) SETUP_XfOrM41(x)
    FUNCCALL(SETUP_XfOrM64(_), scheme_eval_string ("(require mzscheme)" , fa -> global_env ) ); 
  }
  if (! fa -> a -> no_init_file ) {
    char * filename ; 
    BLOCK_SETUP((PUSH(filename, 0+XfOrM41_COUNT)));
#   define XfOrM62_COUNT (1+XfOrM41_COUNT)
#   define SETUP_XfOrM62(x) SETUP(XfOrM62_COUNT)
    filename = NULLED_OUT ; 
    filename = FUNCCALL(SETUP_XfOrM62(_), get_init_filename (fa -> global_env ) ); 
    if (filename ) {
#     define XfOrM63_COUNT (0+XfOrM62_COUNT)
#     define SETUP_XfOrM63(x) SETUP_XfOrM62(x)
      filename = FUNCCALL(SETUP_XfOrM63(_), scheme_expand_filename (filename , - 1 , "startup" , ((void * ) 0 ) , 0x10 ) ); 
      if (FUNCCALL(SETUP_XfOrM63(_), scheme_file_exists (filename ) ))
        FUNCCALL(SETUP_XfOrM63(_), scheme_load (filename ) ); 
    }
  }
  {
    volatile int i ; 
    mz_jmp_buf * volatile save , newbuf ; 
    BLOCK_SETUP((PUSH(save, 0+XfOrM41_COUNT)));
#   define XfOrM45_COUNT (1+XfOrM41_COUNT)
#   define SETUP_XfOrM45(x) SETUP(XfOrM45_COUNT)
    save = NULLED_OUT ; 
    for (i = 0 ; i < fa -> a -> num_enl ; i ++ ) {
#     define XfOrM54_COUNT (0+XfOrM45_COUNT)
#     define SETUP_XfOrM54(x) SETUP_XfOrM45(x)
      if (fa -> eval_kind [i ] == 1 ) {
#       define XfOrM60_COUNT (0+XfOrM54_COUNT)
#       define SETUP_XfOrM60(x) SETUP_XfOrM54(x)
        if (! FUNCCALL(SETUP_XfOrM60(_), scheme_load (fa -> evals_and_loads [i ] ) )) {
          exit_val = 1 ; 
          break ; 
        }
      }
      else if (fa -> eval_kind [i ] == 0 ) {
        Scheme_Thread * volatile p ; 
        BLOCK_SETUP((PUSH(p, 0+XfOrM54_COUNT)));
#       define XfOrM58_COUNT (1+XfOrM54_COUNT)
#       define SETUP_XfOrM58(x) SETUP(XfOrM58_COUNT)
        p = NULLED_OUT ; 
        p = FUNCCALL(SETUP_XfOrM58(_), scheme_get_current_thread () ); 
        save = p -> error_buf ; 
        p -> error_buf = & newbuf ; 
        if (! ((newbuf ) . gcvs = (long ) __gc_var_stack__ , (newbuf ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((newbuf ) . jb ) , (_setjmp (((newbuf ) . jb ) -> jb ) ) ) ) )
          FUNCCALL(SETUP_XfOrM58(_), scheme_eval_string_all_with_prompt (fa -> evals_and_loads [i ] , fa -> global_env , 0 ) ); 
        else {
          exit_val = 1 ; 
          p -> error_buf = save ; 
          break ; 
        }
        p -> error_buf = save ; 
      }
      else if (fa -> eval_kind [i ] == 2 ) {
        Scheme_Thread * volatile p ; 
        BLOCK_SETUP((PUSH(p, 0+XfOrM54_COUNT)));
#       define XfOrM55_COUNT (1+XfOrM54_COUNT)
#       define SETUP_XfOrM55(x) SETUP(XfOrM55_COUNT)
        p = NULLED_OUT ; 
        p = FUNCCALL(SETUP_XfOrM55(_), scheme_get_current_thread () ); 
        save = p -> error_buf ; 
        p -> error_buf = & newbuf ; 
        if (! ((newbuf ) . gcvs = (long ) __gc_var_stack__ , (newbuf ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((newbuf ) . jb ) , (_setjmp (((newbuf ) . jb ) -> jb ) ) ) ) ) {
          Scheme_Object * a [1 ] , * m , * fn ; 
          BLOCK_SETUP((PUSH(fn, 0+XfOrM55_COUNT), PUSHARRAY(a, 1, 1+XfOrM55_COUNT), PUSH(m, 4+XfOrM55_COUNT)));
#         define XfOrM57_COUNT (5+XfOrM55_COUNT)
#         define SETUP_XfOrM57(x) SETUP(XfOrM57_COUNT)
          a[0] = NULLED_OUT ; 
          m = NULLED_OUT ; 
          fn = NULLED_OUT ; 
          m = FUNCCALL(SETUP_XfOrM57(_), scheme_eval_string_with_prompt ("main" , fa -> global_env ) ); 
          fn = FUNCCALL_AGAIN(scheme_make_locale_string (fa -> evals_and_loads [i ] ) ); 
          ((((Scheme_Inclhash_Object * ) (fn ) ) -> so . keyex |= 0x1 ) ) ; 
          a [0 ] = (__funcarg30 = FUNCCALL(SETUP_XfOrM57(_), scheme_vector_to_list (fa -> main_args ) ), FUNCCALL_AGAIN(scheme_make_pair (fn , __funcarg30 ) )) ; 
          (void ) FUNCCALL(SETUP_XfOrM57(_), scheme_apply_multi_with_prompt (m , 1 , a ) ); 
        }
        else {
          exit_val = 1 ; 
          p -> error_buf = save ; 
          break ; 
        }
        p -> error_buf = save ; 
      }
    }
  }
  if (! fa -> a -> no_rep && ! fa -> a -> script_mode ) {
    mz_jmp_buf * volatile save , newbuf ; 
    Scheme_Thread * volatile p ; 
    BLOCK_SETUP((PUSH(save, 0+XfOrM41_COUNT), PUSH(p, 1+XfOrM41_COUNT)));
#   define XfOrM42_COUNT (2+XfOrM41_COUNT)
#   define SETUP_XfOrM42(x) SETUP(XfOrM42_COUNT)
    save = NULLED_OUT ; 
    p = NULLED_OUT ; 
    p = FUNCCALL(SETUP_XfOrM42(_), scheme_get_current_thread () ); 
    save = p -> error_buf ; 
    p -> error_buf = & newbuf ; 
    if (! ((newbuf ) . gcvs = (long ) __gc_var_stack__ , (newbuf ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((newbuf ) . jb ) , (_setjmp (((newbuf ) . jb ) -> jb ) ) ) ) ) {
#     define XfOrM44_COUNT (0+XfOrM42_COUNT)
#     define SETUP_XfOrM44(x) SETUP_XfOrM42(x)
      FUNCCALL(SETUP_XfOrM44(_), repl (fa -> global_env ) ); 
      exit_val = 0 ; 
    }
    else {
      exit_val = 1 ; 
    }
    p -> error_buf = save ; 
  }
  RET_VALUE_START (exit_val ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void init_collection_paths (Scheme_Env * global_env , Scheme_Object * extra_dirs ) {
  mz_jmp_buf * volatile save , newbuf ; 
  Scheme_Thread * volatile p ; 
  PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(extra_dirs, 0), PUSH(save, 1), PUSH(p, 2)));
# define XfOrM65_COUNT (3)
# define SETUP_XfOrM65(x) SETUP(XfOrM65_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  save = NULLED_OUT ; 
  p = NULLED_OUT ; 
  p = FUNCCALL(SETUP_XfOrM65(_), scheme_get_current_thread () ); 
  save = p -> error_buf ; 
  p -> error_buf = & newbuf ; 
  if (! ((newbuf ) . gcvs = (long ) __gc_var_stack__ , (newbuf ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((newbuf ) . jb ) , (_setjmp (((newbuf ) . jb ) -> jb ) ) ) ) ) {
    Scheme_Object * clcp , * flcp , * a [1 ] ; 
    BLOCK_SETUP((PUSH(clcp, 0+XfOrM65_COUNT), PUSHARRAY(a, 1, 1+XfOrM65_COUNT), PUSH(flcp, 4+XfOrM65_COUNT)));
#   define XfOrM66_COUNT (5+XfOrM65_COUNT)
#   define SETUP_XfOrM66(x) SETUP(XfOrM66_COUNT)
    clcp = NULLED_OUT ; 
    flcp = NULLED_OUT ; 
    a[0] = NULLED_OUT ; 
    clcp = FUNCCALL(SETUP_XfOrM66(_), scheme_builtin_value ("current-library-collection-paths" ) ); 
    flcp = FUNCCALL_AGAIN(scheme_builtin_value ("find-library-collection-paths" ) ); 
    if (clcp && flcp ) {
#     define XfOrM67_COUNT (0+XfOrM66_COUNT)
#     define SETUP_XfOrM67(x) SETUP_XfOrM66(x)
      a [0 ] = extra_dirs ; 
      a [0 ] = FUNCCALL(SETUP_XfOrM67(_), scheme_do_eval (flcp , 1 , a , 1 ) ); 
      FUNCCALL(SETUP_XfOrM67(_), scheme_do_eval (clcp , 1 , a , 1 ) ); 
    }
  }
  p -> error_buf = save ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int run_from_cmd_line (int argc , char * _argv [] , Scheme_Env * (* mk_basic_env ) (void ) , int (* cont_run ) (FinishArgs * f ) ) {
  GC_CAN_IGNORE char * * argv = _argv ; 
  Scheme_Env * global_env ; 
  char * prog , * sprog = ((void * ) 0 ) ; 
  Scheme_Object * sch_argv , * collects_path = ((void * ) 0 ) , * collects_extra = ((void * ) 0 ) ; 
  int i ; 
  char * * evals_and_loads , * real_switch = ((void * ) 0 ) , * runner ; 
  int * eval_kind , num_enl ; 
  int no_more_switches = 0 ; 
  int mute_banner = 0 ; 
  int no_argv = 0 ; 
  int start_with_req = 0 ; 
  int no_rep = 0 ; 
  int script_mode = 0 ; 
  int no_init_file = 0 ; 
  int no_lib_path = 0 ; 
  FinishArgs * fa ; 
  FinishArgsAtoms * fa_a ; 
  Scheme_Object * __funcarg39 = NULLED_OUT ; 
  char * __funcarg35 = NULLED_OUT ; 
  Scheme_Config * __funcarg34 = NULLED_OUT ; 
  Scheme_Object * __funcarg33 = NULLED_OUT ; 
  char * __funcarg31 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(15);
  BLOCK_SETUP_TOP((PUSH(prog, 0), PUSH(evals_and_loads, 1), PUSH(runner, 2), PUSH(collects_extra, 3), PUSH(eval_kind, 4), PUSH(collects_path, 5), PUSH(sch_argv, 6), PUSH(_argv, 7), PUSH(sprog, 8), PUSH(fa, 9), PUSH(global_env, 10), PUSH(fa_a, 11), PUSH(real_switch, 12)));
# define XfOrM68_COUNT (13)
# define SETUP_XfOrM68(x) SETUP(XfOrM68_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  global_env = NULLED_OUT ; 
  prog = NULLED_OUT ; 
  sch_argv = NULLED_OUT ; 
  evals_and_loads = NULLED_OUT ; 
  runner = NULLED_OUT ; 
  eval_kind = NULLED_OUT ; 
  fa = NULLED_OUT ; 
  fa_a = NULLED_OUT ; 
  prog = argv [0 ] ; 
  argv ++ ; 
  -- argc ; 
  if (cmdline_exe_hack [0 ] != '[' ) {
    int n , i ; 
    long d ; 
    GC_CAN_IGNORE unsigned char * p ; 
    GC_CAN_IGNORE unsigned char * orig_p ; 
    char * * argv2 ; 
    BLOCK_SETUP((PUSH(argv2, 0+XfOrM68_COUNT)));
#   define XfOrM178_COUNT (1+XfOrM68_COUNT)
#   define SETUP_XfOrM178(x) SETUP(XfOrM178_COUNT)
    argv2 = NULLED_OUT ; 
    p = (unsigned char * ) cmdline_exe_hack + 1 ; 
    orig_p = p ; 
    n = 0 ; 
    while (p [0 ] || p [1 ] || p [2 ] || p [3 ] ) {
      n ++ ; 
      p += (p [0 ] + (((long ) p [1 ] ) << 8 ) + (((long ) p [2 ] ) << 16 ) + (((long ) p [3 ] ) << 24 ) + 4 ) ; 
    }
    argv2 = (char * * ) FUNCCALL(SETUP_XfOrM178(_), malloc (sizeof (char * ) * (argc + n ) ) ); 
    p = orig_p ; 
    for (i = 0 ; i < n ; i ++ ) {
      d = (p [0 ] + (((long ) p [1 ] ) << 8 ) + (((long ) p [2 ] ) << 16 ) + (((long ) p [3 ] ) << 24 ) ) ; 
      argv2 [i ] = (char * ) p + 4 ; 
      p += d + 4 ; 
    }
    for (; i < n + argc ; i ++ ) {
      argv2 [i ] = argv [i - n ] ; 
    }
    argv = argv2 ; 
    argc += n ; 
  }
  evals_and_loads = (char * * ) FUNCCALL(SETUP_XfOrM68(_), malloc (sizeof (char * ) * argc ) ); 
  eval_kind = (int * ) FUNCCALL(SETUP_XfOrM68(_), malloc (sizeof (int ) * argc ) ); 
  num_enl = 0 ; 
  runner = FUNCCALL(SETUP_XfOrM68(_), check_script_runner (prog ) ); 
  if (runner ) {
#   define XfOrM176_COUNT (0+XfOrM68_COUNT)
#   define SETUP_XfOrM176(x) SETUP_XfOrM68(x)
    if (! argc ) {
#     define XfOrM177_COUNT (0+XfOrM176_COUNT)
#     define SETUP_XfOrM177(x) SETUP_XfOrM176(x)
      (printf ("%s: missing script filename to load\n" , prog ) ) ; 
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
    evals_and_loads [0 ] = runner ; 
    eval_kind [0 ] = 0 ; 
    evals_and_loads [1 ] = argv [0 ] ; 
    eval_kind [1 ] = 1 ; 
    evals_and_loads [2 ] = argv [0 ] ; 
    eval_kind [2 ] = 2 ; 
    num_enl = 3 ; 
    script_mode = 1 ; 
    no_more_switches = 1 ; 
    no_init_file = 1 ; 
    no_argv = 1 ; 
    argv ++ ; 
    -- argc ; 
  }
  while (! no_more_switches && argc && argv [0 ] [0 ] == '-' && ! FUNCCALL(SETUP_XfOrM68(_), is_number_arg (argv [0 ] + 1 ) )) {
#   define XfOrM128_COUNT (0+XfOrM68_COUNT)
#   define SETUP_XfOrM128(x) SETUP_XfOrM68(x)
    real_switch = argv [0 ] ; 
    if (! (strcmp ("--help" , argv [0 ] ) ) )
      argv [0 ] = "-h" ; 
    else if (! (strcmp ("--eval" , argv [0 ] ) ) )
      argv [0 ] = "-e" ; 
    else if (! (strcmp ("--load" , argv [0 ] ) ) )
      argv [0 ] = "-f" ; 
    else if (! (strcmp ("--load-cd" , argv [0 ] ) ) )
      argv [0 ] = "-d" ; 
    else if (! (strcmp ("--require" , argv [0 ] ) ) )
      argv [0 ] = "-t" ; 
    else if (! (strcmp ("--Load" , argv [0 ] ) ) )
      argv [0 ] = "-F" ; 
    else if (! (strcmp ("--Load-cd" , argv [0 ] ) ) )
      argv [0 ] = "-D" ; 
    else if (! (strcmp ("--Require" , argv [0 ] ) ) )
      argv [0 ] = "-T" ; 
    else if (! (strcmp ("--mzlib" , argv [0 ] ) ) )
      argv [0 ] = "-l" ; 
    else if (! (strcmp ("--case-sens" , argv [0 ] ) ) )
      argv [0 ] = "-g" ; 
    else if (! (strcmp ("--case-insens" , argv [0 ] ) ) )
      argv [0 ] = "-G" ; 
    else if (! (strcmp ("--set-undef" , argv [0 ] ) ) )
      argv [0 ] = "-s" ; 
    else if (! (strcmp ("--script" , argv [0 ] ) ) )
      argv [0 ] = "-r" ; 
    else if (! (strcmp ("--script-cd" , argv [0 ] ) ) )
      argv [0 ] = "-i" ; 
    else if (! (strcmp ("--require-script" , argv [0 ] ) ) )
      argv [0 ] = "-u" ; 
    else if (! (strcmp ("--main" , argv [0 ] ) ) )
      argv [0 ] = "-I" ; 
    else if (! (strcmp ("--name" , argv [0 ] ) ) )
      argv [0 ] = "-N" ; 
    else if (! (strcmp ("--no-lib-path" , argv [0 ] ) ) )
      argv [0 ] = "-x" ; 
    else if (! (strcmp ("--version" , argv [0 ] ) ) )
      argv [0 ] = "-v" ; 
    else if (! (strcmp ("--no-init-file" , argv [0 ] ) ) )
      argv [0 ] = "-q" ; 
    else if (! (strcmp ("--no-jit" , argv [0 ] ) ) )
      argv [0 ] = "-j" ; 
    else if (! (strcmp ("--no-argv" , argv [0 ] ) ) )
      argv [0 ] = "-A" ; 
    else if (! (strcmp ("--mute-banner" , argv [0 ] ) ) )
      argv [0 ] = "-m" ; 
    else if (! (strcmp ("--awk" , argv [0 ] ) ) )
      argv [0 ] = "-w" ; 
    else if (! (strcmp ("--binary" , argv [0 ] ) ) )
      argv [0 ] = "-b" ; 
    else if (! (strcmp ("--collects" , argv [0 ] ) ) )
      argv [0 ] = "-X" ; 
    else if (! (strcmp ("--search" , argv [0 ] ) ) )
      argv [0 ] = "-S" ; 
    else if (! (strcmp ("--prim" , argv [0 ] ) ) )
      argv [0 ] = "-Q" ; 
    else if (! (strcmp ("--restore" , argv [0 ] ) ) ) {
#     define XfOrM175_COUNT (0+XfOrM128_COUNT)
#     define SETUP_XfOrM175(x) SETUP_XfOrM128(x)
      (printf ("--restore or -R<file> must be the first (and only) switch\n" ) ) ; 
      goto show_need_help ; 
    }
    if (! argv [0 ] [1 ] || (argv [0 ] [1 ] == '-' && argv [0 ] [2 ] ) ) {
      goto bad_switch ; 
    }
    else {
      GC_CAN_IGNORE char * str ; 
      char * se ; 
      BLOCK_SETUP((PUSH(se, 0+XfOrM128_COUNT)));
#     define XfOrM129_COUNT (1+XfOrM128_COUNT)
#     define SETUP_XfOrM129(x) SETUP(XfOrM129_COUNT)
      se = NULLED_OUT ; 
      for (str = argv [0 ] + 1 ; * str ; str ++ ) {
#       define XfOrM152_COUNT (0+XfOrM129_COUNT)
#       define SETUP_XfOrM152(x) SETUP_XfOrM129(x)
        switch (* str ) {
#         define XfOrM153_COUNT (0+XfOrM152_COUNT)
#         define SETUP_XfOrM153(x) SETUP_XfOrM152(x)
          case 'h' : goto show_help ; 
          break ; 
          case 'g' : FUNCCALL(SETUP_XfOrM153(_), scheme_set_case_sensitive (1 ) ); 
          break ; 
          case 'G' : FUNCCALL(SETUP_XfOrM153(_), scheme_set_case_sensitive (0 ) ); 
          break ; 
          case 's' : FUNCCALL(SETUP_XfOrM153(_), scheme_set_allow_set_undefined (1 ) ); 
          break ; 
          case 'e' : if (argc < 2 ) {
#           define XfOrM173_COUNT (0+XfOrM153_COUNT)
#           define SETUP_XfOrM173(x) SETUP_XfOrM153(x)
            (printf ("%s: missing expression after %s switch\n" , prog , real_switch ) ) ; 
            goto show_need_help ; 
          }
          argv ++ ; 
          -- argc ; 
          evals_and_loads [num_enl ] = argv [0 ] ; 
          eval_kind [num_enl ++ ] = 0 ; 
          break ; 
          case 'X' : if (argc < 2 ) {
#           define XfOrM172_COUNT (0+XfOrM153_COUNT)
#           define SETUP_XfOrM172(x) SETUP_XfOrM153(x)
            (printf ("%s: missing path after %s switch\n" , prog , real_switch ) ) ; 
            goto show_need_help ; 
          }
          argv ++ ; 
          -- argc ; 
          collects_path = FUNCCALL(SETUP_XfOrM153(_), scheme_make_path (argv [0 ] ) ); 
          break ; 
          case 'U' : FUNCCALL(SETUP_XfOrM153(_), scheme_set_ignore_user_paths (1 ) ); 
          break ; 
          case 'S' : if (argc < 2 ) {
#           define XfOrM171_COUNT (0+XfOrM153_COUNT)
#           define SETUP_XfOrM171(x) SETUP_XfOrM153(x)
            (printf ("%s: missing path after %s switch\n" , prog , real_switch ) ) ; 
            goto show_need_help ; 
          }
          argv ++ ; 
          -- argc ; 
          if (! collects_extra )
            collects_extra = FUNCCALL(SETUP_XfOrM153(_), scheme_make_null () ); 
          collects_extra = (__funcarg39 = FUNCCALL(SETUP_XfOrM153(_), scheme_make_path (argv [0 ] ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg39 , collects_extra ) )) ; 
          break ; 
          case 'x' : no_lib_path = 1 ; 
          break ; 
          case 'C' : case 'r' : script_mode = 1 ; 
          no_more_switches = 1 ; 
          case 'f' : if (argc < 2 ) {
#           define XfOrM170_COUNT (0+XfOrM153_COUNT)
#           define SETUP_XfOrM170(x) SETUP_XfOrM153(x)
            (printf ("%s: missing file name after %s switch\n" , prog , real_switch ) ) ; 
            goto show_need_help ; 
          }
          argv ++ ; 
          -- argc ; 
          evals_and_loads [num_enl ] = argv [0 ] ; 
          eval_kind [num_enl ++ ] = 1 ; 
          if (* str == 'C' ) {
            evals_and_loads [num_enl ] = argv [0 ] ; 
            eval_kind [num_enl ++ ] = 2 ; 
          }
          break ; 
          case 'i' : script_mode = 1 ; 
          no_more_switches = 1 ; 
          case 'd' : if (argc < 2 ) {
#           define XfOrM168_COUNT (0+XfOrM153_COUNT)
#           define SETUP_XfOrM168(x) SETUP_XfOrM153(x)
            (printf ("%s: missing file name after %s switch\n" , prog , real_switch ) ) ; 
            goto show_need_help ; 
          }
          argv ++ ; 
          -- argc ; 
          se = FUNCCALL(SETUP_XfOrM153(_), make_load_cd (argv [0 ] ) ); 
          evals_and_loads [num_enl ] = se ; 
          eval_kind [num_enl ++ ] = 0 ; 
          break ; 
          case 'u' : script_mode = 1 ; 
          no_more_switches = 1 ; 
          case 't' : if (argc < 2 ) {
#           define XfOrM167_COUNT (0+XfOrM153_COUNT)
#           define SETUP_XfOrM167(x) SETUP_XfOrM153(x)
            (printf ("%s: missing file name after %s switch\n" , prog , real_switch ) ) ; 
            goto show_need_help ; 
          }
          argv ++ ; 
          -- argc ; 
          se = FUNCCALL(SETUP_XfOrM153(_), make_require (argv [0 ] ) ); 
          evals_and_loads [num_enl ] = se ; 
          eval_kind [num_enl ++ ] = 0 ; 
          break ; 
          case 'F' : while (argc > 1 ) {
            argv ++ ; 
            -- argc ; 
            evals_and_loads [num_enl ] = argv [0 ] ; 
            eval_kind [num_enl ++ ] = 1 ; 
          }
          break ; 
          case 'D' : while (argc > 1 ) {
            argv ++ ; 
#           define XfOrM164_COUNT (0+XfOrM153_COUNT)
#           define SETUP_XfOrM164(x) SETUP_XfOrM153(x)
            -- argc ; 
            se = FUNCCALL(SETUP_XfOrM164(_), make_load_cd (argv [0 ] ) ); 
            evals_and_loads [num_enl ] = se ; 
            eval_kind [num_enl ++ ] = 0 ; 
          }
          break ; 
          case 'T' : while (argc > 1 ) {
            argv ++ ; 
#           define XfOrM162_COUNT (0+XfOrM153_COUNT)
#           define SETUP_XfOrM162(x) SETUP_XfOrM153(x)
            -- argc ; 
            se = FUNCCALL(SETUP_XfOrM162(_), make_require (argv [0 ] ) ); 
            evals_and_loads [num_enl ] = se ; 
            eval_kind [num_enl ++ ] = 0 ; 
          }
          break ; 
          case 'l' : if (argc < 2 ) {
#           define XfOrM160_COUNT (0+XfOrM153_COUNT)
#           define SETUP_XfOrM160(x) SETUP_XfOrM153(x)
            (printf ("%s: missing file after %s switch\n" , prog , real_switch ) ) ; 
            goto show_need_help ; 
          }
          argv ++ ; 
          -- argc ; 
          se = FUNCCALL(SETUP_XfOrM153(_), make_require_lib (argv [0 ] , "mzlib" ) ); 
          evals_and_loads [num_enl ] = se ; 
          eval_kind [num_enl ++ ] = 0 ; 
          break ; 
          case 'L' : if (argc < 3 ) {
#           define XfOrM159_COUNT (0+XfOrM153_COUNT)
#           define SETUP_XfOrM159(x) SETUP_XfOrM153(x)
            (printf ("%s: missing %s after %s switch\n" , prog , (argc < 2 ) ? "file and collection" : "collection" , real_switch ) ) ; 
            goto show_need_help ; 
          }
          argv ++ ; 
          -- argc ; 
          se = FUNCCALL(SETUP_XfOrM153(_), make_require_lib (argv [0 ] , argv [1 ] ) ); 
          evals_and_loads [num_enl ] = se ; 
          argv ++ ; 
          -- argc ; 
          eval_kind [num_enl ++ ] = 0 ; 
          break ; 
          case 'M' : if (argc < 2 ) {
#           define XfOrM158_COUNT (0+XfOrM153_COUNT)
#           define SETUP_XfOrM158(x) SETUP_XfOrM153(x)
            (printf ("%s: missing collection after %s switch\n" , prog , real_switch ) ) ; 
            goto show_need_help ; 
          }
          argv ++ ; 
          -- argc ; 
          se = FUNCCALL(SETUP_XfOrM153(_), make_require_coll (argv [0 ] ) ); 
          evals_and_loads [num_enl ] = se ; 
          eval_kind [num_enl ++ ] = 0 ; 
          break ; 
          case 'p' : if (argc < 4 ) {
#           define XfOrM157_COUNT (0+XfOrM153_COUNT)
#           define SETUP_XfOrM157(x) SETUP_XfOrM153(x)
            (printf ("%s: missing %s after %s switch\n" , prog , ((argc > 2 ) ? "package" : ((argc > 1 ) ? "user and package" : "file, user, and package" ) ) , real_switch ) ) ; 
            goto show_need_help ; 
          }
          argv ++ ; 
          -- argc ; 
          se = FUNCCALL(SETUP_XfOrM153(_), make_require_planet (argv [0 ] , "" , argv [1 ] , argv [2 ] , "" ) ); 
          evals_and_loads [num_enl ] = se ; 
          argv += 2 ; 
          argc -= 2 ; 
          eval_kind [num_enl ++ ] = 0 ; 
          break ; 
          case 'P' : if (argc < 3 ) {
#           define XfOrM156_COUNT (0+XfOrM153_COUNT)
#           define SETUP_XfOrM156(x) SETUP_XfOrM153(x)
            (printf ("%s: missing %s after %s switch\n" , prog , (argc < 2 ) ? "package/file base name and user" : "package" , real_switch ) ) ; 
            goto show_need_help ; 
          }
          argv ++ ; 
          -- argc ; 
          se = FUNCCALL(SETUP_XfOrM153(_), make_require_planet (argv [0 ] , ".ss" , argv [1 ] , argv [0 ] , ".plt" ) ); 
          evals_and_loads [num_enl ] = se ; 
          argv ++ ; 
          -- argc ; 
          eval_kind [num_enl ++ ] = 0 ; 
          break ; 
          case 'Q' : start_with_req = 1 ; 
          break ; 
          case 'w' : se = FUNCCALL(SETUP_XfOrM153(_), make_require_lib ("awk.ss" , "mzlib" ) ); 
          evals_and_loads [num_enl ] = se ; 
          eval_kind [num_enl ++ ] = 0 ; 
          break ; 
          case 'k' : if (argc < 3 ) {
#           define XfOrM155_COUNT (0+XfOrM153_COUNT)
#           define SETUP_XfOrM155(x) SETUP_XfOrM153(x)
            (printf ("%s: missing %s after %s switch\n" , prog , (argc < 2 ) ? "starting and ending offsets" : "ending offset" , real_switch ) ) ; 
            goto show_need_help ; 
          }
          argv ++ ; 
          -- argc ; 
          se = FUNCCALL(SETUP_XfOrM153(_), make_embedded_load (argv [0 ] , argv [1 ] ) ); 
          evals_and_loads [num_enl ] = se ; 
          argv ++ ; 
          -- argc ; 
          eval_kind [num_enl ++ ] = 0 ; 
          break ; 
          case 'N' : if (argc < 2 ) {
#           define XfOrM154_COUNT (0+XfOrM153_COUNT)
#           define SETUP_XfOrM154(x) SETUP_XfOrM153(x)
            (printf ("%s: missing name after %s switch\n" , prog , real_switch ) ) ; 
            goto show_need_help ; 
          }
          argv ++ ; 
          -- argc ; 
          sprog = argv [0 ] ; 
          break ; 
          case 'A' : no_argv = 1 ; 
          break ; 
          case 'q' : no_init_file = 1 ; 
          break ; 
          case 'v' : no_rep = 1 ; 
          break ; 
          case 'm' : mute_banner = 1 ; 
          break ; 
          case '-' : no_more_switches = 1 ; 
          break ; 
          case 'j' : FUNCCALL(SETUP_XfOrM153(_), scheme_set_startup_use_jit (0 ) ); 
          break ; 
          case 'b' : FUNCCALL(SETUP_XfOrM153(_), scheme_set_binary_mode_stdio (1 ) ); 
          break ; 
          case 'R' : (printf ("--restore or -R<file> must be the first (and only) switch\n" ) ) ; 
          goto show_need_help ; 
          break ; 
          default : goto bad_switch ; 
        }
      }
    }
    argv ++ ; 
    -- argc ; 
  }
  if (! script_mode && ! mute_banner ) {
#   define XfOrM79_COUNT (0+XfOrM68_COUNT)
#   define SETUP_XfOrM79(x) SETUP_XfOrM68(x)
    (__funcarg35 = FUNCCALL(SETUP_XfOrM79(_), scheme_banner () ), (printf (__funcarg35 ) ) ) ; 
    if (FUNCCALL(SETUP_XfOrM79(_), scheme_get_allow_set_undefined () ))
      (printf ("Set! works on undefined identifiers" ".\n" ) ) ; 
    FUNCCALL(SETUP_XfOrM79(_), fflush (stdout ) ); 
  }
  global_env = FUNCCALL(SETUP_XfOrM68(_), mk_basic_env () ); 
  sch_argv = FUNCCALL(SETUP_XfOrM68(_), scheme_make_vector (argc , ((void * ) 0 ) ) ); 
  for (i = 0 ; i < argc ; i ++ ) {
    Scheme_Object * so ; 
    BLOCK_SETUP((PUSH(so, 0+XfOrM68_COUNT)));
#   define XfOrM78_COUNT (1+XfOrM68_COUNT)
#   define SETUP_XfOrM78(x) SETUP(XfOrM78_COUNT)
    so = NULLED_OUT ; 
    so = FUNCCALL(SETUP_XfOrM78(_), scheme_make_locale_string (argv [i ] ) ); 
    ((((Scheme_Inclhash_Object * ) (so ) ) -> so . keyex |= 0x1 ) ) ; 
    (((Scheme_Vector * ) (sch_argv ) ) -> els ) [i ] = so ; 
  }
  if (argc )
    ((((Scheme_Inclhash_Object * ) (sch_argv ) ) -> so . keyex |= 0x1 ) ) ; 
  (__funcarg34 = FUNCCALL(SETUP_XfOrM68(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_set_param (__funcarg34 , MZCONFIG_CMDLINE_ARGS , sch_argv ) )) ; 
  if (! no_argv )
    FUNCCALL(SETUP_XfOrM68(_), scheme_add_global ("argv" , sch_argv , global_env ) ); 
  {
    Scheme_Object * ps ; 
    BLOCK_SETUP((PUSH(ps, 0+XfOrM68_COUNT)));
#   define XfOrM76_COUNT (1+XfOrM68_COUNT)
#   define SETUP_XfOrM76(x) SETUP(XfOrM76_COUNT)
    ps = NULLED_OUT ; 
    FUNCCALL(SETUP_XfOrM76(_), scheme_set_exec_cmd (prog ) ); 
    if (! sprog )
      sprog = prog ; 
    ps = FUNCCALL(SETUP_XfOrM76(_), scheme_set_run_cmd (sprog ) ); 
    if (! no_argv )
      FUNCCALL(SETUP_XfOrM76(_), scheme_add_global ("program" , ps , global_env ) ); 
  }
  if (! no_lib_path ) {
    Scheme_Object * l , * r ; 
    int len , offset ; 
    BLOCK_SETUP((PUSH(r, 0+XfOrM68_COUNT), PUSH(l, 1+XfOrM68_COUNT)));
#   define XfOrM69_COUNT (2+XfOrM68_COUNT)
#   define SETUP_XfOrM69(x) SETUP(XfOrM69_COUNT)
    l = NULLED_OUT ; 
    r = NULLED_OUT ; 
    if (! collects_path )
      collects_path = FUNCCALL(SETUP_XfOrM69(_), scheme_make_path (_coldir XFORM_OK_PLUS _coldir_offset ) ); 
    FUNCCALL(SETUP_XfOrM69(_), scheme_set_collects_path (collects_path ) ); 
    if (collects_extra ) {
      l = collects_extra ; 
    }
    else {
#     define XfOrM72_COUNT (0+XfOrM69_COUNT)
#     define SETUP_XfOrM72(x) SETUP_XfOrM69(x)
      l = FUNCCALL(SETUP_XfOrM72(_), scheme_make_null () ); 
      offset = _coldir_offset ; 
      while (1 ) {
#       define XfOrM74_COUNT (0+XfOrM72_COUNT)
#       define SETUP_XfOrM74(x) SETUP_XfOrM72(x)
        len = strlen (_coldir XFORM_OK_PLUS offset ) ; 
        offset += len + 1 ; 
        if (! _coldir [offset ] )
          break ; 
        l = (__funcarg33 = FUNCCALL(SETUP_XfOrM74(_), scheme_make_path (_coldir XFORM_OK_PLUS offset ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg33 , l ) )) ; 
      }
    }
    r = FUNCCALL(SETUP_XfOrM69(_), scheme_make_null () ); 
    while (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#     define XfOrM71_COUNT (0+XfOrM69_COUNT)
#     define SETUP_XfOrM71(x) SETUP_XfOrM69(x)
      r = FUNCCALL(SETUP_XfOrM71(_), scheme_make_pair ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) , r ) ); 
      l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
    }
    FUNCCALL(SETUP_XfOrM69(_), init_collection_paths (global_env , r ) ); 
  }
  fa_a = (FinishArgsAtoms * ) FUNCCALL(SETUP_XfOrM68(_), GC_malloc_atomic (sizeof (FinishArgsAtoms ) ) ); 
  fa = (FinishArgs * ) FUNCCALL(SETUP_XfOrM68(_), GC_malloc (sizeof (FinishArgs ) ) ); 
  fa -> a = fa_a ; 
  fa -> a -> start_with_req = start_with_req ; 
  fa -> evals_and_loads = evals_and_loads ; 
  fa -> eval_kind = eval_kind ; 
  fa -> a -> num_enl = num_enl ; 
  fa -> main_args = sch_argv ; 
  fa -> a -> no_init_file = no_init_file ; 
  fa -> a -> no_rep = no_rep ; 
  fa -> a -> script_mode = script_mode ; 
  fa -> global_env = global_env ; 
  FUNCCALL(SETUP_XfOrM68(_), scheme_set_can_break (1 ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(cont_run (fa ) )) RET_VALUE_EMPTY_END ; 
  show_help : prog = ("%s" "mzscheme" " [<option> ...] <argument> ...\n" " Startup file and expression options:\n" "  -e <expr>, --eval <expr> : Evaluates <expr> after " "MzScheme" " starts\n" "  -f <file>, --load <file> : Loads <file> after " "MzScheme" " starts\n" "  -d <file>, --load-cd <file> : Load/cds <file> after " "MzScheme" " starts\n" "  -t <file>, --require <file> : Requires <file> after " "MzScheme" " starts\n" "  -F, --Load : Loads all remaining arguments after " "MzScheme" " starts\n" "  -D, --Load-cd : Load/cds all remaining arguments after " "MzScheme" " starts\n" "  -T, --Require : Requires all remaining arguments after " "MzScheme" " starts\n" "  -l <file>, --mzlib <file> : Same as -e '(require (lib \"<file>\"))'\n" "  -L <file> <coll> : Same as -e '(require (lib \"<file>\" \"<coll>\"))'\n" "  -M <coll> : Same as -e '(require (lib \"<coll>.ss\" \"<coll>\"))'\n" "  -p <fl> <u> <pkg> : Same as -e '(require (planet \"<fl>\" (\"<u>\" \"<pkg>\"))'\n" "  -P <nm> <u> : Same as -e '(require (planet \"<nm>.ss\" (\"<u>\" \"<nm>.plt\"))'\n" "  -r, --script : Script mode: use as last option for scripts; same as -fmv-\n" "  -i, --script-cd : Like -r, but also sets the directory; same as -dmv-\n" "  -u, --require-script : Like -r, but requires a module; same as -tmv-\n" "  -w, --awk : Same as -l awk.ss\n" "  -k <n> <m> : Load executable-embedded code from file offset <n> to <m>\n" "  -C, --main : Like -r, then call `main' w/argument list; car is file name\n" " Initialization options:\n" "  -X <dir>, --collects <dir> : Main collects at <dir> relative to " "MzScheme" "\n" "  -S <dir>, --search <dir> : More collects at <dir> relative to " "MzScheme" "\n" "  -U, --no-user-path : Ignores user-specific collects, etc.\n" "  -x, --no-lib-path : Skips trying to set current-library-collection-paths\n" "  -q, --no-init-file : Skips trying to load " "~/.mzschemerc" "\n" "  -N <file>, --name <file> : Sets `program' to <file>\n" "  -A : Skips defining `argv' and `program'\n" "  -j, --no-jit : Disables just-in-time compiler\n" " Language setting options:\n" "  -Q, --prim : Assume primitive bindings at top level\n" "  -g, --case-sens : Identifiers/symbols are initially case-sensitive\n" "  -G, --case-insens : Identifiers/symbols are initially case-insensitive\n" "  -s, --set-undef : " "Set! works on undefined identifiers" "\n" " Miscellaneous options:\n" "  -- : No argument following this switch is used as a switch\n" "  -m, --mute-banner : Suppresses " "the startup banner" " text\n" "  -v, --version : Suppresses the read-eval-print loop" "\n" "  -b, --binary : Read stdin and write stdout/stderr in binary mode\n" "  -h, --help : Shows this information and exits, ignoring other options\n" "Multiple single-letter switches can be collapsed, with arguments placed\n" " after the collapsed switches; the first collapsed switch cannot be --.\n" " E.g.: `-vfme file expr' is the same as `-v -f file -m -e expr'\n" "Extra arguments following the last option are put into the Scheme global\n" " variable `argv' as a vector of strings. The name used to start " "MzScheme" "\n" " is put into the global variable `program' as a string.\n" "Expressions/files/--main/etc. are evaluated/loaded in order as provided.\n" " An error during evaluation/loading causes later ones to be skipped.\n" "The current-library-collection-paths is automatically set before any\n" " expressions/files are evaluated/loaded, unless the -x or --no-lib-path\n" " option is used.\n" "The file " "~/.mzschemerc" " is loaded before any provided expressions/files\n" " are evaluated/loaded, unless the -q or --no-init-file option is used.\n" "If the executable name has the form scheme-<dialect>, then the command\n" " line is effectively prefixed with:\n" "    -qAeC '(require (lib \"init.ss\" \"script-lang\" \"<dialect>\"))'\n" " Thus, the first command-line argument serves as the name of a file;\n" " the file should define `main', which is called with the arguments in a\n" " list, starting with the path of the loaded file.\n" "For general information about " "MzScheme" ", see:\n" "  http://www.plt-scheme.org/software/" "mzscheme" "/\n" ) ; 
  (__funcarg31 = FUNCCALL(SETUP_XfOrM68(_), scheme_banner () ), (printf (prog , __funcarg31 ) ) ) ; 
  RET_VALUE_START (0 ) RET_VALUE_END ; 
  bad_switch : (printf ("%s: bad switch %s\n" , prog , real_switch ) ) ; 
  show_need_help : (printf ("Use the --help or -h flag for help.\n" ) ) ; 
  RET_VALUE_START (1 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void user_break_hit (int ignore ) {
  /* No conversion */
  scheme_break_thread (((void * ) 0 ) ) ; 
  scheme_signal_received () ; 
  signal (2 , user_break_hit ) ; 
}
static void do_scheme_rep (Scheme_Env * ) ; 
static int cont_run (FinishArgs * f ) ; 
int actual_main (int argc , char * argv [] ) ; 
static int main_after_dlls (int argc , char * * argv ) ; 
int main (int argc , char * * argv ) {
  return main_after_dlls (argc , argv ) ; 
}
static int main_after_dlls (int argc , char * * argv ) {
  void * stack_start ; 
  int rval ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(stack_start, 0), PUSH(argv, 1)));
# define XfOrM186_COUNT (2)
# define SETUP_XfOrM186(x) SETUP(XfOrM186_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  stack_start = NULLED_OUT ; 
  stack_start = (void * ) & stack_start ; 
  stack_start = (void * ) & __gc_var_stack__ ; 
  FUNCCALL(SETUP_XfOrM186(_), scheme_set_stack_base (stack_start , 1 ) ); 
  FUNCCALL_AGAIN(scheme_set_actual_main (actual_main ) ); 
  rval = FUNCCALL_AGAIN(scheme_image_main (argc , argv ) ); 
  argv = ((void * ) 0 ) ; 
  RET_VALUE_START (rval ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int actual_main (int argc , char * argv [] ) {
  int exit_val ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM187_COUNT (1)
# define SETUP_XfOrM187(x) SETUP(XfOrM187_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM187(_), signal (2 , user_break_hit ) ); 
  exit_val = FUNCCALL_EMPTY(run_from_cmd_line (argc , argv , scheme_basic_env , cont_run ) ); 
  FUNCCALL_EMPTY(scheme_immediate_exit (exit_val ) ); 
  RET_VALUE_START (exit_val ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int cont_run (FinishArgs * f ) {
  /* No conversion */
  return finish_cmd_line_run (f , do_scheme_rep ) ; 
}
static void do_scheme_rep (Scheme_Env * env ) {
  PREPARE_VAR_STACK(1);
# define XfOrM189_COUNT (0)
# define SETUP_XfOrM189(x) SETUP(XfOrM189_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  {
    Scheme_Object * rep ; 
    BLOCK_SETUP((PUSH(rep, 0+XfOrM189_COUNT)));
#   define XfOrM190_COUNT (1+XfOrM189_COUNT)
#   define SETUP_XfOrM190(x) SETUP(XfOrM190_COUNT)
    rep = NULLED_OUT ; 
    rep = FUNCCALL(SETUP_XfOrM190(_), scheme_builtin_value ("read-eval-print-loop" ) ); 
    if (rep ) {
#     define XfOrM191_COUNT (0+XfOrM190_COUNT)
#     define SETUP_XfOrM191(x) SETUP_XfOrM190(x)
      FUNCCALL_EMPTY(scheme_apply (rep , 0 , ((void * ) 0 ) ) ); 
      (printf ("\n" ) ) ; 
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
