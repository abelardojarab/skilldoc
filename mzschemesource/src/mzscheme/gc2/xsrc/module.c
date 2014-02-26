#include "precomp.h"
extern void scheme_call_expand_observe (Scheme_Object * obs , int signal , Scheme_Object * argument ) ; 
Scheme_Object * scheme_sys_wraps0 ; 
Scheme_Object * scheme_sys_wraps1 ; 
Scheme_Object * (* scheme_module_demand_hook ) (int , Scheme_Object * * ) ; 
static Scheme_Object * current_module_name_resolver (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * current_module_name_prefix (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * dynamic_require_for_syntax (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * namespace_require (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * namespace_trans_require (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * namespace_require_copy (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * namespace_require_etonly (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * namespace_attach_module (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * namespace_unprotect_module (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * module_compiled_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * module_compiled_name (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * module_compiled_imports (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * module_compiled_exports (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * module_to_namespace (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * module_path_index_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * module_path_index_resolve (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * module_path_index_split (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * module_path_index_join (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * module_export_protected_p (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * module_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
static Scheme_Object * module_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
static Scheme_Object * module_begin_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
static Scheme_Object * module_begin_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
static Scheme_Object * require_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
static Scheme_Object * require_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
static Scheme_Object * require_for_syntax_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
static Scheme_Object * require_for_syntax_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
static Scheme_Object * require_for_template_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
static Scheme_Object * require_for_template_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
static Scheme_Object * require_for_label_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
static Scheme_Object * require_for_label_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
static Scheme_Object * provide_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
static Scheme_Object * provide_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
static Scheme_Object * module_execute (Scheme_Object * data ) ; 
static Scheme_Object * top_level_require_execute (Scheme_Object * data ) ; 
static Scheme_Object * module_jit (Scheme_Object * data ) ; 
static Scheme_Object * top_level_require_jit (Scheme_Object * data ) ; 
static Scheme_Object * module_optimize (Scheme_Object * data , Optimize_Info * info ) ; 
static Scheme_Object * module_resolve (Scheme_Object * data , Resolve_Info * info ) ; 
static Scheme_Object * top_level_require_optimize (Scheme_Object * data , Optimize_Info * info ) ; 
static Scheme_Object * top_level_require_resolve (Scheme_Object * data , Resolve_Info * info ) ; 
static void module_validate (Scheme_Object * data , Mz_CPort * port , char * stack , Scheme_Hash_Table * ht , Scheme_Object * * tls , int depth , int letlimit , int delta , int num_toplevels , int num_stxes , int num_lifts ) ; 
static void top_level_require_validate (Scheme_Object * data , Mz_CPort * port , char * stack , Scheme_Hash_Table * ht , Scheme_Object * * tls , int depth , int letlimit , int delta , int num_toplevels , int num_stxes , int num_lifts ) ; 
static Scheme_Object * write_module (Scheme_Object * obj ) ; 
static Scheme_Object * read_module (Scheme_Object * obj ) ; 
static Scheme_Module * module_load (Scheme_Object * modname , Scheme_Env * env , const char * who ) ; 
static void eval_defmacro (Scheme_Object * names , int count , Scheme_Object * expr , Scheme_Env * genv , Scheme_Comp_Env * env , Resolve_Prefix * rp , int let_depth , int shift , Scheme_Bucket_Table * syntax , int for_stx , Scheme_Object * certs ) ; 
static Scheme_Module_Exports * make_module_exports () ; 
static Scheme_Object * modbeg_syntax ; 
static Scheme_Object * kernel_symbol ; 
static Scheme_Module * kernel ; 
static Scheme_Object * module_symbol ; 
static Scheme_Object * module_begin_symbol ; 
static Scheme_Object * prefix_symbol ; 
static Scheme_Object * only_symbol ; 
static Scheme_Object * rename_symbol ; 
static Scheme_Object * all_except_symbol ; 
static Scheme_Object * prefix_all_except_symbol ; 
static Scheme_Object * all_from_symbol ; 
static Scheme_Object * all_from_except_symbol ; 
static Scheme_Object * all_defined_symbol ; 
static Scheme_Object * all_defined_except_symbol ; 
static Scheme_Object * prefix_all_defined_symbol ; 
static Scheme_Object * prefix_all_defined_except_symbol ; 
static Scheme_Object * struct_symbol ; 
static Scheme_Object * protect_symbol ; 
static Scheme_Object * module_name_symbol ; 
Scheme_Object * scheme_module_stx ; 
Scheme_Object * scheme_begin_stx ; 
Scheme_Object * scheme_define_values_stx ; 
Scheme_Object * scheme_define_syntaxes_stx ; 
static Scheme_Object * define_for_syntaxes_stx ; 
static Scheme_Object * require_stx ; 
static Scheme_Object * require_for_syntax_stx ; 
static Scheme_Object * require_for_template_stx ; 
static Scheme_Object * require_for_label_stx ; 
static Scheme_Object * provide_stx ; 
static Scheme_Object * provide_for_syntax_stx ; 
static Scheme_Object * provide_for_label_stx ; 
static Scheme_Object * set_stx ; 
static Scheme_Object * app_stx ; 
Scheme_Object * scheme_top_stx ; 
static Scheme_Object * lambda_stx ; 
static Scheme_Object * case_lambda_stx ; 
static Scheme_Object * let_values_stx ; 
static Scheme_Object * letrec_values_stx ; 
static Scheme_Object * if_stx ; 
static Scheme_Object * begin0_stx ; 
static Scheme_Object * set_stx ; 
static Scheme_Object * with_continuation_mark_stx ; 
static Scheme_Object * letrec_syntaxes_stx ; 
static Scheme_Object * var_ref_stx ; 
static Scheme_Object * expression_stx ; 
static Scheme_Env * initial_modules_env ; 
static int num_initial_modules ; 
static Scheme_Object * * initial_modules ; 
static Scheme_Object * initial_renames ; 
static Scheme_Bucket_Table * initial_toplevel ; 
static Scheme_Object * empty_self_modidx ; 
static Scheme_Object * empty_self_symbol ; 
static Scheme_Modidx * modidx_caching_chain ; 
static Scheme_Object * global_shift_cache ; 
typedef void (* Check_Func ) (Scheme_Object * prnt_name , Scheme_Object * name , Scheme_Object * nominal_modname , Scheme_Object * modname , Scheme_Object * srcname , int isval , void * data , Scheme_Object * e , Scheme_Object * form , Scheme_Object * err_src ) ; 
static Scheme_Object * parse_requires (Scheme_Object * form , Scheme_Object * base_modidx , Scheme_Env * env , Scheme_Object * rn , Scheme_Object * post_ex_rn , Scheme_Object * et_rn , Scheme_Object * et_post_ex_rn , Scheme_Object * dt_rn , Scheme_Object * dt_post_ex_rn , Check_Func ck , void * data , void * et_data , void * dt_data , int start , int expstart , Scheme_Object * redef_modname , int unpack_kern , int copy_vars , int can_save_marshal , int * all_simple ) ; 
static Scheme_Object * parse_provides (Scheme_Object * form , Scheme_Object * fst , Scheme_Object * e , Scheme_Hash_Table * provided , Scheme_Object * reprovided , Scheme_Object * self_modidx , Scheme_Object * * _all_defs_out ) ; 
static int compute_reprovides (Scheme_Hash_Table * provided , Scheme_Object * reprovided , Scheme_Object * requires , Scheme_Hash_Table * required , Scheme_Env * genv , Scheme_Object * all_defs , Scheme_Object * all_defs_out , Scheme_Object * * _exclude_hint , const char * matching_form ) ; 
static char * compute_provide_arrays (Scheme_Hash_Table * provided , Scheme_Hash_Table * required , Scheme_Module_Phase_Exports * pt , Scheme_Env * genv , int def_phase , int reprovide_kernel , Scheme_Object * form , const char * def_way ) ; 
static void start_module (Scheme_Module * m , Scheme_Env * env , int restart , Scheme_Object * syntax_idx , int delay_exptime , int with_tt , Scheme_Object * cycle_list ) ; 
static void expstart_module (Scheme_Module * m , Scheme_Env * env , int restart , Scheme_Object * syntax_idx , int delay_exptime , int with_tt , Scheme_Object * cycle_list ) ; 
static void finish_expstart_module (Scheme_Env * menv , Scheme_Env * env , int with_tt , Scheme_Object * cycle_list ) ; 
static void finish_expstart_module_in_namespace (Scheme_Env * menv , Scheme_Env * env ) ; 
static void eval_module_body (Scheme_Env * menv ) ; 
static Scheme_Object * do_namespace_require (Scheme_Env * env , int argc , Scheme_Object * argv [] , int for_exp , int copy , int etonly ) ; 
static Scheme_Object * default_module_resolver (int argc , Scheme_Object * * argv ) ; 
static void qsort_provides (Scheme_Object * * exs , Scheme_Object * * exsns , Scheme_Object * * exss , char * exps , char * exets , int start , int count , int do_uninterned ) ; 
void scheme_init_module (Scheme_Env * env ) {
  Scheme_Object * o ; 
  Scheme_Object * __funcarg33 = NULLED_OUT ; 
  Scheme_Object * __funcarg32 = NULLED_OUT ; 
  Scheme_Object * __funcarg31 = NULLED_OUT ; 
  Scheme_Object * __funcarg30 = NULLED_OUT ; 
  Scheme_Object * __funcarg29 = NULLED_OUT ; 
  Scheme_Object * __funcarg28 = NULLED_OUT ; 
  Scheme_Object * __funcarg27 = NULLED_OUT ; 
  Scheme_Object * __funcarg26 = NULLED_OUT ; 
  Scheme_Config * __funcarg25 = NULLED_OUT ; 
  Scheme_Config * __funcarg24 = NULLED_OUT ; 
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
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(o, 1)));
# define XfOrM1_COUNT (2)
# define SETUP_XfOrM1(x) SETUP(XfOrM1_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  o = NULLED_OUT ; 
  (scheme_syntax_optimizers [6 ] = module_optimize , scheme_syntax_resolvers [6 ] = module_resolve , scheme_syntax_executers [6 ] = module_execute , scheme_syntax_validaters [6 ] = module_validate , scheme_syntax_jitters [6 ] = module_jit , scheme_syntax_cloners [6 ] = ((void * ) 0 ) , scheme_syntax_shifters [6 ] = ((void * ) 0 ) , scheme_syntax_protect_afters [6 ] = - 1 ) ; 
  (scheme_syntax_optimizers [7 ] = top_level_require_optimize , scheme_syntax_resolvers [7 ] = top_level_require_resolve , scheme_syntax_executers [7 ] = top_level_require_execute , scheme_syntax_validaters [7 ] = top_level_require_validate , scheme_syntax_jitters [7 ] = top_level_require_jit , scheme_syntax_cloners [7 ] = ((void * ) 0 ) , scheme_syntax_shifters [7 ] = ((void * ) 0 ) , scheme_syntax_protect_afters [7 ] = 2 ) ; 
  (__funcarg33 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_compiled_syntax (module_syntax , module_expand ) ), FUNCCALL_AGAIN(scheme_add_global_keyword ("module" , __funcarg33 , env ) )) ; 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & modbeg_syntax , sizeof (modbeg_syntax ) ) ); 
  modbeg_syntax = FUNCCALL_AGAIN(scheme_make_compiled_syntax (module_begin_syntax , module_begin_expand ) ); 
  FUNCCALL_AGAIN(scheme_add_global_keyword ("#%module-begin" , modbeg_syntax , env ) ); 
  (__funcarg32 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_compiled_syntax (require_syntax , require_expand ) ), FUNCCALL_AGAIN(scheme_add_global_keyword ("require" , __funcarg32 , env ) )) ; 
  (__funcarg31 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_compiled_syntax (require_for_syntax_syntax , require_for_syntax_expand ) ), FUNCCALL_AGAIN(scheme_add_global_keyword ("require-for-syntax" , __funcarg31 , env ) )) ; 
  (__funcarg30 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_compiled_syntax (require_for_template_syntax , require_for_template_expand ) ), FUNCCALL_AGAIN(scheme_add_global_keyword ("require-for-template" , __funcarg30 , env ) )) ; 
  (__funcarg29 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_compiled_syntax (require_for_label_syntax , require_for_label_expand ) ), FUNCCALL_AGAIN(scheme_add_global_keyword ("require-for-label" , __funcarg29 , env ) )) ; 
  (__funcarg28 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_compiled_syntax (provide_syntax , provide_expand ) ), FUNCCALL_AGAIN(scheme_add_global_keyword ("provide" , __funcarg28 , env ) )) ; 
  (__funcarg27 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_compiled_syntax (provide_syntax , provide_expand ) ), FUNCCALL_AGAIN(scheme_add_global_keyword ("provide-for-syntax" , __funcarg27 , env ) )) ; 
  (__funcarg26 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_compiled_syntax (provide_syntax , provide_expand ) ), FUNCCALL_AGAIN(scheme_add_global_keyword ("provide-for-label" , __funcarg26 , env ) )) ; 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & kernel_symbol , sizeof (kernel_symbol ) ) ); 
  kernel_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("#%kernel" ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & module_symbol , sizeof (module_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & module_begin_symbol , sizeof (module_begin_symbol ) ) ); 
  module_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("module" ) ); 
  module_begin_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("#%module-begin" ) ); 
  FUNCCALL_AGAIN(scheme_install_type_writer (scheme_module_type , write_module ) ); 
  FUNCCALL_AGAIN(scheme_install_type_reader (scheme_module_type , read_module ) ); 
  o = FUNCCALL_AGAIN(scheme_make_prim_w_arity (default_module_resolver , "default-module-name-resolver" , 1 , 4 ) ); 
  (__funcarg25 = FUNCCALL(SETUP_XfOrM1(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_set_param (__funcarg25 , MZCONFIG_CURRENT_MODULE_RESOLVER , o ) )) ; 
  (__funcarg24 = FUNCCALL(SETUP_XfOrM1(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_set_param (__funcarg24 , MZCONFIG_CURRENT_MODULE_PREFIX , scheme_false ) )) ; 
  (__funcarg23 = FUNCCALL(SETUP_XfOrM1(_), scheme_register_parameter (current_module_name_resolver , "current-module-name-resolver" , MZCONFIG_CURRENT_MODULE_RESOLVER ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-module-name-resolver" , __funcarg23 , env ) )) ; 
  (__funcarg22 = FUNCCALL(SETUP_XfOrM1(_), scheme_register_parameter (current_module_name_prefix , "current-module-name-prefix" , MZCONFIG_CURRENT_MODULE_PREFIX ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-module-name-prefix" , __funcarg22 , env ) )) ; 
  (__funcarg21 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (scheme_dynamic_require , "dynamic-require" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("dynamic-require" , __funcarg21 , env ) )) ; 
  (__funcarg20 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (dynamic_require_for_syntax , "dynamic-require-for-syntax" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("dynamic-require-for-syntax" , __funcarg20 , env ) )) ; 
  (__funcarg19 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (namespace_require , "namespace-require" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("namespace-require" , __funcarg19 , env ) )) ; 
  (__funcarg18 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (namespace_trans_require , "namespace-transformer-require" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("namespace-transformer-require" , __funcarg18 , env ) )) ; 
  (__funcarg17 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (namespace_attach_module , "namespace-attach-module" , 2 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("namespace-attach-module" , __funcarg17 , env ) )) ; 
  (__funcarg16 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (namespace_unprotect_module , "namespace-unprotect-module" , 2 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("namespace-unprotect-module" , __funcarg16 , env ) )) ; 
  (__funcarg15 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (namespace_require_copy , "namespace-require/copy" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("namespace-require/copy" , __funcarg15 , env ) )) ; 
  (__funcarg14 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (namespace_require_etonly , "namespace-require/expansion-time" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("namespace-require/expansion-time" , __funcarg14 , env ) )) ; 
  (__funcarg13 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (module_compiled_p , "compiled-module-expression?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("compiled-module-expression?" , __funcarg13 , env ) )) ; 
  (__funcarg12 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (module_compiled_name , "module-compiled-name" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("module-compiled-name" , __funcarg12 , env ) )) ; 
  (__funcarg11 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_everything (module_compiled_imports , 0 , "module-compiled-imports" , 1 , 1 , 0 , 3 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("module-compiled-imports" , __funcarg11 , env ) )) ; 
  (__funcarg10 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_everything (module_compiled_exports , 0 , "module-compiled-exports" , 1 , 1 , 0 , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("module-compiled-exports" , __funcarg10 , env ) )) ; 
  (__funcarg9 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (module_path_index_p , "module-path-index?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("module-path-index?" , __funcarg9 , env ) )) ; 
  (__funcarg8 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (module_path_index_resolve , "module-path-index-resolve" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("module-path-index-resolve" , __funcarg8 , env ) )) ; 
  (__funcarg7 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_everything (module_path_index_split , 0 , "module-path-index-split" , 1 , 1 , 0 , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("module-path-index-split" , __funcarg7 , env ) )) ; 
  (__funcarg6 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (module_path_index_join , "module-path-index-join" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("module-path-index-join" , __funcarg6 , env ) )) ; 
  (__funcarg5 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (module_export_protected_p , "module-provide-protected?" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("module-provide-protected?" , __funcarg5 , env ) )) ; 
  (__funcarg4 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (module_to_namespace , "module->namespace" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("module->namespace" , __funcarg4 , env ) )) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_finish_kernel (Scheme_Env * env ) {
  Scheme_Bucket_Table * ht ; 
  int i , j , count , syntax_start = 0 ; 
  Scheme_Bucket * * bs ; 
  Scheme_Object * * exs , * w , * rn ; 
  Scheme_Object * insp ; 
  Scheme_Config * __funcarg60 = NULLED_OUT ; 
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
  PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(ht, 0), PUSH(rn, 1), PUSH(exs, 2), PUSH(w, 3), PUSH(bs, 4), PUSH(insp, 5)));
# define XfOrM2_COUNT (6)
# define SETUP_XfOrM2(x) SETUP(XfOrM2_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  ht = NULLED_OUT ; 
  bs = NULLED_OUT ; 
  exs = NULLED_OUT ; 
  w = NULLED_OUT ; 
  rn = NULLED_OUT ; 
  insp = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM2(_), scheme_register_static ((void * ) & kernel , sizeof (kernel ) ) ); 
  kernel = ((Scheme_Module * ) FUNCCALL(SETUP_XfOrM2(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Module ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  kernel -> so . type = scheme_module_type ; 
  insp = (__funcarg60 = FUNCCALL(SETUP_XfOrM2(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg60 , MZCONFIG_CODE_INSPECTOR ) )) ; 
  scheme_initial_env -> module = kernel ; 
  scheme_initial_env -> insp = insp ; 
  kernel -> modname = kernel_symbol ; 
  kernel -> requires = scheme_null ; 
  kernel -> et_requires = scheme_null ; 
  kernel -> tt_requires = scheme_null ; 
  kernel -> dt_requires = scheme_null ; 
  kernel -> insp = insp ; 
  count = 0 ; 
  for (j = 0 ; j < 2 ; j ++ ) {
    if (! j )
      ht = scheme_initial_env -> toplevel ; 
    else {
      ht = scheme_initial_env -> syntax ; 
      syntax_start = count ; 
    }
    bs = ht -> buckets ; 
    for (i = ht -> size ; i -- ; ) {
      Scheme_Bucket * b = bs [i ] ; 
      if (b && b -> val )
        count ++ ; 
    }
  }
  exs = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM2(_), GC_malloc (sizeof (Scheme_Object * ) * (count ) ) )) ; 
  count = 0 ; 
  for (j = 0 ; j < 2 ; j ++ ) {
    if (! j )
      ht = scheme_initial_env -> toplevel ; 
    else ht = scheme_initial_env -> syntax ; 
    bs = ht -> buckets ; 
    for (i = ht -> size ; i -- ; ) {
      Scheme_Bucket * b = bs [i ] ; 
      if (b && b -> val )
        exs [count ++ ] = (Scheme_Object * ) b -> key ; 
    }
  }
  kernel -> functional = 1 ; 
  kernel -> et_functional = 1 ; 
  kernel -> tt_functional = 1 ; 
  kernel -> no_cert = 1 ; 
  {
    Scheme_Module_Exports * me ; 
    BLOCK_SETUP((PUSH(me, 0+XfOrM2_COUNT)));
#   define XfOrM5_COUNT (1+XfOrM2_COUNT)
#   define SETUP_XfOrM5(x) SETUP(XfOrM5_COUNT)
    me = NULLED_OUT ; 
    me = FUNCCALL(SETUP_XfOrM5(_), make_module_exports () ); 
    kernel -> me = me ; 
  }
  kernel -> me -> rt -> provides = exs ; 
  kernel -> me -> rt -> provide_srcs = ((void * ) 0 ) ; 
  kernel -> me -> rt -> provide_src_names = exs ; 
  kernel -> me -> rt -> num_provides = count ; 
  kernel -> me -> rt -> num_var_provides = syntax_start ; 
  scheme_initial_env -> running = 1 ; 
  scheme_initial_env -> et_running = 1 ; 
  scheme_initial_env -> attached = 1 ; 
  rn = FUNCCALL(SETUP_XfOrM2(_), scheme_make_module_rename (0 , 1 , ((void * ) 0 ) ) ); 
  for (i = kernel -> me -> rt -> num_provides ; i -- ; ) {
#   define XfOrM4_COUNT (0+XfOrM2_COUNT)
#   define SETUP_XfOrM4(x) SETUP_XfOrM2(x)
    FUNCCALL(SETUP_XfOrM4(_), scheme_extend_module_rename (rn , kernel_symbol , exs [i ] , exs [i ] , kernel_symbol , exs [i ] , 0 , 0 ) ); 
  }
  FUNCCALL(SETUP_XfOrM2(_), scheme_sys_wraps (((void * ) 0 ) ) ); 
  FUNCCALL(SETUP_XfOrM2(_), scheme_register_static ((void * ) & scheme_module_stx , sizeof (scheme_module_stx ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_begin_stx , sizeof (scheme_begin_stx ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_define_values_stx , sizeof (scheme_define_values_stx ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_define_syntaxes_stx , sizeof (scheme_define_syntaxes_stx ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & define_for_syntaxes_stx , sizeof (define_for_syntaxes_stx ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & require_stx , sizeof (require_stx ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & require_for_syntax_stx , sizeof (require_for_syntax_stx ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & require_for_template_stx , sizeof (require_for_template_stx ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & require_for_label_stx , sizeof (require_for_label_stx ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & provide_stx , sizeof (provide_stx ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & provide_for_syntax_stx , sizeof (provide_for_syntax_stx ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & provide_for_label_stx , sizeof (provide_for_label_stx ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & set_stx , sizeof (set_stx ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & app_stx , sizeof (app_stx ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_top_stx , sizeof (scheme_top_stx ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & lambda_stx , sizeof (lambda_stx ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & case_lambda_stx , sizeof (case_lambda_stx ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & let_values_stx , sizeof (let_values_stx ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & letrec_values_stx , sizeof (letrec_values_stx ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & if_stx , sizeof (if_stx ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & begin0_stx , sizeof (begin0_stx ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & set_stx , sizeof (set_stx ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & with_continuation_mark_stx , sizeof (with_continuation_mark_stx ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & letrec_syntaxes_stx , sizeof (letrec_syntaxes_stx ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & var_ref_stx , sizeof (var_ref_stx ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & expression_stx , sizeof (expression_stx ) ) ); 
  w = scheme_sys_wraps0 ; 
  scheme_module_stx = (__funcarg59 = FUNCCALL(SETUP_XfOrM2(_), scheme_intern_symbol ("module" ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg59 , scheme_false , w , 0 , 0 ) )) ; 
  scheme_begin_stx = (__funcarg58 = FUNCCALL(SETUP_XfOrM2(_), scheme_intern_symbol ("begin" ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg58 , scheme_false , w , 0 , 0 ) )) ; 
  scheme_define_values_stx = (__funcarg57 = FUNCCALL(SETUP_XfOrM2(_), scheme_intern_symbol ("define-values" ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg57 , scheme_false , w , 0 , 0 ) )) ; 
  scheme_define_syntaxes_stx = (__funcarg56 = FUNCCALL(SETUP_XfOrM2(_), scheme_intern_symbol ("define-syntaxes" ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg56 , scheme_false , w , 0 , 0 ) )) ; 
  define_for_syntaxes_stx = (__funcarg55 = FUNCCALL(SETUP_XfOrM2(_), scheme_intern_symbol ("define-values-for-syntax" ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg55 , scheme_false , w , 0 , 0 ) )) ; 
  require_stx = (__funcarg54 = FUNCCALL(SETUP_XfOrM2(_), scheme_intern_symbol ("require" ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg54 , scheme_false , w , 0 , 0 ) )) ; 
  require_for_syntax_stx = (__funcarg53 = FUNCCALL(SETUP_XfOrM2(_), scheme_intern_symbol ("require-for-syntax" ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg53 , scheme_false , w , 0 , 0 ) )) ; 
  require_for_template_stx = (__funcarg52 = FUNCCALL(SETUP_XfOrM2(_), scheme_intern_symbol ("require-for-template" ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg52 , scheme_false , w , 0 , 0 ) )) ; 
  require_for_label_stx = (__funcarg51 = FUNCCALL(SETUP_XfOrM2(_), scheme_intern_symbol ("require-for-label" ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg51 , scheme_false , w , 0 , 0 ) )) ; 
  provide_stx = (__funcarg50 = FUNCCALL(SETUP_XfOrM2(_), scheme_intern_symbol ("provide" ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg50 , scheme_false , w , 0 , 0 ) )) ; 
  provide_for_syntax_stx = (__funcarg49 = FUNCCALL(SETUP_XfOrM2(_), scheme_intern_symbol ("provide-for-syntax" ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg49 , scheme_false , w , 0 , 0 ) )) ; 
  provide_for_label_stx = (__funcarg48 = FUNCCALL(SETUP_XfOrM2(_), scheme_intern_symbol ("provide-for-label" ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg48 , scheme_false , w , 0 , 0 ) )) ; 
  set_stx = (__funcarg47 = FUNCCALL(SETUP_XfOrM2(_), scheme_intern_symbol ("set!" ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg47 , scheme_false , w , 0 , 0 ) )) ; 
  app_stx = (__funcarg46 = FUNCCALL(SETUP_XfOrM2(_), scheme_intern_symbol ("#%app" ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg46 , scheme_false , w , 0 , 0 ) )) ; 
  scheme_top_stx = (__funcarg45 = FUNCCALL(SETUP_XfOrM2(_), scheme_intern_symbol ("#%top" ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg45 , scheme_false , w , 0 , 0 ) )) ; 
  lambda_stx = (__funcarg44 = FUNCCALL(SETUP_XfOrM2(_), scheme_intern_symbol ("lambda" ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg44 , scheme_false , w , 0 , 0 ) )) ; 
  case_lambda_stx = (__funcarg43 = FUNCCALL(SETUP_XfOrM2(_), scheme_intern_symbol ("case-lambda" ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg43 , scheme_false , w , 0 , 0 ) )) ; 
  let_values_stx = (__funcarg42 = FUNCCALL(SETUP_XfOrM2(_), scheme_intern_symbol ("let-values" ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg42 , scheme_false , w , 0 , 0 ) )) ; 
  letrec_values_stx = (__funcarg41 = FUNCCALL(SETUP_XfOrM2(_), scheme_intern_symbol ("letrec-values" ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg41 , scheme_false , w , 0 , 0 ) )) ; 
  if_stx = (__funcarg40 = FUNCCALL(SETUP_XfOrM2(_), scheme_intern_symbol ("if" ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg40 , scheme_false , w , 0 , 0 ) )) ; 
  begin0_stx = (__funcarg39 = FUNCCALL(SETUP_XfOrM2(_), scheme_intern_symbol ("begin0" ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg39 , scheme_false , w , 0 , 0 ) )) ; 
  set_stx = (__funcarg38 = FUNCCALL(SETUP_XfOrM2(_), scheme_intern_symbol ("set!" ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg38 , scheme_false , w , 0 , 0 ) )) ; 
  with_continuation_mark_stx = (__funcarg37 = FUNCCALL(SETUP_XfOrM2(_), scheme_intern_symbol ("with-continuation-mark" ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg37 , scheme_false , w , 0 , 0 ) )) ; 
  letrec_syntaxes_stx = (__funcarg36 = FUNCCALL(SETUP_XfOrM2(_), scheme_intern_symbol ("letrec-syntaxes+values" ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg36 , scheme_false , w , 0 , 0 ) )) ; 
  var_ref_stx = (__funcarg35 = FUNCCALL(SETUP_XfOrM2(_), scheme_intern_symbol ("#%variable-reference" ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg35 , scheme_false , w , 0 , 0 ) )) ; 
  expression_stx = (__funcarg34 = FUNCCALL(SETUP_XfOrM2(_), scheme_intern_symbol ("#%expression" ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg34 , scheme_false , w , 0 , 0 ) )) ; 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & prefix_symbol , sizeof (prefix_symbol ) ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & only_symbol , sizeof (only_symbol ) ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & rename_symbol , sizeof (rename_symbol ) ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & all_except_symbol , sizeof (all_except_symbol ) ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & prefix_all_except_symbol , sizeof (prefix_all_except_symbol ) ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & all_from_symbol , sizeof (all_from_symbol ) ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & all_from_except_symbol , sizeof (all_from_except_symbol ) ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & all_defined_symbol , sizeof (all_defined_symbol ) ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & all_defined_except_symbol , sizeof (all_defined_except_symbol ) ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & prefix_all_defined_symbol , sizeof (prefix_all_defined_symbol ) ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & prefix_all_defined_except_symbol , sizeof (prefix_all_defined_except_symbol ) ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & struct_symbol , sizeof (struct_symbol ) ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & protect_symbol , sizeof (protect_symbol ) ) ); 
  prefix_symbol = FUNCCALL_EMPTY(scheme_intern_symbol ("prefix" ) ); 
  only_symbol = FUNCCALL_EMPTY(scheme_intern_symbol ("only" ) ); 
  rename_symbol = FUNCCALL_EMPTY(scheme_intern_symbol ("rename" ) ); 
  all_except_symbol = FUNCCALL_EMPTY(scheme_intern_symbol ("all-except" ) ); 
  prefix_all_except_symbol = FUNCCALL_EMPTY(scheme_intern_symbol ("prefix-all-except" ) ); 
  all_from_symbol = FUNCCALL_EMPTY(scheme_intern_symbol ("all-from" ) ); 
  all_from_except_symbol = FUNCCALL_EMPTY(scheme_intern_symbol ("all-from-except" ) ); 
  all_defined_symbol = FUNCCALL_EMPTY(scheme_intern_symbol ("all-defined" ) ); 
  all_defined_except_symbol = FUNCCALL_EMPTY(scheme_intern_symbol ("all-defined-except" ) ); 
  prefix_all_defined_symbol = FUNCCALL_EMPTY(scheme_intern_symbol ("prefix-all-defined" ) ); 
  prefix_all_defined_except_symbol = FUNCCALL_EMPTY(scheme_intern_symbol ("prefix-all-defined-except" ) ); 
  struct_symbol = FUNCCALL_EMPTY(scheme_intern_symbol ("struct" ) ); 
  protect_symbol = FUNCCALL_EMPTY(scheme_intern_symbol ("protect" ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & module_name_symbol , sizeof (module_name_symbol ) ) ); 
  module_name_symbol = FUNCCALL_EMPTY(scheme_intern_symbol ("enclosing-module-name" ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_require_from_original_env (Scheme_Env * env , int syntax_only ) {
  Scheme_Object * rn , * * exs ; 
  int i , c ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(rn, 0), PUSH(exs, 1), PUSH(env, 2)));
# define XfOrM20_COUNT (3)
# define SETUP_XfOrM20(x) SETUP(XfOrM20_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  rn = NULLED_OUT ; 
  exs = NULLED_OUT ; 
  rn = env -> rename ; 
  if (! rn ) {
#   define XfOrM23_COUNT (0+XfOrM20_COUNT)
#   define SETUP_XfOrM23(x) SETUP_XfOrM20(x)
    rn = FUNCCALL(SETUP_XfOrM23(_), scheme_make_module_rename (env -> phase , 0 , ((void * ) 0 ) ) ); 
    env -> rename = rn ; 
  }
  exs = kernel -> me -> rt -> provides ; 
  c = kernel -> me -> rt -> num_provides ; 
  i = (syntax_only ? kernel -> me -> rt -> num_var_provides : 0 ) ; 
  for (; i < c ; i ++ ) {
#   define XfOrM22_COUNT (0+XfOrM20_COUNT)
#   define SETUP_XfOrM22(x) SETUP_XfOrM20(x)
    FUNCCALL(SETUP_XfOrM22(_), scheme_extend_module_rename (rn , kernel_symbol , exs [i ] , exs [i ] , kernel_symbol , exs [i ] , 0 , 0 ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_sys_wraps (Scheme_Comp_Env * env ) {
  Scheme_Object * rn , * w ; 
  long phase ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(rn, 0), PUSH(w, 1)));
# define XfOrM24_COUNT (2)
# define SETUP_XfOrM24(x) SETUP(XfOrM24_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  rn = NULLED_OUT ; 
  w = NULLED_OUT ; 
  if (! env )
    phase = 0 ; 
  else if ((((long ) ((Scheme_Object * ) env ) ) & 0x1 ) )
    phase = (((long ) ((Scheme_Object * ) env ) ) >> 1 ) ; 
  else phase = env -> genv -> phase ; 
  if ((phase == 0 ) && scheme_sys_wraps0 )
    RET_VALUE_START (scheme_sys_wraps0 ) RET_VALUE_END ; 
  if ((phase == 1 ) && scheme_sys_wraps1 )
    RET_VALUE_START (scheme_sys_wraps1 ) RET_VALUE_END ; 
  rn = FUNCCALL(SETUP_XfOrM24(_), scheme_make_module_rename (phase , 1 , ((void * ) 0 ) ) ); 
  FUNCCALL_AGAIN(scheme_extend_module_rename_with_kernel (rn , kernel_symbol ) ); 
  w = FUNCCALL_AGAIN(scheme_datum_to_syntax (kernel_symbol , scheme_false , scheme_false , 0 , 0 ) ); 
  w = FUNCCALL_AGAIN(scheme_add_rename (w , rn ) ); 
  if (phase == 0 ) {
#   define XfOrM26_COUNT (0+XfOrM24_COUNT)
#   define SETUP_XfOrM26(x) SETUP_XfOrM24(x)
    FUNCCALL(SETUP_XfOrM26(_), scheme_register_static ((void * ) & scheme_sys_wraps0 , sizeof (scheme_sys_wraps0 ) ) ); 
    scheme_sys_wraps0 = w ; 
  }
  if (phase == 1 ) {
#   define XfOrM25_COUNT (0+XfOrM24_COUNT)
#   define SETUP_XfOrM25(x) SETUP_XfOrM24(x)
    FUNCCALL(SETUP_XfOrM25(_), scheme_register_static ((void * ) & scheme_sys_wraps1 , sizeof (scheme_sys_wraps1 ) ) ); 
    scheme_sys_wraps1 = w ; 
  }
  RET_VALUE_START (w ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_save_initial_module_set (Scheme_Env * env ) {
  int i , c , count ; 
  Scheme_Hash_Table * ht ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(ht, 1)));
# define XfOrM27_COUNT (2)
# define SETUP_XfOrM27(x) SETUP(XfOrM27_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ht = NULLED_OUT ; 
  if (! initial_modules_env ) {
#   define XfOrM37_COUNT (0+XfOrM27_COUNT)
#   define SETUP_XfOrM37(x) SETUP_XfOrM27(x)
    FUNCCALL(SETUP_XfOrM37(_), scheme_register_static ((void * ) & initial_modules_env , sizeof (initial_modules_env ) ) ); 
  }
  initial_modules_env = env ; 
  ht = env -> module_registry ; 
  c = ht -> size ; 
  count = 0 ; 
  for (i = 0 ; i < c ; i ++ ) {
    if (ht -> vals [i ] )
      count ++ ; 
  }
  num_initial_modules = count ; 
  if (! initial_modules ) {
#   define XfOrM34_COUNT (0+XfOrM27_COUNT)
#   define SETUP_XfOrM34(x) SETUP_XfOrM27(x)
    FUNCCALL(SETUP_XfOrM34(_), scheme_register_static ((void * ) & initial_modules , sizeof (initial_modules ) ) ); 
  }
  initial_modules = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM27(_), GC_malloc (sizeof (Scheme_Object * ) * (count ) ) )) ; 
  count = 0 ; 
  for (i = 0 ; i < c ; i ++ ) {
    if (ht -> vals [i ] ) {
      initial_modules [count ++ ] = ht -> keys [i ] ; 
    }
  }
  if (! initial_renames ) {
#   define XfOrM29_COUNT (0+XfOrM27_COUNT)
#   define SETUP_XfOrM29(x) SETUP_XfOrM27(x)
    FUNCCALL(SETUP_XfOrM29(_), scheme_register_static ((void * ) & initial_renames , sizeof (initial_renames ) ) ); 
  }
  initial_renames = FUNCCALL(SETUP_XfOrM27(_), scheme_make_module_rename (0 , 1 , ((void * ) 0 ) ) ); 
  FUNCCALL(SETUP_XfOrM27(_), scheme_append_module_rename (env -> rename , initial_renames ) ); 
  if (! initial_toplevel ) {
#   define XfOrM28_COUNT (0+XfOrM27_COUNT)
#   define SETUP_XfOrM28(x) SETUP_XfOrM27(x)
    FUNCCALL(SETUP_XfOrM28(_), scheme_register_static ((void * ) & initial_toplevel , sizeof (initial_toplevel ) ) ); 
  }
  initial_toplevel = FUNCCALL_EMPTY(scheme_clone_toplevel (env -> toplevel , ((void * ) 0 ) ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_install_initial_module_set (Scheme_Env * env ) {
  int i ; 
  Scheme_Object * a [3 ] ; 
  Scheme_Module * m ; 
  PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 3, 0), PUSH(env, 3), PUSH(m, 4)));
# define XfOrM38_COUNT (5)
# define SETUP_XfOrM38(x) SETUP(XfOrM38_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  a[2] = NULLED_OUT ; 
  m = NULLED_OUT ; 
  for (i = 0 ; i < num_initial_modules ; i ++ ) {
#   define XfOrM42_COUNT (0+XfOrM38_COUNT)
#   define SETUP_XfOrM42(x) SETUP_XfOrM38(x)
    a [0 ] = (Scheme_Object * ) initial_modules_env ; 
    a [1 ] = initial_modules [i ] ; 
    a [2 ] = (Scheme_Object * ) env ; 
    m = (Scheme_Module * ) FUNCCALL(SETUP_XfOrM42(_), scheme_hash_get (initial_modules_env -> module_registry , a [1 ] ) ); 
    FUNCCALL(SETUP_XfOrM42(_), start_module (m , initial_modules_env , 0 , a [1 ] , 0 , 0 , scheme_null ) ); 
    FUNCCALL_AGAIN(namespace_attach_module (3 , a ) ); 
  }
  if (! env -> rename ) {
    Scheme_Object * rn ; 
    BLOCK_SETUP((PUSH(rn, 0+XfOrM38_COUNT)));
#   define XfOrM40_COUNT (1+XfOrM38_COUNT)
#   define SETUP_XfOrM40(x) SETUP(XfOrM40_COUNT)
    rn = NULLED_OUT ; 
    rn = FUNCCALL(SETUP_XfOrM40(_), scheme_make_module_rename (0 , 0 , ((void * ) 0 ) ) ); 
    env -> rename = rn ; 
  }
  FUNCCALL(SETUP_XfOrM38(_), scheme_append_module_rename (initial_renames , env -> rename ) ); 
  {
    Scheme_Bucket_Table * tl ; 
    BLOCK_SETUP((PUSH(tl, 0+XfOrM38_COUNT)));
#   define XfOrM39_COUNT (1+XfOrM38_COUNT)
#   define SETUP_XfOrM39(x) SETUP(XfOrM39_COUNT)
    tl = NULLED_OUT ; 
    tl = FUNCCALL(SETUP_XfOrM39(_), scheme_clone_toplevel (initial_toplevel , env ) ); 
    env -> toplevel = tl ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void annote_marked_names_nonempty (Scheme_Hash_Table * mn_ht ) {
  /* No conversion */
  scheme_hash_set (mn_ht , scheme_false , scheme_null ) ; 
}
static void clear_marked_names_nonempty (Scheme_Hash_Table * mn_ht ) {
  /* No conversion */
  scheme_hash_set (mn_ht , scheme_false , ((void * ) 0 ) ) ; 
}
static Scheme_Object * default_module_resolver (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  scheme_arg_mismatch ("default-module-name-resolver" , "the kernel's resolver always fails; given: " , argv [0 ] ) ; 
  return ((void * ) 0 ) ; 
}
static Scheme_Object * check_resolver (int argc , Scheme_Object * * argv ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM46_COUNT (1)
# define SETUP_XfOrM46(x) SETUP(XfOrM46_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (FUNCCALL(SETUP_XfOrM46(_), scheme_check_proc_arity (((void * ) 0 ) , 1 , 0 , argc , argv ) )&& FUNCCALL(SETUP_XfOrM46(_), scheme_check_proc_arity (((void * ) 0 ) , 3 , 0 , argc , argv ) )&& FUNCCALL(SETUP_XfOrM46(_), scheme_check_proc_arity (((void * ) 0 ) , 4 , 0 , argc , argv ) ))
    RET_VALUE_START (argv [0 ] ) RET_VALUE_END ; 
  FUNCCALL_EMPTY(scheme_wrong_type ("current-module-name-resolver" , "procedure of arity 1, 3, and 4" , 0 , argc , argv ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * current_module_name_resolver (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("current-module-name-resolver" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_CURRENT_MODULE_RESOLVER ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , check_resolver , "procedure of arity 1, 3, and 4" , 1 ) ; 
}
static Scheme_Object * prefix_p (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  Scheme_Object * o = argv [0 ] ; 
  if ((((o ) ) == (scheme_false ) ) || ((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
    return o ; 
  return ((void * ) 0 ) ; 
}
static Scheme_Object * current_module_name_prefix (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("current-module-name-prefix" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_CURRENT_MODULE_PREFIX ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , prefix_p , "symbol or #f" , 1 ) ; 
}
int scheme_module_protected_wrt (Scheme_Object * home_insp , Scheme_Object * insp ) {
  /* No conversion */
  if (! insp )
    return 1 ; 
  if (((insp ) == (scheme_true ) ) )
    return 0 ; 
  return ! scheme_is_subinspector (home_insp , insp ) ; 
}
static Scheme_Object * _dynamic_require (int argc , Scheme_Object * argv [] , Scheme_Env * env , int get_bucket , int phase , int mod_phase , int indirect_ok , int fail_with_error , int position ) {
  Scheme_Object * modname , * modidx ; 
  Scheme_Object * name , * srcname , * srcmname ; 
  Scheme_Module * m , * srcm ; 
  Scheme_Env * menv , * lookup_env = ((void * ) 0 ) ; 
  int i , count , protected = 0 ; 
  const char * errname ; 
  Scheme_Object * __funcarg67 = NULLED_OUT ; 
  Scheme_Object * __funcarg66 = NULLED_OUT ; 
  Scheme_Object * __funcarg65 = NULLED_OUT ; 
  Scheme_Config * __funcarg61 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(17);
  BLOCK_SETUP_TOP((PUSH(lookup_env, 0), PUSH(m, 1), PUSH(modidx, 2), PUSH(srcname, 3), PUSH(menv, 4), PUSH(errname, 5), PUSH(__funcarg65, 6), PUSH(env, 7), PUSH(name, 8), PUSH(srcm, 9), PUSH(modname, 10), PUSH(srcmname, 11), PUSH(argv, 12)));
# define XfOrM51_COUNT (13)
# define SETUP_XfOrM51(x) SETUP(XfOrM51_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  modname = NULLED_OUT ; 
  modidx = NULLED_OUT ; 
  name = NULLED_OUT ; 
  srcname = NULLED_OUT ; 
  srcmname = NULLED_OUT ; 
  m = NULLED_OUT ; 
  srcm = NULLED_OUT ; 
  menv = NULLED_OUT ; 
  errname = NULLED_OUT ; 
  modname = argv [0 ] ; 
  name = argv [1 ] ; 
  errname = (phase ? ((phase < 0 ) ? "dynamic-require-for-template" : "dynamic-require-for-syntax" ) : "dynamic-require" ) ; 
  if ((! (((name ) ) == (scheme_false ) ) ) && ! ((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) && ! (((name ) ) == (scheme_void ) ) ) {
#   define XfOrM93_COUNT (0+XfOrM51_COUNT)
#   define SETUP_XfOrM93(x) SETUP_XfOrM51(x)
    FUNCCALL_EMPTY(scheme_wrong_type (errname , "symbol, #f, or void" , 1 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (((Scheme_Type ) (((((long ) (modname ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (modname ) ) -> type ) ) == (Scheme_Type ) (scheme_module_index_type ) ) )
    modidx = modname ; 
  else modidx = FUNCCALL(SETUP_XfOrM51(_), scheme_make_modidx (modname , scheme_false , scheme_false ) ); 
  modname = FUNCCALL(SETUP_XfOrM51(_), scheme_module_resolve (modidx , 1 ) ); 
  if (phase == 1 ) {
#   define XfOrM92_COUNT (0+XfOrM51_COUNT)
#   define SETUP_XfOrM92(x) SETUP_XfOrM51(x)
    FUNCCALL(SETUP_XfOrM92(_), scheme_prepare_exp_env (env ) ); 
    if (mod_phase )
      lookup_env = env -> exp_env ; 
    else env = env -> exp_env ; 
  }
  else if (phase == - 1 ) {
#   define XfOrM91_COUNT (0+XfOrM51_COUNT)
#   define SETUP_XfOrM91(x) SETUP_XfOrM51(x)
    FUNCCALL(SETUP_XfOrM91(_), scheme_prepare_template_env (env ) ); 
    env = env -> template_env ; 
  }
  m = FUNCCALL(SETUP_XfOrM51(_), module_load (modname , env , errname ) ); 
  srcm = m ; 
  srcmname = ((void * ) 0 ) ; 
  srcname = ((void * ) 0 ) ; 
  if (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
#   define XfOrM55_COUNT (0+XfOrM51_COUNT)
#   define SETUP_XfOrM55(x) SETUP_XfOrM51(x)
    if (mod_phase ) {
      srcname = name ; 
      srcmname = modname ; 
    }
    else {
#     define XfOrM56_COUNT (0+XfOrM55_COUNT)
#     define SETUP_XfOrM56(x) SETUP_XfOrM55(x)
      try_again : count = srcm -> me -> rt -> num_provides ; 
      if (position >= 0 ) {
#       define XfOrM85_COUNT (0+XfOrM56_COUNT)
#       define SETUP_XfOrM85(x) SETUP_XfOrM56(x)
        if (position < srcm -> me -> rt -> num_var_provides ) {
#         define XfOrM87_COUNT (0+XfOrM85_COUNT)
#         define SETUP_XfOrM87(x) SETUP_XfOrM85(x)
          i = position ; 
          if (((((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (name ) ) ) -> len ) == (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (srcm -> me -> rt -> provide_src_names [i ] ) ) ) -> len ) ) && ! (memcmp ((((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (name ) ) ) -> s ) , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (srcm -> me -> rt -> provide_src_names [i ] ) ) ) -> s ) , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (name ) ) ) -> len ) ) ) ) {
            name = srcm -> me -> rt -> provides [i ] ; 
          }
          else {
            i = count ; 
            indirect_ok = 0 ; 
          }
        }
        else {
          position -= srcm -> me -> rt -> num_var_provides ; 
          i = count ; 
        }
      }
      else {
#       define XfOrM70_COUNT (0+XfOrM56_COUNT)
#       define SETUP_XfOrM70(x) SETUP_XfOrM56(x)
        for (i = 0 ; i < count ; i ++ ) {
#         define XfOrM78_COUNT (0+XfOrM70_COUNT)
#         define SETUP_XfOrM78(x) SETUP_XfOrM70(x)
          if (((name ) == (srcm -> me -> rt -> provides [i ] ) ) ) {
#           define XfOrM79_COUNT (0+XfOrM78_COUNT)
#           define SETUP_XfOrM79(x) SETUP_XfOrM78(x)
            if (i < srcm -> me -> rt -> num_var_provides ) {
              break ; 
            }
            else {
#             define XfOrM80_COUNT (0+XfOrM79_COUNT)
#             define SETUP_XfOrM80(x) SETUP_XfOrM79(x)
              if (fail_with_error ) {
#               define XfOrM81_COUNT (0+XfOrM80_COUNT)
#               define SETUP_XfOrM81(x) SETUP_XfOrM80(x)
                if (! phase ) {
                  Scheme_Object * a [3 ] , * ns ; 
                  BLOCK_SETUP((PUSH(ns, 0+XfOrM81_COUNT), PUSHARRAY(a, 3, 1+XfOrM81_COUNT)));
#                 define XfOrM83_COUNT (4+XfOrM81_COUNT)
#                 define SETUP_XfOrM83(x) SETUP(XfOrM83_COUNT)
                  a[0] = NULLED_OUT ; 
                  a[1] = NULLED_OUT ; 
                  a[2] = NULLED_OUT ; 
                  ns = NULLED_OUT ; 
                  FUNCCALL(SETUP_XfOrM83(_), start_module (m , env , 0 , modidx , 1 , 0 , scheme_null ) ); 
                  a [0 ] = FUNCCALL(SETUP_XfOrM83(_), scheme_intern_symbol ("empty" ) ); 
                  ns = FUNCCALL(SETUP_XfOrM83(_), scheme_make_namespace (1 , a ) ); 
                  a [0 ] = (Scheme_Object * ) env ; 
                  a [1 ] = srcm -> modname ; 
                  a [2 ] = ns ; 
                  FUNCCALL(SETUP_XfOrM83(_), namespace_attach_module (3 , a ) ); 
                  a [0 ] = (__funcarg65 = FUNCCALL(SETUP_XfOrM83(_), scheme_intern_symbol ("only" ) ), __funcarg66 = (__funcarg67 = FUNCCALL(SETUP_XfOrM83(_), scheme_make_pair (name , scheme_null ) ), FUNCCALL_AGAIN(scheme_make_pair (srcm -> modname , __funcarg67 ) )) , FUNCCALL_AGAIN(scheme_make_pair (__funcarg65 , __funcarg66 ) )) ; 
                  FUNCCALL(SETUP_XfOrM83(_), do_namespace_require ((Scheme_Env * ) ns , 1 , a , 0 , 0 , 0 ) ); 
                  RET_VALUE_START (FUNCCALL(SETUP_XfOrM83(_), scheme_eval (name , (Scheme_Env * ) ns ) )) RET_VALUE_END ; 
                }
                else {
#                 define XfOrM82_COUNT (0+XfOrM81_COUNT)
#                 define SETUP_XfOrM82(x) SETUP_XfOrM81(x)
                  FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: name is provided as syntax: %V by module: %V" , errname , name , srcm -> modname ) ); 
                }
              }
              RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
            }
          }
        }
      }
      if (i < count ) {
#       define XfOrM68_COUNT (0+XfOrM56_COUNT)
#       define SETUP_XfOrM68(x) SETUP_XfOrM56(x)
        if (srcm -> provide_protects )
          protected = srcm -> provide_protects [i ] ; 
        srcmname = (srcm -> me -> rt -> provide_srcs ? srcm -> me -> rt -> provide_srcs [i ] : scheme_false ) ; 
        if ((((srcmname ) ) == (scheme_false ) ) )
          srcmname = srcm -> modname ; 
        else {
#         define XfOrM69_COUNT (0+XfOrM68_COUNT)
#         define SETUP_XfOrM69(x) SETUP_XfOrM68(x)
          srcmname = FUNCCALL(SETUP_XfOrM69(_), scheme_modidx_shift (srcmname , srcm -> me -> src_modidx , srcm -> self_modidx ) ); 
          srcmname = FUNCCALL(SETUP_XfOrM69(_), scheme_module_resolve (srcmname , 1 ) ); 
        }
        srcname = srcm -> me -> rt -> provide_src_names [i ] ; 
      }
      if ((position < 0 ) && (i == count ) && srcm -> me -> rt -> reprovide_kernel ) {
        srcm = kernel ; 
        goto try_again ; 
      }
      if (i == count ) {
#       define XfOrM57_COUNT (0+XfOrM56_COUNT)
#       define SETUP_XfOrM57(x) SETUP_XfOrM56(x)
        if (indirect_ok ) {
#         define XfOrM59_COUNT (0+XfOrM57_COUNT)
#         define SETUP_XfOrM59(x) SETUP_XfOrM57(x)
          srcm = m ; 
          count = srcm -> num_indirect_provides ; 
          if (position >= 0 ) {
#           define XfOrM65_COUNT (0+XfOrM59_COUNT)
#           define SETUP_XfOrM65(x) SETUP_XfOrM59(x)
            i = position ; 
            if ((i < srcm -> num_indirect_provides ) && ((((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (name ) ) ) -> len ) == (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (srcm -> indirect_provides [i ] ) ) ) -> len ) ) && ! (memcmp ((((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (name ) ) ) -> s ) , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (srcm -> indirect_provides [i ] ) ) ) -> s ) , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (name ) ) ) -> len ) ) ) ) {
              name = srcm -> indirect_provides [i ] ; 
              srcname = name ; 
              srcmname = srcm -> modname ; 
              if (srcm -> provide_protects )
                protected = srcm -> provide_protects [i ] ; 
            }
            else i = count ; 
          }
          else {
            for (i = 0 ; i < count ; i ++ ) {
              if (((name ) == (srcm -> indirect_provides [i ] ) ) ) {
                srcname = name ; 
                srcmname = srcm -> modname ; 
                if (srcm -> provide_protects )
                  protected = srcm -> provide_protects [i ] ; 
                break ; 
              }
            }
          }
        }
        if (i == count ) {
#         define XfOrM58_COUNT (0+XfOrM57_COUNT)
#         define SETUP_XfOrM58(x) SETUP_XfOrM57(x)
          if (fail_with_error )
            FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: name is not provided: %V by module: %V" , errname , name , srcm -> modname ) ); 
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        }
      }
    }
  }
  if ((((name ) ) == (scheme_void ) ) )
    FUNCCALL(SETUP_XfOrM51(_), expstart_module (m , env , 0 , modidx , 0 , 1 , scheme_null ) ); 
  else FUNCCALL(SETUP_XfOrM51(_), start_module (m , env , 0 , modidx , 1 , 0 , scheme_null ) ); 
  if (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
    Scheme_Bucket * b ; 
    BLOCK_SETUP((PUSH(b, 0+XfOrM51_COUNT)));
#   define XfOrM52_COUNT (1+XfOrM51_COUNT)
#   define SETUP_XfOrM52(x) SETUP(XfOrM52_COUNT)
    b = NULLED_OUT ; 
    menv = FUNCCALL(SETUP_XfOrM52(_), scheme_module_access (srcmname , lookup_env ? lookup_env : env , mod_phase ) ); 
    if (protected ) {
      Scheme_Object * insp ; 
      BLOCK_SETUP((PUSH(insp, 0+XfOrM52_COUNT)));
#     define XfOrM54_COUNT (1+XfOrM52_COUNT)
#     define SETUP_XfOrM54(x) SETUP(XfOrM54_COUNT)
      insp = NULLED_OUT ; 
      insp = (__funcarg61 = FUNCCALL(SETUP_XfOrM54(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg61 , MZCONFIG_CODE_INSPECTOR ) )) ; 
      if (FUNCCALL(SETUP_XfOrM54(_), scheme_module_protected_wrt (menv -> insp , insp ) ))
        FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: name is protected: %V from module: %V" , errname , name , srcm -> modname ) ); 
    }
    b = FUNCCALL(SETUP_XfOrM52(_), scheme_bucket_from_table (menv -> toplevel , (const char * ) srcname ) ); 
    if (get_bucket )
      RET_VALUE_START ((Scheme_Object * ) b ) RET_VALUE_END ; 
    else {
#     define XfOrM53_COUNT (0+XfOrM52_COUNT)
#     define SETUP_XfOrM53(x) SETUP_XfOrM52(x)
      if (! b -> val && fail_with_error )
        FUNCCALL(SETUP_XfOrM53(_), scheme_unbound_global (b ) ); 
      RET_VALUE_START (b -> val ) RET_VALUE_END ; 
    }
  }
  else RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_dynamic_require (int argc , Scheme_Object * argv [] ) {
  Scheme_Env * __funcarg68 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM94_COUNT (1)
# define SETUP_XfOrM94(x) SETUP(XfOrM94_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (scheme_module_demand_hook ) {
    Scheme_Object * r ; 
    BLOCK_SETUP((PUSH(r, 0+XfOrM94_COUNT)));
#   define XfOrM95_COUNT (1+XfOrM94_COUNT)
#   define SETUP_XfOrM95(x) SETUP(XfOrM95_COUNT)
    r = NULLED_OUT ; 
    r = FUNCCALL(SETUP_XfOrM95(_), scheme_module_demand_hook (argc , argv ) ); 
    if (r )
      RET_VALUE_START (r ) RET_VALUE_END ; 
  }
  RET_VALUE_START ((__funcarg68 = FUNCCALL(SETUP_XfOrM94(_), scheme_get_env (((void * ) 0 ) ) ), FUNCCALL_EMPTY(_dynamic_require (argc , argv , __funcarg68 , 0 , 0 , 0 , 0 , 1 , - 1 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * dynamic_require_for_syntax (int argc , Scheme_Object * argv [] ) {
  Scheme_Env * __funcarg69 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM96_COUNT (1)
# define SETUP_XfOrM96(x) SETUP(XfOrM96_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg69 = FUNCCALL(SETUP_XfOrM96(_), scheme_get_env (((void * ) 0 ) ) ), FUNCCALL_EMPTY(_dynamic_require (argc , argv , __funcarg69 , 0 , 1 , 0 , 0 , 1 , - 1 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_namespace_require (Scheme_Env * env , int argc , Scheme_Object * argv [] , int for_exp , int copy , int etonly ) {
  Scheme_Object * form , * rn , * brn , * et_rn , * dt_rn ; 
  Scheme_Object * __funcarg71 = NULLED_OUT ; 
  Scheme_Object * __funcarg70 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSH(dt_rn, 0), PUSH(rn, 1), PUSH(env, 2), PUSH(et_rn, 3), PUSH(brn, 4), PUSH(form, 5), PUSH(argv, 6)));
# define XfOrM97_COUNT (7)
# define SETUP_XfOrM97(x) SETUP(XfOrM97_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  form = NULLED_OUT ; 
  rn = NULLED_OUT ; 
  brn = NULLED_OUT ; 
  et_rn = NULLED_OUT ; 
  dt_rn = NULLED_OUT ; 
  if (! env )
    env = FUNCCALL(SETUP_XfOrM97(_), scheme_get_env (((void * ) 0 ) ) ); 
  if (for_exp ) {
#   define XfOrM103_COUNT (0+XfOrM97_COUNT)
#   define SETUP_XfOrM103(x) SETUP_XfOrM97(x)
    FUNCCALL(SETUP_XfOrM103(_), scheme_prepare_exp_env (env ) ); 
    env = env -> exp_env ; 
  }
  form = (__funcarg70 = (__funcarg71 = FUNCCALL(SETUP_XfOrM97(_), scheme_make_pair (argv [0 ] , scheme_null ) ), FUNCCALL_AGAIN(scheme_make_pair (require_stx , __funcarg71 ) )) , FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg70 , scheme_false , scheme_false , 1 , 0 ) )) ; 
  rn = FUNCCALL(SETUP_XfOrM97(_), scheme_make_module_rename (for_exp , 0 , ((void * ) 0 ) ) ); 
  if (! for_exp && ! etonly && ! copy ) {
#   define XfOrM100_COUNT (0+XfOrM97_COUNT)
#   define SETUP_XfOrM100(x) SETUP_XfOrM97(x)
    FUNCCALL(SETUP_XfOrM100(_), scheme_prepare_exp_env (env ) ); 
    et_rn = env -> exp_env -> rename ; 
    if (! et_rn ) {
#     define XfOrM102_COUNT (0+XfOrM100_COUNT)
#     define SETUP_XfOrM102(x) SETUP_XfOrM100(x)
      et_rn = FUNCCALL(SETUP_XfOrM102(_), scheme_make_module_rename (1 , 0 , ((void * ) 0 ) ) ); 
      env -> exp_env -> rename = et_rn ; 
    }
    dt_rn = env -> dt_rename ; 
    if (! dt_rn ) {
#     define XfOrM101_COUNT (0+XfOrM100_COUNT)
#     define SETUP_XfOrM101(x) SETUP_XfOrM100(x)
      dt_rn = FUNCCALL(SETUP_XfOrM101(_), scheme_make_module_rename (30000 , 0 , ((void * ) 0 ) ) ); 
      env -> dt_rename = dt_rn ; 
    }
  }
  else {
    et_rn = ((void * ) 0 ) ; 
    dt_rn = ((void * ) 0 ) ; 
  }
  (void ) FUNCCALL(SETUP_XfOrM97(_), parse_requires (form , scheme_false , env , rn , rn , et_rn , et_rn , dt_rn , dt_rn , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ! etonly , etonly , ((void * ) 0 ) , 1 , copy , 0 , ((void * ) 0 ) ) ); 
  brn = env -> rename ; 
  if (! brn ) {
#   define XfOrM98_COUNT (0+XfOrM97_COUNT)
#   define SETUP_XfOrM98(x) SETUP_XfOrM97(x)
    brn = FUNCCALL(SETUP_XfOrM98(_), scheme_make_module_rename (for_exp , 0 , ((void * ) 0 ) ) ); 
    env -> rename = brn ; 
  }
  FUNCCALL_EMPTY(scheme_append_module_rename (rn , brn ) ); 
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * namespace_require (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_namespace_require (((void * ) 0 ) , argc , argv , 0 , 0 , 0 ) ; 
}
static Scheme_Object * namespace_trans_require (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_namespace_require (((void * ) 0 ) , argc , argv , 1 , 0 , 0 ) ; 
}
static Scheme_Object * namespace_require_copy (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_namespace_require (((void * ) 0 ) , argc , argv , 0 , 1 , 0 ) ; 
}
static Scheme_Object * namespace_require_etonly (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_namespace_require (((void * ) 0 ) , argc , argv , 0 , 0 , 1 ) ; 
}
static Scheme_Object * namespace_attach_module (int argc , Scheme_Object * argv [] ) {
  Scheme_Env * from_env , * to_env , * menv , * menv2 ; 
  Scheme_Object * todo , * next_phase_todo , * prev_phase_todo ; 
  Scheme_Object * name , * notifies = scheme_null , * a [1 ] , * resolver ; 
  Scheme_Object * to_modchain , * from_modchain , * l ; 
  Scheme_Hash_Table * checked , * next_checked , * prev_checked ; 
  Scheme_Object * past_checkeds , * future_checkeds , * future_todos , * past_to_modchains ; 
  Scheme_Module * m2 ; 
  int same_namespace , set_env_for_notify = 0 , phase ; 
  Scheme_Object * __funcarg73 = NULLED_OUT ; 
  Scheme_Config * __funcarg72 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(27);
  BLOCK_SETUP_TOP((PUSH(next_checked, 0), PUSH(menv2, 1), PUSH(to_modchain, 2), PUSH(m2, 3), PUSH(next_phase_todo, 4), PUSH(prev_checked, 5), PUSH(to_env, 6), PUSH(from_modchain, 7), PUSH(prev_phase_todo, 8), PUSH(l, 9), PUSH(name, 10), PUSH(checked, 11), PUSH(menv, 12), PUSH(future_checkeds, 13), PUSH(from_env, 14), PUSH(todo, 15), PUSHARRAY(a, 1, 16), PUSH(notifies, 19), PUSH(future_todos, 20), PUSH(resolver, 21), PUSH(past_checkeds, 22), PUSH(past_to_modchains, 23), PUSH(argv, 24)));
# define XfOrM108_COUNT (25)
# define SETUP_XfOrM108(x) SETUP(XfOrM108_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  from_env = NULLED_OUT ; 
  to_env = NULLED_OUT ; 
  menv = NULLED_OUT ; 
  menv2 = NULLED_OUT ; 
  todo = NULLED_OUT ; 
  next_phase_todo = NULLED_OUT ; 
  prev_phase_todo = NULLED_OUT ; 
  name = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  resolver = NULLED_OUT ; 
  to_modchain = NULLED_OUT ; 
  from_modchain = NULLED_OUT ; 
  l = NULLED_OUT ; 
  checked = NULLED_OUT ; 
  next_checked = NULLED_OUT ; 
  prev_checked = NULLED_OUT ; 
  past_checkeds = NULLED_OUT ; 
  future_checkeds = NULLED_OUT ; 
  future_todos = NULLED_OUT ; 
  past_to_modchains = NULLED_OUT ; 
  m2 = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_namespace_type ) ) )
    FUNCCALL(SETUP_XfOrM108(_), scheme_wrong_type ("namespace-attach-module" , "namespace" , 0 , argc , argv ) ); 
  from_env = (Scheme_Env * ) argv [0 ] ; 
  if (argc > 2 ) {
#   define XfOrM263_COUNT (0+XfOrM108_COUNT)
#   define SETUP_XfOrM263(x) SETUP_XfOrM108(x)
    if (! ((Scheme_Type ) (((((long ) (argv [2 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [2 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_namespace_type ) ) )
      FUNCCALL(SETUP_XfOrM263(_), scheme_wrong_type ("namespace-attach-module" , "namespace" , 2 , argc , argv ) ); 
    to_env = (Scheme_Env * ) argv [2 ] ; 
    set_env_for_notify = 1 ; 
  }
  else to_env = FUNCCALL(SETUP_XfOrM108(_), scheme_get_env (((void * ) 0 ) ) ); 
  same_namespace = ((from_env ) == (to_env ) ) ; 
  if (((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
    name = argv [1 ] ; 
  else name = (__funcarg73 = FUNCCALL(SETUP_XfOrM108(_), scheme_make_modidx (argv [1 ] , scheme_false , scheme_false ) ), FUNCCALL_AGAIN(scheme_module_resolve (__funcarg73 , 0 ) )) ; 
  todo = FUNCCALL(SETUP_XfOrM108(_), scheme_make_pair (name , scheme_null ) ); 
  next_phase_todo = scheme_null ; 
  prev_phase_todo = scheme_null ; 
  from_modchain = from_env -> modchain ; 
  to_modchain = to_env -> modchain ; 
  phase = 0 ; 
  checked = ((void * ) 0 ) ; 
  next_checked = ((void * ) 0 ) ; 
  prev_checked = ((void * ) 0 ) ; 
  past_checkeds = scheme_null ; 
  future_checkeds = scheme_null ; 
  future_todos = scheme_null ; 
  past_to_modchains = scheme_null ; 
  while (! ((todo ) == (scheme_null ) ) ) {
#   define XfOrM200_COUNT (0+XfOrM108_COUNT)
#   define SETUP_XfOrM200(x) SETUP_XfOrM108(x)
    if (! checked )
      checked = FUNCCALL(SETUP_XfOrM200(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
    if (! next_checked )
      next_checked = FUNCCALL(SETUP_XfOrM200(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
    while (! ((todo ) == (scheme_null ) ) ) {
#     define XfOrM237_COUNT (0+XfOrM200_COUNT)
#     define SETUP_XfOrM237(x) SETUP_XfOrM200(x)
      name = (((Scheme_Simple_Object * ) (todo ) ) -> u . pair_val . car ) ; 
      todo = (((Scheme_Simple_Object * ) (todo ) ) -> u . pair_val . cdr ) ; 
      FUNCCALL(SETUP_XfOrM237(_), scheme_hash_set (checked , name , scheme_true ) ); 
      if (! ((name ) == (kernel_symbol ) ) ) {
#       define XfOrM238_COUNT (0+XfOrM237_COUNT)
#       define SETUP_XfOrM238(x) SETUP_XfOrM237(x)
        menv = (Scheme_Env * ) FUNCCALL(SETUP_XfOrM238(_), scheme_hash_get (((Scheme_Hash_Table * ) ((((Scheme_Vector * ) (from_modchain ) ) -> els ) [0 ] ) ) , name ) ); 
        if (! menv ) {
#         define XfOrM262_COUNT (0+XfOrM238_COUNT)
#         define SETUP_XfOrM262(x) SETUP_XfOrM238(x)
          if (FUNCCALL(SETUP_XfOrM262(_), scheme_hash_get (from_env -> module_registry , name ) ))
            FUNCCALL(SETUP_XfOrM262(_), scheme_arg_mismatch ("namespace-attach-module" , "module not instantiated (in the source namespace): " , name ) ); 
          else FUNCCALL(SETUP_XfOrM262(_), scheme_arg_mismatch ("namespace-attach-module" , "unknown module (in the source namespace): " , name ) ); 
        }
        if ((! (((to_modchain ) ) == (scheme_false ) ) ) ) {
#         define XfOrM257_COUNT (0+XfOrM238_COUNT)
#         define SETUP_XfOrM257(x) SETUP_XfOrM238(x)
          menv2 = (Scheme_Env * ) FUNCCALL(SETUP_XfOrM257(_), scheme_hash_get (((Scheme_Hash_Table * ) ((((Scheme_Vector * ) (to_modchain ) ) -> els ) [0 ] ) ) , name ) ); 
          if (menv2 ) {
            if (! ((menv -> toplevel ) == (menv2 -> toplevel ) ) )
              m2 = menv2 -> module ; 
            else m2 = ((void * ) 0 ) ; 
          }
          else {
#           define XfOrM260_COUNT (0+XfOrM257_COUNT)
#           define SETUP_XfOrM260(x) SETUP_XfOrM257(x)
            m2 = (Scheme_Module * ) FUNCCALL(SETUP_XfOrM260(_), scheme_hash_get (to_env -> module_registry , name ) ); 
            if (m2 && ((m2 ) == (menv -> module ) ) )
              m2 = ((void * ) 0 ) ; 
          }
          if (m2 ) {
            char * phase , buf [32 ] ; 
#           define XfOrM258_COUNT (0+XfOrM257_COUNT)
#           define SETUP_XfOrM258(x) SETUP_XfOrM257(x)
            phase = NULLED_OUT ; 
            if (! menv -> phase )
              phase = "" ; 
            else if (menv -> phase == 1 )
              phase = " for syntax" ; 
            else {
#             define XfOrM259_COUNT (0+XfOrM258_COUNT)
#             define SETUP_XfOrM259(x) SETUP_XfOrM258(x)
              (sprintf (buf , " at phase %ld" , menv -> phase ) ) ; 
              phase = buf ; 
            }
            FUNCCALL(SETUP_XfOrM258(_), scheme_raise_exn (MZEXN_FAIL_CONTRACT , "namespace-attach-module: " "a different module with the same name is already " "in the destination namespace%s, for name: %S" , phase , name ) ); 
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          }
        }
        else menv2 = ((void * ) 0 ) ; 
        if (! menv2 || same_namespace ) {
#         define XfOrM239_COUNT (0+XfOrM238_COUNT)
#         define SETUP_XfOrM239(x) SETUP_XfOrM238(x)
          l = menv -> require_names ; 
          while (! ((l ) == (scheme_null ) ) ) {
#           define XfOrM255_COUNT (0+XfOrM239_COUNT)
#           define SETUP_XfOrM255(x) SETUP_XfOrM239(x)
            name = FUNCCALL(SETUP_XfOrM255(_), scheme_module_resolve ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) , 0 ) ); 
            if (! FUNCCALL(SETUP_XfOrM255(_), scheme_hash_get (checked , name ) )) {
#             define XfOrM256_COUNT (0+XfOrM255_COUNT)
#             define SETUP_XfOrM256(x) SETUP_XfOrM255(x)
              todo = FUNCCALL(SETUP_XfOrM256(_), scheme_make_pair (name , todo ) ); 
              FUNCCALL(SETUP_XfOrM256(_), scheme_hash_set (checked , name , scheme_true ) ); 
            }
            l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
          }
          if (menv -> lazy_syntax )
            FUNCCALL(SETUP_XfOrM239(_), finish_expstart_module_in_namespace (menv , from_env ) ); 
          l = menv -> et_require_names ; 
          while (! ((l ) == (scheme_null ) ) ) {
#           define XfOrM251_COUNT (0+XfOrM239_COUNT)
#           define SETUP_XfOrM251(x) SETUP_XfOrM239(x)
            name = FUNCCALL(SETUP_XfOrM251(_), scheme_module_resolve ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) , 0 ) ); 
            if (! FUNCCALL(SETUP_XfOrM251(_), scheme_hash_get (next_checked , name ) )) {
#             define XfOrM252_COUNT (0+XfOrM251_COUNT)
#             define SETUP_XfOrM252(x) SETUP_XfOrM251(x)
              next_phase_todo = FUNCCALL(SETUP_XfOrM252(_), scheme_make_pair (name , next_phase_todo ) ); 
              FUNCCALL(SETUP_XfOrM252(_), scheme_hash_set (next_checked , name , scheme_true ) ); 
            }
            l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
          }
          l = menv -> tt_require_names ; 
          if (l ) {
#           define XfOrM240_COUNT (0+XfOrM239_COUNT)
#           define SETUP_XfOrM240(x) SETUP_XfOrM239(x)
            while (! ((l ) == (scheme_null ) ) ) {
#             define XfOrM245_COUNT (0+XfOrM240_COUNT)
#             define SETUP_XfOrM245(x) SETUP_XfOrM240(x)
              name = FUNCCALL(SETUP_XfOrM245(_), scheme_module_resolve ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) , 0 ) ); 
              if (phase > 0 ) {
#               define XfOrM247_COUNT (0+XfOrM245_COUNT)
#               define SETUP_XfOrM247(x) SETUP_XfOrM245(x)
                if (! prev_checked )
                  prev_checked = FUNCCALL(SETUP_XfOrM247(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
                if (! FUNCCALL(SETUP_XfOrM247(_), scheme_hash_get (prev_checked , name ) )) {
#                 define XfOrM248_COUNT (0+XfOrM247_COUNT)
#                 define SETUP_XfOrM248(x) SETUP_XfOrM247(x)
                  prev_phase_todo = FUNCCALL(SETUP_XfOrM248(_), scheme_make_pair (name , prev_phase_todo ) ); 
                  FUNCCALL(SETUP_XfOrM248(_), scheme_hash_set (prev_checked , name , scheme_true ) ); 
                }
              }
              else {
              }
              l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
            }
          }
        }
      }
    }
    do {
#     define XfOrM206_COUNT (0+XfOrM200_COUNT)
#     define SETUP_XfOrM206(x) SETUP_XfOrM200(x)
      if (((Scheme_Type ) (((((long ) (prev_phase_todo ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (prev_phase_todo ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#       define XfOrM210_COUNT (0+XfOrM206_COUNT)
#       define SETUP_XfOrM210(x) SETUP_XfOrM206(x)
        future_todos = FUNCCALL(SETUP_XfOrM210(_), scheme_make_pair (next_phase_todo , future_todos ) ); 
        future_checkeds = FUNCCALL(SETUP_XfOrM210(_), scheme_make_pair ((Scheme_Object * ) next_checked , future_checkeds ) ); 
        next_checked = checked ; 
        next_phase_todo = scheme_null ; 
        todo = prev_phase_todo ; 
        prev_phase_todo = scheme_null ; 
        checked = prev_checked ; 
        prev_checked = (Scheme_Hash_Table * ) (((Scheme_Simple_Object * ) (past_checkeds ) ) -> u . pair_val . car ) ; 
        past_checkeds = (((Scheme_Simple_Object * ) (past_checkeds ) ) -> u . pair_val . cdr ) ; 
        from_modchain = (((Scheme_Vector * ) (from_modchain ) ) -> els ) [2 ] ; 
        to_modchain = (((Scheme_Simple_Object * ) (past_to_modchains ) ) -> u . pair_val . car ) ; 
        past_to_modchains = (((Scheme_Simple_Object * ) (past_to_modchains ) ) -> u . pair_val . cdr ) ; 
        phase -- ; 
      }
      else {
#       define XfOrM207_COUNT (0+XfOrM206_COUNT)
#       define SETUP_XfOrM207(x) SETUP_XfOrM206(x)
        past_checkeds = FUNCCALL(SETUP_XfOrM207(_), scheme_make_raw_pair ((Scheme_Object * ) prev_checked , past_checkeds ) ); 
        prev_checked = checked ; 
        todo = next_phase_todo ; 
        checked = next_checked ; 
        if (((future_todos ) == (scheme_null ) ) ) {
          next_phase_todo = scheme_null ; 
          next_checked = ((void * ) 0 ) ; 
        }
        else {
          next_phase_todo = (((Scheme_Simple_Object * ) (future_todos ) ) -> u . pair_val . car ) ; 
          future_todos = (((Scheme_Simple_Object * ) (future_todos ) ) -> u . pair_val . cdr ) ; 
          next_checked = (Scheme_Hash_Table * ) (((Scheme_Simple_Object * ) (future_checkeds ) ) -> u . pair_val . car ) ; 
          future_checkeds = (((Scheme_Simple_Object * ) (future_checkeds ) ) -> u . pair_val . cdr ) ; 
        }
        from_modchain = (((Scheme_Vector * ) (from_modchain ) ) -> els ) [1 ] ; 
        past_to_modchains = FUNCCALL(SETUP_XfOrM207(_), scheme_make_pair (to_modchain , past_to_modchains ) ); 
        if ((! (((to_modchain ) ) == (scheme_false ) ) ) )
          to_modchain = (((Scheme_Vector * ) (to_modchain ) ) -> els ) [1 ] ; 
        phase ++ ; 
      }
    }
    while (((todo ) == (scheme_null ) ) && (((Scheme_Type ) (((((long ) (next_phase_todo ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (next_phase_todo ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || ((Scheme_Type ) (((((long ) (future_todos ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (future_todos ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ; 
  }
  phase += 2 ; 
  if (phase > 1 ) {
#   define XfOrM136_COUNT (0+XfOrM108_COUNT)
#   define SETUP_XfOrM136(x) SETUP_XfOrM108(x)
    if (next_checked )
      future_checkeds = FUNCCALL(SETUP_XfOrM136(_), scheme_make_pair ((Scheme_Object * ) next_checked , future_checkeds ) ); 
    -- phase ; 
  }
  if (phase > 0 ) {
#   define XfOrM135_COUNT (0+XfOrM108_COUNT)
#   define SETUP_XfOrM135(x) SETUP_XfOrM108(x)
    if (checked )
      future_checkeds = FUNCCALL(SETUP_XfOrM135(_), scheme_make_pair ((Scheme_Object * ) checked , future_checkeds ) ); 
    -- phase ; 
  }
  if (phase > 0 ) {
#   define XfOrM134_COUNT (0+XfOrM108_COUNT)
#   define SETUP_XfOrM134(x) SETUP_XfOrM108(x)
    future_checkeds = FUNCCALL(SETUP_XfOrM134(_), scheme_make_pair ((Scheme_Object * ) prev_checked , future_checkeds ) ); 
    -- phase ; 
  }
  while (phase > 0 ) {
#   define XfOrM133_COUNT (0+XfOrM108_COUNT)
#   define SETUP_XfOrM133(x) SETUP_XfOrM108(x)
    prev_checked = (Scheme_Hash_Table * ) (((Scheme_Simple_Object * ) (past_checkeds ) ) -> u . pair_val . car ) ; 
    future_checkeds = FUNCCALL(SETUP_XfOrM133(_), scheme_make_raw_pair ((Scheme_Object * ) prev_checked , future_checkeds ) ); 
    past_checkeds = (((Scheme_Simple_Object * ) (past_checkeds ) ) -> u . pair_val . cdr ) ; 
    -- phase ; 
  }
  from_modchain = from_env -> modchain ; 
  to_modchain = to_env -> modchain ; 
  while (! ((future_checkeds ) == (scheme_null ) ) ) {
    int i ; 
#   define XfOrM123_COUNT (0+XfOrM108_COUNT)
#   define SETUP_XfOrM123(x) SETUP_XfOrM108(x)
    checked = (Scheme_Hash_Table * ) (((Scheme_Simple_Object * ) (future_checkeds ) ) -> u . pair_val . car ) ; 
    for (i = checked -> size ; i -- ; ) {
#     define XfOrM128_COUNT (0+XfOrM123_COUNT)
#     define SETUP_XfOrM128(x) SETUP_XfOrM123(x)
      if (checked -> vals [i ] ) {
#       define XfOrM129_COUNT (0+XfOrM128_COUNT)
#       define SETUP_XfOrM129(x) SETUP_XfOrM128(x)
        name = checked -> keys [i ] ; 
        if (! ((name ) == (kernel_symbol ) ) ) {
#         define XfOrM130_COUNT (0+XfOrM129_COUNT)
#         define SETUP_XfOrM130(x) SETUP_XfOrM129(x)
          menv = (Scheme_Env * ) FUNCCALL(SETUP_XfOrM130(_), scheme_hash_get (((Scheme_Hash_Table * ) ((((Scheme_Vector * ) (from_modchain ) ) -> els ) [0 ] ) ) , name ) ); 
          menv2 = (Scheme_Env * ) FUNCCALL(SETUP_XfOrM130(_), scheme_hash_get (((Scheme_Hash_Table * ) ((((Scheme_Vector * ) (to_modchain ) ) -> els ) [0 ] ) ) , name ) ); 
          if (! menv2 ) {
#           define XfOrM131_COUNT (0+XfOrM130_COUNT)
#           define SETUP_XfOrM131(x) SETUP_XfOrM130(x)
            menv2 = FUNCCALL(SETUP_XfOrM131(_), scheme_clone_module_env (menv , to_env , to_modchain ) ); 
            if (menv -> attached )
              menv2 -> attached = 1 ; 
            FUNCCALL(SETUP_XfOrM131(_), scheme_hash_set (((Scheme_Hash_Table * ) ((((Scheme_Vector * ) (to_modchain ) ) -> els ) [0 ] ) ) , name , (Scheme_Object * ) menv2 ) ); 
            FUNCCALL_AGAIN(scheme_hash_set (to_env -> module_registry , name , (Scheme_Object * ) menv2 -> module ) ); 
            FUNCCALL_AGAIN(scheme_hash_set (to_env -> export_registry , name , (Scheme_Object * ) menv2 -> module -> me ) ); 
            if (! same_namespace )
              notifies = FUNCCALL(SETUP_XfOrM131(_), scheme_make_pair (name , notifies ) ); 
          }
        }
      }
    }
    future_checkeds = (((Scheme_Simple_Object * ) (future_checkeds ) ) -> u . pair_val . cdr ) ; 
    from_modchain = (((Scheme_Vector * ) (from_modchain ) ) -> els ) [1 ] ; 
    to_modchain = (((Scheme_Vector * ) (to_modchain ) ) -> els ) [1 ] ; 
    phase ++ ; 
  }
  {
    Scheme_Cont_Frame_Data cframe ; 
    Scheme_Config * config ; 
    BLOCK_SETUP((PUSH(config, 0+XfOrM108_COUNT), PUSH(cframe.cache, 1+XfOrM108_COUNT)));
#   define XfOrM109_COUNT (2+XfOrM108_COUNT)
#   define SETUP_XfOrM109(x) SETUP(XfOrM109_COUNT)
    cframe.cache = NULLED_OUT ; 
    config = NULLED_OUT ; 
    config = FUNCCALL(SETUP_XfOrM109(_), scheme_current_config () ); 
    if (set_env_for_notify ) {
#     define XfOrM113_COUNT (0+XfOrM109_COUNT)
#     define SETUP_XfOrM113(x) SETUP_XfOrM109(x)
      config = (__funcarg72 = FUNCCALL(SETUP_XfOrM113(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_extend_config (__funcarg72 , MZCONFIG_ENV , (Scheme_Object * ) to_env ) )) ; 
      FUNCCALL(SETUP_XfOrM113(_), scheme_push_continuation_frame (& cframe ) ); 
      FUNCCALL_AGAIN(scheme_set_cont_mark (scheme_parameterization_key , (Scheme_Object * ) config ) ); 
    }
    resolver = FUNCCALL(SETUP_XfOrM109(_), scheme_get_param (config , MZCONFIG_CURRENT_MODULE_RESOLVER ) ); 
    while (! ((notifies ) == (scheme_null ) ) ) {
#     define XfOrM112_COUNT (0+XfOrM109_COUNT)
#     define SETUP_XfOrM112(x) SETUP_XfOrM109(x)
      a [0 ] = (((Scheme_Simple_Object * ) (notifies ) ) -> u . pair_val . car ) ; 
      FUNCCALL(SETUP_XfOrM112(_), scheme_apply (resolver , 1 , a ) ); 
      notifies = (((Scheme_Simple_Object * ) (notifies ) ) -> u . pair_val . cdr ) ; 
    }
    if (set_env_for_notify ) {
#     define XfOrM110_COUNT (0+XfOrM109_COUNT)
#     define SETUP_XfOrM110(x) SETUP_XfOrM109(x)
      FUNCCALL(SETUP_XfOrM110(_), scheme_pop_continuation_frame (& cframe ) ); 
    }
  }
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * namespace_unprotect_module (int argc , Scheme_Object * argv [] ) {
  Scheme_Env * to_env , * menv2 ; 
  Scheme_Object * name , * to_modchain , * insp , * code_insp ; 
  Scheme_Object * __funcarg75 = NULLED_OUT ; 
  Scheme_Config * __funcarg74 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSH(name, 0), PUSH(code_insp, 1), PUSH(to_modchain, 2), PUSH(menv2, 3), PUSH(to_env, 4), PUSH(insp, 5), PUSH(argv, 6)));
# define XfOrM264_COUNT (7)
# define SETUP_XfOrM264(x) SETUP(XfOrM264_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  to_env = NULLED_OUT ; 
  menv2 = NULLED_OUT ; 
  name = NULLED_OUT ; 
  to_modchain = NULLED_OUT ; 
  insp = NULLED_OUT ; 
  code_insp = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_inspector_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("namespace-unprotect-module" , "inspector" , 0 , argc , argv ) ); 
  insp = argv [0 ] ; 
  if (argc > 2 )
    to_env = (Scheme_Env * ) argv [2 ] ; 
  else to_env = FUNCCALL(SETUP_XfOrM264(_), scheme_get_env (((void * ) 0 ) ) ); 
  if (((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
    name = argv [1 ] ; 
  else name = (__funcarg75 = FUNCCALL(SETUP_XfOrM264(_), scheme_make_modidx (argv [1 ] , scheme_false , scheme_false ) ), FUNCCALL_AGAIN(scheme_module_resolve (__funcarg75 , 0 ) )) ; 
  to_modchain = to_env -> modchain ; 
  code_insp = (__funcarg74 = FUNCCALL(SETUP_XfOrM264(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg74 , MZCONFIG_CODE_INSPECTOR ) )) ; 
  if (! ((name ) == (kernel_symbol ) ) ) {
#   define XfOrM265_COUNT (0+XfOrM264_COUNT)
#   define SETUP_XfOrM265(x) SETUP_XfOrM264(x)
    menv2 = (Scheme_Env * ) FUNCCALL(SETUP_XfOrM265(_), scheme_hash_get (((Scheme_Hash_Table * ) ((((Scheme_Vector * ) (to_modchain ) ) -> els ) [0 ] ) ) , name ) ); 
    if (! menv2 ) {
#     define XfOrM267_COUNT (0+XfOrM265_COUNT)
#     define SETUP_XfOrM267(x) SETUP_XfOrM265(x)
      FUNCCALL(SETUP_XfOrM267(_), scheme_arg_mismatch ("namespace-unprotect-module" , "module not instantiated (in the target namespace): " , name ) ); 
    }
    if (! FUNCCALL(SETUP_XfOrM265(_), scheme_module_protected_wrt (menv2 -> insp , insp ) )&& ! menv2 -> attached ) {
#     define XfOrM266_COUNT (0+XfOrM265_COUNT)
#     define SETUP_XfOrM266(x) SETUP_XfOrM265(x)
      code_insp = FUNCCALL(SETUP_XfOrM266(_), scheme_make_inspector (code_insp ) ); 
      menv2 -> insp = code_insp ; 
    }
  }
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int do_add_require_renames (Scheme_Object * rn , Scheme_Hash_Table * required , Scheme_Object * orig_src , Scheme_Module * im , Scheme_Module_Phase_Exports * pt , Scheme_Object * idx , int marshal_k ) {
  int i , saw_mb , numvals ; 
  Scheme_Object * * exs , * * exss , * * exsns , * midx , * info , * vec , * nml ; 
  char * exets ; 
  Scheme_Object * __funcarg77 = NULLED_OUT ; 
  Scheme_Object * __funcarg76 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(14);
  BLOCK_SETUP_TOP((PUSH(exs, 0), PUSH(rn, 1), PUSH(im, 2), PUSH(orig_src, 3), PUSH(vec, 4), PUSH(exsns, 5), PUSH(exss, 6), PUSH(required, 7), PUSH(idx, 8), PUSH(nml, 9), PUSH(info, 10), PUSH(exets, 11), PUSH(midx, 12), PUSH(pt, 13)));
# define XfOrM268_COUNT (14)
# define SETUP_XfOrM268(x) SETUP(XfOrM268_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  exs = NULLED_OUT ; 
  exss = NULLED_OUT ; 
  exsns = NULLED_OUT ; 
  midx = NULLED_OUT ; 
  info = NULLED_OUT ; 
  vec = NULLED_OUT ; 
  nml = NULLED_OUT ; 
  exets = NULLED_OUT ; 
  saw_mb = 0 ; 
  exs = pt -> provides ; 
  exsns = pt -> provide_src_names ; 
  exss = pt -> provide_srcs ; 
  exets = pt -> provide_src_phases ; 
  numvals = pt -> num_var_provides ; 
  for (i = pt -> num_provides ; i -- ; ) {
#   define XfOrM277_COUNT (0+XfOrM268_COUNT)
#   define SETUP_XfOrM277(x) SETUP_XfOrM268(x)
    if (exss && ! (((exss [i ] ) ) == (scheme_false ) ) )
      midx = FUNCCALL(SETUP_XfOrM277(_), scheme_modidx_shift (exss [i ] , im -> me -> src_modidx , idx ) ); 
    else midx = idx ; 
    FUNCCALL(SETUP_XfOrM277(_), scheme_extend_module_rename (rn , midx , exs [i ] , exsns [i ] , idx , exs [i ] , exets ? exets [i ] : 0 , 1 ) ); 
    if (((exs [i ] ) == (module_begin_symbol ) ) )
      saw_mb = 1 ; 
    if (required ) {
#     define XfOrM278_COUNT (0+XfOrM277_COUNT)
#     define SETUP_XfOrM278(x) SETUP_XfOrM277(x)
      vec = FUNCCALL(SETUP_XfOrM278(_), scheme_make_vector (6 , ((void * ) 0 ) ) ); 
      nml = FUNCCALL(SETUP_XfOrM278(_), scheme_make_pair (idx , scheme_null ) ); 
      (((Scheme_Vector * ) (vec ) ) -> els ) [0 ] = nml ; 
      (((Scheme_Vector * ) (vec ) ) -> els ) [1 ] = midx ; 
      (((Scheme_Vector * ) (vec ) ) -> els ) [2 ] = exsns [i ] ; 
      (((Scheme_Vector * ) (vec ) ) -> els ) [3 ] = ((i < numvals ) ? scheme_true : scheme_false ) ; 
      (((Scheme_Vector * ) (vec ) ) -> els ) [4 ] = exs [i ] ; 
      (((Scheme_Vector * ) (vec ) ) -> els ) [5 ] = orig_src ; 
      FUNCCALL(SETUP_XfOrM278(_), scheme_hash_set (required , exs [i ] , vec ) ); 
    }
  }
  if (pt -> reprovide_kernel ) {
#   define XfOrM269_COUNT (0+XfOrM268_COUNT)
#   define SETUP_XfOrM269(x) SETUP_XfOrM268(x)
    FUNCCALL(SETUP_XfOrM269(_), scheme_extend_module_rename_with_kernel (rn , idx ) ); 
    saw_mb = 1 ; 
    if (required ) {
#     define XfOrM270_COUNT (0+XfOrM269_COUNT)
#     define SETUP_XfOrM270(x) SETUP_XfOrM269(x)
      exs = kernel -> me -> rt -> provides ; 
      numvals = kernel -> me -> rt -> num_var_provides ; 
      for (i = kernel -> me -> rt -> num_provides ; i -- ; ) {
#       define XfOrM273_COUNT (0+XfOrM270_COUNT)
#       define SETUP_XfOrM273(x) SETUP_XfOrM270(x)
        if (! ((pt -> kernel_exclusion ) == (exs [i ] ) ) ) {
#         define XfOrM274_COUNT (0+XfOrM273_COUNT)
#         define SETUP_XfOrM274(x) SETUP_XfOrM273(x)
          vec = FUNCCALL(SETUP_XfOrM274(_), scheme_make_vector (6 , ((void * ) 0 ) ) ); 
          nml = FUNCCALL(SETUP_XfOrM274(_), scheme_make_pair (idx , scheme_null ) ); 
          (((Scheme_Vector * ) (vec ) ) -> els ) [0 ] = nml ; 
          (((Scheme_Vector * ) (vec ) ) -> els ) [1 ] = kernel_symbol ; 
          (((Scheme_Vector * ) (vec ) ) -> els ) [2 ] = exs [i ] ; 
          (((Scheme_Vector * ) (vec ) ) -> els ) [3 ] = ((i < numvals ) ? scheme_true : scheme_false ) ; 
          (((Scheme_Vector * ) (vec ) ) -> els ) [4 ] = exs [i ] ; 
          (((Scheme_Vector * ) (vec ) ) -> els ) [5 ] = orig_src ; 
          FUNCCALL(SETUP_XfOrM274(_), scheme_hash_set (required , exs [i ] , vec ) ); 
        }
      }
    }
  }
  info = (__funcarg76 = (__funcarg77 = FUNCCALL(SETUP_XfOrM268(_), scheme_make_pair (scheme_null , scheme_false ) ), FUNCCALL_AGAIN(scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (marshal_k ) ) << 1 ) | 0x1 ) ) , __funcarg77 ) )) , FUNCCALL_AGAIN(scheme_make_pair (idx , __funcarg76 ) )) ; 
  FUNCCALL_EMPTY(scheme_save_module_rename_unmarshal (rn , info ) ); 
  RET_VALUE_START (saw_mb ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int add_initial_require_renames (Scheme_Object * orig_src , Scheme_Object * rn , Scheme_Hash_Table * rn_required , Scheme_Object * et_rn , Scheme_Hash_Table * et_required , Scheme_Object * dt_rn , Scheme_Hash_Table * dt_required , Scheme_Module * im , Scheme_Object * idx ) {
  int saw_mb ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSH(im, 0), PUSH(dt_rn, 1), PUSH(idx, 2), PUSH(orig_src, 3), PUSH(et_required, 4), PUSH(dt_required, 5), PUSH(et_rn, 6)));
# define XfOrM279_COUNT (7)
# define SETUP_XfOrM279(x) SETUP(XfOrM279_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (rn )
    saw_mb = FUNCCALL(SETUP_XfOrM279(_), do_add_require_renames (rn , rn_required , orig_src , im , im -> me -> rt , idx , 0 ) ); 
  else saw_mb = 0 ; 
  if (et_rn && im -> me -> et )
    FUNCCALL(SETUP_XfOrM279(_), do_add_require_renames (et_rn , et_required , orig_src , im , im -> me -> et , idx , 1 ) ); 
  if (dt_rn && im -> me -> dt )
    FUNCCALL_EMPTY(do_add_require_renames (dt_rn , dt_required , orig_src , im , im -> me -> dt , idx , 2 ) ); 
  RET_VALUE_START (saw_mb ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int add_require_renames (Scheme_Object * rn , Scheme_Object * et_rn , Scheme_Object * dt_rn , Scheme_Module * im , Scheme_Object * idx ) {
  /* No conversion */
  return add_initial_require_renames (((void * ) 0 ) , rn , ((void * ) 0 ) , et_rn , ((void * ) 0 ) , dt_rn , ((void * ) 0 ) , im , idx ) ; 
}
static Scheme_Object * module_to_namespace (int argc , Scheme_Object * argv [] ) {
  Scheme_Env * menv , * env ; 
  Scheme_Object * modchain , * name ; 
  Scheme_Object * __funcarg79 = NULLED_OUT ; 
  Scheme_Config * __funcarg78 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(12);
  BLOCK_SETUP_TOP((PUSH(modchain, 0), PUSH(name, 1), PUSH(menv, 2), PUSH(env, 3), PUSH(argv, 4)));
# define XfOrM281_COUNT (5)
# define SETUP_XfOrM281(x) SETUP(XfOrM281_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  menv = NULLED_OUT ; 
  env = NULLED_OUT ; 
  modchain = NULLED_OUT ; 
  name = NULLED_OUT ; 
  env = FUNCCALL(SETUP_XfOrM281(_), scheme_get_env (((void * ) 0 ) ) ); 
  name = (__funcarg79 = FUNCCALL(SETUP_XfOrM281(_), scheme_make_modidx (argv [0 ] , scheme_false , scheme_false ) ), FUNCCALL_AGAIN(scheme_module_resolve (__funcarg79 , 1 ) )) ; 
  modchain = env -> modchain ; 
  menv = (Scheme_Env * ) FUNCCALL(SETUP_XfOrM281(_), scheme_hash_get (((Scheme_Hash_Table * ) ((((Scheme_Vector * ) (modchain ) ) -> els ) [0 ] ) ) , name ) ); 
  if (! menv ) {
#   define XfOrM318_COUNT (0+XfOrM281_COUNT)
#   define SETUP_XfOrM318(x) SETUP_XfOrM281(x)
    if (FUNCCALL(SETUP_XfOrM318(_), scheme_hash_get (env -> module_registry , name ) ))
      FUNCCALL(SETUP_XfOrM318(_), scheme_arg_mismatch ("module->namespace" , "module not instantiated in the current namespace: " , name ) ); 
    else FUNCCALL(SETUP_XfOrM318(_), scheme_arg_mismatch ("module->namespace" , "unknown module in the current namespace: " , name ) ); 
  }
  {
    Scheme_Object * insp ; 
    BLOCK_SETUP((PUSH(insp, 0+XfOrM281_COUNT)));
#   define XfOrM316_COUNT (1+XfOrM281_COUNT)
#   define SETUP_XfOrM316(x) SETUP(XfOrM316_COUNT)
    insp = NULLED_OUT ; 
    insp = (__funcarg78 = FUNCCALL(SETUP_XfOrM316(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg78 , MZCONFIG_CODE_INSPECTOR ) )) ; 
    if (FUNCCALL(SETUP_XfOrM316(_), scheme_module_protected_wrt (menv -> insp , insp ) )|| menv -> attached ) {
#     define XfOrM317_COUNT (0+XfOrM316_COUNT)
#     define SETUP_XfOrM317(x) SETUP_XfOrM316(x)
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "module->namespace: current code inspector cannot access namespace of module: %S" , name ) ); 
    }
  }
  if (! menv -> rename ) {
#   define XfOrM302_COUNT (0+XfOrM281_COUNT)
#   define SETUP_XfOrM302(x) SETUP_XfOrM281(x)
    if (menv -> module -> rn_stx ) {
      Scheme_Object * v , * rn ; 
      Scheme_Module * m = menv -> module ; 
      BLOCK_SETUP((PUSH(v, 0+XfOrM302_COUNT), PUSH(rn, 1+XfOrM302_COUNT), PUSH(m, 2+XfOrM302_COUNT)));
#     define XfOrM303_COUNT (3+XfOrM302_COUNT)
#     define SETUP_XfOrM303(x) SETUP(XfOrM303_COUNT)
      v = NULLED_OUT ; 
      rn = NULLED_OUT ; 
      if (((scheme_true ) == (m -> rn_stx ) ) ) {
        int i ; 
        Scheme_Module * im ; 
        Scheme_Object * l , * idx ; 
        Scheme_Hash_Table * mn_ht ; 
        BLOCK_SETUP((PUSH(im, 0+XfOrM303_COUNT), PUSH(idx, 1+XfOrM303_COUNT), PUSH(l, 2+XfOrM303_COUNT), PUSH(mn_ht, 3+XfOrM303_COUNT)));
#       define XfOrM306_COUNT (4+XfOrM303_COUNT)
#       define SETUP_XfOrM306(x) SETUP(XfOrM306_COUNT)
        im = NULLED_OUT ; 
        l = NULLED_OUT ; 
        idx = NULLED_OUT ; 
        mn_ht = NULLED_OUT ; 
        if (menv -> marked_names )
          mn_ht = menv -> marked_names ; 
        else {
#         define XfOrM315_COUNT (0+XfOrM306_COUNT)
#         define SETUP_XfOrM315(x) SETUP_XfOrM306(x)
          mn_ht = FUNCCALL(SETUP_XfOrM315(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
          menv -> marked_names = mn_ht ; 
        }
        rn = FUNCCALL(SETUP_XfOrM306(_), scheme_make_module_rename (0 , 1 , mn_ht ) ); 
        for (i = 0 ; i < m -> me -> rt -> num_provides ; i ++ ) {
#         define XfOrM313_COUNT (0+XfOrM306_COUNT)
#         define SETUP_XfOrM313(x) SETUP_XfOrM306(x)
          if ((((m -> me -> rt -> provide_srcs [i ] ) ) == (scheme_false ) ) ) {
#           define XfOrM314_COUNT (0+XfOrM313_COUNT)
#           define SETUP_XfOrM314(x) SETUP_XfOrM313(x)
            name = m -> me -> rt -> provides [i ] ; 
            FUNCCALL(SETUP_XfOrM314(_), scheme_extend_module_rename (rn , m -> self_modidx , name , name , m -> self_modidx , name , 0 , 0 ) ); 
          }
        }
        for (i = 0 ; i < m -> num_indirect_provides ; i ++ ) {
#         define XfOrM310_COUNT (0+XfOrM306_COUNT)
#         define SETUP_XfOrM310(x) SETUP_XfOrM306(x)
          name = m -> indirect_provides [i ] ; 
          FUNCCALL(SETUP_XfOrM310(_), scheme_extend_module_rename (rn , m -> self_modidx , name , name , m -> self_modidx , name , 0 , 0 ) ); 
        }
        for (l = menv -> require_names ; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#         define XfOrM308_COUNT (0+XfOrM306_COUNT)
#         define SETUP_XfOrM308(x) SETUP_XfOrM306(x)
          idx = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
          name = FUNCCALL(SETUP_XfOrM308(_), scheme_module_resolve (idx , 0 ) ); 
          if (((name ) == (kernel_symbol ) ) )
            im = kernel ; 
          else im = (Scheme_Module * ) FUNCCALL(SETUP_XfOrM308(_), scheme_hash_get (menv -> module_registry , name ) ); 
          FUNCCALL(SETUP_XfOrM308(_), add_require_renames (rn , ((void * ) 0 ) , ((void * ) 0 ) , im , idx ) ); 
        }
        rn = FUNCCALL(SETUP_XfOrM306(_), scheme_rename_to_stx (rn ) ); 
        m -> rn_stx = rn ; 
      }
      else if (((Scheme_Type ) (((((long ) (m -> rn_stx ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (m -> rn_stx ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
        Scheme_Object * rn_stx , * rn , * midx ; 
        BLOCK_SETUP((PUSH(midx, 0+XfOrM303_COUNT), PUSH(rn, 1+XfOrM303_COUNT), PUSH(rn_stx, 2+XfOrM303_COUNT)));
#       define XfOrM305_COUNT (3+XfOrM303_COUNT)
#       define SETUP_XfOrM305(x) SETUP(XfOrM305_COUNT)
        rn_stx = NULLED_OUT ; 
        rn = NULLED_OUT ; 
        midx = NULLED_OUT ; 
        rn_stx = (((Scheme_Simple_Object * ) (m -> rn_stx ) ) -> u . pair_val . car ) ; 
        midx = (((Scheme_Simple_Object * ) (m -> rn_stx ) ) -> u . pair_val . cdr ) ; 
        rn = FUNCCALL(SETUP_XfOrM305(_), scheme_stx_to_rename (rn_stx ) ); 
        rn = FUNCCALL_AGAIN(scheme_stx_shift_rename (rn , midx , m -> self_modidx ) ); 
        rn_stx = FUNCCALL_AGAIN(scheme_rename_to_stx (rn ) ); 
        m -> rn_stx = rn_stx ; 
      }
      v = FUNCCALL(SETUP_XfOrM303(_), scheme_stx_to_rename (m -> rn_stx ) ); 
      rn = FUNCCALL(SETUP_XfOrM303(_), scheme_make_module_rename (0 , 1 , ((void * ) 0 ) ) ); 
      FUNCCALL_AGAIN(scheme_append_module_rename (v , rn ) ); 
      menv -> rename = rn ; 
      if (! menv -> marked_names ) {
        Scheme_Hash_Table * mn ; 
        BLOCK_SETUP((PUSH(mn, 0+XfOrM303_COUNT)));
#       define XfOrM304_COUNT (1+XfOrM303_COUNT)
#       define SETUP_XfOrM304(x) SETUP(XfOrM304_COUNT)
        mn = NULLED_OUT ; 
        mn = FUNCCALL(SETUP_XfOrM304(_), scheme_module_rename_marked_names (rn ) ); 
        menv -> marked_names = mn ; 
      }
    }
  }
  if (menv -> lazy_syntax )
    FUNCCALL(SETUP_XfOrM281(_), finish_expstart_module (menv , env , 0 , scheme_null ) ); 
  FUNCCALL(SETUP_XfOrM281(_), scheme_prepare_exp_env (menv ) ); 
  if (! menv -> exp_env -> rename ) {
    Scheme_Module * m = menv -> module ; 
    BLOCK_SETUP((PUSH(m, 0+XfOrM281_COUNT)));
#   define XfOrM292_COUNT (1+XfOrM281_COUNT)
#   define SETUP_XfOrM292(x) SETUP(XfOrM292_COUNT)
    if (m -> et_rn_stx ) {
      Scheme_Object * v , * rn ; 
      BLOCK_SETUP((PUSH(v, 0+XfOrM292_COUNT), PUSH(rn, 1+XfOrM292_COUNT)));
#     define XfOrM293_COUNT (2+XfOrM292_COUNT)
#     define SETUP_XfOrM293(x) SETUP(XfOrM293_COUNT)
      v = NULLED_OUT ; 
      rn = NULLED_OUT ; 
      if (((scheme_true ) == (m -> et_rn_stx ) ) ) {
        Scheme_Module * im ; 
        Scheme_Object * l , * idx ; 
        Scheme_Hash_Table * mn_ht ; 
        BLOCK_SETUP((PUSH(im, 0+XfOrM293_COUNT), PUSH(idx, 1+XfOrM293_COUNT), PUSH(l, 2+XfOrM293_COUNT), PUSH(mn_ht, 3+XfOrM293_COUNT)));
#       define XfOrM296_COUNT (4+XfOrM293_COUNT)
#       define SETUP_XfOrM296(x) SETUP(XfOrM296_COUNT)
        im = NULLED_OUT ; 
        l = NULLED_OUT ; 
        idx = NULLED_OUT ; 
        mn_ht = NULLED_OUT ; 
        if (menv -> exp_env -> marked_names )
          mn_ht = menv -> exp_env -> marked_names ; 
        else {
#         define XfOrM301_COUNT (0+XfOrM296_COUNT)
#         define SETUP_XfOrM301(x) SETUP_XfOrM296(x)
          mn_ht = FUNCCALL(SETUP_XfOrM301(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
          menv -> exp_env -> marked_names = mn_ht ; 
        }
        rn = FUNCCALL(SETUP_XfOrM296(_), scheme_make_module_rename (0 , 1 , mn_ht ) ); 
        for (l = menv -> et_require_names ; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#         define XfOrM300_COUNT (0+XfOrM296_COUNT)
#         define SETUP_XfOrM300(x) SETUP_XfOrM296(x)
          idx = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
          name = FUNCCALL(SETUP_XfOrM300(_), scheme_module_resolve (idx , 0 ) ); 
          if (((name ) == (kernel_symbol ) ) )
            im = kernel ; 
          else im = (Scheme_Module * ) FUNCCALL(SETUP_XfOrM300(_), scheme_hash_get (menv -> module_registry , name ) ); 
          FUNCCALL(SETUP_XfOrM300(_), add_require_renames (rn , ((void * ) 0 ) , ((void * ) 0 ) , im , idx ) ); 
        }
        for (l = menv -> require_names ; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#         define XfOrM298_COUNT (0+XfOrM296_COUNT)
#         define SETUP_XfOrM298(x) SETUP_XfOrM296(x)
          idx = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
          name = FUNCCALL(SETUP_XfOrM298(_), scheme_module_resolve (idx , 0 ) ); 
          if (((name ) == (kernel_symbol ) ) )
            im = kernel ; 
          else im = (Scheme_Module * ) FUNCCALL(SETUP_XfOrM298(_), scheme_hash_get (menv -> module_registry , name ) ); 
          FUNCCALL(SETUP_XfOrM298(_), add_require_renames (((void * ) 0 ) , rn , ((void * ) 0 ) , im , idx ) ); 
        }
        rn = FUNCCALL(SETUP_XfOrM296(_), scheme_rename_to_stx (rn ) ); 
        m -> et_rn_stx = rn ; 
      }
      else if (((Scheme_Type ) (((((long ) (m -> et_rn_stx ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (m -> et_rn_stx ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
        Scheme_Object * et_rn_stx , * rn , * midx ; 
        BLOCK_SETUP((PUSH(midx, 0+XfOrM293_COUNT), PUSH(et_rn_stx, 1+XfOrM293_COUNT), PUSH(rn, 2+XfOrM293_COUNT)));
#       define XfOrM295_COUNT (3+XfOrM293_COUNT)
#       define SETUP_XfOrM295(x) SETUP(XfOrM295_COUNT)
        et_rn_stx = NULLED_OUT ; 
        rn = NULLED_OUT ; 
        midx = NULLED_OUT ; 
        et_rn_stx = (((Scheme_Simple_Object * ) (m -> et_rn_stx ) ) -> u . pair_val . car ) ; 
        midx = (((Scheme_Simple_Object * ) (m -> et_rn_stx ) ) -> u . pair_val . cdr ) ; 
        rn = FUNCCALL(SETUP_XfOrM295(_), scheme_stx_to_rename (et_rn_stx ) ); 
        rn = FUNCCALL_AGAIN(scheme_stx_shift_rename (rn , midx , m -> self_modidx ) ); 
        et_rn_stx = FUNCCALL_AGAIN(scheme_rename_to_stx (rn ) ); 
        m -> et_rn_stx = et_rn_stx ; 
      }
      v = FUNCCALL(SETUP_XfOrM293(_), scheme_stx_to_rename (m -> et_rn_stx ) ); 
      rn = FUNCCALL(SETUP_XfOrM293(_), scheme_make_module_rename (1 , 1 , ((void * ) 0 ) ) ); 
      FUNCCALL_AGAIN(scheme_append_module_rename (v , rn ) ); 
      menv -> exp_env -> rename = rn ; 
      if (! menv -> exp_env -> marked_names ) {
        Scheme_Hash_Table * mn ; 
        BLOCK_SETUP((PUSH(mn, 0+XfOrM293_COUNT)));
#       define XfOrM294_COUNT (1+XfOrM293_COUNT)
#       define SETUP_XfOrM294(x) SETUP(XfOrM294_COUNT)
        mn = NULLED_OUT ; 
        mn = FUNCCALL(SETUP_XfOrM294(_), scheme_module_rename_marked_names (rn ) ); 
        menv -> exp_env -> marked_names = mn ; 
      }
    }
  }
  if (! menv -> dt_rename ) {
    Scheme_Module * m = menv -> module ; 
    BLOCK_SETUP((PUSH(m, 0+XfOrM281_COUNT)));
#   define XfOrM282_COUNT (1+XfOrM281_COUNT)
#   define SETUP_XfOrM282(x) SETUP(XfOrM282_COUNT)
    if (m -> dt_rn_stx ) {
      Scheme_Object * v , * rn ; 
      BLOCK_SETUP((PUSH(v, 0+XfOrM282_COUNT), PUSH(rn, 1+XfOrM282_COUNT)));
#     define XfOrM283_COUNT (2+XfOrM282_COUNT)
#     define SETUP_XfOrM283(x) SETUP(XfOrM283_COUNT)
      v = NULLED_OUT ; 
      rn = NULLED_OUT ; 
      if (((scheme_true ) == (m -> dt_rn_stx ) ) ) {
        Scheme_Module * im ; 
        Scheme_Object * l , * idx ; 
        Scheme_Hash_Table * mn_ht ; 
        BLOCK_SETUP((PUSH(im, 0+XfOrM283_COUNT), PUSH(idx, 1+XfOrM283_COUNT), PUSH(l, 2+XfOrM283_COUNT), PUSH(mn_ht, 3+XfOrM283_COUNT)));
#       define XfOrM286_COUNT (4+XfOrM283_COUNT)
#       define SETUP_XfOrM286(x) SETUP(XfOrM286_COUNT)
        im = NULLED_OUT ; 
        l = NULLED_OUT ; 
        idx = NULLED_OUT ; 
        mn_ht = NULLED_OUT ; 
        if (menv -> marked_names )
          mn_ht = menv -> marked_names ; 
        else {
#         define XfOrM291_COUNT (0+XfOrM286_COUNT)
#         define SETUP_XfOrM291(x) SETUP_XfOrM286(x)
          mn_ht = FUNCCALL(SETUP_XfOrM291(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
          menv -> marked_names = mn_ht ; 
        }
        rn = FUNCCALL(SETUP_XfOrM286(_), scheme_make_module_rename (30000 , 1 , mn_ht ) ); 
        for (l = menv -> dt_require_names ; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#         define XfOrM290_COUNT (0+XfOrM286_COUNT)
#         define SETUP_XfOrM290(x) SETUP_XfOrM286(x)
          idx = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
          name = FUNCCALL(SETUP_XfOrM290(_), scheme_module_resolve (idx , 0 ) ); 
          if (((name ) == (kernel_symbol ) ) )
            im = kernel ; 
          else im = (Scheme_Module * ) FUNCCALL(SETUP_XfOrM290(_), scheme_hash_get (menv -> module_registry , name ) ); 
          FUNCCALL(SETUP_XfOrM290(_), add_require_renames (rn , ((void * ) 0 ) , ((void * ) 0 ) , im , idx ) ); 
        }
        for (l = menv -> require_names ; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#         define XfOrM288_COUNT (0+XfOrM286_COUNT)
#         define SETUP_XfOrM288(x) SETUP_XfOrM286(x)
          idx = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
          name = FUNCCALL(SETUP_XfOrM288(_), scheme_module_resolve (idx , 0 ) ); 
          if (((name ) == (kernel_symbol ) ) )
            im = kernel ; 
          else im = (Scheme_Module * ) FUNCCALL(SETUP_XfOrM288(_), scheme_hash_get (menv -> module_registry , name ) ); 
          FUNCCALL(SETUP_XfOrM288(_), add_require_renames (((void * ) 0 ) , ((void * ) 0 ) , rn , im , idx ) ); 
        }
        rn = FUNCCALL(SETUP_XfOrM286(_), scheme_rename_to_stx (rn ) ); 
        m -> dt_rn_stx = rn ; 
      }
      else if (((Scheme_Type ) (((((long ) (m -> dt_rn_stx ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (m -> dt_rn_stx ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
        Scheme_Object * dt_rn_stx , * rn , * midx ; 
        BLOCK_SETUP((PUSH(midx, 0+XfOrM283_COUNT), PUSH(rn, 1+XfOrM283_COUNT), PUSH(dt_rn_stx, 2+XfOrM283_COUNT)));
#       define XfOrM285_COUNT (3+XfOrM283_COUNT)
#       define SETUP_XfOrM285(x) SETUP(XfOrM285_COUNT)
        dt_rn_stx = NULLED_OUT ; 
        rn = NULLED_OUT ; 
        midx = NULLED_OUT ; 
        dt_rn_stx = (((Scheme_Simple_Object * ) (m -> dt_rn_stx ) ) -> u . pair_val . car ) ; 
        midx = (((Scheme_Simple_Object * ) (m -> dt_rn_stx ) ) -> u . pair_val . cdr ) ; 
        rn = FUNCCALL(SETUP_XfOrM285(_), scheme_stx_to_rename (dt_rn_stx ) ); 
        rn = FUNCCALL_AGAIN(scheme_stx_shift_rename (rn , midx , m -> self_modidx ) ); 
        dt_rn_stx = FUNCCALL_AGAIN(scheme_rename_to_stx (rn ) ); 
        m -> dt_rn_stx = dt_rn_stx ; 
      }
      v = FUNCCALL(SETUP_XfOrM283(_), scheme_stx_to_rename (m -> dt_rn_stx ) ); 
      rn = FUNCCALL(SETUP_XfOrM283(_), scheme_make_module_rename (30000 , 1 , ((void * ) 0 ) ) ); 
      FUNCCALL_AGAIN(scheme_append_module_rename (v , rn ) ); 
      menv -> dt_rename = rn ; 
      if (! menv -> marked_names ) {
        Scheme_Hash_Table * mn ; 
        BLOCK_SETUP((PUSH(mn, 0+XfOrM283_COUNT)));
#       define XfOrM284_COUNT (1+XfOrM283_COUNT)
#       define SETUP_XfOrM284(x) SETUP(XfOrM284_COUNT)
        mn = NULLED_OUT ; 
        mn = FUNCCALL(SETUP_XfOrM284(_), scheme_module_rename_marked_names (rn ) ); 
        menv -> marked_names = mn ; 
      }
    }
  }
  RET_VALUE_START ((Scheme_Object * ) menv ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * module_compiled_p (int argc , Scheme_Object * argv [] ) {
  Scheme_Module * m ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(m, 0)));
# define XfOrM319_COUNT (1)
# define SETUP_XfOrM319(x) SETUP(XfOrM319_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  m = NULLED_OUT ; 
  m = FUNCCALL(SETUP_XfOrM319(_), scheme_extract_compiled_module (argv [0 ] ) ); 
  RET_VALUE_START ((m ? scheme_true : scheme_false ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * module_compiled_name (int argc , Scheme_Object * argv [] ) {
  Scheme_Module * m ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(m, 1)));
# define XfOrM320_COUNT (2)
# define SETUP_XfOrM320(x) SETUP(XfOrM320_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  m = NULLED_OUT ; 
  m = FUNCCALL(SETUP_XfOrM320(_), scheme_extract_compiled_module (argv [0 ] ) ); 
  if (m ) {
    RET_VALUE_START (m -> modname ) RET_VALUE_END ; 
  }
  FUNCCALL_EMPTY(scheme_wrong_type ("module-compiled-name" , "compiled module declaration" , 0 , argc , argv ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * module_compiled_imports (int argc , Scheme_Object * argv [] ) {
  Scheme_Module * m ; 
  Scheme_Object * a [4 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 4, 0), PUSH(argv, 3), PUSH(m, 4)));
# define XfOrM322_COUNT (5)
# define SETUP_XfOrM322(x) SETUP(XfOrM322_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  m = NULLED_OUT ; 
  NULL_OUT_ARRAY (a ) ; 
  m = FUNCCALL(SETUP_XfOrM322(_), scheme_extract_compiled_module (argv [0 ] ) ); 
  if (m ) {
#   define XfOrM323_COUNT (0+XfOrM322_COUNT)
#   define SETUP_XfOrM323(x) SETUP_XfOrM322(x)
    FUNCCALL(SETUP_XfOrM323(_), scheme_make_list_immutable (m -> requires ) ); 
    FUNCCALL(SETUP_XfOrM323(_), scheme_make_list_immutable (m -> et_requires ) ); 
    FUNCCALL_AGAIN(scheme_make_list_immutable (m -> tt_requires ) ); 
    FUNCCALL_AGAIN(scheme_make_list_immutable (m -> dt_requires ) ); 
    a [0 ] = m -> requires ; 
    a [1 ] = m -> et_requires ; 
    a [2 ] = m -> tt_requires ; 
    a [3 ] = m -> dt_requires ; 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM323(_), scheme_values (4 , a ) )) RET_VALUE_END ; 
  }
  FUNCCALL(SETUP_XfOrM322(_), scheme_wrong_type ("module-compiled-imports" , "compiled module declaration" , 0 , argc , argv ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * module_compiled_exports (int argc , Scheme_Object * argv [] ) {
  Scheme_Module * m ; 
  Scheme_Object * a [6 ] ; 
  Scheme_Object * ml , * vl ; 
  Scheme_Module_Phase_Exports * pt ; 
  int i , n , k ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(8);
  BLOCK_SETUP_TOP((PUSH(vl, 0), PUSH(pt, 1), PUSHARRAY(a, 6, 2), PUSH(argv, 5), PUSH(ml, 6), PUSH(m, 7)));
# define XfOrM324_COUNT (8)
# define SETUP_XfOrM324(x) SETUP(XfOrM324_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  m = NULLED_OUT ; 
  NULL_OUT_ARRAY (a ) ; 
  ml = NULLED_OUT ; 
  vl = NULLED_OUT ; 
  pt = NULLED_OUT ; 
  m = FUNCCALL(SETUP_XfOrM324(_), scheme_extract_compiled_module (argv [0 ] ) ); 
  if (m ) {
#   define XfOrM325_COUNT (0+XfOrM324_COUNT)
#   define SETUP_XfOrM325(x) SETUP_XfOrM324(x)
    for (k = 0 ; k < 3 ; k ++ ) {
#     define XfOrM332_COUNT (0+XfOrM325_COUNT)
#     define SETUP_XfOrM332(x) SETUP_XfOrM325(x)
      switch (k ) {
        case 0 : pt = m -> me -> rt ; 
        break ; 
        case 1 : pt = m -> me -> et ; 
        break ; 
        case 2 : default : pt = m -> me -> dt ; 
        break ; 
      }
      ml = scheme_null ; 
      vl = scheme_null ; 
      n = pt -> num_var_provides ; 
      for (i = pt -> num_provides - 1 ; i >= n ; -- i ) {
#       define XfOrM336_COUNT (0+XfOrM332_COUNT)
#       define SETUP_XfOrM336(x) SETUP_XfOrM332(x)
        ml = FUNCCALL(SETUP_XfOrM336(_), scheme_make_immutable_pair (pt -> provides [i ] , ml ) ); 
      }
      for (; i >= 0 ; -- i ) {
#       define XfOrM334_COUNT (0+XfOrM332_COUNT)
#       define SETUP_XfOrM334(x) SETUP_XfOrM332(x)
        vl = FUNCCALL(SETUP_XfOrM334(_), scheme_make_immutable_pair (pt -> provides [i ] , vl ) ); 
      }
      a [2 * k ] = vl ; 
      a [(2 * k ) + 1 ] = ml ; 
    }
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM325(_), scheme_values (6 , a ) )) RET_VALUE_END ; 
  }
  FUNCCALL(SETUP_XfOrM324(_), scheme_wrong_type ("module-compiled-exports" , "compiled module declaration" , 0 , argc , argv ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * module_path_index_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_module_index_type ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * module_path_index_resolve (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_module_index_type ) ) )
    scheme_wrong_type ("module-path-index-resolve" , "module-path-index" , 0 , argc , argv ) ; 
  return scheme_module_resolve (argv [0 ] , 0 ) ; 
}
static Scheme_Object * module_path_index_split (int argc , Scheme_Object * argv [] ) {
  Scheme_Modidx * modidx ; 
  Scheme_Object * a [2 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(modidx, 0), PUSHARRAY(a, 2, 1), PUSH(argv, 4)));
# define XfOrM340_COUNT (5)
# define SETUP_XfOrM340(x) SETUP(XfOrM340_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  modidx = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_module_index_type ) ) )
    FUNCCALL(SETUP_XfOrM340(_), scheme_wrong_type ("module-path-index-split" , "module-path-index" , 0 , argc , argv ) ); 
  modidx = (Scheme_Modidx * ) argv [0 ] ; 
  a [0 ] = modidx -> path ; 
  a [1 ] = modidx -> base ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM340(_), scheme_values (2 , a ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * module_path_index_join (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
    scheme_wrong_type ("module-path-index-join" , "non-symbol" , 0 , argc , argv ) ; 
  if (argv [1 ] ) {
    if ((! (((argv [1 ] ) ) == (scheme_false ) ) ) && ! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) && ! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_module_index_type ) ) )
      scheme_wrong_type ("module-path-index-join" , "module-path-index, symbol, or #f" , 1 , argc , argv ) ; 
  }
  return scheme_make_modidx (argv [0 ] , argv [1 ] , scheme_false ) ; 
}
static Scheme_Object * module_export_protected_p (int argc , Scheme_Object * * argv ) {
  Scheme_Env * env ; 
  Scheme_Object * modname , * mv , * name ; 
  Scheme_Module * m ; 
  int i , count ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(m, 0), PUSH(mv, 1), PUSH(modname, 2), PUSH(name, 3), PUSH(env, 4), PUSH(argv, 5)));
# define XfOrM343_COUNT (6)
# define SETUP_XfOrM343(x) SETUP(XfOrM343_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  env = NULLED_OUT ; 
  modname = NULLED_OUT ; 
  mv = NULLED_OUT ; 
  name = NULLED_OUT ; 
  m = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) && ! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_module_index_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("module-provide-protected?" , "symbol or module-path-index" , 0 , argc , argv ) ); 
  if (! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("module-provide-protected?" , "symbol" , 1 , argc , argv ) ); 
  modname = FUNCCALL(SETUP_XfOrM343(_), scheme_module_resolve (argv [0 ] , 1 ) ); 
  name = argv [1 ] ; 
  env = FUNCCALL(SETUP_XfOrM343(_), scheme_get_env (((void * ) 0 ) ) ); 
  if (((modname ) == (kernel_symbol ) ) )
    mv = (Scheme_Object * ) kernel ; 
  else mv = FUNCCALL(SETUP_XfOrM343(_), scheme_hash_get (env -> module_registry , modname ) ); 
  if (! mv ) {
#   define XfOrM348_COUNT (0+XfOrM343_COUNT)
#   define SETUP_XfOrM348(x) SETUP_XfOrM343(x)
    FUNCCALL(SETUP_XfOrM348(_), scheme_arg_mismatch ("module-provide-protected?" , "unknown module (in the source namespace): " , modname ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  m = (Scheme_Module * ) mv ; 
  count = m -> me -> rt -> num_provides ; 
  for (i = 0 ; i < count ; i ++ ) {
    if (((name ) == (m -> me -> rt -> provides [i ] ) ) ) {
      if (m -> provide_protects && m -> provide_protects [i ] )
        RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
      else RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    }
  }
  RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_modidx (Scheme_Object * path , Scheme_Object * base_modidx , Scheme_Object * resolved ) {
  Scheme_Modidx * modidx ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(path, 0), PUSH(base_modidx, 1), PUSH(modidx, 2), PUSH(resolved, 3)));
# define XfOrM349_COUNT (4)
# define SETUP_XfOrM349(x) SETUP(XfOrM349_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  modidx = NULLED_OUT ; 
  if (((Scheme_Type ) (((((long ) (path ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (path ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
    RET_VALUE_START (path ) RET_VALUE_END ; 
  modidx = ((Scheme_Modidx * ) FUNCCALL(SETUP_XfOrM349(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Modidx ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  modidx -> so . type = scheme_module_index_type ; 
  modidx -> path = path ; 
  modidx -> base = base_modidx ; 
  modidx -> resolved = resolved ; 
  RET_VALUE_START ((Scheme_Object * ) modidx ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int same_modidx (Scheme_Object * a , Scheme_Object * b ) {
  /* No conversion */
  if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_module_index_type ) ) )
    a = ((Scheme_Modidx * ) a ) -> path ; 
  if (((Scheme_Type ) (((((long ) (b ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (b ) ) -> type ) ) == (Scheme_Type ) (scheme_module_index_type ) ) )
    b = ((Scheme_Modidx * ) b ) -> path ; 
  return scheme_equal (a , b ) ; 
}
int same_resolved_modidx (Scheme_Object * a , Scheme_Object * b ) {
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(a, 0), PUSH(b, 1)));
# define XfOrM351_COUNT (2)
# define SETUP_XfOrM351(x) SETUP(XfOrM351_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_module_index_type ) ) )
    a = FUNCCALL(SETUP_XfOrM351(_), scheme_module_resolve (a , 1 ) ); 
  if (((Scheme_Type ) (((((long ) (b ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (b ) ) -> type ) ) == (Scheme_Type ) (scheme_module_index_type ) ) )
    b = FUNCCALL(SETUP_XfOrM351(_), scheme_module_resolve (b , 1 ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_equal (a , b ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * _module_resolve_k (void ) ; 
static Scheme_Object * _module_resolve (Scheme_Object * modidx , Scheme_Object * stx , int load_it ) {
  Scheme_Config * __funcarg81 = NULLED_OUT ; 
  Scheme_Object * __funcarg80 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(stx, 0), PUSH(modidx, 1)));
# define XfOrM352_COUNT (2)
# define SETUP_XfOrM352(x) SETUP(XfOrM352_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (((Scheme_Type ) (((((long ) (modidx ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (modidx ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((modidx ) ) == (scheme_false ) ) )
    RET_VALUE_START (modidx ) RET_VALUE_END ; 
  if (((modidx ) == (empty_self_modidx ) ) )
    RET_VALUE_START (empty_self_symbol ) RET_VALUE_END ; 
  if ((((((Scheme_Modidx * ) modidx ) -> resolved ) ) == (scheme_false ) ) ) {
    Scheme_Object * a [4 ] ; 
    Scheme_Object * name , * base ; 
    BLOCK_SETUP((PUSH(base, 0+XfOrM352_COUNT), PUSHARRAY(a, 4, 1+XfOrM352_COUNT), PUSH(name, 4+XfOrM352_COUNT)));
#   define XfOrM353_COUNT (5+XfOrM352_COUNT)
#   define SETUP_XfOrM353(x) SETUP(XfOrM353_COUNT)
    NULL_OUT_ARRAY (a ) ; 
    name = NULLED_OUT ; 
    base = NULLED_OUT ; 
    base = ((Scheme_Modidx * ) modidx ) -> base ; 
    if (! (((base ) ) == (scheme_false ) ) ) {
      unsigned long _stk_pos ; 
#     define XfOrM356_COUNT (0+XfOrM353_COUNT)
#     define SETUP_XfOrM356(x) SETUP_XfOrM353(x)
      _stk_pos = (unsigned long ) & _stk_pos ; 
      if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
        Scheme_Thread * p = scheme_current_thread ; 
#       define XfOrM358_COUNT (0+XfOrM356_COUNT)
#       define SETUP_XfOrM358(x) SETUP_XfOrM356(x)
        p -> ku . k . p1 = (void * ) base ; 
        p -> ku . k . i1 = load_it ; 
        base = FUNCCALL(SETUP_XfOrM358(_), scheme_handle_stack_overflow (_module_resolve_k ) ); 
      }
      else {
#       define XfOrM357_COUNT (0+XfOrM356_COUNT)
#       define SETUP_XfOrM357(x) SETUP_XfOrM356(x)
        base = FUNCCALL(SETUP_XfOrM357(_), _module_resolve (base , ((void * ) 0 ) , load_it ) ); 
      }
    }
    a [0 ] = ((Scheme_Modidx * ) modidx ) -> path ; 
    a [1 ] = base ; 
    a [2 ] = (stx ? stx : scheme_false ) ; 
    a [3 ] = (load_it ? scheme_true : scheme_false ) ; 
    if ((((a [0 ] ) ) == (scheme_false ) ) ) {
#     define XfOrM355_COUNT (0+XfOrM353_COUNT)
#     define SETUP_XfOrM355(x) SETUP_XfOrM353(x)
      FUNCCALL(SETUP_XfOrM355(_), scheme_wrong_syntax ("require" , ((void * ) 0 ) , ((void * ) 0 ) , "broken compiled/expanded code: unresolved module index without path" ) ); 
    }
    name = (__funcarg80 = (__funcarg81 = FUNCCALL(SETUP_XfOrM353(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg81 , MZCONFIG_CURRENT_MODULE_RESOLVER ) )) , FUNCCALL_AGAIN(scheme_apply (__funcarg80 , 4 , a ) )) ; 
    if (! ((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
#     define XfOrM354_COUNT (0+XfOrM353_COUNT)
#     define SETUP_XfOrM354(x) SETUP_XfOrM353(x)
      a [0 ] = name ; 
      FUNCCALL(SETUP_XfOrM354(_), scheme_wrong_type ("module name resolver" , "symbol" , - 1 , - 1 , a ) ); 
    }
    ((Scheme_Modidx * ) modidx ) -> resolved = name ; 
  }
  RET_VALUE_START (((Scheme_Modidx * ) modidx ) -> resolved ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * _module_resolve_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * base = (Scheme_Object * ) p -> ku . k . p1 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  return _module_resolve (base , ((void * ) 0 ) , p -> ku . k . i1 ) ; 
}
Scheme_Object * scheme_module_resolve (Scheme_Object * modidx , int load_it ) {
  /* No conversion */
  return _module_resolve (modidx , ((void * ) 0 ) , load_it ) ; 
}
Scheme_Object * scheme_modidx_shift (Scheme_Object * modidx , Scheme_Object * shift_from_modidx , Scheme_Object * shift_to_modidx ) {
  Scheme_Object * base ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(base, 0), PUSH(modidx, 1)));
# define XfOrM361_COUNT (2)
# define SETUP_XfOrM361(x) SETUP(XfOrM361_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  base = NULLED_OUT ; 
  if (! shift_to_modidx )
    RET_VALUE_START (modidx ) RET_VALUE_END ; 
  if (((modidx ) == (shift_from_modidx ) ) )
    RET_VALUE_START (shift_to_modidx ) RET_VALUE_END ; 
  if (! ((Scheme_Type ) (((((long ) (modidx ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (modidx ) ) -> type ) ) == (Scheme_Type ) (scheme_module_index_type ) ) )
    RET_VALUE_START (modidx ) RET_VALUE_END ; 
  base = ((Scheme_Modidx * ) modidx ) -> base ; 
  if (! (((base ) ) == (scheme_false ) ) ) {
    Scheme_Object * sbase ; 
    BLOCK_SETUP((PUSH(sbase, 0+XfOrM361_COUNT)));
#   define XfOrM362_COUNT (1+XfOrM361_COUNT)
#   define SETUP_XfOrM362(x) SETUP(XfOrM362_COUNT)
    sbase = NULLED_OUT ; 
    sbase = FUNCCALL(SETUP_XfOrM362(_), scheme_modidx_shift (base , shift_from_modidx , shift_to_modidx ) ); 
    if (! ((base ) == (sbase ) ) ) {
      Scheme_Modidx * sbm ; 
      int i , c ; 
      Scheme_Object * smodidx , * cvec ; 
      BLOCK_SETUP((PUSH(sbm, 0+XfOrM362_COUNT), PUSH(cvec, 1+XfOrM362_COUNT), PUSH(smodidx, 2+XfOrM362_COUNT)));
#     define XfOrM363_COUNT (3+XfOrM362_COUNT)
#     define SETUP_XfOrM363(x) SETUP(XfOrM363_COUNT)
      sbm = NULLED_OUT ; 
      smodidx = NULLED_OUT ; 
      cvec = NULLED_OUT ; 
      if (((Scheme_Type ) (((((long ) (sbase ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (sbase ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
        sbm = ((void * ) 0 ) ; 
        cvec = global_shift_cache ; 
      }
      else {
        sbm = (Scheme_Modidx * ) sbase ; 
        cvec = sbm -> shift_cache ; 
      }
      c = (cvec ? (((Scheme_Vector * ) (cvec ) ) -> size ) : 0 ) ; 
      for (i = 0 ; i < c ; i += 2 ) {
        if (! ((((Scheme_Vector * ) (cvec ) ) -> els ) [i ] ) )
          break ; 
        if (((modidx ) == ((((Scheme_Vector * ) (cvec ) ) -> els ) [i ] ) ) )
          RET_VALUE_START ((((Scheme_Vector * ) (cvec ) ) -> els ) [i + 1 ] ) RET_VALUE_END ; 
      }
      smodidx = FUNCCALL(SETUP_XfOrM363(_), scheme_make_modidx (((Scheme_Modidx * ) modidx ) -> path , sbase , scheme_false ) ); 
      if (! sbm ) {
#       define XfOrM369_COUNT (0+XfOrM363_COUNT)
#       define SETUP_XfOrM369(x) SETUP_XfOrM363(x)
        if (! global_shift_cache )
          global_shift_cache = FUNCCALL(SETUP_XfOrM369(_), scheme_make_vector (40 , ((void * ) 0 ) ) ); 
        for (i = 0 ; i < (40 - 2 ) ; i ++ ) {
          (((Scheme_Vector * ) (global_shift_cache ) ) -> els ) [i + 2 ] = (((Scheme_Vector * ) (global_shift_cache ) ) -> els ) [i ] ; 
        }
        (((Scheme_Vector * ) (global_shift_cache ) ) -> els ) [0 ] = modidx ; 
        (((Scheme_Vector * ) (global_shift_cache ) ) -> els ) [1 ] = smodidx ; 
      }
      else {
#       define XfOrM364_COUNT (0+XfOrM363_COUNT)
#       define SETUP_XfOrM364(x) SETUP_XfOrM363(x)
        if (cvec && ! sbm -> shift_cache )
          sbm -> shift_cache = cvec ; 
        if (i >= c ) {
          Scheme_Object * naya ; 
          int j ; 
          BLOCK_SETUP((PUSH(naya, 0+XfOrM364_COUNT)));
#         define XfOrM365_COUNT (1+XfOrM364_COUNT)
#         define SETUP_XfOrM365(x) SETUP(XfOrM365_COUNT)
          naya = NULLED_OUT ; 
          naya = FUNCCALL(SETUP_XfOrM365(_), scheme_make_vector (c + 10 , ((void * ) 0 ) ) ); 
          for (j = 0 ; j < c ; j ++ ) {
            (((Scheme_Vector * ) (naya ) ) -> els ) [j ] = (((Scheme_Vector * ) (cvec ) ) -> els ) [j ] ; 
          }
          if (! sbm -> shift_cache ) {
            sbm -> cache_next = modidx_caching_chain ; 
            modidx_caching_chain = sbm ; 
          }
          sbm -> shift_cache = naya ; 
        }
        (((Scheme_Vector * ) (sbm -> shift_cache ) ) -> els ) [i ] = modidx ; 
        (((Scheme_Vector * ) (sbm -> shift_cache ) ) -> els ) [i + 1 ] = smodidx ; 
      }
      RET_VALUE_START (smodidx ) RET_VALUE_END ; 
    }
  }
  RET_VALUE_START (modidx ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_clear_modidx_cache (void ) {
  /* No conversion */
  Scheme_Modidx * sbm , * next ; 
  global_shift_cache = ((void * ) 0 ) ; 
  for (sbm = modidx_caching_chain ; sbm ; sbm = next ) {
    sbm -> shift_cache = ((void * ) 0 ) ; 
    next = sbm -> cache_next ; 
    sbm -> cache_next = ((void * ) 0 ) ; 
  }
  modidx_caching_chain = ((void * ) 0 ) ; 
}
static Scheme_Module * module_load (Scheme_Object * name , Scheme_Env * env , const char * who ) {
  char * __funcarg82 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Module * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(name, 0), PUSH(who, 1)));
# define XfOrM379_COUNT (2)
# define SETUP_XfOrM379(x) SETUP(XfOrM379_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (name == kernel_symbol )
    RET_VALUE_START (kernel ) RET_VALUE_END ; 
  else {
    Scheme_Module * m ; 
    BLOCK_SETUP((PUSH(m, 0+XfOrM379_COUNT)));
#   define XfOrM380_COUNT (1+XfOrM379_COUNT)
#   define SETUP_XfOrM380(x) SETUP(XfOrM380_COUNT)
    m = NULLED_OUT ; 
    m = (Scheme_Module * ) FUNCCALL(SETUP_XfOrM380(_), scheme_hash_get (env -> module_registry , name ) ); 
    if (! m ) {
      char * mred_note ; 
      BLOCK_SETUP((PUSH(mred_note, 0+XfOrM380_COUNT)));
#     define XfOrM381_COUNT (1+XfOrM380_COUNT)
#     define SETUP_XfOrM381(x) SETUP(XfOrM381_COUNT)
      mred_note = NULLED_OUT ; 
      if (! (strcmp ((((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (name ) ) ) -> s ) , "#%mred-kernel" ) ) && ! ((__funcarg82 = FUNCCALL(SETUP_XfOrM381(_), scheme_banner () ), (scheme_strncmp (__funcarg82 , "Welcome to MzScheme" , 19 ) ) ) ) )
        mred_note = "; need to run in MrEd instead of MzScheme" ; 
      else mred_note = "" ; 
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: unknown module: %S%s" , who ? who : "require" , name , mred_note ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    RET_VALUE_START (m ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void setup_accessible_table (Scheme_Module * m ) {
  PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(m, 0)));
# define XfOrM382_COUNT (1)
# define SETUP_XfOrM382(x) SETUP(XfOrM382_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! m -> accessible ) {
    Scheme_Hash_Table * ht ; 
    int i , count , nvp ; 
    BLOCK_SETUP((PUSH(ht, 0+XfOrM382_COUNT)));
#   define XfOrM383_COUNT (1+XfOrM382_COUNT)
#   define SETUP_XfOrM383(x) SETUP(XfOrM383_COUNT)
    ht = NULLED_OUT ; 
    ht = FUNCCALL(SETUP_XfOrM383(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
    nvp = m -> me -> rt -> num_var_provides ; 
    for (i = 0 ; i < nvp ; i ++ ) {
#     define XfOrM392_COUNT (0+XfOrM383_COUNT)
#     define SETUP_XfOrM392(x) SETUP_XfOrM383(x)
      if ((((m -> me -> rt -> provide_srcs [i ] ) ) == (scheme_false ) ) ) {
#       define XfOrM393_COUNT (0+XfOrM392_COUNT)
#       define SETUP_XfOrM393(x) SETUP_XfOrM392(x)
        FUNCCALL(SETUP_XfOrM393(_), scheme_hash_set (ht , m -> me -> rt -> provide_src_names [i ] , ((Scheme_Object * ) (void * ) (long ) ((((long ) (i ) ) << 1 ) | 0x1 ) ) ) ); 
      }
    }
    count = m -> num_indirect_provides ; 
    for (i = 0 ; i < count ; i ++ ) {
#     define XfOrM389_COUNT (0+XfOrM383_COUNT)
#     define SETUP_XfOrM389(x) SETUP_XfOrM383(x)
      FUNCCALL(SETUP_XfOrM389(_), scheme_hash_set (ht , m -> indirect_provides [i ] , ((Scheme_Object * ) (void * ) (long ) ((((long ) (i + nvp ) ) << 1 ) | 0x1 ) ) ) ); 
    }
    m -> accessible = ht ; 
    count = m -> me -> rt -> num_provides ; 
    for (i = nvp ; i < count ; i ++ ) {
#     define XfOrM386_COUNT (0+XfOrM383_COUNT)
#     define SETUP_XfOrM386(x) SETUP_XfOrM383(x)
      if ((((m -> me -> rt -> provide_srcs [i ] ) ) == (scheme_false ) ) ) {
#       define XfOrM387_COUNT (0+XfOrM386_COUNT)
#       define SETUP_XfOrM387(x) SETUP_XfOrM386(x)
        FUNCCALL(SETUP_XfOrM387(_), scheme_hash_set (ht , m -> me -> rt -> provide_src_names [i ] , ((Scheme_Object * ) (void * ) (long ) ((((long ) (- (i + 1 ) ) ) << 1 ) | 0x1 ) ) ) ); 
      }
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Env * scheme_module_access (Scheme_Object * name , Scheme_Env * env , int rev_mod_phase ) {
  DECL_RET_SAVE (Scheme_Env * ) PREPARE_VAR_STACK(1);
# define XfOrM394_COUNT (0)
# define SETUP_XfOrM394(x) SETUP(XfOrM394_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((name == kernel_symbol ) && ! rev_mod_phase )
    RET_VALUE_START (scheme_initial_env ) RET_VALUE_END ; 
  else {
    Scheme_Object * chain ; 
    Scheme_Env * menv ; 
    BLOCK_SETUP((PUSH(menv, 0+XfOrM394_COUNT)));
#   define XfOrM395_COUNT (1+XfOrM394_COUNT)
#   define SETUP_XfOrM395(x) SETUP(XfOrM395_COUNT)
    chain = NULLED_OUT ; 
    menv = NULLED_OUT ; 
    chain = env -> modchain ; 
    if (rev_mod_phase && chain ) {
      chain = ((((Scheme_Vector * ) (chain ) ) -> els ) ) [2 ] ; 
      if ((((chain ) ) == (scheme_false ) ) )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    if (! chain ) {
#     define XfOrM396_COUNT (0+XfOrM395_COUNT)
#     define SETUP_XfOrM396(x) SETUP_XfOrM395(x)
      FUNCCALL_EMPTY(scheme_signal_error ("internal error: missing chain for module instances" ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    menv = (Scheme_Env * ) FUNCCALL(SETUP_XfOrM395(_), scheme_hash_get (((Scheme_Hash_Table * ) ((((Scheme_Vector * ) (chain ) ) -> els ) [0 ] ) ) , name ) ); 
    if (rev_mod_phase && menv )
      menv = menv -> exp_env ; 
    RET_VALUE_START (menv ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void check_certified (Scheme_Object * stx , Scheme_Object * certs , Scheme_Object * insp , Scheme_Object * in_modidx , Scheme_Env * env , Scheme_Object * symbol , int var , int prot ) {
  int need_cert = 1 ; 
  Scheme_Object * midx ; 
  PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(stx, 0), PUSH(midx, 1), PUSH(env, 2), PUSH(symbol, 3), PUSH(in_modidx, 4), PUSH(insp, 5)));
# define XfOrM398_COUNT (6)
# define SETUP_XfOrM398(x) SETUP(XfOrM398_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  midx = NULLED_OUT ; 
  midx = (env -> link_midx ? env -> link_midx : env -> module -> me -> src_modidx ) ; 
  if (stx )
    need_cert = ! FUNCCALL(SETUP_XfOrM398(_), scheme_stx_certified (stx , certs , prot ? ((void * ) 0 ) : midx , env -> insp ) ); 
  if (need_cert && insp )
    need_cert = FUNCCALL(SETUP_XfOrM398(_), scheme_module_protected_wrt (env -> insp , insp ) ); 
  if (need_cert && in_modidx ) {
#   define XfOrM401_COUNT (0+XfOrM398_COUNT)
#   define SETUP_XfOrM401(x) SETUP_XfOrM398(x)
    in_modidx = FUNCCALL(SETUP_XfOrM401(_), scheme_module_resolve (in_modidx , 0 ) ); 
    midx = FUNCCALL(SETUP_XfOrM401(_), scheme_module_resolve (midx , 0 ) ); 
    if (((in_modidx ) == (midx ) ) )
      need_cert = 0 ; 
  }
  if (need_cert ) {
#   define XfOrM399_COUNT (0+XfOrM398_COUNT)
#   define SETUP_XfOrM399(x) SETUP_XfOrM398(x)
    if (stx && (((((Scheme_Type ) (((((long ) (stx ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (stx ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ? ((Scheme_Stx * ) stx ) -> val : stx ) ) == (symbol ) ) ) {
      symbol = stx ; 
      stx = ((void * ) 0 ) ; 
    }
    FUNCCALL_EMPTY(scheme_wrong_syntax ("compile" , stx , symbol , "access from an uncertified context to %s %s from module: %S" , prot ? "protected" : "unexported" , var ? "variable" : "syntax" , env -> module -> modname ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_check_accessible_in_module (Scheme_Env * env , Scheme_Object * prot_insp , Scheme_Object * in_modidx , Scheme_Object * symbol , Scheme_Object * stx , Scheme_Object * certs , Scheme_Object * unexp_insp , int position , int want_pos , int * _protected ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(9);
  BLOCK_SETUP_TOP((PUSH(_protected, 0), PUSH(symbol, 1), PUSH(env, 2), PUSH(certs, 3), PUSH(stx, 4), PUSH(unexp_insp, 5), PUSH(in_modidx, 6), PUSH(prot_insp, 7)));
# define XfOrM402_COUNT (8)
# define SETUP_XfOrM402(x) SETUP(XfOrM402_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  symbol = FUNCCALL(SETUP_XfOrM402(_), scheme_tl_id_sym (env , symbol , ((void * ) 0 ) , 0 ) ); 
  if ((env == scheme_initial_env ) || ((env -> module -> primitive && ! env -> module -> provide_protects ) ) || env -> mod_phase ) {
    if (want_pos )
      RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (- 1 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
    else RET_VALUE_START (symbol ) RET_VALUE_END ; 
  }
  if (position >= 0 ) {
    Scheme_Object * isym ; 
    int need_cert = 0 ; 
    BLOCK_SETUP((PUSH(isym, 0+XfOrM402_COUNT)));
#   define XfOrM412_COUNT (1+XfOrM402_COUNT)
#   define SETUP_XfOrM412(x) SETUP(XfOrM412_COUNT)
    isym = NULLED_OUT ; 
    if (position < env -> module -> me -> rt -> num_var_provides ) {
      if (! env -> module -> me -> rt -> provide_srcs || (((env -> module -> me -> rt -> provide_srcs [position ] ) ) == (scheme_false ) ) )
        isym = env -> module -> me -> rt -> provide_src_names [position ] ; 
      else isym = ((void * ) 0 ) ; 
    }
    else {
      int ipos = position - env -> module -> me -> rt -> num_var_provides ; 
      if (ipos < env -> module -> num_indirect_provides ) {
        isym = env -> module -> indirect_provides [ipos ] ; 
        need_cert = 1 ; 
        if (_protected )
          * _protected = 1 ; 
      }
      else isym = ((void * ) 0 ) ; 
    }
    if (isym ) {
#     define XfOrM413_COUNT (0+XfOrM412_COUNT)
#     define SETUP_XfOrM413(x) SETUP_XfOrM412(x)
      if (((isym ) == (symbol ) ) || ((((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (isym ) ) ) -> len ) == (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (symbol ) ) ) -> len ) && ! (memcmp ((((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (isym ) ) ) -> s ) , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (symbol ) ) ) -> s ) , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (isym ) ) ) -> len ) ) ) ) ) {
#       define XfOrM414_COUNT (0+XfOrM413_COUNT)
#       define SETUP_XfOrM414(x) SETUP_XfOrM413(x)
        if ((position < env -> module -> me -> rt -> num_var_provides ) && FUNCCALL(SETUP_XfOrM414(_), scheme_module_protected_wrt (env -> insp , prot_insp ) )&& env -> module -> provide_protects && env -> module -> provide_protects [position ] ) {
#         define XfOrM415_COUNT (0+XfOrM414_COUNT)
#         define SETUP_XfOrM415(x) SETUP_XfOrM414(x)
          if (_protected )
            * _protected = 1 ; 
          FUNCCALL(SETUP_XfOrM415(_), check_certified (stx , certs , prot_insp , in_modidx , env , symbol , 1 , 1 ) ); 
        }
        if (need_cert )
          FUNCCALL(SETUP_XfOrM414(_), check_certified (stx , certs , unexp_insp , in_modidx , env , symbol , 1 , 0 ) ); 
        if (want_pos )
          RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (position ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
        else RET_VALUE_START (isym ) RET_VALUE_END ; 
      }
    }
  }
  else {
    Scheme_Object * pos ; 
    BLOCK_SETUP((PUSH(pos, 0+XfOrM402_COUNT)));
#   define XfOrM404_COUNT (1+XfOrM402_COUNT)
#   define SETUP_XfOrM404(x) SETUP(XfOrM404_COUNT)
    pos = NULLED_OUT ; 
    pos = FUNCCALL(SETUP_XfOrM404(_), scheme_hash_get (env -> module -> accessible , symbol ) ); 
    if (pos ) {
      if (position < - 1 ) {
        if ((((long ) (pos ) ) >> 1 ) < 0 )
          pos = ((Scheme_Object * ) (void * ) (long ) ((((long ) (- (((long ) (pos ) ) >> 1 ) - 1 ) ) << 1 ) | 0x1 ) ) ; 
        else pos = ((void * ) 0 ) ; 
      }
      else {
        if ((((long ) (pos ) ) >> 1 ) < 0 )
          pos = ((void * ) 0 ) ; 
      }
    }
    if (pos ) {
#     define XfOrM406_COUNT (0+XfOrM404_COUNT)
#     define SETUP_XfOrM406(x) SETUP_XfOrM404(x)
      if (env -> module -> provide_protects && ((((long ) (pos ) ) >> 1 ) < env -> module -> me -> rt -> num_provides ) && env -> module -> provide_protects [(((long ) (pos ) ) >> 1 ) ] ) {
#       define XfOrM408_COUNT (0+XfOrM406_COUNT)
#       define SETUP_XfOrM408(x) SETUP_XfOrM406(x)
        if (_protected )
          * _protected = 1 ; 
        FUNCCALL(SETUP_XfOrM408(_), check_certified (stx , certs , prot_insp , in_modidx , env , symbol , 1 , 1 ) ); 
      }
      if ((position >= - 1 ) && ((((long ) (pos ) ) >> 1 ) >= env -> module -> me -> rt -> num_var_provides ) ) {
#       define XfOrM407_COUNT (0+XfOrM406_COUNT)
#       define SETUP_XfOrM407(x) SETUP_XfOrM406(x)
        if (_protected )
          * _protected = 1 ; 
        FUNCCALL(SETUP_XfOrM407(_), check_certified (stx , certs , unexp_insp , in_modidx , env , symbol , 1 , 0 ) ); 
      }
      if (want_pos )
        RET_VALUE_START (pos ) RET_VALUE_END ; 
      else RET_VALUE_START (symbol ) RET_VALUE_END ; 
    }
    if (position < - 1 ) {
#     define XfOrM405_COUNT (0+XfOrM404_COUNT)
#     define SETUP_XfOrM405(x) SETUP_XfOrM404(x)
      FUNCCALL(SETUP_XfOrM405(_), check_certified (stx , certs , unexp_insp , in_modidx , env , symbol , 0 , 0 ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  if (stx && (((((Scheme_Type ) (((((long ) (stx ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (stx ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ? ((Scheme_Stx * ) stx ) -> val : stx ) ) == (symbol ) ) ) {
    symbol = stx ; 
    stx = ((void * ) 0 ) ; 
  }
  FUNCCALL_EMPTY(scheme_wrong_syntax ("compile" , stx , symbol , "variable not provided (directly or indirectly%s) from module: %S" , (position >= 0 ) ? " and at the expected position" : "" , env -> module -> modname ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_module_export_position (Scheme_Object * modname , Scheme_Env * env , Scheme_Object * varname ) {
  Scheme_Module * m ; 
  Scheme_Object * pos ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(varname, 0), PUSH(pos, 1), PUSH(m, 2)));
# define XfOrM420_COUNT (3)
# define SETUP_XfOrM420(x) SETUP(XfOrM420_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  m = NULLED_OUT ; 
  pos = NULLED_OUT ; 
  if (modname == kernel_symbol )
    RET_VALUE_START (- 1 ) RET_VALUE_END ; 
  m = FUNCCALL(SETUP_XfOrM420(_), module_load (modname , env , ((void * ) 0 ) ) ); 
  if (! m || m -> primitive )
    RET_VALUE_START (- 1 ) RET_VALUE_END ; 
  FUNCCALL(SETUP_XfOrM420(_), setup_accessible_table (m ) ); 
  pos = FUNCCALL_AGAIN(scheme_hash_get (m -> accessible , varname ) ); 
  if (pos && ((((long ) (pos ) ) >> 1 ) >= 0 ) )
    RET_VALUE_START ((((long ) (pos ) ) >> 1 ) ) RET_VALUE_END ; 
  else RET_VALUE_START (- 1 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_module_syntax (Scheme_Object * modname , Scheme_Env * env , Scheme_Object * name ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(name, 0), PUSH(env, 1)));
# define XfOrM421_COUNT (2)
# define SETUP_XfOrM421(x) SETUP(XfOrM421_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (modname == kernel_symbol ) {
#   define XfOrM424_COUNT (0+XfOrM421_COUNT)
#   define SETUP_XfOrM424(x) SETUP_XfOrM421(x)
    name = (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ? ((Scheme_Stx * ) name ) -> val : name ) ; 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_lookup_in_table (scheme_initial_env -> syntax , (char * ) name ) )) RET_VALUE_EMPTY_END ; 
  }
  else {
    Scheme_Env * menv ; 
    Scheme_Object * val ; 
    BLOCK_SETUP((PUSH(val, 0+XfOrM421_COUNT), PUSH(menv, 1+XfOrM421_COUNT)));
#   define XfOrM422_COUNT (2+XfOrM421_COUNT)
#   define SETUP_XfOrM422(x) SETUP(XfOrM422_COUNT)
    menv = NULLED_OUT ; 
    val = NULLED_OUT ; 
    menv = (Scheme_Env * ) FUNCCALL(SETUP_XfOrM422(_), scheme_hash_get (((Scheme_Hash_Table * ) ((((Scheme_Vector * ) (env -> modchain ) ) -> els ) [0 ] ) ) , modname ) ); 
    if (! menv )
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    if (menv -> lazy_syntax ) {
#     define XfOrM423_COUNT (0+XfOrM422_COUNT)
#     define SETUP_XfOrM423(x) SETUP_XfOrM422(x)
      FUNCCALL(SETUP_XfOrM423(_), finish_expstart_module_in_namespace (menv , env ) ); 
    }
    name = FUNCCALL(SETUP_XfOrM422(_), scheme_tl_id_sym (menv , name , ((void * ) 0 ) , 0 ) ); 
    val = FUNCCALL(SETUP_XfOrM422(_), scheme_lookup_in_table (menv -> syntax , (char * ) name ) ); 
    RET_VALUE_START (val ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_module_force_lazy (Scheme_Env * env , int previous ) {
  Scheme_Object * modchain ; 
  Scheme_Hash_Table * mht ; 
  int mi ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(mht, 1)));
# define XfOrM425_COUNT (2)
# define SETUP_XfOrM425(x) SETUP(XfOrM425_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  modchain = NULLED_OUT ; 
  mht = NULLED_OUT ; 
  modchain = env -> modchain ; 
  if (previous )
    modchain = (((Scheme_Vector * ) (modchain ) ) -> els ) [2 ] ; 
  mht = ((Scheme_Hash_Table * ) ((((Scheme_Vector * ) (modchain ) ) -> els ) [0 ] ) ) ; 
  for (mi = mht -> size ; mi -- ; ) {
#   define XfOrM428_COUNT (0+XfOrM425_COUNT)
#   define SETUP_XfOrM428(x) SETUP_XfOrM425(x)
    if (mht -> vals [mi ] ) {
      Scheme_Env * menv = (Scheme_Env * ) mht -> vals [mi ] ; 
#     define XfOrM429_COUNT (0+XfOrM428_COUNT)
#     define SETUP_XfOrM429(x) SETUP_XfOrM428(x)
      if (menv -> lazy_syntax )
        FUNCCALL(SETUP_XfOrM429(_), finish_expstart_module (menv , env , 0 , scheme_null ) ); 
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void templstart_module (Scheme_Env * menv , Scheme_Env * env , int with_tt , Scheme_Object * cycle_list ) {
  Scheme_Object * np , * new_cycle_list , * midx , * l ; 
  Scheme_Module * im ; 
  Scheme_Object * __funcarg84 = NULLED_OUT ; 
  PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSH(midx, 0), PUSH(im, 1), PUSH(env, 2), PUSH(new_cycle_list, 3), PUSH(np, 4), PUSH(menv, 5), PUSH(l, 6)));
# define XfOrM430_COUNT (7)
# define SETUP_XfOrM430(x) SETUP(XfOrM430_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  np = NULLED_OUT ; 
  new_cycle_list = NULLED_OUT ; 
  midx = NULLED_OUT ; 
  l = NULLED_OUT ; 
  im = NULLED_OUT ; 
  new_cycle_list = FUNCCALL(SETUP_XfOrM430(_), scheme_make_pair (menv -> module -> modname , cycle_list ) ); 
  np = scheme_null ; 
  for (l = menv -> module -> tt_requires ; ! ((l ) == (scheme_null ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#   define XfOrM432_COUNT (0+XfOrM430_COUNT)
#   define SETUP_XfOrM432(x) SETUP_XfOrM430(x)
    midx = FUNCCALL(SETUP_XfOrM432(_), scheme_modidx_shift ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) , menv -> module -> me -> src_modidx , menv -> link_midx ) ); 
    FUNCCALL(SETUP_XfOrM432(_), scheme_prepare_template_env (env ) ); 
    im = (__funcarg84 = FUNCCALL(SETUP_XfOrM432(_), scheme_module_resolve (midx , 1 ) ), FUNCCALL_AGAIN(module_load (__funcarg84 , env , ((void * ) 0 ) ) )) ; 
    if (with_tt > 1 )
      FUNCCALL(SETUP_XfOrM432(_), start_module (im , env -> template_env , 0 , midx , 0 , with_tt - 1 , new_cycle_list ) ); 
    else FUNCCALL(SETUP_XfOrM432(_), expstart_module (im , env -> template_env , 0 , midx , 0 , with_tt - 1 , new_cycle_list ) ); 
    np = FUNCCALL(SETUP_XfOrM432(_), scheme_make_pair (midx , np ) ); 
  }
  menv -> tt_require_names = np ; 
  if (with_tt )
    menv -> tt_running = 1 ; 
  else menv -> tt_running = - 1 ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void expstart_module (Scheme_Module * m , Scheme_Env * env , int restart , Scheme_Object * syntax_idx , int delay_exptime , int with_tt , Scheme_Object * cycle_list ) {
  Scheme_Env * menv ; 
  Scheme_Object * l , * midx , * np , * new_cycle_list ; 
  Scheme_Module * im ; 
  Scheme_Object * __funcarg88 = NULLED_OUT ; 
  Scheme_Object * __funcarg86 = NULLED_OUT ; 
  PREPARE_VAR_STACK(12);
  BLOCK_SETUP_TOP((PUSH(menv, 0), PUSH(midx, 1), PUSH(im, 2), PUSH(syntax_idx, 3), PUSH(env, 4), PUSH(m, 5), PUSH(new_cycle_list, 6), PUSH(np, 7), PUSH(cycle_list, 8), PUSH(l, 9)));
# define XfOrM433_COUNT (10)
# define SETUP_XfOrM433(x) SETUP(XfOrM433_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  menv = NULLED_OUT ; 
  l = NULLED_OUT ; 
  midx = NULLED_OUT ; 
  np = NULLED_OUT ; 
  new_cycle_list = NULLED_OUT ; 
  im = NULLED_OUT ; 
  if (! delay_exptime )
    delay_exptime = m -> et_functional ; 
  for (l = cycle_list ; ! ((l ) == (scheme_null ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#   define XfOrM454_COUNT (0+XfOrM433_COUNT)
#   define SETUP_XfOrM454(x) SETUP_XfOrM433(x)
    if (((m -> modname ) == ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ) ) ) {
#     define XfOrM455_COUNT (0+XfOrM454_COUNT)
#     define SETUP_XfOrM455(x) SETUP_XfOrM454(x)
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "module: import cycle detected at: %S" , m -> modname ) ); 
    }
  }
  if (((m ) == (kernel ) ) )
    RET_NOTHING ; 
  if (! restart ) {
#   define XfOrM450_COUNT (0+XfOrM433_COUNT)
#   define SETUP_XfOrM450(x) SETUP_XfOrM433(x)
    menv = (Scheme_Env * ) FUNCCALL(SETUP_XfOrM450(_), scheme_hash_get (((Scheme_Hash_Table * ) ((((Scheme_Vector * ) (env -> modchain ) ) -> els ) [0 ] ) ) , m -> modname ) ); 
    if (menv && menv -> et_running ) {
#     define XfOrM451_COUNT (0+XfOrM450_COUNT)
#     define SETUP_XfOrM451(x) SETUP_XfOrM450(x)
      if (! delay_exptime && menv -> lazy_syntax )
        FUNCCALL(SETUP_XfOrM451(_), finish_expstart_module (menv , env , with_tt , cycle_list ) ); 
      else if (((with_tt > 1 ) && (menv -> tt_running <= 0 ) ) || ((with_tt > 0 ) && (menv -> tt_running == 0 ) ) )
        FUNCCALL(SETUP_XfOrM451(_), templstart_module (menv , env , with_tt , cycle_list ) ); 
      RET_NOTHING ; 
    }
  }
  if (m -> primitive ) {
#   define XfOrM448_COUNT (0+XfOrM433_COUNT)
#   define SETUP_XfOrM448(x) SETUP_XfOrM433(x)
    menv = (Scheme_Env * ) FUNCCALL(SETUP_XfOrM448(_), scheme_hash_get (((Scheme_Hash_Table * ) ((((Scheme_Vector * ) (env -> modchain ) ) -> els ) [0 ] ) ) , m -> modname ) ); 
    if (! menv ) {
#     define XfOrM449_COUNT (0+XfOrM448_COUNT)
#     define SETUP_XfOrM449(x) SETUP_XfOrM448(x)
      menv = m -> primitive ; 
      FUNCCALL(SETUP_XfOrM449(_), scheme_hash_set (((Scheme_Hash_Table * ) ((((Scheme_Vector * ) (env -> modchain ) ) -> els ) [0 ] ) ) , m -> modname , (Scheme_Object * ) menv ) ); 
    }
    menv -> require_names = scheme_null ; 
    menv -> et_require_names = scheme_null ; 
    menv -> tt_require_names = scheme_null ; 
    menv -> dt_require_names = scheme_null ; 
    RET_NOTHING ; 
  }
  menv = (Scheme_Env * ) FUNCCALL(SETUP_XfOrM433(_), scheme_hash_get (((Scheme_Hash_Table * ) ((((Scheme_Vector * ) (env -> modchain ) ) -> els ) [0 ] ) ) , m -> modname ) ); 
  if (! menv || restart ) {
#   define XfOrM440_COUNT (0+XfOrM433_COUNT)
#   define SETUP_XfOrM440(x) SETUP_XfOrM433(x)
    if (! menv ) {
      Scheme_Object * insp ; 
      BLOCK_SETUP((PUSH(insp, 0+XfOrM440_COUNT)));
#     define XfOrM447_COUNT (1+XfOrM440_COUNT)
#     define SETUP_XfOrM447(x) SETUP(XfOrM447_COUNT)
      insp = NULLED_OUT ; 
      menv = FUNCCALL(SETUP_XfOrM447(_), scheme_new_module_env (env , m , 0 ) ); 
      FUNCCALL_AGAIN(scheme_hash_set (((Scheme_Hash_Table * ) ((((Scheme_Vector * ) (env -> modchain ) ) -> els ) [0 ] ) ) , m -> modname , (Scheme_Object * ) menv ) ); 
      menv -> require_names = scheme_null ; 
      menv -> et_require_names = scheme_null ; 
      menv -> tt_require_names = scheme_null ; 
      menv -> dt_require_names = scheme_null ; 
      menv -> phase = env -> phase ; 
      menv -> link_midx = syntax_idx ; 
      insp = FUNCCALL(SETUP_XfOrM447(_), scheme_make_inspector (m -> insp ) ); 
      menv -> insp = insp ; 
    }
    else {
      menv -> module = m ; 
      menv -> running = 0 ; 
      menv -> et_running = 0 ; 
    }
    FUNCCALL(SETUP_XfOrM440(_), setup_accessible_table (m ) ); 
    {
      Scheme_Object * * exss , * * exsns ; 
      int i , count ; 
      BLOCK_SETUP((PUSH(exsns, 0+XfOrM440_COUNT), PUSH(exss, 1+XfOrM440_COUNT)));
#     define XfOrM441_COUNT (2+XfOrM440_COUNT)
#     define SETUP_XfOrM441(x) SETUP(XfOrM441_COUNT)
      exss = NULLED_OUT ; 
      exsns = NULLED_OUT ; 
      exsns = m -> me -> rt -> provide_src_names ; 
      exss = m -> me -> rt -> provide_srcs ; 
      count = m -> me -> rt -> num_var_provides ; 
      for (i = 0 ; i < count ; i ++ ) {
#       define XfOrM445_COUNT (0+XfOrM441_COUNT)
#       define SETUP_XfOrM445(x) SETUP_XfOrM441(x)
        if ((((exss [i ] ) ) == (scheme_false ) ) )
          FUNCCALL(SETUP_XfOrM445(_), scheme_add_to_table (menv -> toplevel , (const char * ) exsns [i ] , ((void * ) 0 ) , 0 ) ); 
      }
      count = m -> num_indirect_provides ; 
      exsns = m -> indirect_provides ; 
      for (i = 0 ; i < count ; i ++ ) {
#       define XfOrM443_COUNT (0+XfOrM441_COUNT)
#       define SETUP_XfOrM443(x) SETUP_XfOrM441(x)
        FUNCCALL(SETUP_XfOrM443(_), scheme_add_to_table (menv -> toplevel , (const char * ) exsns [i ] , ((void * ) 0 ) , 0 ) ); 
      }
    }
  }
  new_cycle_list = FUNCCALL(SETUP_XfOrM433(_), scheme_make_pair (m -> modname , cycle_list ) ); 
  np = scheme_null ; 
  for (l = m -> requires ; ! ((l ) == (scheme_null ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#   define XfOrM439_COUNT (0+XfOrM433_COUNT)
#   define SETUP_XfOrM439(x) SETUP_XfOrM433(x)
    if (syntax_idx )
      midx = FUNCCALL(SETUP_XfOrM439(_), scheme_modidx_shift ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) , m -> me -> src_modidx , syntax_idx ) ); 
    else midx = FUNCCALL(SETUP_XfOrM439(_), scheme_modidx_shift ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) , m -> me -> src_modidx , m -> self_modidx ) ); 
    np = FUNCCALL(SETUP_XfOrM439(_), scheme_make_pair (midx , np ) ); 
    im = (__funcarg88 = FUNCCALL(SETUP_XfOrM439(_), scheme_module_resolve (midx , 1 ) ), FUNCCALL_AGAIN(module_load (__funcarg88 , env , ((void * ) 0 ) ) )) ; 
    FUNCCALL_AGAIN(expstart_module (im , env , 0 , midx , delay_exptime , with_tt , new_cycle_list ) ); 
  }
  menv -> require_names = np ; 
  menv -> et_running = 1 ; 
  if (scheme_starting_up )
    menv -> attached = 1 ; 
  np = scheme_null ; 
  for (l = m -> dt_requires ; ! ((l ) == (scheme_null ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#   define XfOrM437_COUNT (0+XfOrM433_COUNT)
#   define SETUP_XfOrM437(x) SETUP_XfOrM433(x)
    if (syntax_idx )
      midx = FUNCCALL(SETUP_XfOrM437(_), scheme_modidx_shift ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) , m -> me -> src_modidx , syntax_idx ) ); 
    else midx = FUNCCALL(SETUP_XfOrM437(_), scheme_modidx_shift ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) , m -> me -> src_modidx , m -> self_modidx ) ); 
    np = FUNCCALL(SETUP_XfOrM437(_), scheme_make_pair (midx , np ) ); 
    im = (__funcarg86 = FUNCCALL(SETUP_XfOrM437(_), scheme_module_resolve (midx , 1 ) ), FUNCCALL_AGAIN(module_load (__funcarg86 , env , ((void * ) 0 ) ) )) ; 
  }
  menv -> dt_require_names = np ; 
  if (m -> prim_et_body || ! ((m -> et_body ) == (scheme_null ) ) || ! ((m -> et_requires ) == (scheme_null ) ) ) {
#   define XfOrM434_COUNT (0+XfOrM433_COUNT)
#   define SETUP_XfOrM434(x) SETUP_XfOrM433(x)
    if (delay_exptime ) {
      menv -> lazy_syntax = 1 ; 
    }
    else FUNCCALL(SETUP_XfOrM434(_), finish_expstart_module (menv , env , with_tt , cycle_list ) ); 
  }
  else menv -> et_require_names = scheme_null ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void finish_expstart_module (Scheme_Env * menv , Scheme_Env * env , int with_tt , Scheme_Object * cycle_list ) {
  Scheme_Object * l , * body , * e , * names , * midx , * np , * new_cycle_list ; 
  Scheme_Env * exp_env ; 
  Scheme_Bucket_Table * syntax , * for_stx_globals ; 
  Scheme_Module * im ; 
  int let_depth , for_stx ; 
  Scheme_Object * __funcarg96 = NULLED_OUT ; 
  Scheme_Module * __funcarg95 = NULLED_OUT ; 
  Scheme_Object * __funcarg92 = NULLED_OUT ; 
  int __funcarg90 ; 
  PREPARE_VAR_STACK(16);
  BLOCK_SETUP_TOP((PUSH(im, 0), PUSH(menv, 1), PUSH(names, 2), PUSH(new_cycle_list, 3), PUSH(syntax, 4), PUSH(exp_env, 5), PUSH(l, 6), PUSH(for_stx_globals, 7), PUSH(midx, 8), PUSH(cycle_list, 9), PUSH(e, 10), PUSH(np, 11), PUSH(env, 12), PUSH(body, 13)));
# define XfOrM456_COUNT (14)
# define SETUP_XfOrM456(x) SETUP(XfOrM456_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  l = NULLED_OUT ; 
  body = NULLED_OUT ; 
  e = NULLED_OUT ; 
  names = NULLED_OUT ; 
  midx = NULLED_OUT ; 
  np = NULLED_OUT ; 
  new_cycle_list = NULLED_OUT ; 
  exp_env = NULLED_OUT ; 
  syntax = NULLED_OUT ; 
  for_stx_globals = NULLED_OUT ; 
  im = NULLED_OUT ; 
  menv -> lazy_syntax = 0 ; 
  new_cycle_list = FUNCCALL(SETUP_XfOrM456(_), scheme_make_pair (menv -> module -> modname , cycle_list ) ); 
  for (l = menv -> require_names ; ! ((l ) == (scheme_null ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#   define XfOrM465_COUNT (0+XfOrM456_COUNT)
#   define SETUP_XfOrM465(x) SETUP_XfOrM456(x)
    midx = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
    (__funcarg95 = (__funcarg96 = FUNCCALL(SETUP_XfOrM465(_), scheme_module_resolve (midx , 1 ) ), FUNCCALL_AGAIN(module_load (__funcarg96 , env , ((void * ) 0 ) ) )) , FUNCCALL_AGAIN(expstart_module (__funcarg95 , env , 0 , midx , 0 , with_tt , new_cycle_list ) )) ; 
  }
  menv -> et_running = 0 ; 
  syntax = menv -> syntax ; 
  FUNCCALL(SETUP_XfOrM456(_), scheme_prepare_exp_env (menv ) ); 
  exp_env = menv -> exp_env ; 
  for_stx_globals = exp_env -> toplevel ; 
  exp_env -> link_midx = menv -> link_midx ; 
  np = scheme_null ; 
  for (l = menv -> module -> et_requires ; ! ((l ) == (scheme_null ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#   define XfOrM463_COUNT (0+XfOrM456_COUNT)
#   define SETUP_XfOrM463(x) SETUP_XfOrM456(x)
    midx = FUNCCALL(SETUP_XfOrM463(_), scheme_modidx_shift ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) , menv -> module -> me -> src_modidx , exp_env -> link_midx ) ); 
    np = FUNCCALL(SETUP_XfOrM463(_), scheme_make_pair (midx , np ) ); 
    im = (__funcarg92 = FUNCCALL(SETUP_XfOrM463(_), scheme_module_resolve (midx , 1 ) ), FUNCCALL_AGAIN(module_load (__funcarg92 , env , ((void * ) 0 ) ) )) ; 
    FUNCCALL_AGAIN(start_module (im , exp_env , 0 , midx , 0 , with_tt + 1 , new_cycle_list ) ); 
  }
  menv -> et_require_names = np ; 
  if (((menv -> module -> tt_requires ) == (scheme_null ) ) )
    menv -> tt_running = 1 ; 
  if (((with_tt > 1 ) && (menv -> tt_running <= 0 ) ) || ((with_tt > 0 ) && (menv -> tt_running == 0 ) ) ) {
#   define XfOrM461_COUNT (0+XfOrM456_COUNT)
#   define SETUP_XfOrM461(x) SETUP_XfOrM456(x)
    FUNCCALL(SETUP_XfOrM461(_), templstart_module (menv , env , with_tt , cycle_list ) ); 
  }
  menv -> et_running = 1 ; 
  if (menv -> module -> prim_et_body ) {
    Scheme_Invoke_Proc ivk = menv -> module -> prim_et_body ; 
    Scheme_Env * cenv ; 
    BLOCK_SETUP((PUSH(cenv, 0+XfOrM456_COUNT)));
#   define XfOrM460_COUNT (1+XfOrM456_COUNT)
#   define SETUP_XfOrM460(x) SETUP(XfOrM460_COUNT)
    cenv = NULLED_OUT ; 
    cenv = ((Scheme_Env * ) FUNCCALL(SETUP_XfOrM460(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Env ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    cenv -> so . type = scheme_namespace_type ; 
    cenv -> module_registry = menv -> module_registry ; 
    cenv -> export_registry = menv -> export_registry ; 
    cenv -> module = menv -> module ; 
    cenv -> insp = menv -> insp ; 
    cenv -> syntax = menv -> syntax ; 
    cenv -> toplevel = exp_env -> toplevel ; 
    cenv -> exp_env = exp_env ; 
    cenv -> modchain = menv -> modchain ; 
    FUNCCALL(SETUP_XfOrM460(_), ivk (cenv , menv -> phase , menv -> link_midx , menv -> module -> body ) ); 
  }
  else {
    Resolve_Prefix * rp ; 
    Scheme_Comp_Env * rhs_env ; 
    BLOCK_SETUP((PUSH(rp, 0+XfOrM456_COUNT), PUSH(rhs_env, 1+XfOrM456_COUNT)));
#   define XfOrM457_COUNT (2+XfOrM456_COUNT)
#   define SETUP_XfOrM457(x) SETUP(XfOrM457_COUNT)
    rp = NULLED_OUT ; 
    rhs_env = NULLED_OUT ; 
    rhs_env = FUNCCALL(SETUP_XfOrM457(_), scheme_new_comp_env (menv , menv -> module -> insp , 1 ) ); 
    for (body = menv -> module -> et_body ; ! ((body ) == (scheme_null ) ) ; body = (((Scheme_Simple_Object * ) (body ) ) -> u . pair_val . cdr ) ) {
#     define XfOrM459_COUNT (0+XfOrM457_COUNT)
#     define SETUP_XfOrM459(x) SETUP_XfOrM457(x)
      e = (((Scheme_Simple_Object * ) (body ) ) -> u . pair_val . car ) ; 
      names = (((Scheme_Vector * ) (e ) ) -> els ) [0 ] ; 
      let_depth = (((long ) ((((Scheme_Vector * ) (e ) ) -> els ) [2 ] ) ) >> 1 ) ; 
      rp = (Resolve_Prefix * ) (((Scheme_Vector * ) (e ) ) -> els ) [3 ] ; 
      for_stx = (! ((((((Scheme_Vector * ) (e ) ) -> els ) [4 ] ) ) == (scheme_false ) ) ) ; 
      e = (((Scheme_Vector * ) (e ) ) -> els ) [1 ] ; 
      (__funcarg90 = FUNCCALL(SETUP_XfOrM459(_), scheme_proper_list_length (names ) ), FUNCCALL_AGAIN(eval_defmacro (names , __funcarg90 , e , exp_env , rhs_env , rp , let_depth , 1 , (for_stx ? for_stx_globals : syntax ) , for_stx , ((void * ) 0 ) ) )) ; 
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void finish_expstart_module_in_namespace (Scheme_Env * menv , Scheme_Env * from_env ) {
  Scheme_Cont_Frame_Data cframe ; 
  Scheme_Config * config ; 
  Scheme_Config * __funcarg97 = NULLED_OUT ; 
  PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(config, 0), PUSH(cframe.cache, 1), PUSH(from_env, 2), PUSH(menv, 3)));
# define XfOrM466_COUNT (4)
# define SETUP_XfOrM466(x) SETUP(XfOrM466_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  cframe.cache = NULLED_OUT ; 
  config = NULLED_OUT ; 
  config = (__funcarg97 = FUNCCALL(SETUP_XfOrM466(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_extend_config (__funcarg97 , MZCONFIG_ENV , (Scheme_Object * ) from_env ) )) ; 
  FUNCCALL_AGAIN(scheme_push_continuation_frame (& cframe ) ); 
  FUNCCALL_AGAIN(scheme_set_cont_mark (scheme_parameterization_key , (Scheme_Object * ) config ) ); 
  FUNCCALL_AGAIN(finish_expstart_module (menv , from_env , 0 , scheme_null ) ); 
  FUNCCALL_AGAIN(scheme_pop_continuation_frame (& cframe ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void start_module (Scheme_Module * m , Scheme_Env * env , int restart , Scheme_Object * syntax_idx , int delay_expstart , int with_tt , Scheme_Object * cycle_list ) {
  Scheme_Env * menv ; 
  Scheme_Object * l , * midx , * new_cycle_list ; 
  Scheme_Object * __funcarg101 = NULLED_OUT ; 
  Scheme_Module * __funcarg100 = NULLED_OUT ; 
  PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSH(midx, 0), PUSH(menv, 1), PUSH(l, 2), PUSH(m, 3), PUSH(new_cycle_list, 4), PUSH(env, 5), PUSH(cycle_list, 6)));
# define XfOrM467_COUNT (7)
# define SETUP_XfOrM467(x) SETUP(XfOrM467_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  menv = NULLED_OUT ; 
  l = NULLED_OUT ; 
  midx = NULLED_OUT ; 
  new_cycle_list = NULLED_OUT ; 
  if (((m ) == (kernel ) ) )
    RET_NOTHING ; 
  for (l = cycle_list ; ! ((l ) == (scheme_null ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#   define XfOrM474_COUNT (0+XfOrM467_COUNT)
#   define SETUP_XfOrM474(x) SETUP_XfOrM467(x)
    if (((m -> modname ) == ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ) ) ) {
#     define XfOrM475_COUNT (0+XfOrM474_COUNT)
#     define SETUP_XfOrM475(x) SETUP_XfOrM474(x)
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "module: import cycle detected at: %S" , m -> modname ) ); 
    }
  }
  FUNCCALL(SETUP_XfOrM467(_), expstart_module (m , env , restart , syntax_idx , delay_expstart , with_tt , cycle_list ) ); 
  if (m -> primitive )
    RET_NOTHING ; 
  menv = (Scheme_Env * ) FUNCCALL(SETUP_XfOrM467(_), scheme_hash_get (((Scheme_Hash_Table * ) ((((Scheme_Vector * ) (env -> modchain ) ) -> els ) [0 ] ) ) , m -> modname ) ); 
  if (restart )
    menv -> running = 0 ; 
  if (menv -> running > 0 )
    RET_NOTHING ; 
  new_cycle_list = FUNCCALL(SETUP_XfOrM467(_), scheme_make_pair (m -> modname , cycle_list ) ); 
  for (l = menv -> require_names ; ! ((l ) == (scheme_null ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#   define XfOrM471_COUNT (0+XfOrM467_COUNT)
#   define SETUP_XfOrM471(x) SETUP_XfOrM467(x)
    midx = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
    (__funcarg100 = (__funcarg101 = FUNCCALL(SETUP_XfOrM471(_), scheme_module_resolve (midx , 1 ) ), FUNCCALL_AGAIN(module_load (__funcarg101 , env , ((void * ) 0 ) ) )) , FUNCCALL_AGAIN(start_module (__funcarg100 , env , 0 , midx , delay_expstart , with_tt , new_cycle_list ) )) ; 
  }
  menv -> running = 1 ; 
  if (menv -> module -> prim_body ) {
    Scheme_Invoke_Proc ivk = menv -> module -> prim_body ; 
#   define XfOrM469_COUNT (0+XfOrM467_COUNT)
#   define SETUP_XfOrM469(x) SETUP_XfOrM467(x)
    FUNCCALL(SETUP_XfOrM469(_), ivk (menv , menv -> phase , menv -> link_midx , m -> body ) ); 
  }
  else {
#   define XfOrM468_COUNT (0+XfOrM467_COUNT)
#   define SETUP_XfOrM468(x) SETUP_XfOrM467(x)
    FUNCCALL_EMPTY(eval_module_body (menv ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void * eval_module_body_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Env * menv ; 
  menv = (Scheme_Env * ) p -> ku . k . p1 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  eval_module_body (menv ) ; 
  return ((void * ) 0 ) ; 
}
static void eval_module_body (Scheme_Env * menv ) {
  Scheme_Module * m = menv -> module ; 
  Scheme_Object * body , * * save_runstack ; 
  int depth ; 
  PREPARE_VAR_STACK(9);
  BLOCK_SETUP_TOP((PUSH(save_runstack, 0), PUSH(menv, 1), PUSH(body, 2), PUSH(m, 3)));
# define XfOrM477_COUNT (4)
# define SETUP_XfOrM477(x) SETUP(XfOrM477_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  body = NULLED_OUT ; 
  save_runstack = NULLED_OUT ; 
  depth = m -> max_let_depth + FUNCCALL(SETUP_XfOrM477(_), scheme_prefix_depth (m -> prefix ) ); 
  if (! FUNCCALL(SETUP_XfOrM477(_), scheme_check_runstack (depth ) )) {
    Scheme_Thread * p = scheme_current_thread ; 
#   define XfOrM484_COUNT (0+XfOrM477_COUNT)
#   define SETUP_XfOrM484(x) SETUP_XfOrM477(x)
    p -> ku . k . p1 = menv ; 
    (void ) FUNCCALL(SETUP_XfOrM484(_), scheme_enlarge_runstack (depth , eval_module_body_k ) ); 
    RET_NOTHING ; 
  }
  save_runstack = FUNCCALL(SETUP_XfOrM477(_), scheme_push_prefix (menv , m -> prefix , m -> me -> src_modidx , menv -> link_midx , 0 , menv -> phase ) ); 
  body = m -> body ; 
  for (; ! ((body ) == (scheme_null ) ) ; body = (((Scheme_Simple_Object * ) (body ) ) -> u . pair_val . cdr ) ) {
#   define XfOrM483_COUNT (0+XfOrM477_COUNT)
#   define SETUP_XfOrM483(x) SETUP_XfOrM477(x)
    FUNCCALL(SETUP_XfOrM483(_), scheme_do_eval ((((Scheme_Simple_Object * ) (body ) ) -> u . pair_val . car ) , - 1 , ((void * ) 0 ) , - 1 ) ); 
  }
  if (scheme_module_demand_hook ) {
    Scheme_Object * a [1 ] , * val , * sym ; 
    BLOCK_SETUP((PUSH(val, 0+XfOrM477_COUNT), PUSHARRAY(a, 1, 1+XfOrM477_COUNT), PUSH(sym, 4+XfOrM477_COUNT)));
#   define XfOrM478_COUNT (5+XfOrM477_COUNT)
#   define SETUP_XfOrM478(x) SETUP(XfOrM478_COUNT)
    a[0] = NULLED_OUT ; 
    val = NULLED_OUT ; 
    sym = NULLED_OUT ; 
    a [0 ] = menv -> module -> modname ; 
    sym = FUNCCALL(SETUP_XfOrM478(_), scheme_module_demand_hook (1 , a ) ); 
    if (sym ) {
#     define XfOrM479_COUNT (0+XfOrM478_COUNT)
#     define SETUP_XfOrM479(x) SETUP_XfOrM478(x)
      val = FUNCCALL(SETUP_XfOrM479(_), scheme_lookup_global (sym , menv ) ); 
      if (val ) {
#       define XfOrM480_COUNT (0+XfOrM479_COUNT)
#       define SETUP_XfOrM480(x) SETUP_XfOrM479(x)
        a [0 ] = val ; 
        val = FUNCCALL(SETUP_XfOrM480(_), scheme_module_demand_hook (3 , a ) ); 
        if (val ) {
#         define XfOrM481_COUNT (0+XfOrM480_COUNT)
#         define SETUP_XfOrM481(x) SETUP_XfOrM480(x)
          FUNCCALL(SETUP_XfOrM481(_), scheme_add_global_symbol (sym , val , menv ) ); 
        }
      }
    }
  }
  FUNCCALL_EMPTY(scheme_pop_prefix (save_runstack ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Env * scheme_primitive_module (Scheme_Object * name , Scheme_Env * for_env ) {
  Scheme_Module * m ; 
  Scheme_Env * env ; 
  Scheme_Object * prefix , * insp ; 
  Scheme_Config * config ; 
  DECL_RET_SAVE (Scheme_Env * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(m, 0), PUSH(for_env, 1), PUSH(env, 2), PUSH(prefix, 3), PUSH(config, 4), PUSH(name, 5), PUSH(insp, 6)));
# define XfOrM485_COUNT (7)
# define SETUP_XfOrM485(x) SETUP(XfOrM485_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  m = NULLED_OUT ; 
  env = NULLED_OUT ; 
  prefix = NULLED_OUT ; 
  insp = NULLED_OUT ; 
  config = NULLED_OUT ; 
  m = ((Scheme_Module * ) FUNCCALL(SETUP_XfOrM485(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Module ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  m -> so . type = scheme_module_type ; 
  env = FUNCCALL(SETUP_XfOrM485(_), scheme_new_module_env (for_env , m , 0 ) ); 
  config = FUNCCALL_AGAIN(scheme_current_config () ); 
  prefix = FUNCCALL_AGAIN(scheme_get_param (config , MZCONFIG_CURRENT_MODULE_PREFIX ) ); 
  if (((Scheme_Type ) (((((long ) (prefix ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (prefix ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
    name = FUNCCALL(SETUP_XfOrM485(_), scheme_symbol_append (prefix , name ) ); 
  insp = FUNCCALL(SETUP_XfOrM485(_), scheme_get_param (config , MZCONFIG_CODE_INSPECTOR ) ); 
  m -> modname = name ; 
  m -> requires = scheme_null ; 
  m -> et_requires = scheme_null ; 
  m -> tt_requires = scheme_null ; 
  m -> dt_requires = scheme_null ; 
  m -> primitive = env ; 
  m -> insp = insp ; 
  {
    Scheme_Module_Exports * me ; 
    BLOCK_SETUP((PUSH(me, 0+XfOrM485_COUNT)));
#   define XfOrM486_COUNT (1+XfOrM485_COUNT)
#   define SETUP_XfOrM486(x) SETUP(XfOrM486_COUNT)
    me = NULLED_OUT ; 
    me = FUNCCALL(SETUP_XfOrM486(_), make_module_exports () ); 
    m -> me = me ; 
  }
  FUNCCALL(SETUP_XfOrM485(_), scheme_hash_set (for_env -> export_registry , m -> modname , (Scheme_Object * ) m -> me ) ); 
  insp = FUNCCALL(SETUP_XfOrM485(_), scheme_make_inspector (insp ) ); 
  env -> insp = insp ; 
  FUNCCALL(SETUP_XfOrM485(_), scheme_hash_set (for_env -> module_registry , m -> modname , (Scheme_Object * ) m ) ); 
  RET_VALUE_START (env ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_finish_primitive_module (Scheme_Env * env ) {
  Scheme_Module * m = env -> module ; 
  Scheme_Bucket_Table * ht ; 
  Scheme_Bucket * * bs ; 
  Scheme_Object * * exs ; 
  int i , count ; 
  PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(m, 0), PUSH(exs, 1), PUSH(env, 2), PUSH(bs, 3), PUSH(ht, 4)));
# define XfOrM487_COUNT (5)
# define SETUP_XfOrM487(x) SETUP(XfOrM487_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ht = NULLED_OUT ; 
  bs = NULLED_OUT ; 
  exs = NULLED_OUT ; 
  count = 0 ; 
  ht = env -> toplevel ; 
  bs = ht -> buckets ; 
  for (i = ht -> size ; i -- ; ) {
    Scheme_Bucket * b = bs [i ] ; 
    if (b && b -> val )
      count ++ ; 
  }
  exs = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM487(_), GC_malloc (sizeof (Scheme_Object * ) * (count ) ) )) ; 
  count = 0 ; 
  for (i = ht -> size ; i -- ; ) {
    Scheme_Bucket * b = bs [i ] ; 
    if (b && b -> val )
      exs [count ++ ] = (Scheme_Object * ) b -> key ; 
  }
  m -> functional = 1 ; 
  m -> et_functional = 1 ; 
  m -> tt_functional = 1 ; 
  m -> me -> rt -> provides = exs ; 
  m -> me -> rt -> provide_srcs = ((void * ) 0 ) ; 
  m -> me -> rt -> provide_src_names = exs ; 
  m -> me -> rt -> num_provides = count ; 
  m -> me -> rt -> num_var_provides = count ; 
  FUNCCALL(SETUP_XfOrM487(_), qsort_provides (exs , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , 0 , count , 1 ) ); 
  env -> running = 1 ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_protect_primitive_provide (Scheme_Env * env , Scheme_Object * name ) {
  Scheme_Module * m = env -> module ; 
  int i ; 
  PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(m, 0), PUSH(name, 1)));
# define XfOrM492_COUNT (2)
# define SETUP_XfOrM492(x) SETUP(XfOrM492_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! m -> provide_protects ) {
    Scheme_Hash_Table * ht ; 
    char * exps ; 
    BLOCK_SETUP((PUSH(ht, 0+XfOrM492_COUNT), PUSH(exps, 1+XfOrM492_COUNT)));
#   define XfOrM501_COUNT (2+XfOrM492_COUNT)
#   define SETUP_XfOrM501(x) SETUP(XfOrM501_COUNT)
    ht = NULLED_OUT ; 
    exps = NULLED_OUT ; 
    ht = FUNCCALL(SETUP_XfOrM501(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
    exps = ((char * ) FUNCCALL(SETUP_XfOrM501(_), GC_malloc_atomic (sizeof (char ) * (m -> me -> rt -> num_provides ) ) )) ; 
    for (i = m -> me -> rt -> num_provides ; i -- ; ) {
#     define XfOrM503_COUNT (0+XfOrM501_COUNT)
#     define SETUP_XfOrM503(x) SETUP_XfOrM501(x)
      exps [i ] = 0 ; 
      FUNCCALL(SETUP_XfOrM503(_), scheme_hash_set (ht , m -> me -> rt -> provides [i ] , ((Scheme_Object * ) (void * ) (long ) ((((long ) (i ) ) << 1 ) | 0x1 ) ) ) ); 
    }
    m -> provide_protects = exps ; 
    m -> accessible = ht ; 
  }
  if (name ) {
    for (i = m -> me -> rt -> num_provides ; i -- ; ) {
      if (((name ) == (m -> me -> rt -> provides [i ] ) ) ) {
        m -> provide_protects [i ] = 1 ; 
        break ; 
      }
    }
  }
  else {
    for (i = m -> me -> rt -> num_provides ; i -- ; ) {
      m -> provide_protects [i ] = 1 ; 
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Bucket * scheme_module_bucket (Scheme_Object * modname , Scheme_Object * var , int pos , Scheme_Env * env ) {
  Scheme_Object * a [2 ] ; 
  DECL_RET_SAVE (Scheme_Bucket * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 2, 0)));
# define XfOrM504_COUNT (3)
# define SETUP_XfOrM504(x) SETUP(XfOrM504_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  a [0 ] = modname ; 
  a [1 ] = var ; 
  RET_VALUE_START ((Scheme_Bucket * ) FUNCCALL(SETUP_XfOrM504(_), _dynamic_require (2 , a , env , 1 , 0 , 0 , 1 , 1 , pos ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_builtin_value (const char * name ) {
  Scheme_Object * a [2 ] , * v ; 
  Scheme_Env * __funcarg102 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSHARRAY(a, 2, 1)));
# define XfOrM505_COUNT (4)
# define SETUP_XfOrM505(x) SETUP(XfOrM505_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  v = NULLED_OUT ; 
  a [1 ] = FUNCCALL(SETUP_XfOrM505(_), scheme_intern_symbol (name ) ); 
  a [0 ] = kernel_symbol ; 
  v = (__funcarg102 = FUNCCALL(SETUP_XfOrM505(_), scheme_get_env (((void * ) 0 ) ) ), FUNCCALL_AGAIN(_dynamic_require (2 , a , __funcarg102 , 0 , 0 , 0 , 0 , 0 , - 1 ) )) ; 
  if (v )
    RET_VALUE_START (v ) RET_VALUE_END ; 
  a [0 ] = FUNCCALL(SETUP_XfOrM505(_), scheme_intern_symbol ("mzscheme" ) ); 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM505(_), _dynamic_require (2 , a , initial_modules_env , 0 , 0 , 0 , 0 , 0 , - 1 ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Module * scheme_extract_compiled_module (Scheme_Object * o ) {
  /* No conversion */
  if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_compilation_top_type ) ) ) {
    Scheme_Compilation_Top * c = (Scheme_Compilation_Top * ) o ; 
    if (((Scheme_Type ) (((((long ) (c -> code ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (c -> code ) ) -> type ) ) == (Scheme_Type ) (scheme_syntax_type ) ) && ((((Scheme_Simple_Object * ) (c -> code ) ) -> u . ptr_int_val . pint ) == 6 ) ) {
      return (Scheme_Module * ) (((Scheme_Simple_Object * ) (c -> code ) ) -> u . ptr_int_val . ptr ) ; 
    }
  }
  return ((void * ) 0 ) ; 
}
static Scheme_Module_Exports * make_module_exports () {
  Scheme_Module_Exports * me ; 
  Scheme_Module_Phase_Exports * pt ; 
  DECL_RET_SAVE (Scheme_Module_Exports * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(me, 0), PUSH(pt, 1)));
# define XfOrM509_COUNT (2)
# define SETUP_XfOrM509(x) SETUP(XfOrM509_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  me = NULLED_OUT ; 
  pt = NULLED_OUT ; 
  me = ((Scheme_Module_Exports * ) FUNCCALL(SETUP_XfOrM509(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Module_Exports ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  me -> type = scheme_rt_module_exports ; 
  pt = ((Scheme_Module_Phase_Exports * ) FUNCCALL(SETUP_XfOrM509(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Module_Phase_Exports ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  pt -> type = scheme_rt_module_phase_exports ; 
  me -> rt = pt ; 
  pt = ((Scheme_Module_Phase_Exports * ) FUNCCALL(SETUP_XfOrM509(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Module_Phase_Exports ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  pt -> type = scheme_rt_module_phase_exports ; 
  me -> et = pt ; 
  pt = ((Scheme_Module_Phase_Exports * ) FUNCCALL(SETUP_XfOrM509(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Module_Phase_Exports ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  pt -> type = scheme_rt_module_phase_exports ; 
  me -> dt = pt ; 
  RET_VALUE_START (me ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void * eval_defmacro_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * names ; 
  int count , for_stx ; 
  Scheme_Object * expr , * certs ; 
  Scheme_Env * genv ; 
  Scheme_Comp_Env * comp_env ; 
  Resolve_Prefix * rp ; 
  int let_depth , shift ; 
  Scheme_Bucket_Table * syntax ; 
  names = (Scheme_Object * ) p -> ku . k . p1 ; 
  expr = (Scheme_Object * ) p -> ku . k . p2 ; 
  genv = (Scheme_Env * ) (((Scheme_Simple_Object * ) ((Scheme_Object * ) p -> ku . k . p3 ) ) -> u . pair_val . car ) ; 
  comp_env = (Scheme_Comp_Env * ) (((Scheme_Simple_Object * ) ((Scheme_Object * ) p -> ku . k . p3 ) ) -> u . pair_val . cdr ) ; 
  rp = (Resolve_Prefix * ) (((Scheme_Simple_Object * ) ((Scheme_Object * ) p -> ku . k . p4 ) ) -> u . pair_val . car ) ; 
  syntax = (Scheme_Bucket_Table * ) (((Scheme_Simple_Object * ) ((Scheme_Object * ) p -> ku . k . p4 ) ) -> u . pair_val . cdr ) ; 
  count = p -> ku . k . i1 ; 
  let_depth = p -> ku . k . i2 ; 
  shift = p -> ku . k . i3 ; 
  for_stx = p -> ku . k . i4 ; 
  certs = (Scheme_Object * ) p -> ku . k . p5 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  p -> ku . k . p2 = ((void * ) 0 ) ; 
  p -> ku . k . p3 = ((void * ) 0 ) ; 
  p -> ku . k . p4 = ((void * ) 0 ) ; 
  p -> ku . k . p5 = ((void * ) 0 ) ; 
  eval_defmacro (names , count , expr , genv , comp_env , rp , let_depth , shift , syntax , for_stx , certs ) ; 
  return ((void * ) 0 ) ; 
}
static void eval_defmacro (Scheme_Object * names , int count , Scheme_Object * expr , Scheme_Env * genv , Scheme_Comp_Env * comp_env , Resolve_Prefix * rp , int let_depth , int shift , Scheme_Bucket_Table * syntax , int for_stx , Scheme_Object * certs ) {
  Scheme_Object * macro , * vals , * name , * * save_runstack ; 
  int i , g , depth ; 
  PREPARE_VAR_STACK(12);
  BLOCK_SETUP_TOP((PUSH(vals, 0), PUSH(certs, 1), PUSH(save_runstack, 2), PUSH(genv, 3), PUSH(syntax, 4), PUSH(rp, 5), PUSH(name, 6), PUSH(names, 7), PUSH(expr, 8), PUSH(comp_env, 9), PUSH(macro, 10)));
# define XfOrM511_COUNT (11)
# define SETUP_XfOrM511(x) SETUP(XfOrM511_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  macro = NULLED_OUT ; 
  vals = NULLED_OUT ; 
  name = NULLED_OUT ; 
  save_runstack = NULLED_OUT ; 
  depth = let_depth + FUNCCALL(SETUP_XfOrM511(_), scheme_prefix_depth (rp ) ); 
  if (! FUNCCALL(SETUP_XfOrM511(_), scheme_check_runstack (depth ) )) {
    Scheme_Thread * p = scheme_current_thread ; 
    BLOCK_SETUP((PUSH(p, 0+XfOrM511_COUNT)));
#   define XfOrM521_COUNT (1+XfOrM511_COUNT)
#   define SETUP_XfOrM521(x) SETUP(XfOrM521_COUNT)
    p -> ku . k . p1 = names ; 
    p -> ku . k . p2 = expr ; 
    vals = FUNCCALL(SETUP_XfOrM521(_), scheme_make_pair ((Scheme_Object * ) genv , (Scheme_Object * ) comp_env ) ); 
    p -> ku . k . p3 = vals ; 
    vals = FUNCCALL(SETUP_XfOrM521(_), scheme_make_pair ((Scheme_Object * ) rp , (Scheme_Object * ) syntax ) ); 
    p -> ku . k . p4 = vals ; 
    p -> ku . k . i1 = count ; 
    p -> ku . k . i2 = let_depth ; 
    p -> ku . k . i3 = shift ; 
    p -> ku . k . i4 = for_stx ; 
    p -> ku . k . p5 = certs ; 
    (void ) FUNCCALL(SETUP_XfOrM521(_), scheme_enlarge_runstack (depth , eval_defmacro_k ) ); 
    RET_NOTHING ; 
  }
  save_runstack = FUNCCALL(SETUP_XfOrM511(_), scheme_push_prefix (genv , rp , (shift ? genv -> module -> me -> src_modidx : ((void * ) 0 ) ) , (shift ? genv -> link_midx : ((void * ) 0 ) ) , 1 , genv -> phase ) ); 
  FUNCCALL(SETUP_XfOrM511(_), scheme_on_next_top (comp_env , ((void * ) 0 ) , scheme_false , certs , genv , (genv -> link_midx ? genv -> link_midx : genv -> module -> me -> src_modidx ) ) ); 
  vals = FUNCCALL_AGAIN(scheme_eval_linked_expr_multi (expr ) ); 
  FUNCCALL_AGAIN(scheme_pop_prefix (save_runstack ) ); 
  if (((vals ) == (((Scheme_Object * ) 0x6 ) ) ) ) {
#   define XfOrM515_COUNT (0+XfOrM511_COUNT)
#   define SETUP_XfOrM515(x) SETUP_XfOrM511(x)
    g = scheme_current_thread -> ku . multiple . count ; 
    if (count == g ) {
      Scheme_Object * * values ; 
      BLOCK_SETUP((PUSH(values, 0+XfOrM515_COUNT)));
#     define XfOrM516_COUNT (1+XfOrM515_COUNT)
#     define SETUP_XfOrM516(x) SETUP(XfOrM516_COUNT)
      values = NULLED_OUT ; 
      values = scheme_current_thread -> ku . multiple . array ; 
      scheme_current_thread -> ku . multiple . array = ((void * ) 0 ) ; 
      if (((values ) == (scheme_current_thread -> values_buffer ) ) )
        scheme_current_thread -> values_buffer = ((void * ) 0 ) ; 
      for (i = 0 ; i < g ; i ++ , names = (((Scheme_Simple_Object * ) (names ) ) -> u . pair_val . cdr ) ) {
#       define XfOrM519_COUNT (0+XfOrM516_COUNT)
#       define SETUP_XfOrM519(x) SETUP_XfOrM516(x)
        name = (((Scheme_Simple_Object * ) (names ) ) -> u . pair_val . car ) ; 
        if (! for_stx ) {
#         define XfOrM520_COUNT (0+XfOrM519_COUNT)
#         define SETUP_XfOrM520(x) SETUP_XfOrM519(x)
          macro = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM520(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
          macro -> type = scheme_macro_type ; 
          (((Scheme_Small_Object * ) (macro ) ) -> u . ptr_val ) = values [i ] ; 
        }
        else macro = values [i ] ; 
        FUNCCALL(SETUP_XfOrM519(_), scheme_add_to_table (syntax , (const char * ) name , macro , 0 ) ); 
      }
      RET_NOTHING ; 
    }
  }
  else if (((Scheme_Type ) (((((long ) (names ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (names ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && (((((Scheme_Simple_Object * ) (names ) ) -> u . pair_val . cdr ) ) == (scheme_null ) ) ) {
#   define XfOrM513_COUNT (0+XfOrM511_COUNT)
#   define SETUP_XfOrM513(x) SETUP_XfOrM511(x)
    name = (((Scheme_Simple_Object * ) (names ) ) -> u . pair_val . car ) ; 
    if (! for_stx ) {
#     define XfOrM514_COUNT (0+XfOrM513_COUNT)
#     define SETUP_XfOrM514(x) SETUP_XfOrM513(x)
      macro = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM514(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
      macro -> type = scheme_macro_type ; 
      (((Scheme_Small_Object * ) (macro ) ) -> u . ptr_val ) = vals ; 
    }
    else macro = vals ; 
    FUNCCALL(SETUP_XfOrM513(_), scheme_add_to_table (syntax , (const char * ) name , macro , 0 ) ); 
    RET_NOTHING ; 
  }
  else g = 1 ; 
  if (count )
    name = (((Scheme_Simple_Object * ) (names ) ) -> u . pair_val . car ) ; 
  else name = ((void * ) 0 ) ; 
  {
    const char * symname ; 
    BLOCK_SETUP((PUSH(symname, 0+XfOrM511_COUNT)));
#   define XfOrM512_COUNT (1+XfOrM511_COUNT)
#   define SETUP_XfOrM512(x) SETUP(XfOrM512_COUNT)
    symname = NULLED_OUT ; 
    symname = (name ? FUNCCALL(SETUP_XfOrM512(_), scheme_symbol_name (name ) ): "" ) ; 
    FUNCCALL_EMPTY(scheme_wrong_return_arity ((for_stx ? "define-values-for-syntax" : "define-syntaxes" ) , count , g , (g == 1 ) ? (Scheme_Object * * ) vals : scheme_current_thread -> ku . multiple . array , "%s%s%s" , name ? "defining \"" : "0 names" , symname , name ? ((count == 1 ) ? "\"" : "\", ..." ) : "" ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * module_execute (Scheme_Object * data ) {
  Scheme_Module * m ; 
  Scheme_Env * env ; 
  Scheme_Env * old_menv ; 
  Scheme_Object * prefix , * insp ; 
  Scheme_Config * __funcarg104 = NULLED_OUT ; 
  Scheme_Config * __funcarg103 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(9);
  BLOCK_SETUP_TOP((PUSH(prefix, 0), PUSH(old_menv, 1), PUSH(env, 2), PUSH(m, 3), PUSH(insp, 4), PUSH(data, 5)));
# define XfOrM522_COUNT (6)
# define SETUP_XfOrM522(x) SETUP(XfOrM522_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  m = NULLED_OUT ; 
  env = NULLED_OUT ; 
  old_menv = NULLED_OUT ; 
  prefix = NULLED_OUT ; 
  insp = NULLED_OUT ; 
  m = ((Scheme_Module * ) FUNCCALL(SETUP_XfOrM522(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Module ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  (memcpy (m , data , sizeof (Scheme_Module ) ) ) ; 
  prefix = (__funcarg104 = FUNCCALL(SETUP_XfOrM522(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg104 , MZCONFIG_CURRENT_MODULE_PREFIX ) )) ; 
  if (((Scheme_Type ) (((((long ) (prefix ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (prefix ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
#   define XfOrM527_COUNT (0+XfOrM522_COUNT)
#   define SETUP_XfOrM527(x) SETUP_XfOrM522(x)
    prefix = FUNCCALL(SETUP_XfOrM527(_), scheme_symbol_append (prefix , m -> modname ) ); 
    m -> modname = prefix ; 
    if (m -> self_modidx ) {
#     define XfOrM528_COUNT (0+XfOrM527_COUNT)
#     define SETUP_XfOrM528(x) SETUP_XfOrM527(x)
      if (! ((Scheme_Type ) (((((long ) (m -> self_modidx ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (m -> self_modidx ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
        Scheme_Modidx * midx = (Scheme_Modidx * ) m -> self_modidx ; 
        Scheme_Object * nmidx ; 
        BLOCK_SETUP((PUSH(midx, 0+XfOrM528_COUNT), PUSH(nmidx, 1+XfOrM528_COUNT)));
#       define XfOrM529_COUNT (2+XfOrM528_COUNT)
#       define SETUP_XfOrM529(x) SETUP(XfOrM529_COUNT)
        nmidx = NULLED_OUT ; 
        nmidx = FUNCCALL(SETUP_XfOrM529(_), scheme_make_modidx (midx -> path , midx -> base , m -> modname ) ); 
        m -> self_modidx = nmidx ; 
        if (m -> rn_stx && ! ((scheme_true ) == (m -> rn_stx ) ) ) {
          Scheme_Object * v ; 
          BLOCK_SETUP((PUSH(v, 0+XfOrM529_COUNT)));
#         define XfOrM532_COUNT (1+XfOrM529_COUNT)
#         define SETUP_XfOrM532(x) SETUP(XfOrM532_COUNT)
          v = NULLED_OUT ; 
          v = FUNCCALL(SETUP_XfOrM532(_), scheme_make_pair (m -> rn_stx , (Scheme_Object * ) midx ) ); 
          m -> rn_stx = v ; 
        }
        if (m -> et_rn_stx && ! ((scheme_true ) == (m -> et_rn_stx ) ) ) {
          Scheme_Object * v ; 
          BLOCK_SETUP((PUSH(v, 0+XfOrM529_COUNT)));
#         define XfOrM531_COUNT (1+XfOrM529_COUNT)
#         define SETUP_XfOrM531(x) SETUP(XfOrM531_COUNT)
          v = NULLED_OUT ; 
          v = FUNCCALL(SETUP_XfOrM531(_), scheme_make_pair (m -> et_rn_stx , (Scheme_Object * ) midx ) ); 
          m -> et_rn_stx = v ; 
        }
        if (m -> dt_rn_stx && ! ((scheme_true ) == (m -> dt_rn_stx ) ) ) {
          Scheme_Object * v ; 
          BLOCK_SETUP((PUSH(v, 0+XfOrM529_COUNT)));
#         define XfOrM530_COUNT (1+XfOrM529_COUNT)
#         define SETUP_XfOrM530(x) SETUP(XfOrM530_COUNT)
          v = NULLED_OUT ; 
          v = FUNCCALL(SETUP_XfOrM530(_), scheme_make_pair (m -> dt_rn_stx , (Scheme_Object * ) midx ) ); 
          m -> dt_rn_stx = v ; 
        }
      }
    }
  }
  env = FUNCCALL(SETUP_XfOrM522(_), scheme_environment_from_dummy (m -> dummy ) ); 
  if (((m -> modname ) == (kernel_symbol ) ) )
    old_menv = scheme_initial_env ; 
  else old_menv = (Scheme_Env * ) FUNCCALL(SETUP_XfOrM522(_), scheme_hash_get (((Scheme_Hash_Table * ) ((((Scheme_Vector * ) (env -> modchain ) ) -> els ) [0 ] ) ) , m -> modname ) ); 
  insp = (__funcarg103 = FUNCCALL(SETUP_XfOrM522(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg103 , MZCONFIG_CODE_INSPECTOR ) )) ; 
  if (old_menv ) {
#   define XfOrM525_COUNT (0+XfOrM522_COUNT)
#   define SETUP_XfOrM525(x) SETUP_XfOrM522(x)
    if (FUNCCALL(SETUP_XfOrM525(_), scheme_module_protected_wrt (old_menv -> insp , insp ) )|| old_menv -> attached ) {
#     define XfOrM526_COUNT (0+XfOrM525_COUNT)
#     define SETUP_XfOrM526(x) SETUP_XfOrM525(x)
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "module->namespace: current code inspector cannot re-declare module: %S" , m -> modname ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  m -> insp = insp ; 
  FUNCCALL(SETUP_XfOrM522(_), scheme_hash_set (env -> module_registry , m -> modname , (Scheme_Object * ) m ) ); 
  FUNCCALL_AGAIN(scheme_hash_set (env -> export_registry , m -> modname , (Scheme_Object * ) m -> me ) ); 
  if (scheme_starting_up ) {
    m -> functional = 1 ; 
    m -> et_functional = 1 ; 
    m -> tt_functional = 1 ; 
  }
  if (old_menv ) {
#   define XfOrM523_COUNT (0+XfOrM522_COUNT)
#   define SETUP_XfOrM523(x) SETUP_XfOrM522(x)
    if (old_menv -> running > 0 )
      FUNCCALL(SETUP_XfOrM523(_), start_module (m , env , 1 , ((void * ) 0 ) , 1 , 0 , scheme_null ) ); 
    else FUNCCALL_EMPTY(expstart_module (m , env , 1 , ((void * ) 0 ) , 1 , 1 , scheme_null ) ); 
  }
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * rebuild_et_vec (Scheme_Object * naya , Scheme_Object * vec ) {
  Scheme_Object * vec2 ; 
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(naya, 0), PUSH(vec, 1), PUSH(vec2, 2)));
# define XfOrM533_COUNT (3)
# define SETUP_XfOrM533(x) SETUP(XfOrM533_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  vec2 = NULLED_OUT ; 
  i = (((Scheme_Vector * ) (vec ) ) -> size ) ; 
  vec2 = FUNCCALL(SETUP_XfOrM533(_), scheme_make_vector (i , ((void * ) 0 ) ) ); 
  while (i -- ) {
    (((Scheme_Vector * ) (vec2 ) ) -> els ) [i ] = (((Scheme_Vector * ) (vec ) ) -> els ) [i ] ; 
  }
  (((Scheme_Vector * ) (vec2 ) ) -> els ) [1 ] = naya ; 
  RET_VALUE_START (vec2 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * jit_list (Scheme_Object * orig_l , int in_vec ) {
  Scheme_Object * l , * orig , * naya = ((void * ) 0 ) ; 
  int saw ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(naya, 0), PUSH(orig_l, 1), PUSH(l, 2), PUSH(orig, 3)));
# define XfOrM536_COUNT (4)
# define SETUP_XfOrM536(x) SETUP(XfOrM536_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  l = NULLED_OUT ; 
  orig = NULLED_OUT ; 
  for (l = orig_l , saw = 0 ; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) , saw ++ ) {
#   define XfOrM545_COUNT (0+XfOrM536_COUNT)
#   define SETUP_XfOrM545(x) SETUP_XfOrM536(x)
    orig = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
    if (in_vec )
      orig = (((Scheme_Vector * ) (orig ) ) -> els ) [1 ] ; 
    naya = FUNCCALL(SETUP_XfOrM545(_), scheme_jit_expr (orig ) ); 
    if (! ((orig ) == (naya ) ) )
      break ; 
  }
  if (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
    Scheme_Object * first = scheme_null , * last = ((void * ) 0 ) , * pr ; 
    BLOCK_SETUP((PUSH(pr, 0+XfOrM536_COUNT), PUSH(first, 1+XfOrM536_COUNT), PUSH(last, 2+XfOrM536_COUNT)));
#   define XfOrM537_COUNT (3+XfOrM536_COUNT)
#   define SETUP_XfOrM537(x) SETUP(XfOrM537_COUNT)
    pr = NULLED_OUT ; 
    for (l = orig_l ; saw -- ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#     define XfOrM543_COUNT (0+XfOrM537_COUNT)
#     define SETUP_XfOrM543(x) SETUP_XfOrM537(x)
      orig = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
      pr = FUNCCALL(SETUP_XfOrM543(_), scheme_make_pair (orig , scheme_null ) ); 
      if (last )
        (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = pr ; 
      else first = pr ; 
      last = pr ; 
    }
    if (in_vec )
      naya = FUNCCALL(SETUP_XfOrM537(_), rebuild_et_vec (naya , (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ) ); 
    pr = FUNCCALL(SETUP_XfOrM537(_), scheme_make_pair (naya , scheme_null ) ); 
    if (last )
      (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = pr ; 
    else first = pr ; 
    last = pr ; 
    l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
    for (; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#     define XfOrM540_COUNT (0+XfOrM537_COUNT)
#     define SETUP_XfOrM540(x) SETUP_XfOrM537(x)
      orig = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
      if (in_vec )
        orig = (((Scheme_Vector * ) (orig ) ) -> els ) [1 ] ; 
      naya = FUNCCALL(SETUP_XfOrM540(_), scheme_jit_expr (orig ) ); 
      if (in_vec ) {
#       define XfOrM541_COUNT (0+XfOrM540_COUNT)
#       define SETUP_XfOrM541(x) SETUP_XfOrM540(x)
        if (! ((orig ) == (naya ) ) )
          naya = FUNCCALL(SETUP_XfOrM541(_), rebuild_et_vec (naya , (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ) ); 
        else naya = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
      }
      pr = FUNCCALL(SETUP_XfOrM540(_), scheme_make_pair (naya , scheme_null ) ); 
      (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = pr ; 
      last = pr ; 
    }
    RET_VALUE_START (first ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (orig_l ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * module_jit (Scheme_Object * data ) {
  Scheme_Module * m = (Scheme_Module * ) data ; 
  Scheme_Object * l1 , * l2 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(m, 0), PUSH(l1, 1), PUSH(l2, 2), PUSH(data, 3)));
# define XfOrM546_COUNT (4)
# define SETUP_XfOrM546(x) SETUP(XfOrM546_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  l1 = NULLED_OUT ; 
  l2 = NULLED_OUT ; 
  l1 = FUNCCALL(SETUP_XfOrM546(_), jit_list (m -> body , 0 ) ); 
  l2 = FUNCCALL_AGAIN(jit_list (m -> et_body , 1 ) ); 
  if (((l1 ) == (m -> body ) ) && ((l2 ) == (m -> body ) ) )
    RET_VALUE_START (data ) RET_VALUE_END ; 
  m = ((Scheme_Module * ) FUNCCALL(SETUP_XfOrM546(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Module ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  (memcpy (m , data , sizeof (Scheme_Module ) ) ) ; 
  m -> body = l1 ; 
  m -> et_body = l2 ; 
  RET_VALUE_START ((Scheme_Object * ) m ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void module_validate (Scheme_Object * data , Mz_CPort * port , char * stack , Scheme_Hash_Table * ht , Scheme_Object * * tls , int depth , int letlimit , int delta , int num_toplevels , int num_stxes , int num_lifts ) {
  Scheme_Module * m ; 
  Scheme_Object * l ; 
  PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(port, 0), PUSH(ht, 1), PUSH(m, 2), PUSH(l, 3), PUSH(data, 4)));
# define XfOrM547_COUNT (5)
# define SETUP_XfOrM547(x) SETUP(XfOrM547_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  m = NULLED_OUT ; 
  l = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (data ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (data ) ) -> type ) ) == (Scheme_Type ) (scheme_module_type ) ) )
    FUNCCALL(SETUP_XfOrM547(_), scheme_ill_formed (port , "./../src/module.c" , 3620 ) ); 
  m = (Scheme_Module * ) data ; 
  if (! ((Scheme_Type ) (((((long ) (m -> modname ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (m -> modname ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
    FUNCCALL(SETUP_XfOrM547(_), scheme_ill_formed (port , "./../src/module.c" , 3625 ) ); 
  for (l = m -> body ; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#   define XfOrM549_COUNT (0+XfOrM547_COUNT)
#   define SETUP_XfOrM549(x) SETUP_XfOrM547(x)
    FUNCCALL(SETUP_XfOrM549(_), scheme_validate_code (port , (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) , ht , m -> max_let_depth , m -> prefix -> num_toplevels , m -> prefix -> num_stxes , m -> prefix -> num_lifts ) ); 
  }
  if (! ((l ) == (scheme_null ) ) )
    FUNCCALL_EMPTY(scheme_ill_formed (port , "./../src/module.c" , 3632 ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int set_code_closure_flags (Scheme_Object * clones , int set_flags , int mask_flags ) {
  /* No conversion */
  Scheme_Object * clone , * orig , * first ; 
  Scheme_Closure_Data * data ; 
  int flags = 32 | 4 ; 
  while (clones ) {
    first = (((Scheme_Simple_Object * ) (clones ) ) -> u . pair_val . car ) ; 
    clone = (((Scheme_Simple_Object * ) (first ) ) -> u . pair_val . car ) ; 
    orig = (((Scheme_Simple_Object * ) (first ) ) -> u . pair_val . cdr ) ; 
    data = (Scheme_Closure_Data * ) orig ; 
    flags = (flags & (& (data ) -> iso ) -> so . keyex ) ; 
    (& (data ) -> iso ) -> so . keyex = set_flags | ((& (data ) -> iso ) -> so . keyex & mask_flags ) ; 
    data = (Scheme_Closure_Data * ) clone ; 
    (& (data ) -> iso ) -> so . keyex = set_flags | ((& (data ) -> iso ) -> so . keyex & mask_flags ) ; 
    clones = (((Scheme_Simple_Object * ) (clones ) ) -> u . pair_val . cdr ) ; 
  }
  return flags ; 
}
static Scheme_Object * module_optimize (Scheme_Object * data , Optimize_Info * info ) {
  Scheme_Module * m = (Scheme_Module * ) data ; 
  Scheme_Object * e , * b , * vars , * start_simltaneous_b ; 
  Scheme_Object * cl_first = ((void * ) 0 ) , * cl_last = ((void * ) 0 ) ; 
  Scheme_Hash_Table * consts = ((void * ) 0 ) , * ready_table = ((void * ) 0 ) ; 
  int cont ; 
  Scheme_Object * __funcarg106 = NULLED_OUT ; 
  PREPARE_VAR_STACK(14);
  BLOCK_SETUP_TOP((PUSH(b, 0), PUSH(e, 1), PUSH(ready_table, 2), PUSH(data, 3), PUSH(cl_first, 4), PUSH(consts, 5), PUSH(m, 6), PUSH(info, 7), PUSH(vars, 8), PUSH(start_simltaneous_b, 9), PUSH(cl_last, 10)));
# define XfOrM553_COUNT (11)
# define SETUP_XfOrM553(x) SETUP(XfOrM553_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  e = NULLED_OUT ; 
  b = NULLED_OUT ; 
  vars = NULLED_OUT ; 
  start_simltaneous_b = NULLED_OUT ; 
  start_simltaneous_b = m -> body ; 
  for (b = m -> body ; ! ((b ) == (scheme_null ) ) ; b = (((Scheme_Simple_Object * ) (b ) ) -> u . pair_val . cdr ) ) {
#   define XfOrM583_COUNT (0+XfOrM553_COUNT)
#   define SETUP_XfOrM583(x) SETUP_XfOrM553(x)
    e = FUNCCALL(SETUP_XfOrM583(_), scheme_optimize_expr ((((Scheme_Simple_Object * ) (b ) ) -> u . pair_val . car ) , info ) ); 
    (((Scheme_Simple_Object * ) (b ) ) -> u . pair_val . car ) = e ; 
    if (info -> enforce_const ) {
#     define XfOrM594_COUNT (0+XfOrM583_COUNT)
#     define SETUP_XfOrM594(x) SETUP_XfOrM583(x)
      if (((Scheme_Type ) (((((long ) (e ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e ) ) -> type ) ) == (Scheme_Type ) (scheme_compiled_syntax_type ) ) && ((((Scheme_Simple_Object * ) (e ) ) -> u . ptr_int_val . pint ) == 0 ) ) {
        int n ; 
#       define XfOrM596_COUNT (0+XfOrM594_COUNT)
#       define SETUP_XfOrM596(x) SETUP_XfOrM594(x)
        e = (Scheme_Object * ) (((Scheme_Simple_Object * ) (e ) ) -> u . ptr_int_val . ptr ) ; 
        vars = (((Scheme_Simple_Object * ) (e ) ) -> u . pair_val . car ) ; 
        e = (((Scheme_Simple_Object * ) (e ) ) -> u . pair_val . cdr ) ; 
        n = FUNCCALL(SETUP_XfOrM596(_), scheme_list_length (vars ) ); 
        cont = FUNCCALL_AGAIN(scheme_omittable_expr (e , n ) ); 
        if ((n == 1 ) && FUNCCALL(SETUP_XfOrM596(_), scheme_compiled_propagate_ok (e , info ) )) {
          Scheme_Toplevel * tl ; 
          BLOCK_SETUP((PUSH(tl, 0+XfOrM596_COUNT)));
#         define XfOrM604_COUNT (1+XfOrM596_COUNT)
#         define SETUP_XfOrM604(x) SETUP(XfOrM604_COUNT)
          tl = NULLED_OUT ; 
          tl = (Scheme_Toplevel * ) (((Scheme_Simple_Object * ) (vars ) ) -> u . pair_val . car ) ; 
          if (! ((& ((Scheme_Toplevel * ) (tl ) ) -> iso ) -> so . keyex & 0x2 ) ) {
            Scheme_Object * e2 ; 
            BLOCK_SETUP((PUSH(e2, 0+XfOrM604_COUNT)));
#           define XfOrM605_COUNT (1+XfOrM604_COUNT)
#           define SETUP_XfOrM605(x) SETUP(XfOrM605_COUNT)
            e2 = NULLED_OUT ; 
            if (((Scheme_Type ) (((((long ) (e ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e ) ) -> type ) ) == (Scheme_Type ) (scheme_compiled_unclosed_procedure_type ) ) ) {
#             define XfOrM610_COUNT (0+XfOrM605_COUNT)
#             define SETUP_XfOrM610(x) SETUP_XfOrM605(x)
              e2 = FUNCCALL(SETUP_XfOrM610(_), scheme_optimize_clone (1 , e , info , 0 , 0 ) ); 
              if (e2 ) {
                Scheme_Object * pr ; 
                BLOCK_SETUP((PUSH(pr, 0+XfOrM610_COUNT)));
#               define XfOrM611_COUNT (1+XfOrM610_COUNT)
#               define SETUP_XfOrM611(x) SETUP(XfOrM611_COUNT)
                pr = NULLED_OUT ; 
                pr = (__funcarg106 = FUNCCALL(SETUP_XfOrM611(_), scheme_make_raw_pair (e2 , e ) ), FUNCCALL_AGAIN(scheme_make_raw_pair (__funcarg106 , ((void * ) 0 ) ) )) ; 
                if (cl_last )
                  (((Scheme_Simple_Object * ) (cl_last ) ) -> u . pair_val . cdr ) = pr ; 
                else cl_first = pr ; 
                cl_last = pr ; 
              }
            }
            else {
              e2 = e ; 
            }
            if (e2 ) {
              int pos ; 
#             define XfOrM608_COUNT (0+XfOrM605_COUNT)
#             define SETUP_XfOrM608(x) SETUP_XfOrM605(x)
              if (! consts )
                consts = FUNCCALL(SETUP_XfOrM608(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
              pos = tl -> position ; 
              FUNCCALL(SETUP_XfOrM608(_), scheme_hash_set (consts , ((Scheme_Object * ) (void * ) (long ) ((((long ) (pos ) ) << 1 ) | 0x1 ) ) , e2 ) ); 
            }
            else {
#             define XfOrM606_COUNT (0+XfOrM605_COUNT)
#             define SETUP_XfOrM606(x) SETUP_XfOrM605(x)
              if (! ready_table ) {
#               define XfOrM607_COUNT (0+XfOrM606_COUNT)
#               define SETUP_XfOrM607(x) SETUP_XfOrM606(x)
                ready_table = FUNCCALL(SETUP_XfOrM607(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
                if (! consts )
                  consts = FUNCCALL(SETUP_XfOrM607(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
                FUNCCALL(SETUP_XfOrM607(_), scheme_hash_set (consts , scheme_false , (Scheme_Object * ) ready_table ) ); 
              }
              FUNCCALL(SETUP_XfOrM606(_), scheme_hash_set (ready_table , ((Scheme_Object * ) (void * ) (long ) ((((long ) (tl -> position ) ) << 1 ) | 0x1 ) ) , scheme_true ) ); 
            }
          }
        }
        else {
          Scheme_Object * l , * a ; 
          int pos ; 
          BLOCK_SETUP((PUSH(a, 0+XfOrM596_COUNT), PUSH(l, 1+XfOrM596_COUNT)));
#         define XfOrM597_COUNT (2+XfOrM596_COUNT)
#         define SETUP_XfOrM597(x) SETUP(XfOrM597_COUNT)
          l = NULLED_OUT ; 
          a = NULLED_OUT ; 
          for (l = vars ; ! ((l ) == (scheme_null ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#           define XfOrM601_COUNT (0+XfOrM597_COUNT)
#           define SETUP_XfOrM601(x) SETUP_XfOrM597(x)
            a = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
            if (! ((& ((Scheme_Toplevel * ) (a ) ) -> iso ) -> so . keyex & 0x2 ) ) {
#             define XfOrM602_COUNT (0+XfOrM601_COUNT)
#             define SETUP_XfOrM602(x) SETUP_XfOrM601(x)
              pos = (((Scheme_Toplevel * ) (a ) ) -> position ) ; 
              if (! ready_table ) {
#               define XfOrM603_COUNT (0+XfOrM602_COUNT)
#               define SETUP_XfOrM603(x) SETUP_XfOrM602(x)
                ready_table = FUNCCALL(SETUP_XfOrM603(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
                if (! consts )
                  consts = FUNCCALL(SETUP_XfOrM603(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
                FUNCCALL(SETUP_XfOrM603(_), scheme_hash_set (consts , scheme_false , (Scheme_Object * ) ready_table ) ); 
              }
              FUNCCALL(SETUP_XfOrM602(_), scheme_hash_set (ready_table , ((Scheme_Object * ) (void * ) (long ) ((((long ) (pos ) ) << 1 ) | 0x1 ) ) , scheme_true ) ); 
            }
          }
        }
      }
      else {
#       define XfOrM595_COUNT (0+XfOrM594_COUNT)
#       define SETUP_XfOrM595(x) SETUP_XfOrM594(x)
        cont = FUNCCALL(SETUP_XfOrM595(_), scheme_omittable_expr (e , 1 ) ); 
      }
      if ((((((Scheme_Simple_Object * ) (b ) ) -> u . pair_val . cdr ) ) == (scheme_null ) ) )
        cont = 0 ; 
    }
    else cont = 1 ; 
    if (! cont ) {
#     define XfOrM584_COUNT (0+XfOrM583_COUNT)
#     define SETUP_XfOrM584(x) SETUP_XfOrM583(x)
      if (consts ) {
        int flags ; 
#       define XfOrM585_COUNT (0+XfOrM584_COUNT)
#       define SETUP_XfOrM585(x) SETUP_XfOrM584(x)
        if (! info -> top_level_consts ) {
          info -> top_level_consts = consts ; 
        }
        else {
          int i ; 
#         define XfOrM588_COUNT (0+XfOrM585_COUNT)
#         define SETUP_XfOrM588(x) SETUP_XfOrM585(x)
          for (i = 0 ; i < consts -> size ; i ++ ) {
#           define XfOrM591_COUNT (0+XfOrM588_COUNT)
#           define SETUP_XfOrM591(x) SETUP_XfOrM588(x)
            if (consts -> vals [i ] ) {
#             define XfOrM592_COUNT (0+XfOrM591_COUNT)
#             define SETUP_XfOrM592(x) SETUP_XfOrM591(x)
              FUNCCALL(SETUP_XfOrM592(_), scheme_hash_set (info -> top_level_consts , consts -> keys [i ] , consts -> vals [i ] ) ); 
            }
          }
        }
        (void ) FUNCCALL(SETUP_XfOrM585(_), set_code_closure_flags (cl_first , 32 | 4 | 64 , 0xFFFF ) ); 
        while (1 ) {
#         define XfOrM587_COUNT (0+XfOrM585_COUNT)
#         define SETUP_XfOrM587(x) SETUP_XfOrM585(x)
          e = FUNCCALL(SETUP_XfOrM587(_), scheme_optimize_expr ((((Scheme_Simple_Object * ) (start_simltaneous_b ) ) -> u . pair_val . car ) , info ) ); 
          (((Scheme_Simple_Object * ) (start_simltaneous_b ) ) -> u . pair_val . car ) = e ; 
          if (((start_simltaneous_b ) == (b ) ) )
            break ; 
          start_simltaneous_b = (((Scheme_Simple_Object * ) (start_simltaneous_b ) ) -> u . pair_val . cdr ) ; 
        }
        flags = FUNCCALL(SETUP_XfOrM585(_), set_code_closure_flags (cl_first , 0 , 0xFFFF ) ); 
        (void ) FUNCCALL(SETUP_XfOrM585(_), set_code_closure_flags (cl_first , (flags & (32 | 4 ) ) , ~ (32 | 4 | 64 ) ) ); 
      }
      cl_last = cl_first = ((void * ) 0 ) ; 
      consts = ((void * ) 0 ) ; 
      start_simltaneous_b = (((Scheme_Simple_Object * ) (b ) ) -> u . pair_val . cdr ) ; 
    }
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_syntax_compiled (6 , data ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * module_resolve (Scheme_Object * data , Resolve_Info * old_rslv ) {
  Scheme_Module * m = (Scheme_Module * ) data ; 
  Scheme_Object * b , * lift_vec ; 
  Resolve_Prefix * rp ; 
  Resolve_Info * rslv ; 
  PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(old_rslv, 0), PUSH(m, 1), PUSH(rslv, 2), PUSH(b, 3), PUSH(rp, 4), PUSH(lift_vec, 5), PUSH(data, 6)));
# define XfOrM612_COUNT (7)
# define SETUP_XfOrM612(x) SETUP(XfOrM612_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  b = NULLED_OUT ; 
  lift_vec = NULLED_OUT ; 
  rp = NULLED_OUT ; 
  rslv = NULLED_OUT ; 
  rp = FUNCCALL(SETUP_XfOrM612(_), scheme_resolve_prefix (0 , m -> comp_prefix , 1 ) ); 
  m -> comp_prefix = ((void * ) 0 ) ; 
  b = FUNCCALL(SETUP_XfOrM612(_), scheme_resolve_expr (m -> dummy , old_rslv ) ); 
  m -> dummy = b ; 
  rslv = FUNCCALL(SETUP_XfOrM612(_), scheme_resolve_info_create (rp ) ); 
  rslv -> enforce_const = old_rslv -> enforce_const ; 
  rslv -> in_module = 1 ; 
  FUNCCALL(SETUP_XfOrM612(_), scheme_enable_expression_resolve_lifts (rslv ) ); 
  for (b = m -> body ; ! ((b ) == (scheme_null ) ) ; b = (((Scheme_Simple_Object * ) (b ) ) -> u . pair_val . cdr ) ) {
    Scheme_Object * e ; 
    BLOCK_SETUP((PUSH(e, 0+XfOrM612_COUNT)));
#   define XfOrM614_COUNT (1+XfOrM612_COUNT)
#   define SETUP_XfOrM614(x) SETUP(XfOrM614_COUNT)
    e = NULLED_OUT ; 
    e = FUNCCALL(SETUP_XfOrM614(_), scheme_resolve_expr ((((Scheme_Simple_Object * ) (b ) ) -> u . pair_val . car ) , rslv ) ); 
    (((Scheme_Simple_Object * ) (b ) ) -> u . pair_val . car ) = e ; 
  }
  m -> max_let_depth = rslv -> max_let_depth ; 
  lift_vec = rslv -> lifts ; 
  b = FUNCCALL(SETUP_XfOrM612(_), scheme_append ((((Scheme_Vector * ) (lift_vec ) ) -> els ) [0 ] , m -> body ) ); 
  m -> body = b ; 
  rp -> num_lifts = (((long ) ((((Scheme_Vector * ) (lift_vec ) ) -> els ) [1 ] ) ) >> 1 ) ; 
  rp = FUNCCALL(SETUP_XfOrM612(_), scheme_remap_prefix (rp , rslv ) ); 
  m -> prefix = rp ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_syntax_resolved (6 , data ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_module (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Expand_Info * rec , int drec ) {
  Scheme_Object * fm , * nm , * ii , * rn , * et_rn , * tt_rn , * dt_rn , * iidx , * self_modidx ; 
  Scheme_Module * iim ; 
  Scheme_Env * menv ; 
  Scheme_Comp_Env * benv ; 
  Scheme_Module * m ; 
  Scheme_Object * mbval ; 
  Scheme_Hash_Table * mn_ht , * et_mn_ht , * tt_mn_ht , * dt_mn_ht ; 
  int saw_mb , check_mb = 0 ; 
  int restore_confusing_name = 0 ; 
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
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(23);
  BLOCK_SETUP_TOP((PUSH(m, 0), PUSH(dt_rn, 1), PUSH(rn, 2), PUSH(dt_mn_ht, 3), PUSH(self_modidx, 4), PUSH(fm, 5), PUSH(nm, 6), PUSH(iim, 7), PUSH(mn_ht, 8), PUSH(tt_mn_ht, 9), PUSH(menv, 10), PUSH(mbval, 11), PUSH(et_rn, 12), PUSH(iidx, 13), PUSH(env, 14), PUSH(ii, 15), PUSH(et_mn_ht, 16), PUSH(form, 17), PUSH(rec, 18), PUSH(benv, 19), PUSH(tt_rn, 20)));
# define XfOrM615_COUNT (21)
# define SETUP_XfOrM615(x) SETUP(XfOrM615_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  fm = NULLED_OUT ; 
  nm = NULLED_OUT ; 
  ii = NULLED_OUT ; 
  rn = NULLED_OUT ; 
  et_rn = NULLED_OUT ; 
  tt_rn = NULLED_OUT ; 
  dt_rn = NULLED_OUT ; 
  iidx = NULLED_OUT ; 
  self_modidx = NULLED_OUT ; 
  iim = NULLED_OUT ; 
  menv = NULLED_OUT ; 
  benv = NULLED_OUT ; 
  m = NULLED_OUT ; 
  mbval = NULLED_OUT ; 
  mn_ht = NULLED_OUT ; 
  et_mn_ht = NULLED_OUT ; 
  tt_mn_ht = NULLED_OUT ; 
  dt_mn_ht = NULLED_OUT ; 
  if (! FUNCCALL(SETUP_XfOrM615(_), scheme_is_toplevel (env ) ))
    FUNCCALL(SETUP_XfOrM615(_), scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , form , "illegal use (not at top-level)" ) ); 
  fm = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM615(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  if (! (((Scheme_Type ) (((((long ) (fm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fm ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (fm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fm ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) fm ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) fm ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
    FUNCCALL(SETUP_XfOrM615(_), scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , form , ((void * ) 0 ) ) ); 
  nm = (((Scheme_Type ) (((((long ) (fm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fm ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (fm ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM615(_), scheme_stx_content (fm ) )) ) -> u . pair_val . car ) ) ; 
  if (! (((Scheme_Type ) (((((long ) (nm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (nm ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (nm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (nm ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) nm ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) nm ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) )
    FUNCCALL(SETUP_XfOrM615(_), scheme_wrong_syntax (((void * ) 0 ) , nm , form , "module name is not an identifier" ) ); 
  fm = (((Scheme_Type ) (((((long ) (fm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fm ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (fm ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM615(_), scheme_stx_content (fm ) )) ) -> u . pair_val . cdr ) ) ; 
  if (! (((Scheme_Type ) (((((long ) (fm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fm ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (fm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fm ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) fm ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) fm ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
    FUNCCALL(SETUP_XfOrM615(_), scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , form , ((void * ) 0 ) ) ); 
  ii = (((Scheme_Type ) (((((long ) (fm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fm ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (fm ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM615(_), scheme_stx_content (fm ) )) ) -> u . pair_val . car ) ) ; 
  fm = (((Scheme_Type ) (((((long ) (fm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fm ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (fm ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM615(_), scheme_stx_content (fm ) )) ) -> u . pair_val . cdr ) ) ; 
  m = ((Scheme_Module * ) FUNCCALL(SETUP_XfOrM615(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Module ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  m -> so . type = scheme_module_type ; 
  m -> modname = ((Scheme_Stx * ) nm ) -> val ; 
  if (((m -> modname ) == (kernel_symbol ) ) ) {
    Scheme_Object * k2 ; 
    BLOCK_SETUP((PUSH(k2, 0+XfOrM615_COUNT)));
#   define XfOrM635_COUNT (1+XfOrM615_COUNT)
#   define SETUP_XfOrM635(x) SETUP(XfOrM635_COUNT)
    k2 = NULLED_OUT ; 
    k2 = FUNCCALL(SETUP_XfOrM635(_), scheme_make_symbol ("#%kernel" ) ); 
    m -> modname = k2 ; 
    restore_confusing_name = 1 ; 
  }
  {
    Scheme_Module_Exports * me ; 
    BLOCK_SETUP((PUSH(me, 0+XfOrM615_COUNT)));
#   define XfOrM634_COUNT (1+XfOrM615_COUNT)
#   define SETUP_XfOrM634(x) SETUP(XfOrM634_COUNT)
    me = NULLED_OUT ; 
    me = FUNCCALL(SETUP_XfOrM634(_), make_module_exports () ); 
    m -> me = me ; 
  }
  menv = FUNCCALL(SETUP_XfOrM615(_), scheme_new_module_env (env -> genv , m , 1 ) ); 
  self_modidx = FUNCCALL(SETUP_XfOrM615(_), scheme_make_modidx (scheme_false , scheme_false , m -> modname ) ); 
  m -> self_modidx = self_modidx ; 
  m -> me -> src_modidx = self_modidx ; 
  m -> insp = env -> insp ; 
  m -> ii_src = ii ; 
  iidx = (__funcarg121 = FUNCCALL(SETUP_XfOrM615(_), scheme_syntax_to_datum (ii , 0 , ((void * ) 0 ) ) ), FUNCCALL_AGAIN(scheme_make_modidx (__funcarg121 , self_modidx , scheme_false ) )) ; 
  iim = (__funcarg120 = FUNCCALL(SETUP_XfOrM615(_), _module_resolve (iidx , ii , 1 ) ), FUNCCALL_AGAIN(module_load (__funcarg120 , menv , ((void * ) 0 ) ) )) ; 
  FUNCCALL_AGAIN(expstart_module (iim , menv , 0 , iidx , 0 , 0 , scheme_null ) ); 
  {
    Scheme_Object * ins ; 
    BLOCK_SETUP((PUSH(ins, 0+XfOrM615_COUNT)));
#   define XfOrM633_COUNT (1+XfOrM615_COUNT)
#   define SETUP_XfOrM633(x) SETUP(XfOrM633_COUNT)
    ins = NULLED_OUT ; 
    ins = FUNCCALL(SETUP_XfOrM633(_), scheme_make_pair (iidx , scheme_null ) ); 
    m -> requires = ins ; 
    m -> et_requires = scheme_null ; 
    m -> tt_requires = scheme_null ; 
    m -> dt_requires = scheme_null ; 
  }
  mn_ht = FUNCCALL(SETUP_XfOrM615(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  et_mn_ht = FUNCCALL(SETUP_XfOrM615(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  tt_mn_ht = FUNCCALL_AGAIN(scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  dt_mn_ht = mn_ht ; 
  FUNCCALL(SETUP_XfOrM615(_), annote_marked_names_nonempty (mn_ht ) ); 
  FUNCCALL_AGAIN(annote_marked_names_nonempty (et_mn_ht ) ); 
  FUNCCALL_AGAIN(annote_marked_names_nonempty (tt_mn_ht ) ); 
  rn = FUNCCALL_AGAIN(scheme_make_module_rename (0 , 1 , mn_ht ) ); 
  et_rn = FUNCCALL_AGAIN(scheme_make_module_rename (1 , 1 , et_mn_ht ) ); 
  tt_rn = FUNCCALL_AGAIN(scheme_make_module_rename (- 1 , 1 , tt_mn_ht ) ); 
  dt_rn = FUNCCALL_AGAIN(scheme_make_module_rename (30000 , 1 , dt_mn_ht ) ); 
  menv -> rename = rn ; 
  menv -> et_rename = et_rn ; 
  menv -> tt_rename = tt_rn ; 
  menv -> dt_rename = dt_rn ; 
  {
    Scheme_Object * insp ; 
    BLOCK_SETUP((PUSH(insp, 0+XfOrM615_COUNT)));
#   define XfOrM632_COUNT (1+XfOrM615_COUNT)
#   define SETUP_XfOrM632(x) SETUP(XfOrM632_COUNT)
    insp = NULLED_OUT ; 
    insp = FUNCCALL(SETUP_XfOrM632(_), scheme_make_inspector (env -> insp ) ); 
    menv -> insp = insp ; 
  }
  menv -> marked_names = mn_ht ; 
  FUNCCALL(SETUP_XfOrM615(_), scheme_prepare_exp_env (menv ) ); 
  menv -> exp_env -> marked_names = et_mn_ht ; 
  FUNCCALL(SETUP_XfOrM615(_), scheme_prepare_template_env (menv ) ); 
  menv -> template_env -> marked_names = tt_mn_ht ; 
  if (((iim ) == (kernel ) ) ) {
#   define XfOrM631_COUNT (0+XfOrM615_COUNT)
#   define SETUP_XfOrM631(x) SETUP_XfOrM615(x)
    FUNCCALL(SETUP_XfOrM631(_), scheme_extend_module_rename_with_kernel (rn , kernel_symbol ) ); 
    saw_mb = 1 ; 
  }
  else {
#   define XfOrM630_COUNT (0+XfOrM615_COUNT)
#   define SETUP_XfOrM630(x) SETUP_XfOrM615(x)
    saw_mb = FUNCCALL(SETUP_XfOrM630(_), add_require_renames (rn , et_rn , dt_rn , iim , iidx ) ); 
  }
  if (rec [drec ] . comp )
    benv = FUNCCALL(SETUP_XfOrM615(_), scheme_new_comp_env (menv , env -> insp , 2 ) ); 
  else benv = FUNCCALL(SETUP_XfOrM615(_), scheme_new_expand_env (menv , env -> insp , 2 ) ); 
  if ((((Scheme_Type ) (((((long ) (fm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fm ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (fm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fm ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) fm ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) fm ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) && ((((((Scheme_Type ) (((((long ) (fm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fm ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (fm ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM615(_), scheme_stx_content (fm ) )) ) -> u . pair_val . cdr ) ) ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) ((((Scheme_Type ) (((((long ) (fm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fm ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (fm ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM615(_), scheme_stx_content (fm ) )) ) -> u . pair_val . cdr ) ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Type ) (((((long ) (fm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fm ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (fm ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM615(_), scheme_stx_content (fm ) )) ) -> u . pair_val . cdr ) ) ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (fm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fm ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (fm ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM615(_), scheme_stx_content (fm ) )) ) -> u . pair_val . cdr ) ) ) -> val ) == (scheme_null ) ) ) ) ) {
#   define XfOrM629_COUNT (0+XfOrM615_COUNT)
#   define SETUP_XfOrM629(x) SETUP_XfOrM615(x)
    fm = (((Scheme_Type ) (((((long ) (fm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fm ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (fm ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM629(_), scheme_stx_content (fm ) )) ) -> u . pair_val . car ) ) ; 
  }
  else {
#   define XfOrM628_COUNT (0+XfOrM615_COUNT)
#   define SETUP_XfOrM628(x) SETUP_XfOrM615(x)
    fm = (__funcarg119 = FUNCCALL(SETUP_XfOrM628(_), scheme_datum_to_syntax (module_begin_symbol , form , scheme_false , 0 , 2 ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg119 , fm ) )) ; 
    check_mb = 1 ; 
  }
  fm = FUNCCALL(SETUP_XfOrM615(_), scheme_datum_to_syntax (fm , form , form , 0 , 2 ) ); 
  fm = FUNCCALL(SETUP_XfOrM615(_), scheme_stx_property (fm , module_name_symbol , m -> modname ) ); 
  if (! empty_self_modidx ) {
#   define XfOrM627_COUNT (0+XfOrM615_COUNT)
#   define SETUP_XfOrM627(x) SETUP_XfOrM615(x)
    FUNCCALL(SETUP_XfOrM627(_), scheme_register_static ((void * ) & empty_self_modidx , sizeof (empty_self_modidx ) ) ); 
    FUNCCALL(SETUP_XfOrM627(_), scheme_register_static ((void * ) & empty_self_symbol , sizeof (empty_self_symbol ) ) ); 
    empty_self_modidx = FUNCCALL_AGAIN(scheme_make_modidx (scheme_false , scheme_false , scheme_false ) ); 
    empty_self_symbol = FUNCCALL_AGAIN(scheme_make_symbol ("expanded module" ) ); 
  }
  fm = FUNCCALL(SETUP_XfOrM615(_), scheme_stx_phase_shift (fm , 0 , empty_self_modidx , self_modidx , ((void * ) 0 ) ) ); 
  fm = FUNCCALL(SETUP_XfOrM615(_), scheme_add_rename (fm , rn ) ); 
  fm = FUNCCALL_AGAIN(scheme_add_rename (fm , et_rn ) ); 
  fm = FUNCCALL_AGAIN(scheme_add_rename (fm , tt_rn ) ); 
  fm = FUNCCALL_AGAIN(scheme_add_rename (fm , dt_rn ) ); 
  if (! check_mb ) {
#   define XfOrM621_COUNT (0+XfOrM615_COUNT)
#   define SETUP_XfOrM621(x) SETUP_XfOrM615(x)
    if (rec [drec ] . observer ) {
#     define XfOrM626_COUNT (0+XfOrM621_COUNT)
#     define SETUP_XfOrM626(x) SETUP_XfOrM621(x)
      FUNCCALL(SETUP_XfOrM626(_), scheme_call_expand_observe (rec [drec ] . observer , 3 , ((void * ) 0 ) ) ); 
    }
    else {
    }
    ; 
    fm = FUNCCALL(SETUP_XfOrM621(_), scheme_check_immediate_macro (fm , benv , rec , drec , 0 , & mbval , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
    if (rec [drec ] . observer ) {
#     define XfOrM624_COUNT (0+XfOrM621_COUNT)
#     define SETUP_XfOrM624(x) SETUP_XfOrM621(x)
      FUNCCALL(SETUP_XfOrM624(_), scheme_call_expand_observe (rec [drec ] . observer , 3 , ((void * ) 0 ) ) ); 
    }
    else {
    }
    ; 
    if (! ((mbval ) == (modbeg_syntax ) ) ) {
      Scheme_Object * mb ; 
      BLOCK_SETUP((PUSH(mb, 0+XfOrM621_COUNT)));
#     define XfOrM622_COUNT (1+XfOrM621_COUNT)
#     define SETUP_XfOrM622(x) SETUP(XfOrM622_COUNT)
      mb = NULLED_OUT ; 
      mb = FUNCCALL(SETUP_XfOrM622(_), scheme_datum_to_syntax (module_begin_symbol , form , scheme_false , 0 , 0 ) ); 
      fm = (__funcarg118 = FUNCCALL(SETUP_XfOrM622(_), scheme_make_pair (fm , scheme_null ) ), FUNCCALL_AGAIN(scheme_make_pair (mb , __funcarg118 ) )) ; 
      fm = FUNCCALL_AGAIN(scheme_datum_to_syntax (fm , form , form , 0 , 2 ) ); 
      fm = FUNCCALL_AGAIN(scheme_stx_property (fm , module_name_symbol , m -> modname ) ); 
      fm = FUNCCALL_AGAIN(scheme_add_rename (fm , rn ) ); 
      fm = FUNCCALL_AGAIN(scheme_add_rename (fm , et_rn ) ); 
      fm = FUNCCALL_AGAIN(scheme_add_rename (fm , tt_rn ) ); 
      fm = FUNCCALL_AGAIN(scheme_add_rename (fm , dt_rn ) ); 
      check_mb = 1 ; 
    }
  }
  if (check_mb && ! saw_mb ) {
#   define XfOrM620_COUNT (0+XfOrM615_COUNT)
#   define SETUP_XfOrM620(x) SETUP_XfOrM615(x)
    FUNCCALL(SETUP_XfOrM620(_), scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , form , "no #%%module-begin binding in the module's language" ) ); 
  }
  if (rec [drec ] . comp ) {
    Scheme_Object * dummy ; 
    BLOCK_SETUP((PUSH(dummy, 0+XfOrM615_COUNT)));
#   define XfOrM618_COUNT (1+XfOrM615_COUNT)
#   define SETUP_XfOrM618(x) SETUP(XfOrM618_COUNT)
    dummy = NULLED_OUT ; 
    dummy = FUNCCALL(SETUP_XfOrM618(_), scheme_make_environment_dummy (env ) ); 
    m -> dummy = dummy ; 
    FUNCCALL(SETUP_XfOrM618(_), scheme_compile_rec_done_local (rec , drec ) ); 
    fm = FUNCCALL_AGAIN(scheme_compile_expr (fm , benv , rec , drec ) ); 
    if (! ((fm ) == ((Scheme_Object * ) m ) ) ) {
#     define XfOrM619_COUNT (0+XfOrM618_COUNT)
#     define SETUP_XfOrM619(x) SETUP_XfOrM618(x)
      FUNCCALL(SETUP_XfOrM619(_), scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , form , "compiled body was not built with #%%module-begin" ) ); 
    }
    if (restore_confusing_name )
      m -> modname = kernel_symbol ; 
    m -> ii_src = ((void * ) 0 ) ; 
    fm = FUNCCALL(SETUP_XfOrM618(_), scheme_make_syntax_compiled (6 , (Scheme_Object * ) m ) ); 
  }
  else {
    Scheme_Object * hints , * formname ; 
    BLOCK_SETUP((PUSH(formname, 0+XfOrM615_COUNT), PUSH(hints, 1+XfOrM615_COUNT)));
#   define XfOrM616_COUNT (2+XfOrM615_COUNT)
#   define SETUP_XfOrM616(x) SETUP(XfOrM616_COUNT)
    hints = NULLED_OUT ; 
    formname = NULLED_OUT ; 
    fm = FUNCCALL(SETUP_XfOrM616(_), scheme_expand_expr (fm , benv , rec , drec ) ); 
    m -> ii_src = ((void * ) 0 ) ; 
    hints = m -> hints ; 
    m -> hints = ((void * ) 0 ) ; 
    formname = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM616(_), scheme_stx_content (form ) )) ) -> u . pair_val . car ) ) ; 
    fm = (__funcarg115 = (__funcarg116 = (__funcarg117 = FUNCCALL(SETUP_XfOrM616(_), scheme_make_pair (fm , scheme_null ) ), FUNCCALL_AGAIN(scheme_make_pair (ii , __funcarg117 ) )) , FUNCCALL_AGAIN(scheme_make_pair (nm , __funcarg116 ) )) , FUNCCALL_AGAIN(scheme_make_pair (formname , __funcarg115 ) )) ; 
    fm = FUNCCALL_AGAIN(scheme_datum_to_syntax (fm , form , form , 0 , 2 ) ); 
    if (hints ) {
#     define XfOrM617_COUNT (0+XfOrM616_COUNT)
#     define SETUP_XfOrM617(x) SETUP_XfOrM616(x)
      FUNCCALL(SETUP_XfOrM617(_), scheme_make_list_immutable (m -> requires ) ); 
      FUNCCALL(SETUP_XfOrM617(_), scheme_make_list_immutable (m -> et_requires ) ); 
      FUNCCALL_AGAIN(scheme_make_list_immutable (m -> tt_requires ) ); 
      fm = (__funcarg114 = FUNCCALL(SETUP_XfOrM617(_), scheme_intern_symbol ("module-direct-requires" ) ), FUNCCALL_AGAIN(scheme_stx_property (fm , __funcarg114 , m -> requires ) )) ; 
      fm = (__funcarg113 = FUNCCALL(SETUP_XfOrM617(_), scheme_intern_symbol ("module-direct-for-syntax-requires" ) ), FUNCCALL_AGAIN(scheme_stx_property (fm , __funcarg113 , m -> et_requires ) )) ; 
      fm = (__funcarg112 = FUNCCALL(SETUP_XfOrM617(_), scheme_intern_symbol ("module-direct-for-template-requires" ) ), FUNCCALL_AGAIN(scheme_stx_property (fm , __funcarg112 , m -> tt_requires ) )) ; 
      fm = (__funcarg111 = FUNCCALL(SETUP_XfOrM617(_), scheme_intern_symbol ("module-variable-provides" ) ), FUNCCALL_AGAIN(scheme_stx_property (fm , __funcarg111 , (((Scheme_Simple_Object * ) (hints ) ) -> u . pair_val . car ) ) )) ; 
      hints = (((Scheme_Simple_Object * ) (hints ) ) -> u . pair_val . cdr ) ; 
      fm = (__funcarg110 = FUNCCALL(SETUP_XfOrM617(_), scheme_intern_symbol ("module-syntax-provides" ) ), FUNCCALL_AGAIN(scheme_stx_property (fm , __funcarg110 , (((Scheme_Simple_Object * ) (hints ) ) -> u . pair_val . car ) ) )) ; 
      hints = (((Scheme_Simple_Object * ) (hints ) ) -> u . pair_val . cdr ) ; 
      fm = (__funcarg109 = FUNCCALL(SETUP_XfOrM617(_), scheme_intern_symbol ("module-indirect-provides" ) ), FUNCCALL_AGAIN(scheme_stx_property (fm , __funcarg109 , (((Scheme_Simple_Object * ) (hints ) ) -> u . pair_val . car ) ) )) ; 
      hints = (((Scheme_Simple_Object * ) (hints ) ) -> u . pair_val . cdr ) ; 
      fm = (__funcarg108 = FUNCCALL(SETUP_XfOrM617(_), scheme_intern_symbol ("module-kernel-reprovide-hint" ) ), FUNCCALL_AGAIN(scheme_stx_property (fm , __funcarg108 , (((Scheme_Simple_Object * ) (hints ) ) -> u . pair_val . car ) ) )) ; 
      fm = (__funcarg107 = FUNCCALL(SETUP_XfOrM617(_), scheme_intern_symbol ("module-self-path-index" ) ), FUNCCALL_AGAIN(scheme_stx_property (fm , __funcarg107 , empty_self_modidx ) )) ; 
    }
    fm = FUNCCALL(SETUP_XfOrM616(_), scheme_stx_phase_shift (fm , 0 , self_modidx , empty_self_modidx , ((void * ) 0 ) ) ); 
    ((Scheme_Modidx * ) self_modidx ) -> resolved = empty_self_symbol ; 
  }
  FUNCCALL(SETUP_XfOrM615(_), clear_marked_names_nonempty (mn_ht ) ); 
  FUNCCALL(SETUP_XfOrM615(_), clear_marked_names_nonempty (et_mn_ht ) ); 
  FUNCCALL_AGAIN(clear_marked_names_nonempty (tt_mn_ht ) ); 
  RET_VALUE_START (fm ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * module_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  /* No conversion */
  return do_module (form , env , rec , drec ) ; 
}
static Scheme_Object * module_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(erec, 0), PUSH(env, 1), PUSH(form, 2)));
# define XfOrM637_COUNT (3)
# define SETUP_XfOrM637(x) SETUP(XfOrM637_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (erec [drec ] . observer ) {
#   define XfOrM639_COUNT (0+XfOrM637_COUNT)
#   define SETUP_XfOrM639(x) SETUP_XfOrM637(x)
    FUNCCALL(SETUP_XfOrM639(_), scheme_call_expand_observe (erec [drec ] . observer , 101 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  if (erec [drec ] . depth > 0 )
    erec [drec ] . depth ++ ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(do_module (form , env , erec , drec ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_apply_for_syntax_in_env (Scheme_Object * proc , Scheme_Env * env ) {
  Scheme_Comp_Env * rhs_env ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(proc, 0), PUSH(env, 1), PUSH(rhs_env, 2)));
# define XfOrM640_COUNT (3)
# define SETUP_XfOrM640(x) SETUP(XfOrM640_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  rhs_env = NULLED_OUT ; 
  rhs_env = FUNCCALL(SETUP_XfOrM640(_), scheme_new_comp_env (env , ((void * ) 0 ) , 1 ) ); 
  FUNCCALL_AGAIN(scheme_on_next_top (rhs_env , ((void * ) 0 ) , scheme_false , ((void * ) 0 ) , env , (env -> link_midx ? env -> link_midx : (env -> module ? env -> module -> me -> src_modidx : ((void * ) 0 ) ) ) ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_apply_multi (proc , 0 , ((void * ) 0 ) ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void check_require_name (Scheme_Object * prnt_name , Scheme_Object * name , Scheme_Object * nominal_modidx , Scheme_Object * modidx , Scheme_Object * exname , int isval , void * tables , Scheme_Object * e , Scheme_Object * form , Scheme_Object * err_src ) {
  Scheme_Bucket_Table * toplevel , * syntax ; 
  Scheme_Hash_Table * required ; 
  Scheme_Object * vec , * nml ; 
  Scheme_Config * __funcarg123 = NULLED_OUT ; 
  Scheme_Object * __funcarg122 = NULLED_OUT ; 
  PREPARE_VAR_STACK(14);
  BLOCK_SETUP_TOP((PUSH(required, 0), PUSH(modidx, 1), PUSH(nml, 2), PUSH(vec, 3), PUSH(name, 4), PUSH(err_src, 5), PUSH(nominal_modidx, 6), PUSH(exname, 7), PUSH(syntax, 8), PUSH(prnt_name, 9), PUSH(form, 10)));
# define XfOrM641_COUNT (11)
# define SETUP_XfOrM641(x) SETUP(XfOrM641_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  toplevel = NULLED_OUT ; 
  syntax = NULLED_OUT ; 
  required = NULLED_OUT ; 
  vec = NULLED_OUT ; 
  nml = NULLED_OUT ; 
  toplevel = ((Scheme_Bucket_Table * * ) tables ) [0 ] ; 
  required = ((Scheme_Hash_Table * * ) tables ) [1 ] ; 
  syntax = ((Scheme_Bucket_Table * * ) tables ) [2 ] ; 
  if (toplevel ) {
#   define XfOrM649_COUNT (0+XfOrM641_COUNT)
#   define SETUP_XfOrM649(x) SETUP_XfOrM641(x)
    if (FUNCCALL(SETUP_XfOrM649(_), scheme_lookup_in_table (toplevel , (const char * ) name ) )) {
#     define XfOrM650_COUNT (0+XfOrM649_COUNT)
#     define SETUP_XfOrM650(x) SETUP_XfOrM649(x)
      FUNCCALL_EMPTY(scheme_wrong_syntax ("module" , prnt_name , form , "imported identifier already defined" ) ); 
    }
  }
  vec = FUNCCALL(SETUP_XfOrM641(_), scheme_hash_get (required , name ) ); 
  if (vec ) {
    Scheme_Object * srcs ; 
    char * fromsrc = ((void * ) 0 ) , * fromsrc_colon = "" ; 
    long fromsrclen = 0 ; 
    BLOCK_SETUP((PUSH(fromsrc, 0+XfOrM641_COUNT), PUSH(srcs, 1+XfOrM641_COUNT), PUSH(fromsrc_colon, 2+XfOrM641_COUNT)));
#   define XfOrM644_COUNT (3+XfOrM641_COUNT)
#   define SETUP_XfOrM644(x) SETUP(XfOrM644_COUNT)
    srcs = NULLED_OUT ; 
    if (FUNCCALL(SETUP_XfOrM644(_), same_resolved_modidx ((((Scheme_Vector * ) (vec ) ) -> els ) [1 ] , modidx ) )&& (((((Scheme_Vector * ) (vec ) ) -> els ) [2 ] ) == (exname ) ) ) {
#     define XfOrM648_COUNT (0+XfOrM644_COUNT)
#     define SETUP_XfOrM648(x) SETUP_XfOrM644(x)
      nml = FUNCCALL(SETUP_XfOrM648(_), scheme_make_pair (nominal_modidx , (((Scheme_Vector * ) (vec ) ) -> els ) [0 ] ) ); 
      (((Scheme_Vector * ) (vec ) ) -> els ) [0 ] = nml ; 
      RET_NOTHING ; 
    }
    srcs = scheme_null ; 
    if ((! ((((((Scheme_Vector * ) (vec ) ) -> els ) [5 ] ) ) == (scheme_false ) ) ) ) {
#     define XfOrM646_COUNT (0+XfOrM644_COUNT)
#     define SETUP_XfOrM646(x) SETUP_XfOrM644(x)
      srcs = FUNCCALL(SETUP_XfOrM646(_), scheme_make_immutable_pair ((((Scheme_Vector * ) (vec ) ) -> els ) [5 ] , srcs ) ); 
      if ((! ((((__funcarg123 = FUNCCALL(SETUP_XfOrM646(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg123 , MZCONFIG_ERROR_PRINT_SRCLOC ) )) ) ) == (scheme_false ) ) ) ) {
#       define XfOrM647_COUNT (0+XfOrM646_COUNT)
#       define SETUP_XfOrM647(x) SETUP_XfOrM646(x)
        fromsrc = (__funcarg122 = FUNCCALL(SETUP_XfOrM647(_), scheme_syntax_to_datum ((((Scheme_Vector * ) (vec ) ) -> els ) [5 ] , 0 , ((void * ) 0 ) ) ), FUNCCALL_AGAIN(scheme_write_to_string_w_max (__funcarg122 , & fromsrclen , 32 ) )) ; 
        fromsrc_colon = ":" ; 
      }
    }
    if (! fromsrc ) {
      fromsrc = "a different source" ; 
      fromsrclen = strlen (fromsrc ) ; 
    }
    if (err_src )
      srcs = FUNCCALL(SETUP_XfOrM644(_), scheme_make_immutable_pair (err_src , srcs ) ); 
    FUNCCALL(SETUP_XfOrM644(_), scheme_wrong_syntax_with_more_sources ("module" , prnt_name , err_src , srcs , "identifier already imported from%s %t" , fromsrc_colon , fromsrc , fromsrclen ) ); 
  }
  if (syntax ) {
#   define XfOrM642_COUNT (0+XfOrM641_COUNT)
#   define SETUP_XfOrM642(x) SETUP_XfOrM641(x)
    if (FUNCCALL(SETUP_XfOrM642(_), scheme_lookup_in_table (syntax , (const char * ) name ) )) {
#     define XfOrM643_COUNT (0+XfOrM642_COUNT)
#     define SETUP_XfOrM643(x) SETUP_XfOrM642(x)
      FUNCCALL_EMPTY(scheme_wrong_syntax ("module" , prnt_name , form , "imported identifier already defined" ) ); 
    }
  }
  vec = FUNCCALL(SETUP_XfOrM641(_), scheme_make_vector (6 , ((void * ) 0 ) ) ); 
  nml = FUNCCALL(SETUP_XfOrM641(_), scheme_make_pair (nominal_modidx , scheme_null ) ); 
  (((Scheme_Vector * ) (vec ) ) -> els ) [0 ] = nml ; 
  (((Scheme_Vector * ) (vec ) ) -> els ) [1 ] = modidx ; 
  (((Scheme_Vector * ) (vec ) ) -> els ) [2 ] = exname ; 
  (((Scheme_Vector * ) (vec ) ) -> els ) [3 ] = (isval ? scheme_true : scheme_false ) ; 
  (((Scheme_Vector * ) (vec ) ) -> els ) [4 ] = prnt_name ; 
  (((Scheme_Vector * ) (vec ) ) -> els ) [5 ] = (err_src ? err_src : scheme_false ) ; 
  FUNCCALL_EMPTY(scheme_hash_set (required , name , vec ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * stx_sym (Scheme_Object * name , Scheme_Object * _genv ) {
  /* No conversion */
  return scheme_tl_id_sym ((Scheme_Env * ) _genv , name , ((void * ) 0 ) , 2 ) ; 
}
static Scheme_Object * add_a_rename (Scheme_Object * fm , Scheme_Object * post_ex_rn ) {
  /* No conversion */
  return scheme_add_rename (fm , post_ex_rn ) ; 
}
static Scheme_Object * add_req (Scheme_Object * imods , Scheme_Object * requires ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(imods, 0), PUSH(requires, 1)));
# define XfOrM653_COUNT (2)
# define SETUP_XfOrM653(x) SETUP(XfOrM653_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  for (; ! ((imods ) == (scheme_null ) ) ; imods = (((Scheme_Simple_Object * ) (imods ) ) -> u . pair_val . cdr ) ) {
    Scheme_Object * il , * ilast = ((void * ) 0 ) ; 
    Scheme_Object * idx = (((Scheme_Simple_Object * ) (imods ) ) -> u . pair_val . car ) ; 
    BLOCK_SETUP((PUSH(ilast, 0+XfOrM653_COUNT), PUSH(idx, 1+XfOrM653_COUNT), PUSH(il, 2+XfOrM653_COUNT)));
#   define XfOrM658_COUNT (3+XfOrM653_COUNT)
#   define SETUP_XfOrM658(x) SETUP(XfOrM658_COUNT)
    il = NULLED_OUT ; 
    for (il = requires ; ((Scheme_Type ) (((((long ) (il ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (il ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; il = (((Scheme_Simple_Object * ) (il ) ) -> u . pair_val . cdr ) ) {
#     define XfOrM661_COUNT (0+XfOrM658_COUNT)
#     define SETUP_XfOrM661(x) SETUP_XfOrM658(x)
      if (FUNCCALL(SETUP_XfOrM661(_), same_modidx (idx , (((Scheme_Simple_Object * ) (il ) ) -> u . pair_val . car ) ) ))
        break ; 
      ilast = il ; 
    }
    if (((il ) == (scheme_null ) ) ) {
#     define XfOrM659_COUNT (0+XfOrM658_COUNT)
#     define SETUP_XfOrM659(x) SETUP_XfOrM658(x)
      il = FUNCCALL(SETUP_XfOrM659(_), scheme_make_pair (idx , scheme_null ) ); 
      if (ilast )
        (((Scheme_Simple_Object * ) (ilast ) ) -> u . pair_val . cdr ) = il ; 
      else requires = il ; 
    }
  }
  RET_VALUE_START (requires ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * add_lifted_defn (Scheme_Object * data , Scheme_Object * * _id , Scheme_Object * expr , Scheme_Comp_Env * _env ) {
  Scheme_Comp_Env * env ; 
  Scheme_Object * self_modidx , * rn , * name , * id ; 
  Scheme_Object * __funcarg124 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(8);
  BLOCK_SETUP_TOP((PUSH(id, 0), PUSH(rn, 1), PUSH(self_modidx, 2), PUSH(_env, 3), PUSH(expr, 4), PUSH(name, 5), PUSH(_id, 6), PUSH(env, 7)));
# define XfOrM662_COUNT (8)
# define SETUP_XfOrM662(x) SETUP(XfOrM662_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  env = NULLED_OUT ; 
  self_modidx = NULLED_OUT ; 
  rn = NULLED_OUT ; 
  name = NULLED_OUT ; 
  id = NULLED_OUT ; 
  env = (Scheme_Comp_Env * ) (((Scheme_Vector * ) (data ) ) -> els ) [0 ] ; 
  self_modidx = (((Scheme_Vector * ) (data ) ) -> els ) [1 ] ; 
  rn = (((Scheme_Vector * ) (data ) ) -> els ) [2 ] ; 
  name = FUNCCALL(SETUP_XfOrM662(_), scheme_tl_id_sym (env -> genv , * _id , scheme_false , 2 ) ); 
  FUNCCALL_AGAIN(scheme_add_global_symbol (name , scheme_undefined , env -> genv ) ); 
  FUNCCALL_AGAIN(scheme_extend_module_rename (rn , self_modidx , name , name , self_modidx , name , 0 , 0 ) ); 
  id = FUNCCALL_AGAIN(scheme_add_rename (* _id , rn ) ); 
  * _id = id ; 
  RET_VALUE_START ((__funcarg124 = FUNCCALL(SETUP_XfOrM662(_), scheme_sys_wraps (env ) ), FUNCCALL_EMPTY(scheme_make_lifted_defn (__funcarg124 , _id , expr , _env ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void flush_definitions (Scheme_Env * genv ) {
  PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(genv, 0)));
# define XfOrM663_COUNT (1)
# define SETUP_XfOrM663(x) SETUP(XfOrM663_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (genv -> syntax ) {
    Scheme_Bucket_Table * t ; 
    BLOCK_SETUP((PUSH(t, 0+XfOrM663_COUNT)));
#   define XfOrM665_COUNT (1+XfOrM663_COUNT)
#   define SETUP_XfOrM665(x) SETUP(XfOrM665_COUNT)
    t = NULLED_OUT ; 
    t = FUNCCALL(SETUP_XfOrM665(_), scheme_make_bucket_table (7 , SCHEME_hash_ptr ) ); 
    genv -> syntax = t ; 
  }
  if (genv -> toplevel ) {
    Scheme_Bucket_Table * t ; 
    BLOCK_SETUP((PUSH(t, 0+XfOrM663_COUNT)));
#   define XfOrM664_COUNT (1+XfOrM663_COUNT)
#   define SETUP_XfOrM664(x) SETUP(XfOrM664_COUNT)
    t = NULLED_OUT ; 
    t = FUNCCALL(SETUP_XfOrM664(_), scheme_make_bucket_table (7 , SCHEME_hash_ptr ) ); 
    t -> with_home = 1 ; 
    genv -> toplevel = t ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_module_begin (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Expand_Info * rec , int drec ) {
  Scheme_Object * fm , * first , * last , * p , * rn , * exp_body , * et_rn , * tt_rn , * dt_rn , * self_modidx , * prev_p ; 
  Scheme_Comp_Env * xenv , * cenv , * rhs_env ; 
  Scheme_Hash_Table * et_required ; 
  Scheme_Hash_Table * tt_required ; 
  Scheme_Hash_Table * dt_required ; 
  Scheme_Hash_Table * required ; 
  Scheme_Hash_Table * provided ; 
  Scheme_Object * reprovided ; 
  Scheme_Object * all_defs_out ; 
  Scheme_Object * all_et_defs_out ; 
  Scheme_Hash_Table * et_provided , * dt_provided ; 
  Scheme_Object * et_reprovided , * dt_reprovided ; 
  Scheme_Object * all_defs ; 
  Scheme_Object * all_et_defs ; 
  Scheme_Object * post_ex_rn , * post_ex_et_rn , * post_ex_tt_rn , * post_ex_dt_rn ; 
  void * tables [3 ] , * et_tables [3 ] , * tt_tables [3 ] , * dt_tables [3 ] ; 
  Scheme_Object * exclude_hint = scheme_false , * lift_data ; 
  Scheme_Hash_Table * et_mn ; 
  Scheme_Object * * exis ; 
  Scheme_Object * lift_ctx ; 
  int exicount ; 
  char * exps ; 
  int all_simple_renames = 1 , et_all_simple_renames = 1 , tt_all_simple_renames = 1 , dt_all_simple_renames = 1 ; 
  int maybe_has_lifts = 0 ; 
  int reprovide_kernel ; 
  Scheme_Object * redef_modname ; 
  Scheme_Object * observer ; 
  Scheme_Object * __funcarg144 = NULLED_OUT ; 
  Scheme_Object * __funcarg143 = NULLED_OUT ; 
  Scheme_Object * __funcarg142 = NULLED_OUT ; 
  Scheme_Object * __funcarg139 = NULLED_OUT ; 
  Scheme_Object * __funcarg138 = NULLED_OUT ; 
  Scheme_Object * __funcarg137 = NULLED_OUT ; 
  Scheme_Object * __funcarg129 = NULLED_OUT ; 
  Scheme_Object * __funcarg128 = NULLED_OUT ; 
  Scheme_Object * __funcarg125 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(74);
  BLOCK_SETUP_TOP((PUSH(all_et_defs_out, 0), PUSH(fm, 1), PUSH(rec, 2), PUSH(dt_provided, 3), PUSH(provided, 4), PUSH(tt_rn, 5), PUSH(tt_required, 6), PUSH(dt_reprovided, 7), PUSHARRAY(tables, 3, 8), PUSH(last, 11), PUSH(post_ex_rn, 12), PUSH(first, 13), PUSH(post_ex_et_rn, 14), PUSH(exis, 15), PUSH(required, 16), PUSH(post_ex_tt_rn, 17), PUSH(rhs_env, 18), PUSH(post_ex_dt_rn, 19), PUSH(exp_body, 20), PUSH(form, 21), PUSH(exclude_hint, 22), PUSH(rn, 23), PUSHARRAY(et_tables, 3, 24), PUSH(et_mn, 27), PUSH(cenv, 28), PUSHARRAY(tt_tables, 3, 29), PUSH(all_defs_out, 32), PUSH(all_et_defs, 33), PUSH(env, 34), PUSHARRAY(dt_tables, 3, 35), PUSH(et_rn, 38), PUSH(redef_modname, 39), PUSH(et_provided, 40), PUSH(all_defs, 41), PUSH(lift_data, 42), PUSH(p, 43), PUSH(dt_rn, 44), PUSH(et_reprovided, 45), PUSH(et_required, 46), PUSH(prev_p, 47), PUSH(observer, 48), PUSH(reprovided, 49), PUSH(xenv, 50), PUSH(lift_ctx, 51), PUSH(exps, 52), PUSH(self_modidx, 53), PUSH(dt_required, 54)));
# define XfOrM666_COUNT (55)
# define SETUP_XfOrM666(x) SETUP(XfOrM666_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  fm = NULLED_OUT ; 
  first = NULLED_OUT ; 
  last = NULLED_OUT ; 
  p = NULLED_OUT ; 
  rn = NULLED_OUT ; 
  exp_body = NULLED_OUT ; 
  et_rn = NULLED_OUT ; 
  tt_rn = NULLED_OUT ; 
  dt_rn = NULLED_OUT ; 
  self_modidx = NULLED_OUT ; 
  prev_p = NULLED_OUT ; 
  xenv = NULLED_OUT ; 
  cenv = NULLED_OUT ; 
  rhs_env = NULLED_OUT ; 
  et_required = NULLED_OUT ; 
  tt_required = NULLED_OUT ; 
  dt_required = NULLED_OUT ; 
  required = NULLED_OUT ; 
  provided = NULLED_OUT ; 
  reprovided = NULLED_OUT ; 
  all_defs_out = NULLED_OUT ; 
  all_et_defs_out = NULLED_OUT ; 
  et_provided = NULLED_OUT ; 
  dt_provided = NULLED_OUT ; 
  et_reprovided = NULLED_OUT ; 
  dt_reprovided = NULLED_OUT ; 
  all_defs = NULLED_OUT ; 
  all_et_defs = NULLED_OUT ; 
  post_ex_rn = NULLED_OUT ; 
  post_ex_et_rn = NULLED_OUT ; 
  post_ex_tt_rn = NULLED_OUT ; 
  post_ex_dt_rn = NULLED_OUT ; 
  tables[0] = NULLED_OUT ; 
  tables[1] = NULLED_OUT ; 
  tables[2] = NULLED_OUT ; 
  et_tables[0] = NULLED_OUT ; 
  et_tables[1] = NULLED_OUT ; 
  et_tables[2] = NULLED_OUT ; 
  tt_tables[0] = NULLED_OUT ; 
  tt_tables[1] = NULLED_OUT ; 
  tt_tables[2] = NULLED_OUT ; 
  dt_tables[0] = NULLED_OUT ; 
  dt_tables[1] = NULLED_OUT ; 
  dt_tables[2] = NULLED_OUT ; 
  lift_data = NULLED_OUT ; 
  et_mn = NULLED_OUT ; 
  exis = NULLED_OUT ; 
  lift_ctx = NULLED_OUT ; 
  exps = NULLED_OUT ; 
  redef_modname = NULLED_OUT ; 
  observer = NULLED_OUT ; 
  if (! (env -> flags & 2 ) )
    FUNCCALL(SETUP_XfOrM666(_), scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , form , "illegal use (not a module body)" ) ); 
  if (FUNCCALL(SETUP_XfOrM666(_), scheme_stx_proper_list_length (form ) )< 0 )
    FUNCCALL(SETUP_XfOrM666(_), scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , form , "bad syntax (" "illegal use of `.'" ")" ) ); 
  if (! env -> genv -> module )
    FUNCCALL(SETUP_XfOrM666(_), scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , form , "not currently transforming a module" ) ); 
  redef_modname = env -> genv -> module -> modname ; 
  if (! FUNCCALL(SETUP_XfOrM666(_), scheme_hash_get (env -> genv -> module_registry , redef_modname ) ))
    redef_modname = ((void * ) 0 ) ; 
  xenv = FUNCCALL(SETUP_XfOrM666(_), scheme_new_compilation_frame (0 , (64 | 4 | 128 ) , env , ((void * ) 0 ) ) ); 
  {
    Scheme_Object * stop ; 
    BLOCK_SETUP((PUSH(stop, 0+XfOrM666_COUNT)));
#   define XfOrM1033_COUNT (1+XfOrM666_COUNT)
#   define SETUP_XfOrM1033(x) SETUP(XfOrM1033_COUNT)
    stop = NULLED_OUT ; 
    stop = FUNCCALL(SETUP_XfOrM1033(_), scheme_get_stop_expander () ); 
    FUNCCALL_AGAIN(scheme_add_local_syntax (25 , xenv ) ); 
    FUNCCALL_AGAIN(scheme_set_local_syntax (0 , scheme_begin_stx , stop , xenv ) ); 
    FUNCCALL_AGAIN(scheme_set_local_syntax (1 , scheme_define_values_stx , stop , xenv ) ); 
    FUNCCALL_AGAIN(scheme_set_local_syntax (2 , scheme_define_syntaxes_stx , stop , xenv ) ); 
    FUNCCALL_AGAIN(scheme_set_local_syntax (3 , define_for_syntaxes_stx , stop , xenv ) ); 
    FUNCCALL_AGAIN(scheme_set_local_syntax (4 , require_stx , stop , xenv ) ); 
    FUNCCALL_AGAIN(scheme_set_local_syntax (5 , require_for_syntax_stx , stop , xenv ) ); 
    FUNCCALL_AGAIN(scheme_set_local_syntax (6 , require_for_template_stx , stop , xenv ) ); 
    FUNCCALL_AGAIN(scheme_set_local_syntax (7 , require_for_label_stx , stop , xenv ) ); 
    FUNCCALL_AGAIN(scheme_set_local_syntax (8 , provide_stx , stop , xenv ) ); 
    FUNCCALL_AGAIN(scheme_set_local_syntax (9 , provide_for_syntax_stx , stop , xenv ) ); 
    FUNCCALL_AGAIN(scheme_set_local_syntax (10 , provide_for_label_stx , stop , xenv ) ); 
    FUNCCALL_AGAIN(scheme_set_local_syntax (11 , set_stx , stop , xenv ) ); 
    FUNCCALL_AGAIN(scheme_set_local_syntax (12 , app_stx , stop , xenv ) ); 
    FUNCCALL_AGAIN(scheme_set_local_syntax (13 , scheme_top_stx , stop , xenv ) ); 
    FUNCCALL_AGAIN(scheme_set_local_syntax (14 , lambda_stx , stop , xenv ) ); 
    FUNCCALL_AGAIN(scheme_set_local_syntax (15 , case_lambda_stx , stop , xenv ) ); 
    FUNCCALL_AGAIN(scheme_set_local_syntax (16 , let_values_stx , stop , xenv ) ); 
    FUNCCALL_AGAIN(scheme_set_local_syntax (17 , letrec_values_stx , stop , xenv ) ); 
    FUNCCALL_AGAIN(scheme_set_local_syntax (18 , if_stx , stop , xenv ) ); 
    FUNCCALL_AGAIN(scheme_set_local_syntax (19 , begin0_stx , stop , xenv ) ); 
    FUNCCALL_AGAIN(scheme_set_local_syntax (20 , set_stx , stop , xenv ) ); 
    FUNCCALL_AGAIN(scheme_set_local_syntax (21 , with_continuation_mark_stx , stop , xenv ) ); 
    FUNCCALL_AGAIN(scheme_set_local_syntax (22 , letrec_syntaxes_stx , stop , xenv ) ); 
    FUNCCALL_AGAIN(scheme_set_local_syntax (23 , var_ref_stx , stop , xenv ) ); 
    FUNCCALL_AGAIN(scheme_set_local_syntax (24 , expression_stx , stop , xenv ) ); 
  }
  first = scheme_null ; 
  last = ((void * ) 0 ) ; 
  rn = env -> genv -> rename ; 
  et_rn = env -> genv -> et_rename ; 
  tt_rn = env -> genv -> tt_rename ; 
  dt_rn = env -> genv -> dt_rename ; 
  required = FUNCCALL(SETUP_XfOrM666(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  et_required = FUNCCALL_AGAIN(scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  dt_required = FUNCCALL_AGAIN(scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  {
    Scheme_Module * iim ; 
    Scheme_Object * nmidx , * orig_src ; 
    BLOCK_SETUP((PUSH(iim, 0+XfOrM666_COUNT), PUSH(nmidx, 1+XfOrM666_COUNT), PUSH(orig_src, 2+XfOrM666_COUNT)));
#   define XfOrM1032_COUNT (3+XfOrM666_COUNT)
#   define SETUP_XfOrM1032(x) SETUP(XfOrM1032_COUNT)
    iim = NULLED_OUT ; 
    nmidx = NULLED_OUT ; 
    orig_src = NULLED_OUT ; 
    orig_src = env -> genv -> module -> ii_src ; 
    if (! orig_src )
      orig_src = scheme_false ; 
    else if (! ((Scheme_Type ) (((((long ) (orig_src ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (orig_src ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
      orig_src = scheme_false ; 
    nmidx = (((Scheme_Simple_Object * ) (env -> genv -> module -> requires ) ) -> u . pair_val . car ) ; 
    iim = (__funcarg144 = FUNCCALL(SETUP_XfOrM1032(_), scheme_module_resolve (nmidx , 1 ) ), FUNCCALL_AGAIN(module_load (__funcarg144 , env -> genv , ((void * ) 0 ) ) )) ; 
    FUNCCALL_AGAIN(add_initial_require_renames (orig_src , rn , required , et_rn , et_required , dt_rn , dt_required , iim , nmidx ) ); 
  }
  if (rec [drec ] . comp || (rec [drec ] . depth != - 2 ) ) {
    env -> genv -> rename = ((void * ) 0 ) ; 
    env -> genv -> et_rename = ((void * ) 0 ) ; 
    env -> genv -> tt_rename = ((void * ) 0 ) ; 
  }
  {
    Scheme_Object * v ; 
    BLOCK_SETUP((PUSH(v, 0+XfOrM666_COUNT)));
#   define XfOrM1030_COUNT (1+XfOrM666_COUNT)
#   define SETUP_XfOrM1030(x) SETUP(XfOrM1030_COUNT)
    v = NULLED_OUT ; 
    v = FUNCCALL(SETUP_XfOrM1030(_), scheme_rename_to_stx (rn ) ); 
    env -> genv -> module -> rn_stx = v ; 
    v = FUNCCALL(SETUP_XfOrM1030(_), scheme_rename_to_stx (et_rn ) ); 
    env -> genv -> module -> et_rn_stx = v ; 
    v = FUNCCALL(SETUP_XfOrM1030(_), scheme_rename_to_stx (tt_rn ) ); 
    env -> genv -> module -> tt_rn_stx = v ; 
    v = FUNCCALL(SETUP_XfOrM1030(_), scheme_rename_to_stx (dt_rn ) ); 
    env -> genv -> module -> dt_rn_stx = v ; 
  }
  tables [0 ] = env -> genv -> toplevel ; 
  tables [1 ] = required ; 
  tables [2 ] = env -> genv -> syntax ; 
  et_tables [0 ] = ((void * ) 0 ) ; 
  et_tables [1 ] = et_required ; 
  et_tables [2 ] = ((void * ) 0 ) ; 
  tt_required = FUNCCALL(SETUP_XfOrM666(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  tt_tables [0 ] = ((void * ) 0 ) ; 
  tt_tables [1 ] = tt_required ; 
  tt_tables [2 ] = ((void * ) 0 ) ; 
  dt_tables [0 ] = ((void * ) 0 ) ; 
  dt_tables [1 ] = dt_required ; 
  dt_tables [2 ] = ((void * ) 0 ) ; 
  provided = FUNCCALL(SETUP_XfOrM666(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  reprovided = scheme_null ; 
  et_provided = FUNCCALL(SETUP_XfOrM666(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  et_reprovided = scheme_null ; 
  dt_provided = FUNCCALL(SETUP_XfOrM666(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  dt_reprovided = scheme_null ; 
  all_defs_out = scheme_null ; 
  all_et_defs_out = scheme_null ; 
  all_defs = scheme_null ; 
  all_et_defs = scheme_null ; 
  exp_body = scheme_null ; 
  self_modidx = env -> genv -> module -> self_modidx ; 
  post_ex_rn = FUNCCALL(SETUP_XfOrM666(_), scheme_make_module_rename (0 , 2 , env -> genv -> marked_names ) ); 
  post_ex_et_rn = FUNCCALL_AGAIN(scheme_make_module_rename (1 , 2 , env -> genv -> exp_env -> marked_names ) ); 
  post_ex_tt_rn = FUNCCALL_AGAIN(scheme_make_module_rename (- 1 , 2 , env -> genv -> template_env -> marked_names ) ); 
  post_ex_dt_rn = FUNCCALL_AGAIN(scheme_make_module_rename (30000 , 2 , env -> genv -> template_env -> marked_names ) ); 
  rhs_env = FUNCCALL_AGAIN(scheme_new_comp_env (env -> genv , env -> insp , 1 ) ); 
  FUNCCALL_AGAIN(scheme_rec_add_certs (rec , drec , form ) ); 
  form = FUNCCALL_AGAIN(scheme_add_rename (form , post_ex_rn ) ); 
  form = FUNCCALL_AGAIN(scheme_add_rename (form , post_ex_et_rn ) ); 
  form = FUNCCALL_AGAIN(scheme_add_rename (form , post_ex_tt_rn ) ); 
  form = FUNCCALL_AGAIN(scheme_add_rename (form , post_ex_dt_rn ) ); 
  maybe_has_lifts = 0 ; 
  lift_ctx = FUNCCALL(SETUP_XfOrM666(_), scheme_generate_lifts_key () ); 
  observer = rec [drec ] . observer ; 
  for (fm = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM666(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; ! (((fm ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (fm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fm ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) fm ) -> val ) == (scheme_null ) ) ) ) ; ) {
    Scheme_Object * e ; 
    int kind ; 
    BLOCK_SETUP((PUSH(e, 0+XfOrM666_COUNT)));
#   define XfOrM906_COUNT (1+XfOrM666_COUNT)
#   define SETUP_XfOrM906(x) SETUP(XfOrM906_COUNT)
    e = NULLED_OUT ; 
    while (1 ) {
      Scheme_Object * fst ; 
      BLOCK_SETUP((PUSH(fst, 0+XfOrM906_COUNT)));
#     define XfOrM1015_COUNT (1+XfOrM906_COUNT)
#     define SETUP_XfOrM1015(x) SETUP(XfOrM1015_COUNT)
      fst = NULLED_OUT ; 
      if (observer ) {
#       define XfOrM1029_COUNT (0+XfOrM1015_COUNT)
#       define SETUP_XfOrM1029(x) SETUP_XfOrM1015(x)
        FUNCCALL(SETUP_XfOrM1029(_), scheme_call_expand_observe (observer , 3 , ((void * ) 0 ) ) ); 
      }
      else {
      }
      ; 
      e = (((Scheme_Type ) (((((long ) (fm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fm ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (fm ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1015(_), scheme_stx_content (fm ) )) ) -> u . pair_val . car ) ) ; 
      p = (maybe_has_lifts ? FUNCCALL(SETUP_XfOrM1015(_), scheme_frame_get_end_statement_lifts (xenv ) ): scheme_null ) ; 
      (__funcarg143 = FUNCCALL(SETUP_XfOrM1015(_), scheme_sys_wraps (xenv ) ), FUNCCALL_AGAIN(scheme_frame_captures_lifts (xenv , scheme_make_lifted_defn , __funcarg143 , p , lift_ctx ) )) ; 
      maybe_has_lifts = 1 ; 
      {
        Scheme_Expand_Info erec1 ; 
        BLOCK_SETUP((PUSH(erec1.value_name, 0+XfOrM1015_COUNT), PUSH(erec1.certs, 1+XfOrM1015_COUNT), PUSH(erec1.observer, 2+XfOrM1015_COUNT)));
#       define XfOrM1027_COUNT (3+XfOrM1015_COUNT)
#       define SETUP_XfOrM1027(x) SETUP(XfOrM1027_COUNT)
        erec1.value_name = NULLED_OUT ; 
        erec1.certs = NULLED_OUT ; 
        erec1.observer = NULLED_OUT ; 
        erec1 . comp = 0 ; 
        erec1 . depth = - 1 ; 
        erec1 . value_name = scheme_false ; 
        erec1 . certs = rec [drec ] . certs ; 
        erec1 . observer = rec [drec ] . observer ; 
        e = FUNCCALL(SETUP_XfOrM1027(_), scheme_expand_expr (e , xenv , & erec1 , 0 ) ); 
      }
      fst = FUNCCALL(SETUP_XfOrM1015(_), scheme_frame_get_lifts (xenv ) ); 
      if (! ((fst ) == (scheme_null ) ) ) {
#       define XfOrM1024_COUNT (0+XfOrM1015_COUNT)
#       define SETUP_XfOrM1024(x) SETUP_XfOrM1015(x)
        fm = (((Scheme_Type ) (((((long ) (fm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fm ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (fm ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1024(_), scheme_stx_content (fm ) )) ) -> u . pair_val . cdr ) ) ; 
        e = FUNCCALL(SETUP_XfOrM1024(_), scheme_add_rename (e , post_ex_rn ) ); 
        e = FUNCCALL_AGAIN(scheme_add_rename (e , post_ex_et_rn ) ); 
        e = FUNCCALL_AGAIN(scheme_add_rename (e , post_ex_tt_rn ) ); 
        e = FUNCCALL_AGAIN(scheme_add_rename (e , post_ex_dt_rn ) ); 
        fm = FUNCCALL_AGAIN(scheme_named_map_1 (((void * ) 0 ) , add_a_rename , fm , post_ex_rn ) ); 
        fm = FUNCCALL_AGAIN(scheme_named_map_1 (((void * ) 0 ) , add_a_rename , fm , post_ex_et_rn ) ); 
        fm = FUNCCALL_AGAIN(scheme_named_map_1 (((void * ) 0 ) , add_a_rename , fm , post_ex_tt_rn ) ); 
        fm = FUNCCALL_AGAIN(scheme_named_map_1 (((void * ) 0 ) , add_a_rename , fm , post_ex_dt_rn ) ); 
        fm = (__funcarg142 = FUNCCALL(SETUP_XfOrM1024(_), scheme_make_pair (e , fm ) ), FUNCCALL_AGAIN(scheme_append (fst , __funcarg142 ) )) ; 
        if (observer ) {
#         define XfOrM1026_COUNT (0+XfOrM1024_COUNT)
#         define SETUP_XfOrM1026(x) SETUP_XfOrM1024(x)
          FUNCCALL(SETUP_XfOrM1026(_), scheme_call_expand_observe (observer , 137 , fst ) ); 
        }
        else {
        }
        ; 
      }
      else {
#       define XfOrM1016_COUNT (0+XfOrM1015_COUNT)
#       define SETUP_XfOrM1016(x) SETUP_XfOrM1015(x)
        if ((((Scheme_Type ) (((((long ) (e ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (e ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) e ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) e ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
          fst = (((Scheme_Type ) (((((long ) (e ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (e ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1016(_), scheme_stx_content (e ) )) ) -> u . pair_val . car ) ) ; 
        else fst = ((void * ) 0 ) ; 
        if (fst && (((Scheme_Type ) (((((long ) (fst ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fst ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (fst ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fst ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) fst ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) fst ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) && FUNCCALL(SETUP_XfOrM1016(_), scheme_stx_module_eq (scheme_begin_stx , fst , 0 ) )) {
#         define XfOrM1017_COUNT (0+XfOrM1016_COUNT)
#         define SETUP_XfOrM1017(x) SETUP_XfOrM1016(x)
          fm = (((Scheme_Type ) (((((long ) (fm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fm ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (fm ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1017(_), scheme_stx_content (fm ) )) ) -> u . pair_val . cdr ) ) ; 
          e = FUNCCALL(SETUP_XfOrM1017(_), scheme_add_rename (e , post_ex_rn ) ); 
          e = FUNCCALL_AGAIN(scheme_add_rename (e , post_ex_et_rn ) ); 
          e = FUNCCALL_AGAIN(scheme_add_rename (e , post_ex_tt_rn ) ); 
          e = FUNCCALL_AGAIN(scheme_add_rename (e , post_ex_dt_rn ) ); 
          fm = FUNCCALL_AGAIN(scheme_flatten_begin (e , fm ) ); 
          if (observer ) {
#           define XfOrM1023_COUNT (0+XfOrM1017_COUNT)
#           define SETUP_XfOrM1023(x) SETUP_XfOrM1017(x)
            FUNCCALL(SETUP_XfOrM1023(_), scheme_call_expand_observe (observer , 11 , fm ) ); 
          }
          else {
          }
          ; 
          if ((((fm ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (fm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fm ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) fm ) -> val ) == (scheme_null ) ) ) ) ) {
#           define XfOrM1018_COUNT (0+XfOrM1017_COUNT)
#           define SETUP_XfOrM1018(x) SETUP_XfOrM1017(x)
            fm = FUNCCALL(SETUP_XfOrM1018(_), scheme_frame_get_end_statement_lifts (xenv ) ); 
            fm = FUNCCALL(SETUP_XfOrM1018(_), scheme_reverse (fm ) ); 
            if (observer ) {
#             define XfOrM1021_COUNT (0+XfOrM1018_COUNT)
#             define SETUP_XfOrM1021(x) SETUP_XfOrM1018(x)
              FUNCCALL(SETUP_XfOrM1021(_), scheme_call_expand_observe (observer , 135 , fm ) ); 
            }
            else {
            }
            ; 
            maybe_has_lifts = 0 ; 
            if (((fm ) == (scheme_null ) ) ) {
              e = ((void * ) 0 ) ; 
              break ; 
            }
          }
        }
        else break ; 
      }
    }
    if (! e )
      break ; 
    e = FUNCCALL(SETUP_XfOrM906(_), scheme_add_rename (e , post_ex_rn ) ); 
    e = FUNCCALL_AGAIN(scheme_add_rename (e , post_ex_et_rn ) ); 
    e = FUNCCALL_AGAIN(scheme_add_rename (e , post_ex_tt_rn ) ); 
    e = FUNCCALL_AGAIN(scheme_add_rename (e , post_ex_dt_rn ) ); 
    if ((((Scheme_Type ) (((((long ) (e ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (e ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) e ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) e ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
      Scheme_Object * fst ; 
      BLOCK_SETUP((PUSH(fst, 0+XfOrM906_COUNT)));
#     define XfOrM911_COUNT (1+XfOrM906_COUNT)
#     define SETUP_XfOrM911(x) SETUP(XfOrM911_COUNT)
      fst = NULLED_OUT ; 
      fst = (((Scheme_Type ) (((((long ) (e ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (e ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM911(_), scheme_stx_content (e ) )) ) -> u . pair_val . car ) ) ; 
      if ((((Scheme_Type ) (((((long ) (fst ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fst ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (fst ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fst ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) fst ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) fst ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) ) {
        Scheme_Object * n ; 
#       define XfOrM912_COUNT (0+XfOrM911_COUNT)
#       define SETUP_XfOrM912(x) SETUP_XfOrM911(x)
        n = NULLED_OUT ; 
        n = (((Scheme_Type ) (((((long ) (e ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (e ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM912(_), scheme_stx_content (e ) )) ) -> u . pair_val . car ) ) ; 
        if (FUNCCALL(SETUP_XfOrM912(_), scheme_stx_module_eq (scheme_define_values_stx , fst , 0 ) )) {
          Scheme_Object * vars , * val ; 
          BLOCK_SETUP((PUSH(val, 0+XfOrM912_COUNT), PUSH(vars, 1+XfOrM912_COUNT)));
#         define XfOrM985_COUNT (2+XfOrM912_COUNT)
#         define SETUP_XfOrM985(x) SETUP(XfOrM985_COUNT)
          vars = NULLED_OUT ; 
          val = NULLED_OUT ; 
          if (observer ) {
#           define XfOrM999_COUNT (0+XfOrM985_COUNT)
#           define SETUP_XfOrM999(x) SETUP_XfOrM985(x)
            FUNCCALL(SETUP_XfOrM999(_), scheme_call_expand_observe (observer , 6 , e ) ); 
          }
          else {
          }
          ; 
          if (observer ) {
#           define XfOrM997_COUNT (0+XfOrM985_COUNT)
#           define SETUP_XfOrM997(x) SETUP_XfOrM985(x)
            FUNCCALL(SETUP_XfOrM997(_), scheme_call_expand_observe (observer , 104 , ((void * ) 0 ) ) ); 
          }
          else {
          }
          ; 
          FUNCCALL(SETUP_XfOrM985(_), scheme_define_parse (e , & vars , & val , 0 , env , 1 ) ); 
          while ((((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) vars ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) vars ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
            Scheme_Object * name , * orig_name ; 
            BLOCK_SETUP((PUSH(orig_name, 0+XfOrM985_COUNT), PUSH(name, 1+XfOrM985_COUNT)));
#           define XfOrM992_COUNT (2+XfOrM985_COUNT)
#           define SETUP_XfOrM992(x) SETUP(XfOrM992_COUNT)
            name = NULLED_OUT ; 
            orig_name = NULLED_OUT ; 
            name = (((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (vars ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM992(_), scheme_stx_content (vars ) )) ) -> u . pair_val . car ) ) ; 
            orig_name = name ; 
            all_defs = FUNCCALL(SETUP_XfOrM992(_), scheme_make_pair (name , all_defs ) ); 
            name = FUNCCALL_AGAIN(scheme_tl_id_sym (env -> genv , name , ((void * ) 0 ) , 2 ) ); 
            if (FUNCCALL(SETUP_XfOrM992(_), scheme_lookup_in_table (env -> genv -> toplevel , (const char * ) name ) )) {
#             define XfOrM995_COUNT (0+XfOrM992_COUNT)
#             define SETUP_XfOrM995(x) SETUP_XfOrM992(x)
              FUNCCALL(SETUP_XfOrM995(_), scheme_wrong_syntax ("module" , orig_name , e , "duplicate definition for identifier" ) ); 
              RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
            }
            if (FUNCCALL(SETUP_XfOrM992(_), scheme_hash_get (required , name ) )) {
#             define XfOrM994_COUNT (0+XfOrM992_COUNT)
#             define SETUP_XfOrM994(x) SETUP_XfOrM992(x)
              FUNCCALL(SETUP_XfOrM994(_), scheme_wrong_syntax ("module" , orig_name , e , "identifier is already imported" ) ); 
              RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
            }
            if (FUNCCALL(SETUP_XfOrM992(_), scheme_lookup_in_table (env -> genv -> syntax , (const char * ) name ) )) {
#             define XfOrM993_COUNT (0+XfOrM992_COUNT)
#             define SETUP_XfOrM993(x) SETUP_XfOrM992(x)
              FUNCCALL(SETUP_XfOrM993(_), scheme_wrong_syntax ("module" , orig_name , e , "duplicate definition for identifier" ) ); 
              RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
            }
            FUNCCALL(SETUP_XfOrM992(_), scheme_add_global_symbol (name , scheme_undefined , env -> genv ) ); 
            if (! ((((Scheme_Stx * ) orig_name ) -> val ) == (name ) ) )
              FUNCCALL(SETUP_XfOrM992(_), scheme_extend_module_rename (post_ex_rn , self_modidx , name , name , self_modidx , name , 0 , 0 ) ); 
            else FUNCCALL(SETUP_XfOrM992(_), scheme_extend_module_rename (rn , self_modidx , name , name , self_modidx , name , 0 , 0 ) ); 
            vars = (((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (vars ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM992(_), scheme_stx_content (vars ) )) ) -> u . pair_val . cdr ) ) ; 
          }
          if (observer ) {
#           define XfOrM987_COUNT (0+XfOrM985_COUNT)
#           define SETUP_XfOrM987(x) SETUP_XfOrM985(x)
            FUNCCALL(SETUP_XfOrM987(_), scheme_call_expand_observe (observer , 7 , e ) ); 
          }
          else {
          }
          ; 
          kind = 2 ; 
        }
        else if (FUNCCALL(SETUP_XfOrM912(_), scheme_stx_module_eq (scheme_define_syntaxes_stx , fst , 0 ) )|| FUNCCALL(SETUP_XfOrM912(_), scheme_stx_module_eq (define_for_syntaxes_stx , fst , 0 ) )) {
          Scheme_Compile_Info mrec ; 
          Scheme_Object * names , * l , * code , * m , * vec , * boundname ; 
          Resolve_Prefix * rp ; 
          Resolve_Info * ri ; 
          Scheme_Comp_Env * oenv , * eenv ; 
          Optimize_Info * oi ; 
          int count = 0 ; 
          int for_stx ; 
          BLOCK_SETUP((PUSH(oi, 0+XfOrM912_COUNT), PUSH(rp, 1+XfOrM912_COUNT), PUSH(ri, 2+XfOrM912_COUNT), PUSH(names, 3+XfOrM912_COUNT), PUSH(boundname, 4+XfOrM912_COUNT), PUSH(oenv, 5+XfOrM912_COUNT), PUSH(code, 6+XfOrM912_COUNT), PUSH(vec, 7+XfOrM912_COUNT), PUSH(mrec.value_name, 8+XfOrM912_COUNT), PUSH(mrec.certs, 9+XfOrM912_COUNT), PUSH(mrec.observer, 10+XfOrM912_COUNT), PUSH(m, 11+XfOrM912_COUNT), PUSH(eenv, 12+XfOrM912_COUNT), PUSH(l, 13+XfOrM912_COUNT)));
#         define XfOrM966_COUNT (14+XfOrM912_COUNT)
#         define SETUP_XfOrM966(x) SETUP(XfOrM966_COUNT)
          mrec.value_name = NULLED_OUT ; 
          mrec.certs = NULLED_OUT ; 
          mrec.observer = NULLED_OUT ; 
          names = NULLED_OUT ; 
          l = NULLED_OUT ; 
          code = NULLED_OUT ; 
          m = NULLED_OUT ; 
          vec = NULLED_OUT ; 
          boundname = NULLED_OUT ; 
          rp = NULLED_OUT ; 
          ri = NULLED_OUT ; 
          oenv = NULLED_OUT ; 
          eenv = NULLED_OUT ; 
          oi = NULLED_OUT ; 
          for_stx = FUNCCALL(SETUP_XfOrM966(_), scheme_stx_module_eq (define_for_syntaxes_stx , fst , 0 ) ); 
          if (observer ) {
#           define XfOrM984_COUNT (0+XfOrM966_COUNT)
#           define SETUP_XfOrM984(x) SETUP_XfOrM966(x)
            FUNCCALL(SETUP_XfOrM984(_), scheme_call_expand_observe (observer , 6 , e ) ); 
          }
          else {
          }
          ; 
          if (observer ) {
#           define XfOrM982_COUNT (0+XfOrM966_COUNT)
#           define SETUP_XfOrM982(x) SETUP_XfOrM966(x)
            FUNCCALL(SETUP_XfOrM982(_), scheme_call_expand_observe (observer , 103 , ((void * ) 0 ) ) ); 
          }
          else {
          }
          ; 
          FUNCCALL(SETUP_XfOrM966(_), scheme_define_parse (e , & names , & code , 1 , env , 1 ) ); 
          if ((((Scheme_Type ) (((((long ) (names ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (names ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (names ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (names ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) names ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) names ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) && ((((((Scheme_Type ) (((((long ) (names ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (names ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (names ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM966(_), scheme_stx_content (names ) )) ) -> u . pair_val . cdr ) ) ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) ((((Scheme_Type ) (((((long ) (names ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (names ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (names ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM966(_), scheme_stx_content (names ) )) ) -> u . pair_val . cdr ) ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Type ) (((((long ) (names ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (names ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (names ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM966(_), scheme_stx_content (names ) )) ) -> u . pair_val . cdr ) ) ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (names ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (names ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (names ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM966(_), scheme_stx_content (names ) )) ) -> u . pair_val . cdr ) ) ) -> val ) == (scheme_null ) ) ) ) )
            boundname = (((Scheme_Type ) (((((long ) (names ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (names ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (names ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM966(_), scheme_stx_content (names ) )) ) -> u . pair_val . car ) ) ; 
          else boundname = scheme_false ; 
          FUNCCALL(SETUP_XfOrM966(_), scheme_prepare_exp_env (env -> genv ) ); 
          eenv = FUNCCALL_AGAIN(scheme_new_comp_env (env -> genv -> exp_env , env -> insp , 0 ) ); 
          oenv = (for_stx ? eenv : env ) ; 
          for (l = names ; (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) l ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) l ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ; l = (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM966(_), scheme_stx_content (l ) )) ) -> u . pair_val . cdr ) ) ) {
            Scheme_Object * name , * orig_name ; 
            BLOCK_SETUP((PUSH(orig_name, 0+XfOrM966_COUNT), PUSH(name, 1+XfOrM966_COUNT)));
#           define XfOrM977_COUNT (2+XfOrM966_COUNT)
#           define SETUP_XfOrM977(x) SETUP(XfOrM977_COUNT)
            name = NULLED_OUT ; 
            orig_name = NULLED_OUT ; 
            name = (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM977(_), scheme_stx_content (l ) )) ) -> u . pair_val . car ) ) ; 
            orig_name = name ; 
            if (! for_stx )
              all_defs = FUNCCALL(SETUP_XfOrM977(_), scheme_make_pair (name , all_defs ) ); 
            else all_et_defs = FUNCCALL(SETUP_XfOrM977(_), scheme_make_pair (name , all_et_defs ) ); 
            name = FUNCCALL(SETUP_XfOrM977(_), scheme_tl_id_sym (oenv -> genv , name , ((void * ) 0 ) , 2 ) ); 
            if (FUNCCALL(SETUP_XfOrM977(_), scheme_lookup_in_table (oenv -> genv -> syntax , (const char * ) name ) )) {
#             define XfOrM980_COUNT (0+XfOrM977_COUNT)
#             define SETUP_XfOrM980(x) SETUP_XfOrM977(x)
              FUNCCALL(SETUP_XfOrM980(_), scheme_wrong_syntax ("module" , orig_name , e , (for_stx ? "duplicate for-syntax definition for identifier" : "duplicate definition for identifier" ) ) ); 
              RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
            }
            if (FUNCCALL(SETUP_XfOrM977(_), scheme_lookup_in_table (oenv -> genv -> toplevel , (const char * ) name ) )) {
#             define XfOrM979_COUNT (0+XfOrM977_COUNT)
#             define SETUP_XfOrM979(x) SETUP_XfOrM977(x)
              FUNCCALL(SETUP_XfOrM979(_), scheme_wrong_syntax ("module" , orig_name , e , (for_stx ? "duplicate for-syntax definition for identifier" : "duplicate definition for identifier" ) ) ); 
              RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
            }
            if (FUNCCALL(SETUP_XfOrM977(_), scheme_hash_get (for_stx ? et_required : required , name ) )) {
#             define XfOrM978_COUNT (0+XfOrM977_COUNT)
#             define SETUP_XfOrM978(x) SETUP_XfOrM977(x)
              FUNCCALL(SETUP_XfOrM978(_), scheme_wrong_syntax ("module" , orig_name , e , (for_stx ? "identifier is already imported for syntax" : "identifier is already imported" ) ) ); 
              RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
            }
            if (! ((((Scheme_Stx * ) orig_name ) -> val ) == (name ) ) )
              FUNCCALL(SETUP_XfOrM977(_), scheme_extend_module_rename (for_stx ? post_ex_et_rn : post_ex_rn , self_modidx , name , name , self_modidx , name , for_stx ? 1 : 0 , 0 ) ); 
            else FUNCCALL(SETUP_XfOrM977(_), scheme_extend_module_rename (for_stx ? et_rn : rn , self_modidx , name , name , self_modidx , name , for_stx ? 1 : 0 , 0 ) ); 
            count ++ ; 
          }
          names = FUNCCALL(SETUP_XfOrM966(_), scheme_named_map_1 (((void * ) 0 ) , stx_sym , names , (Scheme_Object * ) oenv -> genv ) ); 
          mrec . comp = 1 ; 
          mrec . dont_mark_local_use = 0 ; 
          mrec . resolve_module_ids = 0 ; 
          mrec . value_name = ((void * ) 0 ) ; 
          mrec . certs = rec [drec ] . certs ; 
          mrec . observer = ((void * ) 0 ) ; 
          if (! rec [drec ] . comp ) {
            Scheme_Expand_Info erec1 ; 
            BLOCK_SETUP((PUSH(erec1.value_name, 0+XfOrM966_COUNT), PUSH(erec1.certs, 1+XfOrM966_COUNT), PUSH(erec1.observer, 2+XfOrM966_COUNT)));
#           define XfOrM970_COUNT (3+XfOrM966_COUNT)
#           define SETUP_XfOrM970(x) SETUP(XfOrM970_COUNT)
            erec1.value_name = NULLED_OUT ; 
            erec1.certs = NULLED_OUT ; 
            erec1.observer = NULLED_OUT ; 
            erec1 . comp = 0 ; 
            erec1 . depth = - 1 ; 
            erec1 . value_name = boundname ; 
            erec1 . certs = rec [drec ] . certs ; 
            erec1 . observer = rec [drec ] . observer ; 
            if (observer ) {
#             define XfOrM972_COUNT (0+XfOrM970_COUNT)
#             define SETUP_XfOrM972(x) SETUP_XfOrM970(x)
              FUNCCALL(SETUP_XfOrM972(_), scheme_call_expand_observe (observer , 20 , ((void * ) 0 ) ) ); 
            }
            else {
            }
            ; 
            code = FUNCCALL(SETUP_XfOrM970(_), scheme_expand_expr_lift_to_let (code , eenv , & erec1 , 0 ) ); 
          }
          m = FUNCCALL(SETUP_XfOrM966(_), scheme_compile_expr_lift_to_let (code , eenv , & mrec , 0 ) ); 
          oi = FUNCCALL(SETUP_XfOrM966(_), scheme_optimize_info_create () ); 
          m = FUNCCALL_AGAIN(scheme_optimize_expr (m , oi ) ); 
          rp = FUNCCALL_AGAIN(scheme_resolve_prefix (1 , eenv -> prefix , rec [drec ] . comp ) ); 
          ri = FUNCCALL_AGAIN(scheme_resolve_info_create (rp ) ); 
          FUNCCALL_AGAIN(scheme_enable_expression_resolve_lifts (ri ) ); 
          m = FUNCCALL_AGAIN(scheme_resolve_expr (m , ri ) ); 
          m = FUNCCALL_AGAIN(scheme_merge_expression_resolve_lifts (m , rp , ri ) ); 
          rp = FUNCCALL_AGAIN(scheme_remap_prefix (rp , ri ) ); 
          vec = FUNCCALL_AGAIN(scheme_make_vector (5 , ((void * ) 0 ) ) ); 
          (((Scheme_Vector * ) (vec ) ) -> els ) [0 ] = names ; 
          (((Scheme_Vector * ) (vec ) ) -> els ) [1 ] = m ; 
          (((Scheme_Vector * ) (vec ) ) -> els ) [2 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (ri -> max_let_depth ) ) << 1 ) | 0x1 ) ) ; 
          (((Scheme_Vector * ) (vec ) ) -> els ) [3 ] = (Scheme_Object * ) rp ; 
          (((Scheme_Vector * ) (vec ) ) -> els ) [4 ] = (for_stx ? scheme_true : scheme_false ) ; 
          exp_body = FUNCCALL(SETUP_XfOrM966(_), scheme_make_pair (vec , exp_body ) ); 
          if (ri -> use_jit )
            m = FUNCCALL(SETUP_XfOrM966(_), scheme_jit_expr (m ) ); 
          FUNCCALL(SETUP_XfOrM966(_), eval_defmacro (names , count , m , eenv -> genv , rhs_env , rp , ri -> max_let_depth , 0 , (for_stx ? env -> genv -> exp_env -> toplevel : env -> genv -> syntax ) , for_stx , rec [drec ] . certs ) ); 
          if (rec [drec ] . comp )
            e = ((void * ) 0 ) ; 
          else {
#           define XfOrM969_COUNT (0+XfOrM966_COUNT)
#           define SETUP_XfOrM969(x) SETUP_XfOrM966(x)
            m = (((Scheme_Type ) (((((long ) (e ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (e ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM969(_), scheme_stx_content (e ) )) ) -> u . pair_val . cdr ) ) ; 
            m = (((Scheme_Type ) (((((long ) (m ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (m ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (m ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM969(_), scheme_stx_content (m ) )) ) -> u . pair_val . car ) ) ; 
            m = (__funcarg138 = (__funcarg139 = FUNCCALL(SETUP_XfOrM969(_), scheme_make_pair (code , scheme_null ) ), FUNCCALL_AGAIN(scheme_make_pair (m , __funcarg139 ) )) , FUNCCALL_AGAIN(scheme_make_pair ((((Scheme_Simple_Object * ) (fst ) ) -> u . pair_val . car ) , __funcarg138 ) )) ; 
            e = FUNCCALL_AGAIN(scheme_datum_to_syntax (m , e , e , 0 , 2 ) ); 
          }
          if (observer ) {
#           define XfOrM968_COUNT (0+XfOrM966_COUNT)
#           define SETUP_XfOrM968(x) SETUP_XfOrM966(x)
            FUNCCALL(SETUP_XfOrM968(_), scheme_call_expand_observe (observer , 7 , e ) ); 
          }
          else {
          }
          ; 
          kind = 0 ; 
        }
        else if (FUNCCALL(SETUP_XfOrM912(_), scheme_stx_module_eq (require_stx , fst , 0 ) )) {
          Scheme_Object * imods ; 
          BLOCK_SETUP((PUSH(imods, 0+XfOrM912_COUNT)));
#         define XfOrM959_COUNT (1+XfOrM912_COUNT)
#         define SETUP_XfOrM959(x) SETUP(XfOrM959_COUNT)
          imods = NULLED_OUT ; 
          if (observer ) {
#           define XfOrM965_COUNT (0+XfOrM959_COUNT)
#           define SETUP_XfOrM965(x) SETUP_XfOrM959(x)
            FUNCCALL(SETUP_XfOrM965(_), scheme_call_expand_observe (observer , 6 , e ) ); 
          }
          else {
          }
          ; 
          if (observer ) {
#           define XfOrM963_COUNT (0+XfOrM959_COUNT)
#           define SETUP_XfOrM963(x) SETUP_XfOrM959(x)
            FUNCCALL(SETUP_XfOrM963(_), scheme_call_expand_observe (observer , 119 , ((void * ) 0 ) ) ); 
          }
          else {
          }
          ; 
          imods = FUNCCALL(SETUP_XfOrM959(_), parse_requires (e , self_modidx , env -> genv , rn , post_ex_rn , et_rn , post_ex_et_rn , dt_rn , post_ex_dt_rn , check_require_name , tables , et_tables , dt_tables , 0 , 1 , redef_modname , 0 , 0 , 1 , & all_simple_renames ) ); 
          FUNCCALL_AGAIN(add_req (imods , env -> genv -> module -> requires ) ); 
          if (rec [drec ] . comp )
            e = ((void * ) 0 ) ; 
          if (observer ) {
#           define XfOrM961_COUNT (0+XfOrM959_COUNT)
#           define SETUP_XfOrM961(x) SETUP_XfOrM959(x)
            FUNCCALL(SETUP_XfOrM961(_), scheme_call_expand_observe (observer , 7 , e ) ); 
          }
          else {
          }
          ; 
          kind = 0 ; 
        }
        else if (FUNCCALL(SETUP_XfOrM912(_), scheme_stx_module_eq (require_for_syntax_stx , fst , 0 ) )) {
          Scheme_Object * imods ; 
          BLOCK_SETUP((PUSH(imods, 0+XfOrM912_COUNT)));
#         define XfOrM951_COUNT (1+XfOrM912_COUNT)
#         define SETUP_XfOrM951(x) SETUP(XfOrM951_COUNT)
          imods = NULLED_OUT ; 
          if (observer ) {
#           define XfOrM958_COUNT (0+XfOrM951_COUNT)
#           define SETUP_XfOrM958(x) SETUP_XfOrM951(x)
            FUNCCALL(SETUP_XfOrM958(_), scheme_call_expand_observe (observer , 6 , e ) ); 
          }
          else {
          }
          ; 
          if (observer ) {
#           define XfOrM956_COUNT (0+XfOrM951_COUNT)
#           define SETUP_XfOrM956(x) SETUP_XfOrM951(x)
            FUNCCALL(SETUP_XfOrM956(_), scheme_call_expand_observe (observer , 120 , ((void * ) 0 ) ) ); 
          }
          else {
          }
          ; 
          FUNCCALL(SETUP_XfOrM951(_), scheme_prepare_exp_env (env -> genv ) ); 
          imods = FUNCCALL_AGAIN(parse_requires (e , self_modidx , env -> genv -> exp_env , et_rn , post_ex_et_rn , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , check_require_name , et_tables , ((void * ) 0 ) , ((void * ) 0 ) , 1 , 0 , redef_modname , 0 , 0 , 1 , & et_all_simple_renames ) ); 
          {
            Scheme_Object * reqs ; 
            BLOCK_SETUP((PUSH(reqs, 0+XfOrM951_COUNT)));
#           define XfOrM954_COUNT (1+XfOrM951_COUNT)
#           define SETUP_XfOrM954(x) SETUP(XfOrM954_COUNT)
            reqs = NULLED_OUT ; 
            reqs = FUNCCALL(SETUP_XfOrM954(_), add_req (imods , env -> genv -> module -> et_requires ) ); 
            env -> genv -> module -> et_requires = reqs ; 
          }
          if (rec [drec ] . comp )
            e = ((void * ) 0 ) ; 
          if (observer ) {
#           define XfOrM953_COUNT (0+XfOrM951_COUNT)
#           define SETUP_XfOrM953(x) SETUP_XfOrM951(x)
            FUNCCALL(SETUP_XfOrM953(_), scheme_call_expand_observe (observer , 7 , e ) ); 
          }
          else {
          }
          ; 
          kind = 0 ; 
        }
        else if (FUNCCALL(SETUP_XfOrM912(_), scheme_stx_module_eq (require_for_template_stx , fst , 0 ) )) {
          Scheme_Object * imods ; 
          BLOCK_SETUP((PUSH(imods, 0+XfOrM912_COUNT)));
#         define XfOrM943_COUNT (1+XfOrM912_COUNT)
#         define SETUP_XfOrM943(x) SETUP(XfOrM943_COUNT)
          imods = NULLED_OUT ; 
          if (observer ) {
#           define XfOrM950_COUNT (0+XfOrM943_COUNT)
#           define SETUP_XfOrM950(x) SETUP_XfOrM943(x)
            FUNCCALL(SETUP_XfOrM950(_), scheme_call_expand_observe (observer , 6 , e ) ); 
          }
          else {
          }
          ; 
          if (observer ) {
#           define XfOrM948_COUNT (0+XfOrM943_COUNT)
#           define SETUP_XfOrM948(x) SETUP_XfOrM943(x)
            FUNCCALL(SETUP_XfOrM948(_), scheme_call_expand_observe (observer , 121 , ((void * ) 0 ) ) ); 
          }
          else {
          }
          ; 
          FUNCCALL(SETUP_XfOrM943(_), scheme_prepare_template_env (env -> genv ) ); 
          imods = FUNCCALL_AGAIN(parse_requires (e , self_modidx , env -> genv -> template_env , tt_rn , post_ex_tt_rn , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , check_require_name , tt_tables , ((void * ) 0 ) , ((void * ) 0 ) , 0 , 0 , redef_modname , 0 , 0 , 1 , & tt_all_simple_renames ) ); 
          {
            Scheme_Object * reqs ; 
            BLOCK_SETUP((PUSH(reqs, 0+XfOrM943_COUNT)));
#           define XfOrM946_COUNT (1+XfOrM943_COUNT)
#           define SETUP_XfOrM946(x) SETUP(XfOrM946_COUNT)
            reqs = NULLED_OUT ; 
            reqs = FUNCCALL(SETUP_XfOrM946(_), add_req (imods , env -> genv -> module -> tt_requires ) ); 
            env -> genv -> module -> tt_requires = reqs ; 
          }
          if (rec [drec ] . comp )
            e = ((void * ) 0 ) ; 
          if (observer ) {
#           define XfOrM945_COUNT (0+XfOrM943_COUNT)
#           define SETUP_XfOrM945(x) SETUP_XfOrM943(x)
            FUNCCALL(SETUP_XfOrM945(_), scheme_call_expand_observe (observer , 7 , e ) ); 
          }
          else {
          }
          ; 
          kind = 0 ; 
        }
        else if (FUNCCALL(SETUP_XfOrM912(_), scheme_stx_module_eq (require_for_label_stx , fst , 0 ) )) {
          Scheme_Object * imods ; 
          BLOCK_SETUP((PUSH(imods, 0+XfOrM912_COUNT)));
#         define XfOrM935_COUNT (1+XfOrM912_COUNT)
#         define SETUP_XfOrM935(x) SETUP(XfOrM935_COUNT)
          imods = NULLED_OUT ; 
          if (observer ) {
#           define XfOrM942_COUNT (0+XfOrM935_COUNT)
#           define SETUP_XfOrM942(x) SETUP_XfOrM935(x)
            FUNCCALL(SETUP_XfOrM942(_), scheme_call_expand_observe (observer , 6 , e ) ); 
          }
          else {
          }
          ; 
          if (observer ) {
#           define XfOrM940_COUNT (0+XfOrM935_COUNT)
#           define SETUP_XfOrM940(x) SETUP_XfOrM935(x)
            FUNCCALL(SETUP_XfOrM940(_), scheme_call_expand_observe (observer , 121 , ((void * ) 0 ) ) ); 
          }
          else {
          }
          ; 
          FUNCCALL(SETUP_XfOrM935(_), scheme_prepare_template_env (env -> genv ) ); 
          imods = FUNCCALL_AGAIN(parse_requires (e , self_modidx , env -> genv -> template_env , dt_rn , post_ex_dt_rn , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , check_require_name , dt_tables , ((void * ) 0 ) , ((void * ) 0 ) , 0 , 0 , redef_modname , 0 , 0 , 1 , & dt_all_simple_renames ) ); 
          {
            Scheme_Object * reqs ; 
            BLOCK_SETUP((PUSH(reqs, 0+XfOrM935_COUNT)));
#           define XfOrM938_COUNT (1+XfOrM935_COUNT)
#           define SETUP_XfOrM938(x) SETUP(XfOrM938_COUNT)
            reqs = NULLED_OUT ; 
            reqs = FUNCCALL(SETUP_XfOrM938(_), add_req (imods , env -> genv -> module -> dt_requires ) ); 
            env -> genv -> module -> dt_requires = reqs ; 
          }
          if (rec [drec ] . comp )
            e = ((void * ) 0 ) ; 
          if (observer ) {
#           define XfOrM937_COUNT (0+XfOrM935_COUNT)
#           define SETUP_XfOrM937(x) SETUP_XfOrM935(x)
            FUNCCALL(SETUP_XfOrM937(_), scheme_call_expand_observe (observer , 7 , e ) ); 
          }
          else {
          }
          ; 
          kind = 0 ; 
        }
        else if (FUNCCALL(SETUP_XfOrM912(_), scheme_stx_module_eq (provide_stx , fst , 0 ) )) {
#         define XfOrM928_COUNT (0+XfOrM912_COUNT)
#         define SETUP_XfOrM928(x) SETUP_XfOrM912(x)
          if (observer ) {
#           define XfOrM934_COUNT (0+XfOrM928_COUNT)
#           define SETUP_XfOrM934(x) SETUP_XfOrM928(x)
            FUNCCALL(SETUP_XfOrM934(_), scheme_call_expand_observe (observer , 6 , e ) ); 
          }
          else {
          }
          ; 
          if (observer ) {
#           define XfOrM932_COUNT (0+XfOrM928_COUNT)
#           define SETUP_XfOrM932(x) SETUP_XfOrM928(x)
            FUNCCALL(SETUP_XfOrM932(_), scheme_call_expand_observe (observer , 122 , ((void * ) 0 ) ) ); 
          }
          else {
          }
          ; 
          reprovided = FUNCCALL(SETUP_XfOrM928(_), parse_provides (form , fst , e , provided , reprovided , self_modidx , & all_defs_out ) ); 
          if (rec [drec ] . comp )
            e = ((void * ) 0 ) ; 
          if (observer ) {
#           define XfOrM930_COUNT (0+XfOrM928_COUNT)
#           define SETUP_XfOrM930(x) SETUP_XfOrM928(x)
            FUNCCALL(SETUP_XfOrM930(_), scheme_call_expand_observe (observer , 7 , e ) ); 
          }
          else {
          }
          ; 
          kind = 0 ; 
        }
        else if (FUNCCALL(SETUP_XfOrM912(_), scheme_stx_module_eq (provide_for_syntax_stx , fst , 0 ) )) {
#         define XfOrM921_COUNT (0+XfOrM912_COUNT)
#         define SETUP_XfOrM921(x) SETUP_XfOrM912(x)
          if (observer ) {
#           define XfOrM927_COUNT (0+XfOrM921_COUNT)
#           define SETUP_XfOrM927(x) SETUP_XfOrM921(x)
            FUNCCALL(SETUP_XfOrM927(_), scheme_call_expand_observe (observer , 6 , e ) ); 
          }
          else {
          }
          ; 
          if (observer ) {
#           define XfOrM925_COUNT (0+XfOrM921_COUNT)
#           define SETUP_XfOrM925(x) SETUP_XfOrM921(x)
            FUNCCALL(SETUP_XfOrM925(_), scheme_call_expand_observe (observer , 122 , ((void * ) 0 ) ) ); 
          }
          else {
          }
          ; 
          et_reprovided = FUNCCALL(SETUP_XfOrM921(_), parse_provides (form , fst , e , et_provided , et_reprovided , self_modidx , & all_et_defs_out ) ); 
          if (rec [drec ] . comp )
            e = ((void * ) 0 ) ; 
          if (observer ) {
#           define XfOrM923_COUNT (0+XfOrM921_COUNT)
#           define SETUP_XfOrM923(x) SETUP_XfOrM921(x)
            FUNCCALL(SETUP_XfOrM923(_), scheme_call_expand_observe (observer , 7 , e ) ); 
          }
          else {
          }
          ; 
          kind = 0 ; 
        }
        else if (FUNCCALL(SETUP_XfOrM912(_), scheme_stx_module_eq (provide_for_label_stx , fst , 0 ) )) {
#         define XfOrM914_COUNT (0+XfOrM912_COUNT)
#         define SETUP_XfOrM914(x) SETUP_XfOrM912(x)
          if (observer ) {
#           define XfOrM920_COUNT (0+XfOrM914_COUNT)
#           define SETUP_XfOrM920(x) SETUP_XfOrM914(x)
            FUNCCALL(SETUP_XfOrM920(_), scheme_call_expand_observe (observer , 6 , e ) ); 
          }
          else {
          }
          ; 
          if (observer ) {
#           define XfOrM918_COUNT (0+XfOrM914_COUNT)
#           define SETUP_XfOrM918(x) SETUP_XfOrM914(x)
            FUNCCALL(SETUP_XfOrM918(_), scheme_call_expand_observe (observer , 122 , ((void * ) 0 ) ) ); 
          }
          else {
          }
          ; 
          dt_reprovided = FUNCCALL(SETUP_XfOrM914(_), parse_provides (form , fst , e , dt_provided , dt_reprovided , self_modidx , ((void * ) 0 ) ) ); 
          if (rec [drec ] . comp )
            e = ((void * ) 0 ) ; 
          if (observer ) {
#           define XfOrM916_COUNT (0+XfOrM914_COUNT)
#           define SETUP_XfOrM916(x) SETUP_XfOrM914(x)
            FUNCCALL(SETUP_XfOrM916(_), scheme_call_expand_observe (observer , 7 , e ) ); 
          }
          else {
          }
          ; 
          kind = 0 ; 
        }
        else {
          kind = 1 ; 
        }
      }
      else kind = 1 ; 
    }
    else kind = 1 ; 
    if (e ) {
#     define XfOrM910_COUNT (0+XfOrM906_COUNT)
#     define SETUP_XfOrM910(x) SETUP_XfOrM906(x)
      p = (__funcarg137 = FUNCCALL(SETUP_XfOrM910(_), scheme_make_pair (e , ((Scheme_Object * ) (void * ) (long ) ((((long ) (kind ) ) << 1 ) | 0x1 ) ) ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg137 , scheme_null ) )) ; 
      if (last )
        (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = p ; 
      else first = p ; 
      last = p ; 
    }
    fm = (((Scheme_Type ) (((((long ) (fm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fm ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (fm ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM906(_), scheme_stx_content (fm ) )) ) -> u . pair_val . cdr ) ) ; 
    if ((((fm ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (fm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fm ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) fm ) -> val ) == (scheme_null ) ) ) ) && maybe_has_lifts ) {
#     define XfOrM907_COUNT (0+XfOrM906_COUNT)
#     define SETUP_XfOrM907(x) SETUP_XfOrM906(x)
      fm = FUNCCALL(SETUP_XfOrM907(_), scheme_frame_get_end_statement_lifts (xenv ) ); 
      fm = FUNCCALL(SETUP_XfOrM907(_), scheme_reverse (fm ) ); 
      if (observer ) {
#       define XfOrM909_COUNT (0+XfOrM907_COUNT)
#       define SETUP_XfOrM909(x) SETUP_XfOrM907(x)
        FUNCCALL(SETUP_XfOrM909(_), scheme_call_expand_observe (observer , 135 , fm ) ); 
      }
      else {
      }
      ; 
      maybe_has_lifts = 0 ; 
    }
  }
  if (observer ) {
#   define XfOrM781_COUNT (0+XfOrM666_COUNT)
#   define SETUP_XfOrM781(x) SETUP_XfOrM666(x)
    FUNCCALL(SETUP_XfOrM781(_), scheme_call_expand_observe (observer , 13 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  if (rec [drec ] . comp ) {
#   define XfOrM779_COUNT (0+XfOrM666_COUNT)
#   define SETUP_XfOrM779(x) SETUP_XfOrM666(x)
    cenv = FUNCCALL(SETUP_XfOrM779(_), scheme_new_comp_env (env -> genv , env -> insp , 1 ) ); 
  }
  else cenv = FUNCCALL(SETUP_XfOrM666(_), scheme_extend_as_toplevel (env ) ); 
  lift_data = FUNCCALL(SETUP_XfOrM666(_), scheme_make_vector (3 , ((void * ) 0 ) ) ); 
  (((Scheme_Vector * ) (lift_data ) ) -> els ) [0 ] = (Scheme_Object * ) cenv ; 
  (((Scheme_Vector * ) (lift_data ) ) -> els ) [1 ] = self_modidx ; 
  (((Scheme_Vector * ) (lift_data ) ) -> els ) [2 ] = rn ; 
  maybe_has_lifts = 0 ; 
  prev_p = ((void * ) 0 ) ; 
  for (p = first ; ! ((p ) == (scheme_null ) ) ; ) {
    Scheme_Object * e , * l , * ll ; 
    int kind ; 
    BLOCK_SETUP((PUSH(e, 0+XfOrM666_COUNT), PUSH(ll, 1+XfOrM666_COUNT), PUSH(l, 2+XfOrM666_COUNT)));
#   define XfOrM757_COUNT (3+XfOrM666_COUNT)
#   define SETUP_XfOrM757(x) SETUP(XfOrM757_COUNT)
    e = NULLED_OUT ; 
    l = NULLED_OUT ; 
    ll = NULLED_OUT ; 
    e = (((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . car ) ; 
    kind = (((long ) ((((Scheme_Simple_Object * ) (e ) ) -> u . pair_val . cdr ) ) ) >> 1 ) ; 
    e = (((Scheme_Simple_Object * ) (e ) ) -> u . pair_val . car ) ; 
    if (observer ) {
#     define XfOrM778_COUNT (0+XfOrM757_COUNT)
#     define SETUP_XfOrM778(x) SETUP_XfOrM757(x)
      FUNCCALL(SETUP_XfOrM778(_), scheme_call_expand_observe (observer , 3 , ((void * ) 0 ) ) ); 
    }
    else {
    }
    ; 
    if (kind ) {
      Scheme_Comp_Env * nenv ; 
      BLOCK_SETUP((PUSH(nenv, 0+XfOrM757_COUNT)));
#     define XfOrM766_COUNT (1+XfOrM757_COUNT)
#     define SETUP_XfOrM766(x) SETUP(XfOrM766_COUNT)
      nenv = NULLED_OUT ; 
      l = (maybe_has_lifts ? FUNCCALL(SETUP_XfOrM766(_), scheme_frame_get_end_statement_lifts (cenv ) ): scheme_null ) ; 
      FUNCCALL(SETUP_XfOrM766(_), scheme_frame_captures_lifts (cenv , add_lifted_defn , lift_data , l , lift_ctx ) ); 
      maybe_has_lifts = 1 ; 
      if (kind == 2 )
        nenv = cenv ; 
      else nenv = FUNCCALL(SETUP_XfOrM766(_), scheme_new_compilation_frame (0 , 0 , cenv , ((void * ) 0 ) ) ); 
      if (rec [drec ] . comp ) {
        Scheme_Compile_Info crec1 ; 
        BLOCK_SETUP((PUSH(crec1.value_name, 0+XfOrM766_COUNT), PUSH(crec1.certs, 1+XfOrM766_COUNT), PUSH(crec1.observer, 2+XfOrM766_COUNT)));
#       define XfOrM776_COUNT (3+XfOrM766_COUNT)
#       define SETUP_XfOrM776(x) SETUP(XfOrM776_COUNT)
        crec1.value_name = NULLED_OUT ; 
        crec1.certs = NULLED_OUT ; 
        crec1.observer = NULLED_OUT ; 
        FUNCCALL(SETUP_XfOrM776(_), scheme_init_compile_recs (rec , drec , & crec1 , 1 ) ); 
        crec1 . resolve_module_ids = 0 ; 
        e = FUNCCALL(SETUP_XfOrM776(_), scheme_compile_expr (e , nenv , & crec1 , 0 ) ); 
      }
      else {
        Scheme_Expand_Info erec1 ; 
        BLOCK_SETUP((PUSH(erec1.value_name, 0+XfOrM766_COUNT), PUSH(erec1.certs, 1+XfOrM766_COUNT), PUSH(erec1.observer, 2+XfOrM766_COUNT)));
#       define XfOrM775_COUNT (3+XfOrM766_COUNT)
#       define SETUP_XfOrM775(x) SETUP(XfOrM775_COUNT)
        erec1.value_name = NULLED_OUT ; 
        erec1.certs = NULLED_OUT ; 
        erec1.observer = NULLED_OUT ; 
        FUNCCALL(SETUP_XfOrM775(_), scheme_init_expand_recs (rec , drec , & erec1 , 1 ) ); 
        erec1 . value_name = scheme_false ; 
        e = FUNCCALL(SETUP_XfOrM775(_), scheme_expand_expr (e , nenv , & erec1 , 0 ) ); 
      }
      l = FUNCCALL(SETUP_XfOrM766(_), scheme_frame_get_lifts (cenv ) ); 
      if (((l ) == (scheme_null ) ) ) {
        (((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . car ) = e ; 
        prev_p = p ; 
        p = (((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . cdr ) ; 
      }
      else {
#       define XfOrM767_COUNT (0+XfOrM766_COUNT)
#       define SETUP_XfOrM767(x) SETUP_XfOrM766(x)
        if (observer ) {
#         define XfOrM773_COUNT (0+XfOrM767_COUNT)
#         define SETUP_XfOrM773(x) SETUP_XfOrM767(x)
          (__funcarg129 = FUNCCALL(SETUP_XfOrM773(_), scheme_copy_list (l ) ), FUNCCALL_AGAIN(scheme_call_expand_observe (observer , 137 , __funcarg129 ) )) ; 
        }
        else {
        }
        ; 
        e = FUNCCALL(SETUP_XfOrM767(_), scheme_make_pair (e , ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) ); 
        (((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . car ) = e ; 
        for (ll = l ; ((Scheme_Type ) (((((long ) (ll ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ll ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; ll = (((Scheme_Simple_Object * ) (ll ) ) -> u . pair_val . cdr ) ) {
#         define XfOrM771_COUNT (0+XfOrM767_COUNT)
#         define SETUP_XfOrM771(x) SETUP_XfOrM767(x)
          e = FUNCCALL(SETUP_XfOrM771(_), scheme_make_pair ((((Scheme_Simple_Object * ) (ll ) ) -> u . pair_val . car ) , ((Scheme_Object * ) (void * ) (long ) ((((long ) (2 ) ) << 1 ) | 0x1 ) ) ) ); 
          (((Scheme_Simple_Object * ) (ll ) ) -> u . pair_val . car ) = e ; 
        }
        p = FUNCCALL(SETUP_XfOrM767(_), scheme_append (l , p ) ); 
        if (prev_p ) {
          (((Scheme_Simple_Object * ) (prev_p ) ) -> u . pair_val . cdr ) = p ; 
        }
        else {
          first = p ; 
        }
      }
    }
    else {
      (((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . car ) = e ; 
      prev_p = p ; 
      p = (((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . cdr ) ; 
    }
    if (((p ) == (scheme_null ) ) && maybe_has_lifts ) {
#     define XfOrM758_COUNT (0+XfOrM757_COUNT)
#     define SETUP_XfOrM758(x) SETUP_XfOrM757(x)
      p = FUNCCALL(SETUP_XfOrM758(_), scheme_frame_get_end_statement_lifts (cenv ) ); 
      if (observer ) {
#       define XfOrM764_COUNT (0+XfOrM758_COUNT)
#       define SETUP_XfOrM764(x) SETUP_XfOrM758(x)
        (__funcarg128 = FUNCCALL(SETUP_XfOrM764(_), scheme_reverse (p ) ), FUNCCALL_AGAIN(scheme_call_expand_observe (observer , 135 , __funcarg128 ) )) ; 
      }
      else {
      }
      ; 
      p = FUNCCALL(SETUP_XfOrM758(_), scheme_reverse (p ) ); 
      for (ll = p ; ((Scheme_Type ) (((((long ) (ll ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ll ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; ll = (((Scheme_Simple_Object * ) (ll ) ) -> u . pair_val . cdr ) ) {
#       define XfOrM762_COUNT (0+XfOrM758_COUNT)
#       define SETUP_XfOrM762(x) SETUP_XfOrM758(x)
        e = FUNCCALL(SETUP_XfOrM762(_), scheme_make_pair ((((Scheme_Simple_Object * ) (ll ) ) -> u . pair_val . car ) , ((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) ) ); 
        (((Scheme_Simple_Object * ) (ll ) ) -> u . pair_val . car ) = e ; 
      }
      maybe_has_lifts = 0 ; 
      if (prev_p ) {
        (((Scheme_Simple_Object * ) (prev_p ) ) -> u . pair_val . cdr ) = p ; 
      }
      else {
        first = p ; 
      }
    }
  }
  et_mn = env -> genv -> exp_env -> marked_names ; 
  if (rec [drec ] . comp ) {
    Scheme_Object * prev = ((void * ) 0 ) , * next ; 
    BLOCK_SETUP((PUSH(prev, 0+XfOrM666_COUNT), PUSH(next, 1+XfOrM666_COUNT)));
#   define XfOrM730_COUNT (2+XfOrM666_COUNT)
#   define SETUP_XfOrM730(x) SETUP(XfOrM730_COUNT)
    next = NULLED_OUT ; 
    for (p = first ; ! ((p ) == (scheme_null ) ) ; p = next ) {
#     define XfOrM733_COUNT (0+XfOrM730_COUNT)
#     define SETUP_XfOrM733(x) SETUP_XfOrM730(x)
      next = (((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . cdr ) ; 
      if (FUNCCALL(SETUP_XfOrM733(_), scheme_omittable_expr ((((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . car ) , 1 ) )) {
        if (prev )
          (((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . cdr ) = next ; 
        else first = next ; 
      }
      else prev = p ; 
    }
  }
  reprovide_kernel = FUNCCALL(SETUP_XfOrM666(_), compute_reprovides (provided , reprovided , env -> genv -> module -> requires , required , env -> genv , all_defs , all_defs_out , & exclude_hint , "require" ) ); 
  (void ) FUNCCALL(SETUP_XfOrM666(_), compute_reprovides (et_provided , et_reprovided , env -> genv -> module -> et_requires , et_required , env -> genv -> exp_env , all_et_defs , all_et_defs_out , ((void * ) 0 ) , "require-for-syntax" ) ); 
  (void ) FUNCCALL(SETUP_XfOrM666(_), compute_reprovides (dt_provided , dt_reprovided , env -> genv -> module -> dt_requires , dt_required , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , "require-for-label" ) ); 
  if ((reprovide_kernel == (kernel -> me -> rt -> num_provides - 1 ) ) && (((exclude_hint ) ) == (scheme_false ) ) ) {
#   define XfOrM729_COUNT (0+XfOrM666_COUNT)
#   define SETUP_XfOrM729(x) SETUP_XfOrM666(x)
    exclude_hint = FUNCCALL(SETUP_XfOrM729(_), scheme_make_pair (module_begin_symbol , scheme_null ) ); 
    exclude_hint = FUNCCALL(SETUP_XfOrM729(_), scheme_datum_to_syntax (exclude_hint , scheme_false , scheme_top_stx , 0 , 0 ) ); 
  }
  if (reprovide_kernel ) {
#   define XfOrM724_COUNT (0+XfOrM666_COUNT)
#   define SETUP_XfOrM724(x) SETUP_XfOrM666(x)
    if ((reprovide_kernel == (kernel -> me -> rt -> num_provides - 1 ) ) && (! (((exclude_hint ) ) == (scheme_false ) ) ) ) {
#     define XfOrM725_COUNT (0+XfOrM724_COUNT)
#     define SETUP_XfOrM725(x) SETUP_XfOrM724(x)
      if ((((Scheme_Type ) (((((long ) (exclude_hint ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (exclude_hint ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (exclude_hint ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (exclude_hint ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) exclude_hint ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) exclude_hint ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) && (((((Scheme_Type ) (((((long ) (exclude_hint ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (exclude_hint ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (exclude_hint ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM725(_), scheme_stx_content (exclude_hint ) )) ) -> u . pair_val . cdr ) ) ) == (scheme_null ) ) ) {
        Scheme_Object * n ; 
        BLOCK_SETUP((PUSH(n, 0+XfOrM725_COUNT)));
#       define XfOrM726_COUNT (1+XfOrM725_COUNT)
#       define SETUP_XfOrM726(x) SETUP(XfOrM726_COUNT)
        n = NULLED_OUT ; 
        exclude_hint = (((Scheme_Type ) (((((long ) (exclude_hint ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (exclude_hint ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (exclude_hint ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM726(_), scheme_stx_content (exclude_hint ) )) ) -> u . pair_val . car ) ) ; 
        exclude_hint = ((Scheme_Stx * ) exclude_hint ) -> val ; 
        n = FUNCCALL(SETUP_XfOrM726(_), scheme_hash_get (provided , exclude_hint ) ); 
        if (n ) {
#         define XfOrM727_COUNT (0+XfOrM726_COUNT)
#         define SETUP_XfOrM727(x) SETUP_XfOrM726(x)
          n = (((Scheme_Simple_Object * ) (n ) ) -> u . pair_val . car ) ; 
          if (((Scheme_Type ) (((((long ) (n ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
            n = FUNCCALL(SETUP_XfOrM727(_), scheme_tl_id_sym (env -> genv , n , ((void * ) 0 ) , 0 ) ); 
          n = FUNCCALL(SETUP_XfOrM727(_), scheme_hash_get (required , n ) ); 
          if (n && ! (((((Scheme_Vector * ) (n ) ) -> els ) [1 ] ) == (kernel_symbol ) ) ) {
          }
          else reprovide_kernel = 0 ; 
        }
        else reprovide_kernel = 0 ; 
      }
      else reprovide_kernel = 0 ; 
    }
    else if (reprovide_kernel != kernel -> me -> rt -> num_provides )
      reprovide_kernel = 0 ; 
    else exclude_hint = scheme_false ; 
  }
  exps = FUNCCALL(SETUP_XfOrM666(_), compute_provide_arrays (provided , required , env -> genv -> module -> me -> rt , env -> genv , 0 , reprovide_kernel , form , "provided identifier not defined or imported" ) ); 
  (void ) FUNCCALL(SETUP_XfOrM666(_), compute_provide_arrays (et_provided , et_required , env -> genv -> module -> me -> et , env -> genv -> exp_env , 1 , 0 , form , "for-syntax provided identifier not defined for syntax or imported for syntax" ) ); 
  (void ) FUNCCALL(SETUP_XfOrM666(_), compute_provide_arrays (dt_provided , dt_required , env -> genv -> module -> me -> dt , ((void * ) 0 ) , 0 , 0 , form , "for-label provided identifier not imported for label" ) ); 
  if (rec [drec ] . comp || (rec [drec ] . depth != - 2 ) ) {
#   define XfOrM723_COUNT (0+XfOrM666_COUNT)
#   define SETUP_XfOrM723(x) SETUP_XfOrM666(x)
    FUNCCALL(SETUP_XfOrM723(_), scheme_clean_dead_env (env -> genv ) ); 
  }
  {
    int i , count , j ; 
    Scheme_Bucket * * bs , * b ; 
    Scheme_Object * * exsns = env -> genv -> module -> me -> rt -> provide_src_names ; 
    int exvcount = env -> genv -> module -> me -> rt -> num_var_provides ; 
    BLOCK_SETUP((PUSH(b, 0+XfOrM666_COUNT), PUSH(exsns, 1+XfOrM666_COUNT), PUSH(bs, 2+XfOrM666_COUNT)));
#   define XfOrM712_COUNT (3+XfOrM666_COUNT)
#   define SETUP_XfOrM712(x) SETUP(XfOrM712_COUNT)
    bs = NULLED_OUT ; 
    b = NULLED_OUT ; 
    bs = env -> genv -> toplevel -> buckets ; 
    for (count = 0 , i = env -> genv -> toplevel -> size ; i -- ; ) {
      b = bs [i ] ; 
      if (b && b -> val )
        count ++ ; 
    }
    exis = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM712(_), GC_malloc (sizeof (Scheme_Object * ) * (count ) ) )) ; 
    for (count = 0 , i = env -> genv -> toplevel -> size ; i -- ; ) {
      b = bs [i ] ; 
      if (b && b -> val ) {
        Scheme_Object * name ; 
        name = NULLED_OUT ; 
        name = (Scheme_Object * ) b -> key ; 
        for (j = 0 ; j < exvcount ; j ++ ) {
          if (((name ) == (exsns [j ] ) ) )
            break ; 
        }
        if (j == exvcount )
          exis [count ++ ] = name ; 
      }
    }
    exicount = count ; 
    FUNCCALL(SETUP_XfOrM712(_), qsort_provides (exis , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , 0 , exicount , 1 ) ); 
  }
  if (! rec [drec ] . comp ) {
    Scheme_Module_Phase_Exports * rt = env -> genv -> module -> me -> rt ; 
    int excount = rt -> num_provides ; 
    int exvcount = rt -> num_var_provides ; 
    Scheme_Object * * exsns = rt -> provide_src_names ; 
    Scheme_Object * * exs = rt -> provides ; 
    Scheme_Object * * exss = rt -> provide_srcs ; 
    int j ; 
    Scheme_Object * e , * a , * result ; 
    BLOCK_SETUP((PUSH(a, 0+XfOrM666_COUNT), PUSH(exs, 1+XfOrM666_COUNT), PUSH(result, 2+XfOrM666_COUNT), PUSH(e, 3+XfOrM666_COUNT), PUSH(exsns, 4+XfOrM666_COUNT), PUSH(exss, 5+XfOrM666_COUNT), PUSH(rt, 6+XfOrM666_COUNT)));
#   define XfOrM676_COUNT (7+XfOrM666_COUNT)
#   define SETUP_XfOrM676(x) SETUP(XfOrM676_COUNT)
    e = NULLED_OUT ; 
    a = NULLED_OUT ; 
    result = NULLED_OUT ; 
    result = scheme_null ; 
    if (reprovide_kernel ) {
#     define XfOrM711_COUNT (0+XfOrM676_COUNT)
#     define SETUP_XfOrM711(x) SETUP_XfOrM676(x)
      if (exclude_hint )
        result = FUNCCALL(SETUP_XfOrM711(_), scheme_make_immutable_pair (exclude_hint , result ) ); 
      else result = FUNCCALL(SETUP_XfOrM711(_), scheme_make_immutable_pair (scheme_true , result ) ); 
    }
    else result = FUNCCALL(SETUP_XfOrM676(_), scheme_make_immutable_pair (scheme_false , result ) ); 
    a = scheme_null ; 
    for (j = 0 ; j < exicount ; j ++ ) {
#     define XfOrM710_COUNT (0+XfOrM676_COUNT)
#     define SETUP_XfOrM710(x) SETUP_XfOrM676(x)
      a = FUNCCALL(SETUP_XfOrM710(_), scheme_make_immutable_pair (exis [j ] , a ) ); 
    }
    result = FUNCCALL(SETUP_XfOrM676(_), scheme_make_immutable_pair (a , result ) ); 
    for (j = 0 ; j < 2 ; j ++ ) {
      int top , i ; 
#     define XfOrM693_COUNT (0+XfOrM676_COUNT)
#     define SETUP_XfOrM693(x) SETUP_XfOrM676(x)
      e = scheme_null ; 
      if (reprovide_kernel ) {
#       define XfOrM702_COUNT (0+XfOrM693_COUNT)
#       define SETUP_XfOrM702(x) SETUP_XfOrM693(x)
        if (! j ) {
          i = kernel -> me -> rt -> num_var_provides ; 
          top = kernel -> me -> rt -> num_provides ; 
        }
        else {
          i = 0 ; 
          top = kernel -> me -> rt -> num_var_provides ; 
        }
        for (; i < top ; i ++ ) {
#         define XfOrM705_COUNT (0+XfOrM702_COUNT)
#         define SETUP_XfOrM705(x) SETUP_XfOrM702(x)
          if (! ((kernel -> me -> rt -> provides [i ] ) == (exclude_hint ) ) ) {
#           define XfOrM706_COUNT (0+XfOrM705_COUNT)
#           define SETUP_XfOrM706(x) SETUP_XfOrM705(x)
            a = FUNCCALL(SETUP_XfOrM706(_), scheme_make_immutable_pair (kernel -> me -> rt -> provides [i ] , kernel -> me -> rt -> provides [i ] ) ); 
            a = FUNCCALL(SETUP_XfOrM706(_), scheme_make_immutable_pair (kernel_symbol , a ) ); 
            e = FUNCCALL_AGAIN(scheme_make_immutable_pair (a , e ) ); 
          }
        }
      }
      if (! j ) {
        i = exvcount ; 
        top = excount ; 
      }
      else {
        i = 0 ; 
        top = exvcount ; 
      }
      for (; i < top ; i ++ ) {
#       define XfOrM697_COUNT (0+XfOrM693_COUNT)
#       define SETUP_XfOrM697(x) SETUP_XfOrM693(x)
        if ((((exss [i ] ) ) == (scheme_false ) ) && ((exs [i ] ) == (exsns [i ] ) ) )
          a = exs [i ] ; 
        else {
#         define XfOrM698_COUNT (0+XfOrM697_COUNT)
#         define SETUP_XfOrM698(x) SETUP_XfOrM697(x)
          a = FUNCCALL(SETUP_XfOrM698(_), scheme_make_immutable_pair (exs [i ] , exsns [i ] ) ); 
          if (! (((exss [i ] ) ) == (scheme_false ) ) ) {
#           define XfOrM699_COUNT (0+XfOrM698_COUNT)
#           define SETUP_XfOrM699(x) SETUP_XfOrM698(x)
            a = FUNCCALL(SETUP_XfOrM699(_), scheme_make_immutable_pair (exss [i ] , a ) ); 
          }
        }
        e = FUNCCALL(SETUP_XfOrM697(_), scheme_make_immutable_pair (a , e ) ); 
      }
      result = FUNCCALL(SETUP_XfOrM693(_), scheme_make_immutable_pair (e , result ) ); 
    }
    env -> genv -> module -> hints = result ; 
  }
  if (rec [drec ] . comp ) {
    Scheme_Object * exp_body_r = scheme_null ; 
    BLOCK_SETUP((PUSH(exp_body_r, 0+XfOrM666_COUNT)));
#   define XfOrM669_COUNT (1+XfOrM666_COUNT)
#   define SETUP_XfOrM669(x) SETUP(XfOrM669_COUNT)
    while (! ((exp_body ) == (scheme_null ) ) ) {
#     define XfOrM675_COUNT (0+XfOrM669_COUNT)
#     define SETUP_XfOrM675(x) SETUP_XfOrM669(x)
      exp_body_r = FUNCCALL(SETUP_XfOrM675(_), scheme_make_pair ((((Scheme_Simple_Object * ) (exp_body ) ) -> u . pair_val . car ) , exp_body_r ) ); 
      exp_body = (((Scheme_Simple_Object * ) (exp_body ) ) -> u . pair_val . cdr ) ; 
    }
    env -> genv -> module -> body = first ; 
    env -> genv -> module -> et_body = exp_body_r ; 
    env -> genv -> module -> provide_protects = exps ; 
    env -> genv -> module -> me -> rt -> reprovide_kernel = reprovide_kernel ; 
    env -> genv -> module -> me -> rt -> kernel_exclusion = exclude_hint ; 
    env -> genv -> module -> indirect_provides = exis ; 
    env -> genv -> module -> num_indirect_provides = exicount ; 
    env -> genv -> module -> comp_prefix = cenv -> prefix ; 
    if (all_simple_renames && (env -> genv -> marked_names -> count == 1 ) ) {
      env -> genv -> module -> rn_stx = scheme_true ; 
    }
    if (et_all_simple_renames && all_simple_renames && (et_mn -> count == 1 ) ) {
      env -> genv -> module -> et_rn_stx = scheme_true ; 
    }
    if (tt_all_simple_renames ) {
      env -> genv -> module -> tt_rn_stx = scheme_true ; 
    }
    if (dt_all_simple_renames && all_simple_renames ) {
      env -> genv -> module -> dt_rn_stx = scheme_true ; 
    }
    RET_VALUE_START ((Scheme_Object * ) env -> genv -> module ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM667_COUNT (0+XfOrM666_COUNT)
#   define SETUP_XfOrM667(x) SETUP_XfOrM666(x)
    if (rec [drec ] . depth == - 2 ) {
#     define XfOrM668_COUNT (0+XfOrM667_COUNT)
#     define SETUP_XfOrM668(x) SETUP_XfOrM667(x)
      FUNCCALL(SETUP_XfOrM668(_), flush_definitions (env -> genv ) ); 
      if (env -> genv -> exp_env )
        FUNCCALL(SETUP_XfOrM668(_), flush_definitions (env -> genv -> exp_env ) ); 
    }
    p = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM667(_), scheme_stx_content (form ) )) ) -> u . pair_val . car ) ) ; 
    RET_VALUE_START ((__funcarg125 = FUNCCALL(SETUP_XfOrM667(_), scheme_make_pair (p , first ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg125 , form , form , 0 , 2 ) )) ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * module_begin_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  /* No conversion */
  return do_module_begin (form , env , rec , drec ) ; 
}
static Scheme_Object * module_begin_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(erec, 0), PUSH(env, 1), PUSH(form, 2)));
# define XfOrM1035_COUNT (3)
# define SETUP_XfOrM1035(x) SETUP(XfOrM1035_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (erec [drec ] . observer ) {
#   define XfOrM1037_COUNT (0+XfOrM1035_COUNT)
#   define SETUP_XfOrM1037(x) SETUP_XfOrM1035(x)
    FUNCCALL(SETUP_XfOrM1037(_), scheme_call_expand_observe (erec [drec ] . observer , 102 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(do_module_begin (form , env , erec , drec ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int compute_reprovides (Scheme_Hash_Table * provided , Scheme_Object * reprovided , Scheme_Object * requires , Scheme_Hash_Table * required , Scheme_Env * genv , Scheme_Object * all_defs , Scheme_Object * all_defs_out , Scheme_Object * * _exclude_hint , const char * matching_form ) {
  int i ; 
  Scheme_Object * rx ; 
  int reprovide_kernel = 0 ; 
  Scheme_Object * __funcarg156 = NULLED_OUT ; 
  Scheme_Object * __funcarg148 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(20);
  BLOCK_SETUP_TOP((PUSH(rx, 0), PUSH(reprovided, 1), PUSH(_exclude_hint, 2), PUSH(genv, 3), PUSH(matching_form, 4), PUSH(all_defs, 5), PUSH(provided, 6), PUSH(required, 7), PUSH(all_defs_out, 8), PUSH(requires, 9)));
# define XfOrM1038_COUNT (10)
# define SETUP_XfOrM1038(x) SETUP(XfOrM1038_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  rx = NULLED_OUT ; 
  for (rx = reprovided ; ! ((rx ) == (scheme_null ) ) ; rx = (((Scheme_Simple_Object * ) (rx ) ) -> u . pair_val . cdr ) ) {
    Scheme_Object * midx = (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (rx ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) , * l , * exns ; 
    BLOCK_SETUP((PUSH(exns, 0+XfOrM1038_COUNT), PUSH(midx, 1+XfOrM1038_COUNT), PUSH(l, 2+XfOrM1038_COUNT)));
#   define XfOrM1148_COUNT (3+XfOrM1038_COUNT)
#   define SETUP_XfOrM1148(x) SETUP(XfOrM1148_COUNT)
    l = NULLED_OUT ; 
    exns = NULLED_OUT ; 
    for (l = requires ; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#     define XfOrM1161_COUNT (0+XfOrM1148_COUNT)
#     define SETUP_XfOrM1161(x) SETUP_XfOrM1148(x)
      if (FUNCCALL(SETUP_XfOrM1161(_), same_modidx (midx , (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ) ))
        break ; 
    }
    if (((l ) == (scheme_null ) ) ) {
      Scheme_Object * name ; 
      BLOCK_SETUP((PUSH(name, 0+XfOrM1148_COUNT)));
#     define XfOrM1159_COUNT (1+XfOrM1148_COUNT)
#     define SETUP_XfOrM1159(x) SETUP(XfOrM1159_COUNT)
      name = NULLED_OUT ; 
      name = (((Scheme_Simple_Object * ) (rx ) ) -> u . pair_val . car ) ; 
      name = (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (name ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1159(_), scheme_stx_content (name ) )) ) -> u . pair_val . cdr ) ) ; 
      name = (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (name ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1159(_), scheme_stx_content (name ) )) ) -> u . pair_val . car ) ) ; 
      FUNCCALL_EMPTY(scheme_wrong_syntax ("module" , ((Scheme_Type ) (((((long ) (midx ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (midx ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ? midx : ((Scheme_Modidx * ) midx ) -> path , name , "cannot provide from a module without a matching `%s'" , matching_form ) ); 
    }
    exns = (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (rx ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ; 
    for (l = exns ; ! (((l ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) l ) -> val ) == (scheme_null ) ) ) ) ; l = (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1148(_), scheme_stx_content (l ) )) ) -> u . pair_val . cdr ) ) ) {
      Scheme_Object * a , * vec ; 
      BLOCK_SETUP((PUSH(vec, 0+XfOrM1148_COUNT), PUSH(a, 1+XfOrM1148_COUNT)));
#     define XfOrM1154_COUNT (2+XfOrM1148_COUNT)
#     define SETUP_XfOrM1154(x) SETUP(XfOrM1154_COUNT)
      a = NULLED_OUT ; 
      vec = NULLED_OUT ; 
      a = ((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1154(_), scheme_stx_content (l ) )) ) -> u . pair_val . car ) ) ) -> val ; 
      vec = FUNCCALL(SETUP_XfOrM1154(_), scheme_hash_get (required , a ) ); 
      if (vec ) {
        Scheme_Object * nml ; 
        BLOCK_SETUP((PUSH(nml, 0+XfOrM1154_COUNT)));
#       define XfOrM1156_COUNT (1+XfOrM1154_COUNT)
#       define SETUP_XfOrM1156(x) SETUP(XfOrM1156_COUNT)
        nml = NULLED_OUT ; 
        nml = (((Scheme_Vector * ) (vec ) ) -> els ) [0 ] ; 
        for (; ((Scheme_Type ) (((((long ) (nml ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (nml ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; nml = (((Scheme_Simple_Object * ) (nml ) ) -> u . pair_val . cdr ) ) {
#         define XfOrM1158_COUNT (0+XfOrM1156_COUNT)
#         define SETUP_XfOrM1158(x) SETUP_XfOrM1156(x)
          if (FUNCCALL(SETUP_XfOrM1158(_), same_modidx ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (rx ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) , (((Scheme_Simple_Object * ) (nml ) ) -> u . pair_val . car ) ) ))
            break ; 
        }
        if (! ((Scheme_Type ) (((((long ) (nml ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (nml ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
          vec = ((void * ) 0 ) ; 
      }
      if (! vec ) {
#       define XfOrM1155_COUNT (0+XfOrM1154_COUNT)
#       define SETUP_XfOrM1155(x) SETUP_XfOrM1154(x)
        a = (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1155(_), scheme_stx_content (l ) )) ) -> u . pair_val . car ) ) ; 
        FUNCCALL_EMPTY(scheme_wrong_syntax ("module" , a , ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (rx ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) , "excluded name was not required from the module" ) ); 
      }
    }
  }
  for (i = required -> size ; i -- ; ) {
#   define XfOrM1106_COUNT (0+XfOrM1038_COUNT)
#   define SETUP_XfOrM1106(x) SETUP_XfOrM1038(x)
    if (required -> vals [i ] ) {
      Scheme_Object * nominal_modidx , * name , * modidx , * srcname , * outname , * nml , * orig_nml ; 
      int break_outer = 0 ; 
      BLOCK_SETUP((PUSH(modidx, 0+XfOrM1106_COUNT), PUSH(nml, 1+XfOrM1106_COUNT), PUSH(srcname, 2+XfOrM1106_COUNT), PUSH(name, 3+XfOrM1106_COUNT), PUSH(outname, 4+XfOrM1106_COUNT), PUSH(nominal_modidx, 5+XfOrM1106_COUNT), PUSH(orig_nml, 6+XfOrM1106_COUNT)));
#     define XfOrM1107_COUNT (7+XfOrM1106_COUNT)
#     define SETUP_XfOrM1107(x) SETUP(XfOrM1107_COUNT)
      nominal_modidx = NULLED_OUT ; 
      name = NULLED_OUT ; 
      modidx = NULLED_OUT ; 
      srcname = NULLED_OUT ; 
      outname = NULLED_OUT ; 
      nml = NULLED_OUT ; 
      orig_nml = NULLED_OUT ; 
      name = required -> keys [i ] ; 
      orig_nml = (((Scheme_Vector * ) (required -> vals [i ] ) ) -> els ) [0 ] ; 
      modidx = (((Scheme_Vector * ) (required -> vals [i ] ) ) -> els ) [1 ] ; 
      srcname = (((Scheme_Vector * ) (required -> vals [i ] ) ) -> els ) [2 ] ; 
      outname = (((Scheme_Vector * ) (required -> vals [i ] ) ) -> els ) [4 ] ; 
      for (rx = reprovided ; ! ((rx ) == (scheme_null ) ) ; rx = (((Scheme_Simple_Object * ) (rx ) ) -> u . pair_val . cdr ) ) {
#       define XfOrM1121_COUNT (0+XfOrM1107_COUNT)
#       define SETUP_XfOrM1121(x) SETUP_XfOrM1107(x)
        for (nml = orig_nml ; ((Scheme_Type ) (((((long ) (nml ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (nml ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; nml = (((Scheme_Simple_Object * ) (nml ) ) -> u . pair_val . cdr ) ) {
#         define XfOrM1128_COUNT (0+XfOrM1121_COUNT)
#         define SETUP_XfOrM1128(x) SETUP_XfOrM1121(x)
          nominal_modidx = (((Scheme_Simple_Object * ) (nml ) ) -> u . pair_val . car ) ; 
          if (FUNCCALL(SETUP_XfOrM1128(_), same_modidx ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (rx ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) , nominal_modidx ) )) {
            Scheme_Object * exns , * ree ; 
            BLOCK_SETUP((PUSH(ree, 0+XfOrM1128_COUNT), PUSH(exns, 1+XfOrM1128_COUNT)));
#           define XfOrM1129_COUNT (2+XfOrM1128_COUNT)
#           define SETUP_XfOrM1129(x) SETUP(XfOrM1129_COUNT)
            exns = NULLED_OUT ; 
            ree = NULLED_OUT ; 
            break_outer = 1 ; 
            ree = (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (rx ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ; 
            exns = (((Scheme_Simple_Object * ) (ree ) ) -> u . pair_val . cdr ) ; 
            if (((modidx ) == (kernel_symbol ) ) )
              if (! (((exns ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (exns ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (exns ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) exns ) -> val ) == (scheme_null ) ) ) ) ) {
              if (_exclude_hint )
                * _exclude_hint = exns ; 
            }
            for (; ! (((exns ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (exns ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (exns ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) exns ) -> val ) == (scheme_null ) ) ) ) ; exns = (((Scheme_Type ) (((((long ) (exns ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (exns ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (exns ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1129(_), scheme_stx_content (exns ) )) ) -> u . pair_val . cdr ) ) ) {
              Scheme_Object * a ; 
              BLOCK_SETUP((PUSH(a, 0+XfOrM1129_COUNT)));
#             define XfOrM1132_COUNT (1+XfOrM1129_COUNT)
#             define SETUP_XfOrM1132(x) SETUP(XfOrM1132_COUNT)
              a = NULLED_OUT ; 
              a = ((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (exns ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (exns ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (exns ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1132(_), scheme_stx_content (exns ) )) ) -> u . pair_val . car ) ) ) -> val ; 
              if (((a ) == (name ) ) )
                break ; 
            }
            if ((((exns ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (exns ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (exns ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) exns ) -> val ) == (scheme_null ) ) ) ) ) {
#             define XfOrM1130_COUNT (0+XfOrM1129_COUNT)
#             define SETUP_XfOrM1130(x) SETUP_XfOrM1129(x)
              if (FUNCCALL(SETUP_XfOrM1130(_), scheme_hash_get (provided , outname ) ))
                FUNCCALL_EMPTY(scheme_wrong_syntax ("module" , outname , (((Scheme_Simple_Object * ) (ree ) ) -> u . pair_val . car ) , "identifier already provided" ) ); 
              (__funcarg156 = FUNCCALL(SETUP_XfOrM1130(_), scheme_make_pair (name , scheme_false ) ), FUNCCALL_AGAIN(scheme_hash_set (provided , outname , __funcarg156 ) )) ; 
              if (((modidx ) == (kernel_symbol ) ) && ((outname ) == (srcname ) ) )
                reprovide_kernel ++ ; 
            }
          }
        }
        if (break_outer )
          break ; 
      }
    }
  }
  if (all_defs_out ) {
#   define XfOrM1039_COUNT (0+XfOrM1038_COUNT)
#   define SETUP_XfOrM1039(x) SETUP_XfOrM1038(x)
    for (; ! ((all_defs_out ) == (scheme_null ) ) ; all_defs_out = (((Scheme_Simple_Object * ) (all_defs_out ) ) -> u . pair_val . cdr ) ) {
      Scheme_Object * exns , * ree , * ree_kw , * exl , * name , * a , * adl , * exname , * pfx ; 
      int protected ; 
      BLOCK_SETUP((PUSH(ree, 0+XfOrM1039_COUNT), PUSH(name, 1+XfOrM1039_COUNT), PUSH(a, 2+XfOrM1039_COUNT), PUSH(exl, 3+XfOrM1039_COUNT), PUSH(adl, 4+XfOrM1039_COUNT), PUSH(pfx, 5+XfOrM1039_COUNT), PUSH(ree_kw, 6+XfOrM1039_COUNT), PUSH(exns, 7+XfOrM1039_COUNT), PUSH(exname, 8+XfOrM1039_COUNT)));
#     define XfOrM1059_COUNT (9+XfOrM1039_COUNT)
#     define SETUP_XfOrM1059(x) SETUP(XfOrM1059_COUNT)
      exns = NULLED_OUT ; 
      ree = NULLED_OUT ; 
      ree_kw = NULLED_OUT ; 
      exl = NULLED_OUT ; 
      name = NULLED_OUT ; 
      a = NULLED_OUT ; 
      adl = NULLED_OUT ; 
      exname = NULLED_OUT ; 
      pfx = NULLED_OUT ; 
      ree = (((Scheme_Simple_Object * ) (all_defs_out ) ) -> u . pair_val . car ) ; 
      protected = (! ((((((Scheme_Simple_Object * ) (ree ) ) -> u . pair_val . cdr ) ) ) == (scheme_false ) ) ) ; 
      ree = (((Scheme_Simple_Object * ) (ree ) ) -> u . pair_val . car ) ; 
      ree_kw = (((Scheme_Simple_Object * ) (ree ) ) -> u . pair_val . car ) ; 
      ree = (((Scheme_Simple_Object * ) (ree ) ) -> u . pair_val . cdr ) ; 
      exl = (((Scheme_Simple_Object * ) (ree ) ) -> u . pair_val . car ) ; 
      pfx = (((Scheme_Simple_Object * ) (ree ) ) -> u . pair_val . cdr ) ; 
      for (exns = exl ; ! (((exns ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (exns ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (exns ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) exns ) -> val ) == (scheme_null ) ) ) ) ; exns = (((Scheme_Type ) (((((long ) (exns ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (exns ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (exns ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1059(_), scheme_stx_content (exns ) )) ) -> u . pair_val . cdr ) ) ) {
#       define XfOrM1076_COUNT (0+XfOrM1059_COUNT)
#       define SETUP_XfOrM1076(x) SETUP_XfOrM1059(x)
        a = (((Scheme_Type ) (((((long ) (exns ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (exns ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (exns ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1076(_), scheme_stx_content (exns ) )) ) -> u . pair_val . car ) ) ; 
        name = FUNCCALL(SETUP_XfOrM1076(_), scheme_tl_id_sym (genv , a , ((void * ) 0 ) , 0 ) ); 
        if (! FUNCCALL(SETUP_XfOrM1076(_), scheme_lookup_in_table (genv -> toplevel , (const char * ) name ) )&& ! FUNCCALL(SETUP_XfOrM1076(_), scheme_lookup_in_table (genv -> syntax , (const char * ) name ) )) {
#         define XfOrM1077_COUNT (0+XfOrM1076_COUNT)
#         define SETUP_XfOrM1077(x) SETUP_XfOrM1076(x)
          FUNCCALL_EMPTY(scheme_wrong_syntax ("module" , a , ree_kw , "excluded identifier was not defined" ) ); 
        }
      }
      for (adl = all_defs ; ((Scheme_Type ) (((((long ) (adl ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (adl ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; adl = (((Scheme_Simple_Object * ) (adl ) ) -> u . pair_val . cdr ) ) {
#       define XfOrM1067_COUNT (0+XfOrM1059_COUNT)
#       define SETUP_XfOrM1067(x) SETUP_XfOrM1059(x)
        name = (((Scheme_Simple_Object * ) (adl ) ) -> u . pair_val . car ) ; 
        exname = (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ? ((Scheme_Stx * ) name ) -> val : name ) ; 
        name = FUNCCALL(SETUP_XfOrM1067(_), scheme_tl_id_sym (genv , name , ((void * ) 0 ) , 0 ) ); 
        for (exns = exl ; ! (((exns ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (exns ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (exns ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) exns ) -> val ) == (scheme_null ) ) ) ) ; exns = (((Scheme_Type ) (((((long ) (exns ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (exns ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (exns ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1067(_), scheme_stx_content (exns ) )) ) -> u . pair_val . cdr ) ) ) {
#         define XfOrM1073_COUNT (0+XfOrM1067_COUNT)
#         define SETUP_XfOrM1073(x) SETUP_XfOrM1067(x)
          a = (((Scheme_Type ) (((((long ) (exns ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (exns ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (exns ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1073(_), scheme_stx_content (exns ) )) ) -> u . pair_val . car ) ) ; 
          a = FUNCCALL(SETUP_XfOrM1073(_), scheme_tl_id_sym (genv , a , ((void * ) 0 ) , 0 ) ); 
          if (((a ) == (name ) ) )
            break ; 
        }
        if ((((exns ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (exns ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (exns ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) exns ) -> val ) == (scheme_null ) ) ) ) ) {
#         define XfOrM1068_COUNT (0+XfOrM1067_COUNT)
#         define SETUP_XfOrM1068(x) SETUP_XfOrM1067(x)
          if (! ((& ((Scheme_Symbol * ) (name ) ) -> iso ) -> so . keyex & 0x1 ) ) {
#           define XfOrM1069_COUNT (0+XfOrM1068_COUNT)
#           define SETUP_XfOrM1069(x) SETUP_XfOrM1068(x)
            a = FUNCCALL(SETUP_XfOrM1069(_), scheme_datum_to_syntax (exname , scheme_false , ree_kw , 0 , 0 ) ); 
            a = FUNCCALL(SETUP_XfOrM1069(_), scheme_tl_id_sym (genv , a , ((void * ) 0 ) , 0 ) ); 
            if (((a ) == (name ) ) ) {
#             define XfOrM1070_COUNT (0+XfOrM1069_COUNT)
#             define SETUP_XfOrM1070(x) SETUP_XfOrM1069(x)
              if ((! (((pfx ) ) == (scheme_false ) ) ) ) {
#               define XfOrM1071_COUNT (0+XfOrM1070_COUNT)
#               define SETUP_XfOrM1071(x) SETUP_XfOrM1070(x)
                exname = FUNCCALL(SETUP_XfOrM1071(_), scheme_symbol_append (pfx , exname ) ); 
              }
              if (FUNCCALL(SETUP_XfOrM1070(_), scheme_hash_get (provided , exname ) ))
                FUNCCALL_EMPTY(scheme_wrong_syntax ("module" , exname , ree_kw , "identifier already provided" ) ); 
              (__funcarg148 = FUNCCALL(SETUP_XfOrM1070(_), scheme_make_pair (name , protected ? scheme_true : scheme_false ) ), FUNCCALL_AGAIN(scheme_hash_set (provided , exname , __funcarg148 ) )) ; 
            }
          }
        }
      }
    }
  }
  RET_VALUE_START (reprovide_kernel ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
char * compute_provide_arrays (Scheme_Hash_Table * provided , Scheme_Hash_Table * required , Scheme_Module_Phase_Exports * pt , Scheme_Env * genv , int def_phase , int reprovide_kernel , Scheme_Object * form , const char * def_way ) {
  int i , count ; 
  Scheme_Object * * exs , * * exsns , * * exss ; 
  char * exps , * exets ; 
  int excount , exvcount ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK(14);
  BLOCK_SETUP_TOP((PUSH(def_way, 0), PUSH(exs, 1), PUSH(genv, 2), PUSH(required, 3), PUSH(exps, 4), PUSH(exets, 5), PUSH(exsns, 6), PUSH(provided, 7), PUSH(exss, 8), PUSH(pt, 9), PUSH(form, 10)));
# define XfOrM1162_COUNT (11)
# define SETUP_XfOrM1162(x) SETUP(XfOrM1162_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  exs = NULLED_OUT ; 
  exsns = NULLED_OUT ; 
  exss = NULLED_OUT ; 
  exps = NULLED_OUT ; 
  exets = NULLED_OUT ; 
  for (count = 0 , i = provided -> size ; i -- ; ) {
    if (provided -> vals [i ] )
      count ++ ; 
  }
  count -= reprovide_kernel ; 
  exs = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM1162(_), GC_malloc (sizeof (Scheme_Object * ) * (count ) ) )) ; 
  exsns = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM1162(_), GC_malloc (sizeof (Scheme_Object * ) * (count ) ) )) ; 
  exss = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM1162(_), GC_malloc (sizeof (Scheme_Object * ) * (count ) ) )) ; 
  exps = ((char * ) FUNCCALL(SETUP_XfOrM1162(_), GC_malloc_atomic (sizeof (char ) * (count ) ) )) ; 
  if (def_phase ) {
#   define XfOrM1206_COUNT (0+XfOrM1162_COUNT)
#   define SETUP_XfOrM1206(x) SETUP_XfOrM1162(x)
    exets = ((char * ) FUNCCALL(SETUP_XfOrM1206(_), GC_malloc_atomic (sizeof (char ) * (count ) ) )) ; 
    (memset (exets , 0 , count ) ) ; 
  }
  else exets = ((void * ) 0 ) ; 
  for (count = 0 , i = provided -> size ; i -- ; ) {
#   define XfOrM1195_COUNT (0+XfOrM1162_COUNT)
#   define SETUP_XfOrM1195(x) SETUP_XfOrM1162(x)
    if (provided -> vals [i ] ) {
      Scheme_Object * name , * prnt_name , * v ; 
      int protected ; 
      BLOCK_SETUP((PUSH(v, 0+XfOrM1195_COUNT), PUSH(prnt_name, 1+XfOrM1195_COUNT), PUSH(name, 2+XfOrM1195_COUNT)));
#     define XfOrM1196_COUNT (3+XfOrM1195_COUNT)
#     define SETUP_XfOrM1196(x) SETUP(XfOrM1196_COUNT)
      name = NULLED_OUT ; 
      prnt_name = NULLED_OUT ; 
      v = NULLED_OUT ; 
      v = provided -> vals [i ] ; 
      name = (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) ; 
      protected = (! ((((((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) ) ) == (scheme_false ) ) ) ; 
      prnt_name = name ; 
      if (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ) {
#       define XfOrM1205_COUNT (0+XfOrM1196_COUNT)
#       define SETUP_XfOrM1205(x) SETUP_XfOrM1196(x)
        if (genv )
          name = FUNCCALL(SETUP_XfOrM1205(_), scheme_tl_id_sym (genv , name , ((void * ) 0 ) , 0 ) ); 
        else name = ((Scheme_Stx * ) name ) -> val ; 
      }
      if (genv && FUNCCALL(SETUP_XfOrM1196(_), scheme_lookup_in_table (genv -> toplevel , (const char * ) name ) )) {
        exs [count ] = provided -> keys [i ] ; 
        exsns [count ] = name ; 
        exss [count ] = scheme_false ; 
        exps [count ] = protected ; 
        if (exets )
          exets [count ] = def_phase ; 
        count ++ ; 
      }
      else if (genv && FUNCCALL(SETUP_XfOrM1196(_), scheme_lookup_in_table (genv -> syntax , (const char * ) name ) )) {
      }
      else if ((v = FUNCCALL(SETUP_XfOrM1196(_), scheme_hash_get (required , name ) )) ) {
#       define XfOrM1198_COUNT (0+XfOrM1196_COUNT)
#       define SETUP_XfOrM1198(x) SETUP_XfOrM1196(x)
        if (protected ) {
#         define XfOrM1202_COUNT (0+XfOrM1198_COUNT)
#         define SETUP_XfOrM1202(x) SETUP_XfOrM1198(x)
          name = (((Scheme_Simple_Object * ) (provided -> vals [i ] ) ) -> u . pair_val . car ) ; 
          FUNCCALL_EMPTY(scheme_wrong_syntax ("module" , ((void * ) 0 ) , name , "cannot protect imported identifier with re-provide" ) ); 
        }
        if ((! ((((((Scheme_Vector * ) (v ) ) -> els ) [3 ] ) ) == (scheme_false ) ) ) ) {
          if (reprovide_kernel && (((((Scheme_Vector * ) (v ) ) -> els ) [1 ] ) == (kernel_symbol ) ) && ((provided -> keys [i ] ) == ((((Scheme_Vector * ) (v ) ) -> els ) [2 ] ) ) ) {
          }
          else {
            exs [count ] = provided -> keys [i ] ; 
            exsns [count ] = (((Scheme_Vector * ) (v ) ) -> els ) [2 ] ; 
            exss [count ] = (((Scheme_Vector * ) (v ) ) -> els ) [1 ] ; 
            exps [count ] = protected ; 
            count ++ ; 
          }
        }
      }
      else {
#       define XfOrM1197_COUNT (0+XfOrM1196_COUNT)
#       define SETUP_XfOrM1197(x) SETUP_XfOrM1196(x)
        FUNCCALL_EMPTY(scheme_wrong_syntax ("module" , prnt_name , form , def_way ) ); 
      }
    }
  }
  exvcount = count ; 
  for (i = provided -> size ; i -- ; ) {
#   define XfOrM1175_COUNT (0+XfOrM1162_COUNT)
#   define SETUP_XfOrM1175(x) SETUP_XfOrM1162(x)
    if (provided -> vals [i ] ) {
      Scheme_Object * name , * v ; 
      int protected ; 
      BLOCK_SETUP((PUSH(v, 0+XfOrM1175_COUNT), PUSH(name, 1+XfOrM1175_COUNT)));
#     define XfOrM1176_COUNT (2+XfOrM1175_COUNT)
#     define SETUP_XfOrM1176(x) SETUP(XfOrM1176_COUNT)
      name = NULLED_OUT ; 
      v = NULLED_OUT ; 
      v = provided -> vals [i ] ; 
      name = (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) ; 
      protected = (! ((((((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) ) ) == (scheme_false ) ) ) ; 
      if (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ) {
#       define XfOrM1182_COUNT (0+XfOrM1176_COUNT)
#       define SETUP_XfOrM1182(x) SETUP_XfOrM1176(x)
        if (genv )
          name = FUNCCALL(SETUP_XfOrM1182(_), scheme_tl_id_sym (genv , name , ((void * ) 0 ) , 0 ) ); 
        else {
          name = ((Scheme_Stx * ) name ) -> val ; 
        }
      }
      if (genv && FUNCCALL(SETUP_XfOrM1176(_), scheme_lookup_in_table (genv -> syntax , (const char * ) name ) )) {
        exs [count ] = provided -> keys [i ] ; 
        exsns [count ] = name ; 
        exss [count ] = scheme_false ; 
        exps [count ] = protected ; 
        if (exets )
          exets [count ] = def_phase ; 
        count ++ ; 
      }
      else if ((v = FUNCCALL(SETUP_XfOrM1176(_), scheme_hash_get (required , name ) )) ) {
        if (((((((Scheme_Vector * ) (v ) ) -> els ) [3 ] ) ) == (scheme_false ) ) ) {
          if (reprovide_kernel && (((((Scheme_Vector * ) (v ) ) -> els ) [1 ] ) == (kernel_symbol ) ) && ((provided -> keys [i ] ) == ((((Scheme_Vector * ) (v ) ) -> els ) [2 ] ) ) ) {
          }
          else {
            exs [count ] = provided -> keys [i ] ; 
            exsns [count ] = (((Scheme_Vector * ) (v ) ) -> els ) [2 ] ; 
            exss [count ] = (((Scheme_Vector * ) (v ) ) -> els ) [1 ] ; 
            exps [count ] = protected ; 
            count ++ ; 
          }
        }
      }
    }
  }
  excount = count ; 
  FUNCCALL(SETUP_XfOrM1162(_), qsort_provides (exs , exsns , exss , exps , exets , 0 , exvcount , 1 ) ); 
  pt -> num_provides = excount ; 
  pt -> num_var_provides = exvcount ; 
  pt -> provides = exs ; 
  pt -> provide_src_names = exsns ; 
  pt -> provide_srcs = exss ; 
  if (exets ) {
    for (i = 0 ; i < excount ; i ++ ) {
      if (exets [i ] )
        break ; 
    }
    if (i >= excount )
      exets = ((void * ) 0 ) ; 
  }
  pt -> provide_src_phases = exets ; 
  RET_VALUE_START (exps ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void qsort_provides (Scheme_Object * * exs , Scheme_Object * * exsns , Scheme_Object * * exss , char * exps , char * exets , int start , int count , int do_uninterned ) {
  int i , j ; 
  Scheme_Object * tmp_ex , * tmp_exsn , * tmp_exs , * pivot ; 
  char tmp_exp , tmp_exet ; 
  PREPARE_VAR_STACK_ONCE(9);
  BLOCK_SETUP_TOP((PUSH(exps, 0), PUSH(exs, 1), PUSH(exss, 2), PUSH(tmp_ex, 3), PUSH(exets, 4), PUSH(exsns, 5), PUSH(pivot, 6), PUSH(tmp_exsn, 7), PUSH(tmp_exs, 8)));
# define XfOrM1209_COUNT (9)
# define SETUP_XfOrM1209(x) SETUP(XfOrM1209_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  tmp_ex = NULLED_OUT ; 
  tmp_exsn = NULLED_OUT ; 
  tmp_exs = NULLED_OUT ; 
  pivot = NULLED_OUT ; 
  if (do_uninterned ) {
#   define XfOrM1232_COUNT (0+XfOrM1209_COUNT)
#   define SETUP_XfOrM1232(x) SETUP_XfOrM1209(x)
    for (j = count ; j -- ; ) {
      if (! ((& ((Scheme_Symbol * ) (exs [j ] ) ) -> iso ) -> so . keyex & 0x3 ) )
        break ; 
    }
    for (i = start ; i < j ; i ++ ) {
      if (((& ((Scheme_Symbol * ) (exs [i ] ) ) -> iso ) -> so . keyex & 0x3 ) ) {
        tmp_ex = exs [i ] ; 
        exs [i ] = exs [j ] ; 
        exs [j ] = tmp_ex ; 
        if (exsns ) {
          tmp_exsn = exsns [i ] ; 
          tmp_exs = exss [i ] ; 
          tmp_exp = exps [i ] ; 
          exsns [i ] = exsns [j ] ; 
          exss [i ] = exss [j ] ; 
          exps [i ] = exps [j ] ; 
          exsns [j ] = tmp_exsn ; 
          exss [j ] = tmp_exs ; 
          exps [j ] = tmp_exp ; 
        }
        if (exets ) {
          tmp_exet = exets [i ] ; 
          exets [i ] = exets [j ] ; 
          exets [j ] = tmp_exet ; 
        }
        j -- ; 
        while (j ) {
          if (! ((& ((Scheme_Symbol * ) (exs [j ] ) ) -> iso ) -> so . keyex & 0x3 ) )
            break ; 
          else j -- ; 
        }
      }
    }
    FUNCCALL(SETUP_XfOrM1232(_), qsort_provides (exs , exsns , exss , exps , exets , 0 , j + 1 , 0 ) ); 
    FUNCCALL(SETUP_XfOrM1232(_), qsort_provides (exs , exsns , exss , exps , exets , j + 1 , count - j - 1 , 0 ) ); 
  }
  else {
#   define XfOrM1210_COUNT (0+XfOrM1209_COUNT)
#   define SETUP_XfOrM1210(x) SETUP_XfOrM1209(x)
    j = start ; 
    while (count > 1 ) {
#     define XfOrM1222_COUNT (0+XfOrM1210_COUNT)
#     define SETUP_XfOrM1222(x) SETUP_XfOrM1210(x)
      j = start ; 
      pivot = exs [j ] ; 
      for (i = 1 ; i < count ; i ++ ) {
        int k = i + start ; 
#       define XfOrM1228_COUNT (0+XfOrM1222_COUNT)
#       define SETUP_XfOrM1228(x) SETUP_XfOrM1222(x)
        if ((strcmp ((((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (exs [k ] ) ) ) -> s ) , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (pivot ) ) ) -> s ) ) ) < 0 ) {
          tmp_ex = exs [k ] ; 
          exs [k ] = exs [j ] ; 
          exs [j ] = tmp_ex ; 
          if (exsns ) {
            tmp_exsn = exsns [k ] ; 
            tmp_exs = exss [k ] ; 
            tmp_exp = exps [k ] ; 
            exsns [k ] = exsns [j ] ; 
            exss [k ] = exss [j ] ; 
            exps [k ] = exps [j ] ; 
            exsns [j ] = tmp_exsn ; 
            exss [j ] = tmp_exs ; 
            exps [j ] = tmp_exp ; 
          }
          if (exets ) {
            tmp_exet = exets [k ] ; 
            exets [k ] = exets [j ] ; 
            exets [j ] = tmp_exet ; 
          }
          j ++ ; 
        }
      }
      if (j == start ) {
        start ++ ; 
        -- count ; 
      }
      else break ; 
    }
    if (count > 1 ) {
#     define XfOrM1211_COUNT (0+XfOrM1210_COUNT)
#     define SETUP_XfOrM1211(x) SETUP_XfOrM1210(x)
      FUNCCALL(SETUP_XfOrM1211(_), qsort_provides (exs , exsns , exss , exps , exets , start , j - start , 0 ) ); 
      FUNCCALL_EMPTY(qsort_provides (exs , exsns , exss , exps , exets , j , count - (j - start ) , 0 ) ); 
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * parse_provides (Scheme_Object * form , Scheme_Object * fst , Scheme_Object * e , Scheme_Hash_Table * provided , Scheme_Object * reprovided , Scheme_Object * self_modidx , Scheme_Object * * _all_defs_out ) {
  Scheme_Object * l ; 
  int protect_cnt = 0 ; 
  Scheme_Object * all_defs_out = (_all_defs_out ? * _all_defs_out : ((void * ) 0 ) ) ; 
  Scheme_Object * __funcarg198 = NULLED_OUT ; 
  Scheme_Object * __funcarg197 = NULLED_OUT ; 
  Scheme_Object * __funcarg196 = NULLED_OUT ; 
  Scheme_Object * __funcarg195 = NULLED_OUT ; 
  Scheme_Object * __funcarg194 = NULLED_OUT ; 
  Scheme_Object * __funcarg193 = NULLED_OUT ; 
  Scheme_Object * __funcarg192 = NULLED_OUT ; 
  Scheme_Object * __funcarg191 = NULLED_OUT ; 
  Scheme_Object * __funcarg190 = NULLED_OUT ; 
  Scheme_Object * __funcarg189 = NULLED_OUT ; 
  Scheme_Object * __funcarg186 = NULLED_OUT ; 
  Scheme_Object * __funcarg185 = NULLED_OUT ; 
  Scheme_Object * __funcarg184 = NULLED_OUT ; 
  Scheme_Object * __funcarg183 = NULLED_OUT ; 
  Scheme_Object * __funcarg182 = NULLED_OUT ; 
  Scheme_Object * __funcarg181 = NULLED_OUT ; 
  Scheme_Object * __funcarg180 = NULLED_OUT ; 
  Scheme_Object * __funcarg179 = NULLED_OUT ; 
  Scheme_Object * __funcarg178 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(19);
  BLOCK_SETUP_TOP((PUSH(reprovided, 0), PUSH(e, 1), PUSH(_all_defs_out, 2), PUSH(self_modidx, 3), PUSH(provided, 4), PUSH(all_defs_out, 5), PUSH(fst, 6), PUSH(form, 7), PUSH(l, 8)));
# define XfOrM1247_COUNT (9)
# define SETUP_XfOrM1247(x) SETUP(XfOrM1247_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  l = NULLED_OUT ; 
  if (FUNCCALL(SETUP_XfOrM1247(_), scheme_stx_proper_list_length (e ) )< 0 )
    FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , e , form , "bad syntax (" "illegal use of `.'" ")" ) ); 
  for (l = (((Scheme_Type ) (((((long ) (e ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (e ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1247(_), scheme_stx_content (e ) )) ) -> u . pair_val . cdr ) ) ; ! (((l ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) l ) -> val ) == (scheme_null ) ) ) ) ; l = (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1247(_), scheme_stx_content (l ) )) ) -> u . pair_val . cdr ) ) ) {
    Scheme_Object * a , * midx , * name ; 
    BLOCK_SETUP((PUSH(midx, 0+XfOrM1247_COUNT), PUSH(a, 1+XfOrM1247_COUNT), PUSH(name, 2+XfOrM1247_COUNT)));
#   define XfOrM1279_COUNT (3+XfOrM1247_COUNT)
#   define SETUP_XfOrM1279(x) SETUP(XfOrM1279_COUNT)
    a = NULLED_OUT ; 
    midx = NULLED_OUT ; 
    name = NULLED_OUT ; 
    a = (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1279(_), scheme_stx_content (l ) )) ) -> u . pair_val . car ) ) ; 
    if ((((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) a ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) a ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) && (FUNCCALL(SETUP_XfOrM1279(_), scheme_stx_proper_list_length (a ) )> 0 ) ) {
#     define XfOrM1308_COUNT (0+XfOrM1279_COUNT)
#     define SETUP_XfOrM1308(x) SETUP_XfOrM1279(x)
      fst = (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1308(_), scheme_stx_content (a ) )) ) -> u . pair_val . car ) ) ; 
      if ((((Scheme_Type ) (((((long ) (fst ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fst ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (fst ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fst ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) fst ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) fst ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) && (((protect_symbol ) == (((Scheme_Stx * ) fst ) -> val ) ) ) ) {
#       define XfOrM1309_COUNT (0+XfOrM1308_COUNT)
#       define SETUP_XfOrM1309(x) SETUP_XfOrM1308(x)
        if (protect_cnt )
          FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , a , e , "bad syntax (nested protect)" ) ); 
        a = (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1309(_), scheme_stx_content (a ) )) ) -> u . pair_val . cdr ) ) ; 
        a = FUNCCALL(SETUP_XfOrM1309(_), scheme_flatten_syntax_list (a , ((void * ) 0 ) ) ); 
        l = (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1309(_), scheme_stx_content (l ) )) ) -> u . pair_val . cdr ) ) ; 
        l = FUNCCALL(SETUP_XfOrM1309(_), scheme_append (a , l ) ); 
        protect_cnt = FUNCCALL_AGAIN(scheme_list_length (a ) ); 
        if ((((l ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) l ) -> val ) == (scheme_null ) ) ) ) )
          break ; 
        a = (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1309(_), scheme_stx_content (l ) )) ) -> u . pair_val . car ) ) ; 
      }
    }
    if ((((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) a ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) a ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) ) {
#     define XfOrM1307_COUNT (0+XfOrM1279_COUNT)
#     define SETUP_XfOrM1307(x) SETUP_XfOrM1279(x)
      name = ((Scheme_Stx * ) a ) -> val ; 
      if (FUNCCALL(SETUP_XfOrM1307(_), scheme_hash_get (provided , name ) ))
        FUNCCALL_EMPTY(scheme_wrong_syntax ("module" , a , form , "identifier already provided" ) ); 
      (__funcarg198 = FUNCCALL(SETUP_XfOrM1307(_), scheme_make_pair (a , protect_cnt ? scheme_true : scheme_false ) ), FUNCCALL_AGAIN(scheme_hash_set (provided , name , __funcarg198 ) )) ; 
    }
    else if ((((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) a ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) a ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
      Scheme_Object * rest ; 
      BLOCK_SETUP((PUSH(rest, 0+XfOrM1279_COUNT)));
#     define XfOrM1281_COUNT (1+XfOrM1279_COUNT)
#     define SETUP_XfOrM1281(x) SETUP(XfOrM1281_COUNT)
      rest = NULLED_OUT ; 
      fst = (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1281(_), scheme_stx_content (a ) )) ) -> u . pair_val . car ) ) ; 
      rest = (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1281(_), scheme_stx_content (a ) )) ) -> u . pair_val . cdr ) ) ; 
      if (((rename_symbol ) == (((Scheme_Stx * ) fst ) -> val ) ) ) {
        Scheme_Object * inm , * enm ; 
        BLOCK_SETUP((PUSH(enm, 0+XfOrM1281_COUNT), PUSH(inm, 1+XfOrM1281_COUNT)));
#       define XfOrM1306_COUNT (2+XfOrM1281_COUNT)
#       define SETUP_XfOrM1306(x) SETUP(XfOrM1306_COUNT)
        inm = NULLED_OUT ; 
        enm = NULLED_OUT ; 
        if (! (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) rest ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) rest ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) || ! (((Scheme_Type ) (((((long ) ((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1306(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1306(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) ((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1306(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1306(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1306(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1306(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
          FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , a , e , "bad syntax" ) ); 
        inm = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1306(_), scheme_stx_content (rest ) )) ) -> u . pair_val . car ) ) ; 
        rest = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1306(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ; 
        enm = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1306(_), scheme_stx_content (rest ) )) ) -> u . pair_val . car ) ) ; 
        if (! (((Scheme_Type ) (((((long ) (inm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (inm ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (inm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (inm ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) inm ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) inm ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) )
          FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , a , e , "bad syntax (internal name is not an identifier)" ) ); 
        if (! (((Scheme_Type ) (((((long ) (enm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (enm ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (enm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (enm ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) enm ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) enm ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) )
          FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , a , e , "bad syntax (external name is not an identifier)" ) ); 
        rest = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1306(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ; 
        if (! (((rest ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) rest ) -> val ) == (scheme_null ) ) ) ) )
          FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , a , e , "bad syntax (data following external name)" ) ); 
        enm = ((Scheme_Stx * ) enm ) -> val ; 
        if (FUNCCALL(SETUP_XfOrM1306(_), scheme_hash_get (provided , enm ) ))
          FUNCCALL_EMPTY(scheme_wrong_syntax ("module" , enm , a , "identifier already provided" ) ); 
        (__funcarg197 = FUNCCALL(SETUP_XfOrM1306(_), scheme_make_pair (inm , protect_cnt ? scheme_true : scheme_false ) ), FUNCCALL_AGAIN(scheme_hash_set (provided , enm , __funcarg197 ) )) ; 
      }
      else if (((all_from_symbol ) == (((Scheme_Stx * ) fst ) -> val ) ) ) {
#       define XfOrM1305_COUNT (0+XfOrM1281_COUNT)
#       define SETUP_XfOrM1305(x) SETUP_XfOrM1281(x)
        if (protect_cnt )
          FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , a , e , "bad syntax (not allowed as protected)" ) ); 
        if (! (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) rest ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) rest ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
          FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , a , e , "bad syntax" ) ); 
        if (! ((((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1305(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) ((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1305(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1305(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1305(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) -> val ) == (scheme_null ) ) ) ) )
          FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , a , e , "bad syntax (data following `all-from')" ) ); 
        midx = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1305(_), scheme_stx_content (rest ) )) ) -> u . pair_val . car ) ) ; 
        midx = (__funcarg196 = FUNCCALL(SETUP_XfOrM1305(_), scheme_syntax_to_datum (midx , 0 , ((void * ) 0 ) ) ), FUNCCALL_AGAIN(scheme_make_modidx (__funcarg196 , self_modidx , scheme_false ) )) ; 
        reprovided = (__funcarg194 = (__funcarg195 = FUNCCALL(SETUP_XfOrM1305(_), scheme_make_pair (e , scheme_null ) ), FUNCCALL_AGAIN(scheme_make_pair (midx , __funcarg195 ) )) , FUNCCALL_AGAIN(scheme_make_pair (__funcarg194 , reprovided ) )) ; 
      }
      else if (((all_from_except_symbol ) == (((Scheme_Stx * ) fst ) -> val ) ) ) {
        Scheme_Object * exns , * el , * p ; 
        int len ; 
        BLOCK_SETUP((PUSH(exns, 0+XfOrM1281_COUNT), PUSH(el, 1+XfOrM1281_COUNT), PUSH(p, 2+XfOrM1281_COUNT)));
#       define XfOrM1300_COUNT (3+XfOrM1281_COUNT)
#       define SETUP_XfOrM1300(x) SETUP(XfOrM1300_COUNT)
        exns = NULLED_OUT ; 
        el = NULLED_OUT ; 
        p = NULLED_OUT ; 
        if (protect_cnt )
          FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , a , e , "bad syntax (not allowed as protected)" ) ); 
        len = FUNCCALL(SETUP_XfOrM1300(_), scheme_stx_proper_list_length (a ) ); 
        if (len < 0 )
          FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , a , e , "bad syntax (" "illegal use of `.'" ")" ) ); 
        else if (len == 1 )
          FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , a , e , "bad syntax (missing module name)" ) ); 
        midx = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1300(_), scheme_stx_content (rest ) )) ) -> u . pair_val . car ) ) ; 
        midx = (__funcarg193 = FUNCCALL(SETUP_XfOrM1300(_), scheme_syntax_to_datum (midx , 0 , ((void * ) 0 ) ) ), FUNCCALL_AGAIN(scheme_make_modidx (__funcarg193 , self_modidx , scheme_false ) )) ; 
        exns = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1300(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ; 
        for (el = exns ; (((Scheme_Type ) (((((long ) (el ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (el ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (el ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (el ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) el ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) el ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ; el = (((Scheme_Type ) (((((long ) (el ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (el ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (el ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1300(_), scheme_stx_content (el ) )) ) -> u . pair_val . cdr ) ) ) {
#         define XfOrM1303_COUNT (0+XfOrM1300_COUNT)
#         define SETUP_XfOrM1303(x) SETUP_XfOrM1300(x)
          p = (((Scheme_Type ) (((((long ) (el ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (el ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (el ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1303(_), scheme_stx_content (el ) )) ) -> u . pair_val . car ) ) ; 
          if (! (((Scheme_Type ) (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) p ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) p ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) ) {
#           define XfOrM1304_COUNT (0+XfOrM1303_COUNT)
#           define SETUP_XfOrM1304(x) SETUP_XfOrM1303(x)
            FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , p , e , "bad syntax (excluded name is not an identifier)" ) ); 
          }
        }
        reprovided = (__funcarg191 = (__funcarg192 = FUNCCALL(SETUP_XfOrM1300(_), scheme_make_pair (e , exns ) ), FUNCCALL_AGAIN(scheme_make_pair (midx , __funcarg192 ) )) , FUNCCALL_AGAIN(scheme_make_pair (__funcarg191 , reprovided ) )) ; 
      }
      else if (((struct_symbol ) == (((Scheme_Stx * ) fst ) -> val ) ) ) {
        int len , i ; 
        Scheme_Object * prnt_base , * base , * fields , * el , * * names , * p ; 
        BLOCK_SETUP((PUSH(base, 0+XfOrM1281_COUNT), PUSH(names, 1+XfOrM1281_COUNT), PUSH(el, 2+XfOrM1281_COUNT), PUSH(prnt_base, 3+XfOrM1281_COUNT), PUSH(fields, 4+XfOrM1281_COUNT), PUSH(p, 5+XfOrM1281_COUNT)));
#       define XfOrM1292_COUNT (6+XfOrM1281_COUNT)
#       define SETUP_XfOrM1292(x) SETUP(XfOrM1292_COUNT)
        prnt_base = NULLED_OUT ; 
        base = NULLED_OUT ; 
        fields = NULLED_OUT ; 
        el = NULLED_OUT ; 
        names = NULLED_OUT ; 
        p = NULLED_OUT ; 
        len = FUNCCALL(SETUP_XfOrM1292(_), scheme_stx_proper_list_length (rest ) ); 
        if (len != 2 ) {
#         define XfOrM1299_COUNT (0+XfOrM1292_COUNT)
#         define SETUP_XfOrM1299(x) SETUP_XfOrM1292(x)
          if (len < 0 )
            FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , a , e , "bad syntax (" "illegal use of `.'" ")" ) ); 
          else FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , a , e , "bad syntax " "(not a struct identifier followed by " "a sequence of field identifiers)" ) ); 
        }
        base = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1292(_), scheme_stx_content (rest ) )) ) -> u . pair_val . car ) ) ; 
        fields = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1292(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ; 
        fields = (((Scheme_Type ) (((((long ) (fields ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (fields ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (fields ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1292(_), scheme_stx_content (fields ) )) ) -> u . pair_val . car ) ) ; 
        if (! (((Scheme_Type ) (((((long ) (base ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (base ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (base ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (base ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) base ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) base ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) )
          FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , base , e , "bad syntax (struct name is not an identifier)" ) ); 
        for (el = fields ; (((Scheme_Type ) (((((long ) (el ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (el ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (el ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (el ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) el ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) el ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ; el = (((Scheme_Type ) (((((long ) (el ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (el ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (el ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1292(_), scheme_stx_content (el ) )) ) -> u . pair_val . cdr ) ) ) {
#         define XfOrM1297_COUNT (0+XfOrM1292_COUNT)
#         define SETUP_XfOrM1297(x) SETUP_XfOrM1292(x)
          p = (((Scheme_Type ) (((((long ) (el ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (el ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (el ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1297(_), scheme_stx_content (el ) )) ) -> u . pair_val . car ) ) ; 
          if (! (((Scheme_Type ) (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) p ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) p ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) ) {
#           define XfOrM1298_COUNT (0+XfOrM1297_COUNT)
#           define SETUP_XfOrM1298(x) SETUP_XfOrM1297(x)
            FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , p , e , "bad syntax (field name is not an identifier)" ) ); 
          }
        }
        if (! (((el ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (el ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (el ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) el ) -> val ) == (scheme_null ) ) ) ) )
          FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , fields , e , "bad syntax (" "illegal use of `.'" ")" ) ); 
        prnt_base = base ; 
        base = ((Scheme_Stx * ) base ) -> val ; 
        fields = FUNCCALL(SETUP_XfOrM1292(_), scheme_syntax_to_datum (fields , 0 , ((void * ) 0 ) ) ); 
        names = FUNCCALL_AGAIN(scheme_make_struct_names (base , fields , 0x80 , & len ) ); 
        for (i = 0 ; i < len ; i ++ ) {
#         define XfOrM1294_COUNT (0+XfOrM1292_COUNT)
#         define SETUP_XfOrM1294(x) SETUP_XfOrM1292(x)
          if (FUNCCALL(SETUP_XfOrM1294(_), scheme_hash_get (provided , names [i ] ) ))
            FUNCCALL_EMPTY(scheme_wrong_syntax ("module" , names [i ] , e , "identifier already provided" ) ); 
          (__funcarg189 = (__funcarg190 = FUNCCALL(SETUP_XfOrM1294(_), scheme_datum_to_syntax (names [i ] , scheme_false , prnt_base , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg190 , protect_cnt ? scheme_true : scheme_false ) )) , FUNCCALL_AGAIN(scheme_hash_set (provided , names [i ] , __funcarg189 ) )) ; 
        }
      }
      else if (((all_defined_symbol ) == (((Scheme_Stx * ) fst ) -> val ) ) ) {
#       define XfOrM1291_COUNT (0+XfOrM1281_COUNT)
#       define SETUP_XfOrM1291(x) SETUP_XfOrM1281(x)
        if (! (((rest ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) rest ) -> val ) == (scheme_null ) ) ) ) )
          FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , a , e , "bad syntax" ) ); 
        all_defs_out = (__funcarg184 = (__funcarg185 = (__funcarg186 = FUNCCALL(SETUP_XfOrM1291(_), scheme_make_pair (scheme_null , scheme_false ) ), FUNCCALL_AGAIN(scheme_make_pair (e , __funcarg186 ) )) , FUNCCALL_AGAIN(scheme_make_pair (__funcarg185 , protect_cnt ? scheme_true : scheme_false ) )) , FUNCCALL_AGAIN(scheme_make_pair (__funcarg184 , all_defs_out ) )) ; 
      }
      else if (((prefix_all_defined_symbol ) == (((Scheme_Stx * ) fst ) -> val ) ) ) {
        Scheme_Object * prefix ; 
        BLOCK_SETUP((PUSH(prefix, 0+XfOrM1281_COUNT)));
#       define XfOrM1289_COUNT (1+XfOrM1281_COUNT)
#       define SETUP_XfOrM1289(x) SETUP(XfOrM1289_COUNT)
        prefix = NULLED_OUT ; 
        if (! (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) rest ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) rest ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
          FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , a , e , "bad syntax" ) ); 
        prefix = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1289(_), scheme_stx_content (rest ) )) ) -> u . pair_val . car ) ) ; 
        rest = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1289(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ; 
        if (! (((rest ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) rest ) -> val ) == (scheme_null ) ) ) ) )
          FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , a , e , "bad syntax" ) ); 
        if (! (((Scheme_Type ) (((((long ) (prefix ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (prefix ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (prefix ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (prefix ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) prefix ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) prefix ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) ) {
#         define XfOrM1290_COUNT (0+XfOrM1289_COUNT)
#         define SETUP_XfOrM1290(x) SETUP_XfOrM1289(x)
          FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , a , e , "bad syntax (prefix is not an identifier)" ) ); 
        }
        prefix = ((Scheme_Stx * ) prefix ) -> val ; 
        all_defs_out = (__funcarg181 = (__funcarg182 = (__funcarg183 = FUNCCALL(SETUP_XfOrM1289(_), scheme_make_pair (scheme_null , prefix ) ), FUNCCALL_AGAIN(scheme_make_pair (e , __funcarg183 ) )) , FUNCCALL_AGAIN(scheme_make_pair (__funcarg182 , protect_cnt ? scheme_true : scheme_false ) )) , FUNCCALL_AGAIN(scheme_make_pair (__funcarg181 , all_defs_out ) )) ; 
      }
      else if (((all_defined_except_symbol ) == (((Scheme_Stx * ) fst ) -> val ) ) || ((prefix_all_defined_except_symbol ) == (((Scheme_Stx * ) fst ) -> val ) ) ) {
        Scheme_Object * exns , * el , * prefix = scheme_false , * p ; 
        int len , is_prefix ; 
        BLOCK_SETUP((PUSH(exns, 0+XfOrM1281_COUNT), PUSH(prefix, 1+XfOrM1281_COUNT), PUSH(el, 2+XfOrM1281_COUNT), PUSH(p, 3+XfOrM1281_COUNT)));
#       define XfOrM1283_COUNT (4+XfOrM1281_COUNT)
#       define SETUP_XfOrM1283(x) SETUP(XfOrM1283_COUNT)
        exns = NULLED_OUT ; 
        el = NULLED_OUT ; 
        p = NULLED_OUT ; 
        is_prefix = ((prefix_all_defined_except_symbol ) == (((Scheme_Stx * ) fst ) -> val ) ) ; 
        len = FUNCCALL(SETUP_XfOrM1283(_), scheme_stx_proper_list_length (a ) ); 
        if (len < 0 )
          FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , a , e , "bad syntax (" "illegal use of `.'" ")" ) ); 
        if (is_prefix && (len < 2 ) )
          FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , a , e , "bad syntax (missing prefix)" ) ); 
        if (is_prefix ) {
#         define XfOrM1288_COUNT (0+XfOrM1283_COUNT)
#         define SETUP_XfOrM1288(x) SETUP_XfOrM1283(x)
          prefix = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1288(_), scheme_stx_content (rest ) )) ) -> u . pair_val . car ) ) ; 
          if (! (((Scheme_Type ) (((((long ) (prefix ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (prefix ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (prefix ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (prefix ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) prefix ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) prefix ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) )
            FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , a , e , "bad syntax (prefix is not an identifier)" ) ); 
          prefix = ((Scheme_Stx * ) prefix ) -> val ; 
          rest = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1288(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ; 
        }
        exns = rest ; 
        for (el = exns ; (((Scheme_Type ) (((((long ) (el ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (el ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (el ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (el ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) el ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) el ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ; el = (((Scheme_Type ) (((((long ) (el ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (el ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (el ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1283(_), scheme_stx_content (el ) )) ) -> u . pair_val . cdr ) ) ) {
#         define XfOrM1286_COUNT (0+XfOrM1283_COUNT)
#         define SETUP_XfOrM1286(x) SETUP_XfOrM1283(x)
          p = (((Scheme_Type ) (((((long ) (el ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (el ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (el ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1286(_), scheme_stx_content (el ) )) ) -> u . pair_val . car ) ) ; 
          if (! (((Scheme_Type ) (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) p ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) p ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) ) {
#           define XfOrM1287_COUNT (0+XfOrM1286_COUNT)
#           define SETUP_XfOrM1287(x) SETUP_XfOrM1286(x)
            FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , p , e , "bad syntax (excluded name is not an identifier)" ) ); 
          }
        }
        all_defs_out = (__funcarg178 = (__funcarg179 = (__funcarg180 = FUNCCALL(SETUP_XfOrM1283(_), scheme_make_pair (exns , prefix ) ), FUNCCALL_AGAIN(scheme_make_pair (e , __funcarg180 ) )) , FUNCCALL_AGAIN(scheme_make_pair (__funcarg179 , protect_cnt ? scheme_true : scheme_false ) )) , FUNCCALL_AGAIN(scheme_make_pair (__funcarg178 , all_defs_out ) )) ; 
      }
      else {
#       define XfOrM1282_COUNT (0+XfOrM1281_COUNT)
#       define SETUP_XfOrM1282(x) SETUP_XfOrM1281(x)
        FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , a , e , ((void * ) 0 ) ) ); 
      }
    }
    else {
#     define XfOrM1280_COUNT (0+XfOrM1279_COUNT)
#     define SETUP_XfOrM1280(x) SETUP_XfOrM1279(x)
      FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , a , e , ((void * ) 0 ) ) ); 
    }
    if (protect_cnt )
      -- protect_cnt ; 
  }
  if (_all_defs_out )
    * _all_defs_out = all_defs_out ; 
  RET_VALUE_START (reprovided ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void add_single_require (Scheme_Module_Exports * me , int base_k , Scheme_Object * idx , Scheme_Env * orig_env , Scheme_Object * rt_rn , Scheme_Object * post_ex_rt_rn , Scheme_Object * et_rn , Scheme_Object * post_ex_et_rn , Scheme_Object * dt_rn , Scheme_Object * post_ex_dt_rn , Scheme_Object * exns , Scheme_Hash_Table * onlys , Scheme_Object * prefix , Scheme_Object * iname , Scheme_Object * orig_ename , Scheme_Object * mark_src , int unpack_kern , int copy_vars , int for_unmarshal , int can_save_marshal , int * all_simple , Check_Func ck , void * rt_data , void * et_data , void * dt_data , Scheme_Object * form , Scheme_Object * err_src , Scheme_Object * cki ) {
  int j , var_count ; 
  Scheme_Object * orig_idx = idx ; 
  Scheme_Object * * exs , * * exsns , * * exss ; 
  char * exets ; 
  void * data ; 
  int is_kern , has_context , save_marshal_info = 0 ; 
  Scheme_Object * nominal_modidx , * one_exn , * prnt_iname , * name , * rn , * post_ex_rn , * ename = orig_ename ; 
  Scheme_Hash_Table * orig_onlys ; 
  Scheme_Env * env ; 
  int k ; 
  Scheme_Object * __funcarg202 = NULLED_OUT ; 
  Scheme_Object * __funcarg201 = NULLED_OUT ; 
  PREPARE_VAR_STACK(41);
  BLOCK_SETUP_TOP((PUSH(exns, 0), PUSH(all_simple, 1), PUSH(prefix, 2), PUSH(onlys, 3), PUSH(ename, 4), PUSH(iname, 5), PUSH(data, 6), PUSH(et_rn, 7), PUSH(exs, 8), PUSH(post_ex_dt_rn, 9), PUSH(cki, 10), PUSH(orig_env, 11), PUSH(err_src, 12), PUSH(nominal_modidx, 13), PUSH(orig_idx, 14), PUSH(prnt_iname, 15), PUSH(dt_rn, 16), PUSH(rn, 17), PUSH(idx, 18), PUSH(rt_data, 19), PUSH(post_ex_rn, 20), PUSH(exsns, 21), PUSH(exss, 22), PUSH(post_ex_et_rn, 23), PUSH(rt_rn, 24), PUSH(me, 25), PUSH(orig_onlys, 26), PUSH(orig_ename, 27), PUSH(one_exn, 28), PUSH(env, 29), PUSH(name, 30), PUSH(exets, 31), PUSH(post_ex_rt_rn, 32), PUSH(et_data, 33), PUSH(form, 34), PUSH(mark_src, 35), PUSH(dt_data, 36)));
# define XfOrM1310_COUNT (37)
# define SETUP_XfOrM1310(x) SETUP(XfOrM1310_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  exs = NULLED_OUT ; 
  exsns = NULLED_OUT ; 
  exss = NULLED_OUT ; 
  exets = NULLED_OUT ; 
  data = NULLED_OUT ; 
  nominal_modidx = NULLED_OUT ; 
  one_exn = NULLED_OUT ; 
  prnt_iname = NULLED_OUT ; 
  name = NULLED_OUT ; 
  rn = NULLED_OUT ; 
  post_ex_rn = NULLED_OUT ; 
  orig_onlys = NULLED_OUT ; 
  env = NULLED_OUT ; 
  if (mark_src ) {
    Scheme_Object * l ; 
    BLOCK_SETUP((PUSH(l, 0+XfOrM1310_COUNT)));
#   define XfOrM1454_COUNT (1+XfOrM1310_COUNT)
#   define SETUP_XfOrM1454(x) SETUP(XfOrM1454_COUNT)
    l = NULLED_OUT ; 
    l = FUNCCALL(SETUP_XfOrM1454(_), scheme_stx_extract_marks (mark_src ) ); 
    has_context = ! ((l ) == (scheme_null ) ) ; 
    if (has_context ) {
      if (all_simple )
        * all_simple = 0 ; 
    }
  }
  else has_context = 0 ; 
  if (iname || ename || onlys || for_unmarshal || unpack_kern || has_context )
    can_save_marshal = 0 ; 
  if (onlys )
    orig_onlys = FUNCCALL(SETUP_XfOrM1310(_), scheme_clone_hash_table (onlys ) ); 
  else orig_onlys = ((void * ) 0 ) ; 
  for (k = 0 ; k < (et_rn ? 3 : 1 ) ; k ++ ) {
    Scheme_Module_Phase_Exports * pt ; 
    BLOCK_SETUP((PUSH(pt, 0+XfOrM1310_COUNT)));
#   define XfOrM1383_COUNT (1+XfOrM1310_COUNT)
#   define SETUP_XfOrM1383(x) SETUP(XfOrM1383_COUNT)
    pt = NULLED_OUT ; 
    switch (k ) {
      case 0 : switch (base_k ) {
        case 0 : pt = me -> rt ; 
        break ; 
        case 1 : pt = me -> et ; 
        break ; 
        case 2 : default : pt = me -> dt ; 
        break ; 
      }
      env = orig_env ; 
      rn = rt_rn ; 
      post_ex_rn = post_ex_rt_rn ; 
      data = rt_data ; 
      break ; 
      case 1 : pt = me -> et ; 
      env = orig_env -> exp_env ; 
      rn = et_rn ; 
      post_ex_rn = post_ex_et_rn ; 
      data = et_data ; 
      break ; 
      case 2 : default : pt = me -> dt ; 
      env = orig_env ; 
      rn = dt_rn ; 
      post_ex_rn = post_ex_dt_rn ; 
      data = dt_data ; 
      break ; 
    }
    is_kern = (((idx ) == (kernel_symbol ) ) && ! exns && ! onlys && ! prefix && ! iname && ! unpack_kern && ! has_context ) ; 
    one_exn = ((void * ) 0 ) ; 
    nominal_modidx = idx ; 
    while (1 ) {
      int break_if_iname_null = ! ! iname ; 
#     define XfOrM1420_COUNT (0+XfOrM1383_COUNT)
#     define SETUP_XfOrM1420(x) SETUP_XfOrM1383(x)
      exs = pt -> provides ; 
      exsns = pt -> provide_src_names ; 
      exss = pt -> provide_srcs ; 
      exets = pt -> provide_src_phases ; 
      var_count = pt -> num_var_provides ; 
      for (j = pt -> num_provides ; j -- ; ) {
        Scheme_Object * modidx ; 
        BLOCK_SETUP((PUSH(modidx, 0+XfOrM1420_COUNT)));
#       define XfOrM1437_COUNT (1+XfOrM1420_COUNT)
#       define SETUP_XfOrM1437(x) SETUP(XfOrM1437_COUNT)
        modidx = NULLED_OUT ; 
        if (orig_ename ) {
          if (! ((((Scheme_Stx * ) orig_ename ) -> val ) == (exs [j ] ) ) )
            continue ; 
        }
        else if (onlys ) {
#         define XfOrM1449_COUNT (0+XfOrM1437_COUNT)
#         define SETUP_XfOrM1449(x) SETUP_XfOrM1437(x)
          name = FUNCCALL(SETUP_XfOrM1449(_), scheme_hash_get (orig_onlys , exs [j ] ) ); 
          if (! name )
            continue ; 
          mark_src = name ; 
          {
            Scheme_Object * l ; 
            BLOCK_SETUP((PUSH(l, 0+XfOrM1449_COUNT)));
#           define XfOrM1450_COUNT (1+XfOrM1449_COUNT)
#           define SETUP_XfOrM1450(x) SETUP(XfOrM1450_COUNT)
            l = NULLED_OUT ; 
            l = FUNCCALL(SETUP_XfOrM1450(_), scheme_stx_extract_marks (mark_src ) ); 
            has_context = ! ((l ) == (scheme_null ) ) ; 
          }
          FUNCCALL(SETUP_XfOrM1449(_), scheme_hash_set (onlys , exs [j ] , ((void * ) 0 ) ) ); 
        }
        else {
#         define XfOrM1444_COUNT (0+XfOrM1437_COUNT)
#         define SETUP_XfOrM1444(x) SETUP_XfOrM1437(x)
          if (exns ) {
            Scheme_Object * l , * a ; 
            BLOCK_SETUP((PUSH(a, 0+XfOrM1444_COUNT), PUSH(l, 1+XfOrM1444_COUNT)));
#           define XfOrM1446_COUNT (2+XfOrM1444_COUNT)
#           define SETUP_XfOrM1446(x) SETUP(XfOrM1446_COUNT)
            l = NULLED_OUT ; 
            a = NULLED_OUT ; 
            for (l = exns ; (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) l ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) l ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ; l = (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1446(_), scheme_stx_content (l ) )) ) -> u . pair_val . cdr ) ) ) {
#             define XfOrM1448_COUNT (0+XfOrM1446_COUNT)
#             define SETUP_XfOrM1448(x) SETUP_XfOrM1446(x)
              a = (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1448(_), scheme_stx_content (l ) )) ) -> u . pair_val . car ) ) ; 
              if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
                a = ((Scheme_Stx * ) a ) -> val ; 
              if (((a ) == (exs [j ] ) ) )
                break ; 
            }
            if (! (((l ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) l ) -> val ) == (scheme_null ) ) ) ) )
              continue ; 
          }
          if (one_exn ) {
            if (((one_exn ) == (exs [j ] ) ) )
              continue ; 
          }
        }
        modidx = ((exss && ! (((exss [j ] ) ) == (scheme_false ) ) ) ? FUNCCALL(SETUP_XfOrM1437(_), scheme_modidx_shift (exss [j ] , me -> src_modidx , idx ) ): idx ) ; 
        if (! iname )
          iname = exs [j ] ; 
        if (((& ((Scheme_Symbol * ) (iname ) ) -> iso ) -> so . keyex & 0x3 ) ) {
          iname = ((void * ) 0 ) ; 
          continue ; 
        }
        if (prefix )
          iname = FUNCCALL(SETUP_XfOrM1437(_), scheme_symbol_append (prefix , iname ) ); 
        prnt_iname = iname ; 
        if (has_context ) {
#         define XfOrM1442_COUNT (0+XfOrM1437_COUNT)
#         define SETUP_XfOrM1442(x) SETUP_XfOrM1437(x)
          iname = FUNCCALL(SETUP_XfOrM1442(_), scheme_datum_to_syntax (iname , scheme_false , mark_src , 0 , 0 ) ); 
          iname = FUNCCALL(SETUP_XfOrM1442(_), scheme_tl_id_sym (env , iname , scheme_false , 2 ) ); 
        }
        if (ck )
          FUNCCALL(SETUP_XfOrM1437(_), ck (prnt_iname , iname , nominal_modidx , modidx , exsns [j ] , (j < var_count ) , data , cki , form , err_src ) ); 
        if (! is_kern ) {
#         define XfOrM1439_COUNT (0+XfOrM1437_COUNT)
#         define SETUP_XfOrM1439(x) SETUP_XfOrM1437(x)
          if (copy_vars && (j < var_count ) && ! env -> module && ! env -> phase && ! k ) {
            Scheme_Env * menv ; 
            Scheme_Object * val ; 
            BLOCK_SETUP((PUSH(val, 0+XfOrM1439_COUNT), PUSH(menv, 1+XfOrM1439_COUNT)));
#           define XfOrM1441_COUNT (2+XfOrM1439_COUNT)
#           define SETUP_XfOrM1441(x) SETUP(XfOrM1441_COUNT)
            menv = NULLED_OUT ; 
            val = NULLED_OUT ; 
            modidx = FUNCCALL(SETUP_XfOrM1441(_), scheme_module_resolve (modidx , 1 ) ); 
            menv = FUNCCALL_AGAIN(scheme_module_access (modidx , env , 0 ) ); 
            val = FUNCCALL_AGAIN(scheme_lookup_in_table (menv -> toplevel , (char * ) exsns [j ] ) ); 
            FUNCCALL_AGAIN(scheme_add_global_symbol (iname , val , env ) ); 
            FUNCCALL_AGAIN(scheme_shadow (env , iname , 1 ) ); 
          }
          else if (! for_unmarshal || ! has_context ) {
#           define XfOrM1440_COUNT (0+XfOrM1439_COUNT)
#           define SETUP_XfOrM1440(x) SETUP_XfOrM1439(x)
            if (! save_marshal_info && ! has_context && can_save_marshal )
              save_marshal_info = 1 ; 
            FUNCCALL(SETUP_XfOrM1440(_), scheme_extend_module_rename ((has_context ? post_ex_rn : rn ) , modidx , iname , exsns [j ] , nominal_modidx , exs [j ] , exets ? exets [j ] : 0 , for_unmarshal || (! has_context && can_save_marshal ) ) ); 
          }
        }
        iname = ((void * ) 0 ) ; 
        if (ename ) {
          ename = ((void * ) 0 ) ; 
          break ; 
        }
      }
      if (is_kern )
        FUNCCALL(SETUP_XfOrM1420(_), scheme_extend_module_rename_with_kernel (rn , nominal_modidx ) ); 
      if (break_if_iname_null && ! iname )
        break ; 
      if (pt -> reprovide_kernel ) {
        idx = kernel_symbol ; 
        one_exn = pt -> kernel_exclusion ; 
        me = kernel -> me ; 
        pt = kernel -> me -> rt ; 
        is_kern = ! prefix && ! unpack_kern && ! ename && ! has_context && ! onlys ; 
      }
      else break ; 
    }
    if (save_marshal_info ) {
      Scheme_Object * info , * a ; 
      BLOCK_SETUP((PUSH(a, 0+XfOrM1383_COUNT), PUSH(info, 1+XfOrM1383_COUNT)));
#     define XfOrM1384_COUNT (2+XfOrM1383_COUNT)
#     define SETUP_XfOrM1384(x) SETUP(XfOrM1384_COUNT)
      info = NULLED_OUT ; 
      a = NULLED_OUT ; 
      if (exns ) {
#       define XfOrM1385_COUNT (0+XfOrM1384_COUNT)
#       define SETUP_XfOrM1385(x) SETUP_XfOrM1384(x)
        info = scheme_null ; 
        for (; (((Scheme_Type ) (((((long ) (exns ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (exns ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (exns ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (exns ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) exns ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) exns ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ; exns = (((Scheme_Type ) (((((long ) (exns ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (exns ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (exns ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1385(_), scheme_stx_content (exns ) )) ) -> u . pair_val . cdr ) ) ) {
#         define XfOrM1387_COUNT (0+XfOrM1385_COUNT)
#         define SETUP_XfOrM1387(x) SETUP_XfOrM1385(x)
          a = (((Scheme_Type ) (((((long ) (exns ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (exns ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (exns ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1387(_), scheme_stx_content (exns ) )) ) -> u . pair_val . car ) ) ; 
          if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
            a = ((Scheme_Stx * ) a ) -> val ; 
          info = FUNCCALL(SETUP_XfOrM1387(_), scheme_make_pair (a , info ) ); 
        }
        exns = info ; 
      }
      else exns = scheme_null ; 
      info = (__funcarg201 = (__funcarg202 = FUNCCALL(SETUP_XfOrM1384(_), scheme_make_pair (exns , prefix ? prefix : scheme_false ) ), FUNCCALL_AGAIN(scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (k + base_k ) ) << 1 ) | 0x1 ) ) , __funcarg202 ) )) , FUNCCALL_AGAIN(scheme_make_pair (orig_idx , __funcarg201 ) )) ; 
      FUNCCALL_AGAIN(scheme_save_module_rename_unmarshal (rn , info ) ); 
      save_marshal_info = 0 ; 
    }
  }
  if (ename ) {
#   define XfOrM1311_COUNT (0+XfOrM1310_COUNT)
#   define SETUP_XfOrM1311(x) SETUP_XfOrM1310(x)
    FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , ename , form , "no such provided variable" ) ); 
    RET_NOTHING ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_do_module_rename_unmarshal (Scheme_Object * rn , Scheme_Object * info , Scheme_Object * modidx_shift_from , Scheme_Object * modidx_shift_to , Scheme_Hash_Table * export_registry ) {
  Scheme_Object * orig_idx , * exns , * prefix , * idx , * name , * kv ; 
  Scheme_Module_Exports * me ; 
  Scheme_Env * env ; 
  Scheme_Config * __funcarg204 = NULLED_OUT ; 
  const char * __funcarg203 = NULLED_OUT ; 
  PREPARE_VAR_STACK_ONCE(10);
  BLOCK_SETUP_TOP((PUSH(exns, 0), PUSH(kv, 1), PUSH(rn, 2), PUSH(name, 3), PUSH(prefix, 4), PUSH(me, 5), PUSH(idx, 6), PUSH(export_registry, 7), PUSH(orig_idx, 8), PUSH(env, 9)));
# define XfOrM1456_COUNT (10)
# define SETUP_XfOrM1456(x) SETUP(XfOrM1456_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  orig_idx = NULLED_OUT ; 
  exns = NULLED_OUT ; 
  prefix = NULLED_OUT ; 
  idx = NULLED_OUT ; 
  name = NULLED_OUT ; 
  kv = NULLED_OUT ; 
  me = NULLED_OUT ; 
  env = NULLED_OUT ; 
  idx = (((Scheme_Simple_Object * ) (info ) ) -> u . pair_val . car ) ; 
  orig_idx = idx ; 
  info = (((Scheme_Simple_Object * ) (info ) ) -> u . pair_val . cdr ) ; 
  kv = (((Scheme_Simple_Object * ) (info ) ) -> u . pair_val . car ) ; 
  info = (((Scheme_Simple_Object * ) (info ) ) -> u . pair_val . cdr ) ; 
  exns = (((Scheme_Simple_Object * ) (info ) ) -> u . pair_val . car ) ; 
  prefix = (((Scheme_Simple_Object * ) (info ) ) -> u . pair_val . cdr ) ; 
  if ((((prefix ) ) == (scheme_false ) ) )
    prefix = ((void * ) 0 ) ; 
  if (((exns ) == (scheme_null ) ) )
    exns = ((void * ) 0 ) ; 
  if (modidx_shift_from )
    idx = FUNCCALL(SETUP_XfOrM1456(_), scheme_modidx_shift (idx , modidx_shift_from , modidx_shift_to ) ); 
  name = FUNCCALL(SETUP_XfOrM1456(_), scheme_module_resolve (idx , 0 ) ); 
  if (((kernel_symbol ) == (name ) ) ) {
    me = kernel -> me ; 
  }
  else {
#   define XfOrM1457_COUNT (0+XfOrM1456_COUNT)
#   define SETUP_XfOrM1457(x) SETUP_XfOrM1456(x)
    if (! export_registry ) {
#     define XfOrM1459_COUNT (0+XfOrM1457_COUNT)
#     define SETUP_XfOrM1459(x) SETUP_XfOrM1457(x)
      env = (__funcarg204 = FUNCCALL(SETUP_XfOrM1459(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_env (__funcarg204 ) )) ; 
      export_registry = env -> export_registry ; 
    }
    me = (Scheme_Module_Exports * ) FUNCCALL(SETUP_XfOrM1457(_), scheme_hash_get (export_registry , name ) ); 
    if (! me ) {
#     define XfOrM1458_COUNT (0+XfOrM1457_COUNT)
#     define SETUP_XfOrM1458(x) SETUP_XfOrM1457(x)
      (__funcarg203 = FUNCCALL(SETUP_XfOrM1458(_), scheme_symbol_name (name ) ), FUNCCALL_EMPTY(scheme_signal_error ("compiled/expanded code out of context;" " cannot find exports to restore imported renamings" " for module: %s" , __funcarg203 ) )) ; 
      RET_NOTHING ; 
    }
  }
  FUNCCALL_EMPTY(add_single_require (me , (((long ) (kv ) ) >> 1 ) , orig_idx , ((void * ) 0 ) , rn , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , exns , ((void * ) 0 ) , prefix , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , 0 , 0 , 1 , 0 , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * parse_requires (Scheme_Object * form , Scheme_Object * base_modidx , Scheme_Env * env , Scheme_Object * rn , Scheme_Object * post_ex_rn , Scheme_Object * et_rn , Scheme_Object * post_ex_et_rn , Scheme_Object * dt_rn , Scheme_Object * post_ex_dt_rn , Check_Func ck , void * data , void * et_data , void * dt_data , int start , int expstart , Scheme_Object * redef_modname , int unpack_kern , int copy_vars , int can_save_marshal , int * all_simple ) {
  Scheme_Object * ll = form ; 
  Scheme_Module * m ; 
  Scheme_Object * idxstx , * idx , * name , * i , * exns , * prefix , * iname , * ename , * aa ; 
  Scheme_Object * imods , * mark_src , * err_src ; 
  Scheme_Hash_Table * onlys ; 
  Scheme_Object * __funcarg206 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(31);
  BLOCK_SETUP_TOP((PUSH(all_simple, 0), PUSH(rn, 1), PUSH(prefix, 2), PUSH(onlys, 3), PUSH(ename, 4), PUSH(data, 5), PUSH(et_rn, 6), PUSH(m, 7), PUSH(err_src, 8), PUSH(form, 9), PUSH(imods, 10), PUSH(i, 11), PUSH(dt_rn, 12), PUSH(aa, 13), PUSH(iname, 14), PUSH(mark_src, 15), PUSH(exns, 16), PUSH(idx, 17), PUSH(post_ex_et_rn, 18), PUSH(name, 19), PUSH(ll, 20), PUSH(base_modidx, 21), PUSH(env, 22), PUSH(idxstx, 23), PUSH(post_ex_dt_rn, 24), PUSH(et_data, 25), PUSH(post_ex_rn, 26), PUSH(dt_data, 27)));
# define XfOrM1461_COUNT (28)
# define SETUP_XfOrM1461(x) SETUP(XfOrM1461_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  m = NULLED_OUT ; 
  idxstx = NULLED_OUT ; 
  idx = NULLED_OUT ; 
  name = NULLED_OUT ; 
  i = NULLED_OUT ; 
  exns = NULLED_OUT ; 
  prefix = NULLED_OUT ; 
  iname = NULLED_OUT ; 
  ename = NULLED_OUT ; 
  aa = NULLED_OUT ; 
  imods = NULLED_OUT ; 
  mark_src = NULLED_OUT ; 
  err_src = NULLED_OUT ; 
  onlys = NULLED_OUT ; 
  imods = scheme_null ; 
  if (FUNCCALL(SETUP_XfOrM1461(_), scheme_stx_proper_list_length (form ) )< 0 )
    FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , form , "bad syntax (" "illegal use of `.'" ")" ) ); 
  for (ll = (((Scheme_Type ) (((((long ) (ll ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ll ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (ll ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1461(_), scheme_stx_content (ll ) )) ) -> u . pair_val . cdr ) ) ; ! (((ll ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (ll ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ll ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) ll ) -> val ) == (scheme_null ) ) ) ) ; ll = (((Scheme_Type ) (((((long ) (ll ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ll ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (ll ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1461(_), scheme_stx_content (ll ) )) ) -> u . pair_val . cdr ) ) ) {
#   define XfOrM1489_COUNT (0+XfOrM1461_COUNT)
#   define SETUP_XfOrM1489(x) SETUP_XfOrM1461(x)
    i = (((Scheme_Type ) (((((long ) (ll ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ll ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (ll ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1489(_), scheme_stx_content (ll ) )) ) -> u . pair_val . car ) ) ; 
    iname = ename = ((void * ) 0 ) ; 
    onlys = ((void * ) 0 ) ; 
    if ((((Scheme_Type ) (((((long ) (i ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (i ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (i ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (i ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) i ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) i ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
      aa = (((Scheme_Type ) (((((long ) (i ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (i ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (i ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1489(_), scheme_stx_content (i ) )) ) -> u . pair_val . car ) ) ; 
    else aa = ((void * ) 0 ) ; 
    err_src = i ; 
    mark_src = i ; 
    if (aa && ((prefix_symbol ) == (((Scheme_Stx * ) aa ) -> val ) ) ) {
      int len ; 
#     define XfOrM1513_COUNT (0+XfOrM1489_COUNT)
#     define SETUP_XfOrM1513(x) SETUP_XfOrM1489(x)
      if (all_simple )
        * all_simple = 0 ; 
      len = FUNCCALL(SETUP_XfOrM1513(_), scheme_stx_proper_list_length (i ) ); 
      if (len != 3 ) {
        GC_CAN_IGNORE const char * reason ; 
#       define XfOrM1515_COUNT (0+XfOrM1513_COUNT)
#       define SETUP_XfOrM1515(x) SETUP_XfOrM1513(x)
        if (len < 0 )
          reason = "bad syntax (" "illegal use of `.'" ")" ; 
        else if (len < 2 )
          reason = "bad syntax (prefix missing)" ; 
        else if (len < 3 )
          reason = "bad syntax (module name missing)" ; 
        else reason = "bad syntax (extra data after module name)" ; 
        FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , i , form , reason ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      i = (((Scheme_Type ) (((((long ) (i ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (i ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (i ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1513(_), scheme_stx_content (i ) )) ) -> u . pair_val . cdr ) ) ; 
      prefix = (((Scheme_Type ) (((((long ) (i ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (i ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (i ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1513(_), scheme_stx_content (i ) )) ) -> u . pair_val . car ) ) ; 
      i = (((Scheme_Type ) (((((long ) (i ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (i ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (i ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1513(_), scheme_stx_content (i ) )) ) -> u . pair_val . cdr ) ) ; 
      idxstx = (((Scheme_Type ) (((((long ) (i ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (i ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (i ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1513(_), scheme_stx_content (i ) )) ) -> u . pair_val . car ) ) ; 
      exns = ((void * ) 0 ) ; 
      if (! ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) prefix ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) prefix ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
#       define XfOrM1514_COUNT (0+XfOrM1513_COUNT)
#       define SETUP_XfOrM1514(x) SETUP_XfOrM1513(x)
        FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , prefix , form , "bad prefix (not an identifier)" ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      prefix = ((Scheme_Stx * ) prefix ) -> val ; 
    }
    else if (aa && (((all_except_symbol ) == (((Scheme_Stx * ) aa ) -> val ) ) || ((prefix_all_except_symbol ) == (((Scheme_Stx * ) aa ) -> val ) ) ) ) {
      Scheme_Object * l ; 
      int len ; 
      int has_prefix ; 
      BLOCK_SETUP((PUSH(l, 0+XfOrM1489_COUNT)));
#     define XfOrM1506_COUNT (1+XfOrM1489_COUNT)
#     define SETUP_XfOrM1506(x) SETUP(XfOrM1506_COUNT)
      l = NULLED_OUT ; 
      if (all_simple )
        * all_simple = 0 ; 
      has_prefix = ((prefix_all_except_symbol ) == (((Scheme_Stx * ) aa ) -> val ) ) ; 
      len = FUNCCALL(SETUP_XfOrM1506(_), scheme_stx_proper_list_length (i ) ); 
      if (len < 0 )
        FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , i , form , "bad syntax (" "illegal use of `.'" ")" ) ); 
      else if (has_prefix && (len < 2 ) )
        FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , i , form , "bad syntax (prefix missing)" ) ); 
      else if (len < (has_prefix ? 3 : 2 ) )
        FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , i , form , "bad syntax (module name missing)" ) ); 
      idxstx = (((Scheme_Type ) (((((long ) (i ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (i ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (i ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1506(_), scheme_stx_content (i ) )) ) -> u . pair_val . cdr ) ) ; 
      if (has_prefix ) {
#       define XfOrM1511_COUNT (0+XfOrM1506_COUNT)
#       define SETUP_XfOrM1511(x) SETUP_XfOrM1506(x)
        prefix = (((Scheme_Type ) (((((long ) (idxstx ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (idxstx ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (idxstx ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1511(_), scheme_stx_content (idxstx ) )) ) -> u . pair_val . car ) ) ; 
        idxstx = (((Scheme_Type ) (((((long ) (idxstx ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (idxstx ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (idxstx ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1511(_), scheme_stx_content (idxstx ) )) ) -> u . pair_val . cdr ) ) ; 
        if (! ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) prefix ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) prefix ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
#         define XfOrM1512_COUNT (0+XfOrM1511_COUNT)
#         define SETUP_XfOrM1512(x) SETUP_XfOrM1511(x)
          FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , prefix , form , "bad prefix (not an identifier)" ) ); 
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        }
        prefix = ((Scheme_Stx * ) prefix ) -> val ; 
      }
      else prefix = ((void * ) 0 ) ; 
      exns = (((Scheme_Type ) (((((long ) (idxstx ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (idxstx ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (idxstx ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1506(_), scheme_stx_content (idxstx ) )) ) -> u . pair_val . cdr ) ) ; 
      idxstx = (((Scheme_Type ) (((((long ) (idxstx ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (idxstx ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (idxstx ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1506(_), scheme_stx_content (idxstx ) )) ) -> u . pair_val . car ) ) ; 
      for (l = exns ; (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) l ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) l ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ; l = (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1506(_), scheme_stx_content (l ) )) ) -> u . pair_val . cdr ) ) ) {
#       define XfOrM1509_COUNT (0+XfOrM1506_COUNT)
#       define SETUP_XfOrM1509(x) SETUP_XfOrM1506(x)
        if (! (((Scheme_Type ) (((((long ) ((((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1509(_), scheme_stx_content (l ) )) ) -> u . pair_val . car ) ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1509(_), scheme_stx_content (l ) )) ) -> u . pair_val . car ) ) ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) ((((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1509(_), scheme_stx_content (l ) )) ) -> u . pair_val . car ) ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1509(_), scheme_stx_content (l ) )) ) -> u . pair_val . car ) ) ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1509(_), scheme_stx_content (l ) )) ) -> u . pair_val . car ) ) ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1509(_), scheme_stx_content (l ) )) ) -> u . pair_val . car ) ) ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) ) {
#         define XfOrM1510_COUNT (0+XfOrM1509_COUNT)
#         define SETUP_XfOrM1510(x) SETUP_XfOrM1509(x)
          l = (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1510(_), scheme_stx_content (l ) )) ) -> u . pair_val . car ) ) ; 
          FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , l , form , "bad syntax (excluded name is not an identifier)" ) ); 
        }
      }
    }
    else if (aa && ((only_symbol ) == (((Scheme_Stx * ) aa ) -> val ) ) ) {
      int len ; 
      Scheme_Object * rest , * nm ; 
      BLOCK_SETUP((PUSH(rest, 0+XfOrM1489_COUNT), PUSH(nm, 1+XfOrM1489_COUNT)));
#     define XfOrM1500_COUNT (2+XfOrM1489_COUNT)
#     define SETUP_XfOrM1500(x) SETUP(XfOrM1500_COUNT)
      rest = NULLED_OUT ; 
      nm = NULLED_OUT ; 
      if (all_simple )
        * all_simple = 0 ; 
      len = FUNCCALL(SETUP_XfOrM1500(_), scheme_stx_proper_list_length (i ) ); 
      if (len < 2 ) {
        GC_CAN_IGNORE const char * reason ; 
#       define XfOrM1505_COUNT (0+XfOrM1500_COUNT)
#       define SETUP_XfOrM1505(x) SETUP_XfOrM1500(x)
        if (len < 0 )
          reason = "bad syntax (" "illegal use of `.'" ")" ; 
        else reason = "bad syntax (module name missing)" ; 
        FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , i , form , reason ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      onlys = FUNCCALL(SETUP_XfOrM1500(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
      rest = (((Scheme_Type ) (((((long ) (i ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (i ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (i ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1500(_), scheme_stx_content (i ) )) ) -> u . pair_val . cdr ) ) ; 
      idxstx = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1500(_), scheme_stx_content (rest ) )) ) -> u . pair_val . car ) ) ; 
      rest = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1500(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ; 
      while ((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) rest ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) rest ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
#       define XfOrM1503_COUNT (0+XfOrM1500_COUNT)
#       define SETUP_XfOrM1503(x) SETUP_XfOrM1500(x)
        nm = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1503(_), scheme_stx_content (rest ) )) ) -> u . pair_val . car ) ) ; 
        if (! (((Scheme_Type ) (((((long ) (nm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (nm ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (nm ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (nm ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) nm ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) nm ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) ) {
#         define XfOrM1504_COUNT (0+XfOrM1503_COUNT)
#         define SETUP_XfOrM1504(x) SETUP_XfOrM1503(x)
          FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , nm , form , "bad syntax (name for `only' is not an identifier)" ) ); 
        }
        FUNCCALL(SETUP_XfOrM1503(_), scheme_hash_set (onlys , ((Scheme_Stx * ) nm ) -> val , nm ) ); 
        rest = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1503(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ; 
      }
      mark_src = ((void * ) 0 ) ; 
      exns = ((void * ) 0 ) ; 
      prefix = ((void * ) 0 ) ; 
    }
    else if (aa && ((rename_symbol ) == (((Scheme_Stx * ) aa ) -> val ) ) ) {
      int len ; 
      Scheme_Object * rest ; 
      BLOCK_SETUP((PUSH(rest, 0+XfOrM1489_COUNT)));
#     define XfOrM1498_COUNT (1+XfOrM1489_COUNT)
#     define SETUP_XfOrM1498(x) SETUP(XfOrM1498_COUNT)
      rest = NULLED_OUT ; 
      if (all_simple )
        * all_simple = 0 ; 
      len = FUNCCALL(SETUP_XfOrM1498(_), scheme_stx_proper_list_length (i ) ); 
      if (len != 4 ) {
        GC_CAN_IGNORE const char * reason ; 
#       define XfOrM1499_COUNT (0+XfOrM1498_COUNT)
#       define SETUP_XfOrM1499(x) SETUP_XfOrM1498(x)
        if (len < 0 )
          reason = "bad syntax (" "illegal use of `.'" ")" ; 
        else if (len < 2 )
          reason = "bad syntax (module name missing)" ; 
        else if (len < 3 )
          reason = "bad syntax (internal name missing)" ; 
        else if (len < 4 )
          reason = "bad syntax (external name missing)" ; 
        else reason = "bad syntax (extra data after external name)" ; 
        FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , i , form , reason ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      rest = (((Scheme_Type ) (((((long ) (i ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (i ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (i ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1498(_), scheme_stx_content (i ) )) ) -> u . pair_val . cdr ) ) ; 
      idxstx = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1498(_), scheme_stx_content (rest ) )) ) -> u . pair_val . car ) ) ; 
      rest = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1498(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ; 
      iname = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1498(_), scheme_stx_content (rest ) )) ) -> u . pair_val . car ) ) ; 
      rest = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1498(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ; 
      ename = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1498(_), scheme_stx_content (rest ) )) ) -> u . pair_val . car ) ) ; 
      if (! (((Scheme_Type ) (((((long ) (iname ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (iname ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (iname ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (iname ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) iname ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) iname ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) )
        FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , i , form , "bad syntax (internal name is not an identifier)" ) ); 
      if (! (((Scheme_Type ) (((((long ) (ename ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ename ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (ename ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ename ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) ename ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) ename ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) )
        FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , i , form , "bad syntax (external name is not an identifier)" ) ); 
      mark_src = iname ; 
      iname = ((Scheme_Stx * ) iname ) -> val ; 
      prefix = ((void * ) 0 ) ; 
      exns = ((void * ) 0 ) ; 
    }
    else {
      idxstx = i ; 
      exns = ((void * ) 0 ) ; 
      prefix = ((void * ) 0 ) ; 
    }
    idx = (__funcarg206 = FUNCCALL(SETUP_XfOrM1489(_), scheme_syntax_to_datum (idxstx , 0 , ((void * ) 0 ) ) ), FUNCCALL_AGAIN(scheme_make_modidx (__funcarg206 , base_modidx , scheme_false ) )) ; 
    name = FUNCCALL(SETUP_XfOrM1489(_), _module_resolve (idx , idxstx , 1 ) ); 
    m = FUNCCALL_AGAIN(module_load (name , env , ((void * ) 0 ) ) ); 
    if (start )
      FUNCCALL(SETUP_XfOrM1489(_), start_module (m , env , 0 , idx , 0 , 1 , scheme_null ) ); 
    else if (expstart )
      FUNCCALL(SETUP_XfOrM1489(_), expstart_module (m , env , 0 , idx , 0 , 0 , scheme_null ) ); 
    {
      Scheme_Object * l , * last = ((void * ) 0 ) , * p ; 
      BLOCK_SETUP((PUSH(last, 0+XfOrM1489_COUNT), PUSH(p, 1+XfOrM1489_COUNT), PUSH(l, 2+XfOrM1489_COUNT)));
#     define XfOrM1493_COUNT (3+XfOrM1489_COUNT)
#     define SETUP_XfOrM1493(x) SETUP(XfOrM1493_COUNT)
      l = NULLED_OUT ; 
      p = NULLED_OUT ; 
      for (l = imods ; ! ((l ) == (scheme_null ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#       define XfOrM1496_COUNT (0+XfOrM1493_COUNT)
#       define SETUP_XfOrM1496(x) SETUP_XfOrM1493(x)
        if (FUNCCALL(SETUP_XfOrM1496(_), same_modidx ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) , idx ) ))
          break ; 
        last = l ; 
      }
      if (((l ) == (scheme_null ) ) ) {
#       define XfOrM1494_COUNT (0+XfOrM1493_COUNT)
#       define SETUP_XfOrM1494(x) SETUP_XfOrM1493(x)
        p = FUNCCALL(SETUP_XfOrM1494(_), scheme_make_pair (idx , scheme_null ) ); 
        if (last )
          (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = p ; 
        else imods = p ; 
      }
    }
    FUNCCALL(SETUP_XfOrM1489(_), add_single_require (m -> me , 0 , idx , env , rn , post_ex_rn , et_rn , post_ex_et_rn , dt_rn , post_ex_dt_rn , exns , onlys , prefix , iname , ename , mark_src , unpack_kern , copy_vars && start , 0 , can_save_marshal , all_simple , ck , data , et_data , dt_data , form , err_src , i ) ); 
    if (onlys && onlys -> count ) {
      int k ; 
#     define XfOrM1490_COUNT (0+XfOrM1489_COUNT)
#     define SETUP_XfOrM1490(x) SETUP_XfOrM1489(x)
      for (k = 0 ; k < onlys -> size ; k ++ ) {
#       define XfOrM1492_COUNT (0+XfOrM1490_COUNT)
#       define SETUP_XfOrM1492(x) SETUP_XfOrM1490(x)
        if (onlys -> vals [k ] )
          FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , onlys -> vals [k ] , form , "no such provided variable" ) ); 
      }
    }
  }
  RET_VALUE_START (imods ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void check_dup_require (Scheme_Object * prnt_name , Scheme_Object * name , Scheme_Object * nominal_modidx , Scheme_Object * modidx , Scheme_Object * srcname , int isval , void * ht , Scheme_Object * e , Scheme_Object * form , Scheme_Object * err_src ) {
  Scheme_Object * i ; 
  Scheme_Object * __funcarg207 = NULLED_OUT ; 
  PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSH(ht, 0), PUSH(srcname, 1), PUSH(modidx, 2), PUSH(i, 3), PUSH(name, 4), PUSH(prnt_name, 5), PUSH(form, 6)));
# define XfOrM1516_COUNT (7)
# define SETUP_XfOrM1516(x) SETUP(XfOrM1516_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  i = NULLED_OUT ; 
  if (ht ) {
#   define XfOrM1517_COUNT (0+XfOrM1516_COUNT)
#   define SETUP_XfOrM1517(x) SETUP_XfOrM1516(x)
    i = FUNCCALL(SETUP_XfOrM1517(_), scheme_hash_get ((Scheme_Hash_Table * ) ht , name ) ); 
    if (i ) {
#     define XfOrM1518_COUNT (0+XfOrM1517_COUNT)
#     define SETUP_XfOrM1518(x) SETUP_XfOrM1517(x)
      if (FUNCCALL(SETUP_XfOrM1518(_), same_resolved_modidx (modidx , (((Scheme_Simple_Object * ) (i ) ) -> u . pair_val . car ) ) )&& ((srcname ) == ((((Scheme_Simple_Object * ) (i ) ) -> u . pair_val . cdr ) ) ) )
        RET_NOTHING ; 
      FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , prnt_name , form , "duplicate import identifier" ) ); 
    }
    else (__funcarg207 = FUNCCALL(SETUP_XfOrM1517(_), scheme_make_pair (modidx , srcname ) ), FUNCCALL_AGAIN(scheme_hash_set ((Scheme_Hash_Table * ) ht , name , __funcarg207 ) )) ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * top_level_require_execute (Scheme_Object * data ) {
  Scheme_Hash_Table * ht , * et_ht , * dt_ht ; 
  Scheme_Object * rn , * et_rn , * dt_rn , * modidx ; 
  Scheme_Object * form = ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) , * rest , * brn ; 
  int for_phase = (((long ) (((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) ) >> 1 ) ; 
  Scheme_Env * env ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(11);
  BLOCK_SETUP_TOP((PUSH(modidx, 0), PUSH(rn, 1), PUSH(dt_rn, 2), PUSH(env, 3), PUSH(ht, 4), PUSH(brn, 5), PUSH(et_ht, 6), PUSH(et_rn, 7), PUSH(dt_ht, 8), PUSH(form, 9), PUSH(rest, 10)));
# define XfOrM1519_COUNT (11)
# define SETUP_XfOrM1519(x) SETUP(XfOrM1519_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ht = NULLED_OUT ; 
  et_ht = NULLED_OUT ; 
  dt_ht = NULLED_OUT ; 
  rn = NULLED_OUT ; 
  et_rn = NULLED_OUT ; 
  dt_rn = NULLED_OUT ; 
  modidx = NULLED_OUT ; 
  rest = NULLED_OUT ; 
  brn = NULLED_OUT ; 
  env = NULLED_OUT ; 
  env = FUNCCALL(SETUP_XfOrM1519(_), scheme_environment_from_dummy ((((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) ) ); 
  if (env -> module )
    modidx = env -> module -> self_modidx ; 
  else modidx = scheme_false ; 
  if (for_phase == 1 ) {
#   define XfOrM1532_COUNT (0+XfOrM1519_COUNT)
#   define SETUP_XfOrM1532(x) SETUP_XfOrM1519(x)
    FUNCCALL(SETUP_XfOrM1532(_), scheme_prepare_exp_env (env ) ); 
    env = env -> exp_env ; 
  }
  else if (for_phase == - 1 ) {
#   define XfOrM1531_COUNT (0+XfOrM1519_COUNT)
#   define SETUP_XfOrM1531(x) SETUP_XfOrM1519(x)
    FUNCCALL(SETUP_XfOrM1531(_), scheme_prepare_template_env (env ) ); 
    env = env -> template_env ; 
  }
  rest = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1519(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  if ((((rest ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) rest ) -> val ) == (scheme_null ) ) ) ) ) {
    rest = ((void * ) 0 ) ; 
  }
  else if ((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) rest ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) rest ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
#   define XfOrM1528_COUNT (0+XfOrM1519_COUNT)
#   define SETUP_XfOrM1528(x) SETUP_XfOrM1519(x)
    rest = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1528(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ; 
    if ((((rest ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) rest ) -> val ) == (scheme_null ) ) ) ) ) {
      rest = ((void * ) 0 ) ; 
    }
  }
  if (rest )
    ht = FUNCCALL(SETUP_XfOrM1519(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  else ht = ((void * ) 0 ) ; 
  rn = FUNCCALL(SETUP_XfOrM1519(_), scheme_make_module_rename (for_phase , 0 , ((void * ) 0 ) ) ); 
  if (! for_phase ) {
#   define XfOrM1525_COUNT (0+XfOrM1519_COUNT)
#   define SETUP_XfOrM1525(x) SETUP_XfOrM1519(x)
    FUNCCALL(SETUP_XfOrM1525(_), scheme_prepare_exp_env (env ) ); 
    et_rn = FUNCCALL(SETUP_XfOrM1525(_), scheme_make_module_rename (1 , 0 , ((void * ) 0 ) ) ); 
    dt_rn = FUNCCALL_AGAIN(scheme_make_module_rename (30000 , 0 , ((void * ) 0 ) ) ); 
    if (rest ) {
#     define XfOrM1527_COUNT (0+XfOrM1525_COUNT)
#     define SETUP_XfOrM1527(x) SETUP_XfOrM1525(x)
      et_ht = FUNCCALL(SETUP_XfOrM1527(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
      dt_ht = FUNCCALL(SETUP_XfOrM1527(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
    }
    else {
      et_ht = ((void * ) 0 ) ; 
      dt_ht = ((void * ) 0 ) ; 
    }
  }
  else {
    et_rn = ((void * ) 0 ) ; 
    dt_rn = ((void * ) 0 ) ; 
    et_ht = ((void * ) 0 ) ; 
    dt_ht = ((void * ) 0 ) ; 
  }
  (void ) FUNCCALL(SETUP_XfOrM1519(_), parse_requires (form , modidx , env , rn , rn , et_rn , et_rn , dt_rn , dt_rn , check_dup_require , ht , et_ht , dt_ht , (for_phase > - 1 ) , (for_phase == 0 ) , ((void * ) 0 ) , ! env -> module , 0 , 0 , ((void * ) 0 ) ) ); 
  brn = ((for_phase == 30000 ) ? env -> dt_rename : env -> rename ) ; 
  if (! brn ) {
#   define XfOrM1523_COUNT (0+XfOrM1519_COUNT)
#   define SETUP_XfOrM1523(x) SETUP_XfOrM1519(x)
    brn = FUNCCALL(SETUP_XfOrM1523(_), scheme_make_module_rename (for_phase , 0 , ((void * ) 0 ) ) ); 
    if (for_phase == 30000 )
      env -> dt_rename = brn ; 
    else env -> rename = brn ; 
  }
  FUNCCALL(SETUP_XfOrM1519(_), scheme_append_module_rename (rn , brn ) ); 
  if (! for_phase ) {
#   define XfOrM1520_COUNT (0+XfOrM1519_COUNT)
#   define SETUP_XfOrM1520(x) SETUP_XfOrM1519(x)
    brn = env -> exp_env -> rename ; 
    if (! brn ) {
#     define XfOrM1522_COUNT (0+XfOrM1520_COUNT)
#     define SETUP_XfOrM1522(x) SETUP_XfOrM1520(x)
      brn = FUNCCALL(SETUP_XfOrM1522(_), scheme_make_module_rename (1 , 0 , ((void * ) 0 ) ) ); 
      env -> exp_env -> rename = brn ; 
    }
    FUNCCALL(SETUP_XfOrM1520(_), scheme_append_module_rename (et_rn , brn ) ); 
    brn = env -> dt_rename ; 
    if (! brn ) {
#     define XfOrM1521_COUNT (0+XfOrM1520_COUNT)
#     define SETUP_XfOrM1521(x) SETUP_XfOrM1520(x)
      brn = FUNCCALL(SETUP_XfOrM1521(_), scheme_make_module_rename (30000 , 0 , ((void * ) 0 ) ) ); 
      env -> dt_rename = brn ; 
    }
    FUNCCALL_EMPTY(scheme_append_module_rename (dt_rn , brn ) ); 
  }
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * top_level_require_jit (Scheme_Object * data ) {
  /* No conversion */
  return data ; 
}
static void top_level_require_validate (Scheme_Object * data , Mz_CPort * port , char * stack , Scheme_Hash_Table * ht , Scheme_Object * * tls , int depth , int letlimit , int delta , int num_toplevels , int num_stxes , int num_lifts ) {
  /* No conversion */
}
static Scheme_Object * top_level_require_optimize (Scheme_Object * data , Optimize_Info * info ) {
  /* No conversion */
  return scheme_make_syntax_compiled (7 , data ) ; 
}
static Scheme_Object * top_level_require_resolve (Scheme_Object * data , Resolve_Info * rslv ) {
  Scheme_Object * dummy = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) ; 
  Scheme_Object * __funcarg208 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(dummy, 0), PUSH(data, 1)));
# define XfOrM1536_COUNT (2)
# define SETUP_XfOrM1536(x) SETUP(XfOrM1536_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  dummy = FUNCCALL(SETUP_XfOrM1536(_), scheme_resolve_expr (dummy , rslv ) ); 
  RET_VALUE_START ((__funcarg208 = FUNCCALL_EMPTY(scheme_make_pair (dummy , (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ) ), FUNCCALL_EMPTY(scheme_make_syntax_resolved (7 , __funcarg208 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_require (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Expand_Info * rec , int drec , int for_phase ) {
  Scheme_Hash_Table * ht , * et_ht , * dt_ht ; 
  Scheme_Object * rn , * et_rn , * dt_rn , * dummy , * modidx ; 
  Scheme_Env * genv ; 
  Scheme_Object * __funcarg210 = NULLED_OUT ; 
  Scheme_Object * __funcarg209 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(12);
  BLOCK_SETUP_TOP((PUSH(rec, 0), PUSH(dt_rn, 1), PUSH(rn, 2), PUSH(genv, 3), PUSH(modidx, 4), PUSH(ht, 5), PUSH(dummy, 6), PUSH(et_ht, 7), PUSH(et_rn, 8), PUSH(env, 9), PUSH(form, 10), PUSH(dt_ht, 11)));
# define XfOrM1537_COUNT (12)
# define SETUP_XfOrM1537(x) SETUP(XfOrM1537_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ht = NULLED_OUT ; 
  et_ht = NULLED_OUT ; 
  dt_ht = NULLED_OUT ; 
  rn = NULLED_OUT ; 
  et_rn = NULLED_OUT ; 
  dt_rn = NULLED_OUT ; 
  dummy = NULLED_OUT ; 
  modidx = NULLED_OUT ; 
  genv = NULLED_OUT ; 
  if (! FUNCCALL(SETUP_XfOrM1537(_), scheme_is_toplevel (env ) ))
    FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , form , "not at top-level or in module body" ) ); 
  ht = FUNCCALL(SETUP_XfOrM1537(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  rn = FUNCCALL_AGAIN(scheme_make_module_rename (for_phase , 0 , ((void * ) 0 ) ) ); 
  if (! for_phase ) {
#   define XfOrM1542_COUNT (0+XfOrM1537_COUNT)
#   define SETUP_XfOrM1542(x) SETUP_XfOrM1537(x)
    et_rn = FUNCCALL(SETUP_XfOrM1542(_), scheme_make_module_rename (1 , 0 , ((void * ) 0 ) ) ); 
    dt_rn = FUNCCALL(SETUP_XfOrM1542(_), scheme_make_module_rename (30000 , 0 , ((void * ) 0 ) ) ); 
    et_ht = FUNCCALL_AGAIN(scheme_make_hash_table (SCHEME_hash_ptr ) ); 
    dt_ht = FUNCCALL_AGAIN(scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  }
  else {
    et_rn = ((void * ) 0 ) ; 
    dt_rn = ((void * ) 0 ) ; 
    et_ht = ((void * ) 0 ) ; 
    dt_ht = ((void * ) 0 ) ; 
  }
  genv = env -> genv ; 
  if (genv -> module )
    modidx = genv -> module -> self_modidx ; 
  else modidx = scheme_false ; 
  if (for_phase == 1 ) {
#   define XfOrM1540_COUNT (0+XfOrM1537_COUNT)
#   define SETUP_XfOrM1540(x) SETUP_XfOrM1537(x)
    FUNCCALL(SETUP_XfOrM1540(_), scheme_prepare_exp_env (genv ) ); 
    genv = genv -> exp_env ; 
  }
  else if (for_phase == - 1 ) {
#   define XfOrM1539_COUNT (0+XfOrM1537_COUNT)
#   define SETUP_XfOrM1539(x) SETUP_XfOrM1537(x)
    FUNCCALL(SETUP_XfOrM1539(_), scheme_prepare_template_env (genv ) ); 
    genv = genv -> template_env ; 
  }
  (void ) FUNCCALL(SETUP_XfOrM1537(_), parse_requires (form , modidx , genv , rn , rn , et_rn , et_rn , dt_rn , dt_rn , check_dup_require , ht , et_ht , dt_ht , 0 , 0 , ((void * ) 0 ) , 0 , 0 , 0 , ((void * ) 0 ) ) ); 
  if (rec [drec ] . comp ) {
#   define XfOrM1538_COUNT (0+XfOrM1537_COUNT)
#   define SETUP_XfOrM1538(x) SETUP_XfOrM1537(x)
    dummy = FUNCCALL(SETUP_XfOrM1538(_), scheme_make_environment_dummy (env ) ); 
    FUNCCALL(SETUP_XfOrM1538(_), scheme_compile_rec_done_local (rec , drec ) ); 
    FUNCCALL_AGAIN(scheme_default_compile_rec (rec , drec ) ); 
    RET_VALUE_START ((__funcarg209 = (__funcarg210 = FUNCCALL(SETUP_XfOrM1538(_), scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (for_phase ) ) << 1 ) | 0x1 ) ) , form ) ), FUNCCALL_AGAIN(scheme_make_pair (dummy , __funcarg210 ) )) , FUNCCALL_EMPTY(scheme_make_syntax_compiled (7 , __funcarg209 ) )) ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (form ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * require_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  /* No conversion */
  return do_require (form , env , rec , drec , 0 ) ; 
}
static Scheme_Object * require_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(erec, 0), PUSH(env, 1), PUSH(form, 2)));
# define XfOrM1544_COUNT (3)
# define SETUP_XfOrM1544(x) SETUP(XfOrM1544_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (erec [drec ] . observer ) {
#   define XfOrM1546_COUNT (0+XfOrM1544_COUNT)
#   define SETUP_XfOrM1546(x) SETUP_XfOrM1544(x)
    FUNCCALL(SETUP_XfOrM1546(_), scheme_call_expand_observe (erec [drec ] . observer , 119 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(do_require (form , env , erec , drec , 0 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * require_for_syntax_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  /* No conversion */
  return do_require (form , env , rec , drec , 1 ) ; 
}
static Scheme_Object * require_for_syntax_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(erec, 0), PUSH(env, 1), PUSH(form, 2)));
# define XfOrM1548_COUNT (3)
# define SETUP_XfOrM1548(x) SETUP(XfOrM1548_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (erec [drec ] . observer ) {
#   define XfOrM1550_COUNT (0+XfOrM1548_COUNT)
#   define SETUP_XfOrM1550(x) SETUP_XfOrM1548(x)
    FUNCCALL(SETUP_XfOrM1550(_), scheme_call_expand_observe (erec [drec ] . observer , 120 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(do_require (form , env , erec , drec , 1 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * require_for_template_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  /* No conversion */
  return do_require (form , env , rec , drec , - 1 ) ; 
}
static Scheme_Object * require_for_template_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(erec, 0), PUSH(env, 1), PUSH(form, 2)));
# define XfOrM1552_COUNT (3)
# define SETUP_XfOrM1552(x) SETUP(XfOrM1552_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (erec [drec ] . observer ) {
#   define XfOrM1554_COUNT (0+XfOrM1552_COUNT)
#   define SETUP_XfOrM1554(x) SETUP_XfOrM1552(x)
    FUNCCALL(SETUP_XfOrM1554(_), scheme_call_expand_observe (erec [drec ] . observer , 121 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(do_require (form , env , erec , drec , - 1 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * require_for_label_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  /* No conversion */
  return do_require (form , env , rec , drec , 30000 ) ; 
}
static Scheme_Object * require_for_label_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(erec, 0), PUSH(env, 1), PUSH(form, 2)));
# define XfOrM1556_COUNT (3)
# define SETUP_XfOrM1556(x) SETUP(XfOrM1556_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (erec [drec ] . observer ) {
#   define XfOrM1558_COUNT (0+XfOrM1556_COUNT)
#   define SETUP_XfOrM1558(x) SETUP_XfOrM1556(x)
    FUNCCALL(SETUP_XfOrM1558(_), scheme_call_expand_observe (erec [drec ] . observer , 121 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(do_require (form , env , erec , drec , 30000 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * provide_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  /* No conversion */
  scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , form , "not in module body" ) ; 
  return ((void * ) 0 ) ; 
}
static Scheme_Object * provide_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(form, 0)));
# define XfOrM1560_COUNT (1)
# define SETUP_XfOrM1560(x) SETUP(XfOrM1560_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (erec [drec ] . observer ) {
#   define XfOrM1562_COUNT (0+XfOrM1560_COUNT)
#   define SETUP_XfOrM1562(x) SETUP_XfOrM1560(x)
    FUNCCALL(SETUP_XfOrM1562(_), scheme_call_expand_observe (erec [drec ] . observer , 122 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , form , "not in module body" ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
__xform_nongcing__ static Scheme_Object * wrap_mod_stx (Scheme_Object * stx ) {
  /* No conversion */
  return (stx ? stx : scheme_false ) ; 
}
static Scheme_Object * write_module (Scheme_Object * obj ) {
  Scheme_Module * m = (Scheme_Module * ) obj ; 
  Scheme_Module_Phase_Exports * pt ; 
  Scheme_Object * l , * v ; 
  int i , k , count ; 
  Scheme_Object * __funcarg214 = NULLED_OUT ; 
  Scheme_Object * __funcarg213 = NULLED_OUT ; 
  Scheme_Object * __funcarg212 = NULLED_OUT ; 
  Scheme_Object * __funcarg211 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(pt, 1), PUSH(l, 2), PUSH(m, 3)));
# define XfOrM1564_COUNT (4)
# define SETUP_XfOrM1564(x) SETUP(XfOrM1564_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  pt = NULLED_OUT ; 
  l = NULLED_OUT ; 
  v = NULLED_OUT ; 
  l = m -> dt_requires ; 
  l = FUNCCALL(SETUP_XfOrM1564(_), scheme_make_pair (m -> tt_requires , l ) ); 
  l = FUNCCALL_AGAIN(scheme_make_pair (m -> et_requires , l ) ); 
  l = FUNCCALL_AGAIN(scheme_make_pair (m -> requires , l ) ); 
  l = FUNCCALL_AGAIN(scheme_make_pair (m -> body , l ) ); 
  l = FUNCCALL_AGAIN(scheme_make_pair (m -> et_body , l ) ); 
  for (k = 0 ; k < 3 ; k ++ ) {
#   define XfOrM1584_COUNT (0+XfOrM1564_COUNT)
#   define SETUP_XfOrM1584(x) SETUP_XfOrM1564(x)
    switch (k ) {
      case 2 : pt = m -> me -> dt ; 
      break ; 
      case 1 : pt = m -> me -> et ; 
      break ; 
      case 0 : default : pt = m -> me -> rt ; 
      break ; 
    }
    l = FUNCCALL(SETUP_XfOrM1584(_), scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (pt -> num_provides ) ) << 1 ) | 0x1 ) ) , l ) ); 
    l = FUNCCALL(SETUP_XfOrM1584(_), scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (pt -> num_var_provides ) ) << 1 ) | 0x1 ) ) , l ) ); 
    count = pt -> num_provides ; 
    v = FUNCCALL(SETUP_XfOrM1584(_), scheme_make_vector (count , ((void * ) 0 ) ) ); 
    for (i = 0 ; i < count ; i ++ ) {
      (((Scheme_Vector * ) (v ) ) -> els ) [i ] = pt -> provides [i ] ; 
    }
    l = FUNCCALL(SETUP_XfOrM1584(_), scheme_make_pair (v , l ) ); 
    v = FUNCCALL(SETUP_XfOrM1584(_), scheme_make_vector (count , ((void * ) 0 ) ) ); 
    for (i = 0 ; i < count ; i ++ ) {
      (((Scheme_Vector * ) (v ) ) -> els ) [i ] = pt -> provide_srcs [i ] ; 
    }
    l = FUNCCALL(SETUP_XfOrM1584(_), scheme_make_pair (v , l ) ); 
    v = FUNCCALL(SETUP_XfOrM1584(_), scheme_make_vector (count , ((void * ) 0 ) ) ); 
    for (i = 0 ; i < count ; i ++ ) {
      (((Scheme_Vector * ) (v ) ) -> els ) [i ] = pt -> provide_src_names [i ] ; 
    }
    l = FUNCCALL(SETUP_XfOrM1584(_), scheme_make_pair (v , l ) ); 
    if (pt -> provide_src_phases ) {
#     define XfOrM1585_COUNT (0+XfOrM1584_COUNT)
#     define SETUP_XfOrM1585(x) SETUP_XfOrM1584(x)
      v = FUNCCALL(SETUP_XfOrM1585(_), scheme_make_vector (count , ((void * ) 0 ) ) ); 
      for (i = 0 ; i < count ; i ++ ) {
        (((Scheme_Vector * ) (v ) ) -> els ) [i ] = (pt -> provide_src_phases [i ] ? scheme_true : scheme_false ) ; 
      }
    }
    else v = scheme_false ; 
    l = FUNCCALL(SETUP_XfOrM1584(_), scheme_make_pair (v , l ) ); 
  }
  count = m -> me -> rt -> num_provides ; 
  if (m -> provide_protects ) {
#   define XfOrM1567_COUNT (0+XfOrM1564_COUNT)
#   define SETUP_XfOrM1567(x) SETUP_XfOrM1564(x)
    for (i = 0 ; i < count ; i ++ ) {
      if (m -> provide_protects [i ] )
        break ; 
    }
    if (i < count ) {
#     define XfOrM1568_COUNT (0+XfOrM1567_COUNT)
#     define SETUP_XfOrM1568(x) SETUP_XfOrM1567(x)
      v = FUNCCALL(SETUP_XfOrM1568(_), scheme_make_vector (count , ((void * ) 0 ) ) ); 
      for (i = 0 ; i < count ; i ++ ) {
        (((Scheme_Vector * ) (v ) ) -> els ) [i ] = (m -> provide_protects [i ] ? scheme_true : scheme_false ) ; 
      }
    }
    else v = scheme_false ; 
    l = FUNCCALL(SETUP_XfOrM1567(_), scheme_make_pair (v , l ) ); 
  }
  else l = FUNCCALL(SETUP_XfOrM1564(_), scheme_make_pair (scheme_false , l ) ); 
  l = FUNCCALL(SETUP_XfOrM1564(_), scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (m -> num_indirect_provides ) ) << 1 ) | 0x1 ) ) , l ) ); 
  count = m -> num_indirect_provides ; 
  v = FUNCCALL(SETUP_XfOrM1564(_), scheme_make_vector (count , ((void * ) 0 ) ) ); 
  for (i = 0 ; i < count ; i ++ ) {
    (((Scheme_Vector * ) (v ) ) -> els ) [i ] = m -> indirect_provides [i ] ; 
  }
  l = FUNCCALL(SETUP_XfOrM1564(_), scheme_make_pair (v , l ) ); 
  l = FUNCCALL(SETUP_XfOrM1564(_), scheme_make_pair (m -> me -> rt -> reprovide_kernel ? scheme_true : scheme_false , l ) ); 
  l = FUNCCALL_AGAIN(scheme_make_pair (m -> me -> rt -> kernel_exclusion , l ) ); 
  l = FUNCCALL_AGAIN(scheme_make_pair ((Scheme_Object * ) m -> prefix , l ) ); 
  l = FUNCCALL_AGAIN(scheme_make_pair (m -> dummy , l ) ); 
  l = FUNCCALL_AGAIN(scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (m -> max_let_depth ) ) << 1 ) | 0x1 ) ) , l ) ); 
  l = (__funcarg214 = (wrap_mod_stx (m -> dt_rn_stx ) ) , FUNCCALL(SETUP_XfOrM1564(_), scheme_make_pair (__funcarg214 , l ) )) ; 
  l = (__funcarg213 = (wrap_mod_stx (m -> tt_rn_stx ) ) , FUNCCALL(SETUP_XfOrM1564(_), scheme_make_pair (__funcarg213 , l ) )) ; 
  l = (__funcarg212 = (wrap_mod_stx (m -> et_rn_stx ) ) , FUNCCALL(SETUP_XfOrM1564(_), scheme_make_pair (__funcarg212 , l ) )) ; 
  l = (__funcarg211 = (wrap_mod_stx (m -> rn_stx ) ) , FUNCCALL(SETUP_XfOrM1564(_), scheme_make_pair (__funcarg211 , l ) )) ; 
  l = FUNCCALL(SETUP_XfOrM1564(_), scheme_make_pair (m -> me -> src_modidx , l ) ); 
  l = FUNCCALL_AGAIN(scheme_make_pair (m -> modname , l ) ); 
  RET_VALUE_START (l ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int check_requires_ok (Scheme_Object * l ) {
  /* No conversion */
  Scheme_Object * x ; 
  while (! ((l ) == (scheme_null ) ) ) {
    x = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
    if (! ((Scheme_Type ) (((((long ) (x ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (x ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) && ! ((Scheme_Type ) (((((long ) (x ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (x ) ) -> type ) ) == (Scheme_Type ) (scheme_module_index_type ) ) )
      return 0 ; 
    l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
  }
  return 1 ; 
}
static Scheme_Object * read_module (Scheme_Object * obj ) {
  Scheme_Module * m ; 
  Scheme_Object * ie , * nie ; 
  Scheme_Object * esp , * esn , * esph , * es , * e , * nve , * ne , * * v ; 
  Scheme_Module_Exports * me ; 
  Scheme_Module_Phase_Exports * pt ; 
  char * ps , * sps ; 
  int i , k , count ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(16);
  BLOCK_SETUP_TOP((PUSH(m, 0), PUSH(ne, 1), PUSH(es, 2), PUSH(sps, 3), PUSH(v, 4), PUSH(esp, 5), PUSH(nve, 6), PUSH(pt, 7), PUSH(obj, 8), PUSH(e, 9), PUSH(esn, 10), PUSH(nie, 11), PUSH(me, 12), PUSH(ps, 13), PUSH(esph, 14), PUSH(ie, 15)));
# define XfOrM1598_COUNT (16)
# define SETUP_XfOrM1598(x) SETUP(XfOrM1598_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  m = NULLED_OUT ; 
  ie = NULLED_OUT ; 
  nie = NULLED_OUT ; 
  esp = NULLED_OUT ; 
  esn = NULLED_OUT ; 
  esph = NULLED_OUT ; 
  es = NULLED_OUT ; 
  e = NULLED_OUT ; 
  nve = NULLED_OUT ; 
  ne = NULLED_OUT ; 
  v = NULLED_OUT ; 
  me = NULLED_OUT ; 
  pt = NULLED_OUT ; 
  ps = NULLED_OUT ; 
  sps = NULLED_OUT ; 
  m = ((Scheme_Module * ) FUNCCALL(SETUP_XfOrM1598(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Module ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  m -> so . type = scheme_module_type ; 
  me = FUNCCALL(SETUP_XfOrM1598(_), make_module_exports () ); 
  m -> me = me ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((printf ("%d\n" , 7084 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
  m -> modname = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((printf ("%d\n" , 7088 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
  me -> src_modidx = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  ((Scheme_Modidx * ) m -> me -> src_modidx ) -> resolved = m -> modname ; 
  m -> self_modidx = m -> me -> src_modidx ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((printf ("%d\n" , 7094 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
  m -> rn_stx = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  if ((((m -> rn_stx ) ) == (scheme_false ) ) )
    m -> rn_stx = ((void * ) 0 ) ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((printf ("%d\n" , 7100 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
  m -> et_rn_stx = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  if ((((m -> et_rn_stx ) ) == (scheme_false ) ) )
    m -> et_rn_stx = ((void * ) 0 ) ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((printf ("%d\n" , 7106 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
  m -> tt_rn_stx = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  if ((((m -> tt_rn_stx ) ) == (scheme_false ) ) )
    m -> tt_rn_stx = ((void * ) 0 ) ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((printf ("%d\n" , 7112 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
  m -> dt_rn_stx = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  if ((((m -> dt_rn_stx ) ) == (scheme_false ) ) )
    m -> dt_rn_stx = ((void * ) 0 ) ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((printf ("%d\n" , 7118 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
  m -> max_let_depth = (((long ) ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ) ) >> 1 ) ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((printf ("%d\n" , 7122 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
  m -> dummy = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((printf ("%d\n" , 7126 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
  m -> prefix = (Resolve_Prefix * ) (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((printf ("%d\n" , 7130 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
  me -> rt -> kernel_exclusion = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((printf ("%d\n" , 7133 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
  me -> rt -> reprovide_kernel = (! ((((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ) ) == (scheme_false ) ) ) ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((printf ("%d\n" , 7137 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
  ie = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((printf ("%d\n" , 7141 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
  nie = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  count = (((long ) (nie ) ) >> 1 ) ; 
  if (! ((Scheme_Type ) (((((long ) (ie ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ie ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) || ((((Scheme_Vector * ) (ie ) ) -> size ) != count ) )
    RET_VALUE_START (((printf ("%d\n" , 7147 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
  v = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM1598(_), GC_malloc (sizeof (Scheme_Object * ) * (count ) ) )) ; 
  for (i = 0 ; i < count ; i ++ ) {
    v [i ] = (((Scheme_Vector * ) (ie ) ) -> els ) [i ] ; 
  }
  m -> indirect_provides = v ; 
  m -> num_indirect_provides = count ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((printf ("%d\n" , 7155 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
  esp = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  for (k = 0 ; k < 3 ; k ++ ) {
#   define XfOrM1614_COUNT (0+XfOrM1598_COUNT)
#   define SETUP_XfOrM1614(x) SETUP_XfOrM1598(x)
    switch (k ) {
      case 0 : pt = me -> dt ; 
      break ; 
      case 1 : pt = me -> et ; 
      break ; 
      case 2 : default : pt = me -> rt ; 
      break ; 
    }
    if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
      RET_VALUE_START (((printf ("%d\n" , 7173 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
    esph = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
    obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
    if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
      RET_VALUE_START (((printf ("%d\n" , 7177 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
    esn = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
    obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
    if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
      RET_VALUE_START (((printf ("%d\n" , 7181 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
    es = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
    obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
    if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
      RET_VALUE_START (((printf ("%d\n" , 7185 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
    e = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
    obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
    if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
      RET_VALUE_START (((printf ("%d\n" , 7189 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
    nve = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
    obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
    if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
      RET_VALUE_START (((printf ("%d\n" , 7193 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
    ne = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
    obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
    count = (((long ) (ne ) ) >> 1 ) ; 
    pt -> num_provides = count ; 
    pt -> num_var_provides = (((long ) (nve ) ) >> 1 ) ; 
    if (! ((Scheme_Type ) (((((long ) (e ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) || ((((Scheme_Vector * ) (e ) ) -> size ) != count ) )
      RET_VALUE_START (((printf ("%d\n" , 7201 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
    v = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM1614(_), GC_malloc (sizeof (Scheme_Object * ) * (count ) ) )) ; 
    for (i = 0 ; i < count ; i ++ ) {
      v [i ] = (((Scheme_Vector * ) (e ) ) -> els ) [i ] ; 
    }
    pt -> provides = v ; 
    if (! ((Scheme_Type ) (((((long ) (es ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (es ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) || ((((Scheme_Vector * ) (es ) ) -> size ) != count ) )
      RET_VALUE_START (((printf ("%d\n" , 7208 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
    v = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM1614(_), GC_malloc (sizeof (Scheme_Object * ) * (count ) ) )) ; 
    for (i = 0 ; i < count ; i ++ ) {
      v [i ] = (((Scheme_Vector * ) (es ) ) -> els ) [i ] ; 
    }
    pt -> provide_srcs = v ; 
    if (! ((Scheme_Type ) (((((long ) (esn ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (esn ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) || ((((Scheme_Vector * ) (esn ) ) -> size ) != count ) )
      RET_VALUE_START (((printf ("%d\n" , 7215 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
    v = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM1614(_), GC_malloc (sizeof (Scheme_Object * ) * (count ) ) )) ; 
    for (i = 0 ; i < count ; i ++ ) {
      v [i ] = (((Scheme_Vector * ) (esn ) ) -> els ) [i ] ; 
    }
    pt -> provide_src_names = v ; 
    if ((((esph ) ) == (scheme_false ) ) )
      sps = ((void * ) 0 ) ; 
    else {
#     define XfOrM1615_COUNT (0+XfOrM1614_COUNT)
#     define SETUP_XfOrM1615(x) SETUP_XfOrM1614(x)
      if (! ((Scheme_Type ) (((((long ) (esph ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (esph ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) || ((((Scheme_Vector * ) (esph ) ) -> size ) != count ) )
        RET_VALUE_START (((printf ("%d\n" , 7225 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
      sps = ((char * ) FUNCCALL(SETUP_XfOrM1615(_), GC_malloc_atomic (sizeof (char ) * (count ) ) )) ; 
      for (i = 0 ; i < count ; i ++ ) {
        sps [i ] = (! ((((((Scheme_Vector * ) (esph ) ) -> els ) [i ] ) ) == (scheme_false ) ) ) ; 
      }
    }
    pt -> provide_src_phases = sps ; 
  }
  if ((((esp ) ) == (scheme_false ) ) ) {
    m -> provide_protects = ((void * ) 0 ) ; 
  }
  else {
#   define XfOrM1599_COUNT (0+XfOrM1598_COUNT)
#   define SETUP_XfOrM1599(x) SETUP_XfOrM1598(x)
    if (! ((Scheme_Type ) (((((long ) (esp ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (esp ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) || ((((Scheme_Vector * ) (esp ) ) -> size ) != count ) )
      RET_VALUE_START (((printf ("%d\n" , 7237 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
    ps = ((char * ) FUNCCALL(SETUP_XfOrM1599(_), GC_malloc_atomic (sizeof (char ) * (count ) ) )) ; 
    for (i = 0 ; i < count ; i ++ ) {
      ps [i ] = (! ((((((Scheme_Vector * ) (esp ) ) -> els ) [i ] ) ) == (scheme_false ) ) ) ; 
    }
    m -> provide_protects = ps ; 
  }
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((printf ("%d\n" , 7245 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
  if (FUNCCALL(SETUP_XfOrM1598(_), scheme_proper_list_length ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ) )< 0 )
    RET_VALUE_START (((printf ("%d\n" , 7246 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
  e = FUNCCALL(SETUP_XfOrM1598(_), scheme_copy_list ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ) ); 
  m -> et_body = e ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((printf ("%d\n" , 7251 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
  if (FUNCCALL(SETUP_XfOrM1598(_), scheme_proper_list_length ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ) )< 0 )
    RET_VALUE_START (((printf ("%d\n" , 7252 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
  e = FUNCCALL(SETUP_XfOrM1598(_), scheme_copy_list ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ) ); 
  m -> body = e ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((printf ("%d\n" , 7257 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
  if (FUNCCALL(SETUP_XfOrM1598(_), scheme_proper_list_length ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ) )< 0 )
    RET_VALUE_START (((printf ("%d\n" , 7258 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
  e = FUNCCALL(SETUP_XfOrM1598(_), scheme_copy_list ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ) ); 
  m -> requires = e ; 
  if (! FUNCCALL(SETUP_XfOrM1598(_), check_requires_ok (e ) ))
    RET_VALUE_START (((printf ("%d\n" , 7261 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((printf ("%d\n" , 7264 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
  if (FUNCCALL(SETUP_XfOrM1598(_), scheme_proper_list_length ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ) )< 0 )
    RET_VALUE_START (((printf ("%d\n" , 7265 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
  e = FUNCCALL(SETUP_XfOrM1598(_), scheme_copy_list ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ) ); 
  m -> et_requires = e ; 
  if (! FUNCCALL(SETUP_XfOrM1598(_), check_requires_ok (e ) ))
    RET_VALUE_START (((printf ("%d\n" , 7268 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((printf ("%d\n" , 7271 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
  if (FUNCCALL(SETUP_XfOrM1598(_), scheme_proper_list_length ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ) )< 0 )
    RET_VALUE_START (((printf ("%d\n" , 7272 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
  e = FUNCCALL(SETUP_XfOrM1598(_), scheme_copy_list ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ) ); 
  m -> tt_requires = e ; 
  if (! FUNCCALL(SETUP_XfOrM1598(_), check_requires_ok (e ) ))
    RET_VALUE_START (((printf ("%d\n" , 7275 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  if (FUNCCALL(SETUP_XfOrM1598(_), scheme_proper_list_length (obj ) )< 0 )
    RET_VALUE_START (((printf ("%d\n" , 7278 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
  e = FUNCCALL(SETUP_XfOrM1598(_), scheme_copy_list (obj ) ); 
  m -> dt_requires = e ; 
  if (! FUNCCALL(SETUP_XfOrM1598(_), check_requires_ok (e ) ))
    RET_VALUE_START (((printf ("%d\n" , 7281 ) ) , ((void * ) 0 ) ) ) RET_VALUE_END ; 
  RET_VALUE_START ((Scheme_Object * ) m ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
