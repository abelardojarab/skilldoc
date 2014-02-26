#include "precomp.h"
Scheme_Type_Reader * scheme_type_readers ; 
Scheme_Type_Writer * scheme_type_writers ; 
Scheme_Equal_Proc * scheme_type_equals ; 
Scheme_Primary_Hash_Proc * scheme_type_hash1s ; 
Scheme_Secondary_Hash_Proc * scheme_type_hash2s ; 
static char * * type_names ; 
static Scheme_Type maxtype , allocmax ; 
static void init_type_arrays () {
  /* No conversion */
  long n ; 
  scheme_register_static ((void * ) & type_names , sizeof (type_names ) ) ; 
  scheme_register_static ((void * ) & scheme_type_readers , sizeof (scheme_type_readers ) ) ; 
  scheme_register_static ((void * ) & scheme_type_writers , sizeof (scheme_type_writers ) ) ; 
  scheme_register_static ((void * ) & scheme_type_equals , sizeof (scheme_type_equals ) ) ; 
  scheme_register_static ((void * ) & scheme_type_hash1s , sizeof (scheme_type_hash1s ) ) ; 
  scheme_register_static ((void * ) & scheme_type_hash2s , sizeof (scheme_type_hash2s ) ) ; 
  maxtype = _scheme_last_type_ ; 
  allocmax = maxtype + 10 ; 
  type_names = ((char * * ) GC_malloc (sizeof (char * ) * (allocmax ) ) ) ; 
  scheme_type_readers = ((Scheme_Type_Reader * ) GC_malloc_atomic (sizeof (Scheme_Type_Reader ) * (allocmax ) ) ) ; 
  n = allocmax * sizeof (Scheme_Type_Reader ) ; 
  memset ((char * ) scheme_type_readers , 0 , n ) ; 
  scheme_type_writers = ((Scheme_Type_Writer * ) GC_malloc_atomic (sizeof (Scheme_Type_Writer ) * (allocmax ) ) ) ; 
  n = allocmax * sizeof (Scheme_Type_Writer ) ; 
  memset ((char * ) scheme_type_writers , 0 , n ) ; 
  scheme_type_equals = ((Scheme_Equal_Proc * ) GC_malloc_atomic (sizeof (Scheme_Equal_Proc ) * (allocmax ) ) ) ; 
  n = allocmax * sizeof (Scheme_Equal_Proc ) ; 
  memset ((char * ) scheme_type_equals , 0 , n ) ; 
  scheme_type_hash1s = ((Scheme_Primary_Hash_Proc * ) GC_malloc_atomic (sizeof (Scheme_Primary_Hash_Proc ) * (allocmax ) ) ) ; 
  n = allocmax * sizeof (Scheme_Primary_Hash_Proc ) ; 
  memset ((char * ) scheme_type_hash1s , 0 , n ) ; 
  scheme_type_hash2s = ((Scheme_Secondary_Hash_Proc * ) GC_malloc_atomic (sizeof (Scheme_Secondary_Hash_Proc ) * (allocmax ) ) ) ; 
  n = allocmax * sizeof (Scheme_Secondary_Hash_Proc ) ; 
  memset ((char * ) scheme_type_hash2s , 0 , n ) ; 
}
void scheme_init_type (Scheme_Env * env ) {
  /* No conversion */
  if (! type_names )
    init_type_arrays () ; 
  type_names [scheme_true_type ] = "<true>" ; 
  type_names [scheme_false_type ] = "<false>" ; 
  type_names [scheme_char_type ] = "<char>" ; 
  type_names [scheme_local_type ] = "<local-code>" ; 
  type_names [scheme_local_unbox_type ] = "<local-unbox-code>" ; 
  type_names [scheme_variable_type ] = "<global-variable-code>" ; 
  type_names [scheme_toplevel_type ] = "<variable-code>" ; 
  type_names [scheme_module_variable_type ] = "<module-variable-code>" ; 
  type_names [scheme_application_type ] = "<application-code>" ; 
  type_names [scheme_application2_type ] = "<unary-application-code>" ; 
  type_names [scheme_application3_type ] = "<binary-application-code>" ; 
  type_names [scheme_compiled_unclosed_procedure_type ] = "<procedure-semi-code>" ; 
  type_names [scheme_unclosed_procedure_type ] = "<procedure-code>" ; 
  type_names [scheme_syntax_type ] = "<syntax-code>" ; 
  type_names [scheme_compiled_syntax_type ] = "<syntax-semi-code>" ; 
  type_names [scheme_branch_type ] = "<branch-code>" ; 
  type_names [scheme_sequence_type ] = "<sequence-code>" ; 
  type_names [scheme_case_lambda_sequence_type ] = "<case-lambda-code>" ; 
  type_names [scheme_begin0_sequence_type ] = "<begin0-code>" ; 
  type_names [scheme_with_cont_mark_type ] = "<with-continuation-mark-code>" ; 
  type_names [scheme_quote_syntax_type ] = "<quote-syntax-code>" ; 
  type_names [scheme_let_value_type ] = "<let-value-code>" ; 
  type_names [scheme_let_void_type ] = "<let-void-code>" ; 
  type_names [scheme_compiled_let_value_type ] = "<let-value-semi-code>" ; 
  type_names [scheme_compiled_let_void_type ] = "<let-void-semi-code>" ; 
  type_names [scheme_compiled_toplevel_type ] = "<variable-semi-code>" ; 
  type_names [scheme_compiled_quote_syntax_type ] = "<quote-syntax-semi-code>" ; 
  type_names [scheme_letrec_type ] = "<letrec-code>" ; 
  type_names [scheme_let_one_type ] = "<let-one-code>" ; 
  type_names [scheme_quote_compilation_type ] = "<quote-code>" ; 
  type_names [scheme_eval_waiting_type ] = "<eval-waiting>" ; 
  type_names [scheme_void_type ] = "<void>" ; 
  type_names [scheme_prim_type ] = "<primitive>" ; 
  type_names [scheme_closed_prim_type ] = "<primitive-closure>" ; 
  type_names [scheme_closure_type ] = "<procedure>" ; 
  type_names [scheme_native_closure_type ] = "<procedure>" ; 
  type_names [scheme_cont_type ] = "<continuation>" ; 
  type_names [scheme_tail_call_waiting_type ] = "<tail-call-waiting>" ; 
  type_names [scheme_null_type ] = "<empty-list>" ; 
  type_names [scheme_pair_type ] = "<pair>" ; 
  type_names [scheme_raw_pair_type ] = "<raw-pair>" ; 
  type_names [scheme_box_type ] = "<box>" ; 
  type_names [scheme_integer_type ] = "<fixnum-integer>" ; 
  type_names [scheme_double_type ] = "<inexact-number>" ; 
  type_names [scheme_float_type ] = "<inexact-number*>" ; 
  type_names [scheme_undefined_type ] = "<undefined>" ; 
  type_names [scheme_eof_type ] = "<eof>" ; 
  type_names [scheme_input_port_type ] = "<input-port>" ; 
  type_names [scheme_output_port_type ] = "<output-port>" ; 
  type_names [scheme_thread_type ] = "<thread>" ; 
  type_names [scheme_char_string_type ] = "<string>" ; 
  type_names [scheme_byte_string_type ] = "<byte-string>" ; 
  type_names [scheme_unix_path_type ] = "<unix-path>" ; 
  type_names [scheme_windows_path_type ] = "<windows-path>" ; 
  type_names [scheme_struct_property_type ] = "<struct-property>" ; 
  type_names [scheme_structure_type ] = "<struct>" ; 
  type_names [scheme_proc_struct_type ] = "<struct>" ; 
  type_names [scheme_symbol_type ] = "<symbol>" ; 
  type_names [scheme_keyword_type ] = "<keyword>" ; 
  type_names [scheme_syntax_compiler_type ] = "<syntax-compiler>" ; 
  type_names [scheme_macro_type ] = "<macro>" ; 
  type_names [scheme_lazy_macro_type ] = "<lazy-macro>" ; 
  type_names [scheme_vector_type ] = "<vector>" ; 
  type_names [scheme_bignum_type ] = "<bignum-integer>" ; 
  type_names [scheme_escaping_cont_type ] = "<escape-continuation>" ; 
  type_names [scheme_sema_type ] = "<semaphore>" ; 
  type_names [scheme_channel_type ] = "<channel>" ; 
  type_names [scheme_channel_put_type ] = "<channel-put>" ; 
  type_names [scheme_hash_table_type ] = "<hash-table>" ; 
  type_names [scheme_bucket_table_type ] = "<hash-table>" ; 
  type_names [scheme_module_registry_type ] = "<module-registry>" ; 
  type_names [scheme_case_closure_type ] = "<procedure>" ; 
  type_names [scheme_placeholder_type ] = "<placeholder>" ; 
  type_names [scheme_multiple_values_type ] = "<syntax<->datum-placeholder>" ; 
  type_names [scheme_weak_box_type ] = "<weak-box>" ; 
  type_names [scheme_ephemeron_type ] = "<ephemeron>" ; 
  type_names [scheme_rational_type ] = "<fractional-number>" ; 
  type_names [scheme_complex_type ] = "<complex-number>" ; 
  type_names [scheme_complex_izi_type ] = "<inexactly-real-number>" ; 
  type_names [scheme_struct_type_type ] = "<struct-type>" ; 
  type_names [scheme_listener_type ] = "<tcp-listener>" ; 
  type_names [scheme_tcp_accept_evt_type ] = "<tcp-accept-evt>" ; 
  type_names [scheme_namespace_type ] = "<namespace>" ; 
  type_names [scheme_config_type ] = "<parameterization>" ; 
  type_names [scheme_will_executor_type ] = "<will-executor>" ; 
  type_names [scheme_random_state_type ] = "<pseudo-random-generator>" ; 
  type_names [scheme_regexp_type ] = "<regexp>" ; 
  type_names [scheme_rename_table_type ] = "<rename-table>" ; 
  type_names [scheme_bucket_type ] = "<hash-table-bucket>" ; 
  type_names [scheme_resolve_prefix_type ] = "<resolve-prefix>" ; 
  type_names [scheme_readtable_type ] = "<readtable>" ; 
  type_names [scheme_compilation_top_type ] = "<compiled-code>" ; 
  type_names [scheme_svector_type ] = "<short-vector>" ; 
  type_names [scheme_custodian_type ] = "<custodian>" ; 
  type_names [scheme_cust_box_type ] = "<custodian-box>" ; 
  type_names [scheme_cont_mark_set_type ] = "<continuation-mark-set>" ; 
  type_names [scheme_cont_mark_chain_type ] = "<chain>" ; 
  type_names [scheme_inspector_type ] = "<inspector>" ; 
  type_names [scheme_stx_type ] = "<syntax>" ; 
  type_names [scheme_stx_offset_type ] = "<internal-syntax-offset>" ; 
  type_names [scheme_expanded_syntax_type ] = "<expanded-syntax>" ; 
  type_names [scheme_set_macro_type ] = "<set!-transformer>" ; 
  type_names [scheme_id_macro_type ] = "<rename-transformer>" ; 
  type_names [scheme_module_type ] = "<module-code>" ; 
  type_names [scheme_module_index_type ] = "<module-path-index>" ; 
  type_names [scheme_subprocess_type ] = "<subprocess>" ; 
  type_names [scheme_cpointer_type ] = "<cpointer>" ; 
  type_names [scheme_offset_cpointer_type ] = "<cpointer>" ; 
  type_names [scheme_wrap_chunk_type ] = "<wrap-chunk>" ; 
  type_names [scheme_security_guard_type ] = "<security-guard>" ; 
  type_names [scheme_indent_type ] = "<internal-indentation>" ; 
  type_names [scheme_udp_type ] = "<udp-socket>" ; 
  type_names [scheme_udp_evt_type ] = "<udp-socket-evt>" ; 
  type_names [scheme_evt_set_type ] = "<evt-set>" ; 
  type_names [scheme_wrap_evt_type ] = "<evt>" ; 
  type_names [scheme_handle_evt_type ] = "<evt>" ; 
  type_names [scheme_nack_evt_type ] = "<evt>" ; 
  type_names [scheme_nack_guard_evt_type ] = "<evt>" ; 
  type_names [scheme_poll_evt_type ] = "<evt>" ; 
  type_names [scheme_semaphore_repost_type ] = "<semaphore-peek>" ; 
  type_names [scheme_alarm_type ] = "<alarm-evt>" ; 
  type_names [scheme_progress_evt_type ] = "<progress-evt>" ; 
  type_names [scheme_write_evt_type ] = "<write-evt>" ; 
  type_names [scheme_always_evt_type ] = "<always-evt>" ; 
  type_names [scheme_never_evt_type ] = "<never-evt>" ; 
  type_names [scheme_thread_resume_type ] = "<thread-resume-evt>" ; 
  type_names [scheme_thread_suspend_type ] = "<thread-suspend-evt>" ; 
  type_names [scheme_thread_dead_type ] = "<thread-dead-evt>" ; 
  type_names [scheme_thread_set_type ] = "<thread-set>" ; 
  type_names [scheme_thread_cell_type ] = "<thread-cell>" ; 
  type_names [scheme_thread_cell_values_type ] = "<thread-cell-values>" ; 
  type_names [scheme_prompt_tag_type ] = "<continuation-prompt-tag>" ; 
  type_names [scheme_string_converter_type ] = "<string-converter>" ; 
  type_names [scheme_channel_syncer_type ] = "<channel-syncer>" ; 
  type_names [scheme_special_comment_type ] = "<special-comment>" ; 
  type_names [scheme_certifications_type ] = "<certifications>" ; 
  type_names [scheme_global_ref_type ] = "<variable-reference>" ; 
  type_names [scheme_intdef_context_type ] = "<internal-definition-context>" ; 
  type_names [scheme_lexical_rib_type ] = "<internal:lexical-rib>" ; 
  type_names [scheme_already_comp_type ] = "<internal:already-compiled>" ; 
  type_names [_scheme_values_types_ ] = "<resurrected>" ; 
  type_names [_scheme_compiled_values_types_ ] = "<internal>" ; 
}
/* this far 312 */
/* this far 307 */
/* this far 302 */
/* this far 297 */
/* this far 292 */
Scheme_Type scheme_make_type (const char * name ) {
  DECL_RET_SAVE (Scheme_Type ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(name, 0)));
# define XfOrM3_COUNT (1)
# define SETUP_XfOrM3(x) SETUP(XfOrM3_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! type_names )
    FUNCCALL(SETUP_XfOrM3(_), init_type_arrays () ); 
  if (maxtype == allocmax ) {
    void * naya ; 
    long n ; 
    BLOCK_SETUP((PUSH(naya, 0+XfOrM3_COUNT)));
#   define XfOrM5_COUNT (1+XfOrM3_COUNT)
#   define SETUP_XfOrM5(x) SETUP(XfOrM5_COUNT)
    naya = NULLED_OUT ; 
    allocmax += 20 ; 
    naya = FUNCCALL(SETUP_XfOrM5(_), GC_malloc (allocmax * sizeof (char * ) ) ); 
    (memcpy (naya , type_names , maxtype * sizeof (char * ) ) ) ; 
    type_names = (char * * ) naya ; 
    naya = FUNCCALL(SETUP_XfOrM5(_), GC_malloc_atomic (n = allocmax * sizeof (Scheme_Type_Reader ) ) ); 
    (memset ((char * ) naya , 0 , n ) ) ; 
    (memcpy (naya , scheme_type_readers , maxtype * sizeof (Scheme_Type_Reader ) ) ) ; 
    scheme_type_readers = (Scheme_Type_Reader * ) naya ; 
    naya = FUNCCALL(SETUP_XfOrM5(_), GC_malloc_atomic (n = allocmax * sizeof (Scheme_Type_Writer ) ) ); 
    (memset ((char * ) naya , 0 , n ) ) ; 
    (memcpy (naya , scheme_type_writers , maxtype * sizeof (Scheme_Type_Writer ) ) ) ; 
    scheme_type_writers = (Scheme_Type_Writer * ) naya ; 
    naya = FUNCCALL(SETUP_XfOrM5(_), GC_malloc_atomic (n = allocmax * sizeof (Scheme_Equal_Proc ) ) ); 
    (memset ((char * ) naya , 0 , n ) ) ; 
    (memcpy (naya , scheme_type_equals , maxtype * sizeof (Scheme_Equal_Proc ) ) ) ; 
    scheme_type_equals = (Scheme_Equal_Proc * ) naya ; 
    naya = FUNCCALL(SETUP_XfOrM5(_), GC_malloc_atomic (n = allocmax * sizeof (Scheme_Primary_Hash_Proc ) ) ); 
    (memset ((char * ) naya , 0 , n ) ) ; 
    (memcpy (naya , scheme_type_hash1s , maxtype * sizeof (Scheme_Primary_Hash_Proc ) ) ) ; 
    scheme_type_hash1s = (Scheme_Primary_Hash_Proc * ) naya ; 
    naya = FUNCCALL(SETUP_XfOrM5(_), GC_malloc_atomic (n = allocmax * sizeof (Scheme_Secondary_Hash_Proc ) ) ); 
    (memset ((char * ) naya , 0 , n ) ) ; 
    (memcpy (naya , scheme_type_hash2s , maxtype * sizeof (Scheme_Secondary_Hash_Proc ) ) ) ; 
    scheme_type_hash2s = (Scheme_Secondary_Hash_Proc * ) naya ; 
  }
  {
    char * tn ; 
    BLOCK_SETUP((PUSH(tn, 0+XfOrM3_COUNT)));
#   define XfOrM4_COUNT (1+XfOrM3_COUNT)
#   define SETUP_XfOrM4(x) SETUP(XfOrM4_COUNT)
    tn = NULLED_OUT ; 
    tn = FUNCCALL(SETUP_XfOrM4(_), scheme_strdup (name ) ); 
    type_names [maxtype ] = tn ; 
  }
  RET_VALUE_START (maxtype ++ ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
char * scheme_get_type_name (Scheme_Type t ) {
  /* No conversion */
  if (t < 0 || t >= maxtype )
    return "<bad-value>" ; 
  return type_names [t ] ; 
}
void scheme_install_type_reader (Scheme_Type t , Scheme_Type_Reader f ) {
  /* No conversion */
  if (t < 0 || t >= maxtype )
    return ; 
  scheme_type_readers [t ] = f ; 
}
void scheme_install_type_writer (Scheme_Type t , Scheme_Type_Writer f ) {
  /* No conversion */
  if (t < 0 || t >= maxtype )
    return ; 
  scheme_type_writers [t ] = f ; 
}
void scheme_set_type_equality (Scheme_Type t , Scheme_Equal_Proc f , Scheme_Primary_Hash_Proc hash1 , Scheme_Secondary_Hash_Proc hash2 ) {
  /* No conversion */
  if (t < 0 || t >= maxtype )
    return ; 
  scheme_type_equals [t ] = f ; 
  scheme_type_hash1s [t ] = hash1 ; 
  scheme_type_hash2s [t ] = hash2 ; 
}
int scheme_num_types (void ) {
  /* No conversion */
  return maxtype ; 
}
static int bad_trav_SIZE (void * p ) {
  printf ("Shouldn't get here.\n" ) ; 
  exit (1 ) ; 
}
static int bad_trav_MARK (void * p ) {
  printf ("Shouldn't get here.\n" ) ; 
  exit (1 ) ; 
}
static int bad_trav_FIXUP (void * p ) {
  printf ("Shouldn't get here.\n" ) ; 
  exit (1 ) ; 
}
static void MARK_cjs (Scheme_Continuation_Jump_State * cjs ) {
  GC_mark (cjs -> jumping_to_continuation ) ; 
  GC_mark (cjs -> val ) ; 
}
static void FIXUP_cjs (Scheme_Continuation_Jump_State * cjs ) {
  GC_fixup (& (cjs -> jumping_to_continuation ) ) ; 
  GC_fixup (& (cjs -> val ) ) ; 
}
static void MARK_stack_state (Scheme_Stack_State * ss ) {
}
static void FIXUP_stack_state (Scheme_Stack_State * ss ) {
}
static void MARK_jmpup (Scheme_Jumpup_Buf * buf ) {
  GC_mark (buf -> stack_copy ) ; 
  GC_mark (buf -> cont ) ; 
  GC_mark (buf -> external_stack ) ; 
  if (buf -> stack_copy )
    GC_mark_variable_stack (buf -> gc_var_stack , (long ) buf -> stack_copy - (long ) buf -> stack_from , (char * ) buf -> stack_copy + buf -> stack_size , buf -> stack_copy ) ; 
}
static void FIXUP_jmpup (Scheme_Jumpup_Buf * buf ) {
  void * new_stack ; 
  new_stack = GC_resolve (buf -> stack_copy ) ; 
  GC_fixup (& (buf -> stack_copy ) ) ; 
  GC_fixup (& (buf -> cont ) ) ; 
  GC_fixup (& (buf -> external_stack ) ) ; 
  if (buf -> stack_copy )
    GC_fixup_variable_stack (buf -> gc_var_stack , (long ) new_stack - (long ) buf -> stack_from , (char * ) new_stack + buf -> stack_size , new_stack ) ; 
}
static int variable_obj_SIZE (void * p ) {
  return ((sizeof (Scheme_Bucket_With_Home ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int variable_obj_MARK (void * p ) {
  Scheme_Bucket * b = (Scheme_Bucket * ) p ; 
  GC_mark (b -> key ) ; 
  GC_mark (b -> val ) ; 
  GC_mark (((Scheme_Bucket_With_Home * ) b ) -> home ) ; 
  return ((sizeof (Scheme_Bucket_With_Home ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int variable_obj_FIXUP (void * p ) {
  Scheme_Bucket * b = (Scheme_Bucket * ) p ; 
  GC_fixup (& (b -> key ) ) ; 
  GC_fixup (& (b -> val ) ) ; 
  GC_fixup (& (((Scheme_Bucket_With_Home * ) b ) -> home ) ) ; 
  return ((sizeof (Scheme_Bucket_With_Home ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int module_var_SIZE (void * p ) {
  return ((sizeof (Module_Variable ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int module_var_MARK (void * p ) {
  Module_Variable * mv = (Module_Variable * ) p ; 
  GC_mark (mv -> modidx ) ; 
  GC_mark (mv -> sym ) ; 
  GC_mark (mv -> insp ) ; 
  return ((sizeof (Module_Variable ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int module_var_FIXUP (void * p ) {
  Module_Variable * mv = (Module_Variable * ) p ; 
  GC_fixup (& (mv -> modidx ) ) ; 
  GC_fixup (& (mv -> sym ) ) ; 
  GC_fixup (& (mv -> insp ) ) ; 
  return ((sizeof (Module_Variable ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int bucket_obj_SIZE (void * p ) {
  return ((sizeof (Scheme_Bucket ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int bucket_obj_MARK (void * p ) {
  Scheme_Bucket * b = (Scheme_Bucket * ) p ; 
  GC_mark (b -> key ) ; 
  GC_mark (b -> val ) ; 
  return ((sizeof (Scheme_Bucket ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int bucket_obj_FIXUP (void * p ) {
  Scheme_Bucket * b = (Scheme_Bucket * ) p ; 
  GC_fixup (& (b -> key ) ) ; 
  GC_fixup (& (b -> val ) ) ; 
  return ((sizeof (Scheme_Bucket ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int local_obj_SIZE (void * p ) {
  return ((sizeof (Scheme_Local ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int local_obj_MARK (void * p ) {
  return ((sizeof (Scheme_Local ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int local_obj_FIXUP (void * p ) {
  return ((sizeof (Scheme_Local ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int toplevel_obj_SIZE (void * p ) {
  return ((sizeof (Scheme_Toplevel ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int toplevel_obj_MARK (void * p ) {
  return ((sizeof (Scheme_Toplevel ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int toplevel_obj_FIXUP (void * p ) {
  return ((sizeof (Scheme_Toplevel ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int quotesyntax_obj_SIZE (void * p ) {
  return ((sizeof (Scheme_Quote_Syntax ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int quotesyntax_obj_MARK (void * p ) {
  return ((sizeof (Scheme_Quote_Syntax ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int quotesyntax_obj_FIXUP (void * p ) {
  return ((sizeof (Scheme_Quote_Syntax ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int cpointer_obj_SIZE (void * p ) {
  return ((sizeof (Scheme_Cptr ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int cpointer_obj_MARK (void * p ) {
  GC_mark ((((Scheme_Cptr * ) (p ) ) -> val ) ) ; 
  GC_mark ((((Scheme_Cptr * ) (p ) ) -> type ) ) ; 
  return ((sizeof (Scheme_Cptr ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int cpointer_obj_FIXUP (void * p ) {
  GC_fixup (& ((((Scheme_Cptr * ) (p ) ) -> val ) ) ) ; 
  GC_fixup (& ((((Scheme_Cptr * ) (p ) ) -> type ) ) ) ; 
  return ((sizeof (Scheme_Cptr ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int offset_cpointer_obj_SIZE (void * p ) {
  return ((sizeof (Scheme_Offset_Cptr ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int offset_cpointer_obj_MARK (void * p ) {
  GC_mark ((((Scheme_Cptr * ) (p ) ) -> val ) ) ; 
  GC_mark ((((Scheme_Cptr * ) (p ) ) -> type ) ) ; 
  return ((sizeof (Scheme_Offset_Cptr ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int offset_cpointer_obj_FIXUP (void * p ) {
  GC_fixup (& ((((Scheme_Cptr * ) (p ) ) -> val ) ) ) ; 
  GC_fixup (& ((((Scheme_Cptr * ) (p ) ) -> type ) ) ) ; 
  return ((sizeof (Scheme_Offset_Cptr ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int second_of_cons_SIZE (void * p ) {
  return ((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int second_of_cons_MARK (void * p ) {
  GC_mark ((((Scheme_Simple_Object * ) ((Scheme_Object * ) p ) ) -> u . two_ptr_val . ptr2 ) ) ; 
  return ((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int second_of_cons_FIXUP (void * p ) {
  GC_fixup (& ((((Scheme_Simple_Object * ) ((Scheme_Object * ) p ) ) -> u . two_ptr_val . ptr2 ) ) ) ; 
  return ((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int twoptr_obj_SIZE (void * p ) {
  return ((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int twoptr_obj_MARK (void * p ) {
  GC_mark ((((Scheme_Simple_Object * ) ((Scheme_Object * ) p ) ) -> u . two_ptr_val . ptr1 ) ) ; 
  GC_mark ((((Scheme_Simple_Object * ) ((Scheme_Object * ) p ) ) -> u . two_ptr_val . ptr2 ) ) ; 
  return ((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int twoptr_obj_FIXUP (void * p ) {
  GC_fixup (& ((((Scheme_Simple_Object * ) ((Scheme_Object * ) p ) ) -> u . two_ptr_val . ptr1 ) ) ) ; 
  GC_fixup (& ((((Scheme_Simple_Object * ) ((Scheme_Object * ) p ) ) -> u . two_ptr_val . ptr2 ) ) ) ; 
  return ((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int iptr_obj_SIZE (void * p ) {
  return ((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int iptr_obj_MARK (void * p ) {
  GC_mark ((((Scheme_Simple_Object * ) ((Scheme_Object * ) p ) ) -> u . ptr_int_val . ptr ) ) ; 
  return ((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int iptr_obj_FIXUP (void * p ) {
  GC_fixup (& ((((Scheme_Simple_Object * ) ((Scheme_Object * ) p ) ) -> u . ptr_int_val . ptr ) ) ) ; 
  return ((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int small_object_SIZE (void * p ) {
  return ((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int small_object_MARK (void * p ) {
  GC_mark (((Scheme_Small_Object * ) p ) -> u . ptr_value ) ; 
  return ((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int small_object_FIXUP (void * p ) {
  GC_fixup (& (((Scheme_Small_Object * ) p ) -> u . ptr_value ) ) ; 
  return ((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int app_rec_SIZE (void * p ) {
  Scheme_App_Rec * r = (Scheme_App_Rec * ) p ; 
  return (((sizeof (Scheme_App_Rec ) + (r -> num_args * sizeof (Scheme_Object * ) ) + ((r -> num_args + 1 ) * sizeof (char ) ) ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int app_rec_MARK (void * p ) {
  Scheme_App_Rec * r = (Scheme_App_Rec * ) p ; 
  int i = r -> num_args + 1 ; 
  while (i -- ) GC_mark (r -> args [i ] ) ; 
  return (((sizeof (Scheme_App_Rec ) + (r -> num_args * sizeof (Scheme_Object * ) ) + ((r -> num_args + 1 ) * sizeof (char ) ) ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int app_rec_FIXUP (void * p ) {
  Scheme_App_Rec * r = (Scheme_App_Rec * ) p ; 
  int i = r -> num_args + 1 ; 
  while (i -- ) GC_fixup (& (r -> args [i ] ) ) ; 
  return (((sizeof (Scheme_App_Rec ) + (r -> num_args * sizeof (Scheme_Object * ) ) + ((r -> num_args + 1 ) * sizeof (char ) ) ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int app2_rec_SIZE (void * p ) {
  return ((sizeof (Scheme_App2_Rec ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int app2_rec_MARK (void * p ) {
  Scheme_App2_Rec * r = (Scheme_App2_Rec * ) p ; 
  GC_mark (r -> rator ) ; 
  GC_mark (r -> rand ) ; 
  return ((sizeof (Scheme_App2_Rec ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int app2_rec_FIXUP (void * p ) {
  Scheme_App2_Rec * r = (Scheme_App2_Rec * ) p ; 
  GC_fixup (& (r -> rator ) ) ; 
  GC_fixup (& (r -> rand ) ) ; 
  return ((sizeof (Scheme_App2_Rec ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int app3_rec_SIZE (void * p ) {
  return ((sizeof (Scheme_App3_Rec ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int app3_rec_MARK (void * p ) {
  Scheme_App3_Rec * r = (Scheme_App3_Rec * ) p ; 
  GC_mark (r -> rator ) ; 
  GC_mark (r -> rand1 ) ; 
  GC_mark (r -> rand2 ) ; 
  return ((sizeof (Scheme_App3_Rec ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int app3_rec_FIXUP (void * p ) {
  Scheme_App3_Rec * r = (Scheme_App3_Rec * ) p ; 
  GC_fixup (& (r -> rator ) ) ; 
  GC_fixup (& (r -> rand1 ) ) ; 
  GC_fixup (& (r -> rand2 ) ) ; 
  return ((sizeof (Scheme_App3_Rec ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int seq_rec_SIZE (void * p ) {
  Scheme_Sequence * s = (Scheme_Sequence * ) p ; 
  return (((sizeof (Scheme_Sequence ) + ((s -> count - 1 ) * sizeof (Scheme_Object * ) ) ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int seq_rec_MARK (void * p ) {
  Scheme_Sequence * s = (Scheme_Sequence * ) p ; 
  int i = s -> count ; 
  while (i -- ) GC_mark (s -> array [i ] ) ; 
  return (((sizeof (Scheme_Sequence ) + ((s -> count - 1 ) * sizeof (Scheme_Object * ) ) ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int seq_rec_FIXUP (void * p ) {
  Scheme_Sequence * s = (Scheme_Sequence * ) p ; 
  int i = s -> count ; 
  while (i -- ) GC_fixup (& (s -> array [i ] ) ) ; 
  return (((sizeof (Scheme_Sequence ) + ((s -> count - 1 ) * sizeof (Scheme_Object * ) ) ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int branch_rec_SIZE (void * p ) {
  return ((sizeof (Scheme_Branch_Rec ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int branch_rec_MARK (void * p ) {
  Scheme_Branch_Rec * b = (Scheme_Branch_Rec * ) p ; 
  GC_mark (b -> test ) ; 
  GC_mark (b -> tbranch ) ; 
  GC_mark (b -> fbranch ) ; 
  return ((sizeof (Scheme_Branch_Rec ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int branch_rec_FIXUP (void * p ) {
  Scheme_Branch_Rec * b = (Scheme_Branch_Rec * ) p ; 
  GC_fixup (& (b -> test ) ) ; 
  GC_fixup (& (b -> tbranch ) ) ; 
  GC_fixup (& (b -> fbranch ) ) ; 
  return ((sizeof (Scheme_Branch_Rec ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int unclosed_proc_SIZE (void * p ) {
  return ((sizeof (Scheme_Closure_Data ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int unclosed_proc_MARK (void * p ) {
  Scheme_Closure_Data * d = (Scheme_Closure_Data * ) p ; 
  GC_mark (d -> name ) ; 
  GC_mark (d -> code ) ; 
  GC_mark (d -> closure_map ) ; 
  GC_mark (d -> u . native_code ) ; 
  GC_mark (d -> context ) ; 
  return ((sizeof (Scheme_Closure_Data ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int unclosed_proc_FIXUP (void * p ) {
  Scheme_Closure_Data * d = (Scheme_Closure_Data * ) p ; 
  GC_fixup (& (d -> name ) ) ; 
  GC_fixup (& (d -> code ) ) ; 
  GC_fixup (& (d -> closure_map ) ) ; 
  GC_fixup (& (d -> u . native_code ) ) ; 
  GC_fixup (& (d -> context ) ) ; 
  return ((sizeof (Scheme_Closure_Data ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int let_value_SIZE (void * p ) {
  return ((sizeof (Scheme_Let_Value ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int let_value_MARK (void * p ) {
  Scheme_Let_Value * l = (Scheme_Let_Value * ) p ; 
  GC_mark (l -> value ) ; 
  GC_mark (l -> body ) ; 
  return ((sizeof (Scheme_Let_Value ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int let_value_FIXUP (void * p ) {
  Scheme_Let_Value * l = (Scheme_Let_Value * ) p ; 
  GC_fixup (& (l -> value ) ) ; 
  GC_fixup (& (l -> body ) ) ; 
  return ((sizeof (Scheme_Let_Value ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int let_void_SIZE (void * p ) {
  return ((sizeof (Scheme_Let_Void ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int let_void_MARK (void * p ) {
  Scheme_Let_Void * l = (Scheme_Let_Void * ) p ; 
  GC_mark (l -> body ) ; 
  return ((sizeof (Scheme_Let_Void ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int let_void_FIXUP (void * p ) {
  Scheme_Let_Void * l = (Scheme_Let_Void * ) p ; 
  GC_fixup (& (l -> body ) ) ; 
  return ((sizeof (Scheme_Let_Void ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int letrec_SIZE (void * p ) {
  return ((sizeof (Scheme_Letrec ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int letrec_MARK (void * p ) {
  Scheme_Letrec * l = (Scheme_Letrec * ) p ; 
  GC_mark (l -> procs ) ; 
  GC_mark (l -> body ) ; 
  return ((sizeof (Scheme_Letrec ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int letrec_FIXUP (void * p ) {
  Scheme_Letrec * l = (Scheme_Letrec * ) p ; 
  GC_fixup (& (l -> procs ) ) ; 
  GC_fixup (& (l -> body ) ) ; 
  return ((sizeof (Scheme_Letrec ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int let_one_SIZE (void * p ) {
  return ((sizeof (Scheme_Let_One ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int let_one_MARK (void * p ) {
  Scheme_Let_One * l = (Scheme_Let_One * ) p ; 
  GC_mark (l -> value ) ; 
  GC_mark (l -> body ) ; 
  return ((sizeof (Scheme_Let_One ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int let_one_FIXUP (void * p ) {
  Scheme_Let_One * l = (Scheme_Let_One * ) p ; 
  GC_fixup (& (l -> value ) ) ; 
  GC_fixup (& (l -> body ) ) ; 
  return ((sizeof (Scheme_Let_One ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int with_cont_mark_SIZE (void * p ) {
  return ((sizeof (Scheme_With_Continuation_Mark ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int with_cont_mark_MARK (void * p ) {
  Scheme_With_Continuation_Mark * w = (Scheme_With_Continuation_Mark * ) p ; 
  GC_mark (w -> key ) ; 
  GC_mark (w -> val ) ; 
  GC_mark (w -> body ) ; 
  return ((sizeof (Scheme_With_Continuation_Mark ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int with_cont_mark_FIXUP (void * p ) {
  Scheme_With_Continuation_Mark * w = (Scheme_With_Continuation_Mark * ) p ; 
  GC_fixup (& (w -> key ) ) ; 
  GC_fixup (& (w -> val ) ) ; 
  GC_fixup (& (w -> body ) ) ; 
  return ((sizeof (Scheme_With_Continuation_Mark ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int comp_let_value_SIZE (void * p ) {
  return ((sizeof (Scheme_Compiled_Let_Value ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int comp_let_value_MARK (void * p ) {
  Scheme_Compiled_Let_Value * c = (Scheme_Compiled_Let_Value * ) p ; 
  GC_mark (c -> flags ) ; 
  GC_mark (c -> value ) ; 
  GC_mark (c -> body ) ; 
  return ((sizeof (Scheme_Compiled_Let_Value ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int comp_let_value_FIXUP (void * p ) {
  Scheme_Compiled_Let_Value * c = (Scheme_Compiled_Let_Value * ) p ; 
  GC_fixup (& (c -> flags ) ) ; 
  GC_fixup (& (c -> value ) ) ; 
  GC_fixup (& (c -> body ) ) ; 
  return ((sizeof (Scheme_Compiled_Let_Value ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int let_header_SIZE (void * p ) {
  return ((sizeof (Scheme_Let_Header ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int let_header_MARK (void * p ) {
  Scheme_Let_Header * h = (Scheme_Let_Header * ) p ; 
  GC_mark (h -> body ) ; 
  return ((sizeof (Scheme_Let_Header ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int let_header_FIXUP (void * p ) {
  Scheme_Let_Header * h = (Scheme_Let_Header * ) p ; 
  GC_fixup (& (h -> body ) ) ; 
  return ((sizeof (Scheme_Let_Header ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int prim_proc_SIZE (void * p ) {
  Scheme_Primitive_Proc * prim = (Scheme_Primitive_Proc * ) p ; 
  return ((prim -> pp . flags & 4096 ) ? (((sizeof (Scheme_Primitive_Closure ) + (1 << 3 ) - 1 ) >> 3 ) + ((Scheme_Primitive_Closure * ) prim ) -> count - 1 ) : ((prim -> pp . flags & 256 ) ? ((sizeof (Scheme_Prim_W_Result_Arity ) + (1 << 3 ) - 1 ) >> 3 ) : ((sizeof (Scheme_Primitive_Proc ) + (1 << 3 ) - 1 ) >> 3 ) ) ) ; 
}
static int prim_proc_MARK (void * p ) {
  Scheme_Primitive_Proc * prim = (Scheme_Primitive_Proc * ) p ; 
  GC_mark (prim -> name ) ; 
  if (prim -> mina < 0 ) {
    GC_mark (prim -> mu . cases ) ; 
  }
  if (prim -> pp . flags & 4096 ) {
    Scheme_Primitive_Closure * cc = (Scheme_Primitive_Closure * ) prim ; 
    int i ; 
    for (i = cc -> count ; i -- ; ) {
      GC_mark (cc -> val [i ] ) ; 
    }
  }
  return ((prim -> pp . flags & 4096 ) ? (((sizeof (Scheme_Primitive_Closure ) + (1 << 3 ) - 1 ) >> 3 ) + ((Scheme_Primitive_Closure * ) prim ) -> count - 1 ) : ((prim -> pp . flags & 256 ) ? ((sizeof (Scheme_Prim_W_Result_Arity ) + (1 << 3 ) - 1 ) >> 3 ) : ((sizeof (Scheme_Primitive_Proc ) + (1 << 3 ) - 1 ) >> 3 ) ) ) ; 
}
static int prim_proc_FIXUP (void * p ) {
  Scheme_Primitive_Proc * prim = (Scheme_Primitive_Proc * ) p ; 
  GC_fixup (& (prim -> name ) ) ; 
  if (prim -> mina < 0 ) {
    GC_fixup (& (prim -> mu . cases ) ) ; 
  }
  if (prim -> pp . flags & 4096 ) {
    Scheme_Primitive_Closure * cc = (Scheme_Primitive_Closure * ) prim ; 
    int i ; 
    for (i = cc -> count ; i -- ; ) {
      GC_fixup (& (cc -> val [i ] ) ) ; 
    }
  }
  return ((prim -> pp . flags & 4096 ) ? (((sizeof (Scheme_Primitive_Closure ) + (1 << 3 ) - 1 ) >> 3 ) + ((Scheme_Primitive_Closure * ) prim ) -> count - 1 ) : ((prim -> pp . flags & 256 ) ? ((sizeof (Scheme_Prim_W_Result_Arity ) + (1 << 3 ) - 1 ) >> 3 ) : ((sizeof (Scheme_Primitive_Proc ) + (1 << 3 ) - 1 ) >> 3 ) ) ) ; 
}
static int closed_prim_proc_SIZE (void * p ) {
  Scheme_Closed_Primitive_Proc * c = (Scheme_Closed_Primitive_Proc * ) p ; 
  return ((c -> pp . flags & 256 ) ? ((sizeof (Scheme_Closed_Prim_W_Result_Arity ) + (1 << 3 ) - 1 ) >> 3 ) : ((c -> mina == - 2 ) ? ((sizeof (Scheme_Closed_Case_Primitive_Proc ) + (1 << 3 ) - 1 ) >> 3 ) : ((sizeof (Scheme_Closed_Primitive_Proc ) + (1 << 3 ) - 1 ) >> 3 ) ) ) ; 
}
static int closed_prim_proc_MARK (void * p ) {
  Scheme_Closed_Primitive_Proc * c = (Scheme_Closed_Primitive_Proc * ) p ; 
  GC_mark (c -> name ) ; 
  GC_mark ((((Scheme_Closed_Primitive_Proc * ) (c ) ) -> data ) ) ; 
  if (c -> mina == - 2 ) {
    GC_mark (((Scheme_Closed_Case_Primitive_Proc * ) c ) -> cases ) ; 
  }
  return ((c -> pp . flags & 256 ) ? ((sizeof (Scheme_Closed_Prim_W_Result_Arity ) + (1 << 3 ) - 1 ) >> 3 ) : ((c -> mina == - 2 ) ? ((sizeof (Scheme_Closed_Case_Primitive_Proc ) + (1 << 3 ) - 1 ) >> 3 ) : ((sizeof (Scheme_Closed_Primitive_Proc ) + (1 << 3 ) - 1 ) >> 3 ) ) ) ; 
}
static int closed_prim_proc_FIXUP (void * p ) {
  Scheme_Closed_Primitive_Proc * c = (Scheme_Closed_Primitive_Proc * ) p ; 
  GC_fixup (& (c -> name ) ) ; 
  GC_fixup (& ((((Scheme_Closed_Primitive_Proc * ) (c ) ) -> data ) ) ) ; 
  if (c -> mina == - 2 ) {
    GC_fixup (& (((Scheme_Closed_Case_Primitive_Proc * ) c ) -> cases ) ) ; 
  }
  return ((c -> pp . flags & 256 ) ? ((sizeof (Scheme_Closed_Prim_W_Result_Arity ) + (1 << 3 ) - 1 ) >> 3 ) : ((c -> mina == - 2 ) ? ((sizeof (Scheme_Closed_Case_Primitive_Proc ) + (1 << 3 ) - 1 ) >> 3 ) : ((sizeof (Scheme_Closed_Primitive_Proc ) + (1 << 3 ) - 1 ) >> 3 ) ) ) ; 
}
static int scm_closure_SIZE (void * p ) {
  Scheme_Closure * c = (Scheme_Closure * ) p ; 
  int closure_size = (c -> code ? ((Scheme_Closure_Data * ) GC_resolve (c -> code ) ) -> closure_size : 0 ) ; 
  return (((sizeof (Scheme_Closure ) + (closure_size - 1 ) * sizeof (Scheme_Object * ) ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int scm_closure_MARK (void * p ) {
  Scheme_Closure * c = (Scheme_Closure * ) p ; 
  int closure_size = (c -> code ? ((Scheme_Closure_Data * ) GC_resolve (c -> code ) ) -> closure_size : 0 ) ; 
  int i = closure_size ; 
  while (i -- ) GC_mark (c -> vals [i ] ) ; 
  GC_mark (c -> code ) ; 
  return (((sizeof (Scheme_Closure ) + (closure_size - 1 ) * sizeof (Scheme_Object * ) ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int scm_closure_FIXUP (void * p ) {
  Scheme_Closure * c = (Scheme_Closure * ) p ; 
  int closure_size = (c -> code ? ((Scheme_Closure_Data * ) GC_resolve (c -> code ) ) -> closure_size : 0 ) ; 
  int i = closure_size ; 
  while (i -- ) GC_fixup (& (c -> vals [i ] ) ) ; 
  GC_fixup (& (c -> code ) ) ; 
  return (((sizeof (Scheme_Closure ) + (closure_size - 1 ) * sizeof (Scheme_Object * ) ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int case_closure_SIZE (void * p ) {
  Scheme_Case_Lambda * c = (Scheme_Case_Lambda * ) p ; 
  return (((sizeof (Scheme_Case_Lambda ) + ((c -> count - 1 ) * sizeof (Scheme_Object * ) ) ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int case_closure_MARK (void * p ) {
  Scheme_Case_Lambda * c = (Scheme_Case_Lambda * ) p ; 
  int i ; 
  for (i = c -> count ; i -- ; ) GC_mark (c -> array [i ] ) ; 
  GC_mark (c -> name ) ; 
  GC_mark (c -> native_code ) ; 
  return (((sizeof (Scheme_Case_Lambda ) + ((c -> count - 1 ) * sizeof (Scheme_Object * ) ) ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int case_closure_FIXUP (void * p ) {
  Scheme_Case_Lambda * c = (Scheme_Case_Lambda * ) p ; 
  int i ; 
  for (i = c -> count ; i -- ; ) GC_fixup (& (c -> array [i ] ) ) ; 
  GC_fixup (& (c -> name ) ) ; 
  GC_fixup (& (c -> native_code ) ) ; 
  return (((sizeof (Scheme_Case_Lambda ) + ((c -> count - 1 ) * sizeof (Scheme_Object * ) ) ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int cont_proc_SIZE (void * p ) {
  return ((sizeof (Scheme_Cont ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int cont_proc_MARK (void * p ) {
  Scheme_Cont * c = (Scheme_Cont * ) p ; 
  GC_mark (c -> dw ) ; 
  GC_mark (c -> prompt_tag ) ; 
  GC_mark (c -> meta_continuation ) ; 
  GC_mark (c -> common_dw ) ; 
  GC_mark (c -> save_overflow ) ; 
  GC_mark (c -> runstack_copied ) ; 
  GC_mark (c -> runstack_owner ) ; 
  GC_mark (c -> cont_mark_stack_copied ) ; 
  GC_mark (c -> cont_mark_stack_owner ) ; 
  GC_mark (c -> init_config ) ; 
  GC_mark (c -> init_break_cell ) ; 
  GC_mark (c -> native_trace ) ; 
  MARK_jmpup (& c -> buf ) ; 
  MARK_cjs (& c -> cjs ) ; 
  MARK_stack_state (& c -> ss ) ; 
  GC_mark (c -> barrier_prompt ) ; 
  GC_mark (c -> runstack_start ) ; 
  GC_mark (c -> runstack_saved ) ; 
  GC_mark (c -> prompt_id ) ; 
  GC_mark (c -> prompt_buf ) ; 
  GC_mark (c -> value ) ; 
  GC_mark (c -> resume_to ) ; 
  GC_mark (c -> use_next_cont ) ; 
  GC_mark (c -> extra_marks ) ; 
  GC_mark (c -> shortcut_prompt ) ; 
  return ((sizeof (Scheme_Cont ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int cont_proc_FIXUP (void * p ) {
  Scheme_Cont * c = (Scheme_Cont * ) p ; 
  GC_fixup (& (c -> dw ) ) ; 
  GC_fixup (& (c -> prompt_tag ) ) ; 
  GC_fixup (& (c -> meta_continuation ) ) ; 
  GC_fixup (& (c -> common_dw ) ) ; 
  GC_fixup (& (c -> save_overflow ) ) ; 
  GC_fixup (& (c -> runstack_copied ) ) ; 
  GC_fixup (& (c -> runstack_owner ) ) ; 
  GC_fixup (& (c -> cont_mark_stack_copied ) ) ; 
  GC_fixup (& (c -> cont_mark_stack_owner ) ) ; 
  GC_fixup (& (c -> init_config ) ) ; 
  GC_fixup (& (c -> init_break_cell ) ) ; 
  GC_fixup (& (c -> native_trace ) ) ; 
  FIXUP_jmpup (& c -> buf ) ; 
  FIXUP_cjs (& c -> cjs ) ; 
  FIXUP_stack_state (& c -> ss ) ; 
  GC_fixup (& (c -> barrier_prompt ) ) ; 
  GC_fixup (& (c -> runstack_start ) ) ; 
  GC_fixup (& (c -> runstack_saved ) ) ; 
  GC_fixup (& (c -> prompt_id ) ) ; 
  GC_fixup (& (c -> prompt_buf ) ) ; 
  GC_fixup (& (c -> value ) ) ; 
  GC_fixup (& (c -> resume_to ) ) ; 
  GC_fixup (& (c -> use_next_cont ) ) ; 
  GC_fixup (& (c -> extra_marks ) ) ; 
  GC_fixup (& (c -> shortcut_prompt ) ) ; 
  return ((sizeof (Scheme_Cont ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int meta_cont_proc_SIZE (void * p ) {
  return ((sizeof (Scheme_Meta_Continuation ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int meta_cont_proc_MARK (void * p ) {
  Scheme_Meta_Continuation * c = (Scheme_Meta_Continuation * ) p ; 
  GC_mark (c -> prompt_tag ) ; 
  GC_mark (c -> overflow ) ; 
  GC_mark (c -> next ) ; 
  GC_mark (c -> cont_mark_stack_copied ) ; 
  return ((sizeof (Scheme_Meta_Continuation ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int meta_cont_proc_FIXUP (void * p ) {
  Scheme_Meta_Continuation * c = (Scheme_Meta_Continuation * ) p ; 
  GC_fixup (& (c -> prompt_tag ) ) ; 
  GC_fixup (& (c -> overflow ) ) ; 
  GC_fixup (& (c -> next ) ) ; 
  GC_fixup (& (c -> cont_mark_stack_copied ) ) ; 
  return ((sizeof (Scheme_Meta_Continuation ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_dyn_wind_SIZE (void * p ) {
  return ((sizeof (Scheme_Dynamic_Wind ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_dyn_wind_MARK (void * p ) {
  Scheme_Dynamic_Wind * dw = (Scheme_Dynamic_Wind * ) p ; 
  GC_mark (dw -> id ) ; 
  GC_mark (dw -> data ) ; 
  GC_mark (dw -> prompt_tag ) ; 
  GC_mark (dw -> prev ) ; 
  MARK_stack_state (& dw -> envss ) ; 
  return ((sizeof (Scheme_Dynamic_Wind ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_dyn_wind_FIXUP (void * p ) {
  Scheme_Dynamic_Wind * dw = (Scheme_Dynamic_Wind * ) p ; 
  GC_fixup (& (dw -> id ) ) ; 
  GC_fixup (& (dw -> data ) ) ; 
  GC_fixup (& (dw -> prompt_tag ) ) ; 
  GC_fixup (& (dw -> prev ) ) ; 
  FIXUP_stack_state (& dw -> envss ) ; 
  return ((sizeof (Scheme_Dynamic_Wind ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_overflow_SIZE (void * p ) {
  return ((sizeof (Scheme_Overflow ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_overflow_MARK (void * p ) {
  Scheme_Overflow * o = (Scheme_Overflow * ) p ; 
  GC_mark (o -> prev ) ; 
  GC_mark (o -> jmp ) ; 
  GC_mark (o -> id ) ; 
  return ((sizeof (Scheme_Overflow ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_overflow_FIXUP (void * p ) {
  Scheme_Overflow * o = (Scheme_Overflow * ) p ; 
  GC_fixup (& (o -> prev ) ) ; 
  GC_fixup (& (o -> jmp ) ) ; 
  GC_fixup (& (o -> id ) ) ; 
  return ((sizeof (Scheme_Overflow ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_overflow_jmp_SIZE (void * p ) {
  return ((sizeof (Scheme_Overflow_Jmp ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_overflow_jmp_MARK (void * p ) {
  Scheme_Overflow_Jmp * o = (Scheme_Overflow_Jmp * ) p ; 
  MARK_jmpup (& o -> cont ) ; 
  return ((sizeof (Scheme_Overflow_Jmp ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_overflow_jmp_FIXUP (void * p ) {
  Scheme_Overflow_Jmp * o = (Scheme_Overflow_Jmp * ) p ; 
  FIXUP_jmpup (& o -> cont ) ; 
  return ((sizeof (Scheme_Overflow_Jmp ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int escaping_cont_proc_SIZE (void * p ) {
  return ((sizeof (Scheme_Escaping_Cont ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int escaping_cont_proc_MARK (void * p ) {
  Scheme_Escaping_Cont * c = (Scheme_Escaping_Cont * ) p ; 
  GC_mark (c -> native_trace ) ; 
  GC_mark (c -> barrier_prompt ) ; 
  MARK_stack_state (& c -> envss ) ; 
  return ((sizeof (Scheme_Escaping_Cont ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int escaping_cont_proc_FIXUP (void * p ) {
  Scheme_Escaping_Cont * c = (Scheme_Escaping_Cont * ) p ; 
  GC_fixup (& (c -> native_trace ) ) ; 
  GC_fixup (& (c -> barrier_prompt ) ) ; 
  FIXUP_stack_state (& c -> envss ) ; 
  return ((sizeof (Scheme_Escaping_Cont ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int char_obj_SIZE (void * p ) {
  return ((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int char_obj_MARK (void * p ) {
  return ((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int char_obj_FIXUP (void * p ) {
  return ((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int bignum_obj_SIZE (void * p ) {
  Scheme_Bignum * b = (Scheme_Bignum * ) p ; 
  return ((! ((& ((Scheme_Bignum * ) b ) -> iso ) -> so . keyex & 0x2 ) ) ? ((sizeof (Scheme_Bignum ) + (1 << 3 ) - 1 ) >> 3 ) : ((sizeof (Small_Bignum ) + (1 << 3 ) - 1 ) >> 3 ) ) ; 
}
static int bignum_obj_MARK (void * p ) {
  Scheme_Bignum * b = (Scheme_Bignum * ) p ; 
  if (! ((& ((Scheme_Bignum * ) b ) -> iso ) -> so . keyex & 0x2 ) ) {
    GC_mark (b -> digits ) ; 
  }
  else {
  }
  return ((! ((& ((Scheme_Bignum * ) b ) -> iso ) -> so . keyex & 0x2 ) ) ? ((sizeof (Scheme_Bignum ) + (1 << 3 ) - 1 ) >> 3 ) : ((sizeof (Small_Bignum ) + (1 << 3 ) - 1 ) >> 3 ) ) ; 
}
static int bignum_obj_FIXUP (void * p ) {
  Scheme_Bignum * b = (Scheme_Bignum * ) p ; 
  if (! ((& ((Scheme_Bignum * ) b ) -> iso ) -> so . keyex & 0x2 ) ) {
    GC_fixup (& (b -> digits ) ) ; 
  }
  else {
    b -> digits = ((Small_Bignum * ) GC_fixup_self (b ) ) -> v ; 
  }
  return ((! ((& ((Scheme_Bignum * ) b ) -> iso ) -> so . keyex & 0x2 ) ) ? ((sizeof (Scheme_Bignum ) + (1 << 3 ) - 1 ) >> 3 ) : ((sizeof (Small_Bignum ) + (1 << 3 ) - 1 ) >> 3 ) ) ; 
}
static int rational_obj_SIZE (void * p ) {
  return ((sizeof (Scheme_Rational ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int rational_obj_MARK (void * p ) {
  Scheme_Rational * r = (Scheme_Rational * ) p ; 
  GC_mark (r -> num ) ; 
  GC_mark (r -> denom ) ; 
  return ((sizeof (Scheme_Rational ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int rational_obj_FIXUP (void * p ) {
  Scheme_Rational * r = (Scheme_Rational * ) p ; 
  GC_fixup (& (r -> num ) ) ; 
  GC_fixup (& (r -> denom ) ) ; 
  return ((sizeof (Scheme_Rational ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int float_obj_SIZE (void * p ) {
  return 0 ; 
}
static int float_obj_MARK (void * p ) {
  return 0 ; 
}
static int float_obj_FIXUP (void * p ) {
  return 0 ; 
}
static int double_obj_SIZE (void * p ) {
  return ((sizeof (Scheme_Double ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int double_obj_MARK (void * p ) {
  return ((sizeof (Scheme_Double ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int double_obj_FIXUP (void * p ) {
  return ((sizeof (Scheme_Double ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int complex_obj_SIZE (void * p ) {
  return ((sizeof (Scheme_Complex ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int complex_obj_MARK (void * p ) {
  Scheme_Complex * c = (Scheme_Complex * ) p ; 
  GC_mark (c -> r ) ; 
  GC_mark (c -> i ) ; 
  return ((sizeof (Scheme_Complex ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int complex_obj_FIXUP (void * p ) {
  Scheme_Complex * c = (Scheme_Complex * ) p ; 
  GC_fixup (& (c -> r ) ) ; 
  GC_fixup (& (c -> i ) ) ; 
  return ((sizeof (Scheme_Complex ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int string_obj_SIZE (void * p ) {
  return ((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int string_obj_MARK (void * p ) {
  Scheme_Object * o = (Scheme_Object * ) p ; 
  GC_mark ((((Scheme_Simple_Object * ) (o ) ) -> u . char_str_val . string_val ) ) ; 
  return ((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int string_obj_FIXUP (void * p ) {
  Scheme_Object * o = (Scheme_Object * ) p ; 
  GC_fixup (& ((((Scheme_Simple_Object * ) (o ) ) -> u . char_str_val . string_val ) ) ) ; 
  return ((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int bstring_obj_SIZE (void * p ) {
  return ((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int bstring_obj_MARK (void * p ) {
  Scheme_Object * o = (Scheme_Object * ) p ; 
  GC_mark ((((Scheme_Simple_Object * ) (o ) ) -> u . byte_str_val . string_val ) ) ; 
  return ((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int bstring_obj_FIXUP (void * p ) {
  Scheme_Object * o = (Scheme_Object * ) p ; 
  GC_fixup (& ((((Scheme_Simple_Object * ) (o ) ) -> u . byte_str_val . string_val ) ) ) ; 
  return ((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int symbol_obj_SIZE (void * p ) {
  Scheme_Symbol * s = (Scheme_Symbol * ) p ; 
  return ((sizeof (Scheme_Symbol ) + s -> len - 3 + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int symbol_obj_MARK (void * p ) {
  Scheme_Symbol * s = (Scheme_Symbol * ) p ; 
  return ((sizeof (Scheme_Symbol ) + s -> len - 3 + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int symbol_obj_FIXUP (void * p ) {
  Scheme_Symbol * s = (Scheme_Symbol * ) p ; 
  return ((sizeof (Scheme_Symbol ) + s -> len - 3 + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int cons_cell_SIZE (void * p ) {
  return ((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int cons_cell_MARK (void * p ) {
  Scheme_Object * o = (Scheme_Object * ) p ; 
  GC_mark ((((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . car ) ) ; 
  GC_mark ((((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . cdr ) ) ; 
  return ((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int cons_cell_FIXUP (void * p ) {
  Scheme_Object * o = (Scheme_Object * ) p ; 
  GC_fixup (& ((((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . car ) ) ) ; 
  GC_fixup (& ((((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . cdr ) ) ) ; 
  return ((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int vector_obj_SIZE (void * p ) {
  Scheme_Vector * vec = (Scheme_Vector * ) p ; 
  return (((sizeof (Scheme_Vector ) + ((vec -> size - 1 ) * sizeof (Scheme_Object * ) ) ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int vector_obj_MARK (void * p ) {
  Scheme_Vector * vec = (Scheme_Vector * ) p ; 
  int i ; 
  for (i = vec -> size ; i -- ; ) GC_mark (vec -> els [i ] ) ; 
  return (((sizeof (Scheme_Vector ) + ((vec -> size - 1 ) * sizeof (Scheme_Object * ) ) ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int vector_obj_FIXUP (void * p ) {
  Scheme_Vector * vec = (Scheme_Vector * ) p ; 
  int i ; 
  for (i = vec -> size ; i -- ; ) GC_fixup (& (vec -> els [i ] ) ) ; 
  return (((sizeof (Scheme_Vector ) + ((vec -> size - 1 ) * sizeof (Scheme_Object * ) ) ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int input_port_SIZE (void * p ) {
  return ((sizeof (Scheme_Input_Port ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int input_port_MARK (void * p ) {
  Scheme_Input_Port * ip = (Scheme_Input_Port * ) p ; 
  GC_mark (ip -> sub_type ) ; 
  GC_mark (ip -> port_data ) ; 
  GC_mark (ip -> name ) ; 
  GC_mark (ip -> peeked_read ) ; 
  GC_mark (ip -> peeked_write ) ; 
  GC_mark (ip -> read_handler ) ; 
  GC_mark (ip -> mref ) ; 
  GC_mark (ip -> output_half ) ; 
  GC_mark (ip -> special ) ; 
  GC_mark (ip -> ungotten_special ) ; 
  GC_mark (ip -> progress_evt ) ; 
  GC_mark (ip -> input_lock ) ; 
  GC_mark (ip -> input_giveup ) ; 
  GC_mark (ip -> input_extras ) ; 
  GC_mark (ip -> input_extras_ready ) ; 
  GC_mark (ip -> unless ) ; 
  GC_mark (ip -> unless_cache ) ; 
  return ((sizeof (Scheme_Input_Port ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int input_port_FIXUP (void * p ) {
  Scheme_Input_Port * ip = (Scheme_Input_Port * ) p ; 
  GC_fixup (& (ip -> sub_type ) ) ; 
  GC_fixup (& (ip -> port_data ) ) ; 
  GC_fixup (& (ip -> name ) ) ; 
  GC_fixup (& (ip -> peeked_read ) ) ; 
  GC_fixup (& (ip -> peeked_write ) ) ; 
  GC_fixup (& (ip -> read_handler ) ) ; 
  GC_fixup (& (ip -> mref ) ) ; 
  GC_fixup (& (ip -> output_half ) ) ; 
  GC_fixup (& (ip -> special ) ) ; 
  GC_fixup (& (ip -> ungotten_special ) ) ; 
  GC_fixup (& (ip -> progress_evt ) ) ; 
  GC_fixup (& (ip -> input_lock ) ) ; 
  GC_fixup (& (ip -> input_giveup ) ) ; 
  GC_fixup (& (ip -> input_extras ) ) ; 
  GC_fixup (& (ip -> input_extras_ready ) ) ; 
  GC_fixup (& (ip -> unless ) ) ; 
  GC_fixup (& (ip -> unless_cache ) ) ; 
  return ((sizeof (Scheme_Input_Port ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int output_port_SIZE (void * p ) {
  return ((sizeof (Scheme_Output_Port ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int output_port_MARK (void * p ) {
  Scheme_Output_Port * op = (Scheme_Output_Port * ) p ; 
  GC_mark (op -> sub_type ) ; 
  GC_mark (op -> port_data ) ; 
  GC_mark (op -> name ) ; 
  GC_mark (op -> display_handler ) ; 
  GC_mark (op -> write_handler ) ; 
  GC_mark (op -> print_handler ) ; 
  GC_mark (op -> mref ) ; 
  GC_mark (op -> input_half ) ; 
  return ((sizeof (Scheme_Output_Port ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int output_port_FIXUP (void * p ) {
  Scheme_Output_Port * op = (Scheme_Output_Port * ) p ; 
  GC_fixup (& (op -> sub_type ) ) ; 
  GC_fixup (& (op -> port_data ) ) ; 
  GC_fixup (& (op -> name ) ) ; 
  GC_fixup (& (op -> display_handler ) ) ; 
  GC_fixup (& (op -> write_handler ) ) ; 
  GC_fixup (& (op -> print_handler ) ) ; 
  GC_fixup (& (op -> mref ) ) ; 
  GC_fixup (& (op -> input_half ) ) ; 
  return ((sizeof (Scheme_Output_Port ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int syntax_compiler_SIZE (void * p ) {
  return ((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int syntax_compiler_MARK (void * p ) {
  return ((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int syntax_compiler_FIXUP (void * p ) {
  return ((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int thread_val_SIZE (void * p ) {
  return ((sizeof (Scheme_Thread ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int thread_val_MARK (void * p ) {
  Scheme_Thread * pr = (Scheme_Thread * ) p ; 
  GC_mark (pr -> next ) ; 
  GC_mark (pr -> prev ) ; 
  GC_mark (pr -> t_set_parent ) ; 
  GC_mark (pr -> t_set_next ) ; 
  GC_mark (pr -> t_set_prev ) ; 
  MARK_cjs (& pr -> cjs ) ; 
  GC_mark (pr -> cell_values ) ; 
  GC_mark (pr -> init_config ) ; 
  GC_mark (pr -> init_break_cell ) ; 
  {
    Scheme_Object * * rs = pr -> runstack_start ; 
    GC_mark (pr -> runstack_start ) ; 
    pr -> runstack = pr -> runstack_start + (pr -> runstack - rs ) ; 
  }
  GC_mark (pr -> runstack_saved ) ; 
  GC_mark (pr -> runstack_owner ) ; 
  GC_mark (pr -> runstack_swapped ) ; 
  pr -> spare_runstack = ((void * ) 0 ) ; 
  GC_mark (pr -> meta_prompt ) ; 
  GC_mark (pr -> meta_continuation ) ; 
  GC_mark (pr -> cont_mark_stack_segments ) ; 
  GC_mark (pr -> cont_mark_stack_owner ) ; 
  GC_mark (pr -> cont_mark_stack_swapped ) ; 
  MARK_jmpup (& pr -> jmpup_buf ) ; 
  GC_mark (pr -> dw ) ; 
  GC_mark (pr -> nester ) ; 
  GC_mark (pr -> nestee ) ; 
  GC_mark (pr -> blocker ) ; 
  GC_mark (pr -> overflow ) ; 
  GC_mark (pr -> current_local_env ) ; 
  GC_mark (pr -> current_local_mark ) ; 
  GC_mark (pr -> current_local_name ) ; 
  GC_mark (pr -> current_local_certs ) ; 
  GC_mark (pr -> current_local_modidx ) ; 
  GC_mark (pr -> current_local_menv ) ; 
  GC_mark (pr -> overflow_reply ) ; 
  GC_mark (pr -> values_buffer ) ; 
  GC_mark (pr -> tail_buffer ) ; 
  GC_mark (pr -> ku . eval . wait_expr ) ; 
  GC_mark (pr -> ku . apply . tail_rator ) ; 
  GC_mark (pr -> ku . apply . tail_rands ) ; 
  GC_mark (pr -> ku . multiple . array ) ; 
  GC_mark (pr -> ku . k . p1 ) ; 
  GC_mark (pr -> ku . k . p2 ) ; 
  GC_mark (pr -> ku . k . p3 ) ; 
  GC_mark (pr -> ku . k . p4 ) ; 
  GC_mark (pr -> ku . k . p5 ) ; 
  GC_mark (pr -> list_stack ) ; 
  GC_mark (pr -> kill_data ) ; 
  GC_mark (pr -> private_kill_data ) ; 
  GC_mark (pr -> private_kill_next ) ; 
  GC_mark (pr -> user_tls ) ; 
  GC_mark (pr -> mr_hop ) ; 
  GC_mark (pr -> mref ) ; 
  GC_mark (pr -> extra_mrefs ) ; 
  GC_mark (pr -> name ) ; 
  GC_mark (pr -> transitive_resumes ) ; 
  GC_mark (pr -> suspended_box ) ; 
  GC_mark (pr -> resumed_box ) ; 
  GC_mark (pr -> dead_box ) ; 
  GC_mark (pr -> running_box ) ; 
  return ((sizeof (Scheme_Thread ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int thread_val_FIXUP (void * p ) {
  Scheme_Thread * pr = (Scheme_Thread * ) p ; 
  GC_fixup (& (pr -> next ) ) ; 
  GC_fixup (& (pr -> prev ) ) ; 
  GC_fixup (& (pr -> t_set_parent ) ) ; 
  GC_fixup (& (pr -> t_set_next ) ) ; 
  GC_fixup (& (pr -> t_set_prev ) ) ; 
  FIXUP_cjs (& pr -> cjs ) ; 
  GC_fixup (& (pr -> cell_values ) ) ; 
  GC_fixup (& (pr -> init_config ) ) ; 
  GC_fixup (& (pr -> init_break_cell ) ) ; 
  {
    Scheme_Object * * rs = pr -> runstack_start ; 
    GC_fixup (& (pr -> runstack_start ) ) ; 
    pr -> runstack = pr -> runstack_start + (pr -> runstack - rs ) ; 
  }
  GC_fixup (& (pr -> runstack_saved ) ) ; 
  GC_fixup (& (pr -> runstack_owner ) ) ; 
  GC_fixup (& (pr -> runstack_swapped ) ) ; 
  pr -> spare_runstack = ((void * ) 0 ) ; 
  GC_fixup (& (pr -> meta_prompt ) ) ; 
  GC_fixup (& (pr -> meta_continuation ) ) ; 
  GC_fixup (& (pr -> cont_mark_stack_segments ) ) ; 
  GC_fixup (& (pr -> cont_mark_stack_owner ) ) ; 
  GC_fixup (& (pr -> cont_mark_stack_swapped ) ) ; 
  FIXUP_jmpup (& pr -> jmpup_buf ) ; 
  GC_fixup (& (pr -> dw ) ) ; 
  GC_fixup (& (pr -> nester ) ) ; 
  GC_fixup (& (pr -> nestee ) ) ; 
  GC_fixup (& (pr -> blocker ) ) ; 
  GC_fixup (& (pr -> overflow ) ) ; 
  GC_fixup (& (pr -> current_local_env ) ) ; 
  GC_fixup (& (pr -> current_local_mark ) ) ; 
  GC_fixup (& (pr -> current_local_name ) ) ; 
  GC_fixup (& (pr -> current_local_certs ) ) ; 
  GC_fixup (& (pr -> current_local_modidx ) ) ; 
  GC_fixup (& (pr -> current_local_menv ) ) ; 
  GC_fixup (& (pr -> overflow_reply ) ) ; 
  GC_fixup (& (pr -> values_buffer ) ) ; 
  GC_fixup (& (pr -> tail_buffer ) ) ; 
  GC_fixup (& (pr -> ku . eval . wait_expr ) ) ; 
  GC_fixup (& (pr -> ku . apply . tail_rator ) ) ; 
  GC_fixup (& (pr -> ku . apply . tail_rands ) ) ; 
  GC_fixup (& (pr -> ku . multiple . array ) ) ; 
  GC_fixup (& (pr -> ku . k . p1 ) ) ; 
  GC_fixup (& (pr -> ku . k . p2 ) ) ; 
  GC_fixup (& (pr -> ku . k . p3 ) ) ; 
  GC_fixup (& (pr -> ku . k . p4 ) ) ; 
  GC_fixup (& (pr -> ku . k . p5 ) ) ; 
  GC_fixup (& (pr -> list_stack ) ) ; 
  GC_fixup (& (pr -> kill_data ) ) ; 
  GC_fixup (& (pr -> private_kill_data ) ) ; 
  GC_fixup (& (pr -> private_kill_next ) ) ; 
  GC_fixup (& (pr -> user_tls ) ) ; 
  GC_fixup (& (pr -> mr_hop ) ) ; 
  GC_fixup (& (pr -> mref ) ) ; 
  GC_fixup (& (pr -> extra_mrefs ) ) ; 
  GC_fixup (& (pr -> name ) ) ; 
  GC_fixup (& (pr -> transitive_resumes ) ) ; 
  GC_fixup (& (pr -> suspended_box ) ) ; 
  GC_fixup (& (pr -> resumed_box ) ) ; 
  GC_fixup (& (pr -> dead_box ) ) ; 
  GC_fixup (& (pr -> running_box ) ) ; 
  return ((sizeof (Scheme_Thread ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int runstack_val_SIZE (void * p ) {
  long * s = (long * ) p ; 
  return s [1 ] ; 
}
static int runstack_val_MARK (void * p ) {
  long * s = (long * ) p ; 
  void * * a , * * b ; 
  a = (void * * ) s + 4 + s [2 ] ; 
  b = (void * * ) s + 4 + s [3 ] ; 
  while (a < b ) {
    GC_mark (* a ) ; 
    a ++ ; 
  }
  return s [1 ] ; 
}
static int runstack_val_FIXUP (void * p ) {
  long * s = (long * ) p ; 
  void * * a , * * b ; 
  a = (void * * ) s + 4 + s [2 ] ; 
  b = (void * * ) s + 4 + s [3 ] ; 
  while (a < b ) {
    GC_fixup (& (* a ) ) ; 
    a ++ ; 
  }
  a = (void * * ) s + 4 ; 
  b = (void * * ) s + 4 + s [2 ] ; 
  while (a < b ) {
    * a = ((void * ) 0 ) ; 
    a ++ ; 
  }
  a = (void * * ) s + 4 + s [3 ] ; 
  b = (void * * ) s + 4 + (s [1 ] - 4 ) ; 
  while (a < b ) {
    * a = ((void * ) 0 ) ; 
    a ++ ; 
  }
  return s [1 ] ; 
}
static int prompt_val_SIZE (void * p ) {
  return ((sizeof (Scheme_Prompt ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int prompt_val_MARK (void * p ) {
  Scheme_Prompt * pr = (Scheme_Prompt * ) p ; 
  GC_mark (pr -> boundary_overflow_id ) ; 
  GC_mark (pr -> runstack_boundary_start ) ; 
  GC_mark (pr -> tag ) ; 
  GC_mark (pr -> id ) ; 
  return ((sizeof (Scheme_Prompt ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int prompt_val_FIXUP (void * p ) {
  Scheme_Prompt * pr = (Scheme_Prompt * ) p ; 
  GC_fixup (& (pr -> boundary_overflow_id ) ) ; 
  GC_fixup (& (pr -> runstack_boundary_start ) ) ; 
  GC_fixup (& (pr -> tag ) ) ; 
  GC_fixup (& (pr -> id ) ) ; 
  return ((sizeof (Scheme_Prompt ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int cont_mark_set_val_SIZE (void * p ) {
  return ((sizeof (Scheme_Cont_Mark_Set ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int cont_mark_set_val_MARK (void * p ) {
  Scheme_Cont_Mark_Set * s = (Scheme_Cont_Mark_Set * ) p ; 
  GC_mark (s -> chain ) ; 
  GC_mark (s -> native_stack_trace ) ; 
  return ((sizeof (Scheme_Cont_Mark_Set ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int cont_mark_set_val_FIXUP (void * p ) {
  Scheme_Cont_Mark_Set * s = (Scheme_Cont_Mark_Set * ) p ; 
  GC_fixup (& (s -> chain ) ) ; 
  GC_fixup (& (s -> native_stack_trace ) ) ; 
  return ((sizeof (Scheme_Cont_Mark_Set ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int sema_val_SIZE (void * p ) {
  return ((sizeof (Scheme_Sema ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int sema_val_MARK (void * p ) {
  Scheme_Sema * s = (Scheme_Sema * ) p ; 
  GC_mark (s -> first ) ; 
  GC_mark (s -> last ) ; 
  return ((sizeof (Scheme_Sema ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int sema_val_FIXUP (void * p ) {
  Scheme_Sema * s = (Scheme_Sema * ) p ; 
  GC_fixup (& (s -> first ) ) ; 
  GC_fixup (& (s -> last ) ) ; 
  return ((sizeof (Scheme_Sema ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int channel_val_SIZE (void * p ) {
  return ((sizeof (Scheme_Channel ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int channel_val_MARK (void * p ) {
  Scheme_Channel * s = (Scheme_Channel * ) p ; 
  GC_mark (s -> get_first ) ; 
  GC_mark (s -> get_last ) ; 
  GC_mark (s -> put_first ) ; 
  GC_mark (s -> put_last ) ; 
  return ((sizeof (Scheme_Channel ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int channel_val_FIXUP (void * p ) {
  Scheme_Channel * s = (Scheme_Channel * ) p ; 
  GC_fixup (& (s -> get_first ) ) ; 
  GC_fixup (& (s -> get_last ) ) ; 
  GC_fixup (& (s -> put_first ) ) ; 
  GC_fixup (& (s -> put_last ) ) ; 
  return ((sizeof (Scheme_Channel ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int channel_put_val_SIZE (void * p ) {
  return ((sizeof (Scheme_Channel_Put ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int channel_put_val_MARK (void * p ) {
  Scheme_Channel_Put * s = (Scheme_Channel_Put * ) p ; 
  GC_mark (s -> ch ) ; 
  GC_mark (s -> val ) ; 
  return ((sizeof (Scheme_Channel_Put ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int channel_put_val_FIXUP (void * p ) {
  Scheme_Channel_Put * s = (Scheme_Channel_Put * ) p ; 
  GC_fixup (& (s -> ch ) ) ; 
  GC_fixup (& (s -> val ) ) ; 
  return ((sizeof (Scheme_Channel_Put ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int hash_table_val_SIZE (void * p ) {
  return ((sizeof (Scheme_Hash_Table ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int hash_table_val_MARK (void * p ) {
  Scheme_Hash_Table * ht = (Scheme_Hash_Table * ) p ; 
  GC_mark (ht -> keys ) ; 
  GC_mark (ht -> vals ) ; 
  GC_mark (ht -> mutex ) ; 
  return ((sizeof (Scheme_Hash_Table ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int hash_table_val_FIXUP (void * p ) {
  Scheme_Hash_Table * ht = (Scheme_Hash_Table * ) p ; 
  GC_fixup (& (ht -> keys ) ) ; 
  GC_fixup (& (ht -> vals ) ) ; 
  GC_fixup (& (ht -> mutex ) ) ; 
  return ((sizeof (Scheme_Hash_Table ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int bucket_table_val_SIZE (void * p ) {
  return ((sizeof (Scheme_Bucket_Table ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int bucket_table_val_MARK (void * p ) {
  Scheme_Bucket_Table * ht = (Scheme_Bucket_Table * ) p ; 
  GC_mark (ht -> buckets ) ; 
  GC_mark (ht -> mutex ) ; 
  return ((sizeof (Scheme_Bucket_Table ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int bucket_table_val_FIXUP (void * p ) {
  Scheme_Bucket_Table * ht = (Scheme_Bucket_Table * ) p ; 
  GC_fixup (& (ht -> buckets ) ) ; 
  GC_fixup (& (ht -> mutex ) ) ; 
  return ((sizeof (Scheme_Bucket_Table ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int namespace_val_SIZE (void * p ) {
  return ((sizeof (Scheme_Env ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int namespace_val_MARK (void * p ) {
  Scheme_Env * e = (Scheme_Env * ) p ; 
  GC_mark (e -> module ) ; 
  GC_mark (e -> module_registry ) ; 
  GC_mark (e -> export_registry ) ; 
  GC_mark (e -> insp ) ; 
  GC_mark (e -> rename ) ; 
  GC_mark (e -> et_rename ) ; 
  GC_mark (e -> tt_rename ) ; 
  GC_mark (e -> dt_rename ) ; 
  GC_mark (e -> syntax ) ; 
  GC_mark (e -> exp_env ) ; 
  GC_mark (e -> template_env ) ; 
  GC_mark (e -> shadowed_syntax ) ; 
  GC_mark (e -> link_midx ) ; 
  GC_mark (e -> require_names ) ; 
  GC_mark (e -> et_require_names ) ; 
  GC_mark (e -> tt_require_names ) ; 
  GC_mark (e -> dt_require_names ) ; 
  GC_mark (e -> toplevel ) ; 
  GC_mark (e -> modchain ) ; 
  GC_mark (e -> modvars ) ; 
  GC_mark (e -> marked_names ) ; 
  return ((sizeof (Scheme_Env ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int namespace_val_FIXUP (void * p ) {
  Scheme_Env * e = (Scheme_Env * ) p ; 
  GC_fixup (& (e -> module ) ) ; 
  GC_fixup (& (e -> module_registry ) ) ; 
  GC_fixup (& (e -> export_registry ) ) ; 
  GC_fixup (& (e -> insp ) ) ; 
  GC_fixup (& (e -> rename ) ) ; 
  GC_fixup (& (e -> et_rename ) ) ; 
  GC_fixup (& (e -> tt_rename ) ) ; 
  GC_fixup (& (e -> dt_rename ) ) ; 
  GC_fixup (& (e -> syntax ) ) ; 
  GC_fixup (& (e -> exp_env ) ) ; 
  GC_fixup (& (e -> template_env ) ) ; 
  GC_fixup (& (e -> shadowed_syntax ) ) ; 
  GC_fixup (& (e -> link_midx ) ) ; 
  GC_fixup (& (e -> require_names ) ) ; 
  GC_fixup (& (e -> et_require_names ) ) ; 
  GC_fixup (& (e -> tt_require_names ) ) ; 
  GC_fixup (& (e -> dt_require_names ) ) ; 
  GC_fixup (& (e -> toplevel ) ) ; 
  GC_fixup (& (e -> modchain ) ) ; 
  GC_fixup (& (e -> modvars ) ) ; 
  GC_fixup (& (e -> marked_names ) ) ; 
  return ((sizeof (Scheme_Env ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int random_state_val_SIZE (void * p ) {
  return ((sizeof (Scheme_Random_State ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int random_state_val_MARK (void * p ) {
  return ((sizeof (Scheme_Random_State ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int random_state_val_FIXUP (void * p ) {
  return ((sizeof (Scheme_Random_State ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int compilation_top_val_SIZE (void * p ) {
  return ((sizeof (Scheme_Compilation_Top ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int compilation_top_val_MARK (void * p ) {
  Scheme_Compilation_Top * t = (Scheme_Compilation_Top * ) p ; 
  GC_mark (t -> code ) ; 
  GC_mark (t -> prefix ) ; 
  return ((sizeof (Scheme_Compilation_Top ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int compilation_top_val_FIXUP (void * p ) {
  Scheme_Compilation_Top * t = (Scheme_Compilation_Top * ) p ; 
  GC_fixup (& (t -> code ) ) ; 
  GC_fixup (& (t -> prefix ) ) ; 
  return ((sizeof (Scheme_Compilation_Top ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int resolve_prefix_val_SIZE (void * p ) {
  return ((sizeof (Resolve_Prefix ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int resolve_prefix_val_MARK (void * p ) {
  Resolve_Prefix * rp = (Resolve_Prefix * ) p ; 
  GC_mark (rp -> toplevels ) ; 
  GC_mark (rp -> stxes ) ; 
  GC_mark (rp -> delay_info ) ; 
  return ((sizeof (Resolve_Prefix ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int resolve_prefix_val_FIXUP (void * p ) {
  Resolve_Prefix * rp = (Resolve_Prefix * ) p ; 
  GC_fixup (& (rp -> toplevels ) ) ; 
  GC_fixup (& (rp -> stxes ) ) ; 
  GC_fixup (& (rp -> delay_info ) ) ; 
  return ((sizeof (Resolve_Prefix ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int comp_prefix_val_SIZE (void * p ) {
  return ((sizeof (Comp_Prefix ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int comp_prefix_val_MARK (void * p ) {
  Comp_Prefix * cp = (Comp_Prefix * ) p ; 
  GC_mark (cp -> toplevels ) ; 
  GC_mark (cp -> stxes ) ; 
  return ((sizeof (Comp_Prefix ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int comp_prefix_val_FIXUP (void * p ) {
  Comp_Prefix * cp = (Comp_Prefix * ) p ; 
  GC_fixup (& (cp -> toplevels ) ) ; 
  GC_fixup (& (cp -> stxes ) ) ; 
  return ((sizeof (Comp_Prefix ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int svector_val_SIZE (void * p ) {
  return ((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int svector_val_MARK (void * p ) {
  Scheme_Object * o = (Scheme_Object * ) p ; 
  GC_mark ((((Scheme_Simple_Object * ) (o ) ) -> u . svector_val . vec ) ) ; 
  return ((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int svector_val_FIXUP (void * p ) {
  Scheme_Object * o = (Scheme_Object * ) p ; 
  GC_fixup (& ((((Scheme_Simple_Object * ) (o ) ) -> u . svector_val . vec ) ) ) ; 
  return ((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int stx_val_SIZE (void * p ) {
  return ((sizeof (Scheme_Stx ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int stx_val_MARK (void * p ) {
  Scheme_Stx * stx = (Scheme_Stx * ) p ; 
  GC_mark (stx -> val ) ; 
  GC_mark (stx -> srcloc ) ; 
  GC_mark (stx -> wraps ) ; 
  GC_mark (stx -> certs ) ; 
  GC_mark (stx -> props ) ; 
  if (! ((& (stx ) -> iso ) -> so . keyex & 0x2 ) )
    GC_mark (stx -> u . modinfo_cache ) ; 
  return ((sizeof (Scheme_Stx ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int stx_val_FIXUP (void * p ) {
  Scheme_Stx * stx = (Scheme_Stx * ) p ; 
  GC_fixup (& (stx -> val ) ) ; 
  GC_fixup (& (stx -> srcloc ) ) ; 
  GC_fixup (& (stx -> wraps ) ) ; 
  GC_fixup (& (stx -> certs ) ) ; 
  GC_fixup (& (stx -> props ) ) ; 
  if (! ((& (stx ) -> iso ) -> so . keyex & 0x2 ) )
    GC_fixup (& (stx -> u . modinfo_cache ) ) ; 
  return ((sizeof (Scheme_Stx ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int stx_off_val_SIZE (void * p ) {
  return ((sizeof (Scheme_Stx_Offset ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int stx_off_val_MARK (void * p ) {
  Scheme_Stx_Offset * o = (Scheme_Stx_Offset * ) p ; 
  GC_mark (o -> src ) ; 
  return ((sizeof (Scheme_Stx_Offset ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int stx_off_val_FIXUP (void * p ) {
  Scheme_Stx_Offset * o = (Scheme_Stx_Offset * ) p ; 
  GC_fixup (& (o -> src ) ) ; 
  return ((sizeof (Scheme_Stx_Offset ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int module_val_SIZE (void * p ) {
  return ((sizeof (Scheme_Module ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int module_val_MARK (void * p ) {
  Scheme_Module * m = (Scheme_Module * ) p ; 
  GC_mark (m -> modname ) ; 
  GC_mark (m -> et_requires ) ; 
  GC_mark (m -> requires ) ; 
  GC_mark (m -> tt_requires ) ; 
  GC_mark (m -> dt_requires ) ; 
  GC_mark (m -> body ) ; 
  GC_mark (m -> et_body ) ; 
  GC_mark (m -> me ) ; 
  GC_mark (m -> provide_protects ) ; 
  GC_mark (m -> indirect_provides ) ; 
  GC_mark (m -> et_provide_protects ) ; 
  GC_mark (m -> et_indirect_provides ) ; 
  GC_mark (m -> self_modidx ) ; 
  GC_mark (m -> accessible ) ; 
  GC_mark (m -> et_accessible ) ; 
  GC_mark (m -> insp ) ; 
  GC_mark (m -> hints ) ; 
  GC_mark (m -> ii_src ) ; 
  GC_mark (m -> comp_prefix ) ; 
  GC_mark (m -> prefix ) ; 
  GC_mark (m -> dummy ) ; 
  GC_mark (m -> rn_stx ) ; 
  GC_mark (m -> et_rn_stx ) ; 
  GC_mark (m -> tt_rn_stx ) ; 
  GC_mark (m -> dt_rn_stx ) ; 
  GC_mark (m -> primitive ) ; 
  return ((sizeof (Scheme_Module ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int module_val_FIXUP (void * p ) {
  Scheme_Module * m = (Scheme_Module * ) p ; 
  GC_fixup (& (m -> modname ) ) ; 
  GC_fixup (& (m -> et_requires ) ) ; 
  GC_fixup (& (m -> requires ) ) ; 
  GC_fixup (& (m -> tt_requires ) ) ; 
  GC_fixup (& (m -> dt_requires ) ) ; 
  GC_fixup (& (m -> body ) ) ; 
  GC_fixup (& (m -> et_body ) ) ; 
  GC_fixup (& (m -> me ) ) ; 
  GC_fixup (& (m -> provide_protects ) ) ; 
  GC_fixup (& (m -> indirect_provides ) ) ; 
  GC_fixup (& (m -> et_provide_protects ) ) ; 
  GC_fixup (& (m -> et_indirect_provides ) ) ; 
  GC_fixup (& (m -> self_modidx ) ) ; 
  GC_fixup (& (m -> accessible ) ) ; 
  GC_fixup (& (m -> et_accessible ) ) ; 
  GC_fixup (& (m -> insp ) ) ; 
  GC_fixup (& (m -> hints ) ) ; 
  GC_fixup (& (m -> ii_src ) ) ; 
  GC_fixup (& (m -> comp_prefix ) ) ; 
  GC_fixup (& (m -> prefix ) ) ; 
  GC_fixup (& (m -> dummy ) ) ; 
  GC_fixup (& (m -> rn_stx ) ) ; 
  GC_fixup (& (m -> et_rn_stx ) ) ; 
  GC_fixup (& (m -> tt_rn_stx ) ) ; 
  GC_fixup (& (m -> dt_rn_stx ) ) ; 
  GC_fixup (& (m -> primitive ) ) ; 
  return ((sizeof (Scheme_Module ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int module_phase_exports_val_SIZE (void * p ) {
  return ((sizeof (Scheme_Module_Phase_Exports ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int module_phase_exports_val_MARK (void * p ) {
  Scheme_Module_Phase_Exports * m = (Scheme_Module_Phase_Exports * ) p ; 
  GC_mark (m -> provides ) ; 
  GC_mark (m -> provide_srcs ) ; 
  GC_mark (m -> provide_src_names ) ; 
  GC_mark (m -> provide_src_phases ) ; 
  GC_mark (m -> kernel_exclusion ) ; 
  return ((sizeof (Scheme_Module_Phase_Exports ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int module_phase_exports_val_FIXUP (void * p ) {
  Scheme_Module_Phase_Exports * m = (Scheme_Module_Phase_Exports * ) p ; 
  GC_fixup (& (m -> provides ) ) ; 
  GC_fixup (& (m -> provide_srcs ) ) ; 
  GC_fixup (& (m -> provide_src_names ) ) ; 
  GC_fixup (& (m -> provide_src_phases ) ) ; 
  GC_fixup (& (m -> kernel_exclusion ) ) ; 
  return ((sizeof (Scheme_Module_Phase_Exports ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int module_exports_val_SIZE (void * p ) {
  return ((sizeof (Scheme_Module_Exports ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int module_exports_val_MARK (void * p ) {
  Scheme_Module_Exports * m = (Scheme_Module_Exports * ) p ; 
  GC_mark (m -> rt ) ; 
  GC_mark (m -> et ) ; 
  GC_mark (m -> dt ) ; 
  GC_mark (m -> src_modidx ) ; 
  return ((sizeof (Scheme_Module_Exports ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int module_exports_val_FIXUP (void * p ) {
  Scheme_Module_Exports * m = (Scheme_Module_Exports * ) p ; 
  GC_fixup (& (m -> rt ) ) ; 
  GC_fixup (& (m -> et ) ) ; 
  GC_fixup (& (m -> dt ) ) ; 
  GC_fixup (& (m -> src_modidx ) ) ; 
  return ((sizeof (Scheme_Module_Exports ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int modidx_val_SIZE (void * p ) {
  return ((sizeof (Scheme_Modidx ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int modidx_val_MARK (void * p ) {
  Scheme_Modidx * modidx = (Scheme_Modidx * ) p ; 
  GC_mark (modidx -> path ) ; 
  GC_mark (modidx -> base ) ; 
  GC_mark (modidx -> resolved ) ; 
  GC_mark (modidx -> shift_cache ) ; 
  GC_mark (modidx -> cache_next ) ; 
  return ((sizeof (Scheme_Modidx ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int modidx_val_FIXUP (void * p ) {
  Scheme_Modidx * modidx = (Scheme_Modidx * ) p ; 
  GC_fixup (& (modidx -> path ) ) ; 
  GC_fixup (& (modidx -> base ) ) ; 
  GC_fixup (& (modidx -> resolved ) ) ; 
  GC_fixup (& (modidx -> shift_cache ) ) ; 
  GC_fixup (& (modidx -> cache_next ) ) ; 
  return ((sizeof (Scheme_Modidx ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int guard_val_SIZE (void * p ) {
  return ((sizeof (Scheme_Security_Guard ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int guard_val_MARK (void * p ) {
  Scheme_Security_Guard * g = (Scheme_Security_Guard * ) p ; 
  GC_mark (g -> parent ) ; 
  GC_mark (g -> file_proc ) ; 
  GC_mark (g -> network_proc ) ; 
  GC_mark (g -> link_proc ) ; 
  return ((sizeof (Scheme_Security_Guard ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int guard_val_FIXUP (void * p ) {
  Scheme_Security_Guard * g = (Scheme_Security_Guard * ) p ; 
  GC_fixup (& (g -> parent ) ) ; 
  GC_fixup (& (g -> file_proc ) ) ; 
  GC_fixup (& (g -> network_proc ) ) ; 
  GC_fixup (& (g -> link_proc ) ) ; 
  return ((sizeof (Scheme_Security_Guard ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int buf_holder_SIZE (void * p ) {
  return ((sizeof (Scheme_Jumpup_Buf_Holder ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int buf_holder_MARK (void * p ) {
  Scheme_Jumpup_Buf_Holder * h = (Scheme_Jumpup_Buf_Holder * ) p ; 
  MARK_jmpup (& h -> buf ) ; 
  return ((sizeof (Scheme_Jumpup_Buf_Holder ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int buf_holder_FIXUP (void * p ) {
  Scheme_Jumpup_Buf_Holder * h = (Scheme_Jumpup_Buf_Holder * ) p ; 
  FIXUP_jmpup (& h -> buf ) ; 
  return ((sizeof (Scheme_Jumpup_Buf_Holder ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_inspector_SIZE (void * p ) {
  return ((sizeof (Scheme_Inspector ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_inspector_MARK (void * p ) {
  Scheme_Inspector * i = (Scheme_Inspector * ) p ; 
  GC_mark (i -> superior ) ; 
  return ((sizeof (Scheme_Inspector ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_inspector_FIXUP (void * p ) {
  Scheme_Inspector * i = (Scheme_Inspector * ) p ; 
  GC_fixup (& (i -> superior ) ) ; 
  return ((sizeof (Scheme_Inspector ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_pipe_SIZE (void * p ) {
  return ((sizeof (Scheme_Pipe ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_pipe_MARK (void * p ) {
  Scheme_Pipe * pp = (Scheme_Pipe * ) p ; 
  GC_mark (pp -> buf ) ; 
  GC_mark (pp -> wakeup_on_read ) ; 
  GC_mark (pp -> wakeup_on_write ) ; 
  return ((sizeof (Scheme_Pipe ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_pipe_FIXUP (void * p ) {
  Scheme_Pipe * pp = (Scheme_Pipe * ) p ; 
  GC_fixup (& (pp -> buf ) ) ; 
  GC_fixup (& (pp -> wakeup_on_read ) ) ; 
  GC_fixup (& (pp -> wakeup_on_write ) ) ; 
  return ((sizeof (Scheme_Pipe ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
void scheme_register_traversers (void ) {
  GC_register_traversers (scheme_toplevel_type , toplevel_obj_SIZE , toplevel_obj_MARK , toplevel_obj_FIXUP , 1 , 1 ) ; 
  GC_register_traversers (scheme_variable_type , variable_obj_SIZE , variable_obj_MARK , variable_obj_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_local_type , local_obj_SIZE , local_obj_MARK , local_obj_FIXUP , 1 , 1 ) ; 
  GC_register_traversers (scheme_local_unbox_type , local_obj_SIZE , local_obj_MARK , local_obj_FIXUP , 1 , 1 ) ; 
  GC_register_traversers (scheme_syntax_type , iptr_obj_SIZE , iptr_obj_MARK , iptr_obj_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_application_type , app_rec_SIZE , app_rec_MARK , app_rec_FIXUP , 0 , 0 ) ; 
  GC_register_traversers (scheme_application2_type , app2_rec_SIZE , app2_rec_MARK , app2_rec_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_application3_type , app3_rec_SIZE , app3_rec_MARK , app3_rec_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_sequence_type , seq_rec_SIZE , seq_rec_MARK , seq_rec_FIXUP , 0 , 0 ) ; 
  GC_register_traversers (scheme_branch_type , branch_rec_SIZE , branch_rec_MARK , branch_rec_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_unclosed_procedure_type , unclosed_proc_SIZE , unclosed_proc_MARK , unclosed_proc_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_let_value_type , let_value_SIZE , let_value_MARK , let_value_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_let_void_type , let_void_SIZE , let_void_MARK , let_void_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_letrec_type , letrec_SIZE , letrec_MARK , letrec_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_let_one_type , let_one_SIZE , let_one_MARK , let_one_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_with_cont_mark_type , with_cont_mark_SIZE , with_cont_mark_MARK , with_cont_mark_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_quote_syntax_type , quotesyntax_obj_SIZE , quotesyntax_obj_MARK , quotesyntax_obj_FIXUP , 1 , 1 ) ; 
  GC_register_traversers (scheme_module_variable_type , module_var_SIZE , module_var_MARK , module_var_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (_scheme_values_types_ , bad_trav_SIZE , bad_trav_MARK , bad_trav_FIXUP , 0 , 0 ) ; 
  GC_register_traversers (scheme_compiled_unclosed_procedure_type , unclosed_proc_SIZE , unclosed_proc_MARK , unclosed_proc_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_compiled_let_value_type , comp_let_value_SIZE , comp_let_value_MARK , comp_let_value_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_compiled_let_void_type , let_header_SIZE , let_header_MARK , let_header_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_compiled_syntax_type , iptr_obj_SIZE , iptr_obj_MARK , iptr_obj_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_compiled_toplevel_type , toplevel_obj_SIZE , toplevel_obj_MARK , toplevel_obj_FIXUP , 1 , 1 ) ; 
  GC_register_traversers (scheme_compiled_quote_syntax_type , local_obj_SIZE , local_obj_MARK , local_obj_FIXUP , 1 , 1 ) ; 
  GC_register_traversers (scheme_quote_compilation_type , small_object_SIZE , small_object_MARK , small_object_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (_scheme_compiled_values_types_ , bad_trav_SIZE , bad_trav_MARK , bad_trav_FIXUP , 0 , 0 ) ; 
  GC_register_traversers (scheme_resolve_prefix_type , resolve_prefix_val_SIZE , resolve_prefix_val_MARK , resolve_prefix_val_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_comp_prefix , comp_prefix_val_SIZE , comp_prefix_val_MARK , comp_prefix_val_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_prim_type , prim_proc_SIZE , prim_proc_MARK , prim_proc_FIXUP , 0 , 0 ) ; 
  GC_register_traversers (scheme_closed_prim_type , closed_prim_proc_SIZE , closed_prim_proc_MARK , closed_prim_proc_FIXUP , 0 , 0 ) ; 
  GC_register_traversers (scheme_closure_type , scm_closure_SIZE , scm_closure_MARK , scm_closure_FIXUP , 0 , 0 ) ; 
  GC_register_traversers (scheme_case_closure_type , case_closure_SIZE , case_closure_MARK , case_closure_FIXUP , 0 , 0 ) ; 
  GC_register_traversers (scheme_cont_type , cont_proc_SIZE , cont_proc_MARK , cont_proc_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_dyn_wind , mark_dyn_wind_SIZE , mark_dyn_wind_MARK , mark_dyn_wind_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_overflow , mark_overflow_SIZE , mark_overflow_MARK , mark_overflow_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_overflow_jmp , mark_overflow_jmp_SIZE , mark_overflow_jmp_MARK , mark_overflow_jmp_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_meta_cont , meta_cont_proc_SIZE , meta_cont_proc_MARK , meta_cont_proc_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_escaping_cont_type , escaping_cont_proc_SIZE , escaping_cont_proc_MARK , escaping_cont_proc_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_char_type , char_obj_SIZE , char_obj_MARK , char_obj_FIXUP , 1 , 1 ) ; 
  GC_register_traversers (scheme_integer_type , bad_trav_SIZE , bad_trav_MARK , bad_trav_FIXUP , 0 , 0 ) ; 
  GC_register_traversers (scheme_bignum_type , bignum_obj_SIZE , bignum_obj_MARK , bignum_obj_FIXUP , 0 , 0 ) ; 
  GC_register_traversers (scheme_rational_type , rational_obj_SIZE , rational_obj_MARK , rational_obj_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_float_type , float_obj_SIZE , float_obj_MARK , float_obj_FIXUP , 0 , 1 ) ; 
  GC_register_traversers (scheme_double_type , double_obj_SIZE , double_obj_MARK , double_obj_FIXUP , 1 , 1 ) ; 
  GC_register_traversers (scheme_complex_izi_type , complex_obj_SIZE , complex_obj_MARK , complex_obj_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_complex_type , complex_obj_SIZE , complex_obj_MARK , complex_obj_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_char_string_type , string_obj_SIZE , string_obj_MARK , string_obj_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_byte_string_type , bstring_obj_SIZE , bstring_obj_MARK , bstring_obj_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_unix_path_type , bstring_obj_SIZE , bstring_obj_MARK , bstring_obj_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_windows_path_type , bstring_obj_SIZE , bstring_obj_MARK , bstring_obj_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_symbol_type , symbol_obj_SIZE , symbol_obj_MARK , symbol_obj_FIXUP , 0 , 1 ) ; 
  GC_register_traversers (scheme_keyword_type , symbol_obj_SIZE , symbol_obj_MARK , symbol_obj_FIXUP , 0 , 1 ) ; 
  GC_register_traversers (scheme_null_type , char_obj_SIZE , char_obj_MARK , char_obj_FIXUP , 1 , 1 ) ; 
  GC_register_traversers (scheme_pair_type , cons_cell_SIZE , cons_cell_MARK , cons_cell_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_raw_pair_type , cons_cell_SIZE , cons_cell_MARK , cons_cell_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_vector_type , vector_obj_SIZE , vector_obj_MARK , vector_obj_FIXUP , 0 , 0 ) ; 
  GC_register_traversers (scheme_cpointer_type , cpointer_obj_SIZE , cpointer_obj_MARK , cpointer_obj_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_offset_cpointer_type , offset_cpointer_obj_SIZE , offset_cpointer_obj_MARK , offset_cpointer_obj_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_bucket_type , bucket_obj_SIZE , bucket_obj_MARK , bucket_obj_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_input_port_type , input_port_SIZE , input_port_MARK , input_port_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_output_port_type , output_port_SIZE , output_port_MARK , output_port_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_eof_type , char_obj_SIZE , char_obj_MARK , char_obj_FIXUP , 1 , 1 ) ; 
  GC_register_traversers (scheme_true_type , char_obj_SIZE , char_obj_MARK , char_obj_FIXUP , 1 , 1 ) ; 
  GC_register_traversers (scheme_false_type , char_obj_SIZE , char_obj_MARK , char_obj_FIXUP , 1 , 1 ) ; 
  GC_register_traversers (scheme_void_type , char_obj_SIZE , char_obj_MARK , char_obj_FIXUP , 1 , 1 ) ; 
  GC_register_traversers (scheme_syntax_compiler_type , syntax_compiler_SIZE , syntax_compiler_MARK , syntax_compiler_FIXUP , 1 , 1 ) ; 
  GC_register_traversers (scheme_macro_type , small_object_SIZE , small_object_MARK , small_object_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_lazy_macro_type , second_of_cons_SIZE , second_of_cons_MARK , second_of_cons_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_box_type , small_object_SIZE , small_object_MARK , small_object_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_thread_type , thread_val_SIZE , thread_val_MARK , thread_val_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_prompt_type , prompt_val_SIZE , prompt_val_MARK , prompt_val_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_prompt_tag_type , cons_cell_SIZE , cons_cell_MARK , cons_cell_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_cont_mark_set_type , cont_mark_set_val_SIZE , cont_mark_set_val_MARK , cont_mark_set_val_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_sema_type , sema_val_SIZE , sema_val_MARK , sema_val_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_channel_type , channel_val_SIZE , channel_val_MARK , channel_val_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_channel_put_type , channel_put_val_SIZE , channel_put_val_MARK , channel_put_val_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_semaphore_repost_type , small_object_SIZE , small_object_MARK , small_object_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_thread_suspend_type , twoptr_obj_SIZE , twoptr_obj_MARK , twoptr_obj_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_thread_resume_type , twoptr_obj_SIZE , twoptr_obj_MARK , twoptr_obj_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_thread_dead_type , small_object_SIZE , small_object_MARK , small_object_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_hash_table_type , hash_table_val_SIZE , hash_table_val_MARK , hash_table_val_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_bucket_table_type , bucket_table_val_SIZE , bucket_table_val_MARK , bucket_table_val_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_module_registry_type , hash_table_val_SIZE , hash_table_val_MARK , hash_table_val_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_namespace_type , namespace_val_SIZE , namespace_val_MARK , namespace_val_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_random_state_type , random_state_val_SIZE , random_state_val_MARK , random_state_val_FIXUP , 1 , 1 ) ; 
  GC_register_traversers (scheme_compilation_top_type , compilation_top_val_SIZE , compilation_top_val_MARK , compilation_top_val_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_intdef_context_type , twoptr_obj_SIZE , twoptr_obj_MARK , twoptr_obj_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_eval_waiting_type , bad_trav_SIZE , bad_trav_MARK , bad_trav_FIXUP , 0 , 0 ) ; 
  GC_register_traversers (scheme_tail_call_waiting_type , bad_trav_SIZE , bad_trav_MARK , bad_trav_FIXUP , 0 , 0 ) ; 
  GC_register_traversers (scheme_undefined_type , char_obj_SIZE , char_obj_MARK , char_obj_FIXUP , 1 , 1 ) ; 
  GC_register_traversers (scheme_placeholder_type , small_object_SIZE , small_object_MARK , small_object_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_multiple_values_type , small_object_SIZE , small_object_MARK , small_object_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_case_lambda_sequence_type , case_closure_SIZE , case_closure_MARK , case_closure_FIXUP , 0 , 0 ) ; 
  GC_register_traversers (scheme_begin0_sequence_type , seq_rec_SIZE , seq_rec_MARK , seq_rec_FIXUP , 0 , 0 ) ; 
  GC_register_traversers (scheme_svector_type , svector_val_SIZE , svector_val_MARK , svector_val_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_set_macro_type , small_object_SIZE , small_object_MARK , small_object_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_id_macro_type , small_object_SIZE , small_object_MARK , small_object_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_stx_type , stx_val_SIZE , stx_val_MARK , stx_val_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_stx_offset_type , stx_off_val_SIZE , stx_off_val_MARK , stx_off_val_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_expanded_syntax_type , twoptr_obj_SIZE , twoptr_obj_MARK , twoptr_obj_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_module_type , module_val_SIZE , module_val_MARK , module_val_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_module_exports , module_exports_val_SIZE , module_exports_val_MARK , module_exports_val_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_module_phase_exports , module_phase_exports_val_SIZE , module_phase_exports_val_MARK , module_phase_exports_val_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_module_index_type , modidx_val_SIZE , modidx_val_MARK , modidx_val_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_security_guard_type , guard_val_SIZE , guard_val_MARK , guard_val_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_nack_evt_type , twoptr_obj_SIZE , twoptr_obj_MARK , twoptr_obj_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_always_evt_type , char_obj_SIZE , char_obj_MARK , char_obj_FIXUP , 1 , 1 ) ; 
  GC_register_traversers (scheme_never_evt_type , char_obj_SIZE , char_obj_MARK , char_obj_FIXUP , 1 , 1 ) ; 
  GC_register_traversers (scheme_inspector_type , mark_inspector_SIZE , mark_inspector_MARK , mark_inspector_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_buf_holder , buf_holder_SIZE , buf_holder_MARK , buf_holder_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_pipe , mark_pipe_SIZE , mark_pipe_MARK , mark_pipe_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_tcp_accept_evt_type , small_object_SIZE , small_object_MARK , small_object_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_special_comment_type , small_object_SIZE , small_object_MARK , small_object_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_progress_evt_type , twoptr_obj_SIZE , twoptr_obj_MARK , twoptr_obj_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_already_comp_type , iptr_obj_SIZE , iptr_obj_MARK , iptr_obj_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_thread_cell_values_type , small_object_SIZE , small_object_MARK , small_object_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_global_ref_type , small_object_SIZE , small_object_MARK , small_object_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_delay_syntax_type , small_object_SIZE , small_object_MARK , small_object_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_runstack , runstack_val_SIZE , runstack_val_MARK , runstack_val_FIXUP , 0 , 0 ) ; 
}
