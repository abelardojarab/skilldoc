#include "precomp.h"
extern double exp (double __x ) __attribute__ ((__nothrow__ ) ) ; 
extern int isinf (double __value ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__const__ ) ) ; 
extern int isnan (double __value ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__const__ ) ) ; 
typedef enum {
  _IEEE_ = - 1 , _SVID_ , _XOPEN_ , _POSIX_ , _ISOC_ }
_LIB_VERSION_TYPE ; 
struct exception {
  int type ; 
  char * name ; 
  double arg1 ; 
  double arg2 ; 
  double retval ; 
}
; 
static Scheme_Object * eq (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * lt (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * gt (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * lt_eq (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * gt_eq (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * zero_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * positive_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * negative_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * sch_max (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * sch_min (int argc , Scheme_Object * argv [] ) ; 
void scheme_init_numcomp (Scheme_Env * env ) {
  Scheme_Object * p ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(p, 1)));
# define XfOrM1_COUNT (2)
# define SETUP_XfOrM1(x) SETUP(XfOrM1_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  p = NULLED_OUT ; 
  p = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (eq , "=" , 2 , - 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 512 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("=" , p , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_folding_prim (lt , "<" , 2 , - 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 512 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("<" , p , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_folding_prim (gt , ">" , 2 , - 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 512 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant (">" , p , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_folding_prim (lt_eq , "<=" , 2 , - 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 512 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("<=" , p , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_folding_prim (gt_eq , ">=" , 2 , - 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 512 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant (">=" , p , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_folding_prim (zero_p , "zero?" , 1 , 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 16384 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("zero?" , p , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_folding_prim (positive_p , "positive?" , 1 , 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 16384 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("positive?" , p , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_folding_prim (negative_p , "negative?" , 1 , 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 16384 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("negative?" , p , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_folding_prim (sch_max , "max" , 1 , - 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 512 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("max" , p , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_folding_prim (sch_min , "min" , 1 , - 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 512 ; 
  FUNCCALL_EMPTY(scheme_add_global_constant ("min" , p , env ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * force_rat (Scheme_Object * n , Small_Rational * sr ) ; 
static inline Scheme_Object * force_rat (Scheme_Object * n , Small_Rational * sr ) {
  Scheme_Type t = ((((long ) (n ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n ) ) -> type ) ; 
  if (t == scheme_rational_type )
    return n ; 
  else return scheme_make_small_bn_rational (n , sr ) ; 
}
static Scheme_Object * eq (int argc , Scheme_Object * argv [] ) ; 
static inline Scheme_Object * eq__slow (Scheme_Object * p , int argc , Scheme_Object * argv [] ) {
  Scheme_Object * o ; 
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(p, 1), PUSH(argv, 2)));
# define XfOrM2_COUNT (3)
# define SETUP_XfOrM2(x) SETUP(XfOrM2_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  o = NULLED_OUT ; 
  for (i = 1 ; i < argc ; i ++ ) {
#   define XfOrM8_COUNT (0+XfOrM2_COUNT)
#   define SETUP_XfOrM8(x) SETUP_XfOrM2(x)
    o = argv [i ] ; 
    if (! ((((long ) (o ) ) & 0x1 ) || ((((o ) -> type ) >= scheme_bignum_type ) && (((o ) -> type ) <= scheme_complex_type ) ) ) ) {
#     define XfOrM12_COUNT (0+XfOrM8_COUNT)
#     define SETUP_XfOrM12(x) SETUP_XfOrM8(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("=" , "number" , i , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    if (! FUNCCALL(SETUP_XfOrM8(_), scheme_bin_eq (p , o ) )) {
#     define XfOrM9_COUNT (0+XfOrM8_COUNT)
#     define SETUP_XfOrM9(x) SETUP_XfOrM8(x)
      for (i ++ ; i < argc ; i ++ ) {
#       define XfOrM11_COUNT (0+XfOrM9_COUNT)
#       define SETUP_XfOrM11(x) SETUP_XfOrM9(x)
        if (! ((((long ) (argv [i ] ) ) & 0x1 ) || ((((argv [i ] ) -> type ) >= scheme_bignum_type ) && (((argv [i ] ) -> type ) <= scheme_complex_type ) ) ) )
          FUNCCALL_EMPTY(scheme_wrong_type ("=" , "number" , i , argc , argv ) ); 
      }
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    }
    p = o ; 
  }
  RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * eq__bin (Scheme_Object * a , Scheme_Object * b ) {
  /* No conversion */
  return (scheme_bin_eq (a , b ) ? scheme_true : scheme_false ) ; 
}
Scheme_Object * eq (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * p , * p2 ; 
  p = argv [0 ] ; 
  if (! ((((long ) (p ) ) & 0x1 ) || ((((p ) -> type ) >= scheme_bignum_type ) && (((p ) -> type ) <= scheme_complex_type ) ) ) )
    scheme_wrong_type ("=" , "number" , 0 , argc , argv ) ; 
  if (argc == 2 ) {
    p2 = argv [1 ] ; 
    if (! ((((long ) (p2 ) ) & 0x1 ) || ((((p2 ) -> type ) >= scheme_bignum_type ) && (((p2 ) -> type ) <= scheme_complex_type ) ) ) )
      scheme_wrong_type ("=" , "number" , 1 , argc , argv ) ; 
    return eq__bin (p , p2 ) ; 
  }
  else return eq__slow (p , argc , argv ) ; 
}
static Scheme_Object * lt (int argc , Scheme_Object * argv [] ) ; 
static inline Scheme_Object * lt__slow (Scheme_Object * p , int argc , Scheme_Object * argv [] ) {
  Scheme_Object * o ; 
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(p, 1), PUSH(argv, 2)));
# define XfOrM16_COUNT (3)
# define SETUP_XfOrM16(x) SETUP(XfOrM16_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  o = NULLED_OUT ; 
  for (i = 1 ; i < argc ; i ++ ) {
#   define XfOrM22_COUNT (0+XfOrM16_COUNT)
#   define SETUP_XfOrM22(x) SETUP_XfOrM16(x)
    o = argv [i ] ; 
    if (! ((((long ) (o ) ) & 0x1 ) || ((((o ) -> type ) >= scheme_bignum_type ) && (((o ) -> type ) <= scheme_complex_izi_type ) ) ) ) {
#     define XfOrM26_COUNT (0+XfOrM22_COUNT)
#     define SETUP_XfOrM26(x) SETUP_XfOrM22(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("<" , "real number" , i , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    if (! FUNCCALL(SETUP_XfOrM22(_), scheme_bin_lt (p , o ) )) {
#     define XfOrM23_COUNT (0+XfOrM22_COUNT)
#     define SETUP_XfOrM23(x) SETUP_XfOrM22(x)
      for (i ++ ; i < argc ; i ++ ) {
#       define XfOrM25_COUNT (0+XfOrM23_COUNT)
#       define SETUP_XfOrM25(x) SETUP_XfOrM23(x)
        if (! ((((long ) (argv [i ] ) ) & 0x1 ) || ((((argv [i ] ) -> type ) >= scheme_bignum_type ) && (((argv [i ] ) -> type ) <= scheme_complex_izi_type ) ) ) )
          FUNCCALL_EMPTY(scheme_wrong_type ("<" , "real number" , i , argc , argv ) ); 
      }
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    }
    p = o ; 
  }
  RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * lt__bin (Scheme_Object * a , Scheme_Object * b ) {
  /* No conversion */
  return (scheme_bin_lt (a , b ) ? scheme_true : scheme_false ) ; 
}
Scheme_Object * lt (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * p , * p2 ; 
  p = argv [0 ] ; 
  if (! ((((long ) (p ) ) & 0x1 ) || ((((p ) -> type ) >= scheme_bignum_type ) && (((p ) -> type ) <= scheme_complex_izi_type ) ) ) )
    scheme_wrong_type ("<" , "real number" , 0 , argc , argv ) ; 
  if (argc == 2 ) {
    p2 = argv [1 ] ; 
    if (! ((((long ) (p2 ) ) & 0x1 ) || ((((p2 ) -> type ) >= scheme_bignum_type ) && (((p2 ) -> type ) <= scheme_complex_izi_type ) ) ) )
      scheme_wrong_type ("<" , "real number" , 1 , argc , argv ) ; 
    return lt__bin (p , p2 ) ; 
  }
  else return lt__slow (p , argc , argv ) ; 
}
static Scheme_Object * gt (int argc , Scheme_Object * argv [] ) ; 
static inline Scheme_Object * gt__slow (Scheme_Object * p , int argc , Scheme_Object * argv [] ) {
  Scheme_Object * o ; 
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(p, 1), PUSH(argv, 2)));
# define XfOrM30_COUNT (3)
# define SETUP_XfOrM30(x) SETUP(XfOrM30_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  o = NULLED_OUT ; 
  for (i = 1 ; i < argc ; i ++ ) {
#   define XfOrM36_COUNT (0+XfOrM30_COUNT)
#   define SETUP_XfOrM36(x) SETUP_XfOrM30(x)
    o = argv [i ] ; 
    if (! ((((long ) (o ) ) & 0x1 ) || ((((o ) -> type ) >= scheme_bignum_type ) && (((o ) -> type ) <= scheme_complex_izi_type ) ) ) ) {
#     define XfOrM40_COUNT (0+XfOrM36_COUNT)
#     define SETUP_XfOrM40(x) SETUP_XfOrM36(x)
      FUNCCALL_EMPTY(scheme_wrong_type (">" , "real number" , i , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    if (! FUNCCALL(SETUP_XfOrM36(_), scheme_bin_gt (p , o ) )) {
#     define XfOrM37_COUNT (0+XfOrM36_COUNT)
#     define SETUP_XfOrM37(x) SETUP_XfOrM36(x)
      for (i ++ ; i < argc ; i ++ ) {
#       define XfOrM39_COUNT (0+XfOrM37_COUNT)
#       define SETUP_XfOrM39(x) SETUP_XfOrM37(x)
        if (! ((((long ) (argv [i ] ) ) & 0x1 ) || ((((argv [i ] ) -> type ) >= scheme_bignum_type ) && (((argv [i ] ) -> type ) <= scheme_complex_izi_type ) ) ) )
          FUNCCALL_EMPTY(scheme_wrong_type (">" , "real number" , i , argc , argv ) ); 
      }
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    }
    p = o ; 
  }
  RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * gt__bin (Scheme_Object * a , Scheme_Object * b ) {
  /* No conversion */
  return (scheme_bin_gt (a , b ) ? scheme_true : scheme_false ) ; 
}
Scheme_Object * gt (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * p , * p2 ; 
  p = argv [0 ] ; 
  if (! ((((long ) (p ) ) & 0x1 ) || ((((p ) -> type ) >= scheme_bignum_type ) && (((p ) -> type ) <= scheme_complex_izi_type ) ) ) )
    scheme_wrong_type (">" , "real number" , 0 , argc , argv ) ; 
  if (argc == 2 ) {
    p2 = argv [1 ] ; 
    if (! ((((long ) (p2 ) ) & 0x1 ) || ((((p2 ) -> type ) >= scheme_bignum_type ) && (((p2 ) -> type ) <= scheme_complex_izi_type ) ) ) )
      scheme_wrong_type (">" , "real number" , 1 , argc , argv ) ; 
    return gt__bin (p , p2 ) ; 
  }
  else return gt__slow (p , argc , argv ) ; 
}
static Scheme_Object * lt_eq (int argc , Scheme_Object * argv [] ) ; 
static inline Scheme_Object * lt_eq__slow (Scheme_Object * p , int argc , Scheme_Object * argv [] ) {
  Scheme_Object * o ; 
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(p, 1), PUSH(argv, 2)));
# define XfOrM44_COUNT (3)
# define SETUP_XfOrM44(x) SETUP(XfOrM44_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  o = NULLED_OUT ; 
  for (i = 1 ; i < argc ; i ++ ) {
#   define XfOrM50_COUNT (0+XfOrM44_COUNT)
#   define SETUP_XfOrM50(x) SETUP_XfOrM44(x)
    o = argv [i ] ; 
    if (! ((((long ) (o ) ) & 0x1 ) || ((((o ) -> type ) >= scheme_bignum_type ) && (((o ) -> type ) <= scheme_complex_izi_type ) ) ) ) {
#     define XfOrM54_COUNT (0+XfOrM50_COUNT)
#     define SETUP_XfOrM54(x) SETUP_XfOrM50(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("<=" , "real number" , i , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    if (! FUNCCALL(SETUP_XfOrM50(_), scheme_bin_lt_eq (p , o ) )) {
#     define XfOrM51_COUNT (0+XfOrM50_COUNT)
#     define SETUP_XfOrM51(x) SETUP_XfOrM50(x)
      for (i ++ ; i < argc ; i ++ ) {
#       define XfOrM53_COUNT (0+XfOrM51_COUNT)
#       define SETUP_XfOrM53(x) SETUP_XfOrM51(x)
        if (! ((((long ) (argv [i ] ) ) & 0x1 ) || ((((argv [i ] ) -> type ) >= scheme_bignum_type ) && (((argv [i ] ) -> type ) <= scheme_complex_izi_type ) ) ) )
          FUNCCALL_EMPTY(scheme_wrong_type ("<=" , "real number" , i , argc , argv ) ); 
      }
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    }
    p = o ; 
  }
  RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * lt_eq__bin (Scheme_Object * a , Scheme_Object * b ) {
  /* No conversion */
  return (scheme_bin_lt_eq (a , b ) ? scheme_true : scheme_false ) ; 
}
Scheme_Object * lt_eq (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * p , * p2 ; 
  p = argv [0 ] ; 
  if (! ((((long ) (p ) ) & 0x1 ) || ((((p ) -> type ) >= scheme_bignum_type ) && (((p ) -> type ) <= scheme_complex_izi_type ) ) ) )
    scheme_wrong_type ("<=" , "real number" , 0 , argc , argv ) ; 
  if (argc == 2 ) {
    p2 = argv [1 ] ; 
    if (! ((((long ) (p2 ) ) & 0x1 ) || ((((p2 ) -> type ) >= scheme_bignum_type ) && (((p2 ) -> type ) <= scheme_complex_izi_type ) ) ) )
      scheme_wrong_type ("<=" , "real number" , 1 , argc , argv ) ; 
    return lt_eq__bin (p , p2 ) ; 
  }
  else return lt_eq__slow (p , argc , argv ) ; 
}
static Scheme_Object * gt_eq (int argc , Scheme_Object * argv [] ) ; 
static inline Scheme_Object * gt_eq__slow (Scheme_Object * p , int argc , Scheme_Object * argv [] ) {
  Scheme_Object * o ; 
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(p, 1), PUSH(argv, 2)));
# define XfOrM58_COUNT (3)
# define SETUP_XfOrM58(x) SETUP(XfOrM58_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  o = NULLED_OUT ; 
  for (i = 1 ; i < argc ; i ++ ) {
#   define XfOrM64_COUNT (0+XfOrM58_COUNT)
#   define SETUP_XfOrM64(x) SETUP_XfOrM58(x)
    o = argv [i ] ; 
    if (! ((((long ) (o ) ) & 0x1 ) || ((((o ) -> type ) >= scheme_bignum_type ) && (((o ) -> type ) <= scheme_complex_izi_type ) ) ) ) {
#     define XfOrM68_COUNT (0+XfOrM64_COUNT)
#     define SETUP_XfOrM68(x) SETUP_XfOrM64(x)
      FUNCCALL_EMPTY(scheme_wrong_type (">=" , "real number" , i , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    if (! FUNCCALL(SETUP_XfOrM64(_), scheme_bin_gt_eq (p , o ) )) {
#     define XfOrM65_COUNT (0+XfOrM64_COUNT)
#     define SETUP_XfOrM65(x) SETUP_XfOrM64(x)
      for (i ++ ; i < argc ; i ++ ) {
#       define XfOrM67_COUNT (0+XfOrM65_COUNT)
#       define SETUP_XfOrM67(x) SETUP_XfOrM65(x)
        if (! ((((long ) (argv [i ] ) ) & 0x1 ) || ((((argv [i ] ) -> type ) >= scheme_bignum_type ) && (((argv [i ] ) -> type ) <= scheme_complex_izi_type ) ) ) )
          FUNCCALL_EMPTY(scheme_wrong_type (">=" , "real number" , i , argc , argv ) ); 
      }
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    }
    p = o ; 
  }
  RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * gt_eq__bin (Scheme_Object * a , Scheme_Object * b ) {
  /* No conversion */
  return (scheme_bin_gt_eq (a , b ) ? scheme_true : scheme_false ) ; 
}
Scheme_Object * gt_eq (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * p , * p2 ; 
  p = argv [0 ] ; 
  if (! ((((long ) (p ) ) & 0x1 ) || ((((p ) -> type ) >= scheme_bignum_type ) && (((p ) -> type ) <= scheme_complex_izi_type ) ) ) )
    scheme_wrong_type (">=" , "real number" , 0 , argc , argv ) ; 
  if (argc == 2 ) {
    p2 = argv [1 ] ; 
    if (! ((((long ) (p2 ) ) & 0x1 ) || ((((p2 ) -> type ) >= scheme_bignum_type ) && (((p2 ) -> type ) <= scheme_complex_izi_type ) ) ) )
      scheme_wrong_type (">=" , "real number" , 1 , argc , argv ) ; 
    return gt_eq__bin (p , p2 ) ; 
  }
  else return gt_eq__slow (p , argc , argv ) ; 
}
int scheme_bin_eq (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
static int scheme_bin_eq__wrong_type (const Scheme_Object * v ) {
  Scheme_Object * a [1 ] ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 1, 0)));
# define XfOrM72_COUNT (3)
# define SETUP_XfOrM72(x) SETUP(XfOrM72_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a [0 ] = (Scheme_Object * ) v ; 
  FUNCCALL(SETUP_XfOrM72(_), scheme_wrong_type ("=" , "number" , - 1 , 0 , a ) ); 
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_eq__int_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  Small_Bignum sb ; 
  return scheme_bignum_eq ((scheme_make_small_bignum ((((long ) (n1 ) ) >> 1 ) , & sb ) ) , (n2 ) ) ; 
}
static inline int scheme_bin_eq__int_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  Small_Rational sr1 ; 
  return scheme_rational_eq ((scheme_make_small_rational ((((long ) (n1 ) ) >> 1 ) , & sr1 ) ) , (n2 ) ) ; 
}
static inline int scheme_bin_eq__int_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM75_COUNT (2)
# define SETUP_XfOrM75(x) SETUP(XfOrM75_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM75(_), scheme_complex_eq ((scheme_make_small_complex (n1 , & sc ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_eq__dbl_big (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr4 ; 
  Scheme_Object * __funcarg6 = NULLED_OUT ; 
  Scheme_Object * __funcarg5 = NULLED_OUT ; 
  Scheme_Object * __funcarg4 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(__funcarg4, 0), PUSH(sr4.num, 1), PUSH(sr4.denom, 2), PUSH(n2, 3)));
# define XfOrM76_COUNT (4)
# define SETUP_XfOrM76(x) SETUP(XfOrM76_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr4.num = NULLED_OUT ; 
  sr4.denom = NULLED_OUT ; 
  ; 
  if ((isinf (d1 ) && (d1 > 0 ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  if ((isinf (d1 ) && (d1 < 0 ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  RET_VALUE_START ((__funcarg4 = (__funcarg6 = FUNCCALL(SETUP_XfOrM76(_), scheme_rational_from_double (d1 ) ), FUNCCALL_AGAIN(force_rat (__funcarg6 , & sr4 ) )) , __funcarg5 = FUNCCALL(SETUP_XfOrM76(_), scheme_integer_to_rational (n2 ) ), (scheme_rational_eq (__funcarg4 , __funcarg5 ) ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_eq__dbl_rat (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr5 ; 
  Scheme_Object * __funcarg8 = NULLED_OUT ; 
  Scheme_Object * __funcarg7 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(sr5.num, 0), PUSH(sr5.denom, 1), PUSH(n2, 2)));
# define XfOrM77_COUNT (3)
# define SETUP_XfOrM77(x) SETUP(XfOrM77_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr5.num = NULLED_OUT ; 
  sr5.denom = NULLED_OUT ; 
  ; 
  if ((isinf (d1 ) && (d1 > 0 ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  if ((isinf (d1 ) && (d1 < 0 ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  if (d1 == 0.0 )
    RET_VALUE_START ((scheme_is_inexact (n2 ) ) ) RET_VALUE_END ; 
  RET_VALUE_START ((__funcarg7 = (__funcarg8 = FUNCCALL(SETUP_XfOrM77(_), scheme_rational_from_double (d1 ) ), FUNCCALL_AGAIN(force_rat (__funcarg8 , & sr5 ) )) , (scheme_rational_eq (__funcarg7 , (n2 ) ) ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_eq__dbl_comp (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM78_COUNT (2)
# define SETUP_XfOrM78(x) SETUP(XfOrM78_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM78(_), scheme_complex_eq ((scheme_make_small_complex (n1 , & sc ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_eq__big_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  Small_Bignum sb ; 
  return scheme_bignum_eq ((n1 ) , (scheme_make_small_bignum ((((long ) (n2 ) ) >> 1 ) , & sb ) ) ) ; 
}
static inline int scheme_bin_eq__big_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  double d2 ; 
  Small_Rational sr7 ; 
  Scheme_Object * __funcarg11 = NULLED_OUT ; 
  Scheme_Object * __funcarg10 = NULLED_OUT ; 
  Scheme_Object * __funcarg9 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(__funcarg9, 0), PUSH(sr7.num, 1), PUSH(sr7.denom, 2)));
# define XfOrM80_COUNT (3)
# define SETUP_XfOrM80(x) SETUP(XfOrM80_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr7.num = NULLED_OUT ; 
  sr7.denom = NULLED_OUT ; 
  d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
  ; 
  if ((isinf (d2 ) && (d2 > 0 ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  if ((isinf (d2 ) && (d2 < 0 ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  RET_VALUE_START ((__funcarg9 = FUNCCALL(SETUP_XfOrM80(_), scheme_integer_to_rational (n1 ) ), __funcarg10 = (__funcarg11 = FUNCCALL(SETUP_XfOrM80(_), scheme_rational_from_double (d2 ) ), FUNCCALL_AGAIN(force_rat (__funcarg11 , & sr7 ) )) , (scheme_rational_eq (__funcarg9 , __funcarg10 ) ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_eq__big_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Scheme_Object * __funcarg12 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(n2, 0)));
# define XfOrM81_COUNT (1)
# define SETUP_XfOrM81(x) SETUP(XfOrM81_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg12 = FUNCCALL(SETUP_XfOrM81(_), scheme_integer_to_rational (n1 ) ), (scheme_rational_eq (__funcarg12 , (n2 ) ) ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_eq__big_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM82_COUNT (2)
# define SETUP_XfOrM82(x) SETUP(XfOrM82_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM82(_), scheme_complex_eq ((scheme_make_small_complex (n1 , & sc ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_eq__rat_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  Small_Rational sr8 ; 
  return scheme_rational_eq ((n1 ) , (scheme_make_small_rational ((((long ) (n2 ) ) >> 1 ) , & sr8 ) ) ) ; 
}
static inline int scheme_bin_eq__rat_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  double d2 ; 
  Small_Rational sr10 ; 
  Scheme_Object * __funcarg14 = NULLED_OUT ; 
  Scheme_Object * __funcarg13 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(n1, 0), PUSH(sr10.num, 1), PUSH(sr10.denom, 2)));
# define XfOrM84_COUNT (3)
# define SETUP_XfOrM84(x) SETUP(XfOrM84_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr10.num = NULLED_OUT ; 
  sr10.denom = NULLED_OUT ; 
  d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
  ; 
  if ((isinf (d2 ) && (d2 > 0 ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  if ((isinf (d2 ) && (d2 < 0 ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  if (d2 == 0.0 )
    RET_VALUE_START ((scheme_is_inexact (n1 ) ) ) RET_VALUE_END ; 
  RET_VALUE_START ((__funcarg13 = (__funcarg14 = FUNCCALL(SETUP_XfOrM84(_), scheme_rational_from_double (d2 ) ), FUNCCALL_AGAIN(force_rat (__funcarg14 , & sr10 ) )) , (scheme_rational_eq ((n1 ) , __funcarg13 ) ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_eq__rat_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Scheme_Object * __funcarg15 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(n1, 0)));
# define XfOrM85_COUNT (1)
# define SETUP_XfOrM85(x) SETUP(XfOrM85_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg15 = FUNCCALL(SETUP_XfOrM85(_), scheme_integer_to_rational (n2 ) ), (scheme_rational_eq ((n1 ) , __funcarg15 ) ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_eq__rat_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM86_COUNT (2)
# define SETUP_XfOrM86(x) SETUP(XfOrM86_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM86(_), scheme_complex_eq ((scheme_make_small_complex (n1 , & sc ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_eq__comp_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM87_COUNT (2)
# define SETUP_XfOrM87(x) SETUP(XfOrM87_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM87(_), scheme_complex_eq ((n1 ) , (scheme_make_small_complex (n2 , & sc ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_eq__comp_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM88_COUNT (2)
# define SETUP_XfOrM88(x) SETUP(XfOrM88_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM88(_), scheme_complex_eq ((n1 ) , (scheme_make_small_complex (n2 , & sc ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_eq__comp_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM89_COUNT (2)
# define SETUP_XfOrM89(x) SETUP(XfOrM89_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM89(_), scheme_complex_eq ((n1 ) , (scheme_make_small_complex (n2 , & sc ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_eq__comp_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM90_COUNT (2)
# define SETUP_XfOrM90(x) SETUP(XfOrM90_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM90(_), scheme_complex_eq ((n1 ) , (scheme_make_small_complex (n2 , & sc ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_bin_eq (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  Scheme_Type t1 , t2 ; 
  if ((((long ) (n1 ) ) & 0x1 ) ) {
    if ((((long ) (n2 ) ) & 0x1 ) )
      return ((((long ) (n1 ) ) >> 1 ) == (((long ) (n2 ) ) >> 1 ) ) ; 
    t2 = ((n2 ) -> type ) ; 
    if (t2 == scheme_double_type ) {
      double d = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
      ; 
      return ((((long ) (n1 ) ) >> 1 ) == d ) ; 
    }
    if (t2 == scheme_bignum_type ) {
      return scheme_bin_eq__int_big (n1 , n2 ) ; 
    }
    if (t2 == scheme_rational_type ) {
      return scheme_bin_eq__int_rat (n1 , n2 ) ; 
    }
    if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
      return scheme_bin_eq__int_comp (n1 , n2 ) ; 
    }
    return scheme_bin_eq__wrong_type (n2 ) ; 
  }
  else {
    t1 = ((n1 ) -> type ) ; 
    if (t1 == scheme_double_type ) {
      double d1 = (((Scheme_Double * ) (n1 ) ) -> double_val ) ; 
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        ; 
        return (d1 == (((long ) (n2 ) ) >> 1 ) ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        double d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
        ; 
        ; 
        return (d1 == d2 ) ; 
      }
      if (t2 == scheme_bignum_type ) {
        return scheme_bin_eq__dbl_big (d1 , n1 , n2 ) ; 
      }
      if (t2 == scheme_rational_type ) {
        return scheme_bin_eq__dbl_rat (d1 , n1 , n2 ) ; 
      }
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
        return scheme_bin_eq__dbl_comp (d1 , n1 , n2 ) ; 
      }
      return scheme_bin_eq__wrong_type (n2 ) ; 
    }
    else if (t1 == scheme_bignum_type ) {
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        return scheme_bin_eq__big_int (n1 , n2 ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return scheme_bin_eq__big_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return scheme_bignum_eq ((n1 ) , (n2 ) ) ; 
      if (t2 == scheme_rational_type )
        return scheme_bin_eq__big_rat (n1 , n2 ) ; 
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
        return scheme_bin_eq__big_comp (n1 , n2 ) ; 
      }
      return scheme_bin_eq__wrong_type (n2 ) ; 
    }
    else if (t1 == scheme_rational_type ) {
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        return scheme_bin_eq__rat_int (n1 , n2 ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return scheme_bin_eq__rat_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return scheme_bin_eq__rat_big (n1 , n2 ) ; 
      if (t2 == scheme_rational_type )
        return scheme_rational_eq ((n1 ) , (n2 ) ) ; 
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
        return scheme_bin_eq__rat_comp (n1 , n2 ) ; 
      }
      return scheme_bin_eq__wrong_type (n2 ) ; 
    }
    else if ((t1 == scheme_complex_type ) || (t1 == scheme_complex_izi_type ) ) {
      if ((((long ) (n2 ) ) & 0x1 ) )
        return scheme_bin_eq__comp_int (n1 , n2 ) ; 
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return scheme_bin_eq__comp_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return scheme_bin_eq__comp_big (n1 , n2 ) ; 
      if (t2 == scheme_rational_type )
        return scheme_bin_eq__comp_rat (n1 , n2 ) ; 
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) )
        return scheme_complex_eq ((n1 ) , (n2 ) ) ; 
      return scheme_bin_eq__wrong_type (n2 ) ; 
    }
    else return scheme_bin_eq__wrong_type (n1 ) ; 
  }
}
int scheme_bin_lt (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
static int scheme_bin_lt__wrong_type (const Scheme_Object * v ) {
  Scheme_Object * a [1 ] ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 1, 0)));
# define XfOrM114_COUNT (3)
# define SETUP_XfOrM114(x) SETUP(XfOrM114_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a [0 ] = (Scheme_Object * ) v ; 
  FUNCCALL(SETUP_XfOrM114(_), scheme_wrong_type ("<" , "real number" , - 1 , 0 , a ) ); 
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt__int_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  Small_Bignum sb ; 
  return scheme_bignum_lt ((scheme_make_small_bignum ((((long ) (n1 ) ) >> 1 ) , & sb ) ) , (n2 ) ) ; 
}
static inline int scheme_bin_lt__int_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr1 ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sr1.num, 0), PUSH(sr1.denom, 1)));
# define XfOrM116_COUNT (2)
# define SETUP_XfOrM116(x) SETUP(XfOrM116_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr1.num = NULLED_OUT ; 
  sr1.denom = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM116(_), scheme_rational_lt ((scheme_make_small_rational ((((long ) (n1 ) ) >> 1 ) , & sr1 ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt__int_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM117_COUNT (2)
# define SETUP_XfOrM117(x) SETUP(XfOrM117_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM117(_), scheme_bin_lt ((((Scheme_Complex * ) ((scheme_make_small_complex (n1 , & sc ) ) ) ) -> r ) , (((Scheme_Complex * ) ((n2 ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt__dbl_big (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr4 ; 
  Scheme_Object * __funcarg18 = NULLED_OUT ; 
  Scheme_Object * __funcarg17 = NULLED_OUT ; 
  Scheme_Object * __funcarg16 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(__funcarg16, 0), PUSH(sr4.num, 1), PUSH(sr4.denom, 2), PUSH(n2, 3)));
# define XfOrM118_COUNT (4)
# define SETUP_XfOrM118(x) SETUP(XfOrM118_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr4.num = NULLED_OUT ; 
  sr4.denom = NULLED_OUT ; 
  ; 
  if ((isinf (d1 ) && (d1 > 0 ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  if ((isinf (d1 ) && (d1 < 0 ) ) )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  RET_VALUE_START ((__funcarg16 = (__funcarg18 = FUNCCALL(SETUP_XfOrM118(_), scheme_rational_from_double (d1 ) ), FUNCCALL_AGAIN(force_rat (__funcarg18 , & sr4 ) )) , __funcarg17 = FUNCCALL(SETUP_XfOrM118(_), scheme_integer_to_rational (n2 ) ), FUNCCALL_AGAIN(scheme_rational_lt (__funcarg16 , __funcarg17 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt__dbl_rat (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr5 ; 
  Scheme_Object * __funcarg20 = NULLED_OUT ; 
  Scheme_Object * __funcarg19 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(sr5.num, 0), PUSH(sr5.denom, 1), PUSH(n2, 2)));
# define XfOrM119_COUNT (3)
# define SETUP_XfOrM119(x) SETUP(XfOrM119_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr5.num = NULLED_OUT ; 
  sr5.denom = NULLED_OUT ; 
  ; 
  if ((isinf (d1 ) && (d1 > 0 ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  if ((isinf (d1 ) && (d1 < 0 ) ) )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  if (d1 == 0.0 )
    RET_VALUE_START ((scheme_is_positive (n2 ) ) ) RET_VALUE_END ; 
  RET_VALUE_START ((__funcarg19 = (__funcarg20 = FUNCCALL(SETUP_XfOrM119(_), scheme_rational_from_double (d1 ) ), FUNCCALL_AGAIN(force_rat (__funcarg20 , & sr5 ) )) , FUNCCALL_AGAIN(scheme_rational_lt (__funcarg19 , (n2 ) ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt__dbl_comp (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM120_COUNT (2)
# define SETUP_XfOrM120(x) SETUP(XfOrM120_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM120(_), scheme_bin_lt ((((Scheme_Complex * ) ((scheme_make_small_complex (n1 , & sc ) ) ) ) -> r ) , (((Scheme_Complex * ) ((n2 ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt__big_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  Small_Bignum sb ; 
  return scheme_bignum_lt ((n1 ) , (scheme_make_small_bignum ((((long ) (n2 ) ) >> 1 ) , & sb ) ) ) ; 
}
static inline int scheme_bin_lt__big_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  double d2 ; 
  Small_Rational sr7 ; 
  Scheme_Object * __funcarg23 = NULLED_OUT ; 
  Scheme_Object * __funcarg22 = NULLED_OUT ; 
  Scheme_Object * __funcarg21 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(__funcarg21, 0), PUSH(sr7.num, 1), PUSH(sr7.denom, 2)));
# define XfOrM122_COUNT (3)
# define SETUP_XfOrM122(x) SETUP(XfOrM122_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr7.num = NULLED_OUT ; 
  sr7.denom = NULLED_OUT ; 
  d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
  ; 
  if ((isinf (d2 ) && (d2 > 0 ) ) )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  if ((isinf (d2 ) && (d2 < 0 ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  RET_VALUE_START ((__funcarg21 = FUNCCALL(SETUP_XfOrM122(_), scheme_integer_to_rational (n1 ) ), __funcarg22 = (__funcarg23 = FUNCCALL(SETUP_XfOrM122(_), scheme_rational_from_double (d2 ) ), FUNCCALL_AGAIN(force_rat (__funcarg23 , & sr7 ) )) , FUNCCALL_AGAIN(scheme_rational_lt (__funcarg21 , __funcarg22 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt__big_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Scheme_Object * __funcarg24 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(n2, 0)));
# define XfOrM123_COUNT (1)
# define SETUP_XfOrM123(x) SETUP(XfOrM123_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg24 = FUNCCALL(SETUP_XfOrM123(_), scheme_integer_to_rational (n1 ) ), FUNCCALL_EMPTY(scheme_rational_lt (__funcarg24 , (n2 ) ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt__big_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM124_COUNT (2)
# define SETUP_XfOrM124(x) SETUP(XfOrM124_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM124(_), scheme_bin_lt ((((Scheme_Complex * ) ((scheme_make_small_complex (n1 , & sc ) ) ) ) -> r ) , (((Scheme_Complex * ) ((n2 ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt__rat_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr8 ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sr8.num, 0), PUSH(sr8.denom, 1)));
# define XfOrM125_COUNT (2)
# define SETUP_XfOrM125(x) SETUP(XfOrM125_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr8.num = NULLED_OUT ; 
  sr8.denom = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM125(_), scheme_rational_lt ((n1 ) , (scheme_make_small_rational ((((long ) (n2 ) ) >> 1 ) , & sr8 ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt__rat_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  double d2 ; 
  Small_Rational sr10 ; 
  Scheme_Object * __funcarg26 = NULLED_OUT ; 
  Scheme_Object * __funcarg25 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(n1, 0), PUSH(sr10.num, 1), PUSH(sr10.denom, 2)));
# define XfOrM126_COUNT (3)
# define SETUP_XfOrM126(x) SETUP(XfOrM126_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr10.num = NULLED_OUT ; 
  sr10.denom = NULLED_OUT ; 
  d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
  ; 
  if ((isinf (d2 ) && (d2 > 0 ) ) )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  if ((isinf (d2 ) && (d2 < 0 ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  if (d2 == 0.0 )
    RET_VALUE_START ((scheme_is_negative (n1 ) ) ) RET_VALUE_END ; 
  RET_VALUE_START ((__funcarg25 = (__funcarg26 = FUNCCALL(SETUP_XfOrM126(_), scheme_rational_from_double (d2 ) ), FUNCCALL_AGAIN(force_rat (__funcarg26 , & sr10 ) )) , FUNCCALL_AGAIN(scheme_rational_lt ((n1 ) , __funcarg25 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt__rat_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Scheme_Object * __funcarg27 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(n1, 0)));
# define XfOrM127_COUNT (1)
# define SETUP_XfOrM127(x) SETUP(XfOrM127_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg27 = FUNCCALL(SETUP_XfOrM127(_), scheme_integer_to_rational (n2 ) ), FUNCCALL_EMPTY(scheme_rational_lt ((n1 ) , __funcarg27 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt__rat_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM128_COUNT (2)
# define SETUP_XfOrM128(x) SETUP(XfOrM128_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM128(_), scheme_bin_lt ((((Scheme_Complex * ) ((scheme_make_small_complex (n1 , & sc ) ) ) ) -> r ) , (((Scheme_Complex * ) ((n2 ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt__comp_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM129_COUNT (2)
# define SETUP_XfOrM129(x) SETUP(XfOrM129_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM129(_), scheme_bin_lt ((((Scheme_Complex * ) ((n1 ) ) ) -> r ) , (((Scheme_Complex * ) ((scheme_make_small_complex (n2 , & sc ) ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt__comp_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM130_COUNT (2)
# define SETUP_XfOrM130(x) SETUP(XfOrM130_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM130(_), scheme_bin_lt ((((Scheme_Complex * ) ((n1 ) ) ) -> r ) , (((Scheme_Complex * ) ((scheme_make_small_complex (n2 , & sc ) ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt__comp_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM131_COUNT (2)
# define SETUP_XfOrM131(x) SETUP(XfOrM131_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM131(_), scheme_bin_lt ((((Scheme_Complex * ) ((n1 ) ) ) -> r ) , (((Scheme_Complex * ) ((scheme_make_small_complex (n2 , & sc ) ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt__comp_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM132_COUNT (2)
# define SETUP_XfOrM132(x) SETUP(XfOrM132_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM132(_), scheme_bin_lt ((((Scheme_Complex * ) ((n1 ) ) ) -> r ) , (((Scheme_Complex * ) ((scheme_make_small_complex (n2 , & sc ) ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_bin_lt (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  Scheme_Type t1 , t2 ; 
  if ((((long ) (n1 ) ) & 0x1 ) ) {
    if ((((long ) (n2 ) ) & 0x1 ) )
      return ((((long ) (n1 ) ) >> 1 ) < (((long ) (n2 ) ) >> 1 ) ) ; 
    t2 = ((n2 ) -> type ) ; 
    if (t2 == scheme_double_type ) {
      double d = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
      ; 
      return ((((long ) (n1 ) ) >> 1 ) < d ) ; 
    }
    if (t2 == scheme_bignum_type ) {
      return scheme_bin_lt__int_big (n1 , n2 ) ; 
    }
    if (t2 == scheme_rational_type ) {
      return scheme_bin_lt__int_rat (n1 , n2 ) ; 
    }
    if ((t2 == scheme_complex_izi_type ) ) {
      return scheme_bin_lt__int_comp (n1 , n2 ) ; 
    }
    return scheme_bin_lt__wrong_type (n2 ) ; 
  }
  else {
    t1 = ((n1 ) -> type ) ; 
    if (t1 == scheme_double_type ) {
      double d1 = (((Scheme_Double * ) (n1 ) ) -> double_val ) ; 
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        ; 
        return (d1 < (((long ) (n2 ) ) >> 1 ) ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        double d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
        ; 
        ; 
        return (d1 < d2 ) ; 
      }
      if (t2 == scheme_bignum_type ) {
        return scheme_bin_lt__dbl_big (d1 , n1 , n2 ) ; 
      }
      if (t2 == scheme_rational_type ) {
        return scheme_bin_lt__dbl_rat (d1 , n1 , n2 ) ; 
      }
      if ((t2 == scheme_complex_izi_type ) ) {
        return scheme_bin_lt__dbl_comp (d1 , n1 , n2 ) ; 
      }
      return scheme_bin_lt__wrong_type (n2 ) ; 
    }
    else if (t1 == scheme_bignum_type ) {
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        return scheme_bin_lt__big_int (n1 , n2 ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return scheme_bin_lt__big_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return scheme_bignum_lt ((n1 ) , (n2 ) ) ; 
      if (t2 == scheme_rational_type )
        return scheme_bin_lt__big_rat (n1 , n2 ) ; 
      if ((t2 == scheme_complex_izi_type ) ) {
        return scheme_bin_lt__big_comp (n1 , n2 ) ; 
      }
      return scheme_bin_lt__wrong_type (n2 ) ; 
    }
    else if (t1 == scheme_rational_type ) {
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        return scheme_bin_lt__rat_int (n1 , n2 ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return scheme_bin_lt__rat_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return scheme_bin_lt__rat_big (n1 , n2 ) ; 
      if (t2 == scheme_rational_type )
        return scheme_rational_lt ((n1 ) , (n2 ) ) ; 
      if ((t2 == scheme_complex_izi_type ) ) {
        return scheme_bin_lt__rat_comp (n1 , n2 ) ; 
      }
      return scheme_bin_lt__wrong_type (n2 ) ; 
    }
    else if ((t1 == scheme_complex_izi_type ) ) {
      if ((((long ) (n2 ) ) & 0x1 ) )
        return scheme_bin_lt__comp_int (n1 , n2 ) ; 
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return scheme_bin_lt__comp_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return scheme_bin_lt__comp_big (n1 , n2 ) ; 
      if (t2 == scheme_rational_type )
        return scheme_bin_lt__comp_rat (n1 , n2 ) ; 
      if ((t2 == scheme_complex_izi_type ) )
        return scheme_bin_lt ((((Scheme_Complex * ) ((n1 ) ) ) -> r ) , (((Scheme_Complex * ) ((n2 ) ) ) -> r ) ) ; 
      return scheme_bin_lt__wrong_type (n2 ) ; 
    }
    else return scheme_bin_lt__wrong_type (n1 ) ; 
  }
}
int scheme_bin_gt (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
static int scheme_bin_gt__wrong_type (const Scheme_Object * v ) {
  Scheme_Object * a [1 ] ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 1, 0)));
# define XfOrM156_COUNT (3)
# define SETUP_XfOrM156(x) SETUP(XfOrM156_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a [0 ] = (Scheme_Object * ) v ; 
  FUNCCALL(SETUP_XfOrM156(_), scheme_wrong_type (">" , "real number" , - 1 , 0 , a ) ); 
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt__int_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  Small_Bignum sb ; 
  return scheme_bignum_gt ((scheme_make_small_bignum ((((long ) (n1 ) ) >> 1 ) , & sb ) ) , (n2 ) ) ; 
}
static inline int scheme_bin_gt__int_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr1 ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sr1.num, 0), PUSH(sr1.denom, 1)));
# define XfOrM158_COUNT (2)
# define SETUP_XfOrM158(x) SETUP(XfOrM158_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr1.num = NULLED_OUT ; 
  sr1.denom = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM158(_), scheme_rational_gt ((scheme_make_small_rational ((((long ) (n1 ) ) >> 1 ) , & sr1 ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt__int_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM159_COUNT (2)
# define SETUP_XfOrM159(x) SETUP(XfOrM159_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM159(_), scheme_bin_gt ((((Scheme_Complex * ) ((scheme_make_small_complex (n1 , & sc ) ) ) ) -> r ) , (((Scheme_Complex * ) ((n2 ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt__dbl_big (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr4 ; 
  Scheme_Object * __funcarg30 = NULLED_OUT ; 
  Scheme_Object * __funcarg29 = NULLED_OUT ; 
  Scheme_Object * __funcarg28 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(__funcarg28, 0), PUSH(sr4.num, 1), PUSH(sr4.denom, 2), PUSH(n2, 3)));
# define XfOrM160_COUNT (4)
# define SETUP_XfOrM160(x) SETUP(XfOrM160_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr4.num = NULLED_OUT ; 
  sr4.denom = NULLED_OUT ; 
  ; 
  if ((isinf (d1 ) && (d1 > 0 ) ) )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  if ((isinf (d1 ) && (d1 < 0 ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  RET_VALUE_START ((__funcarg28 = (__funcarg30 = FUNCCALL(SETUP_XfOrM160(_), scheme_rational_from_double (d1 ) ), FUNCCALL_AGAIN(force_rat (__funcarg30 , & sr4 ) )) , __funcarg29 = FUNCCALL(SETUP_XfOrM160(_), scheme_integer_to_rational (n2 ) ), FUNCCALL_AGAIN(scheme_rational_gt (__funcarg28 , __funcarg29 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt__dbl_rat (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr5 ; 
  Scheme_Object * __funcarg32 = NULLED_OUT ; 
  Scheme_Object * __funcarg31 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(sr5.num, 0), PUSH(sr5.denom, 1), PUSH(n2, 2)));
# define XfOrM161_COUNT (3)
# define SETUP_XfOrM161(x) SETUP(XfOrM161_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr5.num = NULLED_OUT ; 
  sr5.denom = NULLED_OUT ; 
  ; 
  if ((isinf (d1 ) && (d1 > 0 ) ) )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  if ((isinf (d1 ) && (d1 < 0 ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  if (d1 == 0.0 )
    RET_VALUE_START ((scheme_is_negative (n2 ) ) ) RET_VALUE_END ; 
  RET_VALUE_START ((__funcarg31 = (__funcarg32 = FUNCCALL(SETUP_XfOrM161(_), scheme_rational_from_double (d1 ) ), FUNCCALL_AGAIN(force_rat (__funcarg32 , & sr5 ) )) , FUNCCALL_AGAIN(scheme_rational_gt (__funcarg31 , (n2 ) ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt__dbl_comp (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM162_COUNT (2)
# define SETUP_XfOrM162(x) SETUP(XfOrM162_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM162(_), scheme_bin_gt ((((Scheme_Complex * ) ((scheme_make_small_complex (n1 , & sc ) ) ) ) -> r ) , (((Scheme_Complex * ) ((n2 ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt__big_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  Small_Bignum sb ; 
  return scheme_bignum_gt ((n1 ) , (scheme_make_small_bignum ((((long ) (n2 ) ) >> 1 ) , & sb ) ) ) ; 
}
static inline int scheme_bin_gt__big_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  double d2 ; 
  Small_Rational sr7 ; 
  Scheme_Object * __funcarg35 = NULLED_OUT ; 
  Scheme_Object * __funcarg34 = NULLED_OUT ; 
  Scheme_Object * __funcarg33 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(__funcarg33, 0), PUSH(sr7.num, 1), PUSH(sr7.denom, 2)));
# define XfOrM164_COUNT (3)
# define SETUP_XfOrM164(x) SETUP(XfOrM164_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr7.num = NULLED_OUT ; 
  sr7.denom = NULLED_OUT ; 
  d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
  ; 
  if ((isinf (d2 ) && (d2 > 0 ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  if ((isinf (d2 ) && (d2 < 0 ) ) )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  RET_VALUE_START ((__funcarg33 = FUNCCALL(SETUP_XfOrM164(_), scheme_integer_to_rational (n1 ) ), __funcarg34 = (__funcarg35 = FUNCCALL(SETUP_XfOrM164(_), scheme_rational_from_double (d2 ) ), FUNCCALL_AGAIN(force_rat (__funcarg35 , & sr7 ) )) , FUNCCALL_AGAIN(scheme_rational_gt (__funcarg33 , __funcarg34 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt__big_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Scheme_Object * __funcarg36 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(n2, 0)));
# define XfOrM165_COUNT (1)
# define SETUP_XfOrM165(x) SETUP(XfOrM165_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg36 = FUNCCALL(SETUP_XfOrM165(_), scheme_integer_to_rational (n1 ) ), FUNCCALL_EMPTY(scheme_rational_gt (__funcarg36 , (n2 ) ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt__big_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM166_COUNT (2)
# define SETUP_XfOrM166(x) SETUP(XfOrM166_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM166(_), scheme_bin_gt ((((Scheme_Complex * ) ((scheme_make_small_complex (n1 , & sc ) ) ) ) -> r ) , (((Scheme_Complex * ) ((n2 ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt__rat_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr8 ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sr8.num, 0), PUSH(sr8.denom, 1)));
# define XfOrM167_COUNT (2)
# define SETUP_XfOrM167(x) SETUP(XfOrM167_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr8.num = NULLED_OUT ; 
  sr8.denom = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM167(_), scheme_rational_gt ((n1 ) , (scheme_make_small_rational ((((long ) (n2 ) ) >> 1 ) , & sr8 ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt__rat_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  double d2 ; 
  Small_Rational sr10 ; 
  Scheme_Object * __funcarg38 = NULLED_OUT ; 
  Scheme_Object * __funcarg37 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(n1, 0), PUSH(sr10.num, 1), PUSH(sr10.denom, 2)));
# define XfOrM168_COUNT (3)
# define SETUP_XfOrM168(x) SETUP(XfOrM168_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr10.num = NULLED_OUT ; 
  sr10.denom = NULLED_OUT ; 
  d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
  ; 
  if ((isinf (d2 ) && (d2 > 0 ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  if ((isinf (d2 ) && (d2 < 0 ) ) )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  if (d2 == 0.0 )
    RET_VALUE_START ((scheme_is_positive (n1 ) ) ) RET_VALUE_END ; 
  RET_VALUE_START ((__funcarg37 = (__funcarg38 = FUNCCALL(SETUP_XfOrM168(_), scheme_rational_from_double (d2 ) ), FUNCCALL_AGAIN(force_rat (__funcarg38 , & sr10 ) )) , FUNCCALL_AGAIN(scheme_rational_gt ((n1 ) , __funcarg37 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt__rat_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Scheme_Object * __funcarg39 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(n1, 0)));
# define XfOrM169_COUNT (1)
# define SETUP_XfOrM169(x) SETUP(XfOrM169_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg39 = FUNCCALL(SETUP_XfOrM169(_), scheme_integer_to_rational (n2 ) ), FUNCCALL_EMPTY(scheme_rational_gt ((n1 ) , __funcarg39 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt__rat_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM170_COUNT (2)
# define SETUP_XfOrM170(x) SETUP(XfOrM170_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM170(_), scheme_bin_gt ((((Scheme_Complex * ) ((scheme_make_small_complex (n1 , & sc ) ) ) ) -> r ) , (((Scheme_Complex * ) ((n2 ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt__comp_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM171_COUNT (2)
# define SETUP_XfOrM171(x) SETUP(XfOrM171_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM171(_), scheme_bin_gt ((((Scheme_Complex * ) ((n1 ) ) ) -> r ) , (((Scheme_Complex * ) ((scheme_make_small_complex (n2 , & sc ) ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt__comp_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM172_COUNT (2)
# define SETUP_XfOrM172(x) SETUP(XfOrM172_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM172(_), scheme_bin_gt ((((Scheme_Complex * ) ((n1 ) ) ) -> r ) , (((Scheme_Complex * ) ((scheme_make_small_complex (n2 , & sc ) ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt__comp_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM173_COUNT (2)
# define SETUP_XfOrM173(x) SETUP(XfOrM173_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM173(_), scheme_bin_gt ((((Scheme_Complex * ) ((n1 ) ) ) -> r ) , (((Scheme_Complex * ) ((scheme_make_small_complex (n2 , & sc ) ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt__comp_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM174_COUNT (2)
# define SETUP_XfOrM174(x) SETUP(XfOrM174_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM174(_), scheme_bin_gt ((((Scheme_Complex * ) ((n1 ) ) ) -> r ) , (((Scheme_Complex * ) ((scheme_make_small_complex (n2 , & sc ) ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_bin_gt (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  Scheme_Type t1 , t2 ; 
  if ((((long ) (n1 ) ) & 0x1 ) ) {
    if ((((long ) (n2 ) ) & 0x1 ) )
      return ((((long ) (n1 ) ) >> 1 ) > (((long ) (n2 ) ) >> 1 ) ) ; 
    t2 = ((n2 ) -> type ) ; 
    if (t2 == scheme_double_type ) {
      double d = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
      ; 
      return ((((long ) (n1 ) ) >> 1 ) > d ) ; 
    }
    if (t2 == scheme_bignum_type ) {
      return scheme_bin_gt__int_big (n1 , n2 ) ; 
    }
    if (t2 == scheme_rational_type ) {
      return scheme_bin_gt__int_rat (n1 , n2 ) ; 
    }
    if ((t2 == scheme_complex_izi_type ) ) {
      return scheme_bin_gt__int_comp (n1 , n2 ) ; 
    }
    return scheme_bin_gt__wrong_type (n2 ) ; 
  }
  else {
    t1 = ((n1 ) -> type ) ; 
    if (t1 == scheme_double_type ) {
      double d1 = (((Scheme_Double * ) (n1 ) ) -> double_val ) ; 
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        ; 
        return (d1 > (((long ) (n2 ) ) >> 1 ) ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        double d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
        ; 
        ; 
        return (d1 > d2 ) ; 
      }
      if (t2 == scheme_bignum_type ) {
        return scheme_bin_gt__dbl_big (d1 , n1 , n2 ) ; 
      }
      if (t2 == scheme_rational_type ) {
        return scheme_bin_gt__dbl_rat (d1 , n1 , n2 ) ; 
      }
      if ((t2 == scheme_complex_izi_type ) ) {
        return scheme_bin_gt__dbl_comp (d1 , n1 , n2 ) ; 
      }
      return scheme_bin_gt__wrong_type (n2 ) ; 
    }
    else if (t1 == scheme_bignum_type ) {
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        return scheme_bin_gt__big_int (n1 , n2 ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return scheme_bin_gt__big_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return scheme_bignum_gt ((n1 ) , (n2 ) ) ; 
      if (t2 == scheme_rational_type )
        return scheme_bin_gt__big_rat (n1 , n2 ) ; 
      if ((t2 == scheme_complex_izi_type ) ) {
        return scheme_bin_gt__big_comp (n1 , n2 ) ; 
      }
      return scheme_bin_gt__wrong_type (n2 ) ; 
    }
    else if (t1 == scheme_rational_type ) {
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        return scheme_bin_gt__rat_int (n1 , n2 ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return scheme_bin_gt__rat_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return scheme_bin_gt__rat_big (n1 , n2 ) ; 
      if (t2 == scheme_rational_type )
        return scheme_rational_gt ((n1 ) , (n2 ) ) ; 
      if ((t2 == scheme_complex_izi_type ) ) {
        return scheme_bin_gt__rat_comp (n1 , n2 ) ; 
      }
      return scheme_bin_gt__wrong_type (n2 ) ; 
    }
    else if ((t1 == scheme_complex_izi_type ) ) {
      if ((((long ) (n2 ) ) & 0x1 ) )
        return scheme_bin_gt__comp_int (n1 , n2 ) ; 
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return scheme_bin_gt__comp_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return scheme_bin_gt__comp_big (n1 , n2 ) ; 
      if (t2 == scheme_rational_type )
        return scheme_bin_gt__comp_rat (n1 , n2 ) ; 
      if ((t2 == scheme_complex_izi_type ) )
        return scheme_bin_gt ((((Scheme_Complex * ) ((n1 ) ) ) -> r ) , (((Scheme_Complex * ) ((n2 ) ) ) -> r ) ) ; 
      return scheme_bin_gt__wrong_type (n2 ) ; 
    }
    else return scheme_bin_gt__wrong_type (n1 ) ; 
  }
}
int scheme_bin_lt_eq (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
static int scheme_bin_lt_eq__wrong_type (const Scheme_Object * v ) {
  Scheme_Object * a [1 ] ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 1, 0)));
# define XfOrM198_COUNT (3)
# define SETUP_XfOrM198(x) SETUP(XfOrM198_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a [0 ] = (Scheme_Object * ) v ; 
  FUNCCALL(SETUP_XfOrM198(_), scheme_wrong_type ("<=" , "real number" , - 1 , 0 , a ) ); 
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt_eq__int_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  Small_Bignum sb ; 
  return scheme_bignum_le ((scheme_make_small_bignum ((((long ) (n1 ) ) >> 1 ) , & sb ) ) , (n2 ) ) ; 
}
static inline int scheme_bin_lt_eq__int_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr1 ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sr1.num, 0), PUSH(sr1.denom, 1)));
# define XfOrM200_COUNT (2)
# define SETUP_XfOrM200(x) SETUP(XfOrM200_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr1.num = NULLED_OUT ; 
  sr1.denom = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM200(_), scheme_rational_le ((scheme_make_small_rational ((((long ) (n1 ) ) >> 1 ) , & sr1 ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt_eq__int_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM201_COUNT (2)
# define SETUP_XfOrM201(x) SETUP(XfOrM201_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM201(_), scheme_bin_lt_eq ((((Scheme_Complex * ) ((scheme_make_small_complex (n1 , & sc ) ) ) ) -> r ) , (((Scheme_Complex * ) ((n2 ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt_eq__dbl_big (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr4 ; 
  Scheme_Object * __funcarg42 = NULLED_OUT ; 
  Scheme_Object * __funcarg41 = NULLED_OUT ; 
  Scheme_Object * __funcarg40 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(sr4.num, 0), PUSH(sr4.denom, 1), PUSH(__funcarg40, 2), PUSH(n2, 3)));
# define XfOrM202_COUNT (4)
# define SETUP_XfOrM202(x) SETUP(XfOrM202_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr4.num = NULLED_OUT ; 
  sr4.denom = NULLED_OUT ; 
  ; 
  if ((isinf (d1 ) && (d1 > 0 ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  if ((isinf (d1 ) && (d1 < 0 ) ) )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  RET_VALUE_START ((__funcarg40 = (__funcarg42 = FUNCCALL(SETUP_XfOrM202(_), scheme_rational_from_double (d1 ) ), FUNCCALL_AGAIN(force_rat (__funcarg42 , & sr4 ) )) , __funcarg41 = FUNCCALL(SETUP_XfOrM202(_), scheme_integer_to_rational (n2 ) ), FUNCCALL_AGAIN(scheme_rational_le (__funcarg40 , __funcarg41 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt_eq__dbl_rat (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr5 ; 
  Scheme_Object * __funcarg44 = NULLED_OUT ; 
  Scheme_Object * __funcarg43 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(sr5.num, 0), PUSH(sr5.denom, 1), PUSH(n2, 2)));
# define XfOrM203_COUNT (3)
# define SETUP_XfOrM203(x) SETUP(XfOrM203_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr5.num = NULLED_OUT ; 
  sr5.denom = NULLED_OUT ; 
  ; 
  if ((isinf (d1 ) && (d1 > 0 ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  if ((isinf (d1 ) && (d1 < 0 ) ) )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  if (d1 == 0.0 )
    RET_VALUE_START ((scheme_is_positive (n2 ) ) ) RET_VALUE_END ; 
  RET_VALUE_START ((__funcarg43 = (__funcarg44 = FUNCCALL(SETUP_XfOrM203(_), scheme_rational_from_double (d1 ) ), FUNCCALL_AGAIN(force_rat (__funcarg44 , & sr5 ) )) , FUNCCALL_AGAIN(scheme_rational_le (__funcarg43 , (n2 ) ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt_eq__dbl_comp (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM204_COUNT (2)
# define SETUP_XfOrM204(x) SETUP(XfOrM204_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM204(_), scheme_bin_lt_eq ((((Scheme_Complex * ) ((scheme_make_small_complex (n1 , & sc ) ) ) ) -> r ) , (((Scheme_Complex * ) ((n2 ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt_eq__big_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  Small_Bignum sb ; 
  return scheme_bignum_le ((n1 ) , (scheme_make_small_bignum ((((long ) (n2 ) ) >> 1 ) , & sb ) ) ) ; 
}
static inline int scheme_bin_lt_eq__big_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  double d2 ; 
  Small_Rational sr7 ; 
  Scheme_Object * __funcarg47 = NULLED_OUT ; 
  Scheme_Object * __funcarg46 = NULLED_OUT ; 
  Scheme_Object * __funcarg45 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(sr7.num, 0), PUSH(sr7.denom, 1), PUSH(__funcarg45, 2)));
# define XfOrM206_COUNT (3)
# define SETUP_XfOrM206(x) SETUP(XfOrM206_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr7.num = NULLED_OUT ; 
  sr7.denom = NULLED_OUT ; 
  d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
  ; 
  if ((isinf (d2 ) && (d2 > 0 ) ) )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  if ((isinf (d2 ) && (d2 < 0 ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  RET_VALUE_START ((__funcarg45 = FUNCCALL(SETUP_XfOrM206(_), scheme_integer_to_rational (n1 ) ), __funcarg46 = (__funcarg47 = FUNCCALL(SETUP_XfOrM206(_), scheme_rational_from_double (d2 ) ), FUNCCALL_AGAIN(force_rat (__funcarg47 , & sr7 ) )) , FUNCCALL_AGAIN(scheme_rational_le (__funcarg45 , __funcarg46 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt_eq__big_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Scheme_Object * __funcarg48 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(n2, 0)));
# define XfOrM207_COUNT (1)
# define SETUP_XfOrM207(x) SETUP(XfOrM207_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg48 = FUNCCALL(SETUP_XfOrM207(_), scheme_integer_to_rational (n1 ) ), FUNCCALL_EMPTY(scheme_rational_le (__funcarg48 , (n2 ) ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt_eq__big_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM208_COUNT (2)
# define SETUP_XfOrM208(x) SETUP(XfOrM208_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM208(_), scheme_bin_lt_eq ((((Scheme_Complex * ) ((scheme_make_small_complex (n1 , & sc ) ) ) ) -> r ) , (((Scheme_Complex * ) ((n2 ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt_eq__rat_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr8 ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sr8.num, 0), PUSH(sr8.denom, 1)));
# define XfOrM209_COUNT (2)
# define SETUP_XfOrM209(x) SETUP(XfOrM209_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr8.num = NULLED_OUT ; 
  sr8.denom = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM209(_), scheme_rational_le ((n1 ) , (scheme_make_small_rational ((((long ) (n2 ) ) >> 1 ) , & sr8 ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt_eq__rat_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  double d2 ; 
  Small_Rational sr10 ; 
  Scheme_Object * __funcarg50 = NULLED_OUT ; 
  Scheme_Object * __funcarg49 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(n1, 0), PUSH(sr10.num, 1), PUSH(sr10.denom, 2)));
# define XfOrM210_COUNT (3)
# define SETUP_XfOrM210(x) SETUP(XfOrM210_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr10.num = NULLED_OUT ; 
  sr10.denom = NULLED_OUT ; 
  d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
  ; 
  if ((isinf (d2 ) && (d2 > 0 ) ) )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  if ((isinf (d2 ) && (d2 < 0 ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  if (d2 == 0.0 )
    RET_VALUE_START ((scheme_is_negative (n1 ) ) ) RET_VALUE_END ; 
  RET_VALUE_START ((__funcarg49 = (__funcarg50 = FUNCCALL(SETUP_XfOrM210(_), scheme_rational_from_double (d2 ) ), FUNCCALL_AGAIN(force_rat (__funcarg50 , & sr10 ) )) , FUNCCALL_AGAIN(scheme_rational_le ((n1 ) , __funcarg49 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt_eq__rat_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Scheme_Object * __funcarg51 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(n1, 0)));
# define XfOrM211_COUNT (1)
# define SETUP_XfOrM211(x) SETUP(XfOrM211_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg51 = FUNCCALL(SETUP_XfOrM211(_), scheme_integer_to_rational (n2 ) ), FUNCCALL_EMPTY(scheme_rational_le ((n1 ) , __funcarg51 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt_eq__rat_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM212_COUNT (2)
# define SETUP_XfOrM212(x) SETUP(XfOrM212_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM212(_), scheme_bin_lt_eq ((((Scheme_Complex * ) ((scheme_make_small_complex (n1 , & sc ) ) ) ) -> r ) , (((Scheme_Complex * ) ((n2 ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt_eq__comp_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM213_COUNT (2)
# define SETUP_XfOrM213(x) SETUP(XfOrM213_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM213(_), scheme_bin_lt_eq ((((Scheme_Complex * ) ((n1 ) ) ) -> r ) , (((Scheme_Complex * ) ((scheme_make_small_complex (n2 , & sc ) ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt_eq__comp_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM214_COUNT (2)
# define SETUP_XfOrM214(x) SETUP(XfOrM214_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM214(_), scheme_bin_lt_eq ((((Scheme_Complex * ) ((n1 ) ) ) -> r ) , (((Scheme_Complex * ) ((scheme_make_small_complex (n2 , & sc ) ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt_eq__comp_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM215_COUNT (2)
# define SETUP_XfOrM215(x) SETUP(XfOrM215_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM215(_), scheme_bin_lt_eq ((((Scheme_Complex * ) ((n1 ) ) ) -> r ) , (((Scheme_Complex * ) ((scheme_make_small_complex (n2 , & sc ) ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_lt_eq__comp_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM216_COUNT (2)
# define SETUP_XfOrM216(x) SETUP(XfOrM216_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM216(_), scheme_bin_lt_eq ((((Scheme_Complex * ) ((n1 ) ) ) -> r ) , (((Scheme_Complex * ) ((scheme_make_small_complex (n2 , & sc ) ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_bin_lt_eq (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  Scheme_Type t1 , t2 ; 
  if ((((long ) (n1 ) ) & 0x1 ) ) {
    if ((((long ) (n2 ) ) & 0x1 ) )
      return ((((long ) (n1 ) ) >> 1 ) <= (((long ) (n2 ) ) >> 1 ) ) ; 
    t2 = ((n2 ) -> type ) ; 
    if (t2 == scheme_double_type ) {
      double d = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
      ; 
      return ((((long ) (n1 ) ) >> 1 ) <= d ) ; 
    }
    if (t2 == scheme_bignum_type ) {
      return scheme_bin_lt_eq__int_big (n1 , n2 ) ; 
    }
    if (t2 == scheme_rational_type ) {
      return scheme_bin_lt_eq__int_rat (n1 , n2 ) ; 
    }
    if ((t2 == scheme_complex_izi_type ) ) {
      return scheme_bin_lt_eq__int_comp (n1 , n2 ) ; 
    }
    return scheme_bin_lt_eq__wrong_type (n2 ) ; 
  }
  else {
    t1 = ((n1 ) -> type ) ; 
    if (t1 == scheme_double_type ) {
      double d1 = (((Scheme_Double * ) (n1 ) ) -> double_val ) ; 
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        ; 
        return (d1 <= (((long ) (n2 ) ) >> 1 ) ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        double d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
        ; 
        ; 
        return (d1 <= d2 ) ; 
      }
      if (t2 == scheme_bignum_type ) {
        return scheme_bin_lt_eq__dbl_big (d1 , n1 , n2 ) ; 
      }
      if (t2 == scheme_rational_type ) {
        return scheme_bin_lt_eq__dbl_rat (d1 , n1 , n2 ) ; 
      }
      if ((t2 == scheme_complex_izi_type ) ) {
        return scheme_bin_lt_eq__dbl_comp (d1 , n1 , n2 ) ; 
      }
      return scheme_bin_lt_eq__wrong_type (n2 ) ; 
    }
    else if (t1 == scheme_bignum_type ) {
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        return scheme_bin_lt_eq__big_int (n1 , n2 ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return scheme_bin_lt_eq__big_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return scheme_bignum_le ((n1 ) , (n2 ) ) ; 
      if (t2 == scheme_rational_type )
        return scheme_bin_lt_eq__big_rat (n1 , n2 ) ; 
      if ((t2 == scheme_complex_izi_type ) ) {
        return scheme_bin_lt_eq__big_comp (n1 , n2 ) ; 
      }
      return scheme_bin_lt_eq__wrong_type (n2 ) ; 
    }
    else if (t1 == scheme_rational_type ) {
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        return scheme_bin_lt_eq__rat_int (n1 , n2 ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return scheme_bin_lt_eq__rat_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return scheme_bin_lt_eq__rat_big (n1 , n2 ) ; 
      if (t2 == scheme_rational_type )
        return scheme_rational_le ((n1 ) , (n2 ) ) ; 
      if ((t2 == scheme_complex_izi_type ) ) {
        return scheme_bin_lt_eq__rat_comp (n1 , n2 ) ; 
      }
      return scheme_bin_lt_eq__wrong_type (n2 ) ; 
    }
    else if ((t1 == scheme_complex_izi_type ) ) {
      if ((((long ) (n2 ) ) & 0x1 ) )
        return scheme_bin_lt_eq__comp_int (n1 , n2 ) ; 
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return scheme_bin_lt_eq__comp_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return scheme_bin_lt_eq__comp_big (n1 , n2 ) ; 
      if (t2 == scheme_rational_type )
        return scheme_bin_lt_eq__comp_rat (n1 , n2 ) ; 
      if ((t2 == scheme_complex_izi_type ) )
        return scheme_bin_lt_eq ((((Scheme_Complex * ) ((n1 ) ) ) -> r ) , (((Scheme_Complex * ) ((n2 ) ) ) -> r ) ) ; 
      return scheme_bin_lt_eq__wrong_type (n2 ) ; 
    }
    else return scheme_bin_lt_eq__wrong_type (n1 ) ; 
  }
}
int scheme_bin_gt_eq (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
static int scheme_bin_gt_eq__wrong_type (const Scheme_Object * v ) {
  Scheme_Object * a [1 ] ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 1, 0)));
# define XfOrM240_COUNT (3)
# define SETUP_XfOrM240(x) SETUP(XfOrM240_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a [0 ] = (Scheme_Object * ) v ; 
  FUNCCALL(SETUP_XfOrM240(_), scheme_wrong_type (">=" , "real number" , - 1 , 0 , a ) ); 
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt_eq__int_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  Small_Bignum sb ; 
  return scheme_bignum_ge ((scheme_make_small_bignum ((((long ) (n1 ) ) >> 1 ) , & sb ) ) , (n2 ) ) ; 
}
static inline int scheme_bin_gt_eq__int_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr1 ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sr1.num, 0), PUSH(sr1.denom, 1)));
# define XfOrM242_COUNT (2)
# define SETUP_XfOrM242(x) SETUP(XfOrM242_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr1.num = NULLED_OUT ; 
  sr1.denom = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM242(_), scheme_rational_ge ((scheme_make_small_rational ((((long ) (n1 ) ) >> 1 ) , & sr1 ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt_eq__int_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM243_COUNT (2)
# define SETUP_XfOrM243(x) SETUP(XfOrM243_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM243(_), scheme_bin_gt_eq ((((Scheme_Complex * ) ((scheme_make_small_complex (n1 , & sc ) ) ) ) -> r ) , (((Scheme_Complex * ) ((n2 ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt_eq__dbl_big (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr4 ; 
  Scheme_Object * __funcarg54 = NULLED_OUT ; 
  Scheme_Object * __funcarg53 = NULLED_OUT ; 
  Scheme_Object * __funcarg52 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(__funcarg52, 0), PUSH(sr4.num, 1), PUSH(sr4.denom, 2), PUSH(n2, 3)));
# define XfOrM244_COUNT (4)
# define SETUP_XfOrM244(x) SETUP(XfOrM244_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr4.num = NULLED_OUT ; 
  sr4.denom = NULLED_OUT ; 
  ; 
  if ((isinf (d1 ) && (d1 > 0 ) ) )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  if ((isinf (d1 ) && (d1 < 0 ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  RET_VALUE_START ((__funcarg52 = (__funcarg54 = FUNCCALL(SETUP_XfOrM244(_), scheme_rational_from_double (d1 ) ), FUNCCALL_AGAIN(force_rat (__funcarg54 , & sr4 ) )) , __funcarg53 = FUNCCALL(SETUP_XfOrM244(_), scheme_integer_to_rational (n2 ) ), FUNCCALL_AGAIN(scheme_rational_ge (__funcarg52 , __funcarg53 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt_eq__dbl_rat (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr5 ; 
  Scheme_Object * __funcarg56 = NULLED_OUT ; 
  Scheme_Object * __funcarg55 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(sr5.num, 0), PUSH(sr5.denom, 1), PUSH(n2, 2)));
# define XfOrM245_COUNT (3)
# define SETUP_XfOrM245(x) SETUP(XfOrM245_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr5.num = NULLED_OUT ; 
  sr5.denom = NULLED_OUT ; 
  ; 
  if ((isinf (d1 ) && (d1 > 0 ) ) )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  if ((isinf (d1 ) && (d1 < 0 ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  if (d1 == 0.0 )
    RET_VALUE_START ((scheme_is_negative (n2 ) ) ) RET_VALUE_END ; 
  RET_VALUE_START ((__funcarg55 = (__funcarg56 = FUNCCALL(SETUP_XfOrM245(_), scheme_rational_from_double (d1 ) ), FUNCCALL_AGAIN(force_rat (__funcarg56 , & sr5 ) )) , FUNCCALL_AGAIN(scheme_rational_ge (__funcarg55 , (n2 ) ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt_eq__dbl_comp (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM246_COUNT (2)
# define SETUP_XfOrM246(x) SETUP(XfOrM246_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM246(_), scheme_bin_gt_eq ((((Scheme_Complex * ) ((scheme_make_small_complex (n1 , & sc ) ) ) ) -> r ) , (((Scheme_Complex * ) ((n2 ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt_eq__big_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  Small_Bignum sb ; 
  return scheme_bignum_ge ((n1 ) , (scheme_make_small_bignum ((((long ) (n2 ) ) >> 1 ) , & sb ) ) ) ; 
}
static inline int scheme_bin_gt_eq__big_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  double d2 ; 
  Small_Rational sr7 ; 
  Scheme_Object * __funcarg59 = NULLED_OUT ; 
  Scheme_Object * __funcarg58 = NULLED_OUT ; 
  Scheme_Object * __funcarg57 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(__funcarg57, 0), PUSH(sr7.num, 1), PUSH(sr7.denom, 2)));
# define XfOrM248_COUNT (3)
# define SETUP_XfOrM248(x) SETUP(XfOrM248_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr7.num = NULLED_OUT ; 
  sr7.denom = NULLED_OUT ; 
  d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
  ; 
  if ((isinf (d2 ) && (d2 > 0 ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  if ((isinf (d2 ) && (d2 < 0 ) ) )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  RET_VALUE_START ((__funcarg57 = FUNCCALL(SETUP_XfOrM248(_), scheme_integer_to_rational (n1 ) ), __funcarg58 = (__funcarg59 = FUNCCALL(SETUP_XfOrM248(_), scheme_rational_from_double (d2 ) ), FUNCCALL_AGAIN(force_rat (__funcarg59 , & sr7 ) )) , FUNCCALL_AGAIN(scheme_rational_ge (__funcarg57 , __funcarg58 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt_eq__big_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Scheme_Object * __funcarg60 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(n2, 0)));
# define XfOrM249_COUNT (1)
# define SETUP_XfOrM249(x) SETUP(XfOrM249_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg60 = FUNCCALL(SETUP_XfOrM249(_), scheme_integer_to_rational (n1 ) ), FUNCCALL_EMPTY(scheme_rational_ge (__funcarg60 , (n2 ) ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt_eq__big_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM250_COUNT (2)
# define SETUP_XfOrM250(x) SETUP(XfOrM250_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM250(_), scheme_bin_gt_eq ((((Scheme_Complex * ) ((scheme_make_small_complex (n1 , & sc ) ) ) ) -> r ) , (((Scheme_Complex * ) ((n2 ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt_eq__rat_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr8 ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sr8.num, 0), PUSH(sr8.denom, 1)));
# define XfOrM251_COUNT (2)
# define SETUP_XfOrM251(x) SETUP(XfOrM251_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr8.num = NULLED_OUT ; 
  sr8.denom = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM251(_), scheme_rational_ge ((n1 ) , (scheme_make_small_rational ((((long ) (n2 ) ) >> 1 ) , & sr8 ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt_eq__rat_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  double d2 ; 
  Small_Rational sr10 ; 
  Scheme_Object * __funcarg62 = NULLED_OUT ; 
  Scheme_Object * __funcarg61 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(n1, 0), PUSH(sr10.num, 1), PUSH(sr10.denom, 2)));
# define XfOrM252_COUNT (3)
# define SETUP_XfOrM252(x) SETUP(XfOrM252_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr10.num = NULLED_OUT ; 
  sr10.denom = NULLED_OUT ; 
  d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
  ; 
  if ((isinf (d2 ) && (d2 > 0 ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  if ((isinf (d2 ) && (d2 < 0 ) ) )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  if (d2 == 0.0 )
    RET_VALUE_START ((scheme_is_positive (n1 ) ) ) RET_VALUE_END ; 
  RET_VALUE_START ((__funcarg61 = (__funcarg62 = FUNCCALL(SETUP_XfOrM252(_), scheme_rational_from_double (d2 ) ), FUNCCALL_AGAIN(force_rat (__funcarg62 , & sr10 ) )) , FUNCCALL_AGAIN(scheme_rational_ge ((n1 ) , __funcarg61 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt_eq__rat_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Scheme_Object * __funcarg63 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(n1, 0)));
# define XfOrM253_COUNT (1)
# define SETUP_XfOrM253(x) SETUP(XfOrM253_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg63 = FUNCCALL(SETUP_XfOrM253(_), scheme_integer_to_rational (n2 ) ), FUNCCALL_EMPTY(scheme_rational_ge ((n1 ) , __funcarg63 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt_eq__rat_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM254_COUNT (2)
# define SETUP_XfOrM254(x) SETUP(XfOrM254_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM254(_), scheme_bin_gt_eq ((((Scheme_Complex * ) ((scheme_make_small_complex (n1 , & sc ) ) ) ) -> r ) , (((Scheme_Complex * ) ((n2 ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt_eq__comp_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM255_COUNT (2)
# define SETUP_XfOrM255(x) SETUP(XfOrM255_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM255(_), scheme_bin_gt_eq ((((Scheme_Complex * ) ((n1 ) ) ) -> r ) , (((Scheme_Complex * ) ((scheme_make_small_complex (n2 , & sc ) ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt_eq__comp_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM256_COUNT (2)
# define SETUP_XfOrM256(x) SETUP(XfOrM256_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM256(_), scheme_bin_gt_eq ((((Scheme_Complex * ) ((n1 ) ) ) -> r ) , (((Scheme_Complex * ) ((scheme_make_small_complex (n2 , & sc ) ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt_eq__comp_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM257_COUNT (2)
# define SETUP_XfOrM257(x) SETUP(XfOrM257_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM257(_), scheme_bin_gt_eq ((((Scheme_Complex * ) ((n1 ) ) ) -> r ) , (((Scheme_Complex * ) ((scheme_make_small_complex (n2 , & sc ) ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline int scheme_bin_gt_eq__comp_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM258_COUNT (2)
# define SETUP_XfOrM258(x) SETUP(XfOrM258_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM258(_), scheme_bin_gt_eq ((((Scheme_Complex * ) ((n1 ) ) ) -> r ) , (((Scheme_Complex * ) ((scheme_make_small_complex (n2 , & sc ) ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_bin_gt_eq (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  Scheme_Type t1 , t2 ; 
  if ((((long ) (n1 ) ) & 0x1 ) ) {
    if ((((long ) (n2 ) ) & 0x1 ) )
      return ((((long ) (n1 ) ) >> 1 ) >= (((long ) (n2 ) ) >> 1 ) ) ; 
    t2 = ((n2 ) -> type ) ; 
    if (t2 == scheme_double_type ) {
      double d = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
      ; 
      return ((((long ) (n1 ) ) >> 1 ) >= d ) ; 
    }
    if (t2 == scheme_bignum_type ) {
      return scheme_bin_gt_eq__int_big (n1 , n2 ) ; 
    }
    if (t2 == scheme_rational_type ) {
      return scheme_bin_gt_eq__int_rat (n1 , n2 ) ; 
    }
    if ((t2 == scheme_complex_izi_type ) ) {
      return scheme_bin_gt_eq__int_comp (n1 , n2 ) ; 
    }
    return scheme_bin_gt_eq__wrong_type (n2 ) ; 
  }
  else {
    t1 = ((n1 ) -> type ) ; 
    if (t1 == scheme_double_type ) {
      double d1 = (((Scheme_Double * ) (n1 ) ) -> double_val ) ; 
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        ; 
        return (d1 >= (((long ) (n2 ) ) >> 1 ) ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        double d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
        ; 
        ; 
        return (d1 >= d2 ) ; 
      }
      if (t2 == scheme_bignum_type ) {
        return scheme_bin_gt_eq__dbl_big (d1 , n1 , n2 ) ; 
      }
      if (t2 == scheme_rational_type ) {
        return scheme_bin_gt_eq__dbl_rat (d1 , n1 , n2 ) ; 
      }
      if ((t2 == scheme_complex_izi_type ) ) {
        return scheme_bin_gt_eq__dbl_comp (d1 , n1 , n2 ) ; 
      }
      return scheme_bin_gt_eq__wrong_type (n2 ) ; 
    }
    else if (t1 == scheme_bignum_type ) {
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        return scheme_bin_gt_eq__big_int (n1 , n2 ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return scheme_bin_gt_eq__big_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return scheme_bignum_ge ((n1 ) , (n2 ) ) ; 
      if (t2 == scheme_rational_type )
        return scheme_bin_gt_eq__big_rat (n1 , n2 ) ; 
      if ((t2 == scheme_complex_izi_type ) ) {
        return scheme_bin_gt_eq__big_comp (n1 , n2 ) ; 
      }
      return scheme_bin_gt_eq__wrong_type (n2 ) ; 
    }
    else if (t1 == scheme_rational_type ) {
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        return scheme_bin_gt_eq__rat_int (n1 , n2 ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return scheme_bin_gt_eq__rat_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return scheme_bin_gt_eq__rat_big (n1 , n2 ) ; 
      if (t2 == scheme_rational_type )
        return scheme_rational_ge ((n1 ) , (n2 ) ) ; 
      if ((t2 == scheme_complex_izi_type ) ) {
        return scheme_bin_gt_eq__rat_comp (n1 , n2 ) ; 
      }
      return scheme_bin_gt_eq__wrong_type (n2 ) ; 
    }
    else if ((t1 == scheme_complex_izi_type ) ) {
      if ((((long ) (n2 ) ) & 0x1 ) )
        return scheme_bin_gt_eq__comp_int (n1 , n2 ) ; 
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return scheme_bin_gt_eq__comp_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return scheme_bin_gt_eq__comp_big (n1 , n2 ) ; 
      if (t2 == scheme_rational_type )
        return scheme_bin_gt_eq__comp_rat (n1 , n2 ) ; 
      if ((t2 == scheme_complex_izi_type ) )
        return scheme_bin_gt_eq ((((Scheme_Complex * ) ((n1 ) ) ) -> r ) , (((Scheme_Complex * ) ((n2 ) ) ) -> r ) ) ; 
      return scheme_bin_gt_eq__wrong_type (n2 ) ; 
    }
    else return scheme_bin_gt_eq__wrong_type (n1 ) ; 
  }
}
int scheme_is_zero (const Scheme_Object * o ) {
  /* No conversion */
  Scheme_Type t ; 
  top : if ((((long ) (o ) ) & 0x1 ) )
    return o == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
  t = ((o ) -> type ) ; 
  if (t == scheme_double_type ) {
    return (((Scheme_Double * ) (o ) ) -> double_val ) == 0.0 ; 
  }
  if (t == scheme_complex_izi_type ) {
    o = (((Scheme_Complex * ) (o ) ) -> r ) ; 
    goto top ; 
  }
  if ((t >= scheme_bignum_type ) && (t <= scheme_complex_type ) )
    return 0 ; 
  return - 1 ; 
}
Scheme_Object * zero_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  int v ; 
  v = scheme_is_zero (argv [0 ] ) ; 
  if (v < 0 ) {
    scheme_wrong_type ("zero?" , "real number" , 0 , argc , argv ) ; 
    return ((void * ) 0 ) ; 
  }
  return (v ? scheme_true : scheme_false ) ; 
}
int scheme_is_positive (const Scheme_Object * o ) {
  /* No conversion */
  Scheme_Type t ; 
  top : if ((((long ) (o ) ) & 0x1 ) )
    return (((long ) (o ) ) >> 1 ) > 0 ; 
  t = ((o ) -> type ) ; 
  if (t == scheme_double_type ) {
    double d = (((Scheme_Double * ) (o ) ) -> double_val ) ; 
    return d > 0 ; 
  }
  if (t == scheme_bignum_type )
    return ((& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex & 0x1 ) ; 
  if (t == scheme_rational_type )
    return scheme_is_rational_positive (o ) ; 
  if (t == scheme_complex_izi_type ) {
    o = (((Scheme_Complex * ) (o ) ) -> r ) ; 
    goto top ; 
  }
  return - 1 ; 
}
Scheme_Object * positive_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  int v ; 
  v = scheme_is_positive (argv [0 ] ) ; 
  if (v < 0 ) {
    scheme_wrong_type ("positive?" , "real number" , 0 , argc , argv ) ; 
    return ((void * ) 0 ) ; 
  }
  return (v ? scheme_true : scheme_false ) ; 
}
int scheme_is_negative (const Scheme_Object * o ) {
  /* No conversion */
  Scheme_Type t ; 
  top : if ((((long ) (o ) ) & 0x1 ) )
    return (((long ) (o ) ) >> 1 ) < 0 ; 
  t = ((o ) -> type ) ; 
  if (t == scheme_double_type ) {
    double d = (((Scheme_Double * ) (o ) ) -> double_val ) ; 
    return d < 0 ; 
  }
  if (t == scheme_bignum_type )
    return ! ((& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex & 0x1 ) ; 
  if (t == scheme_rational_type )
    return ! scheme_is_rational_positive (o ) ; 
  if (t == scheme_complex_izi_type ) {
    o = (((Scheme_Complex * ) (o ) ) -> r ) ; 
    goto top ; 
  }
  return - 1 ; 
}
Scheme_Object * negative_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  int v ; 
  v = scheme_is_negative (argv [0 ] ) ; 
  if (v < 0 ) {
    scheme_wrong_type ("negative?" , "real number" , 0 , argc , argv ) ; 
    return ((void * ) 0 ) ; 
  }
  return (v ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * bin_max (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
static Scheme_Object * bin_max__wrong_type (const Scheme_Object * v ) {
  Scheme_Object * a [1 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 1, 0)));
# define XfOrM297_COUNT (3)
# define SETUP_XfOrM297(x) SETUP(XfOrM297_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a [0 ] = (Scheme_Object * ) v ; 
  FUNCCALL(SETUP_XfOrM297(_), scheme_wrong_type ("max" , "number" , - 1 , 0 , a ) ); 
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_max__int_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Bignum sb ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(sb.o.digits, 0)));
# define XfOrM298_COUNT (1)
# define SETUP_XfOrM298(x) SETUP(XfOrM298_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sb.o.digits = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM298(_), scheme_bignum_max ((scheme_make_small_bignum ((((long ) (n1 ) ) >> 1 ) , & sb ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_max__int_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr1 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sr1.num, 0), PUSH(sr1.denom, 1)));
# define XfOrM299_COUNT (2)
# define SETUP_XfOrM299(x) SETUP(XfOrM299_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr1.num = NULLED_OUT ; 
  sr1.denom = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM299(_), scheme_rational_max ((scheme_make_small_rational ((((long ) (n1 ) ) >> 1 ) , & sr1 ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_max__int_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM300_COUNT (2)
# define SETUP_XfOrM300(x) SETUP(XfOrM300_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM300(_), bin_max ((((Scheme_Complex * ) ((scheme_make_small_complex (n1 , & sc ) ) ) ) -> r ) , (((Scheme_Complex * ) ((n2 ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_max__dbl_big (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  ; 
  if (isnan (d1 ) )
    return scheme_nan_object ; 
  return scheme_make_double ((d1 > scheme_bignum_to_double (n2 ) ) ? d1 : scheme_bignum_to_double (n2 ) ) ; 
}
static inline Scheme_Object * bin_max__dbl_rat (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  ; 
  if (isnan (d1 ) )
    return scheme_nan_object ; 
  return scheme_make_double ((d1 > scheme_rational_to_double (n2 ) ) ? d1 : scheme_rational_to_double (n2 ) ) ; 
}
static inline Scheme_Object * bin_max__dbl_comp (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM303_COUNT (2)
# define SETUP_XfOrM303(x) SETUP(XfOrM303_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  if (isnan (d1 ) )
    RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM303(_), bin_max ((((Scheme_Complex * ) ((scheme_make_small_complex (n1 , & sc ) ) ) ) -> r ) , (((Scheme_Complex * ) ((n2 ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_max__big_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Bignum sb ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(sb.o.digits, 0)));
# define XfOrM304_COUNT (1)
# define SETUP_XfOrM304(x) SETUP(XfOrM304_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sb.o.digits = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM304(_), scheme_bignum_max ((n1 ) , (scheme_make_small_bignum ((((long ) (n2 ) ) >> 1 ) , & sb ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_max__big_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  double d2 ; 
  ; 
  d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
  if (isnan (d2 ) )
    return scheme_nan_object ; 
  return scheme_make_double ((scheme_bignum_to_double (n1 ) > d2 ) ? scheme_bignum_to_double (n1 ) : d2 ) ; 
}
static inline Scheme_Object * bin_max__big_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Scheme_Object * __funcarg64 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(n2, 0)));
# define XfOrM306_COUNT (1)
# define SETUP_XfOrM306(x) SETUP(XfOrM306_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg64 = FUNCCALL(SETUP_XfOrM306(_), scheme_integer_to_rational (n1 ) ), FUNCCALL_EMPTY(scheme_rational_max (__funcarg64 , (n2 ) ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_max__big_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM307_COUNT (2)
# define SETUP_XfOrM307(x) SETUP(XfOrM307_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM307(_), bin_max ((((Scheme_Complex * ) ((scheme_make_small_complex (n1 , & sc ) ) ) ) -> r ) , (((Scheme_Complex * ) ((n2 ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_max__rat_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr8 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sr8.num, 0), PUSH(sr8.denom, 1)));
# define XfOrM308_COUNT (2)
# define SETUP_XfOrM308(x) SETUP(XfOrM308_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr8.num = NULLED_OUT ; 
  sr8.denom = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM308(_), scheme_rational_max ((n1 ) , (scheme_make_small_rational ((((long ) (n2 ) ) >> 1 ) , & sr8 ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_max__rat_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  double d2 ; 
  ; 
  d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
  if (isnan (d2 ) )
    return scheme_nan_object ; 
  return scheme_make_double ((scheme_rational_to_double (n1 ) > d2 ) ? scheme_rational_to_double (n1 ) : d2 ) ; 
}
static inline Scheme_Object * bin_max__rat_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Scheme_Object * __funcarg65 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(n1, 0)));
# define XfOrM310_COUNT (1)
# define SETUP_XfOrM310(x) SETUP(XfOrM310_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg65 = FUNCCALL(SETUP_XfOrM310(_), scheme_integer_to_rational (n2 ) ), FUNCCALL_EMPTY(scheme_rational_max ((n1 ) , __funcarg65 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_max__rat_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM311_COUNT (2)
# define SETUP_XfOrM311(x) SETUP(XfOrM311_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM311(_), bin_max ((((Scheme_Complex * ) ((scheme_make_small_complex (n1 , & sc ) ) ) ) -> r ) , (((Scheme_Complex * ) ((n2 ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_max__comp_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM312_COUNT (2)
# define SETUP_XfOrM312(x) SETUP(XfOrM312_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM312(_), bin_max ((((Scheme_Complex * ) ((n1 ) ) ) -> r ) , (((Scheme_Complex * ) ((scheme_make_small_complex (n2 , & sc ) ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_max__comp_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM313_COUNT (2)
# define SETUP_XfOrM313(x) SETUP(XfOrM313_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  if (isnan ((((Scheme_Double * ) (n2 ) ) -> double_val ) ) )
    RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM313(_), bin_max ((((Scheme_Complex * ) ((n1 ) ) ) -> r ) , (((Scheme_Complex * ) ((scheme_make_small_complex (n2 , & sc ) ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_max__comp_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM314_COUNT (2)
# define SETUP_XfOrM314(x) SETUP(XfOrM314_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM314(_), bin_max ((((Scheme_Complex * ) ((n1 ) ) ) -> r ) , (((Scheme_Complex * ) ((scheme_make_small_complex (n2 , & sc ) ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_max__comp_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM315_COUNT (2)
# define SETUP_XfOrM315(x) SETUP(XfOrM315_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM315(_), bin_max ((((Scheme_Complex * ) ((n1 ) ) ) -> r ) , (((Scheme_Complex * ) ((scheme_make_small_complex (n2 , & sc ) ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * bin_max (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  Scheme_Type t1 , t2 ; 
  if ((((long ) (n1 ) ) & 0x1 ) ) {
    if ((((long ) (n2 ) ) & 0x1 ) )
      return ((Scheme_Object * ) (void * ) (long ) ((((long ) (((((long ) (n1 ) ) >> 1 ) > (((long ) (n2 ) ) >> 1 ) ) ? (((long ) (n1 ) ) >> 1 ) : (((long ) (n2 ) ) >> 1 ) ) ) << 1 ) | 0x1 ) ) ; 
    t2 = ((n2 ) -> type ) ; 
    if (t2 == scheme_double_type ) {
      double d = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
      if (isnan (d ) )
        return scheme_nan_object ; 
      return scheme_make_double (((((long ) (n1 ) ) >> 1 ) > d ) ? (((long ) (n1 ) ) >> 1 ) : d ) ; 
    }
    if (t2 == scheme_bignum_type ) {
      return bin_max__int_big (n1 , n2 ) ; 
    }
    if (t2 == scheme_rational_type ) {
      return bin_max__int_rat (n1 , n2 ) ; 
    }
    if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
      return bin_max__int_comp (n1 , n2 ) ; 
    }
    return bin_max__wrong_type (n2 ) ; 
  }
  else {
    t1 = ((n1 ) -> type ) ; 
    if (t1 == scheme_double_type ) {
      double d1 = (((Scheme_Double * ) (n1 ) ) -> double_val ) ; 
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        if (isnan (d1 ) )
          return scheme_nan_object ; 
        return scheme_make_double ((d1 > (((long ) (n2 ) ) >> 1 ) ) ? d1 : (((long ) (n2 ) ) >> 1 ) ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        double d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
        if (isnan (d1 ) )
          return scheme_nan_object ; 
        if (isnan (d2 ) )
          return scheme_nan_object ; 
        return scheme_make_double ((d1 > d2 ) ? d1 : d2 ) ; 
      }
      if (t2 == scheme_bignum_type ) {
        return bin_max__dbl_big (d1 , n1 , n2 ) ; 
      }
      if (t2 == scheme_rational_type ) {
        return bin_max__dbl_rat (d1 , n1 , n2 ) ; 
      }
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
        return bin_max__dbl_comp (d1 , n1 , n2 ) ; 
      }
      return bin_max__wrong_type (n2 ) ; 
    }
    else if (t1 == scheme_bignum_type ) {
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        return bin_max__big_int (n1 , n2 ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return bin_max__big_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return scheme_bignum_max ((n1 ) , (n2 ) ) ; 
      if (t2 == scheme_rational_type )
        return bin_max__big_rat (n1 , n2 ) ; 
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
        return bin_max__big_comp (n1 , n2 ) ; 
      }
      return bin_max__wrong_type (n2 ) ; 
    }
    else if (t1 == scheme_rational_type ) {
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        return bin_max__rat_int (n1 , n2 ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return bin_max__rat_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return bin_max__rat_big (n1 , n2 ) ; 
      if (t2 == scheme_rational_type )
        return scheme_rational_max ((n1 ) , (n2 ) ) ; 
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
        return bin_max__rat_comp (n1 , n2 ) ; 
      }
      return bin_max__wrong_type (n2 ) ; 
    }
    else if ((t1 == scheme_complex_type ) || (t1 == scheme_complex_izi_type ) ) {
      if ((((long ) (n2 ) ) & 0x1 ) )
        return bin_max__comp_int (n1 , n2 ) ; 
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return bin_max__comp_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return bin_max__comp_big (n1 , n2 ) ; 
      if (t2 == scheme_rational_type )
        return bin_max__comp_rat (n1 , n2 ) ; 
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) )
        return bin_max ((((Scheme_Complex * ) ((n1 ) ) ) -> r ) , (((Scheme_Complex * ) ((n2 ) ) ) -> r ) ) ; 
      return bin_max__wrong_type (n2 ) ; 
    }
    else return bin_max__wrong_type (n1 ) ; 
  }
}
static Scheme_Object * bin_min (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
static Scheme_Object * bin_min__wrong_type (const Scheme_Object * v ) {
  Scheme_Object * a [1 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 1, 0)));
# define XfOrM339_COUNT (3)
# define SETUP_XfOrM339(x) SETUP(XfOrM339_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a [0 ] = (Scheme_Object * ) v ; 
  FUNCCALL(SETUP_XfOrM339(_), scheme_wrong_type ("min" , "number" , - 1 , 0 , a ) ); 
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_min__int_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Bignum sb ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(sb.o.digits, 0)));
# define XfOrM340_COUNT (1)
# define SETUP_XfOrM340(x) SETUP(XfOrM340_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sb.o.digits = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM340(_), scheme_bignum_min ((scheme_make_small_bignum ((((long ) (n1 ) ) >> 1 ) , & sb ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_min__int_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr1 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sr1.num, 0), PUSH(sr1.denom, 1)));
# define XfOrM341_COUNT (2)
# define SETUP_XfOrM341(x) SETUP(XfOrM341_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr1.num = NULLED_OUT ; 
  sr1.denom = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM341(_), scheme_rational_min ((scheme_make_small_rational ((((long ) (n1 ) ) >> 1 ) , & sr1 ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_min__int_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM342_COUNT (2)
# define SETUP_XfOrM342(x) SETUP(XfOrM342_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM342(_), bin_min ((((Scheme_Complex * ) ((scheme_make_small_complex (n1 , & sc ) ) ) ) -> r ) , (((Scheme_Complex * ) ((n2 ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_min__dbl_big (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  ; 
  if (isnan (d1 ) )
    return scheme_nan_object ; 
  return scheme_make_double ((d1 < scheme_bignum_to_double (n2 ) ) ? d1 : scheme_bignum_to_double (n2 ) ) ; 
}
static inline Scheme_Object * bin_min__dbl_rat (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  ; 
  if (isnan (d1 ) )
    return scheme_nan_object ; 
  return scheme_make_double ((d1 < scheme_rational_to_double (n2 ) ) ? d1 : scheme_rational_to_double (n2 ) ) ; 
}
static inline Scheme_Object * bin_min__dbl_comp (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM345_COUNT (2)
# define SETUP_XfOrM345(x) SETUP(XfOrM345_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  if (isnan (d1 ) )
    RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM345(_), bin_min ((((Scheme_Complex * ) ((scheme_make_small_complex (n1 , & sc ) ) ) ) -> r ) , (((Scheme_Complex * ) ((n2 ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_min__big_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Bignum sb ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(sb.o.digits, 0)));
# define XfOrM346_COUNT (1)
# define SETUP_XfOrM346(x) SETUP(XfOrM346_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sb.o.digits = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM346(_), scheme_bignum_min ((n1 ) , (scheme_make_small_bignum ((((long ) (n2 ) ) >> 1 ) , & sb ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_min__big_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  double d2 ; 
  ; 
  d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
  if (isnan (d2 ) )
    return scheme_nan_object ; 
  return scheme_make_double ((scheme_bignum_to_double (n1 ) < d2 ) ? scheme_bignum_to_double (n1 ) : d2 ) ; 
}
static inline Scheme_Object * bin_min__big_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Scheme_Object * __funcarg66 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(n2, 0)));
# define XfOrM348_COUNT (1)
# define SETUP_XfOrM348(x) SETUP(XfOrM348_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg66 = FUNCCALL(SETUP_XfOrM348(_), scheme_integer_to_rational (n1 ) ), FUNCCALL_EMPTY(scheme_rational_min (__funcarg66 , (n2 ) ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_min__big_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM349_COUNT (2)
# define SETUP_XfOrM349(x) SETUP(XfOrM349_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM349(_), bin_min ((((Scheme_Complex * ) ((scheme_make_small_complex (n1 , & sc ) ) ) ) -> r ) , (((Scheme_Complex * ) ((n2 ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_min__rat_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr8 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sr8.num, 0), PUSH(sr8.denom, 1)));
# define XfOrM350_COUNT (2)
# define SETUP_XfOrM350(x) SETUP(XfOrM350_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr8.num = NULLED_OUT ; 
  sr8.denom = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM350(_), scheme_rational_min ((n1 ) , (scheme_make_small_rational ((((long ) (n2 ) ) >> 1 ) , & sr8 ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_min__rat_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  double d2 ; 
  ; 
  d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
  if (isnan (d2 ) )
    return scheme_nan_object ; 
  return scheme_make_double ((scheme_rational_to_double (n1 ) < d2 ) ? scheme_rational_to_double (n1 ) : d2 ) ; 
}
static inline Scheme_Object * bin_min__rat_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Scheme_Object * __funcarg67 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(n1, 0)));
# define XfOrM352_COUNT (1)
# define SETUP_XfOrM352(x) SETUP(XfOrM352_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg67 = FUNCCALL(SETUP_XfOrM352(_), scheme_integer_to_rational (n2 ) ), FUNCCALL_EMPTY(scheme_rational_min ((n1 ) , __funcarg67 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_min__rat_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM353_COUNT (2)
# define SETUP_XfOrM353(x) SETUP(XfOrM353_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM353(_), bin_min ((((Scheme_Complex * ) ((scheme_make_small_complex (n1 , & sc ) ) ) ) -> r ) , (((Scheme_Complex * ) ((n2 ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_min__comp_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM354_COUNT (2)
# define SETUP_XfOrM354(x) SETUP(XfOrM354_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM354(_), bin_min ((((Scheme_Complex * ) ((n1 ) ) ) -> r ) , (((Scheme_Complex * ) ((scheme_make_small_complex (n2 , & sc ) ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_min__comp_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM355_COUNT (2)
# define SETUP_XfOrM355(x) SETUP(XfOrM355_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  if (isnan ((((Scheme_Double * ) (n2 ) ) -> double_val ) ) )
    RET_VALUE_START (scheme_nan_object ) RET_VALUE_END ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM355(_), bin_min ((((Scheme_Complex * ) ((n1 ) ) ) -> r ) , (((Scheme_Complex * ) ((scheme_make_small_complex (n2 , & sc ) ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_min__comp_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM356_COUNT (2)
# define SETUP_XfOrM356(x) SETUP(XfOrM356_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM356(_), bin_min ((((Scheme_Complex * ) ((n1 ) ) ) -> r ) , (((Scheme_Complex * ) ((scheme_make_small_complex (n2 , & sc ) ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * bin_min__comp_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM357_COUNT (2)
# define SETUP_XfOrM357(x) SETUP(XfOrM357_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM357(_), bin_min ((((Scheme_Complex * ) ((n1 ) ) ) -> r ) , (((Scheme_Complex * ) ((scheme_make_small_complex (n2 , & sc ) ) ) ) -> r ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * bin_min (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  Scheme_Type t1 , t2 ; 
  if ((((long ) (n1 ) ) & 0x1 ) ) {
    if ((((long ) (n2 ) ) & 0x1 ) )
      return ((Scheme_Object * ) (void * ) (long ) ((((long ) (((((long ) (n1 ) ) >> 1 ) < (((long ) (n2 ) ) >> 1 ) ) ? (((long ) (n1 ) ) >> 1 ) : (((long ) (n2 ) ) >> 1 ) ) ) << 1 ) | 0x1 ) ) ; 
    t2 = ((n2 ) -> type ) ; 
    if (t2 == scheme_double_type ) {
      double d = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
      if (isnan (d ) )
        return scheme_nan_object ; 
      return scheme_make_double (((((long ) (n1 ) ) >> 1 ) < d ) ? (((long ) (n1 ) ) >> 1 ) : d ) ; 
    }
    if (t2 == scheme_bignum_type ) {
      return bin_min__int_big (n1 , n2 ) ; 
    }
    if (t2 == scheme_rational_type ) {
      return bin_min__int_rat (n1 , n2 ) ; 
    }
    if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
      return bin_min__int_comp (n1 , n2 ) ; 
    }
    return bin_min__wrong_type (n2 ) ; 
  }
  else {
    t1 = ((n1 ) -> type ) ; 
    if (t1 == scheme_double_type ) {
      double d1 = (((Scheme_Double * ) (n1 ) ) -> double_val ) ; 
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        if (isnan (d1 ) )
          return scheme_nan_object ; 
        return scheme_make_double ((d1 < (((long ) (n2 ) ) >> 1 ) ) ? d1 : (((long ) (n2 ) ) >> 1 ) ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        double d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
        if (isnan (d1 ) )
          return scheme_nan_object ; 
        if (isnan (d2 ) )
          return scheme_nan_object ; 
        return scheme_make_double ((d1 < d2 ) ? d1 : d2 ) ; 
      }
      if (t2 == scheme_bignum_type ) {
        return bin_min__dbl_big (d1 , n1 , n2 ) ; 
      }
      if (t2 == scheme_rational_type ) {
        return bin_min__dbl_rat (d1 , n1 , n2 ) ; 
      }
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
        return bin_min__dbl_comp (d1 , n1 , n2 ) ; 
      }
      return bin_min__wrong_type (n2 ) ; 
    }
    else if (t1 == scheme_bignum_type ) {
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        return bin_min__big_int (n1 , n2 ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return bin_min__big_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return scheme_bignum_min ((n1 ) , (n2 ) ) ; 
      if (t2 == scheme_rational_type )
        return bin_min__big_rat (n1 , n2 ) ; 
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
        return bin_min__big_comp (n1 , n2 ) ; 
      }
      return bin_min__wrong_type (n2 ) ; 
    }
    else if (t1 == scheme_rational_type ) {
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        return bin_min__rat_int (n1 , n2 ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return bin_min__rat_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return bin_min__rat_big (n1 , n2 ) ; 
      if (t2 == scheme_rational_type )
        return scheme_rational_min ((n1 ) , (n2 ) ) ; 
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
        return bin_min__rat_comp (n1 , n2 ) ; 
      }
      return bin_min__wrong_type (n2 ) ; 
    }
    else if ((t1 == scheme_complex_type ) || (t1 == scheme_complex_izi_type ) ) {
      if ((((long ) (n2 ) ) & 0x1 ) )
        return bin_min__comp_int (n1 , n2 ) ; 
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return bin_min__comp_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return bin_min__comp_big (n1 , n2 ) ; 
      if (t2 == scheme_rational_type )
        return bin_min__comp_rat (n1 , n2 ) ; 
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) )
        return bin_min ((((Scheme_Complex * ) ((n1 ) ) ) -> r ) , (((Scheme_Complex * ) ((n2 ) ) ) -> r ) ) ; 
      return bin_min__wrong_type (n2 ) ; 
    }
    else return bin_min__wrong_type (n1 ) ; 
  }
}
static Scheme_Object * sch_max (int argc , Scheme_Object * argv [] ) ; 
static inline Scheme_Object * sch_max__slow (Scheme_Object * ret , int argc , Scheme_Object * argv [] ) {
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(ret, 0), PUSH(argv, 1)));
# define XfOrM381_COUNT (2)
# define SETUP_XfOrM381(x) SETUP(XfOrM381_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  for (i = 1 ; i < argc ; ++ i ) {
#   define XfOrM383_COUNT (0+XfOrM381_COUNT)
#   define SETUP_XfOrM383(x) SETUP_XfOrM381(x)
    if (! ((((long ) (argv [i ] ) ) & 0x1 ) || ((((argv [i ] ) -> type ) >= scheme_bignum_type ) && (((argv [i ] ) -> type ) <= scheme_complex_izi_type ) ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("max" , "real number" , i , argc , argv ) ); 
    ret = FUNCCALL(SETUP_XfOrM383(_), bin_max (ret , argv [i ] ) ); 
  }
  RET_VALUE_START (ret ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * sch_max (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * ret = argv [0 ] ; 
  if (! ((((long ) (ret ) ) & 0x1 ) || ((((ret ) -> type ) >= scheme_bignum_type ) && (((ret ) -> type ) <= scheme_complex_izi_type ) ) ) )
    scheme_wrong_type ("max" , "real number" , 0 , argc , argv ) ; 
  if (argc == 1 )
    return ret ; 
  if (argc == 2 ) {
    if (! ((((long ) (argv [1 ] ) ) & 0x1 ) || ((((argv [1 ] ) -> type ) >= scheme_bignum_type ) && (((argv [1 ] ) -> type ) <= scheme_complex_izi_type ) ) ) )
      scheme_wrong_type ("max" , "real number" , 1 , argc , argv ) ; 
    return bin_max (ret , argv [1 ] ) ; 
  }
  return sch_max__slow (ret , argc , argv ) ; 
}
static Scheme_Object * sch_min (int argc , Scheme_Object * argv [] ) ; 
static inline Scheme_Object * sch_min__slow (Scheme_Object * ret , int argc , Scheme_Object * argv [] ) {
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(ret, 0), PUSH(argv, 1)));
# define XfOrM386_COUNT (2)
# define SETUP_XfOrM386(x) SETUP(XfOrM386_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  for (i = 1 ; i < argc ; ++ i ) {
#   define XfOrM388_COUNT (0+XfOrM386_COUNT)
#   define SETUP_XfOrM388(x) SETUP_XfOrM386(x)
    if (! ((((long ) (argv [i ] ) ) & 0x1 ) || ((((argv [i ] ) -> type ) >= scheme_bignum_type ) && (((argv [i ] ) -> type ) <= scheme_complex_izi_type ) ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("min" , "real number" , i , argc , argv ) ); 
    ret = FUNCCALL(SETUP_XfOrM388(_), bin_min (ret , argv [i ] ) ); 
  }
  RET_VALUE_START (ret ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * sch_min (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * ret = argv [0 ] ; 
  if (! ((((long ) (ret ) ) & 0x1 ) || ((((ret ) -> type ) >= scheme_bignum_type ) && (((ret ) -> type ) <= scheme_complex_izi_type ) ) ) )
    scheme_wrong_type ("min" , "real number" , 0 , argc , argv ) ; 
  if (argc == 1 )
    return ret ; 
  if (argc == 2 ) {
    if (! ((((long ) (argv [1 ] ) ) & 0x1 ) || ((((argv [1 ] ) -> type ) >= scheme_bignum_type ) && (((argv [1 ] ) -> type ) <= scheme_complex_izi_type ) ) ) )
      scheme_wrong_type ("min" , "real number" , 1 , argc , argv ) ; 
    return bin_min (ret , argv [1 ] ) ; 
  }
  return sch_min__slow (ret , argc , argv ) ; 
}
