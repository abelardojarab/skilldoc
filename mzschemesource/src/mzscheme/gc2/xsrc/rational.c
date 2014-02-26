#include "precomp.h"
enum {
  _ISupper = ((0 ) < 8 ? ((1 << (0 ) ) << 8 ) : ((1 << (0 ) ) >> 8 ) ) , _ISlower = ((1 ) < 8 ? ((1 << (1 ) ) << 8 ) : ((1 << (1 ) ) >> 8 ) ) , _ISalpha = ((2 ) < 8 ? ((1 << (2 ) ) << 8 ) : ((1 << (2 ) ) >> 8 ) ) , _ISdigit = ((3 ) < 8 ? ((1 << (3 ) ) << 8 ) : ((1 << (3 ) ) >> 8 ) ) , _ISxdigit = ((4 ) < 8 ? ((1 << (4 ) ) << 8 ) : ((1 << (4 ) ) >> 8 ) ) , _ISspace = ((5 ) < 8 ? ((1 << (5 ) ) << 8 ) : ((1 << (5 ) ) >> 8 ) ) , _ISprint = ((6 ) < 8 ? ((1 << (6 ) ) << 8 ) : ((1 << (6 ) ) >> 8 ) ) , _ISgraph = ((7 ) < 8 ? ((1 << (7 ) ) << 8 ) : ((1 << (7 ) ) >> 8 ) ) , _ISblank = ((8 ) < 8 ? ((1 << (8 ) ) << 8 ) : ((1 << (8 ) ) >> 8 ) ) , _IScntrl = ((9 ) < 8 ? ((1 << (9 ) ) << 8 ) : ((1 << (9 ) ) >> 8 ) ) , _ISpunct = ((10 ) < 8 ? ((1 << (10 ) ) << 8 ) : ((1 << (10 ) ) >> 8 ) ) , _ISalnum = ((11 ) < 8 ? ((1 << (11 ) ) << 8 ) : ((1 << (11 ) ) >> 8 ) ) }
; 
extern double exp (double __x ) __attribute__ ((__nothrow__ ) ) ; 
extern double frexp (double __x , int * __exponent ) __attribute__ ((__nothrow__ ) ) ; 
extern double ldexp (double __x , int __exponent ) __attribute__ ((__nothrow__ ) ) ; 
extern double modf (double __x , double * __iptr ) __attribute__ ((__nothrow__ ) ) ; 
extern double pow (double __x , double __y ) __attribute__ ((__nothrow__ ) ) ; 
extern double sqrt (double __x ) __attribute__ ((__nothrow__ ) ) ; 
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
static Scheme_Object * one = ((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) ; 
static Scheme_Object * make_rational (const Scheme_Object * n , const Scheme_Object * d , int normalize ) {
  Scheme_Rational * r ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(n, 0), PUSH(r, 1), PUSH(d, 2)));
# define XfOrM1_COUNT (3)
# define SETUP_XfOrM1(x) SETUP(XfOrM1_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  r = NULLED_OUT ; 
  r = (Scheme_Rational * ) FUNCCALL(SETUP_XfOrM1(_), GC_malloc_one_small_dirty_tagged ((((sizeof (Scheme_Rational ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) ); 
  r -> so . type = scheme_rational_type ; 
  ((& r -> so ) -> keyex = 0 ) ; 
  r -> num = (Scheme_Object * ) n ; 
  r -> denom = (Scheme_Object * ) d ; 
  RET_VALUE_START ((normalize ? FUNCCALL(SETUP_XfOrM1(_), scheme_rational_normalize ((Scheme_Object * ) r ) ): (Scheme_Object * ) r ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_rational (const Scheme_Object * n , const Scheme_Object * d ) {
  Scheme_Object * __funcarg5 = NULLED_OUT ; 
  Scheme_Object * __funcarg4 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(0);
# define XfOrM2_COUNT (0)
# define SETUP_XfOrM2(x) SETUP(XfOrM2_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg4 = (scheme_bignum_normalize (n ) ) , __funcarg5 = (scheme_bignum_normalize (d ) ) , FUNCCALL_EMPTY(make_rational (__funcarg4 , __funcarg5 , 1 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_integer_to_rational (const Scheme_Object * n ) {
  /* No conversion */
  return make_rational (n , one , 0 ) ; 
}
Scheme_Object * scheme_make_small_rational (long n , Small_Rational * s ) {
  s -> so . type = scheme_rational_type ; 
  s -> num = ((Scheme_Object * ) (void * ) (long ) ((((long ) (n ) ) << 1 ) | 0x1 ) ) ; 
  s -> denom = one ; 
  return (Scheme_Object * ) s ; 
}
Scheme_Object * scheme_make_small_bn_rational (Scheme_Object * n , Small_Rational * s ) {
  s -> so . type = scheme_rational_type ; 
  s -> num = n ; 
  s -> denom = one ; 
  return (Scheme_Object * ) s ; 
}
int scheme_is_rational_positive (const Scheme_Object * o ) {
  /* No conversion */
  Scheme_Rational * r = (Scheme_Rational * ) o ; 
  if ((((long ) (r -> num ) ) & 0x1 ) )
    return ((((long ) (r -> num ) ) >> 1 ) > 0 ) ; 
  else return ((& ((Scheme_Bignum * ) r -> num ) -> iso ) -> so . keyex & 0x1 ) ; 
}
Scheme_Object * scheme_rational_normalize (const Scheme_Object * o ) {
  Scheme_Rational * r = (Scheme_Rational * ) o ; 
  Scheme_Object * gcd , * tmpn ; 
  int negate = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(gcd, 0), PUSH(r, 1), PUSH(tmpn, 2), PUSH(o, 3)));
# define XfOrM5_COUNT (4)
# define SETUP_XfOrM5(x) SETUP(XfOrM5_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  gcd = NULLED_OUT ; 
  tmpn = NULLED_OUT ; 
  if (r -> num == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) )
    RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
  if ((((long ) (r -> denom ) ) & 0x1 ) ) {
#   define XfOrM10_COUNT (0+XfOrM5_COUNT)
#   define SETUP_XfOrM10(x) SETUP_XfOrM5(x)
    if ((((long ) (r -> denom ) ) >> 1 ) < 0 ) {
#     define XfOrM11_COUNT (0+XfOrM10_COUNT)
#     define SETUP_XfOrM11(x) SETUP_XfOrM10(x)
      tmpn = FUNCCALL(SETUP_XfOrM11(_), scheme_make_integer_value (- (((long ) (r -> denom ) ) >> 1 ) ) ); 
      r -> denom = tmpn ; 
      negate = 1 ; 
    }
  }
  else if (! ((& ((Scheme_Bignum * ) r -> denom ) -> iso ) -> so . keyex & 0x1 ) ) {
#   define XfOrM9_COUNT (0+XfOrM5_COUNT)
#   define SETUP_XfOrM9(x) SETUP_XfOrM5(x)
    tmpn = FUNCCALL(SETUP_XfOrM9(_), scheme_bignum_negate (r -> denom ) ); 
    r -> denom = tmpn ; 
    negate = 1 ; 
  }
  if (negate ) {
#   define XfOrM6_COUNT (0+XfOrM5_COUNT)
#   define SETUP_XfOrM6(x) SETUP_XfOrM5(x)
    if ((((long ) (r -> num ) ) & 0x1 ) ) {
#     define XfOrM8_COUNT (0+XfOrM6_COUNT)
#     define SETUP_XfOrM8(x) SETUP_XfOrM6(x)
      tmpn = FUNCCALL(SETUP_XfOrM8(_), scheme_make_integer_value (- (((long ) (r -> num ) ) >> 1 ) ) ); 
      r -> num = tmpn ; 
    }
    else {
#     define XfOrM7_COUNT (0+XfOrM6_COUNT)
#     define SETUP_XfOrM7(x) SETUP_XfOrM6(x)
      tmpn = FUNCCALL(SETUP_XfOrM7(_), scheme_bignum_negate (r -> num ) ); 
      r -> num = tmpn ; 
    }
  }
  if (r -> denom == one )
    RET_VALUE_START (r -> num ) RET_VALUE_END ; 
  gcd = FUNCCALL(SETUP_XfOrM5(_), scheme_bin_gcd (r -> num , r -> denom ) ); 
  if (gcd == one )
    RET_VALUE_START ((Scheme_Object * ) o ) RET_VALUE_END ; 
  tmpn = FUNCCALL(SETUP_XfOrM5(_), scheme_bin_quotient (r -> num , gcd ) ); 
  r -> num = tmpn ; 
  tmpn = FUNCCALL(SETUP_XfOrM5(_), scheme_bin_quotient (r -> denom , gcd ) ); 
  r -> denom = tmpn ; 
  if (r -> denom == one )
    RET_VALUE_START (r -> num ) RET_VALUE_END ; 
  RET_VALUE_START ((Scheme_Object * ) r ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_rational_numerator (const Scheme_Object * n ) {
  /* No conversion */
  return ((Scheme_Rational * ) n ) -> num ; 
}
Scheme_Object * scheme_rational_denominator (const Scheme_Object * n ) {
  /* No conversion */
  return ((Scheme_Rational * ) n ) -> denom ; 
}
Scheme_Object * scheme_make_fixnum_rational (long n , long d ) {
  Small_Rational s ; 
  Scheme_Object * o ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(s.num, 0), PUSH(s.denom, 1), PUSH(o, 2)));
# define XfOrM14_COUNT (3)
# define SETUP_XfOrM14(x) SETUP(XfOrM14_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s.num = NULLED_OUT ; 
  s.denom = NULLED_OUT ; 
  o = NULLED_OUT ; 
  s . so . type = scheme_rational_type ; 
  s . num = ((Scheme_Object * ) (void * ) (long ) ((((long ) (n ) ) << 1 ) | 0x1 ) ) ; 
  s . denom = ((Scheme_Object * ) (void * ) (long ) ((((long ) (d ) ) << 1 ) | 0x1 ) ) ; 
  o = FUNCCALL(SETUP_XfOrM14(_), scheme_rational_normalize ((Scheme_Object * ) & s ) ); 
  if (o == (Scheme_Object * ) & s )
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM14(_), make_rational (s . num , s . denom , 0 ) )) RET_VALUE_END ; 
  else RET_VALUE_START (o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_rational_eq (const Scheme_Object * a , const Scheme_Object * b ) {
  /* No conversion */
  Scheme_Rational * ra = (Scheme_Rational * ) a ; 
  Scheme_Rational * rb = (Scheme_Rational * ) b ; 
  if ((((long ) (ra -> num ) ) & 0x1 ) && (((long ) (rb -> num ) ) & 0x1 ) ) {
    if (ra -> num != rb -> num )
      return 0 ; 
  }
  else if (((Scheme_Type ) (((((long ) (ra -> num ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ra -> num ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) && ((Scheme_Type ) (((((long ) (rb -> num ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rb -> num ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) {
    if (! scheme_bignum_eq (ra -> num , rb -> num ) )
      return 0 ; 
  }
  else return 0 ; 
  if ((((long ) (ra -> denom ) ) & 0x1 ) && (((long ) (rb -> denom ) ) & 0x1 ) ) {
    if (ra -> denom != rb -> denom )
      return 0 ; 
  }
  else if (((Scheme_Type ) (((((long ) (ra -> denom ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ra -> denom ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) && ((Scheme_Type ) (((((long ) (rb -> denom ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (rb -> denom ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) {
    if (! scheme_bignum_eq (ra -> denom , rb -> denom ) )
      return 0 ; 
  }
  else return 0 ; 
  return 1 ; 
}
static int rational_lt (const Scheme_Object * a , const Scheme_Object * b , int or_eq ) {
  Scheme_Rational * ra = (Scheme_Rational * ) a ; 
  Scheme_Rational * rb = (Scheme_Rational * ) b ; 
  Scheme_Object * ma , * mb ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(ra, 0), PUSH(rb, 1), PUSH(ma, 2), PUSH(mb, 3)));
# define XfOrM20_COUNT (4)
# define SETUP_XfOrM20(x) SETUP(XfOrM20_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ma = NULLED_OUT ; 
  mb = NULLED_OUT ; 
  ma = FUNCCALL(SETUP_XfOrM20(_), scheme_bin_mult (ra -> num , rb -> denom ) ); 
  mb = FUNCCALL_AGAIN(scheme_bin_mult (rb -> num , ra -> denom ) ); 
  if ((((long ) (ma ) ) & 0x1 ) && (((long ) (mb ) ) & 0x1 ) ) {
    if (or_eq )
      RET_VALUE_START (((((long ) (ma ) ) >> 1 ) <= (((long ) (mb ) ) >> 1 ) ) ) RET_VALUE_END ; 
    else RET_VALUE_START (((((long ) (ma ) ) >> 1 ) < (((long ) (mb ) ) >> 1 ) ) ) RET_VALUE_END ; 
  }
  else if (((Scheme_Type ) (((((long ) (ma ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ma ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) && ((Scheme_Type ) (((((long ) (mb ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (mb ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) {
#   define XfOrM22_COUNT (0+XfOrM20_COUNT)
#   define SETUP_XfOrM22(x) SETUP_XfOrM20(x)
    if (or_eq )
      RET_VALUE_START ((scheme_bignum_le (ma , mb ) ) ) RET_VALUE_END ; 
    else RET_VALUE_START ((scheme_bignum_lt (ma , mb ) ) ) RET_VALUE_END ; 
  }
  else if (((Scheme_Type ) (((((long ) (mb ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (mb ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) {
    RET_VALUE_START (((& ((Scheme_Bignum * ) mb ) -> iso ) -> so . keyex & 0x1 ) ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (! ((& ((Scheme_Bignum * ) ma ) -> iso ) -> so . keyex & 0x1 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_rational_lt (const Scheme_Object * a , const Scheme_Object * b ) {
  /* No conversion */
  return rational_lt (a , b , 0 ) ; 
}
int scheme_rational_gt (const Scheme_Object * a , const Scheme_Object * b ) {
  /* No conversion */
  return ! rational_lt (a , b , 1 ) ; 
}
int scheme_rational_le (const Scheme_Object * a , const Scheme_Object * b ) {
  /* No conversion */
  return rational_lt (a , b , 1 ) ; 
}
int scheme_rational_ge (const Scheme_Object * a , const Scheme_Object * b ) {
  /* No conversion */
  return ! rational_lt (a , b , 0 ) ; 
}
Scheme_Object * scheme_rational_negate (const Scheme_Object * o ) {
  Scheme_Rational * r = (Scheme_Rational * ) o ; 
  Scheme_Object * __funcarg6 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(r, 0)));
# define XfOrM28_COUNT (1)
# define SETUP_XfOrM28(x) SETUP(XfOrM28_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg6 = FUNCCALL(SETUP_XfOrM28(_), scheme_bin_minus (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) , r -> num ) ), FUNCCALL_EMPTY(make_rational (__funcarg6 , r -> denom , 0 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_rational_add (const Scheme_Object * a , const Scheme_Object * b ) {
  Scheme_Rational * ra = (Scheme_Rational * ) a ; 
  Scheme_Rational * rb = (Scheme_Rational * ) b ; 
  Scheme_Object * ac , * bd , * sum , * cd ; 
  int no_normalize = 0 ; 
  PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(rb, 0), PUSH(cd, 1), PUSH(ra, 2), PUSH(ac, 3), PUSH(bd, 4), PUSH(sum, 5)));
# define XfOrM29_COUNT (6)
# define SETUP_XfOrM29(x) SETUP(XfOrM29_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ac = NULLED_OUT ; 
  bd = NULLED_OUT ; 
  sum = NULLED_OUT ; 
  cd = NULLED_OUT ; 
  if ((((long ) (ra -> denom ) ) & 0x1 ) && ((((long ) (ra -> denom ) ) >> 1 ) == 1 ) ) {
    Scheme_Rational * rx = ra ; 
    ra = rb ; 
    rb = rx ; 
  }
  if ((((long ) (rb -> denom ) ) & 0x1 ) && ((((long ) (rb -> denom ) ) >> 1 ) == 1 ) ) {
    ac = ra -> num ; 
    cd = ra -> denom ; 
    no_normalize = 1 ; 
  }
  else {
#   define XfOrM30_COUNT (0+XfOrM29_COUNT)
#   define SETUP_XfOrM30(x) SETUP_XfOrM29(x)
    ac = FUNCCALL(SETUP_XfOrM30(_), scheme_bin_mult (ra -> num , rb -> denom ) ); 
    cd = FUNCCALL(SETUP_XfOrM30(_), scheme_bin_mult (ra -> denom , rb -> denom ) ); 
  }
  bd = FUNCCALL(SETUP_XfOrM29(_), scheme_bin_mult (ra -> denom , rb -> num ) ); 
  sum = FUNCCALL(SETUP_XfOrM29(_), scheme_bin_plus (ac , bd ) ); 
  if (no_normalize )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(make_rational (sum , cd , 0 ) )) RET_VALUE_EMPTY_END ; 
  else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_rational (sum , cd ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_rational_subtract (const Scheme_Object * a , const Scheme_Object * b ) {
  Scheme_Object * __funcarg7 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(a, 0)));
# define XfOrM33_COUNT (1)
# define SETUP_XfOrM33(x) SETUP(XfOrM33_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg7 = FUNCCALL(SETUP_XfOrM33(_), scheme_rational_negate (b ) ), FUNCCALL_EMPTY(scheme_rational_add (a , __funcarg7 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_rational_add1 (const Scheme_Object * n ) {
  Small_Rational s ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(s.num, 0), PUSH(s.denom, 1)));
# define XfOrM34_COUNT (2)
# define SETUP_XfOrM34(x) SETUP(XfOrM34_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s.num = NULLED_OUT ; 
  s.denom = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM34(_), scheme_rational_add (scheme_make_small_rational (1 , & s ) , n ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_rational_sub1 (const Scheme_Object * n ) {
  Small_Rational s ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(s.num, 0), PUSH(s.denom, 1)));
# define XfOrM35_COUNT (2)
# define SETUP_XfOrM35(x) SETUP(XfOrM35_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s.num = NULLED_OUT ; 
  s.denom = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM35(_), scheme_rational_add (n , scheme_make_small_rational (- 1 , & s ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_rational_multiply (const Scheme_Object * a , const Scheme_Object * b ) {
  Scheme_Rational * ra = (Scheme_Rational * ) a ; 
  Scheme_Rational * rb = (Scheme_Rational * ) b ; 
  Scheme_Object * gcd_ps , * gcd_rq , * p_ , * r_ , * q_ , * s_ ; 
  PREPARE_VAR_STACK_ONCE(8);
  BLOCK_SETUP_TOP((PUSH(s_, 0), PUSH(p_, 1), PUSH(q_, 2), PUSH(ra, 3), PUSH(gcd_ps, 4), PUSH(r_, 5), PUSH(gcd_rq, 6), PUSH(rb, 7)));
# define XfOrM36_COUNT (8)
# define SETUP_XfOrM36(x) SETUP(XfOrM36_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  gcd_ps = NULLED_OUT ; 
  gcd_rq = NULLED_OUT ; 
  p_ = NULLED_OUT ; 
  r_ = NULLED_OUT ; 
  q_ = NULLED_OUT ; 
  s_ = NULLED_OUT ; 
  gcd_ps = FUNCCALL(SETUP_XfOrM36(_), scheme_bin_gcd (ra -> num , rb -> denom ) ); 
  gcd_rq = FUNCCALL_AGAIN(scheme_bin_gcd (rb -> num , ra -> denom ) ); 
  p_ = FUNCCALL_AGAIN(scheme_bin_quotient (ra -> num , gcd_ps ) ); 
  r_ = FUNCCALL_AGAIN(scheme_bin_quotient (rb -> num , gcd_rq ) ); 
  q_ = FUNCCALL_AGAIN(scheme_bin_quotient (ra -> denom , gcd_rq ) ); 
  s_ = FUNCCALL_AGAIN(scheme_bin_quotient (rb -> denom , gcd_ps ) ); 
  p_ = FUNCCALL_AGAIN(scheme_bin_mult (p_ , r_ ) ); 
  q_ = FUNCCALL_AGAIN(scheme_bin_mult (q_ , s_ ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_rational (p_ , q_ ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_rational_max (const Scheme_Object * a , const Scheme_Object * b ) {
  int lt ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(a, 0), PUSH(b, 1)));
# define XfOrM37_COUNT (2)
# define SETUP_XfOrM37(x) SETUP(XfOrM37_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  lt = FUNCCALL(SETUP_XfOrM37(_), scheme_rational_lt (a , b ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_rational_normalize (lt ? b : a ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_rational_min (const Scheme_Object * a , const Scheme_Object * b ) {
  int lt ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(a, 0), PUSH(b, 1)));
# define XfOrM38_COUNT (2)
# define SETUP_XfOrM38(x) SETUP(XfOrM38_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  lt = FUNCCALL(SETUP_XfOrM38(_), scheme_rational_lt (a , b ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_rational_normalize (lt ? a : b ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * negate_simple (Scheme_Object * v ) {
  /* No conversion */
  if ((((long ) (v ) ) & 0x1 ) )
    return scheme_make_integer_value (- (((long ) (v ) ) >> 1 ) ) ; 
  else return scheme_bignum_negate (v ) ; 
}
Scheme_Object * scheme_rational_divide (const Scheme_Object * n , const Scheme_Object * d ) {
  Scheme_Rational * rd = (Scheme_Rational * ) d , * rn = (Scheme_Rational * ) n ; 
  Scheme_Rational d_inv ; 
  Scheme_Object * __funcarg8 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(n, 0), PUSH(rd, 1), PUSH(d_inv.num, 2), PUSH(d_inv.denom, 3)));
# define XfOrM40_COUNT (4)
# define SETUP_XfOrM40(x) SETUP(XfOrM40_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  d_inv.num = NULLED_OUT ; 
  d_inv.denom = NULLED_OUT ; 
  if (((((long ) (rn -> num ) ) & 0x1 ) && (((((long ) (rn -> num ) ) >> 1 ) == 1 ) || ((((long ) (rn -> num ) ) >> 1 ) == - 1 ) ) ) && ((((long ) (rn -> denom ) ) & 0x1 ) && (((long ) (rn -> denom ) ) >> 1 ) == 1 ) ) {
    int negate = ((((long ) (rn -> num ) ) >> 1 ) == - 1 ) ; 
#   define XfOrM41_COUNT (0+XfOrM40_COUNT)
#   define SETUP_XfOrM41(x) SETUP_XfOrM40(x)
    if ((((long ) (rd -> num ) ) & 0x1 ) ) {
#     define XfOrM44_COUNT (0+XfOrM41_COUNT)
#     define SETUP_XfOrM44(x) SETUP_XfOrM41(x)
      if (((((long ) (rd -> num ) ) >> 1 ) == 1 ) ) {
#       define XfOrM46_COUNT (0+XfOrM44_COUNT)
#       define SETUP_XfOrM46(x) SETUP_XfOrM44(x)
        if (negate )
          RET_VALUE_START (FUNCCALL(SETUP_XfOrM46(_), negate_simple (rd -> denom ) )) RET_VALUE_END ; 
        else RET_VALUE_START (rd -> denom ) RET_VALUE_END ; 
      }
      if ((((long ) (rd -> num ) ) >> 1 ) == - 1 ) {
#       define XfOrM45_COUNT (0+XfOrM44_COUNT)
#       define SETUP_XfOrM45(x) SETUP_XfOrM44(x)
        if (negate )
          RET_VALUE_START (rd -> denom ) RET_VALUE_END ; 
        else RET_VALUE_START (FUNCCALL(SETUP_XfOrM45(_), negate_simple (rd -> denom ) )) RET_VALUE_END ; 
      }
    }
    if ((((((long ) (rd -> num ) ) & 0x1 ) ) && ((((long ) (rd -> num ) ) >> 1 ) < 0 ) ) || (! (((long ) (rd -> num ) ) & 0x1 ) && ! ((& ((Scheme_Bignum * ) rd -> num ) -> iso ) -> so . keyex & 0x1 ) ) ) {
      Scheme_Object * v ; 
      BLOCK_SETUP((PUSH(v, 0+XfOrM41_COUNT)));
#     define XfOrM43_COUNT (1+XfOrM41_COUNT)
#     define SETUP_XfOrM43(x) SETUP(XfOrM43_COUNT)
      v = NULLED_OUT ; 
      v = negate ? rd -> denom : FUNCCALL(SETUP_XfOrM43(_), negate_simple (rd -> denom ) ); 
      RET_VALUE_START ((__funcarg8 = FUNCCALL(SETUP_XfOrM43(_), negate_simple (rd -> num ) ), FUNCCALL_AGAIN(make_rational (v , __funcarg8 , 0 ) )) ) RET_VALUE_END ; 
    }
    else {
      Scheme_Object * v ; 
      BLOCK_SETUP((PUSH(v, 0+XfOrM41_COUNT)));
#     define XfOrM42_COUNT (1+XfOrM41_COUNT)
#     define SETUP_XfOrM42(x) SETUP(XfOrM42_COUNT)
      v = NULLED_OUT ; 
      v = negate ? FUNCCALL(SETUP_XfOrM42(_), negate_simple (rd -> denom ) ): rd -> denom ; 
      RET_VALUE_START (FUNCCALL(SETUP_XfOrM42(_), make_rational (v , rd -> num , 0 ) )) RET_VALUE_END ; 
    }
  }
  d_inv . so . type = scheme_rational_type ; 
  d_inv . denom = rd -> num ; 
  d_inv . num = rd -> denom ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM40(_), scheme_rational_multiply (n , (Scheme_Object * ) & d_inv ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_rational_power (const Scheme_Object * o , const Scheme_Object * p ) {
  double b , e , v ; 
  Scheme_Object * __funcarg11 = NULLED_OUT ; 
  Scheme_Object * __funcarg10 = NULLED_OUT ; 
  Scheme_Object * __funcarg9 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(__funcarg9, 0), PUSH(p, 1), PUSH(o, 2)));
# define XfOrM47_COUNT (3)
# define SETUP_XfOrM47(x) SETUP(XfOrM47_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (((Scheme_Rational * ) p ) -> denom == one ) {
    Scheme_Object * a [2 ] , * n ; 
    BLOCK_SETUP((PUSH(n, 0+XfOrM47_COUNT), PUSHARRAY(a, 2, 1+XfOrM47_COUNT)));
#   define XfOrM50_COUNT (4+XfOrM47_COUNT)
#   define SETUP_XfOrM50(x) SETUP(XfOrM50_COUNT)
    a[0] = NULLED_OUT ; 
    a[1] = NULLED_OUT ; 
    n = NULLED_OUT ; 
    a [0 ] = ((Scheme_Rational * ) o ) -> num ; 
    a [1 ] = ((Scheme_Rational * ) p ) -> num ; 
    n = FUNCCALL(SETUP_XfOrM50(_), scheme_expt (2 , a ) ); 
    a [0 ] = ((Scheme_Rational * ) o ) -> denom ; 
    RET_VALUE_START ((__funcarg11 = FUNCCALL(SETUP_XfOrM50(_), scheme_expt (2 , a ) ), FUNCCALL_AGAIN(make_rational (n , __funcarg11 , 0 ) )) ) RET_VALUE_END ; 
  }
  if ((scheme_is_rational_positive (o ) ) ) {
#   define XfOrM49_COUNT (0+XfOrM47_COUNT)
#   define SETUP_XfOrM49(x) SETUP_XfOrM47(x)
    b = scheme_rational_to_double (o ) ; 
    e = scheme_rational_to_double (p ) ; 
    v = pow (b , e ) ; 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_double (v ) )) RET_VALUE_EMPTY_END ; 
  }
  else {
#   define XfOrM48_COUNT (0+XfOrM47_COUNT)
#   define SETUP_XfOrM48(x) SETUP_XfOrM47(x)
    RET_VALUE_START ((__funcarg9 = FUNCCALL(SETUP_XfOrM48(_), scheme_real_to_complex (o ) ), __funcarg10 = FUNCCALL(SETUP_XfOrM48(_), scheme_real_to_complex (p ) ), FUNCCALL_EMPTY(scheme_complex_power (__funcarg9 , __funcarg10 ) )) ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_rational_truncate (const Scheme_Object * o ) {
  /* No conversion */
  Scheme_Rational * r = (Scheme_Rational * ) o ; 
  return scheme_bin_quotient (r -> num , r -> denom ) ; 
}
Scheme_Object * scheme_rational_floor (const Scheme_Object * o ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(1);
# define XfOrM52_COUNT (0)
# define SETUP_XfOrM52(x) SETUP(XfOrM52_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((scheme_is_rational_positive (o ) ) )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_rational_truncate (o ) )) RET_VALUE_EMPTY_END ; 
  else {
    Scheme_Object * r ; 
    BLOCK_SETUP((PUSH(r, 0+XfOrM52_COUNT)));
#   define XfOrM53_COUNT (1+XfOrM52_COUNT)
#   define SETUP_XfOrM53(x) SETUP(XfOrM53_COUNT)
    r = NULLED_OUT ; 
    r = FUNCCALL(SETUP_XfOrM53(_), scheme_rational_truncate (o ) ); 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM53(_), scheme_sub1 (1 , & r ) )) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_rational_ceiling (const Scheme_Object * o ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(1);
# define XfOrM54_COUNT (0)
# define SETUP_XfOrM54(x) SETUP(XfOrM54_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! (scheme_is_rational_positive (o ) ) )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_rational_truncate (o ) )) RET_VALUE_EMPTY_END ; 
  else {
    Scheme_Object * r ; 
    BLOCK_SETUP((PUSH(r, 0+XfOrM54_COUNT)));
#   define XfOrM55_COUNT (1+XfOrM54_COUNT)
#   define SETUP_XfOrM55(x) SETUP(XfOrM55_COUNT)
    r = NULLED_OUT ; 
    r = FUNCCALL(SETUP_XfOrM55(_), scheme_rational_truncate (o ) ); 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM55(_), scheme_add1 (1 , & r ) )) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_rational_round (const Scheme_Object * o ) {
  Scheme_Rational * r = (Scheme_Rational * ) o ; 
  Scheme_Object * q , * qd , * delta , * half ; 
  int more = 0 , can_eq_half , negative ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(half, 0), PUSH(delta, 1), PUSH(r, 2), PUSH(q, 3), PUSH(qd, 4)));
# define XfOrM56_COUNT (5)
# define SETUP_XfOrM56(x) SETUP(XfOrM56_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  q = NULLED_OUT ; 
  qd = NULLED_OUT ; 
  delta = NULLED_OUT ; 
  half = NULLED_OUT ; 
  negative = ! (scheme_is_rational_positive (o ) ) ; 
  q = FUNCCALL(SETUP_XfOrM56(_), scheme_bin_quotient (r -> num , r -> denom ) ); 
  qd = FUNCCALL_AGAIN(scheme_bin_mult (q , r -> denom ) ); 
  if (negative )
    delta = FUNCCALL(SETUP_XfOrM56(_), scheme_bin_minus (qd , r -> num ) ); 
  else delta = FUNCCALL(SETUP_XfOrM56(_), scheme_bin_minus (r -> num , qd ) ); 
  half = FUNCCALL(SETUP_XfOrM56(_), scheme_bin_quotient (r -> denom , ((Scheme_Object * ) (void * ) (long ) ((((long ) (2 ) ) << 1 ) | 0x1 ) ) ) ); 
  can_eq_half = (((FUNCCALL(SETUP_XfOrM56(_), scheme_odd_p (1 , & r -> denom ) )) ) == (scheme_false ) ) ; 
  if ((((long ) (half ) ) & 0x1 ) && (((long ) (delta ) ) & 0x1 ) ) {
#   define XfOrM59_COUNT (0+XfOrM56_COUNT)
#   define SETUP_XfOrM59(x) SETUP_XfOrM56(x)
    if (can_eq_half && ((((long ) (delta ) ) >> 1 ) == (((long ) (half ) ) >> 1 ) ) )
      more = (! (((FUNCCALL(SETUP_XfOrM59(_), scheme_odd_p (1 , & q ) )) ) == (scheme_false ) ) ) ; 
    else more = ((((long ) (delta ) ) >> 1 ) > (((long ) (half ) ) >> 1 ) ) ; 
  }
  else if (((Scheme_Type ) (((((long ) (delta ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (delta ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) && ((Scheme_Type ) (((((long ) (half ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (half ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) {
#   define XfOrM58_COUNT (0+XfOrM56_COUNT)
#   define SETUP_XfOrM58(x) SETUP_XfOrM56(x)
    if (can_eq_half && ((scheme_bignum_eq (delta , half ) ) ) )
      more = (! (((FUNCCALL(SETUP_XfOrM58(_), scheme_odd_p (1 , & q ) )) ) == (scheme_false ) ) ) ; 
    else more = ! (scheme_bignum_lt (delta , half ) ) ; 
  }
  else more = ((Scheme_Type ) (((((long ) (delta ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (delta ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ; 
  if (more ) {
#   define XfOrM57_COUNT (0+XfOrM56_COUNT)
#   define SETUP_XfOrM57(x) SETUP_XfOrM56(x)
    if (negative )
      q = FUNCCALL(SETUP_XfOrM57(_), scheme_sub1 (1 , & q ) ); 
    else q = FUNCCALL(SETUP_XfOrM57(_), scheme_add1 (1 , & q ) ); 
  }
  RET_VALUE_START (q ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_rational_sqrt (const Scheme_Object * o ) {
  Scheme_Rational * r = (Scheme_Rational * ) o ; 
  Scheme_Object * n , * d ; 
  double v ; 
  PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(n, 0), PUSH(o, 1), PUSH(r, 2), PUSH(d, 3)));
# define XfOrM60_COUNT (4)
# define SETUP_XfOrM60(x) SETUP(XfOrM60_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  n = NULLED_OUT ; 
  d = NULLED_OUT ; 
  n = FUNCCALL(SETUP_XfOrM60(_), scheme_integer_sqrt (r -> num ) ); 
  if (! ((Scheme_Type ) (((((long ) (n ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ) {
#   define XfOrM61_COUNT (0+XfOrM60_COUNT)
#   define SETUP_XfOrM61(x) SETUP_XfOrM60(x)
    d = FUNCCALL(SETUP_XfOrM61(_), scheme_integer_sqrt (r -> denom ) ); 
    if (! ((Scheme_Type ) (((((long ) (d ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (d ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) )
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(make_rational (n , d , 0 ) )) RET_VALUE_EMPTY_END ; 
  }
  v = sqrt (scheme_rational_to_double (o ) ) ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_double (v ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static double do_double_div (double n , double d ) {
  return n / d ; 
}
double scheme_rational_to_double (const Scheme_Object * o ) {
  Scheme_Rational * r = (Scheme_Rational * ) o ; 
  double n , d ; 
  int ns , ds ; 
  if ((((long ) (r -> num ) ) & 0x1 ) ) {
    n = (double ) (((long ) (r -> num ) ) >> 1 ) ; 
    ns = 0 ; 
  }
  else n = scheme_bignum_to_double_inf_info (r -> num , 0 , & ns ) ; 
  if ((((long ) (r -> denom ) ) & 0x1 ) ) {
    d = (double ) (((long ) (r -> denom ) ) >> 1 ) ; 
    ds = 0 ; 
  }
  else d = scheme_bignum_to_double_inf_info (r -> denom , 0 , & ds ) ; 
  if (ns && ds ) {
    int m ; 
    m = (ns < ds ) ? ds : ns ; 
    n = scheme_bignum_to_double_inf_info (r -> num , m , ((void * ) 0 ) ) ; 
    d = scheme_bignum_to_double_inf_info (r -> denom , m , ((void * ) 0 ) ) ; 
  }
  return do_double_div (n , d ) ; 
}
Scheme_Object * scheme_rational_from_double (double d ) {
  double frac , i ; 
  int count , exponent , is_neg ; 
  Scheme_Object * int_part , * frac_part , * frac_num , * frac_denom , * two , * result ; 
  double __funcarg13 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(int_part, 0), PUSH(two, 1), PUSH(frac_denom, 2), PUSH(frac_num, 3), PUSH(result, 4), PUSH(frac_part, 5)));
# define XfOrM62_COUNT (6)
# define SETUP_XfOrM62(x) SETUP(XfOrM62_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  int_part = NULLED_OUT ; 
  frac_part = NULLED_OUT ; 
  frac_num = NULLED_OUT ; 
  frac_denom = NULLED_OUT ; 
  two = NULLED_OUT ; 
  result = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM62(_), scheme_check_double ("inexact->exact" , d , "exact" ) ); 
  is_neg = (d < 0 ) ; 
  frac = FUNCCALL(SETUP_XfOrM62(_), modf ((double ) d , & i ) ); 
  (void ) FUNCCALL(SETUP_XfOrM62(_), frexp (d , & exponent ) ); 
  int_part = FUNCCALL(SETUP_XfOrM62(_), scheme_bignum_from_double (i ) ); 
  if (! frac ) {
    RET_VALUE_START (int_part ) RET_VALUE_END ; 
  }
  frac_num = ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
  frac_denom = one ; 
  two = ((Scheme_Object * ) (void * ) (long ) ((((long ) (2 ) ) << 1 ) | 0x1 ) ) ; 
  count = 0 ; 
  while (frac ) {
    count ++ ; 
#   define XfOrM65_COUNT (0+XfOrM62_COUNT)
#   define SETUP_XfOrM65(x) SETUP_XfOrM62(x)
    frac_num = FUNCCALL(SETUP_XfOrM65(_), scheme_bin_mult (frac_num , two ) ); 
    frac_denom = FUNCCALL(SETUP_XfOrM65(_), scheme_bin_mult (frac_denom , two ) ); 
    frac = (__funcarg13 = FUNCCALL(SETUP_XfOrM65(_), ldexp (frac , 1 ) ), FUNCCALL_AGAIN(modf (__funcarg13 , & i ) )) ; 
    if (i ) {
#     define XfOrM66_COUNT (0+XfOrM65_COUNT)
#     define SETUP_XfOrM66(x) SETUP_XfOrM65(x)
      if (is_neg )
        frac_num = FUNCCALL(SETUP_XfOrM66(_), scheme_bin_minus (frac_num , one ) ); 
      else frac_num = FUNCCALL(SETUP_XfOrM66(_), scheme_bin_plus (frac_num , one ) ); 
    }
  }
  frac_part = FUNCCALL(SETUP_XfOrM62(_), scheme_bin_div (frac_num , frac_denom ) ); 
  result = FUNCCALL(SETUP_XfOrM62(_), scheme_bin_plus (int_part , frac_part ) ); 
  RET_VALUE_START (result ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
