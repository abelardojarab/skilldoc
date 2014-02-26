#include "precomp.h"
enum {
  _ISupper = ((0 ) < 8 ? ((1 << (0 ) ) << 8 ) : ((1 << (0 ) ) >> 8 ) ) , _ISlower = ((1 ) < 8 ? ((1 << (1 ) ) << 8 ) : ((1 << (1 ) ) >> 8 ) ) , _ISalpha = ((2 ) < 8 ? ((1 << (2 ) ) << 8 ) : ((1 << (2 ) ) >> 8 ) ) , _ISdigit = ((3 ) < 8 ? ((1 << (3 ) ) << 8 ) : ((1 << (3 ) ) >> 8 ) ) , _ISxdigit = ((4 ) < 8 ? ((1 << (4 ) ) << 8 ) : ((1 << (4 ) ) >> 8 ) ) , _ISspace = ((5 ) < 8 ? ((1 << (5 ) ) << 8 ) : ((1 << (5 ) ) >> 8 ) ) , _ISprint = ((6 ) < 8 ? ((1 << (6 ) ) << 8 ) : ((1 << (6 ) ) >> 8 ) ) , _ISgraph = ((7 ) < 8 ? ((1 << (7 ) ) << 8 ) : ((1 << (7 ) ) >> 8 ) ) , _ISblank = ((8 ) < 8 ? ((1 << (8 ) ) << 8 ) : ((1 << (8 ) ) >> 8 ) ) , _IScntrl = ((9 ) < 8 ? ((1 << (9 ) ) << 8 ) : ((1 << (9 ) ) >> 8 ) ) , _ISpunct = ((10 ) < 8 ? ((1 << (10 ) ) << 8 ) : ((1 << (10 ) ) >> 8 ) ) , _ISalnum = ((11 ) < 8 ? ((1 << (11 ) ) << 8 ) : ((1 << (11 ) ) >> 8 ) ) }
; 
scheme_console_printf_t scheme_console_printf ; 
scheme_console_printf_t scheme_get_console_printf () {
  /* No conversion */
  return scheme_console_printf ; 
}
void (* scheme_console_output ) (char * str , long len ) ; 
Scheme_Exit_Proc scheme_exit ; 
void scheme_set_exit (Scheme_Exit_Proc p ) {
  /* No conversion */
  scheme_exit = p ; 
}
static Scheme_Object * error (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * raise_user_error (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * raise_syntax_error (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * raise_type_error (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * raise_mismatch_error (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * raise_arity_error (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * error_escape_handler (int , Scheme_Object * [] ) ; 
static Scheme_Object * error_display_handler (int , Scheme_Object * [] ) ; 
static Scheme_Object * error_value_string_handler (int , Scheme_Object * [] ) ; 
static Scheme_Object * exit_handler (int , Scheme_Object * [] ) ; 
static Scheme_Object * error_print_width (int , Scheme_Object * [] ) ; 
static Scheme_Object * error_print_context_length (int , Scheme_Object * [] ) ; 
static Scheme_Object * error_print_srcloc (int , Scheme_Object * [] ) ; 
static Scheme_Object * def_error_escape_proc (int , Scheme_Object * [] ) ; 
static Scheme_Object * def_error_display_proc (int , Scheme_Object * [] ) ; 
static Scheme_Object * emergency_error_display_proc (int , Scheme_Object * [] ) ; 
static Scheme_Object * def_error_value_string_proc (int , Scheme_Object * [] ) ; 
static Scheme_Object * def_exit_handler_proc (int , Scheme_Object * [] ) ; 
static Scheme_Object * do_raise (Scheme_Object * arg , int need_debug ) ; 
static Scheme_Object * nested_exn_handler (void * old_exn , int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * def_err_val_proc ; 
static Scheme_Object * def_error_esc_proc ; 
static Scheme_Object * default_display_handler , * emergency_display_handler ; 
Scheme_Object * scheme_def_exit_proc ; 
Scheme_Object * scheme_raise_arity_error_proc ; 
static char * init_buf (long * len , long * blen ) ; 
static char * prepared_buf ; 
static long prepared_buf_len ; 
static Scheme_Object * kernel_symbol ; 
typedef struct {
  int args ; 
  Scheme_Object * type ; 
  Scheme_Object * * names ; 
  int count ; 
  Scheme_Object * exptime ; 
  int super_pos ; 
}
exn_rec ; 
static exn_rec * exn_table ; 
static void default_printf (char * msg , ... ) {
  /* No conversion */
  GC_CAN_IGNORE va_list args ; 
  HIDE_FROM_XFORM (__builtin_va_start (args , msg ) ) ; 
  vfprintf (stderr , msg , args ) ; 
  HIDE_FROM_XFORM (__builtin_va_end (args ) ) ; 
  fflush (stderr ) ; 
}
static void default_output (char * s , long len ) {
  /* No conversion */
  fwrite (s , len , 1 , stderr ) ; 
  fflush (stderr ) ; 
}
Scheme_Config * scheme_init_error_escape_proc (Scheme_Config * config ) {
  DECL_RET_SAVE (Scheme_Config * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(config, 0)));
# define XfOrM5_COUNT (1)
# define SETUP_XfOrM5(x) SETUP(XfOrM5_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! def_error_esc_proc ) {
#   define XfOrM7_COUNT (0+XfOrM5_COUNT)
#   define SETUP_XfOrM7(x) SETUP_XfOrM5(x)
    FUNCCALL(SETUP_XfOrM7(_), scheme_register_static ((void * ) & def_error_esc_proc , sizeof (def_error_esc_proc ) ) ); 
    def_error_esc_proc = FUNCCALL(SETUP_XfOrM7(_), scheme_make_prim_w_arity (def_error_escape_proc , "default-error-escape-handler" , 0 , 0 ) ); 
  }
  if (config )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_extend_config (config , MZCONFIG_ERROR_ESCAPE_HANDLER , def_error_esc_proc ) )) RET_VALUE_EMPTY_END ; 
  else {
#   define XfOrM6_COUNT (0+XfOrM5_COUNT)
#   define SETUP_XfOrM6(x) SETUP_XfOrM5(x)
    FUNCCALL_EMPTY(scheme_set_root_param (MZCONFIG_ERROR_ESCAPE_HANDLER , def_error_esc_proc ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static long sch_vsprintf (char * s , long maxlen , const char * msg , va_list args ) {
  long i , j ; 
  char buf [100 ] ; 
  int pp = 0 , ip = 0 , dp = 0 ; 
  void * ptrs [25 ] ; 
  long ints [25 ] ; 
  double dbls [25 ] ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(msg, 0), PUSHARRAY(ptrs, 25, 1), PUSH(s, 4)));
# define XfOrM8_COUNT (5)
# define SETUP_XfOrM8(x) SETUP(XfOrM8_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  NULL_OUT_ARRAY (ptrs ) ; 
  for (j = 0 ; msg [j ] ; j ++ ) {
    if (msg [j ] == '%' ) {
      int type ; 
      j ++ ; 
      type = msg [j ] ; 
      switch (type ) {
        case 'c' : ints [ip ++ ] = HIDE_FROM_XFORM (__builtin_va_arg (args , int ) ) ; 
        break ; 
        case 'd' : case 'o' : ints [ip ++ ] = HIDE_FROM_XFORM (__builtin_va_arg (args , int ) ) ; 
        break ; 
        case 'l' : ints [ip ++ ] = HIDE_FROM_XFORM (__builtin_va_arg (args , long ) ) ; 
        break ; 
        case 'f' : dbls [dp ++ ] = HIDE_FROM_XFORM (__builtin_va_arg (args , double ) ) ; 
        break ; 
        case 'L' : ints [ip ++ ] = HIDE_FROM_XFORM (__builtin_va_arg (args , long ) ) ; 
        break ; 
        case 'e' : case 'E' : ints [ip ++ ] = HIDE_FROM_XFORM (__builtin_va_arg (args , int ) ) ; 
        break ; 
        case 'N' : ints [ip ++ ] = HIDE_FROM_XFORM (__builtin_va_arg (args , int ) ) ; 
        ints [ip ++ ] = HIDE_FROM_XFORM (__builtin_va_arg (args , int ) ) ; 
        break ; 
        case 'Z' : ints [ip ++ ] = HIDE_FROM_XFORM (__builtin_va_arg (args , int ) ) ; 
        ptrs [pp ++ ] = HIDE_FROM_XFORM (__builtin_va_arg (args , char * ) ) ; 
        break ; 
        case 'S' : case 'V' : case 'T' : case 'Q' : ptrs [pp ++ ] = HIDE_FROM_XFORM (__builtin_va_arg (args , Scheme_Object * ) ) ; 
        break ; 
        default : ptrs [pp ++ ] = HIDE_FROM_XFORM (__builtin_va_arg (args , char * ) ) ; 
        if ((type == 't' ) || (type == 'u' ) ) {
          ints [ip ++ ] = HIDE_FROM_XFORM (__builtin_va_arg (args , long ) ) ; 
        }
      }
    }
  }
  pp = 0 ; 
  ip = 0 ; 
  dp = 0 ; 
  -- maxlen ; 
  i = j = 0 ; 
  while ((i < maxlen ) && msg [j ] ) {
#   define XfOrM43_COUNT (0+XfOrM8_COUNT)
#   define SETUP_XfOrM43(x) SETUP_XfOrM8(x)
    if (msg [j ] == '%' ) {
      int type ; 
      j ++ ; 
#     define XfOrM45_COUNT (0+XfOrM43_COUNT)
#     define SETUP_XfOrM45(x) SETUP_XfOrM43(x)
      type = msg [j ++ ] ; 
      if (type == '%' )
        s [i ++ ] = '%' ; 
      else {
        const char * t ; 
        int tlen ; 
        int dots = 0 ; 
        BLOCK_SETUP((PUSH(t, 0+XfOrM45_COUNT)));
#       define XfOrM46_COUNT (1+XfOrM45_COUNT)
#       define SETUP_XfOrM46(x) SETUP(XfOrM46_COUNT)
        t = NULLED_OUT ; 
        switch (type ) {
#         define XfOrM53_COUNT (0+XfOrM46_COUNT)
#         define SETUP_XfOrM53(x) SETUP_XfOrM46(x)
          case 'c' : {
            int c ; 
#           define XfOrM74_COUNT (0+XfOrM53_COUNT)
#           define SETUP_XfOrM74(x) SETUP_XfOrM53(x)
            c = ints [ip ++ ] ; 
            if (c < 128 ) {
              buf [0 ] = c ; 
              tlen = 1 ; 
            }
            else {
              mzchar mc ; 
#             define XfOrM75_COUNT (0+XfOrM74_COUNT)
#             define SETUP_XfOrM75(x) SETUP_XfOrM74(x)
              tlen = FUNCCALL(SETUP_XfOrM75(_), scheme_utf8_encode_all (& mc , 1 , (unsigned char * ) buf ) ); 
              c = (int ) mc ; 
            }
            t = buf ; 
          }
          break ; 
          case 'd' : {
            int d ; 
#           define XfOrM73_COUNT (0+XfOrM53_COUNT)
#           define SETUP_XfOrM73(x) SETUP_XfOrM53(x)
            d = ints [ip ++ ] ; 
            (sprintf (buf , "%d" , d ) ) ; 
            t = buf ; 
            tlen = strlen (t ) ; 
          }
          break ; 
          case 'o' : {
            int d ; 
#           define XfOrM72_COUNT (0+XfOrM53_COUNT)
#           define SETUP_XfOrM72(x) SETUP_XfOrM53(x)
            d = ints [ip ++ ] ; 
            (sprintf (buf , "%o" , d ) ) ; 
            t = buf ; 
            tlen = strlen (t ) ; 
          }
          break ; 
          case 'l' : {
            long d ; 
            j ++ ; 
#           define XfOrM71_COUNT (0+XfOrM53_COUNT)
#           define SETUP_XfOrM71(x) SETUP_XfOrM53(x)
            d = ints [ip ++ ] ; 
            (sprintf (buf , "%ld" , d ) ) ; 
            t = buf ; 
            tlen = strlen (t ) ; 
          }
          break ; 
          case 'f' : {
            double f ; 
            j ++ ; 
#           define XfOrM70_COUNT (0+XfOrM53_COUNT)
#           define SETUP_XfOrM70(x) SETUP_XfOrM53(x)
            f = dbls [dp ++ ] ; 
            (sprintf (buf , "%f" , f ) ) ; 
            t = buf ; 
            tlen = strlen (t ) ; 
          }
          break ; 
          case 'L' : {
            long d ; 
#           define XfOrM67_COUNT (0+XfOrM53_COUNT)
#           define SETUP_XfOrM67(x) SETUP_XfOrM53(x)
            d = ints [ip ++ ] ; 
            if (d >= 0 ) {
#             define XfOrM69_COUNT (0+XfOrM67_COUNT)
#             define SETUP_XfOrM69(x) SETUP_XfOrM67(x)
              (sprintf (buf , "%ld:" , d ) ) ; 
              t = buf ; 
              tlen = strlen (t ) ; 
            }
            else {
              t = ":" ; 
              tlen = 1 ; 
            }
          }
          break ; 
          case 'e' : case 'E' : case 'Z' : case 'N' : {
            int en , he ; 
            char * es ; 
            BLOCK_SETUP((PUSH(es, 0+XfOrM53_COUNT)));
#           define XfOrM63_COUNT (1+XfOrM53_COUNT)
#           define SETUP_XfOrM63(x) SETUP(XfOrM63_COUNT)
            es = NULLED_OUT ; 
            if (type == 'N' ) {
              he = ints [ip ++ ] ; 
              type = 'E' ; 
            }
            else he = 0 ; 
            en = ints [ip ++ ] ; 
            if (type == 'Z' )
              es = ptrs [pp ++ ] ; 
            else es = ((void * ) 0 ) ; 
            if (he )
              es = (char * ) FUNCCALL(SETUP_XfOrM63(_), scheme_hostname_error (en ) ); 
            if (en || es ) {
#             define XfOrM65_COUNT (0+XfOrM63_COUNT)
#             define SETUP_XfOrM65(x) SETUP_XfOrM63(x)
              if (! es )
                es = FUNCCALL(SETUP_XfOrM65(_), strerror (en ) ); 
              tlen = strlen (es ) + 24 ; 
              t = (const char * ) FUNCCALL(SETUP_XfOrM65(_), GC_malloc_atomic (tlen ) ); 
              (sprintf ((char * ) t , "%s; errno=%d" , es , en ) ) ; 
              tlen = strlen (t ) ; 
            }
            else {
              t = "errno=?" ; 
              tlen = 7 ; 
            }
          }
          break ; 
          case 'S' : {
            Scheme_Object * sym ; 
#           define XfOrM62_COUNT (0+XfOrM53_COUNT)
#           define SETUP_XfOrM62(x) SETUP_XfOrM53(x)
            sym = NULLED_OUT ; 
            sym = (Scheme_Object * ) ptrs [pp ++ ] ; 
            t = FUNCCALL(SETUP_XfOrM62(_), scheme_symbol_name_and_size (sym , (unsigned int * ) & tlen , 0 ) ); 
          }
          break ; 
          case 'V' : {
            Scheme_Object * o ; 
#           define XfOrM61_COUNT (0+XfOrM53_COUNT)
#           define SETUP_XfOrM61(x) SETUP_XfOrM53(x)
            o = NULLED_OUT ; 
            o = (Scheme_Object * ) ptrs [pp ++ ] ; 
            t = FUNCCALL(SETUP_XfOrM61(_), scheme_make_provided_string (o , 1 , & tlen ) ); 
          }
          break ; 
          case 'T' : case 'Q' : {
            Scheme_Object * str ; 
            BLOCK_SETUP((PUSH(str, 0+XfOrM53_COUNT)));
#           define XfOrM60_COUNT (1+XfOrM53_COUNT)
#           define SETUP_XfOrM60(x) SETUP(XfOrM60_COUNT)
            str = NULLED_OUT ; 
            str = (Scheme_Object * ) ptrs [pp ++ ] ; 
            if (((Scheme_Type ) (((((long ) (str ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (str ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
              str = FUNCCALL(SETUP_XfOrM60(_), scheme_char_string_to_byte_string (str ) ); 
            t = (((Scheme_Simple_Object * ) (str ) ) -> u . byte_str_val . string_val ) ; 
            tlen = (((Scheme_Simple_Object * ) (str ) ) -> u . byte_str_val . tag_val ) ; 
          }
          break ; 
          case 'u' : case '5' : {
            mzchar * u ; 
            long ltlen ; 
            BLOCK_SETUP((PUSH(u, 0+XfOrM53_COUNT)));
#           define XfOrM57_COUNT (1+XfOrM53_COUNT)
#           define SETUP_XfOrM57(x) SETUP(XfOrM57_COUNT)
            u = NULLED_OUT ; 
            u = (mzchar * ) ptrs [pp ++ ] ; 
            if (type == 'u' ) {
#             define XfOrM59_COUNT (0+XfOrM57_COUNT)
#             define SETUP_XfOrM59(x) SETUP_XfOrM57(x)
              tlen = ints [ip ++ ] ; 
              if (tlen < 0 )
                tlen = FUNCCALL(SETUP_XfOrM59(_), scheme_char_strlen (u ) ); 
            }
            else {
#             define XfOrM58_COUNT (0+XfOrM57_COUNT)
#             define SETUP_XfOrM58(x) SETUP_XfOrM57(x)
              tlen = FUNCCALL(SETUP_XfOrM58(_), scheme_char_strlen (u ) ); 
            }
            t = FUNCCALL(SETUP_XfOrM57(_), scheme_utf8_encode_to_buffer_len (u , tlen , ((void * ) 0 ) , 0 , & ltlen ) ); 
            tlen = ltlen ; 
          }
          break ; 
          default : {
            t = (char * ) ptrs [pp ++ ] ; 
            if (type == 't' ) {
              tlen = ints [ip ++ ] ; 
              if (tlen < 0 )
                tlen = strlen (t ) ; 
            }
            else {
              tlen = strlen (t ) ; 
            }
          }
          break ; 
        }
        if ((type == 'q' ) || (type == 'Q' ) ) {
          if (tlen > 256 ) {
            tlen = 250 ; 
            dots = 1 ; 
          }
        }
        while (tlen && i < maxlen ) {
          s [i ++ ] = * t ; 
          t = t XFORM_OK_PLUS 1 ; 
          tlen -- ; 
        }
        if (dots ) {
          if (i < maxlen - 3 ) {
            s [i ++ ] = '.' ; 
            s [i ++ ] = '.' ; 
            s [i ++ ] = '.' ; 
          }
        }
      }
    }
    else {
      s [i ++ ] = msg [j ++ ] ; 
    }
  }
  s [i ] = 0 ; 
  RET_VALUE_START (i ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static long scheme_sprintf (char * s , long maxlen , const char * msg , ... ) {
  /* No conversion */
  long len ; 
  GC_CAN_IGNORE va_list args ; 
  HIDE_FROM_XFORM (__builtin_va_start (args , msg ) ) ; 
  len = sch_vsprintf (s , maxlen , msg , args ) ; 
  HIDE_FROM_XFORM (__builtin_va_end (args ) ) ; 
  return len ; 
}
void scheme_init_error (Scheme_Env * env ) {
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
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(env, 0)));
# define XfOrM86_COUNT (1)
# define SETUP_XfOrM86(x) SETUP(XfOrM86_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! scheme_console_printf )
    scheme_console_printf = default_printf ; 
  if (! scheme_console_output )
    scheme_console_output = default_output ; 
  FUNCCALL(SETUP_XfOrM86(_), scheme_register_static ((void * ) & scheme_raise_arity_error_proc , sizeof (scheme_raise_arity_error_proc ) ) ); 
  (__funcarg17 = FUNCCALL(SETUP_XfOrM86(_), scheme_make_prim_w_arity (error , "error" , 1 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("error" , __funcarg17 , env ) )) ; 
  (__funcarg16 = FUNCCALL(SETUP_XfOrM86(_), scheme_make_prim_w_arity (raise_user_error , "raise-user-error" , 1 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("raise-user-error" , __funcarg16 , env ) )) ; 
  (__funcarg15 = FUNCCALL(SETUP_XfOrM86(_), scheme_make_prim_w_arity (raise_syntax_error , "raise-syntax-error" , 2 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("raise-syntax-error" , __funcarg15 , env ) )) ; 
  (__funcarg14 = FUNCCALL(SETUP_XfOrM86(_), scheme_make_prim_w_arity (raise_type_error , "raise-type-error" , 3 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("raise-type-error" , __funcarg14 , env ) )) ; 
  (__funcarg13 = FUNCCALL(SETUP_XfOrM86(_), scheme_make_prim_w_arity (raise_mismatch_error , "raise-mismatch-error" , 3 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("raise-mismatch-error" , __funcarg13 , env ) )) ; 
  scheme_raise_arity_error_proc = FUNCCALL_AGAIN(scheme_make_prim_w_arity (raise_arity_error , "raise-arity-error" , 2 , - 1 ) ); 
  FUNCCALL_AGAIN(scheme_add_global_constant ("raise-arity-error" , scheme_raise_arity_error_proc , env ) ); 
  (__funcarg12 = FUNCCALL(SETUP_XfOrM86(_), scheme_register_parameter (error_display_handler , "error-display-handler" , MZCONFIG_ERROR_DISPLAY_HANDLER ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("error-display-handler" , __funcarg12 , env ) )) ; 
  (__funcarg11 = FUNCCALL(SETUP_XfOrM86(_), scheme_register_parameter (error_value_string_handler , "error-value->string-handler" , MZCONFIG_ERROR_PRINT_VALUE_HANDLER ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("error-value->string-handler" , __funcarg11 , env ) )) ; 
  (__funcarg10 = FUNCCALL(SETUP_XfOrM86(_), scheme_register_parameter (error_escape_handler , "error-escape-handler" , MZCONFIG_ERROR_ESCAPE_HANDLER ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("error-escape-handler" , __funcarg10 , env ) )) ; 
  (__funcarg9 = FUNCCALL(SETUP_XfOrM86(_), scheme_register_parameter (exit_handler , "exit-handler" , MZCONFIG_EXIT_HANDLER ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("exit-handler" , __funcarg9 , env ) )) ; 
  (__funcarg8 = FUNCCALL(SETUP_XfOrM86(_), scheme_register_parameter (error_print_width , "error-print-width" , MZCONFIG_ERROR_PRINT_WIDTH ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("error-print-width" , __funcarg8 , env ) )) ; 
  (__funcarg7 = FUNCCALL(SETUP_XfOrM86(_), scheme_register_parameter (error_print_context_length , "error-print-context-length" , MZCONFIG_ERROR_PRINT_CONTEXT_LENGTH ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("error-print-context-length" , __funcarg7 , env ) )) ; 
  (__funcarg6 = FUNCCALL(SETUP_XfOrM86(_), scheme_register_parameter (error_print_srcloc , "error-print-source-location" , MZCONFIG_ERROR_PRINT_SRCLOC ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("error-print-source-location" , __funcarg6 , env ) )) ; 
  (__funcarg5 = FUNCCALL(SETUP_XfOrM86(_), scheme_make_prim_w_arity (scheme_do_exit , "exit" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("exit" , __funcarg5 , env ) )) ; 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & scheme_def_exit_proc , sizeof (scheme_def_exit_proc ) ) ); 
  scheme_def_exit_proc = FUNCCALL_EMPTY(scheme_make_prim_w_arity (def_exit_handler_proc , "default-exit-handler" , 1 , 1 ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & def_err_val_proc , sizeof (def_err_val_proc ) ) ); 
  def_err_val_proc = FUNCCALL_EMPTY(scheme_make_prim_w_arity (def_error_value_string_proc , "default-error-value->string-handler" , 2 , 2 ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & prepared_buf , sizeof (prepared_buf ) ) ); 
  prepared_buf = "" ; 
  prepared_buf = FUNCCALL_EMPTY(init_buf (((void * ) 0 ) , & prepared_buf_len ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & kernel_symbol , sizeof (kernel_symbol ) ) ); 
  kernel_symbol = FUNCCALL_EMPTY(scheme_intern_symbol ("#%kernel" ) ); 
  FUNCCALL_EMPTY(scheme_init_error_config () ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_init_error_config (void ) {
  /* No conversion */
  scheme_set_root_param (MZCONFIG_EXIT_HANDLER , scheme_def_exit_proc ) ; 
  scheme_register_static ((void * ) & default_display_handler , sizeof (default_display_handler ) ) ; 
  scheme_register_static ((void * ) & emergency_display_handler , sizeof (emergency_display_handler ) ) ; 
  default_display_handler = scheme_make_prim_w_arity (def_error_display_proc , "default-error-display-handler" , 2 , 2 ) ; 
  emergency_display_handler = scheme_make_prim_w_arity (emergency_error_display_proc , "emergency-error-display-handler" , 2 , 2 ) ; 
  scheme_set_root_param (MZCONFIG_ERROR_DISPLAY_HANDLER , default_display_handler ) ; 
  scheme_set_root_param (MZCONFIG_ERROR_PRINT_VALUE_HANDLER , def_err_val_proc ) ; 
}
static void scheme_inescapeable_error (const char * a , const char * b ) {
  int al , bl ; 
  char * t ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(t, 0), PUSH(a, 1), PUSH(b, 2)));
# define XfOrM88_COUNT (3)
# define SETUP_XfOrM88(x) SETUP(XfOrM88_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  t = NULLED_OUT ; 
  al = strlen (a ) ; 
  bl = strlen (b ) ; 
  t = FUNCCALL(SETUP_XfOrM88(_), GC_malloc_atomic (al + bl + 2 ) ); 
  (memcpy (t , a , al ) ) ; 
  (memcpy (t + al , b , bl ) ) ; 
  t [al + bl ] = '\n' ; 
  t [al + bl + 1 ] = 0 ; 
  FUNCCALL_EMPTY(scheme_console_output (t , al + bl + 1 ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void call_error (char * buffer , int len , Scheme_Object * exn ) {
  Scheme_Object * __funcarg19 = NULLED_OUT ; 
  Scheme_Object * __funcarg18 = NULLED_OUT ; 
  PREPARE_VAR_STACK(12);
  BLOCK_SETUP_TOP((PUSH(buffer, 0), PUSH(exn, 1)));
# define XfOrM89_COUNT (2)
# define SETUP_XfOrM89(x) SETUP(XfOrM89_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (scheme_current_thread -> skip_error ) {
    (((long * ) (void * ) ((* (scheme_current_thread -> error_buf ) ) . gcvs ) ) [1 ] = (* (scheme_current_thread -> error_buf ) ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* (scheme_current_thread -> error_buf ) ) . gcvs , scheme_jit_longjmp ((* (scheme_current_thread -> error_buf ) ) . jb , 1 ) ) ; 
  }
  else {
    mz_jmp_buf savebuf ; 
    Scheme_Object * p [2 ] , * display_handler , * escape_handler , * v ; 
    Scheme_Config * config , * orig_config ; 
    Scheme_Cont_Frame_Data cframe , cframe2 ; 
    BLOCK_SETUP((PUSH(escape_handler, 0+XfOrM89_COUNT), PUSH(cframe.cache, 1+XfOrM89_COUNT), PUSH(cframe2.cache, 2+XfOrM89_COUNT), PUSH(orig_config, 3+XfOrM89_COUNT), PUSH(v, 4+XfOrM89_COUNT), PUSH(config, 5+XfOrM89_COUNT), PUSH(display_handler, 6+XfOrM89_COUNT), PUSHARRAY(p, 2, 7+XfOrM89_COUNT)));
#   define XfOrM90_COUNT (10+XfOrM89_COUNT)
#   define SETUP_XfOrM90(x) SETUP(XfOrM90_COUNT)
    p[0] = NULLED_OUT ; 
    p[1] = NULLED_OUT ; 
    display_handler = NULLED_OUT ; 
    escape_handler = NULLED_OUT ; 
    v = NULLED_OUT ; 
    config = NULLED_OUT ; 
    orig_config = NULLED_OUT ; 
    cframe.cache = NULLED_OUT ; 
    cframe2.cache = NULLED_OUT ; 
    (memcpy ((void * ) & savebuf , & * (scheme_current_thread -> error_buf ) , sizeof (mz_jmp_buf ) ) ) ; 
    orig_config = FUNCCALL(SETUP_XfOrM90(_), scheme_current_config () ); 
    display_handler = FUNCCALL_AGAIN(scheme_get_param (orig_config , MZCONFIG_ERROR_DISPLAY_HANDLER ) ); 
    escape_handler = FUNCCALL_AGAIN(scheme_get_param (orig_config , MZCONFIG_ERROR_ESCAPE_HANDLER ) ); 
    v = FUNCCALL_AGAIN(scheme_make_byte_string_without_copying ("error display handler" ) ); 
    v = (__funcarg19 = FUNCCALL(SETUP_XfOrM90(_), scheme_make_pair (v , exn ) ), FUNCCALL_AGAIN(scheme_make_closed_prim_w_arity (nested_exn_handler , __funcarg19 , "nested-exception-handler" , 1 , 1 ) )) ; 
    config = orig_config ; 
    if (((display_handler ) == (default_display_handler ) ) )
      config = FUNCCALL(SETUP_XfOrM90(_), scheme_extend_config (config , MZCONFIG_ERROR_DISPLAY_HANDLER , emergency_display_handler ) ); 
    else config = FUNCCALL(SETUP_XfOrM90(_), scheme_extend_config (config , MZCONFIG_ERROR_DISPLAY_HANDLER , default_display_handler ) ); 
    FUNCCALL(SETUP_XfOrM90(_), scheme_push_continuation_frame (& cframe ) ); 
    FUNCCALL_AGAIN(scheme_install_config (config ) ); 
    FUNCCALL_AGAIN(scheme_set_cont_mark (scheme_exn_handler_key , v ) ); 
    FUNCCALL_AGAIN(scheme_push_break_enable (& cframe2 , 0 , 0 ) ); 
    p [0 ] = FUNCCALL(SETUP_XfOrM90(_), scheme_make_immutable_sized_utf8_string (buffer , len ) ); 
    p [1 ] = exn ; 
    FUNCCALL(SETUP_XfOrM90(_), scheme_apply_multi (display_handler , 2 , p ) ); 
    v = FUNCCALL_AGAIN(scheme_make_byte_string_without_copying ("error escape handler" ) ); 
    v = (__funcarg18 = FUNCCALL(SETUP_XfOrM90(_), scheme_make_pair (v , exn ) ), FUNCCALL_AGAIN(scheme_make_closed_prim_w_arity (nested_exn_handler , __funcarg18 , "nested-exception-handler" , 1 , 1 ) )) ; 
    config = FUNCCALL_AGAIN(scheme_extend_config (config , MZCONFIG_ERROR_DISPLAY_HANDLER , default_display_handler ) ); 
    config = FUNCCALL_AGAIN(scheme_extend_config (config , MZCONFIG_ERROR_ESCAPE_HANDLER , def_error_esc_proc ) ); 
    FUNCCALL_AGAIN(scheme_pop_break_enable (& cframe2 , 0 ) ); 
    FUNCCALL_AGAIN(scheme_pop_continuation_frame (& cframe ) ); 
    FUNCCALL_AGAIN(scheme_push_continuation_frame (& cframe ) ); 
    FUNCCALL_AGAIN(scheme_set_cont_mark (scheme_exn_handler_key , v ) ); 
    FUNCCALL_AGAIN(scheme_install_config (config ) ); 
    FUNCCALL_AGAIN(scheme_push_break_enable (& cframe2 , 0 , 0 ) ); 
    FUNCCALL_AGAIN(scheme_apply_multi (escape_handler , 0 , ((void * ) 0 ) ) ); 
    FUNCCALL_AGAIN(scheme_pop_break_enable (& cframe2 , 0 ) ); 
    FUNCCALL_AGAIN(scheme_pop_continuation_frame (& cframe ) ); 
    FUNCCALL_AGAIN(scheme_inescapeable_error ("error escape handler did not escape; calling the default error escape handler" , "" ) ); 
    (((long * ) (void * ) ((savebuf ) . gcvs ) ) [1 ] = (savebuf ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (savebuf ) . gcvs , scheme_jit_longjmp ((savebuf ) . jb , 1 ) ) ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static long get_print_width (void ) {
  long print_width ; 
  Scheme_Object * w ; 
  Scheme_Config * __funcarg20 = NULLED_OUT ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(w, 0)));
# define XfOrM92_COUNT (1)
# define SETUP_XfOrM92(x) SETUP(XfOrM92_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  w = NULLED_OUT ; 
  w = (__funcarg20 = FUNCCALL(SETUP_XfOrM92(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg20 , MZCONFIG_ERROR_PRINT_WIDTH ) )) ; 
  if ((((long ) (w ) ) & 0x1 ) )
    print_width = (((long ) (w ) ) >> 1 ) ; 
  else if (((Scheme_Type ) (((((long ) (w ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (w ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
    print_width = 0x7FFFFFFF ; 
  else print_width = 10000 ; 
  RET_VALUE_START (print_width ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static char * init_buf (long * len , long * _size ) {
  long size , print_width ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(len, 0), PUSH(_size, 1)));
# define XfOrM93_COUNT (2)
# define SETUP_XfOrM93(x) SETUP(XfOrM93_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  print_width = FUNCCALL(SETUP_XfOrM93(_), get_print_width () ); 
  if (len )
    * len = print_width ; 
  size = (3 * scheme_max_found_symbol_name + 500 + 2 * print_width ) ; 
  if (_size )
    * _size = size ; 
  RET_VALUE_START ((char * ) FUNCCALL_EMPTY(GC_malloc_atomic (size ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_reset_prepared_error_buffer (void ) {
  /* No conversion */
  if (prepared_buf )
    prepared_buf = init_buf (((void * ) 0 ) , & prepared_buf_len ) ; 
}
void scheme_signal_error (const char * msg , ... ) {
  GC_CAN_IGNORE va_list args ; 
  char * buffer ; 
  long len ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(buffer, 0)));
# define XfOrM95_COUNT (1)
# define SETUP_XfOrM95(x) SETUP(XfOrM95_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  buffer = NULLED_OUT ; 
  buffer = prepared_buf ; 
  HIDE_FROM_XFORM (__builtin_va_start (args , msg ) ) ; 
  len = FUNCCALL(SETUP_XfOrM95(_), sch_vsprintf (buffer , prepared_buf_len , msg , args ) ); 
  HIDE_FROM_XFORM (__builtin_va_end (args ) ) ; 
  prepared_buf = FUNCCALL(SETUP_XfOrM95(_), init_buf (((void * ) 0 ) , & prepared_buf_len ) ); 
  if (scheme_current_thread -> current_local_env ) {
    char * s2 = " [during expansion]" ; 
#   define XfOrM97_COUNT (0+XfOrM95_COUNT)
#   define SETUP_XfOrM97(x) SETUP_XfOrM95(x)
    (strcpy (buffer + len , s2 ) ) ; 
    len = strlen (s2 ) ; 
  }
  buffer [len ] = 0 ; 
  if (scheme_starting_up ) {
#   define XfOrM96_COUNT (0+XfOrM95_COUNT)
#   define SETUP_XfOrM96(x) SETUP_XfOrM95(x)
    buffer [len ++ ] = '\n' ; 
    buffer [len ] = 0 ; 
    FUNCCALL(SETUP_XfOrM96(_), scheme_console_output (buffer , len ) ); 
    FUNCCALL_EMPTY(exit (0 ) ); 
  }
  FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL , "%t" , buffer , len ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_warning (char * msg , ... ) {
  GC_CAN_IGNORE va_list args ; 
  char * buffer ; 
  long len ; 
  Scheme_Config * __funcarg22 = NULLED_OUT ; 
  Scheme_Object * __funcarg21 = NULLED_OUT ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(buffer, 0)));
# define XfOrM98_COUNT (1)
# define SETUP_XfOrM98(x) SETUP(XfOrM98_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  buffer = NULLED_OUT ; 
  buffer = prepared_buf ; 
  HIDE_FROM_XFORM (__builtin_va_start (args , msg ) ) ; 
  len = FUNCCALL(SETUP_XfOrM98(_), sch_vsprintf (buffer , prepared_buf_len , msg , args ) ); 
  HIDE_FROM_XFORM (__builtin_va_end (args ) ) ; 
  prepared_buf = FUNCCALL(SETUP_XfOrM98(_), init_buf (((void * ) 0 ) , & prepared_buf_len ) ); 
  buffer [len ++ ] = '\n' ; 
  buffer [len ] = 0 ; 
  (__funcarg21 = (__funcarg22 = FUNCCALL(SETUP_XfOrM98(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg22 , MZCONFIG_ERROR_PORT ) )) , FUNCCALL_AGAIN(scheme_write_byte_string (buffer , len , __funcarg21 ) )) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static char * error_write_to_string_w_max (Scheme_Object * v , int len , int * lenout ) {
  Scheme_Object * o , * args [2 ] ; 
  Scheme_Config * __funcarg25 = NULLED_OUT ; 
  Scheme_Config * __funcarg24 = NULLED_OUT ; 
  Scheme_Config * __funcarg23 = NULLED_OUT ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK(11);
  BLOCK_SETUP_TOP((PUSHARRAY(args, 2, 0), PUSH(v, 3), PUSH(lenout, 4), PUSH(o, 5)));
# define XfOrM99_COUNT (6)
# define SETUP_XfOrM99(x) SETUP(XfOrM99_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  o = NULLED_OUT ; 
  args[0] = NULLED_OUT ; 
  args[1] = NULLED_OUT ; 
  o = (__funcarg25 = FUNCCALL(SETUP_XfOrM99(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg25 , MZCONFIG_ERROR_PRINT_VALUE_HANDLER ) )) ; 
  if ((((o ) == (def_err_val_proc ) ) && (((__funcarg24 = FUNCCALL(SETUP_XfOrM99(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg24 , MZCONFIG_PORT_PRINT_HANDLER ) )) ) == (scheme_default_global_print_handler ) ) ) ) {
    long l ; 
    char * s ; 
    BLOCK_SETUP((PUSH(s, 0+XfOrM99_COUNT)));
#   define XfOrM105_COUNT (1+XfOrM99_COUNT)
#   define SETUP_XfOrM105(x) SETUP(XfOrM105_COUNT)
    s = NULLED_OUT ; 
    s = FUNCCALL(SETUP_XfOrM105(_), scheme_print_to_string_w_max (v , & l , len ) ); 
    if (lenout )
      * lenout = l ; 
    RET_VALUE_START (s ) RET_VALUE_END ; 
  }
  else {
    Scheme_Config * config ; 
    Scheme_Cont_Frame_Data cframe , cframe2 ; 
    BLOCK_SETUP((PUSH(config, 0+XfOrM99_COUNT), PUSH(cframe.cache, 1+XfOrM99_COUNT), PUSH(cframe2.cache, 2+XfOrM99_COUNT)));
#   define XfOrM100_COUNT (3+XfOrM99_COUNT)
#   define SETUP_XfOrM100(x) SETUP(XfOrM100_COUNT)
    config = NULLED_OUT ; 
    cframe.cache = NULLED_OUT ; 
    cframe2.cache = NULLED_OUT ; 
    args [0 ] = v ; 
    args [1 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (len ) ) << 1 ) | 0x1 ) ) ; 
    config = (__funcarg23 = FUNCCALL(SETUP_XfOrM100(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_extend_config (__funcarg23 , MZCONFIG_ERROR_PRINT_VALUE_HANDLER , def_err_val_proc ) )) ; 
    config = FUNCCALL_AGAIN(scheme_extend_config (config , MZCONFIG_PRINT_UNREADABLE , scheme_true ) ); 
    FUNCCALL_AGAIN(scheme_push_continuation_frame (& cframe ) ); 
    FUNCCALL_AGAIN(scheme_install_config (config ) ); 
    FUNCCALL_AGAIN(scheme_push_break_enable (& cframe2 , 0 , 0 ) ); 
    o = FUNCCALL_AGAIN(scheme_do_eval (o , 2 , args , 1 ) ); 
    FUNCCALL_AGAIN(scheme_pop_break_enable (& cframe2 , 0 ) ); 
    FUNCCALL_AGAIN(scheme_pop_continuation_frame (& cframe ) ); 
    if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) ) {
#     define XfOrM104_COUNT (0+XfOrM100_COUNT)
#     define SETUP_XfOrM104(x) SETUP_XfOrM100(x)
      o = FUNCCALL(SETUP_XfOrM104(_), scheme_char_string_to_byte_string (o ) ); 
    }
    if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ) {
      char * s = (((Scheme_Simple_Object * ) (o ) ) -> u . byte_str_val . string_val ) ; 
      BLOCK_SETUP((PUSH(s, 0+XfOrM100_COUNT)));
#     define XfOrM102_COUNT (1+XfOrM100_COUNT)
#     define SETUP_XfOrM102(x) SETUP(XfOrM102_COUNT)
      if ((((Scheme_Simple_Object * ) (o ) ) -> u . byte_str_val . tag_val ) > len ) {
        char * naya ; 
        BLOCK_SETUP((PUSH(naya, 0+XfOrM102_COUNT)));
#       define XfOrM103_COUNT (1+XfOrM102_COUNT)
#       define SETUP_XfOrM103(x) SETUP(XfOrM103_COUNT)
        naya = NULLED_OUT ; 
        naya = FUNCCALL(SETUP_XfOrM103(_), GC_malloc_atomic (len + 1 ) ); 
        (memcpy (naya , s , len ) ) ; 
        s [len ] = 0 ; 
        if (lenout )
          * lenout = len ; 
      }
      else if (lenout )
        * lenout = (((Scheme_Simple_Object * ) (o ) ) -> u . byte_str_val . tag_val ) ; 
      RET_VALUE_START (s ) RET_VALUE_END ; 
    }
    else {
      if (lenout )
        * lenout = 3 ; 
      RET_VALUE_START ("..." ) RET_VALUE_END ; 
    }
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static char * make_arity_expect_string (const char * name , int namelen , int minc , int maxc , int argc , Scheme_Object * * argv , long * _len , int is_method ) {
  long len , pos , slen ; 
  int xargc , xminc , xmaxc ; 
  char * s ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(_len, 0), PUSH(s, 1), PUSH(argv, 2), PUSH(name, 3)));
# define XfOrM106_COUNT (4)
# define SETUP_XfOrM106(x) SETUP(XfOrM106_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  s = NULLED_OUT ; 
  s = FUNCCALL(SETUP_XfOrM106(_), init_buf (& len , & slen ) ); 
  if (! name )
    name = "#<procedure>" ; 
  xargc = argc - (is_method ? 1 : 0 ) ; 
  xminc = minc - (is_method ? 1 : 0 ) ; 
  xmaxc = maxc - (is_method ? 1 : 0 ) ; 
  if ((minc == - 1 ) && ((Scheme_Type ) (((((long ) ((Scheme_Object * ) name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((Scheme_Object * ) name ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) {
    Scheme_Object * arity ; 
    BLOCK_SETUP((PUSH(arity, 0+XfOrM106_COUNT)));
#   define XfOrM114_COUNT (1+XfOrM106_COUNT)
#   define SETUP_XfOrM114(x) SETUP(XfOrM114_COUNT)
    arity = NULLED_OUT ; 
    arity = FUNCCALL(SETUP_XfOrM114(_), scheme_arity ((Scheme_Object * ) name ) ); 
    if ((((long ) (arity ) ) & 0x1 ) ) {
#     define XfOrM115_COUNT (0+XfOrM114_COUNT)
#     define SETUP_XfOrM115(x) SETUP_XfOrM114(x)
      xminc = xmaxc = minc = maxc = (((long ) (arity ) ) >> 1 ) ; 
      name = FUNCCALL(SETUP_XfOrM115(_), scheme_get_proc_name ((Scheme_Object * ) name , & namelen , 1 ) ); 
      if (! name ) {
        name = "#<procedure>" ; 
        namelen = strlen (name ) ; 
      }
    }
  }
  if (minc < 0 ) {
    const char * n ; 
    int nlen ; 
    BLOCK_SETUP((PUSH(n, 0+XfOrM106_COUNT)));
#   define XfOrM111_COUNT (1+XfOrM106_COUNT)
#   define SETUP_XfOrM111(x) SETUP(XfOrM111_COUNT)
    n = NULLED_OUT ; 
    if (minc == - 2 ) {
      n = name ; 
      nlen = (namelen < 0 ? strlen (n ) : namelen ) ; 
    }
    else n = FUNCCALL(SETUP_XfOrM111(_), scheme_get_proc_name ((Scheme_Object * ) name , & nlen , 1 ) ); 
    if (! n ) {
      n = "#<case-lambda-procedure>" ; 
      nlen = strlen (n ) ; 
    }
    pos = FUNCCALL(SETUP_XfOrM111(_), scheme_sprintf (s , slen , "%t: no clause matching %d argument%s" , n , nlen , xargc , xargc == 1 ? "" : "s" ) ); 
  }
  else if (! maxc )
    pos = FUNCCALL(SETUP_XfOrM106(_), scheme_sprintf (s , slen , "%t: expects no arguments, given %d" , name , namelen , xargc ) ); 
  else if (maxc < 0 )
    pos = FUNCCALL(SETUP_XfOrM106(_), scheme_sprintf (s , slen , "%t: expects at least %d argument%s, given %d" , name , namelen , xminc , (xminc == 1 ) ? "" : "s" , xargc ) ); 
  else if (minc == maxc )
    pos = FUNCCALL(SETUP_XfOrM106(_), scheme_sprintf (s , slen , "%t: expects %d argument%s, given %d" , name , namelen , xminc , (xminc == 1 ) ? "" : "s" , xargc ) ); 
  else pos = FUNCCALL(SETUP_XfOrM106(_), scheme_sprintf (s , slen , "%t: expects %d to %d arguments, given %d" , name , namelen , xminc , xmaxc , xargc ) ); 
  if (xargc && argv ) {
    len /= xargc ; 
#   define XfOrM107_COUNT (0+XfOrM106_COUNT)
#   define SETUP_XfOrM107(x) SETUP_XfOrM106(x)
    if ((xargc < 50 ) && (len >= 3 ) ) {
      int i ; 
#     define XfOrM108_COUNT (0+XfOrM107_COUNT)
#     define SETUP_XfOrM108(x) SETUP_XfOrM107(x)
      (strcpy (s + pos , ":" ) ) ; 
      pos ++ ; 
      for (i = (is_method ? 1 : 0 ) ; i < argc ; i ++ ) {
        int l ; 
        char * o ; 
        BLOCK_SETUP((PUSH(o, 0+XfOrM108_COUNT)));
#       define XfOrM110_COUNT (1+XfOrM108_COUNT)
#       define SETUP_XfOrM110(x) SETUP(XfOrM110_COUNT)
        o = NULLED_OUT ; 
        o = FUNCCALL(SETUP_XfOrM110(_), error_write_to_string_w_max (argv [i ] , len , & l ) ); 
        (memcpy (s + pos , " " , 1 ) ) ; 
        (memcpy (s + pos + 1 , o , l ) ) ; 
        pos += l + 1 ; 
      }
      s [pos ] = 0 ; 
    }
  }
  * _len = pos ; 
  RET_VALUE_START (s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_wrong_count_m (const char * name , int minc , int maxc , int argc , Scheme_Object * * argv , int is_method ) {
  char * s ; 
  long len ; 
  Scheme_Thread * p = scheme_current_thread ; 
  PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(name, 0), PUSH(s, 1), PUSH(argv, 2), PUSH(p, 3)));
# define XfOrM117_COUNT (4)
# define SETUP_XfOrM117(x) SETUP(XfOrM117_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  s = NULLED_OUT ; 
  if (argv == p -> tail_buffer ) {
    GC_CAN_IGNORE Scheme_Object * * tb ; 
#   define XfOrM128_COUNT (0+XfOrM117_COUNT)
#   define SETUP_XfOrM128(x) SETUP_XfOrM117(x)
    p -> tail_buffer = ((void * ) 0 ) ; 
    tb = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM128(_), GC_malloc (sizeof (Scheme_Object * ) * (p -> tail_buffer_size ) ) )) ; 
    p -> tail_buffer = tb ; 
  }
  if (minc == - 1 ) {
#   define XfOrM118_COUNT (0+XfOrM117_COUNT)
#   define SETUP_XfOrM118(x) SETUP_XfOrM117(x)
    if ((((Scheme_Type ) (((((long ) ((Scheme_Object * ) name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((Scheme_Object * ) name ) ) -> type ) ) == (Scheme_Type ) (scheme_closure_type ) ) || ((Scheme_Type ) (((((long ) ((Scheme_Object * ) name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((Scheme_Object * ) name ) ) -> type ) ) == (Scheme_Type ) (scheme_case_closure_type ) ) ) ) {
      Scheme_Case_Lambda * cl = (Scheme_Case_Lambda * ) name ; 
      if (cl -> count ) {
        Scheme_Closure_Data * data ; 
        data = NULLED_OUT ; 
        data = (Scheme_Closure_Data * ) ((Scheme_Closure * ) cl -> array [0 ] ) -> code ; 
        if ((& (data ) -> iso ) -> so . keyex & 16 )
          is_method = 1 ; 
      }
      else if (cl -> name && ((Scheme_Type ) (((((long ) (cl -> name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (cl -> name ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) {
        is_method = 1 ; 
      }
    }
    else if (((Scheme_Type ) (((((long ) ((Scheme_Object * ) name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((Scheme_Object * ) name ) ) -> type ) ) == (Scheme_Type ) (scheme_native_closure_type ) ) ) {
      Scheme_Object * pa ; 
      BLOCK_SETUP((PUSH(pa, 0+XfOrM118_COUNT)));
#     define XfOrM119_COUNT (1+XfOrM118_COUNT)
#     define SETUP_XfOrM119(x) SETUP(XfOrM119_COUNT)
      pa = NULLED_OUT ; 
      pa = FUNCCALL(SETUP_XfOrM119(_), scheme_get_native_arity ((Scheme_Object * ) name ) ); 
      if (((Scheme_Type ) (((((long ) (pa ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (pa ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) {
        pa = (((Scheme_Small_Object * ) (pa ) ) -> u . ptr_val ) ; 
        is_method = 1 ; 
      }
      if ((((long ) (pa ) ) & 0x1 ) ) {
#       define XfOrM122_COUNT (0+XfOrM119_COUNT)
#       define SETUP_XfOrM122(x) SETUP_XfOrM119(x)
        minc = (((long ) (pa ) ) >> 1 ) ; 
        if (minc < 0 ) {
          minc = (- minc ) - 1 ; 
          maxc = - 1 ; 
        }
        else maxc = minc ; 
        name = FUNCCALL(SETUP_XfOrM122(_), scheme_get_proc_name ((Scheme_Object * ) name , ((void * ) 0 ) , 1 ) ); 
      }
      else if ((((Scheme_Type ) (((((long ) (pa ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (pa ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (pa ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (pa ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) ) {
#       define XfOrM121_COUNT (0+XfOrM119_COUNT)
#       define SETUP_XfOrM121(x) SETUP_XfOrM119(x)
        pa = ((Scheme_Structure * ) pa ) -> slots [0 ] ; 
        minc = (((long ) (pa ) ) >> 1 ) ; 
        maxc = - 1 ; 
        name = FUNCCALL(SETUP_XfOrM121(_), scheme_get_proc_name ((Scheme_Object * ) name , ((void * ) 0 ) , 1 ) ); 
      }
      else {
      }
    }
  }
  if (! argc || ! minc )
    is_method = 0 ; 
  if (maxc > 0x3FFFFFFE )
    maxc = - 1 ; 
  s = FUNCCALL(SETUP_XfOrM117(_), make_arity_expect_string (name , - 1 , minc , maxc , argc , argv , & len , is_method ) ); 
  FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT_ARITY , "%t" , s , len ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_wrong_count (const char * name , int minc , int maxc , int argc , Scheme_Object * * argv ) {
  /* No conversion */
  scheme_wrong_count_m (name , minc , maxc , argc , argv , 0 ) ; 
}
void scheme_case_lambda_wrong_count (const char * name , int argc , Scheme_Object * * argv , int is_method , int count , ... ) {
  char * s ; 
  long len ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(s, 0)));
# define XfOrM130_COUNT (1)
# define SETUP_XfOrM130(x) SETUP(XfOrM130_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  if (! argc )
    is_method = 0 ; 
  s = FUNCCALL(SETUP_XfOrM130(_), make_arity_expect_string (name , - 1 , - 2 , 0 , argc , argv , & len , is_method ) ); 
  FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT_ARITY , "%t" , s , len ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
char * scheme_make_arity_expect_string (Scheme_Object * proc , int argc , Scheme_Object * * argv , long * _slen ) {
  const char * name ; 
  int namelen = - 1 ; 
  int mina , maxa ; 
  PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(name, 0), PUSH(_slen, 1), PUSH(argv, 2), PUSH(proc, 3)));
# define XfOrM131_COUNT (4)
# define SETUP_XfOrM131(x) SETUP(XfOrM131_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  name = NULLED_OUT ; 
  if (((Scheme_Type ) (((((long ) (proc ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (proc ) ) -> type ) ) == (Scheme_Type ) (scheme_prim_type ) ) ) {
    name = ((Scheme_Primitive_Proc * ) proc ) -> name ; 
    mina = ((Scheme_Primitive_Proc * ) proc ) -> mina ; 
    if (mina < 0 ) {
      mina = - 2 ; 
      maxa = 0 ; 
    }
    else {
      maxa = ((Scheme_Primitive_Proc * ) proc ) -> mu . maxa ; 
      if (maxa > 0x3FFFFFFE )
        maxa = - 1 ; 
    }
  }
  else if (((Scheme_Type ) (((((long ) (proc ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (proc ) ) -> type ) ) == (Scheme_Type ) (scheme_closed_prim_type ) ) ) {
    name = ((Scheme_Closed_Primitive_Proc * ) proc ) -> name ; 
    mina = ((Scheme_Closed_Primitive_Proc * ) proc ) -> mina ; 
    maxa = ((Scheme_Closed_Primitive_Proc * ) proc ) -> maxa ; 
  }
  else if (((Scheme_Type ) (((((long ) (proc ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (proc ) ) -> type ) ) == (Scheme_Type ) (scheme_case_closure_type ) ) ) {
#   define XfOrM140_COUNT (0+XfOrM131_COUNT)
#   define SETUP_XfOrM140(x) SETUP_XfOrM131(x)
    name = FUNCCALL(SETUP_XfOrM140(_), scheme_get_proc_name (proc , & namelen , 1 ) ); 
    mina = - 2 ; 
    maxa = 0 ; 
  }
  else if (((Scheme_Type ) (((((long ) ((Scheme_Object * ) proc ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((Scheme_Object * ) proc ) ) -> type ) ) == (Scheme_Type ) (scheme_native_closure_type ) ) ) {
    Scheme_Object * pa ; 
    BLOCK_SETUP((PUSH(pa, 0+XfOrM131_COUNT)));
#   define XfOrM134_COUNT (1+XfOrM131_COUNT)
#   define SETUP_XfOrM134(x) SETUP(XfOrM134_COUNT)
    pa = NULLED_OUT ; 
    pa = FUNCCALL(SETUP_XfOrM134(_), scheme_get_native_arity ((Scheme_Object * ) proc ) ); 
    if (((Scheme_Type ) (((((long ) (pa ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (pa ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) {
      pa = (((Scheme_Small_Object * ) (pa ) ) -> u . ptr_val ) ; 
    }
    if ((((long ) (pa ) ) & 0x1 ) ) {
      mina = (((long ) (pa ) ) >> 1 ) ; 
      if (mina < 0 ) {
        mina = (- mina ) - 1 ; 
        maxa = - 1 ; 
      }
      else maxa = mina ; 
    }
    else if ((((Scheme_Type ) (((((long ) (pa ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (pa ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (pa ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (pa ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) ) {
      pa = ((Scheme_Structure * ) pa ) -> slots [0 ] ; 
      mina = (((long ) (pa ) ) >> 1 ) ; 
      maxa = - 1 ; 
    }
    else {
      mina = - 2 ; 
      maxa = 0 ; 
    }
    name = FUNCCALL(SETUP_XfOrM134(_), scheme_get_proc_name ((Scheme_Object * ) proc , & namelen , 1 ) ); 
  }
  else {
    Scheme_Closure_Data * data ; 
#   define XfOrM132_COUNT (0+XfOrM131_COUNT)
#   define SETUP_XfOrM132(x) SETUP_XfOrM131(x)
    data = NULLED_OUT ; 
    data = (Scheme_Closure_Data * ) ((Scheme_Closure * ) proc ) -> code ; 
    mina = maxa = data -> num_params ; 
    if ((& (data ) -> iso ) -> so . keyex & 1 ) {
      -- mina ; 
      maxa = - 1 ; 
    }
    name = FUNCCALL(SETUP_XfOrM132(_), scheme_get_proc_name (proc , & namelen , 1 ) ); 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(make_arity_expect_string (name , namelen , mina , maxa , argc , argv , _slen , 0 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
char * scheme_make_args_string (char * s , int which , int argc , Scheme_Object * * argv , long * _olen ) {
  char * other ; 
  long len ; 
  GC_CAN_IGNORE char * isres = "arguments" ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(other, 0), PUSH(_olen, 1), PUSH(argv, 2), PUSH(s, 3)));
# define XfOrM145_COUNT (4)
# define SETUP_XfOrM145(x) SETUP(XfOrM145_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  other = NULLED_OUT ; 
  other = FUNCCALL(SETUP_XfOrM145(_), init_buf (& len , ((void * ) 0 ) ) ); 
  if (argc < 0 ) {
    isres = "results" ; 
    argc = - argc ; 
  }
  len /= (argc - (((which >= 0 ) && (argc > 1 ) ) ? 1 : 0 ) ) ; 
  if ((argc < 50 ) && (len >= 3 ) ) {
    int i , pos ; 
#   define XfOrM147_COUNT (0+XfOrM145_COUNT)
#   define SETUP_XfOrM147(x) SETUP_XfOrM145(x)
    (sprintf (other , "; %s%s were:" , s , isres ) ) ; 
    pos = strlen (other ) ; 
    for (i = 0 ; i < argc ; i ++ ) {
#     define XfOrM150_COUNT (0+XfOrM147_COUNT)
#     define SETUP_XfOrM150(x) SETUP_XfOrM147(x)
      if (i != which ) {
        int l ; 
        char * o ; 
        BLOCK_SETUP((PUSH(o, 0+XfOrM150_COUNT)));
#       define XfOrM151_COUNT (1+XfOrM150_COUNT)
#       define SETUP_XfOrM151(x) SETUP(XfOrM151_COUNT)
        o = NULLED_OUT ; 
        o = FUNCCALL(SETUP_XfOrM151(_), error_write_to_string_w_max (argv [i ] , len , & l ) ); 
        (memcpy (other + pos , " " , 1 ) ) ; 
        (memcpy (other + pos + 1 , o , l ) ) ; 
        pos += l + 1 ; 
      }
    }
    other [pos ] = 0 ; 
    if (_olen )
      * _olen = pos ; 
  }
  else {
#   define XfOrM146_COUNT (0+XfOrM145_COUNT)
#   define SETUP_XfOrM146(x) SETUP_XfOrM145(x)
    (sprintf (other , "; given %d arguments total" , argc ) ) ; 
    if (_olen )
      * _olen = strlen (other ) ; 
  }
  RET_VALUE_START (other ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
const char * scheme_number_suffix (int which ) {
  /* No conversion */
  static char * ending [] = {
    "st" , "nd" , "rd" }
  ; 
  if (! which )
    return "th" ; 
  -- which ; 
  which = which % 100 ; 
  return ((which < 10 || which >= 20 ) && ((which % 10 ) < 3 ) ) ? ending [which % 10 ] : "th" ; 
}
void scheme_wrong_type (const char * name , const char * expected , int which , int argc , Scheme_Object * * argv ) {
  Scheme_Object * o ; 
  char * s ; 
  int slen ; 
  int isres = 0 ; 
  GC_CAN_IGNORE char * isress = "argument" ; 
  const char * __funcarg26 = NULLED_OUT ; 
  PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(name, 0), PUSH(s, 1), PUSH(expected, 2), PUSH(argv, 3)));
# define XfOrM154_COUNT (4)
# define SETUP_XfOrM154(x) SETUP(XfOrM154_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  o = NULLED_OUT ; 
  s = NULLED_OUT ; 
  o = argv [which < 0 ? 0 : which ] ; 
  if (argc < 0 ) {
    argc = - argc ; 
    isress = "result" ; 
    isres = 1 ; 
  }
  s = FUNCCALL(SETUP_XfOrM154(_), scheme_make_provided_string (o , 1 , & slen ) ); 
  if ((which < 0 ) || (argc == 1 ) )
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: expect%s %s of type <%s>; " "given %t" , name , (which < 0 ) ? "ed" : "s" , isress , expected , s , slen ) ); 
  else {
    char * other ; 
    long olen ; 
    BLOCK_SETUP((PUSH(other, 0+XfOrM154_COUNT)));
#   define XfOrM155_COUNT (1+XfOrM154_COUNT)
#   define SETUP_XfOrM155(x) SETUP(XfOrM155_COUNT)
    other = NULLED_OUT ; 
    if ((which >= 0 ) && (argc > 1 ) )
      other = FUNCCALL(SETUP_XfOrM155(_), scheme_make_args_string ("other " , which , (isres ? - argc : argc ) , argv , & olen ) ); 
    else {
      other = "" ; 
      olen = 0 ; 
    }
    (__funcarg26 = FUNCCALL(SETUP_XfOrM155(_), scheme_number_suffix (which + 1 ) ), FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: expects type <%s> as %d%s %s, " "given: %t%t" , name , expected , which + 1 , __funcarg26 , isress , s , slen , other , olen ) )) ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_wrong_field_type (Scheme_Object * c_name , const char * expected , Scheme_Object * o ) {
  const char * s ; 
  char * s2 ; 
  int l ; 
  Scheme_Object * a [1 ] ; 
  PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(s2, 0), PUSHARRAY(a, 1, 1), PUSH(expected, 4), PUSH(s, 5)));
# define XfOrM158_COUNT (6)
# define SETUP_XfOrM158(x) SETUP(XfOrM158_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  s2 = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  a [0 ] = o ; 
  s = FUNCCALL(SETUP_XfOrM158(_), scheme_symbol_name (c_name ) ); 
  l = strlen (s ) ; 
  s2 = (char * ) FUNCCALL(SETUP_XfOrM158(_), GC_malloc_atomic (l + 6 ) ); 
  (memcpy (s2 , "make-" , 5 ) ) ; 
  (memcpy (s2 + 5 , s , l + 1 ) ) ; 
  FUNCCALL(SETUP_XfOrM158(_), scheme_wrong_type (s2 , expected , - 1 , 0 , a ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_arg_mismatch (const char * name , const char * msg , Scheme_Object * o ) {
  char * s ; 
  int slen ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(msg, 0), PUSH(s, 1), PUSH(name, 2)));
# define XfOrM159_COUNT (3)
# define SETUP_XfOrM159(x) SETUP(XfOrM159_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  if (o )
    s = FUNCCALL(SETUP_XfOrM159(_), scheme_make_provided_string (o , 1 , & slen ) ); 
  else {
    s = "" ; 
    slen = 0 ; 
  }
  FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: %s%t" , name , msg , s , slen ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static char * make_srcloc_string (Scheme_Stx_Srcloc * srcloc , long * len ) {
  long line , col ; 
  Scheme_Object * src ; 
  char * srcstr , * result ; 
  long srclen , rlen ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(srcstr, 0), PUSH(src, 1), PUSH(len, 2), PUSH(result, 3)));
# define XfOrM161_COUNT (4)
# define SETUP_XfOrM161(x) SETUP(XfOrM161_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  src = NULLED_OUT ; 
  srcstr = NULLED_OUT ; 
  result = NULLED_OUT ; 
  if (! srcloc -> src || ((((srcloc -> src ) ) == (scheme_false ) ) && (srcloc -> pos < 0 ) ) ) {
    if (len )
      * len = 0 ; 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  line = srcloc -> line ; 
  col = srcloc -> col ; 
  if (col < 0 )
    col = srcloc -> pos ; 
  src = srcloc -> src ; 
  if (src && ((Scheme_Type ) (((((long ) (src ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (src ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) {
#   define XfOrM164_COUNT (0+XfOrM161_COUNT)
#   define SETUP_XfOrM164(x) SETUP_XfOrM161(x)
    src = FUNCCALL(SETUP_XfOrM164(_), scheme_remove_current_directory_prefix (src ) ); 
    srclen = (((Scheme_Simple_Object * ) (src ) ) -> u . byte_str_val . tag_val ) ; 
    if (srclen > 100 ) {
#     define XfOrM165_COUNT (0+XfOrM164_COUNT)
#     define SETUP_XfOrM165(x) SETUP_XfOrM164(x)
      srcstr = FUNCCALL(SETUP_XfOrM165(_), GC_malloc_atomic (100 ) ); 
      (memcpy (srcstr , (((Scheme_Simple_Object * ) (src ) ) -> u . byte_str_val . string_val ) + (srclen - 100 ) , 100 ) ) ; 
      srcstr [0 ] = '.' ; 
      srcstr [1 ] = '.' ; 
      srcstr [2 ] = '.' ; 
      srclen = 100 ; 
    }
    else srcstr = (((Scheme_Simple_Object * ) (src ) ) -> u . byte_str_val . string_val ) ; 
  }
  else srcstr = FUNCCALL(SETUP_XfOrM161(_), scheme_display_to_string_w_max (src , & srclen , 100 ) ); 
  result = (char * ) FUNCCALL(SETUP_XfOrM161(_), GC_malloc_atomic (srclen + 15 ) ); 
  if (col >= 0 ) {
#   define XfOrM163_COUNT (0+XfOrM161_COUNT)
#   define SETUP_XfOrM163(x) SETUP_XfOrM161(x)
    rlen = FUNCCALL(SETUP_XfOrM163(_), scheme_sprintf (result , srclen + 15 , "%t:%L%ld: " , srcstr , srclen , line , col - 1 ) ); 
  }
  else {
#   define XfOrM162_COUNT (0+XfOrM161_COUNT)
#   define SETUP_XfOrM162(x) SETUP_XfOrM161(x)
    rlen = FUNCCALL(SETUP_XfOrM162(_), scheme_sprintf (result , srclen + 15 , "%t::: " , srcstr , srclen ) ); 
  }
  if (len )
    * len = rlen ; 
  RET_VALUE_START (result ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_read_err (Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , long span , int gotc , Scheme_Object * indentation , const char * detail , ... ) {
  GC_CAN_IGNORE va_list args ; 
  char * s , * ls , lbuf [30 ] , * fn , * suggests ; 
  long slen , fnlen ; 
  int show_loc ; 
  Scheme_Object * loc ; 
  Scheme_Config * __funcarg28 = NULLED_OUT ; 
  Scheme_Object * __funcarg27 = NULLED_OUT ; 
  PREPARE_VAR_STACK(9);
  BLOCK_SETUP_TOP((PUSH(stxsrc, 0), PUSH(loc, 1), PUSH(port, 2), PUSH(fn, 3), PUSH(ls, 4), PUSH(indentation, 5), PUSH(suggests, 6), PUSH(s, 7)));
# define XfOrM167_COUNT (8)
# define SETUP_XfOrM167(x) SETUP(XfOrM167_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  s = NULLED_OUT ; 
  ls = NULLED_OUT ; 
  fn = NULLED_OUT ; 
  suggests = NULLED_OUT ; 
  loc = NULLED_OUT ; 
  s = prepared_buf ; 
  HIDE_FROM_XFORM (__builtin_va_start (args , detail ) ) ; 
  slen = FUNCCALL(SETUP_XfOrM167(_), sch_vsprintf (s , prepared_buf_len , detail , args ) ); 
  HIDE_FROM_XFORM (__builtin_va_end (args ) ) ; 
  prepared_buf = FUNCCALL(SETUP_XfOrM167(_), init_buf (((void * ) 0 ) , & prepared_buf_len ) ); 
  ls = "" ; 
  fnlen = 0 ; 
  show_loc = (! ((((__funcarg28 = FUNCCALL(SETUP_XfOrM167(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg28 , MZCONFIG_ERROR_PRINT_SRCLOC ) )) ) ) == (scheme_false ) ) ) ; 
  if (! pos )
    line = col = pos = - 1 ; 
  if (stxsrc ) {
    Scheme_Object * xsrc ; 
    BLOCK_SETUP((PUSH(xsrc, 0+XfOrM167_COUNT)));
#   define XfOrM173_COUNT (1+XfOrM167_COUNT)
#   define SETUP_XfOrM173(x) SETUP(XfOrM173_COUNT)
    xsrc = NULLED_OUT ; 
    xsrc = FUNCCALL(SETUP_XfOrM173(_), scheme_make_stx_w_offset (scheme_false , line , col , pos , span , stxsrc , scheme_false ) ); 
    stxsrc = ((Scheme_Stx * ) xsrc ) -> srcloc -> src ; 
    line = ((Scheme_Stx * ) xsrc ) -> srcloc -> line ; 
    col = ((Scheme_Stx * ) xsrc ) -> srcloc -> col ; 
    pos = ((Scheme_Stx * ) xsrc ) -> srcloc -> pos ; 
    if (show_loc )
      fn = FUNCCALL(SETUP_XfOrM173(_), make_srcloc_string (((Scheme_Stx * ) xsrc ) -> srcloc , & fnlen ) ); 
    else fn = ((void * ) 0 ) ; 
  }
  else fn = ((void * ) 0 ) ; 
  if (! fn && show_loc ) {
    long column ; 
#   define XfOrM169_COUNT (0+XfOrM167_COUNT)
#   define SETUP_XfOrM169(x) SETUP_XfOrM167(x)
    if (col < 0 )
      column = pos ; 
    else column = col ; 
    if (port ) {
      Scheme_Object * pn ; 
      BLOCK_SETUP((PUSH(pn, 0+XfOrM169_COUNT)));
#     define XfOrM171_COUNT (1+XfOrM169_COUNT)
#     define SETUP_XfOrM171(x) SETUP(XfOrM171_COUNT)
      pn = NULLED_OUT ; 
      pn = (((Scheme_Input_Port * ) port ) -> name ) ; 
      if (((Scheme_Type ) (((((long ) (pn ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (pn ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) {
#       define XfOrM172_COUNT (0+XfOrM171_COUNT)
#       define SETUP_XfOrM172(x) SETUP_XfOrM171(x)
        pn = FUNCCALL(SETUP_XfOrM172(_), scheme_remove_current_directory_prefix (pn ) ); 
        fn = (((Scheme_Simple_Object * ) (pn ) ) -> u . byte_str_val . string_val ) ; 
      }
      else fn = "UNKNOWN" ; 
    }
    else fn = "UNKNOWN" ; 
    fnlen = strlen (fn ) ; 
    if (column >= 0 ) {
#     define XfOrM170_COUNT (0+XfOrM169_COUNT)
#     define SETUP_XfOrM170(x) SETUP_XfOrM169(x)
      FUNCCALL(SETUP_XfOrM170(_), scheme_sprintf (lbuf , 30 , ":%L%ld: " , line , column - 1 ) ); 
      ls = lbuf ; 
    }
    else ls = ": " ; 
  }
  else if (! show_loc ) {
    fn = "" ; 
    fnlen = 0 ; 
  }
  if (indentation )
    suggests = FUNCCALL(SETUP_XfOrM167(_), scheme_extract_indentation_suggestions (indentation ) ); 
  else suggests = "" ; 
  loc = FUNCCALL(SETUP_XfOrM167(_), scheme_make_location (stxsrc ? stxsrc : scheme_false , (line < 0 ) ? scheme_false : ((Scheme_Object * ) (void * ) (long ) ((((long ) (line ) ) << 1 ) | 0x1 ) ) , (col < 0 ) ? scheme_false : ((Scheme_Object * ) (void * ) (long ) ((((long ) (col - 1 ) ) << 1 ) | 0x1 ) ) , (pos < 0 ) ? scheme_false : ((Scheme_Object * ) (void * ) (long ) ((((long ) (pos ) ) << 1 ) | 0x1 ) ) , (span < 0 ) ? scheme_false : ((Scheme_Object * ) (void * ) (long ) ((((long ) (span ) ) << 1 ) | 0x1 ) ) ) ); 
  (__funcarg27 = FUNCCALL(SETUP_XfOrM167(_), scheme_make_immutable_pair (loc , scheme_null ) ), FUNCCALL_EMPTY(scheme_raise_exn (((gotc == (- 1 ) ) ? MZEXN_FAIL_READ_EOF : ((gotc == (- 2 ) ) ? MZEXN_FAIL_READ_NON_CHAR : MZEXN_FAIL_READ ) ) , __funcarg27 , "%t%s%t%s" , fn , fnlen , ls , s , slen , suggests ) )) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
const char * scheme_compile_stx_string = "compile" ; 
const char * scheme_expand_stx_string = "expand" ; 
const char * scheme_application_stx_string = "application" ; 
const char * scheme_set_stx_string = "set!" ; 
const char * scheme_var_ref_string = "#%variable-reference" ; 
const char * scheme_begin_stx_string = "begin" ; 
static void do_wrong_syntax (const char * where , Scheme_Object * detail_form , Scheme_Object * form , char * s , long slen , Scheme_Object * extra_sources ) {
  long len , vlen , dvlen , blen , plen ; 
  char * buffer ; 
  char * v , * dv , * p ; 
  Scheme_Object * mod , * nomwho , * who ; 
  int show_src ; 
  Scheme_Config * __funcarg29 = NULLED_OUT ; 
  PREPARE_VAR_STACK(14);
  BLOCK_SETUP_TOP((PUSH(mod, 0), PUSH(buffer, 1), PUSH(extra_sources, 2), PUSH(dv, 3), PUSH(where, 4), PUSH(nomwho, 5), PUSH(form, 6), PUSH(v, 7), PUSH(s, 8), PUSH(detail_form, 9), PUSH(p, 10), PUSH(who, 11)));
# define XfOrM174_COUNT (12)
# define SETUP_XfOrM174(x) SETUP(XfOrM174_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  buffer = NULLED_OUT ; 
  v = NULLED_OUT ; 
  dv = NULLED_OUT ; 
  p = NULLED_OUT ; 
  mod = NULLED_OUT ; 
  nomwho = NULLED_OUT ; 
  who = NULLED_OUT ; 
  who = ((void * ) 0 ) ; 
  nomwho = ((void * ) 0 ) ; 
  mod = scheme_false ; 
  if (! s ) {
    s = "bad syntax" ; 
    slen = strlen (s ) ; 
  }
  if ((where == scheme_compile_stx_string ) || (where == scheme_expand_stx_string ) ) {
    who = nomwho = scheme_false ; 
  }
  else if (where == scheme_application_stx_string ) {
#   define XfOrM191_COUNT (0+XfOrM174_COUNT)
#   define SETUP_XfOrM191(x) SETUP_XfOrM174(x)
    who = FUNCCALL(SETUP_XfOrM191(_), scheme_intern_symbol ("#%app" ) ); 
    nomwho = who ; 
    mod = FUNCCALL(SETUP_XfOrM191(_), scheme_intern_symbol ("mzscheme" ) ); 
  }
  else if ((where == scheme_set_stx_string ) || (where == scheme_var_ref_string ) || (where == scheme_begin_stx_string ) ) {
#   define XfOrM190_COUNT (0+XfOrM174_COUNT)
#   define SETUP_XfOrM190(x) SETUP_XfOrM174(x)
    who = FUNCCALL(SETUP_XfOrM190(_), scheme_intern_symbol (where ) ); 
    nomwho = who ; 
    mod = FUNCCALL(SETUP_XfOrM190(_), scheme_intern_symbol ("mzscheme" ) ); 
    if (where == scheme_begin_stx_string )
      where = "begin (possibly implicit)" ; 
  }
  buffer = FUNCCALL(SETUP_XfOrM174(_), init_buf (& len , & blen ) ); 
  p = ((void * ) 0 ) ; 
  plen = 0 ; 
  show_src = (! ((((__funcarg29 = FUNCCALL(SETUP_XfOrM174(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg29 , MZCONFIG_ERROR_PRINT_SRCLOC ) )) ) ) == (scheme_false ) ) ) ; 
  if (form ) {
    Scheme_Object * pform ; 
    BLOCK_SETUP((PUSH(pform, 0+XfOrM174_COUNT)));
#   define XfOrM184_COUNT (1+XfOrM174_COUNT)
#   define SETUP_XfOrM184(x) SETUP(XfOrM184_COUNT)
    pform = NULLED_OUT ; 
    if (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ) {
#     define XfOrM187_COUNT (0+XfOrM184_COUNT)
#     define SETUP_XfOrM187(x) SETUP_XfOrM184(x)
      p = FUNCCALL(SETUP_XfOrM187(_), make_srcloc_string (((Scheme_Stx * ) form ) -> srcloc , & plen ) ); 
      pform = FUNCCALL(SETUP_XfOrM187(_), scheme_syntax_to_datum (form , 0 , ((void * ) 0 ) ) ); 
      if (! nomwho && (((Scheme_Type ) (((((long ) (((Scheme_Stx * ) form ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) form ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) || (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) form ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) form ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) ) ) {
        Scheme_Object * first ; 
        BLOCK_SETUP((PUSH(first, 0+XfOrM187_COUNT)));
#       define XfOrM188_COUNT (1+XfOrM187_COUNT)
#       define SETUP_XfOrM188(x) SETUP(XfOrM188_COUNT)
        first = NULLED_OUT ; 
        if ((((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) form ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) form ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
          first = (((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (form ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM188(_), scheme_stx_content (form ) )) ) -> u . pair_val . car ) ) ; 
        else first = form ; 
        if (((Scheme_Type ) (((((long ) (((Scheme_Stx * ) first ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) first ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
          int phase ; 
#         define XfOrM189_COUNT (0+XfOrM188_COUNT)
#         define SETUP_XfOrM189(x) SETUP_XfOrM188(x)
          who = ((Scheme_Stx * ) first ) -> val ; 
          if (scheme_current_thread -> current_local_env )
            phase = scheme_current_thread -> current_local_env -> genv -> phase ; 
          else phase = 0 ; 
          FUNCCALL(SETUP_XfOrM189(_), scheme_stx_module_name (& first , phase , & mod , & nomwho , ((void * ) 0 ) ) ); 
        }
      }
    }
    else {
#     define XfOrM186_COUNT (0+XfOrM184_COUNT)
#     define SETUP_XfOrM186(x) SETUP_XfOrM184(x)
      pform = form ; 
      if (! detail_form )
        form = FUNCCALL(SETUP_XfOrM186(_), scheme_datum_to_syntax (form , scheme_false , scheme_false , 1 , 0 ) ); 
    }
    if (show_src )
      v = FUNCCALL(SETUP_XfOrM184(_), scheme_write_to_string_w_max (pform , & vlen , len ) ); 
    else {
      v = ((void * ) 0 ) ; 
      vlen = 0 ; 
    }
  }
  else {
    form = scheme_false ; 
    v = ((void * ) 0 ) ; 
    vlen = 0 ; 
  }
  if (detail_form ) {
    Scheme_Object * pform ; 
    BLOCK_SETUP((PUSH(pform, 0+XfOrM174_COUNT)));
#   define XfOrM179_COUNT (1+XfOrM174_COUNT)
#   define SETUP_XfOrM179(x) SETUP(XfOrM179_COUNT)
    pform = NULLED_OUT ; 
    if (((Scheme_Type ) (((((long ) (detail_form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (detail_form ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ) {
#     define XfOrM182_COUNT (0+XfOrM179_COUNT)
#     define SETUP_XfOrM182(x) SETUP_XfOrM179(x)
      if (((Scheme_Stx * ) detail_form ) -> srcloc -> line >= 0 )
        p = FUNCCALL(SETUP_XfOrM182(_), make_srcloc_string (((Scheme_Stx * ) detail_form ) -> srcloc , & plen ) ); 
      pform = FUNCCALL(SETUP_XfOrM182(_), scheme_syntax_to_datum (detail_form , 0 , ((void * ) 0 ) ) ); 
      form = detail_form ; 
    }
    else {
#     define XfOrM181_COUNT (0+XfOrM179_COUNT)
#     define SETUP_XfOrM181(x) SETUP_XfOrM179(x)
      pform = detail_form ; 
      form = FUNCCALL(SETUP_XfOrM181(_), scheme_datum_to_syntax (detail_form , ((Scheme_Type ) (((((long ) (form ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (form ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ? form : scheme_false , scheme_false , 1 , 0 ) ); 
    }
    if (show_src )
      dv = FUNCCALL(SETUP_XfOrM179(_), scheme_write_to_string_w_max (pform , & dvlen , len ) ); 
    else {
      dv = ((void * ) 0 ) ; 
      dvlen = 0 ; 
    }
  }
  else {
    dv = ((void * ) 0 ) ; 
    dvlen = 0 ; 
  }
  if (! who ) {
#   define XfOrM177_COUNT (0+XfOrM174_COUNT)
#   define SETUP_XfOrM177(x) SETUP_XfOrM174(x)
    if (where )
      who = FUNCCALL(SETUP_XfOrM177(_), scheme_intern_symbol (where ) ); 
    else who = scheme_false ; 
  }
  if (! nomwho )
    nomwho = who ; 
  if (! where ) {
#   define XfOrM176_COUNT (0+XfOrM174_COUNT)
#   define SETUP_XfOrM176(x) SETUP_XfOrM174(x)
    if ((((who ) ) == (scheme_false ) ) )
      where = "?" ; 
    else where = FUNCCALL(SETUP_XfOrM176(_), scheme_symbol_val (who ) ); 
  }
  if (v ) {
#   define XfOrM175_COUNT (0+XfOrM174_COUNT)
#   define SETUP_XfOrM175(x) SETUP_XfOrM174(x)
    if (dv )
      blen = FUNCCALL(SETUP_XfOrM175(_), scheme_sprintf (buffer , blen , "%t%s: %t at: %t in: %t" , p , plen , where , s , slen , dv , dvlen , v , vlen ) ); 
    else blen = FUNCCALL(SETUP_XfOrM175(_), scheme_sprintf (buffer , blen , "%t%s: %t in: %t" , p , plen , where , s , slen , v , vlen ) ); 
  }
  else blen = FUNCCALL(SETUP_XfOrM174(_), scheme_sprintf (buffer , blen , "%s: %t" , where , s , slen ) ); 
  if ((((form ) ) == (scheme_false ) ) )
    form = extra_sources ; 
  else form = FUNCCALL(SETUP_XfOrM174(_), scheme_make_immutable_pair (form , extra_sources ) ); 
  FUNCCALL(SETUP_XfOrM174(_), scheme_raise_exn (MZEXN_FAIL_SYNTAX , form , "%t" , buffer , blen ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_wrong_syntax (const char * where , Scheme_Object * detail_form , Scheme_Object * form , const char * detail , ... ) {
  char * s ; 
  long slen ; 
  PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(where, 0), PUSH(detail_form, 1), PUSH(s, 2), PUSH(form, 3)));
# define XfOrM194_COUNT (4)
# define SETUP_XfOrM194(x) SETUP(XfOrM194_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  if (! detail ) {
    s = ((void * ) 0 ) ; 
    slen = 0 ; 
  }
  else {
    GC_CAN_IGNORE va_list args ; 
#   define XfOrM195_COUNT (0+XfOrM194_COUNT)
#   define SETUP_XfOrM195(x) SETUP_XfOrM194(x)
    s = prepared_buf ; 
    HIDE_FROM_XFORM (__builtin_va_start (args , detail ) ) ; 
    slen = FUNCCALL(SETUP_XfOrM195(_), sch_vsprintf (s , prepared_buf_len , detail , args ) ); 
    HIDE_FROM_XFORM (__builtin_va_end (args ) ) ; 
    prepared_buf = FUNCCALL(SETUP_XfOrM195(_), init_buf (((void * ) 0 ) , & prepared_buf_len ) ); 
  }
  FUNCCALL_EMPTY(do_wrong_syntax (where , detail_form , form , s , slen , scheme_null ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_wrong_syntax_with_more_sources (const char * where , Scheme_Object * detail_form , Scheme_Object * form , Scheme_Object * extra_sources , const char * detail , ... ) {
  char * s ; 
  long slen ; 
  PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(extra_sources, 0), PUSH(where, 1), PUSH(detail_form, 2), PUSH(s, 3), PUSH(form, 4)));
# define XfOrM197_COUNT (5)
# define SETUP_XfOrM197(x) SETUP(XfOrM197_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  if (! detail ) {
    s = ((void * ) 0 ) ; 
    slen = 0 ; 
  }
  else {
    GC_CAN_IGNORE va_list args ; 
#   define XfOrM198_COUNT (0+XfOrM197_COUNT)
#   define SETUP_XfOrM198(x) SETUP_XfOrM197(x)
    s = prepared_buf ; 
    HIDE_FROM_XFORM (__builtin_va_start (args , detail ) ) ; 
    slen = FUNCCALL(SETUP_XfOrM198(_), sch_vsprintf (s , prepared_buf_len , detail , args ) ); 
    HIDE_FROM_XFORM (__builtin_va_end (args ) ) ; 
    prepared_buf = FUNCCALL(SETUP_XfOrM198(_), init_buf (((void * ) 0 ) , & prepared_buf_len ) ); 
  }
  FUNCCALL_EMPTY(do_wrong_syntax (where , detail_form , form , s , slen , extra_sources ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_wrong_rator (Scheme_Object * rator , int argc , Scheme_Object * * argv ) {
  long len , slen ; 
  int rlen ; 
  char * s , * r ; 
  PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(rator, 0), PUSH(r, 1), PUSH(s, 2), PUSH(argv, 3)));
# define XfOrM200_COUNT (4)
# define SETUP_XfOrM200(x) SETUP(XfOrM200_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  s = NULLED_OUT ; 
  r = NULLED_OUT ; 
  s = FUNCCALL(SETUP_XfOrM200(_), init_buf (& len , ((void * ) 0 ) ) ); 
  r = FUNCCALL_AGAIN(scheme_make_provided_string (rator , 1 , & rlen ) ); 
  if (argc )
    len /= argc ; 
  slen = 0 ; 
  if (argc && (argc < 50 ) && (len >= 3 ) ) {
    int i ; 
#   define XfOrM202_COUNT (0+XfOrM200_COUNT)
#   define SETUP_XfOrM202(x) SETUP_XfOrM200(x)
    (strcpy (s , "; arguments were:" ) ) ; 
    slen = 17 ; 
    for (i = 0 ; i < argc ; i ++ ) {
      char * o ; 
      int olen ; 
      BLOCK_SETUP((PUSH(o, 0+XfOrM202_COUNT)));
#     define XfOrM204_COUNT (1+XfOrM202_COUNT)
#     define SETUP_XfOrM204(x) SETUP(XfOrM204_COUNT)
      o = NULLED_OUT ; 
      o = FUNCCALL(SETUP_XfOrM204(_), error_write_to_string_w_max (argv [i ] , len , & olen ) ); 
      (memcpy (s + slen , " " , 1 ) ) ; 
      (memcpy (s + slen + 1 , o , olen ) ) ; 
      slen += 1 + olen ; 
    }
    s [slen ] = 0 ; 
  }
  else {
#   define XfOrM201_COUNT (0+XfOrM200_COUNT)
#   define SETUP_XfOrM201(x) SETUP_XfOrM200(x)
    slen = - 1 ; 
    if (argc )
      (sprintf (s , " (%d args)" , argc ) ) ; 
    else s = " (no arguments)" ; 
  }
  FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "procedure application: expected procedure, given: %t%t" , r , rlen , s , slen ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_wrong_return_arity (const char * where , int expected , int got , Scheme_Object * * argv , const char * detail , ... ) {
  long slen , vlen , blen ; 
  char * s , * buffer ; 
  char * v ; 
  PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(where, 1), PUSH(buffer, 2), PUSH(argv, 3), PUSH(s, 4)));
# define XfOrM205_COUNT (5)
# define SETUP_XfOrM205(x) SETUP(XfOrM205_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  s = NULLED_OUT ; 
  buffer = NULLED_OUT ; 
  v = NULLED_OUT ; 
  if ((got != 1 ) && ((scheme_current_thread -> ku . multiple . array ) == (scheme_current_thread -> values_buffer ) ) )
    scheme_current_thread -> values_buffer = ((void * ) 0 ) ; 
  scheme_current_thread -> ku . multiple . array = ((void * ) 0 ) ; 
  if (! detail ) {
    s = ((void * ) 0 ) ; 
    slen = 0 ; 
  }
  else {
    GC_CAN_IGNORE va_list args ; 
#   define XfOrM212_COUNT (0+XfOrM205_COUNT)
#   define SETUP_XfOrM212(x) SETUP_XfOrM205(x)
    s = prepared_buf ; 
    HIDE_FROM_XFORM (__builtin_va_start (args , detail ) ) ; 
    slen = FUNCCALL(SETUP_XfOrM212(_), sch_vsprintf (s , prepared_buf_len , detail , args ) ); 
    HIDE_FROM_XFORM (__builtin_va_end (args ) ) ; 
    prepared_buf = FUNCCALL(SETUP_XfOrM212(_), init_buf (((void * ) 0 ) , & prepared_buf_len ) ); 
  }
  buffer = FUNCCALL(SETUP_XfOrM205(_), init_buf (((void * ) 0 ) , & blen ) ); 
  if (! got || ! argv ) {
    v = "" ; 
    vlen = 0 ; 
  }
  else {
    int i ; 
    long len , origlen , maxpos ; 
    Scheme_Object * * array ; 
    BLOCK_SETUP((PUSH(array, 0+XfOrM205_COUNT)));
#   define XfOrM206_COUNT (1+XfOrM205_COUNT)
#   define SETUP_XfOrM206(x) SETUP(XfOrM206_COUNT)
    array = NULLED_OUT ; 
    v = FUNCCALL(SETUP_XfOrM206(_), init_buf (& len , ((void * ) 0 ) ) ); 
    v [0 ] = ':' ; 
    v [1 ] = 0 ; 
    array = ((got == 1 ) ? (Scheme_Object * * ) (void * ) & argv : argv ) ; 
    origlen = len ; 
    len /= got ; 
    maxpos = got ; 
    if (len < 3 ) {
      maxpos = origlen / 4 ; 
      len = 3 ; 
    }
    vlen = 1 ; 
    for (i = 0 ; i < maxpos ; i ++ ) {
      char * o ; 
      int olen ; 
      BLOCK_SETUP((PUSH(o, 0+XfOrM206_COUNT)));
#     define XfOrM209_COUNT (1+XfOrM206_COUNT)
#     define SETUP_XfOrM209(x) SETUP(XfOrM209_COUNT)
      o = NULLED_OUT ; 
      o = FUNCCALL(SETUP_XfOrM209(_), error_write_to_string_w_max (array [i ] , len , & olen ) ); 
      (memcpy (v + vlen , " " , 1 ) ) ; 
      (memcpy (v + vlen + 1 , o , olen ) ) ; 
      vlen += 1 + olen ; 
    }
    if (maxpos != got ) {
#     define XfOrM207_COUNT (0+XfOrM206_COUNT)
#     define SETUP_XfOrM207(x) SETUP_XfOrM206(x)
      (strcpy (v + vlen , " ..." ) ) ; 
      vlen += 4 ; 
    }
    v [vlen ] = 0 ; 
  }
  blen = FUNCCALL(SETUP_XfOrM205(_), scheme_sprintf (buffer , blen , "%s%scontext%s%t%s expected %d value%s," " received %d value%s%t" , where ? where : "" , where ? ": " : "" , s ? " (" : "" , s ? s : "" , slen , s ? ")" : "" , expected , (expected == 1 ) ? "" : "s" , got , (got == 1 ) ? "" : "s" , v , vlen ) ); 
  FUNCCALL(SETUP_XfOrM205(_), scheme_raise_exn (MZEXN_FAIL_CONTRACT_ARITY , "%t" , buffer , blen ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_raise_out_of_memory (const char * where , const char * msg , ... ) {
  char * s ; 
  long slen ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(where, 0), PUSH(s, 1)));
# define XfOrM214_COUNT (2)
# define SETUP_XfOrM214(x) SETUP(XfOrM214_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  if (! msg ) {
    s = "" ; 
    slen = 0 ; 
  }
  else {
    GC_CAN_IGNORE va_list args ; 
#   define XfOrM215_COUNT (0+XfOrM214_COUNT)
#   define SETUP_XfOrM215(x) SETUP_XfOrM214(x)
    s = prepared_buf ; 
    HIDE_FROM_XFORM (__builtin_va_start (args , msg ) ) ; 
    slen = FUNCCALL(SETUP_XfOrM215(_), sch_vsprintf (s , prepared_buf_len , msg , args ) ); 
    HIDE_FROM_XFORM (__builtin_va_end (args ) ) ; 
    prepared_buf = FUNCCALL(SETUP_XfOrM215(_), init_buf (((void * ) 0 ) , & prepared_buf_len ) ); 
  }
  FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_OUT_OF_MEMORY , "%s%sout of memory %t" , where ? where : "" , where ? ": " : "" , s , slen ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_unbound_global (Scheme_Bucket * b ) {
  Scheme_Object * name = (Scheme_Object * ) b -> key ; 
  Scheme_Config * __funcarg30 = NULLED_OUT ; 
  PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(name, 0), PUSH(b, 1)));
# define XfOrM217_COUNT (2)
# define SETUP_XfOrM217(x) SETUP(XfOrM217_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (((Scheme_Bucket_With_Home * ) b ) -> home -> module ) {
    const char * errmsg ; 
    BLOCK_SETUP((PUSH(errmsg, 0+XfOrM217_COUNT)));
#   define XfOrM219_COUNT (1+XfOrM217_COUNT)
#   define SETUP_XfOrM219(x) SETUP(XfOrM219_COUNT)
    errmsg = NULLED_OUT ; 
    if ((! ((((__funcarg30 = FUNCCALL(SETUP_XfOrM219(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg30 , MZCONFIG_ERROR_PRINT_SRCLOC ) )) ) ) == (scheme_false ) ) ) )
      errmsg = "reference to an identifier before its definition: %S in module: %S" ; 
    else errmsg = "reference to an identifier before its definition: %S" ; 
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT_VARIABLE , name , errmsg , name , ((Scheme_Bucket_With_Home * ) b ) -> home -> module -> modname ) ); 
  }
  else {
#   define XfOrM218_COUNT (0+XfOrM217_COUNT)
#   define SETUP_XfOrM218(x) SETUP_XfOrM217(x)
    FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT_VARIABLE , name , "reference to undefined identifier: %S" , name ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
char * scheme_make_provided_string (Scheme_Object * o , int count , int * lenout ) {
  long len ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(lenout, 0), PUSH(o, 1)));
# define XfOrM220_COUNT (2)
# define SETUP_XfOrM220(x) SETUP(XfOrM220_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  len = FUNCCALL(SETUP_XfOrM220(_), get_print_width () ); 
  if (count )
    len /= count ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(error_write_to_string_w_max (o , len , lenout ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_error (int for_user , int argc , Scheme_Object * argv [] ) {
  Scheme_Object * newargs [2 ] ; 
  Scheme_Object * __funcarg33 = NULLED_OUT ; 
  Scheme_Object * __funcarg32 = NULLED_OUT ; 
  Scheme_Object * __funcarg31 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(__funcarg32, 0), PUSHARRAY(newargs, 2, 1), PUSH(argv, 4)));
# define XfOrM221_COUNT (5)
# define SETUP_XfOrM221(x) SETUP(XfOrM221_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  newargs[0] = NULLED_OUT ; 
  newargs[1] = NULLED_OUT ; 
  if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
#   define XfOrM225_COUNT (0+XfOrM221_COUNT)
#   define SETUP_XfOrM225(x) SETUP_XfOrM221(x)
    if (argc < 2 ) {
      const char * s ; 
      int l ; 
      BLOCK_SETUP((PUSH(s, 0+XfOrM225_COUNT)));
#     define XfOrM227_COUNT (1+XfOrM225_COUNT)
#     define SETUP_XfOrM227(x) SETUP(XfOrM227_COUNT)
      s = NULLED_OUT ; 
      s = FUNCCALL(SETUP_XfOrM227(_), scheme_symbol_val (argv [0 ] ) ); 
      l = (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (argv [0 ] ) ) ) -> len ) ; 
      newargs [0 ] = (__funcarg32 = FUNCCALL(SETUP_XfOrM227(_), scheme_make_utf8_string ("error: " ) ), __funcarg33 = FUNCCALL(SETUP_XfOrM227(_), scheme_make_sized_utf8_string ((char * ) s , l ) ), FUNCCALL_AGAIN(scheme_append_char_string (__funcarg32 , __funcarg33 ) )) ; 
      ((((Scheme_Inclhash_Object * ) (newargs [0 ] ) ) -> so . keyex |= 0x1 ) ) ; 
    }
    else {
      char * s , * r ; 
      long l , l2 ; 
      Scheme_Object * port ; 
      BLOCK_SETUP((PUSH(r, 0+XfOrM225_COUNT), PUSH(s, 1+XfOrM225_COUNT), PUSH(port, 2+XfOrM225_COUNT)));
#     define XfOrM226_COUNT (3+XfOrM225_COUNT)
#     define SETUP_XfOrM226(x) SETUP(XfOrM226_COUNT)
      s = NULLED_OUT ; 
      r = NULLED_OUT ; 
      port = NULLED_OUT ; 
      port = FUNCCALL(SETUP_XfOrM226(_), scheme_make_byte_string_output_port () ); 
      if (! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
        FUNCCALL(SETUP_XfOrM226(_), scheme_wrong_type ("error" , "string" , 1 , argc , argv ) ); 
      FUNCCALL(SETUP_XfOrM226(_), scheme_do_format ("error" , port , ((void * ) 0 ) , - 1 , 1 , 2 , argc , argv ) ); 
      s = FUNCCALL_AGAIN(scheme_get_sized_byte_string_output (port , & l ) ); 
      l2 = (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (argv [0 ] ) ) ) -> len ) ; 
      r = ((char * ) FUNCCALL(SETUP_XfOrM226(_), GC_malloc_atomic (sizeof (char ) * (l + l2 + 3 ) ) )) ; 
      (memcpy (r , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (argv [0 ] ) ) ) -> s ) , l2 ) ) ; 
      (memcpy (r + l2 , ": " , 2 ) ) ; 
      (memcpy (r + l2 + 2 , s , l + 1 ) ) ; 
      newargs [0 ] = FUNCCALL(SETUP_XfOrM226(_), scheme_make_immutable_sized_utf8_string (r , l + l2 + 2 ) ); 
    }
  }
  else {
    Scheme_Object * strout ; 
    char * str ; 
    long len , i ; 
    BLOCK_SETUP((PUSH(strout, 0+XfOrM221_COUNT), PUSH(str, 1+XfOrM221_COUNT)));
#   define XfOrM222_COUNT (2+XfOrM221_COUNT)
#   define SETUP_XfOrM222(x) SETUP(XfOrM222_COUNT)
    strout = NULLED_OUT ; 
    str = NULLED_OUT ; 
    if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
      FUNCCALL(SETUP_XfOrM222(_), scheme_wrong_type ("error" , "string or symbol" , 0 , argc , argv ) ); 
    strout = FUNCCALL(SETUP_XfOrM222(_), scheme_make_byte_string_output_port () ); 
    FUNCCALL_AGAIN(scheme_internal_display (argv [0 ] , strout ) ); 
    for (i = 1 ; i < argc ; i ++ ) {
#     define XfOrM224_COUNT (0+XfOrM222_COUNT)
#     define SETUP_XfOrM224(x) SETUP_XfOrM222(x)
      FUNCCALL(SETUP_XfOrM224(_), scheme_write_byte_string (" " , 1 , strout ) ); 
      FUNCCALL(SETUP_XfOrM224(_), scheme_internal_write (argv [i ] , strout ) ); 
    }
    str = FUNCCALL(SETUP_XfOrM222(_), scheme_get_sized_byte_string_output (strout , & len ) ); 
    newargs [0 ] = FUNCCALL(SETUP_XfOrM222(_), scheme_make_immutable_sized_utf8_string (str , len ) ); 
  }
  newargs [1 ] = scheme_parameterization_key ; 
  (__funcarg31 = FUNCCALL(SETUP_XfOrM221(_), scheme_make_struct_instance (exn_table [for_user ? MZEXN_FAIL_USER : MZEXN_FAIL ] . type , 2 , newargs ) ), FUNCCALL_AGAIN(do_raise (__funcarg31 , 1 ) )) ; 
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * error (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_error (0 , argc , argv ) ; 
}
static Scheme_Object * raise_user_error (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_error (1 , argc , argv ) ; 
}
static Scheme_Object * raise_syntax_error (int argc , Scheme_Object * argv [] ) {
  const char * who ; 
  Scheme_Object * str ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(str, 0), PUSH(argv, 1), PUSH(who, 2)));
# define XfOrM230_COUNT (3)
# define SETUP_XfOrM230(x) SETUP(XfOrM230_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  who = NULLED_OUT ; 
  str = NULLED_OUT ; 
  if (! (((argv [0 ] ) ) == (scheme_false ) ) && ! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("raise-syntax-error" , "symbol or #f" , 0 , argc , argv ) ); 
  if (! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("raise-syntax-error" , "string" , 1 , argc , argv ) ); 
  if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
    who = FUNCCALL(SETUP_XfOrM230(_), scheme_symbol_val (argv [0 ] ) ); 
  else who = ((void * ) 0 ) ; 
  str = argv [1 ] ; 
  if ((! (((Scheme_Inclhash_Object * ) (str ) ) -> so . keyex & 0x1 ) ) ) {
#   define XfOrM231_COUNT (0+XfOrM230_COUNT)
#   define SETUP_XfOrM231(x) SETUP_XfOrM230(x)
    str = FUNCCALL(SETUP_XfOrM231(_), scheme_make_immutable_sized_char_string ((((Scheme_Simple_Object * ) (str ) ) -> u . char_str_val . string_val ) , (((Scheme_Simple_Object * ) (str ) ) -> u . char_str_val . tag_val ) , 1 ) ); 
  }
  FUNCCALL_EMPTY(scheme_wrong_syntax (who , (argc > 3 ) ? argv [3 ] : ((void * ) 0 ) , (argc > 2 ) ? argv [2 ] : ((void * ) 0 ) , "%T" , str ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * raise_type_error (int argc , Scheme_Object * argv [] ) {
  char * __funcarg35 = NULLED_OUT ; 
  char * __funcarg34 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM232_COUNT (1)
# define SETUP_XfOrM232(x) SETUP(XfOrM232_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("raise-type-error" , "symbol" , 0 , argc , argv ) ); 
  if (! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("raise-type-error" , "string" , 1 , argc , argv ) ); 
  if (argc == 3 ) {
    Scheme_Object * v , * s ; 
    BLOCK_SETUP((PUSH(v, 0+XfOrM232_COUNT), PUSH(s, 1+XfOrM232_COUNT)));
#   define XfOrM236_COUNT (2+XfOrM232_COUNT)
#   define SETUP_XfOrM236(x) SETUP(XfOrM236_COUNT)
    v = NULLED_OUT ; 
    s = NULLED_OUT ; 
    v = argv [2 ] ; 
    s = FUNCCALL(SETUP_XfOrM236(_), scheme_char_string_to_byte_string (argv [1 ] ) ); 
    (__funcarg35 = FUNCCALL(SETUP_XfOrM236(_), scheme_symbol_val (argv [0 ] ) ), FUNCCALL_AGAIN(scheme_wrong_type (__funcarg35 , (((Scheme_Simple_Object * ) (s ) ) -> u . byte_str_val . string_val ) , - 1 , 0 , & v ) )) ; 
  }
  else {
    Scheme_Object * * args , * s ; 
    int i ; 
    BLOCK_SETUP((PUSH(args, 0+XfOrM232_COUNT), PUSH(s, 1+XfOrM232_COUNT)));
#   define XfOrM233_COUNT (2+XfOrM232_COUNT)
#   define SETUP_XfOrM233(x) SETUP(XfOrM233_COUNT)
    args = NULLED_OUT ; 
    s = NULLED_OUT ; 
    if (! ((((long ) (argv [2 ] ) ) & 0x1 ) && ((((long ) (argv [2 ] ) ) >> 1 ) >= 0 ) ) && ! (((Scheme_Type ) (((((long ) (argv [2 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [2 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) && ((& ((Scheme_Bignum * ) argv [2 ] ) -> iso ) -> so . keyex & 0x1 ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("raise-type-error" , "exact non-negative integer" , 2 , argc , argv ) ); 
    if (((((long ) (argv [2 ] ) ) & 0x1 ) && ((((long ) (argv [2 ] ) ) >> 1 ) >= argc - 3 ) ) || ((Scheme_Type ) (((((long ) (argv [2 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [2 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "raise-type-error: position index is %V, " "but only %d arguments provided" , argv [2 ] , argc - 3 ) ); 
    args = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM233(_), GC_malloc (sizeof (Scheme_Object * ) * (argc - 3 ) ) )) ; 
    for (i = 3 ; i < argc ; i ++ ) {
      args [i - 3 ] = argv [i ] ; 
    }
    s = FUNCCALL(SETUP_XfOrM233(_), scheme_char_string_to_byte_string (argv [1 ] ) ); 
    (__funcarg34 = FUNCCALL(SETUP_XfOrM233(_), scheme_symbol_val (argv [0 ] ) ), FUNCCALL_EMPTY(scheme_wrong_type (__funcarg34 , (((Scheme_Simple_Object * ) (s ) ) -> u . byte_str_val . string_val ) , (((long ) (argv [2 ] ) ) >> 1 ) , argc - 3 , args ) )) ; 
  }
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * raise_mismatch_error (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * s ; 
  char * __funcarg36 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(s, 1)));
# define XfOrM237_COUNT (2)
# define SETUP_XfOrM237(x) SETUP(XfOrM237_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("raise-mismatch-error" , "symbol" , 0 , argc , argv ) ); 
  if (! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("raise-mismatch-error" , "string" , 1 , argc , argv ) ); 
  s = FUNCCALL(SETUP_XfOrM237(_), scheme_char_string_to_byte_string (argv [1 ] ) ); 
  (__funcarg36 = FUNCCALL(SETUP_XfOrM237(_), scheme_symbol_val (argv [0 ] ) ), FUNCCALL_AGAIN(scheme_arg_mismatch (__funcarg36 , (((Scheme_Simple_Object * ) (s ) ) -> u . byte_str_val . string_val ) , argv [2 ] ) )) ; 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int is_arity_at_least (Scheme_Object * v ) {
  /* No conversion */
  return ((((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) && scheme_is_struct_instance (scheme_arity_at_least , v ) && scheme_nonneg_exact_p (((Scheme_Structure * ) v ) -> slots [0 ] ) ) ; 
}
static int is_arity_list (Scheme_Object * l ) {
  int c ; 
  Scheme_Object * a ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(a, 0), PUSH(l, 1)));
# define XfOrM239_COUNT (2)
# define SETUP_XfOrM239(x) SETUP(XfOrM239_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a = NULLED_OUT ; 
  c = FUNCCALL(SETUP_XfOrM239(_), scheme_proper_list_length (l ) ); 
  if (c < 0 )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  while (! ((l ) == (scheme_null ) ) ) {
#   define XfOrM241_COUNT (0+XfOrM239_COUNT)
#   define SETUP_XfOrM241(x) SETUP_XfOrM239(x)
    a = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
    if (! FUNCCALL(SETUP_XfOrM241(_), scheme_nonneg_exact_p (a ) )&& ! FUNCCALL(SETUP_XfOrM241(_), scheme_nonneg_exact_p (a ) ))
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
  }
  RET_VALUE_START (1 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * raise_arity_error (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * * args ; 
  const char * name ; 
  int minc , maxc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(name, 0), PUSH(args, 1), PUSH(argv, 2)));
# define XfOrM242_COUNT (3)
# define SETUP_XfOrM242(x) SETUP(XfOrM242_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  args = NULLED_OUT ; 
  name = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) && ! (! (((long ) (argv [0 ] ) ) & 0x1 ) && ((((argv [0 ] ) -> type ) >= scheme_prim_type ) && (((argv [0 ] ) -> type ) <= scheme_native_closure_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("raise-arity-error" , "symbol or procedure" , 0 , argc , argv ) ); 
  if (! FUNCCALL(SETUP_XfOrM242(_), scheme_nonneg_exact_p (argv [1 ] ) )&& ! FUNCCALL(SETUP_XfOrM242(_), is_arity_at_least (argv [1 ] ) )&& ! FUNCCALL(SETUP_XfOrM242(_), is_arity_list (argv [1 ] ) ))
    FUNCCALL_EMPTY(scheme_wrong_type ("raise-mismatch-error" , "arity (integer, arity-at-least, or list)" , 1 , argc , argv ) ); 
  args = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM242(_), GC_malloc (sizeof (Scheme_Object * ) * (argc - 2 ) ) )) ; 
  (memcpy (args , argv + 2 , sizeof (Scheme_Object * ) * (argc - 2 ) ) ) ; 
  if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
    name = FUNCCALL(SETUP_XfOrM242(_), scheme_symbol_val (argv [0 ] ) ); 
  else {
    int len ; 
#   define XfOrM248_COUNT (0+XfOrM242_COUNT)
#   define SETUP_XfOrM248(x) SETUP_XfOrM242(x)
    name = FUNCCALL(SETUP_XfOrM248(_), scheme_get_proc_name (argv [0 ] , & len , 1 ) ); 
  }
  if ((((long ) (argv [1 ] ) ) & 0x1 ) ) {
    minc = maxc = (((long ) (argv [1 ] ) ) >> 1 ) ; 
  }
  else if (FUNCCALL(SETUP_XfOrM242(_), is_arity_at_least (argv [1 ] ) )) {
    Scheme_Object * v ; 
    v = NULLED_OUT ; 
    v = ((Scheme_Structure * ) argv [1 ] ) -> slots [0 ] ; 
    if ((((long ) (v ) ) & 0x1 ) ) {
      minc = (((long ) (v ) ) >> 1 ) ; 
      maxc = - 1 ; 
    }
    else {
      minc = - 2 ; 
      maxc = 0 ; 
    }
  }
  else {
    minc = - 2 ; 
    maxc = 0 ; 
  }
  FUNCCALL_EMPTY(scheme_wrong_count_m (name , minc , maxc , argc - 2 , args , 0 ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * good_print_width (int c , Scheme_Object * * argv ) {
  /* No conversion */
  int ok ; 
  ok = ((((long ) (argv [0 ] ) ) & 0x1 ) ? ((((long ) (argv [0 ] ) ) >> 1 ) > 3 ) : (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ? ((& ((Scheme_Bignum * ) argv [0 ] ) -> iso ) -> so . keyex & 0x1 ) : 0 ) ) ; 
  return ok ? scheme_true : scheme_false ; 
}
static Scheme_Object * error_print_width (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("error-print-width" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_ERROR_PRINT_WIDTH ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , good_print_width , "integer greater than three" , 0 ) ; 
}
static Scheme_Object * good_print_context_length (int c , Scheme_Object * * argv ) {
  /* No conversion */
  int ok ; 
  ok = ((((long ) (argv [0 ] ) ) & 0x1 ) ? ((((long ) (argv [0 ] ) ) >> 1 ) >= 0 ) : (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ? ((& ((Scheme_Bignum * ) argv [0 ] ) -> iso ) -> so . keyex & 0x1 ) : 0 ) ) ; 
  return ok ? scheme_true : scheme_false ; 
}
static Scheme_Object * error_print_context_length (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("error-print-context-length" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_ERROR_PRINT_CONTEXT_LENGTH ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , good_print_context_length , "non-negative integer" , 0 ) ; 
}
static Scheme_Object * error_print_srcloc (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("error-print-source-location" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_ERROR_PRINT_SRCLOC ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ; 
}
static Scheme_Object * def_error_display_proc (int argc , Scheme_Object * argv [] ) {
  Scheme_Config * config ; 
  Scheme_Object * port , * s ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(9);
  BLOCK_SETUP_TOP((PUSH(port, 0), PUSH(config, 1), PUSH(argv, 2), PUSH(s, 3)));
# define XfOrM254_COUNT (4)
# define SETUP_XfOrM254(x) SETUP(XfOrM254_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  config = NULLED_OUT ; 
  port = NULLED_OUT ; 
  s = NULLED_OUT ; 
  config = FUNCCALL(SETUP_XfOrM254(_), scheme_current_config () ); 
  port = FUNCCALL_AGAIN(scheme_get_param (config , MZCONFIG_ERROR_PORT ) ); 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("default-error-display-handler" , "string" , 0 , argc , argv ) ); 
  s = FUNCCALL(SETUP_XfOrM254(_), scheme_char_string_to_byte_string (argv [0 ] ) ); 
  FUNCCALL_AGAIN(scheme_write_byte_string ((((Scheme_Simple_Object * ) (s ) ) -> u . byte_str_val . string_val ) , (((Scheme_Simple_Object * ) (s ) ) -> u . byte_str_val . tag_val ) , port ) ); 
  FUNCCALL_AGAIN(scheme_write_byte_string ("\n" , 1 , port ) ); 
  if ((((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) && (scheme_is_struct_instance (exn_table [MZEXN ] . type , argv [1 ] ) ) && ! (scheme_is_struct_instance (exn_table [MZEXN_FAIL_USER ] . type , argv [1 ] ) ) ) {
    Scheme_Object * l , * w ; 
    int print_width = 1024 , max_cnt = 16 ; 
    BLOCK_SETUP((PUSH(l, 0+XfOrM254_COUNT), PUSH(w, 1+XfOrM254_COUNT)));
#   define XfOrM255_COUNT (2+XfOrM254_COUNT)
#   define SETUP_XfOrM255(x) SETUP(XfOrM255_COUNT)
    l = NULLED_OUT ; 
    w = NULLED_OUT ; 
    w = FUNCCALL(SETUP_XfOrM255(_), scheme_get_param (config , MZCONFIG_ERROR_PRINT_CONTEXT_LENGTH ) ); 
    if ((((long ) (w ) ) & 0x1 ) )
      max_cnt = (((long ) (w ) ) >> 1 ) ; 
    else max_cnt = 0x7FFFFFFF ; 
    if (max_cnt ) {
      int orig_max_cnt = max_cnt ; 
#     define XfOrM256_COUNT (0+XfOrM255_COUNT)
#     define SETUP_XfOrM256(x) SETUP_XfOrM255(x)
      w = FUNCCALL(SETUP_XfOrM256(_), scheme_get_param (config , MZCONFIG_ERROR_PRINT_WIDTH ) ); 
      if ((((long ) (w ) ) & 0x1 ) )
        print_width = (((long ) (w ) ) >> 1 ) ; 
      else print_width = 0x7FFFFFFF ; 
      l = FUNCCALL(SETUP_XfOrM256(_), scheme_get_stack_trace (((Scheme_Structure * ) argv [1 ] ) -> slots [1 ] ) ); 
      while (! ((l ) == (scheme_null ) ) ) {
#       define XfOrM267_COUNT (0+XfOrM256_COUNT)
#       define SETUP_XfOrM267(x) SETUP_XfOrM256(x)
        if (! max_cnt ) {
#         define XfOrM275_COUNT (0+XfOrM267_COUNT)
#         define SETUP_XfOrM275(x) SETUP_XfOrM267(x)
          FUNCCALL(SETUP_XfOrM275(_), scheme_write_byte_string ("...\n" , 4 , port ) ); 
          break ; 
        }
        else {
          Scheme_Object * name , * loc ; 
          BLOCK_SETUP((PUSH(loc, 0+XfOrM267_COUNT), PUSH(name, 1+XfOrM267_COUNT)));
#         define XfOrM268_COUNT (2+XfOrM267_COUNT)
#         define SETUP_XfOrM268(x) SETUP(XfOrM268_COUNT)
          name = NULLED_OUT ; 
          loc = NULLED_OUT ; 
          if (max_cnt == orig_max_cnt ) {
#           define XfOrM274_COUNT (0+XfOrM268_COUNT)
#           define SETUP_XfOrM274(x) SETUP_XfOrM268(x)
            FUNCCALL(SETUP_XfOrM274(_), scheme_write_byte_string ("\n === context ===\n" , 18 , port ) ); 
          }
          name = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
          loc = (((Scheme_Simple_Object * ) (name ) ) -> u . pair_val . cdr ) ; 
          name = (((Scheme_Simple_Object * ) (name ) ) -> u . pair_val . car ) ; 
          if ((! (((loc ) ) == (scheme_false ) ) ) ) {
            Scheme_Structure * sloc = (Scheme_Structure * ) loc ; 
            BLOCK_SETUP((PUSH(sloc, 0+XfOrM268_COUNT)));
#           define XfOrM270_COUNT (1+XfOrM268_COUNT)
#           define SETUP_XfOrM270(x) SETUP(XfOrM270_COUNT)
            FUNCCALL(SETUP_XfOrM270(_), scheme_display_w_max (sloc -> slots [0 ] , port , print_width ) ); 
            if ((! (((sloc -> slots [1 ] ) ) == (scheme_false ) ) ) ) {
#             define XfOrM273_COUNT (0+XfOrM270_COUNT)
#             define SETUP_XfOrM273(x) SETUP_XfOrM270(x)
              FUNCCALL(SETUP_XfOrM273(_), scheme_write_byte_string (":" , 1 , port ) ); 
              FUNCCALL(SETUP_XfOrM273(_), scheme_display_w_max (sloc -> slots [1 ] , port , print_width ) ); 
              FUNCCALL_AGAIN(scheme_write_byte_string (":" , 1 , port ) ); 
              FUNCCALL_AGAIN(scheme_display_w_max (sloc -> slots [2 ] , port , print_width ) ); 
            }
            else {
#             define XfOrM272_COUNT (0+XfOrM270_COUNT)
#             define SETUP_XfOrM272(x) SETUP_XfOrM270(x)
              FUNCCALL(SETUP_XfOrM272(_), scheme_write_byte_string ("::" , 2 , port ) ); 
              FUNCCALL(SETUP_XfOrM272(_), scheme_display_w_max (sloc -> slots [3 ] , port , print_width ) ); 
            }
            if ((! (((name ) ) == (scheme_false ) ) ) ) {
#             define XfOrM271_COUNT (0+XfOrM270_COUNT)
#             define SETUP_XfOrM271(x) SETUP_XfOrM270(x)
              FUNCCALL(SETUP_XfOrM271(_), scheme_write_byte_string (": " , 2 , port ) ); 
            }
          }
          if ((! (((name ) ) == (scheme_false ) ) ) ) {
#           define XfOrM269_COUNT (0+XfOrM268_COUNT)
#           define SETUP_XfOrM269(x) SETUP_XfOrM268(x)
            FUNCCALL(SETUP_XfOrM269(_), scheme_display_w_max (name , port , print_width ) ); 
          }
          FUNCCALL(SETUP_XfOrM268(_), scheme_write_byte_string ("\n" , 1 , port ) ); 
          l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
          -- max_cnt ; 
        }
      }
      if (max_cnt != orig_max_cnt ) {
#       define XfOrM257_COUNT (0+XfOrM256_COUNT)
#       define SETUP_XfOrM257(x) SETUP_XfOrM256(x)
        FUNCCALL_EMPTY(scheme_write_byte_string ("\n" , 1 , port ) ); 
      }
    }
  }
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * emergency_error_display_proc (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * s ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(s, 0)));
# define XfOrM276_COUNT (1)
# define SETUP_XfOrM276(x) SETUP(XfOrM276_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
  s = FUNCCALL(SETUP_XfOrM276(_), scheme_char_string_to_byte_string (argv [0 ] ) ); 
  FUNCCALL_EMPTY(scheme_console_output ((((Scheme_Simple_Object * ) (s ) ) -> u . byte_str_val . string_val ) , (((Scheme_Simple_Object * ) (s ) ) -> u . byte_str_val . tag_val ) ) ); 
  FUNCCALL_EMPTY(scheme_console_output ("\n" , 1 ) ); 
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * def_error_value_string_proc (int argc , Scheme_Object * argv [] ) {
  long origl , len , l ; 
  char * s ; 
  Scheme_Object * pph ; 
  Scheme_Config * __funcarg37 = NULLED_OUT ; 
  PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(pph, 0), PUSH(s, 1), PUSH(argv, 2)));
# define XfOrM277_COUNT (3)
# define SETUP_XfOrM277(x) SETUP(XfOrM277_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  s = NULLED_OUT ; 
  pph = NULLED_OUT ; 
  if (! (((long ) (argv [1 ] ) ) & 0x1 ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("default-error-value->string-handler" , "number" , 1 , argc , argv ) ); 
  origl = len = (((long ) (argv [1 ] ) ) >> 1 ) ; 
  pph = (__funcarg37 = FUNCCALL(SETUP_XfOrM277(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg37 , MZCONFIG_PORT_PRINT_HANDLER ) )) ; 
  if (((pph ) == (scheme_default_global_print_handler ) ) ) {
#   define XfOrM282_COUNT (0+XfOrM277_COUNT)
#   define SETUP_XfOrM282(x) SETUP_XfOrM277(x)
    if (len < 3 )
      len = 3 ; 
    s = FUNCCALL(SETUP_XfOrM282(_), scheme_print_to_string_w_max (argv [0 ] , & l , len ) ); 
    if ((origl < 3 ) && (l > origl ) )
      l = origl ; 
  }
  else {
    Scheme_Object * a [2 ] ; 
    BLOCK_SETUP((PUSHARRAY(a, 2, 0+XfOrM277_COUNT)));
#   define XfOrM278_COUNT (3+XfOrM277_COUNT)
#   define SETUP_XfOrM278(x) SETUP(XfOrM278_COUNT)
    a[0] = NULLED_OUT ; 
    a[1] = NULLED_OUT ; 
    a [0 ] = argv [0 ] ; 
    a [1 ] = FUNCCALL(SETUP_XfOrM278(_), scheme_make_byte_string_output_port () ); 
    FUNCCALL(SETUP_XfOrM278(_), scheme_do_eval (pph , 2 , a , 1 ) ); 
    s = FUNCCALL_AGAIN(scheme_get_sized_byte_string_output (a [1 ] , & l ) ); 
    if (l > origl ) {
      l = origl ; 
      if (origl >= 1 ) {
        s [origl - 1 ] = '.' ; 
        if (origl >= 2 ) {
          s [origl - 2 ] = '.' ; 
          if (origl >= 3 )
            s [origl - 3 ] = '.' ; 
        }
      }
    }
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_utf8_string (s , l ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * def_error_escape_proc (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * prompt ; 
  Scheme_Thread * p = scheme_current_thread ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(p, 0), PUSH(prompt, 1)));
# define XfOrM283_COUNT (2)
# define SETUP_XfOrM283(x) SETUP(XfOrM283_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  prompt = NULLED_OUT ; 
  prompt = FUNCCALL(SETUP_XfOrM283(_), scheme_extract_one_cc_mark (((void * ) 0 ) , (((Scheme_Small_Object * ) (scheme_default_prompt_tag ) ) -> u . ptr_val ) ) ); 
  if (prompt ) {
    p -> cjs . jumping_to_continuation = prompt ; 
    p -> cjs . num_vals = 1 ; 
    p -> cjs . val = scheme_void_proc ; 
  }
  (((long * ) (void * ) ((* (scheme_current_thread -> error_buf ) ) . gcvs ) ) [1 ] = (* (scheme_current_thread -> error_buf ) ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* (scheme_current_thread -> error_buf ) ) . gcvs , scheme_jit_longjmp ((* (scheme_current_thread -> error_buf ) ) . jb , 1 ) ) ; 
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * error_display_handler (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("error-display-handler" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_ERROR_DISPLAY_HANDLER ) ) << 1 ) | 0x1 ) ) , argc , argv , 2 , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ; 
}
static Scheme_Object * error_value_string_handler (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("error-value->string-handler" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_ERROR_PRINT_VALUE_HANDLER ) ) << 1 ) | 0x1 ) ) , argc , argv , 2 , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ; 
}
static Scheme_Object * error_escape_handler (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("error-escape-handler" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_ERROR_ESCAPE_HANDLER ) ) << 1 ) | 0x1 ) ) , argc , argv , 0 , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ; 
}
static Scheme_Object * exit_handler (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("exit-handler" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_EXIT_HANDLER ) ) << 1 ) | 0x1 ) ) , argc , argv , 1 , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ; 
}
int scheme_exiting_result ; 
static Scheme_Object * def_exit_handler_proc (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  long status ; 
  if ((((long ) (argv [0 ] ) ) & 0x1 ) ) {
    status = (((long ) (argv [0 ] ) ) >> 1 ) ; 
    if (status < 1 || status > 255 )
      status = 0 ; 
  }
  else status = 0 ; 
  scheme_exiting_result = status ; 
  if (scheme_exit )
    scheme_exit (status ) ; 
  else exit (status ) ; 
  return scheme_void ; 
}
Scheme_Object * scheme_do_exit (int argc , Scheme_Object * argv [] ) {
  long status ; 
  Scheme_Object * handler ; 
  Scheme_Config * __funcarg38 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(handler, 0), PUSH(argv, 1)));
# define XfOrM291_COUNT (2)
# define SETUP_XfOrM291(x) SETUP(XfOrM291_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  handler = NULLED_OUT ; 
  if (argc == 1 ) {
    if ((((long ) (argv [0 ] ) ) & 0x1 ) )
      status = (((long ) (argv [0 ] ) ) >> 1 ) ; 
    else status = 0 ; 
  }
  else status = 0 ; 
  handler = (__funcarg38 = FUNCCALL(SETUP_XfOrM291(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg38 , MZCONFIG_EXIT_HANDLER ) )) ; 
  if (handler ) {
    Scheme_Object * p [1 ] ; 
    BLOCK_SETUP((PUSHARRAY(p, 1, 0+XfOrM291_COUNT)));
#   define XfOrM292_COUNT (3+XfOrM291_COUNT)
#   define SETUP_XfOrM292(x) SETUP(XfOrM292_COUNT)
    p[0] = NULLED_OUT ; 
    p [0 ] = argc ? argv [0 ] : ((Scheme_Object * ) (void * ) (long ) ((((long ) (status ) ) << 1 ) | 0x1 ) ) ; 
    FUNCCALL(SETUP_XfOrM292(_), scheme_apply_multi (handler , 1 , p ) ); 
  }
  else if (scheme_exit )
    FUNCCALL_EMPTY(scheme_exit (status ) ); 
  else FUNCCALL_EMPTY(exit (status ) ); 
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_immediate_exit (int status ) {
  /* No conversion */
  exit (status ) ; 
}
void scheme_raise_exn (int id , ... ) {
  GC_CAN_IGNORE va_list args ; 
  long alen ; 
  char * msg ; 
  int i , c ; 
  Scheme_Object * eargs [3 ] ; 
  char * buffer ; 
  Scheme_Object * __funcarg39 = NULLED_OUT ; 
  PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(buffer, 0), PUSHARRAY(eargs, 3, 1)));
# define XfOrM295_COUNT (4)
# define SETUP_XfOrM295(x) SETUP(XfOrM295_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  msg = NULLED_OUT ; 
  eargs[0] = NULLED_OUT ; 
  eargs[1] = NULLED_OUT ; 
  eargs[2] = NULLED_OUT ; 
  buffer = NULLED_OUT ; 
  buffer = prepared_buf ; 
  HIDE_FROM_XFORM (__builtin_va_start (args , id ) ) ; 
  if (id == MZEXN_OTHER )
    c = 3 ; 
  else c = exn_table [id ] . args ; 
  for (i = 2 ; i < c ; i ++ ) {
    eargs [i ] = HIDE_FROM_XFORM (__builtin_va_arg (args , Scheme_Object * ) ) ; 
  }
  msg = HIDE_FROM_XFORM (__builtin_va_arg (args , char * ) ) ; 
  alen = FUNCCALL(SETUP_XfOrM295(_), sch_vsprintf (buffer , prepared_buf_len , msg , args ) ); 
  HIDE_FROM_XFORM (__builtin_va_end (args ) ) ; 
  prepared_buf = FUNCCALL(SETUP_XfOrM295(_), init_buf (((void * ) 0 ) , & prepared_buf_len ) ); 
  eargs [0 ] = FUNCCALL(SETUP_XfOrM295(_), scheme_make_immutable_sized_utf8_string (buffer , alen ) ); 
  eargs [1 ] = scheme_parameterization_key ; 
  (__funcarg39 = FUNCCALL(SETUP_XfOrM295(_), scheme_make_struct_instance (exn_table [id ] . type , c , eargs ) ), FUNCCALL_AGAIN(do_raise (__funcarg39 , 1 ) )) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * def_exn_handler (int argc , Scheme_Object * argv [] ) {
  char * s ; 
  int len = - 1 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(s, 1)));
# define XfOrM298_COUNT (2)
# define SETUP_XfOrM298(x) SETUP(XfOrM298_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  s = NULLED_OUT ; 
  if ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) && (scheme_is_struct_instance (exn_table [MZEXN ] . type , argv [0 ] ) ) ) {
    Scheme_Object * str = ((Scheme_Structure * ) argv [0 ] ) -> slots [0 ] ; 
    BLOCK_SETUP((PUSH(str, 0+XfOrM298_COUNT)));
#   define XfOrM300_COUNT (1+XfOrM298_COUNT)
#   define SETUP_XfOrM300(x) SETUP(XfOrM300_COUNT)
    if (((Scheme_Type ) (((((long ) (str ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (str ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) ) {
#     define XfOrM301_COUNT (0+XfOrM300_COUNT)
#     define SETUP_XfOrM301(x) SETUP_XfOrM300(x)
      str = FUNCCALL(SETUP_XfOrM301(_), scheme_char_string_to_byte_string (str ) ); 
      s = (((Scheme_Simple_Object * ) (str ) ) -> u . byte_str_val . string_val ) ; 
      len = (((Scheme_Simple_Object * ) (str ) ) -> u . byte_str_val . tag_val ) ; 
    }
    else s = "exception raised [message field is not a string]" ; 
  }
  else {
    char * v ; 
    BLOCK_SETUP((PUSH(v, 0+XfOrM298_COUNT)));
#   define XfOrM299_COUNT (1+XfOrM298_COUNT)
#   define SETUP_XfOrM299(x) SETUP(XfOrM299_COUNT)
    v = NULLED_OUT ; 
    v = FUNCCALL(SETUP_XfOrM299(_), scheme_make_provided_string (argv [0 ] , 1 , & len ) ); 
    s = FUNCCALL_AGAIN(GC_malloc_atomic (len + 21 ) ); 
    (memcpy (s , "uncaught exception: " , 20 ) ) ; 
    (memcpy (s + 20 , v , len + 1 ) ) ; 
    len += 20 ; 
  }
  FUNCCALL_EMPTY(call_error (s , len , argv [0 ] ) ); 
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * init_exn_handler (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("uncaught-exception-handler" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_INIT_EXN_HANDLER ) ) << 1 ) | 0x1 ) ) , argc , argv , 1 , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ; 
}
static Scheme_Object * nested_exn_handler (void * old_exn , int argc , Scheme_Object * argv [] ) {
  Scheme_Object * arg = argv [0 ] , * orig_arg = (((Scheme_Simple_Object * ) ((Scheme_Object * ) old_exn ) ) -> u . pair_val . cdr ) ; 
  long len , mlen = - 1 , orig_mlen = - 1 , blen ; 
  char * buffer , * msg , * orig_msg , * raisetype , * orig_raisetype , * who , * sep ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(11);
  BLOCK_SETUP_TOP((PUSH(orig_msg, 0), PUSH(arg, 1), PUSH(msg, 2), PUSH(who, 3), PUSH(buffer, 4), PUSH(orig_raisetype, 5), PUSH(sep, 6), PUSH(old_exn, 7), PUSH(raisetype, 8), PUSH(orig_arg, 9)));
# define XfOrM303_COUNT (10)
# define SETUP_XfOrM303(x) SETUP(XfOrM303_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  buffer = NULLED_OUT ; 
  msg = NULLED_OUT ; 
  orig_msg = NULLED_OUT ; 
  raisetype = NULLED_OUT ; 
  orig_raisetype = NULLED_OUT ; 
  who = NULLED_OUT ; 
  sep = NULLED_OUT ; 
  buffer = FUNCCALL(SETUP_XfOrM303(_), init_buf (& len , & blen ) ); 
  if (((((((Scheme_Simple_Object * ) ((Scheme_Object * ) old_exn ) ) -> u . pair_val . car ) ) ) == (scheme_false ) ) ) {
    raisetype = "" ; 
    sep = "" ; 
    who = "handler for uncaught exceptions" ; 
    msg = "did not escape" ; 
  }
  else {
#   define XfOrM306_COUNT (0+XfOrM303_COUNT)
#   define SETUP_XfOrM306(x) SETUP_XfOrM303(x)
    who = (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((Scheme_Object * ) old_exn ) ) -> u . pair_val . car ) ) ) -> u . byte_str_val . string_val ) ; 
    sep = " by " ; 
    if ((((Scheme_Type ) (((((long ) (arg ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (arg ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (arg ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (arg ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) && (scheme_is_struct_instance (exn_table [MZEXN ] . type , arg ) ) ) {
      Scheme_Object * str = ((Scheme_Structure * ) arg ) -> slots [0 ] ; 
      BLOCK_SETUP((PUSH(str, 0+XfOrM306_COUNT)));
#     define XfOrM308_COUNT (1+XfOrM306_COUNT)
#     define SETUP_XfOrM308(x) SETUP(XfOrM308_COUNT)
      raisetype = "exception raised" ; 
      str = FUNCCALL(SETUP_XfOrM308(_), scheme_char_string_to_byte_string (str ) ); 
      msg = (((Scheme_Simple_Object * ) (str ) ) -> u . byte_str_val . string_val ) ; 
      mlen = (((Scheme_Simple_Object * ) (str ) ) -> u . byte_str_val . tag_val ) ; 
    }
    else {
#     define XfOrM307_COUNT (0+XfOrM306_COUNT)
#     define SETUP_XfOrM307(x) SETUP_XfOrM306(x)
      msg = FUNCCALL(SETUP_XfOrM307(_), error_write_to_string_w_max (arg , len , ((void * ) 0 ) ) ); 
      raisetype = "raise called (with non-exception value)" ; 
    }
  }
  if ((((Scheme_Type ) (((((long ) (orig_arg ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (orig_arg ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (orig_arg ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (orig_arg ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) && (scheme_is_struct_instance (exn_table [MZEXN ] . type , orig_arg ) ) ) {
    Scheme_Object * str = ((Scheme_Structure * ) orig_arg ) -> slots [0 ] ; 
    BLOCK_SETUP((PUSH(str, 0+XfOrM303_COUNT)));
#   define XfOrM305_COUNT (1+XfOrM303_COUNT)
#   define SETUP_XfOrM305(x) SETUP(XfOrM305_COUNT)
    orig_raisetype = "exception raised" ; 
    str = FUNCCALL(SETUP_XfOrM305(_), scheme_char_string_to_byte_string (str ) ); 
    orig_msg = (((Scheme_Simple_Object * ) (str ) ) -> u . byte_str_val . string_val ) ; 
    orig_mlen = (((Scheme_Simple_Object * ) (str ) ) -> u . byte_str_val . tag_val ) ; 
  }
  else {
#   define XfOrM304_COUNT (0+XfOrM303_COUNT)
#   define SETUP_XfOrM304(x) SETUP_XfOrM303(x)
    orig_msg = FUNCCALL(SETUP_XfOrM304(_), error_write_to_string_w_max (orig_arg , len , ((void * ) 0 ) ) ); 
    orig_raisetype = "raise called (with non-exception value)" ; 
  }
  blen = FUNCCALL(SETUP_XfOrM303(_), scheme_sprintf (buffer , blen , "%s%s%s: %t; original %s: %t" , raisetype , sep , who , msg , mlen , orig_raisetype , orig_msg , orig_mlen ) ); 
  FUNCCALL_EMPTY(call_error (buffer , blen , scheme_false ) ); 
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_raise (Scheme_Object * arg , int need_debug ) {
  Scheme_Object * v , * p [1 ] , * h , * marks ; 
  Scheme_Cont_Mark_Chain * chain ; 
  Scheme_Cont_Frame_Data cframe , cframe2 ; 
  int got_chain ; 
  Scheme_Config * __funcarg45 = NULLED_OUT ; 
  Scheme_Object * __funcarg44 = NULLED_OUT ; 
  Scheme_Object * __funcarg43 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(10);
  BLOCK_SETUP_TOP((PUSH(marks, 0), PUSH(h, 1), PUSH(cframe.cache, 2), PUSH(cframe2.cache, 3), PUSH(chain, 4), PUSH(v, 5), PUSH(arg, 6), PUSHARRAY(p, 1, 7)));
# define XfOrM310_COUNT (10)
# define SETUP_XfOrM310(x) SETUP(XfOrM310_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  p[0] = NULLED_OUT ; 
  h = NULLED_OUT ; 
  marks = NULLED_OUT ; 
  chain = NULLED_OUT ; 
  cframe.cache = NULLED_OUT ; 
  cframe2.cache = NULLED_OUT ; 
  if (scheme_current_thread -> skip_error ) {
    (((long * ) (void * ) ((* (scheme_current_thread -> error_buf ) ) . gcvs ) ) [1 ] = (* (scheme_current_thread -> error_buf ) ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* (scheme_current_thread -> error_buf ) ) . gcvs , scheme_jit_longjmp ((* (scheme_current_thread -> error_buf ) ) . jb , 1 ) ) ; 
  }
  if (need_debug ) {
#   define XfOrM329_COUNT (0+XfOrM310_COUNT)
#   define SETUP_XfOrM329(x) SETUP_XfOrM310(x)
    marks = FUNCCALL(SETUP_XfOrM329(_), scheme_current_continuation_marks (((void * ) 0 ) ) ); 
    ((Scheme_Structure * ) arg ) -> slots [1 ] = marks ; 
  }
  h = FUNCCALL(SETUP_XfOrM310(_), scheme_extract_one_cc_mark (((void * ) 0 ) , scheme_exn_handler_key ) ); 
  chain = ((void * ) 0 ) ; 
  got_chain = 0 ; 
  while (1 ) {
#   define XfOrM320_COUNT (0+XfOrM310_COUNT)
#   define SETUP_XfOrM320(x) SETUP_XfOrM310(x)
    if (! h ) {
#     define XfOrM328_COUNT (0+XfOrM320_COUNT)
#     define SETUP_XfOrM328(x) SETUP_XfOrM320(x)
      h = (__funcarg45 = FUNCCALL(SETUP_XfOrM328(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg45 , MZCONFIG_INIT_EXN_HANDLER ) )) ; 
      chain = ((void * ) 0 ) ; 
      got_chain = 1 ; 
    }
    v = FUNCCALL(SETUP_XfOrM320(_), scheme_make_byte_string_without_copying ("exception handler" ) ); 
    v = (__funcarg44 = FUNCCALL(SETUP_XfOrM320(_), scheme_make_pair (v , arg ) ), FUNCCALL_AGAIN(scheme_make_closed_prim_w_arity (nested_exn_handler , __funcarg44 , "nested-exception-handler" , 1 , 1 ) )) ; 
    FUNCCALL_AGAIN(scheme_push_continuation_frame (& cframe ) ); 
    FUNCCALL_AGAIN(scheme_set_cont_mark (scheme_exn_handler_key , v ) ); 
    FUNCCALL_AGAIN(scheme_push_break_enable (& cframe2 , 0 , 0 ) ); 
    p [0 ] = arg ; 
    v = FUNCCALL(SETUP_XfOrM320(_), scheme_apply (h , 1 , p ) ); 
    FUNCCALL_AGAIN(scheme_pop_break_enable (& cframe2 , 0 ) ); 
    FUNCCALL_AGAIN(scheme_pop_continuation_frame (& cframe ) ); 
    if (! got_chain ) {
#     define XfOrM325_COUNT (0+XfOrM320_COUNT)
#     define SETUP_XfOrM325(x) SETUP_XfOrM320(x)
      marks = FUNCCALL(SETUP_XfOrM325(_), scheme_all_current_continuation_marks () ); 
      chain = ((Scheme_Cont_Mark_Set * ) marks ) -> chain ; 
      marks = ((void * ) 0 ) ; 
      while (chain -> key != scheme_exn_handler_key ) {
        chain = chain -> next ; 
      }
      got_chain = 1 ; 
    }
    if (chain ) {
      chain = chain -> next ; 
      while (chain && (chain -> key != scheme_exn_handler_key ) ) {
        chain = chain -> next ; 
      }
      if (! chain )
        h = ((void * ) 0 ) ; 
      else h = chain -> val ; 
      arg = v ; 
    }
    else {
#     define XfOrM321_COUNT (0+XfOrM320_COUNT)
#     define SETUP_XfOrM321(x) SETUP_XfOrM320(x)
      p [0 ] = scheme_false ; 
      RET_VALUE_START ((__funcarg43 = FUNCCALL(SETUP_XfOrM321(_), scheme_make_pair (scheme_false , arg ) ), FUNCCALL_AGAIN(nested_exn_handler (__funcarg43 , 1 , p ) )) ) RET_VALUE_END ; 
    }
  }
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * sch_raise (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_raise (argv [0 ] , 0 ) ; 
}
void scheme_raise (Scheme_Object * exn ) {
  /* No conversion */
  do_raise (exn , 0 ) ; 
}
typedef Scheme_Object (* Scheme_Struct_Field_Guard_Proc ) (int argc , Scheme_Object * v ) ; 
static Scheme_Object * exn_field_check (int argc , Scheme_Object * * argv ) {
  Scheme_Object * a [2 ] , * v ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSHARRAY(a, 2, 1), PUSH(argv, 4)));
# define XfOrM333_COUNT (5)
# define SETUP_XfOrM333(x) SETUP(XfOrM333_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  v = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL(SETUP_XfOrM333(_), scheme_wrong_field_type (argv [2 ] , "string" , argv [0 ] ) ); 
  if (! ((argv [1 ] ) == (scheme_parameterization_key ) ) && ! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_cont_mark_set_type ) ) )
    FUNCCALL(SETUP_XfOrM333(_), scheme_wrong_field_type (argv [2 ] , "continuation mark set" , argv [1 ] ) ); 
  a [0 ] = argv [0 ] ; 
  a [1 ] = argv [1 ] ; 
  if (! (((Scheme_Type ) (((((long ) (a [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) && (((Scheme_Inclhash_Object * ) (a [0 ] ) ) -> so . keyex & 0x1 ) ) ) {
#   define XfOrM334_COUNT (0+XfOrM333_COUNT)
#   define SETUP_XfOrM334(x) SETUP_XfOrM333(x)
    v = FUNCCALL(SETUP_XfOrM334(_), scheme_make_immutable_sized_char_string ((((Scheme_Simple_Object * ) (a [0 ] ) ) -> u . char_str_val . string_val ) , (((Scheme_Simple_Object * ) (a [0 ] ) ) -> u . char_str_val . tag_val ) , 1 ) ); 
    a [0 ] = v ; 
  }
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM333(_), scheme_values (2 , a ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * variable_field_check (int argc , Scheme_Object * * argv ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM335_COUNT (1)
# define SETUP_XfOrM335(x) SETUP(XfOrM335_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! ((Scheme_Type ) (((((long ) (argv [2 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [2 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
    FUNCCALL(SETUP_XfOrM335(_), scheme_wrong_field_type (argv [3 ] , "symbol" , argv [2 ] ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_values (3 , argv ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * syntax_field_check (int argc , Scheme_Object * * argv ) {
  Scheme_Object * l , * first = scheme_null , * last = ((void * ) 0 ) , * pr , * a [3 ] ; 
  int all_imm = 1 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(8);
  BLOCK_SETUP_TOP((PUSH(pr, 0), PUSH(first, 1), PUSHARRAY(a, 3, 2), PUSH(argv, 5), PUSH(l, 6), PUSH(last, 7)));
# define XfOrM336_COUNT (8)
# define SETUP_XfOrM336(x) SETUP(XfOrM336_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  l = NULLED_OUT ; 
  pr = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  a[2] = NULLED_OUT ; 
  l = argv [2 ] ; 
  while (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#   define XfOrM338_COUNT (0+XfOrM336_COUNT)
#   define SETUP_XfOrM338(x) SETUP_XfOrM336(x)
    if (! (((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && (((Scheme_Inclhash_Object * ) (l ) ) -> so . keyex & 0x1 ) ) )
      all_imm = 0 ; 
    pr = FUNCCALL(SETUP_XfOrM338(_), scheme_make_immutable_pair ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) , scheme_null ) ); 
    if (last )
      (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = pr ; 
    else first = pr ; 
    last = pr ; 
    if (! ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
      break ; 
    l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
  }
  if (! ((l ) == (scheme_null ) ) )
    FUNCCALL(SETUP_XfOrM336(_), scheme_wrong_field_type (argv [3 ] , "list of syntax objects" , argv [2 ] ) ); 
  a [0 ] = argv [0 ] ; 
  a [1 ] = argv [1 ] ; 
  if (! all_imm )
    a [2 ] = first ; 
  else a [2 ] = argv [2 ] ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM336(_), scheme_values (3 , a ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * read_field_check (int argc , Scheme_Object * * argv ) {
  Scheme_Object * l ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0), PUSH(l, 1)));
# define XfOrM339_COUNT (2)
# define SETUP_XfOrM339(x) SETUP(XfOrM339_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  l = NULLED_OUT ; 
  l = argv [2 ] ; 
  while ((((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) && (((Scheme_Inclhash_Object * ) (l ) ) -> so . keyex & 0x1 ) ) ) {
#   define XfOrM341_COUNT (0+XfOrM339_COUNT)
#   define SETUP_XfOrM341(x) SETUP_XfOrM339(x)
    if (! FUNCCALL(SETUP_XfOrM341(_), scheme_is_location ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ) ))
      break ; 
    l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
  }
  if (! ((l ) == (scheme_null ) ) )
    FUNCCALL(SETUP_XfOrM339(_), scheme_wrong_field_type (argv [3 ] , "immutable list of locations" , argv [2 ] ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_values (3 , argv ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * break_field_check (int argc , Scheme_Object * * argv ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM342_COUNT (1)
# define SETUP_XfOrM342(x) SETUP(XfOrM342_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! ((Scheme_Type ) (((((long ) (argv [2 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [2 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_escaping_cont_type ) ) )
    FUNCCALL(SETUP_XfOrM342(_), scheme_wrong_field_type (argv [3 ] , "escape continuation" , argv [2 ] ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_values (3 , argv ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * extract_syntax_locations (int argc , Scheme_Object * * argv ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM343_COUNT (1)
# define SETUP_XfOrM343(x) SETUP(XfOrM343_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((scheme_is_struct_instance (exn_table [MZEXN_FAIL_SYNTAX ] . type , argv [0 ] ) ) ) {
    Scheme_Object * stxs , * stx , * first = scheme_null , * last = ((void * ) 0 ) , * loco , * p ; 
    Scheme_Stx_Srcloc * loc ; 
    BLOCK_SETUP((PUSH(first, 0+XfOrM343_COUNT), PUSH(loco, 1+XfOrM343_COUNT), PUSH(last, 2+XfOrM343_COUNT), PUSH(stxs, 3+XfOrM343_COUNT), PUSH(stx, 4+XfOrM343_COUNT), PUSH(loc, 5+XfOrM343_COUNT), PUSH(p, 6+XfOrM343_COUNT)));
#   define XfOrM344_COUNT (7+XfOrM343_COUNT)
#   define SETUP_XfOrM344(x) SETUP(XfOrM344_COUNT)
    stxs = NULLED_OUT ; 
    stx = NULLED_OUT ; 
    loco = NULLED_OUT ; 
    p = NULLED_OUT ; 
    loc = NULLED_OUT ; 
    stxs = FUNCCALL(SETUP_XfOrM344(_), scheme_struct_ref (argv [0 ] , 2 ) ); 
    while (((Scheme_Type ) (((((long ) (stxs ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (stxs ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#     define XfOrM346_COUNT (0+XfOrM344_COUNT)
#     define SETUP_XfOrM346(x) SETUP_XfOrM344(x)
      stx = (((Scheme_Simple_Object * ) (stxs ) ) -> u . pair_val . car ) ; 
      loc = ((Scheme_Stx * ) stx ) -> srcloc ; 
      loco = FUNCCALL(SETUP_XfOrM346(_), scheme_make_location (loc -> src ? loc -> src : scheme_false , (loc -> line >= 0 ) ? ((Scheme_Object * ) (void * ) (long ) ((((long ) (loc -> line ) ) << 1 ) | 0x1 ) ) : scheme_false , (loc -> col >= 0 ) ? ((Scheme_Object * ) (void * ) (long ) ((((long ) (loc -> col - 1 ) ) << 1 ) | 0x1 ) ) : scheme_false , (loc -> pos >= 0 ) ? ((Scheme_Object * ) (void * ) (long ) ((((long ) (loc -> pos ) ) << 1 ) | 0x1 ) ) : scheme_false , (loc -> span >= 0 ) ? ((Scheme_Object * ) (void * ) (long ) ((((long ) (loc -> span ) ) << 1 ) | 0x1 ) ) : scheme_false ) ); 
      p = FUNCCALL_AGAIN(scheme_make_pair (loco , scheme_null ) ); 
      if (last )
        (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = p ; 
      else first = p ; 
      last = p ; 
      stxs = (((Scheme_Simple_Object * ) (stxs ) ) -> u . pair_val . cdr ) ; 
    }
    RET_VALUE_START (first ) RET_VALUE_END ; 
  }
  FUNCCALL_EMPTY(scheme_wrong_type ("exn:fail:syntax-locations-accessor" , "exn:fail:syntax" , 0 , argc , argv ) ); 
  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * extract_read_locations (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  if (scheme_is_struct_instance (exn_table [MZEXN_FAIL_READ ] . type , argv [0 ] ) )
    return scheme_struct_ref (argv [0 ] , 2 ) ; 
  scheme_wrong_type ("exn:fail:read-locations-accessor" , "exn:fail:read" , 0 , argc , argv ) ; 
  return ((void * ) 0 ) ; 
}
void scheme_init_exn (Scheme_Env * env ) {
  int i , j ; 
  Scheme_Object * tmpo , * * tmpop ; 
  static const char * MZEXN_FIELDS [2 ] = {
    "message" , "continuation-marks" }
  ; 
  static const char * MZEXN_FAIL_CONTRACT_VARIABLE_FIELDS [1 ] = {
    "id" }
  ; 
  static const char * MZEXN_FAIL_SYNTAX_FIELDS [1 ] = {
    "exprs" }
  ; 
  static const char * MZEXN_FAIL_READ_FIELDS [1 ] = {
    "srclocs" }
  ; 
  static const char * MZEXN_BREAK_FIELDS [1 ] = {
    "continuation" }
  ; 
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
  PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(__funcarg53, 0), PUSH(tmpo, 1), PUSH(__funcarg49, 2), PUSH(env, 3), PUSH(tmpop, 4)));
# define XfOrM348_COUNT (5)
# define SETUP_XfOrM348(x) SETUP(XfOrM348_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  tmpo = NULLED_OUT ; 
  tmpop = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM348(_), scheme_register_static ((void * ) & exn_table , sizeof (exn_table ) ) ); 
  exn_table = (exn_rec * ) FUNCCALL(SETUP_XfOrM348(_), GC_malloc (sizeof (exn_rec ) * MZEXN_OTHER ) ); 
  exn_table [MZEXN ] . args = 2 ; 
  exn_table [MZEXN_FAIL ] . args = 2 ; 
  exn_table [MZEXN_FAIL_CONTRACT ] . args = 2 ; 
  exn_table [MZEXN_FAIL_CONTRACT_ARITY ] . args = 2 ; 
  exn_table [MZEXN_FAIL_CONTRACT_DIVIDE_BY_ZERO ] . args = 2 ; 
  exn_table [MZEXN_FAIL_CONTRACT_CONTINUATION ] . args = 2 ; 
  exn_table [MZEXN_FAIL_CONTRACT_VARIABLE ] . args = 3 ; 
  exn_table [MZEXN_FAIL_SYNTAX ] . args = 3 ; 
  exn_table [MZEXN_FAIL_READ ] . args = 3 ; 
  exn_table [MZEXN_FAIL_READ_EOF ] . args = 3 ; 
  exn_table [MZEXN_FAIL_READ_NON_CHAR ] . args = 3 ; 
  exn_table [MZEXN_FAIL_FILESYSTEM ] . args = 2 ; 
  exn_table [MZEXN_FAIL_FILESYSTEM_EXISTS ] . args = 2 ; 
  exn_table [MZEXN_FAIL_FILESYSTEM_VERSION ] . args = 2 ; 
  exn_table [MZEXN_FAIL_NETWORK ] . args = 2 ; 
  exn_table [MZEXN_FAIL_OUT_OF_MEMORY ] . args = 2 ; 
  exn_table [MZEXN_FAIL_UNSUPPORTED ] . args = 2 ; 
  exn_table [MZEXN_FAIL_USER ] . args = 2 ; 
  exn_table [MZEXN_BREAK ] . args = 3 ; 
  {
#   define XfOrM375_COUNT (0+XfOrM348_COUNT)
#   define SETUP_XfOrM375(x) SETUP_XfOrM348(x)
    tmpo = (__funcarg58 = FUNCCALL(SETUP_XfOrM375(_), scheme_make_prim (exn_field_check ) ), FUNCCALL_AGAIN(scheme_make_struct_type_from_string ("exn" , ((void * ) 0 ) , 2 , scheme_null , __funcarg58 , 1 ) )) ; 
    exn_table [MZEXN ] . type = tmpo ; 
    tmpop = FUNCCALL(SETUP_XfOrM375(_), scheme_make_struct_names_from_array ("exn" , 2 , MZEXN_FIELDS , 0x80 | 0x10 , & exn_table [MZEXN ] . count ) ); 
    exn_table [MZEXN ] . names = tmpop ; 
  }
  {
#   define XfOrM374_COUNT (0+XfOrM348_COUNT)
#   define SETUP_XfOrM374(x) SETUP_XfOrM348(x)
    tmpo = FUNCCALL(SETUP_XfOrM374(_), scheme_make_struct_type_from_string ("exn:fail" , exn_table [MZEXN ] . type , 0 , scheme_null , ((void * ) 0 ) , 1 ) ); 
    exn_table [MZEXN_FAIL ] . type = tmpo ; 
    tmpop = FUNCCALL(SETUP_XfOrM374(_), scheme_make_struct_names_from_array ("exn:fail" , 0 , ((void * ) 0 ) , 0x80 | 0x10 , & exn_table [MZEXN_FAIL ] . count ) ); 
    exn_table [MZEXN_FAIL ] . names = tmpop ; 
  }
  {
#   define XfOrM373_COUNT (0+XfOrM348_COUNT)
#   define SETUP_XfOrM373(x) SETUP_XfOrM348(x)
    tmpo = FUNCCALL(SETUP_XfOrM373(_), scheme_make_struct_type_from_string ("exn:fail:contract" , exn_table [MZEXN_FAIL ] . type , 0 , scheme_null , ((void * ) 0 ) , 1 ) ); 
    exn_table [MZEXN_FAIL_CONTRACT ] . type = tmpo ; 
    tmpop = FUNCCALL(SETUP_XfOrM373(_), scheme_make_struct_names_from_array ("exn:fail:contract" , 0 , ((void * ) 0 ) , 0x80 | 0x10 , & exn_table [MZEXN_FAIL_CONTRACT ] . count ) ); 
    exn_table [MZEXN_FAIL_CONTRACT ] . names = tmpop ; 
  }
  {
#   define XfOrM372_COUNT (0+XfOrM348_COUNT)
#   define SETUP_XfOrM372(x) SETUP_XfOrM348(x)
    tmpo = FUNCCALL(SETUP_XfOrM372(_), scheme_make_struct_type_from_string ("exn:fail:contract:arity" , exn_table [MZEXN_FAIL_CONTRACT ] . type , 0 , scheme_null , ((void * ) 0 ) , 1 ) ); 
    exn_table [MZEXN_FAIL_CONTRACT_ARITY ] . type = tmpo ; 
    tmpop = FUNCCALL(SETUP_XfOrM372(_), scheme_make_struct_names_from_array ("exn:fail:contract:arity" , 0 , ((void * ) 0 ) , 0x80 | 0x10 , & exn_table [MZEXN_FAIL_CONTRACT_ARITY ] . count ) ); 
    exn_table [MZEXN_FAIL_CONTRACT_ARITY ] . names = tmpop ; 
  }
  {
#   define XfOrM371_COUNT (0+XfOrM348_COUNT)
#   define SETUP_XfOrM371(x) SETUP_XfOrM348(x)
    tmpo = FUNCCALL(SETUP_XfOrM371(_), scheme_make_struct_type_from_string ("exn:fail:contract:divide-by-zero" , exn_table [MZEXN_FAIL_CONTRACT ] . type , 0 , scheme_null , ((void * ) 0 ) , 1 ) ); 
    exn_table [MZEXN_FAIL_CONTRACT_DIVIDE_BY_ZERO ] . type = tmpo ; 
    tmpop = FUNCCALL(SETUP_XfOrM371(_), scheme_make_struct_names_from_array ("exn:fail:contract:divide-by-zero" , 0 , ((void * ) 0 ) , 0x80 | 0x10 , & exn_table [MZEXN_FAIL_CONTRACT_DIVIDE_BY_ZERO ] . count ) ); 
    exn_table [MZEXN_FAIL_CONTRACT_DIVIDE_BY_ZERO ] . names = tmpop ; 
  }
  {
#   define XfOrM370_COUNT (0+XfOrM348_COUNT)
#   define SETUP_XfOrM370(x) SETUP_XfOrM348(x)
    tmpo = FUNCCALL(SETUP_XfOrM370(_), scheme_make_struct_type_from_string ("exn:fail:contract:continuation" , exn_table [MZEXN_FAIL_CONTRACT ] . type , 0 , scheme_null , ((void * ) 0 ) , 1 ) ); 
    exn_table [MZEXN_FAIL_CONTRACT_CONTINUATION ] . type = tmpo ; 
    tmpop = FUNCCALL(SETUP_XfOrM370(_), scheme_make_struct_names_from_array ("exn:fail:contract:continuation" , 0 , ((void * ) 0 ) , 0x80 | 0x10 , & exn_table [MZEXN_FAIL_CONTRACT_CONTINUATION ] . count ) ); 
    exn_table [MZEXN_FAIL_CONTRACT_CONTINUATION ] . names = tmpop ; 
  }
  {
#   define XfOrM369_COUNT (0+XfOrM348_COUNT)
#   define SETUP_XfOrM369(x) SETUP_XfOrM348(x)
    tmpo = (__funcarg57 = FUNCCALL(SETUP_XfOrM369(_), scheme_make_prim (variable_field_check ) ), FUNCCALL_AGAIN(scheme_make_struct_type_from_string ("exn:fail:contract:variable" , exn_table [MZEXN_FAIL_CONTRACT ] . type , 1 , scheme_null , __funcarg57 , 1 ) )) ; 
    exn_table [MZEXN_FAIL_CONTRACT_VARIABLE ] . type = tmpo ; 
    tmpop = FUNCCALL(SETUP_XfOrM369(_), scheme_make_struct_names_from_array ("exn:fail:contract:variable" , 1 , MZEXN_FAIL_CONTRACT_VARIABLE_FIELDS , 0x80 | 0x10 , & exn_table [MZEXN_FAIL_CONTRACT_VARIABLE ] . count ) ); 
    exn_table [MZEXN_FAIL_CONTRACT_VARIABLE ] . names = tmpop ; 
  }
  {
#   define XfOrM368_COUNT (0+XfOrM348_COUNT)
#   define SETUP_XfOrM368(x) SETUP_XfOrM348(x)
    tmpo = (__funcarg53 = (__funcarg55 = (__funcarg56 = FUNCCALL(SETUP_XfOrM368(_), scheme_make_prim (extract_syntax_locations ) ), FUNCCALL_AGAIN(scheme_make_pair (scheme_source_property , __funcarg56 ) )) , FUNCCALL_AGAIN(scheme_make_pair (__funcarg55 , scheme_null ) )) , __funcarg54 = FUNCCALL(SETUP_XfOrM368(_), scheme_make_prim (syntax_field_check ) ), FUNCCALL_AGAIN(scheme_make_struct_type_from_string ("exn:fail:syntax" , exn_table [MZEXN_FAIL ] . type , 1 , __funcarg53 , __funcarg54 , 1 ) )) ; 
    exn_table [MZEXN_FAIL_SYNTAX ] . type = tmpo ; 
    tmpop = FUNCCALL(SETUP_XfOrM368(_), scheme_make_struct_names_from_array ("exn:fail:syntax" , 1 , MZEXN_FAIL_SYNTAX_FIELDS , 0x80 | 0x10 , & exn_table [MZEXN_FAIL_SYNTAX ] . count ) ); 
    exn_table [MZEXN_FAIL_SYNTAX ] . names = tmpop ; 
  }
  {
#   define XfOrM367_COUNT (0+XfOrM348_COUNT)
#   define SETUP_XfOrM367(x) SETUP_XfOrM348(x)
    tmpo = (__funcarg49 = (__funcarg51 = (__funcarg52 = FUNCCALL(SETUP_XfOrM367(_), scheme_make_prim (extract_read_locations ) ), FUNCCALL_AGAIN(scheme_make_pair (scheme_source_property , __funcarg52 ) )) , FUNCCALL_AGAIN(scheme_make_pair (__funcarg51 , scheme_null ) )) , __funcarg50 = FUNCCALL(SETUP_XfOrM367(_), scheme_make_prim (read_field_check ) ), FUNCCALL_AGAIN(scheme_make_struct_type_from_string ("exn:fail:read" , exn_table [MZEXN_FAIL ] . type , 1 , __funcarg49 , __funcarg50 , 1 ) )) ; 
    exn_table [MZEXN_FAIL_READ ] . type = tmpo ; 
    tmpop = FUNCCALL(SETUP_XfOrM367(_), scheme_make_struct_names_from_array ("exn:fail:read" , 1 , MZEXN_FAIL_READ_FIELDS , 0x80 | 0x10 , & exn_table [MZEXN_FAIL_READ ] . count ) ); 
    exn_table [MZEXN_FAIL_READ ] . names = tmpop ; 
  }
  {
#   define XfOrM366_COUNT (0+XfOrM348_COUNT)
#   define SETUP_XfOrM366(x) SETUP_XfOrM348(x)
    tmpo = FUNCCALL(SETUP_XfOrM366(_), scheme_make_struct_type_from_string ("exn:fail:read:eof" , exn_table [MZEXN_FAIL_READ ] . type , 0 , scheme_null , ((void * ) 0 ) , 1 ) ); 
    exn_table [MZEXN_FAIL_READ_EOF ] . type = tmpo ; 
    tmpop = FUNCCALL(SETUP_XfOrM366(_), scheme_make_struct_names_from_array ("exn:fail:read:eof" , 0 , ((void * ) 0 ) , 0x80 | 0x10 , & exn_table [MZEXN_FAIL_READ_EOF ] . count ) ); 
    exn_table [MZEXN_FAIL_READ_EOF ] . names = tmpop ; 
  }
  {
#   define XfOrM365_COUNT (0+XfOrM348_COUNT)
#   define SETUP_XfOrM365(x) SETUP_XfOrM348(x)
    tmpo = FUNCCALL(SETUP_XfOrM365(_), scheme_make_struct_type_from_string ("exn:fail:read:non-char" , exn_table [MZEXN_FAIL_READ ] . type , 0 , scheme_null , ((void * ) 0 ) , 1 ) ); 
    exn_table [MZEXN_FAIL_READ_NON_CHAR ] . type = tmpo ; 
    tmpop = FUNCCALL(SETUP_XfOrM365(_), scheme_make_struct_names_from_array ("exn:fail:read:non-char" , 0 , ((void * ) 0 ) , 0x80 | 0x10 , & exn_table [MZEXN_FAIL_READ_NON_CHAR ] . count ) ); 
    exn_table [MZEXN_FAIL_READ_NON_CHAR ] . names = tmpop ; 
  }
  {
#   define XfOrM364_COUNT (0+XfOrM348_COUNT)
#   define SETUP_XfOrM364(x) SETUP_XfOrM348(x)
    tmpo = FUNCCALL(SETUP_XfOrM364(_), scheme_make_struct_type_from_string ("exn:fail:filesystem" , exn_table [MZEXN_FAIL ] . type , 0 , scheme_null , ((void * ) 0 ) , 1 ) ); 
    exn_table [MZEXN_FAIL_FILESYSTEM ] . type = tmpo ; 
    tmpop = FUNCCALL(SETUP_XfOrM364(_), scheme_make_struct_names_from_array ("exn:fail:filesystem" , 0 , ((void * ) 0 ) , 0x80 | 0x10 , & exn_table [MZEXN_FAIL_FILESYSTEM ] . count ) ); 
    exn_table [MZEXN_FAIL_FILESYSTEM ] . names = tmpop ; 
  }
  {
#   define XfOrM363_COUNT (0+XfOrM348_COUNT)
#   define SETUP_XfOrM363(x) SETUP_XfOrM348(x)
    tmpo = FUNCCALL(SETUP_XfOrM363(_), scheme_make_struct_type_from_string ("exn:fail:filesystem:exists" , exn_table [MZEXN_FAIL_FILESYSTEM ] . type , 0 , scheme_null , ((void * ) 0 ) , 1 ) ); 
    exn_table [MZEXN_FAIL_FILESYSTEM_EXISTS ] . type = tmpo ; 
    tmpop = FUNCCALL(SETUP_XfOrM363(_), scheme_make_struct_names_from_array ("exn:fail:filesystem:exists" , 0 , ((void * ) 0 ) , 0x80 | 0x10 , & exn_table [MZEXN_FAIL_FILESYSTEM_EXISTS ] . count ) ); 
    exn_table [MZEXN_FAIL_FILESYSTEM_EXISTS ] . names = tmpop ; 
  }
  {
#   define XfOrM362_COUNT (0+XfOrM348_COUNT)
#   define SETUP_XfOrM362(x) SETUP_XfOrM348(x)
    tmpo = FUNCCALL(SETUP_XfOrM362(_), scheme_make_struct_type_from_string ("exn:fail:filesystem:version" , exn_table [MZEXN_FAIL_FILESYSTEM ] . type , 0 , scheme_null , ((void * ) 0 ) , 1 ) ); 
    exn_table [MZEXN_FAIL_FILESYSTEM_VERSION ] . type = tmpo ; 
    tmpop = FUNCCALL(SETUP_XfOrM362(_), scheme_make_struct_names_from_array ("exn:fail:filesystem:version" , 0 , ((void * ) 0 ) , 0x80 | 0x10 , & exn_table [MZEXN_FAIL_FILESYSTEM_VERSION ] . count ) ); 
    exn_table [MZEXN_FAIL_FILESYSTEM_VERSION ] . names = tmpop ; 
  }
  {
#   define XfOrM361_COUNT (0+XfOrM348_COUNT)
#   define SETUP_XfOrM361(x) SETUP_XfOrM348(x)
    tmpo = FUNCCALL(SETUP_XfOrM361(_), scheme_make_struct_type_from_string ("exn:fail:network" , exn_table [MZEXN_FAIL ] . type , 0 , scheme_null , ((void * ) 0 ) , 1 ) ); 
    exn_table [MZEXN_FAIL_NETWORK ] . type = tmpo ; 
    tmpop = FUNCCALL(SETUP_XfOrM361(_), scheme_make_struct_names_from_array ("exn:fail:network" , 0 , ((void * ) 0 ) , 0x80 | 0x10 , & exn_table [MZEXN_FAIL_NETWORK ] . count ) ); 
    exn_table [MZEXN_FAIL_NETWORK ] . names = tmpop ; 
  }
  {
#   define XfOrM360_COUNT (0+XfOrM348_COUNT)
#   define SETUP_XfOrM360(x) SETUP_XfOrM348(x)
    tmpo = FUNCCALL(SETUP_XfOrM360(_), scheme_make_struct_type_from_string ("exn:fail:out-of-memory" , exn_table [MZEXN_FAIL ] . type , 0 , scheme_null , ((void * ) 0 ) , 1 ) ); 
    exn_table [MZEXN_FAIL_OUT_OF_MEMORY ] . type = tmpo ; 
    tmpop = FUNCCALL(SETUP_XfOrM360(_), scheme_make_struct_names_from_array ("exn:fail:out-of-memory" , 0 , ((void * ) 0 ) , 0x80 | 0x10 , & exn_table [MZEXN_FAIL_OUT_OF_MEMORY ] . count ) ); 
    exn_table [MZEXN_FAIL_OUT_OF_MEMORY ] . names = tmpop ; 
  }
  {
#   define XfOrM359_COUNT (0+XfOrM348_COUNT)
#   define SETUP_XfOrM359(x) SETUP_XfOrM348(x)
    tmpo = FUNCCALL(SETUP_XfOrM359(_), scheme_make_struct_type_from_string ("exn:fail:unsupported" , exn_table [MZEXN_FAIL ] . type , 0 , scheme_null , ((void * ) 0 ) , 1 ) ); 
    exn_table [MZEXN_FAIL_UNSUPPORTED ] . type = tmpo ; 
    tmpop = FUNCCALL(SETUP_XfOrM359(_), scheme_make_struct_names_from_array ("exn:fail:unsupported" , 0 , ((void * ) 0 ) , 0x80 | 0x10 , & exn_table [MZEXN_FAIL_UNSUPPORTED ] . count ) ); 
    exn_table [MZEXN_FAIL_UNSUPPORTED ] . names = tmpop ; 
  }
  {
#   define XfOrM358_COUNT (0+XfOrM348_COUNT)
#   define SETUP_XfOrM358(x) SETUP_XfOrM348(x)
    tmpo = FUNCCALL(SETUP_XfOrM358(_), scheme_make_struct_type_from_string ("exn:fail:user" , exn_table [MZEXN_FAIL ] . type , 0 , scheme_null , ((void * ) 0 ) , 1 ) ); 
    exn_table [MZEXN_FAIL_USER ] . type = tmpo ; 
    tmpop = FUNCCALL(SETUP_XfOrM358(_), scheme_make_struct_names_from_array ("exn:fail:user" , 0 , ((void * ) 0 ) , 0x80 | 0x10 , & exn_table [MZEXN_FAIL_USER ] . count ) ); 
    exn_table [MZEXN_FAIL_USER ] . names = tmpop ; 
  }
  {
#   define XfOrM357_COUNT (0+XfOrM348_COUNT)
#   define SETUP_XfOrM357(x) SETUP_XfOrM348(x)
    tmpo = (__funcarg48 = FUNCCALL(SETUP_XfOrM357(_), scheme_make_prim (break_field_check ) ), FUNCCALL_AGAIN(scheme_make_struct_type_from_string ("exn:break" , exn_table [MZEXN ] . type , 1 , scheme_null , __funcarg48 , 1 ) )) ; 
    exn_table [MZEXN_BREAK ] . type = tmpo ; 
    tmpop = FUNCCALL(SETUP_XfOrM357(_), scheme_make_struct_names_from_array ("exn:break" , 1 , MZEXN_BREAK_FIELDS , 0x80 | 0x10 , & exn_table [MZEXN_BREAK ] . count ) ); 
    exn_table [MZEXN_BREAK ] . names = tmpop ; 
  }
  for (i = 0 ; i < MZEXN_OTHER ; i ++ ) {
#   define XfOrM353_COUNT (0+XfOrM348_COUNT)
#   define SETUP_XfOrM353(x) SETUP_XfOrM348(x)
    if (exn_table [i ] . count ) {
      Scheme_Object * * values , * et ; 
      int sp ; 
      BLOCK_SETUP((PUSH(et, 0+XfOrM353_COUNT), PUSH(values, 1+XfOrM353_COUNT)));
#     define XfOrM354_COUNT (2+XfOrM353_COUNT)
#     define SETUP_XfOrM354(x) SETUP(XfOrM354_COUNT)
      values = NULLED_OUT ; 
      et = NULLED_OUT ; 
      values = FUNCCALL(SETUP_XfOrM354(_), scheme_make_struct_values (exn_table [i ] . type , exn_table [i ] . names , exn_table [i ] . count , 0x80 | 0x10 ) ); 
      for (j = exn_table [i ] . count - 1 ; j -- ; ) {
#       define XfOrM356_COUNT (0+XfOrM354_COUNT)
#       define SETUP_XfOrM356(x) SETUP_XfOrM354(x)
        FUNCCALL(SETUP_XfOrM356(_), scheme_add_global_constant_symbol (exn_table [i ] . names [j ] , values [j ] , env ) ); 
      }
      sp = exn_table [i ] . super_pos ; 
      et = FUNCCALL(SETUP_XfOrM354(_), scheme_make_struct_exptime (exn_table [i ] . names , exn_table [i ] . count , (sp >= 0 ) ? exn_table [sp ] . names [exn_table [sp ] . count - 1 ] : ((void * ) 0 ) , (sp >= 0 ) ? exn_table [sp ] . exptime : ((void * ) 0 ) , 0x80 | 0x10 ) ); 
      exn_table [i ] . exptime = et ; 
      FUNCCALL(SETUP_XfOrM354(_), scheme_add_global_keyword_symbol (exn_table [i ] . names [exn_table [i ] . count - 1 ] , et , env ) ); 
    }
  }
  (__funcarg47 = FUNCCALL(SETUP_XfOrM348(_), scheme_register_parameter (init_exn_handler , "uncaught-exception-handler" , MZCONFIG_INIT_EXN_HANDLER ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("uncaught-exception-handler" , __funcarg47 , env ) )) ; 
  (__funcarg46 = FUNCCALL(SETUP_XfOrM348(_), scheme_make_prim_w_arity (sch_raise , "raise" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("raise" , __funcarg46 , env ) )) ; 
  FUNCCALL_EMPTY(scheme_init_exn_config () ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_init_exn_config (void ) {
  Scheme_Object * h ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(h, 0)));
# define XfOrM376_COUNT (1)
# define SETUP_XfOrM376(x) SETUP(XfOrM376_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  h = NULLED_OUT ; 
  h = FUNCCALL(SETUP_XfOrM376(_), scheme_make_prim_w_arity (def_exn_handler , "default-exception-handler" , 1 , 1 ) ); 
  FUNCCALL_EMPTY(scheme_set_root_param (MZCONFIG_INIT_EXN_HANDLER , h ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
