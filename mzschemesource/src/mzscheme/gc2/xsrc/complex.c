#include "precomp.h"
enum {
  _ISupper = ((0 ) < 8 ? ((1 << (0 ) ) << 8 ) : ((1 << (0 ) ) >> 8 ) ) , _ISlower = ((1 ) < 8 ? ((1 << (1 ) ) << 8 ) : ((1 << (1 ) ) >> 8 ) ) , _ISalpha = ((2 ) < 8 ? ((1 << (2 ) ) << 8 ) : ((1 << (2 ) ) >> 8 ) ) , _ISdigit = ((3 ) < 8 ? ((1 << (3 ) ) << 8 ) : ((1 << (3 ) ) >> 8 ) ) , _ISxdigit = ((4 ) < 8 ? ((1 << (4 ) ) << 8 ) : ((1 << (4 ) ) >> 8 ) ) , _ISspace = ((5 ) < 8 ? ((1 << (5 ) ) << 8 ) : ((1 << (5 ) ) >> 8 ) ) , _ISprint = ((6 ) < 8 ? ((1 << (6 ) ) << 8 ) : ((1 << (6 ) ) >> 8 ) ) , _ISgraph = ((7 ) < 8 ? ((1 << (7 ) ) << 8 ) : ((1 << (7 ) ) >> 8 ) ) , _ISblank = ((8 ) < 8 ? ((1 << (8 ) ) << 8 ) : ((1 << (8 ) ) >> 8 ) ) , _IScntrl = ((9 ) < 8 ? ((1 << (9 ) ) << 8 ) : ((1 << (9 ) ) >> 8 ) ) , _ISpunct = ((10 ) < 8 ? ((1 << (10 ) ) << 8 ) : ((1 << (10 ) ) >> 8 ) ) , _ISalnum = ((11 ) < 8 ? ((1 << (11 ) ) << 8 ) : ((1 << (11 ) ) >> 8 ) ) }
; 
extern double atan2 (double __y , double __x ) __attribute__ ((__nothrow__ ) ) ; 
extern double cos (double __x ) __attribute__ ((__nothrow__ ) ) ; 
extern double sin (double __x ) __attribute__ ((__nothrow__ ) ) ; 
extern double exp (double __x ) __attribute__ ((__nothrow__ ) ) ; 
extern double log (double __x ) __attribute__ ((__nothrow__ ) ) ; 
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
static Scheme_Object * make_complex (const Scheme_Object * r , const Scheme_Object * i , int normalize ) {
  Scheme_Complex * c ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(c, 0), PUSH(r, 1), PUSH(i, 2)));
# define XfOrM1_COUNT (3)
# define SETUP_XfOrM1(x) SETUP(XfOrM1_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  c = NULLED_OUT ; 
  c = (Scheme_Complex * ) FUNCCALL(SETUP_XfOrM1(_), GC_malloc_one_small_dirty_tagged ((((sizeof (Scheme_Complex ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) ); 
  ((& c -> so ) -> keyex = 0 ) ; 
  c -> so . type = scheme_complex_type ; 
  c -> r = (Scheme_Object * ) r ; 
  c -> i = (Scheme_Object * ) i ; 
  if (normalize )
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM1(_), scheme_complex_normalize ((Scheme_Object * ) c ) )) RET_VALUE_END ; 
  else RET_VALUE_START ((Scheme_Object * ) c ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_complex (const Scheme_Object * r , const Scheme_Object * i ) {
  /* No conversion */
  return make_complex (r , i , 1 ) ; 
}
Scheme_Object * scheme_real_to_complex (const Scheme_Object * n ) {
  /* No conversion */
  return make_complex (n , ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) , 0 ) ; 
}
Scheme_Object * scheme_make_small_complex (const Scheme_Object * n , Small_Complex * s ) {
  s -> so . type = scheme_complex_type ; 
  s -> r = (Scheme_Object * ) n ; 
  s -> i = ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
  return (Scheme_Object * ) s ; 
}
int scheme_is_complex_exact (const Scheme_Object * o ) {
  /* No conversion */
  Scheme_Complex * c = (Scheme_Complex * ) o ; 
  return ! ((Scheme_Type ) (((((long ) (c -> r ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (c -> r ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) && ! ((Scheme_Type ) (((((long ) (c -> i ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (c -> i ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ; 
}
Scheme_Object * scheme_complex_normalize (const Scheme_Object * o ) {
  Scheme_Complex * c = (Scheme_Complex * ) o ; 
  double __funcarg5 ; 
  double __funcarg4 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(c, 0)));
# define XfOrM5_COUNT (1)
# define SETUP_XfOrM5(x) SETUP(XfOrM5_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (c -> i == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) )
    RET_VALUE_START (c -> r ) RET_VALUE_END ; 
  if (c -> r == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) {
    if (((Scheme_Type ) (((((long ) (c -> i ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (c -> i ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ) {
      if ((((Scheme_Double * ) (c -> i ) ) -> double_val ) == 0.0 )
        c -> so . type = scheme_complex_izi_type ; 
    }
    RET_VALUE_START ((Scheme_Object * ) c ) RET_VALUE_END ; 
  }
  if (((Scheme_Type ) (((((long ) (c -> i ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (c -> i ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ) {
#   define XfOrM7_COUNT (0+XfOrM5_COUNT)
#   define SETUP_XfOrM7(x) SETUP_XfOrM5(x)
    if (! ((Scheme_Type ) (((((long ) (c -> r ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (c -> r ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ) {
      Scheme_Object * r ; 
      BLOCK_SETUP((PUSH(r, 0+XfOrM7_COUNT)));
#     define XfOrM8_COUNT (1+XfOrM7_COUNT)
#     define SETUP_XfOrM8(x) SETUP(XfOrM8_COUNT)
      r = NULLED_OUT ; 
      r = (__funcarg5 = FUNCCALL(SETUP_XfOrM8(_), scheme_get_val_as_double (c -> r ) ), FUNCCALL_AGAIN(scheme_make_double (__funcarg5 ) )) ; 
      c -> r = r ; 
    }
    if ((((Scheme_Double * ) (c -> i ) ) -> double_val ) == 0.0 )
      c -> so . type = scheme_complex_izi_type ; 
  }
  else if (((Scheme_Type ) (((((long ) (c -> r ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (c -> r ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ) {
    Scheme_Object * i ; 
    BLOCK_SETUP((PUSH(i, 0+XfOrM5_COUNT)));
#   define XfOrM6_COUNT (1+XfOrM5_COUNT)
#   define SETUP_XfOrM6(x) SETUP(XfOrM6_COUNT)
    i = NULLED_OUT ; 
    i = (__funcarg4 = FUNCCALL(SETUP_XfOrM6(_), scheme_get_val_as_double (c -> i ) ), FUNCCALL_AGAIN(scheme_make_double (__funcarg4 ) )) ; 
    c -> i = i ; 
  }
  RET_VALUE_START ((Scheme_Object * ) c ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_complex_real_part (const Scheme_Object * n ) {
  /* No conversion */
  return ((Scheme_Complex * ) n ) -> r ; 
}
Scheme_Object * scheme_complex_imaginary_part (const Scheme_Object * n ) {
  /* No conversion */
  return ((Scheme_Complex * ) n ) -> i ; 
}
int scheme_complex_eq (const Scheme_Object * a , const Scheme_Object * b ) {
  Scheme_Complex * ca = (Scheme_Complex * ) a ; 
  Scheme_Complex * cb = (Scheme_Complex * ) b ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(cb, 0), PUSH(ca, 1)));
# define XfOrM13_COUNT (2)
# define SETUP_XfOrM13(x) SETUP(XfOrM13_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM13(_), scheme_bin_eq (ca -> r , cb -> r ) )&& FUNCCALL_EMPTY(scheme_bin_eq (ca -> i , cb -> i ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_complex_negate (const Scheme_Object * o ) {
  Scheme_Complex * c = (Scheme_Complex * ) o ; 
  Scheme_Object * __funcarg7 = NULLED_OUT ; 
  Scheme_Object * __funcarg6 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(c, 0), PUSH(__funcarg6, 1)));
# define XfOrM14_COUNT (2)
# define SETUP_XfOrM14(x) SETUP(XfOrM14_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg6 = FUNCCALL(SETUP_XfOrM14(_), scheme_bin_minus (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) , c -> r ) ), __funcarg7 = FUNCCALL(SETUP_XfOrM14(_), scheme_bin_minus (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) , c -> i ) ), FUNCCALL_EMPTY(make_complex (__funcarg6 , __funcarg7 , 0 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_complex_add (const Scheme_Object * a , const Scheme_Object * b ) {
  Scheme_Complex * ca = (Scheme_Complex * ) a ; 
  Scheme_Complex * cb = (Scheme_Complex * ) b ; 
  Scheme_Object * __funcarg9 = NULLED_OUT ; 
  Scheme_Object * __funcarg8 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(__funcarg8, 0), PUSH(cb, 1), PUSH(ca, 2)));
# define XfOrM15_COUNT (3)
# define SETUP_XfOrM15(x) SETUP(XfOrM15_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg8 = FUNCCALL(SETUP_XfOrM15(_), scheme_bin_plus (ca -> r , cb -> r ) ), __funcarg9 = FUNCCALL(SETUP_XfOrM15(_), scheme_bin_plus (ca -> i , cb -> i ) ), FUNCCALL_EMPTY(scheme_make_complex (__funcarg8 , __funcarg9 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_complex_subtract (const Scheme_Object * a , const Scheme_Object * b ) {
  Scheme_Complex * ca = (Scheme_Complex * ) a ; 
  Scheme_Complex * cb = (Scheme_Complex * ) b ; 
  Scheme_Object * __funcarg11 = NULLED_OUT ; 
  Scheme_Object * __funcarg10 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(__funcarg10, 0), PUSH(cb, 1), PUSH(ca, 2)));
# define XfOrM16_COUNT (3)
# define SETUP_XfOrM16(x) SETUP(XfOrM16_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg10 = FUNCCALL(SETUP_XfOrM16(_), scheme_bin_minus (ca -> r , cb -> r ) ), __funcarg11 = FUNCCALL(SETUP_XfOrM16(_), scheme_bin_minus (ca -> i , cb -> i ) ), FUNCCALL_EMPTY(scheme_make_complex (__funcarg10 , __funcarg11 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_complex_add1 (const Scheme_Object * n ) {
  Small_Complex s ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(s.r, 0), PUSH(s.i, 1)));
# define XfOrM17_COUNT (2)
# define SETUP_XfOrM17(x) SETUP(XfOrM17_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s.r = NULLED_OUT ; 
  s.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM17(_), scheme_complex_add (scheme_make_small_complex (((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) , & s ) , n ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_complex_sub1 (const Scheme_Object * n ) {
  Small_Complex s ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(s.r, 0), PUSH(s.i, 1)));
# define XfOrM18_COUNT (2)
# define SETUP_XfOrM18(x) SETUP(XfOrM18_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s.r = NULLED_OUT ; 
  s.i = NULLED_OUT ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM18(_), scheme_complex_add (n , scheme_make_small_complex (((Scheme_Object * ) (void * ) (long ) ((((long ) (- 1 ) ) << 1 ) | 0x1 ) ) , & s ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_complex_multiply (const Scheme_Object * a , const Scheme_Object * b ) {
  Scheme_Complex * ca = (Scheme_Complex * ) a ; 
  Scheme_Complex * cb = (Scheme_Complex * ) b ; 
  Scheme_Object * __funcarg17 = NULLED_OUT ; 
  Scheme_Object * __funcarg16 = NULLED_OUT ; 
  Scheme_Object * __funcarg15 = NULLED_OUT ; 
  Scheme_Object * __funcarg14 = NULLED_OUT ; 
  Scheme_Object * __funcarg13 = NULLED_OUT ; 
  Scheme_Object * __funcarg12 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(__funcarg16, 0), PUSH(__funcarg12, 1), PUSH(__funcarg14, 2), PUSH(cb, 3), PUSH(ca, 4)));
# define XfOrM19_COUNT (5)
# define SETUP_XfOrM19(x) SETUP(XfOrM19_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START ((__funcarg12 = (__funcarg16 = FUNCCALL(SETUP_XfOrM19(_), scheme_bin_mult (ca -> r , cb -> r ) ), __funcarg17 = FUNCCALL(SETUP_XfOrM19(_), scheme_bin_mult (ca -> i , cb -> i ) ), FUNCCALL_AGAIN(scheme_bin_minus (__funcarg16 , __funcarg17 ) )) , __funcarg13 = (__funcarg14 = FUNCCALL(SETUP_XfOrM19(_), scheme_bin_mult (ca -> r , cb -> i ) ), __funcarg15 = FUNCCALL(SETUP_XfOrM19(_), scheme_bin_mult (ca -> i , cb -> r ) ), FUNCCALL_AGAIN(scheme_bin_plus (__funcarg14 , __funcarg15 ) )) , FUNCCALL_EMPTY(scheme_make_complex (__funcarg12 , __funcarg13 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_complex_divide (const Scheme_Object * _n , const Scheme_Object * _d ) {
  Scheme_Complex * cn = (Scheme_Complex * ) _n ; 
  Scheme_Complex * cd = (Scheme_Complex * ) _d ; 
  Scheme_Object * den , * r , * i , * a , * b , * c , * d , * cm , * dm , * aa [1 ] ; 
  int swap ; 
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
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(19);
  BLOCK_SETUP_TOP((PUSH(i, 0), PUSH(a, 1), PUSH(__funcarg25, 2), PUSH(r, 3), PUSHARRAY(aa, 1, 4), PUSH(d, 7), PUSH(b, 8), PUSH(__funcarg37, 9), PUSH(__funcarg34, 10), PUSH(__funcarg39, 11), PUSH(__funcarg27, 12), PUSH(den, 13), PUSH(__funcarg29, 14), PUSH(dm, 15), PUSH(c, 16), PUSH(__funcarg31, 17), PUSH(cm, 18)));
# define XfOrM20_COUNT (19)
# define SETUP_XfOrM20(x) SETUP(XfOrM20_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  den = NULLED_OUT ; 
  r = NULLED_OUT ; 
  i = NULLED_OUT ; 
  a = NULLED_OUT ; 
  b = NULLED_OUT ; 
  c = NULLED_OUT ; 
  d = NULLED_OUT ; 
  cm = NULLED_OUT ; 
  dm = NULLED_OUT ; 
  aa[0] = NULLED_OUT ; 
  if ((cn -> r == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) && (cn -> i == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) )
    RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
  a = cn -> r ; 
  b = cn -> i ; 
  c = cd -> r ; 
  d = cd -> i ; 
  if (c == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) {
#   define XfOrM26_COUNT (0+XfOrM20_COUNT)
#   define SETUP_XfOrM26(x) SETUP_XfOrM20(x)
    i = (__funcarg41 = FUNCCALL(SETUP_XfOrM26(_), scheme_bin_div (a , d ) ), FUNCCALL_AGAIN(scheme_bin_minus (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) , __funcarg41 ) )) ; 
    r = FUNCCALL(SETUP_XfOrM26(_), scheme_bin_div (b , d ) ); 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM26(_), scheme_make_complex (r , i ) )) RET_VALUE_END ; 
  }
  else if (d == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) {
#   define XfOrM25_COUNT (0+XfOrM20_COUNT)
#   define SETUP_XfOrM25(x) SETUP_XfOrM20(x)
    r = FUNCCALL(SETUP_XfOrM25(_), scheme_bin_div (a , c ) ); 
    i = FUNCCALL(SETUP_XfOrM25(_), scheme_bin_div (b , c ) ); 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM25(_), scheme_make_complex (r , i ) )) RET_VALUE_END ; 
  }
  if (! ((Scheme_Type ) (((((long ) (c ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (c ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) && ! ((Scheme_Type ) (((((long ) (d ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (d ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ) {
#   define XfOrM24_COUNT (0+XfOrM20_COUNT)
#   define SETUP_XfOrM24(x) SETUP_XfOrM20(x)
    cm = (__funcarg39 = FUNCCALL(SETUP_XfOrM24(_), scheme_bin_mult (c , c ) ), __funcarg40 = FUNCCALL(SETUP_XfOrM24(_), scheme_bin_mult (d , d ) ), FUNCCALL_AGAIN(scheme_bin_plus (__funcarg39 , __funcarg40 ) )) ; 
    r = (__funcarg36 = (__funcarg37 = FUNCCALL(SETUP_XfOrM24(_), scheme_bin_mult (c , a ) ), __funcarg38 = FUNCCALL(SETUP_XfOrM24(_), scheme_bin_mult (d , b ) ), FUNCCALL_AGAIN(scheme_bin_plus (__funcarg37 , __funcarg38 ) )) , FUNCCALL_AGAIN(scheme_bin_div (__funcarg36 , cm ) )) ; 
    i = (__funcarg33 = (__funcarg34 = FUNCCALL(SETUP_XfOrM24(_), scheme_bin_mult (c , b ) ), __funcarg35 = FUNCCALL(SETUP_XfOrM24(_), scheme_bin_mult (d , a ) ), FUNCCALL_AGAIN(scheme_bin_minus (__funcarg34 , __funcarg35 ) )) , FUNCCALL_AGAIN(scheme_bin_div (__funcarg33 , cm ) )) ; 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM24(_), scheme_make_complex (r , i ) )) RET_VALUE_END ; 
  }
  if ((scheme_is_zero (d ) ) ) {
#   define XfOrM23_COUNT (0+XfOrM20_COUNT)
#   define SETUP_XfOrM23(x) SETUP_XfOrM20(x)
    r = (__funcarg31 = FUNCCALL(SETUP_XfOrM23(_), scheme_bin_div (a , c ) ), __funcarg32 = FUNCCALL(SETUP_XfOrM23(_), scheme_bin_mult (d , b ) ), FUNCCALL_AGAIN(scheme_bin_plus (__funcarg31 , __funcarg32 ) )) ; 
    i = (__funcarg29 = FUNCCALL(SETUP_XfOrM23(_), scheme_bin_div (b , c ) ), __funcarg30 = FUNCCALL(SETUP_XfOrM23(_), scheme_bin_mult (d , a ) ), FUNCCALL_AGAIN(scheme_bin_minus (__funcarg29 , __funcarg30 ) )) ; 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM23(_), scheme_make_complex (r , i ) )) RET_VALUE_END ; 
  }
  if ((scheme_is_zero (c ) ) ) {
#   define XfOrM22_COUNT (0+XfOrM20_COUNT)
#   define SETUP_XfOrM22(x) SETUP_XfOrM20(x)
    r = (__funcarg27 = FUNCCALL(SETUP_XfOrM22(_), scheme_bin_div (b , d ) ), __funcarg28 = FUNCCALL(SETUP_XfOrM22(_), scheme_bin_mult (c , a ) ), FUNCCALL_AGAIN(scheme_bin_plus (__funcarg27 , __funcarg28 ) )) ; 
    i = (__funcarg25 = FUNCCALL(SETUP_XfOrM22(_), scheme_bin_mult (c , b ) ), __funcarg26 = FUNCCALL(SETUP_XfOrM22(_), scheme_bin_div (a , d ) ), FUNCCALL_AGAIN(scheme_bin_minus (__funcarg25 , __funcarg26 ) )) ; 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM22(_), scheme_make_complex (r , i ) )) RET_VALUE_END ; 
  }
  aa [0 ] = c ; 
  cm = FUNCCALL(SETUP_XfOrM20(_), scheme_abs (1 , aa ) ); 
  aa [0 ] = d ; 
  dm = FUNCCALL(SETUP_XfOrM20(_), scheme_abs (1 , aa ) ); 
  if (FUNCCALL(SETUP_XfOrM20(_), scheme_bin_lt (cm , dm ) )) {
    cm = a ; 
    a = b ; 
    b = cm ; 
    cm = c ; 
    c = d ; 
    d = cm ; 
    swap = 1 ; 
  }
  else swap = 0 ; 
  r = FUNCCALL(SETUP_XfOrM20(_), scheme_bin_div (c , d ) ); 
  den = (__funcarg24 = FUNCCALL(SETUP_XfOrM20(_), scheme_bin_mult (c , r ) ), FUNCCALL_AGAIN(scheme_bin_plus (d , __funcarg24 ) )) ; 
  if (swap )
    i = (__funcarg22 = (__funcarg23 = FUNCCALL(SETUP_XfOrM20(_), scheme_bin_mult (b , r ) ), FUNCCALL_AGAIN(scheme_bin_minus (a , __funcarg23 ) )) , FUNCCALL_AGAIN(scheme_bin_div (__funcarg22 , den ) )) ; 
  else i = (__funcarg20 = (__funcarg21 = FUNCCALL(SETUP_XfOrM20(_), scheme_bin_mult (b , r ) ), FUNCCALL_AGAIN(scheme_bin_minus (__funcarg21 , a ) )) , FUNCCALL_AGAIN(scheme_bin_div (__funcarg20 , den ) )) ; 
  r = (__funcarg18 = (__funcarg19 = FUNCCALL(SETUP_XfOrM20(_), scheme_bin_mult (a , r ) ), FUNCCALL_AGAIN(scheme_bin_plus (b , __funcarg19 ) )) , FUNCCALL_AGAIN(scheme_bin_div (__funcarg18 , den ) )) ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM20(_), scheme_make_complex (r , i ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_complex_power (const Scheme_Object * base , const Scheme_Object * exponent ) {
  Scheme_Complex * cb = (Scheme_Complex * ) base ; 
  Scheme_Complex * ce = (Scheme_Complex * ) exponent ; 
  double a , b , c , d , bm , ba , nm , na , r1 , r2 ; 
  Scheme_Object * __funcarg43 = NULLED_OUT ; 
  Scheme_Object * __funcarg42 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(ce, 0), PUSH(__funcarg42, 1), PUSH(cb, 2)));
# define XfOrM27_COUNT (3)
# define SETUP_XfOrM27(x) SETUP(XfOrM27_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if ((ce -> i == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) && ! ((Scheme_Type ) (((((long ) (ce -> r ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ce -> r ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ) {
#   define XfOrM28_COUNT (0+XfOrM27_COUNT)
#   define SETUP_XfOrM28(x) SETUP_XfOrM27(x)
    if ((((long ) (ce -> r ) ) & 0x1 ) || ((Scheme_Type ) (((((long ) (ce -> r ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ce -> r ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_generic_integer_power (base , ce -> r ) )) RET_VALUE_EMPTY_END ; 
  }
  a = FUNCCALL(SETUP_XfOrM27(_), scheme_get_val_as_double (cb -> r ) ); 
  b = FUNCCALL(SETUP_XfOrM27(_), scheme_get_val_as_double (cb -> i ) ); 
  c = FUNCCALL_AGAIN(scheme_get_val_as_double (ce -> r ) ); 
  d = FUNCCALL_AGAIN(scheme_get_val_as_double (ce -> i ) ); 
  bm = sqrt (a * a + b * b ) ; 
  ba = atan2 (b , a ) ; 
  nm = pow (bm , c ) * exp (- (ba * d ) ) ; 
  na = log (bm ) * d + ba * c ; 
  r1 = nm * cos (na ) ; 
  r2 = nm * sin (na ) ; 
  RET_VALUE_START ((__funcarg42 = FUNCCALL(SETUP_XfOrM27(_), scheme_make_double (r1 ) ), __funcarg43 = FUNCCALL(SETUP_XfOrM27(_), scheme_make_double (r2 ) ), FUNCCALL_EMPTY(scheme_make_complex (__funcarg42 , __funcarg43 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_complex_sqrt (const Scheme_Object * o ) {
  Scheme_Complex * c = (Scheme_Complex * ) o ; 
  Scheme_Object * r , * i , * ssq , * srssq , * nrsq , * prsq , * nr , * ni ; 
  Scheme_Object * __funcarg47 = NULLED_OUT ; 
  Scheme_Object * __funcarg46 = NULLED_OUT ; 
  Scheme_Object * __funcarg45 = NULLED_OUT ; 
  Scheme_Object * __funcarg44 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(13);
  BLOCK_SETUP_TOP((PUSH(i, 0), PUSH(r, 1), PUSH(__funcarg46, 2), PUSH(prsq, 3), PUSH(ni, 4), PUSH(ssq, 5), PUSH(nrsq, 6), PUSH(o, 7), PUSH(nr, 8), PUSH(srssq, 9)));
# define XfOrM29_COUNT (10)
# define SETUP_XfOrM29(x) SETUP(XfOrM29_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  r = NULLED_OUT ; 
  i = NULLED_OUT ; 
  ssq = NULLED_OUT ; 
  srssq = NULLED_OUT ; 
  nrsq = NULLED_OUT ; 
  prsq = NULLED_OUT ; 
  nr = NULLED_OUT ; 
  ni = NULLED_OUT ; 
  r = c -> r ; 
  i = c -> i ; 
  ssq = (__funcarg46 = FUNCCALL(SETUP_XfOrM29(_), scheme_bin_mult (r , r ) ), __funcarg47 = FUNCCALL(SETUP_XfOrM29(_), scheme_bin_mult (i , i ) ), FUNCCALL_AGAIN(scheme_bin_plus (__funcarg46 , __funcarg47 ) )) ; 
  srssq = FUNCCALL_AGAIN(scheme_sqrt (1 , & ssq ) ); 
  if (((Scheme_Type ) (((((long ) (srssq ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (srssq ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ) {
    Scheme_Object * a [2 ] ; 
    BLOCK_SETUP((PUSHARRAY(a, 2, 0+XfOrM29_COUNT)));
#   define XfOrM30_COUNT (3+XfOrM29_COUNT)
#   define SETUP_XfOrM30(x) SETUP(XfOrM30_COUNT)
    a[0] = NULLED_OUT ; 
    a[1] = NULLED_OUT ; 
    a [0 ] = (Scheme_Object * ) o ; 
    a [1 ] = FUNCCALL(SETUP_XfOrM30(_), scheme_make_double (0.5 ) ); 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM30(_), scheme_expt (2 , a ) )) RET_VALUE_END ; 
  }
  nrsq = (__funcarg45 = FUNCCALL(SETUP_XfOrM29(_), scheme_bin_minus (srssq , r ) ), FUNCCALL_AGAIN(scheme_bin_div (__funcarg45 , ((Scheme_Object * ) (void * ) (long ) ((((long ) (2 ) ) << 1 ) | 0x1 ) ) ) )) ; 
  nr = FUNCCALL(SETUP_XfOrM29(_), scheme_sqrt (1 , & nrsq ) ); 
  if ((scheme_is_negative (i ) ) )
    nr = FUNCCALL(SETUP_XfOrM29(_), scheme_bin_minus (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) , nr ) ); 
  prsq = (__funcarg44 = FUNCCALL(SETUP_XfOrM29(_), scheme_bin_plus (srssq , r ) ), FUNCCALL_AGAIN(scheme_bin_div (__funcarg44 , ((Scheme_Object * ) (void * ) (long ) ((((long ) (2 ) ) << 1 ) | 0x1 ) ) ) )) ; 
  ni = FUNCCALL_AGAIN(scheme_sqrt (1 , & prsq ) ); 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM29(_), scheme_make_complex (ni , nr ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
