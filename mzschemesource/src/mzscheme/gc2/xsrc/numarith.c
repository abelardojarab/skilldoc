#include "precomp.h"
extern double exp (double __x ) __attribute__ ((__nothrow__ ) ) ; 
extern double ceil (double __x ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__const__ ) ) ; 
extern double fabs (double __x ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__const__ ) ) ; 
extern double floor (double __x ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__const__ ) ) ; 
extern double fmod (double __x , double __y ) __attribute__ ((__nothrow__ ) ) ; 
extern int isinf (double __value ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__const__ ) ) ; 
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
static Scheme_Object * plus (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * minus (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * mult (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * div_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * quotient (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * rem_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * quotient_remainder (int argc , Scheme_Object * argv [] ) ; 
void scheme_init_numarith (Scheme_Env * env ) {
  Scheme_Object * p ; 
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
  p = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (scheme_add1 , "add1" , 1 , 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 16384 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("add1" , p , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_folding_prim (scheme_sub1 , "sub1" , 1 , 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 16384 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("sub1" , p , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_folding_prim (plus , "+" , 0 , - 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 512 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("+" , p , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_folding_prim (minus , "-" , 1 , - 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 512 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("-" , p , env ) ); 
  (__funcarg10 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (mult , "*" , 0 , - 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("*" , __funcarg10 , env ) )) ; 
  (__funcarg9 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (div_prim , "/" , 1 , - 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("/" , __funcarg9 , env ) )) ; 
  (__funcarg8 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (scheme_abs , "abs" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("abs" , __funcarg8 , env ) )) ; 
  (__funcarg7 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (quotient , "quotient" , 2 , 2 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("quotient" , __funcarg7 , env ) )) ; 
  (__funcarg6 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (rem_prim , "remainder" , 2 , 2 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("remainder" , __funcarg6 , env ) )) ; 
  (__funcarg5 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_everything (quotient_remainder , 0 , "quotient/remainder" , 2 , 2 , 0 , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("quotient/remainder" , __funcarg5 , env ) )) ; 
  (__funcarg4 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (scheme_modulo , "modulo" , 2 , 2 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("modulo" , __funcarg4 , env ) )) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_add1 (int argc , Scheme_Object * argv [] ) {
  Scheme_Type t ; 
  Scheme_Object * o = argv [0 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(o, 1)));
# define XfOrM2_COUNT (2)
# define SETUP_XfOrM2(x) SETUP(XfOrM2_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((((long ) (o ) ) & 0x1 ) ) {
    long v ; 
#   define XfOrM3_COUNT (0+XfOrM2_COUNT)
#   define SETUP_XfOrM3(x) SETUP_XfOrM2(x)
    v = (((long ) (o ) ) >> 1 ) ; 
    if (v < 0x3FFFFFFF )
      RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (v + 1 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
    else {
      Small_Bignum b ; 
      BLOCK_SETUP((PUSH(b.o.digits, 0+XfOrM3_COUNT)));
#     define XfOrM4_COUNT (1+XfOrM3_COUNT)
#     define SETUP_XfOrM4(x) SETUP(XfOrM4_COUNT)
      b.o.digits = NULLED_OUT ; 
      RET_VALUE_START (FUNCCALL(SETUP_XfOrM4(_), scheme_bignum_add1 (scheme_make_small_bignum (v , & b ) ) )) RET_VALUE_END ; 
    }
  }
  t = ((o ) -> type ) ; 
  if (t == scheme_double_type )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_double ((((Scheme_Double * ) (o ) ) -> double_val ) + 1.0 ) )) RET_VALUE_EMPTY_END ; 
  if (t == scheme_bignum_type )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_bignum_add1 (o ) )) RET_VALUE_EMPTY_END ; 
  if (t == scheme_rational_type )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_rational_add1 (o ) )) RET_VALUE_EMPTY_END ; 
  if ((t == scheme_complex_type ) || (t == scheme_complex_izi_type ) )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_complex_add1 (o ) )) RET_VALUE_EMPTY_END ; 
  FUNCCALL_EMPTY(scheme_wrong_type ("add1" , "number" , 0 , argc , argv ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_sub1 (int argc , Scheme_Object * argv [] ) {
  Scheme_Type t ; 
  Scheme_Object * o = argv [0 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(o, 1)));
# define XfOrM5_COUNT (2)
# define SETUP_XfOrM5(x) SETUP(XfOrM5_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((((long ) (o ) ) & 0x1 ) ) {
    long v ; 
#   define XfOrM6_COUNT (0+XfOrM5_COUNT)
#   define SETUP_XfOrM6(x) SETUP_XfOrM5(x)
    v = (((long ) (o ) ) >> 1 ) ; 
    if (v > - (0x3FFFFFFF ) )
      RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) ((((long ) (o ) ) >> 1 ) - 1 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
    else {
      Small_Bignum b ; 
      BLOCK_SETUP((PUSH(b.o.digits, 0+XfOrM6_COUNT)));
#     define XfOrM7_COUNT (1+XfOrM6_COUNT)
#     define SETUP_XfOrM7(x) SETUP(XfOrM7_COUNT)
      b.o.digits = NULLED_OUT ; 
      RET_VALUE_START (FUNCCALL(SETUP_XfOrM7(_), scheme_bignum_sub1 (scheme_make_small_bignum (v , & b ) ) )) RET_VALUE_END ; 
    }
  }
  t = ((o ) -> type ) ; 
  if (t == scheme_double_type )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_double ((((Scheme_Double * ) (o ) ) -> double_val ) - 1.0 ) )) RET_VALUE_EMPTY_END ; 
  if (t == scheme_bignum_type )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_bignum_sub1 (o ) )) RET_VALUE_EMPTY_END ; 
  if (t == scheme_rational_type )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_rational_sub1 (o ) )) RET_VALUE_EMPTY_END ; 
  if ((t == scheme_complex_type ) || (t == scheme_complex_izi_type ) )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_complex_sub1 (o ) )) RET_VALUE_EMPTY_END ; 
  FUNCCALL_EMPTY(scheme_wrong_type ("sub1" , "number" , 0 , argc , argv ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * ADD_slow (long a , long b ) {
  Small_Bignum sa , sb ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sb.o.digits, 0), PUSH(sa.o.digits, 1)));
# define XfOrM8_COUNT (2)
# define SETUP_XfOrM8(x) SETUP(XfOrM8_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sa.o.digits = NULLED_OUT ; 
  sb.o.digits = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM8(_), scheme_bignum_add (scheme_make_small_bignum (a , & sa ) , scheme_make_small_bignum (b , & sb ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * ADD (long a , long b ) {
  /* No conversion */
  long r ; 
  Scheme_Object * o ; 
  r = a + b ; 
  o = ((Scheme_Object * ) (void * ) (long ) ((((long ) (r ) ) << 1 ) | 0x1 ) ) ; 
  r = (((long ) (o ) ) >> 1 ) ; 
  if (b == r - a )
    return o ; 
  else return ADD_slow (a , b ) ; 
}
static Scheme_Object * SUBTRACT_slow (long a , long b ) {
  Small_Bignum sa , sb ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sb.o.digits, 0), PUSH(sa.o.digits, 1)));
# define XfOrM10_COUNT (2)
# define SETUP_XfOrM10(x) SETUP(XfOrM10_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sa.o.digits = NULLED_OUT ; 
  sb.o.digits = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM10(_), scheme_bignum_subtract (scheme_make_small_bignum (a , & sa ) , scheme_make_small_bignum (b , & sb ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * SUBTRACT (long a , long b ) {
  /* No conversion */
  long r ; 
  Scheme_Object * o ; 
  r = a - b ; 
  o = ((Scheme_Object * ) (void * ) (long ) ((((long ) (r ) ) << 1 ) | 0x1 ) ) ; 
  r = (((long ) (o ) ) >> 1 ) ; 
  if (a == r + b )
    return o ; 
  else return SUBTRACT_slow (a , b ) ; 
}
static Scheme_Object * MULTIPLY (long a , long b ) {
  long r ; 
  Scheme_Object * o ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(2);
# define XfOrM12_COUNT (0)
# define SETUP_XfOrM12(x) SETUP(XfOrM12_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  o = NULLED_OUT ; 
  if (! b )
    RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
  r = a * b ; 
  o = ((Scheme_Object * ) (void * ) (long ) ((((long ) (r ) ) << 1 ) | 0x1 ) ) ; 
  r = (((long ) (o ) ) >> 1 ) ; 
  if (a == r / b )
    RET_VALUE_START (o ) RET_VALUE_END ; 
  else {
    Small_Bignum sa , sb ; 
    BLOCK_SETUP((PUSH(sb.o.digits, 0+XfOrM12_COUNT), PUSH(sa.o.digits, 1+XfOrM12_COUNT)));
#   define XfOrM13_COUNT (2+XfOrM12_COUNT)
#   define SETUP_XfOrM13(x) SETUP(XfOrM13_COUNT)
    sa.o.digits = NULLED_OUT ; 
    sb.o.digits = NULLED_OUT ; 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM13(_), scheme_bignum_multiply (scheme_make_small_bignum (a , & sa ) , scheme_make_small_bignum (b , & sb ) ) )) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * unary_minus (const Scheme_Object * n ) {
  Scheme_Object * a [1 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 1, 0)));
# define XfOrM14_COUNT (3)
# define SETUP_XfOrM14(x) SETUP(XfOrM14_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a [0 ] = (Scheme_Object * ) n ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM14(_), minus (1 , a ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_bin_plus (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
static Scheme_Object * scheme_bin_plus__wrong_type (const Scheme_Object * v ) {
  Scheme_Object * a [1 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 1, 0)));
# define XfOrM15_COUNT (3)
# define SETUP_XfOrM15(x) SETUP(XfOrM15_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a [0 ] = (Scheme_Object * ) v ; 
  FUNCCALL(SETUP_XfOrM15(_), scheme_wrong_type ("+" , "number" , - 1 , 0 , a ) ); 
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_plus__int_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Bignum sb ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(sb.o.digits, 0)));
# define XfOrM16_COUNT (1)
# define SETUP_XfOrM16(x) SETUP(XfOrM16_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sb.o.digits = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM16(_), scheme_bignum_add ((scheme_make_small_bignum ((((long ) (n1 ) ) >> 1 ) , & sb ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_plus__int_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr1 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sr1.num, 0), PUSH(sr1.denom, 1)));
# define XfOrM17_COUNT (2)
# define SETUP_XfOrM17(x) SETUP(XfOrM17_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr1.num = NULLED_OUT ; 
  sr1.denom = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM17(_), scheme_rational_add ((scheme_make_small_rational ((((long ) (n1 ) ) >> 1 ) , & sr1 ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_plus__int_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM18_COUNT (2)
# define SETUP_XfOrM18(x) SETUP(XfOrM18_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM18(_), scheme_complex_add ((scheme_make_small_complex (n1 , & sc ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_plus__dbl_big (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  ; 
  ; 
  return scheme_make_double (d1 + scheme_bignum_to_double (n2 ) ) ; 
}
static inline Scheme_Object * scheme_bin_plus__dbl_rat (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  ; 
  ; 
  return scheme_make_double (d1 + scheme_rational_to_double (n2 ) ) ; 
}
static inline Scheme_Object * scheme_bin_plus__dbl_comp (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM21_COUNT (2)
# define SETUP_XfOrM21(x) SETUP(XfOrM21_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM21(_), scheme_complex_add ((scheme_make_small_complex (n1 , & sc ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_plus__big_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Bignum sb ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(sb.o.digits, 0)));
# define XfOrM22_COUNT (1)
# define SETUP_XfOrM22(x) SETUP(XfOrM22_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sb.o.digits = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM22(_), scheme_bignum_add ((n1 ) , (scheme_make_small_bignum ((((long ) (n2 ) ) >> 1 ) , & sb ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_plus__big_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  double d2 ; 
  ; 
  d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
  ; 
  return scheme_make_double (scheme_bignum_to_double (n1 ) + d2 ) ; 
}
static inline Scheme_Object * scheme_bin_plus__big_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Scheme_Object * __funcarg11 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(n2, 0)));
# define XfOrM24_COUNT (1)
# define SETUP_XfOrM24(x) SETUP(XfOrM24_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg11 = FUNCCALL(SETUP_XfOrM24(_), scheme_integer_to_rational (n1 ) ), FUNCCALL_EMPTY(scheme_rational_add (__funcarg11 , (n2 ) ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_plus__big_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM25_COUNT (2)
# define SETUP_XfOrM25(x) SETUP(XfOrM25_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM25(_), scheme_complex_add ((scheme_make_small_complex (n1 , & sc ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_plus__rat_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr8 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sr8.num, 0), PUSH(sr8.denom, 1)));
# define XfOrM26_COUNT (2)
# define SETUP_XfOrM26(x) SETUP(XfOrM26_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr8.num = NULLED_OUT ; 
  sr8.denom = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM26(_), scheme_rational_add ((n1 ) , (scheme_make_small_rational ((((long ) (n2 ) ) >> 1 ) , & sr8 ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_plus__rat_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  double d2 ; 
  ; 
  d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
  ; 
  return scheme_make_double (scheme_rational_to_double (n1 ) + d2 ) ; 
}
static inline Scheme_Object * scheme_bin_plus__rat_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Scheme_Object * __funcarg12 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(n1, 0)));
# define XfOrM28_COUNT (1)
# define SETUP_XfOrM28(x) SETUP(XfOrM28_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg12 = FUNCCALL(SETUP_XfOrM28(_), scheme_integer_to_rational (n2 ) ), FUNCCALL_EMPTY(scheme_rational_add ((n1 ) , __funcarg12 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_plus__rat_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM29_COUNT (2)
# define SETUP_XfOrM29(x) SETUP(XfOrM29_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM29(_), scheme_complex_add ((scheme_make_small_complex (n1 , & sc ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_plus__comp_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM30_COUNT (2)
# define SETUP_XfOrM30(x) SETUP(XfOrM30_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM30(_), scheme_complex_add ((n1 ) , (scheme_make_small_complex (n2 , & sc ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_plus__comp_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM31_COUNT (2)
# define SETUP_XfOrM31(x) SETUP(XfOrM31_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM31(_), scheme_complex_add ((n1 ) , (scheme_make_small_complex (n2 , & sc ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_plus__comp_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM32_COUNT (2)
# define SETUP_XfOrM32(x) SETUP(XfOrM32_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM32(_), scheme_complex_add ((n1 ) , (scheme_make_small_complex (n2 , & sc ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_plus__comp_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM33_COUNT (2)
# define SETUP_XfOrM33(x) SETUP(XfOrM33_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM33(_), scheme_complex_add ((n1 ) , (scheme_make_small_complex (n2 , & sc ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_bin_plus (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  Scheme_Type t1 , t2 ; 
  if (n2 == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) )
    return (Scheme_Object * ) n1 ; 
  if ((((long ) (n1 ) ) & 0x1 ) ) {
    if (n1 == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) )
      return (Scheme_Object * ) n2 ; 
    if ((((long ) (n2 ) ) & 0x1 ) )
      return ADD ((((long ) (n1 ) ) >> 1 ) , (((long ) (n2 ) ) >> 1 ) ) ; 
    t2 = ((n2 ) -> type ) ; 
    if (t2 == scheme_double_type ) {
      double d = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
      ; 
      return scheme_make_double ((((long ) (n1 ) ) >> 1 ) + d ) ; 
    }
    if (t2 == scheme_bignum_type ) {
      return scheme_bin_plus__int_big (n1 , n2 ) ; 
    }
    if (t2 == scheme_rational_type ) {
      return scheme_bin_plus__int_rat (n1 , n2 ) ; 
    }
    if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
      return scheme_bin_plus__int_comp (n1 , n2 ) ; 
    }
    return scheme_bin_plus__wrong_type (n2 ) ; 
  }
  else {
    t1 = ((n1 ) -> type ) ; 
    if (t1 == scheme_double_type ) {
      double d1 = (((Scheme_Double * ) (n1 ) ) -> double_val ) ; 
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        ; 
        return scheme_make_double (d1 + (((long ) (n2 ) ) >> 1 ) ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        double d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
        ; 
        ; 
        return scheme_make_double (d1 + d2 ) ; 
      }
      if (t2 == scheme_bignum_type ) {
        return scheme_bin_plus__dbl_big (d1 , n1 , n2 ) ; 
      }
      if (t2 == scheme_rational_type ) {
        return scheme_bin_plus__dbl_rat (d1 , n1 , n2 ) ; 
      }
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
        return scheme_bin_plus__dbl_comp (d1 , n1 , n2 ) ; 
      }
      return scheme_bin_plus__wrong_type (n2 ) ; 
    }
    else if (t1 == scheme_bignum_type ) {
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        return scheme_bin_plus__big_int (n1 , n2 ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return scheme_bin_plus__big_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return scheme_bignum_add ((n1 ) , (n2 ) ) ; 
      if (t2 == scheme_rational_type )
        return scheme_bin_plus__big_rat (n1 , n2 ) ; 
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
        return scheme_bin_plus__big_comp (n1 , n2 ) ; 
      }
      return scheme_bin_plus__wrong_type (n2 ) ; 
    }
    else if (t1 == scheme_rational_type ) {
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        return scheme_bin_plus__rat_int (n1 , n2 ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return scheme_bin_plus__rat_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return scheme_bin_plus__rat_big (n1 , n2 ) ; 
      if (t2 == scheme_rational_type )
        return scheme_rational_add ((n1 ) , (n2 ) ) ; 
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
        return scheme_bin_plus__rat_comp (n1 , n2 ) ; 
      }
      return scheme_bin_plus__wrong_type (n2 ) ; 
    }
    else if ((t1 == scheme_complex_type ) || (t1 == scheme_complex_izi_type ) ) {
      if ((((long ) (n2 ) ) & 0x1 ) )
        return scheme_bin_plus__comp_int (n1 , n2 ) ; 
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return scheme_bin_plus__comp_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return scheme_bin_plus__comp_big (n1 , n2 ) ; 
      if (t2 == scheme_rational_type )
        return scheme_bin_plus__comp_rat (n1 , n2 ) ; 
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) )
        return scheme_complex_add ((n1 ) , (n2 ) ) ; 
      return scheme_bin_plus__wrong_type (n2 ) ; 
    }
    else return scheme_bin_plus__wrong_type (n1 ) ; 
  }
}
Scheme_Object * scheme_bin_minus (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
static Scheme_Object * scheme_bin_minus__wrong_type (const Scheme_Object * v ) {
  Scheme_Object * a [1 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 1, 0)));
# define XfOrM57_COUNT (3)
# define SETUP_XfOrM57(x) SETUP(XfOrM57_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a [0 ] = (Scheme_Object * ) v ; 
  FUNCCALL(SETUP_XfOrM57(_), scheme_wrong_type ("-" , "number" , - 1 , 0 , a ) ); 
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_minus__int_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Bignum sb ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(sb.o.digits, 0)));
# define XfOrM58_COUNT (1)
# define SETUP_XfOrM58(x) SETUP(XfOrM58_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sb.o.digits = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM58(_), scheme_bignum_subtract ((scheme_make_small_bignum ((((long ) (n1 ) ) >> 1 ) , & sb ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_minus__int_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr1 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sr1.num, 0), PUSH(sr1.denom, 1)));
# define XfOrM59_COUNT (2)
# define SETUP_XfOrM59(x) SETUP(XfOrM59_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr1.num = NULLED_OUT ; 
  sr1.denom = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM59(_), scheme_rational_subtract ((scheme_make_small_rational ((((long ) (n1 ) ) >> 1 ) , & sr1 ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_minus__int_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM60_COUNT (2)
# define SETUP_XfOrM60(x) SETUP(XfOrM60_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM60(_), scheme_complex_subtract ((scheme_make_small_complex (n1 , & sc ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_minus__dbl_big (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  ; 
  ; 
  return scheme_make_double (d1 - scheme_bignum_to_double (n2 ) ) ; 
}
static inline Scheme_Object * scheme_bin_minus__dbl_rat (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  ; 
  ; 
  return scheme_make_double (d1 - scheme_rational_to_double (n2 ) ) ; 
}
static inline Scheme_Object * scheme_bin_minus__dbl_comp (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM63_COUNT (2)
# define SETUP_XfOrM63(x) SETUP(XfOrM63_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM63(_), scheme_complex_subtract ((scheme_make_small_complex (n1 , & sc ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_minus__big_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Bignum sb ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(sb.o.digits, 0)));
# define XfOrM64_COUNT (1)
# define SETUP_XfOrM64(x) SETUP(XfOrM64_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sb.o.digits = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM64(_), scheme_bignum_subtract ((n1 ) , (scheme_make_small_bignum ((((long ) (n2 ) ) >> 1 ) , & sb ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_minus__big_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  double d2 ; 
  ; 
  d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
  ; 
  return scheme_make_double (scheme_bignum_to_double (n1 ) - d2 ) ; 
}
static inline Scheme_Object * scheme_bin_minus__big_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Scheme_Object * __funcarg13 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(n2, 0)));
# define XfOrM66_COUNT (1)
# define SETUP_XfOrM66(x) SETUP(XfOrM66_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg13 = FUNCCALL(SETUP_XfOrM66(_), scheme_integer_to_rational (n1 ) ), FUNCCALL_EMPTY(scheme_rational_subtract (__funcarg13 , (n2 ) ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_minus__big_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM67_COUNT (2)
# define SETUP_XfOrM67(x) SETUP(XfOrM67_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM67(_), scheme_complex_subtract ((scheme_make_small_complex (n1 , & sc ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_minus__rat_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr8 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sr8.num, 0), PUSH(sr8.denom, 1)));
# define XfOrM68_COUNT (2)
# define SETUP_XfOrM68(x) SETUP(XfOrM68_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr8.num = NULLED_OUT ; 
  sr8.denom = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM68(_), scheme_rational_subtract ((n1 ) , (scheme_make_small_rational ((((long ) (n2 ) ) >> 1 ) , & sr8 ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_minus__rat_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  double d2 ; 
  ; 
  d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
  ; 
  return scheme_make_double (scheme_rational_to_double (n1 ) - d2 ) ; 
}
static inline Scheme_Object * scheme_bin_minus__rat_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Scheme_Object * __funcarg14 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(n1, 0)));
# define XfOrM70_COUNT (1)
# define SETUP_XfOrM70(x) SETUP(XfOrM70_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg14 = FUNCCALL(SETUP_XfOrM70(_), scheme_integer_to_rational (n2 ) ), FUNCCALL_EMPTY(scheme_rational_subtract ((n1 ) , __funcarg14 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_minus__rat_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM71_COUNT (2)
# define SETUP_XfOrM71(x) SETUP(XfOrM71_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM71(_), scheme_complex_subtract ((scheme_make_small_complex (n1 , & sc ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_minus__comp_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM72_COUNT (2)
# define SETUP_XfOrM72(x) SETUP(XfOrM72_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM72(_), scheme_complex_subtract ((n1 ) , (scheme_make_small_complex (n2 , & sc ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_minus__comp_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM73_COUNT (2)
# define SETUP_XfOrM73(x) SETUP(XfOrM73_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM73(_), scheme_complex_subtract ((n1 ) , (scheme_make_small_complex (n2 , & sc ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_minus__comp_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM74_COUNT (2)
# define SETUP_XfOrM74(x) SETUP(XfOrM74_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM74(_), scheme_complex_subtract ((n1 ) , (scheme_make_small_complex (n2 , & sc ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_minus__comp_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM75_COUNT (2)
# define SETUP_XfOrM75(x) SETUP(XfOrM75_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM75(_), scheme_complex_subtract ((n1 ) , (scheme_make_small_complex (n2 , & sc ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_bin_minus (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  Scheme_Type t1 , t2 ; 
  if (n2 == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) )
    return (Scheme_Object * ) n1 ; 
  if ((((long ) (n1 ) ) & 0x1 ) ) {
    if (n1 == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) )
      if ((Scheme_Type ) (((((long ) (n2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n2 ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) )
      return unary_minus (n2 ) ; 
    if ((((long ) (n2 ) ) & 0x1 ) )
      return SUBTRACT ((((long ) (n1 ) ) >> 1 ) , (((long ) (n2 ) ) >> 1 ) ) ; 
    t2 = ((n2 ) -> type ) ; 
    if (t2 == scheme_double_type ) {
      double d = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
      ; 
      return scheme_make_double ((((long ) (n1 ) ) >> 1 ) - d ) ; 
    }
    if (t2 == scheme_bignum_type ) {
      return scheme_bin_minus__int_big (n1 , n2 ) ; 
    }
    if (t2 == scheme_rational_type ) {
      return scheme_bin_minus__int_rat (n1 , n2 ) ; 
    }
    if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
      return scheme_bin_minus__int_comp (n1 , n2 ) ; 
    }
    return scheme_bin_minus__wrong_type (n2 ) ; 
  }
  else {
    t1 = ((n1 ) -> type ) ; 
    if (t1 == scheme_double_type ) {
      double d1 = (((Scheme_Double * ) (n1 ) ) -> double_val ) ; 
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        ; 
        return scheme_make_double (d1 - (((long ) (n2 ) ) >> 1 ) ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        double d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
        ; 
        ; 
        return scheme_make_double (d1 - d2 ) ; 
      }
      if (t2 == scheme_bignum_type ) {
        return scheme_bin_minus__dbl_big (d1 , n1 , n2 ) ; 
      }
      if (t2 == scheme_rational_type ) {
        return scheme_bin_minus__dbl_rat (d1 , n1 , n2 ) ; 
      }
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
        return scheme_bin_minus__dbl_comp (d1 , n1 , n2 ) ; 
      }
      return scheme_bin_minus__wrong_type (n2 ) ; 
    }
    else if (t1 == scheme_bignum_type ) {
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        return scheme_bin_minus__big_int (n1 , n2 ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return scheme_bin_minus__big_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return scheme_bignum_subtract ((n1 ) , (n2 ) ) ; 
      if (t2 == scheme_rational_type )
        return scheme_bin_minus__big_rat (n1 , n2 ) ; 
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
        return scheme_bin_minus__big_comp (n1 , n2 ) ; 
      }
      return scheme_bin_minus__wrong_type (n2 ) ; 
    }
    else if (t1 == scheme_rational_type ) {
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        return scheme_bin_minus__rat_int (n1 , n2 ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return scheme_bin_minus__rat_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return scheme_bin_minus__rat_big (n1 , n2 ) ; 
      if (t2 == scheme_rational_type )
        return scheme_rational_subtract ((n1 ) , (n2 ) ) ; 
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
        return scheme_bin_minus__rat_comp (n1 , n2 ) ; 
      }
      return scheme_bin_minus__wrong_type (n2 ) ; 
    }
    else if ((t1 == scheme_complex_type ) || (t1 == scheme_complex_izi_type ) ) {
      if ((((long ) (n2 ) ) & 0x1 ) )
        return scheme_bin_minus__comp_int (n1 , n2 ) ; 
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return scheme_bin_minus__comp_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return scheme_bin_minus__comp_big (n1 , n2 ) ; 
      if (t2 == scheme_rational_type )
        return scheme_bin_minus__comp_rat (n1 , n2 ) ; 
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) )
        return scheme_complex_subtract ((n1 ) , (n2 ) ) ; 
      return scheme_bin_minus__wrong_type (n2 ) ; 
    }
    else return scheme_bin_minus__wrong_type (n1 ) ; 
  }
}
Scheme_Object * scheme_bin_mult (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
static Scheme_Object * scheme_bin_mult__wrong_type (const Scheme_Object * v ) {
  Scheme_Object * a [1 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 1, 0)));
# define XfOrM99_COUNT (3)
# define SETUP_XfOrM99(x) SETUP(XfOrM99_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a [0 ] = (Scheme_Object * ) v ; 
  FUNCCALL(SETUP_XfOrM99(_), scheme_wrong_type ("*" , "number" , - 1 , 0 , a ) ); 
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_mult__int_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Bignum sb ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(sb.o.digits, 0)));
# define XfOrM100_COUNT (1)
# define SETUP_XfOrM100(x) SETUP(XfOrM100_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sb.o.digits = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM100(_), scheme_bignum_multiply ((scheme_make_small_bignum ((((long ) (n1 ) ) >> 1 ) , & sb ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_mult__int_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr1 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sr1.num, 0), PUSH(sr1.denom, 1)));
# define XfOrM101_COUNT (2)
# define SETUP_XfOrM101(x) SETUP(XfOrM101_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr1.num = NULLED_OUT ; 
  sr1.denom = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM101(_), scheme_rational_multiply ((scheme_make_small_rational ((((long ) (n1 ) ) >> 1 ) , & sr1 ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_mult__int_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM102_COUNT (2)
# define SETUP_XfOrM102(x) SETUP(XfOrM102_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM102(_), scheme_complex_multiply ((scheme_make_small_complex (n1 , & sc ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_mult__dbl_big (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  ; 
  ; 
  return scheme_make_double (d1 * scheme_bignum_to_double (n2 ) ) ; 
}
static inline Scheme_Object * scheme_bin_mult__dbl_rat (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  ; 
  ; 
  return scheme_make_double (d1 * scheme_rational_to_double (n2 ) ) ; 
}
static inline Scheme_Object * scheme_bin_mult__dbl_comp (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM105_COUNT (2)
# define SETUP_XfOrM105(x) SETUP(XfOrM105_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM105(_), scheme_complex_multiply ((scheme_make_small_complex (n1 , & sc ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_mult__big_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Bignum sb ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(sb.o.digits, 0)));
# define XfOrM106_COUNT (1)
# define SETUP_XfOrM106(x) SETUP(XfOrM106_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sb.o.digits = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM106(_), scheme_bignum_multiply ((n1 ) , (scheme_make_small_bignum ((((long ) (n2 ) ) >> 1 ) , & sb ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_mult__big_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  double d2 ; 
  ; 
  d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
  ; 
  return scheme_make_double (scheme_bignum_to_double (n1 ) * d2 ) ; 
}
static inline Scheme_Object * scheme_bin_mult__big_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Scheme_Object * __funcarg15 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(n2, 0)));
# define XfOrM108_COUNT (1)
# define SETUP_XfOrM108(x) SETUP(XfOrM108_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg15 = FUNCCALL(SETUP_XfOrM108(_), scheme_integer_to_rational (n1 ) ), FUNCCALL_EMPTY(scheme_rational_multiply (__funcarg15 , (n2 ) ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_mult__big_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM109_COUNT (2)
# define SETUP_XfOrM109(x) SETUP(XfOrM109_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM109(_), scheme_complex_multiply ((scheme_make_small_complex (n1 , & sc ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_mult__rat_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr8 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sr8.num, 0), PUSH(sr8.denom, 1)));
# define XfOrM110_COUNT (2)
# define SETUP_XfOrM110(x) SETUP(XfOrM110_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr8.num = NULLED_OUT ; 
  sr8.denom = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM110(_), scheme_rational_multiply ((n1 ) , (scheme_make_small_rational ((((long ) (n2 ) ) >> 1 ) , & sr8 ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_mult__rat_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  double d2 ; 
  ; 
  d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
  ; 
  return scheme_make_double (scheme_rational_to_double (n1 ) * d2 ) ; 
}
static inline Scheme_Object * scheme_bin_mult__rat_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Scheme_Object * __funcarg16 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(n1, 0)));
# define XfOrM112_COUNT (1)
# define SETUP_XfOrM112(x) SETUP(XfOrM112_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg16 = FUNCCALL(SETUP_XfOrM112(_), scheme_integer_to_rational (n2 ) ), FUNCCALL_EMPTY(scheme_rational_multiply ((n1 ) , __funcarg16 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_mult__rat_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM113_COUNT (2)
# define SETUP_XfOrM113(x) SETUP(XfOrM113_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM113(_), scheme_complex_multiply ((scheme_make_small_complex (n1 , & sc ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_mult__comp_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM114_COUNT (2)
# define SETUP_XfOrM114(x) SETUP(XfOrM114_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM114(_), scheme_complex_multiply ((n1 ) , (scheme_make_small_complex (n2 , & sc ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_mult__comp_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM115_COUNT (2)
# define SETUP_XfOrM115(x) SETUP(XfOrM115_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM115(_), scheme_complex_multiply ((n1 ) , (scheme_make_small_complex (n2 , & sc ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_mult__comp_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM116_COUNT (2)
# define SETUP_XfOrM116(x) SETUP(XfOrM116_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM116(_), scheme_complex_multiply ((n1 ) , (scheme_make_small_complex (n2 , & sc ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_mult__comp_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM117_COUNT (2)
# define SETUP_XfOrM117(x) SETUP(XfOrM117_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM117(_), scheme_complex_multiply ((n1 ) , (scheme_make_small_complex (n2 , & sc ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_bin_mult (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  Scheme_Type t1 , t2 ; 
  if (n2 == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) )
    return ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
  if ((((long ) (n1 ) ) & 0x1 ) ) {
    if (n1 == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) )
      return ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
    if ((((long ) (n2 ) ) & 0x1 ) )
      return MULTIPLY ((((long ) (n1 ) ) >> 1 ) , (((long ) (n2 ) ) >> 1 ) ) ; 
    t2 = ((n2 ) -> type ) ; 
    if (t2 == scheme_double_type ) {
      double d = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
      ; 
      return scheme_make_double ((((long ) (n1 ) ) >> 1 ) * d ) ; 
    }
    if (t2 == scheme_bignum_type ) {
      return scheme_bin_mult__int_big (n1 , n2 ) ; 
    }
    if (t2 == scheme_rational_type ) {
      return scheme_bin_mult__int_rat (n1 , n2 ) ; 
    }
    if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
      return scheme_bin_mult__int_comp (n1 , n2 ) ; 
    }
    return scheme_bin_mult__wrong_type (n2 ) ; 
  }
  else {
    t1 = ((n1 ) -> type ) ; 
    if (t1 == scheme_double_type ) {
      double d1 = (((Scheme_Double * ) (n1 ) ) -> double_val ) ; 
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        ; 
        return scheme_make_double (d1 * (((long ) (n2 ) ) >> 1 ) ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        double d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
        ; 
        ; 
        return scheme_make_double (d1 * d2 ) ; 
      }
      if (t2 == scheme_bignum_type ) {
        return scheme_bin_mult__dbl_big (d1 , n1 , n2 ) ; 
      }
      if (t2 == scheme_rational_type ) {
        return scheme_bin_mult__dbl_rat (d1 , n1 , n2 ) ; 
      }
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
        return scheme_bin_mult__dbl_comp (d1 , n1 , n2 ) ; 
      }
      return scheme_bin_mult__wrong_type (n2 ) ; 
    }
    else if (t1 == scheme_bignum_type ) {
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        return scheme_bin_mult__big_int (n1 , n2 ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return scheme_bin_mult__big_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return scheme_bignum_multiply ((n1 ) , (n2 ) ) ; 
      if (t2 == scheme_rational_type )
        return scheme_bin_mult__big_rat (n1 , n2 ) ; 
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
        return scheme_bin_mult__big_comp (n1 , n2 ) ; 
      }
      return scheme_bin_mult__wrong_type (n2 ) ; 
    }
    else if (t1 == scheme_rational_type ) {
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        return scheme_bin_mult__rat_int (n1 , n2 ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return scheme_bin_mult__rat_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return scheme_bin_mult__rat_big (n1 , n2 ) ; 
      if (t2 == scheme_rational_type )
        return scheme_rational_multiply ((n1 ) , (n2 ) ) ; 
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
        return scheme_bin_mult__rat_comp (n1 , n2 ) ; 
      }
      return scheme_bin_mult__wrong_type (n2 ) ; 
    }
    else if ((t1 == scheme_complex_type ) || (t1 == scheme_complex_izi_type ) ) {
      if ((((long ) (n2 ) ) & 0x1 ) )
        return scheme_bin_mult__comp_int (n1 , n2 ) ; 
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return scheme_bin_mult__comp_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return scheme_bin_mult__comp_big (n1 , n2 ) ; 
      if (t2 == scheme_rational_type )
        return scheme_bin_mult__comp_rat (n1 , n2 ) ; 
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) )
        return scheme_complex_multiply ((n1 ) , (n2 ) ) ; 
      return scheme_bin_mult__wrong_type (n2 ) ; 
    }
    else return scheme_bin_mult__wrong_type (n1 ) ; 
  }
}
Scheme_Object * scheme_bin_div (const Scheme_Object * n1 , const Scheme_Object * n2 ) ; 
static Scheme_Object * scheme_bin_div__wrong_type (const Scheme_Object * v ) {
  Scheme_Object * a [1 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 1, 0)));
# define XfOrM141_COUNT (3)
# define SETUP_XfOrM141(x) SETUP(XfOrM141_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a [0 ] = (Scheme_Object * ) v ; 
  FUNCCALL(SETUP_XfOrM141(_), scheme_wrong_type ("/" , "number" , - 1 , 0 , a ) ); 
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_div__int_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Bignum sb ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(sb.o.digits, 0)));
# define XfOrM142_COUNT (1)
# define SETUP_XfOrM142(x) SETUP(XfOrM142_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sb.o.digits = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM142(_), scheme_make_rational ((scheme_make_small_bignum ((((long ) (n1 ) ) >> 1 ) , & sb ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_div__int_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr1 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sr1.num, 0), PUSH(sr1.denom, 1)));
# define XfOrM143_COUNT (2)
# define SETUP_XfOrM143(x) SETUP(XfOrM143_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr1.num = NULLED_OUT ; 
  sr1.denom = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM143(_), scheme_rational_divide ((scheme_make_small_rational ((((long ) (n1 ) ) >> 1 ) , & sr1 ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_div__int_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM144_COUNT (2)
# define SETUP_XfOrM144(x) SETUP(XfOrM144_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM144(_), scheme_complex_divide ((scheme_make_small_complex (n1 , & sc ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_div__dbl_big (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  ; 
  ; 
  if ((isinf (d1 ) && (d1 > 0 ) ) )
    return (scheme_is_positive (n2 ) ? scheme_inf_object : scheme_minus_inf_object ) ; 
  if ((isinf (d1 ) && (d1 < 0 ) ) )
    return (! scheme_is_positive (n2 ) ? scheme_inf_object : scheme_minus_inf_object ) ; 
  return scheme_make_double ((double ) d1 / (double ) scheme_bignum_to_double (n2 ) ) ; 
}
static inline Scheme_Object * scheme_bin_div__dbl_rat (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  ; 
  ; 
  if ((isinf (d1 ) && (d1 > 0 ) ) )
    return (scheme_is_positive (n2 ) ? scheme_inf_object : scheme_minus_inf_object ) ; 
  if ((isinf (d1 ) && (d1 < 0 ) ) )
    return (! scheme_is_positive (n2 ) ? scheme_inf_object : scheme_minus_inf_object ) ; 
  if (d1 == 0.0 )
    return (scheme_minus_zero_p (d1 ) ? (! scheme_is_positive (n2 ) ? scheme_zerod : scheme_nzerod ) : (! scheme_is_positive (n2 ) ? scheme_nzerod : scheme_zerod ) ) ; 
  return scheme_make_double ((double ) d1 / (double ) scheme_rational_to_double (n2 ) ) ; 
}
static inline Scheme_Object * scheme_bin_div__dbl_comp (double d1 , const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM147_COUNT (2)
# define SETUP_XfOrM147(x) SETUP(XfOrM147_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM147(_), scheme_complex_divide ((scheme_make_small_complex (n1 , & sc ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_div__big_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Bignum sb ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(sb.o.digits, 0)));
# define XfOrM148_COUNT (1)
# define SETUP_XfOrM148(x) SETUP(XfOrM148_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sb.o.digits = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM148(_), scheme_make_rational ((n1 ) , (scheme_make_small_bignum ((((long ) (n2 ) ) >> 1 ) , & sb ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_div__big_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  double d2 ; 
  ; 
  d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
  ; 
  if ((isinf (d2 ) && (d2 > 0 ) ) )
    return (! scheme_is_positive (n1 ) ? scheme_nzerod : scheme_zerod ) ; 
  if ((isinf (d2 ) && (d2 < 0 ) ) )
    return (! scheme_is_positive (n1 ) ? scheme_zerod : scheme_nzerod ) ; 
  return scheme_make_double ((double ) scheme_bignum_to_double (n1 ) / (double ) d2 ) ; 
}
static inline Scheme_Object * scheme_bin_div__big_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Scheme_Object * __funcarg17 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(n2, 0)));
# define XfOrM150_COUNT (1)
# define SETUP_XfOrM150(x) SETUP(XfOrM150_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg17 = FUNCCALL(SETUP_XfOrM150(_), scheme_integer_to_rational (n1 ) ), FUNCCALL_EMPTY(scheme_rational_divide (__funcarg17 , (n2 ) ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_div__big_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM151_COUNT (2)
# define SETUP_XfOrM151(x) SETUP(XfOrM151_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM151(_), scheme_complex_divide ((scheme_make_small_complex (n1 , & sc ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_div__rat_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Rational sr8 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sr8.num, 0), PUSH(sr8.denom, 1)));
# define XfOrM152_COUNT (2)
# define SETUP_XfOrM152(x) SETUP(XfOrM152_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sr8.num = NULLED_OUT ; 
  sr8.denom = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM152(_), scheme_rational_divide ((n1 ) , (scheme_make_small_rational ((((long ) (n2 ) ) >> 1 ) , & sr8 ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_div__rat_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  double d2 ; 
  ; 
  d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
  ; 
  if ((isinf (d2 ) && (d2 > 0 ) ) )
    return (! scheme_is_positive (n1 ) ? scheme_nzerod : scheme_zerod ) ; 
  if ((isinf (d2 ) && (d2 < 0 ) ) )
    return (! scheme_is_positive (n1 ) ? scheme_zerod : scheme_nzerod ) ; 
  if (d2 == 0.0 )
    return (scheme_minus_zero_p (d2 ) ? (! scheme_is_positive (n1 ) ? scheme_inf_object : scheme_minus_inf_object ) : (scheme_is_positive (n1 ) ? scheme_inf_object : scheme_minus_inf_object ) ) ; 
  return scheme_make_double ((double ) scheme_rational_to_double (n1 ) / (double ) d2 ) ; 
}
static inline Scheme_Object * scheme_bin_div__rat_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Scheme_Object * __funcarg18 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(n1, 0)));
# define XfOrM154_COUNT (1)
# define SETUP_XfOrM154(x) SETUP(XfOrM154_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg18 = FUNCCALL(SETUP_XfOrM154(_), scheme_integer_to_rational (n2 ) ), FUNCCALL_EMPTY(scheme_rational_divide ((n1 ) , __funcarg18 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_div__rat_comp (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM155_COUNT (2)
# define SETUP_XfOrM155(x) SETUP(XfOrM155_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM155(_), scheme_complex_divide ((scheme_make_small_complex (n1 , & sc ) ) , (n2 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_div__comp_int (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM156_COUNT (2)
# define SETUP_XfOrM156(x) SETUP(XfOrM156_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM156(_), scheme_complex_divide ((n1 ) , (scheme_make_small_complex (n2 , & sc ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_div__comp_dbl (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM157_COUNT (2)
# define SETUP_XfOrM157(x) SETUP(XfOrM157_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM157(_), scheme_complex_divide ((n1 ) , (scheme_make_small_complex (n2 , & sc ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_div__comp_big (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM158_COUNT (2)
# define SETUP_XfOrM158(x) SETUP(XfOrM158_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM158(_), scheme_complex_divide ((n1 ) , (scheme_make_small_complex (n2 , & sc ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Object * scheme_bin_div__comp_rat (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  Small_Complex sc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sc.r, 0), PUSH(sc.i, 1)));
# define XfOrM159_COUNT (2)
# define SETUP_XfOrM159(x) SETUP(XfOrM159_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sc.r = NULLED_OUT ; 
  sc.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM159(_), scheme_complex_divide ((n1 ) , (scheme_make_small_complex (n2 , & sc ) ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_bin_div (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  Scheme_Type t1 , t2 ; 
  if ((((long ) (n1 ) ) & 0x1 ) ) {
    if (n1 == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) )
      return ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
    if ((((long ) (n2 ) ) & 0x1 ) )
      return scheme_make_fixnum_rational ((((long ) (n1 ) ) >> 1 ) , (((long ) (n2 ) ) >> 1 ) ) ; 
    t2 = ((n2 ) -> type ) ; 
    if (t2 == scheme_double_type ) {
      double d = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
      ; 
      return scheme_make_double ((double ) (((long ) (n1 ) ) >> 1 ) / (double ) d ) ; 
    }
    if (t2 == scheme_bignum_type ) {
      return scheme_bin_div__int_big (n1 , n2 ) ; 
    }
    if (t2 == scheme_rational_type ) {
      return scheme_bin_div__int_rat (n1 , n2 ) ; 
    }
    if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
      return scheme_bin_div__int_comp (n1 , n2 ) ; 
    }
    return scheme_bin_div__wrong_type (n2 ) ; 
  }
  else {
    t1 = ((n1 ) -> type ) ; 
    if (t1 == scheme_double_type ) {
      double d1 = (((Scheme_Double * ) (n1 ) ) -> double_val ) ; 
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        ; 
        return scheme_make_double ((double ) d1 / (double ) (((long ) (n2 ) ) >> 1 ) ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        double d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
        ; 
        ; 
        return scheme_make_double ((double ) d1 / (double ) d2 ) ; 
      }
      if (t2 == scheme_bignum_type ) {
        return scheme_bin_div__dbl_big (d1 , n1 , n2 ) ; 
      }
      if (t2 == scheme_rational_type ) {
        return scheme_bin_div__dbl_rat (d1 , n1 , n2 ) ; 
      }
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
        return scheme_bin_div__dbl_comp (d1 , n1 , n2 ) ; 
      }
      return scheme_bin_div__wrong_type (n2 ) ; 
    }
    else if (t1 == scheme_bignum_type ) {
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        return scheme_bin_div__big_int (n1 , n2 ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return scheme_bin_div__big_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return scheme_make_rational ((n1 ) , (n2 ) ) ; 
      if (t2 == scheme_rational_type )
        return scheme_bin_div__big_rat (n1 , n2 ) ; 
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
        return scheme_bin_div__big_comp (n1 , n2 ) ; 
      }
      return scheme_bin_div__wrong_type (n2 ) ; 
    }
    else if (t1 == scheme_rational_type ) {
      if ((((long ) (n2 ) ) & 0x1 ) ) {
        return scheme_bin_div__rat_int (n1 , n2 ) ; 
      }
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return scheme_bin_div__rat_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return scheme_bin_div__rat_big (n1 , n2 ) ; 
      if (t2 == scheme_rational_type )
        return scheme_rational_divide ((n1 ) , (n2 ) ) ; 
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) ) {
        return scheme_bin_div__rat_comp (n1 , n2 ) ; 
      }
      return scheme_bin_div__wrong_type (n2 ) ; 
    }
    else if ((t1 == scheme_complex_type ) || (t1 == scheme_complex_izi_type ) ) {
      if ((((long ) (n2 ) ) & 0x1 ) )
        return scheme_bin_div__comp_int (n1 , n2 ) ; 
      t2 = ((n2 ) -> type ) ; 
      if (t2 == scheme_double_type ) {
        return scheme_bin_div__comp_dbl (n1 , n2 ) ; 
      }
      if (t2 == scheme_bignum_type )
        return scheme_bin_div__comp_big (n1 , n2 ) ; 
      if (t2 == scheme_rational_type )
        return scheme_bin_div__comp_rat (n1 , n2 ) ; 
      if ((t2 == scheme_complex_type ) || (t2 == scheme_complex_izi_type ) )
        return scheme_complex_divide ((n1 ) , (n2 ) ) ; 
      return scheme_bin_div__wrong_type (n2 ) ; 
    }
    else return scheme_bin_div__wrong_type (n1 ) ; 
  }
}
static Scheme_Object * plus (int argc , Scheme_Object * argv [] ) ; 
static inline Scheme_Object * plus__slow (Scheme_Object * ret , int argc , Scheme_Object * argv [] ) {
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(ret, 0), PUSH(argv, 1)));
# define XfOrM183_COUNT (2)
# define SETUP_XfOrM183(x) SETUP(XfOrM183_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  for (i = 1 ; i < argc ; ++ i ) {
    Scheme_Object * o ; 
    BLOCK_SETUP((PUSH(o, 0+XfOrM183_COUNT)));
#   define XfOrM186_COUNT (1+XfOrM183_COUNT)
#   define SETUP_XfOrM186(x) SETUP(XfOrM186_COUNT)
    o = NULLED_OUT ; 
    o = argv [i ] ; 
    if (! ((((long ) (o ) ) & 0x1 ) || ((((o ) -> type ) >= scheme_bignum_type ) && (((o ) -> type ) <= scheme_complex_type ) ) ) ) {
#     define XfOrM187_COUNT (0+XfOrM186_COUNT)
#     define SETUP_XfOrM187(x) SETUP_XfOrM186(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("+" , "number" , i , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    ret = FUNCCALL(SETUP_XfOrM186(_), scheme_bin_plus (ret , o ) ); 
  }
  RET_VALUE_START ((ret ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * plus (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * ret ; 
  if (! argc )
    return ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
  ret = argv [0 ] ; 
  if (! ((((long ) (ret ) ) & 0x1 ) || ((((ret ) -> type ) >= scheme_bignum_type ) && (((ret ) -> type ) <= scheme_complex_type ) ) ) ) {
    scheme_wrong_type ("+" , "number" , 0 , argc , argv ) ; 
    return ((void * ) 0 ) ; 
  }
  if (argc == 2 ) {
    Scheme_Object * b ; 
    b = argv [1 ] ; 
    if (! ((((long ) (b ) ) & 0x1 ) || ((((b ) -> type ) >= scheme_bignum_type ) && (((b ) -> type ) <= scheme_complex_type ) ) ) ) {
      scheme_wrong_type ("+" , "number" , 1 , argc , argv ) ; 
      return ((void * ) 0 ) ; 
    }
    return scheme_bin_plus (ret , b ) ; 
  }
  return plus__slow (ret , argc , argv ) ; 
}
static Scheme_Object * mult (int argc , Scheme_Object * argv [] ) ; 
static inline Scheme_Object * mult__slow (Scheme_Object * ret , int argc , Scheme_Object * argv [] ) {
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(ret, 0), PUSH(argv, 1)));
# define XfOrM192_COUNT (2)
# define SETUP_XfOrM192(x) SETUP(XfOrM192_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  for (i = 1 ; i < argc ; ++ i ) {
    Scheme_Object * o ; 
    BLOCK_SETUP((PUSH(o, 0+XfOrM192_COUNT)));
#   define XfOrM195_COUNT (1+XfOrM192_COUNT)
#   define SETUP_XfOrM195(x) SETUP(XfOrM195_COUNT)
    o = NULLED_OUT ; 
    o = argv [i ] ; 
    if (! ((((long ) (o ) ) & 0x1 ) || ((((o ) -> type ) >= scheme_bignum_type ) && (((o ) -> type ) <= scheme_complex_type ) ) ) ) {
#     define XfOrM196_COUNT (0+XfOrM195_COUNT)
#     define SETUP_XfOrM196(x) SETUP_XfOrM195(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("*" , "number" , i , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    ret = FUNCCALL(SETUP_XfOrM195(_), scheme_bin_mult (ret , o ) ); 
  }
  RET_VALUE_START ((ret ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * mult (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * ret ; 
  if (! argc )
    return ((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) ; 
  ret = argv [0 ] ; 
  if (! ((((long ) (ret ) ) & 0x1 ) || ((((ret ) -> type ) >= scheme_bignum_type ) && (((ret ) -> type ) <= scheme_complex_type ) ) ) ) {
    scheme_wrong_type ("*" , "number" , 0 , argc , argv ) ; 
    return ((void * ) 0 ) ; 
  }
  if (argc == 2 ) {
    Scheme_Object * b ; 
    b = argv [1 ] ; 
    if (! ((((long ) (b ) ) & 0x1 ) || ((((b ) -> type ) >= scheme_bignum_type ) && (((b ) -> type ) <= scheme_complex_type ) ) ) ) {
      scheme_wrong_type ("*" , "number" , 1 , argc , argv ) ; 
      return ((void * ) 0 ) ; 
    }
    return scheme_bin_mult (ret , b ) ; 
  }
  return mult__slow (ret , argc , argv ) ; 
}
static inline Scheme_Object * minus_slow (Scheme_Object * ret , int argc , Scheme_Object * argv [] ) {
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(ret, 0), PUSH(argv, 1)));
# define XfOrM201_COUNT (2)
# define SETUP_XfOrM201(x) SETUP(XfOrM201_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  for (i = 1 ; i < argc ; i ++ ) {
    Scheme_Object * o = argv [i ] ; 
    BLOCK_SETUP((PUSH(o, 0+XfOrM201_COUNT)));
#   define XfOrM204_COUNT (1+XfOrM201_COUNT)
#   define SETUP_XfOrM204(x) SETUP(XfOrM204_COUNT)
    if (! ((((long ) (o ) ) & 0x1 ) || ((((o ) -> type ) >= scheme_bignum_type ) && (((o ) -> type ) <= scheme_complex_type ) ) ) ) {
#     define XfOrM205_COUNT (0+XfOrM204_COUNT)
#     define SETUP_XfOrM205(x) SETUP_XfOrM204(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("-" , "number" , i , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    ret = FUNCCALL(SETUP_XfOrM204(_), scheme_bin_minus (ret , o ) ); 
  }
  RET_VALUE_START (ret ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * minus (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * ret , * v ; 
  ret = argv [0 ] ; 
  if (! ((((long ) (ret ) ) & 0x1 ) || ((((ret ) -> type ) >= scheme_bignum_type ) && (((ret ) -> type ) <= scheme_complex_type ) ) ) ) {
    scheme_wrong_type ("-" , "number" , 0 , argc , argv ) ; 
    return ((void * ) 0 ) ; 
  }
  if (argc == 1 ) {
    if (((Scheme_Type ) (((((long ) (ret ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ret ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ) {
      return scheme_make_double (- (((Scheme_Double * ) (ret ) ) -> double_val ) ) ; 
    }
    return scheme_bin_minus (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) , ret ) ; 
  }
  if (argc == 2 ) {
    v = argv [1 ] ; 
    if (! ((((long ) (v ) ) & 0x1 ) || ((((v ) -> type ) >= scheme_bignum_type ) && (((v ) -> type ) <= scheme_complex_type ) ) ) ) {
      scheme_wrong_type ("-" , "number" , 1 , argc , argv ) ; 
      return ((void * ) 0 ) ; 
    }
    return scheme_bin_minus (ret , v ) ; 
  }
  return minus_slow (ret , argc , argv ) ; 
}
static Scheme_Object * div_prim (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * ret ; 
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(ret, 0), PUSH(argv, 1)));
# define XfOrM212_COUNT (2)
# define SETUP_XfOrM212(x) SETUP(XfOrM212_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  ret = NULLED_OUT ; 
  ret = argv [0 ] ; 
  if (! ((((long ) (ret ) ) & 0x1 ) || ((((ret ) -> type ) >= scheme_bignum_type ) && (((ret ) -> type ) <= scheme_complex_type ) ) ) ) {
#   define XfOrM221_COUNT (0+XfOrM212_COUNT)
#   define SETUP_XfOrM221(x) SETUP_XfOrM212(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("/" , "number" , 0 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (argc == 1 ) {
#   define XfOrM219_COUNT (0+XfOrM212_COUNT)
#   define SETUP_XfOrM219(x) SETUP_XfOrM212(x)
    if (ret != ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) )
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_bin_div (((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) , ret ) )) RET_VALUE_EMPTY_END ; 
    else {
#     define XfOrM220_COUNT (0+XfOrM219_COUNT)
#     define SETUP_XfOrM220(x) SETUP_XfOrM219(x)
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT_DIVIDE_BY_ZERO , "/: division by zero" ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  for (i = 1 ; i < argc ; i ++ ) {
    Scheme_Object * o = argv [i ] ; 
    BLOCK_SETUP((PUSH(o, 0+XfOrM212_COUNT)));
#   define XfOrM216_COUNT (1+XfOrM212_COUNT)
#   define SETUP_XfOrM216(x) SETUP(XfOrM216_COUNT)
    if (! ((((long ) (o ) ) & 0x1 ) || ((((o ) -> type ) >= scheme_bignum_type ) && (((o ) -> type ) <= scheme_complex_type ) ) ) ) {
#     define XfOrM218_COUNT (0+XfOrM216_COUNT)
#     define SETUP_XfOrM218(x) SETUP_XfOrM216(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("/" , "number" , i , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    if (o != ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) )
      ret = FUNCCALL(SETUP_XfOrM216(_), scheme_bin_div (ret , o ) ); 
    else {
#     define XfOrM217_COUNT (0+XfOrM216_COUNT)
#     define SETUP_XfOrM217(x) SETUP_XfOrM216(x)
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT_DIVIDE_BY_ZERO , "/: division by zero" ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  RET_VALUE_START (ret ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_abs (int argc , Scheme_Object * argv [] ) {
  Scheme_Type t ; 
  Scheme_Object * o ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM222_COUNT (1)
# define SETUP_XfOrM222(x) SETUP(XfOrM222_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  o = NULLED_OUT ; 
  o = argv [0 ] ; 
  if ((((long ) (o ) ) & 0x1 ) ) {
    int n = (((long ) (o ) ) >> 1 ) ; 
#   define XfOrM226_COUNT (0+XfOrM222_COUNT)
#   define SETUP_XfOrM226(x) SETUP_XfOrM222(x)
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_integer_value (((n > 0 ) ? n : - n ) ) )) RET_VALUE_EMPTY_END ; 
  }
  t = ((o ) -> type ) ; 
  if (t == scheme_double_type )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_double (fabs ((((Scheme_Double * ) (o ) ) -> double_val ) ) ) )) RET_VALUE_EMPTY_END ; 
  if (t == scheme_bignum_type ) {
#   define XfOrM225_COUNT (0+XfOrM222_COUNT)
#   define SETUP_XfOrM225(x) SETUP_XfOrM222(x)
    if (((& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex & 0x1 ) )
      RET_VALUE_START (o ) RET_VALUE_END ; 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_bignum_negate (o ) )) RET_VALUE_EMPTY_END ; 
  }
  if (t == scheme_rational_type ) {
#   define XfOrM224_COUNT (0+XfOrM222_COUNT)
#   define SETUP_XfOrM224(x) SETUP_XfOrM222(x)
    if ((scheme_is_rational_positive (o ) ) )
      RET_VALUE_START (o ) RET_VALUE_END ; 
    else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_rational_negate (o ) )) RET_VALUE_EMPTY_END ; 
  }
  if (t == scheme_complex_izi_type ) {
    Scheme_Object * r = (((Scheme_Complex * ) (o ) ) -> r ) ; 
    BLOCK_SETUP((PUSH(r, 0+XfOrM222_COUNT)));
#   define XfOrM223_COUNT (1+XfOrM222_COUNT)
#   define SETUP_XfOrM223(x) SETUP(XfOrM223_COUNT)
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM223(_), scheme_abs (1 , & r ) )) RET_VALUE_END ; 
  }
  FUNCCALL_EMPTY(scheme_wrong_type ("abs" , "real number" , 0 , argc , argv ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * do_bin_quotient (const char * name , const Scheme_Object * n1 , const Scheme_Object * n2 , Scheme_Object * * bn_rem ) {
  Scheme_Object * q ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(bn_rem, 0), PUSH(q, 1), PUSH(n1, 2), PUSH(n2, 3), PUSH(name, 4)));
# define XfOrM227_COUNT (5)
# define SETUP_XfOrM227(x) SETUP(XfOrM227_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  q = NULLED_OUT ; 
  if (! (scheme_is_integer (n1 ) ) ) {
    Scheme_Object * a [2 ] ; 
    BLOCK_SETUP((PUSHARRAY(a, 2, 0+XfOrM227_COUNT)));
#   define XfOrM232_COUNT (3+XfOrM227_COUNT)
#   define SETUP_XfOrM232(x) SETUP(XfOrM232_COUNT)
    a[0] = NULLED_OUT ; 
    a[1] = NULLED_OUT ; 
    a [0 ] = (Scheme_Object * ) n1 ; 
    a [1 ] = (Scheme_Object * ) n2 ; 
    FUNCCALL(SETUP_XfOrM232(_), scheme_wrong_type (name , "integer" , 0 , 2 , a ) ); 
  }
  if (! (scheme_is_integer (n2 ) ) ) {
    Scheme_Object * a [2 ] ; 
    BLOCK_SETUP((PUSHARRAY(a, 2, 0+XfOrM227_COUNT)));
#   define XfOrM231_COUNT (3+XfOrM227_COUNT)
#   define SETUP_XfOrM231(x) SETUP(XfOrM231_COUNT)
    a[0] = NULLED_OUT ; 
    a[1] = NULLED_OUT ; 
    a [0 ] = (Scheme_Object * ) n1 ; 
    a [1 ] = (Scheme_Object * ) n2 ; 
    FUNCCALL(SETUP_XfOrM231(_), scheme_wrong_type (name , "integer" , 1 , 2 , a ) ); 
  }
  if ((((((long ) (n1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n1 ) ) -> type ) == scheme_complex_izi_type ) )
    n1 = (((Scheme_Complex * ) (n1 ) ) -> r ) ; 
  if ((((((long ) (n2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n2 ) ) -> type ) == scheme_complex_izi_type ) )
    n2 = (((Scheme_Complex * ) (n2 ) ) -> r ) ; 
  if ((((long ) (n2 ) ) & 0x1 ) && ! (((long ) (n2 ) ) >> 1 ) )
    FUNCCALL(SETUP_XfOrM227(_), scheme_raise_exn (MZEXN_FAIL_CONTRACT_DIVIDE_BY_ZERO , "%s: undefined for 0" , name ) ); 
  if ((((Scheme_Type ) (((((long ) (n2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n2 ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) && ((((Scheme_Double * ) (n2 ) ) -> double_val ) == 0.0 ) ) )
    FUNCCALL(SETUP_XfOrM227(_), scheme_raise_exn (MZEXN_FAIL_CONTRACT_DIVIDE_BY_ZERO , "%s: undefined for 0.0" , name ) ); 
  if ((((long ) (n1 ) ) & 0x1 ) && (((long ) (n2 ) ) & 0x1 ) ) {
    RET_VALUE_START ((((Scheme_Object * ) (void * ) (long ) ((((long ) ((((long ) (n1 ) ) >> 1 ) / (((long ) (n2 ) ) >> 1 ) ) ) << 1 ) | 0x1 ) ) ) ) RET_VALUE_END ; 
  }
  if (((Scheme_Type ) (((((long ) (n1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n1 ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) || ((Scheme_Type ) (((((long ) (n2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n2 ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ) {
    Scheme_Object * r ; 
    double d , d2 ; 
    BLOCK_SETUP((PUSH(r, 0+XfOrM227_COUNT)));
#   define XfOrM228_COUNT (1+XfOrM227_COUNT)
#   define SETUP_XfOrM228(x) SETUP(XfOrM228_COUNT)
    r = NULLED_OUT ; 
    r = FUNCCALL(SETUP_XfOrM228(_), scheme_bin_div (n1 , n2 ) ); 
    if (((Scheme_Type ) (((((long ) (r ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (r ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ) {
#     define XfOrM229_COUNT (0+XfOrM228_COUNT)
#     define SETUP_XfOrM229(x) SETUP_XfOrM228(x)
      d = (((Scheme_Double * ) (r ) ) -> double_val ) ; 
      if (d > 0 )
        d2 = floor (d ) ; 
      else d2 = ceil (d ) ; 
      if (d2 == d )
        RET_VALUE_START (r ) RET_VALUE_END ; 
      else RET_VALUE_START (FUNCCALL(SETUP_XfOrM229(_), scheme_make_double (d2 ) )) RET_VALUE_END ; 
    }
    else RET_VALUE_START (r ) RET_VALUE_END ; 
  }
  n1 = FUNCCALL(SETUP_XfOrM227(_), scheme_to_bignum (n1 ) ); 
  n2 = FUNCCALL(SETUP_XfOrM227(_), scheme_to_bignum (n2 ) ); 
  FUNCCALL_AGAIN(scheme_bignum_divide (n1 , n2 , & q , bn_rem , 1 ) ); 
  RET_VALUE_START (q ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_bin_quotient (const Scheme_Object * n1 , const Scheme_Object * n2 ) {
  /* No conversion */
  return do_bin_quotient ("quotient" , n1 , n2 , ((void * ) 0 ) ) ; 
}
static Scheme_Object * quotient (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_bin_quotient ("quotient" , argv [0 ] , argv [1 ] , ((void * ) 0 ) ) ; 
}
static Scheme_Object * rem_mod (int argc , Scheme_Object * argv [] , char * name , int first_sign ) ; 
static Scheme_Object * rem_mod (int argc , Scheme_Object * argv [] , char * name , int first_sign ) {
  Scheme_Object * n1 , * n2 , * r ; 
  int negate ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(name, 0), PUSH(n1, 1), PUSH(r, 2), PUSH(n2, 3), PUSH(argv, 4)));
# define XfOrM235_COUNT (5)
# define SETUP_XfOrM235(x) SETUP(XfOrM235_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  n1 = NULLED_OUT ; 
  n2 = NULLED_OUT ; 
  r = NULLED_OUT ; 
  n1 = argv [0 ] ; 
  n2 = argv [1 ] ; 
  if (! (scheme_is_integer (n1 ) ) )
    FUNCCALL(SETUP_XfOrM235(_), scheme_wrong_type (name , "integer" , 0 , argc , argv ) ); 
  if (! (scheme_is_integer (n2 ) ) )
    FUNCCALL(SETUP_XfOrM235(_), scheme_wrong_type (name , "integer" , 1 , argc , argv ) ); 
  if ((((((long ) (n1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n1 ) ) -> type ) == scheme_complex_izi_type ) )
    n1 = (((Scheme_Complex * ) (n1 ) ) -> r ) ; 
  if ((((((long ) (n2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n2 ) ) -> type ) == scheme_complex_izi_type ) )
    n2 = (((Scheme_Complex * ) (n2 ) ) -> r ) ; 
  if ((((long ) (n2 ) ) & 0x1 ) && ! (((long ) (n2 ) ) >> 1 ) )
    FUNCCALL(SETUP_XfOrM235(_), scheme_raise_exn (MZEXN_FAIL_CONTRACT_DIVIDE_BY_ZERO , "%s: undefined for 0" , name ) ); 
  if ((((Scheme_Type ) (((((long ) (n2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n2 ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) && ((((Scheme_Double * ) (n2 ) ) -> double_val ) == 0.0 ) ) ) {
    int neg ; 
#   define XfOrM253_COUNT (0+XfOrM235_COUNT)
#   define SETUP_XfOrM253(x) SETUP_XfOrM235(x)
    neg = (scheme_minus_zero_p ((((Scheme_Double * ) (n2 ) ) -> double_val ) ) ) ; 
    FUNCCALL(SETUP_XfOrM253(_), scheme_raise_exn (MZEXN_FAIL_CONTRACT_DIVIDE_BY_ZERO , "%s: undefined for %s0.0" , name , neg ? "-" : "" ) ); 
  }
  if ((((long ) (n1 ) ) & 0x1 ) && ! (((long ) (n1 ) ) >> 1 ) )
    RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
  if ((((long ) (n1 ) ) & 0x1 ) && (((long ) (n2 ) ) & 0x1 ) ) {
    long a , b , na , nb , v ; 
    int neg1 , neg2 ; 
    a = (((long ) (n1 ) ) >> 1 ) ; 
    b = (((long ) (n2 ) ) >> 1 ) ; 
    na = (a < 0 ) ? - a : a ; 
    nb = (b < 0 ) ? - b : b ; 
    v = na % nb ; 
    if (v ) {
      if (first_sign ) {
        if (a < 0 )
          v = - v ; 
      }
      else {
        neg1 = (a < 0 ) ; 
        neg2 = (b < 0 ) ; 
        if (neg1 != neg2 )
          v = nb - v ; 
        if (neg2 )
          v = - v ; 
      }
    }
    RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (v ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
  }
  if (((Scheme_Type ) (((((long ) (n1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n1 ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) || ((Scheme_Type ) (((((long ) (n2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n2 ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ) {
    double a , b , na , nb , v ; 
#   define XfOrM242_COUNT (0+XfOrM235_COUNT)
#   define SETUP_XfOrM242(x) SETUP_XfOrM235(x)
    if ((((long ) (n1 ) ) & 0x1 ) )
      a = (((long ) (n1 ) ) >> 1 ) ; 
    else if (((Scheme_Type ) (((((long ) (n1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n1 ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) )
      a = (((Scheme_Double * ) (n1 ) ) -> double_val ) ; 
    else a = scheme_bignum_to_double (n1 ) ; 
    if ((((long ) (n2 ) ) & 0x1 ) )
      b = (((long ) (n2 ) ) >> 1 ) ; 
    else if (((Scheme_Type ) (((((long ) (n2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n2 ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) )
      b = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
    else b = scheme_bignum_to_double (n2 ) ; 
    if (a == 0.0 ) {
      RET_VALUE_START (scheme_zerod ) RET_VALUE_END ; 
    }
    na = (a < 0 ) ? - a : a ; 
    nb = (b < 0 ) ? - b : b ; 
    if ((isinf (nb ) && (nb > 0 ) ) )
      v = na ; 
    else if ((isinf (na ) && (na > 0 ) ) ) {
      RET_VALUE_START (scheme_zerod ) RET_VALUE_END ; 
    }
    else {
      v = fmod (na , nb ) ; 
    }
    if (v ) {
      if (first_sign ) {
        if (a < 0 )
          v = - v ; 
      }
      else {
        int neg1 , neg2 ; 
        neg1 = (a < 0 ) ; 
        neg2 = (b < 0 ) ; 
        if (neg1 != neg2 )
          v = nb - v ; 
        if (neg2 )
          v = - v ; 
      }
    }
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM242(_), scheme_make_double (v ) )) RET_VALUE_END ; 
  }
  n1 = FUNCCALL(SETUP_XfOrM235(_), scheme_to_bignum (n1 ) ); 
  n2 = FUNCCALL(SETUP_XfOrM235(_), scheme_to_bignum (n2 ) ); 
  FUNCCALL_AGAIN(scheme_bignum_divide (n1 , n2 , ((void * ) 0 ) , & r , 1 ) ); 
  negate = 0 ; 
  if (! (((long ) (r ) ) & 0x1 ) || (((long ) (r ) ) >> 1 ) ) {
#   define XfOrM236_COUNT (0+XfOrM235_COUNT)
#   define SETUP_XfOrM236(x) SETUP_XfOrM235(x)
    if ((((long ) (r ) ) & 0x1 ) ) {
      if ((((long ) (r ) ) >> 1 ) < 0 )
        r = ((Scheme_Object * ) (void * ) (long ) ((((long ) (- (((long ) (r ) ) >> 1 ) ) ) << 1 ) | 0x1 ) ) ; 
    }
    else if (! ((& ((Scheme_Bignum * ) r ) -> iso ) -> so . keyex & 0x1 ) )
      r = FUNCCALL(SETUP_XfOrM236(_), scheme_bignum_negate (r ) ); 
    if (first_sign ) {
      if (! ((& ((Scheme_Bignum * ) n1 ) -> iso ) -> so . keyex & 0x1 ) )
        negate = 1 ; 
    }
    else {
      int neg1 , neg2 ; 
#     define XfOrM238_COUNT (0+XfOrM236_COUNT)
#     define SETUP_XfOrM238(x) SETUP_XfOrM236(x)
      neg1 = ! ((& ((Scheme_Bignum * ) n1 ) -> iso ) -> so . keyex & 0x1 ) ; 
      neg2 = ! ((& ((Scheme_Bignum * ) n2 ) -> iso ) -> so . keyex & 0x1 ) ; 
      if (neg1 != neg2 ) {
#       define XfOrM239_COUNT (0+XfOrM238_COUNT)
#       define SETUP_XfOrM239(x) SETUP_XfOrM238(x)
        if (neg2 )
          r = FUNCCALL(SETUP_XfOrM239(_), scheme_bin_plus (n2 , r ) ); 
        else r = FUNCCALL(SETUP_XfOrM239(_), scheme_bin_minus (n2 , r ) ); 
      }
      else if (neg2 )
        negate = 1 ; 
    }
    if (negate ) {
#     define XfOrM237_COUNT (0+XfOrM236_COUNT)
#     define SETUP_XfOrM237(x) SETUP_XfOrM236(x)
      if ((((long ) (r ) ) & 0x1 ) )
        r = ((Scheme_Object * ) (void * ) (long ) ((((long ) (- (((long ) (r ) ) >> 1 ) ) ) << 1 ) | 0x1 ) ) ; 
      else r = FUNCCALL(SETUP_XfOrM237(_), scheme_bignum_negate (r ) ); 
    }
  }
  RET_VALUE_START (r ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * rem_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return rem_mod (argc , argv , "remainder" , 1 ) ; 
}
Scheme_Object * scheme_modulo (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return rem_mod (argc , argv , "modulo" , 0 ) ; 
}
Scheme_Object * quotient_remainder (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * rem = ((void * ) 0 ) , * quot , * a [2 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 2, 0), PUSH(rem, 3), PUSH(quot, 4), PUSH(argv, 5)));
# define XfOrM256_COUNT (6)
# define SETUP_XfOrM256(x) SETUP(XfOrM256_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  quot = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  quot = FUNCCALL(SETUP_XfOrM256(_), do_bin_quotient ("quotient/remainder" , argv [0 ] , argv [1 ] , & rem ) ); 
  if (! rem ) {
#   define XfOrM257_COUNT (0+XfOrM256_COUNT)
#   define SETUP_XfOrM257(x) SETUP_XfOrM256(x)
    rem = FUNCCALL(SETUP_XfOrM257(_), rem_mod (argc , argv , "remainder" , 1 ) ); 
  }
  a [0 ] = quot ; 
  a [1 ] = rem ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM256(_), scheme_values (2 , a ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
