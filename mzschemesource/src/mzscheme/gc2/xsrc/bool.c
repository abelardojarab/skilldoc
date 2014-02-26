#include "precomp.h"
extern double exp (double __x ) __attribute__ ((__nothrow__ ) ) ; 
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
Scheme_Object scheme_true [1 ] ; 
Scheme_Object scheme_false [1 ] ; 
Scheme_Object * scheme_not_prim ; 
Scheme_Object * scheme_eq_prim ; 
Scheme_Object * scheme_eqv_prim ; 
Scheme_Object * scheme_equal_prim ; 
static Scheme_Object * not_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * boolean_p_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * eq_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * eqv_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * equal_prim (int argc , Scheme_Object * argv [] ) ; 
static int vector_equal (Scheme_Object * vec1 , Scheme_Object * vec2 ) ; 
static int struct_equal (Scheme_Object * s1 , Scheme_Object * s2 ) ; 
void scheme_init_true_false (void ) {
  /* No conversion */
  scheme_true -> type = scheme_true_type ; 
  scheme_false -> type = scheme_false_type ; 
  scheme_void -> type = scheme_void_type ; 
}
void scheme_init_bool (Scheme_Env * env ) {
  Scheme_Object * p ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(p, 1)));
# define XfOrM2_COUNT (2)
# define SETUP_XfOrM2(x) SETUP(XfOrM2_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  p = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM2(_), scheme_register_static ((void * ) & scheme_not_prim , sizeof (scheme_not_prim ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_eq_prim , sizeof (scheme_eq_prim ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_eqv_prim , sizeof (scheme_eqv_prim ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_equal_prim , sizeof (scheme_equal_prim ) ) ); 
  p = FUNCCALL_AGAIN(scheme_make_folding_prim (not_prim , "not" , 1 , 1 , 1 ) ); 
  scheme_not_prim = p ; 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 16384 ; 
  FUNCCALL(SETUP_XfOrM2(_), scheme_add_global_constant ("not" , p , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_folding_prim (boolean_p_prim , "boolean?" , 1 , 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 16384 ; 
  FUNCCALL(SETUP_XfOrM2(_), scheme_add_global_constant ("boolean?" , p , env ) ); 
  p = FUNCCALL_AGAIN(scheme_make_folding_prim (eq_prim , "eq?" , 2 , 2 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 512 ; 
  scheme_eq_prim = p ; 
  FUNCCALL(SETUP_XfOrM2(_), scheme_add_global_constant ("eq?" , p , env ) ); 
  scheme_eqv_prim = FUNCCALL_AGAIN(scheme_make_folding_prim (eqv_prim , "eqv?" , 2 , 2 , 1 ) ); 
  FUNCCALL_AGAIN(scheme_add_global_constant ("eqv?" , scheme_eqv_prim , env ) ); 
  scheme_equal_prim = FUNCCALL_AGAIN(scheme_make_prim_w_arity (equal_prim , "equal?" , 2 , 2 ) ); 
  FUNCCALL_EMPTY(scheme_add_global_constant ("equal?" , scheme_equal_prim , env ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * not_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (((argv [0 ] ) == (scheme_false ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * boolean_p_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return ((((argv [0 ] ) == (scheme_true ) ) || ((argv [0 ] ) == (scheme_false ) ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * eq_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (((argv [0 ] ) == (argv [1 ] ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * eqv_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (scheme_eqv (argv [0 ] , argv [1 ] ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * equal_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (scheme_equal (argv [0 ] , argv [1 ] ) ? scheme_true : scheme_false ) ; 
}
int scheme_eq (Scheme_Object * obj1 , Scheme_Object * obj2 ) {
  /* No conversion */
  return ((obj1 ) == (obj2 ) ) ; 
}
__xform_nongcing__ static inline int double_eqv (double a , double b ) {
  /* No conversion */
  if (a != b ) {
    if (isnan (a ) ) {
      if (isnan (b ) )
        return 1 ; 
    }
    return 0 ; 
  }
  if (a == 0.0 ) {
    if (b == 0.0 ) {
      return scheme_minus_zero_p (a ) == scheme_minus_zero_p (b ) ; 
    }
  }
  return 1 ; 
}
int scheme_eqv (Scheme_Object * obj1 , Scheme_Object * obj2 ) {
  /* No conversion */
  Scheme_Type t1 , t2 ; 
  if (((obj1 ) == (obj2 ) ) )
    return 1 ; 
  t1 = ((((long ) (obj1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj1 ) ) -> type ) ; 
  t2 = ((((long ) (obj2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj2 ) ) -> type ) ; 
  if (((Scheme_Type ) (t1 ) != (Scheme_Type ) (t2 ) ) ) {
    return 0 ; 
  }
  else if (t1 == scheme_double_type ) {
    return double_eqv ((((Scheme_Double * ) (obj1 ) ) -> double_val ) , (((Scheme_Double * ) (obj2 ) ) -> double_val ) ) ; 
  }
  else if (t1 == scheme_bignum_type )
    return scheme_bignum_eq (obj1 , obj2 ) ; 
  else if (t1 == scheme_rational_type )
    return scheme_rational_eq (obj1 , obj2 ) ; 
  else if ((t1 == scheme_complex_type ) || (t1 == scheme_complex_izi_type ) ) {
    Scheme_Complex * c1 = (Scheme_Complex * ) obj1 ; 
    Scheme_Complex * c2 = (Scheme_Complex * ) obj2 ; 
    return scheme_eqv (c1 -> r , c2 -> r ) && scheme_eqv (c1 -> i , c2 -> i ) ; 
  }
  else if (t1 == scheme_char_type )
    return (((Scheme_Small_Object * ) (obj1 ) ) -> u . char_val ) == (((Scheme_Small_Object * ) (obj2 ) ) -> u . char_val ) ; 
  else return 0 ; 
}
static Scheme_Object * equal_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * v1 = (Scheme_Object * ) p -> ku . k . p1 ; 
  Scheme_Object * v2 = (Scheme_Object * ) p -> ku . k . p2 ; 
  p -> ku . k . p1 = p -> ku . k . p2 = ((void * ) 0 ) ; 
  return scheme_equal (v1 , v2 ) ? scheme_true : scheme_false ; 
}
int scheme_equal (Scheme_Object * obj1 , Scheme_Object * obj2 ) {
  static int equal_counter = 20 ; 
  Scheme_Config * __funcarg4 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(obj2, 0), PUSH(obj1, 1)));
# define XfOrM19_COUNT (2)
# define SETUP_XfOrM19(x) SETUP(XfOrM19_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  top : if ((scheme_eqv (obj1 , obj2 ) ) )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  else if (((Scheme_Type ) (((((long ) (obj1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj1 ) ) -> type ) ) != (Scheme_Type ) (((((long ) (obj2 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj2 ) ) -> type ) ) ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  else if (((Scheme_Type ) (((((long ) (obj1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj1 ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#   define XfOrM53_COUNT (0+XfOrM19_COUNT)
#   define SETUP_XfOrM53(x) SETUP_XfOrM19(x)
    if (! -- equal_counter ) {
#     define XfOrM55_COUNT (0+XfOrM53_COUNT)
#     define SETUP_XfOrM55(x) SETUP_XfOrM53(x)
      equal_counter = 20 ; 
      {
#       define XfOrM58_COUNT (0+XfOrM55_COUNT)
#       define SETUP_XfOrM58(x) SETUP_XfOrM55(x)
        if ((scheme_fuel_counter ) <= 0 ) {
#         define XfOrM59_COUNT (0+XfOrM58_COUNT)
#         define SETUP_XfOrM59(x) SETUP_XfOrM58(x)
          FUNCCALL(SETUP_XfOrM59(_), scheme_out_of_fuel () ); 
        }
      }
      ; 
      {
        unsigned long _stk_pos ; 
#       define XfOrM56_COUNT (0+XfOrM55_COUNT)
#       define SETUP_XfOrM56(x) SETUP_XfOrM55(x)
        _stk_pos = (unsigned long ) & _stk_pos ; 
        if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
          Scheme_Thread * p = scheme_current_thread ; 
#         define XfOrM57_COUNT (0+XfOrM56_COUNT)
#         define SETUP_XfOrM57(x) SETUP_XfOrM56(x)
          p -> ku . k . p1 = (void * ) obj1 ; 
          p -> ku . k . p2 = (void * ) obj2 ; 
          RET_VALUE_START ((! (((FUNCCALL(SETUP_XfOrM57(_), scheme_handle_stack_overflow (equal_k ) )) ) == (scheme_false ) ) ) ) RET_VALUE_END ; 
        }
      }
    }
    if (FUNCCALL(SETUP_XfOrM53(_), scheme_equal ((((Scheme_Simple_Object * ) (obj1 ) ) -> u . pair_val . car ) , (((Scheme_Simple_Object * ) (obj2 ) ) -> u . pair_val . car ) ) )) {
      obj1 = (((Scheme_Simple_Object * ) (obj1 ) ) -> u . pair_val . cdr ) ; 
      obj2 = (((Scheme_Simple_Object * ) (obj2 ) ) -> u . pair_val . cdr ) ; 
      goto top ; 
    }
    else RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  else if (((Scheme_Type ) (((((long ) (obj1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj1 ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
#   define XfOrM47_COUNT (0+XfOrM19_COUNT)
#   define SETUP_XfOrM47(x) SETUP_XfOrM19(x)
    if (! -- equal_counter ) {
#     define XfOrM48_COUNT (0+XfOrM47_COUNT)
#     define SETUP_XfOrM48(x) SETUP_XfOrM47(x)
      equal_counter = 20 ; 
      {
#       define XfOrM51_COUNT (0+XfOrM48_COUNT)
#       define SETUP_XfOrM51(x) SETUP_XfOrM48(x)
        if ((scheme_fuel_counter ) <= 0 ) {
#         define XfOrM52_COUNT (0+XfOrM51_COUNT)
#         define SETUP_XfOrM52(x) SETUP_XfOrM51(x)
          FUNCCALL(SETUP_XfOrM52(_), scheme_out_of_fuel () ); 
        }
      }
      ; 
      {
        unsigned long _stk_pos ; 
#       define XfOrM49_COUNT (0+XfOrM48_COUNT)
#       define SETUP_XfOrM49(x) SETUP_XfOrM48(x)
        _stk_pos = (unsigned long ) & _stk_pos ; 
        if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
          Scheme_Thread * p = scheme_current_thread ; 
#         define XfOrM50_COUNT (0+XfOrM49_COUNT)
#         define SETUP_XfOrM50(x) SETUP_XfOrM49(x)
          p -> ku . k . p1 = (void * ) obj1 ; 
          p -> ku . k . p2 = (void * ) obj2 ; 
          RET_VALUE_START ((! (((FUNCCALL(SETUP_XfOrM50(_), scheme_handle_stack_overflow (equal_k ) )) ) == (scheme_false ) ) ) ) RET_VALUE_END ; 
        }
      }
    }
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(vector_equal (obj1 , obj2 ) )) RET_VALUE_EMPTY_END ; 
  }
  else if (((Scheme_Type ) (((((long ) (obj1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj1 ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) || ((((((long ) (obj1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj1 ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (obj1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj1 ) ) -> type ) <= scheme_windows_path_type ) ) ) {
    int l1 , l2 ; 
#   define XfOrM46_COUNT (0+XfOrM19_COUNT)
#   define SETUP_XfOrM46(x) SETUP_XfOrM19(x)
    l1 = (((Scheme_Simple_Object * ) (obj1 ) ) -> u . byte_str_val . tag_val ) ; 
    l2 = (((Scheme_Simple_Object * ) (obj2 ) ) -> u . byte_str_val . tag_val ) ; 
    RET_VALUE_START (((l1 == l2 ) && ! (memcmp ((((Scheme_Simple_Object * ) (obj1 ) ) -> u . byte_str_val . string_val ) , (((Scheme_Simple_Object * ) (obj2 ) ) -> u . byte_str_val . string_val ) , l1 ) ) ) ) RET_VALUE_END ; 
  }
  else if (((Scheme_Type ) (((((long ) (obj1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj1 ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) ) {
    int l1 , l2 ; 
#   define XfOrM45_COUNT (0+XfOrM19_COUNT)
#   define SETUP_XfOrM45(x) SETUP_XfOrM19(x)
    l1 = (((Scheme_Simple_Object * ) (obj1 ) ) -> u . char_str_val . tag_val ) ; 
    l2 = (((Scheme_Simple_Object * ) (obj2 ) ) -> u . char_str_val . tag_val ) ; 
    RET_VALUE_START (((l1 == l2 ) && ! (memcmp ((((Scheme_Simple_Object * ) (obj1 ) ) -> u . char_str_val . string_val ) , (((Scheme_Simple_Object * ) (obj2 ) ) -> u . char_str_val . string_val ) , l1 * sizeof (mzchar ) ) ) ) ) RET_VALUE_END ; 
  }
  else if ((((Scheme_Type ) (((((long ) (obj1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj1 ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (obj1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj1 ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) ) {
#   define XfOrM37_COUNT (0+XfOrM19_COUNT)
#   define SETUP_XfOrM37(x) SETUP_XfOrM19(x)
    if ((((Scheme_Structure * ) obj1 ) -> stype ) != (((Scheme_Structure * ) obj2 ) -> stype ) )
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    else {
      Scheme_Object * insp ; 
      BLOCK_SETUP((PUSH(insp, 0+XfOrM37_COUNT)));
#     define XfOrM38_COUNT (1+XfOrM37_COUNT)
#     define SETUP_XfOrM38(x) SETUP(XfOrM38_COUNT)
      insp = NULLED_OUT ; 
      insp = (__funcarg4 = FUNCCALL(SETUP_XfOrM38(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg4 , MZCONFIG_INSPECTOR ) )) ; 
      if (FUNCCALL(SETUP_XfOrM38(_), scheme_inspector_sees_part (obj1 , insp , - 2 ) )&& FUNCCALL(SETUP_XfOrM38(_), scheme_inspector_sees_part (obj2 , insp , - 2 ) )) {
#       define XfOrM39_COUNT (0+XfOrM38_COUNT)
#       define SETUP_XfOrM39(x) SETUP_XfOrM38(x)
        if (! -- equal_counter ) {
#         define XfOrM40_COUNT (0+XfOrM39_COUNT)
#         define SETUP_XfOrM40(x) SETUP_XfOrM39(x)
          equal_counter = 20 ; 
          {
#           define XfOrM43_COUNT (0+XfOrM40_COUNT)
#           define SETUP_XfOrM43(x) SETUP_XfOrM40(x)
            if ((scheme_fuel_counter ) <= 0 ) {
#             define XfOrM44_COUNT (0+XfOrM43_COUNT)
#             define SETUP_XfOrM44(x) SETUP_XfOrM43(x)
              FUNCCALL(SETUP_XfOrM44(_), scheme_out_of_fuel () ); 
            }
          }
          ; 
          {
            unsigned long _stk_pos ; 
#           define XfOrM41_COUNT (0+XfOrM40_COUNT)
#           define SETUP_XfOrM41(x) SETUP_XfOrM40(x)
            _stk_pos = (unsigned long ) & _stk_pos ; 
            if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
              Scheme_Thread * p = scheme_current_thread ; 
#             define XfOrM42_COUNT (0+XfOrM41_COUNT)
#             define SETUP_XfOrM42(x) SETUP_XfOrM41(x)
              p -> ku . k . p1 = (void * ) obj1 ; 
              p -> ku . k . p2 = (void * ) obj2 ; 
              RET_VALUE_START ((! (((FUNCCALL(SETUP_XfOrM42(_), scheme_handle_stack_overflow (equal_k ) )) ) == (scheme_false ) ) ) ) RET_VALUE_END ; 
            }
          }
        }
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(struct_equal (obj1 , obj2 ) )) RET_VALUE_EMPTY_END ; 
      }
      else RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
  }
  else if (((Scheme_Type ) (((((long ) (obj1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj1 ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) {
#   define XfOrM34_COUNT (0+XfOrM19_COUNT)
#   define SETUP_XfOrM34(x) SETUP_XfOrM19(x)
    {
#     define XfOrM35_COUNT (0+XfOrM34_COUNT)
#     define SETUP_XfOrM35(x) SETUP_XfOrM34(x)
      if ((scheme_fuel_counter ) <= 0 ) {
#       define XfOrM36_COUNT (0+XfOrM35_COUNT)
#       define SETUP_XfOrM36(x) SETUP_XfOrM35(x)
        FUNCCALL(SETUP_XfOrM36(_), scheme_out_of_fuel () ); 
      }
    }
    ; 
    obj1 = (((Scheme_Small_Object * ) (obj1 ) ) -> u . ptr_val ) ; 
    obj2 = (((Scheme_Small_Object * ) (obj2 ) ) -> u . ptr_val ) ; 
    goto top ; 
  }
  else if (((Scheme_Type ) (((((long ) (obj1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj1 ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) ) {
#   define XfOrM28_COUNT (0+XfOrM19_COUNT)
#   define SETUP_XfOrM28(x) SETUP_XfOrM19(x)
    if (! -- equal_counter ) {
#     define XfOrM29_COUNT (0+XfOrM28_COUNT)
#     define SETUP_XfOrM29(x) SETUP_XfOrM28(x)
      equal_counter = 20 ; 
      {
#       define XfOrM32_COUNT (0+XfOrM29_COUNT)
#       define SETUP_XfOrM32(x) SETUP_XfOrM29(x)
        if ((scheme_fuel_counter ) <= 0 ) {
#         define XfOrM33_COUNT (0+XfOrM32_COUNT)
#         define SETUP_XfOrM33(x) SETUP_XfOrM32(x)
          FUNCCALL(SETUP_XfOrM33(_), scheme_out_of_fuel () ); 
        }
      }
      ; 
      {
        unsigned long _stk_pos ; 
#       define XfOrM30_COUNT (0+XfOrM29_COUNT)
#       define SETUP_XfOrM30(x) SETUP_XfOrM29(x)
        _stk_pos = (unsigned long ) & _stk_pos ; 
        if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
          Scheme_Thread * p = scheme_current_thread ; 
#         define XfOrM31_COUNT (0+XfOrM30_COUNT)
#         define SETUP_XfOrM31(x) SETUP_XfOrM30(x)
          p -> ku . k . p1 = (void * ) obj1 ; 
          p -> ku . k . p2 = (void * ) obj2 ; 
          RET_VALUE_START ((! (((FUNCCALL(SETUP_XfOrM31(_), scheme_handle_stack_overflow (equal_k ) )) ) == (scheme_false ) ) ) ) RET_VALUE_END ; 
        }
      }
    }
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_hash_table_equal ((Scheme_Hash_Table * ) obj1 , (Scheme_Hash_Table * ) obj2 ) )) RET_VALUE_EMPTY_END ; 
  }
  else if (((Scheme_Type ) (((((long ) (obj1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj1 ) ) -> type ) ) == (Scheme_Type ) (scheme_bucket_table_type ) ) ) {
#   define XfOrM22_COUNT (0+XfOrM19_COUNT)
#   define SETUP_XfOrM22(x) SETUP_XfOrM19(x)
    if (! -- equal_counter ) {
#     define XfOrM23_COUNT (0+XfOrM22_COUNT)
#     define SETUP_XfOrM23(x) SETUP_XfOrM22(x)
      equal_counter = 20 ; 
      {
#       define XfOrM26_COUNT (0+XfOrM23_COUNT)
#       define SETUP_XfOrM26(x) SETUP_XfOrM23(x)
        if ((scheme_fuel_counter ) <= 0 ) {
#         define XfOrM27_COUNT (0+XfOrM26_COUNT)
#         define SETUP_XfOrM27(x) SETUP_XfOrM26(x)
          FUNCCALL(SETUP_XfOrM27(_), scheme_out_of_fuel () ); 
        }
      }
      ; 
      {
        unsigned long _stk_pos ; 
#       define XfOrM24_COUNT (0+XfOrM23_COUNT)
#       define SETUP_XfOrM24(x) SETUP_XfOrM23(x)
        _stk_pos = (unsigned long ) & _stk_pos ; 
        if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
          Scheme_Thread * p = scheme_current_thread ; 
#         define XfOrM25_COUNT (0+XfOrM24_COUNT)
#         define SETUP_XfOrM25(x) SETUP_XfOrM24(x)
          p -> ku . k . p1 = (void * ) obj1 ; 
          p -> ku . k . p2 = (void * ) obj2 ; 
          RET_VALUE_START ((! (((FUNCCALL(SETUP_XfOrM25(_), scheme_handle_stack_overflow (equal_k ) )) ) == (scheme_false ) ) ) ) RET_VALUE_END ; 
        }
      }
    }
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_bucket_table_equal ((Scheme_Bucket_Table * ) obj1 , (Scheme_Bucket_Table * ) obj2 ) )) RET_VALUE_EMPTY_END ; 
  }
  else if (((Scheme_Type ) (((((long ) (obj1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj1 ) ) -> type ) ) == (Scheme_Type ) (scheme_wrap_chunk_type ) ) ) {
#   define XfOrM21_COUNT (0+XfOrM19_COUNT)
#   define SETUP_XfOrM21(x) SETUP_XfOrM19(x)
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(vector_equal (obj1 , obj2 ) )) RET_VALUE_EMPTY_END ; 
  }
  else {
    Scheme_Equal_Proc eql = scheme_type_equals [((((long ) (obj1 ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj1 ) ) -> type ) ] ; 
#   define XfOrM20_COUNT (0+XfOrM19_COUNT)
#   define SETUP_XfOrM20(x) SETUP_XfOrM19(x)
    if (eql )
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(eql (obj1 , obj2 ) )) RET_VALUE_EMPTY_END ; 
    else RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int vector_equal (Scheme_Object * vec1 , Scheme_Object * vec2 ) {
  int i , len ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(vec1, 0), PUSH(vec2, 1)));
# define XfOrM60_COUNT (2)
# define SETUP_XfOrM60(x) SETUP(XfOrM60_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  len = (((Scheme_Vector * ) (vec1 ) ) -> size ) ; 
  if (len != (((Scheme_Vector * ) (vec2 ) ) -> size ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  {
#   define XfOrM63_COUNT (0+XfOrM60_COUNT)
#   define SETUP_XfOrM63(x) SETUP_XfOrM60(x)
    if ((scheme_fuel_counter ) <= 0 ) {
#     define XfOrM64_COUNT (0+XfOrM63_COUNT)
#     define SETUP_XfOrM64(x) SETUP_XfOrM63(x)
      FUNCCALL(SETUP_XfOrM64(_), scheme_out_of_fuel () ); 
    }
  }
  ; 
  for (i = 0 ; i < len ; i ++ ) {
#   define XfOrM62_COUNT (0+XfOrM60_COUNT)
#   define SETUP_XfOrM62(x) SETUP_XfOrM60(x)
    if (! FUNCCALL(SETUP_XfOrM62(_), scheme_equal ((((Scheme_Vector * ) (vec1 ) ) -> els ) [i ] , (((Scheme_Vector * ) (vec2 ) ) -> els ) [i ] ) ))
      RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  RET_VALUE_START (1 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int struct_equal (Scheme_Object * obj1 , Scheme_Object * obj2 ) {
  Scheme_Structure * s1 , * s2 ; 
  int i ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(s2, 0), PUSH(s1, 1)));
# define XfOrM65_COUNT (2)
# define SETUP_XfOrM65(x) SETUP(XfOrM65_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s1 = NULLED_OUT ; 
  s2 = NULLED_OUT ; 
  s1 = (Scheme_Structure * ) obj1 ; 
  s2 = (Scheme_Structure * ) obj2 ; 
  for (i = ((((Scheme_Structure * ) s1 ) -> stype ) -> num_slots ) ; i -- ; ) {
#   define XfOrM67_COUNT (0+XfOrM65_COUNT)
#   define SETUP_XfOrM67(x) SETUP_XfOrM65(x)
    if (! FUNCCALL(SETUP_XfOrM67(_), scheme_equal (s1 -> slots [i ] , s2 -> slots [i ] ) ))
      RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  RET_VALUE_START (1 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_true (void ) {
  /* No conversion */
  return scheme_true ; 
}
Scheme_Object * scheme_make_false (void ) {
  /* No conversion */
  return scheme_false ; 
}
