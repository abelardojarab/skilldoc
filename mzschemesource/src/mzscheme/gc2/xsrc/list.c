#include "precomp.h"
Scheme_Object scheme_null [1 ] ; 
static Scheme_Object * pair_p_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * cons_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * cons_immutable (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * null_p_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * list_p_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * list_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * list_immutable_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * list_star_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * list_star_immutable_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * immutablep (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * length_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * append_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * append_bang_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * reverse_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * reverse_bang_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * list_tail_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * list_ref_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * memv (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * memq (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * member (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * assv (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * assq (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * assoc (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * caaar_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * caadr_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * cadar_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * cdaar_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * cdadr_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * cddar_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * caddr_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * cdddr_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * cddddr_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * cadddr_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * cdaddr_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * cddadr_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * cdddar_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * caaddr_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * cadadr_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * caddar_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * cdaadr_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * cdadar_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * cddaar_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * cdaaar_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * cadaar_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * caadar_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * caaadr_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * caaaar_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * box (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * immutable_box (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * box_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * unbox (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * set_box (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * make_hash_table (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * make_immutable_hash_table (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * hash_table_count (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * hash_table_copy (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * hash_table_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * hash_table_put (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * hash_table_get (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * hash_table_remove (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * hash_table_map (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * hash_table_for_each (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * hash_table_iterate_start (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * hash_table_iterate_next (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * hash_table_iterate_value (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * hash_table_iterate_key (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * eq_hash_code (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * equal_hash_code (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * make_weak_box (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * weak_box_value (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * weak_boxp (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * make_ephemeron (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * ephemeron_value (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * ephemeronp (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * weak_symbol , * equal_symbol ; 
void scheme_init_list (Scheme_Env * env ) {
  Scheme_Object * p ; 
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
  Scheme_Object * __funcarg4 = NULLED_OUT ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(p, 1)));
# define XfOrM1_COUNT (2)
# define SETUP_XfOrM1(x) SETUP(XfOrM1_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  p = NULLED_OUT ; 
  scheme_null -> type = scheme_null_type ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("null" , scheme_null , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_folding_prim (pair_p_prim , "pair?" , 1 , 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 16384 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("pair?" , p , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_prim_w_arity (cons_prim , "cons" , 2 , 2 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 512 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("cons" , p , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_noncm_prim (scheme_checked_car , "car" , 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 16384 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("car" , p , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_noncm_prim (scheme_checked_cdr , "cdr" , 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 16384 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("cdr" , p , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_noncm_prim (scheme_checked_set_car , "set-car!" , 2 , 2 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 512 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("set-car!" , p , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_noncm_prim (scheme_checked_set_cdr , "set-cdr!" , 2 , 2 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 512 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("set-cdr!" , p , env ) ); 
  (__funcarg72 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (cons_immutable , "cons-immutable" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("cons-immutable" , __funcarg72 , env ) )) ; 
  p = FUNCCALL_AGAIN(scheme_make_folding_prim (null_p_prim , "null?" , 1 , 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 16384 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("null?" , p , env ) ); 
  (__funcarg71 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (list_p_prim , "list?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("list?" , __funcarg71 , env ) )) ; 
  (__funcarg70 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (list_prim , "list" , 0 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("list" , __funcarg70 , env ) )) ; 
  (__funcarg69 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (list_immutable_prim , "list-immutable" , 0 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("list-immutable" , __funcarg69 , env ) )) ; 
  (__funcarg68 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (list_star_prim , "list*" , 1 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("list*" , __funcarg68 , env ) )) ; 
  (__funcarg67 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (list_star_immutable_prim , "list*-immutable" , 1 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("list*-immutable" , __funcarg67 , env ) )) ; 
  (__funcarg66 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (immutablep , "immutable?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("immutable?" , __funcarg66 , env ) )) ; 
  (__funcarg65 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (length_prim , "length" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("length" , __funcarg65 , env ) )) ; 
  (__funcarg64 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (append_prim , "append" , 0 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("append" , __funcarg64 , env ) )) ; 
  (__funcarg63 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (append_bang_prim , "append!" , 0 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("append!" , __funcarg63 , env ) )) ; 
  (__funcarg62 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (reverse_prim , "reverse" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("reverse" , __funcarg62 , env ) )) ; 
  (__funcarg61 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (reverse_bang_prim , "reverse!" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("reverse!" , __funcarg61 , env ) )) ; 
  (__funcarg60 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (list_tail_prim , "list-tail" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("list-tail" , __funcarg60 , env ) )) ; 
  (__funcarg59 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (list_ref_prim , "list-ref" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("list-ref" , __funcarg59 , env ) )) ; 
  (__funcarg58 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (memq , "memq" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("memq" , __funcarg58 , env ) )) ; 
  (__funcarg57 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (memv , "memv" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("memv" , __funcarg57 , env ) )) ; 
  (__funcarg56 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (member , "member" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("member" , __funcarg56 , env ) )) ; 
  (__funcarg55 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (assq , "assq" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("assq" , __funcarg55 , env ) )) ; 
  (__funcarg54 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (assv , "assv" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("assv" , __funcarg54 , env ) )) ; 
  (__funcarg53 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (assoc , "assoc" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("assoc" , __funcarg53 , env ) )) ; 
  p = FUNCCALL_AGAIN(scheme_make_noncm_prim (scheme_checked_caar , "caar" , 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 16384 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("caar" , p , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_noncm_prim (scheme_checked_cadr , "cadr" , 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 16384 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("cadr" , p , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_noncm_prim (scheme_checked_cdar , "cdar" , 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 16384 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("cdar" , p , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_noncm_prim (scheme_checked_cddr , "cddr" , 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 16384 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("cddr" , p , env ) ); 
  (__funcarg52 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (caaar_prim , "caaar" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("caaar" , __funcarg52 , env ) )) ; 
  (__funcarg51 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (caadr_prim , "caadr" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("caadr" , __funcarg51 , env ) )) ; 
  (__funcarg50 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (cadar_prim , "cadar" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("cadar" , __funcarg50 , env ) )) ; 
  (__funcarg49 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (cdaar_prim , "cdaar" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("cdaar" , __funcarg49 , env ) )) ; 
  (__funcarg48 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (cdadr_prim , "cdadr" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("cdadr" , __funcarg48 , env ) )) ; 
  (__funcarg47 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (cddar_prim , "cddar" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("cddar" , __funcarg47 , env ) )) ; 
  (__funcarg46 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (caddr_prim , "caddr" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("caddr" , __funcarg46 , env ) )) ; 
  (__funcarg45 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (cdddr_prim , "cdddr" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("cdddr" , __funcarg45 , env ) )) ; 
  (__funcarg44 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (cddddr_prim , "cddddr" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("cddddr" , __funcarg44 , env ) )) ; 
  (__funcarg43 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (cadddr_prim , "cadddr" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("cadddr" , __funcarg43 , env ) )) ; 
  (__funcarg42 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (cdaddr_prim , "cdaddr" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("cdaddr" , __funcarg42 , env ) )) ; 
  (__funcarg41 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (cddadr_prim , "cddadr" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("cddadr" , __funcarg41 , env ) )) ; 
  (__funcarg40 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (cdddar_prim , "cdddar" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("cdddar" , __funcarg40 , env ) )) ; 
  (__funcarg39 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (caaddr_prim , "caaddr" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("caaddr" , __funcarg39 , env ) )) ; 
  (__funcarg38 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (cadadr_prim , "cadadr" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("cadadr" , __funcarg38 , env ) )) ; 
  (__funcarg37 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (caddar_prim , "caddar" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("caddar" , __funcarg37 , env ) )) ; 
  (__funcarg36 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (cdaadr_prim , "cdaadr" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("cdaadr" , __funcarg36 , env ) )) ; 
  (__funcarg35 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (cdadar_prim , "cdadar" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("cdadar" , __funcarg35 , env ) )) ; 
  (__funcarg34 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (cddaar_prim , "cddaar" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("cddaar" , __funcarg34 , env ) )) ; 
  (__funcarg33 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (cdaaar_prim , "cdaaar" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("cdaaar" , __funcarg33 , env ) )) ; 
  (__funcarg32 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (cadaar_prim , "cadaar" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("cadaar" , __funcarg32 , env ) )) ; 
  (__funcarg31 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (caadar_prim , "caadar" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("caadar" , __funcarg31 , env ) )) ; 
  (__funcarg30 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (caaadr_prim , "caaadr" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("caaadr" , __funcarg30 , env ) )) ; 
  (__funcarg29 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (caaaar_prim , "caaaar" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("caaaar" , __funcarg29 , env ) )) ; 
  (__funcarg28 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (box , "box" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("box" , __funcarg28 , env ) )) ; 
  (__funcarg27 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (immutable_box , "box-immutable" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("box-immutable" , __funcarg27 , env ) )) ; 
  p = FUNCCALL_AGAIN(scheme_make_folding_prim (box_p , "box?" , 1 , 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 16384 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("box?" , p , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_noncm_prim (unbox , "unbox" , 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 16384 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("unbox" , p , env ) ); 
  (__funcarg26 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (set_box , "set-box!" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("set-box!" , __funcarg26 , env ) )) ; 
  (__funcarg25 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (make_hash_table , "make-hash-table" , 0 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-hash-table" , __funcarg25 , env ) )) ; 
  (__funcarg24 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (make_immutable_hash_table , "make-immutable-hash-table" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-immutable-hash-table" , __funcarg24 , env ) )) ; 
  (__funcarg23 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (hash_table_p , "hash-table?" , 1 , 3 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("hash-table?" , __funcarg23 , env ) )) ; 
  (__funcarg22 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (hash_table_count , "hash-table-count" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("hash-table-count" , __funcarg22 , env ) )) ; 
  (__funcarg21 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (hash_table_copy , "hash-table-copy" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("hash-table-copy" , __funcarg21 , env ) )) ; 
  (__funcarg20 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (hash_table_put , "hash-table-put!" , 3 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("hash-table-put!" , __funcarg20 , env ) )) ; 
  (__funcarg19 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (hash_table_get , "hash-table-get" , 2 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("hash-table-get" , __funcarg19 , env ) )) ; 
  (__funcarg18 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (hash_table_remove , "hash-table-remove!" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("hash-table-remove!" , __funcarg18 , env ) )) ; 
  (__funcarg17 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (hash_table_map , "hash-table-map" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("hash-table-map" , __funcarg17 , env ) )) ; 
  (__funcarg16 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (hash_table_for_each , "hash-table-for-each" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("hash-table-for-each" , __funcarg16 , env ) )) ; 
  (__funcarg15 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (hash_table_iterate_start , "hash-table-iterate-first" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("hash-table-iterate-first" , __funcarg15 , env ) )) ; 
  (__funcarg14 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (hash_table_iterate_next , "hash-table-iterate-next" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("hash-table-iterate-next" , __funcarg14 , env ) )) ; 
  (__funcarg13 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (hash_table_iterate_value , "hash-table-iterate-value" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("hash-table-iterate-value" , __funcarg13 , env ) )) ; 
  (__funcarg12 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (hash_table_iterate_key , "hash-table-iterate-key" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("hash-table-iterate-key" , __funcarg12 , env ) )) ; 
  (__funcarg11 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (eq_hash_code , "eq-hash-code" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("eq-hash-code" , __funcarg11 , env ) )) ; 
  (__funcarg10 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (equal_hash_code , "equal-hash-code" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("equal-hash-code" , __funcarg10 , env ) )) ; 
  (__funcarg9 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (make_weak_box , "make-weak-box" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-weak-box" , __funcarg9 , env ) )) ; 
  (__funcarg8 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (weak_box_value , "weak-box-value" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("weak-box-value" , __funcarg8 , env ) )) ; 
  (__funcarg7 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (weak_boxp , "weak-box?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("weak-box?" , __funcarg7 , env ) )) ; 
  (__funcarg6 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (make_ephemeron , "make-ephemeron" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-ephemeron" , __funcarg6 , env ) )) ; 
  (__funcarg5 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (ephemeron_value , "ephemeron-value" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("ephemeron-value" , __funcarg5 , env ) )) ; 
  (__funcarg4 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (ephemeronp , "ephemeron?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("ephemeron?" , __funcarg4 , env ) )) ; 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & weak_symbol , sizeof (weak_symbol ) ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & equal_symbol , sizeof (equal_symbol ) ) ); 
  weak_symbol = FUNCCALL_EMPTY(scheme_intern_symbol ("weak" ) ); 
  equal_symbol = FUNCCALL_EMPTY(scheme_intern_symbol ("equal" ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_pair (Scheme_Object * car , Scheme_Object * cdr ) {
  /* No conversion */
  return GC_malloc_pair (car , cdr ) ; 
}
Scheme_Object * scheme_make_raw_pair (Scheme_Object * car , Scheme_Object * cdr ) {
  Scheme_Object * cons ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(cdr, 0), PUSH(cons, 1), PUSH(car, 2)));
# define XfOrM3_COUNT (3)
# define SETUP_XfOrM3(x) SETUP(XfOrM3_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  cons = NULLED_OUT ; 
  cons = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM3(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  cons -> type = scheme_raw_pair_type ; 
  (((Scheme_Simple_Object * ) (cons ) ) -> u . pair_val . car ) = car ; 
  (((Scheme_Simple_Object * ) (cons ) ) -> u . pair_val . cdr ) = cdr ; 
  RET_VALUE_START (cons ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_immutable_pair (Scheme_Object * car , Scheme_Object * cdr ) {
  Scheme_Object * cons ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(cdr, 0), PUSH(cons, 1), PUSH(car, 2)));
# define XfOrM4_COUNT (3)
# define SETUP_XfOrM4(x) SETUP(XfOrM4_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  cons = NULLED_OUT ; 
  cons = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM4(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  cons -> type = scheme_pair_type ; 
  (((Scheme_Simple_Object * ) (cons ) ) -> u . pair_val . car ) = car ; 
  (((Scheme_Simple_Object * ) (cons ) ) -> u . pair_val . cdr ) = cdr ; 
  ((((Scheme_Inclhash_Object * ) (cons ) ) -> so . keyex |= 0x1 ) ) ; 
  RET_VALUE_START (cons ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_build_list (int size , Scheme_Object * * argv ) {
  Scheme_Object * pair = scheme_null ; 
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(pair, 1)));
# define XfOrM5_COUNT (2)
# define SETUP_XfOrM5(x) SETUP(XfOrM5_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  for (i = size ; i -- ; ) {
#   define XfOrM7_COUNT (0+XfOrM5_COUNT)
#   define SETUP_XfOrM7(x) SETUP_XfOrM5(x)
    pair = FUNCCALL(SETUP_XfOrM7(_), scheme_make_pair (argv [i ] , pair ) ); 
  }
  RET_VALUE_START (pair ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_build_list_offset (int size , Scheme_Object * * argv , int delta ) {
  Scheme_Object * pair = scheme_null ; 
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(pair, 1)));
# define XfOrM8_COUNT (2)
# define SETUP_XfOrM8(x) SETUP(XfOrM8_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  for (i = size ; i -- > delta ; ) {
#   define XfOrM10_COUNT (0+XfOrM8_COUNT)
#   define SETUP_XfOrM10(x) SETUP_XfOrM8(x)
    pair = FUNCCALL(SETUP_XfOrM10(_), scheme_make_pair (argv [i ] , pair ) ); 
  }
  RET_VALUE_START (pair ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_alloc_list (int size ) {
  Scheme_Object * pair = scheme_null ; 
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(pair, 0)));
# define XfOrM11_COUNT (1)
# define SETUP_XfOrM11(x) SETUP(XfOrM11_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  for (i = size ; i -- ; ) {
#   define XfOrM13_COUNT (0+XfOrM11_COUNT)
#   define SETUP_XfOrM13(x) SETUP_XfOrM11(x)
    pair = FUNCCALL(SETUP_XfOrM13(_), scheme_make_pair (scheme_false , pair ) ); 
  }
  RET_VALUE_START (pair ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_make_list_immutable (Scheme_Object * l ) {
  /* No conversion */
  for (; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
    if ((! (((Scheme_Inclhash_Object * ) (l ) ) -> so . keyex & 0x1 ) ) )
      ((((Scheme_Inclhash_Object * ) (l ) ) -> so . keyex |= 0x1 ) ) ; 
  }
}
int scheme_list_length (Scheme_Object * list ) {
  /* No conversion */
  int len ; 
  len = 0 ; 
  while (! ((list ) == (scheme_null ) ) ) {
    len ++ ; 
    if (((Scheme_Type ) (((((long ) (list ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (list ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
      list = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . cdr ) ; 
    else list = scheme_null ; 
  }
  return len ; 
}
int scheme_proper_list_length (Scheme_Object * list ) {
  /* No conversion */
  int len ; 
  Scheme_Object * turtle ; 
  len = 0 ; 
  turtle = list ; 
  while (((Scheme_Type ) (((((long ) (list ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (list ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
    len ++ ; 
    list = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . cdr ) ; 
    if (! ((Scheme_Type ) (((((long ) (list ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (list ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
      break ; 
    len ++ ; 
    list = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . cdr ) ; 
    if (((turtle ) == (list ) ) )
      break ; 
    turtle = (((Scheme_Simple_Object * ) (turtle ) ) -> u . pair_val . cdr ) ; 
  }
  if (((list ) == (scheme_null ) ) )
    return len ; 
  return - 1 ; 
}
Scheme_Object * scheme_named_map_1 (char * name , Scheme_Object * (* fun ) (Scheme_Object * , Scheme_Object * ) , Scheme_Object * lst , Scheme_Object * form ) {
  Scheme_Object * first = scheme_null , * last = ((void * ) 0 ) , * pr ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(lst, 0), PUSH(pr, 1), PUSH(first, 2), PUSH(name, 3), PUSH(form, 4), PUSH(last, 5)));
# define XfOrM23_COUNT (6)
# define SETUP_XfOrM23(x) SETUP(XfOrM23_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  pr = NULLED_OUT ; 
  while ((((Scheme_Type ) (((((long ) (lst ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lst ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (lst ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lst ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) lst ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) lst ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) {
    Scheme_Object * v ; 
    BLOCK_SETUP((PUSH(v, 0+XfOrM23_COUNT)));
#   define XfOrM25_COUNT (1+XfOrM23_COUNT)
#   define SETUP_XfOrM25(x) SETUP(XfOrM25_COUNT)
    v = NULLED_OUT ; 
    v = (((Scheme_Type ) (((((long ) (lst ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lst ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (lst ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM25(_), scheme_stx_content (lst ) )) ) -> u . pair_val . car ) ) ; 
    v = FUNCCALL(SETUP_XfOrM25(_), fun (v , form ) ); 
    pr = FUNCCALL_AGAIN(scheme_make_pair (v , scheme_null ) ); 
    if (last )
      (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = pr ; 
    else first = pr ; 
    last = pr ; 
    lst = (((Scheme_Type ) (((((long ) (lst ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lst ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (lst ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM25(_), scheme_stx_content (lst ) )) ) -> u . pair_val . cdr ) ) ; 
  }
  if (! (((lst ) == (scheme_null ) ) || (((Scheme_Type ) (((((long ) (lst ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lst ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((((Scheme_Stx * ) lst ) -> val ) == (scheme_null ) ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_syntax (name , lst , form , "bad syntax (" "illegal use of `.'" ")" ) ); 
  RET_VALUE_START (first ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_map_1 (Scheme_Object * (* fun ) (Scheme_Object * ) , Scheme_Object * lst ) {
  /* No conversion */
  return scheme_named_map_1 ("map" , (Scheme_Object * (* ) (Scheme_Object * , Scheme_Object * ) ) fun , lst , ((void * ) 0 ) ) ; 
}
Scheme_Object * scheme_car (Scheme_Object * pair ) {
  /* No conversion */
  return ((((Scheme_Simple_Object * ) (pair ) ) -> u . pair_val . car ) ) ; 
}
Scheme_Object * scheme_cdr (Scheme_Object * pair ) {
  /* No conversion */
  return ((((Scheme_Simple_Object * ) (pair ) ) -> u . pair_val . cdr ) ) ; 
}
Scheme_Object * scheme_cadr (Scheme_Object * pair ) {
  /* No conversion */
  return ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (pair ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ; 
}
Scheme_Object * scheme_caddr (Scheme_Object * pair ) {
  /* No conversion */
  return ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (pair ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ; 
}
Scheme_Object * scheme_copy_list (Scheme_Object * l ) {
  Scheme_Object * __funcarg73 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(0);
# define XfOrM31_COUNT (0)
# define SETUP_XfOrM31(x) SETUP(XfOrM31_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg73 = FUNCCALL_EMPTY(scheme_list_to_vector (l ) ), FUNCCALL_EMPTY(scheme_vector_to_list (__funcarg73 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * pair_p_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * cons_prim (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * cons ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(cons, 0)));
# define XfOrM33_COUNT (1)
# define SETUP_XfOrM33(x) SETUP(XfOrM33_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  cons = NULLED_OUT ; 
  cons = FUNCCALL(SETUP_XfOrM33(_), scheme_make_pair (argv [0 ] , argv [1 ] ) ); 
  RET_VALUE_START ((cons ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * cons_immutable (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * cons ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(cons, 0)));
# define XfOrM34_COUNT (1)
# define SETUP_XfOrM34(x) SETUP(XfOrM34_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  cons = NULLED_OUT ; 
  cons = FUNCCALL(SETUP_XfOrM34(_), scheme_make_immutable_pair (argv [0 ] , argv [1 ] ) ); 
  RET_VALUE_START ((cons ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_checked_car (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    scheme_wrong_type ("car" , "pair" , 0 , argc , argv ) ; 
  return ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ; 
}
Scheme_Object * scheme_checked_cdr (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    scheme_wrong_type ("cdr" , "pair" , 0 , argc , argv ) ; 
  return ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ; 
}
Scheme_Object * scheme_checked_set_car (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && (! (((Scheme_Inclhash_Object * ) (argv [0 ] ) ) -> so . keyex & 0x1 ) ) ) )
    scheme_wrong_type ("set-car!" , "mutable-pair" , 0 , argc , argv ) ; 
  (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) = argv [1 ] ; 
  return scheme_void ; 
}
Scheme_Object * scheme_checked_set_cdr (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && (! (((Scheme_Inclhash_Object * ) (argv [0 ] ) ) -> so . keyex & 0x1 ) ) ) )
    scheme_wrong_type ("set-cdr!" , "mutable-pair" , 0 , argc , argv ) ; 
  (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) = argv [1 ] ; 
  return scheme_void ; 
}
static Scheme_Object * null_p_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (((argv [0 ] ) == (scheme_null ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * list_p_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * obj1 , * obj2 ; 
  obj1 = obj2 = argv [0 ] ; 
  do {
    if (((obj1 ) == (scheme_null ) ) )
      return scheme_true ; 
    if (! ((Scheme_Type ) (((((long ) (obj1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj1 ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
      return (scheme_false ) ; 
    obj1 = (((Scheme_Simple_Object * ) (obj1 ) ) -> u . pair_val . cdr ) ; 
    if (((obj1 ) == (scheme_null ) ) )
      return scheme_true ; 
    if (! ((Scheme_Type ) (((((long ) (obj1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj1 ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
      return scheme_false ; 
    obj1 = (((Scheme_Simple_Object * ) (obj1 ) ) -> u . pair_val . cdr ) ; 
    obj2 = (((Scheme_Simple_Object * ) (obj2 ) ) -> u . pair_val . cdr ) ; 
  }
  while (((obj1 ) != (obj2 ) ) ) ; 
  return scheme_false ; 
}
static Scheme_Object * list_prim (int argc , Scheme_Object * argv [] ) {
  int i ; 
  Scheme_Object * l ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(l, 1)));
# define XfOrM43_COUNT (2)
# define SETUP_XfOrM43(x) SETUP(XfOrM43_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  l = NULLED_OUT ; 
  l = scheme_null ; 
  for (i = argc ; i -- ; ) {
#   define XfOrM45_COUNT (0+XfOrM43_COUNT)
#   define SETUP_XfOrM45(x) SETUP_XfOrM43(x)
    l = FUNCCALL(SETUP_XfOrM45(_), GC_malloc_pair (argv [i ] , l ) ); 
  }
  RET_VALUE_START (l ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * list_immutable_prim (int argc , Scheme_Object * argv [] ) {
  int i ; 
  Scheme_Object * l ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(l, 1)));
# define XfOrM46_COUNT (2)
# define SETUP_XfOrM46(x) SETUP(XfOrM46_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  l = NULLED_OUT ; 
  l = scheme_null ; 
  for (i = argc ; i -- ; ) {
#   define XfOrM48_COUNT (0+XfOrM46_COUNT)
#   define SETUP_XfOrM48(x) SETUP_XfOrM46(x)
    l = FUNCCALL(SETUP_XfOrM48(_), scheme_make_immutable_pair (argv [i ] , l ) ); 
  }
  RET_VALUE_START (l ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * list_star_prim (int argc , Scheme_Object * argv [] ) {
  int i ; 
  Scheme_Object * l ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(l, 1)));
# define XfOrM49_COUNT (2)
# define SETUP_XfOrM49(x) SETUP(XfOrM49_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  l = NULLED_OUT ; 
  -- argc ; 
  l = argv [argc ] ; 
  for (i = argc ; i -- ; ) {
#   define XfOrM51_COUNT (0+XfOrM49_COUNT)
#   define SETUP_XfOrM51(x) SETUP_XfOrM49(x)
    l = FUNCCALL(SETUP_XfOrM51(_), GC_malloc_pair (argv [i ] , l ) ); 
  }
  RET_VALUE_START (l ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * list_star_immutable_prim (int argc , Scheme_Object * argv [] ) {
  int i ; 
  Scheme_Object * l ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(l, 1)));
# define XfOrM52_COUNT (2)
# define SETUP_XfOrM52(x) SETUP(XfOrM52_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  l = NULLED_OUT ; 
  -- argc ; 
  l = argv [argc ] ; 
  for (i = argc ; i -- ; ) {
#   define XfOrM54_COUNT (0+XfOrM52_COUNT)
#   define SETUP_XfOrM54(x) SETUP_XfOrM52(x)
    l = FUNCCALL(SETUP_XfOrM54(_), scheme_make_immutable_pair (argv [i ] , l ) ); 
  }
  RET_VALUE_START (l ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * immutablep (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * v = argv [0 ] ; 
  return ((! (((long ) (v ) ) & 0x1 ) && (((Scheme_Inclhash_Object * ) (v ) ) -> so . keyex & 0x1 ) && (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || ((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) || ((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) || ((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) || ((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * length_prim (int argc , Scheme_Object * argv [] ) {
  int l ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM56_COUNT (1)
# define SETUP_XfOrM56(x) SETUP(XfOrM56_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! (((argv [0 ] ) == (scheme_null ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("length" , "proper list" , 0 , argc , argv ) ); 
  l = FUNCCALL(SETUP_XfOrM56(_), scheme_proper_list_length (argv [0 ] ) ); 
  if (l < 0 )
    FUNCCALL_EMPTY(scheme_wrong_type ("length" , "proper list" , 0 , argc , argv ) ); 
  RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (l ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_append (Scheme_Object * lst1 , Scheme_Object * lst2 ) {
  Scheme_Object * first , * last , * orig1 , * v ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(first, 0), PUSH(last, 1), PUSH(v, 2), PUSH(orig1, 3), PUSH(lst2, 4), PUSH(lst1, 5)));
# define XfOrM57_COUNT (6)
# define SETUP_XfOrM57(x) SETUP(XfOrM57_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  first = NULLED_OUT ; 
  last = NULLED_OUT ; 
  orig1 = NULLED_OUT ; 
  v = NULLED_OUT ; 
  orig1 = lst1 ; 
  first = last = ((void * ) 0 ) ; 
  while (((Scheme_Type ) (((((long ) (lst1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lst1 ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#   define XfOrM61_COUNT (0+XfOrM57_COUNT)
#   define SETUP_XfOrM61(x) SETUP_XfOrM57(x)
    v = FUNCCALL(SETUP_XfOrM61(_), scheme_make_pair ((((Scheme_Simple_Object * ) (lst1 ) ) -> u . pair_val . car ) , scheme_null ) ); 
    if (! first )
      first = v ; 
    else (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = v ; 
    last = v ; 
    lst1 = (((Scheme_Simple_Object * ) (lst1 ) ) -> u . pair_val . cdr ) ; 
    {
#     define XfOrM62_COUNT (0+XfOrM61_COUNT)
#     define SETUP_XfOrM62(x) SETUP_XfOrM61(x)
      if ((scheme_fuel_counter ) <= 0 ) {
#       define XfOrM63_COUNT (0+XfOrM62_COUNT)
#       define SETUP_XfOrM63(x) SETUP_XfOrM62(x)
        FUNCCALL(SETUP_XfOrM63(_), scheme_out_of_fuel () ); 
      }
    }
    ; 
  }
  if (! ((lst1 ) == (scheme_null ) ) )
    FUNCCALL(SETUP_XfOrM57(_), scheme_wrong_type ("append" , "proper list" , - 1 , 0 , & orig1 ) ); 
  if (! last )
    RET_VALUE_START (lst2 ) RET_VALUE_END ; 
  (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = lst2 ; 
  RET_VALUE_START (first ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_reverse (Scheme_Object * l ) {
  Scheme_Object * a [1 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 1, 0)));
# define XfOrM64_COUNT (3)
# define SETUP_XfOrM64(x) SETUP(XfOrM64_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a [0 ] = l ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM64(_), reverse_prim (1 , a ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * scheme_append_bang (Scheme_Object * lst1 , Scheme_Object * lst2 ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(lst1, 0), PUSH(lst2, 1)));
# define XfOrM65_COUNT (2)
# define SETUP_XfOrM65(x) SETUP(XfOrM65_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (((lst1 ) == (scheme_null ) ) )
    RET_VALUE_START (lst2 ) RET_VALUE_END ; 
  else {
    Scheme_Object * prev , * orig ; 
    BLOCK_SETUP((PUSH(orig, 0+XfOrM65_COUNT), PUSH(prev, 1+XfOrM65_COUNT)));
#   define XfOrM66_COUNT (2+XfOrM65_COUNT)
#   define SETUP_XfOrM66(x) SETUP(XfOrM66_COUNT)
    prev = NULLED_OUT ; 
    orig = NULLED_OUT ; 
    orig = lst1 ; 
    do {
#     define XfOrM70_COUNT (0+XfOrM66_COUNT)
#     define SETUP_XfOrM70(x) SETUP_XfOrM66(x)
      prev = lst1 ; 
      if (! ((Scheme_Type ) (((((long ) (lst1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lst1 ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
        FUNCCALL(SETUP_XfOrM70(_), scheme_wrong_type ("append!" , "proper list" , - 1 , 0 , & lst1 ) ); 
      lst1 = (((Scheme_Simple_Object * ) (lst1 ) ) -> u . pair_val . cdr ) ; 
      {
#       define XfOrM71_COUNT (0+XfOrM70_COUNT)
#       define SETUP_XfOrM71(x) SETUP_XfOrM70(x)
        if ((scheme_fuel_counter ) <= 0 ) {
#         define XfOrM72_COUNT (0+XfOrM71_COUNT)
#         define SETUP_XfOrM72(x) SETUP_XfOrM71(x)
          FUNCCALL(SETUP_XfOrM72(_), scheme_out_of_fuel () ); 
        }
      }
      ; 
    }
    while (! ((lst1 ) == (scheme_null ) ) ) ; 
    if (! (((Scheme_Type ) (((((long ) (prev ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (prev ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && (! (((Scheme_Inclhash_Object * ) (prev ) ) -> so . keyex & 0x1 ) ) ) )
      FUNCCALL(SETUP_XfOrM66(_), scheme_wrong_type ("append!" , "mutable proper list" , - 1 , 0 , & lst1 ) ); 
    (((Scheme_Simple_Object * ) (prev ) ) -> u . pair_val . cdr ) = lst2 ; 
    RET_VALUE_START (orig ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * append_prim (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * res ; 
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(res, 1)));
# define XfOrM73_COUNT (2)
# define SETUP_XfOrM73(x) SETUP(XfOrM73_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  res = NULLED_OUT ; 
  if (! argc )
    RET_VALUE_START (scheme_null ) RET_VALUE_END ; 
  res = argv [argc - 1 ] ; 
  for (i = argc - 1 ; i -- ; ) {
#   define XfOrM75_COUNT (0+XfOrM73_COUNT)
#   define SETUP_XfOrM75(x) SETUP_XfOrM73(x)
    res = FUNCCALL(SETUP_XfOrM75(_), scheme_append (argv [i ] , res ) ); 
  }
  RET_VALUE_START (res ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * append_bang_prim (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * res ; 
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(res, 1)));
# define XfOrM76_COUNT (2)
# define SETUP_XfOrM76(x) SETUP(XfOrM76_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  res = NULLED_OUT ; 
  if (! argc )
    RET_VALUE_START (scheme_null ) RET_VALUE_END ; 
  res = argv [argc - 1 ] ; 
  for (i = argc - 1 ; i -- ; ) {
#   define XfOrM78_COUNT (0+XfOrM76_COUNT)
#   define SETUP_XfOrM78(x) SETUP_XfOrM76(x)
    res = FUNCCALL(SETUP_XfOrM78(_), scheme_append_bang (argv [i ] , res ) ); 
  }
  RET_VALUE_START (res ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * reverse_prim (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * lst , * last ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(last, 0), PUSH(argv, 1), PUSH(lst, 2)));
# define XfOrM79_COUNT (3)
# define SETUP_XfOrM79(x) SETUP(XfOrM79_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  lst = NULLED_OUT ; 
  last = NULLED_OUT ; 
  last = scheme_null ; 
  lst = argv [0 ] ; 
  while (! ((lst ) == (scheme_null ) ) ) {
#   define XfOrM83_COUNT (0+XfOrM79_COUNT)
#   define SETUP_XfOrM83(x) SETUP_XfOrM79(x)
    if (! ((Scheme_Type ) (((((long ) (lst ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lst ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("reverse" , "proper list" , 0 , argc , argv ) ); 
    last = FUNCCALL(SETUP_XfOrM83(_), scheme_make_pair ((((Scheme_Simple_Object * ) (lst ) ) -> u . pair_val . car ) , last ) ); 
    lst = (((Scheme_Simple_Object * ) (lst ) ) -> u . pair_val . cdr ) ; 
    {
#     define XfOrM84_COUNT (0+XfOrM83_COUNT)
#     define SETUP_XfOrM84(x) SETUP_XfOrM83(x)
      if ((scheme_fuel_counter ) <= 0 ) {
#       define XfOrM85_COUNT (0+XfOrM84_COUNT)
#       define SETUP_XfOrM85(x) SETUP_XfOrM84(x)
        FUNCCALL(SETUP_XfOrM85(_), scheme_out_of_fuel () ); 
      }
    }
    ; 
  }
  RET_VALUE_START ((last ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * reverse_bang_prim (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * lst , * prev , * next ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(prev, 0), PUSH(argv, 1), PUSH(next, 2), PUSH(lst, 3)));
# define XfOrM86_COUNT (4)
# define SETUP_XfOrM86(x) SETUP(XfOrM86_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  lst = NULLED_OUT ; 
  prev = NULLED_OUT ; 
  next = NULLED_OUT ; 
  prev = ((void * ) 0 ) ; 
  lst = argv [0 ] ; 
  while (! ((lst ) == (scheme_null ) ) ) {
#   define XfOrM90_COUNT (0+XfOrM86_COUNT)
#   define SETUP_XfOrM90(x) SETUP_XfOrM86(x)
    if (! (((Scheme_Type ) (((((long ) (lst ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lst ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && (! (((Scheme_Inclhash_Object * ) (lst ) ) -> so . keyex & 0x1 ) ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("reverse!" , "mutable proper list" , 0 , argc , argv ) ); 
    next = (((Scheme_Simple_Object * ) (lst ) ) -> u . pair_val . cdr ) ; 
    if (prev )
      (((Scheme_Simple_Object * ) (lst ) ) -> u . pair_val . cdr ) = prev ; 
    else (((Scheme_Simple_Object * ) (lst ) ) -> u . pair_val . cdr ) = scheme_null ; 
    prev = lst ; 
    lst = next ; 
    {
#     define XfOrM91_COUNT (0+XfOrM90_COUNT)
#     define SETUP_XfOrM91(x) SETUP_XfOrM90(x)
      if ((scheme_fuel_counter ) <= 0 ) {
#       define XfOrM92_COUNT (0+XfOrM91_COUNT)
#       define SETUP_XfOrM92(x) SETUP_XfOrM91(x)
        FUNCCALL(SETUP_XfOrM92(_), scheme_out_of_fuel () ); 
      }
    }
    ; 
  }
  if (prev )
    RET_VALUE_START (prev ) RET_VALUE_END ; 
  else RET_VALUE_START (scheme_null ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_list_ref (char * name , int takecar , int argc , Scheme_Object * argv [] ) {
  long i , k ; 
  Scheme_Object * lst , * index , * bnindex ; 
  char * __funcarg78 = NULLED_OUT ; 
  char * __funcarg74 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(name, 0), PUSH(bnindex, 1), PUSH(argv, 2), PUSH(lst, 3), PUSH(index, 4)));
# define XfOrM93_COUNT (5)
# define SETUP_XfOrM93(x) SETUP(XfOrM93_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  lst = NULLED_OUT ; 
  index = NULLED_OUT ; 
  bnindex = NULLED_OUT ; 
  if (((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) {
    bnindex = argv [1 ] ; 
    k = 0 ; 
  }
  else if (! (((long ) (argv [1 ] ) ) & 0x1 ) ) {
#   define XfOrM122_COUNT (0+XfOrM93_COUNT)
#   define SETUP_XfOrM122(x) SETUP_XfOrM93(x)
    FUNCCALL_EMPTY(scheme_wrong_type (name , "non-negative exact integer" , 1 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  else {
    bnindex = ((void * ) 0 ) ; 
    k = (((long ) (argv [1 ] ) ) >> 1 ) ; 
  }
  lst = argv [0 ] ; 
  index = argv [1 ] ; 
  if ((bnindex && ! ((& ((Scheme_Bignum * ) bnindex ) -> iso ) -> so . keyex & 0x1 ) ) || (! bnindex && (k < 0 ) ) ) {
#   define XfOrM120_COUNT (0+XfOrM93_COUNT)
#   define SETUP_XfOrM120(x) SETUP_XfOrM93(x)
    FUNCCALL_EMPTY(scheme_wrong_type (name , "non-negative exact integer" , 1 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  do {
#   define XfOrM108_COUNT (0+XfOrM93_COUNT)
#   define SETUP_XfOrM108(x) SETUP_XfOrM93(x)
    if (bnindex ) {
#     define XfOrM117_COUNT (0+XfOrM108_COUNT)
#     define SETUP_XfOrM117(x) SETUP_XfOrM108(x)
      if ((((long ) (bnindex ) ) & 0x1 ) ) {
        k = (((long ) (bnindex ) ) >> 1 ) ; 
        bnindex = 0 ; 
      }
      else {
#       define XfOrM118_COUNT (0+XfOrM117_COUNT)
#       define SETUP_XfOrM118(x) SETUP_XfOrM117(x)
        k = 1000000 ; 
        bnindex = FUNCCALL(SETUP_XfOrM118(_), scheme_bin_minus (bnindex , ((Scheme_Object * ) (void * ) (long ) ((((long ) (1000000 ) ) << 1 ) | 0x1 ) ) ) ); 
      }
    }
    for (i = 0 ; i < k ; i ++ ) {
#     define XfOrM113_COUNT (0+XfOrM108_COUNT)
#     define SETUP_XfOrM113(x) SETUP_XfOrM108(x)
      if (! ((Scheme_Type ) (((((long ) (lst ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lst ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
        char * lstr ; 
        int llen ; 
        BLOCK_SETUP((PUSH(lstr, 0+XfOrM113_COUNT)));
#       define XfOrM116_COUNT (1+XfOrM113_COUNT)
#       define SETUP_XfOrM116(x) SETUP(XfOrM116_COUNT)
        lstr = NULLED_OUT ; 
        lstr = FUNCCALL(SETUP_XfOrM116(_), scheme_make_provided_string (argv [0 ] , 2 , & llen ) ); 
        (__funcarg78 = FUNCCALL(SETUP_XfOrM116(_), scheme_make_provided_string (index , 2 , ((void * ) 0 ) ) ), FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: index %s too large for list%s: %t" , name , __funcarg78 , ((lst ) == (scheme_null ) ) ? "" : " (not a proper list)" , lstr , llen ) )) ; 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      lst = (((Scheme_Simple_Object * ) (lst ) ) -> u . pair_val . cdr ) ; 
      if (! (i & ((int ) 0xFF ) ) ) {
#       define XfOrM114_COUNT (0+XfOrM113_COUNT)
#       define SETUP_XfOrM114(x) SETUP_XfOrM113(x)
        if ((scheme_fuel_counter ) <= 0 ) {
#         define XfOrM115_COUNT (0+XfOrM114_COUNT)
#         define SETUP_XfOrM115(x) SETUP_XfOrM114(x)
          FUNCCALL(SETUP_XfOrM115(_), scheme_out_of_fuel () ); 
        }
      }
      ; 
    }
  }
  while (bnindex ) ; 
  if (takecar ) {
#   define XfOrM94_COUNT (0+XfOrM93_COUNT)
#   define SETUP_XfOrM94(x) SETUP_XfOrM93(x)
    if (! ((Scheme_Type ) (((((long ) (lst ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lst ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
      char * lstr ; 
      int llen ; 
      BLOCK_SETUP((PUSH(lstr, 0+XfOrM94_COUNT)));
#     define XfOrM95_COUNT (1+XfOrM94_COUNT)
#     define SETUP_XfOrM95(x) SETUP(XfOrM95_COUNT)
      lstr = NULLED_OUT ; 
      lstr = FUNCCALL(SETUP_XfOrM95(_), scheme_make_provided_string (argv [0 ] , 2 , & llen ) ); 
      (__funcarg74 = FUNCCALL(SETUP_XfOrM95(_), scheme_make_provided_string (index , 2 , ((void * ) 0 ) ) ), FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: index %s too large for list%s: %t" , name , __funcarg74 , ((lst ) == (scheme_null ) ) ? "" : " (not a proper list)" , lstr , llen ) )) ; 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    RET_VALUE_START ((((Scheme_Simple_Object * ) (lst ) ) -> u . pair_val . car ) ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (lst ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * list_tail_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_list_ref ("list-tail" , 0 , argc , argv ) ; 
}
static Scheme_Object * list_ref_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_list_ref ("list-ref" , 1 , argc , argv ) ; 
}
static Scheme_Object * memv (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * list , * turtle ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(list, 0), PUSH(argv, 1), PUSH(turtle, 2)));
# define XfOrM126_COUNT (3)
# define SETUP_XfOrM126(x) SETUP(XfOrM126_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  list = NULLED_OUT ; 
  turtle = NULLED_OUT ; 
  list = turtle = argv [1 ] ; 
  while (((Scheme_Type ) (((((long ) (list ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (list ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#   define XfOrM134_COUNT (0+XfOrM126_COUNT)
#   define SETUP_XfOrM134(x) SETUP_XfOrM126(x)
    if ((scheme_eqv (argv [0 ] , (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . car ) ) ) ) {
      RET_VALUE_START (list ) RET_VALUE_END ; 
    }
    list = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . cdr ) ; 
    if (((Scheme_Type ) (((((long ) (list ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (list ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#     define XfOrM135_COUNT (0+XfOrM134_COUNT)
#     define SETUP_XfOrM135(x) SETUP_XfOrM134(x)
      if ((scheme_eqv (argv [0 ] , (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . car ) ) ) ) {
        RET_VALUE_START (list ) RET_VALUE_END ; 
      }
      if (((list ) == (turtle ) ) )
        break ; 
      list = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . cdr ) ; 
      turtle = (((Scheme_Simple_Object * ) (turtle ) ) -> u . pair_val . cdr ) ; 
      {
#       define XfOrM136_COUNT (0+XfOrM135_COUNT)
#       define SETUP_XfOrM136(x) SETUP_XfOrM135(x)
        if ((scheme_fuel_counter ) <= 0 ) {
#         define XfOrM137_COUNT (0+XfOrM136_COUNT)
#         define SETUP_XfOrM137(x) SETUP_XfOrM136(x)
          FUNCCALL(SETUP_XfOrM137(_), scheme_out_of_fuel () ); 
        }
      }
      ; 
    }
  }
  if (! ((list ) == (scheme_null ) ) ) {
#   define XfOrM127_COUNT (0+XfOrM126_COUNT)
#   define SETUP_XfOrM127(x) SETUP_XfOrM126(x)
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: not a proper list: %V" , "memv" , argv [1 ] ) ); 
  }
  RET_VALUE_START ((scheme_false ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * memq (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * list , * turtle ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(list, 0), PUSH(argv, 1), PUSH(turtle, 2)));
# define XfOrM140_COUNT (3)
# define SETUP_XfOrM140(x) SETUP(XfOrM140_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  list = NULLED_OUT ; 
  turtle = NULLED_OUT ; 
  list = turtle = argv [1 ] ; 
  while (((Scheme_Type ) (((((long ) (list ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (list ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#   define XfOrM148_COUNT (0+XfOrM140_COUNT)
#   define SETUP_XfOrM148(x) SETUP_XfOrM140(x)
    if (((argv [0 ] ) == ((((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . car ) ) ) ) {
      RET_VALUE_START (list ) RET_VALUE_END ; 
    }
    list = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . cdr ) ; 
    if (((Scheme_Type ) (((((long ) (list ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (list ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#     define XfOrM149_COUNT (0+XfOrM148_COUNT)
#     define SETUP_XfOrM149(x) SETUP_XfOrM148(x)
      if (((argv [0 ] ) == ((((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . car ) ) ) ) {
        RET_VALUE_START (list ) RET_VALUE_END ; 
      }
      if (((list ) == (turtle ) ) )
        break ; 
      list = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . cdr ) ; 
      turtle = (((Scheme_Simple_Object * ) (turtle ) ) -> u . pair_val . cdr ) ; 
      {
#       define XfOrM150_COUNT (0+XfOrM149_COUNT)
#       define SETUP_XfOrM150(x) SETUP_XfOrM149(x)
        if ((scheme_fuel_counter ) <= 0 ) {
#         define XfOrM151_COUNT (0+XfOrM150_COUNT)
#         define SETUP_XfOrM151(x) SETUP_XfOrM150(x)
          FUNCCALL(SETUP_XfOrM151(_), scheme_out_of_fuel () ); 
        }
      }
      ; 
    }
  }
  if (! ((list ) == (scheme_null ) ) ) {
#   define XfOrM141_COUNT (0+XfOrM140_COUNT)
#   define SETUP_XfOrM141(x) SETUP_XfOrM140(x)
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: not a proper list: %V" , "memq" , argv [1 ] ) ); 
  }
  RET_VALUE_START ((scheme_false ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * member (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * list , * turtle ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(list, 0), PUSH(argv, 1), PUSH(turtle, 2)));
# define XfOrM154_COUNT (3)
# define SETUP_XfOrM154(x) SETUP(XfOrM154_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  list = NULLED_OUT ; 
  turtle = NULLED_OUT ; 
  list = turtle = argv [1 ] ; 
  while (((Scheme_Type ) (((((long ) (list ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (list ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#   define XfOrM162_COUNT (0+XfOrM154_COUNT)
#   define SETUP_XfOrM162(x) SETUP_XfOrM154(x)
    if (FUNCCALL(SETUP_XfOrM162(_), scheme_equal (argv [0 ] , (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . car ) ) )) {
      RET_VALUE_START (list ) RET_VALUE_END ; 
    }
    list = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . cdr ) ; 
    if (((Scheme_Type ) (((((long ) (list ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (list ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#     define XfOrM163_COUNT (0+XfOrM162_COUNT)
#     define SETUP_XfOrM163(x) SETUP_XfOrM162(x)
      if (FUNCCALL(SETUP_XfOrM163(_), scheme_equal (argv [0 ] , (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . car ) ) )) {
        RET_VALUE_START (list ) RET_VALUE_END ; 
      }
      if (((list ) == (turtle ) ) )
        break ; 
      list = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . cdr ) ; 
      turtle = (((Scheme_Simple_Object * ) (turtle ) ) -> u . pair_val . cdr ) ; 
      {
#       define XfOrM164_COUNT (0+XfOrM163_COUNT)
#       define SETUP_XfOrM164(x) SETUP_XfOrM163(x)
        if ((scheme_fuel_counter ) <= 0 ) {
#         define XfOrM165_COUNT (0+XfOrM164_COUNT)
#         define SETUP_XfOrM165(x) SETUP_XfOrM164(x)
          FUNCCALL(SETUP_XfOrM165(_), scheme_out_of_fuel () ); 
        }
      }
      ; 
    }
  }
  if (! ((list ) == (scheme_null ) ) ) {
#   define XfOrM155_COUNT (0+XfOrM154_COUNT)
#   define SETUP_XfOrM155(x) SETUP_XfOrM154(x)
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: not a proper list: %V" , "member" , argv [1 ] ) ); 
  }
  RET_VALUE_START ((scheme_false ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * assv (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * pair , * list , * turtle ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(list, 0), PUSH(pair, 1), PUSH(argv, 2), PUSH(turtle, 3)));
# define XfOrM168_COUNT (4)
# define SETUP_XfOrM168(x) SETUP(XfOrM168_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  pair = NULLED_OUT ; 
  list = NULLED_OUT ; 
  turtle = NULLED_OUT ; 
  list = turtle = argv [1 ] ; 
  while (((Scheme_Type ) (((((long ) (list ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (list ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#   define XfOrM177_COUNT (0+XfOrM168_COUNT)
#   define SETUP_XfOrM177(x) SETUP_XfOrM168(x)
    pair = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . car ) ; 
    if (! ((Scheme_Type ) (((((long ) (pair ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (pair ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
      char * npstr , * lstr ; 
      int nplen , llen ; 
      BLOCK_SETUP((PUSH(lstr, 0+XfOrM177_COUNT), PUSH(npstr, 1+XfOrM177_COUNT)));
#     define XfOrM183_COUNT (2+XfOrM177_COUNT)
#     define SETUP_XfOrM183(x) SETUP(XfOrM183_COUNT)
      npstr = NULLED_OUT ; 
      lstr = NULLED_OUT ; 
      npstr = FUNCCALL(SETUP_XfOrM183(_), scheme_make_provided_string (pair , 2 , & nplen ) ); 
      lstr = FUNCCALL_AGAIN(scheme_make_provided_string (argv [1 ] , 2 , & llen ) ); 
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: non-pair found in list: %t in %t" , "assv" , npstr , nplen , lstr , llen ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    if ((scheme_eqv (argv [0 ] , (((Scheme_Simple_Object * ) (pair ) ) -> u . pair_val . car ) ) ) ) {
      RET_VALUE_START ((pair ) ) RET_VALUE_END ; 
    }
    list = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . cdr ) ; 
    if (((Scheme_Type ) (((((long ) (list ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (list ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#     define XfOrM178_COUNT (0+XfOrM177_COUNT)
#     define SETUP_XfOrM178(x) SETUP_XfOrM177(x)
      pair = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . car ) ; 
      if (((Scheme_Type ) (((((long ) (pair ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (pair ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#       define XfOrM179_COUNT (0+XfOrM178_COUNT)
#       define SETUP_XfOrM179(x) SETUP_XfOrM178(x)
        if ((scheme_eqv (argv [0 ] , (((Scheme_Simple_Object * ) (pair ) ) -> u . pair_val . car ) ) ) )
          RET_VALUE_START (pair ) RET_VALUE_END ; 
        list = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . cdr ) ; 
        if (((list ) == (turtle ) ) )
          break ; 
        turtle = (((Scheme_Simple_Object * ) (turtle ) ) -> u . pair_val . cdr ) ; 
        {
#         define XfOrM180_COUNT (0+XfOrM179_COUNT)
#         define SETUP_XfOrM180(x) SETUP_XfOrM179(x)
          if ((scheme_fuel_counter ) <= 0 ) {
#           define XfOrM181_COUNT (0+XfOrM180_COUNT)
#           define SETUP_XfOrM181(x) SETUP_XfOrM180(x)
            FUNCCALL(SETUP_XfOrM181(_), scheme_out_of_fuel () ); 
          }
        }
        ; 
      }
    }
  }
  if (! ((list ) == (scheme_null ) ) ) {
#   define XfOrM169_COUNT (0+XfOrM168_COUNT)
#   define SETUP_XfOrM169(x) SETUP_XfOrM168(x)
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: not a proper list: %V" , "assv" , argv [1 ] ) ); 
  }
  RET_VALUE_START ((scheme_false ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * assq (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * pair , * list , * turtle ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(list, 0), PUSH(pair, 1), PUSH(argv, 2), PUSH(turtle, 3)));
# define XfOrM184_COUNT (4)
# define SETUP_XfOrM184(x) SETUP(XfOrM184_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  pair = NULLED_OUT ; 
  list = NULLED_OUT ; 
  turtle = NULLED_OUT ; 
  list = turtle = argv [1 ] ; 
  while (((Scheme_Type ) (((((long ) (list ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (list ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#   define XfOrM193_COUNT (0+XfOrM184_COUNT)
#   define SETUP_XfOrM193(x) SETUP_XfOrM184(x)
    pair = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . car ) ; 
    if (! ((Scheme_Type ) (((((long ) (pair ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (pair ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
      char * npstr , * lstr ; 
      int nplen , llen ; 
      BLOCK_SETUP((PUSH(lstr, 0+XfOrM193_COUNT), PUSH(npstr, 1+XfOrM193_COUNT)));
#     define XfOrM199_COUNT (2+XfOrM193_COUNT)
#     define SETUP_XfOrM199(x) SETUP(XfOrM199_COUNT)
      npstr = NULLED_OUT ; 
      lstr = NULLED_OUT ; 
      npstr = FUNCCALL(SETUP_XfOrM199(_), scheme_make_provided_string (pair , 2 , & nplen ) ); 
      lstr = FUNCCALL_AGAIN(scheme_make_provided_string (argv [1 ] , 2 , & llen ) ); 
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: non-pair found in list: %t in %t" , "assq" , npstr , nplen , lstr , llen ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    if (((argv [0 ] ) == ((((Scheme_Simple_Object * ) (pair ) ) -> u . pair_val . car ) ) ) ) {
      RET_VALUE_START ((pair ) ) RET_VALUE_END ; 
    }
    list = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . cdr ) ; 
    if (((Scheme_Type ) (((((long ) (list ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (list ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#     define XfOrM194_COUNT (0+XfOrM193_COUNT)
#     define SETUP_XfOrM194(x) SETUP_XfOrM193(x)
      pair = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . car ) ; 
      if (((Scheme_Type ) (((((long ) (pair ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (pair ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#       define XfOrM195_COUNT (0+XfOrM194_COUNT)
#       define SETUP_XfOrM195(x) SETUP_XfOrM194(x)
        if (((argv [0 ] ) == ((((Scheme_Simple_Object * ) (pair ) ) -> u . pair_val . car ) ) ) )
          RET_VALUE_START (pair ) RET_VALUE_END ; 
        list = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . cdr ) ; 
        if (((list ) == (turtle ) ) )
          break ; 
        turtle = (((Scheme_Simple_Object * ) (turtle ) ) -> u . pair_val . cdr ) ; 
        {
#         define XfOrM196_COUNT (0+XfOrM195_COUNT)
#         define SETUP_XfOrM196(x) SETUP_XfOrM195(x)
          if ((scheme_fuel_counter ) <= 0 ) {
#           define XfOrM197_COUNT (0+XfOrM196_COUNT)
#           define SETUP_XfOrM197(x) SETUP_XfOrM196(x)
            FUNCCALL(SETUP_XfOrM197(_), scheme_out_of_fuel () ); 
          }
        }
        ; 
      }
    }
  }
  if (! ((list ) == (scheme_null ) ) ) {
#   define XfOrM185_COUNT (0+XfOrM184_COUNT)
#   define SETUP_XfOrM185(x) SETUP_XfOrM184(x)
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: not a proper list: %V" , "assq" , argv [1 ] ) ); 
  }
  RET_VALUE_START ((scheme_false ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * assoc (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * pair , * list , * turtle ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(list, 0), PUSH(pair, 1), PUSH(argv, 2), PUSH(turtle, 3)));
# define XfOrM200_COUNT (4)
# define SETUP_XfOrM200(x) SETUP(XfOrM200_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  pair = NULLED_OUT ; 
  list = NULLED_OUT ; 
  turtle = NULLED_OUT ; 
  list = turtle = argv [1 ] ; 
  while (((Scheme_Type ) (((((long ) (list ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (list ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#   define XfOrM209_COUNT (0+XfOrM200_COUNT)
#   define SETUP_XfOrM209(x) SETUP_XfOrM200(x)
    pair = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . car ) ; 
    if (! ((Scheme_Type ) (((((long ) (pair ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (pair ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
      char * npstr , * lstr ; 
      int nplen , llen ; 
      BLOCK_SETUP((PUSH(lstr, 0+XfOrM209_COUNT), PUSH(npstr, 1+XfOrM209_COUNT)));
#     define XfOrM215_COUNT (2+XfOrM209_COUNT)
#     define SETUP_XfOrM215(x) SETUP(XfOrM215_COUNT)
      npstr = NULLED_OUT ; 
      lstr = NULLED_OUT ; 
      npstr = FUNCCALL(SETUP_XfOrM215(_), scheme_make_provided_string (pair , 2 , & nplen ) ); 
      lstr = FUNCCALL_AGAIN(scheme_make_provided_string (argv [1 ] , 2 , & llen ) ); 
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: non-pair found in list: %t in %t" , "assoc" , npstr , nplen , lstr , llen ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    if (FUNCCALL(SETUP_XfOrM209(_), scheme_equal (argv [0 ] , (((Scheme_Simple_Object * ) (pair ) ) -> u . pair_val . car ) ) )) {
      RET_VALUE_START ((pair ) ) RET_VALUE_END ; 
    }
    list = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . cdr ) ; 
    if (((Scheme_Type ) (((((long ) (list ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (list ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#     define XfOrM210_COUNT (0+XfOrM209_COUNT)
#     define SETUP_XfOrM210(x) SETUP_XfOrM209(x)
      pair = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . car ) ; 
      if (((Scheme_Type ) (((((long ) (pair ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (pair ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#       define XfOrM211_COUNT (0+XfOrM210_COUNT)
#       define SETUP_XfOrM211(x) SETUP_XfOrM210(x)
        if (FUNCCALL(SETUP_XfOrM211(_), scheme_equal (argv [0 ] , (((Scheme_Simple_Object * ) (pair ) ) -> u . pair_val . car ) ) ))
          RET_VALUE_START (pair ) RET_VALUE_END ; 
        list = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . cdr ) ; 
        if (((list ) == (turtle ) ) )
          break ; 
        turtle = (((Scheme_Simple_Object * ) (turtle ) ) -> u . pair_val . cdr ) ; 
        {
#         define XfOrM212_COUNT (0+XfOrM211_COUNT)
#         define SETUP_XfOrM212(x) SETUP_XfOrM211(x)
          if ((scheme_fuel_counter ) <= 0 ) {
#           define XfOrM213_COUNT (0+XfOrM212_COUNT)
#           define SETUP_XfOrM213(x) SETUP_XfOrM212(x)
            FUNCCALL(SETUP_XfOrM213(_), scheme_out_of_fuel () ); 
          }
        }
        ; 
      }
    }
  }
  if (! ((list ) == (scheme_null ) ) ) {
#   define XfOrM201_COUNT (0+XfOrM200_COUNT)
#   define SETUP_XfOrM201(x) SETUP_XfOrM200(x)
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: not a proper list: %V" , "assoc" , argv [1 ] ) ); 
  }
  RET_VALUE_START ((scheme_false ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_checked_cddr (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) )
    scheme_wrong_type ("cddr" , "cddr" "able value" , 0 , argc , argv ) ; 
  return (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ; 
}
Scheme_Object * scheme_checked_cadr (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) )
    scheme_wrong_type ("cadr" , "cadr" "able value" , 0 , argc , argv ) ; 
  return (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ; 
}
Scheme_Object * scheme_checked_cdar (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) )
    scheme_wrong_type ("cdar" , "cdar" "able value" , 0 , argc , argv ) ; 
  return (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ; 
}
Scheme_Object * scheme_checked_caar (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) )
    scheme_wrong_type ("caar" , "caar" "able value" , 0 , argc , argv ) ; 
  return (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ; 
}
static Scheme_Object * cdddr_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) )
    scheme_wrong_type ("cdddr" , "cdddr" "able value" , 0 , argc , argv ) ; 
  return (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ; 
}
static Scheme_Object * caddr_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) )
    scheme_wrong_type ("caddr" , "caddr" "able value" , 0 , argc , argv ) ; 
  return (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ; 
}
static Scheme_Object * cdadr_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) )
    scheme_wrong_type ("cdadr" , "cdadr" "able value" , 0 , argc , argv ) ; 
  return (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ; 
}
static Scheme_Object * cddar_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) )
    scheme_wrong_type ("cddar" , "cddar" "able value" , 0 , argc , argv ) ; 
  return (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ; 
}
static Scheme_Object * cdaar_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) )
    scheme_wrong_type ("cdaar" , "cdaar" "able value" , 0 , argc , argv ) ; 
  return (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ; 
}
static Scheme_Object * cadar_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) )
    scheme_wrong_type ("cadar" , "cadar" "able value" , 0 , argc , argv ) ; 
  return (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ; 
}
static Scheme_Object * caadr_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) )
    scheme_wrong_type ("caadr" , "caadr" "able value" , 0 , argc , argv ) ; 
  return (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ; 
}
static Scheme_Object * caaar_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) )
    scheme_wrong_type ("caaar" , "caaar" "able value" , 0 , argc , argv ) ; 
  return (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ; 
}
static Scheme_Object * cddddr_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) )
    scheme_wrong_type ("cddddr" , "cddddr" "able value" , 0 , argc , argv ) ; 
  return (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ; 
}
static Scheme_Object * cadddr_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) )
    scheme_wrong_type ("cadddr" , "cadddr" "able value" , 0 , argc , argv ) ; 
  return (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ; 
}
static Scheme_Object * cdaddr_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) )
    scheme_wrong_type ("cdaddr" , "cdaddr" "able value" , 0 , argc , argv ) ; 
  return (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ; 
}
static Scheme_Object * cddadr_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) )
    scheme_wrong_type ("cddadr" , "cddadr" "able value" , 0 , argc , argv ) ; 
  return (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ; 
}
static Scheme_Object * cdddar_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) )
    scheme_wrong_type ("cdddar" , "cdddar" "able value" , 0 , argc , argv ) ; 
  return (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ; 
}
static Scheme_Object * caaddr_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) )
    scheme_wrong_type ("caaddr" , "caaddr" "able value" , 0 , argc , argv ) ; 
  return (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ; 
}
static Scheme_Object * cadadr_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) )
    scheme_wrong_type ("cadadr" , "cadadr" "able value" , 0 , argc , argv ) ; 
  return (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ; 
}
static Scheme_Object * caddar_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) )
    scheme_wrong_type ("caddar" , "caddar" "able value" , 0 , argc , argv ) ; 
  return (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ; 
}
static Scheme_Object * cdaadr_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) )
    scheme_wrong_type ("cdaadr" , "cdaadr" "able value" , 0 , argc , argv ) ; 
  return (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ; 
}
static Scheme_Object * cdadar_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) )
    scheme_wrong_type ("cdadar" , "cdadar" "able value" , 0 , argc , argv ) ; 
  return (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ; 
}
static Scheme_Object * cddaar_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) )
    scheme_wrong_type ("cddaar" , "cddaar" "able value" , 0 , argc , argv ) ; 
  return (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ; 
}
static Scheme_Object * cdaaar_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) )
    scheme_wrong_type ("cdaaar" , "cdaaar" "able value" , 0 , argc , argv ) ; 
  return (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ; 
}
static Scheme_Object * cadaar_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) )
    scheme_wrong_type ("cadaar" , "cadaar" "able value" , 0 , argc , argv ) ; 
  return (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ; 
}
static Scheme_Object * caadar_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) )
    scheme_wrong_type ("caadar" , "caadar" "able value" , 0 , argc , argv ) ; 
  return (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ; 
}
static Scheme_Object * caaadr_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) )
    scheme_wrong_type ("caaadr" , "caaadr" "able value" , 0 , argc , argv ) ; 
  return (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ; 
}
static Scheme_Object * caaaar_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) )
    scheme_wrong_type ("caaaar" , "caaaar" "able value" , 0 , argc , argv ) ; 
  return (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ; 
}
Scheme_Object * scheme_box (Scheme_Object * v ) {
  Scheme_Object * obj ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(obj, 0), PUSH(v, 1)));
# define XfOrM244_COUNT (2)
# define SETUP_XfOrM244(x) SETUP(XfOrM244_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  obj = NULLED_OUT ; 
  obj = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM244(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  obj -> type = scheme_box_type ; 
  (((Scheme_Small_Object * ) (obj ) ) -> u . ptr_val ) = v ; 
  RET_VALUE_START (obj ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_unbox (Scheme_Object * obj ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(obj, 0)));
# define XfOrM245_COUNT (1)
# define SETUP_XfOrM245(x) SETUP(XfOrM245_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) )
    FUNCCALL(SETUP_XfOrM245(_), scheme_wrong_type ("unbox" , "box" , 0 , 1 , & obj ) ); 
  RET_VALUE_START ((Scheme_Object * ) (((Scheme_Small_Object * ) (obj ) ) -> u . ptr_val ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_set_box (Scheme_Object * b , Scheme_Object * v ) {
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(b, 1)));
# define XfOrM246_COUNT (2)
# define SETUP_XfOrM246(x) SETUP(XfOrM246_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! (((Scheme_Type ) (((((long ) (b ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (b ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) && (! (((Scheme_Inclhash_Object * ) (b ) ) -> so . keyex & 0x1 ) ) ) )
    FUNCCALL(SETUP_XfOrM246(_), scheme_wrong_type ("set-box!" , "mutable box" , 0 , 1 , & b ) ); 
  (((Scheme_Small_Object * ) (b ) ) -> u . ptr_val ) = v ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * box (int c , Scheme_Object * p [] ) {
  /* No conversion */
  return scheme_box (p [0 ] ) ; 
}
static Scheme_Object * immutable_box (int c , Scheme_Object * p [] ) {
  Scheme_Object * obj ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(obj, 0)));
# define XfOrM248_COUNT (1)
# define SETUP_XfOrM248(x) SETUP(XfOrM248_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  obj = NULLED_OUT ; 
  obj = FUNCCALL(SETUP_XfOrM248(_), scheme_box (p [0 ] ) ); 
  ((((Scheme_Inclhash_Object * ) (obj ) ) -> so . keyex |= 0x1 ) ) ; 
  RET_VALUE_START (obj ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * box_p (int c , Scheme_Object * p [] ) {
  /* No conversion */
  return ((Scheme_Type ) (((((long ) (p [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ? scheme_true : scheme_false ; 
}
static Scheme_Object * unbox (int c , Scheme_Object * p [] ) {
  /* No conversion */
  return scheme_unbox (p [0 ] ) ; 
}
static Scheme_Object * set_box (int c , Scheme_Object * p [] ) {
  /* No conversion */
  scheme_set_box (p [0 ] , p [1 ] ) ; 
  return scheme_void ; 
}
static int compare_equal (void * v1 , void * v2 ) {
  /* No conversion */
  return ! scheme_equal ((Scheme_Object * ) v1 , (Scheme_Object * ) v2 ) ; 
}
static void make_hash_indices_for_equal (void * v , long * _stk_h1 , long * _stk_h2 ) {
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(_stk_h2, 1)));
# define XfOrM253_COUNT (2)
# define SETUP_XfOrM253(x) SETUP(XfOrM253_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  * _stk_h1 = FUNCCALL(SETUP_XfOrM253(_), scheme_equal_hash_key ((Scheme_Object * ) v ) ); 
  * _stk_h2 = FUNCCALL_EMPTY(scheme_equal_hash_key2 ((Scheme_Object * ) v ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void check_hash_table_flags (const char * name , int i , int argc , Scheme_Object * * argv , int * flags ) {
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(flags, 1), PUSH(name, 2)));
# define XfOrM254_COUNT (3)
# define SETUP_XfOrM254(x) SETUP(XfOrM254_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  for (; i < argc ; i ++ ) {
    int j ; 
#   define XfOrM257_COUNT (0+XfOrM254_COUNT)
#   define SETUP_XfOrM257(x) SETUP_XfOrM254(x)
    if (((argv [i ] ) == (weak_symbol ) ) )
      j = 0 ; 
    else if (((argv [i ] ) == (equal_symbol ) ) )
      j = 1 ; 
    else {
#     define XfOrM258_COUNT (0+XfOrM257_COUNT)
#     define SETUP_XfOrM258(x) SETUP_XfOrM257(x)
      FUNCCALL_EMPTY(scheme_wrong_type (name , "'weak or 'equal" , i , argc , argv ) ); 
      RET_NOTHING ; 
    }
    if (flags [j ] )
      FUNCCALL(SETUP_XfOrM257(_), scheme_arg_mismatch (name , "redundant flag: " , argv [i ] ) ); 
    flags [j ] = 1 ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_hash_table (int argc , Scheme_Object * argv [] ) {
  int flags [2 ] = {
    0 , 0 }
  ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(2);
# define XfOrM259_COUNT (0)
# define SETUP_XfOrM259(x) SETUP(XfOrM259_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  FUNCCALL(SETUP_XfOrM259(_), check_hash_table_flags ("make-hash-table" , 0 , argc , argv , flags ) ); 
  if (flags [0 ] ) {
    Scheme_Bucket_Table * t ; 
    BLOCK_SETUP((PUSH(t, 0+XfOrM259_COUNT)));
#   define XfOrM261_COUNT (1+XfOrM259_COUNT)
#   define SETUP_XfOrM261(x) SETUP(XfOrM261_COUNT)
    t = NULLED_OUT ; 
    t = FUNCCALL(SETUP_XfOrM261(_), scheme_make_bucket_table (20 , SCHEME_hash_weak_ptr ) ); 
    if (flags [1 ] ) {
      Scheme_Object * sema ; 
      BLOCK_SETUP((PUSH(sema, 0+XfOrM261_COUNT)));
#     define XfOrM262_COUNT (1+XfOrM261_COUNT)
#     define SETUP_XfOrM262(x) SETUP(XfOrM262_COUNT)
      sema = NULLED_OUT ; 
      sema = FUNCCALL(SETUP_XfOrM262(_), scheme_make_sema (1 ) ); 
      t -> mutex = sema ; 
      t -> compare = compare_equal ; 
      t -> make_hash_indices = make_hash_indices_for_equal ; 
    }
    RET_VALUE_START ((Scheme_Object * ) t ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM260_COUNT (0+XfOrM259_COUNT)
#   define SETUP_XfOrM260(x) SETUP_XfOrM259(x)
    if (flags [1 ] )
      RET_VALUE_START ((Scheme_Object * ) FUNCCALL_EMPTY(scheme_make_hash_table_equal () )) RET_VALUE_END ; 
    else RET_VALUE_START ((Scheme_Object * ) FUNCCALL_EMPTY(scheme_make_hash_table (SCHEME_hash_ptr ) )) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_immutable_hash_table (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * l = argv [0 ] , * a ; 
  Scheme_Hash_Table * ht ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(ht, 0), PUSH(argv, 1), PUSH(a, 2), PUSH(l, 3)));
# define XfOrM263_COUNT (4)
# define SETUP_XfOrM263(x) SETUP(XfOrM263_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a = NULLED_OUT ; 
  ht = NULLED_OUT ; 
  if (FUNCCALL(SETUP_XfOrM263(_), scheme_proper_list_length (l ) )>= 0 ) {
    for (; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
      a = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
      if (! ((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
        break ; 
    }
  }
  if (! ((l ) == (scheme_null ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("make-immutable-hash-table" , "list of pairs" , 0 , argc , argv ) ); 
  if (argc > 1 ) {
#   define XfOrM266_COUNT (0+XfOrM263_COUNT)
#   define SETUP_XfOrM266(x) SETUP_XfOrM263(x)
    if (! ((equal_symbol ) == (argv [1 ] ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("make-immutable-hash-table" , "'equal" , 1 , argc , argv ) ); 
    ht = FUNCCALL(SETUP_XfOrM266(_), scheme_make_hash_table_equal () ); 
  }
  else ht = FUNCCALL(SETUP_XfOrM263(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  for (l = argv [0 ] ; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#   define XfOrM265_COUNT (0+XfOrM263_COUNT)
#   define SETUP_XfOrM265(x) SETUP_XfOrM263(x)
    a = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
    FUNCCALL(SETUP_XfOrM265(_), scheme_hash_set (ht , (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) , (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) ) ); 
  }
  ((((Scheme_Inclhash_Object * ) ((Scheme_Object * ) ht ) ) -> so . keyex |= 0x1 ) ) ; 
  RET_VALUE_START ((Scheme_Object * ) ht ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Hash_Table * scheme_make_hash_table_equal () {
  Scheme_Hash_Table * t ; 
  Scheme_Object * sema ; 
  DECL_RET_SAVE (Scheme_Hash_Table * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(t, 0), PUSH(sema, 1)));
# define XfOrM270_COUNT (2)
# define SETUP_XfOrM270(x) SETUP(XfOrM270_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  t = NULLED_OUT ; 
  sema = NULLED_OUT ; 
  t = FUNCCALL(SETUP_XfOrM270(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  sema = FUNCCALL_AGAIN(scheme_make_sema (1 ) ); 
  t -> mutex = sema ; 
  t -> compare = compare_equal ; 
  t -> make_hash_indices = make_hash_indices_for_equal ; 
  RET_VALUE_START (t ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * hash_table_count (int argc , Scheme_Object * argv [] ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM271_COUNT (1)
# define SETUP_XfOrM271(x) SETUP(XfOrM271_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) ) {
    Scheme_Hash_Table * t = (Scheme_Hash_Table * ) argv [0 ] ; 
    RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (t -> count ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
  }
  else if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_bucket_table_type ) ) ) {
    Scheme_Bucket_Table * t = (Scheme_Bucket_Table * ) argv [0 ] ; 
    int count = 0 , weak , i ; 
    Scheme_Bucket * * buckets , * bucket ; 
    const char * key ; 
    BLOCK_SETUP((PUSH(bucket, 0+XfOrM271_COUNT), PUSH(t, 1+XfOrM271_COUNT), PUSH(key, 2+XfOrM271_COUNT), PUSH(buckets, 3+XfOrM271_COUNT)));
#   define XfOrM273_COUNT (4+XfOrM271_COUNT)
#   define SETUP_XfOrM273(x) SETUP(XfOrM273_COUNT)
    buckets = NULLED_OUT ; 
    bucket = NULLED_OUT ; 
    key = NULLED_OUT ; 
    buckets = t -> buckets ; 
    weak = t -> weak ; 
    for (i = t -> size ; i -- ; ) {
#     define XfOrM280_COUNT (0+XfOrM273_COUNT)
#     define SETUP_XfOrM280(x) SETUP_XfOrM273(x)
      bucket = buckets [i ] ; 
      if (bucket ) {
        if (weak ) {
          key = (const char * ) (((Scheme_Small_Object * ) (bucket -> key ) ) -> u . ptr_val ) ; 
        }
        else {
          key = bucket -> key ; 
        }
        if (key )
          count ++ ; 
      }
      {
#       define XfOrM281_COUNT (0+XfOrM280_COUNT)
#       define SETUP_XfOrM281(x) SETUP_XfOrM280(x)
        if ((scheme_fuel_counter ) <= 0 ) {
#         define XfOrM282_COUNT (0+XfOrM281_COUNT)
#         define SETUP_XfOrM282(x) SETUP_XfOrM281(x)
          FUNCCALL(SETUP_XfOrM282(_), scheme_out_of_fuel () ); 
        }
      }
      ; 
    }
    RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (count ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM272_COUNT (0+XfOrM271_COUNT)
#   define SETUP_XfOrM272(x) SETUP_XfOrM271(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("hash-table-count" , "hash-table" , 0 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * hash_table_copy (int argc , Scheme_Object * argv [] ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM287_COUNT (1)
# define SETUP_XfOrM287(x) SETUP(XfOrM287_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) ) {
    Scheme_Object * o ; 
    Scheme_Hash_Table * t = (Scheme_Hash_Table * ) argv [0 ] ; 
    BLOCK_SETUP((PUSH(t, 0+XfOrM287_COUNT), PUSH(o, 1+XfOrM287_COUNT)));
#   define XfOrM290_COUNT (2+XfOrM287_COUNT)
#   define SETUP_XfOrM290(x) SETUP(XfOrM290_COUNT)
    o = NULLED_OUT ; 
    if (t -> mutex )
      FUNCCALL(SETUP_XfOrM290(_), scheme_wait_sema (t -> mutex , 0 ) ); 
    o = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM290(_), scheme_clone_hash_table (t ) ); 
    if (t -> mutex )
      FUNCCALL(SETUP_XfOrM290(_), scheme_post_sema (t -> mutex ) ); 
    RET_VALUE_START (o ) RET_VALUE_END ; 
  }
  else if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_bucket_table_type ) ) ) {
    Scheme_Object * o ; 
    Scheme_Bucket_Table * t = (Scheme_Bucket_Table * ) argv [0 ] ; 
    BLOCK_SETUP((PUSH(t, 0+XfOrM287_COUNT), PUSH(o, 1+XfOrM287_COUNT)));
#   define XfOrM289_COUNT (2+XfOrM287_COUNT)
#   define SETUP_XfOrM289(x) SETUP(XfOrM289_COUNT)
    o = NULLED_OUT ; 
    if (t -> mutex )
      FUNCCALL(SETUP_XfOrM289(_), scheme_wait_sema (t -> mutex , 0 ) ); 
    o = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM289(_), scheme_clone_bucket_table (t ) ); 
    if (t -> mutex )
      FUNCCALL(SETUP_XfOrM289(_), scheme_post_sema (t -> mutex ) ); 
    RET_VALUE_START (o ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM288_COUNT (0+XfOrM287_COUNT)
#   define SETUP_XfOrM288(x) SETUP_XfOrM287(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("hash-table-copy" , "hash-table" , 0 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * hash_table_p (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * o = argv [0 ] ; 
  int flags [2 ] = {
    0 , 0 }
  ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(o, 0)));
# define XfOrM291_COUNT (1)
# define SETUP_XfOrM291(x) SETUP(XfOrM291_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM291(_), check_hash_table_flags ("hash-table?" , 1 , argc , argv , flags ) ); 
  if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) ) {
    if (flags [0 ] )
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    if (flags [1 ] && (((Scheme_Hash_Table * ) o ) -> compare != compare_equal ) )
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
  }
  else if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_bucket_table_type ) ) ) {
    if (flags [1 ] && (((Scheme_Bucket_Table * ) o ) -> compare != compare_equal ) )
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_is_hash_table_equal (Scheme_Object * o ) {
  /* No conversion */
  return (((Scheme_Hash_Table * ) o ) -> compare == compare_equal ) ; 
}
static Scheme_Object * hash_table_put (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * v = argv [0 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(argv, 1)));
# define XfOrM295_COUNT (2)
# define SETUP_XfOrM295(x) SETUP(XfOrM295_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_bucket_table_type ) ) ) {
    Scheme_Bucket_Table * t = (Scheme_Bucket_Table * ) v ; 
    BLOCK_SETUP((PUSH(t, 0+XfOrM295_COUNT)));
#   define XfOrM299_COUNT (1+XfOrM295_COUNT)
#   define SETUP_XfOrM299(x) SETUP(XfOrM299_COUNT)
    if (t -> mutex )
      FUNCCALL(SETUP_XfOrM299(_), scheme_wait_sema (t -> mutex , 0 ) ); 
    FUNCCALL(SETUP_XfOrM299(_), scheme_add_to_table (t , (char * ) argv [1 ] , (void * ) argv [2 ] , 0 ) ); 
    if (t -> mutex )
      FUNCCALL(SETUP_XfOrM299(_), scheme_post_sema (t -> mutex ) ); 
  }
  else if (! ((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) || ! (! (((Scheme_Inclhash_Object * ) (v ) ) -> so . keyex & 0x1 ) ) ) {
#   define XfOrM298_COUNT (0+XfOrM295_COUNT)
#   define SETUP_XfOrM298(x) SETUP_XfOrM295(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("hash-table-put!" , "mutable hash-table" , 0 , argc , argv ) ); 
  }
  else if (((Scheme_Hash_Table * ) v ) -> mutex ) {
    Scheme_Hash_Table * t = (Scheme_Hash_Table * ) v ; 
    BLOCK_SETUP((PUSH(t, 0+XfOrM295_COUNT)));
#   define XfOrM297_COUNT (1+XfOrM295_COUNT)
#   define SETUP_XfOrM297(x) SETUP(XfOrM297_COUNT)
    FUNCCALL(SETUP_XfOrM297(_), scheme_wait_sema (t -> mutex , 0 ) ); 
    FUNCCALL(SETUP_XfOrM297(_), scheme_hash_set (t , argv [1 ] , argv [2 ] ) ); 
    FUNCCALL_AGAIN(scheme_post_sema (t -> mutex ) ); 
  }
  else {
#   define XfOrM296_COUNT (0+XfOrM295_COUNT)
#   define SETUP_XfOrM296(x) SETUP_XfOrM295(x)
    FUNCCALL_EMPTY(scheme_hash_set ((Scheme_Hash_Table * ) v , argv [1 ] , argv [2 ] ) ); 
  }
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * hash_table_get (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * v ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(argv, 1)));
# define XfOrM300_COUNT (2)
# define SETUP_XfOrM300(x) SETUP(XfOrM300_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  v = NULLED_OUT ; 
  v = argv [0 ] ; 
  if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_bucket_table_type ) ) ) {
    Scheme_Bucket_Table * t = (Scheme_Bucket_Table * ) v ; 
    BLOCK_SETUP((PUSH(t, 0+XfOrM300_COUNT)));
#   define XfOrM306_COUNT (1+XfOrM300_COUNT)
#   define SETUP_XfOrM306(x) SETUP(XfOrM306_COUNT)
    if (t -> mutex )
      FUNCCALL(SETUP_XfOrM306(_), scheme_wait_sema (t -> mutex , 0 ) ); 
    v = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM306(_), scheme_lookup_in_table (t , (char * ) argv [1 ] ) ); 
    if (t -> mutex )
      FUNCCALL(SETUP_XfOrM306(_), scheme_post_sema (t -> mutex ) ); 
  }
  else if (! ((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) ) {
#   define XfOrM305_COUNT (0+XfOrM300_COUNT)
#   define SETUP_XfOrM305(x) SETUP_XfOrM300(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("hash-table-get" , "hash-table" , 0 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  else if (((Scheme_Hash_Table * ) v ) -> mutex ) {
    Scheme_Hash_Table * t = (Scheme_Hash_Table * ) v ; 
    BLOCK_SETUP((PUSH(t, 0+XfOrM300_COUNT)));
#   define XfOrM304_COUNT (1+XfOrM300_COUNT)
#   define SETUP_XfOrM304(x) SETUP(XfOrM304_COUNT)
    FUNCCALL(SETUP_XfOrM304(_), scheme_wait_sema (t -> mutex , 0 ) ); 
    v = FUNCCALL(SETUP_XfOrM304(_), scheme_hash_get (t , argv [1 ] ) ); 
    FUNCCALL_AGAIN(scheme_post_sema (t -> mutex ) ); 
  }
  else {
#   define XfOrM303_COUNT (0+XfOrM300_COUNT)
#   define SETUP_XfOrM303(x) SETUP_XfOrM300(x)
    v = FUNCCALL(SETUP_XfOrM303(_), scheme_hash_get ((Scheme_Hash_Table * ) v , argv [1 ] ) ); 
  }
  if (v )
    RET_VALUE_START (v ) RET_VALUE_END ; 
  else if (argc == 3 ) {
#   define XfOrM302_COUNT (0+XfOrM300_COUNT)
#   define SETUP_XfOrM302(x) SETUP_XfOrM300(x)
    v = argv [2 ] ; 
    if ((! (((long ) (v ) ) & 0x1 ) && ((((v ) -> type ) >= scheme_prim_type ) && (((v ) -> type ) <= scheme_native_closure_type ) ) ) )
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_tail_apply (v , 0 , ((void * ) 0 ) ) )) RET_VALUE_EMPTY_END ; 
    else RET_VALUE_START (v ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM301_COUNT (0+XfOrM300_COUNT)
#   define SETUP_XfOrM301(x) SETUP_XfOrM300(x)
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "hash-table-get: no value found for key: %V" , argv [1 ] ) ); 
    RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * hash_table_remove (int argc , Scheme_Object * argv [] ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM307_COUNT (1)
# define SETUP_XfOrM307(x) SETUP(XfOrM307_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) && (! (((Scheme_Inclhash_Object * ) (argv [0 ] ) ) -> so . keyex & 0x1 ) ) ) && ! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_bucket_table_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("hash-table-remove!" , "mutable hash-table" , 0 , argc , argv ) ); 
  if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_bucket_table_type ) ) ) {
    Scheme_Bucket * b ; 
    Scheme_Bucket_Table * t = (Scheme_Bucket_Table * ) argv [0 ] ; 
    BLOCK_SETUP((PUSH(t, 0+XfOrM307_COUNT), PUSH(b, 1+XfOrM307_COUNT)));
#   define XfOrM309_COUNT (2+XfOrM307_COUNT)
#   define SETUP_XfOrM309(x) SETUP(XfOrM309_COUNT)
    b = NULLED_OUT ; 
    if (t -> mutex )
      FUNCCALL(SETUP_XfOrM309(_), scheme_wait_sema (t -> mutex , 0 ) ); 
    b = FUNCCALL(SETUP_XfOrM309(_), scheme_bucket_or_null_from_table ((Scheme_Bucket_Table * ) argv [0 ] , (char * ) argv [1 ] , 0 ) ); 
    if (b ) {
      (((Scheme_Small_Object * ) (b -> key ) ) -> u . ptr_val ) = ((void * ) 0 ) ; 
      b -> val = ((void * ) 0 ) ; 
    }
    if (t -> mutex )
      FUNCCALL(SETUP_XfOrM309(_), scheme_post_sema (t -> mutex ) ); 
  }
  else {
    Scheme_Hash_Table * t = (Scheme_Hash_Table * ) argv [0 ] ; 
    BLOCK_SETUP((PUSH(t, 0+XfOrM307_COUNT)));
#   define XfOrM308_COUNT (1+XfOrM307_COUNT)
#   define SETUP_XfOrM308(x) SETUP(XfOrM308_COUNT)
    if (t -> mutex )
      FUNCCALL(SETUP_XfOrM308(_), scheme_wait_sema (t -> mutex , 0 ) ); 
    FUNCCALL(SETUP_XfOrM308(_), scheme_hash_set (t , argv [1 ] , ((void * ) 0 ) ) ); 
    if (t -> mutex )
      FUNCCALL_EMPTY(scheme_post_sema (t -> mutex ) ); 
  }
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_map_hash_table (int argc , Scheme_Object * argv [] , char * name , int keep ) {
  int i ; 
  Scheme_Object * f ; 
  Scheme_Object * first , * last = ((void * ) 0 ) , * v , * p [2 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(11);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(f, 1), PUSH(argv, 2), PUSH(name, 3), PUSH(last, 4), PUSH(first, 5), PUSHARRAY(p, 2, 6)));
# define XfOrM311_COUNT (9)
# define SETUP_XfOrM311(x) SETUP(XfOrM311_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  f = NULLED_OUT ; 
  first = NULLED_OUT ; 
  v = NULLED_OUT ; 
  p[0] = NULLED_OUT ; 
  p[1] = NULLED_OUT ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_bucket_table_type ) ) ) )
    FUNCCALL(SETUP_XfOrM311(_), scheme_wrong_type (name , "hash table" , 0 , argc , argv ) ); 
  FUNCCALL(SETUP_XfOrM311(_), scheme_check_proc_arity (name , 2 , 1 , argc , argv ) ); 
  f = argv [1 ] ; 
  if (keep )
    first = scheme_null ; 
  else first = scheme_void ; 
  if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_bucket_table_type ) ) ) {
    Scheme_Bucket_Table * hash ; 
    Scheme_Bucket * bucket ; 
    BLOCK_SETUP((PUSH(bucket, 0+XfOrM311_COUNT), PUSH(hash, 1+XfOrM311_COUNT)));
#   define XfOrM319_COUNT (2+XfOrM311_COUNT)
#   define SETUP_XfOrM319(x) SETUP(XfOrM319_COUNT)
    hash = NULLED_OUT ; 
    bucket = NULLED_OUT ; 
    hash = (Scheme_Bucket_Table * ) argv [0 ] ; 
    for (i = hash -> size ; i -- ; ) {
#     define XfOrM323_COUNT (0+XfOrM319_COUNT)
#     define SETUP_XfOrM323(x) SETUP_XfOrM319(x)
      bucket = hash -> buckets [i ] ; 
      if (bucket && bucket -> val && bucket -> key ) {
#       define XfOrM324_COUNT (0+XfOrM323_COUNT)
#       define SETUP_XfOrM324(x) SETUP_XfOrM323(x)
        if (hash -> weak )
          p [0 ] = (Scheme_Object * ) (((Scheme_Small_Object * ) (bucket -> key ) ) -> u . ptr_val ) ; 
        else p [0 ] = (Scheme_Object * ) bucket -> key ; 
        p [1 ] = (Scheme_Object * ) bucket -> val ; 
        if (keep ) {
#         define XfOrM325_COUNT (0+XfOrM324_COUNT)
#         define SETUP_XfOrM325(x) SETUP_XfOrM324(x)
          v = FUNCCALL(SETUP_XfOrM325(_), scheme_do_eval (f , 2 , p , 1 ) ); 
          v = FUNCCALL(SETUP_XfOrM325(_), scheme_make_pair (v , scheme_null ) ); 
          if (last )
            (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = v ; 
          else first = v ; 
          last = v ; 
        }
        else FUNCCALL(SETUP_XfOrM324(_), scheme_do_eval (f , 2 , p , - 1 ) ); 
      }
    }
  }
  else {
    Scheme_Hash_Table * hash ; 
    BLOCK_SETUP((PUSH(hash, 0+XfOrM311_COUNT)));
#   define XfOrM312_COUNT (1+XfOrM311_COUNT)
#   define SETUP_XfOrM312(x) SETUP(XfOrM312_COUNT)
    hash = NULLED_OUT ; 
    hash = (Scheme_Hash_Table * ) argv [0 ] ; 
    for (i = hash -> size ; i -- ; ) {
#     define XfOrM316_COUNT (0+XfOrM312_COUNT)
#     define SETUP_XfOrM316(x) SETUP_XfOrM312(x)
      if (hash -> vals [i ] ) {
#       define XfOrM317_COUNT (0+XfOrM316_COUNT)
#       define SETUP_XfOrM317(x) SETUP_XfOrM316(x)
        p [0 ] = hash -> keys [i ] ; 
        p [1 ] = hash -> vals [i ] ; 
        if (keep ) {
#         define XfOrM318_COUNT (0+XfOrM317_COUNT)
#         define SETUP_XfOrM318(x) SETUP_XfOrM317(x)
          v = FUNCCALL(SETUP_XfOrM318(_), scheme_do_eval (f , 2 , p , 1 ) ); 
          v = FUNCCALL(SETUP_XfOrM318(_), scheme_make_pair (v , scheme_null ) ); 
          if (last )
            (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = v ; 
          else first = v ; 
          last = v ; 
        }
        else FUNCCALL(SETUP_XfOrM317(_), scheme_do_eval (f , 2 , p , - 1 ) ); 
      }
    }
  }
  RET_VALUE_START (first ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * hash_table_map (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_map_hash_table (argc , argv , "hash-table-map" , 1 ) ; 
}
static Scheme_Object * hash_table_for_each (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_map_hash_table (argc , argv , "hash-table-for-each" , 0 ) ; 
}
static Scheme_Object * hash_table_next (const char * name , int start , int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) ) {
    Scheme_Hash_Table * hash ; 
    int i , sz ; 
    hash = (Scheme_Hash_Table * ) argv [0 ] ; 
    sz = hash -> size ; 
    if (start >= 0 ) {
      if ((start >= sz ) || ! hash -> vals [start ] )
        return ((void * ) 0 ) ; 
    }
    for (i = start + 1 ; i < sz ; i ++ ) {
      if (hash -> vals [i ] )
        return ((Scheme_Object * ) (void * ) (long ) ((((long ) (i ) ) << 1 ) | 0x1 ) ) ; 
    }
    return scheme_false ; 
  }
  else if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_bucket_table_type ) ) ) {
    Scheme_Bucket_Table * hash ; 
    Scheme_Bucket * bucket ; 
    int i , sz ; 
    hash = (Scheme_Bucket_Table * ) argv [0 ] ; 
    sz = hash -> size ; 
    if (start >= 0 ) {
      bucket = ((start < sz ) ? hash -> buckets [start ] : ((void * ) 0 ) ) ; 
      if (! bucket || ! bucket -> val || ! bucket -> key )
        return ((void * ) 0 ) ; 
    }
    for (i = start + 1 ; i < sz ; i ++ ) {
      bucket = hash -> buckets [i ] ; 
      if (bucket && bucket -> val && bucket -> key ) {
        return ((Scheme_Object * ) (void * ) (long ) ((((long ) (i ) ) << 1 ) | 0x1 ) ) ; 
      }
    }
    return scheme_false ; 
  }
  else {
    scheme_wrong_type (name , "hash table" , 0 , argc , argv ) ; 
    return ((void * ) 0 ) ; 
  }
}
static Scheme_Object * hash_table_iterate_start (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return hash_table_next ("hash-table-iterate-first" , - 1 , argc , argv ) ; 
}
static Scheme_Object * hash_table_iterate_next (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * p = argv [1 ] , * v ; 
  int pos ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(argv, 1), PUSH(p, 2)));
# define XfOrM341_COUNT (3)
# define SETUP_XfOrM341(x) SETUP(XfOrM341_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  if ((((long ) (p ) ) & 0x1 ) ) {
    pos = (((long ) (p ) ) >> 1 ) ; 
    if (pos < 0 )
      pos = 0x7FFFFFFE ; 
  }
  else {
    pos = 0x7FFFFFFE ; 
  }
  v = FUNCCALL(SETUP_XfOrM341(_), hash_table_next ("hash-table-iterate-next" , pos , argc , argv ) ); 
  if (v )
    RET_VALUE_START (v ) RET_VALUE_END ; 
  if ((((long ) (p ) ) & 0x1 ) ) {
    if ((((long ) (p ) ) >> 1 ) >= 0 )
      p = ((void * ) 0 ) ; 
  }
  else if (((Scheme_Type ) (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) {
    if (((& ((Scheme_Bignum * ) p ) -> iso ) -> so . keyex & 0x1 ) )
      p = ((void * ) 0 ) ; 
  }
  if (p )
    FUNCCALL_EMPTY(scheme_wrong_type ("hash-table-iterate-next" , "exact non-negative integer" , 1 , argc , argv ) ); 
  FUNCCALL_EMPTY(scheme_arg_mismatch ("hash-table-iterate-next" , "no element at index: " , argv [1 ] ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * hash_table_index (const char * name , int argc , Scheme_Object * argv [] , int get_val ) {
  Scheme_Object * p = argv [1 ] ; 
  int pos , sz ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(name, 1)));
# define XfOrM346_COUNT (2)
# define SETUP_XfOrM346(x) SETUP(XfOrM346_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if ((((long ) (p ) ) & 0x1 ) ) {
    pos = (((long ) (p ) ) >> 1 ) ; 
    if (pos < 0 )
      pos = 0x7FFFFFFF ; 
  }
  else {
    pos = 0x7FFFFFFF ; 
  }
  if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) ) {
    Scheme_Hash_Table * hash ; 
    hash = NULLED_OUT ; 
    hash = (Scheme_Hash_Table * ) argv [0 ] ; 
    sz = hash -> size ; 
    if (pos < sz ) {
      if (hash -> vals [pos ] ) {
        if (get_val )
          RET_VALUE_START (hash -> vals [pos ] ) RET_VALUE_END ; 
        else RET_VALUE_START (hash -> keys [pos ] ) RET_VALUE_END ; 
      }
    }
  }
  else if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_bucket_table_type ) ) ) {
    Scheme_Bucket_Table * hash ; 
    int sz ; 
    Scheme_Bucket * bucket ; 
    hash = NULLED_OUT ; 
    bucket = NULLED_OUT ; 
    hash = (Scheme_Bucket_Table * ) argv [0 ] ; 
    sz = hash -> size ; 
    if (pos < sz ) {
      bucket = hash -> buckets [pos ] ; 
      if (bucket && bucket -> val && bucket -> key ) {
        if (get_val )
          RET_VALUE_START ((Scheme_Object * ) bucket -> val ) RET_VALUE_END ; 
        else {
          if (hash -> weak )
            RET_VALUE_START ((Scheme_Object * ) (((Scheme_Small_Object * ) (bucket -> key ) ) -> u . ptr_val ) ) RET_VALUE_END ; 
          else RET_VALUE_START ((Scheme_Object * ) bucket -> key ) RET_VALUE_END ; 
        }
      }
    }
  }
  else {
#   define XfOrM348_COUNT (0+XfOrM346_COUNT)
#   define SETUP_XfOrM348(x) SETUP_XfOrM346(x)
    FUNCCALL_EMPTY(scheme_wrong_type (name , "hash table" , 0 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (((((long ) (p ) ) & 0x1 ) && ((((long ) (p ) ) >> 1 ) >= 0 ) ) || (((Scheme_Type ) (((((long ) (p ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) && ((& ((Scheme_Bignum * ) p ) -> iso ) -> so . keyex & 0x1 ) ) ) {
#   define XfOrM347_COUNT (0+XfOrM346_COUNT)
#   define SETUP_XfOrM347(x) SETUP_XfOrM346(x)
    FUNCCALL(SETUP_XfOrM347(_), scheme_arg_mismatch (name , "no element at index: " , p ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  FUNCCALL_EMPTY(scheme_wrong_type (name , "exact non-negative integer" , 1 , argc , argv ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * hash_table_iterate_value (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return hash_table_index ("hash-table-iterate-value" , argc , argv , 1 ) ; 
}
static Scheme_Object * hash_table_iterate_key (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return hash_table_index ("hash-table-iterate-key" , argc , argv , 0 ) ; 
}
static Scheme_Object * eq_hash_code (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  long v ; 
  if ((((long ) (argv [0 ] ) ) & 0x1 ) )
    return argv [0 ] ; 
  v = scheme_hash_key (argv [0 ] ) ; 
  return ((Scheme_Object * ) (void * ) (long ) ((((long ) (v ) ) << 1 ) | 0x1 ) ) ; 
}
static Scheme_Object * equal_hash_code (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  long v ; 
  if ((((long ) (argv [0 ] ) ) & 0x1 ) )
    return argv [0 ] ; 
  v = scheme_equal_hash_key (argv [0 ] ) ; 
  return ((Scheme_Object * ) (void * ) (long ) ((((long ) (v ) ) << 1 ) | 0x1 ) ) ; 
}
Scheme_Object * scheme_make_weak_box (Scheme_Object * v ) {
  /* No conversion */
  return (Scheme_Object * ) GC_malloc_weak_box (v , ((void * ) 0 ) , 0 ) ; 
}
static Scheme_Object * make_weak_box (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_make_weak_box (argv [0 ] ) ; 
}
static Scheme_Object * weak_box_value (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * o ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_weak_box_type ) ) )
    scheme_wrong_type ("weak-box-value" , "weak-box" , 0 , argc , argv ) ; 
  o = (((Scheme_Small_Object * ) (argv [0 ] ) ) -> u . ptr_val ) ; 
  if (! o )
    return scheme_false ; 
  else return o ; 
}
static Scheme_Object * weak_boxp (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_weak_box_type ) ) ? scheme_true : scheme_false ) ; 
}
Scheme_Object * scheme_make_null (void ) {
  /* No conversion */
  return scheme_null ; 
}
typedef struct Scheme_Ephemeron {
  Scheme_Object so ; 
  Scheme_Object * key , * val ; 
  struct Scheme_Ephemeron * next ; 
}
Scheme_Ephemeron ; 
Scheme_Object * scheme_make_ephemeron (Scheme_Object * key , Scheme_Object * val ) {
  /* No conversion */
  return GC_malloc_ephemeron (key , val ) ; 
}
Scheme_Object * scheme_ephemeron_value (Scheme_Object * o ) {
  /* No conversion */
  return ((Scheme_Ephemeron * ) o ) -> val ; 
}
static Scheme_Object * make_ephemeron (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return scheme_make_ephemeron (argv [0 ] , argv [1 ] ) ; 
}
static Scheme_Object * ephemeron_value (int argc , Scheme_Object * * argv ) {
  Scheme_Object * v ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(v, 0)));
# define XfOrM370_COUNT (1)
# define SETUP_XfOrM370(x) SETUP(XfOrM370_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_ephemeron_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("ephemeron-value" , "ephemeron" , 0 , argc , argv ) ); 
  v = FUNCCALL(SETUP_XfOrM370(_), scheme_ephemeron_value (argv [0 ] ) ); 
  if (! v )
    RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
  else RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * ephemeronp (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_ephemeron_type ) ) ? scheme_true : scheme_false ) ; 
}
