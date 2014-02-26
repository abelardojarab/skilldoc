#include "precomp.h"
enum {
  _ISupper = ((0 ) < 8 ? ((1 << (0 ) ) << 8 ) : ((1 << (0 ) ) >> 8 ) ) , _ISlower = ((1 ) < 8 ? ((1 << (1 ) ) << 8 ) : ((1 << (1 ) ) >> 8 ) ) , _ISalpha = ((2 ) < 8 ? ((1 << (2 ) ) << 8 ) : ((1 << (2 ) ) >> 8 ) ) , _ISdigit = ((3 ) < 8 ? ((1 << (3 ) ) << 8 ) : ((1 << (3 ) ) >> 8 ) ) , _ISxdigit = ((4 ) < 8 ? ((1 << (4 ) ) << 8 ) : ((1 << (4 ) ) >> 8 ) ) , _ISspace = ((5 ) < 8 ? ((1 << (5 ) ) << 8 ) : ((1 << (5 ) ) >> 8 ) ) , _ISprint = ((6 ) < 8 ? ((1 << (6 ) ) << 8 ) : ((1 << (6 ) ) >> 8 ) ) , _ISgraph = ((7 ) < 8 ? ((1 << (7 ) ) << 8 ) : ((1 << (7 ) ) >> 8 ) ) , _ISblank = ((8 ) < 8 ? ((1 << (8 ) ) << 8 ) : ((1 << (8 ) ) >> 8 ) ) , _IScntrl = ((9 ) < 8 ? ((1 << (9 ) ) << 8 ) : ((1 << (9 ) ) >> 8 ) ) , _ISpunct = ((10 ) < 8 ? ((1 << (10 ) ) << 8 ) : ((1 << (10 ) ) >> 8 ) ) , _ISalnum = ((11 ) < 8 ? ((1 << (11 ) ) << 8 ) : ((1 << (11 ) ) >> 8 ) ) }
; 
extern double exp (double __x ) __attribute__ ((__nothrow__ ) ) ; 
extern double log (double __x ) __attribute__ ((__nothrow__ ) ) ; 
extern double pow (double __x , double __y ) __attribute__ ((__nothrow__ ) ) ; 
extern double sqrt (double __x ) __attribute__ ((__nothrow__ ) ) ; 
extern double ceil (double __x ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__const__ ) ) ; 
extern int isinf (double __value ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__const__ ) ) ; 
extern double remainder (double __x , double __y ) __attribute__ ((__nothrow__ ) ) ; 
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
typedef unsigned long int mp_limb_t ; 
typedef mp_limb_t * mp_ptr ; 
typedef const mp_limb_t * mp_srcptr ; 
typedef long int mp_size_t ; 
typedef long int mp_exp_t ; 
typedef struct {
  int _mp_alloc ; 
  int _mp_size ; 
  mp_limb_t * _mp_d ; 
}
__mpz_struct ; 
typedef __mpz_struct mpz_t [1 ] ; 
typedef struct {
  __mpz_struct _mp_num ; 
  __mpz_struct _mp_den ; 
}
__mpq_struct ; 
typedef __mpq_struct mpq_t [1 ] ; 
typedef struct {
  int _mp_prec ; 
  int _mp_size ; 
  mp_exp_t _mp_exp ; 
  mp_limb_t * _mp_d ; 
}
__mpf_struct ; 
typedef __mpf_struct mpf_t [1 ] ; 
typedef enum {
  GMP_RAND_ALG_DEFAULT = 0 , GMP_RAND_ALG_LC = GMP_RAND_ALG_DEFAULT }
gmp_randalg_t ; 
typedef struct {
  mpz_t a ; 
  unsigned long int c ; 
  mpz_t m ; 
  unsigned long int m2exp ; 
}
__gmp_randata_lc ; 
typedef struct {
  mpz_t seed ; 
  gmp_randalg_t alg ; 
  union {
    __gmp_randata_lc * lc ; 
  }
  algdata ; 
}
__gmp_randstate_struct ; 
typedef __gmp_randstate_struct gmp_randstate_t [1 ] ; 
mp_limb_t scheme_gmpn_add (mp_ptr , mp_srcptr , mp_size_t , mp_srcptr , mp_size_t ) ; 
mp_limb_t scheme_gmpn_add_1 (mp_ptr , mp_srcptr , mp_size_t , mp_limb_t ) ; 
mp_limb_t scheme_gmpn_add_n (mp_ptr , mp_srcptr , mp_srcptr , mp_size_t ) ; 
__xform_nongcing__ int scheme_gmpn_cmp (mp_srcptr , mp_srcptr , mp_size_t ) ; 
mp_size_t scheme_gmpn_gcd (mp_ptr , mp_ptr , mp_size_t , mp_ptr , mp_size_t ) ; 
size_t scheme_gmpn_get_str (unsigned char * , int , mp_ptr , mp_size_t ) ; 
mp_limb_t scheme_gmpn_lshift (mp_ptr , mp_srcptr , mp_size_t , unsigned int ) ; 
mp_limb_t scheme_gmpn_mul (mp_ptr , mp_srcptr , mp_size_t , mp_srcptr , mp_size_t ) ; 
mp_limb_t scheme_gmpn_rshift (mp_ptr , mp_srcptr , mp_size_t , unsigned int ) ; 
mp_size_t scheme_gmpn_set_str (mp_ptr , const unsigned char * , size_t , int ) ; 
mp_size_t scheme_gmpn_sqrtrem (mp_ptr , mp_ptr , mp_srcptr , mp_size_t ) ; 
mp_limb_t scheme_gmpn_sub (mp_ptr , mp_srcptr , mp_size_t , mp_srcptr , mp_size_t ) ; 
mp_limb_t scheme_gmpn_sub_1 (mp_ptr , mp_srcptr , mp_size_t , mp_limb_t ) ; 
mp_limb_t scheme_gmpn_sub_n (mp_ptr , mp_srcptr , mp_srcptr , mp_size_t ) ; 
void scheme_gmpn_tdiv_qr (mp_ptr , mp_ptr , mp_size_t , mp_srcptr , mp_size_t , mp_srcptr , mp_size_t ) ; 
extern __inline__ mp_limb_t scheme_gmpn_add_1 (register mp_ptr res_ptr , register mp_srcptr s1_ptr , register mp_size_t s1_size , register mp_limb_t s2_limb ) {
  register mp_limb_t x ; 
  x = * s1_ptr ++ ; 
  s2_limb = x + s2_limb ; 
  * res_ptr ++ = s2_limb ; 
  if (s2_limb < x ) {
    while (-- s1_size != 0 ) {
      x = * s1_ptr ++ + 1 ; 
      * res_ptr ++ = x ; 
      if (x != 0 )
        goto fin ; 
    }
    return 1 ; 
  }
  fin : if (res_ptr != s1_ptr ) {
    mp_size_t i ; 
    for (i = 0 ; i < s1_size - 1 ; i ++ ) {
      res_ptr [i ] = s1_ptr [i ] ; 
    }
  }
  return 0 ; 
}
extern __inline__ mp_limb_t scheme_gmpn_add (register mp_ptr res_ptr , register mp_srcptr s1_ptr , register mp_size_t s1_size , register mp_srcptr s2_ptr , register mp_size_t s2_size ) {
  mp_limb_t cy_limb = 0 ; 
  if (s2_size != 0 )
    cy_limb = scheme_gmpn_add_n (res_ptr , s1_ptr , s2_ptr , s2_size ) ; 
  if (s1_size - s2_size != 0 )
    cy_limb = scheme_gmpn_add_1 (res_ptr + s2_size , s1_ptr + s2_size , s1_size - s2_size , cy_limb ) ; 
  return cy_limb ; 
}
extern __inline__ mp_limb_t scheme_gmpn_sub_1 (register mp_ptr res_ptr , register mp_srcptr s1_ptr , register mp_size_t s1_size , register mp_limb_t s2_limb ) {
  register mp_limb_t x ; 
  x = * s1_ptr ++ ; 
  s2_limb = x - s2_limb ; 
  * res_ptr ++ = s2_limb ; 
  if (s2_limb > x ) {
    while (-- s1_size != 0 ) {
      x = * s1_ptr ++ ; 
      * res_ptr ++ = x - 1 ; 
      if (x != 0 )
        goto fin ; 
    }
    return 1 ; 
  }
  fin : if (res_ptr != s1_ptr ) {
    mp_size_t i ; 
    for (i = 0 ; i < s1_size - 1 ; i ++ ) {
      res_ptr [i ] = s1_ptr [i ] ; 
    }
  }
  return 0 ; 
}
extern __inline__ mp_limb_t scheme_gmpn_sub (register mp_ptr res_ptr , register mp_srcptr s1_ptr , register mp_size_t s1_size , register mp_srcptr s2_ptr , register mp_size_t s2_size ) {
  mp_limb_t cy_limb = 0 ; 
  if (s2_size != 0 )
    cy_limb = scheme_gmpn_sub_n (res_ptr , s1_ptr , s2_ptr , s2_size ) ; 
  if (s1_size - s2_size != 0 )
    cy_limb = scheme_gmpn_sub_1 (res_ptr + s2_size , s1_ptr + s2_size , s1_size - s2_size , cy_limb ) ; 
  return cy_limb ; 
}
enum {
  GMP_ERROR_NONE = 0 , GMP_ERROR_UNSUPPORTED_ARGUMENT = 1 , GMP_ERROR_DIVISION_BY_ZERO = 2 , GMP_ERROR_SQRT_OF_NEGATIVE = 4 , GMP_ERROR_INVALID_ARGUMENT = 8 , GMP_ERROR_ALLOCATE = 16 , GMP_ERROR_BAD_STRING = 32 , GMP_ERROR_UNUSED_ERROR }
; 
void scheme_bignum_use_fuel (long n ) ; 
static Scheme_Object * bignum_one ; 
static void * bignum_cache [16 ] ; 
static int cache_count ; 
static void * copy_to_protected (void * p , long len , int zero ) {
  void * r ; 
  long minsz ; 
  DECL_RET_SAVE (void * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(r, 0), PUSH(p, 1)));
# define XfOrM1_COUNT (2)
# define SETUP_XfOrM1(x) SETUP(XfOrM1_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  r = NULLED_OUT ; 
  minsz = FUNCCALL(SETUP_XfOrM1(_), GC_malloc_stays_put_threshold () ); 
  if (minsz >= len + sizeof (long ) ) {
#   define XfOrM3_COUNT (0+XfOrM1_COUNT)
#   define SETUP_XfOrM3(x) SETUP_XfOrM1(x)
    if (cache_count ) {
      -- cache_count ; 
      r = bignum_cache [cache_count ] ; 
      bignum_cache [cache_count ] = ((void * ) 0 ) ; 
    }
    else r = (char * ) FUNCCALL(SETUP_XfOrM3(_), GC_malloc_atomic (minsz ) ); 
    ((long * ) r ) [0 ] = 1 ; 
  }
  else {
#   define XfOrM2_COUNT (0+XfOrM1_COUNT)
#   define SETUP_XfOrM2(x) SETUP_XfOrM1(x)
    r = (char * ) FUNCCALL(SETUP_XfOrM2(_), GC_malloc_atomic (len + sizeof (long ) ) ); 
    ((long * ) r ) [0 ] = 0 ; 
  }
  r = (char * ) r XFORM_OK_PLUS sizeof (long ) ; 
  if (p )
    (memcpy (r , p , len ) ) ; 
  if (zero )
    (memset (r , 0 , len ) ) ; 
  RET_VALUE_START (r ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void free_protected (void * p ) {
  /* No conversion */
  if (((long * ) p ) [- 1 ] ) {
    if (cache_count < 16 ) {
      bignum_cache [cache_count ++ ] = (char * ) p - sizeof (long ) ; 
    }
  }
}
void scheme_clear_bignum_cache (void ) {
  /* No conversion */
  int i ; 
  for (i = 0 ; i < 16 ; i ++ ) {
    bignum_cache [i ] = ((void * ) 0 ) ; 
  }
  cache_count = 0 ; 
}
Scheme_Object * scheme_make_small_bignum (long v , Small_Bignum * o ) {
  bigdig bv ; 
  o -> o . iso . so . type = scheme_bignum_type ; 
  (& ((Scheme_Bignum * ) & o -> o ) -> iso ) -> so . keyex = ((((v >= 0 ) ? 1 : 0 ) ) | ((& ((Scheme_Bignum * ) & o -> o ) -> iso ) -> so . keyex & 0x2 ) ) ; 
  if (v < 0 )
    bv = - v ; 
  else bv = v ; 
  if (bv == 0 )
    (((Scheme_Bignum * ) & o -> o ) -> len ) = 0 ; 
  else (((Scheme_Bignum * ) & o -> o ) -> len ) = 1 ; 
  (((Scheme_Bignum * ) & o -> o ) -> digits ) = o -> v ; 
  o -> v [0 ] = bv ; 
  return (Scheme_Object * ) (void * ) o ; 
}
Scheme_Object * scheme_make_bignum (long v ) {
  Small_Bignum * r ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(r, 0)));
# define XfOrM11_COUNT (1)
# define SETUP_XfOrM11(x) SETUP(XfOrM11_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  r = NULLED_OUT ; 
  r = ((Small_Bignum * ) FUNCCALL(SETUP_XfOrM11(_), GC_malloc_one_small_tagged ((((sizeof (Small_Bignum ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  (& ((Scheme_Bignum * ) & r -> o ) -> iso ) -> so . keyex |= (0x2 | ((& ((Scheme_Bignum * ) & r -> o ) -> iso ) -> so . keyex & 0x1 ) ) ; 
  RET_VALUE_START (scheme_make_small_bignum (v , r ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_bignum_from_unsigned (unsigned long v ) {
  Small_Bignum * r ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(r, 0)));
# define XfOrM12_COUNT (1)
# define SETUP_XfOrM12(x) SETUP(XfOrM12_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  r = NULLED_OUT ; 
  r = ((Small_Bignum * ) FUNCCALL(SETUP_XfOrM12(_), GC_malloc_one_small_tagged ((((sizeof (Small_Bignum ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  (& ((Scheme_Bignum * ) & r -> o ) -> iso ) -> so . keyex |= (0x2 | ((& ((Scheme_Bignum * ) & r -> o ) -> iso ) -> so . keyex & 0x1 ) ) ; 
  r -> o . iso . so . type = scheme_bignum_type ; 
  (& ((Scheme_Bignum * ) & r -> o ) -> iso ) -> so . keyex = ((1 ) | ((& ((Scheme_Bignum * ) & r -> o ) -> iso ) -> so . keyex & 0x2 ) ) ; 
  if (v == 0 )
    (((Scheme_Bignum * ) & r -> o ) -> len ) = 0 ; 
  else (((Scheme_Bignum * ) & r -> o ) -> len ) = 1 ; 
  (((Scheme_Bignum * ) & r -> o ) -> digits ) = r -> v ; 
  r -> v [0 ] = v ; 
  RET_VALUE_START ((Scheme_Object * ) (void * ) r ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_bignum_from_long_long (mzlonglong v ) {
  /* No conversion */
  return scheme_make_bignum (v ) ; 
}
Scheme_Object * scheme_make_bignum_from_unsigned_long_long (umzlonglong v ) {
  /* No conversion */
  return scheme_make_bignum_from_unsigned (v ) ; 
}
int scheme_bignum_get_int_val (const Scheme_Object * o , long * v ) {
  /* No conversion */
  if ((((Scheme_Bignum * ) o ) -> len ) > 1 ) {
    return 0 ; 
  }
  else if ((((Scheme_Bignum * ) o ) -> len ) == 0 ) {
    * v = 0 ; 
    return 1 ; 
  }
  else if ((((Scheme_Bignum * ) o ) -> digits ) [0 ] == 0x8000000000000000 && ! ((& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex & 0x1 ) ) {
    * v = (((Scheme_Bignum * ) o ) -> digits ) [0 ] ; 
    return 1 ; 
  }
  else if (((((Scheme_Bignum * ) o ) -> digits ) [0 ] & 0x8000000000000000 ) != 0 ) {
    return 0 ; 
  }
  else if (((& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex & 0x1 ) ) {
    * v = (long ) (((Scheme_Bignum * ) o ) -> digits ) [0 ] ; 
    return 1 ; 
  }
  else {
    * v = - ((long ) (((Scheme_Bignum * ) o ) -> digits ) [0 ] ) ; 
    return 1 ; 
  }
}
int scheme_bignum_get_unsigned_int_val (const Scheme_Object * o , unsigned long * v ) {
  /* No conversion */
  if (((((Scheme_Bignum * ) o ) -> len ) > 1 ) || ! ((& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex & 0x1 ) )
    return 0 ; 
  else if ((((Scheme_Bignum * ) o ) -> len ) == 0 ) {
    * v = 0 ; 
    return 1 ; 
  }
  else {
    * v = (((Scheme_Bignum * ) o ) -> digits ) [0 ] ; 
    return 1 ; 
  }
}
int scheme_bignum_get_long_long_val (const Scheme_Object * o , mzlonglong * v ) {
  /* No conversion */
  if ((((Scheme_Bignum * ) o ) -> len ) > 1 ) {
    return 0 ; 
  }
  else if ((((Scheme_Bignum * ) o ) -> len ) == 0 ) {
    * v = 0 ; 
    return 1 ; 
  }
  else if ((((Scheme_Bignum * ) o ) -> digits ) [1 - 1 ] == 0x8000000000000000 && ! (((Scheme_Bignum * ) o ) -> digits ) [0 ] && ! ((& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex & 0x1 ) ) {
    mzlonglong v2 ; 
    v2 = 1 ; 
    v2 = (v2 << 63 ) ; 
    * v = v2 ; 
    return 1 ; 
  }
  else if (((((Scheme_Bignum * ) o ) -> digits ) [1 - 1 ] & 0x8000000000000000 ) != 0 ) {
    return 0 ; 
  }
  else {
    mzlonglong v2 ; 
    v2 = (((Scheme_Bignum * ) o ) -> digits ) [0 ] ; 
    if ((((Scheme_Bignum * ) o ) -> len ) > 1 ) {
      v2 |= ((mzlonglong ) ((((Scheme_Bignum * ) o ) -> digits ) [1 ] ) ) << 32 ; 
    }
    if (! ((& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex & 0x1 ) ) {
      v2 = - v2 ; 
    }
    * v = v2 ; 
    return 1 ; 
  }
}
int scheme_bignum_get_unsigned_long_long_val (const Scheme_Object * o , umzlonglong * v ) {
  /* No conversion */
  if (((((Scheme_Bignum * ) o ) -> len ) > 1 ) || ! ((& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex & 0x1 ) )
    return 0 ; 
  else if ((((Scheme_Bignum * ) o ) -> len ) == 0 ) {
    * v = 0 ; 
    return 1 ; 
  }
  else {
    umzlonglong v2 ; 
    v2 = (((Scheme_Bignum * ) o ) -> digits ) [0 ] ; 
    if ((((Scheme_Bignum * ) o ) -> len ) ) {
      v2 |= ((umzlonglong ) (((Scheme_Bignum * ) o ) -> digits ) [1 ] ) << 32 ; 
    }
    * v = v2 ; 
    return 1 ; 
  }
}
Scheme_Object * scheme_bignum_normalize (const Scheme_Object * o ) {
  /* No conversion */
  long v ; 
  if (! ((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
    return (Scheme_Object * ) (void * ) o ; 
  if (scheme_bignum_get_int_val (o , & v ) ) {
    long t ; 
    t = v & 0xC000000000000000 ; 
    if (t == 0 || t == 0xC000000000000000 )
      return ((Scheme_Object * ) (void * ) (long ) ((((long ) (v ) ) << 1 ) | 0x1 ) ) ; 
    else return (Scheme_Object * ) (void * ) o ; 
  }
  else return (Scheme_Object * ) (void * ) o ; 
}
static Scheme_Object * make_single_bigdig_result (int pos , bigdig d ) {
  Small_Bignum * sm , quick ; 
  Scheme_Object * o ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(quick.o.digits, 1), PUSH(sm, 2)));
# define XfOrM39_COUNT (3)
# define SETUP_XfOrM39(x) SETUP(XfOrM39_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sm = NULLED_OUT ; 
  quick.o.digits = NULLED_OUT ; 
  o = NULLED_OUT ; 
  sm = & quick ; 
  sm -> o . iso . so . type = scheme_bignum_type ; 
  (& ((Scheme_Bignum * ) sm ) -> iso ) -> so . keyex = ((pos ) | ((& ((Scheme_Bignum * ) sm ) -> iso ) -> so . keyex & 0x2 ) ) ; 
  (((Scheme_Bignum * ) sm ) -> len ) = 1 ; 
  (((Scheme_Bignum * ) sm ) -> digits ) = sm -> v ; 
  sm -> v [0 ] = d ; 
  o = (scheme_bignum_normalize ((Scheme_Object * ) (void * ) sm ) ) ; 
  if (((o ) == ((Scheme_Object * ) (void * ) sm ) ) ) {
#   define XfOrM40_COUNT (0+XfOrM39_COUNT)
#   define SETUP_XfOrM40(x) SETUP_XfOrM39(x)
    sm = ((Small_Bignum * ) FUNCCALL(SETUP_XfOrM40(_), GC_malloc_one_small_tagged ((((sizeof (Small_Bignum ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    sm -> o . iso . so . type = scheme_bignum_type ; 
    (& ((Scheme_Bignum * ) sm ) -> iso ) -> so . keyex |= (0x2 | ((& ((Scheme_Bignum * ) sm ) -> iso ) -> so . keyex & 0x1 ) ) ; 
    (& ((Scheme_Bignum * ) sm ) -> iso ) -> so . keyex = ((pos ) | ((& ((Scheme_Bignum * ) sm ) -> iso ) -> so . keyex & 0x2 ) ) ; 
    (((Scheme_Bignum * ) sm ) -> len ) = 1 ; 
    (((Scheme_Bignum * ) sm ) -> digits ) = sm -> v ; 
    sm -> v [0 ] = d ; 
    RET_VALUE_START ((Scheme_Object * ) (void * ) sm ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * bignum_copy (const Scheme_Object * a , long msd ) {
  Scheme_Object * o ; 
  int c ; 
  bigdig * o_digs ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(a, 1), PUSH(o_digs, 2)));
# define XfOrM41_COUNT (3)
# define SETUP_XfOrM41(x) SETUP(XfOrM41_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  o = NULLED_OUT ; 
  o_digs = NULLED_OUT ; 
  c = (((Scheme_Bignum * ) a ) -> len ) ; 
  o = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM41(_), GC_malloc_one_tagged (sizeof (Scheme_Bignum ) ) ); 
  o -> type = scheme_bignum_type ; 
  (((Scheme_Bignum * ) o ) -> len ) = c ; 
  (& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex = ((((& ((Scheme_Bignum * ) a ) -> iso ) -> so . keyex & 0x1 ) ) | ((& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex & 0x2 ) ) ; 
  o_digs = (bigdig * ) FUNCCALL(SETUP_XfOrM41(_), GC_malloc_atomic (sizeof (bigdig ) * (c + (msd ? 1 : 0 ) ) ) ); 
  (((Scheme_Bignum * ) o ) -> digits ) = o_digs ; 
  (memcpy (o_digs , (((Scheme_Bignum * ) a ) -> digits ) , sizeof (bigdig ) * c ) ) ; 
  if (msd ) {
    o_digs [c ] = msd ; 
    (((Scheme_Bignum * ) o ) -> len ) = (((Scheme_Bignum * ) o ) -> len ) + 1 ; 
  }
  RET_VALUE_START (o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_bignum_eq (const Scheme_Object * a , const Scheme_Object * b ) {
  /* No conversion */
  long a_len , b_len ; 
  a_len = (((Scheme_Bignum * ) a ) -> len ) ; 
  b_len = (((Scheme_Bignum * ) b ) -> len ) ; 
  if (a_len == 0 && b_len == 0 )
    return 1 ; 
  if (a_len == b_len && ((& ((Scheme_Bignum * ) a ) -> iso ) -> so . keyex & 0x1 ) == ((& ((Scheme_Bignum * ) b ) -> iso ) -> so . keyex & 0x1 ) )
    return scheme_gmpn_cmp ((((Scheme_Bignum * ) a ) -> digits ) , (((Scheme_Bignum * ) b ) -> digits ) , b_len ) == 0 ; 
  else return 0 ; 
}
__xform_nongcing__ static int bignum_abs_cmp (const Scheme_Object * a , const Scheme_Object * b ) {
  /* No conversion */
  long a_len , b_len ; 
  a_len = (((Scheme_Bignum * ) a ) -> len ) ; 
  b_len = (((Scheme_Bignum * ) b ) -> len ) ; 
  if (a_len > b_len )
    return 1 ; 
  else if (a_len < b_len )
    return - 1 ; 
  else if (a_len == 0 )
    return 0 ; 
  else return scheme_gmpn_cmp ((((Scheme_Bignum * ) a ) -> digits ) , (((Scheme_Bignum * ) b ) -> digits ) , b_len ) ; 
}
int scheme_bignum_lt (const Scheme_Object * a , const Scheme_Object * b ) {
  /* No conversion */
  long a_pos , b_pos ; 
  int res ; 
  a_pos = ((& ((Scheme_Bignum * ) a ) -> iso ) -> so . keyex & 0x1 ) ; 
  b_pos = ((& ((Scheme_Bignum * ) b ) -> iso ) -> so . keyex & 0x1 ) ; 
  if (! a_pos && b_pos )
    return 1 ; 
  else if (a_pos && ! b_pos )
    return 0 ; 
  else res = bignum_abs_cmp (a , b ) ; 
  if (! a_pos )
    return (res > 0 ) ; 
  else return (res < 0 ) ; 
}
int scheme_bignum_gt (const Scheme_Object * a , const Scheme_Object * b ) {
  /* No conversion */
  return scheme_bignum_lt (b , a ) ; 
}
int scheme_bignum_le (const Scheme_Object * a , const Scheme_Object * b ) {
  /* No conversion */
  return ! scheme_bignum_gt (a , b ) ; 
}
int scheme_bignum_ge (const Scheme_Object * a , const Scheme_Object * b ) {
  /* No conversion */
  return ! scheme_bignum_lt (a , b ) ; 
}
Scheme_Object * scheme_bignum_negate (const Scheme_Object * n ) {
  Scheme_Object * o ; 
  int len ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(n, 0), PUSH(o, 1)));
# define XfOrM49_COUNT (2)
# define SETUP_XfOrM49(x) SETUP(XfOrM49_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  o = NULLED_OUT ; 
  len = (((Scheme_Bignum * ) n ) -> len ) ; 
  if ((((Scheme_Bignum * ) n ) -> digits ) == ((Small_Bignum * ) (void * ) n ) -> v ) {
#   define XfOrM51_COUNT (0+XfOrM49_COUNT)
#   define SETUP_XfOrM51(x) SETUP_XfOrM49(x)
    o = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM51(_), GC_malloc_one_tagged (sizeof (Small_Bignum ) ) ); 
    (& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex |= (0x2 | ((& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex & 0x1 ) ) ; 
    ((Small_Bignum * ) o ) -> v [0 ] = (((Scheme_Bignum * ) n ) -> digits ) [0 ] ; 
    (((Scheme_Bignum * ) o ) -> digits ) = ((Small_Bignum * ) (void * ) o ) -> v ; 
  }
  else {
#   define XfOrM50_COUNT (0+XfOrM49_COUNT)
#   define SETUP_XfOrM50(x) SETUP_XfOrM49(x)
    o = (Scheme_Object * ) ((Scheme_Bignum * ) FUNCCALL(SETUP_XfOrM50(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Bignum ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    (((Scheme_Bignum * ) o ) -> digits ) = (((Scheme_Bignum * ) n ) -> digits ) ; 
  }
  o -> type = scheme_bignum_type ; 
  (& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex = ((! ((& ((Scheme_Bignum * ) n ) -> iso ) -> so . keyex & 0x1 ) ) | ((& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex & 0x2 ) ) ; 
  (((Scheme_Bignum * ) o ) -> len ) = len ; 
  RET_VALUE_START (o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static bigdig * allocate_bigdig_array (int length ) {
  int i ; 
  bigdig * res ; 
  DECL_RET_SAVE (bigdig * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(res, 0)));
# define XfOrM52_COUNT (1)
# define SETUP_XfOrM52(x) SETUP(XfOrM52_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  res = NULLED_OUT ; 
  if (length > 4096 ) {
#   define XfOrM56_COUNT (0+XfOrM52_COUNT)
#   define SETUP_XfOrM56(x) SETUP_XfOrM52(x)
    res = (bigdig * ) FUNCCALL(SETUP_XfOrM56(_), scheme_malloc_fail_ok (GC_malloc_atomic , length * sizeof (bigdig ) ) ); 
  }
  else {
#   define XfOrM55_COUNT (0+XfOrM52_COUNT)
#   define SETUP_XfOrM55(x) SETUP_XfOrM52(x)
    res = (bigdig * ) FUNCCALL(SETUP_XfOrM55(_), GC_malloc_atomic (length * sizeof (bigdig ) ) ); 
  }
  for (i = 0 ; i < length ; ++ i ) {
    res [i ] = 0 ; 
  }
  RET_VALUE_START (res ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
__xform_nongcing__ static int bigdig_length (bigdig * array , int alloced ) {
  /* No conversion */
  alloced -- ; 
  while (alloced >= 0 && array [alloced ] == 0 ) {
    alloced -- ; 
  }
  return alloced + 1 ; 
}
static Scheme_Object * bignum_add_sub (const Scheme_Object * a , const Scheme_Object * b , int sub ) {
  Scheme_Object * o ; 
  long a_size , b_size , max_size ; 
  short a_pos , b_pos ; 
  bigdig * o_digs , * a_digs , * b_digs ; 
  bigdig asd [1 ] ; 
  bigdig bsd [1 ] ; 
  Scheme_Object * __funcarg9 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(a_digs, 0), PUSH(b_digs, 1), PUSH(o, 2), PUSH(o_digs, 3), PUSH(b, 4)));
# define XfOrM60_COUNT (5)
# define SETUP_XfOrM60(x) SETUP(XfOrM60_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  o = NULLED_OUT ; 
  o_digs = NULLED_OUT ; 
  a_digs = NULLED_OUT ; 
  b_digs = NULLED_OUT ; 
  a_size = (((Scheme_Bignum * ) a ) -> len ) ; 
  b_size = (((Scheme_Bignum * ) b ) -> len ) ; 
  a_pos = ((& ((Scheme_Bignum * ) a ) -> iso ) -> so . keyex & 0x1 ) ; 
  b_pos = (! (((& ((Scheme_Bignum * ) b ) -> iso ) -> so . keyex & 0x1 ) ) ^ ! (sub ) ) ; 
  a_digs = (((((Scheme_Bignum * ) a ) -> digits ) == ((Small_Bignum * ) (void * ) a ) -> v ) ? (asd [0 ] = (((Scheme_Bignum * ) a ) -> digits ) [0 ] , asd ) : (((Scheme_Bignum * ) a ) -> digits ) ) ; 
  b_digs = (((((Scheme_Bignum * ) b ) -> digits ) == ((Small_Bignum * ) (void * ) b ) -> v ) ? (bsd [0 ] = (((Scheme_Bignum * ) b ) -> digits ) [0 ] , bsd ) : (((Scheme_Bignum * ) b ) -> digits ) ) ; 
  if (b_size == 0 )
    RET_VALUE_START ((__funcarg9 = FUNCCALL(SETUP_XfOrM60(_), bignum_copy (a , 0 ) ), (scheme_bignum_normalize (__funcarg9 ) ) ) ) RET_VALUE_END ; 
  else if (a_size == 0 ) {
#   define XfOrM64_COUNT (0+XfOrM60_COUNT)
#   define SETUP_XfOrM64(x) SETUP_XfOrM60(x)
    o = FUNCCALL(SETUP_XfOrM64(_), bignum_copy (b , 0 ) ); 
    (& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex = ((b_pos ) | ((& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex & 0x2 ) ) ; 
    RET_VALUE_START ((scheme_bignum_normalize (o ) ) ) RET_VALUE_END ; 
  }
  o = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM60(_), GC_malloc_one_tagged (sizeof (Scheme_Bignum ) ) ); 
  o -> type = scheme_bignum_type ; 
  o_digs = ((void * ) 0 ) ; 
  max_size = (a_size > b_size ) ? a_size : b_size ; 
  if (a_pos == b_pos ) {
    int carry ; 
#   define XfOrM63_COUNT (0+XfOrM60_COUNT)
#   define SETUP_XfOrM63(x) SETUP_XfOrM60(x)
    o_digs = FUNCCALL(SETUP_XfOrM63(_), allocate_bigdig_array (max_size ) ); 
    if (a_size > b_size )
      carry = FUNCCALL(SETUP_XfOrM63(_), scheme_gmpn_add (o_digs , a_digs , a_size , b_digs , b_size ) ); 
    else carry = FUNCCALL(SETUP_XfOrM63(_), scheme_gmpn_add (o_digs , b_digs , b_size , a_digs , a_size ) ); 
    (& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex = ((a_pos ) | ((& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex & 0x2 ) ) ; 
    (((Scheme_Bignum * ) o ) -> len ) = max_size ; 
    (((Scheme_Bignum * ) o ) -> digits ) = o_digs ; 
    if (carry )
      o = FUNCCALL(SETUP_XfOrM63(_), bignum_copy (o , 1 ) ); 
  }
  else {
    int sw ; 
#   define XfOrM61_COUNT (0+XfOrM60_COUNT)
#   define SETUP_XfOrM61(x) SETUP_XfOrM60(x)
    if (a_size > b_size )
      sw = 0 ; 
    else if (b_size > a_size )
      sw = 1 ; 
    else {
      int cmp ; 
#     define XfOrM62_COUNT (0+XfOrM61_COUNT)
#     define SETUP_XfOrM62(x) SETUP_XfOrM61(x)
      cmp = (scheme_gmpn_cmp (a_digs , b_digs , a_size ) ) ; 
      if (cmp == 0 )
        RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
      else if (cmp > 0 )
        sw = 0 ; 
      else sw = 1 ; 
    }
    o_digs = FUNCCALL(SETUP_XfOrM61(_), allocate_bigdig_array (max_size ) ); 
    if (sw )
      FUNCCALL(SETUP_XfOrM61(_), scheme_gmpn_sub (o_digs , b_digs , b_size , a_digs , a_size ) ); 
    else FUNCCALL(SETUP_XfOrM61(_), scheme_gmpn_sub (o_digs , a_digs , a_size , b_digs , b_size ) ); 
    (& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex = (((! (sw ) ^ ! (a_pos ) ) ) | ((& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex & 0x2 ) ) ; 
    max_size = (bigdig_length (o_digs , max_size ) ) ; 
    (((Scheme_Bignum * ) o ) -> len ) = max_size ; 
    (((Scheme_Bignum * ) o ) -> digits ) = o_digs ; 
  }
  RET_VALUE_START ((scheme_bignum_normalize (o ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_bignum_add (const Scheme_Object * a , const Scheme_Object * b ) {
  /* No conversion */
  return bignum_add_sub (a , b , 0 ) ; 
}
Scheme_Object * scheme_bignum_subtract (const Scheme_Object * a , const Scheme_Object * b ) {
  /* No conversion */
  return bignum_add_sub (a , b , 1 ) ; 
}
Scheme_Object * scheme_bignum_add1 (const Scheme_Object * n ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(n, 0)));
# define XfOrM67_COUNT (1)
# define SETUP_XfOrM67(x) SETUP(XfOrM67_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! bignum_one ) {
#   define XfOrM68_COUNT (0+XfOrM67_COUNT)
#   define SETUP_XfOrM68(x) SETUP_XfOrM67(x)
    FUNCCALL(SETUP_XfOrM68(_), scheme_register_static ((void * ) & bignum_one , sizeof (bignum_one ) ) ); 
    bignum_one = FUNCCALL(SETUP_XfOrM68(_), scheme_make_bignum (1 ) ); 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(bignum_add_sub (n , bignum_one , 0 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_bignum_sub1 (const Scheme_Object * n ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(n, 0)));
# define XfOrM69_COUNT (1)
# define SETUP_XfOrM69(x) SETUP(XfOrM69_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! bignum_one ) {
#   define XfOrM70_COUNT (0+XfOrM69_COUNT)
#   define SETUP_XfOrM70(x) SETUP_XfOrM69(x)
    FUNCCALL(SETUP_XfOrM70(_), scheme_register_static ((void * ) & bignum_one , sizeof (bignum_one ) ) ); 
    bignum_one = FUNCCALL(SETUP_XfOrM70(_), scheme_make_bignum (1 ) ); 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(bignum_add_sub (n , bignum_one , 1 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * bignum_multiply (const Scheme_Object * a , const Scheme_Object * b , int norm ) {
  Scheme_Object * o ; 
  long a_size , a_pos , b_size , b_pos , res_size , i , j ; 
  bigdig * o_digs , * a_digs , * b_digs ; 
  bigdig asd [1 ] ; 
  bigdig bsd [1 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(b_digs, 0), PUSH(a_digs, 1), PUSH(a, 2), PUSH(o, 3), PUSH(o_digs, 4), PUSH(b, 5)));
# define XfOrM71_COUNT (6)
# define SETUP_XfOrM71(x) SETUP(XfOrM71_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  o = NULLED_OUT ; 
  o_digs = NULLED_OUT ; 
  a_digs = NULLED_OUT ; 
  b_digs = NULLED_OUT ; 
  a_size = (((Scheme_Bignum * ) a ) -> len ) ; 
  b_size = (((Scheme_Bignum * ) b ) -> len ) ; 
  {
#   define XfOrM80_COUNT (0+XfOrM71_COUNT)
#   define SETUP_XfOrM80(x) SETUP_XfOrM71(x)
    if ((scheme_fuel_counter ) <= 0 ) {
#     define XfOrM81_COUNT (0+XfOrM80_COUNT)
#     define SETUP_XfOrM81(x) SETUP_XfOrM80(x)
      FUNCCALL(SETUP_XfOrM81(_), scheme_out_of_fuel () ); 
    }
  }
  ; 
  {
#   define XfOrM78_COUNT (0+XfOrM71_COUNT)
#   define SETUP_XfOrM78(x) SETUP_XfOrM71(x)
    if ((scheme_fuel_counter ) <= 0 ) {
#     define XfOrM79_COUNT (0+XfOrM78_COUNT)
#     define SETUP_XfOrM79(x) SETUP_XfOrM78(x)
      FUNCCALL(SETUP_XfOrM79(_), scheme_out_of_fuel () ); 
    }
  }
  ; 
  if (a_size == 0 || b_size == 0 ) {
#   define XfOrM77_COUNT (0+XfOrM71_COUNT)
#   define SETUP_XfOrM77(x) SETUP_XfOrM71(x)
    if (norm )
      RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
    else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_bignum (0 ) )) RET_VALUE_EMPTY_END ; 
  }
  a_pos = ((& ((Scheme_Bignum * ) a ) -> iso ) -> so . keyex & 0x1 ) ; 
  b_pos = ((& ((Scheme_Bignum * ) b ) -> iso ) -> so . keyex & 0x1 ) ; 
  a_digs = (((((Scheme_Bignum * ) a ) -> digits ) == ((Small_Bignum * ) (void * ) a ) -> v ) ? (asd [0 ] = (((Scheme_Bignum * ) a ) -> digits ) [0 ] , asd ) : (((Scheme_Bignum * ) a ) -> digits ) ) ; 
  b_digs = (((((Scheme_Bignum * ) b ) -> digits ) == ((Small_Bignum * ) (void * ) b ) -> v ) ? (bsd [0 ] = (((Scheme_Bignum * ) b ) -> digits ) [0 ] , bsd ) : (((Scheme_Bignum * ) b ) -> digits ) ) ; 
  res_size = a_size + b_size ; 
  o = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM71(_), GC_malloc_one_tagged (sizeof (Scheme_Bignum ) ) ); 
  o -> type = scheme_bignum_type ; 
  o_digs = FUNCCALL(SETUP_XfOrM71(_), copy_to_protected (((void * ) 0 ) , res_size * sizeof (bigdig ) , 1 ) ); 
  ; 
  a_digs = FUNCCALL_AGAIN(copy_to_protected (a_digs , a_size * sizeof (bigdig ) , 0 ) ); 
  ; 
  b_digs = FUNCCALL_AGAIN(copy_to_protected (b_digs , b_size * sizeof (bigdig ) , 0 ) ); 
  ; 
  for (i = 0 ; (a_digs [i ] == 0 ) && i < a_size ; i ++ ) {
    o_digs [i ] = 0 ; 
  }
  for (j = 0 ; (b_digs [j ] == 0 ) && j < b_size ; j ++ ) {
    o_digs [i + j ] = 0 ; 
  }
  if ((a_size - i ) > (b_size - j ) )
    FUNCCALL(SETUP_XfOrM71(_), scheme_gmpn_mul (o_digs XFORM_OK_PLUS i + j , a_digs XFORM_OK_PLUS i , a_size - i , b_digs XFORM_OK_PLUS j , b_size - j ) ); 
  else FUNCCALL(SETUP_XfOrM71(_), scheme_gmpn_mul (o_digs XFORM_OK_PLUS i + j , b_digs XFORM_OK_PLUS j , b_size - j , a_digs XFORM_OK_PLUS i , a_size - i ) ); 
  (FUNCCALL(SETUP_XfOrM71(_), free_protected (a_digs ) ), a_digs = ((void * ) 0 ) ) ; 
  ; 
  (FUNCCALL(SETUP_XfOrM71(_), free_protected (b_digs ) ), b_digs = ((void * ) 0 ) ) ; 
  ; 
  {
    bigdig * save = o_digs ; 
    BLOCK_SETUP((PUSH(save, 0+XfOrM71_COUNT)));
#   define XfOrM72_COUNT (1+XfOrM71_COUNT)
#   define SETUP_XfOrM72(x) SETUP(XfOrM72_COUNT)
    o_digs = (bigdig * ) FUNCCALL(SETUP_XfOrM72(_), GC_malloc_atomic (res_size * sizeof (bigdig ) ) ); 
    (memcpy (o_digs , save , res_size * sizeof (bigdig ) ) ) ; 
    (FUNCCALL(SETUP_XfOrM72(_), free_protected (save ) ), save = ((void * ) 0 ) ) ; 
    ; 
  }
  ; 
  res_size = (bigdig_length (o_digs , res_size ) ) ; 
  (((Scheme_Bignum * ) o ) -> len ) = res_size ; 
  (((Scheme_Bignum * ) o ) -> digits ) = o_digs ; 
  (& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex = ((! (! (a_pos ) ^ ! (b_pos ) ) ) | ((& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex & 0x2 ) ) ; 
  RET_VALUE_START ((norm ? (scheme_bignum_normalize (o ) ) : o ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_bignum_multiply (const Scheme_Object * a , const Scheme_Object * b ) {
  /* No conversion */
  return bignum_multiply (a , b , 1 ) ; 
}
static Scheme_Object * do_power (const Scheme_Object * a , unsigned long b ) {
  Scheme_Object * result ; 
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(a, 0), PUSH(result, 1)));
# define XfOrM83_COUNT (2)
# define SETUP_XfOrM83(x) SETUP(XfOrM83_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  result = NULLED_OUT ; 
  result = ((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) ; 
  i = sizeof (unsigned long ) * 8 - 1 ; 
  while (! ((b >> i ) & 0x1 ) && i >= 0 ) {
    i = i - 1 ; 
  }
  while (i >= 0 ) {
#   define XfOrM85_COUNT (0+XfOrM83_COUNT)
#   define SETUP_XfOrM85(x) SETUP_XfOrM83(x)
    result = FUNCCALL(SETUP_XfOrM85(_), scheme_bin_mult (result , result ) ); 
    if ((b >> i ) & 0x1 )
      result = FUNCCALL(SETUP_XfOrM85(_), scheme_bin_mult (a , result ) ); 
    i = i - 1 ; 
  }
  RET_VALUE_START (result ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * do_big_power (const Scheme_Object * a , const Scheme_Object * b ) {
  Scheme_Object * result , * v [2 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSHARRAY(v, 2, 0), PUSH(a, 3), PUSH(result, 4), PUSH(b, 5)));
# define XfOrM88_COUNT (6)
# define SETUP_XfOrM88(x) SETUP(XfOrM88_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  result = NULLED_OUT ; 
  v[0] = NULLED_OUT ; 
  v[1] = NULLED_OUT ; 
  result = ((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) ; 
  v [1 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (- 1 ) ) << 1 ) | 0x1 ) ) ; 
  while (! (scheme_is_zero (b ) ) ) {
#   define XfOrM90_COUNT (0+XfOrM88_COUNT)
#   define SETUP_XfOrM90(x) SETUP_XfOrM88(x)
    if ((! (((FUNCCALL(SETUP_XfOrM90(_), scheme_odd_p (1 , (Scheme_Object * * ) & b ) )) ) == (scheme_false ) ) ) )
      result = FUNCCALL(SETUP_XfOrM90(_), scheme_bin_mult (a , result ) ); 
    a = FUNCCALL(SETUP_XfOrM90(_), scheme_bin_mult (a , a ) ); 
    v [0 ] = (Scheme_Object * ) b ; 
    b = FUNCCALL(SETUP_XfOrM90(_), scheme_bitwise_shift (2 , v ) ); 
  }
  RET_VALUE_START (result ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_generic_integer_power (const Scheme_Object * a , const Scheme_Object * b ) {
  /* No conversion */
  unsigned long exponent ; 
  if (scheme_get_unsigned_int_val ((Scheme_Object * ) b , & exponent ) )
    return do_power (a , exponent ) ; 
  else return do_big_power (a , b ) ; 
}
Scheme_Object * scheme_bignum_max (const Scheme_Object * a , const Scheme_Object * b ) {
  /* No conversion */
  int lt ; 
  lt = scheme_bignum_lt (a , b ) ; 
  return scheme_bignum_normalize (lt ? b : a ) ; 
}
Scheme_Object * scheme_bignum_min (const Scheme_Object * a , const Scheme_Object * b ) {
  /* No conversion */
  int lt ; 
  lt = scheme_bignum_lt (a , b ) ; 
  return scheme_bignum_normalize (lt ? a : b ) ; 
}
static Scheme_Object * do_bitop (const Scheme_Object * a , const Scheme_Object * b , int op ) {
  long a_size , b_size , a_pos , b_pos , res_alloc , i ; 
  short res_pos ; 
  bigdig * a_digs , * b_digs , * res_digs , quick_digs [1 ] ; 
  int carry_out_a , carry_out_b , carry_out_res , carry_in_a , carry_in_b , carry_in_res ; 
  Scheme_Object * o ; 
  bigdig asd [1 ] ; 
  bigdig bsd [1 ] ; 
  Scheme_Object * __funcarg10 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(b_digs, 0), PUSH(res_digs, 1), PUSH(a_digs, 2), PUSH(a, 3), PUSH(o, 4), PUSH(b, 5)));
# define XfOrM94_COUNT (6)
# define SETUP_XfOrM94(x) SETUP(XfOrM94_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a_digs = NULLED_OUT ; 
  b_digs = NULLED_OUT ; 
  res_digs = NULLED_OUT ; 
  o = NULLED_OUT ; 
  a_size = (((Scheme_Bignum * ) a ) -> len ) ; 
  b_size = (((Scheme_Bignum * ) b ) -> len ) ; 
  if (a_size == 0 ) {
    RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
  }
  else if (b_size == 0 ) {
#   define XfOrM117_COUNT (0+XfOrM94_COUNT)
#   define SETUP_XfOrM117(x) SETUP_XfOrM94(x)
    if (op == 0 )
      RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
    else RET_VALUE_START ((__funcarg10 = FUNCCALL(SETUP_XfOrM117(_), bignum_copy (a , 0 ) ), (scheme_bignum_normalize (__funcarg10 ) ) ) ) RET_VALUE_END ; 
  }
  a_pos = ((& ((Scheme_Bignum * ) a ) -> iso ) -> so . keyex & 0x1 ) ; 
  a_digs = (((((Scheme_Bignum * ) a ) -> digits ) == ((Small_Bignum * ) (void * ) a ) -> v ) ? (asd [0 ] = (((Scheme_Bignum * ) a ) -> digits ) [0 ] , asd ) : (((Scheme_Bignum * ) a ) -> digits ) ) ; 
  b_pos = ((& ((Scheme_Bignum * ) b ) -> iso ) -> so . keyex & 0x1 ) ; 
  b_digs = (((((Scheme_Bignum * ) b ) -> digits ) == ((Small_Bignum * ) (void * ) b ) -> v ) ? (bsd [0 ] = (((Scheme_Bignum * ) b ) -> digits ) [0 ] , bsd ) : (((Scheme_Bignum * ) b ) -> digits ) ) ; 
  if (op == 0 ) {
    res_pos = a_pos || b_pos ; 
    res_alloc = (b_pos ? b_size : a_size ) ; 
  }
  else if (op == 1 ) {
    res_pos = a_pos && b_pos ; 
    res_alloc = (b_pos ? a_size : b_size ) ; 
  }
  else {
    res_pos = ! (! (a_pos ) ^ ! (b_pos ) ) ; 
    res_alloc = a_size ; 
  }
  if (res_alloc < 2 )
    res_digs = quick_digs ; 
  else res_digs = FUNCCALL(SETUP_XfOrM94(_), allocate_bigdig_array (res_alloc ) ); 
  carry_out_a = carry_out_b = carry_out_res = 1 ; 
  carry_in_a = carry_in_b = carry_in_res = 0 ; 
  for (i = 0 ; i < res_alloc ; ++ i ) {
    bigdig a_val , b_val , res_val ; 
    a_val = a_digs [i ] ; 
    if (! a_pos ) {
      carry_in_a = carry_out_a ; 
      carry_out_a = (carry_in_a == 1 && a_val == 0 ) ? 1 : 0 ; 
      a_val = ~ a_val + carry_in_a ; 
    }
    if (i < b_size ) {
      b_val = b_digs [i ] ; 
      if (! b_pos ) {
        carry_in_b = carry_out_b ; 
        carry_out_b = (carry_in_b == 1 && b_val == 0 ) ? 1 : 0 ; 
        b_val = ~ b_val + carry_in_b ; 
      }
    }
    else {
      if (b_pos )
        b_val = 0 ; 
      else b_val = 0xFFFFFFFFFFFFFFFF ; 
    }
    if (op == 0 )
      res_val = a_val & b_val ; 
    else if (op == 1 )
      res_val = a_val | b_val ; 
    else res_val = a_val ^ b_val ; 
    if (! res_pos ) {
      carry_in_res = carry_out_res ; 
      carry_out_res = (carry_in_res == 1 && res_val == 0 ) ? 1 : 0 ; 
      res_val = ~ res_val + carry_in_res ; 
    }
    res_digs [i ] = res_val ; 
  }
  if (! res_pos && carry_out_res == 1 ) {
#   define XfOrM99_COUNT (0+XfOrM94_COUNT)
#   define SETUP_XfOrM99(x) SETUP_XfOrM94(x)
    res_digs = FUNCCALL(SETUP_XfOrM99(_), allocate_bigdig_array (res_alloc + 1 ) ); 
    for (i = 0 ; i < res_alloc ; i ++ ) {
      res_digs [i ] = 0 ; 
    }
    res_digs [res_alloc ] = 1 ; 
    res_alloc = res_alloc + 1 ; 
  }
  else {
#   define XfOrM98_COUNT (0+XfOrM94_COUNT)
#   define SETUP_XfOrM98(x) SETUP_XfOrM94(x)
    res_alloc = (bigdig_length (res_digs , res_alloc ) ) ; 
  }
  if (! res_alloc ) {
    RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
  }
  else if (res_alloc == 1 ) {
#   define XfOrM96_COUNT (0+XfOrM94_COUNT)
#   define SETUP_XfOrM96(x) SETUP_XfOrM94(x)
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(make_single_bigdig_result (res_pos , res_digs [0 ] ) )) RET_VALUE_EMPTY_END ; 
  }
  else {
#   define XfOrM95_COUNT (0+XfOrM94_COUNT)
#   define SETUP_XfOrM95(x) SETUP_XfOrM94(x)
    o = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM95(_), GC_malloc_one_tagged (sizeof (Scheme_Bignum ) ) ); 
    o -> type = scheme_bignum_type ; 
    (& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex = ((res_pos ) | ((& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex & 0x2 ) ) ; 
    (((Scheme_Bignum * ) o ) -> len ) = res_alloc ; 
    (((Scheme_Bignum * ) o ) -> digits ) = res_digs ; 
    RET_VALUE_START (o ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_bignum_and (const Scheme_Object * a , const Scheme_Object * b ) {
  /* No conversion */
  if ((((Scheme_Bignum * ) a ) -> len ) > (((Scheme_Bignum * ) b ) -> len ) )
    return do_bitop (a , b , 0 ) ; 
  else return do_bitop (b , a , 0 ) ; 
}
Scheme_Object * scheme_bignum_or (const Scheme_Object * a , const Scheme_Object * b ) {
  /* No conversion */
  if ((((Scheme_Bignum * ) a ) -> len ) > (((Scheme_Bignum * ) b ) -> len ) )
    return do_bitop (a , b , 1 ) ; 
  else return do_bitop (b , a , 1 ) ; 
}
Scheme_Object * scheme_bignum_xor (const Scheme_Object * a , const Scheme_Object * b ) {
  /* No conversion */
  if ((((Scheme_Bignum * ) a ) -> len ) > (((Scheme_Bignum * ) b ) -> len ) )
    return do_bitop (a , b , 2 ) ; 
  else return do_bitop (b , a , 2 ) ; 
}
Scheme_Object * scheme_bignum_not (const Scheme_Object * a ) {
  Scheme_Object * o ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(o, 0)));
# define XfOrM122_COUNT (1)
# define SETUP_XfOrM122(x) SETUP(XfOrM122_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  o = NULLED_OUT ; 
  o = FUNCCALL(SETUP_XfOrM122(_), scheme_bignum_add1 (a ) ); 
  if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) {
#   define XfOrM124_COUNT (0+XfOrM122_COUNT)
#   define SETUP_XfOrM124(x) SETUP_XfOrM122(x)
    (& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex = ((! ((& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex & 0x1 ) ) | ((& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex & 0x2 ) ) ; 
    RET_VALUE_START ((scheme_bignum_normalize (o ) ) ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM123_COUNT (0+XfOrM122_COUNT)
#   define SETUP_XfOrM123(x) SETUP_XfOrM122(x)
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_bin_minus (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) , o ) )) RET_VALUE_EMPTY_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_bignum_shift (const Scheme_Object * n , long shift ) {
  Scheme_Object * o ; 
  bigdig * res_digs , * n_digs , quick_digs [1 ] , shift_out ; 
  long res_alloc , shift_words , shift_bits , i , j , n_size ; 
  bigdig nsd [1 ] ; 
  Scheme_Object * __funcarg11 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(res_digs, 0), PUSH(o, 1), PUSH(n, 2), PUSH(n_digs, 3)));
# define XfOrM125_COUNT (4)
# define SETUP_XfOrM125(x) SETUP(XfOrM125_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  o = NULLED_OUT ; 
  res_digs = NULLED_OUT ; 
  n_digs = NULLED_OUT ; 
  n_size = (((Scheme_Bignum * ) n ) -> len ) ; 
  if (n_size == 0 )
    RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
  if (shift == 0 )
    RET_VALUE_START ((__funcarg11 = FUNCCALL(SETUP_XfOrM125(_), bignum_copy (n , 0 ) ), (scheme_bignum_normalize (__funcarg11 ) ) ) ) RET_VALUE_END ; 
  n_digs = (((((Scheme_Bignum * ) n ) -> digits ) == ((Small_Bignum * ) (void * ) n ) -> v ) ? (nsd [0 ] = (((Scheme_Bignum * ) n ) -> digits ) [0 ] , nsd ) : (((Scheme_Bignum * ) n ) -> digits ) ) ; 
  if (shift < 0 ) {
    int shifted_off_one = 0 ; 
#   define XfOrM132_COUNT (0+XfOrM125_COUNT)
#   define SETUP_XfOrM132(x) SETUP_XfOrM125(x)
    shift = - shift ; 
    shift_words = shift / 64 ; 
    shift_bits = shift % 64 ; 
    if (shift_words >= n_size ) {
      if (((& ((Scheme_Bignum * ) n ) -> iso ) -> so . keyex & 0x1 ) )
        RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
      else RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (- 1 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
    }
    res_alloc = n_size - shift_words ; 
    if (shift_bits == 0 && ! ((& ((Scheme_Bignum * ) n ) -> iso ) -> so . keyex & 0x1 ) )
      res_alloc ++ ; 
    if (res_alloc < 2 )
      res_digs = quick_digs ; 
    else res_digs = FUNCCALL(SETUP_XfOrM132(_), allocate_bigdig_array (res_alloc ) ); 
    if (! ((& ((Scheme_Bignum * ) n ) -> iso ) -> so . keyex & 0x1 ) ) {
      for (i = 0 ; i < shift_words ; ++ i ) {
        if (n_digs [i ] != 0 ) {
          shifted_off_one = 1 ; 
          break ; 
        }
      }
    }
    for (i = 0 , j = shift_words ; j < n_size ; ++ i , ++ j ) {
      res_digs [i ] = n_digs [j ] ; 
    }
    if (shift_bits )
      shift_out = FUNCCALL(SETUP_XfOrM132(_), scheme_gmpn_rshift (res_digs , res_digs , res_alloc , shift_bits ) ); 
    else shift_out = 0 ; 
    if (! ((& ((Scheme_Bignum * ) n ) -> iso ) -> so . keyex & 0x1 ) && (shifted_off_one || shift_out ) ) {
#     define XfOrM133_COUNT (0+XfOrM132_COUNT)
#     define SETUP_XfOrM133(x) SETUP_XfOrM132(x)
      FUNCCALL(SETUP_XfOrM133(_), scheme_gmpn_add_1 (res_digs , res_digs , res_alloc , 1 ) ); 
    }
  }
  else {
#   define XfOrM129_COUNT (0+XfOrM125_COUNT)
#   define SETUP_XfOrM129(x) SETUP_XfOrM125(x)
    shift_words = shift / 64 ; 
    shift_bits = shift % 64 ; 
    res_alloc = (((Scheme_Bignum * ) n ) -> len ) + shift_words ; 
    if (shift_bits != 0 )
      ++ res_alloc ; 
    if (res_alloc < 2 )
      res_digs = quick_digs ; 
    else res_digs = FUNCCALL(SETUP_XfOrM129(_), allocate_bigdig_array (res_alloc ) ); 
    for (i = 0 , j = shift_words ; i < (((Scheme_Bignum * ) n ) -> len ) ; ++ i , ++ j ) {
      res_digs [j ] = n_digs [i ] ; 
    }
    if (shift_bits != 0 )
      FUNCCALL(SETUP_XfOrM129(_), scheme_gmpn_lshift (res_digs XFORM_OK_PLUS shift_words , res_digs XFORM_OK_PLUS shift_words , res_alloc - shift_words , shift_bits ) ); 
  }
  res_alloc = (bigdig_length (res_digs , res_alloc ) ) ; 
  if (res_alloc == 0 ) {
    RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
  }
  else if (res_alloc == 1 ) {
#   define XfOrM127_COUNT (0+XfOrM125_COUNT)
#   define SETUP_XfOrM127(x) SETUP_XfOrM125(x)
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(make_single_bigdig_result (((& ((Scheme_Bignum * ) n ) -> iso ) -> so . keyex & 0x1 ) , res_digs [0 ] ) )) RET_VALUE_EMPTY_END ; 
  }
  else {
#   define XfOrM126_COUNT (0+XfOrM125_COUNT)
#   define SETUP_XfOrM126(x) SETUP_XfOrM125(x)
    o = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM126(_), GC_malloc_one_tagged (sizeof (Scheme_Bignum ) ) ); 
    o -> type = scheme_bignum_type ; 
    (((Scheme_Bignum * ) o ) -> digits ) = res_digs ; 
    (((Scheme_Bignum * ) o ) -> len ) = res_alloc ; 
    (& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex = ((((& ((Scheme_Bignum * ) n ) -> iso ) -> so . keyex & 0x1 ) ) | ((& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex & 0x2 ) ) ; 
    RET_VALUE_START ((scheme_bignum_normalize (o ) ) ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
char * scheme_bignum_to_allocated_string (const Scheme_Object * b , int radix , int alloc ) {
  Scheme_Object * c ; 
  unsigned char * str , * str2 ; 
  int i , slen , start , clen ; 
  bigdig * c_digs ; 
  bigdig csd [1 ] ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(c, 0), PUSH(c_digs, 1), PUSH(str, 2), PUSH(str2, 3), PUSH(b, 4)));
# define XfOrM142_COUNT (5)
# define SETUP_XfOrM142(x) SETUP(XfOrM142_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  c = NULLED_OUT ; 
  str = NULLED_OUT ; 
  str2 = NULLED_OUT ; 
  c_digs = NULLED_OUT ; 
  if (radix != 10 && radix != 2 && radix != 8 && radix != 16 )
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "bad bignum radix: %d" , radix ) ); 
  if ((((Scheme_Bignum * ) b ) -> len ) == 0 ) {
#   define XfOrM151_COUNT (0+XfOrM142_COUNT)
#   define SETUP_XfOrM151(x) SETUP_XfOrM142(x)
    if (alloc ) {
#     define XfOrM152_COUNT (0+XfOrM151_COUNT)
#     define SETUP_XfOrM152(x) SETUP_XfOrM151(x)
      str2 = (unsigned char * ) FUNCCALL(SETUP_XfOrM152(_), GC_malloc_atomic (2 ) ); 
      str2 [0 ] = '0' ; 
      str2 [1 ] = 0 ; 
      RET_VALUE_START ((char * ) str2 ) RET_VALUE_END ; 
    }
    else RET_VALUE_START ("0" ) RET_VALUE_END ; 
  }
  c = FUNCCALL(SETUP_XfOrM142(_), bignum_copy (b , 1 ) ); 
  if (radix == 2 )
    slen = 64 * (((Scheme_Bignum * ) b ) -> len ) + 2 ; 
  else if (radix == 8 )
    slen = (int ) (ceil (64 * (((Scheme_Bignum * ) b ) -> len ) / 3.0 ) + 2 ) ; 
  else if (radix == 16 )
    slen = 64 * (((Scheme_Bignum * ) b ) -> len ) / 4 + 2 ; 
  else slen = (int ) (ceil (64 * (((Scheme_Bignum * ) b ) -> len ) * 0.30102999566398115 ) ) + 1 ; 
  str = (unsigned char * ) FUNCCALL(SETUP_XfOrM142(_), copy_to_protected (((void * ) 0 ) , slen , 0 ) ); 
  c_digs = (((((Scheme_Bignum * ) c ) -> digits ) == ((Small_Bignum * ) (void * ) c ) -> v ) ? (csd [0 ] = (((Scheme_Bignum * ) c ) -> digits ) [0 ] , csd ) : (((Scheme_Bignum * ) c ) -> digits ) ) ; 
  clen = (((Scheme_Bignum * ) c ) -> len ) ; 
  c_digs = FUNCCALL(SETUP_XfOrM142(_), copy_to_protected (c_digs , clen * sizeof (bigdig ) , 0 ) ); 
  ; 
  slen = FUNCCALL_AGAIN(scheme_gmpn_get_str (str , radix , c_digs , (((Scheme_Bignum * ) c ) -> len ) - 1 ) ); 
  (FUNCCALL(SETUP_XfOrM142(_), free_protected (c_digs ) ), c_digs = ((void * ) 0 ) ) ; 
  ; 
  {
    unsigned char * save = str ; 
    BLOCK_SETUP((PUSH(save, 0+XfOrM142_COUNT)));
#   define XfOrM150_COUNT (1+XfOrM142_COUNT)
#   define SETUP_XfOrM150(x) SETUP(XfOrM150_COUNT)
    str = (unsigned char * ) FUNCCALL(SETUP_XfOrM150(_), GC_malloc_atomic (slen ) ); 
    (memcpy (str , save , slen ) ) ; 
    FUNCCALL(SETUP_XfOrM150(_), free_protected (save ) ); 
  }
  i = 0 ; 
  while (i < slen && str [i ] == 0 ) {
    ++ i ; 
  }
  if (i == slen ) {
#   define XfOrM146_COUNT (0+XfOrM142_COUNT)
#   define SETUP_XfOrM146(x) SETUP_XfOrM142(x)
    if (alloc ) {
#     define XfOrM147_COUNT (0+XfOrM146_COUNT)
#     define SETUP_XfOrM147(x) SETUP_XfOrM146(x)
      str2 = (unsigned char * ) FUNCCALL(SETUP_XfOrM147(_), GC_malloc_atomic (2 ) ); 
      str2 [0 ] = '0' ; 
      str2 [1 ] = 0 ; 
      RET_VALUE_START ((char * ) str2 ) RET_VALUE_END ; 
    }
    else RET_VALUE_START ("0" ) RET_VALUE_END ; 
  }
  else slen = slen - i + 1 + (((& ((Scheme_Bignum * ) b ) -> iso ) -> so . keyex & 0x1 ) ? 0 : 1 ) ; 
  str2 = (unsigned char * ) FUNCCALL(SETUP_XfOrM142(_), GC_malloc_atomic (slen ) ); 
  start = i ; 
  if (! (((& ((Scheme_Bignum * ) b ) -> iso ) -> so . keyex & 0x1 ) ) ) {
    i = 1 ; 
    start -- ; 
    str2 [0 ] = '-' ; 
  }
  else i = 0 ; 
  for (; i < slen - 1 ; ++ i ) {
    if (str [i + start ] < 10 )
      str2 [i ] = str [i + start ] + '0' ; 
    else str2 [i ] = str [i + start ] + 'a' - 10 ; 
  }
  str2 [slen - 1 ] = 0 ; 
  RET_VALUE_START ((char * ) str2 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
char * scheme_bignum_to_string (const Scheme_Object * b , int radix ) {
  /* No conversion */
  return scheme_bignum_to_allocated_string (b , radix , 0 ) ; 
}
Scheme_Object * scheme_read_bignum (const mzchar * str , int offset , int radix ) {
  int len , negate , stri , alloc , i , test ; 
  Scheme_Object * o ; 
  bigdig * digs ; 
  unsigned char * istring ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(str, 1), PUSH(digs, 2), PUSH(istring, 3)));
# define XfOrM154_COUNT (4)
# define SETUP_XfOrM154(x) SETUP(XfOrM154_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  o = NULLED_OUT ; 
  digs = NULLED_OUT ; 
  istring = NULLED_OUT ; 
  if (radix < 0 || radix > 16 ) {
    RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
  }
  negate = 0 ; 
  stri = offset ; 
  while ((str [stri ] == '+' ) || (str [stri ] == '-' ) ) {
    if (str [stri ] == '-' )
      negate = ! negate ; 
    stri ++ ; 
  }
  len = FUNCCALL(SETUP_XfOrM154(_), scheme_char_strlen (str XFORM_OK_PLUS stri ) ); 
  if (radix == 10 && (len < 19 ) ) {
    long fx ; 
    if (! str [stri ] )
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    for (fx = 0 ; str [stri ] ; stri ++ ) {
      if (str [stri ] < '0' || str [stri ] > '9' )
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      fx = (fx * 10 ) + (str [stri ] - '0' ) ; 
    }
    if (negate )
      fx = - fx ; 
    RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (fx ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
  }
  istring = (unsigned char * ) FUNCCALL(SETUP_XfOrM154(_), copy_to_protected (((void * ) 0 ) , len , 0 ) ); 
  i = stri ; 
  while (str [i ] != 0 ) {
    if (str [i ] >= '0' && str [i ] <= '9' )
      istring [i - stri ] = str [i ] - '0' ; 
    else if (str [i ] >= 'a' && str [i ] <= 'z' )
      istring [i - stri ] = str [i ] - 'a' + 10 ; 
    else if (str [i ] >= 'A' && str [i ] <= 'Z' )
      istring [i - stri ] = str [i ] - 'A' + 10 ; 
    else RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    if (istring [i - stri ] >= radix )
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    ++ i ; 
  }
  o = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM154(_), GC_malloc_one_tagged (sizeof (Scheme_Bignum ) ) ); 
  o -> type = scheme_bignum_type ; 
  alloc = (int ) (ceil (len * log ((double ) radix ) / (32 * log ((double ) 2 ) ) ) ) ; 
  digs = FUNCCALL(SETUP_XfOrM154(_), copy_to_protected (((void * ) 0 ) , alloc * sizeof (bigdig ) , 1 ) ); 
  ; 
  (& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex = ((! negate ) | ((& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex & 0x2 ) ) ; 
  test = FUNCCALL(SETUP_XfOrM154(_), scheme_gmpn_set_str (digs , istring , len , radix ) ); 
  FUNCCALL_AGAIN(free_protected (istring ) ); 
  {
    bigdig * save = digs ; 
    BLOCK_SETUP((PUSH(save, 0+XfOrM154_COUNT)));
#   define XfOrM155_COUNT (1+XfOrM154_COUNT)
#   define SETUP_XfOrM155(x) SETUP(XfOrM155_COUNT)
    digs = (bigdig * ) FUNCCALL(SETUP_XfOrM155(_), GC_malloc_atomic (alloc * sizeof (bigdig ) ) ); 
    (memcpy (digs , save , alloc * sizeof (bigdig ) ) ) ; 
    (FUNCCALL(SETUP_XfOrM155(_), free_protected (save ) ), save = ((void * ) 0 ) ) ; 
    ; 
  }
  ; 
  alloc = (bigdig_length (digs , alloc ) ) ; 
  (((Scheme_Bignum * ) o ) -> len ) = alloc ; 
  (((Scheme_Bignum * ) o ) -> digits ) = digs ; 
  RET_VALUE_START ((scheme_bignum_normalize (o ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_read_bignum_bytes (const char * str , int offset , int radix ) {
  mzchar * us ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(us, 0)));
# define XfOrM164_COUNT (1)
# define SETUP_XfOrM164(x) SETUP(XfOrM164_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  us = NULLED_OUT ; 
  us = FUNCCALL(SETUP_XfOrM164(_), scheme_utf8_decode_to_buffer ((unsigned char * ) str , strlen (str XFORM_OK_PLUS offset ) , ((void * ) 0 ) , 0 ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_read_bignum (us , 0 , radix ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void bignum_double_inplace (Scheme_Object * * _stk_o ) {
  int carry , len ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(_stk_o, 0)));
# define XfOrM165_COUNT (1)
# define SETUP_XfOrM165(x) SETUP(XfOrM165_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  len = (((Scheme_Bignum * ) * _stk_o ) -> len ) ; 
  if (len == 0 )
    RET_NOTHING ; 
  carry = FUNCCALL(SETUP_XfOrM165(_), scheme_gmpn_lshift ((((Scheme_Bignum * ) * _stk_o ) -> digits ) , (((Scheme_Bignum * ) * _stk_o ) -> digits ) , len , 1 ) ); 
  if (carry )
    * _stk_o = FUNCCALL_EMPTY(bignum_copy (* _stk_o , carry ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void bignum_add1_inplace (Scheme_Object * * _stk_o ) {
  int carry , len ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(_stk_o, 0)));
# define XfOrM166_COUNT (1)
# define SETUP_XfOrM166(x) SETUP(XfOrM166_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  len = (((Scheme_Bignum * ) * _stk_o ) -> len ) ; 
  if (len == 0 ) {
#   define XfOrM167_COUNT (0+XfOrM166_COUNT)
#   define SETUP_XfOrM167(x) SETUP_XfOrM166(x)
    * _stk_o = FUNCCALL(SETUP_XfOrM167(_), bignum_copy (* _stk_o , 1 ) ); 
    RET_NOTHING ; 
  }
  carry = FUNCCALL(SETUP_XfOrM166(_), scheme_gmpn_add_1 ((((Scheme_Bignum * ) * _stk_o ) -> digits ) , (((Scheme_Bignum * ) * _stk_o ) -> digits ) , len , 1 ) ); 
  if (carry )
    * _stk_o = FUNCCALL_EMPTY(bignum_copy (* _stk_o , carry ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int is_double_inf (double d ) {
  return (isinf (d ) && (d > 0 ) ) ; 
}
double scheme_bignum_to_double_inf_info (const Scheme_Object * n , int skip , int * _skipped ) {
  int nl , skipped ; 
  bigdig * na ; 
  double d ; 
  nl = (((Scheme_Bignum * ) n ) -> len ) ; 
  na = (((Scheme_Bignum * ) n ) -> digits ) + nl ; 
  skipped = nl ; 
  if (skip >= nl )
    return 0.0 ; 
  else nl -= skip ; 
  d = 0 ; 
  while (nl -- ) {
    d *= (double ) 18446744073709551616.0 ; 
    d += * (-- na ) ; 
    if (is_double_inf (d ) )
      break ; 
    -- skipped ; 
  }
  if (_skipped )
    * _skipped = skipped ; 
  if (! ((& ((Scheme_Bignum * ) n ) -> iso ) -> so . keyex & 0x1 ) )
    d = - d ; 
  return d ; 
}
double scheme_bignum_to_double (const Scheme_Object * n ) {
  return scheme_bignum_to_double_inf_info (n , 0 , ((void * ) 0 ) ) ; 
}
Scheme_Object * scheme_bignum_from_double (double d ) {
  Small_Bignum s1 ; 
  int negate , log , times , i ; 
  double r ; 
  Scheme_Object * n , * m ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(m, 0), PUSH(n, 1), PUSH(s1.o.digits, 2)));
# define XfOrM168_COUNT (3)
# define SETUP_XfOrM168(x) SETUP(XfOrM168_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s1.o.digits = NULLED_OUT ; 
  n = NULLED_OUT ; 
  m = NULLED_OUT ; 
  r = 1 ; 
  FUNCCALL(SETUP_XfOrM168(_), scheme_check_double ("inexact->exact" , d , "integer" ) ); 
  if (d < 0 ) {
    negate = 1 ; 
    d = - d ; 
  }
  else negate = 0 ; 
  if (d < 1.0 )
    RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
  log = 0 ; 
  while (r < d ) {
    log ++ ; 
    r *= 2.0 ; 
  }
  if (log > 53 ) {
    times = log - 53 ; 
    log = 53 ; 
    for (i = 0 ; i < times ; i ++ ) {
      d /= 2 ; 
    }
  }
  else times = 0 ; 
  r = pow (2.0 , (double ) log ) ; 
  n = scheme_make_small_bignum (0 , & s1 ) ; 
  log ++ ; 
  while (log -- ) {
#   define XfOrM174_COUNT (0+XfOrM168_COUNT)
#   define SETUP_XfOrM174(x) SETUP_XfOrM168(x)
    FUNCCALL(SETUP_XfOrM174(_), bignum_double_inplace (& n ) ); 
    if (d >= r ) {
#     define XfOrM175_COUNT (0+XfOrM174_COUNT)
#     define SETUP_XfOrM175(x) SETUP_XfOrM174(x)
      d -= r ; 
      FUNCCALL(SETUP_XfOrM175(_), bignum_add1_inplace (& n ) ); 
    }
    r /= 2 ; 
  }
  if (times ) {
#   define XfOrM169_COUNT (0+XfOrM168_COUNT)
#   define SETUP_XfOrM169(x) SETUP_XfOrM168(x)
    m = FUNCCALL(SETUP_XfOrM169(_), scheme_make_bignum (1 ) ); 
    while (times -- ) {
#     define XfOrM171_COUNT (0+XfOrM169_COUNT)
#     define SETUP_XfOrM171(x) SETUP_XfOrM169(x)
      FUNCCALL(SETUP_XfOrM171(_), bignum_double_inplace (& m ) ); 
    }
    n = FUNCCALL(SETUP_XfOrM169(_), bignum_multiply (n , m , 0 ) ); 
  }
  if (negate )
    (& ((Scheme_Bignum * ) n ) -> iso ) -> so . keyex = ((! ((& ((Scheme_Bignum * ) n ) -> iso ) -> so . keyex & 0x1 ) ) | ((& ((Scheme_Bignum * ) n ) -> iso ) -> so . keyex & 0x2 ) ) ; 
  n = (scheme_bignum_normalize (n ) ) ; 
  RET_VALUE_START (n ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_bignum_divide (const Scheme_Object * n , const Scheme_Object * d , Scheme_Object * * _stk_qp , Scheme_Object * * _stk_rp , int norm ) {
  int cmp ; 
  Scheme_Object * __funcarg12 = NULLED_OUT ; 
  PREPARE_VAR_STACK(11);
  BLOCK_SETUP_TOP((PUSH(_stk_rp, 0), PUSH(n, 1), PUSH(_stk_qp, 2), PUSH(d, 3)));
# define XfOrM182_COUNT (4)
# define SETUP_XfOrM182(x) SETUP(XfOrM182_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  cmp = (bignum_abs_cmp (n , d ) ) ; 
  if (cmp == - 1 ) {
#   define XfOrM191_COUNT (0+XfOrM182_COUNT)
#   define SETUP_XfOrM191(x) SETUP_XfOrM182(x)
    if (_stk_qp )
      * _stk_qp = (norm ? ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) : FUNCCALL(SETUP_XfOrM191(_), scheme_make_bignum (0 ) )) ; 
    if (_stk_rp )
      * _stk_rp = (norm ? (__funcarg12 = FUNCCALL(SETUP_XfOrM191(_), bignum_copy (n , 0 ) ), (scheme_bignum_normalize (__funcarg12 ) ) ) : FUNCCALL(SETUP_XfOrM191(_), bignum_copy (n , 0 ) )) ; 
    RET_NOTHING ; 
  }
  else if (cmp == 0 ) {
    int n_pos , d_pos , res ; 
#   define XfOrM190_COUNT (0+XfOrM182_COUNT)
#   define SETUP_XfOrM190(x) SETUP_XfOrM182(x)
    n_pos = ((& ((Scheme_Bignum * ) n ) -> iso ) -> so . keyex & 0x1 ) ; 
    d_pos = ((& ((Scheme_Bignum * ) d ) -> iso ) -> so . keyex & 0x1 ) ; 
    res = ((! (n_pos ) ^ ! (d_pos ) ) ? - 1 : 1 ) ; 
    if (_stk_qp )
      * _stk_qp = (norm ? ((Scheme_Object * ) (void * ) (long ) ((((long ) (res ) ) << 1 ) | 0x1 ) ) : FUNCCALL(SETUP_XfOrM190(_), scheme_make_bignum (res ) )) ; 
    if (_stk_rp )
      * _stk_rp = (norm ? ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) : FUNCCALL(SETUP_XfOrM190(_), scheme_make_bignum (0 ) )) ; 
    RET_NOTHING ; 
  }
  else {
    int i ; 
    long n_size , d_size , q_alloc , r_alloc , d_pos ; 
    short n_pos ; 
    bigdig * q_digs , * r_digs , * n_digs , * d_digs ; 
    Scheme_Object * q , * r ; 
    bigdig ns [1 ] ; 
    bigdig ds [1 ] ; 
    BLOCK_SETUP((PUSH(q_digs, 0+XfOrM182_COUNT), PUSH(d_digs, 1+XfOrM182_COUNT), PUSH(r, 2+XfOrM182_COUNT), PUSH(q, 3+XfOrM182_COUNT), PUSH(r_digs, 4+XfOrM182_COUNT), PUSH(n_digs, 5+XfOrM182_COUNT)));
#   define XfOrM183_COUNT (6+XfOrM182_COUNT)
#   define SETUP_XfOrM183(x) SETUP(XfOrM183_COUNT)
    q_digs = NULLED_OUT ; 
    r_digs = NULLED_OUT ; 
    n_digs = NULLED_OUT ; 
    d_digs = NULLED_OUT ; 
    q = NULLED_OUT ; 
    r = NULLED_OUT ; 
    n_size = (((Scheme_Bignum * ) n ) -> len ) ; 
    d_size = (((Scheme_Bignum * ) d ) -> len ) ; 
    q = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM183(_), GC_malloc_one_tagged (sizeof (Scheme_Bignum ) ) ); 
    q -> type = scheme_bignum_type ; 
    r = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM183(_), GC_malloc_one_tagged (sizeof (Scheme_Bignum ) ) ); 
    r -> type = scheme_bignum_type ; 
    q_alloc = n_size - d_size + 1 ; 
    r_alloc = d_size ; 
    q_digs = FUNCCALL(SETUP_XfOrM183(_), copy_to_protected (((void * ) 0 ) , q_alloc * sizeof (bigdig ) , 1 ) ); 
    ; 
    r_digs = FUNCCALL_AGAIN(copy_to_protected (((void * ) 0 ) , r_alloc * sizeof (bigdig ) , 1 ) ); 
    ; 
    n_digs = (((((Scheme_Bignum * ) n ) -> digits ) == ((Small_Bignum * ) (void * ) n ) -> v ) ? (ns [0 ] = (((Scheme_Bignum * ) n ) -> digits ) [0 ] , ns ) : (((Scheme_Bignum * ) n ) -> digits ) ) ; 
    d_digs = (((((Scheme_Bignum * ) d ) -> digits ) == ((Small_Bignum * ) (void * ) d ) -> v ) ? (ds [0 ] = (((Scheme_Bignum * ) d ) -> digits ) [0 ] , ds ) : (((Scheme_Bignum * ) d ) -> digits ) ) ; 
    n_digs = FUNCCALL(SETUP_XfOrM183(_), copy_to_protected (n_digs , n_size * sizeof (bigdig ) , 0 ) ); 
    ; 
    d_digs = FUNCCALL_AGAIN(copy_to_protected (d_digs , d_size * sizeof (bigdig ) , 0 ) ); 
    ; 
    for (i = 0 ; (i < d_size ) && (d_digs [i ] == 0 ) ; i ++ ) {
      r_digs [i ] = n_digs [i ] ; 
    }
    FUNCCALL(SETUP_XfOrM183(_), scheme_gmpn_tdiv_qr (q_digs , r_digs XFORM_OK_PLUS i , 0 , n_digs XFORM_OK_PLUS i , n_size - i , d_digs XFORM_OK_PLUS i , d_size - i ) ); 
    (FUNCCALL(SETUP_XfOrM183(_), free_protected (d_digs ) ), d_digs = ((void * ) 0 ) ) ; 
    ; 
    (FUNCCALL(SETUP_XfOrM183(_), free_protected (n_digs ) ), n_digs = ((void * ) 0 ) ) ; 
    ; 
    {
      bigdig * save = q_digs ; 
      BLOCK_SETUP((PUSH(save, 0+XfOrM183_COUNT)));
#     define XfOrM187_COUNT (1+XfOrM183_COUNT)
#     define SETUP_XfOrM187(x) SETUP(XfOrM187_COUNT)
      q_digs = (bigdig * ) FUNCCALL(SETUP_XfOrM187(_), GC_malloc_atomic (q_alloc * sizeof (bigdig ) ) ); 
      (memcpy (q_digs , save , q_alloc * sizeof (bigdig ) ) ) ; 
      (FUNCCALL(SETUP_XfOrM187(_), free_protected (save ) ), save = ((void * ) 0 ) ) ; 
      ; 
    }
    ; 
    {
      bigdig * save = r_digs ; 
      BLOCK_SETUP((PUSH(save, 0+XfOrM183_COUNT)));
#     define XfOrM186_COUNT (1+XfOrM183_COUNT)
#     define SETUP_XfOrM186(x) SETUP(XfOrM186_COUNT)
      r_digs = (bigdig * ) FUNCCALL(SETUP_XfOrM186(_), GC_malloc_atomic (r_alloc * sizeof (bigdig ) ) ); 
      (memcpy (r_digs , save , r_alloc * sizeof (bigdig ) ) ) ; 
      (FUNCCALL(SETUP_XfOrM186(_), free_protected (save ) ), save = ((void * ) 0 ) ) ; 
      ; 
    }
    ; 
    n_pos = ((& ((Scheme_Bignum * ) n ) -> iso ) -> so . keyex & 0x1 ) ; 
    d_pos = ((& ((Scheme_Bignum * ) d ) -> iso ) -> so . keyex & 0x1 ) ; 
    if (_stk_rp ) {
#     define XfOrM185_COUNT (0+XfOrM183_COUNT)
#     define SETUP_XfOrM185(x) SETUP_XfOrM183(x)
      (((Scheme_Bignum * ) r ) -> digits ) = r_digs ; 
      r_alloc = (bigdig_length (r_digs , r_alloc ) ) ; 
      (((Scheme_Bignum * ) r ) -> len ) = r_alloc ; 
      (& ((Scheme_Bignum * ) r ) -> iso ) -> so . keyex = ((n_pos ) | ((& ((Scheme_Bignum * ) r ) -> iso ) -> so . keyex & 0x2 ) ) ; 
      * _stk_rp = (norm ? (scheme_bignum_normalize (r ) ) : r ) ; 
    }
    if (_stk_qp ) {
#     define XfOrM184_COUNT (0+XfOrM183_COUNT)
#     define SETUP_XfOrM184(x) SETUP_XfOrM183(x)
      (((Scheme_Bignum * ) q ) -> digits ) = q_digs ; 
      q_alloc = (bigdig_length (q_digs , q_alloc ) ) ; 
      (((Scheme_Bignum * ) q ) -> len ) = q_alloc ; 
      (& ((Scheme_Bignum * ) q ) -> iso ) -> so . keyex = ((! (! (n_pos ) ^ ! (d_pos ) ) ) | ((& ((Scheme_Bignum * ) q ) -> iso ) -> so . keyex & 0x2 ) ) ; 
      * _stk_qp = (norm ? (scheme_bignum_normalize (q ) ) : q ) ; 
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static unsigned long fixnum_sqrt (unsigned long n , unsigned long * rem ) {
  /* No conversion */
  unsigned long root = 0 ; 
  unsigned long square = 0 ; 
  unsigned long try_root , try_square ; 
  int i ; 
  for (i = 31 ; i >= 0 ; i -- ) {
    try_root = root | (0x1 << i ) ; 
    try_square = try_root * try_root ; 
    if (try_square <= n ) {
      root = try_root ; 
      square = try_square ; 
    }
  }
  if (rem )
    * rem = n - square ; 
  return root ; 
}
Scheme_Object * scheme_integer_sqrt (const Scheme_Object * n ) {
  /* No conversion */
  return scheme_integer_sqrt_rem (n , ((void * ) 0 ) ) ; 
}
Scheme_Object * scheme_integer_sqrt_rem (const Scheme_Object * n , Scheme_Object * * remainder ) {
  Scheme_Object * o ; 
  int rem_size ; 
  bigdig qsd [1 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(n, 0), PUSH(remainder, 1), PUSH(o, 2)));
# define XfOrM198_COUNT (3)
# define SETUP_XfOrM198(x) SETUP(XfOrM198_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  o = NULLED_OUT ; 
  if ((((long ) (n ) ) & 0x1 ) ) {
    unsigned long root , rem ; 
#   define XfOrM210_COUNT (0+XfOrM198_COUNT)
#   define SETUP_XfOrM210(x) SETUP_XfOrM198(x)
    root = FUNCCALL(SETUP_XfOrM210(_), fixnum_sqrt ((((long ) (n ) ) >> 1 ) , & rem ) ); 
    if (remainder ) {
#     define XfOrM211_COUNT (0+XfOrM210_COUNT)
#     define SETUP_XfOrM211(x) SETUP_XfOrM210(x)
      o = FUNCCALL(SETUP_XfOrM211(_), scheme_make_integer_value (rem ) ); 
      * remainder = o ; 
    }
    rem_size = (rem == 0 ? 0 : 1 ) ; 
    o = ((Scheme_Object * ) (void * ) (long ) ((((long ) (root ) ) << 1 ) | 0x1 ) ) ; 
  }
  else {
    long n_size , res_alloc , rem_alloc ; 
    bigdig * res_digs , * rem_digs , * sqr_digs ; 
    BLOCK_SETUP((PUSH(sqr_digs, 0+XfOrM198_COUNT), PUSH(res_digs, 1+XfOrM198_COUNT), PUSH(rem_digs, 2+XfOrM198_COUNT)));
#   define XfOrM202_COUNT (3+XfOrM198_COUNT)
#   define SETUP_XfOrM202(x) SETUP(XfOrM202_COUNT)
    res_digs = NULLED_OUT ; 
    rem_digs = NULLED_OUT ; 
    sqr_digs = NULLED_OUT ; 
    n_size = (((Scheme_Bignum * ) n ) -> len ) ; 
    if (n_size == 0 )
      RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
    sqr_digs = (((((Scheme_Bignum * ) n ) -> digits ) == ((Small_Bignum * ) (void * ) n ) -> v ) ? (qsd [0 ] = (((Scheme_Bignum * ) n ) -> digits ) [0 ] , qsd ) : (((Scheme_Bignum * ) n ) -> digits ) ) ; 
    if (n_size & 0x1 )
      res_alloc = (n_size + 1 ) >> 1 ; 
    else res_alloc = n_size >> 1 ; 
    res_digs = FUNCCALL(SETUP_XfOrM202(_), copy_to_protected (((void * ) 0 ) , res_alloc * sizeof (bigdig ) , 1 ) ); 
    ; 
    if (remainder ) {
#     define XfOrM209_COUNT (0+XfOrM202_COUNT)
#     define SETUP_XfOrM209(x) SETUP_XfOrM202(x)
      rem_alloc = n_size ; 
      rem_digs = FUNCCALL(SETUP_XfOrM209(_), copy_to_protected (((void * ) 0 ) , rem_alloc * sizeof (bigdig ) , 1 ) ); 
      ; 
    }
    else {
      rem_alloc = 0 ; 
      rem_digs = ((void * ) 0 ) ; 
    }
    sqr_digs = FUNCCALL(SETUP_XfOrM202(_), copy_to_protected (sqr_digs , n_size * sizeof (bigdig ) , 0 ) ); 
    ; 
    rem_size = FUNCCALL(SETUP_XfOrM202(_), scheme_gmpn_sqrtrem (res_digs , rem_digs , sqr_digs , n_size ) ); 
    (FUNCCALL(SETUP_XfOrM202(_), free_protected (sqr_digs ) ), sqr_digs = ((void * ) 0 ) ) ; 
    ; 
    if (remainder || rem_size == 0 ) {
#     define XfOrM203_COUNT (0+XfOrM202_COUNT)
#     define SETUP_XfOrM203(x) SETUP_XfOrM202(x)
      {
        bigdig * save = res_digs ; 
        BLOCK_SETUP((PUSH(save, 0+XfOrM203_COUNT)));
#       define XfOrM207_COUNT (1+XfOrM203_COUNT)
#       define SETUP_XfOrM207(x) SETUP(XfOrM207_COUNT)
        res_digs = (bigdig * ) FUNCCALL(SETUP_XfOrM207(_), GC_malloc_atomic (res_alloc * sizeof (bigdig ) ) ); 
        (memcpy (res_digs , save , res_alloc * sizeof (bigdig ) ) ) ; 
        (FUNCCALL(SETUP_XfOrM207(_), free_protected (save ) ), save = ((void * ) 0 ) ) ; 
        ; 
      }
      ; 
      if (remainder && rem_size == 0 ) {
#       define XfOrM206_COUNT (0+XfOrM203_COUNT)
#       define SETUP_XfOrM206(x) SETUP_XfOrM203(x)
        * remainder = ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
        (FUNCCALL(SETUP_XfOrM206(_), free_protected (rem_digs ) ), rem_digs = ((void * ) 0 ) ) ; 
        ; 
      }
      else if (remainder ) {
        Scheme_Object * p ; 
        BLOCK_SETUP((PUSH(p, 0+XfOrM203_COUNT)));
#       define XfOrM204_COUNT (1+XfOrM203_COUNT)
#       define SETUP_XfOrM204(x) SETUP(XfOrM204_COUNT)
        p = NULLED_OUT ; 
        {
          bigdig * save = rem_digs ; 
          BLOCK_SETUP((PUSH(save, 0+XfOrM204_COUNT)));
#         define XfOrM205_COUNT (1+XfOrM204_COUNT)
#         define SETUP_XfOrM205(x) SETUP(XfOrM205_COUNT)
          rem_digs = (bigdig * ) FUNCCALL(SETUP_XfOrM205(_), GC_malloc_atomic (rem_alloc * sizeof (bigdig ) ) ); 
          (memcpy (rem_digs , save , rem_alloc * sizeof (bigdig ) ) ) ; 
          (FUNCCALL(SETUP_XfOrM205(_), free_protected (save ) ), save = ((void * ) 0 ) ) ; 
          ; 
        }
        ; 
        p = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM204(_), GC_malloc_one_tagged (sizeof (Scheme_Bignum ) ) ); 
        p -> type = scheme_bignum_type ; 
        rem_alloc = (bigdig_length (rem_digs , rem_alloc ) ) ; 
        (((Scheme_Bignum * ) p ) -> len ) = rem_alloc ; 
        (((Scheme_Bignum * ) p ) -> digits ) = rem_digs ; 
        (& ((Scheme_Bignum * ) p ) -> iso ) -> so . keyex = ((1 ) | ((& ((Scheme_Bignum * ) p ) -> iso ) -> so . keyex & 0x2 ) ) ; 
        o = (scheme_bignum_normalize (p ) ) ; 
        * remainder = o ; 
      }
      o = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM203(_), GC_malloc_one_tagged (sizeof (Scheme_Bignum ) ) ); 
      o -> type = scheme_bignum_type ; 
      res_alloc = (bigdig_length (res_digs , res_alloc ) ) ; 
      (((Scheme_Bignum * ) o ) -> len ) = res_alloc ; 
      (((Scheme_Bignum * ) o ) -> digits ) = res_digs ; 
      (& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex = ((1 ) | ((& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex & 0x2 ) ) ; 
      RET_VALUE_START ((scheme_bignum_normalize (o ) ) ) RET_VALUE_END ; 
    }
    else o = ((void * ) 0 ) ; 
    (FUNCCALL(SETUP_XfOrM202(_), free_protected (res_digs ) ), res_digs = ((void * ) 0 ) ) ; 
    ; 
  }
  if (remainder || rem_size == 0 )
    RET_VALUE_START (o ) RET_VALUE_END ; 
  else {
    double v ; 
#   define XfOrM199_COUNT (0+XfOrM198_COUNT)
#   define SETUP_XfOrM199(x) SETUP_XfOrM198(x)
    if ((((long ) (n ) ) & 0x1 ) )
      v = (double ) (((long ) (n ) ) >> 1 ) ; 
    else {
#     define XfOrM200_COUNT (0+XfOrM199_COUNT)
#     define SETUP_XfOrM200(x) SETUP_XfOrM199(x)
      v = scheme_bignum_to_double (n ) ; 
      if ((isinf (v ) && (v > 0 ) ) ) {
#       define XfOrM201_COUNT (0+XfOrM200_COUNT)
#       define SETUP_XfOrM201(x) SETUP_XfOrM200(x)
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_double (v ) )) RET_VALUE_EMPTY_END ; 
      }
    }
    v = sqrt (v ) ; 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_double (v ) )) RET_VALUE_EMPTY_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int gcd_calls = 0 ; 
Scheme_Object * scheme_bignum_gcd (const Scheme_Object * n , const Scheme_Object * d ) {
  bigdig * r_digs , * n_digs , * d_digs ; 
  long n_size , d_size , r_alloc , r_size ; 
  int res_double ; 
  Scheme_Object * r ; 
  bigdig ns [1 ] ; 
  bigdig ds [1 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(n_digs, 0), PUSH(n, 1), PUSH(d_digs, 2), PUSH(r, 3), PUSH(r_digs, 4), PUSH(d, 5)));
# define XfOrM212_COUNT (6)
# define SETUP_XfOrM212(x) SETUP(XfOrM212_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  r_digs = NULLED_OUT ; 
  n_digs = NULLED_OUT ; 
  d_digs = NULLED_OUT ; 
  r = NULLED_OUT ; 
  if ((scheme_bignum_lt (d , n ) ) ) {
    const Scheme_Object * tmp ; 
    tmp = NULLED_OUT ; 
    tmp = n ; 
    n = d ; 
    d = tmp ; 
  }
  n_size = (((Scheme_Bignum * ) n ) -> len ) ; 
  d_size = (((Scheme_Bignum * ) d ) -> len ) ; 
  if (! n_size )
    RET_VALUE_START ((Scheme_Object * ) d ) RET_VALUE_END ; 
  r = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM212(_), GC_malloc_one_tagged (sizeof (Scheme_Bignum ) ) ); 
  r -> type = scheme_bignum_type ; 
  n_digs = (((((Scheme_Bignum * ) n ) -> digits ) == ((Small_Bignum * ) (void * ) n ) -> v ) ? (ns [0 ] = (((Scheme_Bignum * ) n ) -> digits ) [0 ] , ns ) : (((Scheme_Bignum * ) n ) -> digits ) ) ; 
  d_digs = (((((Scheme_Bignum * ) d ) -> digits ) == ((Small_Bignum * ) (void * ) d ) -> v ) ? (ds [0 ] = (((Scheme_Bignum * ) d ) -> digits ) [0 ] , ds ) : (((Scheme_Bignum * ) d ) -> digits ) ) ; 
  n_digs = FUNCCALL(SETUP_XfOrM212(_), copy_to_protected (n_digs , n_size * sizeof (bigdig ) , 0 ) ); 
  ; 
  d_digs = FUNCCALL_AGAIN(copy_to_protected (d_digs , d_size * sizeof (bigdig ) , 0 ) ); 
  ; 
  {
    bigdig mask ; 
    int b , w , nz = 0 , dz = 0 ; 
#   define XfOrM214_COUNT (0+XfOrM212_COUNT)
#   define SETUP_XfOrM214(x) SETUP_XfOrM212(x)
    b = 1 ; 
    w = 0 ; 
    mask = 0x1 ; 
    while (! (n_digs [w ] & mask ) ) {
      nz ++ ; 
      if (b == 64 ) {
        b = 1 ; 
        mask = 0x1 ; 
        w ++ ; 
      }
      else {
        b ++ ; 
        mask = mask << 1 ; 
      }
    }
    b = 1 ; 
    w = 0 ; 
    mask = 0x1 ; 
    while ((dz < nz ) && ! (d_digs [w ] & mask ) ) {
      dz ++ ; 
      if (b == 64 ) {
        b = 1 ; 
        mask = 0x1 ; 
        w ++ ; 
      }
      else {
        b ++ ; 
        mask = mask << 1 ; 
      }
    }
    if (nz ) {
#     define XfOrM216_COUNT (0+XfOrM214_COUNT)
#     define SETUP_XfOrM216(x) SETUP_XfOrM214(x)
      w = nz / 64 ; 
      (memmove (n_digs , n_digs + w , sizeof (bigdig ) * (n_size - w ) ) ) ; 
      n_size -= w ; 
      w = nz & (64 - 1 ) ; 
      if (w )
        FUNCCALL(SETUP_XfOrM216(_), scheme_gmpn_rshift (n_digs , n_digs , n_size , w ) ); 
    }
    if (dz ) {
#     define XfOrM215_COUNT (0+XfOrM214_COUNT)
#     define SETUP_XfOrM215(x) SETUP_XfOrM214(x)
      w = dz / 64 ; 
      (memmove (d_digs , d_digs + w , sizeof (bigdig ) * (d_size - w ) ) ) ; 
      d_size -= w ; 
      w = dz & (64 - 1 ) ; 
      if (w )
        FUNCCALL(SETUP_XfOrM215(_), scheme_gmpn_rshift (d_digs , d_digs , d_size , w ) ); 
    }
    if (nz < dz )
      res_double = nz ; 
    else res_double = dz ; 
    if (! (n_digs [n_size - 1 ] ) )
      -- n_size ; 
    if (! (d_digs [d_size - 1 ] ) )
      -- d_size ; 
  }
  r_alloc = n_size ; 
  r_digs = FUNCCALL(SETUP_XfOrM212(_), copy_to_protected (((void * ) 0 ) , r_alloc * sizeof (bigdig ) , 1 ) ); 
  ; 
  r_size = FUNCCALL_AGAIN(scheme_gmpn_gcd (r_digs , d_digs , d_size , n_digs , n_size ) ); 
  (FUNCCALL(SETUP_XfOrM212(_), free_protected (d_digs ) ), d_digs = ((void * ) 0 ) ) ; 
  ; 
  (FUNCCALL(SETUP_XfOrM212(_), free_protected (n_digs ) ), n_digs = ((void * ) 0 ) ) ; 
  ; 
  {
    bigdig * save = r_digs ; 
    BLOCK_SETUP((PUSH(save, 0+XfOrM212_COUNT)));
#   define XfOrM213_COUNT (1+XfOrM212_COUNT)
#   define SETUP_XfOrM213(x) SETUP(XfOrM213_COUNT)
    r_digs = (bigdig * ) FUNCCALL(SETUP_XfOrM213(_), GC_malloc_atomic (r_size * sizeof (bigdig ) ) ); 
    (memcpy (r_digs , save , r_size * sizeof (bigdig ) ) ) ; 
    (FUNCCALL(SETUP_XfOrM213(_), free_protected (save ) ), save = ((void * ) 0 ) ) ; 
    ; 
  }
  ; 
  (((Scheme_Bignum * ) r ) -> digits ) = r_digs ; 
  r_alloc = (bigdig_length (r_digs , r_size ) ) ; 
  (((Scheme_Bignum * ) r ) -> len ) = r_alloc ; 
  (& ((Scheme_Bignum * ) r ) -> iso ) -> so . keyex = ((1 ) | ((& ((Scheme_Bignum * ) r ) -> iso ) -> so . keyex & 0x2 ) ) ; 
  if (res_double )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_bignum_shift (r , res_double ) )) RET_VALUE_EMPTY_END ; 
  else RET_VALUE_START ((scheme_bignum_normalize (r ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_bignum_use_fuel (long n ) {
  /* No conversion */
  {
    if ((scheme_fuel_counter ) <= 0 ) {
      scheme_out_of_fuel () ; 
    }
  }
  ; 
}
