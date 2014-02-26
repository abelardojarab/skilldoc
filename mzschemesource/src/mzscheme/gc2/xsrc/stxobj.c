#include "precomp.h"
Scheme_Object * scheme_datum_to_syntax_proc ; 
static Scheme_Object * syntax_p (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * graph_syntax_p (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * syntax_to_datum (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * datum_to_syntax (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * syntax_line (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * syntax_col (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * syntax_pos (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * syntax_span (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * syntax_src (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * syntax_to_list (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * syntax_original_p (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * syntax_property (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * syntax_property_keys (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * syntax_track_origin (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * bound_eq (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * free_eq (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * module_eq (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * module_trans_eq (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * module_templ_eq (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * module_label_eq (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * module_binding (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * module_trans_binding (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * module_templ_binding (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * module_label_binding (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * module_binding_pos (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * module_trans_binding_pos (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * syntax_src_module (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * syntax_recertify (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * lift_inactive_certs (Scheme_Object * o , int as_active ) ; 
static Scheme_Object * source_symbol ; 
static Scheme_Object * share_symbol ; 
static Scheme_Object * origin_symbol ; 
static Scheme_Object * lexical_symbol ; 
static Scheme_Object * protected_symbol ; 
static Scheme_Object * nominal_ipair_cache ; 
static Scheme_Object * mark_id = ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
static Scheme_Object * current_rib_timestamp = ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
static Scheme_Stx_Srcloc * empty_srcloc ; 
static Scheme_Object * empty_simplified ; 
static Scheme_Hash_Table * empty_hash_table ; 
static Scheme_Object * last_phase_shift ; 
static Scheme_Hash_Table * id_marks_ht , * than_id_marks_ht ; 
static Scheme_Object * no_nested_inactive_certs ; 
static void register_traversers (void ) ; 
static int includes_mark (Scheme_Object * wraps , Scheme_Object * mark ) ; 
static void add_all_marks (Scheme_Object * wraps , Scheme_Hash_Table * marks ) ; 
static struct Scheme_Cert * cons_cert (Scheme_Object * mark , Scheme_Object * modidx , Scheme_Object * insp , Scheme_Object * key , struct Scheme_Cert * next_cert ) ; 
static void phase_shift_certs (Scheme_Object * o , Scheme_Object * owner_wraps , int len ) ; 
static void preemptive_chunk (Scheme_Stx * stx ) ; 
typedef struct Module_Renames {
  Scheme_Object so ; 
  char plus_kernel , kind , needs_unmarshal ; 
  long phase ; 
  Scheme_Object * plus_kernel_nominal_source ; 
  Scheme_Hash_Table * ht ; 
  Scheme_Hash_Table * nomarshal_ht ; 
  Scheme_Hash_Table * marked_names ; 
  Scheme_Object * unmarshal_info ; 
}
Module_Renames ; 
typedef struct Scheme_Cert {
  Scheme_Inclhash_Object iso ; 
  Scheme_Object * mark ; 
  Scheme_Object * modidx ; 
  Scheme_Object * insp ; 
  Scheme_Object * key ; 
  Scheme_Object * mapped ; 
  int depth ; 
  struct Scheme_Cert * next ; 
}
Scheme_Cert ; 
static Scheme_Object * stx_activate_certs (Scheme_Object * o , Scheme_Cert * * cp , Scheme_Hash_Table * * ht ) ; 
typedef struct Scheme_Lexical_Rib {
  Scheme_Object so ; 
  Scheme_Object * rename ; 
  Scheme_Object * timestamp ; 
  struct Scheme_Lexical_Rib * next ; 
}
Scheme_Lexical_Rib ; 
static Module_Renames * krn ; 
typedef struct {
  Scheme_Type type ; 
  mzshort len ; 
  Scheme_Object * a [1 ] ; 
}
Wrap_Chunk ; 
typedef struct {
  Scheme_Object * l ; 
  Scheme_Object * a ; 
  int is_limb ; 
  int pos ; 
}
Wrap_Pos ; 
__xform_nongcing__ static void WRAP_POS_SET_FIRST (Wrap_Pos * w ) {
  /* No conversion */
  if (! ((w -> l ) == (scheme_null ) ) ) {
    Scheme_Object * a ; 
    a = (((Scheme_Simple_Object * ) (w -> l ) ) -> u . pair_val . car ) ; 
    if (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) == scheme_wrap_chunk_type ) {
      w -> is_limb = 1 ; 
      w -> pos = 0 ; 
      w -> a = ((Wrap_Chunk * ) a ) -> a [0 ] ; 
    }
    else {
      w -> is_limb = 0 ; 
      w -> a = a ; 
    }
  }
}
__xform_nongcing__ static inline void DO_WRAP_POS_INC (Wrap_Pos * w ) {
  /* No conversion */
  Scheme_Object * a ; 
  if (w -> is_limb && (w -> pos + 1 < ((Wrap_Chunk * ) (((Scheme_Simple_Object * ) (w -> l ) ) -> u . pair_val . car ) ) -> len ) ) {
    a = (((Scheme_Simple_Object * ) (w -> l ) ) -> u . pair_val . car ) ; 
    w -> pos ++ ; 
    w -> a = ((Wrap_Chunk * ) a ) -> a [w -> pos ] ; 
  }
  else {
    w -> l = (((Scheme_Simple_Object * ) (w -> l ) ) -> u . pair_val . cdr ) ; 
    if (! ((w -> l ) == (scheme_null ) ) ) {
      a = (((Scheme_Simple_Object * ) (w -> l ) ) -> u . pair_val . car ) ; 
      if (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) == scheme_wrap_chunk_type ) {
        w -> is_limb = 1 ; 
        w -> pos = 0 ; 
        w -> a = ((Wrap_Chunk * ) a ) -> a [0 ] ; 
      }
      else {
        w -> is_limb = 0 ; 
        w -> a = a ; 
      }
    }
    else w -> is_limb = 0 ; 
  }
}
__xform_nongcing__ static void DO_WRAP_POS_REVINIT (Wrap_Pos * w , Scheme_Object * k ) {
  /* No conversion */
  Scheme_Object * a ; 
  a = (((Scheme_Simple_Object * ) (k ) ) -> u . pair_val . car ) ; 
  if (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) == scheme_wrap_chunk_type ) {
    w -> is_limb = 1 ; 
    w -> l = k ; 
    w -> pos = ((Wrap_Chunk * ) a ) -> len - 1 ; 
    w -> a = ((Wrap_Chunk * ) a ) -> a [w -> pos ] ; 
  }
  else {
    w -> l = k ; 
    w -> a = a ; 
    w -> is_limb = 0 ; 
    w -> pos = 0 ; 
  }
}
void scheme_init_stx (Scheme_Env * env ) {
  Scheme_Object * p ; 
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
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(p, 1)));
# define XfOrM14_COUNT (2)
# define SETUP_XfOrM14(x) SETUP(XfOrM14_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  p = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM14(_), register_traversers () ); 
  p = FUNCCALL_AGAIN(scheme_make_folding_prim (syntax_p , "syntax?" , 1 , 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 16384 ; 
  FUNCCALL(SETUP_XfOrM14(_), scheme_add_global_constant ("syntax?" , p , env ) ); 
  (__funcarg31 = FUNCCALL(SETUP_XfOrM14(_), scheme_make_folding_prim (graph_syntax_p , "syntax-graph?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("syntax-graph?" , __funcarg31 , env ) )) ; 
  (__funcarg30 = FUNCCALL(SETUP_XfOrM14(_), scheme_make_folding_prim (syntax_to_datum , "syntax-object->datum" , 1 , 1 + 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("syntax-object->datum" , __funcarg30 , env ) )) ; 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_datum_to_syntax_proc , sizeof (scheme_datum_to_syntax_proc ) ) ); 
  scheme_datum_to_syntax_proc = FUNCCALL_AGAIN(scheme_make_folding_prim (datum_to_syntax , "datum->syntax-object" , 2 , 5 , 1 ) ); 
  FUNCCALL_AGAIN(scheme_add_global_constant ("datum->syntax-object" , scheme_datum_to_syntax_proc , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_folding_prim (scheme_checked_syntax_e , "syntax-e" , 1 , 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 16384 ; 
  FUNCCALL(SETUP_XfOrM14(_), scheme_add_global_constant ("syntax-e" , p , env ) ); 
  (__funcarg29 = FUNCCALL(SETUP_XfOrM14(_), scheme_make_folding_prim (syntax_line , "syntax-line" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("syntax-line" , __funcarg29 , env ) )) ; 
  (__funcarg28 = FUNCCALL(SETUP_XfOrM14(_), scheme_make_folding_prim (syntax_col , "syntax-column" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("syntax-column" , __funcarg28 , env ) )) ; 
  (__funcarg27 = FUNCCALL(SETUP_XfOrM14(_), scheme_make_folding_prim (syntax_pos , "syntax-position" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("syntax-position" , __funcarg27 , env ) )) ; 
  (__funcarg26 = FUNCCALL(SETUP_XfOrM14(_), scheme_make_folding_prim (syntax_span , "syntax-span" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("syntax-span" , __funcarg26 , env ) )) ; 
  (__funcarg25 = FUNCCALL(SETUP_XfOrM14(_), scheme_make_folding_prim (syntax_src , "syntax-source" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("syntax-source" , __funcarg25 , env ) )) ; 
  (__funcarg24 = FUNCCALL(SETUP_XfOrM14(_), scheme_make_folding_prim (syntax_to_list , "syntax->list" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("syntax->list" , __funcarg24 , env ) )) ; 
  (__funcarg23 = FUNCCALL(SETUP_XfOrM14(_), scheme_make_noncm_prim (syntax_original_p , "syntax-original?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("syntax-original?" , __funcarg23 , env ) )) ; 
  (__funcarg22 = FUNCCALL(SETUP_XfOrM14(_), scheme_make_noncm_prim (syntax_property , "syntax-property" , 2 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("syntax-property" , __funcarg22 , env ) )) ; 
  (__funcarg21 = FUNCCALL(SETUP_XfOrM14(_), scheme_make_noncm_prim (syntax_property_keys , "syntax-property-symbol-keys" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("syntax-property-symbol-keys" , __funcarg21 , env ) )) ; 
  (__funcarg20 = FUNCCALL(SETUP_XfOrM14(_), scheme_make_noncm_prim (syntax_track_origin , "syntax-track-origin" , 3 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("syntax-track-origin" , __funcarg20 , env ) )) ; 
  (__funcarg19 = FUNCCALL(SETUP_XfOrM14(_), scheme_make_noncm_prim (bound_eq , "bound-identifier=?" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("bound-identifier=?" , __funcarg19 , env ) )) ; 
  (__funcarg18 = FUNCCALL(SETUP_XfOrM14(_), scheme_make_noncm_prim (free_eq , "free-identifier=?" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("free-identifier=?" , __funcarg18 , env ) )) ; 
  (__funcarg17 = FUNCCALL(SETUP_XfOrM14(_), scheme_make_noncm_prim (module_eq , "module-identifier=?" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("module-identifier=?" , __funcarg17 , env ) )) ; 
  (__funcarg16 = FUNCCALL(SETUP_XfOrM14(_), scheme_make_noncm_prim (module_trans_eq , "module-transformer-identifier=?" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("module-transformer-identifier=?" , __funcarg16 , env ) )) ; 
  (__funcarg15 = FUNCCALL(SETUP_XfOrM14(_), scheme_make_noncm_prim (module_templ_eq , "module-template-identifier=?" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("module-template-identifier=?" , __funcarg15 , env ) )) ; 
  (__funcarg14 = FUNCCALL(SETUP_XfOrM14(_), scheme_make_noncm_prim (module_label_eq , "module-label-identifier=?" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("module-label-identifier=?" , __funcarg14 , env ) )) ; 
  (__funcarg13 = FUNCCALL(SETUP_XfOrM14(_), scheme_make_noncm_prim (module_binding , "identifier-binding" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("identifier-binding" , __funcarg13 , env ) )) ; 
  (__funcarg12 = FUNCCALL(SETUP_XfOrM14(_), scheme_make_noncm_prim (module_trans_binding , "identifier-transformer-binding" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("identifier-transformer-binding" , __funcarg12 , env ) )) ; 
  (__funcarg11 = FUNCCALL(SETUP_XfOrM14(_), scheme_make_noncm_prim (module_templ_binding , "identifier-template-binding" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("identifier-template-binding" , __funcarg11 , env ) )) ; 
  (__funcarg10 = FUNCCALL(SETUP_XfOrM14(_), scheme_make_noncm_prim (module_label_binding , "identifier-label-binding" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("identifier-label-binding" , __funcarg10 , env ) )) ; 
  (__funcarg9 = FUNCCALL(SETUP_XfOrM14(_), scheme_make_noncm_prim (module_binding_pos , "identifier-binding-export-position" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("identifier-binding-export-position" , __funcarg9 , env ) )) ; 
  (__funcarg8 = FUNCCALL(SETUP_XfOrM14(_), scheme_make_noncm_prim (module_trans_binding_pos , "identifier-transformer-binding-export-position" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("identifier-transformer-binding-export-position" , __funcarg8 , env ) )) ; 
  (__funcarg7 = FUNCCALL(SETUP_XfOrM14(_), scheme_make_folding_prim (syntax_src_module , "syntax-source-module" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("syntax-source-module" , __funcarg7 , env ) )) ; 
  (__funcarg6 = FUNCCALL(SETUP_XfOrM14(_), scheme_make_noncm_prim (syntax_recertify , "syntax-recertify" , 4 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("syntax-recertify" , __funcarg6 , env ) )) ; 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & source_symbol , sizeof (source_symbol ) ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & share_symbol , sizeof (share_symbol ) ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & origin_symbol , sizeof (origin_symbol ) ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & lexical_symbol , sizeof (lexical_symbol ) ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & protected_symbol , sizeof (protected_symbol ) ) ); 
  source_symbol = FUNCCALL_EMPTY(scheme_make_symbol ("source" ) ); 
  share_symbol = FUNCCALL_EMPTY(scheme_make_symbol ("share" ) ); 
  origin_symbol = FUNCCALL_EMPTY(scheme_intern_symbol ("origin" ) ); 
  lexical_symbol = FUNCCALL_EMPTY(scheme_intern_symbol ("lexical" ) ); 
  protected_symbol = FUNCCALL_EMPTY(scheme_intern_symbol ("protected" ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & mark_id , sizeof (mark_id ) ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & empty_srcloc , sizeof (empty_srcloc ) ) ); 
  empty_srcloc = ((Scheme_Stx_Srcloc * ) FUNCCALL_EMPTY(GC_malloc_one_small_tagged ((((sizeof (Scheme_Stx_Srcloc ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  empty_srcloc -> type = scheme_rt_srcloc ; 
  empty_srcloc -> src = scheme_false ; 
  empty_srcloc -> line = - 1 ; 
  empty_srcloc -> col = - 1 ; 
  empty_srcloc -> pos = - 1 ; 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & empty_simplified , sizeof (empty_simplified ) ) ); 
  empty_simplified = FUNCCALL_EMPTY(scheme_make_vector (2 , scheme_false ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & nominal_ipair_cache , sizeof (nominal_ipair_cache ) ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & last_phase_shift , sizeof (last_phase_shift ) ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & empty_hash_table , sizeof (empty_hash_table ) ) ); 
  empty_hash_table = FUNCCALL_EMPTY(scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & id_marks_ht , sizeof (id_marks_ht ) ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & than_id_marks_ht , sizeof (than_id_marks_ht ) ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & no_nested_inactive_certs , sizeof (no_nested_inactive_certs ) ) ); 
  no_nested_inactive_certs = FUNCCALL_EMPTY(scheme_make_raw_pair (((void * ) 0 ) , ((void * ) 0 ) ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_stx (Scheme_Object * val , Scheme_Stx_Srcloc * srcloc , Scheme_Object * props ) {
  Scheme_Stx * stx ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(stx, 0), PUSH(val, 1), PUSH(props, 2), PUSH(srcloc, 3)));
# define XfOrM15_COUNT (4)
# define SETUP_XfOrM15(x) SETUP(XfOrM15_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  stx = NULLED_OUT ; 
  stx = ((Scheme_Stx * ) FUNCCALL(SETUP_XfOrM15(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Stx ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  stx -> iso . so . type = scheme_stx_type ; 
  (& (stx ) -> iso ) -> so . keyex = (((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || ((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) || ((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) ? 0x2 : 0 ; 
  stx -> val = val ; 
  stx -> srcloc = srcloc ; 
  stx -> wraps = scheme_null ; 
  stx -> props = props ; 
  RET_VALUE_START ((Scheme_Object * ) stx ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_stx_w_offset (Scheme_Object * val , long line , long col , long pos , long span , Scheme_Object * src , Scheme_Object * props ) {
  Scheme_Stx_Srcloc * srcloc ; 
  PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(val, 0), PUSH(src, 1), PUSH(props, 2), PUSH(srcloc, 3)));
# define XfOrM16_COUNT (4)
# define SETUP_XfOrM16(x) SETUP(XfOrM16_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  srcloc = NULLED_OUT ; 
  srcloc = ((Scheme_Stx_Srcloc * ) FUNCCALL(SETUP_XfOrM16(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Stx_Srcloc ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  srcloc -> type = scheme_rt_srcloc ; 
  srcloc -> src = src ; 
  srcloc -> line = line ; 
  srcloc -> col = col ; 
  srcloc -> pos = pos ; 
  srcloc -> span = span ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_stx (val , srcloc , props ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_graph_stx (Scheme_Object * stx , long line , long col , long pos ) {
  Scheme_Object * tmp , * key ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(stx, 0), PUSH(tmp, 1), PUSH(key, 2)));
# define XfOrM17_COUNT (3)
# define SETUP_XfOrM17(x) SETUP(XfOrM17_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  tmp = NULLED_OUT ; 
  key = NULLED_OUT ; 
  (& ((Scheme_Stx * ) stx ) -> iso ) -> so . keyex |= 0x1 ; 
  key = FUNCCALL(SETUP_XfOrM17(_), scheme_new_mark () ); 
  tmp = FUNCCALL_AGAIN(scheme_stx_property (stx , share_symbol , key ) ); 
  ((Scheme_Stx * ) stx ) -> props = ((Scheme_Stx * ) tmp ) -> props ; 
  RET_VALUE_START (stx ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_renamed_stx (Scheme_Object * sym , Scheme_Object * rn ) {
  Scheme_Object * stx ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(stx, 0), PUSH(rn, 1)));
# define XfOrM18_COUNT (2)
# define SETUP_XfOrM18(x) SETUP(XfOrM18_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  stx = NULLED_OUT ; 
  stx = FUNCCALL(SETUP_XfOrM18(_), scheme_make_stx (sym , empty_srcloc , ((void * ) 0 ) ) ); 
  if (rn ) {
#   define XfOrM19_COUNT (0+XfOrM18_COUNT)
#   define SETUP_XfOrM19(x) SETUP_XfOrM18(x)
    rn = FUNCCALL(SETUP_XfOrM19(_), scheme_make_pair (rn , scheme_null ) ); 
    ((Scheme_Stx * ) stx ) -> wraps = rn ; 
  }
  RET_VALUE_START (stx ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_stx_track (Scheme_Object * naya , Scheme_Object * old , Scheme_Object * origin ) {
  Scheme_Stx * nstx = (Scheme_Stx * ) naya ; 
  Scheme_Stx * ostx = (Scheme_Stx * ) old ; 
  Scheme_Object * ne , * oe , * e1 , * e2 ; 
  Scheme_Object * certs ; 
  Scheme_Object * wraps , * modinfo_cache ; 
  long lazy_prefix ; 
  int graph ; 
  Scheme_Object * __funcarg44 = NULLED_OUT ; 
  Scheme_Object * __funcarg43 = NULLED_OUT ; 
  Scheme_Object * __funcarg42 = NULLED_OUT ; 
  Scheme_Object * __funcarg39 = NULLED_OUT ; 
  Scheme_Object * __funcarg38 = NULLED_OUT ; 
  Scheme_Object * __funcarg37 = NULLED_OUT ; 
  Scheme_Object * __funcarg36 = NULLED_OUT ; 
  Scheme_Object * __funcarg35 = NULLED_OUT ; 
  Scheme_Object * __funcarg33 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(15);
  BLOCK_SETUP_TOP((PUSH(origin, 0), PUSH(e2, 1), PUSH(e1, 2), PUSH(nstx, 3), PUSH(oe, 4), PUSH(certs, 5), PUSH(ostx, 6), PUSH(modinfo_cache, 7), PUSH(wraps, 8), PUSH(ne, 9)));
# define XfOrM20_COUNT (10)
# define SETUP_XfOrM20(x) SETUP(XfOrM20_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  ne = NULLED_OUT ; 
  oe = NULLED_OUT ; 
  e1 = NULLED_OUT ; 
  e2 = NULLED_OUT ; 
  certs = NULLED_OUT ; 
  wraps = NULLED_OUT ; 
  modinfo_cache = NULLED_OUT ; 
  if (nstx -> props ) {
#   define XfOrM73_COUNT (0+XfOrM20_COUNT)
#   define SETUP_XfOrM73(x) SETUP_XfOrM20(x)
    if (((nstx -> props ) == (scheme_false ) ) ) {
#     define XfOrM74_COUNT (0+XfOrM73_COUNT)
#     define SETUP_XfOrM74(x) SETUP_XfOrM73(x)
      ne = (__funcarg44 = FUNCCALL(SETUP_XfOrM74(_), scheme_make_immutable_pair (source_symbol , scheme_true ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (__funcarg44 , scheme_null ) )) ; 
    }
    else ne = nstx -> props ; 
  }
  else ne = scheme_null ; 
  if (ostx -> props ) {
#   define XfOrM58_COUNT (0+XfOrM20_COUNT)
#   define SETUP_XfOrM58(x) SETUP_XfOrM20(x)
    if (((ostx -> props ) == (scheme_false ) ) ) {
      oe = ((void * ) 0 ) ; 
    }
    else {
      Scheme_Object * p , * a ; 
      int mod = 0 , add = 1 ; 
      BLOCK_SETUP((PUSH(a, 0+XfOrM58_COUNT), PUSH(p, 1+XfOrM58_COUNT)));
#     define XfOrM59_COUNT (2+XfOrM58_COUNT)
#     define SETUP_XfOrM59(x) SETUP(XfOrM59_COUNT)
      p = NULLED_OUT ; 
      a = NULLED_OUT ; 
      oe = ostx -> props ; 
      for (p = oe ; ((Scheme_Type ) (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; p = (((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . cdr ) ) {
        a = (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ; 
        if (((a ) == (source_symbol ) ) || ((a ) == (share_symbol ) ) )
          mod = 1 ; 
        else if (((a ) == (origin_symbol ) ) )
          mod = 1 ; 
      }
      if (mod ) {
        Scheme_Object * first = scheme_null , * last = ((void * ) 0 ) ; 
        BLOCK_SETUP((PUSH(first, 0+XfOrM59_COUNT), PUSH(last, 1+XfOrM59_COUNT)));
#       define XfOrM61_COUNT (2+XfOrM59_COUNT)
#       define SETUP_XfOrM61(x) SETUP(XfOrM61_COUNT)
        for (; ((Scheme_Type ) (((((long ) (oe ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (oe ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; oe = (((Scheme_Simple_Object * ) (oe ) ) -> u . pair_val . cdr ) ) {
#         define XfOrM66_COUNT (0+XfOrM61_COUNT)
#         define SETUP_XfOrM66(x) SETUP_XfOrM61(x)
          a = (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (oe ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ; 
          if (! ((a ) == (source_symbol ) ) && ! ((a ) == (share_symbol ) ) ) {
#           define XfOrM67_COUNT (0+XfOrM66_COUNT)
#           define SETUP_XfOrM67(x) SETUP_XfOrM66(x)
            if (! ((a ) == (origin_symbol ) ) ) {
#             define XfOrM69_COUNT (0+XfOrM67_COUNT)
#             define SETUP_XfOrM69(x) SETUP_XfOrM67(x)
              p = FUNCCALL(SETUP_XfOrM69(_), scheme_make_immutable_pair ((((Scheme_Simple_Object * ) (oe ) ) -> u . pair_val . car ) , scheme_null ) ); 
            }
            else {
#             define XfOrM68_COUNT (0+XfOrM67_COUNT)
#             define SETUP_XfOrM68(x) SETUP_XfOrM67(x)
              p = (__funcarg42 = (__funcarg43 = FUNCCALL(SETUP_XfOrM68(_), scheme_make_immutable_pair (origin , (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (oe ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (a , __funcarg43 ) )) , FUNCCALL_AGAIN(scheme_make_immutable_pair (__funcarg42 , scheme_null ) )) ; 
              add = 0 ; 
            }
            if (last )
              (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = p ; 
            else first = p ; 
            last = p ; 
          }
        }
        oe = first ; 
      }
      if (add ) {
#       define XfOrM60_COUNT (0+XfOrM59_COUNT)
#       define SETUP_XfOrM60(x) SETUP_XfOrM59(x)
        oe = (__funcarg38 = (__funcarg39 = FUNCCALL(SETUP_XfOrM60(_), scheme_make_immutable_pair (origin , scheme_null ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (origin_symbol , __funcarg39 ) )) , FUNCCALL_AGAIN(scheme_make_immutable_pair (__funcarg38 , oe ) )) ; 
      }
    }
  }
  else {
    oe = ((void * ) 0 ) ; 
  }
  if (! oe )
    oe = (__funcarg36 = (__funcarg37 = FUNCCALL(SETUP_XfOrM20(_), scheme_make_immutable_pair (origin , scheme_null ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (origin_symbol , __funcarg37 ) )) , FUNCCALL_AGAIN(scheme_make_immutable_pair (__funcarg36 , scheme_null ) )) ; 
  for (e1 = ne ; ((Scheme_Type ) (((((long ) (e1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e1 ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; e1 = (((Scheme_Simple_Object * ) (e1 ) ) -> u . pair_val . cdr ) ) {
    Scheme_Object * a ; 
    a = NULLED_OUT ; 
    a = (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (e1 ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ; 
    for (e2 = oe ; ((Scheme_Type ) (((((long ) (e2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e2 ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; e2 = (((Scheme_Simple_Object * ) (e2 ) ) -> u . pair_val . cdr ) ) {
      if ((((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (e2 ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) == (a ) ) ) {
        break ; 
      }
    }
    if (! ((e1 ) == (scheme_null ) ) )
      break ; 
  }
  if (((e1 ) == (scheme_null ) ) ) {
#   define XfOrM46_COUNT (0+XfOrM20_COUNT)
#   define SETUP_XfOrM46(x) SETUP_XfOrM20(x)
    if (! ((oe ) == (scheme_null ) ) )
      ne = FUNCCALL(SETUP_XfOrM46(_), scheme_append (ne , oe ) ); 
  }
  else {
    Scheme_Object * first = scheme_null , * last = ((void * ) 0 ) , * p ; 
    BLOCK_SETUP((PUSH(first, 0+XfOrM20_COUNT), PUSH(p, 1+XfOrM20_COUNT), PUSH(last, 2+XfOrM20_COUNT)));
#   define XfOrM23_COUNT (3+XfOrM20_COUNT)
#   define SETUP_XfOrM23(x) SETUP(XfOrM23_COUNT)
    p = NULLED_OUT ; 
    for (e1 = ne ; ((Scheme_Type ) (((((long ) (e1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e1 ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; e1 = (((Scheme_Simple_Object * ) (e1 ) ) -> u . pair_val . cdr ) ) {
      Scheme_Object * a , * v ; 
      BLOCK_SETUP((PUSH(v, 0+XfOrM23_COUNT), PUSH(a, 1+XfOrM23_COUNT)));
#     define XfOrM41_COUNT (2+XfOrM23_COUNT)
#     define SETUP_XfOrM41(x) SETUP(XfOrM41_COUNT)
      a = NULLED_OUT ; 
      v = NULLED_OUT ; 
      a = (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (e1 ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ; 
      v = (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (e1 ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ; 
      for (e2 = oe ; ((Scheme_Type ) (((((long ) (e2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e2 ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; e2 = (((Scheme_Simple_Object * ) (e2 ) ) -> u . pair_val . cdr ) ) {
#       define XfOrM44_COUNT (0+XfOrM41_COUNT)
#       define SETUP_XfOrM44(x) SETUP_XfOrM41(x)
        if ((((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (e2 ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) == (a ) ) ) {
#         define XfOrM45_COUNT (0+XfOrM44_COUNT)
#         define SETUP_XfOrM45(x) SETUP_XfOrM44(x)
          v = FUNCCALL(SETUP_XfOrM45(_), scheme_make_immutable_pair (v , (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (e2 ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ); 
          break ; 
        }
      }
      p = (__funcarg35 = FUNCCALL(SETUP_XfOrM41(_), scheme_make_immutable_pair (a , v ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (__funcarg35 , scheme_null ) )) ; 
      if (last )
        (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = p ; 
      else first = p ; 
      last = p ; 
    }
    for (e1 = oe ; ((Scheme_Type ) (((((long ) (e1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e1 ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; e1 = (((Scheme_Simple_Object * ) (e1 ) ) -> u . pair_val . cdr ) ) {
      Scheme_Object * a , * v ; 
      BLOCK_SETUP((PUSH(v, 0+XfOrM23_COUNT), PUSH(a, 1+XfOrM23_COUNT)));
#     define XfOrM30_COUNT (2+XfOrM23_COUNT)
#     define SETUP_XfOrM30(x) SETUP(XfOrM30_COUNT)
      a = NULLED_OUT ; 
      v = NULLED_OUT ; 
      a = (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (e1 ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ; 
      v = (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (e1 ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ; 
      for (e2 = ne ; ((Scheme_Type ) (((((long ) (e2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e2 ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; e2 = (((Scheme_Simple_Object * ) (e2 ) ) -> u . pair_val . cdr ) ) {
        if ((((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (e2 ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) == (a ) ) ) {
          v = ((void * ) 0 ) ; 
          break ; 
        }
      }
      if (v ) {
#       define XfOrM31_COUNT (0+XfOrM30_COUNT)
#       define SETUP_XfOrM31(x) SETUP_XfOrM30(x)
        p = (__funcarg33 = FUNCCALL(SETUP_XfOrM31(_), scheme_make_immutable_pair (a , v ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (__funcarg33 , scheme_null ) )) ; 
        if (last )
          (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = p ; 
        else first = p ; 
        last = p ; 
      }
    }
    ne = first ; 
  }
  graph = ((& (nstx ) -> iso ) -> so . keyex & 0x1 ) ; 
  wraps = nstx -> wraps ; 
  if ((& (nstx ) -> iso ) -> so . keyex & 0x2 ) {
    modinfo_cache = ((void * ) 0 ) ; 
    lazy_prefix = nstx -> u . lazy_prefix ; 
  }
  else {
    modinfo_cache = nstx -> u . modinfo_cache ; 
    lazy_prefix = 0 ; 
  }
  certs = nstx -> certs ; 
  nstx = (Scheme_Stx * ) FUNCCALL(SETUP_XfOrM20(_), scheme_make_stx (nstx -> val , nstx -> srcloc , ne ) ); 
  nstx -> wraps = wraps ; 
  if (modinfo_cache )
    nstx -> u . modinfo_cache = modinfo_cache ; 
  else nstx -> u . lazy_prefix = lazy_prefix ; 
  nstx -> certs = certs ; 
  if (graph )
    (& (nstx ) -> iso ) -> so . keyex |= 0x1 ; 
  RET_VALUE_START ((Scheme_Object * ) nstx ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int maybe_add_chain_cache (Scheme_Stx * stx ) {
  Wrap_Pos awl ; 
  Scheme_Object * p ; 
  int skipable = 0 , pos = 1 ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(stx, 0), PUSH(awl.l, 1), PUSH(awl.a, 2), PUSH(p, 3)));
# define XfOrM75_COUNT (4)
# define SETUP_XfOrM75(x) SETUP(XfOrM75_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  awl.l = NULLED_OUT ; 
  awl.a = NULLED_OUT ; 
  p = NULLED_OUT ; 
  awl . l = ((Scheme_Stx * ) stx ) -> wraps ; 
  (WRAP_POS_SET_FIRST (& awl ) ) ; 
  while (! ((awl . l ) == (scheme_null ) ) ) {
#   define XfOrM82_COUNT (0+XfOrM75_COUNT)
#   define SETUP_XfOrM82(x) SETUP_XfOrM75(x)
    p = awl . a ; 
    if (((Scheme_Type ) (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
      skipable ++ ; 
    }
    else if (((((long ) (p ) ) & 0x1 ) || ((((p ) -> type ) >= scheme_bignum_type ) && (((p ) -> type ) <= scheme_complex_type ) ) ) || ((Scheme_Type ) (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
    }
    else if (((Scheme_Type ) (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) ) {
      Scheme_Hash_Table * ht2 = (Scheme_Hash_Table * ) p ; 
#     define XfOrM83_COUNT (0+XfOrM82_COUNT)
#     define SETUP_XfOrM83(x) SETUP_XfOrM82(x)
      if (! ht2 -> count )
        pos = ht2 -> size ; 
      else {
#       define XfOrM84_COUNT (0+XfOrM83_COUNT)
#       define SETUP_XfOrM84(x) SETUP_XfOrM83(x)
        p = FUNCCALL(SETUP_XfOrM84(_), scheme_hash_get (ht2 , ((Scheme_Object * ) (void * ) (long ) ((((long ) (2 ) ) << 1 ) | 0x1 ) ) ) ); 
        pos = (((long ) (p ) ) >> 1 ) ; 
      }
      pos ++ ; 
      break ; 
    }
    else break ; 
    (DO_WRAP_POS_INC (& awl ) ) ; 
  }
  if (skipable >= 32 ) {
    Scheme_Hash_Table * ht ; 
    BLOCK_SETUP((PUSH(ht, 0+XfOrM75_COUNT)));
#   define XfOrM76_COUNT (1+XfOrM75_COUNT)
#   define SETUP_XfOrM76(x) SETUP(XfOrM76_COUNT)
    ht = NULLED_OUT ; 
    ht = FUNCCALL(SETUP_XfOrM76(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
    ht -> size = pos ; 
    p = FUNCCALL(SETUP_XfOrM76(_), scheme_make_pair ((Scheme_Object * ) ht , stx -> wraps ) ); 
    stx -> wraps = p ; 
    if ((& (stx ) -> iso ) -> so . keyex & 0x2 )
      stx -> u . lazy_prefix ++ ; 
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  }
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void set_wraps_to_skip (Scheme_Hash_Table * ht , Wrap_Pos * wraps ) {
  Scheme_Object * v ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(wraps, 1), PUSH(ht, 2)));
# define XfOrM87_COUNT (3)
# define SETUP_XfOrM87(x) SETUP(XfOrM87_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  v = FUNCCALL(SETUP_XfOrM87(_), scheme_hash_get (ht , ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) ); 
  wraps -> l = v ; 
  v = FUNCCALL(SETUP_XfOrM87(_), scheme_hash_get (ht , ((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) ) ); 
  if ((! (((v ) ) == (scheme_false ) ) ) ) {
    wraps -> pos = (((long ) (v ) ) >> 1 ) ; 
    wraps -> is_limb = 1 ; 
    wraps -> a = ((Wrap_Chunk * ) (((Scheme_Simple_Object * ) (wraps -> l ) ) -> u . pair_val . car ) ) -> a [wraps -> pos ] ; 
  }
  else {
    wraps -> is_limb = 0 ; 
    if (! ((wraps -> l ) == (scheme_null ) ) )
      wraps -> a = (((Scheme_Simple_Object * ) (wraps -> l ) ) -> u . pair_val . car ) ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void fill_chain_cache (Scheme_Object * wraps ) {
  int pos , max_depth , limit ; 
  Scheme_Hash_Table * ht ; 
  Scheme_Object * p , * id ; 
  Wrap_Pos awl ; 
  PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(id, 0), PUSH(awl.l, 1), PUSH(awl.a, 2), PUSH(ht, 3), PUSH(p, 4), PUSH(wraps, 5)));
# define XfOrM90_COUNT (6)
# define SETUP_XfOrM90(x) SETUP(XfOrM90_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ht = NULLED_OUT ; 
  p = NULLED_OUT ; 
  id = NULLED_OUT ; 
  awl.l = NULLED_OUT ; 
  awl.a = NULLED_OUT ; 
  ht = (Scheme_Hash_Table * ) (((Scheme_Simple_Object * ) (wraps ) ) -> u . pair_val . car ) ; 
  p = FUNCCALL(SETUP_XfOrM90(_), scheme_hash_get (ht , ((Scheme_Object * ) (void * ) (long ) ((((long ) (5 ) ) << 1 ) | 0x1 ) ) ) ); 
  if (p ) {
#   define XfOrM110_COUNT (0+XfOrM90_COUNT)
#   define SETUP_XfOrM110(x) SETUP_XfOrM90(x)
    limit = (((long ) (p ) ) >> 1 ) ; 
    FUNCCALL(SETUP_XfOrM110(_), set_wraps_to_skip (ht , & awl ) ); 
    p = FUNCCALL_AGAIN(scheme_hash_get (ht , ((Scheme_Object * ) (void * ) (long ) ((((long ) (2 ) ) << 1 ) | 0x1 ) ) ) ); 
    pos = (((long ) (p ) ) >> 1 ) ; 
    FUNCCALL(SETUP_XfOrM110(_), scheme_hash_set (ht , ((Scheme_Object * ) (void * ) (long ) ((((long ) (5 ) ) << 1 ) | 0x1 ) ) , ((void * ) 0 ) ) ); 
  }
  else {
#   define XfOrM109_COUNT (0+XfOrM90_COUNT)
#   define SETUP_XfOrM109(x) SETUP_XfOrM90(x)
    pos = ht -> size ; 
    ht -> size = 0 ; 
    wraps = (((Scheme_Simple_Object * ) (wraps ) ) -> u . pair_val . cdr ) ; 
    awl . l = wraps ; 
    (WRAP_POS_SET_FIRST (& awl ) ) ; 
    limit = 4 ; 
  }
  max_depth = limit ; 
  while (! ((awl . l ) == (scheme_null ) ) ) {
#   define XfOrM101_COUNT (0+XfOrM90_COUNT)
#   define SETUP_XfOrM101(x) SETUP_XfOrM90(x)
    if (! (max_depth -- ) ) {
      limit *= 2 ; 
#     define XfOrM108_COUNT (0+XfOrM101_COUNT)
#     define SETUP_XfOrM108(x) SETUP_XfOrM101(x)
      FUNCCALL(SETUP_XfOrM108(_), scheme_hash_set (ht , ((Scheme_Object * ) (void * ) (long ) ((((long ) (5 ) ) << 1 ) | 0x1 ) ) , ((Scheme_Object * ) (void * ) (long ) ((((long ) (limit ) ) << 1 ) | 0x1 ) ) ) ); 
      break ; 
    }
    p = awl . a ; 
    if (((Scheme_Type ) (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
      int i , len ; 
#     define XfOrM105_COUNT (0+XfOrM101_COUNT)
#     define SETUP_XfOrM105(x) SETUP_XfOrM101(x)
      len = (((((Scheme_Vector * ) (p ) ) -> size ) - 2 ) >> 1 ) ; 
      for (i = 0 ; i < len ; i ++ ) {
#       define XfOrM107_COUNT (0+XfOrM105_COUNT)
#       define SETUP_XfOrM107(x) SETUP_XfOrM105(x)
        id = (((Scheme_Vector * ) (p ) ) -> els ) [i + 2 ] ; 
        if (((Scheme_Type ) (((((long ) (id ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (id ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
          id = ((Scheme_Stx * ) id ) -> val ; 
        FUNCCALL(SETUP_XfOrM107(_), scheme_hash_set (ht , id , scheme_true ) ); 
      }
    }
    else if (((((long ) (p ) ) & 0x1 ) || ((((p ) -> type ) >= scheme_bignum_type ) && (((p ) -> type ) <= scheme_complex_type ) ) ) || ((Scheme_Type ) (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
    }
    else if (((Scheme_Type ) (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) ) {
      Scheme_Hash_Table * ht2 = (Scheme_Hash_Table * ) p ; 
      int pos2 ; 
#     define XfOrM102_COUNT (0+XfOrM101_COUNT)
#     define SETUP_XfOrM102(x) SETUP_XfOrM101(x)
      if (! ht2 -> count )
        pos2 = ht2 -> size ; 
      else {
#       define XfOrM103_COUNT (0+XfOrM102_COUNT)
#       define SETUP_XfOrM103(x) SETUP_XfOrM102(x)
        p = FUNCCALL(SETUP_XfOrM103(_), scheme_hash_get (ht2 , ((Scheme_Object * ) (void * ) (long ) ((((long ) (2 ) ) << 1 ) | 0x1 ) ) ) ); 
        pos2 = (((long ) (p ) ) >> 1 ) ; 
      }
      if ((pos & pos2 ) == pos2 )
        break ; 
    }
    else break ; 
    (DO_WRAP_POS_INC (& awl ) ) ; 
  }
  FUNCCALL(SETUP_XfOrM90(_), scheme_hash_set (ht , ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) , awl . l ) ); 
  if (! awl . is_limb ) {
#   define XfOrM92_COUNT (0+XfOrM90_COUNT)
#   define SETUP_XfOrM92(x) SETUP_XfOrM90(x)
    FUNCCALL(SETUP_XfOrM92(_), scheme_hash_set (ht , ((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) , scheme_false ) ); 
  }
  else {
#   define XfOrM91_COUNT (0+XfOrM90_COUNT)
#   define SETUP_XfOrM91(x) SETUP_XfOrM90(x)
    FUNCCALL(SETUP_XfOrM91(_), scheme_hash_set (ht , ((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) , ((Scheme_Object * ) (void * ) (long ) ((((long ) (awl . pos ) ) << 1 ) | 0x1 ) ) ) ); 
  }
  FUNCCALL(SETUP_XfOrM90(_), scheme_hash_set (ht , ((Scheme_Object * ) (void * ) (long ) ((((long ) (2 ) ) << 1 ) | 0x1 ) ) , ((Scheme_Object * ) (void * ) (long ) ((((long ) (pos ) ) << 1 ) | 0x1 ) ) ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_new_mark () {
  /* No conversion */
  mark_id = scheme_add1 (1 , & mark_id ) ; 
  return mark_id ; 
}
static Scheme_Object * negate_mark (Scheme_Object * n ) {
  /* No conversion */
  return scheme_bin_minus (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) , n ) ; 
}
Scheme_Object * scheme_add_remove_mark (Scheme_Object * o , Scheme_Object * m ) {
  Scheme_Stx * stx = (Scheme_Stx * ) o ; 
  Scheme_Object * wraps ; 
  Scheme_Object * certs ; 
  long lp ; 
  int graph ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(certs, 0), PUSH(stx, 1), PUSH(wraps, 2), PUSH(m, 3)));
# define XfOrM113_COUNT (4)
# define SETUP_XfOrM113(x) SETUP(XfOrM113_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  wraps = NULLED_OUT ; 
  certs = NULLED_OUT ; 
  graph = ((& (stx ) -> iso ) -> so . keyex & 0x1 ) ; 
  if ((& (stx ) -> iso ) -> so . keyex & 0x2 )
    lp = stx -> u . lazy_prefix ; 
  else lp = 1 ; 
  wraps = stx -> wraps ; 
  if (((Scheme_Type ) (((((long ) (wraps ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (wraps ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((m ) == ((((Scheme_Simple_Object * ) (wraps ) ) -> u . pair_val . car ) ) ) && lp ) {
    -- lp ; 
    wraps = (((Scheme_Simple_Object * ) (wraps ) ) -> u . pair_val . cdr ) ; 
  }
  else {
#   define XfOrM114_COUNT (0+XfOrM113_COUNT)
#   define SETUP_XfOrM114(x) SETUP_XfOrM113(x)
    if (FUNCCALL(SETUP_XfOrM114(_), maybe_add_chain_cache (stx ) ))
      lp ++ ; 
    wraps = stx -> wraps ; 
    lp ++ ; 
    wraps = FUNCCALL(SETUP_XfOrM114(_), scheme_make_pair (m , wraps ) ); 
  }
  certs = stx -> certs ; 
  stx = (Scheme_Stx * ) FUNCCALL(SETUP_XfOrM113(_), scheme_make_stx (stx -> val , stx -> srcloc , stx -> props ) ); 
  stx -> wraps = wraps ; 
  stx -> certs = certs ; 
  if ((& (stx ) -> iso ) -> so . keyex & 0x2 )
    stx -> u . lazy_prefix = lp ; 
  if (graph )
    (& (stx ) -> iso ) -> so . keyex |= 0x1 ; 
  RET_VALUE_START ((Scheme_Object * ) stx ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 1018 */
Scheme_Object * scheme_make_rename (Scheme_Object * newname , int c ) {
  Scheme_Object * v ; 
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(newname, 1)));
# define XfOrM116_COUNT (2)
# define SETUP_XfOrM116(x) SETUP(XfOrM116_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  v = NULLED_OUT ; 
  v = FUNCCALL(SETUP_XfOrM116(_), scheme_make_vector ((2 * c ) + 2 , ((void * ) 0 ) ) ); 
  (((Scheme_Vector * ) (v ) ) -> els ) [0 ] = newname ; 
  if (c > 15 ) {
    Scheme_Hash_Table * ht ; 
    BLOCK_SETUP((PUSH(ht, 0+XfOrM116_COUNT)));
#   define XfOrM119_COUNT (1+XfOrM116_COUNT)
#   define SETUP_XfOrM119(x) SETUP(XfOrM119_COUNT)
    ht = NULLED_OUT ; 
    ht = FUNCCALL(SETUP_XfOrM119(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
    (((Scheme_Vector * ) (v ) ) -> els ) [1 ] = (Scheme_Object * ) ht ; 
  }
  else (((Scheme_Vector * ) (v ) ) -> els ) [1 ] = scheme_false ; 
  for (i = 0 ; i < c ; i ++ ) {
    (((Scheme_Vector * ) (v ) ) -> els ) [2 + c + i ] = scheme_void ; 
  }
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_set_rename (Scheme_Object * rnm , int pos , Scheme_Object * oldname ) {
  PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(oldname, 0)));
# define XfOrM120_COUNT (1)
# define SETUP_XfOrM120(x) SETUP(XfOrM120_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  (((Scheme_Vector * ) (rnm ) ) -> els ) [2 + pos ] = oldname ; 
  if (! ((((((Scheme_Vector * ) (rnm ) ) -> els ) [1 ] ) ) == (scheme_false ) ) ) {
    Scheme_Hash_Table * ht ; 
    BLOCK_SETUP((PUSH(ht, 0+XfOrM120_COUNT)));
#   define XfOrM121_COUNT (1+XfOrM120_COUNT)
#   define SETUP_XfOrM121(x) SETUP(XfOrM121_COUNT)
    ht = NULLED_OUT ; 
    ht = (Scheme_Hash_Table * ) (((Scheme_Vector * ) (rnm ) ) -> els ) [1 ] ; 
    if (FUNCCALL(SETUP_XfOrM121(_), scheme_hash_get (ht , ((Scheme_Stx * ) oldname ) -> val ) ))
      pos = - 1 ; 
    FUNCCALL_EMPTY(scheme_hash_set (ht , ((Scheme_Stx * ) oldname ) -> val , ((Scheme_Object * ) (void * ) (long ) ((((long ) (pos ) ) << 1 ) | 0x1 ) ) ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_rename_rib () {
  Scheme_Lexical_Rib * rib ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(rib, 0)));
# define XfOrM122_COUNT (1)
# define SETUP_XfOrM122(x) SETUP(XfOrM122_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  rib = NULLED_OUT ; 
  rib = ((Scheme_Lexical_Rib * ) FUNCCALL(SETUP_XfOrM122(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Lexical_Rib ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  rib -> so . type = scheme_lexical_rib_type ; 
  rib -> timestamp = current_rib_timestamp ; 
  current_rib_timestamp = FUNCCALL(SETUP_XfOrM122(_), scheme_add1 (1 , & current_rib_timestamp ) ); 
  RET_VALUE_START ((Scheme_Object * ) rib ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_add_rib_rename (Scheme_Object * ro , Scheme_Object * rename ) {
  Scheme_Lexical_Rib * rib , * naya ; 
  PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(naya, 0), PUSH(ro, 1), PUSH(rib, 2), PUSH(rename, 3)));
# define XfOrM123_COUNT (4)
# define SETUP_XfOrM123(x) SETUP(XfOrM123_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  rib = NULLED_OUT ; 
  naya = NULLED_OUT ; 
  naya = ((Scheme_Lexical_Rib * ) FUNCCALL(SETUP_XfOrM123(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Lexical_Rib ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  naya -> so . type = scheme_lexical_rib_type ; 
  naya -> rename = rename ; 
  rib = (Scheme_Lexical_Rib * ) ro ; 
  naya -> next = rib -> next ; 
  rib -> next = naya ; 
  naya -> timestamp = rib -> timestamp ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_drop_first_rib_rename (Scheme_Object * ro ) {
  /* No conversion */
  Scheme_Lexical_Rib * rib = (Scheme_Lexical_Rib * ) ro ; 
  rib -> next = rib -> next -> next ; 
}
Scheme_Object * scheme_make_module_rename (long phase , int kind , Scheme_Hash_Table * marked_names ) {
  Module_Renames * mr ; 
  Scheme_Hash_Table * ht ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(mr, 0), PUSH(marked_names, 1), PUSH(ht, 2)));
# define XfOrM125_COUNT (3)
# define SETUP_XfOrM125(x) SETUP(XfOrM125_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  mr = NULLED_OUT ; 
  ht = NULLED_OUT ; 
  mr = ((Module_Renames * ) FUNCCALL(SETUP_XfOrM125(_), GC_malloc_one_small_tagged ((((sizeof (Module_Renames ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  mr -> so . type = scheme_rename_table_type ; 
  ht = FUNCCALL(SETUP_XfOrM125(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  mr -> ht = ht ; 
  mr -> phase = phase ; 
  mr -> kind = kind ; 
  mr -> marked_names = marked_names ; 
  mr -> unmarshal_info = scheme_null ; 
  if (! krn ) {
#   define XfOrM126_COUNT (0+XfOrM125_COUNT)
#   define SETUP_XfOrM126(x) SETUP_XfOrM125(x)
    FUNCCALL(SETUP_XfOrM126(_), scheme_register_static ((void * ) & krn , sizeof (krn ) ) ); 
    krn = mr ; 
  }
  RET_VALUE_START ((Scheme_Object * ) mr ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_extend_module_rename_with_kernel (Scheme_Object * mrn , Scheme_Object * nominal_mod ) {
  /* No conversion */
  ((Module_Renames * ) mrn ) -> plus_kernel = 1 ; 
  ((Module_Renames * ) mrn ) -> plus_kernel_nominal_source = nominal_mod ; 
}
void scheme_extend_module_rename (Scheme_Object * mrn , Scheme_Object * modname , Scheme_Object * localname , Scheme_Object * exname , Scheme_Object * nominal_mod , Scheme_Object * nominal_ex , int mod_phase , int unmarshal_drop ) {
  Scheme_Object * elem ; 
  Scheme_Object * __funcarg45 = NULLED_OUT ; 
  PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(mrn, 0), PUSH(modname, 1), PUSH(localname, 2), PUSH(nominal_mod, 3), PUSH(nominal_ex, 4), PUSH(elem, 5), PUSH(exname, 6)));
# define XfOrM128_COUNT (7)
# define SETUP_XfOrM128(x) SETUP(XfOrM128_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  elem = NULLED_OUT ; 
  if (((modname ) == (nominal_mod ) ) && ((exname ) == (nominal_ex ) ) && ! mod_phase ) {
#   define XfOrM134_COUNT (0+XfOrM128_COUNT)
#   define SETUP_XfOrM134(x) SETUP_XfOrM128(x)
    if (((localname ) == (exname ) ) )
      elem = modname ; 
    else elem = FUNCCALL(SETUP_XfOrM134(_), scheme_make_pair (modname , exname ) ); 
  }
  else if (((exname ) == (nominal_ex ) ) && ((localname ) == (exname ) ) && ! mod_phase ) {
#   define XfOrM132_COUNT (0+XfOrM128_COUNT)
#   define SETUP_XfOrM132(x) SETUP_XfOrM128(x)
    if (nominal_ipair_cache && (((((Scheme_Simple_Object * ) (nominal_ipair_cache ) ) -> u . pair_val . car ) ) == (modname ) ) && (((((Scheme_Simple_Object * ) (nominal_ipair_cache ) ) -> u . pair_val . cdr ) ) == (nominal_mod ) ) )
      elem = nominal_ipair_cache ; 
    else {
#     define XfOrM133_COUNT (0+XfOrM132_COUNT)
#     define SETUP_XfOrM133(x) SETUP_XfOrM132(x)
      elem = FUNCCALL(SETUP_XfOrM133(_), scheme_make_immutable_pair (modname , nominal_mod ) ); 
      nominal_ipair_cache = elem ; 
    }
  }
  else {
#   define XfOrM131_COUNT (0+XfOrM128_COUNT)
#   define SETUP_XfOrM131(x) SETUP_XfOrM128(x)
    elem = (__funcarg45 = FUNCCALL(SETUP_XfOrM131(_), scheme_make_pair (nominal_mod , nominal_ex ) ), FUNCCALL_AGAIN(scheme_make_pair (exname , __funcarg45 ) )) ; 
    if (mod_phase )
      elem = FUNCCALL(SETUP_XfOrM131(_), scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (mod_phase ) ) << 1 ) | 0x1 ) ) , elem ) ); 
    elem = FUNCCALL(SETUP_XfOrM131(_), scheme_make_pair (modname , elem ) ); 
  }
  if (unmarshal_drop ) {
#   define XfOrM129_COUNT (0+XfOrM128_COUNT)
#   define SETUP_XfOrM129(x) SETUP_XfOrM128(x)
    if (! ((Module_Renames * ) mrn ) -> nomarshal_ht ) {
      Scheme_Hash_Table * ht ; 
      BLOCK_SETUP((PUSH(ht, 0+XfOrM129_COUNT)));
#     define XfOrM130_COUNT (1+XfOrM129_COUNT)
#     define SETUP_XfOrM130(x) SETUP(XfOrM130_COUNT)
      ht = NULLED_OUT ; 
      ht = FUNCCALL(SETUP_XfOrM130(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
      ((Module_Renames * ) mrn ) -> nomarshal_ht = ht ; 
    }
    FUNCCALL(SETUP_XfOrM129(_), scheme_hash_set (((Module_Renames * ) mrn ) -> nomarshal_ht , localname , elem ) ); 
  }
  else FUNCCALL_EMPTY(scheme_hash_set (((Module_Renames * ) mrn ) -> ht , localname , elem ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_save_module_rename_unmarshal (Scheme_Object * rn , Scheme_Object * info ) {
  Scheme_Object * l ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(rn, 0), PUSH(l, 1)));
# define XfOrM135_COUNT (2)
# define SETUP_XfOrM135(x) SETUP(XfOrM135_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  l = NULLED_OUT ; 
  l = FUNCCALL(SETUP_XfOrM135(_), scheme_make_pair (info , ((Module_Renames * ) rn ) -> unmarshal_info ) ); 
  ((Module_Renames * ) rn ) -> unmarshal_info = l ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void do_append_module_rename (Scheme_Object * src , Scheme_Object * dest , Scheme_Object * old_midx , Scheme_Object * new_midx ) {
  Scheme_Hash_Table * ht , * hts , * drop_ht ; 
  Scheme_Object * v ; 
  int i , t ; 
  Scheme_Object * __funcarg61 = NULLED_OUT ; 
  Scheme_Object * __funcarg60 = NULLED_OUT ; 
  Scheme_Object * __funcarg59 = NULLED_OUT ; 
  Scheme_Object * __funcarg58 = NULLED_OUT ; 
  PREPARE_VAR_STACK(11);
  BLOCK_SETUP_TOP((PUSH(ht, 0), PUSH(old_midx, 1), PUSH(hts, 2), PUSH(src, 3), PUSH(drop_ht, 4), PUSH(dest, 5), PUSH(v, 6), PUSH(__funcarg59, 7), PUSH(new_midx, 8)));
# define XfOrM136_COUNT (9)
# define SETUP_XfOrM136(x) SETUP(XfOrM136_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  ht = NULLED_OUT ; 
  hts = NULLED_OUT ; 
  drop_ht = NULLED_OUT ; 
  v = NULLED_OUT ; 
  if (((Module_Renames * ) src ) -> plus_kernel ) {
    ((Module_Renames * ) dest ) -> plus_kernel = 1 ; 
    ((Module_Renames * ) dest ) -> plus_kernel_nominal_source = ((Module_Renames * ) src ) -> plus_kernel_nominal_source ; 
  }
  for (t = 0 ; t < 2 ; t ++ ) {
#   define XfOrM160_COUNT (0+XfOrM136_COUNT)
#   define SETUP_XfOrM160(x) SETUP_XfOrM136(x)
    if (! t ) {
      ht = ((Module_Renames * ) dest ) -> ht ; 
      hts = ((Module_Renames * ) src ) -> ht ; 
      drop_ht = ((Module_Renames * ) dest ) -> nomarshal_ht ; 
    }
    else {
#     define XfOrM179_COUNT (0+XfOrM160_COUNT)
#     define SETUP_XfOrM179(x) SETUP_XfOrM160(x)
      hts = ((Module_Renames * ) src ) -> nomarshal_ht ; 
      if (! hts )
        break ; 
      ht = ((Module_Renames * ) dest ) -> nomarshal_ht ; 
      if (! ht ) {
#       define XfOrM180_COUNT (0+XfOrM179_COUNT)
#       define SETUP_XfOrM180(x) SETUP_XfOrM179(x)
        ht = FUNCCALL(SETUP_XfOrM180(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
        ((Module_Renames * ) dest ) -> nomarshal_ht = ht ; 
      }
      drop_ht = ((Module_Renames * ) dest ) -> ht ; 
    }
    for (i = hts -> size ; i -- ; ) {
#     define XfOrM170_COUNT (0+XfOrM160_COUNT)
#     define SETUP_XfOrM170(x) SETUP_XfOrM160(x)
      if (hts -> vals [i ] ) {
#       define XfOrM171_COUNT (0+XfOrM170_COUNT)
#       define SETUP_XfOrM171(x) SETUP_XfOrM170(x)
        v = hts -> vals [i ] ; 
        if (old_midx ) {
#         define XfOrM172_COUNT (0+XfOrM171_COUNT)
#         define SETUP_XfOrM172(x) SETUP_XfOrM171(x)
          if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#           define XfOrM174_COUNT (0+XfOrM172_COUNT)
#           define SETUP_XfOrM174(x) SETUP_XfOrM172(x)
            if (((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
              Scheme_Object * midx1 , * midx2 ; 
              int mod_phase ; 
              BLOCK_SETUP((PUSH(midx2, 0+XfOrM174_COUNT), PUSH(midx1, 1+XfOrM174_COUNT)));
#             define XfOrM177_COUNT (2+XfOrM174_COUNT)
#             define SETUP_XfOrM177(x) SETUP(XfOrM177_COUNT)
              midx1 = NULLED_OUT ; 
              midx2 = NULLED_OUT ; 
              midx1 = (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) ; 
              v = (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) ; 
              if ((((long ) ((((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) ) ) & 0x1 ) ) {
                mod_phase = (((long ) ((((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) ) ) >> 1 ) ; 
                v = (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) ; 
              }
              else mod_phase = 0 ; 
              midx2 = (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ; 
              midx1 = FUNCCALL(SETUP_XfOrM177(_), scheme_modidx_shift (midx1 , old_midx , new_midx ) ); 
              midx2 = FUNCCALL_AGAIN(scheme_modidx_shift (midx2 , old_midx , new_midx ) ); 
              v = (__funcarg61 = FUNCCALL(SETUP_XfOrM177(_), scheme_make_pair (midx2 , (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ), FUNCCALL_AGAIN(scheme_make_pair ((((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) , __funcarg61 ) )) ; 
              if (mod_phase )
                v = FUNCCALL(SETUP_XfOrM177(_), scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (mod_phase ) ) << 1 ) | 0x1 ) ) , v ) ); 
              v = FUNCCALL(SETUP_XfOrM177(_), scheme_make_pair (midx1 , v ) ); 
            }
            else if ((((Scheme_Inclhash_Object * ) (v ) ) -> so . keyex & 0x1 ) ) {
#             define XfOrM176_COUNT (0+XfOrM174_COUNT)
#             define SETUP_XfOrM176(x) SETUP_XfOrM174(x)
              v = (__funcarg59 = FUNCCALL(SETUP_XfOrM176(_), scheme_modidx_shift ((((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) , old_midx , new_midx ) ), __funcarg60 = FUNCCALL(SETUP_XfOrM176(_), scheme_modidx_shift ((((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) , old_midx , new_midx ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (__funcarg59 , __funcarg60 ) )) ; 
            }
            else {
#             define XfOrM175_COUNT (0+XfOrM174_COUNT)
#             define SETUP_XfOrM175(x) SETUP_XfOrM174(x)
              v = (__funcarg58 = FUNCCALL(SETUP_XfOrM175(_), scheme_modidx_shift ((((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) , old_midx , new_midx ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg58 , (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) ) )) ; 
            }
          }
          else {
#           define XfOrM173_COUNT (0+XfOrM172_COUNT)
#           define SETUP_XfOrM173(x) SETUP_XfOrM172(x)
            v = FUNCCALL(SETUP_XfOrM173(_), scheme_modidx_shift (v , old_midx , new_midx ) ); 
          }
        }
        FUNCCALL(SETUP_XfOrM171(_), scheme_hash_set (ht , hts -> keys [i ] , v ) ); 
        if (drop_ht )
          FUNCCALL(SETUP_XfOrM171(_), scheme_hash_set (drop_ht , hts -> keys [i ] , ((void * ) 0 ) ) ); 
      }
    }
  }
  if (((Module_Renames * ) src ) -> marked_names ) {
    ((Module_Renames * ) dest ) -> marked_names = ((Module_Renames * ) src ) -> marked_names ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_append_module_rename (Scheme_Object * src , Scheme_Object * dest ) {
  /* No conversion */
  do_append_module_rename (src , dest , ((void * ) 0 ) , ((void * ) 0 ) ) ; 
}
void scheme_remove_module_rename (Scheme_Object * mrn , Scheme_Object * localname ) {
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(mrn, 0), PUSH(localname, 1)));
# define XfOrM184_COUNT (2)
# define SETUP_XfOrM184(x) SETUP(XfOrM184_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM184(_), scheme_hash_set (((Module_Renames * ) mrn ) -> ht , localname , ((void * ) 0 ) ) ); 
  if (((Module_Renames * ) mrn ) -> nomarshal_ht )
    FUNCCALL_EMPTY(scheme_hash_set (((Module_Renames * ) mrn ) -> nomarshal_ht , localname , ((void * ) 0 ) ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_list_module_rename (Scheme_Object * src , Scheme_Hash_Table * ht ) {
  Scheme_Hash_Table * hts ; 
  int i , t ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(hts, 0), PUSH(src, 1), PUSH(ht, 2)));
# define XfOrM185_COUNT (3)
# define SETUP_XfOrM185(x) SETUP(XfOrM185_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  hts = NULLED_OUT ; 
  for (t = 0 ; t < 2 ; t ++ ) {
#   define XfOrM193_COUNT (0+XfOrM185_COUNT)
#   define SETUP_XfOrM193(x) SETUP_XfOrM185(x)
    if (! t )
      hts = ((Module_Renames * ) src ) -> ht ; 
    else {
      hts = ((Module_Renames * ) src ) -> nomarshal_ht ; 
      if (! hts )
        break ; 
    }
    for (i = hts -> size ; i -- ; ) {
#     define XfOrM196_COUNT (0+XfOrM193_COUNT)
#     define SETUP_XfOrM196(x) SETUP_XfOrM193(x)
      if (hts -> vals [i ] ) {
#       define XfOrM197_COUNT (0+XfOrM196_COUNT)
#       define SETUP_XfOrM197(x) SETUP_XfOrM196(x)
        FUNCCALL(SETUP_XfOrM197(_), scheme_hash_set (ht , hts -> keys [i ] , scheme_false ) ); 
      }
    }
  }
  if (((Module_Renames * ) src ) -> plus_kernel ) {
#   define XfOrM186_COUNT (0+XfOrM185_COUNT)
#   define SETUP_XfOrM186(x) SETUP_XfOrM185(x)
    FUNCCALL_EMPTY(scheme_list_module_rename ((Scheme_Object * ) krn , ht ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_rename_to_stx (Scheme_Object * mrn ) {
  Scheme_Object * stx ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(mrn, 0), PUSH(stx, 1)));
# define XfOrM199_COUNT (2)
# define SETUP_XfOrM199(x) SETUP(XfOrM199_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  stx = NULLED_OUT ; 
  stx = FUNCCALL(SETUP_XfOrM199(_), scheme_make_stx (scheme_false , empty_srcloc , ((void * ) 0 ) ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_add_rename (stx , mrn ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_stx_to_rename (Scheme_Object * stx ) {
  /* No conversion */
  Scheme_Object * wraps ; 
  wraps = ((Scheme_Stx * ) stx ) -> wraps ; 
  return (((Scheme_Simple_Object * ) (wraps ) ) -> u . pair_val . car ) ; 
}
Scheme_Object * scheme_stx_shift_rename (Scheme_Object * mrn , Scheme_Object * old_midx , Scheme_Object * new_midx ) {
  Scheme_Object * nmrn , * a , * l , * nl ; 
  Scheme_Object * __funcarg65 = NULLED_OUT ; 
  Scheme_Object * __funcarg64 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSH(a, 0), PUSH(l, 1), PUSH(nl, 2), PUSH(mrn, 3), PUSH(old_midx, 4), PUSH(nmrn, 5), PUSH(new_midx, 6)));
# define XfOrM201_COUNT (7)
# define SETUP_XfOrM201(x) SETUP(XfOrM201_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  nmrn = NULLED_OUT ; 
  a = NULLED_OUT ; 
  l = NULLED_OUT ; 
  nl = NULLED_OUT ; 
  nmrn = FUNCCALL(SETUP_XfOrM201(_), scheme_make_module_rename (0 , 1 , ((void * ) 0 ) ) ); 
  FUNCCALL_AGAIN(do_append_module_rename (mrn , nmrn , old_midx , new_midx ) ); 
  l = ((Module_Renames * ) mrn ) -> unmarshal_info ; 
  nl = scheme_null ; 
  while (! ((l ) == (scheme_null ) ) ) {
#   define XfOrM203_COUNT (0+XfOrM201_COUNT)
#   define SETUP_XfOrM203(x) SETUP_XfOrM201(x)
    a = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
    nl = (__funcarg64 = (__funcarg65 = FUNCCALL(SETUP_XfOrM203(_), scheme_modidx_shift ((((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) , old_midx , new_midx ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg65 , (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) ) )) , FUNCCALL_AGAIN(scheme_make_pair (__funcarg64 , nl ) )) ; 
    l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
  }
  ((Module_Renames * ) nmrn ) -> unmarshal_info = nl ; 
  RET_VALUE_START (nmrn ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Hash_Table * scheme_module_rename_marked_names (Scheme_Object * rn ) {
  /* No conversion */
  return ((Module_Renames * ) rn ) -> marked_names ; 
}
static void unmarshal_rename (Module_Renames * mrn , Scheme_Object * modidx_shift_from , Scheme_Object * modidx_shift_to , Scheme_Hash_Table * export_registry ) {
  Scheme_Object * l ; 
  PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(export_registry, 0), PUSH(mrn, 1), PUSH(modidx_shift_to, 2), PUSH(modidx_shift_from, 3), PUSH(l, 4)));
# define XfOrM205_COUNT (5)
# define SETUP_XfOrM205(x) SETUP(XfOrM205_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  l = NULLED_OUT ; 
  mrn -> needs_unmarshal = 0 ; 
  for (l = mrn -> unmarshal_info ; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#   define XfOrM207_COUNT (0+XfOrM205_COUNT)
#   define SETUP_XfOrM207(x) SETUP_XfOrM205(x)
    FUNCCALL(SETUP_XfOrM207(_), scheme_do_module_rename_unmarshal ((Scheme_Object * ) mrn , (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) , modidx_shift_from , modidx_shift_to , export_registry ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_add_rename (Scheme_Object * o , Scheme_Object * rename ) {
  Scheme_Stx * stx = (Scheme_Stx * ) o ; 
  Scheme_Object * wraps ; 
  Scheme_Object * certs ; 
  long lp ; 
  int graph ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(certs, 0), PUSH(stx, 1), PUSH(wraps, 2), PUSH(rename, 3)));
# define XfOrM208_COUNT (4)
# define SETUP_XfOrM208(x) SETUP(XfOrM208_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  wraps = NULLED_OUT ; 
  certs = NULLED_OUT ; 
  if ((& (stx ) -> iso ) -> so . keyex & 0x2 )
    FUNCCALL(SETUP_XfOrM208(_), preemptive_chunk (stx ) ); 
  FUNCCALL(SETUP_XfOrM208(_), maybe_add_chain_cache (stx ) ); 
  graph = ((& (stx ) -> iso ) -> so . keyex & 0x1 ) ; 
  wraps = FUNCCALL(SETUP_XfOrM208(_), scheme_make_pair (rename , stx -> wraps ) ); 
  if ((& (stx ) -> iso ) -> so . keyex & 0x2 )
    lp = stx -> u . lazy_prefix + 1 ; 
  else lp = 0 ; 
  certs = stx -> certs ; 
  stx = (Scheme_Stx * ) FUNCCALL(SETUP_XfOrM208(_), scheme_make_stx (stx -> val , stx -> srcloc , stx -> props ) ); 
  stx -> wraps = wraps ; 
  stx -> certs = certs ; 
  stx -> u . lazy_prefix = lp ; 
  if (graph )
    (& (stx ) -> iso ) -> so . keyex |= 0x1 ; 
  if (stx -> certs )
    FUNCCALL(SETUP_XfOrM208(_), phase_shift_certs ((Scheme_Object * ) stx , stx -> wraps , 1 ) ); 
  RET_VALUE_START ((Scheme_Object * ) stx ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_delayed_rename (Scheme_Object * * o , long i ) {
  Scheme_Object * rename ; 
  Resolve_Prefix * rp ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(rename, 0), PUSH(rp, 1)));
# define XfOrM209_COUNT (2)
# define SETUP_XfOrM209(x) SETUP(XfOrM209_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  rename = NULLED_OUT ; 
  rp = NULLED_OUT ; 
  rename = o [0 ] ; 
  if (! rename )
    RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
  rp = (Resolve_Prefix * ) o [1 ] ; 
  if ((((long ) (rp -> stxes [i ] ) ) & 0x1 ) ) {
    Scheme_Object * stx ; 
    BLOCK_SETUP((PUSH(stx, 0+XfOrM209_COUNT)));
#   define XfOrM210_COUNT (1+XfOrM209_COUNT)
#   define SETUP_XfOrM210(x) SETUP(XfOrM210_COUNT)
    stx = NULLED_OUT ; 
    stx = FUNCCALL(SETUP_XfOrM210(_), scheme_load_delayed_code ((((long ) (rp -> stxes [i ] ) ) >> 1 ) , rp -> delay_info ) ); 
    rp -> stxes [i ] = stx ; 
    -- rp -> delay_refcount ; 
    if (! rp -> delay_refcount )
      rp -> delay_info = ((void * ) 0 ) ; 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_add_rename (rp -> stxes [i ] , rename ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_add_rename_rib (Scheme_Object * o , Scheme_Object * rib ) {
  /* No conversion */
  return scheme_add_rename (o , rib ) ; 
}
Scheme_Object * scheme_stx_phase_shift_as_rename (long shift , Scheme_Object * old_midx , Scheme_Object * new_midx , Scheme_Hash_Table * export_registry ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(export_registry, 0), PUSH(old_midx, 1), PUSH(new_midx, 2)));
# define XfOrM212_COUNT (3)
# define SETUP_XfOrM212(x) SETUP(XfOrM212_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (shift || new_midx || export_registry ) {
    Scheme_Object * vec ; 
    BLOCK_SETUP((PUSH(vec, 0+XfOrM212_COUNT)));
#   define XfOrM213_COUNT (1+XfOrM212_COUNT)
#   define SETUP_XfOrM213(x) SETUP(XfOrM213_COUNT)
    vec = NULLED_OUT ; 
    if (last_phase_shift && ((vec = (((Scheme_Small_Object * ) (last_phase_shift ) ) -> u . ptr_val ) ) ) && ((((Scheme_Vector * ) (vec ) ) -> els ) [0 ] == ((Scheme_Object * ) (void * ) (long ) ((((long ) (shift ) ) << 1 ) | 0x1 ) ) ) && ((((Scheme_Vector * ) (vec ) ) -> els ) [1 ] == (new_midx ? old_midx : scheme_false ) ) && ((((Scheme_Vector * ) (vec ) ) -> els ) [2 ] == (new_midx ? new_midx : scheme_false ) ) && ((((Scheme_Vector * ) (vec ) ) -> els ) [3 ] == (export_registry ? (Scheme_Object * ) export_registry : scheme_false ) ) ) {
    }
    else {
#     define XfOrM214_COUNT (0+XfOrM213_COUNT)
#     define SETUP_XfOrM214(x) SETUP_XfOrM213(x)
      vec = FUNCCALL(SETUP_XfOrM214(_), scheme_make_vector (4 , ((void * ) 0 ) ) ); 
      (((Scheme_Vector * ) (vec ) ) -> els ) [0 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (shift ) ) << 1 ) | 0x1 ) ) ; 
      (((Scheme_Vector * ) (vec ) ) -> els ) [1 ] = (new_midx ? old_midx : scheme_false ) ; 
      (((Scheme_Vector * ) (vec ) ) -> els ) [2 ] = (new_midx ? new_midx : scheme_false ) ; 
      (((Scheme_Vector * ) (vec ) ) -> els ) [3 ] = (export_registry ? (Scheme_Object * ) export_registry : scheme_false ) ; 
      last_phase_shift = FUNCCALL_EMPTY(scheme_box (vec ) ); 
    }
    RET_VALUE_START (last_phase_shift ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_stx_phase_shift (Scheme_Object * stx , long shift , Scheme_Object * old_midx , Scheme_Object * new_midx , Scheme_Hash_Table * export_registry ) {
  Scheme_Object * ps ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(stx, 0), PUSH(ps, 1)));
# define XfOrM216_COUNT (2)
# define SETUP_XfOrM216(x) SETUP(XfOrM216_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ps = NULLED_OUT ; 
  ps = FUNCCALL(SETUP_XfOrM216(_), scheme_stx_phase_shift_as_rename (shift , old_midx , new_midx , export_registry ) ); 
  if (ps )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_add_rename (stx , ps ) )) RET_VALUE_EMPTY_END ; 
  else RET_VALUE_START (stx ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_clear_shift_cache (void ) {
  /* No conversion */
  last_phase_shift = ((void * ) 0 ) ; 
}
static void phase_shift_certs (Scheme_Object * o , Scheme_Object * owner_wraps , int len ) {
  Scheme_Object * l , * a , * modidx_shift_to = ((void * ) 0 ) , * modidx_shift_from = ((void * ) 0 ) , * vec , * src , * dest ; 
  int i , j , cnt ; 
  PREPARE_VAR_STACK(16);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(src, 1), PUSH(vec, 2), PUSH(a, 3), PUSH(modidx_shift_from, 4), PUSH(dest, 5), PUSH(owner_wraps, 6), PUSH(modidx_shift_to, 7), PUSH(l, 8)));
# define XfOrM218_COUNT (9)
# define SETUP_XfOrM218(x) SETUP(XfOrM218_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  l = NULLED_OUT ; 
  a = NULLED_OUT ; 
  vec = NULLED_OUT ; 
  src = NULLED_OUT ; 
  dest = NULLED_OUT ; 
  for (i = 0 , l = owner_wraps ; i < len ; i ++ , l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#   define XfOrM240_COUNT (0+XfOrM218_COUNT)
#   define SETUP_XfOrM240(x) SETUP_XfOrM218(x)
    a = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
    if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_wrap_chunk_type ) ) ) {
#     define XfOrM244_COUNT (0+XfOrM240_COUNT)
#     define SETUP_XfOrM244(x) SETUP_XfOrM240(x)
      cnt = ((Wrap_Chunk * ) a ) -> len ; 
      for (j = 0 ; j < cnt ; j ++ ) {
#       define XfOrM249_COUNT (0+XfOrM244_COUNT)
#       define SETUP_XfOrM249(x) SETUP_XfOrM244(x)
        if (((Scheme_Type ) (((((long ) (((Wrap_Chunk * ) a ) -> a [j ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Wrap_Chunk * ) a ) -> a [j ] ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) {
#         define XfOrM250_COUNT (0+XfOrM249_COUNT)
#         define SETUP_XfOrM250(x) SETUP_XfOrM249(x)
          vec = (((Scheme_Small_Object * ) (((Wrap_Chunk * ) a ) -> a [j ] ) ) -> u . ptr_val ) ; 
          src = (((Scheme_Vector * ) (vec ) ) -> els ) [1 ] ; 
          dest = (((Scheme_Vector * ) (vec ) ) -> els ) [2 ] ; 
          if (! modidx_shift_to ) {
            modidx_shift_to = dest ; 
          }
          else if (! ((modidx_shift_from ) == (dest ) ) ) {
#           define XfOrM251_COUNT (0+XfOrM250_COUNT)
#           define SETUP_XfOrM251(x) SETUP_XfOrM250(x)
            modidx_shift_to = FUNCCALL(SETUP_XfOrM251(_), scheme_modidx_shift (dest , modidx_shift_from , modidx_shift_to ) ); 
          }
          modidx_shift_from = src ; 
        }
      }
    }
    else if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) {
#     define XfOrM241_COUNT (0+XfOrM240_COUNT)
#     define SETUP_XfOrM241(x) SETUP_XfOrM240(x)
      vec = (((Scheme_Small_Object * ) (a ) ) -> u . ptr_val ) ; 
      src = (((Scheme_Vector * ) (vec ) ) -> els ) [1 ] ; 
      dest = (((Scheme_Vector * ) (vec ) ) -> els ) [2 ] ; 
      if (! modidx_shift_to ) {
        modidx_shift_to = dest ; 
      }
      else if (! ((modidx_shift_from ) == (dest ) ) ) {
#       define XfOrM242_COUNT (0+XfOrM241_COUNT)
#       define SETUP_XfOrM242(x) SETUP_XfOrM241(x)
        modidx_shift_to = FUNCCALL(SETUP_XfOrM242(_), scheme_modidx_shift (dest , modidx_shift_from , modidx_shift_to ) ); 
      }
      modidx_shift_from = src ; 
    }
  }
  if (modidx_shift_from ) {
    Scheme_Cert * certs , * acerts , * icerts , * first = ((void * ) 0 ) , * last = ((void * ) 0 ) , * c ; 
    Scheme_Object * nc ; 
    int i ; 
    BLOCK_SETUP((PUSH(first, 0+XfOrM218_COUNT), PUSH(acerts, 1+XfOrM218_COUNT), PUSH(last, 2+XfOrM218_COUNT), PUSH(c, 3+XfOrM218_COUNT), PUSH(certs, 4+XfOrM218_COUNT), PUSH(icerts, 5+XfOrM218_COUNT), PUSH(nc, 6+XfOrM218_COUNT)));
#   define XfOrM219_COUNT (7+XfOrM218_COUNT)
#   define SETUP_XfOrM219(x) SETUP(XfOrM219_COUNT)
    certs = NULLED_OUT ; 
    acerts = NULLED_OUT ; 
    icerts = NULLED_OUT ; 
    c = NULLED_OUT ; 
    nc = NULLED_OUT ; 
    acerts = ((Scheme_Cert * ) ((((Scheme_Stx * ) o ) ) -> certs ? (((Scheme_Type ) (((((long ) ((((Scheme_Stx * ) o ) ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Stx * ) o ) ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) ((((Scheme_Stx * ) o ) ) -> certs ) ) -> u . pair_val . car ) : (((Scheme_Stx * ) o ) ) -> certs ) : ((void * ) 0 ) ) ) ; 
    icerts = ((Scheme_Cert * ) ((((Scheme_Stx * ) o ) ) -> certs ? (((Scheme_Type ) (((((long ) ((((Scheme_Stx * ) o ) ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Stx * ) o ) ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) ((((Scheme_Stx * ) o ) ) -> certs ) ) -> u . pair_val . cdr ) : ((void * ) 0 ) ) : ((void * ) 0 ) ) ) ; 
    for (i = 0 ; i < 2 ; i ++ ) {
#     define XfOrM224_COUNT (0+XfOrM219_COUNT)
#     define SETUP_XfOrM224(x) SETUP_XfOrM219(x)
      certs = (i ? acerts : icerts ) ; 
      first = last = ((void * ) 0 ) ; 
      while (certs ) {
#       define XfOrM226_COUNT (0+XfOrM224_COUNT)
#       define SETUP_XfOrM226(x) SETUP_XfOrM224(x)
        a = FUNCCALL(SETUP_XfOrM226(_), scheme_modidx_shift (certs -> modidx , modidx_shift_from , modidx_shift_to ) ); 
        c = FUNCCALL(SETUP_XfOrM226(_), cons_cert (certs -> mark , a , certs -> insp , certs -> key , ((void * ) 0 ) ) ); 
        c -> mapped = certs -> mapped ; 
        c -> depth = certs -> depth ; 
        if (first )
          last -> next = c ; 
        else first = c ; 
        last = c ; 
        certs = certs -> next ; 
      }
      if (i )
        acerts = first ; 
      else icerts = first ; 
    }
    if (icerts || ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) o ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) o ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ) {
#     define XfOrM220_COUNT (0+XfOrM219_COUNT)
#     define SETUP_XfOrM220(x) SETUP_XfOrM219(x)
      nc = FUNCCALL(SETUP_XfOrM220(_), scheme_make_raw_pair ((Scheme_Object * ) acerts , (Scheme_Object * ) icerts ) ); 
    }
    else nc = (Scheme_Object * ) acerts ; 
    ((Scheme_Stx * ) o ) -> certs = nc ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_chunk (int len , Scheme_Object * owner_wraps ) {
  Wrap_Chunk * wc ; 
  Scheme_Object * l , * a , * max_chunk_start_list = ((void * ) 0 ) , * ml ; 
  int i , count = 0 , j , max_chunk_size = 0 , max_chunk_start_pos = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(wc, 0), PUSH(owner_wraps, 1), PUSH(a, 2), PUSH(ml, 3), PUSH(l, 4), PUSH(max_chunk_start_list, 5)));
# define XfOrM253_COUNT (6)
# define SETUP_XfOrM253(x) SETUP(XfOrM253_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  wc = NULLED_OUT ; 
  l = NULLED_OUT ; 
  a = NULLED_OUT ; 
  ml = NULLED_OUT ; 
  if (len > 1 ) {
#   define XfOrM255_COUNT (0+XfOrM253_COUNT)
#   define SETUP_XfOrM255(x) SETUP_XfOrM253(x)
    for (i = 0 , l = owner_wraps ; i < len ; i ++ , l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
      a = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
      if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_wrap_chunk_type ) ) ) {
        j = ((Wrap_Chunk * ) a ) -> len ; 
        if (j > max_chunk_size ) {
          max_chunk_start_list = l ; 
          max_chunk_start_pos = i ; 
          max_chunk_size = j ; 
        }
        count += j ; 
      }
      else if (((((long ) (a ) ) & 0x1 ) || ((((a ) -> type ) >= scheme_bignum_type ) && (((a ) -> type ) <= scheme_complex_type ) ) ) ) {
        if ((i >= len - 1 ) || ! ((a ) == (((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) ) )
          count ++ ; 
        else {
          i ++ ; 
          l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
        }
      }
      else if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) ) {
      }
      else count ++ ; 
    }
    if ((max_chunk_size > 8 ) && ((max_chunk_size * 2 ) > count ) ) {
      Scheme_Object * ml2 ; 
      BLOCK_SETUP((PUSH(ml2, 0+XfOrM255_COUNT)));
#     define XfOrM273_COUNT (1+XfOrM255_COUNT)
#     define SETUP_XfOrM273(x) SETUP(XfOrM273_COUNT)
      ml2 = NULLED_OUT ; 
      if (max_chunk_start_pos ) {
#       define XfOrM276_COUNT (0+XfOrM273_COUNT)
#       define SETUP_XfOrM276(x) SETUP_XfOrM273(x)
        ml = FUNCCALL(SETUP_XfOrM276(_), make_chunk (max_chunk_start_pos , owner_wraps ) ); 
        if (! ((Scheme_Type ) (((((long ) (ml ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ml ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ! ((ml ) == (scheme_null ) ) )
          ml = FUNCCALL(SETUP_XfOrM276(_), scheme_make_pair (ml , scheme_null ) ); 
      }
      else ml = scheme_null ; 
      ml = FUNCCALL(SETUP_XfOrM273(_), scheme_make_pair ((((Scheme_Simple_Object * ) (max_chunk_start_list ) ) -> u . pair_val . car ) , ml ) ); 
      if (max_chunk_start_pos + 1 < len ) {
#       define XfOrM274_COUNT (0+XfOrM273_COUNT)
#       define SETUP_XfOrM274(x) SETUP_XfOrM273(x)
        ml2 = FUNCCALL(SETUP_XfOrM274(_), make_chunk (len - 1 - max_chunk_start_pos , (((Scheme_Simple_Object * ) (max_chunk_start_list ) ) -> u . pair_val . cdr ) ) ); 
        if (! ((ml2 ) == (scheme_null ) ) ) {
#         define XfOrM275_COUNT (0+XfOrM274_COUNT)
#         define SETUP_XfOrM275(x) SETUP_XfOrM274(x)
          if (((Scheme_Type ) (((((long ) (ml2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ml2 ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
            ml = FUNCCALL(SETUP_XfOrM275(_), scheme_append (ml2 , ml ) ); 
          else ml = FUNCCALL(SETUP_XfOrM275(_), scheme_make_pair (ml2 , ml ) ); 
        }
      }
    }
    else {
#     define XfOrM256_COUNT (0+XfOrM255_COUNT)
#     define SETUP_XfOrM256(x) SETUP_XfOrM255(x)
      if (! count ) {
        ml = scheme_null ; 
      }
      else {
#       define XfOrM257_COUNT (0+XfOrM256_COUNT)
#       define SETUP_XfOrM257(x) SETUP_XfOrM256(x)
        wc = (Wrap_Chunk * ) FUNCCALL(SETUP_XfOrM257(_), GC_malloc_one_tagged (sizeof (Wrap_Chunk ) + ((count - 1 ) * sizeof (Scheme_Object * ) ) ) ); 
        wc -> type = scheme_wrap_chunk_type ; 
        wc -> len = count ; 
        ml = ((void * ) 0 ) ; 
        j = 0 ; 
        for (i = 0 , l = owner_wraps ; i < len ; i ++ , l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
          a = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
          if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_wrap_chunk_type ) ) ) {
            int k , cl = ((Wrap_Chunk * ) a ) -> len ; 
            for (k = 0 ; k < cl ; k ++ ) {
              wc -> a [j ++ ] = ((Wrap_Chunk * ) a ) -> a [k ] ; 
            }
          }
          else if (((((long ) (a ) ) & 0x1 ) || ((((a ) -> type ) >= scheme_bignum_type ) && (((a ) -> type ) <= scheme_complex_type ) ) ) ) {
            if ((i >= len - 1 ) || ! ((a ) == (((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) ) )
              wc -> a [j ++ ] = a ; 
            else {
              i ++ ; 
              l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
            }
          }
          else if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) ) {
          }
          else wc -> a [j ++ ] = a ; 
        }
        if (count == 1 )
          ml = wc -> a [0 ] ; 
        else ml = (Scheme_Object * ) wc ; 
      }
    }
  }
  else {
    ml = (((Scheme_Simple_Object * ) (owner_wraps ) ) -> u . pair_val . car ) ; 
    if (((Scheme_Type ) (((((long ) (ml ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ml ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) )
      RET_VALUE_START (scheme_null ) RET_VALUE_END ; 
  }
  RET_VALUE_START (ml ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void preemptive_chunk (Scheme_Stx * stx ) {
  int wl_count ; 
  int new_count ; 
  Scheme_Object * here_wraps , * ml ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(stx, 0), PUSH(here_wraps, 1), PUSH(ml, 2)));
# define XfOrM289_COUNT (3)
# define SETUP_XfOrM289(x) SETUP(XfOrM289_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  here_wraps = NULLED_OUT ; 
  ml = NULLED_OUT ; 
  wl_count = stx -> u . lazy_prefix ; 
  if (wl_count > 32 ) {
#   define XfOrM290_COUNT (0+XfOrM289_COUNT)
#   define SETUP_XfOrM290(x) SETUP_XfOrM289(x)
    here_wraps = stx -> wraps ; 
    ml = FUNCCALL(SETUP_XfOrM290(_), make_chunk (wl_count , here_wraps ) ); 
    if (((Scheme_Type ) (((((long ) (ml ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ml ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || ((ml ) == (scheme_null ) ) ) {
#     define XfOrM297_COUNT (0+XfOrM290_COUNT)
#     define SETUP_XfOrM297(x) SETUP_XfOrM290(x)
      new_count = FUNCCALL(SETUP_XfOrM297(_), scheme_list_length (ml ) ); 
      if (new_count == 1 )
        ml = (((Scheme_Simple_Object * ) (ml ) ) -> u . pair_val . car ) ; 
    }
    else {
      new_count = 1 ; 
    }
    while (wl_count -- ) {
      here_wraps = (((Scheme_Simple_Object * ) (here_wraps ) ) -> u . pair_val . cdr ) ; 
    }
    wl_count = new_count ; 
    if (new_count == 1 )
      here_wraps = FUNCCALL(SETUP_XfOrM290(_), scheme_make_pair (ml , here_wraps ) ); 
    else {
#     define XfOrM291_COUNT (0+XfOrM290_COUNT)
#     define SETUP_XfOrM291(x) SETUP_XfOrM290(x)
      while (new_count -- ) {
#       define XfOrM293_COUNT (0+XfOrM291_COUNT)
#       define SETUP_XfOrM293(x) SETUP_XfOrM291(x)
        here_wraps = FUNCCALL(SETUP_XfOrM293(_), scheme_make_pair ((((Scheme_Simple_Object * ) (ml ) ) -> u . pair_val . car ) , here_wraps ) ); 
        ml = (((Scheme_Simple_Object * ) (ml ) ) -> u . pair_val . cdr ) ; 
      }
    }
    stx -> wraps = here_wraps ; 
    stx -> u . lazy_prefix = wl_count ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * propagate_wraps (Scheme_Object * o , int len , Scheme_Object * * _ml , Scheme_Object * owner_wraps ) {
  int i ; 
  Scheme_Object * ml , * a ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(owner_wraps, 0), PUSH(o, 1), PUSH(a, 2), PUSH(ml, 3), PUSH(_ml, 4)));
# define XfOrM298_COUNT (5)
# define SETUP_XfOrM298(x) SETUP(XfOrM298_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  ml = NULLED_OUT ; 
  a = NULLED_OUT ; 
  if (len < 128 ) {
    Scheme_Stx * stx = (Scheme_Stx * ) o ; 
    Scheme_Object * p1 = owner_wraps ; 
    Scheme_Object * certs ; 
    BLOCK_SETUP((PUSH(stx, 0+XfOrM298_COUNT), PUSH(certs, 1+XfOrM298_COUNT)));
#   define XfOrM308_COUNT (2+XfOrM298_COUNT)
#   define SETUP_XfOrM308(x) SETUP(XfOrM308_COUNT)
    certs = NULLED_OUT ; 
    for (i = 0 ; i < len ; i ++ ) {
      p1 = (((Scheme_Simple_Object * ) (p1 ) ) -> u . pair_val . cdr ) ; 
    }
    if (((stx -> wraps ) == (p1 ) ) ) {
      long lp ; 
      int graph ; 
#     define XfOrM309_COUNT (0+XfOrM308_COUNT)
#     define SETUP_XfOrM309(x) SETUP_XfOrM308(x)
      graph = ((& (stx ) -> iso ) -> so . keyex & 0x1 ) ; 
      if ((& (stx ) -> iso ) -> so . keyex & 0x2 )
        lp = stx -> u . lazy_prefix + len ; 
      else lp = 0 ; 
      certs = stx -> certs ; 
      stx = (Scheme_Stx * ) FUNCCALL(SETUP_XfOrM309(_), scheme_make_stx (stx -> val , stx -> srcloc , stx -> props ) ); 
      stx -> wraps = owner_wraps ; 
      stx -> u . lazy_prefix = lp ; 
      stx -> certs = certs ; 
      if (graph )
        (& (stx ) -> iso ) -> so . keyex |= 0x1 ; 
      if (stx -> certs )
        FUNCCALL(SETUP_XfOrM309(_), phase_shift_certs ((Scheme_Object * ) stx , owner_wraps , len ) ); 
      RET_VALUE_START ((Scheme_Object * ) stx ) RET_VALUE_END ; 
    }
  }
  ml = * _ml ; 
  if (! ml ) {
#   define XfOrM307_COUNT (0+XfOrM298_COUNT)
#   define SETUP_XfOrM307(x) SETUP_XfOrM298(x)
    ml = FUNCCALL(SETUP_XfOrM307(_), make_chunk (len , owner_wraps ) ); 
    * _ml = ml ; 
  }
  if (((Scheme_Type ) (((((long ) (ml ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ml ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#   define XfOrM300_COUNT (0+XfOrM298_COUNT)
#   define SETUP_XfOrM300(x) SETUP_XfOrM298(x)
    while (((Scheme_Type ) (((((long ) (ml ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ml ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#     define XfOrM304_COUNT (0+XfOrM300_COUNT)
#     define SETUP_XfOrM304(x) SETUP_XfOrM300(x)
      a = (((Scheme_Simple_Object * ) (ml ) ) -> u . pair_val . car ) ; 
      if (((((long ) (a ) ) & 0x1 ) || ((((a ) -> type ) >= scheme_bignum_type ) && (((a ) -> type ) <= scheme_complex_type ) ) ) ) {
#       define XfOrM306_COUNT (0+XfOrM304_COUNT)
#       define SETUP_XfOrM306(x) SETUP_XfOrM304(x)
        o = FUNCCALL(SETUP_XfOrM306(_), scheme_add_remove_mark (o , a ) ); 
      }
      else {
#       define XfOrM305_COUNT (0+XfOrM304_COUNT)
#       define SETUP_XfOrM305(x) SETUP_XfOrM304(x)
        o = FUNCCALL(SETUP_XfOrM305(_), scheme_add_rename (o , a ) ); 
      }
      ml = (((Scheme_Simple_Object * ) (ml ) ) -> u . pair_val . cdr ) ; 
    }
  }
  else if (((((long ) (ml ) ) & 0x1 ) || ((((ml ) -> type ) >= scheme_bignum_type ) && (((ml ) -> type ) <= scheme_complex_type ) ) ) )
    o = FUNCCALL(SETUP_XfOrM298(_), scheme_add_remove_mark (o , ml ) ); 
  else if (((ml ) == (scheme_null ) ) ) {
  }
  else o = FUNCCALL(SETUP_XfOrM298(_), scheme_add_rename (o , ml ) ); 
  if (((Scheme_Stx * ) o ) -> certs )
    FUNCCALL(SETUP_XfOrM298(_), phase_shift_certs (o , owner_wraps , len ) ); 
  RET_VALUE_START (o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_stx_certified (Scheme_Object * stx , Scheme_Object * extra_certs , Scheme_Object * home_modidx , Scheme_Object * home_insp ) {
  Scheme_Cert * certs = ((Scheme_Cert * ) (((Scheme_Stx * ) stx ) -> certs ? (((Scheme_Type ) (((((long ) (((Scheme_Stx * ) stx ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) stx ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) (((Scheme_Stx * ) stx ) -> certs ) ) -> u . pair_val . car ) : ((Scheme_Stx * ) stx ) -> certs ) : ((void * ) 0 ) ) ) ; 
  Scheme_Object * cert_modidx , * a , * b ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(8);
  BLOCK_SETUP_TOP((PUSH(a, 0), PUSH(b, 1), PUSH(home_modidx, 2), PUSH(certs, 3), PUSH(stx, 4), PUSH(extra_certs, 5), PUSH(cert_modidx, 6), PUSH(home_insp, 7)));
# define XfOrM312_COUNT (8)
# define SETUP_XfOrM312(x) SETUP(XfOrM312_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  cert_modidx = NULLED_OUT ; 
  a = NULLED_OUT ; 
  b = NULLED_OUT ; 
  do {
#   define XfOrM323_COUNT (0+XfOrM312_COUNT)
#   define SETUP_XfOrM323(x) SETUP_XfOrM312(x)
    while (certs ) {
#     define XfOrM329_COUNT (0+XfOrM323_COUNT)
#     define SETUP_XfOrM329(x) SETUP_XfOrM323(x)
      if (! FUNCCALL(SETUP_XfOrM329(_), scheme_module_protected_wrt (home_insp , certs -> insp ) )) {
#       define XfOrM330_COUNT (0+XfOrM329_COUNT)
#       define SETUP_XfOrM330(x) SETUP_XfOrM329(x)
        if (home_modidx ) {
#         define XfOrM332_COUNT (0+XfOrM330_COUNT)
#         define SETUP_XfOrM332(x) SETUP_XfOrM330(x)
          if ((((certs -> modidx ) ) == (scheme_false ) ) )
            cert_modidx = home_modidx ; 
          else cert_modidx = certs -> modidx ; 
          a = FUNCCALL(SETUP_XfOrM332(_), scheme_module_resolve (home_modidx , 0 ) ); 
          b = FUNCCALL_AGAIN(scheme_module_resolve (cert_modidx , 0 ) ); 
        }
        else a = b = ((void * ) 0 ) ; 
        if (((a ) == (b ) ) ) {
#         define XfOrM331_COUNT (0+XfOrM330_COUNT)
#         define SETUP_XfOrM331(x) SETUP_XfOrM330(x)
          if (FUNCCALL(SETUP_XfOrM331(_), includes_mark (((Scheme_Stx * ) stx ) -> wraps , certs -> mark ) ))
            RET_VALUE_START (1 ) RET_VALUE_END ; 
        }
      }
      certs = certs -> next ; 
    }
    if (extra_certs ) {
      certs = (Scheme_Cert * ) extra_certs ; 
      extra_certs = ((void * ) 0 ) ; 
    }
  }
  while (certs ) ; 
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Cert * cons_cert (Scheme_Object * mark , Scheme_Object * modidx , Scheme_Object * insp , Scheme_Object * key , Scheme_Cert * next_cert ) {
  Scheme_Cert * cert ; 
  DECL_RET_SAVE (Scheme_Cert * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(cert, 0), PUSH(next_cert, 1), PUSH(modidx, 2), PUSH(key, 3), PUSH(insp, 4), PUSH(mark, 5)));
# define XfOrM333_COUNT (6)
# define SETUP_XfOrM333(x) SETUP(XfOrM333_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  cert = NULLED_OUT ; 
  cert = ((Scheme_Cert * ) FUNCCALL(SETUP_XfOrM333(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Cert ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  cert -> iso . so . type = scheme_certifications_type ; 
  cert -> mark = mark ; 
  cert -> modidx = modidx ; 
  cert -> insp = insp ; 
  cert -> key = key ; 
  cert -> next = next_cert ; 
  cert -> depth = (next_cert ? next_cert -> depth + 1 : 1 ) ; 
  if (! key && (! next_cert || ((& (next_cert ) -> iso ) -> so . keyex & 0x1 ) ) ) {
    ((& (cert ) -> iso ) -> so . keyex |= 0x1 ) ; 
  }
  RET_VALUE_START (cert ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void make_mapped (Scheme_Cert * cert ) ; 
static Scheme_Object * make_mapped_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Cert * cert = (Scheme_Cert * ) p -> ku . k . p1 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  make_mapped (cert ) ; 
  return scheme_void ; 
}
static void make_mapped (Scheme_Cert * cert ) {
  Scheme_Cert * stop ; 
  Scheme_Object * pr ; 
  Scheme_Hash_Table * ht ; 
  PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(ht, 0), PUSH(stop, 1), PUSH(pr, 2), PUSH(cert, 3)));
# define XfOrM336_COUNT (4)
# define SETUP_XfOrM336(x) SETUP(XfOrM336_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  stop = NULLED_OUT ; 
  pr = NULLED_OUT ; 
  ht = NULLED_OUT ; 
  {
    unsigned long _stk_pos ; 
#   define XfOrM345_COUNT (0+XfOrM336_COUNT)
#   define SETUP_XfOrM345(x) SETUP_XfOrM336(x)
    _stk_pos = (unsigned long ) & _stk_pos ; 
    if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
      Scheme_Thread * p = scheme_current_thread ; 
#     define XfOrM346_COUNT (0+XfOrM345_COUNT)
#     define SETUP_XfOrM346(x) SETUP_XfOrM345(x)
      p -> ku . k . p1 = (void * ) cert ; 
      FUNCCALL(SETUP_XfOrM346(_), scheme_handle_stack_overflow (make_mapped_k ) ); 
      RET_NOTHING ; 
    }
  }
  {
#   define XfOrM343_COUNT (0+XfOrM336_COUNT)
#   define SETUP_XfOrM343(x) SETUP_XfOrM336(x)
    if ((scheme_fuel_counter ) <= 0 ) {
#     define XfOrM344_COUNT (0+XfOrM343_COUNT)
#     define SETUP_XfOrM344(x) SETUP_XfOrM343(x)
      FUNCCALL(SETUP_XfOrM344(_), scheme_out_of_fuel () ); 
    }
  }
  ; 
  if (cert -> mapped )
    RET_NOTHING ; 
  if (cert -> depth == 16 ) {
    stop = ((void * ) 0 ) ; 
  }
  else {
#   define XfOrM339_COUNT (0+XfOrM336_COUNT)
#   define SETUP_XfOrM339(x) SETUP_XfOrM336(x)
    for (stop = cert -> next ; stop && ((stop -> depth & cert -> depth ) != stop -> depth ) ; stop = stop -> next ) {
    }
    if (stop )
      FUNCCALL(SETUP_XfOrM339(_), make_mapped (stop ) ); 
  }
  ht = FUNCCALL(SETUP_XfOrM336(_), scheme_make_hash_table_equal () ); 
  pr = FUNCCALL(SETUP_XfOrM336(_), scheme_make_raw_pair ((Scheme_Object * ) ht , (Scheme_Object * ) stop ) ); 
  cert -> mapped = pr ; 
  for (; cert != stop ; cert = cert -> next ) {
#   define XfOrM338_COUNT (0+XfOrM336_COUNT)
#   define SETUP_XfOrM338(x) SETUP_XfOrM336(x)
    if (cert -> key )
      pr = FUNCCALL(SETUP_XfOrM338(_), scheme_make_pair (cert -> mark , cert -> key ) ); 
    else pr = cert -> mark ; 
    FUNCCALL(SETUP_XfOrM338(_), scheme_hash_set_atomic (ht , pr , scheme_true ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int cert_in_chain (Scheme_Object * mark , Scheme_Object * key , Scheme_Cert * cert ) {
  Scheme_Object * hkey = key ? ((void * ) 0 ) : mark ; 
  Scheme_Hash_Table * ht ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(cert, 0), PUSH(mark, 1), PUSH(key, 2), PUSH(hkey, 3), PUSH(ht, 4)));
# define XfOrM347_COUNT (5)
# define SETUP_XfOrM347(x) SETUP(XfOrM347_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ht = NULLED_OUT ; 
  while (cert ) {
#   define XfOrM351_COUNT (0+XfOrM347_COUNT)
#   define SETUP_XfOrM351(x) SETUP_XfOrM347(x)
    if (! (cert -> depth & 0xF ) ) {
#     define XfOrM353_COUNT (0+XfOrM351_COUNT)
#     define SETUP_XfOrM353(x) SETUP_XfOrM351(x)
      FUNCCALL(SETUP_XfOrM353(_), make_mapped (cert ) ); 
      ht = (Scheme_Hash_Table * ) (((Scheme_Simple_Object * ) (cert -> mapped ) ) -> u . pair_val . car ) ; 
      cert = (Scheme_Cert * ) (((Scheme_Simple_Object * ) (cert -> mapped ) ) -> u . pair_val . cdr ) ; 
      if (! hkey )
        hkey = FUNCCALL(SETUP_XfOrM353(_), scheme_make_pair (mark , key ) ); 
      if (FUNCCALL(SETUP_XfOrM353(_), scheme_hash_get_atomic (ht , hkey ) ))
        RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
    else if (((cert -> mark ) == (mark ) ) && ((cert -> key ) == (key ) ) ) {
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
    else cert = cert -> next ; 
  }
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Cert * append_certs (Scheme_Cert * a , Scheme_Cert * b ) {
  DECL_RET_SAVE (Scheme_Cert * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(a, 0), PUSH(b, 1)));
# define XfOrM354_COUNT (2)
# define SETUP_XfOrM354(x) SETUP(XfOrM354_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! a )
    RET_VALUE_START (b ) RET_VALUE_END ; 
  if (! b )
    RET_VALUE_START (a ) RET_VALUE_END ; 
  if (a -> depth < b -> depth ) {
    Scheme_Cert * c = a ; 
    a = b ; 
    b = c ; 
  }
  for (; b ; b = b -> next ) {
#   define XfOrM356_COUNT (0+XfOrM354_COUNT)
#   define SETUP_XfOrM356(x) SETUP_XfOrM354(x)
    if (! FUNCCALL(SETUP_XfOrM356(_), cert_in_chain (b -> mark , b -> key , a ) ))
      a = FUNCCALL(SETUP_XfOrM356(_), cons_cert (b -> mark , b -> modidx , b -> insp , b -> key , a ) ); 
  }
  RET_VALUE_START (a ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * add_certs (Scheme_Object * o , Scheme_Cert * certs , Scheme_Object * use_key , int active ) {
  Scheme_Cert * orig_certs , * cl , * now_certs , * next_certs ; 
  Scheme_Stx * stx = (Scheme_Stx * ) o , * res ; 
  Scheme_Object * pr ; 
  int copy_on_write ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(9);
  BLOCK_SETUP_TOP((PUSH(use_key, 0), PUSH(res, 1), PUSH(next_certs, 2), PUSH(pr, 3), PUSH(orig_certs, 4), PUSH(certs, 5), PUSH(stx, 6), PUSH(cl, 7), PUSH(now_certs, 8)));
# define XfOrM358_COUNT (9)
# define SETUP_XfOrM358(x) SETUP(XfOrM358_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  orig_certs = NULLED_OUT ; 
  cl = NULLED_OUT ; 
  now_certs = NULLED_OUT ; 
  next_certs = NULLED_OUT ; 
  res = NULLED_OUT ; 
  pr = NULLED_OUT ; 
  if (! stx -> certs ) {
#   define XfOrM375_COUNT (0+XfOrM358_COUNT)
#   define SETUP_XfOrM375(x) SETUP_XfOrM358(x)
    if (! certs )
      RET_VALUE_START ((Scheme_Object * ) stx ) RET_VALUE_END ; 
    if (use_key ) {
      for (cl = certs ; cl ; cl = cl -> next ) {
        if (! ((cl -> key ) == (use_key ) ) )
          break ; 
      }
    }
    else cl = ((void * ) 0 ) ; 
    if (! cl ) {
#     define XfOrM376_COUNT (0+XfOrM375_COUNT)
#     define SETUP_XfOrM376(x) SETUP_XfOrM375(x)
      res = (Scheme_Stx * ) FUNCCALL(SETUP_XfOrM376(_), scheme_make_stx (stx -> val , stx -> srcloc , stx -> props ) ); 
      res -> wraps = stx -> wraps ; 
      res -> u . lazy_prefix = stx -> u . lazy_prefix ; 
      if (active )
        res -> certs = (Scheme_Object * ) certs ; 
      else {
#       define XfOrM377_COUNT (0+XfOrM376_COUNT)
#       define SETUP_XfOrM377(x) SETUP_XfOrM376(x)
        pr = FUNCCALL(SETUP_XfOrM377(_), scheme_make_raw_pair (((void * ) 0 ) , (Scheme_Object * ) certs ) ); 
        res -> certs = pr ; 
      }
      RET_VALUE_START ((Scheme_Object * ) res ) RET_VALUE_END ; 
    }
  }
  copy_on_write = 1 ; 
  if (active )
    orig_certs = ((Scheme_Cert * ) ((stx ) -> certs ? (((Scheme_Type ) (((((long ) ((stx ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((stx ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) ((stx ) -> certs ) ) -> u . pair_val . car ) : (stx ) -> certs ) : ((void * ) 0 ) ) ) ; 
  else orig_certs = ((Scheme_Cert * ) ((stx ) -> certs ? (((Scheme_Type ) (((((long ) ((stx ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((stx ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) ((stx ) -> certs ) ) -> u . pair_val . cdr ) : ((void * ) 0 ) ) : ((void * ) 0 ) ) ) ; 
  now_certs = orig_certs ; 
  for (; certs ; certs = next_certs ) {
#   define XfOrM367_COUNT (0+XfOrM358_COUNT)
#   define SETUP_XfOrM367(x) SETUP_XfOrM358(x)
    next_certs = certs -> next ; 
    if (! FUNCCALL(SETUP_XfOrM367(_), cert_in_chain (certs -> mark , use_key , now_certs ) )) {
#     define XfOrM368_COUNT (0+XfOrM367_COUNT)
#     define SETUP_XfOrM368(x) SETUP_XfOrM367(x)
      if (copy_on_write ) {
#       define XfOrM372_COUNT (0+XfOrM368_COUNT)
#       define SETUP_XfOrM372(x) SETUP_XfOrM368(x)
        res = (Scheme_Stx * ) FUNCCALL(SETUP_XfOrM372(_), scheme_make_stx (stx -> val , stx -> srcloc , stx -> props ) ); 
        res -> wraps = stx -> wraps ; 
        res -> u . lazy_prefix = stx -> u . lazy_prefix ; 
        if (! active ) {
#         define XfOrM374_COUNT (0+XfOrM372_COUNT)
#         define SETUP_XfOrM374(x) SETUP_XfOrM372(x)
          pr = FUNCCALL(SETUP_XfOrM374(_), scheme_make_raw_pair ((Scheme_Object * ) ((Scheme_Cert * ) ((stx ) -> certs ? (((Scheme_Type ) (((((long ) ((stx ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((stx ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) ((stx ) -> certs ) ) -> u . pair_val . car ) : (stx ) -> certs ) : ((void * ) 0 ) ) ) , (Scheme_Object * ) orig_certs ) ); 
          res -> certs = pr ; 
        }
        else if (stx -> certs && ((Scheme_Type ) (((((long ) (stx -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (stx -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ) {
#         define XfOrM373_COUNT (0+XfOrM372_COUNT)
#         define SETUP_XfOrM373(x) SETUP_XfOrM372(x)
          pr = FUNCCALL(SETUP_XfOrM373(_), scheme_make_raw_pair ((Scheme_Object * ) orig_certs , (((Scheme_Simple_Object * ) (stx -> certs ) ) -> u . pair_val . cdr ) ) ); 
          res -> certs = pr ; 
        }
        else res -> certs = (Scheme_Object * ) orig_certs ; 
        stx = res ; 
        copy_on_write = 0 ; 
      }
      if (! now_certs && ! use_key && ((& (certs ) -> iso ) -> so . keyex & 0x1 ) ) {
        cl = certs ; 
        next_certs = ((void * ) 0 ) ; 
      }
      else {
#       define XfOrM370_COUNT (0+XfOrM368_COUNT)
#       define SETUP_XfOrM370(x) SETUP_XfOrM368(x)
        cl = FUNCCALL(SETUP_XfOrM370(_), cons_cert (certs -> mark , certs -> modidx , certs -> insp , use_key , active ? ((Scheme_Cert * ) ((stx ) -> certs ? (((Scheme_Type ) (((((long ) ((stx ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((stx ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) ((stx ) -> certs ) ) -> u . pair_val . car ) : (stx ) -> certs ) : ((void * ) 0 ) ) ) : ((Scheme_Cert * ) ((stx ) -> certs ? (((Scheme_Type ) (((((long ) ((stx ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((stx ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) ((stx ) -> certs ) ) -> u . pair_val . cdr ) : ((void * ) 0 ) ) : ((void * ) 0 ) ) ) ) ); 
      }
      now_certs = cl ; 
      if (! active ) {
        (((Scheme_Simple_Object * ) (stx -> certs ) ) -> u . pair_val . cdr ) = (Scheme_Object * ) cl ; 
      }
      else if (stx -> certs && ((Scheme_Type ) (((((long ) (stx -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (stx -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) )
        (((Scheme_Simple_Object * ) (stx -> certs ) ) -> u . pair_val . car ) = (Scheme_Object * ) cl ; 
      else stx -> certs = (Scheme_Object * ) cl ; 
    }
  }
  RET_VALUE_START ((Scheme_Object * ) stx ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_stx_add_inactive_certs (Scheme_Object * o , Scheme_Object * certs ) {
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(certs, 0), PUSH(o, 1)));
# define XfOrM381_COUNT (2)
# define SETUP_XfOrM381(x) SETUP(XfOrM381_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  o = FUNCCALL(SETUP_XfOrM381(_), lift_inactive_certs (o , 0 ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(add_certs (o , (Scheme_Cert * ) certs , ((void * ) 0 ) , 0 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_stx_propagate_inactive_certs (Scheme_Object * o , Scheme_Object * orig ) {
  /* No conversion */
  Scheme_Cert * certs ; 
  certs = ((Scheme_Cert * ) (((Scheme_Stx * ) orig ) -> certs ? (((Scheme_Type ) (((((long ) (((Scheme_Stx * ) orig ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) orig ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) (((Scheme_Stx * ) orig ) -> certs ) ) -> u . pair_val . cdr ) : ((void * ) 0 ) ) : ((void * ) 0 ) ) ) ; 
  if (certs )
    return scheme_stx_add_inactive_certs (o , (Scheme_Object * ) certs ) ; 
  else return o ; 
}
Scheme_Object * scheme_stx_extract_certs (Scheme_Object * o , Scheme_Object * base_certs ) {
  /* No conversion */
  return (Scheme_Object * ) append_certs ((Scheme_Cert * ) base_certs , ((Scheme_Cert * ) (((Scheme_Stx * ) o ) -> certs ? (((Scheme_Type ) (((((long ) (((Scheme_Stx * ) o ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) o ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) (((Scheme_Stx * ) o ) -> certs ) ) -> u . pair_val . car ) : ((Scheme_Stx * ) o ) -> certs ) : ((void * ) 0 ) ) ) ) ; 
}
Scheme_Object * scheme_stx_cert (Scheme_Object * o , Scheme_Object * mark , Scheme_Env * menv , Scheme_Object * plus_stx_or_certs , Scheme_Object * key , int active ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(9);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(mark, 1), PUSH(menv, 2), PUSH(key, 3), PUSH(plus_stx_or_certs, 4)));
# define XfOrM384_COUNT (5)
# define SETUP_XfOrM384(x) SETUP(XfOrM384_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (mark && active ) {
#   define XfOrM393_COUNT (0+XfOrM384_COUNT)
#   define SETUP_XfOrM393(x) SETUP_XfOrM384(x)
    o = FUNCCALL(SETUP_XfOrM393(_), scheme_stx_activate_certs (o ) ); 
  }
  if (plus_stx_or_certs ) {
    Scheme_Cert * certs ; 
    BLOCK_SETUP((PUSH(certs, 0+XfOrM384_COUNT)));
#   define XfOrM390_COUNT (1+XfOrM384_COUNT)
#   define SETUP_XfOrM390(x) SETUP(XfOrM390_COUNT)
    certs = NULLED_OUT ; 
    if (((Scheme_Type ) (((((long ) (plus_stx_or_certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (plus_stx_or_certs ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
      certs = ((Scheme_Cert * ) (((Scheme_Stx * ) plus_stx_or_certs ) -> certs ? (((Scheme_Type ) (((((long ) (((Scheme_Stx * ) plus_stx_or_certs ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) plus_stx_or_certs ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) (((Scheme_Stx * ) plus_stx_or_certs ) -> certs ) ) -> u . pair_val . car ) : ((Scheme_Stx * ) plus_stx_or_certs ) -> certs ) : ((void * ) 0 ) ) ) ; 
    else certs = (Scheme_Cert * ) plus_stx_or_certs ; 
    if (certs ) {
#     define XfOrM392_COUNT (0+XfOrM390_COUNT)
#     define SETUP_XfOrM392(x) SETUP_XfOrM390(x)
      if (! active )
        o = FUNCCALL(SETUP_XfOrM392(_), lift_inactive_certs (o , 0 ) ); 
      o = FUNCCALL(SETUP_XfOrM392(_), add_certs (o , certs , key , active ) ); 
    }
    if (((Scheme_Type ) (((((long ) (plus_stx_or_certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (plus_stx_or_certs ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ) {
#     define XfOrM391_COUNT (0+XfOrM390_COUNT)
#     define SETUP_XfOrM391(x) SETUP_XfOrM390(x)
      o = FUNCCALL(SETUP_XfOrM391(_), lift_inactive_certs (o , 0 ) ); 
      o = FUNCCALL(SETUP_XfOrM391(_), add_certs (o , ((Scheme_Cert * ) (((Scheme_Stx * ) plus_stx_or_certs ) -> certs ? (((Scheme_Type ) (((((long ) (((Scheme_Stx * ) plus_stx_or_certs ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) plus_stx_or_certs ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) (((Scheme_Stx * ) plus_stx_or_certs ) -> certs ) ) -> u . pair_val . cdr ) : ((void * ) 0 ) ) : ((void * ) 0 ) ) ) , key , 0 ) ); 
    }
  }
  if (menv && ! menv -> module -> no_cert ) {
    Scheme_Stx * stx = (Scheme_Stx * ) o , * res ; 
    Scheme_Cert * cert ; 
    BLOCK_SETUP((PUSH(stx, 0+XfOrM384_COUNT), PUSH(res, 1+XfOrM384_COUNT), PUSH(cert, 2+XfOrM384_COUNT)));
#   define XfOrM385_COUNT (3+XfOrM384_COUNT)
#   define SETUP_XfOrM385(x) SETUP(XfOrM385_COUNT)
    res = NULLED_OUT ; 
    cert = NULLED_OUT ; 
    res = (Scheme_Stx * ) FUNCCALL(SETUP_XfOrM385(_), scheme_make_stx (stx -> val , stx -> srcloc , stx -> props ) ); 
    res -> wraps = stx -> wraps ; 
    res -> u . lazy_prefix = stx -> u . lazy_prefix ; 
    if ((((mark ) ) == (scheme_false ) ) ) {
#     define XfOrM389_COUNT (0+XfOrM385_COUNT)
#     define SETUP_XfOrM389(x) SETUP_XfOrM385(x)
      mark = FUNCCALL(SETUP_XfOrM389(_), scheme_new_mark () ); 
      mark = FUNCCALL(SETUP_XfOrM389(_), negate_mark (mark ) ); 
      res = (Scheme_Stx * ) FUNCCALL(SETUP_XfOrM389(_), scheme_add_remove_mark ((Scheme_Object * ) res , mark ) ); 
    }
    if (active )
      cert = ((Scheme_Cert * ) ((stx ) -> certs ? (((Scheme_Type ) (((((long ) ((stx ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((stx ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) ((stx ) -> certs ) ) -> u . pair_val . car ) : (stx ) -> certs ) : ((void * ) 0 ) ) ) ; 
    else cert = ((Scheme_Cert * ) ((stx ) -> certs ? (((Scheme_Type ) (((((long ) ((stx ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((stx ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) ((stx ) -> certs ) ) -> u . pair_val . cdr ) : ((void * ) 0 ) ) : ((void * ) 0 ) ) ) ; 
    cert = FUNCCALL(SETUP_XfOrM385(_), cons_cert (mark , menv -> link_midx ? menv -> link_midx : menv -> module -> me -> src_modidx , menv -> module -> insp , key , cert ) ); 
    if (active ) {
#     define XfOrM387_COUNT (0+XfOrM385_COUNT)
#     define SETUP_XfOrM387(x) SETUP_XfOrM385(x)
      if (stx -> certs && ((Scheme_Type ) (((((long ) (stx -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (stx -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ) {
        Scheme_Object * pr ; 
        BLOCK_SETUP((PUSH(pr, 0+XfOrM387_COUNT)));
#       define XfOrM388_COUNT (1+XfOrM387_COUNT)
#       define SETUP_XfOrM388(x) SETUP(XfOrM388_COUNT)
        pr = NULLED_OUT ; 
        pr = FUNCCALL(SETUP_XfOrM388(_), scheme_make_raw_pair ((Scheme_Object * ) cert , (((Scheme_Simple_Object * ) (stx -> certs ) ) -> u . pair_val . cdr ) ) ); 
        res -> certs = pr ; 
      }
      else res -> certs = (Scheme_Object * ) cert ; 
    }
    else {
      Scheme_Object * pr ; 
      BLOCK_SETUP((PUSH(pr, 0+XfOrM385_COUNT)));
#     define XfOrM386_COUNT (1+XfOrM385_COUNT)
#     define SETUP_XfOrM386(x) SETUP(XfOrM386_COUNT)
      pr = NULLED_OUT ; 
      pr = FUNCCALL(SETUP_XfOrM386(_), scheme_make_raw_pair ((Scheme_Object * ) ((Scheme_Cert * ) ((stx ) -> certs ? (((Scheme_Type ) (((((long ) ((stx ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((stx ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) ((stx ) -> certs ) ) -> u . pair_val . car ) : (stx ) -> certs ) : ((void * ) 0 ) ) ) , (Scheme_Object * ) cert ) ); 
      res -> certs = pr ; 
    }
    o = (Scheme_Object * ) res ; 
  }
  RET_VALUE_START (o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_stx_content (Scheme_Object * o ) {
  Scheme_Stx * stx = (Scheme_Stx * ) o ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(stx, 0)));
# define XfOrM394_COUNT (1)
# define SETUP_XfOrM394(x) SETUP(XfOrM394_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (((& (stx ) -> iso ) -> so . keyex & 0x2 ) && stx -> u . lazy_prefix ) {
    Scheme_Object * v = stx -> val , * result ; 
    Scheme_Object * here_wraps ; 
    Scheme_Object * ml = ((void * ) 0 ) ; 
    int wl_count = 0 ; 
    BLOCK_SETUP((PUSH(v, 0+XfOrM394_COUNT), PUSH(here_wraps, 1+XfOrM394_COUNT), PUSH(ml, 2+XfOrM394_COUNT), PUSH(result, 3+XfOrM394_COUNT)));
#   define XfOrM395_COUNT (4+XfOrM394_COUNT)
#   define SETUP_XfOrM395(x) SETUP(XfOrM395_COUNT)
    result = NULLED_OUT ; 
    here_wraps = NULLED_OUT ; 
    here_wraps = stx -> wraps ; 
    wl_count = stx -> u . lazy_prefix ; 
    stx -> u . lazy_prefix = 0 ; 
    if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
      Scheme_Object * last = ((void * ) 0 ) , * first = ((void * ) 0 ) ; 
      BLOCK_SETUP((PUSH(first, 0+XfOrM395_COUNT), PUSH(last, 1+XfOrM395_COUNT)));
#     define XfOrM400_COUNT (2+XfOrM395_COUNT)
#     define SETUP_XfOrM400(x) SETUP(XfOrM400_COUNT)
      while (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
        Scheme_Object * p ; 
        BLOCK_SETUP((PUSH(p, 0+XfOrM400_COUNT)));
#       define XfOrM403_COUNT (1+XfOrM400_COUNT)
#       define SETUP_XfOrM403(x) SETUP(XfOrM403_COUNT)
        p = NULLED_OUT ; 
        result = FUNCCALL(SETUP_XfOrM403(_), propagate_wraps ((((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) , wl_count , & ml , here_wraps ) ); 
        p = FUNCCALL_AGAIN(scheme_make_immutable_pair (result , scheme_null ) ); 
        if (last )
          (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = p ; 
        else first = p ; 
        last = p ; 
        v = (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) ; 
      }
      if (! ((v ) == (scheme_null ) ) ) {
#       define XfOrM401_COUNT (0+XfOrM400_COUNT)
#       define SETUP_XfOrM401(x) SETUP_XfOrM400(x)
        result = FUNCCALL(SETUP_XfOrM401(_), propagate_wraps (v , wl_count , & ml , here_wraps ) ); 
        if (last )
          (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = result ; 
        else first = result ; 
      }
      v = first ; 
    }
    else if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) {
#     define XfOrM399_COUNT (0+XfOrM395_COUNT)
#     define SETUP_XfOrM399(x) SETUP_XfOrM395(x)
      result = FUNCCALL(SETUP_XfOrM399(_), propagate_wraps ((((Scheme_Small_Object * ) (v ) ) -> u . ptr_val ) , wl_count , & ml , here_wraps ) ); 
      v = FUNCCALL(SETUP_XfOrM399(_), scheme_box (result ) ); 
    }
    else if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
      Scheme_Object * v2 ; 
      int size = (((Scheme_Vector * ) (v ) ) -> size ) , i ; 
      BLOCK_SETUP((PUSH(v2, 0+XfOrM395_COUNT)));
#     define XfOrM396_COUNT (1+XfOrM395_COUNT)
#     define SETUP_XfOrM396(x) SETUP(XfOrM396_COUNT)
      v2 = NULLED_OUT ; 
      v2 = FUNCCALL(SETUP_XfOrM396(_), scheme_make_vector (size , ((void * ) 0 ) ) ); 
      for (i = 0 ; i < size ; i ++ ) {
#       define XfOrM398_COUNT (0+XfOrM396_COUNT)
#       define SETUP_XfOrM398(x) SETUP_XfOrM396(x)
        result = FUNCCALL(SETUP_XfOrM398(_), propagate_wraps ((((Scheme_Vector * ) (v ) ) -> els ) [i ] , wl_count , & ml , here_wraps ) ); 
        (((Scheme_Vector * ) (v2 ) ) -> els ) [i ] = result ; 
      }
      v = v2 ; 
    }
    stx -> val = v ; 
  }
  RET_VALUE_START (stx -> val ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_stx_extract_marks (Scheme_Object * stx ) {
  Wrap_Pos awl ; 
  Scheme_Object * acur_mark , * first = scheme_null , * last = ((void * ) 0 ) , * p ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(first, 0), PUSH(awl.l, 1), PUSH(awl.a, 2), PUSH(acur_mark, 3), PUSH(p, 4), PUSH(last, 5)));
# define XfOrM404_COUNT (6)
# define SETUP_XfOrM404(x) SETUP(XfOrM404_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  awl.l = NULLED_OUT ; 
  awl.a = NULLED_OUT ; 
  acur_mark = NULLED_OUT ; 
  p = NULLED_OUT ; 
  awl . l = ((Scheme_Stx * ) stx ) -> wraps ; 
  (WRAP_POS_SET_FIRST (& awl ) ) ; 
  while (1 ) {
#   define XfOrM419_COUNT (0+XfOrM404_COUNT)
#   define SETUP_XfOrM419(x) SETUP_XfOrM404(x)
    acur_mark = ((void * ) 0 ) ; 
    while (1 ) {
#     define XfOrM427_COUNT (0+XfOrM419_COUNT)
#     define SETUP_XfOrM427(x) SETUP_XfOrM419(x)
      if (((awl . l ) == (scheme_null ) ) )
        break ; 
      p = awl . a ; 
      if (((((long ) (p ) ) & 0x1 ) || ((((p ) -> type ) >= scheme_bignum_type ) && (((p ) -> type ) <= scheme_complex_type ) ) ) && ((((long ) (p ) ) & 0x1 ) ? ((((long ) (p ) ) >> 1 ) >= 0 ) : ((& ((Scheme_Bignum * ) p ) -> iso ) -> so . keyex & 0x1 ) ) ) {
#       define XfOrM429_COUNT (0+XfOrM427_COUNT)
#       define SETUP_XfOrM429(x) SETUP_XfOrM427(x)
        if (acur_mark ) {
#         define XfOrM431_COUNT (0+XfOrM429_COUNT)
#         define SETUP_XfOrM431(x) SETUP_XfOrM429(x)
          if (((acur_mark ) == (p ) ) ) {
#           define XfOrM432_COUNT (0+XfOrM431_COUNT)
#           define SETUP_XfOrM432(x) SETUP_XfOrM431(x)
            acur_mark = ((void * ) 0 ) ; 
            (DO_WRAP_POS_INC (& awl ) ) ; 
          }
          else break ; 
        }
        else {
#         define XfOrM430_COUNT (0+XfOrM429_COUNT)
#         define SETUP_XfOrM430(x) SETUP_XfOrM429(x)
          acur_mark = p ; 
          (DO_WRAP_POS_INC (& awl ) ) ; 
        }
      }
      else {
#       define XfOrM428_COUNT (0+XfOrM427_COUNT)
#       define SETUP_XfOrM428(x) SETUP_XfOrM427(x)
        (DO_WRAP_POS_INC (& awl ) ) ; 
      }
    }
    if (acur_mark ) {
#     define XfOrM420_COUNT (0+XfOrM419_COUNT)
#     define SETUP_XfOrM420(x) SETUP_XfOrM419(x)
      p = FUNCCALL(SETUP_XfOrM420(_), scheme_make_pair (acur_mark , scheme_null ) ); 
      if (! last )
        first = p ; 
      else (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = p ; 
      last = p ; 
    }
    if (((awl . l ) == (scheme_null ) ) )
      RET_VALUE_START (first ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_stx_strip_module_context (Scheme_Object * _stx ) {
  Scheme_Stx * stx = (Scheme_Stx * ) _stx ; 
  Wrap_Pos awl ; 
  int mod_ctx_count = 0 , skipped = 0 ; 
  Scheme_Object * v ; 
  Wrap_Chunk * chunk ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(stx, 0), PUSH(v, 1), PUSH(awl.l, 2), PUSH(awl.a, 3), PUSH(chunk, 4)));
# define XfOrM433_COUNT (5)
# define SETUP_XfOrM433(x) SETUP(XfOrM433_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  awl.l = NULLED_OUT ; 
  awl.a = NULLED_OUT ; 
  v = NULLED_OUT ; 
  chunk = NULLED_OUT ; 
  awl . l = stx -> wraps ; 
  (WRAP_POS_SET_FIRST (& awl ) ) ; 
  while (! ((awl . l ) == (scheme_null ) ) ) {
#   define XfOrM442_COUNT (0+XfOrM433_COUNT)
#   define SETUP_XfOrM442(x) SETUP_XfOrM433(x)
    v = awl . a ; 
    if ((((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_rename_table_type ) ) ) || ((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) {
      mod_ctx_count ++ ; 
    }
    (DO_WRAP_POS_INC (& awl ) ) ; 
    skipped ++ ; 
  }
  if (! mod_ctx_count )
    RET_VALUE_START (_stx ) RET_VALUE_END ; 
  if (mod_ctx_count == skipped ) {
#   define XfOrM439_COUNT (0+XfOrM433_COUNT)
#   define SETUP_XfOrM439(x) SETUP_XfOrM433(x)
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM439(_), scheme_make_stx (stx -> val , stx -> srcloc , stx -> props ) )) RET_VALUE_END ; 
  }
  else {
#   define XfOrM434_COUNT (0+XfOrM433_COUNT)
#   define SETUP_XfOrM434(x) SETUP_XfOrM433(x)
    chunk = (Wrap_Chunk * ) FUNCCALL(SETUP_XfOrM434(_), GC_malloc_one_tagged (sizeof (Wrap_Chunk ) + (((skipped - mod_ctx_count ) - 1 ) * sizeof (Scheme_Object * ) ) ) ); 
    chunk -> type = scheme_wrap_chunk_type ; 
    chunk -> len = skipped - mod_ctx_count ; 
    skipped = 0 ; 
    awl . l = stx -> wraps ; 
    (WRAP_POS_SET_FIRST (& awl ) ) ; 
    while (! ((awl . l ) == (scheme_null ) ) ) {
#     define XfOrM437_COUNT (0+XfOrM434_COUNT)
#     define SETUP_XfOrM437(x) SETUP_XfOrM434(x)
      v = awl . a ; 
      if (! (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_rename_table_type ) ) ) && ! ((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) {
        chunk -> a [skipped ] = v ; 
        skipped ++ ; 
      }
      (DO_WRAP_POS_INC (& awl ) ) ; 
    }
    stx = (Scheme_Stx * ) FUNCCALL(SETUP_XfOrM434(_), scheme_make_stx (stx -> val , stx -> srcloc , stx -> props ) ); 
    v = FUNCCALL(SETUP_XfOrM434(_), scheme_make_pair ((Scheme_Object * ) chunk , scheme_null ) ); 
    stx -> wraps = v ; 
    RET_VALUE_START ((Scheme_Object * ) stx ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * stx_activate_certs_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * o = (Scheme_Object * ) p -> ku . k . p1 ; 
  Scheme_Cert * * cp = (Scheme_Cert * * ) p -> ku . k . p2 ; 
  Scheme_Hash_Table * * ht = (Scheme_Hash_Table * * ) p -> ku . k . p3 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  p -> ku . k . p2 = ((void * ) 0 ) ; 
  p -> ku . k . p3 = ((void * ) 0 ) ; 
  return stx_activate_certs (o , cp , ht ) ; 
}
static Scheme_Object * stx_activate_certs (Scheme_Object * o , Scheme_Cert * * cp , Scheme_Hash_Table * * ht ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(cp, 1), PUSH(ht, 2)));
# define XfOrM445_COUNT (3)
# define SETUP_XfOrM445(x) SETUP(XfOrM445_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  {
    unsigned long _stk_pos ; 
#   define XfOrM473_COUNT (0+XfOrM445_COUNT)
#   define SETUP_XfOrM473(x) SETUP_XfOrM445(x)
    _stk_pos = (unsigned long ) & _stk_pos ; 
    if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
      Scheme_Thread * p = scheme_current_thread ; 
      Scheme_Cert * * _cp ; 
      Scheme_Hash_Table * * _ht ; 
      BLOCK_SETUP((PUSH(_ht, 0+XfOrM473_COUNT), PUSH(_cp, 1+XfOrM473_COUNT), PUSH(p, 2+XfOrM473_COUNT)));
#     define XfOrM474_COUNT (3+XfOrM473_COUNT)
#     define SETUP_XfOrM474(x) SETUP(XfOrM474_COUNT)
      _cp = NULLED_OUT ; 
      _ht = NULLED_OUT ; 
      _cp = ((Scheme_Cert * * ) FUNCCALL(SETUP_XfOrM474(_), GC_malloc (sizeof (Scheme_Cert * ) * (1 ) ) )) ; 
      _ht = ((Scheme_Hash_Table * * ) FUNCCALL(SETUP_XfOrM474(_), GC_malloc (sizeof (Scheme_Hash_Table * ) * (1 ) ) )) ; 
      * _cp = * cp ; 
      * _ht = * ht ; 
      p -> ku . k . p1 = (void * ) o ; 
      p -> ku . k . p2 = (void * ) _cp ; 
      p -> ku . k . p3 = (void * ) _ht ; 
      o = FUNCCALL(SETUP_XfOrM474(_), scheme_handle_stack_overflow (stx_activate_certs_k ) ); 
      * cp = * _cp ; 
      * ht = * _ht ; 
      RET_VALUE_START (o ) RET_VALUE_END ; 
    }
  }
  {
#   define XfOrM471_COUNT (0+XfOrM445_COUNT)
#   define SETUP_XfOrM471(x) SETUP_XfOrM445(x)
    if ((scheme_fuel_counter ) <= 0 ) {
#     define XfOrM472_COUNT (0+XfOrM471_COUNT)
#     define SETUP_XfOrM472(x) SETUP_XfOrM471(x)
      FUNCCALL(SETUP_XfOrM472(_), scheme_out_of_fuel () ); 
    }
  }
  ; 
  if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
    Scheme_Object * a , * d ; 
    BLOCK_SETUP((PUSH(a, 0+XfOrM445_COUNT), PUSH(d, 1+XfOrM445_COUNT)));
#   define XfOrM470_COUNT (2+XfOrM445_COUNT)
#   define SETUP_XfOrM470(x) SETUP(XfOrM470_COUNT)
    a = NULLED_OUT ; 
    d = NULLED_OUT ; 
    a = FUNCCALL(SETUP_XfOrM470(_), stx_activate_certs ((((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . car ) , cp , ht ) ); 
    d = FUNCCALL_AGAIN(stx_activate_certs ((((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . cdr ) , cp , ht ) ); 
    if (((a ) == ((((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . car ) ) ) && ((d ) == ((((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . cdr ) ) ) )
      RET_VALUE_START (o ) RET_VALUE_END ; 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_immutable_pair (a , d ) )) RET_VALUE_EMPTY_END ; 
  }
  else if (((o ) == (scheme_null ) ) ) {
    RET_VALUE_START (o ) RET_VALUE_END ; 
  }
  else if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) {
    Scheme_Object * c ; 
    BLOCK_SETUP((PUSH(c, 0+XfOrM445_COUNT)));
#   define XfOrM468_COUNT (1+XfOrM445_COUNT)
#   define SETUP_XfOrM468(x) SETUP(XfOrM468_COUNT)
    c = NULLED_OUT ; 
    c = FUNCCALL(SETUP_XfOrM468(_), stx_activate_certs ((((Scheme_Small_Object * ) (o ) ) -> u . ptr_val ) , cp , ht ) ); 
    if (((c ) == ((((Scheme_Small_Object * ) (o ) ) -> u . ptr_val ) ) ) )
      RET_VALUE_START (o ) RET_VALUE_END ; 
    o = FUNCCALL(SETUP_XfOrM468(_), scheme_box (c ) ); 
    ((((Scheme_Inclhash_Object * ) (o ) ) -> so . keyex |= 0x1 ) ) ; 
    RET_VALUE_START (o ) RET_VALUE_END ; 
  }
  else if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
    Scheme_Object * e = ((void * ) 0 ) , * v2 ; 
    int size = (((Scheme_Vector * ) (o ) ) -> size ) , i , j ; 
    BLOCK_SETUP((PUSH(v2, 0+XfOrM445_COUNT), PUSH(e, 1+XfOrM445_COUNT)));
#   define XfOrM461_COUNT (2+XfOrM445_COUNT)
#   define SETUP_XfOrM461(x) SETUP(XfOrM461_COUNT)
    v2 = NULLED_OUT ; 
    for (i = 0 ; i < size ; i ++ ) {
#     define XfOrM467_COUNT (0+XfOrM461_COUNT)
#     define SETUP_XfOrM467(x) SETUP_XfOrM461(x)
      e = FUNCCALL(SETUP_XfOrM467(_), stx_activate_certs ((((Scheme_Vector * ) (o ) ) -> els ) [i ] , cp , ht ) ); 
      if (! ((e ) == ((((Scheme_Vector * ) (o ) ) -> els ) [i ] ) ) )
        break ; 
    }
    if (i == size )
      RET_VALUE_START (o ) RET_VALUE_END ; 
    v2 = FUNCCALL(SETUP_XfOrM461(_), scheme_make_vector (size , ((void * ) 0 ) ) ); 
    for (j = 0 ; j < i ; j ++ ) {
      (((Scheme_Vector * ) (v2 ) ) -> els ) [j ] = (((Scheme_Vector * ) (o ) ) -> els ) [j ] ; 
    }
    (((Scheme_Vector * ) (v2 ) ) -> els ) [i ] = e ; 
    for (i ++ ; i < size ; i ++ ) {
#     define XfOrM463_COUNT (0+XfOrM461_COUNT)
#     define SETUP_XfOrM463(x) SETUP_XfOrM461(x)
      e = FUNCCALL(SETUP_XfOrM463(_), stx_activate_certs ((((Scheme_Vector * ) (o ) ) -> els ) [i ] , cp , ht ) ); 
      (((Scheme_Vector * ) (v2 ) ) -> els ) [i ] = e ; 
    }
    ((((Scheme_Inclhash_Object * ) (v2 ) ) -> so . keyex |= 0x1 ) ) ; 
    RET_VALUE_START (v2 ) RET_VALUE_END ; 
  }
  else if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ) {
    Scheme_Stx * stx = (Scheme_Stx * ) o ; 
    BLOCK_SETUP((PUSH(stx, 0+XfOrM445_COUNT)));
#   define XfOrM446_COUNT (1+XfOrM445_COUNT)
#   define SETUP_XfOrM446(x) SETUP(XfOrM446_COUNT)
    if (((Scheme_Cert * ) ((stx ) -> certs ? (((Scheme_Type ) (((((long ) ((stx ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((stx ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) ((stx ) -> certs ) ) -> u . pair_val . cdr ) : ((void * ) 0 ) ) : ((void * ) 0 ) ) ) ) {
      Scheme_Object * np ; 
      Scheme_Stx * res ; 
      Scheme_Cert * certs ; 
      BLOCK_SETUP((PUSH(certs, 0+XfOrM446_COUNT), PUSH(res, 1+XfOrM446_COUNT), PUSH(np, 2+XfOrM446_COUNT)));
#     define XfOrM460_COUNT (3+XfOrM446_COUNT)
#     define SETUP_XfOrM460(x) SETUP(XfOrM460_COUNT)
      np = NULLED_OUT ; 
      res = NULLED_OUT ; 
      certs = NULLED_OUT ; 
      res = (Scheme_Stx * ) FUNCCALL(SETUP_XfOrM460(_), scheme_make_stx (stx -> val , stx -> srcloc , stx -> props ) ); 
      res -> wraps = stx -> wraps ; 
      res -> u . lazy_prefix = stx -> u . lazy_prefix ; 
      np = FUNCCALL(SETUP_XfOrM460(_), scheme_make_raw_pair ((((Scheme_Simple_Object * ) (stx -> certs ) ) -> u . pair_val . car ) , ((void * ) 0 ) ) ); 
      res -> certs = np ; 
      certs = FUNCCALL(SETUP_XfOrM460(_), append_certs (((Scheme_Cert * ) ((stx ) -> certs ? (((Scheme_Type ) (((((long ) ((stx ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((stx ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) ((stx ) -> certs ) ) -> u . pair_val . cdr ) : ((void * ) 0 ) ) : ((void * ) 0 ) ) ) , * cp ) ); 
      * cp = certs ; 
      RET_VALUE_START ((Scheme_Object * ) res ) RET_VALUE_END ; 
    }
    else if (stx -> certs && ((Scheme_Type ) (((((long ) (stx -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (stx -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ) {
      RET_VALUE_START ((Scheme_Object * ) stx ) RET_VALUE_END ; 
    }
    else {
      Scheme_Object * ph ; 
      Scheme_Object * key ; 
      BLOCK_SETUP((PUSH(ph, 0+XfOrM446_COUNT), PUSH(key, 1+XfOrM446_COUNT)));
#     define XfOrM447_COUNT (2+XfOrM446_COUNT)
#     define SETUP_XfOrM447(x) SETUP(XfOrM447_COUNT)
      ph = NULLED_OUT ; 
      key = NULLED_OUT ; 
      if ((& (stx ) -> iso ) -> so . keyex & 0x1 ) {
#       define XfOrM455_COUNT (0+XfOrM447_COUNT)
#       define SETUP_XfOrM455(x) SETUP_XfOrM447(x)
        if (! * ht ) {
          GC_CAN_IGNORE Scheme_Hash_Table * htv ; 
#         define XfOrM458_COUNT (0+XfOrM455_COUNT)
#         define SETUP_XfOrM458(x) SETUP_XfOrM455(x)
          htv = FUNCCALL(SETUP_XfOrM458(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
          * ht = htv ; 
        }
        key = FUNCCALL(SETUP_XfOrM455(_), scheme_stx_property ((Scheme_Object * ) stx , share_symbol , ((void * ) 0 ) ) ); 
        if ((((key ) ) == (scheme_false ) ) ) {
#         define XfOrM457_COUNT (0+XfOrM455_COUNT)
#         define SETUP_XfOrM457(x) SETUP_XfOrM455(x)
          FUNCCALL_EMPTY(scheme_signal_error ("bad 'share key" ) ); 
        }
        ph = FUNCCALL(SETUP_XfOrM455(_), scheme_hash_get (* ht , key ) ); 
        if (ph )
          RET_VALUE_START (ph ) RET_VALUE_END ; 
        else {
#         define XfOrM456_COUNT (0+XfOrM455_COUNT)
#         define SETUP_XfOrM456(x) SETUP_XfOrM455(x)
          ph = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM456(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
          ph -> type = scheme_multiple_values_type ; 
          FUNCCALL(SETUP_XfOrM456(_), scheme_hash_set (* ht , key , (Scheme_Object * ) ph ) ); 
        }
      }
      else {
        ph = ((void * ) 0 ) ; 
        key = ((void * ) 0 ) ; 
      }
      o = FUNCCALL(SETUP_XfOrM447(_), stx_activate_certs (stx -> val , cp , ht ) ); 
      if (! ((o ) == (stx -> val ) ) ) {
        Scheme_Stx * res ; 
        BLOCK_SETUP((PUSH(res, 0+XfOrM447_COUNT)));
#       define XfOrM451_COUNT (1+XfOrM447_COUNT)
#       define SETUP_XfOrM451(x) SETUP(XfOrM451_COUNT)
        res = NULLED_OUT ; 
        res = (Scheme_Stx * ) FUNCCALL(SETUP_XfOrM451(_), scheme_make_stx (o , stx -> srcloc , stx -> props ) ); 
        res -> wraps = stx -> wraps ; 
        res -> u . lazy_prefix = stx -> u . lazy_prefix ; 
        if (stx -> certs ) {
          Scheme_Object * np ; 
          BLOCK_SETUP((PUSH(np, 0+XfOrM451_COUNT)));
#         define XfOrM453_COUNT (1+XfOrM451_COUNT)
#         define SETUP_XfOrM453(x) SETUP(XfOrM453_COUNT)
          np = NULLED_OUT ; 
          np = FUNCCALL(SETUP_XfOrM453(_), scheme_make_raw_pair (stx -> certs , ((void * ) 0 ) ) ); 
          res -> certs = np ; 
        }
        else res -> certs = no_nested_inactive_certs ; 
        if (ph ) {
#         define XfOrM452_COUNT (0+XfOrM451_COUNT)
#         define SETUP_XfOrM452(x) SETUP_XfOrM451(x)
          FUNCCALL(SETUP_XfOrM452(_), scheme_make_graph_stx ((Scheme_Object * ) res , - 1 , - 1 , - 1 ) ); 
          (((Scheme_Small_Object * ) (ph ) ) -> u . ptr_val ) = (Scheme_Object * ) res ; 
        }
        RET_VALUE_START ((Scheme_Object * ) res ) RET_VALUE_END ; 
      }
      else {
#       define XfOrM448_COUNT (0+XfOrM447_COUNT)
#       define SETUP_XfOrM448(x) SETUP_XfOrM447(x)
        if (stx -> certs ) {
          Scheme_Object * np ; 
          BLOCK_SETUP((PUSH(np, 0+XfOrM448_COUNT)));
#         define XfOrM450_COUNT (1+XfOrM448_COUNT)
#         define SETUP_XfOrM450(x) SETUP(XfOrM450_COUNT)
          np = NULLED_OUT ; 
          np = FUNCCALL(SETUP_XfOrM450(_), scheme_make_raw_pair (stx -> certs , ((void * ) 0 ) ) ); 
          stx -> certs = np ; 
        }
        else stx -> certs = no_nested_inactive_certs ; 
        if (ph ) {
#         define XfOrM449_COUNT (0+XfOrM448_COUNT)
#         define SETUP_XfOrM449(x) SETUP_XfOrM448(x)
          FUNCCALL(SETUP_XfOrM449(_), scheme_hash_set (* ht , key , (Scheme_Object * ) stx ) ); 
        }
        RET_VALUE_START ((Scheme_Object * ) stx ) RET_VALUE_END ; 
      }
    }
  }
  else RET_VALUE_START (o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * lift_inactive_certs (Scheme_Object * o , int as_active ) {
  Scheme_Cert * certs = ((void * ) 0 ) ; 
  Scheme_Hash_Table * ht = ((void * ) 0 ) ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(certs, 0), PUSH(ht, 1), PUSH(o, 2)));
# define XfOrM475_COUNT (3)
# define SETUP_XfOrM475(x) SETUP(XfOrM475_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  o = FUNCCALL(SETUP_XfOrM475(_), stx_activate_certs (o , & certs , & ht ) ); 
  if (certs )
    o = FUNCCALL(SETUP_XfOrM475(_), add_certs (o , certs , ((void * ) 0 ) , as_active ) ); 
  if (ht )
    o = FUNCCALL(SETUP_XfOrM475(_), scheme_resolve_placeholders (o , 1 , scheme_multiple_values_type ) ); 
  RET_VALUE_START (o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_stx_activate_certs (Scheme_Object * o ) {
  /* No conversion */
  return lift_inactive_certs (o , 1 ) ; 
}
int scheme_stx_has_empty_wraps (Scheme_Object * o ) {
  /* No conversion */
  Wrap_Pos awl ; 
  Scheme_Object * mark = ((void * ) 0 ) , * v ; 
  awl . l = ((Scheme_Stx * ) o ) -> wraps ; 
  WRAP_POS_SET_FIRST (& awl ) ; 
  while (! ((awl . l ) == (scheme_null ) ) ) {
    v = awl . a ; 
    if (mark ) {
      if (! ((mark ) == (v ) ) )
        return 0 ; 
      mark = ((void * ) 0 ) ; 
    }
    else mark = v ; 
    DO_WRAP_POS_INC (& awl ) ; 
  }
  return ! mark ; 
}
__xform_nongcing__ static int same_marks (Wrap_Pos * _awl , Wrap_Pos * _bwl , Scheme_Object * barrier_env , Scheme_Object * ignore_rib ) {
  /* No conversion */
  Wrap_Pos awl ; 
  Wrap_Pos bwl ; 
  Scheme_Object * acur_mark , * bcur_mark ; 
  int used_barrier = 0 ; 
  awl . l = (* _awl ) . l ; 
  awl . a = (* _awl ) . a ; 
  awl . is_limb = (* _awl ) . is_limb ; 
  awl . pos = (* _awl ) . pos ; 
  bwl . l = (* _bwl ) . l ; 
  bwl . a = (* _bwl ) . a ; 
  bwl . is_limb = (* _bwl ) . is_limb ; 
  bwl . pos = (* _bwl ) . pos ; 
  while (1 ) {
    acur_mark = ((void * ) 0 ) ; 
    while (1 ) {
      if (((awl . l ) == (scheme_null ) ) )
        break ; 
      if (((((long ) (awl . a ) ) & 0x1 ) || ((((awl . a ) -> type ) >= scheme_bignum_type ) && (((awl . a ) -> type ) <= scheme_complex_type ) ) ) && ((((long ) (awl . a ) ) & 0x1 ) ? ((((long ) (awl . a ) ) >> 1 ) >= 0 ) : ((& ((Scheme_Bignum * ) awl . a ) -> iso ) -> so . keyex & 0x1 ) ) ) {
        if (acur_mark ) {
          if (((acur_mark ) == (awl . a ) ) ) {
            acur_mark = ((void * ) 0 ) ; 
            DO_WRAP_POS_INC (& awl ) ; 
          }
          else break ; 
        }
        else {
          acur_mark = awl . a ; 
          DO_WRAP_POS_INC (& awl ) ; 
        }
      }
      else if (((Scheme_Type ) (scheme_lexical_rib_type ) == (Scheme_Type ) (((((long ) (awl . a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (awl . a ) ) -> type ) ) ) ) {
        if (((ignore_rib ) == (awl . a ) ) ) {
          DO_WRAP_POS_INC (& awl ) ; 
        }
        else if ((((barrier_env ) ) == (scheme_false ) ) ) {
          DO_WRAP_POS_INC (& awl ) ; 
        }
        else {
          Scheme_Lexical_Rib * rib ; 
          rib = (Scheme_Lexical_Rib * ) awl . a ; 
          for (rib = rib -> next ; rib ; rib = rib -> next ) {
            if ((((((Scheme_Vector * ) (rib -> rename ) ) -> els ) [0 ] ) == (barrier_env ) ) )
              break ; 
          }
          if (! rib ) {
            DO_WRAP_POS_INC (& awl ) ; 
          }
          else {
            (awl . l = scheme_null , awl . a = ((void * ) 0 ) , awl . is_limb = 0 , awl . pos = 0 ) ; 
            used_barrier = 1 ; 
          }
        }
      }
      else {
        DO_WRAP_POS_INC (& awl ) ; 
      }
    }
    bcur_mark = ((void * ) 0 ) ; 
    while (1 ) {
      if (((bwl . l ) == (scheme_null ) ) )
        break ; 
      if (((((long ) (bwl . a ) ) & 0x1 ) || ((((bwl . a ) -> type ) >= scheme_bignum_type ) && (((bwl . a ) -> type ) <= scheme_complex_type ) ) ) && ((((long ) (bwl . a ) ) & 0x1 ) ? ((((long ) (bwl . a ) ) >> 1 ) >= 0 ) : ((& ((Scheme_Bignum * ) bwl . a ) -> iso ) -> so . keyex & 0x1 ) ) ) {
        if (bcur_mark ) {
          if (((bcur_mark ) == (bwl . a ) ) ) {
            bcur_mark = ((void * ) 0 ) ; 
            DO_WRAP_POS_INC (& bwl ) ; 
          }
          else break ; 
        }
        else {
          bcur_mark = bwl . a ; 
          DO_WRAP_POS_INC (& bwl ) ; 
        }
      }
      else if (((Scheme_Type ) (scheme_lexical_rib_type ) == (Scheme_Type ) (((((long ) (bwl . a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (bwl . a ) ) -> type ) ) ) ) {
        if (((ignore_rib ) == (bwl . a ) ) ) {
          DO_WRAP_POS_INC (& bwl ) ; 
        }
        else if ((((barrier_env ) ) == (scheme_false ) ) ) {
          DO_WRAP_POS_INC (& bwl ) ; 
        }
        else {
          Scheme_Lexical_Rib * rib ; 
          rib = (Scheme_Lexical_Rib * ) bwl . a ; 
          for (rib = rib -> next ; rib ; rib = rib -> next ) {
            if ((((((Scheme_Vector * ) (rib -> rename ) ) -> els ) [0 ] ) == (barrier_env ) ) )
              break ; 
          }
          if (! rib ) {
            DO_WRAP_POS_INC (& bwl ) ; 
          }
          else {
            (bwl . l = scheme_null , bwl . a = ((void * ) 0 ) , bwl . is_limb = 0 , bwl . pos = 0 ) ; 
            used_barrier = 1 ; 
          }
        }
      }
      else {
        DO_WRAP_POS_INC (& bwl ) ; 
      }
    }
    if (! ((acur_mark ) == (bcur_mark ) ) )
      return 0 ; 
    if (((awl . l ) == (scheme_null ) ) && ((bwl . l ) == (scheme_null ) ) )
      return used_barrier + 1 ; 
  }
}
static int includes_mark (Scheme_Object * wraps , Scheme_Object * mark ) {
  /* No conversion */
  Wrap_Pos awl ; 
  Scheme_Object * acur_mark ; 
  awl . l = wraps ; 
  WRAP_POS_SET_FIRST (& awl ) ; 
  while (1 ) {
    acur_mark = ((void * ) 0 ) ; 
    while (1 ) {
      if (((awl . l ) == (scheme_null ) ) )
        break ; 
      if (((((long ) (awl . a ) ) & 0x1 ) || ((((awl . a ) -> type ) >= scheme_bignum_type ) && (((awl . a ) -> type ) <= scheme_complex_type ) ) ) ) {
        if (acur_mark ) {
          if (((acur_mark ) == (awl . a ) ) ) {
            acur_mark = ((void * ) 0 ) ; 
            DO_WRAP_POS_INC (& awl ) ; 
          }
          else break ; 
        }
        else {
          acur_mark = awl . a ; 
          DO_WRAP_POS_INC (& awl ) ; 
        }
      }
      else {
        DO_WRAP_POS_INC (& awl ) ; 
      }
    }
    if (((acur_mark ) == (mark ) ) )
      return 1 ; 
    if (((awl . l ) == (scheme_null ) ) )
      return 0 ; 
  }
}
static void add_all_marks (Scheme_Object * wraps , Scheme_Hash_Table * marks ) {
  Wrap_Pos awl ; 
  Scheme_Object * acur_mark ; 
  PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(awl.l, 0), PUSH(awl.a, 1), PUSH(acur_mark, 2), PUSH(marks, 3)));
# define XfOrM624_COUNT (4)
# define SETUP_XfOrM624(x) SETUP(XfOrM624_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  awl.l = NULLED_OUT ; 
  awl.a = NULLED_OUT ; 
  acur_mark = NULLED_OUT ; 
  awl . l = wraps ; 
  (WRAP_POS_SET_FIRST (& awl ) ) ; 
  while (1 ) {
#   define XfOrM638_COUNT (0+XfOrM624_COUNT)
#   define SETUP_XfOrM638(x) SETUP_XfOrM624(x)
    acur_mark = ((void * ) 0 ) ; 
    while (1 ) {
#     define XfOrM645_COUNT (0+XfOrM638_COUNT)
#     define SETUP_XfOrM645(x) SETUP_XfOrM638(x)
      if (((awl . l ) == (scheme_null ) ) )
        break ; 
      if (((((long ) (awl . a ) ) & 0x1 ) || ((((awl . a ) -> type ) >= scheme_bignum_type ) && (((awl . a ) -> type ) <= scheme_complex_type ) ) ) ) {
#       define XfOrM647_COUNT (0+XfOrM645_COUNT)
#       define SETUP_XfOrM647(x) SETUP_XfOrM645(x)
        if (acur_mark ) {
#         define XfOrM649_COUNT (0+XfOrM647_COUNT)
#         define SETUP_XfOrM649(x) SETUP_XfOrM647(x)
          if (((acur_mark ) == (awl . a ) ) ) {
#           define XfOrM650_COUNT (0+XfOrM649_COUNT)
#           define SETUP_XfOrM650(x) SETUP_XfOrM649(x)
            acur_mark = ((void * ) 0 ) ; 
            (DO_WRAP_POS_INC (& awl ) ) ; 
          }
          else break ; 
        }
        else {
#         define XfOrM648_COUNT (0+XfOrM647_COUNT)
#         define SETUP_XfOrM648(x) SETUP_XfOrM647(x)
          acur_mark = awl . a ; 
          (DO_WRAP_POS_INC (& awl ) ) ; 
        }
      }
      else {
#       define XfOrM646_COUNT (0+XfOrM645_COUNT)
#       define SETUP_XfOrM646(x) SETUP_XfOrM645(x)
        (DO_WRAP_POS_INC (& awl ) ) ; 
      }
    }
    if (acur_mark )
      FUNCCALL(SETUP_XfOrM638(_), scheme_hash_set (marks , acur_mark , scheme_true ) ); 
    else RET_NOTHING ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * resolve_env (Wrap_Pos * _wraps , Scheme_Object * a , long phase , int w_mod , Scheme_Object * * get_names , Scheme_Object * skip_ribs ) {
  Wrap_Pos wraps ; 
  Scheme_Object * o_rename_stack = scheme_null ; 
  Scheme_Object * mresult = scheme_false ; 
  Scheme_Object * modidx_shift_to = ((void * ) 0 ) , * modidx_shift_from = ((void * ) 0 ) ; 
  Scheme_Object * rename_stack [10 ] ; 
  int stack_pos = 0 , no_lexical = 0 ; 
  int is_in_module = 0 , skip_other_mods = 0 ; 
  Scheme_Lexical_Rib * rib = ((void * ) 0 ) , * did_rib = ((void * ) 0 ) ; 
  long orig_phase = phase ; 
  Scheme_Object * bdg = ((void * ) 0 ) ; 
  Scheme_Hash_Table * export_registry = ((void * ) 0 ) ; 
  Scheme_Object * __funcarg69 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(21);
  BLOCK_SETUP_TOP((PUSH(o_rename_stack, 0), PUSH(a, 1), PUSH(export_registry, 2), PUSH(get_names, 3), PUSH(bdg, 4), PUSH(skip_ribs, 5), PUSH(modidx_shift_from, 6), PUSH(did_rib, 7), PUSHARRAY(rename_stack, 10, 8), PUSH(rib, 11), PUSH(modidx_shift_to, 12), PUSH(mresult, 13), PUSH(wraps.l, 14), PUSH(wraps.a, 15)));
# define XfOrM651_COUNT (16)
# define SETUP_XfOrM651(x) SETUP(XfOrM651_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  wraps.l = NULLED_OUT ; 
  wraps.a = NULLED_OUT ; 
  NULL_OUT_ARRAY (rename_stack ) ; 
  ; 
  if (_wraps ) {
#   define XfOrM824_COUNT (0+XfOrM651_COUNT)
#   define SETUP_XfOrM824(x) SETUP_XfOrM651(x)
    wraps . l = (* _wraps ) . l ; 
    wraps . a = (* _wraps ) . a ; 
    wraps . is_limb = (* _wraps ) . is_limb ; 
    wraps . pos = (* _wraps ) . pos ; 
    (DO_WRAP_POS_INC (& wraps ) ) ; 
  }
  else wraps . l = ((Scheme_Stx * ) a ) -> wraps ; 
  (WRAP_POS_SET_FIRST (& wraps ) ) ; 
  while (1 ) {
#   define XfOrM738_COUNT (0+XfOrM651_COUNT)
#   define SETUP_XfOrM738(x) SETUP_XfOrM651(x)
    if (((wraps . l ) == (scheme_null ) ) ) {
      Scheme_Object * result , * key ; 
      int did_lexical = 0 ; 
      result = NULLED_OUT ; 
      key = NULLED_OUT ; 
      ; 
      result = scheme_false ; 
      while (! ((o_rename_stack ) == (scheme_null ) ) ) {
        key = ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (o_rename_stack ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ; 
        if (((key ) == (result ) ) ) {
          ; 
          did_lexical = 1 ; 
          result = (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (o_rename_stack ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ; 
        }
        else {
          ; 
          if (((key ) == (scheme_true ) ) ) {
            did_lexical = 0 ; 
          }
        }
        o_rename_stack = (((Scheme_Simple_Object * ) (o_rename_stack ) ) -> u . pair_val . cdr ) ; 
      }
      while (stack_pos ) {
        key = rename_stack [stack_pos - 1 ] ; 
        if (((key ) == (result ) ) ) {
          ; 
          result = rename_stack [stack_pos - 2 ] ; 
          did_lexical = 1 ; 
        }
        else {
          ; 
          if (((key ) == (scheme_true ) ) ) {
            did_lexical = 0 ; 
          }
        }
        stack_pos -= 2 ; 
      }
      if (! did_lexical )
        result = mresult ; 
      else if (get_names )
        get_names [0 ] = scheme_undefined ; 
      ; 
      RET_VALUE_START (result ) RET_VALUE_END ; 
    }
    else if ((((Scheme_Type ) (((((long ) (wraps . a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (wraps . a ) ) -> type ) ) == (Scheme_Type ) (scheme_rename_table_type ) ) ) && w_mod ) {
      Module_Renames * mrn = (Module_Renames * ) wraps . a ; 
      BLOCK_SETUP((PUSH(mrn, 0+XfOrM738_COUNT)));
#     define XfOrM790_COUNT (1+XfOrM738_COUNT)
#     define SETUP_XfOrM790(x) SETUP(XfOrM790_COUNT)
      if ((! is_in_module || (mrn -> kind != 0 ) ) && ! skip_other_mods ) {
#       define XfOrM791_COUNT (0+XfOrM790_COUNT)
#       define SETUP_XfOrM791(x) SETUP_XfOrM790(x)
        if (mrn -> kind != 0 )
          is_in_module = 1 ; 
        if (phase == mrn -> phase ) {
          Scheme_Object * rename , * nominal = ((void * ) 0 ) , * glob_id ; 
          BLOCK_SETUP((PUSH(glob_id, 0+XfOrM791_COUNT), PUSH(nominal, 1+XfOrM791_COUNT), PUSH(rename, 2+XfOrM791_COUNT)));
#         define XfOrM792_COUNT (3+XfOrM791_COUNT)
#         define SETUP_XfOrM792(x) SETUP(XfOrM792_COUNT)
          rename = NULLED_OUT ; 
          glob_id = NULLED_OUT ; 
          if (mrn -> needs_unmarshal )
            FUNCCALL(SETUP_XfOrM792(_), unmarshal_rename (mrn , modidx_shift_from , modidx_shift_to , export_registry ) ); 
          if (mrn -> marked_names ) {
#           define XfOrM805_COUNT (0+XfOrM792_COUNT)
#           define SETUP_XfOrM805(x) SETUP_XfOrM792(x)
            if (! bdg )
              bdg = FUNCCALL(SETUP_XfOrM805(_), resolve_env (((void * ) 0 ) , a , orig_phase , 0 , ((void * ) 0 ) , skip_ribs ) ); 
            glob_id = FUNCCALL(SETUP_XfOrM805(_), scheme_tl_id_sym ((Scheme_Env * ) mrn -> marked_names , a , bdg , 0 ) ); 
            if ((! (((bdg ) ) == (scheme_false ) ) ) && ! ((glob_id ) == (((Scheme_Stx * ) a ) -> val ) ) ) {
              no_lexical = 1 ; 
              stack_pos = 0 ; 
              o_rename_stack = scheme_null ; 
            }
          }
          else glob_id = ((Scheme_Stx * ) a ) -> val ; 
          rename = FUNCCALL(SETUP_XfOrM792(_), scheme_hash_get (mrn -> ht , glob_id ) ); 
          if (! rename && mrn -> nomarshal_ht )
            rename = FUNCCALL(SETUP_XfOrM792(_), scheme_hash_get (mrn -> nomarshal_ht , glob_id ) ); 
          if (! rename && mrn -> plus_kernel ) {
#           define XfOrM804_COUNT (0+XfOrM792_COUNT)
#           define SETUP_XfOrM804(x) SETUP_XfOrM792(x)
            rename = FUNCCALL(SETUP_XfOrM804(_), scheme_hash_get (krn -> ht , glob_id ) ); 
            nominal = mrn -> plus_kernel_nominal_source ; 
          }
          if (rename ) {
#           define XfOrM794_COUNT (0+XfOrM792_COUNT)
#           define SETUP_XfOrM794(x) SETUP_XfOrM792(x)
            if (mrn -> kind == 2 )
              skip_other_mods = 1 ; 
            if (((Scheme_Type ) (((((long ) (rename ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rename ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
              mresult = (((Scheme_Simple_Object * ) (rename ) ) -> u . pair_val . car ) ; 
            else mresult = rename ; 
            if (modidx_shift_from )
              mresult = FUNCCALL(SETUP_XfOrM794(_), scheme_modidx_shift (mresult , modidx_shift_from , modidx_shift_to ) ); 
            if (get_names ) {
              if (((Scheme_Type ) (((((long ) (rename ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rename ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
                if ((((Scheme_Inclhash_Object * ) (rename ) ) -> so . keyex & 0x1 ) ) {
                  get_names [0 ] = glob_id ; 
                  get_names [1 ] = (((Scheme_Simple_Object * ) (rename ) ) -> u . pair_val . cdr ) ; 
                  get_names [2 ] = get_names [0 ] ; 
                }
                else {
                  rename = (((Scheme_Simple_Object * ) (rename ) ) -> u . pair_val . cdr ) ; 
                  if (((Scheme_Type ) (((((long ) (rename ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rename ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
                    if ((((long ) ((((Scheme_Simple_Object * ) (rename ) ) -> u . pair_val . car ) ) ) & 0x1 ) ) {
                      get_names [3 ] = (((Scheme_Simple_Object * ) (rename ) ) -> u . pair_val . car ) ; 
                      rename = (((Scheme_Simple_Object * ) (rename ) ) -> u . pair_val . cdr ) ; 
                    }
                    get_names [0 ] = (((Scheme_Simple_Object * ) (rename ) ) -> u . pair_val . car ) ; 
                    get_names [1 ] = ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (rename ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ; 
                    get_names [2 ] = ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (rename ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ; 
                  }
                  else {
                    get_names [0 ] = rename ; 
                    get_names [2 ] = ((void * ) 0 ) ; 
                  }
                }
              }
              else {
                get_names [0 ] = glob_id ; 
                get_names [2 ] = ((void * ) 0 ) ; 
              }
              if (! get_names [2 ] ) {
                get_names [2 ] = get_names [0 ] ; 
                if (nominal )
                  get_names [1 ] = nominal ; 
                else get_names [1 ] = mresult ; 
              }
            }
          }
          else {
            mresult = scheme_false ; 
            if (get_names )
              get_names [0 ] = ((void * ) 0 ) ; 
          }
        }
      }
    }
    else if (((Scheme_Type ) (((((long ) (wraps . a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (wraps . a ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) && w_mod ) {
      Scheme_Object * vec , * n , * dest , * src ; 
      BLOCK_SETUP((PUSH(src, 0+XfOrM738_COUNT), PUSH(vec, 1+XfOrM738_COUNT)));
#     define XfOrM785_COUNT (2+XfOrM738_COUNT)
#     define SETUP_XfOrM785(x) SETUP(XfOrM785_COUNT)
      vec = NULLED_OUT ; 
      n = NULLED_OUT ; 
      dest = NULLED_OUT ; 
      src = NULLED_OUT ; 
      vec = (((Scheme_Small_Object * ) (wraps . a ) ) -> u . ptr_val ) ; 
      n = (((Scheme_Vector * ) (vec ) ) -> els ) [0 ] ; 
      phase -= (((long ) (n ) ) >> 1 ) ; 
      src = (((Scheme_Vector * ) (vec ) ) -> els ) [1 ] ; 
      dest = (((Scheme_Vector * ) (vec ) ) -> els ) [2 ] ; 
      if (! (((src ) ) == (scheme_false ) ) ) {
#       define XfOrM787_COUNT (0+XfOrM785_COUNT)
#       define SETUP_XfOrM787(x) SETUP_XfOrM785(x)
        if (! modidx_shift_to ) {
          modidx_shift_to = dest ; 
        }
        else if (! ((modidx_shift_from ) == (dest ) ) ) {
#         define XfOrM788_COUNT (0+XfOrM787_COUNT)
#         define SETUP_XfOrM788(x) SETUP_XfOrM787(x)
          modidx_shift_to = FUNCCALL(SETUP_XfOrM788(_), scheme_modidx_shift (dest , modidx_shift_from , modidx_shift_to ) ); 
        }
        modidx_shift_from = src ; 
      }
      {
        Scheme_Object * er ; 
        er = NULLED_OUT ; 
        er = (((Scheme_Vector * ) (vec ) ) -> els ) [3 ] ; 
        if ((! (((er ) ) == (scheme_false ) ) ) )
          export_registry = (Scheme_Hash_Table * ) er ; 
      }
    }
    else if (rib || (((Scheme_Type ) (((((long ) (wraps . a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (wraps . a ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) && ! no_lexical ) ) {
      Scheme_Object * rename , * renamed , * recur_skip_ribs ; 
      int ri , c , istart , iend , is_rib ; 
      BLOCK_SETUP((PUSH(recur_skip_ribs, 0+XfOrM738_COUNT), PUSH(renamed, 1+XfOrM738_COUNT), PUSH(rename, 2+XfOrM738_COUNT)));
#     define XfOrM749_COUNT (3+XfOrM738_COUNT)
#     define SETUP_XfOrM749(x) SETUP(XfOrM749_COUNT)
      rename = NULLED_OUT ; 
      renamed = NULLED_OUT ; 
      recur_skip_ribs = NULLED_OUT ; 
      if (rib ) {
        rename = rib -> rename ; 
        recur_skip_ribs = rib -> timestamp ; 
        rib = rib -> next ; 
        is_rib = 1 ; 
      }
      else {
        rename = wraps . a ; 
        recur_skip_ribs = skip_ribs ; 
        is_rib = 0 ; 
      }
      c = (((((Scheme_Vector * ) (rename ) ) -> size ) - 2 ) >> 1 ) ; 
      if (! ((((((Scheme_Vector * ) (rename ) ) -> els ) [1 ] ) ) == (scheme_false ) ) ) {
        void * pos ; 
        BLOCK_SETUP((PUSH(pos, 0+XfOrM749_COUNT)));
#       define XfOrM779_COUNT (1+XfOrM749_COUNT)
#       define SETUP_XfOrM779(x) SETUP(XfOrM779_COUNT)
        pos = NULLED_OUT ; 
        pos = FUNCCALL(SETUP_XfOrM779(_), scheme_hash_get ((Scheme_Hash_Table * ) ((((Scheme_Vector * ) (rename ) ) -> els ) [1 ] ) , ((Scheme_Stx * ) a ) -> val ) ); 
        if (pos ) {
          istart = (((long ) (pos ) ) >> 1 ) ; 
          if (istart < 0 ) {
            istart = 0 ; 
            iend = c ; 
          }
          else iend = istart + 1 ; 
        }
        else {
          istart = 0 ; 
          iend = 0 ; 
        }
      }
      else {
        istart = 0 ; 
        iend = c ; 
      }
      for (ri = istart ; ri < iend ; ri ++ ) {
#       define XfOrM764_COUNT (0+XfOrM749_COUNT)
#       define SETUP_XfOrM764(x) SETUP_XfOrM749(x)
        renamed = (((Scheme_Vector * ) (rename ) ) -> els ) [2 + ri ] ; 
        if (((((Scheme_Stx * ) a ) -> val ) == ((((Scheme_Type ) (((((long ) (renamed ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (renamed ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ? ((Scheme_Stx * ) renamed ) -> val : renamed ) ) ) ) {
          int same ; 
#         define XfOrM765_COUNT (0+XfOrM764_COUNT)
#         define SETUP_XfOrM765(x) SETUP_XfOrM764(x)
          {
            Scheme_Object * other_env , * envname ; 
            BLOCK_SETUP((PUSH(other_env, 0+XfOrM765_COUNT), PUSH(envname, 1+XfOrM765_COUNT)));
#           define XfOrM766_COUNT (2+XfOrM765_COUNT)
#           define SETUP_XfOrM766(x) SETUP(XfOrM766_COUNT)
            other_env = NULLED_OUT ; 
            envname = NULLED_OUT ; 
            if (((Scheme_Type ) (((((long ) (renamed ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (renamed ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
              other_env = scheme_false ; 
              envname = (((Scheme_Vector * ) (rename ) ) -> els ) [2 + c + ri ] ; 
              same = 1 ; 
              ; 
            }
            else {
#             define XfOrM770_COUNT (0+XfOrM766_COUNT)
#             define SETUP_XfOrM770(x) SETUP_XfOrM766(x)
              envname = (((Scheme_Vector * ) (rename ) ) -> els ) [0 ] ; 
              other_env = (((Scheme_Vector * ) (rename ) ) -> els ) [2 + c + ri ] ; 
              if ((((other_env ) ) == (scheme_void ) ) ) {
#               define XfOrM772_COUNT (0+XfOrM770_COUNT)
#               define SETUP_XfOrM772(x) SETUP_XfOrM770(x)
                {
#                 define XfOrM775_COUNT (0+XfOrM772_COUNT)
#                 define SETUP_XfOrM775(x) SETUP_XfOrM772(x)
                  if ((scheme_fuel_counter ) <= 0 ) {
#                   define XfOrM776_COUNT (0+XfOrM775_COUNT)
#                   define SETUP_XfOrM776(x) SETUP_XfOrM775(x)
                    FUNCCALL(SETUP_XfOrM776(_), scheme_out_of_fuel () ); 
                  }
                }
                ; 
                other_env = FUNCCALL(SETUP_XfOrM772(_), resolve_env (((void * ) 0 ) , renamed , 0 , 0 , ((void * ) 0 ) , recur_skip_ribs ) ); 
                if (! is_rib )
                  (((Scheme_Vector * ) (rename ) ) -> els ) [2 + c + ri ] = other_env ; 
                {
#                 define XfOrM773_COUNT (0+XfOrM772_COUNT)
#                 define SETUP_XfOrM773(x) SETUP_XfOrM772(x)
                  if ((scheme_fuel_counter ) <= 0 ) {
#                   define XfOrM774_COUNT (0+XfOrM773_COUNT)
#                   define SETUP_XfOrM774(x) SETUP_XfOrM773(x)
                    FUNCCALL(SETUP_XfOrM774(_), scheme_out_of_fuel () ); 
                  }
                }
                ; 
              }
              ; 
              {
                Wrap_Pos w2 ; 
#               define XfOrM771_COUNT (0+XfOrM770_COUNT)
#               define SETUP_XfOrM771(x) SETUP_XfOrM770(x)
                w2.l = NULLED_OUT ; 
                w2.a = NULLED_OUT ; 
                w2 . l = ((Scheme_Stx * ) renamed ) -> wraps ; 
                (WRAP_POS_SET_FIRST (& w2 ) ) ; 
                same = (same_marks (& w2 , & wraps , other_env , wraps . a ) ) ; 
                if (! same )
                  ; 
              }
            }
            if (same ) {
#             define XfOrM767_COUNT (0+XfOrM766_COUNT)
#             define SETUP_XfOrM767(x) SETUP_XfOrM766(x)
              if (stack_pos < 10 ) {
                rename_stack [stack_pos ++ ] = envname ; 
                rename_stack [stack_pos ++ ] = other_env ; 
              }
              else {
#               define XfOrM768_COUNT (0+XfOrM767_COUNT)
#               define SETUP_XfOrM768(x) SETUP_XfOrM767(x)
                o_rename_stack = (__funcarg69 = FUNCCALL(SETUP_XfOrM768(_), scheme_make_pair (other_env , envname ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg69 , o_rename_stack ) )) ; 
              }
              rib = ((void * ) 0 ) ; 
            }
            break ; 
          }
        }
      }
    }
    else if (((Scheme_Type ) (scheme_lexical_rib_type ) == (Scheme_Type ) (((((long ) (wraps . a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (wraps . a ) ) -> type ) ) ) && ! no_lexical ) {
#     define XfOrM743_COUNT (0+XfOrM738_COUNT)
#     define SETUP_XfOrM743(x) SETUP_XfOrM738(x)
      rib = (Scheme_Lexical_Rib * ) wraps . a ; 
      ; 
      if (skip_ribs ) {
#       define XfOrM747_COUNT (0+XfOrM743_COUNT)
#       define SETUP_XfOrM747(x) SETUP_XfOrM743(x)
        if (FUNCCALL(SETUP_XfOrM747(_), scheme_bin_gt_eq (rib -> timestamp , skip_ribs ) )) {
          ; 
          rib = ((void * ) 0 ) ; 
        }
      }
      if (rib ) {
        if (((did_rib ) == (rib ) ) ) {
          ; 
          rib = ((void * ) 0 ) ; 
        }
        else {
          did_rib = rib ; 
          rib = rib -> next ; 
        }
      }
    }
    else if (((((long ) (wraps . a ) ) & 0x1 ) || ((((wraps . a ) -> type ) >= scheme_bignum_type ) && (((wraps . a ) -> type ) <= scheme_complex_type ) ) ) ) {
      did_rib = ((void * ) 0 ) ; 
    }
    else if (((Scheme_Type ) (((((long ) (wraps . a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (wraps . a ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) ) {
      Scheme_Hash_Table * ht = (Scheme_Hash_Table * ) wraps . a ; 
      BLOCK_SETUP((PUSH(ht, 0+XfOrM738_COUNT)));
#     define XfOrM739_COUNT (1+XfOrM738_COUNT)
#     define SETUP_XfOrM739(x) SETUP(XfOrM739_COUNT)
      did_rib = ((void * ) 0 ) ; 
      if (! ht -> count || FUNCCALL(SETUP_XfOrM739(_), scheme_hash_get (ht , ((Scheme_Object * ) (void * ) (long ) ((((long ) (5 ) ) << 1 ) | 0x1 ) ) ) )) {
#       define XfOrM741_COUNT (0+XfOrM739_COUNT)
#       define SETUP_XfOrM741(x) SETUP_XfOrM739(x)
        FUNCCALL(SETUP_XfOrM741(_), fill_chain_cache (wraps . l ) ); 
      }
      if (! FUNCCALL(SETUP_XfOrM739(_), scheme_hash_get (ht , ((Scheme_Stx * ) a ) -> val ) )) {
#       define XfOrM740_COUNT (0+XfOrM739_COUNT)
#       define SETUP_XfOrM740(x) SETUP_XfOrM739(x)
        FUNCCALL(SETUP_XfOrM740(_), set_wraps_to_skip (ht , & wraps ) ); 
        continue ; 
      }
    }
    if (! rib )
      (DO_WRAP_POS_INC (& wraps ) ) ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * get_module_src_name (Scheme_Object * a , long phase ) {
  Wrap_Pos wraps ; 
  Scheme_Object * result ; 
  int is_in_module = 0 , skip_other_mods = 0 ; 
  long orig_phase = phase ; 
  Scheme_Object * bdg = ((void * ) 0 ) ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(bdg, 0), PUSH(a, 1), PUSH(result, 2), PUSH(wraps.l, 3), PUSH(wraps.a, 4)));
# define XfOrM825_COUNT (5)
# define SETUP_XfOrM825(x) SETUP(XfOrM825_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  wraps.l = NULLED_OUT ; 
  wraps.a = NULLED_OUT ; 
  result = NULLED_OUT ; 
  if (((Scheme_Stx * ) a ) -> u . modinfo_cache )
    RET_VALUE_START (((Scheme_Stx * ) a ) -> u . modinfo_cache ) RET_VALUE_END ; 
  wraps . l = ((Scheme_Stx * ) a ) -> wraps ; 
  (WRAP_POS_SET_FIRST (& wraps ) ) ; 
  result = ((void * ) 0 ) ; 
  while (1 ) {
#   define XfOrM838_COUNT (0+XfOrM825_COUNT)
#   define SETUP_XfOrM838(x) SETUP_XfOrM825(x)
    if (((wraps . l ) == (scheme_null ) ) ) {
      if (! result )
        result = ((Scheme_Stx * ) a ) -> val ; 
      ((Scheme_Stx * ) a ) -> u . modinfo_cache = result ; 
      RET_VALUE_START (result ) RET_VALUE_END ; 
    }
    else if ((((Scheme_Type ) (((((long ) (wraps . a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (wraps . a ) ) -> type ) ) == (Scheme_Type ) (scheme_rename_table_type ) ) ) ) {
      Module_Renames * mrn = (Module_Renames * ) wraps . a ; 
      BLOCK_SETUP((PUSH(mrn, 0+XfOrM838_COUNT)));
#     define XfOrM840_COUNT (1+XfOrM838_COUNT)
#     define SETUP_XfOrM840(x) SETUP(XfOrM840_COUNT)
      if ((! is_in_module || (mrn -> kind != 0 ) ) && ! skip_other_mods ) {
#       define XfOrM841_COUNT (0+XfOrM840_COUNT)
#       define SETUP_XfOrM841(x) SETUP_XfOrM840(x)
        if (mrn -> kind != 0 )
          is_in_module = 1 ; 
        if (phase == mrn -> phase ) {
          Scheme_Object * rename , * glob_id ; 
          BLOCK_SETUP((PUSH(glob_id, 0+XfOrM841_COUNT), PUSH(rename, 1+XfOrM841_COUNT)));
#         define XfOrM842_COUNT (2+XfOrM841_COUNT)
#         define SETUP_XfOrM842(x) SETUP(XfOrM842_COUNT)
          rename = NULLED_OUT ; 
          glob_id = NULLED_OUT ; 
          if (mrn -> needs_unmarshal ) {
#           define XfOrM848_COUNT (0+XfOrM842_COUNT)
#           define SETUP_XfOrM848(x) SETUP_XfOrM842(x)
            FUNCCALL(SETUP_XfOrM848(_), resolve_env (((void * ) 0 ) , a , orig_phase , 1 , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
          }
          if (mrn -> marked_names ) {
#           define XfOrM847_COUNT (0+XfOrM842_COUNT)
#           define SETUP_XfOrM847(x) SETUP_XfOrM842(x)
            if (! bdg )
              bdg = FUNCCALL(SETUP_XfOrM847(_), resolve_env (& wraps , a , orig_phase , 0 , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
            glob_id = FUNCCALL(SETUP_XfOrM847(_), scheme_tl_id_sym ((Scheme_Env * ) mrn -> marked_names , a , bdg , 0 ) ); 
          }
          else glob_id = ((Scheme_Stx * ) a ) -> val ; 
          rename = FUNCCALL(SETUP_XfOrM842(_), scheme_hash_get (mrn -> ht , glob_id ) ); 
          if (! rename && mrn -> nomarshal_ht )
            rename = FUNCCALL(SETUP_XfOrM842(_), scheme_hash_get (mrn -> nomarshal_ht , glob_id ) ); 
          if (! rename && mrn -> plus_kernel )
            rename = FUNCCALL(SETUP_XfOrM842(_), scheme_hash_get (krn -> ht , glob_id ) ); 
          if (rename ) {
            if (mrn -> kind == 2 )
              skip_other_mods = 1 ; 
            if (((Scheme_Type ) (((((long ) (rename ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rename ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
              if ((((Scheme_Inclhash_Object * ) (rename ) ) -> so . keyex & 0x1 ) ) {
                result = glob_id ; 
              }
              else {
                result = (((Scheme_Simple_Object * ) (rename ) ) -> u . pair_val . cdr ) ; 
                if (((Scheme_Type ) (((((long ) (result ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (result ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
                  result = (((Scheme_Simple_Object * ) (result ) ) -> u . pair_val . car ) ; 
              }
            }
            else result = glob_id ; 
          }
          else result = ((void * ) 0 ) ; 
        }
      }
    }
    else if (((Scheme_Type ) (((((long ) (wraps . a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (wraps . a ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) {
      Scheme_Object * n , * vec ; 
      n = NULLED_OUT ; 
      vec = NULLED_OUT ; 
      vec = (((Scheme_Small_Object * ) (wraps . a ) ) -> u . ptr_val ) ; 
      n = (((Scheme_Vector * ) (vec ) ) -> els ) [0 ] ; 
      phase -= (((long ) (n ) ) >> 1 ) ; 
    }
    (DO_WRAP_POS_INC (& wraps ) ) ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_stx_free_eq (Scheme_Object * a , Scheme_Object * b , long phase ) {
  Scheme_Object * asym , * bsym ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(a, 0), PUSH(b, 1)));
# define XfOrM850_COUNT (2)
# define SETUP_XfOrM850(x) SETUP(XfOrM850_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  asym = NULLED_OUT ; 
  bsym = NULLED_OUT ; 
  if (! a || ! b )
    RET_VALUE_START ((a == b ) ) RET_VALUE_END ; 
  if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    asym = ((Scheme_Stx * ) a ) -> val ; 
  else asym = a ; 
  if (((Scheme_Type ) (((((long ) (b ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (b ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    bsym = ((Scheme_Stx * ) b ) -> val ; 
  else bsym = b ; 
  if (! ((asym ) == (bsym ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  if ((a == asym ) || (b == bsym ) )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  a = FUNCCALL(SETUP_XfOrM850(_), resolve_env (((void * ) 0 ) , a , phase , 1 , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
  b = FUNCCALL_AGAIN(resolve_env (((void * ) 0 ) , b , phase , 1 , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
  a = FUNCCALL_AGAIN(scheme_module_resolve (a , 0 ) ); 
  b = FUNCCALL_AGAIN(scheme_module_resolve (b , 0 ) ); 
  RET_VALUE_START (((a ) == (b ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_stx_module_eq (Scheme_Object * a , Scheme_Object * b , long phase ) {
  Scheme_Object * asym , * bsym ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(b, 0), PUSH(bsym, 1), PUSH(a, 2), PUSH(asym, 3)));
# define XfOrM851_COUNT (4)
# define SETUP_XfOrM851(x) SETUP(XfOrM851_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  asym = NULLED_OUT ; 
  bsym = NULLED_OUT ; 
  if (! a || ! b )
    RET_VALUE_START ((a == b ) ) RET_VALUE_END ; 
  if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    asym = FUNCCALL(SETUP_XfOrM851(_), get_module_src_name (a , phase ) ); 
  else asym = a ; 
  if (((Scheme_Type ) (((((long ) (b ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (b ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    bsym = FUNCCALL(SETUP_XfOrM851(_), get_module_src_name (b , phase ) ); 
  else bsym = b ; 
  if (! ((asym ) == (bsym ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  if ((a == asym ) || (b == bsym ) )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  a = FUNCCALL(SETUP_XfOrM851(_), resolve_env (((void * ) 0 ) , a , phase , 1 , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
  b = FUNCCALL_AGAIN(resolve_env (((void * ) 0 ) , b , phase , 1 , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
  a = FUNCCALL_AGAIN(scheme_module_resolve (a , 0 ) ); 
  b = FUNCCALL_AGAIN(scheme_module_resolve (b , 0 ) ); 
  RET_VALUE_START (((a ) == (b ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_stx_module_name (Scheme_Object * * a , long phase , Scheme_Object * * nominal_modidx , Scheme_Object * * nominal_name , int * mod_phase ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(nominal_name, 0), PUSH(a, 1), PUSH(mod_phase, 2), PUSH(nominal_modidx, 3)));
# define XfOrM852_COUNT (4)
# define SETUP_XfOrM852(x) SETUP(XfOrM852_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (((Scheme_Type ) (((((long ) (* a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (* a ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ) {
    Scheme_Object * modname , * names [4 ] ; 
    BLOCK_SETUP((PUSHARRAY(names, 4, 0+XfOrM852_COUNT), PUSH(modname, 3+XfOrM852_COUNT)));
#   define XfOrM853_COUNT (4+XfOrM852_COUNT)
#   define SETUP_XfOrM853(x) SETUP(XfOrM853_COUNT)
    modname = NULLED_OUT ; 
    NULL_OUT_ARRAY (names ) ; 
    names [0 ] = ((void * ) 0 ) ; 
    names [3 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
    modname = FUNCCALL(SETUP_XfOrM853(_), resolve_env (((void * ) 0 ) , * a , phase , 1 , names , ((void * ) 0 ) ) ); 
    if (names [0 ] ) {
      if (((names [0 ] ) == (scheme_undefined ) ) ) {
        RET_VALUE_START (scheme_undefined ) RET_VALUE_END ; 
      }
      else {
        * a = names [0 ] ; 
        if (nominal_modidx )
          * nominal_modidx = names [1 ] ; 
        if (nominal_name )
          * nominal_name = names [2 ] ; 
        if (mod_phase )
          * mod_phase = (((long ) (names [3 ] ) ) >> 1 ) ; 
        RET_VALUE_START (modname ) RET_VALUE_END ; 
      }
    }
    else RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_stx_moduleless_env (Scheme_Object * a , long phase ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(1);
# define XfOrM857_COUNT (0)
# define SETUP_XfOrM857(x) SETUP(XfOrM857_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ) {
    Scheme_Object * r ; 
    BLOCK_SETUP((PUSH(r, 0+XfOrM857_COUNT)));
#   define XfOrM858_COUNT (1+XfOrM857_COUNT)
#   define SETUP_XfOrM858(x) SETUP(XfOrM858_COUNT)
    r = NULLED_OUT ; 
    r = FUNCCALL(SETUP_XfOrM858(_), resolve_env (((void * ) 0 ) , a , phase , 0 , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
    if (r )
      RET_VALUE_START (r ) RET_VALUE_END ; 
  }
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_stx_env_bound_eq (Scheme_Object * a , Scheme_Object * b , Scheme_Object * uid , long phase ) {
  Scheme_Object * asym , * bsym , * ae , * be ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(ae, 0), PUSH(b, 1), PUSH(be, 2), PUSH(a, 3), PUSH(uid, 4)));
# define XfOrM859_COUNT (5)
# define SETUP_XfOrM859(x) SETUP(XfOrM859_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  asym = NULLED_OUT ; 
  bsym = NULLED_OUT ; 
  ae = NULLED_OUT ; 
  be = NULLED_OUT ; 
  if (! a || ! b )
    RET_VALUE_START ((a == b ) ) RET_VALUE_END ; 
  if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    asym = ((Scheme_Stx * ) a ) -> val ; 
  else asym = a ; 
  if (((Scheme_Type ) (((((long ) (b ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (b ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    bsym = ((Scheme_Stx * ) b ) -> val ; 
  else bsym = b ; 
  if (! ((asym ) == (bsym ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  ae = FUNCCALL(SETUP_XfOrM859(_), resolve_env (((void * ) 0 ) , a , phase , 0 , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
  if (uid )
    be = uid ; 
  else {
#   define XfOrM861_COUNT (0+XfOrM859_COUNT)
#   define SETUP_XfOrM861(x) SETUP_XfOrM859(x)
    be = FUNCCALL(SETUP_XfOrM861(_), resolve_env (((void * ) 0 ) , b , phase , 0 , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
  }
  if (! ((ae ) == (be ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  if (! uid ) {
    Wrap_Pos aw ; 
    Wrap_Pos bw ; 
#   define XfOrM860_COUNT (0+XfOrM859_COUNT)
#   define SETUP_XfOrM860(x) SETUP_XfOrM859(x)
    aw.l = NULLED_OUT ; 
    aw.a = NULLED_OUT ; 
    bw.l = NULLED_OUT ; 
    bw.a = NULLED_OUT ; 
    aw . l = ((Scheme_Stx * ) a ) -> wraps ; 
    (WRAP_POS_SET_FIRST (& aw ) ) ; 
    bw . l = ((Scheme_Stx * ) b ) -> wraps ; 
    (WRAP_POS_SET_FIRST (& bw ) ) ; 
    if (! (same_marks (& aw , & bw , ae , ((void * ) 0 ) ) ) )
      RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  RET_VALUE_START (1 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_stx_bound_eq (Scheme_Object * a , Scheme_Object * b , long phase ) {
  /* No conversion */
  return scheme_stx_env_bound_eq (a , b , ((void * ) 0 ) , phase ) ; 
}
Scheme_Object * scheme_stx_source_module (Scheme_Object * stx , int resolve ) {
  Wrap_Pos w ; 
  Scheme_Object * srcmod = scheme_false , * chain_from = ((void * ) 0 ) ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(chain_from, 0), PUSH(srcmod, 1), PUSH(w.l, 2), PUSH(w.a, 3)));
# define XfOrM863_COUNT (4)
# define SETUP_XfOrM863(x) SETUP(XfOrM863_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  w.l = NULLED_OUT ; 
  w.a = NULLED_OUT ; 
  w . l = ((Scheme_Stx * ) stx ) -> wraps ; 
  (WRAP_POS_SET_FIRST (& w ) ) ; 
  while (! ((w . l ) == (scheme_null ) ) ) {
#   define XfOrM869_COUNT (0+XfOrM863_COUNT)
#   define SETUP_XfOrM869(x) SETUP_XfOrM863(x)
    if (((Scheme_Type ) (((((long ) (w . a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (w . a ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) {
      Scheme_Object * vec , * dest , * src ; 
      BLOCK_SETUP((PUSH(src, 0+XfOrM869_COUNT)));
#     define XfOrM870_COUNT (1+XfOrM869_COUNT)
#     define SETUP_XfOrM870(x) SETUP(XfOrM870_COUNT)
      vec = NULLED_OUT ; 
      dest = NULLED_OUT ; 
      src = NULLED_OUT ; 
      vec = (((Scheme_Small_Object * ) (w . a ) ) -> u . ptr_val ) ; 
      src = (((Scheme_Vector * ) (vec ) ) -> els ) [1 ] ; 
      dest = (((Scheme_Vector * ) (vec ) ) -> els ) [2 ] ; 
      if (! (((src ) ) == (scheme_false ) ) ) {
#       define XfOrM871_COUNT (0+XfOrM870_COUNT)
#       define SETUP_XfOrM871(x) SETUP_XfOrM870(x)
        if (! chain_from ) {
          srcmod = dest ; 
        }
        else if (! ((chain_from ) == (dest ) ) ) {
#         define XfOrM872_COUNT (0+XfOrM871_COUNT)
#         define SETUP_XfOrM872(x) SETUP_XfOrM871(x)
          srcmod = FUNCCALL(SETUP_XfOrM872(_), scheme_modidx_shift (dest , chain_from , srcmod ) ); 
        }
        chain_from = src ; 
      }
    }
    (DO_WRAP_POS_INC (& w ) ) ; 
  }
  if ((! (((srcmod ) ) == (scheme_false ) ) ) && resolve )
    srcmod = FUNCCALL(SETUP_XfOrM863(_), scheme_module_resolve (srcmod , 0 ) ); 
  RET_VALUE_START (srcmod ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_stx_parallel_is_used (Scheme_Object * sym , Scheme_Object * stx ) {
  Wrap_Pos w ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(sym, 0), PUSH(w.l, 1), PUSH(w.a, 2)));
# define XfOrM874_COUNT (3)
# define SETUP_XfOrM874(x) SETUP(XfOrM874_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  w.l = NULLED_OUT ; 
  w.a = NULLED_OUT ; 
  w . l = ((Scheme_Stx * ) stx ) -> wraps ; 
  (WRAP_POS_SET_FIRST (& w ) ) ; 
  while (! ((w . l ) == (scheme_null ) ) ) {
#   define XfOrM877_COUNT (0+XfOrM874_COUNT)
#   define SETUP_XfOrM877(x) SETUP_XfOrM874(x)
    if ((((Scheme_Type ) (((((long ) (w . a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (w . a ) ) -> type ) ) == (Scheme_Type ) (scheme_rename_table_type ) ) ) ) {
      Module_Renames * mrn = (Module_Renames * ) w . a ; 
#     define XfOrM878_COUNT (0+XfOrM877_COUNT)
#     define SETUP_XfOrM878(x) SETUP_XfOrM877(x)
      if (FUNCCALL(SETUP_XfOrM878(_), scheme_tl_id_is_sym_used (mrn -> marked_names , sym ) ))
        RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
    (DO_WRAP_POS_INC (& w ) ) ; 
  }
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_stx_has_more_certs (Scheme_Object * id , Scheme_Object * id_certs , Scheme_Object * than_id , Scheme_Object * than_id_certs ) {
  int i , j ; 
  Scheme_Cert * certs , * t_certs ; 
  Scheme_Hash_Table * ht , * t_ht = ((void * ) 0 ) ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(8);
  BLOCK_SETUP_TOP((PUSH(ht, 0), PUSH(t_certs, 1), PUSH(id_certs, 2), PUSH(id, 3), PUSH(t_ht, 4), PUSH(certs, 5), PUSH(than_id_certs, 6), PUSH(than_id, 7)));
# define XfOrM879_COUNT (8)
# define SETUP_XfOrM879(x) SETUP(XfOrM879_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  certs = NULLED_OUT ; 
  t_certs = NULLED_OUT ; 
  ht = NULLED_OUT ; 
  if ((! id_certs || ((id_certs ) == (than_id_certs ) ) ) && ! ((Scheme_Cert * ) (((Scheme_Stx * ) id ) -> certs ? (((Scheme_Type ) (((((long ) (((Scheme_Stx * ) id ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) id ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) (((Scheme_Stx * ) id ) -> certs ) ) -> u . pair_val . car ) : ((Scheme_Stx * ) id ) -> certs ) : ((void * ) 0 ) ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  if (id_marks_ht ) {
    ht = id_marks_ht ; 
    id_marks_ht = ((void * ) 0 ) ; 
  }
  else ht = FUNCCALL(SETUP_XfOrM879(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  FUNCCALL(SETUP_XfOrM879(_), add_all_marks (((Scheme_Stx * ) id ) -> wraps , ht ) ); 
  for (i = 0 ; i < 2 ; i ++ ) {
#   define XfOrM906_COUNT (0+XfOrM879_COUNT)
#   define SETUP_XfOrM906(x) SETUP_XfOrM879(x)
    if (i )
      certs = ((Scheme_Cert * ) (((Scheme_Stx * ) id ) -> certs ? (((Scheme_Type ) (((((long ) (((Scheme_Stx * ) id ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) id ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) (((Scheme_Stx * ) id ) -> certs ) ) -> u . pair_val . car ) : ((Scheme_Stx * ) id ) -> certs ) : ((void * ) 0 ) ) ) ; 
    else certs = (Scheme_Cert * ) id_certs ; 
    while (certs && ! ((certs ) == ((Scheme_Cert * ) than_id_certs ) ) ) {
#     define XfOrM919_COUNT (0+XfOrM906_COUNT)
#     define SETUP_XfOrM919(x) SETUP_XfOrM906(x)
      if (FUNCCALL(SETUP_XfOrM919(_), scheme_hash_get (ht , certs -> mark ) )) {
#       define XfOrM920_COUNT (0+XfOrM919_COUNT)
#       define SETUP_XfOrM920(x) SETUP_XfOrM919(x)
        if (! t_ht ) {
#         define XfOrM929_COUNT (0+XfOrM920_COUNT)
#         define SETUP_XfOrM929(x) SETUP_XfOrM920(x)
          if (than_id_marks_ht ) {
            t_ht = than_id_marks_ht ; 
            than_id_marks_ht = ((void * ) 0 ) ; 
          }
          else t_ht = FUNCCALL(SETUP_XfOrM929(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
          FUNCCALL(SETUP_XfOrM929(_), add_all_marks (((Scheme_Stx * ) than_id ) -> wraps , t_ht ) ); 
        }
        if (FUNCCALL(SETUP_XfOrM920(_), scheme_hash_get (t_ht , certs -> mark ) )) {
#         define XfOrM921_COUNT (0+XfOrM920_COUNT)
#         define SETUP_XfOrM921(x) SETUP_XfOrM920(x)
          for (j = 0 ; j < 2 ; j ++ ) {
            if (j )
              t_certs = ((Scheme_Cert * ) (((Scheme_Stx * ) than_id ) -> certs ? (((Scheme_Type ) (((((long ) (((Scheme_Stx * ) than_id ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) than_id ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) (((Scheme_Stx * ) than_id ) -> certs ) ) -> u . pair_val . car ) : ((Scheme_Stx * ) than_id ) -> certs ) : ((void * ) 0 ) ) ) ; 
            else t_certs = (Scheme_Cert * ) than_id_certs ; 
            while (t_certs ) {
              if (((t_certs -> mark ) == (certs -> mark ) ) )
                break ; 
              t_certs = t_certs -> next ; 
            }
            if (t_certs )
              break ; 
          }
          if (j == 2 ) {
#           define XfOrM922_COUNT (0+XfOrM921_COUNT)
#           define SETUP_XfOrM922(x) SETUP_XfOrM921(x)
            FUNCCALL(SETUP_XfOrM922(_), scheme_reset_hash_table (ht , ((void * ) 0 ) ) ); 
            id_marks_ht = ht ; 
            FUNCCALL(SETUP_XfOrM922(_), scheme_reset_hash_table (t_ht , ((void * ) 0 ) ) ); 
            than_id_marks_ht = t_ht ; 
            RET_VALUE_START (1 ) RET_VALUE_END ; 
          }
        }
      }
      certs = certs -> next ; 
    }
  }
  FUNCCALL(SETUP_XfOrM879(_), scheme_reset_hash_table (ht , ((void * ) 0 ) ) ); 
  id_marks_ht = ht ; 
  if (t_ht ) {
#   define XfOrM880_COUNT (0+XfOrM879_COUNT)
#   define SETUP_XfOrM880(x) SETUP_XfOrM879(x)
    FUNCCALL(SETUP_XfOrM880(_), scheme_reset_hash_table (t_ht , ((void * ) 0 ) ) ); 
    than_id_marks_ht = t_ht ; 
  }
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_stx_remove_extra_marks (Scheme_Object * a , Scheme_Object * relative_to , Scheme_Object * uid ) {
  Wrap_Pos aw ; 
  Wrap_Pos bw ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(9);
  BLOCK_SETUP_TOP((PUSH(bw.l, 0), PUSH(bw.a, 1), PUSH(aw.l, 2), PUSH(aw.a, 3), PUSH(a, 4), PUSH(relative_to, 5)));
# define XfOrM932_COUNT (6)
# define SETUP_XfOrM932(x) SETUP(XfOrM932_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  aw.l = NULLED_OUT ; 
  aw.a = NULLED_OUT ; 
  bw.l = NULLED_OUT ; 
  bw.a = NULLED_OUT ; 
  aw . l = ((Scheme_Stx * ) a ) -> wraps ; 
  (WRAP_POS_SET_FIRST (& aw ) ) ; 
  bw . l = ((Scheme_Stx * ) relative_to ) -> wraps ; 
  (WRAP_POS_SET_FIRST (& bw ) ) ; 
  if (! (same_marks (& aw , & bw , ((void * ) 0 ) , ((void * ) 0 ) ) ) ) {
    Scheme_Object * wraps = ((Scheme_Stx * ) relative_to ) -> wraps ; 
    BLOCK_SETUP((PUSH(wraps, 0+XfOrM932_COUNT)));
#   define XfOrM933_COUNT (1+XfOrM932_COUNT)
#   define SETUP_XfOrM933(x) SETUP(XfOrM933_COUNT)
    if (uid ) {
      Scheme_Object * rn ; 
      BLOCK_SETUP((PUSH(rn, 0+XfOrM933_COUNT)));
#     define XfOrM935_COUNT (1+XfOrM933_COUNT)
#     define SETUP_XfOrM935(x) SETUP(XfOrM935_COUNT)
      rn = NULLED_OUT ; 
      rn = FUNCCALL(SETUP_XfOrM935(_), scheme_make_rename (uid , 1 ) ); 
      FUNCCALL_AGAIN(scheme_set_rename (rn , 0 , relative_to ) ); 
      wraps = FUNCCALL_AGAIN(scheme_make_pair (rn , wraps ) ); 
    }
    {
      Scheme_Stx * stx = (Scheme_Stx * ) a ; 
      Scheme_Object * certs ; 
      BLOCK_SETUP((PUSH(stx, 0+XfOrM933_COUNT), PUSH(certs, 1+XfOrM933_COUNT)));
#     define XfOrM934_COUNT (2+XfOrM933_COUNT)
#     define SETUP_XfOrM934(x) SETUP(XfOrM934_COUNT)
      certs = NULLED_OUT ; 
      certs = stx -> certs ; 
      stx = (Scheme_Stx * ) FUNCCALL(SETUP_XfOrM934(_), scheme_make_stx (stx -> val , stx -> srcloc , stx -> props ) ); 
      stx -> wraps = wraps ; 
      stx -> certs = certs ; 
      a = (Scheme_Object * ) stx ; 
    }
  }
  RET_VALUE_START (a ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_stx_list_length (Scheme_Object * list ) {
  /* No conversion */
  int len ; 
  if (((Scheme_Type ) (((((long ) (list ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (list ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    list = ((Scheme_Stx * ) list ) -> val ; 
  len = 0 ; 
  while (! ((list ) == (scheme_null ) ) ) {
    if (((Scheme_Type ) (((((long ) (list ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (list ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
      list = ((Scheme_Stx * ) list ) -> val ; 
    if (((Scheme_Type ) (((((long ) (list ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (list ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
      len ++ ; 
      list = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . cdr ) ; 
    }
    else {
      if (! ((list ) == (scheme_null ) ) )
        len ++ ; 
      break ; 
    }
  }
  return len ; 
}
int scheme_stx_proper_list_length (Scheme_Object * list ) {
  /* No conversion */
  int len ; 
  Scheme_Object * turtle ; 
  if (((Scheme_Type ) (((((long ) (list ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (list ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    list = ((Scheme_Stx * ) list ) -> val ; 
  len = 0 ; 
  turtle = list ; 
  while (((Scheme_Type ) (((((long ) (list ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (list ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
    len ++ ; 
    list = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . cdr ) ; 
    if (((Scheme_Type ) (((((long ) (list ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (list ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
      list = ((Scheme_Stx * ) list ) -> val ; 
    if (! ((Scheme_Type ) (((((long ) (list ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (list ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
      break ; 
    len ++ ; 
    list = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . cdr ) ; 
    if (((Scheme_Type ) (((((long ) (list ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (list ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
      list = ((Scheme_Stx * ) list ) -> val ; 
    if (((turtle ) == (list ) ) )
      break ; 
    turtle = (((Scheme_Simple_Object * ) (turtle ) ) -> u . pair_val . cdr ) ; 
    if (((Scheme_Type ) (((((long ) (turtle ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (turtle ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
      turtle = ((Scheme_Stx * ) turtle ) -> val ; 
  }
  if (((list ) == (scheme_null ) ) )
    return len ; 
  return - 1 ; 
}
static Scheme_Object * flatten_syntax_list_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * l = (Scheme_Object * ) p -> ku . k . p1 ; 
  int * r = (int * ) p -> ku . k . p2 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  p -> ku . k . p2 = ((void * ) 0 ) ; 
  return scheme_flatten_syntax_list (l , r ) ; 
}
Scheme_Object * scheme_flatten_syntax_list (Scheme_Object * lst , int * islist ) {
  Scheme_Object * l = lst , * lflat , * first , * last ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(first, 0), PUSH(last, 1), PUSH(islist, 2), PUSH(lflat, 3), PUSH(l, 4), PUSH(lst, 5)));
# define XfOrM947_COUNT (6)
# define SETUP_XfOrM947(x) SETUP(XfOrM947_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  lflat = NULLED_OUT ; 
  first = NULLED_OUT ; 
  last = NULLED_OUT ; 
  while (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
    l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
  }
  if (((l ) == (scheme_null ) ) ) {
    if (islist )
      * islist = 1 ; 
    RET_VALUE_START (lst ) RET_VALUE_END ; 
  }
  if (islist )
    * islist = 0 ; 
  lflat = ((void * ) 0 ) ; 
  if (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ) {
#   define XfOrM951_COUNT (0+XfOrM947_COUNT)
#   define SETUP_XfOrM951(x) SETUP_XfOrM947(x)
    l = FUNCCALL(SETUP_XfOrM951(_), scheme_stx_content (l ) ); 
    if (((l ) == (scheme_null ) ) || ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
      int lislist ; 
#     define XfOrM953_COUNT (0+XfOrM951_COUNT)
#     define SETUP_XfOrM953(x) SETUP_XfOrM951(x)
      lflat = ((void * ) 0 ) ; 
      {
        unsigned long _stk_pos ; 
#       define XfOrM955_COUNT (0+XfOrM953_COUNT)
#       define SETUP_XfOrM955(x) SETUP_XfOrM953(x)
        _stk_pos = (unsigned long ) & _stk_pos ; 
        if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
          Scheme_Thread * p = scheme_current_thread ; 
          int * r ; 
          BLOCK_SETUP((PUSH(r, 0+XfOrM955_COUNT), PUSH(p, 1+XfOrM955_COUNT)));
#         define XfOrM956_COUNT (2+XfOrM955_COUNT)
#         define SETUP_XfOrM956(x) SETUP(XfOrM956_COUNT)
          r = NULLED_OUT ; 
          r = (int * ) FUNCCALL(SETUP_XfOrM956(_), GC_malloc_atomic (sizeof (int ) ) ); 
          p -> ku . k . p1 = (void * ) l ; 
          p -> ku . k . p2 = (void * ) r ; 
          lflat = FUNCCALL(SETUP_XfOrM956(_), scheme_handle_stack_overflow (flatten_syntax_list_k ) ); 
          lislist = * r ; 
        }
      }
      if (! lflat )
        lflat = FUNCCALL(SETUP_XfOrM953(_), scheme_flatten_syntax_list (l , & lislist ) ); 
      if (! lislist ) {
        RET_VALUE_START (lst ) RET_VALUE_END ; 
      }
    }
    else {
      RET_VALUE_START (lst ) RET_VALUE_END ; 
    }
  }
  else {
    RET_VALUE_START (lst ) RET_VALUE_END ; 
  }
  if (islist )
    * islist = 1 ; 
  first = last = ((void * ) 0 ) ; 
  for (l = lst ; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
    Scheme_Object * p ; 
    BLOCK_SETUP((PUSH(p, 0+XfOrM947_COUNT)));
#   define XfOrM949_COUNT (1+XfOrM947_COUNT)
#   define SETUP_XfOrM949(x) SETUP(XfOrM949_COUNT)
    p = NULLED_OUT ; 
    p = FUNCCALL(SETUP_XfOrM949(_), scheme_make_immutable_pair ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) , scheme_null ) ); 
    if (last )
      (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = p ; 
    else first = p ; 
    last = p ; 
  }
  if (last )
    (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = lflat ; 
  else first = lflat ; 
  RET_VALUE_START (first ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void simplify_lex_renames (Scheme_Object * wraps , Scheme_Hash_Table * lex_cache ) {
  Wrap_Pos w ; 
  Wrap_Pos prev ; 
  Wrap_Pos w2 ; 
  Scheme_Object * stack = scheme_null , * key , * old_key ; 
  Scheme_Object * v , * v2 , * v2l , * stx , * name , * svl ; 
  long size , vsize , psize , i , j , pos ; 
  PREPARE_VAR_STACK(26);
  BLOCK_SETUP_TOP((PUSH(svl, 0), PUSH(old_key, 1), PUSH(stx, 2), PUSH(v, 3), PUSH(lex_cache, 4), PUSH(key, 5), PUSH(w.l, 6), PUSH(w.a, 7), PUSH(prev.l, 8), PUSH(prev.a, 9), PUSH(name, 10), PUSH(stack, 11), PUSH(v2l, 12), PUSH(v2, 13), PUSH(w2.l, 14), PUSH(w2.a, 15), PUSH(wraps, 16)));
# define XfOrM960_COUNT (17)
# define SETUP_XfOrM960(x) SETUP(XfOrM960_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  w.l = NULLED_OUT ; 
  w.a = NULLED_OUT ; 
  prev.l = NULLED_OUT ; 
  prev.a = NULLED_OUT ; 
  w2.l = NULLED_OUT ; 
  w2.a = NULLED_OUT ; 
  key = NULLED_OUT ; 
  old_key = NULLED_OUT ; 
  v = NULLED_OUT ; 
  v2 = NULLED_OUT ; 
  v2l = NULLED_OUT ; 
  stx = NULLED_OUT ; 
  name = NULLED_OUT ; 
  svl = NULLED_OUT ; 
  w . l = wraps ; 
  (WRAP_POS_SET_FIRST (& w ) ) ; 
  (prev . l = scheme_null , prev . a = ((void * ) 0 ) , prev . is_limb = 0 , prev . pos = 0 ) ; 
  old_key = ((void * ) 0 ) ; 
  while (! ((w . l ) == (scheme_null ) ) ) {
#   define XfOrM1330_COUNT (0+XfOrM960_COUNT)
#   define SETUP_XfOrM1330(x) SETUP_XfOrM960(x)
    if (((Scheme_Type ) (((((long ) (w . a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (w . a ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) || ((Scheme_Type ) (scheme_lexical_rib_type ) == (Scheme_Type ) (((((long ) (w . a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (w . a ) ) -> type ) ) ) ) {
#     define XfOrM1331_COUNT (0+XfOrM1330_COUNT)
#     define SETUP_XfOrM1331(x) SETUP_XfOrM1330(x)
      key = w . l ; 
      if (! ((key ) == (old_key ) ) ) {
#       define XfOrM1340_COUNT (0+XfOrM1331_COUNT)
#       define SETUP_XfOrM1340(x) SETUP_XfOrM1331(x)
        v = FUNCCALL(SETUP_XfOrM1340(_), scheme_hash_get (lex_cache , key ) ); 
      }
      else v = ((void * ) 0 ) ; 
      old_key = key ; 
      if (v ) {
        prev . l = (w ) . l ; 
        prev . a = (w ) . a ; 
        prev . is_limb = (w ) . is_limb ; 
        prev . pos = (w ) . pos ; 
        break ; 
      }
      else {
        int add = 0 ; 
#       define XfOrM1332_COUNT (0+XfOrM1331_COUNT)
#       define SETUP_XfOrM1332(x) SETUP_XfOrM1331(x)
        v = w . a ; 
        if (((Scheme_Type ) (scheme_lexical_rib_type ) == (Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) ) ) {
          add = 1 ; 
        }
        else {
          if ((((Scheme_Vector * ) (v ) ) -> size ) == 1 )
            v = (((Scheme_Vector * ) (v ) ) -> els ) [0 ] ; 
          if (((((Scheme_Vector * ) (v ) ) -> size ) > 2 ) && ! ((Scheme_Type ) (((((long ) ((((Scheme_Vector * ) (v ) ) -> els ) [2 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Vector * ) (v ) ) -> els ) [2 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
            add = 1 ; 
          }
        }
        if (add ) {
#         define XfOrM1334_COUNT (0+XfOrM1332_COUNT)
#         define SETUP_XfOrM1334(x) SETUP_XfOrM1332(x)
          if (((stack ) == (scheme_null ) ) || ! (((((Scheme_Simple_Object * ) (stack ) ) -> u . pair_val . car ) ) == (key ) ) ) {
#           define XfOrM1335_COUNT (0+XfOrM1334_COUNT)
#           define SETUP_XfOrM1335(x) SETUP_XfOrM1334(x)
            stack = FUNCCALL(SETUP_XfOrM1335(_), scheme_make_pair (key , stack ) ); 
          }
        }
        else {
          if (((prev . l ) == (scheme_null ) ) )
            prev . l = (w ) . l ; 
          prev . a = (w ) . a ; 
          prev . is_limb = (w ) . is_limb ; 
          prev . pos = (w ) . pos ; 
          break ; 
        }
      }
    }
    (DO_WRAP_POS_INC (& w ) ) ; 
  }
  while (! ((stack ) == (scheme_null ) ) ) {
#   define XfOrM1140_COUNT (0+XfOrM960_COUNT)
#   define SETUP_XfOrM1140(x) SETUP_XfOrM960(x)
    key = (((Scheme_Simple_Object * ) (stack ) ) -> u . pair_val . car ) ; 
    v2l = scheme_null ; 
    (DO_WRAP_POS_REVINIT (& w , key ) ) ; 
    while (! (w . pos < 0 ) ) {
#     define XfOrM1230_COUNT (0+XfOrM1140_COUNT)
#     define SETUP_XfOrM1230(x) SETUP_XfOrM1140(x)
      v = w . a ; 
      if (((Scheme_Type ) (scheme_lexical_rib_type ) == (Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) ) || (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) && ((((Scheme_Vector * ) (v ) ) -> size ) > 2 ) && ! ((Scheme_Type ) (((((long ) ((((Scheme_Vector * ) (v ) ) -> els ) [2 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Vector * ) (v ) ) -> els ) [2 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) {
        Scheme_Lexical_Rib * rib = ((void * ) 0 ) , * init_rib = ((void * ) 0 ) ; 
        Scheme_Object * skip_ribs = ((void * ) 0 ) ; 
        int ii , vvsize ; 
        BLOCK_SETUP((PUSH(init_rib, 0+XfOrM1230_COUNT), PUSH(rib, 1+XfOrM1230_COUNT), PUSH(skip_ribs, 2+XfOrM1230_COUNT)));
#       define XfOrM1231_COUNT (3+XfOrM1230_COUNT)
#       define SETUP_XfOrM1231(x) SETUP(XfOrM1231_COUNT)
        if (((Scheme_Type ) (scheme_lexical_rib_type ) == (Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) ) ) {
          init_rib = (Scheme_Lexical_Rib * ) v ; 
          skip_ribs = init_rib -> timestamp ; 
          rib = init_rib -> next ; 
          vsize = 0 ; 
          while (rib ) {
            vsize += (((((Scheme_Vector * ) (rib -> rename ) ) -> size ) - 2 ) >> 1 ) ; 
            rib = rib -> next ; 
          }
          rib = init_rib -> next ; 
        }
        else vsize = (((((Scheme_Vector * ) (v ) ) -> size ) - 2 ) >> 1 ) ; 
        size = vsize ; 
        v2 = FUNCCALL(SETUP_XfOrM1231(_), scheme_make_vector (2 + (2 * size ) , ((void * ) 0 ) ) ); 
        pos = 0 ; 
        ii = 0 ; 
        vvsize = vsize ; 
        for (i = 0 ; i < vsize ; i ++ ) {
#         define XfOrM1276_COUNT (0+XfOrM1231_COUNT)
#         define SETUP_XfOrM1276(x) SETUP_XfOrM1231(x)
          if (rib ) {
            v = rib -> rename ; 
            vvsize = (((((Scheme_Vector * ) (v ) ) -> size ) - 2 ) >> 1 ) ; 
            while (ii >= vvsize ) {
              ii = 0 ; 
              rib = rib -> next ; 
              v = rib -> rename ; 
              vvsize = (((((Scheme_Vector * ) (v ) ) -> size ) - 2 ) >> 1 ) ; 
            }
          }
          stx = (((Scheme_Vector * ) (v ) ) -> els ) [2 + ii ] ; 
          name = ((Scheme_Stx * ) stx ) -> val ; 
          (((Scheme_Vector * ) (v2 ) ) -> els ) [2 + pos ] = name ; 
          {
            Scheme_Object * ok = ((void * ) 0 ) , * ok_replace = ((void * ) 0 ) ; 
            int ok_replace_index = 0 ; 
            BLOCK_SETUP((PUSH(ok, 0+XfOrM1276_COUNT), PUSH(ok_replace, 1+XfOrM1276_COUNT)));
#           define XfOrM1277_COUNT (2+XfOrM1276_COUNT)
#           define SETUP_XfOrM1277(x) SETUP(XfOrM1277_COUNT)
            if (! ((prev . l ) == (scheme_null ) ) || ((Scheme_Type ) (((((long ) (v2l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v2l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
              Wrap_Pos w3 ; 
              Scheme_Object * vp ; 
              Scheme_Object * other_env ; 
              BLOCK_SETUP((PUSH(other_env, 0+XfOrM1277_COUNT), PUSH(w3.l, 1+XfOrM1277_COUNT), PUSH(w3.a, 2+XfOrM1277_COUNT), PUSH(vp, 3+XfOrM1277_COUNT)));
#             define XfOrM1282_COUNT (4+XfOrM1277_COUNT)
#             define SETUP_XfOrM1282(x) SETUP(XfOrM1282_COUNT)
              w3.l = NULLED_OUT ; 
              w3.a = NULLED_OUT ; 
              vp = NULLED_OUT ; 
              other_env = NULLED_OUT ; 
              other_env = (((Scheme_Vector * ) (v ) ) -> els ) [2 + vvsize + ii ] ; 
              if ((((other_env ) ) == (scheme_void ) ) ) {
#               define XfOrM1312_COUNT (0+XfOrM1282_COUNT)
#               define SETUP_XfOrM1312(x) SETUP_XfOrM1282(x)
                other_env = FUNCCALL(SETUP_XfOrM1312(_), resolve_env (((void * ) 0 ) , stx , 0 , 0 , ((void * ) 0 ) , skip_ribs ) ); 
                (((Scheme_Vector * ) (v ) ) -> els ) [2 + vvsize + ii ] = other_env ; 
              }
              w2 . l = ((Scheme_Stx * ) stx ) -> wraps ; 
              (WRAP_POS_SET_FIRST (& w2 ) ) ; 
              if (! (same_marks (& w2 , & w , other_env , (Scheme_Object * ) init_rib ) ) ) {
                other_env = ((void * ) 0 ) ; 
              }
              if (other_env ) {
#               define XfOrM1283_COUNT (0+XfOrM1282_COUNT)
#               define SETUP_XfOrM1283(x) SETUP_XfOrM1282(x)
                if (! ok ) {
#                 define XfOrM1284_COUNT (0+XfOrM1283_COUNT)
#                 define SETUP_XfOrM1284(x) SETUP_XfOrM1283(x)
                  w3 . l = (prev ) . l ; 
                  w3 . a = (prev ) . a ; 
                  w3 . is_limb = (prev ) . is_limb ; 
                  w3 . pos = (prev ) . pos ; 
                  svl = v2l ; 
                  for (; ((Scheme_Type ) (((((long ) (svl ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (svl ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || ! ((w3 . l ) == (scheme_null ) ) ; ) {
#                   define XfOrM1298_COUNT (0+XfOrM1284_COUNT)
#                   define SETUP_XfOrM1298(x) SETUP_XfOrM1284(x)
                    if (((Scheme_Type ) (((((long ) (svl ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (svl ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
                      vp = (((Scheme_Simple_Object * ) (svl ) ) -> u . pair_val . car ) ; 
                    else vp = w3 . a ; 
                    if (((Scheme_Type ) (((((long ) (vp ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vp ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
                      psize = (((((Scheme_Vector * ) (vp ) ) -> size ) - 2 ) >> 1 ) ; 
                      for (j = 0 ; j < psize ; j ++ ) {
                        if ((((((Scheme_Vector * ) (vp ) ) -> els ) [2 + j ] ) == (name ) ) ) {
                          if ((((((Scheme_Vector * ) (vp ) ) -> els ) [2 + psize + j ] ) == (other_env ) ) ) {
                            ok = (((Scheme_Vector * ) (v ) ) -> els ) [0 ] ; 
                          }
                          else {
                            ok = ((void * ) 0 ) ; 
                          }
                          if (ok && ((Scheme_Type ) (((((long ) (svl ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (svl ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
                            ok_replace = vp ; 
                            ok_replace_index = 2 + psize + j ; 
                          }
                          break ; 
                        }
                      }
                      if (j < psize )
                        break ; 
                    }
                    if (((Scheme_Type ) (((((long ) (svl ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (svl ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
                      svl = (((Scheme_Simple_Object * ) (svl ) ) -> u . pair_val . cdr ) ; 
                    else {
#                     define XfOrM1299_COUNT (0+XfOrM1298_COUNT)
#                     define SETUP_XfOrM1299(x) SETUP_XfOrM1298(x)
                      (DO_WRAP_POS_INC (& w3 ) ) ; 
                    }
                  }
                  if (((w3 . l ) == (scheme_null ) ) && ((svl ) == (scheme_null ) ) && (((other_env ) ) == (scheme_false ) ) )
                    ok = (((Scheme_Vector * ) (v ) ) -> els ) [0 ] ; 
                }
                else ok = ((void * ) 0 ) ; 
              }
            }
            else {
#             define XfOrM1281_COUNT (0+XfOrM1277_COUNT)
#             define SETUP_XfOrM1281(x) SETUP_XfOrM1277(x)
              w2 . l = ((Scheme_Stx * ) stx ) -> wraps ; 
              (WRAP_POS_SET_FIRST (& w2 ) ) ; 
              if ((same_marks (& w2 , & w , scheme_false , (Scheme_Object * ) init_rib ) ) )
                ok = (((Scheme_Vector * ) (v ) ) -> els ) [0 ] ; 
              else ok = ((void * ) 0 ) ; 
            }
            if (ok ) {
              if (ok_replace ) {
                (((Scheme_Vector * ) (ok_replace ) ) -> els ) [ok_replace_index ] = ok ; 
              }
              else {
                (((Scheme_Vector * ) (v2 ) ) -> els ) [2 + size + pos ] = ok ; 
                pos ++ ; 
              }
            }
          }
          ii ++ ; 
        }
        if (pos != size ) {
#         define XfOrM1232_COUNT (0+XfOrM1231_COUNT)
#         define SETUP_XfOrM1232(x) SETUP_XfOrM1231(x)
          if (! pos )
            v2 = empty_simplified ; 
          else {
#           define XfOrM1233_COUNT (0+XfOrM1232_COUNT)
#           define SETUP_XfOrM1233(x) SETUP_XfOrM1232(x)
            v = v2 ; 
            v2 = FUNCCALL(SETUP_XfOrM1233(_), scheme_make_vector (2 + (2 * pos ) , ((void * ) 0 ) ) ); 
            for (i = 0 ; i < pos ; i ++ ) {
              (((Scheme_Vector * ) (v2 ) ) -> els ) [2 + i ] = (((Scheme_Vector * ) (v ) ) -> els ) [2 + i ] ; 
              (((Scheme_Vector * ) (v2 ) ) -> els ) [2 + pos + i ] = (((Scheme_Vector * ) (v ) ) -> els ) [2 + size + i ] ; 
            }
          }
        }
        (((Scheme_Vector * ) (v2 ) ) -> els ) [0 ] = scheme_false ; 
        (((Scheme_Vector * ) (v2 ) ) -> els ) [1 ] = scheme_false ; 
        v2l = FUNCCALL(SETUP_XfOrM1231(_), scheme_make_pair (v2 , v2l ) ); 
      }
      -- w . pos ; 
      if (w . pos >= 0 )
        w . a = ((Wrap_Chunk * ) (((Scheme_Simple_Object * ) (w . l ) ) -> u . pair_val . car ) ) -> a [w . pos ] ; 
    }
    FUNCCALL(SETUP_XfOrM1140(_), scheme_hash_set (lex_cache , key , v2l ) ); 
    stack = (((Scheme_Simple_Object * ) (stack ) ) -> u . pair_val . cdr ) ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * wraps_to_datum (Scheme_Object * w_in , Scheme_Marshal_Tables * mt , Scheme_Hash_Table * rns , int just_simplify ) {
  Scheme_Object * stack , * a , * old_key , * simplifies = scheme_null ; 
  Wrap_Pos w ; 
  Scheme_Hash_Table * lex_cache , * reverse_map ; 
  int stack_size = 0 ; 
  Scheme_Object * __funcarg75 = NULLED_OUT ; 
  Scheme_Object * __funcarg74 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(17);
  BLOCK_SETUP_TOP((PUSH(rns, 0), PUSH(simplifies, 1), PUSH(a, 2), PUSH(w_in, 3), PUSH(old_key, 4), PUSH(stack, 5), PUSH(reverse_map, 6), PUSH(mt, 7), PUSH(lex_cache, 8), PUSH(w.l, 9), PUSH(w.a, 10)));
# define XfOrM1341_COUNT (11)
# define SETUP_XfOrM1341(x) SETUP(XfOrM1341_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  stack = NULLED_OUT ; 
  a = NULLED_OUT ; 
  old_key = NULLED_OUT ; 
  w.l = NULLED_OUT ; 
  w.a = NULLED_OUT ; 
  lex_cache = NULLED_OUT ; 
  reverse_map = NULLED_OUT ; 
  if (! rns )
    rns = mt -> rns ; 
  if (just_simplify ) {
#   define XfOrM1475_COUNT (0+XfOrM1341_COUNT)
#   define SETUP_XfOrM1475(x) SETUP_XfOrM1341(x)
    a = FUNCCALL(SETUP_XfOrM1475(_), scheme_hash_get (rns , w_in ) ); 
  }
  else {
#   define XfOrM1473_COUNT (0+XfOrM1341_COUNT)
#   define SETUP_XfOrM1473(x) SETUP_XfOrM1341(x)
    if (mt -> pass && mt -> same_map ) {
#     define XfOrM1474_COUNT (0+XfOrM1473_COUNT)
#     define SETUP_XfOrM1474(x) SETUP_XfOrM1473(x)
      a = FUNCCALL(SETUP_XfOrM1474(_), scheme_hash_get (mt -> same_map , w_in ) ); 
      if (a )
        w_in = a ; 
    }
    a = FUNCCALL(SETUP_XfOrM1473(_), scheme_marshal_lookup (mt , w_in ) ); 
  }
  if (a ) {
#   define XfOrM1471_COUNT (0+XfOrM1341_COUNT)
#   define SETUP_XfOrM1471(x) SETUP_XfOrM1341(x)
    if (just_simplify )
      RET_VALUE_START (a ) RET_VALUE_END ; 
    else {
#     define XfOrM1472_COUNT (0+XfOrM1471_COUNT)
#     define SETUP_XfOrM1472(x) SETUP_XfOrM1471(x)
      FUNCCALL(SETUP_XfOrM1472(_), scheme_marshal_using_key (mt , w_in ) ); 
      RET_VALUE_START (a ) RET_VALUE_END ; 
    }
  }
  w . l = w_in ; 
  (WRAP_POS_SET_FIRST (& w ) ) ; 
  stack = scheme_null ; 
  lex_cache = (Scheme_Hash_Table * ) FUNCCALL(SETUP_XfOrM1341(_), scheme_hash_get (rns , scheme_void ) ); 
  if (! lex_cache ) {
#   define XfOrM1470_COUNT (0+XfOrM1341_COUNT)
#   define SETUP_XfOrM1470(x) SETUP_XfOrM1341(x)
    lex_cache = FUNCCALL(SETUP_XfOrM1470(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
    FUNCCALL(SETUP_XfOrM1470(_), scheme_hash_set (rns , scheme_void , (Scheme_Object * ) lex_cache ) ); 
  }
  FUNCCALL(SETUP_XfOrM1341(_), simplify_lex_renames (w_in , lex_cache ) ); 
  if (mt )
    FUNCCALL(SETUP_XfOrM1341(_), scheme_marshal_push_refs (mt ) ); 
  while (! ((w . l ) == (scheme_null ) ) ) {
#   define XfOrM1414_COUNT (0+XfOrM1341_COUNT)
#   define SETUP_XfOrM1414(x) SETUP_XfOrM1341(x)
    a = w . a ; 
    old_key = w . l ; 
    (DO_WRAP_POS_INC (& w ) ) ; 
    if (((((long ) (a ) ) & 0x1 ) || ((((a ) -> type ) >= scheme_bignum_type ) && (((a ) -> type ) <= scheme_complex_type ) ) ) ) {
#     define XfOrM1468_COUNT (0+XfOrM1414_COUNT)
#     define SETUP_XfOrM1468(x) SETUP_XfOrM1414(x)
      if (! ((w . l ) == (scheme_null ) ) && ((a ) == (w . a ) ) )
        (DO_WRAP_POS_INC (& w ) ) ; 
      else {
#       define XfOrM1469_COUNT (0+XfOrM1468_COUNT)
#       define SETUP_XfOrM1469(x) SETUP_XfOrM1468(x)
        if (just_simplify )
          stack = FUNCCALL(SETUP_XfOrM1469(_), scheme_make_pair (a , stack ) ); 
        else stack = (__funcarg75 = FUNCCALL(SETUP_XfOrM1469(_), scheme_make_pair (a , scheme_null ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg75 , stack ) )) ; 
        stack_size ++ ; 
      }
    }
    else if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) || ((Scheme_Type ) (scheme_lexical_rib_type ) == (Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) ) ) {
#     define XfOrM1459_COUNT (0+XfOrM1414_COUNT)
#     define SETUP_XfOrM1459(x) SETUP_XfOrM1414(x)
      if (((Scheme_Type ) (scheme_lexical_rib_type ) == (Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) ) || ((((Scheme_Vector * ) (a ) ) -> size ) > 2 ) ) {
#       define XfOrM1460_COUNT (0+XfOrM1459_COUNT)
#       define SETUP_XfOrM1460(x) SETUP_XfOrM1459(x)
        if (((Scheme_Type ) (scheme_lexical_rib_type ) == (Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) ) || ! ((Scheme_Type ) (((((long ) ((((Scheme_Vector * ) (a ) ) -> els ) [2 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Vector * ) (a ) ) -> els ) [2 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
#         define XfOrM1466_COUNT (0+XfOrM1460_COUNT)
#         define SETUP_XfOrM1466(x) SETUP_XfOrM1460(x)
          if (((simplifies ) == (scheme_null ) ) ) {
#           define XfOrM1467_COUNT (0+XfOrM1466_COUNT)
#           define SETUP_XfOrM1467(x) SETUP_XfOrM1466(x)
            simplifies = FUNCCALL(SETUP_XfOrM1467(_), scheme_hash_get (lex_cache , old_key ) ); 
          }
          a = (((Scheme_Simple_Object * ) (simplifies ) ) -> u . pair_val . car ) ; 
          simplifies = (((Scheme_Simple_Object * ) (simplifies ) ) -> u . pair_val . cdr ) ; 
        }
        if ((((Scheme_Vector * ) (a ) ) -> size ) > 2 ) {
#         define XfOrM1461_COUNT (0+XfOrM1460_COUNT)
#         define SETUP_XfOrM1461(x) SETUP_XfOrM1460(x)
          if (just_simplify ) {
#           define XfOrM1465_COUNT (0+XfOrM1461_COUNT)
#           define SETUP_XfOrM1465(x) SETUP_XfOrM1461(x)
            stack = FUNCCALL(SETUP_XfOrM1465(_), scheme_make_pair (a , stack ) ); 
          }
          else {
            Scheme_Object * local_key ; 
            BLOCK_SETUP((PUSH(local_key, 0+XfOrM1461_COUNT)));
#           define XfOrM1462_COUNT (1+XfOrM1461_COUNT)
#           define SETUP_XfOrM1462(x) SETUP(XfOrM1462_COUNT)
            local_key = NULLED_OUT ; 
            local_key = FUNCCALL(SETUP_XfOrM1462(_), scheme_marshal_lookup (mt , a ) ); 
            if (local_key ) {
#             define XfOrM1464_COUNT (0+XfOrM1462_COUNT)
#             define SETUP_XfOrM1464(x) SETUP_XfOrM1462(x)
              FUNCCALL(SETUP_XfOrM1464(_), scheme_marshal_using_key (mt , a ) ); 
              a = local_key ; 
            }
            else {
#             define XfOrM1463_COUNT (0+XfOrM1462_COUNT)
#             define SETUP_XfOrM1463(x) SETUP_XfOrM1462(x)
              a = FUNCCALL(SETUP_XfOrM1463(_), scheme_marshal_wrap_set (mt , a , a ) ); 
            }
            stack = FUNCCALL(SETUP_XfOrM1462(_), scheme_make_pair (a , stack ) ); 
          }
          stack_size ++ ; 
        }
      }
    }
    else if ((((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_rename_table_type ) ) ) ) {
      Module_Renames * mrn = (Module_Renames * ) a ; 
      int redundant = 0 ; 
      BLOCK_SETUP((PUSH(mrn, 0+XfOrM1414_COUNT)));
#     define XfOrM1419_COUNT (1+XfOrM1414_COUNT)
#     define SETUP_XfOrM1419(x) SETUP(XfOrM1419_COUNT)
      if (mrn -> kind == 2 ) {
#       define XfOrM1453_COUNT (0+XfOrM1419_COUNT)
#       define SETUP_XfOrM1453(x) SETUP_XfOrM1419(x)
        redundant = ! mrn -> marked_names -> count ; 
        if (! redundant ) {
          Wrap_Pos l ; 
          Scheme_Object * la ; 
#         define XfOrM1454_COUNT (0+XfOrM1453_COUNT)
#         define SETUP_XfOrM1454(x) SETUP_XfOrM1453(x)
          l.l = NULLED_OUT ; 
          l.a = NULLED_OUT ; 
          la = NULLED_OUT ; 
          l . l = (w ) . l ; 
          l . a = (w ) . a ; 
          l . is_limb = (w ) . is_limb ; 
          l . pos = (w ) . pos ; 
          for (; ! ((l . l ) == (scheme_null ) ) ; (DO_WRAP_POS_INC (& l ) ) ) {
            la = l . a ; 
            if (((a ) == (la ) ) ) {
              redundant = 1 ; 
              break ; 
            }
          }
        }
      }
      else {
        long shift = 0 ; 
        Wrap_Pos l ; 
        Scheme_Object * la ; 
#       define XfOrM1444_COUNT (0+XfOrM1419_COUNT)
#       define SETUP_XfOrM1444(x) SETUP_XfOrM1419(x)
        l.l = NULLED_OUT ; 
        l.a = NULLED_OUT ; 
        la = NULLED_OUT ; 
        l . l = (w ) . l ; 
        l . a = (w ) . a ; 
        l . is_limb = (w ) . is_limb ; 
        l . pos = (w ) . pos ; 
        for (; ! ((l . l ) == (scheme_null ) ) ; (DO_WRAP_POS_INC (& l ) ) ) {
          la = l . a ; 
          if ((((Scheme_Type ) (((((long ) (la ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (la ) ) -> type ) ) == (Scheme_Type ) (scheme_rename_table_type ) ) ) ) {
            Module_Renames * lrn = (Module_Renames * ) l . a ; 
            if ((lrn -> kind == mrn -> kind ) && ((lrn -> phase + shift ) == mrn -> phase ) ) {
              redundant = 1 ; 
              break ; 
            }
          }
          else if (((Scheme_Type ) (((((long ) (la ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (la ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) {
            shift += (((long ) ((((Scheme_Vector * ) ((((Scheme_Small_Object * ) (l . a ) ) -> u . ptr_val ) ) ) -> els ) [0 ] ) ) >> 1 ) ; 
          }
        }
      }
      if (! redundant ) {
#       define XfOrM1420_COUNT (0+XfOrM1419_COUNT)
#       define SETUP_XfOrM1420(x) SETUP_XfOrM1419(x)
        if (just_simplify ) {
#         define XfOrM1443_COUNT (0+XfOrM1420_COUNT)
#         define SETUP_XfOrM1443(x) SETUP_XfOrM1420(x)
          stack = FUNCCALL(SETUP_XfOrM1443(_), scheme_make_pair ((Scheme_Object * ) mrn , stack ) ); 
        }
        else {
#         define XfOrM1421_COUNT (0+XfOrM1420_COUNT)
#         define SETUP_XfOrM1421(x) SETUP_XfOrM1420(x)
          if (mrn -> kind == 0 ) {
#           define XfOrM1442_COUNT (0+XfOrM1421_COUNT)
#           define SETUP_XfOrM1442(x) SETUP_XfOrM1421(x)
            stack = FUNCCALL(SETUP_XfOrM1442(_), scheme_make_pair (((mrn -> phase == 0 ) ? scheme_true : scheme_false ) , stack ) ); 
          }
          else {
            Scheme_Object * local_key ; 
            BLOCK_SETUP((PUSH(local_key, 0+XfOrM1421_COUNT)));
#           define XfOrM1422_COUNT (1+XfOrM1421_COUNT)
#           define SETUP_XfOrM1422(x) SETUP(XfOrM1422_COUNT)
            local_key = NULLED_OUT ; 
            local_key = FUNCCALL(SETUP_XfOrM1422(_), scheme_marshal_lookup (mt , (Scheme_Object * ) mrn ) ); 
            if (! local_key ) {
              int i , j , count = 0 ; 
              Scheme_Object * l , * idi ; 
              BLOCK_SETUP((PUSH(l, 0+XfOrM1422_COUNT), PUSH(idi, 1+XfOrM1422_COUNT)));
#             define XfOrM1424_COUNT (2+XfOrM1422_COUNT)
#             define SETUP_XfOrM1424(x) SETUP(XfOrM1424_COUNT)
              l = NULLED_OUT ; 
              idi = NULLED_OUT ; 
              count = mrn -> ht -> count ; 
              l = FUNCCALL(SETUP_XfOrM1424(_), scheme_make_vector (count * 2 , ((void * ) 0 ) ) ); 
              for (i = mrn -> ht -> size , j = 0 ; i -- ; ) {
#               define XfOrM1437_COUNT (0+XfOrM1424_COUNT)
#               define SETUP_XfOrM1437(x) SETUP_XfOrM1424(x)
                if (mrn -> ht -> vals [i ] ) {
#                 define XfOrM1438_COUNT (0+XfOrM1437_COUNT)
#                 define SETUP_XfOrM1438(x) SETUP_XfOrM1437(x)
                  (((Scheme_Vector * ) (l ) ) -> els ) [j ++ ] = mrn -> ht -> keys [i ] ; 
                  idi = mrn -> ht -> vals [i ] ; 
                  if (((Scheme_Type ) (((((long ) (idi ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (idi ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#                   define XfOrM1439_COUNT (0+XfOrM1438_COUNT)
#                   define SETUP_XfOrM1439(x) SETUP_XfOrM1438(x)
                    if ((((Scheme_Inclhash_Object * ) (idi ) ) -> so . keyex & 0x1 ) )
                      idi = (((Scheme_Simple_Object * ) (idi ) ) -> u . pair_val . car ) ; 
                    else if (((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (idi ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (idi ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#                     define XfOrM1440_COUNT (0+XfOrM1439_COUNT)
#                     define SETUP_XfOrM1440(x) SETUP_XfOrM1439(x)
                      if ((((long ) (((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (idi ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) ) & 0x1 ) ) {
#                       define XfOrM1441_COUNT (0+XfOrM1440_COUNT)
#                       define SETUP_XfOrM1441(x) SETUP_XfOrM1440(x)
                        idi = (__funcarg74 = FUNCCALL(SETUP_XfOrM1441(_), scheme_make_pair (((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (idi ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) , ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (idi ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) ), FUNCCALL_AGAIN(scheme_make_pair ((((Scheme_Simple_Object * ) (idi ) ) -> u . pair_val . car ) , __funcarg74 ) )) ; 
                      }
                      else idi = FUNCCALL(SETUP_XfOrM1440(_), scheme_make_pair ((((Scheme_Simple_Object * ) (idi ) ) -> u . pair_val . car ) , ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (idi ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) ); 
                    }
                  }
                  (((Scheme_Vector * ) (l ) ) -> els ) [j ++ ] = idi ; 
                }
              }
              if (mrn -> marked_names && mrn -> marked_names -> count ) {
                Scheme_Object * d = scheme_null , * p ; 
                BLOCK_SETUP((PUSH(d, 0+XfOrM1424_COUNT), PUSH(p, 1+XfOrM1424_COUNT)));
#               define XfOrM1427_COUNT (2+XfOrM1424_COUNT)
#               define SETUP_XfOrM1427(x) SETUP(XfOrM1427_COUNT)
                p = NULLED_OUT ; 
                for (i = mrn -> marked_names -> size ; i -- ; ) {
#                 define XfOrM1430_COUNT (0+XfOrM1427_COUNT)
#                 define SETUP_XfOrM1430(x) SETUP_XfOrM1427(x)
                  if (mrn -> marked_names -> vals [i ] ) {
#                   define XfOrM1431_COUNT (0+XfOrM1430_COUNT)
#                   define SETUP_XfOrM1431(x) SETUP_XfOrM1430(x)
                    p = FUNCCALL(SETUP_XfOrM1431(_), scheme_make_pair (mrn -> marked_names -> keys [i ] , mrn -> marked_names -> vals [i ] ) ); 
                    d = FUNCCALL(SETUP_XfOrM1431(_), scheme_make_pair (p , d ) ); 
                  }
                }
                l = FUNCCALL(SETUP_XfOrM1427(_), scheme_make_pair (l , d ) ); 
              }
              else l = FUNCCALL(SETUP_XfOrM1424(_), scheme_make_pair (l , scheme_null ) ); 
              if (((Scheme_Type ) (((((long ) (mrn -> unmarshal_info ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (mrn -> unmarshal_info ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
                l = FUNCCALL(SETUP_XfOrM1424(_), scheme_make_pair (mrn -> unmarshal_info , l ) ); 
              l = FUNCCALL(SETUP_XfOrM1424(_), scheme_make_pair ((mrn -> kind == 2 ) ? scheme_true : scheme_false , l ) ); 
              l = FUNCCALL_AGAIN(scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (mrn -> phase ) ) << 1 ) | 0x1 ) ) , l ) ); 
              if (mrn -> plus_kernel ) {
#               define XfOrM1426_COUNT (0+XfOrM1424_COUNT)
#               define SETUP_XfOrM1426(x) SETUP_XfOrM1424(x)
                l = FUNCCALL(SETUP_XfOrM1426(_), scheme_make_pair (scheme_true , l ) ); 
              }
              local_key = FUNCCALL(SETUP_XfOrM1424(_), scheme_marshal_lookup (mt , a ) ); 
              if (local_key )
                FUNCCALL(SETUP_XfOrM1424(_), scheme_marshal_using_key (mt , a ) ); 
              else {
#               define XfOrM1425_COUNT (0+XfOrM1424_COUNT)
#               define SETUP_XfOrM1425(x) SETUP_XfOrM1424(x)
                local_key = FUNCCALL(SETUP_XfOrM1425(_), scheme_marshal_wrap_set (mt , a , l ) ); 
              }
            }
            else {
#             define XfOrM1423_COUNT (0+XfOrM1422_COUNT)
#             define SETUP_XfOrM1423(x) SETUP_XfOrM1422(x)
              FUNCCALL(SETUP_XfOrM1423(_), scheme_marshal_using_key (mt , (Scheme_Object * ) mrn ) ); 
            }
            stack = FUNCCALL(SETUP_XfOrM1422(_), scheme_make_pair (local_key , stack ) ); 
          }
        }
        stack_size ++ ; 
      }
    }
    else if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
#     define XfOrM1418_COUNT (0+XfOrM1414_COUNT)
#     define SETUP_XfOrM1418(x) SETUP_XfOrM1414(x)
      stack = FUNCCALL(SETUP_XfOrM1418(_), scheme_make_pair (a , stack ) ); 
      stack_size ++ ; 
    }
    else if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) ) {
    }
    else {
      Scheme_Object * aa ; 
      BLOCK_SETUP((PUSH(aa, 0+XfOrM1414_COUNT)));
#     define XfOrM1415_COUNT (1+XfOrM1414_COUNT)
#     define SETUP_XfOrM1415(x) SETUP(XfOrM1415_COUNT)
      aa = NULLED_OUT ; 
      aa = (((Scheme_Small_Object * ) (a ) ) -> u . ptr_val ) ; 
      if ((! ((((((Scheme_Vector * ) (aa ) ) -> els ) [3 ] ) ) == (scheme_false ) ) ) ) {
#       define XfOrM1416_COUNT (0+XfOrM1415_COUNT)
#       define SETUP_XfOrM1416(x) SETUP_XfOrM1415(x)
        a = FUNCCALL(SETUP_XfOrM1416(_), scheme_make_vector (4 , ((void * ) 0 ) ) ); 
        (((Scheme_Vector * ) (a ) ) -> els ) [0 ] = (((Scheme_Vector * ) (aa ) ) -> els ) [0 ] ; 
        (((Scheme_Vector * ) (a ) ) -> els ) [1 ] = (((Scheme_Vector * ) (aa ) ) -> els ) [1 ] ; 
        (((Scheme_Vector * ) (a ) ) -> els ) [2 ] = (((Scheme_Vector * ) (aa ) ) -> els ) [2 ] ; 
        (((Scheme_Vector * ) (a ) ) -> els ) [3 ] = scheme_false ; 
        a = FUNCCALL(SETUP_XfOrM1416(_), scheme_box (a ) ); 
      }
      stack = FUNCCALL(SETUP_XfOrM1415(_), scheme_make_pair (a , stack ) ); 
      stack_size ++ ; 
    }
  }
  if (just_simplify ) {
#   define XfOrM1354_COUNT (0+XfOrM1341_COUNT)
#   define SETUP_XfOrM1354(x) SETUP_XfOrM1341(x)
    if (stack_size ) {
      Wrap_Chunk * wc ; 
      int i ; 
      BLOCK_SETUP((PUSH(wc, 0+XfOrM1354_COUNT)));
#     define XfOrM1355_COUNT (1+XfOrM1354_COUNT)
#     define SETUP_XfOrM1355(x) SETUP(XfOrM1355_COUNT)
      wc = NULLED_OUT ; 
      wc = (Wrap_Chunk * ) FUNCCALL(SETUP_XfOrM1355(_), GC_malloc_one_tagged (sizeof (Wrap_Chunk ) + ((stack_size - 1 ) * sizeof (Scheme_Object * ) ) ) ); 
      wc -> type = scheme_wrap_chunk_type ; 
      wc -> len = stack_size ; 
      for (i = stack_size ; i -- ; stack = (((Scheme_Simple_Object * ) (stack ) ) -> u . pair_val . cdr ) ) {
        wc -> a [i ] = (((Scheme_Simple_Object * ) (stack ) ) -> u . pair_val . car ) ; 
      }
      stack = FUNCCALL(SETUP_XfOrM1355(_), scheme_make_pair ((Scheme_Object * ) wc , scheme_null ) ); 
    }
    else stack = scheme_null ; 
  }
  if (mt && mt -> pass ) {
  }
  else {
#   define XfOrM1345_COUNT (0+XfOrM1341_COUNT)
#   define SETUP_XfOrM1345(x) SETUP_XfOrM1341(x)
    if (mt ) {
      reverse_map = mt -> reverse_map ; 
    }
    else {
#     define XfOrM1351_COUNT (0+XfOrM1345_COUNT)
#     define SETUP_XfOrM1351(x) SETUP_XfOrM1345(x)
      reverse_map = (Scheme_Hash_Table * ) FUNCCALL(SETUP_XfOrM1351(_), scheme_hash_get (rns , scheme_undefined ) ); 
    }
    if (! reverse_map ) {
#     define XfOrM1350_COUNT (0+XfOrM1345_COUNT)
#     define SETUP_XfOrM1350(x) SETUP_XfOrM1345(x)
      reverse_map = FUNCCALL(SETUP_XfOrM1350(_), scheme_make_hash_table_equal () ); 
      if (mt )
        mt -> reverse_map = reverse_map ; 
      else FUNCCALL(SETUP_XfOrM1350(_), scheme_hash_set (rns , scheme_undefined , (Scheme_Object * ) reverse_map ) ); 
    }
    old_key = FUNCCALL(SETUP_XfOrM1345(_), scheme_hash_get (reverse_map , stack ) ); 
    if (old_key ) {
#     define XfOrM1346_COUNT (0+XfOrM1345_COUNT)
#     define SETUP_XfOrM1346(x) SETUP_XfOrM1345(x)
      if (just_simplify ) {
#       define XfOrM1349_COUNT (0+XfOrM1346_COUNT)
#       define SETUP_XfOrM1349(x) SETUP_XfOrM1346(x)
        RET_VALUE_START (FUNCCALL(SETUP_XfOrM1349(_), scheme_hash_get (rns , old_key ) )) RET_VALUE_END ; 
      }
      else {
#       define XfOrM1347_COUNT (0+XfOrM1346_COUNT)
#       define SETUP_XfOrM1347(x) SETUP_XfOrM1346(x)
        a = FUNCCALL(SETUP_XfOrM1347(_), scheme_marshal_lookup (mt , old_key ) ); 
        FUNCCALL(SETUP_XfOrM1347(_), scheme_marshal_using_key (mt , old_key ) ); 
        if (! mt -> same_map ) {
          Scheme_Hash_Table * same_map ; 
          BLOCK_SETUP((PUSH(same_map, 0+XfOrM1347_COUNT)));
#         define XfOrM1348_COUNT (1+XfOrM1347_COUNT)
#         define SETUP_XfOrM1348(x) SETUP(XfOrM1348_COUNT)
          same_map = NULLED_OUT ; 
          same_map = FUNCCALL(SETUP_XfOrM1348(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
          mt -> same_map = same_map ; 
        }
        FUNCCALL(SETUP_XfOrM1347(_), scheme_hash_set (mt -> same_map , w_in , old_key ) ); 
        FUNCCALL(SETUP_XfOrM1347(_), scheme_marshal_pop_refs (mt , 0 ) ); 
        RET_VALUE_START (a ) RET_VALUE_END ; 
      }
    }
    FUNCCALL(SETUP_XfOrM1345(_), scheme_hash_set (reverse_map , stack , w_in ) ); 
  }
  if (mt ) {
#   define XfOrM1344_COUNT (0+XfOrM1341_COUNT)
#   define SETUP_XfOrM1344(x) SETUP_XfOrM1341(x)
    FUNCCALL(SETUP_XfOrM1344(_), scheme_marshal_pop_refs (mt , 1 ) ); 
  }
  if (just_simplify ) {
#   define XfOrM1343_COUNT (0+XfOrM1341_COUNT)
#   define SETUP_XfOrM1343(x) SETUP_XfOrM1341(x)
    FUNCCALL(SETUP_XfOrM1343(_), scheme_hash_set (rns , w_in , stack ) ); 
    RET_VALUE_START (stack ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM1342_COUNT (0+XfOrM1341_COUNT)
#   define SETUP_XfOrM1342(x) SETUP_XfOrM1341(x)
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM1342(_), scheme_marshal_wrap_set (mt , w_in , stack ) )) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * extract_for_common_wrap (Scheme_Object * a , int get_mark , int pair_ok ) {
  /* No conversion */
  Scheme_Object * v ; 
  if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
    v = (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) ; 
    if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
      if (pair_ok && (((((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) ) == (scheme_true ) ) ) {
        if (get_mark )
          return (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) ; 
        else return (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) ; 
      }
    }
    else if (! ((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) && ! ((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
      if (get_mark )
        return (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) ; 
      else return v ; 
    }
  }
  return ((void * ) 0 ) ; 
}
static void lift_common_wraps (Scheme_Object * l , Scheme_Object * common_wraps , int cnt , int tail ) {
  Scheme_Object * a ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(a, 0), PUSH(l, 1)));
# define XfOrM1481_COUNT (2)
# define SETUP_XfOrM1481(x) SETUP(XfOrM1481_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a = NULLED_OUT ; 
  while (cnt -- ) {
#   define XfOrM1484_COUNT (0+XfOrM1481_COUNT)
#   define SETUP_XfOrM1484(x) SETUP_XfOrM1481(x)
    a = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
    a = FUNCCALL(SETUP_XfOrM1484(_), extract_for_common_wrap (a , 0 , 1 ) ); 
    (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) = a ; 
    if (cnt )
      l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
  }
  if (tail ) {
#   define XfOrM1482_COUNT (0+XfOrM1481_COUNT)
#   define SETUP_XfOrM1482(x) SETUP_XfOrM1481(x)
    a = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
    a = FUNCCALL(SETUP_XfOrM1482(_), extract_for_common_wrap (a , 0 , 0 ) ); 
    (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) = a ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * syntax_to_datum_inner (Scheme_Object * o , Scheme_Hash_Table * * ht , int with_marks , Scheme_Marshal_Tables * mt ) ; 
static Scheme_Object * syntax_to_datum_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * o = (Scheme_Object * ) p -> ku . k . p1 ; 
  Scheme_Hash_Table * * ht = (Scheme_Hash_Table * * ) p -> ku . k . p2 ; 
  Scheme_Marshal_Tables * mt = (Scheme_Marshal_Tables * ) p -> ku . k . p3 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  p -> ku . k . p2 = ((void * ) 0 ) ; 
  p -> ku . k . p3 = ((void * ) 0 ) ; 
  return syntax_to_datum_inner (o , ht , p -> ku . k . i1 , mt ) ; 
}
static Scheme_Object * syntax_to_datum_inner (Scheme_Object * o , Scheme_Hash_Table * * ht , int with_marks , Scheme_Marshal_Tables * mt ) {
  Scheme_Stx * stx = (Scheme_Stx * ) o ; 
  Scheme_Object * ph , * v , * result , * converted_wraps = ((void * ) 0 ) ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(12);
  BLOCK_SETUP_TOP((PUSH(mt, 0), PUSH(converted_wraps, 1), PUSH(ph, 2), PUSH(ht, 3), PUSH(stx, 4), PUSH(v, 5), PUSH(result, 6)));
# define XfOrM1486_COUNT (7)
# define SETUP_XfOrM1486(x) SETUP(XfOrM1486_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  ph = NULLED_OUT ; 
  v = NULLED_OUT ; 
  result = NULLED_OUT ; 
  {
    unsigned long _stk_pos ; 
#   define XfOrM1519_COUNT (0+XfOrM1486_COUNT)
#   define SETUP_XfOrM1519(x) SETUP_XfOrM1486(x)
    _stk_pos = (unsigned long ) & _stk_pos ; 
    if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
      Scheme_Thread * p = scheme_current_thread ; 
#     define XfOrM1520_COUNT (0+XfOrM1519_COUNT)
#     define SETUP_XfOrM1520(x) SETUP_XfOrM1519(x)
      p -> ku . k . p1 = (void * ) o ; 
      p -> ku . k . p2 = (void * ) ht ; 
      p -> ku . k . i1 = with_marks ; 
      p -> ku . k . p3 = (void * ) mt ; 
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_handle_stack_overflow (syntax_to_datum_k ) )) RET_VALUE_EMPTY_END ; 
    }
  }
  {
#   define XfOrM1517_COUNT (0+XfOrM1486_COUNT)
#   define SETUP_XfOrM1517(x) SETUP_XfOrM1486(x)
    if ((scheme_fuel_counter ) <= 0 ) {
#     define XfOrM1518_COUNT (0+XfOrM1517_COUNT)
#     define SETUP_XfOrM1518(x) SETUP_XfOrM1517(x)
      FUNCCALL(SETUP_XfOrM1518(_), scheme_out_of_fuel () ); 
    }
  }
  ; 
  if ((& (stx ) -> iso ) -> so . keyex & 0x1 ) {
    Scheme_Object * key ; 
    BLOCK_SETUP((PUSH(key, 0+XfOrM1486_COUNT)));
#   define XfOrM1513_COUNT (1+XfOrM1486_COUNT)
#   define SETUP_XfOrM1513(x) SETUP(XfOrM1513_COUNT)
    key = NULLED_OUT ; 
    if (! * ht ) {
      GC_CAN_IGNORE Scheme_Hash_Table * htv ; 
#     define XfOrM1516_COUNT (0+XfOrM1513_COUNT)
#     define SETUP_XfOrM1516(x) SETUP_XfOrM1513(x)
      htv = FUNCCALL(SETUP_XfOrM1516(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
      * ht = htv ; 
    }
    key = FUNCCALL(SETUP_XfOrM1513(_), scheme_stx_property ((Scheme_Object * ) stx , share_symbol , ((void * ) 0 ) ) ); 
    if ((((key ) ) == (scheme_false ) ) ) {
#     define XfOrM1515_COUNT (0+XfOrM1513_COUNT)
#     define SETUP_XfOrM1515(x) SETUP_XfOrM1513(x)
      FUNCCALL_EMPTY(scheme_signal_error ("bad 'share key" ) ); 
    }
    ph = FUNCCALL(SETUP_XfOrM1513(_), scheme_hash_get (* ht , key ) ); 
    if (ph )
      RET_VALUE_START (ph ) RET_VALUE_END ; 
    else {
#     define XfOrM1514_COUNT (0+XfOrM1513_COUNT)
#     define SETUP_XfOrM1514(x) SETUP_XfOrM1513(x)
      ph = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM1514(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
      ph -> type = scheme_multiple_values_type ; 
      FUNCCALL(SETUP_XfOrM1514(_), scheme_hash_set (* ht , key , (Scheme_Object * ) ph ) ); 
    }
  }
  else ph = ((void * ) 0 ) ; 
  if (with_marks ) {
#   define XfOrM1512_COUNT (0+XfOrM1486_COUNT)
#   define SETUP_XfOrM1512(x) SETUP_XfOrM1486(x)
    FUNCCALL(SETUP_XfOrM1512(_), scheme_stx_content ((Scheme_Object * ) stx ) ); 
  }
  v = stx -> val ; 
  if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
    Scheme_Object * first = ((void * ) 0 ) , * last = ((void * ) 0 ) , * p , * common_wraps = ((void * ) 0 ) ; 
    int cnt = 0 ; 
    BLOCK_SETUP((PUSH(first, 0+XfOrM1486_COUNT), PUSH(last, 1+XfOrM1486_COUNT), PUSH(common_wraps, 2+XfOrM1486_COUNT), PUSH(p, 3+XfOrM1486_COUNT)));
#   define XfOrM1499_COUNT (4+XfOrM1486_COUNT)
#   define SETUP_XfOrM1499(x) SETUP(XfOrM1499_COUNT)
    p = NULLED_OUT ; 
    while (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
      Scheme_Object * a ; 
      cnt ++ ; 
      BLOCK_SETUP((PUSH(a, 0+XfOrM1499_COUNT)));
#     define XfOrM1509_COUNT (1+XfOrM1499_COUNT)
#     define SETUP_XfOrM1509(x) SETUP(XfOrM1509_COUNT)
      a = NULLED_OUT ; 
      a = FUNCCALL(SETUP_XfOrM1509(_), syntax_to_datum_inner ((((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) , ht , with_marks , mt ) ); 
      p = FUNCCALL_AGAIN(scheme_make_pair (a , scheme_null ) ); 
      if (last )
        (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = p ; 
      else first = p ; 
      last = p ; 
      v = (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) ; 
      if (with_marks ) {
#       define XfOrM1510_COUNT (0+XfOrM1509_COUNT)
#       define SETUP_XfOrM1510(x) SETUP_XfOrM1509(x)
        a = FUNCCALL(SETUP_XfOrM1510(_), extract_for_common_wrap (a , 1 , 1 ) ); 
        if (! common_wraps ) {
          if (a )
            common_wraps = a ; 
          else common_wraps = scheme_false ; 
        }
        else if (! a || ! ((common_wraps ) == (a ) ) )
          common_wraps = scheme_false ; 
      }
    }
    if (! ((v ) == (scheme_null ) ) ) {
#     define XfOrM1502_COUNT (0+XfOrM1499_COUNT)
#     define SETUP_XfOrM1502(x) SETUP_XfOrM1499(x)
      v = FUNCCALL(SETUP_XfOrM1502(_), syntax_to_datum_inner (v , ht , with_marks , mt ) ); 
      (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = v ; 
      if (with_marks ) {
#       define XfOrM1504_COUNT (0+XfOrM1502_COUNT)
#       define SETUP_XfOrM1504(x) SETUP_XfOrM1502(x)
        v = FUNCCALL(SETUP_XfOrM1504(_), extract_for_common_wrap (v , 1 , 0 ) ); 
        if (v && ((common_wraps ) == (v ) ) ) {
#         define XfOrM1505_COUNT (0+XfOrM1504_COUNT)
#         define SETUP_XfOrM1505(x) SETUP_XfOrM1504(x)
          converted_wraps = FUNCCALL(SETUP_XfOrM1505(_), wraps_to_datum (stx -> wraps , mt , ((void * ) 0 ) , 0 ) ); 
          if (((common_wraps ) == (converted_wraps ) ) )
            FUNCCALL(SETUP_XfOrM1505(_), lift_common_wraps (first , common_wraps , cnt , 1 ) ); 
          else common_wraps = scheme_false ; 
        }
        else common_wraps = scheme_false ; 
      }
      if ((with_marks > 1 ) && (((common_wraps ) ) == (scheme_false ) ) ) {
#       define XfOrM1503_COUNT (0+XfOrM1502_COUNT)
#       define SETUP_XfOrM1503(x) SETUP_XfOrM1502(x)
        first = FUNCCALL(SETUP_XfOrM1503(_), scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (cnt ) ) << 1 ) | 0x1 ) ) , first ) ); 
      }
    }
    else if (with_marks && (! (((common_wraps ) ) == (scheme_false ) ) ) ) {
#     define XfOrM1501_COUNT (0+XfOrM1499_COUNT)
#     define SETUP_XfOrM1501(x) SETUP_XfOrM1499(x)
      converted_wraps = FUNCCALL(SETUP_XfOrM1501(_), wraps_to_datum (stx -> wraps , mt , ((void * ) 0 ) , 0 ) ); 
      if (((common_wraps ) == (converted_wraps ) ) )
        FUNCCALL(SETUP_XfOrM1501(_), lift_common_wraps (first , common_wraps , cnt , 0 ) ); 
      else common_wraps = scheme_false ; 
    }
    if (with_marks && (! (((common_wraps ) ) == (scheme_false ) ) ) ) {
#     define XfOrM1500_COUNT (0+XfOrM1499_COUNT)
#     define SETUP_XfOrM1500(x) SETUP_XfOrM1499(x)
      first = FUNCCALL(SETUP_XfOrM1500(_), scheme_make_pair (scheme_true , first ) ); 
    }
    result = first ; 
  }
  else if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) {
#   define XfOrM1498_COUNT (0+XfOrM1486_COUNT)
#   define SETUP_XfOrM1498(x) SETUP_XfOrM1486(x)
    v = FUNCCALL(SETUP_XfOrM1498(_), syntax_to_datum_inner ((((Scheme_Small_Object * ) (v ) ) -> u . ptr_val ) , ht , with_marks , mt ) ); 
    result = FUNCCALL(SETUP_XfOrM1498(_), scheme_box (v ) ); 
  }
  else if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
    int size = (((Scheme_Vector * ) (v ) ) -> size ) , i ; 
    Scheme_Object * r , * a ; 
    BLOCK_SETUP((PUSH(a, 0+XfOrM1486_COUNT), PUSH(r, 1+XfOrM1486_COUNT)));
#   define XfOrM1495_COUNT (2+XfOrM1486_COUNT)
#   define SETUP_XfOrM1495(x) SETUP(XfOrM1495_COUNT)
    r = NULLED_OUT ; 
    a = NULLED_OUT ; 
    r = FUNCCALL(SETUP_XfOrM1495(_), scheme_make_vector (size , ((void * ) 0 ) ) ); 
    for (i = 0 ; i < size ; i ++ ) {
#     define XfOrM1497_COUNT (0+XfOrM1495_COUNT)
#     define SETUP_XfOrM1497(x) SETUP_XfOrM1495(x)
      a = FUNCCALL(SETUP_XfOrM1497(_), syntax_to_datum_inner ((((Scheme_Vector * ) (v ) ) -> els ) [i ] , ht , with_marks , mt ) ); 
      (((Scheme_Vector * ) (r ) ) -> els ) [i ] = a ; 
    }
    result = r ; 
  }
  else if ((with_marks == 1 ) && ((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
#   define XfOrM1494_COUNT (0+XfOrM1486_COUNT)
#   define SETUP_XfOrM1494(x) SETUP_XfOrM1486(x)
    result = FUNCCALL(SETUP_XfOrM1494(_), scheme_make_pair (v , stx -> wraps ) ); 
  }
  else result = v ; 
  if (with_marks > 1 ) {
#   define XfOrM1487_COUNT (0+XfOrM1486_COUNT)
#   define SETUP_XfOrM1487(x) SETUP_XfOrM1486(x)
    if (! converted_wraps )
      converted_wraps = FUNCCALL(SETUP_XfOrM1487(_), wraps_to_datum (stx -> wraps , mt , ((void * ) 0 ) , 0 ) ); 
    result = FUNCCALL(SETUP_XfOrM1487(_), scheme_make_pair (result , converted_wraps ) ); 
    if (stx -> certs ) {
      Scheme_Object * cert_marks = scheme_null , * icert_marks = scheme_null ; 
      Scheme_Cert * certs ; 
      BLOCK_SETUP((PUSH(icert_marks, 0+XfOrM1487_COUNT), PUSH(cert_marks, 1+XfOrM1487_COUNT), PUSH(certs, 2+XfOrM1487_COUNT)));
#     define XfOrM1488_COUNT (3+XfOrM1487_COUNT)
#     define SETUP_XfOrM1488(x) SETUP(XfOrM1488_COUNT)
      certs = NULLED_OUT ; 
      certs = ((Scheme_Cert * ) ((stx ) -> certs ? (((Scheme_Type ) (((((long ) ((stx ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((stx ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) ((stx ) -> certs ) ) -> u . pair_val . car ) : (stx ) -> certs ) : ((void * ) 0 ) ) ) ; 
      while (certs ) {
#       define XfOrM1493_COUNT (0+XfOrM1488_COUNT)
#       define SETUP_XfOrM1493(x) SETUP_XfOrM1488(x)
        cert_marks = FUNCCALL(SETUP_XfOrM1493(_), scheme_make_pair (certs -> modidx , cert_marks ) ); 
        cert_marks = FUNCCALL(SETUP_XfOrM1493(_), scheme_make_pair (certs -> mark , cert_marks ) ); 
        certs = certs -> next ; 
      }
      certs = ((Scheme_Cert * ) ((stx ) -> certs ? (((Scheme_Type ) (((((long ) ((stx ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((stx ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) ((stx ) -> certs ) ) -> u . pair_val . cdr ) : ((void * ) 0 ) ) : ((void * ) 0 ) ) ) ; 
      while (certs ) {
#       define XfOrM1491_COUNT (0+XfOrM1488_COUNT)
#       define SETUP_XfOrM1491(x) SETUP_XfOrM1488(x)
        icert_marks = FUNCCALL(SETUP_XfOrM1491(_), scheme_make_pair (certs -> modidx , icert_marks ) ); 
        icert_marks = FUNCCALL(SETUP_XfOrM1491(_), scheme_make_pair (certs -> mark , icert_marks ) ); 
        certs = certs -> next ; 
      }
      if (((Scheme_Type ) (((((long ) (cert_marks ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (cert_marks ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || ((Scheme_Type ) (((((long ) (icert_marks ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (icert_marks ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#       define XfOrM1489_COUNT (0+XfOrM1488_COUNT)
#       define SETUP_XfOrM1489(x) SETUP_XfOrM1488(x)
        v = FUNCCALL(SETUP_XfOrM1489(_), scheme_make_vector (2 , ((void * ) 0 ) ) ); 
        (((Scheme_Vector * ) (v ) ) -> els ) [0 ] = result ; 
        if (((Scheme_Type ) (((((long ) (icert_marks ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (icert_marks ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
          cert_marks = FUNCCALL(SETUP_XfOrM1489(_), scheme_make_pair (cert_marks , icert_marks ) ); 
        (((Scheme_Vector * ) (v ) ) -> els ) [1 ] = cert_marks ; 
        result = v ; 
      }
    }
  }
  if (ph )
    (((Scheme_Small_Object * ) (ph ) ) -> u . ptr_val ) = result ; 
  RET_VALUE_START (result ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_syntax_to_datum (Scheme_Object * stx , int with_marks , Scheme_Marshal_Tables * mt ) {
  Scheme_Hash_Table * ht = ((void * ) 0 ) ; 
  Scheme_Object * v ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(mt, 0), PUSH(stx, 1), PUSH(v, 2), PUSH(ht, 3)));
# define XfOrM1521_COUNT (4)
# define SETUP_XfOrM1521(x) SETUP(XfOrM1521_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  v = NULLED_OUT ; 
  if (mt )
    FUNCCALL(SETUP_XfOrM1521(_), scheme_marshal_push_refs (mt ) ); 
  v = FUNCCALL(SETUP_XfOrM1521(_), syntax_to_datum_inner (stx , & ht , with_marks , mt ) ); 
  if (mt ) {
    Scheme_Hash_Table * top_map ; 
    Scheme_Object * key ; 
    BLOCK_SETUP((PUSH(top_map, 0+XfOrM1521_COUNT), PUSH(key, 1+XfOrM1521_COUNT)));
#   define XfOrM1522_COUNT (2+XfOrM1521_COUNT)
#   define SETUP_XfOrM1522(x) SETUP(XfOrM1522_COUNT)
    top_map = NULLED_OUT ; 
    key = NULLED_OUT ; 
    top_map = mt -> top_map ; 
    if (! top_map ) {
#     define XfOrM1525_COUNT (0+XfOrM1522_COUNT)
#     define SETUP_XfOrM1525(x) SETUP_XfOrM1522(x)
      top_map = FUNCCALL(SETUP_XfOrM1525(_), scheme_make_hash_table_equal () ); 
      mt -> top_map = top_map ; 
    }
    key = FUNCCALL(SETUP_XfOrM1522(_), scheme_hash_get (top_map , v ) ); 
    if (key ) {
#     define XfOrM1524_COUNT (0+XfOrM1522_COUNT)
#     define SETUP_XfOrM1524(x) SETUP_XfOrM1522(x)
      FUNCCALL(SETUP_XfOrM1524(_), scheme_marshal_pop_refs (mt , 0 ) ); 
      v = FUNCCALL(SETUP_XfOrM1524(_), scheme_marshal_lookup (mt , key ) ); 
      FUNCCALL_AGAIN(scheme_marshal_using_key (mt , key ) ); 
    }
    else {
#     define XfOrM1523_COUNT (0+XfOrM1522_COUNT)
#     define SETUP_XfOrM1523(x) SETUP_XfOrM1522(x)
      FUNCCALL(SETUP_XfOrM1523(_), scheme_hash_set (top_map , stx , v ) ); 
      v = FUNCCALL(SETUP_XfOrM1523(_), scheme_marshal_wrap_set (mt , stx , v ) ); 
      FUNCCALL_AGAIN(scheme_marshal_pop_refs (mt , 1 ) ); 
    }
  }
  if (ht )
    v = FUNCCALL(SETUP_XfOrM1521(_), scheme_resolve_placeholders (v , 0 , scheme_multiple_values_type ) ); 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int syntax_is_graph_inner (Scheme_Object * o ) ; 
static Scheme_Object * syntax_is_graph_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * o = (Scheme_Object * ) p -> ku . k . p1 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  return syntax_is_graph_inner (o ) ? scheme_true : scheme_false ; 
}
static int syntax_is_graph_inner (Scheme_Object * o ) {
  Scheme_Stx * stx = (Scheme_Stx * ) o ; 
  Scheme_Object * v ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(stx, 1)));
# define XfOrM1527_COUNT (2)
# define SETUP_XfOrM1527(x) SETUP(XfOrM1527_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  {
    unsigned long _stk_pos ; 
#   define XfOrM1538_COUNT (0+XfOrM1527_COUNT)
#   define SETUP_XfOrM1538(x) SETUP_XfOrM1527(x)
    _stk_pos = (unsigned long ) & _stk_pos ; 
    if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
      Scheme_Thread * p = scheme_current_thread ; 
#     define XfOrM1539_COUNT (0+XfOrM1538_COUNT)
#     define SETUP_XfOrM1539(x) SETUP_XfOrM1538(x)
      p -> ku . k . p1 = (void * ) o ; 
      v = FUNCCALL(SETUP_XfOrM1539(_), scheme_handle_stack_overflow (syntax_is_graph_k ) ); 
      RET_VALUE_START ((! (((v ) ) == (scheme_false ) ) ) ) RET_VALUE_END ; 
    }
  }
  {
#   define XfOrM1536_COUNT (0+XfOrM1527_COUNT)
#   define SETUP_XfOrM1536(x) SETUP_XfOrM1527(x)
    if ((scheme_fuel_counter ) <= 0 ) {
#     define XfOrM1537_COUNT (0+XfOrM1536_COUNT)
#     define SETUP_XfOrM1537(x) SETUP_XfOrM1536(x)
      FUNCCALL(SETUP_XfOrM1537(_), scheme_out_of_fuel () ); 
    }
  }
  ; 
  if ((& (stx ) -> iso ) -> so . keyex & 0x1 )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  v = stx -> val ; 
  if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#   define XfOrM1532_COUNT (0+XfOrM1527_COUNT)
#   define SETUP_XfOrM1532(x) SETUP_XfOrM1527(x)
    while (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#     define XfOrM1535_COUNT (0+XfOrM1532_COUNT)
#     define SETUP_XfOrM1535(x) SETUP_XfOrM1532(x)
      if (FUNCCALL(SETUP_XfOrM1535(_), syntax_is_graph_inner ((((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) ) ))
        RET_VALUE_START (1 ) RET_VALUE_END ; 
      v = (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) ; 
    }
    if (! ((v ) == (scheme_null ) ) ) {
#     define XfOrM1533_COUNT (0+XfOrM1532_COUNT)
#     define SETUP_XfOrM1533(x) SETUP_XfOrM1532(x)
      if (FUNCCALL(SETUP_XfOrM1533(_), syntax_is_graph_inner (v ) ))
        RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  else if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) {
#   define XfOrM1531_COUNT (0+XfOrM1527_COUNT)
#   define SETUP_XfOrM1531(x) SETUP_XfOrM1527(x)
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(syntax_is_graph_inner ((((Scheme_Small_Object * ) (v ) ) -> u . ptr_val ) ) )) RET_VALUE_EMPTY_END ; 
  }
  else if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
    int size = (((Scheme_Vector * ) (v ) ) -> size ) , i ; 
#   define XfOrM1528_COUNT (0+XfOrM1527_COUNT)
#   define SETUP_XfOrM1528(x) SETUP_XfOrM1527(x)
    for (i = 0 ; i < size ; i ++ ) {
#     define XfOrM1530_COUNT (0+XfOrM1528_COUNT)
#     define SETUP_XfOrM1530(x) SETUP_XfOrM1528(x)
      if (FUNCCALL(SETUP_XfOrM1530(_), syntax_is_graph_inner ((((Scheme_Vector * ) (v ) ) -> els ) [i ] ) ))
        RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_syntax_is_graph (Scheme_Object * stx ) {
  /* No conversion */
  return syntax_is_graph_inner (stx ) ; 
}
static Scheme_Object * unmarshal_mark (Scheme_Object * _a , Scheme_Unmarshal_Tables * ut ) {
  Scheme_Object * n , * a = _a ; 
  char * __funcarg76 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(ut, 0), PUSH(_a, 1), PUSH(a, 2), PUSH(n, 3)));
# define XfOrM1541_COUNT (4)
# define SETUP_XfOrM1541(x) SETUP(XfOrM1541_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  n = NULLED_OUT ; 
  if ((((long ) (a ) ) & 0x1 ) && ((((long ) (a ) ) & 0x1 ) ? ((((long ) (a ) ) >> 1 ) >= 0 ) : ((& ((Scheme_Bignum * ) a ) -> iso ) -> so . keyex & 0x1 ) ) )
    a = ((Scheme_Object * ) (void * ) (long ) ((((long ) (- (((long ) (a ) ) >> 1 ) ) ) << 1 ) | 0x1 ) ) ; 
  else a = (__funcarg76 = FUNCCALL(SETUP_XfOrM1541(_), scheme_number_to_string (10 , a ) ), FUNCCALL_AGAIN(scheme_intern_symbol (__funcarg76 ) )) ; 
  n = FUNCCALL(SETUP_XfOrM1541(_), scheme_hash_get (ut -> rns , a ) ); 
  if (! n ) {
#   define XfOrM1542_COUNT (0+XfOrM1541_COUNT)
#   define SETUP_XfOrM1542(x) SETUP_XfOrM1541(x)
    n = FUNCCALL(SETUP_XfOrM1542(_), scheme_new_mark () ); 
    if (! ((((long ) (_a ) ) & 0x1 ) ? ((((long ) (_a ) ) >> 1 ) >= 0 ) : ((& ((Scheme_Bignum * ) _a ) -> iso ) -> so . keyex & 0x1 ) ) ) {
#     define XfOrM1543_COUNT (0+XfOrM1542_COUNT)
#     define SETUP_XfOrM1543(x) SETUP_XfOrM1542(x)
      n = FUNCCALL(SETUP_XfOrM1543(_), negate_mark (n ) ); 
    }
    FUNCCALL(SETUP_XfOrM1542(_), scheme_hash_set (ut -> rns , a , n ) ); 
  }
  if (! ((((long ) (n ) ) & 0x1 ) || ((((n ) -> type ) >= scheme_bignum_type ) && (((n ) -> type ) <= scheme_complex_type ) ) ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  RET_VALUE_START (n ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * datum_to_wraps (Scheme_Object * w , Scheme_Unmarshal_Tables * ut ) {
  Scheme_Object * a , * wraps_key , * local_key ; 
  int stack_size , decoded ; 
  Wrap_Chunk * wc ; 
  Scheme_Object * __funcarg112 = NULLED_OUT ; 
  Scheme_Object * __funcarg111 = NULLED_OUT ; 
  Scheme_Object * __funcarg110 = NULLED_OUT ; 
  Scheme_Object * __funcarg106 = NULLED_OUT ; 
  Scheme_Object * __funcarg104 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(17);
  BLOCK_SETUP_TOP((PUSH(ut, 0), PUSH(wc, 1), PUSH(wraps_key, 2), PUSH(a, 3), PUSH(w, 4), PUSH(local_key, 5)));
# define XfOrM1544_COUNT (6)
# define SETUP_XfOrM1544(x) SETUP(XfOrM1544_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  a = NULLED_OUT ; 
  wraps_key = NULLED_OUT ; 
  local_key = NULLED_OUT ; 
  wc = NULLED_OUT ; 
  if ((((long ) (w ) ) & 0x1 ) ) {
#   define XfOrM1685_COUNT (0+XfOrM1544_COUNT)
#   define SETUP_XfOrM1685(x) SETUP_XfOrM1544(x)
    wraps_key = w ; 
    w = FUNCCALL(SETUP_XfOrM1685(_), scheme_unmarshal_wrap_get (ut , wraps_key , & decoded ) ); 
    if (decoded && (! w || ! (((w ) == (scheme_null ) ) || ((Scheme_Type ) (((((long ) (w ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (w ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    if (decoded )
      RET_VALUE_START (w ) RET_VALUE_END ; 
  }
  else {
    wraps_key = ((void * ) 0 ) ; 
  }
  stack_size = FUNCCALL(SETUP_XfOrM1544(_), scheme_proper_list_length (w ) ); 
  if (stack_size < 1 ) {
#   define XfOrM1683_COUNT (0+XfOrM1544_COUNT)
#   define SETUP_XfOrM1683(x) SETUP_XfOrM1544(x)
    FUNCCALL(SETUP_XfOrM1683(_), scheme_unmarshal_wrap_set (ut , wraps_key , scheme_null ) ); 
    RET_VALUE_START (scheme_null ) RET_VALUE_END ; 
  }
  else if (stack_size < 2 ) {
    wc = ((void * ) 0 ) ; 
  }
  else {
#   define XfOrM1681_COUNT (0+XfOrM1544_COUNT)
#   define SETUP_XfOrM1681(x) SETUP_XfOrM1544(x)
    wc = (Wrap_Chunk * ) FUNCCALL(SETUP_XfOrM1681(_), GC_malloc_one_tagged (sizeof (Wrap_Chunk ) + ((stack_size - 1 ) * sizeof (Scheme_Object * ) ) ) ); 
    wc -> type = scheme_wrap_chunk_type ; 
    wc -> len = stack_size ; 
  }
  a = ((void * ) 0 ) ; 
  while (! ((w ) == (scheme_null ) ) ) {
#   define XfOrM1613_COUNT (0+XfOrM1544_COUNT)
#   define SETUP_XfOrM1613(x) SETUP_XfOrM1544(x)
    a = (((Scheme_Simple_Object * ) (w ) ) -> u . pair_val . car ) ; 
    if (((((long ) (a ) ) & 0x1 ) || ((((a ) -> type ) >= scheme_bignum_type ) && (((a ) -> type ) <= scheme_complex_type ) ) ) ) {
#     define XfOrM1680_COUNT (0+XfOrM1613_COUNT)
#     define SETUP_XfOrM1680(x) SETUP_XfOrM1613(x)
      local_key = a ; 
      a = FUNCCALL(SETUP_XfOrM1680(_), scheme_unmarshal_wrap_get (ut , local_key , & decoded ) ); 
      if (decoded && (! a || (((a ) == (scheme_null ) ) || ((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else {
      local_key = ((void * ) 0 ) ; 
      decoded = 0 ; 
    }
    if (decoded ) {
    }
    else if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && (((((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) ) == (scheme_null ) ) && ((((long ) ((((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) ) ) & 0x1 ) || (((((((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) ) -> type ) >= scheme_bignum_type ) && ((((((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) ) -> type ) <= scheme_complex_type ) ) ) ) {
#     define XfOrM1677_COUNT (0+XfOrM1613_COUNT)
#     define SETUP_XfOrM1677(x) SETUP_XfOrM1613(x)
      a = FUNCCALL(SETUP_XfOrM1677(_), unmarshal_mark ((((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) , ut ) ); 
      if (! a )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
      int i = (((Scheme_Vector * ) (a ) ) -> size ) ; 
#     define XfOrM1674_COUNT (0+XfOrM1613_COUNT)
#     define SETUP_XfOrM1674(x) SETUP_XfOrM1613(x)
      if ((i < 2 ) || ! ((((((Scheme_Vector * ) (a ) ) -> els ) [1 ] ) ) == (scheme_false ) ) )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      while (i > 2 ) {
        i -- ; 
        if (! ((Scheme_Type ) (((((long ) ((((Scheme_Vector * ) (a ) ) -> els ) [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Vector * ) (a ) ) -> els ) [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      FUNCCALL(SETUP_XfOrM1674(_), scheme_unmarshal_wrap_set (ut , local_key , a ) ); 
    }
    else if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
      Scheme_Object * mns ; 
      Module_Renames * mrn ; 
      Scheme_Object * p , * key ; 
      int plus_kernel , i , count , kind ; 
      long phase ; 
      BLOCK_SETUP((PUSH(mrn, 0+XfOrM1613_COUNT), PUSH(mns, 1+XfOrM1613_COUNT), PUSH(p, 2+XfOrM1613_COUNT), PUSH(key, 3+XfOrM1613_COUNT)));
#     define XfOrM1620_COUNT (4+XfOrM1613_COUNT)
#     define SETUP_XfOrM1620(x) SETUP(XfOrM1620_COUNT)
      mns = NULLED_OUT ; 
      mrn = NULLED_OUT ; 
      p = NULLED_OUT ; 
      key = NULLED_OUT ; 
      if (! ((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      if (((((((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) ) == (scheme_true ) ) || (((((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) ) == (scheme_false ) ) ) ) {
        plus_kernel = 1 ; 
        a = (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) ; 
      }
      else plus_kernel = 0 ; 
      if (! ((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      phase = (((long ) ((((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) ) ) >> 1 ) ; 
      a = (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) ; 
      if (! ((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      if ((! ((((((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) ) ) == (scheme_false ) ) ) )
        kind = 2 ; 
      else kind = 1 ; 
      a = (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) ; 
      mrn = (Module_Renames * ) FUNCCALL(SETUP_XfOrM1620(_), scheme_make_module_rename (phase , kind , ((void * ) 0 ) ) ); 
      mrn -> plus_kernel = plus_kernel ; 
      if (! ((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      mns = (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) ; 
      a = (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) ; 
      if (! ((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
        Scheme_Object * ml = a , * mli ; 
        mli = NULLED_OUT ; 
        while (((Scheme_Type ) (((((long ) (ml ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ml ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
          mli = (((Scheme_Simple_Object * ) (ml ) ) -> u . pair_val . car ) ; 
          if (! ((Scheme_Type ) (((((long ) (mli ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (mli ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          p = (((Scheme_Simple_Object * ) (mli ) ) -> u . pair_val . car ) ; 
          if (! (((Scheme_Type ) (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || ((Scheme_Type ) (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) == (Scheme_Type ) (scheme_module_index_type ) ) ) )
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          mli = (((Scheme_Simple_Object * ) (mli ) ) -> u . pair_val . cdr ) ; 
          if (! ((Scheme_Type ) (((((long ) (mli ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (mli ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          p = (((Scheme_Simple_Object * ) (mli ) ) -> u . pair_val . car ) ; 
          if (((((long ) (p ) ) >> 1 ) < 0 ) || ((((long ) (p ) ) >> 1 ) > 2 ) )
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          mli = (((Scheme_Simple_Object * ) (mli ) ) -> u . pair_val . cdr ) ; 
          if (! ((Scheme_Type ) (((((long ) (mli ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (mli ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          p = (((Scheme_Simple_Object * ) (mli ) ) -> u . pair_val . car ) ; 
          while (((Scheme_Type ) (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
            if (! ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
              RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
            p = (((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . cdr ) ; 
          }
          if (! ((p ) == (scheme_null ) ) )
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          p = (((Scheme_Simple_Object * ) (mli ) ) -> u . pair_val . cdr ) ; 
          if (! ((Scheme_Type ) (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) && ! (((p ) ) == (scheme_false ) ) )
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          ml = (((Scheme_Simple_Object * ) (ml ) ) -> u . pair_val . cdr ) ; 
        }
        if (! ((ml ) == (scheme_null ) ) )
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        mrn -> unmarshal_info = a ; 
        if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
          mrn -> needs_unmarshal = 1 ; 
        if (! ((Scheme_Type ) (((((long ) (mns ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (mns ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        a = (((Scheme_Simple_Object * ) (mns ) ) -> u . pair_val . car ) ; 
        mns = (((Scheme_Simple_Object * ) (mns ) ) -> u . pair_val . cdr ) ; 
      }
      if (! ((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      count = (((Scheme_Vector * ) (a ) ) -> size ) ; 
      if (count & 0x1 )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      for (i = 0 ; i < count ; i += 2 ) {
#       define XfOrM1661_COUNT (0+XfOrM1620_COUNT)
#       define SETUP_XfOrM1661(x) SETUP_XfOrM1620(x)
        key = (((Scheme_Vector * ) (a ) ) -> els ) [i ] ; 
        p = (((Scheme_Vector * ) (a ) ) -> els ) [i + 1 ] ; 
        if (! ((Scheme_Type ) (((((long ) (key ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (key ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        if (((Scheme_Type ) (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || ((Scheme_Type ) (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) == (Scheme_Type ) (scheme_module_index_type ) ) ) {
        }
        else if (((Scheme_Type ) (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
          Scheme_Object * midx ; 
          BLOCK_SETUP((PUSH(midx, 0+XfOrM1661_COUNT)));
#         define XfOrM1662_COUNT (1+XfOrM1661_COUNT)
#         define SETUP_XfOrM1662(x) SETUP(XfOrM1662_COUNT)
          midx = NULLED_OUT ; 
          midx = (((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . car ) ; 
          if (! ((Scheme_Type ) (((((long ) (midx ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (midx ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) && ! ((Scheme_Type ) (((((long ) (midx ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (midx ) ) -> type ) ) == (Scheme_Type ) (scheme_module_index_type ) ) )
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          if (((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
          }
          else {
#           define XfOrM1663_COUNT (0+XfOrM1662_COUNT)
#           define SETUP_XfOrM1663(x) SETUP_XfOrM1662(x)
            if (! ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
              RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
            if (! (((long ) (((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) ) & 0x1 ) )
              RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
            if (! ((Scheme_Type ) (((((long ) (((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
              RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
            p = (__funcarg110 = (__funcarg111 = (__funcarg112 = FUNCCALL(SETUP_XfOrM1663(_), scheme_make_pair (midx , ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) ), FUNCCALL_AGAIN(scheme_make_pair (((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) , __funcarg112 ) )) , FUNCCALL_AGAIN(scheme_make_pair (((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) , __funcarg111 ) )) , FUNCCALL_AGAIN(scheme_make_pair (midx , __funcarg110 ) )) ; 
          }
        }
        else RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        FUNCCALL(SETUP_XfOrM1661(_), scheme_hash_set (mrn -> ht , key , p ) ); 
      }
      if (((Scheme_Type ) (((((long ) (mns ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (mns ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
        Scheme_Hash_Table * ht ; 
        Scheme_Object * ll , * kkey , * kfirst , * klast , * kp ; 
        BLOCK_SETUP((PUSH(ht, 0+XfOrM1620_COUNT), PUSH(kp, 1+XfOrM1620_COUNT), PUSH(kfirst, 2+XfOrM1620_COUNT), PUSH(ll, 3+XfOrM1620_COUNT), PUSH(kkey, 4+XfOrM1620_COUNT), PUSH(klast, 5+XfOrM1620_COUNT)));
#       define XfOrM1621_COUNT (6+XfOrM1620_COUNT)
#       define SETUP_XfOrM1621(x) SETUP(XfOrM1621_COUNT)
        ht = NULLED_OUT ; 
        ll = NULLED_OUT ; 
        kkey = NULLED_OUT ; 
        kfirst = NULLED_OUT ; 
        klast = NULLED_OUT ; 
        kp = NULLED_OUT ; 
        ht = FUNCCALL(SETUP_XfOrM1621(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
        for (; ((Scheme_Type ) (((((long ) (mns ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (mns ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; mns = (((Scheme_Simple_Object * ) (mns ) ) -> u . pair_val . cdr ) ) {
#         define XfOrM1639_COUNT (0+XfOrM1621_COUNT)
#         define SETUP_XfOrM1639(x) SETUP_XfOrM1621(x)
          p = (((Scheme_Simple_Object * ) (mns ) ) -> u . pair_val . car ) ; 
          if (! ((Scheme_Type ) (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          key = (((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . car ) ; 
          p = (((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . cdr ) ; 
          if (! ((Scheme_Type ) (((((long ) (key ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (key ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          ll = scheme_null ; 
          for (; ((Scheme_Type ) (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; p = (((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . cdr ) ) {
#           define XfOrM1648_COUNT (0+XfOrM1639_COUNT)
#           define SETUP_XfOrM1648(x) SETUP_XfOrM1639(x)
            a = (((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . car ) ; 
            if (! ((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
              RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
            kkey = (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) ; 
            if (! ((Scheme_Type ) (((((long ) (kkey ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (kkey ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
              RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
            kfirst = scheme_null ; 
            klast = ((void * ) 0 ) ; 
            a = (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) ; 
            if (((((long ) (a ) ) & 0x1 ) || ((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) ) {
#             define XfOrM1655_COUNT (0+XfOrM1648_COUNT)
#             define SETUP_XfOrM1655(x) SETUP_XfOrM1648(x)
              kfirst = FUNCCALL(SETUP_XfOrM1655(_), unmarshal_mark (a , ut ) ); 
            }
            else {
              Scheme_Object * bdg = ((void * ) 0 ) ; 
              BLOCK_SETUP((PUSH(bdg, 0+XfOrM1648_COUNT)));
#             define XfOrM1649_COUNT (1+XfOrM1648_COUNT)
#             define SETUP_XfOrM1649(x) SETUP(XfOrM1649_COUNT)
              if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
                if ((((Scheme_Vector * ) (a ) ) -> size ) != 2 )
                  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
                bdg = (((Scheme_Vector * ) (a ) ) -> els ) [1 ] ; 
                if (! ((Scheme_Type ) (((((long ) (bdg ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (bdg ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
                  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
                a = (((Scheme_Vector * ) (a ) ) -> els ) [0 ] ; 
              }
              for (; ((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; a = (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) ) {
#               define XfOrM1653_COUNT (0+XfOrM1649_COUNT)
#               define SETUP_XfOrM1653(x) SETUP_XfOrM1649(x)
                kp = (__funcarg106 = FUNCCALL(SETUP_XfOrM1653(_), unmarshal_mark ((((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) , ut ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg106 , scheme_null ) )) ; 
                if (! klast )
                  kfirst = kp ; 
                else (((Scheme_Simple_Object * ) (klast ) ) -> u . pair_val . cdr ) = kp ; 
                klast = kp ; 
              }
              if (! ((a ) == (scheme_null ) ) ) {
#               define XfOrM1651_COUNT (0+XfOrM1649_COUNT)
#               define SETUP_XfOrM1651(x) SETUP_XfOrM1649(x)
                if (bdg && ((((long ) (a ) ) & 0x1 ) || ((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) && ((kfirst ) == (scheme_null ) ) )
                  kfirst = FUNCCALL(SETUP_XfOrM1651(_), unmarshal_mark (a , ut ) ); 
                else RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
              }
              if (bdg ) {
#               define XfOrM1650_COUNT (0+XfOrM1649_COUNT)
#               define SETUP_XfOrM1650(x) SETUP_XfOrM1649(x)
                a = FUNCCALL(SETUP_XfOrM1650(_), scheme_make_vector (2 , ((void * ) 0 ) ) ); 
                (((Scheme_Vector * ) (a ) ) -> els ) [0 ] = kfirst ; 
                (((Scheme_Vector * ) (a ) ) -> els ) [1 ] = bdg ; 
                kfirst = a ; 
              }
            }
            ll = (__funcarg104 = FUNCCALL(SETUP_XfOrM1648(_), scheme_make_pair (kfirst , kkey ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg104 , ll ) )) ; 
          }
          FUNCCALL(SETUP_XfOrM1639(_), scheme_hash_set (ht , key , ll ) ); 
          if (! ((p ) == (scheme_null ) ) )
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        }
        if (! ((mns ) == (scheme_null ) ) )
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        mrn -> marked_names = ht ; 
      }
      FUNCCALL(SETUP_XfOrM1620(_), scheme_unmarshal_wrap_set (ut , local_key , (Scheme_Object * ) mrn ) ); 
      a = (Scheme_Object * ) mrn ; 
    }
    else if (((a ) == (scheme_true ) ) ) {
      Scheme_Env * env ; 
      BLOCK_SETUP((PUSH(env, 0+XfOrM1613_COUNT)));
#     define XfOrM1618_COUNT (1+XfOrM1613_COUNT)
#     define SETUP_XfOrM1618(x) SETUP(XfOrM1618_COUNT)
      env = NULLED_OUT ; 
      env = FUNCCALL(SETUP_XfOrM1618(_), scheme_get_env (((void * ) 0 ) ) ); 
      if (! env -> rename ) {
        Scheme_Object * rn ; 
        BLOCK_SETUP((PUSH(rn, 0+XfOrM1618_COUNT)));
#       define XfOrM1619_COUNT (1+XfOrM1618_COUNT)
#       define SETUP_XfOrM1619(x) SETUP(XfOrM1619_COUNT)
        rn = NULLED_OUT ; 
        rn = FUNCCALL(SETUP_XfOrM1619(_), scheme_make_module_rename (0 , 0 , ((void * ) 0 ) ) ); 
        env -> rename = rn ; 
      }
      a = env -> rename ; 
    }
    else if ((((a ) ) == (scheme_false ) ) ) {
      Scheme_Env * env ; 
      BLOCK_SETUP((PUSH(env, 0+XfOrM1613_COUNT)));
#     define XfOrM1616_COUNT (1+XfOrM1613_COUNT)
#     define SETUP_XfOrM1616(x) SETUP(XfOrM1616_COUNT)
      env = NULLED_OUT ; 
      env = FUNCCALL(SETUP_XfOrM1616(_), scheme_get_env (((void * ) 0 ) ) ); 
      FUNCCALL_AGAIN(scheme_prepare_exp_env (env ) ); 
      if (! env -> exp_env -> rename ) {
        Scheme_Object * rn ; 
        BLOCK_SETUP((PUSH(rn, 0+XfOrM1616_COUNT)));
#       define XfOrM1617_COUNT (1+XfOrM1616_COUNT)
#       define SETUP_XfOrM1617(x) SETUP(XfOrM1617_COUNT)
        rn = NULLED_OUT ; 
        rn = FUNCCALL(SETUP_XfOrM1617(_), scheme_make_module_rename (1 , 0 , ((void * ) 0 ) ) ); 
        env -> exp_env -> rename = rn ; 
      }
      a = env -> exp_env -> rename ; 
    }
    else if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
    }
    else {
    }
    if (wc )
      wc -> a [-- stack_size ] = a ; 
    w = (((Scheme_Simple_Object * ) (w ) ) -> u . pair_val . cdr ) ; 
  }
  if (wc )
    a = (Scheme_Object * ) wc ; 
  a = FUNCCALL(SETUP_XfOrM1544(_), scheme_make_pair (a , scheme_null ) ); 
  FUNCCALL_AGAIN(scheme_unmarshal_wrap_set (ut , wraps_key , a ) ); 
  RET_VALUE_START (a ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * datum_to_syntax_inner (Scheme_Object * o , Scheme_Unmarshal_Tables * ut , Scheme_Stx * stx_src , Scheme_Stx * stx_wraps , Scheme_Hash_Table * ht ) ; 
Scheme_Object * cert_marks_to_certs (Scheme_Object * cert_marks , Scheme_Unmarshal_Tables * ut , Scheme_Stx * stx_wraps , int * bad ) {
  Scheme_Cert * certs = ((void * ) 0 ) ; 
  Scheme_Object * a , * b , * insp ; 
  Scheme_Config * __funcarg113 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSH(a, 0), PUSH(bad, 1), PUSH(b, 2), PUSH(certs, 3), PUSH(ut, 4), PUSH(cert_marks, 5), PUSH(insp, 6)));
# define XfOrM1686_COUNT (7)
# define SETUP_XfOrM1686(x) SETUP(XfOrM1686_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a = NULLED_OUT ; 
  b = NULLED_OUT ; 
  insp = NULLED_OUT ; 
  insp = (__funcarg113 = FUNCCALL(SETUP_XfOrM1686(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg113 , MZCONFIG_CODE_INSPECTOR ) )) ; 
  while (((Scheme_Type ) (((((long ) (cert_marks ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (cert_marks ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#   define XfOrM1693_COUNT (0+XfOrM1686_COUNT)
#   define SETUP_XfOrM1693(x) SETUP_XfOrM1686(x)
    a = (((Scheme_Simple_Object * ) (cert_marks ) ) -> u . pair_val . car ) ; 
    if (! ((((long ) (a ) ) & 0x1 ) || ((((a ) -> type ) >= scheme_bignum_type ) && (((a ) -> type ) <= scheme_complex_type ) ) ) ) {
      * bad = 1 ; 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    a = FUNCCALL(SETUP_XfOrM1693(_), unmarshal_mark (a , ut ) ); 
    if (! a ) {
      * bad = 1 ; 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    cert_marks = (((Scheme_Simple_Object * ) (cert_marks ) ) -> u . pair_val . cdr ) ; 
    if (! ((Scheme_Type ) (((((long ) (cert_marks ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (cert_marks ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
      * bad = 1 ; 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    b = (((Scheme_Simple_Object * ) (cert_marks ) ) -> u . pair_val . car ) ; 
    if (! ((Scheme_Type ) (((((long ) (b ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (b ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) && ! ((Scheme_Type ) (((((long ) (b ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (b ) ) -> type ) ) == (Scheme_Type ) (scheme_module_index_type ) ) ) {
      * bad = 1 ; 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    if (! FUNCCALL(SETUP_XfOrM1693(_), cert_in_chain (a , ((void * ) 0 ) , certs ) ))
      certs = FUNCCALL(SETUP_XfOrM1693(_), cons_cert (a , b , insp , ((void * ) 0 ) , certs ) ); 
    cert_marks = (((Scheme_Simple_Object * ) (cert_marks ) ) -> u . pair_val . cdr ) ; 
  }
  if (! ((cert_marks ) == (scheme_null ) ) ) {
    * bad = 1 ; 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  RET_VALUE_START ((Scheme_Object * ) certs ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * datum_to_syntax_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * o = (Scheme_Object * ) p -> ku . k . p1 ; 
  Scheme_Stx * stx_src = (Scheme_Stx * ) p -> ku . k . p2 ; 
  Scheme_Stx * stx_wraps = (Scheme_Stx * ) p -> ku . k . p3 ; 
  Scheme_Hash_Table * ht = (Scheme_Hash_Table * ) p -> ku . k . p4 ; 
  Scheme_Unmarshal_Tables * ut = (Scheme_Unmarshal_Tables * ) p -> ku . k . p5 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  p -> ku . k . p2 = ((void * ) 0 ) ; 
  p -> ku . k . p3 = ((void * ) 0 ) ; 
  p -> ku . k . p4 = ((void * ) 0 ) ; 
  p -> ku . k . p5 = ((void * ) 0 ) ; 
  return datum_to_syntax_inner (o , ut , stx_src , stx_wraps , ht ) ; 
}
static Scheme_Object * datum_to_syntax_inner (Scheme_Object * o , Scheme_Unmarshal_Tables * ut , Scheme_Stx * stx_src , Scheme_Stx * stx_wraps , Scheme_Hash_Table * ht ) {
  Scheme_Object * result , * ph = ((void * ) 0 ) , * wraps , * cert_marks = ((void * ) 0 ) ; 
  int do_not_unpack_wraps = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(14);
  BLOCK_SETUP_TOP((PUSH(ph, 0), PUSH(stx_wraps, 1), PUSH(o, 2), PUSH(stx_src, 3), PUSH(result, 4), PUSH(ht, 5), PUSH(ut, 6), PUSH(cert_marks, 7), PUSH(wraps, 8)));
# define XfOrM1699_COUNT (9)
# define SETUP_XfOrM1699(x) SETUP(XfOrM1699_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  result = NULLED_OUT ; 
  wraps = NULLED_OUT ; 
  if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    RET_VALUE_START (o ) RET_VALUE_END ; 
  {
    unsigned long _stk_pos ; 
#   define XfOrM1738_COUNT (0+XfOrM1699_COUNT)
#   define SETUP_XfOrM1738(x) SETUP_XfOrM1699(x)
    _stk_pos = (unsigned long ) & _stk_pos ; 
    if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
      Scheme_Thread * p = scheme_current_thread ; 
#     define XfOrM1739_COUNT (0+XfOrM1738_COUNT)
#     define SETUP_XfOrM1739(x) SETUP_XfOrM1738(x)
      p -> ku . k . p1 = (void * ) o ; 
      p -> ku . k . p2 = (void * ) stx_src ; 
      p -> ku . k . p3 = (void * ) stx_wraps ; 
      p -> ku . k . p4 = (void * ) ht ; 
      p -> ku . k . p5 = (void * ) ut ; 
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_handle_stack_overflow (datum_to_syntax_k ) )) RET_VALUE_EMPTY_END ; 
    }
  }
  {
#   define XfOrM1736_COUNT (0+XfOrM1699_COUNT)
#   define SETUP_XfOrM1736(x) SETUP_XfOrM1699(x)
    if ((scheme_fuel_counter ) <= 0 ) {
#     define XfOrM1737_COUNT (0+XfOrM1736_COUNT)
#     define SETUP_XfOrM1737(x) SETUP_XfOrM1736(x)
      FUNCCALL(SETUP_XfOrM1737(_), scheme_out_of_fuel () ); 
    }
  }
  ; 
  if (ht ) {
#   define XfOrM1731_COUNT (0+XfOrM1699_COUNT)
#   define SETUP_XfOrM1731(x) SETUP_XfOrM1699(x)
    if ((((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || ((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) || ((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) ) {
      long val ; 
#     define XfOrM1732_COUNT (0+XfOrM1731_COUNT)
#     define SETUP_XfOrM1732(x) SETUP_XfOrM1731(x)
      val = (long ) FUNCCALL(SETUP_XfOrM1732(_), scheme_hash_get (ht , o ) ); 
      if (val != 1 ) {
#       define XfOrM1733_COUNT (0+XfOrM1732_COUNT)
#       define SETUP_XfOrM1733(x) SETUP_XfOrM1732(x)
        if (val & 0x1 ) {
#         define XfOrM1735_COUNT (0+XfOrM1733_COUNT)
#         define SETUP_XfOrM1735(x) SETUP_XfOrM1733(x)
          ph = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM1735(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
          ph -> type = scheme_multiple_values_type ; 
          FUNCCALL(SETUP_XfOrM1735(_), scheme_hash_set (ht , o , (Scheme_Object * ) ph ) ); 
        }
        else {
          RET_VALUE_START ((Scheme_Object * ) val ) RET_VALUE_END ; 
        }
      }
    }
  }
  if (ut && ! ((Scheme_Type ) (((((long ) (stx_wraps ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (stx_wraps ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) {
    if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
      if ((((Scheme_Vector * ) (o ) ) -> size ) == 2 ) {
        cert_marks = (((Scheme_Vector * ) (o ) ) -> els ) [1 ] ; 
        o = (((Scheme_Vector * ) (o ) ) -> els ) [0 ] ; 
      }
      else RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    if (! ((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    wraps = (((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . cdr ) ; 
    o = (((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . car ) ; 
  }
  else if (((Scheme_Type ) (((((long ) (stx_wraps ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (stx_wraps ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) {
    wraps = (((Scheme_Small_Object * ) (stx_wraps ) ) -> u . ptr_val ) ; 
    do_not_unpack_wraps = 1 ; 
  }
  else wraps = ((void * ) 0 ) ; 
  if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
    Scheme_Object * first = ((void * ) 0 ) , * last = ((void * ) 0 ) , * p ; 
    BLOCK_SETUP((PUSH(last, 0+XfOrM1699_COUNT), PUSH(first, 1+XfOrM1699_COUNT), PUSH(p, 2+XfOrM1699_COUNT)));
#   define XfOrM1713_COUNT (3+XfOrM1699_COUNT)
#   define SETUP_XfOrM1713(x) SETUP(XfOrM1713_COUNT)
    p = NULLED_OUT ; 
    p = o ; 
    while ((((Scheme_Type ) (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && (((Scheme_Inclhash_Object * ) (p ) ) -> so . keyex & 0x1 ) ) ) {
      if (! ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
        break ; 
      p = (((Scheme_Simple_Object * ) (p ) ) -> u . pair_val . cdr ) ; 
    }
    if (((p ) == (scheme_null ) ) || ((Scheme_Type ) (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ) {
      result = o ; 
    }
    else {
      int cnt = - 1 ; 
      Scheme_Stx * sub_stx_wraps = stx_wraps ; 
      BLOCK_SETUP((PUSH(sub_stx_wraps, 0+XfOrM1713_COUNT)));
#     define XfOrM1714_COUNT (1+XfOrM1713_COUNT)
#     define SETUP_XfOrM1714(x) SETUP(XfOrM1714_COUNT)
      if (wraps && ! ((Scheme_Type ) (((((long ) (stx_wraps ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (stx_wraps ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) && (((((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . car ) ) == (scheme_true ) ) ) {
#       define XfOrM1723_COUNT (0+XfOrM1714_COUNT)
#       define SETUP_XfOrM1723(x) SETUP_XfOrM1714(x)
        wraps = FUNCCALL(SETUP_XfOrM1723(_), datum_to_wraps (wraps , ut ) ); 
        do_not_unpack_wraps = 1 ; 
        sub_stx_wraps = (Scheme_Stx * ) FUNCCALL(SETUP_XfOrM1723(_), scheme_box (wraps ) ); 
        o = (((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . cdr ) ; 
      }
      else if (wraps && ! ((Scheme_Type ) (((((long ) (stx_wraps ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (stx_wraps ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) && (((long ) ((((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . car ) ) ) & 0x1 ) ) {
        cnt = (((long ) ((((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . car ) ) ) >> 1 ) ; 
        o = (((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . cdr ) ; 
      }
      while (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && cnt ) {
        Scheme_Object * a ; 
        BLOCK_SETUP((PUSH(a, 0+XfOrM1714_COUNT)));
#       define XfOrM1719_COUNT (1+XfOrM1714_COUNT)
#       define SETUP_XfOrM1719(x) SETUP(XfOrM1719_COUNT)
        a = NULLED_OUT ; 
        if (ht && last ) {
#         define XfOrM1720_COUNT (0+XfOrM1719_COUNT)
#         define SETUP_XfOrM1720(x) SETUP_XfOrM1719(x)
          if ((long ) FUNCCALL(SETUP_XfOrM1720(_), scheme_hash_get (ht , o ) )!= 1 ) {
            break ; 
          }
        }
        a = FUNCCALL(SETUP_XfOrM1719(_), datum_to_syntax_inner ((((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . car ) , ut , stx_src , sub_stx_wraps , ht ) ); 
        if (! a )
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        p = FUNCCALL(SETUP_XfOrM1719(_), scheme_make_immutable_pair (a , scheme_null ) ); 
        if (last )
          (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = p ; 
        else first = p ; 
        last = p ; 
        o = (((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . cdr ) ; 
        -- cnt ; 
      }
      if (! ((o ) == (scheme_null ) ) ) {
#       define XfOrM1715_COUNT (0+XfOrM1714_COUNT)
#       define SETUP_XfOrM1715(x) SETUP_XfOrM1714(x)
        o = FUNCCALL(SETUP_XfOrM1715(_), datum_to_syntax_inner (o , ut , stx_src , sub_stx_wraps , ht ) ); 
        if (! o )
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = o ; 
      }
      result = first ; 
    }
  }
  else if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) {
#   define XfOrM1712_COUNT (0+XfOrM1699_COUNT)
#   define SETUP_XfOrM1712(x) SETUP_XfOrM1699(x)
    o = FUNCCALL(SETUP_XfOrM1712(_), datum_to_syntax_inner ((((Scheme_Small_Object * ) (o ) ) -> u . ptr_val ) , ut , stx_src , stx_wraps , ht ) ); 
    if (! o )
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    result = FUNCCALL(SETUP_XfOrM1712(_), scheme_box (o ) ); 
    ((((Scheme_Inclhash_Object * ) (result ) ) -> so . keyex |= 0x1 ) ) ; 
  }
  else if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
    int size = (((Scheme_Vector * ) (o ) ) -> size ) , i ; 
    Scheme_Object * a ; 
    BLOCK_SETUP((PUSH(a, 0+XfOrM1699_COUNT)));
#   define XfOrM1709_COUNT (1+XfOrM1699_COUNT)
#   define SETUP_XfOrM1709(x) SETUP(XfOrM1709_COUNT)
    a = NULLED_OUT ; 
    result = FUNCCALL(SETUP_XfOrM1709(_), scheme_make_vector (size , ((void * ) 0 ) ) ); 
    for (i = 0 ; i < size ; i ++ ) {
#     define XfOrM1711_COUNT (0+XfOrM1709_COUNT)
#     define SETUP_XfOrM1711(x) SETUP_XfOrM1709(x)
      a = FUNCCALL(SETUP_XfOrM1711(_), datum_to_syntax_inner ((((Scheme_Vector * ) (o ) ) -> els ) [i ] , ut , stx_src , stx_wraps , ht ) ); 
      if (! a )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      (((Scheme_Vector * ) (result ) ) -> els ) [i ] = a ; 
    }
    if (size )
      ((((Scheme_Inclhash_Object * ) (result ) ) -> so . keyex |= 0x1 ) ) ; 
  }
  else {
    result = o ; 
  }
  if (((((Scheme_Object * ) stx_src ) ) == (scheme_false ) ) )
    result = FUNCCALL(SETUP_XfOrM1699(_), scheme_make_stx (result , empty_srcloc , ((void * ) 0 ) ) ); 
  else result = FUNCCALL(SETUP_XfOrM1699(_), scheme_make_stx (result , stx_src -> srcloc , ((void * ) 0 ) ) ); 
  if (wraps ) {
#   define XfOrM1706_COUNT (0+XfOrM1699_COUNT)
#   define SETUP_XfOrM1706(x) SETUP_XfOrM1699(x)
    if (! do_not_unpack_wraps ) {
#     define XfOrM1707_COUNT (0+XfOrM1706_COUNT)
#     define SETUP_XfOrM1707(x) SETUP_XfOrM1706(x)
      wraps = FUNCCALL(SETUP_XfOrM1707(_), datum_to_wraps (wraps , ut ) ); 
      if (! wraps )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    ((Scheme_Stx * ) result ) -> wraps = wraps ; 
  }
  else if (((((Scheme_Object * ) stx_wraps ) ) == (scheme_false ) ) ) {
  }
  else {
    ((Scheme_Stx * ) result ) -> wraps = stx_wraps -> wraps ; 
  }
  if (cert_marks ) {
    Scheme_Object * certs ; 
    int bad = 0 ; 
    BLOCK_SETUP((PUSH(certs, 0+XfOrM1699_COUNT)));
#   define XfOrM1701_COUNT (1+XfOrM1699_COUNT)
#   define SETUP_XfOrM1701(x) SETUP(XfOrM1701_COUNT)
    certs = NULLED_OUT ; 
    if (((Scheme_Type ) (((((long ) (cert_marks ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (cert_marks ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && (((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (cert_marks ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (cert_marks ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((((Scheme_Simple_Object * ) (cert_marks ) ) -> u . pair_val . car ) ) == (scheme_null ) ) ) ) {
      Scheme_Object * icerts ; 
      BLOCK_SETUP((PUSH(icerts, 0+XfOrM1701_COUNT)));
#     define XfOrM1703_COUNT (1+XfOrM1701_COUNT)
#     define SETUP_XfOrM1703(x) SETUP(XfOrM1703_COUNT)
      icerts = NULLED_OUT ; 
      certs = FUNCCALL(SETUP_XfOrM1703(_), cert_marks_to_certs ((((Scheme_Simple_Object * ) (cert_marks ) ) -> u . pair_val . car ) , ut , stx_wraps , & bad ) ); 
      icerts = FUNCCALL_AGAIN(cert_marks_to_certs ((((Scheme_Simple_Object * ) (cert_marks ) ) -> u . pair_val . cdr ) , ut , stx_wraps , & bad ) ); 
      certs = FUNCCALL_AGAIN(scheme_make_raw_pair (certs , icerts ) ); 
    }
    else {
#     define XfOrM1702_COUNT (0+XfOrM1701_COUNT)
#     define SETUP_XfOrM1702(x) SETUP_XfOrM1701(x)
      certs = FUNCCALL(SETUP_XfOrM1702(_), cert_marks_to_certs (cert_marks , ut , stx_wraps , & bad ) ); 
    }
    if (bad )
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    ((Scheme_Stx * ) result ) -> certs = certs ; 
  }
  if (ph ) {
#   define XfOrM1700_COUNT (0+XfOrM1699_COUNT)
#   define SETUP_XfOrM1700(x) SETUP_XfOrM1699(x)
    FUNCCALL(SETUP_XfOrM1700(_), scheme_make_graph_stx (result , - 1 , - 1 , - 1 ) ); 
    (((Scheme_Small_Object * ) (ph ) ) -> u . ptr_val ) = result ; 
  }
  RET_VALUE_START (result ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * general_datum_to_syntax (Scheme_Object * o , Scheme_Unmarshal_Tables * ut , Scheme_Object * stx_src , Scheme_Object * stx_wraps , int can_graph , int copy_props ) {
  Scheme_Hash_Table * ht ; 
  Scheme_Object * v , * code = ((void * ) 0 ) ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSH(code, 0), PUSH(stx_wraps, 1), PUSH(ht, 2), PUSH(stx_src, 3), PUSH(v, 4), PUSH(o, 5), PUSH(ut, 6)));
# define XfOrM1740_COUNT (7)
# define SETUP_XfOrM1740(x) SETUP(XfOrM1740_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ht = NULLED_OUT ; 
  v = NULLED_OUT ; 
  if (! (((stx_src ) ) == (scheme_false ) ) && ! ((Scheme_Type ) (((((long ) (stx_src ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (stx_src ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    RET_VALUE_START (o ) RET_VALUE_END ; 
  if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    RET_VALUE_START (o ) RET_VALUE_END ; 
  if (can_graph && (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || ((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) || ((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) )
    ht = FUNCCALL(SETUP_XfOrM1740(_), scheme_setup_datum_graph (o , 0 ) ); 
  else ht = ((void * ) 0 ) ; 
  if (ut ) {
#   define XfOrM1744_COUNT (0+XfOrM1740_COUNT)
#   define SETUP_XfOrM1744(x) SETUP_XfOrM1740(x)
    if ((((long ) (o ) ) & 0x1 ) ) {
      int decoded ; 
#     define XfOrM1745_COUNT (0+XfOrM1744_COUNT)
#     define SETUP_XfOrM1745(x) SETUP_XfOrM1744(x)
      v = FUNCCALL(SETUP_XfOrM1745(_), scheme_unmarshal_wrap_get (ut , o , & decoded ) ); 
      if (! decoded ) {
        code = o ; 
        o = v ; 
      }
      else RET_VALUE_START (v ) RET_VALUE_END ; 
    }
  }
  v = FUNCCALL(SETUP_XfOrM1740(_), datum_to_syntax_inner (o , ut , (Scheme_Stx * ) stx_src , (Scheme_Stx * ) stx_wraps , ht ) ); 
  if (! v )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  if (code ) {
#   define XfOrM1743_COUNT (0+XfOrM1740_COUNT)
#   define SETUP_XfOrM1743(x) SETUP_XfOrM1740(x)
    FUNCCALL(SETUP_XfOrM1743(_), scheme_unmarshal_wrap_set (ut , code , v ) ); 
  }
  if (ht )
    v = FUNCCALL(SETUP_XfOrM1740(_), scheme_resolve_placeholders (v , 1 , scheme_multiple_values_type ) ); 
  if (copy_props > 0 )
    ((Scheme_Stx * ) v ) -> props = ((Scheme_Stx * ) stx_src ) -> props ; 
  if (copy_props && (copy_props != 1 ) ) {
#   define XfOrM1741_COUNT (0+XfOrM1740_COUNT)
#   define SETUP_XfOrM1741(x) SETUP_XfOrM1740(x)
    if (((Scheme_Cert * ) ((((Scheme_Stx * ) stx_src ) ) -> certs ? (((Scheme_Type ) (((((long ) ((((Scheme_Stx * ) stx_src ) ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Stx * ) stx_src ) ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) ((((Scheme_Stx * ) stx_src ) ) -> certs ) ) -> u . pair_val . car ) : (((Scheme_Stx * ) stx_src ) ) -> certs ) : ((void * ) 0 ) ) ) )
      v = FUNCCALL(SETUP_XfOrM1741(_), add_certs (v , ((Scheme_Cert * ) (((Scheme_Stx * ) stx_src ) -> certs ? (((Scheme_Type ) (((((long ) (((Scheme_Stx * ) stx_src ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) stx_src ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) (((Scheme_Stx * ) stx_src ) -> certs ) ) -> u . pair_val . car ) : ((Scheme_Stx * ) stx_src ) -> certs ) : ((void * ) 0 ) ) ) , ((void * ) 0 ) , 1 ) ); 
    if (((Scheme_Cert * ) (((Scheme_Stx * ) stx_src ) -> certs ? (((Scheme_Type ) (((((long ) (((Scheme_Stx * ) stx_src ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) stx_src ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) (((Scheme_Stx * ) stx_src ) -> certs ) ) -> u . pair_val . cdr ) : ((void * ) 0 ) ) : ((void * ) 0 ) ) ) ) {
#     define XfOrM1742_COUNT (0+XfOrM1741_COUNT)
#     define SETUP_XfOrM1742(x) SETUP_XfOrM1741(x)
      v = FUNCCALL(SETUP_XfOrM1742(_), lift_inactive_certs (v , 0 ) ); 
      v = FUNCCALL(SETUP_XfOrM1742(_), add_certs (v , ((Scheme_Cert * ) (((Scheme_Stx * ) stx_src ) -> certs ? (((Scheme_Type ) (((((long ) (((Scheme_Stx * ) stx_src ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) stx_src ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) (((Scheme_Stx * ) stx_src ) -> certs ) ) -> u . pair_val . cdr ) : ((void * ) 0 ) ) : ((void * ) 0 ) ) ) , ((void * ) 0 ) , 0 ) ); 
    }
  }
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_datum_to_syntax (Scheme_Object * o , Scheme_Object * stx_src , Scheme_Object * stx_wraps , int can_graph , int copy_props ) {
  /* No conversion */
  return general_datum_to_syntax (o , ((void * ) 0 ) , stx_src , stx_wraps , can_graph , copy_props ) ; 
}
Scheme_Object * scheme_unmarshal_datum_to_syntax (Scheme_Object * o , struct Scheme_Unmarshal_Tables * ut , int can_graph ) {
  /* No conversion */
  return general_datum_to_syntax (o , ut , scheme_false , scheme_false , can_graph , 0 ) ; 
}
static void simplify_syntax_inner (Scheme_Object * o , Scheme_Hash_Table * rns , Scheme_Hash_Table * marks ) ; 
static Scheme_Object * simplify_syntax_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * o = (Scheme_Object * ) p -> ku . k . p1 ; 
  Scheme_Hash_Table * rns = (Scheme_Hash_Table * ) p -> ku . k . p2 ; 
  Scheme_Hash_Table * marks = (Scheme_Hash_Table * ) p -> ku . k . p3 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  p -> ku . k . p2 = ((void * ) 0 ) ; 
  p -> ku . k . p3 = ((void * ) 0 ) ; 
  simplify_syntax_inner (o , rns , marks ) ; 
  return ((void * ) 0 ) ; 
}
static void simplify_syntax_inner (Scheme_Object * o , Scheme_Hash_Table * rns , Scheme_Hash_Table * marks ) {
  Scheme_Stx * stx = (Scheme_Stx * ) o ; 
  Scheme_Object * v ; 
  PREPARE_VAR_STACK(10);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(rns, 1), PUSH(stx, 2), PUSH(marks, 3)));
# define XfOrM1750_COUNT (4)
# define SETUP_XfOrM1750(x) SETUP(XfOrM1750_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  v = NULLED_OUT ; 
  {
    unsigned long _stk_pos ; 
#   define XfOrM1808_COUNT (0+XfOrM1750_COUNT)
#   define SETUP_XfOrM1808(x) SETUP_XfOrM1750(x)
    _stk_pos = (unsigned long ) & _stk_pos ; 
    if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
      Scheme_Thread * p = scheme_current_thread ; 
#     define XfOrM1809_COUNT (0+XfOrM1808_COUNT)
#     define SETUP_XfOrM1809(x) SETUP_XfOrM1808(x)
      p -> ku . k . p1 = (void * ) o ; 
      p -> ku . k . p2 = (void * ) rns ; 
      p -> ku . k . p3 = (void * ) marks ; 
      FUNCCALL(SETUP_XfOrM1809(_), scheme_handle_stack_overflow (simplify_syntax_k ) ); 
      RET_NOTHING ; 
    }
  }
  {
#   define XfOrM1806_COUNT (0+XfOrM1750_COUNT)
#   define SETUP_XfOrM1806(x) SETUP_XfOrM1750(x)
    if ((scheme_fuel_counter ) <= 0 ) {
#     define XfOrM1807_COUNT (0+XfOrM1806_COUNT)
#     define SETUP_XfOrM1807(x) SETUP_XfOrM1806(x)
      FUNCCALL(SETUP_XfOrM1807(_), scheme_out_of_fuel () ); 
    }
  }
  ; 
  if ((& (stx ) -> iso ) -> so . keyex & 0x1 ) {
    RET_NOTHING ; 
  }
  FUNCCALL(SETUP_XfOrM1750(_), scheme_stx_content ((Scheme_Object * ) stx ) ); 
  if (rns ) {
#   define XfOrM1804_COUNT (0+XfOrM1750_COUNT)
#   define SETUP_XfOrM1804(x) SETUP_XfOrM1750(x)
    v = FUNCCALL(SETUP_XfOrM1804(_), wraps_to_datum (stx -> wraps , ((void * ) 0 ) , rns , 1 ) ); 
    stx -> wraps = v ; 
  }
  if (stx -> certs && ! marks )
    marks = FUNCCALL(SETUP_XfOrM1750(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  v = stx -> val ; 
  if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#   define XfOrM1800_COUNT (0+XfOrM1750_COUNT)
#   define SETUP_XfOrM1800(x) SETUP_XfOrM1750(x)
    while (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#     define XfOrM1803_COUNT (0+XfOrM1800_COUNT)
#     define SETUP_XfOrM1803(x) SETUP_XfOrM1800(x)
      FUNCCALL(SETUP_XfOrM1803(_), simplify_syntax_inner ((((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) , rns , marks ) ); 
      v = (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) ; 
    }
    if (! ((v ) == (scheme_null ) ) ) {
#     define XfOrM1801_COUNT (0+XfOrM1800_COUNT)
#     define SETUP_XfOrM1801(x) SETUP_XfOrM1800(x)
      FUNCCALL(SETUP_XfOrM1801(_), simplify_syntax_inner (v , rns , marks ) ); 
    }
  }
  else if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) {
#   define XfOrM1799_COUNT (0+XfOrM1750_COUNT)
#   define SETUP_XfOrM1799(x) SETUP_XfOrM1750(x)
    FUNCCALL(SETUP_XfOrM1799(_), simplify_syntax_inner ((((Scheme_Small_Object * ) (v ) ) -> u . ptr_val ) , rns , marks ) ); 
  }
  else if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
    int size = (((Scheme_Vector * ) (v ) ) -> size ) , i ; 
#   define XfOrM1796_COUNT (0+XfOrM1750_COUNT)
#   define SETUP_XfOrM1796(x) SETUP_XfOrM1750(x)
    for (i = 0 ; i < size ; i ++ ) {
#     define XfOrM1798_COUNT (0+XfOrM1796_COUNT)
#     define SETUP_XfOrM1798(x) SETUP_XfOrM1796(x)
      FUNCCALL(SETUP_XfOrM1798(_), simplify_syntax_inner ((((Scheme_Vector * ) (v ) ) -> els ) [i ] , rns , marks ) ); 
    }
  }
  if (marks )
    FUNCCALL(SETUP_XfOrM1750(_), add_all_marks (stx -> wraps , marks ) ); 
  if (stx -> certs ) {
    Scheme_Cert * orig_certs , * certs , * cl , * all_used_after , * result ; 
    int i ; 
    BLOCK_SETUP((PUSH(orig_certs, 0+XfOrM1750_COUNT), PUSH(certs, 1+XfOrM1750_COUNT), PUSH(all_used_after, 2+XfOrM1750_COUNT), PUSH(cl, 3+XfOrM1750_COUNT), PUSH(result, 4+XfOrM1750_COUNT)));
#   define XfOrM1751_COUNT (5+XfOrM1750_COUNT)
#   define SETUP_XfOrM1751(x) SETUP(XfOrM1751_COUNT)
    orig_certs = NULLED_OUT ; 
    certs = NULLED_OUT ; 
    cl = NULLED_OUT ; 
    all_used_after = NULLED_OUT ; 
    result = NULLED_OUT ; 
    for (i = 0 ; i < 2 ; i ++ ) {
#     define XfOrM1774_COUNT (0+XfOrM1751_COUNT)
#     define SETUP_XfOrM1774(x) SETUP_XfOrM1751(x)
      if (! i )
        certs = ((Scheme_Cert * ) ((stx ) -> certs ? (((Scheme_Type ) (((((long ) ((stx ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((stx ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) ((stx ) -> certs ) ) -> u . pair_val . car ) : (stx ) -> certs ) : ((void * ) 0 ) ) ) ; 
      else certs = ((Scheme_Cert * ) ((stx ) -> certs ? (((Scheme_Type ) (((((long ) ((stx ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((stx ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) ((stx ) -> certs ) ) -> u . pair_val . cdr ) : ((void * ) 0 ) ) : ((void * ) 0 ) ) ) ; 
      orig_certs = certs ; 
      all_used_after = certs ; 
      for (cl = certs ; cl ; cl = cl -> next ) {
#       define XfOrM1795_COUNT (0+XfOrM1774_COUNT)
#       define SETUP_XfOrM1795(x) SETUP_XfOrM1774(x)
        if (! FUNCCALL(SETUP_XfOrM1795(_), scheme_hash_get (marks , cl -> mark ) ))
          all_used_after = cl -> next ; 
      }
      for (cl = all_used_after ; cl ; cl = cl -> next ) {
#       define XfOrM1790_COUNT (0+XfOrM1774_COUNT)
#       define SETUP_XfOrM1790(x) SETUP_XfOrM1774(x)
        v = FUNCCALL(SETUP_XfOrM1790(_), scheme_hash_get (marks , cl -> mark ) ); 
        if ((((v ) ) == (scheme_void ) ) ) {
#         define XfOrM1791_COUNT (0+XfOrM1790_COUNT)
#         define SETUP_XfOrM1791(x) SETUP_XfOrM1790(x)
          result = cl ; 
          for (cl = all_used_after ; cl != result ; cl = cl -> next ) {
#           define XfOrM1793_COUNT (0+XfOrM1791_COUNT)
#           define SETUP_XfOrM1793(x) SETUP_XfOrM1791(x)
            FUNCCALL(SETUP_XfOrM1793(_), scheme_hash_set (marks , cl -> mark , scheme_true ) ); 
          }
          all_used_after = ((void * ) 0 ) ; 
          break ; 
        }
        FUNCCALL(SETUP_XfOrM1790(_), scheme_hash_set (marks , cl -> mark , scheme_void ) ); 
      }
      if (all_used_after != certs ) {
#       define XfOrM1777_COUNT (0+XfOrM1774_COUNT)
#       define SETUP_XfOrM1777(x) SETUP_XfOrM1774(x)
        result = all_used_after ; 
        for (cl = orig_certs ; cl ; cl = cl -> next ) {
#         define XfOrM1784_COUNT (0+XfOrM1777_COUNT)
#         define SETUP_XfOrM1784(x) SETUP_XfOrM1777(x)
          if (((cl ) == (all_used_after ) ) )
            break ; 
          if (FUNCCALL(SETUP_XfOrM1784(_), scheme_hash_get (marks , cl -> mark ) )) {
#           define XfOrM1785_COUNT (0+XfOrM1784_COUNT)
#           define SETUP_XfOrM1785(x) SETUP_XfOrM1784(x)
            v = FUNCCALL(SETUP_XfOrM1785(_), scheme_hash_get (marks , cl -> mark ) ); 
            if (! (((v ) ) == (scheme_void ) ) )
              result = FUNCCALL(SETUP_XfOrM1785(_), cons_cert (cl -> mark , cl -> modidx , cl -> insp , cl -> key , result ) ); 
          }
        }
        if (! i ) {
#         define XfOrM1780_COUNT (0+XfOrM1777_COUNT)
#         define SETUP_XfOrM1780(x) SETUP_XfOrM1777(x)
          if (((Scheme_Type ) (((((long ) (stx -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (stx -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ) {
            Scheme_Object * pr ; 
            BLOCK_SETUP((PUSH(pr, 0+XfOrM1780_COUNT)));
#           define XfOrM1781_COUNT (1+XfOrM1780_COUNT)
#           define SETUP_XfOrM1781(x) SETUP(XfOrM1781_COUNT)
            pr = NULLED_OUT ; 
            pr = FUNCCALL(SETUP_XfOrM1781(_), scheme_make_raw_pair ((Scheme_Object * ) result , (((Scheme_Simple_Object * ) (stx -> certs ) ) -> u . pair_val . cdr ) ) ); 
            stx -> certs = pr ; 
          }
          else stx -> certs = (Scheme_Object * ) result ; 
        }
        else {
#         define XfOrM1778_COUNT (0+XfOrM1777_COUNT)
#         define SETUP_XfOrM1778(x) SETUP_XfOrM1777(x)
          if (! result )
            stx -> certs = (((Scheme_Simple_Object * ) (stx -> certs ) ) -> u . pair_val . car ) ; 
          else {
            Scheme_Object * pr ; 
            BLOCK_SETUP((PUSH(pr, 0+XfOrM1778_COUNT)));
#           define XfOrM1779_COUNT (1+XfOrM1778_COUNT)
#           define SETUP_XfOrM1779(x) SETUP(XfOrM1779_COUNT)
            pr = NULLED_OUT ; 
            pr = FUNCCALL(SETUP_XfOrM1779(_), scheme_make_raw_pair ((((Scheme_Simple_Object * ) (stx -> certs ) ) -> u . pair_val . car ) , (Scheme_Object * ) result ) ); 
            stx -> certs = pr ; 
          }
        }
      }
      for (cl = all_used_after ; cl ; cl = cl -> next ) {
#       define XfOrM1776_COUNT (0+XfOrM1774_COUNT)
#       define SETUP_XfOrM1776(x) SETUP_XfOrM1774(x)
        FUNCCALL(SETUP_XfOrM1776(_), scheme_hash_set (marks , cl -> mark , scheme_true ) ); 
      }
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_new_stx_simplify_cache () {
  /* No conversion */
  return (Scheme_Object * ) scheme_make_hash_table (SCHEME_hash_ptr ) ; 
}
void scheme_simplify_stx (Scheme_Object * stx , Scheme_Object * cache ) {
  /* No conversion */
  if (cache ) {
    Scheme_Hash_Table * rns ; 
    rns = (Scheme_Hash_Table * ) cache ; 
    simplify_syntax_inner (stx , rns , ((void * ) 0 ) ) ; 
  }
}
static Scheme_Object * syntax_p (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ? scheme_true : scheme_false ; 
}
static Scheme_Object * graph_syntax_p (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    scheme_wrong_type ("syntax-graph?" , "syntax" , 0 , argc , argv ) ; 
  return (((& ((Scheme_Stx * ) argv [0 ] ) -> iso ) -> so . keyex & 0x1 ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * syntax_to_datum (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    scheme_wrong_type ("syntax-object->datum" , "syntax" , 0 , argc , argv ) ; 
  return scheme_syntax_to_datum (argv [0 ] , 0 , ((void * ) 0 ) ) ; 
}
static int nonneg_exact_or_false_p (Scheme_Object * o ) {
  /* No conversion */
  return (((o ) ) == (scheme_false ) ) || scheme_nonneg_exact_p (o ) ; 
}
static int pos_exact_or_false_p (Scheme_Object * o ) {
  /* No conversion */
  return ((((o ) ) == (scheme_false ) ) || ((((long ) (o ) ) & 0x1 ) && ((((long ) (o ) ) >> 1 ) > 0 ) ) || (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) && ((& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex & 0x1 ) ) ) ; 
}
static Scheme_Object * datum_to_syntax (int argc , Scheme_Object * * argv ) {
  Scheme_Object * src = scheme_false , * properties = ((void * ) 0 ) , * certs = ((void * ) 0 ) ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(certs, 0), PUSH(properties, 1), PUSH(src, 2), PUSH(argv, 3)));
# define XfOrM1818_COUNT (4)
# define SETUP_XfOrM1818(x) SETUP(XfOrM1818_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! (((argv [0 ] ) ) == (scheme_false ) ) && ! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("datum->syntax-object" , "syntax or #f" , 0 , argc , argv ) ); 
  if (argc > 2 ) {
    int ll ; 
#   define XfOrM1821_COUNT (0+XfOrM1818_COUNT)
#   define SETUP_XfOrM1821(x) SETUP_XfOrM1818(x)
    src = argv [2 ] ; 
    ll = FUNCCALL(SETUP_XfOrM1821(_), scheme_proper_list_length (src ) ); 
    if (! (((src ) ) == (scheme_false ) ) && ! ((Scheme_Type ) (((((long ) (src ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (src ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ! ((ll == 5 ) && FUNCCALL(SETUP_XfOrM1821(_), pos_exact_or_false_p (((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (src ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) )&& FUNCCALL(SETUP_XfOrM1821(_), nonneg_exact_or_false_p (((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (src ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) )&& FUNCCALL(SETUP_XfOrM1821(_), pos_exact_or_false_p (((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (src ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) )&& FUNCCALL(SETUP_XfOrM1821(_), nonneg_exact_or_false_p (((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (src ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) )) )
      FUNCCALL_EMPTY(scheme_wrong_type ("datum->syntax-object" , "syntax, source location list, or #f" , 2 , argc , argv ) ); 
    if (argc > 3 ) {
#     define XfOrM1824_COUNT (0+XfOrM1821_COUNT)
#     define SETUP_XfOrM1824(x) SETUP_XfOrM1821(x)
      if (! (((argv [3 ] ) ) == (scheme_false ) ) ) {
#       define XfOrM1827_COUNT (0+XfOrM1824_COUNT)
#       define SETUP_XfOrM1827(x) SETUP_XfOrM1824(x)
        if (! ((Scheme_Type ) (((((long ) (argv [3 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [3 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
          FUNCCALL_EMPTY(scheme_wrong_type ("datum->syntax-object" , "syntax or #f" , 3 , argc , argv ) ); 
        properties = ((Scheme_Stx * ) argv [3 ] ) -> props ; 
      }
      if (argc > 4 ) {
#       define XfOrM1825_COUNT (0+XfOrM1824_COUNT)
#       define SETUP_XfOrM1825(x) SETUP_XfOrM1824(x)
        if (! (((argv [4 ] ) ) == (scheme_false ) ) ) {
#         define XfOrM1826_COUNT (0+XfOrM1825_COUNT)
#         define SETUP_XfOrM1826(x) SETUP_XfOrM1825(x)
          if (! ((Scheme_Type ) (((((long ) (argv [4 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [4 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
            FUNCCALL_EMPTY(scheme_wrong_type ("datum->syntax-object" , "syntax or #f" , 4 , argc , argv ) ); 
          certs = (Scheme_Object * ) ((Scheme_Cert * ) (((Scheme_Stx * ) argv [4 ] ) -> certs ? (((Scheme_Type ) (((((long ) (((Scheme_Stx * ) argv [4 ] ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) argv [4 ] ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) (((Scheme_Stx * ) argv [4 ] ) -> certs ) ) -> u . pair_val . cdr ) : ((void * ) 0 ) ) : ((void * ) 0 ) ) ) ; 
        }
      }
    }
    if (ll == 5 ) {
      Scheme_Object * line , * col , * pos , * span ; 
      BLOCK_SETUP((PUSH(span, 0+XfOrM1821_COUNT), PUSH(col, 1+XfOrM1821_COUNT), PUSH(pos, 2+XfOrM1821_COUNT), PUSH(line, 3+XfOrM1821_COUNT)));
#     define XfOrM1822_COUNT (4+XfOrM1821_COUNT)
#     define SETUP_XfOrM1822(x) SETUP(XfOrM1822_COUNT)
      line = NULLED_OUT ; 
      col = NULLED_OUT ; 
      pos = NULLED_OUT ; 
      span = NULLED_OUT ; 
      line = ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (src ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ; 
      col = ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (src ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ; 
      pos = ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (src ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ; 
      span = ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (src ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ; 
      src = (((Scheme_Simple_Object * ) (src ) ) -> u . pair_val . car ) ; 
      if ((((line ) ) == (scheme_false ) ) != (((col ) ) == (scheme_false ) ) )
        FUNCCALL(SETUP_XfOrM1822(_), scheme_arg_mismatch ("datum->syntax-object" , "line and column positions must both be numbers or #f in: " , argv [2 ] ) ); 
      if (((Scheme_Type ) (((((long ) (line ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (line ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) || ((Scheme_Type ) (((((long ) (col ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (col ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) {
        line = ((Scheme_Object * ) (void * ) (long ) ((((long ) (- 1 ) ) << 1 ) | 0x1 ) ) ; 
        col = ((Scheme_Object * ) (void * ) (long ) ((((long ) (- 1 ) ) << 1 ) | 0x1 ) ) ; 
      }
      if (((Scheme_Type ) (((((long ) (pos ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (pos ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
        pos = ((Scheme_Object * ) (void * ) (long ) ((((long ) (- 1 ) ) << 1 ) | 0x1 ) ) ; 
      if (span && ((Scheme_Type ) (((((long ) (span ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (span ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
        span = ((Scheme_Object * ) (void * ) (long ) ((((long ) (- 1 ) ) << 1 ) | 0x1 ) ) ; 
      src = FUNCCALL(SETUP_XfOrM1822(_), scheme_make_stx_w_offset (scheme_false , (((line ) ) == (scheme_false ) ) ? - 1 : (((long ) (line ) ) >> 1 ) , (((col ) ) == (scheme_false ) ) ? - 1 : ((((long ) (col ) ) >> 1 ) + 1 ) , (((pos ) ) == (scheme_false ) ) ? - 1 : (((long ) (pos ) ) >> 1 ) , (((span ) ) == (scheme_false ) ) ? - 1 : (((long ) (span ) ) >> 1 ) , src , ((void * ) 0 ) ) ); 
    }
  }
  if (((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    RET_VALUE_START (argv [1 ] ) RET_VALUE_END ; 
  src = FUNCCALL(SETUP_XfOrM1818(_), scheme_datum_to_syntax (argv [1 ] , src , argv [0 ] , 1 , 0 ) ); 
  if (properties ) {
    ((Scheme_Stx * ) src ) -> props = properties ; 
  }
  if (certs ) {
#   define XfOrM1819_COUNT (0+XfOrM1818_COUNT)
#   define SETUP_XfOrM1819(x) SETUP_XfOrM1818(x)
    src = FUNCCALL(SETUP_XfOrM1819(_), lift_inactive_certs (src , 0 ) ); 
    src = FUNCCALL(SETUP_XfOrM1819(_), add_certs (src , (Scheme_Cert * ) certs , ((void * ) 0 ) , 0 ) ); 
  }
  RET_VALUE_START (src ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_checked_syntax_e (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    scheme_wrong_type ("syntax-e" , "syntax" , 0 , argc , argv ) ; 
  return scheme_stx_content (argv [0 ] ) ; 
}
static Scheme_Object * syntax_line (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  Scheme_Stx * stx = (Scheme_Stx * ) argv [0 ] ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    scheme_wrong_type ("syntax-line" , "syntax" , 0 , argc , argv ) ; 
  if (stx -> srcloc -> line < 0 )
    return scheme_false ; 
  else return ((Scheme_Object * ) (void * ) (long ) ((((long ) (stx -> srcloc -> line ) ) << 1 ) | 0x1 ) ) ; 
}
static Scheme_Object * syntax_col (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  Scheme_Stx * stx = (Scheme_Stx * ) argv [0 ] ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    scheme_wrong_type ("syntax-column" , "syntax" , 0 , argc , argv ) ; 
  if (stx -> srcloc -> col < 0 )
    return scheme_false ; 
  else return ((Scheme_Object * ) (void * ) (long ) ((((long ) (stx -> srcloc -> col - 1 ) ) << 1 ) | 0x1 ) ) ; 
}
static Scheme_Object * syntax_pos (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  Scheme_Stx * stx = (Scheme_Stx * ) argv [0 ] ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    scheme_wrong_type ("syntax-position" , "syntax" , 0 , argc , argv ) ; 
  if (stx -> srcloc -> pos < 0 )
    return scheme_false ; 
  else return ((Scheme_Object * ) (void * ) (long ) ((((long ) (stx -> srcloc -> pos ) ) << 1 ) | 0x1 ) ) ; 
}
static Scheme_Object * syntax_span (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  Scheme_Stx * stx = (Scheme_Stx * ) argv [0 ] ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    scheme_wrong_type ("syntax-span" , "syntax" , 0 , argc , argv ) ; 
  if (stx -> srcloc -> span < 0 )
    return scheme_false ; 
  else return ((Scheme_Object * ) (void * ) (long ) ((((long ) (stx -> srcloc -> span ) ) << 1 ) | 0x1 ) ) ; 
}
static Scheme_Object * syntax_src (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  Scheme_Stx * stx = (Scheme_Stx * ) argv [0 ] ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    scheme_wrong_type ("syntax-source" , "syntax" , 0 , argc , argv ) ; 
  return stx -> srcloc -> src ; 
}
static Scheme_Object * syntax_to_list (int argc , Scheme_Object * * argv ) {
  Scheme_Object * l ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(l, 0)));
# define XfOrM1834_COUNT (1)
# define SETUP_XfOrM1834(x) SETUP(XfOrM1834_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  l = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("syntax->list" , "syntax" , 0 , argc , argv ) ); 
  l = FUNCCALL(SETUP_XfOrM1834(_), scheme_stx_content (argv [0 ] ) ); 
  if (((l ) == (scheme_null ) ) )
    RET_VALUE_START (scheme_null ) RET_VALUE_END ; 
  else if (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
    int islist ; 
#   define XfOrM1835_COUNT (0+XfOrM1834_COUNT)
#   define SETUP_XfOrM1835(x) SETUP_XfOrM1834(x)
    l = FUNCCALL(SETUP_XfOrM1835(_), scheme_flatten_syntax_list (l , & islist ) ); 
    if (islist )
      RET_VALUE_START (l ) RET_VALUE_END ; 
    else RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * syntax_original_p (int argc , Scheme_Object * * argv ) {
  Scheme_Stx * stx ; 
  Wrap_Pos awl ; 
  Wrap_Pos ewl ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(stx, 0), PUSH(ewl.l, 1), PUSH(ewl.a, 2), PUSH(awl.l, 3), PUSH(awl.a, 4), PUSH(argv, 5)));
# define XfOrM1836_COUNT (6)
# define SETUP_XfOrM1836(x) SETUP(XfOrM1836_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  stx = NULLED_OUT ; 
  awl.l = NULLED_OUT ; 
  awl.a = NULLED_OUT ; 
  ewl.l = NULLED_OUT ; 
  ewl.a = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    FUNCCALL(SETUP_XfOrM1836(_), scheme_wrong_type ("syntax-original?" , "syntax" , 0 , argc , argv ) ); 
  stx = (Scheme_Stx * ) argv [0 ] ; 
  if (stx -> props ) {
    if (((stx -> props ) == (scheme_false ) ) ) {
    }
    else {
      Scheme_Object * e ; 
      e = NULLED_OUT ; 
      for (e = stx -> props ; ((Scheme_Type ) (((((long ) (e ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; e = (((Scheme_Simple_Object * ) (e ) ) -> u . pair_val . cdr ) ) {
        if (((source_symbol ) == ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (e ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) ) {
          break ; 
        }
      }
      if (((e ) == (scheme_null ) ) )
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    }
  }
  else RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
  awl . l = stx -> wraps ; 
  (WRAP_POS_SET_FIRST (& awl ) ) ; 
  (ewl . l = scheme_null , ewl . a = ((void * ) 0 ) , ewl . is_limb = 0 , ewl . pos = 0 ) ; 
  if ((same_marks (& awl , & ewl , scheme_false , ((void * ) 0 ) ) ) )
    RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
  else RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_stx_property (Scheme_Object * _stx , Scheme_Object * key , Scheme_Object * val ) {
  Scheme_Stx * stx ; 
  Scheme_Object * l ; 
  Scheme_Object * __funcarg115 = NULLED_OUT ; 
  Scheme_Object * __funcarg114 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(stx, 0), PUSH(val, 1), PUSH(l, 2), PUSH(key, 3)));
# define XfOrM1844_COUNT (4)
# define SETUP_XfOrM1844(x) SETUP(XfOrM1844_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  stx = NULLED_OUT ; 
  l = NULLED_OUT ; 
  stx = (Scheme_Stx * ) _stx ; 
  if (stx -> props ) {
#   define XfOrM1848_COUNT (0+XfOrM1844_COUNT)
#   define SETUP_XfOrM1848(x) SETUP_XfOrM1844(x)
    if (((stx -> props ) == (scheme_false ) ) ) {
#     define XfOrM1861_COUNT (0+XfOrM1848_COUNT)
#     define SETUP_XfOrM1861(x) SETUP_XfOrM1848(x)
      if (val )
        l = (__funcarg115 = FUNCCALL(SETUP_XfOrM1861(_), scheme_make_pair (source_symbol , scheme_true ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg115 , scheme_null ) )) ; 
      else l = ((void * ) 0 ) ; 
    }
    else {
      Scheme_Object * e ; 
      BLOCK_SETUP((PUSH(e, 0+XfOrM1848_COUNT)));
#     define XfOrM1849_COUNT (1+XfOrM1848_COUNT)
#     define SETUP_XfOrM1849(x) SETUP(XfOrM1849_COUNT)
      e = NULLED_OUT ; 
      for (e = stx -> props ; ((Scheme_Type ) (((((long ) (e ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; e = (((Scheme_Simple_Object * ) (e ) ) -> u . pair_val . cdr ) ) {
        if (((key ) == ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (e ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) ) {
          if (val )
            break ; 
          else RET_VALUE_START ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (e ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) RET_VALUE_END ; 
        }
      }
      if (((e ) == (scheme_null ) ) )
        l = stx -> props ; 
      else {
        Scheme_Object * first = scheme_null , * last = ((void * ) 0 ) , * p ; 
        BLOCK_SETUP((PUSH(first, 0+XfOrM1849_COUNT), PUSH(p, 1+XfOrM1849_COUNT), PUSH(last, 2+XfOrM1849_COUNT)));
#       define XfOrM1850_COUNT (3+XfOrM1849_COUNT)
#       define SETUP_XfOrM1850(x) SETUP(XfOrM1850_COUNT)
        p = NULLED_OUT ; 
        for (e = stx -> props ; ((Scheme_Type ) (((((long ) (e ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; e = (((Scheme_Simple_Object * ) (e ) ) -> u . pair_val . cdr ) ) {
#         define XfOrM1854_COUNT (0+XfOrM1850_COUNT)
#         define SETUP_XfOrM1854(x) SETUP_XfOrM1850(x)
          if (((key ) == ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (e ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) ) {
            p = (((Scheme_Simple_Object * ) (e ) ) -> u . pair_val . cdr ) ; 
            e = ((void * ) 0 ) ; 
          }
          else {
#           define XfOrM1855_COUNT (0+XfOrM1854_COUNT)
#           define SETUP_XfOrM1855(x) SETUP_XfOrM1854(x)
            p = FUNCCALL(SETUP_XfOrM1855(_), scheme_make_pair ((((Scheme_Simple_Object * ) (e ) ) -> u . pair_val . car ) , scheme_null ) ); 
          }
          if (last )
            (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = p ; 
          else first = p ; 
          last = p ; 
          if (! e )
            break ; 
        }
        l = first ; 
      }
    }
  }
  else l = scheme_null ; 
  if (val ) {
    Scheme_Object * wraps , * modinfo_cache ; 
    Scheme_Object * certs ; 
    long lazy_prefix ; 
    int graph ; 
    BLOCK_SETUP((PUSH(modinfo_cache, 0+XfOrM1844_COUNT), PUSH(certs, 1+XfOrM1844_COUNT), PUSH(wraps, 2+XfOrM1844_COUNT)));
#   define XfOrM1845_COUNT (3+XfOrM1844_COUNT)
#   define SETUP_XfOrM1845(x) SETUP(XfOrM1845_COUNT)
    wraps = NULLED_OUT ; 
    modinfo_cache = NULLED_OUT ; 
    certs = NULLED_OUT ; 
    graph = ((& (stx ) -> iso ) -> so . keyex & 0x1 ) ; 
    l = (__funcarg114 = FUNCCALL(SETUP_XfOrM1845(_), scheme_make_pair (key , val ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg114 , l ) )) ; 
    wraps = stx -> wraps ; 
    if ((& (stx ) -> iso ) -> so . keyex & 0x2 ) {
      modinfo_cache = ((void * ) 0 ) ; 
      lazy_prefix = stx -> u . lazy_prefix ; 
    }
    else {
      modinfo_cache = stx -> u . modinfo_cache ; 
      lazy_prefix = 0 ; 
    }
    certs = stx -> certs ; 
    stx = (Scheme_Stx * ) FUNCCALL(SETUP_XfOrM1845(_), scheme_make_stx (stx -> val , stx -> srcloc , l ) ); 
    stx -> wraps = wraps ; 
    if (modinfo_cache )
      stx -> u . modinfo_cache = modinfo_cache ; 
    else stx -> u . lazy_prefix = lazy_prefix ; 
    stx -> certs = certs ; 
    if (graph )
      (& (stx ) -> iso ) -> so . keyex |= 0x1 ; 
    RET_VALUE_START ((Scheme_Object * ) stx ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * syntax_property (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    scheme_wrong_type ("syntax-property" , "syntax" , 0 , argc , argv ) ; 
  return scheme_stx_property (argv [0 ] , argv [1 ] , (argc > 2 ) ? argv [2 ] : ((void * ) 0 ) ) ; 
}
static Scheme_Object * syntax_property_keys (int argc , Scheme_Object * * argv ) {
  Scheme_Stx * stx ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(stx, 0)));
# define XfOrM1863_COUNT (1)
# define SETUP_XfOrM1863(x) SETUP(XfOrM1863_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  stx = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("syntax-property" , "syntax" , 0 , argc , argv ) ); 
  stx = (Scheme_Stx * ) argv [0 ] ; 
  if (stx -> props ) {
#   define XfOrM1864_COUNT (0+XfOrM1863_COUNT)
#   define SETUP_XfOrM1864(x) SETUP_XfOrM1863(x)
    if (! ((stx -> props ) == (scheme_false ) ) ) {
      Scheme_Object * e , * k , * l = scheme_null ; 
      BLOCK_SETUP((PUSH(k, 0+XfOrM1864_COUNT), PUSH(l, 1+XfOrM1864_COUNT), PUSH(e, 2+XfOrM1864_COUNT)));
#     define XfOrM1865_COUNT (3+XfOrM1864_COUNT)
#     define SETUP_XfOrM1865(x) SETUP(XfOrM1865_COUNT)
      e = NULLED_OUT ; 
      k = NULLED_OUT ; 
      for (e = stx -> props ; ((Scheme_Type ) (((((long ) (e ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (e ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; e = (((Scheme_Simple_Object * ) (e ) ) -> u . pair_val . cdr ) ) {
#       define XfOrM1867_COUNT (0+XfOrM1865_COUNT)
#       define SETUP_XfOrM1867(x) SETUP_XfOrM1865(x)
        k = (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (e ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ; 
        if (((Scheme_Type ) (((((long ) (k ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (k ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) && ! ((& ((Scheme_Symbol * ) (k ) ) -> iso ) -> so . keyex & 0x3 ) )
          l = FUNCCALL(SETUP_XfOrM1867(_), scheme_make_pair (k , l ) ); 
      }
      RET_VALUE_START (l ) RET_VALUE_END ; 
    }
  }
  RET_VALUE_START (scheme_null ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * syntax_track_origin (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    scheme_wrong_type ("syntax-track-origin" , "syntax" , 0 , argc , argv ) ; 
  if (! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    scheme_wrong_type ("syntax-track-origin" , "syntax" , 1 , argc , argv ) ; 
  if (! (((Scheme_Type ) (((((long ) (argv [2 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [2 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) argv [2 ] ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) argv [2 ] ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) )
    scheme_wrong_type ("syntax-track-origin" , "identifier syntax" , 2 , argc , argv ) ; 
  return scheme_stx_track (argv [0 ] , argv [1 ] , argv [2 ] ) ; 
}
static Scheme_Object * bound_eq (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) argv [0 ] ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) argv [0 ] ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) )
    scheme_wrong_type ("bound-identifier=?" , "identifier syntax" , 0 , argc , argv ) ; 
  if (! (((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) argv [1 ] ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) argv [1 ] ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) )
    scheme_wrong_type ("bound-identifier=?" , "identifier syntax" , 1 , argc , argv ) ; 
  return (scheme_stx_bound_eq (argv [0 ] , argv [1 ] , (p -> current_local_env ? p -> current_local_env -> genv -> phase : 0 ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * free_eq (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) argv [0 ] ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) argv [0 ] ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) )
    scheme_wrong_type ("free-identifier=?" , "identifier syntax" , 0 , argc , argv ) ; 
  if (! (((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) argv [1 ] ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) argv [1 ] ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) )
    scheme_wrong_type ("free-identifier=?" , "identifier syntax" , 1 , argc , argv ) ; 
  return (scheme_stx_free_eq (argv [0 ] , argv [1 ] , (p -> current_local_env ? p -> current_local_env -> genv -> phase : 0 ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * do_module_eq (const char * who , int delta , int argc , Scheme_Object * * argv ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) argv [0 ] ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) argv [0 ] ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) )
    scheme_wrong_type (who , "identifier syntax" , 0 , argc , argv ) ; 
  if (! (((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) argv [1 ] ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) argv [1 ] ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) )
    scheme_wrong_type (who , "identifier syntax" , 1 , argc , argv ) ; 
  return (scheme_stx_module_eq (argv [0 ] , argv [1 ] , ((delta == 30000 ) ? 30000 : (delta + (p -> current_local_env ? p -> current_local_env -> genv -> phase : 0 ) ) ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * module_eq (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return do_module_eq ("module-identifier=?" , 0 , argc , argv ) ; 
}
static Scheme_Object * module_trans_eq (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return do_module_eq ("module-transformer-identifier=?" , 1 , argc , argv ) ; 
}
static Scheme_Object * module_templ_eq (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return do_module_eq ("module-template-identifier=?" , - 1 , argc , argv ) ; 
}
static Scheme_Object * module_label_eq (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return do_module_eq ("module-label-identifier=?" , 30000 , argc , argv ) ; 
}
static Scheme_Object * do_module_binding (char * name , int argc , Scheme_Object * * argv , int dphase , int get_position ) {
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * a , * m , * nom_mod , * nom_a ; 
  int mod_phase ; 
  Scheme_Env * __funcarg120 = NULLED_OUT ; 
  Scheme_Object * __funcarg119 = NULLED_OUT ; 
  Scheme_Object * __funcarg118 = NULLED_OUT ; 
  Scheme_Object * __funcarg117 = NULLED_OUT ; 
  Scheme_Object * __funcarg116 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(nom_mod, 0), PUSH(m, 1), PUSH(a, 2), PUSH(nom_a, 3), PUSH(p, 4)));
# define XfOrM1876_COUNT (5)
# define SETUP_XfOrM1876(x) SETUP(XfOrM1876_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a = NULLED_OUT ; 
  m = NULLED_OUT ; 
  nom_mod = NULLED_OUT ; 
  nom_a = NULLED_OUT ; 
  a = argv [0 ] ; 
  if (! ((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) || ! (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) a ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) a ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) )
    FUNCCALL(SETUP_XfOrM1876(_), scheme_wrong_type (name , "identifier syntax" , 0 , argc , argv ) ); 
  m = FUNCCALL(SETUP_XfOrM1876(_), scheme_stx_module_name (& a , ((dphase == 30000 ) ? 30000 : (dphase + (p -> current_local_env ? p -> current_local_env -> genv -> phase : 0 ) ) ) , & nom_mod , & nom_a , & mod_phase ) ); 
  if (! m )
    RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
  else if (((m ) == (scheme_undefined ) ) ) {
    if (get_position )
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    else RET_VALUE_START (lexical_symbol ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM1877_COUNT (0+XfOrM1876_COUNT)
#   define SETUP_XfOrM1877(x) SETUP_XfOrM1876(x)
    if (get_position ) {
#     define XfOrM1878_COUNT (0+XfOrM1877_COUNT)
#     define SETUP_XfOrM1878(x) SETUP_XfOrM1877(x)
      if (((Scheme_Type ) (((((long ) (m ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (m ) ) -> type ) ) == (Scheme_Type ) (scheme_module_index_type ) ) && (((((Scheme_Modidx * ) m ) -> path ) ) == (scheme_false ) ) && (((((Scheme_Modidx * ) m ) -> base ) ) == (scheme_false ) ) ) {
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      }
      else {
        int pos ; 
#       define XfOrM1879_COUNT (0+XfOrM1878_COUNT)
#       define SETUP_XfOrM1879(x) SETUP_XfOrM1878(x)
        m = FUNCCALL(SETUP_XfOrM1879(_), scheme_module_resolve (m , 0 ) ); 
        pos = (__funcarg120 = FUNCCALL(SETUP_XfOrM1879(_), scheme_get_env (((void * ) 0 ) ) ), FUNCCALL_AGAIN(scheme_module_export_position (m , __funcarg120 , a ) )) ; 
        if (pos < 0 )
          RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
        else RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (pos ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
      }
    }
    else RET_VALUE_START ((__funcarg116 = (__funcarg117 = (__funcarg118 = (__funcarg119 = FUNCCALL(SETUP_XfOrM1877(_), scheme_make_pair (mod_phase ? scheme_true : scheme_false , scheme_null ) ), FUNCCALL_AGAIN(scheme_make_pair (nom_a , __funcarg119 ) )) , FUNCCALL_AGAIN(scheme_make_pair (nom_mod , __funcarg118 ) )) , FUNCCALL_AGAIN(scheme_make_pair (a , __funcarg117 ) )) , FUNCCALL_AGAIN(scheme_make_pair (m , __funcarg116 ) )) ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * module_binding (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return do_module_binding ("identifier-binding" , argc , argv , 0 , 0 ) ; 
}
static Scheme_Object * module_trans_binding (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return do_module_binding ("identifier-transformer-binding" , argc , argv , 1 , 0 ) ; 
}
static Scheme_Object * module_templ_binding (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return do_module_binding ("identifier-template-binding" , argc , argv , - 1 , 0 ) ; 
}
static Scheme_Object * module_label_binding (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return do_module_binding ("identifier-label-binding" , argc , argv , 30000 , 0 ) ; 
}
static Scheme_Object * module_binding_pos (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return do_module_binding ("identifier-binding-export-position" , argc , argv , 0 , 1 ) ; 
}
static Scheme_Object * module_trans_binding_pos (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return do_module_binding ("identifier-transformer-binding-export-position" , argc , argv , 1 , 1 ) ; 
}
static Scheme_Object * syntax_src_module (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    scheme_wrong_type ("syntax-source-module" , "syntax" , 0 , argc , argv ) ; 
  return scheme_stx_source_module (argv [0 ] , 0 ) ; 
}
static Scheme_Object * syntax_recertify (int argc , Scheme_Object * * argv ) {
  Scheme_Object * insp , * key ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(9);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(key, 1), PUSH(insp, 2)));
# define XfOrM1889_COUNT (3)
# define SETUP_XfOrM1889(x) SETUP(XfOrM1889_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  insp = NULLED_OUT ; 
  key = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("syntax-recertify" , "syntax" , 0 , argc , argv ) ); 
  if (! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("syntax-recertify" , "syntax" , 1 , argc , argv ) ); 
  if ((! (((argv [2 ] ) ) == (scheme_false ) ) ) && ! ((Scheme_Type ) (((((long ) (argv [2 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [2 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_inspector_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("syntax-recertify" , "inspector or #f" , 2 , argc , argv ) ); 
  if (((argv [0 ] ) == (argv [1 ] ) ) )
    RET_VALUE_START (argv [0 ] ) RET_VALUE_END ; 
  insp = argv [2 ] ; 
  if ((((insp ) ) == (scheme_false ) ) )
    insp = ((void * ) 0 ) ; 
  key = argv [3 ] ; 
  if (((Scheme_Stx * ) argv [1 ] ) -> certs ) {
    Scheme_Stx * stx , * res ; 
    Scheme_Cert * certs , * new_certs , * orig_certs ; 
    int i ; 
    BLOCK_SETUP((PUSH(stx, 0+XfOrM1889_COUNT), PUSH(orig_certs, 1+XfOrM1889_COUNT), PUSH(res, 2+XfOrM1889_COUNT), PUSH(new_certs, 3+XfOrM1889_COUNT), PUSH(certs, 4+XfOrM1889_COUNT)));
#   define XfOrM1890_COUNT (5+XfOrM1889_COUNT)
#   define SETUP_XfOrM1890(x) SETUP(XfOrM1890_COUNT)
    stx = NULLED_OUT ; 
    res = NULLED_OUT ; 
    certs = NULLED_OUT ; 
    new_certs = NULLED_OUT ; 
    orig_certs = NULLED_OUT ; 
    stx = (Scheme_Stx * ) argv [0 ] ; 
    for (i = 0 ; i < 2 ; i ++ ) {
#     define XfOrM1902_COUNT (0+XfOrM1890_COUNT)
#     define SETUP_XfOrM1902(x) SETUP_XfOrM1890(x)
      if (! i ) {
        certs = ((Scheme_Cert * ) (((Scheme_Stx * ) argv [1 ] ) -> certs ? (((Scheme_Type ) (((((long ) (((Scheme_Stx * ) argv [1 ] ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) argv [1 ] ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) (((Scheme_Stx * ) argv [1 ] ) -> certs ) ) -> u . pair_val . car ) : ((Scheme_Stx * ) argv [1 ] ) -> certs ) : ((void * ) 0 ) ) ) ; 
        new_certs = ((Scheme_Cert * ) ((stx ) -> certs ? (((Scheme_Type ) (((((long ) ((stx ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((stx ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) ((stx ) -> certs ) ) -> u . pair_val . car ) : (stx ) -> certs ) : ((void * ) 0 ) ) ) ; 
      }
      else {
        certs = ((Scheme_Cert * ) (((Scheme_Stx * ) argv [1 ] ) -> certs ? (((Scheme_Type ) (((((long ) (((Scheme_Stx * ) argv [1 ] ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) argv [1 ] ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) (((Scheme_Stx * ) argv [1 ] ) -> certs ) ) -> u . pair_val . cdr ) : ((void * ) 0 ) ) : ((void * ) 0 ) ) ) ; 
        new_certs = ((Scheme_Cert * ) ((stx ) -> certs ? (((Scheme_Type ) (((((long ) ((stx ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((stx ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) ((stx ) -> certs ) ) -> u . pair_val . cdr ) : ((void * ) 0 ) ) : ((void * ) 0 ) ) ) ; 
      }
      orig_certs = new_certs ; 
      while (certs ) {
#       define XfOrM1908_COUNT (0+XfOrM1902_COUNT)
#       define SETUP_XfOrM1908(x) SETUP_XfOrM1902(x)
        if (! ((certs -> key ) == (key ) ) && ! ((certs -> insp ) == (insp ) ) && (! insp || ! (scheme_is_subinspector (certs -> insp , insp ) ) ) ) {
        }
        else {
#         define XfOrM1909_COUNT (0+XfOrM1908_COUNT)
#         define SETUP_XfOrM1909(x) SETUP_XfOrM1908(x)
          if (! FUNCCALL(SETUP_XfOrM1909(_), cert_in_chain (certs -> mark , certs -> key , new_certs ) ))
            new_certs = FUNCCALL(SETUP_XfOrM1909(_), cons_cert (certs -> mark , certs -> modidx , certs -> insp , certs -> key , new_certs ) ); 
        }
        certs = certs -> next ; 
      }
      if (! ((orig_certs ) == (new_certs ) ) ) {
#       define XfOrM1903_COUNT (0+XfOrM1902_COUNT)
#       define SETUP_XfOrM1903(x) SETUP_XfOrM1902(x)
        if (i && ! orig_certs )
          stx = (Scheme_Stx * ) FUNCCALL(SETUP_XfOrM1903(_), lift_inactive_certs ((Scheme_Object * ) stx , 0 ) ); 
        res = (Scheme_Stx * ) FUNCCALL(SETUP_XfOrM1903(_), scheme_make_stx (stx -> val , stx -> srcloc , stx -> props ) ); 
        res -> wraps = stx -> wraps ; 
        res -> u . lazy_prefix = stx -> u . lazy_prefix ; 
        if (! i && (! stx -> certs || ! ((Scheme_Type ) (((((long ) (stx -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (stx -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) || ! (((Scheme_Simple_Object * ) (stx -> certs ) ) -> u . pair_val . cdr ) ) )
          res -> certs = (Scheme_Object * ) new_certs ; 
        else {
          Scheme_Object * pr ; 
          BLOCK_SETUP((PUSH(pr, 0+XfOrM1903_COUNT)));
#         define XfOrM1904_COUNT (1+XfOrM1903_COUNT)
#         define SETUP_XfOrM1904(x) SETUP(XfOrM1904_COUNT)
          pr = NULLED_OUT ; 
          if (! i )
            pr = FUNCCALL(SETUP_XfOrM1904(_), scheme_make_raw_pair ((Scheme_Object * ) new_certs , (((Scheme_Simple_Object * ) (stx -> certs ) ) -> u . pair_val . cdr ) ) ); 
          else pr = FUNCCALL(SETUP_XfOrM1904(_), scheme_make_raw_pair ((Scheme_Object * ) ((Scheme_Cert * ) ((stx ) -> certs ? (((Scheme_Type ) (((((long ) ((stx ) -> certs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((stx ) -> certs ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ? (((Scheme_Simple_Object * ) ((stx ) -> certs ) ) -> u . pair_val . car ) : (stx ) -> certs ) : ((void * ) 0 ) ) ) , (Scheme_Object * ) new_certs ) ); 
          res -> certs = pr ; 
        }
        stx = res ; 
      }
    }
    RET_VALUE_START ((Scheme_Object * ) stx ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (argv [0 ] ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int mark_rename_table_SIZE (void * p ) {
  return ((sizeof (Module_Renames ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_rename_table_MARK (void * p ) {
  Module_Renames * rn = (Module_Renames * ) p ; 
  GC_mark (rn -> ht ) ; 
  GC_mark (rn -> nomarshal_ht ) ; 
  GC_mark (rn -> unmarshal_info ) ; 
  GC_mark (rn -> plus_kernel_nominal_source ) ; 
  GC_mark (rn -> marked_names ) ; 
  return ((sizeof (Module_Renames ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_rename_table_FIXUP (void * p ) {
  Module_Renames * rn = (Module_Renames * ) p ; 
  GC_fixup (& (rn -> ht ) ) ; 
  GC_fixup (& (rn -> nomarshal_ht ) ) ; 
  GC_fixup (& (rn -> unmarshal_info ) ) ; 
  GC_fixup (& (rn -> plus_kernel_nominal_source ) ) ; 
  GC_fixup (& (rn -> marked_names ) ) ; 
  return ((sizeof (Module_Renames ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_srcloc_SIZE (void * p ) {
  return ((sizeof (Scheme_Stx_Srcloc ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_srcloc_MARK (void * p ) {
  Scheme_Stx_Srcloc * s = (Scheme_Stx_Srcloc * ) p ; 
  GC_mark (s -> src ) ; 
  return ((sizeof (Scheme_Stx_Srcloc ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_srcloc_FIXUP (void * p ) {
  Scheme_Stx_Srcloc * s = (Scheme_Stx_Srcloc * ) p ; 
  GC_fixup (& (s -> src ) ) ; 
  return ((sizeof (Scheme_Stx_Srcloc ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_wrapchunk_SIZE (void * p ) {
  Wrap_Chunk * wc = (Wrap_Chunk * ) p ; 
  return ((sizeof (Wrap_Chunk ) + ((wc -> len - 1 ) * sizeof (Scheme_Object * ) ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_wrapchunk_MARK (void * p ) {
  Wrap_Chunk * wc = (Wrap_Chunk * ) p ; 
  int i ; 
  for (i = wc -> len ; i -- ; ) {
    GC_mark (wc -> a [i ] ) ; 
  }
  return ((sizeof (Wrap_Chunk ) + ((wc -> len - 1 ) * sizeof (Scheme_Object * ) ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_wrapchunk_FIXUP (void * p ) {
  Wrap_Chunk * wc = (Wrap_Chunk * ) p ; 
  int i ; 
  for (i = wc -> len ; i -- ; ) {
    GC_fixup (& (wc -> a [i ] ) ) ; 
  }
  return ((sizeof (Wrap_Chunk ) + ((wc -> len - 1 ) * sizeof (Scheme_Object * ) ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_cert_SIZE (void * p ) {
  return ((sizeof (Scheme_Cert ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_cert_MARK (void * p ) {
  Scheme_Cert * c = (Scheme_Cert * ) p ; 
  GC_mark (c -> mark ) ; 
  GC_mark (c -> modidx ) ; 
  GC_mark (c -> insp ) ; 
  GC_mark (c -> key ) ; 
  GC_mark (c -> mapped ) ; 
  GC_mark (c -> next ) ; 
  return ((sizeof (Scheme_Cert ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_cert_FIXUP (void * p ) {
  Scheme_Cert * c = (Scheme_Cert * ) p ; 
  GC_fixup (& (c -> mark ) ) ; 
  GC_fixup (& (c -> modidx ) ) ; 
  GC_fixup (& (c -> insp ) ) ; 
  GC_fixup (& (c -> key ) ) ; 
  GC_fixup (& (c -> mapped ) ) ; 
  GC_fixup (& (c -> next ) ) ; 
  return ((sizeof (Scheme_Cert ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int lex_rib_SIZE (void * p ) {
  return ((sizeof (Scheme_Lexical_Rib ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int lex_rib_MARK (void * p ) {
  Scheme_Lexical_Rib * rib = (Scheme_Lexical_Rib * ) p ; 
  GC_mark (rib -> rename ) ; 
  GC_mark (rib -> next ) ; 
  return ((sizeof (Scheme_Lexical_Rib ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int lex_rib_FIXUP (void * p ) {
  Scheme_Lexical_Rib * rib = (Scheme_Lexical_Rib * ) p ; 
  GC_fixup (& (rib -> rename ) ) ; 
  GC_fixup (& (rib -> next ) ) ; 
  return ((sizeof (Scheme_Lexical_Rib ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static void register_traversers (void ) {
  GC_register_traversers (scheme_rename_table_type , mark_rename_table_SIZE , mark_rename_table_MARK , mark_rename_table_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_srcloc , mark_srcloc_SIZE , mark_srcloc_MARK , mark_srcloc_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_wrap_chunk_type , mark_wrapchunk_SIZE , mark_wrapchunk_MARK , mark_wrapchunk_FIXUP , 0 , 0 ) ; 
  GC_register_traversers (scheme_certifications_type , mark_cert_SIZE , mark_cert_MARK , mark_cert_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_lexical_rib_type , lex_rib_SIZE , lex_rib_MARK , lex_rib_FIXUP , 1 , 0 ) ; 
}
