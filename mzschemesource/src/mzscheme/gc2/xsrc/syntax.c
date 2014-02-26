#include "precomp.h"
extern void scheme_call_expand_observe (Scheme_Object * obs , int signal , Scheme_Object * argument ) ; 
extern void scheme_init_expand_observe (Scheme_Env * ) ; 
extern Scheme_Object * scheme_get_expand_observe () ; 
Scheme_Object * scheme_define_values_syntax , * scheme_define_syntaxes_syntax ; 
Scheme_Object * scheme_begin_syntax ; 
Scheme_Object * scheme_lambda_syntax ; 
Scheme_Object * scheme_compiled_void_code ; 
Scheme_Object scheme_undefined [1 ] ; 
Scheme_Syntax_Optimizer scheme_syntax_optimizers [12 ] ; 
Scheme_Syntax_Resolver scheme_syntax_resolvers [12 ] ; 
Scheme_Syntax_Validater scheme_syntax_validaters [12 ] ; 
Scheme_Syntax_Executer scheme_syntax_executers [12 ] ; 
Scheme_Syntax_Jitter scheme_syntax_jitters [12 ] ; 
Scheme_Syntax_Cloner scheme_syntax_cloners [12 ] ; 
Scheme_Syntax_Shifter scheme_syntax_shifters [12 ] ; 
int scheme_syntax_protect_afters [12 ] ; 
static Scheme_Object * lambda_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
static Scheme_Object * lambda_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
static Scheme_Object * define_values_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
static Scheme_Object * define_values_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
static Scheme_Object * ref_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
static Scheme_Object * ref_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
static Scheme_Object * quote_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
static Scheme_Object * quote_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
static Scheme_Object * if_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
static Scheme_Object * if_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
static Scheme_Object * set_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
static Scheme_Object * set_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
static Scheme_Object * case_lambda_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
static Scheme_Object * case_lambda_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
static Scheme_Object * let_values_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
static Scheme_Object * let_values_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
static Scheme_Object * let_star_values_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
static Scheme_Object * let_star_values_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
static Scheme_Object * letrec_values_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
static Scheme_Object * letrec_values_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
static Scheme_Object * begin_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
static Scheme_Object * begin_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
static Scheme_Object * begin0_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
static Scheme_Object * begin0_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
static Scheme_Object * expression_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
static Scheme_Object * expression_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
static Scheme_Object * unquote_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
static Scheme_Object * unquote_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
static Scheme_Object * with_cont_mark_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
static Scheme_Object * with_cont_mark_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
static Scheme_Object * quote_syntax_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
static Scheme_Object * quote_syntax_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
static Scheme_Object * define_syntaxes_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
static Scheme_Object * define_syntaxes_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
static Scheme_Object * define_for_syntaxes_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
static Scheme_Object * define_for_syntaxes_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
static Scheme_Object * letrec_syntaxes_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) ; 
static Scheme_Object * letrec_syntaxes_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) ; 
static Scheme_Object * define_values_execute (Scheme_Object * data ) ; 
static Scheme_Object * ref_execute (Scheme_Object * data ) ; 
static Scheme_Object * set_execute (Scheme_Object * data ) ; 
static Scheme_Object * define_syntaxes_execute (Scheme_Object * expr ) ; 
static Scheme_Object * define_for_syntaxes_execute (Scheme_Object * expr ) ; 
static Scheme_Object * case_lambda_execute (Scheme_Object * expr ) ; 
static Scheme_Object * begin0_execute (Scheme_Object * data ) ; 
static Scheme_Object * apply_values_execute (Scheme_Object * data ) ; 
static Scheme_Object * splice_execute (Scheme_Object * data ) ; 
static Scheme_Object * bangboxenv_execute (Scheme_Object * data ) ; 
static Scheme_Object * define_values_optimize (Scheme_Object * data , Optimize_Info * info ) ; 
static Scheme_Object * ref_optimize (Scheme_Object * data , Optimize_Info * info ) ; 
static Scheme_Object * set_optimize (Scheme_Object * data , Optimize_Info * info ) ; 
static Scheme_Object * define_syntaxes_optimize (Scheme_Object * expr , Optimize_Info * info ) ; 
static Scheme_Object * define_for_syntaxes_optimize (Scheme_Object * expr , Optimize_Info * info ) ; 
static Scheme_Object * case_lambda_optimize (Scheme_Object * expr , Optimize_Info * info ) ; 
static Scheme_Object * begin0_optimize (Scheme_Object * data , Optimize_Info * info ) ; 
static Scheme_Object * apply_values_optimize (Scheme_Object * data , Optimize_Info * info ) ; 
static Scheme_Object * splice_optimize (Scheme_Object * data , Optimize_Info * info ) ; 
static Scheme_Object * begin0_clone (int dup_ok , Scheme_Object * data , Optimize_Info * info , int delta , int closure_depth ) ; 
static Scheme_Object * set_clone (int dup_ok , Scheme_Object * data , Optimize_Info * info , int delta , int closure_depth ) ; 
static Scheme_Object * apply_values_clone (int dup_ok , Scheme_Object * data , Optimize_Info * info , int delta , int closure_depth ) ; 
static Scheme_Object * splice_clone (int dup_ok , Scheme_Object * data , Optimize_Info * info , int delta , int closure_depth ) ; 
static Scheme_Object * begin0_shift (Scheme_Object * data , int delta , int after_depth ) ; 
static Scheme_Object * set_shift (Scheme_Object * data , int delta , int after_depth ) ; 
static Scheme_Object * ref_shift (Scheme_Object * data , int delta , int after_depth ) ; 
static Scheme_Object * case_lambda_shift (Scheme_Object * data , int delta , int after_depth ) ; 
static Scheme_Object * apply_values_shift (Scheme_Object * data , int delta , int after_depth ) ; 
static Scheme_Object * splice_shift (Scheme_Object * data , int delta , int after_depth ) ; 
static Scheme_Object * define_values_resolve (Scheme_Object * data , Resolve_Info * info ) ; 
static Scheme_Object * ref_resolve (Scheme_Object * data , Resolve_Info * info ) ; 
static Scheme_Object * set_resolve (Scheme_Object * data , Resolve_Info * info ) ; 
static Scheme_Object * define_syntaxes_resolve (Scheme_Object * expr , Resolve_Info * info ) ; 
static Scheme_Object * define_for_syntaxes_resolve (Scheme_Object * expr , Resolve_Info * info ) ; 
static Scheme_Object * case_lambda_resolve (Scheme_Object * expr , Resolve_Info * info ) ; 
static Scheme_Object * begin0_resolve (Scheme_Object * data , Resolve_Info * info ) ; 
static Scheme_Object * apply_values_resolve (Scheme_Object * data , Resolve_Info * info ) ; 
static Scheme_Object * splice_resolve (Scheme_Object * data , Resolve_Info * info ) ; 
static void define_values_validate (Scheme_Object * data , Mz_CPort * port , char * stack , Scheme_Hash_Table * ht , Scheme_Object * * tls , int depth , int letlimit , int delta , int num_toplevels , int num_stxes , int num_lifts ) ; 
static void ref_validate (Scheme_Object * data , Mz_CPort * port , char * stack , Scheme_Hash_Table * ht , Scheme_Object * * tls , int depth , int letlimit , int delta , int num_toplevels , int num_stxes , int num_lifts ) ; 
static void set_validate (Scheme_Object * data , Mz_CPort * port , char * stack , Scheme_Hash_Table * ht , Scheme_Object * * tls , int depth , int letlimit , int delta , int num_toplevels , int num_stxes , int num_lifts ) ; 
static void define_syntaxes_validate (Scheme_Object * data , Mz_CPort * port , char * stack , Scheme_Hash_Table * ht , Scheme_Object * * tls , int depth , int letlimit , int delta , int num_toplevels , int num_stxes , int num_lifts ) ; 
static void define_for_syntaxes_validate (Scheme_Object * data , Mz_CPort * port , char * stack , Scheme_Hash_Table * ht , Scheme_Object * * tls , int depth , int letlimit , int delta , int num_toplevels , int num_stxes , int num_lifts ) ; 
static void case_lambda_validate (Scheme_Object * data , Mz_CPort * port , char * stack , Scheme_Hash_Table * ht , Scheme_Object * * tls , int depth , int letlimit , int delta , int num_toplevels , int num_stxes , int num_lifts ) ; 
static void begin0_validate (Scheme_Object * data , Mz_CPort * port , char * stack , Scheme_Hash_Table * ht , Scheme_Object * * tls , int depth , int letlimit , int delta , int num_toplevels , int num_stxes , int num_lifts ) ; 
static void apply_values_validate (Scheme_Object * data , Mz_CPort * port , char * stack , Scheme_Hash_Table * ht , Scheme_Object * * tls , int depth , int letlimit , int delta , int num_toplevels , int num_stxes , int num_lifts ) ; 
static void splice_validate (Scheme_Object * data , Mz_CPort * port , char * stack , Scheme_Hash_Table * ht , Scheme_Object * * tls , int depth , int letlimit , int delta , int num_toplevels , int num_stxes , int num_lifts ) ; 
static void bangboxenv_validate (Scheme_Object * data , Mz_CPort * port , char * stack , Scheme_Hash_Table * ht , Scheme_Object * * tls , int depth , int letlimit , int delta , int num_toplevels , int num_stxes , int num_lifts ) ; 
static Scheme_Object * define_values_jit (Scheme_Object * data ) ; 
static Scheme_Object * ref_jit (Scheme_Object * data ) ; 
static Scheme_Object * set_jit (Scheme_Object * data ) ; 
static Scheme_Object * define_syntaxes_jit (Scheme_Object * expr ) ; 
static Scheme_Object * define_for_syntaxes_jit (Scheme_Object * expr ) ; 
static Scheme_Object * case_lambda_jit (Scheme_Object * expr ) ; 
static Scheme_Object * begin0_jit (Scheme_Object * data ) ; 
static Scheme_Object * apply_values_jit (Scheme_Object * data ) ; 
static Scheme_Object * splice_jit (Scheme_Object * data ) ; 
static Scheme_Object * bangboxenv_jit (Scheme_Object * data ) ; 
static Scheme_Object * expand_lam (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * write_let_value (Scheme_Object * obj ) ; 
static Scheme_Object * read_let_value (Scheme_Object * obj ) ; 
static Scheme_Object * write_let_void (Scheme_Object * obj ) ; 
static Scheme_Object * read_let_void (Scheme_Object * obj ) ; 
static Scheme_Object * write_letrec (Scheme_Object * obj ) ; 
static Scheme_Object * read_letrec (Scheme_Object * obj ) ; 
static Scheme_Object * write_let_one (Scheme_Object * obj ) ; 
static Scheme_Object * read_let_one (Scheme_Object * obj ) ; 
static Scheme_Object * write_top (Scheme_Object * obj ) ; 
static Scheme_Object * read_top (Scheme_Object * obj ) ; 
static Scheme_Object * write_case_lambda (Scheme_Object * obj ) ; 
static Scheme_Object * read_case_lambda (Scheme_Object * obj ) ; 
static Scheme_Object * lambda_symbol ; 
static Scheme_Object * letrec_values_symbol ; 
static Scheme_Object * let_star_values_symbol ; 
static Scheme_Object * let_values_symbol ; 
static Scheme_Object * begin_symbol ; 
static Scheme_Object * disappeared_binding_symbol ; 
static void register_traversers (void ) ; 
void scheme_init_syntax (Scheme_Env * env ) {
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
  PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(env, 0)));
# define XfOrM1_COUNT (1)
# define SETUP_XfOrM1(x) SETUP(XfOrM1_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  FUNCCALL(SETUP_XfOrM1(_), register_traversers () ); 
  FUNCCALL(SETUP_XfOrM1(_), scheme_register_static ((void * ) & scheme_define_values_syntax , sizeof (scheme_define_values_syntax ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_define_syntaxes_syntax , sizeof (scheme_define_syntaxes_syntax ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_lambda_syntax , sizeof (scheme_lambda_syntax ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_begin_syntax , sizeof (scheme_begin_syntax ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_compiled_void_code , sizeof (scheme_compiled_void_code ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & lambda_symbol , sizeof (lambda_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & letrec_values_symbol , sizeof (letrec_values_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & let_star_values_symbol , sizeof (let_star_values_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & let_values_symbol , sizeof (let_values_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & begin_symbol , sizeof (begin_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & disappeared_binding_symbol , sizeof (disappeared_binding_symbol ) ) ); 
  scheme_undefined -> type = scheme_undefined_type ; 
  lambda_symbol = FUNCCALL(SETUP_XfOrM1(_), scheme_intern_symbol ("lambda" ) ); 
  letrec_values_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("letrec-values" ) ); 
  let_star_values_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("let*-values" ) ); 
  let_values_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("let-values" ) ); 
  begin_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("begin" ) ); 
  disappeared_binding_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("disappeared-binding" ) ); 
  (scheme_syntax_optimizers [0 ] = define_values_optimize , scheme_syntax_resolvers [0 ] = define_values_resolve , scheme_syntax_executers [0 ] = define_values_execute , scheme_syntax_validaters [0 ] = define_values_validate , scheme_syntax_jitters [0 ] = define_values_jit , scheme_syntax_cloners [0 ] = ((void * ) 0 ) , scheme_syntax_shifters [0 ] = ((void * ) 0 ) , scheme_syntax_protect_afters [0 ] = - 2 ) ; 
  (scheme_syntax_optimizers [2 ] = set_optimize , scheme_syntax_resolvers [2 ] = set_resolve , scheme_syntax_executers [2 ] = set_execute , scheme_syntax_validaters [2 ] = set_validate , scheme_syntax_jitters [2 ] = set_jit , scheme_syntax_cloners [2 ] = set_clone , scheme_syntax_shifters [2 ] = set_shift , scheme_syntax_protect_afters [2 ] = 2 ) ; 
  (scheme_syntax_optimizers [9 ] = ref_optimize , scheme_syntax_resolvers [9 ] = ref_resolve , scheme_syntax_executers [9 ] = ref_execute , scheme_syntax_validaters [9 ] = ref_validate , scheme_syntax_jitters [9 ] = ref_jit , scheme_syntax_cloners [9 ] = ((void * ) 0 ) , scheme_syntax_shifters [9 ] = ref_shift , scheme_syntax_protect_afters [9 ] = 0 ) ; 
  (scheme_syntax_optimizers [1 ] = define_syntaxes_optimize , scheme_syntax_resolvers [1 ] = define_syntaxes_resolve , scheme_syntax_executers [1 ] = define_syntaxes_execute , scheme_syntax_validaters [1 ] = define_syntaxes_validate , scheme_syntax_jitters [1 ] = define_syntaxes_jit , scheme_syntax_cloners [1 ] = ((void * ) 0 ) , scheme_syntax_shifters [1 ] = ((void * ) 0 ) , scheme_syntax_protect_afters [1 ] = - 2 ) ; 
  (scheme_syntax_optimizers [8 ] = define_for_syntaxes_optimize , scheme_syntax_resolvers [8 ] = define_for_syntaxes_resolve , scheme_syntax_executers [8 ] = define_for_syntaxes_execute , scheme_syntax_validaters [8 ] = define_for_syntaxes_validate , scheme_syntax_jitters [8 ] = define_for_syntaxes_jit , scheme_syntax_cloners [8 ] = ((void * ) 0 ) , scheme_syntax_shifters [8 ] = ((void * ) 0 ) , scheme_syntax_protect_afters [8 ] = - 2 ) ; 
  (scheme_syntax_optimizers [3 ] = case_lambda_optimize , scheme_syntax_resolvers [3 ] = case_lambda_resolve , scheme_syntax_executers [3 ] = case_lambda_execute , scheme_syntax_validaters [3 ] = case_lambda_validate , scheme_syntax_jitters [3 ] = case_lambda_jit , scheme_syntax_cloners [3 ] = ((void * ) 0 ) , scheme_syntax_shifters [3 ] = case_lambda_shift , scheme_syntax_protect_afters [3 ] = - 1 ) ; 
  (scheme_syntax_optimizers [4 ] = begin0_optimize , scheme_syntax_resolvers [4 ] = begin0_resolve , scheme_syntax_executers [4 ] = begin0_execute , scheme_syntax_validaters [4 ] = begin0_validate , scheme_syntax_jitters [4 ] = begin0_jit , scheme_syntax_cloners [4 ] = begin0_clone , scheme_syntax_shifters [4 ] = begin0_shift , scheme_syntax_protect_afters [4 ] = - 1 ) ; 
  (scheme_syntax_optimizers [10 ] = apply_values_optimize , scheme_syntax_resolvers [10 ] = apply_values_resolve , scheme_syntax_executers [10 ] = apply_values_execute , scheme_syntax_validaters [10 ] = apply_values_validate , scheme_syntax_jitters [10 ] = apply_values_jit , scheme_syntax_cloners [10 ] = apply_values_clone , scheme_syntax_shifters [10 ] = apply_values_shift , scheme_syntax_protect_afters [10 ] = 1 ) ; 
  (scheme_syntax_optimizers [11 ] = splice_optimize , scheme_syntax_resolvers [11 ] = splice_resolve , scheme_syntax_executers [11 ] = splice_execute , scheme_syntax_validaters [11 ] = splice_validate , scheme_syntax_jitters [11 ] = splice_jit , scheme_syntax_cloners [11 ] = splice_clone , scheme_syntax_shifters [11 ] = splice_shift , scheme_syntax_protect_afters [11 ] = 0 ) ; 
  (scheme_syntax_optimizers [5 ] = ((void * ) 0 ) , scheme_syntax_resolvers [5 ] = ((void * ) 0 ) , scheme_syntax_executers [5 ] = bangboxenv_execute , scheme_syntax_validaters [5 ] = bangboxenv_validate , scheme_syntax_jitters [5 ] = bangboxenv_jit , scheme_syntax_cloners [5 ] = ((void * ) 0 ) , scheme_syntax_shifters [5 ] = ((void * ) 0 ) , scheme_syntax_protect_afters [5 ] = 1 ) ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_install_type_writer (scheme_let_value_type , write_let_value ) ); 
  FUNCCALL_AGAIN(scheme_install_type_reader (scheme_let_value_type , read_let_value ) ); 
  FUNCCALL_AGAIN(scheme_install_type_writer (scheme_let_void_type , write_let_void ) ); 
  FUNCCALL_AGAIN(scheme_install_type_reader (scheme_let_void_type , read_let_void ) ); 
  FUNCCALL_AGAIN(scheme_install_type_writer (scheme_letrec_type , write_letrec ) ); 
  FUNCCALL_AGAIN(scheme_install_type_reader (scheme_letrec_type , read_letrec ) ); 
  FUNCCALL_AGAIN(scheme_install_type_writer (scheme_let_one_type , write_let_one ) ); 
  FUNCCALL_AGAIN(scheme_install_type_reader (scheme_let_one_type , read_let_one ) ); 
  FUNCCALL_AGAIN(scheme_install_type_writer (scheme_case_lambda_sequence_type , write_case_lambda ) ); 
  FUNCCALL_AGAIN(scheme_install_type_reader (scheme_case_lambda_sequence_type , read_case_lambda ) ); 
  FUNCCALL_AGAIN(scheme_install_type_writer (scheme_compilation_top_type , write_top ) ); 
  FUNCCALL_AGAIN(scheme_install_type_reader (scheme_compilation_top_type , read_top ) ); 
  scheme_define_values_syntax = FUNCCALL_AGAIN(scheme_make_compiled_syntax (define_values_syntax , define_values_expand ) ); 
  scheme_define_syntaxes_syntax = FUNCCALL_AGAIN(scheme_make_compiled_syntax (define_syntaxes_syntax , define_syntaxes_expand ) ); 
  scheme_lambda_syntax = FUNCCALL_AGAIN(scheme_make_compiled_syntax (lambda_syntax , lambda_expand ) ); 
  scheme_begin_syntax = FUNCCALL_AGAIN(scheme_make_compiled_syntax (begin_syntax , begin_expand ) ); 
  FUNCCALL_AGAIN(scheme_add_global_keyword ("lambda" , scheme_lambda_syntax , env ) ); 
  {
    Scheme_Object * macro , * fn ; 
    BLOCK_SETUP((PUSH(macro, 0+XfOrM1_COUNT), PUSH(fn, 1+XfOrM1_COUNT)));
#   define XfOrM2_COUNT (2+XfOrM1_COUNT)
#   define SETUP_XfOrM2(x) SETUP(XfOrM2_COUNT)
    macro = NULLED_OUT ; 
    fn = NULLED_OUT ; 
    fn = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (expand_lam , "\316\273" , 1 , 1 ) ); 
    macro = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM2(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    macro -> type = scheme_macro_type ; 
    (((Scheme_Small_Object * ) (macro ) ) -> u . ptr_val ) = fn ; 
    FUNCCALL(SETUP_XfOrM2(_), scheme_add_global_keyword ("\316\273" , macro , env ) ); 
  }
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_keyword ("define-values" , scheme_define_values_syntax , env ) ); 
  (__funcarg19 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_compiled_syntax (quote_syntax , quote_expand ) ), FUNCCALL_AGAIN(scheme_add_global_keyword ("quote" , __funcarg19 , env ) )) ; 
  (__funcarg18 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_compiled_syntax (if_syntax , if_expand ) ), FUNCCALL_AGAIN(scheme_add_global_keyword ("if" , __funcarg18 , env ) )) ; 
  (__funcarg17 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_compiled_syntax (set_syntax , set_expand ) ), FUNCCALL_AGAIN(scheme_add_global_keyword ("set!" , __funcarg17 , env ) )) ; 
  (__funcarg16 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_compiled_syntax (ref_syntax , ref_expand ) ), FUNCCALL_AGAIN(scheme_add_global_keyword ("#%variable-reference" , __funcarg16 , env ) )) ; 
  (__funcarg15 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_compiled_syntax (expression_syntax , expression_expand ) ), FUNCCALL_AGAIN(scheme_add_global_keyword ("#%expression" , __funcarg15 , env ) )) ; 
  (__funcarg14 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_compiled_syntax (case_lambda_syntax , case_lambda_expand ) ), FUNCCALL_AGAIN(scheme_add_global_keyword ("case-lambda" , __funcarg14 , env ) )) ; 
  (__funcarg13 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_compiled_syntax (let_values_syntax , let_values_expand ) ), FUNCCALL_AGAIN(scheme_add_global_keyword ("let-values" , __funcarg13 , env ) )) ; 
  (__funcarg12 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_compiled_syntax (let_star_values_syntax , let_star_values_expand ) ), FUNCCALL_AGAIN(scheme_add_global_keyword ("let*-values" , __funcarg12 , env ) )) ; 
  (__funcarg11 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_compiled_syntax (letrec_values_syntax , letrec_values_expand ) ), FUNCCALL_AGAIN(scheme_add_global_keyword ("letrec-values" , __funcarg11 , env ) )) ; 
  FUNCCALL_AGAIN(scheme_add_global_keyword ("begin" , scheme_begin_syntax , env ) ); 
  (__funcarg10 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_compiled_syntax (begin0_syntax , begin0_expand ) ), FUNCCALL_AGAIN(scheme_add_global_keyword ("begin0" , __funcarg10 , env ) )) ; 
  (__funcarg9 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_compiled_syntax (unquote_syntax , unquote_expand ) ), FUNCCALL_AGAIN(scheme_add_global_keyword ("unquote" , __funcarg9 , env ) )) ; 
  (__funcarg8 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_compiled_syntax (unquote_syntax , unquote_expand ) ), FUNCCALL_AGAIN(scheme_add_global_keyword ("unquote-splicing" , __funcarg8 , env ) )) ; 
  (__funcarg7 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_compiled_syntax (with_cont_mark_syntax , with_cont_mark_expand ) ), FUNCCALL_AGAIN(scheme_add_global_keyword ("with-continuation-mark" , __funcarg7 , env ) )) ; 
  (__funcarg6 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_compiled_syntax (quote_syntax_syntax , quote_syntax_expand ) ), FUNCCALL_AGAIN(scheme_add_global_keyword ("quote-syntax" , __funcarg6 , env ) )) ; 
  FUNCCALL_AGAIN(scheme_add_global_keyword ("define-syntaxes" , scheme_define_syntaxes_syntax , env ) ); 
  (__funcarg5 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_compiled_syntax (define_for_syntaxes_syntax , define_for_syntaxes_expand ) ), FUNCCALL_AGAIN(scheme_add_global_keyword ("define-values-for-syntax" , __funcarg5 , env ) )) ; 
  (__funcarg4 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_compiled_syntax (letrec_syntaxes_syntax , letrec_syntaxes_expand ) ), FUNCCALL_AGAIN(scheme_add_global_keyword ("letrec-syntaxes+values" , __funcarg4 , env ) )) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_compiled_syntax (Scheme_Syntax * proc , Scheme_Syntax_Expander * eproc ) {
  Scheme_Object * syntax ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(eproc, 0), PUSH(syntax, 1), PUSH(proc, 2)));
# define XfOrM3_COUNT (3)
# define SETUP_XfOrM3(x) SETUP(XfOrM3_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  syntax = NULLED_OUT ; 
  syntax = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM3(_), GC_malloc_atomic_uncollectable (sizeof (Scheme_Simple_Object ) ) )) ; 
  syntax -> type = scheme_syntax_compiler_type ; 
  (((Scheme_Simple_Object * ) (syntax ) ) -> u . two_ptr_val . ptr1 ) = (Scheme_Object * ) proc ; 
  (((Scheme_Simple_Object * ) (syntax ) ) -> u . two_ptr_val . ptr2 ) = (Scheme_Object * ) eproc ; 
  RET_VALUE_START (syntax ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int check_form (Scheme_Object * form , Scheme_Object * base_form ) {
  int i ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(base_form, 0), PUSH(form, 1)));
# define XfOrM4_COUNT (2)
# define SETUP_XfOrM4(x) SETUP(XfOrM4_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  for (i = 0 ; (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) form ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) form ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ; i ++ ) {
#   define XfOrM7_COUNT (0+XfOrM4_COUNT)
#   define SETUP_XfOrM7(x) SETUP_XfOrM4(x)
    form = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM7(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  }
  if (! (((form ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) form ) -> val ) == (scheme_null ) ) ) ) ) {
#   define XfOrM5_COUNT (0+XfOrM4_COUNT)
#   define SETUP_XfOrM5(x) SETUP_XfOrM4(x)
    FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , form , base_form , "bad syntax (" "illegal use of `.'" ")" ) ); 
  }
  RET_VALUE_START (i ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void bad_form (Scheme_Object * form , int l ) {
  /* No conversion */
  scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , form , "bad syntax (has %d part%s after keyword)" , l - 1 , (l != 2 ) ? "s" : "" ) ; 
}
Scheme_Object * scheme_check_name_property (Scheme_Object * code , Scheme_Object * current_val ) {
  Scheme_Object * name ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(current_val, 0), PUSH(name, 1)));
# define XfOrM9_COUNT (2)
# define SETUP_XfOrM9(x) SETUP(XfOrM9_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  name = NULLED_OUT ; 
  name = FUNCCALL(SETUP_XfOrM9(_), scheme_stx_property (code , scheme_inferred_name_symbol , ((void * ) 0 ) ) ); 
  if (name && ((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
    RET_VALUE_START (name ) RET_VALUE_END ; 
  else RET_VALUE_START (current_val ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void lambda_check (Scheme_Object * form ) {
  PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(form, 0)));
# define XfOrM10_COUNT (1)
# define SETUP_XfOrM10(x) SETUP(XfOrM10_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) form ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) form ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) && (((Scheme_Type ) (((((long ) ((((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM10(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM10(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) ((((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM10(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM10(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM10(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM10(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
    Scheme_Object * rest ; 
    BLOCK_SETUP((PUSH(rest, 0+XfOrM10_COUNT)));
#   define XfOrM11_COUNT (1+XfOrM10_COUNT)
#   define SETUP_XfOrM11(x) SETUP(XfOrM11_COUNT)
    rest = NULLED_OUT ; 
    rest = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM11(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
    if ((((Scheme_Type ) (((((long ) ((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM11(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM11(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) ((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM11(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM11(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM11(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM11(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
      RET_NOTHING ; 
  }
  FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , form , ((void * ) 0 ) ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void lambda_check_args (Scheme_Object * args , Scheme_Object * form , Scheme_Comp_Env * env ) {
  Scheme_Object * v , * a ; 
  DupCheckRecord r ; 
  PREPARE_VAR_STACK(10);
  BLOCK_SETUP_TOP((PUSH(args, 0), PUSH(a, 1), PUSH(env, 2), PUSH(v, 3), PUSHARRAY(r.syms, 5, 4), PUSH(r.ht, 7), PUSH(form, 8)));
# define XfOrM12_COUNT (9)
# define SETUP_XfOrM12(x) SETUP(XfOrM12_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  v = NULLED_OUT ; 
  a = NULLED_OUT ; 
  NULL_OUT_ARRAY (r.syms ) ; 
  r.ht = NULLED_OUT ; 
  if (! (((Scheme_Type ) (((((long ) (args ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (args ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) args ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) args ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) ) {
#   define XfOrM13_COUNT (0+XfOrM12_COUNT)
#   define SETUP_XfOrM13(x) SETUP_XfOrM12(x)
    for (v = args ; (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) v ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) v ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ; v = (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM13(_), scheme_stx_content (v ) )) ) -> u . pair_val . cdr ) ) ) {
#     define XfOrM20_COUNT (0+XfOrM13_COUNT)
#     define SETUP_XfOrM20(x) SETUP_XfOrM13(x)
      a = (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM20(_), scheme_stx_content (v ) )) ) -> u . pair_val . car ) ) ; 
      FUNCCALL(SETUP_XfOrM20(_), scheme_check_identifier (((void * ) 0 ) , a , ((void * ) 0 ) , env , form ) ); 
    }
    if (! (((v ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) v ) -> val ) == (scheme_null ) ) ) ) ) {
#     define XfOrM17_COUNT (0+XfOrM13_COUNT)
#     define SETUP_XfOrM17(x) SETUP_XfOrM13(x)
      if (! (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) v ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) v ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) ) {
#       define XfOrM18_COUNT (0+XfOrM17_COUNT)
#       define SETUP_XfOrM18(x) SETUP_XfOrM17(x)
        FUNCCALL(SETUP_XfOrM18(_), scheme_check_identifier (((void * ) 0 ) , v , ((void * ) 0 ) , env , form ) ); 
      }
    }
    FUNCCALL(SETUP_XfOrM13(_), scheme_begin_dup_symbol_check (& r , env ) ); 
    for (v = args ; (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) v ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) v ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ; v = (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM13(_), scheme_stx_content (v ) )) ) -> u . pair_val . cdr ) ) ) {
      Scheme_Object * name ; 
      BLOCK_SETUP((PUSH(name, 0+XfOrM13_COUNT)));
#     define XfOrM16_COUNT (1+XfOrM13_COUNT)
#     define SETUP_XfOrM16(x) SETUP(XfOrM16_COUNT)
      name = NULLED_OUT ; 
      name = (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM16(_), scheme_stx_content (v ) )) ) -> u . pair_val . car ) ) ; 
      FUNCCALL(SETUP_XfOrM16(_), scheme_dup_symbol_check (& r , ((void * ) 0 ) , name , "argument" , form ) ); 
    }
    if (! (((v ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) v ) -> val ) == (scheme_null ) ) ) ) ) {
#     define XfOrM14_COUNT (0+XfOrM13_COUNT)
#     define SETUP_XfOrM14(x) SETUP_XfOrM13(x)
      FUNCCALL(SETUP_XfOrM14(_), scheme_dup_symbol_check (& r , ((void * ) 0 ) , v , "argument" , form ) ); 
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * lambda_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  Scheme_Object * args ; 
  PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(args, 0), PUSH(env, 1), PUSH(rec, 2), PUSH(form, 3)));
# define XfOrM21_COUNT (4)
# define SETUP_XfOrM21(x) SETUP(XfOrM21_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  args = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM21(_), lambda_check (form ) ); 
  args = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM21(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  args = (((Scheme_Type ) (((((long ) (args ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (args ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM21(_), scheme_stx_content (args ) )) ) -> u . pair_val . car ) ) ; 
  FUNCCALL(SETUP_XfOrM21(_), lambda_check_args (args , form , env ) ); 
  FUNCCALL_AGAIN(scheme_rec_add_certs (rec , drec , form ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_closure_compilation (env , form , rec , drec ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * lambda_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  Scheme_Object * args , * body , * fn ; 
  Scheme_Comp_Env * newenv ; 
  Scheme_Object * __funcarg23 = NULLED_OUT ; 
  Scheme_Object * __funcarg22 = NULLED_OUT ; 
  Scheme_Object * __funcarg21 = NULLED_OUT ; 
  Scheme_Object * __funcarg20 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSH(newenv, 0), PUSH(fn, 1), PUSH(erec, 2), PUSH(args, 3), PUSH(env, 4), PUSH(form, 5), PUSH(body, 6)));
# define XfOrM22_COUNT (7)
# define SETUP_XfOrM22(x) SETUP(XfOrM22_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  args = NULLED_OUT ; 
  body = NULLED_OUT ; 
  fn = NULLED_OUT ; 
  newenv = NULLED_OUT ; 
  if (erec [drec ] . observer ) {
#   define XfOrM26_COUNT (0+XfOrM22_COUNT)
#   define SETUP_XfOrM26(x) SETUP_XfOrM22(x)
    FUNCCALL(SETUP_XfOrM26(_), scheme_call_expand_observe (erec [drec ] . observer , 110 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  FUNCCALL(SETUP_XfOrM22(_), lambda_check (form ) ); 
  args = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM22(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  args = (((Scheme_Type ) (((((long ) (args ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (args ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM22(_), scheme_stx_content (args ) )) ) -> u . pair_val . car ) ) ; 
  FUNCCALL(SETUP_XfOrM22(_), lambda_check_args (args , form , env ) ); 
  FUNCCALL_AGAIN(scheme_rec_add_certs (erec , drec , form ) ); 
  newenv = FUNCCALL_AGAIN(scheme_add_compilation_frame (args , env , 0 , erec [drec ] . certs ) ); 
  body = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM22(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  body = (((Scheme_Type ) (((((long ) (body ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (body ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (body ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM22(_), scheme_stx_content (body ) )) ) -> u . pair_val . cdr ) ) ; 
  body = FUNCCALL(SETUP_XfOrM22(_), scheme_datum_to_syntax (body , form , form , 0 , 0 ) ); 
  body = FUNCCALL_AGAIN(scheme_add_env_renames (body , newenv , env ) ); 
  args = FUNCCALL_AGAIN(scheme_add_env_renames (args , newenv , env ) ); 
  if (erec [drec ] . observer ) {
#   define XfOrM24_COUNT (0+XfOrM22_COUNT)
#   define SETUP_XfOrM24(x) SETUP_XfOrM22(x)
    (__funcarg23 = FUNCCALL(SETUP_XfOrM24(_), scheme_make_immutable_pair (args , body ) ), FUNCCALL_AGAIN(scheme_call_expand_observe (erec [drec ] . observer , 17 , __funcarg23 ) )) ; 
  }
  else {
  }
  ; 
  fn = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM22(_), scheme_stx_content (form ) )) ) -> u . pair_val . car ) ) ; 
  RET_VALUE_START ((__funcarg20 = (__funcarg21 = (__funcarg22 = FUNCCALL(SETUP_XfOrM22(_), scheme_expand_block (body , newenv , erec , drec ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (args , __funcarg22 ) )) , FUNCCALL_AGAIN(scheme_make_immutable_pair (fn , __funcarg21 ) )) , FUNCCALL_EMPTY(scheme_datum_to_syntax (__funcarg20 , form , form , 0 , 2 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * expand_lam (int argc , Scheme_Object * * argv ) {
  Scheme_Object * form = argv [0 ] , * args , * fn ; 
  Scheme_Comp_Env * env ; 
  Scheme_Object * __funcarg25 = NULLED_OUT ; 
  Scheme_Object * __funcarg24 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(args, 0), PUSH(env, 1), PUSH(fn, 2), PUSH(form, 3)));
# define XfOrM27_COUNT (4)
# define SETUP_XfOrM27(x) SETUP(XfOrM27_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  args = NULLED_OUT ; 
  fn = NULLED_OUT ; 
  env = NULLED_OUT ; 
  env = scheme_current_thread -> current_local_env ; 
  FUNCCALL(SETUP_XfOrM27(_), lambda_check (form ) ); 
  args = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM27(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  args = (((Scheme_Type ) (((((long ) (args ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (args ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM27(_), scheme_stx_content (args ) )) ) -> u . pair_val . car ) ) ; 
  FUNCCALL(SETUP_XfOrM27(_), lambda_check_args (args , form , env ) ); 
  fn = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM27(_), scheme_stx_content (form ) )) ) -> u . pair_val . car ) ) ; 
  fn = (__funcarg25 = FUNCCALL(SETUP_XfOrM27(_), scheme_sys_wraps (env ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (lambda_symbol , fn , __funcarg25 , 0 , 0 ) )) ; 
  args = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM27(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  RET_VALUE_START ((__funcarg24 = FUNCCALL(SETUP_XfOrM27(_), scheme_make_immutable_pair (fn , args ) ), FUNCCALL_EMPTY(scheme_datum_to_syntax (__funcarg24 , form , fn , 0 , 0 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_set_global_bucket (char * who , Scheme_Bucket * b , Scheme_Object * val , int set_undef ) {
  Scheme_Config * __funcarg26 = NULLED_OUT ; 
  PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(b, 0), PUSH(val, 1), PUSH(who, 2)));
# define XfOrM28_COUNT (3)
# define SETUP_XfOrM28(x) SETUP(XfOrM28_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((b -> val || set_undef ) && ((b -> so . type != scheme_variable_type ) || ! (((Scheme_Bucket_With_Flags * ) b ) -> flags & 64 ) ) )
    b -> val = val ; 
  else {
#   define XfOrM29_COUNT (0+XfOrM28_COUNT)
#   define SETUP_XfOrM29(x) SETUP_XfOrM28(x)
    if (((Scheme_Bucket_With_Home * ) b ) -> home -> module ) {
      const char * msg ; 
      BLOCK_SETUP((PUSH(msg, 0+XfOrM29_COUNT)));
#     define XfOrM31_COUNT (1+XfOrM29_COUNT)
#     define SETUP_XfOrM31(x) SETUP(XfOrM31_COUNT)
      msg = NULLED_OUT ; 
      if ((! ((((__funcarg26 = FUNCCALL(SETUP_XfOrM31(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg26 , MZCONFIG_ERROR_PRINT_SRCLOC ) )) ) ) == (scheme_false ) ) ) )
        msg = "%s: cannot %s: %S in module: %S" ; 
      else msg = "%s: cannot %s: %S" ; 
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT_VARIABLE , b -> key , msg , who , (b -> val ? "change identifier that is instantiated as a module constant" : "set identifier before its definition" ) , (Scheme_Object * ) b -> key , ((Scheme_Bucket_With_Home * ) b ) -> home -> module -> modname ) ); 
    }
    else {
#     define XfOrM30_COUNT (0+XfOrM29_COUNT)
#     define SETUP_XfOrM30(x) SETUP_XfOrM29(x)
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT_VARIABLE , b -> key , "%s: cannot %s identifier: %S" , who , b -> val ? "change constant" : "set undefined" , (Scheme_Object * ) b -> key ) ); 
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_install_macro (Scheme_Bucket * b , Scheme_Object * v ) {
  Scheme_Object * macro ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(macro, 0), PUSH(v, 1), PUSH(b, 2)));
# define XfOrM32_COUNT (3)
# define SETUP_XfOrM32(x) SETUP(XfOrM32_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  macro = NULLED_OUT ; 
  macro = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM32(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  macro -> type = scheme_macro_type ; 
  (((Scheme_Small_Object * ) (macro ) ) -> u . ptr_val ) = v ; 
  b -> val = macro ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * define_execute (Scheme_Object * vec , int delta , int defmacro , Resolve_Prefix * rp , Scheme_Env * dm_env ) {
  Scheme_Object * name , * macro , * vals , * var ; 
  int i , g , show_any ; 
  Scheme_Bucket * b ; 
  Scheme_Object * * save_runstack = ((void * ) 0 ) ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(10);
  BLOCK_SETUP_TOP((PUSH(vals, 0), PUSH(save_runstack, 1), PUSH(name, 2), PUSH(vec, 3), PUSH(dm_env, 4), PUSH(macro, 5), PUSH(b, 6), PUSH(rp, 7), PUSH(var, 8)));
# define XfOrM33_COUNT (9)
# define SETUP_XfOrM33(x) SETUP(XfOrM33_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  name = NULLED_OUT ; 
  macro = NULLED_OUT ; 
  vals = NULLED_OUT ; 
  var = NULLED_OUT ; 
  b = NULLED_OUT ; 
  vals = (((Scheme_Vector * ) (vec ) ) -> els ) [0 ] ; 
  if (dm_env ) {
#   define XfOrM53_COUNT (0+XfOrM33_COUNT)
#   define SETUP_XfOrM53(x) SETUP_XfOrM33(x)
    FUNCCALL(SETUP_XfOrM53(_), scheme_prepare_exp_env (dm_env ) ); 
    save_runstack = FUNCCALL(SETUP_XfOrM53(_), scheme_push_prefix (dm_env -> exp_env , rp , ((void * ) 0 ) , ((void * ) 0 ) , 1 , 1 ) ); 
    vals = FUNCCALL_AGAIN(scheme_eval_linked_expr_multi (vals ) ); 
    if (defmacro == 2 )
      dm_env = ((void * ) 0 ) ; 
    else FUNCCALL(SETUP_XfOrM53(_), scheme_pop_prefix (save_runstack ) ); 
  }
  else {
#   define XfOrM52_COUNT (0+XfOrM33_COUNT)
#   define SETUP_XfOrM52(x) SETUP_XfOrM33(x)
    vals = FUNCCALL(SETUP_XfOrM52(_), scheme_do_eval (vals , - 1 , ((void * ) 0 ) , - 1 ) ); 
    dm_env = ((void * ) 0 ) ; 
  }
  if (((vals ) == (((Scheme_Object * ) 0x6 ) ) ) ) {
    Scheme_Object * * values ; 
    BLOCK_SETUP((PUSH(values, 0+XfOrM33_COUNT)));
#   define XfOrM42_COUNT (1+XfOrM33_COUNT)
#   define SETUP_XfOrM42(x) SETUP(XfOrM42_COUNT)
    values = NULLED_OUT ; 
    i = (((Scheme_Vector * ) (vec ) ) -> size ) - delta ; 
    g = scheme_current_thread -> ku . multiple . count ; 
    if (i == g ) {
#     define XfOrM43_COUNT (0+XfOrM42_COUNT)
#     define SETUP_XfOrM43(x) SETUP_XfOrM42(x)
      values = scheme_current_thread -> ku . multiple . array ; 
      scheme_current_thread -> ku . multiple . array = ((void * ) 0 ) ; 
      if (((values ) == (scheme_current_thread -> values_buffer ) ) )
        scheme_current_thread -> values_buffer = ((void * ) 0 ) ; 
      for (i = 0 ; i < g ; i ++ ) {
#       define XfOrM48_COUNT (0+XfOrM43_COUNT)
#       define SETUP_XfOrM48(x) SETUP_XfOrM43(x)
        var = (((Scheme_Vector * ) (vec ) ) -> els ) [i + delta ] ; 
        if (dm_env ) {
#         define XfOrM51_COUNT (0+XfOrM48_COUNT)
#         define SETUP_XfOrM51(x) SETUP_XfOrM48(x)
          b = FUNCCALL(SETUP_XfOrM51(_), scheme_global_keyword_bucket (var , dm_env ) ); 
          macro = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM51(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
          macro -> type = scheme_macro_type ; 
          (((Scheme_Small_Object * ) (macro ) ) -> u . ptr_val ) = values [i ] ; 
          FUNCCALL(SETUP_XfOrM51(_), scheme_set_global_bucket ("define-syntaxes" , b , macro , 1 ) ); 
          FUNCCALL_AGAIN(scheme_shadow (dm_env , (Scheme_Object * ) b -> key , 0 ) ); 
        }
        else {
          Scheme_Object * * toplevels ; 
#         define XfOrM49_COUNT (0+XfOrM48_COUNT)
#         define SETUP_XfOrM49(x) SETUP_XfOrM48(x)
          toplevels = NULLED_OUT ; 
          toplevels = (Scheme_Object * * ) scheme_current_runstack [(((Scheme_Toplevel * ) (var ) ) -> depth ) ] ; 
          b = (Scheme_Bucket * ) toplevels [(((Scheme_Toplevel * ) (var ) ) -> position ) ] ; 
          FUNCCALL(SETUP_XfOrM49(_), scheme_set_global_bucket ("define-values" , b , values [i ] , 1 ) ); 
          FUNCCALL_AGAIN(scheme_shadow (((Scheme_Bucket_With_Home * ) b ) -> home , (Scheme_Object * ) b -> key , 1 ) ); 
          if ((& ((Scheme_Toplevel * ) (var ) ) -> iso ) -> so . keyex & 0x1 ) {
            ((Scheme_Bucket_With_Flags * ) b ) -> flags |= 64 ; 
          }
        }
      }
      if (defmacro )
        FUNCCALL(SETUP_XfOrM43(_), scheme_pop_prefix (save_runstack ) ); 
      RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
    }
    if (((scheme_current_thread -> ku . multiple . array ) == (scheme_current_thread -> values_buffer ) ) )
      scheme_current_thread -> values_buffer = ((void * ) 0 ) ; 
  }
  else if ((((Scheme_Vector * ) (vec ) ) -> size ) == delta + 1 ) {
#   define XfOrM38_COUNT (0+XfOrM33_COUNT)
#   define SETUP_XfOrM38(x) SETUP_XfOrM33(x)
    var = (((Scheme_Vector * ) (vec ) ) -> els ) [delta ] ; 
    if (dm_env ) {
#     define XfOrM41_COUNT (0+XfOrM38_COUNT)
#     define SETUP_XfOrM41(x) SETUP_XfOrM38(x)
      b = FUNCCALL(SETUP_XfOrM41(_), scheme_global_keyword_bucket (var , dm_env ) ); 
      macro = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM41(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
      macro -> type = scheme_macro_type ; 
      (((Scheme_Small_Object * ) (macro ) ) -> u . ptr_val ) = vals ; 
      FUNCCALL(SETUP_XfOrM41(_), scheme_set_global_bucket ("define-syntaxes" , b , macro , 1 ) ); 
      FUNCCALL_AGAIN(scheme_shadow (dm_env , (Scheme_Object * ) b -> key , 0 ) ); 
    }
    else {
      Scheme_Object * * toplevels ; 
#     define XfOrM39_COUNT (0+XfOrM38_COUNT)
#     define SETUP_XfOrM39(x) SETUP_XfOrM38(x)
      toplevels = NULLED_OUT ; 
      toplevels = (Scheme_Object * * ) scheme_current_runstack [(((Scheme_Toplevel * ) (var ) ) -> depth ) ] ; 
      b = (Scheme_Bucket * ) toplevels [(((Scheme_Toplevel * ) (var ) ) -> position ) ] ; 
      FUNCCALL(SETUP_XfOrM39(_), scheme_set_global_bucket ("define-values" , b , vals , 1 ) ); 
      FUNCCALL_AGAIN(scheme_shadow (((Scheme_Bucket_With_Home * ) b ) -> home , (Scheme_Object * ) b -> key , 1 ) ); 
      if ((& ((Scheme_Toplevel * ) (var ) ) -> iso ) -> so . keyex & 0x1 ) {
        ((Scheme_Bucket_With_Flags * ) b ) -> flags |= 64 ; 
      }
      if (defmacro )
        FUNCCALL(SETUP_XfOrM39(_), scheme_pop_prefix (save_runstack ) ); 
    }
    RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
  }
  else g = 1 ; 
  if (dm_env && ! g )
    RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
  i = (((Scheme_Vector * ) (vec ) ) -> size ) - delta ; 
  show_any = i ; 
  if (show_any ) {
#   define XfOrM35_COUNT (0+XfOrM33_COUNT)
#   define SETUP_XfOrM35(x) SETUP_XfOrM33(x)
    var = (((Scheme_Vector * ) (vec ) ) -> els ) [delta ] ; 
    if (dm_env ) {
#     define XfOrM37_COUNT (0+XfOrM35_COUNT)
#     define SETUP_XfOrM37(x) SETUP_XfOrM35(x)
      b = FUNCCALL(SETUP_XfOrM37(_), scheme_global_keyword_bucket (var , dm_env ) ); 
      name = (Scheme_Object * ) b -> key ; 
    }
    else {
      Scheme_Object * * toplevels ; 
      toplevels = NULLED_OUT ; 
      toplevels = (Scheme_Object * * ) scheme_current_runstack [(((Scheme_Toplevel * ) (var ) ) -> depth ) ] ; 
      b = (Scheme_Bucket * ) toplevels [(((Scheme_Toplevel * ) (var ) ) -> position ) ] ; 
      name = (Scheme_Object * ) b -> key ; 
    }
  }
  else name = ((void * ) 0 ) ; 
  if (defmacro > 1 )
    FUNCCALL(SETUP_XfOrM33(_), scheme_pop_prefix (save_runstack ) ); 
  {
    const char * symname ; 
    BLOCK_SETUP((PUSH(symname, 0+XfOrM33_COUNT)));
#   define XfOrM34_COUNT (1+XfOrM33_COUNT)
#   define SETUP_XfOrM34(x) SETUP(XfOrM34_COUNT)
    symname = NULLED_OUT ; 
    symname = (show_any ? FUNCCALL(SETUP_XfOrM34(_), scheme_symbol_name (name ) ): "" ) ; 
    FUNCCALL_EMPTY(scheme_wrong_return_arity ((defmacro ? (dm_env ? "define-syntaxes" : "define-values-for-syntax" ) : "define-values" ) , i , g , (g == 1 ) ? (Scheme_Object * * ) vals : scheme_current_thread -> ku . multiple . array , "%s%s%s" , show_any ? "defining \"" : "0 names" , symname , show_any ? ((i == 1 ) ? "\"" : "\", ..." ) : "" ) ); 
  }
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * define_values_execute (Scheme_Object * data ) {
  /* No conversion */
  return define_execute (data , 1 , 0 , ((void * ) 0 ) , ((void * ) 0 ) ) ; 
}
static Scheme_Object * clone_vector (Scheme_Object * data , int skip ) {
  Scheme_Object * naya ; 
  int i , size ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(data, 0), PUSH(naya, 1)));
# define XfOrM55_COUNT (2)
# define SETUP_XfOrM55(x) SETUP(XfOrM55_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  naya = NULLED_OUT ; 
  size = (((Scheme_Vector * ) (data ) ) -> size ) ; 
  naya = FUNCCALL(SETUP_XfOrM55(_), scheme_make_vector (size - skip , ((void * ) 0 ) ) ); 
  for (i = skip ; i < size ; i ++ ) {
    (((Scheme_Vector * ) (naya ) ) -> els ) [i - skip ] = (((Scheme_Vector * ) (data ) ) -> els ) [i ] ; 
  }
  RET_VALUE_START (naya ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * define_values_jit (Scheme_Object * data ) {
  Scheme_Object * orig = (((Scheme_Vector * ) (data ) ) -> els ) [0 ] , * naya ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(naya, 0), PUSH(data, 1), PUSH(orig, 2)));
# define XfOrM58_COUNT (3)
# define SETUP_XfOrM58(x) SETUP(XfOrM58_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  naya = NULLED_OUT ; 
  if (((Scheme_Type ) (((((long ) (orig ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (orig ) ) -> type ) ) == (Scheme_Type ) (scheme_unclosed_procedure_type ) ) && ((((Scheme_Vector * ) (data ) ) -> size ) == 2 ) )
    naya = FUNCCALL(SETUP_XfOrM58(_), scheme_jit_closure (orig , (((Scheme_Vector * ) (data ) ) -> els ) [1 ] ) ); 
  else naya = FUNCCALL(SETUP_XfOrM58(_), scheme_jit_expr (orig ) ); 
  if (((naya ) == (orig ) ) )
    RET_VALUE_START (data ) RET_VALUE_END ; 
  else {
#   define XfOrM59_COUNT (0+XfOrM58_COUNT)
#   define SETUP_XfOrM59(x) SETUP_XfOrM58(x)
    orig = naya ; 
    naya = FUNCCALL(SETUP_XfOrM59(_), clone_vector (data , 0 ) ); 
    (((Scheme_Vector * ) (naya ) ) -> els ) [0 ] = orig ; 
    RET_VALUE_START (naya ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void define_values_validate (Scheme_Object * data , Mz_CPort * port , char * stack , Scheme_Hash_Table * ht , Scheme_Object * * tls , int depth , int letlimit , int delta , int num_toplevels , int num_stxes , int num_lifts ) {
  int i , size ; 
  Scheme_Object * val , * only_var ; 
  PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(tls, 0), PUSH(only_var, 1), PUSH(ht, 2), PUSH(data, 3), PUSH(val, 4), PUSH(port, 5), PUSH(stack, 6)));
# define XfOrM60_COUNT (7)
# define SETUP_XfOrM60(x) SETUP(XfOrM60_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  val = NULLED_OUT ; 
  only_var = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (data ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (data ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) )
    FUNCCALL(SETUP_XfOrM60(_), scheme_ill_formed (port , "./../src/syntax.c" , 851 ) ); 
  val = (((Scheme_Vector * ) (data ) ) -> els ) [0 ] ; 
  size = (((Scheme_Vector * ) (data ) ) -> size ) ; 
  if (size == 2 )
    only_var = (((Scheme_Vector * ) (data ) ) -> els ) [1 ] ; 
  else only_var = ((void * ) 0 ) ; 
  for (i = 1 ; i < size ; i ++ ) {
#   define XfOrM69_COUNT (0+XfOrM60_COUNT)
#   define SETUP_XfOrM69(x) SETUP_XfOrM60(x)
    FUNCCALL(SETUP_XfOrM69(_), scheme_validate_toplevel ((((Scheme_Vector * ) (data ) ) -> els ) [i ] , port , stack , ht , tls , depth , delta , num_toplevels , num_stxes , num_lifts , 1 ) ); 
  }
  if (only_var ) {
    int pos ; 
#   define XfOrM61_COUNT (0+XfOrM60_COUNT)
#   define SETUP_XfOrM61(x) SETUP_XfOrM60(x)
    pos = (((Scheme_Toplevel * ) (only_var ) ) -> position ) ; 
    if (pos >= (num_toplevels + num_stxes + (num_stxes ? 1 : 0 ) ) ) {
      int tp = pos - (num_stxes + (num_stxes ? 1 : 0 ) ) ; 
      Scheme_Object * vec ; 
      BLOCK_SETUP((PUSH(vec, 0+XfOrM61_COUNT)));
#     define XfOrM62_COUNT (1+XfOrM61_COUNT)
#     define SETUP_XfOrM62(x) SETUP(XfOrM62_COUNT)
      vec = NULLED_OUT ; 
      vec = tls [tp ] ; 
      if (vec && ! ((Scheme_Type ) (((((long ) (vec ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vec ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) && ! (((vec ) ) == (scheme_false ) ) )
        FUNCCALL(SETUP_XfOrM62(_), scheme_ill_formed (port , "./../src/syntax.c" , 878 ) ); 
      if (((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) || (((val ) ) == (scheme_false ) ) )
        tls [tp ] = scheme_true ; 
      else tls [tp ] = val ; 
      if (vec && ((Scheme_Type ) (((((long ) (vec ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vec ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
        int i ; 
#       define XfOrM63_COUNT (0+XfOrM62_COUNT)
#       define SETUP_XfOrM63(x) SETUP_XfOrM62(x)
        for (i = (((Scheme_Vector * ) (vec ) ) -> size ) ; i -- ; ) {
#         define XfOrM66_COUNT (0+XfOrM63_COUNT)
#         define SETUP_XfOrM66(x) SETUP_XfOrM63(x)
          if (! (((((Scheme_Vector * ) (vec ) ) -> els ) [i ] ) == (scheme_null ) ) ) {
#           define XfOrM67_COUNT (0+XfOrM66_COUNT)
#           define SETUP_XfOrM67(x) SETUP_XfOrM66(x)
            FUNCCALL(SETUP_XfOrM67(_), scheme_validate_rator_wants_box (val , i , (! ((((((Scheme_Vector * ) (vec ) ) -> els ) [i ] ) ) == (scheme_false ) ) ) , tls , num_toplevels , num_stxes , num_lifts ) ); 
          }
        }
      }
    }
    else only_var = ((void * ) 0 ) ; 
  }
  FUNCCALL_EMPTY(scheme_validate_expr (port , val , stack , ht , tls , depth , letlimit , delta , num_toplevels , num_stxes , num_lifts , ((void * ) 0 ) , ! ! only_var ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * define_values_optimize (Scheme_Object * data , Optimize_Info * info ) {
  Scheme_Object * vars = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) ; 
  Scheme_Object * val = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ; 
  Scheme_Object * __funcarg27 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(val, 0), PUSH(vars, 1), PUSH(info, 2)));
# define XfOrM70_COUNT (3)
# define SETUP_XfOrM70(x) SETUP(XfOrM70_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM70(_), scheme_optimize_info_used_top (info ) ); 
  val = FUNCCALL(SETUP_XfOrM70(_), scheme_optimize_expr (val , info ) ); 
  RET_VALUE_START ((__funcarg27 = FUNCCALL_EMPTY(scheme_make_pair (vars , val ) ), FUNCCALL_EMPTY(scheme_make_syntax_compiled (0 , __funcarg27 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * define_values_resolve (Scheme_Object * data , Resolve_Info * rslv ) {
  long cnt = 0 ; 
  Scheme_Object * vars = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) , * l , * a ; 
  Scheme_Object * val = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) , * vec ; 
  PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(vars, 0), PUSH(rslv, 1), PUSH(a, 2), PUSH(vec, 3), PUSH(val, 4), PUSH(l, 5)));
# define XfOrM71_COUNT (6)
# define SETUP_XfOrM71(x) SETUP(XfOrM71_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  l = NULLED_OUT ; 
  a = NULLED_OUT ; 
  vec = NULLED_OUT ; 
  for (l = vars ; ! ((l ) == (scheme_null ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#   define XfOrM76_COUNT (0+XfOrM71_COUNT)
#   define SETUP_XfOrM76(x) SETUP_XfOrM71(x)
    a = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
    if (rslv -> in_module && rslv -> enforce_const && (! ((& ((Scheme_Toplevel * ) (a ) ) -> iso ) -> so . keyex & 0x2 ) ) ) {
#     define XfOrM77_COUNT (0+XfOrM76_COUNT)
#     define SETUP_XfOrM77(x) SETUP_XfOrM76(x)
      a = FUNCCALL(SETUP_XfOrM77(_), scheme_toplevel_to_flagged_toplevel (a , 0x1 ) ); 
    }
    a = FUNCCALL(SETUP_XfOrM76(_), scheme_resolve_toplevel (rslv , a ) ); 
    (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) = a ; 
    cnt ++ ; 
  }
  vec = FUNCCALL(SETUP_XfOrM71(_), scheme_make_vector (cnt + 1 , ((void * ) 0 ) ) ); 
  cnt = 1 ; 
  for (l = vars ; ! ((l ) == (scheme_null ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
    (((Scheme_Vector * ) (vec ) ) -> els ) [cnt ++ ] = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
  }
  val = FUNCCALL(SETUP_XfOrM71(_), scheme_resolve_expr (val , rslv ) ); 
  (((Scheme_Vector * ) (vec ) ) -> els ) [0 ] = val ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_syntax_resolved (0 , vec ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_resolve_lift_definition (Resolve_Info * info , Scheme_Object * var , Scheme_Object * rhs ) {
  Scheme_Object * decl , * vec , * pr ; 
  PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(decl, 0), PUSH(info, 1), PUSH(rhs, 2), PUSH(vec, 3), PUSH(pr, 4), PUSH(var, 5)));
# define XfOrM78_COUNT (6)
# define SETUP_XfOrM78(x) SETUP(XfOrM78_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  decl = NULLED_OUT ; 
  vec = NULLED_OUT ; 
  pr = NULLED_OUT ; 
  vec = FUNCCALL(SETUP_XfOrM78(_), scheme_make_vector (2 , ((void * ) 0 ) ) ); 
  (((Scheme_Vector * ) (vec ) ) -> els ) [0 ] = rhs ; 
  (((Scheme_Vector * ) (vec ) ) -> els ) [1 ] = var ; 
  decl = FUNCCALL(SETUP_XfOrM78(_), scheme_make_syntax_resolved (0 , vec ) ); 
  vec = info -> lifts ; 
  pr = FUNCCALL(SETUP_XfOrM78(_), scheme_make_pair (decl , (((Scheme_Vector * ) (vec ) ) -> els ) [0 ] ) ); 
  (((Scheme_Vector * ) (vec ) ) -> els ) [0 ] = pr ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_define_parse (Scheme_Object * form , Scheme_Object * * var , Scheme_Object * * _stk_val , int defmacro , Scheme_Comp_Env * env , int no_toplevel_check ) {
  Scheme_Object * vars , * rest ; 
  int len ; 
  DupCheckRecord r ; 
  PREPARE_VAR_STACK(11);
  BLOCK_SETUP_TOP((PUSH(_stk_val, 0), PUSH(env, 1), PUSHARRAY(r.syms, 5, 2), PUSH(r.ht, 5), PUSH(var, 6), PUSH(vars, 7), PUSH(form, 8), PUSH(rest, 9)));
# define XfOrM79_COUNT (10)
# define SETUP_XfOrM79(x) SETUP(XfOrM79_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  vars = NULLED_OUT ; 
  rest = NULLED_OUT ; 
  NULL_OUT_ARRAY (r.syms ) ; 
  r.ht = NULLED_OUT ; 
  if (! no_toplevel_check && ! FUNCCALL(SETUP_XfOrM79(_), scheme_is_toplevel (env ) ))
    FUNCCALL(SETUP_XfOrM79(_), scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , form , "illegal use (not at top-level)" ) ); 
  len = FUNCCALL(SETUP_XfOrM79(_), check_form (form , form ) ); 
  if (len != 3 )
    FUNCCALL(SETUP_XfOrM79(_), bad_form (form , len ) ); 
  rest = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM79(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  vars = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM79(_), scheme_stx_content (rest ) )) ) -> u . pair_val . car ) ) ; 
  rest = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM79(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ; 
  * _stk_val = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM79(_), scheme_stx_content (rest ) )) ) -> u . pair_val . car ) ) ; 
  * var = vars ; 
  FUNCCALL(SETUP_XfOrM79(_), scheme_begin_dup_symbol_check (& r , env ) ); 
  while ((((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) vars ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) vars ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
    Scheme_Object * name ; 
    BLOCK_SETUP((PUSH(name, 0+XfOrM79_COUNT)));
#   define XfOrM81_COUNT (1+XfOrM79_COUNT)
#   define SETUP_XfOrM81(x) SETUP(XfOrM81_COUNT)
    name = NULLED_OUT ; 
    name = (((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (vars ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM81(_), scheme_stx_content (vars ) )) ) -> u . pair_val . car ) ) ; 
    FUNCCALL(SETUP_XfOrM81(_), scheme_check_identifier (((void * ) 0 ) , name , ((void * ) 0 ) , env , form ) ); 
    vars = (((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (vars ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM81(_), scheme_stx_content (vars ) )) ) -> u . pair_val . cdr ) ) ; 
    FUNCCALL(SETUP_XfOrM81(_), scheme_dup_symbol_check (& r , ((void * ) 0 ) , name , "binding" , form ) ); 
  }
  if (! (((vars ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) vars ) -> val ) == (scheme_null ) ) ) ) )
    FUNCCALL(SETUP_XfOrM79(_), scheme_wrong_syntax (((void * ) 0 ) , * var , form , "bad variable list" ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * defn_targets_syntax (Scheme_Object * var , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  Scheme_Object * first = scheme_null , * last = ((void * ) 0 ) ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(first, 0), PUSH(last, 1), PUSH(env, 2), PUSH(var, 3), PUSH(rec, 4)));
# define XfOrM82_COUNT (5)
# define SETUP_XfOrM82(x) SETUP(XfOrM82_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  while ((((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) var ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) var ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
    Scheme_Object * name , * pr , * bucket ; 
    BLOCK_SETUP((PUSH(bucket, 0+XfOrM82_COUNT), PUSH(pr, 1+XfOrM82_COUNT), PUSH(name, 2+XfOrM82_COUNT)));
#   define XfOrM86_COUNT (3+XfOrM82_COUNT)
#   define SETUP_XfOrM86(x) SETUP(XfOrM86_COUNT)
    name = NULLED_OUT ; 
    pr = NULLED_OUT ; 
    bucket = NULLED_OUT ; 
    name = (((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (var ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM86(_), scheme_stx_content (var ) )) ) -> u . pair_val . car ) ) ; 
    name = FUNCCALL(SETUP_XfOrM86(_), scheme_tl_id_sym (env -> genv , name , ((void * ) 0 ) , 2 ) ); 
    if (rec [drec ] . resolve_module_ids || ! env -> genv -> module ) {
#     define XfOrM88_COUNT (0+XfOrM86_COUNT)
#     define SETUP_XfOrM88(x) SETUP_XfOrM86(x)
      bucket = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM88(_), scheme_global_bucket (name , env -> genv ) ); 
    }
    else {
#     define XfOrM87_COUNT (0+XfOrM86_COUNT)
#     define SETUP_XfOrM87(x) SETUP_XfOrM86(x)
      bucket = FUNCCALL(SETUP_XfOrM87(_), scheme_hash_module_variable (env -> genv , env -> genv -> module -> self_modidx , name , env -> genv -> module -> insp , - 1 , env -> genv -> mod_phase ) ); 
    }
    bucket = FUNCCALL(SETUP_XfOrM86(_), scheme_register_toplevel_in_prefix (bucket , env , rec , drec ) ); 
    pr = FUNCCALL(SETUP_XfOrM86(_), scheme_make_pair (bucket , scheme_null ) ); 
    if (last )
      (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = pr ; 
    else first = pr ; 
    last = pr ; 
    var = (((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (var ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM86(_), scheme_stx_content (var ) )) ) -> u . pair_val . cdr ) ) ; 
  }
  RET_VALUE_START (first ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * define_values_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  Scheme_Object * var , * val , * targets , * variables ; 
  Scheme_Object * __funcarg28 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSH(targets, 0), PUSH(rec, 1), PUSH(val, 2), PUSH(env, 3), PUSH(var, 4), PUSH(form, 5), PUSH(variables, 6)));
# define XfOrM89_COUNT (7)
# define SETUP_XfOrM89(x) SETUP(XfOrM89_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  var = NULLED_OUT ; 
  val = NULLED_OUT ; 
  targets = NULLED_OUT ; 
  variables = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM89(_), scheme_define_parse (form , & var , & val , 0 , env , 0 ) ); 
  variables = var ; 
  targets = FUNCCALL(SETUP_XfOrM89(_), defn_targets_syntax (var , env , rec , drec ) ); 
  FUNCCALL_AGAIN(scheme_compile_rec_done_local (rec , drec ) ); 
  if ((((Scheme_Type ) (((((long ) (targets ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (targets ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (targets ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (targets ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) targets ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) targets ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) && ((((((Scheme_Type ) (((((long ) (targets ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (targets ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (targets ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM89(_), scheme_stx_content (targets ) )) ) -> u . pair_val . cdr ) ) ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) ((((Scheme_Type ) (((((long ) (targets ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (targets ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (targets ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM89(_), scheme_stx_content (targets ) )) ) -> u . pair_val . cdr ) ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Type ) (((((long ) (targets ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (targets ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (targets ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM89(_), scheme_stx_content (targets ) )) ) -> u . pair_val . cdr ) ) ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (targets ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (targets ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (targets ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM89(_), scheme_stx_content (targets ) )) ) -> u . pair_val . cdr ) ) ) -> val ) == (scheme_null ) ) ) ) ) {
#   define XfOrM90_COUNT (0+XfOrM89_COUNT)
#   define SETUP_XfOrM90(x) SETUP_XfOrM89(x)
    var = (((Scheme_Type ) (((((long ) (variables ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (variables ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (variables ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM90(_), scheme_stx_content (variables ) )) ) -> u . pair_val . car ) ) ; 
    rec [drec ] . value_name = (((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ? ((Scheme_Stx * ) var ) -> val : var ) ; 
  }
  env = FUNCCALL(SETUP_XfOrM89(_), scheme_no_defines (env ) ); 
  FUNCCALL(SETUP_XfOrM89(_), scheme_rec_add_certs (rec , drec , form ) ); 
  val = FUNCCALL_AGAIN(scheme_compile_expr (val , env , rec , drec ) ); 
  RET_VALUE_START ((__funcarg28 = FUNCCALL(SETUP_XfOrM89(_), scheme_make_pair (targets , val ) ), FUNCCALL_AGAIN(scheme_make_syntax_compiled (0 , __funcarg28 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * define_values_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  Scheme_Object * var , * val , * fn , * boundname ; 
  Scheme_Object * __funcarg32 = NULLED_OUT ; 
  Scheme_Object * __funcarg31 = NULLED_OUT ; 
  Scheme_Object * __funcarg30 = NULLED_OUT ; 
  Scheme_Object * __funcarg29 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSH(val, 0), PUSH(env, 1), PUSH(var, 2), PUSH(erec, 3), PUSH(boundname, 4), PUSH(form, 5), PUSH(fn, 6)));
# define XfOrM91_COUNT (7)
# define SETUP_XfOrM91(x) SETUP(XfOrM91_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  var = NULLED_OUT ; 
  val = NULLED_OUT ; 
  fn = NULLED_OUT ; 
  boundname = NULLED_OUT ; 
  if (erec [drec ] . observer ) {
#   define XfOrM93_COUNT (0+XfOrM91_COUNT)
#   define SETUP_XfOrM93(x) SETUP_XfOrM91(x)
    FUNCCALL(SETUP_XfOrM93(_), scheme_call_expand_observe (erec [drec ] . observer , 104 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  FUNCCALL(SETUP_XfOrM91(_), scheme_define_parse (form , & var , & val , 0 , env , 0 ) ); 
  env = FUNCCALL_AGAIN(scheme_no_defines (env ) ); 
  if ((((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) var ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) var ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) && ((((((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (var ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM91(_), scheme_stx_content (var ) )) ) -> u . pair_val . cdr ) ) ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) ((((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (var ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM91(_), scheme_stx_content (var ) )) ) -> u . pair_val . cdr ) ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (var ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM91(_), scheme_stx_content (var ) )) ) -> u . pair_val . cdr ) ) ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (var ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM91(_), scheme_stx_content (var ) )) ) -> u . pair_val . cdr ) ) ) -> val ) == (scheme_null ) ) ) ) )
    boundname = (((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (var ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM91(_), scheme_stx_content (var ) )) ) -> u . pair_val . car ) ) ; 
  else boundname = scheme_false ; 
  erec [drec ] . value_name = boundname ; 
  FUNCCALL(SETUP_XfOrM91(_), scheme_rec_add_certs (erec , drec , form ) ); 
  fn = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM91(_), scheme_stx_content (form ) )) ) -> u . pair_val . car ) ) ; 
  RET_VALUE_START ((__funcarg29 = (__funcarg30 = (__funcarg31 = (__funcarg32 = FUNCCALL(SETUP_XfOrM91(_), scheme_expand_expr (val , env , erec , drec ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (__funcarg32 , scheme_null ) )) , FUNCCALL_AGAIN(scheme_make_immutable_pair (var , __funcarg31 ) )) , FUNCCALL_AGAIN(scheme_make_immutable_pair (fn , __funcarg30 ) )) , FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg29 , form , form , 0 , 2 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * quote_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  Scheme_Object * v , * rest ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(rest, 1), PUSH(rec, 2), PUSH(form, 3)));
# define XfOrM94_COUNT (4)
# define SETUP_XfOrM94(x) SETUP(XfOrM94_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  rest = NULLED_OUT ; 
  rest = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM94(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  if (! ((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) rest ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) rest ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) && ((((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM94(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) ((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM94(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM94(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM94(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) -> val ) == (scheme_null ) ) ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , form , "bad syntax (wrong number of parts)" ) ); 
  FUNCCALL(SETUP_XfOrM94(_), scheme_compile_rec_done_local (rec , drec ) ); 
  FUNCCALL_AGAIN(scheme_default_compile_rec (rec , drec ) ); 
  v = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM94(_), scheme_stx_content (rest ) )) ) -> u . pair_val . car ) ) ; 
  if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_syntax_to_datum (v , 0 , ((void * ) 0 ) ) )) RET_VALUE_EMPTY_END ; 
  else RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * quote_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  Scheme_Object * rest ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(form, 0), PUSH(rest, 1)));
# define XfOrM95_COUNT (2)
# define SETUP_XfOrM95(x) SETUP(XfOrM95_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  rest = NULLED_OUT ; 
  if (erec [drec ] . observer ) {
#   define XfOrM97_COUNT (0+XfOrM95_COUNT)
#   define SETUP_XfOrM97(x) SETUP_XfOrM95(x)
    FUNCCALL(SETUP_XfOrM97(_), scheme_call_expand_observe (erec [drec ] . observer , 117 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  rest = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM95(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  if (! ((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) rest ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) rest ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) && ((((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM95(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) ((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM95(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM95(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM95(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) -> val ) == (scheme_null ) ) ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , form , "bad syntax (wrong number of parts)" ) ); 
  RET_VALUE_START (form ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * if_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  int len , opt ; 
  Scheme_Object * test , * thenp , * elsep , * name , * rest ; 
  Scheme_Compile_Info recs [3 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(17);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(rec, 1), PUSH(name, 2), PUSH(thenp, 3), PUSH(recs[0].value_name, 4), PUSH(recs[0].certs, 5), PUSH(recs[0].observer, 6), PUSH(recs[1].value_name, 7), PUSH(recs[1].certs, 8), PUSH(recs[1].observer, 9), PUSH(recs[2].value_name, 10), PUSH(recs[2].certs, 11), PUSH(recs[2].observer, 12), PUSH(test, 13), PUSH(elsep, 14), PUSH(form, 15), PUSH(rest, 16)));
# define XfOrM98_COUNT (17)
# define SETUP_XfOrM98(x) SETUP(XfOrM98_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  test = NULLED_OUT ; 
  thenp = NULLED_OUT ; 
  elsep = NULLED_OUT ; 
  name = NULLED_OUT ; 
  rest = NULLED_OUT ; 
  recs[0].value_name = NULLED_OUT ; 
  recs[0].certs = NULLED_OUT ; 
  recs[0].observer = NULLED_OUT ; 
  recs[1].value_name = NULLED_OUT ; 
  recs[1].certs = NULLED_OUT ; 
  recs[1].observer = NULLED_OUT ; 
  recs[2].value_name = NULLED_OUT ; 
  recs[2].certs = NULLED_OUT ; 
  recs[2].observer = NULLED_OUT ; 
  len = FUNCCALL(SETUP_XfOrM98(_), check_form (form , form ) ); 
  if (! (((len == 3 ) || (len == 4 ) ) ) )
    FUNCCALL(SETUP_XfOrM98(_), bad_form (form , len ) ); 
  name = rec [drec ] . value_name ; 
  FUNCCALL(SETUP_XfOrM98(_), scheme_compile_rec_done_local (rec , drec ) ); 
  name = FUNCCALL_AGAIN(scheme_check_name_property (form , name ) ); 
  rest = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM98(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  test = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM98(_), scheme_stx_content (rest ) )) ) -> u . pair_val . car ) ) ; 
  rest = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM98(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ; 
  thenp = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM98(_), scheme_stx_content (rest ) )) ) -> u . pair_val . car ) ) ; 
  if (len == 4 ) {
#   define XfOrM104_COUNT (0+XfOrM98_COUNT)
#   define SETUP_XfOrM104(x) SETUP_XfOrM98(x)
    rest = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM104(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ; 
    elsep = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM104(_), scheme_stx_content (rest ) )) ) -> u . pair_val . car ) ) ; 
  }
  else elsep = FUNCCALL(SETUP_XfOrM98(_), scheme_compiled_void () ); 
  FUNCCALL(SETUP_XfOrM98(_), scheme_rec_add_certs (rec , drec , form ) ); 
  FUNCCALL_AGAIN(scheme_init_compile_recs (rec , drec , recs , 3 ) ); 
  recs [1 ] . value_name = name ; 
  recs [2 ] . value_name = name ; 
  env = FUNCCALL(SETUP_XfOrM98(_), scheme_no_defines (env ) ); 
  test = FUNCCALL_AGAIN(scheme_compile_expr (test , env , recs , 0 ) ); 
  if (((((long ) (test ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (test ) ) -> type ) > _scheme_compiled_values_types_ ) {
#   define XfOrM100_COUNT (0+XfOrM98_COUNT)
#   define SETUP_XfOrM100(x) SETUP_XfOrM98(x)
    opt = 1 ; 
    if ((((test ) ) == (scheme_false ) ) ) {
#     define XfOrM103_COUNT (0+XfOrM100_COUNT)
#     define SETUP_XfOrM103(x) SETUP_XfOrM100(x)
      recs [2 ] . dont_mark_local_use = 1 ; 
      FUNCCALL(SETUP_XfOrM103(_), scheme_compile_expr (thenp , env , recs , 2 ) ); 
      if (len == 4 )
        test = FUNCCALL(SETUP_XfOrM103(_), scheme_compile_expr (elsep , env , recs , 1 ) ); 
      else test = elsep ; 
    }
    else {
#     define XfOrM101_COUNT (0+XfOrM100_COUNT)
#     define SETUP_XfOrM101(x) SETUP_XfOrM100(x)
      if (len == 4 ) {
#       define XfOrM102_COUNT (0+XfOrM101_COUNT)
#       define SETUP_XfOrM102(x) SETUP_XfOrM101(x)
        recs [2 ] . dont_mark_local_use = 1 ; 
        FUNCCALL(SETUP_XfOrM102(_), scheme_compile_expr (elsep , env , recs , 2 ) ); 
      }
      test = FUNCCALL(SETUP_XfOrM101(_), scheme_compile_expr (thenp , env , recs , 1 ) ); 
    }
  }
  else {
#   define XfOrM99_COUNT (0+XfOrM98_COUNT)
#   define SETUP_XfOrM99(x) SETUP_XfOrM98(x)
    opt = 0 ; 
    thenp = FUNCCALL(SETUP_XfOrM99(_), scheme_compile_expr (thenp , env , recs , 1 ) ); 
    if (len == 4 )
      elsep = FUNCCALL(SETUP_XfOrM99(_), scheme_compile_expr (elsep , env , recs , 2 ) ); 
  }
  FUNCCALL(SETUP_XfOrM98(_), scheme_merge_compile_recs (rec , drec , recs , (opt || (len == 3 ) ) ? 2 : 3 ) ); 
  if (opt )
    RET_VALUE_START (test ) RET_VALUE_END ; 
  else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_branch (test , thenp , elsep ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * if_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  Scheme_Object * test , * rest , * thenp , * elsep , * fn , * boundname ; 
  int len ; 
  Scheme_Expand_Info recs [3 ] ; 
  Scheme_Object * __funcarg34 = NULLED_OUT ; 
  Scheme_Object * __funcarg33 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(18);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(erec, 1), PUSH(rest, 2), PUSH(recs[0].value_name, 3), PUSH(recs[0].certs, 4), PUSH(recs[0].observer, 5), PUSH(recs[1].value_name, 6), PUSH(recs[1].certs, 7), PUSH(recs[1].observer, 8), PUSH(recs[2].value_name, 9), PUSH(recs[2].certs, 10), PUSH(recs[2].observer, 11), PUSH(test, 12), PUSH(thenp, 13), PUSH(boundname, 14), PUSH(fn, 15), PUSH(form, 16), PUSH(elsep, 17)));
# define XfOrM105_COUNT (18)
# define SETUP_XfOrM105(x) SETUP(XfOrM105_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  test = NULLED_OUT ; 
  rest = NULLED_OUT ; 
  thenp = NULLED_OUT ; 
  elsep = NULLED_OUT ; 
  fn = NULLED_OUT ; 
  boundname = NULLED_OUT ; 
  recs[0].value_name = NULLED_OUT ; 
  recs[0].certs = NULLED_OUT ; 
  recs[0].observer = NULLED_OUT ; 
  recs[1].value_name = NULLED_OUT ; 
  recs[1].certs = NULLED_OUT ; 
  recs[1].observer = NULLED_OUT ; 
  recs[2].value_name = NULLED_OUT ; 
  recs[2].certs = NULLED_OUT ; 
  recs[2].observer = NULLED_OUT ; 
  if (erec [drec ] . observer ) {
#   define XfOrM116_COUNT (0+XfOrM105_COUNT)
#   define SETUP_XfOrM116(x) SETUP_XfOrM105(x)
    FUNCCALL(SETUP_XfOrM116(_), scheme_call_expand_observe (erec [drec ] . observer , 105 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  len = FUNCCALL(SETUP_XfOrM105(_), check_form (form , form ) ); 
  if (! (((len == 3 ) || (len == 4 ) ) ) )
    FUNCCALL(SETUP_XfOrM105(_), bad_form (form , len ) ); 
  if (len == 3 ) {
#   define XfOrM112_COUNT (0+XfOrM105_COUNT)
#   define SETUP_XfOrM112(x) SETUP_XfOrM105(x)
    if (erec [drec ] . observer ) {
#     define XfOrM114_COUNT (0+XfOrM112_COUNT)
#     define SETUP_XfOrM114(x) SETUP_XfOrM112(x)
      FUNCCALL(SETUP_XfOrM114(_), scheme_call_expand_observe (erec [drec ] . observer , 13 , ((void * ) 0 ) ) ); 
    }
    else {
    }
    ; 
  }
  env = FUNCCALL(SETUP_XfOrM105(_), scheme_no_defines (env ) ); 
  boundname = FUNCCALL(SETUP_XfOrM105(_), scheme_check_name_property (form , erec [drec ] . value_name ) ); 
  FUNCCALL_AGAIN(scheme_rec_add_certs (erec , drec , form ) ); 
  FUNCCALL_AGAIN(scheme_init_expand_recs (erec , drec , recs , 3 ) ); 
  recs [0 ] . value_name = scheme_false ; 
  recs [1 ] . value_name = boundname ; 
  recs [2 ] . value_name = boundname ; 
  rest = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM105(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  test = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM105(_), scheme_stx_content (rest ) )) ) -> u . pair_val . car ) ) ; 
  test = FUNCCALL(SETUP_XfOrM105(_), scheme_expand_expr (test , env , recs , 0 ) ); 
  if (erec [drec ] . observer ) {
#   define XfOrM111_COUNT (0+XfOrM105_COUNT)
#   define SETUP_XfOrM111(x) SETUP_XfOrM105(x)
    FUNCCALL(SETUP_XfOrM111(_), scheme_call_expand_observe (erec [drec ] . observer , 3 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  rest = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM105(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ; 
  thenp = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM105(_), scheme_stx_content (rest ) )) ) -> u . pair_val . car ) ) ; 
  thenp = FUNCCALL(SETUP_XfOrM105(_), scheme_expand_expr (thenp , env , recs , 1 ) ); 
  rest = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM105(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ; 
  if (! (((rest ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) rest ) -> val ) == (scheme_null ) ) ) ) ) {
#   define XfOrM107_COUNT (0+XfOrM105_COUNT)
#   define SETUP_XfOrM107(x) SETUP_XfOrM105(x)
    if (erec [drec ] . observer ) {
#     define XfOrM109_COUNT (0+XfOrM107_COUNT)
#     define SETUP_XfOrM109(x) SETUP_XfOrM107(x)
      FUNCCALL(SETUP_XfOrM109(_), scheme_call_expand_observe (erec [drec ] . observer , 3 , ((void * ) 0 ) ) ); 
    }
    else {
    }
    ; 
    elsep = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM107(_), scheme_stx_content (rest ) )) ) -> u . pair_val . car ) ) ; 
    elsep = FUNCCALL(SETUP_XfOrM107(_), scheme_expand_expr (elsep , env , recs , 2 ) ); 
    rest = FUNCCALL_AGAIN(scheme_make_immutable_pair (elsep , scheme_null ) ); 
  }
  else {
    rest = scheme_null ; 
  }
  rest = FUNCCALL(SETUP_XfOrM105(_), scheme_make_immutable_pair (thenp , rest ) ); 
  fn = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM105(_), scheme_stx_content (form ) )) ) -> u . pair_val . car ) ) ; 
  RET_VALUE_START ((__funcarg33 = (__funcarg34 = FUNCCALL(SETUP_XfOrM105(_), scheme_make_immutable_pair (test , rest ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (fn , __funcarg34 ) )) , FUNCCALL_EMPTY(scheme_datum_to_syntax (__funcarg33 , form , form , 0 , 2 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * with_cont_mark_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  Scheme_Object * key , * val , * expr , * name , * orig_form = form ; 
  Scheme_Compile_Info recs [3 ] ; 
  Scheme_With_Continuation_Mark * wcm ; 
  int len ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(18);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(expr, 1), PUSH(rec, 2), PUSH(name, 3), PUSH(wcm, 4), PUSH(recs[0].value_name, 5), PUSH(recs[0].certs, 6), PUSH(recs[0].observer, 7), PUSH(recs[1].value_name, 8), PUSH(recs[1].certs, 9), PUSH(recs[1].observer, 10), PUSH(recs[2].value_name, 11), PUSH(recs[2].certs, 12), PUSH(recs[2].observer, 13), PUSH(val, 14), PUSH(orig_form, 15), PUSH(key, 16), PUSH(form, 17)));
# define XfOrM117_COUNT (18)
# define SETUP_XfOrM117(x) SETUP(XfOrM117_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  key = NULLED_OUT ; 
  val = NULLED_OUT ; 
  expr = NULLED_OUT ; 
  name = NULLED_OUT ; 
  recs[0].value_name = NULLED_OUT ; 
  recs[0].certs = NULLED_OUT ; 
  recs[0].observer = NULLED_OUT ; 
  recs[1].value_name = NULLED_OUT ; 
  recs[1].certs = NULLED_OUT ; 
  recs[1].observer = NULLED_OUT ; 
  recs[2].value_name = NULLED_OUT ; 
  recs[2].certs = NULLED_OUT ; 
  recs[2].observer = NULLED_OUT ; 
  wcm = NULLED_OUT ; 
  len = FUNCCALL(SETUP_XfOrM117(_), check_form (form , form ) ); 
  if (len != 4 )
    FUNCCALL(SETUP_XfOrM117(_), bad_form (form , len ) ); 
  env = FUNCCALL(SETUP_XfOrM117(_), scheme_no_defines (env ) ); 
  form = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM117(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  key = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM117(_), scheme_stx_content (form ) )) ) -> u . pair_val . car ) ) ; 
  form = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM117(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  val = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM117(_), scheme_stx_content (form ) )) ) -> u . pair_val . car ) ) ; 
  form = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM117(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  expr = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM117(_), scheme_stx_content (form ) )) ) -> u . pair_val . car ) ) ; 
  name = rec [drec ] . value_name ; 
  FUNCCALL(SETUP_XfOrM117(_), scheme_compile_rec_done_local (rec , drec ) ); 
  name = FUNCCALL_AGAIN(scheme_check_name_property (orig_form , name ) ); 
  FUNCCALL_AGAIN(scheme_rec_add_certs (rec , drec , orig_form ) ); 
  FUNCCALL_AGAIN(scheme_init_compile_recs (rec , drec , recs , 3 ) ); 
  recs [2 ] . value_name = name ; 
  key = FUNCCALL(SETUP_XfOrM117(_), scheme_compile_expr (key , env , recs , 0 ) ); 
  val = FUNCCALL_AGAIN(scheme_compile_expr (val , env , recs , 1 ) ); 
  expr = FUNCCALL_AGAIN(scheme_compile_expr (expr , env , recs , 2 ) ); 
  FUNCCALL_AGAIN(scheme_merge_compile_recs (rec , drec , recs , 3 ) ); 
  wcm = ((Scheme_With_Continuation_Mark * ) FUNCCALL(SETUP_XfOrM117(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_With_Continuation_Mark ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  wcm -> so . type = scheme_with_cont_mark_type ; 
  wcm -> key = key ; 
  wcm -> val = val ; 
  wcm -> body = expr ; 
  RET_VALUE_START ((Scheme_Object * ) wcm ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * with_cont_mark_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  Scheme_Object * key , * val , * expr , * orig_form = form , * fn , * boundname ; 
  int len ; 
  Scheme_Expand_Info recs [3 ] ; 
  Scheme_Object * __funcarg38 = NULLED_OUT ; 
  Scheme_Object * __funcarg37 = NULLED_OUT ; 
  Scheme_Object * __funcarg36 = NULLED_OUT ; 
  Scheme_Object * __funcarg35 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(18);
  BLOCK_SETUP_TOP((PUSH(expr, 0), PUSH(boundname, 1), PUSH(fn, 2), PUSH(orig_form, 3), PUSH(erec, 4), PUSH(recs[0].value_name, 5), PUSH(recs[0].certs, 6), PUSH(recs[0].observer, 7), PUSH(recs[1].value_name, 8), PUSH(recs[1].certs, 9), PUSH(recs[1].observer, 10), PUSH(recs[2].value_name, 11), PUSH(recs[2].certs, 12), PUSH(recs[2].observer, 13), PUSH(val, 14), PUSH(env, 15), PUSH(key, 16), PUSH(form, 17)));
# define XfOrM118_COUNT (18)
# define SETUP_XfOrM118(x) SETUP(XfOrM118_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  key = NULLED_OUT ; 
  val = NULLED_OUT ; 
  expr = NULLED_OUT ; 
  fn = NULLED_OUT ; 
  boundname = NULLED_OUT ; 
  recs[0].value_name = NULLED_OUT ; 
  recs[0].certs = NULLED_OUT ; 
  recs[0].observer = NULLED_OUT ; 
  recs[1].value_name = NULLED_OUT ; 
  recs[1].certs = NULLED_OUT ; 
  recs[1].observer = NULLED_OUT ; 
  recs[2].value_name = NULLED_OUT ; 
  recs[2].certs = NULLED_OUT ; 
  recs[2].observer = NULLED_OUT ; 
  if (erec [drec ] . observer ) {
#   define XfOrM124_COUNT (0+XfOrM118_COUNT)
#   define SETUP_XfOrM124(x) SETUP_XfOrM118(x)
    FUNCCALL(SETUP_XfOrM124(_), scheme_call_expand_observe (erec [drec ] . observer , 106 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  len = FUNCCALL(SETUP_XfOrM118(_), check_form (form , form ) ); 
  if (len != 4 )
    FUNCCALL(SETUP_XfOrM118(_), bad_form (form , len ) ); 
  env = FUNCCALL(SETUP_XfOrM118(_), scheme_no_defines (env ) ); 
  boundname = FUNCCALL_AGAIN(scheme_check_name_property (form , erec [drec ] . value_name ) ); 
  FUNCCALL_AGAIN(scheme_rec_add_certs (erec , drec , form ) ); 
  FUNCCALL_AGAIN(scheme_init_expand_recs (erec , drec , recs , 3 ) ); 
  recs [0 ] . value_name = scheme_false ; 
  recs [1 ] . value_name = scheme_false ; 
  recs [2 ] . value_name = boundname ; 
  form = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM118(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  key = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM118(_), scheme_stx_content (form ) )) ) -> u . pair_val . car ) ) ; 
  form = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM118(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  val = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM118(_), scheme_stx_content (form ) )) ) -> u . pair_val . car ) ) ; 
  form = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM118(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  expr = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM118(_), scheme_stx_content (form ) )) ) -> u . pair_val . car ) ) ; 
  key = FUNCCALL(SETUP_XfOrM118(_), scheme_expand_expr (key , env , recs , 0 ) ); 
  if (erec [drec ] . observer ) {
#   define XfOrM122_COUNT (0+XfOrM118_COUNT)
#   define SETUP_XfOrM122(x) SETUP_XfOrM118(x)
    FUNCCALL(SETUP_XfOrM122(_), scheme_call_expand_observe (erec [drec ] . observer , 3 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  val = FUNCCALL(SETUP_XfOrM118(_), scheme_expand_expr (val , env , recs , 1 ) ); 
  if (erec [drec ] . observer ) {
#   define XfOrM120_COUNT (0+XfOrM118_COUNT)
#   define SETUP_XfOrM120(x) SETUP_XfOrM118(x)
    FUNCCALL(SETUP_XfOrM120(_), scheme_call_expand_observe (erec [drec ] . observer , 3 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  expr = FUNCCALL(SETUP_XfOrM118(_), scheme_expand_expr (expr , env , recs , 2 ) ); 
  fn = (((Scheme_Type ) (((((long ) (orig_form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (orig_form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (orig_form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM118(_), scheme_stx_content (orig_form ) )) ) -> u . pair_val . car ) ) ; 
  RET_VALUE_START ((__funcarg35 = (__funcarg36 = (__funcarg37 = (__funcarg38 = FUNCCALL(SETUP_XfOrM118(_), scheme_make_immutable_pair (expr , scheme_null ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (val , __funcarg38 ) )) , FUNCCALL_AGAIN(scheme_make_immutable_pair (key , __funcarg37 ) )) , FUNCCALL_AGAIN(scheme_make_immutable_pair (fn , __funcarg36 ) )) , FUNCCALL_EMPTY(scheme_datum_to_syntax (__funcarg35 , orig_form , orig_form , 0 , 2 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * set_execute (Scheme_Object * data ) {
  Scheme_Object * val , * set_undef , * tl , * * toplevels ; 
  Scheme_Bucket * var ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(val, 0), PUSH(set_undef, 1), PUSH(data, 2), PUSH(toplevels, 3), PUSH(var, 4), PUSH(tl, 5)));
# define XfOrM125_COUNT (6)
# define SETUP_XfOrM125(x) SETUP(XfOrM125_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  val = NULLED_OUT ; 
  set_undef = NULLED_OUT ; 
  tl = NULLED_OUT ; 
  toplevels = NULLED_OUT ; 
  var = NULLED_OUT ; 
  set_undef = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) ; 
  data = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ; 
  val = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ; 
  val = FUNCCALL(SETUP_XfOrM125(_), scheme_do_eval (val , - 1 , ((void * ) 0 ) , 1 ) ); 
  tl = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) ; 
  toplevels = (Scheme_Object * * ) scheme_current_runstack [(((Scheme_Toplevel * ) (tl ) ) -> depth ) ] ; 
  var = (Scheme_Bucket * ) toplevels [(((Scheme_Toplevel * ) (tl ) ) -> position ) ] ; 
  FUNCCALL_EMPTY(scheme_set_global_bucket ("set!" , var , val , (! (((set_undef ) ) == (scheme_false ) ) ) ) ); 
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * set_jit (Scheme_Object * data ) {
  Scheme_Object * orig_val , * naya_val ; 
  Scheme_Object * __funcarg39 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(orig_val, 0), PUSH(data, 1), PUSH(naya_val, 2)));
# define XfOrM126_COUNT (3)
# define SETUP_XfOrM126(x) SETUP(XfOrM126_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  orig_val = NULLED_OUT ; 
  naya_val = NULLED_OUT ; 
  orig_val = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ; 
  orig_val = (((Scheme_Simple_Object * ) (orig_val ) ) -> u . pair_val . cdr ) ; 
  naya_val = FUNCCALL(SETUP_XfOrM126(_), scheme_jit_expr (orig_val ) ); 
  if (((naya_val ) == (orig_val ) ) )
    RET_VALUE_START (data ) RET_VALUE_END ; 
  else RET_VALUE_START ((__funcarg39 = FUNCCALL(SETUP_XfOrM126(_), scheme_make_pair (((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) , naya_val ) ), FUNCCALL_EMPTY(scheme_make_pair ((((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) , __funcarg39 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void set_validate (Scheme_Object * data , Mz_CPort * port , char * stack , Scheme_Hash_Table * ht , Scheme_Object * * tls , int depth , int letlimit , int delta , int num_toplevels , int num_stxes , int num_lifts ) {
  Scheme_Object * val , * tl ; 
  PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSH(val, 0), PUSH(port, 1), PUSH(data, 2), PUSH(tls, 3), PUSH(ht, 4), PUSH(stack, 5), PUSH(tl, 6)));
# define XfOrM127_COUNT (7)
# define SETUP_XfOrM127(x) SETUP(XfOrM127_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  val = NULLED_OUT ; 
  tl = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (data ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (data ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || ! ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    FUNCCALL(SETUP_XfOrM127(_), scheme_ill_formed (port , "./../src/syntax.c" , 1418 ) ); 
  data = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ; 
  tl = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) ; 
  val = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ; 
  FUNCCALL(SETUP_XfOrM127(_), scheme_validate_expr (port , val , stack , ht , tls , depth , letlimit , delta , num_toplevels , num_stxes , num_lifts , ((void * ) 0 ) , 0 ) ); 
  FUNCCALL_EMPTY(scheme_validate_toplevel (tl , port , stack , ht , tls , depth , delta , num_toplevels , num_stxes , num_lifts , 0 ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * set_optimize (Scheme_Object * data , Optimize_Info * info ) {
  Scheme_Object * var , * val , * set_undef ; 
  Scheme_Object * __funcarg41 = NULLED_OUT ; 
  Scheme_Object * __funcarg40 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(set_undef, 0), PUSH(val, 1), PUSH(var, 2), PUSH(info, 3)));
# define XfOrM128_COUNT (4)
# define SETUP_XfOrM128(x) SETUP(XfOrM128_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  var = NULLED_OUT ; 
  val = NULLED_OUT ; 
  set_undef = NULLED_OUT ; 
  set_undef = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) ; 
  data = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ; 
  var = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) ; 
  val = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ; 
  val = FUNCCALL(SETUP_XfOrM128(_), scheme_optimize_expr (val , info ) ); 
  info -> preserves_marks = 1 ; 
  info -> single_result = 1 ; 
  if (((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_local_type ) ) ) {
    int pos , delta ; 
#   define XfOrM130_COUNT (0+XfOrM128_COUNT)
#   define SETUP_XfOrM130(x) SETUP_XfOrM128(x)
    pos = (((Scheme_Local * ) (var ) ) -> position ) ; 
    FUNCCALL(SETUP_XfOrM130(_), scheme_optimize_info_lookup (info , pos , ((void * ) 0 ) ) ); 
    delta = FUNCCALL_AGAIN(scheme_optimize_info_get_shift (info , pos ) ); 
    if (delta )
      var = FUNCCALL(SETUP_XfOrM130(_), scheme_make_local (scheme_local_type , pos + delta ) ); 
  }
  else {
#   define XfOrM129_COUNT (0+XfOrM128_COUNT)
#   define SETUP_XfOrM129(x) SETUP_XfOrM128(x)
    FUNCCALL(SETUP_XfOrM129(_), scheme_optimize_info_used_top (info ) ); 
  }
  RET_VALUE_START ((__funcarg40 = (__funcarg41 = FUNCCALL(SETUP_XfOrM128(_), scheme_make_pair (var , val ) ), FUNCCALL_AGAIN(scheme_make_pair (set_undef , __funcarg41 ) )) , FUNCCALL_EMPTY(scheme_make_syntax_compiled (2 , __funcarg40 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * set_clone (int dup_ok , Scheme_Object * data , Optimize_Info * info , int delta , int closure_depth ) {
  Scheme_Object * var , * val , * set_undef ; 
  Scheme_Object * __funcarg43 = NULLED_OUT ; 
  Scheme_Object * __funcarg42 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(set_undef, 0), PUSH(val, 1), PUSH(var, 2), PUSH(info, 3)));
# define XfOrM131_COUNT (4)
# define SETUP_XfOrM131(x) SETUP(XfOrM131_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  var = NULLED_OUT ; 
  val = NULLED_OUT ; 
  set_undef = NULLED_OUT ; 
  set_undef = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) ; 
  data = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ; 
  var = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) ; 
  val = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ; 
  val = FUNCCALL(SETUP_XfOrM131(_), scheme_optimize_clone (dup_ok , val , info , delta , closure_depth ) ); 
  if (! val )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  if (((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_local_type ) ) ) {
#   define XfOrM132_COUNT (0+XfOrM131_COUNT)
#   define SETUP_XfOrM132(x) SETUP_XfOrM131(x)
    var = FUNCCALL(SETUP_XfOrM132(_), scheme_optimize_clone (dup_ok , var , info , delta , closure_depth ) ); 
    if (! var )
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  RET_VALUE_START ((__funcarg42 = (__funcarg43 = FUNCCALL(SETUP_XfOrM131(_), scheme_make_pair (var , val ) ), FUNCCALL_AGAIN(scheme_make_pair (set_undef , __funcarg43 ) )) , FUNCCALL_EMPTY(scheme_make_syntax_compiled (2 , __funcarg42 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * set_shift (Scheme_Object * data , int delta , int after_depth ) {
  Scheme_Object * l , * e ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(e, 0), PUSH(data, 1), PUSH(l, 2)));
# define XfOrM133_COUNT (3)
# define SETUP_XfOrM133(x) SETUP(XfOrM133_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  l = NULLED_OUT ; 
  e = NULLED_OUT ; 
  l = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ; 
  e = FUNCCALL(SETUP_XfOrM133(_), scheme_optimize_shift ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) , delta , after_depth ) ); 
  (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) = e ; 
  e = FUNCCALL(SETUP_XfOrM133(_), scheme_optimize_shift ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) , delta , after_depth ) ); 
  (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) = e ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_syntax_compiled (2 , data ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * set_resolve (Scheme_Object * data , Resolve_Info * rslv ) {
  Scheme_Object * var , * val , * set_undef ; 
  Scheme_Object * __funcarg45 = NULLED_OUT ; 
  Scheme_Object * __funcarg44 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(set_undef, 0), PUSH(val, 1), PUSH(var, 2), PUSH(rslv, 3)));
# define XfOrM134_COUNT (4)
# define SETUP_XfOrM134(x) SETUP(XfOrM134_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  var = NULLED_OUT ; 
  val = NULLED_OUT ; 
  set_undef = NULLED_OUT ; 
  set_undef = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) ; 
  data = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ; 
  var = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) ; 
  val = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ; 
  val = FUNCCALL(SETUP_XfOrM134(_), scheme_resolve_expr (val , rslv ) ); 
  if (((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_local_type ) ) ) {
    Scheme_Let_Value * lv ; 
    Scheme_Object * cv ; 
    int flags , li ; 
    BLOCK_SETUP((PUSH(lv, 0+XfOrM134_COUNT), PUSH(cv, 1+XfOrM134_COUNT)));
#   define XfOrM135_COUNT (2+XfOrM134_COUNT)
#   define SETUP_XfOrM135(x) SETUP(XfOrM135_COUNT)
    lv = NULLED_OUT ; 
    cv = NULLED_OUT ; 
    cv = FUNCCALL(SETUP_XfOrM135(_), scheme_compiled_void () ); 
    lv = ((Scheme_Let_Value * ) FUNCCALL(SETUP_XfOrM135(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Let_Value ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    lv -> iso . so . type = scheme_let_value_type ; 
    lv -> body = cv ; 
    lv -> count = 1 ; 
    li = FUNCCALL(SETUP_XfOrM135(_), scheme_resolve_info_lookup (rslv , (((Scheme_Local * ) (var ) ) -> position ) , & flags , ((void * ) 0 ) , 0 ) ); 
    lv -> position = li ; 
    (& lv -> iso ) -> so . keyex = (flags & 1 ) ; 
    lv -> value = val ; 
    if (! (flags & 1 ) )
      FUNCCALL(SETUP_XfOrM135(_), scheme_signal_error ("internal error: set!: set!ed local variable is not boxed" ) ); 
    RET_VALUE_START ((Scheme_Object * ) lv ) RET_VALUE_END ; 
  }
  var = FUNCCALL(SETUP_XfOrM134(_), scheme_resolve_expr (var , rslv ) ); 
  RET_VALUE_START ((__funcarg44 = (__funcarg45 = FUNCCALL(SETUP_XfOrM134(_), scheme_make_pair (var , val ) ), FUNCCALL_AGAIN(scheme_make_pair (set_undef , __funcarg45 ) )) , FUNCCALL_EMPTY(scheme_make_syntax_resolved (2 , __funcarg44 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * set_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  Scheme_Env * menv = ((void * ) 0 ) ; 
  Scheme_Object * var , * val , * name , * body , * rest , * find_name ; 
  int l , set_undef ; 
  Scheme_Comp_Env * __funcarg49 = NULLED_OUT ; 
  Scheme_Config * __funcarg48 = NULLED_OUT ; 
  Scheme_Object * __funcarg47 = NULLED_OUT ; 
  Scheme_Object * __funcarg46 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(10);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(var, 1), PUSH(rec, 2), PUSH(name, 3), PUSH(find_name, 4), PUSH(val, 5), PUSH(menv, 6), PUSH(body, 7), PUSH(form, 8), PUSH(rest, 9)));
# define XfOrM136_COUNT (10)
# define SETUP_XfOrM136(x) SETUP(XfOrM136_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  var = NULLED_OUT ; 
  val = NULLED_OUT ; 
  name = NULLED_OUT ; 
  body = NULLED_OUT ; 
  rest = NULLED_OUT ; 
  find_name = NULLED_OUT ; 
  l = FUNCCALL(SETUP_XfOrM136(_), check_form (form , form ) ); 
  if (l != 3 )
    FUNCCALL(SETUP_XfOrM136(_), bad_form (form , l ) ); 
  rest = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM136(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  name = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM136(_), scheme_stx_content (rest ) )) ) -> u . pair_val . car ) ) ; 
  rest = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM136(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ; 
  body = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM136(_), scheme_stx_content (rest ) )) ) -> u . pair_val . car ) ) ; 
  FUNCCALL(SETUP_XfOrM136(_), scheme_check_identifier ("set!" , name , ((void * ) 0 ) , env , form ) ); 
  find_name = name ; 
  FUNCCALL(SETUP_XfOrM136(_), scheme_rec_add_certs (rec , drec , form ) ); 
  while (1 ) {
#   define XfOrM148_COUNT (0+XfOrM136_COUNT)
#   define SETUP_XfOrM148(x) SETUP_XfOrM136(x)
    var = FUNCCALL(SETUP_XfOrM148(_), scheme_lookup_binding (find_name , env , 4 + 16 + (rec [drec ] . dont_mark_local_use ? 128 : 0 ) + (rec [drec ] . resolve_module_ids ? 1024 : 0 ) , rec [drec ] . certs , env -> in_modidx , & menv , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
    if (((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_macro_type ) ) ) {
#     define XfOrM149_COUNT (0+XfOrM148_COUNT)
#     define SETUP_XfOrM149(x) SETUP_XfOrM148(x)
      if (((Scheme_Type ) (((((long ) ((((Scheme_Small_Object * ) (var ) ) -> u . ptr_val ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Small_Object * ) (var ) ) -> u . ptr_val ) ) ) -> type ) ) == (Scheme_Type ) (scheme_set_macro_type ) ) ) {
#       define XfOrM153_COUNT (0+XfOrM149_COUNT)
#       define SETUP_XfOrM153(x) SETUP_XfOrM149(x)
        form = FUNCCALL(SETUP_XfOrM153(_), scheme_apply_macro (name , menv , (((Scheme_Small_Object * ) (var ) ) -> u . ptr_val ) , form , env , scheme_false , rec , drec , 1 ) ); 
        RET_VALUE_START (FUNCCALL(SETUP_XfOrM153(_), scheme_compile_expr (form , env , rec , drec ) )) RET_VALUE_END ; 
      }
      else if (((Scheme_Type ) (((((long ) ((((Scheme_Small_Object * ) (var ) ) -> u . ptr_val ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Small_Object * ) (var ) ) -> u . ptr_val ) ) ) -> type ) ) == (Scheme_Type ) (scheme_id_macro_type ) ) ) {
#       define XfOrM150_COUNT (0+XfOrM149_COUNT)
#       define SETUP_XfOrM150(x) SETUP_XfOrM149(x)
        find_name = (((Scheme_Small_Object * ) ((((Scheme_Small_Object * ) (var ) ) -> u . ptr_val ) ) ) -> u . ptr_val ) ; 
        find_name = FUNCCALL(SETUP_XfOrM150(_), scheme_stx_cert (find_name , scheme_false , menv , find_name , ((void * ) 0 ) , 1 ) ); 
        {
#         define XfOrM151_COUNT (0+XfOrM150_COUNT)
#         define SETUP_XfOrM151(x) SETUP_XfOrM150(x)
          if ((scheme_fuel_counter ) <= 0 ) {
#           define XfOrM152_COUNT (0+XfOrM151_COUNT)
#           define SETUP_XfOrM152(x) SETUP_XfOrM151(x)
            FUNCCALL(SETUP_XfOrM152(_), scheme_out_of_fuel () ); 
          }
        }
        ; 
        menv = ((void * ) 0 ) ; 
      }
      else break ; 
    }
    else break ; 
  }
  if (((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_macro_type ) ) || ((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_syntax_compiler_type ) ) ) {
#   define XfOrM141_COUNT (0+XfOrM136_COUNT)
#   define SETUP_XfOrM141(x) SETUP_XfOrM136(x)
    FUNCCALL(SETUP_XfOrM141(_), scheme_wrong_syntax (((void * ) 0 ) , name , form , "cannot mutate syntax identifier" ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_variable_type ) ) || ((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_module_variable_type ) ) ) {
#   define XfOrM140_COUNT (0+XfOrM136_COUNT)
#   define SETUP_XfOrM140(x) SETUP_XfOrM136(x)
    var = FUNCCALL(SETUP_XfOrM140(_), scheme_register_toplevel_in_prefix (var , env , rec , drec ) ); 
    if (env -> genv -> module )
      (& ((Scheme_Toplevel * ) (var ) ) -> iso ) -> so . keyex |= 0x2 ; 
  }
  FUNCCALL(SETUP_XfOrM136(_), scheme_compile_rec_done_local (rec , drec ) ); 
  rec [drec ] . value_name = (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ? ((Scheme_Stx * ) name ) -> val : name ) ; 
  val = (__funcarg49 = FUNCCALL(SETUP_XfOrM136(_), scheme_no_defines (env ) ), FUNCCALL_AGAIN(scheme_compile_expr (body , __funcarg49 , rec , drec ) )) ; 
  if (((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) ) ) {
#   define XfOrM137_COUNT (0+XfOrM136_COUNT)
#   define SETUP_XfOrM137(x) SETUP_XfOrM136(x)
    if (((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_local_type ) ) || ((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_local_unbox_type ) ) ) {
#     define XfOrM139_COUNT (0+XfOrM137_COUNT)
#     define SETUP_XfOrM139(x) SETUP_XfOrM137(x)
      if ((((Scheme_Local * ) (var ) ) -> position ) == (((Scheme_Local * ) (val ) ) -> position ) )
        RET_VALUE_START (FUNCCALL(SETUP_XfOrM139(_), scheme_compiled_void () )) RET_VALUE_END ; 
    }
    else {
    }
  }
  set_undef = (! ((((__funcarg48 = FUNCCALL(SETUP_XfOrM136(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg48 , MZCONFIG_ALLOW_SET_UNDEFINED ) )) ) ) == (scheme_false ) ) ) ; 
  RET_VALUE_START ((__funcarg46 = (__funcarg47 = FUNCCALL(SETUP_XfOrM136(_), scheme_make_pair (var , val ) ), FUNCCALL_AGAIN(scheme_make_pair (set_undef ? scheme_true : scheme_false , __funcarg47 ) )) , FUNCCALL_AGAIN(scheme_make_syntax_compiled (2 , __funcarg46 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * set_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  Scheme_Env * menv = ((void * ) 0 ) ; 
  Scheme_Object * name , * var , * fn , * rhs , * find_name , * lexical_binding_id ; 
  int l ; 
  Scheme_Object * __funcarg52 = NULLED_OUT ; 
  Scheme_Object * __funcarg51 = NULLED_OUT ; 
  Scheme_Object * __funcarg50 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(11);
  BLOCK_SETUP_TOP((PUSH(name, 0), PUSH(rhs, 1), PUSH(menv, 2), PUSH(fn, 3), PUSH(find_name, 4), PUSH(erec, 5), PUSH(env, 6), PUSH(lexical_binding_id, 7), PUSH(form, 8), PUSH(var, 9)));
# define XfOrM154_COUNT (10)
# define SETUP_XfOrM154(x) SETUP(XfOrM154_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  name = NULLED_OUT ; 
  var = NULLED_OUT ; 
  fn = NULLED_OUT ; 
  rhs = NULLED_OUT ; 
  find_name = NULLED_OUT ; 
  lexical_binding_id = NULLED_OUT ; 
  if (erec [drec ] . observer ) {
#   define XfOrM183_COUNT (0+XfOrM154_COUNT)
#   define SETUP_XfOrM183(x) SETUP_XfOrM154(x)
    FUNCCALL(SETUP_XfOrM183(_), scheme_call_expand_observe (erec [drec ] . observer , 123 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  l = FUNCCALL(SETUP_XfOrM154(_), check_form (form , form ) ); 
  if (l != 3 )
    FUNCCALL(SETUP_XfOrM154(_), bad_form (form , l ) ); 
  env = FUNCCALL(SETUP_XfOrM154(_), scheme_no_defines (env ) ); 
  name = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM154(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  name = (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (name ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM154(_), scheme_stx_content (name ) )) ) -> u . pair_val . car ) ) ; 
  FUNCCALL(SETUP_XfOrM154(_), scheme_check_identifier ("set!" , name , ((void * ) 0 ) , env , form ) ); 
  find_name = name ; 
  FUNCCALL(SETUP_XfOrM154(_), scheme_rec_add_certs (erec , drec , form ) ); 
  while (1 ) {
#   define XfOrM170_COUNT (0+XfOrM154_COUNT)
#   define SETUP_XfOrM170(x) SETUP_XfOrM154(x)
    lexical_binding_id = ((void * ) 0 ) ; 
    var = FUNCCALL(SETUP_XfOrM170(_), scheme_lookup_binding (find_name , env , 4 , erec [drec ] . certs , env -> in_modidx , & menv , ((void * ) 0 ) , & lexical_binding_id ) ); 
    if (erec [drec ] . observer ) {
#     define XfOrM181_COUNT (0+XfOrM170_COUNT)
#     define SETUP_XfOrM181(x) SETUP_XfOrM170(x)
      FUNCCALL(SETUP_XfOrM181(_), scheme_call_expand_observe (erec [drec ] . observer , 1 , find_name ) ); 
    }
    else {
    }
    ; 
    if ((erec [drec ] . depth != 0 ) && ((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_macro_type ) ) ) {
#     define XfOrM173_COUNT (0+XfOrM170_COUNT)
#     define SETUP_XfOrM173(x) SETUP_XfOrM170(x)
      if (((Scheme_Type ) (((((long ) ((((Scheme_Small_Object * ) (var ) ) -> u . ptr_val ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Small_Object * ) (var ) ) -> u . ptr_val ) ) ) -> type ) ) == (Scheme_Type ) (scheme_set_macro_type ) ) ) {
#       define XfOrM175_COUNT (0+XfOrM173_COUNT)
#       define SETUP_XfOrM175(x) SETUP_XfOrM173(x)
        if (erec [drec ] . observer ) {
#         define XfOrM179_COUNT (0+XfOrM175_COUNT)
#         define SETUP_XfOrM179(x) SETUP_XfOrM175(x)
          FUNCCALL(SETUP_XfOrM179(_), scheme_call_expand_observe (erec [drec ] . observer , 8 , form ) ); 
        }
        else {
        }
        ; 
        form = FUNCCALL(SETUP_XfOrM175(_), scheme_apply_macro (name , menv , (((Scheme_Small_Object * ) (var ) ) -> u . ptr_val ) , form , env , scheme_false , erec , drec , 1 ) ); 
        if (erec [drec ] . observer ) {
#         define XfOrM177_COUNT (0+XfOrM175_COUNT)
#         define SETUP_XfOrM177(x) SETUP_XfOrM175(x)
          FUNCCALL(SETUP_XfOrM177(_), scheme_call_expand_observe (erec [drec ] . observer , 9 , form ) ); 
        }
        else {
        }
        ; 
        if (erec [drec ] . depth > 0 )
          erec [drec ] . depth -- ; 
        erec [drec ] . value_name = name ; 
        RET_VALUE_START (FUNCCALL(SETUP_XfOrM175(_), scheme_expand_expr (form , env , erec , drec ) )) RET_VALUE_END ; 
      }
      else if (((Scheme_Type ) (((((long ) ((((Scheme_Small_Object * ) (var ) ) -> u . ptr_val ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Small_Object * ) (var ) ) -> u . ptr_val ) ) ) -> type ) ) == (Scheme_Type ) (scheme_id_macro_type ) ) ) {
        Scheme_Object * new_name ; 
        BLOCK_SETUP((PUSH(new_name, 0+XfOrM173_COUNT)));
#       define XfOrM174_COUNT (1+XfOrM173_COUNT)
#       define SETUP_XfOrM174(x) SETUP(XfOrM174_COUNT)
        new_name = NULLED_OUT ; 
        new_name = (((Scheme_Small_Object * ) ((((Scheme_Small_Object * ) (var ) ) -> u . ptr_val ) ) ) -> u . ptr_val ) ; 
        new_name = FUNCCALL(SETUP_XfOrM174(_), scheme_stx_track (new_name , find_name , find_name ) ); 
        new_name = FUNCCALL_AGAIN(scheme_stx_cert (new_name , scheme_false , menv , find_name , ((void * ) 0 ) , 1 ) ); 
        find_name = new_name ; 
        menv = ((void * ) 0 ) ; 
      }
      else break ; 
    }
    else {
      if (lexical_binding_id ) {
        find_name = lexical_binding_id ; 
      }
      break ; 
    }
  }
  if (((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_macro_type ) ) || ((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_syntax_compiler_type ) ) ) {
#   define XfOrM157_COUNT (0+XfOrM154_COUNT)
#   define SETUP_XfOrM157(x) SETUP_XfOrM154(x)
    FUNCCALL(SETUP_XfOrM157(_), scheme_wrong_syntax (((void * ) 0 ) , name , form , "cannot mutate syntax identifier" ) ); 
  }
  if (erec [drec ] . observer ) {
#   define XfOrM156_COUNT (0+XfOrM154_COUNT)
#   define SETUP_XfOrM156(x) SETUP_XfOrM154(x)
    FUNCCALL(SETUP_XfOrM156(_), scheme_call_expand_observe (erec [drec ] . observer , 3 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  fn = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM154(_), scheme_stx_content (form ) )) ) -> u . pair_val . car ) ) ; 
  rhs = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM154(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  rhs = (((Scheme_Type ) (((((long ) (rhs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rhs ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rhs ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM154(_), scheme_stx_content (rhs ) )) ) -> u . pair_val . cdr ) ) ; 
  rhs = (((Scheme_Type ) (((((long ) (rhs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rhs ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rhs ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM154(_), scheme_stx_content (rhs ) )) ) -> u . pair_val . car ) ) ; 
  erec [drec ] . value_name = name ; 
  rhs = FUNCCALL(SETUP_XfOrM154(_), scheme_expand_expr (rhs , env , erec , drec ) ); 
  RET_VALUE_START ((__funcarg50 = (__funcarg51 = (__funcarg52 = FUNCCALL(SETUP_XfOrM154(_), scheme_make_immutable_pair (rhs , scheme_null ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (find_name , __funcarg52 ) )) , FUNCCALL_AGAIN(scheme_make_immutable_pair (fn , __funcarg51 ) )) , FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg50 , form , form , 0 , 2 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * ref_execute (Scheme_Object * tl ) {
  Scheme_Object * * toplevels , * o ; 
  Scheme_Bucket * var ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(var, 1)));
# define XfOrM184_COUNT (2)
# define SETUP_XfOrM184(x) SETUP(XfOrM184_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  toplevels = NULLED_OUT ; 
  o = NULLED_OUT ; 
  var = NULLED_OUT ; 
  toplevels = (Scheme_Object * * ) scheme_current_runstack [(((Scheme_Toplevel * ) (tl ) ) -> depth ) ] ; 
  var = (Scheme_Bucket * ) toplevels [(((Scheme_Toplevel * ) (tl ) ) -> position ) ] ; 
  o = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM184(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  o -> type = scheme_global_ref_type ; 
  (((Scheme_Small_Object * ) (o ) ) -> u . ptr_val ) = (Scheme_Object * ) var ; 
  RET_VALUE_START (o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * ref_jit (Scheme_Object * data ) {
  /* No conversion */
  return data ; 
}
static void ref_validate (Scheme_Object * tl , Mz_CPort * port , char * stack , Scheme_Hash_Table * ht , Scheme_Object * * tls , int depth , int letlimit , int delta , int num_toplevels , int num_stxes , int num_lifts ) {
  /* No conversion */
  scheme_validate_toplevel (tl , port , stack , ht , tls , depth , delta , num_toplevels , num_stxes , num_lifts , 0 ) ; 
}
static Scheme_Object * ref_optimize (Scheme_Object * tl , Optimize_Info * info ) {
  /* No conversion */
  info -> preserves_marks = 1 ; 
  info -> single_result = 1 ; 
  return scheme_make_syntax_compiled (9 , tl ) ; 
}
static Scheme_Object * ref_shift (Scheme_Object * data , int delta , int after_depth ) {
  /* No conversion */
  return scheme_make_syntax_compiled (9 , data ) ; 
}
static Scheme_Object * ref_resolve (Scheme_Object * tl , Resolve_Info * rslv ) {
  Scheme_Object * __funcarg53 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(0);
# define XfOrM189_COUNT (0)
# define SETUP_XfOrM189(x) SETUP(XfOrM189_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg53 = FUNCCALL_EMPTY(scheme_resolve_expr (tl , rslv ) ), FUNCCALL_EMPTY(scheme_make_syntax_resolved (9 , __funcarg53 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * ref_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  Scheme_Env * menv = ((void * ) 0 ) ; 
  Scheme_Object * var , * name , * rest ; 
  int l , ok ; 
  Scheme_Object * __funcarg54 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(rec, 1), PUSH(name, 2), PUSH(menv, 3), PUSH(var, 4), PUSH(form, 5), PUSH(rest, 6)));
# define XfOrM190_COUNT (7)
# define SETUP_XfOrM190(x) SETUP(XfOrM190_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  var = NULLED_OUT ; 
  name = NULLED_OUT ; 
  rest = NULLED_OUT ; 
  l = FUNCCALL(SETUP_XfOrM190(_), check_form (form , form ) ); 
  if (l != 2 )
    FUNCCALL(SETUP_XfOrM190(_), bad_form (form , l ) ); 
  rest = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM190(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  name = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM190(_), scheme_stx_content (rest ) )) ) -> u . pair_val . car ) ) ; 
  if ((((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) name ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) name ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
#   define XfOrM196_COUNT (0+XfOrM190_COUNT)
#   define SETUP_XfOrM196(x) SETUP_XfOrM190(x)
    rest = (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (name ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM196(_), scheme_stx_content (name ) )) ) -> u . pair_val . car ) ) ; 
    if (env -> genv -> phase == 0 ) {
      var = scheme_top_stx ; 
    }
    else {
#     define XfOrM197_COUNT (0+XfOrM196_COUNT)
#     define SETUP_XfOrM197(x) SETUP_XfOrM196(x)
      var = (__funcarg54 = FUNCCALL(SETUP_XfOrM197(_), scheme_sys_wraps (env ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (((Scheme_Stx * ) scheme_top_stx ) -> val , scheme_false , __funcarg54 , 0 , 0 ) )) ; 
    }
    ok = FUNCCALL(SETUP_XfOrM196(_), scheme_stx_module_eq (rest , var , env -> genv -> phase ) ); 
  }
  else ok = (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) name ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) name ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) ; 
  if (! ok ) {
#   define XfOrM195_COUNT (0+XfOrM190_COUNT)
#   define SETUP_XfOrM195(x) SETUP_XfOrM190(x)
    FUNCCALL(SETUP_XfOrM195(_), scheme_wrong_syntax ("#%variable-reference" , name , form , "not an identifier or #%%top form" ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if ((((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) name ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) name ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
#   define XfOrM194_COUNT (0+XfOrM190_COUNT)
#   define SETUP_XfOrM194(x) SETUP_XfOrM190(x)
    if (rec [drec ] . comp )
      var = FUNCCALL(SETUP_XfOrM194(_), scheme_compile_expr (name , env , rec , drec ) ); 
    else var = FUNCCALL(SETUP_XfOrM194(_), scheme_expand_expr (name , env , rec , drec ) ); 
  }
  else {
#   define XfOrM191_COUNT (0+XfOrM190_COUNT)
#   define SETUP_XfOrM191(x) SETUP_XfOrM190(x)
    FUNCCALL(SETUP_XfOrM191(_), scheme_rec_add_certs (rec , drec , form ) ); 
    var = FUNCCALL(SETUP_XfOrM191(_), scheme_lookup_binding (name , env , 4096 + 16 + (rec [drec ] . dont_mark_local_use ? 128 : 0 ) + (rec [drec ] . resolve_module_ids ? 1024 : 0 ) , rec [drec ] . certs , env -> in_modidx , & menv , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
    if (((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_variable_type ) ) || ((Scheme_Type ) (((((long ) (var ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var ) ) -> type ) ) == (Scheme_Type ) (scheme_module_variable_type ) ) ) {
#     define XfOrM193_COUNT (0+XfOrM191_COUNT)
#     define SETUP_XfOrM193(x) SETUP_XfOrM191(x)
      if (rec [drec ] . comp )
        var = FUNCCALL(SETUP_XfOrM193(_), scheme_register_toplevel_in_prefix (var , env , rec , drec ) ); 
    }
    else {
#     define XfOrM192_COUNT (0+XfOrM191_COUNT)
#     define SETUP_XfOrM192(x) SETUP_XfOrM191(x)
      FUNCCALL(SETUP_XfOrM192(_), scheme_wrong_syntax (((void * ) 0 ) , name , form , "identifier does not refer to a top-level or module variable" ) ); 
    }
    if (rec [drec ] . comp )
      FUNCCALL(SETUP_XfOrM191(_), scheme_compile_rec_done_local (rec , drec ) ); 
  }
  if (rec [drec ] . comp )
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM190(_), scheme_make_syntax_compiled (9 , var ) )) RET_VALUE_END ; 
  else RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * ref_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(form, 0)));
# define XfOrM199_COUNT (1)
# define SETUP_XfOrM199(x) SETUP(XfOrM199_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM199(_), ref_syntax (form , env , erec , drec ) ); 
  RET_VALUE_START (form ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * apply_values_execute (Scheme_Object * data ) {
  Scheme_Object * f , * v ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(data, 1), PUSH(f, 2)));
# define XfOrM200_COUNT (3)
# define SETUP_XfOrM200(x) SETUP(XfOrM200_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  f = NULLED_OUT ; 
  v = NULLED_OUT ; 
  f = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) ; 
  f = FUNCCALL(SETUP_XfOrM200(_), scheme_do_eval (f , - 1 , ((void * ) 0 ) , 1 ) ); 
  if (! (! (((long ) (f ) ) & 0x1 ) && ((((f ) -> type ) >= scheme_prim_type ) && (((f ) -> type ) <= scheme_native_closure_type ) ) ) ) {
    Scheme_Object * a [1 ] ; 
    BLOCK_SETUP((PUSHARRAY(a, 1, 0+XfOrM200_COUNT)));
#   define XfOrM204_COUNT (3+XfOrM200_COUNT)
#   define SETUP_XfOrM204(x) SETUP(XfOrM204_COUNT)
    a[0] = NULLED_OUT ; 
    a [0 ] = f ; 
    FUNCCALL(SETUP_XfOrM204(_), scheme_wrong_type ("call-with-values" , "procedure" , - 1 , 1 , a ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  v = FUNCCALL(SETUP_XfOrM200(_), scheme_do_eval ((((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) , - 1 , ((void * ) 0 ) , - 1 ) ); 
  if (((v ) == (((Scheme_Object * ) 0x6 ) ) ) ) {
    Scheme_Thread * p = scheme_current_thread ; 
    int num_rands = p -> ku . multiple . count ; 
#   define XfOrM202_COUNT (0+XfOrM200_COUNT)
#   define SETUP_XfOrM202(x) SETUP_XfOrM200(x)
    if (num_rands > p -> tail_buffer_size ) {
      if (((p -> ku . multiple . array ) == (p -> values_buffer ) ) )
        p -> values_buffer = ((void * ) 0 ) ; 
    }
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_tail_apply (f , num_rands , p -> ku . multiple . array ) )) RET_VALUE_EMPTY_END ; 
  }
  else {
    Scheme_Object * a [1 ] ; 
    BLOCK_SETUP((PUSHARRAY(a, 1, 0+XfOrM200_COUNT)));
#   define XfOrM201_COUNT (3+XfOrM200_COUNT)
#   define SETUP_XfOrM201(x) SETUP(XfOrM201_COUNT)
    a[0] = NULLED_OUT ; 
    a [0 ] = v ; 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM201(_), scheme_tail_apply (f , 1 , a ) )) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * apply_values_jit (Scheme_Object * data ) {
  Scheme_Object * f , * e ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(data, 0), PUSH(f, 1), PUSH(e, 2)));
# define XfOrM205_COUNT (3)
# define SETUP_XfOrM205(x) SETUP(XfOrM205_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  f = NULLED_OUT ; 
  e = NULLED_OUT ; 
  f = FUNCCALL(SETUP_XfOrM205(_), scheme_jit_expr ((((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) ) ); 
  e = FUNCCALL_AGAIN(scheme_jit_expr ((((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ) ); 
  if (((f ) == ((((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) ) ) && ((e ) == ((((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) ) ) )
    RET_VALUE_START (data ) RET_VALUE_END ; 
  else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_pair (f , e ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * apply_values_optimize (Scheme_Object * data , Optimize_Info * info ) {
  Scheme_Object * f , * e ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(info, 0), PUSH(f, 1), PUSH(e, 2)));
# define XfOrM206_COUNT (3)
# define SETUP_XfOrM206(x) SETUP(XfOrM206_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  f = NULLED_OUT ; 
  e = NULLED_OUT ; 
  f = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) ; 
  e = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ; 
  f = FUNCCALL(SETUP_XfOrM206(_), scheme_optimize_expr (f , info ) ); 
  e = FUNCCALL_AGAIN(scheme_optimize_expr (e , info ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_optimize_apply_values (f , e , info , info -> single_result ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * apply_values_resolve (Scheme_Object * data , Resolve_Info * rslv ) {
  Scheme_Object * f , * e ; 
  Scheme_Object * __funcarg55 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(e, 0), PUSH(f, 1), PUSH(rslv, 2)));
# define XfOrM207_COUNT (3)
# define SETUP_XfOrM207(x) SETUP(XfOrM207_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  f = NULLED_OUT ; 
  e = NULLED_OUT ; 
  f = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) ; 
  e = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ; 
  f = FUNCCALL(SETUP_XfOrM207(_), scheme_resolve_expr (f , rslv ) ); 
  e = FUNCCALL_AGAIN(scheme_resolve_expr (e , rslv ) ); 
  RET_VALUE_START ((__funcarg55 = FUNCCALL_EMPTY(scheme_make_pair (f , e ) ), FUNCCALL_EMPTY(scheme_make_syntax_resolved (10 , __funcarg55 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * apply_values_shift (Scheme_Object * data , int delta , int after_depth ) {
  Scheme_Object * e ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(data, 0), PUSH(e, 1)));
# define XfOrM208_COUNT (2)
# define SETUP_XfOrM208(x) SETUP(XfOrM208_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  e = NULLED_OUT ; 
  e = FUNCCALL(SETUP_XfOrM208(_), scheme_optimize_shift ((((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) , delta , after_depth ) ); 
  (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) = e ; 
  e = FUNCCALL(SETUP_XfOrM208(_), scheme_optimize_shift ((((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) , delta , after_depth ) ); 
  (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) = e ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_syntax_compiled (10 , data ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * apply_values_clone (int dup_ok , Scheme_Object * data , Optimize_Info * info , int delta , int closure_depth ) {
  Scheme_Object * f , * e ; 
  Scheme_Object * __funcarg56 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(e, 0), PUSH(f, 1), PUSH(info, 2)));
# define XfOrM209_COUNT (3)
# define SETUP_XfOrM209(x) SETUP(XfOrM209_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  f = NULLED_OUT ; 
  e = NULLED_OUT ; 
  f = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) ; 
  e = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ; 
  f = FUNCCALL(SETUP_XfOrM209(_), scheme_optimize_clone (dup_ok , f , info , delta , closure_depth ) ); 
  if (! f )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  e = FUNCCALL(SETUP_XfOrM209(_), scheme_optimize_clone (dup_ok , e , info , delta , closure_depth ) ); 
  if (! e )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  RET_VALUE_START ((__funcarg56 = FUNCCALL_EMPTY(scheme_make_pair (f , e ) ), FUNCCALL_EMPTY(scheme_make_syntax_compiled (10 , __funcarg56 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void apply_values_validate (Scheme_Object * data , Mz_CPort * port , char * stack , Scheme_Hash_Table * ht , Scheme_Object * * tls , int depth , int letlimit , int delta , int num_toplevels , int num_stxes , int num_lifts ) {
  Scheme_Object * f , * e ; 
  PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(tls, 0), PUSH(e, 1), PUSH(stack, 2), PUSH(ht, 3), PUSH(port, 4)));
# define XfOrM210_COUNT (5)
# define SETUP_XfOrM210(x) SETUP(XfOrM210_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  f = NULLED_OUT ; 
  e = NULLED_OUT ; 
  f = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) ; 
  e = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ; 
  FUNCCALL(SETUP_XfOrM210(_), scheme_validate_expr (port , f , stack , ht , tls , depth , letlimit , delta , num_toplevels , num_stxes , num_lifts , ((void * ) 0 ) , 0 ) ); 
  FUNCCALL_EMPTY(scheme_validate_expr (port , e , stack , ht , tls , depth , letlimit , delta , num_toplevels , num_stxes , num_lifts , ((void * ) 0 ) , 0 ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 2035 */
static Scheme_Object * case_lambda_execute (Scheme_Object * expr ) {
  Scheme_Case_Lambda * seqin , * seqout ; 
  int i , cnt ; 
  Scheme_Thread * p = scheme_current_thread ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(seqin, 0), PUSH(seqout, 1), PUSH(p, 2)));
# define XfOrM211_COUNT (3)
# define SETUP_XfOrM211(x) SETUP(XfOrM211_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  seqin = NULLED_OUT ; 
  seqout = NULLED_OUT ; 
  seqin = (Scheme_Case_Lambda * ) expr ; 
  if (seqin -> native_code ) {
    Scheme_Native_Closure_Data * ndata ; 
    Scheme_Native_Closure * nc , * na ; 
    Scheme_Closure_Data * data ; 
    Scheme_Object * val ; 
    GC_CAN_IGNORE Scheme_Object * * runstack ; 
    GC_CAN_IGNORE mzshort * map ; 
    int j , jcnt ; 
    BLOCK_SETUP((PUSH(na, 0+XfOrM211_COUNT), PUSH(data, 1+XfOrM211_COUNT), PUSH(nc, 2+XfOrM211_COUNT), PUSH(val, 3+XfOrM211_COUNT)));
#   define XfOrM218_COUNT (4+XfOrM211_COUNT)
#   define SETUP_XfOrM218(x) SETUP(XfOrM218_COUNT)
    ndata = NULLED_OUT ; 
    nc = NULLED_OUT ; 
    na = NULLED_OUT ; 
    data = NULLED_OUT ; 
    val = NULLED_OUT ; 
    ndata = seqin -> native_code ; 
    nc = (Scheme_Native_Closure * ) FUNCCALL(SETUP_XfOrM218(_), scheme_make_native_case_closure (ndata ) ); 
    cnt = seqin -> count ; 
    for (i = 0 ; i < cnt ; i ++ ) {
#     define XfOrM223_COUNT (0+XfOrM218_COUNT)
#     define SETUP_XfOrM223(x) SETUP_XfOrM218(x)
      val = seqin -> array [i ] ; 
      if (! (! (((long ) (val ) ) & 0x1 ) && ((((val ) -> type ) >= scheme_prim_type ) && (((val ) -> type ) <= scheme_native_closure_type ) ) ) ) {
#       define XfOrM224_COUNT (0+XfOrM223_COUNT)
#       define SETUP_XfOrM224(x) SETUP_XfOrM223(x)
        data = (Scheme_Closure_Data * ) val ; 
        na = (Scheme_Native_Closure * ) FUNCCALL(SETUP_XfOrM224(_), scheme_make_native_closure (data -> u . native_code ) ); 
        runstack = scheme_current_runstack ; 
        jcnt = data -> closure_size ; 
        map = data -> closure_map ; 
        for (j = 0 ; j < jcnt ; j ++ ) {
          na -> vals [j ] = runstack [map [j ] ] ; 
        }
        val = (Scheme_Object * ) na ; 
      }
      nc -> vals [i ] = val ; 
    }
    RET_VALUE_START ((Scheme_Object * ) nc ) RET_VALUE_END ; 
  }
  seqout = (Scheme_Case_Lambda * ) FUNCCALL(SETUP_XfOrM211(_), GC_malloc_one_tagged (sizeof (Scheme_Case_Lambda ) + (seqin -> count - 1 ) * sizeof (Scheme_Object * ) ) ); 
  seqout -> so . type = scheme_case_closure_type ; 
  seqout -> count = seqin -> count ; 
  seqout -> name = seqin -> name ; 
  cnt = seqin -> count ; 
  for (i = 0 ; i < cnt ; i ++ ) {
#   define XfOrM215_COUNT (0+XfOrM211_COUNT)
#   define SETUP_XfOrM215(x) SETUP_XfOrM211(x)
    if (((Scheme_Type ) (((((long ) (seqin -> array [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (seqin -> array [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_closure_type ) ) ) {
      seqout -> array [i ] = seqin -> array [i ] ; 
    }
    else {
      Scheme_Object * lc ; 
      BLOCK_SETUP((PUSH(lc, 0+XfOrM215_COUNT)));
#     define XfOrM216_COUNT (1+XfOrM215_COUNT)
#     define SETUP_XfOrM216(x) SETUP(XfOrM216_COUNT)
      lc = NULLED_OUT ; 
      lc = FUNCCALL(SETUP_XfOrM216(_), scheme_make_closure (p , seqin -> array [i ] , 1 ) ); 
      seqout -> array [i ] = lc ; 
    }
  }
  RET_VALUE_START ((Scheme_Object * ) seqout ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * case_lambda_jit (Scheme_Object * expr ) {
  Scheme_Case_Lambda * seqin = (Scheme_Case_Lambda * ) expr ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(seqin, 0), PUSH(expr, 1)));
# define XfOrM227_COUNT (2)
# define SETUP_XfOrM227(x) SETUP(XfOrM227_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! seqin -> native_code ) {
    Scheme_Case_Lambda * seqout ; 
    Scheme_Native_Closure_Data * ndata ; 
    Scheme_Object * val , * name ; 
    int i , cnt , size , all_closed = 1 ; 
    BLOCK_SETUP((PUSH(val, 0+XfOrM227_COUNT), PUSH(ndata, 1+XfOrM227_COUNT), PUSH(seqout, 2+XfOrM227_COUNT), PUSH(name, 3+XfOrM227_COUNT)));
#   define XfOrM228_COUNT (4+XfOrM227_COUNT)
#   define SETUP_XfOrM228(x) SETUP(XfOrM228_COUNT)
    seqout = NULLED_OUT ; 
    ndata = NULLED_OUT ; 
    val = NULLED_OUT ; 
    name = NULLED_OUT ; 
    cnt = seqin -> count ; 
    size = sizeof (Scheme_Case_Lambda ) + ((cnt - 1 ) * sizeof (Scheme_Object * ) ) ; 
    seqout = (Scheme_Case_Lambda * ) FUNCCALL(SETUP_XfOrM228(_), GC_malloc_one_tagged (size ) ); 
    (memcpy (seqout , seqin , size ) ) ; 
    name = seqin -> name ; 
    if (name && ((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) )
      name = (((Scheme_Small_Object * ) (name ) ) -> u . ptr_val ) ; 
    for (i = 0 ; i < cnt ; i ++ ) {
      val = seqout -> array [i ] ; 
      if ((! (((long ) (val ) ) & 0x1 ) && ((((val ) -> type ) >= scheme_prim_type ) && (((val ) -> type ) <= scheme_native_closure_type ) ) ) ) {
        val = (Scheme_Object * ) ((Scheme_Closure * ) val ) -> code ; 
        seqout -> array [i ] = val ; 
      }
      ((Scheme_Closure_Data * ) val ) -> name = name ; 
      if (((Scheme_Closure_Data * ) val ) -> closure_size )
        all_closed = 0 ; 
    }
    ndata = FUNCCALL(SETUP_XfOrM228(_), scheme_generate_case_lambda (seqout ) ); 
    seqout -> native_code = ndata ; 
    if (all_closed ) {
      Scheme_Native_Closure * nc ; 
      BLOCK_SETUP((PUSH(nc, 0+XfOrM228_COUNT)));
#     define XfOrM234_COUNT (1+XfOrM228_COUNT)
#     define SETUP_XfOrM234(x) SETUP(XfOrM234_COUNT)
      nc = NULLED_OUT ; 
      nc = (Scheme_Native_Closure * ) FUNCCALL(SETUP_XfOrM234(_), scheme_make_native_case_closure (ndata ) ); 
      for (i = 0 ; i < cnt ; i ++ ) {
#       define XfOrM237_COUNT (0+XfOrM234_COUNT)
#       define SETUP_XfOrM237(x) SETUP_XfOrM234(x)
        val = seqout -> array [i ] ; 
        if (! (! (((long ) (val ) ) & 0x1 ) && ((((val ) -> type ) >= scheme_prim_type ) && (((val ) -> type ) <= scheme_native_closure_type ) ) ) ) {
#         define XfOrM238_COUNT (0+XfOrM237_COUNT)
#         define SETUP_XfOrM238(x) SETUP_XfOrM237(x)
          val = FUNCCALL(SETUP_XfOrM238(_), scheme_make_native_closure (((Scheme_Closure_Data * ) val ) -> u . native_code ) ); 
        }
        nc -> vals [i ] = val ; 
      }
      RET_VALUE_START ((Scheme_Object * ) nc ) RET_VALUE_END ; 
    }
    else {
#     define XfOrM229_COUNT (0+XfOrM228_COUNT)
#     define SETUP_XfOrM229(x) SETUP_XfOrM228(x)
      for (i = 0 ; i < cnt ; i ++ ) {
#       define XfOrM232_COUNT (0+XfOrM229_COUNT)
#       define SETUP_XfOrM232(x) SETUP_XfOrM229(x)
        val = seqout -> array [i ] ; 
        if (! (! (((long ) (val ) ) & 0x1 ) && ((((val ) -> type ) >= scheme_prim_type ) && (((val ) -> type ) <= scheme_native_closure_type ) ) ) ) {
          Scheme_Closure_Data * data ; 
          BLOCK_SETUP((PUSH(data, 0+XfOrM232_COUNT)));
#         define XfOrM233_COUNT (1+XfOrM232_COUNT)
#         define SETUP_XfOrM233(x) SETUP(XfOrM233_COUNT)
          data = NULLED_OUT ; 
          data = ((Scheme_Closure_Data * ) FUNCCALL(SETUP_XfOrM233(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Closure_Data ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
          (memcpy (data , val , sizeof (Scheme_Closure_Data ) ) ) ; 
          data -> code = ((void * ) 0 ) ; 
          seqout -> array [i ] = (Scheme_Object * ) data ; 
        }
      }
    }
    RET_VALUE_START ((Scheme_Object * ) seqout ) RET_VALUE_END ; 
  }
  RET_VALUE_START (expr ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void case_lambda_validate (Scheme_Object * data , Mz_CPort * port , char * stack , Scheme_Hash_Table * ht , Scheme_Object * * tls , int depth , int letlimit , int delta , int num_toplevels , int num_stxes , int num_lifts ) {
  Scheme_Case_Lambda * seq = (Scheme_Case_Lambda * ) data ; 
  int i ; 
  PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(stack, 0), PUSH(ht, 1), PUSH(seq, 2), PUSH(tls, 3), PUSH(port, 4)));
# define XfOrM243_COUNT (5)
# define SETUP_XfOrM243(x) SETUP(XfOrM243_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  for (i = 0 ; i < seq -> count ; i ++ ) {
#   define XfOrM245_COUNT (0+XfOrM243_COUNT)
#   define SETUP_XfOrM245(x) SETUP_XfOrM243(x)
    FUNCCALL(SETUP_XfOrM245(_), scheme_validate_expr (port , seq -> array [i ] , stack , ht , tls , depth , letlimit , delta , num_toplevels , num_stxes , num_lifts , ((void * ) 0 ) , 0 ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * case_lambda_resolve (Scheme_Object * expr , Resolve_Info * rslv ) {
  int i , all_closed = 1 ; 
  Scheme_Case_Lambda * seq = (Scheme_Case_Lambda * ) expr ; 
  PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(seq, 0), PUSH(expr, 1), PUSH(rslv, 2)));
# define XfOrM246_COUNT (3)
# define SETUP_XfOrM246(x) SETUP(XfOrM246_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  for (i = 0 ; i < seq -> count ; i ++ ) {
    Scheme_Object * le ; 
    BLOCK_SETUP((PUSH(le, 0+XfOrM246_COUNT)));
#   define XfOrM249_COUNT (1+XfOrM246_COUNT)
#   define SETUP_XfOrM249(x) SETUP(XfOrM249_COUNT)
    le = NULLED_OUT ; 
    le = seq -> array [i ] ; 
    le = FUNCCALL(SETUP_XfOrM249(_), scheme_resolve_closure_compilation (le , rslv , 0 , 0 , 0 , ((void * ) 0 ) ) ); 
    seq -> array [i ] = le ; 
    if (! (! (((long ) (le ) ) & 0x1 ) && ((((le ) -> type ) >= scheme_prim_type ) && (((le ) -> type ) <= scheme_native_closure_type ) ) ) )
      all_closed = 0 ; 
  }
  if (all_closed ) {
#   define XfOrM247_COUNT (0+XfOrM246_COUNT)
#   define SETUP_XfOrM247(x) SETUP_XfOrM246(x)
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(case_lambda_execute (expr ) )) RET_VALUE_EMPTY_END ; 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_syntax_resolved (3 , expr ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * case_lambda_optimize (Scheme_Object * expr , Optimize_Info * info ) {
  Scheme_Object * le ; 
  int i ; 
  Scheme_Case_Lambda * seq = (Scheme_Case_Lambda * ) expr ; 
  PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(info, 0), PUSH(seq, 1), PUSH(expr, 2), PUSH(le, 3)));
# define XfOrM250_COUNT (4)
# define SETUP_XfOrM250(x) SETUP(XfOrM250_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  le = NULLED_OUT ; 
  for (i = 0 ; i < seq -> count ; i ++ ) {
#   define XfOrM252_COUNT (0+XfOrM250_COUNT)
#   define SETUP_XfOrM252(x) SETUP_XfOrM250(x)
    le = seq -> array [i ] ; 
    le = FUNCCALL(SETUP_XfOrM252(_), scheme_optimize_expr (le , info ) ); 
    seq -> array [i ] = le ; 
  }
  info -> preserves_marks = 1 ; 
  info -> single_result = 1 ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_syntax_compiled (3 , expr ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * case_lambda_shift (Scheme_Object * data , int delta , int after_depth ) {
  Scheme_Object * le ; 
  int i ; 
  Scheme_Case_Lambda * seq = (Scheme_Case_Lambda * ) data ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(seq, 0), PUSH(data, 1), PUSH(le, 2)));
# define XfOrM253_COUNT (3)
# define SETUP_XfOrM253(x) SETUP(XfOrM253_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  le = NULLED_OUT ; 
  for (i = 0 ; i < seq -> count ; i ++ ) {
#   define XfOrM255_COUNT (0+XfOrM253_COUNT)
#   define SETUP_XfOrM255(x) SETUP_XfOrM253(x)
    le = seq -> array [i ] ; 
    le = FUNCCALL(SETUP_XfOrM255(_), scheme_optimize_shift (le , delta , after_depth ) ); 
    seq -> array [i ] = le ; 
  }
  RET_VALUE_START (data ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_unclose_case_lambda (Scheme_Object * expr , int jit ) {
  Scheme_Case_Lambda * cl = (Scheme_Case_Lambda * ) expr ; 
  Scheme_Closure * c ; 
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(c, 0), PUSH(expr, 1), PUSH(cl, 2)));
# define XfOrM256_COUNT (3)
# define SETUP_XfOrM256(x) SETUP(XfOrM256_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  c = NULLED_OUT ; 
  for (i = cl -> count ; i -- ; ) {
    c = (Scheme_Closure * ) cl -> array [i ] ; 
    if (! ! (c -> code -> closure_size ) ) {
      break ; 
    }
  }
  if (i < 0 ) {
    Scheme_Case_Lambda * cl2 ; 
    BLOCK_SETUP((PUSH(cl2, 0+XfOrM256_COUNT)));
#   define XfOrM257_COUNT (1+XfOrM256_COUNT)
#   define SETUP_XfOrM257(x) SETUP(XfOrM257_COUNT)
    cl2 = NULLED_OUT ; 
    cl2 = (Scheme_Case_Lambda * ) FUNCCALL(SETUP_XfOrM257(_), GC_malloc_one_tagged (sizeof (Scheme_Case_Lambda ) + ((cl -> count - 1 ) * sizeof (Scheme_Object * ) ) ) ); 
    cl2 -> so . type = scheme_case_lambda_sequence_type ; 
    cl2 -> count = cl -> count ; 
    cl2 -> name = cl -> name ; 
    for (i = cl -> count ; i -- ; ) {
      c = (Scheme_Closure * ) cl -> array [i ] ; 
      cl2 -> array [i ] = (Scheme_Object * ) c -> code ; 
    }
    if (jit )
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(case_lambda_jit ((Scheme_Object * ) cl2 ) )) RET_VALUE_EMPTY_END ; 
    else RET_VALUE_START ((Scheme_Object * ) cl2 ) RET_VALUE_END ; 
  }
  RET_VALUE_START (expr ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void case_lambda_check_line (Scheme_Object * line , Scheme_Object * form , Scheme_Comp_Env * env ) {
  Scheme_Object * body , * args ; 
  PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(args, 0), PUSH(env, 1), PUSH(body, 2), PUSH(form, 3), PUSH(line, 4)));
# define XfOrM264_COUNT (5)
# define SETUP_XfOrM264(x) SETUP(XfOrM264_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  body = NULLED_OUT ; 
  args = NULLED_OUT ; 
  if (! (((Scheme_Type ) (((((long ) (line ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (line ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (line ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (line ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) line ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) line ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , line , form , ((void * ) 0 ) ) ); 
  body = (((Scheme_Type ) (((((long ) (line ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (line ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (line ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM264(_), scheme_stx_content (line ) )) ) -> u . pair_val . cdr ) ) ; 
  args = (((Scheme_Type ) (((((long ) (line ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (line ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (line ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM264(_), scheme_stx_content (line ) )) ) -> u . pair_val . car ) ) ; 
  FUNCCALL(SETUP_XfOrM264(_), lambda_check_args (args , form , env ) ); 
  if (! (((Scheme_Type ) (((((long ) (body ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (body ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (body ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (body ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) body ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) body ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , line , form , "bad syntax (%s)" , (((body ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (body ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (body ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) body ) -> val ) == (scheme_null ) ) ) ) ? "empty body" : "illegal use of `.'" ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 2339 */
/* this far 2273 */
static Scheme_Object * case_lambda_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  Scheme_Object * list , * last , * c , * orig_form = form , * name ; 
  Scheme_Case_Lambda * cl ; 
  int i , count = 0 ; 
  Scheme_Compile_Info * recs ; 
  Scheme_Object * __funcarg60 = NULLED_OUT ; 
  Scheme_Object * __funcarg59 = NULLED_OUT ; 
  Scheme_Object * __funcarg58 = NULLED_OUT ; 
  PREPARE_VAR_STACK(11);
  BLOCK_SETUP_TOP((PUSH(list, 0), PUSH(env, 1), PUSH(rec, 2), PUSH(last, 3), PUSH(cl, 4), PUSH(recs, 5), PUSH(c, 6), PUSH(orig_form, 7), PUSH(name, 8), PUSH(form, 9)));
# define XfOrM265_COUNT (10)
# define SETUP_XfOrM265(x) SETUP(XfOrM265_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  list = NULLED_OUT ; 
  last = NULLED_OUT ; 
  c = NULLED_OUT ; 
  name = NULLED_OUT ; 
  cl = NULLED_OUT ; 
  recs = NULLED_OUT ; 
  form = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM265(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  name = FUNCCALL(SETUP_XfOrM265(_), scheme_build_closure_name (orig_form , rec , drec ) ); 
  if ((((form ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) form ) -> val ) == (scheme_null ) ) ) ) ) {
#   define XfOrM275_COUNT (0+XfOrM265_COUNT)
#   define SETUP_XfOrM275(x) SETUP_XfOrM265(x)
    form = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM275(_), GC_malloc_one_tagged (sizeof (Scheme_Case_Lambda ) - sizeof (Scheme_Object * ) ) ); 
    form -> type = scheme_case_lambda_sequence_type ; 
    ((Scheme_Case_Lambda * ) form ) -> count = 0 ; 
    ((Scheme_Case_Lambda * ) form ) -> name = name ; 
    FUNCCALL(SETUP_XfOrM275(_), scheme_compile_rec_done_local (rec , drec ) ); 
    FUNCCALL_AGAIN(scheme_default_compile_rec (rec , drec ) ); 
    if (FUNCCALL(SETUP_XfOrM275(_), scheme_has_method_property (orig_form ) )) {
#     define XfOrM276_COUNT (0+XfOrM275_COUNT)
#     define SETUP_XfOrM276(x) SETUP_XfOrM275(x)
      if (! name )
        name = scheme_false ; 
      name = FUNCCALL(SETUP_XfOrM276(_), scheme_box (name ) ); 
      ((Scheme_Case_Lambda * ) form ) -> name = name ; 
    }
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_syntax_compiled (3 , form ) )) RET_VALUE_EMPTY_END ; 
  }
  if (! (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) form ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) form ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , form , orig_form , ((void * ) 0 ) ) ); 
  if (((((((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM265(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) ((((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM265(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM265(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM265(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ) -> val ) == (scheme_null ) ) ) ) ) {
#   define XfOrM274_COUNT (0+XfOrM265_COUNT)
#   define SETUP_XfOrM274(x) SETUP_XfOrM265(x)
    c = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM274(_), scheme_stx_content (form ) )) ) -> u . pair_val . car ) ) ; 
    FUNCCALL(SETUP_XfOrM274(_), case_lambda_check_line (c , orig_form , env ) ); 
    c = (__funcarg59 = (__funcarg60 = FUNCCALL(SETUP_XfOrM274(_), scheme_sys_wraps (env ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (lambda_symbol , scheme_false , __funcarg60 , 0 , 0 ) )) , FUNCCALL_AGAIN(scheme_make_immutable_pair (__funcarg59 , c ) )) ; 
    c = FUNCCALL_AGAIN(scheme_datum_to_syntax (c , orig_form , orig_form , 0 , 2 ) ); 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(lambda_syntax (c , env , rec , drec ) )) RET_VALUE_EMPTY_END ; 
  }
  FUNCCALL(SETUP_XfOrM265(_), scheme_compile_rec_done_local (rec , drec ) ); 
  FUNCCALL(SETUP_XfOrM265(_), scheme_rec_add_certs (rec , drec , orig_form ) ); 
  list = last = ((void * ) 0 ) ; 
  while ((((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) form ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) form ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
    Scheme_Object * clause ; 
    BLOCK_SETUP((PUSH(clause, 0+XfOrM265_COUNT)));
#   define XfOrM273_COUNT (1+XfOrM265_COUNT)
#   define SETUP_XfOrM273(x) SETUP(XfOrM273_COUNT)
    clause = NULLED_OUT ; 
    clause = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM273(_), scheme_stx_content (form ) )) ) -> u . pair_val . car ) ) ; 
    FUNCCALL(SETUP_XfOrM273(_), case_lambda_check_line (clause , orig_form , env ) ); 
    c = FUNCCALL_AGAIN(scheme_make_immutable_pair (lambda_symbol , clause ) ); 
    c = (__funcarg58 = FUNCCALL(SETUP_XfOrM273(_), scheme_sys_wraps (env ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (c , clause , __funcarg58 , 0 , 0 ) )) ; 
    c = FUNCCALL_AGAIN(scheme_make_pair (c , scheme_null ) ); 
    if (list )
      (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = c ; 
    else list = c ; 
    last = c ; 
    form = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM273(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
    count ++ ; 
  }
  if (! (((form ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) form ) -> val ) == (scheme_null ) ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , form , orig_form , ((void * ) 0 ) ) ); 
  cl = (Scheme_Case_Lambda * ) FUNCCALL(SETUP_XfOrM265(_), GC_malloc_one_tagged (sizeof (Scheme_Case_Lambda ) + (count - 1 ) * sizeof (Scheme_Object * ) ) ); 
  cl -> so . type = scheme_case_lambda_sequence_type ; 
  cl -> count = count ; 
  cl -> name = (! (((name ) ) == (scheme_false ) ) ) ? name : ((void * ) 0 ) ; 
  FUNCCALL(SETUP_XfOrM265(_), scheme_compile_rec_done_local (rec , drec ) ); 
  recs = ((Scheme_Compile_Info * ) FUNCCALL(SETUP_XfOrM265(_), GC_malloc_array_tagged (sizeof (Scheme_Compile_Info ) * (count ) ) )) ; 
  FUNCCALL(SETUP_XfOrM265(_), scheme_init_compile_recs (rec , drec , recs , count ) ); 
  for (i = 0 ; i < count ; i ++ ) {
    Scheme_Object * ce ; 
    BLOCK_SETUP((PUSH(ce, 0+XfOrM265_COUNT)));
#   define XfOrM271_COUNT (1+XfOrM265_COUNT)
#   define SETUP_XfOrM271(x) SETUP(XfOrM271_COUNT)
    ce = NULLED_OUT ; 
    ce = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . car ) ; 
    ce = FUNCCALL(SETUP_XfOrM271(_), scheme_compile_expr (ce , env , recs , i ) ); 
    cl -> array [i ] = ce ; 
    list = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . cdr ) ; 
  }
  FUNCCALL(SETUP_XfOrM265(_), scheme_merge_compile_recs (rec , drec , recs , count ) ); 
  if (FUNCCALL(SETUP_XfOrM265(_), scheme_has_method_property (orig_form ) )) {
    Scheme_Closure_Data * data ; 
    data = NULLED_OUT ; 
    for (i = 0 ; i < count ; i ++ ) {
      data = (Scheme_Closure_Data * ) cl -> array [i ] ; 
      if (! data -> num_params )
        break ; 
    }
    if (i >= count ) {
      data = (Scheme_Closure_Data * ) cl -> array [0 ] ; 
      (& (data ) -> iso ) -> so . keyex |= 16 ; 
    }
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_syntax_compiled (3 , (Scheme_Object * ) cl ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * case_lambda_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  Scheme_Object * first , * last , * args , * body , * c , * new_line , * orig_form = form ; 
  Scheme_Object * __funcarg64 = NULLED_OUT ; 
  Scheme_Object * __funcarg63 = NULLED_OUT ; 
  PREPARE_VAR_STACK(15);
  BLOCK_SETUP_TOP((PUSH(first, 0), PUSH(env, 1), PUSH(c, 2), PUSH(last, 3), PUSH(erec, 4), PUSH(new_line, 5), PUSH(args, 6), PUSH(orig_form, 7), PUSH(form, 8), PUSH(body, 9)));
# define XfOrM277_COUNT (10)
# define SETUP_XfOrM277(x) SETUP(XfOrM277_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  first = NULLED_OUT ; 
  last = NULLED_OUT ; 
  args = NULLED_OUT ; 
  body = NULLED_OUT ; 
  c = NULLED_OUT ; 
  new_line = NULLED_OUT ; 
  if (erec [drec ] . observer ) {
#   define XfOrM291_COUNT (0+XfOrM277_COUNT)
#   define SETUP_XfOrM291(x) SETUP_XfOrM277(x)
    FUNCCALL(SETUP_XfOrM291(_), scheme_call_expand_observe (erec [drec ] . observer , 111 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  first = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM277(_), scheme_stx_content (form ) )) ) -> u . pair_val . car ) ) ; 
  first = FUNCCALL(SETUP_XfOrM277(_), scheme_make_immutable_pair (first , scheme_null ) ); 
  last = first ; 
  form = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM277(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  FUNCCALL(SETUP_XfOrM277(_), scheme_rec_add_certs (erec , drec , orig_form ) ); 
  while ((((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) form ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) form ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
    Scheme_Object * line_form ; 
    Scheme_Comp_Env * newenv ; 
    BLOCK_SETUP((PUSH(line_form, 0+XfOrM277_COUNT), PUSH(newenv, 1+XfOrM277_COUNT)));
#   define XfOrM284_COUNT (2+XfOrM277_COUNT)
#   define SETUP_XfOrM284(x) SETUP(XfOrM284_COUNT)
    line_form = NULLED_OUT ; 
    newenv = NULLED_OUT ; 
    if (erec [drec ] . observer ) {
#     define XfOrM289_COUNT (0+XfOrM284_COUNT)
#     define SETUP_XfOrM289(x) SETUP_XfOrM284(x)
      FUNCCALL(SETUP_XfOrM289(_), scheme_call_expand_observe (erec [drec ] . observer , 3 , ((void * ) 0 ) ) ); 
    }
    else {
    }
    ; 
    line_form = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM284(_), scheme_stx_content (form ) )) ) -> u . pair_val . car ) ) ; 
    FUNCCALL(SETUP_XfOrM284(_), case_lambda_check_line (line_form , orig_form , env ) ); 
    body = (((Scheme_Type ) (((((long ) (line_form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (line_form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (line_form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM284(_), scheme_stx_content (line_form ) )) ) -> u . pair_val . cdr ) ) ; 
    args = (((Scheme_Type ) (((((long ) (line_form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (line_form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (line_form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM284(_), scheme_stx_content (line_form ) )) ) -> u . pair_val . car ) ) ; 
    body = FUNCCALL(SETUP_XfOrM284(_), scheme_datum_to_syntax (body , line_form , line_form , 0 , 0 ) ); 
    newenv = FUNCCALL_AGAIN(scheme_add_compilation_frame (args , env , 0 , erec [drec ] . certs ) ); 
    body = FUNCCALL_AGAIN(scheme_add_env_renames (body , newenv , env ) ); 
    args = FUNCCALL_AGAIN(scheme_add_env_renames (args , newenv , env ) ); 
    if (erec [drec ] . observer ) {
#     define XfOrM287_COUNT (0+XfOrM284_COUNT)
#     define SETUP_XfOrM287(x) SETUP_XfOrM284(x)
      (__funcarg64 = FUNCCALL(SETUP_XfOrM287(_), scheme_make_immutable_pair (args , body ) ), FUNCCALL_AGAIN(scheme_call_expand_observe (erec [drec ] . observer , 18 , __funcarg64 ) )) ; 
    }
    else {
    }
    ; 
    {
      Scheme_Expand_Info erec1 ; 
      BLOCK_SETUP((PUSH(erec1.value_name, 0+XfOrM284_COUNT), PUSH(erec1.certs, 1+XfOrM284_COUNT), PUSH(erec1.observer, 2+XfOrM284_COUNT)));
#     define XfOrM285_COUNT (3+XfOrM284_COUNT)
#     define SETUP_XfOrM285(x) SETUP(XfOrM285_COUNT)
      erec1.value_name = NULLED_OUT ; 
      erec1.certs = NULLED_OUT ; 
      erec1.observer = NULLED_OUT ; 
      FUNCCALL(SETUP_XfOrM285(_), scheme_init_expand_recs (erec , drec , & erec1 , 1 ) ); 
      erec1 . value_name = scheme_false ; 
      new_line = (__funcarg63 = FUNCCALL(SETUP_XfOrM285(_), scheme_expand_block (body , newenv , & erec1 , 0 ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (args , __funcarg63 ) )) ; 
    }
    new_line = FUNCCALL(SETUP_XfOrM284(_), scheme_datum_to_syntax (new_line , line_form , line_form , 0 , 1 ) ); 
    c = FUNCCALL(SETUP_XfOrM284(_), scheme_make_immutable_pair (new_line , scheme_null ) ); 
    (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = c ; 
    last = c ; 
    form = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM284(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  }
  if (! (((form ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) form ) -> val ) == (scheme_null ) ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , form , orig_form , ((void * ) 0 ) ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_datum_to_syntax (first , orig_form , orig_form , 0 , 2 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * bangboxenv_execute (Scheme_Object * data ) {
  int pos = (((long ) ((((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) ) ) >> 1 ) ; 
  Scheme_Object * bb ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(bb, 0), PUSH(data, 1)));
# define XfOrM292_COUNT (2)
# define SETUP_XfOrM292(x) SETUP(XfOrM292_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  bb = NULLED_OUT ; 
  data = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ; 
  bb = FUNCCALL(SETUP_XfOrM292(_), scheme_make_envunbox (scheme_current_runstack [pos ] ) ); 
  scheme_current_runstack [pos ] = bb ; 
  RET_VALUE_START (((scheme_current_thread -> ku . eval . wait_expr ) = data , ((Scheme_Object * ) 0x2 ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * bangboxenv_jit (Scheme_Object * data ) {
  Scheme_Object * orig , * naya ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(naya, 0), PUSH(data, 1), PUSH(orig, 2)));
# define XfOrM293_COUNT (3)
# define SETUP_XfOrM293(x) SETUP(XfOrM293_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  orig = NULLED_OUT ; 
  naya = NULLED_OUT ; 
  orig = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ; 
  naya = FUNCCALL(SETUP_XfOrM293(_), scheme_jit_expr (orig ) ); 
  if (((naya ) == (orig ) ) )
    RET_VALUE_START (data ) RET_VALUE_END ; 
  else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_pair ((((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) , naya ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void bangboxenv_validate (Scheme_Object * data , Mz_CPort * port , char * stack , Scheme_Hash_Table * ht , Scheme_Object * * tls , int depth , int letlimit , int delta , int num_toplevels , int num_stxes , int num_lifts ) {
  PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(stack, 0), PUSH(ht, 1), PUSH(data, 2), PUSH(tls, 3), PUSH(port, 4)));
# define XfOrM294_COUNT (5)
# define SETUP_XfOrM294(x) SETUP(XfOrM294_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! ((Scheme_Type ) (((((long ) (data ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (data ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    FUNCCALL(SETUP_XfOrM294(_), scheme_ill_formed (port , "./../src/syntax.c" , 2471 ) ); 
  FUNCCALL(SETUP_XfOrM294(_), scheme_validate_boxenv ((((long ) ((((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) ) ) >> 1 ) , port , stack , depth , delta ) ); 
  FUNCCALL_EMPTY(scheme_validate_expr (port , (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) , stack , ht , tls , depth , letlimit , delta , num_toplevels , num_stxes , num_lifts , ((void * ) 0 ) , 0 ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int is_liftable (Scheme_Object * o , int bind_count , int fuel ) {
  Scheme_Type t = ((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(o, 0)));
# define XfOrM295_COUNT (1)
# define SETUP_XfOrM295(x) SETUP(XfOrM295_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  switch (t ) {
#   define XfOrM296_COUNT (0+XfOrM295_COUNT)
#   define SETUP_XfOrM296(x) SETUP_XfOrM295(x)
    case scheme_compiled_toplevel_type : RET_VALUE_START (1 ) RET_VALUE_END ; 
    case scheme_local_type : if ((((Scheme_Local * ) (o ) ) -> position ) > bind_count )
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    break ; 
    case scheme_branch_type : if (fuel ) {
      Scheme_Branch_Rec * b = (Scheme_Branch_Rec * ) o ; 
      BLOCK_SETUP((PUSH(b, 0+XfOrM296_COUNT)));
#     define XfOrM302_COUNT (1+XfOrM296_COUNT)
#     define SETUP_XfOrM302(x) SETUP(XfOrM302_COUNT)
      if (FUNCCALL(SETUP_XfOrM302(_), is_liftable (b -> test , bind_count , fuel - 1 ) )&& FUNCCALL(SETUP_XfOrM302(_), is_liftable (b -> tbranch , bind_count , fuel - 1 ) )&& FUNCCALL(SETUP_XfOrM302(_), is_liftable (b -> fbranch , bind_count , fuel - 1 ) ))
        RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
    break ; 
    case scheme_application_type : {
      Scheme_App_Rec * app = (Scheme_App_Rec * ) o ; 
      int i ; 
      BLOCK_SETUP((PUSH(app, 0+XfOrM296_COUNT)));
#     define XfOrM299_COUNT (1+XfOrM296_COUNT)
#     define SETUP_XfOrM299(x) SETUP(XfOrM299_COUNT)
      for (i = app -> num_args + 1 ; i -- ; ) {
#       define XfOrM301_COUNT (0+XfOrM299_COUNT)
#       define SETUP_XfOrM301(x) SETUP_XfOrM299(x)
        if (! FUNCCALL(SETUP_XfOrM301(_), is_liftable (app -> args [i ] , bind_count + app -> num_args , fuel - 1 ) ))
          RET_VALUE_START (0 ) RET_VALUE_END ; 
      }
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
    case scheme_application2_type : {
      Scheme_App2_Rec * app = (Scheme_App2_Rec * ) o ; 
      BLOCK_SETUP((PUSH(app, 0+XfOrM296_COUNT)));
#     define XfOrM298_COUNT (1+XfOrM296_COUNT)
#     define SETUP_XfOrM298(x) SETUP(XfOrM298_COUNT)
      if (FUNCCALL(SETUP_XfOrM298(_), is_liftable (app -> rator , bind_count + 1 , fuel - 1 ) )&& FUNCCALL(SETUP_XfOrM298(_), is_liftable (app -> rand , bind_count + 1 , fuel - 1 ) ))
        RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
    case scheme_application3_type : {
      Scheme_App3_Rec * app = (Scheme_App3_Rec * ) o ; 
      BLOCK_SETUP((PUSH(app, 0+XfOrM296_COUNT)));
#     define XfOrM297_COUNT (1+XfOrM296_COUNT)
#     define SETUP_XfOrM297(x) SETUP(XfOrM297_COUNT)
      if (FUNCCALL(SETUP_XfOrM297(_), is_liftable (app -> rator , bind_count + 2 , fuel - 1 ) )&& FUNCCALL(SETUP_XfOrM297(_), is_liftable (app -> rand1 , bind_count + 2 , fuel - 1 ) )&& FUNCCALL_EMPTY(is_liftable (app -> rand2 , bind_count + 2 , fuel - 1 ) ))
        RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
    default : if (t > _scheme_compiled_values_types_ )
      RET_VALUE_START (1 ) RET_VALUE_END ; 
  }
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_compiled_propagate_ok (Scheme_Object * value , Optimize_Info * info ) {
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(value, 0), PUSH(info, 1)));
# define XfOrM303_COUNT (2)
# define SETUP_XfOrM303(x) SETUP(XfOrM303_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (FUNCCALL(SETUP_XfOrM303(_), scheme_compiled_duplicate_ok (value ) ))
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  if (((Scheme_Type ) (((((long ) (value ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (value ) ) -> type ) ) == (Scheme_Type ) (scheme_compiled_unclosed_procedure_type ) ) ) {
    int sz ; 
#   define XfOrM306_COUNT (0+XfOrM303_COUNT)
#   define SETUP_XfOrM306(x) SETUP_XfOrM303(x)
    sz = FUNCCALL(SETUP_XfOrM306(_), scheme_closure_body_size ((Scheme_Closure_Data * ) value , 1 ) ); 
    if ((sz >= 0 ) && (sz <= 256 ) )
      RET_VALUE_START (1 ) RET_VALUE_END ; 
  }
  if (((Scheme_Type ) (((((long ) (value ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (value ) ) -> type ) ) == (Scheme_Type ) (scheme_compiled_toplevel_type ) ) ) {
#   define XfOrM304_COUNT (0+XfOrM303_COUNT)
#   define SETUP_XfOrM304(x) SETUP_XfOrM303(x)
    if (info -> top_level_consts ) {
      int pos ; 
#     define XfOrM305_COUNT (0+XfOrM304_COUNT)
#     define SETUP_XfOrM305(x) SETUP_XfOrM304(x)
      pos = (((Scheme_Toplevel * ) (value ) ) -> position ) ; 
      value = FUNCCALL(SETUP_XfOrM305(_), scheme_hash_get (info -> top_level_consts , ((Scheme_Object * ) (void * ) (long ) ((((long ) (pos ) ) << 1 ) | 0x1 ) ) ) ); 
      if (value )
        RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
  }
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int is_values_apply (Scheme_Object * e ) {
  /* No conversion */
  if (((Scheme_Type ) (((((long ) (e ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e ) ) -> type ) ) == (Scheme_Type ) (scheme_application_type ) ) ) {
    Scheme_App_Rec * app = (Scheme_App_Rec * ) e ; 
    return ((scheme_values_func ) == (app -> args [0 ] ) ) ; 
  }
  else if (((Scheme_Type ) (((((long ) (e ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e ) ) -> type ) ) == (Scheme_Type ) (scheme_application2_type ) ) ) {
    Scheme_App2_Rec * app = (Scheme_App2_Rec * ) e ; 
    return ((scheme_values_func ) == (app -> rator ) ) ; 
  }
  else if (((Scheme_Type ) (((((long ) (e ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e ) ) -> type ) ) == (Scheme_Type ) (scheme_application3_type ) ) ) {
    Scheme_App3_Rec * app = (Scheme_App3_Rec * ) e ; 
    return ((scheme_values_func ) == (app -> rator ) ) ; 
  }
  return 0 ; 
}
static void unpack_values_application (Scheme_Object * e , Scheme_Compiled_Let_Value * naya ) {
  /* No conversion */
  if (((Scheme_Type ) (((((long ) (e ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e ) ) -> type ) ) == (Scheme_Type ) (scheme_application_type ) ) ) {
    Scheme_App_Rec * app = (Scheme_App_Rec * ) e ; 
    int i ; 
    for (i = 0 ; i < app -> num_args ; i ++ ) {
      naya -> value = app -> args [i + 1 ] ; 
      naya = (Scheme_Compiled_Let_Value * ) naya -> body ; 
    }
  }
  else if (((Scheme_Type ) (((((long ) (e ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e ) ) -> type ) ) == (Scheme_Type ) (scheme_application2_type ) ) ) {
    Scheme_App2_Rec * app = (Scheme_App2_Rec * ) e ; 
    naya -> value = app -> rand ; 
  }
  else if (((Scheme_Type ) (((((long ) (e ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e ) ) -> type ) ) == (Scheme_Type ) (scheme_application3_type ) ) ) {
    Scheme_App3_Rec * app = (Scheme_App3_Rec * ) e ; 
    naya -> value = app -> rand1 ; 
    naya = (Scheme_Compiled_Let_Value * ) naya -> body ; 
    naya -> value = app -> rand2 ; 
  }
}
static Scheme_Object * make_clones (Scheme_Compiled_Let_Value * retry_start , Scheme_Compiled_Let_Value * pre_body , Optimize_Info * body_info ) {
  Scheme_Compiled_Let_Value * clv ; 
  Scheme_Object * value , * clone , * pr ; 
  Scheme_Object * last = ((void * ) 0 ) , * first = ((void * ) 0 ) ; 
  Scheme_Object * __funcarg66 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(8);
  BLOCK_SETUP_TOP((PUSH(first, 0), PUSH(body_info, 1), PUSH(clone, 2), PUSH(pr, 3), PUSH(last, 4), PUSH(pre_body, 5), PUSH(clv, 6), PUSH(value, 7)));
# define XfOrM317_COUNT (8)
# define SETUP_XfOrM317(x) SETUP(XfOrM317_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  clv = NULLED_OUT ; 
  value = NULLED_OUT ; 
  clone = NULLED_OUT ; 
  pr = NULLED_OUT ; 
  clv = retry_start ; 
  while (1 ) {
#   define XfOrM321_COUNT (0+XfOrM317_COUNT)
#   define SETUP_XfOrM321(x) SETUP_XfOrM317(x)
    value = clv -> value ; 
    if (((Scheme_Type ) (((((long ) (value ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (value ) ) -> type ) ) == (Scheme_Type ) (scheme_compiled_unclosed_procedure_type ) ) ) {
#     define XfOrM322_COUNT (0+XfOrM321_COUNT)
#     define SETUP_XfOrM322(x) SETUP_XfOrM321(x)
      clone = FUNCCALL(SETUP_XfOrM322(_), scheme_optimize_clone (1 , value , body_info , 0 , 0 ) ); 
      if (clone ) {
#       define XfOrM323_COUNT (0+XfOrM322_COUNT)
#       define SETUP_XfOrM323(x) SETUP_XfOrM322(x)
        pr = (__funcarg66 = FUNCCALL(SETUP_XfOrM323(_), scheme_make_raw_pair (value , clone ) ), FUNCCALL_AGAIN(scheme_make_raw_pair (__funcarg66 , ((void * ) 0 ) ) )) ; 
        if (last )
          (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = pr ; 
        else first = pr ; 
        last = pr ; 
      }
    }
    if (clv == pre_body )
      break ; 
    clv = (Scheme_Compiled_Let_Value * ) clv -> body ; 
  }
  RET_VALUE_START (first ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int set_code_flags (Scheme_Compiled_Let_Value * retry_start , Scheme_Compiled_Let_Value * pre_body , Scheme_Object * clones , int set_flags , int mask_flags ) {
  /* No conversion */
  Scheme_Compiled_Let_Value * clv ; 
  Scheme_Object * value , * first ; 
  int flags = 32 | 4 ; 
  Scheme_Closure_Data * data ; 
  clv = retry_start ; 
  while (clones ) {
    value = retry_start -> value ; 
    if (((Scheme_Type ) (scheme_compiled_unclosed_procedure_type ) == (Scheme_Type ) (((((long ) (value ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (value ) ) -> type ) ) ) ) {
      data = (Scheme_Closure_Data * ) value ; 
      flags = (flags & (& (data ) -> iso ) -> so . keyex ) ; 
      first = (((Scheme_Simple_Object * ) (clones ) ) -> u . pair_val . car ) ; 
      data = (Scheme_Closure_Data * ) (((Scheme_Simple_Object * ) (first ) ) -> u . pair_val . cdr ) ; 
      (& (data ) -> iso ) -> so . keyex = set_flags | ((& (data ) -> iso ) -> so . keyex & mask_flags ) ; 
      data = (Scheme_Closure_Data * ) (((Scheme_Simple_Object * ) (first ) ) -> u . pair_val . car ) ; 
      (& (data ) -> iso ) -> so . keyex = set_flags | ((& (data ) -> iso ) -> so . keyex & mask_flags ) ; 
      clones = (((Scheme_Simple_Object * ) (clones ) ) -> u . pair_val . cdr ) ; 
    }
    if (clv == pre_body )
      break ; 
    clv = (Scheme_Compiled_Let_Value * ) clv -> body ; 
  }
  return flags ; 
}
Scheme_Object * scheme_optimize_lets (Scheme_Object * form , Optimize_Info * info , int for_inline ) {
  Optimize_Info * body_info , * rhs_info ; 
  Scheme_Let_Header * head = (Scheme_Let_Header * ) form ; 
  Scheme_Compiled_Let_Value * clv , * pre_body , * retry_start , * prev_body ; 
  Scheme_Object * body , * value ; 
  int i , j , pos , is_rec , not_simply_let_star = 0 ; 
  int size_before_opt , did_set_value ; 
  int remove_last_one = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(15);
  BLOCK_SETUP_TOP((PUSH(head, 0), PUSH(rhs_info, 1), PUSH(body_info, 2), PUSH(retry_start, 3), PUSH(clv, 4), PUSH(info, 5), PUSH(pre_body, 6), PUSH(form, 7), PUSH(body, 8), PUSH(value, 9), PUSH(prev_body, 10)));
# define XfOrM329_COUNT (11)
# define SETUP_XfOrM329(x) SETUP(XfOrM329_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  body_info = NULLED_OUT ; 
  rhs_info = NULLED_OUT ; 
  clv = NULLED_OUT ; 
  pre_body = NULLED_OUT ; 
  retry_start = NULLED_OUT ; 
  prev_body = NULLED_OUT ; 
  body = NULLED_OUT ; 
  value = NULLED_OUT ; 
  if (! ((& head -> iso ) -> so . keyex & 0x1 ) && (head -> count == 1 ) && (head -> num_clauses == 1 ) ) {
#   define XfOrM427_COUNT (0+XfOrM329_COUNT)
#   define SETUP_XfOrM427(x) SETUP_XfOrM329(x)
    clv = (Scheme_Compiled_Let_Value * ) head -> body ; 
    if (((Scheme_Type ) (((((long ) (clv -> body ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (clv -> body ) ) -> type ) ) == (Scheme_Type ) (scheme_local_type ) ) && (((Scheme_Local * ) clv -> body ) -> position == 0 ) ) {
      Scheme_Type lhs ; 
#     define XfOrM428_COUNT (0+XfOrM427_COUNT)
#     define SETUP_XfOrM428(x) SETUP_XfOrM427(x)
      lhs = ((((long ) (clv -> value ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (clv -> value ) ) -> type ) ; 
      if ((lhs == scheme_compiled_unclosed_procedure_type ) || (lhs == scheme_local_type ) || (lhs == scheme_compiled_toplevel_type ) || (lhs == scheme_compiled_quote_syntax_type ) || (lhs > _scheme_compiled_values_types_ ) ) {
#       define XfOrM429_COUNT (0+XfOrM428_COUNT)
#       define SETUP_XfOrM429(x) SETUP_XfOrM428(x)
        if (for_inline ) {
#         define XfOrM431_COUNT (0+XfOrM429_COUNT)
#         define SETUP_XfOrM431(x) SETUP_XfOrM429(x)
          RET_VALUE_START (FUNCCALL(SETUP_XfOrM431(_), scheme_optimize_expr (clv -> value , info ) )) RET_VALUE_END ; 
        }
        else {
#         define XfOrM430_COUNT (0+XfOrM429_COUNT)
#         define SETUP_XfOrM430(x) SETUP_XfOrM429(x)
          info = FUNCCALL(SETUP_XfOrM430(_), scheme_optimize_info_add_frame (info , 1 , 0 , 0 ) ); 
          body = FUNCCALL(SETUP_XfOrM430(_), scheme_optimize_expr (clv -> value , info ) ); 
          info -> next -> single_result = info -> single_result ; 
          info -> next -> preserves_marks = info -> preserves_marks ; 
          FUNCCALL(SETUP_XfOrM430(_), scheme_optimize_info_done (info ) ); 
          RET_VALUE_START (body ) RET_VALUE_END ; 
        }
      }
    }
  }
  body_info = FUNCCALL(SETUP_XfOrM329(_), scheme_optimize_info_add_frame (info , head -> count , head -> count , 0 ) ); 
  if (for_inline ) {
#   define XfOrM426_COUNT (0+XfOrM329_COUNT)
#   define SETUP_XfOrM426(x) SETUP_XfOrM329(x)
    rhs_info = FUNCCALL(SETUP_XfOrM426(_), scheme_optimize_info_add_frame (info , 0 , head -> count , 0 ) ); 
    body_info -> inline_fuel >>= 1 ; 
  }
  else rhs_info = body_info ; 
  is_rec = ((& head -> iso ) -> so . keyex & 0x1 ) ; 
  body = head -> body ; 
  pos = 0 ; 
  for (i = head -> num_clauses ; i -- ; ) {
#   define XfOrM421_COUNT (0+XfOrM329_COUNT)
#   define SETUP_XfOrM421(x) SETUP_XfOrM329(x)
    pre_body = (Scheme_Compiled_Let_Value * ) body ; 
    for (j = pre_body -> count ; j -- ; ) {
#     define XfOrM424_COUNT (0+XfOrM421_COUNT)
#     define SETUP_XfOrM424(x) SETUP_XfOrM421(x)
      if (pre_body -> flags [j ] & 0x2 ) {
#       define XfOrM425_COUNT (0+XfOrM424_COUNT)
#       define SETUP_XfOrM425(x) SETUP_XfOrM424(x)
        FUNCCALL(SETUP_XfOrM425(_), scheme_optimize_mutated (body_info , pos + j ) ); 
      }
    }
    pos += pre_body -> count ; 
    body = pre_body -> body ; 
  }
  prev_body = ((void * ) 0 ) ; 
  body = head -> body ; 
  pre_body = ((void * ) 0 ) ; 
  retry_start = ((void * ) 0 ) ; 
  did_set_value = 0 ; 
  pos = 0 ; 
  for (i = head -> num_clauses ; i -- ; ) {
#   define XfOrM387_COUNT (0+XfOrM329_COUNT)
#   define SETUP_XfOrM387(x) SETUP_XfOrM329(x)
    pre_body = (Scheme_Compiled_Let_Value * ) body ; 
    size_before_opt = body_info -> size ; 
    if ((pre_body -> count == 1 ) && ((Scheme_Type ) (scheme_compiled_unclosed_procedure_type ) == (Scheme_Type ) (((((long ) (pre_body -> value ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (pre_body -> value ) ) -> type ) ) ) && ! FUNCCALL(SETUP_XfOrM387(_), scheme_optimize_is_used (body_info , pos ) )) {
#     define XfOrM414_COUNT (0+XfOrM387_COUNT)
#     define SETUP_XfOrM414(x) SETUP_XfOrM387(x)
      if (! body_info -> transitive_use ) {
        mzshort * * tu ; 
        int * tu_len ; 
        BLOCK_SETUP((PUSH(tu_len, 0+XfOrM414_COUNT), PUSH(tu, 1+XfOrM414_COUNT)));
#       define XfOrM415_COUNT (2+XfOrM414_COUNT)
#       define SETUP_XfOrM415(x) SETUP(XfOrM415_COUNT)
        tu = NULLED_OUT ; 
        tu_len = NULLED_OUT ; 
        tu = (mzshort * * ) FUNCCALL(SETUP_XfOrM415(_), GC_malloc (sizeof (mzshort * ) * head -> count ) ); 
        tu_len = (int * ) FUNCCALL(SETUP_XfOrM415(_), GC_malloc_atomic (sizeof (int ) * head -> count ) ); 
        (memset (tu_len , 0 , sizeof (int ) * head -> count ) ) ; 
        body_info -> transitive_use = tu ; 
        body_info -> transitive_use_len = tu_len ; 
      }
      body_info -> transitive_use_pos = pos + 1 ; 
    }
    value = FUNCCALL(SETUP_XfOrM387(_), scheme_optimize_expr (pre_body -> value , rhs_info ) ); 
    pre_body -> value = value ; 
    body_info -> transitive_use_pos = 0 ; 
    if (is_rec && ! not_simply_let_star ) {
#     define XfOrM413_COUNT (0+XfOrM387_COUNT)
#     define SETUP_XfOrM413(x) SETUP_XfOrM387(x)
      if (FUNCCALL(SETUP_XfOrM413(_), scheme_optimize_any_uses (rhs_info , pos , head -> count ) ))
        not_simply_let_star = 1 ; 
    }
    if ((pre_body -> count != 1 ) && FUNCCALL(SETUP_XfOrM387(_), is_values_apply (value ) )&& FUNCCALL(SETUP_XfOrM387(_), scheme_omittable_expr (value , pre_body -> count ) )) {
#     define XfOrM405_COUNT (0+XfOrM387_COUNT)
#     define SETUP_XfOrM405(x) SETUP_XfOrM387(x)
      if (! pre_body -> count && ! i ) {
        remove_last_one = 1 ; 
      }
      else {
        Scheme_Compiled_Let_Value * naya ; 
        Scheme_Object * rest = pre_body -> body ; 
        int * new_flags ; 
        int cnt = pre_body -> count ; 
        BLOCK_SETUP((PUSH(naya, 0+XfOrM405_COUNT), PUSH(new_flags, 1+XfOrM405_COUNT), PUSH(rest, 2+XfOrM405_COUNT)));
#       define XfOrM406_COUNT (3+XfOrM405_COUNT)
#       define SETUP_XfOrM406(x) SETUP(XfOrM406_COUNT)
        naya = NULLED_OUT ; 
        new_flags = NULLED_OUT ; 
        while (cnt -- ) {
#         define XfOrM411_COUNT (0+XfOrM406_COUNT)
#         define SETUP_XfOrM411(x) SETUP_XfOrM406(x)
          naya = ((Scheme_Compiled_Let_Value * ) FUNCCALL(SETUP_XfOrM411(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Compiled_Let_Value ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
          naya -> so . type = scheme_compiled_let_value_type ; 
          naya -> body = rest ; 
          naya -> count = 1 ; 
          naya -> position = pre_body -> position + cnt ; 
          new_flags = (int * ) FUNCCALL(SETUP_XfOrM411(_), GC_malloc_atomic (sizeof (int ) ) ); 
          new_flags [0 ] = pre_body -> flags [cnt ] ; 
          naya -> flags = new_flags ; 
          rest = (Scheme_Object * ) naya ; 
        }
        naya = (Scheme_Compiled_Let_Value * ) rest ; 
        FUNCCALL(SETUP_XfOrM406(_), unpack_values_application (value , naya ) ); 
        if (prev_body )
          prev_body -> body = (Scheme_Object * ) naya ; 
        else head -> body = (Scheme_Object * ) naya ; 
        head -> num_clauses += (pre_body -> count - 1 ) ; 
        i += (pre_body -> count - 1 ) ; 
        if (pre_body -> count ) {
          pre_body = naya ; 
          body = (Scheme_Object * ) naya ; 
          value = pre_body -> value ; 
        }
        else {
          i ++ ; 
          if (i > 0 ) {
            body = (Scheme_Object * ) naya ; 
            continue ; 
          }
          else break ; 
        }
      }
    }
    if ((pre_body -> count == 1 ) && ! (pre_body -> flags [0 ] & 0x2 ) ) {
#     define XfOrM401_COUNT (0+XfOrM387_COUNT)
#     define SETUP_XfOrM401(x) SETUP_XfOrM387(x)
      if (((Scheme_Type ) (((((long ) (value ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (value ) ) -> type ) ) == (Scheme_Type ) (scheme_local_type ) ) ) {
        int vpos ; 
#       define XfOrM403_COUNT (0+XfOrM401_COUNT)
#       define SETUP_XfOrM403(x) SETUP_XfOrM401(x)
        vpos = (((Scheme_Local * ) (value ) ) -> position ) ; 
        if ((vpos < head -> count ) && (vpos >= pos ) )
          value = ((void * ) 0 ) ; 
        else {
#         define XfOrM404_COUNT (0+XfOrM403_COUNT)
#         define SETUP_XfOrM404(x) SETUP_XfOrM403(x)
          value = FUNCCALL(SETUP_XfOrM404(_), scheme_optimize_reverse (body_info , vpos , 1 ) ); 
        }
      }
      if (value && (FUNCCALL(SETUP_XfOrM401(_), scheme_compiled_propagate_ok (value , body_info ) )) ) {
#       define XfOrM402_COUNT (0+XfOrM401_COUNT)
#       define SETUP_XfOrM402(x) SETUP_XfOrM401(x)
        FUNCCALL(SETUP_XfOrM402(_), scheme_optimize_propagate (body_info , pos , value ) ); 
        did_set_value = 1 ; 
      }
    }
    if (! retry_start )
      retry_start = pre_body ; 
    if (is_rec && ! body_info -> letrec_not_twice && ((i < 1 ) || (! FUNCCALL(SETUP_XfOrM387(_), scheme_is_compiled_procedure (((Scheme_Compiled_Let_Value * ) pre_body -> body ) -> value , 1 , 1 ) )&& ! FUNCCALL(SETUP_XfOrM387(_), is_liftable (((Scheme_Compiled_Let_Value * ) pre_body -> body ) -> value , head -> count , 5 ) )) ) ) {
#     define XfOrM391_COUNT (0+XfOrM387_COUNT)
#     define SETUP_XfOrM391(x) SETUP_XfOrM387(x)
      if (did_set_value ) {
        int flags ; 
        Scheme_Object * clones , * cl , * cl_first ; 
        BLOCK_SETUP((PUSH(cl_first, 0+XfOrM391_COUNT), PUSH(clones, 1+XfOrM391_COUNT), PUSH(cl, 2+XfOrM391_COUNT)));
#       define XfOrM392_COUNT (3+XfOrM391_COUNT)
#       define SETUP_XfOrM392(x) SETUP(XfOrM392_COUNT)
        clones = NULLED_OUT ; 
        cl = NULLED_OUT ; 
        cl_first = NULLED_OUT ; 
        clones = FUNCCALL(SETUP_XfOrM392(_), make_clones (retry_start , pre_body , body_info ) ); 
        (void ) FUNCCALL(SETUP_XfOrM392(_), set_code_flags (retry_start , pre_body , clones , 32 | 4 | 64 , 0xFFFF ) ); 
        clv = retry_start ; 
        cl = clones ; 
        while (1 ) {
#         define XfOrM397_COUNT (0+XfOrM392_COUNT)
#         define SETUP_XfOrM397(x) SETUP_XfOrM392(x)
          value = clv -> value ; 
          if (cl )
            cl_first = (((Scheme_Simple_Object * ) (cl ) ) -> u . pair_val . car ) ; 
          else cl_first = ((void * ) 0 ) ; 
          if (cl_first && ((value ) == ((((Scheme_Simple_Object * ) (cl_first ) ) -> u . pair_val . car ) ) ) ) {
            Scheme_Object * self_value ; 
            int sz ; 
            BLOCK_SETUP((PUSH(self_value, 0+XfOrM397_COUNT)));
#           define XfOrM398_COUNT (1+XfOrM397_COUNT)
#           define SETUP_XfOrM398(x) SETUP(XfOrM398_COUNT)
            self_value = NULLED_OUT ; 
            if ((clv -> count == 1 ) && body_info -> transitive_use && ! FUNCCALL(SETUP_XfOrM398(_), scheme_optimize_is_used (body_info , clv -> position ) )) {
              body_info -> transitive_use [clv -> position ] = ((void * ) 0 ) ; 
              body_info -> transitive_use_pos = clv -> position + 1 ; 
            }
            cl = (((Scheme_Simple_Object * ) (cl ) ) -> u . pair_val . cdr ) ; 
            self_value = (((Scheme_Simple_Object * ) (cl_first ) ) -> u . pair_val . cdr ) ; 
            sz = FUNCCALL(SETUP_XfOrM398(_), scheme_closure_body_size ((Scheme_Closure_Data * ) value , 0 ) ); 
            body_info -> size -= (sz + 1 ) ; 
            body_info -> letrec_not_twice = 1 ; 
            value = FUNCCALL(SETUP_XfOrM398(_), scheme_optimize_expr (self_value , body_info ) ); 
            body_info -> letrec_not_twice = 0 ; 
            clv -> value = value ; 
            if (! (clv -> flags [0 ] & 0x2 ) ) {
#             define XfOrM399_COUNT (0+XfOrM398_COUNT)
#             define SETUP_XfOrM399(x) SETUP_XfOrM398(x)
              FUNCCALL(SETUP_XfOrM399(_), scheme_optimize_propagate (body_info , clv -> position , value ) ); 
            }
            body_info -> transitive_use_pos = 0 ; 
          }
          if (clv == pre_body )
            break ; 
          clv = (Scheme_Compiled_Let_Value * ) clv -> body ; 
        }
        flags = FUNCCALL(SETUP_XfOrM392(_), set_code_flags (retry_start , pre_body , clones , 0 , 0xFFFF ) ); 
        (void ) FUNCCALL(SETUP_XfOrM392(_), set_code_flags (retry_start , pre_body , clones , (flags & (32 | 4 ) ) , ~ (32 | 4 | 64 ) ) ); 
      }
      retry_start = ((void * ) 0 ) ; 
      did_set_value = 0 ; 
    }
    if (remove_last_one ) {
      head -> num_clauses -= 1 ; 
      body = (Scheme_Object * ) pre_body -> body ; 
      if (prev_body ) {
        prev_body -> body = body ; 
        pre_body = prev_body ; 
      }
      else {
        head -> body = body ; 
        pre_body = ((void * ) 0 ) ; 
      }
      break ; 
    }
    pos += pre_body -> count ; 
    prev_body = pre_body ; 
    body = pre_body -> body ; 
    info -> size += 1 ; 
  }
  if (for_inline ) {
    body_info -> size = rhs_info -> size ; 
  }
  body = FUNCCALL(SETUP_XfOrM329(_), scheme_optimize_expr (body , body_info ) ); 
  if (head -> num_clauses )
    pre_body -> body = body ; 
  else head -> body = body ; 
  info -> size += 1 ; 
  info -> single_result = body_info -> single_result ; 
  info -> preserves_marks = body_info -> preserves_marks ; 
  body = head -> body ; 
  pos = 0 ; 
  for (i = head -> num_clauses ; i -- ; ) {
    int used = 0 , j ; 
#   define XfOrM344_COUNT (0+XfOrM329_COUNT)
#   define SETUP_XfOrM344(x) SETUP_XfOrM329(x)
    pre_body = (Scheme_Compiled_Let_Value * ) body ; 
    for (j = pre_body -> count ; j -- ; ) {
#     define XfOrM355_COUNT (0+XfOrM344_COUNT)
#     define SETUP_XfOrM355(x) SETUP_XfOrM344(x)
      if (FUNCCALL(SETUP_XfOrM355(_), scheme_optimize_is_used (body_info , pos + j ) )) {
        used = 1 ; 
        break ; 
      }
    }
    if (! used && FUNCCALL(SETUP_XfOrM344(_), scheme_omittable_expr (pre_body -> value , pre_body -> count ) )) {
      for (j = pre_body -> count ; j -- ; ) {
        if (pre_body -> flags [j ] & 0x1 ) {
          pre_body -> flags [j ] -= 0x1 ; 
        }
      }
    }
    else {
      for (j = pre_body -> count ; j -- ; ) {
        pre_body -> flags [j ] |= 0x1 ; 
      }
    }
    pos += pre_body -> count ; 
    body = pre_body -> body ; 
  }
  FUNCCALL(SETUP_XfOrM329(_), scheme_optimize_info_done (body_info ) ); 
  if (! head -> num_clauses )
    RET_VALUE_START (head -> body ) RET_VALUE_END ; 
  if (is_rec && ! not_simply_let_star ) {
    (& head -> iso ) -> so . keyex -= 0x1 ; 
    (& head -> iso ) -> so . keyex |= 0x2 ; 
  }
  RET_VALUE_START (form ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_optimize_lets_for_test (Scheme_Object * form , Optimize_Info * info ) {
  Scheme_Let_Header * head = (Scheme_Let_Header * ) form ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(info, 0), PUSH(head, 1), PUSH(form, 2)));
# define XfOrM432_COUNT (3)
# define SETUP_XfOrM432(x) SETUP(XfOrM432_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! ((& head -> iso ) -> so . keyex & 0x1 ) && (head -> count == 1 ) && (head -> num_clauses == 1 ) ) {
    Scheme_Compiled_Let_Value * clv ; 
    BLOCK_SETUP((PUSH(clv, 0+XfOrM432_COUNT)));
#   define XfOrM433_COUNT (1+XfOrM432_COUNT)
#   define SETUP_XfOrM433(x) SETUP(XfOrM433_COUNT)
    clv = NULLED_OUT ; 
    clv = (Scheme_Compiled_Let_Value * ) head -> body ; 
    if (((Scheme_Type ) (((((long ) (clv -> body ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (clv -> body ) ) -> type ) ) == (Scheme_Type ) (scheme_branch_type ) ) && (((clv -> flags [0 ] & 0x70 ) >> 4 ) == 2 ) ) {
      Scheme_Branch_Rec * b = (Scheme_Branch_Rec * ) clv -> body ; 
      BLOCK_SETUP((PUSH(b, 0+XfOrM433_COUNT)));
#     define XfOrM434_COUNT (1+XfOrM433_COUNT)
#     define SETUP_XfOrM434(x) SETUP(XfOrM434_COUNT)
      if (((Scheme_Type ) (((((long ) (b -> test ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (b -> test ) ) -> type ) ) == (Scheme_Type ) (scheme_local_type ) ) && ((Scheme_Type ) (((((long ) (b -> tbranch ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (b -> tbranch ) ) -> type ) ) == (Scheme_Type ) (scheme_local_type ) ) && ! (((Scheme_Local * ) (b -> test ) ) -> position ) && ! (((Scheme_Local * ) (b -> tbranch ) ) -> position ) ) {
        Scheme_Branch_Rec * b3 ; 
        Optimize_Info * sub_info ; 
        BLOCK_SETUP((PUSH(sub_info, 0+XfOrM434_COUNT), PUSH(b3, 1+XfOrM434_COUNT)));
#       define XfOrM435_COUNT (2+XfOrM434_COUNT)
#       define SETUP_XfOrM435(x) SETUP(XfOrM435_COUNT)
        b3 = NULLED_OUT ; 
        sub_info = NULLED_OUT ; 
        b3 = ((Scheme_Branch_Rec * ) FUNCCALL(SETUP_XfOrM435(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Branch_Rec ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
        b3 -> so . type = scheme_branch_type ; 
        b3 -> test = clv -> value ; 
        b3 -> tbranch = scheme_true ; 
        b3 -> fbranch = b -> fbranch ; 
        sub_info = FUNCCALL(SETUP_XfOrM435(_), scheme_optimize_info_add_frame (info , 1 , 0 , 0 ) ); 
        form = FUNCCALL_AGAIN(scheme_optimize_expr ((Scheme_Object * ) b3 , sub_info ) ); 
        info -> single_result = sub_info -> single_result ; 
        info -> preserves_marks = sub_info -> preserves_marks ; 
        FUNCCALL(SETUP_XfOrM435(_), scheme_optimize_info_done (sub_info ) ); 
        RET_VALUE_START (form ) RET_VALUE_END ; 
      }
    }
  }
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM432(_), scheme_optimize_lets (form , info , 0 ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int is_lifted_reference (Scheme_Object * v ) {
  /* No conversion */
  if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) )
    return 1 ; 
  return (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_toplevel_type ) ) && ((& ((Scheme_Toplevel * ) (v ) ) -> iso ) -> so . keyex & 0x1 ) ) ; 
}
static int is_closed_reference (Scheme_Object * v ) {
  /* No conversion */
  if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ) {
    v = (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) ; 
    return (! (((long ) (v ) ) & 0x1 ) && ((((v ) -> type ) >= scheme_prim_type ) && (((v ) -> type ) <= scheme_native_closure_type ) ) ) ; 
  }
  return 0 ; 
}
static Scheme_Object * scheme_resolve_generate_stub_closure () {
  Scheme_Closure * cl ; 
  Scheme_Object * * ca ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(ca, 0), PUSH(cl, 1)));
# define XfOrM439_COUNT (2)
# define SETUP_XfOrM439(x) SETUP(XfOrM439_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  cl = NULLED_OUT ; 
  ca = NULLED_OUT ; 
  cl = FUNCCALL(SETUP_XfOrM439(_), scheme_malloc_empty_closure () ); 
  ca = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM439(_), GC_malloc (sizeof (Scheme_Object * ) * (4 ) ) )) ; 
  ca [0 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
  ca [1 ] = ((void * ) 0 ) ; 
  ca [2 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
  ca [3 ] = ((void * ) 0 ) ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_raw_pair ((Scheme_Object * ) cl , (Scheme_Object * ) ca ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void shift_lift (Scheme_Object * lifted , int frame_size , int lifted_frame_size ) {
  /* No conversion */
  int i , cnt ; 
  Scheme_Object * * ca ; 
  mzshort * map ; 
  if (! lifted )
    return ; 
  if (! ((Scheme_Type ) (((((long ) (lifted ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lifted ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) )
    return ; 
  ca = (Scheme_Object * * ) (((Scheme_Simple_Object * ) (lifted ) ) -> u . pair_val . cdr ) ; 
  cnt = (((long ) (ca [0 ] ) ) >> 1 ) ; 
  map = (mzshort * ) ca [1 ] ; 
  for (i = 0 ; i < cnt ; i ++ ) {
    map [i ] += (frame_size - lifted_frame_size ) ; 
  }
}
static int get_convert_arg_count (Scheme_Object * lift ) {
  /* No conversion */
  if (! lift )
    return 0 ; 
  else if (((Scheme_Type ) (((((long ) (lift ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lift ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ) {
    Scheme_Object * * ca ; 
    ca = (Scheme_Object * * ) (((Scheme_Simple_Object * ) (lift ) ) -> u . pair_val . cdr ) ; 
    return (((long ) (ca [0 ] ) ) >> 1 ) ; 
  }
  else return 0 ; 
}
/* this far 3380 */
/* this far 3377 */
/* this far 3377 */
/* this far 3380 */
/* this far 3377 */
/* this far 3377 */
Scheme_Object * scheme_resolve_lets (Scheme_Object * form , Resolve_Info * info ) {
  Resolve_Info * linfo , * val_linfo ; 
  Scheme_Let_Header * head = (Scheme_Let_Header * ) form ; 
  Scheme_Compiled_Let_Value * clv , * pre_body ; 
  Scheme_Let_Value * lv , * last = ((void * ) 0 ) ; 
  Scheme_Object * first = ((void * ) 0 ) , * body , * last_body = ((void * ) 0 ) ; 
  Scheme_Letrec * letrec ; 
  mzshort * skips , skips_fast [5 ] ; 
  Scheme_Object * * lifted , * lifted_fast [5 ] , * boxes ; 
  int i , pos , opos , rpos , recbox , num_rec_procs = 0 , extra_alloc ; 
  int rec_proc_nonapply = 0 ; 
  int max_let_depth = 0 ; 
  int resolve_phase , num_skips ; 
  Scheme_Object * * lifted_recs ; 
  Scheme_Object * __funcarg68 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(22);
  BLOCK_SETUP_TOP((PUSH(first, 0), PUSH(last_body, 1), PUSH(boxes, 2), PUSH(last, 3), PUSH(clv, 4), PUSH(letrec, 5), PUSH(head, 6), PUSH(lifted, 7), PUSH(linfo, 8), PUSH(skips, 9), PUSH(val_linfo, 10), PUSH(info, 11), PUSH(lifted_recs, 12), PUSHARRAY(lifted_fast, 5, 13), PUSH(lv, 16), PUSH(body, 17)));
# define XfOrM445_COUNT (18)
# define SETUP_XfOrM445(x) SETUP(XfOrM445_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  linfo = NULLED_OUT ; 
  val_linfo = NULLED_OUT ; 
  clv = NULLED_OUT ; 
  pre_body = NULLED_OUT ; 
  lv = NULLED_OUT ; 
  body = NULLED_OUT ; 
  letrec = NULLED_OUT ; 
  skips = NULLED_OUT ; 
  lifted = NULLED_OUT ; 
  NULL_OUT_ARRAY (lifted_fast ) ; 
  boxes = NULLED_OUT ; 
  lifted_recs = NULLED_OUT ; 
  body = head -> body ; 
  pre_body = ((void * ) 0 ) ; 
  for (i = head -> num_clauses ; i -- ; ) {
    pre_body = (Scheme_Compiled_Let_Value * ) body ; 
    body = pre_body -> body ; 
  }
  recbox = 0 ; 
  if ((& head -> iso ) -> so . keyex & 0x1 ) {
#   define XfOrM669_COUNT (0+XfOrM445_COUNT)
#   define SETUP_XfOrM669(x) SETUP_XfOrM445(x)
    clv = (Scheme_Compiled_Let_Value * ) head -> body ; 
    for (i = head -> num_clauses ; i -- ; clv = (Scheme_Compiled_Let_Value * ) clv -> body ) {
      int is_proc , is_lift ; 
#     define XfOrM681_COUNT (0+XfOrM669_COUNT)
#     define SETUP_XfOrM681(x) SETUP_XfOrM669(x)
      if ((clv -> count == 1 ) && ! (clv -> flags [0 ] & 0x1 ) ) {
      }
      else {
#       define XfOrM682_COUNT (0+XfOrM681_COUNT)
#       define SETUP_XfOrM682(x) SETUP_XfOrM681(x)
        if (clv -> count == 1 )
          is_proc = FUNCCALL(SETUP_XfOrM682(_), scheme_is_compiled_procedure (clv -> value , 1 , 1 ) ); 
        else is_proc = 0 ; 
        if (is_proc )
          is_lift = 0 ; 
        else is_lift = FUNCCALL(SETUP_XfOrM682(_), is_liftable (clv -> value , head -> count , 5 ) ); 
        if (! is_proc && ! is_lift ) {
          recbox = 1 ; 
          break ; 
        }
        else {
#         define XfOrM683_COUNT (0+XfOrM682_COUNT)
#         define SETUP_XfOrM683(x) SETUP_XfOrM682(x)
          if (! is_lift ) {
            int j ; 
#           define XfOrM684_COUNT (0+XfOrM683_COUNT)
#           define SETUP_XfOrM684(x) SETUP_XfOrM683(x)
            for (j = 0 ; j < clv -> count ; j ++ ) {
              if (clv -> flags [j ] & 0x2 ) {
                recbox = 1 ; 
                break ; 
              }
            }
            if (recbox )
              break ; 
            if (FUNCCALL(SETUP_XfOrM684(_), scheme_is_compiled_procedure (clv -> value , 0 , 0 ) )) {
              num_rec_procs ++ ; 
              if (! (clv -> flags [0 ] & 0x4 ) )
                rec_proc_nonapply = 1 ; 
            }
          }
        }
      }
    }
    if (recbox )
      num_rec_procs = 0 ; 
  }
  else {
#   define XfOrM623_COUNT (0+XfOrM445_COUNT)
#   define SETUP_XfOrM623(x) SETUP_XfOrM445(x)
    clv = (Scheme_Compiled_Let_Value * ) head -> body ; 
    for (i = head -> num_clauses ; i -- ; clv = (Scheme_Compiled_Let_Value * ) clv -> body ) {
      if (clv -> count != 1 )
        break ; 
      if (clv -> flags [0 ] & 0x2 )
        break ; 
    }
    if (i < 0 ) {
      int skip_count = 0 , frame_size , lifts_frame_size = 0 ; 
      int j , k ; 
#     define XfOrM632_COUNT (0+XfOrM623_COUNT)
#     define SETUP_XfOrM632(x) SETUP_XfOrM623(x)
      j = head -> num_clauses ; 
      if (j <= 5 ) {
        skips = skips_fast ; 
        lifted = lifted_fast ; 
      }
      else {
#       define XfOrM665_COUNT (0+XfOrM632_COUNT)
#       define SETUP_XfOrM665(x) SETUP_XfOrM632(x)
        skips = ((mzshort * ) FUNCCALL(SETUP_XfOrM665(_), GC_malloc_atomic (sizeof (mzshort ) * (j ) ) )) ; 
        lifted = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM665(_), GC_malloc (sizeof (Scheme_Object * ) * (j ) ) )) ; 
      }
      clv = (Scheme_Compiled_Let_Value * ) head -> body ; 
      for (i = 0 ; i < j ; i ++ , clv = (Scheme_Compiled_Let_Value * ) clv -> body ) {
        if (! (clv -> flags [0 ] & 0x1 ) )
          skips [i ] = 1 ; 
        else skips [i ] = 0 ; 
        lifted [i ] = ((void * ) 0 ) ; 
      }
      clv = (Scheme_Compiled_Let_Value * ) head -> body ; 
      for (i = 0 ; i < head -> num_clauses ; i ++ , clv = (Scheme_Compiled_Let_Value * ) clv -> body ) {
        Scheme_Object * le ; 
        BLOCK_SETUP((PUSH(le, 0+XfOrM632_COUNT)));
#       define XfOrM651_COUNT (1+XfOrM632_COUNT)
#       define SETUP_XfOrM651(x) SETUP(XfOrM651_COUNT)
        le = NULLED_OUT ; 
        if (! (clv -> flags [0 ] & 0x1 ) ) {
          skip_count ++ ; 
        }
        frame_size = i + 1 - skip_count ; 
        linfo = FUNCCALL(SETUP_XfOrM651(_), scheme_resolve_info_extend (info , frame_size , head -> count , i + 1 ) ); 
        for (j = i , k = 0 ; j >= 0 ; j -- ) {
#         define XfOrM660_COUNT (0+XfOrM651_COUNT)
#         define SETUP_XfOrM660(x) SETUP_XfOrM651(x)
          if (lifts_frame_size != frame_size ) {
#           define XfOrM661_COUNT (0+XfOrM660_COUNT)
#           define SETUP_XfOrM661(x) SETUP_XfOrM660(x)
            FUNCCALL(SETUP_XfOrM661(_), shift_lift (lifted [j ] , frame_size , lifts_frame_size ) ); 
          }
          if (skips [j ] )
            FUNCCALL(SETUP_XfOrM660(_), scheme_resolve_info_add_mapping (linfo , j , 0 , 0 , lifted [j ] ) ); 
          else FUNCCALL(SETUP_XfOrM660(_), scheme_resolve_info_add_mapping (linfo , j , k ++ , 0 , lifted [j ] ) ); 
        }
        lifts_frame_size = frame_size ; 
        if (skips [i ] ) {
          le = scheme_void ; 
        }
        else {
#         define XfOrM656_COUNT (0+XfOrM651_COUNT)
#         define SETUP_XfOrM656(x) SETUP_XfOrM651(x)
          if ((clv -> flags [0 ] & 0x4 ) && ((Scheme_Type ) (((((long ) (clv -> value ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (clv -> value ) ) -> type ) ) == (Scheme_Type ) (scheme_compiled_unclosed_procedure_type ) ) )
            le = FUNCCALL(SETUP_XfOrM656(_), scheme_resolve_closure_compilation (clv -> value , linfo , 1 , 1 , 0 , ((void * ) 0 ) ) ); 
          else le = FUNCCALL(SETUP_XfOrM656(_), scheme_resolve_expr (clv -> value , linfo ) ); 
        }
        if (max_let_depth < linfo -> max_let_depth + frame_size )
          max_let_depth = linfo -> max_let_depth + frame_size ; 
        if (FUNCCALL(SETUP_XfOrM651(_), is_lifted_reference (le ) )) {
          lifted [i ] = le ; 
          if (! skips [i ] ) {
            skips [i ] = 1 ; 
            skip_count ++ ; 
          }
        }
        if (skips [i ] ) {
        }
        else {
          Scheme_Let_One * lo ; 
          int et ; 
          BLOCK_SETUP((PUSH(lo, 0+XfOrM651_COUNT)));
#         define XfOrM652_COUNT (1+XfOrM651_COUNT)
#         define SETUP_XfOrM652(x) SETUP(XfOrM652_COUNT)
          lo = NULLED_OUT ; 
          lo = ((Scheme_Let_One * ) FUNCCALL(SETUP_XfOrM652(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Let_One ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
          lo -> iso . so . type = scheme_let_one_type ; 
          lo -> value = le ; 
          et = FUNCCALL(SETUP_XfOrM652(_), scheme_get_eval_type (lo -> value ) ); 
          (& lo -> iso ) -> so . keyex = et ; 
          if (last )
            ((Scheme_Let_One * ) last ) -> body = (Scheme_Object * ) lo ; 
          else first = (Scheme_Object * ) lo ; 
          last = (Scheme_Let_Value * ) lo ; 
        }
      }
      frame_size = head -> count - skip_count ; 
      linfo = FUNCCALL(SETUP_XfOrM632(_), scheme_resolve_info_extend (info , frame_size , head -> count , head -> count ) ); 
      if (lifts_frame_size != frame_size ) {
#       define XfOrM636_COUNT (0+XfOrM632_COUNT)
#       define SETUP_XfOrM636(x) SETUP_XfOrM632(x)
        for (i = head -> count ; i -- ; ) {
#         define XfOrM638_COUNT (0+XfOrM636_COUNT)
#         define SETUP_XfOrM638(x) SETUP_XfOrM636(x)
          FUNCCALL(SETUP_XfOrM638(_), shift_lift (lifted [i ] , frame_size , lifts_frame_size ) ); 
        }
      }
      for (k = 0 , i = head -> count ; i -- ; ) {
#       define XfOrM635_COUNT (0+XfOrM632_COUNT)
#       define SETUP_XfOrM635(x) SETUP_XfOrM632(x)
        if (skips [i ] )
          FUNCCALL(SETUP_XfOrM635(_), scheme_resolve_info_add_mapping (linfo , i , ((skips [i ] < 0 ) ? (k - skips [i ] - 1 ) : (skips [i ] - 1 + frame_size ) ) , 0 , lifted [i ] ) ); 
        else FUNCCALL(SETUP_XfOrM635(_), scheme_resolve_info_add_mapping (linfo , i , k ++ , 0 , lifted [i ] ) ); 
      }
      body = FUNCCALL(SETUP_XfOrM632(_), scheme_resolve_expr (body , linfo ) ); 
      if (last )
        ((Scheme_Let_One * ) last ) -> body = body ; 
      else {
        first = body ; 
      }
      if (max_let_depth < linfo -> max_let_depth + frame_size )
        max_let_depth = linfo -> max_let_depth + frame_size ; 
      if (info -> max_let_depth < max_let_depth )
        info -> max_let_depth = max_let_depth ; 
      RET_VALUE_START (first ) RET_VALUE_END ; 
    }
    else {
      int total = 0 , j ; 
#     define XfOrM624_COUNT (0+XfOrM623_COUNT)
#     define SETUP_XfOrM624(x) SETUP_XfOrM623(x)
      clv = (Scheme_Compiled_Let_Value * ) head -> body ; 
      for (i = head -> num_clauses ; i -- ; clv = (Scheme_Compiled_Let_Value * ) clv -> body ) {
#       define XfOrM629_COUNT (0+XfOrM624_COUNT)
#       define SETUP_XfOrM629(x) SETUP_XfOrM624(x)
        total += clv -> count ; 
        for (j = clv -> count ; j -- ; ) {
          if (clv -> flags [j ] & 0x1 )
            break ; 
        }
        if (j >= 0 )
          break ; 
        if (! FUNCCALL(SETUP_XfOrM629(_), scheme_omittable_expr (clv -> value , clv -> count ) ))
          break ; 
      }
      if (i < 0 ) {
#       define XfOrM625_COUNT (0+XfOrM624_COUNT)
#       define SETUP_XfOrM625(x) SETUP_XfOrM624(x)
        linfo = FUNCCALL(SETUP_XfOrM625(_), scheme_resolve_info_extend (info , 0 , total , 0 ) ); 
        first = FUNCCALL(SETUP_XfOrM625(_), scheme_resolve_expr ((Scheme_Object * ) clv , linfo ) ); 
        if (info -> max_let_depth < linfo -> max_let_depth )
          info -> max_let_depth = linfo -> max_let_depth ; 
        RET_VALUE_START (first ) RET_VALUE_END ; 
      }
    }
  }
  num_skips = 0 ; 
  clv = (Scheme_Compiled_Let_Value * ) head -> body ; 
  for (i = head -> num_clauses ; i -- ; clv = (Scheme_Compiled_Let_Value * ) clv -> body ) {
    if ((clv -> count == 1 ) && ! (clv -> flags [0 ] & 0x1 ) )
      num_skips ++ ; 
  }
  linfo = 0 ; 
  for (resolve_phase = ((num_rec_procs && ! rec_proc_nonapply ) ? 0 : 2 ) ; resolve_phase < 3 ; resolve_phase ++ ) {
#   define XfOrM554_COUNT (0+XfOrM445_COUNT)
#   define SETUP_XfOrM554(x) SETUP_XfOrM445(x)
    if ((resolve_phase == 1 ) && ! FUNCCALL(SETUP_XfOrM554(_), scheme_resolve_is_toplevel_available (info ) ))
      resolve_phase = 2 ; 
    if (resolve_phase < 2 ) {
#     define XfOrM620_COUNT (0+XfOrM554_COUNT)
#     define SETUP_XfOrM620(x) SETUP_XfOrM554(x)
      linfo = FUNCCALL(SETUP_XfOrM620(_), scheme_resolve_info_extend (info , head -> count - num_rec_procs - num_skips , head -> count , head -> count ) ); 
      lifted_recs = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM620(_), GC_malloc (sizeof (Scheme_Object * ) * (num_rec_procs ) ) )) ; 
    }
    else {
#     define XfOrM619_COUNT (0+XfOrM554_COUNT)
#     define SETUP_XfOrM619(x) SETUP_XfOrM554(x)
      linfo = FUNCCALL(SETUP_XfOrM619(_), scheme_resolve_info_extend (info , head -> count - num_skips , head -> count , head -> count ) ); 
      lifted_recs = ((void * ) 0 ) ; 
    }
    clv = (Scheme_Compiled_Let_Value * ) head -> body ; 
    pos = ((resolve_phase < 2 ) ? 0 : num_rec_procs ) ; 
    rpos = 0 ; 
    opos = 0 ; 
    for (i = head -> num_clauses ; i -- ; clv = (Scheme_Compiled_Let_Value * ) clv -> body ) {
      int j ; 
#     define XfOrM604_COUNT (0+XfOrM554_COUNT)
#     define SETUP_XfOrM604(x) SETUP_XfOrM554(x)
      if ((clv -> count == 1 ) && ! (clv -> flags [0 ] & 0x1 ) ) {
#       define XfOrM618_COUNT (0+XfOrM604_COUNT)
#       define SETUP_XfOrM618(x) SETUP_XfOrM604(x)
        FUNCCALL(SETUP_XfOrM618(_), scheme_resolve_info_add_mapping (linfo , opos , 0 , 0 , ((void * ) 0 ) ) ); 
        opos ++ ; 
      }
      else {
#       define XfOrM605_COUNT (0+XfOrM604_COUNT)
#       define SETUP_XfOrM605(x) SETUP_XfOrM604(x)
        for (j = 0 ; j < clv -> count ; j ++ ) {
          int p , skip ; 
          Scheme_Object * lift ; 
          BLOCK_SETUP((PUSH(lift, 0+XfOrM605_COUNT)));
#         define XfOrM612_COUNT (1+XfOrM605_COUNT)
#         define SETUP_XfOrM612(x) SETUP(XfOrM612_COUNT)
          lift = NULLED_OUT ; 
          skip = 0 ; 
          if (num_rec_procs && (clv -> count == 1 ) && FUNCCALL(SETUP_XfOrM612(_), scheme_is_compiled_procedure (clv -> value , 0 , 0 ) )) {
#           define XfOrM614_COUNT (0+XfOrM612_COUNT)
#           define SETUP_XfOrM614(x) SETUP_XfOrM612(x)
            if (resolve_phase == 0 ) {
#             define XfOrM617_COUNT (0+XfOrM614_COUNT)
#             define SETUP_XfOrM617(x) SETUP_XfOrM614(x)
              lift = FUNCCALL(SETUP_XfOrM617(_), scheme_resolve_generate_stub_closure () ); 
              lifted_recs [rpos ] = lift ; 
              p = 0 ; 
            }
            else if (resolve_phase == 1 ) {
#             define XfOrM616_COUNT (0+XfOrM614_COUNT)
#             define SETUP_XfOrM616(x) SETUP_XfOrM614(x)
              lift = FUNCCALL(SETUP_XfOrM616(_), scheme_resolve_generate_stub_lift () ); 
              lifted_recs [rpos ] = lift ; 
              p = 0 ; 
            }
            else {
              lift = ((void * ) 0 ) ; 
              p = rpos ; 
            }
            rpos ++ ; 
          }
          else {
            p = pos ++ ; 
            lift = ((void * ) 0 ) ; 
          }
          FUNCCALL(SETUP_XfOrM612(_), scheme_resolve_info_add_mapping (linfo , opos , p , ((recbox || (clv -> flags [j ] & 0x2 ) ) ? 1 : 0 ) , lift ) ); 
          opos ++ ; 
        }
      }
    }
    if (resolve_phase < 2 ) {
      int converted ; 
#     define XfOrM555_COUNT (0+XfOrM554_COUNT)
#     define SETUP_XfOrM555(x) SETUP_XfOrM554(x)
      do {
#       define XfOrM578_COUNT (0+XfOrM555_COUNT)
#       define SETUP_XfOrM578(x) SETUP_XfOrM555(x)
        clv = (Scheme_Compiled_Let_Value * ) head -> body ; 
        rpos = 0 ; 
        opos = 0 ; 
        converted = 0 ; 
        for (i = head -> num_clauses ; i -- ; clv = (Scheme_Compiled_Let_Value * ) clv -> body ) {
#         define XfOrM584_COUNT (0+XfOrM578_COUNT)
#         define SETUP_XfOrM584(x) SETUP_XfOrM578(x)
          if ((clv -> count == 1 ) && ! (clv -> flags [0 ] & 0x1 ) ) {
          }
          else if ((clv -> count == 1 ) && FUNCCALL(SETUP_XfOrM584(_), scheme_is_compiled_procedure (clv -> value , 0 , 0 ) )) {
            Scheme_Object * lift , * old_lift ; 
            int old_convert_count ; 
            BLOCK_SETUP((PUSH(old_lift, 0+XfOrM584_COUNT), PUSH(lift, 1+XfOrM584_COUNT)));
#           define XfOrM585_COUNT (2+XfOrM584_COUNT)
#           define SETUP_XfOrM585(x) SETUP(XfOrM585_COUNT)
            lift = NULLED_OUT ; 
            old_lift = NULLED_OUT ; 
            old_lift = lifted_recs [rpos ] ; 
            old_convert_count = FUNCCALL(SETUP_XfOrM585(_), get_convert_arg_count (old_lift ) ); 
            lift = FUNCCALL_AGAIN(scheme_resolve_closure_compilation (clv -> value , linfo , 1 , 1 , 1 , (resolve_phase ? ((void * ) 0 ) : old_lift ) ) ); 
            if (FUNCCALL(SETUP_XfOrM585(_), is_closed_reference (lift ) )|| (FUNCCALL(SETUP_XfOrM585(_), is_lifted_reference (lift ) )&& resolve_phase ) ) {
#             define XfOrM587_COUNT (0+XfOrM585_COUNT)
#             define SETUP_XfOrM587(x) SETUP_XfOrM585(x)
              if (! ((old_lift ) == (lift ) ) )
                FUNCCALL(SETUP_XfOrM587(_), scheme_resolve_info_adjust_mapping (linfo , opos , rpos , 0 , lift ) ); 
              lifted_recs [rpos ] = lift ; 
              if (FUNCCALL(SETUP_XfOrM587(_), get_convert_arg_count (lift ) )!= old_convert_count )
                converted = 1 ; 
            }
            else {
              lifted_recs = ((void * ) 0 ) ; 
              converted = 0 ; 
              break ; 
            }
            rpos ++ ; 
          }
          opos += clv -> count ; 
        }
      }
      while (converted ) ; 
      if (lifted_recs ) {
#       define XfOrM556_COUNT (0+XfOrM555_COUNT)
#       define SETUP_XfOrM556(x) SETUP_XfOrM555(x)
        clv = (Scheme_Compiled_Let_Value * ) head -> body ; 
        rpos = 0 ; 
        opos = 0 ; 
        for (i = head -> num_clauses ; i -- ; clv = (Scheme_Compiled_Let_Value * ) clv -> body ) {
#         define XfOrM562_COUNT (0+XfOrM556_COUNT)
#         define SETUP_XfOrM562(x) SETUP_XfOrM556(x)
          if ((clv -> count == 1 ) && ! (clv -> flags [0 ] & 0x1 ) ) {
          }
          else if ((clv -> count == 1 ) && FUNCCALL(SETUP_XfOrM562(_), scheme_is_compiled_procedure (clv -> value , 0 , 0 ) )) {
            Scheme_Object * lift ; 
            BLOCK_SETUP((PUSH(lift, 0+XfOrM562_COUNT)));
#           define XfOrM563_COUNT (1+XfOrM562_COUNT)
#           define SETUP_XfOrM563(x) SETUP(XfOrM563_COUNT)
            lift = NULLED_OUT ; 
            lift = lifted_recs [rpos ] ; 
            if (FUNCCALL(SETUP_XfOrM563(_), is_closed_reference (lift ) )) {
#             define XfOrM565_COUNT (0+XfOrM563_COUNT)
#             define SETUP_XfOrM565(x) SETUP_XfOrM563(x)
              (void ) FUNCCALL(SETUP_XfOrM565(_), scheme_resolve_closure_compilation (clv -> value , linfo , 1 , 1 , 0 , lift ) ); 
              clv -> value = ((void * ) 0 ) ; 
            }
            else {
#             define XfOrM564_COUNT (0+XfOrM563_COUNT)
#             define SETUP_XfOrM564(x) SETUP_XfOrM563(x)
              lift = FUNCCALL(SETUP_XfOrM564(_), scheme_resolve_closure_compilation (clv -> value , linfo , 1 , 1 , 2 , ((void * ) 0 ) ) ); 
            }
            FUNCCALL(SETUP_XfOrM563(_), scheme_resolve_info_adjust_mapping (linfo , opos , rpos , 0 , lift ) ); 
            lifted_recs [rpos ] = lift ; 
            rpos ++ ; 
          }
          opos += clv -> count ; 
        }
        break ; 
      }
    }
  }
  extra_alloc = 0 ; 
  val_linfo = linfo ; 
  if (num_rec_procs ) {
#   define XfOrM484_COUNT (0+XfOrM445_COUNT)
#   define SETUP_XfOrM484(x) SETUP_XfOrM445(x)
    if (! lifted_recs ) {
      Scheme_Object * * sa ; 
      BLOCK_SETUP((PUSH(sa, 0+XfOrM484_COUNT)));
#     define XfOrM486_COUNT (1+XfOrM484_COUNT)
#     define SETUP_XfOrM486(x) SETUP(XfOrM486_COUNT)
      sa = NULLED_OUT ; 
      letrec = ((Scheme_Letrec * ) FUNCCALL(SETUP_XfOrM486(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Letrec ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
      letrec -> so . type = scheme_letrec_type ; 
      letrec -> count = num_rec_procs ; 
      sa = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM486(_), GC_malloc (sizeof (Scheme_Object * ) * (num_rec_procs ) ) )) ; 
      letrec -> procs = sa ; 
    }
    else {
      extra_alloc = - num_rec_procs ; 
      letrec = ((void * ) 0 ) ; 
    }
  }
  else letrec = ((void * ) 0 ) ; 
  boxes = scheme_null ; 
  clv = (Scheme_Compiled_Let_Value * ) head -> body ; 
  rpos = 0 ; 
  opos = 0 ; 
  for (i = head -> num_clauses ; i -- ; clv = (Scheme_Compiled_Let_Value * ) clv -> body ) {
#   define XfOrM467_COUNT (0+XfOrM445_COUNT)
#   define SETUP_XfOrM467(x) SETUP_XfOrM445(x)
    if ((clv -> count == 1 ) && ! (clv -> flags [0 ] & 0x1 ) ) {
    }
    else {
      int isproc ; 
      Scheme_Object * expr ; 
      BLOCK_SETUP((PUSH(expr, 0+XfOrM467_COUNT)));
#     define XfOrM468_COUNT (1+XfOrM467_COUNT)
#     define SETUP_XfOrM468(x) SETUP(XfOrM468_COUNT)
      expr = NULLED_OUT ; 
      if (! clv -> value )
        isproc = 1 ; 
      else if (clv -> count == 1 )
        isproc = FUNCCALL(SETUP_XfOrM468(_), scheme_is_compiled_procedure (clv -> value , 0 , 0 ) ); 
      else isproc = 0 ; 
      if (num_rec_procs && isproc ) {
#       define XfOrM479_COUNT (0+XfOrM468_COUNT)
#       define SETUP_XfOrM479(x) SETUP_XfOrM468(x)
        if (! lifted_recs ) {
#         define XfOrM482_COUNT (0+XfOrM479_COUNT)
#         define SETUP_XfOrM482(x) SETUP_XfOrM479(x)
          expr = FUNCCALL(SETUP_XfOrM482(_), scheme_resolve_closure_compilation (clv -> value , val_linfo , 0 , 0 , 0 , ((void * ) 0 ) ) ); 
          letrec -> procs [rpos ++ ] = expr ; 
        }
        else {
#         define XfOrM480_COUNT (0+XfOrM479_COUNT)
#         define SETUP_XfOrM480(x) SETUP_XfOrM479(x)
          if (! FUNCCALL(SETUP_XfOrM480(_), is_closed_reference (lifted_recs [rpos ] ) )) {
#           define XfOrM481_COUNT (0+XfOrM480_COUNT)
#           define SETUP_XfOrM481(x) SETUP_XfOrM480(x)
            (void ) FUNCCALL(SETUP_XfOrM481(_), scheme_resolve_closure_compilation (clv -> value , val_linfo , 1 , 1 , 0 , lifted_recs [rpos ] ) ); 
          }
          rpos ++ ; 
        }
      }
      else {
        int j ; 
        Scheme_Object * one_lifted ; 
        BLOCK_SETUP((PUSH(one_lifted, 0+XfOrM468_COUNT)));
#       define XfOrM469_COUNT (1+XfOrM468_COUNT)
#       define SETUP_XfOrM469(x) SETUP(XfOrM469_COUNT)
        one_lifted = NULLED_OUT ; 
        expr = FUNCCALL(SETUP_XfOrM469(_), scheme_resolve_expr (clv -> value , val_linfo ) ); 
        lv = ((Scheme_Let_Value * ) FUNCCALL(SETUP_XfOrM469(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Let_Value ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
        if (last )
          last -> body = (Scheme_Object * ) lv ; 
        else if (last_body )
          (((Scheme_Simple_Object * ) (last_body ) ) -> u . pair_val . cdr ) = (Scheme_Object * ) lv ; 
        else first = (Scheme_Object * ) lv ; 
        last = lv ; 
        last_body = ((void * ) 0 ) ; 
        lv -> iso . so . type = scheme_let_value_type ; 
        lv -> value = expr ; 
        if (clv -> count ) {
          int li ; 
#         define XfOrM478_COUNT (0+XfOrM469_COUNT)
#         define SETUP_XfOrM478(x) SETUP_XfOrM469(x)
          li = FUNCCALL(SETUP_XfOrM478(_), scheme_resolve_info_lookup (linfo , clv -> position , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ); 
          lv -> position = li ; 
        }
        else lv -> position = 0 ; 
        lv -> count = clv -> count ; 
        (& lv -> iso ) -> so . keyex = recbox ; 
        for (j = lv -> count ; j -- ; ) {
#         define XfOrM474_COUNT (0+XfOrM469_COUNT)
#         define SETUP_XfOrM474(x) SETUP_XfOrM469(x)
          if (! recbox && (FUNCCALL(SETUP_XfOrM474(_), scheme_resolve_info_flags (linfo , opos + j , & one_lifted ) )& 1 ) ) {
            GC_CAN_IGNORE Scheme_Object * pos ; 
#           define XfOrM475_COUNT (0+XfOrM474_COUNT)
#           define SETUP_XfOrM475(x) SETUP_XfOrM474(x)
            pos = ((Scheme_Object * ) (void * ) (long ) ((((long ) (lv -> position + j ) ) << 1 ) | 0x1 ) ) ; 
            if ((& head -> iso ) -> so . keyex & (0x2 | 0x1 ) ) {
              Scheme_Object * boxenv , * pr ; 
              BLOCK_SETUP((PUSH(boxenv, 0+XfOrM475_COUNT), PUSH(pr, 1+XfOrM475_COUNT)));
#             define XfOrM477_COUNT (2+XfOrM475_COUNT)
#             define SETUP_XfOrM477(x) SETUP(XfOrM477_COUNT)
              boxenv = NULLED_OUT ; 
              pr = NULLED_OUT ; 
              pr = FUNCCALL(SETUP_XfOrM477(_), scheme_make_pair (pos , scheme_false ) ); 
              boxenv = FUNCCALL_AGAIN(scheme_make_syntax_resolved (5 , pr ) ); 
              if (last )
                last -> body = boxenv ; 
              else (((Scheme_Simple_Object * ) (last_body ) ) -> u . pair_val . cdr ) = boxenv ; 
              last = ((void * ) 0 ) ; 
              last_body = pr ; 
            }
            else {
#             define XfOrM476_COUNT (0+XfOrM475_COUNT)
#             define SETUP_XfOrM476(x) SETUP_XfOrM475(x)
              boxes = FUNCCALL(SETUP_XfOrM476(_), scheme_make_pair (pos , boxes ) ); 
            }
          }
        }
      }
    }
    opos += clv -> count ; 
  }
  body = FUNCCALL(SETUP_XfOrM445(_), scheme_resolve_expr (body , linfo ) ); 
  while (((Scheme_Type ) (((((long ) (boxes ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (boxes ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#   define XfOrM449_COUNT (0+XfOrM445_COUNT)
#   define SETUP_XfOrM449(x) SETUP_XfOrM445(x)
    body = (__funcarg68 = FUNCCALL(SETUP_XfOrM449(_), scheme_make_pair ((((Scheme_Simple_Object * ) (boxes ) ) -> u . pair_val . car ) , body ) ), FUNCCALL_AGAIN(scheme_make_syntax_resolved (5 , __funcarg68 ) )) ; 
    boxes = (((Scheme_Simple_Object * ) (boxes ) ) -> u . pair_val . cdr ) ; 
  }
  if (letrec ) {
    letrec -> body = body ; 
    if (last )
      last -> body = (Scheme_Object * ) letrec ; 
    else if (last_body )
      (((Scheme_Simple_Object * ) (last_body ) ) -> u . pair_val . cdr ) = (Scheme_Object * ) letrec ; 
    else first = (Scheme_Object * ) letrec ; 
  }
  else if (last )
    last -> body = body ; 
  else if (last_body )
    (((Scheme_Simple_Object * ) (last_body ) ) -> u . pair_val . cdr ) = body ; 
  else first = body ; 
  if (head -> count + extra_alloc - num_skips ) {
    Scheme_Let_Void * lvd ; 
    BLOCK_SETUP((PUSH(lvd, 0+XfOrM445_COUNT)));
#   define XfOrM446_COUNT (1+XfOrM445_COUNT)
#   define SETUP_XfOrM446(x) SETUP(XfOrM446_COUNT)
    lvd = NULLED_OUT ; 
    lvd = ((Scheme_Let_Void * ) FUNCCALL(SETUP_XfOrM446(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Let_Void ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    lvd -> iso . so . type = scheme_let_void_type ; 
    lvd -> body = first ; 
    lvd -> count = head -> count + extra_alloc - num_skips ; 
    (& lvd -> iso ) -> so . keyex = recbox ; 
    first = (Scheme_Object * ) lvd ; 
  }
  if (info -> max_let_depth < linfo -> max_let_depth + head -> count - num_skips + extra_alloc )
    info -> max_let_depth = linfo -> max_let_depth + head -> count - num_skips + extra_alloc ; 
  RET_VALUE_START (first ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * gen_let_syntax (Scheme_Object * form , Scheme_Comp_Env * origenv , char * formname , int star , int recursive , int multi , Scheme_Compile_Info * rec , int drec , Scheme_Comp_Env * frame_already ) {
  Scheme_Object * bindings , * l , * binding , * name , * * names , * forms , * defname ; 
  int num_clauses , num_bindings , i , j , k , m , pre_k ; 
  Scheme_Comp_Env * frame , * env ; 
  Scheme_Compile_Info * recs ; 
  Scheme_Object * first = ((void * ) 0 ) ; 
  Scheme_Compiled_Let_Value * last = ((void * ) 0 ) , * lv ; 
  DupCheckRecord r ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(24);
  BLOCK_SETUP_TOP((PUSH(recs, 0), PUSH(origenv, 1), PUSHARRAY(r.syms, 5, 2), PUSH(r.ht, 5), PUSH(frame, 6), PUSH(forms, 7), PUSH(env, 8), PUSH(bindings, 9), PUSH(l, 10), PUSH(frame_already, 11), PUSH(first, 12), PUSH(defname, 13), PUSH(name, 14), PUSH(last, 15), PUSH(names, 16), PUSH(binding, 17), PUSH(rec, 18), PUSH(lv, 19), PUSH(form, 20)));
# define XfOrM694_COUNT (21)
# define SETUP_XfOrM694(x) SETUP(XfOrM694_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  bindings = NULLED_OUT ; 
  l = NULLED_OUT ; 
  binding = NULLED_OUT ; 
  name = NULLED_OUT ; 
  names = NULLED_OUT ; 
  forms = NULLED_OUT ; 
  defname = NULLED_OUT ; 
  frame = NULLED_OUT ; 
  env = NULLED_OUT ; 
  recs = NULLED_OUT ; 
  lv = NULLED_OUT ; 
  NULL_OUT_ARRAY (r.syms ) ; 
  r.ht = NULLED_OUT ; 
  i = FUNCCALL(SETUP_XfOrM694(_), scheme_stx_proper_list_length (form ) ); 
  if (i < 3 )
    FUNCCALL(SETUP_XfOrM694(_), scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , form , (! i ? "bad syntax (empty body)" : ((void * ) 0 ) ) ) ); 
  bindings = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM694(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  bindings = (((Scheme_Type ) (((((long ) (bindings ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (bindings ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (bindings ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM694(_), scheme_stx_content (bindings ) )) ) -> u . pair_val . car ) ) ; 
  num_clauses = FUNCCALL(SETUP_XfOrM694(_), scheme_stx_proper_list_length (bindings ) ); 
  if (num_clauses < 0 )
    FUNCCALL(SETUP_XfOrM694(_), scheme_wrong_syntax (((void * ) 0 ) , bindings , form , ((void * ) 0 ) ) ); 
  FUNCCALL(SETUP_XfOrM694(_), scheme_rec_add_certs (rec , drec , form ) ); 
  forms = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM694(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  forms = (((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (forms ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM694(_), scheme_stx_content (forms ) )) ) -> u . pair_val . cdr ) ) ; 
  forms = FUNCCALL(SETUP_XfOrM694(_), scheme_datum_to_syntax (forms , form , form , 0 , 0 ) ); 
  if (! num_clauses ) {
#   define XfOrM753_COUNT (0+XfOrM694_COUNT)
#   define SETUP_XfOrM753(x) SETUP_XfOrM694(x)
    env = FUNCCALL(SETUP_XfOrM753(_), scheme_no_defines (origenv ) ); 
    name = FUNCCALL(SETUP_XfOrM753(_), scheme_check_name_property (form , rec [drec ] . value_name ) ); 
    rec [drec ] . value_name = name ; 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM753(_), scheme_compile_sequence (forms , env , rec , drec ) )) RET_VALUE_END ; 
  }
  if (multi ) {
#   define XfOrM746_COUNT (0+XfOrM694_COUNT)
#   define SETUP_XfOrM746(x) SETUP_XfOrM694(x)
    num_bindings = 0 ; 
    l = bindings ; 
    while (! (((l ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) l ) -> val ) == (scheme_null ) ) ) ) ) {
      Scheme_Object * clause , * names , * rest ; 
      int num_names ; 
      BLOCK_SETUP((PUSH(names, 0+XfOrM746_COUNT), PUSH(clause, 1+XfOrM746_COUNT), PUSH(rest, 2+XfOrM746_COUNT)));
#     define XfOrM750_COUNT (3+XfOrM746_COUNT)
#     define SETUP_XfOrM750(x) SETUP(XfOrM750_COUNT)
      clause = NULLED_OUT ; 
      names = NULLED_OUT ; 
      rest = NULLED_OUT ; 
      clause = (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM750(_), scheme_stx_content (l ) )) ) -> u . pair_val . car ) ) ; 
      if (! (((Scheme_Type ) (((((long ) (clause ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (clause ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (clause ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (clause ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) clause ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) clause ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
        rest = ((void * ) 0 ) ; 
      else {
#       define XfOrM751_COUNT (0+XfOrM750_COUNT)
#       define SETUP_XfOrM751(x) SETUP_XfOrM750(x)
        rest = (((Scheme_Type ) (((((long ) (clause ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (clause ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (clause ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM751(_), scheme_stx_content (clause ) )) ) -> u . pair_val . cdr ) ) ; 
        if (! (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) rest ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) rest ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
          rest = ((void * ) 0 ) ; 
        else {
#         define XfOrM752_COUNT (0+XfOrM751_COUNT)
#         define SETUP_XfOrM752(x) SETUP_XfOrM751(x)
          rest = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM752(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ; 
          if (! (((rest ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) rest ) -> val ) == (scheme_null ) ) ) ) )
            rest = ((void * ) 0 ) ; 
        }
      }
      if (! rest )
        FUNCCALL(SETUP_XfOrM750(_), scheme_wrong_syntax (((void * ) 0 ) , clause , form , ((void * ) 0 ) ) ); 
      names = (((Scheme_Type ) (((((long ) (clause ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (clause ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (clause ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM750(_), scheme_stx_content (clause ) )) ) -> u . pair_val . car ) ) ; 
      num_names = FUNCCALL(SETUP_XfOrM750(_), scheme_stx_proper_list_length (names ) ); 
      if (num_names < 0 )
        FUNCCALL(SETUP_XfOrM750(_), scheme_wrong_syntax (((void * ) 0 ) , names , form , ((void * ) 0 ) ) ); 
      num_bindings += num_names ; 
      l = (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM750(_), scheme_stx_content (l ) )) ) -> u . pair_val . cdr ) ) ; 
    }
  }
  else num_bindings = num_clauses ; 
  names = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM694(_), GC_malloc (sizeof (Scheme_Object * ) * (num_bindings ) ) )) ; 
  if (frame_already )
    frame = frame_already ; 
  else frame = FUNCCALL(SETUP_XfOrM694(_), scheme_new_compilation_frame (num_bindings , 0 , origenv , rec [drec ] . certs ) ); 
  env = frame ; 
  recs = ((Scheme_Compile_Info * ) FUNCCALL(SETUP_XfOrM694(_), GC_malloc_array_tagged (sizeof (Scheme_Compile_Info ) * ((num_clauses + 1 ) ) ) )) ; 
  defname = rec [drec ] . value_name ; 
  FUNCCALL(SETUP_XfOrM694(_), scheme_compile_rec_done_local (rec , drec ) ); 
  FUNCCALL_AGAIN(scheme_init_compile_recs (rec , drec , recs , num_clauses + 1 ) ); 
  defname = FUNCCALL_AGAIN(scheme_check_name_property (form , defname ) ); 
  if (! star ) {
#   define XfOrM745_COUNT (0+XfOrM694_COUNT)
#   define SETUP_XfOrM745(x) SETUP_XfOrM694(x)
    FUNCCALL(SETUP_XfOrM745(_), scheme_begin_dup_symbol_check (& r , env ) ); 
  }
  for (i = 0 , k = 0 ; i < num_clauses ; i ++ ) {
#   define XfOrM725_COUNT (0+XfOrM694_COUNT)
#   define SETUP_XfOrM725(x) SETUP_XfOrM694(x)
    if (! (((Scheme_Type ) (((((long ) (bindings ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (bindings ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (bindings ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (bindings ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) bindings ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) bindings ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
      FUNCCALL(SETUP_XfOrM725(_), scheme_wrong_syntax (((void * ) 0 ) , bindings , form , ((void * ) 0 ) ) ); 
    binding = (((Scheme_Type ) (((((long ) (bindings ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (bindings ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (bindings ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM725(_), scheme_stx_content (bindings ) )) ) -> u . pair_val . car ) ) ; 
    if (! (((Scheme_Type ) (((((long ) (binding ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (binding ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (binding ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (binding ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) binding ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) binding ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) || ! (((Scheme_Type ) (((((long ) ((((Scheme_Type ) (((((long ) (binding ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (binding ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (binding ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM725(_), scheme_stx_content (binding ) )) ) -> u . pair_val . cdr ) ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Type ) (((((long ) (binding ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (binding ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (binding ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM725(_), scheme_stx_content (binding ) )) ) -> u . pair_val . cdr ) ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) ((((Scheme_Type ) (((((long ) (binding ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (binding ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (binding ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM725(_), scheme_stx_content (binding ) )) ) -> u . pair_val . cdr ) ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Type ) (((((long ) (binding ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (binding ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (binding ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM725(_), scheme_stx_content (binding ) )) ) -> u . pair_val . cdr ) ) ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (binding ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (binding ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (binding ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM725(_), scheme_stx_content (binding ) )) ) -> u . pair_val . cdr ) ) ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (binding ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (binding ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (binding ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM725(_), scheme_stx_content (binding ) )) ) -> u . pair_val . cdr ) ) ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
      FUNCCALL(SETUP_XfOrM725(_), scheme_wrong_syntax (((void * ) 0 ) , binding , form , ((void * ) 0 ) ) ); 
    {
      Scheme_Object * rest ; 
      BLOCK_SETUP((PUSH(rest, 0+XfOrM725_COUNT)));
#     define XfOrM744_COUNT (1+XfOrM725_COUNT)
#     define SETUP_XfOrM744(x) SETUP(XfOrM744_COUNT)
      rest = NULLED_OUT ; 
      rest = (((Scheme_Type ) (((((long ) (binding ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (binding ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (binding ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM744(_), scheme_stx_content (binding ) )) ) -> u . pair_val . cdr ) ) ; 
      if (! ((((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM744(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) ((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM744(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM744(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM744(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) -> val ) == (scheme_null ) ) ) ) )
        FUNCCALL(SETUP_XfOrM744(_), scheme_wrong_syntax (((void * ) 0 ) , binding , form , ((void * ) 0 ) ) ); 
    }
    pre_k = k ; 
    name = (((Scheme_Type ) (((((long ) (binding ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (binding ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (binding ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM725(_), scheme_stx_content (binding ) )) ) -> u . pair_val . car ) ) ; 
    if (multi ) {
#     define XfOrM735_COUNT (0+XfOrM725_COUNT)
#     define SETUP_XfOrM735(x) SETUP_XfOrM725(x)
      while (! (((name ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) name ) -> val ) == (scheme_null ) ) ) ) ) {
        Scheme_Object * n ; 
        BLOCK_SETUP((PUSH(n, 0+XfOrM735_COUNT)));
#       define XfOrM743_COUNT (1+XfOrM735_COUNT)
#       define SETUP_XfOrM743(x) SETUP(XfOrM743_COUNT)
        n = NULLED_OUT ; 
        n = (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (name ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM743(_), scheme_stx_content (name ) )) ) -> u . pair_val . car ) ) ; 
        names [k ] = n ; 
        FUNCCALL(SETUP_XfOrM743(_), scheme_check_identifier (((void * ) 0 ) , names [k ] , ((void * ) 0 ) , env , form ) ); 
        k ++ ; 
        name = (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (name ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM743(_), scheme_stx_content (name ) )) ) -> u . pair_val . cdr ) ) ; 
      }
      for (j = pre_k ; j < k ; j ++ ) {
#       define XfOrM739_COUNT (0+XfOrM735_COUNT)
#       define SETUP_XfOrM739(x) SETUP_XfOrM735(x)
        for (m = j + 1 ; m < k ; m ++ ) {
#         define XfOrM741_COUNT (0+XfOrM739_COUNT)
#         define SETUP_XfOrM741(x) SETUP_XfOrM739(x)
          if (FUNCCALL(SETUP_XfOrM741(_), scheme_stx_bound_eq (names [m ] , names [j ] , env -> genv -> phase ) ))
            FUNCCALL(SETUP_XfOrM741(_), scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , form , "multiple bindings of `%S' in the same clause" , (((Scheme_Type ) (((((long ) (names [m ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (names [m ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ? ((Scheme_Stx * ) names [m ] ) -> val : names [m ] ) ) ); 
        }
      }
    }
    else {
#     define XfOrM734_COUNT (0+XfOrM725_COUNT)
#     define SETUP_XfOrM734(x) SETUP_XfOrM725(x)
      FUNCCALL(SETUP_XfOrM734(_), scheme_check_identifier (((void * ) 0 ) , name , ((void * ) 0 ) , env , form ) ); 
      names [k ++ ] = name ; 
    }
    if (! star ) {
#     define XfOrM731_COUNT (0+XfOrM725_COUNT)
#     define SETUP_XfOrM731(x) SETUP_XfOrM725(x)
      for (m = pre_k ; m < k ; m ++ ) {
#       define XfOrM733_COUNT (0+XfOrM731_COUNT)
#       define SETUP_XfOrM733(x) SETUP_XfOrM731(x)
        FUNCCALL(SETUP_XfOrM733(_), scheme_dup_symbol_check (& r , ((void * ) 0 ) , names [m ] , "binding" , form ) ); 
      }
    }
    lv = ((Scheme_Compiled_Let_Value * ) FUNCCALL(SETUP_XfOrM725(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Compiled_Let_Value ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    lv -> so . type = scheme_compiled_let_value_type ; 
    if (! last )
      first = (Scheme_Object * ) lv ; 
    else last -> body = (Scheme_Object * ) lv ; 
    last = lv ; 
    lv -> count = (k - pre_k ) ; 
    lv -> position = pre_k ; 
    if (lv -> count == 1 )
      recs [i ] . value_name = (((Scheme_Type ) (((((long ) (names [pre_k ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (names [pre_k ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ? ((Scheme_Stx * ) names [pre_k ] ) -> val : names [pre_k ] ) ; 
    if (! recursive ) {
      Scheme_Object * ce , * rhs ; 
      BLOCK_SETUP((PUSH(rhs, 0+XfOrM725_COUNT), PUSH(ce, 1+XfOrM725_COUNT)));
#     define XfOrM730_COUNT (2+XfOrM725_COUNT)
#     define SETUP_XfOrM730(x) SETUP(XfOrM730_COUNT)
      ce = NULLED_OUT ; 
      rhs = NULLED_OUT ; 
      rhs = (((Scheme_Type ) (((((long ) (binding ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (binding ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (binding ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM730(_), scheme_stx_content (binding ) )) ) -> u . pair_val . cdr ) ) ; 
      rhs = (((Scheme_Type ) (((((long ) (rhs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rhs ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rhs ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM730(_), scheme_stx_content (rhs ) )) ) -> u . pair_val . car ) ) ; 
      rhs = FUNCCALL(SETUP_XfOrM730(_), scheme_add_env_renames (rhs , env , origenv ) ); 
      ce = FUNCCALL_AGAIN(scheme_compile_expr (rhs , env , recs , i ) ); 
      lv -> value = ce ; 
    }
    else {
      Scheme_Object * rhs ; 
      BLOCK_SETUP((PUSH(rhs, 0+XfOrM725_COUNT)));
#     define XfOrM729_COUNT (1+XfOrM725_COUNT)
#     define SETUP_XfOrM729(x) SETUP(XfOrM729_COUNT)
      rhs = NULLED_OUT ; 
      rhs = (((Scheme_Type ) (((((long ) (binding ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (binding ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (binding ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM729(_), scheme_stx_content (binding ) )) ) -> u . pair_val . cdr ) ) ; 
      rhs = (((Scheme_Type ) (((((long ) (rhs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rhs ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rhs ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM729(_), scheme_stx_content (rhs ) )) ) -> u . pair_val . car ) ) ; 
      lv -> value = rhs ; 
    }
    if (star || recursive ) {
#     define XfOrM726_COUNT (0+XfOrM725_COUNT)
#     define SETUP_XfOrM726(x) SETUP_XfOrM725(x)
      for (m = pre_k ; m < k ; m ++ ) {
#       define XfOrM728_COUNT (0+XfOrM726_COUNT)
#       define SETUP_XfOrM728(x) SETUP_XfOrM726(x)
        FUNCCALL(SETUP_XfOrM728(_), scheme_add_compilation_binding (m , names [m ] , frame ) ); 
      }
    }
    bindings = (((Scheme_Type ) (((((long ) (bindings ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (bindings ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (bindings ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM725(_), scheme_stx_content (bindings ) )) ) -> u . pair_val . cdr ) ) ; 
  }
  if (! star && ! recursive ) {
#   define XfOrM702_COUNT (0+XfOrM694_COUNT)
#   define SETUP_XfOrM702(x) SETUP_XfOrM694(x)
    for (i = 0 ; i < num_bindings ; i ++ ) {
#     define XfOrM704_COUNT (0+XfOrM702_COUNT)
#     define SETUP_XfOrM704(x) SETUP_XfOrM702(x)
      FUNCCALL(SETUP_XfOrM704(_), scheme_add_compilation_binding (i , names [i ] , frame ) ); 
    }
  }
  if (recursive ) {
#   define XfOrM699_COUNT (0+XfOrM694_COUNT)
#   define SETUP_XfOrM699(x) SETUP_XfOrM694(x)
    lv = (Scheme_Compiled_Let_Value * ) first ; 
    for (i = 0 ; i < num_clauses ; i ++ , lv = (Scheme_Compiled_Let_Value * ) lv -> body ) {
      Scheme_Object * ce , * rhs ; 
      BLOCK_SETUP((PUSH(rhs, 0+XfOrM699_COUNT), PUSH(ce, 1+XfOrM699_COUNT)));
#     define XfOrM701_COUNT (2+XfOrM699_COUNT)
#     define SETUP_XfOrM701(x) SETUP(XfOrM701_COUNT)
      ce = NULLED_OUT ; 
      rhs = NULLED_OUT ; 
      rhs = lv -> value ; 
      rhs = FUNCCALL(SETUP_XfOrM701(_), scheme_add_env_renames (rhs , env , origenv ) ); 
      ce = FUNCCALL_AGAIN(scheme_compile_expr (rhs , env , recs , i ) ); 
      lv -> value = ce ; 
    }
  }
  recs [num_clauses ] . value_name = defname ? (((Scheme_Type ) (((((long ) (defname ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (defname ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ? ((Scheme_Stx * ) defname ) -> val : defname ) : ((void * ) 0 ) ; 
  {
    Scheme_Object * cs ; 
    BLOCK_SETUP((PUSH(cs, 0+XfOrM694_COUNT)));
#   define XfOrM698_COUNT (1+XfOrM694_COUNT)
#   define SETUP_XfOrM698(x) SETUP(XfOrM698_COUNT)
    cs = NULLED_OUT ; 
    forms = FUNCCALL(SETUP_XfOrM698(_), scheme_add_env_renames (forms , env , origenv ) ); 
    cs = FUNCCALL_AGAIN(scheme_compile_sequence (forms , env , recs , num_clauses ) ); 
    last -> body = cs ; 
  }
  lv = (Scheme_Compiled_Let_Value * ) first ; 
  for (i = 0 ; i < num_clauses ; i ++ , lv = (Scheme_Compiled_Let_Value * ) lv -> body ) {
    int * flags ; 
    BLOCK_SETUP((PUSH(flags, 0+XfOrM694_COUNT)));
#   define XfOrM697_COUNT (1+XfOrM694_COUNT)
#   define SETUP_XfOrM697(x) SETUP(XfOrM697_COUNT)
    flags = NULLED_OUT ; 
    flags = FUNCCALL(SETUP_XfOrM697(_), scheme_env_get_flags (env , lv -> position , lv -> count ) ); 
    lv -> flags = flags ; 
  }
  {
    Scheme_Let_Header * head ; 
    BLOCK_SETUP((PUSH(head, 0+XfOrM694_COUNT)));
#   define XfOrM695_COUNT (1+XfOrM694_COUNT)
#   define SETUP_XfOrM695(x) SETUP(XfOrM695_COUNT)
    head = NULLED_OUT ; 
    head = ((Scheme_Let_Header * ) FUNCCALL(SETUP_XfOrM695(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Let_Header ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    head -> iso . so . type = scheme_compiled_let_void_type ; 
    head -> body = first ; 
    head -> count = num_bindings ; 
    head -> num_clauses = num_clauses ; 
    (& head -> iso ) -> so . keyex = ((recursive ? 0x1 : 0 ) | (star ? 0x2 : 0 ) ) ; 
    first = (Scheme_Object * ) head ; 
  }
  FUNCCALL(SETUP_XfOrM694(_), scheme_merge_compile_recs (rec , drec , recs , num_clauses + 1 ) ); 
  RET_VALUE_START (first ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_let_expand (Scheme_Object * form , Scheme_Comp_Env * origenv , Scheme_Expand_Info * erec , int drec , const char * formname , int letrec , int multi , int letstar , Scheme_Comp_Env * env_already ) {
  Scheme_Object * vars , * body , * first , * last , * name , * v , * vs , * vlist , * boundname ; 
  Scheme_Comp_Env * use_env , * env ; 
  Scheme_Expand_Info erec1 ; 
  DupCheckRecord r ; 
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
  Scheme_Object * __funcarg74 = NULLED_OUT ; 
  Scheme_Object * __funcarg73 = NULLED_OUT ; 
  Scheme_Object * __funcarg72 = NULLED_OUT ; 
  Scheme_Object * __funcarg69 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(28);
  BLOCK_SETUP_TOP((PUSH(first, 0), PUSH(vs, 1), PUSHARRAY(r.syms, 5, 2), PUSH(r.ht, 5), PUSH(use_env, 6), PUSH(last, 7), PUSH(vars, 8), PUSH(env, 9), PUSH(erec1.value_name, 10), PUSH(erec1.certs, 11), PUSH(erec1.observer, 12), PUSH(env_already, 13), PUSH(name, 14), PUSH(boundname, 15), PUSH(v, 16), PUSH(origenv, 17), PUSH(vlist, 18), PUSH(erec, 19), PUSH(form, 20), PUSH(body, 21)));
# define XfOrM754_COUNT (22)
# define SETUP_XfOrM754(x) SETUP(XfOrM754_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  vars = NULLED_OUT ; 
  body = NULLED_OUT ; 
  first = NULLED_OUT ; 
  last = NULLED_OUT ; 
  name = NULLED_OUT ; 
  v = NULLED_OUT ; 
  vs = NULLED_OUT ; 
  vlist = NULLED_OUT ; 
  boundname = NULLED_OUT ; 
  use_env = NULLED_OUT ; 
  env = NULLED_OUT ; 
  erec1.value_name = NULLED_OUT ; 
  erec1.certs = NULLED_OUT ; 
  erec1.observer = NULLED_OUT ; 
  NULL_OUT_ARRAY (r.syms ) ; 
  r.ht = NULLED_OUT ; 
  vars = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM754(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  if (! (((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) vars ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) vars ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
    FUNCCALL(SETUP_XfOrM754(_), scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , form , ((void * ) 0 ) ) ); 
  body = (((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (vars ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM754(_), scheme_stx_content (vars ) )) ) -> u . pair_val . cdr ) ) ; 
  vars = (((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (vars ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM754(_), scheme_stx_content (vars ) )) ) -> u . pair_val . car ) ) ; 
  if (! (((Scheme_Type ) (((((long ) (body ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (body ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (body ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (body ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) body ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) body ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
    FUNCCALL(SETUP_XfOrM754(_), scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , form , ((((body ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (body ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (body ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) body ) -> val ) == (scheme_null ) ) ) ) ? "bad syntax (empty body)" : ((void * ) 0 ) ) ) ); 
  boundname = FUNCCALL(SETUP_XfOrM754(_), scheme_check_name_property (form , erec [drec ] . value_name ) ); 
  erec [drec ] . value_name = boundname ; 
  FUNCCALL(SETUP_XfOrM754(_), scheme_rec_add_certs (erec , drec , form ) ); 
  if (letstar ) {
#   define XfOrM780_COUNT (0+XfOrM754_COUNT)
#   define SETUP_XfOrM780(x) SETUP_XfOrM754(x)
    if (! (((vars ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) vars ) -> val ) == (scheme_null ) ) ) ) ) {
      Scheme_Object * a , * vr ; 
      BLOCK_SETUP((PUSH(a, 0+XfOrM780_COUNT), PUSH(vr, 1+XfOrM780_COUNT)));
#     define XfOrM783_COUNT (2+XfOrM780_COUNT)
#     define SETUP_XfOrM783(x) SETUP(XfOrM783_COUNT)
      a = NULLED_OUT ; 
      vr = NULLED_OUT ; 
      if (! (((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) vars ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) vars ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
        FUNCCALL(SETUP_XfOrM783(_), scheme_wrong_syntax (((void * ) 0 ) , vars , form , ((void * ) 0 ) ) ); 
      a = (((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (vars ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM783(_), scheme_stx_content (vars ) )) ) -> u . pair_val . car ) ) ; 
      vr = (((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (vars ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM783(_), scheme_stx_content (vars ) )) ) -> u . pair_val . cdr ) ) ; 
      first = let_values_symbol ; 
      first = (__funcarg86 = FUNCCALL(SETUP_XfOrM783(_), scheme_sys_wraps (origenv ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (first , form , __funcarg86 , 0 , 0 ) )) ; 
      if ((((vr ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (vr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vr ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) vr ) -> val ) == (scheme_null ) ) ) ) ) {
      }
      else {
#       define XfOrM784_COUNT (0+XfOrM783_COUNT)
#       define SETUP_XfOrM784(x) SETUP_XfOrM783(x)
        last = let_star_values_symbol ; 
        last = (__funcarg85 = FUNCCALL(SETUP_XfOrM784(_), scheme_sys_wraps (origenv ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (last , form , __funcarg85 , 0 , 0 ) )) ; 
        body = (__funcarg83 = (__funcarg84 = FUNCCALL(SETUP_XfOrM784(_), scheme_make_immutable_pair (vr , body ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (last , __funcarg84 ) )) , FUNCCALL_AGAIN(scheme_make_immutable_pair (__funcarg83 , scheme_null ) )) ; 
      }
      body = (__funcarg81 = (__funcarg82 = FUNCCALL(SETUP_XfOrM783(_), scheme_make_immutable_pair (a , scheme_null ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (__funcarg82 , body ) )) , FUNCCALL_AGAIN(scheme_make_immutable_pair (first , __funcarg81 ) )) ; 
    }
    else {
#     define XfOrM782_COUNT (0+XfOrM780_COUNT)
#     define SETUP_XfOrM782(x) SETUP_XfOrM780(x)
      first = (__funcarg80 = FUNCCALL(SETUP_XfOrM782(_), scheme_sys_wraps (origenv ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (let_values_symbol , form , __funcarg80 , 0 , 0 ) )) ; 
      body = (__funcarg79 = FUNCCALL(SETUP_XfOrM782(_), scheme_make_immutable_pair (scheme_null , body ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (first , __funcarg79 ) )) ; 
    }
    body = FUNCCALL(SETUP_XfOrM780(_), scheme_datum_to_syntax (body , form , form , 0 , - 1 ) ); 
    first = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM780(_), scheme_stx_content (form ) )) ) -> u . pair_val . car ) ) ; 
    body = FUNCCALL(SETUP_XfOrM780(_), scheme_stx_track (body , form , first ) ); 
    if (erec [drec ] . depth > 0 )
      -- erec [drec ] . depth ; 
    if (! erec [drec ] . depth )
      RET_VALUE_START (body ) RET_VALUE_END ; 
    else {
#     define XfOrM781_COUNT (0+XfOrM780_COUNT)
#     define SETUP_XfOrM781(x) SETUP_XfOrM780(x)
      env = FUNCCALL(SETUP_XfOrM781(_), scheme_no_defines (origenv ) ); 
      RET_VALUE_START (FUNCCALL(SETUP_XfOrM781(_), scheme_expand_expr (body , env , erec , drec ) )) RET_VALUE_END ; 
    }
  }
  FUNCCALL(SETUP_XfOrM754(_), scheme_begin_dup_symbol_check (& r , origenv ) ); 
  vlist = scheme_null ; 
  vs = vars ; 
  while ((((Scheme_Type ) (((((long ) (vs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vs ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (vs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vs ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) vs ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) vs ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
    Scheme_Object * v2 ; 
    BLOCK_SETUP((PUSH(v2, 0+XfOrM754_COUNT)));
#   define XfOrM776_COUNT (1+XfOrM754_COUNT)
#   define SETUP_XfOrM776(x) SETUP(XfOrM776_COUNT)
    v2 = NULLED_OUT ; 
    v = (((Scheme_Type ) (((((long ) (vs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vs ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (vs ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM776(_), scheme_stx_content (vs ) )) ) -> u . pair_val . car ) ) ; 
    if ((((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) v ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) v ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
      v2 = (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM776(_), scheme_stx_content (v ) )) ) -> u . pair_val . cdr ) ) ; 
    else v2 = scheme_false ; 
    if (! (((Scheme_Type ) (((((long ) (v2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v2 ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (v2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v2 ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) v2 ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) v2 ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) || ! ((((((Scheme_Type ) (((((long ) (v2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v2 ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (v2 ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM776(_), scheme_stx_content (v2 ) )) ) -> u . pair_val . cdr ) ) ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) ((((Scheme_Type ) (((((long ) (v2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v2 ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (v2 ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM776(_), scheme_stx_content (v2 ) )) ) -> u . pair_val . cdr ) ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Type ) (((((long ) (v2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v2 ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (v2 ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM776(_), scheme_stx_content (v2 ) )) ) -> u . pair_val . cdr ) ) ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (v2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v2 ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (v2 ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM776(_), scheme_stx_content (v2 ) )) ) -> u . pair_val . cdr ) ) ) -> val ) == (scheme_null ) ) ) ) )
      FUNCCALL(SETUP_XfOrM776(_), scheme_wrong_syntax (((void * ) 0 ) , v , form , ((void * ) 0 ) ) ); 
    name = (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM776(_), scheme_stx_content (v ) )) ) -> u . pair_val . car ) ) ; 
    {
      DupCheckRecord r2 ; 
      Scheme_Object * names = name ; 
      BLOCK_SETUP((PUSH(names, 0+XfOrM776_COUNT), PUSHARRAY(r2.syms, 5, 1+XfOrM776_COUNT), PUSH(r2.ht, 4+XfOrM776_COUNT)));
#     define XfOrM777_COUNT (5+XfOrM776_COUNT)
#     define SETUP_XfOrM777(x) SETUP(XfOrM777_COUNT)
      NULL_OUT_ARRAY (r2.syms ) ; 
      r2.ht = NULLED_OUT ; 
      FUNCCALL(SETUP_XfOrM777(_), scheme_begin_dup_symbol_check (& r2 , origenv ) ); 
      while ((((Scheme_Type ) (((((long ) (names ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (names ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (names ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (names ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) names ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) names ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
#       define XfOrM779_COUNT (0+XfOrM777_COUNT)
#       define SETUP_XfOrM779(x) SETUP_XfOrM777(x)
        name = (((Scheme_Type ) (((((long ) (names ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (names ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (names ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM779(_), scheme_stx_content (names ) )) ) -> u . pair_val . car ) ) ; 
        FUNCCALL(SETUP_XfOrM779(_), scheme_check_identifier (((void * ) 0 ) , name , ((void * ) 0 ) , origenv , form ) ); 
        vlist = FUNCCALL_AGAIN(scheme_make_pair (name , vlist ) ); 
        FUNCCALL_AGAIN(scheme_dup_symbol_check (& r2 , ((void * ) 0 ) , name , "clause binding" , form ) ); 
        FUNCCALL_AGAIN(scheme_dup_symbol_check (& r , ((void * ) 0 ) , name , "binding" , form ) ); 
        names = (((Scheme_Type ) (((((long ) (names ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (names ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (names ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM779(_), scheme_stx_content (names ) )) ) -> u . pair_val . cdr ) ) ; 
      }
      if (! (((names ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (names ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (names ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) names ) -> val ) == (scheme_null ) ) ) ) )
        FUNCCALL(SETUP_XfOrM777(_), scheme_wrong_syntax (((void * ) 0 ) , names , form , ((void * ) 0 ) ) ); 
    }
    vs = (((Scheme_Type ) (((((long ) (vs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vs ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (vs ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM776(_), scheme_stx_content (vs ) )) ) -> u . pair_val . cdr ) ) ; 
  }
  if (! (((vs ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (vs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vs ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) vs ) -> val ) == (scheme_null ) ) ) ) )
    FUNCCALL(SETUP_XfOrM754(_), scheme_wrong_syntax (((void * ) 0 ) , vs , form , ((void * ) 0 ) ) ); 
  if (env_already )
    env = env_already ; 
  else env = FUNCCALL(SETUP_XfOrM754(_), scheme_add_compilation_frame (vlist , origenv , 0 , erec [drec ] . certs ) ); 
  if (letrec )
    use_env = env ; 
  else use_env = FUNCCALL(SETUP_XfOrM754(_), scheme_no_defines (origenv ) ); 
  first = last = ((void * ) 0 ) ; 
  vs = vars ; 
  while ((((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) vars ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) vars ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
    Scheme_Object * rhs ; 
    BLOCK_SETUP((PUSH(rhs, 0+XfOrM754_COUNT)));
#   define XfOrM771_COUNT (1+XfOrM754_COUNT)
#   define SETUP_XfOrM771(x) SETUP(XfOrM771_COUNT)
    rhs = NULLED_OUT ; 
    v = (((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (vars ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM771(_), scheme_stx_content (vars ) )) ) -> u . pair_val . car ) ) ; 
    name = (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM771(_), scheme_stx_content (v ) )) ) -> u . pair_val . car ) ) ; 
    name = FUNCCALL(SETUP_XfOrM771(_), scheme_add_env_renames (name , env , origenv ) ); 
    rhs = (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM771(_), scheme_stx_content (v ) )) ) -> u . pair_val . cdr ) ) ; 
    rhs = (((Scheme_Type ) (((((long ) (rhs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rhs ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rhs ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM771(_), scheme_stx_content (rhs ) )) ) -> u . pair_val . car ) ) ; 
    rhs = FUNCCALL(SETUP_XfOrM771(_), scheme_add_env_renames (rhs , use_env , origenv ) ); 
    v = (__funcarg77 = (__funcarg78 = FUNCCALL(SETUP_XfOrM771(_), scheme_make_immutable_pair (rhs , scheme_null ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (name , __funcarg78 ) )) , FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg77 , v , v , 0 , 1 ) )) ; 
    v = FUNCCALL_AGAIN(scheme_make_immutable_pair (v , scheme_null ) ); 
    if (! first )
      first = v ; 
    else (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = v ; 
    last = v ; 
    vars = (((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (vars ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM771(_), scheme_stx_content (vars ) )) ) -> u . pair_val . cdr ) ) ; 
  }
  if (! first ) {
    first = scheme_null ; 
  }
  vars = first ; 
  body = FUNCCALL(SETUP_XfOrM754(_), scheme_datum_to_syntax (body , form , form , 0 , 0 ) ); 
  body = FUNCCALL_AGAIN(scheme_add_env_renames (body , env , origenv ) ); 
  if (erec [drec ] . observer ) {
#   define XfOrM768_COUNT (0+XfOrM754_COUNT)
#   define SETUP_XfOrM768(x) SETUP_XfOrM754(x)
    (__funcarg74 = FUNCCALL(SETUP_XfOrM768(_), scheme_make_immutable_pair (vars , body ) ), FUNCCALL_AGAIN(scheme_call_expand_observe (erec [drec ] . observer , 16 , __funcarg74 ) )) ; 
  }
  else {
  }
  ; 
  first = last = ((void * ) 0 ) ; 
  while ((((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) vars ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) vars ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
    Scheme_Object * rhs , * rhs_name ; 
    BLOCK_SETUP((PUSH(rhs, 0+XfOrM754_COUNT), PUSH(rhs_name, 1+XfOrM754_COUNT)));
#   define XfOrM762_COUNT (2+XfOrM754_COUNT)
#   define SETUP_XfOrM762(x) SETUP(XfOrM762_COUNT)
    rhs = NULLED_OUT ; 
    rhs_name = NULLED_OUT ; 
    if (erec [drec ] . observer ) {
#     define XfOrM766_COUNT (0+XfOrM762_COUNT)
#     define SETUP_XfOrM766(x) SETUP_XfOrM762(x)
      FUNCCALL(SETUP_XfOrM766(_), scheme_call_expand_observe (erec [drec ] . observer , 3 , ((void * ) 0 ) ) ); 
    }
    else {
    }
    ; 
    v = (((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (vars ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM762(_), scheme_stx_content (vars ) )) ) -> u . pair_val . car ) ) ; 
    name = (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM762(_), scheme_stx_content (v ) )) ) -> u . pair_val . car ) ) ; 
    rhs = (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM762(_), scheme_stx_content (v ) )) ) -> u . pair_val . cdr ) ) ; 
    rhs = (((Scheme_Type ) (((((long ) (rhs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rhs ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rhs ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM762(_), scheme_stx_content (rhs ) )) ) -> u . pair_val . car ) ) ; 
    if ((((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) name ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) name ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) && ((((((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (name ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM762(_), scheme_stx_content (name ) )) ) -> u . pair_val . cdr ) ) ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) ((((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (name ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM762(_), scheme_stx_content (name ) )) ) -> u . pair_val . cdr ) ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (name ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM762(_), scheme_stx_content (name ) )) ) -> u . pair_val . cdr ) ) ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (name ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM762(_), scheme_stx_content (name ) )) ) -> u . pair_val . cdr ) ) ) -> val ) == (scheme_null ) ) ) ) ) {
#     define XfOrM764_COUNT (0+XfOrM762_COUNT)
#     define SETUP_XfOrM764(x) SETUP_XfOrM762(x)
      rhs_name = (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (name ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM764(_), scheme_stx_content (name ) )) ) -> u . pair_val . car ) ) ; 
    }
    else {
      rhs_name = scheme_false ; 
    }
    FUNCCALL(SETUP_XfOrM762(_), scheme_init_expand_recs (erec , drec , & erec1 , 1 ) ); 
    erec1 . value_name = rhs_name ; 
    rhs = FUNCCALL(SETUP_XfOrM762(_), scheme_expand_expr (rhs , use_env , & erec1 , 0 ) ); 
    v = (__funcarg72 = (__funcarg73 = FUNCCALL(SETUP_XfOrM762(_), scheme_make_immutable_pair (rhs , scheme_null ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (name , __funcarg73 ) )) , FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg72 , v , v , 0 , 1 ) )) ; 
    v = FUNCCALL_AGAIN(scheme_make_immutable_pair (v , scheme_null ) ); 
    if (! first )
      first = v ; 
    else (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = v ; 
    last = v ; 
    vars = (((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (vars ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM762(_), scheme_stx_content (vars ) )) ) -> u . pair_val . cdr ) ) ; 
  }
  if (! (((vars ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (vars ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vars ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) vars ) -> val ) == (scheme_null ) ) ) ) )
    FUNCCALL(SETUP_XfOrM754(_), scheme_wrong_syntax (((void * ) 0 ) , vars , form , ((void * ) 0 ) ) ); 
  if (! first )
    first = scheme_null ; 
  first = FUNCCALL(SETUP_XfOrM754(_), scheme_datum_to_syntax (first , vs , vs , 0 , 1 ) ); 
  if (erec [drec ] . observer ) {
#   define XfOrM756_COUNT (0+XfOrM754_COUNT)
#   define SETUP_XfOrM756(x) SETUP_XfOrM754(x)
    FUNCCALL(SETUP_XfOrM756(_), scheme_call_expand_observe (erec [drec ] . observer , 13 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  FUNCCALL(SETUP_XfOrM754(_), scheme_init_expand_recs (erec , drec , & erec1 , 1 ) ); 
  erec1 . value_name = erec [drec ] . value_name ; 
  body = FUNCCALL(SETUP_XfOrM754(_), scheme_expand_block (body , env , & erec1 , 0 ) ); 
  v = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM754(_), scheme_stx_content (form ) )) ) -> u . pair_val . car ) ) ; 
  v = (__funcarg69 = FUNCCALL(SETUP_XfOrM754(_), scheme_make_immutable_pair (first , body ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (v , __funcarg69 ) )) ; 
  v = FUNCCALL_AGAIN(scheme_datum_to_syntax (v , form , form , 0 , 2 ) ); 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * let_values_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(erec, 0), PUSH(env, 1), PUSH(form, 2)));
# define XfOrM786_COUNT (3)
# define SETUP_XfOrM786(x) SETUP(XfOrM786_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (erec [drec ] . observer ) {
#   define XfOrM788_COUNT (0+XfOrM786_COUNT)
#   define SETUP_XfOrM788(x) SETUP_XfOrM786(x)
    FUNCCALL(SETUP_XfOrM788(_), scheme_call_expand_observe (erec [drec ] . observer , 112 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(do_let_expand (form , env , erec , drec , "let-values" , 0 , 1 , 0 , ((void * ) 0 ) ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * let_star_values_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(erec, 0), PUSH(env, 1), PUSH(form, 2)));
# define XfOrM789_COUNT (3)
# define SETUP_XfOrM789(x) SETUP(XfOrM789_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (erec [drec ] . observer ) {
#   define XfOrM791_COUNT (0+XfOrM789_COUNT)
#   define SETUP_XfOrM791(x) SETUP_XfOrM789(x)
    FUNCCALL(SETUP_XfOrM791(_), scheme_call_expand_observe (erec [drec ] . observer , 124 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(do_let_expand (form , env , erec , drec , "let*-values" , 0 , 1 , 1 , ((void * ) 0 ) ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * letrec_values_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(erec, 0), PUSH(env, 1), PUSH(form, 2)));
# define XfOrM792_COUNT (3)
# define SETUP_XfOrM792(x) SETUP(XfOrM792_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (erec [drec ] . observer ) {
#   define XfOrM794_COUNT (0+XfOrM792_COUNT)
#   define SETUP_XfOrM794(x) SETUP_XfOrM792(x)
    FUNCCALL(SETUP_XfOrM794(_), scheme_call_expand_observe (erec [drec ] . observer , 113 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(do_let_expand (form , env , erec , drec , "letrec-values" , 1 , 1 , 0 , ((void * ) 0 ) ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * let_values_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  /* No conversion */
  return gen_let_syntax (form , env , "let-values" , 0 , 0 , 1 , rec , drec , ((void * ) 0 ) ) ; 
}
static Scheme_Object * let_star_values_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  /* No conversion */
  return gen_let_syntax (form , env , "let*-values" , 1 , 0 , 1 , rec , drec , ((void * ) 0 ) ) ; 
}
static Scheme_Object * letrec_values_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  /* No conversion */
  return gen_let_syntax (form , env , "letrec-values" , 0 , 1 , 1 , rec , drec , ((void * ) 0 ) ) ; 
}
Scheme_Object * scheme_compile_sequence (Scheme_Object * forms , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  Scheme_Object * __funcarg88 = NULLED_OUT ; 
  Scheme_Object * __funcarg87 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(forms, 0), PUSH(env, 1), PUSH(rec, 2)));
# define XfOrM798_COUNT (3)
# define SETUP_XfOrM798(x) SETUP(XfOrM798_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) forms ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) forms ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) && ((((((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (forms ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM798(_), scheme_stx_content (forms ) )) ) -> u . pair_val . cdr ) ) ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) ((((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (forms ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM798(_), scheme_stx_content (forms ) )) ) -> u . pair_val . cdr ) ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (forms ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM798(_), scheme_stx_content (forms ) )) ) -> u . pair_val . cdr ) ) ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (forms ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM798(_), scheme_stx_content (forms ) )) ) -> u . pair_val . cdr ) ) ) -> val ) == (scheme_null ) ) ) ) ) {
    Scheme_Object * first , * val ; 
    BLOCK_SETUP((PUSH(val, 0+XfOrM798_COUNT), PUSH(first, 1+XfOrM798_COUNT)));
#   define XfOrM802_COUNT (2+XfOrM798_COUNT)
#   define SETUP_XfOrM802(x) SETUP(XfOrM802_COUNT)
    first = NULLED_OUT ; 
    val = NULLED_OUT ; 
    first = (((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (forms ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM802(_), scheme_stx_content (forms ) )) ) -> u . pair_val . car ) ) ; 
    first = FUNCCALL(SETUP_XfOrM802(_), scheme_check_immediate_macro (first , env , rec , drec , 0 , & val , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
    if (((val ) == (scheme_begin_syntax ) ) && (((Scheme_Type ) (((((long ) (first ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (first ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (first ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (first ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) first ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) first ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
      Scheme_Object * rest ; 
      BLOCK_SETUP((PUSH(rest, 0+XfOrM802_COUNT)));
#     define XfOrM803_COUNT (1+XfOrM802_COUNT)
#     define SETUP_XfOrM803(x) SETUP(XfOrM803_COUNT)
      rest = NULLED_OUT ; 
      rest = (((Scheme_Type ) (((((long ) (first ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (first ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (first ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM803(_), scheme_stx_content (first ) )) ) -> u . pair_val . cdr ) ) ; 
      if (FUNCCALL(SETUP_XfOrM803(_), scheme_stx_proper_list_length (rest ) )> 0 ) {
#       define XfOrM804_COUNT (0+XfOrM803_COUNT)
#       define SETUP_XfOrM804(x) SETUP_XfOrM803(x)
        first = FUNCCALL(SETUP_XfOrM804(_), scheme_datum_to_syntax (rest , first , first , 0 , 2 ) ); 
        RET_VALUE_START (FUNCCALL(SETUP_XfOrM804(_), scheme_compile_sequence (first , env , rec , drec ) )) RET_VALUE_END ; 
      }
    }
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM802(_), scheme_compile_expr (first , env , rec , drec ) )) RET_VALUE_END ; 
  }
  else {
#   define XfOrM799_COUNT (0+XfOrM798_COUNT)
#   define SETUP_XfOrM799(x) SETUP_XfOrM798(x)
    if (FUNCCALL(SETUP_XfOrM799(_), scheme_stx_proper_list_length (forms ) )< 0 ) {
#     define XfOrM801_COUNT (0+XfOrM799_COUNT)
#     define SETUP_XfOrM801(x) SETUP_XfOrM799(x)
      (__funcarg87 = (__funcarg88 = FUNCCALL(SETUP_XfOrM801(_), scheme_make_immutable_pair (begin_symbol , forms ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg88 , forms , forms , 0 , 0 ) )) , FUNCCALL_EMPTY(scheme_wrong_syntax (scheme_begin_stx_string , ((void * ) 0 ) , __funcarg87 , "bad syntax (" "illegal use of `.'" ")" ) )) ; 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else {
      Scheme_Object * body ; 
      BLOCK_SETUP((PUSH(body, 0+XfOrM799_COUNT)));
#     define XfOrM800_COUNT (1+XfOrM799_COUNT)
#     define SETUP_XfOrM800(x) SETUP(XfOrM800_COUNT)
      body = NULLED_OUT ; 
      body = FUNCCALL(SETUP_XfOrM800(_), scheme_compile_block (forms , env , rec , drec ) ); 
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sequence_compilation (body , 1 ) )) RET_VALUE_EMPTY_END ; 
    }
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_compiled_void () {
  /* No conversion */
  return scheme_void ; 
}
static Scheme_Object * begin0_execute (Scheme_Object * obj ) {
  Scheme_Object * v , * * mv ; 
  int i , mc , apos ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(obj, 1), PUSH(mv, 2)));
# define XfOrM806_COUNT (3)
# define SETUP_XfOrM806(x) SETUP(XfOrM806_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  mv = NULLED_OUT ; 
  i = ((Scheme_Sequence * ) obj ) -> count ; 
  v = FUNCCALL(SETUP_XfOrM806(_), scheme_do_eval (((Scheme_Sequence * ) obj ) -> array [0 ] , - 1 , ((void * ) 0 ) , - 1 ) ); 
  i -- ; 
  if (((v ) == (((Scheme_Object * ) 0x6 ) ) ) ) {
    Scheme_Thread * p = scheme_current_thread ; 
    mv = p -> ku . multiple . array ; 
    mc = p -> ku . multiple . count ; 
    if (((mv ) == (p -> values_buffer ) ) )
      p -> values_buffer = ((void * ) 0 ) ; 
  }
  else {
    mv = ((void * ) 0 ) ; 
    mc = 0 ; 
  }
  apos = 1 ; 
  while (i -- ) {
#   define XfOrM809_COUNT (0+XfOrM806_COUNT)
#   define SETUP_XfOrM809(x) SETUP_XfOrM806(x)
    (void ) FUNCCALL(SETUP_XfOrM809(_), scheme_do_eval (((Scheme_Sequence * ) obj ) -> array [apos ++ ] , - 1 , ((void * ) 0 ) , - 1 ) ); 
  }
  if (mv ) {
    Scheme_Thread * p = scheme_current_thread ; 
    p -> ku . multiple . array = mv ; 
    p -> ku . multiple . count = mc ; 
  }
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 4262 */
static Scheme_Object * begin0_jit (Scheme_Object * data ) {
  Scheme_Sequence * seq = (Scheme_Sequence * ) data , * seq2 ; 
  Scheme_Object * old , * naya = ((void * ) 0 ) ; 
  int i , j , count ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(seq2, 0), PUSH(naya, 1), PUSH(data, 2), PUSH(seq, 3), PUSH(old, 4)));
# define XfOrM812_COUNT (5)
# define SETUP_XfOrM812(x) SETUP(XfOrM812_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  seq2 = NULLED_OUT ; 
  old = NULLED_OUT ; 
  count = seq -> count ; 
  for (i = 0 ; i < count ; i ++ ) {
#   define XfOrM818_COUNT (0+XfOrM812_COUNT)
#   define SETUP_XfOrM818(x) SETUP_XfOrM812(x)
    old = seq -> array [i ] ; 
    naya = FUNCCALL(SETUP_XfOrM818(_), scheme_jit_expr (old ) ); 
    if (! ((old ) == (naya ) ) )
      break ; 
  }
  if (i >= count )
    RET_VALUE_START (data ) RET_VALUE_END ; 
  seq2 = (Scheme_Sequence * ) FUNCCALL(SETUP_XfOrM812(_), GC_malloc_one_tagged (sizeof (Scheme_Sequence ) + (count - 1 ) * sizeof (Scheme_Object * ) ) ); 
  seq2 -> so . type = scheme_begin0_sequence_type ; 
  seq2 -> count = count ; 
  for (j = 0 ; j < i ; j ++ ) {
    seq2 -> array [j ] = seq -> array [j ] ; 
  }
  seq2 -> array [i ] = naya ; 
  for (i ++ ; i < count ; i ++ ) {
#   define XfOrM814_COUNT (0+XfOrM812_COUNT)
#   define SETUP_XfOrM814(x) SETUP_XfOrM812(x)
    old = seq -> array [i ] ; 
    naya = FUNCCALL(SETUP_XfOrM814(_), scheme_jit_expr (old ) ); 
    seq2 -> array [i ] = naya ; 
  }
  RET_VALUE_START ((Scheme_Object * ) seq2 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void begin0_validate (Scheme_Object * data , Mz_CPort * port , char * stack , Scheme_Hash_Table * ht , Scheme_Object * * tls , int depth , int letlimit , int delta , int num_toplevels , int num_stxes , int num_lifts ) {
  Scheme_Sequence * seq = (Scheme_Sequence * ) data ; 
  int i ; 
  PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(stack, 0), PUSH(ht, 1), PUSH(seq, 2), PUSH(tls, 3), PUSH(port, 4)));
# define XfOrM819_COUNT (5)
# define SETUP_XfOrM819(x) SETUP(XfOrM819_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  for (i = 0 ; i < seq -> count ; i ++ ) {
#   define XfOrM821_COUNT (0+XfOrM819_COUNT)
#   define SETUP_XfOrM821(x) SETUP_XfOrM819(x)
    FUNCCALL(SETUP_XfOrM821(_), scheme_validate_expr (port , seq -> array [i ] , stack , ht , tls , depth , letlimit , delta , num_toplevels , num_stxes , num_lifts , ((void * ) 0 ) , 0 ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * begin0_optimize (Scheme_Object * obj , Optimize_Info * info ) {
  int i ; 
  PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(obj, 0), PUSH(info, 1)));
# define XfOrM822_COUNT (2)
# define SETUP_XfOrM822(x) SETUP(XfOrM822_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  i = ((Scheme_Sequence * ) obj ) -> count ; 
  while (i -- ) {
    Scheme_Object * le ; 
    BLOCK_SETUP((PUSH(le, 0+XfOrM822_COUNT)));
#   define XfOrM824_COUNT (1+XfOrM822_COUNT)
#   define SETUP_XfOrM824(x) SETUP(XfOrM824_COUNT)
    le = NULLED_OUT ; 
    le = FUNCCALL(SETUP_XfOrM824(_), scheme_optimize_expr (((Scheme_Sequence * ) obj ) -> array [i ] , info ) ); 
    ((Scheme_Sequence * ) obj ) -> array [i ] = le ; 
  }
  info -> preserves_marks = 1 ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_syntax_compiled (4 , obj ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * begin0_clone (int dup_ok , Scheme_Object * obj , Optimize_Info * info , int delta , int closure_depth ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(obj, 0)));
# define XfOrM825_COUNT (1)
# define SETUP_XfOrM825(x) SETUP(XfOrM825_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  obj = FUNCCALL(SETUP_XfOrM825(_), scheme_optimize_clone (dup_ok , obj , info , delta , closure_depth ) ); 
  if (! obj )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_syntax_compiled (4 , obj ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * begin0_shift (Scheme_Object * obj , int delta , int after_depth ) {
  int i ; 
  PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(obj, 0)));
# define XfOrM826_COUNT (1)
# define SETUP_XfOrM826(x) SETUP(XfOrM826_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  i = ((Scheme_Sequence * ) obj ) -> count ; 
  while (i -- ) {
    Scheme_Object * le ; 
    BLOCK_SETUP((PUSH(le, 0+XfOrM826_COUNT)));
#   define XfOrM828_COUNT (1+XfOrM826_COUNT)
#   define SETUP_XfOrM828(x) SETUP(XfOrM828_COUNT)
    le = NULLED_OUT ; 
    le = FUNCCALL(SETUP_XfOrM828(_), scheme_optimize_shift (((Scheme_Sequence * ) obj ) -> array [i ] , delta , after_depth ) ); 
    ((Scheme_Sequence * ) obj ) -> array [i ] = le ; 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_syntax_compiled (4 , obj ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * begin0_resolve (Scheme_Object * obj , Resolve_Info * info ) {
  int i ; 
  PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(obj, 0), PUSH(info, 1)));
# define XfOrM829_COUNT (2)
# define SETUP_XfOrM829(x) SETUP(XfOrM829_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  i = ((Scheme_Sequence * ) obj ) -> count ; 
  while (i -- ) {
    Scheme_Object * le ; 
    BLOCK_SETUP((PUSH(le, 0+XfOrM829_COUNT)));
#   define XfOrM831_COUNT (1+XfOrM829_COUNT)
#   define SETUP_XfOrM831(x) SETUP(XfOrM831_COUNT)
    le = NULLED_OUT ; 
    le = FUNCCALL(SETUP_XfOrM831(_), scheme_resolve_expr (((Scheme_Sequence * ) obj ) -> array [i ] , info ) ); 
    ((Scheme_Sequence * ) obj ) -> array [i ] = le ; 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_syntax_resolved (4 , obj ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_begin_syntax (char * name , Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec , int zero ) {
  Scheme_Object * forms , * body ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(14);
  BLOCK_SETUP_TOP((PUSH(forms, 0), PUSH(env, 1), PUSH(body, 2), PUSH(rec, 3), PUSH(form, 4)));
# define XfOrM832_COUNT (5)
# define SETUP_XfOrM832(x) SETUP(XfOrM832_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  forms = NULLED_OUT ; 
  body = NULLED_OUT ; 
  forms = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM832(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  if ((((forms ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) forms ) -> val ) == (scheme_null ) ) ) ) ) {
#   define XfOrM839_COUNT (0+XfOrM832_COUNT)
#   define SETUP_XfOrM839(x) SETUP_XfOrM832(x)
    if (! zero && FUNCCALL(SETUP_XfOrM839(_), scheme_is_toplevel (env ) ))
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_compiled_void () )) RET_VALUE_EMPTY_END ; 
    FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , form , "bad syntax (empty form)" ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  FUNCCALL(SETUP_XfOrM832(_), check_form (form , form ) ); 
  if (zero )
    env = FUNCCALL(SETUP_XfOrM832(_), scheme_no_defines (env ) ); 
  if (((((((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (forms ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM832(_), scheme_stx_content (forms ) )) ) -> u . pair_val . cdr ) ) ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) ((((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (forms ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM832(_), scheme_stx_content (forms ) )) ) -> u . pair_val . cdr ) ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (forms ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM832(_), scheme_stx_content (forms ) )) ) -> u . pair_val . cdr ) ) ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (forms ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM832(_), scheme_stx_content (forms ) )) ) -> u . pair_val . cdr ) ) ) -> val ) == (scheme_null ) ) ) ) ) {
#   define XfOrM838_COUNT (0+XfOrM832_COUNT)
#   define SETUP_XfOrM838(x) SETUP_XfOrM832(x)
    FUNCCALL(SETUP_XfOrM838(_), scheme_rec_add_certs (rec , drec , form ) ); 
    forms = (((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (forms ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM838(_), scheme_stx_content (forms ) )) ) -> u . pair_val . car ) ) ; 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_compile_expr (forms , env , rec , drec ) )) RET_VALUE_EMPTY_END ; 
  }
  if (! FUNCCALL(SETUP_XfOrM832(_), scheme_is_toplevel (env ) )) {
#   define XfOrM835_COUNT (0+XfOrM832_COUNT)
#   define SETUP_XfOrM835(x) SETUP_XfOrM832(x)
    if (zero ) {
      Scheme_Compile_Info recs [2 ] ; 
      Scheme_Object * first , * rest , * vname ; 
      BLOCK_SETUP((PUSH(recs[0].value_name, 0+XfOrM835_COUNT), PUSH(recs[0].certs, 1+XfOrM835_COUNT), PUSH(recs[0].observer, 2+XfOrM835_COUNT), PUSH(recs[1].value_name, 3+XfOrM835_COUNT), PUSH(recs[1].certs, 4+XfOrM835_COUNT), PUSH(recs[1].observer, 5+XfOrM835_COUNT), PUSH(first, 6+XfOrM835_COUNT), PUSH(rest, 7+XfOrM835_COUNT), PUSH(vname, 8+XfOrM835_COUNT)));
#     define XfOrM837_COUNT (9+XfOrM835_COUNT)
#     define SETUP_XfOrM837(x) SETUP(XfOrM837_COUNT)
      recs[0].value_name = NULLED_OUT ; 
      recs[0].certs = NULLED_OUT ; 
      recs[0].observer = NULLED_OUT ; 
      recs[1].value_name = NULLED_OUT ; 
      recs[1].certs = NULLED_OUT ; 
      recs[1].observer = NULLED_OUT ; 
      first = NULLED_OUT ; 
      rest = NULLED_OUT ; 
      vname = NULLED_OUT ; 
      vname = rec [drec ] . value_name ; 
      FUNCCALL(SETUP_XfOrM837(_), scheme_compile_rec_done_local (rec , drec ) ); 
      vname = FUNCCALL_AGAIN(scheme_check_name_property (form , vname ) ); 
      FUNCCALL_AGAIN(scheme_rec_add_certs (rec , drec , form ) ); 
      FUNCCALL_AGAIN(scheme_init_compile_recs (rec , drec , recs , 2 ) ); 
      recs [0 ] . value_name = vname ; 
      first = (((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (forms ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM837(_), scheme_stx_content (forms ) )) ) -> u . pair_val . car ) ) ; 
      first = FUNCCALL(SETUP_XfOrM837(_), scheme_compile_expr (first , env , recs , 0 ) ); 
      rest = (((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (forms ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM837(_), scheme_stx_content (forms ) )) ) -> u . pair_val . cdr ) ) ; 
      rest = FUNCCALL(SETUP_XfOrM837(_), scheme_compile_list (rest , env , recs , 1 ) ); 
      FUNCCALL_AGAIN(scheme_merge_compile_recs (rec , drec , recs , 2 ) ); 
      body = FUNCCALL_AGAIN(scheme_make_immutable_pair (first , rest ) ); 
    }
    else {
      Scheme_Object * v ; 
      BLOCK_SETUP((PUSH(v, 0+XfOrM835_COUNT)));
#     define XfOrM836_COUNT (1+XfOrM835_COUNT)
#     define SETUP_XfOrM836(x) SETUP(XfOrM836_COUNT)
      v = NULLED_OUT ; 
      v = FUNCCALL(SETUP_XfOrM836(_), scheme_check_name_property (form , rec [drec ] . value_name ) ); 
      rec [drec ] . value_name = v ; 
      FUNCCALL(SETUP_XfOrM836(_), scheme_rec_add_certs (rec , drec , form ) ); 
      body = FUNCCALL_AGAIN(scheme_compile_list (forms , env , rec , drec ) ); 
    }
  }
  else {
#   define XfOrM834_COUNT (0+XfOrM832_COUNT)
#   define SETUP_XfOrM834(x) SETUP_XfOrM832(x)
    FUNCCALL(SETUP_XfOrM834(_), scheme_rec_add_certs (rec , drec , form ) ); 
    body = FUNCCALL(SETUP_XfOrM834(_), scheme_compile_list (forms , env , rec , drec ) ); 
  }
  forms = FUNCCALL(SETUP_XfOrM832(_), scheme_make_sequence_compilation (body , zero ? - 1 : 1 ) ); 
  if (! zero && ((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_sequence_type ) ) && FUNCCALL(SETUP_XfOrM832(_), scheme_is_toplevel (env ) )) {
#   define XfOrM833_COUNT (0+XfOrM832_COUNT)
#   define SETUP_XfOrM833(x) SETUP_XfOrM832(x)
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_syntax_compiled (11 , forms ) )) RET_VALUE_EMPTY_END ; 
  }
  if (! zero || (((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) != (Scheme_Type ) (scheme_begin0_sequence_type ) ) ) )
    RET_VALUE_START (forms ) RET_VALUE_END ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_syntax_compiled (4 , forms ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * begin_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  /* No conversion */
  return do_begin_syntax ("begin" , form , env , rec , drec , 0 ) ; 
}
static Scheme_Object * begin0_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  /* No conversion */
  return do_begin_syntax ("begin0" , form , env , rec , drec , 1 ) ; 
}
static Scheme_Object * do_begin_expand (char * name , Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec , int zero ) {
  Scheme_Object * form_name ; 
  Scheme_Object * rest ; 
  Scheme_Object * orig_form = form ; 
  Scheme_Object * __funcarg91 = NULLED_OUT ; 
  Scheme_Object * __funcarg90 = NULLED_OUT ; 
  Scheme_Object * __funcarg89 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(11);
  BLOCK_SETUP_TOP((PUSH(erec, 0), PUSH(form_name, 1), PUSH(env, 2), PUSH(orig_form, 3), PUSH(form, 4), PUSH(rest, 5)));
# define XfOrM842_COUNT (6)
# define SETUP_XfOrM842(x) SETUP(XfOrM842_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  form_name = NULLED_OUT ; 
  rest = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM842(_), check_form (form , form ) ); 
  form_name = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM842(_), scheme_stx_content (form ) )) ) -> u . pair_val . car ) ) ; 
  rest = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM842(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  if ((((rest ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) rest ) -> val ) == (scheme_null ) ) ) ) ) {
#   define XfOrM851_COUNT (0+XfOrM842_COUNT)
#   define SETUP_XfOrM851(x) SETUP_XfOrM842(x)
    if (! zero && FUNCCALL(SETUP_XfOrM851(_), scheme_is_toplevel (env ) )) {
#     define XfOrM852_COUNT (0+XfOrM851_COUNT)
#     define SETUP_XfOrM852(x) SETUP_XfOrM851(x)
      if (erec [drec ] . observer ) {
#       define XfOrM856_COUNT (0+XfOrM852_COUNT)
#       define SETUP_XfOrM856(x) SETUP_XfOrM852(x)
        FUNCCALL(SETUP_XfOrM856(_), scheme_call_expand_observe (erec [drec ] . observer , 4 , form ) ); 
      }
      else {
      }
      ; 
      if (erec [drec ] . observer ) {
#       define XfOrM854_COUNT (0+XfOrM852_COUNT)
#       define SETUP_XfOrM854(x) SETUP_XfOrM852(x)
        FUNCCALL(SETUP_XfOrM854(_), scheme_call_expand_observe (erec [drec ] . observer , 5 , form ) ); 
      }
      else {
      }
      ; 
      RET_VALUE_START (form ) RET_VALUE_END ; 
    }
    FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , form , "bad syntax (empty form)" ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (zero )
    env = FUNCCALL(SETUP_XfOrM842(_), scheme_no_defines (env ) ); 
  if (! FUNCCALL(SETUP_XfOrM842(_), scheme_is_toplevel (env ) )) {
#   define XfOrM844_COUNT (0+XfOrM842_COUNT)
#   define SETUP_XfOrM844(x) SETUP_XfOrM842(x)
    if (zero ) {
      Scheme_Object * fst , * boundname ; 
      Scheme_Expand_Info erec1 ; 
      BLOCK_SETUP((PUSH(boundname, 0+XfOrM844_COUNT), PUSH(erec1.value_name, 1+XfOrM844_COUNT), PUSH(erec1.certs, 2+XfOrM844_COUNT), PUSH(erec1.observer, 3+XfOrM844_COUNT), PUSH(fst, 4+XfOrM844_COUNT)));
#     define XfOrM846_COUNT (5+XfOrM844_COUNT)
#     define SETUP_XfOrM846(x) SETUP(XfOrM846_COUNT)
      fst = NULLED_OUT ; 
      boundname = NULLED_OUT ; 
      erec1.value_name = NULLED_OUT ; 
      erec1.certs = NULLED_OUT ; 
      erec1.observer = NULLED_OUT ; 
      FUNCCALL(SETUP_XfOrM846(_), scheme_rec_add_certs (erec , drec , form ) ); 
      FUNCCALL_AGAIN(scheme_init_expand_recs (erec , drec , & erec1 , 1 ) ); 
      boundname = FUNCCALL_AGAIN(scheme_check_name_property (form , erec [drec ] . value_name ) ); 
      erec1 . value_name = boundname ; 
      erec [drec ] . value_name = scheme_false ; 
      fst = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM846(_), scheme_stx_content (rest ) )) ) -> u . pair_val . car ) ) ; 
      rest = (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM846(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ; 
      if (erec [drec ] . observer ) {
#       define XfOrM850_COUNT (0+XfOrM846_COUNT)
#       define SETUP_XfOrM850(x) SETUP_XfOrM846(x)
        FUNCCALL(SETUP_XfOrM850(_), scheme_call_expand_observe (erec [drec ] . observer , 3 , ((void * ) 0 ) ) ); 
      }
      else {
      }
      ; 
      fst = FUNCCALL(SETUP_XfOrM846(_), scheme_expand_expr (fst , env , & erec1 , 0 ) ); 
      rest = FUNCCALL_AGAIN(scheme_datum_to_syntax (rest , form , form , 0 , 0 ) ); 
      if (erec [drec ] . observer ) {
#       define XfOrM848_COUNT (0+XfOrM846_COUNT)
#       define SETUP_XfOrM848(x) SETUP_XfOrM846(x)
        FUNCCALL(SETUP_XfOrM848(_), scheme_call_expand_observe (erec [drec ] . observer , 3 , ((void * ) 0 ) ) ); 
      }
      else {
      }
      ; 
      rest = FUNCCALL(SETUP_XfOrM846(_), scheme_expand_list (rest , env , erec , drec ) ); 
      form = FUNCCALL_AGAIN(scheme_make_immutable_pair (fst , rest ) ); 
    }
    else {
      Scheme_Object * boundname ; 
      BLOCK_SETUP((PUSH(boundname, 0+XfOrM844_COUNT)));
#     define XfOrM845_COUNT (1+XfOrM844_COUNT)
#     define SETUP_XfOrM845(x) SETUP(XfOrM845_COUNT)
      boundname = NULLED_OUT ; 
      boundname = FUNCCALL(SETUP_XfOrM845(_), scheme_check_name_property (form , erec [drec ] . value_name ) ); 
      erec [drec ] . value_name = boundname ; 
      FUNCCALL(SETUP_XfOrM845(_), scheme_rec_add_certs (erec , drec , form ) ); 
      form = (__funcarg91 = FUNCCALL(SETUP_XfOrM845(_), scheme_datum_to_syntax (rest , form , form , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_expand_list (__funcarg91 , env , erec , drec ) )) ; 
    }
  }
  else {
#   define XfOrM843_COUNT (0+XfOrM842_COUNT)
#   define SETUP_XfOrM843(x) SETUP_XfOrM842(x)
    FUNCCALL(SETUP_XfOrM843(_), scheme_rec_add_certs (erec , drec , form ) ); 
    form = (__funcarg90 = FUNCCALL(SETUP_XfOrM843(_), scheme_datum_to_syntax (rest , form , form , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_expand_list (__funcarg90 , env , erec , drec ) )) ; 
  }
  RET_VALUE_START ((__funcarg89 = FUNCCALL(SETUP_XfOrM842(_), scheme_make_immutable_pair (form_name , form ) ), FUNCCALL_EMPTY(scheme_datum_to_syntax (__funcarg89 , orig_form , orig_form , 0 , 2 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * begin_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(erec, 0), PUSH(env, 1), PUSH(form, 2)));
# define XfOrM857_COUNT (3)
# define SETUP_XfOrM857(x) SETUP(XfOrM857_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (erec [drec ] . observer ) {
#   define XfOrM859_COUNT (0+XfOrM857_COUNT)
#   define SETUP_XfOrM859(x) SETUP_XfOrM857(x)
    FUNCCALL(SETUP_XfOrM859(_), scheme_call_expand_observe (erec [drec ] . observer , 107 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(do_begin_expand ("begin" , form , env , erec , drec , 0 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * begin0_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(erec, 0), PUSH(env, 1), PUSH(form, 2)));
# define XfOrM860_COUNT (3)
# define SETUP_XfOrM860(x) SETUP(XfOrM860_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (erec [drec ] . observer ) {
#   define XfOrM862_COUNT (0+XfOrM860_COUNT)
#   define SETUP_XfOrM862(x) SETUP_XfOrM860(x)
    FUNCCALL(SETUP_XfOrM862(_), scheme_call_expand_observe (erec [drec ] . observer , 108 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(do_begin_expand ("begin0" , form , env , erec , drec , 1 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * splice_one_expr (void * expr , int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return scheme_do_eval ((Scheme_Object * ) expr , - 1 , ((void * ) 0 ) , - 1 ) ; 
}
static Scheme_Object * splice_execute (Scheme_Object * data ) {
  Scheme_Sequence * seq = (Scheme_Sequence * ) data ; 
  int i , cnt = seq -> count - 1 ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(seq, 0)));
# define XfOrM864_COUNT (1)
# define SETUP_XfOrM864(x) SETUP(XfOrM864_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  for (i = 0 ; i < cnt ; i ++ ) {
#   define XfOrM866_COUNT (0+XfOrM864_COUNT)
#   define SETUP_XfOrM866(x) SETUP_XfOrM864(x)
    (void ) FUNCCALL(SETUP_XfOrM866(_), _scheme_call_with_prompt_multi (splice_one_expr , seq -> array [i ] ) ); 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_do_eval (seq -> array [cnt ] , - 1 , ((void * ) 0 ) , - 1 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * splice_jit (Scheme_Object * data ) {
  /* No conversion */
  return scheme_jit_expr (data ) ; 
}
static Scheme_Object * splice_optimize (Scheme_Object * data , Optimize_Info * info ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(data, 0)));
# define XfOrM868_COUNT (1)
# define SETUP_XfOrM868(x) SETUP(XfOrM868_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  data = FUNCCALL(SETUP_XfOrM868(_), scheme_optimize_expr (data , info ) ); 
  if (((((long ) (data ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (data ) ) -> type ) != scheme_sequence_type )
    RET_VALUE_START (data ) RET_VALUE_END ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_syntax_compiled (11 , data ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * splice_resolve (Scheme_Object * data , Resolve_Info * rslv ) {
  Scheme_Object * __funcarg92 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(0);
# define XfOrM869_COUNT (0)
# define SETUP_XfOrM869(x) SETUP(XfOrM869_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg92 = FUNCCALL_EMPTY(scheme_resolve_expr (data , rslv ) ), FUNCCALL_EMPTY(scheme_make_syntax_resolved (11 , __funcarg92 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * splice_shift (Scheme_Object * data , int delta , int after_depth ) {
  Scheme_Object * __funcarg93 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(0);
# define XfOrM870_COUNT (0)
# define SETUP_XfOrM870(x) SETUP(XfOrM870_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg93 = FUNCCALL_EMPTY(scheme_optimize_shift (data , delta , after_depth ) ), FUNCCALL_EMPTY(scheme_make_syntax_compiled (11 , __funcarg93 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * splice_clone (int dup_ok , Scheme_Object * data , Optimize_Info * info , int delta , int closure_depth ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(data, 0)));
# define XfOrM871_COUNT (1)
# define SETUP_XfOrM871(x) SETUP(XfOrM871_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  data = FUNCCALL(SETUP_XfOrM871(_), scheme_optimize_clone (dup_ok , data , info , delta , closure_depth ) ); 
  if (! data )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_syntax_compiled (11 , data ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void splice_validate (Scheme_Object * data , Mz_CPort * port , char * stack , Scheme_Hash_Table * ht , Scheme_Object * * tls , int depth , int letlimit , int delta , int num_toplevels , int num_stxes , int num_lifts ) {
  /* No conversion */
  scheme_validate_expr (port , data , stack , ht , tls , depth , letlimit , delta , num_toplevels , num_stxes , num_lifts , ((void * ) 0 ) , 0 ) ; 
}
static Scheme_Object * check_single (Scheme_Object * form , Scheme_Comp_Env * top_only ) {
  Scheme_Object * rest ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(top_only, 0), PUSH(rest, 1), PUSH(form, 2)));
# define XfOrM873_COUNT (3)
# define SETUP_XfOrM873(x) SETUP(XfOrM873_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  rest = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM873(_), check_form (form , form ) ); 
  rest = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM873(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  if (! ((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) rest ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) rest ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) && ((((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM873(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) ((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM873(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM873(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM873(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) -> val ) == (scheme_null ) ) ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , form , "bad syntax (wrong number of parts)" ) ); 
  if (top_only && ! FUNCCALL(SETUP_XfOrM873(_), scheme_is_toplevel (top_only ) ))
    FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , form , "illegal use (not at top-level)" ) ); 
  RET_VALUE_START ((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL_EMPTY(scheme_stx_content (rest ) )) ) -> u . pair_val . car ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * single_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec , int top_only ) {
  Scheme_Object * __funcarg94 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(rec, 1), PUSH(form, 2)));
# define XfOrM874_COUNT (3)
# define SETUP_XfOrM874(x) SETUP(XfOrM874_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM874(_), scheme_rec_add_certs (rec , drec , form ) ); 
  RET_VALUE_START ((__funcarg94 = FUNCCALL(SETUP_XfOrM874(_), check_single (form , top_only ? env : ((void * ) 0 ) ) ), FUNCCALL_EMPTY(scheme_compile_expr (__funcarg94 , env , rec , drec ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * single_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec , int top_only , int simplify ) {
  Scheme_Object * expr , * form_name ; 
  Scheme_Object * __funcarg96 = NULLED_OUT ; 
  Scheme_Object * __funcarg95 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(erec, 0), PUSH(env, 1), PUSH(expr, 2), PUSH(form, 3), PUSH(form_name, 4)));
# define XfOrM875_COUNT (5)
# define SETUP_XfOrM875(x) SETUP(XfOrM875_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  expr = NULLED_OUT ; 
  form_name = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM875(_), scheme_rec_add_certs (erec , drec , form ) ); 
  expr = FUNCCALL_AGAIN(check_single (form , top_only ? env : ((void * ) 0 ) ) ); 
  expr = FUNCCALL_AGAIN(scheme_expand_expr (expr , env , erec , drec ) ); 
  form_name = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM875(_), scheme_stx_content (form ) )) ) -> u . pair_val . car ) ) ; 
  if (simplify && (erec [drec ] . depth == - 1 ) ) {
#   define XfOrM876_COUNT (0+XfOrM875_COUNT)
#   define SETUP_XfOrM876(x) SETUP_XfOrM875(x)
    expr = FUNCCALL(SETUP_XfOrM876(_), scheme_stx_track (expr , form , form_name ) ); 
    expr = FUNCCALL(SETUP_XfOrM876(_), scheme_stx_cert (expr , scheme_false , ((void * ) 0 ) , form , ((void * ) 0 ) , 1 ) ); 
    RET_VALUE_START (expr ) RET_VALUE_END ; 
  }
  RET_VALUE_START ((__funcarg95 = (__funcarg96 = FUNCCALL(SETUP_XfOrM875(_), scheme_make_immutable_pair (expr , scheme_null ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (form_name , __funcarg96 ) )) , FUNCCALL_EMPTY(scheme_datum_to_syntax (__funcarg95 , form , form , 0 , 2 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * expression_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  Scheme_Comp_Env * __funcarg97 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(rec, 0), PUSH(form, 1)));
# define XfOrM877_COUNT (2)
# define SETUP_XfOrM877(x) SETUP(XfOrM877_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg97 = FUNCCALL(SETUP_XfOrM877(_), scheme_no_defines (env ) ), FUNCCALL_EMPTY(single_syntax (form , __funcarg97 , rec , drec , 0 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * expression_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  Scheme_Comp_Env * __funcarg98 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(erec, 0), PUSH(env, 1), PUSH(form, 2)));
# define XfOrM878_COUNT (3)
# define SETUP_XfOrM878(x) SETUP(XfOrM878_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (erec [drec ] . observer ) {
#   define XfOrM880_COUNT (0+XfOrM878_COUNT)
#   define SETUP_XfOrM880(x) SETUP_XfOrM878(x)
    FUNCCALL(SETUP_XfOrM880(_), scheme_call_expand_observe (erec [drec ] . observer , 138 , scheme_false ) ); 
  }
  else {
  }
  ; 
  RET_VALUE_START ((__funcarg98 = FUNCCALL(SETUP_XfOrM878(_), scheme_no_defines (env ) ), FUNCCALL_EMPTY(single_expand (form , __funcarg98 , erec , drec , 0 , ! (env -> flags & 1 ) ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * unquote_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  int len ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(form, 0)));
# define XfOrM881_COUNT (1)
# define SETUP_XfOrM881(x) SETUP(XfOrM881_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (rec [drec ] . comp )
    FUNCCALL(SETUP_XfOrM881(_), scheme_compile_rec_done_local (rec , drec ) ); 
  len = FUNCCALL(SETUP_XfOrM881(_), check_form (form , form ) ); 
  if (len != 2 )
    FUNCCALL(SETUP_XfOrM881(_), bad_form (form , len ) ); 
  FUNCCALL_EMPTY(scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , form , "not in quasiquote" ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * unquote_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  /* No conversion */
  return unquote_syntax (form , env , erec , drec ) ; 
}
static Scheme_Object * quote_syntax_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  int len ; 
  Scheme_Object * stx ; 
  Scheme_Object * __funcarg100 = NULLED_OUT ; 
  Scheme_Object * __funcarg99 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(stx, 0), PUSH(env, 1), PUSH(form, 2), PUSH(rec, 3)));
# define XfOrM883_COUNT (4)
# define SETUP_XfOrM883(x) SETUP(XfOrM883_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  stx = NULLED_OUT ; 
  if (rec [drec ] . comp )
    FUNCCALL(SETUP_XfOrM883(_), scheme_compile_rec_done_local (rec , drec ) ); 
  len = FUNCCALL(SETUP_XfOrM883(_), check_form (form , form ) ); 
  if (len != 2 )
    FUNCCALL(SETUP_XfOrM883(_), bad_form (form , len ) ); 
  FUNCCALL(SETUP_XfOrM883(_), scheme_rec_add_certs (rec , drec , form ) ); 
  stx = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM883(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  stx = (((Scheme_Type ) (((((long ) (stx ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (stx ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (stx ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM883(_), scheme_stx_content (stx ) )) ) -> u . pair_val . car ) ) ; 
  stx = FUNCCALL(SETUP_XfOrM883(_), scheme_stx_add_inactive_certs (stx , rec [drec ] . certs ) ); 
  if (rec [drec ] . comp ) {
#   define XfOrM885_COUNT (0+XfOrM883_COUNT)
#   define SETUP_XfOrM885(x) SETUP_XfOrM883(x)
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_register_stx_in_prefix (stx , env , rec , drec ) )) RET_VALUE_EMPTY_END ; 
  }
  else {
    Scheme_Object * fn ; 
    BLOCK_SETUP((PUSH(fn, 0+XfOrM883_COUNT)));
#   define XfOrM884_COUNT (1+XfOrM883_COUNT)
#   define SETUP_XfOrM884(x) SETUP(XfOrM884_COUNT)
    fn = NULLED_OUT ; 
    fn = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM884(_), scheme_stx_content (form ) )) ) -> u . pair_val . car ) ) ; 
    RET_VALUE_START ((__funcarg99 = (__funcarg100 = FUNCCALL(SETUP_XfOrM884(_), scheme_make_immutable_pair (stx , scheme_null ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (fn , __funcarg100 ) )) , FUNCCALL_EMPTY(scheme_datum_to_syntax (__funcarg99 , form , form , 0 , 2 ) )) ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * quote_syntax_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(erec, 0), PUSH(env, 1), PUSH(form, 2)));
# define XfOrM886_COUNT (3)
# define SETUP_XfOrM886(x) SETUP(XfOrM886_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (erec [drec ] . observer ) {
#   define XfOrM888_COUNT (0+XfOrM886_COUNT)
#   define SETUP_XfOrM888(x) SETUP_XfOrM886(x)
    FUNCCALL(SETUP_XfOrM888(_), scheme_call_expand_observe (erec [drec ] . observer , 118 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(quote_syntax_syntax (form , env , erec , drec ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_define_syntaxes_execute (Scheme_Object * expr , Scheme_Env * dm_env , int for_stx ) ; 
static void * define_syntaxes_execute_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * form = p -> ku . k . p1 ; 
  Scheme_Env * dm_env = (Scheme_Env * ) p -> ku . k . p2 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  p -> ku . k . p2 = ((void * ) 0 ) ; 
  return do_define_syntaxes_execute (form , dm_env , p -> ku . k . i1 ) ; 
}
static Scheme_Object * do_define_syntaxes_execute (Scheme_Object * form , Scheme_Env * dm_env , int for_stx ) {
  Scheme_Thread * p = scheme_current_thread ; 
  Resolve_Prefix * rp ; 
  Scheme_Object * base_stack_depth , * dummy ; 
  int depth ; 
  Scheme_Comp_Env * rhs_env ; 
  Scheme_Env * __funcarg101 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(rhs_env, 0), PUSH(dummy, 1), PUSH(dm_env, 2), PUSH(rp, 3), PUSH(form, 4), PUSH(p, 5)));
# define XfOrM890_COUNT (6)
# define SETUP_XfOrM890(x) SETUP(XfOrM890_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  rp = NULLED_OUT ; 
  base_stack_depth = NULLED_OUT ; 
  dummy = NULLED_OUT ; 
  rhs_env = NULLED_OUT ; 
  rp = (Resolve_Prefix * ) (((Scheme_Vector * ) (form ) ) -> els ) [1 ] ; 
  base_stack_depth = (((Scheme_Vector * ) (form ) ) -> els ) [2 ] ; 
  depth = (((long ) (base_stack_depth ) ) >> 1 ) + rp -> num_stxes + 1 ; 
  if (! FUNCCALL(SETUP_XfOrM890(_), scheme_check_runstack (depth ) )) {
#   define XfOrM891_COUNT (0+XfOrM890_COUNT)
#   define SETUP_XfOrM891(x) SETUP_XfOrM890(x)
    p -> ku . k . p1 = form ; 
    if (! dm_env ) {
#     define XfOrM892_COUNT (0+XfOrM891_COUNT)
#     define SETUP_XfOrM892(x) SETUP_XfOrM891(x)
      dummy = (((Scheme_Vector * ) (form ) ) -> els ) [3 ] ; 
      dm_env = FUNCCALL(SETUP_XfOrM892(_), scheme_environment_from_dummy (dummy ) ); 
    }
    p -> ku . k . p2 = (Scheme_Object * ) dm_env ; 
    p -> ku . k . i1 = for_stx ; 
    RET_VALUE_START ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM891(_), scheme_enlarge_runstack (depth , define_syntaxes_execute_k ) )) RET_VALUE_END ; 
  }
  dummy = (((Scheme_Vector * ) (form ) ) -> els ) [3 ] ; 
  rhs_env = (__funcarg101 = FUNCCALL(SETUP_XfOrM890(_), scheme_get_env (((void * ) 0 ) ) ), FUNCCALL_AGAIN(scheme_new_comp_env (__funcarg101 , ((void * ) 0 ) , 1 ) )) ; 
  if (! dm_env )
    dm_env = FUNCCALL(SETUP_XfOrM890(_), scheme_environment_from_dummy (dummy ) ); 
  FUNCCALL(SETUP_XfOrM890(_), scheme_on_next_top (rhs_env , ((void * ) 0 ) , scheme_false , ((void * ) 0 ) , dm_env , dm_env -> link_midx ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(define_execute (form , 4 , for_stx ? 2 : 1 , rp , dm_env ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * define_syntaxes_execute (Scheme_Object * form ) {
  /* No conversion */
  return do_define_syntaxes_execute (form , ((void * ) 0 ) , 0 ) ; 
}
static Scheme_Object * define_for_syntaxes_execute (Scheme_Object * form ) {
  /* No conversion */
  return do_define_syntaxes_execute (form , ((void * ) 0 ) , 1 ) ; 
}
static Scheme_Object * do_define_syntaxes_jit (Scheme_Object * expr ) {
  Scheme_Object * naya ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(expr, 0), PUSH(naya, 1)));
# define XfOrM895_COUNT (2)
# define SETUP_XfOrM895(x) SETUP(XfOrM895_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  naya = NULLED_OUT ; 
  naya = FUNCCALL(SETUP_XfOrM895(_), scheme_jit_expr ((((Scheme_Vector * ) (expr ) ) -> els ) [0 ] ) ); 
  if (((naya ) == (expr ) ) )
    RET_VALUE_START (expr ) RET_VALUE_END ; 
  else {
#   define XfOrM896_COUNT (0+XfOrM895_COUNT)
#   define SETUP_XfOrM896(x) SETUP_XfOrM895(x)
    expr = FUNCCALL(SETUP_XfOrM896(_), clone_vector (expr , 0 ) ); 
    (((Scheme_Vector * ) (expr ) ) -> els ) [0 ] = naya ; 
    RET_VALUE_START (expr ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * define_syntaxes_jit (Scheme_Object * expr ) {
  /* No conversion */
  return do_define_syntaxes_jit (expr ) ; 
}
static Scheme_Object * define_for_syntaxes_jit (Scheme_Object * expr ) {
  /* No conversion */
  return do_define_syntaxes_jit (expr ) ; 
}
static void do_define_syntaxes_validate (Scheme_Object * data , Mz_CPort * port , char * stack , Scheme_Hash_Table * ht , Scheme_Object * * tls , int depth , int letlimit , int delta , int num_toplevels , int num_stxes , int num_lifts , int for_stx ) {
  Resolve_Prefix * rp ; 
  Scheme_Object * name , * val , * base_stack_depth , * dummy ; 
  int sdepth ; 
  PREPARE_VAR_STACK_ONCE(10);
  BLOCK_SETUP_TOP((PUSH(val, 0), PUSH(name, 1), PUSH(data, 2), PUSH(stack, 3), PUSH(base_stack_depth, 4), PUSH(dummy, 5), PUSH(tls, 6), PUSH(port, 7), PUSH(ht, 8), PUSH(rp, 9)));
# define XfOrM899_COUNT (10)
# define SETUP_XfOrM899(x) SETUP(XfOrM899_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  rp = NULLED_OUT ; 
  name = NULLED_OUT ; 
  val = NULLED_OUT ; 
  base_stack_depth = NULLED_OUT ; 
  dummy = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (data ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (data ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) || ((((Scheme_Vector * ) (data ) ) -> size ) < 4 ) )
    FUNCCALL(SETUP_XfOrM899(_), scheme_ill_formed (port , "./../src/syntax.c" , 4842 ) ); 
  rp = (Resolve_Prefix * ) (((Scheme_Vector * ) (data ) ) -> els ) [1 ] ; 
  base_stack_depth = (((Scheme_Vector * ) (data ) ) -> els ) [2 ] ; 
  sdepth = (((long ) (base_stack_depth ) ) >> 1 ) ; 
  if (! ((Scheme_Type ) (rp -> so . type ) == (Scheme_Type ) (scheme_resolve_prefix_type ) ) || (sdepth < 0 ) )
    FUNCCALL(SETUP_XfOrM899(_), scheme_ill_formed (port , "./../src/syntax.c" , 4850 ) ); 
  dummy = (((Scheme_Vector * ) (data ) ) -> els ) [3 ] ; 
  if (! for_stx ) {
    int i , size ; 
#   define XfOrM902_COUNT (0+XfOrM899_COUNT)
#   define SETUP_XfOrM902(x) SETUP_XfOrM899(x)
    size = (((Scheme_Vector * ) (data ) ) -> size ) ; 
    for (i = 4 ; i < size ; i ++ ) {
#     define XfOrM905_COUNT (0+XfOrM902_COUNT)
#     define SETUP_XfOrM905(x) SETUP_XfOrM902(x)
      name = (((Scheme_Vector * ) (data ) ) -> els ) [i ] ; 
      if (! ((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
#       define XfOrM906_COUNT (0+XfOrM905_COUNT)
#       define SETUP_XfOrM906(x) SETUP_XfOrM905(x)
        FUNCCALL(SETUP_XfOrM906(_), scheme_ill_formed (port , "./../src/syntax.c" , 4860 ) ); 
      }
    }
  }
  FUNCCALL(SETUP_XfOrM899(_), scheme_validate_toplevel (dummy , port , stack , ht , tls , depth , delta , num_toplevels , num_stxes , num_lifts , 0 ) ); 
  if (! for_stx ) {
#   define XfOrM901_COUNT (0+XfOrM899_COUNT)
#   define SETUP_XfOrM901(x) SETUP_XfOrM899(x)
    FUNCCALL(SETUP_XfOrM901(_), scheme_validate_code (port , (((Scheme_Vector * ) (data ) ) -> els ) [0 ] , ht , sdepth , rp -> num_toplevels , rp -> num_stxes , rp -> num_lifts ) ); 
  }
  else {
#   define XfOrM900_COUNT (0+XfOrM899_COUNT)
#   define SETUP_XfOrM900(x) SETUP_XfOrM899(x)
    val = FUNCCALL(SETUP_XfOrM900(_), clone_vector (data , 3 ) ); 
    (((Scheme_Vector * ) (val ) ) -> els ) [0 ] = (((Scheme_Vector * ) (data ) ) -> els ) [0 ] ; 
    val = FUNCCALL(SETUP_XfOrM900(_), scheme_make_syntax_resolved (0 , val ) ); 
    FUNCCALL_EMPTY(scheme_validate_code (port , val , ht , sdepth , rp -> num_toplevels , rp -> num_stxes , rp -> num_lifts ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void define_syntaxes_validate (Scheme_Object * data , Mz_CPort * port , char * stack , Scheme_Hash_Table * ht , Scheme_Object * * tls , int depth , int letlimit , int delta , int num_toplevels , int num_stxes , int num_lifts ) {
  /* No conversion */
  do_define_syntaxes_validate (data , port , stack , ht , tls , depth , letlimit , delta , num_toplevels , num_stxes , num_lifts , 0 ) ; 
}
static void define_for_syntaxes_validate (Scheme_Object * data , Mz_CPort * port , char * stack , Scheme_Hash_Table * ht , Scheme_Object * * tls , int depth , int letlimit , int delta , int num_toplevels , int num_stxes , int num_lifts ) {
  /* No conversion */
  do_define_syntaxes_validate (data , port , stack , ht , tls , depth , letlimit , delta , num_toplevels , num_stxes , num_lifts , 1 ) ; 
}
static Scheme_Object * do_define_syntaxes_optimize (Scheme_Object * data , Optimize_Info * info , int for_stx ) {
  Scheme_Object * cp , * names , * val , * dummy ; 
  Optimize_Info * einfo ; 
  Scheme_Object * __funcarg104 = NULLED_OUT ; 
  Scheme_Object * __funcarg103 = NULLED_OUT ; 
  Scheme_Object * __funcarg102 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(names, 0), PUSH(dummy, 1), PUSH(einfo, 2), PUSH(val, 3), PUSH(cp, 4)));
# define XfOrM909_COUNT (5)
# define SETUP_XfOrM909(x) SETUP(XfOrM909_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  cp = NULLED_OUT ; 
  names = NULLED_OUT ; 
  val = NULLED_OUT ; 
  dummy = NULLED_OUT ; 
  einfo = NULLED_OUT ; 
  cp = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) ; 
  data = ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ; 
  dummy = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) ; 
  data = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ; 
  names = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) ; 
  val = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ; 
  einfo = FUNCCALL(SETUP_XfOrM909(_), scheme_optimize_info_create () ); 
  val = FUNCCALL_AGAIN(scheme_optimize_expr (val , einfo ) ); 
  RET_VALUE_START ((__funcarg102 = (__funcarg103 = (__funcarg104 = FUNCCALL(SETUP_XfOrM909(_), scheme_make_pair (names , val ) ), FUNCCALL_AGAIN(scheme_make_pair (dummy , __funcarg104 ) )) , FUNCCALL_AGAIN(scheme_make_pair (cp , __funcarg103 ) )) , FUNCCALL_EMPTY(scheme_make_syntax_compiled ((for_stx ? 8 : 1 ) , __funcarg102 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * define_syntaxes_optimize (Scheme_Object * data , Optimize_Info * info ) {
  /* No conversion */
  return do_define_syntaxes_optimize (data , info , 0 ) ; 
}
static Scheme_Object * define_for_syntaxes_optimize (Scheme_Object * data , Optimize_Info * info ) {
  /* No conversion */
  return do_define_syntaxes_optimize (data , info , 1 ) ; 
}
static Scheme_Object * do_define_syntaxes_resolve (Scheme_Object * data , Resolve_Info * info , int for_stx ) {
  Comp_Prefix * cp ; 
  Resolve_Prefix * rp ; 
  Scheme_Object * names , * val , * base_stack_depth , * dummy , * vec ; 
  Resolve_Info * einfo ; 
  int len ; 
  PREPARE_VAR_STACK_ONCE(8);
  BLOCK_SETUP_TOP((PUSH(val, 0), PUSH(base_stack_depth, 1), PUSH(einfo, 2), PUSH(vec, 3), PUSH(names, 4), PUSH(info, 5), PUSH(dummy, 6), PUSH(rp, 7)));
# define XfOrM912_COUNT (8)
# define SETUP_XfOrM912(x) SETUP(XfOrM912_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  cp = NULLED_OUT ; 
  rp = NULLED_OUT ; 
  names = NULLED_OUT ; 
  val = NULLED_OUT ; 
  base_stack_depth = NULLED_OUT ; 
  dummy = NULLED_OUT ; 
  vec = NULLED_OUT ; 
  einfo = NULLED_OUT ; 
  cp = (Comp_Prefix * ) (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) ; 
  data = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ; 
  dummy = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) ; 
  data = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ; 
  names = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . car ) ; 
  val = (((Scheme_Simple_Object * ) (data ) ) -> u . pair_val . cdr ) ; 
  rp = FUNCCALL(SETUP_XfOrM912(_), scheme_resolve_prefix (1 , cp , 1 ) ); 
  dummy = FUNCCALL_AGAIN(scheme_resolve_expr (dummy , info ) ); 
  einfo = FUNCCALL_AGAIN(scheme_resolve_info_create (rp ) ); 
  if (for_stx )
    names = FUNCCALL(SETUP_XfOrM912(_), scheme_resolve_list (names , einfo ) ); 
  val = FUNCCALL(SETUP_XfOrM912(_), scheme_resolve_expr (val , einfo ) ); 
  rp = FUNCCALL_AGAIN(scheme_remap_prefix (rp , einfo ) ); 
  base_stack_depth = ((Scheme_Object * ) (void * ) (long ) ((((long ) (einfo -> max_let_depth ) ) << 1 ) | 0x1 ) ) ; 
  len = FUNCCALL(SETUP_XfOrM912(_), scheme_list_length (names ) ); 
  vec = FUNCCALL_AGAIN(scheme_make_vector (len + 4 , ((void * ) 0 ) ) ); 
  (((Scheme_Vector * ) (vec ) ) -> els ) [0 ] = val ; 
  (((Scheme_Vector * ) (vec ) ) -> els ) [1 ] = (Scheme_Object * ) rp ; 
  (((Scheme_Vector * ) (vec ) ) -> els ) [2 ] = base_stack_depth ; 
  (((Scheme_Vector * ) (vec ) ) -> els ) [3 ] = dummy ; 
  len = 4 ; 
  while (((Scheme_Type ) (((((long ) (names ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (names ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
    (((Scheme_Vector * ) (vec ) ) -> els ) [len ++ ] = (((Scheme_Simple_Object * ) (names ) ) -> u . pair_val . car ) ; 
    names = (((Scheme_Simple_Object * ) (names ) ) -> u . pair_val . cdr ) ; 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_syntax_resolved ((for_stx ? 8 : 1 ) , vec ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * define_syntaxes_resolve (Scheme_Object * data , Resolve_Info * info ) {
  /* No conversion */
  return do_define_syntaxes_resolve (data , info , 0 ) ; 
}
static Scheme_Object * define_for_syntaxes_resolve (Scheme_Object * data , Resolve_Info * info ) {
  /* No conversion */
  return do_define_syntaxes_resolve (data , info , 1 ) ; 
}
static Scheme_Object * stx_val (Scheme_Object * name , Scheme_Object * _env ) {
  /* No conversion */
  Scheme_Env * env = (Scheme_Env * ) _env ; 
  return scheme_tl_id_sym (env , name , ((void * ) 0 ) , 2 ) ; 
}
static Scheme_Object * do_define_syntaxes_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec , int for_stx ) {
  Scheme_Object * names , * code , * dummy ; 
  Scheme_Object * val ; 
  Scheme_Comp_Env * exp_env ; 
  Scheme_Compile_Info rec1 ; 
  Scheme_Object * __funcarg108 = NULLED_OUT ; 
  Scheme_Object * __funcarg107 = NULLED_OUT ; 
  Scheme_Object * __funcarg106 = NULLED_OUT ; 
  Scheme_Object * __funcarg105 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(11);
  BLOCK_SETUP_TOP((PUSH(val, 0), PUSH(exp_env, 1), PUSH(rec1.value_name, 2), PUSH(rec1.certs, 3), PUSH(rec1.observer, 4), PUSH(code, 5), PUSH(rec, 6), PUSH(names, 7), PUSH(dummy, 8), PUSH(env, 9), PUSH(form, 10)));
# define XfOrM918_COUNT (11)
# define SETUP_XfOrM918(x) SETUP(XfOrM918_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  names = NULLED_OUT ; 
  code = NULLED_OUT ; 
  dummy = NULLED_OUT ; 
  val = NULLED_OUT ; 
  exp_env = NULLED_OUT ; 
  rec1.value_name = NULLED_OUT ; 
  rec1.certs = NULLED_OUT ; 
  rec1.observer = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM918(_), scheme_compile_rec_done_local (rec , drec ) ); 
  FUNCCALL_AGAIN(scheme_default_compile_rec (rec , drec ) ); 
  FUNCCALL_AGAIN(scheme_rec_add_certs (rec , drec , form ) ); 
  FUNCCALL_AGAIN(scheme_define_parse (form , & names , & code , 1 , env , 0 ) ); 
  FUNCCALL_AGAIN(scheme_prepare_exp_env (env -> genv ) ); 
  if (! for_stx )
    names = FUNCCALL(SETUP_XfOrM918(_), scheme_named_map_1 (((void * ) 0 ) , stx_val , names , (Scheme_Object * ) env -> genv ) ); 
  exp_env = FUNCCALL(SETUP_XfOrM918(_), scheme_new_comp_env (env -> genv -> exp_env , env -> insp , 0 ) ); 
  dummy = FUNCCALL_AGAIN(scheme_make_environment_dummy (env ) ); 
  rec1 . comp = 1 ; 
  rec1 . dont_mark_local_use = 0 ; 
  rec1 . resolve_module_ids = 0 ; 
  rec1 . value_name = ((void * ) 0 ) ; 
  rec1 . certs = rec [drec ] . certs ; 
  rec1 . observer = ((void * ) 0 ) ; 
  if (for_stx ) {
#   define XfOrM919_COUNT (0+XfOrM918_COUNT)
#   define SETUP_XfOrM919(x) SETUP_XfOrM918(x)
    names = FUNCCALL(SETUP_XfOrM919(_), defn_targets_syntax (names , exp_env , & rec1 , 0 ) ); 
    FUNCCALL(SETUP_XfOrM919(_), scheme_compile_rec_done_local (& rec1 , 0 ) ); 
  }
  val = FUNCCALL(SETUP_XfOrM918(_), scheme_compile_expr_lift_to_let (code , exp_env , & rec1 , 0 ) ); 
  RET_VALUE_START ((__funcarg105 = (__funcarg106 = (__funcarg107 = (__funcarg108 = FUNCCALL(SETUP_XfOrM918(_), scheme_make_pair (names , val ) ), FUNCCALL_AGAIN(scheme_make_pair (dummy , __funcarg108 ) )) , FUNCCALL_AGAIN(scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) , __funcarg107 ) )) , FUNCCALL_AGAIN(scheme_make_pair ((Scheme_Object * ) exp_env -> prefix , __funcarg106 ) )) , FUNCCALL_AGAIN(scheme_make_syntax_compiled ((for_stx ? 8 : 1 ) , __funcarg105 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * define_syntaxes_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  /* No conversion */
  return do_define_syntaxes_syntax (form , env , rec , drec , 0 ) ; 
}
static Scheme_Object * define_for_syntaxes_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  /* No conversion */
  return do_define_syntaxes_syntax (form , env , rec , drec , 1 ) ; 
}
static Scheme_Object * define_syntaxes_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  Scheme_Object * names , * code , * fpart , * fn ; 
  Scheme_Object * __funcarg109 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSH(code, 0), PUSH(env, 1), PUSH(fn, 2), PUSH(erec, 3), PUSH(names, 4), PUSH(form, 5), PUSH(fpart, 6)));
# define XfOrM922_COUNT (7)
# define SETUP_XfOrM922(x) SETUP(XfOrM922_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  names = NULLED_OUT ; 
  code = NULLED_OUT ; 
  fpart = NULLED_OUT ; 
  fn = NULLED_OUT ; 
  if (erec [drec ] . observer ) {
#   define XfOrM924_COUNT (0+XfOrM922_COUNT)
#   define SETUP_XfOrM924(x) SETUP_XfOrM922(x)
    FUNCCALL(SETUP_XfOrM924(_), scheme_call_expand_observe (erec [drec ] . observer , 103 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  FUNCCALL(SETUP_XfOrM922(_), scheme_prepare_exp_env (env -> genv ) ); 
  FUNCCALL_AGAIN(scheme_define_parse (form , & names , & code , 1 , env , 0 ) ); 
  env = FUNCCALL_AGAIN(scheme_new_expand_env (env -> genv -> exp_env , env -> insp , 0 ) ); 
  FUNCCALL_AGAIN(scheme_rec_add_certs (erec , drec , form ) ); 
  erec [drec ] . value_name = names ; 
  fpart = FUNCCALL(SETUP_XfOrM922(_), scheme_expand_expr_lift_to_let (code , env , erec , drec ) ); 
  code = FUNCCALL_AGAIN(scheme_make_immutable_pair (fpart , scheme_null ) ); 
  code = FUNCCALL_AGAIN(scheme_make_immutable_pair (names , code ) ); 
  fn = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM922(_), scheme_stx_content (form ) )) ) -> u . pair_val . car ) ) ; 
  RET_VALUE_START ((__funcarg109 = FUNCCALL(SETUP_XfOrM922(_), scheme_make_immutable_pair (fn , code ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (__funcarg109 , form , form , 0 , 2 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * define_for_syntaxes_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  /* No conversion */
  return define_syntaxes_expand (form , env , erec , drec ) ; 
}
Scheme_Object * scheme_make_environment_dummy (Scheme_Comp_Env * env ) {
  Scheme_Object * dummy ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(dummy, 0), PUSH(env, 1)));
# define XfOrM926_COUNT (2)
# define SETUP_XfOrM926(x) SETUP(XfOrM926_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  dummy = NULLED_OUT ; 
  dummy = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM926(_), scheme_global_bucket (begin_symbol , env -> genv ) ); 
  dummy = FUNCCALL(SETUP_XfOrM926(_), scheme_register_toplevel_in_prefix (dummy , env , ((void * ) 0 ) , 0 ) ); 
  RET_VALUE_START (dummy ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Env * scheme_environment_from_dummy (Scheme_Object * dummy ) {
  /* No conversion */
  Scheme_Object * * toplevels ; 
  Scheme_Bucket_With_Home * b ; 
  toplevels = (Scheme_Object * * ) scheme_current_runstack [(((Scheme_Toplevel * ) (dummy ) ) -> depth ) ] ; 
  b = (Scheme_Bucket_With_Home * ) toplevels [(((Scheme_Toplevel * ) (dummy ) ) -> position ) ] ; 
  return b -> home ; 
}
static void * eval_letmacro_rhs_k (void ) ; 
static Scheme_Object * eval_letmacro_rhs (Scheme_Object * a , Scheme_Comp_Env * rhs_env , int max_let_depth , Resolve_Prefix * rp , int phase , Scheme_Object * certs ) {
  Scheme_Object * * save_runstack ; 
  int depth ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(rhs_env, 0), PUSH(save_runstack, 1), PUSH(rp, 2), PUSH(certs, 3), PUSH(a, 4)));
# define XfOrM928_COUNT (5)
# define SETUP_XfOrM928(x) SETUP(XfOrM928_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  save_runstack = NULLED_OUT ; 
  depth = max_let_depth + FUNCCALL(SETUP_XfOrM928(_), scheme_prefix_depth (rp ) ); 
  if (! FUNCCALL(SETUP_XfOrM928(_), scheme_check_runstack (depth ) )) {
    Scheme_Thread * p = scheme_current_thread ; 
#   define XfOrM931_COUNT (0+XfOrM928_COUNT)
#   define SETUP_XfOrM931(x) SETUP_XfOrM928(x)
    p -> ku . k . p1 = a ; 
    p -> ku . k . p2 = rhs_env ; 
    p -> ku . k . p3 = rp ; 
    p -> ku . k . p4 = certs ; 
    p -> ku . k . i1 = max_let_depth ; 
    p -> ku . k . i2 = phase ; 
    RET_VALUE_START ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM931(_), scheme_enlarge_runstack (depth , eval_letmacro_rhs_k ) )) RET_VALUE_END ; 
  }
  save_runstack = FUNCCALL(SETUP_XfOrM928(_), scheme_push_prefix (((void * ) 0 ) , rp , ((void * ) 0 ) , ((void * ) 0 ) , phase , phase ) ); 
  if (FUNCCALL(SETUP_XfOrM928(_), scheme_omittable_expr (a , 1 ) )) {
#   define XfOrM930_COUNT (0+XfOrM928_COUNT)
#   define SETUP_XfOrM930(x) SETUP_XfOrM928(x)
    a = FUNCCALL(SETUP_XfOrM930(_), scheme_do_eval (a , - 1 , ((void * ) 0 ) , - 1 ) ); 
  }
  else {
#   define XfOrM929_COUNT (0+XfOrM928_COUNT)
#   define SETUP_XfOrM929(x) SETUP_XfOrM928(x)
    FUNCCALL(SETUP_XfOrM929(_), scheme_on_next_top (rhs_env , ((void * ) 0 ) , scheme_false , certs , rhs_env -> genv , rhs_env -> genv -> link_midx ) ); 
    a = FUNCCALL(SETUP_XfOrM929(_), scheme_eval_linked_expr_multi (a ) ); 
  }
  FUNCCALL(SETUP_XfOrM928(_), scheme_pop_prefix (save_runstack ) ); 
  RET_VALUE_START (a ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void * eval_letmacro_rhs_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * a , * certs ; 
  Scheme_Comp_Env * rhs_env ; 
  int max_let_depth , phase ; 
  Resolve_Prefix * rp ; 
  a = (Scheme_Object * ) p -> ku . k . p1 ; 
  rhs_env = (Scheme_Comp_Env * ) p -> ku . k . p2 ; 
  rp = (Resolve_Prefix * ) p -> ku . k . p3 ; 
  certs = (Scheme_Object * ) p -> ku . k . p4 ; 
  max_let_depth = p -> ku . k . i1 ; 
  phase = p -> ku . k . i2 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  p -> ku . k . p2 = ((void * ) 0 ) ; 
  p -> ku . k . p3 = ((void * ) 0 ) ; 
  p -> ku . k . p4 = ((void * ) 0 ) ; 
  return (void * ) eval_letmacro_rhs (a , rhs_env , max_let_depth , rp , phase , certs ) ; 
}
void scheme_bind_syntaxes (const char * where , Scheme_Object * names , Scheme_Object * a , Scheme_Env * exp_env , Scheme_Object * insp , Scheme_Compile_Expand_Info * rec , int drec , Scheme_Comp_Env * stx_env , Scheme_Comp_Env * rhs_env , int * _pos ) {
  Scheme_Object * * results , * l ; 
  Scheme_Comp_Env * eenv ; 
  Scheme_Object * certs ; 
  Resolve_Prefix * rp ; 
  Resolve_Info * ri ; 
  Optimize_Info * oi ; 
  int vc , nc , j , i ; 
  Scheme_Compile_Expand_Info mrec ; 
  PREPARE_VAR_STACK(19);
  BLOCK_SETUP_TOP((PUSH(results, 0), PUSH(stx_env, 1), PUSH(a, 2), PUSH(_pos, 3), PUSH(where, 4), PUSH(mrec.value_name, 5), PUSH(mrec.certs, 6), PUSH(mrec.observer, 7), PUSH(rec, 8), PUSH(ri, 9), PUSH(eenv, 10), PUSH(certs, 11), PUSH(names, 12), PUSH(l, 13), PUSH(oi, 14), PUSH(rhs_env, 15), PUSH(rp, 16)));
# define XfOrM933_COUNT (17)
# define SETUP_XfOrM933(x) SETUP(XfOrM933_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  results = NULLED_OUT ; 
  l = NULLED_OUT ; 
  eenv = NULLED_OUT ; 
  certs = NULLED_OUT ; 
  rp = NULLED_OUT ; 
  ri = NULLED_OUT ; 
  oi = NULLED_OUT ; 
  mrec.value_name = NULLED_OUT ; 
  mrec.certs = NULLED_OUT ; 
  mrec.observer = NULLED_OUT ; 
  certs = rec [drec ] . certs ; 
  eenv = FUNCCALL(SETUP_XfOrM933(_), scheme_new_comp_env (exp_env , insp , 0 ) ); 
  if (! rec [drec ] . comp ) {
#   define XfOrM942_COUNT (0+XfOrM933_COUNT)
#   define SETUP_XfOrM942(x) SETUP_XfOrM933(x)
    FUNCCALL(SETUP_XfOrM942(_), scheme_init_expand_recs (rec , drec , & mrec , 1 ) ); 
    if (mrec . observer ) {
#     define XfOrM944_COUNT (0+XfOrM942_COUNT)
#     define SETUP_XfOrM944(x) SETUP_XfOrM942(x)
      FUNCCALL(SETUP_XfOrM944(_), scheme_call_expand_observe (mrec . observer , 20 , ((void * ) 0 ) ) ); 
    }
    else {
    }
    ; 
    a = FUNCCALL(SETUP_XfOrM942(_), scheme_expand_expr_lift_to_let (a , eenv , & mrec , 0 ) ); 
  }
  mrec . comp = 1 ; 
  mrec . dont_mark_local_use = 0 ; 
  mrec . resolve_module_ids = 1 ; 
  mrec . value_name = ((void * ) 0 ) ; 
  mrec . certs = certs ; 
  mrec . observer = ((void * ) 0 ) ; 
  a = FUNCCALL(SETUP_XfOrM933(_), scheme_compile_expr_lift_to_let (a , eenv , & mrec , 0 ) ); 
  rp = FUNCCALL_AGAIN(scheme_resolve_prefix (eenv -> genv -> phase , eenv -> prefix , 0 ) ); 
  oi = FUNCCALL_AGAIN(scheme_optimize_info_create () ); 
  a = FUNCCALL_AGAIN(scheme_optimize_expr (a , oi ) ); 
  ri = FUNCCALL_AGAIN(scheme_resolve_info_create (rp ) ); 
  a = FUNCCALL_AGAIN(scheme_resolve_expr (a , ri ) ); 
  rp = FUNCCALL_AGAIN(scheme_remap_prefix (rp , ri ) ); 
  a = FUNCCALL_AGAIN(eval_letmacro_rhs (a , rhs_env , ri -> max_let_depth , rp , eenv -> genv -> phase , certs ) ); 
  if (((a ) == (((Scheme_Object * ) 0x6 ) ) ) ) {
    vc = scheme_current_thread -> ku . multiple . count ; 
    results = scheme_current_thread -> ku . multiple . array ; 
    scheme_current_thread -> ku . multiple . array = ((void * ) 0 ) ; 
    if (((results ) == (scheme_current_thread -> values_buffer ) ) )
      scheme_current_thread -> values_buffer = ((void * ) 0 ) ; 
  }
  else {
    vc = 1 ; 
    results = ((void * ) 0 ) ; 
  }
  for (nc = 0 , l = names ; (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) l ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) l ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ; l = (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM933(_), scheme_stx_content (l ) )) ) -> u . pair_val . cdr ) ) ) {
    nc ++ ; 
  }
  if (vc != nc ) {
    Scheme_Object * name ; 
    const char * symname ; 
    BLOCK_SETUP((PUSH(symname, 0+XfOrM933_COUNT), PUSH(name, 1+XfOrM933_COUNT)));
#   define XfOrM936_COUNT (2+XfOrM933_COUNT)
#   define SETUP_XfOrM936(x) SETUP(XfOrM936_COUNT)
    name = NULLED_OUT ; 
    symname = NULLED_OUT ; 
    if (nc >= 1 ) {
#     define XfOrM937_COUNT (0+XfOrM936_COUNT)
#     define SETUP_XfOrM937(x) SETUP_XfOrM936(x)
      name = (((Scheme_Type ) (((((long ) (names ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (names ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (names ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM937(_), scheme_stx_content (names ) )) ) -> u . pair_val . car ) ) ; 
      name = ((Scheme_Stx * ) name ) -> val ; 
    }
    else name = ((void * ) 0 ) ; 
    symname = (name ? FUNCCALL(SETUP_XfOrM936(_), scheme_symbol_name (name ) ): "" ) ; 
    FUNCCALL(SETUP_XfOrM936(_), scheme_wrong_return_arity (where , nc , vc , (vc == 1 ) ? (Scheme_Object * * ) a : results , "%s%s%s" , name ? "defining \"" : "0 names" , symname , name ? ((nc == 1 ) ? "\"" : "\", ..." ) : "" ) ); 
  }
  i = * _pos ; 
  for (j = 0 , l = names ; (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) l ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) l ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ; l = (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM933(_), scheme_stx_content (l ) )) ) -> u . pair_val . cdr ) ) , j ++ ) {
    Scheme_Object * name , * macro ; 
    BLOCK_SETUP((PUSH(macro, 0+XfOrM933_COUNT), PUSH(name, 1+XfOrM933_COUNT)));
#   define XfOrM935_COUNT (2+XfOrM933_COUNT)
#   define SETUP_XfOrM935(x) SETUP(XfOrM935_COUNT)
    name = NULLED_OUT ; 
    macro = NULLED_OUT ; 
    name = (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM935(_), scheme_stx_content (l ) )) ) -> u . pair_val . car ) ) ; 
    macro = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM935(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    macro -> type = scheme_macro_type ; 
    if (vc == 1 )
      (((Scheme_Small_Object * ) (macro ) ) -> u . ptr_val ) = a ; 
    else (((Scheme_Small_Object * ) (macro ) ) -> u . ptr_val ) = results [j ] ; 
    FUNCCALL(SETUP_XfOrM935(_), scheme_set_local_syntax (i ++ , name , macro , stx_env ) ); 
  }
  * _pos = i ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_letrec_syntaxes (const char * where , Scheme_Object * forms , Scheme_Comp_Env * origenv , Scheme_Compile_Info * rec , int drec ) {
  Scheme_Object * form , * bindings , * var_bindings , * body , * v ; 
  Scheme_Object * names_to_disappear ; 
  Scheme_Comp_Env * stx_env , * var_env , * rhs_env ; 
  int cnt , stx_cnt , var_cnt , i , j , depth , saw_var ; 
  DupCheckRecord r ; 
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
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(21);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSHARRAY(r.syms, 5, 1), PUSH(r.ht, 4), PUSH(var_bindings, 5), PUSH(stx_env, 6), PUSH(forms, 7), PUSH(bindings, 8), PUSH(rec, 9), PUSH(rhs_env, 10), PUSH(origenv, 11), PUSH(var_env, 12), PUSH(where, 13), PUSH(names_to_disappear, 14), PUSH(body, 15), PUSH(form, 16)));
# define XfOrM945_COUNT (17)
# define SETUP_XfOrM945(x) SETUP(XfOrM945_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  form = NULLED_OUT ; 
  bindings = NULLED_OUT ; 
  var_bindings = NULLED_OUT ; 
  body = NULLED_OUT ; 
  v = NULLED_OUT ; 
  names_to_disappear = NULLED_OUT ; 
  stx_env = NULLED_OUT ; 
  var_env = NULLED_OUT ; 
  rhs_env = NULLED_OUT ; 
  NULL_OUT_ARRAY (r.syms ) ; 
  r.ht = NULLED_OUT ; 
  form = (((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (forms ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM945(_), scheme_stx_content (forms ) )) ) -> u . pair_val . cdr ) ) ; 
  if (! (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) form ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) form ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
    FUNCCALL(SETUP_XfOrM945(_), scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , forms , ((void * ) 0 ) ) ); 
  bindings = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM945(_), scheme_stx_content (form ) )) ) -> u . pair_val . car ) ) ; 
  form = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM945(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  if (! (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) form ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) form ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
    FUNCCALL(SETUP_XfOrM945(_), scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , forms , ((void * ) 0 ) ) ); 
  var_bindings = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM945(_), scheme_stx_content (form ) )) ) -> u . pair_val . car ) ) ; 
  form = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM945(_), scheme_stx_content (form ) )) ) -> u . pair_val . cdr ) ) ; 
  if (! (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) form ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) form ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
    FUNCCALL(SETUP_XfOrM945(_), scheme_wrong_syntax (((void * ) 0 ) , ((void * ) 0 ) , forms , ((void * ) 0 ) ) ); 
  body = FUNCCALL(SETUP_XfOrM945(_), scheme_datum_to_syntax (form , forms , forms , 0 , 0 ) ); 
  FUNCCALL_AGAIN(scheme_rec_add_certs (rec , drec , forms ) ); 
  stx_env = FUNCCALL_AGAIN(scheme_new_compilation_frame (0 , 0 , origenv , rec [drec ] . certs ) ); 
  rhs_env = stx_env ; 
  if (! (((bindings ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (bindings ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (bindings ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) bindings ) -> val ) == (scheme_null ) ) ) ) && ! (((Scheme_Type ) (((((long ) (bindings ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (bindings ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (bindings ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (bindings ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) bindings ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) bindings ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
#   define XfOrM1036_COUNT (0+XfOrM945_COUNT)
#   define SETUP_XfOrM1036(x) SETUP_XfOrM945(x)
    FUNCCALL(SETUP_XfOrM1036(_), scheme_wrong_syntax (((void * ) 0 ) , bindings , forms , "bad syntax (not a binding sequence)" ) ); 
  }
  else FUNCCALL(SETUP_XfOrM945(_), check_form (bindings , forms ) ); 
  if (! (((var_bindings ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (var_bindings ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var_bindings ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) var_bindings ) -> val ) == (scheme_null ) ) ) ) && ! (((Scheme_Type ) (((((long ) (var_bindings ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var_bindings ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (var_bindings ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (var_bindings ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) var_bindings ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) var_bindings ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
#   define XfOrM1035_COUNT (0+XfOrM945_COUNT)
#   define SETUP_XfOrM1035(x) SETUP_XfOrM945(x)
    FUNCCALL(SETUP_XfOrM1035(_), scheme_wrong_syntax (((void * ) 0 ) , var_bindings , forms , "bad syntax (not a binding sequence)" ) ); 
  }
  else FUNCCALL(SETUP_XfOrM945(_), check_form (var_bindings , forms ) ); 
  cnt = stx_cnt = var_cnt = 0 ; 
  saw_var = 0 ; 
  depth = rec [drec ] . depth ; 
  if (! rec [drec ] . comp && (depth <= 0 ) && (depth > - 2 ) )
    names_to_disappear = scheme_null ; 
  else names_to_disappear = ((void * ) 0 ) ; 
  FUNCCALL(SETUP_XfOrM945(_), scheme_begin_dup_symbol_check (& r , stx_env ) ); 
  for (i = 0 ; i < 2 ; i ++ ) {
#   define XfOrM1020_COUNT (0+XfOrM945_COUNT)
#   define SETUP_XfOrM1020(x) SETUP_XfOrM945(x)
    for (v = (i ? var_bindings : bindings ) ; (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) v ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) v ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ; v = (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1020(_), scheme_stx_content (v ) )) ) -> u . pair_val . cdr ) ) ) {
      Scheme_Object * a , * l ; 
      BLOCK_SETUP((PUSH(a, 0+XfOrM1020_COUNT), PUSH(l, 1+XfOrM1020_COUNT)));
#     define XfOrM1028_COUNT (2+XfOrM1020_COUNT)
#     define SETUP_XfOrM1028(x) SETUP(XfOrM1028_COUNT)
      a = NULLED_OUT ; 
      l = NULLED_OUT ; 
      a = (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1028(_), scheme_stx_content (v ) )) ) -> u . pair_val . car ) ) ; 
      if (! (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) a ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) a ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) || ! (((Scheme_Type ) (((((long ) ((((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1028(_), scheme_stx_content (a ) )) ) -> u . pair_val . cdr ) ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1028(_), scheme_stx_content (a ) )) ) -> u . pair_val . cdr ) ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) ((((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1028(_), scheme_stx_content (a ) )) ) -> u . pair_val . cdr ) ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1028(_), scheme_stx_content (a ) )) ) -> u . pair_val . cdr ) ) ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1028(_), scheme_stx_content (a ) )) ) -> u . pair_val . cdr ) ) ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1028(_), scheme_stx_content (a ) )) ) -> u . pair_val . cdr ) ) ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
        v = ((void * ) 0 ) ; 
      else {
#       define XfOrM1032_COUNT (0+XfOrM1028_COUNT)
#       define SETUP_XfOrM1032(x) SETUP_XfOrM1028(x)
        for (l = (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1032(_), scheme_stx_content (a ) )) ) -> u . pair_val . car ) ) ; (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) l ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) l ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ; l = (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1032(_), scheme_stx_content (l ) )) ) -> u . pair_val . cdr ) ) ) {
#         define XfOrM1034_COUNT (0+XfOrM1032_COUNT)
#         define SETUP_XfOrM1034(x) SETUP_XfOrM1032(x)
          if (! (((Scheme_Type ) (((((long ) ((((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1034(_), scheme_stx_content (l ) )) ) -> u . pair_val . car ) ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1034(_), scheme_stx_content (l ) )) ) -> u . pair_val . car ) ) ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) ((((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1034(_), scheme_stx_content (l ) )) ) -> u . pair_val . car ) ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1034(_), scheme_stx_content (l ) )) ) -> u . pair_val . car ) ) ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1034(_), scheme_stx_content (l ) )) ) -> u . pair_val . car ) ) ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1034(_), scheme_stx_content (l ) )) ) -> u . pair_val . car ) ) ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) )
            break ; 
        }
        if (! (((l ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) l ) -> val ) == (scheme_null ) ) ) ) )
          v = ((void * ) 0 ) ; 
      }
      if (v ) {
        Scheme_Object * rest ; 
        BLOCK_SETUP((PUSH(rest, 0+XfOrM1028_COUNT)));
#       define XfOrM1031_COUNT (1+XfOrM1028_COUNT)
#       define SETUP_XfOrM1031(x) SETUP(XfOrM1031_COUNT)
        rest = NULLED_OUT ; 
        rest = (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1031(_), scheme_stx_content (a ) )) ) -> u . pair_val . cdr ) ) ; 
        if (! ((((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1031(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) ((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1031(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1031(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) (((Scheme_Type ) (((((long ) (rest ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rest ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (rest ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1031(_), scheme_stx_content (rest ) )) ) -> u . pair_val . cdr ) ) ) -> val ) == (scheme_null ) ) ) ) )
          v = ((void * ) 0 ) ; 
      }
      if (! v )
        FUNCCALL(SETUP_XfOrM1028(_), scheme_wrong_syntax (((void * ) 0 ) , a , forms , "bad syntax (binding clause not an identifier sequence and expression)" ) ); 
      for (l = (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1028(_), scheme_stx_content (a ) )) ) -> u . pair_val . car ) ) ; (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) l ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) l ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ; l = (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1028(_), scheme_stx_content (l ) )) ) -> u . pair_val . cdr ) ) ) {
#       define XfOrM1030_COUNT (0+XfOrM1028_COUNT)
#       define SETUP_XfOrM1030(x) SETUP_XfOrM1028(x)
        a = (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1030(_), scheme_stx_content (l ) )) ) -> u . pair_val . car ) ) ; 
        FUNCCALL(SETUP_XfOrM1030(_), scheme_check_identifier (where , a , ((void * ) 0 ) , stx_env , forms ) ); 
        FUNCCALL_AGAIN(scheme_dup_symbol_check (& r , where , a , "binding" , forms ) ); 
        cnt ++ ; 
      }
      if (i )
        saw_var = 1 ; 
    }
    if (! i )
      stx_cnt = cnt ; 
    else var_cnt = cnt - stx_cnt ; 
  }
  FUNCCALL(SETUP_XfOrM945(_), scheme_add_local_syntax (stx_cnt , stx_env ) ); 
  if (saw_var )
    var_env = FUNCCALL(SETUP_XfOrM945(_), scheme_new_compilation_frame (var_cnt , 0 , stx_env , rec [drec ] . certs ) ); 
  else var_env = ((void * ) 0 ) ; 
  for (i = 0 ; i < (var_env ? 2 : 1 ) ; i ++ ) {
#   define XfOrM993_COUNT (0+XfOrM945_COUNT)
#   define SETUP_XfOrM993(x) SETUP_XfOrM945(x)
    cnt = (i ? var_cnt : stx_cnt ) ; 
    if (cnt > 0 ) {
#     define XfOrM994_COUNT (0+XfOrM993_COUNT)
#     define SETUP_XfOrM994(x) SETUP_XfOrM993(x)
      j = 0 ; 
      for (v = (i ? var_bindings : bindings ) ; (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) v ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) v ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ; v = (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM994(_), scheme_stx_content (v ) )) ) -> u . pair_val . cdr ) ) ) {
        Scheme_Object * a , * l ; 
        BLOCK_SETUP((PUSH(a, 0+XfOrM994_COUNT), PUSH(l, 1+XfOrM994_COUNT)));
#       define XfOrM1000_COUNT (2+XfOrM994_COUNT)
#       define SETUP_XfOrM1000(x) SETUP(XfOrM1000_COUNT)
        a = NULLED_OUT ; 
        l = NULLED_OUT ; 
        a = (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1000(_), scheme_stx_content (v ) )) ) -> u . pair_val . car ) ) ; 
        for (l = (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1000(_), scheme_stx_content (a ) )) ) -> u . pair_val . car ) ) ; (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) l ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) l ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ; l = (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1000(_), scheme_stx_content (l ) )) ) -> u . pair_val . cdr ) ) ) {
#         define XfOrM1003_COUNT (0+XfOrM1000_COUNT)
#         define SETUP_XfOrM1003(x) SETUP_XfOrM1000(x)
          a = (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM1003(_), scheme_stx_content (l ) )) ) -> u . pair_val . car ) ) ; 
          if (i ) {
#           define XfOrM1004_COUNT (0+XfOrM1003_COUNT)
#           define SETUP_XfOrM1004(x) SETUP_XfOrM1003(x)
            FUNCCALL(SETUP_XfOrM1004(_), scheme_add_compilation_binding (j ++ , a , var_env ) ); 
          }
          else FUNCCALL(SETUP_XfOrM1003(_), scheme_set_local_syntax (j ++ , a , ((void * ) 0 ) , stx_env ) ); 
        }
      }
    }
  }
  if (names_to_disappear ) {
#   define XfOrM974_COUNT (0+XfOrM945_COUNT)
#   define SETUP_XfOrM974(x) SETUP_XfOrM945(x)
    for (v = bindings ; (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) v ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) v ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ; v = (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM974(_), scheme_stx_content (v ) )) ) -> u . pair_val . cdr ) ) ) {
      Scheme_Object * a , * names ; 
      BLOCK_SETUP((PUSH(names, 0+XfOrM974_COUNT), PUSH(a, 1+XfOrM974_COUNT)));
#     define XfOrM978_COUNT (2+XfOrM974_COUNT)
#     define SETUP_XfOrM978(x) SETUP(XfOrM978_COUNT)
      a = NULLED_OUT ; 
      names = NULLED_OUT ; 
      a = (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM978(_), scheme_stx_content (v ) )) ) -> u . pair_val . car ) ) ; 
      names = (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM978(_), scheme_stx_content (a ) )) ) -> u . pair_val . car ) ) ; 
      while (! (((names ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (names ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (names ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) names ) -> val ) == (scheme_null ) ) ) ) ) {
#       define XfOrM980_COUNT (0+XfOrM978_COUNT)
#       define SETUP_XfOrM980(x) SETUP_XfOrM978(x)
        a = (((Scheme_Type ) (((((long ) (names ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (names ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (names ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM980(_), scheme_stx_content (names ) )) ) -> u . pair_val . car ) ) ; 
        if (names_to_disappear )
          names_to_disappear = FUNCCALL(SETUP_XfOrM980(_), scheme_make_immutable_pair (a , names_to_disappear ) ); 
        names = (((Scheme_Type ) (((((long ) (names ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (names ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (names ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM980(_), scheme_stx_content (names ) )) ) -> u . pair_val . cdr ) ) ; 
      }
    }
  }
  bindings = FUNCCALL(SETUP_XfOrM945(_), scheme_add_env_renames (bindings , stx_env , origenv ) ); 
  if (var_env )
    bindings = FUNCCALL(SETUP_XfOrM945(_), scheme_add_env_renames (bindings , var_env , origenv ) ); 
  if (var_env )
    var_bindings = FUNCCALL(SETUP_XfOrM945(_), scheme_add_env_renames (var_bindings , stx_env , origenv ) ); 
  body = FUNCCALL(SETUP_XfOrM945(_), scheme_add_env_renames (body , stx_env , origenv ) ); 
  if (rec [drec ] . observer ) {
#   define XfOrM973_COUNT (0+XfOrM945_COUNT)
#   define SETUP_XfOrM973(x) SETUP_XfOrM945(x)
    (__funcarg118 = (__funcarg119 = FUNCCALL(SETUP_XfOrM973(_), scheme_make_immutable_pair (var_bindings , body ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (bindings , __funcarg119 ) )) , FUNCCALL_AGAIN(scheme_call_expand_observe (rec [drec ] . observer , 19 , __funcarg118 ) )) ; 
  }
  else {
  }
  ; 
  FUNCCALL(SETUP_XfOrM945(_), scheme_prepare_exp_env (stx_env -> genv ) ); 
  i = 0 ; 
  for (v = bindings ; (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) v ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) v ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ; v = (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM945(_), scheme_stx_content (v ) )) ) -> u . pair_val . cdr ) ) ) {
    Scheme_Object * a , * names ; 
    BLOCK_SETUP((PUSH(names, 0+XfOrM945_COUNT), PUSH(a, 1+XfOrM945_COUNT)));
#   define XfOrM969_COUNT (2+XfOrM945_COUNT)
#   define SETUP_XfOrM969(x) SETUP(XfOrM969_COUNT)
    a = NULLED_OUT ; 
    names = NULLED_OUT ; 
    if (rec [drec ] . observer ) {
#     define XfOrM971_COUNT (0+XfOrM969_COUNT)
#     define SETUP_XfOrM971(x) SETUP_XfOrM969(x)
      FUNCCALL(SETUP_XfOrM971(_), scheme_call_expand_observe (rec [drec ] . observer , 3 , ((void * ) 0 ) ) ); 
    }
    else {
    }
    ; 
    a = (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM969(_), scheme_stx_content (v ) )) ) -> u . pair_val . car ) ) ; 
    names = (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM969(_), scheme_stx_content (a ) )) ) -> u . pair_val . car ) ) ; 
    a = (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM969(_), scheme_stx_content (a ) )) ) -> u . pair_val . cdr ) ) ; 
    a = (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM969(_), scheme_stx_content (a ) )) ) -> u . pair_val . car ) ) ; 
    FUNCCALL(SETUP_XfOrM969(_), scheme_bind_syntaxes (where , names , a , stx_env -> genv -> exp_env , stx_env -> insp , rec , drec , stx_env , rhs_env , & i ) ); 
  }
  if (rec [drec ] . observer ) {
#   define XfOrM965_COUNT (0+XfOrM945_COUNT)
#   define SETUP_XfOrM965(x) SETUP_XfOrM945(x)
    FUNCCALL(SETUP_XfOrM965(_), scheme_call_expand_observe (rec [drec ] . observer , 13 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  if (names_to_disappear ) {
    Scheme_Object * l , * a , * pf = ((void * ) 0 ) , * pl = ((void * ) 0 ) ; 
    BLOCK_SETUP((PUSH(pf, 0+XfOrM945_COUNT), PUSH(a, 1+XfOrM945_COUNT), PUSH(pl, 2+XfOrM945_COUNT), PUSH(l, 3+XfOrM945_COUNT)));
#   define XfOrM957_COUNT (4+XfOrM945_COUNT)
#   define SETUP_XfOrM957(x) SETUP(XfOrM957_COUNT)
    l = NULLED_OUT ; 
    a = NULLED_OUT ; 
    if (origenv -> flags & 256 ) {
#     define XfOrM961_COUNT (0+XfOrM957_COUNT)
#     define SETUP_XfOrM961(x) SETUP_XfOrM957(x)
      for (l = names_to_disappear ; ! ((l ) == (scheme_null ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#       define XfOrM963_COUNT (0+XfOrM961_COUNT)
#       define SETUP_XfOrM963(x) SETUP_XfOrM961(x)
        a = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
        a = FUNCCALL(SETUP_XfOrM963(_), scheme_make_immutable_pair (a , scheme_null ) ); 
        if (pl )
          (((Scheme_Simple_Object * ) (pl ) ) -> u . pair_val . cdr ) = a ; 
        else pf = a ; 
        pl = a ; 
      }
    }
    for (l = names_to_disappear ; ! ((l ) == (scheme_null ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#     define XfOrM960_COUNT (0+XfOrM957_COUNT)
#     define SETUP_XfOrM960(x) SETUP_XfOrM957(x)
      a = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
      a = FUNCCALL(SETUP_XfOrM960(_), scheme_add_env_renames (a , stx_env , origenv ) ); 
      (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) = a ; 
    }
    if (pf ) {
      (((Scheme_Simple_Object * ) (pl ) ) -> u . pair_val . cdr ) = names_to_disappear ; 
      names_to_disappear = pf ; 
    }
  }
  if (! var_env ) {
#   define XfOrM952_COUNT (0+XfOrM945_COUNT)
#   define SETUP_XfOrM952(x) SETUP_XfOrM945(x)
    var_env = FUNCCALL(SETUP_XfOrM952(_), scheme_require_renames (stx_env ) ); 
    if (rec [drec ] . comp ) {
#     define XfOrM956_COUNT (0+XfOrM952_COUNT)
#     define SETUP_XfOrM956(x) SETUP_XfOrM952(x)
      v = FUNCCALL(SETUP_XfOrM956(_), scheme_check_name_property (forms , rec [drec ] . value_name ) ); 
      rec [drec ] . value_name = v ; 
      v = FUNCCALL(SETUP_XfOrM956(_), scheme_compile_block (body , var_env , rec , drec ) ); 
      v = FUNCCALL_AGAIN(scheme_make_sequence_compilation (v , 1 ) ); 
    }
    else {
#     define XfOrM953_COUNT (0+XfOrM952_COUNT)
#     define SETUP_XfOrM953(x) SETUP_XfOrM952(x)
      v = FUNCCALL(SETUP_XfOrM953(_), scheme_expand_block (body , var_env , rec , drec ) ); 
      if ((depth >= 0 ) || (depth == - 2 ) ) {
        Scheme_Object * formname ; 
        BLOCK_SETUP((PUSH(formname, 0+XfOrM953_COUNT)));
#       define XfOrM955_COUNT (1+XfOrM953_COUNT)
#       define SETUP_XfOrM955(x) SETUP(XfOrM955_COUNT)
        formname = NULLED_OUT ; 
        formname = (((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (forms ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM955(_), scheme_stx_content (forms ) )) ) -> u . pair_val . car ) ) ; 
        v = (__funcarg116 = (__funcarg117 = FUNCCALL(SETUP_XfOrM955(_), scheme_make_immutable_pair (var_bindings , v ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (bindings , __funcarg117 ) )) , FUNCCALL_AGAIN(scheme_make_immutable_pair (formname , __funcarg116 ) )) ; 
      }
      else {
#       define XfOrM954_COUNT (0+XfOrM953_COUNT)
#       define SETUP_XfOrM954(x) SETUP_XfOrM953(x)
        v = (__funcarg115 = FUNCCALL(SETUP_XfOrM954(_), scheme_make_immutable_pair (scheme_null , v ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (let_values_symbol , __funcarg115 ) )) ; 
      }
      if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
        v = (__funcarg114 = FUNCCALL(SETUP_XfOrM953(_), scheme_sys_wraps (origenv ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (v , forms , __funcarg114 , 0 , 2 ) )) ; 
    }
  }
  else {
#   define XfOrM946_COUNT (0+XfOrM945_COUNT)
#   define SETUP_XfOrM946(x) SETUP_XfOrM945(x)
    v = (__funcarg113 = FUNCCALL(SETUP_XfOrM946(_), scheme_make_immutable_pair (var_bindings , body ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (letrec_values_symbol , __funcarg113 ) )) ; 
    v = (__funcarg112 = FUNCCALL(SETUP_XfOrM946(_), scheme_sys_wraps (origenv ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (v , forms , __funcarg112 , 0 , 2 ) )) ; 
    if (rec [drec ] . comp ) {
#     define XfOrM951_COUNT (0+XfOrM946_COUNT)
#     define SETUP_XfOrM951(x) SETUP_XfOrM946(x)
      v = FUNCCALL(SETUP_XfOrM951(_), gen_let_syntax (v , stx_env , "letrec-values" , 0 , 1 , 1 , rec , drec , var_env ) ); 
    }
    else {
#     define XfOrM947_COUNT (0+XfOrM946_COUNT)
#     define SETUP_XfOrM947(x) SETUP_XfOrM946(x)
      if (rec [drec ] . observer ) {
#       define XfOrM950_COUNT (0+XfOrM947_COUNT)
#       define SETUP_XfOrM950(x) SETUP_XfOrM947(x)
        FUNCCALL(SETUP_XfOrM950(_), scheme_call_expand_observe (rec [drec ] . observer , 113 , ((void * ) 0 ) ) ); 
      }
      else {
      }
      ; 
      v = FUNCCALL(SETUP_XfOrM947(_), do_let_expand (v , stx_env , rec , drec , "letrec-values" , 1 , 1 , 0 , var_env ) ); 
      if ((depth >= 0 ) || (depth == - 2 ) ) {
        Scheme_Object * formname ; 
        BLOCK_SETUP((PUSH(formname, 0+XfOrM947_COUNT)));
#       define XfOrM948_COUNT (1+XfOrM947_COUNT)
#       define SETUP_XfOrM948(x) SETUP(XfOrM948_COUNT)
        formname = NULLED_OUT ; 
        formname = (((Scheme_Type ) (((((long ) (forms ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (forms ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (forms ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM948(_), scheme_stx_content (forms ) )) ) -> u . pair_val . car ) ) ; 
        v = (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM948(_), scheme_stx_content (v ) )) ) -> u . pair_val . cdr ) ) ; 
        v = (__funcarg111 = FUNCCALL(SETUP_XfOrM948(_), scheme_make_immutable_pair (bindings , v ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (formname , __funcarg111 ) )) ; 
        v = (__funcarg110 = FUNCCALL(SETUP_XfOrM948(_), scheme_sys_wraps (origenv ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (v , forms , __funcarg110 , 0 , 2 ) )) ; 
      }
    }
  }
  if (names_to_disappear )
    v = FUNCCALL(SETUP_XfOrM945(_), scheme_stx_property (v , disappeared_binding_symbol , names_to_disappear ) ); 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * letrec_syntaxes_syntax (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Compile_Info * rec , int drec ) {
  /* No conversion */
  return do_letrec_syntaxes ("letrec-syntaxes+values" , form , env , rec , drec ) ; 
}
static Scheme_Object * letrec_syntaxes_expand (Scheme_Object * form , Scheme_Comp_Env * env , Scheme_Expand_Info * erec , int drec ) {
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(erec, 0), PUSH(env, 1), PUSH(form, 2)));
# define XfOrM1038_COUNT (3)
# define SETUP_XfOrM1038(x) SETUP(XfOrM1038_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (erec [drec ] . observer ) {
#   define XfOrM1040_COUNT (0+XfOrM1038_COUNT)
#   define SETUP_XfOrM1040(x) SETUP_XfOrM1038(x)
    FUNCCALL(SETUP_XfOrM1040(_), scheme_call_expand_observe (erec [drec ] . observer , 114 , ((void * ) 0 ) ) ); 
  }
  else {
  }
  ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(do_letrec_syntaxes ("letrec-syntaxes+values" , form , env , erec , drec ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * write_let_value (Scheme_Object * obj ) {
  Scheme_Let_Value * lv ; 
  Scheme_Object * __funcarg124 = NULLED_OUT ; 
  Scheme_Object * __funcarg123 = NULLED_OUT ; 
  Scheme_Object * __funcarg122 = NULLED_OUT ; 
  Scheme_Object * __funcarg121 = NULLED_OUT ; 
  Scheme_Object * __funcarg120 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(__funcarg123, 0), PUSH(lv, 1)));
# define XfOrM1041_COUNT (2)
# define SETUP_XfOrM1041(x) SETUP(XfOrM1041_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  lv = NULLED_OUT ; 
  lv = (Scheme_Let_Value * ) obj ; 
  RET_VALUE_START ((__funcarg120 = (__funcarg121 = (__funcarg122 = (__funcarg123 = FUNCCALL(SETUP_XfOrM1041(_), scheme_protect_quote (lv -> value ) ), __funcarg124 = FUNCCALL(SETUP_XfOrM1041(_), scheme_protect_quote (lv -> body ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg123 , __funcarg124 ) )) , FUNCCALL_AGAIN(scheme_make_pair ((& lv -> iso ) -> so . keyex ? scheme_true : scheme_false , __funcarg122 ) )) , FUNCCALL_AGAIN(scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (lv -> position ) ) << 1 ) | 0x1 ) ) , __funcarg121 ) )) , FUNCCALL_AGAIN(scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (lv -> count ) ) << 1 ) | 0x1 ) ) , __funcarg120 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * read_let_value (Scheme_Object * obj ) {
  Scheme_Let_Value * lv ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(obj, 0), PUSH(lv, 1)));
# define XfOrM1042_COUNT (2)
# define SETUP_XfOrM1042(x) SETUP(XfOrM1042_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  lv = NULLED_OUT ; 
  lv = (Scheme_Let_Value * ) FUNCCALL(SETUP_XfOrM1042(_), GC_malloc_one_tagged (sizeof (Scheme_Let_Value ) ) ); 
  lv -> iso . so . type = scheme_let_value_type ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  lv -> count = (((long ) ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ) ) >> 1 ) ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  lv -> position = (((long ) ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ) ) >> 1 ) ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  (& lv -> iso ) -> so . keyex = (! ((((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ) ) == (scheme_false ) ) ) ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  lv -> value = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
  lv -> body = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  RET_VALUE_START ((Scheme_Object * ) lv ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * write_let_void (Scheme_Object * obj ) {
  Scheme_Let_Void * lv ; 
  Scheme_Object * __funcarg126 = NULLED_OUT ; 
  Scheme_Object * __funcarg125 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(lv, 0)));
# define XfOrM1043_COUNT (1)
# define SETUP_XfOrM1043(x) SETUP(XfOrM1043_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  lv = NULLED_OUT ; 
  lv = (Scheme_Let_Void * ) obj ; 
  RET_VALUE_START ((__funcarg125 = (__funcarg126 = FUNCCALL(SETUP_XfOrM1043(_), scheme_protect_quote (lv -> body ) ), FUNCCALL_AGAIN(scheme_make_pair ((& lv -> iso ) -> so . keyex ? scheme_true : scheme_false , __funcarg126 ) )) , FUNCCALL_AGAIN(scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (lv -> count ) ) << 1 ) | 0x1 ) ) , __funcarg125 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * read_let_void (Scheme_Object * obj ) {
  Scheme_Let_Void * lv ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(obj, 0), PUSH(lv, 1)));
# define XfOrM1044_COUNT (2)
# define SETUP_XfOrM1044(x) SETUP(XfOrM1044_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  lv = NULLED_OUT ; 
  lv = (Scheme_Let_Void * ) FUNCCALL(SETUP_XfOrM1044(_), GC_malloc_one_tagged (sizeof (Scheme_Let_Void ) ) ); 
  lv -> iso . so . type = scheme_let_void_type ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  lv -> count = (((long ) ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ) ) >> 1 ) ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  (& lv -> iso ) -> so . keyex = (! ((((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ) ) == (scheme_false ) ) ) ; 
  lv -> body = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  RET_VALUE_START ((Scheme_Object * ) lv ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * write_let_one (Scheme_Object * obj ) {
  /* No conversion */
  scheme_signal_error ("let-one writer shouldn't be used" ) ; 
  return ((void * ) 0 ) ; 
}
static Scheme_Object * read_let_one (Scheme_Object * obj ) {
  /* No conversion */
  return ((void * ) 0 ) ; 
}
static Scheme_Object * write_letrec (Scheme_Object * obj ) {
  Scheme_Letrec * lr = (Scheme_Letrec * ) obj ; 
  Scheme_Object * l = scheme_null ; 
  int i = lr -> count ; 
  Scheme_Object * __funcarg130 = NULLED_OUT ; 
  Scheme_Object * __funcarg128 = NULLED_OUT ; 
  Scheme_Object * __funcarg127 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(lr, 0), PUSH(l, 1)));
# define XfOrM1047_COUNT (2)
# define SETUP_XfOrM1047(x) SETUP(XfOrM1047_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  while (i -- ) {
#   define XfOrM1049_COUNT (0+XfOrM1047_COUNT)
#   define SETUP_XfOrM1049(x) SETUP_XfOrM1047(x)
    l = (__funcarg130 = FUNCCALL(SETUP_XfOrM1049(_), scheme_protect_quote (lr -> procs [i ] ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg130 , l ) )) ; 
  }
  RET_VALUE_START ((__funcarg127 = (__funcarg128 = FUNCCALL(SETUP_XfOrM1047(_), scheme_protect_quote (lr -> body ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg128 , l ) )) , FUNCCALL_EMPTY(scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (lr -> count ) ) << 1 ) | 0x1 ) ) , __funcarg127 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * read_letrec (Scheme_Object * obj ) {
  Scheme_Letrec * lr ; 
  int i , c ; 
  Scheme_Object * * sa ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(obj, 0), PUSH(sa, 1), PUSH(lr, 2)));
# define XfOrM1050_COUNT (3)
# define SETUP_XfOrM1050(x) SETUP(XfOrM1050_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  lr = NULLED_OUT ; 
  sa = NULLED_OUT ; 
  lr = ((Scheme_Letrec * ) FUNCCALL(SETUP_XfOrM1050(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Letrec ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  lr -> so . type = scheme_letrec_type ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  c = lr -> count = (((long ) ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ) ) >> 1 ) ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  lr -> body = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  sa = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM1050(_), GC_malloc (sizeof (Scheme_Object * ) * (c ) ) )) ; 
  lr -> procs = sa ; 
  for (i = 0 ; i < c ; i ++ ) {
    if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    lr -> procs [i ] = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
    obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  }
  RET_VALUE_START ((Scheme_Object * ) lr ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * write_top (Scheme_Object * obj ) {
  Scheme_Compilation_Top * top = (Scheme_Compilation_Top * ) obj ; 
  Scheme_Object * __funcarg132 = NULLED_OUT ; 
  Scheme_Object * __funcarg131 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(top, 0)));
# define XfOrM1053_COUNT (1)
# define SETUP_XfOrM1053(x) SETUP(XfOrM1053_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg131 = (__funcarg132 = FUNCCALL(SETUP_XfOrM1053(_), scheme_protect_quote (top -> code ) ), FUNCCALL_AGAIN(scheme_make_pair ((Scheme_Object * ) top -> prefix , __funcarg132 ) )) , FUNCCALL_EMPTY(scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (top -> max_let_depth ) ) << 1 ) | 0x1 ) ) , __funcarg131 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * read_top (Scheme_Object * obj ) {
  Scheme_Compilation_Top * top ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(obj, 0), PUSH(top, 1)));
# define XfOrM1054_COUNT (2)
# define SETUP_XfOrM1054(x) SETUP(XfOrM1054_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  top = NULLED_OUT ; 
  top = ((Scheme_Compilation_Top * ) FUNCCALL(SETUP_XfOrM1054(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Compilation_Top ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  top -> so . type = scheme_compilation_top_type ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  top -> max_let_depth = (((long ) ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ) ) >> 1 ) ; 
  obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  top -> prefix = (Resolve_Prefix * ) (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
  top -> code = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  RET_VALUE_START ((Scheme_Object * ) top ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * write_case_lambda (Scheme_Object * obj ) {
  Scheme_Case_Lambda * cl = (Scheme_Case_Lambda * ) obj ; 
  int i ; 
  Scheme_Object * l ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(l, 0), PUSH(cl, 1)));
# define XfOrM1055_COUNT (2)
# define SETUP_XfOrM1055(x) SETUP(XfOrM1055_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  l = NULLED_OUT ; 
  i = cl -> count ; 
  l = scheme_null ; 
  for (; i -- ; ) {
#   define XfOrM1057_COUNT (0+XfOrM1055_COUNT)
#   define SETUP_XfOrM1057(x) SETUP_XfOrM1055(x)
    l = FUNCCALL(SETUP_XfOrM1057(_), scheme_make_pair (cl -> array [i ] , l ) ); 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_pair ((cl -> name ? cl -> name : scheme_null ) , l ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 5728 */
static Scheme_Object * read_case_lambda (Scheme_Object * obj ) {
  Scheme_Object * s , * a ; 
  int count , i , all_closed = 1 ; 
  Scheme_Case_Lambda * cl ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(cl, 0), PUSH(obj, 1), PUSH(a, 2), PUSH(s, 3)));
# define XfOrM1058_COUNT (4)
# define SETUP_XfOrM1058(x) SETUP(XfOrM1058_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  a = NULLED_OUT ; 
  cl = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  s = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  for (count = 0 ; ((Scheme_Type ) (((((long ) (s ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (s ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; s = (((Scheme_Simple_Object * ) (s ) ) -> u . pair_val . cdr ) ) {
    count ++ ; 
  }
  cl = (Scheme_Case_Lambda * ) FUNCCALL(SETUP_XfOrM1058(_), GC_malloc_one_tagged (sizeof (Scheme_Case_Lambda ) + (count - 1 ) * sizeof (Scheme_Object * ) ) ); 
  cl -> so . type = scheme_case_lambda_sequence_type ; 
  cl -> count = count ; 
  cl -> name = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
  if (((cl -> name ) == (scheme_null ) ) )
    cl -> name = ((void * ) 0 ) ; 
  s = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  for (i = 0 ; i < count ; i ++ , s = (((Scheme_Simple_Object * ) (s ) ) -> u . pair_val . cdr ) ) {
    a = (((Scheme_Simple_Object * ) (s ) ) -> u . pair_val . car ) ; 
    cl -> array [i ] = a ; 
    if (! (! (((long ) (a ) ) & 0x1 ) && ((((a ) -> type ) >= scheme_prim_type ) && (((a ) -> type ) <= scheme_native_closure_type ) ) ) )
      all_closed = 0 ; 
  }
  if (all_closed ) {
#   define XfOrM1059_COUNT (0+XfOrM1058_COUNT)
#   define SETUP_XfOrM1059(x) SETUP_XfOrM1058(x)
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(case_lambda_execute ((Scheme_Object * ) cl ) )) RET_VALUE_EMPTY_END ; 
  }
  RET_VALUE_START ((Scheme_Object * ) cl ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_call_expand_observe (Scheme_Object * obs , int tag , Scheme_Object * obj ) {
  PREPARE_VAR_STACK(3);
# define XfOrM1064_COUNT (0)
# define SETUP_XfOrM1064(x) SETUP(XfOrM1064_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! (! (((long ) (obs ) ) & 0x1 ) && ((((obs ) -> type ) >= scheme_prim_type ) && (((obs ) -> type ) <= scheme_native_closure_type ) ) ) ) {
#   define XfOrM1068_COUNT (0+XfOrM1064_COUNT)
#   define SETUP_XfOrM1068(x) SETUP_XfOrM1064(x)
    FUNCCALL_EMPTY(scheme_signal_error ("internal error: expand-observer should never be non-procedure" ) ); 
  }
  else {
    Scheme_Object * buf [2 ] ; 
    BLOCK_SETUP((PUSHARRAY(buf, 2, 0+XfOrM1064_COUNT)));
#   define XfOrM1065_COUNT (3+XfOrM1064_COUNT)
#   define SETUP_XfOrM1065(x) SETUP(XfOrM1065_COUNT)
    buf[0] = NULLED_OUT ; 
    buf[1] = NULLED_OUT ; 
    buf [0 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (tag ) ) << 1 ) | 0x1 ) ) ; 
    if (obj ) {
      buf [1 ] = obj ; 
    }
    else {
      buf [1 ] = scheme_false ; 
    }
    FUNCCALL(SETUP_XfOrM1065(_), scheme_apply (obs , 2 , buf ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * current_expand_observe (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return scheme_param_config ("current-expand-observe" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_EXPAND_OBSERVE ) ) << 1 ) | 0x1 ) ) , argc , argv , 2 , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ; 
}
Scheme_Object * scheme_get_expand_observe () {
  Scheme_Object * obs ; 
  Scheme_Config * __funcarg133 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(obs, 0)));
# define XfOrM1070_COUNT (1)
# define SETUP_XfOrM1070(x) SETUP(XfOrM1070_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  obs = NULLED_OUT ; 
  obs = (__funcarg133 = FUNCCALL(SETUP_XfOrM1070(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg133 , MZCONFIG_EXPAND_OBSERVE ) )) ; 
  if ((! (((long ) (obs ) ) & 0x1 ) && ((((obs ) -> type ) >= scheme_prim_type ) && (((obs ) -> type ) <= scheme_native_closure_type ) ) ) ) {
    RET_VALUE_START (obs ) RET_VALUE_END ; 
  }
  else {
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_init_expand_observe (Scheme_Env * env ) {
  Scheme_Env * newenv ; 
  Scheme_Object * modname ; 
  Scheme_Object * __funcarg134 = NULLED_OUT ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(modname, 0), PUSH(env, 1), PUSH(newenv, 2)));
# define XfOrM1073_COUNT (3)
# define SETUP_XfOrM1073(x) SETUP(XfOrM1073_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  newenv = NULLED_OUT ; 
  modname = NULLED_OUT ; 
  modname = FUNCCALL(SETUP_XfOrM1073(_), scheme_intern_symbol ("#%expobs" ) ); 
  newenv = FUNCCALL_AGAIN(scheme_primitive_module (modname , env ) ); 
  (__funcarg134 = FUNCCALL(SETUP_XfOrM1073(_), scheme_register_parameter (current_expand_observe , "current-expand-observe" , MZCONFIG_EXPAND_OBSERVE ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-expand-observe" , __funcarg134 , newenv ) )) ; 
  FUNCCALL_EMPTY(scheme_finish_primitive_module (newenv ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void register_traversers (void ) {
}
