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
typedef int (* __compar_fn_t ) (__const void * , __const void * ) ; 
extern void * memcpy (void * __restrict __dest , __const void * __restrict __src , size_t __n ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern void * memmove (void * __dest , __const void * __src , size_t __n ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern void * memset (void * __s , int __c , size_t __n ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern int strcmp (__const char * __s1 , __const char * __s2 ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__pure__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
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
extern void * GC_malloc_weak_box (void * p , void * * secondary , int soffset ) ; 
extern void * * GC_malloc_immobile_box (void * p ) ; 
extern void GC_free_immobile_box (void * * b ) ; 
typedef void (* GC_finalization_proc ) (void * p , void * data ) ; 
extern void * * GC_variable_stack ; 
extern void * * GC_get_variable_stack () ; 
extern void GC_set_variable_stack (void * * p ) ; 
extern void GC_register_traversers (short tag , Size_Proc size , Mark_Proc mark , Fixup_Proc fixup , int is_constant_size , int is_atomic ) ; 
extern void * GC_resolve (void * p ) ; 
extern void GC_mark (const void * p ) ; 
extern void GC_fixup (void * p ) ; 
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
extern int (* scheme_actual_main ) (int argc , char * * argv ) ; 
extern void scheme_register_static (void * ptr , long size ) ; 
extern void (* scheme_on_atomic_timeout ) (void ) ; 
extern Scheme_Thread * scheme_current_thread ; 
extern volatile int scheme_fuel_counter ; 
extern void scheme_signal_error (const char * msg , ... ) ; 
extern void scheme_raise_exn (int exnid , ... ) ; 
extern void scheme_wrong_type (const char * name , const char * expected , int which , int argc , Scheme_Object * * argv ) ; 
extern void scheme_arg_mismatch (const char * name , const char * msg , Scheme_Object * o ) ; 
extern Scheme_Type scheme_make_type (const char * name ) ; 
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
extern Scheme_Object * scheme_do_eval (Scheme_Object * obj , int _num_rands , Scheme_Object * * rands , int val ) ; 
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
extern void * scheme_malloc_fail_ok (void * (* f ) (size_t ) , size_t ) ; 
extern void scheme_register_finalizer (void * p , void (* f ) (void * p , void * data ) , void * data , void (* * oldf ) (void * p , void * data ) , void * * olddata ) ; 
extern void * * GC_variable_stack ; 
extern void GC_register_traversers (short tag , Size_Proc size , Mark_Proc mark , Fixup_Proc fixup , int is_constant_size , int is_atomic ) ; 
extern void * GC_resolve (void * p ) ; 
extern void GC_mark (const void * p ) ; 
extern void GC_fixup (void * p ) ; 
extern void * * scheme_malloc_immobile_box (void * p ) ; 
extern void scheme_free_immobile_box (void * * b ) ; 
extern Scheme_Hash_Table * scheme_make_hash_table (int type ) ; 
extern void scheme_hash_set (Scheme_Hash_Table * table , Scheme_Object * key , Scheme_Object * val ) ; 
extern Scheme_Object * scheme_hash_get (Scheme_Hash_Table * table , Scheme_Object * key ) ; 
extern Scheme_Object * scheme_make_prim_w_arity (Scheme_Prim * prim , const char * name , mzshort mina , mzshort maxa ) ; 
extern Scheme_Object * scheme_make_closed_prim_w_arity (Scheme_Closed_Prim * prim , void * data , const char * name , mzshort mina , mzshort maxa ) ; 
extern Scheme_Object * scheme_make_byte_string (const char * chars ) ; 
extern Scheme_Object * scheme_make_sized_byte_string (char * chars , long len , int copy ) ; 
extern Scheme_Object * scheme_make_byte_string_without_copying (char * chars ) ; 
extern Scheme_Object * scheme_append_byte_string (Scheme_Object * , Scheme_Object * ) ; 
extern Scheme_Object * scheme_char_string_to_path (Scheme_Object * p ) ; 
extern Scheme_Object * scheme_make_sized_char_string (mzchar * chars , long len , int copy ) ; 
extern Scheme_Object * scheme_make_char_string_without_copying (mzchar * chars ) ; 
extern Scheme_Object * scheme_make_vector (int size , Scheme_Object * fill ) ; 
extern Scheme_Object * scheme_make_integer_value (long i ) ; 
extern Scheme_Object * scheme_make_integer_value_from_long_long (mzlonglong i ) ; 
extern Scheme_Object * scheme_make_integer_value_from_unsigned_long_long (umzlonglong i ) ; 
extern Scheme_Object * scheme_make_double (double d ) ; 
__xform_nongcing__ extern int scheme_get_int_val (Scheme_Object * o , long * v ) ; 
__xform_nongcing__ extern int scheme_get_long_long_val (Scheme_Object * o , mzlonglong * v ) ; 
__xform_nongcing__ extern int scheme_get_unsigned_long_long_val (Scheme_Object * o , umzlonglong * v ) ; 
__xform_nongcing__ extern double scheme_real_to_double (Scheme_Object * r ) ; 
extern Scheme_Object * scheme_make_cptr (void * cptr , Scheme_Object * typetag ) ; 
extern Scheme_Object * scheme_make_offset_cptr (void * cptr , long offset , Scheme_Object * typetag ) ; 
extern unsigned short * scheme_ucs4_to_utf16 (const mzchar * text , int start , int end , unsigned short * buf , int bufsize , long * ulen , int term_size ) ; 
extern mzchar * scheme_utf16_to_ucs4 (const unsigned short * text , int start , int end , mzchar * buf , int bufsize , long * ulen , int term_size ) ; 
extern Scheme_Object * scheme_make_path_without_copying (char * chars ) ; 
extern void scheme_require_from_original_env (Scheme_Env * env , int syntax_only ) ; 
extern void scheme_add_global (const char * name , Scheme_Object * val , Scheme_Env * env ) ; 
extern Scheme_Env * scheme_primitive_module (Scheme_Object * name , Scheme_Env * for_env ) ; 
extern void scheme_finish_primitive_module (Scheme_Env * env ) ; 
extern void scheme_protect_primitive_provide (Scheme_Env * env , Scheme_Object * name ) ; 
extern Scheme_Object * scheme_intern_symbol (const char * name ) ; 
__xform_nongcing__ extern long scheme_hash_key (Scheme_Object * o ) ; 
extern int scheme_proper_list_length (Scheme_Object * list ) ; 
extern char * scheme_make_args_string (char * s , int which , int argc , Scheme_Object * * argv , long * len ) ; 
long scheme_hash_key (Scheme_Object * o ) ; 
typedef int (* Compare_Proc ) (void * v1 , void * v2 ) ; 
void scheme_init_foreign (Scheme_Env * env ) ; 
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
typedef struct {
  Scheme_Object so ; 
  double x10 , x11 , x12 , x20 , x21 , x22 ; 
}
Scheme_Random_State ; 
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
char * scheme_make_args_string (char * s , int which , int argc , Scheme_Object * * argv , long * olen ) ; 
typedef struct {
  Scheme_Type type ; 
  Scheme_Object * syms [5 ] ; 
  int count ; 
  long phase ; 
  Scheme_Hash_Table * ht ; 
}
DupCheckRecord ; 
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
unsigned short * scheme_ucs4_to_utf16 (const mzchar * text , int start , int end , unsigned short * buf , int bufsize , long * ulen , int term_size ) ; 
extern void * dlopen (__const char * __file , int __mode ) __attribute__ ((__nothrow__ ) ) ; 
extern void * dlsym (void * __restrict __handle , __const char * __restrict __name ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (2 ) ) ) ; 
extern char * dlerror (void ) __attribute__ ((__nothrow__ ) ) ; 
typedef signed char Tsint8 ; 
typedef unsigned char Tuint8 ; 
typedef signed short Tsint16 ; 
typedef unsigned short Tuint16 ; 
typedef signed int Tsint32 ; 
typedef unsigned int Tuint32 ; 
typedef signed long Tsint64 ; 
typedef unsigned long Tuint64 ; 
typedef unsigned long ffi_arg ; 
typedef signed long ffi_sarg ; 
typedef enum ffi_abi {
  FFI_FIRST_ABI = 0 , FFI_SYSV , FFI_UNIX64 , FFI_DEFAULT_ABI = FFI_UNIX64 , FFI_LAST_ABI = FFI_DEFAULT_ABI + 1 }
ffi_abi ; 
typedef struct _ffi_type {
  size_t size ; 
  unsigned short alignment ; 
  unsigned short type ; 
  struct _ffi_type * * elements ; 
}
ffi_type ; 
extern ffi_type ffi_type_void ; 
extern ffi_type ffi_type_uint8 ; 
extern ffi_type ffi_type_sint8 ; 
extern ffi_type ffi_type_uint16 ; 
extern ffi_type ffi_type_sint16 ; 
extern ffi_type ffi_type_uint32 ; 
extern ffi_type ffi_type_sint32 ; 
extern ffi_type ffi_type_uint64 ; 
extern ffi_type ffi_type_sint64 ; 
extern ffi_type ffi_type_float ; 
extern ffi_type ffi_type_double ; 
extern ffi_type ffi_type_pointer ; 
typedef enum {
  FFI_OK = 0 , FFI_BAD_TYPEDEF , FFI_BAD_ABI }
ffi_status ; 
typedef struct {
  ffi_abi abi ; 
  unsigned nargs ; 
  ffi_type * * arg_types ; 
  ffi_type * rtype ; 
  unsigned bytes ; 
  unsigned flags ; 
}
ffi_cif ; 
typedef union {
  ffi_sarg sint ; 
  ffi_arg uint ; 
  float flt ; 
  char data [8 ] ; 
  void * ptr ; 
}
ffi_raw ; 
typedef struct {
  char tramp [24 ] ; 
  ffi_cif * cif ; 
  void (* fun ) (ffi_cif * , void * , void * * , void * ) ; 
  void * user_data ; 
}
ffi_closure __attribute__ ((aligned (8 ) ) ) ; 
ffi_status ffi_prep_closure (ffi_closure * , ffi_cif * , void (* fun ) (ffi_cif * , void * , void * * , void * ) , void * user_data ) ; 
typedef struct {
  char tramp [24 ] ; 
  ffi_cif * cif ; 
  void (* translate_args ) (ffi_cif * , void * , void * * , void * ) ; 
  void * this_closure ; 
  void (* fun ) (ffi_cif * , void * , ffi_raw * , void * ) ; 
  void * user_data ; 
}
ffi_raw_closure ; 
ffi_status ffi_prep_cif (ffi_cif * cif , ffi_abi abi , unsigned int nargs , ffi_type * rtype , ffi_type * * atypes ) ; 
void ffi_call (ffi_cif * cif , void (* fn ) () , void * rvalue , void * * avalue ) ; 
static Scheme_Type ffi_lib_tag ; 
typedef struct ffi_lib_struct {
  Scheme_Object so ; 
  void * handle ; 
  Scheme_Object * name ; 
  Scheme_Hash_Table * objects ; 
}
ffi_lib_struct ; 
static Scheme_Object * foreign_ffi_lib_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ffi_lib_tag ) ? scheme_true : scheme_false ; 
}
int ffi_lib_SIZE (void * p ) {
  return ((sizeof (ffi_lib_struct ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
int ffi_lib_MARK (void * p ) {
  ffi_lib_struct * s = (ffi_lib_struct * ) p ; 
  GC_mark (s -> handle ) ; 
  GC_mark (s -> name ) ; 
  GC_mark (s -> objects ) ; 
  return ((sizeof (ffi_lib_struct ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
int ffi_lib_FIXUP (void * p ) {
  ffi_lib_struct * s = (ffi_lib_struct * ) p ; 
  GC_fixup (& (s -> handle ) ) ; 
  GC_fixup (& (s -> name ) ) ; 
  GC_fixup (& (s -> objects ) ) ; 
  return ((sizeof (ffi_lib_struct ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static Scheme_Hash_Table * opened_libs ; 
static Scheme_Object * foreign_ffi_lib (int argc , Scheme_Object * argv [] ) {
  char * name ; 
  Scheme_Object * path , * hashname ; 
  void * handle ; 
  int null_ok = 0 ; 
  ffi_lib_struct * lib ; 
  char * __funcarg50 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(lib, 0), PUSH(name, 1), PUSH(handle, 2), PUSH(hashname, 3), PUSH(argv, 4), PUSH(path, 5)));
# define XfOrM2_COUNT (6)
# define SETUP_XfOrM2(x) SETUP(XfOrM2_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  name = NULLED_OUT ; 
  path = NULLED_OUT ; 
  hashname = NULLED_OUT ; 
  handle = NULLED_OUT ; 
  lib = NULLED_OUT ; 
  if (! ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) || (((argv [0 ] ) ) == (scheme_false ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("ffi-lib" , "string-or-false" , 0 , argc , argv ) ); 
  path = (((argv [0 ] ) ) == (scheme_false ) ) ? ((void * ) 0 ) : (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ? (argv [0 ] ) : FUNCCALL(SETUP_XfOrM2(_), scheme_char_string_to_path (argv [0 ] ) )) ; 
  name = (path == ((void * ) 0 ) ) ? ((void * ) 0 ) : (((Scheme_Simple_Object * ) (path ) ) -> u . byte_str_val . string_val ) ; 
  hashname = (Scheme_Object * ) ((name == ((void * ) 0 ) ) ? "" : name ) ; 
  lib = (ffi_lib_struct * ) FUNCCALL(SETUP_XfOrM2(_), scheme_hash_get (opened_libs , hashname ) ); 
  if (! lib ) {
    Scheme_Hash_Table * ht ; 
    BLOCK_SETUP((PUSH(ht, 0+XfOrM2_COUNT)));
#   define XfOrM3_COUNT (1+XfOrM2_COUNT)
#   define SETUP_XfOrM3(x) SETUP(XfOrM3_COUNT)
    ht = NULLED_OUT ; 
    handle = FUNCCALL(SETUP_XfOrM3(_), dlopen (name , 0x00002 | 0x00100 ) ); 
    if (handle == ((void * ) 0 ) && ! null_ok ) {
#     define XfOrM4_COUNT (0+XfOrM3_COUNT)
#     define SETUP_XfOrM4(x) SETUP_XfOrM3(x)
      if (argc > 1 && (! (((argv [1 ] ) ) == (scheme_false ) ) ) )
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      else {
#       define XfOrM5_COUNT (0+XfOrM4_COUNT)
#       define SETUP_XfOrM5(x) SETUP_XfOrM4(x)
        (__funcarg50 = FUNCCALL(SETUP_XfOrM5(_), dlerror () ), FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_FILESYSTEM , "ffi-lib" ": couldn't open %V (%s)" , argv [0 ] , __funcarg50 ) )) ; 
      }
    }
    ht = FUNCCALL(SETUP_XfOrM3(_), scheme_make_hash_table (SCHEME_hash_string ) ); 
    lib = (ffi_lib_struct * ) FUNCCALL(SETUP_XfOrM3(_), GC_malloc_one_tagged (sizeof (ffi_lib_struct ) ) ); 
    lib -> so . type = ffi_lib_tag ; 
    lib -> handle = (handle ) ; 
    lib -> name = (argv [0 ] ) ; 
    lib -> objects = (ht ) ; 
    FUNCCALL(SETUP_XfOrM3(_), scheme_hash_set (opened_libs , hashname , (Scheme_Object * ) lib ) ); 
  }
  RET_VALUE_START ((Scheme_Object * ) lib ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * foreign_ffi_lib_name (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ffi_lib_tag ) )
    scheme_wrong_type ("ffi-lib-name" , "ffi-lib" , 0 , argc , argv ) ; 
  return ((ffi_lib_struct * ) argv [0 ] ) -> name ; 
}
static Scheme_Type ffi_obj_tag ; 
typedef struct ffi_obj_struct {
  Scheme_Object so ; 
  void * obj ; 
  char * name ; 
  ffi_lib_struct * lib ; 
}
ffi_obj_struct ; 
static Scheme_Object * foreign_ffi_obj_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ffi_obj_tag ) ? scheme_true : scheme_false ; 
}
int ffi_obj_SIZE (void * p ) {
  return ((sizeof (ffi_obj_struct ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
int ffi_obj_MARK (void * p ) {
  ffi_obj_struct * s = (ffi_obj_struct * ) p ; 
  GC_mark (s -> obj ) ; 
  GC_mark (s -> name ) ; 
  GC_mark (s -> lib ) ; 
  return ((sizeof (ffi_obj_struct ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
int ffi_obj_FIXUP (void * p ) {
  ffi_obj_struct * s = (ffi_obj_struct * ) p ; 
  GC_fixup (& (s -> obj ) ) ; 
  GC_fixup (& (s -> name ) ) ; 
  GC_fixup (& (s -> lib ) ) ; 
  return ((sizeof (ffi_obj_struct ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static Scheme_Object * foreign_ffi_obj (int argc , Scheme_Object * argv [] ) {
  ffi_obj_struct * obj ; 
  void * dlobj ; 
  ffi_lib_struct * lib = ((void * ) 0 ) ; 
  char * dlname ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(lib, 0), PUSH(obj, 1), PUSH(dlobj, 2), PUSH(dlname, 3), PUSH(argv, 4)));
# define XfOrM8_COUNT (5)
# define SETUP_XfOrM8(x) SETUP(XfOrM8_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  obj = NULLED_OUT ; 
  dlobj = NULLED_OUT ; 
  dlname = NULLED_OUT ; 
  if ((((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) == ffi_lib_tag ) )
    lib = (ffi_lib_struct * ) argv [1 ] ; 
  else if ((((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) || (((argv [1 ] ) ) == (scheme_false ) ) )
    lib = (ffi_lib_struct * ) (FUNCCALL(SETUP_XfOrM8(_), foreign_ffi_lib (1 , & argv [1 ] ) )) ; 
  else FUNCCALL(SETUP_XfOrM8(_), scheme_wrong_type ("ffi-obj" , "ffi-lib" , 1 , argc , argv ) ); 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
    FUNCCALL(SETUP_XfOrM8(_), scheme_wrong_type ("ffi-obj" , "bytes" , 0 , argc , argv ) ); 
  dlname = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) ; 
  obj = (ffi_obj_struct * ) FUNCCALL(SETUP_XfOrM8(_), scheme_hash_get (lib -> objects , (Scheme_Object * ) dlname ) ); 
  if (! obj ) {
#   define XfOrM9_COUNT (0+XfOrM8_COUNT)
#   define SETUP_XfOrM9(x) SETUP_XfOrM8(x)
    dlobj = FUNCCALL(SETUP_XfOrM9(_), dlsym (lib -> handle , dlname ) ); 
    if (! dlobj ) {
      const char * err ; 
      BLOCK_SETUP((PUSH(err, 0+XfOrM9_COUNT)));
#     define XfOrM10_COUNT (1+XfOrM9_COUNT)
#     define SETUP_XfOrM10(x) SETUP(XfOrM10_COUNT)
      err = NULLED_OUT ; 
      err = FUNCCALL(SETUP_XfOrM10(_), dlerror () ); 
      if (err != ((void * ) 0 ) )
        FUNCCALL(SETUP_XfOrM10(_), scheme_raise_exn (MZEXN_FAIL_FILESYSTEM , "ffi-obj" ": couldn't get \"%s\" from %V (%s)" , dlname , lib -> name , err ) ); 
    }
    obj = (ffi_obj_struct * ) FUNCCALL(SETUP_XfOrM9(_), GC_malloc_one_tagged (sizeof (ffi_obj_struct ) ) ); 
    obj -> so . type = ffi_obj_tag ; 
    obj -> obj = (dlobj ) ; 
    obj -> name = (dlname ) ; 
    obj -> lib = (lib ) ; 
    FUNCCALL(SETUP_XfOrM9(_), scheme_hash_set (lib -> objects , (Scheme_Object * ) dlname , (Scheme_Object * ) obj ) ); 
  }
  RET_VALUE_START ((obj == ((void * ) 0 ) ) ? scheme_false : (Scheme_Object * ) obj ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * foreign_ffi_obj_lib (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ffi_obj_tag ) )
    scheme_wrong_type ("ffi-obj-lib" , "ffi-obj" , 0 , argc , argv ) ; 
  return (Scheme_Object * ) (((ffi_obj_struct * ) argv [0 ] ) -> lib ) ; 
}
static Scheme_Object * foreign_ffi_obj_name (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ffi_obj_tag ) )
    scheme_wrong_type ("ffi-obj-name" , "ffi-obj" , 0 , argc , argv ) ; 
  return scheme_make_byte_string (((ffi_obj_struct * ) argv [0 ] ) -> name ) ; 
}
inline int scheme_get_realint_val (Scheme_Object * o , int * v ) {
  /* No conversion */
  if ((((long ) (o ) ) & 0x1 ) ) {
    unsigned long lv = (((long ) (o ) ) >> 1 ) ; 
    int i = (int ) lv ; 
    if (i != lv )
      return 0 ; 
    * v = i ; 
    return 1 ; 
  }
  else return 0 ; 
}
inline int scheme_get_unsigned_realint_val (Scheme_Object * o , unsigned int * v ) {
  /* No conversion */
  if ((((long ) (o ) ) & 0x1 ) ) {
    unsigned long lv = (((long ) (o ) ) >> 1 ) ; 
    unsigned int i = (unsigned int ) lv ; 
    if (i != lv )
      return 0 ; 
    * v = i ; 
    return 1 ; 
  }
  else return 0 ; 
}
unsigned short * ucs4_string_to_utf16_pointer (Scheme_Object * ucs ) {
  long ulen ; 
  unsigned short * res ; 
  DECL_RET_SAVE (unsigned short * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(res, 0)));
# define XfOrM17_COUNT (1)
# define SETUP_XfOrM17(x) SETUP(XfOrM17_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  res = NULLED_OUT ; 
  res = FUNCCALL(SETUP_XfOrM17(_), scheme_ucs4_to_utf16 ((((Scheme_Simple_Object * ) (ucs ) ) -> u . char_str_val . string_val ) , 0 , 1 + (((Scheme_Simple_Object * ) (ucs ) ) -> u . char_str_val . tag_val ) , ((void * ) 0 ) , - 1 , & ulen , 0 ) ); 
  RET_VALUE_START (res ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * utf16_pointer_to_ucs4_string (unsigned short * utf ) {
  long ulen ; 
  mzchar * res ; 
  int end ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(res, 0)));
# define XfOrM18_COUNT (1)
# define SETUP_XfOrM18(x) SETUP(XfOrM18_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  res = NULLED_OUT ; 
  for (end = 0 ; utf [end ] != 0 ; end ++ ) {
  }
  res = FUNCCALL(SETUP_XfOrM18(_), scheme_utf16_to_ucs4 (utf , 0 , end , ((void * ) 0 ) , - 1 , & ulen , 0 ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_char_string (res , ulen , 0 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
typedef union _ForeignAny {
  Tsint8 x_int8 ; 
  Tuint8 x_uint8 ; 
  Tsint16 x_int16 ; 
  Tuint16 x_uint16 ; 
  Tsint32 x_int32 ; 
  Tuint32 x_uint32 ; 
  Tsint64 x_int64 ; 
  Tuint64 x_uint64 ; 
  Tsint32 x_fixint ; 
  Tuint32 x_ufixint ; 
  long x_fixnum ; 
  unsigned long x_ufixnum ; 
  float x_float ; 
  double x_double ; 
  double x_doubleS ; 
  int x_bool ; 
  mzchar * x_string_ucs_4 ; 
  unsigned short * x_string_utf_16 ; 
  char * x_bytes ; 
  char * x_path ; 
  char * x_symbol ; 
  void * x_pointer ; 
  Scheme_Object * x_scheme ; 
}
ForeignAny ; 
static Scheme_Type ctype_tag ; 
typedef struct ctype_struct {
  Scheme_Object so ; 
  Scheme_Object * basetype ; 
  Scheme_Object * scheme_to_c ; 
  Scheme_Object * c_to_scheme ; 
}
ctype_struct ; 
static Scheme_Object * foreign_ctype_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ctype_tag ) ? scheme_true : scheme_false ; 
}
int ctype_SIZE (void * p ) {
  return ((sizeof (ctype_struct ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
int ctype_MARK (void * p ) {
  ctype_struct * s = (ctype_struct * ) p ; 
  GC_mark (s -> basetype ) ; 
  GC_mark (s -> scheme_to_c ) ; 
  GC_mark (s -> c_to_scheme ) ; 
  return ((sizeof (ctype_struct ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
int ctype_FIXUP (void * p ) {
  ctype_struct * s = (ctype_struct * ) p ; 
  GC_fixup (& (s -> basetype ) ) ; 
  GC_fixup (& (s -> scheme_to_c ) ) ; 
  GC_fixup (& (s -> c_to_scheme ) ) ; 
  return ((sizeof (ctype_struct ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static Scheme_Object * foreign_ctype_basetype (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * base ; 
  if (! (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ctype_tag ) )
    scheme_wrong_type ("ctype-basetype" , "ctype" , 0 , argc , argv ) ; 
  base = (((ctype_struct * ) (argv [0 ] ) ) -> basetype ) ; 
  if (((void * ) 0 ) == base )
    return scheme_false ; 
  else return base ; 
}
static Scheme_Object * foreign_ctype_scheme_to_c (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ctype_tag ) )
    scheme_wrong_type ("ctype-scheme->c" , "ctype" , 0 , argc , argv ) ; 
  return ((((void * ) 0 ) == ((((ctype_struct * ) (argv [0 ] ) ) -> basetype ) ) ) ) ? scheme_false : ((ctype_struct * ) (argv [0 ] ) ) -> scheme_to_c ; 
}
static Scheme_Object * foreign_ctype_c_to_scheme (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ctype_tag ) )
    scheme_wrong_type ("ctype-c->scheme" , "ctype" , 0 , argc , argv ) ; 
  return ((((void * ) 0 ) == ((((ctype_struct * ) (argv [0 ] ) ) -> basetype ) ) ) ) ? scheme_false : ((ctype_struct * ) (argv [0 ] ) ) -> c_to_scheme ; 
}
static Scheme_Object * get_ctype_base (Scheme_Object * type ) {
  /* No conversion */
  if (! (((((long ) (type ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (type ) ) -> type ) == ctype_tag ) )
    return ((void * ) 0 ) ; 
  while ((! ((((void * ) 0 ) == ((((ctype_struct * ) (type ) ) -> basetype ) ) ) ) ) ) {
    type = (((ctype_struct * ) (type ) ) -> basetype ) ; 
  }
  return type ; 
}
static int ctype_sizeof (Scheme_Object * type ) {
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(type, 0)));
# define XfOrM28_COUNT (1)
# define SETUP_XfOrM28(x) SETUP(XfOrM28_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  type = FUNCCALL(SETUP_XfOrM28(_), get_ctype_base (type ) ); 
  if (type == ((void * ) 0 ) )
    RET_VALUE_START (- 1 ) RET_VALUE_END ; 
  switch (((long ) (((ctype_struct * ) (type ) ) -> c_to_scheme ) ) ) {
    case (1 ) : RET_VALUE_START (0 ) RET_VALUE_END ; 
    case (2 ) : RET_VALUE_START (sizeof (Tsint8 ) ) RET_VALUE_END ; 
    case (3 ) : RET_VALUE_START (sizeof (Tuint8 ) ) RET_VALUE_END ; 
    case (4 ) : RET_VALUE_START (sizeof (Tsint16 ) ) RET_VALUE_END ; 
    case (5 ) : RET_VALUE_START (sizeof (Tuint16 ) ) RET_VALUE_END ; 
    case (6 ) : RET_VALUE_START (sizeof (Tsint32 ) ) RET_VALUE_END ; 
    case (7 ) : RET_VALUE_START (sizeof (Tuint32 ) ) RET_VALUE_END ; 
    case (8 ) : RET_VALUE_START (sizeof (Tsint64 ) ) RET_VALUE_END ; 
    case (9 ) : RET_VALUE_START (sizeof (Tuint64 ) ) RET_VALUE_END ; 
    case (10 ) : RET_VALUE_START (sizeof (Tsint32 ) ) RET_VALUE_END ; 
    case (11 ) : RET_VALUE_START (sizeof (Tuint32 ) ) RET_VALUE_END ; 
    case (12 ) : RET_VALUE_START (sizeof (long ) ) RET_VALUE_END ; 
    case (13 ) : RET_VALUE_START (sizeof (unsigned long ) ) RET_VALUE_END ; 
    case (14 ) : RET_VALUE_START (sizeof (float ) ) RET_VALUE_END ; 
    case (15 ) : RET_VALUE_START (sizeof (double ) ) RET_VALUE_END ; 
    case (16 ) : RET_VALUE_START (sizeof (double ) ) RET_VALUE_END ; 
    case (17 ) : RET_VALUE_START (sizeof (int ) ) RET_VALUE_END ; 
    case (18 ) : RET_VALUE_START (sizeof (mzchar * ) ) RET_VALUE_END ; 
    case (19 ) : RET_VALUE_START (sizeof (unsigned short * ) ) RET_VALUE_END ; 
    case (20 ) : RET_VALUE_START (sizeof (char * ) ) RET_VALUE_END ; 
    case (21 ) : RET_VALUE_START (sizeof (char * ) ) RET_VALUE_END ; 
    case (22 ) : RET_VALUE_START (sizeof (char * ) ) RET_VALUE_END ; 
    case (23 ) : RET_VALUE_START (sizeof (void * ) ) RET_VALUE_END ; 
    case (24 ) : RET_VALUE_START (sizeof (Scheme_Object * ) ) RET_VALUE_END ; 
    case (25 ) : RET_VALUE_START (0 ) RET_VALUE_END ; 
    default : RET_VALUE_START (((ffi_type * ) (((ctype_struct * ) (type ) ) -> scheme_to_c ) ) -> size ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * foreign_make_ctype (int argc , Scheme_Object * argv [] ) {
  ctype_struct * type ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(type, 0), PUSH(argv, 1)));
# define XfOrM30_COUNT (2)
# define SETUP_XfOrM30(x) SETUP(XfOrM30_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  type = NULLED_OUT ; 
  if (! (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ctype_tag ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("make-ctype" , "C-type" , 0 , argc , argv ) ); 
  else if (! ((((argv [1 ] ) ) == (scheme_false ) ) || (! (((long ) (argv [1 ] ) ) & 0x1 ) && ((((argv [1 ] ) -> type ) >= scheme_prim_type ) && (((argv [1 ] ) -> type ) <= scheme_native_closure_type ) ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("make-ctype" , "procedure-or-false" , 1 , argc , argv ) ); 
  else if (! ((((argv [2 ] ) ) == (scheme_false ) ) || (! (((long ) (argv [2 ] ) ) & 0x1 ) && ((((argv [2 ] ) -> type ) >= scheme_prim_type ) && (((argv [2 ] ) -> type ) <= scheme_native_closure_type ) ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("make-ctype" , "procedure-or-false" , 2 , argc , argv ) ); 
  else if ((((argv [1 ] ) ) == (scheme_false ) ) && (((argv [2 ] ) ) == (scheme_false ) ) )
    RET_VALUE_START (argv [0 ] ) RET_VALUE_END ; 
  else {
#   define XfOrM31_COUNT (0+XfOrM30_COUNT)
#   define SETUP_XfOrM31(x) SETUP_XfOrM30(x)
    type = (ctype_struct * ) FUNCCALL(SETUP_XfOrM31(_), GC_malloc_one_tagged (sizeof (ctype_struct ) ) ); 
    type -> so . type = ctype_tag ; 
    type -> basetype = (argv [0 ] ) ; 
    type -> scheme_to_c = (argv [1 ] ) ; 
    type -> c_to_scheme = (argv [2 ] ) ; 
    RET_VALUE_START ((Scheme_Object * ) type ) RET_VALUE_END ; 
  }
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void free_libffi_type (void * ignored , void * p ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(p, 0)));
# define XfOrM32_COUNT (1)
# define SETUP_XfOrM32(x) SETUP(XfOrM32_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM32(_), free (((ffi_type * ) p ) -> elements ) ); 
  FUNCCALL_EMPTY(free (p ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 989 */
static Scheme_Object * foreign_make_cstruct_type (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * p , * base ; 
  GC_CAN_IGNORE ffi_type * * elements , * libffi_type , * * dummy ; 
  ctype_struct * type ; 
  ffi_cif cif ; 
  int i , nargs ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(base, 0), PUSH(type, 1), PUSH(cif.arg_types, 2), PUSH(cif.rtype, 3), PUSH(argv, 4), PUSH(p, 5)));
# define XfOrM33_COUNT (6)
# define SETUP_XfOrM33(x) SETUP(XfOrM33_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  p = NULLED_OUT ; 
  base = NULLED_OUT ; 
  type = NULLED_OUT ; 
  cif.arg_types = NULLED_OUT ; 
  cif.rtype = NULLED_OUT ; 
  nargs = FUNCCALL(SETUP_XfOrM33(_), scheme_proper_list_length (argv [0 ] ) ); 
  if (nargs < 0 )
    FUNCCALL(SETUP_XfOrM33(_), scheme_wrong_type ("make-cstruct-type" , "proper list" , 0 , argc , argv ) ); 
  elements = FUNCCALL(SETUP_XfOrM33(_), malloc ((nargs + 1 ) * sizeof (ffi_type * ) ) ); 
  elements [nargs ] = ((void * ) 0 ) ; 
  for (i = 0 , p = argv [0 ] ; i < nargs ; i ++ , p = (((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . cdr ) ) {
#   define XfOrM35_COUNT (0+XfOrM33_COUNT)
#   define SETUP_XfOrM35(x) SETUP_XfOrM33(x)
    if (((void * ) 0 ) == (base = FUNCCALL(SETUP_XfOrM35(_), get_ctype_base ((((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . car ) ) )) )
      FUNCCALL(SETUP_XfOrM35(_), scheme_wrong_type ("make-cstruct-type" , "list-of-C-types" , 0 , argc , argv ) ); 
    if (((long ) (((ctype_struct * ) (base ) ) -> c_to_scheme ) ) == (1 ) )
      FUNCCALL(SETUP_XfOrM35(_), scheme_wrong_type ("make-cstruct-type" , "list-of-non-void-C-types" , 0 , argc , argv ) ); 
    elements [i ] = ((ffi_type * ) (((ctype_struct * ) (base ) ) -> scheme_to_c ) ) ; 
  }
  libffi_type = FUNCCALL(SETUP_XfOrM33(_), malloc (sizeof (ffi_type ) ) ); 
  libffi_type -> size = 0 ; 
  libffi_type -> alignment = 0 ; 
  libffi_type -> type = 13 ; 
  libffi_type -> elements = elements ; 
  dummy = & libffi_type ; 
  if (FUNCCALL(SETUP_XfOrM33(_), ffi_prep_cif (& cif , FFI_DEFAULT_ABI , 1 , & ffi_type_void , dummy ) )!= FFI_OK )
    FUNCCALL(SETUP_XfOrM33(_), scheme_signal_error ("internal error: ffi_prep_cif did not return FFI_OK" ) ); 
  type = (ctype_struct * ) FUNCCALL(SETUP_XfOrM33(_), GC_malloc_one_tagged (sizeof (ctype_struct ) ) ); 
  type -> so . type = ctype_tag ; 
  type -> basetype = (((void * ) 0 ) ) ; 
  type -> scheme_to_c = ((Scheme_Object * ) libffi_type ) ; 
  type -> c_to_scheme = ((Scheme_Object * ) (26 ) ) ; 
  FUNCCALL(SETUP_XfOrM33(_), scheme_register_finalizer (type , free_libffi_type , libffi_type , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
  RET_VALUE_START ((Scheme_Object * ) type ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * foreign_cpointer_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return ((((argv [0 ] ) ) == (scheme_false ) ) || (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) || (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ffi_obj_tag ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ) ? scheme_true : scheme_false ; 
}
static Scheme_Object * foreign_cpointer_tag (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * tag = ((void * ) 0 ) ; 
  if (! ((((argv [0 ] ) ) == (scheme_false ) ) || (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) || (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ffi_obj_tag ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ) )
    scheme_wrong_type ("cpointer-tag" , "cpointer" , 0 , argc , argv ) ; 
  if ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) )
    tag = (((Scheme_Cptr * ) (argv [0 ] ) ) -> type ) ; 
  return (tag == ((void * ) 0 ) ) ? scheme_false : tag ; 
}
static Scheme_Object * foreign_set_cpointer_tag_bang (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) )
    scheme_wrong_type ("set-cpointer-tag!" , "proper-cpointer" , 0 , argc , argv ) ; 
  (((Scheme_Cptr * ) (argv [0 ] ) ) -> type ) = argv [1 ] ; 
  return scheme_void ; 
}
static Scheme_Type ffi_callback_tag ; 
typedef struct ffi_callback_struct {
  Scheme_Object so ; 
  void * callback ; 
  Scheme_Object * proc ; 
  Scheme_Object * itypes ; 
  Scheme_Object * otype ; 
}
ffi_callback_struct ; 
static Scheme_Object * foreign_ffi_callback_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ffi_callback_tag ) ? scheme_true : scheme_false ; 
}
int ffi_callback_SIZE (void * p ) {
  return ((sizeof (ffi_callback_struct ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
int ffi_callback_MARK (void * p ) {
  ffi_callback_struct * s = (ffi_callback_struct * ) p ; 
  GC_mark (s -> callback ) ; 
  GC_mark (s -> proc ) ; 
  GC_mark (s -> itypes ) ; 
  GC_mark (s -> otype ) ; 
  return ((sizeof (ffi_callback_struct ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
int ffi_callback_FIXUP (void * p ) {
  ffi_callback_struct * s = (ffi_callback_struct * ) p ; 
  GC_fixup (& (s -> callback ) ) ; 
  GC_fixup (& (s -> proc ) ) ; 
  GC_fixup (& (s -> itypes ) ) ; 
  GC_fixup (& (s -> otype ) ) ; 
  return ((sizeof (ffi_callback_struct ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static Scheme_Object * c_to_scheme (Scheme_Object * type , void * src , int delta ) {
  Scheme_Object * res , * base ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(base, 0), PUSH(src, 1), PUSH(type, 2), PUSH(res, 3)));
# define XfOrM40_COUNT (4)
# define SETUP_XfOrM40(x) SETUP(XfOrM40_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  res = NULLED_OUT ; 
  base = NULLED_OUT ; 
  if (! (((((long ) (type ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (type ) ) -> type ) == ctype_tag ) )
    FUNCCALL(SETUP_XfOrM40(_), scheme_wrong_type ("C->Scheme" , "C-type" , 0 , 1 , & type ) ); 
  base = (((ctype_struct * ) (type ) ) -> basetype ) ; 
  if (base != ((void * ) 0 ) ) {
#   define XfOrM43_COUNT (0+XfOrM40_COUNT)
#   define SETUP_XfOrM43(x) SETUP_XfOrM40(x)
    res = FUNCCALL(SETUP_XfOrM43(_), c_to_scheme (base , src , delta ) ); 
    if (((((((ctype_struct * ) (type ) ) -> c_to_scheme ) ) ) == (scheme_false ) ) )
      RET_VALUE_START (res ) RET_VALUE_END ; 
    else RET_VALUE_START (FUNCCALL(SETUP_XfOrM43(_), scheme_do_eval ((((ctype_struct * ) (type ) ) -> c_to_scheme ) , 1 , (Scheme_Object * * ) (& res ) , 1 ) )) RET_VALUE_END ; 
  }
  else if (((long ) (((ctype_struct * ) (type ) ) -> c_to_scheme ) ) == (25 ) ) {
    RET_VALUE_START ((Scheme_Object * ) ((char * ) (src ) XFORM_OK_PLUS (delta ) ) ) RET_VALUE_END ; 
  }
  else switch (((long ) (((ctype_struct * ) (type ) ) -> c_to_scheme ) ) ) {
#   define XfOrM41_COUNT (0+XfOrM40_COUNT)
#   define SETUP_XfOrM41(x) SETUP_XfOrM40(x)
    case (1 ) : RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
    case (2 ) : RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) ((((Tsint8 * ) ((char * ) (src ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
    case (3 ) : RET_VALUE_START (((Scheme_Object * ) ((((unsigned long ) (((Tuint8 * ) ((char * ) (src ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
    case (4 ) : RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) ((((Tsint16 * ) ((char * ) (src ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
    case (5 ) : RET_VALUE_START (((Scheme_Object * ) ((((unsigned long ) (((Tuint16 * ) ((char * ) (src ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
    case (6 ) : RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) ((long ) ((((Tsint32 * ) ((char * ) (src ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) ) ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
    case (7 ) : RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) ((unsigned long ) ((((Tuint32 * ) ((char * ) (src ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) ) ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
    case (8 ) : RET_VALUE_START (FUNCCALL(SETUP_XfOrM41(_), scheme_make_integer_value_from_long_long ((((Tsint64 * ) ((char * ) (src ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) ) )) RET_VALUE_END ; 
    case (9 ) : RET_VALUE_START (FUNCCALL(SETUP_XfOrM41(_), scheme_make_integer_value_from_unsigned_long_long ((((Tuint64 * ) ((char * ) (src ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) ) )) RET_VALUE_END ; 
    case (10 ) : RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) ((((Tsint32 * ) ((char * ) (src ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
    case (11 ) : RET_VALUE_START (((Scheme_Object * ) ((((unsigned long ) (((Tuint32 * ) ((char * ) (src ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
    case (12 ) : RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) ((((long * ) ((char * ) (src ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
    case (13 ) : RET_VALUE_START (((Scheme_Object * ) ((((unsigned long ) (((unsigned long * ) ((char * ) (src ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
    case (14 ) : RET_VALUE_START (FUNCCALL(SETUP_XfOrM41(_), scheme_make_double ((double ) (((float * ) ((char * ) (src ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) ) )) RET_VALUE_END ; 
    case (15 ) : RET_VALUE_START (FUNCCALL(SETUP_XfOrM41(_), scheme_make_double ((((double * ) ((char * ) (src ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) ) )) RET_VALUE_END ; 
    case (16 ) : RET_VALUE_START (FUNCCALL(SETUP_XfOrM41(_), scheme_make_double ((((double * ) ((char * ) (src ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) ) )) RET_VALUE_END ; 
    case (17 ) : RET_VALUE_START (((((int * ) ((char * ) (src ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) ? scheme_true : scheme_false ) ) RET_VALUE_END ; 
    case (18 ) : RET_VALUE_START (FUNCCALL(SETUP_XfOrM41(_), scheme_make_char_string_without_copying ((((mzchar * * ) ((char * ) (src ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) ) )) RET_VALUE_END ; 
    case (19 ) : RET_VALUE_START (FUNCCALL(SETUP_XfOrM41(_), utf16_pointer_to_ucs4_string ((((unsigned short * * ) ((char * ) (src ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) ) )) RET_VALUE_END ; 
    case (20 ) : RET_VALUE_START (((((char * * ) ((char * ) (src ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) == ((void * ) 0 ) ) ? scheme_false : FUNCCALL(SETUP_XfOrM41(_), scheme_make_byte_string_without_copying ((((char * * ) ((char * ) (src ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) ) )) RET_VALUE_END ; 
    case (21 ) : RET_VALUE_START (((((char * * ) ((char * ) (src ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) == ((void * ) 0 ) ) ? scheme_false : FUNCCALL(SETUP_XfOrM41(_), scheme_make_path_without_copying ((((char * * ) ((char * ) (src ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) ) )) RET_VALUE_END ; 
    case (22 ) : RET_VALUE_START (FUNCCALL(SETUP_XfOrM41(_), scheme_intern_symbol ((((char * * ) ((char * ) (src ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) ) )) RET_VALUE_END ; 
    case (23 ) : RET_VALUE_START ((((((void * * ) ((char * ) (src ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) == ((void * ) 0 ) ) ? scheme_false : FUNCCALL(SETUP_XfOrM41(_), scheme_make_cptr ((((void * * ) ((char * ) (src ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) , ((void * ) 0 ) ) )) ) RET_VALUE_END ; 
    case (24 ) : RET_VALUE_START ((((Scheme_Object * * ) ((char * ) (src ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) ) RET_VALUE_END ; 
    case (25 ) : RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
    case (26 ) : RET_VALUE_START (((((char * ) (src ) XFORM_OK_PLUS (delta ) ) == ((void * ) 0 ) ) ? scheme_false : FUNCCALL(SETUP_XfOrM41(_), scheme_make_cptr (((char * ) (src ) XFORM_OK_PLUS (delta ) ) , ((void * ) 0 ) ) )) ) RET_VALUE_END ; 
    default : FUNCCALL(SETUP_XfOrM41(_), scheme_signal_error ("corrupt foreign type: %V" , type ) ); 
  }
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void * scheme_to_c (Scheme_Object * type , void * dst , long delta , Scheme_Object * val , long * basetype_p , long * _offset ) {
  DECL_RET_SAVE (void * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(val, 0), PUSH(basetype_p, 1), PUSH(_offset, 2), PUSH(type, 3), PUSH(dst, 4)));
# define XfOrM44_COUNT (5)
# define SETUP_XfOrM44(x) SETUP(XfOrM44_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! (((((long ) (type ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (type ) ) -> type ) == ctype_tag ) )
    FUNCCALL(SETUP_XfOrM44(_), scheme_wrong_type ("Scheme->C" , "C-type" , 0 , 1 , & type ) ); 
  while ((! ((((void * ) 0 ) == ((((ctype_struct * ) (type ) ) -> basetype ) ) ) ) ) ) {
#   define XfOrM105_COUNT (0+XfOrM44_COUNT)
#   define SETUP_XfOrM105(x) SETUP_XfOrM44(x)
    if (! ((((((ctype_struct * ) (type ) ) -> scheme_to_c ) ) ) == (scheme_false ) ) )
      val = FUNCCALL(SETUP_XfOrM105(_), scheme_do_eval ((((ctype_struct * ) (type ) ) -> scheme_to_c ) , 1 , (Scheme_Object * * ) (& val ) , 1 ) ); 
    type = (((ctype_struct * ) (type ) ) -> basetype ) ; 
  }
  if (((long ) (((ctype_struct * ) (type ) ) -> c_to_scheme ) ) == (25 ) ) {
#   define XfOrM103_COUNT (0+XfOrM44_COUNT)
#   define SETUP_XfOrM103(x) SETUP_XfOrM44(x)
    if ((((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) == ffi_callback_tag ) )
      ((void * * ) ((char * ) (dst ) XFORM_OK_PLUS (delta ) ) ) [0 ] = ((ffi_callback_struct * ) val ) -> callback ; 
    else if ((((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) )
      ((void * * ) ((char * ) (dst ) XFORM_OK_PLUS (delta ) ) ) [0 ] = (((Scheme_Cptr * ) (val ) ) -> val ) ; 
    else if ((((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) == ffi_obj_tag ) )
      ((void * * ) ((char * ) (dst ) XFORM_OK_PLUS (delta ) ) ) [0 ] = ((ffi_obj_struct * ) val ) -> obj ; 
    else FUNCCALL(SETUP_XfOrM103(_), scheme_wrong_type ("Scheme->C" , "cpointer" , 0 , 1 , & val ) ); 
  }
  else switch (((long ) (((ctype_struct * ) (type ) ) -> c_to_scheme ) ) ) {
#   define XfOrM45_COUNT (0+XfOrM44_COUNT)
#   define SETUP_XfOrM45(x) SETUP_XfOrM44(x)
    case (1 ) : FUNCCALL(SETUP_XfOrM45(_), scheme_wrong_type ("Scheme->C" , "non-void-C-type" , 0 , 1 , & (type ) ) ); 
    case (2 ) : if ((((long ) (val ) ) & 0x1 ) ) {
      Tsint8 tmp ; 
      tmp = (Tsint8 ) ((((long ) (val ) ) >> 1 ) ) ; 
      (((Tsint8 * ) ((char * ) (dst ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) = tmp ; 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else {
#     define XfOrM101_COUNT (0+XfOrM45_COUNT)
#     define SETUP_XfOrM101(x) SETUP_XfOrM45(x)
      FUNCCALL(SETUP_XfOrM101(_), scheme_wrong_type ("Scheme->C" , "int8" , 0 , 1 , & (val ) ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    case (3 ) : if ((((long ) (val ) ) & 0x1 ) ) {
      Tuint8 tmp ; 
      tmp = (Tuint8 ) (((unsigned ) ((((long ) (val ) ) >> 1 ) ) ) ) ; 
      (((Tuint8 * ) ((char * ) (dst ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) = tmp ; 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else {
#     define XfOrM99_COUNT (0+XfOrM45_COUNT)
#     define SETUP_XfOrM99(x) SETUP_XfOrM45(x)
      FUNCCALL(SETUP_XfOrM99(_), scheme_wrong_type ("Scheme->C" , "uint8" , 0 , 1 , & (val ) ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    case (4 ) : if ((((long ) (val ) ) & 0x1 ) ) {
      Tsint16 tmp ; 
      tmp = (Tsint16 ) ((((long ) (val ) ) >> 1 ) ) ; 
      (((Tsint16 * ) ((char * ) (dst ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) = tmp ; 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else {
#     define XfOrM97_COUNT (0+XfOrM45_COUNT)
#     define SETUP_XfOrM97(x) SETUP_XfOrM45(x)
      FUNCCALL(SETUP_XfOrM97(_), scheme_wrong_type ("Scheme->C" , "int16" , 0 , 1 , & (val ) ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    case (5 ) : if ((((long ) (val ) ) & 0x1 ) ) {
      Tuint16 tmp ; 
      tmp = (Tuint16 ) (((unsigned ) ((((long ) (val ) ) >> 1 ) ) ) ) ; 
      (((Tuint16 * ) ((char * ) (dst ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) = tmp ; 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else {
#     define XfOrM95_COUNT (0+XfOrM45_COUNT)
#     define SETUP_XfOrM95(x) SETUP_XfOrM45(x)
      FUNCCALL(SETUP_XfOrM95(_), scheme_wrong_type ("Scheme->C" , "uint16" , 0 , 1 , & (val ) ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    case (6 ) : if (! (FUNCCALL(SETUP_XfOrM45(_), scheme_get_realint_val (val , & (((Tsint32 * ) ((char * ) (dst ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) ) )) )
      FUNCCALL(SETUP_XfOrM45(_), scheme_wrong_type ("Scheme->C" , "int32" , 0 , 1 , & (val ) ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    case (7 ) : if (! (FUNCCALL(SETUP_XfOrM45(_), scheme_get_unsigned_realint_val (val , & (((Tuint32 * ) ((char * ) (dst ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) ) )) )
      FUNCCALL(SETUP_XfOrM45(_), scheme_wrong_type ("Scheme->C" , "uint32" , 0 , 1 , & (val ) ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    case (8 ) : if (! ((scheme_get_long_long_val (val , & (((Tsint64 * ) ((char * ) (dst ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) ) ) ) )
      FUNCCALL(SETUP_XfOrM45(_), scheme_wrong_type ("Scheme->C" , "int64" , 0 , 1 , & (val ) ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    case (9 ) : if (! ((scheme_get_unsigned_long_long_val (val , & (((Tuint64 * ) ((char * ) (dst ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) ) ) ) )
      FUNCCALL(SETUP_XfOrM45(_), scheme_wrong_type ("Scheme->C" , "uint64" , 0 , 1 , & (val ) ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    case (10 ) : if ((((long ) (val ) ) & 0x1 ) ) {
      Tsint32 tmp ; 
      tmp = (Tsint32 ) ((((long ) (val ) ) >> 1 ) ) ; 
      (((Tsint32 * ) ((char * ) (dst ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) = tmp ; 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else {
#     define XfOrM93_COUNT (0+XfOrM45_COUNT)
#     define SETUP_XfOrM93(x) SETUP_XfOrM45(x)
      FUNCCALL(SETUP_XfOrM93(_), scheme_wrong_type ("Scheme->C" , "fixint" , 0 , 1 , & (val ) ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    case (11 ) : if ((((long ) (val ) ) & 0x1 ) ) {
      Tuint32 tmp ; 
      tmp = (Tuint32 ) (((unsigned ) ((((long ) (val ) ) >> 1 ) ) ) ) ; 
      (((Tuint32 * ) ((char * ) (dst ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) = tmp ; 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else {
#     define XfOrM91_COUNT (0+XfOrM45_COUNT)
#     define SETUP_XfOrM91(x) SETUP_XfOrM45(x)
      FUNCCALL(SETUP_XfOrM91(_), scheme_wrong_type ("Scheme->C" , "ufixint" , 0 , 1 , & (val ) ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    case (12 ) : if ((((long ) (val ) ) & 0x1 ) ) {
      long tmp ; 
      tmp = (long ) ((((long ) (val ) ) >> 1 ) ) ; 
      (((long * ) ((char * ) (dst ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) = tmp ; 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else {
#     define XfOrM89_COUNT (0+XfOrM45_COUNT)
#     define SETUP_XfOrM89(x) SETUP_XfOrM45(x)
      FUNCCALL(SETUP_XfOrM89(_), scheme_wrong_type ("Scheme->C" , "fixnum" , 0 , 1 , & (val ) ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    case (13 ) : if ((((long ) (val ) ) & 0x1 ) ) {
      unsigned long tmp ; 
      tmp = (unsigned long ) (((unsigned ) ((((long ) (val ) ) >> 1 ) ) ) ) ; 
      (((unsigned long * ) ((char * ) (dst ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) = tmp ; 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else {
#     define XfOrM87_COUNT (0+XfOrM45_COUNT)
#     define SETUP_XfOrM87(x) SETUP_XfOrM45(x)
      FUNCCALL(SETUP_XfOrM87(_), scheme_wrong_type ("Scheme->C" , "ufixnum" , 0 , 1 , & (val ) ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    case (14 ) : if (((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ) {
      float tmp ; 
      tmp = (float ) (((float ) ((((Scheme_Double * ) (val ) ) -> double_val ) ) ) ) ; 
      (((float * ) ((char * ) (dst ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) = tmp ; 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else {
#     define XfOrM85_COUNT (0+XfOrM45_COUNT)
#     define SETUP_XfOrM85(x) SETUP_XfOrM45(x)
      FUNCCALL(SETUP_XfOrM85(_), scheme_wrong_type ("Scheme->C" , "float" , 0 , 1 , & (val ) ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    case (15 ) : if (((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ) {
      double tmp ; 
      tmp = (double ) ((((Scheme_Double * ) (val ) ) -> double_val ) ) ; 
      (((double * ) ((char * ) (dst ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) = tmp ; 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else {
#     define XfOrM83_COUNT (0+XfOrM45_COUNT)
#     define SETUP_XfOrM83(x) SETUP_XfOrM45(x)
      FUNCCALL(SETUP_XfOrM83(_), scheme_wrong_type ("Scheme->C" , "double" , 0 , 1 , & (val ) ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    case (16 ) : if (((((long ) (val ) ) & 0x1 ) || ((((val ) -> type ) >= scheme_bignum_type ) && (((val ) -> type ) <= scheme_complex_izi_type ) ) ) ) {
      double tmp ; 
#     define XfOrM82_COUNT (0+XfOrM45_COUNT)
#     define SETUP_XfOrM82(x) SETUP_XfOrM45(x)
      tmp = (double ) ((scheme_real_to_double (val ) ) ) ; 
      (((double * ) ((char * ) (dst ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) = tmp ; 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else {
#     define XfOrM81_COUNT (0+XfOrM45_COUNT)
#     define SETUP_XfOrM81(x) SETUP_XfOrM45(x)
      FUNCCALL(SETUP_XfOrM81(_), scheme_wrong_type ("Scheme->C" , "double*" , 0 , 1 , & (val ) ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    case (17 ) : if (1 ) {
      int tmp ; 
      tmp = (int ) ((! (((val ) ) == (scheme_false ) ) ) ) ; 
      (((int * ) ((char * ) (dst ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) = tmp ; 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else {
#     define XfOrM79_COUNT (0+XfOrM45_COUNT)
#     define SETUP_XfOrM79(x) SETUP_XfOrM45(x)
      FUNCCALL(SETUP_XfOrM79(_), scheme_wrong_type ("Scheme->C" , "bool" , 0 , 1 , & (val ) ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    case (18 ) : if (((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) ) {
      mzchar * tmp ; 
      tmp = NULLED_OUT ; 
      tmp = (mzchar * ) ((((Scheme_Simple_Object * ) (val ) ) -> u . char_str_val . string_val ) ) ; 
      if (basetype_p == ((void * ) 0 ) || tmp == ((void * ) 0 ) ) {
        (((mzchar * * ) ((char * ) (dst ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) = tmp ; 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      else {
        * basetype_p = (18 ) ; 
        RET_VALUE_START (tmp ) RET_VALUE_END ; 
      }
    }
    else {
#     define XfOrM75_COUNT (0+XfOrM45_COUNT)
#     define SETUP_XfOrM75(x) SETUP_XfOrM45(x)
      FUNCCALL(SETUP_XfOrM75(_), scheme_wrong_type ("Scheme->C" , "string/ucs-4" , 0 , 1 , & (val ) ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    case (19 ) : if (((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) ) {
      unsigned short * tmp ; 
      BLOCK_SETUP((PUSH(tmp, 0+XfOrM45_COUNT)));
#     define XfOrM72_COUNT (1+XfOrM45_COUNT)
#     define SETUP_XfOrM72(x) SETUP(XfOrM72_COUNT)
      tmp = NULLED_OUT ; 
      tmp = (unsigned short * ) (FUNCCALL(SETUP_XfOrM72(_), ucs4_string_to_utf16_pointer (val ) )) ; 
      if (basetype_p == ((void * ) 0 ) || tmp == ((void * ) 0 ) ) {
        (((unsigned short * * ) ((char * ) (dst ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) = tmp ; 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      else {
        * basetype_p = (19 ) ; 
        RET_VALUE_START (tmp ) RET_VALUE_END ; 
      }
    }
    else {
#     define XfOrM71_COUNT (0+XfOrM45_COUNT)
#     define SETUP_XfOrM71(x) SETUP_XfOrM45(x)
      FUNCCALL(SETUP_XfOrM71(_), scheme_wrong_type ("Scheme->C" , "string/utf-16" , 0 , 1 , & (val ) ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    case (20 ) : if ((((val ) ) == (scheme_false ) ) || ((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ) {
      char * tmp ; 
      tmp = NULLED_OUT ; 
      tmp = (char * ) ((((val ) ) == (scheme_false ) ) ? ((void * ) 0 ) : (((Scheme_Simple_Object * ) (val ) ) -> u . byte_str_val . string_val ) ) ; 
      if (basetype_p == ((void * ) 0 ) || tmp == ((void * ) 0 ) ) {
        (((char * * ) ((char * ) (dst ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) = tmp ; 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      else {
        * basetype_p = (20 ) ; 
        RET_VALUE_START (tmp ) RET_VALUE_END ; 
      }
    }
    else {
#     define XfOrM67_COUNT (0+XfOrM45_COUNT)
#     define SETUP_XfOrM67(x) SETUP_XfOrM45(x)
      FUNCCALL(SETUP_XfOrM67(_), scheme_wrong_type ("Scheme->C" , "bytes" , 0 , 1 , & (val ) ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    case (21 ) : if ((((val ) ) == (scheme_false ) ) || (((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) ) {
      char * tmp ; 
      BLOCK_SETUP((PUSH(tmp, 0+XfOrM45_COUNT)));
#     define XfOrM64_COUNT (1+XfOrM45_COUNT)
#     define SETUP_XfOrM64(x) SETUP(XfOrM64_COUNT)
      tmp = NULLED_OUT ; 
      tmp = (char * ) ((((val ) ) == (scheme_false ) ) ? ((void * ) 0 ) : (((Scheme_Simple_Object * ) ((((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ? (val ) : FUNCCALL(SETUP_XfOrM64(_), scheme_char_string_to_path (val ) )) ) ) -> u . byte_str_val . string_val ) ) ; 
      if (basetype_p == ((void * ) 0 ) || tmp == ((void * ) 0 ) ) {
        (((char * * ) ((char * ) (dst ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) = tmp ; 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      else {
        * basetype_p = (21 ) ; 
        RET_VALUE_START (tmp ) RET_VALUE_END ; 
      }
    }
    else {
#     define XfOrM63_COUNT (0+XfOrM45_COUNT)
#     define SETUP_XfOrM63(x) SETUP_XfOrM45(x)
      FUNCCALL(SETUP_XfOrM63(_), scheme_wrong_type ("Scheme->C" , "path" , 0 , 1 , & (val ) ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    case (22 ) : if (((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
      char * tmp ; 
      tmp = NULLED_OUT ; 
      tmp = (char * ) ((((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (val ) ) ) -> s ) ) ; 
      if (basetype_p == ((void * ) 0 ) || tmp == ((void * ) 0 ) ) {
        (((char * * ) ((char * ) (dst ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) = tmp ; 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      else {
        * basetype_p = (22 ) ; 
        RET_VALUE_START (tmp ) RET_VALUE_END ; 
      }
    }
    else {
#     define XfOrM59_COUNT (0+XfOrM45_COUNT)
#     define SETUP_XfOrM59(x) SETUP_XfOrM45(x)
      FUNCCALL(SETUP_XfOrM59(_), scheme_wrong_type ("Scheme->C" , "symbol" , 0 , 1 , & (val ) ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    case (23 ) : if (((((val ) ) == (scheme_false ) ) || (((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) || (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) == ffi_obj_tag ) || ((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ) ) {
      void * tmp ; 
      long toff ; 
      tmp = NULLED_OUT ; 
      tmp = (void * ) (((((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Cptr * ) (val ) ) -> val ) : ((((val ) ) == (scheme_false ) ) ? ((void * ) 0 ) : ((((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) == ffi_obj_tag ) ? (((ffi_obj_struct * ) val ) -> obj ) : ((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ? (((Scheme_Simple_Object * ) (val ) ) -> u . byte_str_val . string_val ) : ((void * ) 0 ) ) ) ) ) ; 
      toff = ((((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Type ) (((val ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ? ((Scheme_Offset_Cptr * ) val ) -> offset : 0 ) : 0 ) ; 
      if (_offset )
        * _offset = toff ; 
      if (basetype_p == ((void * ) 0 ) || (tmp == ((void * ) 0 ) && toff == 0 ) ) {
        (((void * * ) ((char * ) (dst ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) = (_offset ? tmp : (void * ) ((char * ) (tmp ) XFORM_OK_PLUS (toff ) ) ) ; 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      else {
        * basetype_p = (23 ) ; 
        RET_VALUE_START (_offset ? tmp : (void * ) ((char * ) (tmp ) XFORM_OK_PLUS (toff ) ) ) RET_VALUE_END ; 
      }
    }
    else {
#     define XfOrM55_COUNT (0+XfOrM45_COUNT)
#     define SETUP_XfOrM55(x) SETUP_XfOrM45(x)
      FUNCCALL(SETUP_XfOrM55(_), scheme_wrong_type ("Scheme->C" , "pointer" , 0 , 1 , & (val ) ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    case (24 ) : if (1 ) {
      Scheme_Object * tmp ; 
      tmp = NULLED_OUT ; 
      tmp = (Scheme_Object * ) (val ) ; 
      if (basetype_p == ((void * ) 0 ) || tmp == ((void * ) 0 ) ) {
        (((Scheme_Object * * ) ((char * ) (dst ) XFORM_OK_PLUS (delta ) ) ) [0 ] ) = tmp ; 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      else {
        * basetype_p = (24 ) ; 
        RET_VALUE_START (tmp ) RET_VALUE_END ; 
      }
    }
    else {
#     define XfOrM51_COUNT (0+XfOrM45_COUNT)
#     define SETUP_XfOrM51(x) SETUP_XfOrM45(x)
      FUNCCALL(SETUP_XfOrM51(_), scheme_wrong_type ("Scheme->C" , "scheme" , 0 , 1 , & (val ) ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    case (25 ) : FUNCCALL(SETUP_XfOrM45(_), scheme_wrong_type ("Scheme->C" , "non-void-C-type" , 0 , 1 , & (type ) ) ); 
    case (26 ) : if (! ((((val ) ) == (scheme_false ) ) || (((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) || (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) == ffi_obj_tag ) || ((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ) )
      FUNCCALL(SETUP_XfOrM45(_), scheme_wrong_type ("Scheme->C" , "pointer" , 0 , 1 , & val ) ); 
    {
      void * p = ((((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Cptr * ) (val ) ) -> val ) : ((((val ) ) == (scheme_false ) ) ? ((void * ) 0 ) : ((((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) == ffi_obj_tag ) ? (((ffi_obj_struct * ) val ) -> obj ) : ((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ? (((Scheme_Simple_Object * ) (val ) ) -> u . byte_str_val . string_val ) : ((void * ) 0 ) ) ) ) ; 
      long poff = ((((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Type ) (((val ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ? ((Scheme_Offset_Cptr * ) val ) -> offset : 0 ) : 0 ) ; 
      BLOCK_SETUP((PUSH(p, 0+XfOrM45_COUNT)));
#     define XfOrM46_COUNT (1+XfOrM45_COUNT)
#     define SETUP_XfOrM46(x) SETUP(XfOrM46_COUNT)
      if (basetype_p == ((void * ) 0 ) ) {
#       define XfOrM50_COUNT (0+XfOrM46_COUNT)
#       define SETUP_XfOrM50(x) SETUP_XfOrM46(x)
        if (p == ((void * ) 0 ) && poff == 0 )
          FUNCCALL(SETUP_XfOrM50(_), scheme_signal_error ("FFI pointer value was NULL" ) ); 
        (memcpy (((char * ) (dst ) XFORM_OK_PLUS (delta ) ) , ((char * ) (p ) XFORM_OK_PLUS (poff ) ) , ((ffi_type * ) (((ctype_struct * ) (type ) ) -> scheme_to_c ) ) -> size ) ) ; 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      else {
        * basetype_p = (26 ) ; 
        if (_offset ) {
          * _offset = poff ; 
          RET_VALUE_START (p ) RET_VALUE_END ; 
        }
        else {
          RET_VALUE_START (((char * ) (p ) XFORM_OK_PLUS (poff ) ) ) RET_VALUE_END ; 
        }
      }
    }
    default : FUNCCALL(SETUP_XfOrM45(_), scheme_signal_error ("corrupt foreign type: %V" , type ) ); 
  }
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * foreign_ctype_sizeof (int argc , Scheme_Object * argv [] ) {
  int size ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM106_COUNT (1)
# define SETUP_XfOrM106(x) SETUP(XfOrM106_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  size = FUNCCALL(SETUP_XfOrM106(_), ctype_sizeof (argv [0 ] ) ); 
  if (size >= 0 )
    RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (size ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
  else FUNCCALL_EMPTY(scheme_wrong_type ("ctype-sizeof" , "C-type" , 0 , argc , argv ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * foreign_ctype_alignof (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * type ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(type, 0), PUSH(argv, 1)));
# define XfOrM107_COUNT (2)
# define SETUP_XfOrM107(x) SETUP(XfOrM107_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  type = NULLED_OUT ; 
  type = FUNCCALL(SETUP_XfOrM107(_), get_ctype_base (argv [0 ] ) ); 
  if (type == ((void * ) 0 ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("ctype-alignof" , "C-type" , 0 , argc , argv ) ); 
  else RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (((ffi_type * ) (((ctype_struct * ) (type ) ) -> scheme_to_c ) ) -> alignment ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * foreign_compiler_sizeof (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  int res = 0 ; 
  int basetype = 0 ; 
  int intsize = 0 ; 
  int stars = 0 ; 
  Scheme_Object * l = argv [0 ] , * p ; 
  while (! ((l ) == (scheme_null ) ) ) {
    if (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
      p = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
      l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
    }
    else {
      p = l ; 
      l = scheme_null ; 
    }
    if (! ((Scheme_Type ) (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
      scheme_wrong_type ("compiler-sizeof" , "list of symbols" , 0 , argc , argv ) ; 
    }
    else if (! strcmp ((((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (p ) ) ) -> s ) , "int" ) ) {
      if (basetype == 0 )
        basetype = 1 ; 
      else scheme_signal_error ("compiler-sizeof" ": extraneous type: %V" , p ) ; 
    }
    else if (! strcmp ((((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (p ) ) ) -> s ) , "char" ) ) {
      if (basetype == 0 )
        basetype = 2 ; 
      else scheme_signal_error ("compiler-sizeof" ": extraneous type: %V" , p ) ; 
    }
    else if (! strcmp ((((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (p ) ) ) -> s ) , "void" ) ) {
      if (basetype == 0 )
        basetype = 3 ; 
      else scheme_signal_error ("compiler-sizeof" ": extraneous type: %V" , p ) ; 
    }
    else if (! strcmp ((((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (p ) ) ) -> s ) , "float" ) ) {
      if (basetype == 0 )
        basetype = 4 ; 
      else scheme_signal_error ("compiler-sizeof" ": extraneous type: %V" , p ) ; 
    }
    else if (! strcmp ((((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (p ) ) ) -> s ) , "double" ) ) {
      if (basetype == 0 || basetype == 4 )
        basetype = 5 ; 
      else scheme_signal_error ("compiler-sizeof" ": extraneous type: %V" , p ) ; 
    }
    else if (! strcmp ((((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (p ) ) ) -> s ) , "short" ) ) {
      if (intsize > 0 )
        scheme_signal_error ("compiler-sizeof" ": cannot use both 'short and 'long" ) ; 
      else intsize -- ; 
    }
    else if (! strcmp ((((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (p ) ) ) -> s ) , "long" ) ) {
      if (intsize < 0 )
        scheme_signal_error ("compiler-sizeof" ": cannot use both 'short and 'long" ) ; 
      else intsize ++ ; 
    }
    else if (! strcmp ((((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (p ) ) ) -> s ) , "*" ) ) {
      stars ++ ; 
    }
    else {
      scheme_wrong_type ("compiler-sizeof" , "list of C type symbols" , 0 , argc , argv ) ; 
    }
  }
  if (stars > 1 )
    scheme_signal_error ("compiler-sizeof" ": cannot handle more than one '*" ) ; 
  if (intsize < - 1 )
    scheme_signal_error ("compiler-sizeof" ": cannot handle more than one 'short" ) ; 
  if (intsize > 2 )
    scheme_signal_error ("compiler-sizeof" ": cannot handle more than two 'long" ) ; 
  if (basetype == 0 )
    basetype = 1 ; 
  switch (basetype ) {
    case 1 : switch (intsize ) {
      case 0 : res = ((stars == 0 ) ? sizeof (int ) : sizeof (int * ) ) ; 
      break ; 
      case 1 : res = ((stars == 0 ) ? sizeof (long int ) : sizeof (long int * ) ) ; 
      break ; 
      case 2 : res = ((stars == 0 ) ? sizeof (long long int ) : sizeof (long long int * ) ) ; 
      break ; 
      case - 1 : res = ((stars == 0 ) ? sizeof (short int ) : sizeof (short int * ) ) ; 
      break ; 
    }
    break ; 
    case 2 : if (intsize == 0 )
      res = ((stars == 0 ) ? sizeof (char ) : sizeof (char * ) ) ; 
    else scheme_signal_error ("compiler-sizeof" ": cannot qualify 'char" ) ; 
    break ; 
    case 3 : if (intsize == 0 )
      res = ((stars == 0 ) ? sizeof (void ) : sizeof (void * ) ) ; 
    else scheme_signal_error ("compiler-sizeof" ": cannot qualify 'char" ) ; 
    break ; 
    case 4 : if (intsize == 0 )
      res = ((stars == 0 ) ? sizeof (float ) : sizeof (float * ) ) ; 
    else scheme_signal_error ("compiler-sizeof" ": bad qualifiers for 'float" ) ; 
    break ; 
    case 5 : if (intsize == 0 )
      res = ((stars == 0 ) ? sizeof (double ) : sizeof (double * ) ) ; 
    else if (intsize == 1 )
      res = ((stars == 0 ) ? sizeof (long double ) : sizeof (long double * ) ) ; 
    else scheme_signal_error ("compiler-sizeof" ": bad qualifiers for 'double" ) ; 
    break ; 
    default : scheme_signal_error ("compiler-sizeof" ": internal error (unexpected type %d)" , basetype ) ; 
  }
  return ((Scheme_Object * ) (void * ) (long ) ((((long ) (res ) ) << 1 ) | 0x1 ) ) ; 
}
static Scheme_Object * nonatomic_sym ; 
static Scheme_Object * atomic_sym ; 
static Scheme_Object * stubborn_sym ; 
static Scheme_Object * uncollectable_sym ; 
static Scheme_Object * eternal_sym ; 
static Scheme_Object * interior_sym ; 
static Scheme_Object * atomic_interior_sym ; 
static Scheme_Object * raw_sym ; 
static Scheme_Object * fail_ok_sym ; 
static Scheme_Object * foreign_malloc (int argc , Scheme_Object * argv [] ) {
  int i , size = 0 , num = 0 , failok = 0 ; 
  void * from = ((void * ) 0 ) , * res = ((void * ) 0 ) ; 
  long foff = 0 ; 
  Scheme_Object * mode = ((void * ) 0 ) , * a , * base = ((void * ) 0 ) ; 
  void * (* mf ) (size_t ) ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(base, 0), PUSH(from, 1), PUSH(a, 2), PUSH(res, 3), PUSH(mode, 4), PUSH(argv, 5)));
# define XfOrM137_COUNT (6)
# define SETUP_XfOrM137(x) SETUP(XfOrM137_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a = NULLED_OUT ; 
  for (i = 0 ; i < argc ; i ++ ) {
#   define XfOrM146_COUNT (0+XfOrM137_COUNT)
#   define SETUP_XfOrM146(x) SETUP_XfOrM137(x)
    a = argv [i ] ; 
    if ((((long ) (a ) ) & 0x1 ) ) {
#     define XfOrM152_COUNT (0+XfOrM146_COUNT)
#     define SETUP_XfOrM152(x) SETUP_XfOrM146(x)
      if (num != 0 )
        FUNCCALL_EMPTY(scheme_signal_error ("malloc" ": specifying a second integer size: %V" , a ) ); 
      num = (((long ) (a ) ) >> 1 ) ; 
      if (num <= 0 )
        FUNCCALL_EMPTY(scheme_wrong_type ("malloc" , "positive-integer" , 0 , argc , argv ) ); 
    }
    else if ((((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) == ctype_tag ) ) {
#     define XfOrM151_COUNT (0+XfOrM146_COUNT)
#     define SETUP_XfOrM151(x) SETUP_XfOrM146(x)
      if (size != 0 )
        FUNCCALL_EMPTY(scheme_signal_error ("malloc" ": specifying a second type: %V" , a ) ); 
      if (((void * ) 0 ) == (base = FUNCCALL(SETUP_XfOrM151(_), get_ctype_base (a ) )) )
        FUNCCALL_EMPTY(scheme_wrong_type ("malloc" , "C-type" , i , argc , argv ) ); 
      size = FUNCCALL(SETUP_XfOrM151(_), ctype_sizeof (a ) ); 
      if (size <= 0 )
        FUNCCALL_EMPTY(scheme_wrong_type ("malloc" , "non-void-C-type" , i , argc , argv ) ); 
    }
    else if (((a ) == (fail_ok_sym ) ) ) {
      failok = 1 ; 
    }
    else if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
#     define XfOrM149_COUNT (0+XfOrM146_COUNT)
#     define SETUP_XfOrM149(x) SETUP_XfOrM146(x)
      if (mode != ((void * ) 0 ) )
        FUNCCALL_EMPTY(scheme_signal_error ("malloc" ": specifying a second mode symbol: %V" , a ) ); 
      mode = a ; 
    }
    else if (((((a ) ) == (scheme_false ) ) || (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) || (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) == ffi_obj_tag ) || ((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ) && ! (((a ) ) == (scheme_false ) ) ) {
#     define XfOrM148_COUNT (0+XfOrM146_COUNT)
#     define SETUP_XfOrM148(x) SETUP_XfOrM146(x)
      if (from != ((void * ) 0 ) )
        FUNCCALL_EMPTY(scheme_signal_error ("malloc" ": specifying a second source pointer: %V" , a ) ); 
      from = ((((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Cptr * ) (a ) ) -> val ) : ((((a ) ) == (scheme_false ) ) ? ((void * ) 0 ) : ((((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) == ffi_obj_tag ) ? (((ffi_obj_struct * ) a ) -> obj ) : ((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ? (((Scheme_Simple_Object * ) (a ) ) -> u . byte_str_val . string_val ) : ((void * ) 0 ) ) ) ) ; 
      foff = ((((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Type ) (((a ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ? ((Scheme_Offset_Cptr * ) a ) -> offset : 0 ) : 0 ) ; 
    }
    else {
#     define XfOrM147_COUNT (0+XfOrM146_COUNT)
#     define SETUP_XfOrM147(x) SETUP_XfOrM146(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("malloc" , "malloc-argument" , i , argc , argv ) ); 
    }
  }
  if ((num == 0 ) && (size == 0 ) )
    FUNCCALL_EMPTY(scheme_signal_error ("malloc" ": no size given" ) ); 
  size = ((size == 0 ) ? 1 : size ) * ((num == 0 ) ? 1 : num ) ; 
  if (mode == ((void * ) 0 ) )
    mf = (base != ((void * ) 0 ) && ((ffi_type * ) (((ctype_struct * ) (base ) ) -> scheme_to_c ) ) == & ffi_type_pointer ) ? GC_malloc : GC_malloc_atomic ; 
  else if (((mode ) == (nonatomic_sym ) ) )
    mf = GC_malloc ; 
  else if (((mode ) == (atomic_sym ) ) )
    mf = GC_malloc_atomic ; 
  else if (((mode ) == (stubborn_sym ) ) )
    mf = GC_malloc ; 
  else if (((mode ) == (eternal_sym ) ) )
    mf = scheme_malloc_eternal ; 
  else if (((mode ) == (uncollectable_sym ) ) )
    mf = scheme_malloc_uncollectable ; 
  else if (((mode ) == (interior_sym ) ) )
    mf = GC_malloc_allow_interior ; 
  else if (((mode ) == (atomic_interior_sym ) ) )
    mf = GC_malloc_allow_interior ; 
  else if (((mode ) == (raw_sym ) ) )
    mf = malloc ; 
  else {
#   define XfOrM138_COUNT (0+XfOrM137_COUNT)
#   define SETUP_XfOrM138(x) SETUP_XfOrM137(x)
    FUNCCALL_EMPTY(scheme_signal_error ("malloc" ": bad allocation mode: %V" , mode ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (failok )
    res = FUNCCALL(SETUP_XfOrM137(_), scheme_malloc_fail_ok (mf , size ) ); 
  else res = FUNCCALL(SETUP_XfOrM137(_), mf (size ) ); 
  if (((from != ((void * ) 0 ) ) || (foff != 0 ) ) && (res != ((void * ) 0 ) ) )
    (memcpy (res , ((char * ) (from ) XFORM_OK_PLUS (foff ) ) , size ) ) ; 
  RET_VALUE_START (((res == ((void * ) 0 ) ) ? scheme_false : FUNCCALL_EMPTY(scheme_make_cptr (res , ((void * ) 0 ) ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * foreign_end_stubborn_change (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  void * ptr ; 
  long poff ; 
  if (! ((((argv [0 ] ) ) == (scheme_false ) ) || (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) || (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ffi_obj_tag ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ) )
    scheme_wrong_type ("end-stubborn-change" , "cpointer" , 0 , argc , argv ) ; 
  ptr = ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Cptr * ) (argv [0 ] ) ) -> val ) : ((((argv [0 ] ) ) == (scheme_false ) ) ? ((void * ) 0 ) : ((((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ffi_obj_tag ) ? (((ffi_obj_struct * ) argv [0 ] ) -> obj ) : ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ? (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) : ((void * ) 0 ) ) ) ) ; 
  poff = ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Type ) (((argv [0 ] ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ? ((Scheme_Offset_Cptr * ) argv [0 ] ) -> offset : 0 ) : 0 ) ; 
  if ((ptr == ((void * ) 0 ) ) && (poff == 0 ) )
    scheme_wrong_type ("end-stubborn-change" , "non-null-cpointer" , 0 , argc , argv ) ; 
  scheme_end_stubborn_change (((char * ) (ptr ) XFORM_OK_PLUS (poff ) ) ) ; 
  return scheme_void ; 
}
static Scheme_Object * foreign_free (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  void * ptr ; 
  long poff ; 
  if (! ((((argv [0 ] ) ) == (scheme_false ) ) || (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) || (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ffi_obj_tag ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ) )
    scheme_wrong_type ("free" , "cpointer" , 0 , argc , argv ) ; 
  ptr = ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Cptr * ) (argv [0 ] ) ) -> val ) : ((((argv [0 ] ) ) == (scheme_false ) ) ? ((void * ) 0 ) : ((((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ffi_obj_tag ) ? (((ffi_obj_struct * ) argv [0 ] ) -> obj ) : ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ? (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) : ((void * ) 0 ) ) ) ) ; 
  poff = ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Type ) (((argv [0 ] ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ? ((Scheme_Offset_Cptr * ) argv [0 ] ) -> offset : 0 ) : 0 ) ; 
  if ((ptr == ((void * ) 0 ) ) && (poff == 0 ) )
    scheme_wrong_type ("free" , "non-null-cpointer" , 0 , argc , argv ) ; 
  free (((char * ) (ptr ) XFORM_OK_PLUS (poff ) ) ) ; 
  return scheme_void ; 
}
static Scheme_Object * foreign_malloc_immobile_cell (int argc , Scheme_Object * argv [] ) {
  void * * __funcarg51 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM155_COUNT (1)
# define SETUP_XfOrM155(x) SETUP(XfOrM155_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START (((FUNCCALL(SETUP_XfOrM155(_), scheme_malloc_immobile_box (argv [0 ] ) )== ((void * ) 0 ) ) ? scheme_false : (__funcarg51 = FUNCCALL_EMPTY(scheme_malloc_immobile_box (argv [0 ] ) ), FUNCCALL_EMPTY(scheme_make_cptr (__funcarg51 , ((void * ) 0 ) ) )) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * foreign_free_immobile_cell (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  void * ptr ; 
  long poff ; 
  if (! ((((argv [0 ] ) ) == (scheme_false ) ) || (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) || (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ffi_obj_tag ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ) )
    scheme_wrong_type ("free-immobile-cell" , "cpointer" , 0 , argc , argv ) ; 
  ptr = ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Cptr * ) (argv [0 ] ) ) -> val ) : ((((argv [0 ] ) ) == (scheme_false ) ) ? ((void * ) 0 ) : ((((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ffi_obj_tag ) ? (((ffi_obj_struct * ) argv [0 ] ) -> obj ) : ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ? (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) : ((void * ) 0 ) ) ) ) ; 
  poff = ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Type ) (((argv [0 ] ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ? ((Scheme_Offset_Cptr * ) argv [0 ] ) -> offset : 0 ) : 0 ) ; 
  if ((ptr == ((void * ) 0 ) ) && (poff == 0 ) )
    scheme_wrong_type ("free-immobile-cell" , "non-null-cpointer" , 0 , argc , argv ) ; 
  scheme_free_immobile_box ((void * * ) ((char * ) (ptr ) XFORM_OK_PLUS (poff ) ) ) ; 
  return scheme_void ; 
}
/* this far 1900 */
static Scheme_Object * do_ptr_add (const char * who , int is_bang , int argc , Scheme_Object * * argv ) {
  long noff ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(who, 1)));
# define XfOrM157_COUNT (2)
# define SETUP_XfOrM157(x) SETUP(XfOrM157_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (is_bang ) {
#   define XfOrM163_COUNT (0+XfOrM157_COUNT)
#   define SETUP_XfOrM163(x) SETUP_XfOrM157(x)
    if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type (who , "offset-cpointer" , 0 , argc , argv ) ); 
  }
  else {
#   define XfOrM162_COUNT (0+XfOrM157_COUNT)
#   define SETUP_XfOrM162(x) SETUP_XfOrM157(x)
    if (! ((((argv [0 ] ) ) == (scheme_false ) ) || (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) || (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ffi_obj_tag ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type (who , "cpointer" , 0 , argc , argv ) ); 
  }
  if (! (scheme_get_int_val (argv [1 ] , & noff ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type (who , "exact integer that fits a C long" , 1 , argc , argv ) ); 
  if (argc > 2 ) {
#   define XfOrM160_COUNT (0+XfOrM157_COUNT)
#   define SETUP_XfOrM160(x) SETUP_XfOrM157(x)
    if ((((((long ) (argv [2 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [2 ] ) ) -> type ) == ctype_tag ) ) {
      long size ; 
#     define XfOrM161_COUNT (0+XfOrM160_COUNT)
#     define SETUP_XfOrM161(x) SETUP_XfOrM160(x)
      size = FUNCCALL(SETUP_XfOrM161(_), ctype_sizeof (argv [2 ] ) ); 
      if (size <= 0 )
        FUNCCALL_EMPTY(scheme_wrong_type (who , "non-void-C-type" , 2 , argc , argv ) ); 
      noff = noff * size ; 
    }
    else FUNCCALL_EMPTY(scheme_wrong_type (who , "C-type" , 2 , argc , argv ) ); 
  }
  if (is_bang ) {
    ((Scheme_Offset_Cptr * ) (argv [0 ] ) ) -> offset += noff ; 
    RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM158_COUNT (0+XfOrM157_COUNT)
#   define SETUP_XfOrM158(x) SETUP_XfOrM157(x)
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_offset_cptr (((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Cptr * ) (argv [0 ] ) ) -> val ) : ((((argv [0 ] ) ) == (scheme_false ) ) ? ((void * ) 0 ) : ((((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ffi_obj_tag ) ? (((ffi_obj_struct * ) argv [0 ] ) -> obj ) : ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ? (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) : ((void * ) 0 ) ) ) ) , ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Type ) (((argv [0 ] ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ? ((Scheme_Offset_Cptr * ) argv [0 ] ) -> offset : 0 ) : 0 ) + noff , ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ) ? (((Scheme_Cptr * ) (argv [0 ] ) ) -> type ) : ((void * ) 0 ) ) )) RET_VALUE_EMPTY_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * foreign_ptr_add (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_ptr_add ("ptr-add" , 0 , argc , argv ) ; 
}
static Scheme_Object * foreign_ptr_add_bang (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_ptr_add ("ptr-add!" , 1 , argc , argv ) ; 
}
static Scheme_Object * foreign_offset_ptr_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? scheme_true : scheme_false ; 
}
static Scheme_Object * foreign_ptr_offset (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((((argv [0 ] ) ) == (scheme_false ) ) || (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) || (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ffi_obj_tag ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ) )
    scheme_wrong_type ("ptr-offset" , "cpointer" , 0 , argc , argv ) ; 
  return scheme_make_integer_value (((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Type ) (((argv [0 ] ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ? ((Scheme_Offset_Cptr * ) argv [0 ] ) -> offset : 0 ) : 0 ) ) ; 
}
static Scheme_Object * foreign_set_ptr_offset_bang (int argc , Scheme_Object * argv [] ) {
  long noff ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM168_COUNT (1)
# define SETUP_XfOrM168(x) SETUP(XfOrM168_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("set-ptr-offset!" , "offset-cpointer" , 0 , argc , argv ) ); 
  if (! (scheme_get_int_val (argv [1 ] , & noff ) ) ) {
#   define XfOrM171_COUNT (0+XfOrM168_COUNT)
#   define SETUP_XfOrM171(x) SETUP_XfOrM168(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("set-ptr-offset!" , "exact integer that fits a C long" , 1 , argc , argv ) ); 
  }
  if (argc > 2 ) {
#   define XfOrM169_COUNT (0+XfOrM168_COUNT)
#   define SETUP_XfOrM169(x) SETUP_XfOrM168(x)
    if ((((((long ) (argv [2 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [2 ] ) ) -> type ) == ctype_tag ) ) {
      long size ; 
#     define XfOrM170_COUNT (0+XfOrM169_COUNT)
#     define SETUP_XfOrM170(x) SETUP_XfOrM169(x)
      if (((void * ) 0 ) == FUNCCALL(SETUP_XfOrM170(_), get_ctype_base (argv [2 ] ) ))
        FUNCCALL_EMPTY(scheme_wrong_type ("set-ptr-offset!" , "C-type" , 2 , argc , argv ) ); 
      size = FUNCCALL(SETUP_XfOrM170(_), ctype_sizeof (argv [2 ] ) ); 
      if (size <= 0 )
        FUNCCALL_EMPTY(scheme_wrong_type ("set-ptr-offset!" , "non-void-C-type" , 2 , argc , argv ) ); 
      noff = noff * size ; 
    }
    else FUNCCALL_EMPTY(scheme_wrong_type ("set-ptr-offset!" , "C-type" , 2 , argc , argv ) ); 
  }
  ((Scheme_Offset_Cptr * ) (argv [0 ] ) ) -> offset = noff ; 
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_memop (const char * who , int mode , int argc , Scheme_Object * * argv ) {
  void * src = ((void * ) 0 ) , * dest = ((void * ) 0 ) ; 
  long soff = 0 , doff = 0 , count , v , mult = 0 ; 
  int i , j , ch = 0 , argc1 = argc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(dest, 0), PUSH(src, 1), PUSH(argv, 2), PUSH(who, 3)));
# define XfOrM172_COUNT (4)
# define SETUP_XfOrM172(x) SETUP(XfOrM172_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if ((((((long ) (argv [argc1 - 1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [argc1 - 1 ] ) ) -> type ) == ctype_tag ) ) {
    argc1 -- ; 
#   define XfOrM183_COUNT (0+XfOrM172_COUNT)
#   define SETUP_XfOrM183(x) SETUP_XfOrM172(x)
    mult = FUNCCALL(SETUP_XfOrM183(_), ctype_sizeof (argv [argc1 ] ) ); 
    if (mult <= 0 )
      FUNCCALL_EMPTY(scheme_wrong_type (who , "non-void-C-type" , argc1 , argc , argv ) ); 
  }
  argc1 -- ; 
  if ((! (scheme_get_int_val (argv [argc1 ] , & count ) ) ) || (count < 0 ) )
    FUNCCALL_EMPTY(scheme_wrong_type (who , "count as " "exact integer that fits a C long" , argc1 , argc , argv ) ); 
  if (mult )
    count *= mult ; 
  if (! mode ) {
    argc1 -- ; 
#   define XfOrM182_COUNT (0+XfOrM172_COUNT)
#   define SETUP_XfOrM182(x) SETUP_XfOrM172(x)
    ch = (((long ) (argv [argc1 ] ) ) & 0x1 ) ? (((long ) (argv [argc1 ] ) ) >> 1 ) : - 1 ; 
    if ((ch < 0 ) || (ch > 255 ) )
      FUNCCALL_EMPTY(scheme_wrong_type (who , "byte" , argc1 , argc , argv ) ); 
  }
  i = 0 ; 
  for (j = 0 ; j < 2 ; j ++ ) {
#   define XfOrM178_COUNT (0+XfOrM172_COUNT)
#   define SETUP_XfOrM178(x) SETUP_XfOrM172(x)
    if (! mode && j == 1 )
      break ; 
    if (! (i < argc1 ) )
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: missing a pointer argument for %s" , who , (j == 0 ? "destination" : "source" ) ) ); 
    if (! ((((argv [i ] ) ) == (scheme_false ) ) || (((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) || (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) == ffi_obj_tag ) || ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type (who , "cpointer" , i , argc , argv ) ); 
    switch (j ) {
      case 0 : dest = ((((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Cptr * ) (argv [i ] ) ) -> val ) : ((((argv [i ] ) ) == (scheme_false ) ) ? ((void * ) 0 ) : ((((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) == ffi_obj_tag ) ? (((ffi_obj_struct * ) argv [i ] ) -> obj ) : ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ? (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . byte_str_val . string_val ) : ((void * ) 0 ) ) ) ) ; 
      doff = ((((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Type ) (((argv [i ] ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ? ((Scheme_Offset_Cptr * ) argv [i ] ) -> offset : 0 ) : 0 ) ; 
      break ; 
      case 1 : src = ((((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Cptr * ) (argv [i ] ) ) -> val ) : ((((argv [i ] ) ) == (scheme_false ) ) ? ((void * ) 0 ) : ((((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) == ffi_obj_tag ) ? (((ffi_obj_struct * ) argv [i ] ) -> obj ) : ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ? (((Scheme_Simple_Object * ) (argv [i ] ) ) -> u . byte_str_val . string_val ) : ((void * ) 0 ) ) ) ) ; 
      soff = ((((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Type ) (((argv [i ] ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ? ((Scheme_Offset_Cptr * ) argv [i ] ) -> offset : 0 ) : 0 ) ; 
      break ; 
    }
    i ++ ; 
    if ((i < argc1 ) && ((((long ) (argv [i ] ) ) & 0x1 ) || (((argv [i ] ) -> type ) == scheme_bignum_type ) ) ) {
#     define XfOrM179_COUNT (0+XfOrM178_COUNT)
#     define SETUP_XfOrM179(x) SETUP_XfOrM178(x)
      if (! (scheme_get_int_val (argv [i ] , & v ) ) )
        FUNCCALL_EMPTY(scheme_wrong_type (who , "exact integer that fits a C long" , i , argc , argv ) ); 
      if (mult )
        v *= mult ; 
      switch (j ) {
        case 0 : doff += v ; 
        break ; 
        case 1 : soff += v ; 
        break ; 
      }
      i ++ ; 
    }
  }
  if (! (i == argc1 ) )
    FUNCCALL(SETUP_XfOrM172(_), scheme_arg_mismatch (who , "unexpected extra argument: " , argv [i ] ) ); 
  switch (mode ) {
#   define XfOrM173_COUNT (0+XfOrM172_COUNT)
#   define SETUP_XfOrM173(x) SETUP_XfOrM172(x)
    case 0 : (memset (((char * ) (dest ) XFORM_OK_PLUS (doff ) ) , ch , count ) ) ; 
    break ; 
    case 1 : (memmove (((char * ) (dest ) XFORM_OK_PLUS (doff ) ) , ((char * ) (src ) XFORM_OK_PLUS (soff ) ) , count ) ) ; 
    break ; 
    case 2 : (memcpy (((char * ) (dest ) XFORM_OK_PLUS (doff ) ) , ((char * ) (src ) XFORM_OK_PLUS (soff ) ) , count ) ) ; 
    break ; 
  }
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * foreign_memset (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_memop ("memset" , 0 , argc , argv ) ; 
}
static Scheme_Object * foreign_memmove (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_memop ("memmove" , 1 , argc , argv ) ; 
}
static Scheme_Object * foreign_memcpy (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_memop ("memcpy" , 2 , argc , argv ) ; 
}
static Scheme_Object * abs_sym ; 
static Scheme_Object * foreign_ptr_ref (int argc , Scheme_Object * argv [] ) {
  int size = 0 ; 
  void * ptr ; 
  Scheme_Object * base ; 
  long delta ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(base, 0), PUSH(ptr, 1), PUSH(argv, 2)));
# define XfOrM187_COUNT (3)
# define SETUP_XfOrM187(x) SETUP(XfOrM187_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ptr = NULLED_OUT ; 
  base = NULLED_OUT ; 
  if (! ((((argv [0 ] ) ) == (scheme_false ) ) || (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) || (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ffi_obj_tag ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("ptr-ref" , "cpointer" , 0 , argc , argv ) ); 
  ptr = ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Cptr * ) (argv [0 ] ) ) -> val ) : ((((argv [0 ] ) ) == (scheme_false ) ) ? ((void * ) 0 ) : ((((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ffi_obj_tag ) ? (((ffi_obj_struct * ) argv [0 ] ) -> obj ) : ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ? (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) : ((void * ) 0 ) ) ) ) ; 
  delta = ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Type ) (((argv [0 ] ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ? ((Scheme_Offset_Cptr * ) argv [0 ] ) -> offset : 0 ) : 0 ) ; 
  if ((ptr == ((void * ) 0 ) ) && (delta == 0 ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("ptr-ref" , "non-null-cpointer" , 0 , argc , argv ) ); 
  if (((void * ) 0 ) == (base = FUNCCALL(SETUP_XfOrM187(_), get_ctype_base (argv [1 ] ) )) )
    FUNCCALL_EMPTY(scheme_wrong_type ("ptr-ref" , "C-type" , 1 , argc , argv ) ); 
  else size = FUNCCALL(SETUP_XfOrM187(_), ctype_sizeof (base ) ); 
  if (((long ) (((ctype_struct * ) (base ) ) -> c_to_scheme ) ) == (25 ) ) {
#   define XfOrM192_COUNT (0+XfOrM187_COUNT)
#   define SETUP_XfOrM192(x) SETUP_XfOrM187(x)
    if (argc > 2 )
      FUNCCALL_EMPTY(scheme_signal_error ("ptr-ref" ": referencing fpointer with extra arguments" ) ); 
    else ptr = argv [0 ] ; 
  }
  else if (size < 0 ) {
#   define XfOrM191_COUNT (0+XfOrM187_COUNT)
#   define SETUP_XfOrM191(x) SETUP_XfOrM187(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("ptr-ref" , "C-type" , 1 , argc , argv ) ); 
  }
  else if (size == 0 ) {
#   define XfOrM190_COUNT (0+XfOrM187_COUNT)
#   define SETUP_XfOrM190(x) SETUP_XfOrM187(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("ptr-ref" , "non-void-C-type" , 1 , argc , argv ) ); 
  }
  else if (argc > 3 ) {
#   define XfOrM189_COUNT (0+XfOrM187_COUNT)
#   define SETUP_XfOrM189(x) SETUP_XfOrM187(x)
    if (! ((argv [2 ] ) == (abs_sym ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("ptr-ref" , "abs-flag" , 2 , argc , argv ) ); 
    if (! (((long ) (argv [3 ] ) ) & 0x1 ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("ptr-ref" , "integer" , 3 , argc , argv ) ); 
    delta += (((long ) (argv [3 ] ) ) >> 1 ) ; 
  }
  else if (argc > 2 ) {
#   define XfOrM188_COUNT (0+XfOrM187_COUNT)
#   define SETUP_XfOrM188(x) SETUP_XfOrM187(x)
    if (! (((long ) (argv [2 ] ) ) & 0x1 ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("ptr-ref" , "integer" , 2 , argc , argv ) ); 
    delta += (size * (((long ) (argv [2 ] ) ) >> 1 ) ) ; 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(c_to_scheme (argv [1 ] , ptr , delta ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * foreign_ptr_set_bang (int argc , Scheme_Object * argv [] ) {
  int size = 0 ; 
  void * ptr ; 
  long delta ; 
  Scheme_Object * val = argv [argc - 1 ] , * base ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(val, 0), PUSH(base, 1), PUSH(ptr, 2), PUSH(argv, 3)));
# define XfOrM193_COUNT (4)
# define SETUP_XfOrM193(x) SETUP(XfOrM193_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ptr = NULLED_OUT ; 
  base = NULLED_OUT ; 
  if (! ((((argv [0 ] ) ) == (scheme_false ) ) || (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) || (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ffi_obj_tag ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("ptr-set!" , "cpointer" , 0 , argc , argv ) ); 
  ptr = ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Cptr * ) (argv [0 ] ) ) -> val ) : ((((argv [0 ] ) ) == (scheme_false ) ) ? ((void * ) 0 ) : ((((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ffi_obj_tag ) ? (((ffi_obj_struct * ) argv [0 ] ) -> obj ) : ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ? (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) : ((void * ) 0 ) ) ) ) ; 
  delta = ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Type ) (((argv [0 ] ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ? ((Scheme_Offset_Cptr * ) argv [0 ] ) -> offset : 0 ) : 0 ) ; 
  if ((ptr == ((void * ) 0 ) ) && (delta == 0 ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("ptr-set!" , "non-null-cpointer" , 0 , argc , argv ) ); 
  if (((void * ) 0 ) == (base = FUNCCALL(SETUP_XfOrM193(_), get_ctype_base (argv [1 ] ) )) )
    FUNCCALL_EMPTY(scheme_wrong_type ("ptr-set!" , "C-type" , 1 , argc , argv ) ); 
  else size = FUNCCALL(SETUP_XfOrM193(_), ctype_sizeof (base ) ); 
  if (((long ) (((ctype_struct * ) (base ) ) -> c_to_scheme ) ) == (25 ) ) {
#   define XfOrM198_COUNT (0+XfOrM193_COUNT)
#   define SETUP_XfOrM198(x) SETUP_XfOrM193(x)
    if (argc > 3 ) {
#     define XfOrM202_COUNT (0+XfOrM198_COUNT)
#     define SETUP_XfOrM202(x) SETUP_XfOrM198(x)
      FUNCCALL_EMPTY(scheme_signal_error ("ptr-set!" ": setting fpointer value with extra arguments" ) ); 
    }
    else if ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ) {
      ptr = (((Scheme_Cptr * ) (argv [0 ] ) ) -> val ) ; 
    }
    else if (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ffi_obj_tag ) {
      ptr = ((ffi_obj_struct * ) (argv [0 ] ) ) -> obj ; 
    }
    else {
#     define XfOrM199_COUNT (0+XfOrM198_COUNT)
#     define SETUP_XfOrM199(x) SETUP_XfOrM198(x)
      FUNCCALL_EMPTY(scheme_signal_error ("ptr-set!" ": bad lvalue (NULL or string)" ) ); 
    }
  }
  else if (size < 0 ) {
#   define XfOrM197_COUNT (0+XfOrM193_COUNT)
#   define SETUP_XfOrM197(x) SETUP_XfOrM193(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("ptr-set!" , "C-type" , 1 , argc , argv ) ); 
  }
  else if (size == 0 ) {
#   define XfOrM196_COUNT (0+XfOrM193_COUNT)
#   define SETUP_XfOrM196(x) SETUP_XfOrM193(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("ptr-set!" , "non-void-C-type" , 1 , argc , argv ) ); 
  }
  else if (argc > 4 ) {
#   define XfOrM195_COUNT (0+XfOrM193_COUNT)
#   define SETUP_XfOrM195(x) SETUP_XfOrM193(x)
    if (! ((argv [2 ] ) == (abs_sym ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("ptr-set!" , "abs-flag" , 2 , argc , argv ) ); 
    if (! (((long ) (argv [3 ] ) ) & 0x1 ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("ptr-set!" , "integer" , 3 , argc , argv ) ); 
    delta += (((long ) (argv [3 ] ) ) >> 1 ) ; 
  }
  else if (argc > 3 ) {
#   define XfOrM194_COUNT (0+XfOrM193_COUNT)
#   define SETUP_XfOrM194(x) SETUP_XfOrM193(x)
    if (! (((long ) (argv [2 ] ) ) & 0x1 ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("ptr-set!" , "integer" , 2 , argc , argv ) ); 
    delta += (size * (((long ) (argv [2 ] ) ) >> 1 ) ) ; 
  }
  FUNCCALL_EMPTY(scheme_to_c (argv [1 ] , ptr , delta , val , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * foreign_ptr_equal_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((((argv [0 ] ) ) == (scheme_false ) ) || (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) || (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ffi_obj_tag ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ) )
    scheme_wrong_type ("ptr-equal?" , "cpointer" , 0 , argc , argv ) ; 
  if (! ((((argv [1 ] ) ) == (scheme_false ) ) || (((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) || (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) == ffi_obj_tag ) || ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ) )
    scheme_wrong_type ("ptr-equal?" , "cpointer" , 1 , argc , argv ) ; 
  return (((argv [0 ] ) == (argv [1 ] ) ) || (((char * ) (((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Cptr * ) (argv [0 ] ) ) -> val ) : ((((argv [0 ] ) ) == (scheme_false ) ) ? ((void * ) 0 ) : ((((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ffi_obj_tag ) ? (((ffi_obj_struct * ) argv [0 ] ) -> obj ) : ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ? (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) : ((void * ) 0 ) ) ) ) ) XFORM_OK_PLUS (((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Type ) (((argv [0 ] ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ? ((Scheme_Offset_Cptr * ) argv [0 ] ) -> offset : 0 ) : 0 ) ) ) == ((char * ) (((((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Cptr * ) (argv [1 ] ) ) -> val ) : ((((argv [1 ] ) ) == (scheme_false ) ) ? ((void * ) 0 ) : ((((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) == ffi_obj_tag ) ? (((ffi_obj_struct * ) argv [1 ] ) -> obj ) : ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ? (((Scheme_Simple_Object * ) (argv [1 ] ) ) -> u . byte_str_val . string_val ) : ((void * ) 0 ) ) ) ) ) XFORM_OK_PLUS (((((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Type ) (((argv [1 ] ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ? ((Scheme_Offset_Cptr * ) argv [1 ] ) -> offset : 0 ) : 0 ) ) ) ) ) ? scheme_true : scheme_false ; 
}
static Scheme_Object * foreign_make_sized_byte_string (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  long len ; 
  if (! ((((argv [0 ] ) ) == (scheme_false ) ) || (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) || (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ffi_obj_tag ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ) )
    scheme_wrong_type ("make-sized-byte-string" , "cpointer" , 0 , argc , argv ) ; 
  if (! scheme_get_int_val (argv [1 ] , & len ) )
    scheme_wrong_type ("make-sized-byte-string" , "integer in a C long range" , 1 , argc , argv ) ; 
  if ((((argv [0 ] ) ) == (scheme_false ) ) )
    return scheme_false ; 
  else return scheme_make_sized_byte_string (((char * ) (((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Cptr * ) (argv [0 ] ) ) -> val ) : ((((argv [0 ] ) ) == (scheme_false ) ) ? ((void * ) 0 ) : ((((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ffi_obj_tag ) ? (((ffi_obj_struct * ) argv [0 ] ) -> obj ) : ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ? (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) : ((void * ) 0 ) ) ) ) ) XFORM_OK_PLUS (((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Type ) (((argv [0 ] ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ? ((Scheme_Offset_Cptr * ) argv [0 ] ) -> offset : 0 ) : 0 ) ) ) , len , 0 ) ; 
}
void do_scm_finalizer (void * p , void * finalizer ) {
  Scheme_Object * f = (Scheme_Object * ) finalizer ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(p, 0)));
# define XfOrM205_COUNT (1)
# define SETUP_XfOrM205(x) SETUP(XfOrM205_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! (((f ) ) == (scheme_false ) ) )
    FUNCCALL(SETUP_XfOrM205(_), scheme_do_eval (f , 1 , (Scheme_Object * * ) (void * ) (& p ) , 1 ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void do_ptr_finalizer (void * p , void * finalizer ) {
  Scheme_Object * f = (Scheme_Object * ) finalizer ; 
  Scheme_Object * ptr ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(f, 0), PUSH(ptr, 1)));
# define XfOrM206_COUNT (2)
# define SETUP_XfOrM206(x) SETUP(XfOrM206_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ptr = NULLED_OUT ; 
  if (p == ((void * ) 0 ) )
    RET_NOTHING ; 
  ptr = FUNCCALL(SETUP_XfOrM206(_), scheme_make_cptr (p , ((void * ) 0 ) ) ); 
  if (! (((f ) ) == (scheme_false ) ) )
    FUNCCALL(SETUP_XfOrM206(_), scheme_do_eval (f , 1 , (Scheme_Object * * ) (& ptr ) , 1 ) ); 
  (((Scheme_Cptr * ) (ptr ) ) -> val ) = ((void * ) 0 ) ; 
  ptr = ((void * ) 0 ) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * ffi_do_call (void * data , int argc , Scheme_Object * argv [] ) {
  void * c_func = (void * ) ((((Scheme_Vector * ) (data ) ) -> els ) [1 ] ) ; 
  Scheme_Object * itypes = (((Scheme_Vector * ) (data ) ) -> els ) [2 ] ; 
  Scheme_Object * otype = (((Scheme_Vector * ) (data ) ) -> els ) [3 ] ; 
  Scheme_Object * base ; 
  ffi_cif * cif = (ffi_cif * ) ((((Scheme_Vector * ) (data ) ) -> els ) [4 ] ) ; 
  long cfoff = (((long ) ((((Scheme_Vector * ) (data ) ) -> els ) [5 ] ) ) >> 1 ) ; 
  int nargs = cif -> nargs ; 
  GC_CAN_IGNORE ForeignAny * ivals , oval ; 
  void * * avalues , * p , * newp , * tmp ; 
  GC_CAN_IGNORE ForeignAny stack_ivals [16 ] ; 
  void * stack_avalues [16 ] ; 
  long stack_offsets [16 ] ; 
  int i ; 
  long basetype , offset , * offsets ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(14);
  BLOCK_SETUP_TOP((PUSH(tmp, 0), PUSH(offsets, 1), PUSH(avalues, 2), PUSH(cif, 3), PUSH(newp, 4), PUSH(itypes, 5), PUSHARRAY(stack_avalues, 16, 6), PUSH(base, 9), PUSH(c_func, 10), PUSH(p, 11), PUSH(otype, 12), PUSH(argv, 13)));
# define XfOrM207_COUNT (14)
# define SETUP_XfOrM207(x) SETUP(XfOrM207_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  base = NULLED_OUT ; 
  avalues = NULLED_OUT ; 
  p = NULLED_OUT ; 
  newp = NULLED_OUT ; 
  tmp = NULLED_OUT ; 
  NULL_OUT_ARRAY (stack_avalues ) ; 
  offsets = NULLED_OUT ; 
  if (nargs <= 16 ) {
    ivals = stack_ivals ; 
    avalues = stack_avalues ; 
    offsets = stack_offsets ; 
  }
  else {
#   define XfOrM226_COUNT (0+XfOrM207_COUNT)
#   define SETUP_XfOrM226(x) SETUP_XfOrM207(x)
    ivals = FUNCCALL(SETUP_XfOrM226(_), malloc (nargs * sizeof (ForeignAny ) ) ); 
    avalues = FUNCCALL(SETUP_XfOrM226(_), GC_malloc (nargs * sizeof (void * ) ) ); 
    offsets = FUNCCALL_AGAIN(GC_malloc (nargs * sizeof (long ) ) ); 
  }
  for (i = 0 ; i < nargs ; i ++ , itypes = (((Scheme_Simple_Object * ) (itypes ) ) -> u . pair_val . cdr ) ) {
#   define XfOrM223_COUNT (0+XfOrM207_COUNT)
#   define SETUP_XfOrM223(x) SETUP_XfOrM207(x)
    offset = 0 ; 
    p = FUNCCALL(SETUP_XfOrM223(_), scheme_to_c ((((Scheme_Simple_Object * ) (itypes ) ) -> u . pair_val . car ) , & (ivals [i ] ) , 0 , argv [i ] , & basetype , & offset ) ); 
    if (p != ((void * ) 0 ) ) {
      avalues [i ] = p ; 
      ivals [i ] . x_fixnum = basetype ; 
    }
    else {
      avalues [i ] = ((void * ) 0 ) ; 
    }
    offsets [i ] = offset ; 
  }
  base = FUNCCALL(SETUP_XfOrM207(_), get_ctype_base (otype ) ); 
  if (((long ) (((ctype_struct * ) (base ) ) -> c_to_scheme ) ) == (26 ) ) {
#   define XfOrM219_COUNT (0+XfOrM207_COUNT)
#   define SETUP_XfOrM219(x) SETUP_XfOrM207(x)
    p = FUNCCALL(SETUP_XfOrM219(_), malloc (((ffi_type * ) (((ctype_struct * ) (base ) ) -> scheme_to_c ) ) -> size ) ); 
    newp = FUNCCALL(SETUP_XfOrM219(_), GC_malloc_atomic (((ffi_type * ) (((ctype_struct * ) (base ) ) -> scheme_to_c ) ) -> size ) ); 
  }
  else {
    p = & oval ; 
    newp = ((void * ) 0 ) ; 
  }
  for (i = 0 ; i < nargs ; i ++ ) {
    if (avalues [i ] == ((void * ) 0 ) )
      avalues [i ] = & (ivals [i ] ) ; 
    else if (ivals [i ] . x_fixnum != (26 ) ) {
      ivals [i ] . x_pointer = avalues [i ] ; 
      avalues [i ] = & (ivals [i ] ) ; 
    }
    if (offsets [i ] != 0 ) {
      ivals [i ] . x_pointer = (char * ) ivals [i ] . x_pointer + offsets [i ] ; 
    }
  }
  FUNCCALL(SETUP_XfOrM207(_), ffi_call (cif , (void * ) ((char * ) (c_func ) XFORM_OK_PLUS (cfoff ) ) , p , avalues ) ); 
  if (ivals != stack_ivals )
    FUNCCALL(SETUP_XfOrM207(_), free (ivals ) ); 
  ivals = ((void * ) 0 ) ; 
  for (i = 0 ; i < nargs ; i ++ ) {
    avalues [i ] = ((void * ) 0 ) ; 
  }
  avalues = ((void * ) 0 ) ; 
  switch (((long ) (((ctype_struct * ) (base ) ) -> c_to_scheme ) ) ) {
#   define XfOrM208_COUNT (0+XfOrM207_COUNT)
#   define SETUP_XfOrM208(x) SETUP_XfOrM207(x)
    case (25 ) : p = ((oval . x_pointer == ((void * ) 0 ) ) ? scheme_false : FUNCCALL(SETUP_XfOrM208(_), scheme_make_cptr (oval . x_pointer , ((void * ) 0 ) ) )) ; 
    break ; 
    case (26 ) : (memcpy (newp , p , ((ffi_type * ) (((ctype_struct * ) (base ) ) -> scheme_to_c ) ) -> size ) ) ; 
    FUNCCALL(SETUP_XfOrM208(_), free (p ) ); 
    p = newp ; 
    break ; 
    default : if (((ffi_type * ) (((ctype_struct * ) (base ) ) -> scheme_to_c ) ) == & ffi_type_pointer ) {
      tmp = ((void * * ) p ) [0 ] ; 
      p = & tmp ; 
    }
    break ; 
  }
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM207(_), c_to_scheme (otype , p , 0 ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void free_fficall_data (void * ignored , void * p ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(p, 0)));
# define XfOrM228_COUNT (1)
# define SETUP_XfOrM228(x) SETUP(XfOrM228_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM228(_), free (((ffi_cif * ) p ) -> arg_types ) ); 
  FUNCCALL_EMPTY(free (p ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * foreign_ffi_call (int argc , Scheme_Object * argv [] ) {
  static Scheme_Object * ffi_name_prefix = ((void * ) 0 ) ; 
  Scheme_Object * itypes = argv [1 ] ; 
  Scheme_Object * otype = argv [2 ] ; 
  Scheme_Object * obj , * data , * p , * base ; 
  long ooff ; 
  GC_CAN_IGNORE ffi_type * rtype , * * atypes ; 
  GC_CAN_IGNORE ffi_cif * cif ; 
  int i , nargs ; 
  Scheme_Object * __funcarg52 = NULLED_OUT ; 
  PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSH(itypes, 0), PUSH(obj, 1), PUSH(base, 2), PUSH(p, 3), PUSH(data, 4), PUSH(otype, 5), PUSH(argv, 6)));
# define XfOrM229_COUNT (7)
# define SETUP_XfOrM229(x) SETUP(XfOrM229_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  obj = NULLED_OUT ; 
  data = NULLED_OUT ; 
  p = NULLED_OUT ; 
  base = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM229(_), scheme_register_static ((void * ) & ffi_name_prefix , sizeof (ffi_name_prefix ) ) ); 
  if (! ffi_name_prefix )
    ffi_name_prefix = FUNCCALL(SETUP_XfOrM229(_), scheme_make_byte_string_without_copying ("ffi:" ) ); 
  if (! ((((argv [0 ] ) ) == (scheme_false ) ) || (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) || (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ffi_obj_tag ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("ffi-call" , "ffi-obj-or-cpointer" , 0 , argc , argv ) ); 
  obj = ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Cptr * ) (argv [0 ] ) ) -> val ) : ((((argv [0 ] ) ) == (scheme_false ) ) ? ((void * ) 0 ) : ((((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ffi_obj_tag ) ? (((ffi_obj_struct * ) argv [0 ] ) -> obj ) : ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ? (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) : ((void * ) 0 ) ) ) ) ; 
  ooff = ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ? (((Scheme_Type ) (((argv [0 ] ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ? ((Scheme_Offset_Cptr * ) argv [0 ] ) -> offset : 0 ) : 0 ) ; 
  if ((obj == ((void * ) 0 ) ) && (ooff == 0 ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("ffi-call" , "non-null-cpointer" , 0 , argc , argv ) ); 
  nargs = FUNCCALL(SETUP_XfOrM229(_), scheme_proper_list_length (itypes ) ); 
  if (nargs < 0 )
    FUNCCALL_EMPTY(scheme_wrong_type ("ffi-call" , "proper list" , 1 , argc , argv ) ); 
  if (((void * ) 0 ) == (base = FUNCCALL(SETUP_XfOrM229(_), get_ctype_base (otype ) )) )
    FUNCCALL_EMPTY(scheme_wrong_type ("ffi-call" , "C-type" , 2 , argc , argv ) ); 
  rtype = ((ffi_type * ) (((ctype_struct * ) (base ) ) -> scheme_to_c ) ) ; 
  atypes = FUNCCALL(SETUP_XfOrM229(_), malloc (nargs * sizeof (ffi_type * ) ) ); 
  for (i = 0 , p = itypes ; i < nargs ; i ++ , p = (((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . cdr ) ) {
#   define XfOrM231_COUNT (0+XfOrM229_COUNT)
#   define SETUP_XfOrM231(x) SETUP_XfOrM229(x)
    if (((void * ) 0 ) == (base = FUNCCALL(SETUP_XfOrM231(_), get_ctype_base ((((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . car ) ) )) )
      FUNCCALL_EMPTY(scheme_wrong_type ("ffi-call" , "list-of-C-types" , 1 , argc , argv ) ); 
    if (((long ) (((ctype_struct * ) (base ) ) -> c_to_scheme ) ) == (1 ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("ffi-call" , "list-of-non-void-C-types" , 1 , argc , argv ) ); 
    atypes [i ] = ((ffi_type * ) (((ctype_struct * ) (base ) ) -> scheme_to_c ) ) ; 
  }
  cif = FUNCCALL(SETUP_XfOrM229(_), malloc (sizeof (ffi_cif ) ) ); 
  if (FUNCCALL(SETUP_XfOrM229(_), ffi_prep_cif (cif , FFI_DEFAULT_ABI , nargs , rtype , atypes ) )!= FFI_OK )
    FUNCCALL_EMPTY(scheme_signal_error ("internal error: ffi_prep_cif did not return FFI_OK" ) ); 
  data = FUNCCALL(SETUP_XfOrM229(_), scheme_make_vector (6 , ((void * ) 0 ) ) ); 
  p = (__funcarg52 = FUNCCALL(SETUP_XfOrM229(_), scheme_make_byte_string_without_copying ((((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == ffi_obj_tag ) ? ((ffi_obj_struct * ) (argv [0 ] ) ) -> name : "proc" ) ), FUNCCALL_AGAIN(scheme_append_byte_string (ffi_name_prefix , __funcarg52 ) )) ; 
  (((Scheme_Vector * ) (data ) ) -> els ) [0 ] = p ; 
  (((Scheme_Vector * ) (data ) ) -> els ) [1 ] = obj ; 
  (((Scheme_Vector * ) (data ) ) -> els ) [2 ] = itypes ; 
  (((Scheme_Vector * ) (data ) ) -> els ) [3 ] = otype ; 
  (((Scheme_Vector * ) (data ) ) -> els ) [4 ] = (Scheme_Object * ) cif ; 
  (((Scheme_Vector * ) (data ) ) -> els ) [5 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (ooff ) ) << 1 ) | 0x1 ) ) ; 
  FUNCCALL(SETUP_XfOrM229(_), scheme_register_finalizer (data , free_fficall_data , cif , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_closed_prim_w_arity (ffi_do_call , (void * ) data , (((Scheme_Simple_Object * ) (p ) ) -> u . byte_str_val . string_val ) , nargs , nargs ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void ffi_do_callback (ffi_cif * cif , void * resultp , void * * args , void * userdata ) {
  ffi_callback_struct * data ; 
  Scheme_Object * argv_stack [16 ] ; 
  int argc = cif -> nargs , i ; 
  Scheme_Object * * argv , * p , * v ; 
  PREPARE_VAR_STACK_ONCE(9);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSHARRAY(argv_stack, 16, 1), PUSH(data, 4), PUSH(args, 5), PUSH(resultp, 6), PUSH(p, 7), PUSH(argv, 8)));
# define XfOrM232_COUNT (9)
# define SETUP_XfOrM232(x) SETUP(XfOrM232_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  data = NULLED_OUT ; 
  NULL_OUT_ARRAY (argv_stack ) ; 
  argv = NULLED_OUT ; 
  p = NULLED_OUT ; 
  v = NULLED_OUT ; 
  {
    void * tmp ; 
#   define XfOrM235_COUNT (0+XfOrM232_COUNT)
#   define SETUP_XfOrM235(x) SETUP_XfOrM232(x)
    tmp = NULLED_OUT ; 
    tmp = * ((void * * ) userdata ) ; 
    data = (ffi_callback_struct * ) ((((Scheme_Small_Object * ) (tmp ) ) -> u . ptr_val ) ) ; 
    if (data == ((void * ) 0 ) )
      FUNCCALL(SETUP_XfOrM235(_), scheme_signal_error ("callback lost" ) ); 
  }
  if (argc <= 16 )
    argv = argv_stack ; 
  else argv = FUNCCALL(SETUP_XfOrM232(_), GC_malloc (argc * sizeof (Scheme_Object * ) ) ); 
  for (i = 0 , p = data -> itypes ; i < argc ; i ++ , p = (((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . cdr ) ) {
#   define XfOrM234_COUNT (0+XfOrM232_COUNT)
#   define SETUP_XfOrM234(x) SETUP_XfOrM232(x)
    v = FUNCCALL(SETUP_XfOrM234(_), c_to_scheme ((((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . car ) , args [i ] , 0 ) ); 
    argv [i ] = v ; 
  }
  p = FUNCCALL(SETUP_XfOrM232(_), scheme_do_eval (data -> proc , argc , argv , 1 ) ); 
  FUNCCALL(SETUP_XfOrM232(_), scheme_to_c (data -> otype , resultp , 0 , p , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
typedef struct closure_and_cif_struct {
  ffi_closure closure ; 
  ffi_cif cif ; 
  struct immobile_box * data ; 
}
closure_and_cif ; 
void free_cl_cif_args (void * ignored , void * p ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(p, 0)));
# define XfOrM236_COUNT (1)
# define SETUP_XfOrM236(x) SETUP(XfOrM236_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM236(_), GC_free_immobile_box ((void * * ) (((closure_and_cif * ) p ) -> data ) ) ); 
  FUNCCALL_EMPTY(free (p ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 2544 */
/* this far 2544 */
static Scheme_Object * foreign_ffi_callback (int argc , Scheme_Object * argv [] ) {
  ffi_callback_struct * data ; 
  Scheme_Object * itypes = argv [1 ] ; 
  Scheme_Object * otype = argv [2 ] ; 
  Scheme_Object * p , * base ; 
  int nargs , i ; 
  GC_CAN_IGNORE ffi_type * rtype , * * atypes ; 
  GC_CAN_IGNORE ffi_cif * cif ; 
  GC_CAN_IGNORE ffi_closure * cl ; 
  GC_CAN_IGNORE closure_and_cif * cl_cif_args ; 
  void * __funcarg53 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(data, 0), PUSH(itypes, 1), PUSH(base, 2), PUSH(argv, 3), PUSH(otype, 4), PUSH(p, 5)));
# define XfOrM237_COUNT (6)
# define SETUP_XfOrM237(x) SETUP(XfOrM237_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  data = NULLED_OUT ; 
  p = NULLED_OUT ; 
  base = NULLED_OUT ; 
  if (! (! (((long ) (argv [0 ] ) ) & 0x1 ) && ((((argv [0 ] ) -> type ) >= scheme_prim_type ) && (((argv [0 ] ) -> type ) <= scheme_native_closure_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("ffi-callback" , "procedure" , 0 , argc , argv ) ); 
  nargs = FUNCCALL(SETUP_XfOrM237(_), scheme_proper_list_length (itypes ) ); 
  if (nargs < 0 )
    FUNCCALL_EMPTY(scheme_wrong_type ("ffi-callback" , "proper list" , 1 , argc , argv ) ); 
  if (((void * ) 0 ) == (base = FUNCCALL(SETUP_XfOrM237(_), get_ctype_base (otype ) )) )
    FUNCCALL_EMPTY(scheme_wrong_type ("ffi-callback" , "C-type" , 2 , argc , argv ) ); 
  rtype = ((ffi_type * ) (((ctype_struct * ) (base ) ) -> scheme_to_c ) ) ; 
  cl_cif_args = FUNCCALL(SETUP_XfOrM237(_), malloc (sizeof (closure_and_cif ) + nargs * sizeof (ffi_cif * ) ) ); 
  cl = & (cl_cif_args -> closure ) ; 
  cif = & (cl_cif_args -> cif ) ; 
  atypes = (ffi_type * * ) (((char * ) cl_cif_args ) + sizeof (closure_and_cif ) ) ; 
  for (i = 0 , p = itypes ; i < nargs ; i ++ , p = (((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . cdr ) ) {
#   define XfOrM240_COUNT (0+XfOrM237_COUNT)
#   define SETUP_XfOrM240(x) SETUP_XfOrM237(x)
    if (((void * ) 0 ) == (base = FUNCCALL(SETUP_XfOrM240(_), get_ctype_base ((((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . car ) ) )) )
      FUNCCALL_EMPTY(scheme_wrong_type ("ffi-callback" , "list-of-C-types" , 1 , argc , argv ) ); 
    if (((long ) (((ctype_struct * ) (base ) ) -> c_to_scheme ) ) == (1 ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("ffi-callback" , "list-of-non-void-C-types" , 1 , argc , argv ) ); 
    atypes [i ] = ((ffi_type * ) (((ctype_struct * ) (base ) ) -> scheme_to_c ) ) ; 
  }
  if (FUNCCALL(SETUP_XfOrM237(_), ffi_prep_cif (cif , FFI_DEFAULT_ABI , nargs , rtype , atypes ) )!= FFI_OK )
    FUNCCALL_EMPTY(scheme_signal_error ("internal error: ffi_prep_cif did not return FFI_OK" ) ); 
  data = (ffi_callback_struct * ) FUNCCALL(SETUP_XfOrM237(_), GC_malloc_one_tagged (sizeof (ffi_callback_struct ) ) ); 
  data -> so . type = ffi_callback_tag ; 
  data -> callback = (cl_cif_args ) ; 
  data -> proc = (argv [0 ] ) ; 
  data -> itypes = (argv [1 ] ) ; 
  data -> otype = (argv [2 ] ) ; 
  {
    void * * tmp ; 
    BLOCK_SETUP((PUSH(tmp, 0+XfOrM237_COUNT)));
#   define XfOrM238_COUNT (1+XfOrM237_COUNT)
#   define SETUP_XfOrM238(x) SETUP(XfOrM238_COUNT)
    tmp = NULLED_OUT ; 
    tmp = (__funcarg53 = FUNCCALL(SETUP_XfOrM238(_), GC_malloc_weak_box (data , ((void * ) 0 ) , 0 ) ), FUNCCALL_AGAIN(GC_malloc_immobile_box (__funcarg53 ) )) ; 
    cl_cif_args -> data = (struct immobile_box * ) tmp ; 
  }
  if (FUNCCALL(SETUP_XfOrM237(_), ffi_prep_closure (cl , cif , & ffi_do_callback , (void * ) (cl_cif_args -> data ) ) )!= FFI_OK )
    FUNCCALL_EMPTY(scheme_signal_error ("internal error: ffi_prep_closure did not return FFI_OK" ) ); 
  FUNCCALL(SETUP_XfOrM237(_), scheme_register_finalizer (data , free_cl_cif_args , cl_cif_args , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
  RET_VALUE_START ((Scheme_Object * ) data ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_init_foreign (Scheme_Env * env ) {
  Scheme_Env * menv ; 
  ctype_struct * t ; 
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
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(menv, 0), PUSH(t, 1), PUSH(env, 2)));
# define XfOrM241_COUNT (3)
# define SETUP_XfOrM241(x) SETUP(XfOrM241_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  menv = NULLED_OUT ; 
  t = NULLED_OUT ; 
  menv = (__funcarg93 = FUNCCALL(SETUP_XfOrM241(_), scheme_intern_symbol ("#%foreign" ) ), FUNCCALL_AGAIN(scheme_primitive_module (__funcarg93 , env ) )) ; 
  ffi_lib_tag = FUNCCALL_AGAIN(scheme_make_type ("<ffi-lib>" ) ); 
  ffi_obj_tag = FUNCCALL_AGAIN(scheme_make_type ("<ffi-obj>" ) ); 
  ctype_tag = FUNCCALL_AGAIN(scheme_make_type ("<ctype>" ) ); 
  ffi_callback_tag = FUNCCALL_AGAIN(scheme_make_type ("<ffi-callback>" ) ); 
  FUNCCALL_AGAIN(GC_register_traversers (ffi_lib_tag , ffi_lib_SIZE , ffi_lib_MARK , ffi_lib_FIXUP , 1 , 0 ) ); 
  FUNCCALL_AGAIN(GC_register_traversers (ffi_obj_tag , ffi_obj_SIZE , ffi_obj_MARK , ffi_obj_FIXUP , 1 , 0 ) ); 
  FUNCCALL_AGAIN(GC_register_traversers (ctype_tag , ctype_SIZE , ctype_MARK , ctype_FIXUP , 1 , 0 ) ); 
  FUNCCALL_AGAIN(GC_register_traversers (ffi_callback_tag , ffi_callback_SIZE , ffi_callback_MARK , ffi_callback_FIXUP , 1 , 0 ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & opened_libs , sizeof (opened_libs ) ) ); 
  opened_libs = FUNCCALL_AGAIN(scheme_make_hash_table (SCHEME_hash_string ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & nonatomic_sym , sizeof (nonatomic_sym ) ) ); 
  nonatomic_sym = FUNCCALL_AGAIN(scheme_intern_symbol ("nonatomic" ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & atomic_sym , sizeof (atomic_sym ) ) ); 
  atomic_sym = FUNCCALL_AGAIN(scheme_intern_symbol ("atomic" ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & stubborn_sym , sizeof (stubborn_sym ) ) ); 
  stubborn_sym = FUNCCALL_AGAIN(scheme_intern_symbol ("stubborn" ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & uncollectable_sym , sizeof (uncollectable_sym ) ) ); 
  uncollectable_sym = FUNCCALL_AGAIN(scheme_intern_symbol ("uncollectable" ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & eternal_sym , sizeof (eternal_sym ) ) ); 
  eternal_sym = FUNCCALL_AGAIN(scheme_intern_symbol ("eternal" ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & interior_sym , sizeof (interior_sym ) ) ); 
  interior_sym = FUNCCALL_AGAIN(scheme_intern_symbol ("interior" ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & atomic_interior_sym , sizeof (atomic_interior_sym ) ) ); 
  atomic_interior_sym = FUNCCALL_AGAIN(scheme_intern_symbol ("atomic-interior" ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & raw_sym , sizeof (raw_sym ) ) ); 
  raw_sym = FUNCCALL_AGAIN(scheme_intern_symbol ("raw" ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & fail_ok_sym , sizeof (fail_ok_sym ) ) ); 
  fail_ok_sym = FUNCCALL_AGAIN(scheme_intern_symbol ("fail-ok" ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & abs_sym , sizeof (abs_sym ) ) ); 
  abs_sym = FUNCCALL_AGAIN(scheme_intern_symbol ("abs" ) ); 
  (__funcarg92 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_ffi_lib_p , "ffi-lib?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global ("ffi-lib?" , __funcarg92 , menv ) )) ; 
  (__funcarg91 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_ffi_lib , "ffi-lib" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global ("ffi-lib" , __funcarg91 , menv ) )) ; 
  (__funcarg90 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_ffi_lib_name , "ffi-lib-name" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global ("ffi-lib-name" , __funcarg90 , menv ) )) ; 
  (__funcarg89 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_ffi_obj_p , "ffi-obj?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global ("ffi-obj?" , __funcarg89 , menv ) )) ; 
  (__funcarg88 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_ffi_obj , "ffi-obj" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global ("ffi-obj" , __funcarg88 , menv ) )) ; 
  (__funcarg87 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_ffi_obj_lib , "ffi-obj-lib" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global ("ffi-obj-lib" , __funcarg87 , menv ) )) ; 
  (__funcarg86 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_ffi_obj_name , "ffi-obj-name" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global ("ffi-obj-name" , __funcarg86 , menv ) )) ; 
  (__funcarg85 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_ctype_p , "ctype?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global ("ctype?" , __funcarg85 , menv ) )) ; 
  (__funcarg84 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_ctype_basetype , "ctype-basetype" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global ("ctype-basetype" , __funcarg84 , menv ) )) ; 
  (__funcarg83 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_ctype_scheme_to_c , "ctype-scheme->c" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global ("ctype-scheme->c" , __funcarg83 , menv ) )) ; 
  (__funcarg82 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_ctype_c_to_scheme , "ctype-c->scheme" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global ("ctype-c->scheme" , __funcarg82 , menv ) )) ; 
  (__funcarg81 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_make_ctype , "make-ctype" , 3 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global ("make-ctype" , __funcarg81 , menv ) )) ; 
  (__funcarg80 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_make_cstruct_type , "make-cstruct-type" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global ("make-cstruct-type" , __funcarg80 , menv ) )) ; 
  (__funcarg79 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_cpointer_p , "cpointer?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global ("cpointer?" , __funcarg79 , menv ) )) ; 
  (__funcarg78 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_cpointer_tag , "cpointer-tag" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global ("cpointer-tag" , __funcarg78 , menv ) )) ; 
  (__funcarg77 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_set_cpointer_tag_bang , "set-cpointer-tag!" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global ("set-cpointer-tag!" , __funcarg77 , menv ) )) ; 
  (__funcarg76 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_ffi_callback_p , "ffi-callback?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global ("ffi-callback?" , __funcarg76 , menv ) )) ; 
  (__funcarg75 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_ctype_sizeof , "ctype-sizeof" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global ("ctype-sizeof" , __funcarg75 , menv ) )) ; 
  (__funcarg74 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_ctype_alignof , "ctype-alignof" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global ("ctype-alignof" , __funcarg74 , menv ) )) ; 
  (__funcarg73 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_compiler_sizeof , "compiler-sizeof" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global ("compiler-sizeof" , __funcarg73 , menv ) )) ; 
  (__funcarg72 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_malloc , "malloc" , 1 , 5 ) ), FUNCCALL_AGAIN(scheme_add_global ("malloc" , __funcarg72 , menv ) )) ; 
  (__funcarg71 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_end_stubborn_change , "end-stubborn-change" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global ("end-stubborn-change" , __funcarg71 , menv ) )) ; 
  (__funcarg70 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_free , "free" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global ("free" , __funcarg70 , menv ) )) ; 
  (__funcarg69 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_malloc_immobile_cell , "malloc-immobile-cell" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global ("malloc-immobile-cell" , __funcarg69 , menv ) )) ; 
  (__funcarg68 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_free_immobile_cell , "free-immobile-cell" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global ("free-immobile-cell" , __funcarg68 , menv ) )) ; 
  (__funcarg67 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_ptr_add , "ptr-add" , 2 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global ("ptr-add" , __funcarg67 , menv ) )) ; 
  (__funcarg66 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_ptr_add_bang , "ptr-add!" , 2 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global ("ptr-add!" , __funcarg66 , menv ) )) ; 
  (__funcarg65 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_offset_ptr_p , "offset-ptr?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global ("offset-ptr?" , __funcarg65 , menv ) )) ; 
  (__funcarg64 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_ptr_offset , "ptr-offset" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global ("ptr-offset" , __funcarg64 , menv ) )) ; 
  (__funcarg63 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_set_ptr_offset_bang , "set-ptr-offset!" , 2 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global ("set-ptr-offset!" , __funcarg63 , menv ) )) ; 
  (__funcarg62 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_memset , "memset" , 3 , 5 ) ), FUNCCALL_AGAIN(scheme_add_global ("memset" , __funcarg62 , menv ) )) ; 
  (__funcarg61 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_memmove , "memmove" , 3 , 6 ) ), FUNCCALL_AGAIN(scheme_add_global ("memmove" , __funcarg61 , menv ) )) ; 
  (__funcarg60 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_memcpy , "memcpy" , 3 , 6 ) ), FUNCCALL_AGAIN(scheme_add_global ("memcpy" , __funcarg60 , menv ) )) ; 
  (__funcarg59 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_ptr_ref , "ptr-ref" , 2 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global ("ptr-ref" , __funcarg59 , menv ) )) ; 
  (__funcarg58 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_ptr_set_bang , "ptr-set!" , 3 , 5 ) ), FUNCCALL_AGAIN(scheme_add_global ("ptr-set!" , __funcarg58 , menv ) )) ; 
  (__funcarg57 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_ptr_equal_p , "ptr-equal?" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global ("ptr-equal?" , __funcarg57 , menv ) )) ; 
  (__funcarg56 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_make_sized_byte_string , "make-sized-byte-string" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global ("make-sized-byte-string" , __funcarg56 , menv ) )) ; 
  (__funcarg55 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_ffi_call , "ffi-call" , 3 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global ("ffi-call" , __funcarg55 , menv ) )) ; 
  (__funcarg54 = FUNCCALL(SETUP_XfOrM241(_), scheme_make_prim_w_arity (foreign_ffi_callback , "ffi-callback" , 3 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global ("ffi-callback" , __funcarg54 , menv ) )) ; 
  t = (ctype_struct * ) FUNCCALL(SETUP_XfOrM241(_), GC_malloc_one_tagged (sizeof (ctype_struct ) ) ); 
  t -> so . type = ctype_tag ; 
  t -> basetype = (((void * ) 0 ) ) ; 
  t -> scheme_to_c = ((Scheme_Object * ) (void * ) (& ffi_type_void ) ) ; 
  t -> c_to_scheme = ((Scheme_Object * ) (1 ) ) ; 
  FUNCCALL(SETUP_XfOrM241(_), scheme_add_global ("_void" , (Scheme_Object * ) t , menv ) ); 
  t = (ctype_struct * ) FUNCCALL(SETUP_XfOrM241(_), GC_malloc_one_tagged (sizeof (ctype_struct ) ) ); 
  t -> so . type = ctype_tag ; 
  t -> basetype = (((void * ) 0 ) ) ; 
  t -> scheme_to_c = ((Scheme_Object * ) (void * ) (& ffi_type_sint8 ) ) ; 
  t -> c_to_scheme = ((Scheme_Object * ) (2 ) ) ; 
  FUNCCALL(SETUP_XfOrM241(_), scheme_add_global ("_int8" , (Scheme_Object * ) t , menv ) ); 
  t = (ctype_struct * ) FUNCCALL(SETUP_XfOrM241(_), GC_malloc_one_tagged (sizeof (ctype_struct ) ) ); 
  t -> so . type = ctype_tag ; 
  t -> basetype = (((void * ) 0 ) ) ; 
  t -> scheme_to_c = ((Scheme_Object * ) (void * ) (& ffi_type_uint8 ) ) ; 
  t -> c_to_scheme = ((Scheme_Object * ) (3 ) ) ; 
  FUNCCALL(SETUP_XfOrM241(_), scheme_add_global ("_uint8" , (Scheme_Object * ) t , menv ) ); 
  t = (ctype_struct * ) FUNCCALL(SETUP_XfOrM241(_), GC_malloc_one_tagged (sizeof (ctype_struct ) ) ); 
  t -> so . type = ctype_tag ; 
  t -> basetype = (((void * ) 0 ) ) ; 
  t -> scheme_to_c = ((Scheme_Object * ) (void * ) (& ffi_type_sint16 ) ) ; 
  t -> c_to_scheme = ((Scheme_Object * ) (4 ) ) ; 
  FUNCCALL(SETUP_XfOrM241(_), scheme_add_global ("_int16" , (Scheme_Object * ) t , menv ) ); 
  t = (ctype_struct * ) FUNCCALL(SETUP_XfOrM241(_), GC_malloc_one_tagged (sizeof (ctype_struct ) ) ); 
  t -> so . type = ctype_tag ; 
  t -> basetype = (((void * ) 0 ) ) ; 
  t -> scheme_to_c = ((Scheme_Object * ) (void * ) (& ffi_type_uint16 ) ) ; 
  t -> c_to_scheme = ((Scheme_Object * ) (5 ) ) ; 
  FUNCCALL(SETUP_XfOrM241(_), scheme_add_global ("_uint16" , (Scheme_Object * ) t , menv ) ); 
  t = (ctype_struct * ) FUNCCALL(SETUP_XfOrM241(_), GC_malloc_one_tagged (sizeof (ctype_struct ) ) ); 
  t -> so . type = ctype_tag ; 
  t -> basetype = (((void * ) 0 ) ) ; 
  t -> scheme_to_c = ((Scheme_Object * ) (void * ) (& ffi_type_sint32 ) ) ; 
  t -> c_to_scheme = ((Scheme_Object * ) (6 ) ) ; 
  FUNCCALL(SETUP_XfOrM241(_), scheme_add_global ("_int32" , (Scheme_Object * ) t , menv ) ); 
  t = (ctype_struct * ) FUNCCALL(SETUP_XfOrM241(_), GC_malloc_one_tagged (sizeof (ctype_struct ) ) ); 
  t -> so . type = ctype_tag ; 
  t -> basetype = (((void * ) 0 ) ) ; 
  t -> scheme_to_c = ((Scheme_Object * ) (void * ) (& ffi_type_uint32 ) ) ; 
  t -> c_to_scheme = ((Scheme_Object * ) (7 ) ) ; 
  FUNCCALL(SETUP_XfOrM241(_), scheme_add_global ("_uint32" , (Scheme_Object * ) t , menv ) ); 
  t = (ctype_struct * ) FUNCCALL(SETUP_XfOrM241(_), GC_malloc_one_tagged (sizeof (ctype_struct ) ) ); 
  t -> so . type = ctype_tag ; 
  t -> basetype = (((void * ) 0 ) ) ; 
  t -> scheme_to_c = ((Scheme_Object * ) (void * ) (& ffi_type_sint64 ) ) ; 
  t -> c_to_scheme = ((Scheme_Object * ) (8 ) ) ; 
  FUNCCALL(SETUP_XfOrM241(_), scheme_add_global ("_int64" , (Scheme_Object * ) t , menv ) ); 
  t = (ctype_struct * ) FUNCCALL(SETUP_XfOrM241(_), GC_malloc_one_tagged (sizeof (ctype_struct ) ) ); 
  t -> so . type = ctype_tag ; 
  t -> basetype = (((void * ) 0 ) ) ; 
  t -> scheme_to_c = ((Scheme_Object * ) (void * ) (& ffi_type_uint64 ) ) ; 
  t -> c_to_scheme = ((Scheme_Object * ) (9 ) ) ; 
  FUNCCALL(SETUP_XfOrM241(_), scheme_add_global ("_uint64" , (Scheme_Object * ) t , menv ) ); 
  t = (ctype_struct * ) FUNCCALL(SETUP_XfOrM241(_), GC_malloc_one_tagged (sizeof (ctype_struct ) ) ); 
  t -> so . type = ctype_tag ; 
  t -> basetype = (((void * ) 0 ) ) ; 
  t -> scheme_to_c = ((Scheme_Object * ) (void * ) (& ffi_type_sint32 ) ) ; 
  t -> c_to_scheme = ((Scheme_Object * ) (10 ) ) ; 
  FUNCCALL(SETUP_XfOrM241(_), scheme_add_global ("_fixint" , (Scheme_Object * ) t , menv ) ); 
  t = (ctype_struct * ) FUNCCALL(SETUP_XfOrM241(_), GC_malloc_one_tagged (sizeof (ctype_struct ) ) ); 
  t -> so . type = ctype_tag ; 
  t -> basetype = (((void * ) 0 ) ) ; 
  t -> scheme_to_c = ((Scheme_Object * ) (void * ) (& ffi_type_uint32 ) ) ; 
  t -> c_to_scheme = ((Scheme_Object * ) (11 ) ) ; 
  FUNCCALL(SETUP_XfOrM241(_), scheme_add_global ("_ufixint" , (Scheme_Object * ) t , menv ) ); 
  t = (ctype_struct * ) FUNCCALL(SETUP_XfOrM241(_), GC_malloc_one_tagged (sizeof (ctype_struct ) ) ); 
  t -> so . type = ctype_tag ; 
  t -> basetype = (((void * ) 0 ) ) ; 
  t -> scheme_to_c = ((Scheme_Object * ) (void * ) (& ffi_type_sint64 ) ) ; 
  t -> c_to_scheme = ((Scheme_Object * ) (12 ) ) ; 
  FUNCCALL(SETUP_XfOrM241(_), scheme_add_global ("_fixnum" , (Scheme_Object * ) t , menv ) ); 
  t = (ctype_struct * ) FUNCCALL(SETUP_XfOrM241(_), GC_malloc_one_tagged (sizeof (ctype_struct ) ) ); 
  t -> so . type = ctype_tag ; 
  t -> basetype = (((void * ) 0 ) ) ; 
  t -> scheme_to_c = ((Scheme_Object * ) (void * ) (& ffi_type_uint64 ) ) ; 
  t -> c_to_scheme = ((Scheme_Object * ) (13 ) ) ; 
  FUNCCALL(SETUP_XfOrM241(_), scheme_add_global ("_ufixnum" , (Scheme_Object * ) t , menv ) ); 
  t = (ctype_struct * ) FUNCCALL(SETUP_XfOrM241(_), GC_malloc_one_tagged (sizeof (ctype_struct ) ) ); 
  t -> so . type = ctype_tag ; 
  t -> basetype = (((void * ) 0 ) ) ; 
  t -> scheme_to_c = ((Scheme_Object * ) (void * ) (& ffi_type_float ) ) ; 
  t -> c_to_scheme = ((Scheme_Object * ) (14 ) ) ; 
  FUNCCALL(SETUP_XfOrM241(_), scheme_add_global ("_float" , (Scheme_Object * ) t , menv ) ); 
  t = (ctype_struct * ) FUNCCALL(SETUP_XfOrM241(_), GC_malloc_one_tagged (sizeof (ctype_struct ) ) ); 
  t -> so . type = ctype_tag ; 
  t -> basetype = (((void * ) 0 ) ) ; 
  t -> scheme_to_c = ((Scheme_Object * ) (void * ) (& ffi_type_double ) ) ; 
  t -> c_to_scheme = ((Scheme_Object * ) (15 ) ) ; 
  FUNCCALL(SETUP_XfOrM241(_), scheme_add_global ("_double" , (Scheme_Object * ) t , menv ) ); 
  t = (ctype_struct * ) FUNCCALL(SETUP_XfOrM241(_), GC_malloc_one_tagged (sizeof (ctype_struct ) ) ); 
  t -> so . type = ctype_tag ; 
  t -> basetype = (((void * ) 0 ) ) ; 
  t -> scheme_to_c = ((Scheme_Object * ) (void * ) (& ffi_type_double ) ) ; 
  t -> c_to_scheme = ((Scheme_Object * ) (16 ) ) ; 
  FUNCCALL(SETUP_XfOrM241(_), scheme_add_global ("_double*" , (Scheme_Object * ) t , menv ) ); 
  t = (ctype_struct * ) FUNCCALL(SETUP_XfOrM241(_), GC_malloc_one_tagged (sizeof (ctype_struct ) ) ); 
  t -> so . type = ctype_tag ; 
  t -> basetype = (((void * ) 0 ) ) ; 
  t -> scheme_to_c = ((Scheme_Object * ) (void * ) (& ffi_type_sint32 ) ) ; 
  t -> c_to_scheme = ((Scheme_Object * ) (17 ) ) ; 
  FUNCCALL(SETUP_XfOrM241(_), scheme_add_global ("_bool" , (Scheme_Object * ) t , menv ) ); 
  t = (ctype_struct * ) FUNCCALL(SETUP_XfOrM241(_), GC_malloc_one_tagged (sizeof (ctype_struct ) ) ); 
  t -> so . type = ctype_tag ; 
  t -> basetype = (((void * ) 0 ) ) ; 
  t -> scheme_to_c = ((Scheme_Object * ) (void * ) (& ffi_type_pointer ) ) ; 
  t -> c_to_scheme = ((Scheme_Object * ) (18 ) ) ; 
  FUNCCALL(SETUP_XfOrM241(_), scheme_add_global ("_string/ucs-4" , (Scheme_Object * ) t , menv ) ); 
  t = (ctype_struct * ) FUNCCALL(SETUP_XfOrM241(_), GC_malloc_one_tagged (sizeof (ctype_struct ) ) ); 
  t -> so . type = ctype_tag ; 
  t -> basetype = (((void * ) 0 ) ) ; 
  t -> scheme_to_c = ((Scheme_Object * ) (void * ) (& ffi_type_pointer ) ) ; 
  t -> c_to_scheme = ((Scheme_Object * ) (19 ) ) ; 
  FUNCCALL(SETUP_XfOrM241(_), scheme_add_global ("_string/utf-16" , (Scheme_Object * ) t , menv ) ); 
  t = (ctype_struct * ) FUNCCALL(SETUP_XfOrM241(_), GC_malloc_one_tagged (sizeof (ctype_struct ) ) ); 
  t -> so . type = ctype_tag ; 
  t -> basetype = (((void * ) 0 ) ) ; 
  t -> scheme_to_c = ((Scheme_Object * ) (void * ) (& ffi_type_pointer ) ) ; 
  t -> c_to_scheme = ((Scheme_Object * ) (20 ) ) ; 
  FUNCCALL(SETUP_XfOrM241(_), scheme_add_global ("_bytes" , (Scheme_Object * ) t , menv ) ); 
  t = (ctype_struct * ) FUNCCALL(SETUP_XfOrM241(_), GC_malloc_one_tagged (sizeof (ctype_struct ) ) ); 
  t -> so . type = ctype_tag ; 
  t -> basetype = (((void * ) 0 ) ) ; 
  t -> scheme_to_c = ((Scheme_Object * ) (void * ) (& ffi_type_pointer ) ) ; 
  t -> c_to_scheme = ((Scheme_Object * ) (21 ) ) ; 
  FUNCCALL(SETUP_XfOrM241(_), scheme_add_global ("_path" , (Scheme_Object * ) t , menv ) ); 
  t = (ctype_struct * ) FUNCCALL(SETUP_XfOrM241(_), GC_malloc_one_tagged (sizeof (ctype_struct ) ) ); 
  t -> so . type = ctype_tag ; 
  t -> basetype = (((void * ) 0 ) ) ; 
  t -> scheme_to_c = ((Scheme_Object * ) (void * ) (& ffi_type_pointer ) ) ; 
  t -> c_to_scheme = ((Scheme_Object * ) (22 ) ) ; 
  FUNCCALL(SETUP_XfOrM241(_), scheme_add_global ("_symbol" , (Scheme_Object * ) t , menv ) ); 
  t = (ctype_struct * ) FUNCCALL(SETUP_XfOrM241(_), GC_malloc_one_tagged (sizeof (ctype_struct ) ) ); 
  t -> so . type = ctype_tag ; 
  t -> basetype = (((void * ) 0 ) ) ; 
  t -> scheme_to_c = ((Scheme_Object * ) (void * ) (& ffi_type_pointer ) ) ; 
  t -> c_to_scheme = ((Scheme_Object * ) (23 ) ) ; 
  FUNCCALL(SETUP_XfOrM241(_), scheme_add_global ("_pointer" , (Scheme_Object * ) t , menv ) ); 
  t = (ctype_struct * ) FUNCCALL(SETUP_XfOrM241(_), GC_malloc_one_tagged (sizeof (ctype_struct ) ) ); 
  t -> so . type = ctype_tag ; 
  t -> basetype = (((void * ) 0 ) ) ; 
  t -> scheme_to_c = ((Scheme_Object * ) (void * ) (& ffi_type_pointer ) ) ; 
  t -> c_to_scheme = ((Scheme_Object * ) (24 ) ) ; 
  FUNCCALL(SETUP_XfOrM241(_), scheme_add_global ("_scheme" , (Scheme_Object * ) t , menv ) ); 
  t = (ctype_struct * ) FUNCCALL(SETUP_XfOrM241(_), GC_malloc_one_tagged (sizeof (ctype_struct ) ) ); 
  t -> so . type = ctype_tag ; 
  t -> basetype = (((void * ) 0 ) ) ; 
  t -> scheme_to_c = ((Scheme_Object * ) (void * ) (& ffi_type_pointer ) ) ; 
  t -> c_to_scheme = ((Scheme_Object * ) (25 ) ) ; 
  FUNCCALL(SETUP_XfOrM241(_), scheme_add_global ("_fpointer" , (Scheme_Object * ) t , menv ) ); 
  FUNCCALL_AGAIN(scheme_finish_primitive_module (menv ) ); 
  FUNCCALL_EMPTY(scheme_protect_primitive_provide (menv , ((void * ) 0 ) ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
