#include "precomp.h"
static Scheme_Object * vector_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * make_vector (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * vector (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * vector_immutable (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * vector_length (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * vector_to_list (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * list_to_vector (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * vector_fill (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * vector_to_immutable (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * vector_to_values (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * zero_length_vector ; 
/* this far 48 */
void scheme_init_vector (Scheme_Env * env ) {
  Scheme_Object * p ; 
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
  FUNCCALL(SETUP_XfOrM1(_), scheme_register_static ((void * ) & zero_length_vector , sizeof (zero_length_vector ) ) ); 
  zero_length_vector = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM1(_), GC_malloc_one_tagged (sizeof (Scheme_Vector ) - sizeof (Scheme_Object * ) ) ); 
  zero_length_vector -> type = scheme_vector_type ; 
  (((Scheme_Vector * ) (zero_length_vector ) ) -> size ) = 0 ; 
  p = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (vector_p , "vector?" , 1 , 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 16384 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("vector?" , p , env ) ); 
  (__funcarg12 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (make_vector , "make-vector" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-vector" , __funcarg12 , env ) )) ; 
  (__funcarg11 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (vector , "vector" , 0 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("vector" , __funcarg11 , env ) )) ; 
  (__funcarg10 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (vector_immutable , "vector-immutable" , 0 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("vector-immutable" , __funcarg10 , env ) )) ; 
  (__funcarg9 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (vector_length , "vector-length" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("vector-length" , __funcarg9 , env ) )) ; 
  p = FUNCCALL_AGAIN(scheme_make_noncm_prim (scheme_checked_vector_ref , "vector-ref" , 2 , 2 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 512 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("vector-ref" , p , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_noncm_prim (scheme_checked_vector_set , "vector-set!" , 3 , 3 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 32768 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("vector-set!" , p , env ) ); 
  (__funcarg8 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (vector_to_list , "vector->list" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("vector->list" , __funcarg8 , env ) )) ; 
  (__funcarg7 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (list_to_vector , "list->vector" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("list->vector" , __funcarg7 , env ) )) ; 
  (__funcarg6 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (vector_fill , "vector-fill!" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("vector-fill!" , __funcarg6 , env ) )) ; 
  (__funcarg5 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (vector_to_immutable , "vector->immutable-vector" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("vector->immutable-vector" , __funcarg5 , env ) )) ; 
  (__funcarg4 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_everything (vector_to_values , 0 , "vector->values" , 1 , 3 , 0 , 0 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("vector->values" , __funcarg4 , env ) )) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 137 */
/* this far 133 */
Scheme_Object * scheme_make_vector (int size , Scheme_Object * fill ) {
  Scheme_Object * vec ; 
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(vec, 0), PUSH(fill, 1)));
# define XfOrM2_COUNT (2)
# define SETUP_XfOrM2(x) SETUP(XfOrM2_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  vec = NULLED_OUT ; 
  if (size <= 0 ) {
#   define XfOrM8_COUNT (0+XfOrM2_COUNT)
#   define SETUP_XfOrM8(x) SETUP_XfOrM2(x)
    if (size ) {
#     define XfOrM9_COUNT (0+XfOrM8_COUNT)
#     define SETUP_XfOrM9(x) SETUP_XfOrM8(x)
      vec = ((Scheme_Object * ) (void * ) (long ) ((((long ) (size ) ) << 1 ) | 0x1 ) ) ; 
      FUNCCALL(SETUP_XfOrM9(_), scheme_wrong_type ("make-vector" , "non-negative exact integer" , - 1 , 0 , & vec ) ); 
    }
    else RET_VALUE_START (zero_length_vector ) RET_VALUE_END ; 
  }
  if (size < 1024 ) {
#   define XfOrM7_COUNT (0+XfOrM2_COUNT)
#   define SETUP_XfOrM7(x) SETUP_XfOrM2(x)
    vec = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM7(_), GC_malloc_one_tagged (sizeof (Scheme_Vector ) + (size - 1 ) * sizeof (Scheme_Object * ) ) ); 
  }
  else {
#   define XfOrM6_COUNT (0+XfOrM2_COUNT)
#   define SETUP_XfOrM6(x) SETUP_XfOrM2(x)
    vec = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM6(_), scheme_malloc_fail_ok (GC_malloc_one_tagged , sizeof (Scheme_Vector ) + (size - 1 ) * sizeof (Scheme_Object * ) ) ); 
  }
  vec -> type = scheme_vector_type ; 
  (((Scheme_Vector * ) (vec ) ) -> size ) = size ; 
  if (fill ) {
    for (i = 0 ; i < size ; i ++ ) {
      (((Scheme_Vector * ) (vec ) ) -> els ) [i ] = fill ; 
    }
  }
  RET_VALUE_START (vec ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * vector_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * make_vector (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * vec , * fill ; 
  long len ; 
  char * __funcarg13 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(vec, 0), PUSH(fill, 1), PUSH(argv, 2)));
# define XfOrM11_COUNT (3)
# define SETUP_XfOrM11(x) SETUP(XfOrM11_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  vec = NULLED_OUT ; 
  fill = NULLED_OUT ; 
  len = FUNCCALL(SETUP_XfOrM11(_), scheme_extract_index ("make-vector" , 0 , argc , argv , - 1 , 0 ) ); 
  if (len == - 1 ) {
#   define XfOrM12_COUNT (0+XfOrM11_COUNT)
#   define SETUP_XfOrM12(x) SETUP_XfOrM11(x)
    (__funcarg13 = FUNCCALL(SETUP_XfOrM12(_), scheme_make_provided_string (argv [0 ] , 1 , ((void * ) 0 ) ) ), FUNCCALL_EMPTY(scheme_raise_out_of_memory ("make-vector" , "making vector of length %s" , __funcarg13 ) )) ; 
  }
  if (argc == 2 )
    fill = argv [1 ] ; 
  else fill = ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
  vec = FUNCCALL(SETUP_XfOrM11(_), scheme_make_vector (len , fill ) ); 
  RET_VALUE_START (vec ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * vector (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * vec ; 
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(vec, 0), PUSH(argv, 1)));
# define XfOrM13_COUNT (2)
# define SETUP_XfOrM13(x) SETUP(XfOrM13_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  vec = NULLED_OUT ; 
  vec = FUNCCALL(SETUP_XfOrM13(_), scheme_make_vector (argc , 0 ) ); 
  for (i = 0 ; i < argc ; i ++ ) {
    (((Scheme_Vector * ) (vec ) ) -> els ) [i ] = argv [i ] ; 
  }
  RET_VALUE_START (vec ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * vector_immutable (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * vec ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(vec, 0)));
# define XfOrM16_COUNT (1)
# define SETUP_XfOrM16(x) SETUP(XfOrM16_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  vec = NULLED_OUT ; 
  vec = FUNCCALL(SETUP_XfOrM16(_), vector (argc , argv ) ); 
  ((((Scheme_Inclhash_Object * ) (vec ) ) -> so . keyex |= 0x1 ) ) ; 
  RET_VALUE_START (vec ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * vector_length (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) )
    scheme_wrong_type ("vector-length" , "vector" , 0 , argc , argv ) ; 
  return ((Scheme_Object * ) (void * ) (long ) ((((long ) ((((Scheme_Vector * ) (argv [0 ] ) ) -> size ) ) ) << 1 ) | 0x1 ) ) ; 
}
static Scheme_Object * bad_index (char * name , Scheme_Object * i , Scheme_Object * vec , int bottom ) {
  int n = (((Scheme_Vector * ) (vec ) ) -> size ) - 1 ; 
  char * __funcarg15 = NULLED_OUT ; 
  char * __funcarg14 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(name, 0), PUSH(i, 1)));
# define XfOrM18_COUNT (2)
# define SETUP_XfOrM18(x) SETUP(XfOrM18_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((((Scheme_Vector * ) (vec ) ) -> size ) ) {
    char * vstr ; 
    int vlen ; 
    BLOCK_SETUP((PUSH(vstr, 0+XfOrM18_COUNT)));
#   define XfOrM19_COUNT (1+XfOrM18_COUNT)
#   define SETUP_XfOrM19(x) SETUP(XfOrM19_COUNT)
    vstr = NULLED_OUT ; 
    vstr = FUNCCALL(SETUP_XfOrM19(_), scheme_make_provided_string (vec , 2 , & vlen ) ); 
    (__funcarg15 = FUNCCALL(SETUP_XfOrM19(_), scheme_make_provided_string (i , 2 , ((void * ) 0 ) ) ), FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: index %s out of range [%d, %d] for vector: %t" , name , __funcarg15 , bottom , n , vstr , vlen ) )) ; 
  }
  else (__funcarg14 = FUNCCALL(SETUP_XfOrM18(_), scheme_make_provided_string (i , 0 , ((void * ) 0 ) ) ), FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: bad index %s for empty vector" , name , __funcarg14 ) )) ; 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_checked_vector_ref (int argc , Scheme_Object * argv [] ) {
  long i , len ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM20_COUNT (1)
# define SETUP_XfOrM20(x) SETUP(XfOrM20_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("vector-ref" , "vector" , 0 , argc , argv ) ); 
  len = (((Scheme_Vector * ) (argv [0 ] ) ) -> size ) ; 
  i = FUNCCALL(SETUP_XfOrM20(_), scheme_extract_index ("vector-ref" , 1 , argc , argv , len , 0 ) ); 
  if (i >= len )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(bad_index ("vector-ref" , argv [1 ] , argv [0 ] , 0 ) )) RET_VALUE_EMPTY_END ; 
  RET_VALUE_START (((((Scheme_Vector * ) (argv [0 ] ) ) -> els ) ) [i ] ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_checked_vector_set (int argc , Scheme_Object * argv [] ) {
  long i , len ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM21_COUNT (1)
# define SETUP_XfOrM21(x) SETUP(XfOrM21_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) && (! (((Scheme_Inclhash_Object * ) (argv [0 ] ) ) -> so . keyex & 0x1 ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("vector-set!" , "mutable vector" , 0 , argc , argv ) ); 
  len = (((Scheme_Vector * ) (argv [0 ] ) ) -> size ) ; 
  i = FUNCCALL(SETUP_XfOrM21(_), scheme_extract_index ("vector-set!" , 1 , argc , argv , len , 0 ) ); 
  if (i >= len )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(bad_index ("vector-set!" , argv [1 ] , argv [0 ] , 0 ) )) RET_VALUE_EMPTY_END ; 
  ((((Scheme_Vector * ) (argv [0 ] ) ) -> els ) ) [i ] = argv [2 ] ; 
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * vector_to_list (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) )
    scheme_wrong_type ("vector->list" , "vector" , 0 , argc , argv ) ; 
  return scheme_vector_to_list (argv [0 ] ) ; 
}
Scheme_Object * scheme_vector_to_list (Scheme_Object * vec ) {
  int i ; 
  Scheme_Object * pair = scheme_null ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(vec, 0), PUSH(pair, 1)));
# define XfOrM23_COUNT (2)
# define SETUP_XfOrM23(x) SETUP(XfOrM23_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  i = (((Scheme_Vector * ) (vec ) ) -> size ) ; 
  if (i < 0xFFF ) {
#   define XfOrM31_COUNT (0+XfOrM23_COUNT)
#   define SETUP_XfOrM31(x) SETUP_XfOrM23(x)
    for (; i -- ; ) {
#     define XfOrM33_COUNT (0+XfOrM31_COUNT)
#     define SETUP_XfOrM33(x) SETUP_XfOrM31(x)
      pair = FUNCCALL(SETUP_XfOrM33(_), scheme_make_pair ((((Scheme_Vector * ) (vec ) ) -> els ) [i ] , pair ) ); 
    }
  }
  else {
#   define XfOrM24_COUNT (0+XfOrM23_COUNT)
#   define SETUP_XfOrM24(x) SETUP_XfOrM23(x)
    for (; i -- ; ) {
#     define XfOrM28_COUNT (0+XfOrM24_COUNT)
#     define SETUP_XfOrM28(x) SETUP_XfOrM24(x)
      if (! (i & 0xFFF ) ) {
#       define XfOrM29_COUNT (0+XfOrM28_COUNT)
#       define SETUP_XfOrM29(x) SETUP_XfOrM28(x)
        if ((scheme_fuel_counter ) <= 0 ) {
#         define XfOrM30_COUNT (0+XfOrM29_COUNT)
#         define SETUP_XfOrM30(x) SETUP_XfOrM29(x)
          FUNCCALL(SETUP_XfOrM30(_), scheme_out_of_fuel () ); 
        }
      }
      ; 
      pair = FUNCCALL(SETUP_XfOrM28(_), scheme_make_pair ((((Scheme_Vector * ) (vec ) ) -> els ) [i ] , pair ) ); 
    }
  }
  RET_VALUE_START (pair ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * list_to_vector (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_list_to_vector (argv [0 ] ) ; 
}
Scheme_Object * scheme_list_to_vector (Scheme_Object * list ) {
  int len , i ; 
  Scheme_Object * vec , * orig = list ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(list, 0), PUSH(vec, 1), PUSH(orig, 2)));
# define XfOrM35_COUNT (3)
# define SETUP_XfOrM35(x) SETUP(XfOrM35_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  vec = NULLED_OUT ; 
  len = FUNCCALL(SETUP_XfOrM35(_), scheme_proper_list_length (list ) ); 
  if (len < 0 )
    FUNCCALL(SETUP_XfOrM35(_), scheme_wrong_type ("list->vector" , "proper list" , - 1 , 0 , & orig ) ); 
  vec = FUNCCALL(SETUP_XfOrM35(_), scheme_make_vector (len , ((void * ) 0 ) ) ); 
  for (i = 0 ; i < len ; i ++ ) {
    (((Scheme_Vector * ) (vec ) ) -> els ) [i ] = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . car ) ; 
    list = (((Scheme_Simple_Object * ) (list ) ) -> u . pair_val . cdr ) ; 
  }
  RET_VALUE_START (vec ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * vector_fill (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  int i ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) && (! (((Scheme_Inclhash_Object * ) (argv [0 ] ) ) -> so . keyex & 0x1 ) ) ) )
    scheme_wrong_type ("vector-fill!" , "mutable vector" , 0 , argc , argv ) ; 
  for (i = 0 ; i < (((Scheme_Vector * ) (argv [0 ] ) ) -> size ) ; i ++ ) {
    (((Scheme_Vector * ) (argv [0 ] ) ) -> els ) [i ] = argv [1 ] ; 
  }
  return argv [0 ] ; 
}
static Scheme_Object * vector_to_immutable (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * vec , * ovec ; 
  long len , i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(vec, 0), PUSH(ovec, 1)));
# define XfOrM41_COUNT (2)
# define SETUP_XfOrM41(x) SETUP(XfOrM41_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  vec = NULLED_OUT ; 
  ovec = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("vector->immutable-vector" , "vector" , 0 , argc , argv ) ); 
  if ((((Scheme_Inclhash_Object * ) (argv [0 ] ) ) -> so . keyex & 0x1 ) )
    RET_VALUE_START (argv [0 ] ) RET_VALUE_END ; 
  ovec = argv [0 ] ; 
  len = (((Scheme_Vector * ) (ovec ) ) -> size ) ; 
  vec = FUNCCALL(SETUP_XfOrM41(_), scheme_make_vector (len , ((void * ) 0 ) ) ); 
  for (i = 0 ; i < len ; i ++ ) {
    (((Scheme_Vector * ) (vec ) ) -> els ) [i ] = (((Scheme_Vector * ) (ovec ) ) -> els ) [i ] ; 
  }
  ((((Scheme_Inclhash_Object * ) (vec ) ) -> so . keyex |= 0x1 ) ) ; 
  RET_VALUE_START (vec ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * vector_to_values (int argc , Scheme_Object * argv [] ) {
  Scheme_Thread * p ; 
  Scheme_Object * vec , * * a ; 
  long len , start , finish , i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(vec, 0), PUSH(a, 1), PUSH(p, 2), PUSH(argv, 3)));
# define XfOrM44_COUNT (4)
# define SETUP_XfOrM44(x) SETUP(XfOrM44_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  p = NULLED_OUT ; 
  vec = NULLED_OUT ; 
  a = NULLED_OUT ; 
  vec = argv [0 ] ; 
  if (! ((Scheme_Type ) (((((long ) (vec ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (vec ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("vector->values" , "vector" , 0 , argc , argv ) ); 
  len = (((Scheme_Vector * ) (vec ) ) -> size ) ; 
  if (argc > 1 )
    start = FUNCCALL(SETUP_XfOrM44(_), scheme_extract_index ("vector->values" , 1 , argc , argv , len + 1 , 0 ) ); 
  else start = 0 ; 
  if (argc > 2 )
    finish = FUNCCALL(SETUP_XfOrM44(_), scheme_extract_index ("vector->values" , 2 , argc , argv , len + 1 , 0 ) ); 
  else finish = len ; 
  if (! (start <= len ) ) {
#   define XfOrM49_COUNT (0+XfOrM44_COUNT)
#   define SETUP_XfOrM49(x) SETUP_XfOrM44(x)
    FUNCCALL(SETUP_XfOrM49(_), bad_index ("vector->values" , argv [1 ] , vec , 0 ) ); 
  }
  if (! (finish >= start && finish <= len ) ) {
#   define XfOrM48_COUNT (0+XfOrM44_COUNT)
#   define SETUP_XfOrM48(x) SETUP_XfOrM44(x)
    FUNCCALL(SETUP_XfOrM48(_), bad_index ("vector->values" , argv [2 ] , vec , start ) ); 
  }
  len = finish - start ; 
  if (len == 1 )
    RET_VALUE_START ((((Scheme_Vector * ) (vec ) ) -> els ) [start ] ) RET_VALUE_END ; 
  p = scheme_current_thread ; 
  if (p -> values_buffer && (p -> values_buffer_size >= len ) )
    a = p -> values_buffer ; 
  else {
#   define XfOrM47_COUNT (0+XfOrM44_COUNT)
#   define SETUP_XfOrM47(x) SETUP_XfOrM44(x)
    a = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM47(_), GC_malloc (sizeof (Scheme_Object * ) * (len ) ) )) ; 
    p -> values_buffer = a ; 
    p -> values_buffer_size = len ; 
  }
  p -> ku . multiple . array = a ; 
  p -> ku . multiple . count = len ; 
  for (i = 0 ; i < len ; i ++ ) {
    a [i ] = (((Scheme_Vector * ) (vec ) ) -> els ) [start + i ] ; 
  }
  RET_VALUE_START (((Scheme_Object * ) 0x6 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
