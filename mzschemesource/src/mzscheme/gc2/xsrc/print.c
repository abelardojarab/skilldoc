#include "precomp.h"
enum {
  CPT_ESCAPE , CPT_SYMBOL , CPT_SYMREF , CPT_WEIRD_SYMBOL , CPT_KEYWORD , CPT_BYTE_STRING , CPT_CHAR_STRING , CPT_CHAR , CPT_INT , CPT_NULL , CPT_TRUE , CPT_FALSE , CPT_VOID , CPT_BOX , CPT_PAIR , CPT_LIST , CPT_VECTOR , CPT_HASH_TABLE , CPT_STX , CPT_GSTX , CPT_MARSHALLED , CPT_QUOTE , CPT_REFERENCE , CPT_LOCAL , CPT_LOCAL_UNBOX , CPT_SVECTOR , CPT_APPLICATION , CPT_LET_ONE , CPT_BRANCH , CPT_MODULE_INDEX , CPT_MODULE_VAR , CPT_PATH , CPT_CLOSURE , CPT_DELAY_REF , _CPT_COUNT_ }
; 
enum {
  _ISupper = ((0 ) < 8 ? ((1 << (0 ) ) << 8 ) : ((1 << (0 ) ) >> 8 ) ) , _ISlower = ((1 ) < 8 ? ((1 << (1 ) ) << 8 ) : ((1 << (1 ) ) >> 8 ) ) , _ISalpha = ((2 ) < 8 ? ((1 << (2 ) ) << 8 ) : ((1 << (2 ) ) >> 8 ) ) , _ISdigit = ((3 ) < 8 ? ((1 << (3 ) ) << 8 ) : ((1 << (3 ) ) >> 8 ) ) , _ISxdigit = ((4 ) < 8 ? ((1 << (4 ) ) << 8 ) : ((1 << (4 ) ) >> 8 ) ) , _ISspace = ((5 ) < 8 ? ((1 << (5 ) ) << 8 ) : ((1 << (5 ) ) >> 8 ) ) , _ISprint = ((6 ) < 8 ? ((1 << (6 ) ) << 8 ) : ((1 << (6 ) ) >> 8 ) ) , _ISgraph = ((7 ) < 8 ? ((1 << (7 ) ) << 8 ) : ((1 << (7 ) ) >> 8 ) ) , _ISblank = ((8 ) < 8 ? ((1 << (8 ) ) << 8 ) : ((1 << (8 ) ) >> 8 ) ) , _IScntrl = ((9 ) < 8 ? ((1 << (9 ) ) << 8 ) : ((1 << (9 ) ) >> 8 ) ) , _ISpunct = ((10 ) < 8 ? ((1 << (10 ) ) << 8 ) : ((1 << (10 ) ) >> 8 ) ) , _ISalnum = ((11 ) < 8 ? ((1 << (11 ) ) << 8 ) : ((1 << (11 ) ) >> 8 ) ) }
; 
int (* scheme_check_print_is_obj ) (Scheme_Object * o ) ; 
typedef struct Scheme_Print_Params {
  Scheme_Type type ; 
  char print_struct ; 
  char print_graph ; 
  char print_box ; 
  char print_vec_shorthand ; 
  char print_hash_table ; 
  char print_unreadable ; 
  char can_read_pipe_quote ; 
  char case_sens ; 
  char honu_mode ; 
  Scheme_Object * inspector ; 
  char * print_buffer ; 
  long print_position ; 
  long print_allocated ; 
  long print_maxlen ; 
  long print_offset ; 
  Scheme_Object * print_port ; 
  mz_jmp_buf * print_escape ; 
}
PrintParams ; 
static void register_traversers (void ) ; 
static void print_to_port (char * name , Scheme_Object * obj , Scheme_Object * port , int notdisplay , long maxl , int check_honu ) ; 
static int print (Scheme_Object * obj , int notdisplay , int compact , Scheme_Hash_Table * ht , Scheme_Marshal_Tables * mt , PrintParams * p ) ; 
static void print_char_string (const char * s , int l , const mzchar * us , int delta , int ul , int notdisplay , int honu_char , PrintParams * pp ) ; 
static void print_byte_string (const char * s , int delta , int l , int notdisplay , PrintParams * pp ) ; 
static void print_pair (Scheme_Object * pair , int notdisplay , int compact , Scheme_Hash_Table * ht , Scheme_Marshal_Tables * mt , PrintParams * pp ) ; 
static void print_vector (Scheme_Object * vec , int notdisplay , int compact , Scheme_Hash_Table * ht , Scheme_Marshal_Tables * mt , PrintParams * pp ) ; 
static void print_char (Scheme_Object * chobj , int notdisplay , PrintParams * pp ) ; 
static char * print_to_string (Scheme_Object * obj , long * volatile len , int write , Scheme_Object * port , long maxl , int check_honu ) ; 
static void custom_write_struct (Scheme_Object * s , Scheme_Hash_Table * ht , Scheme_Marshal_Tables * mt , PrintParams * pp , int notdisplay ) ; 
static Scheme_Object * writable_struct_subs (Scheme_Object * s , PrintParams * pp ) ; 
static Scheme_Object * quote_link_symbol = ((void * ) 0 ) ; 
static char * quick_buffer = ((void * ) 0 ) ; 
static char * quick_encode_buffer = ((void * ) 0 ) ; 
static Scheme_Type_Printer * printers ; 
static int printers_count ; 
static char compacts [_CPT_COUNT_ ] ; 
static Scheme_Hash_Table * global_constants_ht ; 
static Scheme_Hash_Table * cache_ht ; 
void scheme_init_print (Scheme_Env * env ) {
  /* No conversion */
  int i ; 
  scheme_register_static ((void * ) & quick_buffer , sizeof (quick_buffer ) ) ; 
  scheme_register_static ((void * ) & quick_encode_buffer , sizeof (quick_encode_buffer ) ) ; 
  quick_buffer = (char * ) GC_malloc_atomic (100 ) ; 
  quick_encode_buffer = (char * ) GC_malloc_atomic (256 ) ; 
  scheme_register_static ((void * ) & quote_link_symbol , sizeof (quote_link_symbol ) ) ; 
  quote_link_symbol = scheme_intern_symbol ("-q" ) ; 
  for (i = 0 ; i < _CPT_COUNT_ ; i ++ ) {
    compacts [i ] = i ; 
  }
  register_traversers () ; 
  scheme_register_static ((void * ) & cache_ht , sizeof (cache_ht ) ) ; 
}
Scheme_Object * scheme_make_svector (mzshort c , mzshort * a ) {
  Scheme_Object * o ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(a, 0), PUSH(o, 1)));
# define XfOrM4_COUNT (2)
# define SETUP_XfOrM4(x) SETUP(XfOrM4_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  o = NULLED_OUT ; 
  o = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM4(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  o -> type = scheme_svector_type ; 
  (((Scheme_Simple_Object * ) (o ) ) -> u . svector_val . len ) = c ; 
  (((Scheme_Simple_Object * ) (o ) ) -> u . svector_val . vec ) = a ; 
  RET_VALUE_START (o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
PrintParams * copy_print_params (PrintParams * pp ) {
  PrintParams * pp2 ; 
  DECL_RET_SAVE (PrintParams * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(pp, 0), PUSH(pp2, 1)));
# define XfOrM5_COUNT (2)
# define SETUP_XfOrM5(x) SETUP(XfOrM5_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  pp2 = NULLED_OUT ; 
  pp2 = ((PrintParams * ) FUNCCALL(SETUP_XfOrM5(_), GC_malloc_one_small_tagged ((((sizeof (PrintParams ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  (memcpy (pp2 , pp , sizeof (PrintParams ) ) ) ; 
  pp2 -> type = scheme_rt_print_params ; 
  RET_VALUE_START (pp2 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_debug_print (Scheme_Object * obj ) {
  /* No conversion */
  scheme_write (obj , scheme_orig_stdout_port ) ; 
  fflush (stdout ) ; 
}
static void * print_to_port_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * obj , * port ; 
  port = (Scheme_Object * ) p -> ku . k . p1 ; 
  obj = (Scheme_Object * ) p -> ku . k . p2 ; 
  print_to_port (p -> ku . k . i2 ? "write" : "display" , obj , port , p -> ku . k . i2 , p -> ku . k . i1 , p -> ku . k . i3 ) ; 
  return ((void * ) 0 ) ; 
}
static void do_handled_print (Scheme_Object * obj , Scheme_Object * port , Scheme_Object * proc , long maxl ) {
  Scheme_Object * a [2 ] ; 
  PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 2, 0), PUSH(port, 3)));
# define XfOrM8_COUNT (4)
# define SETUP_XfOrM8(x) SETUP(XfOrM8_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  a [0 ] = obj ; 
  if (maxl > 0 ) {
#   define XfOrM10_COUNT (0+XfOrM8_COUNT)
#   define SETUP_XfOrM10(x) SETUP_XfOrM8(x)
    a [1 ] = FUNCCALL(SETUP_XfOrM10(_), scheme_make_byte_string_output_port () ); 
  }
  else a [1 ] = port ; 
  FUNCCALL(SETUP_XfOrM8(_), scheme_apply_multi (scheme_write_proc , 2 , a ) ); 
  if (maxl > 0 ) {
    char * s ; 
    long len ; 
    BLOCK_SETUP((PUSH(s, 0+XfOrM8_COUNT)));
#   define XfOrM9_COUNT (1+XfOrM8_COUNT)
#   define SETUP_XfOrM9(x) SETUP(XfOrM9_COUNT)
    s = NULLED_OUT ; 
    s = FUNCCALL(SETUP_XfOrM9(_), scheme_get_sized_byte_string_output (a [1 ] , & len ) ); 
    if (len > maxl )
      len = maxl ; 
    FUNCCALL(SETUP_XfOrM9(_), scheme_write_byte_string (s , len , port ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_write_w_max (Scheme_Object * obj , Scheme_Object * port , long maxl ) {
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(obj, 0), PUSH(port, 1)));
# define XfOrM11_COUNT (2)
# define SETUP_XfOrM11(x) SETUP(XfOrM11_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (((Scheme_Output_Port * ) port ) -> write_handler )
    FUNCCALL(SETUP_XfOrM11(_), do_handled_print (obj , port , scheme_write_proc , maxl ) ); 
  else {
    Scheme_Thread * p = scheme_current_thread ; 
#   define XfOrM12_COUNT (0+XfOrM11_COUNT)
#   define SETUP_XfOrM12(x) SETUP_XfOrM11(x)
    p -> ku . k . p1 = port ; 
    p -> ku . k . p2 = obj ; 
    p -> ku . k . i1 = maxl ; 
    p -> ku . k . i2 = 1 ; 
    p -> ku . k . i3 = 0 ; 
    (void ) FUNCCALL_EMPTY(scheme_top_level_do (print_to_port_k , 0 ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_write (Scheme_Object * obj , Scheme_Object * port ) {
  /* No conversion */
  scheme_write_w_max (obj , port , - 1 ) ; 
}
void scheme_display_w_max (Scheme_Object * obj , Scheme_Object * port , long maxl ) {
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(obj, 0), PUSH(port, 1)));
# define XfOrM14_COUNT (2)
# define SETUP_XfOrM14(x) SETUP(XfOrM14_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (((Scheme_Output_Port * ) port ) -> display_handler )
    FUNCCALL(SETUP_XfOrM14(_), do_handled_print (obj , port , scheme_display_proc , maxl ) ); 
  else {
    Scheme_Thread * p = scheme_current_thread ; 
#   define XfOrM15_COUNT (0+XfOrM14_COUNT)
#   define SETUP_XfOrM15(x) SETUP_XfOrM14(x)
    p -> ku . k . p1 = port ; 
    p -> ku . k . p2 = obj ; 
    p -> ku . k . i1 = maxl ; 
    p -> ku . k . i2 = 0 ; 
    p -> ku . k . i3 = 0 ; 
    (void ) FUNCCALL_EMPTY(scheme_top_level_do (print_to_port_k , 0 ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_display (Scheme_Object * obj , Scheme_Object * port ) {
  /* No conversion */
  scheme_display_w_max (obj , port , - 1 ) ; 
}
void scheme_print_w_max (Scheme_Object * obj , Scheme_Object * port , long maxl ) {
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(obj, 0), PUSH(port, 1)));
# define XfOrM17_COUNT (2)
# define SETUP_XfOrM17(x) SETUP(XfOrM17_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (((Scheme_Output_Port * ) port ) -> print_handler )
    FUNCCALL(SETUP_XfOrM17(_), do_handled_print (obj , port , scheme_print_proc , maxl ) ); 
  else {
    Scheme_Thread * p = scheme_current_thread ; 
#   define XfOrM18_COUNT (0+XfOrM17_COUNT)
#   define SETUP_XfOrM18(x) SETUP_XfOrM17(x)
    p -> ku . k . p1 = port ; 
    p -> ku . k . p2 = obj ; 
    p -> ku . k . i1 = maxl ; 
    p -> ku . k . i2 = 1 ; 
    p -> ku . k . i3 = 1 ; 
    (void ) FUNCCALL_EMPTY(scheme_top_level_do (print_to_port_k , 0 ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_print (Scheme_Object * obj , Scheme_Object * port ) {
  /* No conversion */
  scheme_print_w_max (obj , port , - 1 ) ; 
}
static void * print_to_string_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * obj ; 
  long * len , maxl ; 
  int iswrite , check_honu ; 
  obj = (Scheme_Object * ) p -> ku . k . p1 ; 
  len = (long * ) (void * ) p -> ku . k . p2 ; 
  maxl = p -> ku . k . i1 ; 
  iswrite = p -> ku . k . i2 ; 
  check_honu = p -> ku . k . i3 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  p -> ku . k . p2 = ((void * ) 0 ) ; 
  return (void * ) print_to_string (obj , len , iswrite , ((void * ) 0 ) , maxl , check_honu ) ; 
}
char * scheme_write_to_string_w_max (Scheme_Object * obj , long * len , long maxl ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  p -> ku . k . p1 = obj ; 
  p -> ku . k . p2 = len ; 
  p -> ku . k . i1 = maxl ; 
  p -> ku . k . i2 = 1 ; 
  p -> ku . k . i3 = 0 ; 
  return (char * ) scheme_top_level_do (print_to_string_k , 0 ) ; 
}
char * scheme_write_to_string (Scheme_Object * obj , long * len ) {
  /* No conversion */
  return scheme_write_to_string_w_max (obj , len , - 1 ) ; 
}
char * scheme_display_to_string_w_max (Scheme_Object * obj , long * len , long maxl ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  p -> ku . k . p1 = obj ; 
  p -> ku . k . p2 = len ; 
  p -> ku . k . i1 = maxl ; 
  p -> ku . k . i2 = 0 ; 
  p -> ku . k . i3 = 0 ; 
  return (char * ) scheme_top_level_do (print_to_string_k , 0 ) ; 
}
char * scheme_display_to_string (Scheme_Object * obj , long * len ) {
  /* No conversion */
  return scheme_display_to_string_w_max (obj , len , - 1 ) ; 
}
char * scheme_print_to_string_w_max (Scheme_Object * obj , long * len , long maxl ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  p -> ku . k . p1 = obj ; 
  p -> ku . k . p2 = len ; 
  p -> ku . k . i1 = maxl ; 
  p -> ku . k . i2 = 1 ; 
  p -> ku . k . i3 = 1 ; 
  return (char * ) scheme_top_level_do (print_to_string_k , 0 ) ; 
}
char * scheme_print_to_string (Scheme_Object * obj , long * len ) {
  /* No conversion */
  return scheme_print_to_string_w_max (obj , len , - 1 ) ; 
}
void scheme_internal_write (Scheme_Object * obj , Scheme_Object * port ) {
  /* No conversion */
  print_to_port ("write" , obj , port , 1 , - 1 , 0 ) ; 
}
void scheme_internal_display (Scheme_Object * obj , Scheme_Object * port ) {
  /* No conversion */
  print_to_port ("display" , obj , port , 0 , - 1 , 0 ) ; 
}
void scheme_internal_print (Scheme_Object * obj , Scheme_Object * port ) {
  /* No conversion */
  print_to_port ("print" , obj , port , 1 , - 1 , 1 ) ; 
}
static int check_cycles (Scheme_Object * , Scheme_Hash_Table * ht , PrintParams * ) ; 
static Scheme_Object * check_cycle_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * o = (Scheme_Object * ) p -> ku . k . p1 ; 
  Scheme_Hash_Table * ht = (Scheme_Hash_Table * ) p -> ku . k . p2 ; 
  PrintParams * pp = (PrintParams * ) p -> ku . k . p3 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  p -> ku . k . p2 = ((void * ) 0 ) ; 
  p -> ku . k . p3 = ((void * ) 0 ) ; 
  return check_cycles (o , ht , pp ) ? scheme_true : scheme_false ; 
}
static int check_cycles (Scheme_Object * obj , Scheme_Hash_Table * ht , PrintParams * pp ) {
  Scheme_Type t ; 
  Scheme_Object * __funcarg4 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(obj, 0), PUSH(pp, 1), PUSH(ht, 2)));
# define XfOrM31_COUNT (3)
# define SETUP_XfOrM31(x) SETUP(XfOrM31_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  {
    unsigned long _stk_pos ; 
#   define XfOrM56_COUNT (0+XfOrM31_COUNT)
#   define SETUP_XfOrM56(x) SETUP_XfOrM31(x)
    _stk_pos = (unsigned long ) & _stk_pos ; 
    if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
#     define XfOrM57_COUNT (0+XfOrM56_COUNT)
#     define SETUP_XfOrM57(x) SETUP_XfOrM56(x)
      pp = FUNCCALL(SETUP_XfOrM57(_), copy_print_params (pp ) ); 
      scheme_current_thread -> ku . k . p1 = (void * ) obj ; 
      scheme_current_thread -> ku . k . p2 = (void * ) ht ; 
      scheme_current_thread -> ku . k . p3 = (void * ) pp ; 
      RET_VALUE_START ((! (((FUNCCALL(SETUP_XfOrM57(_), scheme_handle_stack_overflow (check_cycle_k ) )) ) == (scheme_false ) ) ) ) RET_VALUE_END ; 
    }
  }
  {
#   define XfOrM54_COUNT (0+XfOrM31_COUNT)
#   define SETUP_XfOrM54(x) SETUP_XfOrM31(x)
    if ((scheme_fuel_counter ) <= 0 ) {
#     define XfOrM55_COUNT (0+XfOrM54_COUNT)
#     define SETUP_XfOrM55(x) SETUP_XfOrM54(x)
      FUNCCALL(SETUP_XfOrM55(_), scheme_out_of_fuel () ); 
    }
  }
  ; 
  t = ((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ; 
  if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (pp -> print_box && ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) || ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) || ((((Scheme_Type ) (t ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (t ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) && ((pp -> print_struct && (FUNCCALL(SETUP_XfOrM31(_), scheme_inspector_sees_part (obj , pp -> inspector , - 1 ) )) ) || FUNCCALL(SETUP_XfOrM31(_), scheme_is_writable_struct (obj ) )) ) || (pp -> print_hash_table && ((Scheme_Type ) (t ) == (Scheme_Type ) (scheme_hash_table_type ) ) ) ) {
#   define XfOrM53_COUNT (0+XfOrM31_COUNT)
#   define SETUP_XfOrM53(x) SETUP_XfOrM31(x)
    if (FUNCCALL(SETUP_XfOrM53(_), scheme_hash_get (ht , obj ) ))
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    FUNCCALL(SETUP_XfOrM53(_), scheme_hash_set (ht , obj , (Scheme_Object * ) 0x1 ) ); 
  }
  else RET_VALUE_START (0 ) RET_VALUE_END ; 
  if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#   define XfOrM52_COUNT (0+XfOrM31_COUNT)
#   define SETUP_XfOrM52(x) SETUP_XfOrM31(x)
    if (FUNCCALL(SETUP_XfOrM52(_), check_cycles ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) , ht , pp ) ))
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    if (FUNCCALL(SETUP_XfOrM52(_), check_cycles ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) , ht , pp ) ))
      RET_VALUE_START (1 ) RET_VALUE_END ; 
  }
  else if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) {
#   define XfOrM51_COUNT (0+XfOrM31_COUNT)
#   define SETUP_XfOrM51(x) SETUP_XfOrM31(x)
    if (FUNCCALL(SETUP_XfOrM51(_), check_cycles ((((Scheme_Small_Object * ) (obj ) ) -> u . ptr_val ) , ht , pp ) ))
      RET_VALUE_START (1 ) RET_VALUE_END ; 
  }
  else if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
    int i , len ; 
#   define XfOrM46_COUNT (0+XfOrM31_COUNT)
#   define SETUP_XfOrM46(x) SETUP_XfOrM31(x)
    len = (((Scheme_Vector * ) (obj ) ) -> size ) ; 
    for (i = 0 ; i < len ; i ++ ) {
#     define XfOrM49_COUNT (0+XfOrM46_COUNT)
#     define SETUP_XfOrM49(x) SETUP_XfOrM46(x)
      if (FUNCCALL(SETUP_XfOrM49(_), check_cycles ((((Scheme_Vector * ) (obj ) ) -> els ) [i ] , ht , pp ) )) {
        RET_VALUE_START (1 ) RET_VALUE_END ; 
      }
    }
  }
  else if (((Scheme_Type ) (t ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (t ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) {
#   define XfOrM37_COUNT (0+XfOrM31_COUNT)
#   define SETUP_XfOrM37(x) SETUP_XfOrM31(x)
    if (FUNCCALL(SETUP_XfOrM37(_), scheme_is_writable_struct (obj ) )) {
#     define XfOrM45_COUNT (0+XfOrM37_COUNT)
#     define SETUP_XfOrM45(x) SETUP_XfOrM37(x)
      if ((__funcarg4 = FUNCCALL(SETUP_XfOrM45(_), writable_struct_subs (obj , pp ) ), FUNCCALL_AGAIN(check_cycles (__funcarg4 , ht , pp ) )) )
        RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
    else {
      int i = ((((Scheme_Structure * ) obj ) -> stype ) -> num_slots ) ; 
#     define XfOrM38_COUNT (0+XfOrM37_COUNT)
#     define SETUP_XfOrM38(x) SETUP_XfOrM37(x)
      while (i -- ) {
#       define XfOrM42_COUNT (0+XfOrM38_COUNT)
#       define SETUP_XfOrM42(x) SETUP_XfOrM38(x)
        if (FUNCCALL(SETUP_XfOrM42(_), scheme_inspector_sees_part (obj , pp -> inspector , i ) )) {
#         define XfOrM43_COUNT (0+XfOrM42_COUNT)
#         define SETUP_XfOrM43(x) SETUP_XfOrM42(x)
          if (FUNCCALL(SETUP_XfOrM43(_), check_cycles (((Scheme_Structure * ) obj ) -> slots [i ] , ht , pp ) )) {
            RET_VALUE_START (1 ) RET_VALUE_END ; 
          }
        }
      }
    }
  }
  else if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) ) {
    Scheme_Hash_Table * t ; 
    Scheme_Object * * keys , * * vals , * val ; 
    int i ; 
    BLOCK_SETUP((PUSH(vals, 0+XfOrM31_COUNT), PUSH(t, 1+XfOrM31_COUNT), PUSH(val, 2+XfOrM31_COUNT), PUSH(keys, 3+XfOrM31_COUNT)));
#   define XfOrM32_COUNT (4+XfOrM31_COUNT)
#   define SETUP_XfOrM32(x) SETUP(XfOrM32_COUNT)
    t = NULLED_OUT ; 
    keys = NULLED_OUT ; 
    vals = NULLED_OUT ; 
    val = NULLED_OUT ; 
    t = (Scheme_Hash_Table * ) obj ; 
    keys = t -> keys ; 
    vals = t -> vals ; 
    for (i = t -> size ; i -- ; ) {
#     define XfOrM35_COUNT (0+XfOrM32_COUNT)
#     define SETUP_XfOrM35(x) SETUP_XfOrM32(x)
      if (vals [i ] ) {
#       define XfOrM36_COUNT (0+XfOrM35_COUNT)
#       define SETUP_XfOrM36(x) SETUP_XfOrM35(x)
        val = vals [i ] ; 
        if (FUNCCALL(SETUP_XfOrM36(_), check_cycles (keys [i ] , ht , pp ) ))
          RET_VALUE_START (1 ) RET_VALUE_END ; 
        if (FUNCCALL(SETUP_XfOrM36(_), check_cycles (val , ht , pp ) ))
          RET_VALUE_START (1 ) RET_VALUE_END ; 
      }
    }
  }
  FUNCCALL_EMPTY(scheme_hash_set (ht , obj , ((void * ) 0 ) ) ); 
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int fast_checker_counter ; 
static int check_cycles_fast (Scheme_Object * obj , PrintParams * pp ) {
  Scheme_Type t ; 
  int cycle = 0 ; 
  t = ((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ; 
  if (t < 0 )
    return 1 ; 
  if (fast_checker_counter -- < 0 )
    return - 1 ; 
  if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
    obj -> type = - t ; 
    cycle = check_cycles_fast ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) , pp ) ; 
    if (! cycle )
      cycle = check_cycles_fast ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) , pp ) ; 
    obj -> type = t ; 
  }
  else if (pp -> print_box && ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) {
    obj -> type = - t ; 
    cycle = check_cycles_fast ((((Scheme_Small_Object * ) (obj ) ) -> u . ptr_val ) , pp ) ; 
    obj -> type = t ; 
  }
  else if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
    int i , len ; 
    obj -> type = - t ; 
    len = (((Scheme_Vector * ) (obj ) ) -> size ) ; 
    for (i = 0 ; i < len ; i ++ ) {
      cycle = check_cycles_fast ((((Scheme_Vector * ) (obj ) ) -> els ) [i ] , pp ) ; 
      if (cycle )
        break ; 
    }
    obj -> type = t ; 
  }
  else if (((Scheme_Type ) (t ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (t ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) {
    if (scheme_is_writable_struct (obj ) ) {
      if (! pp -> print_unreadable )
        cycle = 0 ; 
      else cycle = - 1 ; 
    }
    else if (pp -> print_struct && (scheme_inspector_sees_part (obj , pp -> inspector , - 1 ) ) ) {
      int i = ((((Scheme_Structure * ) obj ) -> stype ) -> num_slots ) ; 
      obj -> type = - t ; 
      while (i -- ) {
        if (scheme_inspector_sees_part (obj , pp -> inspector , i ) ) {
          cycle = check_cycles_fast (((Scheme_Structure * ) obj ) -> slots [i ] , pp ) ; 
          if (cycle )
            break ; 
        }
      }
      obj -> type = t ; 
    }
    else cycle = 0 ; 
  }
  else if (pp -> print_hash_table && ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) ) {
    if (! ((Scheme_Hash_Table * ) obj ) -> count )
      cycle = 0 ; 
    else cycle = - 1 ; 
  }
  else cycle = 0 ; 
  return cycle ; 
}
static void setup_graph_table (Scheme_Object * obj , Scheme_Hash_Table * ht , int * counter , PrintParams * pp ) ; 
static Scheme_Object * setup_graph_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * o = (Scheme_Object * ) p -> ku . k . p1 ; 
  Scheme_Hash_Table * ht = (Scheme_Hash_Table * ) p -> ku . k . p2 ; 
  int * counter = (int * ) p -> ku . k . p3 ; 
  PrintParams * pp = (PrintParams * ) p -> ku . k . p4 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  p -> ku . k . p2 = ((void * ) 0 ) ; 
  p -> ku . k . p3 = ((void * ) 0 ) ; 
  p -> ku . k . p4 = ((void * ) 0 ) ; 
  setup_graph_table (o , ht , counter , pp ) ; 
  return scheme_false ; 
}
static void setup_graph_table (Scheme_Object * obj , Scheme_Hash_Table * ht , int * counter , PrintParams * pp ) {
  PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(counter, 0), PUSH(obj, 1), PUSH(pp, 2), PUSH(ht, 3)));
# define XfOrM59_COUNT (4)
# define SETUP_XfOrM59(x) SETUP(XfOrM59_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) || ((pp ? pp -> print_box : 1 ) && ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) || ((pp ? pp -> print_struct && (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) && (FUNCCALL(SETUP_XfOrM59(_), scheme_inspector_sees_part (obj , pp -> inspector , - 1 ) )) : 0 ) ) || ((pp ? (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) && FUNCCALL(SETUP_XfOrM59(_), scheme_is_writable_struct (obj ) ): 0 ) ) || ((pp ? pp -> print_hash_table : 1 ) && ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) ) ) ) {
    Scheme_Object * v ; 
    BLOCK_SETUP((PUSH(v, 0+XfOrM59_COUNT)));
#   define XfOrM78_COUNT (1+XfOrM59_COUNT)
#   define SETUP_XfOrM78(x) SETUP(XfOrM78_COUNT)
    v = NULLED_OUT ; 
    {
      unsigned long _stk_pos ; 
#     define XfOrM81_COUNT (0+XfOrM78_COUNT)
#     define SETUP_XfOrM81(x) SETUP_XfOrM78(x)
      _stk_pos = (unsigned long ) & _stk_pos ; 
      if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
#       define XfOrM82_COUNT (0+XfOrM81_COUNT)
#       define SETUP_XfOrM82(x) SETUP_XfOrM81(x)
        if (pp )
          pp = FUNCCALL(SETUP_XfOrM82(_), copy_print_params (pp ) ); 
        scheme_current_thread -> ku . k . p1 = (void * ) obj ; 
        scheme_current_thread -> ku . k . p2 = (void * ) ht ; 
        scheme_current_thread -> ku . k . p3 = (void * ) counter ; 
        scheme_current_thread -> ku . k . p4 = (void * ) pp ; 
        FUNCCALL(SETUP_XfOrM82(_), scheme_handle_stack_overflow (setup_graph_k ) ); 
        RET_NOTHING ; 
      }
    }
    v = FUNCCALL(SETUP_XfOrM78(_), scheme_hash_get (ht , obj ) ); 
    if (! v )
      FUNCCALL(SETUP_XfOrM78(_), scheme_hash_set (ht , obj , (Scheme_Object * ) 0x1 ) ); 
    else {
#     define XfOrM79_COUNT (0+XfOrM78_COUNT)
#     define SETUP_XfOrM79(x) SETUP_XfOrM78(x)
      if ((long ) v == 1 ) {
#       define XfOrM80_COUNT (0+XfOrM79_COUNT)
#       define SETUP_XfOrM80(x) SETUP_XfOrM79(x)
        (* counter ) += 2 ; 
        FUNCCALL(SETUP_XfOrM80(_), scheme_hash_set (ht , obj , (Scheme_Object * ) (long ) * counter ) ); 
      }
      RET_NOTHING ; 
    }
  }
  else RET_NOTHING ; 
  {
#   define XfOrM76_COUNT (0+XfOrM59_COUNT)
#   define SETUP_XfOrM76(x) SETUP_XfOrM59(x)
    if ((scheme_fuel_counter ) <= 0 ) {
#     define XfOrM77_COUNT (0+XfOrM76_COUNT)
#     define SETUP_XfOrM77(x) SETUP_XfOrM76(x)
      FUNCCALL(SETUP_XfOrM77(_), scheme_out_of_fuel () ); 
    }
  }
  ; 
  if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#   define XfOrM75_COUNT (0+XfOrM59_COUNT)
#   define SETUP_XfOrM75(x) SETUP_XfOrM59(x)
    FUNCCALL(SETUP_XfOrM75(_), setup_graph_table ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) , ht , counter , pp ) ); 
    FUNCCALL(SETUP_XfOrM75(_), setup_graph_table ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) , ht , counter , pp ) ); 
  }
  else if ((! pp || pp -> print_box ) && ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) {
#   define XfOrM74_COUNT (0+XfOrM59_COUNT)
#   define SETUP_XfOrM74(x) SETUP_XfOrM59(x)
    FUNCCALL(SETUP_XfOrM74(_), setup_graph_table ((((Scheme_Small_Object * ) (obj ) ) -> u . ptr_val ) , ht , counter , pp ) ); 
  }
  else if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
    int i , len ; 
#   define XfOrM71_COUNT (0+XfOrM59_COUNT)
#   define SETUP_XfOrM71(x) SETUP_XfOrM59(x)
    len = (((Scheme_Vector * ) (obj ) ) -> size ) ; 
    for (i = 0 ; i < len ; i ++ ) {
#     define XfOrM73_COUNT (0+XfOrM71_COUNT)
#     define SETUP_XfOrM73(x) SETUP_XfOrM71(x)
      FUNCCALL(SETUP_XfOrM73(_), setup_graph_table ((((Scheme_Vector * ) (obj ) ) -> els ) [i ] , ht , counter , pp ) ); 
    }
  }
  else if (pp && (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) ) {
#   define XfOrM65_COUNT (0+XfOrM59_COUNT)
#   define SETUP_XfOrM65(x) SETUP_XfOrM59(x)
    if (FUNCCALL(SETUP_XfOrM65(_), scheme_is_writable_struct (obj ) )) {
#     define XfOrM69_COUNT (0+XfOrM65_COUNT)
#     define SETUP_XfOrM69(x) SETUP_XfOrM65(x)
      if (pp -> print_unreadable ) {
#       define XfOrM70_COUNT (0+XfOrM69_COUNT)
#       define SETUP_XfOrM70(x) SETUP_XfOrM69(x)
        obj = FUNCCALL(SETUP_XfOrM70(_), writable_struct_subs (obj , pp ) ); 
        FUNCCALL(SETUP_XfOrM70(_), setup_graph_table (obj , ht , counter , pp ) ); 
      }
    }
    else {
      int i = ((((Scheme_Structure * ) obj ) -> stype ) -> num_slots ) ; 
#     define XfOrM66_COUNT (0+XfOrM65_COUNT)
#     define SETUP_XfOrM66(x) SETUP_XfOrM65(x)
      while (i -- ) {
#       define XfOrM68_COUNT (0+XfOrM66_COUNT)
#       define SETUP_XfOrM68(x) SETUP_XfOrM66(x)
        if (FUNCCALL(SETUP_XfOrM68(_), scheme_inspector_sees_part (obj , pp -> inspector , i ) ))
          FUNCCALL(SETUP_XfOrM68(_), setup_graph_table (((Scheme_Structure * ) obj ) -> slots [i ] , ht , counter , pp ) ); 
      }
    }
  }
  else if (pp && ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) ) {
    Scheme_Hash_Table * t ; 
    Scheme_Object * * keys , * * vals , * val ; 
    int i ; 
    BLOCK_SETUP((PUSH(vals, 0+XfOrM59_COUNT), PUSH(t, 1+XfOrM59_COUNT), PUSH(val, 2+XfOrM59_COUNT), PUSH(keys, 3+XfOrM59_COUNT)));
#   define XfOrM60_COUNT (4+XfOrM59_COUNT)
#   define SETUP_XfOrM60(x) SETUP(XfOrM60_COUNT)
    t = NULLED_OUT ; 
    keys = NULLED_OUT ; 
    vals = NULLED_OUT ; 
    val = NULLED_OUT ; 
    t = (Scheme_Hash_Table * ) obj ; 
    keys = t -> keys ; 
    vals = t -> vals ; 
    for (i = t -> size ; i -- ; ) {
#     define XfOrM63_COUNT (0+XfOrM60_COUNT)
#     define SETUP_XfOrM63(x) SETUP_XfOrM60(x)
      if (vals [i ] ) {
#       define XfOrM64_COUNT (0+XfOrM63_COUNT)
#       define SETUP_XfOrM64(x) SETUP_XfOrM63(x)
        val = vals [i ] ; 
        FUNCCALL(SETUP_XfOrM64(_), setup_graph_table (keys [i ] , ht , counter , pp ) ); 
        FUNCCALL_AGAIN(setup_graph_table (val , ht , counter , pp ) ); 
      }
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Hash_Table * scheme_setup_datum_graph (Scheme_Object * o , void * for_print ) {
  Scheme_Hash_Table * ht ; 
  int counter = 1 ; 
  DECL_RET_SAVE (Scheme_Hash_Table * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(for_print, 0), PUSH(ht, 1), PUSH(o, 2)));
# define XfOrM83_COUNT (3)
# define SETUP_XfOrM83(x) SETUP(XfOrM83_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ht = NULLED_OUT ; 
  if (cache_ht ) {
    ht = cache_ht ; 
    cache_ht = ((void * ) 0 ) ; 
  }
  else ht = FUNCCALL(SETUP_XfOrM83(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  FUNCCALL(SETUP_XfOrM83(_), setup_graph_table (o , ht , & counter , (PrintParams * ) for_print ) ); 
  if (counter > 1 )
    RET_VALUE_START (ht ) RET_VALUE_END ; 
  else {
    if (ht -> size < 32 ) {
      int i ; 
      for (i = 0 ; i < ht -> size ; i ++ ) {
        ht -> keys [i ] = ((void * ) 0 ) ; 
        ht -> vals [i ] = ((void * ) 0 ) ; 
      }
      cache_ht = ht ; 
    }
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static char * print_to_string (Scheme_Object * obj , long * volatile len , int write , Scheme_Object * port , long maxl , int check_honu ) {
  Scheme_Hash_Table * volatile ht ; 
  Scheme_Object * v ; 
  char * ca ; 
  int cycles ; 
  Scheme_Config * config ; 
  mz_jmp_buf escape ; 
  volatile PrintParams params ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK_ONCE(11);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(ht, 1), PUSH(config, 2), PUSH(len, 3), PUSH(ca, 4), PUSH(params.inspector, 5), PUSH(params.print_buffer, 6), PUSH(params.print_port, 7), PUSH(params.print_escape, 8), PUSH(obj, 9), PUSH(port, 10)));
# define XfOrM89_COUNT (11)
# define SETUP_XfOrM89(x) SETUP(XfOrM89_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ht = NULLED_OUT ; 
  v = NULLED_OUT ; 
  ca = NULLED_OUT ; 
  config = NULLED_OUT ; 
  params.inspector = NULLED_OUT ; 
  params.print_buffer = NULLED_OUT ; 
  params.print_port = NULLED_OUT ; 
  params.print_escape = NULLED_OUT ; 
  params . print_allocated = 50 ; 
  ca = (char * ) FUNCCALL(SETUP_XfOrM89(_), GC_malloc_atomic (params . print_allocated ) ); 
  params . print_buffer = ca ; 
  params . print_position = 0 ; 
  params . print_offset = 0 ; 
  params . print_maxlen = maxl ; 
  params . print_port = port ; 
  if (! write && (((((long ) (obj ) ) & 0x1 ) || ((((obj ) -> type ) >= scheme_bignum_type ) && (((obj ) -> type ) <= scheme_complex_type ) ) ) || ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) || ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) ) {
    params . print_graph = 0 ; 
    params . print_box = 0 ; 
    params . print_struct = 0 ; 
    params . print_vec_shorthand = 0 ; 
    params . print_hash_table = 0 ; 
    params . print_unreadable = 1 ; 
    params . can_read_pipe_quote = 1 ; 
    params . case_sens = 1 ; 
    params . honu_mode = 0 ; 
    params . inspector = scheme_false ; 
  }
  else {
#   define XfOrM92_COUNT (0+XfOrM89_COUNT)
#   define SETUP_XfOrM92(x) SETUP_XfOrM89(x)
    config = FUNCCALL(SETUP_XfOrM92(_), scheme_current_config () ); 
    v = FUNCCALL(SETUP_XfOrM92(_), scheme_get_param (config , MZCONFIG_PRINT_GRAPH ) ); 
    params . print_graph = (! (((v ) ) == (scheme_false ) ) ) ; 
    v = FUNCCALL(SETUP_XfOrM92(_), scheme_get_param (config , MZCONFIG_PRINT_BOX ) ); 
    params . print_box = (! (((v ) ) == (scheme_false ) ) ) ; 
    v = FUNCCALL(SETUP_XfOrM92(_), scheme_get_param (config , MZCONFIG_PRINT_STRUCT ) ); 
    params . print_struct = (! (((v ) ) == (scheme_false ) ) ) ; 
    v = FUNCCALL(SETUP_XfOrM92(_), scheme_get_param (config , MZCONFIG_PRINT_VEC_SHORTHAND ) ); 
    params . print_vec_shorthand = (! (((v ) ) == (scheme_false ) ) ) ; 
    v = FUNCCALL(SETUP_XfOrM92(_), scheme_get_param (config , MZCONFIG_PRINT_HASH_TABLE ) ); 
    params . print_hash_table = (! (((v ) ) == (scheme_false ) ) ) ; 
    if (write ) {
#     define XfOrM94_COUNT (0+XfOrM92_COUNT)
#     define SETUP_XfOrM94(x) SETUP_XfOrM92(x)
      if (maxl > 0 )
        params . print_unreadable = 1 ; 
      else {
#       define XfOrM95_COUNT (0+XfOrM94_COUNT)
#       define SETUP_XfOrM95(x) SETUP_XfOrM94(x)
        v = FUNCCALL(SETUP_XfOrM95(_), scheme_get_param (config , MZCONFIG_PRINT_UNREADABLE ) ); 
        params . print_unreadable = (! (((v ) ) == (scheme_false ) ) ) ; 
      }
    }
    else params . print_unreadable = 1 ; 
    v = FUNCCALL(SETUP_XfOrM92(_), scheme_get_param (config , MZCONFIG_CAN_READ_PIPE_QUOTE ) ); 
    params . can_read_pipe_quote = (! (((v ) ) == (scheme_false ) ) ) ; 
    v = FUNCCALL(SETUP_XfOrM92(_), scheme_get_param (config , MZCONFIG_CASE_SENS ) ); 
    params . case_sens = (! (((v ) ) == (scheme_false ) ) ) ; 
    if (check_honu ) {
#     define XfOrM93_COUNT (0+XfOrM92_COUNT)
#     define SETUP_XfOrM93(x) SETUP_XfOrM92(x)
      v = FUNCCALL(SETUP_XfOrM93(_), scheme_get_param (config , MZCONFIG_HONU_MODE ) ); 
      params . honu_mode = (! (((v ) ) == (scheme_false ) ) ) ; 
    }
    else params . honu_mode = 0 ; 
    v = FUNCCALL(SETUP_XfOrM92(_), scheme_get_param (config , MZCONFIG_INSPECTOR ) ); 
    params . inspector = v ; 
  }
  if (params . print_graph )
    cycles = 1 ; 
  else {
#   define XfOrM90_COUNT (0+XfOrM89_COUNT)
#   define SETUP_XfOrM90(x) SETUP_XfOrM89(x)
    fast_checker_counter = 50 ; 
    cycles = FUNCCALL(SETUP_XfOrM90(_), check_cycles_fast (obj , (PrintParams * ) & params ) ); 
    if (cycles == - 1 ) {
#     define XfOrM91_COUNT (0+XfOrM90_COUNT)
#     define SETUP_XfOrM91(x) SETUP_XfOrM90(x)
      ht = FUNCCALL(SETUP_XfOrM91(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
      cycles = FUNCCALL(SETUP_XfOrM91(_), check_cycles (obj , ht , (PrintParams * ) & params ) ); 
    }
  }
  if (cycles )
    ht = FUNCCALL(SETUP_XfOrM89(_), scheme_setup_datum_graph (obj , (PrintParams * ) & params ) ); 
  else ht = ((void * ) 0 ) ; 
  if (maxl > 0 )
    params . print_escape = & escape ; 
  else params . print_escape = ((void * ) 0 ) ; 
  if ((maxl <= 3 ) || ! ((escape ) . gcvs = (long ) __gc_var_stack__ , (escape ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((escape ) . jb ) , (_setjmp (((escape ) . jb ) -> jb ) ) ) ) )
    FUNCCALL(SETUP_XfOrM89(_), print (obj , write , 0 , ht , ((void * ) 0 ) , (PrintParams * ) & params ) ); 
  params . print_buffer [params . print_position ] = '\0' ; 
  if (len )
    * len = params . print_position ; 
  params . inspector = ((void * ) 0 ) ; 
  RET_VALUE_START (params . print_buffer ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void print_to_port (char * name , Scheme_Object * obj , Scheme_Object * port , int notdisplay , long maxl , int check_honu ) {
  Scheme_Output_Port * op ; 
  char * str ; 
  long len ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(str, 0), PUSH(port, 1)));
# define XfOrM97_COUNT (2)
# define SETUP_XfOrM97(x) SETUP(XfOrM97_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  op = NULLED_OUT ; 
  str = NULLED_OUT ; 
  op = (Scheme_Output_Port * ) port ; 
  if (op -> closed )
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL , "%s: output port is closed" , name ) ); 
  str = FUNCCALL(SETUP_XfOrM97(_), print_to_string (obj , & len , notdisplay , port , maxl , check_honu ) ); 
  FUNCCALL_EMPTY(scheme_write_byte_string (str , len , port ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void print_this_string (PrintParams * pp , const char * str , int offset , int autolen ) {
  long len ; 
  char * oldstr ; 
  PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(oldstr, 0), PUSH(str, 1), PUSH(pp, 2)));
# define XfOrM98_COUNT (3)
# define SETUP_XfOrM98(x) SETUP(XfOrM98_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  oldstr = NULLED_OUT ; 
  if (! autolen ) {
    if (! str )
      len = 0 ; 
    else RET_NOTHING ; 
  }
  else if (autolen > 0 )
    len = autolen ; 
  else len = strlen (str XFORM_OK_PLUS offset ) ; 
  if (! pp -> print_buffer ) {
    pp -> print_position += len ; 
    pp -> print_offset += len ; 
    RET_NOTHING ; 
  }
  if (len + pp -> print_position + 1 > pp -> print_allocated ) {
#   define XfOrM105_COUNT (0+XfOrM98_COUNT)
#   define SETUP_XfOrM105(x) SETUP_XfOrM98(x)
    if (len + 1 >= pp -> print_allocated )
      pp -> print_allocated = 2 * pp -> print_allocated + len + 1 ; 
    else pp -> print_allocated = 2 * pp -> print_allocated ; 
    oldstr = pp -> print_buffer ; 
    {
      char * ca ; 
      BLOCK_SETUP((PUSH(ca, 0+XfOrM105_COUNT)));
#     define XfOrM106_COUNT (1+XfOrM105_COUNT)
#     define SETUP_XfOrM106(x) SETUP(XfOrM106_COUNT)
      ca = NULLED_OUT ; 
      ca = (char * ) FUNCCALL(SETUP_XfOrM106(_), GC_malloc_atomic (pp -> print_allocated ) ); 
      pp -> print_buffer = ca ; 
    }
    (memcpy (pp -> print_buffer , oldstr , pp -> print_position ) ) ; 
  }
  (memcpy (pp -> print_buffer + pp -> print_position , str + offset , len ) ) ; 
  pp -> print_position += len ; 
  pp -> print_offset += len ; 
  {
#   define XfOrM103_COUNT (0+XfOrM98_COUNT)
#   define SETUP_XfOrM103(x) SETUP_XfOrM98(x)
    if ((scheme_fuel_counter ) <= 0 ) {
#     define XfOrM104_COUNT (0+XfOrM103_COUNT)
#     define SETUP_XfOrM104(x) SETUP_XfOrM103(x)
      FUNCCALL(SETUP_XfOrM104(_), scheme_out_of_fuel () ); 
    }
  }
  ; 
  if (pp -> print_maxlen > 3 ) {
    if (pp -> print_position > pp -> print_maxlen ) {
      long l = pp -> print_maxlen ; 
      pp -> print_buffer [l ] = 0 ; 
      pp -> print_buffer [l - 1 ] = '.' ; 
      pp -> print_buffer [l - 2 ] = '.' ; 
      pp -> print_buffer [l - 3 ] = '.' ; 
      pp -> print_position = l ; 
      (((long * ) (void * ) ((* pp -> print_escape ) . gcvs ) ) [1 ] = (* pp -> print_escape ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* pp -> print_escape ) . gcvs , scheme_jit_longjmp ((* pp -> print_escape ) . jb , 1 ) ) ; 
    }
  }
  else if ((pp -> print_position > 500 ) || ! str ) {
#   define XfOrM99_COUNT (0+XfOrM98_COUNT)
#   define SETUP_XfOrM99(x) SETUP_XfOrM98(x)
    if (pp -> print_port ) {
#     define XfOrM100_COUNT (0+XfOrM99_COUNT)
#     define SETUP_XfOrM100(x) SETUP_XfOrM99(x)
      pp -> print_buffer [pp -> print_position ] = 0 ; 
      FUNCCALL(SETUP_XfOrM100(_), scheme_write_byte_string (pp -> print_buffer , pp -> print_position , pp -> print_port ) ); 
      pp -> print_position = 0 ; 
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void print_utf8_string (PrintParams * pp , const char * str , int offset , int autolen ) {
  /* No conversion */
  print_this_string (pp , str , offset , autolen ) ; 
}
void scheme_print_bytes (Scheme_Print_Params * pp , const char * str , int offset , int len ) {
  /* No conversion */
  print_this_string (pp , str , offset , len ) ; 
}
void scheme_print_utf8 (Scheme_Print_Params * pp , const char * str , int offset , int len ) {
  /* No conversion */
  print_utf8_string (pp , str , offset , len ) ; 
}
static void print_number (PrintParams * pp , long n ) {
  /* No conversion */
  unsigned char s [4 ] ; 
  s [0 ] = (unsigned char ) (n & 0xFF ) ; 
  s [1 ] = (unsigned char ) ((n >> 8 ) & 0xFF ) ; 
  s [2 ] = (unsigned char ) ((n >> 16 ) & 0xFF ) ; 
  s [3 ] = (unsigned char ) ((n >> 24 ) & 0xFF ) ; 
  print_this_string (pp , (char * ) s , 0 , 4 ) ; 
}
static void print_short_number (PrintParams * pp , long n ) {
  /* No conversion */
  unsigned char s [2 ] ; 
  s [0 ] = (unsigned char ) (n & 0xFF ) ; 
  s [1 ] = (unsigned char ) ((n >> 8 ) & 0xFF ) ; 
  print_this_string (pp , (char * ) s , 0 , 2 ) ; 
}
static void print_one_byte (PrintParams * pp , int n ) {
  /* No conversion */
  unsigned char s [1 ] ; 
  s [0 ] = n ; 
  print_this_string (pp , (char * ) s , 0 , 1 ) ; 
}
static void print_compact_number (PrintParams * pp , long n ) {
  unsigned char s [2 ] ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(pp, 0)));
# define XfOrM115_COUNT (1)
# define SETUP_XfOrM115(x) SETUP(XfOrM115_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (n < 0 ) {
#   define XfOrM119_COUNT (0+XfOrM115_COUNT)
#   define SETUP_XfOrM119(x) SETUP_XfOrM115(x)
    if (n > - 32 ) {
#     define XfOrM121_COUNT (0+XfOrM119_COUNT)
#     define SETUP_XfOrM121(x) SETUP_XfOrM119(x)
      s [0 ] = (unsigned char ) (0xC0 | (- n ) ) ; 
      FUNCCALL(SETUP_XfOrM121(_), print_this_string (pp , (char * ) s , 0 , 1 ) ); 
      RET_NOTHING ; 
    }
    else {
      n = - n ; 
      s [0 ] = 0xE0 ; 
    }
  }
  else if (n < 128 ) {
#   define XfOrM118_COUNT (0+XfOrM115_COUNT)
#   define SETUP_XfOrM118(x) SETUP_XfOrM115(x)
    s [0 ] = (unsigned char ) n ; 
    FUNCCALL(SETUP_XfOrM118(_), print_this_string (pp , (char * ) s , 0 , 1 ) ); 
    RET_NOTHING ; 
  }
  else if (n < 0x4000 ) {
#   define XfOrM117_COUNT (0+XfOrM115_COUNT)
#   define SETUP_XfOrM117(x) SETUP_XfOrM115(x)
    s [0 ] = (unsigned char ) (0x80 | (n & 0x3F ) ) ; 
    s [1 ] = (unsigned char ) ((n >> 6 ) & 0xFF ) ; 
    FUNCCALL(SETUP_XfOrM117(_), print_this_string (pp , (char * ) s , 0 , 2 ) ); 
    RET_NOTHING ; 
  }
  else {
    s [0 ] = 0xF0 ; 
  }
  FUNCCALL(SETUP_XfOrM115(_), print_this_string (pp , (char * ) s , 0 , 1 ) ); 
  FUNCCALL_EMPTY(print_number (pp , n ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void do_print_string (int compact , int notdisplay , Scheme_Print_Params * pp , const mzchar * s , int offset , int l ) {
  int el , reset ; 
  char * buf ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(pp, 0), PUSH(buf, 1), PUSH(s, 2)));
# define XfOrM122_COUNT (3)
# define SETUP_XfOrM122(x) SETUP(XfOrM122_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  buf = NULLED_OUT ; 
  el = l * 6 ; 
  if (el <= 256 ) {
#   define XfOrM126_COUNT (0+XfOrM122_COUNT)
#   define SETUP_XfOrM126(x) SETUP_XfOrM122(x)
    if (quick_encode_buffer ) {
      buf = quick_encode_buffer ; 
      quick_encode_buffer = ((void * ) 0 ) ; 
    }
    else buf = (char * ) FUNCCALL(SETUP_XfOrM126(_), GC_malloc_atomic (256 ) ); 
    reset = 1 ; 
  }
  else {
#   define XfOrM125_COUNT (0+XfOrM122_COUNT)
#   define SETUP_XfOrM125(x) SETUP_XfOrM122(x)
    buf = (char * ) FUNCCALL(SETUP_XfOrM125(_), GC_malloc_atomic (el ) ); 
    reset = 0 ; 
  }
  el = FUNCCALL(SETUP_XfOrM122(_), scheme_utf8_encode (s , offset , offset + l , (unsigned char * ) buf , 0 , 0 ) ); 
  if (compact ) {
#   define XfOrM124_COUNT (0+XfOrM122_COUNT)
#   define SETUP_XfOrM124(x) SETUP_XfOrM122(x)
    FUNCCALL(SETUP_XfOrM124(_), print_this_string (pp , & compacts [CPT_CHAR_STRING ] , 0 , 1 ) ); 
    FUNCCALL(SETUP_XfOrM124(_), print_compact_number (pp , el ) ); 
    FUNCCALL_AGAIN(print_compact_number (pp , l ) ); 
    FUNCCALL_AGAIN(print_this_string (pp , buf , 0 , el ) ); 
  }
  else {
#   define XfOrM123_COUNT (0+XfOrM122_COUNT)
#   define SETUP_XfOrM123(x) SETUP_XfOrM122(x)
    FUNCCALL(SETUP_XfOrM123(_), print_char_string (buf , el , s , offset , l , notdisplay , 0 , pp ) ); 
  }
  if (reset )
    quick_encode_buffer = buf ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_print_string (Scheme_Print_Params * pp , const mzchar * s , int offset , int l ) {
  /* No conversion */
  do_print_string (0 , 0 , pp , s , offset , l ) ; 
}
static void print_string_in_angle (PrintParams * pp , const char * start , const char * prefix , int slen ) {
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(pp, 0), PUSH(start, 1)));
# define XfOrM129_COUNT (2)
# define SETUP_XfOrM129(x) SETUP(XfOrM129_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM129(_), print_utf8_string (pp , prefix , 0 , - 1 ) ); 
  FUNCCALL_EMPTY(print_utf8_string (pp , start , 0 , slen ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * print_k (void ) {
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * o = (Scheme_Object * ) p -> ku . k . p1 ; 
  Scheme_Hash_Table * ht = (Scheme_Hash_Table * ) p -> ku . k . p2 ; 
  Scheme_Marshal_Tables * mt = (Scheme_Marshal_Tables * ) p -> ku . k . p3 ; 
  PrintParams * pp = (PrintParams * ) p -> ku . k . p5 ; 
  mz_jmp_buf * volatile save ; 
  mz_jmp_buf newbuf ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(mt, 0), PUSH(o, 1), PUSH(pp, 2), PUSH(ht, 3), PUSH(p, 4), PUSH(save, 5)));
# define XfOrM130_COUNT (6)
# define SETUP_XfOrM130(x) SETUP(XfOrM130_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  save = NULLED_OUT ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  p -> ku . k . p2 = ((void * ) 0 ) ; 
  p -> ku . k . p3 = ((void * ) 0 ) ; 
  p -> ku . k . p5 = ((void * ) 0 ) ; 
  save = pp -> print_escape ; 
  pp -> print_escape = & newbuf ; 
  if (((newbuf ) . gcvs = (long ) __gc_var_stack__ , (newbuf ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((newbuf ) . jb ) , (_setjmp (((newbuf ) . jb ) -> jb ) ) ) ) ) {
#   define XfOrM132_COUNT (0+XfOrM130_COUNT)
#   define SETUP_XfOrM132(x) SETUP_XfOrM130(x)
    FUNCCALL(SETUP_XfOrM132(_), scheme_make_pair (scheme_void , scheme_void ) ); 
    pp -> print_escape = save ; 
    RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM131_COUNT (0+XfOrM130_COUNT)
#   define SETUP_XfOrM131(x) SETUP_XfOrM130(x)
    RET_VALUE_START (FUNCCALL_EMPTY(print (o , p -> ku . k . i1 , p -> ku . k . i2 , ht , mt , pp ) )? scheme_true : scheme_false ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int compare_keys (const void * a , const void * b ) {
  /* No conversion */
  Scheme_Object * av , * bv ; 
  av = ((Scheme_Object * * ) a ) [0 ] ; 
  bv = ((Scheme_Object * * ) b ) [0 ] ; 
  if ((((Scheme_Type ) (((((long ) (av ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (av ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || ((Scheme_Type ) (((((long ) (av ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (av ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) || ((Scheme_Type ) (((((long ) (av ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (av ) ) -> type ) ) == (Scheme_Type ) (scheme_keyword_type ) ) || ((Scheme_Type ) (((((long ) (av ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (av ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (av ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (av ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) || ((Scheme_Type ) (((((long ) (av ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (av ) ) -> type ) ) == (Scheme_Type ) (scheme_char_type ) ) || ((Scheme_Type ) (((((long ) (av ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (av ) ) -> type ) ) == (Scheme_Type ) (scheme_module_index_type ) ) ) ) {
    if (! (((Scheme_Type ) (((((long ) (bv ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (bv ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || ((Scheme_Type ) (((((long ) (bv ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (bv ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) || ((Scheme_Type ) (((((long ) (bv ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (bv ) ) -> type ) ) == (Scheme_Type ) (scheme_keyword_type ) ) || ((Scheme_Type ) (((((long ) (bv ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (bv ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (bv ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (bv ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) || ((Scheme_Type ) (((((long ) (bv ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (bv ) ) -> type ) ) == (Scheme_Type ) (scheme_char_type ) ) || ((Scheme_Type ) (((((long ) (bv ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (bv ) ) -> type ) ) == (Scheme_Type ) (scheme_module_index_type ) ) ) )
      return - 1 ; 
  }
  else if ((((Scheme_Type ) (((((long ) (bv ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (bv ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || ((Scheme_Type ) (((((long ) (bv ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (bv ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) || ((Scheme_Type ) (((((long ) (bv ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (bv ) ) -> type ) ) == (Scheme_Type ) (scheme_keyword_type ) ) || ((Scheme_Type ) (((((long ) (bv ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (bv ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (bv ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (bv ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) || ((Scheme_Type ) (((((long ) (bv ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (bv ) ) -> type ) ) == (Scheme_Type ) (scheme_char_type ) ) || ((Scheme_Type ) (((((long ) (bv ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (bv ) ) -> type ) ) == (Scheme_Type ) (scheme_module_index_type ) ) ) )
    return 1 ; 
  return ((long * ) a ) [1 ] - ((long * ) b ) [1 ] ; 
}
static void sort_referenced_keys (Scheme_Marshal_Tables * mt ) {
  long j , size , pos = 0 ; 
  Scheme_Object * * keys ; 
  Scheme_Hash_Table * key_map ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(mt, 0), PUSH(key_map, 1), PUSH(keys, 2)));
# define XfOrM135_COUNT (3)
# define SETUP_XfOrM135(x) SETUP(XfOrM135_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  keys = NULLED_OUT ; 
  key_map = NULLED_OUT ; 
  size = mt -> st_refs -> count ; 
  keys = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM135(_), GC_malloc (sizeof (Scheme_Object * ) * ((2 * size ) ) ) )) ; 
  for (j = 0 ; j < mt -> st_refs -> size ; j ++ ) {
    if (mt -> st_refs -> vals [j ] ) {
      keys [pos ] = mt -> st_refs -> keys [j ] ; 
      keys [pos + 1 ] = mt -> st_refs -> vals [j ] ; 
      pos += 2 ; 
    }
  }
  FUNCCALL(SETUP_XfOrM135(_), qsort (keys , size , 2 * sizeof (Scheme_Object * ) , compare_keys ) ); 
  key_map = FUNCCALL(SETUP_XfOrM135(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  for (j = 0 ; j < size ; j ++ ) {
#   define XfOrM137_COUNT (0+XfOrM135_COUNT)
#   define SETUP_XfOrM137(x) SETUP_XfOrM135(x)
    FUNCCALL(SETUP_XfOrM137(_), scheme_hash_set (key_map , keys [(j << 1 ) + 1 ] , ((Scheme_Object * ) (void * ) (long ) ((((long ) (j + 1 ) ) << 1 ) | 0x1 ) ) ) ); 
  }
  mt -> key_map = key_map ; 
  mt -> sorted_keys = keys ; 
  mt -> sorted_keys_count = size ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void print_table_keys (int notdisplay , int compact , Scheme_Hash_Table * ht , Scheme_Marshal_Tables * mt , PrintParams * pp ) {
  long j , size , offset ; 
  Scheme_Object * * keys , * key , * obj ; 
  PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(ht, 0), PUSH(obj, 1), PUSH(pp, 2), PUSH(mt, 3), PUSH(key, 4), PUSH(keys, 5)));
# define XfOrM142_COUNT (6)
# define SETUP_XfOrM142(x) SETUP(XfOrM142_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  keys = NULLED_OUT ; 
  key = NULLED_OUT ; 
  obj = NULLED_OUT ; 
  size = mt -> sorted_keys_count ; 
  keys = mt -> sorted_keys ; 
  for (j = 0 ; j < size ; j ++ ) {
#   define XfOrM146_COUNT (0+XfOrM142_COUNT)
#   define SETUP_XfOrM146(x) SETUP_XfOrM142(x)
    offset = pp -> print_offset ; 
    mt -> shared_offsets [j ] = offset ; 
    key = keys [j << 1 ] ; 
    if (mt -> rn_saved ) {
#     define XfOrM148_COUNT (0+XfOrM146_COUNT)
#     define SETUP_XfOrM148(x) SETUP_XfOrM146(x)
      obj = FUNCCALL(SETUP_XfOrM148(_), scheme_hash_get (mt -> rn_saved , key ) ); 
    }
    else {
      obj = ((void * ) 0 ) ; 
    }
    if (! obj )
      obj = key ; 
    mt -> print_now = j + 1 ; 
    FUNCCALL(SETUP_XfOrM146(_), print (obj ? obj : key , notdisplay , compact , ht , mt , pp ) ); 
    mt -> print_now = 0 ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int print_substring (Scheme_Object * obj , int notdisplay , int compact , Scheme_Hash_Table * ht , Scheme_Marshal_Tables * mt , PrintParams * pp , char * * result , long * rlen , int print_keys , long * klen ) {
  int closed ; 
  long save_alloc , save_pos , save_off , save_maxl ; 
  char * save_buf ; 
  Scheme_Object * save_port ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(10);
  BLOCK_SETUP_TOP((PUSH(klen, 0), PUSH(mt, 1), PUSH(pp, 2), PUSH(ht, 3), PUSH(obj, 4), PUSH(save_port, 5), PUSH(save_buf, 6), PUSH(rlen, 7), PUSH(result, 8)));
# define XfOrM149_COUNT (9)
# define SETUP_XfOrM149(x) SETUP(XfOrM149_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  save_buf = NULLED_OUT ; 
  save_port = NULLED_OUT ; 
  save_alloc = pp -> print_allocated ; 
  save_buf = pp -> print_buffer ; 
  save_pos = pp -> print_position ; 
  save_off = pp -> print_offset ; 
  save_maxl = pp -> print_maxlen ; 
  save_port = pp -> print_port ; 
  if (result ) {
    char * ca ; 
    BLOCK_SETUP((PUSH(ca, 0+XfOrM149_COUNT)));
#   define XfOrM153_COUNT (1+XfOrM149_COUNT)
#   define SETUP_XfOrM153(x) SETUP(XfOrM153_COUNT)
    ca = NULLED_OUT ; 
    pp -> print_allocated = 50 ; 
    ca = (char * ) FUNCCALL(SETUP_XfOrM153(_), GC_malloc_atomic (pp -> print_allocated ) ); 
    pp -> print_buffer = ca ; 
  }
  else {
    pp -> print_allocated = 0 ; 
    pp -> print_buffer = ((void * ) 0 ) ; 
  }
  pp -> print_position = 0 ; 
  pp -> print_offset = 0 ; 
  pp -> print_port = ((void * ) 0 ) ; 
  if (print_keys < 0 ) {
#   define XfOrM151_COUNT (0+XfOrM149_COUNT)
#   define SETUP_XfOrM151(x) SETUP_XfOrM149(x)
    FUNCCALL(SETUP_XfOrM151(_), print_table_keys (notdisplay , compact , ht , mt , pp ) ); 
    * klen = pp -> print_offset ; 
  }
  closed = FUNCCALL(SETUP_XfOrM149(_), print (obj , notdisplay , compact , ht , mt , pp ) ); 
  if (print_keys > 0 ) {
#   define XfOrM150_COUNT (0+XfOrM149_COUNT)
#   define SETUP_XfOrM150(x) SETUP_XfOrM149(x)
    FUNCCALL(SETUP_XfOrM150(_), print_table_keys (notdisplay , compact , ht , mt , pp ) ); 
    * klen = pp -> print_offset ; 
  }
  if (result )
    * result = pp -> print_buffer ; 
  * rlen = pp -> print_position ; 
  pp -> print_allocated = save_alloc ; 
  pp -> print_buffer = save_buf ; 
  pp -> print_position = save_pos ; 
  pp -> print_offset = save_off ; 
  pp -> print_maxlen = save_maxl ; 
  pp -> print_port = save_port ; 
  RET_VALUE_START (closed ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * get_symtab_idx (Scheme_Marshal_Tables * mt , Scheme_Object * obj ) {
  Scheme_Object * idx ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(idx, 0), PUSH(obj, 1), PUSH(mt, 2)));
# define XfOrM154_COUNT (3)
# define SETUP_XfOrM154(x) SETUP(XfOrM154_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  idx = NULLED_OUT ; 
  idx = FUNCCALL(SETUP_XfOrM154(_), scheme_hash_get (mt -> symtab , obj ) ); 
  if (idx ) {
#   define XfOrM158_COUNT (0+XfOrM154_COUNT)
#   define SETUP_XfOrM158(x) SETUP_XfOrM154(x)
    if (! mt -> pass ) {
#     define XfOrM159_COUNT (0+XfOrM158_COUNT)
#     define SETUP_XfOrM159(x) SETUP_XfOrM158(x)
      FUNCCALL(SETUP_XfOrM159(_), scheme_hash_set (mt -> st_refs , obj , idx ) ); 
    }
  }
  else {
#   define XfOrM155_COUNT (0+XfOrM154_COUNT)
#   define SETUP_XfOrM155(x) SETUP_XfOrM154(x)
    if (mt -> pass && mt -> print_now ) {
#     define XfOrM156_COUNT (0+XfOrM155_COUNT)
#     define SETUP_XfOrM156(x) SETUP_XfOrM155(x)
      idx = FUNCCALL(SETUP_XfOrM156(_), scheme_hash_get (mt -> st_refs , obj ) ); 
      if (idx ) {
#       define XfOrM157_COUNT (0+XfOrM156_COUNT)
#       define SETUP_XfOrM157(x) SETUP_XfOrM156(x)
        idx = FUNCCALL(SETUP_XfOrM157(_), scheme_hash_get (mt -> key_map , idx ) ); 
        if ((((long ) (idx ) ) >> 1 ) != mt -> print_now )
          RET_VALUE_START (idx ) RET_VALUE_END ; 
        idx = ((void * ) 0 ) ; 
      }
    }
  }
  RET_VALUE_START (idx ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void set_symtab_shared (Scheme_Marshal_Tables * mt , Scheme_Object * obj ) {
  /* No conversion */
  (void ) get_symtab_idx (mt , obj ) ; 
}
static void print_general_symtab_ref (PrintParams * pp , Scheme_Object * idx , int cpt_id ) {
  int l ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(idx, 0), PUSH(pp, 1)));
# define XfOrM161_COUNT (2)
# define SETUP_XfOrM161(x) SETUP(XfOrM161_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM161(_), print_this_string (pp , & compacts [cpt_id ] , 0 , 1 ) ); 
  l = (((long ) (idx ) ) >> 1 ) ; 
  FUNCCALL_EMPTY(print_compact_number (pp , l ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void print_symtab_ref (PrintParams * pp , Scheme_Object * idx ) {
  /* No conversion */
  print_general_symtab_ref (pp , idx , CPT_SYMREF ) ; 
}
static int add_symtab (Scheme_Marshal_Tables * mt , Scheme_Object * obj ) {
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(obj, 0), PUSH(mt, 1)));
# define XfOrM163_COUNT (2)
# define SETUP_XfOrM163(x) SETUP(XfOrM163_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! mt -> pass ) {
    int l ; 
#   define XfOrM168_COUNT (0+XfOrM163_COUNT)
#   define SETUP_XfOrM168(x) SETUP_XfOrM163(x)
    l = mt -> symtab -> count + 1 ; 
    FUNCCALL(SETUP_XfOrM168(_), scheme_hash_set (mt -> symtab , obj , ((Scheme_Object * ) (void * ) (long ) ((((long ) (l ) ) << 1 ) | 0x1 ) ) ) ); 
    RET_VALUE_START (l ) RET_VALUE_END ; 
  }
  else {
    Scheme_Object * key , * l ; 
    BLOCK_SETUP((PUSH(key, 0+XfOrM163_COUNT), PUSH(l, 1+XfOrM163_COUNT)));
#   define XfOrM164_COUNT (2+XfOrM163_COUNT)
#   define SETUP_XfOrM164(x) SETUP(XfOrM164_COUNT)
    key = NULLED_OUT ; 
    l = NULLED_OUT ; 
    key = FUNCCALL(SETUP_XfOrM164(_), scheme_hash_get (mt -> st_refs , obj ) ); 
    for (l = mt -> st_ref_stack ; ! key && ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#     define XfOrM167_COUNT (0+XfOrM164_COUNT)
#     define SETUP_XfOrM167(x) SETUP_XfOrM164(x)
      key = FUNCCALL(SETUP_XfOrM167(_), scheme_hash_get ((Scheme_Hash_Table * ) (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) , obj ) ); 
    }
    if (! key ) {
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    key = FUNCCALL(SETUP_XfOrM164(_), scheme_hash_get (mt -> key_map , key ) ); 
    FUNCCALL(SETUP_XfOrM164(_), scheme_hash_set (mt -> symtab , obj , key ) ); 
    RET_VALUE_START ((((long ) (key ) ) >> 1 ) ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void symtab_set (PrintParams * pp , Scheme_Marshal_Tables * mt , Scheme_Object * obj ) {
  /* No conversion */
  (void ) add_symtab (mt , obj ) ; 
}
static void print_symtab_set (PrintParams * pp , Scheme_Marshal_Tables * mt , Scheme_Object * obj ) {
  int l ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(pp, 0)));
# define XfOrM170_COUNT (1)
# define SETUP_XfOrM170(x) SETUP(XfOrM170_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  l = FUNCCALL(SETUP_XfOrM170(_), add_symtab (mt , obj ) ); 
  FUNCCALL_EMPTY(print_compact_number (pp , l ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_marshal_wrap_set (Scheme_Marshal_Tables * mt , Scheme_Object * obj , Scheme_Object * val ) {
  int l ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(val, 0), PUSH(obj, 1), PUSH(mt, 2)));
# define XfOrM171_COUNT (3)
# define SETUP_XfOrM171(x) SETUP(XfOrM171_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  l = FUNCCALL(SETUP_XfOrM171(_), add_symtab (mt , obj ) ); 
  if (l ) {
#   define XfOrM172_COUNT (0+XfOrM171_COUNT)
#   define SETUP_XfOrM172(x) SETUP_XfOrM171(x)
    if (! mt -> rn_saved ) {
      Scheme_Hash_Table * rn_saved ; 
      BLOCK_SETUP((PUSH(rn_saved, 0+XfOrM172_COUNT)));
#     define XfOrM174_COUNT (1+XfOrM172_COUNT)
#     define SETUP_XfOrM174(x) SETUP(XfOrM174_COUNT)
      rn_saved = NULLED_OUT ; 
      rn_saved = FUNCCALL(SETUP_XfOrM174(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
      mt -> rn_saved = rn_saved ; 
    }
    if (mt -> pass >= 2 ) {
    }
    else FUNCCALL(SETUP_XfOrM172(_), scheme_hash_set (mt -> rn_saved , obj , val ) ); 
    if (mt -> pass )
      RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (l ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
  }
  RET_VALUE_START (val ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_marshal_lookup (Scheme_Marshal_Tables * mt , Scheme_Object * obj ) {
  /* No conversion */
  return get_symtab_idx (mt , obj ) ; 
}
void scheme_marshal_using_key (Scheme_Marshal_Tables * mt , Scheme_Object * obj ) {
  /* No conversion */
  set_symtab_shared (mt , obj ) ; 
}
void scheme_marshal_push_refs (Scheme_Marshal_Tables * mt ) {
  Scheme_Object * p ; 
  Scheme_Hash_Table * st_refs ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(mt, 0), PUSH(st_refs, 1), PUSH(p, 2)));
# define XfOrM177_COUNT (3)
# define SETUP_XfOrM177(x) SETUP(XfOrM177_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  p = NULLED_OUT ; 
  st_refs = NULLED_OUT ; 
  p = FUNCCALL(SETUP_XfOrM177(_), scheme_make_pair ((Scheme_Object * ) mt -> st_refs , mt -> st_ref_stack ) ); 
  mt -> st_ref_stack = p ; 
  st_refs = FUNCCALL(SETUP_XfOrM177(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  mt -> st_refs = st_refs ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_marshal_pop_refs (Scheme_Marshal_Tables * mt , int keep ) {
  Scheme_Hash_Table * st_refs = mt -> st_refs ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(st_refs, 0), PUSH(mt, 1)));
# define XfOrM178_COUNT (2)
# define SETUP_XfOrM178(x) SETUP(XfOrM178_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  mt -> st_refs = (Scheme_Hash_Table * ) (((Scheme_Simple_Object * ) (mt -> st_ref_stack ) ) -> u . pair_val . car ) ; 
  mt -> st_ref_stack = (((Scheme_Simple_Object * ) (mt -> st_ref_stack ) ) -> u . pair_val . cdr ) ; 
  if (keep ) {
#   define XfOrM179_COUNT (0+XfOrM178_COUNT)
#   define SETUP_XfOrM179(x) SETUP_XfOrM178(x)
    if (! mt -> st_refs -> count )
      mt -> st_refs = st_refs ; 
    else {
      long i ; 
#     define XfOrM180_COUNT (0+XfOrM179_COUNT)
#     define SETUP_XfOrM180(x) SETUP_XfOrM179(x)
      for (i = 0 ; i < st_refs -> size ; i ++ ) {
#       define XfOrM183_COUNT (0+XfOrM180_COUNT)
#       define SETUP_XfOrM183(x) SETUP_XfOrM180(x)
        if (st_refs -> vals [i ] ) {
#         define XfOrM184_COUNT (0+XfOrM183_COUNT)
#         define SETUP_XfOrM184(x) SETUP_XfOrM183(x)
          FUNCCALL(SETUP_XfOrM184(_), scheme_hash_set (mt -> st_refs , st_refs -> keys [i ] , st_refs -> vals [i ] ) ); 
        }
      }
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void print_escaped (PrintParams * pp , int notdisplay , Scheme_Object * obj , Scheme_Hash_Table * ht , Scheme_Marshal_Tables * mt , int shared ) {
  char * r ; 
  long len ; 
  Scheme_Object * idx ; 
  PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(obj, 0), PUSH(mt, 1), PUSH(idx, 2), PUSH(pp, 3), PUSH(r, 4), PUSH(ht, 5)));
# define XfOrM185_COUNT (6)
# define SETUP_XfOrM185(x) SETUP(XfOrM185_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  r = NULLED_OUT ; 
  idx = NULLED_OUT ; 
  if (shared ) {
#   define XfOrM187_COUNT (0+XfOrM185_COUNT)
#   define SETUP_XfOrM187(x) SETUP_XfOrM185(x)
    idx = FUNCCALL(SETUP_XfOrM187(_), get_symtab_idx (mt , obj ) ); 
    if (idx ) {
#     define XfOrM188_COUNT (0+XfOrM187_COUNT)
#     define SETUP_XfOrM188(x) SETUP_XfOrM187(x)
      FUNCCALL(SETUP_XfOrM188(_), print_symtab_ref (pp , idx ) ); 
      RET_NOTHING ; 
    }
  }
  FUNCCALL(SETUP_XfOrM185(_), print_substring (obj , notdisplay , 0 , ht , ((void * ) 0 ) , pp , & r , & len , 0 , ((void * ) 0 ) ) ); 
  FUNCCALL(SETUP_XfOrM185(_), print_this_string (pp , & compacts [CPT_ESCAPE ] , 0 , 1 ) ); 
  FUNCCALL_AGAIN(print_compact_number (pp , len ) ); 
  FUNCCALL_AGAIN(print_this_string (pp , r , 0 , len ) ); 
  if (mt ) {
#   define XfOrM186_COUNT (0+XfOrM185_COUNT)
#   define SETUP_XfOrM186(x) SETUP_XfOrM185(x)
    FUNCCALL(SETUP_XfOrM186(_), symtab_set (pp , mt , obj ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void cannot_print (PrintParams * pp , int notdisplay , Scheme_Object * obj , Scheme_Hash_Table * ht , int compact ) {
  /* No conversion */
  scheme_raise_exn (MZEXN_FAIL , (compact ? "%s: cannot marshal constant that is embedded in compiled code: %V" : "%s: printing disabled for unreadable value: %V" ) , notdisplay ? "write" : "display" , obj ) ; 
}
static void print_named (Scheme_Object * obj , const char * kind , const char * s , int len , PrintParams * pp ) {
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(kind, 0), PUSH(pp, 1), PUSH(s, 2)));
# define XfOrM190_COUNT (3)
# define SETUP_XfOrM190(x) SETUP(XfOrM190_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM190(_), print_utf8_string (pp , "#<" , 0 , 2 ) ); 
  FUNCCALL(SETUP_XfOrM190(_), print_utf8_string (pp , kind , 0 , - 1 ) ); 
  if (s ) {
#   define XfOrM191_COUNT (0+XfOrM190_COUNT)
#   define SETUP_XfOrM191(x) SETUP_XfOrM190(x)
    FUNCCALL(SETUP_XfOrM191(_), print_utf8_string (pp , ":" , 0 , 1 ) ); 
    FUNCCALL(SETUP_XfOrM191(_), print_utf8_string (pp , s , 0 , len ) ); 
  }
  ; 
  FUNCCALL_EMPTY(print_utf8_string (pp , ">" , 0 , 1 ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void always_scheme (PrintParams * pp , int reset ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(pp, 0)));
# define XfOrM192_COUNT (1)
# define SETUP_XfOrM192(x) SETUP(XfOrM192_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (pp -> honu_mode ) {
#   define XfOrM193_COUNT (0+XfOrM192_COUNT)
#   define SETUP_XfOrM193(x) SETUP_XfOrM192(x)
    FUNCCALL(SETUP_XfOrM193(_), print_utf8_string (pp , "#sx" , 0 , 3 ) ); 
    if (reset )
      pp -> honu_mode = 0 ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int print (Scheme_Object * obj , int notdisplay , int compact , Scheme_Hash_Table * ht , Scheme_Marshal_Tables * mt , PrintParams * pp ) {
  int closed = 0 ; 
  int save_honu_mode ; 
  char * __funcarg27 = NULLED_OUT ; 
  char * __funcarg26 = NULLED_OUT ; 
  Scheme_Object * __funcarg25 = NULLED_OUT ; 
  Scheme_Config * __funcarg24 = NULLED_OUT ; 
  char * __funcarg23 = NULLED_OUT ; 
  char * __funcarg22 = NULLED_OUT ; 
  char * __funcarg21 = NULLED_OUT ; 
  char * __funcarg20 = NULLED_OUT ; 
  char * __funcarg19 = NULLED_OUT ; 
  char * __funcarg18 = NULLED_OUT ; 
  Scheme_Object * __funcarg17 = NULLED_OUT ; 
  Scheme_Object * __funcarg16 = NULLED_OUT ; 
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
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(9);
  BLOCK_SETUP_TOP((PUSH(ht, 0), PUSH(obj, 1), PUSH(pp, 2), PUSH(mt, 3)));
# define XfOrM194_COUNT (4)
# define SETUP_XfOrM194(x) SETUP(XfOrM194_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  {
    static int check_counter = 20 ; 
#   define XfOrM393_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM393(x) SETUP_XfOrM194(x)
    if (! -- check_counter ) {
#     define XfOrM394_COUNT (0+XfOrM393_COUNT)
#     define SETUP_XfOrM394(x) SETUP_XfOrM393(x)
      check_counter = 20 ; 
      {
        unsigned long _stk_pos ; 
#       define XfOrM395_COUNT (0+XfOrM394_COUNT)
#       define SETUP_XfOrM395(x) SETUP_XfOrM394(x)
        _stk_pos = (unsigned long ) & _stk_pos ; 
        if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
          Scheme_Thread * p = scheme_current_thread ; 
          PrintParams * pp2 ; 
          BLOCK_SETUP((PUSH(pp2, 0+XfOrM395_COUNT), PUSH(p, 1+XfOrM395_COUNT)));
#         define XfOrM396_COUNT (2+XfOrM395_COUNT)
#         define SETUP_XfOrM396(x) SETUP(XfOrM396_COUNT)
          pp2 = NULLED_OUT ; 
          pp2 = FUNCCALL(SETUP_XfOrM396(_), copy_print_params (pp ) ); 
          p -> ku . k . p1 = (void * ) obj ; 
          p -> ku . k . i1 = notdisplay ; 
          p -> ku . k . i2 = compact ; 
          p -> ku . k . p2 = (void * ) ht ; 
          p -> ku . k . p3 = mt ; 
          p -> ku . k . p5 = pp2 ; 
          obj = FUNCCALL(SETUP_XfOrM396(_), scheme_handle_stack_overflow (print_k ) ); 
          (memcpy (pp , pp2 , sizeof (PrintParams ) ) ) ; 
          if ((((obj ) ) == (scheme_void ) ) ) {
            (((long * ) (void * ) ((* pp -> print_escape ) . gcvs ) ) [1 ] = (* pp -> print_escape ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* pp -> print_escape ) . gcvs , scheme_jit_longjmp ((* pp -> print_escape ) . jb , 1 ) ) ; 
          }
          RET_VALUE_START (closed ) RET_VALUE_END ; 
        }
      }
    }
  }
  if (scheme_check_print_is_obj && ! FUNCCALL(SETUP_XfOrM194(_), scheme_check_print_is_obj (obj ) )) {
#   define XfOrM392_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM392(x) SETUP_XfOrM194(x)
    FUNCCALL(SETUP_XfOrM392(_), print_utf8_string (pp , "#<" "???" ">" , 0 , 6 ) ); 
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  }
  if (compact && ((! (((long ) (obj ) ) & 0x1 ) && ((((obj ) -> type ) >= scheme_prim_type ) && (((obj ) -> type ) <= scheme_native_closure_type ) ) ) || ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_struct_type_type ) ) || (((obj ) ) == (scheme_eof ) ) || ((Scheme_Type ) (scheme_always_evt_type ) == (Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) ) || ((Scheme_Type ) (scheme_never_evt_type ) == (Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) ) || ((Scheme_Type ) (scheme_struct_property_type ) == (Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) ) ) ) {
    Scheme_Object * val ; 
    BLOCK_SETUP((PUSH(val, 0+XfOrM194_COUNT)));
#   define XfOrM390_COUNT (1+XfOrM194_COUNT)
#   define SETUP_XfOrM390(x) SETUP(XfOrM390_COUNT)
    val = NULLED_OUT ; 
    val = FUNCCALL(SETUP_XfOrM390(_), scheme_hash_get (global_constants_ht , obj ) ); 
    if (val ) {
      obj = val ; 
    }
  }
  save_honu_mode = pp -> honu_mode ; 
  if (ht && (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) || (pp -> print_box && ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) || (pp -> print_struct && (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) && (FUNCCALL(SETUP_XfOrM194(_), scheme_inspector_sees_part (obj , pp -> inspector , - 1 ) )) ) || ((((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) && FUNCCALL(SETUP_XfOrM194(_), scheme_is_writable_struct (obj ) )) || (pp -> print_hash_table && ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) ) ) ) {
    long val ; 
#   define XfOrM383_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM383(x) SETUP_XfOrM194(x)
    val = (long ) FUNCCALL(SETUP_XfOrM383(_), scheme_hash_get (ht , obj ) ); 
    if (val ) {
#     define XfOrM384_COUNT (0+XfOrM383_COUNT)
#     define SETUP_XfOrM384(x) SETUP_XfOrM383(x)
      if (val != 1 ) {
#       define XfOrM385_COUNT (0+XfOrM384_COUNT)
#       define SETUP_XfOrM385(x) SETUP_XfOrM384(x)
        if (compact ) {
#         define XfOrM389_COUNT (0+XfOrM385_COUNT)
#         define SETUP_XfOrM389(x) SETUP_XfOrM385(x)
          FUNCCALL(SETUP_XfOrM389(_), print_escaped (pp , notdisplay , obj , ht , mt , 0 ) ); 
          RET_VALUE_START (1 ) RET_VALUE_END ; 
        }
        else {
#         define XfOrM386_COUNT (0+XfOrM385_COUNT)
#         define SETUP_XfOrM386(x) SETUP_XfOrM385(x)
          if (val > 0 ) {
#           define XfOrM388_COUNT (0+XfOrM386_COUNT)
#           define SETUP_XfOrM388(x) SETUP_XfOrM386(x)
            FUNCCALL(SETUP_XfOrM388(_), always_scheme (pp , 1 ) ); 
            (sprintf (quick_buffer , "#%ld=" , (val - 3 ) >> 1 ) ) ; 
            FUNCCALL(SETUP_XfOrM388(_), print_utf8_string (pp , quick_buffer , 0 , - 1 ) ); 
            FUNCCALL_AGAIN(scheme_hash_set (ht , obj , (Scheme_Object * ) (- val ) ) ); 
          }
          else {
#           define XfOrM387_COUNT (0+XfOrM386_COUNT)
#           define SETUP_XfOrM387(x) SETUP_XfOrM386(x)
            FUNCCALL(SETUP_XfOrM387(_), always_scheme (pp , 0 ) ); 
            (sprintf (quick_buffer , "#%ld#" , ((- val ) - 3 ) >> 1 ) ) ; 
            FUNCCALL(SETUP_XfOrM387(_), print_utf8_string (pp , quick_buffer , 0 , - 1 ) ); 
            RET_VALUE_START (0 ) RET_VALUE_END ; 
          }
        }
      }
    }
  }
  if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_keyword_type ) ) ) {
    int l ; 
    Scheme_Object * idx ; 
    int is_kw ; 
    BLOCK_SETUP((PUSH(idx, 0+XfOrM194_COUNT)));
#   define XfOrM368_COUNT (1+XfOrM194_COUNT)
#   define SETUP_XfOrM368(x) SETUP(XfOrM368_COUNT)
    idx = NULLED_OUT ; 
    is_kw = ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_keyword_type ) ) ; 
    if (compact )
      idx = FUNCCALL(SETUP_XfOrM368(_), get_symtab_idx (mt , obj ) ); 
    else idx = ((void * ) 0 ) ; 
    if (idx ) {
#     define XfOrM382_COUNT (0+XfOrM368_COUNT)
#     define SETUP_XfOrM382(x) SETUP_XfOrM368(x)
      FUNCCALL(SETUP_XfOrM382(_), print_symtab_ref (pp , idx ) ); 
    }
    else if (compact ) {
      int weird ; 
#     define XfOrM378_COUNT (0+XfOrM368_COUNT)
#     define SETUP_XfOrM378(x) SETUP_XfOrM368(x)
      weird = ((& ((Scheme_Symbol * ) (obj ) ) -> iso ) -> so . keyex & 0x3 ) ; 
      l = (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (obj ) ) ) -> len ) ; 
      if (! weird && ! is_kw && (l < (80 - 60 ) ) ) {
        unsigned char s [1 ] ; 
#       define XfOrM381_COUNT (0+XfOrM378_COUNT)
#       define SETUP_XfOrM381(x) SETUP_XfOrM378(x)
        s [0 ] = l + 60 ; 
        FUNCCALL(SETUP_XfOrM381(_), print_this_string (pp , (char * ) s , 0 , 1 ) ); 
      }
      else {
#       define XfOrM379_COUNT (0+XfOrM378_COUNT)
#       define SETUP_XfOrM379(x) SETUP_XfOrM378(x)
        FUNCCALL(SETUP_XfOrM379(_), print_this_string (pp , & compacts [(is_kw ? CPT_KEYWORD : (weird ? CPT_WEIRD_SYMBOL : CPT_SYMBOL ) ) ] , 0 , 1 ) ); 
        if (weird ) {
#         define XfOrM380_COUNT (0+XfOrM379_COUNT)
#         define SETUP_XfOrM380(x) SETUP_XfOrM379(x)
          FUNCCALL(SETUP_XfOrM380(_), print_compact_number (pp , ((& ((Scheme_Symbol * ) (obj ) ) -> iso ) -> so . keyex & 0x1 ) ? 1 : 0 ) ); 
        }
        FUNCCALL(SETUP_XfOrM379(_), print_compact_number (pp , l ) ); 
      }
      (__funcarg27 = FUNCCALL(SETUP_XfOrM378(_), scheme_symbol_val (obj ) ), FUNCCALL_AGAIN(print_this_string (pp , __funcarg27 , 0 , l ) )) ; 
      FUNCCALL(SETUP_XfOrM378(_), symtab_set (pp , mt , obj ) ); 
    }
    else if (notdisplay ) {
#     define XfOrM370_COUNT (0+XfOrM368_COUNT)
#     define SETUP_XfOrM370(x) SETUP_XfOrM368(x)
      if (pp -> honu_mode ) {
#       define XfOrM372_COUNT (0+XfOrM370_COUNT)
#       define SETUP_XfOrM372(x) SETUP_XfOrM370(x)
        if (is_kw )
          FUNCCALL(SETUP_XfOrM372(_), print_utf8_string (pp , "key(" , 0 , 4 ) ); 
        else FUNCCALL(SETUP_XfOrM372(_), print_utf8_string (pp , "sym(" , 0 , 4 ) ); 
        {
          int i ; 
#         define XfOrM373_COUNT (0+XfOrM372_COUNT)
#         define SETUP_XfOrM373(x) SETUP_XfOrM372(x)
          for (i = (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (obj ) ) ) -> len ) ; i -- ; ) {
            if (((unsigned char * ) (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (obj ) ) ) -> s ) ) [i ] > 127 )
              break ; 
          }
          if (i < 0 ) {
#           define XfOrM375_COUNT (0+XfOrM373_COUNT)
#           define SETUP_XfOrM375(x) SETUP_XfOrM373(x)
            FUNCCALL(SETUP_XfOrM375(_), print_byte_string ((char * ) obj , ((unsigned long ) (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (obj ) ) ) -> s ) - (unsigned long ) (obj ) ) , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (obj ) ) ) -> len ) , notdisplay , pp ) ); 
          }
          else {
            Scheme_Object * s ; 
            BLOCK_SETUP((PUSH(s, 0+XfOrM373_COUNT)));
#           define XfOrM374_COUNT (1+XfOrM373_COUNT)
#           define SETUP_XfOrM374(x) SETUP(XfOrM374_COUNT)
            s = NULLED_OUT ; 
            s = FUNCCALL(SETUP_XfOrM374(_), scheme_make_sized_offset_utf8_string ((char * ) obj , ((unsigned long ) (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (obj ) ) ) -> s ) - (unsigned long ) (obj ) ) , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (obj ) ) ) -> len ) ) ); 
            FUNCCALL_AGAIN(do_print_string (0 , notdisplay , pp , (((Scheme_Simple_Object * ) (s ) ) -> u . char_str_val . string_val ) , 0 , (((Scheme_Simple_Object * ) (s ) ) -> u . char_str_val . tag_val ) ) ); 
          }
        }
        FUNCCALL(SETUP_XfOrM372(_), print_utf8_string (pp , ")" , 0 , 1 ) ); 
      }
      else {
        const char * s ; 
        BLOCK_SETUP((PUSH(s, 0+XfOrM370_COUNT)));
#       define XfOrM371_COUNT (1+XfOrM370_COUNT)
#       define SETUP_XfOrM371(x) SETUP(XfOrM371_COUNT)
        s = NULLED_OUT ; 
        if (is_kw )
          FUNCCALL(SETUP_XfOrM371(_), print_utf8_string (pp , "#:" , 0 , 2 ) ); 
        s = FUNCCALL(SETUP_XfOrM371(_), scheme_symbol_name_and_size (obj , (unsigned int * ) & l , ((pp -> can_read_pipe_quote ? 0x2 : 0x4 ) | (pp -> case_sens ? 0 : 0x8 ) | (is_kw ? 0x10 : 0 ) ) ) ); 
        FUNCCALL_AGAIN(print_utf8_string (pp , s , 0 , l ) ); 
      }
    }
    else {
#     define XfOrM369_COUNT (0+XfOrM368_COUNT)
#     define SETUP_XfOrM369(x) SETUP_XfOrM368(x)
      if (is_kw )
        FUNCCALL(SETUP_XfOrM369(_), print_utf8_string (pp , "#:" , 0 , 2 ) ); 
      FUNCCALL(SETUP_XfOrM369(_), print_utf8_string (pp , (char * ) obj , ((char * ) ((((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (obj ) ) ) -> s ) ) ) - ((char * ) obj ) , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (obj ) ) ) -> len ) ) ); 
    }
  }
  else if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ) {
#   define XfOrM362_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM362(x) SETUP_XfOrM194(x)
    if (compact ) {
      int l ; 
      Scheme_Object * idx ; 
      BLOCK_SETUP((PUSH(idx, 0+XfOrM362_COUNT)));
#     define XfOrM365_COUNT (1+XfOrM362_COUNT)
#     define SETUP_XfOrM365(x) SETUP(XfOrM365_COUNT)
      idx = NULLED_OUT ; 
      idx = FUNCCALL(SETUP_XfOrM365(_), get_symtab_idx (mt , obj ) ); 
      if (idx ) {
#       define XfOrM367_COUNT (0+XfOrM365_COUNT)
#       define SETUP_XfOrM367(x) SETUP_XfOrM365(x)
        FUNCCALL(SETUP_XfOrM367(_), print_symtab_ref (pp , idx ) ); 
      }
      else {
#       define XfOrM366_COUNT (0+XfOrM365_COUNT)
#       define SETUP_XfOrM366(x) SETUP_XfOrM365(x)
        FUNCCALL(SETUP_XfOrM366(_), print_this_string (pp , & compacts [CPT_BYTE_STRING ] , 0 , 1 ) ); 
        l = (((Scheme_Simple_Object * ) (obj ) ) -> u . byte_str_val . tag_val ) ; 
        FUNCCALL(SETUP_XfOrM366(_), print_compact_number (pp , l ) ); 
        FUNCCALL_AGAIN(print_this_string (pp , (((Scheme_Simple_Object * ) (obj ) ) -> u . byte_str_val . string_val ) , 0 , l ) ); 
        FUNCCALL_AGAIN(symtab_set (pp , mt , obj ) ); 
      }
    }
    else {
#     define XfOrM363_COUNT (0+XfOrM362_COUNT)
#     define SETUP_XfOrM363(x) SETUP_XfOrM362(x)
      if (notdisplay ) {
#       define XfOrM364_COUNT (0+XfOrM363_COUNT)
#       define SETUP_XfOrM364(x) SETUP_XfOrM363(x)
        FUNCCALL(SETUP_XfOrM364(_), always_scheme (pp , 0 ) ); 
        FUNCCALL(SETUP_XfOrM364(_), print_utf8_string (pp , "#" , 0 , 1 ) ); 
      }
      FUNCCALL(SETUP_XfOrM363(_), print_byte_string ((((Scheme_Simple_Object * ) (obj ) ) -> u . byte_str_val . string_val ) , 0 , (((Scheme_Simple_Object * ) (obj ) ) -> u . byte_str_val . tag_val ) , notdisplay , pp ) ); 
      closed = 1 ; 
    }
  }
  else if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) ) {
    Scheme_Object * idx ; 
    BLOCK_SETUP((PUSH(idx, 0+XfOrM194_COUNT)));
#   define XfOrM359_COUNT (1+XfOrM194_COUNT)
#   define SETUP_XfOrM359(x) SETUP(XfOrM359_COUNT)
    idx = NULLED_OUT ; 
    if (compact )
      idx = FUNCCALL(SETUP_XfOrM359(_), get_symtab_idx (mt , obj ) ); 
    else idx = ((void * ) 0 ) ; 
    if (idx ) {
#     define XfOrM361_COUNT (0+XfOrM359_COUNT)
#     define SETUP_XfOrM361(x) SETUP_XfOrM359(x)
      FUNCCALL(SETUP_XfOrM361(_), print_symtab_ref (pp , idx ) ); 
    }
    else {
#     define XfOrM360_COUNT (0+XfOrM359_COUNT)
#     define SETUP_XfOrM360(x) SETUP_XfOrM359(x)
      FUNCCALL(SETUP_XfOrM360(_), do_print_string (compact , notdisplay , pp , (((Scheme_Simple_Object * ) (obj ) ) -> u . char_str_val . string_val ) , 0 , (((Scheme_Simple_Object * ) (obj ) ) -> u . char_str_val . tag_val ) ) ); 
      if (compact )
        FUNCCALL(SETUP_XfOrM360(_), symtab_set (pp , mt , obj ) ); 
    }
    closed = 1 ; 
  }
  else if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_char_type ) ) ) {
#   define XfOrM356_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM356(x) SETUP_XfOrM194(x)
    if (compact ) {
      int cv ; 
#     define XfOrM358_COUNT (0+XfOrM356_COUNT)
#     define SETUP_XfOrM358(x) SETUP_XfOrM356(x)
      FUNCCALL(SETUP_XfOrM358(_), print_this_string (pp , & compacts [CPT_CHAR ] , 0 , 1 ) ); 
      cv = (((Scheme_Small_Object * ) (obj ) ) -> u . char_val ) ; 
      FUNCCALL(SETUP_XfOrM358(_), print_compact_number (pp , cv ) ); 
    }
    else if (notdisplay && pp -> honu_mode ) {
      char s [6 ] ; 
      mzchar us [1 ] ; 
      int l ; 
#     define XfOrM357_COUNT (0+XfOrM356_COUNT)
#     define SETUP_XfOrM357(x) SETUP_XfOrM356(x)
      us [0 ] = (((Scheme_Small_Object * ) (obj ) ) -> u . char_val ) ; 
      l = FUNCCALL(SETUP_XfOrM357(_), scheme_utf8_encode (us , 0 , 1 , (unsigned char * ) s , 0 , 0 ) ); 
      FUNCCALL_AGAIN(print_char_string (s , l , us , 0 , 1 , notdisplay , 1 , pp ) ); 
    }
    else FUNCCALL(SETUP_XfOrM356(_), print_char (obj , notdisplay , pp ) ); 
  }
  else if ((((long ) (obj ) ) & 0x1 ) ) {
#   define XfOrM349_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM349(x) SETUP_XfOrM194(x)
    if (compact ) {
      long v = (((long ) (obj ) ) >> 1 ) ; 
#     define XfOrM351_COUNT (0+XfOrM349_COUNT)
#     define SETUP_XfOrM351(x) SETUP_XfOrM349(x)
      if (v >= 0 && v < (60 - 34 ) ) {
        unsigned char s [1 ] ; 
#       define XfOrM355_COUNT (0+XfOrM351_COUNT)
#       define SETUP_XfOrM355(x) SETUP_XfOrM351(x)
        s [0 ] = (unsigned char ) (v + 34 ) ; 
        FUNCCALL(SETUP_XfOrM355(_), print_this_string (pp , (char * ) s , 0 , 1 ) ); 
      }
      else {
#       define XfOrM352_COUNT (0+XfOrM351_COUNT)
#       define SETUP_XfOrM352(x) SETUP_XfOrM351(x)
        if ((v >= - 1073741824 ) && (v <= 1073741823 ) ) {
#         define XfOrM354_COUNT (0+XfOrM352_COUNT)
#         define SETUP_XfOrM354(x) SETUP_XfOrM352(x)
          FUNCCALL(SETUP_XfOrM354(_), print_this_string (pp , & compacts [CPT_INT ] , 0 , 1 ) ); 
          FUNCCALL(SETUP_XfOrM354(_), print_compact_number (pp , v ) ); 
        }
        else {
#         define XfOrM353_COUNT (0+XfOrM352_COUNT)
#         define SETUP_XfOrM353(x) SETUP_XfOrM352(x)
          FUNCCALL(SETUP_XfOrM353(_), print_escaped (pp , notdisplay , obj , ht , mt , 1 ) ); 
        }
      }
    }
    else {
#     define XfOrM350_COUNT (0+XfOrM349_COUNT)
#     define SETUP_XfOrM350(x) SETUP_XfOrM349(x)
      (sprintf (quick_buffer , "%ld" , (((long ) (obj ) ) >> 1 ) ) ) ; 
      FUNCCALL(SETUP_XfOrM350(_), print_utf8_string (pp , quick_buffer , 0 , - 1 ) ); 
    }
  }
  else if (((((long ) (obj ) ) & 0x1 ) || ((((obj ) -> type ) >= scheme_bignum_type ) && (((obj ) -> type ) <= scheme_complex_type ) ) ) ) {
#   define XfOrM346_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM346(x) SETUP_XfOrM194(x)
    if (compact ) {
#     define XfOrM348_COUNT (0+XfOrM346_COUNT)
#     define SETUP_XfOrM348(x) SETUP_XfOrM346(x)
      FUNCCALL(SETUP_XfOrM348(_), print_escaped (pp , notdisplay , obj , ht , mt , 1 ) ); 
      closed = 1 ; 
    }
    else {
#     define XfOrM347_COUNT (0+XfOrM346_COUNT)
#     define SETUP_XfOrM347(x) SETUP_XfOrM346(x)
      if ((! (((long ) (obj ) ) & 0x1 ) && ((((obj ) -> type ) >= scheme_complex_izi_type ) && (((obj ) -> type ) <= scheme_complex_type ) ) ) )
        FUNCCALL(SETUP_XfOrM347(_), always_scheme (pp , 0 ) ); 
      (__funcarg26 = FUNCCALL(SETUP_XfOrM347(_), scheme_number_to_string (10 , obj ) ), FUNCCALL_AGAIN(print_utf8_string (pp , __funcarg26 , 0 , - 1 ) )) ; 
    }
  }
  else if (((obj ) == (scheme_null ) ) ) {
#   define XfOrM343_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM343(x) SETUP_XfOrM194(x)
    if (compact ) {
#     define XfOrM345_COUNT (0+XfOrM343_COUNT)
#     define SETUP_XfOrM345(x) SETUP_XfOrM343(x)
      FUNCCALL(SETUP_XfOrM345(_), print_this_string (pp , & compacts [CPT_NULL ] , 0 , 1 ) ); 
    }
    else {
#     define XfOrM344_COUNT (0+XfOrM343_COUNT)
#     define SETUP_XfOrM344(x) SETUP_XfOrM343(x)
      if (pp -> honu_mode )
        FUNCCALL(SETUP_XfOrM344(_), print_utf8_string (pp , "null" , 0 , 4 ) ); 
      else FUNCCALL(SETUP_XfOrM344(_), print_utf8_string (pp , "()" , 0 , 2 ) ); 
      closed = 1 ; 
    }
  }
  else if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#   define XfOrM342_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM342(x) SETUP_XfOrM194(x)
    FUNCCALL(SETUP_XfOrM342(_), print_pair (obj , notdisplay , compact , ht , mt , pp ) ); 
    closed = 1 ; 
  }
  else if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
#   define XfOrM341_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM341(x) SETUP_XfOrM194(x)
    FUNCCALL(SETUP_XfOrM341(_), print_vector (obj , notdisplay , compact , ht , mt , pp ) ); 
    closed = 1 ; 
  }
  else if ((compact || pp -> print_box ) && ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) {
#   define XfOrM337_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM337(x) SETUP_XfOrM194(x)
    if (compact && ! pp -> print_box ) {
#     define XfOrM340_COUNT (0+XfOrM337_COUNT)
#     define SETUP_XfOrM340(x) SETUP_XfOrM337(x)
      closed = (__funcarg25 = FUNCCALL(SETUP_XfOrM340(_), scheme_protect_quote (obj ) ), FUNCCALL_AGAIN(print (__funcarg25 , notdisplay , compact , ht , mt , pp ) )) ; 
    }
    else {
#     define XfOrM338_COUNT (0+XfOrM337_COUNT)
#     define SETUP_XfOrM338(x) SETUP_XfOrM337(x)
      if (compact )
        FUNCCALL(SETUP_XfOrM338(_), print_this_string (pp , & compacts [CPT_BOX ] , 0 , 1 ) ); 
      else {
#       define XfOrM339_COUNT (0+XfOrM338_COUNT)
#       define SETUP_XfOrM339(x) SETUP_XfOrM338(x)
        FUNCCALL(SETUP_XfOrM339(_), always_scheme (pp , 1 ) ); 
        FUNCCALL(SETUP_XfOrM339(_), print_utf8_string (pp , "#&" , 0 , 2 ) ); 
      }
      closed = FUNCCALL(SETUP_XfOrM338(_), print ((((Scheme_Small_Object * ) (obj ) ) -> u . ptr_val ) , notdisplay , compact , ht , mt , pp ) ); 
    }
  }
  else if ((compact || pp -> print_hash_table ) && ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) ) {
    Scheme_Hash_Table * t ; 
    Scheme_Object * * keys , * * vals , * val ; 
    int i , size , did_one = 0 ; 
    BLOCK_SETUP((PUSH(vals, 0+XfOrM194_COUNT), PUSH(t, 1+XfOrM194_COUNT), PUSH(val, 2+XfOrM194_COUNT), PUSH(keys, 3+XfOrM194_COUNT)));
#   define XfOrM328_COUNT (4+XfOrM194_COUNT)
#   define SETUP_XfOrM328(x) SETUP(XfOrM328_COUNT)
    t = NULLED_OUT ; 
    keys = NULLED_OUT ; 
    vals = NULLED_OUT ; 
    val = NULLED_OUT ; 
    if (compact ) {
#     define XfOrM336_COUNT (0+XfOrM328_COUNT)
#     define SETUP_XfOrM336(x) SETUP_XfOrM328(x)
      FUNCCALL(SETUP_XfOrM336(_), print_this_string (pp , & compacts [CPT_HASH_TABLE ] , 0 , 1 ) ); 
      if (FUNCCALL(SETUP_XfOrM336(_), scheme_is_hash_table_equal (obj ) ))
        FUNCCALL(SETUP_XfOrM336(_), print_compact_number (pp , 1 ) ); 
      else FUNCCALL(SETUP_XfOrM336(_), print_compact_number (pp , 0 ) ); 
    }
    else {
#     define XfOrM335_COUNT (0+XfOrM328_COUNT)
#     define SETUP_XfOrM335(x) SETUP_XfOrM328(x)
      FUNCCALL(SETUP_XfOrM335(_), always_scheme (pp , 1 ) ); 
      FUNCCALL(SETUP_XfOrM335(_), print_utf8_string (pp , "#hash" , 0 , 5 ) ); 
      if (! FUNCCALL(SETUP_XfOrM335(_), scheme_is_hash_table_equal (obj ) ))
        FUNCCALL(SETUP_XfOrM335(_), print_utf8_string (pp , "eq" , 0 , 2 ) ); 
      FUNCCALL(SETUP_XfOrM335(_), print_utf8_string (pp , "(" , 0 , 1 ) ); 
    }
    t = (Scheme_Hash_Table * ) obj ; 
    if (compact )
      FUNCCALL(SETUP_XfOrM328(_), print_compact_number (pp , t -> count ) ); 
    keys = t -> keys ; 
    vals = t -> vals ; 
    size = t -> size ; 
    for (i = 0 ; i < size ; i ++ ) {
#     define XfOrM332_COUNT (0+XfOrM328_COUNT)
#     define SETUP_XfOrM332(x) SETUP_XfOrM328(x)
      if (vals [i ] ) {
#       define XfOrM333_COUNT (0+XfOrM332_COUNT)
#       define SETUP_XfOrM333(x) SETUP_XfOrM332(x)
        if (! compact ) {
#         define XfOrM334_COUNT (0+XfOrM333_COUNT)
#         define SETUP_XfOrM334(x) SETUP_XfOrM333(x)
          if (did_one )
            FUNCCALL(SETUP_XfOrM334(_), print_utf8_string (pp , " " , 0 , 1 ) ); 
          FUNCCALL(SETUP_XfOrM334(_), print_utf8_string (pp , "(" , 0 , 1 ) ); 
        }
        val = vals [i ] ; 
        FUNCCALL(SETUP_XfOrM333(_), print (keys [i ] , notdisplay , compact , ht , mt , pp ) ); 
        if (! compact )
          FUNCCALL(SETUP_XfOrM333(_), print_utf8_string (pp , " . " , 0 , 3 ) ); 
        FUNCCALL(SETUP_XfOrM333(_), print (val , notdisplay , compact , ht , mt , pp ) ); 
        if (! compact )
          FUNCCALL(SETUP_XfOrM333(_), print_utf8_string (pp , ")" , 0 , 1 ) ); 
        did_one ++ ; 
      }
    }
    if (! compact )
      FUNCCALL(SETUP_XfOrM328(_), print_utf8_string (pp , ")" , 0 , 1 ) ); 
    closed = 1 ; 
  }
  else if (((obj ) == (scheme_true ) ) ) {
#   define XfOrM327_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM327(x) SETUP_XfOrM194(x)
    if (compact )
      FUNCCALL(SETUP_XfOrM327(_), print_this_string (pp , & compacts [CPT_TRUE ] , 0 , 1 ) ); 
    else if (pp -> honu_mode )
      FUNCCALL(SETUP_XfOrM327(_), print_utf8_string (pp , "true" , 0 , 4 ) ); 
    else FUNCCALL(SETUP_XfOrM327(_), print_utf8_string (pp , "#t" , 0 , 2 ) ); 
  }
  else if (((obj ) == (scheme_false ) ) ) {
#   define XfOrM326_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM326(x) SETUP_XfOrM194(x)
    if (compact )
      FUNCCALL(SETUP_XfOrM326(_), print_this_string (pp , & compacts [CPT_FALSE ] , 0 , 1 ) ); 
    else if (pp -> honu_mode )
      FUNCCALL(SETUP_XfOrM326(_), print_utf8_string (pp , "false" , 0 , 5 ) ); 
    else FUNCCALL(SETUP_XfOrM326(_), print_utf8_string (pp , "#f" , 0 , 2 ) ); 
  }
  else if (compact && ((obj ) == (scheme_void ) ) ) {
#   define XfOrM325_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM325(x) SETUP_XfOrM194(x)
    FUNCCALL(SETUP_XfOrM325(_), print_this_string (pp , & compacts [CPT_VOID ] , 0 , 1 ) ); 
  }
  else if ((((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) ) {
#   define XfOrM316_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM316(x) SETUP_XfOrM194(x)
    if (compact || ! pp -> print_unreadable )
      FUNCCALL(SETUP_XfOrM316(_), cannot_print (pp , notdisplay , obj , ht , compact ) ); 
    else if (FUNCCALL(SETUP_XfOrM316(_), scheme_is_writable_struct (obj ) )) {
#     define XfOrM324_COUNT (0+XfOrM316_COUNT)
#     define SETUP_XfOrM324(x) SETUP_XfOrM316(x)
      FUNCCALL(SETUP_XfOrM324(_), custom_write_struct (obj , ht , mt , pp , notdisplay ) ); 
    }
    else {
      int pb ; 
#     define XfOrM317_COUNT (0+XfOrM316_COUNT)
#     define SETUP_XfOrM317(x) SETUP_XfOrM316(x)
      pb = pp -> print_struct && (FUNCCALL(SETUP_XfOrM317(_), scheme_inspector_sees_part (obj , pp -> inspector , - 1 ) )) ; 
      if (pb ) {
#       define XfOrM323_COUNT (0+XfOrM317_COUNT)
#       define SETUP_XfOrM323(x) SETUP_XfOrM317(x)
        obj = FUNCCALL(SETUP_XfOrM323(_), scheme_struct_to_vector (obj , ((void * ) 0 ) , pp -> inspector ) ); 
        closed = FUNCCALL(SETUP_XfOrM323(_), print (obj , notdisplay , compact , ht , mt , pp ) ); 
      }
      else {
        Scheme_Object * src ; 
        BLOCK_SETUP((PUSH(src, 0+XfOrM317_COUNT)));
#       define XfOrM318_COUNT (1+XfOrM317_COUNT)
#       define SETUP_XfOrM318(x) SETUP(XfOrM318_COUNT)
        src = NULLED_OUT ; 
        if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) {
#         define XfOrM322_COUNT (0+XfOrM318_COUNT)
#         define SETUP_XfOrM322(x) SETUP_XfOrM318(x)
          src = FUNCCALL(SETUP_XfOrM322(_), scheme_proc_struct_name_source (obj ) ); 
        }
        else src = obj ; 
        if (((src ) == (obj ) ) ) {
#         define XfOrM320_COUNT (0+XfOrM318_COUNT)
#         define SETUP_XfOrM320(x) SETUP_XfOrM318(x)
          FUNCCALL(SETUP_XfOrM320(_), print_utf8_string (pp , "#<struct:" , 0 , 9 ) ); 
          {
            int l ; 
            const char * s ; 
            Scheme_Object * name = ((((Scheme_Structure * ) obj ) -> stype ) -> name ) ; 
            BLOCK_SETUP((PUSH(s, 0+XfOrM320_COUNT)));
#           define XfOrM321_COUNT (1+XfOrM320_COUNT)
#           define SETUP_XfOrM321(x) SETUP(XfOrM321_COUNT)
            s = NULLED_OUT ; 
            s = FUNCCALL(SETUP_XfOrM321(_), scheme_symbol_name_and_size (name , (unsigned int * ) & l , (pp -> print_struct ? 0x1 : (pp -> can_read_pipe_quote ? 0x2 : 0x4 ) ) ) ); 
            FUNCCALL_AGAIN(print_utf8_string (pp , s , 0 , l ) ); 
          }
          ; 
          FUNCCALL(SETUP_XfOrM320(_), print_utf8_string (pp , ">" , 0 , 1 ) ); 
        }
        else {
#         define XfOrM319_COUNT (0+XfOrM318_COUNT)
#         define SETUP_XfOrM319(x) SETUP_XfOrM318(x)
          closed = FUNCCALL(SETUP_XfOrM319(_), print (src , notdisplay , compact , ht , mt , pp ) ); 
        }
      }
    }
    closed = 1 ; 
  }
  else if (((((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) >= scheme_unix_path_type ) && (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) <= scheme_windows_path_type ) ) ) {
#   define XfOrM303_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM303(x) SETUP_XfOrM194(x)
    if (compact && ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) {
      Scheme_Object * idx ; 
      int l ; 
      BLOCK_SETUP((PUSH(idx, 0+XfOrM303_COUNT)));
#     define XfOrM312_COUNT (1+XfOrM303_COUNT)
#     define SETUP_XfOrM312(x) SETUP(XfOrM312_COUNT)
      idx = NULLED_OUT ; 
      idx = FUNCCALL(SETUP_XfOrM312(_), get_symtab_idx (mt , obj ) ); 
      if (idx ) {
#       define XfOrM315_COUNT (0+XfOrM312_COUNT)
#       define SETUP_XfOrM315(x) SETUP_XfOrM312(x)
        FUNCCALL(SETUP_XfOrM315(_), print_symtab_ref (pp , idx ) ); 
      }
      else {
        Scheme_Object * orig_obj = obj , * dir ; 
        BLOCK_SETUP((PUSH(orig_obj, 0+XfOrM312_COUNT), PUSH(dir, 1+XfOrM312_COUNT)));
#       define XfOrM313_COUNT (2+XfOrM312_COUNT)
#       define SETUP_XfOrM313(x) SETUP(XfOrM313_COUNT)
        dir = NULLED_OUT ; 
        dir = (__funcarg24 = FUNCCALL(SETUP_XfOrM313(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg24 , MZCONFIG_WRITE_DIRECTORY ) )) ; 
        if (((Scheme_Type ) (((((long ) (dir ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (dir ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) {
#         define XfOrM314_COUNT (0+XfOrM313_COUNT)
#         define SETUP_XfOrM314(x) SETUP_XfOrM313(x)
          obj = FUNCCALL(SETUP_XfOrM314(_), scheme_extract_relative_to (obj , dir ) ); 
        }
        FUNCCALL(SETUP_XfOrM313(_), print_this_string (pp , & compacts [CPT_PATH ] , 0 , 1 ) ); 
        l = (((Scheme_Simple_Object * ) (obj ) ) -> u . byte_str_val . tag_val ) ; 
        FUNCCALL(SETUP_XfOrM313(_), print_compact_number (pp , l ) ); 
        FUNCCALL_AGAIN(print_this_string (pp , (((Scheme_Simple_Object * ) (obj ) ) -> u . byte_str_val . string_val ) , 0 , l ) ); 
        FUNCCALL_AGAIN(symtab_set (pp , mt , orig_obj ) ); 
      }
    }
    else if (! pp -> print_unreadable ) {
#     define XfOrM311_COUNT (0+XfOrM303_COUNT)
#     define SETUP_XfOrM311(x) SETUP_XfOrM303(x)
      FUNCCALL(SETUP_XfOrM311(_), cannot_print (pp , notdisplay , obj , ht , compact ) ); 
    }
    else {
#     define XfOrM304_COUNT (0+XfOrM303_COUNT)
#     define SETUP_XfOrM304(x) SETUP_XfOrM303(x)
      if (notdisplay ) {
#       define XfOrM307_COUNT (0+XfOrM304_COUNT)
#       define SETUP_XfOrM307(x) SETUP_XfOrM304(x)
        if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) {
#         define XfOrM310_COUNT (0+XfOrM307_COUNT)
#         define SETUP_XfOrM310(x) SETUP_XfOrM307(x)
          FUNCCALL(SETUP_XfOrM310(_), print_utf8_string (pp , "#<path:" , 0 , 7 ) ); 
        }
        else {
#         define XfOrM308_COUNT (0+XfOrM307_COUNT)
#         define SETUP_XfOrM308(x) SETUP_XfOrM307(x)
          switch (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) {
#           define XfOrM309_COUNT (0+XfOrM308_COUNT)
#           define SETUP_XfOrM309(x) SETUP_XfOrM308(x)
            case scheme_windows_path_type : FUNCCALL(SETUP_XfOrM309(_), print_utf8_string (pp , "#<windows-path:" , 0 , 15 ) ); 
            break ; 
            default : case scheme_unix_path_type : FUNCCALL(SETUP_XfOrM309(_), print_utf8_string (pp , "#<unix-path:" , 0 , 12 ) ); 
            break ; 
          }
        }
      }
      {
        Scheme_Object * str ; 
        BLOCK_SETUP((PUSH(str, 0+XfOrM304_COUNT)));
#       define XfOrM306_COUNT (1+XfOrM304_COUNT)
#       define SETUP_XfOrM306(x) SETUP(XfOrM306_COUNT)
        str = NULLED_OUT ; 
        str = FUNCCALL(SETUP_XfOrM306(_), scheme_path_to_char_string (obj ) ); 
        FUNCCALL_AGAIN(print (str , 0 , 0 , ht , mt , pp ) ); 
      }
      if (notdisplay ) {
#       define XfOrM305_COUNT (0+XfOrM304_COUNT)
#       define SETUP_XfOrM305(x) SETUP_XfOrM304(x)
        ; 
        FUNCCALL(SETUP_XfOrM305(_), print_utf8_string (pp , ">" , 0 , 1 ) ); 
      }
    }
  }
  else if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_prim_type ) ) && ((Scheme_Primitive_Proc * ) obj ) -> name ) {
#   define XfOrM300_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM300(x) SETUP_XfOrM194(x)
    if (compact || ! pp -> print_unreadable ) {
#     define XfOrM302_COUNT (0+XfOrM300_COUNT)
#     define SETUP_XfOrM302(x) SETUP_XfOrM300(x)
      FUNCCALL(SETUP_XfOrM302(_), cannot_print (pp , notdisplay , obj , ht , compact ) ); 
    }
    else {
#     define XfOrM301_COUNT (0+XfOrM300_COUNT)
#     define SETUP_XfOrM301(x) SETUP_XfOrM300(x)
      FUNCCALL(SETUP_XfOrM301(_), print_utf8_string (pp , "#<" , 0 , 2 ) ); 
      FUNCCALL(SETUP_XfOrM301(_), print_string_in_angle (pp , ((Scheme_Primitive_Proc * ) obj ) -> name , "primitive:" , - 1 ) ); 
      ; 
      FUNCCALL_AGAIN(print_utf8_string (pp , ">" , 0 , 1 ) ); 
    }
    closed = 1 ; 
  }
  else if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_closed_prim_type ) ) && ((Scheme_Closed_Primitive_Proc * ) obj ) -> name ) {
#   define XfOrM296_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM296(x) SETUP_XfOrM194(x)
    if (compact || ! pp -> print_unreadable )
      FUNCCALL(SETUP_XfOrM296(_), cannot_print (pp , notdisplay , obj , ht , compact ) ); 
    else {
#     define XfOrM297_COUNT (0+XfOrM296_COUNT)
#     define SETUP_XfOrM297(x) SETUP_XfOrM296(x)
      if ((((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_prim_type ) ) && (((Scheme_Primitive_Proc * ) (obj ) ) -> pp . flags & (4 | 8 | 32 ) ) ) ) {
#       define XfOrM299_COUNT (0+XfOrM297_COUNT)
#       define SETUP_XfOrM299(x) SETUP_XfOrM297(x)
        FUNCCALL(SETUP_XfOrM299(_), print_named (obj , "struct-procedure" , ((Scheme_Closed_Primitive_Proc * ) obj ) -> name , - 1 , pp ) ); 
      }
      else {
#       define XfOrM298_COUNT (0+XfOrM297_COUNT)
#       define SETUP_XfOrM298(x) SETUP_XfOrM297(x)
        FUNCCALL(SETUP_XfOrM298(_), print_utf8_string (pp , "#<" , 0 , 2 ) ); 
        FUNCCALL(SETUP_XfOrM298(_), print_string_in_angle (pp , ((Scheme_Closed_Primitive_Proc * ) obj ) -> name , "primitive:" , - 1 ) ); 
        ; 
        FUNCCALL_AGAIN(print_utf8_string (pp , ">" , 0 , 1 ) ); 
      }
    }
    closed = 1 ; 
  }
  else if ((((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_closure_type ) ) || ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_case_closure_type ) ) ) || ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_native_closure_type ) ) ) {
#   define XfOrM286_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM286(x) SETUP_XfOrM194(x)
    if (compact || ! pp -> print_unreadable ) {
      int done = 0 ; 
#     define XfOrM288_COUNT (0+XfOrM286_COUNT)
#     define SETUP_XfOrM288(x) SETUP_XfOrM286(x)
      if (compact ) {
#       define XfOrM289_COUNT (0+XfOrM288_COUNT)
#       define SETUP_XfOrM289(x) SETUP_XfOrM288(x)
        if (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) == scheme_closure_type ) {
          Scheme_Closure * closure = (Scheme_Closure * ) obj ; 
          BLOCK_SETUP((PUSH(closure, 0+XfOrM289_COUNT)));
#         define XfOrM292_COUNT (1+XfOrM289_COUNT)
#         define SETUP_XfOrM292(x) SETUP(XfOrM292_COUNT)
          if (! (closure -> code -> closure_size ) ) {
            Scheme_Object * idx ; 
            BLOCK_SETUP((PUSH(idx, 0+XfOrM292_COUNT)));
#           define XfOrM293_COUNT (1+XfOrM292_COUNT)
#           define SETUP_XfOrM293(x) SETUP(XfOrM293_COUNT)
            idx = NULLED_OUT ; 
            idx = FUNCCALL(SETUP_XfOrM293(_), get_symtab_idx (mt , obj ) ); 
            if (idx ) {
#             define XfOrM295_COUNT (0+XfOrM293_COUNT)
#             define SETUP_XfOrM295(x) SETUP_XfOrM293(x)
              FUNCCALL(SETUP_XfOrM295(_), print_symtab_ref (pp , idx ) ); 
            }
            else {
#             define XfOrM294_COUNT (0+XfOrM293_COUNT)
#             define SETUP_XfOrM294(x) SETUP_XfOrM293(x)
              FUNCCALL(SETUP_XfOrM294(_), print_this_string (pp , & compacts [CPT_CLOSURE ] , 0 , 1 ) ); 
              FUNCCALL(SETUP_XfOrM294(_), print_symtab_set (pp , mt , obj ) ); 
              FUNCCALL_AGAIN(print ((Scheme_Object * ) ((Scheme_Closure * ) closure ) -> code , notdisplay , compact , ht , mt , pp ) ); 
            }
            compact = 1 ; 
            done = 1 ; 
          }
        }
        else if (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) == scheme_case_closure_type ) {
#         define XfOrM290_COUNT (0+XfOrM289_COUNT)
#         define SETUP_XfOrM290(x) SETUP_XfOrM289(x)
          obj = FUNCCALL(SETUP_XfOrM290(_), scheme_unclose_case_lambda (obj , 0 ) ); 
          if (! (! (((long ) (obj ) ) & 0x1 ) && ((((obj ) -> type ) >= scheme_prim_type ) && (((obj ) -> type ) <= scheme_native_closure_type ) ) ) ) {
#           define XfOrM291_COUNT (0+XfOrM290_COUNT)
#           define SETUP_XfOrM291(x) SETUP_XfOrM290(x)
            compact = FUNCCALL(SETUP_XfOrM291(_), print (obj , notdisplay , compact , ht , mt , pp ) ); 
            done = 1 ; 
          }
        }
      }
      if (! done )
        FUNCCALL(SETUP_XfOrM288(_), cannot_print (pp , notdisplay , obj , ht , compact ) ); 
    }
    else {
      int len ; 
      const char * s ; 
      BLOCK_SETUP((PUSH(s, 0+XfOrM286_COUNT)));
#     define XfOrM287_COUNT (1+XfOrM286_COUNT)
#     define SETUP_XfOrM287(x) SETUP(XfOrM287_COUNT)
      s = NULLED_OUT ; 
      s = FUNCCALL(SETUP_XfOrM287(_), scheme_get_proc_name (obj , & len , 0 ) ); 
      FUNCCALL_AGAIN(print_named (obj , "procedure" , s , len , pp ) ); 
    }
    closed = 1 ; 
  }
  else if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_struct_type_type ) ) ) {
#   define XfOrM283_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM283(x) SETUP_XfOrM194(x)
    if (compact || ! pp -> print_unreadable ) {
#     define XfOrM285_COUNT (0+XfOrM283_COUNT)
#     define SETUP_XfOrM285(x) SETUP_XfOrM283(x)
      FUNCCALL(SETUP_XfOrM285(_), cannot_print (pp , notdisplay , obj , ht , compact ) ); 
    }
    else {
#     define XfOrM284_COUNT (0+XfOrM283_COUNT)
#     define SETUP_XfOrM284(x) SETUP_XfOrM283(x)
      FUNCCALL(SETUP_XfOrM284(_), print_utf8_string (pp , "#<" , 0 , 2 ) ); 
      (__funcarg23 = FUNCCALL(SETUP_XfOrM284(_), scheme_symbol_val (((Scheme_Struct_Type * ) obj ) -> name ) ), FUNCCALL_AGAIN(print_string_in_angle (pp , __funcarg23 , "struct-type:" , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (((Scheme_Struct_Type * ) obj ) -> name ) ) ) -> len ) ) )) ; 
      ; 
      FUNCCALL_AGAIN(print_utf8_string (pp , ">" , 0 , 1 ) ); 
    }
  }
  else if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_struct_property_type ) ) ) {
#   define XfOrM280_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM280(x) SETUP_XfOrM194(x)
    if (compact || ! pp -> print_unreadable ) {
#     define XfOrM282_COUNT (0+XfOrM280_COUNT)
#     define SETUP_XfOrM282(x) SETUP_XfOrM280(x)
      FUNCCALL(SETUP_XfOrM282(_), cannot_print (pp , notdisplay , obj , ht , compact ) ); 
    }
    else {
#     define XfOrM281_COUNT (0+XfOrM280_COUNT)
#     define SETUP_XfOrM281(x) SETUP_XfOrM280(x)
      FUNCCALL(SETUP_XfOrM281(_), print_utf8_string (pp , "#<" , 0 , 2 ) ); 
      (__funcarg22 = FUNCCALL(SETUP_XfOrM281(_), scheme_symbol_val (((Scheme_Struct_Property * ) obj ) -> name ) ), FUNCCALL_AGAIN(print_string_in_angle (pp , __funcarg22 , "struct-type-property:" , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (((Scheme_Struct_Property * ) obj ) -> name ) ) ) -> len ) ) )) ; 
      ; 
      FUNCCALL_AGAIN(print_utf8_string (pp , ">" , 0 , 1 ) ); 
    }
  }
  else if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_thread_type ) ) && (((Scheme_Thread * ) obj ) -> name ) ) {
#   define XfOrM277_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM277(x) SETUP_XfOrM194(x)
    if (compact || ! pp -> print_unreadable ) {
#     define XfOrM279_COUNT (0+XfOrM277_COUNT)
#     define SETUP_XfOrM279(x) SETUP_XfOrM277(x)
      FUNCCALL(SETUP_XfOrM279(_), cannot_print (pp , notdisplay , obj , ht , compact ) ); 
    }
    else {
      Scheme_Thread * t = (Scheme_Thread * ) obj ; 
      BLOCK_SETUP((PUSH(t, 0+XfOrM277_COUNT)));
#     define XfOrM278_COUNT (1+XfOrM277_COUNT)
#     define SETUP_XfOrM278(x) SETUP(XfOrM278_COUNT)
      FUNCCALL(SETUP_XfOrM278(_), print_utf8_string (pp , "#<thread:" , 0 , 9 ) ); 
      (__funcarg21 = FUNCCALL(SETUP_XfOrM278(_), scheme_symbol_val (t -> name ) ), FUNCCALL_AGAIN(print_utf8_string (pp , __funcarg21 , 0 , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (t -> name ) ) ) -> len ) ) )) ; 
      FUNCCALL_AGAIN(print_utf8_string (pp , ">" , 0 , 1 ) ); 
    }
  }
  else if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_input_port_type ) ) ) {
#   define XfOrM271_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM271(x) SETUP_XfOrM194(x)
    if (compact || ! pp -> print_unreadable ) {
#     define XfOrM276_COUNT (0+XfOrM271_COUNT)
#     define SETUP_XfOrM276(x) SETUP_XfOrM271(x)
      FUNCCALL(SETUP_XfOrM276(_), cannot_print (pp , notdisplay , obj , ht , compact ) ); 
    }
    else {
      Scheme_Input_Port * ip ; 
      BLOCK_SETUP((PUSH(ip, 0+XfOrM271_COUNT)));
#     define XfOrM272_COUNT (1+XfOrM271_COUNT)
#     define SETUP_XfOrM272(x) SETUP(XfOrM272_COUNT)
      ip = NULLED_OUT ; 
      ip = (Scheme_Input_Port * ) obj ; 
      FUNCCALL(SETUP_XfOrM272(_), print_utf8_string (pp , "#<input-port" , 0 , 12 ) ); 
      if (ip -> name ) {
#       define XfOrM273_COUNT (0+XfOrM272_COUNT)
#       define SETUP_XfOrM273(x) SETUP_XfOrM272(x)
        if (((Scheme_Type ) (((((long ) (ip -> name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ip -> name ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) {
#         define XfOrM275_COUNT (0+XfOrM273_COUNT)
#         define SETUP_XfOrM275(x) SETUP_XfOrM273(x)
          FUNCCALL(SETUP_XfOrM275(_), print_utf8_string (pp , ":" , 0 , 1 ) ); 
          FUNCCALL(SETUP_XfOrM275(_), print_utf8_string (pp , (((Scheme_Simple_Object * ) (ip -> name ) ) -> u . byte_str_val . string_val ) , 0 , (((Scheme_Simple_Object * ) (ip -> name ) ) -> u . byte_str_val . tag_val ) ) ); 
        }
        else if (((Scheme_Type ) (((((long ) (ip -> name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ip -> name ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
#         define XfOrM274_COUNT (0+XfOrM273_COUNT)
#         define SETUP_XfOrM274(x) SETUP_XfOrM273(x)
          FUNCCALL(SETUP_XfOrM274(_), print_utf8_string (pp , ":" , 0 , 1 ) ); 
          (__funcarg20 = FUNCCALL(SETUP_XfOrM274(_), scheme_symbol_val (ip -> name ) ), FUNCCALL_AGAIN(print_utf8_string (pp , __funcarg20 , 0 , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (ip -> name ) ) ) -> len ) ) )) ; 
        }
      }
      FUNCCALL(SETUP_XfOrM272(_), print_utf8_string (pp , ">" , 0 , 1 ) ); 
    }
  }
  else if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_regexp_type ) ) ) {
#   define XfOrM267_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM267(x) SETUP_XfOrM194(x)
    if (compact ) {
#     define XfOrM270_COUNT (0+XfOrM267_COUNT)
#     define SETUP_XfOrM270(x) SETUP_XfOrM267(x)
      FUNCCALL(SETUP_XfOrM270(_), print_escaped (pp , notdisplay , obj , ht , mt , 1 ) ); 
    }
    else {
      Scheme_Object * src ; 
      BLOCK_SETUP((PUSH(src, 0+XfOrM267_COUNT)));
#     define XfOrM268_COUNT (1+XfOrM267_COUNT)
#     define SETUP_XfOrM268(x) SETUP(XfOrM268_COUNT)
      src = NULLED_OUT ; 
      src = FUNCCALL(SETUP_XfOrM268(_), scheme_regexp_source (obj ) ); 
      if (src ) {
#       define XfOrM269_COUNT (0+XfOrM268_COUNT)
#       define SETUP_XfOrM269(x) SETUP_XfOrM268(x)
        if (FUNCCALL(SETUP_XfOrM269(_), scheme_is_pregexp (obj ) ))
          FUNCCALL(SETUP_XfOrM269(_), print_utf8_string (pp , "#px" , 0 , 3 ) ); 
        else FUNCCALL(SETUP_XfOrM269(_), print_utf8_string (pp , "#rx" , 0 , 3 ) ); 
        FUNCCALL(SETUP_XfOrM269(_), print (src , 1 , 0 , ht , mt , pp ) ); 
      }
      else if (compact || ! pp -> print_unreadable )
        FUNCCALL(SETUP_XfOrM268(_), cannot_print (pp , notdisplay , obj , ht , compact ) ); 
      else FUNCCALL(SETUP_XfOrM268(_), print_utf8_string (pp , "#<regexp>" , 0 , 9 ) ); 
      closed = 1 ; 
    }
  }
  else if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_output_port_type ) ) ) {
#   define XfOrM261_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM261(x) SETUP_XfOrM194(x)
    if (compact || ! pp -> print_unreadable ) {
#     define XfOrM266_COUNT (0+XfOrM261_COUNT)
#     define SETUP_XfOrM266(x) SETUP_XfOrM261(x)
      FUNCCALL(SETUP_XfOrM266(_), cannot_print (pp , notdisplay , obj , ht , compact ) ); 
    }
    else {
      Scheme_Output_Port * op ; 
      BLOCK_SETUP((PUSH(op, 0+XfOrM261_COUNT)));
#     define XfOrM262_COUNT (1+XfOrM261_COUNT)
#     define SETUP_XfOrM262(x) SETUP(XfOrM262_COUNT)
      op = NULLED_OUT ; 
      op = (Scheme_Output_Port * ) obj ; 
      FUNCCALL(SETUP_XfOrM262(_), print_utf8_string (pp , "#<output-port" , 0 , 13 ) ); 
      if (op -> name ) {
#       define XfOrM263_COUNT (0+XfOrM262_COUNT)
#       define SETUP_XfOrM263(x) SETUP_XfOrM262(x)
        if (((Scheme_Type ) (((((long ) (op -> name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (op -> name ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) {
#         define XfOrM265_COUNT (0+XfOrM263_COUNT)
#         define SETUP_XfOrM265(x) SETUP_XfOrM263(x)
          FUNCCALL(SETUP_XfOrM265(_), print_utf8_string (pp , ":" , 0 , 1 ) ); 
          FUNCCALL(SETUP_XfOrM265(_), print_utf8_string (pp , (((Scheme_Simple_Object * ) (op -> name ) ) -> u . byte_str_val . string_val ) , 0 , (((Scheme_Simple_Object * ) (op -> name ) ) -> u . byte_str_val . tag_val ) ) ); 
        }
        else if (((Scheme_Type ) (((((long ) (op -> name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (op -> name ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
#         define XfOrM264_COUNT (0+XfOrM263_COUNT)
#         define SETUP_XfOrM264(x) SETUP_XfOrM263(x)
          FUNCCALL(SETUP_XfOrM264(_), print_utf8_string (pp , ":" , 0 , 1 ) ); 
          (__funcarg19 = FUNCCALL(SETUP_XfOrM264(_), scheme_symbol_val (op -> name ) ), FUNCCALL_AGAIN(print_utf8_string (pp , __funcarg19 , 0 , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (op -> name ) ) ) -> len ) ) )) ; 
        }
      }
      FUNCCALL(SETUP_XfOrM262(_), print_utf8_string (pp , ">" , 0 , 1 ) ); 
    }
  }
  else if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_prompt_tag_type ) ) && (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) && ! (compact || ! pp -> print_unreadable ) ) {
#   define XfOrM260_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM260(x) SETUP_XfOrM194(x)
    FUNCCALL(SETUP_XfOrM260(_), print_utf8_string (pp , "#<" , 0 , 2 ) ); 
    (__funcarg18 = FUNCCALL(SETUP_XfOrM260(_), scheme_symbol_val ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ) ), FUNCCALL_AGAIN(print_string_in_angle (pp , __funcarg18 , "continuation-prompt-tag:" , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ) ) ) -> len ) ) )) ; 
    ; 
    FUNCCALL_AGAIN(print_utf8_string (pp , ">" , 0 , 1 ) ); 
  }
  else if ((((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_cpointer_type ) ) || ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_offset_cpointer_type ) ) ) ) {
    Scheme_Object * tag = (((Scheme_Cptr * ) (obj ) ) -> type ) ; 
    BLOCK_SETUP((PUSH(tag, 0+XfOrM194_COUNT)));
#   define XfOrM252_COUNT (1+XfOrM194_COUNT)
#   define SETUP_XfOrM252(x) SETUP(XfOrM252_COUNT)
    if (compact || ! pp -> print_unreadable ) {
#     define XfOrM259_COUNT (0+XfOrM252_COUNT)
#     define SETUP_XfOrM259(x) SETUP_XfOrM252(x)
      FUNCCALL(SETUP_XfOrM259(_), cannot_print (pp , notdisplay , obj , ht , compact ) ); 
    }
    else if (tag == ((void * ) 0 ) ) {
#     define XfOrM258_COUNT (0+XfOrM252_COUNT)
#     define SETUP_XfOrM258(x) SETUP_XfOrM252(x)
      FUNCCALL(SETUP_XfOrM258(_), print_utf8_string (pp , "#<cpointer>" , 0 , 11 ) ); 
    }
    else {
      Scheme_Object * name = tag ; 
      BLOCK_SETUP((PUSH(name, 0+XfOrM252_COUNT)));
#     define XfOrM253_COUNT (1+XfOrM252_COUNT)
#     define SETUP_XfOrM253(x) SETUP(XfOrM253_COUNT)
      if (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
        name = (((Scheme_Simple_Object * ) (name ) ) -> u . pair_val . car ) ; 
      FUNCCALL(SETUP_XfOrM253(_), print_utf8_string (pp , "#<cpointer:" , 0 , 11 ) ); 
      if (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
#       define XfOrM257_COUNT (0+XfOrM253_COUNT)
#       define SETUP_XfOrM257(x) SETUP_XfOrM253(x)
        FUNCCALL(SETUP_XfOrM257(_), print_this_string (pp , (char * ) name , ((char * ) ((((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (name ) ) ) -> s ) ) ) - ((char * ) name ) , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (name ) ) ) -> len ) ) ); 
      }
      else if (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ) {
#       define XfOrM256_COUNT (0+XfOrM253_COUNT)
#       define SETUP_XfOrM256(x) SETUP_XfOrM253(x)
        FUNCCALL(SETUP_XfOrM256(_), print_byte_string ((((Scheme_Simple_Object * ) (name ) ) -> u . byte_str_val . string_val ) , 0 , (((Scheme_Simple_Object * ) (name ) ) -> u . byte_str_val . tag_val ) , 0 , pp ) ); 
      }
      else if (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) ) {
#       define XfOrM255_COUNT (0+XfOrM253_COUNT)
#       define SETUP_XfOrM255(x) SETUP_XfOrM253(x)
        FUNCCALL(SETUP_XfOrM255(_), scheme_print_string (pp , (((Scheme_Simple_Object * ) (name ) ) -> u . char_str_val . string_val ) , 0 , (((Scheme_Simple_Object * ) (name ) ) -> u . char_str_val . tag_val ) ) ); 
      }
      else {
#       define XfOrM254_COUNT (0+XfOrM253_COUNT)
#       define SETUP_XfOrM254(x) SETUP_XfOrM253(x)
        FUNCCALL(SETUP_XfOrM254(_), print_utf8_string (pp , "#" , 0 , 1 ) ); 
      }
      FUNCCALL(SETUP_XfOrM253(_), print_utf8_string (pp , ">" , 0 , 1 ) ); 
      closed = 1 ; 
    }
  }
  else if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ) {
#   define XfOrM246_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM246(x) SETUP_XfOrM194(x)
    if (compact ) {
#     define XfOrM251_COUNT (0+XfOrM246_COUNT)
#     define SETUP_XfOrM251(x) SETUP_XfOrM246(x)
      if (FUNCCALL(SETUP_XfOrM251(_), scheme_syntax_is_graph (obj ) ))
        FUNCCALL(SETUP_XfOrM251(_), print_this_string (pp , & compacts [CPT_GSTX ] , 0 , 1 ) ); 
      else FUNCCALL(SETUP_XfOrM251(_), print_this_string (pp , & compacts [CPT_STX ] , 0 , 1 ) ); 
      closed = (__funcarg17 = FUNCCALL(SETUP_XfOrM251(_), scheme_syntax_to_datum (obj , 2 , mt ) ), FUNCCALL_AGAIN(print (__funcarg17 , notdisplay , 1 , ht , mt , pp ) )) ; 
    }
    else if (pp -> print_unreadable ) {
      Scheme_Stx * stx = (Scheme_Stx * ) obj ; 
      BLOCK_SETUP((PUSH(stx, 0+XfOrM246_COUNT)));
#     define XfOrM248_COUNT (1+XfOrM246_COUNT)
#     define SETUP_XfOrM248(x) SETUP(XfOrM248_COUNT)
      if ((stx -> srcloc -> line >= 0 ) || (stx -> srcloc -> pos >= 0 ) ) {
#       define XfOrM249_COUNT (0+XfOrM248_COUNT)
#       define SETUP_XfOrM249(x) SETUP_XfOrM248(x)
        FUNCCALL(SETUP_XfOrM249(_), print_utf8_string (pp , "#<syntax:" , 0 , 9 ) ); 
        if (stx -> srcloc -> src && ((Scheme_Type ) (((((long ) (stx -> srcloc -> src ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (stx -> srcloc -> src ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) {
#         define XfOrM250_COUNT (0+XfOrM249_COUNT)
#         define SETUP_XfOrM250(x) SETUP_XfOrM249(x)
          FUNCCALL(SETUP_XfOrM250(_), print_utf8_string (pp , (((Scheme_Simple_Object * ) (stx -> srcloc -> src ) ) -> u . byte_str_val . string_val ) , 0 , (((Scheme_Simple_Object * ) (stx -> srcloc -> src ) ) -> u . byte_str_val . tag_val ) ) ); 
          FUNCCALL(SETUP_XfOrM250(_), print_utf8_string (pp , ":" , 0 , 1 ) ); 
        }
        if (stx -> srcloc -> line >= 0 )
          (sprintf (quick_buffer , "%ld:%ld" , stx -> srcloc -> line , stx -> srcloc -> col - 1 ) ) ; 
        else (sprintf (quick_buffer , ":%ld" , stx -> srcloc -> pos ) ) ; 
        FUNCCALL(SETUP_XfOrM249(_), print_utf8_string (pp , quick_buffer , 0 , - 1 ) ); 
        FUNCCALL_AGAIN(print_utf8_string (pp , ">" , 0 , 1 ) ); 
      }
      else FUNCCALL(SETUP_XfOrM248(_), print_utf8_string (pp , "#<syntax>" , 0 , 9 ) ); 
    }
    else {
#     define XfOrM247_COUNT (0+XfOrM246_COUNT)
#     define SETUP_XfOrM247(x) SETUP_XfOrM246(x)
      FUNCCALL(SETUP_XfOrM247(_), cannot_print (pp , notdisplay , obj , ht , compact ) ); 
    }
  }
  else if (compact && ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_module_index_type ) ) ) {
    Scheme_Object * idx ; 
    BLOCK_SETUP((PUSH(idx, 0+XfOrM194_COUNT)));
#   define XfOrM243_COUNT (1+XfOrM194_COUNT)
#   define SETUP_XfOrM243(x) SETUP(XfOrM243_COUNT)
    idx = NULLED_OUT ; 
    idx = FUNCCALL(SETUP_XfOrM243(_), get_symtab_idx (mt , obj ) ); 
    if (idx ) {
#     define XfOrM245_COUNT (0+XfOrM243_COUNT)
#     define SETUP_XfOrM245(x) SETUP_XfOrM243(x)
      FUNCCALL(SETUP_XfOrM245(_), print_symtab_ref (pp , idx ) ); 
    }
    else {
#     define XfOrM244_COUNT (0+XfOrM243_COUNT)
#     define SETUP_XfOrM244(x) SETUP_XfOrM243(x)
      FUNCCALL(SETUP_XfOrM244(_), print_this_string (pp , & compacts [CPT_MODULE_INDEX ] , 0 , 1 ) ); 
      FUNCCALL(SETUP_XfOrM244(_), print (((Scheme_Modidx * ) obj ) -> path , notdisplay , 1 , ht , mt , pp ) ); 
      FUNCCALL_AGAIN(print (((Scheme_Modidx * ) obj ) -> base , notdisplay , 1 , ht , mt , pp ) ); 
      FUNCCALL_AGAIN(symtab_set (pp , mt , obj ) ); 
    }
  }
  else if (compact && ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_module_variable_type ) ) && ! ((Module_Variable * ) obj ) -> mod_phase ) {
    Scheme_Object * idx ; 
    BLOCK_SETUP((PUSH(idx, 0+XfOrM194_COUNT)));
#   define XfOrM240_COUNT (1+XfOrM194_COUNT)
#   define SETUP_XfOrM240(x) SETUP(XfOrM240_COUNT)
    idx = NULLED_OUT ; 
    idx = FUNCCALL(SETUP_XfOrM240(_), get_symtab_idx (mt , obj ) ); 
    if (idx ) {
#     define XfOrM242_COUNT (0+XfOrM240_COUNT)
#     define SETUP_XfOrM242(x) SETUP_XfOrM240(x)
      FUNCCALL(SETUP_XfOrM242(_), print_symtab_ref (pp , idx ) ); 
    }
    else {
      Module_Variable * mv ; 
      BLOCK_SETUP((PUSH(mv, 0+XfOrM240_COUNT)));
#     define XfOrM241_COUNT (1+XfOrM240_COUNT)
#     define SETUP_XfOrM241(x) SETUP(XfOrM241_COUNT)
      mv = NULLED_OUT ; 
      FUNCCALL(SETUP_XfOrM241(_), print_this_string (pp , & compacts [CPT_MODULE_VAR ] , 0 , 1 ) ); 
      mv = (Module_Variable * ) obj ; 
      FUNCCALL(SETUP_XfOrM241(_), print (mv -> modidx , notdisplay , 1 , ht , mt , pp ) ); 
      FUNCCALL_AGAIN(print (mv -> sym , notdisplay , 1 , ht , mt , pp ) ); 
      FUNCCALL_AGAIN(print_compact_number (pp , mv -> pos ) ); 
      FUNCCALL_AGAIN(symtab_set (pp , mt , obj ) ); 
    }
  }
  else if (compact && ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_variable_type ) ) && (((Scheme_Bucket_With_Flags * ) obj ) -> flags & 16 ) ) {
    int pos ; 
#   define XfOrM239_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM239(x) SETUP_XfOrM194(x)
    pos = ((Scheme_Bucket_With_Ref_Id * ) obj ) -> id ; 
    FUNCCALL(SETUP_XfOrM239(_), print_this_string (pp , & compacts [CPT_REFERENCE ] , 0 , 1 ) ); 
    FUNCCALL_AGAIN(print_compact_number (pp , pos ) ); 
  }
  else if (compact && (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_local_type ) ) || ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_local_unbox_type ) ) ) ) {
    int unbox = ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_local_unbox_type ) ) ; 
    Scheme_Local * loc = (Scheme_Local * ) obj ; 
    BLOCK_SETUP((PUSH(loc, 0+XfOrM194_COUNT)));
#   define XfOrM236_COUNT (1+XfOrM194_COUNT)
#   define SETUP_XfOrM236(x) SETUP(XfOrM236_COUNT)
    if (loc -> position < (207 - 192 ) ) {
      unsigned char s [1 ] ; 
#     define XfOrM238_COUNT (0+XfOrM236_COUNT)
#     define SETUP_XfOrM238(x) SETUP_XfOrM236(x)
      s [0 ] = loc -> position + (unbox ? 207 : 192 ) ; 
      FUNCCALL(SETUP_XfOrM238(_), print_this_string (pp , (char * ) s , 0 , 1 ) ); 
    }
    else {
#     define XfOrM237_COUNT (0+XfOrM236_COUNT)
#     define SETUP_XfOrM237(x) SETUP_XfOrM236(x)
      FUNCCALL(SETUP_XfOrM237(_), print_this_string (pp , & compacts [unbox ? CPT_LOCAL_UNBOX : CPT_LOCAL ] , 0 , 1 ) ); 
      FUNCCALL(SETUP_XfOrM237(_), print_compact_number (pp , loc -> position ) ); 
    }
  }
  else if (compact && ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_application_type ) ) ) {
    Scheme_App_Rec * app ; 
    int i ; 
    BLOCK_SETUP((PUSH(app, 0+XfOrM194_COUNT)));
#   define XfOrM231_COUNT (1+XfOrM194_COUNT)
#   define SETUP_XfOrM231(x) SETUP(XfOrM231_COUNT)
    app = NULLED_OUT ; 
    app = (Scheme_App_Rec * ) obj ; 
    if (app -> num_args < (255 - 247 ) ) {
      unsigned char s [1 ] ; 
#     define XfOrM235_COUNT (0+XfOrM231_COUNT)
#     define SETUP_XfOrM235(x) SETUP_XfOrM231(x)
      s [0 ] = 247 + app -> num_args ; 
      FUNCCALL(SETUP_XfOrM235(_), print_this_string (pp , (char * ) s , 0 , 1 ) ); 
    }
    else {
#     define XfOrM234_COUNT (0+XfOrM231_COUNT)
#     define SETUP_XfOrM234(x) SETUP_XfOrM231(x)
      FUNCCALL(SETUP_XfOrM234(_), print_this_string (pp , & compacts [CPT_APPLICATION ] , 0 , 1 ) ); 
      FUNCCALL(SETUP_XfOrM234(_), print_compact_number (pp , app -> num_args ) ); 
    }
    for (i = 0 ; i < app -> num_args + 1 ; i ++ ) {
#     define XfOrM233_COUNT (0+XfOrM231_COUNT)
#     define SETUP_XfOrM233(x) SETUP_XfOrM231(x)
      closed = (__funcarg16 = FUNCCALL(SETUP_XfOrM233(_), scheme_protect_quote (app -> args [i ] ) ), FUNCCALL_AGAIN(print (__funcarg16 , notdisplay , 1 , ((void * ) 0 ) , mt , pp ) )) ; 
    }
  }
  else if (compact && ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_application2_type ) ) ) {
    Scheme_App2_Rec * app ; 
    unsigned char s [1 ] ; 
    BLOCK_SETUP((PUSH(app, 0+XfOrM194_COUNT)));
#   define XfOrM230_COUNT (1+XfOrM194_COUNT)
#   define SETUP_XfOrM230(x) SETUP(XfOrM230_COUNT)
    app = NULLED_OUT ; 
    app = (Scheme_App2_Rec * ) obj ; 
    s [0 ] = 247 + 1 ; 
    FUNCCALL(SETUP_XfOrM230(_), print_this_string (pp , (char * ) s , 0 , 1 ) ); 
    (__funcarg14 = FUNCCALL(SETUP_XfOrM230(_), scheme_protect_quote (app -> rator ) ), FUNCCALL_AGAIN(print (__funcarg14 , notdisplay , 1 , ((void * ) 0 ) , mt , pp ) )) ; 
    closed = (__funcarg13 = FUNCCALL(SETUP_XfOrM230(_), scheme_protect_quote (app -> rand ) ), FUNCCALL_AGAIN(print (__funcarg13 , notdisplay , 1 , ((void * ) 0 ) , mt , pp ) )) ; 
  }
  else if (compact && ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_application3_type ) ) ) {
    Scheme_App3_Rec * app ; 
    unsigned char s [1 ] ; 
    BLOCK_SETUP((PUSH(app, 0+XfOrM194_COUNT)));
#   define XfOrM229_COUNT (1+XfOrM194_COUNT)
#   define SETUP_XfOrM229(x) SETUP(XfOrM229_COUNT)
    app = NULLED_OUT ; 
    app = (Scheme_App3_Rec * ) obj ; 
    s [0 ] = 247 + 2 ; 
    FUNCCALL(SETUP_XfOrM229(_), print_this_string (pp , (char * ) s , 0 , 1 ) ); 
    (__funcarg12 = FUNCCALL(SETUP_XfOrM229(_), scheme_protect_quote (app -> rator ) ), FUNCCALL_AGAIN(print (__funcarg12 , notdisplay , 1 , ((void * ) 0 ) , mt , pp ) )) ; 
    (__funcarg11 = FUNCCALL(SETUP_XfOrM229(_), scheme_protect_quote (app -> rand1 ) ), FUNCCALL_AGAIN(print (__funcarg11 , notdisplay , 1 , ((void * ) 0 ) , mt , pp ) )) ; 
    closed = (__funcarg10 = FUNCCALL(SETUP_XfOrM229(_), scheme_protect_quote (app -> rand2 ) ), FUNCCALL_AGAIN(print (__funcarg10 , notdisplay , 1 , ((void * ) 0 ) , mt , pp ) )) ; 
  }
  else if (compact && ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_let_one_type ) ) ) {
    Scheme_Let_One * lo ; 
    BLOCK_SETUP((PUSH(lo, 0+XfOrM194_COUNT)));
#   define XfOrM228_COUNT (1+XfOrM194_COUNT)
#   define SETUP_XfOrM228(x) SETUP(XfOrM228_COUNT)
    lo = NULLED_OUT ; 
    lo = (Scheme_Let_One * ) obj ; 
    FUNCCALL(SETUP_XfOrM228(_), print_this_string (pp , & compacts [CPT_LET_ONE ] , 0 , 1 ) ); 
    (__funcarg9 = FUNCCALL(SETUP_XfOrM228(_), scheme_protect_quote (lo -> value ) ), FUNCCALL_AGAIN(print (__funcarg9 , notdisplay , 1 , ((void * ) 0 ) , mt , pp ) )) ; 
    closed = (__funcarg8 = FUNCCALL(SETUP_XfOrM228(_), scheme_protect_quote (lo -> body ) ), FUNCCALL_AGAIN(print (__funcarg8 , notdisplay , 1 , ((void * ) 0 ) , mt , pp ) )) ; 
  }
  else if (compact && ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_branch_type ) ) ) {
    Scheme_Branch_Rec * b ; 
    BLOCK_SETUP((PUSH(b, 0+XfOrM194_COUNT)));
#   define XfOrM227_COUNT (1+XfOrM194_COUNT)
#   define SETUP_XfOrM227(x) SETUP(XfOrM227_COUNT)
    b = NULLED_OUT ; 
    b = (Scheme_Branch_Rec * ) obj ; 
    FUNCCALL(SETUP_XfOrM227(_), print_this_string (pp , & compacts [CPT_BRANCH ] , 0 , 1 ) ); 
    (__funcarg7 = FUNCCALL(SETUP_XfOrM227(_), scheme_protect_quote (b -> test ) ), FUNCCALL_AGAIN(print (__funcarg7 , notdisplay , 1 , ((void * ) 0 ) , mt , pp ) )) ; 
    (__funcarg6 = FUNCCALL(SETUP_XfOrM227(_), scheme_protect_quote (b -> tbranch ) ), FUNCCALL_AGAIN(print (__funcarg6 , notdisplay , 1 , ((void * ) 0 ) , mt , pp ) )) ; 
    closed = (__funcarg5 = FUNCCALL(SETUP_XfOrM227(_), scheme_protect_quote (b -> fbranch ) ), FUNCCALL_AGAIN(print (__funcarg5 , notdisplay , 1 , ((void * ) 0 ) , mt , pp ) )) ; 
  }
  else if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_quote_compilation_type ) ) ) {
    Scheme_Hash_Table * q_ht ; 
    Scheme_Object * v ; 
    int counter = 1 , qpht , qpb ; 
    BLOCK_SETUP((PUSH(q_ht, 0+XfOrM194_COUNT), PUSH(v, 1+XfOrM194_COUNT)));
#   define XfOrM225_COUNT (2+XfOrM194_COUNT)
#   define SETUP_XfOrM225(x) SETUP(XfOrM225_COUNT)
    q_ht = NULLED_OUT ; 
    v = NULLED_OUT ; 
    v = (((Scheme_Small_Object * ) (obj ) ) -> u . ptr_val ) ; 
    qpht = pp -> print_hash_table ; 
    qpb = pp -> print_box ; 
    pp -> print_hash_table = 1 ; 
    pp -> print_box = 1 ; 
    q_ht = FUNCCALL(SETUP_XfOrM225(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
    FUNCCALL_AGAIN(setup_graph_table (v , q_ht , & counter , pp ) ); 
    if (compact )
      FUNCCALL(SETUP_XfOrM225(_), print_this_string (pp , & compacts [CPT_QUOTE ] , 0 , 1 ) ); 
    else {
#     define XfOrM226_COUNT (0+XfOrM225_COUNT)
#     define SETUP_XfOrM226(x) SETUP_XfOrM225(x)
      FUNCCALL_EMPTY(scheme_signal_error ("internal error: non-compact quote compilation" ) ); 
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    compact = FUNCCALL(SETUP_XfOrM225(_), print (v , notdisplay , 1 , q_ht , mt , pp ) ); 
    pp -> print_hash_table = qpht ; 
    pp -> print_box = qpb ; 
  }
  else if (compact && ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_svector_type ) ) ) {
    mzshort l , * v ; 
    BLOCK_SETUP((PUSH(v, 0+XfOrM194_COUNT)));
#   define XfOrM220_COUNT (1+XfOrM194_COUNT)
#   define SETUP_XfOrM220(x) SETUP(XfOrM220_COUNT)
    v = NULLED_OUT ; 
    l = (((Scheme_Simple_Object * ) (obj ) ) -> u . svector_val . len ) ; 
    v = (mzshort * ) (((Scheme_Simple_Object * ) (obj ) ) -> u . svector_val . vec ) ; 
    if (l < (247 - 222 ) ) {
      unsigned char s [1 ] ; 
#     define XfOrM224_COUNT (0+XfOrM220_COUNT)
#     define SETUP_XfOrM224(x) SETUP_XfOrM220(x)
      s [0 ] = l + 222 ; 
      FUNCCALL(SETUP_XfOrM224(_), print_this_string (pp , (char * ) s , 0 , 1 ) ); 
    }
    else {
#     define XfOrM223_COUNT (0+XfOrM220_COUNT)
#     define SETUP_XfOrM223(x) SETUP_XfOrM220(x)
      FUNCCALL(SETUP_XfOrM223(_), print_this_string (pp , & compacts [CPT_SVECTOR ] , 0 , 1 ) ); 
      FUNCCALL(SETUP_XfOrM223(_), print_compact_number (pp , l ) ); 
    }
    while (l -- ) {
      int n = v [l ] ; 
#     define XfOrM222_COUNT (0+XfOrM220_COUNT)
#     define SETUP_XfOrM222(x) SETUP_XfOrM220(x)
      FUNCCALL(SETUP_XfOrM222(_), print_compact_number (pp , n ) ); 
    }
  }
  else if (compact && ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_delay_syntax_type ) ) ) {
    Scheme_Object * idx ; 
    BLOCK_SETUP((PUSH(idx, 0+XfOrM194_COUNT)));
#   define XfOrM215_COUNT (1+XfOrM194_COUNT)
#   define SETUP_XfOrM215(x) SETUP(XfOrM215_COUNT)
    idx = NULLED_OUT ; 
    if (! mt -> pass ) {
#     define XfOrM218_COUNT (0+XfOrM215_COUNT)
#     define SETUP_XfOrM218(x) SETUP_XfOrM215(x)
      if (! mt -> delay_map ) {
        Scheme_Hash_Table * delay_map ; 
        BLOCK_SETUP((PUSH(delay_map, 0+XfOrM218_COUNT)));
#       define XfOrM219_COUNT (1+XfOrM218_COUNT)
#       define SETUP_XfOrM219(x) SETUP(XfOrM219_COUNT)
        delay_map = NULLED_OUT ; 
        delay_map = FUNCCALL(SETUP_XfOrM219(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
        mt -> delay_map = delay_map ; 
      }
      FUNCCALL(SETUP_XfOrM218(_), scheme_hash_set (mt -> delay_map , (((Scheme_Small_Object * ) (obj ) ) -> u . ptr_val ) , obj ) ); 
    }
    else obj = FUNCCALL(SETUP_XfOrM215(_), scheme_hash_get (mt -> delay_map , (((Scheme_Small_Object * ) (obj ) ) -> u . ptr_val ) ) ); 
    idx = FUNCCALL(SETUP_XfOrM215(_), get_symtab_idx (mt , obj ) ); 
    if (idx ) {
#     define XfOrM217_COUNT (0+XfOrM215_COUNT)
#     define SETUP_XfOrM217(x) SETUP_XfOrM215(x)
      FUNCCALL(SETUP_XfOrM217(_), print_general_symtab_ref (pp , idx , CPT_DELAY_REF ) ); 
    }
    else {
#     define XfOrM216_COUNT (0+XfOrM215_COUNT)
#     define SETUP_XfOrM216(x) SETUP_XfOrM215(x)
      FUNCCALL(SETUP_XfOrM216(_), print ((((Scheme_Small_Object * ) (obj ) ) -> u . ptr_val ) , notdisplay , 1 , ht , mt , pp ) ); 
      FUNCCALL(SETUP_XfOrM216(_), symtab_set (pp , mt , obj ) ); 
      FUNCCALL_AGAIN(set_symtab_shared (mt , obj ) ); 
    }
  }
  else if (scheme_type_writers [((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ] && (compact || ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_compilation_top_type ) ) ) ) {
    Scheme_Type t = ((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ; 
    Scheme_Object * v ; 
    long slen ; 
    BLOCK_SETUP((PUSH(v, 0+XfOrM194_COUNT)));
#   define XfOrM200_COUNT (1+XfOrM194_COUNT)
#   define SETUP_XfOrM200(x) SETUP(XfOrM200_COUNT)
    v = NULLED_OUT ; 
    if (t >= _scheme_last_type_ ) {
#     define XfOrM214_COUNT (0+XfOrM200_COUNT)
#     define SETUP_XfOrM214(x) SETUP_XfOrM200(x)
      FUNCCALL_EMPTY(scheme_signal_error ("internal error: bad type with writer" ) ); 
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    if (! global_constants_ht ) {
#     define XfOrM213_COUNT (0+XfOrM200_COUNT)
#     define SETUP_XfOrM213(x) SETUP_XfOrM200(x)
      FUNCCALL(SETUP_XfOrM213(_), scheme_register_static ((void * ) & global_constants_ht , sizeof (global_constants_ht ) ) ); 
      global_constants_ht = FUNCCALL(SETUP_XfOrM213(_), scheme_map_constants_to_globals () ); 
    }
    if (compact ) {
#     define XfOrM210_COUNT (0+XfOrM200_COUNT)
#     define SETUP_XfOrM210(x) SETUP_XfOrM200(x)
      if (t < (92 - 80 ) ) {
        unsigned char s [1 ] ; 
#       define XfOrM212_COUNT (0+XfOrM210_COUNT)
#       define SETUP_XfOrM212(x) SETUP_XfOrM210(x)
        s [0 ] = t + 80 ; 
        FUNCCALL(SETUP_XfOrM212(_), print_this_string (pp , (char * ) s , 0 , 1 ) ); 
      }
      else {
#       define XfOrM211_COUNT (0+XfOrM210_COUNT)
#       define SETUP_XfOrM211(x) SETUP_XfOrM210(x)
        FUNCCALL(SETUP_XfOrM211(_), print_this_string (pp , & compacts [CPT_MARSHALLED ] , 0 , 1 ) ); 
        FUNCCALL(SETUP_XfOrM211(_), print_compact_number (pp , t ) ); 
      }
    }
    else {
#     define XfOrM209_COUNT (0+XfOrM200_COUNT)
#     define SETUP_XfOrM209(x) SETUP_XfOrM200(x)
      FUNCCALL(SETUP_XfOrM209(_), print_this_string (pp , "#~" , 0 , 2 ) ); 
    }
    {
      Scheme_Type_Writer writer ; 
#     define XfOrM208_COUNT (0+XfOrM200_COUNT)
#     define SETUP_XfOrM208(x) SETUP_XfOrM200(x)
      writer = scheme_type_writers [t ] ; 
      v = FUNCCALL(SETUP_XfOrM208(_), writer (obj ) ); 
    }
    if (compact )
      closed = FUNCCALL(SETUP_XfOrM200(_), print (v , notdisplay , 1 , ((void * ) 0 ) , mt , pp ) ); 
    else {
      Scheme_Hash_Table * st_refs , * symtab , * rns ; 
      long * shared_offsets ; 
      long st_len , j , shared_offset , start_offset ; 
      BLOCK_SETUP((PUSH(rns, 0+XfOrM200_COUNT), PUSH(shared_offsets, 1+XfOrM200_COUNT), PUSH(symtab, 2+XfOrM200_COUNT), PUSH(st_refs, 3+XfOrM200_COUNT)));
#     define XfOrM201_COUNT (4+XfOrM200_COUNT)
#     define SETUP_XfOrM201(x) SETUP(XfOrM201_COUNT)
      st_refs = NULLED_OUT ; 
      symtab = NULLED_OUT ; 
      rns = NULLED_OUT ; 
      shared_offsets = NULLED_OUT ; 
      mt = ((Scheme_Marshal_Tables * ) FUNCCALL(SETUP_XfOrM201(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Marshal_Tables ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
      mt -> type = scheme_rt_marshal_info ; 
      st_refs = FUNCCALL(SETUP_XfOrM201(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
      mt -> st_refs = st_refs ; 
      mt -> st_ref_stack = scheme_null ; 
      symtab = FUNCCALL(SETUP_XfOrM201(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
      mt -> symtab = symtab ; 
      rns = FUNCCALL(SETUP_XfOrM201(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
      mt -> rns = rns ; 
      mt -> reverse_map = ((void * ) 0 ) ; 
      mt -> pass = 0 ; 
      FUNCCALL(SETUP_XfOrM201(_), scheme_hash_set (symtab , scheme_void , scheme_true ) ); 
      FUNCCALL_AGAIN(print_substring (v , notdisplay , 1 , ((void * ) 0 ) , mt , pp , ((void * ) 0 ) , & slen , 0 , ((void * ) 0 ) ) ); 
      FUNCCALL_AGAIN(sort_referenced_keys (mt ) ); 
      mt -> rn_saved = ((void * ) 0 ) ; 
      shared_offsets = ((long * ) FUNCCALL(SETUP_XfOrM201(_), GC_malloc_atomic (sizeof (long ) * (mt -> st_refs -> count ) ) )) ; 
      mt -> shared_offsets = shared_offsets ; 
      symtab = FUNCCALL(SETUP_XfOrM201(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
      mt -> symtab = symtab ; 
      rns = FUNCCALL(SETUP_XfOrM201(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
      mt -> rns = rns ; 
      mt -> reverse_map = ((void * ) 0 ) ; 
      mt -> top_map = ((void * ) 0 ) ; 
      mt -> pass = 1 ; 
      FUNCCALL(SETUP_XfOrM201(_), print_substring (v , notdisplay , 1 , ((void * ) 0 ) , mt , pp , ((void * ) 0 ) , & slen , 1 , & st_len ) ); 
      symtab = FUNCCALL_AGAIN(scheme_make_hash_table (SCHEME_hash_ptr ) ); 
      mt -> symtab = symtab ; 
      rns = FUNCCALL(SETUP_XfOrM201(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
      mt -> rns = rns ; 
      mt -> reverse_map = ((void * ) 0 ) ; 
      mt -> top_map = ((void * ) 0 ) ; 
      mt -> pass = 2 ; 
      FUNCCALL(SETUP_XfOrM201(_), print_substring (v , notdisplay , 1 , ((void * ) 0 ) , mt , pp , ((void * ) 0 ) , & slen , - 1 , & st_len ) ); 
      FUNCCALL_AGAIN(print_one_byte (pp , strlen ("372" "" ) ) ); 
      FUNCCALL_AGAIN(print_this_string (pp , "372" "" , 0 , - 1 ) ); 
      if (mt -> st_refs -> count != mt -> sorted_keys_count )
        FUNCCALL_EMPTY(scheme_signal_error ("shared key count somehow changed" ) ); 
      FUNCCALL(SETUP_XfOrM201(_), print_number (pp , mt -> st_refs -> count + 1 ) ); 
      if (mt -> st_refs -> count ) {
        int all_short = shared_offsets [mt -> st_refs -> count - 1 ] < 0xFFFF ; 
#       define XfOrM205_COUNT (0+XfOrM201_COUNT)
#       define SETUP_XfOrM205(x) SETUP_XfOrM201(x)
        FUNCCALL(SETUP_XfOrM205(_), print_one_byte (pp , all_short ) ); 
        for (j = 0 ; j < mt -> st_refs -> count ; j ++ ) {
#         define XfOrM207_COUNT (0+XfOrM205_COUNT)
#         define SETUP_XfOrM207(x) SETUP_XfOrM205(x)
          if (all_short )
            FUNCCALL(SETUP_XfOrM207(_), print_short_number (pp , shared_offsets [j ] ) ); 
          else FUNCCALL(SETUP_XfOrM207(_), print_number (pp , shared_offsets [j ] ) ); 
        }
      }
      else {
#       define XfOrM204_COUNT (0+XfOrM201_COUNT)
#       define SETUP_XfOrM204(x) SETUP_XfOrM201(x)
        FUNCCALL(SETUP_XfOrM204(_), print_one_byte (pp , 1 ) ); 
      }
      FUNCCALL(SETUP_XfOrM201(_), print_number (pp , st_len ) ); 
      FUNCCALL(SETUP_XfOrM201(_), print_number (pp , slen ) ); 
      symtab = FUNCCALL_AGAIN(scheme_make_hash_table (SCHEME_hash_ptr ) ); 
      mt -> symtab = symtab ; 
      rns = FUNCCALL(SETUP_XfOrM201(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
      mt -> rns = rns ; 
      mt -> reverse_map = ((void * ) 0 ) ; 
      mt -> top_map = ((void * ) 0 ) ; 
      mt -> pass = 3 ; 
      start_offset = pp -> print_offset ; 
      FUNCCALL(SETUP_XfOrM201(_), print_table_keys (notdisplay , 1 , ((void * ) 0 ) , mt , pp ) ); 
      shared_offset = pp -> print_offset ; 
      closed = FUNCCALL(SETUP_XfOrM201(_), print (v , notdisplay , 1 , ((void * ) 0 ) , mt , pp ) ); 
      if (shared_offset - start_offset != st_len ) {
#       define XfOrM203_COUNT (0+XfOrM201_COUNT)
#       define SETUP_XfOrM203(x) SETUP_XfOrM201(x)
        FUNCCALL_EMPTY(scheme_signal_error ("compiled code shared printed size changed on third pass:" " %ld versus %ld (total %ld)" , st_len , shared_offset - start_offset , slen ) ); 
      }
      if (pp -> print_offset - start_offset != slen ) {
#       define XfOrM202_COUNT (0+XfOrM201_COUNT)
#       define SETUP_XfOrM202(x) SETUP_XfOrM201(x)
        FUNCCALL_EMPTY(scheme_signal_error ("compiled code printed size changed on third pass:" " %ld versus %ld" , slen , pp -> print_offset - start_offset ) ); 
      }
      mt = ((void * ) 0 ) ; 
    }
  }
  else {
#   define XfOrM195_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM195(x) SETUP_XfOrM194(x)
    if (compact || ! pp -> print_unreadable )
      FUNCCALL(SETUP_XfOrM195(_), cannot_print (pp , notdisplay , obj , ht , compact ) ); 
    else if ((((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) < printers_count ) && printers [((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ] ) {
      Scheme_Type_Printer printer ; 
#     define XfOrM199_COUNT (0+XfOrM195_COUNT)
#     define SETUP_XfOrM199(x) SETUP_XfOrM195(x)
      printer = printers [((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ] ; 
      FUNCCALL(SETUP_XfOrM199(_), printer (obj , ! notdisplay , pp ) ); 
    }
    else {
      char * s ; 
      long len = - 1 ; 
      BLOCK_SETUP((PUSH(s, 0+XfOrM195_COUNT)));
#     define XfOrM196_COUNT (1+XfOrM195_COUNT)
#     define SETUP_XfOrM196(x) SETUP(XfOrM196_COUNT)
      s = NULLED_OUT ; 
      s = FUNCCALL(SETUP_XfOrM196(_), scheme_get_type_name ((((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) ) ); 
      FUNCCALL_AGAIN(print_utf8_string (pp , "#" , 0 , 1 ) ); 
      if (! s ) {
        char s [8 ] ; 
#       define XfOrM198_COUNT (0+XfOrM196_COUNT)
#       define SETUP_XfOrM198(x) SETUP_XfOrM196(x)
        FUNCCALL(SETUP_XfOrM198(_), print_utf8_string (pp , "<???:" , 0 , 5 ) ); 
        (sprintf (s , "%d" , ((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) ) ; 
        FUNCCALL(SETUP_XfOrM198(_), print_utf8_string (pp , s , 0 , - 1 ) ); 
        FUNCCALL_AGAIN(print_utf8_string (pp , ">" , 0 , 1 ) ); 
      }
      else {
#       define XfOrM197_COUNT (0+XfOrM196_COUNT)
#       define SETUP_XfOrM197(x) SETUP_XfOrM196(x)
        FUNCCALL(SETUP_XfOrM197(_), print_utf8_string (pp , s , 0 , len ) ); 
      }
    }
    closed = 1 ; 
  }
  if (save_honu_mode != pp -> honu_mode )
    pp -> honu_mode = save_honu_mode ; 
  RET_VALUE_START ((closed || compact ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void print_char_string (const char * str , int len , const mzchar * ustr , int delta , int ulen , int notdisplay , int honu_char , PrintParams * pp ) {
  char minibuf [12 ] , * esc ; 
  int a , i , v , ui , cont_utf8 = 0 , isize ; 
  PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(ustr, 0), PUSH(pp, 1), PUSH(str, 2), PUSH(esc, 3)));
# define XfOrM398_COUNT (4)
# define SETUP_XfOrM398(x) SETUP(XfOrM398_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  esc = NULLED_OUT ; 
  if (notdisplay ) {
#   define XfOrM400_COUNT (0+XfOrM398_COUNT)
#   define SETUP_XfOrM400(x) SETUP_XfOrM398(x)
    FUNCCALL(SETUP_XfOrM400(_), print_utf8_string (pp , honu_char ? "'" : "\"" , 0 , 1 ) ); 
    for (a = i = ui = 0 ; i < len ; i += isize , ui ++ ) {
#     define XfOrM413_COUNT (0+XfOrM400_COUNT)
#     define SETUP_XfOrM413(x) SETUP_XfOrM400(x)
      v = ((unsigned char * ) str ) [i ] ; 
      isize = 1 ; 
      switch (v ) {
#       define XfOrM417_COUNT (0+XfOrM413_COUNT)
#       define SETUP_XfOrM417(x) SETUP_XfOrM413(x)
        case '\"' : if (honu_char )
          esc = ((void * ) 0 ) ; 
        else esc = "\\\"" ; 
        break ; 
        case '\'' : if (honu_char )
          esc = "\\'" ; 
        else esc = ((void * ) 0 ) ; 
        break ; 
        case '\\' : esc = "\\\\" ; 
        break ; 
        case '\a' : esc = "\\a" ; 
        break ; 
        case '\b' : esc = "\\b" ; 
        break ; 
        case 27 : esc = "\\e" ; 
        break ; 
        case '\f' : esc = "\\f" ; 
        break ; 
        case '\n' : esc = "\\n" ; 
        break ; 
        case '\r' : esc = "\\r" ; 
        break ; 
        case '\t' : esc = "\\t" ; 
        break ; 
        case '\v' : esc = "\\v" ; 
        break ; 
        default : if (v > 127 ) {
#         define XfOrM420_COUNT (0+XfOrM417_COUNT)
#         define SETUP_XfOrM420(x) SETUP_XfOrM417(x)
          if (cont_utf8 ) {
            cont_utf8 -- ; 
            ui -- ; 
            esc = ((void * ) 0 ) ; 
          }
          else {
            int clen ; 
#           define XfOrM421_COUNT (0+XfOrM420_COUNT)
#           define SETUP_XfOrM421(x) SETUP_XfOrM420(x)
            clen = FUNCCALL(SETUP_XfOrM421(_), scheme_utf8_encode (ustr , ui + delta , ui + delta + 1 , ((void * ) 0 ) , 0 , 0 ) ); 
            if ((((scheme_uchar_table [(ustr [ui + delta ] >> 8 ) & 0x1FFF ] [ustr [ui + delta ] & 0xFF ] ) ) & 0x800 ) || (((scheme_uchar_table [(ustr [ui + delta ] >> 8 ) & 0x1FFF ] [ustr [ui + delta ] & 0xFF ] ) ) & 0x1 ) ) {
              cont_utf8 = clen - 1 ; 
              esc = ((void * ) 0 ) ; 
            }
            else {
              esc = minibuf ; 
              isize = clen ; 
            }
          }
        }
        else if ((((scheme_uchar_table [(v >> 8 ) & 0x1FFF ] [v & 0xFF ] ) ) & 0x800 ) || (((scheme_uchar_table [(v >> 8 ) & 0x1FFF ] [v & 0xFF ] ) ) & 0x1 ) ) {
          esc = ((void * ) 0 ) ; 
        }
        else {
          esc = minibuf ; 
        }
        break ; 
      }
      if (esc ) {
#       define XfOrM414_COUNT (0+XfOrM413_COUNT)
#       define SETUP_XfOrM414(x) SETUP_XfOrM413(x)
        if (esc == minibuf ) {
#         define XfOrM415_COUNT (0+XfOrM414_COUNT)
#         define SETUP_XfOrM415(x) SETUP_XfOrM414(x)
          if (ustr [ui + delta ] > 0xFFFF ) {
#           define XfOrM416_COUNT (0+XfOrM415_COUNT)
#           define SETUP_XfOrM416(x) SETUP_XfOrM415(x)
            (sprintf (minibuf , "\\U%.8X" , ustr [ui + delta ] ) ) ; 
          }
          else (sprintf (minibuf , "\\u%.4X" , ustr [ui + delta ] ) ) ; 
        }
        if (a < i )
          FUNCCALL(SETUP_XfOrM414(_), print_utf8_string (pp , str , a , i - a ) ); 
        FUNCCALL(SETUP_XfOrM414(_), print_utf8_string (pp , esc , 0 , - 1 ) ); 
        a = i + isize ; 
      }
    }
    if (a < i )
      FUNCCALL(SETUP_XfOrM400(_), print_utf8_string (pp , str , a , i - a ) ); 
    FUNCCALL(SETUP_XfOrM400(_), print_utf8_string (pp , honu_char ? "'" : "\"" , 0 , 1 ) ); 
  }
  else if (len ) {
#   define XfOrM399_COUNT (0+XfOrM398_COUNT)
#   define SETUP_XfOrM399(x) SETUP_XfOrM398(x)
    FUNCCALL_EMPTY(print_utf8_string (pp , str , 0 , len ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void print_byte_string (const char * str , int delta , int len , int notdisplay , PrintParams * pp ) {
  char minibuf [8 ] , * esc ; 
  int a , i , v ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(pp, 0), PUSH(str, 1), PUSH(esc, 2)));
# define XfOrM425_COUNT (3)
# define SETUP_XfOrM425(x) SETUP(XfOrM425_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  esc = NULLED_OUT ; 
  if (notdisplay ) {
#   define XfOrM427_COUNT (0+XfOrM425_COUNT)
#   define SETUP_XfOrM427(x) SETUP_XfOrM425(x)
    FUNCCALL(SETUP_XfOrM427(_), print_utf8_string (pp , "\"" , 0 , 1 ) ); 
    for (a = i = delta ; i < delta + len ; i ++ ) {
#     define XfOrM435_COUNT (0+XfOrM427_COUNT)
#     define SETUP_XfOrM435(x) SETUP_XfOrM427(x)
      switch (((unsigned char * ) str ) [i ] ) {
        case '\"' : esc = "\\\"" ; 
        break ; 
        case '\\' : esc = "\\\\" ; 
        break ; 
        case '\a' : esc = "\\a" ; 
        break ; 
        case '\b' : esc = "\\b" ; 
        break ; 
        case 27 : esc = "\\e" ; 
        break ; 
        case '\f' : esc = "\\f" ; 
        break ; 
        case '\n' : esc = "\\n" ; 
        break ; 
        case '\r' : esc = "\\r" ; 
        break ; 
        case '\t' : esc = "\\t" ; 
        break ; 
        case '\v' : esc = "\\v" ; 
        break ; 
        default : v = ((unsigned char * ) str ) [i ] ; 
        if (v > 127 ) {
          esc = minibuf ; 
        }
        else if ((((scheme_uchar_table [(v >> 8 ) & 0x1FFF ] [v & 0xFF ] ) ) & 0x800 ) || (((scheme_uchar_table [(v >> 8 ) & 0x1FFF ] [v & 0xFF ] ) ) & 0x1 ) ) {
          esc = ((void * ) 0 ) ; 
        }
        else {
          esc = minibuf ; 
        }
        break ; 
      }
      if (esc ) {
#       define XfOrM436_COUNT (0+XfOrM435_COUNT)
#       define SETUP_XfOrM436(x) SETUP_XfOrM435(x)
        if (esc == minibuf ) {
#         define XfOrM437_COUNT (0+XfOrM436_COUNT)
#         define SETUP_XfOrM437(x) SETUP_XfOrM436(x)
          (sprintf (minibuf , ((i + 1 >= len ) || (str [i + 1 ] < '0' ) || (str [i + 1 ] > '7' ) ) ? "\\%o" : "\\%03o" , ((unsigned char * ) str ) [i ] ) ) ; 
        }
        if (a < i )
          FUNCCALL(SETUP_XfOrM436(_), print_utf8_string (pp , str , a , i - a ) ); 
        FUNCCALL(SETUP_XfOrM436(_), print_utf8_string (pp , esc , 0 , - 1 ) ); 
        a = i + 1 ; 
      }
    }
    if (a < i )
      FUNCCALL(SETUP_XfOrM427(_), print_utf8_string (pp , str , a , i - a ) ); 
    FUNCCALL(SETUP_XfOrM427(_), print_utf8_string (pp , "\"" , 0 , 1 ) ); 
  }
  else if (len ) {
#   define XfOrM426_COUNT (0+XfOrM425_COUNT)
#   define SETUP_XfOrM426(x) SETUP_XfOrM425(x)
    FUNCCALL_EMPTY(print_this_string (pp , str , delta , len ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void print_pair (Scheme_Object * pair , int notdisplay , int compact , Scheme_Hash_Table * ht , Scheme_Marshal_Tables * mt , PrintParams * pp ) {
  Scheme_Object * cdr ; 
  int super_compact = 0 ; 
  PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(cdr, 0), PUSH(mt, 1), PUSH(pair, 2), PUSH(pp, 3), PUSH(ht, 4)));
# define XfOrM442_COUNT (5)
# define SETUP_XfOrM442(x) SETUP(XfOrM442_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  cdr = NULLED_OUT ; 
  if (compact ) {
    int c = 0 ; 
    Scheme_Object * pr ; 
    BLOCK_SETUP((PUSH(pr, 0+XfOrM442_COUNT)));
#   define XfOrM470_COUNT (1+XfOrM442_COUNT)
#   define SETUP_XfOrM470(x) SETUP(XfOrM470_COUNT)
    pr = NULLED_OUT ; 
    pr = pair ; 
    while (((Scheme_Type ) (((((long ) (pr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (pr ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#     define XfOrM476_COUNT (0+XfOrM470_COUNT)
#     define SETUP_XfOrM476(x) SETUP_XfOrM470(x)
      if (ht )
        if ((long ) FUNCCALL(SETUP_XfOrM476(_), scheme_hash_get (ht , pr ) )!= 1 ) {
        c = - 1 ; 
        break ; 
      }
      c ++ ; 
      pr = (((Scheme_Simple_Object * ) (pr ) ) -> u . pair_val . cdr ) ; 
    }
    if (c > - 1 ) {
#     define XfOrM471_COUNT (0+XfOrM470_COUNT)
#     define SETUP_XfOrM471(x) SETUP_XfOrM470(x)
      super_compact = 1 ; 
      if (c < (((92 + 65 ) + 65 ) - (92 + 65 ) ) ) {
        unsigned char s [1 ] ; 
#       define XfOrM473_COUNT (0+XfOrM471_COUNT)
#       define SETUP_XfOrM473(x) SETUP_XfOrM471(x)
        s [0 ] = c + (((pr ) == (scheme_null ) ) ? 92 : (92 + 65 ) ) ; 
        FUNCCALL(SETUP_XfOrM473(_), print_this_string (pp , (char * ) s , 0 , 1 ) ); 
      }
      else {
#       define XfOrM472_COUNT (0+XfOrM471_COUNT)
#       define SETUP_XfOrM472(x) SETUP_XfOrM471(x)
        FUNCCALL(SETUP_XfOrM472(_), print_this_string (pp , & compacts [CPT_LIST ] , 0 , 1 ) ); 
        FUNCCALL(SETUP_XfOrM472(_), print_compact_number (pp , c ) ); 
        super_compact = - 1 ; 
      }
    }
  }
  else if (pp -> honu_mode ) {
#   define XfOrM451_COUNT (0+XfOrM442_COUNT)
#   define SETUP_XfOrM451(x) SETUP_XfOrM442(x)
    cdr = (((Scheme_Simple_Object * ) (pair ) ) -> u . pair_val . cdr ) ; 
    while (((Scheme_Type ) (((((long ) (cdr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (cdr ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#     define XfOrM467_COUNT (0+XfOrM451_COUNT)
#     define SETUP_XfOrM467(x) SETUP_XfOrM451(x)
      if (ht ) {
#       define XfOrM468_COUNT (0+XfOrM467_COUNT)
#       define SETUP_XfOrM468(x) SETUP_XfOrM467(x)
        if ((long ) FUNCCALL(SETUP_XfOrM468(_), scheme_hash_get (ht , cdr ) )!= 1 ) {
          break ; 
        }
      }
      cdr = (((Scheme_Simple_Object * ) (cdr ) ) -> u . pair_val . cdr ) ; 
    }
    if (((cdr ) == (scheme_null ) ) ) {
#     define XfOrM461_COUNT (0+XfOrM451_COUNT)
#     define SETUP_XfOrM461(x) SETUP_XfOrM451(x)
      FUNCCALL(SETUP_XfOrM461(_), print_utf8_string (pp , "list(" , 0 , 5 ) ); 
      (void ) FUNCCALL(SETUP_XfOrM461(_), print ((((Scheme_Simple_Object * ) (pair ) ) -> u . pair_val . car ) , notdisplay , compact , ht , mt , pp ) ); 
      cdr = (((Scheme_Simple_Object * ) (pair ) ) -> u . pair_val . cdr ) ; 
      while (((Scheme_Type ) (((((long ) (cdr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (cdr ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#       define XfOrM463_COUNT (0+XfOrM461_COUNT)
#       define SETUP_XfOrM463(x) SETUP_XfOrM461(x)
        FUNCCALL(SETUP_XfOrM463(_), print_utf8_string (pp , ", " , 0 , 2 ) ); 
        (void ) FUNCCALL(SETUP_XfOrM463(_), print ((((Scheme_Simple_Object * ) (cdr ) ) -> u . pair_val . car ) , notdisplay , compact , ht , mt , pp ) ); 
        cdr = (((Scheme_Simple_Object * ) (cdr ) ) -> u . pair_val . cdr ) ; 
      }
      FUNCCALL(SETUP_XfOrM461(_), print_utf8_string (pp , ")" , 0 , 1 ) ); 
    }
    else {
      int cnt = 1 ; 
#     define XfOrM452_COUNT (0+XfOrM451_COUNT)
#     define SETUP_XfOrM452(x) SETUP_XfOrM451(x)
      FUNCCALL(SETUP_XfOrM452(_), print_utf8_string (pp , "cons(" , 0 , 5 ) ); 
      (void ) FUNCCALL(SETUP_XfOrM452(_), print ((((Scheme_Simple_Object * ) (pair ) ) -> u . pair_val . car ) , notdisplay , compact , ht , mt , pp ) ); 
      cdr = (((Scheme_Simple_Object * ) (pair ) ) -> u . pair_val . cdr ) ; 
      while (((Scheme_Type ) (((((long ) (cdr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (cdr ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#       define XfOrM458_COUNT (0+XfOrM452_COUNT)
#       define SETUP_XfOrM458(x) SETUP_XfOrM452(x)
        FUNCCALL(SETUP_XfOrM458(_), print_utf8_string (pp , ", " , 0 , 2 ) ); 
        if (ht ) {
#         define XfOrM459_COUNT (0+XfOrM458_COUNT)
#         define SETUP_XfOrM459(x) SETUP_XfOrM458(x)
          if ((long ) FUNCCALL(SETUP_XfOrM459(_), scheme_hash_get (ht , cdr ) )!= 1 ) {
#           define XfOrM460_COUNT (0+XfOrM459_COUNT)
#           define SETUP_XfOrM460(x) SETUP_XfOrM459(x)
            (void ) FUNCCALL(SETUP_XfOrM460(_), print (cdr , notdisplay , compact , ht , mt , pp ) ); 
            break ; 
          }
        }
        FUNCCALL(SETUP_XfOrM458(_), print_utf8_string (pp , "cons(" , 0 , 5 ) ); 
        (void ) FUNCCALL(SETUP_XfOrM458(_), print ((((Scheme_Simple_Object * ) (cdr ) ) -> u . pair_val . car ) , notdisplay , compact , ht , mt , pp ) ); 
        cnt ++ ; 
        cdr = (((Scheme_Simple_Object * ) (cdr ) ) -> u . pair_val . cdr ) ; 
      }
      FUNCCALL(SETUP_XfOrM452(_), print_utf8_string (pp , ", " , 0 , 2 ) ); 
      (void ) FUNCCALL(SETUP_XfOrM452(_), print (cdr , notdisplay , compact , ht , mt , pp ) ); 
      while (cnt -- ) {
#       define XfOrM454_COUNT (0+XfOrM452_COUNT)
#       define SETUP_XfOrM454(x) SETUP_XfOrM452(x)
        FUNCCALL(SETUP_XfOrM454(_), print_utf8_string (pp , ")" , 0 , 1 ) ); 
      }
    }
    RET_NOTHING ; 
  }
  if (compact ) {
#   define XfOrM450_COUNT (0+XfOrM442_COUNT)
#   define SETUP_XfOrM450(x) SETUP_XfOrM442(x)
    if (! super_compact )
      FUNCCALL(SETUP_XfOrM450(_), print_this_string (pp , & compacts [CPT_PAIR ] , 0 , 1 ) ); 
  }
  else FUNCCALL(SETUP_XfOrM442(_), print_utf8_string (pp , "(" , 0 , 1 ) ); 
  FUNCCALL(SETUP_XfOrM442(_), print ((((Scheme_Simple_Object * ) (pair ) ) -> u . pair_val . car ) , notdisplay , compact , ht , mt , pp ) ); 
  cdr = (((Scheme_Simple_Object * ) (pair ) ) -> u . pair_val . cdr ) ; 
  while (((Scheme_Type ) (((((long ) (cdr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (cdr ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#   define XfOrM447_COUNT (0+XfOrM442_COUNT)
#   define SETUP_XfOrM447(x) SETUP_XfOrM442(x)
    if (ht && ! super_compact ) {
#     define XfOrM448_COUNT (0+XfOrM447_COUNT)
#     define SETUP_XfOrM448(x) SETUP_XfOrM447(x)
      if ((long ) FUNCCALL(SETUP_XfOrM448(_), scheme_hash_get (ht , cdr ) )!= 1 ) {
#       define XfOrM449_COUNT (0+XfOrM448_COUNT)
#       define SETUP_XfOrM449(x) SETUP_XfOrM448(x)
        if (! compact )
          FUNCCALL(SETUP_XfOrM449(_), print_utf8_string (pp , " . " , 0 , 3 ) ); 
        (void ) FUNCCALL(SETUP_XfOrM449(_), print (cdr , notdisplay , compact , ht , mt , pp ) ); 
        if (! compact )
          FUNCCALL(SETUP_XfOrM449(_), print_utf8_string (pp , ")" , 0 , 1 ) ); 
        RET_NOTHING ; 
      }
    }
    if (compact && ! super_compact )
      FUNCCALL(SETUP_XfOrM447(_), print_this_string (pp , & compacts [CPT_PAIR ] , 0 , 1 ) ); 
    if (! compact )
      FUNCCALL(SETUP_XfOrM447(_), print_utf8_string (pp , " " , 0 , 1 ) ); 
    FUNCCALL(SETUP_XfOrM447(_), print ((((Scheme_Simple_Object * ) (cdr ) ) -> u . pair_val . car ) , notdisplay , compact , ht , mt , pp ) ); 
    cdr = (((Scheme_Simple_Object * ) (cdr ) ) -> u . pair_val . cdr ) ; 
  }
  if (! ((cdr ) == (scheme_null ) ) ) {
#   define XfOrM443_COUNT (0+XfOrM442_COUNT)
#   define SETUP_XfOrM443(x) SETUP_XfOrM442(x)
    if (! compact )
      FUNCCALL(SETUP_XfOrM443(_), print_utf8_string (pp , " . " , 0 , 3 ) ); 
    FUNCCALL(SETUP_XfOrM443(_), print (cdr , notdisplay , compact , ht , mt , pp ) ); 
  }
  else if (compact && (super_compact < 1 ) )
    FUNCCALL(SETUP_XfOrM442(_), print_this_string (pp , & compacts [CPT_NULL ] , 0 , 1 ) ); 
  if (! compact )
    FUNCCALL_EMPTY(print_utf8_string (pp , ")" , 0 , 1 ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void print_vector (Scheme_Object * vec , int notdisplay , int compact , Scheme_Hash_Table * ht , Scheme_Marshal_Tables * mt , PrintParams * pp ) {
  int i , size , common = 0 ; 
  Scheme_Object * * elems ; 
  PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(mt, 0), PUSH(elems, 1), PUSH(vec, 2), PUSH(pp, 3), PUSH(ht, 4)));
# define XfOrM478_COUNT (5)
# define SETUP_XfOrM478(x) SETUP(XfOrM478_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  elems = NULLED_OUT ; 
  size = (((Scheme_Vector * ) (vec ) ) -> size ) ; 
  if (compact ) {
#   define XfOrM491_COUNT (0+XfOrM478_COUNT)
#   define SETUP_XfOrM491(x) SETUP_XfOrM478(x)
    FUNCCALL(SETUP_XfOrM491(_), print_this_string (pp , & compacts [CPT_VECTOR ] , 0 , 1 ) ); 
    FUNCCALL(SETUP_XfOrM491(_), print_compact_number (pp , size ) ); 
  }
  else {
#   define XfOrM485_COUNT (0+XfOrM478_COUNT)
#   define SETUP_XfOrM485(x) SETUP_XfOrM478(x)
    elems = (((Scheme_Vector * ) (vec ) ) -> els ) ; 
    for (i = size ; i -- ; common ++ ) {
      if (! i || (elems [i ] != elems [i - 1 ] ) )
        break ; 
    }
    elems = ((void * ) 0 ) ; 
    if (notdisplay && pp -> print_vec_shorthand ) {
#     define XfOrM486_COUNT (0+XfOrM485_COUNT)
#     define SETUP_XfOrM486(x) SETUP_XfOrM485(x)
      if (size == 0 ) {
#       define XfOrM488_COUNT (0+XfOrM486_COUNT)
#       define SETUP_XfOrM488(x) SETUP_XfOrM486(x)
        if (pp -> honu_mode )
          FUNCCALL(SETUP_XfOrM488(_), print_utf8_string (pp , "vectorN(0" , 0 , 7 ) ); 
        else FUNCCALL(SETUP_XfOrM488(_), print_utf8_string (pp , "#0(" , 0 , 3 ) ); 
      }
      else {
        char buffer [100 ] ; 
#       define XfOrM487_COUNT (0+XfOrM486_COUNT)
#       define SETUP_XfOrM487(x) SETUP_XfOrM486(x)
        (sprintf (buffer , pp -> honu_mode ? "vectorN(%d, " : "#%d(" , size ) ) ; 
        FUNCCALL(SETUP_XfOrM487(_), print_utf8_string (pp , buffer , 0 , - 1 ) ); 
        size -= common ; 
      }
    }
    else if (pp -> honu_mode )
      FUNCCALL(SETUP_XfOrM485(_), print_utf8_string (pp , "vector(" , 0 , 7 ) ); 
    else FUNCCALL(SETUP_XfOrM485(_), print_utf8_string (pp , "#(" , 0 , 2 ) ); 
  }
  for (i = 0 ; i < size ; i ++ ) {
#   define XfOrM482_COUNT (0+XfOrM478_COUNT)
#   define SETUP_XfOrM482(x) SETUP_XfOrM478(x)
    FUNCCALL(SETUP_XfOrM482(_), print ((((Scheme_Vector * ) (vec ) ) -> els ) [i ] , notdisplay , compact , ht , mt , pp ) ); 
    if (i < (size - 1 ) ) {
#     define XfOrM483_COUNT (0+XfOrM482_COUNT)
#     define SETUP_XfOrM483(x) SETUP_XfOrM482(x)
      if (! compact ) {
#       define XfOrM484_COUNT (0+XfOrM483_COUNT)
#       define SETUP_XfOrM484(x) SETUP_XfOrM483(x)
        if (pp -> honu_mode )
          FUNCCALL(SETUP_XfOrM484(_), print_utf8_string (pp , ", " , 0 , 2 ) ); 
        else FUNCCALL(SETUP_XfOrM484(_), print_utf8_string (pp , " " , 0 , 1 ) ); 
      }
    }
  }
  if (! compact )
    FUNCCALL_EMPTY(print_utf8_string (pp , ")" , 0 , 1 ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void print_char (Scheme_Object * charobj , int notdisplay , PrintParams * pp ) {
  int ch ; 
  char minibuf [10 + 6 ] , * str ; 
  int len = - 1 ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(pp, 0), PUSH(str, 1)));
# define XfOrM492_COUNT (2)
# define SETUP_XfOrM492(x) SETUP(XfOrM492_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  str = NULLED_OUT ; 
  ch = (((Scheme_Small_Object * ) (charobj ) ) -> u . char_val ) ; 
  if (notdisplay ) {
#   define XfOrM494_COUNT (0+XfOrM492_COUNT)
#   define SETUP_XfOrM494(x) SETUP_XfOrM492(x)
    switch (ch ) {
#     define XfOrM495_COUNT (0+XfOrM494_COUNT)
#     define SETUP_XfOrM495(x) SETUP_XfOrM494(x)
      case '\0' : str = "#\\nul" ; 
      break ; 
      case '\n' : str = "#\\newline" ; 
      break ; 
      case '\t' : str = "#\\tab" ; 
      break ; 
      case 0xb : str = "#\\vtab" ; 
      break ; 
      case ' ' : str = "#\\space" ; 
      break ; 
      case '\r' : str = "#\\return" ; 
      break ; 
      case '\f' : str = "#\\page" ; 
      break ; 
      case '\b' : str = "#\\backspace" ; 
      break ; 
      case 0x7f : str = "#\\rubout" ; 
      break ; 
      default : if ((((scheme_uchar_table [(ch >> 8 ) & 0x1FFF ] [ch & 0xFF ] ) ) & 0x800 ) ) {
#       define XfOrM497_COUNT (0+XfOrM495_COUNT)
#       define SETUP_XfOrM497(x) SETUP_XfOrM495(x)
        minibuf [0 ] = '#' ; 
        minibuf [1 ] = '\\' ; 
        ch = FUNCCALL(SETUP_XfOrM497(_), scheme_utf8_encode ((unsigned int * ) & ch , 0 , 1 , (unsigned char * ) minibuf , 2 , 0 ) ); 
        minibuf [2 + ch ] = 0 ; 
      }
      else {
#       define XfOrM496_COUNT (0+XfOrM495_COUNT)
#       define SETUP_XfOrM496(x) SETUP_XfOrM495(x)
        if (ch > 0xFFFF )
          (sprintf (minibuf , "#\\U%.8X" , ch ) ) ; 
        else (sprintf (minibuf , "#\\u%.4X" , ch ) ) ; 
      }
      str = minibuf ; 
      break ; 
    }
  }
  else {
#   define XfOrM493_COUNT (0+XfOrM492_COUNT)
#   define SETUP_XfOrM493(x) SETUP_XfOrM492(x)
    len = FUNCCALL(SETUP_XfOrM493(_), scheme_utf8_encode ((unsigned int * ) & ch , 0 , 1 , (unsigned char * ) minibuf , 0 , 0 ) ); 
    minibuf [len ] = 0 ; 
    str = minibuf ; 
  }
  FUNCCALL_EMPTY(print_utf8_string (pp , str , 0 , len ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_protect_quote (Scheme_Object * expr ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(expr, 0)));
# define XfOrM498_COUNT (1)
# define SETUP_XfOrM498(x) SETUP(XfOrM498_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((((Scheme_Type ) (((((long ) (expr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (expr ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || ((Scheme_Type ) (((((long ) (expr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (expr ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) || (1 && ((Scheme_Type ) (((((long ) (expr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (expr ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) || (0 ) || (0 ) || (1 && ((Scheme_Type ) (((((long ) (expr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (expr ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) ) ) ) {
    Scheme_Object * q ; 
    BLOCK_SETUP((PUSH(q, 0+XfOrM498_COUNT)));
#   define XfOrM499_COUNT (1+XfOrM498_COUNT)
#   define SETUP_XfOrM499(x) SETUP(XfOrM499_COUNT)
    q = NULLED_OUT ; 
    q = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM499(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    q -> type = scheme_quote_compilation_type ; 
    (((Scheme_Small_Object * ) (q ) ) -> u . ptr_val ) = expr ; 
    RET_VALUE_START (q ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (expr ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_set_type_printer (Scheme_Type stype , Scheme_Type_Printer printer ) {
  PREPARE_VAR_STACK(1);
# define XfOrM500_COUNT (0)
# define SETUP_XfOrM500(x) SETUP(XfOrM500_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! printers ) {
#   define XfOrM502_COUNT (0+XfOrM500_COUNT)
#   define SETUP_XfOrM502(x) SETUP_XfOrM500(x)
    FUNCCALL(SETUP_XfOrM502(_), scheme_register_static ((void * ) & printers , sizeof (printers ) ) ); 
  }
  if (stype >= printers_count ) {
    Scheme_Type_Printer * naya ; 
    BLOCK_SETUP((PUSH(naya, 0+XfOrM500_COUNT)));
#   define XfOrM501_COUNT (1+XfOrM500_COUNT)
#   define SETUP_XfOrM501(x) SETUP(XfOrM501_COUNT)
    naya = NULLED_OUT ; 
    naya = ((Scheme_Type_Printer * ) FUNCCALL(SETUP_XfOrM501(_), GC_malloc (sizeof (Scheme_Type_Printer ) * (stype + 10 ) ) )) ; 
    (memset (naya , 0 , sizeof (Scheme_Type_Printer ) * (stype + 10 ) ) ) ; 
    (memcpy (naya , printers , sizeof (Scheme_Type_Printer ) * printers_count ) ) ; 
    printers_count = stype + 10 ; 
    printers = naya ; 
  }
  printers [stype ] = printer ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * accum_write (void * _b , int argc , Scheme_Object * * argv ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(_b, 0)));
# define XfOrM503_COUNT (1)
# define SETUP_XfOrM503(x) SETUP(XfOrM503_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((((Scheme_Small_Object * ) (_b ) ) -> u . ptr_val ) ) {
    Scheme_Object * v ; 
    BLOCK_SETUP((PUSH(v, 0+XfOrM503_COUNT)));
#   define XfOrM504_COUNT (1+XfOrM503_COUNT)
#   define SETUP_XfOrM504(x) SETUP(XfOrM504_COUNT)
    v = NULLED_OUT ; 
    v = FUNCCALL(SETUP_XfOrM504(_), scheme_make_pair (argv [0 ] , (((Scheme_Small_Object * ) (_b ) ) -> u . ptr_val ) ) ); 
    (((Scheme_Small_Object * ) (_b ) ) -> u . ptr_val ) = v ; 
  }
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * writable_struct_subs (Scheme_Object * s , PrintParams * pp ) {
  Scheme_Object * v , * o , * a [3 ] , * b , * accum_proc ; 
  Scheme_Output_Port * op ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(10);
  BLOCK_SETUP_TOP((PUSH(pp, 0), PUSHARRAY(a, 3, 1), PUSH(o, 4), PUSH(accum_proc, 5), PUSH(v, 6), PUSH(b, 7), PUSH(s, 8), PUSH(op, 9)));
# define XfOrM505_COUNT (10)
# define SETUP_XfOrM505(x) SETUP(XfOrM505_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  o = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  a[2] = NULLED_OUT ; 
  b = NULLED_OUT ; 
  accum_proc = NULLED_OUT ; 
  op = NULLED_OUT ; 
  v = FUNCCALL(SETUP_XfOrM505(_), scheme_is_writable_struct (s ) ); 
  o = FUNCCALL_AGAIN(scheme_make_null_output_port (pp -> print_port && ((Scheme_Output_Port * ) pp -> print_port ) -> write_special_fun ) ); 
  op = (Scheme_Output_Port * ) o ; 
  b = FUNCCALL(SETUP_XfOrM505(_), scheme_box (scheme_null ) ); 
  accum_proc = FUNCCALL_AGAIN(scheme_make_closed_prim_w_arity (accum_write , b , "custom-write-recur-handler" , 2 , 2 ) ); 
  op -> display_handler = accum_proc ; 
  op -> write_handler = accum_proc ; 
  op -> print_handler = accum_proc ; 
  a [0 ] = s ; 
  a [1 ] = o ; 
  a [2 ] = scheme_false ; 
  FUNCCALL(SETUP_XfOrM505(_), scheme_apply_multi (v , 3 , a ) ); 
  FUNCCALL_AGAIN(scheme_close_output_port (o ) ); 
  v = (((Scheme_Small_Object * ) (b ) ) -> u . ptr_val ) ; 
  (((Scheme_Small_Object * ) (b ) ) -> u . ptr_val ) = ((void * ) 0 ) ; 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void flush_from_byte_port (Scheme_Object * orig_port , PrintParams * pp ) {
  char * bytes ; 
  long len ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(bytes, 0), PUSH(pp, 1)));
# define XfOrM506_COUNT (2)
# define SETUP_XfOrM506(x) SETUP(XfOrM506_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  bytes = NULLED_OUT ; 
  bytes = FUNCCALL(SETUP_XfOrM506(_), scheme_get_sized_byte_string_output (orig_port , & len ) ); 
  FUNCCALL_EMPTY(print_this_string (pp , bytes , 0 , len ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * custom_recur (int notdisplay , void * _vec , int argc , Scheme_Object * * argv ) {
  Scheme_Hash_Table * ht = (Scheme_Hash_Table * ) (((Scheme_Vector * ) (_vec ) ) -> els ) [0 ] ; 
  Scheme_Marshal_Tables * mt = (Scheme_Marshal_Tables * ) (((Scheme_Vector * ) (_vec ) ) -> els ) [1 ] ; 
  PrintParams * volatile pp = (PrintParams * ) (((Scheme_Vector * ) (_vec ) ) -> els ) [2 ] ; 
  Scheme_Object * volatile save_port ; 
  mz_jmp_buf escape , * volatile save ; 
  volatile long save_max ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(ht, 0), PUSH(_vec, 1), PUSH(pp, 2), PUSH(mt, 3), PUSH(save, 4), PUSH(save_port, 5), PUSH(argv, 6)));
# define XfOrM507_COUNT (7)
# define SETUP_XfOrM507(x) SETUP(XfOrM507_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  save_port = NULLED_OUT ; 
  save = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_output_port_type ) ) ) {
#   define XfOrM514_COUNT (0+XfOrM507_COUNT)
#   define SETUP_XfOrM514(x) SETUP_XfOrM507(x)
    FUNCCALL_EMPTY(scheme_wrong_type (notdisplay ? "write/recusrive" : "display/recursive" , "output-port" , 1 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if ((((Scheme_Vector * ) (_vec ) ) -> els ) [3 ] ) {
#   define XfOrM508_COUNT (0+XfOrM507_COUNT)
#   define SETUP_XfOrM508(x) SETUP_XfOrM507(x)
    {
#     define XfOrM509_COUNT (0+XfOrM508_COUNT)
#     define SETUP_XfOrM509(x) SETUP_XfOrM508(x)
      if (pp -> print_escape ) {
        save = pp -> print_escape ; 
        pp -> print_escape = & escape ; 
      }
      else save = ((void * ) 0 ) ; 
      save_port = pp -> print_port ; 
      save_max = pp -> print_maxlen ; 
      if (! pp -> print_escape || ! ((escape ) . gcvs = (long ) __gc_var_stack__ , (escape ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((escape ) . jb ) , (_setjmp (((escape ) . jb ) -> jb ) ) ) ) ) {
        Scheme_Object * sp ; 
        BLOCK_SETUP((PUSH(sp, 0+XfOrM509_COUNT)));
#       define XfOrM510_COUNT (1+XfOrM509_COUNT)
#       define SETUP_XfOrM510(x) SETUP(XfOrM510_COUNT)
        sp = NULLED_OUT ; 
        sp = (((Scheme_Vector * ) (_vec ) ) -> els ) [4 ] ; 
        if (sp ) {
#         define XfOrM512_COUNT (0+XfOrM510_COUNT)
#         define SETUP_XfOrM512(x) SETUP_XfOrM510(x)
          FUNCCALL(SETUP_XfOrM512(_), flush_from_byte_port (sp , pp ) ); 
          sp = FUNCCALL(SETUP_XfOrM512(_), scheme_make_byte_string_output_port () ); 
          ((Scheme_Output_Port * ) (((Scheme_Vector * ) (_vec ) ) -> els ) [5 ] ) -> port_data = sp ; 
          (((Scheme_Vector * ) (_vec ) ) -> els ) [4 ] = sp ; 
        }
        if (! ((save_port ) == (argv [1 ] ) ) ) {
#         define XfOrM511_COUNT (0+XfOrM510_COUNT)
#         define SETUP_XfOrM511(x) SETUP_XfOrM510(x)
          FUNCCALL(SETUP_XfOrM511(_), print_this_string (pp , ((void * ) 0 ) , 0 , 0 ) ); 
          pp -> print_maxlen = 0 ; 
        }
        pp -> print_port = argv [1 ] ; 
        FUNCCALL(SETUP_XfOrM510(_), print (argv [0 ] , notdisplay , 0 , ht , mt , pp ) ); 
        FUNCCALL_AGAIN(print_this_string (pp , ((void * ) 0 ) , 0 , 0 ) ); 
      }
      pp -> print_port = save_port ; 
      pp -> print_escape = save ; 
      pp -> print_maxlen = save_max ; 
    }
  }
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * custom_write_recur (void * _vec , int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return custom_recur (1 , _vec , argc , argv ) ; 
}
static Scheme_Object * custom_display_recur (void * _vec , int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return custom_recur (0 , _vec , argc , argv ) ; 
}
static void custom_write_struct (Scheme_Object * s , Scheme_Hash_Table * ht , Scheme_Marshal_Tables * mt , PrintParams * orig_pp , int notdisplay ) {
  Scheme_Object * v , * a [3 ] , * o , * vec , * orig_port ; 
  Scheme_Output_Port * op ; 
  Scheme_Object * recur_write , * recur_display ; 
  PrintParams * pp ; 
  PREPARE_VAR_STACK_ONCE(15);
  BLOCK_SETUP_TOP((PUSH(ht, 0), PUSH(pp, 1), PUSH(v, 2), PUSH(recur_write, 3), PUSH(orig_port, 4), PUSH(s, 5), PUSH(orig_pp, 6), PUSH(mt, 7), PUSH(vec, 8), PUSHARRAY(a, 3, 9), PUSH(o, 12), PUSH(recur_display, 13), PUSH(op, 14)));
# define XfOrM517_COUNT (15)
# define SETUP_XfOrM517(x) SETUP(XfOrM517_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  a[2] = NULLED_OUT ; 
  o = NULLED_OUT ; 
  vec = NULLED_OUT ; 
  orig_port = NULLED_OUT ; 
  op = NULLED_OUT ; 
  recur_write = NULLED_OUT ; 
  recur_display = NULLED_OUT ; 
  pp = NULLED_OUT ; 
  v = FUNCCALL(SETUP_XfOrM517(_), scheme_is_writable_struct (s ) ); 
  pp = FUNCCALL_AGAIN(copy_print_params (orig_pp ) ); 
  if (pp -> print_port )
    orig_port = pp -> print_port ; 
  else orig_port = FUNCCALL(SETUP_XfOrM517(_), scheme_make_byte_string_output_port () ); 
  o = FUNCCALL(SETUP_XfOrM517(_), scheme_make_redirect_output_port (orig_port ) ); 
  op = (Scheme_Output_Port * ) o ; 
  vec = FUNCCALL(SETUP_XfOrM517(_), scheme_make_vector (6 , ((void * ) 0 ) ) ); 
  (((Scheme_Vector * ) (vec ) ) -> els ) [0 ] = (Scheme_Object * ) ht ; 
  (((Scheme_Vector * ) (vec ) ) -> els ) [1 ] = (Scheme_Object * ) mt ; 
  (((Scheme_Vector * ) (vec ) ) -> els ) [2 ] = (Scheme_Object * ) pp ; 
  (((Scheme_Vector * ) (vec ) ) -> els ) [3 ] = scheme_true ; 
  (((Scheme_Vector * ) (vec ) ) -> els ) [4 ] = (pp -> print_port ? ((void * ) 0 ) : orig_port ) ; 
  (((Scheme_Vector * ) (vec ) ) -> els ) [5 ] = o ; 
  recur_write = FUNCCALL(SETUP_XfOrM517(_), scheme_make_closed_prim_w_arity (custom_write_recur , vec , "custom-write-recur-handler" , 2 , 2 ) ); 
  recur_display = FUNCCALL_AGAIN(scheme_make_closed_prim_w_arity (custom_display_recur , vec , "custom-display-recur-handler" , 2 , 2 ) ); 
  op -> write_handler = recur_write ; 
  op -> display_handler = recur_display ; 
  op -> print_handler = recur_write ; 
  if (pp -> print_port )
    FUNCCALL(SETUP_XfOrM517(_), print_this_string (pp , ((void * ) 0 ) , 0 , 0 ) ); 
  a [0 ] = s ; 
  a [1 ] = o ; 
  a [2 ] = (notdisplay ? scheme_true : scheme_false ) ; 
  FUNCCALL(SETUP_XfOrM517(_), scheme_apply_multi (v , 3 , a ) ); 
  FUNCCALL_AGAIN(scheme_close_output_port (o ) ); 
  (memcpy (orig_pp , pp , sizeof (PrintParams ) ) ) ; 
  (((Scheme_Vector * ) (vec ) ) -> els ) [3 ] = ((void * ) 0 ) ; 
  if (! orig_pp -> print_port )
    FUNCCALL(SETUP_XfOrM517(_), flush_from_byte_port ((((Scheme_Vector * ) (vec ) ) -> els ) [4 ] , orig_pp ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int mark_print_params_SIZE (void * p ) {
  return ((sizeof (PrintParams ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_print_params_MARK (void * p ) {
  PrintParams * pp = (PrintParams * ) p ; 
  GC_mark (pp -> inspector ) ; 
  GC_mark (pp -> print_port ) ; 
  GC_mark (pp -> print_buffer ) ; 
  return ((sizeof (PrintParams ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_print_params_FIXUP (void * p ) {
  PrintParams * pp = (PrintParams * ) p ; 
  GC_fixup (& (pp -> inspector ) ) ; 
  GC_fixup (& (pp -> print_port ) ) ; 
  GC_fixup (& (pp -> print_buffer ) ) ; 
  return ((sizeof (PrintParams ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_marshal_tables_SIZE (void * p ) {
  return ((sizeof (Scheme_Marshal_Tables ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_marshal_tables_MARK (void * p ) {
  Scheme_Marshal_Tables * mt = (Scheme_Marshal_Tables * ) p ; 
  GC_mark (mt -> symtab ) ; 
  GC_mark (mt -> rns ) ; 
  GC_mark (mt -> rn_refs ) ; 
  GC_mark (mt -> st_refs ) ; 
  GC_mark (mt -> st_ref_stack ) ; 
  GC_mark (mt -> reverse_map ) ; 
  GC_mark (mt -> same_map ) ; 
  GC_mark (mt -> top_map ) ; 
  GC_mark (mt -> key_map ) ; 
  GC_mark (mt -> delay_map ) ; 
  GC_mark (mt -> rn_saved ) ; 
  GC_mark (mt -> shared_offsets ) ; 
  GC_mark (mt -> sorted_keys ) ; 
  return ((sizeof (Scheme_Marshal_Tables ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_marshal_tables_FIXUP (void * p ) {
  Scheme_Marshal_Tables * mt = (Scheme_Marshal_Tables * ) p ; 
  GC_fixup (& (mt -> symtab ) ) ; 
  GC_fixup (& (mt -> rns ) ) ; 
  GC_fixup (& (mt -> rn_refs ) ) ; 
  GC_fixup (& (mt -> st_refs ) ) ; 
  GC_fixup (& (mt -> st_ref_stack ) ) ; 
  GC_fixup (& (mt -> reverse_map ) ) ; 
  GC_fixup (& (mt -> same_map ) ) ; 
  GC_fixup (& (mt -> top_map ) ) ; 
  GC_fixup (& (mt -> key_map ) ) ; 
  GC_fixup (& (mt -> delay_map ) ) ; 
  GC_fixup (& (mt -> rn_saved ) ) ; 
  GC_fixup (& (mt -> shared_offsets ) ) ; 
  GC_fixup (& (mt -> sorted_keys ) ) ; 
  return ((sizeof (Scheme_Marshal_Tables ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static void register_traversers (void ) {
  GC_register_traversers (scheme_rt_print_params , mark_print_params_SIZE , mark_print_params_MARK , mark_print_params_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_marshal_info , mark_marshal_tables_SIZE , mark_marshal_tables_MARK , mark_marshal_tables_FIXUP , 1 , 0 ) ; 
}
