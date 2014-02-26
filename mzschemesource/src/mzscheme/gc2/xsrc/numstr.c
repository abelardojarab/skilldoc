#include "precomp.h"
extern double cos (double __x ) __attribute__ ((__nothrow__ ) ) ; 
extern double sin (double __x ) __attribute__ ((__nothrow__ ) ) ; 
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
enum {
  _ISupper = ((0 ) < 8 ? ((1 << (0 ) ) << 8 ) : ((1 << (0 ) ) >> 8 ) ) , _ISlower = ((1 ) < 8 ? ((1 << (1 ) ) << 8 ) : ((1 << (1 ) ) >> 8 ) ) , _ISalpha = ((2 ) < 8 ? ((1 << (2 ) ) << 8 ) : ((1 << (2 ) ) >> 8 ) ) , _ISdigit = ((3 ) < 8 ? ((1 << (3 ) ) << 8 ) : ((1 << (3 ) ) >> 8 ) ) , _ISxdigit = ((4 ) < 8 ? ((1 << (4 ) ) << 8 ) : ((1 << (4 ) ) >> 8 ) ) , _ISspace = ((5 ) < 8 ? ((1 << (5 ) ) << 8 ) : ((1 << (5 ) ) >> 8 ) ) , _ISprint = ((6 ) < 8 ? ((1 << (6 ) ) << 8 ) : ((1 << (6 ) ) >> 8 ) ) , _ISgraph = ((7 ) < 8 ? ((1 << (7 ) ) << 8 ) : ((1 << (7 ) ) >> 8 ) ) , _ISblank = ((8 ) < 8 ? ((1 << (8 ) ) << 8 ) : ((1 << (8 ) ) >> 8 ) ) , _IScntrl = ((9 ) < 8 ? ((1 << (9 ) ) << 8 ) : ((1 << (9 ) ) >> 8 ) ) , _ISpunct = ((10 ) < 8 ? ((1 << (10 ) ) << 8 ) : ((1 << (10 ) ) >> 8 ) ) , _ISalnum = ((11 ) < 8 ? ((1 << (11 ) ) << 8 ) : ((1 << (11 ) ) >> 8 ) ) }
; 
extern __const unsigned short int * * __ctype_b_loc (void ) __attribute__ ((__const ) ) ; 
static Scheme_Object * number_to_string (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_to_number (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * bytes_to_integer (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * integer_to_bytes (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * bytes_to_real (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * real_to_bytes (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * system_big_endian_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * random_seed (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * sch_random (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * make_pseudo_random_generator (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * current_pseudo_random_generator (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * current_sched_pseudo_random_generator (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * pseudo_random_generator_p (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * sch_unpack (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * sch_pack (int argc , Scheme_Object * argv [] ) ; 
static char * number_to_allocated_string (int radix , Scheme_Object * obj , int alloc ) ; 
static char * infinity_str = "+inf.0" ; 
static char * minus_infinity_str = "-inf.0" ; 
static char * not_a_number_str = "+nan.0" ; 
static char * other_not_a_number_str = "-nan.0" ; 
static Scheme_Object * num_limits [3 ] ; 
void scheme_init_numstr (Scheme_Env * env ) {
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
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(env, 0)));
# define XfOrM1_COUNT (1)
# define SETUP_XfOrM1(x) SETUP(XfOrM1_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  (__funcarg18 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (number_to_string , "number->string" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("number->string" , __funcarg18 , env ) )) ; 
  (__funcarg17 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (string_to_number , "string->number" , 1 , 2 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string->number" , __funcarg17 , env ) )) ; 
  (__funcarg16 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (bytes_to_integer , "integer-bytes->integer" , 2 , 3 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("integer-bytes->integer" , __funcarg16 , env ) )) ; 
  (__funcarg15 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (integer_to_bytes , "integer->integer-bytes" , 3 , 5 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("integer->integer-bytes" , __funcarg15 , env ) )) ; 
  (__funcarg14 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (bytes_to_real , "floating-point-bytes->real" , 1 , 2 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("floating-point-bytes->real" , __funcarg14 , env ) )) ; 
  (__funcarg13 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (real_to_bytes , "real->floating-point-bytes" , 2 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("real->floating-point-bytes" , __funcarg13 , env ) )) ; 
  (__funcarg12 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (system_big_endian_p , "system-big-endian?" , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("system-big-endian?" , __funcarg12 , env ) )) ; 
  (__funcarg11 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (sch_random , "random" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("random" , __funcarg11 , env ) )) ; 
  (__funcarg10 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (random_seed , "random-seed" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("random-seed" , __funcarg10 , env ) )) ; 
  (__funcarg9 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (make_pseudo_random_generator , "make-pseudo-random-generator" , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-pseudo-random-generator" , __funcarg9 , env ) )) ; 
  (__funcarg8 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (sch_pack , "vector->pseudo-random-generator" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("vector->pseudo-random-generator" , __funcarg8 , env ) )) ; 
  (__funcarg7 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (sch_unpack , "pseudo-random-generator->vector" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("pseudo-random-generator->vector" , __funcarg7 , env ) )) ; 
  (__funcarg6 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (pseudo_random_generator_p , "pseudo-random-generator?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("pseudo-random-generator?" , __funcarg6 , env ) )) ; 
  (__funcarg5 = FUNCCALL(SETUP_XfOrM1(_), scheme_register_parameter (current_pseudo_random_generator , "current-pseudo-random-generator" , MZCONFIG_RANDOM_STATE ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-pseudo-random-generator" , __funcarg5 , env ) )) ; 
  (__funcarg4 = FUNCCALL(SETUP_XfOrM1(_), scheme_register_parameter (current_sched_pseudo_random_generator , "current-evt-pseudo-random-generator" , MZCONFIG_SCHEDULER_RANDOM_STATE ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-evt-pseudo-random-generator" , __funcarg4 , env ) )) ; 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & num_limits , sizeof (num_limits ) ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int u_strcmp (mzchar * s , char * t ) {
  /* No conversion */
  int i ; 
  for (i = 0 ; s [i ] && (s [i ] == ((unsigned char * ) t ) [i ] ) ; i ++ ) {
  }
  if (s [i ] || t [i ] )
    return 1 ; 
  return 0 ; 
}
static Scheme_Object * read_special_number (const mzchar * str , int pos ) {
  /* No conversion */
  if ((str [pos ] == '-' || str [pos ] == '+' ) && (((scheme_uchar_table [(str [pos + 1 ] >> 8 ) & 0x1FFF ] [str [pos + 1 ] & 0xFF ] ) ) & 0x80 ) ) {
    mzchar s [7 ] ; 
    int i ; 
    for (i = 0 ; i < 6 ; i ++ ) {
      s [i ] = (str [i + pos ] + scheme_uchar_downs [(scheme_uchar_cases_table [(str [i + pos ] >> 8 ) & 0x1FFF ] [str [i + pos ] & 0xFF ] ) ] ) ; 
    }
    s [i ] = 0 ; 
    if (! u_strcmp (s , infinity_str ) ) {
      return scheme_inf_object ; 
    }
    else if (! u_strcmp (s , minus_infinity_str ) ) {
      return scheme_minus_inf_object ; 
    }
    else if (! u_strcmp (s , not_a_number_str ) || ! u_strcmp (s , other_not_a_number_str ) ) {
      return scheme_nan_object ; 
    }
  }
  return ((void * ) 0 ) ; 
}
static char ffl_buf [50 + 1 ] ; 
static double STRTOD (const char * orig_c , char * * f ) {
  int neg = 0 ; 
  int found_dot = 0 , is_infinity = 0 , is_zero = 0 ; 
  const char * c = orig_c ; 
  DECL_RET_SAVE (double ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(c, 0), PUSH(f, 1), PUSH(orig_c, 2)));
# define XfOrM12_COUNT (3)
# define SETUP_XfOrM12(x) SETUP(XfOrM12_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  * f = (char * ) c ; 
  if (* c == '-' ) {
    c ++ ; 
    neg = 1 ; 
  }
  else if (* c == '+' ) {
    c ++ ; 
  }
  if (! ((* FUNCCALL(SETUP_XfOrM12(_), __ctype_b_loc () )) [(int ) (((unsigned char ) * c ) ) ] & (unsigned short int ) _ISdigit ) ) {
#   define XfOrM39_COUNT (0+XfOrM12_COUNT)
#   define SETUP_XfOrM39(x) SETUP_XfOrM12(x)
    if (* c == '.' ) {
#     define XfOrM40_COUNT (0+XfOrM39_COUNT)
#     define SETUP_XfOrM40(x) SETUP_XfOrM39(x)
      if (! ((* FUNCCALL(SETUP_XfOrM40(_), __ctype_b_loc () )) [(int ) (((unsigned char ) c [1 ] ) ) ] & (unsigned short int ) _ISdigit ) )
        RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    else RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  for (; * c ; c ++ ) {
    int ch = * c ; 
#   define XfOrM27_COUNT (0+XfOrM12_COUNT)
#   define SETUP_XfOrM27(x) SETUP_XfOrM12(x)
    if (((* FUNCCALL(SETUP_XfOrM27(_), __ctype_b_loc () )) [(int ) ((ch ) ) ] & (unsigned short int ) _ISdigit ) ) {
    }
    else if ((ch == 'e' ) || (ch == 'E' ) ) {
      int e = 0 , neg_exp = 0 ; 
      c ++ ; 
#     define XfOrM29_COUNT (0+XfOrM27_COUNT)
#     define SETUP_XfOrM29(x) SETUP_XfOrM27(x)
      if (* c == '-' ) {
        c ++ ; 
        neg_exp = 1 ; 
      }
      else if (* c == '+' ) {
        c ++ ; 
      }
      if (! ((* FUNCCALL(SETUP_XfOrM29(_), __ctype_b_loc () )) [(int ) (((unsigned char ) * c ) ) ] & (unsigned short int ) _ISdigit ) )
        RET_VALUE_START (0 ) RET_VALUE_END ; 
      for (; * c ; c ++ ) {
        int ch = * c ; 
#       define XfOrM33_COUNT (0+XfOrM29_COUNT)
#       define SETUP_XfOrM33(x) SETUP_XfOrM29(x)
        if (! ((* FUNCCALL(SETUP_XfOrM33(_), __ctype_b_loc () )) [(int ) ((ch ) ) ] & (unsigned short int ) _ISdigit ) )
          RET_VALUE_START (0 ) RET_VALUE_END ; 
        else {
          e = (e * 10 ) + (ch - '0' ) ; 
          if (e > 400 ) {
            if (neg_exp )
              is_zero = 1 ; 
            else is_infinity = 1 ; 
          }
        }
      }
      break ; 
    }
    else if (ch == '.' ) {
      if (found_dot )
        RET_VALUE_START (0 ) RET_VALUE_END ; 
      found_dot = 1 ; 
    }
    else RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  * f = (char * ) c ; 
  if (is_infinity ) {
    if (neg )
      RET_VALUE_START (scheme_minus_infinity_val ) RET_VALUE_END ; 
    else RET_VALUE_START (scheme_infinity_val ) RET_VALUE_END ; 
  }
  if (is_zero ) {
    if (neg )
      RET_VALUE_START (scheme_floating_point_nzero ) RET_VALUE_END ; 
    else RET_VALUE_START (scheme_floating_point_zero ) RET_VALUE_END ; 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(strtod (orig_c , ((void * ) 0 ) ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 1251 */
/* this far 1250 */
/* this far 1135 */
/* this far 1104 */
/* this far 1103 */
/* this far 770 */
/* this far 769 */
/* this far 694 */
/* this far 693 */
/* this far 687 */
/* this far 686 */
/* this far 550 */
/* this far 549 */
/* this far 540 */
/* this far 539 */
/* this far 478 */
/* this far 477 */
/* this far 472 */
/* this far 467 */
Scheme_Object * scheme_read_number (const mzchar * str , long len , int is_float , int is_not_float , int decimal_means_float , int radix , int radix_set , Scheme_Object * complain , int * div_by_zero , int test_only , Scheme_Object * stxsrc , long line , long col , long pos , long span , Scheme_Object * indentation ) {
  int i , has_decimal , must_parse , has_slash ; 
  int report , delta ; 
  Scheme_Object * next_complain ; 
  int has_hash , has_expt , has_i , has_sign , has_at , has_hash_since_slash ; 
  int saw_digit , saw_digit_since_slash , saw_nonzero_digit ; 
  Scheme_Object * o ; 
  Scheme_Object * __funcarg20 = NULLED_OUT ; 
  Scheme_Object * __funcarg19 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(16);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(str, 1), PUSH(__funcarg19, 2), PUSH(complain, 3), PUSH(stxsrc, 4), PUSH(next_complain, 5), PUSH(indentation, 6), PUSH(div_by_zero, 7)));
# define XfOrM43_COUNT (8)
# define SETUP_XfOrM43(x) SETUP(XfOrM43_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  next_complain = NULLED_OUT ; 
  o = NULLED_OUT ; 
  if (len < 0 )
    len = FUNCCALL(SETUP_XfOrM43(_), scheme_char_strlen (str ) ); 
  delta = 0 ; 
  while (str [delta ] == '#' ) {
#   define XfOrM191_COUNT (0+XfOrM43_COUNT)
#   define SETUP_XfOrM191(x) SETUP_XfOrM43(x)
    if (str [delta + 1 ] != 'E' && str [delta + 1 ] != 'e' && str [delta + 1 ] != 'I' && str [delta + 1 ] != 'i' ) {
#     define XfOrM195_COUNT (0+XfOrM191_COUNT)
#     define SETUP_XfOrM195(x) SETUP_XfOrM191(x)
      if (radix_set ) {
#       define XfOrM196_COUNT (0+XfOrM195_COUNT)
#       define SETUP_XfOrM196(x) SETUP_XfOrM195(x)
        if (complain )
          FUNCCALL_EMPTY(scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: bad radix specification: %u" , str , len ) ); 
        else RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      }
      radix_set = 1 ; 
    }
    else {
#     define XfOrM193_COUNT (0+XfOrM191_COUNT)
#     define SETUP_XfOrM193(x) SETUP_XfOrM191(x)
      if (is_float || is_not_float ) {
#       define XfOrM194_COUNT (0+XfOrM193_COUNT)
#       define SETUP_XfOrM194(x) SETUP_XfOrM193(x)
        if (complain )
          FUNCCALL_EMPTY(scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: bad exactness specification: %u" , str , len ) ); 
        else RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      }
    }
    switch (str [delta + 1 ] ) {
#     define XfOrM192_COUNT (0+XfOrM191_COUNT)
#     define SETUP_XfOrM192(x) SETUP_XfOrM191(x)
      case 'B' : case 'b' : radix = 2 ; 
      break ; 
      case 'O' : case 'o' : radix = 8 ; 
      break ; 
      case 'D' : case 'd' : radix = 10 ; 
      break ; 
      case 'X' : case 'x' : radix = 16 ; 
      break ; 
      case 'I' : case 'i' : is_float = 1 ; 
      break ; 
      case 'E' : case 'e' : is_not_float = 1 ; 
      break ; 
      default : if (complain )
        FUNCCALL_EMPTY(scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: bad `#' indicator `%c': %u" , str [delta + 1 ] , str , len ) ); 
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    }
    delta += 2 ; 
  }
  must_parse = (radix_set || is_float || is_not_float ) ; 
  report = complain && must_parse ; 
  next_complain = must_parse ? complain : ((void * ) 0 ) ; 
  if (! (len - delta ) ) {
#   define XfOrM184_COUNT (0+XfOrM43_COUNT)
#   define SETUP_XfOrM184(x) SETUP_XfOrM43(x)
    if (report )
      FUNCCALL_EMPTY(scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: no digits" ) ); 
    RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
  }
  if (len - delta == 6 ) {
    Scheme_Object * special ; 
    BLOCK_SETUP((PUSH(special, 0+XfOrM43_COUNT)));
#   define XfOrM182_COUNT (1+XfOrM43_COUNT)
#   define SETUP_XfOrM182(x) SETUP(XfOrM182_COUNT)
    special = NULLED_OUT ; 
    special = FUNCCALL(SETUP_XfOrM182(_), read_special_number (str , delta ) ); 
    if (special ) {
#     define XfOrM183_COUNT (0+XfOrM182_COUNT)
#     define SETUP_XfOrM183(x) SETUP_XfOrM182(x)
      if (! is_not_float )
        RET_VALUE_START (special ) RET_VALUE_END ; 
      if (report )
        FUNCCALL_EMPTY(scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: no exact representation for %V" , special ) ); 
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    }
  }
  if ((len - delta > 7 ) && str [len - 1 ] == 'i' ) {
    Scheme_Object * special ; 
    mzchar * s2 ; 
    BLOCK_SETUP((PUSH(special, 0+XfOrM43_COUNT), PUSH(s2, 1+XfOrM43_COUNT)));
#   define XfOrM175_COUNT (2+XfOrM43_COUNT)
#   define SETUP_XfOrM175(x) SETUP(XfOrM175_COUNT)
    special = NULLED_OUT ; 
    s2 = NULLED_OUT ; 
    special = FUNCCALL(SETUP_XfOrM175(_), read_special_number (str , delta ) ); 
    if (special ) {
#     define XfOrM181_COUNT (0+XfOrM175_COUNT)
#     define SETUP_XfOrM181(x) SETUP_XfOrM175(x)
      s2 = (mzchar * ) FUNCCALL(SETUP_XfOrM181(_), GC_malloc_atomic ((len - delta - 6 + 4 + 1 ) * sizeof (mzchar ) ) ); 
      s2 [0 ] = '+' ; 
      s2 [1 ] = '0' ; 
      s2 [2 ] = '.' ; 
      s2 [3 ] = '0' ; 
      (memcpy (s2 + 4 , str + delta + 6 , (len - delta - 5 ) * sizeof (mzchar ) ) ) ; 
    }
    else {
#     define XfOrM179_COUNT (0+XfOrM175_COUNT)
#     define SETUP_XfOrM179(x) SETUP_XfOrM175(x)
      special = FUNCCALL(SETUP_XfOrM179(_), read_special_number (str , len - 7 ) ); 
      if (special ) {
#       define XfOrM180_COUNT (0+XfOrM179_COUNT)
#       define SETUP_XfOrM180(x) SETUP_XfOrM179(x)
        s2 = (mzchar * ) FUNCCALL(SETUP_XfOrM180(_), GC_malloc_atomic ((len - delta - 6 + 4 + 1 ) * sizeof (mzchar ) ) ); 
        (memcpy (s2 , str + delta , (len - delta - 7 ) * sizeof (mzchar ) ) ) ; 
        s2 [len - delta - 7 ] = '+' ; 
        s2 [len - delta - 7 + 1 ] = '0' ; 
        s2 [len - delta - 7 + 2 ] = '.' ; 
        s2 [len - delta - 7 + 3 ] = '0' ; 
        s2 [len - delta - 7 + 4 ] = 'i' ; 
        s2 [len - delta - 7 + 5 ] = 0 ; 
        special = FUNCCALL(SETUP_XfOrM180(_), scheme_bin_mult (special , scheme_plus_i ) ); 
      }
      else s2 = ((void * ) 0 ) ; 
    }
    if (special ) {
      Scheme_Object * other ; 
      int dbz = 0 ; 
      BLOCK_SETUP((PUSH(other, 0+XfOrM175_COUNT)));
#     define XfOrM176_COUNT (1+XfOrM175_COUNT)
#     define SETUP_XfOrM176(x) SETUP(XfOrM176_COUNT)
      other = NULLED_OUT ; 
      if (is_not_float ) {
#       define XfOrM178_COUNT (0+XfOrM176_COUNT)
#       define SETUP_XfOrM178(x) SETUP_XfOrM176(x)
        if (report )
          FUNCCALL_EMPTY(scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: no exact representation for %V" , special ) ); 
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      }
      other = FUNCCALL(SETUP_XfOrM176(_), scheme_read_number (s2 , len - delta - 6 + 4 , is_float , is_not_float , 1 , radix , 1 , 0 , & dbz , test_only , stxsrc , line , col , pos , span , indentation ) ); 
      if (dbz ) {
#       define XfOrM177_COUNT (0+XfOrM176_COUNT)
#       define SETUP_XfOrM177(x) SETUP_XfOrM176(x)
        if (div_by_zero )
          * div_by_zero = 1 ; 
        if (complain )
          FUNCCALL_EMPTY(scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: division by zero: %u" , str , len ) ); 
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      }
      if (! (((other ) ) == (scheme_false ) ) )
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_bin_plus (special , other ) )) RET_VALUE_EMPTY_END ; 
      if (! complain )
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    }
  }
  if ((len - delta > 7 ) && ((str [delta + 6 ] == '@' ) || (str [len - 7 ] == '@' ) ) ) {
    Scheme_Object * special ; 
    mzchar * s2 ; 
    int spec_mag = 0 ; 
    BLOCK_SETUP((PUSH(special, 0+XfOrM43_COUNT), PUSH(s2, 1+XfOrM43_COUNT)));
#   define XfOrM163_COUNT (2+XfOrM43_COUNT)
#   define SETUP_XfOrM163(x) SETUP(XfOrM163_COUNT)
    special = NULLED_OUT ; 
    s2 = NULLED_OUT ; 
    if (str [delta + 6 ] == '@' )
      special = FUNCCALL(SETUP_XfOrM163(_), read_special_number (str , delta ) ); 
    else special = ((void * ) 0 ) ; 
    if (special ) {
#     define XfOrM174_COUNT (0+XfOrM163_COUNT)
#     define SETUP_XfOrM174(x) SETUP_XfOrM163(x)
      s2 = (mzchar * ) FUNCCALL(SETUP_XfOrM174(_), GC_malloc_atomic ((len - delta - 6 ) * sizeof (mzchar ) ) ); 
      (memcpy (s2 , str + delta + 7 , (len - delta - 6 ) * sizeof (mzchar ) ) ) ; 
      spec_mag = 1 ; 
    }
    else {
#     define XfOrM172_COUNT (0+XfOrM163_COUNT)
#     define SETUP_XfOrM172(x) SETUP_XfOrM163(x)
      if (str [len - 7 ] == '@' )
        special = FUNCCALL(SETUP_XfOrM172(_), read_special_number (str , len - 6 ) ); 
      else special = ((void * ) 0 ) ; 
      if (special ) {
#       define XfOrM173_COUNT (0+XfOrM172_COUNT)
#       define SETUP_XfOrM173(x) SETUP_XfOrM172(x)
        s2 = (mzchar * ) FUNCCALL(SETUP_XfOrM173(_), GC_malloc_atomic ((len - delta - 6 ) * sizeof (mzchar ) ) ); 
        (memcpy (s2 , str + delta , (len - delta - 7 ) * sizeof (mzchar ) ) ) ; 
        s2 [len - delta - 7 ] = 0 ; 
      }
      else s2 = ((void * ) 0 ) ; 
    }
    if (special ) {
      Scheme_Object * other ; 
      int dbz = 0 ; 
      BLOCK_SETUP((PUSH(other, 0+XfOrM163_COUNT)));
#     define XfOrM164_COUNT (1+XfOrM163_COUNT)
#     define SETUP_XfOrM164(x) SETUP(XfOrM164_COUNT)
      other = NULLED_OUT ; 
      for (i = 0 ; s2 [i ] ; i ++ ) {
        if (s2 [i ] == '@' )
          break ; 
      }
      if (s2 [i ] )
        other = scheme_false ; 
      else other = FUNCCALL(SETUP_XfOrM164(_), scheme_read_number (s2 , len - delta - 7 , is_float , is_not_float , 1 , radix , 1 , 0 , & dbz , test_only , stxsrc , line , col , pos , span , indentation ) ); 
      if (dbz ) {
#       define XfOrM169_COUNT (0+XfOrM164_COUNT)
#       define SETUP_XfOrM169(x) SETUP_XfOrM164(x)
        if (div_by_zero )
          * div_by_zero = 1 ; 
        if (complain )
          FUNCCALL_EMPTY(scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: division by zero: %u" , str , len ) ); 
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      }
      if (! (((other ) ) == (scheme_false ) ) ) {
#       define XfOrM165_COUNT (0+XfOrM164_COUNT)
#       define SETUP_XfOrM165(x) SETUP_XfOrM164(x)
        if (! (! (((long ) (other ) ) & 0x1 ) && ((((other ) -> type ) >= scheme_complex_izi_type ) && (((other ) -> type ) <= scheme_complex_type ) ) ) ) {
          Scheme_Object * a [2 ] ; 
          BLOCK_SETUP((PUSHARRAY(a, 2, 0+XfOrM165_COUNT)));
#         define XfOrM166_COUNT (3+XfOrM165_COUNT)
#         define SETUP_XfOrM166(x) SETUP(XfOrM166_COUNT)
          a[0] = NULLED_OUT ; 
          a[1] = NULLED_OUT ; 
          if (spec_mag ) {
            a [0 ] = special ; 
            a [1 ] = other ; 
          }
          else {
            a [0 ] = other ; 
            a [1 ] = special ; 
          }
          RET_VALUE_START (FUNCCALL(SETUP_XfOrM166(_), scheme_make_polar (2 , a ) )) RET_VALUE_END ; 
        }
      }
      if (! complain )
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    }
  }
  has_i = 0 ; 
  has_at = 0 ; 
  has_sign = delta - 1 ; 
  for (i = delta ; i < len ; i ++ ) {
    mzchar ch = str [i ] ; 
#   define XfOrM152_COUNT (0+XfOrM43_COUNT)
#   define SETUP_XfOrM152(x) SETUP_XfOrM43(x)
    if (! ch ) {
#     define XfOrM162_COUNT (0+XfOrM152_COUNT)
#     define SETUP_XfOrM162(x) SETUP_XfOrM152(x)
      if (report )
        FUNCCALL_EMPTY(scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: embedded null character: %u" , str , len ) ); 
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    }
    else if (((ch == 'e' ) || (ch == 'E' ) || (ch == 's' ) || (ch == 'S' ) || (ch == 'f' ) || (ch == 'F' ) || (ch == 'd' ) || (ch == 'D' ) || (ch == 'l' ) || (ch == 'L' ) ) && ((radix <= 10 ) || ! (((ch >= 'a' ) && (ch <= (mzchar ) ('a' + radix - 11 ) ) ) || ((ch >= 'A' ) && (ch <= (mzchar ) ('A' + radix - 11 ) ) ) ) ) ) {
      if (str [i + 1 ] == '+' || str [i + 1 ] == '-' )
        i ++ ; 
    }
    else if ((ch == '+' ) || (ch == '-' ) ) {
#     define XfOrM159_COUNT (0+XfOrM152_COUNT)
#     define SETUP_XfOrM159(x) SETUP_XfOrM152(x)
      if ((has_sign > delta ) || ((has_sign == delta ) && (i == delta + 1 ) ) ) {
#       define XfOrM160_COUNT (0+XfOrM159_COUNT)
#       define SETUP_XfOrM160(x) SETUP_XfOrM159(x)
        if (report )
          FUNCCALL_EMPTY(scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: too many signs: %u" , str , len ) ); 
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      }
      has_sign = i ; 
    }
    else if (((ch == 'I' ) || (ch == 'i' ) ) && (has_sign >= delta ) ) {
#     define XfOrM156_COUNT (0+XfOrM152_COUNT)
#     define SETUP_XfOrM156(x) SETUP_XfOrM152(x)
      if (has_at ) {
#       define XfOrM158_COUNT (0+XfOrM156_COUNT)
#       define SETUP_XfOrM158(x) SETUP_XfOrM156(x)
        if (report )
          FUNCCALL_EMPTY(scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: cannot mix `@' and `i': %u" , str , len ) ); 
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      }
      if (i + 1 < len ) {
#       define XfOrM157_COUNT (0+XfOrM156_COUNT)
#       define SETUP_XfOrM157(x) SETUP_XfOrM156(x)
        if (report )
          FUNCCALL_EMPTY(scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: `i' must be at the end: %u" , str , len ) ); 
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      }
      has_i = i ; 
    }
    else if (ch == '@' ) {
#     define XfOrM153_COUNT (0+XfOrM152_COUNT)
#     define SETUP_XfOrM153(x) SETUP_XfOrM152(x)
      if (has_at ) {
#       define XfOrM155_COUNT (0+XfOrM153_COUNT)
#       define SETUP_XfOrM155(x) SETUP_XfOrM153(x)
        if (report )
          FUNCCALL_EMPTY(scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: too many `@'s: %u" , str , len ) ); 
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      }
      if (i == delta ) {
#       define XfOrM154_COUNT (0+XfOrM153_COUNT)
#       define SETUP_XfOrM154(x) SETUP_XfOrM153(x)
        if (report )
          FUNCCALL_EMPTY(scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: `@' cannot be at start: %u" , str , len ) ); 
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      }
      has_at = i ; 
      if (has_sign >= delta )
        has_sign = delta - 1 ; 
    }
  }
  if (has_i ) {
    Scheme_Object * n1 , * n2 ; 
    mzchar * first , * second ; 
    int fdbz = 0 , sdbz = 0 ; 
    BLOCK_SETUP((PUSH(n1, 0+XfOrM43_COUNT), PUSH(first, 1+XfOrM43_COUNT), PUSH(n2, 2+XfOrM43_COUNT), PUSH(second, 3+XfOrM43_COUNT)));
#   define XfOrM135_COUNT (4+XfOrM43_COUNT)
#   define SETUP_XfOrM135(x) SETUP(XfOrM135_COUNT)
    n1 = NULLED_OUT ; 
    n2 = NULLED_OUT ; 
    first = NULLED_OUT ; 
    second = NULLED_OUT ; 
    if (has_sign != delta ) {
#     define XfOrM140_COUNT (0+XfOrM135_COUNT)
#     define SETUP_XfOrM140(x) SETUP_XfOrM135(x)
      first = (mzchar * ) FUNCCALL(SETUP_XfOrM140(_), GC_malloc_atomic ((has_sign - delta + 1 ) * sizeof (mzchar ) ) ); 
      (memcpy (first , str + delta , (has_sign - delta ) * sizeof (mzchar ) ) ) ; 
      first [has_sign - delta ] = 0 ; 
    }
    else first = ((void * ) 0 ) ; 
    if (has_i - has_sign > 1 ) {
#     define XfOrM139_COUNT (0+XfOrM135_COUNT)
#     define SETUP_XfOrM139(x) SETUP_XfOrM135(x)
      second = (mzchar * ) FUNCCALL(SETUP_XfOrM139(_), GC_malloc_atomic ((has_i - has_sign + 1 ) * sizeof (mzchar ) ) ); 
      (memcpy (second , str + has_sign , (has_i - has_sign ) * sizeof (mzchar ) ) ) ; 
      second [has_i - has_sign ] = 0 ; 
    }
    else second = ((void * ) 0 ) ; 
    if (first )
      n1 = FUNCCALL(SETUP_XfOrM135(_), scheme_read_number (first , has_sign - delta , is_float , is_not_float , decimal_means_float , radix , 1 , next_complain , & fdbz , test_only , stxsrc , line , col , pos , span , indentation ) ); 
    else n1 = ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
    if (((n1 ) == (scheme_false ) ) && ! fdbz )
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    else if (((Scheme_Type ) (((((long ) (n1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n1 ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ) {
      double d = (((Scheme_Double * ) (n1 ) ) -> double_val ) ; 
      if (isnan (d ) )
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    }
    if (second )
      n2 = FUNCCALL(SETUP_XfOrM135(_), scheme_read_number (second , has_i - has_sign , is_float , is_not_float , decimal_means_float , radix , 1 , next_complain , & sdbz , test_only , stxsrc , line , col , pos , span , indentation ) ); 
    else if (str [has_sign ] == '-' )
      n2 = ((Scheme_Object * ) (void * ) (long ) ((((long ) (- 1 ) ) << 1 ) | 0x1 ) ) ; 
    else n2 = ((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) ; 
    if (((n2 ) == (scheme_false ) ) && ! sdbz )
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    else if (((Scheme_Type ) (((((long ) (n2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n2 ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ) {
      double d = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
      if (isnan (d ) )
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    }
    if (fdbz || sdbz ) {
#     define XfOrM136_COUNT (0+XfOrM135_COUNT)
#     define SETUP_XfOrM136(x) SETUP_XfOrM135(x)
      if (div_by_zero )
        * div_by_zero = 1 ; 
      if (complain )
        FUNCCALL(SETUP_XfOrM136(_), scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: division by zero: %u" , str , len ) ); 
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    }
    if (! is_not_float && ((((Scheme_Type ) (((((long ) (n1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n1 ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) && (n2 != ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) ) || is_float ) )
      n2 = FUNCCALL(SETUP_XfOrM135(_), scheme_exact_to_inexact (1 , & n2 ) ); 
    else if (is_not_float )
      n2 = FUNCCALL(SETUP_XfOrM135(_), scheme_inexact_to_exact (1 , & n2 ) ); 
    if (! is_not_float && ((((Scheme_Type ) (((((long ) (n2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n2 ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) && (n1 != ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) ) || is_float ) )
      n1 = FUNCCALL(SETUP_XfOrM135(_), scheme_exact_to_inexact (1 , & n1 ) ); 
    else if (is_not_float )
      n1 = FUNCCALL(SETUP_XfOrM135(_), scheme_inexact_to_exact (1 , & n1 ) ); 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM135(_), scheme_make_complex (n1 , n2 ) )) RET_VALUE_END ; 
  }
  if (has_at ) {
    Scheme_Object * n1 , * n2 ; 
    double d1 , d2 , r1 , r2 ; 
    mzchar * first ; 
    const mzchar * second ; 
    int fdbz = 0 , sdbz = 0 ; 
    BLOCK_SETUP((PUSH(n1, 0+XfOrM43_COUNT), PUSH(first, 1+XfOrM43_COUNT), PUSH(n2, 2+XfOrM43_COUNT), PUSH(second, 3+XfOrM43_COUNT)));
#   define XfOrM130_COUNT (4+XfOrM43_COUNT)
#   define SETUP_XfOrM130(x) SETUP(XfOrM130_COUNT)
    n1 = NULLED_OUT ; 
    n2 = NULLED_OUT ; 
    first = NULLED_OUT ; 
    second = NULLED_OUT ; 
    first = (mzchar * ) FUNCCALL(SETUP_XfOrM130(_), GC_malloc_atomic ((has_at - delta + 1 ) * sizeof (mzchar ) ) ); 
    (memcpy (first , str + delta , (has_at - delta ) * sizeof (mzchar ) ) ) ; 
    first [has_at - delta ] = 0 ; 
    {
      int slen = len - (has_at + 1 ) + 1 ; 
#     define XfOrM134_COUNT (0+XfOrM130_COUNT)
#     define SETUP_XfOrM134(x) SETUP_XfOrM130(x)
      second = (mzchar * ) FUNCCALL(SETUP_XfOrM134(_), GC_malloc_atomic (slen * sizeof (mzchar ) ) ); 
      (memcpy ((mzchar * ) second , str + has_at + 1 , slen * sizeof (mzchar ) ) ) ; 
    }
    n2 = FUNCCALL(SETUP_XfOrM130(_), scheme_read_number (second , len - has_at - 1 , is_float , is_not_float , decimal_means_float , radix , 1 , next_complain , & fdbz , test_only , stxsrc , line , col , pos , span , indentation ) ); 
    if (! fdbz ) {
#     define XfOrM133_COUNT (0+XfOrM130_COUNT)
#     define SETUP_XfOrM133(x) SETUP_XfOrM130(x)
      if ((((n2 ) ) == (scheme_false ) ) )
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      if (n2 == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) )
        RET_VALUE_START (FUNCCALL(SETUP_XfOrM133(_), scheme_read_number (first , has_at - delta , is_float , is_not_float , decimal_means_float , radix , 1 , complain , div_by_zero , test_only , stxsrc , line , col , pos , span , indentation ) )) RET_VALUE_END ; 
      n2 = FUNCCALL(SETUP_XfOrM133(_), scheme_exact_to_inexact (1 , & n2 ) ); 
      d2 = (((Scheme_Double * ) (n2 ) ) -> double_val ) ; 
      if (isnan (d2 ) )
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      n1 = FUNCCALL(SETUP_XfOrM133(_), scheme_read_number (first , has_at - delta , is_float , is_not_float , decimal_means_float , radix , 1 , next_complain , & sdbz , test_only , stxsrc , line , col , pos , span , indentation ) ); 
      if (n1 == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) )
        RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
      if (! (((n1 ) ) == (scheme_false ) ) )
        n1 = FUNCCALL(SETUP_XfOrM133(_), scheme_exact_to_inexact (1 , & n1 ) ); 
    }
    else {
      n1 = ((void * ) 0 ) ; 
      d2 = 0 ; 
    }
    if (fdbz || sdbz ) {
#     define XfOrM131_COUNT (0+XfOrM130_COUNT)
#     define SETUP_XfOrM131(x) SETUP_XfOrM130(x)
      if (div_by_zero )
        * div_by_zero = 1 ; 
      if (complain )
        FUNCCALL(SETUP_XfOrM131(_), scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: division by zero in %u" , str , len ) ); 
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    }
    if ((((n1 ) ) == (scheme_false ) ) )
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    d1 = (((Scheme_Double * ) (n1 ) ) -> double_val ) ; 
    if (isnan (d1 ) )
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    r1 = d1 * cos (d2 ) ; 
    r2 = d1 * sin (d2 ) ; 
    RET_VALUE_START ((__funcarg19 = FUNCCALL(SETUP_XfOrM130(_), scheme_make_double (r1 ) ), __funcarg20 = FUNCCALL(SETUP_XfOrM130(_), scheme_make_double (r2 ) ), FUNCCALL_AGAIN(scheme_make_complex (__funcarg19 , __funcarg20 ) )) ) RET_VALUE_END ; 
  }
  has_decimal = has_slash = has_hash = has_hash_since_slash = has_expt = 0 ; 
  saw_digit = saw_digit_since_slash = saw_nonzero_digit = 0 ; 
  for (i = delta ; i < len ; i ++ ) {
    mzchar ch = str [i ] ; 
#   define XfOrM111_COUNT (0+XfOrM43_COUNT)
#   define SETUP_XfOrM111(x) SETUP_XfOrM43(x)
    if (ch == '.' ) {
#     define XfOrM127_COUNT (0+XfOrM111_COUNT)
#     define SETUP_XfOrM127(x) SETUP_XfOrM111(x)
      if (has_decimal ) {
#       define XfOrM129_COUNT (0+XfOrM127_COUNT)
#       define SETUP_XfOrM129(x) SETUP_XfOrM127(x)
        if (report )
          FUNCCALL_EMPTY(scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: multiple decimal points: %u" , str , len ) ); 
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      }
      if (has_slash ) {
#       define XfOrM128_COUNT (0+XfOrM127_COUNT)
#       define SETUP_XfOrM128(x) SETUP_XfOrM127(x)
        if (report )
          FUNCCALL_EMPTY(scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: decimal points and fractions " "cannot be mixed: %u" , str , len ) ); 
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      }
      has_decimal = 1 ; 
    }
    else if (((ch == 'e' ) || (ch == 'E' ) || (ch == 's' ) || (ch == 'S' ) || (ch == 'f' ) || (ch == 'F' ) || (ch == 'd' ) || (ch == 'D' ) || (ch == 'l' ) || (ch == 'L' ) ) && ((radix <= 10 ) || ! (((ch >= 'a' ) && (ch <= (mzchar ) ('a' + radix - 11 ) ) ) || ((ch >= 'A' ) && (ch <= (mzchar ) ('A' + radix - 11 ) ) ) ) ) ) {
#     define XfOrM125_COUNT (0+XfOrM111_COUNT)
#     define SETUP_XfOrM125(x) SETUP_XfOrM111(x)
      if (i == delta ) {
#       define XfOrM126_COUNT (0+XfOrM125_COUNT)
#       define SETUP_XfOrM126(x) SETUP_XfOrM125(x)
        if (report )
          FUNCCALL_EMPTY(scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: cannot begin with `%c' in %u" , ch , str , len ) ); 
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      }
      has_expt = i ; 
      break ; 
    }
    else if (ch == '/' ) {
#     define XfOrM121_COUNT (0+XfOrM111_COUNT)
#     define SETUP_XfOrM121(x) SETUP_XfOrM111(x)
      if (i == delta ) {
#       define XfOrM124_COUNT (0+XfOrM121_COUNT)
#       define SETUP_XfOrM124(x) SETUP_XfOrM121(x)
        if (report )
          FUNCCALL_EMPTY(scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: cannot have slash at start: %u" , str , len ) ); 
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      }
      if (has_slash ) {
#       define XfOrM123_COUNT (0+XfOrM121_COUNT)
#       define SETUP_XfOrM123(x) SETUP_XfOrM121(x)
        if (report )
          FUNCCALL_EMPTY(scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: multiple slashes: %u" , str , len ) ); 
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      }
      if (has_decimal ) {
#       define XfOrM122_COUNT (0+XfOrM121_COUNT)
#       define SETUP_XfOrM122(x) SETUP_XfOrM121(x)
        if (report )
          FUNCCALL_EMPTY(scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: decimal points and fractions " "cannot be mixed: %u" , str , len ) ); 
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      }
      has_slash = i ; 
      saw_digit_since_slash = 0 ; 
      has_hash_since_slash = 0 ; 
    }
    else if ((ch == '-' ) || (ch == '+' ) ) {
#     define XfOrM119_COUNT (0+XfOrM111_COUNT)
#     define SETUP_XfOrM119(x) SETUP_XfOrM111(x)
      if (has_slash || has_decimal || has_hash ) {
#       define XfOrM120_COUNT (0+XfOrM119_COUNT)
#       define SETUP_XfOrM120(x) SETUP_XfOrM119(x)
        if (report )
          FUNCCALL_EMPTY(scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: misplaced sign: %u" , str , len ) ); 
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      }
    }
    else if (ch == '#' ) {
#     define XfOrM117_COUNT (0+XfOrM111_COUNT)
#     define SETUP_XfOrM117(x) SETUP_XfOrM111(x)
      if (! saw_digit_since_slash ) {
#       define XfOrM118_COUNT (0+XfOrM117_COUNT)
#       define SETUP_XfOrM118(x) SETUP_XfOrM117(x)
        if (report )
          FUNCCALL_EMPTY(scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: misplaced hash: %u" , str , len ) ); 
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      }
      has_hash = 1 ; 
      has_hash_since_slash = 1 ; 
    }
    else if (! ((ch >= '0' ) && (ch <= '9' ) ) && ! ((radix > 10 ) && (((ch >= 'a' ) && (ch <= (mzchar ) ('a' + radix - 11 ) ) ) || ((ch >= 'A' ) && (ch <= (mzchar ) ('A' + radix - 11 ) ) ) ) ) ) {
#     define XfOrM114_COUNT (0+XfOrM111_COUNT)
#     define SETUP_XfOrM114(x) SETUP_XfOrM111(x)
      if (has_decimal ) {
#       define XfOrM116_COUNT (0+XfOrM114_COUNT)
#       define SETUP_XfOrM116(x) SETUP_XfOrM114(x)
        if (report )
          FUNCCALL_EMPTY(scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: bad decimal number: %u" , str , len ) ); 
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      }
      if (has_hash ) {
#       define XfOrM115_COUNT (0+XfOrM114_COUNT)
#       define SETUP_XfOrM115(x) SETUP_XfOrM114(x)
        if (report )
          FUNCCALL_EMPTY(scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: misplaced hash: %u" , str , len ) ); 
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      }
      break ; 
    }
    else {
#     define XfOrM112_COUNT (0+XfOrM111_COUNT)
#     define SETUP_XfOrM112(x) SETUP_XfOrM111(x)
      saw_digit = 1 ; 
      saw_digit_since_slash = 1 ; 
      if (ch != '0' )
        saw_nonzero_digit = 1 ; 
      if (has_hash_since_slash ) {
#       define XfOrM113_COUNT (0+XfOrM112_COUNT)
#       define SETUP_XfOrM113(x) SETUP_XfOrM112(x)
        if (report )
          FUNCCALL_EMPTY(scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: misplaced hash: %u" , str , len ) ); 
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      }
    }
  }
  if (! is_not_float && (is_float || decimal_means_float ) && ! has_slash && ! has_hash && (radix == 10 ) && (has_decimal || has_expt ) && (len <= 50 ) ) {
    double d ; 
    GC_CAN_IGNORE char * ptr ; 
#   define XfOrM81_COUNT (0+XfOrM43_COUNT)
#   define SETUP_XfOrM81(x) SETUP_XfOrM43(x)
    if (has_expt && ! (str [has_expt + 1 ] ) ) {
#     define XfOrM91_COUNT (0+XfOrM81_COUNT)
#     define SETUP_XfOrM91(x) SETUP_XfOrM81(x)
      if (report )
        FUNCCALL_EMPTY(scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: no digits after \"%c\": %u" , str [has_expt ] , str , len ) ); 
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    }
    {
      int k ; 
      for (k = delta ; k < len ; k ++ ) {
        if (str [k ] > 127 )
          ffl_buf [k - delta ] = '?' ; 
        else ffl_buf [k - delta ] = str [k ] ; 
      }
      ffl_buf [len - delta ] = 0 ; 
    }
    if (has_expt && (str [has_expt ] != 'e' && str [has_expt ] != 'E' ) ) {
      ffl_buf [has_expt - delta ] = 'e' ; 
    }
    d = FUNCCALL(SETUP_XfOrM81(_), STRTOD (ffl_buf , & ptr ) ); 
    if ((ptr XFORM_OK_MINUS ffl_buf ) < (len - delta ) ) {
#     define XfOrM86_COUNT (0+XfOrM81_COUNT)
#     define SETUP_XfOrM86(x) SETUP_XfOrM81(x)
      if (report )
        FUNCCALL_EMPTY(scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: bad decimal number %u" , str , len ) ); 
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    }
    if (! saw_nonzero_digit ) {
      if (str [delta ] == '-' ) {
        RET_VALUE_START (scheme_nzerod ) RET_VALUE_END ; 
      }
    }
    if (! d ) {
      if (str [delta ] == '-' ) {
        RET_VALUE_START (scheme_nzerod ) RET_VALUE_END ; 
      }
    }
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_double (d ) )) RET_VALUE_EMPTY_END ; 
  }
  if (has_decimal || has_expt || (has_hash && ! has_slash ) ) {
    Scheme_Object * mantissa , * exponent , * power , * n ; 
    Scheme_Object * args [2 ] ; 
    int result_is_float = (is_float || (! is_not_float && decimal_means_float ) ) ; 
    BLOCK_SETUP((PUSHARRAY(args, 2, 0+XfOrM43_COUNT), PUSH(n, 3+XfOrM43_COUNT), PUSH(exponent, 4+XfOrM43_COUNT), PUSH(power, 5+XfOrM43_COUNT), PUSH(mantissa, 6+XfOrM43_COUNT)));
#   define XfOrM54_COUNT (7+XfOrM43_COUNT)
#   define SETUP_XfOrM54(x) SETUP(XfOrM54_COUNT)
    mantissa = NULLED_OUT ; 
    exponent = NULLED_OUT ; 
    power = NULLED_OUT ; 
    n = NULLED_OUT ; 
    args[0] = NULLED_OUT ; 
    args[1] = NULLED_OUT ; 
    if (has_expt ) {
      mzchar * substr ; 
      BLOCK_SETUP((PUSH(substr, 0+XfOrM54_COUNT)));
#     define XfOrM77_COUNT (1+XfOrM54_COUNT)
#     define SETUP_XfOrM77(x) SETUP(XfOrM77_COUNT)
      substr = NULLED_OUT ; 
      if (! str [has_expt + 1 ] ) {
#       define XfOrM80_COUNT (0+XfOrM77_COUNT)
#       define SETUP_XfOrM80(x) SETUP_XfOrM77(x)
        if (report )
          FUNCCALL(SETUP_XfOrM80(_), scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: no digits after \"%c\": %u" , str [has_expt ] , str , len ) ); 
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      }
      {
        int slen = len - (has_expt + 1 ) + 1 ; 
#       define XfOrM79_COUNT (0+XfOrM77_COUNT)
#       define SETUP_XfOrM79(x) SETUP_XfOrM77(x)
        substr = (mzchar * ) FUNCCALL(SETUP_XfOrM79(_), GC_malloc_atomic (slen * sizeof (mzchar ) ) ); 
        (memcpy (substr , str + has_expt + 1 , slen * sizeof (mzchar ) ) ) ; 
      }
      exponent = FUNCCALL(SETUP_XfOrM77(_), scheme_read_bignum (substr , 0 , radix ) ); 
      if ((((exponent ) ) == (scheme_false ) ) ) {
#       define XfOrM78_COUNT (0+XfOrM77_COUNT)
#       define SETUP_XfOrM78(x) SETUP_XfOrM77(x)
        if (report )
          FUNCCALL(SETUP_XfOrM78(_), scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: bad exponent: %u" , str , len ) ); 
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      }
    }
    else exponent = ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
    if (! has_expt )
      has_expt = len ; 
    if (has_slash ) {
      mzchar * s ; 
      int dbz ; 
      BLOCK_SETUP((PUSH(s, 0+XfOrM54_COUNT)));
#     define XfOrM74_COUNT (1+XfOrM54_COUNT)
#     define SETUP_XfOrM74(x) SETUP(XfOrM74_COUNT)
      s = NULLED_OUT ; 
      s = (mzchar * ) FUNCCALL(SETUP_XfOrM74(_), GC_malloc_atomic ((has_expt - delta + 1 ) * sizeof (mzchar ) ) ); 
      (memcpy (s , str + delta , (has_expt - delta ) * sizeof (mzchar ) ) ) ; 
      s [has_expt - delta ] = 0 ; 
      mantissa = FUNCCALL(SETUP_XfOrM74(_), scheme_read_number (s , has_expt - delta , is_float , is_not_float , 1 , radix , 1 , next_complain , & dbz , test_only , stxsrc , line , col , pos , span , indentation ) ); 
      if ((((mantissa ) ) == (scheme_false ) ) ) {
#       define XfOrM75_COUNT (0+XfOrM74_COUNT)
#       define SETUP_XfOrM75(x) SETUP_XfOrM74(x)
        if (dbz ) {
#         define XfOrM76_COUNT (0+XfOrM75_COUNT)
#         define SETUP_XfOrM76(x) SETUP_XfOrM75(x)
          if (div_by_zero )
            * div_by_zero = 1 ; 
          if (complain )
            FUNCCALL(SETUP_XfOrM76(_), scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: division by zero: %u" , str , len ) ); 
        }
        if (report )
          FUNCCALL(SETUP_XfOrM75(_), scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: bad number: %u" , str , len ) ); 
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      }
    }
    else {
      mzchar * digits ; 
      int extra_power = 0 , dcp = 0 , num_ok ; 
      BLOCK_SETUP((PUSH(digits, 0+XfOrM54_COUNT)));
#     define XfOrM57_COUNT (1+XfOrM54_COUNT)
#     define SETUP_XfOrM57(x) SETUP(XfOrM57_COUNT)
      digits = NULLED_OUT ; 
      digits = (mzchar * ) FUNCCALL(SETUP_XfOrM57(_), GC_malloc_atomic ((has_expt - delta + 1 ) * sizeof (mzchar ) ) ); 
      i = delta ; 
      if (str [i ] == '+' || str [i ] == '-' )
        digits [dcp ++ ] = str [i ++ ] ; 
      for (; ((str [i ] >= '0' ) && (str [i ] <= '9' ) ) || ((radix > 10 ) && (((str [i ] >= 'a' ) && (str [i ] <= (mzchar ) ('a' + radix - 11 ) ) ) || ((str [i ] >= 'A' ) && (str [i ] <= (mzchar ) ('A' + radix - 11 ) ) ) ) ) ; i ++ ) {
        digits [dcp ++ ] = str [i ] ; 
      }
      if (str [i ] == '#' ) {
        for (; str [i ] == '#' ; i ++ ) {
          digits [dcp ++ ] = '0' ; 
        }
        num_ok = 0 ; 
      }
      else num_ok = 1 ; 
      if (str [i ] == '.' ) {
        i ++ ; 
        if (num_ok )
          for (; ((str [i ] >= '0' ) && (str [i ] <= '9' ) ) || ((radix > 10 ) && (((str [i ] >= 'a' ) && (str [i ] <= (mzchar ) ('a' + radix - 11 ) ) ) || ((str [i ] >= 'A' ) && (str [i ] <= (mzchar ) ('A' + radix - 11 ) ) ) ) ) ; i ++ ) {
          digits [dcp ++ ] = str [i ] ; 
          extra_power ++ ; 
        }
        for (; str [i ] == '#' ; i ++ ) {
          digits [dcp ++ ] = '0' ; 
          extra_power ++ ; 
        }
      }
      if ((str [i ] && (! has_expt || i != has_expt ) ) || ! dcp || (dcp == 1 && ! (((digits [0 ] >= '0' ) && (digits [0 ] <= '9' ) ) || ((radix > 10 ) && (((digits [0 ] >= 'a' ) && (digits [0 ] <= (mzchar ) ('a' + radix - 11 ) ) ) || ((digits [0 ] >= 'A' ) && (digits [0 ] <= (mzchar ) ('A' + radix - 11 ) ) ) ) ) ) ) ) {
#       define XfOrM63_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM63(x) SETUP_XfOrM57(x)
        if (report )
          FUNCCALL(SETUP_XfOrM63(_), scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: bad decimal number %u" , str , len ) ); 
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      }
      if (result_is_float && (dcp > 50 ) ) {
        extra_power -= (dcp - 50 ) ; 
        dcp = 50 ; 
      }
      digits [dcp ] = 0 ; 
      mantissa = FUNCCALL(SETUP_XfOrM57(_), scheme_read_bignum (digits , 0 , radix ) ); 
      if ((((mantissa ) ) == (scheme_false ) ) ) {
#       define XfOrM61_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM61(x) SETUP_XfOrM57(x)
        if (report )
          FUNCCALL(SETUP_XfOrM61(_), scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: bad number: %u" , str , len ) ); 
        RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
      }
      if (extra_power )
        exponent = FUNCCALL(SETUP_XfOrM57(_), scheme_bin_minus (exponent , ((Scheme_Object * ) (void * ) (long ) ((((long ) (extra_power ) ) << 1 ) | 0x1 ) ) ) ); 
      if (result_is_float ) {
#       define XfOrM58_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM58(x) SETUP_XfOrM57(x)
        if (FUNCCALL(SETUP_XfOrM58(_), scheme_bin_gt (exponent , ((Scheme_Object * ) (void * ) (long ) ((((long ) (400 ) ) << 1 ) | 0x1 ) ) ) )) {
#         define XfOrM60_COUNT (0+XfOrM58_COUNT)
#         define SETUP_XfOrM60(x) SETUP_XfOrM58(x)
          if ((scheme_is_negative (mantissa ) ) )
            RET_VALUE_START (scheme_minus_inf_object ) RET_VALUE_END ; 
          else RET_VALUE_START (scheme_inf_object ) RET_VALUE_END ; 
        }
        else if (FUNCCALL(SETUP_XfOrM58(_), scheme_bin_lt (exponent , ((Scheme_Object * ) (void * ) (long ) ((((long ) (- 400 ) ) << 1 ) | 0x1 ) ) ) )) {
#         define XfOrM59_COUNT (0+XfOrM58_COUNT)
#         define SETUP_XfOrM59(x) SETUP_XfOrM58(x)
          if ((scheme_is_negative (mantissa ) ) )
            RET_VALUE_START (scheme_nzerod ) RET_VALUE_END ; 
          else RET_VALUE_START (scheme_zerod ) RET_VALUE_END ; 
        }
      }
    }
    if (test_only )
      RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
    args [0 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (radix ) ) << 1 ) | 0x1 ) ) ; 
    args [1 ] = exponent ; 
    power = FUNCCALL(SETUP_XfOrM54(_), scheme_expt (2 , args ) ); 
    n = FUNCCALL_AGAIN(scheme_bin_mult (mantissa , power ) ); 
    if (result_is_float )
      n = FUNCCALL(SETUP_XfOrM54(_), scheme_TO_DOUBLE (n ) ); 
    else n = n ; 
    if (((Scheme_Type ) (((((long ) (n ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) && str [delta ] == '-' ) {
#     define XfOrM55_COUNT (0+XfOrM54_COUNT)
#     define SETUP_XfOrM55(x) SETUP_XfOrM54(x)
      if ((((Scheme_Double * ) (n ) ) -> double_val ) == 0.0 ) {
#       define XfOrM56_COUNT (0+XfOrM55_COUNT)
#       define SETUP_XfOrM56(x) SETUP_XfOrM55(x)
        n = FUNCCALL(SETUP_XfOrM56(_), scheme_make_double (- (((Scheme_Double * ) (n ) ) -> double_val ) ) ); 
      }
    }
    RET_VALUE_START (n ) RET_VALUE_END ; 
  }
  if (has_slash ) {
    Scheme_Object * n1 , * n2 ; 
    mzchar * first ; 
    BLOCK_SETUP((PUSH(n1, 0+XfOrM43_COUNT), PUSH(first, 1+XfOrM43_COUNT), PUSH(n2, 2+XfOrM43_COUNT)));
#   define XfOrM47_COUNT (3+XfOrM43_COUNT)
#   define SETUP_XfOrM47(x) SETUP(XfOrM47_COUNT)
    n1 = NULLED_OUT ; 
    n2 = NULLED_OUT ; 
    first = NULLED_OUT ; 
    first = (mzchar * ) FUNCCALL(SETUP_XfOrM47(_), GC_malloc_atomic ((has_slash - delta + 1 ) * sizeof (mzchar ) ) ); 
    (memcpy (first , str + delta , (has_slash - delta ) * sizeof (mzchar ) ) ) ; 
    first [has_slash - delta ] = 0 ; 
    n1 = FUNCCALL(SETUP_XfOrM47(_), scheme_read_number (first , has_slash - delta , is_float , is_not_float , 1 , radix , 1 , next_complain , div_by_zero , test_only , stxsrc , line , col , pos , span , indentation ) ); 
    if (((n1 ) == (scheme_false ) ) )
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    {
      mzchar * substr ; 
      BLOCK_SETUP((PUSH(substr, 0+XfOrM47_COUNT)));
#     define XfOrM52_COUNT (1+XfOrM47_COUNT)
#     define SETUP_XfOrM52(x) SETUP(XfOrM52_COUNT)
      substr = NULLED_OUT ; 
      {
        int slen = len - (has_slash + 1 ) + 1 ; 
#       define XfOrM53_COUNT (0+XfOrM52_COUNT)
#       define SETUP_XfOrM53(x) SETUP_XfOrM52(x)
        substr = (mzchar * ) FUNCCALL(SETUP_XfOrM53(_), GC_malloc_atomic (slen * sizeof (mzchar ) ) ); 
        (memcpy (substr , str + has_slash + 1 , slen * sizeof (mzchar ) ) ) ; 
      }
      n2 = FUNCCALL(SETUP_XfOrM52(_), scheme_read_number (substr , len - has_slash - 1 , is_float , is_not_float , 1 , radix , 1 , next_complain , div_by_zero , test_only , stxsrc , line , col , pos , span , indentation ) ); 
    }
    if (((n2 ) == (scheme_false ) ) )
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    if (((((long ) (n2 ) ) & 0x1 ) || (((n2 ) -> type ) == scheme_bignum_type ) || (((n2 ) -> type ) == scheme_rational_type ) ) && (scheme_is_zero (n2 ) ) ) {
#     define XfOrM51_COUNT (0+XfOrM47_COUNT)
#     define SETUP_XfOrM51(x) SETUP_XfOrM47(x)
      if (complain )
        FUNCCALL(SETUP_XfOrM51(_), scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: division by zero: %u" , str , len ) ); 
      if (div_by_zero )
        * div_by_zero = 1 ; 
      RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
    }
    if (test_only )
      RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (1 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
    n1 = FUNCCALL(SETUP_XfOrM47(_), scheme_bin_div (n1 , n2 ) ); 
    if (is_not_float ) {
#     define XfOrM48_COUNT (0+XfOrM47_COUNT)
#     define SETUP_XfOrM48(x) SETUP_XfOrM47(x)
      if (((Scheme_Type ) (((((long ) (n1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n1 ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ) {
#       define XfOrM49_COUNT (0+XfOrM48_COUNT)
#       define SETUP_XfOrM49(x) SETUP_XfOrM48(x)
        if (! FUNCCALL(SETUP_XfOrM49(_), scheme_check_double (((void * ) 0 ) , (((Scheme_Double * ) (n1 ) ) -> double_val ) , ((void * ) 0 ) ) )) {
#         define XfOrM50_COUNT (0+XfOrM49_COUNT)
#         define SETUP_XfOrM50(x) SETUP_XfOrM49(x)
          if (complain )
            FUNCCALL(SETUP_XfOrM50(_), scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: no exact representation for %V" , n1 ) ); 
          RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
        }
      }
      n1 = FUNCCALL(SETUP_XfOrM48(_), scheme_inexact_to_exact (1 , & n1 ) ); 
    }
    else if (is_float )
      n1 = FUNCCALL(SETUP_XfOrM47(_), scheme_TO_DOUBLE (n1 ) ); 
    RET_VALUE_START (n1 ) RET_VALUE_END ; 
  }
  o = FUNCCALL(SETUP_XfOrM43(_), scheme_read_bignum (str , delta , radix ) ); 
  if (((o ) == (scheme_false ) ) ) {
#   define XfOrM46_COUNT (0+XfOrM43_COUNT)
#   define SETUP_XfOrM46(x) SETUP_XfOrM43(x)
    if (report )
      FUNCCALL_EMPTY(scheme_read_err (complain , stxsrc , line , col , pos , span , 0 , indentation , "read-number: bad number: %u" , str , len ) ); 
  }
  else if (is_float ) {
#   define XfOrM44_COUNT (0+XfOrM43_COUNT)
#   define SETUP_XfOrM44(x) SETUP_XfOrM43(x)
    if ((o == ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) && str [delta ] == '-' ) {
      RET_VALUE_START (scheme_nzerod ) RET_VALUE_END ; 
    }
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_TO_DOUBLE (o ) )) RET_VALUE_EMPTY_END ; 
  }
  RET_VALUE_START (o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * number_to_string (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * o = argv [0 ] ; 
  long radix ; 
  char * __funcarg21 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(0);
# define XfOrM197_COUNT (0)
# define SETUP_XfOrM197(x) SETUP(XfOrM197_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! ((((long ) (o ) ) & 0x1 ) || ((((o ) -> type ) >= scheme_bignum_type ) && (((o ) -> type ) <= scheme_complex_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("number->string" , "number" , 0 , argc , argv ) ); 
  if (argc == 2 ) {
#   define XfOrM204_COUNT (0+XfOrM197_COUNT)
#   define SETUP_XfOrM204(x) SETUP_XfOrM197(x)
    if (! (((long ) (argv [1 ] ) ) & 0x1 ) )
      radix = 0 ; 
    else radix = (((long ) (argv [1 ] ) ) >> 1 ) ; 
    if ((radix != 2 ) && (radix != 8 ) && (radix != 10 ) && (radix != 16 ) ) {
#     define XfOrM205_COUNT (0+XfOrM204_COUNT)
#     define SETUP_XfOrM205(x) SETUP_XfOrM204(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("number->string" , "2, 8, 10, or 16" , 1 , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    radix = (((long ) (argv [1 ] ) ) >> 1 ) ; 
  }
  else radix = 10 ; 
  if ((((long ) (o ) ) & 0x1 ) && ((radix == 10 ) || (radix == 16 ) ) ) {
    mzchar num [32 ] ; 
    int pos = 32 ; 
    long v = (((long ) (o ) ) >> 1 ) ; 
#   define XfOrM198_COUNT (0+XfOrM197_COUNT)
#   define SETUP_XfOrM198(x) SETUP_XfOrM197(x)
    if (v ) {
      int neg , digit ; 
      if (v < 0 ) {
        neg = 1 ; 
        v = - v ; 
      }
      else neg = 0 ; 
      while (v ) {
        digit = (v % radix ) ; 
        if (digit < 10 )
          num [-- pos ] = digit + '0' ; 
        else num [-- pos ] = (digit - 10 ) + 'a' ; 
        v = v / radix ; 
      }
      if (neg )
        num [-- pos ] = '-' ; 
    }
    else {
      num [-- pos ] = '0' ; 
    }
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_offset_char_string (num , pos , 32 - pos , 1 ) )) RET_VALUE_EMPTY_END ; 
  }
  RET_VALUE_START ((__funcarg21 = FUNCCALL_EMPTY(number_to_allocated_string (radix , o , 1 ) ), FUNCCALL_EMPTY(scheme_make_utf8_string (__funcarg21 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * string_to_number (int argc , Scheme_Object * argv [] ) {
  long radix ; 
  long len ; 
  mzchar * mzstr ; 
  int decimal_inexact , div_by_zero = 0 ; 
  Scheme_Object * v ; 
  Scheme_Config * __funcarg22 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(mzstr, 0), PUSH(v, 1), PUSH(argv, 2)));
# define XfOrM206_COUNT (3)
# define SETUP_XfOrM206(x) SETUP(XfOrM206_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  mzstr = NULLED_OUT ; 
  v = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("string->number" , "string" , 0 , argc , argv ) ); 
  if (argc > 1 ) {
#   define XfOrM207_COUNT (0+XfOrM206_COUNT)
#   define SETUP_XfOrM207(x) SETUP_XfOrM206(x)
    if ((((long ) (argv [1 ] ) ) & 0x1 ) )
      radix = (((long ) (argv [1 ] ) ) >> 1 ) ; 
    else radix = 0 ; 
    if ((radix < 2 ) || (radix > 16 ) ) {
#     define XfOrM208_COUNT (0+XfOrM207_COUNT)
#     define SETUP_XfOrM208(x) SETUP_XfOrM207(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("string->number" , "exact integer in [2, 16]" , 1 , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  else radix = 10 ; 
  decimal_inexact = (! ((((__funcarg22 = FUNCCALL(SETUP_XfOrM206(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg22 , MZCONFIG_READ_DECIMAL_INEXACT ) )) ) ) == (scheme_false ) ) ) ; 
  mzstr = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) ; 
  len = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) ; 
  v = FUNCCALL(SETUP_XfOrM206(_), scheme_read_number (mzstr , len , 0 , 0 , decimal_inexact , radix , 0 , ((void * ) 0 ) , & div_by_zero , 0 , ((void * ) 0 ) , 0 , 0 , 0 , 0 , ((void * ) 0 ) ) ); 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static char * double_to_string (double d , int alloc ) {
  char buffer [100 ] , * s ; 
  int l , i , digits ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(s, 0)));
# define XfOrM209_COUNT (1)
# define SETUP_XfOrM209(x) SETUP(XfOrM209_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  s = NULLED_OUT ; 
  if (isnan (d ) )
    s = not_a_number_str ; 
  else if ((isinf (d ) && (d > 0 ) ) )
    s = infinity_str ; 
  else if ((isinf (d ) && (d < 0 ) ) )
    s = minus_infinity_str ; 
  else if (d == 0.0 ) {
#   define XfOrM217_COUNT (0+XfOrM209_COUNT)
#   define SETUP_XfOrM217(x) SETUP_XfOrM209(x)
    if ((scheme_minus_zero_p (d ) ) )
      s = "-0.0" ; 
    else s = "0.0" ; 
  }
  else {
#   define XfOrM211_COUNT (0+XfOrM209_COUNT)
#   define SETUP_XfOrM211(x) SETUP_XfOrM209(x)
    digits = 14 ; 
    while (digits < 30 ) {
      double check ; 
      GC_CAN_IGNORE char * ptr ; 
#     define XfOrM216_COUNT (0+XfOrM211_COUNT)
#     define SETUP_XfOrM216(x) SETUP_XfOrM211(x)
      (sprintf (buffer , "%.*g" , digits , d ) ) ; 
      check = FUNCCALL(SETUP_XfOrM216(_), strtod (buffer , & ptr ) ); 
      if (check == d )
        break ; 
      digits ++ ; 
    }
    l = strlen (buffer ) ; 
    for (i = 0 ; i < l ; i ++ ) {
#     define XfOrM214_COUNT (0+XfOrM211_COUNT)
#     define SETUP_XfOrM214(x) SETUP_XfOrM211(x)
      if (buffer [i ] == '.' || ((* FUNCCALL(SETUP_XfOrM214(_), __ctype_b_loc () )) [(int ) (((unsigned char ) buffer [i ] ) ) ] & (unsigned short int ) _ISalpha ) )
        break ; 
    }
    if (i == l ) {
      buffer [i ] = '.' ; 
      buffer [i + 1 ] = '0' ; 
      buffer [i + 2 ] = 0 ; 
      l += 2 ; 
    }
    s = (char * ) FUNCCALL(SETUP_XfOrM211(_), GC_malloc_atomic (strlen (buffer ) + 1 ) ); 
    (strcpy (s , buffer ) ) ; 
    alloc = 0 ; 
  }
  if (alloc ) {
    char * s2 ; 
    BLOCK_SETUP((PUSH(s2, 0+XfOrM209_COUNT)));
#   define XfOrM210_COUNT (1+XfOrM209_COUNT)
#   define SETUP_XfOrM210(x) SETUP(XfOrM210_COUNT)
    s2 = NULLED_OUT ; 
    l = strlen (s ) + 1 ; 
    s2 = (char * ) FUNCCALL(SETUP_XfOrM210(_), GC_malloc_atomic (l ) ); 
    (memcpy (s2 , s , l ) ) ; 
    s = s2 ; 
  }
  RET_VALUE_START (s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static char * number_to_allocated_string (int radix , Scheme_Object * obj , int alloc ) {
  char * s ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(obj, 0), PUSH(s, 1)));
# define XfOrM218_COUNT (2)
# define SETUP_XfOrM218(x) SETUP(XfOrM218_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  s = NULLED_OUT ; 
  if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_double_type ) ) ) {
#   define XfOrM223_COUNT (0+XfOrM218_COUNT)
#   define SETUP_XfOrM223(x) SETUP_XfOrM218(x)
    if (radix != 10 )
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "number->string: " "inexact numbers can only be printed in base 10" ) ); 
    s = FUNCCALL(SETUP_XfOrM223(_), double_to_string ((((Scheme_Double * ) (obj ) ) -> double_val ) , alloc ) ); 
  }
  else if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_rational_type ) ) ) {
    Scheme_Object * n , * d ; 
    char * ns , * ds ; 
    int nlen , dlen ; 
    BLOCK_SETUP((PUSH(ds, 0+XfOrM218_COUNT), PUSH(n, 1+XfOrM218_COUNT), PUSH(ns, 2+XfOrM218_COUNT), PUSH(d, 3+XfOrM218_COUNT)));
#   define XfOrM222_COUNT (4+XfOrM218_COUNT)
#   define SETUP_XfOrM222(x) SETUP(XfOrM222_COUNT)
    n = NULLED_OUT ; 
    d = NULLED_OUT ; 
    ns = NULLED_OUT ; 
    ds = NULLED_OUT ; 
    n = FUNCCALL(SETUP_XfOrM222(_), scheme_rational_numerator (obj ) ); 
    d = FUNCCALL_AGAIN(scheme_rational_denominator (obj ) ); 
    ns = FUNCCALL_AGAIN(number_to_allocated_string (radix , n , 0 ) ); 
    ds = FUNCCALL_AGAIN(number_to_allocated_string (radix , d , 0 ) ); 
    nlen = strlen (ns ) ; 
    dlen = strlen (ds ) ; 
    s = (char * ) FUNCCALL(SETUP_XfOrM222(_), GC_malloc_atomic (nlen + dlen + 2 ) ); 
    (memcpy (s , ns , nlen ) ) ; 
    s [nlen ] = '/' ; 
    (strcpy (s + nlen + 1 , ds ) ) ; 
  }
  else if ((! (((long ) (obj ) ) & 0x1 ) && ((((obj ) -> type ) >= scheme_complex_izi_type ) && (((obj ) -> type ) <= scheme_complex_type ) ) ) ) {
    Scheme_Object * r , * i ; 
    char * rs , * is ; 
    int rlen , ilen , offset = 0 ; 
    BLOCK_SETUP((PUSH(is, 0+XfOrM218_COUNT), PUSH(rs, 1+XfOrM218_COUNT), PUSH(i, 2+XfOrM218_COUNT)));
#   define XfOrM220_COUNT (3+XfOrM218_COUNT)
#   define SETUP_XfOrM220(x) SETUP(XfOrM220_COUNT)
    r = NULLED_OUT ; 
    i = NULLED_OUT ; 
    rs = NULLED_OUT ; 
    is = NULLED_OUT ; 
    r = (((Scheme_Complex * ) (obj ) ) -> r ) ; 
    i = (((Scheme_Complex * ) (obj ) ) -> i ) ; 
    rs = FUNCCALL(SETUP_XfOrM220(_), number_to_allocated_string (radix , r , 0 ) ); 
    is = FUNCCALL_AGAIN(number_to_allocated_string (radix , i , 0 ) ); 
    rlen = strlen (rs ) ; 
    ilen = strlen (is ) ; 
    s = (char * ) FUNCCALL(SETUP_XfOrM220(_), GC_malloc_atomic (rlen + ilen + 3 ) ); 
    (memcpy (s , rs , rlen ) ) ; 
    if ((is [0 ] != '-' ) && (is [0 ] != '+' ) ) {
      offset = 1 ; 
      s [rlen ] = '+' ; 
    }
    (memcpy (s + rlen + offset , is , ilen ) ) ; 
    s [rlen + offset + ilen ] = 'i' ; 
    s [rlen + offset + ilen + 1 ] = 0 ; 
  }
  else {
#   define XfOrM219_COUNT (0+XfOrM218_COUNT)
#   define SETUP_XfOrM219(x) SETUP_XfOrM218(x)
    if ((((long ) (obj ) ) & 0x1 ) )
      obj = FUNCCALL(SETUP_XfOrM219(_), scheme_make_bignum ((((long ) (obj ) ) >> 1 ) ) ); 
    s = FUNCCALL(SETUP_XfOrM219(_), scheme_bignum_to_allocated_string (obj , radix , alloc ) ); 
  }
  RET_VALUE_START (s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
char * scheme_number_to_string (int radix , Scheme_Object * obj ) {
  /* No conversion */
  return number_to_allocated_string (radix , obj , 0 ) ; 
}
int scheme_check_double (const char * where , double d , const char * dest ) {
  char * __funcarg23 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(where, 0), PUSH(dest, 1)));
# define XfOrM225_COUNT (2)
# define SETUP_XfOrM225(x) SETUP(XfOrM225_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if ((isinf (d ) && (d > 0 ) ) || (isinf (d ) && (d < 0 ) ) || isnan (d ) ) {
#   define XfOrM226_COUNT (0+XfOrM225_COUNT)
#   define SETUP_XfOrM226(x) SETUP_XfOrM225(x)
    if (where )
      (__funcarg23 = FUNCCALL(SETUP_XfOrM226(_), double_to_string (d , 0 ) ), FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: no %s representation for %s" , where , dest , __funcarg23 ) )) ; 
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  RET_VALUE_START (1 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * bytes_to_integer (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  int slen , sgned ; 
  char * str ; 
  int buf [2 ] , i ; 
  int bigend = 0 ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
    slen = 0 ; 
  else slen = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . tag_val ) ; 
  if ((slen != 2 ) && (slen != 4 ) && (slen != 8 ) )
    scheme_wrong_type ("integer-bytes->integer" , "byte string (2, 4, or 8 bytes)" , 0 , argc , argv ) ; 
  str = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) ; 
  sgned = (! (((argv [1 ] ) ) == (scheme_false ) ) ) ; 
  if (argc > 2 )
    bigend = (! (((argv [2 ] ) ) == (scheme_false ) ) ) ; 
  if (bigend != 0 ) {
    for (i = 0 ; i < slen ; i ++ ) {
      ((char * ) buf ) [slen - i - 1 ] = str [i ] ; 
    }
    str = (char * ) buf ; 
  }
  switch (slen ) {
    case 2 : if (sgned )
      return ((Scheme_Object * ) (void * ) (long ) ((((long ) (((short * ) str ) [0 ] ) ) << 1 ) | 0x1 ) ) ; 
    else return ((Scheme_Object * ) (void * ) (long ) ((((long ) (((unsigned short * ) str ) [0 ] ) ) << 1 ) | 0x1 ) ) ; 
    break ; 
    case 4 : if (sgned )
      return scheme_make_integer_value (((int * ) str ) [0 ] ) ; 
    else return scheme_make_integer_value_from_unsigned (((unsigned int * ) str ) [0 ] ) ; 
    break ; 
    default : if (sgned )
      return scheme_make_integer_value (((long * ) str ) [0 ] ) ; 
    else return scheme_make_integer_value_from_unsigned (((unsigned long * ) str ) [0 ] ) ; 
    break ; 
    break ; 
  }
}
static Scheme_Object * integer_to_bytes (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * n , * s ; 
  char * str ; 
  int size , sgned ; 
  long val ; 
  int bigend = 0 , bad ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(n, 0), PUSH(str, 1), PUSH(s, 2), PUSH(argv, 3)));
# define XfOrM232_COUNT (4)
# define SETUP_XfOrM232(x) SETUP(XfOrM232_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  n = NULLED_OUT ; 
  s = NULLED_OUT ; 
  str = NULLED_OUT ; 
  n = argv [0 ] ; 
  if (! (((long ) (n ) ) & 0x1 ) && ! ((Scheme_Type ) (((((long ) (n ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("integer->integer-bytes" , "exact integer" , 0 , argc , argv ) ); 
  if ((((long ) (argv [1 ] ) ) & 0x1 ) )
    size = (((long ) (argv [1 ] ) ) >> 1 ) ; 
  else size = 0 ; 
  if ((size != 2 ) && (size != 4 ) && (size != 8 ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("integer->integer-bytes" , "exact 2, 4, or 8" , 1 , argc , argv ) ); 
  sgned = (! (((argv [2 ] ) ) == (scheme_false ) ) ) ; 
  if (argc > 3 )
    bigend = (! (((argv [3 ] ) ) == (scheme_false ) ) ) ; 
  if (argc > 4 )
    s = argv [4 ] ; 
  else s = FUNCCALL(SETUP_XfOrM232(_), scheme_make_sized_byte_string ("12345678" , size , 1 ) ); 
  if (! (((Scheme_Type ) (((((long ) (s ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (s ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) && (! (((Scheme_Inclhash_Object * ) (s ) ) -> so . keyex & 0x1 ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("integer->integer-bytes" , "mutable byte string" , 4 , argc , argv ) ); 
  if (size == 2 ) {
    if (((Scheme_Type ) (((((long ) (n ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
      bad = 1 ; 
    else {
      val = (((long ) (n ) ) >> 1 ) ; 
      if (sgned ) {
        bad = ((val < - 32768 ) || (val > 32767 ) ) ; 
      }
      else {
        bad = ((val < 0 ) || (val > 65535 ) ) ; 
      }
    }
  }
  else if (size == 4 ) {
#   define XfOrM247_COUNT (0+XfOrM232_COUNT)
#   define SETUP_XfOrM247(x) SETUP_XfOrM232(x)
    if (sgned )
      bad = ! (scheme_get_int_val (n , & val ) ) ; 
    else bad = ! (scheme_get_unsigned_int_val (n , (unsigned long * ) & val ) ) ; 
    if (! bad ) {
      if (sgned )
        bad = ((val > (long ) 0x7fffffff ) || (val < - (long ) 0x80000000 ) ) ; 
      else bad = (val > (long ) 0xffffffff ) ; 
    }
  }
  else {
#   define XfOrM246_COUNT (0+XfOrM232_COUNT)
#   define SETUP_XfOrM246(x) SETUP_XfOrM232(x)
    if (sgned )
      bad = ! (scheme_get_int_val (n , & val ) ) ; 
    else bad = ! (scheme_get_unsigned_int_val (n , (unsigned long * ) & val ) ) ; 
  }
  if (bad ) {
#   define XfOrM245_COUNT (0+XfOrM232_COUNT)
#   define SETUP_XfOrM245(x) SETUP_XfOrM232(x)
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "integer->integer-bytes: integer does not fit into %d %ssigned bytes: %V" , size , (sgned ? "" : "un" ) , n ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (size != (((Scheme_Simple_Object * ) (s ) ) -> u . byte_str_val . tag_val ) ) {
#   define XfOrM244_COUNT (0+XfOrM232_COUNT)
#   define SETUP_XfOrM244(x) SETUP_XfOrM232(x)
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "integer->integer-bytes: string size %d does not match indicated %d-byte length: %V" , (((Scheme_Simple_Object * ) (s ) ) -> u . byte_str_val . tag_val ) , size , s ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  str = (((Scheme_Simple_Object * ) (s ) ) -> u . byte_str_val . string_val ) ; 
  switch (size ) {
    case 2 : {
      if (sgned ) {
        * (unsigned short * ) str = (unsigned short ) (val ) ; 
      }
      else {
        * (short * ) str = (short ) (val ) ; 
      }
    }
    break ; 
    case 4 : if (sgned ) {
      unsigned int sv = val ; 
      * (unsigned int * ) str = sv ; 
    }
    else {
      int sv = val ; 
      * (int * ) str = sv ; 
    }
    break ; 
    default : * (long * ) str = val ; 
    break ; 
  }
  if (bigend != 0 ) {
    int i ; 
    char buf [8 ] ; 
    for (i = 0 ; i < size ; i ++ ) {
      buf [size - i - 1 ] = str [i ] ; 
    }
    for (i = 0 ; i < size ; i ++ ) {
      str [i ] = buf [i ] ; 
    }
  }
  RET_VALUE_START (s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * bytes_to_real (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  int slen ; 
  char * str , buf [8 ] ; 
  int bigend = 0 ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
    slen = 0 ; 
  else slen = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . tag_val ) ; 
  if ((slen != 4 ) && (slen != 8 ) )
    scheme_wrong_type ("floating-point-bytes->real" , "byte string (4 or 8 bytes)" , 0 , argc , argv ) ; 
  str = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) ; 
  if (argc > 1 )
    bigend = (! (((argv [1 ] ) ) == (scheme_false ) ) ) ; 
  if (bigend != 0 ) {
    int i ; 
    for (i = 0 ; i < slen ; i ++ ) {
      buf [slen - i - 1 ] = str [i ] ; 
    }
    str = (char * ) buf ; 
  }
  switch (slen ) {
    case 4 : {
      float f ; 
      f = * (float * ) str ; 
      return scheme_make_double (f ) ; 
    }
    break ; 
    default : {
      double d ; 
      memcpy (& d , str , sizeof (double ) ) ; 
      return scheme_make_double (d ) ; 
    }
    break ; 
  }
}
static Scheme_Object * real_to_bytes (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * n , * s ; 
  int size ; 
  int bigend = 0 ; 
  double d ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(n, 0), PUSH(s, 1), PUSH(argv, 2)));
# define XfOrM260_COUNT (3)
# define SETUP_XfOrM260(x) SETUP(XfOrM260_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  n = NULLED_OUT ; 
  s = NULLED_OUT ; 
  n = argv [0 ] ; 
  if (! ((((long ) (n ) ) & 0x1 ) || ((((n ) -> type ) >= scheme_bignum_type ) && (((n ) -> type ) <= scheme_complex_izi_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("real->floating-point-bytes" , "real number" , 0 , argc , argv ) ); 
  if ((((long ) (argv [1 ] ) ) & 0x1 ) )
    size = (((long ) (argv [1 ] ) ) >> 1 ) ; 
  else size = 0 ; 
  if ((size != 4 ) && (size != 8 ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("real->floating-point-bytes" , "exact 4 or 8" , 1 , argc , argv ) ); 
  if (argc > 2 )
    bigend = (! (((argv [2 ] ) ) == (scheme_false ) ) ) ; 
  if (argc > 3 )
    s = argv [3 ] ; 
  else s = FUNCCALL(SETUP_XfOrM260(_), scheme_make_sized_byte_string ("12345678" , size , 1 ) ); 
  if (! (((Scheme_Type ) (((((long ) (s ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (s ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) && (! (((Scheme_Inclhash_Object * ) (s ) ) -> so . keyex & 0x1 ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("real->floating-point-bytes" , "mutable byte string" , 3 , argc , argv ) ); 
  if (size != (((Scheme_Simple_Object * ) (s ) ) -> u . byte_str_val . tag_val ) ) {
#   define XfOrM267_COUNT (0+XfOrM260_COUNT)
#   define SETUP_XfOrM267(x) SETUP_XfOrM260(x)
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "real->floating-point-bytes: string size %d does not match indicated %d-byte length: %V" , (((Scheme_Simple_Object * ) (s ) ) -> u . byte_str_val . tag_val ) , size , s ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  d = FUNCCALL(SETUP_XfOrM260(_), scheme_get_val_as_double (n ) ); 
  if (size == 4 )
    * (float * ) ((((Scheme_Simple_Object * ) (s ) ) -> u . byte_str_val . string_val ) ) = (float ) (d ) ; 
  else {
#   define XfOrM266_COUNT (0+XfOrM260_COUNT)
#   define SETUP_XfOrM266(x) SETUP_XfOrM260(x)
    (memcpy ((((Scheme_Simple_Object * ) (s ) ) -> u . byte_str_val . string_val ) , & d , sizeof (double ) ) ) ; 
  }
  if (bigend != 0 ) {
    int i ; 
    char buf [8 ] , * str ; 
    str = NULLED_OUT ; 
    str = (((Scheme_Simple_Object * ) (s ) ) -> u . byte_str_val . string_val ) ; 
    for (i = 0 ; i < size ; i ++ ) {
      buf [size - i - 1 ] = str [i ] ; 
    }
    for (i = 0 ; i < size ; i ++ ) {
      str [i ] = buf [i ] ; 
    }
  }
  RET_VALUE_START (s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * system_big_endian_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_false ; 
}
static double mrg32k3a (Scheme_Random_State * s ) {
  /* No conversion */
  double x10 , x20 , y ; 
  long k10 , k20 ; 
  x10 = 1403580.0 * (s -> x11 ) - 810728.0 * (s -> x12 ) ; 
  k10 = (long ) (x10 / 4294967087.0 ) ; 
  x10 -= k10 * 4294967087.0 ; 
  if (x10 < 0.0 )
    x10 += 4294967087.0 ; 
  s -> x12 = s -> x11 ; 
  s -> x11 = s -> x10 ; 
  s -> x10 = x10 ; 
  x20 = 527612.0 * (s -> x20 ) - 1370589.0 * (s -> x22 ) ; 
  k20 = (long ) (x20 / 4294944443.0 ) ; 
  x20 -= k20 * 4294944443.0 ; 
  if (x20 < 0.0 )
    x20 += 4294944443.0 ; 
  s -> x22 = s -> x21 ; 
  s -> x21 = s -> x20 ; 
  s -> x20 = x20 ; 
  y = x10 - x20 ; 
  if (y < 0.0 )
    y += 4294967087.0 ; 
  return y ; 
}
static Scheme_Object * pack_rand_state (Scheme_Object * vec ) {
  Scheme_Random_State * s ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(vec, 1)));
# define XfOrM270_COUNT (2)
# define SETUP_XfOrM270(x) SETUP(XfOrM270_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  s = (Scheme_Random_State * ) FUNCCALL(SETUP_XfOrM270(_), GC_malloc_one_tagged (sizeof (Scheme_Random_State ) ) ); 
  s -> so . type = scheme_random_state_type ; 
  {
    unsigned long l ; 
#   define XfOrM276_COUNT (0+XfOrM270_COUNT)
#   define SETUP_XfOrM276(x) SETUP_XfOrM270(x)
    if (! (scheme_get_unsigned_int_val ((((Scheme_Vector * ) (vec ) ) -> els ) [0 ] , & l ) ) )
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    if (l > 0xffffff2f - 1 )
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    s -> x10 = (double ) l ; 
  }
  {
    unsigned long l ; 
#   define XfOrM275_COUNT (0+XfOrM270_COUNT)
#   define SETUP_XfOrM275(x) SETUP_XfOrM270(x)
    if (! (scheme_get_unsigned_int_val ((((Scheme_Vector * ) (vec ) ) -> els ) [1 ] , & l ) ) )
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    if (l > 0xffffff2f - 1 )
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    s -> x11 = (double ) l ; 
  }
  {
    unsigned long l ; 
#   define XfOrM274_COUNT (0+XfOrM270_COUNT)
#   define SETUP_XfOrM274(x) SETUP_XfOrM270(x)
    if (! (scheme_get_unsigned_int_val ((((Scheme_Vector * ) (vec ) ) -> els ) [2 ] , & l ) ) )
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    if (l > 0xffffff2f - 1 )
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    s -> x12 = (double ) l ; 
  }
  {
    unsigned long l ; 
#   define XfOrM273_COUNT (0+XfOrM270_COUNT)
#   define SETUP_XfOrM273(x) SETUP_XfOrM270(x)
    if (! (scheme_get_unsigned_int_val ((((Scheme_Vector * ) (vec ) ) -> els ) [3 ] , & l ) ) )
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    if (l > 0xffffa6bb - 1 )
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    s -> x20 = (double ) l ; 
  }
  {
    unsigned long l ; 
#   define XfOrM272_COUNT (0+XfOrM270_COUNT)
#   define SETUP_XfOrM272(x) SETUP_XfOrM270(x)
    if (! (scheme_get_unsigned_int_val ((((Scheme_Vector * ) (vec ) ) -> els ) [4 ] , & l ) ) )
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    if (l > 0xffffa6bb - 1 )
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    s -> x21 = (double ) l ; 
  }
  {
    unsigned long l ; 
#   define XfOrM271_COUNT (0+XfOrM270_COUNT)
#   define SETUP_XfOrM271(x) SETUP_XfOrM270(x)
    if (! (scheme_get_unsigned_int_val ((((Scheme_Vector * ) (vec ) ) -> els ) [5 ] , & l ) ) )
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    if (l > 0xffffa6bb - 1 )
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    s -> x22 = (double ) l ; 
  }
  if (! s -> x10 && ! s -> x11 && ! s -> x12 )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  if (! s -> x20 && ! s -> x21 && ! s -> x22 )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  RET_VALUE_START ((Scheme_Object * ) s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * unpack_rand_state (Scheme_Random_State * s ) {
  Scheme_Object * result ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(result, 0), PUSH(s, 1)));
# define XfOrM277_COUNT (2)
# define SETUP_XfOrM277(x) SETUP(XfOrM277_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  result = NULLED_OUT ; 
  result = FUNCCALL(SETUP_XfOrM277(_), scheme_make_vector ((long ) 6 , ((void * ) 0 ) ) ); 
  {
    Scheme_Object * o ; 
    BLOCK_SETUP((PUSH(o, 0+XfOrM277_COUNT)));
#   define XfOrM283_COUNT (1+XfOrM277_COUNT)
#   define SETUP_XfOrM283(x) SETUP(XfOrM283_COUNT)
    o = NULLED_OUT ; 
    o = FUNCCALL(SETUP_XfOrM283(_), scheme_make_integer_value_from_unsigned ((unsigned long ) s -> x10 ) ); 
    (((Scheme_Vector * ) (result ) ) -> els ) [0 ] = o ; 
  }
  {
    Scheme_Object * o ; 
    BLOCK_SETUP((PUSH(o, 0+XfOrM277_COUNT)));
#   define XfOrM282_COUNT (1+XfOrM277_COUNT)
#   define SETUP_XfOrM282(x) SETUP(XfOrM282_COUNT)
    o = NULLED_OUT ; 
    o = FUNCCALL(SETUP_XfOrM282(_), scheme_make_integer_value_from_unsigned ((unsigned long ) s -> x11 ) ); 
    (((Scheme_Vector * ) (result ) ) -> els ) [1 ] = o ; 
  }
  {
    Scheme_Object * o ; 
    BLOCK_SETUP((PUSH(o, 0+XfOrM277_COUNT)));
#   define XfOrM281_COUNT (1+XfOrM277_COUNT)
#   define SETUP_XfOrM281(x) SETUP(XfOrM281_COUNT)
    o = NULLED_OUT ; 
    o = FUNCCALL(SETUP_XfOrM281(_), scheme_make_integer_value_from_unsigned ((unsigned long ) s -> x12 ) ); 
    (((Scheme_Vector * ) (result ) ) -> els ) [2 ] = o ; 
  }
  {
    Scheme_Object * o ; 
    BLOCK_SETUP((PUSH(o, 0+XfOrM277_COUNT)));
#   define XfOrM280_COUNT (1+XfOrM277_COUNT)
#   define SETUP_XfOrM280(x) SETUP(XfOrM280_COUNT)
    o = NULLED_OUT ; 
    o = FUNCCALL(SETUP_XfOrM280(_), scheme_make_integer_value_from_unsigned ((unsigned long ) s -> x20 ) ); 
    (((Scheme_Vector * ) (result ) ) -> els ) [3 ] = o ; 
  }
  {
    Scheme_Object * o ; 
    BLOCK_SETUP((PUSH(o, 0+XfOrM277_COUNT)));
#   define XfOrM279_COUNT (1+XfOrM277_COUNT)
#   define SETUP_XfOrM279(x) SETUP(XfOrM279_COUNT)
    o = NULLED_OUT ; 
    o = FUNCCALL(SETUP_XfOrM279(_), scheme_make_integer_value_from_unsigned ((unsigned long ) s -> x21 ) ); 
    (((Scheme_Vector * ) (result ) ) -> els ) [4 ] = o ; 
  }
  {
    Scheme_Object * o ; 
    BLOCK_SETUP((PUSH(o, 0+XfOrM277_COUNT)));
#   define XfOrM278_COUNT (1+XfOrM277_COUNT)
#   define SETUP_XfOrM278(x) SETUP(XfOrM278_COUNT)
    o = NULLED_OUT ; 
    o = FUNCCALL(SETUP_XfOrM278(_), scheme_make_integer_value_from_unsigned ((unsigned long ) s -> x22 ) ); 
    (((Scheme_Vector * ) (result ) ) -> els ) [5 ] = o ; 
  }
  RET_VALUE_START (result ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static unsigned int _random_m (unsigned int * _x ) {
  /* No conversion */
  unsigned int x , y ; 
  x = * _x ; 
  y = x & 0xFFFF ; 
  x = (30903 * y ) + (x >> 16 ) ; 
  * _x = x ; 
  return y ; 
}
static int _random_n (unsigned int * _x , int n ) {
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(_x, 0)));
# define XfOrM285_COUNT (1)
# define SETUP_XfOrM285(x) SETUP(XfOrM285_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  RET_VALUE_START (((FUNCCALL(SETUP_XfOrM285(_), _random_m (_x ) )<< 16 ) + FUNCCALL_EMPTY(_random_m (_x ) )) % n ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void sch_srand_half (unsigned int x , Scheme_Random_State * s ) {
  unsigned int z ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(s, 0)));
# define XfOrM286_COUNT (1)
# define SETUP_XfOrM286(x) SETUP(XfOrM286_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  z = FUNCCALL(SETUP_XfOrM286(_), _random_n (& x , 0xffffff2f - 1 ) ); 
  s -> x10 = (double ) (1 + (((unsigned int ) s -> x10 + z ) % (0xffffff2f - 1 ) ) ) ; 
  z = FUNCCALL(SETUP_XfOrM286(_), _random_n (& x , 0xffffff2f ) ); 
  s -> x11 = (double ) (((unsigned int ) s -> x11 + z ) % 0xffffff2f ) ; 
  z = FUNCCALL(SETUP_XfOrM286(_), _random_n (& x , 0xffffff2f ) ); 
  s -> x12 = (double ) (((unsigned int ) s -> x12 + z ) % 0xffffff2f ) ; 
  z = FUNCCALL(SETUP_XfOrM286(_), _random_n (& x , 0xffffa6bb - 1 ) ); 
  s -> x20 = (double ) (1 + (((unsigned int ) s -> x20 + z ) % (0xffffa6bb - 1 ) ) ) ; 
  z = FUNCCALL(SETUP_XfOrM286(_), _random_n (& x , 0xffffa6bb ) ); 
  s -> x21 = (double ) (((unsigned int ) s -> x21 + z ) % 0xffffa6bb ) ; 
  z = FUNCCALL(SETUP_XfOrM286(_), _random_n (& x , 0xffffa6bb ) ); 
  s -> x22 = (double ) (((unsigned int ) s -> x22 + z ) % 0xffffa6bb ) ; 
  if (! s -> x10 && ! s -> x11 && ! s -> x12 )
    s -> x10 = 1 ; 
  if (! s -> x20 && ! s -> x21 && ! s -> x22 )
    s -> x20 = 1 ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void sch_srand (unsigned int x , Scheme_Random_State * s ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(s, 0)));
# define XfOrM287_COUNT (1)
# define SETUP_XfOrM287(x) SETUP(XfOrM287_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s -> x10 = 1062452522.0 ; 
  s -> x11 = 2961816100.0 ; 
  s -> x12 = 342112271.0 ; 
  s -> x20 = 2854655037.0 ; 
  s -> x21 = 3321940838.0 ; 
  s -> x22 = 3542344109.0 ; 
  FUNCCALL(SETUP_XfOrM287(_), sch_srand_half (x & 0xFFFF , s ) ); 
  FUNCCALL_EMPTY(sch_srand_half ((x >> 16 ) & 0xFFFF , s ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static long sch_int_rand (long n , Scheme_Random_State * rs ) {
  double x , q , qn , xq ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(rs, 0)));
# define XfOrM288_COUNT (1)
# define SETUP_XfOrM288(x) SETUP(XfOrM288_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  q = (double ) ((unsigned long ) (4294967087.0 / (double ) n ) ) ; 
  qn = q * n ; 
  do {
#   define XfOrM290_COUNT (0+XfOrM288_COUNT)
#   define SETUP_XfOrM290(x) SETUP_XfOrM288(x)
    x = FUNCCALL(SETUP_XfOrM290(_), mrg32k3a (rs ) ); 
  }
  while (x >= qn ) ; 
  xq = x / q ; 
  RET_VALUE_START ((long ) xq ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static double sch_double_rand (Scheme_Random_State * rs ) {
  /* No conversion */
  double x ; 
  x = mrg32k3a (rs ) ; 
  return (x + 1.0 ) * 2.328306549295728e-10 ; 
}
Scheme_Object * scheme_make_random_state (long seed ) {
  Scheme_Random_State * s ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(s, 0)));
# define XfOrM292_COUNT (1)
# define SETUP_XfOrM292(x) SETUP(XfOrM292_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  s = (Scheme_Random_State * ) FUNCCALL(SETUP_XfOrM292(_), GC_malloc_one_tagged (sizeof (Scheme_Random_State ) ) ); 
  s -> so . type = scheme_random_state_type ; 
  FUNCCALL(SETUP_XfOrM292(_), sch_srand (seed , s ) ); 
  RET_VALUE_START ((Scheme_Object * ) s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
long scheme_rand (Scheme_Random_State * rs ) {
  /* No conversion */
  return sch_int_rand (2147483647 , rs ) ; 
}
static Scheme_Object * random_seed (int argc , Scheme_Object * argv [] ) {
  long i = - 1 ; 
  Scheme_Object * o = argv [0 ] , * rand_state ; 
  Scheme_Config * __funcarg24 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(rand_state, 0)));
# define XfOrM294_COUNT (1)
# define SETUP_XfOrM294(x) SETUP(XfOrM294_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  rand_state = NULLED_OUT ; 
  if ((scheme_get_int_val (o , & i ) ) ) {
    if (i > 2147483647 )
      i = - 1 ; 
  }
  if (i < 0 )
    FUNCCALL_EMPTY(scheme_wrong_type ("random-seed" , "exact integer in [0, 2147483647]" , 0 , argc , argv ) ); 
  rand_state = (__funcarg24 = FUNCCALL(SETUP_XfOrM294(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg24 , MZCONFIG_RANDOM_STATE ) )) ; 
  FUNCCALL_EMPTY(sch_srand (i , (Scheme_Random_State * ) rand_state ) ); 
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * sch_random (int argc , Scheme_Object * argv [] ) {
  Scheme_Config * __funcarg26 = NULLED_OUT ; 
  Scheme_Config * __funcarg25 = NULLED_OUT ; 
  PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM296_COUNT (1)
# define SETUP_XfOrM296(x) SETUP(XfOrM296_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! argc ) {
    double v ; 
    Scheme_Object * rand_state ; 
    BLOCK_SETUP((PUSH(rand_state, 0+XfOrM296_COUNT)));
#   define XfOrM299_COUNT (1+XfOrM296_COUNT)
#   define SETUP_XfOrM299(x) SETUP(XfOrM299_COUNT)
    rand_state = NULLED_OUT ; 
    rand_state = (__funcarg26 = FUNCCALL(SETUP_XfOrM299(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg26 , MZCONFIG_RANDOM_STATE ) )) ; 
    v = FUNCCALL_AGAIN(sch_double_rand ((Scheme_Random_State * ) rand_state ) ); 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_double (v ) )) RET_VALUE_EMPTY_END ; 
  }
  else {
    unsigned long i , v ; 
    Scheme_Object * o , * rand_state ; 
    BLOCK_SETUP((PUSH(rand_state, 0+XfOrM296_COUNT)));
#   define XfOrM297_COUNT (1+XfOrM296_COUNT)
#   define SETUP_XfOrM297(x) SETUP(XfOrM297_COUNT)
    o = NULLED_OUT ; 
    rand_state = NULLED_OUT ; 
    o = argv [0 ] ; 
    if ((scheme_get_unsigned_int_val (o , & i ) ) ) {
      if (i > 2147483647 )
        i = 0 ; 
    }
    else i = 0 ; 
    if (! i )
      FUNCCALL_EMPTY(scheme_wrong_type ("random" , "exact integer in [1, 2147483647]" , 0 , argc , argv ) ); 
    rand_state = (__funcarg25 = FUNCCALL(SETUP_XfOrM297(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg25 , MZCONFIG_RANDOM_STATE ) )) ; 
    v = FUNCCALL_EMPTY(sch_int_rand (i , (Scheme_Random_State * ) rand_state ) ); 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_integer_value_from_unsigned (v ) )) RET_VALUE_EMPTY_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * sch_pack (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * s ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(argv, 1)));
# define XfOrM300_COUNT (2)
# define SETUP_XfOrM300(x) SETUP(XfOrM300_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) )
    s = FUNCCALL(SETUP_XfOrM300(_), pack_rand_state (argv [0 ] ) ); 
  else s = ((void * ) 0 ) ; 
  if (! s )
    FUNCCALL_EMPTY(scheme_wrong_type ("vector->pseudo-random-generator" , "vector of six elements, three in [0, 4294967086] and three in [0, 4294944442], " "at least one non-zero in each set of three" , 0 , argc , argv ) ); 
  RET_VALUE_START (s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * sch_unpack (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_random_state_type ) ) )
    scheme_wrong_type ("pseudo-random-generator->vector" , "pseudo-random-generator" , 0 , argc , argv ) ; 
  return unpack_rand_state ((Scheme_Random_State * ) argv [0 ] ) ; 
}
static Scheme_Object * current_pseudo_random_generator (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("current-pseudo-random-generator" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_RANDOM_STATE ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , pseudo_random_generator_p , "pseudo-random-generator" , 0 ) ; 
}
static Scheme_Object * current_sched_pseudo_random_generator (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("current-evt-pseudo-random-generator" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_SCHEDULER_RANDOM_STATE ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , pseudo_random_generator_p , "pseudo-random-generator" , 0 ) ; 
}
static Scheme_Object * make_pseudo_random_generator (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return scheme_make_random_state (scheme_get_milliseconds () ) ; 
}
static Scheme_Object * pseudo_random_generator_p (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_random_state_type ) ) ) ? scheme_true : scheme_false ) ; 
}
