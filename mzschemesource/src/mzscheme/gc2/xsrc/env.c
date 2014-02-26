#include "precomp.h"
extern Scheme_Object * scheme_eval_compiled_sized_string (const char * str , int len , Scheme_Env * env ) ; 
extern void scheme_call_expand_observe (Scheme_Object * obs , int signal , Scheme_Object * argument ) ; 
extern void scheme_init_expand_observe (Scheme_Env * ) ; 
extern Scheme_Object * scheme_get_expand_observe () ; 
int scheme_allow_set_undefined ; 
void scheme_set_allow_set_undefined (int v ) {
  /* No conversion */
  scheme_allow_set_undefined = v ; 
}
int scheme_get_allow_set_undefined () {
  /* No conversion */
  return scheme_allow_set_undefined ; 
}
int scheme_starting_up ; 
Scheme_Object * scheme_local [64 ] [2 ] ; 
Scheme_Object * toplevels [16 ] [16 ] [0x3 + 1 ] ; 
Scheme_Hash_Table * toplevels_ht ; 
Scheme_Hash_Table * locals_ht [2 ] ; 
Scheme_Env * scheme_initial_env ; 
static Scheme_Env * make_env (Scheme_Env * base , int semi , int toplevel_size ) ; 
static void make_init_env (void ) ; 
static Scheme_Object * namespace_identifier (int , Scheme_Object * [] ) ; 
static Scheme_Object * namespace_variable_value (int , Scheme_Object * [] ) ; 
static Scheme_Object * namespace_set_variable_value (int , Scheme_Object * [] ) ; 
static Scheme_Object * namespace_undefine_variable (int , Scheme_Object * [] ) ; 
static Scheme_Object * namespace_mapped_symbols (int , Scheme_Object * [] ) ; 
static Scheme_Object * namespace_module_registry (int , Scheme_Object * [] ) ; 
static Scheme_Object * now_transforming (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * local_exp_time_value (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * local_exp_time_name (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * local_context (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * local_make_intdef_context (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * local_introduce (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * local_module_introduce (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * local_get_shadower (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * local_certify (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * local_lift_expr (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * local_lift_context (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * local_lift_end_statement (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * make_introducer (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * make_set_transformer (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * set_transformer_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * set_transformer_proc (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * make_rename_transformer (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * rename_transformer_target (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * rename_transformer_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * write_toplevel (Scheme_Object * obj ) ; 
static Scheme_Object * read_toplevel (Scheme_Object * obj ) ; 
static Scheme_Object * write_variable (Scheme_Object * obj ) ; 
static Scheme_Object * read_variable (Scheme_Object * obj ) ; 
static Scheme_Object * write_local (Scheme_Object * obj ) ; 
static Scheme_Object * read_local (Scheme_Object * obj ) ; 
static Scheme_Object * read_local_unbox (Scheme_Object * obj ) ; 
static Scheme_Object * write_resolve_prefix (Scheme_Object * obj ) ; 
static Scheme_Object * read_resolve_prefix (Scheme_Object * obj ) ; 
static void skip_certain_things (Scheme_Object * o , Scheme_Close_Custodian_Client * f , void * data ) ; 
int scheme_is_module_begin_env (Scheme_Comp_Env * env ) ; 
static void register_traversers (void ) ; 
typedef Scheme_Object * (* Lazy_Macro_Fun ) (Scheme_Object * , int ) ; 
static Scheme_Object * kernel_symbol ; 
static int intdef_counter = 0 ; 
static int builtin_ref_counter = 0 ; 
static int env_uid_counter ; 
typedef struct Compile_Data {
  int num_const ; 
  Scheme_Object * * const_names ; 
  Scheme_Object * * const_vals ; 
  Scheme_Object * * const_uids ; 
  int * use ; 
  Scheme_Object * lifts ; 
}
Compile_Data ; 
typedef struct Scheme_Full_Comp_Env {
  Scheme_Comp_Env base ; 
  Compile_Data data ; 
}
Scheme_Full_Comp_Env ; 
static void init_compile_data (Scheme_Comp_Env * env ) ; 
Scheme_Env * scheme_basic_env () {
  Scheme_Env * env ; 
  Scheme_Config * __funcarg5 = NULLED_OUT ; 
  Scheme_Config * __funcarg4 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Env * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(env, 0)));
# define XfOrM3_COUNT (1)
# define SETUP_XfOrM3(x) SETUP(XfOrM3_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  env = NULLED_OUT ; 
  if (scheme_main_thread ) {
#   define XfOrM27_COUNT (0+XfOrM3_COUNT)
#   define SETUP_XfOrM27(x) SETUP_XfOrM3(x)
    FUNCCALL(SETUP_XfOrM27(_), scheme_do_close_managed (((void * ) 0 ) , skip_certain_things ) ); 
    scheme_main_thread = ((void * ) 0 ) ; 
    FUNCCALL(SETUP_XfOrM27(_), scheme_reset_finalizations () ); 
    FUNCCALL_AGAIN(scheme_init_stack_check () ); 
    FUNCCALL_AGAIN(scheme_reset_overflow () ); 
    FUNCCALL_AGAIN(scheme_make_thread () ); 
    FUNCCALL_AGAIN(scheme_init_error_escape_proc (((void * ) 0 ) ) ); 
    env = FUNCCALL_AGAIN(scheme_make_empty_env () ); 
    FUNCCALL_AGAIN(scheme_install_initial_module_set (env ) ); 
    (__funcarg5 = FUNCCALL(SETUP_XfOrM27(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_set_param (__funcarg5 , MZCONFIG_ENV , (Scheme_Object * ) env ) )) ; 
    FUNCCALL_AGAIN(scheme_init_port_config () ); 
    FUNCCALL_AGAIN(scheme_init_port_fun_config () ); 
    FUNCCALL_AGAIN(scheme_init_error_config () ); 
    FUNCCALL_AGAIN(scheme_init_exn_config () ); 
    RET_VALUE_START (env ) RET_VALUE_END ; 
  }
  scheme_starting_up = 1 ; 
  FUNCCALL(SETUP_XfOrM3(_), scheme_init_stack_check () ); 
  FUNCCALL_AGAIN(scheme_init_overflow () ); 
  FUNCCALL_AGAIN(scheme_init_portable_case () ); 
  {
    int i , k ; 
    GC_CAN_IGNORE Scheme_Local * all ; 
#   define XfOrM20_COUNT (0+XfOrM3_COUNT)
#   define SETUP_XfOrM20(x) SETUP_XfOrM3(x)
    all = (Scheme_Local * ) FUNCCALL(SETUP_XfOrM20(_), scheme_malloc_eternal (sizeof (Scheme_Local ) * 2 * 64 ) ); 
    for (i = 0 ; i < 64 ; i ++ ) {
      for (k = 0 ; k < 2 ; k ++ ) {
        Scheme_Object * v ; 
        v = NULLED_OUT ; 
        v = (Scheme_Object * ) (all ++ ) ; 
        v -> type = k + scheme_local_type ; 
        (((Scheme_Local * ) (v ) ) -> position ) = i ; 
        scheme_local [i ] [k ] = v ; 
      }
    }
  }
  {
    int i , k , cnst ; 
    GC_CAN_IGNORE Scheme_Toplevel * all ; 
#   define XfOrM5_COUNT (0+XfOrM3_COUNT)
#   define SETUP_XfOrM5(x) SETUP_XfOrM3(x)
    all = (Scheme_Toplevel * ) FUNCCALL(SETUP_XfOrM5(_), scheme_malloc_eternal (sizeof (Scheme_Toplevel ) * 16 * 16 * (0x3 + 1 ) ) ); 
    for (i = 0 ; i < 16 ; i ++ ) {
      for (k = 0 ; k < 16 ; k ++ ) {
        for (cnst = 0 ; cnst <= 0x3 ; cnst ++ ) {
          Scheme_Toplevel * v ; 
          v = NULLED_OUT ; 
          v = (all ++ ) ; 
          v -> iso . so . type = scheme_toplevel_type ; 
          v -> depth = i ; 
          v -> position = k ; 
          (& ((Scheme_Toplevel * ) (v ) ) -> iso ) -> so . keyex = cnst ; 
          toplevels [i ] [k ] [cnst ] = (Scheme_Object * ) v ; 
        }
      }
    }
  }
  FUNCCALL(SETUP_XfOrM3(_), scheme_register_traversers () ); 
  FUNCCALL(SETUP_XfOrM3(_), register_traversers () ); 
  FUNCCALL_AGAIN(scheme_init_hash_key_procs () ); 
  FUNCCALL_AGAIN(scheme_init_true_false () ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & toplevels_ht , sizeof (toplevels_ht ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & locals_ht [0 ] , sizeof (locals_ht [0 ] ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & locals_ht [1 ] , sizeof (locals_ht [1 ] ) ) ); 
  {
    Scheme_Hash_Table * ht ; 
    BLOCK_SETUP((PUSH(ht, 0+XfOrM3_COUNT)));
#   define XfOrM4_COUNT (1+XfOrM3_COUNT)
#   define SETUP_XfOrM4(x) SETUP(XfOrM4_COUNT)
    ht = NULLED_OUT ; 
    toplevels_ht = FUNCCALL(SETUP_XfOrM4(_), scheme_make_hash_table_equal () ); 
    ht = FUNCCALL_AGAIN(scheme_make_hash_table (SCHEME_hash_ptr ) ); 
    locals_ht [0 ] = ht ; 
    ht = FUNCCALL(SETUP_XfOrM4(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
    locals_ht [1 ] = ht ; 
  }
  FUNCCALL(SETUP_XfOrM3(_), scheme_init_getenv () ); 
  FUNCCALL(SETUP_XfOrM3(_), scheme_make_thread () ); 
  FUNCCALL_AGAIN(make_init_env () ); 
  env = FUNCCALL_AGAIN(scheme_make_empty_env () ); 
  FUNCCALL_AGAIN(scheme_require_from_original_env (env , 1 ) ); 
  (__funcarg4 = FUNCCALL(SETUP_XfOrM3(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_set_param (__funcarg4 , MZCONFIG_ENV , (Scheme_Object * ) env ) )) ; 
  FUNCCALL_AGAIN(scheme_init_memtrace (env ) ); 
  FUNCCALL_AGAIN(scheme_init_parameterization (env ) ); 
  FUNCCALL_AGAIN(scheme_init_expand_observe (env ) ); 
  FUNCCALL_AGAIN(scheme_init_foreign (env ) ); 
  FUNCCALL_AGAIN(scheme_add_embedded_builtins (env ) ); 
  FUNCCALL_AGAIN(scheme_save_initial_module_set (env ) ); 
  FUNCCALL_AGAIN(scheme_init_error_escape_proc (((void * ) 0 ) ) ); 
  scheme_starting_up = 0 ; 
  RET_VALUE_START (env ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void make_init_env (void ) {
  Scheme_Env * env ; 
  Scheme_Config * __funcarg30 = NULLED_OUT ; 
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
  PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(env, 0)));
# define XfOrM28_COUNT (1)
# define SETUP_XfOrM28(x) SETUP(XfOrM28_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  env = NULLED_OUT ; 
  env = FUNCCALL(SETUP_XfOrM28(_), make_env (((void * ) 0 ) , 0 , 500 ) ); 
  (__funcarg30 = FUNCCALL(SETUP_XfOrM28(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_set_param (__funcarg30 , MZCONFIG_ENV , (Scheme_Object * ) env ) )) ; 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_initial_env , sizeof (scheme_initial_env ) ) ); 
  scheme_initial_env = env ; 
  scheme_defining_primitives = 1 ; 
  builtin_ref_counter = 0 ; 
  FUNCCALL(SETUP_XfOrM28(_), scheme_init_symbol_table () ); 
  FUNCCALL_AGAIN(scheme_init_type (env ) ); 
  FUNCCALL_AGAIN(scheme_init_symbol_type (env ) ); 
  FUNCCALL_AGAIN(scheme_init_fun (env ) ); 
  FUNCCALL_AGAIN(scheme_init_symbol (env ) ); 
  FUNCCALL_AGAIN(scheme_init_list (env ) ); 
  FUNCCALL_AGAIN(scheme_init_number (env ) ); 
  FUNCCALL_AGAIN(scheme_init_numarith (env ) ); 
  FUNCCALL_AGAIN(scheme_init_numcomp (env ) ); 
  FUNCCALL_AGAIN(scheme_init_numstr (env ) ); 
  FUNCCALL_AGAIN(scheme_init_stx (env ) ); 
  FUNCCALL_AGAIN(scheme_init_module (env ) ); 
  FUNCCALL_AGAIN(scheme_init_port (env ) ); 
  FUNCCALL_AGAIN(scheme_init_port_fun (env ) ); 
  FUNCCALL_AGAIN(scheme_init_network (env ) ); 
  FUNCCALL_AGAIN(scheme_init_string (env ) ); 
  FUNCCALL_AGAIN(scheme_init_vector (env ) ); 
  FUNCCALL_AGAIN(scheme_init_char (env ) ); 
  FUNCCALL_AGAIN(scheme_init_bool (env ) ); 
  FUNCCALL_AGAIN(scheme_init_syntax (env ) ); 
  FUNCCALL_AGAIN(scheme_init_eval (env ) ); 
  FUNCCALL_AGAIN(scheme_init_error (env ) ); 
  FUNCCALL_AGAIN(scheme_init_struct (env ) ); 
  FUNCCALL_AGAIN(scheme_init_exn (env ) ); 
  FUNCCALL_AGAIN(scheme_init_thread (env ) ); 
  FUNCCALL_AGAIN(scheme_init_sema (env ) ); 
  FUNCCALL_AGAIN(scheme_init_read (env ) ); 
  FUNCCALL_AGAIN(scheme_init_print (env ) ); 
  FUNCCALL_AGAIN(scheme_init_file (env ) ); 
  FUNCCALL_AGAIN(scheme_init_dynamic_extension (env ) ); 
  FUNCCALL_AGAIN(scheme_regexp_initialize (env ) ); 
  ; 
  (__funcarg29 = FUNCCALL(SETUP_XfOrM28(_), scheme_make_prim_w_arity (namespace_identifier , "namespace-symbol->identifier" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("namespace-symbol->identifier" , __funcarg29 , env ) )) ; 
  (__funcarg28 = FUNCCALL(SETUP_XfOrM28(_), scheme_make_prim_w_arity (namespace_variable_value , "namespace-variable-value" , 1 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("namespace-variable-value" , __funcarg28 , env ) )) ; 
  (__funcarg27 = FUNCCALL(SETUP_XfOrM28(_), scheme_make_prim_w_arity (namespace_set_variable_value , "namespace-set-variable-value!" , 2 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("namespace-set-variable-value!" , __funcarg27 , env ) )) ; 
  (__funcarg26 = FUNCCALL(SETUP_XfOrM28(_), scheme_make_prim_w_arity (namespace_undefine_variable , "namespace-undefine-variable!" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("namespace-undefine-variable!" , __funcarg26 , env ) )) ; 
  (__funcarg25 = FUNCCALL(SETUP_XfOrM28(_), scheme_make_prim_w_arity (namespace_mapped_symbols , "namespace-mapped-symbols" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("namespace-mapped-symbols" , __funcarg25 , env ) )) ; 
  (__funcarg24 = FUNCCALL(SETUP_XfOrM28(_), scheme_make_prim_w_arity (namespace_module_registry , "namespace-module-registry" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("namespace-module-registry" , __funcarg24 , env ) )) ; 
  (__funcarg23 = FUNCCALL(SETUP_XfOrM28(_), scheme_make_prim_w_arity (now_transforming , "syntax-transforming?" , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("syntax-transforming?" , __funcarg23 , env ) )) ; 
  (__funcarg22 = FUNCCALL(SETUP_XfOrM28(_), scheme_make_prim_w_arity (local_exp_time_value , "syntax-local-value" , 1 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("syntax-local-value" , __funcarg22 , env ) )) ; 
  (__funcarg21 = FUNCCALL(SETUP_XfOrM28(_), scheme_make_prim_w_arity (local_exp_time_name , "syntax-local-name" , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("syntax-local-name" , __funcarg21 , env ) )) ; 
  (__funcarg20 = FUNCCALL(SETUP_XfOrM28(_), scheme_make_prim_w_arity (local_context , "syntax-local-context" , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("syntax-local-context" , __funcarg20 , env ) )) ; 
  (__funcarg19 = FUNCCALL(SETUP_XfOrM28(_), scheme_make_prim_w_arity (local_make_intdef_context , "syntax-local-make-definition-context" , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("syntax-local-make-definition-context" , __funcarg19 , env ) )) ; 
  (__funcarg18 = FUNCCALL(SETUP_XfOrM28(_), scheme_make_prim_w_arity (local_get_shadower , "syntax-local-get-shadower" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("syntax-local-get-shadower" , __funcarg18 , env ) )) ; 
  (__funcarg17 = FUNCCALL(SETUP_XfOrM28(_), scheme_make_prim_w_arity (local_introduce , "syntax-local-introduce" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("syntax-local-introduce" , __funcarg17 , env ) )) ; 
  (__funcarg16 = FUNCCALL(SETUP_XfOrM28(_), scheme_make_prim_w_arity (make_introducer , "make-syntax-introducer" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-syntax-introducer" , __funcarg16 , env ) )) ; 
  (__funcarg15 = FUNCCALL(SETUP_XfOrM28(_), scheme_make_prim_w_arity (local_certify , "syntax-local-certifier" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("syntax-local-certifier" , __funcarg15 , env ) )) ; 
  (__funcarg14 = FUNCCALL(SETUP_XfOrM28(_), scheme_make_prim_w_arity (make_set_transformer , "make-set!-transformer" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-set!-transformer" , __funcarg14 , env ) )) ; 
  (__funcarg13 = FUNCCALL(SETUP_XfOrM28(_), scheme_make_prim_w_arity (set_transformer_p , "set!-transformer?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("set!-transformer?" , __funcarg13 , env ) )) ; 
  (__funcarg12 = FUNCCALL(SETUP_XfOrM28(_), scheme_make_prim_w_arity (set_transformer_proc , "set!-transformer-procedure" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("set!-transformer-procedure" , __funcarg12 , env ) )) ; 
  (__funcarg11 = FUNCCALL(SETUP_XfOrM28(_), scheme_make_prim_w_arity (make_rename_transformer , "make-rename-transformer" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-rename-transformer" , __funcarg11 , env ) )) ; 
  (__funcarg10 = FUNCCALL(SETUP_XfOrM28(_), scheme_make_prim_w_arity (rename_transformer_p , "rename-transformer?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("rename-transformer?" , __funcarg10 , env ) )) ; 
  (__funcarg9 = FUNCCALL(SETUP_XfOrM28(_), scheme_make_prim_w_arity (rename_transformer_target , "rename-transformer-target" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("rename-transformer-target" , __funcarg9 , env ) )) ; 
  (__funcarg8 = FUNCCALL(SETUP_XfOrM28(_), scheme_make_prim_w_arity (local_lift_expr , "syntax-local-lift-expression" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("syntax-local-lift-expression" , __funcarg8 , env ) )) ; 
  (__funcarg7 = FUNCCALL(SETUP_XfOrM28(_), scheme_make_prim_w_arity (local_lift_context , "syntax-local-lift-context" , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("syntax-local-lift-context" , __funcarg7 , env ) )) ; 
  (__funcarg6 = FUNCCALL(SETUP_XfOrM28(_), scheme_make_prim_w_arity (local_lift_end_statement , "syntax-local-lift-module-end-declaration" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("syntax-local-lift-module-end-declaration" , __funcarg6 , env ) )) ; 
  {
    Scheme_Object * sym ; 
    BLOCK_SETUP((PUSH(sym, 0+XfOrM28_COUNT)));
#   define XfOrM30_COUNT (1+XfOrM28_COUNT)
#   define SETUP_XfOrM30(x) SETUP(XfOrM30_COUNT)
    sym = NULLED_OUT ; 
    sym = FUNCCALL(SETUP_XfOrM30(_), scheme_intern_symbol ("mzscheme" ) ); 
    scheme_current_thread -> name = sym ; 
  }
  ; 
  FUNCCALL(SETUP_XfOrM28(_), scheme_install_type_writer (scheme_toplevel_type , write_toplevel ) ); 
  FUNCCALL_AGAIN(scheme_install_type_reader (scheme_toplevel_type , read_toplevel ) ); 
  FUNCCALL_AGAIN(scheme_install_type_writer (scheme_variable_type , write_variable ) ); 
  FUNCCALL_AGAIN(scheme_install_type_reader (scheme_variable_type , read_variable ) ); 
  FUNCCALL_AGAIN(scheme_install_type_writer (scheme_module_variable_type , write_variable ) ); 
  FUNCCALL_AGAIN(scheme_install_type_reader (scheme_module_variable_type , read_variable ) ); 
  FUNCCALL_AGAIN(scheme_install_type_writer (scheme_local_type , write_local ) ); 
  FUNCCALL_AGAIN(scheme_install_type_reader (scheme_local_type , read_local ) ); 
  FUNCCALL_AGAIN(scheme_install_type_writer (scheme_local_unbox_type , write_local ) ); 
  FUNCCALL_AGAIN(scheme_install_type_reader (scheme_local_unbox_type , read_local_unbox ) ); 
  FUNCCALL_AGAIN(scheme_install_type_writer (scheme_resolve_prefix_type , write_resolve_prefix ) ); 
  FUNCCALL_AGAIN(scheme_install_type_reader (scheme_resolve_prefix_type , read_resolve_prefix ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & kernel_symbol , sizeof (kernel_symbol ) ) ); 
  kernel_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("#%kernel" ) ); 
  ; 
  FUNCCALL_EMPTY(scheme_finish_kernel (env ) ); 
  if (builtin_ref_counter != 911 ) {
#   define XfOrM29_COUNT (0+XfOrM28_COUNT)
#   define SETUP_XfOrM29(x) SETUP_XfOrM28(x)
    (printf ("Primitive count %d doesn't match expected count %d\n" "Turn off USE_COMPILED_STARTUP in src/schminc.h\n" , builtin_ref_counter , 911 ) ) ; 
    FUNCCALL_EMPTY(exit (1 ) ); 
  }
  scheme_defining_primitives = 0 ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void skip_certain_things (Scheme_Object * o , Scheme_Close_Custodian_Client * f , void * data ) {
  /* No conversion */
  if ((o == scheme_orig_stdin_port ) || (o == scheme_orig_stdout_port ) || (o == scheme_orig_stderr_port ) )
    return ; 
  if (f )
    f (o , data ) ; 
}
static void create_env_marked_names (Scheme_Env * e ) {
  Scheme_Hash_Table * mn ; 
  Scheme_Object * rn ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(e, 0), PUSH(rn, 1), PUSH(mn, 2)));
# define XfOrM32_COUNT (3)
# define SETUP_XfOrM32(x) SETUP(XfOrM32_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  mn = NULLED_OUT ; 
  rn = NULLED_OUT ; 
  mn = FUNCCALL(SETUP_XfOrM32(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  FUNCCALL_AGAIN(scheme_hash_set (mn , scheme_false , scheme_null ) ); 
  e -> marked_names = mn ; 
  rn = FUNCCALL(SETUP_XfOrM32(_), scheme_make_module_rename (e -> phase , 0 , mn ) ); 
  e -> rename = rn ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Env * scheme_make_empty_env (void ) {
  Scheme_Env * e ; 
  DECL_RET_SAVE (Scheme_Env * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(e, 0)));
# define XfOrM33_COUNT (1)
# define SETUP_XfOrM33(x) SETUP(XfOrM33_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  e = NULLED_OUT ; 
  e = FUNCCALL(SETUP_XfOrM33(_), make_env (((void * ) 0 ) , 0 , 7 ) ); 
  FUNCCALL_AGAIN(create_env_marked_names (e ) ); 
  RET_VALUE_START (e ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Env * make_env (Scheme_Env * base , int semi , int toplevel_size ) {
  Scheme_Bucket_Table * toplevel , * syntax ; 
  Scheme_Hash_Table * module_registry , * export_registry ; 
  Scheme_Object * modchain ; 
  Scheme_Env * env ; 
  DECL_RET_SAVE (Scheme_Env * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(syntax, 0), PUSH(modchain, 1), PUSH(env, 2), PUSH(module_registry, 3), PUSH(base, 4), PUSH(toplevel, 5), PUSH(export_registry, 6)));
# define XfOrM34_COUNT (7)
# define SETUP_XfOrM34(x) SETUP(XfOrM34_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  toplevel = NULLED_OUT ; 
  syntax = NULLED_OUT ; 
  module_registry = NULLED_OUT ; 
  export_registry = NULLED_OUT ; 
  modchain = NULLED_OUT ; 
  env = NULLED_OUT ; 
  toplevel = FUNCCALL(SETUP_XfOrM34(_), scheme_make_bucket_table (toplevel_size , SCHEME_hash_ptr ) ); 
  toplevel -> with_home = 1 ; 
  if (semi > 0 ) {
    syntax = ((void * ) 0 ) ; 
    modchain = ((void * ) 0 ) ; 
    module_registry = ((void * ) 0 ) ; 
    export_registry = ((void * ) 0 ) ; 
  }
  else {
#   define XfOrM36_COUNT (0+XfOrM34_COUNT)
#   define SETUP_XfOrM36(x) SETUP_XfOrM34(x)
    syntax = FUNCCALL(SETUP_XfOrM36(_), scheme_make_bucket_table (7 , SCHEME_hash_ptr ) ); 
    if (base ) {
      modchain = base -> modchain ; 
      module_registry = base -> module_registry ; 
      export_registry = base -> export_registry ; 
    }
    else {
#     define XfOrM37_COUNT (0+XfOrM36_COUNT)
#     define SETUP_XfOrM37(x) SETUP_XfOrM36(x)
      if (semi < 0 ) {
        module_registry = ((void * ) 0 ) ; 
        export_registry = ((void * ) 0 ) ; 
        modchain = ((void * ) 0 ) ; 
      }
      else {
        Scheme_Hash_Table * modules ; 
        BLOCK_SETUP((PUSH(modules, 0+XfOrM37_COUNT)));
#       define XfOrM38_COUNT (1+XfOrM37_COUNT)
#       define SETUP_XfOrM38(x) SETUP(XfOrM38_COUNT)
        modules = NULLED_OUT ; 
        modules = FUNCCALL(SETUP_XfOrM38(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
        modchain = FUNCCALL_AGAIN(scheme_make_vector (3 , scheme_false ) ); 
        (((Scheme_Vector * ) (modchain ) ) -> els ) [0 ] = (Scheme_Object * ) modules ; 
        module_registry = FUNCCALL(SETUP_XfOrM38(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
        module_registry -> iso . so . type = scheme_module_registry_type ; 
        export_registry = FUNCCALL(SETUP_XfOrM38(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
      }
    }
  }
  env = ((Scheme_Env * ) FUNCCALL(SETUP_XfOrM34(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Env ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  env -> so . type = scheme_namespace_type ; 
  env -> toplevel = toplevel ; 
  if (semi < 1 ) {
    env -> syntax = syntax ; 
    env -> modchain = modchain ; 
    env -> module_registry = module_registry ; 
    env -> export_registry = export_registry ; 
  }
  RET_VALUE_START (env ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Env * scheme_new_module_env (Scheme_Env * env , Scheme_Module * m , int new_exp_module_tree ) {
  Scheme_Env * menv ; 
  DECL_RET_SAVE (Scheme_Env * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(menv, 0), PUSH(m, 1)));
# define XfOrM42_COUNT (2)
# define SETUP_XfOrM42(x) SETUP(XfOrM42_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  menv = NULLED_OUT ; 
  menv = FUNCCALL(SETUP_XfOrM42(_), make_env (env , 0 , 7 ) ); 
  menv -> module = m ; 
  if (new_exp_module_tree ) {
    Scheme_Object * p ; 
    Scheme_Hash_Table * modules ; 
    BLOCK_SETUP((PUSH(p, 0+XfOrM42_COUNT), PUSH(modules, 1+XfOrM42_COUNT)));
#   define XfOrM43_COUNT (2+XfOrM42_COUNT)
#   define SETUP_XfOrM43(x) SETUP(XfOrM43_COUNT)
    p = NULLED_OUT ; 
    modules = NULLED_OUT ; 
    modules = FUNCCALL(SETUP_XfOrM43(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
    p = FUNCCALL_AGAIN(scheme_make_vector (3 , scheme_false ) ); 
    (((Scheme_Vector * ) (p ) ) -> els ) [0 ] = (Scheme_Object * ) modules ; 
    menv -> modchain = p ; 
  }
  RET_VALUE_START (menv ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_prepare_exp_env (Scheme_Env * env ) {
  PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(env, 0)));
# define XfOrM44_COUNT (1)
# define SETUP_XfOrM44(x) SETUP(XfOrM44_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! env -> exp_env ) {
    Scheme_Env * eenv ; 
    Scheme_Object * modchain ; 
    BLOCK_SETUP((PUSH(modchain, 0+XfOrM44_COUNT), PUSH(eenv, 1+XfOrM44_COUNT)));
#   define XfOrM45_COUNT (2+XfOrM44_COUNT)
#   define SETUP_XfOrM45(x) SETUP(XfOrM45_COUNT)
    eenv = NULLED_OUT ; 
    modchain = NULLED_OUT ; 
    eenv = FUNCCALL(SETUP_XfOrM45(_), make_env (((void * ) 0 ) , - 1 , 7 ) ); 
    eenv -> phase = env -> phase + 1 ; 
    eenv -> mod_phase = env -> mod_phase + 1 ; 
    eenv -> module = env -> module ; 
    eenv -> module_registry = env -> module_registry ; 
    eenv -> export_registry = env -> export_registry ; 
    eenv -> insp = env -> insp ; 
    modchain = (((Scheme_Vector * ) (env -> modchain ) ) -> els ) [1 ] ; 
    if ((((modchain ) ) == (scheme_false ) ) ) {
      Scheme_Hash_Table * next_modules ; 
      BLOCK_SETUP((PUSH(next_modules, 0+XfOrM45_COUNT)));
#     define XfOrM46_COUNT (1+XfOrM45_COUNT)
#     define SETUP_XfOrM46(x) SETUP(XfOrM46_COUNT)
      next_modules = NULLED_OUT ; 
      next_modules = FUNCCALL(SETUP_XfOrM46(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
      modchain = FUNCCALL_AGAIN(scheme_make_vector (3 , scheme_false ) ); 
      (((Scheme_Vector * ) (modchain ) ) -> els ) [0 ] = (Scheme_Object * ) next_modules ; 
      (((Scheme_Vector * ) (env -> modchain ) ) -> els ) [1 ] = modchain ; 
      (((Scheme_Vector * ) (modchain ) ) -> els ) [2 ] = env -> modchain ; 
    }
    eenv -> modchain = modchain ; 
    env -> exp_env = eenv ; 
    eenv -> template_env = env ; 
    if (! env -> module && ! env -> phase )
      FUNCCALL_EMPTY(create_env_marked_names (eenv ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_prepare_template_env (Scheme_Env * env ) {
  PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(env, 0)));
# define XfOrM47_COUNT (1)
# define SETUP_XfOrM47(x) SETUP(XfOrM47_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! env -> template_env ) {
    Scheme_Env * eenv ; 
    Scheme_Object * modchain ; 
    BLOCK_SETUP((PUSH(modchain, 0+XfOrM47_COUNT), PUSH(eenv, 1+XfOrM47_COUNT)));
#   define XfOrM48_COUNT (2+XfOrM47_COUNT)
#   define SETUP_XfOrM48(x) SETUP(XfOrM48_COUNT)
    eenv = NULLED_OUT ; 
    modchain = NULLED_OUT ; 
    eenv = FUNCCALL(SETUP_XfOrM48(_), make_env (((void * ) 0 ) , - 1 , 7 ) ); 
    eenv -> phase = env -> phase - 1 ; 
    eenv -> mod_phase = env -> mod_phase - 1 ; 
    eenv -> module = env -> module ; 
    eenv -> module_registry = env -> module_registry ; 
    eenv -> export_registry = env -> export_registry ; 
    eenv -> insp = env -> insp ; 
    modchain = (((Scheme_Vector * ) (env -> modchain ) ) -> els ) [2 ] ; 
    if ((((modchain ) ) == (scheme_false ) ) ) {
      Scheme_Hash_Table * prev_modules ; 
      BLOCK_SETUP((PUSH(prev_modules, 0+XfOrM48_COUNT)));
#     define XfOrM49_COUNT (1+XfOrM48_COUNT)
#     define SETUP_XfOrM49(x) SETUP(XfOrM49_COUNT)
      prev_modules = NULLED_OUT ; 
      prev_modules = FUNCCALL(SETUP_XfOrM49(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
      modchain = FUNCCALL_AGAIN(scheme_make_vector (3 , scheme_false ) ); 
      (((Scheme_Vector * ) (modchain ) ) -> els ) [0 ] = (Scheme_Object * ) prev_modules ; 
      (((Scheme_Vector * ) (env -> modchain ) ) -> els ) [2 ] = modchain ; 
      (((Scheme_Vector * ) (modchain ) ) -> els ) [1 ] = env -> modchain ; 
    }
    eenv -> modchain = modchain ; 
    env -> template_env = eenv ; 
    eenv -> exp_env = env ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Env * scheme_clone_module_env (Scheme_Env * menv , Scheme_Env * ns , Scheme_Object * modchain ) {
  Scheme_Env * menv2 ; 
  DECL_RET_SAVE (Scheme_Env * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(menv2, 0), PUSH(menv, 1), PUSH(modchain, 2), PUSH(ns, 3)));
# define XfOrM50_COUNT (4)
# define SETUP_XfOrM50(x) SETUP(XfOrM50_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  menv2 = NULLED_OUT ; 
  menv2 = ((Scheme_Env * ) FUNCCALL(SETUP_XfOrM50(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Env ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  menv2 -> so . type = scheme_namespace_type ; 
  menv2 -> module = menv -> module ; 
  menv2 -> module_registry = ns -> module_registry ; 
  menv2 -> export_registry = ns -> export_registry ; 
  menv2 -> insp = menv -> insp ; 
  menv2 -> syntax = menv -> syntax ; 
  menv2 -> phase = menv -> phase ; 
  menv2 -> mod_phase = menv -> mod_phase ; 
  menv2 -> link_midx = menv -> link_midx ; 
  menv2 -> running = menv -> running ; 
  menv2 -> et_running = menv -> et_running ; 
  menv2 -> require_names = menv -> require_names ; 
  menv2 -> et_require_names = menv -> et_require_names ; 
  menv2 -> toplevel = menv -> toplevel ; 
  menv2 -> modchain = modchain ; 
  if (! ((menv2 -> module -> et_requires ) == (scheme_null ) ) ) {
#   define XfOrM52_COUNT (0+XfOrM50_COUNT)
#   define SETUP_XfOrM52(x) SETUP_XfOrM50(x)
    modchain = (((Scheme_Vector * ) (modchain ) ) -> els ) [1 ] ; 
    if ((((modchain ) ) == (scheme_false ) ) ) {
      Scheme_Hash_Table * next_modules ; 
      BLOCK_SETUP((PUSH(next_modules, 0+XfOrM52_COUNT)));
#     define XfOrM53_COUNT (1+XfOrM52_COUNT)
#     define SETUP_XfOrM53(x) SETUP(XfOrM53_COUNT)
      next_modules = NULLED_OUT ; 
      next_modules = FUNCCALL(SETUP_XfOrM53(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
      modchain = FUNCCALL_AGAIN(scheme_make_vector (3 , scheme_false ) ); 
      (((Scheme_Vector * ) (modchain ) ) -> els ) [0 ] = (Scheme_Object * ) next_modules ; 
      (((Scheme_Vector * ) (menv2 -> modchain ) ) -> els ) [1 ] = modchain ; 
      (((Scheme_Vector * ) (modchain ) ) -> els ) [2 ] = menv2 -> modchain ; 
    }
  }
  if (menv -> exp_env ) {
#   define XfOrM51_COUNT (0+XfOrM50_COUNT)
#   define SETUP_XfOrM51(x) SETUP_XfOrM50(x)
    FUNCCALL(SETUP_XfOrM51(_), scheme_prepare_exp_env (menv2 ) ); 
    menv2 -> exp_env -> toplevel = menv -> exp_env -> toplevel ; 
  }
  RET_VALUE_START (menv2 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Bucket_Table * scheme_clone_toplevel (Scheme_Bucket_Table * ht , Scheme_Env * home ) {
  Scheme_Bucket_Table * r ; 
  Scheme_Bucket * * bs ; 
  int i ; 
  DECL_RET_SAVE (Scheme_Bucket_Table * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(bs, 0), PUSH(r, 1), PUSH(home, 2), PUSH(ht, 3)));
# define XfOrM54_COUNT (4)
# define SETUP_XfOrM54(x) SETUP(XfOrM54_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  r = NULLED_OUT ; 
  bs = NULLED_OUT ; 
  r = FUNCCALL(SETUP_XfOrM54(_), scheme_make_bucket_table (ht -> size , SCHEME_hash_ptr ) ); 
  if (home )
    r -> with_home = 1 ; 
  bs = ht -> buckets ; 
  for (i = ht -> size ; i -- ; ) {
    Scheme_Bucket * b = bs [i ] ; 
    BLOCK_SETUP((PUSH(b, 0+XfOrM54_COUNT)));
#   define XfOrM58_COUNT (1+XfOrM54_COUNT)
#   define SETUP_XfOrM58(x) SETUP(XfOrM58_COUNT)
    if (b && b -> val ) {
      Scheme_Object * name = (Scheme_Object * ) b -> key ; 
      Scheme_Object * val = (Scheme_Object * ) b -> val ; 
      BLOCK_SETUP((PUSH(val, 0+XfOrM58_COUNT)));
#     define XfOrM59_COUNT (1+XfOrM58_COUNT)
#     define SETUP_XfOrM59(x) SETUP(XfOrM59_COUNT)
      b = FUNCCALL(SETUP_XfOrM59(_), scheme_bucket_from_table (r , (const char * ) name ) ); 
      b -> val = val ; 
      if (home ) {
        ; 
        ((Scheme_Bucket_With_Home * ) b ) -> home = home ; 
      }
    }
  }
  RET_VALUE_START (r ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_clean_dead_env (Scheme_Env * env ) {
  Scheme_Object * modchain , * next ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(modchain, 1), PUSH(next, 2)));
# define XfOrM61_COUNT (3)
# define SETUP_XfOrM61(x) SETUP(XfOrM61_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  modchain = NULLED_OUT ; 
  next = NULLED_OUT ; 
  if (env -> exp_env ) {
#   define XfOrM65_COUNT (0+XfOrM61_COUNT)
#   define SETUP_XfOrM65(x) SETUP_XfOrM61(x)
    env -> exp_env -> template_env = ((void * ) 0 ) ; 
    FUNCCALL(SETUP_XfOrM65(_), scheme_clean_dead_env (env -> exp_env ) ); 
    env -> exp_env = ((void * ) 0 ) ; 
  }
  if (env -> template_env ) {
#   define XfOrM64_COUNT (0+XfOrM61_COUNT)
#   define SETUP_XfOrM64(x) SETUP_XfOrM61(x)
    env -> template_env -> exp_env = ((void * ) 0 ) ; 
    FUNCCALL(SETUP_XfOrM64(_), scheme_clean_dead_env (env -> template_env ) ); 
    env -> template_env = ((void * ) 0 ) ; 
  }
  env -> modvars = ((void * ) 0 ) ; 
  modchain = env -> modchain ; 
  env -> modchain = ((void * ) 0 ) ; 
  while (modchain && ! ((Scheme_Type ) (((((long ) (modchain ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (modchain ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
    next = (((Scheme_Vector * ) (modchain ) ) -> els ) [1 ] ; 
    (((Scheme_Vector * ) (modchain ) ) -> els ) [1 ] = scheme_void ; 
    modchain = next ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_lookup_global (Scheme_Object * symbol , Scheme_Env * env ) {
  Scheme_Bucket * b ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(b, 1)));
# define XfOrM66_COUNT (2)
# define SETUP_XfOrM66(x) SETUP(XfOrM66_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  b = NULLED_OUT ; 
  b = FUNCCALL(SETUP_XfOrM66(_), scheme_bucket_or_null_from_table (env -> toplevel , (char * ) symbol , 0 ) ); 
  if (b ) {
    ; 
    if (! ((Scheme_Bucket_With_Home * ) b ) -> home )
      ((Scheme_Bucket_With_Home * ) b ) -> home = env ; 
    RET_VALUE_START ((Scheme_Object * ) b -> val ) RET_VALUE_END ; 
  }
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Bucket * scheme_global_bucket (Scheme_Object * symbol , Scheme_Env * env ) {
  Scheme_Bucket * b ; 
  DECL_RET_SAVE (Scheme_Bucket * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(b, 1)));
# define XfOrM68_COUNT (2)
# define SETUP_XfOrM68(x) SETUP(XfOrM68_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  b = NULLED_OUT ; 
  b = FUNCCALL(SETUP_XfOrM68(_), scheme_bucket_from_table (env -> toplevel , (char * ) symbol ) ); 
  ; 
  if (! ((Scheme_Bucket_With_Home * ) b ) -> home )
    ((Scheme_Bucket_With_Home * ) b ) -> home = env ; 
  RET_VALUE_START (b ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Bucket * scheme_global_keyword_bucket (Scheme_Object * symbol , Scheme_Env * env ) {
  Scheme_Bucket * b ; 
  DECL_RET_SAVE (Scheme_Bucket * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(b, 0)));
# define XfOrM69_COUNT (1)
# define SETUP_XfOrM69(x) SETUP(XfOrM69_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  b = NULLED_OUT ; 
  b = FUNCCALL(SETUP_XfOrM69(_), scheme_bucket_from_table (env -> syntax , (char * ) symbol ) ); 
  RET_VALUE_START (b ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_do_add_global_symbol (Scheme_Env * env , Scheme_Object * sym , Scheme_Object * obj , int valvar , int constant ) {
  PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(obj, 0), PUSH(env, 1), PUSH(sym, 2)));
# define XfOrM70_COUNT (3)
# define SETUP_XfOrM70(x) SETUP(XfOrM70_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (valvar ) {
    Scheme_Bucket * b ; 
    BLOCK_SETUP((PUSH(b, 0+XfOrM70_COUNT)));
#   define XfOrM71_COUNT (1+XfOrM70_COUNT)
#   define SETUP_XfOrM71(x) SETUP(XfOrM71_COUNT)
    b = NULLED_OUT ; 
    b = FUNCCALL(SETUP_XfOrM71(_), scheme_bucket_from_table (env -> toplevel , (const char * ) sym ) ); 
    b -> val = obj ; 
    ; 
    ((Scheme_Bucket_With_Home * ) b ) -> home = env ; 
    if (constant && scheme_defining_primitives ) {
      ((Scheme_Bucket_With_Flags * ) b ) -> id = builtin_ref_counter ++ ; 
      ((Scheme_Bucket_With_Flags * ) b ) -> flags |= (16 | 1 ) ; 
    }
  }
  else FUNCCALL_EMPTY(scheme_add_to_table (env -> syntax , (const char * ) sym , obj , constant ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_add_global (const char * name , Scheme_Object * obj , Scheme_Env * env ) {
  Scheme_Object * __funcarg31 = NULLED_OUT ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(obj, 0), PUSH(env, 1)));
# define XfOrM73_COUNT (2)
# define SETUP_XfOrM73(x) SETUP(XfOrM73_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  (__funcarg31 = FUNCCALL(SETUP_XfOrM73(_), scheme_intern_symbol (name ) ), FUNCCALL_AGAIN(scheme_do_add_global_symbol (env , __funcarg31 , obj , 1 , 0 ) )) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_add_global_symbol (Scheme_Object * sym , Scheme_Object * obj , Scheme_Env * env ) {
  /* No conversion */
  scheme_do_add_global_symbol (env , sym , obj , 1 , 0 ) ; 
}
void scheme_add_global_constant (const char * name , Scheme_Object * obj , Scheme_Env * env ) {
  Scheme_Object * __funcarg32 = NULLED_OUT ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(obj, 0), PUSH(env, 1)));
# define XfOrM75_COUNT (2)
# define SETUP_XfOrM75(x) SETUP(XfOrM75_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  (__funcarg32 = FUNCCALL(SETUP_XfOrM75(_), scheme_intern_symbol (name ) ), FUNCCALL_AGAIN(scheme_do_add_global_symbol (env , __funcarg32 , obj , 1 , 1 ) )) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_add_global_constant_symbol (Scheme_Object * name , Scheme_Object * obj , Scheme_Env * env ) {
  /* No conversion */
  scheme_do_add_global_symbol (env , name , obj , 1 , 1 ) ; 
}
void scheme_add_global_keyword (const char * name , Scheme_Object * obj , Scheme_Env * env ) {
  Scheme_Object * __funcarg33 = NULLED_OUT ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(obj, 0), PUSH(env, 1)));
# define XfOrM77_COUNT (2)
# define SETUP_XfOrM77(x) SETUP(XfOrM77_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  (__funcarg33 = FUNCCALL(SETUP_XfOrM77(_), scheme_intern_symbol (name ) ), FUNCCALL_AGAIN(scheme_do_add_global_symbol (env , __funcarg33 , obj , 0 , 0 ) )) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_add_global_keyword_symbol (Scheme_Object * name , Scheme_Object * obj , Scheme_Env * env ) {
  /* No conversion */
  scheme_do_add_global_symbol (env , name , obj , 0 , 0 ) ; 
}
void scheme_shadow (Scheme_Env * env , Scheme_Object * n , int stxtoo ) {
  PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(n, 0), PUSH(env, 1)));
# define XfOrM79_COUNT (2)
# define SETUP_XfOrM79(x) SETUP(XfOrM79_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (env -> rename ) {
#   define XfOrM84_COUNT (0+XfOrM79_COUNT)
#   define SETUP_XfOrM84(x) SETUP_XfOrM79(x)
    FUNCCALL(SETUP_XfOrM84(_), scheme_remove_module_rename (env -> rename , n ) ); 
    if (env -> module ) {
#     define XfOrM85_COUNT (0+XfOrM84_COUNT)
#     define SETUP_XfOrM85(x) SETUP_XfOrM84(x)
      FUNCCALL(SETUP_XfOrM85(_), scheme_extend_module_rename (env -> rename , env -> module -> self_modidx , n , n , env -> module -> self_modidx , n , env -> mod_phase , 0 ) ); 
    }
  }
  if (stxtoo ) {
#   define XfOrM81_COUNT (0+XfOrM79_COUNT)
#   define SETUP_XfOrM81(x) SETUP_XfOrM79(x)
    if (! env -> module || env -> rename ) {
#     define XfOrM82_COUNT (0+XfOrM81_COUNT)
#     define SETUP_XfOrM82(x) SETUP_XfOrM81(x)
      if (! env -> shadowed_syntax ) {
        Scheme_Hash_Table * ht ; 
        BLOCK_SETUP((PUSH(ht, 0+XfOrM82_COUNT)));
#       define XfOrM83_COUNT (1+XfOrM82_COUNT)
#       define SETUP_XfOrM83(x) SETUP(XfOrM83_COUNT)
        ht = NULLED_OUT ; 
        ht = FUNCCALL(SETUP_XfOrM83(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
        env -> shadowed_syntax = ht ; 
      }
      FUNCCALL(SETUP_XfOrM82(_), scheme_hash_set (env -> shadowed_syntax , n , scheme_true ) ); 
    }
  }
  else {
#   define XfOrM80_COUNT (0+XfOrM79_COUNT)
#   define SETUP_XfOrM80(x) SETUP_XfOrM79(x)
    if (env -> shadowed_syntax )
      FUNCCALL_EMPTY(scheme_hash_set (env -> shadowed_syntax , n , ((void * ) 0 ) ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * * scheme_make_builtin_references_table (void ) {
  Scheme_Bucket_Table * ht ; 
  Scheme_Object * * t ; 
  Scheme_Bucket * * bs ; 
  long i ; 
  DECL_RET_SAVE (Scheme_Object * * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(t, 0), PUSH(bs, 1), PUSH(ht, 2)));
# define XfOrM86_COUNT (3)
# define SETUP_XfOrM86(x) SETUP(XfOrM86_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ht = NULLED_OUT ; 
  t = NULLED_OUT ; 
  bs = NULLED_OUT ; 
  t = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM86(_), GC_malloc (sizeof (Scheme_Object * ) * ((builtin_ref_counter + 1 ) ) ) )) ; 
  ht = scheme_initial_env -> toplevel ; 
  bs = ht -> buckets ; 
  for (i = ht -> size ; i -- ; ) {
    Scheme_Bucket * b = bs [i ] ; 
    if (b && (((Scheme_Bucket_With_Flags * ) b ) -> flags & 16 ) )
      t [((Scheme_Bucket_With_Ref_Id * ) b ) -> id ] = (Scheme_Object * ) b -> val ; 
  }
  RET_VALUE_START (t ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Hash_Table * scheme_map_constants_to_globals (void ) {
  Scheme_Bucket_Table * ht ; 
  Scheme_Hash_Table * result ; 
  Scheme_Bucket * * bs ; 
  long i ; 
  DECL_RET_SAVE (Scheme_Hash_Table * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(bs, 0), PUSH(result, 1), PUSH(ht, 2)));
# define XfOrM89_COUNT (3)
# define SETUP_XfOrM89(x) SETUP(XfOrM89_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  ht = NULLED_OUT ; 
  result = NULLED_OUT ; 
  bs = NULLED_OUT ; 
  ht = scheme_initial_env -> toplevel ; 
  bs = ht -> buckets ; 
  result = FUNCCALL(SETUP_XfOrM89(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  for (i = ht -> size ; i -- ; ) {
    Scheme_Bucket * b = bs [i ] ; 
    BLOCK_SETUP((PUSH(b, 0+XfOrM89_COUNT)));
#   define XfOrM91_COUNT (1+XfOrM89_COUNT)
#   define SETUP_XfOrM91(x) SETUP(XfOrM91_COUNT)
    if (b && (((Scheme_Bucket_With_Flags * ) b ) -> flags & 1 ) )
      FUNCCALL(SETUP_XfOrM91(_), scheme_hash_set (result , b -> val , (Scheme_Object * ) b ) ); 
  }
  RET_VALUE_START (result ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void init_compile_data (Scheme_Comp_Env * env ) {
  Compile_Data * data ; 
  int i , c , * use ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(data, 1), PUSH(use, 2)));
# define XfOrM92_COUNT (3)
# define SETUP_XfOrM92(x) SETUP(XfOrM92_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  data = NULLED_OUT ; 
  use = NULLED_OUT ; 
  c = env -> num_bindings ; 
  if (c )
    use = ((int * ) FUNCCALL(SETUP_XfOrM92(_), GC_malloc_atomic (sizeof (int ) * (c ) ) )) ; 
  else use = ((void * ) 0 ) ; 
  data = (& ((Scheme_Full_Comp_Env * ) env ) -> data ) ; 
  data -> use = use ; 
  for (i = 0 ; i < c ; i ++ ) {
    use [i ] = 0 ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Comp_Env * scheme_new_compilation_frame (int num_bindings , int flags , Scheme_Comp_Env * base , Scheme_Object * certs ) {
  Scheme_Comp_Env * frame ; 
  int count ; 
  DECL_RET_SAVE (Scheme_Comp_Env * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(base, 0), PUSH(certs, 1), PUSH(frame, 2)));
# define XfOrM95_COUNT (3)
# define SETUP_XfOrM95(x) SETUP(XfOrM95_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  frame = NULLED_OUT ; 
  count = num_bindings ; 
  frame = (Scheme_Comp_Env * ) ((Scheme_Full_Comp_Env * ) FUNCCALL(SETUP_XfOrM95(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Full_Comp_Env ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  frame -> type = scheme_rt_comp_env ; 
  {
    Scheme_Object * * vals ; 
    BLOCK_SETUP((PUSH(vals, 0+XfOrM95_COUNT)));
#   define XfOrM96_COUNT (1+XfOrM95_COUNT)
#   define SETUP_XfOrM96(x) SETUP(XfOrM96_COUNT)
    vals = NULLED_OUT ; 
    vals = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM96(_), GC_malloc (sizeof (Scheme_Object * ) * (count ) ) )) ; 
    frame -> values = vals ; 
  }
  frame -> certs = certs ; 
  frame -> num_bindings = num_bindings ; 
  frame -> flags = flags | (base -> flags & 32 ) ; 
  frame -> next = base ; 
  frame -> genv = base -> genv ; 
  frame -> insp = base -> insp ; 
  frame -> prefix = base -> prefix ; 
  frame -> in_modidx = base -> in_modidx ; 
  if (flags & (32 | 64 | 128 | 256 | 512 ) )
    frame -> skip_depth = 0 ; 
  else if (base -> next )
    frame -> skip_depth = base -> skip_depth + 1 ; 
  else frame -> skip_depth = 0 ; 
  FUNCCALL(SETUP_XfOrM95(_), init_compile_data (frame ) ); 
  RET_VALUE_START (frame ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Comp_Env * scheme_new_comp_env (Scheme_Env * genv , Scheme_Object * insp , int flags ) {
  Scheme_Comp_Env * e ; 
  Comp_Prefix * cp ; 
  Scheme_Config * __funcarg34 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Comp_Env * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(e, 0), PUSH(cp, 1), PUSH(insp, 2), PUSH(genv, 3)));
# define XfOrM97_COUNT (4)
# define SETUP_XfOrM97(x) SETUP(XfOrM97_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  e = NULLED_OUT ; 
  cp = NULLED_OUT ; 
  if (! insp )
    insp = (__funcarg34 = FUNCCALL(SETUP_XfOrM97(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg34 , MZCONFIG_CODE_INSPECTOR ) )) ; 
  e = (Scheme_Comp_Env * ) ((Scheme_Full_Comp_Env * ) FUNCCALL(SETUP_XfOrM97(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Full_Comp_Env ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  e -> type = scheme_rt_comp_env ; 
  e -> num_bindings = 0 ; 
  e -> next = ((void * ) 0 ) ; 
  e -> genv = genv ; 
  e -> insp = insp ; 
  e -> flags = flags ; 
  FUNCCALL(SETUP_XfOrM97(_), init_compile_data (e ) ); 
  cp = ((Comp_Prefix * ) FUNCCALL(SETUP_XfOrM97(_), GC_malloc_one_small_tagged ((((sizeof (Comp_Prefix ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  cp -> type = scheme_rt_comp_prefix ; 
  e -> prefix = cp ; 
  RET_VALUE_START (e ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Comp_Env * scheme_new_expand_env (Scheme_Env * genv , Scheme_Object * insp , int flags ) {
  Scheme_Comp_Env * e ; 
  DECL_RET_SAVE (Scheme_Comp_Env * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(e, 0)));
# define XfOrM98_COUNT (1)
# define SETUP_XfOrM98(x) SETUP(XfOrM98_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  e = NULLED_OUT ; 
  e = FUNCCALL(SETUP_XfOrM98(_), scheme_new_comp_env (genv , insp , flags ) ); 
  e -> prefix = ((void * ) 0 ) ; 
  RET_VALUE_START (e ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_is_sub_env (Scheme_Comp_Env * stx_env , Scheme_Comp_Env * env ) {
  /* No conversion */
  Scheme_Comp_Env * se ; 
  for (se = stx_env ; ((se ) != (env ) ) ; se = se -> next ) {
    if (! (se -> flags & 256 ) )
      break ; 
  }
  return ((se ) == (env ) ) ; 
}
int scheme_used_ever (Scheme_Comp_Env * env , int which ) {
  /* No conversion */
  Compile_Data * data = (& ((Scheme_Full_Comp_Env * ) env ) -> data ) ; 
  return ! ! data -> use [which ] ; 
}
int scheme_is_env_variable_boxed (Scheme_Comp_Env * env , int which ) {
  /* No conversion */
  Compile_Data * data = (& ((Scheme_Full_Comp_Env * ) env ) -> data ) ; 
  return ! ! (data -> use [which ] & 0x4 ) ; 
}
void scheme_add_compilation_binding (int index , Scheme_Object * val , Scheme_Comp_Env * frame ) {
  /* No conversion */
  if ((index >= frame -> num_bindings ) || (index < 0 ) )
    scheme_signal_error ("internal error: scheme_add_binding: " "index out of range: %d" , index ) ; 
  frame -> values [index ] = val ; 
  frame -> skip_table = ((void * ) 0 ) ; 
}
void scheme_frame_captures_lifts (Scheme_Comp_Env * env , Scheme_Lift_Capture_Proc cp , Scheme_Object * data , Scheme_Object * end_stmts , Scheme_Object * context_key ) {
  Scheme_Lift_Capture_Proc * pp ; 
  Scheme_Object * vec ; 
  PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(end_stmts, 1), PUSH(vec, 2), PUSH(pp, 3), PUSH(data, 4), PUSH(context_key, 5)));
# define XfOrM105_COUNT (6)
# define SETUP_XfOrM105(x) SETUP(XfOrM105_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  pp = NULLED_OUT ; 
  vec = NULLED_OUT ; 
  pp = (Scheme_Lift_Capture_Proc * ) FUNCCALL(SETUP_XfOrM105(_), GC_malloc_atomic (sizeof (Scheme_Lift_Capture_Proc ) ) ); 
  * pp = cp ; 
  vec = FUNCCALL(SETUP_XfOrM105(_), scheme_make_vector (5 , ((void * ) 0 ) ) ); 
  (((Scheme_Vector * ) (vec ) ) -> els ) [0 ] = scheme_null ; 
  (((Scheme_Vector * ) (vec ) ) -> els ) [1 ] = (Scheme_Object * ) pp ; 
  (((Scheme_Vector * ) (vec ) ) -> els ) [2 ] = data ; 
  (((Scheme_Vector * ) (vec ) ) -> els ) [3 ] = end_stmts ; 
  (((Scheme_Vector * ) (vec ) ) -> els ) [4 ] = context_key ; 
  (& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> lifts = vec ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_frame_get_lifts (Scheme_Comp_Env * env ) {
  /* No conversion */
  return (((Scheme_Vector * ) ((& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> lifts ) ) -> els ) [0 ] ; 
}
Scheme_Object * scheme_frame_get_end_statement_lifts (Scheme_Comp_Env * env ) {
  /* No conversion */
  return (((Scheme_Vector * ) ((& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> lifts ) ) -> els ) [3 ] ; 
}
void scheme_add_local_syntax (int cnt , Scheme_Comp_Env * env ) {
  Scheme_Object * * ns , * * vs ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(vs, 1), PUSH(ns, 2)));
# define XfOrM108_COUNT (3)
# define SETUP_XfOrM108(x) SETUP(XfOrM108_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ns = NULLED_OUT ; 
  vs = NULLED_OUT ; 
  if (cnt ) {
#   define XfOrM109_COUNT (0+XfOrM108_COUNT)
#   define SETUP_XfOrM109(x) SETUP_XfOrM108(x)
    ns = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM109(_), GC_malloc (sizeof (Scheme_Object * ) * (cnt ) ) )) ; 
    vs = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM109(_), GC_malloc (sizeof (Scheme_Object * ) * (cnt ) ) )) ; 
    (& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> num_const = cnt ; 
    (& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> const_names = ns ; 
    (& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> const_vals = vs ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_set_local_syntax (int pos , Scheme_Object * name , Scheme_Object * val , Scheme_Comp_Env * env ) {
  /* No conversion */
  (& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> const_names [pos ] = name ; 
  (& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> const_vals [pos ] = val ; 
  env -> skip_table = ((void * ) 0 ) ; 
}
Scheme_Comp_Env * scheme_add_compilation_frame (Scheme_Object * vals , Scheme_Comp_Env * env , int flags , Scheme_Object * certs ) {
  Scheme_Comp_Env * frame ; 
  int len , i , count ; 
  DECL_RET_SAVE (Scheme_Comp_Env * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(certs, 0), PUSH(env, 1), PUSH(frame, 2), PUSH(vals, 3)));
# define XfOrM111_COUNT (4)
# define SETUP_XfOrM111(x) SETUP(XfOrM111_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  frame = NULLED_OUT ; 
  len = FUNCCALL(SETUP_XfOrM111(_), scheme_stx_list_length (vals ) ); 
  count = len ; 
  frame = FUNCCALL(SETUP_XfOrM111(_), scheme_new_compilation_frame (count , flags , env , certs ) ); 
  for (i = 0 ; i < len ; i ++ ) {
#   define XfOrM114_COUNT (0+XfOrM111_COUNT)
#   define SETUP_XfOrM114(x) SETUP_XfOrM111(x)
    if ((((Scheme_Type ) (((((long ) (vals ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vals ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (vals ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vals ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) vals ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) vals ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) )
      frame -> values [i ] = vals ; 
    else {
      Scheme_Object * a ; 
      BLOCK_SETUP((PUSH(a, 0+XfOrM114_COUNT)));
#     define XfOrM115_COUNT (1+XfOrM114_COUNT)
#     define SETUP_XfOrM115(x) SETUP(XfOrM115_COUNT)
      a = NULLED_OUT ; 
      a = (((Scheme_Type ) (((((long ) (vals ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vals ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (vals ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM115(_), scheme_stx_content (vals ) )) ) -> u . pair_val . car ) ) ; 
      frame -> values [i ] = a ; 
      vals = (((Scheme_Type ) (((((long ) (vals ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vals ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (vals ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM115(_), scheme_stx_content (vals ) )) ) -> u . pair_val . cdr ) ) ; 
    }
  }
  FUNCCALL(SETUP_XfOrM111(_), init_compile_data (frame ) ); 
  RET_VALUE_START (frame ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Comp_Env * scheme_no_defines (Scheme_Comp_Env * env ) {
  DECL_RET_SAVE (Scheme_Comp_Env * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(env, 0)));
# define XfOrM116_COUNT (1)
# define SETUP_XfOrM116(x) SETUP(XfOrM116_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (FUNCCALL(SETUP_XfOrM116(_), scheme_is_toplevel (env ) )|| FUNCCALL(SETUP_XfOrM116(_), scheme_is_module_env (env ) )|| FUNCCALL(SETUP_XfOrM116(_), scheme_is_module_begin_env (env ) )|| (env -> flags & 16 ) )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_new_compilation_frame (0 , 0 , env , ((void * ) 0 ) ) )) RET_VALUE_EMPTY_END ; 
  else RET_VALUE_START (env ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Comp_Env * scheme_require_renames (Scheme_Comp_Env * env ) {
  DECL_RET_SAVE (Scheme_Comp_Env * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(env, 0)));
# define XfOrM117_COUNT (1)
# define SETUP_XfOrM117(x) SETUP(XfOrM117_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (env -> flags & 32 ) {
#   define XfOrM118_COUNT (0+XfOrM117_COUNT)
#   define SETUP_XfOrM118(x) SETUP_XfOrM117(x)
    env = FUNCCALL(SETUP_XfOrM118(_), scheme_new_compilation_frame (0 , 0 , env , ((void * ) 0 ) ) ); 
    env -> flags -= 32 ; 
  }
  RET_VALUE_START (env ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_is_toplevel (Scheme_Comp_Env * env ) {
  /* No conversion */
  return ! env -> next || (env -> flags & 1 ) ; 
}
int scheme_is_module_env (Scheme_Comp_Env * env ) {
  /* No conversion */
  return ! ! (env -> flags & 4 ) ; 
}
int scheme_is_module_begin_env (Scheme_Comp_Env * env ) {
  /* No conversion */
  return ! ! (env -> flags & 2 ) ; 
}
Scheme_Comp_Env * scheme_extend_as_toplevel (Scheme_Comp_Env * env ) {
  DECL_RET_SAVE (Scheme_Comp_Env * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(env, 0)));
# define XfOrM122_COUNT (1)
# define SETUP_XfOrM122(x) SETUP(XfOrM122_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (FUNCCALL(SETUP_XfOrM122(_), scheme_is_toplevel (env ) ))
    RET_VALUE_START (env ) RET_VALUE_END ; 
  else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_new_compilation_frame (0 , 1 , env , ((void * ) 0 ) ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_toplevel (mzshort depth , int position , int resolved , int flags ) {
  Scheme_Toplevel * tl ; 
  Scheme_Object * v , * pr ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(tl, 0), PUSH(v, 1), PUSH(pr, 2)));
# define XfOrM123_COUNT (3)
# define SETUP_XfOrM123(x) SETUP(XfOrM123_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  tl = NULLED_OUT ; 
  v = NULLED_OUT ; 
  pr = NULLED_OUT ; 
  if (resolved ) {
#   define XfOrM126_COUNT (0+XfOrM123_COUNT)
#   define SETUP_XfOrM126(x) SETUP_XfOrM123(x)
    if ((depth < 16 ) && (position < 16 ) )
      RET_VALUE_START (toplevels [depth ] [position ] [flags ] ) RET_VALUE_END ; 
    pr = (flags ? FUNCCALL(SETUP_XfOrM126(_), scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (position ) ) << 1 ) | 0x1 ) ) , ((Scheme_Object * ) (void * ) (long ) ((((long ) (flags ) ) << 1 ) | 0x1 ) ) ) ): ((Scheme_Object * ) (void * ) (long ) ((((long ) (position ) ) << 1 ) | 0x1 ) ) ) ; 
    pr = FUNCCALL(SETUP_XfOrM126(_), scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (depth ) ) << 1 ) | 0x1 ) ) , pr ) ); 
    v = FUNCCALL_AGAIN(scheme_hash_get_atomic (toplevels_ht , pr ) ); 
    if (v )
      RET_VALUE_START (v ) RET_VALUE_END ; 
  }
  else pr = ((void * ) 0 ) ; 
  tl = (Scheme_Toplevel * ) FUNCCALL(SETUP_XfOrM123(_), GC_malloc_one_tagged (sizeof (Scheme_Toplevel ) ) ); 
  tl -> iso . so . type = (resolved ? scheme_toplevel_type : scheme_compiled_toplevel_type ) ; 
  tl -> depth = depth ; 
  tl -> position = position ; 
  (& ((Scheme_Toplevel * ) (tl ) ) -> iso ) -> so . keyex = flags ; 
  if (resolved ) {
#   define XfOrM124_COUNT (0+XfOrM123_COUNT)
#   define SETUP_XfOrM124(x) SETUP_XfOrM123(x)
    if (toplevels_ht -> count > 2048 ) {
#     define XfOrM125_COUNT (0+XfOrM124_COUNT)
#     define SETUP_XfOrM125(x) SETUP_XfOrM124(x)
      toplevels_ht = FUNCCALL(SETUP_XfOrM125(_), scheme_make_hash_table_equal () ); 
    }
    FUNCCALL(SETUP_XfOrM124(_), scheme_hash_set_atomic (toplevels_ht , pr , (Scheme_Object * ) tl ) ); 
  }
  RET_VALUE_START ((Scheme_Object * ) tl ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_register_toplevel_in_prefix (Scheme_Object * var , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  Comp_Prefix * cp = env -> prefix ; 
  Scheme_Hash_Table * ht ; 
  Scheme_Object * o ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(cp, 1), PUSH(var, 2), PUSH(ht, 3)));
# define XfOrM127_COUNT (4)
# define SETUP_XfOrM127(x) SETUP(XfOrM127_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ht = NULLED_OUT ; 
  o = NULLED_OUT ; 
  if (rec && rec [drec ] . dont_mark_local_use ) {
#   define XfOrM129_COUNT (0+XfOrM127_COUNT)
#   define SETUP_XfOrM129(x) SETUP_XfOrM127(x)
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(make_toplevel (0 , 0 , 0 , 0 ) )) RET_VALUE_EMPTY_END ; 
  }
  ht = cp -> toplevels ; 
  if (! ht ) {
#   define XfOrM128_COUNT (0+XfOrM127_COUNT)
#   define SETUP_XfOrM128(x) SETUP_XfOrM127(x)
    ht = FUNCCALL(SETUP_XfOrM128(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
    cp -> toplevels = ht ; 
  }
  o = FUNCCALL(SETUP_XfOrM127(_), scheme_hash_get (ht , var ) ); 
  if (o )
    RET_VALUE_START (o ) RET_VALUE_END ; 
  o = FUNCCALL(SETUP_XfOrM127(_), make_toplevel (0 , cp -> num_toplevels , 0 , 0 ) ); 
  cp -> num_toplevels ++ ; 
  FUNCCALL(SETUP_XfOrM127(_), scheme_hash_set (ht , var , o ) ); 
  RET_VALUE_START (o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_toplevel_to_flagged_toplevel (Scheme_Object * _tl , int flags ) {
  /* No conversion */
  Scheme_Toplevel * tl = (Scheme_Toplevel * ) _tl ; 
  return make_toplevel (tl -> depth , tl -> position , 0 , flags ) ; 
}
Scheme_Object * scheme_register_stx_in_prefix (Scheme_Object * var , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  Comp_Prefix * cp = env -> prefix ; 
  Scheme_Local * l ; 
  Scheme_Object * o ; 
  int pos ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(cp, 1), PUSH(var, 2), PUSH(l, 3)));
# define XfOrM131_COUNT (4)
# define SETUP_XfOrM131(x) SETUP(XfOrM131_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  l = NULLED_OUT ; 
  o = NULLED_OUT ; 
  if (rec && rec [drec ] . dont_mark_local_use ) {
#   define XfOrM133_COUNT (0+XfOrM131_COUNT)
#   define SETUP_XfOrM133(x) SETUP_XfOrM131(x)
    l = (Scheme_Local * ) FUNCCALL(SETUP_XfOrM133(_), GC_malloc_one_tagged (sizeof (Scheme_Local ) ) ); 
    l -> so . type = scheme_compiled_quote_syntax_type ; 
    l -> position = 0 ; 
    RET_VALUE_START ((Scheme_Object * ) l ) RET_VALUE_END ; 
  }
  if (! cp -> stxes ) {
    Scheme_Hash_Table * ht ; 
    BLOCK_SETUP((PUSH(ht, 0+XfOrM131_COUNT)));
#   define XfOrM132_COUNT (1+XfOrM131_COUNT)
#   define SETUP_XfOrM132(x) SETUP(XfOrM132_COUNT)
    ht = NULLED_OUT ; 
    ht = FUNCCALL(SETUP_XfOrM132(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
    cp -> stxes = ht ; 
  }
  pos = cp -> num_stxes ; 
  l = (Scheme_Local * ) FUNCCALL(SETUP_XfOrM131(_), GC_malloc_one_tagged (sizeof (Scheme_Local ) ) ); 
  l -> so . type = scheme_compiled_quote_syntax_type ; 
  l -> position = pos ; 
  cp -> num_stxes ++ ; 
  o = (Scheme_Object * ) l ; 
  FUNCCALL(SETUP_XfOrM131(_), scheme_hash_set (cp -> stxes , var , o ) ); 
  RET_VALUE_START (o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * alloc_local (short type , int pos ) {
  Scheme_Object * v ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(v, 0)));
# define XfOrM134_COUNT (1)
# define SETUP_XfOrM134(x) SETUP(XfOrM134_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  v = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM134(_), GC_malloc_one_tagged (sizeof (Scheme_Local ) ) ); 
  v -> type = type ; 
  (((Scheme_Local * ) (v ) ) -> position ) = pos ; 
  RET_VALUE_START ((Scheme_Object * ) v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_local (Scheme_Type type , int pos ) {
  int k ; 
  Scheme_Object * v ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(v, 0)));
# define XfOrM135_COUNT (1)
# define SETUP_XfOrM135(x) SETUP(XfOrM135_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  v = NULLED_OUT ; 
  k = type - scheme_local_type ; 
  if (pos < 64 ) {
    if (pos >= 0 )
      RET_VALUE_START (scheme_local [pos ] [k ] ) RET_VALUE_END ; 
  }
  v = FUNCCALL(SETUP_XfOrM135(_), scheme_hash_get (locals_ht [k ] , ((Scheme_Object * ) (void * ) (long ) ((((long ) (pos ) ) << 1 ) | 0x1 ) ) ) ); 
  if (v )
    RET_VALUE_START (v ) RET_VALUE_END ; 
  v = FUNCCALL(SETUP_XfOrM135(_), alloc_local (type , pos ) ); 
  if (locals_ht [k ] -> count > 2048 ) {
    Scheme_Hash_Table * ht ; 
    BLOCK_SETUP((PUSH(ht, 0+XfOrM135_COUNT)));
#   define XfOrM136_COUNT (1+XfOrM135_COUNT)
#   define SETUP_XfOrM136(x) SETUP(XfOrM136_COUNT)
    ht = NULLED_OUT ; 
    ht = FUNCCALL(SETUP_XfOrM136(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
    locals_ht [k ] = ht ; 
  }
  FUNCCALL(SETUP_XfOrM135(_), scheme_hash_set (locals_ht [k ] , ((Scheme_Object * ) (void * ) (long ) ((((long ) (pos ) ) << 1 ) | 0x1 ) ) , v ) ); 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * force_lazy_macro (Scheme_Object * val , long phase ) {
  /* No conversion */
  Lazy_Macro_Fun f = (Lazy_Macro_Fun ) (((Scheme_Simple_Object * ) (val ) ) -> u . two_ptr_val . ptr1 ) ; 
  Scheme_Object * data = (((Scheme_Simple_Object * ) (val ) ) -> u . two_ptr_val . ptr2 ) ; 
  return f (data , phase ) ; 
}
static Scheme_Local * get_frame_loc (Scheme_Comp_Env * frame , int i , int j , int p , int flags ) {
  /* No conversion */
  int cnt , u ; 
  u = (& ((Scheme_Full_Comp_Env * ) frame ) -> data ) -> use [i ] ; 
  u |= (((flags & (2 | 4 | 4096 ) ) ? 0x2 : ((u & (0x1 | 0x8 ) ) ? 0x1 : 0x8 ) ) | ((flags & (4 | 4096 | 64 ) ) ? 0x4 : 0 ) ) ; 
  cnt = ((u & 0x70 ) >> 4 ) ; 
  if (cnt < (0x70 >> 4 ) )
    cnt ++ ; 
  u -= (u & 0x70 ) ; 
  u |= (cnt << 4 ) ; 
  (& ((Scheme_Full_Comp_Env * ) frame ) -> data ) -> use [i ] = u ; 
  return (Scheme_Local * ) scheme_make_local (scheme_local_type , p + i ) ; 
}
Scheme_Object * scheme_hash_module_variable (Scheme_Env * env , Scheme_Object * modidx , Scheme_Object * stxsym , Scheme_Object * insp , int pos , int mod_phase ) {
  Scheme_Object * val ; 
  Scheme_Hash_Table * ht ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(val, 0), PUSH(stxsym, 1), PUSH(env, 2), PUSH(ht, 3), PUSH(insp, 4), PUSH(modidx, 5)));
# define XfOrM140_COUNT (6)
# define SETUP_XfOrM140(x) SETUP(XfOrM140_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  val = NULLED_OUT ; 
  ht = NULLED_OUT ; 
  if (! env -> modvars ) {
#   define XfOrM152_COUNT (0+XfOrM140_COUNT)
#   define SETUP_XfOrM152(x) SETUP_XfOrM140(x)
    ht = FUNCCALL(SETUP_XfOrM152(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
    env -> modvars = ht ; 
  }
  stxsym = (((Scheme_Type ) (((((long ) (stxsym ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (stxsym ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ? ((Scheme_Stx * ) stxsym ) -> val : stxsym ) ; 
  ht = (Scheme_Hash_Table * ) FUNCCALL(SETUP_XfOrM140(_), scheme_hash_get (env -> modvars , modidx ) ); 
  if (! ht ) {
#   define XfOrM151_COUNT (0+XfOrM140_COUNT)
#   define SETUP_XfOrM151(x) SETUP_XfOrM140(x)
    ht = FUNCCALL(SETUP_XfOrM151(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
    FUNCCALL(SETUP_XfOrM151(_), scheme_hash_set (env -> modvars , modidx , (Scheme_Object * ) ht ) ); 
  }
  while (1 ) {
#   define XfOrM146_COUNT (0+XfOrM140_COUNT)
#   define SETUP_XfOrM146(x) SETUP_XfOrM140(x)
    val = FUNCCALL(SETUP_XfOrM146(_), scheme_hash_get (ht , stxsym ) ); 
    if (! val ) {
      Module_Variable * mv ; 
      BLOCK_SETUP((PUSH(mv, 0+XfOrM146_COUNT)));
#     define XfOrM150_COUNT (1+XfOrM146_COUNT)
#     define SETUP_XfOrM150(x) SETUP(XfOrM150_COUNT)
      mv = NULLED_OUT ; 
      mv = ((Module_Variable * ) FUNCCALL(SETUP_XfOrM150(_), GC_malloc_one_small_tagged ((((sizeof (Module_Variable ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
      mv -> so . type = scheme_module_variable_type ; 
      mv -> modidx = modidx ; 
      mv -> sym = stxsym ; 
      mv -> insp = insp ; 
      mv -> pos = pos ; 
      mv -> mod_phase = mod_phase ; 
      val = (Scheme_Object * ) mv ; 
      FUNCCALL(SETUP_XfOrM150(_), scheme_hash_set (ht , stxsym , val ) ); 
      break ; 
    }
    else {
      Module_Variable * mv = (Module_Variable * ) val ; 
#     define XfOrM147_COUNT (0+XfOrM146_COUNT)
#     define SETUP_XfOrM147(x) SETUP_XfOrM146(x)
      if (! ((mv -> insp ) == (insp ) ) ) {
#       define XfOrM148_COUNT (0+XfOrM147_COUNT)
#       define SETUP_XfOrM148(x) SETUP_XfOrM147(x)
        val = FUNCCALL(SETUP_XfOrM148(_), scheme_hash_get (ht , insp ) ); 
        if (! val ) {
          Scheme_Hash_Table * ht2 ; 
          BLOCK_SETUP((PUSH(ht2, 0+XfOrM148_COUNT)));
#         define XfOrM149_COUNT (1+XfOrM148_COUNT)
#         define SETUP_XfOrM149(x) SETUP(XfOrM149_COUNT)
          ht2 = NULLED_OUT ; 
          ht2 = FUNCCALL(SETUP_XfOrM149(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
          FUNCCALL_AGAIN(scheme_hash_set (ht , insp , (Scheme_Object * ) ht2 ) ); 
          ht = ht2 ; 
        }
        else ht = (Scheme_Hash_Table * ) val ; 
      }
      else break ; 
    }
  }
  RET_VALUE_START (val ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_tl_id_sym (Scheme_Env * env , Scheme_Object * id , Scheme_Object * bdg , int is_def ) {
  Scheme_Object * marks = ((void * ) 0 ) , * sym , * map , * l , * a , * amarks , * m , * best_match , * cm , * abdg ; 
  int best_match_skipped , ms , one_mark ; 
  Scheme_Hash_Table * marked_names ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(16);
  BLOCK_SETUP_TOP((PUSH(m, 0), PUSH(a, 1), PUSH(cm, 2), PUSH(abdg, 3), PUSH(map, 4), PUSH(best_match, 5), PUSH(sym, 6), PUSH(l, 7), PUSH(amarks, 8), PUSH(bdg, 9), PUSH(id, 10), PUSH(marked_names, 11), PUSH(env, 12), PUSH(marks, 13)));
# define XfOrM153_COUNT (14)
# define SETUP_XfOrM153(x) SETUP(XfOrM153_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  sym = NULLED_OUT ; 
  map = NULLED_OUT ; 
  l = NULLED_OUT ; 
  a = NULLED_OUT ; 
  amarks = NULLED_OUT ; 
  m = NULLED_OUT ; 
  best_match = NULLED_OUT ; 
  cm = NULLED_OUT ; 
  abdg = NULLED_OUT ; 
  marked_names = NULLED_OUT ; 
  sym = (((Scheme_Type ) (((((long ) (id ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (id ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ? ((Scheme_Stx * ) id ) -> val : id ) ; 
  if (((Scheme_Type ) (((((long ) ((Scheme_Object * ) env ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((Scheme_Object * ) env ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) )
    marked_names = (Scheme_Hash_Table * ) env ; 
  else {
    if (! is_def && ! env -> marked_names )
      RET_VALUE_START (sym ) RET_VALUE_END ; 
    marked_names = env -> marked_names ; 
  }
  if (is_def ) {
#   define XfOrM200_COUNT (0+XfOrM153_COUNT)
#   define SETUP_XfOrM200(x) SETUP_XfOrM153(x)
    if (! bdg )
      bdg = FUNCCALL(SETUP_XfOrM200(_), scheme_stx_moduleless_env (id , 0 ) ); 
    marks = FUNCCALL(SETUP_XfOrM200(_), scheme_stx_extract_marks (id ) ); 
    if (((marks ) == (scheme_null ) ) && (((bdg ) ) == (scheme_false ) ) )
      RET_VALUE_START (sym ) RET_VALUE_END ; 
  }
  if (! marked_names ) {
#   define XfOrM199_COUNT (0+XfOrM153_COUNT)
#   define SETUP_XfOrM199(x) SETUP_XfOrM153(x)
    marked_names = FUNCCALL(SETUP_XfOrM199(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
    env -> marked_names = marked_names ; 
  }
  map = FUNCCALL(SETUP_XfOrM153(_), scheme_hash_get (marked_names , sym ) ); 
  if (! map ) {
    if (! is_def )
      RET_VALUE_START (sym ) RET_VALUE_END ; 
    else map = scheme_null ; 
  }
  if (! bdg ) {
#   define XfOrM197_COUNT (0+XfOrM153_COUNT)
#   define SETUP_XfOrM197(x) SETUP_XfOrM153(x)
    bdg = FUNCCALL(SETUP_XfOrM197(_), scheme_stx_moduleless_env (id , 0 ) ); 
  }
  if (! marks ) {
#   define XfOrM196_COUNT (0+XfOrM153_COUNT)
#   define SETUP_XfOrM196(x) SETUP_XfOrM153(x)
    marks = FUNCCALL(SETUP_XfOrM196(_), scheme_stx_extract_marks (id ) ); 
    if (((marks ) == (scheme_null ) ) && (((bdg ) ) == (scheme_false ) ) )
      RET_VALUE_START (sym ) RET_VALUE_END ; 
  }
  best_match = ((void * ) 0 ) ; 
  best_match_skipped = FUNCCALL(SETUP_XfOrM153(_), scheme_list_length (marks ) ); 
  if (best_match_skipped == 1 ) {
    marks = (((Scheme_Simple_Object * ) (marks ) ) -> u . pair_val . car ) ; 
    one_mark = 1 ; 
  }
  else one_mark = 0 ; 
  if (! (! (((bdg ) ) == (scheme_false ) ) ) )
    bdg = ((void * ) 0 ) ; 
  for (l = map ; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#   define XfOrM180_COUNT (0+XfOrM153_COUNT)
#   define SETUP_XfOrM180(x) SETUP_XfOrM153(x)
    a = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
    amarks = (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) ; 
    if (((Scheme_Type ) (((((long ) (amarks ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (amarks ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
      abdg = (((Scheme_Vector * ) (amarks ) ) -> els ) [1 ] ; 
      amarks = (((Scheme_Vector * ) (amarks ) ) -> els ) [0 ] ; 
    }
    else abdg = ((void * ) 0 ) ; 
    if (((abdg ) == (bdg ) ) ) {
#     define XfOrM181_COUNT (0+XfOrM180_COUNT)
#     define SETUP_XfOrM181(x) SETUP_XfOrM180(x)
      if (is_def ) {
#       define XfOrM192_COUNT (0+XfOrM181_COUNT)
#       define SETUP_XfOrM192(x) SETUP_XfOrM181(x)
        if (FUNCCALL(SETUP_XfOrM192(_), scheme_equal (amarks , marks ) )) {
          best_match = (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) ; 
          break ; 
        }
      }
      else {
#       define XfOrM182_COUNT (0+XfOrM181_COUNT)
#       define SETUP_XfOrM182(x) SETUP_XfOrM181(x)
        if (! ((Scheme_Type ) (((((long ) (marks ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (marks ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#         define XfOrM190_COUNT (0+XfOrM182_COUNT)
#         define SETUP_XfOrM190(x) SETUP_XfOrM182(x)
          if (FUNCCALL(SETUP_XfOrM190(_), scheme_equal (amarks , marks ) )) {
            best_match = (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) ; 
            best_match_skipped = 0 ; 
          }
        }
        else {
#         define XfOrM183_COUNT (0+XfOrM182_COUNT)
#         define SETUP_XfOrM183(x) SETUP_XfOrM182(x)
          for (m = marks , ms = 0 ; ((Scheme_Type ) (((((long ) (m ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (m ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && (ms < best_match_skipped ) ; m = (((Scheme_Simple_Object * ) (m ) ) -> u . pair_val . cdr ) , ms ++ ) {
#           define XfOrM187_COUNT (0+XfOrM183_COUNT)
#           define SETUP_XfOrM187(x) SETUP_XfOrM183(x)
            cm = m ; 
            if (! ((Scheme_Type ) (((((long ) (amarks ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (amarks ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
              if ((((((Scheme_Simple_Object * ) (m ) ) -> u . pair_val . cdr ) ) == (scheme_null ) ) )
                cm = (((Scheme_Simple_Object * ) (m ) ) -> u . pair_val . car ) ; 
            }
            if (FUNCCALL(SETUP_XfOrM187(_), scheme_equal (amarks , cm ) )) {
              best_match = (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) ; 
              best_match_skipped = ms ; 
              break ; 
            }
          }
        }
      }
    }
  }
  if (! best_match ) {
#   define XfOrM154_COUNT (0+XfOrM153_COUNT)
#   define SETUP_XfOrM154(x) SETUP_XfOrM153(x)
    if (! is_def ) {
      RET_VALUE_START (sym ) RET_VALUE_END ; 
    }
    if (! ((Scheme_Type ) (((((long ) ((Scheme_Object * ) env ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((Scheme_Object * ) env ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) && env -> module && (is_def != 2 ) ) {
      Scheme_Object * mod , * nm = id ; 
      BLOCK_SETUP((PUSH(nm, 0+XfOrM154_COUNT), PUSH(mod, 1+XfOrM154_COUNT)));
#     define XfOrM163_COUNT (2+XfOrM154_COUNT)
#     define SETUP_XfOrM163(x) SETUP(XfOrM163_COUNT)
      mod = NULLED_OUT ; 
      mod = FUNCCALL(SETUP_XfOrM163(_), scheme_stx_module_name (& nm , env -> phase , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
      if (mod && ((nm ) != (sym ) ) )
        best_match = nm ; 
    }
    if (! best_match ) {
      char onstack [50 ] , * buf ; 
      int len ; 
      BLOCK_SETUP((PUSH(buf, 0+XfOrM154_COUNT)));
#     define XfOrM156_COUNT (1+XfOrM154_COUNT)
#     define SETUP_XfOrM156(x) SETUP(XfOrM156_COUNT)
      buf = NULLED_OUT ; 
      while (1 ) {
#       define XfOrM160_COUNT (0+XfOrM156_COUNT)
#       define SETUP_XfOrM160(x) SETUP_XfOrM156(x)
        env -> id_counter ++ ; 
        len = (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (sym ) ) ) -> len ) ; 
        if (len <= 35 )
          buf = onstack ; 
        else buf = FUNCCALL(SETUP_XfOrM160(_), GC_malloc_atomic (len + 15 ) ); 
        (memcpy (buf , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (sym ) ) ) -> s ) , len ) ) ; 
        (sprintf (buf + len , ".%d" , env -> id_counter ) ) ; 
        best_match = FUNCCALL(SETUP_XfOrM160(_), scheme_intern_exact_parallel_symbol (buf , strlen (buf ) ) ); 
        if (! FUNCCALL(SETUP_XfOrM160(_), scheme_stx_parallel_is_used (best_match , id ) )) {
#         define XfOrM161_COUNT (0+XfOrM160_COUNT)
#         define SETUP_XfOrM161(x) SETUP_XfOrM160(x)
          if (! FUNCCALL(SETUP_XfOrM161(_), scheme_tl_id_is_sym_used (marked_names , best_match ) )) {
            break ; 
          }
        }
      }
    }
    if (bdg ) {
#     define XfOrM155_COUNT (0+XfOrM154_COUNT)
#     define SETUP_XfOrM155(x) SETUP_XfOrM154(x)
      a = FUNCCALL(SETUP_XfOrM155(_), scheme_make_vector (2 , ((void * ) 0 ) ) ); 
      (((Scheme_Vector * ) (a ) ) -> els ) [0 ] = marks ; 
      (((Scheme_Vector * ) (a ) ) -> els ) [1 ] = bdg ; 
      marks = a ; 
    }
    a = FUNCCALL(SETUP_XfOrM154(_), scheme_make_pair (marks , best_match ) ); 
    map = FUNCCALL(SETUP_XfOrM154(_), scheme_make_pair (a , map ) ); 
    FUNCCALL_AGAIN(scheme_hash_set (marked_names , sym , map ) ); 
  }
  RET_VALUE_START (best_match ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_tl_id_is_sym_used (Scheme_Hash_Table * marked_names , Scheme_Object * sym ) {
  /* No conversion */
  int i ; 
  Scheme_Object * l , * a ; 
  if (! marked_names )
    return 0 ; 
  for (i = marked_names -> size ; i -- ; ) {
    l = marked_names -> vals [i ] ; 
    if (l ) {
      for (; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
        a = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
        if (((sym ) == ((((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) ) ) )
          return 1 ; 
      }
    }
  }
  return 0 ; 
}
static Scheme_Object * make_uid () {
  /* No conversion */
  char name [20 ] ; 
  sprintf (name , "env%d" , env_uid_counter ++ ) ; 
  return scheme_make_symbol (name ) ; 
}
Scheme_Object * scheme_env_frame_uid (Scheme_Comp_Env * env ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(env, 0)));
# define XfOrM212_COUNT (1)
# define SETUP_XfOrM212(x) SETUP(XfOrM212_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (env -> flags & (32 | 64 | 512 ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  if (! env -> uid ) {
    Scheme_Object * sym ; 
    BLOCK_SETUP((PUSH(sym, 0+XfOrM212_COUNT)));
#   define XfOrM213_COUNT (1+XfOrM212_COUNT)
#   define SETUP_XfOrM213(x) SETUP(XfOrM213_COUNT)
    sym = NULLED_OUT ; 
    sym = FUNCCALL(SETUP_XfOrM213(_), make_uid () ); 
    env -> uid = sym ; 
  }
  RET_VALUE_START (env -> uid ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void make_env_renames (Scheme_Comp_Env * env , int rcount , int rstart , int rstart_sec , int force_multi , Scheme_Object * stx ) {
  Scheme_Object * rnm ; 
  Scheme_Object * uid = ((void * ) 0 ) ; 
  int i , pos ; 
  Scheme_Object * __funcarg35 = NULLED_OUT ; 
  PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(stx, 0), PUSH(rnm, 1), PUSH(uid, 2), PUSH(env, 3)));
# define XfOrM214_COUNT (4)
# define SETUP_XfOrM214(x) SETUP(XfOrM214_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  rnm = NULLED_OUT ; 
  if (env -> flags & (32 | 64 | 512 ) )
    RET_NOTHING ; 
  FUNCCALL(SETUP_XfOrM214(_), scheme_env_frame_uid (env ) ); 
  if (force_multi ) {
#   define XfOrM224_COUNT (0+XfOrM214_COUNT)
#   define SETUP_XfOrM224(x) SETUP_XfOrM214(x)
    if (env -> num_bindings && ! env -> uids ) {
      Scheme_Object * * uids ; 
      BLOCK_SETUP((PUSH(uids, 0+XfOrM224_COUNT)));
#     define XfOrM227_COUNT (1+XfOrM224_COUNT)
#     define SETUP_XfOrM227(x) SETUP(XfOrM227_COUNT)
      uids = NULLED_OUT ; 
      uids = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM227(_), GC_malloc (sizeof (Scheme_Object * ) * (env -> num_bindings ) ) )) ; 
      env -> uids = uids ; 
    }
    if ((& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> num_const && ! (& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> const_uids ) {
      Scheme_Object * * cuids ; 
      BLOCK_SETUP((PUSH(cuids, 0+XfOrM224_COUNT)));
#     define XfOrM226_COUNT (1+XfOrM224_COUNT)
#     define SETUP_XfOrM226(x) SETUP(XfOrM226_COUNT)
      cuids = NULLED_OUT ; 
      cuids = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM226(_), GC_malloc (sizeof (Scheme_Object * ) * ((& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> num_const ) ) )) ; 
      (& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> const_uids = cuids ; 
    }
    if (env -> uid && ! (((env -> uid ) ) == (scheme_false ) ) ) {
      uid = env -> uid ; 
      env -> uid = scheme_false ; 
    }
  }
  if (! uid ) {
#   define XfOrM221_COUNT (0+XfOrM214_COUNT)
#   define SETUP_XfOrM221(x) SETUP_XfOrM214(x)
    if (env -> uid && (! (((env -> uid ) ) == (scheme_false ) ) ) ) {
      uid = env -> uid ; 
    }
    else {
#     define XfOrM222_COUNT (0+XfOrM221_COUNT)
#     define SETUP_XfOrM222(x) SETUP_XfOrM221(x)
      if (! rstart_sec )
        uid = (& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> const_uids [rstart ] ; 
      else uid = env -> uids [rstart ] ; 
      if (! uid )
        uid = FUNCCALL(SETUP_XfOrM222(_), make_uid () ); 
    }
  }
  rnm = FUNCCALL(SETUP_XfOrM214(_), scheme_make_rename (uid , rcount ) ); 
  pos = 0 ; 
  if (! rstart_sec ) {
#   define XfOrM218_COUNT (0+XfOrM214_COUNT)
#   define SETUP_XfOrM218(x) SETUP_XfOrM214(x)
    for (i = rstart ; (i < (& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> num_const ) && (pos < rcount ) ; i ++ , pos ++ ) {
#     define XfOrM220_COUNT (0+XfOrM218_COUNT)
#     define SETUP_XfOrM220(x) SETUP_XfOrM218(x)
      if ((& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> const_uids )
        (& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> const_uids [i ] = uid ; 
      FUNCCALL(SETUP_XfOrM220(_), scheme_set_rename (rnm , pos , (& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> const_names [i ] ) ); 
    }
    rstart = 0 ; 
  }
  for (i = rstart ; pos < rcount ; i ++ , pos ++ ) {
#   define XfOrM217_COUNT (0+XfOrM214_COUNT)
#   define SETUP_XfOrM217(x) SETUP_XfOrM214(x)
    if (env -> uids )
      env -> uids [i ] = uid ; 
    FUNCCALL(SETUP_XfOrM217(_), scheme_set_rename (rnm , pos , env -> values [i ] ) ); 
  }
  if (((Scheme_Type ) (scheme_lexical_rib_type ) == (Scheme_Type ) (((((long ) (stx ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (stx ) ) -> type ) ) ) )
    FUNCCALL(SETUP_XfOrM214(_), scheme_add_rib_rename (stx , rnm ) ); 
  if (env -> renames ) {
#   define XfOrM215_COUNT (0+XfOrM214_COUNT)
#   define SETUP_XfOrM215(x) SETUP_XfOrM214(x)
    if (((Scheme_Type ) (((((long ) (env -> renames ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (env -> renames ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || ((env -> renames ) == (scheme_null ) ) )
      rnm = FUNCCALL(SETUP_XfOrM215(_), scheme_make_pair (rnm , env -> renames ) ); 
    else rnm = (__funcarg35 = FUNCCALL(SETUP_XfOrM215(_), scheme_make_pair (env -> renames , scheme_null ) ), FUNCCALL_AGAIN(scheme_make_pair (rnm , __funcarg35 ) )) ; 
  }
  env -> renames = rnm ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_add_env_renames (Scheme_Object * stx , Scheme_Comp_Env * env , Scheme_Comp_Env * upto ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(stx, 0), PUSH(env, 1), PUSH(upto, 2)));
# define XfOrM228_COUNT (3)
# define SETUP_XfOrM228(x) SETUP(XfOrM228_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! ((Scheme_Type ) (((((long ) (stx ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (stx ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ! ((Scheme_Type ) (scheme_lexical_rib_type ) == (Scheme_Type ) (((((long ) (stx ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (stx ) ) -> type ) ) ) ) {
#   define XfOrM357_COUNT (0+XfOrM228_COUNT)
#   define SETUP_XfOrM357(x) SETUP_XfOrM228(x)
    FUNCCALL_EMPTY(scheme_signal_error ("internal error: not syntax or rib" ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  while (env != upto ) {
#   define XfOrM293_COUNT (0+XfOrM228_COUNT)
#   define SETUP_XfOrM293(x) SETUP_XfOrM228(x)
    if (! (env -> flags & (32 | 64 | 512 ) ) ) {
      int i , count ; 
#     define XfOrM294_COUNT (0+XfOrM293_COUNT)
#     define SETUP_XfOrM294(x) SETUP_XfOrM293(x)
      count = (& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> num_const ; 
      for (i = env -> num_bindings ; i -- ; ) {
        if (env -> values [i ] )
          count ++ ; 
      }
      if (count ) {
        Scheme_Object * l ; 
        BLOCK_SETUP((PUSH(l, 0+XfOrM294_COUNT)));
#       define XfOrM295_COUNT (1+XfOrM294_COUNT)
#       define SETUP_XfOrM295(x) SETUP(XfOrM295_COUNT)
        l = NULLED_OUT ; 
        if (! env -> renames || (env -> rename_var_count != count ) ) {
          Scheme_Hash_Table * ht ; 
          Scheme_Object * name ; 
          int rcount = 0 , rstart , rstart_sec = 0 , vstart ; 
          BLOCK_SETUP((PUSH(ht, 0+XfOrM295_COUNT), PUSH(name, 1+XfOrM295_COUNT)));
#         define XfOrM299_COUNT (2+XfOrM295_COUNT)
#         define SETUP_XfOrM299(x) SETUP(XfOrM299_COUNT)
          ht = NULLED_OUT ; 
          name = NULLED_OUT ; 
          rstart = env -> rename_rstart ; 
          if (env -> renames ) {
#           define XfOrM354_COUNT (0+XfOrM299_COUNT)
#           define SETUP_XfOrM354(x) SETUP_XfOrM299(x)
            if (((Scheme_Type ) (((((long ) (env -> renames ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (env -> renames ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
              env -> renames = (((Scheme_Simple_Object * ) (env -> renames ) ) -> u . pair_val . cdr ) ; 
            else env -> renames = ((void * ) 0 ) ; 
            if (((Scheme_Type ) (scheme_lexical_rib_type ) == (Scheme_Type ) (((((long ) (stx ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (stx ) ) -> type ) ) ) )
              FUNCCALL(SETUP_XfOrM354(_), scheme_drop_first_rib_rename (stx ) ); 
            vstart = env -> rename_var_count ; 
            rstart_sec = 1 ; 
            rcount = vstart - rstart ; 
          }
          else vstart = 0 ; 
          if (env -> dup_check )
            ht = env -> dup_check ; 
          else if (env -> num_bindings + (& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> num_const > 10 )
            ht = FUNCCALL(SETUP_XfOrM299(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
          else ht = ((void * ) 0 ) ; 
          if (rcount > 16 ) {
#           define XfOrM352_COUNT (0+XfOrM299_COUNT)
#           define SETUP_XfOrM352(x) SETUP_XfOrM299(x)
            FUNCCALL(SETUP_XfOrM352(_), make_env_renames (env , rcount , rstart , rstart_sec , 1 , stx ) ); 
            rcount = 0 ; 
            rstart = vstart ; 
            rstart_sec = 1 ; 
            if (ht ) {
#             define XfOrM353_COUNT (0+XfOrM352_COUNT)
#             define SETUP_XfOrM353(x) SETUP_XfOrM352(x)
              ht = FUNCCALL(SETUP_XfOrM353(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
            }
          }
          if (! rstart_sec ) {
#           define XfOrM332_COUNT (0+XfOrM299_COUNT)
#           define SETUP_XfOrM332(x) SETUP_XfOrM299(x)
            if ((& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> num_const ) {
#             define XfOrM333_COUNT (0+XfOrM332_COUNT)
#             define SETUP_XfOrM333(x) SETUP_XfOrM332(x)
              for (i = 0 ; i < (& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> num_const ; i ++ ) {
                int found = 0 ; 
#               define XfOrM343_COUNT (0+XfOrM333_COUNT)
#               define SETUP_XfOrM343(x) SETUP_XfOrM333(x)
                name = ((Scheme_Stx * ) (& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> const_names [i ] ) -> val ; 
                if (ht ) {
#                 define XfOrM351_COUNT (0+XfOrM343_COUNT)
#                 define SETUP_XfOrM351(x) SETUP_XfOrM343(x)
                  if (FUNCCALL(SETUP_XfOrM351(_), scheme_hash_get (ht , name ) ))
                    found = 1 ; 
                  else FUNCCALL(SETUP_XfOrM351(_), scheme_hash_set (ht , name , scheme_true ) ); 
                }
                else {
                  int j ; 
                  for (j = rstart ; j < i ; j ++ ) {
                    if (((name ) == (((Scheme_Stx * ) (& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> const_names [j ] ) -> val ) ) ) {
                      found = 1 ; 
                      break ; 
                    }
                  }
                }
                if (found ) {
#                 define XfOrM344_COUNT (0+XfOrM343_COUNT)
#                 define SETUP_XfOrM344(x) SETUP_XfOrM343(x)
                  FUNCCALL(SETUP_XfOrM344(_), make_env_renames (env , rcount , rstart , rstart_sec , 1 , stx ) ); 
                  rcount = 1 ; 
                  rstart = i ; 
                  if (ht ) {
#                   define XfOrM345_COUNT (0+XfOrM344_COUNT)
#                   define SETUP_XfOrM345(x) SETUP_XfOrM344(x)
                    ht = FUNCCALL(SETUP_XfOrM345(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
                    FUNCCALL(SETUP_XfOrM345(_), scheme_hash_set (ht , name , scheme_true ) ); 
                  }
                }
                else rcount ++ ; 
              }
            }
            else rstart_sec = 1 ; 
          }
          for (i = vstart ; (i < env -> num_bindings ) && env -> values [i ] ; i ++ ) {
            int found = 0 ; 
#           define XfOrM317_COUNT (0+XfOrM299_COUNT)
#           define SETUP_XfOrM317(x) SETUP_XfOrM299(x)
            name = ((Scheme_Stx * ) env -> values [i ] ) -> val ; 
            if (ht ) {
#             define XfOrM331_COUNT (0+XfOrM317_COUNT)
#             define SETUP_XfOrM331(x) SETUP_XfOrM317(x)
              if (FUNCCALL(SETUP_XfOrM331(_), scheme_hash_get (ht , name ) ))
                found = 1 ; 
              else FUNCCALL(SETUP_XfOrM331(_), scheme_hash_set (ht , name , scheme_true ) ); 
            }
            else {
              int j ; 
              if (! rstart_sec ) {
                for (j = rstart ; j < (& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> num_const ; j ++ ) {
                  if (((name ) == (((Scheme_Stx * ) (& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> const_names [j ] ) -> val ) ) ) {
                    found = 1 ; 
                    break ; 
                  }
                }
                j = 0 ; 
              }
              else j = rstart ; 
              if (! found ) {
                for (; j < i ; j ++ ) {
                  if (((name ) == (((Scheme_Stx * ) env -> values [j ] ) -> val ) ) ) {
                    found = 1 ; 
                    break ; 
                  }
                }
              }
            }
            if (found ) {
#             define XfOrM318_COUNT (0+XfOrM317_COUNT)
#             define SETUP_XfOrM318(x) SETUP_XfOrM317(x)
              FUNCCALL(SETUP_XfOrM318(_), make_env_renames (env , rcount , rstart , rstart_sec , 1 , stx ) ); 
              rcount = 1 ; 
              rstart = i ; 
              rstart_sec = 1 ; 
              if (ht ) {
#               define XfOrM319_COUNT (0+XfOrM318_COUNT)
#               define SETUP_XfOrM319(x) SETUP_XfOrM318(x)
                ht = FUNCCALL(SETUP_XfOrM319(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
                FUNCCALL(SETUP_XfOrM319(_), scheme_hash_set (ht , name , scheme_true ) ); 
              }
            }
            else rcount ++ ; 
          }
          FUNCCALL(SETUP_XfOrM299(_), make_env_renames (env , rcount , rstart , rstart_sec , 0 , stx ) ); 
          env -> rename_var_count = count ; 
          env -> rename_rstart = rstart ; 
          if (count < env -> num_bindings ) {
            env -> dup_check = ht ; 
          }
          else {
            env -> dup_check = ((void * ) 0 ) ; 
          }
        }
        if (((Scheme_Type ) (((((long ) (stx ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (stx ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ) {
#         define XfOrM296_COUNT (0+XfOrM295_COUNT)
#         define SETUP_XfOrM296(x) SETUP_XfOrM295(x)
          for (l = env -> renames ; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#           define XfOrM298_COUNT (0+XfOrM296_COUNT)
#           define SETUP_XfOrM298(x) SETUP_XfOrM296(x)
            stx = FUNCCALL(SETUP_XfOrM298(_), scheme_add_rename (stx , (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ) ); 
          }
          if (! ((l ) == (scheme_null ) ) )
            stx = FUNCCALL(SETUP_XfOrM296(_), scheme_add_rename (stx , l ) ); 
        }
      }
    }
    env = env -> next ; 
  }
  RET_VALUE_START (stx ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_seal_env_renames (Scheme_Comp_Env * env ) {
  /* No conversion */
  env -> dup_check = ((void * ) 0 ) ; 
}
void create_skip_table (Scheme_Comp_Env * start_frame ) {
  Scheme_Comp_Env * end_frame , * frame ; 
  int depth , dj = 0 , dp = 0 , i ; 
  Scheme_Hash_Table * table ; 
  int stride = 0 ; 
  PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(end_frame, 0), PUSH(frame, 1), PUSH(start_frame, 2), PUSH(table, 3)));
# define XfOrM359_COUNT (4)
# define SETUP_XfOrM359(x) SETUP(XfOrM359_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  end_frame = NULLED_OUT ; 
  frame = NULLED_OUT ; 
  table = NULLED_OUT ; 
  depth = start_frame -> skip_depth ; 
  for (end_frame = start_frame -> next ; end_frame && ((depth & end_frame -> skip_depth ) != end_frame -> skip_depth ) ; end_frame = end_frame -> next ) {
    stride ++ ; 
  }
  table = FUNCCALL(SETUP_XfOrM359(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  for (frame = start_frame ; frame != end_frame ; frame = frame -> next ) {
#   define XfOrM367_COUNT (0+XfOrM359_COUNT)
#   define SETUP_XfOrM367(x) SETUP_XfOrM359(x)
    if (frame -> flags & 8 )
      dj ++ ; 
    dp += frame -> num_bindings ; 
    for (i = frame -> num_bindings ; i -- ; ) {
#     define XfOrM372_COUNT (0+XfOrM367_COUNT)
#     define SETUP_XfOrM372(x) SETUP_XfOrM367(x)
      if (frame -> values [i ] ) {
#       define XfOrM373_COUNT (0+XfOrM372_COUNT)
#       define SETUP_XfOrM373(x) SETUP_XfOrM372(x)
        FUNCCALL(SETUP_XfOrM373(_), scheme_hash_set (table , ((Scheme_Stx * ) frame -> values [i ] ) -> val , scheme_true ) ); 
      }
    }
    for (i = (& ((Scheme_Full_Comp_Env * ) frame ) -> data ) -> num_const ; i -- ; ) {
#     define XfOrM369_COUNT (0+XfOrM367_COUNT)
#     define SETUP_XfOrM369(x) SETUP_XfOrM367(x)
      FUNCCALL(SETUP_XfOrM369(_), scheme_hash_set (table , ((Scheme_Stx * ) (& ((Scheme_Full_Comp_Env * ) frame ) -> data ) -> const_names [i ] ) -> val , scheme_true ) ); 
    }
  }
  FUNCCALL(SETUP_XfOrM359(_), scheme_hash_set (table , ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) , (Scheme_Object * ) end_frame ) ); 
  FUNCCALL(SETUP_XfOrM359(_), scheme_hash_set (table , ((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) , ((Scheme_Object * ) (void * ) (long ) ((((long ) (dj ) ) << 1 ) | 0x1 ) ) ) ); 
  FUNCCALL_AGAIN(scheme_hash_set (table , ((Scheme_Object * ) (void * ) (long ) ((((long ) (2 ) ) << 1 ) | 0x1 ) ) , ((Scheme_Object * ) (void * ) (long ) ((((long ) (dp ) ) << 1 ) | 0x1 ) ) ) ); 
  start_frame -> skip_table = table ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_lookup_binding (Scheme_Object * find_id , Scheme_Comp_Env * env , int flags , Scheme_Object * certs , Scheme_Object * in_modidx , Scheme_Env * * _menv , int * _protected , Scheme_Object * * _lexical_binding_id ) {
  Scheme_Comp_Env * frame ; 
  int j = 0 , p = 0 , modpos , skip_stops = 0 , mod_defn_phase , module_self_reference = 0 ; 
  Scheme_Bucket * b ; 
  Scheme_Object * val , * modidx , * modname , * src_find_id , * find_global_id ; 
  Scheme_Env * genv ; 
  long phase ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(16);
  BLOCK_SETUP_TOP((PUSH(val, 0), PUSH(_protected, 1), PUSH(find_global_id, 2), PUSH(_lexical_binding_id, 3), PUSH(b, 4), PUSH(certs, 5), PUSH(find_id, 6), PUSH(modidx, 7), PUSH(_menv, 8), PUSH(frame, 9), PUSH(in_modidx, 10), PUSH(modname, 11), PUSH(env, 12), PUSH(genv, 13), PUSH(src_find_id, 14)));
# define XfOrM376_COUNT (15)
# define SETUP_XfOrM376(x) SETUP(XfOrM376_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  frame = NULLED_OUT ; 
  b = NULLED_OUT ; 
  val = NULLED_OUT ; 
  modidx = NULLED_OUT ; 
  modname = NULLED_OUT ; 
  src_find_id = NULLED_OUT ; 
  find_global_id = NULLED_OUT ; 
  genv = NULLED_OUT ; 
  phase = env -> genv -> phase ; 
  for (frame = env ; frame -> next != ((void * ) 0 ) ; frame = frame -> next ) {
    int i ; 
    Scheme_Object * uid ; 
    BLOCK_SETUP((PUSH(uid, 0+XfOrM376_COUNT)));
#   define XfOrM437_COUNT (1+XfOrM376_COUNT)
#   define SETUP_XfOrM437(x) SETUP(XfOrM437_COUNT)
    uid = NULLED_OUT ; 
    while (1 ) {
#     define XfOrM471_COUNT (0+XfOrM437_COUNT)
#     define SETUP_XfOrM471(x) SETUP_XfOrM437(x)
      if (frame -> skip_table ) {
#       define XfOrM473_COUNT (0+XfOrM471_COUNT)
#       define SETUP_XfOrM473(x) SETUP_XfOrM471(x)
        if (! FUNCCALL(SETUP_XfOrM473(_), scheme_hash_get (frame -> skip_table , ((Scheme_Stx * ) find_id ) -> val ) )) {
#         define XfOrM474_COUNT (0+XfOrM473_COUNT)
#         define SETUP_XfOrM474(x) SETUP_XfOrM473(x)
          val = FUNCCALL(SETUP_XfOrM474(_), scheme_hash_get (frame -> skip_table , ((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) ) ); 
          j += (((long ) (val ) ) >> 1 ) ; 
          val = FUNCCALL(SETUP_XfOrM474(_), scheme_hash_get (frame -> skip_table , ((Scheme_Object * ) (void * ) (long ) ((((long ) (2 ) ) << 1 ) | 0x1 ) ) ) ); 
          p += (((long ) (val ) ) >> 1 ) ; 
          frame = (Scheme_Comp_Env * ) FUNCCALL(SETUP_XfOrM474(_), scheme_hash_get (frame -> skip_table , ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) ); 
        }
        else break ; 
      }
      else if (frame -> skip_depth && ! (frame -> skip_depth & 0x1F ) ) {
#       define XfOrM472_COUNT (0+XfOrM471_COUNT)
#       define SETUP_XfOrM472(x) SETUP_XfOrM471(x)
        FUNCCALL(SETUP_XfOrM472(_), create_skip_table (frame ) ); 
      }
      else break ; 
    }
    if (frame -> flags & 8 )
      j ++ ; 
    if (! skip_stops || ! (frame -> flags & 128 ) ) {
#     define XfOrM438_COUNT (0+XfOrM437_COUNT)
#     define SETUP_XfOrM438(x) SETUP_XfOrM437(x)
      if (frame -> flags & 128 )
        skip_stops = 1 ; 
      uid = FUNCCALL(SETUP_XfOrM438(_), scheme_env_frame_uid (frame ) ); 
      for (i = frame -> num_bindings ; i -- ; ) {
#       define XfOrM461_COUNT (0+XfOrM438_COUNT)
#       define SETUP_XfOrM461(x) SETUP_XfOrM438(x)
        if (frame -> values [i ] ) {
#         define XfOrM462_COUNT (0+XfOrM461_COUNT)
#         define SETUP_XfOrM462(x) SETUP_XfOrM461(x)
          if (frame -> uids )
            uid = frame -> uids [i ] ; 
          if (((((Scheme_Stx * ) find_id ) -> val ) == (((Scheme_Stx * ) frame -> values [i ] ) -> val ) ) && (FUNCCALL(SETUP_XfOrM462(_), scheme_stx_env_bound_eq (find_id , frame -> values [i ] , uid , phase ) )|| ((frame -> flags & 64 ) && FUNCCALL(SETUP_XfOrM462(_), scheme_stx_module_eq (find_id , frame -> values [i ] , phase ) )) || ((frame -> flags & 512 ) && FUNCCALL(SETUP_XfOrM462(_), scheme_stx_bound_eq (find_id , frame -> values [i ] , phase ) )) ) ) {
#           define XfOrM463_COUNT (0+XfOrM462_COUNT)
#           define SETUP_XfOrM463(x) SETUP_XfOrM462(x)
            if (! (flags & 2048 ) && ! (frame -> flags & (64 | 512 ) ) ) {
#             define XfOrM465_COUNT (0+XfOrM463_COUNT)
#             define SETUP_XfOrM465(x) SETUP_XfOrM463(x)
              if (FUNCCALL(SETUP_XfOrM465(_), scheme_stx_has_more_certs (find_id , certs , frame -> values [i ] , frame -> certs ) )) {
#               define XfOrM466_COUNT (0+XfOrM465_COUNT)
#               define SETUP_XfOrM466(x) SETUP_XfOrM465(x)
                FUNCCALL(SETUP_XfOrM466(_), scheme_wrong_syntax (scheme_compile_stx_string , ((void * ) 0 ) , find_id , "reference is more certified than binding" ) ); 
                RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
              }
            }
            if (_lexical_binding_id ) {
#             define XfOrM464_COUNT (0+XfOrM463_COUNT)
#             define SETUP_XfOrM464(x) SETUP_XfOrM463(x)
              if (! (frame -> flags & 64 ) )
                val = FUNCCALL(SETUP_XfOrM464(_), scheme_stx_remove_extra_marks (find_id , frame -> values [i ] , ((frame -> flags & 512 ) ? ((void * ) 0 ) : uid ) ) ); 
              else val = find_id ; 
              * _lexical_binding_id = val ; 
            }
            if (flags & 128 )
              RET_VALUE_START (FUNCCALL(SETUP_XfOrM463(_), scheme_make_local (scheme_local_type , 0 ) )) RET_VALUE_END ; 
            else RET_VALUE_START ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM463(_), get_frame_loc (frame , i , j , p , flags ) )) RET_VALUE_END ; 
          }
        }
      }
      for (i = (& ((Scheme_Full_Comp_Env * ) frame ) -> data ) -> num_const ; i -- ; ) {
        int issame ; 
#       define XfOrM447_COUNT (0+XfOrM438_COUNT)
#       define SETUP_XfOrM447(x) SETUP_XfOrM438(x)
        if (frame -> flags & 64 )
          issame = FUNCCALL(SETUP_XfOrM447(_), scheme_stx_module_eq (find_id , (& ((Scheme_Full_Comp_Env * ) frame ) -> data ) -> const_names [i ] , phase ) ); 
        else {
#         define XfOrM454_COUNT (0+XfOrM447_COUNT)
#         define SETUP_XfOrM454(x) SETUP_XfOrM447(x)
          if ((& ((Scheme_Full_Comp_Env * ) frame ) -> data ) -> const_uids )
            uid = (& ((Scheme_Full_Comp_Env * ) frame ) -> data ) -> const_uids [i ] ; 
          issame = (((((Scheme_Stx * ) find_id ) -> val ) == (((Scheme_Stx * ) (& ((Scheme_Full_Comp_Env * ) frame ) -> data ) -> const_names [i ] ) -> val ) ) && FUNCCALL(SETUP_XfOrM454(_), scheme_stx_env_bound_eq (find_id , (& ((Scheme_Full_Comp_Env * ) frame ) -> data ) -> const_names [i ] , uid , phase ) )) ; 
        }
        if (issame ) {
#         define XfOrM448_COUNT (0+XfOrM447_COUNT)
#         define SETUP_XfOrM448(x) SETUP_XfOrM447(x)
          if (! (flags & 2048 ) && ! (frame -> flags & 64 ) ) {
#           define XfOrM452_COUNT (0+XfOrM448_COUNT)
#           define SETUP_XfOrM452(x) SETUP_XfOrM448(x)
            if (FUNCCALL(SETUP_XfOrM452(_), scheme_stx_has_more_certs (find_id , certs , (& ((Scheme_Full_Comp_Env * ) frame ) -> data ) -> const_names [i ] , frame -> certs ) )) {
#             define XfOrM453_COUNT (0+XfOrM452_COUNT)
#             define SETUP_XfOrM453(x) SETUP_XfOrM452(x)
              FUNCCALL(SETUP_XfOrM453(_), scheme_wrong_syntax (scheme_compile_stx_string , ((void * ) 0 ) , find_id , "reference is more certified than binding" ) ); 
              RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
            }
          }
          val = (& ((Scheme_Full_Comp_Env * ) frame ) -> data ) -> const_vals [i ] ; 
          if (! val ) {
#           define XfOrM451_COUNT (0+XfOrM448_COUNT)
#           define SETUP_XfOrM451(x) SETUP_XfOrM448(x)
            FUNCCALL(SETUP_XfOrM451(_), scheme_wrong_syntax (scheme_compile_stx_string , ((void * ) 0 ) , find_id , "variable used out of context" ) ); 
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          }
          if ((((val ) ) == (scheme_false ) ) ) {
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          }
          if (! (flags & 8 ) ) {
#           define XfOrM449_COUNT (0+XfOrM448_COUNT)
#           define SETUP_XfOrM449(x) SETUP_XfOrM448(x)
            if (((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_macro_type ) ) )
              RET_VALUE_START (val ) RET_VALUE_END ; 
            else if (((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_lazy_macro_type ) ) )
              RET_VALUE_START (FUNCCALL(SETUP_XfOrM449(_), force_lazy_macro (val , phase ) )) RET_VALUE_END ; 
            else FUNCCALL(SETUP_XfOrM449(_), scheme_wrong_syntax (scheme_set_stx_string , ((void * ) 0 ) , find_id , "local syntax identifier cannot be mutated" ) ); 
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          }
          RET_VALUE_START (val ) RET_VALUE_END ; 
        }
      }
    }
    p += frame -> num_bindings ; 
  }
  src_find_id = find_id ; 
  modidx = FUNCCALL(SETUP_XfOrM376(_), scheme_stx_module_name (& find_id , phase , ((void * ) 0 ) , ((void * ) 0 ) , & mod_defn_phase ) ); 
  if (((modidx ) == (scheme_undefined ) ) ) {
#   define XfOrM398_COUNT (0+XfOrM376_COUNT)
#   define SETUP_XfOrM398(x) SETUP_XfOrM376(x)
    if (! (flags & 256 ) )
      FUNCCALL(SETUP_XfOrM398(_), scheme_wrong_syntax (scheme_compile_stx_string , ((void * ) 0 ) , find_id , "identifier used out of context" ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (modidx ) {
#   define XfOrM392_COUNT (0+XfOrM376_COUNT)
#   define SETUP_XfOrM392(x) SETUP_XfOrM376(x)
    modname = FUNCCALL(SETUP_XfOrM392(_), scheme_module_resolve (modidx , 1 ) ); 
    if (env -> genv -> module && ((modname ) == (env -> genv -> module -> modname ) ) ) {
      modidx = ((void * ) 0 ) ; 
      modname = ((void * ) 0 ) ; 
      genv = env -> genv ; 
      module_self_reference = 1 ; 
    }
    else {
#     define XfOrM393_COUNT (0+XfOrM392_COUNT)
#     define SETUP_XfOrM393(x) SETUP_XfOrM392(x)
      genv = FUNCCALL(SETUP_XfOrM393(_), scheme_module_access (modname , env -> genv , mod_defn_phase ) ); 
      if (! genv ) {
#       define XfOrM394_COUNT (0+XfOrM393_COUNT)
#       define SETUP_XfOrM394(x) SETUP_XfOrM393(x)
        if (env -> genv -> phase ) {
#         define XfOrM396_COUNT (0+XfOrM394_COUNT)
#         define SETUP_XfOrM396(x) SETUP_XfOrM394(x)
          FUNCCALL(SETUP_XfOrM396(_), scheme_module_force_lazy (env -> genv , 1 ) ); 
          genv = FUNCCALL(SETUP_XfOrM396(_), scheme_module_access (modname , env -> genv , mod_defn_phase ) ); 
        }
        if (! genv ) {
#         define XfOrM395_COUNT (0+XfOrM394_COUNT)
#         define SETUP_XfOrM395(x) SETUP_XfOrM394(x)
          FUNCCALL(SETUP_XfOrM395(_), scheme_wrong_syntax ("require" , ((void * ) 0 ) , src_find_id , "broken compiled code (phase %d, defn-phase %d): cannot find module %S" , env -> genv -> phase , mod_defn_phase , modname ) ); 
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        }
      }
    }
  }
  else {
#   define XfOrM389_COUNT (0+XfOrM376_COUNT)
#   define SETUP_XfOrM389(x) SETUP_XfOrM376(x)
    genv = env -> genv ; 
    modname = ((void * ) 0 ) ; 
    if (genv -> module && ! genv -> rename ) {
#     define XfOrM390_COUNT (0+XfOrM389_COUNT)
#     define SETUP_XfOrM390(x) SETUP_XfOrM389(x)
      if (flags & (4 | 4096 ) ) {
#       define XfOrM391_COUNT (0+XfOrM390_COUNT)
#       define SETUP_XfOrM391(x) SETUP_XfOrM390(x)
        FUNCCALL(SETUP_XfOrM391(_), scheme_wrong_syntax (((flags & 4 ) ? scheme_set_stx_string : scheme_var_ref_string ) , ((void * ) 0 ) , src_find_id , "unbound variable in module" ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      if (flags & 512 )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  if (_menv && genv -> module )
    * _menv = genv ; 
  if (! modname && ((Scheme_Type ) (((((long ) (find_id ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (find_id ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    find_global_id = FUNCCALL(SETUP_XfOrM376(_), scheme_tl_id_sym (env -> genv , find_id , ((void * ) 0 ) , 0 ) ); 
  else find_global_id = find_id ; 
  if (modname ) {
#   define XfOrM388_COUNT (0+XfOrM376_COUNT)
#   define SETUP_XfOrM388(x) SETUP_XfOrM376(x)
    val = FUNCCALL(SETUP_XfOrM388(_), scheme_module_syntax (modname , env -> genv , find_id ) ); 
    if (val && ! (flags & 2048 ) )
      FUNCCALL(SETUP_XfOrM388(_), scheme_check_accessible_in_module (genv , env -> insp , in_modidx , find_id , src_find_id , certs , ((void * ) 0 ) , - 2 , 0 , ((void * ) 0 ) ) ); 
  }
  else {
#   define XfOrM387_COUNT (0+XfOrM376_COUNT)
#   define SETUP_XfOrM387(x) SETUP_XfOrM376(x)
    if (genv -> shadowed_syntax && FUNCCALL(SETUP_XfOrM387(_), scheme_hash_get (genv -> shadowed_syntax , find_global_id ) ))
      val = ((void * ) 0 ) ; 
    else val = FUNCCALL(SETUP_XfOrM387(_), scheme_lookup_in_table (genv -> syntax , (const char * ) find_global_id ) ); 
  }
  if (val ) {
#   define XfOrM386_COUNT (0+XfOrM376_COUNT)
#   define SETUP_XfOrM386(x) SETUP_XfOrM376(x)
    if (((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_lazy_macro_type ) ) )
      RET_VALUE_START (FUNCCALL(SETUP_XfOrM386(_), force_lazy_macro (val , phase ) )) RET_VALUE_END ; 
    RET_VALUE_START (val ) RET_VALUE_END ; 
  }
  if (modname ) {
    Scheme_Object * pos ; 
    BLOCK_SETUP((PUSH(pos, 0+XfOrM376_COUNT)));
#   define XfOrM385_COUNT (1+XfOrM376_COUNT)
#   define SETUP_XfOrM385(x) SETUP(XfOrM385_COUNT)
    pos = NULLED_OUT ; 
    if (flags & 2048 )
      pos = 0 ; 
    else pos = FUNCCALL(SETUP_XfOrM385(_), scheme_check_accessible_in_module (genv , env -> insp , in_modidx , find_id , src_find_id , certs , ((void * ) 0 ) , - 1 , 1 , _protected ) ); 
    modpos = (((long ) (pos ) ) >> 1 ) ; 
  }
  else modpos = - 1 ; 
  if (modname && (flags & 4 ) ) {
#   define XfOrM384_COUNT (0+XfOrM376_COUNT)
#   define SETUP_XfOrM384(x) SETUP_XfOrM376(x)
    if (((src_find_id ) == (find_id ) ) || (((((Scheme_Type ) (((((long ) (src_find_id ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (src_find_id ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ? ((Scheme_Stx * ) src_find_id ) -> val : src_find_id ) ) == (find_id ) ) )
      find_id = ((void * ) 0 ) ; 
    FUNCCALL(SETUP_XfOrM384(_), scheme_wrong_syntax (scheme_set_stx_string , find_id , src_find_id , "cannot mutate module-required variable" ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (! modname && (flags & (4 | 4096 ) ) && (genv -> module && ! genv -> rename ) ) {
#   define XfOrM382_COUNT (0+XfOrM376_COUNT)
#   define SETUP_XfOrM382(x) SETUP_XfOrM376(x)
    if (! FUNCCALL(SETUP_XfOrM382(_), scheme_lookup_in_table (genv -> toplevel , (const char * ) find_global_id ) )) {
#     define XfOrM383_COUNT (0+XfOrM382_COUNT)
#     define SETUP_XfOrM383(x) SETUP_XfOrM382(x)
      FUNCCALL(SETUP_XfOrM383(_), scheme_wrong_syntax (((flags & 4 ) ? scheme_set_stx_string : scheme_var_ref_string ) , ((void * ) 0 ) , src_find_id , "unbound variable in module" ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  if (! modname && (flags & 512 ) ) {
#   define XfOrM379_COUNT (0+XfOrM376_COUNT)
#   define SETUP_XfOrM379(x) SETUP_XfOrM376(x)
    if (module_self_reference ) {
#     define XfOrM380_COUNT (0+XfOrM379_COUNT)
#     define SETUP_XfOrM380(x) SETUP_XfOrM379(x)
      if (! (flags & 1024 ) ) {
#       define XfOrM381_COUNT (0+XfOrM380_COUNT)
#       define SETUP_XfOrM381(x) SETUP_XfOrM380(x)
        RET_VALUE_START (FUNCCALL(SETUP_XfOrM381(_), scheme_hash_module_variable (genv , genv -> module -> self_modidx , find_id , genv -> module -> insp , - 1 , genv -> mod_phase ) )) RET_VALUE_END ; 
      }
    }
    else RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (modname && ! (flags & 1024 ) && (! ((modidx ) == (kernel_symbol ) ) || (flags & 4096 ) ) ) {
#   define XfOrM378_COUNT (0+XfOrM376_COUNT)
#   define SETUP_XfOrM378(x) SETUP_XfOrM376(x)
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM378(_), scheme_hash_module_variable (env -> genv , modidx , find_id , genv -> module -> insp , modpos , mod_defn_phase ) )) RET_VALUE_END ; 
  }
  if (! modname && (flags & (4 | 4096 ) ) && genv -> module ) {
#   define XfOrM377_COUNT (0+XfOrM376_COUNT)
#   define SETUP_XfOrM377(x) SETUP_XfOrM376(x)
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM377(_), scheme_hash_module_variable (env -> genv , genv -> module -> self_modidx , find_global_id , genv -> module -> insp , modpos , genv -> mod_phase ) )) RET_VALUE_END ; 
  }
  b = FUNCCALL(SETUP_XfOrM376(_), scheme_bucket_from_table (genv -> toplevel , (char * ) find_global_id ) ); 
  if ((flags & 1 ) && b && b -> val && (((Scheme_Bucket_With_Flags * ) b ) -> flags & 1 ) && ! (flags & 16 ) )
    RET_VALUE_START ((Scheme_Object * ) b -> val ) RET_VALUE_END ; 
  ; 
  if (! ((Scheme_Bucket_With_Home * ) b ) -> home )
    ((Scheme_Bucket_With_Home * ) b ) -> home = genv ; 
  RET_VALUE_START ((Scheme_Object * ) b ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 2547 */
int * scheme_env_get_flags (Scheme_Comp_Env * frame , int start , int count ) {
  int * v , i ; 
  DECL_RET_SAVE (int * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(frame, 1)));
# define XfOrM475_COUNT (2)
# define SETUP_XfOrM475(x) SETUP(XfOrM475_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  v = ((int * ) FUNCCALL(SETUP_XfOrM475(_), GC_malloc_atomic (sizeof (int ) * (count ) ) )) ; 
  (memcpy (v , (& ((Scheme_Full_Comp_Env * ) frame ) -> data ) -> use + start , sizeof (int ) * count ) ) ; 
  for (i = count ; i -- ; ) {
    int old ; 
    old = v [i ] ; 
    v [i ] = 0 ; 
    if (old & (0x1 | 0x8 | 0x2 ) ) {
      v [i ] |= 0x1 ; 
      if (! (old & (0x1 | 0x4 ) ) ) {
        if (old & 0x8 )
          v [i ] |= 0x8 ; 
        else v [i ] |= 0x4 ; 
      }
    }
    if (old & 0x4 )
      v [i ] |= 0x2 ; 
    v [i ] |= (old & 0x70 ) ; 
  }
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_check_identifier (const char * formname , Scheme_Object * id , const char * where , Scheme_Comp_Env * env , Scheme_Object * form ) {
  /* No conversion */
  if (! where )
    where = "" ; 
  if (! (((Scheme_Type ) (((((long ) (id ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (id ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (id ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (id ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) id ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) id ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) )
    scheme_wrong_syntax (formname , form ? id : ((void * ) 0 ) , form ? form : id , "not an identifier%s" , where ) ; 
}
void scheme_begin_dup_symbol_check (DupCheckRecord * r , Scheme_Comp_Env * env ) {
  /* No conversion */
  r -> phase = env -> genv -> phase ; 
  r -> count = 0 ; 
}
void scheme_dup_symbol_check (DupCheckRecord * r , const char * where , Scheme_Object * symbol , char * what , Scheme_Object * form ) {
  int i ; 
  PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(symbol, 0), PUSH(where, 1), PUSH(what, 2), PUSH(r, 3), PUSH(form, 4)));
# define XfOrM484_COUNT (5)
# define SETUP_XfOrM484(x) SETUP(XfOrM484_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (r -> count <= 5 ) {
#   define XfOrM486_COUNT (0+XfOrM484_COUNT)
#   define SETUP_XfOrM486(x) SETUP_XfOrM484(x)
    for (i = 0 ; i < r -> count ; i ++ ) {
#     define XfOrM492_COUNT (0+XfOrM486_COUNT)
#     define SETUP_XfOrM492(x) SETUP_XfOrM486(x)
      if (FUNCCALL(SETUP_XfOrM492(_), scheme_stx_bound_eq (symbol , r -> syms [i ] , r -> phase ) ))
        FUNCCALL_EMPTY(scheme_wrong_syntax (where , symbol , form , "duplicate %s name" , what ) ); 
    }
    if (r -> count < 5 ) {
      r -> syms [r -> count ++ ] = symbol ; 
      RET_NOTHING ; 
    }
    else {
      Scheme_Hash_Table * ht ; 
      BLOCK_SETUP((PUSH(ht, 0+XfOrM486_COUNT)));
#     define XfOrM487_COUNT (1+XfOrM486_COUNT)
#     define SETUP_XfOrM487(x) SETUP(XfOrM487_COUNT)
      ht = NULLED_OUT ; 
      ht = FUNCCALL(SETUP_XfOrM487(_), scheme_make_hash_table (SCHEME_hash_bound_id ) ); 
      r -> ht = ht ; 
      for (i = 0 ; i < r -> count ; i ++ ) {
#       define XfOrM489_COUNT (0+XfOrM487_COUNT)
#       define SETUP_XfOrM489(x) SETUP_XfOrM487(x)
        FUNCCALL(SETUP_XfOrM489(_), scheme_hash_set (ht , r -> syms [i ] , scheme_true ) ); 
      }
      r -> count ++ ; 
    }
  }
  if (FUNCCALL(SETUP_XfOrM484(_), scheme_hash_get (r -> ht , symbol ) )) {
#   define XfOrM485_COUNT (0+XfOrM484_COUNT)
#   define SETUP_XfOrM485(x) SETUP_XfOrM484(x)
    FUNCCALL_EMPTY(scheme_wrong_syntax (where , symbol , form , "duplicate %s name" , what ) ); 
  }
  FUNCCALL_EMPTY(scheme_hash_set (r -> ht , symbol , scheme_true ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_check_context (Scheme_Env * env , Scheme_Object * name , Scheme_Object * ok_modidx ) {
  Scheme_Object * mod , * id = name ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(id, 0), PUSH(env, 1), PUSH(ok_modidx, 2), PUSH(mod, 3)));
# define XfOrM493_COUNT (4)
# define SETUP_XfOrM493(x) SETUP(XfOrM493_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  mod = NULLED_OUT ; 
  mod = FUNCCALL(SETUP_XfOrM493(_), scheme_stx_source_module (id , 0 ) ); 
  if (mod && (! (((mod ) ) == (scheme_false ) ) ) && ((ok_modidx ) != (mod ) ) ) {
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM494_COUNT (0+XfOrM493_COUNT)
#   define SETUP_XfOrM494(x) SETUP_XfOrM493(x)
    mod = FUNCCALL(SETUP_XfOrM494(_), scheme_stx_module_name (& id , env -> phase , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
    if (((mod ) == (scheme_undefined ) ) )
      RET_VALUE_START (1 ) RET_VALUE_END ; 
  }
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Optimize_Info * scheme_optimize_info_create () {
  Optimize_Info * info ; 
  DECL_RET_SAVE (Optimize_Info * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(info, 0)));
# define XfOrM496_COUNT (1)
# define SETUP_XfOrM496(x) SETUP(XfOrM496_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  info = NULLED_OUT ; 
  info = ((Optimize_Info * ) FUNCCALL(SETUP_XfOrM496(_), GC_malloc_one_small_tagged ((((sizeof (Optimize_Info ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  info -> type = scheme_rt_optimize_info ; 
  info -> inline_fuel = 16 ; 
  RET_VALUE_START (info ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void register_transitive_use (Optimize_Info * info , int pos , int j ) ; 
static void register_stat_dist (Optimize_Info * info , int i , int j ) {
  PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(info, 0)));
# define XfOrM497_COUNT (1)
# define SETUP_XfOrM497(x) SETUP(XfOrM497_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! info -> stat_dists ) {
    int k , * ia ; 
    char * * ca ; 
    BLOCK_SETUP((PUSH(ca, 0+XfOrM497_COUNT), PUSH(ia, 1+XfOrM497_COUNT)));
#   define XfOrM507_COUNT (2+XfOrM497_COUNT)
#   define SETUP_XfOrM507(x) SETUP(XfOrM507_COUNT)
    ia = NULLED_OUT ; 
    ca = NULLED_OUT ; 
    ca = ((char * * ) FUNCCALL(SETUP_XfOrM507(_), GC_malloc (sizeof (char * ) * (info -> new_frame ) ) )) ; 
    info -> stat_dists = ca ; 
    ia = ((int * ) FUNCCALL(SETUP_XfOrM507(_), GC_malloc_atomic (sizeof (int ) * (info -> new_frame ) ) )) ; 
    info -> sd_depths = ia ; 
    for (k = info -> new_frame ; k -- ; ) {
      info -> sd_depths [k ] = 0 ; 
    }
  }
  if (info -> sd_depths [i ] <= j ) {
    char * naya , * a ; 
    int k ; 
    BLOCK_SETUP((PUSH(a, 0+XfOrM497_COUNT), PUSH(naya, 1+XfOrM497_COUNT)));
#   define XfOrM502_COUNT (2+XfOrM497_COUNT)
#   define SETUP_XfOrM502(x) SETUP(XfOrM502_COUNT)
    naya = NULLED_OUT ; 
    a = NULLED_OUT ; 
    naya = ((char * ) FUNCCALL(SETUP_XfOrM502(_), GC_malloc_atomic (sizeof (char ) * ((j + 1 ) ) ) )) ; 
    for (k = j + 1 ; k -- ; ) {
      naya [k ] = 0 ; 
    }
    a = info -> stat_dists [i ] ; 
    for (k = info -> sd_depths [i ] ; k -- ; ) {
      naya [k ] = a [k ] ; 
    }
    info -> stat_dists [i ] = naya ; 
    info -> sd_depths [i ] = j + 1 ; 
  }
  if (info -> transitive_use && info -> transitive_use [i ] ) {
#   define XfOrM498_COUNT (0+XfOrM497_COUNT)
#   define SETUP_XfOrM498(x) SETUP_XfOrM497(x)
    if (! info -> transitive_use_pos ) {
      mzshort * map = info -> transitive_use [i ] ; 
      int len = info -> transitive_use_len [i ] ; 
      int k ; 
      BLOCK_SETUP((PUSH(map, 0+XfOrM498_COUNT)));
#     define XfOrM499_COUNT (1+XfOrM498_COUNT)
#     define SETUP_XfOrM499(x) SETUP(XfOrM499_COUNT)
      info -> transitive_use [i ] = ((void * ) 0 ) ; 
      for (k = 0 ; k < len ; k ++ ) {
#       define XfOrM501_COUNT (0+XfOrM499_COUNT)
#       define SETUP_XfOrM501(x) SETUP_XfOrM499(x)
        FUNCCALL(SETUP_XfOrM501(_), register_transitive_use (info , map [k ] , 0 ) ); 
      }
    }
  }
  info -> stat_dists [i ] [j ] = 1 ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * transitive_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Optimize_Info * info = (Optimize_Info * ) p -> ku . k . p1 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  register_transitive_use (info , p -> ku . k . i1 , p -> ku . k . i2 ) ; 
  return scheme_false ; 
}
static void register_transitive_use (Optimize_Info * info , int pos , int j ) {
  unsigned long _stk_pos ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(info, 0)));
# define XfOrM511_COUNT (1)
# define SETUP_XfOrM511(x) SETUP(XfOrM511_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  _stk_pos = (unsigned long ) & _stk_pos ; 
  if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
    Scheme_Thread * p = scheme_current_thread ; 
#   define XfOrM515_COUNT (0+XfOrM511_COUNT)
#   define SETUP_XfOrM515(x) SETUP_XfOrM511(x)
    p -> ku . k . p1 = (void * ) info ; 
    p -> ku . k . i1 = pos ; 
    p -> ku . k . i2 = j ; 
    FUNCCALL(SETUP_XfOrM515(_), scheme_handle_stack_overflow (transitive_k ) ); 
    RET_NOTHING ; 
  }
  while (info ) {
    if (info -> flags & 8 )
      j ++ ; 
    if (pos < info -> new_frame )
      break ; 
    pos -= info -> new_frame ; 
    info = info -> next ; 
  }
  if (info -> sd_depths [pos ] <= j ) {
#   define XfOrM512_COUNT (0+XfOrM511_COUNT)
#   define SETUP_XfOrM512(x) SETUP_XfOrM511(x)
    FUNCCALL_EMPTY(scheme_signal_error ("bad transitive position depth: %d vs. %d" , info -> sd_depths [pos ] , j ) ); 
  }
  FUNCCALL_EMPTY(register_stat_dist (info , pos , j ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_env_make_closure_map (Optimize_Info * info , mzshort * _size , mzshort * * _map ) {
  Optimize_Info * frame ; 
  int i , j , pos = 0 , lpos = 0 , tu ; 
  mzshort * map , size ; 
  PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(map, 0), PUSH(_map, 1), PUSH(frame, 2), PUSH(info, 3)));
# define XfOrM516_COUNT (4)
# define SETUP_XfOrM516(x) SETUP(XfOrM516_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  frame = NULLED_OUT ; 
  map = NULLED_OUT ; 
  j = 1 ; 
  for (frame = info -> next ; frame ; frame = frame -> next ) {
    if (frame -> flags & 8 )
      j ++ ; 
    if (frame -> stat_dists ) {
      for (i = 0 ; i < frame -> new_frame ; i ++ ) {
        if (frame -> sd_depths [i ] > j ) {
          if (frame -> stat_dists [i ] [j ] ) {
            pos ++ ; 
          }
        }
      }
    }
  }
  size = pos ; 
  * _size = size ; 
  map = ((mzshort * ) FUNCCALL(SETUP_XfOrM516(_), GC_malloc_atomic (sizeof (mzshort ) * (size ) ) )) ; 
  * _map = map ; 
  if (info -> next && info -> next -> transitive_use_pos ) {
    info -> next -> transitive_use [info -> next -> transitive_use_pos - 1 ] = map ; 
    info -> next -> transitive_use_len [info -> next -> transitive_use_pos - 1 ] = size ; 
    tu = 1 ; 
  }
  else tu = 0 ; 
  j = 1 ; 
  pos = 0 ; 
  for (frame = info -> next ; frame ; frame = frame -> next ) {
    if (frame -> flags & 8 )
      j ++ ; 
    if (frame -> stat_dists ) {
      for (i = 0 ; i < frame -> new_frame ; i ++ ) {
        if (frame -> sd_depths [i ] > j ) {
          if (frame -> stat_dists [i ] [j ] ) {
            map [pos ++ ] = lpos ; 
            frame -> stat_dists [i ] [j ] = 0 ; 
            if (! tu )
              frame -> stat_dists [i ] [j - 1 ] = 1 ; 
          }
        }
        lpos ++ ; 
      }
    }
    else lpos += frame -> new_frame ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_env_uses_toplevel (Optimize_Info * frame ) {
  /* No conversion */
  int used ; 
  used = frame -> used_toplevel ; 
  if (used ) {
    frame = frame -> next ; 
    while (frame ) {
      if (frame -> flags & 8 ) {
        frame -> used_toplevel = 1 ; 
        break ; 
      }
      frame = frame -> next ; 
    }
  }
  return used ; 
}
void scheme_optimize_info_used_top (Optimize_Info * info ) {
  /* No conversion */
  while (info ) {
    if (info -> flags & 8 ) {
      info -> used_toplevel = 1 ; 
      break ; 
    }
    info = info -> next ; 
  }
}
void scheme_optimize_propagate (Optimize_Info * info , int pos , Scheme_Object * value ) {
  Scheme_Object * p ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(info, 0), PUSH(p, 1), PUSH(value, 2)));
# define XfOrM561_COUNT (3)
# define SETUP_XfOrM561(x) SETUP(XfOrM561_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  p = NULLED_OUT ; 
  p = FUNCCALL(SETUP_XfOrM561(_), scheme_make_vector (3 , ((void * ) 0 ) ) ); 
  (((Scheme_Vector * ) (p ) ) -> els ) [0 ] = info -> consts ; 
  (((Scheme_Vector * ) (p ) ) -> els ) [1 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (pos ) ) << 1 ) | 0x1 ) ) ; 
  (((Scheme_Vector * ) (p ) ) -> els ) [2 ] = value ; 
  info -> consts = p ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_optimize_mutated (Optimize_Info * info , int pos ) {
  PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(info, 0)));
# define XfOrM562_COUNT (1)
# define SETUP_XfOrM562(x) SETUP(XfOrM562_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! info -> use ) {
    char * use ; 
    BLOCK_SETUP((PUSH(use, 0+XfOrM562_COUNT)));
#   define XfOrM563_COUNT (1+XfOrM562_COUNT)
#   define SETUP_XfOrM563(x) SETUP(XfOrM563_COUNT)
    use = NULLED_OUT ; 
    use = (char * ) FUNCCALL(SETUP_XfOrM563(_), GC_malloc_atomic (info -> new_frame ) ); 
    (memset (use , 0 , info -> new_frame ) ) ; 
    info -> use = use ; 
  }
  info -> use [pos ] = 1 ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_optimize_reverse (Optimize_Info * info , int pos , int unless_mutated ) {
  /* No conversion */
  int delta = 0 ; 
  while (1 ) {
    if (pos < info -> new_frame )
      break ; 
    pos -= info -> new_frame ; 
    delta += info -> original_frame ; 
    info = info -> next ; 
  }
  if (unless_mutated )
    if (info -> use && info -> use [pos ] )
    return ((void * ) 0 ) ; 
  return scheme_make_local (scheme_local_type , pos + delta ) ; 
}
int scheme_optimize_is_used (Optimize_Info * info , int pos ) {
  /* No conversion */
  int i ; 
  if (info -> stat_dists ) {
    for (i = info -> sd_depths [pos ] ; i -- ; ) {
      if (info -> stat_dists [pos ] [i ] )
        return 1 ; 
    }
  }
  return 0 ; 
}
int scheme_optimize_any_uses (Optimize_Info * info , int start_pos , int end_pos ) {
  /* No conversion */
  int j , i ; 
  if (info -> stat_dists ) {
    for (i = start_pos ; i < end_pos ; i ++ ) {
      for (j = info -> sd_depths [i ] ; j -- ; ) {
        if (info -> stat_dists [i ] [j ] )
          return 1 ; 
      }
    }
  }
  if (info -> transitive_use ) {
    for (i = info -> new_frame ; i -- ; ) {
      if (info -> transitive_use [i ] ) {
        for (j = info -> transitive_use_len [i ] ; j -- ; ) {
          if ((info -> transitive_use [i ] [j ] >= start_pos ) && (info -> transitive_use [i ] [j ] < end_pos ) )
            return 1 ; 
        }
      }
    }
  }
  return 0 ; 
}
static Scheme_Object * do_optimize_info_lookup (Optimize_Info * info , int pos , int j , int * closure_offset ) {
  Scheme_Object * p , * n ; 
  int delta = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(closure_offset, 0), PUSH(info, 1), PUSH(n, 2), PUSH(p, 3)));
# define XfOrM588_COUNT (4)
# define SETUP_XfOrM588(x) SETUP(XfOrM588_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  p = NULLED_OUT ; 
  n = NULLED_OUT ; 
  while (info ) {
    if (info -> flags & 8 )
      j ++ ; 
    if (pos < info -> original_frame )
      break ; 
    pos -= info -> original_frame ; 
    delta += info -> new_frame ; 
    info = info -> next ; 
  }
  p = info -> consts ; 
  while (p ) {
#   define XfOrM597_COUNT (0+XfOrM588_COUNT)
#   define SETUP_XfOrM597(x) SETUP_XfOrM588(x)
    n = (((Scheme_Vector * ) (p ) ) -> els ) [1 ] ; 
    if ((((long ) (n ) ) >> 1 ) == pos ) {
#     define XfOrM598_COUNT (0+XfOrM597_COUNT)
#     define SETUP_XfOrM598(x) SETUP_XfOrM597(x)
      n = (((Scheme_Vector * ) (p ) ) -> els ) [2 ] ; 
      if (((Scheme_Type ) (((((long ) (n ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n ) ) -> type ) ) == (Scheme_Type ) (scheme_compiled_unclosed_procedure_type ) ) ) {
        if (! closure_offset )
          break ; 
        else {
          * closure_offset = delta ; 
        }
      }
      else if (((Scheme_Type ) (((((long ) (n ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n ) ) -> type ) ) == (Scheme_Type ) (scheme_compiled_toplevel_type ) ) ) {
      }
      else if (closure_offset ) {
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      else if (((Scheme_Type ) (((((long ) (n ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n ) ) -> type ) ) == (Scheme_Type ) (scheme_local_type ) ) ) {
        int pos ; 
#       define XfOrM599_COUNT (0+XfOrM598_COUNT)
#       define SETUP_XfOrM599(x) SETUP_XfOrM598(x)
        pos = (((Scheme_Local * ) (n ) ) -> position ) ; 
        if (info -> flags & 8 )
          j -- ; 
        n = FUNCCALL(SETUP_XfOrM599(_), do_optimize_info_lookup (info , pos , j , ((void * ) 0 ) ) ); 
        if (! n ) {
#         define XfOrM600_COUNT (0+XfOrM599_COUNT)
#         define SETUP_XfOrM600(x) SETUP_XfOrM599(x)
          delta += FUNCCALL(SETUP_XfOrM600(_), scheme_optimize_info_get_shift (info , pos ) ); 
          n = FUNCCALL(SETUP_XfOrM600(_), scheme_make_local (scheme_local_type , pos + delta ) ); 
        }
      }
      RET_VALUE_START (n ) RET_VALUE_END ; 
    }
    p = (((Scheme_Vector * ) (p ) ) -> els ) [0 ] ; 
  }
  if (! closure_offset )
    FUNCCALL_EMPTY(register_stat_dist (info , pos , j ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_optimize_info_lookup (Optimize_Info * info , int pos , int * closure_offset ) {
  /* No conversion */
  return do_optimize_info_lookup (info , pos , 0 , closure_offset ) ; 
}
Optimize_Info * scheme_optimize_info_add_frame (Optimize_Info * info , int orig , int current , int flags ) {
  Optimize_Info * naya ; 
  DECL_RET_SAVE (Optimize_Info * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(naya, 0), PUSH(info, 1)));
# define XfOrM608_COUNT (2)
# define SETUP_XfOrM608(x) SETUP(XfOrM608_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  naya = NULLED_OUT ; 
  naya = FUNCCALL(SETUP_XfOrM608(_), scheme_optimize_info_create () ); 
  naya -> flags = (short ) flags ; 
  naya -> next = info ; 
  naya -> original_frame = orig ; 
  naya -> new_frame = current ; 
  naya -> inline_fuel = info -> inline_fuel ; 
  naya -> letrec_not_twice = info -> letrec_not_twice ; 
  naya -> enforce_const = info -> enforce_const ; 
  naya -> top_level_consts = info -> top_level_consts ; 
  RET_VALUE_START (naya ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_optimize_info_get_shift (Optimize_Info * info , int pos ) {
  /* No conversion */
  int delta = 0 ; 
  while (info ) {
    if (pos < info -> original_frame )
      break ; 
    pos -= info -> original_frame ; 
    delta += (info -> new_frame - info -> original_frame ) ; 
    info = info -> next ; 
  }
  if (! info )
    * (long * ) 0x0 = 1 ; 
  return delta ; 
}
void scheme_optimize_info_done (Optimize_Info * info ) {
  /* No conversion */
  info -> next -> size += info -> size ; 
}
Resolve_Prefix * scheme_resolve_prefix (int phase , Comp_Prefix * cp , int simplify ) {
  Resolve_Prefix * rp ; 
  Scheme_Object * * tls , * * stxes , * simplify_cache ; 
  Scheme_Hash_Table * ht ; 
  int i ; 
  DECL_RET_SAVE (Resolve_Prefix * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(rp, 0), PUSH(ht, 1), PUSH(cp, 2), PUSH(stxes, 3), PUSH(simplify_cache, 4), PUSH(tls, 5)));
# define XfOrM613_COUNT (6)
# define SETUP_XfOrM613(x) SETUP(XfOrM613_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  rp = NULLED_OUT ; 
  tls = NULLED_OUT ; 
  stxes = NULLED_OUT ; 
  simplify_cache = NULLED_OUT ; 
  ht = NULLED_OUT ; 
  rp = ((Resolve_Prefix * ) FUNCCALL(SETUP_XfOrM613(_), GC_malloc_one_small_tagged ((((sizeof (Resolve_Prefix ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  rp -> so . type = scheme_resolve_prefix_type ; 
  rp -> num_toplevels = cp -> num_toplevels ; 
  rp -> num_stxes = cp -> num_stxes ; 
  if (rp -> num_toplevels )
    tls = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM613(_), GC_malloc (sizeof (Scheme_Object * ) * (rp -> num_toplevels ) ) )) ; 
  else tls = ((void * ) 0 ) ; 
  if (rp -> num_stxes )
    stxes = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM613(_), GC_malloc (sizeof (Scheme_Object * ) * (rp -> num_stxes ) ) )) ; 
  else stxes = ((void * ) 0 ) ; 
  rp -> toplevels = tls ; 
  rp -> stxes = stxes ; 
  ht = cp -> toplevels ; 
  if (ht ) {
    for (i = 0 ; i < ht -> size ; i ++ ) {
      if (ht -> vals [i ] ) {
        tls [(((Scheme_Toplevel * ) (ht -> vals [i ] ) ) -> position ) ] = ht -> keys [i ] ; 
      }
    }
  }
  if (simplify )
    simplify_cache = FUNCCALL(SETUP_XfOrM613(_), scheme_new_stx_simplify_cache () ); 
  else simplify_cache = ((void * ) 0 ) ; 
  ht = cp -> stxes ; 
  if (ht ) {
#   define XfOrM614_COUNT (0+XfOrM613_COUNT)
#   define SETUP_XfOrM614(x) SETUP_XfOrM613(x)
    for (i = 0 ; i < ht -> size ; i ++ ) {
#     define XfOrM617_COUNT (0+XfOrM614_COUNT)
#     define SETUP_XfOrM617(x) SETUP_XfOrM614(x)
      if (ht -> vals [i ] ) {
#       define XfOrM618_COUNT (0+XfOrM617_COUNT)
#       define SETUP_XfOrM618(x) SETUP_XfOrM617(x)
        FUNCCALL(SETUP_XfOrM618(_), scheme_simplify_stx (ht -> keys [i ] , simplify_cache ) ); 
        stxes [(((Scheme_Local * ) (ht -> vals [i ] ) ) -> position ) ] = ht -> keys [i ] ; 
      }
    }
  }
  RET_VALUE_START (rp ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Resolve_Prefix * scheme_remap_prefix (Resolve_Prefix * rp , Resolve_Info * ri ) {
  int i , cnt ; 
  Scheme_Object * * new_stxes , * v ; 
  DECL_RET_SAVE (Resolve_Prefix * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(rp, 1), PUSH(ri, 2), PUSH(new_stxes, 3)));
# define XfOrM624_COUNT (4)
# define SETUP_XfOrM624(x) SETUP(XfOrM624_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  new_stxes = NULLED_OUT ; 
  v = NULLED_OUT ; 
  if (! rp -> num_stxes )
    RET_VALUE_START (rp ) RET_VALUE_END ; 
  if (rp -> num_lifts )
    cnt = rp -> num_stxes ; 
  else cnt = ri -> stx_map -> count ; 
  new_stxes = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM624(_), GC_malloc (sizeof (Scheme_Object * ) * (cnt ) ) )) ; 
  for (i = 0 ; i < rp -> num_stxes ; i ++ ) {
#   define XfOrM627_COUNT (0+XfOrM624_COUNT)
#   define SETUP_XfOrM627(x) SETUP_XfOrM624(x)
    if (ri -> stx_map )
      v = FUNCCALL(SETUP_XfOrM627(_), scheme_hash_get (ri -> stx_map , ((Scheme_Object * ) (void * ) (long ) ((((long ) (i ) ) << 1 ) | 0x1 ) ) ) ); 
    else v = ((void * ) 0 ) ; 
    if (v ) {
      new_stxes [(((long ) (v ) ) >> 1 ) ] = rp -> stxes [i ] ; 
    }
  }
  rp -> stxes = new_stxes ; 
  rp -> num_stxes = cnt ; 
  RET_VALUE_START (rp ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Resolve_Info * scheme_resolve_info_create (Resolve_Prefix * rp ) {
  Resolve_Info * naya ; 
  Scheme_Object * b ; 
  Scheme_Hash_Table * ht ; 
  Scheme_Config * __funcarg36 = NULLED_OUT ; 
  DECL_RET_SAVE (Resolve_Info * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(b, 0), PUSH(rp, 1), PUSH(naya, 2), PUSH(ht, 3)));
# define XfOrM629_COUNT (4)
# define SETUP_XfOrM629(x) SETUP(XfOrM629_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  naya = NULLED_OUT ; 
  b = NULLED_OUT ; 
  ht = NULLED_OUT ; 
  naya = ((Resolve_Info * ) FUNCCALL(SETUP_XfOrM629(_), GC_malloc_one_small_tagged ((((sizeof (Resolve_Info ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  naya -> type = scheme_rt_resolve_info ; 
  naya -> prefix = rp ; 
  naya -> count = 0 ; 
  naya -> next = ((void * ) 0 ) ; 
  naya -> toplevel_pos = - 1 ; 
  ht = FUNCCALL(SETUP_XfOrM629(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  naya -> stx_map = ht ; 
  b = (__funcarg36 = FUNCCALL(SETUP_XfOrM629(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg36 , MZCONFIG_USE_JIT ) )) ; 
  naya -> use_jit = (! (((b ) ) == (scheme_false ) ) ) ; 
  RET_VALUE_START (naya ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Resolve_Info * scheme_resolve_info_extend (Resolve_Info * info , int size , int oldsize , int mapc ) {
  Resolve_Info * naya ; 
  DECL_RET_SAVE (Resolve_Info * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(naya, 0), PUSH(info, 1)));
# define XfOrM630_COUNT (2)
# define SETUP_XfOrM630(x) SETUP(XfOrM630_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  naya = NULLED_OUT ; 
  naya = ((Resolve_Info * ) FUNCCALL(SETUP_XfOrM630(_), GC_malloc_one_small_tagged ((((sizeof (Resolve_Info ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  naya -> type = scheme_rt_resolve_info ; 
  naya -> prefix = info -> prefix ; 
  naya -> stx_map = info -> stx_map ; 
  naya -> next = info ; 
  naya -> use_jit = info -> use_jit ; 
  naya -> enforce_const = info -> enforce_const ; 
  naya -> size = size ; 
  naya -> oldsize = oldsize ; 
  naya -> count = mapc ; 
  naya -> pos = 0 ; 
  naya -> toplevel_pos = - 1 ; 
  naya -> lifts = info -> lifts ; 
  if (mapc ) {
    int i , * ia ; 
    mzshort * sa ; 
    BLOCK_SETUP((PUSH(ia, 0+XfOrM630_COUNT), PUSH(sa, 1+XfOrM630_COUNT)));
#   define XfOrM631_COUNT (2+XfOrM630_COUNT)
#   define SETUP_XfOrM631(x) SETUP(XfOrM631_COUNT)
    ia = NULLED_OUT ; 
    sa = NULLED_OUT ; 
    sa = ((mzshort * ) FUNCCALL(SETUP_XfOrM631(_), GC_malloc_atomic (sizeof (mzshort ) * (mapc ) ) )) ; 
    naya -> old_pos = sa ; 
    sa = ((mzshort * ) FUNCCALL(SETUP_XfOrM631(_), GC_malloc_atomic (sizeof (mzshort ) * (mapc ) ) )) ; 
    naya -> new_pos = sa ; 
    ia = ((int * ) FUNCCALL(SETUP_XfOrM631(_), GC_malloc_atomic (sizeof (int ) * (mapc ) ) )) ; 
    naya -> flags = ia ; 
    for (i = mapc ; i -- ; ) {
      naya -> old_pos [i ] = 0 ; 
      naya -> new_pos [i ] = 0 ; 
      naya -> flags [i ] = 0 ; 
    }
  }
  RET_VALUE_START (naya ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_resolve_info_add_mapping (Resolve_Info * info , int oldp , int newp , int flags , Scheme_Object * lifted ) {
  PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(lifted, 0), PUSH(info, 1)));
# define XfOrM634_COUNT (2)
# define SETUP_XfOrM634(x) SETUP(XfOrM634_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (info -> pos == info -> count ) {
#   define XfOrM637_COUNT (0+XfOrM634_COUNT)
#   define SETUP_XfOrM637(x) SETUP_XfOrM634(x)
    FUNCCALL_EMPTY(scheme_signal_error ("internal error: add_mapping: " "too many: %d" , info -> pos ) ); 
  }
  info -> old_pos [info -> pos ] = oldp ; 
  info -> new_pos [info -> pos ] = newp ; 
  info -> flags [info -> pos ] = flags ; 
  if (lifted ) {
#   define XfOrM635_COUNT (0+XfOrM634_COUNT)
#   define SETUP_XfOrM635(x) SETUP_XfOrM634(x)
    if (! info -> lifted ) {
      Scheme_Object * * lifteds ; 
      BLOCK_SETUP((PUSH(lifteds, 0+XfOrM635_COUNT)));
#     define XfOrM636_COUNT (1+XfOrM635_COUNT)
#     define SETUP_XfOrM636(x) SETUP(XfOrM636_COUNT)
      lifteds = NULLED_OUT ; 
      lifteds = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM636(_), GC_malloc (sizeof (Scheme_Object * ) * (info -> count ) ) )) ; 
      info -> lifted = lifteds ; 
    }
    info -> lifted [info -> pos ] = lifted ; 
  }
  info -> pos ++ ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_resolve_info_adjust_mapping (Resolve_Info * info , int oldp , int newp , int flags , Scheme_Object * lifted ) {
  /* No conversion */
  int i ; 
  for (i = info -> pos ; i -- ; ) {
    if (info -> old_pos [i ] == oldp ) {
      info -> new_pos [i ] = newp ; 
      info -> flags [i ] = flags ; 
      if (lifted ) {
        info -> lifted [i ] = lifted ; 
      }
      return ; 
    }
  }
  scheme_signal_error ("internal error: adjust_mapping: " "couldn't find: %d" , oldp ) ; 
}
void scheme_resolve_info_set_toplevel_pos (Resolve_Info * info , int pos ) {
  /* No conversion */
  info -> toplevel_pos = pos ; 
}
static int resolve_info_lookup (Resolve_Info * info , int pos , int * flags , Scheme_Object * * _lifted , int convert_shift ) {
  Resolve_Info * orig_info = info ; 
  int i , offset = 0 , orig = pos ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(11);
  BLOCK_SETUP_TOP((PUSH(orig_info, 0), PUSH(info, 1), PUSH(_lifted, 2), PUSH(flags, 3)));
# define XfOrM646_COUNT (4)
# define SETUP_XfOrM646(x) SETUP(XfOrM646_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (_lifted )
    * _lifted = ((void * ) 0 ) ; 
  while (info ) {
#   define XfOrM671_COUNT (0+XfOrM646_COUNT)
#   define SETUP_XfOrM671(x) SETUP_XfOrM646(x)
    for (i = info -> pos ; i -- ; ) {
      int oldp = info -> old_pos [i ] ; 
#     define XfOrM684_COUNT (0+XfOrM671_COUNT)
#     define SETUP_XfOrM684(x) SETUP_XfOrM671(x)
      if (pos == oldp ) {
#       define XfOrM685_COUNT (0+XfOrM684_COUNT)
#       define SETUP_XfOrM685(x) SETUP_XfOrM684(x)
        if (flags )
          * flags = info -> flags [i ] ; 
        if (info -> lifted && (info -> lifted [i ] ) ) {
          int skip , shifted ; 
          Scheme_Object * lifted , * tl , * * ca ; 
          BLOCK_SETUP((PUSH(lifted, 0+XfOrM685_COUNT), PUSH(ca, 1+XfOrM685_COUNT), PUSH(tl, 2+XfOrM685_COUNT)));
#         define XfOrM686_COUNT (3+XfOrM685_COUNT)
#         define SETUP_XfOrM686(x) SETUP(XfOrM686_COUNT)
          lifted = NULLED_OUT ; 
          tl = NULLED_OUT ; 
          ca = NULLED_OUT ; 
          if (! _lifted )
            FUNCCALL_EMPTY(scheme_signal_error ("unexpected lifted binding" ) ); 
          lifted = info -> lifted [i ] ; 
          if (((Scheme_Type ) (((((long ) (lifted ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lifted ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ) {
            tl = (((Scheme_Simple_Object * ) (lifted ) ) -> u . pair_val . car ) ; 
            ca = (Scheme_Object * * ) (((Scheme_Simple_Object * ) (lifted ) ) -> u . pair_val . cdr ) ; 
            if (convert_shift )
              shifted = (((long ) (ca [0 ] ) ) >> 1 ) + convert_shift - 1 ; 
            else shifted = 0 ; 
          }
          else {
            tl = lifted ; 
            shifted = 0 ; 
            ca = ((void * ) 0 ) ; 
          }
          if (((Scheme_Type ) (((((long ) (tl ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (tl ) ) -> type ) ) == (Scheme_Type ) (scheme_toplevel_type ) ) ) {
#           define XfOrM692_COUNT (0+XfOrM686_COUNT)
#           define SETUP_XfOrM692(x) SETUP_XfOrM686(x)
            skip = FUNCCALL(SETUP_XfOrM692(_), scheme_resolve_toplevel_pos (orig_info ) ); 
            tl = FUNCCALL(SETUP_XfOrM692(_), make_toplevel (skip + shifted , (((Scheme_Toplevel * ) (tl ) ) -> position ) , 1 , 0x1 ) ); 
          }
          if (((Scheme_Type ) (((((long ) (lifted ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lifted ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ) {
            int sz , i ; 
            mzshort * posmap , * boxmap ; 
            Scheme_Object * vec , * loc ; 
            BLOCK_SETUP((PUSH(vec, 0+XfOrM686_COUNT), PUSH(boxmap, 1+XfOrM686_COUNT), PUSH(loc, 2+XfOrM686_COUNT), PUSH(posmap, 3+XfOrM686_COUNT)));
#           define XfOrM687_COUNT (4+XfOrM686_COUNT)
#           define SETUP_XfOrM687(x) SETUP(XfOrM687_COUNT)
            posmap = NULLED_OUT ; 
            boxmap = NULLED_OUT ; 
            vec = NULLED_OUT ; 
            loc = NULLED_OUT ; 
            sz = (((long ) (ca [0 ] ) ) >> 1 ) ; 
            posmap = (mzshort * ) ca [1 ] ; 
            boxmap = (mzshort * ) ca [3 ] ; 
            vec = FUNCCALL(SETUP_XfOrM687(_), scheme_make_vector (sz + 1 , ((void * ) 0 ) ) ); 
            for (i = 0 ; i < sz ; i ++ ) {
#             define XfOrM690_COUNT (0+XfOrM687_COUNT)
#             define SETUP_XfOrM690(x) SETUP_XfOrM687(x)
              loc = FUNCCALL(SETUP_XfOrM690(_), scheme_make_local (scheme_local_type , posmap [i ] + offset + shifted ) ); 
              if (boxmap ) {
#               define XfOrM691_COUNT (0+XfOrM690_COUNT)
#               define SETUP_XfOrM691(x) SETUP_XfOrM690(x)
                if (boxmap [i / (8 * sizeof (mzshort ) ) ] & ((mzshort ) 1 << (i & ((8 * sizeof (mzshort ) ) - 1 ) ) ) )
                  loc = FUNCCALL(SETUP_XfOrM691(_), scheme_box (loc ) ); 
              }
              (((Scheme_Vector * ) (vec ) ) -> els ) [i + 1 ] = loc ; 
            }
            (((Scheme_Vector * ) (vec ) ) -> els ) [0 ] = ca [2 ] ; 
            lifted = FUNCCALL(SETUP_XfOrM687(_), scheme_make_raw_pair (tl , vec ) ); 
          }
          else lifted = tl ; 
          * _lifted = lifted ; 
          RET_VALUE_START (0 ) RET_VALUE_END ; 
        }
        else RET_VALUE_START (info -> new_pos [i ] + offset ) RET_VALUE_END ; 
      }
    }
    if (info -> in_proc ) {
#     define XfOrM672_COUNT (0+XfOrM671_COUNT)
#     define SETUP_XfOrM672(x) SETUP_XfOrM671(x)
      FUNCCALL_EMPTY(scheme_signal_error ("internal error: scheme_resolve_info_lookup: " "searching past procedure" ) ); 
    }
    pos -= info -> oldsize ; 
    offset += info -> size ; 
    info = info -> next ; 
  }
  FUNCCALL_EMPTY(scheme_signal_error ("internal error: scheme_resolve_info_lookup: " "variable %d not found" , orig ) ); 
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_resolve_generate_stub_lift () {
  /* No conversion */
  return make_toplevel (0 , 0 , 1 , 0x1 ) ; 
}
int scheme_resolve_info_flags (Resolve_Info * info , int pos , Scheme_Object * * lifted ) {
  /* No conversion */
  int flags ; 
  resolve_info_lookup (info , pos , & flags , lifted , 0 ) ; 
  return flags ; 
}
int scheme_resolve_info_lookup (Resolve_Info * info , int pos , int * flags , Scheme_Object * * lifted , int convert_shift ) {
  /* No conversion */
  return resolve_info_lookup (info , pos , flags , lifted , convert_shift ) ; 
}
int scheme_resolve_toplevel_pos (Resolve_Info * info ) {
  /* No conversion */
  int pos = 0 ; 
  while (info && (info -> toplevel_pos < 0 ) ) {
    if (info -> in_proc ) {
      scheme_signal_error ("internal error: scheme_resolve_toplevel_pos: " "searching past procedure" ) ; 
    }
    pos += info -> size ; 
    info = info -> next ; 
  }
  if (! info )
    return pos ; 
  else return info -> toplevel_pos + pos ; 
}
int scheme_resolve_is_toplevel_available (Resolve_Info * info ) {
  /* No conversion */
  while (info ) {
    if (info -> toplevel_pos >= 0 )
      return 1 ; 
    if (info -> in_proc )
      return 0 ; 
    info = info -> next ; 
  }
  return 0 ; 
}
int scheme_resolve_quote_syntax_offset (int i , Resolve_Info * info ) {
  Scheme_Hash_Table * ht ; 
  Scheme_Object * v ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(ht, 1)));
# define XfOrM706_COUNT (2)
# define SETUP_XfOrM706(x) SETUP(XfOrM706_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ht = NULLED_OUT ; 
  v = NULLED_OUT ; 
  ht = info -> stx_map ; 
  v = FUNCCALL(SETUP_XfOrM706(_), scheme_hash_get (ht , ((Scheme_Object * ) (void * ) (long ) ((((long ) (i ) ) << 1 ) | 0x1 ) ) ) ); 
  if (! v ) {
#   define XfOrM707_COUNT (0+XfOrM706_COUNT)
#   define SETUP_XfOrM707(x) SETUP_XfOrM706(x)
    v = ((Scheme_Object * ) (void * ) (long ) ((((long ) (ht -> count ) ) << 1 ) | 0x1 ) ) ; 
    FUNCCALL(SETUP_XfOrM707(_), scheme_hash_set (ht , ((Scheme_Object * ) (void * ) (long ) ((((long ) (i ) ) << 1 ) | 0x1 ) ) , v ) ); 
  }
  RET_VALUE_START ((((long ) (v ) ) >> 1 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_resolve_quote_syntax_pos (Resolve_Info * info ) {
  /* No conversion */
  return info -> prefix -> num_toplevels ; 
}
Scheme_Object * scheme_resolve_toplevel (Resolve_Info * info , Scheme_Object * expr ) {
  int skip ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(expr, 0)));
# define XfOrM709_COUNT (1)
# define SETUP_XfOrM709(x) SETUP(XfOrM709_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  skip = FUNCCALL(SETUP_XfOrM709(_), scheme_resolve_toplevel_pos (info ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(make_toplevel (skip + (((Scheme_Toplevel * ) (expr ) ) -> depth ) , (((Scheme_Toplevel * ) (expr ) ) -> position ) , 1 , (& ((Scheme_Toplevel * ) (expr ) ) -> iso ) -> so . keyex & 0x1 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 3436 */
Scheme_Object * scheme_shift_toplevel (Scheme_Object * expr , int delta ) {
  /* No conversion */
  return make_toplevel ((((Scheme_Toplevel * ) (expr ) ) -> depth ) + delta , (((Scheme_Toplevel * ) (expr ) ) -> position ) , 1 , (& ((Scheme_Toplevel * ) (expr ) ) -> iso ) -> so . keyex & 0x3 ) ; 
}
Scheme_Object * scheme_resolve_invent_toplevel (Resolve_Info * info ) {
  int skip , pos ; 
  Scheme_Object * count ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(count, 0), PUSH(info, 1)));
# define XfOrM711_COUNT (2)
# define SETUP_XfOrM711(x) SETUP(XfOrM711_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  count = NULLED_OUT ; 
  skip = FUNCCALL(SETUP_XfOrM711(_), scheme_resolve_toplevel_pos (info ) ); 
  count = (((Scheme_Vector * ) (info -> lifts ) ) -> els ) [1 ] ; 
  pos = ((((long ) (count ) ) >> 1 ) + info -> prefix -> num_toplevels + info -> prefix -> num_stxes + (info -> prefix -> num_stxes ? 1 : 0 ) ) ; 
  count = ((Scheme_Object * ) (void * ) (long ) ((((long ) ((((long ) (count ) ) >> 1 ) + 1 ) ) << 1 ) | 0x1 ) ) ; 
  (((Scheme_Vector * ) (info -> lifts ) ) -> els ) [1 ] = count ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(make_toplevel (skip , pos , 1 , 0x1 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_resolve_invented_toplevel_to_defn (Resolve_Info * info , Scheme_Object * tl ) {
  /* No conversion */
  return make_toplevel (0 , (((Scheme_Toplevel * ) (tl ) ) -> position ) , 1 , 0x1 ) ; 
}
int scheme_resolving_in_procedure (Resolve_Info * info ) {
  /* No conversion */
  while (info ) {
    if (info -> in_proc )
      return 1 ; 
    info = info -> next ; 
  }
  return 0 ; 
}
Scheme_Object * scheme_make_envunbox (Scheme_Object * value ) {
  Scheme_Object * obj ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(obj, 0), PUSH(value, 1)));
# define XfOrM716_COUNT (2)
# define SETUP_XfOrM716(x) SETUP(XfOrM716_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  obj = NULLED_OUT ; 
  obj = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM716(_), GC_malloc (sizeof (Scheme_Object * ) ) ); 
  (* ((Scheme_Object * * ) (obj ) ) ) = value ; 
  RET_VALUE_START (obj ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * namespace_identifier (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * obj ; 
  Scheme_Env * genv ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(obj, 0), PUSH(argv, 1), PUSH(genv, 2)));
# define XfOrM717_COUNT (3)
# define SETUP_XfOrM717(x) SETUP(XfOrM717_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  obj = NULLED_OUT ; 
  genv = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("namespace-symbol->identifier" , "symbol" , 0 , argc , argv ) ); 
  if ((argc > 1 ) && ! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_namespace_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("namespace-symbol->identifier" , "namespace" , 1 , argc , argv ) ); 
  if (argc > 1 )
    genv = (Scheme_Env * ) argv [1 ] ; 
  else genv = FUNCCALL(SETUP_XfOrM717(_), scheme_get_env (((void * ) 0 ) ) ); 
  obj = argv [0 ] ; 
  obj = FUNCCALL(SETUP_XfOrM717(_), scheme_datum_to_syntax (obj , scheme_false , scheme_false , 1 , 0 ) ); 
  if (genv -> rename )
    obj = FUNCCALL(SETUP_XfOrM717(_), scheme_add_rename (obj , genv -> rename ) ); 
  if (genv -> exp_env && genv -> exp_env -> rename )
    obj = FUNCCALL(SETUP_XfOrM717(_), scheme_add_rename (obj , genv -> exp_env -> rename ) ); 
  RET_VALUE_START (obj ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * namespace_variable_value (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * v , * id = ((void * ) 0 ) ; 
  Scheme_Env * genv ; 
  int use_map ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(22);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(id, 1), PUSH(argv, 2), PUSH(genv, 3)));
# define XfOrM718_COUNT (4)
# define SETUP_XfOrM718(x) SETUP(XfOrM718_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  v = NULLED_OUT ; 
  genv = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("namespace-variable-value" , "symbol" , 0 , argc , argv ) ); 
  use_map = ((argc > 1 ) ? (! (((argv [1 ] ) ) == (scheme_false ) ) ) : 1 ) ; 
  if ((argc > 2 ) && (! (((argv [2 ] ) ) == (scheme_false ) ) ) && ! FUNCCALL(SETUP_XfOrM718(_), scheme_check_proc_arity (((void * ) 0 ) , 0 , 2 , argc , argv ) ))
    FUNCCALL_EMPTY(scheme_wrong_type ("namespace-variable-value" , "procedure (arity 0) or #f" , 1 , argc , argv ) ); 
  if ((argc > 3 ) && ! ((Scheme_Type ) (((((long ) (argv [3 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [3 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_namespace_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("namespace-variable-value" , "namespace" , 3 , argc , argv ) ); 
  if (argc > 3 )
    genv = (Scheme_Env * ) argv [3 ] ; 
  else genv = FUNCCALL(SETUP_XfOrM718(_), scheme_get_env (((void * ) 0 ) ) ); 
  if (! use_map )
    v = FUNCCALL(SETUP_XfOrM718(_), scheme_lookup_global (argv [0 ] , genv ) ); 
  else {
    Scheme_Full_Comp_Env inlined_e ; 
    BLOCK_SETUP((PUSH(inlined_e.base.genv, 0+XfOrM718_COUNT), PUSH(inlined_e.base.insp, 1+XfOrM718_COUNT), PUSH(inlined_e.base.prefix, 2+XfOrM718_COUNT), PUSH(inlined_e.base.values, 3+XfOrM718_COUNT), PUSH(inlined_e.base.certs, 4+XfOrM718_COUNT), PUSH(inlined_e.base.uid, 5+XfOrM718_COUNT), PUSH(inlined_e.base.uids, 6+XfOrM718_COUNT), PUSH(inlined_e.base.renames, 7+XfOrM718_COUNT), PUSH(inlined_e.base.dup_check, 8+XfOrM718_COUNT), PUSH(inlined_e.base.intdef_name, 9+XfOrM718_COUNT), PUSH(inlined_e.base.in_modidx, 10+XfOrM718_COUNT), PUSH(inlined_e.base.skip_table, 11+XfOrM718_COUNT), PUSH(inlined_e.base.next, 12+XfOrM718_COUNT), PUSH(inlined_e.data.const_names, 13+XfOrM718_COUNT), PUSH(inlined_e.data.const_vals, 14+XfOrM718_COUNT), PUSH(inlined_e.data.const_uids, 15+XfOrM718_COUNT), PUSH(inlined_e.data.use, 16+XfOrM718_COUNT), PUSH(inlined_e.data.lifts, 17+XfOrM718_COUNT)));
#   define XfOrM722_COUNT (18+XfOrM718_COUNT)
#   define SETUP_XfOrM722(x) SETUP(XfOrM722_COUNT)
    inlined_e.base.genv = NULLED_OUT ; 
    inlined_e.base.insp = NULLED_OUT ; 
    inlined_e.base.prefix = NULLED_OUT ; 
    inlined_e.base.values = NULLED_OUT ; 
    inlined_e.base.certs = NULLED_OUT ; 
    inlined_e.base.uid = NULLED_OUT ; 
    inlined_e.base.uids = NULLED_OUT ; 
    inlined_e.base.renames = NULLED_OUT ; 
    inlined_e.base.dup_check = NULLED_OUT ; 
    inlined_e.base.intdef_name = NULLED_OUT ; 
    inlined_e.base.in_modidx = NULLED_OUT ; 
    inlined_e.base.skip_table = NULLED_OUT ; 
    inlined_e.base.next = NULLED_OUT ; 
    inlined_e.data.const_names = NULLED_OUT ; 
    inlined_e.data.const_vals = NULLED_OUT ; 
    inlined_e.data.const_uids = NULLED_OUT ; 
    inlined_e.data.use = NULLED_OUT ; 
    inlined_e.data.lifts = NULLED_OUT ; 
    id = FUNCCALL(SETUP_XfOrM722(_), scheme_make_renamed_stx (argv [0 ] , genv -> rename ) ); 
    inlined_e . base . num_bindings = 0 ; 
    inlined_e . base . next = ((void * ) 0 ) ; 
    inlined_e . base . genv = genv ; 
    inlined_e . base . flags = 1 ; 
    FUNCCALL(SETUP_XfOrM722(_), init_compile_data ((Scheme_Comp_Env * ) & inlined_e ) ); 
    inlined_e . base . prefix = ((void * ) 0 ) ; 
    v = FUNCCALL(SETUP_XfOrM722(_), scheme_lookup_binding (id , (Scheme_Comp_Env * ) & inlined_e , 1024 , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
    if (v ) {
      if (! ((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_variable_type ) ) ) {
        use_map = - 1 ; 
        v = ((void * ) 0 ) ; 
      }
      else v = (Scheme_Object * ) (((Scheme_Bucket * ) (v ) ) ) -> val ; 
    }
  }
  if (! v ) {
#   define XfOrM719_COUNT (0+XfOrM718_COUNT)
#   define SETUP_XfOrM719(x) SETUP_XfOrM718(x)
    if ((argc > 2 ) && (! (((argv [2 ] ) ) == (scheme_false ) ) ) )
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_tail_apply (argv [2 ] , 0 , ((void * ) 0 ) ) )) RET_VALUE_EMPTY_END ; 
    else if (use_map == - 1 ) {
#     define XfOrM721_COUNT (0+XfOrM719_COUNT)
#     define SETUP_XfOrM721(x) SETUP_XfOrM719(x)
      FUNCCALL_EMPTY(scheme_wrong_syntax ("namespace-variable-value" , ((void * ) 0 ) , id , "bound to syntax" ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else {
#     define XfOrM720_COUNT (0+XfOrM719_COUNT)
#     define SETUP_XfOrM720(x) SETUP_XfOrM719(x)
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT_VARIABLE , argv [0 ] , "namespace-variable-value: %S is not defined" , argv [0 ] ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * namespace_set_variable_value (int argc , Scheme_Object * argv [] ) {
  Scheme_Env * env ; 
  Scheme_Bucket * bucket ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(bucket, 1), PUSH(argv, 2)));
# define XfOrM725_COUNT (3)
# define SETUP_XfOrM725(x) SETUP(XfOrM725_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  env = NULLED_OUT ; 
  bucket = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("namespace-set-variable-value!" , "symbol" , 0 , argc , argv ) ); 
  if ((argc > 3 ) && ! ((Scheme_Type ) (((((long ) (argv [3 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [3 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_namespace_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("namespace-set-variable-value!" , "namespace" , 3 , argc , argv ) ); 
  if (argc > 3 )
    env = (Scheme_Env * ) argv [3 ] ; 
  else env = FUNCCALL(SETUP_XfOrM725(_), scheme_get_env (((void * ) 0 ) ) ); 
  bucket = FUNCCALL(SETUP_XfOrM725(_), scheme_global_bucket (argv [0 ] , env ) ); 
  FUNCCALL_AGAIN(scheme_set_global_bucket ("namespace-set-variable-value!" , bucket , argv [1 ] , 1 ) ); 
  if ((argc > 2 ) && (! (((argv [2 ] ) ) == (scheme_false ) ) ) ) {
#   define XfOrM726_COUNT (0+XfOrM725_COUNT)
#   define SETUP_XfOrM726(x) SETUP_XfOrM725(x)
    FUNCCALL_EMPTY(scheme_shadow (env , argv [0 ] , 1 ) ); 
  }
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * namespace_undefine_variable (int argc , Scheme_Object * argv [] ) {
  Scheme_Env * env ; 
  Scheme_Bucket * bucket ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(bucket, 0), PUSH(env, 1), PUSH(argv, 2)));
# define XfOrM727_COUNT (3)
# define SETUP_XfOrM727(x) SETUP(XfOrM727_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  env = NULLED_OUT ; 
  bucket = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("namespace-undefine-variable!" , "symbol" , 0 , argc , argv ) ); 
  if ((argc > 1 ) && ! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_namespace_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("namespace-undefine-variable!" , "namespace" , 1 , argc , argv ) ); 
  if (argc > 1 )
    env = (Scheme_Env * ) argv [1 ] ; 
  else env = FUNCCALL(SETUP_XfOrM727(_), scheme_get_env (((void * ) 0 ) ) ); 
  if (FUNCCALL(SETUP_XfOrM727(_), scheme_lookup_global (argv [0 ] , env ) )) {
#   define XfOrM729_COUNT (0+XfOrM727_COUNT)
#   define SETUP_XfOrM729(x) SETUP_XfOrM727(x)
    bucket = FUNCCALL(SETUP_XfOrM729(_), scheme_global_bucket (argv [0 ] , env ) ); 
    bucket -> val = ((void * ) 0 ) ; 
  }
  else {
#   define XfOrM728_COUNT (0+XfOrM727_COUNT)
#   define SETUP_XfOrM728(x) SETUP_XfOrM727(x)
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT_VARIABLE , argv [0 ] , "namespace-undefine-variable!: %S is not defined" , argv [0 ] ) ); 
  }
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * namespace_mapped_symbols (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * l ; 
  Scheme_Env * env ; 
  Scheme_Hash_Table * mapped ; 
  Scheme_Bucket_Table * ht ; 
  Scheme_Bucket * * bs ; 
  int i , j ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(bs, 1), PUSH(mapped, 2), PUSH(l, 3), PUSH(ht, 4)));
# define XfOrM730_COUNT (5)
# define SETUP_XfOrM730(x) SETUP(XfOrM730_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  l = NULLED_OUT ; 
  env = NULLED_OUT ; 
  mapped = NULLED_OUT ; 
  ht = NULLED_OUT ; 
  bs = NULLED_OUT ; 
  if ((argc > 0 ) && ! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_namespace_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("namespace-mapped-symbols" , "namespace" , 0 , argc , argv ) ); 
  if (argc )
    env = (Scheme_Env * ) argv [0 ] ; 
  else env = FUNCCALL(SETUP_XfOrM730(_), scheme_get_env (((void * ) 0 ) ) ); 
  mapped = FUNCCALL(SETUP_XfOrM730(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  for (j = 0 ; j < 2 ; j ++ ) {
#   define XfOrM738_COUNT (0+XfOrM730_COUNT)
#   define SETUP_XfOrM738(x) SETUP_XfOrM730(x)
    if (j )
      ht = env -> syntax ; 
    else ht = env -> toplevel ; 
    bs = ht -> buckets ; 
    for (i = ht -> size ; i -- ; ) {
      Scheme_Bucket * b = bs [i ] ; 
      BLOCK_SETUP((PUSH(b, 0+XfOrM738_COUNT)));
#     define XfOrM741_COUNT (1+XfOrM738_COUNT)
#     define SETUP_XfOrM741(x) SETUP(XfOrM741_COUNT)
      if (b && b -> val ) {
#       define XfOrM742_COUNT (0+XfOrM741_COUNT)
#       define SETUP_XfOrM742(x) SETUP_XfOrM741(x)
        FUNCCALL(SETUP_XfOrM742(_), scheme_hash_set (mapped , (Scheme_Object * ) b -> key , scheme_true ) ); 
      }
    }
  }
  if (env -> rename )
    FUNCCALL(SETUP_XfOrM730(_), scheme_list_module_rename (env -> rename , mapped ) ); 
  l = scheme_null ; 
  for (i = mapped -> size ; i -- ; ) {
#   define XfOrM732_COUNT (0+XfOrM730_COUNT)
#   define SETUP_XfOrM732(x) SETUP_XfOrM730(x)
    if (mapped -> vals [i ] )
      l = FUNCCALL(SETUP_XfOrM732(_), scheme_make_pair (mapped -> keys [i ] , l ) ); 
  }
  RET_VALUE_START (l ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * namespace_module_registry (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_namespace_type ) ) )
    scheme_wrong_type ("namespace-module-registry" , "namespace" , 0 , argc , argv ) ; 
  return (Scheme_Object * ) ((Scheme_Env * ) argv [0 ] ) -> module_registry ; 
}
static Scheme_Object * now_transforming (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (scheme_current_thread -> current_local_env ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * local_exp_time_value (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * v , * sym ; 
  Scheme_Env * menv ; 
  Scheme_Comp_Env * env ; 
  int renamed = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(env, 1), PUSH(argv, 2), PUSH(sym, 3), PUSH(menv, 4)));
# define XfOrM745_COUNT (5)
# define SETUP_XfOrM745(x) SETUP(XfOrM745_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  v = NULLED_OUT ; 
  sym = NULLED_OUT ; 
  menv = NULLED_OUT ; 
  env = NULLED_OUT ; 
  env = scheme_current_thread -> current_local_env ; 
  if (! env )
    FUNCCALL(SETUP_XfOrM745(_), scheme_raise_exn (MZEXN_FAIL_CONTRACT , "syntax-local-value: not currently transforming" ) ); 
  sym = argv [0 ] ; 
  if (! (((Scheme_Type ) (((((long ) (sym ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (sym ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) sym ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) sym ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) )
    FUNCCALL(SETUP_XfOrM745(_), scheme_wrong_type ("syntax-local-value" , "syntax identifier" , 0 , argc , argv ) ); 
  if (argc > 1 ) {
#   define XfOrM756_COUNT (0+XfOrM745_COUNT)
#   define SETUP_XfOrM756(x) SETUP_XfOrM745(x)
    FUNCCALL(SETUP_XfOrM756(_), scheme_check_proc_arity2 ("syntax-local-value" , 0 , 1 , argc , argv , 1 ) ); 
    if ((argc > 2 ) && (! (((argv [2 ] ) ) == (scheme_false ) ) ) ) {
      Scheme_Comp_Env * stx_env ; 
      BLOCK_SETUP((PUSH(stx_env, 0+XfOrM756_COUNT)));
#     define XfOrM757_COUNT (1+XfOrM756_COUNT)
#     define SETUP_XfOrM757(x) SETUP(XfOrM757_COUNT)
      stx_env = NULLED_OUT ; 
      if (! ((Scheme_Type ) (scheme_intdef_context_type ) == (Scheme_Type ) (((((long ) (argv [2 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [2 ] ) ) -> type ) ) ) )
        FUNCCALL(SETUP_XfOrM757(_), scheme_wrong_type ("syntax-local-value" , "internal-definition context or #f" , 2 , argc , argv ) ); 
      stx_env = (Scheme_Comp_Env * ) (((Scheme_Simple_Object * ) (argv [2 ] ) ) -> u . two_ptr_val . ptr1 ) ; 
      if (! FUNCCALL(SETUP_XfOrM757(_), scheme_is_sub_env (stx_env , env ) )) {
#       define XfOrM758_COUNT (0+XfOrM757_COUNT)
#       define SETUP_XfOrM758(x) SETUP_XfOrM757(x)
        FUNCCALL(SETUP_XfOrM758(_), scheme_raise_exn (MZEXN_FAIL_CONTRACT , "syntax-local-value: transforming context does " "not match given internal-definition context" ) ); 
      }
      env = stx_env ; 
    }
  }
  if (scheme_current_thread -> current_local_mark )
    sym = FUNCCALL(SETUP_XfOrM745(_), scheme_add_remove_mark (sym , scheme_current_thread -> current_local_mark ) ); 
  menv = ((void * ) 0 ) ; 
  sym = FUNCCALL(SETUP_XfOrM745(_), scheme_stx_activate_certs (sym ) ); 
  while (1 ) {
#   define XfOrM751_COUNT (0+XfOrM745_COUNT)
#   define SETUP_XfOrM751(x) SETUP_XfOrM745(x)
    v = FUNCCALL(SETUP_XfOrM751(_), scheme_lookup_binding (sym , env , (512 + 1024 + 2 + 8 + 256 + 1 ) , scheme_current_thread -> current_local_certs , scheme_current_thread -> current_local_modidx , & menv , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
    if (v && ((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_variable_type ) ) )
      v = (Scheme_Object * ) (((Scheme_Bucket * ) (v ) ) ) -> val ; 
    if (! v || ((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) != (Scheme_Type ) (scheme_macro_type ) ) ) {
#     define XfOrM755_COUNT (0+XfOrM751_COUNT)
#     define SETUP_XfOrM755(x) SETUP_XfOrM751(x)
      if ((argc > 1 ) && (! (((argv [1 ] ) ) == (scheme_false ) ) ) )
        RET_VALUE_START (FUNCCALL(SETUP_XfOrM755(_), scheme_tail_apply (argv [1 ] , 0 , ((void * ) 0 ) ) )) RET_VALUE_END ; 
      else FUNCCALL(SETUP_XfOrM755(_), scheme_arg_mismatch ("syntax-local-value" , (renamed ? "not defined as syntax (after renaming): " : "not defined as syntax: " ) , argv [0 ] ) ); 
    }
    v = (((Scheme_Small_Object * ) (v ) ) -> u . ptr_val ) ; 
    if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_id_macro_type ) ) ) {
#     define XfOrM752_COUNT (0+XfOrM751_COUNT)
#     define SETUP_XfOrM752(x) SETUP_XfOrM751(x)
      sym = (((Scheme_Simple_Object * ) (v ) ) -> u . two_ptr_val . ptr1 ) ; 
      sym = FUNCCALL(SETUP_XfOrM752(_), scheme_stx_cert (sym , scheme_false , menv , sym , ((void * ) 0 ) , 1 ) ); 
      renamed = 1 ; 
      menv = ((void * ) 0 ) ; 
      {
#       define XfOrM753_COUNT (0+XfOrM752_COUNT)
#       define SETUP_XfOrM753(x) SETUP_XfOrM752(x)
        if ((scheme_fuel_counter ) <= 0 ) {
#         define XfOrM754_COUNT (0+XfOrM753_COUNT)
#         define SETUP_XfOrM754(x) SETUP_XfOrM753(x)
          FUNCCALL(SETUP_XfOrM754(_), scheme_out_of_fuel () ); 
        }
      }
      ; 
    }
    else RET_VALUE_START (v ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * local_exp_time_name (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * sym ; 
  sym = scheme_current_thread -> current_local_name ; 
  if (! sym )
    scheme_raise_exn (MZEXN_FAIL_CONTRACT , "syntax-local-name: not currently transforming" ) ; 
  return sym ; 
}
static Scheme_Object * local_context (int argc , Scheme_Object * argv [] ) {
  Scheme_Comp_Env * env ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(env, 0)));
# define XfOrM760_COUNT (1)
# define SETUP_XfOrM760(x) SETUP(XfOrM760_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  env = NULLED_OUT ; 
  env = scheme_current_thread -> current_local_env ; 
  if (! env )
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "syntax-local-context: not currently transforming" ) ); 
  if (env -> flags & 16 ) {
#   define XfOrM761_COUNT (0+XfOrM760_COUNT)
#   define SETUP_XfOrM761(x) SETUP_XfOrM760(x)
    if (! env -> intdef_name ) {
      Scheme_Object * sym , * pr , * prev = ((void * ) 0 ) ; 
      Scheme_Comp_Env * lenv = env ; 
      char buf [22 ] ; 
      BLOCK_SETUP((PUSH(pr, 0+XfOrM761_COUNT), PUSH(lenv, 1+XfOrM761_COUNT), PUSH(prev, 2+XfOrM761_COUNT), PUSH(sym, 3+XfOrM761_COUNT)));
#     define XfOrM762_COUNT (4+XfOrM761_COUNT)
#     define SETUP_XfOrM762(x) SETUP(XfOrM762_COUNT)
      sym = NULLED_OUT ; 
      pr = NULLED_OUT ; 
      while (1 ) {
#       define XfOrM768_COUNT (0+XfOrM762_COUNT)
#       define SETUP_XfOrM768(x) SETUP_XfOrM762(x)
        if (env -> flags & 256 )
          lenv = lenv -> next ; 
        else {
#         define XfOrM769_COUNT (0+XfOrM768_COUNT)
#         define SETUP_XfOrM769(x) SETUP_XfOrM768(x)
          (sprintf (buf , "internal-define%d" , intdef_counter ++ ) ) ; 
          sym = FUNCCALL(SETUP_XfOrM769(_), scheme_make_symbol (buf ) ); 
          pr = FUNCCALL_AGAIN(scheme_make_immutable_pair (sym , scheme_null ) ); 
          lenv -> intdef_name = pr ; 
          if (prev )
            (((Scheme_Simple_Object * ) (prev ) ) -> u . pair_val . cdr ) = pr ; 
          if (lenv -> next -> flags & 16 ) {
            if (lenv -> next -> intdef_name ) {
              (((Scheme_Simple_Object * ) (pr ) ) -> u . pair_val . cdr ) = lenv -> next -> intdef_name ; 
              break ; 
            }
            else {
              prev = pr ; 
              lenv = lenv -> next ; 
            }
          }
          else break ; 
        }
      }
    }
    RET_VALUE_START (env -> intdef_name ) RET_VALUE_END ; 
  }
  else if (FUNCCALL(SETUP_XfOrM760(_), scheme_is_module_env (env ) ))
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_intern_symbol ("module" ) )) RET_VALUE_EMPTY_END ; 
  else if (FUNCCALL(SETUP_XfOrM760(_), scheme_is_module_begin_env (env ) ))
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_intern_symbol ("module-begin" ) )) RET_VALUE_EMPTY_END ; 
  else if (FUNCCALL_EMPTY(scheme_is_toplevel (env ) ))
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_intern_symbol ("top-level" ) )) RET_VALUE_EMPTY_END ; 
  else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_intern_symbol ("expression" ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * local_make_intdef_context (int argc , Scheme_Object * argv [] ) {
  Scheme_Comp_Env * env ; 
  Scheme_Object * c , * rib ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(c, 0), PUSH(env, 1), PUSH(rib, 2)));
# define XfOrM773_COUNT (3)
# define SETUP_XfOrM773(x) SETUP(XfOrM773_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  env = NULLED_OUT ; 
  c = NULLED_OUT ; 
  rib = NULLED_OUT ; 
  env = scheme_current_thread -> current_local_env ; 
  if (! env )
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "syntax-local-make-definition-context: not currently transforming" ) ); 
  rib = FUNCCALL(SETUP_XfOrM773(_), scheme_make_rename_rib () ); 
  c = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM773(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  c -> type = scheme_intdef_context_type ; 
  (((Scheme_Simple_Object * ) (c ) ) -> u . two_ptr_val . ptr1 ) = env ; 
  (((Scheme_Simple_Object * ) (c ) ) -> u . two_ptr_val . ptr2 ) = rib ; 
  RET_VALUE_START (c ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * local_introduce (int argc , Scheme_Object * argv [] ) {
  Scheme_Comp_Env * env ; 
  Scheme_Object * s ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(s, 0)));
# define XfOrM774_COUNT (1)
# define SETUP_XfOrM774(x) SETUP(XfOrM774_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  env = NULLED_OUT ; 
  s = NULLED_OUT ; 
  env = scheme_current_thread -> current_local_env ; 
  if (! env )
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "syntax-local-introduce: not currently transforming" ) ); 
  s = argv [0 ] ; 
  if (! ((Scheme_Type ) (((((long ) (s ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (s ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("syntax-local-introduce" , "syntax" , 0 , argc , argv ) ); 
  if (scheme_current_thread -> current_local_mark )
    s = FUNCCALL(SETUP_XfOrM774(_), scheme_add_remove_mark (s , scheme_current_thread -> current_local_mark ) ); 
  RET_VALUE_START (s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * local_module_introduce (int argc , Scheme_Object * argv [] ) {
  Scheme_Comp_Env * env ; 
  Scheme_Object * s , * v ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(v, 1), PUSH(s, 2)));
# define XfOrM775_COUNT (3)
# define SETUP_XfOrM775(x) SETUP(XfOrM775_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  env = NULLED_OUT ; 
  s = NULLED_OUT ; 
  v = NULLED_OUT ; 
  env = scheme_current_thread -> current_local_env ; 
  if (! env )
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "syntax-local-module-introduce: not currently transforming" ) ); 
  s = argv [0 ] ; 
  if (! ((Scheme_Type ) (((((long ) (s ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (s ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("syntax-local-module-introduce" , "syntax" , 0 , argc , argv ) ); 
  v = FUNCCALL(SETUP_XfOrM775(_), scheme_stx_source_module (s , 0 ) ); 
  if ((((v ) ) == (scheme_false ) ) ) {
#   define XfOrM776_COUNT (0+XfOrM775_COUNT)
#   define SETUP_XfOrM776(x) SETUP_XfOrM775(x)
    if (env -> genv -> module ) {
#     define XfOrM779_COUNT (0+XfOrM776_COUNT)
#     define SETUP_XfOrM779(x) SETUP_XfOrM776(x)
      if (env -> genv -> module -> rn_stx && ! ((scheme_true ) == (env -> genv -> module -> rn_stx ) ) ) {
#       define XfOrM782_COUNT (0+XfOrM779_COUNT)
#       define SETUP_XfOrM782(x) SETUP_XfOrM779(x)
        v = FUNCCALL(SETUP_XfOrM782(_), scheme_stx_to_rename (env -> genv -> module -> rn_stx ) ); 
        s = FUNCCALL(SETUP_XfOrM782(_), scheme_add_rename (s , v ) ); 
      }
      if (env -> genv -> module -> et_rn_stx && ! ((scheme_true ) == (env -> genv -> module -> et_rn_stx ) ) ) {
#       define XfOrM781_COUNT (0+XfOrM779_COUNT)
#       define SETUP_XfOrM781(x) SETUP_XfOrM779(x)
        v = FUNCCALL(SETUP_XfOrM781(_), scheme_stx_to_rename (env -> genv -> module -> et_rn_stx ) ); 
        s = FUNCCALL(SETUP_XfOrM781(_), scheme_add_rename (s , v ) ); 
      }
      if (env -> genv -> module -> dt_rn_stx && ! ((scheme_true ) == (env -> genv -> module -> dt_rn_stx ) ) ) {
#       define XfOrM780_COUNT (0+XfOrM779_COUNT)
#       define SETUP_XfOrM780(x) SETUP_XfOrM779(x)
        v = FUNCCALL(SETUP_XfOrM780(_), scheme_stx_to_rename (env -> genv -> module -> dt_rn_stx ) ); 
        s = FUNCCALL(SETUP_XfOrM780(_), scheme_add_rename (s , v ) ); 
      }
    }
    else {
#     define XfOrM777_COUNT (0+XfOrM776_COUNT)
#     define SETUP_XfOrM777(x) SETUP_XfOrM776(x)
      if (env -> genv -> rename )
        s = FUNCCALL(SETUP_XfOrM777(_), scheme_add_rename (s , env -> genv -> rename ) ); 
      if (env -> genv -> et_rename )
        s = FUNCCALL(SETUP_XfOrM777(_), scheme_add_rename (s , env -> genv -> et_rename ) ); 
      if (env -> genv -> dt_rename ) {
#       define XfOrM778_COUNT (0+XfOrM777_COUNT)
#       define SETUP_XfOrM778(x) SETUP_XfOrM777(x)
        s = FUNCCALL(SETUP_XfOrM778(_), scheme_add_rename (s , env -> genv -> dt_rename ) ); 
      }
    }
  }
  RET_VALUE_START (s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * local_get_shadower (int argc , Scheme_Object * argv [] ) {
  Scheme_Comp_Env * env , * frame ; 
  Scheme_Object * sym , * esym , * sym_marks = ((void * ) 0 ) , * orig_sym , * uid = ((void * ) 0 ) , * env_marks ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(11);
  BLOCK_SETUP_TOP((PUSH(esym, 0), PUSH(frame, 1), PUSH(argv, 2), PUSH(env, 3), PUSH(orig_sym, 4), PUSH(env_marks, 5), PUSH(uid, 6), PUSH(sym_marks, 7), PUSH(sym, 8)));
# define XfOrM783_COUNT (9)
# define SETUP_XfOrM783(x) SETUP(XfOrM783_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  env = NULLED_OUT ; 
  frame = NULLED_OUT ; 
  sym = NULLED_OUT ; 
  esym = NULLED_OUT ; 
  orig_sym = NULLED_OUT ; 
  env_marks = NULLED_OUT ; 
  env = scheme_current_thread -> current_local_env ; 
  if (! env )
    FUNCCALL(SETUP_XfOrM783(_), scheme_raise_exn (MZEXN_FAIL_CONTRACT , "syntax-local-get-shadower: not currently transforming" ) ); 
  sym = argv [0 ] ; 
  orig_sym = sym ; 
  if (! (((Scheme_Type ) (((((long ) (sym ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (sym ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) sym ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) sym ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) )
    FUNCCALL(SETUP_XfOrM783(_), scheme_wrong_type ("syntax-local-get-shadower" , "syntax identifier" , 0 , argc , argv ) ); 
  sym_marks = FUNCCALL(SETUP_XfOrM783(_), scheme_stx_extract_marks (sym ) ); 
  for (frame = env ; frame -> next != ((void * ) 0 ) ; frame = frame -> next ) {
    int i ; 
#   define XfOrM805_COUNT (0+XfOrM783_COUNT)
#   define SETUP_XfOrM805(x) SETUP_XfOrM783(x)
    for (i = frame -> num_bindings ; i -- ; ) {
#     define XfOrM820_COUNT (0+XfOrM805_COUNT)
#     define SETUP_XfOrM820(x) SETUP_XfOrM805(x)
      if (frame -> values [i ] ) {
#       define XfOrM821_COUNT (0+XfOrM820_COUNT)
#       define SETUP_XfOrM821(x) SETUP_XfOrM820(x)
        if (((((Scheme_Stx * ) sym ) -> val ) == (((Scheme_Stx * ) frame -> values [i ] ) -> val ) ) ) {
#         define XfOrM822_COUNT (0+XfOrM821_COUNT)
#         define SETUP_XfOrM822(x) SETUP_XfOrM821(x)
          esym = frame -> values [i ] ; 
          env_marks = FUNCCALL(SETUP_XfOrM822(_), scheme_stx_extract_marks (esym ) ); 
          if (FUNCCALL(SETUP_XfOrM822(_), scheme_equal (env_marks , sym_marks ) )) {
            sym = esym ; 
            if (frame -> uids )
              uid = frame -> uids [i ] ; 
            else uid = frame -> uid ; 
            break ; 
          }
        }
      }
    }
    if (uid )
      break ; 
    for (i = (& ((Scheme_Full_Comp_Env * ) frame ) -> data ) -> num_const ; i -- ; ) {
#     define XfOrM811_COUNT (0+XfOrM805_COUNT)
#     define SETUP_XfOrM811(x) SETUP_XfOrM805(x)
      if (! (frame -> flags & 64 ) ) {
#       define XfOrM812_COUNT (0+XfOrM811_COUNT)
#       define SETUP_XfOrM812(x) SETUP_XfOrM811(x)
        if (((((Scheme_Stx * ) sym ) -> val ) == (((Scheme_Stx * ) (& ((Scheme_Full_Comp_Env * ) frame ) -> data ) -> const_names [i ] ) -> val ) ) ) {
#         define XfOrM813_COUNT (0+XfOrM812_COUNT)
#         define SETUP_XfOrM813(x) SETUP_XfOrM812(x)
          esym = (& ((Scheme_Full_Comp_Env * ) frame ) -> data ) -> const_names [i ] ; 
          env_marks = FUNCCALL(SETUP_XfOrM813(_), scheme_stx_extract_marks (esym ) ); 
          if (FUNCCALL(SETUP_XfOrM813(_), scheme_equal (env_marks , sym_marks ) )) {
            sym = esym ; 
            if ((& ((Scheme_Full_Comp_Env * ) frame ) -> data ) -> const_uids ) {
              uid = (& ((Scheme_Full_Comp_Env * ) frame ) -> data ) -> const_uids [i ] ; 
            }
            else uid = frame -> uid ; 
            break ; 
          }
        }
      }
    }
    if (uid )
      break ; 
  }
  if (! uid ) {
#   define XfOrM785_COUNT (0+XfOrM783_COUNT)
#   define SETUP_XfOrM785(x) SETUP_XfOrM783(x)
    sym = FUNCCALL(SETUP_XfOrM785(_), scheme_stx_strip_module_context (sym ) ); 
    sym = FUNCCALL(SETUP_XfOrM785(_), local_module_introduce (1 , & sym ) ); 
    RET_VALUE_START (sym ) RET_VALUE_END ; 
  }
  {
    Scheme_Object * rn , * result ; 
    BLOCK_SETUP((PUSH(rn, 0+XfOrM783_COUNT), PUSH(result, 1+XfOrM783_COUNT)));
#   define XfOrM784_COUNT (2+XfOrM783_COUNT)
#   define SETUP_XfOrM784(x) SETUP(XfOrM784_COUNT)
    rn = NULLED_OUT ; 
    result = NULLED_OUT ; 
    result = FUNCCALL(SETUP_XfOrM784(_), scheme_datum_to_syntax (((Scheme_Stx * ) sym ) -> val , orig_sym , sym , 0 , 0 ) ); 
    ((Scheme_Stx * ) result ) -> props = ((Scheme_Stx * ) orig_sym ) -> props ; 
    rn = FUNCCALL(SETUP_XfOrM784(_), scheme_make_rename (uid , 1 ) ); 
    FUNCCALL_AGAIN(scheme_set_rename (rn , 0 , result ) ); 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM784(_), scheme_add_rename (result , rn ) )) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * introducer_proc (void * mark , int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * s ; 
  s = argv [0 ] ; 
  if (! ((Scheme_Type ) (((((long ) (s ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (s ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    scheme_wrong_type ("syntax-introducer" , "syntax" , 0 , argc , argv ) ; 
  return scheme_add_remove_mark (s , (Scheme_Object * ) mark ) ; 
}
static Scheme_Object * make_introducer (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * mark ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(mark, 0)));
# define XfOrM825_COUNT (1)
# define SETUP_XfOrM825(x) SETUP(XfOrM825_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  mark = NULLED_OUT ; 
  mark = FUNCCALL(SETUP_XfOrM825(_), scheme_new_mark () ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_closed_prim_w_arity (introducer_proc , mark , "syntax-introducer" , 1 , 1 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * certifier (void * _data , int argc , Scheme_Object * * argv ) {
  Scheme_Object * s , * * cert_data = (Scheme_Object * * ) _data ; 
  Scheme_Object * mark = scheme_false ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(cert_data, 1), PUSH(s, 2), PUSH(mark, 3)));
# define XfOrM826_COUNT (4)
# define SETUP_XfOrM826(x) SETUP(XfOrM826_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  s = argv [0 ] ; 
  if (! ((Scheme_Type ) (((((long ) (s ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (s ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("certifier" , "syntax" , 0 , argc , argv ) ); 
  if (argc > 2 ) {
#   define XfOrM829_COUNT (0+XfOrM826_COUNT)
#   define SETUP_XfOrM829(x) SETUP_XfOrM826(x)
    if ((! (((argv [2 ] ) ) == (scheme_false ) ) ) ) {
#     define XfOrM830_COUNT (0+XfOrM829_COUNT)
#     define SETUP_XfOrM830(x) SETUP_XfOrM829(x)
      if (((Scheme_Type ) (((((long ) (argv [2 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [2 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_closed_prim_type ) ) && (((Scheme_Closed_Primitive_Proc * ) argv [2 ] ) -> prim_val == introducer_proc ) )
        mark = (Scheme_Object * ) ((Scheme_Closed_Primitive_Proc * ) argv [2 ] ) -> data ; 
      else {
#       define XfOrM831_COUNT (0+XfOrM830_COUNT)
#       define SETUP_XfOrM831(x) SETUP_XfOrM830(x)
        FUNCCALL_EMPTY(scheme_wrong_type ("certifier" , "procedure from make-syntax-introducer or #f" , 2 , argc , argv ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
    }
  }
  if (cert_data [0 ] || cert_data [1 ] || cert_data [2 ] ) {
    int as_active = (! (((cert_data [3 ] ) ) == (scheme_false ) ) ) ; 
#   define XfOrM827_COUNT (0+XfOrM826_COUNT)
#   define SETUP_XfOrM827(x) SETUP_XfOrM826(x)
    s = FUNCCALL(SETUP_XfOrM827(_), scheme_stx_cert (s , mark , (Scheme_Env * ) (cert_data [1 ] ? cert_data [1 ] : cert_data [2 ] ) , cert_data [0 ] , ((argc > 1 ) && (! (((argv [1 ] ) ) == (scheme_false ) ) ) ) ? argv [1 ] : ((void * ) 0 ) , as_active ) ); 
    if (cert_data [1 ] && cert_data [2 ] && ! ((cert_data [1 ] ) == (cert_data [2 ] ) ) ) {
#     define XfOrM828_COUNT (0+XfOrM827_COUNT)
#     define SETUP_XfOrM828(x) SETUP_XfOrM827(x)
      s = FUNCCALL(SETUP_XfOrM828(_), scheme_stx_cert (s , mark , (Scheme_Env * ) cert_data [2 ] , ((void * ) 0 ) , ((argc > 1 ) && (! (((argv [1 ] ) ) == (scheme_false ) ) ) ) ? argv [1 ] : ((void * ) 0 ) , as_active ) ); 
    }
  }
  RET_VALUE_START (s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * local_certify (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * * cert_data ; 
  Scheme_Env * menv ; 
  int active = 0 ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(cert_data, 0), PUSH(menv, 1)));
# define XfOrM832_COUNT (2)
# define SETUP_XfOrM832(x) SETUP(XfOrM832_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  cert_data = NULLED_OUT ; 
  menv = NULLED_OUT ; 
  if (! scheme_current_thread -> current_local_env )
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "syntax-local-certifier: not currently transforming" ) ); 
  menv = scheme_current_thread -> current_local_menv ; 
  if (argc )
    active = (! (((argv [0 ] ) ) == (scheme_false ) ) ) ; 
  cert_data = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM832(_), GC_malloc (sizeof (Scheme_Object * ) * (4 ) ) )) ; 
  cert_data [0 ] = scheme_current_thread -> current_local_certs ; 
  cert_data [1 ] = (Scheme_Object * ) ((menv && menv -> module ) ? menv : ((void * ) 0 ) ) ; 
  menv = scheme_current_thread -> current_local_env -> genv ; 
  cert_data [2 ] = (Scheme_Object * ) ((menv && menv -> module ) ? menv : ((void * ) 0 ) ) ; 
  cert_data [3 ] = (active ? scheme_true : scheme_false ) ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_closed_prim_w_arity (certifier , cert_data , "certifier" , 1 , 3 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * local_lift_expr (int argc , Scheme_Object * argv [] ) {
  Scheme_Env * menv ; 
  Scheme_Comp_Env * env , * orig_env ; 
  Scheme_Object * id , * local_mark , * expr , * data , * vec , * id_sym ; 
  Scheme_Lift_Capture_Proc cp ; 
  Scheme_Object * orig_expr ; 
  Scheme_Object * __funcarg39 = NULLED_OUT ; 
  Scheme_Object * __funcarg38 = NULLED_OUT ; 
  Scheme_Object * __funcarg37 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(11);
  BLOCK_SETUP_TOP((PUSH(vec, 0), PUSH(data, 1), PUSH(orig_expr, 2), PUSH(menv, 3), PUSH(env, 4), PUSH(id, 5), PUSH(__funcarg37, 6), PUSH(id_sym, 7), PUSH(expr, 8), PUSH(orig_env, 9), PUSH(local_mark, 10)));
# define XfOrM833_COUNT (11)
# define SETUP_XfOrM833(x) SETUP(XfOrM833_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  menv = NULLED_OUT ; 
  env = NULLED_OUT ; 
  orig_env = NULLED_OUT ; 
  id = NULLED_OUT ; 
  local_mark = NULLED_OUT ; 
  expr = NULLED_OUT ; 
  data = NULLED_OUT ; 
  vec = NULLED_OUT ; 
  id_sym = NULLED_OUT ; 
  orig_expr = NULLED_OUT ; 
  expr = argv [0 ] ; 
  if (! ((Scheme_Type ) (((((long ) (expr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (expr ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    FUNCCALL(SETUP_XfOrM833(_), scheme_wrong_type ("syntax-local-lift-expression" , "syntax" , 0 , argc , argv ) ); 
  env = orig_env = scheme_current_thread -> current_local_env ; 
  local_mark = scheme_current_thread -> current_local_mark ; 
  if (! env )
    FUNCCALL(SETUP_XfOrM833(_), scheme_raise_exn (MZEXN_FAIL_CONTRACT , "syntax-local-lift-expression: not currently transforming" ) ); 
  while (env && ! (& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> lifts ) {
    env = env -> next ; 
  }
  if (! env )
    FUNCCALL(SETUP_XfOrM833(_), scheme_raise_exn (MZEXN_FAIL_CONTRACT , "syntax-local-lift-expression: no lift target" ) ); 
  expr = FUNCCALL(SETUP_XfOrM833(_), scheme_add_remove_mark (expr , local_mark ) ); 
  id_sym = FUNCCALL_AGAIN(scheme_intern_exact_parallel_symbol ("lifted" , 6 ) ); 
  id = FUNCCALL_AGAIN(scheme_datum_to_syntax (id_sym , scheme_false , scheme_false , 0 , 0 ) ); 
  id = (__funcarg39 = FUNCCALL(SETUP_XfOrM833(_), scheme_new_mark () ), FUNCCALL_AGAIN(scheme_add_remove_mark (id , __funcarg39 ) )) ; 
  vec = (& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> lifts ; 
  cp = * (Scheme_Lift_Capture_Proc * ) (((Scheme_Vector * ) (vec ) ) -> els ) [1 ] ; 
  data = (((Scheme_Vector * ) (vec ) ) -> els ) [2 ] ; 
  menv = scheme_current_thread -> current_local_menv ; 
  expr = FUNCCALL(SETUP_XfOrM833(_), scheme_stx_cert (expr , scheme_false , (menv && menv -> module ) ? menv : ((void * ) 0 ) , scheme_current_thread -> current_local_certs , ((void * ) 0 ) , 1 ) ); 
  expr = FUNCCALL_AGAIN(scheme_stx_activate_certs (expr ) ); 
  orig_expr = expr ; 
  expr = FUNCCALL(SETUP_XfOrM833(_), cp (data , & id , expr , orig_env ) ); 
  expr = FUNCCALL_AGAIN(scheme_make_pair (expr , (((Scheme_Vector * ) (vec ) ) -> els ) [0 ] ) ); 
  (((Scheme_Vector * ) (vec ) ) -> els ) [0 ] = expr ; 
  if (FUNCCALL(SETUP_XfOrM833(_), scheme_get_expand_observe () )) {
#   define XfOrM835_COUNT (0+XfOrM833_COUNT)
#   define SETUP_XfOrM835(x) SETUP_XfOrM833(x)
    (__funcarg37 = FUNCCALL(SETUP_XfOrM835(_), scheme_get_expand_observe () ), __funcarg38 = FUNCCALL(SETUP_XfOrM835(_), scheme_make_pair (id , orig_expr ) ), FUNCCALL_AGAIN(scheme_call_expand_observe (__funcarg37 , 129 , __funcarg38 ) )) ; 
  }
  else {
  }
  ; 
  id = FUNCCALL(SETUP_XfOrM833(_), scheme_add_remove_mark (id , local_mark ) ); 
  RET_VALUE_START (id ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * local_lift_context (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Comp_Env * env ; 
  env = scheme_current_thread -> current_local_env ; 
  if (! env )
    scheme_raise_exn (MZEXN_FAIL_CONTRACT , "syntax-local-lift-context: not currently transforming" ) ; 
  while (env && ! (& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> lifts ) {
    env = env -> next ; 
  }
  if (! env )
    return scheme_false ; 
  return (((Scheme_Vector * ) ((& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> lifts ) ) -> els ) [4 ] ; 
}
static Scheme_Object * local_lift_end_statement (int argc , Scheme_Object * argv [] ) {
  Scheme_Comp_Env * env ; 
  Scheme_Object * local_mark , * expr , * pr ; 
  Scheme_Object * orig_expr ; 
  Scheme_Object * __funcarg40 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(expr, 1), PUSH(orig_expr, 2), PUSH(pr, 3)));
# define XfOrM841_COUNT (4)
# define SETUP_XfOrM841(x) SETUP(XfOrM841_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  env = NULLED_OUT ; 
  local_mark = NULLED_OUT ; 
  expr = NULLED_OUT ; 
  pr = NULLED_OUT ; 
  orig_expr = NULLED_OUT ; 
  expr = argv [0 ] ; 
  if (! ((Scheme_Type ) (((((long ) (expr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (expr ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("syntax-local-lift-module-end-declaration" , "syntax" , 0 , argc , argv ) ); 
  env = scheme_current_thread -> current_local_env ; 
  local_mark = scheme_current_thread -> current_local_mark ; 
  if (! env )
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "syntax-local-lift-module-end-declaration: not currently transforming" ) ); 
  while (env ) {
    if (((& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> lifts ) && (! ((((((Scheme_Vector * ) ((& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> lifts ) ) -> els ) [3 ] ) ) == (scheme_false ) ) ) )
      break ; 
    env = env -> next ; 
  }
  if (! env )
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "syntax-local-lift-module-end-declaration: not currently transforming" " a run-time expression in a module declaration" ) ); 
  expr = FUNCCALL(SETUP_XfOrM841(_), scheme_add_remove_mark (expr , local_mark ) ); 
  orig_expr = expr ; 
  pr = FUNCCALL(SETUP_XfOrM841(_), scheme_make_pair (expr , (((Scheme_Vector * ) ((& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> lifts ) ) -> els ) [3 ] ) ); 
  (((Scheme_Vector * ) ((& ((Scheme_Full_Comp_Env * ) env ) -> data ) -> lifts ) ) -> els ) [3 ] = pr ; 
  if (FUNCCALL(SETUP_XfOrM841(_), scheme_get_expand_observe () )) {
#   define XfOrM843_COUNT (0+XfOrM841_COUNT)
#   define SETUP_XfOrM843(x) SETUP_XfOrM841(x)
    (__funcarg40 = FUNCCALL(SETUP_XfOrM843(_), scheme_get_expand_observe () ), FUNCCALL_AGAIN(scheme_call_expand_observe (__funcarg40 , 134 , orig_expr ) )) ; 
  }
  else {
  }
  ; 
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_set_transformer (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * v ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(argv, 1)));
# define XfOrM846_COUNT (2)
# define SETUP_XfOrM846(x) SETUP(XfOrM846_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM846(_), scheme_check_proc_arity ("make-set!-transformer" , 1 , 0 , argc , argv ) ); 
  v = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM846(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  v -> type = scheme_set_macro_type ; 
  (((Scheme_Small_Object * ) (v ) ) -> u . ptr_val ) = argv [0 ] ; 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * set_transformer_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_set_macro_type ) ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * set_transformer_proc (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_set_macro_type ) ) ) )
    scheme_wrong_type ("set!-transformer-procedure" , "set!-transformer" , 1 , argc , argv ) ; 
  return (((Scheme_Small_Object * ) (argv [0 ] ) ) -> u . ptr_val ) ; 
}
static Scheme_Object * make_rename_transformer (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * v ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(argv, 1)));
# define XfOrM849_COUNT (2)
# define SETUP_XfOrM849(x) SETUP(XfOrM849_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) || ! ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) argv [0 ] ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) argv [0 ] ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("make-rename-transformer" , "syntax identifier" , 0 , argc , argv ) ); 
  v = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM849(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  v -> type = scheme_id_macro_type ; 
  (((Scheme_Small_Object * ) (v ) ) -> u . ptr_val ) = argv [0 ] ; 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * rename_transformer_target (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_id_macro_type ) ) )
    scheme_wrong_type ("rename-transformer-target" , "rename transformer" , 0 , argc , argv ) ; 
  return (((Scheme_Small_Object * ) (argv [0 ] ) ) -> u . ptr_val ) ; 
}
static Scheme_Object * rename_transformer_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_id_macro_type ) ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * write_toplevel (Scheme_Object * obj ) {
  int pos , flags ; 
  Scheme_Object * pr ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(obj, 0), PUSH(pr, 1)));
# define XfOrM852_COUNT (2)
# define SETUP_XfOrM852(x) SETUP(XfOrM852_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  pr = NULLED_OUT ; 
  pos = (((Scheme_Toplevel * ) (obj ) ) -> position ) ; 
  flags = ((& ((Scheme_Toplevel * ) (obj ) ) -> iso ) -> so . keyex & 0x3 ) ; 
  pr = (flags ? FUNCCALL(SETUP_XfOrM852(_), scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (pos ) ) << 1 ) | 0x1 ) ) , ((Scheme_Object * ) (void * ) (long ) ((((long ) (flags ) ) << 1 ) | 0x1 ) ) ) ): ((Scheme_Object * ) (void * ) (long ) ((((long ) (pos ) ) << 1 ) | 0x1 ) ) ) ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) ((((Scheme_Toplevel * ) (obj ) ) -> depth ) ) ) << 1 ) | 0x1 ) ) , pr ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * read_toplevel (Scheme_Object * obj ) {
  /* No conversion */
  int pos , depth , flags ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    return ((void * ) 0 ) ; 
  depth = (((long ) ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ) ) >> 1 ) ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
    pos = (((long ) ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ) ) >> 1 ) ; 
    flags = (((long ) ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ) ) >> 1 ) & 0x3 ; 
  }
  else {
    pos = (((long ) (obj ) ) >> 1 ) ; 
    flags = 0 ; 
  }
  return make_toplevel (depth , pos , 1 , flags ) ; 
}
static Scheme_Object * write_variable (Scheme_Object * obj ) {
  Scheme_Object * __funcarg41 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(obj, 0)));
# define XfOrM856_COUNT (1)
# define SETUP_XfOrM856(x) SETUP(XfOrM856_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (((Scheme_Type ) (scheme_variable_type ) == (Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) ) ) {
    Scheme_Object * sym ; 
    Scheme_Env * home ; 
    Scheme_Module * m ; 
    BLOCK_SETUP((PUSH(sym, 0+XfOrM856_COUNT), PUSH(home, 1+XfOrM856_COUNT)));
#   define XfOrM858_COUNT (2+XfOrM856_COUNT)
#   define SETUP_XfOrM858(x) SETUP(XfOrM858_COUNT)
    sym = NULLED_OUT ; 
    home = NULLED_OUT ; 
    m = NULLED_OUT ; 
    sym = (Scheme_Object * ) (((Scheme_Bucket * ) (obj ) ) ) -> key ; 
    home = ((Scheme_Bucket_With_Home * ) obj ) -> home ; 
    m = home -> module ; 
    if (m ) {
#     define XfOrM859_COUNT (0+XfOrM858_COUNT)
#     define SETUP_XfOrM859(x) SETUP_XfOrM858(x)
      sym = FUNCCALL(SETUP_XfOrM859(_), scheme_make_pair (m -> modname , sym ) ); 
      if (home -> mod_phase )
        sym = FUNCCALL(SETUP_XfOrM859(_), scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (home -> mod_phase ) ) << 1 ) | 0x1 ) ) , sym ) ); 
    }
    RET_VALUE_START (sym ) RET_VALUE_END ; 
  }
  else {
    Module_Variable * mv = (Module_Variable * ) obj ; 
    BLOCK_SETUP((PUSH(mv, 0+XfOrM856_COUNT)));
#   define XfOrM857_COUNT (1+XfOrM856_COUNT)
#   define SETUP_XfOrM857(x) SETUP(XfOrM857_COUNT)
    RET_VALUE_START ((__funcarg41 = FUNCCALL(SETUP_XfOrM857(_), scheme_make_pair (mv -> modidx , mv -> sym ) ), FUNCCALL_EMPTY(scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (mv -> mod_phase ) ) << 1 ) | 0x1 ) ) , __funcarg41 ) )) ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * read_variable (Scheme_Object * obj ) {
  Scheme_Env * env ; 
  Scheme_Config * __funcarg42 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(obj, 1)));
# define XfOrM860_COUNT (2)
# define SETUP_XfOrM860(x) SETUP(XfOrM860_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  env = NULLED_OUT ; 
  env = FUNCCALL(SETUP_XfOrM860(_), scheme_get_env (((void * ) 0 ) ) ); 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
    Scheme_Object * modname , * varname ; 
    int mod_phase = 0 ; 
    BLOCK_SETUP((PUSH(varname, 0+XfOrM860_COUNT), PUSH(modname, 1+XfOrM860_COUNT)));
#   define XfOrM861_COUNT (2+XfOrM860_COUNT)
#   define SETUP_XfOrM861(x) SETUP(XfOrM861_COUNT)
    modname = NULLED_OUT ; 
    varname = NULLED_OUT ; 
    if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    modname = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
    if ((((long ) (modname ) ) & 0x1 ) ) {
      mod_phase = (((long ) (modname ) ) >> 1 ) ; 
      if (mod_phase != 1 )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
      if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      modname = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
    }
    varname = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
    if (((modname ) == (kernel_symbol ) ) && ! mod_phase ) {
#     define XfOrM863_COUNT (0+XfOrM861_COUNT)
#     define SETUP_XfOrM863(x) SETUP_XfOrM861(x)
      RET_VALUE_START ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM863(_), scheme_global_bucket (varname , scheme_initial_env ) )) RET_VALUE_END ; 
    }
    else {
      Module_Variable * mv ; 
      Scheme_Object * insp ; 
      BLOCK_SETUP((PUSH(mv, 0+XfOrM861_COUNT), PUSH(insp, 1+XfOrM861_COUNT)));
#     define XfOrM862_COUNT (2+XfOrM861_COUNT)
#     define SETUP_XfOrM862(x) SETUP(XfOrM862_COUNT)
      mv = NULLED_OUT ; 
      insp = NULLED_OUT ; 
      insp = (__funcarg42 = FUNCCALL(SETUP_XfOrM862(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg42 , MZCONFIG_CODE_INSPECTOR ) )) ; 
      mv = ((Module_Variable * ) FUNCCALL(SETUP_XfOrM862(_), GC_malloc_one_small_tagged ((((sizeof (Module_Variable ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
      mv -> so . type = scheme_module_variable_type ; 
      mv -> modidx = modname ; 
      mv -> sym = varname ; 
      mv -> insp = insp ; 
      mv -> pos = - 1 ; 
      mv -> mod_phase = mod_phase ; 
      RET_VALUE_START ((Scheme_Object * ) mv ) RET_VALUE_END ; 
    }
  }
  RET_VALUE_START ((Scheme_Object * ) FUNCCALL_EMPTY(scheme_global_bucket (obj , env ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * write_local (Scheme_Object * obj ) {
  /* No conversion */
  return ((Scheme_Object * ) (void * ) (long ) ((((long ) ((((Scheme_Local * ) (obj ) ) -> position ) ) ) << 1 ) | 0x1 ) ) ; 
}
static Scheme_Object * read_local (Scheme_Object * obj ) {
  /* No conversion */
  return scheme_make_local (scheme_local_type , (((long ) (obj ) ) >> 1 ) ) ; 
}
static Scheme_Object * read_local_unbox (Scheme_Object * obj ) {
  /* No conversion */
  return scheme_make_local (scheme_local_unbox_type , (((long ) (obj ) ) >> 1 ) ) ; 
}
static Scheme_Object * write_resolve_prefix (Scheme_Object * obj ) {
  Resolve_Prefix * rp = (Resolve_Prefix * ) obj ; 
  Scheme_Object * tv , * sv , * ds ; 
  int i ; 
  Scheme_Object * __funcarg43 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(tv, 0), PUSH(ds, 1), PUSH(sv, 2), PUSH(rp, 3)));
# define XfOrM868_COUNT (4)
# define SETUP_XfOrM868(x) SETUP(XfOrM868_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  tv = NULLED_OUT ; 
  sv = NULLED_OUT ; 
  ds = NULLED_OUT ; 
  i = rp -> num_toplevels ; 
  tv = FUNCCALL(SETUP_XfOrM868(_), scheme_make_vector (i , ((void * ) 0 ) ) ); 
  while (i -- ) {
    (((Scheme_Vector * ) (tv ) ) -> els ) [i ] = rp -> toplevels [i ] ; 
  }
  i = rp -> num_stxes ; 
  sv = FUNCCALL(SETUP_XfOrM868(_), scheme_make_vector (i , ((void * ) 0 ) ) ); 
  while (i -- ) {
#   define XfOrM871_COUNT (0+XfOrM868_COUNT)
#   define SETUP_XfOrM871(x) SETUP_XfOrM868(x)
    if (rp -> stxes [i ] ) {
#     define XfOrM872_COUNT (0+XfOrM871_COUNT)
#     define SETUP_XfOrM872(x) SETUP_XfOrM871(x)
      ds = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM872(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
      ds -> type = scheme_delay_syntax_type ; 
      (((Scheme_Small_Object * ) (ds ) ) -> u . ptr_val ) = rp -> stxes [i ] ; 
    }
    else ds = scheme_false ; 
    (((Scheme_Vector * ) (sv ) ) -> els ) [i ] = ds ; 
  }
  RET_VALUE_START ((__funcarg43 = FUNCCALL(SETUP_XfOrM868(_), scheme_make_pair (tv , sv ) ), FUNCCALL_EMPTY(scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (rp -> num_lifts ) ) << 1 ) | 0x1 ) ) , __funcarg43 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * read_resolve_prefix (Scheme_Object * obj ) {
  Resolve_Prefix * rp ; 
  Scheme_Object * tv , * sv , * * a , * stx ; 
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(stx, 0), PUSH(rp, 1), PUSH(tv, 2), PUSH(sv, 3), PUSH(a, 4)));
# define XfOrM875_COUNT (5)
# define SETUP_XfOrM875(x) SETUP(XfOrM875_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  rp = NULLED_OUT ; 
  tv = NULLED_OUT ; 
  sv = NULLED_OUT ; 
  a = NULLED_OUT ; 
  stx = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  i = (((long ) ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ) ) >> 1 ) ; 
  if (i < 0 )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  tv = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
  sv = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  rp = ((Resolve_Prefix * ) FUNCCALL(SETUP_XfOrM875(_), GC_malloc_one_small_tagged ((((sizeof (Resolve_Prefix ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  rp -> so . type = scheme_resolve_prefix_type ; 
  rp -> num_toplevels = (((Scheme_Vector * ) (tv ) ) -> size ) ; 
  rp -> num_stxes = (((Scheme_Vector * ) (sv ) ) -> size ) ; 
  rp -> num_lifts = i ; 
  i = rp -> num_toplevels ; 
  a = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM875(_), GC_malloc (sizeof (Scheme_Object * ) * (i ) ) )) ; 
  while (i -- ) {
    a [i ] = (((Scheme_Vector * ) (tv ) ) -> els ) [i ] ; 
  }
  rp -> toplevels = a ; 
  i = rp -> num_stxes ; 
  a = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM875(_), GC_malloc (sizeof (Scheme_Object * ) * (i ) ) )) ; 
  while (i -- ) {
    stx = (((Scheme_Vector * ) (sv ) ) -> els ) [i ] ; 
    if ((((stx ) ) == (scheme_false ) ) ) {
      stx = ((void * ) 0 ) ; 
    }
    else if (((Scheme_Type ) (((((long ) (stx ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (stx ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ) {
      rp -> delay_info = (struct Scheme_Load_Delay * ) (((Scheme_Simple_Object * ) (stx ) ) -> u . pair_val . cdr ) ; 
      rp -> delay_refcount ++ ; 
      stx = (((Scheme_Simple_Object * ) (stx ) ) -> u . pair_val . car ) ; 
    }
    else {
      if (! ((Scheme_Type ) (((((long ) (stx ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (stx ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    a [i ] = stx ; 
  }
  rp -> stxes = a ; 
  RET_VALUE_START ((Scheme_Object * ) rp ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int mark_comp_env_SIZE (void * p ) {
  return ((sizeof (Scheme_Full_Comp_Env ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_comp_env_MARK (void * p ) {
  Scheme_Full_Comp_Env * e = (Scheme_Full_Comp_Env * ) p ; 
  GC_mark (e -> base . genv ) ; 
  GC_mark (e -> base . insp ) ; 
  GC_mark (e -> base . prefix ) ; 
  GC_mark (e -> base . next ) ; 
  GC_mark (e -> base . values ) ; 
  GC_mark (e -> base . certs ) ; 
  GC_mark (e -> base . renames ) ; 
  GC_mark (e -> base . uid ) ; 
  GC_mark (e -> base . uids ) ; 
  GC_mark (e -> base . dup_check ) ; 
  GC_mark (e -> base . intdef_name ) ; 
  GC_mark (e -> base . in_modidx ) ; 
  GC_mark (e -> base . skip_table ) ; 
  GC_mark (e -> data . const_names ) ; 
  GC_mark (e -> data . const_vals ) ; 
  GC_mark (e -> data . const_uids ) ; 
  GC_mark (e -> data . use ) ; 
  GC_mark (e -> data . lifts ) ; 
  return ((sizeof (Scheme_Full_Comp_Env ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_comp_env_FIXUP (void * p ) {
  Scheme_Full_Comp_Env * e = (Scheme_Full_Comp_Env * ) p ; 
  GC_fixup (& (e -> base . genv ) ) ; 
  GC_fixup (& (e -> base . insp ) ) ; 
  GC_fixup (& (e -> base . prefix ) ) ; 
  GC_fixup (& (e -> base . next ) ) ; 
  GC_fixup (& (e -> base . values ) ) ; 
  GC_fixup (& (e -> base . certs ) ) ; 
  GC_fixup (& (e -> base . renames ) ) ; 
  GC_fixup (& (e -> base . uid ) ) ; 
  GC_fixup (& (e -> base . uids ) ) ; 
  GC_fixup (& (e -> base . dup_check ) ) ; 
  GC_fixup (& (e -> base . intdef_name ) ) ; 
  GC_fixup (& (e -> base . in_modidx ) ) ; 
  GC_fixup (& (e -> base . skip_table ) ) ; 
  GC_fixup (& (e -> data . const_names ) ) ; 
  GC_fixup (& (e -> data . const_vals ) ) ; 
  GC_fixup (& (e -> data . const_uids ) ) ; 
  GC_fixup (& (e -> data . use ) ) ; 
  GC_fixup (& (e -> data . lifts ) ) ; 
  return ((sizeof (Scheme_Full_Comp_Env ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_resolve_info_SIZE (void * p ) {
  return ((sizeof (Resolve_Info ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_resolve_info_MARK (void * p ) {
  Resolve_Info * i = (Resolve_Info * ) p ; 
  GC_mark (i -> prefix ) ; 
  GC_mark (i -> stx_map ) ; 
  GC_mark (i -> old_pos ) ; 
  GC_mark (i -> new_pos ) ; 
  GC_mark (i -> old_stx_pos ) ; 
  GC_mark (i -> flags ) ; 
  GC_mark (i -> lifts ) ; 
  GC_mark (i -> lifted ) ; 
  GC_mark (i -> next ) ; 
  return ((sizeof (Resolve_Info ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_resolve_info_FIXUP (void * p ) {
  Resolve_Info * i = (Resolve_Info * ) p ; 
  GC_fixup (& (i -> prefix ) ) ; 
  GC_fixup (& (i -> stx_map ) ) ; 
  GC_fixup (& (i -> old_pos ) ) ; 
  GC_fixup (& (i -> new_pos ) ) ; 
  GC_fixup (& (i -> old_stx_pos ) ) ; 
  GC_fixup (& (i -> flags ) ) ; 
  GC_fixup (& (i -> lifts ) ) ; 
  GC_fixup (& (i -> lifted ) ) ; 
  GC_fixup (& (i -> next ) ) ; 
  return ((sizeof (Resolve_Info ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_optimize_info_SIZE (void * p ) {
  return ((sizeof (Optimize_Info ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_optimize_info_MARK (void * p ) {
  Optimize_Info * i = (Optimize_Info * ) p ; 
  GC_mark (i -> stat_dists ) ; 
  GC_mark (i -> sd_depths ) ; 
  GC_mark (i -> next ) ; 
  GC_mark (i -> use ) ; 
  GC_mark (i -> consts ) ; 
  GC_mark (i -> top_level_consts ) ; 
  GC_mark (i -> transitive_use ) ; 
  GC_mark (i -> transitive_use_len ) ; 
  return ((sizeof (Optimize_Info ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_optimize_info_FIXUP (void * p ) {
  Optimize_Info * i = (Optimize_Info * ) p ; 
  GC_fixup (& (i -> stat_dists ) ) ; 
  GC_fixup (& (i -> sd_depths ) ) ; 
  GC_fixup (& (i -> next ) ) ; 
  GC_fixup (& (i -> use ) ) ; 
  GC_fixup (& (i -> consts ) ) ; 
  GC_fixup (& (i -> top_level_consts ) ) ; 
  GC_fixup (& (i -> transitive_use ) ) ; 
  GC_fixup (& (i -> transitive_use_len ) ) ; 
  return ((sizeof (Optimize_Info ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static void register_traversers (void ) {
  GC_register_traversers (scheme_rt_comp_env , mark_comp_env_SIZE , mark_comp_env_MARK , mark_comp_env_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_resolve_info , mark_resolve_info_SIZE , mark_resolve_info_MARK , mark_resolve_info_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_optimize_info , mark_optimize_info_SIZE , mark_optimize_info_MARK , mark_optimize_info_FIXUP , 1 , 0 ) ; 
}
