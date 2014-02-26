#include "precomp.h"
extern Scheme_Object * scheme_eval_compiled_sized_string (const char * str , int len , Scheme_Env * env ) ; 
enum {
  CPT_ESCAPE , CPT_SYMBOL , CPT_SYMREF , CPT_WEIRD_SYMBOL , CPT_KEYWORD , CPT_BYTE_STRING , CPT_CHAR_STRING , CPT_CHAR , CPT_INT , CPT_NULL , CPT_TRUE , CPT_FALSE , CPT_VOID , CPT_BOX , CPT_PAIR , CPT_LIST , CPT_VECTOR , CPT_HASH_TABLE , CPT_STX , CPT_GSTX , CPT_MARSHALLED , CPT_QUOTE , CPT_REFERENCE , CPT_LOCAL , CPT_LOCAL_UNBOX , CPT_SVECTOR , CPT_APPLICATION , CPT_LET_ONE , CPT_BRANCH , CPT_MODULE_INDEX , CPT_MODULE_VAR , CPT_PATH , CPT_CLOSURE , CPT_DELAY_REF , _CPT_COUNT_ }
; 
enum {
  _ISupper = ((0 ) < 8 ? ((1 << (0 ) ) << 8 ) : ((1 << (0 ) ) >> 8 ) ) , _ISlower = ((1 ) < 8 ? ((1 << (1 ) ) << 8 ) : ((1 << (1 ) ) >> 8 ) ) , _ISalpha = ((2 ) < 8 ? ((1 << (2 ) ) << 8 ) : ((1 << (2 ) ) >> 8 ) ) , _ISdigit = ((3 ) < 8 ? ((1 << (3 ) ) << 8 ) : ((1 << (3 ) ) >> 8 ) ) , _ISxdigit = ((4 ) < 8 ? ((1 << (4 ) ) << 8 ) : ((1 << (4 ) ) >> 8 ) ) , _ISspace = ((5 ) < 8 ? ((1 << (5 ) ) << 8 ) : ((1 << (5 ) ) >> 8 ) ) , _ISprint = ((6 ) < 8 ? ((1 << (6 ) ) << 8 ) : ((1 << (6 ) ) >> 8 ) ) , _ISgraph = ((7 ) < 8 ? ((1 << (7 ) ) << 8 ) : ((1 << (7 ) ) >> 8 ) ) , _ISblank = ((8 ) < 8 ? ((1 << (8 ) ) << 8 ) : ((1 << (8 ) ) >> 8 ) ) , _IScntrl = ((9 ) < 8 ? ((1 << (9 ) ) << 8 ) : ((1 << (9 ) ) >> 8 ) ) , _ISpunct = ((10 ) < 8 ? ((1 << (10 ) ) << 8 ) : ((1 << (10 ) ) >> 8 ) ) , _ISalnum = ((11 ) < 8 ? ((1 << (11 ) ) << 8 ) : ((1 << (11 ) ) >> 8 ) ) }
; 
int scheme_square_brackets_are_parens = 1 ; 
int scheme_curly_braces_are_parens = 1 ; 
int scheme_num_read_syntax_objects ; 
static Scheme_Object * read_case_sensitive (int , Scheme_Object * [] ) ; 
static Scheme_Object * read_bracket_as_paren (int , Scheme_Object * [] ) ; 
static Scheme_Object * read_brace_as_paren (int , Scheme_Object * [] ) ; 
static Scheme_Object * read_accept_graph (int , Scheme_Object * [] ) ; 
static Scheme_Object * read_accept_compiled (int , Scheme_Object * [] ) ; 
static Scheme_Object * read_accept_box (int , Scheme_Object * [] ) ; 
static Scheme_Object * read_accept_pipe_quote (int , Scheme_Object * [] ) ; 
static Scheme_Object * read_decimal_as_inexact (int , Scheme_Object * [] ) ; 
static Scheme_Object * read_accept_dot (int , Scheme_Object * [] ) ; 
static Scheme_Object * read_accept_infix_dot (int , Scheme_Object * [] ) ; 
static Scheme_Object * read_accept_quasi (int , Scheme_Object * [] ) ; 
static Scheme_Object * read_accept_reader (int , Scheme_Object * [] ) ; 
static Scheme_Object * print_graph (int , Scheme_Object * [] ) ; 
static Scheme_Object * print_struct (int , Scheme_Object * [] ) ; 
static Scheme_Object * print_box (int , Scheme_Object * [] ) ; 
static Scheme_Object * print_vec_shorthand (int , Scheme_Object * [] ) ; 
static Scheme_Object * print_hash_table (int , Scheme_Object * [] ) ; 
static Scheme_Object * print_unreadable (int , Scheme_Object * [] ) ; 
static Scheme_Object * print_honu (int , Scheme_Object * [] ) ; 
static inline long SPAN (Scheme_Object * port , long pos ) {
  /* No conversion */
  long cpos ; 
  scheme_tell_all (port , ((void * ) 0 ) , ((void * ) 0 ) , & cpos ) ; 
  return cpos - pos + 1 ; 
}
typedef struct Readtable {
  Scheme_Object so ; 
  Scheme_Hash_Table * mapping ; 
  char * fast_mapping ; 
  Scheme_Object * symbol_parser ; 
  char * * names ; 
}
Readtable ; 
typedef struct ReadParams {
  Scheme_Type type ; 
  int can_read_compiled ; 
  int can_read_pipe_quote ; 
  int can_read_box ; 
  int can_read_graph ; 
  int can_read_reader ; 
  int case_sensitive ; 
  int square_brackets_are_parens ; 
  int curly_braces_are_parens ; 
  int read_decimal_inexact ; 
  int can_read_dot ; 
  int can_read_infix_dot ; 
  int can_read_quasi ; 
  int honu_mode ; 
  Readtable * table ; 
  Scheme_Object * magic_sym , * magic_val ; 
  Scheme_Object * delay_load_info ; 
}
ReadParams ; 
static Scheme_Object * read_list (Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , int closer , int shape , int use_stack , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params ) ; 
static Scheme_Object * read_string (int is_byte , int is_honu_char , Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params , int err_ok ) ; 
static Scheme_Object * read_here_string (Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , Scheme_Object * indentation , ReadParams * params ) ; 
static Scheme_Object * read_quote (char * who , Scheme_Object * quote_symbol , int len , Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params ) ; 
static Scheme_Object * read_vector (Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , char closer , long reqLen , const mzchar * reqBuffer , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params ) ; 
static Scheme_Object * read_number (int init_ch , Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , int , int , int , int , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params , Readtable * table ) ; 
static Scheme_Object * read_symbol (int init_ch , int skip_rt , Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params , Readtable * table ) ; 
static Scheme_Object * read_keyword (int init_ch , Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params , Readtable * table ) ; 
static Scheme_Object * read_character (Scheme_Object * port , Scheme_Object * stcsrc , long line , long col , long pos , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params ) ; 
static Scheme_Object * read_box (Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params ) ; 
static Scheme_Object * read_hash (Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , char closer , int eq , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params ) ; 
static Scheme_Object * read_reader (Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params ) ; 
static Scheme_Object * read_lang (Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params ) ; 
static Scheme_Object * read_compiled (Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , Scheme_Hash_Table * * ht , ReadParams * params ) ; 
static void unexpected_closer (int ch , Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , Scheme_Object * indentation , ReadParams * params ) ; 
static void pop_indentation (Scheme_Object * indentation ) ; 
static int skip_whitespace_comments (Scheme_Object * port , Scheme_Object * stxsrc , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params ) ; 
static Scheme_Object * readtable_call (int w_char , int ch , Scheme_Object * proc , ReadParams * params , Scheme_Object * port , Scheme_Object * src , long line , long col , long pos , Scheme_Hash_Table * * ht ) ; 
static Scheme_Object * copy_to_protect_placeholders (Scheme_Object * v , Scheme_Object * src , Scheme_Hash_Table * * ht ) ; 
static int readtable_kind (Readtable * t , int ch , ReadParams * params ) ; 
static Scheme_Object * readtable_handle (Readtable * t , int * _ch , int * _use_default , ReadParams * params , Scheme_Object * port , Scheme_Object * src , long line , long col , long pos , Scheme_Hash_Table * * ht ) ; 
static Scheme_Object * readtable_handle_hash (Readtable * t , int ch , int * _use_default , ReadParams * params , Scheme_Object * port , Scheme_Object * src , long line , long col , long pos , Scheme_Hash_Table * * ht ) ; 
static int readtable_effective_char (Readtable * t , int ch ) ; 
static Scheme_Object * make_readtable (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * readtable_p (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * readtable_mapping (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * current_readtable (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * current_reader_guard (int argc , Scheme_Object * * argv ) ; 
typedef struct {
  int pos ; 
  Scheme_Simple_Object * stack ; 
}
ListStackRec ; 
static void register_traversers (void ) ; 
typedef struct {
  Scheme_Type type ; 
  char closer ; 
  char suspicious_closer ; 
  char multiline ; 
  char quote_for_char ; 
  long start_line ; 
  long last_line ; 
  long suspicious_line ; 
  long max_indent ; 
  long suspicious_quote ; 
}
Scheme_Indent ; 
static Scheme_Object * quote_symbol ; 
static Scheme_Object * quasiquote_symbol ; 
static Scheme_Object * unquote_symbol ; 
static Scheme_Object * unquote_splicing_symbol ; 
static Scheme_Object * syntax_symbol ; 
static Scheme_Object * unsyntax_symbol ; 
static Scheme_Object * unsyntax_splicing_symbol ; 
static Scheme_Object * quasisyntax_symbol ; 
static Scheme_Object * honu_comma , * honu_semicolon ; 
static Scheme_Object * honu_parens , * honu_braces , * honu_brackets , * honu_angles ; 
static Scheme_Object * paren_shape_symbol ; 
static Scheme_Object * terminating_macro_symbol , * non_terminating_macro_symbol , * dispatch_macro_symbol ; 
static char * builtin_fast ; 
static Scheme_Object * honu_angle_open , * honu_angle_close ; 
static Scheme_Object * an_uninterned_symbol ; 
static Scheme_Object * * variable_references ; 
static unsigned char delim [128 ] ; 
void scheme_init_read (Scheme_Env * env ) {
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
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(env, 0)));
# define XfOrM2_COUNT (1)
# define SETUP_XfOrM2(x) SETUP(XfOrM2_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM2(_), scheme_register_static ((void * ) & variable_references , sizeof (variable_references ) ) ); 
  FUNCCALL(SETUP_XfOrM2(_), scheme_register_static ((void * ) & quote_symbol , sizeof (quote_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & quasiquote_symbol , sizeof (quasiquote_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & unquote_symbol , sizeof (unquote_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & unquote_splicing_symbol , sizeof (unquote_splicing_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & syntax_symbol , sizeof (syntax_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & unsyntax_symbol , sizeof (unsyntax_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & unsyntax_splicing_symbol , sizeof (unsyntax_splicing_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & quasisyntax_symbol , sizeof (quasisyntax_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & an_uninterned_symbol , sizeof (an_uninterned_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & paren_shape_symbol , sizeof (paren_shape_symbol ) ) ); 
  quote_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("quote" ) ); 
  quasiquote_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("quasiquote" ) ); 
  unquote_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("unquote" ) ); 
  unquote_splicing_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("unquote-splicing" ) ); 
  syntax_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("syntax" ) ); 
  unsyntax_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("unsyntax" ) ); 
  unsyntax_splicing_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("unsyntax-splicing" ) ); 
  quasisyntax_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("quasisyntax" ) ); 
  an_uninterned_symbol = FUNCCALL_AGAIN(scheme_make_symbol ("unresolved" ) ); 
  paren_shape_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("paren-shape" ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & honu_comma , sizeof (honu_comma ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & honu_semicolon , sizeof (honu_semicolon ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & honu_parens , sizeof (honu_parens ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & honu_braces , sizeof (honu_braces ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & honu_brackets , sizeof (honu_brackets ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & honu_angles , sizeof (honu_angles ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & honu_angle_open , sizeof (honu_angle_open ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & honu_angle_close , sizeof (honu_angle_close ) ) ); 
  honu_comma = FUNCCALL_AGAIN(scheme_intern_symbol ("," ) ); 
  honu_semicolon = FUNCCALL_AGAIN(scheme_intern_symbol (";" ) ); 
  honu_parens = FUNCCALL_AGAIN(scheme_intern_symbol ("#%parens" ) ); 
  honu_braces = FUNCCALL_AGAIN(scheme_intern_symbol ("#%braces" ) ); 
  honu_brackets = FUNCCALL_AGAIN(scheme_intern_symbol ("#%brackets" ) ); 
  honu_angles = FUNCCALL_AGAIN(scheme_intern_symbol ("#%angles" ) ); 
  honu_angle_open = FUNCCALL_AGAIN(scheme_make_symbol ("<" ) ); 
  honu_angle_close = FUNCCALL_AGAIN(scheme_make_symbol (">" ) ); 
  {
    int i ; 
    for (i = 0 ; i < 128 ; i ++ ) {
      delim [i ] = 0x1 ; 
    }
    for (i = 'A' ; i <= 'Z' ; i ++ ) {
      delim [i ] |= 0x2 ; 
      delim [i + ('a' - 'A' ) ] |= 0x2 ; 
    }
    for (i = '0' ; i <= '9' ; i ++ ) {
      delim [i ] |= (0x2 | 0x8 ) ; 
    }
    delim ['(' ] -= 0x1 ; 
    delim [')' ] -= 0x1 ; 
    delim ['[' ] -= 0x1 ; 
    delim [']' ] -= 0x1 ; 
    delim ['{' ] -= 0x1 ; 
    delim ['}' ] -= 0x1 ; 
    delim ['"' ] -= 0x1 ; 
    delim ['\'' ] -= 0x1 ; 
    delim [',' ] -= 0x1 ; 
    delim [';' ] -= 0x1 ; 
    delim ['`' ] -= 0x1 ; 
    delim ['_' ] |= 0x2 ; 
    {
      GC_CAN_IGNORE const char * syms = "+-_=?:<>.!%^&*/~|" ; 
      for (i = 0 ; syms [i ] ; i ++ ) {
        delim [(int ) syms [i ] ] |= 0x4 ; 
      }
    }
    delim ['.' ] |= 0x8 ; 
    delim ['e' ] |= 0x10 ; 
    delim ['E' ] |= 0x10 ; 
    delim ['d' ] |= 0x10 ; 
    delim ['D' ] |= 0x10 ; 
    delim ['f' ] |= 0x10 ; 
    delim ['F' ] |= 0x10 ; 
    delim ['+' ] |= 0x20 ; 
    delim ['-' ] |= 0x20 ; 
  }
  FUNCCALL(SETUP_XfOrM2(_), register_traversers () ); 
  (__funcarg29 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (current_readtable , "current-readtable" , MZCONFIG_READTABLE ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-readtable" , __funcarg29 , env ) )) ; 
  (__funcarg28 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (current_reader_guard , "current-reader-guard" , MZCONFIG_READER_GUARD ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-reader-guard" , __funcarg28 , env ) )) ; 
  (__funcarg27 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (read_case_sensitive , "read-case-sensitive" , MZCONFIG_CASE_SENS ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-case-sensitive" , __funcarg27 , env ) )) ; 
  (__funcarg26 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (read_bracket_as_paren , "read-square-bracket-as-paren" , MZCONFIG_SQUARE_BRACKETS_ARE_PARENS ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-square-bracket-as-paren" , __funcarg26 , env ) )) ; 
  (__funcarg25 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (read_brace_as_paren , "read-curly-brace-as-paren" , MZCONFIG_CURLY_BRACES_ARE_PARENS ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-curly-brace-as-paren" , __funcarg25 , env ) )) ; 
  (__funcarg24 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (read_accept_graph , "read-accept-graph" , MZCONFIG_CAN_READ_GRAPH ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-accept-graph" , __funcarg24 , env ) )) ; 
  (__funcarg23 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (read_accept_compiled , "read-accept-compiled" , MZCONFIG_CAN_READ_COMPILED ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-accept-compiled" , __funcarg23 , env ) )) ; 
  (__funcarg22 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (read_accept_box , "read-accept-box" , MZCONFIG_CAN_READ_BOX ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-accept-box" , __funcarg22 , env ) )) ; 
  (__funcarg21 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (read_accept_pipe_quote , "read-accept-bar-quote" , MZCONFIG_CAN_READ_PIPE_QUOTE ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-accept-bar-quote" , __funcarg21 , env ) )) ; 
  (__funcarg20 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (read_decimal_as_inexact , "read-decimal-as-inexact" , MZCONFIG_READ_DECIMAL_INEXACT ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-decimal-as-inexact" , __funcarg20 , env ) )) ; 
  (__funcarg19 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (read_accept_dot , "read-accept-dot" , MZCONFIG_CAN_READ_DOT ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-accept-dot" , __funcarg19 , env ) )) ; 
  (__funcarg18 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (read_accept_infix_dot , "read-accept-infix-dot" , MZCONFIG_CAN_READ_INFIX_DOT ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-accept-infix-dot" , __funcarg18 , env ) )) ; 
  (__funcarg17 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (read_accept_quasi , "read-accept-quasiquote" , MZCONFIG_CAN_READ_QUASI ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-accept-quasiquote" , __funcarg17 , env ) )) ; 
  (__funcarg16 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (read_accept_reader , "read-accept-reader" , MZCONFIG_CAN_READ_READER ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-accept-reader" , __funcarg16 , env ) )) ; 
  (__funcarg15 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (print_graph , "print-graph" , MZCONFIG_PRINT_GRAPH ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("print-graph" , __funcarg15 , env ) )) ; 
  (__funcarg14 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (print_struct , "print-struct" , MZCONFIG_PRINT_STRUCT ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("print-struct" , __funcarg14 , env ) )) ; 
  (__funcarg13 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (print_box , "print-box" , MZCONFIG_PRINT_BOX ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("print-box" , __funcarg13 , env ) )) ; 
  (__funcarg12 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (print_vec_shorthand , "print-vector-length" , MZCONFIG_PRINT_VEC_SHORTHAND ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("print-vector-length" , __funcarg12 , env ) )) ; 
  (__funcarg11 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (print_hash_table , "print-hash-table" , MZCONFIG_PRINT_HASH_TABLE ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("print-hash-table" , __funcarg11 , env ) )) ; 
  (__funcarg10 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (print_unreadable , "print-unreadable" , MZCONFIG_PRINT_UNREADABLE ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("print-unreadable" , __funcarg10 , env ) )) ; 
  (__funcarg9 = FUNCCALL(SETUP_XfOrM2(_), scheme_register_parameter (print_honu , "print-honu" , MZCONFIG_HONU_MODE ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("print-honu" , __funcarg9 , env ) )) ; 
  (__funcarg8 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (make_readtable , "make-readtable" , 1 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-readtable" , __funcarg8 , env ) )) ; 
  (__funcarg7 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_folding_prim (readtable_p , "readtable?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("readtable?" , __funcarg7 , env ) )) ; 
  (__funcarg6 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_everything (readtable_mapping , 0 , "readtable-mapping" , 2 , 2 , 0 , 3 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("readtable-mapping" , __funcarg6 , env ) )) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Simple_Object * malloc_list_stack () {
  long sz = sizeof (Scheme_Simple_Object ) * 500 ; 
  Scheme_Simple_Object * r ; 
  DECL_RET_SAVE (Scheme_Simple_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(r, 0)));
# define XfOrM13_COUNT (1)
# define SETUP_XfOrM13(x) SETUP(XfOrM13_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  r = NULLED_OUT ; 
  if (sz < FUNCCALL(SETUP_XfOrM13(_), GC_malloc_stays_put_threshold () )) {
#   define XfOrM14_COUNT (0+XfOrM13_COUNT)
#   define SETUP_XfOrM14(x) SETUP_XfOrM13(x)
    sz = FUNCCALL(SETUP_XfOrM14(_), GC_malloc_stays_put_threshold () ); 
    while (sz % sizeof (Scheme_Simple_Object ) ) {
      sz ++ ; 
    }
  }
  r = (Scheme_Simple_Object * ) FUNCCALL(SETUP_XfOrM13(_), GC_malloc_array_tagged (sz ) ); 
  r [0 ] . iso . so . type = scheme_pair_type ; 
  RET_VALUE_START (r ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_alloc_list_stack (Scheme_Thread * p ) {
  Scheme_Simple_Object * sa ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sa, 0), PUSH(p, 1)));
# define XfOrM17_COUNT (2)
# define SETUP_XfOrM17(x) SETUP(XfOrM17_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sa = NULLED_OUT ; 
  p -> list_stack_pos = 0 ; 
  sa = FUNCCALL(SETUP_XfOrM17(_), malloc_list_stack () ); 
  p -> list_stack = sa ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 602 */
void scheme_clean_list_stack (Scheme_Thread * p ) {
  /* No conversion */
  if (p -> list_stack ) {
    memset (p -> list_stack + p -> list_stack_pos , 0 , (500 - p -> list_stack_pos ) * sizeof (Scheme_Simple_Object ) ) ; 
    if (! p -> list_stack_pos ) {
      p -> list_stack [0 ] . iso . so . type = scheme_pair_type ; 
    }
  }
}
static void track_indentation (Scheme_Object * indentation , int line , int col ) {
  /* No conversion */
  if (! ((indentation ) == (scheme_null ) ) ) {
    Scheme_Indent * indt = (Scheme_Indent * ) (((Scheme_Simple_Object * ) (indentation ) ) -> u . pair_val . car ) ; 
    if (line > indt -> last_line ) {
      indt -> last_line = line ; 
      indt -> multiline = 1 ; 
      if (col >= indt -> max_indent )
        indt -> max_indent = col ; 
      else if (! indt -> suspicious_line ) {
        indt -> suspicious_closer = indt -> closer ; 
        indt -> suspicious_line = line ; 
      }
    }
  }
}
static Scheme_Object * read_case_sensitive (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("read-case-sensitive" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_CASE_SENS ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ; 
}
static Scheme_Object * read_bracket_as_paren (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("read-square-bracket-as-paren" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_SQUARE_BRACKETS_ARE_PARENS ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ; 
}
static Scheme_Object * read_brace_as_paren (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("read-curly-brace-as-paren" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_CURLY_BRACES_ARE_PARENS ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ; 
}
static Scheme_Object * read_accept_graph (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("read-accept-graph" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_CAN_READ_GRAPH ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ; 
}
static Scheme_Object * read_accept_compiled (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("read-accept-compiled" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_CAN_READ_COMPILED ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ; 
}
static Scheme_Object * read_accept_box (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("read-accept-box" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_CAN_READ_BOX ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ; 
}
static Scheme_Object * read_accept_pipe_quote (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("read-accept-pipe-quote" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_CAN_READ_PIPE_QUOTE ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ; 
}
static Scheme_Object * read_decimal_as_inexact (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("read-decimal-as-inexact" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_READ_DECIMAL_INEXACT ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ; 
}
static Scheme_Object * read_accept_dot (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("read-accept-dot" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_CAN_READ_DOT ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ; 
}
static Scheme_Object * read_accept_infix_dot (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("read-accept-infix-dot" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_CAN_READ_INFIX_DOT ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ; 
}
static Scheme_Object * read_accept_quasi (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("read-accept-quasiquote" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_CAN_READ_QUASI ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ; 
}
static Scheme_Object * read_accept_reader (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("read-accept-reader" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_CAN_READ_READER ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ; 
}
static Scheme_Object * print_graph (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("print-graph" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_PRINT_GRAPH ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ; 
}
static Scheme_Object * print_struct (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("print-struct" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_PRINT_STRUCT ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ; 
}
static Scheme_Object * print_box (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("print-box" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_PRINT_BOX ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ; 
}
static Scheme_Object * print_vec_shorthand (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("print-vector-length" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_PRINT_VEC_SHORTHAND ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ; 
}
static Scheme_Object * print_hash_table (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("print-vector-length" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_PRINT_HASH_TABLE ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ; 
}
static Scheme_Object * print_unreadable (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("print-unreadable" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_PRINT_UNREADABLE ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ; 
}
static Scheme_Object * print_honu (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("print-honu" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_HONU_MODE ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ; 
}
static Scheme_Object * read_inner_inner (Scheme_Object * port , Scheme_Object * stxsrc , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params , int comment_mode , int pre_char , Readtable * init_readtable ) ; 
static Scheme_Object * read_inner (Scheme_Object * port , Scheme_Object * stxsrc , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params , int comment_mode ) ; 
static Scheme_Object * read_inner_inner_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * o = (Scheme_Object * ) p -> ku . k . p1 ; 
  Scheme_Hash_Table * * ht = (Scheme_Hash_Table * * ) p -> ku . k . p2 ; 
  Scheme_Object * stxsrc = (Scheme_Object * ) p -> ku . k . p3 ; 
  Scheme_Object * indentation = (((Scheme_Simple_Object * ) ((Scheme_Object * ) p -> ku . k . p4 ) ) -> u . pair_val . car ) ; 
  ReadParams * params = (ReadParams * ) (((Scheme_Simple_Object * ) ((Scheme_Object * ) p -> ku . k . p4 ) ) -> u . pair_val . cdr ) ; 
  Readtable * table = (Readtable * ) p -> ku . k . p5 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  p -> ku . k . p2 = ((void * ) 0 ) ; 
  p -> ku . k . p3 = ((void * ) 0 ) ; 
  p -> ku . k . p4 = ((void * ) 0 ) ; 
  p -> ku . k . p5 = ((void * ) 0 ) ; 
  return read_inner_inner (o , stxsrc , ht , indentation , params , p -> ku . k . i1 , p -> ku . k . i2 , table ) ; 
}
static Scheme_Object * read_inner_inner (Scheme_Object * port , Scheme_Object * stxsrc , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params , int comment_mode , int pre_char , Readtable * table ) {
  int ch , ch2 , depth , dispatch_ch , special_value_need_copy = 0 ; 
  long line = 0 , col = 0 , pos = 0 ; 
  Scheme_Object * special_value ; 
  long __funcarg49 ; 
  long __funcarg48 ; 
  long __funcarg47 ; 
  long __funcarg46 ; 
  long __funcarg45 ; 
  long __funcarg44 ; 
  long __funcarg43 ; 
  long __funcarg41 ; 
  long __funcarg40 ; 
  long __funcarg39 ; 
  long __funcarg38 ; 
  long __funcarg37 ; 
  long __funcarg36 ; 
  long __funcarg35 ; 
  long __funcarg34 ; 
  long __funcarg33 ; 
  long __funcarg32 ; 
  long __funcarg31 ; 
  long __funcarg30 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(12);
  BLOCK_SETUP_TOP((PUSH(indentation, 0), PUSH(table, 1), PUSH(stxsrc, 2), PUSH(special_value, 3), PUSH(params, 4), PUSH(ht, 5), PUSH(port, 6)));
# define XfOrM45_COUNT (7)
# define SETUP_XfOrM45(x) SETUP(XfOrM45_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  special_value = NULLED_OUT ; 
  {
    unsigned long _stk_pos ; 
#   define XfOrM229_COUNT (0+XfOrM45_COUNT)
#   define SETUP_XfOrM229(x) SETUP_XfOrM45(x)
    _stk_pos = (unsigned long ) & _stk_pos ; 
    if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
      Scheme_Thread * p = scheme_current_thread ; 
      Scheme_Object * pr ; 
      ReadParams * params2 ; 
      BLOCK_SETUP((PUSH(pr, 0+XfOrM229_COUNT), PUSH(p, 1+XfOrM229_COUNT), PUSH(params2, 2+XfOrM229_COUNT)));
#     define XfOrM230_COUNT (3+XfOrM229_COUNT)
#     define SETUP_XfOrM230(x) SETUP(XfOrM230_COUNT)
      pr = NULLED_OUT ; 
      params2 = NULLED_OUT ; 
      params2 = ((ReadParams * ) FUNCCALL(SETUP_XfOrM230(_), GC_malloc_one_small_tagged ((((sizeof (ReadParams ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
      (memcpy (params2 , params , sizeof (ReadParams ) ) ) ; 
      params2 -> type = scheme_rt_read_params ; 
      p -> ku . k . p1 = (void * ) port ; 
      p -> ku . k . p2 = (void * ) ht ; 
      p -> ku . k . p3 = (void * ) stxsrc ; 
      pr = FUNCCALL(SETUP_XfOrM230(_), scheme_make_pair (indentation , (Scheme_Object * ) params2 ) ); 
      p -> ku . k . p4 = (void * ) pr ; 
      p -> ku . k . p5 = (void * ) table ; 
      p -> ku . k . i1 = comment_mode ; 
      p -> ku . k . i2 = pre_char ; 
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_handle_stack_overflow (read_inner_inner_k ) )) RET_VALUE_EMPTY_END ; 
    }
  }
  start_over : {
#   define XfOrM227_COUNT (0+XfOrM45_COUNT)
#   define SETUP_XfOrM227(x) SETUP_XfOrM45(x)
    if ((scheme_fuel_counter ) <= 0 ) {
#     define XfOrM228_COUNT (0+XfOrM227_COUNT)
#     define SETUP_XfOrM228(x) SETUP_XfOrM227(x)
      FUNCCALL(SETUP_XfOrM228(_), scheme_out_of_fuel () ); 
    }
  }
  ; 
  while (1 ) {
#   define XfOrM223_COUNT (0+XfOrM45_COUNT)
#   define SETUP_XfOrM223(x) SETUP_XfOrM45(x)
    if (pre_char >= 0 ) {
      ch = pre_char ; 
      pre_char = - 1 ; 
    }
    else ch = FUNCCALL(SETUP_XfOrM223(_), scheme_getc_special_ok (port ) ); 
    if (((ch ) >= 0 ) ) {
#     define XfOrM224_COUNT (0+XfOrM223_COUNT)
#     define SETUP_XfOrM224(x) SETUP_XfOrM223(x)
      if (table ) {
#       define XfOrM225_COUNT (0+XfOrM224_COUNT)
#       define SETUP_XfOrM225(x) SETUP_XfOrM224(x)
        if (! (FUNCCALL(SETUP_XfOrM225(_), readtable_kind (table , ch , params ) )& 0x1 ) )
          break ; 
      }
      else if (! (((scheme_uchar_table [(ch >> 8 ) & 0x1FFF ] [ch & 0xFF ] ) ) & 0x10 ) )
        break ; 
    }
    else break ; 
  }
  start_over_with_ch : FUNCCALL(SETUP_XfOrM45(_), scheme_tell_all (port , & line , & col , & pos ) ); 
  if (col >= 0 ) {
#   define XfOrM216_COUNT (0+XfOrM45_COUNT)
#   define SETUP_XfOrM216(x) SETUP_XfOrM45(x)
    if (((Scheme_Type ) (((((long ) (indentation ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (indentation ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
      int effective_ch ; 
#     define XfOrM217_COUNT (0+XfOrM216_COUNT)
#     define SETUP_XfOrM217(x) SETUP_XfOrM216(x)
      effective_ch = FUNCCALL(SETUP_XfOrM217(_), readtable_effective_char (table , ch ) ); 
      if ((effective_ch != ';' ) && ! ((effective_ch == '#' ) && (FUNCCALL(SETUP_XfOrM217(_), scheme_peekc_special_ok (port ) )== '|' ) ) && (effective_ch != ')' ) && ((effective_ch != '}' ) || ! params -> curly_braces_are_parens ) && ((effective_ch != ']' ) || ! params -> square_brackets_are_parens ) ) {
#       define XfOrM218_COUNT (0+XfOrM217_COUNT)
#       define SETUP_XfOrM218(x) SETUP_XfOrM217(x)
        FUNCCALL(SETUP_XfOrM218(_), track_indentation (indentation , line , col ) ); 
      }
    }
  }
  special_value = ((void * ) 0 ) ; 
  if (table && ((ch ) >= 0 ) ) {
    Scheme_Object * v ; 
    int use_default , ch2 = ch ; 
    BLOCK_SETUP((PUSH(v, 0+XfOrM45_COUNT)));
#   define XfOrM214_COUNT (1+XfOrM45_COUNT)
#   define SETUP_XfOrM214(x) SETUP(XfOrM214_COUNT)
    v = NULLED_OUT ; 
    v = FUNCCALL(SETUP_XfOrM214(_), readtable_handle (table , & ch2 , & use_default , params , port , stxsrc , line , col , pos , ht ) ); 
    if (! use_default ) {
      dispatch_ch = (- 2 ) ; 
      special_value = v ; 
    }
    else dispatch_ch = ch2 ; 
  }
  else dispatch_ch = ch ; 
  switch (dispatch_ch ) {
#   define XfOrM51_COUNT (0+XfOrM45_COUNT)
#   define SETUP_XfOrM51(x) SETUP_XfOrM45(x)
    case (- 1 ) : RET_VALUE_START (scheme_eof ) RET_VALUE_END ; 
    case (- 2 ) : {
#     define XfOrM212_COUNT (0+XfOrM51_COUNT)
#     define SETUP_XfOrM212(x) SETUP_XfOrM51(x)
      if (! special_value ) {
#       define XfOrM213_COUNT (0+XfOrM212_COUNT)
#       define SETUP_XfOrM213(x) SETUP_XfOrM212(x)
        special_value = FUNCCALL(SETUP_XfOrM213(_), scheme_get_special (port , stxsrc , line , col , pos , 0 , ht ) ); 
        special_value_need_copy = 1 ; 
      }
      break ; 
    }
    case ']' : if (! params -> square_brackets_are_parens ) {
#     define XfOrM211_COUNT (0+XfOrM51_COUNT)
#     define SETUP_XfOrM211(x) SETUP_XfOrM51(x)
      FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , 1 , 0 , indentation , "read: illegal use of close square bracket" ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else {
#     define XfOrM210_COUNT (0+XfOrM51_COUNT)
#     define SETUP_XfOrM210(x) SETUP_XfOrM51(x)
      FUNCCALL(SETUP_XfOrM210(_), unexpected_closer (ch , port , stxsrc , line , col , pos , indentation , params ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    case '}' : if (! params -> curly_braces_are_parens ) {
#     define XfOrM209_COUNT (0+XfOrM51_COUNT)
#     define SETUP_XfOrM209(x) SETUP_XfOrM51(x)
      FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , 1 , 0 , indentation , "read: illegal use of close curly brace" ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else {
#     define XfOrM208_COUNT (0+XfOrM51_COUNT)
#     define SETUP_XfOrM208(x) SETUP_XfOrM51(x)
      FUNCCALL(SETUP_XfOrM208(_), unexpected_closer (ch , port , stxsrc , line , col , pos , indentation , params ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    case ')' : FUNCCALL(SETUP_XfOrM51(_), unexpected_closer (ch , port , stxsrc , line , col , pos , indentation , params ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    case '(' : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_list (port , stxsrc , line , col , pos , ')' , 0 , 0 , ht , indentation , params ) )) RET_VALUE_EMPTY_END ; 
    case '[' : if (! params -> square_brackets_are_parens ) {
#     define XfOrM207_COUNT (0+XfOrM51_COUNT)
#     define SETUP_XfOrM207(x) SETUP_XfOrM51(x)
      FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , 1 , 0 , indentation , "read: illegal use of open square bracket" ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_list (port , stxsrc , line , col , pos , ']' , 0 , 0 , ht , indentation , params ) )) RET_VALUE_EMPTY_END ; 
    case '{' : if (! params -> curly_braces_are_parens ) {
#     define XfOrM206_COUNT (0+XfOrM51_COUNT)
#     define SETUP_XfOrM206(x) SETUP_XfOrM51(x)
      FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , 1 , 0 , indentation , "read: illegal use of open curly brace" ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_list (port , stxsrc , line , col , pos , '}' , 0 , 0 , ht , indentation , params ) )) RET_VALUE_EMPTY_END ; 
    case '|' : special_value = FUNCCALL(SETUP_XfOrM51(_), read_symbol (ch , 1 , port , stxsrc , line , col , pos , ht , indentation , params , table ) ); 
    break ; 
    case '"' : RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_string (0 , 0 , port , stxsrc , line , col , pos , ht , indentation , params , 1 ) )) RET_VALUE_EMPTY_END ; 
    case '\'' : if (params -> honu_mode ) {
#     define XfOrM205_COUNT (0+XfOrM51_COUNT)
#     define SETUP_XfOrM205(x) SETUP_XfOrM51(x)
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_string (0 , 1 , port , stxsrc , line , col , pos , ht , indentation , params , 1 ) )) RET_VALUE_EMPTY_END ; 
    }
    else {
#     define XfOrM204_COUNT (0+XfOrM51_COUNT)
#     define SETUP_XfOrM204(x) SETUP_XfOrM51(x)
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_quote ("quoting '" , quote_symbol , 1 , port , stxsrc , line , col , pos , ht , indentation , params ) )) RET_VALUE_EMPTY_END ; 
    }
    case '`' : if (params -> honu_mode ) {
#     define XfOrM203_COUNT (0+XfOrM51_COUNT)
#     define SETUP_XfOrM203(x) SETUP_XfOrM51(x)
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_symbol (ch , 1 , port , stxsrc , line , col , pos , ht , indentation , params , table ) )) RET_VALUE_EMPTY_END ; 
    }
    else if (! params -> can_read_quasi ) {
#     define XfOrM202_COUNT (0+XfOrM51_COUNT)
#     define SETUP_XfOrM202(x) SETUP_XfOrM51(x)
      FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , 1 , 0 , indentation , "read: illegal use of backquote" ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_quote ("quasiquoting `" , quasiquote_symbol , 1 , port , stxsrc , line , col , pos , ht , indentation , params ) )) RET_VALUE_EMPTY_END ; 
    case ',' : if (params -> honu_mode ) {
#     define XfOrM201_COUNT (0+XfOrM51_COUNT)
#     define SETUP_XfOrM201(x) SETUP_XfOrM51(x)
      if (stxsrc )
        RET_VALUE_START ((__funcarg49 = FUNCCALL(SETUP_XfOrM201(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_make_stx_w_offset (honu_comma , line , col , pos , __funcarg49 , stxsrc , scheme_false ) )) ) RET_VALUE_END ; 
      else RET_VALUE_START (honu_comma ) RET_VALUE_END ; 
    }
    else if (! params -> can_read_quasi ) {
#     define XfOrM200_COUNT (0+XfOrM51_COUNT)
#     define SETUP_XfOrM200(x) SETUP_XfOrM51(x)
      FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , 1 , 0 , indentation , "read: illegal use of comma" ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else {
#     define XfOrM198_COUNT (0+XfOrM51_COUNT)
#     define SETUP_XfOrM198(x) SETUP_XfOrM51(x)
      if (FUNCCALL(SETUP_XfOrM198(_), scheme_peekc_special_ok (port ) )== '@' ) {
#       define XfOrM199_COUNT (0+XfOrM198_COUNT)
#       define SETUP_XfOrM199(x) SETUP_XfOrM198(x)
        ch = FUNCCALL(SETUP_XfOrM199(_), scheme_getc (port ) ); 
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_quote ("unquoting ,@" , unquote_splicing_symbol , 2 , port , stxsrc , line , col , pos , ht , indentation , params ) )) RET_VALUE_EMPTY_END ; 
      }
      else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_quote ("unquoting ," , unquote_symbol , 1 , port , stxsrc , line , col , pos , ht , indentation , params ) )) RET_VALUE_EMPTY_END ; 
    }
    case ';' : if (params -> honu_mode ) {
#     define XfOrM197_COUNT (0+XfOrM51_COUNT)
#     define SETUP_XfOrM197(x) SETUP_XfOrM51(x)
      if (stxsrc )
        RET_VALUE_START ((__funcarg48 = FUNCCALL(SETUP_XfOrM197(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_make_stx_w_offset (honu_semicolon , line , col , pos , __funcarg48 , stxsrc , scheme_false ) )) ) RET_VALUE_END ; 
      else RET_VALUE_START (honu_semicolon ) RET_VALUE_END ; 
    }
    else {
#     define XfOrM192_COUNT (0+XfOrM51_COUNT)
#     define SETUP_XfOrM192(x) SETUP_XfOrM51(x)
      while (((ch = FUNCCALL(SETUP_XfOrM192(_), scheme_getc_special_ok (port ) )) != '\n' ) && (ch != '\r' ) ) {
#       define XfOrM195_COUNT (0+XfOrM192_COUNT)
#       define SETUP_XfOrM195(x) SETUP_XfOrM192(x)
        if (ch == (- 1 ) ) {
          if (comment_mode & 0x8 )
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          RET_VALUE_START (scheme_eof ) RET_VALUE_END ; 
        }
        if (ch == (- 2 ) )
          FUNCCALL(SETUP_XfOrM195(_), scheme_get_ready_read_special (port , stxsrc , ht ) ); 
      }
      if ((table && (comment_mode & 0x1 ) ) || (comment_mode & 0x8 ) )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      goto start_over ; 
    }
    case '+' : case '-' : if (params -> honu_mode ) {
#     define XfOrM191_COUNT (0+XfOrM51_COUNT)
#     define SETUP_XfOrM191(x) SETUP_XfOrM51(x)
      special_value = FUNCCALL(SETUP_XfOrM191(_), read_symbol (ch , 1 , port , stxsrc , line , col , pos , ht , indentation , params , table ) ); 
      break ; 
    }
    case '.' : ch2 = FUNCCALL(SETUP_XfOrM51(_), scheme_peekc_special_ok (port ) ); 
    if ((((ch2 ) >= 0 ) && ((ch2 >= '0' ) && (ch2 <= '9' ) ) ) || (ch2 == '.' ) || (! params -> honu_mode && ((ch2 == 'i' ) || (ch2 == 'I' ) || (ch2 == 'n' ) || (ch2 == 'N' ) ) ) ) {
#     define XfOrM190_COUNT (0+XfOrM51_COUNT)
#     define SETUP_XfOrM190(x) SETUP_XfOrM51(x)
      special_value = FUNCCALL(SETUP_XfOrM190(_), read_number (ch , port , stxsrc , line , col , pos , 0 , 0 , 10 , 0 , ht , indentation , params , table ) ); 
    }
    else {
#     define XfOrM189_COUNT (0+XfOrM51_COUNT)
#     define SETUP_XfOrM189(x) SETUP_XfOrM51(x)
      special_value = FUNCCALL(SETUP_XfOrM189(_), read_symbol (ch , 0 , port , stxsrc , line , col , pos , ht , indentation , params , table ) ); 
    }
    break ; 
    case '#' : ch = FUNCCALL(SETUP_XfOrM51(_), scheme_getc_special_ok (port ) ); 
    if (table ) {
      Scheme_Object * v ; 
      int use_default ; 
      BLOCK_SETUP((PUSH(v, 0+XfOrM51_COUNT)));
#     define XfOrM187_COUNT (1+XfOrM51_COUNT)
#     define SETUP_XfOrM187(x) SETUP(XfOrM187_COUNT)
      v = NULLED_OUT ; 
      v = FUNCCALL(SETUP_XfOrM187(_), readtable_handle_hash (table , ch , & use_default , params , port , stxsrc , line , col , pos , ht ) ); 
      if (! use_default ) {
        if (v )
          RET_VALUE_START (v ) RET_VALUE_END ; 
        if (comment_mode & 0x1 )
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        goto start_over ; 
      }
    }
    special_value = ((void * ) 0 ) ; 
    switch (ch ) {
#     define XfOrM57_COUNT (0+XfOrM51_COUNT)
#     define SETUP_XfOrM57(x) SETUP_XfOrM51(x)
      case (- 1 ) : case (- 2 ) : FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , 1 , ch , indentation , "read: bad syntax `#'" ) ); 
      break ; 
      case ';' : {
        Scheme_Object * skipped ; 
        BLOCK_SETUP((PUSH(skipped, 0+XfOrM57_COUNT)));
#       define XfOrM185_COUNT (1+XfOrM57_COUNT)
#       define SETUP_XfOrM185(x) SETUP(XfOrM185_COUNT)
        skipped = NULLED_OUT ; 
        skipped = FUNCCALL(SETUP_XfOrM185(_), read_inner (port , stxsrc , ht , indentation , params , 0 ) ); 
        if ((((skipped ) ) == (scheme_eof ) ) )
          (__funcarg47 = FUNCCALL(SETUP_XfOrM185(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg47 , (- 1 ) , indentation , "read: expected a commented-out element for `#;' (found end-of-file)" ) )) ; 
        if (* ht ) {
          Scheme_Object * v ; 
          BLOCK_SETUP((PUSH(v, 0+XfOrM185_COUNT)));
#         define XfOrM186_COUNT (1+XfOrM185_COUNT)
#         define SETUP_XfOrM186(x) SETUP(XfOrM186_COUNT)
          v = NULLED_OUT ; 
          v = FUNCCALL(SETUP_XfOrM186(_), scheme_hash_get (* ht , an_uninterned_symbol ) ); 
          if (! v )
            v = scheme_null ; 
          v = FUNCCALL(SETUP_XfOrM186(_), scheme_make_pair (skipped , v ) ); 
          FUNCCALL_AGAIN(scheme_hash_set (* ht , an_uninterned_symbol , v ) ); 
        }
        if ((comment_mode & 0x2 ) || (table && (comment_mode & 0x1 ) ) || (comment_mode & 0x8 ) )
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        goto start_over ; 
      }
      break ; 
      case '%' : if (! params -> honu_mode ) {
#       define XfOrM184_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM184(x) SETUP_XfOrM57(x)
        FUNCCALL(SETUP_XfOrM184(_), scheme_ungetc ('%' , port ) ); 
        special_value = FUNCCALL(SETUP_XfOrM184(_), read_symbol ('#' , 1 , port , stxsrc , line , col , pos , ht , indentation , params , table ) ); 
      }
      break ; 
      case ':' : if (! params -> honu_mode ) {
#       define XfOrM183_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM183(x) SETUP_XfOrM57(x)
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_keyword (- 1 , port , stxsrc , line , col , pos , ht , indentation , params , table ) )) RET_VALUE_EMPTY_END ; 
      }
      break ; 
      case '(' : if (! params -> honu_mode ) {
#       define XfOrM182_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM182(x) SETUP_XfOrM57(x)
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_vector (port , stxsrc , line , col , pos , ')' , - 1 , ((void * ) 0 ) , ht , indentation , params ) )) RET_VALUE_EMPTY_END ; 
      }
      break ; 
      case '[' : if (! params -> honu_mode ) {
#       define XfOrM180_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM180(x) SETUP_XfOrM57(x)
        if (! params -> square_brackets_are_parens ) {
#         define XfOrM181_COUNT (0+XfOrM180_COUNT)
#         define SETUP_XfOrM181(x) SETUP_XfOrM180(x)
          FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , 2 , 0 , indentation , "read: bad syntax `#['" ) ); 
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        }
        else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_vector (port , stxsrc , line , col , pos , ']' , - 1 , ((void * ) 0 ) , ht , indentation , params ) )) RET_VALUE_EMPTY_END ; 
      }
      break ; 
      case '{' : if (! params -> honu_mode ) {
#       define XfOrM178_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM178(x) SETUP_XfOrM57(x)
        if (! params -> curly_braces_are_parens ) {
#         define XfOrM179_COUNT (0+XfOrM178_COUNT)
#         define SETUP_XfOrM179(x) SETUP_XfOrM178(x)
          FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , 2 , 0 , indentation , "read: bad syntax `#{'" ) ); 
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        }
        else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_vector (port , stxsrc , line , col , pos , '}' , - 1 , ((void * ) 0 ) , ht , indentation , params ) )) RET_VALUE_EMPTY_END ; 
      }
      break ; 
      case '\\' : if (! params -> honu_mode ) {
        Scheme_Object * chr ; 
        BLOCK_SETUP((PUSH(chr, 0+XfOrM57_COUNT)));
#       define XfOrM177_COUNT (1+XfOrM57_COUNT)
#       define SETUP_XfOrM177(x) SETUP(XfOrM177_COUNT)
        chr = NULLED_OUT ; 
        chr = FUNCCALL(SETUP_XfOrM177(_), read_character (port , stxsrc , line , col , pos , ht , indentation , params ) ); 
        if (stxsrc )
          chr = (__funcarg46 = FUNCCALL(SETUP_XfOrM177(_), SPAN (port , pos ) ), FUNCCALL_AGAIN(scheme_make_stx_w_offset (chr , line , col , pos , __funcarg46 , stxsrc , scheme_false ) )) ; 
        RET_VALUE_START (chr ) RET_VALUE_END ; 
      }
      break ; 
      case 'T' : case 't' : if (! params -> honu_mode ) {
#       define XfOrM176_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM176(x) SETUP_XfOrM57(x)
        RET_VALUE_START ((stxsrc ? FUNCCALL(SETUP_XfOrM176(_), scheme_make_stx_w_offset (scheme_true , line , col , pos , 2 , stxsrc , scheme_false ) ): scheme_true ) ) RET_VALUE_END ; 
      }
      case 'F' : case 'f' : if (! params -> honu_mode ) {
#       define XfOrM175_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM175(x) SETUP_XfOrM57(x)
        RET_VALUE_START ((stxsrc ? FUNCCALL(SETUP_XfOrM175(_), scheme_make_stx_w_offset (scheme_false , line , col , pos , 2 , stxsrc , scheme_false ) ): scheme_false ) ) RET_VALUE_END ; 
      }
      case 'c' : case 'C' : if (! params -> honu_mode ) {
        Scheme_Object * v ; 
        int sens = 0 ; 
        int save_sens ; 
        BLOCK_SETUP((PUSH(v, 0+XfOrM57_COUNT)));
#       define XfOrM172_COUNT (1+XfOrM57_COUNT)
#       define SETUP_XfOrM172(x) SETUP(XfOrM172_COUNT)
        v = NULLED_OUT ; 
        ch = FUNCCALL(SETUP_XfOrM172(_), scheme_getc_special_ok (port ) ); 
        switch (ch ) {
#         define XfOrM174_COUNT (0+XfOrM172_COUNT)
#         define SETUP_XfOrM174(x) SETUP_XfOrM172(x)
          case 'i' : case 'I' : sens = 0 ; 
          break ; 
          case 's' : case 'S' : sens = 1 ; 
          break ; 
          default : FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , 2 , ch , indentation , "read: expected `s' or `i' after #c" ) ); 
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        }
        save_sens = params -> case_sensitive ; 
        params -> case_sensitive = sens ; 
        v = FUNCCALL(SETUP_XfOrM172(_), read_inner (port , stxsrc , ht , indentation , params , 0 ) ); 
        params -> case_sensitive = save_sens ; 
        if ((((v ) ) == (scheme_eof ) ) ) {
#         define XfOrM173_COUNT (0+XfOrM172_COUNT)
#         define SETUP_XfOrM173(x) SETUP_XfOrM172(x)
          FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , 2 , (- 1 ) , indentation , "read: end-of-file after #c%c" , sens ? 's' : 'i' ) ); 
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        }
        RET_VALUE_START (v ) RET_VALUE_END ; 
      }
      break ; 
      case 's' : case 'S' : ch = FUNCCALL(SETUP_XfOrM57(_), scheme_getc_special_ok (port ) ); 
      if ((ch == 'x' ) || (ch == 'X' ) ) {
        ReadParams params_copy ; 
        Scheme_Object * v ; 
        BLOCK_SETUP((PUSH(params_copy.table, 0+XfOrM57_COUNT), PUSH(params_copy.magic_sym, 1+XfOrM57_COUNT), PUSH(params_copy.magic_val, 2+XfOrM57_COUNT), PUSH(params_copy.delay_load_info, 3+XfOrM57_COUNT), PUSH(v, 4+XfOrM57_COUNT)));
#       define XfOrM170_COUNT (5+XfOrM57_COUNT)
#       define SETUP_XfOrM170(x) SETUP(XfOrM170_COUNT)
        params_copy.table = NULLED_OUT ; 
        params_copy.magic_sym = NULLED_OUT ; 
        params_copy.magic_val = NULLED_OUT ; 
        params_copy.delay_load_info = NULLED_OUT ; 
        v = NULLED_OUT ; 
        (memcpy (& params_copy , params , sizeof (ReadParams ) ) ) ; 
        params_copy . honu_mode = 0 ; 
        v = FUNCCALL(SETUP_XfOrM170(_), read_inner (port , stxsrc , ht , indentation , & params_copy , 0 ) ); 
        if ((((v ) ) == (scheme_eof ) ) ) {
#         define XfOrM171_COUNT (0+XfOrM170_COUNT)
#         define SETUP_XfOrM171(x) SETUP_XfOrM170(x)
          FUNCCALL(SETUP_XfOrM171(_), scheme_read_err (port , stxsrc , line , col , pos , 2 , (- 1 ) , indentation , "read: end-of-file after #sx" ) ); 
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        }
        RET_VALUE_START (v ) RET_VALUE_END ; 
      }
      else {
#       define XfOrM169_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM169(x) SETUP_XfOrM57(x)
        (__funcarg45 = FUNCCALL(SETUP_XfOrM169(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg45 , ch , indentation , "read: expected `x' after `#s'" ) )) ; 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      case 'X' : case 'x' : if (! params -> honu_mode ) {
#       define XfOrM168_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM168(x) SETUP_XfOrM57(x)
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_number (- 1 , port , stxsrc , line , col , pos , 0 , 0 , 16 , 1 , ht , indentation , params , table ) )) RET_VALUE_EMPTY_END ; 
      }
      break ; 
      case 'B' : case 'b' : if (! params -> honu_mode ) {
#       define XfOrM167_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM167(x) SETUP_XfOrM57(x)
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_number (- 1 , port , stxsrc , line , col , pos , 0 , 0 , 2 , 1 , ht , indentation , params , table ) )) RET_VALUE_EMPTY_END ; 
      }
      break ; 
      case 'O' : case 'o' : if (! params -> honu_mode ) {
#       define XfOrM166_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM166(x) SETUP_XfOrM57(x)
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_number (- 1 , port , stxsrc , line , col , pos , 0 , 0 , 8 , 1 , ht , indentation , params , table ) )) RET_VALUE_EMPTY_END ; 
      }
      break ; 
      case 'D' : case 'd' : if (! params -> honu_mode ) {
#       define XfOrM165_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM165(x) SETUP_XfOrM57(x)
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_number (- 1 , port , stxsrc , line , col , pos , 0 , 0 , 10 , 1 , ht , indentation , params , table ) )) RET_VALUE_EMPTY_END ; 
      }
      break ; 
      case 'E' : case 'e' : if (! params -> honu_mode ) {
#       define XfOrM164_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM164(x) SETUP_XfOrM57(x)
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_number (- 1 , port , stxsrc , line , col , pos , 0 , 1 , 10 , 0 , ht , indentation , params , table ) )) RET_VALUE_EMPTY_END ; 
      }
      break ; 
      case 'I' : case 'i' : if (! params -> honu_mode ) {
#       define XfOrM163_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM163(x) SETUP_XfOrM57(x)
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_number (- 1 , port , stxsrc , line , col , pos , 1 , 0 , 10 , 0 , ht , indentation , params , table ) )) RET_VALUE_EMPTY_END ; 
      }
      break ; 
      case '\'' : if (! params -> honu_mode ) {
#       define XfOrM162_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM162(x) SETUP_XfOrM57(x)
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_quote ("quoting #'" , syntax_symbol , 2 , port , stxsrc , line , col , pos , ht , indentation , params ) )) RET_VALUE_EMPTY_END ; 
      }
      break ; 
      case '`' : if (! params -> honu_mode ) {
#       define XfOrM161_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM161(x) SETUP_XfOrM57(x)
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_quote ("quasiquoting #`" , quasisyntax_symbol , 2 , port , stxsrc , line , col , pos , ht , indentation , params ) )) RET_VALUE_EMPTY_END ; 
      }
      break ; 
      case ',' : if (! params -> honu_mode ) {
#       define XfOrM159_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM159(x) SETUP_XfOrM57(x)
        if (FUNCCALL(SETUP_XfOrM159(_), scheme_peekc_special_ok (port ) )== '@' ) {
#         define XfOrM160_COUNT (0+XfOrM159_COUNT)
#         define SETUP_XfOrM160(x) SETUP_XfOrM159(x)
          ch = FUNCCALL(SETUP_XfOrM160(_), scheme_getc (port ) ); 
          RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_quote ("unquoting #`@" , unsyntax_splicing_symbol , 3 , port , stxsrc , line , col , pos , ht , indentation , params ) )) RET_VALUE_EMPTY_END ; 
        }
        else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_quote ("unquoting #`" , unsyntax_symbol , 2 , port , stxsrc , line , col , pos , ht , indentation , params ) )) RET_VALUE_EMPTY_END ; 
      }
      break ; 
      case '~' : if (! params -> honu_mode ) {
#       define XfOrM156_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM156(x) SETUP_XfOrM57(x)
        if (params -> can_read_compiled ) {
          Scheme_Object * cpld ; 
          BLOCK_SETUP((PUSH(cpld, 0+XfOrM156_COUNT)));
#         define XfOrM158_COUNT (1+XfOrM156_COUNT)
#         define SETUP_XfOrM158(x) SETUP(XfOrM158_COUNT)
          cpld = NULLED_OUT ; 
          cpld = FUNCCALL(SETUP_XfOrM158(_), read_compiled (port , stxsrc , line , col , pos , ht , params ) ); 
          if (stxsrc )
            cpld = (__funcarg44 = FUNCCALL(SETUP_XfOrM158(_), SPAN (port , pos ) ), FUNCCALL_AGAIN(scheme_make_stx_w_offset (cpld , line , col , pos , __funcarg44 , stxsrc , scheme_false ) )) ; 
          RET_VALUE_START (cpld ) RET_VALUE_END ; 
        }
        else {
#         define XfOrM157_COUNT (0+XfOrM156_COUNT)
#         define SETUP_XfOrM157(x) SETUP_XfOrM156(x)
          FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , 2 , 0 , indentation , "read: #~ compiled expressions not currently enabled" ) ); 
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        }
      }
      break ; 
      case '|' : if (! params -> honu_mode ) {
#       define XfOrM147_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM147(x) SETUP_XfOrM57(x)
        depth = 0 ; 
        ch2 = 0 ; 
        do {
#         define XfOrM152_COUNT (0+XfOrM147_COUNT)
#         define SETUP_XfOrM152(x) SETUP_XfOrM147(x)
          ch = FUNCCALL(SETUP_XfOrM152(_), scheme_getc_special_ok (port ) ); 
          if (ch == (- 1 ) )
            (__funcarg43 = FUNCCALL(SETUP_XfOrM152(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg43 , (- 1 ) , indentation , "read: end of file in #| comment" ) )) ; 
          else if (ch == (- 2 ) )
            FUNCCALL(SETUP_XfOrM152(_), scheme_get_ready_read_special (port , stxsrc , ht ) ); 
          if ((ch2 == '|' ) && (ch == '#' ) ) {
            if (! (depth -- ) ) {
              if ((table && (comment_mode & 0x1 ) ) || (comment_mode & 0x8 ) )
                RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
              goto start_over ; 
            }
            ch = 0 ; 
          }
          else if ((ch2 == '#' ) && (ch == '|' ) ) {
            depth ++ ; 
            ch = 0 ; 
          }
          ch2 = ch ; 
        }
        while (1 ) ; 
      }
      break ; 
      case '&' : if (! params -> honu_mode ) {
#       define XfOrM145_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM145(x) SETUP_XfOrM57(x)
        if (params -> can_read_box )
          RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_box (port , stxsrc , line , col , pos , ht , indentation , params ) )) RET_VALUE_EMPTY_END ; 
        else {
#         define XfOrM146_COUNT (0+XfOrM145_COUNT)
#         define SETUP_XfOrM146(x) SETUP_XfOrM145(x)
          FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , 2 , 0 , indentation , "read: #& expressions not currently enabled" ) ); 
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        }
      }
      break ; 
      case 'l' : {
        mzchar found [5 ] ; 
        int fl = 1 ; 
#       define XfOrM137_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM137(x) SETUP_XfOrM57(x)
        found [0 ] = 'l' ; 
        ch = FUNCCALL(SETUP_XfOrM137(_), scheme_getc_special_ok (port ) ); 
        found [fl ++ ] = ch ; 
        if (ch == 'a' ) {
#         define XfOrM138_COUNT (0+XfOrM137_COUNT)
#         define SETUP_XfOrM138(x) SETUP_XfOrM137(x)
          ch = FUNCCALL(SETUP_XfOrM138(_), scheme_getc_special_ok (port ) ); 
          found [fl ++ ] = ch ; 
          if (ch == 'n' ) {
#           define XfOrM139_COUNT (0+XfOrM138_COUNT)
#           define SETUP_XfOrM139(x) SETUP_XfOrM138(x)
            ch = FUNCCALL(SETUP_XfOrM139(_), scheme_getc_special_ok (port ) ); 
            found [fl ++ ] = ch ; 
            if (ch == 'g' ) {
#             define XfOrM140_COUNT (0+XfOrM139_COUNT)
#             define SETUP_XfOrM140(x) SETUP_XfOrM139(x)
              ch = FUNCCALL(SETUP_XfOrM140(_), scheme_getc_special_ok (port ) ); 
              found [fl ++ ] = ch ; 
              if (ch == ' ' ) {
                Scheme_Object * v ; 
                BLOCK_SETUP((PUSH(v, 0+XfOrM140_COUNT)));
#               define XfOrM142_COUNT (1+XfOrM140_COUNT)
#               define SETUP_XfOrM142(x) SETUP(XfOrM142_COUNT)
                v = NULLED_OUT ; 
                if (! params -> can_read_reader ) {
#                 define XfOrM144_COUNT (0+XfOrM142_COUNT)
#                 define SETUP_XfOrM144(x) SETUP_XfOrM142(x)
                  FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , 6 , 0 , indentation , "read: #lang expressions not currently enabled" ) ); 
                  RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
                }
                v = FUNCCALL(SETUP_XfOrM142(_), read_lang (port , stxsrc , line , col , pos , ht , indentation , params ) ); 
                if (! v ) {
                  if (comment_mode & 0x1 )
                    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
                  goto start_over ; 
                }
                RET_VALUE_START (v ) RET_VALUE_END ; 
              }
              else {
#               define XfOrM141_COUNT (0+XfOrM140_COUNT)
#               define SETUP_XfOrM141(x) SETUP_XfOrM140(x)
                FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , 6 , ch , indentation , "read: expected a single space after `#lang'" , found , fl ) ); 
                RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
              }
            }
          }
        }
        FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , fl , ch , indentation , "read: bad input: `#%u'" , found , fl ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      break ; 
      case 'r' : case 'p' : if (! params -> honu_mode ) {
        int orig_ch = ch ; 
        int cnt = 0 , is_byte = 0 ; 
        char * expect ; 
        BLOCK_SETUP((PUSH(expect, 0+XfOrM57_COUNT)));
#       define XfOrM122_COUNT (1+XfOrM57_COUNT)
#       define SETUP_XfOrM122(x) SETUP(XfOrM122_COUNT)
        expect = NULLED_OUT ; 
        ch = FUNCCALL(SETUP_XfOrM122(_), scheme_getc_special_ok (port ) ); 
        if (ch == 'x' ) {
#         define XfOrM133_COUNT (0+XfOrM122_COUNT)
#         define SETUP_XfOrM133(x) SETUP_XfOrM122(x)
          expect = "x#" ; 
          ch = FUNCCALL(SETUP_XfOrM133(_), scheme_getc_special_ok (port ) ); 
          cnt ++ ; 
          if (ch == '#' ) {
#           define XfOrM136_COUNT (0+XfOrM133_COUNT)
#           define SETUP_XfOrM136(x) SETUP_XfOrM133(x)
            is_byte = 1 ; 
            cnt ++ ; 
            ch = FUNCCALL(SETUP_XfOrM136(_), scheme_getc_special_ok (port ) ); 
          }
          if (ch == '"' ) {
            Scheme_Object * str ; 
            int is_err ; 
            long sline = 0 , scol = 0 , spos = 0 ; 
            BLOCK_SETUP((PUSH(str, 0+XfOrM133_COUNT)));
#           define XfOrM134_COUNT (1+XfOrM133_COUNT)
#           define SETUP_XfOrM134(x) SETUP(XfOrM134_COUNT)
            str = NULLED_OUT ; 
            FUNCCALL(SETUP_XfOrM134(_), scheme_tell_all (port , & sline , & scol , & spos ) ); 
            str = FUNCCALL_AGAIN(read_string (is_byte , 0 , port , stxsrc , sline , scol , spos , ht , indentation , params , 1 ) ); 
            if (stxsrc )
              str = ((Scheme_Stx * ) str ) -> val ; 
            str = FUNCCALL(SETUP_XfOrM134(_), scheme_make_regexp (str , is_byte , (orig_ch == 'p' ) , & is_err ) ); 
            if (is_err ) {
#             define XfOrM135_COUNT (0+XfOrM134_COUNT)
#             define SETUP_XfOrM135(x) SETUP_XfOrM134(x)
              FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , sline , scol , spos , 2 , 0 , indentation , "read: bad %sregexp string: %s" , (orig_ch == 'r' ) ? "" : "p" , (char * ) str ) ); 
              RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
            }
            if (stxsrc )
              str = (__funcarg41 = FUNCCALL(SETUP_XfOrM134(_), SPAN (port , pos ) ), FUNCCALL_AGAIN(scheme_make_stx_w_offset (str , line , col , pos , __funcarg41 , stxsrc , scheme_false ) )) ; 
            RET_VALUE_START (str ) RET_VALUE_END ; 
          }
        }
        else if ((orig_ch == 'r' ) && (ch == 'e' ) ) {
#         define XfOrM127_COUNT (0+XfOrM122_COUNT)
#         define SETUP_XfOrM127(x) SETUP_XfOrM122(x)
          expect = "eader" ; 
          cnt ++ ; 
          while (expect [cnt ] ) {
#           define XfOrM132_COUNT (0+XfOrM127_COUNT)
#           define SETUP_XfOrM132(x) SETUP_XfOrM127(x)
            ch = FUNCCALL(SETUP_XfOrM132(_), scheme_getc_special_ok (port ) ); 
            if (ch != expect [cnt ] )
              break ; 
            cnt ++ ; 
          }
          if (! expect [cnt ] ) {
            Scheme_Object * v ; 
            BLOCK_SETUP((PUSH(v, 0+XfOrM127_COUNT)));
#           define XfOrM128_COUNT (1+XfOrM127_COUNT)
#           define SETUP_XfOrM128(x) SETUP(XfOrM128_COUNT)
            v = NULLED_OUT ; 
            if (! params -> can_read_reader ) {
#             define XfOrM130_COUNT (0+XfOrM128_COUNT)
#             define SETUP_XfOrM130(x) SETUP_XfOrM128(x)
              FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , 7 , 0 , indentation , "read: #reader expressions not currently enabled" ) ); 
              RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
            }
            v = FUNCCALL(SETUP_XfOrM128(_), read_reader (port , stxsrc , line , col , pos , ht , indentation , params ) ); 
            if (! v ) {
              if (comment_mode & 0x1 )
                RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
              goto start_over ; 
            }
            RET_VALUE_START (v ) RET_VALUE_END ; 
          }
        }
        else expect = "" ; 
        {
          mzchar a [6 ] ; 
          int i ; 
#         define XfOrM123_COUNT (0+XfOrM122_COUNT)
#         define SETUP_XfOrM123(x) SETUP_XfOrM122(x)
          for (i = 0 ; i < cnt ; i ++ ) {
            a [i ] = expect [i ] ; 
          }
          if (((ch ) >= 0 ) ) {
            a [cnt ++ ] = ch ; 
          }
          (__funcarg40 = FUNCCALL(SETUP_XfOrM123(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg40 , ch , indentation , "read: bad syntax `#%c%u'" , orig_ch , a , cnt ) )) ; 
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        }
      }
      break ; 
      case 'h' : {
        int honu = 0 ; 
#       define XfOrM100_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM100(x) SETUP_XfOrM57(x)
        ch = FUNCCALL(SETUP_XfOrM100(_), scheme_getc_special_ok (port ) ); 
        switch (ch ) {
#         define XfOrM120_COUNT (0+XfOrM100_COUNT)
#         define SETUP_XfOrM120(x) SETUP_XfOrM100(x)
          case 'a' : honu = 0 ; 
          break ; 
          case 'o' : honu = - 1 ; 
          break ; 
          case 'x' : honu = 1 ; 
          break ; 
          default : if (! params -> honu_mode ) {
#           define XfOrM121_COUNT (0+XfOrM120_COUNT)
#           define SETUP_XfOrM121(x) SETUP_XfOrM120(x)
            FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , 2 , ch , indentation , "read: expected `a', `u', or `o' after #h" ) ); 
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          }
          honu = 0 ; 
          break ; 
        }
        if (params -> honu_mode && (honu != 1 ) ) {
#         define XfOrM119_COUNT (0+XfOrM100_COUNT)
#         define SETUP_XfOrM119(x) SETUP_XfOrM100(x)
          FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , 2 , ch , indentation , "read: expected `x' after #h" ) ); 
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        }
        if (honu ) {
          ReadParams params_copy ; 
          Scheme_Object * v ; 
          BLOCK_SETUP((PUSH(params_copy.table, 0+XfOrM100_COUNT), PUSH(params_copy.magic_sym, 1+XfOrM100_COUNT), PUSH(params_copy.magic_val, 2+XfOrM100_COUNT), PUSH(params_copy.delay_load_info, 3+XfOrM100_COUNT), PUSH(v, 4+XfOrM100_COUNT)));
#         define XfOrM113_COUNT (5+XfOrM100_COUNT)
#         define SETUP_XfOrM113(x) SETUP(XfOrM113_COUNT)
          params_copy.table = NULLED_OUT ; 
          params_copy.magic_sym = NULLED_OUT ; 
          params_copy.magic_val = NULLED_OUT ; 
          params_copy.delay_load_info = NULLED_OUT ; 
          v = NULLED_OUT ; 
          if (honu == - 1 ) {
#           define XfOrM116_COUNT (0+XfOrM113_COUNT)
#           define SETUP_XfOrM116(x) SETUP_XfOrM113(x)
            ch = FUNCCALL(SETUP_XfOrM116(_), scheme_getc_special_ok (port ) ); 
            if (ch == 'n' ) {
#             define XfOrM117_COUNT (0+XfOrM116_COUNT)
#             define SETUP_XfOrM117(x) SETUP_XfOrM116(x)
              ch = FUNCCALL(SETUP_XfOrM117(_), scheme_getc_special_ok (port ) ); 
              if (ch == 'u' ) {
              }
              else FUNCCALL(SETUP_XfOrM117(_), scheme_read_err (port , stxsrc , line , col , pos , 4 , ch , indentation , "read: expected `u' after #hon" ) ); 
            }
            else FUNCCALL(SETUP_XfOrM116(_), scheme_read_err (port , stxsrc , line , col , pos , 3 , ch , indentation , "read: expected `nu' after #ho" ) ); 
          }
          (memcpy (& params_copy , params , sizeof (ReadParams ) ) ) ; 
          params_copy . honu_mode = 1 ; 
          if (honu == 1 ) {
#           define XfOrM114_COUNT (0+XfOrM113_COUNT)
#           define SETUP_XfOrM114(x) SETUP_XfOrM113(x)
            v = FUNCCALL(SETUP_XfOrM114(_), read_inner (port , stxsrc , ht , indentation , & params_copy , 0 ) ); 
            if ((((v ) ) == (scheme_eof ) ) ) {
#             define XfOrM115_COUNT (0+XfOrM114_COUNT)
#             define SETUP_XfOrM115(x) SETUP_XfOrM114(x)
              FUNCCALL(SETUP_XfOrM115(_), scheme_read_err (port , stxsrc , line , col , pos , 2 , (- 1 ) , indentation , "read: end-of-file after #hx" ) ); 
              RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
            }
          }
          else v = FUNCCALL(SETUP_XfOrM113(_), read_list (port , stxsrc , line , col , pos , (- 1 ) , 0 , 0 , ht , indentation , & params_copy ) ); 
          RET_VALUE_START (v ) RET_VALUE_END ; 
        }
        else {
          GC_CAN_IGNORE const mzchar str [] = {
            's' , 'h' , 'e' , 'q' , 0 }
          ; 
          int scanpos = 0 , failed = 0 ; 
#         define XfOrM101_COUNT (0+XfOrM100_COUNT)
#         define SETUP_XfOrM101(x) SETUP_XfOrM100(x)
          do {
#           define XfOrM109_COUNT (0+XfOrM101_COUNT)
#           define SETUP_XfOrM109(x) SETUP_XfOrM101(x)
            ch = FUNCCALL(SETUP_XfOrM109(_), scheme_getc_special_ok (port ) ); 
            if ((mzchar ) ch == str [scanpos ] ) {
              scanpos ++ ; 
            }
            else {
#             define XfOrM110_COUNT (0+XfOrM109_COUNT)
#             define SETUP_XfOrM110(x) SETUP_XfOrM109(x)
              if (scanpos == 2 ) {
                int effective_ch ; 
#               define XfOrM111_COUNT (0+XfOrM110_COUNT)
#               define SETUP_XfOrM111(x) SETUP_XfOrM110(x)
                effective_ch = FUNCCALL(SETUP_XfOrM111(_), readtable_effective_char (table , ch ) ); 
                if (! (effective_ch == '(' ) && ! (effective_ch == '[' && params -> square_brackets_are_parens ) && ! (effective_ch == '{' && params -> curly_braces_are_parens ) )
                  failed = 1 ; 
              }
              else failed = 1 ; 
              break ; 
            }
          }
          while (str [scanpos ] ) ; 
          if (! failed ) {
            int effective_ch ; 
#           define XfOrM104_COUNT (0+XfOrM101_COUNT)
#           define SETUP_XfOrM104(x) SETUP_XfOrM101(x)
            if (scanpos > 2 )
              ch = FUNCCALL(SETUP_XfOrM104(_), scheme_getc_special_ok (port ) ); 
            effective_ch = FUNCCALL(SETUP_XfOrM104(_), readtable_effective_char (table , ch ) ); 
            if (effective_ch == '(' )
              RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_hash (port , stxsrc , line , col , pos , ')' , (scanpos == 4 ) , ht , indentation , params ) )) RET_VALUE_EMPTY_END ; 
            if (effective_ch == '[' && params -> square_brackets_are_parens )
              RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_hash (port , stxsrc , line , col , pos , ']' , (scanpos == 4 ) , ht , indentation , params ) )) RET_VALUE_EMPTY_END ; 
            if (effective_ch == '{' && params -> curly_braces_are_parens )
              RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_hash (port , stxsrc , line , col , pos , '}' , (scanpos == 4 ) , ht , indentation , params ) )) RET_VALUE_EMPTY_END ; 
          }
          {
            mzchar str_part [7 ] , one_more [2 ] ; 
#           define XfOrM102_COUNT (0+XfOrM101_COUNT)
#           define SETUP_XfOrM102(x) SETUP_XfOrM101(x)
            (memcpy (str_part , str , scanpos * sizeof (mzchar ) ) ) ; 
            str_part [scanpos ] = 0 ; 
            if (((ch ) >= 0 ) ) {
              one_more [0 ] = ch ; 
              one_more [1 ] = 0 ; 
            }
            else one_more [0 ] = 0 ; 
            (__funcarg39 = FUNCCALL(SETUP_XfOrM102(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg39 , ch , indentation , "read: bad syntax `#ha%5%u'" , str_part , one_more , ((ch ) >= 0 ) ? 1 : 0 ) )) ; 
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          }
        }
      }
      break ; 
      case '"' : if (! params -> honu_mode ) {
#       define XfOrM99_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM99(x) SETUP_XfOrM57(x)
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_string (1 , 0 , port , stxsrc , line , col , pos , ht , indentation , params , 1 ) )) RET_VALUE_EMPTY_END ; 
      }
      break ; 
      case '<' : if (! params -> honu_mode ) {
#       define XfOrM96_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM96(x) SETUP_XfOrM57(x)
        if (FUNCCALL(SETUP_XfOrM96(_), scheme_peekc_special_ok (port ) )== '<' ) {
#         define XfOrM98_COUNT (0+XfOrM96_COUNT)
#         define SETUP_XfOrM98(x) SETUP_XfOrM96(x)
          ch = FUNCCALL(SETUP_XfOrM98(_), scheme_getc_special_ok (port ) ); 
          RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_here_string (port , stxsrc , line , col , pos , indentation , params ) )) RET_VALUE_EMPTY_END ; 
        }
        else {
#         define XfOrM97_COUNT (0+XfOrM96_COUNT)
#         define SETUP_XfOrM97(x) SETUP_XfOrM96(x)
          FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , 2 , 0 , indentation , "read: bad syntax `#<'" ) ); 
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        }
      }
      break ; 
      case '!' : ch = FUNCCALL(SETUP_XfOrM57(_), scheme_getc_special_ok (port ) ); 
      if ((ch == ' ' ) || (ch == '/' ) ) {
        int was_backslash = 0 , was_backslash_cr = 0 , prev_backslash_cr ; 
#       define XfOrM83_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM83(x) SETUP_XfOrM57(x)
        while (1 ) {
#         define XfOrM90_COUNT (0+XfOrM83_COUNT)
#         define SETUP_XfOrM90(x) SETUP_XfOrM83(x)
          prev_backslash_cr = was_backslash_cr ; 
          was_backslash_cr = 0 ; 
          ch = FUNCCALL(SETUP_XfOrM90(_), scheme_getc_special_ok (port ) ); 
          if (ch == (- 1 ) ) {
            break ; 
          }
          else if (ch == (- 2 ) ) {
#           define XfOrM94_COUNT (0+XfOrM90_COUNT)
#           define SETUP_XfOrM94(x) SETUP_XfOrM90(x)
            FUNCCALL(SETUP_XfOrM94(_), scheme_get_ready_read_special (port , stxsrc , ht ) ); 
          }
          else if (ch == '\r' ) {
            if (was_backslash ) {
              was_backslash_cr = 1 ; 
            }
            else break ; 
          }
          else if (ch == '\n' ) {
            if (! was_backslash && ! was_backslash_cr )
              break ; 
          }
          was_backslash = (ch == '\\' ) ; 
        }
        if (comment_mode & 0x8 )
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        goto start_over ; 
      }
      else {
#       define XfOrM82_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM82(x) SETUP_XfOrM57(x)
        if (((ch ) >= 0 ) )
          FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , 3 , ch , indentation , "read: bad syntax `#!%c'" , ch ) ); 
        else FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , 2 , ch , indentation , "read: bad syntax `#!'" , ch ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      break ; 
      default : if (! params -> honu_mode ) {
        int vector_length = - 1 ; 
        int i = 0 , j = 0 , overflow = 0 , digits = 0 , effective_ch ; 
        mzchar tagbuf [64 ] , vecbuf [64 ] ; 
#       define XfOrM58_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM58(x) SETUP_XfOrM57(x)
        while (((ch ) >= 0 ) && ((ch >= '0' ) && (ch <= '9' ) ) ) {
#         define XfOrM74_COUNT (0+XfOrM58_COUNT)
#         define SETUP_XfOrM74(x) SETUP_XfOrM58(x)
          if (digits <= 8 )
            digits ++ ; 
          if (j || (ch != '0' ) ) {
            if (j < 60 ) {
              vecbuf [j ++ ] = ch ; 
            }
            else if (j == 60 ) {
              vecbuf [j ++ ] = '.' ; 
              vecbuf [j ++ ] = '.' ; 
              vecbuf [j ++ ] = '.' ; 
              vecbuf [j ] = 0 ; 
            }
          }
          if (i < 60 ) {
            tagbuf [i ++ ] = ch ; 
          }
          else if (i == 60 ) {
            tagbuf [i ++ ] = '.' ; 
            tagbuf [i ++ ] = '.' ; 
            tagbuf [i ++ ] = '.' ; 
            tagbuf [i ] = 0 ; 
          }
          if (! overflow ) {
            long old_len ; 
            if (vector_length < 0 )
              vector_length = 0 ; 
            old_len = vector_length ; 
            vector_length = (vector_length * 10 ) + (ch - 48 ) ; 
            if ((vector_length < 0 ) || ((vector_length / 10 ) != old_len ) ) {
              overflow = 1 ; 
            }
          }
          ch = FUNCCALL(SETUP_XfOrM74(_), scheme_getc_special_ok (port ) ); 
        }
        if (overflow )
          vector_length = - 2 ; 
        vecbuf [j ] = 0 ; 
        tagbuf [i ] = 0 ; 
        effective_ch = FUNCCALL(SETUP_XfOrM58(_), readtable_effective_char (table , ch ) ); 
        if (effective_ch == '(' )
          RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_vector (port , stxsrc , line , col , pos , ')' , vector_length , vecbuf , ht , indentation , params ) )) RET_VALUE_EMPTY_END ; 
        if (effective_ch == '[' && params -> square_brackets_are_parens )
          RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_vector (port , stxsrc , line , col , pos , ']' , vector_length , vecbuf , ht , indentation , params ) )) RET_VALUE_EMPTY_END ; 
        if (effective_ch == '{' && params -> curly_braces_are_parens )
          RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(read_vector (port , stxsrc , line , col , pos , '}' , vector_length , vecbuf , ht , indentation , params ) )) RET_VALUE_EMPTY_END ; 
        if (ch == '#' && (vector_length != - 1 ) ) {
          Scheme_Object * ph ; 
          BLOCK_SETUP((PUSH(ph, 0+XfOrM58_COUNT)));
#         define XfOrM64_COUNT (1+XfOrM58_COUNT)
#         define SETUP_XfOrM64(x) SETUP(XfOrM64_COUNT)
          ph = NULLED_OUT ; 
          if (! params -> can_read_graph )
            (__funcarg38 = FUNCCALL(SETUP_XfOrM64(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg38 , 0 , indentation , "read: #..# expressions not currently enabled" ) )) ; 
          if (digits > 8 )
            (__funcarg37 = FUNCCALL(SETUP_XfOrM64(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg37 , 0 , indentation , "read: graph id too long in #%5#" , tagbuf ) )) ; 
          if (* ht )
            ph = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM64(_), scheme_hash_get (* ht , ((Scheme_Object * ) (void * ) (long ) ((((long ) (vector_length ) ) << 1 ) | 0x1 ) ) ) ); 
          else ph = ((void * ) 0 ) ; 
          if (! ph ) {
#           define XfOrM65_COUNT (0+XfOrM64_COUNT)
#           define SETUP_XfOrM65(x) SETUP_XfOrM64(x)
            (__funcarg36 = FUNCCALL(SETUP_XfOrM65(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg36 , 0 , indentation , "read: no #%ld= preceding #%ld#" , vector_length , vector_length ) )) ; 
            RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
          }
          RET_VALUE_START (ph ) RET_VALUE_END ; 
        }
        if (ch == '=' && (vector_length != - 1 ) ) {
          Scheme_Object * v , * ph ; 
          BLOCK_SETUP((PUSH(v, 0+XfOrM58_COUNT), PUSH(ph, 1+XfOrM58_COUNT)));
#         define XfOrM60_COUNT (2+XfOrM58_COUNT)
#         define SETUP_XfOrM60(x) SETUP(XfOrM60_COUNT)
          v = NULLED_OUT ; 
          ph = NULLED_OUT ; 
          if (! params -> can_read_graph )
            (__funcarg35 = FUNCCALL(SETUP_XfOrM60(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg35 , 0 , indentation , "read: #..= expressions not currently enabled" ) )) ; 
          if (digits > 8 )
            (__funcarg34 = FUNCCALL(SETUP_XfOrM60(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg34 , 0 , indentation , "read: graph id too long in #%s=" , tagbuf ) )) ; 
          if (* ht ) {
#           define XfOrM62_COUNT (0+XfOrM60_COUNT)
#           define SETUP_XfOrM62(x) SETUP_XfOrM60(x)
            if (FUNCCALL(SETUP_XfOrM62(_), scheme_hash_get (* ht , ((Scheme_Object * ) (void * ) (long ) ((((long ) (vector_length ) ) << 1 ) | 0x1 ) ) ) )) {
#             define XfOrM63_COUNT (0+XfOrM62_COUNT)
#             define SETUP_XfOrM63(x) SETUP_XfOrM62(x)
              (__funcarg33 = FUNCCALL(SETUP_XfOrM63(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg33 , 0 , indentation , "read: multiple #%ld= tags" , vector_length ) )) ; 
              RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
            }
          }
          else {
            Scheme_Hash_Table * tht ; 
            BLOCK_SETUP((PUSH(tht, 0+XfOrM60_COUNT)));
#           define XfOrM61_COUNT (1+XfOrM60_COUNT)
#           define SETUP_XfOrM61(x) SETUP(XfOrM61_COUNT)
            tht = NULLED_OUT ; 
            tht = FUNCCALL(SETUP_XfOrM61(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
            * ht = tht ; 
          }
          ph = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM60(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
          ph -> type = scheme_placeholder_type ; 
          FUNCCALL(SETUP_XfOrM60(_), scheme_hash_set (* ht , ((Scheme_Object * ) (void * ) (long ) ((((long ) (vector_length ) ) << 1 ) | 0x1 ) ) , (void * ) ph ) ); 
          v = FUNCCALL_AGAIN(read_inner (port , stxsrc , ht , indentation , params , 0 ) ); 
          if ((((v ) ) == (scheme_eof ) ) )
            (__funcarg32 = FUNCCALL(SETUP_XfOrM60(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg32 , (- 1 ) , indentation , "read: expected an element for graph (found end-of-file)" ) )) ; 
          if (stxsrc && ((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
            v = FUNCCALL(SETUP_XfOrM60(_), scheme_make_graph_stx (v , line , col , pos ) ); 
          (((Scheme_Small_Object * ) (ph ) ) -> u . ptr_val ) = v ; 
          RET_VALUE_START (v ) RET_VALUE_END ; 
        }
        {
          char * lbuffer ; 
          int pch = ch , ulen , blen ; 
          BLOCK_SETUP((PUSH(lbuffer, 0+XfOrM58_COUNT)));
#         define XfOrM59_COUNT (1+XfOrM58_COUNT)
#         define SETUP_XfOrM59(x) SETUP(XfOrM59_COUNT)
          lbuffer = NULLED_OUT ; 
          if ((pch == (- 1 ) ) || (pch == (- 2 ) ) )
            pch = 0 ; 
          ulen = FUNCCALL(SETUP_XfOrM59(_), scheme_char_strlen (tagbuf ) ); 
          blen = FUNCCALL_AGAIN(scheme_utf8_encode_all (tagbuf , ulen , ((void * ) 0 ) ) ); 
          lbuffer = (char * ) FUNCCALL(SETUP_XfOrM59(_), GC_malloc_atomic (blen + 6 + 1 ) ); 
          FUNCCALL(SETUP_XfOrM59(_), scheme_utf8_encode_all (tagbuf , ulen , (unsigned char * ) lbuffer ) ); 
          blen += FUNCCALL(SETUP_XfOrM59(_), scheme_utf8_encode ((mzchar * ) & pch , 0 , 1 , (unsigned char * ) lbuffer , blen , 0 ) ); 
          lbuffer [blen ] = 0 ; 
          (__funcarg31 = FUNCCALL(SETUP_XfOrM59(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg31 , ch , indentation , "read: bad syntax `#%s'" , lbuffer ) )) ; 
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        }
      }
      break ; 
    }
    if (! special_value ) {
#     define XfOrM56_COUNT (0+XfOrM51_COUNT)
#     define SETUP_XfOrM56(x) SETUP_XfOrM51(x)
      FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , 2 , ch , indentation , "read: bad syntax `#%c'" , ch ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    break ; 
    case '/' : if (params -> honu_mode ) {
      int ch2 ; 
#     define XfOrM54_COUNT (0+XfOrM51_COUNT)
#     define SETUP_XfOrM54(x) SETUP_XfOrM51(x)
      ch2 = FUNCCALL(SETUP_XfOrM54(_), scheme_peekc_special_ok (port ) ); 
      if ((ch2 == '/' ) || (ch2 == '*' ) ) {
#       define XfOrM55_COUNT (0+XfOrM54_COUNT)
#       define SETUP_XfOrM55(x) SETUP_XfOrM54(x)
        FUNCCALL(SETUP_XfOrM55(_), scheme_ungetc ('/' , port ) ); 
        ch = FUNCCALL(SETUP_XfOrM55(_), skip_whitespace_comments (port , stxsrc , ht , indentation , params ) ); 
        goto start_over_with_ch ; 
      }
    }
    special_value = FUNCCALL(SETUP_XfOrM51(_), read_symbol (ch , 0 , port , stxsrc , line , col , pos , ht , indentation , params , table ) ); 
    break ; 
    case '>' : case '<' : if ((params -> honu_mode ) && (comment_mode & 0x10 ) ) {
      Scheme_Object * v ; 
      BLOCK_SETUP((PUSH(v, 0+XfOrM51_COUNT)));
#     define XfOrM52_COUNT (1+XfOrM51_COUNT)
#     define SETUP_XfOrM52(x) SETUP(XfOrM52_COUNT)
      v = NULLED_OUT ; 
      v = FUNCCALL(SETUP_XfOrM52(_), read_symbol (ch , 0 , port , stxsrc , line , col , pos , ht , indentation , params , table ) ); 
      special_value = v ; 
      if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
        v = ((Scheme_Stx * ) v ) -> val ; 
      if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) && ((((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (v ) ) ) -> len ) == 1 ) && (((((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (v ) ) ) -> s ) [0 ] == '>' ) || ((((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (v ) ) ) -> s ) [0 ] == '<' ) ) ) {
#       define XfOrM53_COUNT (0+XfOrM52_COUNT)
#       define SETUP_XfOrM53(x) SETUP_XfOrM52(x)
        if ((((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (v ) ) ) -> s ) [0 ] == '<' )
          v = honu_angle_open ; 
        else v = honu_angle_close ; 
        if (((Scheme_Type ) (((((long ) (special_value ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (special_value ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
          special_value = FUNCCALL(SETUP_XfOrM53(_), scheme_datum_to_syntax (v , scheme_false , special_value , 0 , 1 ) ); 
        else special_value = v ; 
      }
    }
    else special_value = FUNCCALL(SETUP_XfOrM51(_), read_symbol (ch , 0 , port , stxsrc , line , col , pos , ht , indentation , params , table ) ); 
    break ; 
    default : if (((ch >= '0' ) && (ch <= '9' ) ) )
      special_value = FUNCCALL(SETUP_XfOrM51(_), read_number (ch , port , stxsrc , line , col , pos , 0 , 0 , 10 , 0 , ht , indentation , params , table ) ); 
    else special_value = FUNCCALL(SETUP_XfOrM51(_), read_symbol (ch , 0 , port , stxsrc , line , col , pos , ht , indentation , params , table ) ); 
    break ; 
  }
  {
    Scheme_Object * v = special_value ; 
    BLOCK_SETUP((PUSH(v, 0+XfOrM45_COUNT)));
#   define XfOrM46_COUNT (1+XfOrM45_COUNT)
#   define SETUP_XfOrM46(x) SETUP(XfOrM46_COUNT)
    if (FUNCCALL(SETUP_XfOrM46(_), scheme_special_comment_value (v ) )) {
      if (comment_mode & 0x1 )
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      else {
        special_value_need_copy = 0 ; 
        goto start_over ; 
      }
    }
    else if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ) {
#     define XfOrM48_COUNT (0+XfOrM46_COUNT)
#     define SETUP_XfOrM48(x) SETUP_XfOrM46(x)
      if (! stxsrc )
        v = FUNCCALL(SETUP_XfOrM48(_), scheme_syntax_to_datum (v , 0 , ((void * ) 0 ) ) ); 
    }
    else if (stxsrc ) {
      Scheme_Object * s ; 
      BLOCK_SETUP((PUSH(s, 0+XfOrM46_COUNT)));
#     define XfOrM47_COUNT (1+XfOrM46_COUNT)
#     define SETUP_XfOrM47(x) SETUP(XfOrM47_COUNT)
      s = NULLED_OUT ; 
      s = (__funcarg30 = FUNCCALL(SETUP_XfOrM47(_), SPAN (port , pos ) ), FUNCCALL_AGAIN(scheme_make_stx_w_offset (scheme_false , line , col , pos , __funcarg30 , stxsrc , scheme_false ) )) ; 
      v = FUNCCALL_AGAIN(scheme_datum_to_syntax (v , s , scheme_false , 1 , 0 ) ); 
    }
    if (special_value_need_copy )
      v = FUNCCALL(SETUP_XfOrM46(_), copy_to_protect_placeholders (v , stxsrc , ht ) ); 
    RET_VALUE_START (v ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * read_inner (Scheme_Object * port , Scheme_Object * stxsrc , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params , int comment_mode ) {
  /* No conversion */
  return read_inner_inner (port , stxsrc , ht , indentation , params , comment_mode , - 1 , params -> table ) ; 
}
static Scheme_Object * resolve_references (Scheme_Object * obj , Scheme_Object * port , Scheme_Object * * dht , int mkstx , int ph_type ) ; 
static Scheme_Object * resolve_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * o = (Scheme_Object * ) p -> ku . k . p1 ; 
  Scheme_Object * port = (Scheme_Object * ) p -> ku . k . p2 ; 
  Scheme_Object * * dht = (Scheme_Object * * ) p -> ku . k . p3 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  p -> ku . k . p2 = ((void * ) 0 ) ; 
  p -> ku . k . p3 = ((void * ) 0 ) ; 
  return resolve_references (o , port , dht , p -> ku . k . i1 , p -> ku . k . i2 ) ; 
}
static Scheme_Object * resolve_references (Scheme_Object * obj , Scheme_Object * port , Scheme_Object * * dht , int mkstx , int ph_type ) {
  Scheme_Object * result ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(10);
  BLOCK_SETUP_TOP((PUSH(dht, 0), PUSH(obj, 1), PUSH(result, 2), PUSH(port, 3)));
# define XfOrM233_COUNT (4)
# define SETUP_XfOrM233(x) SETUP(XfOrM233_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  result = NULLED_OUT ; 
  {
    unsigned long _stk_pos ; 
#   define XfOrM263_COUNT (0+XfOrM233_COUNT)
#   define SETUP_XfOrM263(x) SETUP_XfOrM233(x)
    _stk_pos = (unsigned long ) & _stk_pos ; 
    if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
      Scheme_Thread * p = scheme_current_thread ; 
#     define XfOrM264_COUNT (0+XfOrM263_COUNT)
#     define SETUP_XfOrM264(x) SETUP_XfOrM263(x)
      p -> ku . k . p1 = (void * ) obj ; 
      p -> ku . k . p2 = (void * ) port ; 
      p -> ku . k . p3 = (void * ) dht ; 
      p -> ku . k . i1 = mkstx ; 
      p -> ku . k . i2 = ph_type ; 
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_handle_stack_overflow (resolve_k ) )) RET_VALUE_EMPTY_END ; 
    }
  }
  {
#   define XfOrM261_COUNT (0+XfOrM233_COUNT)
#   define SETUP_XfOrM261(x) SETUP_XfOrM233(x)
    if ((scheme_fuel_counter ) <= 0 ) {
#     define XfOrM262_COUNT (0+XfOrM261_COUNT)
#     define SETUP_XfOrM262(x) SETUP_XfOrM261(x)
      FUNCCALL(SETUP_XfOrM262(_), scheme_out_of_fuel () ); 
    }
  }
  ; 
  if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (ph_type ) ) ) {
    Scheme_Object * start = obj ; 
#   define XfOrM252_COUNT (0+XfOrM233_COUNT)
#   define SETUP_XfOrM252(x) SETUP_XfOrM233(x)
    while (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (ph_type ) ) ) {
#     define XfOrM257_COUNT (0+XfOrM252_COUNT)
#     define SETUP_XfOrM257(x) SETUP_XfOrM252(x)
      if ((((Scheme_Inclhash_Object * ) (obj ) ) -> so . keyex & 0x1 ) ) {
        break ; 
      }
      else {
#       define XfOrM258_COUNT (0+XfOrM257_COUNT)
#       define SETUP_XfOrM258(x) SETUP_XfOrM257(x)
        obj = (Scheme_Object * ) (((Scheme_Small_Object * ) (obj ) ) -> u . ptr_val ) ; 
        if (((start ) == (obj ) ) ) {
#         define XfOrM259_COUNT (0+XfOrM258_COUNT)
#         define SETUP_XfOrM259(x) SETUP_XfOrM258(x)
          FUNCCALL_EMPTY(scheme_read_err (port , ((void * ) 0 ) , - 1 , - 1 , - 1 , - 1 , 0 , ((void * ) 0 ) , "read: illegal cycle" ) ); 
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        }
      }
    }
    if (! ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (ph_type ) ) )
      RET_VALUE_START (obj ) RET_VALUE_END ; 
    else obj = (Scheme_Object * ) (((Scheme_Small_Object * ) (obj ) ) -> u . ptr_val ) ; 
  }
  result = obj ; 
  if (mkstx && ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ) {
#   define XfOrM249_COUNT (0+XfOrM233_COUNT)
#   define SETUP_XfOrM249(x) SETUP_XfOrM233(x)
    obj = ((Scheme_Stx * ) obj ) -> val ; 
    if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (ph_type ) ) ) {
#     define XfOrM250_COUNT (0+XfOrM249_COUNT)
#     define SETUP_XfOrM250(x) SETUP_XfOrM249(x)
      if (mkstx && ! ((Scheme_Type ) (((((long ) ((((Scheme_Small_Object * ) (obj ) ) -> u . ptr_val ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Small_Object * ) (obj ) ) -> u . ptr_val ) ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ) {
        RET_VALUE_START (result ) RET_VALUE_END ; 
      }
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(resolve_references (obj , port , dht , mkstx , ph_type ) )) RET_VALUE_EMPTY_END ; 
    }
  }
  if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
    Scheme_Object * rr ; 
    BLOCK_SETUP((PUSH(rr, 0+XfOrM233_COUNT)));
#   define XfOrM248_COUNT (1+XfOrM233_COUNT)
#   define SETUP_XfOrM248(x) SETUP(XfOrM248_COUNT)
    rr = NULLED_OUT ; 
    rr = FUNCCALL(SETUP_XfOrM248(_), resolve_references ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) , port , dht , mkstx , ph_type ) ); 
    (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) = rr ; 
    rr = FUNCCALL(SETUP_XfOrM248(_), resolve_references ((((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) , port , dht , mkstx , ph_type ) ); 
    (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) = rr ; 
  }
  else if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) {
    Scheme_Object * rr ; 
    BLOCK_SETUP((PUSH(rr, 0+XfOrM233_COUNT)));
#   define XfOrM247_COUNT (1+XfOrM233_COUNT)
#   define SETUP_XfOrM247(x) SETUP(XfOrM247_COUNT)
    rr = NULLED_OUT ; 
    rr = FUNCCALL(SETUP_XfOrM247(_), resolve_references ((((Scheme_Small_Object * ) (obj ) ) -> u . ptr_val ) , port , dht , mkstx , ph_type ) ); 
    (((Scheme_Small_Object * ) (obj ) ) -> u . ptr_val ) = rr ; 
  }
  else if (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
    int i , len ; 
    Scheme_Object * prev_rr , * prev_v ; 
    BLOCK_SETUP((PUSH(prev_v, 0+XfOrM233_COUNT), PUSH(prev_rr, 1+XfOrM233_COUNT)));
#   define XfOrM240_COUNT (2+XfOrM233_COUNT)
#   define SETUP_XfOrM240(x) SETUP(XfOrM240_COUNT)
    prev_rr = NULLED_OUT ; 
    prev_v = NULLED_OUT ; 
    prev_v = prev_rr = ((void * ) 0 ) ; 
    len = (((Scheme_Vector * ) (obj ) ) -> size ) ; 
    for (i = 0 ; i < len ; i ++ ) {
      Scheme_Object * rr ; 
      BLOCK_SETUP((PUSH(rr, 0+XfOrM240_COUNT)));
#     define XfOrM244_COUNT (1+XfOrM240_COUNT)
#     define SETUP_XfOrM244(x) SETUP(XfOrM244_COUNT)
      rr = NULLED_OUT ; 
      if ((((Scheme_Vector * ) (obj ) ) -> els ) [i ] == prev_v ) {
        rr = prev_rr ; 
      }
      else {
#       define XfOrM245_COUNT (0+XfOrM244_COUNT)
#       define SETUP_XfOrM245(x) SETUP_XfOrM244(x)
        prev_v = (((Scheme_Vector * ) (obj ) ) -> els ) [i ] ; 
        rr = FUNCCALL(SETUP_XfOrM245(_), resolve_references (prev_v , port , dht , mkstx , ph_type ) ); 
        prev_rr = rr ; 
      }
      (((Scheme_Vector * ) (obj ) ) -> els ) [i ] = rr ; 
    }
  }
  else if ((ph_type == scheme_placeholder_type ) && ((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) ) {
    Scheme_Object * l ; 
    Scheme_Hash_Table * t = (Scheme_Hash_Table * ) obj ; 
    BLOCK_SETUP((PUSH(t, 0+XfOrM233_COUNT), PUSH(l, 1+XfOrM233_COUNT)));
#   define XfOrM234_COUNT (2+XfOrM233_COUNT)
#   define SETUP_XfOrM234(x) SETUP(XfOrM234_COUNT)
    l = NULLED_OUT ; 
    l = FUNCCALL(SETUP_XfOrM234(_), scheme_hash_get (t , an_uninterned_symbol ) ); 
    if (l ) {
      Scheme_Object * a , * key , * val ; 
      BLOCK_SETUP((PUSH(val, 0+XfOrM234_COUNT), PUSH(a, 1+XfOrM234_COUNT), PUSH(key, 2+XfOrM234_COUNT)));
#     define XfOrM235_COUNT (3+XfOrM234_COUNT)
#     define SETUP_XfOrM235(x) SETUP(XfOrM235_COUNT)
      a = NULLED_OUT ; 
      key = NULLED_OUT ; 
      val = NULLED_OUT ; 
      ((((Scheme_Inclhash_Object * ) (obj ) ) -> so . keyex |= 0x1 ) ) ; 
      l = FUNCCALL(SETUP_XfOrM235(_), resolve_references (l , port , dht , mkstx , ph_type ) ); 
      if (mkstx && dht ) {
        Scheme_Object * d ; 
        BLOCK_SETUP((PUSH(d, 0+XfOrM235_COUNT)));
#       define XfOrM239_COUNT (1+XfOrM235_COUNT)
#       define SETUP_XfOrM239(x) SETUP(XfOrM239_COUNT)
        d = NULLED_OUT ; 
        FUNCCALL(SETUP_XfOrM239(_), scheme_hash_set (t , an_uninterned_symbol , l ) ); 
        d = FUNCCALL_AGAIN(scheme_make_raw_pair ((Scheme_Object * ) t , * dht ) ); 
        * dht = d ; 
      }
      else {
#       define XfOrM236_COUNT (0+XfOrM235_COUNT)
#       define SETUP_XfOrM236(x) SETUP_XfOrM235(x)
        if (mkstx )
          l = FUNCCALL(SETUP_XfOrM236(_), scheme_syntax_to_datum (l , 0 , ((void * ) 0 ) ) ); 
        FUNCCALL(SETUP_XfOrM236(_), scheme_hash_set (t , an_uninterned_symbol , ((void * ) 0 ) ) ); 
        for (; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#         define XfOrM238_COUNT (0+XfOrM236_COUNT)
#         define SETUP_XfOrM238(x) SETUP_XfOrM236(x)
          a = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
          key = (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) ; 
          val = (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) ; 
          FUNCCALL(SETUP_XfOrM238(_), scheme_hash_set (t , key , val ) ); 
        }
      }
    }
  }
  RET_VALUE_START (result ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void fixup_delayed_hash_tables (Scheme_Object * dht ) {
  Scheme_Hash_Table * t ; 
  Scheme_Object * l , * a , * key , * val ; 
  PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(t, 0), PUSH(dht, 1), PUSH(a, 2), PUSH(val, 3), PUSH(key, 4), PUSH(l, 5)));
# define XfOrM265_COUNT (6)
# define SETUP_XfOrM265(x) SETUP(XfOrM265_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  t = NULLED_OUT ; 
  l = NULLED_OUT ; 
  a = NULLED_OUT ; 
  key = NULLED_OUT ; 
  val = NULLED_OUT ; 
  while (dht ) {
#   define XfOrM269_COUNT (0+XfOrM265_COUNT)
#   define SETUP_XfOrM269(x) SETUP_XfOrM265(x)
    t = (Scheme_Hash_Table * ) (((Scheme_Simple_Object * ) (dht ) ) -> u . pair_val . car ) ; 
    l = FUNCCALL(SETUP_XfOrM269(_), scheme_hash_get (t , an_uninterned_symbol ) ); 
    l = FUNCCALL_AGAIN(scheme_syntax_to_datum (l , 0 , ((void * ) 0 ) ) ); 
    FUNCCALL_AGAIN(scheme_hash_set (t , an_uninterned_symbol , ((void * ) 0 ) ) ); 
    for (; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#     define XfOrM271_COUNT (0+XfOrM269_COUNT)
#     define SETUP_XfOrM271(x) SETUP_XfOrM269(x)
      a = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
      key = (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) ; 
      val = (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) ; 
      FUNCCALL(SETUP_XfOrM271(_), scheme_hash_set (t , key , val ) ); 
    }
    dht = (((Scheme_Simple_Object * ) (dht ) ) -> u . pair_val . cdr ) ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * _scheme_internal_read (Scheme_Object * port , Scheme_Object * stxsrc , int crc , int honu_mode , int recur , int expose_comment , int extra_char , Scheme_Object * init_readtable , Scheme_Object * magic_sym , Scheme_Object * magic_val , Scheme_Object * delay_load_info ) {
  Scheme_Object * v , * v2 ; 
  Scheme_Config * config ; 
  Scheme_Hash_Table * * ht = ((void * ) 0 ) ; 
  ReadParams params ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(16);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(ht, 1), PUSH(init_readtable, 2), PUSH(stxsrc, 3), PUSH(delay_load_info, 4), PUSH(port, 5), PUSH(magic_sym, 6), PUSH(v2, 7), PUSH(config, 8), PUSH(params.table, 9), PUSH(params.magic_sym, 10), PUSH(params.magic_val, 11), PUSH(params.delay_load_info, 12), PUSH(magic_val, 13)));
# define XfOrM272_COUNT (14)
# define SETUP_XfOrM272(x) SETUP(XfOrM272_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  v = NULLED_OUT ; 
  v2 = NULLED_OUT ; 
  config = NULLED_OUT ; 
  params.table = NULLED_OUT ; 
  params.magic_sym = NULLED_OUT ; 
  params.magic_val = NULLED_OUT ; 
  params.delay_load_info = NULLED_OUT ; 
  config = FUNCCALL(SETUP_XfOrM272(_), scheme_current_config () ); 
  v = FUNCCALL_AGAIN(scheme_get_param (config , MZCONFIG_READTABLE ) ); 
  if ((! (((v ) ) == (scheme_false ) ) ) )
    params . table = (Readtable * ) v ; 
  else params . table = ((void * ) 0 ) ; 
  params . can_read_compiled = crc ; 
  v = FUNCCALL(SETUP_XfOrM272(_), scheme_get_param (config , MZCONFIG_CAN_READ_PIPE_QUOTE ) ); 
  params . can_read_pipe_quote = (! (((v ) ) == (scheme_false ) ) ) ; 
  v = FUNCCALL(SETUP_XfOrM272(_), scheme_get_param (config , MZCONFIG_CAN_READ_BOX ) ); 
  params . can_read_box = (! (((v ) ) == (scheme_false ) ) ) ; 
  v = FUNCCALL(SETUP_XfOrM272(_), scheme_get_param (config , MZCONFIG_CAN_READ_GRAPH ) ); 
  params . can_read_graph = (! (((v ) ) == (scheme_false ) ) ) ; 
  if (crc ) {
    params . can_read_reader = 1 ; 
  }
  else {
#   define XfOrM285_COUNT (0+XfOrM272_COUNT)
#   define SETUP_XfOrM285(x) SETUP_XfOrM272(x)
    v = FUNCCALL(SETUP_XfOrM285(_), scheme_get_param (config , MZCONFIG_CAN_READ_READER ) ); 
    params . can_read_reader = (! (((v ) ) == (scheme_false ) ) ) ; 
  }
  v = FUNCCALL(SETUP_XfOrM272(_), scheme_get_param (config , MZCONFIG_CASE_SENS ) ); 
  params . case_sensitive = (! (((v ) ) == (scheme_false ) ) ) ; 
  v = FUNCCALL(SETUP_XfOrM272(_), scheme_get_param (config , MZCONFIG_SQUARE_BRACKETS_ARE_PARENS ) ); 
  params . square_brackets_are_parens = (! (((v ) ) == (scheme_false ) ) ) ; 
  v = FUNCCALL(SETUP_XfOrM272(_), scheme_get_param (config , MZCONFIG_CURLY_BRACES_ARE_PARENS ) ); 
  params . curly_braces_are_parens = (! (((v ) ) == (scheme_false ) ) ) ; 
  v = FUNCCALL(SETUP_XfOrM272(_), scheme_get_param (config , MZCONFIG_READ_DECIMAL_INEXACT ) ); 
  params . read_decimal_inexact = (! (((v ) ) == (scheme_false ) ) ) ; 
  v = FUNCCALL(SETUP_XfOrM272(_), scheme_get_param (config , MZCONFIG_CAN_READ_QUASI ) ); 
  params . can_read_quasi = (! (((v ) ) == (scheme_false ) ) ) ; 
  v = FUNCCALL(SETUP_XfOrM272(_), scheme_get_param (config , MZCONFIG_CAN_READ_DOT ) ); 
  params . can_read_dot = (! (((v ) ) == (scheme_false ) ) ) ; 
  v = FUNCCALL(SETUP_XfOrM272(_), scheme_get_param (config , MZCONFIG_CAN_READ_INFIX_DOT ) ); 
  params . can_read_infix_dot = (! (((v ) ) == (scheme_false ) ) ) ; 
  if (! delay_load_info )
    delay_load_info = FUNCCALL(SETUP_XfOrM272(_), scheme_get_param (config , MZCONFIG_DELAY_LOAD_INFO ) ); 
  if ((! (((delay_load_info ) ) == (scheme_false ) ) ) )
    params . delay_load_info = delay_load_info ; 
  else params . delay_load_info = ((void * ) 0 ) ; 
  params . honu_mode = honu_mode ; 
  if (honu_mode )
    params . table = ((void * ) 0 ) ; 
  params . magic_sym = magic_sym ; 
  params . magic_val = magic_val ; 
  ht = ((void * ) 0 ) ; 
  if (recur ) {
#   define XfOrM283_COUNT (0+XfOrM272_COUNT)
#   define SETUP_XfOrM283(x) SETUP_XfOrM272(x)
    v = FUNCCALL(SETUP_XfOrM283(_), scheme_extract_one_cc_mark (((void * ) 0 ) , an_uninterned_symbol ) ); 
    if (v && ((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_raw_pair_type ) ) ) {
      if (((((((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) ) ) == (scheme_false ) ) == ! stxsrc )
        ht = (Scheme_Hash_Table * * ) (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) ; 
    }
  }
  if (! ht ) {
#   define XfOrM282_COUNT (0+XfOrM272_COUNT)
#   define SETUP_XfOrM282(x) SETUP_XfOrM272(x)
    ht = ((Scheme_Hash_Table * * ) FUNCCALL(SETUP_XfOrM282(_), GC_malloc (sizeof (Scheme_Hash_Table * ) * (1 ) ) )) ; 
    recur = 0 ; 
  }
  do {
#   define XfOrM279_COUNT (0+XfOrM272_COUNT)
#   define SETUP_XfOrM279(x) SETUP_XfOrM272(x)
    v = FUNCCALL(SETUP_XfOrM279(_), read_inner_inner (port , stxsrc , ht , scheme_null , & params , (0x2 | (expose_comment ? (0x8 | 0x1 ) : 0 ) ) , extra_char , (init_readtable ? ((((init_readtable ) ) == (scheme_false ) ) ? ((void * ) 0 ) : (Readtable * ) init_readtable ) : params . table ) ) ); 
    extra_char = - 1 ; 
    if (* ht && ! recur ) {
      Scheme_Object * dht = ((void * ) 0 ) ; 
      BLOCK_SETUP((PUSH(dht, 0+XfOrM279_COUNT)));
#     define XfOrM281_COUNT (1+XfOrM279_COUNT)
#     define SETUP_XfOrM281(x) SETUP(XfOrM281_COUNT)
      if (v )
        v = FUNCCALL(SETUP_XfOrM281(_), resolve_references (v , port , & dht , ! ! stxsrc , scheme_placeholder_type ) ); 
      v2 = FUNCCALL(SETUP_XfOrM281(_), scheme_hash_get (* ht , an_uninterned_symbol ) ); 
      if (v2 )
        FUNCCALL(SETUP_XfOrM281(_), resolve_references (v2 , port , & dht , ! ! stxsrc , scheme_placeholder_type ) ); 
      if (! v )
        * ht = ((void * ) 0 ) ; 
      FUNCCALL(SETUP_XfOrM281(_), fixup_delayed_hash_tables (dht ) ); 
    }
    if (! v && expose_comment ) {
#     define XfOrM280_COUNT (0+XfOrM279_COUNT)
#     define SETUP_XfOrM280(x) SETUP_XfOrM279(x)
      v = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM280(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
      v -> type = scheme_special_comment_type ; 
      (((Scheme_Small_Object * ) (v ) ) -> u . ptr_val ) = scheme_false ; 
      RET_VALUE_START (v ) RET_VALUE_END ; 
    }
  }
  while (! v ) ; 
  if (recur ) {
    Scheme_Object * ph ; 
    BLOCK_SETUP((PUSH(ph, 0+XfOrM272_COUNT)));
#   define XfOrM273_COUNT (1+XfOrM272_COUNT)
#   define SETUP_XfOrM273(x) SETUP(XfOrM273_COUNT)
    ph = NULLED_OUT ; 
    if (! (((v ) ) == (scheme_eof ) ) && ! ((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_placeholder_type ) ) ) {
#     define XfOrM274_COUNT (0+XfOrM273_COUNT)
#     define SETUP_XfOrM274(x) SETUP_XfOrM273(x)
      if (! * ht ) {
        Scheme_Hash_Table * tht ; 
        BLOCK_SETUP((PUSH(tht, 0+XfOrM274_COUNT)));
#       define XfOrM275_COUNT (1+XfOrM274_COUNT)
#       define SETUP_XfOrM275(x) SETUP(XfOrM275_COUNT)
        tht = NULLED_OUT ; 
        tht = FUNCCALL(SETUP_XfOrM275(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
        * ht = tht ; 
      }
      ph = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM274(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
      ph -> type = scheme_placeholder_type ; 
      (((Scheme_Small_Object * ) (ph ) ) -> u . ptr_val ) = v ; 
      ((((Scheme_Inclhash_Object * ) (ph ) ) -> so . keyex |= 0x1 ) ) ; 
      v = ph ; 
    }
  }
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void * scheme_internal_read_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * port = (Scheme_Object * ) p -> ku . k . p1 ; 
  Scheme_Object * stxsrc = (Scheme_Object * ) p -> ku . k . p2 ; 
  Scheme_Object * init_readtable = (Scheme_Object * ) p -> ku . k . p3 ; 
  Scheme_Object * magic_sym = (Scheme_Object * ) p -> ku . k . p4 ; 
  Scheme_Object * magic_val = ((void * ) 0 ) ; 
  Scheme_Object * delay_load_info = (Scheme_Object * ) p -> ku . k . p5 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  p -> ku . k . p2 = ((void * ) 0 ) ; 
  p -> ku . k . p3 = ((void * ) 0 ) ; 
  p -> ku . k . p4 = ((void * ) 0 ) ; 
  p -> ku . k . p5 = ((void * ) 0 ) ; 
  if (magic_sym ) {
    magic_val = (((Scheme_Simple_Object * ) (magic_sym ) ) -> u . pair_val . cdr ) ; 
    magic_sym = (((Scheme_Simple_Object * ) (magic_sym ) ) -> u . pair_val . car ) ; 
  }
  return (void * ) _scheme_internal_read (port , stxsrc , p -> ku . k . i1 , p -> ku . k . i2 , p -> ku . k . i3 & 0x2 , p -> ku . k . i3 & 0x1 , p -> ku . k . i4 , init_readtable , magic_sym , magic_val , delay_load_info ) ; 
}
Scheme_Object * scheme_internal_read (Scheme_Object * port , Scheme_Object * stxsrc , int crc , int cantfail , int honu_mode , int recur , int expose_comment , int pre_char , Scheme_Object * init_readtable , Scheme_Object * magic_sym , Scheme_Object * magic_val , Scheme_Object * delay_load_info ) {
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Config * __funcarg50 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSH(init_readtable, 0), PUSH(stxsrc, 1), PUSH(delay_load_info, 2), PUSH(port, 3), PUSH(magic_sym, 4), PUSH(p, 5), PUSH(magic_val, 6)));
# define XfOrM289_COUNT (7)
# define SETUP_XfOrM289(x) SETUP(XfOrM289_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (crc < 0 )
    crc = (! ((((__funcarg50 = FUNCCALL(SETUP_XfOrM289(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg50 , MZCONFIG_CAN_READ_COMPILED ) )) ) ) == (scheme_false ) ) ) ; 
  if (0 )
    FUNCCALL(SETUP_XfOrM289(_), scheme_alloc_list_stack (p ) ); 
  if (cantfail ) {
#   define XfOrM291_COUNT (0+XfOrM289_COUNT)
#   define SETUP_XfOrM291(x) SETUP_XfOrM289(x)
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(_scheme_internal_read (port , stxsrc , crc , honu_mode , recur , expose_comment , - 1 , ((void * ) 0 ) , magic_sym , magic_val , delay_load_info ) )) RET_VALUE_EMPTY_END ; 
  }
  else {
#   define XfOrM290_COUNT (0+XfOrM289_COUNT)
#   define SETUP_XfOrM290(x) SETUP_XfOrM289(x)
    if (magic_sym )
      magic_sym = FUNCCALL(SETUP_XfOrM290(_), scheme_make_pair (magic_sym , magic_val ) ); 
    p -> ku . k . p1 = (void * ) port ; 
    p -> ku . k . p2 = (void * ) stxsrc ; 
    p -> ku . k . i1 = crc ; 
    p -> ku . k . i2 = honu_mode ; 
    p -> ku . k . i3 = ((recur ? 0x2 : 0 ) | (expose_comment ? 0x1 : 0 ) ) ; 
    p -> ku . k . i4 = pre_char ; 
    p -> ku . k . p3 = (void * ) init_readtable ; 
    p -> ku . k . p4 = (void * ) magic_sym ; 
    p -> ku . k . p5 = (void * ) delay_load_info ; 
    RET_VALUE_START ((Scheme_Object * ) FUNCCALL_EMPTY(scheme_top_level_do (scheme_internal_read_k , 0 ) )) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_read (Scheme_Object * port ) {
  /* No conversion */
  return scheme_internal_read (port , ((void * ) 0 ) , - 1 , 0 , 0 , 0 , 0 , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) ) ; 
}
Scheme_Object * scheme_read_syntax (Scheme_Object * port , Scheme_Object * stxsrc ) {
  /* No conversion */
  return scheme_internal_read (port , stxsrc , - 1 , 0 , 0 , 0 , 0 , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) ) ; 
}
Scheme_Object * scheme_resolve_placeholders (Scheme_Object * obj , int mkstx , Scheme_Type ph_type ) {
  /* No conversion */
  return resolve_references (obj , ((void * ) 0 ) , ((void * ) 0 ) , mkstx , ph_type ) ; 
}
static Scheme_Object * attach_shape_property (Scheme_Object * list , Scheme_Object * stxsrc , ReadParams * params , int closer ) ; 
static int next_is_delim (Scheme_Object * port , ReadParams * params , int brackets , int braces ) {
  int next ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(params, 0)));
# define XfOrM295_COUNT (1)
# define SETUP_XfOrM295(x) SETUP(XfOrM295_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  next = FUNCCALL(SETUP_XfOrM295(_), scheme_peekc_special_ok (port ) ); 
  RET_VALUE_START (((next == (- 1 ) ) || (next == (- 2 ) ) || (! params -> table && ((((scheme_uchar_table [(next >> 8 ) & 0x1FFF ] [next & 0xFF ] ) ) & 0x10 ) || (next == '(' ) || (next == ')' ) || (next == '"' ) || (next == ';' ) || (next == '\'' ) || (next == '`' ) || (next == ',' ) || ((next == '[' ) && brackets ) || ((next == '{' ) && braces ) || ((next == ']' ) && brackets ) || ((next == '}' ) && braces ) ) ) || (params -> table && (FUNCCALL_EMPTY(readtable_kind (params -> table , next , params ) )& (0x1 | 0x4 ) ) ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static const char * mapping_name (ReadParams * params , int ch , const char * def , int name_pos ) {
  DECL_RET_SAVE (const char * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(def, 0), PUSH(params, 1)));
# define XfOrM296_COUNT (2)
# define SETUP_XfOrM296(x) SETUP(XfOrM296_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (params -> table ) {
    int i ; 
    char * buf = "" ; 
    Scheme_Object * v ; 
    Scheme_Hash_Table * mapping ; 
    BLOCK_SETUP((PUSH(buf, 0+XfOrM296_COUNT), PUSH(v, 1+XfOrM296_COUNT), PUSH(mapping, 2+XfOrM296_COUNT)));
#   define XfOrM297_COUNT (3+XfOrM296_COUNT)
#   define SETUP_XfOrM297(x) SETUP(XfOrM297_COUNT)
    v = NULLED_OUT ; 
    mapping = NULLED_OUT ; 
    if (params -> table -> names ) {
      if (params -> table -> names [name_pos ] )
        RET_VALUE_START (params -> table -> names [name_pos ] ) RET_VALUE_END ; 
    }
    mapping = params -> table -> mapping ; 
    if (! FUNCCALL(SETUP_XfOrM297(_), scheme_hash_get (mapping , ((Scheme_Object * ) (void * ) (long ) ((((long ) (ch ) ) << 1 ) | 0x1 ) ) ) )) {
#     define XfOrM307_COUNT (0+XfOrM297_COUNT)
#     define SETUP_XfOrM307(x) SETUP_XfOrM297(x)
      buf = (char * ) FUNCCALL(SETUP_XfOrM307(_), GC_malloc_atomic (4 ) ); 
      (sprintf (buf , "`%c'" , ch ) ) ; 
    }
    for (i = mapping -> size ; i -- ; ) {
#     define XfOrM303_COUNT (0+XfOrM297_COUNT)
#     define SETUP_XfOrM303(x) SETUP_XfOrM297(x)
      if (mapping -> vals [i ] ) {
#       define XfOrM304_COUNT (0+XfOrM303_COUNT)
#       define SETUP_XfOrM304(x) SETUP_XfOrM303(x)
        v = mapping -> vals [i ] ; 
        if (((((long ) ((((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) ) ) >> 1 ) == 0x20 ) && ((((long ) ((((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) ) ) >> 1 ) == ch ) ) {
          int len ; 
          mzchar a [2 ] ; 
          char * naya , utf8_buf [6 + 1 ] ; 
          BLOCK_SETUP((PUSH(naya, 0+XfOrM304_COUNT)));
#         define XfOrM305_COUNT (1+XfOrM304_COUNT)
#         define SETUP_XfOrM305(x) SETUP(XfOrM305_COUNT)
          naya = NULLED_OUT ; 
          v = mapping -> keys [i ] ; 
          a [0 ] = (mzchar ) (((long ) (v ) ) >> 1 ) ; 
          len = FUNCCALL(SETUP_XfOrM305(_), scheme_utf8_encode_all (a , 1 , (unsigned char * ) utf8_buf ) ); 
          utf8_buf [len ] = 0 ; 
          naya = (char * ) FUNCCALL(SETUP_XfOrM305(_), GC_malloc_atomic (len + 5 + strlen (buf ) ) ); 
          (sprintf (naya , "`%s'" , utf8_buf ) ) ; 
          if (* buf ) {
#           define XfOrM306_COUNT (0+XfOrM305_COUNT)
#           define SETUP_XfOrM306(x) SETUP_XfOrM305(x)
            (sprintf (naya XFORM_OK_PLUS len + 2 , " or %s" , buf ) ) ; 
          }
          buf = naya ; 
        }
      }
    }
    if (! params -> table -> names ) {
      char * * a ; 
      BLOCK_SETUP((PUSH(a, 0+XfOrM297_COUNT)));
#     define XfOrM298_COUNT (1+XfOrM297_COUNT)
#     define SETUP_XfOrM298(x) SETUP(XfOrM298_COUNT)
      a = NULLED_OUT ; 
      a = ((char * * ) FUNCCALL(SETUP_XfOrM298(_), GC_malloc (sizeof (char * ) * (7 ) ) )) ; 
      params -> table -> names = a ; 
    }
    params -> table -> names [name_pos ] = buf ; 
    RET_VALUE_START (buf ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (def ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static const char * closer_name (ReadParams * params , int closer ) {
  /* No conversion */
  int pos ; 
  const char * def ; 
  switch (closer ) {
    case ')' : pos = 0 ; 
    def = "`)'" ; 
    break ; 
    case ']' : pos = 1 ; 
    def = "`]'" ; 
    break ; 
    case '}' : default : pos = 2 ; 
    def = "`}'" ; 
    break ; 
  }
  return mapping_name (params , closer , def , pos ) ; 
}
static const char * opener_name (ReadParams * params , int opener ) {
  /* No conversion */
  int pos ; 
  const char * def ; 
  switch (opener ) {
    case '(' : pos = 3 ; 
    def = "`('" ; 
    break ; 
    case '[' : pos = 4 ; 
    def = "`['" ; 
    break ; 
    case '{' : default : pos = 5 ; 
    def = "`{'" ; 
    break ; 
  }
  return mapping_name (params , opener , def , pos ) ; 
}
static const char * dot_name (ReadParams * params ) {
  /* No conversion */
  return mapping_name (params , '.' , "`.'" , 6 ) ; 
}
static Scheme_Object * combine_angle_brackets (Scheme_Object * list ) ; 
static Scheme_Object * honu_add_module_wrapper (Scheme_Object * list , Scheme_Object * stxsrc , Scheme_Object * port ) ; 
static Scheme_Object * read_list (Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , int closer , int shape , int use_stack , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params ) {
  Scheme_Object * list = ((void * ) 0 ) , * last = ((void * ) 0 ) , * car , * cdr , * pair , * infixed = ((void * ) 0 ) , * prefetched = ((void * ) 0 ) ; 
  int ch = 0 , got_ch_already = 0 , effective_ch ; 
  int brackets = params -> square_brackets_are_parens ; 
  int braces = params -> curly_braces_are_parens ; 
  long start , startcol , startline , dotpos , dotcol , dotline , dot2pos , dot2line , dot2col ; 
  const char * __funcarg82 = NULLED_OUT ; 
  const char * __funcarg81 = NULLED_OUT ; 
  long __funcarg80 ; 
  const char * __funcarg79 = NULLED_OUT ; 
  long __funcarg78 ; 
  long __funcarg77 ; 
  long __funcarg76 ; 
  const char * __funcarg75 = NULLED_OUT ; 
  const char * __funcarg74 = NULLED_OUT ; 
  long __funcarg73 ; 
  long __funcarg72 ; 
  const char * __funcarg71 = NULLED_OUT ; 
  long __funcarg70 ; 
  long __funcarg69 ; 
  const char * __funcarg68 = NULLED_OUT ; 
  long __funcarg67 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(14);
  BLOCK_SETUP_TOP((PUSH(car, 0), PUSH(indentation, 1), PUSH(params, 2), PUSH(stxsrc, 3), PUSH(prefetched, 4), PUSH(infixed, 5), PUSH(port, 6), PUSH(list, 7), PUSH(last, 8), PUSH(cdr, 9), PUSH(pair, 10), PUSH(ht, 11)));
# define XfOrM314_COUNT (12)
# define SETUP_XfOrM314(x) SETUP(XfOrM314_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  car = NULLED_OUT ; 
  cdr = NULLED_OUT ; 
  pair = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM314(_), scheme_tell_all (port , & startline , & startcol , & start ) ); 
  if (stxsrc ) {
    Scheme_Indent * indt ; 
    BLOCK_SETUP((PUSH(indt, 0+XfOrM314_COUNT)));
#   define XfOrM387_COUNT (1+XfOrM314_COUNT)
#   define SETUP_XfOrM387(x) SETUP(XfOrM387_COUNT)
    indt = NULLED_OUT ; 
    indt = (Scheme_Indent * ) FUNCCALL(SETUP_XfOrM387(_), GC_malloc_one_tagged (sizeof (Scheme_Indent ) ) ); 
    indt -> type = scheme_indent_type ; 
    indt -> closer = closer ; 
    indt -> max_indent = startcol + 1 ; 
    indt -> multiline = 0 ; 
    indt -> suspicious_line = 0 ; 
    indt -> suspicious_quote = 0 ; 
    indt -> start_line = startline ; 
    indt -> last_line = startline ; 
    indentation = FUNCCALL(SETUP_XfOrM387(_), scheme_make_pair ((Scheme_Object * ) indt , indentation ) ); 
  }
  while (1 ) {
#   define XfOrM351_COUNT (0+XfOrM314_COUNT)
#   define SETUP_XfOrM351(x) SETUP_XfOrM314(x)
    if (prefetched )
      ch = 0 ; 
    else if (got_ch_already )
      got_ch_already = 0 ; 
    else ch = FUNCCALL(SETUP_XfOrM351(_), skip_whitespace_comments (port , stxsrc , ht , indentation , params ) ); 
    if ((ch == (- 1 ) ) && (closer != (- 1 ) ) ) {
      char * suggestion = "" ; 
      BLOCK_SETUP((PUSH(suggestion, 0+XfOrM351_COUNT)));
#     define XfOrM384_COUNT (1+XfOrM351_COUNT)
#     define SETUP_XfOrM384(x) SETUP(XfOrM384_COUNT)
      if (((Scheme_Type ) (((((long ) (indentation ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (indentation ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
        Scheme_Indent * indt ; 
        BLOCK_SETUP((PUSH(indt, 0+XfOrM384_COUNT)));
#       define XfOrM385_COUNT (1+XfOrM384_COUNT)
#       define SETUP_XfOrM385(x) SETUP(XfOrM385_COUNT)
        indt = NULLED_OUT ; 
        indt = (Scheme_Indent * ) (((Scheme_Simple_Object * ) (indentation ) ) -> u . pair_val . car ) ; 
        if (indt -> suspicious_line ) {
#         define XfOrM386_COUNT (0+XfOrM385_COUNT)
#         define SETUP_XfOrM386(x) SETUP_XfOrM385(x)
          suggestion = FUNCCALL(SETUP_XfOrM386(_), GC_malloc_atomic (100 ) ); 
          (__funcarg82 = FUNCCALL(SETUP_XfOrM386(_), closer_name (params , indt -> suspicious_closer ) ), (sprintf (suggestion , "; indentation suggests a missing %s before line %ld" , __funcarg82 , indt -> suspicious_line ) ) ) ; 
        }
      }
      (__funcarg80 = FUNCCALL(SETUP_XfOrM384(_), SPAN (port , start ) ), __funcarg81 = FUNCCALL(SETUP_XfOrM384(_), closer_name (params , closer ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , startline , startcol , start , __funcarg80 , (- 1 ) , indentation , "read: expected a %s%s" , __funcarg81 , suggestion ) )) ; 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    effective_ch = FUNCCALL(SETUP_XfOrM351(_), readtable_effective_char (params -> table , ch ) ); 
    if (effective_ch == closer ) {
#     define XfOrM377_COUNT (0+XfOrM351_COUNT)
#     define SETUP_XfOrM377(x) SETUP_XfOrM351(x)
      if (shape == 3 ) {
#       define XfOrM383_COUNT (0+XfOrM377_COUNT)
#       define SETUP_XfOrM383(x) SETUP_XfOrM377(x)
        (__funcarg78 = FUNCCALL(SETUP_XfOrM383(_), SPAN (port , start ) ), __funcarg79 = FUNCCALL(SETUP_XfOrM383(_), dot_name (params ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , startline , startcol , start , __funcarg78 , ch , indentation , "read: expected hash pair (with key and value separated by %s) before `%c'" , __funcarg79 , ch ) )) ; 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      if (params -> honu_mode ) {
#       define XfOrM381_COUNT (0+XfOrM377_COUNT)
#       define SETUP_XfOrM381(x) SETUP_XfOrM377(x)
        if (! list )
          list = scheme_null ; 
        if (closer == ')' )
          car = honu_parens ; 
        else if (closer == ']' )
          car = honu_brackets ; 
        else if (closer == '}' )
          car = honu_braces ; 
        else car = ((void * ) 0 ) ; 
        if (car ) {
#         define XfOrM382_COUNT (0+XfOrM381_COUNT)
#         define SETUP_XfOrM382(x) SETUP_XfOrM381(x)
          if (stxsrc )
            car = (__funcarg77 = FUNCCALL(SETUP_XfOrM382(_), SPAN (port , pos ) ), FUNCCALL_AGAIN(scheme_make_stx_w_offset (car , line , col , pos , __funcarg77 , stxsrc , scheme_false ) )) ; 
          list = FUNCCALL(SETUP_XfOrM382(_), scheme_make_pair (car , list ) ); 
          if (stxsrc )
            ((((Scheme_Inclhash_Object * ) (list ) ) -> so . keyex |= 0x1 ) ) ; 
        }
      }
      else {
        if (! list ) {
          list = scheme_null ; 
        }
      }
      FUNCCALL(SETUP_XfOrM377(_), pop_indentation (indentation ) ); 
      list = FUNCCALL(SETUP_XfOrM377(_), combine_angle_brackets (list ) ); 
      list = (stxsrc ? (__funcarg76 = FUNCCALL(SETUP_XfOrM377(_), SPAN (port , pos ) ), FUNCCALL_AGAIN(scheme_make_stx_w_offset (list , line , col , pos , __funcarg76 , stxsrc , scheme_false ) )) : list ) ; 
      if (params -> honu_mode && (closer == (- 1 ) ) ) {
#       define XfOrM378_COUNT (0+XfOrM377_COUNT)
#       define SETUP_XfOrM378(x) SETUP_XfOrM377(x)
        list = FUNCCALL(SETUP_XfOrM378(_), honu_add_module_wrapper (list , stxsrc , port ) ); 
      }
      list = FUNCCALL(SETUP_XfOrM377(_), attach_shape_property (list , stxsrc , params , closer ) ); 
      RET_VALUE_START (list ) RET_VALUE_END ; 
    }
    if (shape == 2 ) {
#     define XfOrM374_COUNT (0+XfOrM351_COUNT)
#     define SETUP_XfOrM374(x) SETUP_XfOrM351(x)
      if (! (effective_ch == '(' ) && ! (effective_ch == '[' && params -> square_brackets_are_parens ) && ! (effective_ch == '{' && params -> curly_braces_are_parens ) ) {
        long xl , xc , xp ; 
        const char * sbname , * cbname ; 
        BLOCK_SETUP((PUSH(cbname, 0+XfOrM374_COUNT), PUSH(sbname, 1+XfOrM374_COUNT)));
#       define XfOrM376_COUNT (2+XfOrM374_COUNT)
#       define SETUP_XfOrM376(x) SETUP(XfOrM376_COUNT)
        sbname = NULLED_OUT ; 
        cbname = NULLED_OUT ; 
        FUNCCALL(SETUP_XfOrM376(_), scheme_ungetc (ch , port ) ); 
        prefetched = FUNCCALL_AGAIN(read_inner (port , stxsrc , ht , indentation , params , 0x1 | 0x10 ) ); 
        if (! prefetched )
          continue ; 
        sbname = (params -> square_brackets_are_parens ? FUNCCALL(SETUP_XfOrM376(_), opener_name (params , '[' ) ): "" ) ; 
        cbname = (params -> curly_braces_are_parens ? FUNCCALL(SETUP_XfOrM376(_), opener_name (params , '{' ) ): "" ) ; 
        FUNCCALL(SETUP_XfOrM376(_), scheme_tell_all (port , & xl , & xc , & xp ) ); 
        (__funcarg75 = FUNCCALL(SETUP_XfOrM376(_), opener_name (params , '(' ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , xl , xc , xp , 1 , ch , indentation , "read: expected %s%s%s%s%s to start a hash pair" , __funcarg75 , params -> square_brackets_are_parens ? " or " : "" , sbname , params -> curly_braces_are_parens ? " or " : "" , cbname ) )) ; 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      else {
        long xl , xc , xp ; 
#       define XfOrM375_COUNT (0+XfOrM374_COUNT)
#       define SETUP_XfOrM375(x) SETUP_XfOrM374(x)
        FUNCCALL(SETUP_XfOrM375(_), scheme_tell_all (port , & xl , & xc , & xp ) ); 
        car = FUNCCALL(SETUP_XfOrM375(_), read_list (port , stxsrc , xl , xc , xp , ((effective_ch == '(' ) ? ')' : ((effective_ch == '[' ) ? ']' : '}' ) ) , 3 , use_stack , ht , indentation , params ) ); 
      }
    }
    else {
#     define XfOrM371_COUNT (0+XfOrM351_COUNT)
#     define SETUP_XfOrM371(x) SETUP_XfOrM351(x)
      if (prefetched ) {
        car = prefetched ; 
        prefetched = ((void * ) 0 ) ; 
      }
      else {
#       define XfOrM372_COUNT (0+XfOrM371_COUNT)
#       define SETUP_XfOrM372(x) SETUP_XfOrM371(x)
        FUNCCALL(SETUP_XfOrM372(_), scheme_ungetc (ch , port ) ); 
        car = FUNCCALL(SETUP_XfOrM372(_), read_inner (port , stxsrc , ht , indentation , params , 0x1 | 0x10 ) ); 
        if (! car )
          continue ; 
      }
    }
    if (0 ) {
#     define XfOrM369_COUNT (0+XfOrM351_COUNT)
#     define SETUP_XfOrM369(x) SETUP_XfOrM351(x)
      if ((scheme_current_thread -> list_stack_pos ) >= 500 ) {
        Scheme_Simple_Object * sa ; 
        BLOCK_SETUP((PUSH(sa, 0+XfOrM369_COUNT)));
#       define XfOrM370_COUNT (1+XfOrM369_COUNT)
#       define SETUP_XfOrM370(x) SETUP(XfOrM370_COUNT)
        sa = NULLED_OUT ; 
        sa = FUNCCALL(SETUP_XfOrM370(_), malloc_list_stack () ); 
        (scheme_current_thread -> list_stack ) = sa ; 
        (scheme_current_thread -> list_stack_pos ) = 0 ; 
      }
      pair = (Scheme_Object * ) ((scheme_current_thread -> list_stack ) + ((scheme_current_thread -> list_stack_pos ) ++ ) ) ; 
      pair -> type = scheme_pair_type ; 
      (((Scheme_Simple_Object * ) (pair ) ) -> u . pair_val . car ) = car ; 
      (((Scheme_Simple_Object * ) (pair ) ) -> u . pair_val . cdr ) = scheme_null ; 
    }
    else {
#     define XfOrM368_COUNT (0+XfOrM351_COUNT)
#     define SETUP_XfOrM368(x) SETUP_XfOrM351(x)
      pair = FUNCCALL(SETUP_XfOrM368(_), scheme_make_pair (car , scheme_null ) ); 
      if (stxsrc )
        ((((Scheme_Inclhash_Object * ) (pair ) ) -> so . keyex |= 0x1 ) ) ; 
    }
    retry_before_dot : ch = FUNCCALL(SETUP_XfOrM351(_), skip_whitespace_comments (port , stxsrc , ht , indentation , params ) ); 
    effective_ch = FUNCCALL(SETUP_XfOrM351(_), readtable_effective_char (params -> table , ch ) ); 
    if ((effective_ch == closer ) && ! params -> honu_mode ) {
#     define XfOrM365_COUNT (0+XfOrM351_COUNT)
#     define SETUP_XfOrM365(x) SETUP_XfOrM351(x)
      if (shape == 3 ) {
#       define XfOrM367_COUNT (0+XfOrM365_COUNT)
#       define SETUP_XfOrM367(x) SETUP_XfOrM365(x)
        (__funcarg73 = FUNCCALL(SETUP_XfOrM367(_), SPAN (port , start ) ), __funcarg74 = FUNCCALL(SETUP_XfOrM367(_), dot_name (params ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , startline , startcol , start , __funcarg73 , ch , indentation , "read: expected %s and value for hash before `%c'" , __funcarg74 , ch ) )) ; 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      cdr = pair ; 
      if (! list )
        list = cdr ; 
      else (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = cdr ; 
      if (infixed ) {
#       define XfOrM366_COUNT (0+XfOrM365_COUNT)
#       define SETUP_XfOrM366(x) SETUP_XfOrM365(x)
        list = FUNCCALL(SETUP_XfOrM366(_), scheme_make_pair (infixed , list ) ); 
        if (stxsrc )
          ((((Scheme_Inclhash_Object * ) (list ) ) -> so . keyex |= 0x1 ) ) ; 
      }
      FUNCCALL(SETUP_XfOrM365(_), pop_indentation (indentation ) ); 
      if (params -> honu_mode )
        list = FUNCCALL(SETUP_XfOrM365(_), combine_angle_brackets (list ) ); 
      list = (stxsrc ? (__funcarg72 = FUNCCALL(SETUP_XfOrM365(_), SPAN (port , pos ) ), FUNCCALL_AGAIN(scheme_make_stx_w_offset (list , line , col , pos , __funcarg72 , stxsrc , scheme_false ) )) : list ) ; 
      list = FUNCCALL(SETUP_XfOrM365(_), attach_shape_property (list , stxsrc , params , closer ) ); 
      RET_VALUE_START (list ) RET_VALUE_END ; 
    }
    else if (! params -> honu_mode && params -> can_read_dot && (effective_ch == '.' ) && FUNCCALL(SETUP_XfOrM351(_), next_is_delim (port , params , brackets , braces ) )) {
      int dot_ch = ch ; 
#     define XfOrM356_COUNT (0+XfOrM351_COUNT)
#     define SETUP_XfOrM356(x) SETUP_XfOrM351(x)
      FUNCCALL(SETUP_XfOrM356(_), scheme_tell_all (port , & dotline , & dotcol , & dotpos ) ); 
      FUNCCALL(SETUP_XfOrM356(_), track_indentation (indentation , dotline , dotcol ) ); 
      if (((shape != 0 ) && (shape != 3 ) ) || infixed ) {
#       define XfOrM364_COUNT (0+XfOrM356_COUNT)
#       define SETUP_XfOrM364(x) SETUP_XfOrM356(x)
        FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , dotline , dotcol , dotpos , 1 , 0 , indentation , "read: illegal use of `%c'" , dot_ch ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      cdr = FUNCCALL(SETUP_XfOrM356(_), read_inner (port , stxsrc , ht , indentation , params , 0x10 ) ); 
      ch = FUNCCALL(SETUP_XfOrM356(_), skip_whitespace_comments (port , stxsrc , ht , indentation , params ) ); 
      effective_ch = FUNCCALL_AGAIN(readtable_effective_char (params -> table , ch ) ); 
      if (effective_ch != closer ) {
#       define XfOrM358_COUNT (0+XfOrM356_COUNT)
#       define SETUP_XfOrM358(x) SETUP_XfOrM356(x)
        if (params -> can_read_infix_dot && (effective_ch == '.' ) && FUNCCALL(SETUP_XfOrM358(_), next_is_delim (port , params , brackets , braces ) )) {
#         define XfOrM360_COUNT (0+XfOrM358_COUNT)
#         define SETUP_XfOrM360(x) SETUP_XfOrM358(x)
          if (shape == 3 ) {
#           define XfOrM363_COUNT (0+XfOrM360_COUNT)
#           define SETUP_XfOrM363(x) SETUP_XfOrM360(x)
            (__funcarg70 = FUNCCALL(SETUP_XfOrM363(_), SPAN (port , start ) ), __funcarg71 = FUNCCALL(SETUP_XfOrM363(_), closer_name (params , closer ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , startline , startcol , start , __funcarg70 , ch , indentation , "read: expected %s after hash value" , __funcarg71 ) )) ; 
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          }
          {
#           define XfOrM362_COUNT (0+XfOrM360_COUNT)
#           define SETUP_XfOrM362(x) SETUP_XfOrM360(x)
            FUNCCALL(SETUP_XfOrM362(_), scheme_tell_all (port , & dot2line , & dot2col , & dot2pos ) ); 
            FUNCCALL(SETUP_XfOrM362(_), track_indentation (indentation , dot2line , dot2col ) ); 
          }
          infixed = cdr ; 
          if (! list )
            list = pair ; 
          else (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = pair ; 
          last = pair ; 
          ch = FUNCCALL(SETUP_XfOrM360(_), skip_whitespace_comments (port , stxsrc , ht , indentation , params ) ); 
          effective_ch = FUNCCALL_AGAIN(readtable_effective_char (params -> table , ch ) ); 
          if ((effective_ch == closer ) || (ch == (- 1 ) ) ) {
#           define XfOrM361_COUNT (0+XfOrM360_COUNT)
#           define SETUP_XfOrM361(x) SETUP_XfOrM360(x)
            FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , dotline , dotcol , dotpos , 1 , (ch == (- 1 ) ) ? (- 1 ) : 0 , indentation , "read: illegal use of `%c'" , ch ) ); 
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          }
          got_ch_already = 1 ; 
        }
        else {
#         define XfOrM359_COUNT (0+XfOrM358_COUNT)
#         define SETUP_XfOrM359(x) SETUP_XfOrM358(x)
          FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , dotline , dotcol , dotpos , 1 , (ch == (- 1 ) ) ? (- 1 ) : 0 , indentation , "read: illegal use of `%c'" , dot_ch ) ); 
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        }
      }
      else {
#       define XfOrM357_COUNT (0+XfOrM356_COUNT)
#       define SETUP_XfOrM357(x) SETUP_XfOrM356(x)
        (((Scheme_Simple_Object * ) (pair ) ) -> u . pair_val . cdr ) = cdr ; 
        cdr = pair ; 
        if (! list )
          list = cdr ; 
        else (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = cdr ; 
        FUNCCALL(SETUP_XfOrM357(_), pop_indentation (indentation ) ); 
        if (params -> honu_mode )
          list = FUNCCALL(SETUP_XfOrM357(_), combine_angle_brackets (list ) ); 
        list = (stxsrc ? (__funcarg69 = FUNCCALL(SETUP_XfOrM357(_), SPAN (port , pos ) ), FUNCCALL_AGAIN(scheme_make_stx_w_offset (list , line , col , pos , __funcarg69 , stxsrc , scheme_false ) )) : list ) ; 
        list = FUNCCALL(SETUP_XfOrM357(_), attach_shape_property (list , stxsrc , params , closer ) ); 
        RET_VALUE_START (list ) RET_VALUE_END ; 
      }
    }
    else {
#     define XfOrM352_COUNT (0+XfOrM351_COUNT)
#     define SETUP_XfOrM352(x) SETUP_XfOrM351(x)
      if ((ch == (- 2 ) ) || (params -> table && (ch != (- 1 ) ) && (shape != 2 ) ) ) {
#       define XfOrM355_COUNT (0+XfOrM352_COUNT)
#       define SETUP_XfOrM355(x) SETUP_XfOrM352(x)
        FUNCCALL(SETUP_XfOrM355(_), scheme_ungetc (ch , port ) ); 
        prefetched = FUNCCALL(SETUP_XfOrM355(_), read_inner (port , stxsrc , ht , indentation , params , 0x1 | 0x10 ) ); 
        if (! prefetched )
          goto retry_before_dot ; 
      }
      else {
        got_ch_already = 1 ; 
      }
      if (shape == 3 ) {
#       define XfOrM353_COUNT (0+XfOrM352_COUNT)
#       define SETUP_XfOrM353(x) SETUP_XfOrM352(x)
        (__funcarg67 = FUNCCALL(SETUP_XfOrM353(_), SPAN (port , start ) ), __funcarg68 = FUNCCALL(SETUP_XfOrM353(_), dot_name (params ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , startline , startcol , start , __funcarg67 , ch , indentation , "read: expected %s and value for hash" , __funcarg68 ) )) ; 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      cdr = pair ; 
      if (! list )
        list = cdr ; 
      else (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = cdr ; 
      last = cdr ; 
    }
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * combine_angle_brackets (Scheme_Object * list ) {
  Scheme_Object * l , * a , * open_stack = ((void * ) 0 ) , * prev = ((void * ) 0 ) ; 
  int i , ch ; 
  Scheme_Object * __funcarg84 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(10);
  BLOCK_SETUP_TOP((PUSH(list, 0), PUSH(a, 1), PUSH(open_stack, 2), PUSH(l, 3), PUSH(prev, 4)));
# define XfOrM388_COUNT (5)
# define SETUP_XfOrM388(x) SETUP(XfOrM388_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  l = NULLED_OUT ; 
  a = NULLED_OUT ; 
  for (l = list ; ! ((l ) == (scheme_null ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#   define XfOrM403_COUNT (0+XfOrM388_COUNT)
#   define SETUP_XfOrM403(x) SETUP_XfOrM388(x)
    a = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
    if (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
      a = ((Scheme_Stx * ) a ) -> val ; 
    if (((a ) == (honu_angle_open ) ) ) {
#     define XfOrM416_COUNT (0+XfOrM403_COUNT)
#     define SETUP_XfOrM416(x) SETUP_XfOrM403(x)
      open_stack = (__funcarg84 = FUNCCALL(SETUP_XfOrM416(_), scheme_make_raw_pair (l , prev ) ), FUNCCALL_AGAIN(scheme_make_raw_pair (__funcarg84 , open_stack ) )) ; 
      a = FUNCCALL(SETUP_XfOrM416(_), scheme_intern_symbol ("<" ) ); 
      if (((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
        a = FUNCCALL(SETUP_XfOrM416(_), scheme_datum_to_syntax (a , scheme_false , (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) , 0 , 1 ) ); 
      (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) = a ; 
    }
    else if (((a ) == (honu_angle_close ) ) ) {
#     define XfOrM409_COUNT (0+XfOrM403_COUNT)
#     define SETUP_XfOrM409(x) SETUP_XfOrM403(x)
      if (open_stack ) {
        Scheme_Object * open , * open_prev ; 
        Scheme_Object * naya , * ang , * seq ; 
        BLOCK_SETUP((PUSH(open_prev, 0+XfOrM409_COUNT), PUSH(open, 1+XfOrM409_COUNT), PUSH(ang, 2+XfOrM409_COUNT), PUSH(seq, 3+XfOrM409_COUNT), PUSH(naya, 4+XfOrM409_COUNT)));
#       define XfOrM411_COUNT (5+XfOrM409_COUNT)
#       define SETUP_XfOrM411(x) SETUP(XfOrM411_COUNT)
        open = NULLED_OUT ; 
        open_prev = NULLED_OUT ; 
        naya = NULLED_OUT ; 
        ang = NULLED_OUT ; 
        seq = NULLED_OUT ; 
        open = (((Scheme_Simple_Object * ) (open_stack ) ) -> u . pair_val . car ) ; 
        open_prev = (((Scheme_Simple_Object * ) (open ) ) -> u . pair_val . cdr ) ; 
        open = (((Scheme_Simple_Object * ) (open ) ) -> u . pair_val . car ) ; 
        open_stack = (((Scheme_Simple_Object * ) (open_stack ) ) -> u . pair_val . cdr ) ; 
        ang = honu_angles ; 
        if (((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ) {
          Scheme_Stx * o , * c ; 
          int span ; 
#         define XfOrM415_COUNT (0+XfOrM411_COUNT)
#         define SETUP_XfOrM415(x) SETUP_XfOrM411(x)
          o = NULLED_OUT ; 
          c = NULLED_OUT ; 
          o = (Scheme_Stx * ) (((Scheme_Simple_Object * ) (open ) ) -> u . pair_val . car ) ; 
          c = (Scheme_Stx * ) (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
          if ((o -> srcloc -> pos >= 0 ) && (c -> srcloc -> pos >= 0 ) )
            span = (c -> srcloc -> pos - o -> srcloc -> pos ) + c -> srcloc -> span ; 
          else span = - 1 ; 
          ang = FUNCCALL(SETUP_XfOrM415(_), scheme_make_stx_w_offset (ang , o -> srcloc -> line , o -> srcloc -> col , o -> srcloc -> pos , span , o -> srcloc -> src , scheme_false ) ); 
        }
        seq = FUNCCALL(SETUP_XfOrM411(_), scheme_make_pair (ang , (((Scheme_Simple_Object * ) (open ) ) -> u . pair_val . cdr ) ) ); 
        (((Scheme_Simple_Object * ) (prev ) ) -> u . pair_val . cdr ) = scheme_null ; 
        if (((Scheme_Type ) (((((long ) (ang ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ang ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ) {
#         define XfOrM414_COUNT (0+XfOrM411_COUNT)
#         define SETUP_XfOrM414(x) SETUP_XfOrM411(x)
          seq = FUNCCALL(SETUP_XfOrM414(_), scheme_datum_to_syntax (seq , scheme_false , ang , 0 , 1 ) ); 
        }
        naya = FUNCCALL(SETUP_XfOrM411(_), scheme_make_pair (seq , (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) ); 
        if (open_prev ) {
          (((Scheme_Simple_Object * ) (open_prev ) ) -> u . pair_val . cdr ) = naya ; 
        }
        else {
          list = naya ; 
        }
        l = naya ; 
      }
      else {
#       define XfOrM410_COUNT (0+XfOrM409_COUNT)
#       define SETUP_XfOrM410(x) SETUP_XfOrM409(x)
        a = FUNCCALL(SETUP_XfOrM410(_), scheme_intern_symbol (">" ) ); 
        if (((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
          a = FUNCCALL(SETUP_XfOrM410(_), scheme_datum_to_syntax (a , scheme_false , (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) , 0 , 1 ) ); 
        (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) = a ; 
      }
    }
    else if (open_stack && ((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
      for (i = (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (a ) ) ) -> len ) ; i -- ; ) {
        ch = (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (a ) ) ) -> s ) [i ] ; 
        if ((ch == '=' ) || (ch == '|' ) || (ch == '&' ) ) {
          open_stack = ((void * ) 0 ) ; 
          break ; 
        }
      }
    }
    prev = l ; 
  }
  RET_VALUE_START (list ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * honu_add_module_wrapper (Scheme_Object * list , Scheme_Object * stxsrc , Scheme_Object * port ) {
  Scheme_Object * v , * name ; 
  Scheme_Object * __funcarg93 = NULLED_OUT ; 
  Scheme_Object * __funcarg92 = NULLED_OUT ; 
  Scheme_Object * __funcarg91 = NULLED_OUT ; 
  Scheme_Object * __funcarg90 = NULLED_OUT ; 
  Scheme_Object * __funcarg89 = NULLED_OUT ; 
  Scheme_Object * __funcarg88 = NULLED_OUT ; 
  Scheme_Object * __funcarg87 = NULLED_OUT ; 
  Scheme_Object * __funcarg86 = NULLED_OUT ; 
  Scheme_Object * __funcarg85 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(__funcarg85, 0), PUSH(list, 1), PUSH(stxsrc, 2), PUSH(__funcarg91, 3), PUSH(name, 4), PUSH(__funcarg89, 5), PUSH(v, 6)));
# define XfOrM417_COUNT (7)
# define SETUP_XfOrM417(x) SETUP(XfOrM417_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  v = NULLED_OUT ; 
  name = NULLED_OUT ; 
  if (stxsrc )
    name = stxsrc ; 
  else name = ((Scheme_Input_Port * ) port ) -> name ; 
  if (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    name = FUNCCALL(SETUP_XfOrM417(_), scheme_char_string_to_byte_string_locale (name ) ); 
  if (((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) {
    Scheme_Object * base ; 
    int isdir , i ; 
    BLOCK_SETUP((PUSH(base, 0+XfOrM417_COUNT)));
#   define XfOrM419_COUNT (1+XfOrM417_COUNT)
#   define SETUP_XfOrM419(x) SETUP(XfOrM419_COUNT)
    base = NULLED_OUT ; 
    name = FUNCCALL(SETUP_XfOrM419(_), scheme_split_path ((((Scheme_Simple_Object * ) (name ) ) -> u . byte_str_val . string_val ) , (((Scheme_Simple_Object * ) (name ) ) -> u . byte_str_val . tag_val ) , & base , & isdir , scheme_unix_path_type ) ); 
    for (i = (((Scheme_Simple_Object * ) (name ) ) -> u . byte_str_val . tag_val ) ; i -- ; ) {
      if ((((Scheme_Simple_Object * ) (name ) ) -> u . byte_str_val . string_val ) [i ] == '.' )
        break ; 
    }
    if (i > 0 )
      name = FUNCCALL(SETUP_XfOrM419(_), scheme_make_sized_path ((((Scheme_Simple_Object * ) (name ) ) -> u . byte_str_val . string_val ) , i , 0 ) ); 
    name = FUNCCALL(SETUP_XfOrM419(_), scheme_byte_string_to_char_string_locale (name ) ); 
    name = FUNCCALL_AGAIN(scheme_intern_exact_char_symbol ((((Scheme_Simple_Object * ) (name ) ) -> u . char_str_val . string_val ) , (((Scheme_Simple_Object * ) (name ) ) -> u . char_str_val . tag_val ) ) ); 
  }
  else if (! ((Scheme_Type ) (((((long ) (name ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (name ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
#   define XfOrM418_COUNT (0+XfOrM417_COUNT)
#   define SETUP_XfOrM418(x) SETUP_XfOrM417(x)
    name = FUNCCALL(SETUP_XfOrM418(_), scheme_intern_symbol ("unknown" ) ); 
  }
  v = (__funcarg85 = FUNCCALL(SETUP_XfOrM417(_), scheme_intern_symbol ("module" ) ), __funcarg86 = (__funcarg87 = (__funcarg88 = (__funcarg89 = FUNCCALL(SETUP_XfOrM417(_), scheme_intern_symbol ("lib" ) ), __funcarg90 = (__funcarg91 = FUNCCALL(SETUP_XfOrM417(_), scheme_make_utf8_string ("honu-module.ss" ) ), __funcarg92 = (__funcarg93 = FUNCCALL(SETUP_XfOrM417(_), scheme_make_utf8_string ("honu-module" ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (__funcarg93 , scheme_null ) )) , FUNCCALL_AGAIN(scheme_make_immutable_pair (__funcarg91 , __funcarg92 ) )) , FUNCCALL_AGAIN(scheme_make_immutable_pair (__funcarg89 , __funcarg90 ) )) , FUNCCALL_AGAIN(scheme_make_immutable_pair (__funcarg88 , list ) )) , FUNCCALL_AGAIN(scheme_make_immutable_pair (name , __funcarg87 ) )) , FUNCCALL_AGAIN(scheme_make_immutable_pair (__funcarg85 , __funcarg86 ) )) ; 
  if (stxsrc )
    v = FUNCCALL(SETUP_XfOrM417(_), scheme_datum_to_syntax (v , list , scheme_false , 0 , 0 ) ); 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * attach_shape_property (Scheme_Object * list , Scheme_Object * stxsrc , ReadParams * params , int closer ) {
  /* No conversion */
  if ((closer != ')' ) && stxsrc && ! params -> honu_mode ) {
    Scheme_Object * opener ; 
    opener = ((closer == '}' ) ? scheme_char_constants [(unsigned char ) ('{' ) ] : scheme_char_constants [(unsigned char ) ('[' ) ] ) ; 
    return scheme_stx_property (list , paren_shape_symbol , opener ) ; 
  }
  return list ; 
}
/* this far 3068 */
/* this far 3068 */
static Scheme_Object * read_string (int is_byte , int is_honu_char , Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params , int err_ok ) {
  mzchar * buf , * oldbuf , onstack [32 ] ; 
  int i , j , n , n1 , ch , closer = (is_honu_char ? '\'' : '"' ) ; 
  long size = 31 , oldsize ; 
  Scheme_Object * result ; 
  long __funcarg114 ; 
  long __funcarg113 ; 
  long __funcarg112 ; 
  long __funcarg111 ; 
  long __funcarg110 ; 
  long __funcarg109 ; 
  long __funcarg108 ; 
  long __funcarg106 ; 
  long __funcarg105 ; 
  long __funcarg94 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(indentation, 0), PUSH(port, 1), PUSH(stxsrc, 2), PUSH(ht, 3), PUSH(buf, 4), PUSH(oldbuf, 5), PUSH(result, 6)));
# define XfOrM424_COUNT (7)
# define SETUP_XfOrM424(x) SETUP(XfOrM424_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  buf = NULLED_OUT ; 
  oldbuf = NULLED_OUT ; 
  result = NULLED_OUT ; 
  i = 0 ; 
  buf = onstack ; 
  while ((ch = FUNCCALL(SETUP_XfOrM424(_), scheme_getc_special_ok (port ) )) != closer ) {
#   define XfOrM467_COUNT (0+XfOrM424_COUNT)
#   define SETUP_XfOrM467(x) SETUP_XfOrM424(x)
    if ((ch == (- 1 ) ) || (is_honu_char && (i > 0 ) ) ) {
#     define XfOrM503_COUNT (0+XfOrM467_COUNT)
#     define SETUP_XfOrM503(x) SETUP_XfOrM467(x)
      if (err_ok )
        (__funcarg114 = FUNCCALL(SETUP_XfOrM503(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg114 , ch , indentation , "read: expected a closing %s%s" , is_honu_char ? "'" : "'\"'" , (ch == (- 1 ) ) ? "" : " after one character" ) )) ; 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else if (ch == (- 2 ) ) {
#     define XfOrM502_COUNT (0+XfOrM467_COUNT)
#     define SETUP_XfOrM502(x) SETUP_XfOrM467(x)
      FUNCCALL(SETUP_XfOrM502(_), scheme_get_ready_read_special (port , stxsrc , ht ) ); 
      if (err_ok )
        (__funcarg113 = FUNCCALL(SETUP_XfOrM502(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg113 , (- 2 ) , indentation , "read: found non-character while reading a %s" , is_honu_char ? "character constant" : "string" ) )) ; 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    if (ch == '\\' ) {
#     define XfOrM474_COUNT (0+XfOrM467_COUNT)
#     define SETUP_XfOrM474(x) SETUP_XfOrM467(x)
      ch = FUNCCALL(SETUP_XfOrM474(_), scheme_getc_special_ok (port ) ); 
      if (ch == (- 1 ) ) {
#       define XfOrM501_COUNT (0+XfOrM474_COUNT)
#       define SETUP_XfOrM501(x) SETUP_XfOrM474(x)
        if (err_ok )
          (__funcarg112 = FUNCCALL(SETUP_XfOrM501(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg112 , (- 1 ) , indentation , "read: expected a closing %s" , is_honu_char ? "'" : "'\"'" ) )) ; 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      else if (ch == (- 2 ) ) {
#       define XfOrM500_COUNT (0+XfOrM474_COUNT)
#       define SETUP_XfOrM500(x) SETUP_XfOrM474(x)
        FUNCCALL(SETUP_XfOrM500(_), scheme_get_ready_read_special (port , stxsrc , ht ) ); 
        if (err_ok )
          (__funcarg111 = FUNCCALL(SETUP_XfOrM500(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg111 , (- 2 ) , indentation , "read: found non-character while reading a %s" , is_honu_char ? "character constant" : "string" ) )) ; 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      switch (ch ) {
#       define XfOrM475_COUNT (0+XfOrM474_COUNT)
#       define SETUP_XfOrM475(x) SETUP_XfOrM474(x)
        case '\\' : case '\"' : case '\'' : break ; 
        case 'a' : ch = '\a' ; 
        break ; 
        case 'b' : ch = '\b' ; 
        break ; 
        case 'e' : ch = 27 ; 
        break ; 
        case 'f' : ch = '\f' ; 
        break ; 
        case 'n' : ch = '\n' ; 
        break ; 
        case 'r' : ch = '\r' ; 
        break ; 
        case 't' : ch = '\t' ; 
        break ; 
        case 'v' : ch = '\v' ; 
        break ; 
        case '\r' : if (FUNCCALL(SETUP_XfOrM475(_), scheme_peekc_special_ok (port ) )== '\n' )
          FUNCCALL(SETUP_XfOrM475(_), scheme_getc (port ) ); 
        continue ; 
        case '\n' : continue ; 
        case 'x' : ch = FUNCCALL(SETUP_XfOrM475(_), scheme_getc_special_ok (port ) ); 
        if (((ch ) >= 0 ) && (((ch >= '0' ) && (ch <= '9' ) ) || ((ch >= 'a' ) && (ch <= 'f' ) ) || ((ch >= 'A' ) && (ch <= 'F' ) ) ) ) {
#         define XfOrM498_COUNT (0+XfOrM475_COUNT)
#         define SETUP_XfOrM498(x) SETUP_XfOrM475(x)
          n = ch <= '9' ? ch - '0' : ((ch + scheme_uchar_ups [(scheme_uchar_cases_table [(ch >> 8 ) & 0x1FFF ] [ch & 0xFF ] ) ] ) - 'A' + 10 ) ; 
          ch = FUNCCALL(SETUP_XfOrM498(_), scheme_peekc_special_ok (port ) ); 
          if (((ch ) >= 0 ) && (((ch >= '0' ) && (ch <= '9' ) ) || ((ch >= 'a' ) && (ch <= 'f' ) ) || ((ch >= 'A' ) && (ch <= 'F' ) ) ) ) {
#           define XfOrM499_COUNT (0+XfOrM498_COUNT)
#           define SETUP_XfOrM499(x) SETUP_XfOrM498(x)
            n = n * 16 + (ch <= '9' ? ch - '0' : ((ch + scheme_uchar_ups [(scheme_uchar_cases_table [(ch >> 8 ) & 0x1FFF ] [ch & 0xFF ] ) ] ) - 'A' + 10 ) ) ; 
            FUNCCALL(SETUP_XfOrM499(_), scheme_getc (port ) ); 
          }
          ch = n ; 
        }
        else {
#         define XfOrM497_COUNT (0+XfOrM475_COUNT)
#         define SETUP_XfOrM497(x) SETUP_XfOrM475(x)
          if (ch == (- 2 ) )
            FUNCCALL(SETUP_XfOrM497(_), scheme_get_ready_read_special (port , stxsrc , ht ) ); 
          if (err_ok )
            (__funcarg110 = FUNCCALL(SETUP_XfOrM497(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg110 , ch , indentation , "read: no hex digit following \\x in %s" , is_honu_char ? "character constant" : "string" ) )) ; 
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        }
        break ; 
        case 'u' : case 'U' : if (! is_byte ) {
          int maxc = ((ch == 'u' ) ? 4 : 8 ) ; 
#         define XfOrM488_COUNT (0+XfOrM475_COUNT)
#         define SETUP_XfOrM488(x) SETUP_XfOrM475(x)
          ch = FUNCCALL(SETUP_XfOrM488(_), scheme_getc_special_ok (port ) ); 
          if (((ch ) >= 0 ) && (((ch >= '0' ) && (ch <= '9' ) ) || ((ch >= 'a' ) && (ch <= 'f' ) ) || ((ch >= 'A' ) && (ch <= 'F' ) ) ) ) {
            int count = 1 ; 
#           define XfOrM490_COUNT (0+XfOrM488_COUNT)
#           define SETUP_XfOrM490(x) SETUP_XfOrM488(x)
            n = ch <= '9' ? ch - '0' : ((ch + scheme_uchar_ups [(scheme_uchar_cases_table [(ch >> 8 ) & 0x1FFF ] [ch & 0xFF ] ) ] ) - 'A' + 10 ) ; 
            while (count < maxc ) {
#             define XfOrM495_COUNT (0+XfOrM490_COUNT)
#             define SETUP_XfOrM495(x) SETUP_XfOrM490(x)
              ch = FUNCCALL(SETUP_XfOrM495(_), scheme_peekc_special_ok (port ) ); 
              if (((ch ) >= 0 ) && (((ch >= '0' ) && (ch <= '9' ) ) || ((ch >= 'a' ) && (ch <= 'f' ) ) || ((ch >= 'A' ) && (ch <= 'F' ) ) ) ) {
#               define XfOrM496_COUNT (0+XfOrM495_COUNT)
#               define SETUP_XfOrM496(x) SETUP_XfOrM495(x)
                n = n * 16 + (ch <= '9' ? ch - '0' : ((ch + scheme_uchar_ups [(scheme_uchar_cases_table [(ch >> 8 ) & 0x1FFF ] [ch & 0xFF ] ) ] ) - 'A' + 10 ) ) ; 
                FUNCCALL(SETUP_XfOrM496(_), scheme_getc (port ) ); 
                count ++ ; 
              }
              else break ; 
            }
            if (((n >= 0xD800 ) && (n <= 0xDFFF ) ) || (n > 0x10FFFF ) ) {
              ch = - 1 ; 
            }
            else {
              ch = n ; 
            }
          }
          else {
#           define XfOrM489_COUNT (0+XfOrM488_COUNT)
#           define SETUP_XfOrM489(x) SETUP_XfOrM488(x)
            if (ch == (- 2 ) )
              FUNCCALL(SETUP_XfOrM489(_), scheme_get_ready_read_special (port , stxsrc , ht ) ); 
            if (err_ok )
              (__funcarg109 = FUNCCALL(SETUP_XfOrM489(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg109 , ch , indentation , "read: no hex digit following \\%c in %s" , ((maxc == 4 ) ? 'u' : 'U' ) , is_honu_char ? "character constant" : "string" ) )) ; 
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          }
          break ; 
        }
        default : if ((ch >= '0' ) && (ch <= '7' ) ) {
#         define XfOrM477_COUNT (0+XfOrM475_COUNT)
#         define SETUP_XfOrM477(x) SETUP_XfOrM475(x)
          for (n = j = 0 ; j < 3 ; j ++ ) {
#           define XfOrM483_COUNT (0+XfOrM477_COUNT)
#           define SETUP_XfOrM483(x) SETUP_XfOrM477(x)
            n1 = 8 * n + ch - '0' ; 
            if (n1 > 255 ) {
#             define XfOrM487_COUNT (0+XfOrM483_COUNT)
#             define SETUP_XfOrM487(x) SETUP_XfOrM483(x)
              if (err_ok )
                (__funcarg108 = FUNCCALL(SETUP_XfOrM487(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg108 , 0 , indentation , "read: escape sequence \\%o out of range in %s" , n1 , is_honu_char ? "character constant" : "string" ) )) ; 
              RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
            }
            n = n1 ; 
            if (j < 2 ) {
#             define XfOrM484_COUNT (0+XfOrM483_COUNT)
#             define SETUP_XfOrM484(x) SETUP_XfOrM483(x)
              ch = FUNCCALL(SETUP_XfOrM484(_), scheme_peekc_special_ok (port ) ); 
              if (! ((ch >= '0' ) && (ch <= '7' ) ) ) {
                break ; 
              }
              else {
#               define XfOrM485_COUNT (0+XfOrM484_COUNT)
#               define SETUP_XfOrM485(x) SETUP_XfOrM484(x)
                FUNCCALL(SETUP_XfOrM485(_), scheme_getc (port ) ); 
              }
            }
          }
          ch = n ; 
        }
        else {
#         define XfOrM476_COUNT (0+XfOrM475_COUNT)
#         define SETUP_XfOrM476(x) SETUP_XfOrM475(x)
          if (err_ok )
            (__funcarg106 = FUNCCALL(SETUP_XfOrM476(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg106 , 0 , indentation , "read: unknown escape sequence \\%c in %s%s" , ch , is_byte ? "byte " : "" , is_honu_char ? "character constant" : "string" ) )) ; 
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        }
        break ; 
      }
    }
    else if ((ch == '\n' ) || (ch == '\r' ) ) {
      if (line > 0 ) {
        if (((Scheme_Type ) (((((long ) (indentation ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (indentation ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
          Scheme_Indent * indt ; 
          indt = NULLED_OUT ; 
          indt = (Scheme_Indent * ) (((Scheme_Simple_Object * ) (indentation ) ) -> u . pair_val . car ) ; 
          if (! indt -> suspicious_quote ) {
            indt -> suspicious_quote = line ; 
            indt -> quote_for_char = is_honu_char ; 
          }
        }
      }
    }
    if (ch < 0 ) {
#     define XfOrM469_COUNT (0+XfOrM467_COUNT)
#     define SETUP_XfOrM469(x) SETUP_XfOrM467(x)
      if (err_ok )
        (__funcarg105 = FUNCCALL(SETUP_XfOrM469(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg105 , 0 , indentation , "read: out-of-range character in %s%s" , is_byte ? "byte " : "" , is_honu_char ? "character constant" : "string" ) )) ; 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    if (i >= size ) {
#     define XfOrM468_COUNT (0+XfOrM467_COUNT)
#     define SETUP_XfOrM468(x) SETUP_XfOrM467(x)
      oldsize = size ; 
      oldbuf = buf ; 
      size *= 2 ; 
      buf = (mzchar * ) FUNCCALL(SETUP_XfOrM468(_), GC_malloc_atomic ((size + 1 ) * sizeof (mzchar ) ) ); 
      (memcpy (buf , oldbuf , oldsize * sizeof (mzchar ) ) ) ; 
    }
    buf [i ++ ] = ch ; 
  }
  buf [i ] = '\0' ; 
  if (is_honu_char ) {
#   define XfOrM428_COUNT (0+XfOrM424_COUNT)
#   define SETUP_XfOrM428(x) SETUP_XfOrM424(x)
    if (i )
      result = ((((mzchar ) buf [0 ] ) < 256 ) ? scheme_char_constants [(unsigned char ) (buf [0 ] ) ] : FUNCCALL(SETUP_XfOrM428(_), scheme_make_char (buf [0 ] ) )) ; 
    else {
#     define XfOrM429_COUNT (0+XfOrM428_COUNT)
#     define SETUP_XfOrM429(x) SETUP_XfOrM428(x)
      if (err_ok )
        FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , 2 , 0 , indentation , "read: expected one character before closing '" ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  else if (! is_byte )
    result = FUNCCALL(SETUP_XfOrM424(_), scheme_make_immutable_sized_char_string (buf , i , i <= 31 ) ); 
  else {
    char * s ; 
    BLOCK_SETUP((PUSH(s, 0+XfOrM424_COUNT)));
#   define XfOrM425_COUNT (1+XfOrM424_COUNT)
#   define SETUP_XfOrM425(x) SETUP(XfOrM425_COUNT)
    s = NULLED_OUT ; 
    s = (char * ) FUNCCALL(SETUP_XfOrM425(_), GC_malloc_atomic (i + 1 ) ); 
    for (j = 0 ; j < i ; j ++ ) {
      ((unsigned char * ) s ) [j ] = buf [j ] ; 
    }
    s [i ] = 0 ; 
    result = FUNCCALL(SETUP_XfOrM425(_), scheme_make_immutable_sized_byte_string (s , i , 0 ) ); 
  }
  if (stxsrc )
    result = (__funcarg94 = FUNCCALL(SETUP_XfOrM424(_), SPAN (port , pos ) ), FUNCCALL_AGAIN(scheme_make_stx_w_offset (result , line , col , pos , __funcarg94 , stxsrc , scheme_false ) )) ; 
  RET_VALUE_START (result ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_read_byte_string (Scheme_Object * port ) {
  /* No conversion */
  return read_string (1 , 0 , port , ((void * ) 0 ) , 0 , 0 , 0 , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ; 
}
static Scheme_Object * read_here_string (Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , Scheme_Object * indentation , ReadParams * params ) {
  int tlen = 0 , len = 0 , size = 12 ; 
  mzchar * tag , * naya , * s , buf [12 ] , c ; 
  Scheme_Object * str ; 
  long __funcarg117 ; 
  long __funcarg115 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSH(indentation, 0), PUSH(port, 1), PUSH(stxsrc, 2), PUSH(str, 3), PUSH(naya, 4), PUSH(tag, 5), PUSH(s, 6)));
# define XfOrM505_COUNT (7)
# define SETUP_XfOrM505(x) SETUP(XfOrM505_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  tag = NULLED_OUT ; 
  naya = NULLED_OUT ; 
  s = NULLED_OUT ; 
  str = NULLED_OUT ; 
  tag = buf ; 
  while (1 ) {
#   define XfOrM520_COUNT (0+XfOrM505_COUNT)
#   define SETUP_XfOrM520(x) SETUP_XfOrM505(x)
    c = FUNCCALL(SETUP_XfOrM520(_), scheme_getc (port ) ); 
    if (c == '\n' ) {
      break ; 
    }
    else if (c == (- 1 ) ) {
#     define XfOrM523_COUNT (0+XfOrM520_COUNT)
#     define SETUP_XfOrM523(x) SETUP_XfOrM520(x)
      FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , 3 + tlen , (- 1 ) , indentation , "read: found end-of-file after #<< and before first and-of-line" ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else {
#     define XfOrM521_COUNT (0+XfOrM520_COUNT)
#     define SETUP_XfOrM521(x) SETUP_XfOrM520(x)
      if (tlen >= size ) {
        size *= 2 ; 
#       define XfOrM522_COUNT (0+XfOrM521_COUNT)
#       define SETUP_XfOrM522(x) SETUP_XfOrM521(x)
        naya = (mzchar * ) FUNCCALL(SETUP_XfOrM522(_), GC_malloc_atomic (size * sizeof (mzchar ) ) ); 
        (memcpy (naya , tag , tlen * sizeof (mzchar ) ) ) ; 
        tag = naya ; 
      }
      tag [tlen ++ ] = c ; 
    }
  }
  if (! tlen ) {
#   define XfOrM514_COUNT (0+XfOrM505_COUNT)
#   define SETUP_XfOrM514(x) SETUP_XfOrM505(x)
    FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , 3 , 0 , indentation , "read: no characters after #<< before and-of-line" ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  size = 10 + tlen ; 
  s = (mzchar * ) FUNCCALL(SETUP_XfOrM505(_), GC_malloc_atomic (size * sizeof (mzchar ) ) ); 
  while (1 ) {
#   define XfOrM510_COUNT (0+XfOrM505_COUNT)
#   define SETUP_XfOrM510(x) SETUP_XfOrM505(x)
    c = FUNCCALL(SETUP_XfOrM510(_), scheme_getc (port ) ); 
    if (c == (- 1 ) ) {
#     define XfOrM513_COUNT (0+XfOrM510_COUNT)
#     define SETUP_XfOrM513(x) SETUP_XfOrM510(x)
      (__funcarg117 = FUNCCALL(SETUP_XfOrM513(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg117 , (- 1 ) , indentation , "read: found end-of-file before terminating %u%s" , tag , (tlen > 50 ) ? 50 : tlen , (tlen > 50 ) ? "..." : "" ) )) ; 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    if (len >= size ) {
      size *= 2 ; 
#     define XfOrM512_COUNT (0+XfOrM510_COUNT)
#     define SETUP_XfOrM512(x) SETUP_XfOrM510(x)
      naya = (mzchar * ) FUNCCALL(SETUP_XfOrM512(_), GC_malloc_atomic (size * sizeof (mzchar ) ) ); 
      (memcpy (naya , s , len * sizeof (mzchar ) ) ) ; 
      s = naya ; 
    }
    s [len ++ ] = c ; 
    if ((len >= tlen ) && ((len == tlen ) || (s [len - tlen - 1 ] == '\n' ) ) && ! (memcmp (s XFORM_OK_PLUS (len - tlen ) , tag , sizeof (mzchar ) * tlen ) ) ) {
#     define XfOrM511_COUNT (0+XfOrM510_COUNT)
#     define SETUP_XfOrM511(x) SETUP_XfOrM510(x)
      c = FUNCCALL(SETUP_XfOrM511(_), scheme_peekc (port ) ); 
      if ((c == '\r' ) || (c == '\n' ) || (c == (- 1 ) ) )
        break ; 
    }
  }
  len -= (tlen + 1 ) ; 
  if (len < 0 )
    len = 0 ; 
  str = FUNCCALL(SETUP_XfOrM505(_), scheme_make_sized_char_string (s , len , 1 ) ); 
  if (stxsrc )
    str = (__funcarg115 = FUNCCALL(SETUP_XfOrM505(_), SPAN (port , pos ) ), FUNCCALL_AGAIN(scheme_make_stx_w_offset (str , line , col , pos , __funcarg115 , stxsrc , scheme_false ) )) ; 
  RET_VALUE_START (str ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
char * scheme_extract_indentation_suggestions (Scheme_Object * indentation ) {
  long suspicious_quote = 0 ; 
  int is_honu_char = 0 ; 
  char * suspicions = "" ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(suspicions, 0)));
# define XfOrM525_COUNT (1)
# define SETUP_XfOrM525(x) SETUP(XfOrM525_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  while (((Scheme_Type ) (((((long ) (indentation ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (indentation ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
    Scheme_Indent * indt ; 
    indt = NULLED_OUT ; 
    indt = (Scheme_Indent * ) (((Scheme_Simple_Object * ) (indentation ) ) -> u . pair_val . car ) ; 
    indentation = (((Scheme_Simple_Object * ) (indentation ) ) -> u . pair_val . cdr ) ; 
    if (indt -> suspicious_quote ) {
      suspicious_quote = indt -> suspicious_quote ; 
      is_honu_char = indt -> quote_for_char ; 
    }
  }
  if (suspicious_quote ) {
#   define XfOrM526_COUNT (0+XfOrM525_COUNT)
#   define SETUP_XfOrM526(x) SETUP_XfOrM525(x)
    suspicions = (char * ) FUNCCALL(SETUP_XfOrM526(_), GC_malloc_atomic (64 ) ); 
    (sprintf (suspicions , "; newline within %s suggests a missing %s on line %ld" , is_honu_char ? "character" : "string" , is_honu_char ? "'" : "'\"'" , suspicious_quote ) ) ; 
  }
  RET_VALUE_START (suspicions ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * read_vector (Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , char closer , long requestLength , const mzchar * reqBuffer , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params ) {
  Scheme_Object * lresult , * obj , * vec , * * els ; 
  int len , i ; 
  ListStackRec r ; 
  long __funcarg119 ; 
  long __funcarg118 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(9);
  BLOCK_SETUP_TOP((PUSH(indentation, 0), PUSH(lresult, 1), PUSH(stxsrc, 2), PUSH(vec, 3), PUSH(r.stack, 4), PUSH(port, 5), PUSH(obj, 6), PUSH(reqBuffer, 7), PUSH(els, 8)));
# define XfOrM531_COUNT (9)
# define SETUP_XfOrM531(x) SETUP(XfOrM531_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  lresult = NULLED_OUT ; 
  obj = NULLED_OUT ; 
  vec = NULLED_OUT ; 
  els = NULLED_OUT ; 
  r.stack = NULLED_OUT ; 
  (r . pos = (scheme_current_thread -> list_stack_pos ) , r . stack = (scheme_current_thread -> list_stack ) ) ; 
  lresult = FUNCCALL(SETUP_XfOrM531(_), read_list (port , stxsrc , line , col , pos , closer , 1 , 1 , ht , indentation , params ) ); 
  if (requestLength == - 2 ) {
#   define XfOrM541_COUNT (0+XfOrM531_COUNT)
#   define SETUP_XfOrM541(x) SETUP_XfOrM531(x)
    ((scheme_current_thread -> list_stack_pos ) = r . pos , (scheme_current_thread -> list_stack ) = r . stack ) ; 
    FUNCCALL_EMPTY(scheme_raise_out_of_memory ("read" , "making vector of size %5" , reqBuffer ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (stxsrc )
    obj = ((Scheme_Stx * ) lresult ) -> val ; 
  else obj = lresult ; 
  len = FUNCCALL(SETUP_XfOrM531(_), scheme_list_length (obj ) ); 
  if (requestLength >= 0 && len > requestLength ) {
    char buffer [20 ] ; 
#   define XfOrM540_COUNT (0+XfOrM531_COUNT)
#   define SETUP_XfOrM540(x) SETUP_XfOrM531(x)
    ((scheme_current_thread -> list_stack_pos ) = r . pos , (scheme_current_thread -> list_stack ) = r . stack ) ; 
    (sprintf (buffer , "%ld" , requestLength ) ) ; 
    (__funcarg119 = FUNCCALL(SETUP_XfOrM540(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg119 , 0 , indentation , "read: vector length %ld is too small, " "%d values provided" , requestLength , len ) )) ; 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (requestLength < 0 )
    requestLength = len ; 
  vec = FUNCCALL(SETUP_XfOrM531(_), scheme_make_vector (requestLength , ((void * ) 0 ) ) ); 
  els = (((Scheme_Vector * ) (vec ) ) -> els ) ; 
  for (i = 0 ; i < len ; i ++ ) {
    els [i ] = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) ; 
    obj = (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) ; 
  }
  els = ((void * ) 0 ) ; 
  ((scheme_current_thread -> list_stack_pos ) = r . pos , (scheme_current_thread -> list_stack ) = r . stack ) ; 
  if (i < requestLength ) {
#   define XfOrM533_COUNT (0+XfOrM531_COUNT)
#   define SETUP_XfOrM533(x) SETUP_XfOrM531(x)
    if (len )
      obj = (((Scheme_Vector * ) (vec ) ) -> els ) [len - 1 ] ; 
    else {
#     define XfOrM537_COUNT (0+XfOrM533_COUNT)
#     define SETUP_XfOrM537(x) SETUP_XfOrM533(x)
      obj = ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
      if (stxsrc )
        obj = (__funcarg118 = FUNCCALL(SETUP_XfOrM537(_), SPAN (port , pos ) ), FUNCCALL_AGAIN(scheme_make_stx_w_offset (obj , line , col , pos , __funcarg118 , stxsrc , scheme_false ) )) ; 
    }
    if (stxsrc && (requestLength > 1 ) ) {
      Scheme_Object * v ; 
#     define XfOrM536_COUNT (0+XfOrM533_COUNT)
#     define SETUP_XfOrM536(x) SETUP_XfOrM533(x)
      v = NULLED_OUT ; 
      v = ((Scheme_Stx * ) obj ) -> val ; 
      if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || ((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) || ((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) )
        obj = FUNCCALL(SETUP_XfOrM536(_), scheme_make_graph_stx (obj , - 1 , - 1 , - 1 ) ); 
    }
    els = (((Scheme_Vector * ) (vec ) ) -> els ) ; 
    for (; i < requestLength ; i ++ ) {
      els [i ] = obj ; 
    }
    els = ((void * ) 0 ) ; 
  }
  if (stxsrc ) {
    if ((((Scheme_Vector * ) (vec ) ) -> size ) > 0 )
      ((((Scheme_Inclhash_Object * ) (vec ) ) -> so . keyex |= 0x1 ) ) ; 
    ((Scheme_Stx * ) lresult ) -> val = vec ; 
    RET_VALUE_START (lresult ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (vec ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int check_honu_num (mzchar * buf , int i ) ; 
typedef int (* Getc_Fun_r ) (Scheme_Object * port ) ; 
/* this far 3569 */
/* this far 3518 */
/* this far 3471 */
/* this far 3452 */
/* this far 3471 */
/* this far 3452 */
static Scheme_Object * read_number_or_symbol (int init_ch , int skip_rt , Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , int is_float , int is_not_float , int radix , int radix_set , int is_symbol , int is_kw , int pipe_quote , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params , Readtable * table ) {
  mzchar * buf , * oldbuf , onstack [64 ] ; 
  int size , oldsize ; 
  int i , ch , quoted , quoted_ever = 0 , running_quote = 0 ; 
  int running_quote_ch = 0 ; 
  long rq_pos = 0 , rq_col = 0 , rq_line = 0 ; 
  int case_sens = params -> case_sensitive ; 
  int decimal_inexact = params -> read_decimal_inexact ; 
  Scheme_Object * o ; 
  int delim_ok ; 
  int ungetc_ok ; 
  int honu_mode , e_ok = 0 ; 
  int far_char_ok ; 
  int single_escape , multiple_escape , norm_count = 0 ; 
  Getc_Fun_r getc_special_ok_fun ; 
  long __funcarg129 ; 
  long __funcarg128 ; 
  long __funcarg125 ; 
  long __funcarg124 ; 
  long __funcarg123 ; 
  long __funcarg122 ; 
  long __funcarg121 ; 
  long __funcarg120 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(10);
  BLOCK_SETUP_TOP((PUSH(indentation, 0), PUSH(ht, 1), PUSH(oldbuf, 2), PUSH(stxsrc, 3), PUSH(table, 4), PUSH(port, 5), PUSH(buf, 6), PUSH(params, 7), PUSH(o, 8)));
# define XfOrM542_COUNT (9)
# define SETUP_XfOrM542(x) SETUP(XfOrM542_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  buf = NULLED_OUT ; 
  oldbuf = NULLED_OUT ; 
  o = NULLED_OUT ; 
  if (! skip_rt && table ) {
#   define XfOrM596_COUNT (0+XfOrM542_COUNT)
#   define SETUP_XfOrM596(x) SETUP_XfOrM542(x)
    if (table -> symbol_parser ) {
#     define XfOrM597_COUNT (0+XfOrM596_COUNT)
#     define SETUP_XfOrM597(x) SETUP_XfOrM596(x)
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(readtable_call (1 , init_ch , table -> symbol_parser , params , port , stxsrc , line , col , pos , ht ) )) RET_VALUE_EMPTY_END ; 
    }
  }
  ungetc_ok = FUNCCALL(SETUP_XfOrM542(_), scheme_peekc_is_ungetc (port ) ); 
  if (ungetc_ok ) {
    getc_special_ok_fun = scheme_getc_special_ok ; 
  }
  else {
    getc_special_ok_fun = scheme_peekc_special_ok ; 
  }
  i = 0 ; 
  size = 64 - 1 ; 
  buf = onstack ; 
  if (init_ch < 0 )
    ch = FUNCCALL(SETUP_XfOrM542(_), getc_special_ok_fun (port ) ); 
  else {
    ch = init_ch ; 
  }
  if (is_float || is_not_float || radix_set )
    honu_mode = 0 ; 
  else honu_mode = params -> honu_mode ; 
  if (table ) {
    far_char_ok = 0 ; 
    delim_ok = 0 ; 
  }
  else if (! honu_mode ) {
    delim_ok = 0x1 ; 
    far_char_ok = 1 ; 
  }
  else {
    pipe_quote = 0 ; 
    if (! is_symbol ) {
      delim_ok = (0x8 | 0x10 ) ; 
      e_ok = 1 ; 
      far_char_ok = 0 ; 
    }
    else if (delim [ch ] & 0x4 ) {
      delim_ok = 0x4 ; 
      far_char_ok = 0 ; 
    }
    else {
      delim_ok = 0x2 ; 
      far_char_ok = 1 ; 
    }
  }
  while (((ch ) >= 0 ) && (running_quote || (! table && ! (((scheme_uchar_table [(ch >> 8 ) & 0x1FFF ] [ch & 0xFF ] ) ) & 0x10 ) && (((ch < 128 ) && (delim [ch ] & delim_ok ) ) || ((ch >= 128 ) && far_char_ok ) ) ) || table ) ) {
#   define XfOrM573_COUNT (0+XfOrM542_COUNT)
#   define SETUP_XfOrM573(x) SETUP_XfOrM542(x)
    if (table ) {
      int v ; 
#     define XfOrM586_COUNT (0+XfOrM573_COUNT)
#     define SETUP_XfOrM586(x) SETUP_XfOrM573(x)
      v = FUNCCALL(SETUP_XfOrM586(_), readtable_kind (table , ch , params ) ); 
      if (! running_quote && (v & (0x4 | 0x1 ) ) )
        break ; 
      single_escape = (v & 0x8 ) ; 
      multiple_escape = (v & 0x10 ) ; 
    }
    else {
      single_escape = (ch == '\\' ) ; 
      multiple_escape = ((ch == '|' ) && pipe_quote ) ; 
    }
    if (! ungetc_ok ) {
#     define XfOrM584_COUNT (0+XfOrM573_COUNT)
#     define SETUP_XfOrM584(x) SETUP_XfOrM573(x)
      if (init_ch < 0 )
        FUNCCALL(SETUP_XfOrM584(_), scheme_getc (port ) ); 
      else init_ch = - 1 ; 
    }
    if (single_escape && ! running_quote ) {
      int esc_ch = ch ; 
#     define XfOrM581_COUNT (0+XfOrM573_COUNT)
#     define SETUP_XfOrM581(x) SETUP_XfOrM573(x)
      ch = FUNCCALL(SETUP_XfOrM581(_), scheme_getc_special_ok (port ) ); 
      if (ch == (- 1 ) ) {
#       define XfOrM583_COUNT (0+XfOrM581_COUNT)
#       define SETUP_XfOrM583(x) SETUP_XfOrM581(x)
        (__funcarg129 = FUNCCALL(SETUP_XfOrM583(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg129 , (- 1 ) , indentation , "read: EOF following `%c' in %s" , esc_ch , is_kw ? "keyword" : "symbol" ) )) ; 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      else if (ch == (- 2 ) ) {
#       define XfOrM582_COUNT (0+XfOrM581_COUNT)
#       define SETUP_XfOrM582(x) SETUP_XfOrM581(x)
        FUNCCALL(SETUP_XfOrM582(_), scheme_get_ready_read_special (port , stxsrc , ht ) ); 
        (__funcarg128 = FUNCCALL(SETUP_XfOrM582(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg128 , (- 2 ) , indentation , "read: non-character following `%c' in %s" , esc_ch , is_kw ? "keyword" : "symbol" ) )) ; 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      quoted = 1 ; 
      quoted_ever = 1 ; 
    }
    else if (multiple_escape && (! running_quote || (ch == running_quote_ch ) ) ) {
#     define XfOrM580_COUNT (0+XfOrM573_COUNT)
#     define SETUP_XfOrM580(x) SETUP_XfOrM573(x)
      quoted_ever = 1 ; 
      running_quote = ! running_quote ; 
      running_quote_ch = ch ; 
      quoted = 0 ; 
      FUNCCALL(SETUP_XfOrM580(_), scheme_tell_all (port , & rq_line , & rq_col , & rq_pos ) ); 
      ch = FUNCCALL_AGAIN(getc_special_ok_fun (port ) ); 
      continue ; 
    }
    else quoted = 0 ; 
    if (i >= size ) {
#     define XfOrM579_COUNT (0+XfOrM573_COUNT)
#     define SETUP_XfOrM579(x) SETUP_XfOrM573(x)
      oldsize = size ; 
      oldbuf = buf ; 
      size *= 2 ; 
      buf = (mzchar * ) FUNCCALL(SETUP_XfOrM579(_), GC_malloc_atomic ((size + 1 ) * sizeof (mzchar ) ) ); 
      (memcpy (buf , oldbuf , oldsize * sizeof (mzchar ) ) ) ; 
    }
    if (! case_sens && ! quoted && ! running_quote )
      norm_count ++ ; 
    else if (norm_count ) {
      mzchar * s ; 
      int newlen ; 
      BLOCK_SETUP((PUSH(s, 0+XfOrM573_COUNT)));
#     define XfOrM576_COUNT (1+XfOrM573_COUNT)
#     define SETUP_XfOrM576(x) SETUP(XfOrM576_COUNT)
      s = NULLED_OUT ; 
      s = FUNCCALL(SETUP_XfOrM576(_), scheme_string_recase (buf , i - norm_count , norm_count , 3 , 1 , & newlen ) ); 
      if (s != buf ) {
#       define XfOrM577_COUNT (0+XfOrM576_COUNT)
#       define SETUP_XfOrM577(x) SETUP_XfOrM576(x)
        if ((i + newlen - norm_count ) >= size ) {
#         define XfOrM578_COUNT (0+XfOrM577_COUNT)
#         define SETUP_XfOrM578(x) SETUP_XfOrM577(x)
          oldsize = size ; 
          oldbuf = buf ; 
          size *= 2 ; 
          if (size <= (i + newlen - norm_count ) )
            size = 2 * (i + (newlen - norm_count ) ) ; 
          buf = (mzchar * ) FUNCCALL(SETUP_XfOrM578(_), GC_malloc_atomic ((size + 1 ) * sizeof (mzchar ) ) ); 
          (memcpy (buf , oldbuf , oldsize * sizeof (mzchar ) ) ) ; 
        }
        (memcpy (buf + i - norm_count , s , sizeof (mzchar ) * newlen ) ) ; 
      }
      i += (newlen - norm_count ) ; 
      norm_count = 0 ; 
    }
    buf [i ++ ] = ch ; 
    if (delim_ok & 0x10 ) {
      if ((ch == 'e' ) || (ch == 'E' ) ) {
        delim_ok = (0x8 | 0x10 | 0x20 ) ; 
      }
      else delim_ok = (0x8 | 0x10 ) ; 
    }
    ch = FUNCCALL(SETUP_XfOrM573(_), getc_special_ok_fun (port ) ); 
  }
  if (running_quote && (ch == (- 2 ) ) ) {
#   define XfOrM558_COUNT (0+XfOrM542_COUNT)
#   define SETUP_XfOrM558(x) SETUP_XfOrM542(x)
    FUNCCALL(SETUP_XfOrM558(_), scheme_get_ready_read_special (port , stxsrc , ht ) ); 
    (__funcarg125 = FUNCCALL(SETUP_XfOrM558(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg125 , (- 2 ) , indentation , "read: non-character following `%c' in %s" , running_quote_ch , is_kw ? "keyword" : "symbol" ) )) ; 
  }
  if (ungetc_ok )
    FUNCCALL(SETUP_XfOrM542(_), scheme_ungetc (ch , port ) ); 
  if (running_quote ) {
#   define XfOrM557_COUNT (0+XfOrM542_COUNT)
#   define SETUP_XfOrM557(x) SETUP_XfOrM542(x)
    (__funcarg124 = FUNCCALL(SETUP_XfOrM557(_), SPAN (port , rq_pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , rq_line , rq_col , rq_pos , __funcarg124 , (- 1 ) , indentation , "read: unbalanced `%c'" , running_quote_ch ) )) ; 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (norm_count ) {
    mzchar * s ; 
    int newlen ; 
    BLOCK_SETUP((PUSH(s, 0+XfOrM542_COUNT)));
#   define XfOrM555_COUNT (1+XfOrM542_COUNT)
#   define SETUP_XfOrM555(x) SETUP(XfOrM555_COUNT)
    s = NULLED_OUT ; 
    s = FUNCCALL(SETUP_XfOrM555(_), scheme_string_recase (buf , i - norm_count , norm_count , 3 , 1 , & newlen ) ); 
    if (s != buf ) {
#     define XfOrM556_COUNT (0+XfOrM555_COUNT)
#     define SETUP_XfOrM556(x) SETUP_XfOrM555(x)
      oldsize = size ; 
      oldbuf = buf ; 
      size = i + (newlen - norm_count ) + 1 ; 
      buf = (mzchar * ) FUNCCALL(SETUP_XfOrM556(_), GC_malloc_atomic ((size + 1 ) * sizeof (mzchar ) ) ); 
      (memcpy (buf , oldbuf , oldsize * sizeof (mzchar ) ) ) ; 
      (memcpy (buf + i - norm_count , s , sizeof (mzchar ) * newlen ) ) ; 
    }
    i += (newlen - norm_count ) ; 
  }
  buf [i ] = '\0' ; 
  if (! quoted_ever && (i == 1 ) && (buf [0 ] == '.' ) && ! honu_mode ) {
    long xl , xc , xp ; 
#   define XfOrM554_COUNT (0+XfOrM542_COUNT)
#   define SETUP_XfOrM554(x) SETUP_XfOrM542(x)
    FUNCCALL(SETUP_XfOrM554(_), scheme_tell_all (port , & xl , & xc , & xp ) ); 
    FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , xl , xc , xp , 1 , 0 , indentation , "read: illegal use of \".\"" ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (! i && honu_mode ) {
#   define XfOrM553_COUNT (0+XfOrM542_COUNT)
#   define SETUP_XfOrM553(x) SETUP_XfOrM542(x)
    FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , 1 , 0 , indentation , "read: illegal character: %c" , ch ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (honu_mode && ! is_symbol ) {
    int found_e ; 
#   define XfOrM547_COUNT (0+XfOrM542_COUNT)
#   define SETUP_XfOrM547(x) SETUP_XfOrM542(x)
    found_e = FUNCCALL(SETUP_XfOrM547(_), check_honu_num (buf , i ) ); 
    if (found_e < 0 ) {
#     define XfOrM552_COUNT (0+XfOrM547_COUNT)
#     define SETUP_XfOrM552(x) SETUP_XfOrM547(x)
      (__funcarg123 = FUNCCALL(SETUP_XfOrM552(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg123 , 0 , indentation , "read: bad number: %5" , buf ) )) ; 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    if (delim [buf [i - 1 ] ] & 0x10 ) {
#     define XfOrM548_COUNT (0+XfOrM547_COUNT)
#     define SETUP_XfOrM548(x) SETUP_XfOrM547(x)
      if (found_e ) {
        buf [found_e ] = buf [i - 1 ] ; 
        i -- ; 
      }
      else {
#       define XfOrM549_COUNT (0+XfOrM548_COUNT)
#       define SETUP_XfOrM549(x) SETUP_XfOrM548(x)
        if (i >= size ) {
#         define XfOrM550_COUNT (0+XfOrM549_COUNT)
#         define SETUP_XfOrM550(x) SETUP_XfOrM549(x)
          oldsize = size ; 
          oldbuf = buf ; 
          size *= 2 ; 
          buf = (mzchar * ) FUNCCALL(SETUP_XfOrM550(_), GC_malloc_atomic ((size + 1 ) * sizeof (mzchar ) ) ); 
          (memcpy (buf , oldbuf , oldsize * sizeof (mzchar ) ) ) ; 
        }
        buf [i ++ ] = '0' ; 
        buf [i ] = 0 ; 
      }
    }
  }
  if ((is_symbol || quoted_ever ) && ! is_float && ! is_not_float && ! radix_set )
    o = scheme_false ; 
  else {
#   define XfOrM546_COUNT (0+XfOrM542_COUNT)
#   define SETUP_XfOrM546(x) SETUP_XfOrM542(x)
    o = (__funcarg122 = FUNCCALL(SETUP_XfOrM546(_), SPAN (port , pos ) ), FUNCCALL_AGAIN(scheme_read_number (buf , i , is_float , is_not_float , decimal_inexact , radix , radix_set , port , ((void * ) 0 ) , 0 , stxsrc , line , col , pos , __funcarg122 , indentation ) )) ; 
  }
  if (((o ) == (scheme_false ) ) ) {
#   define XfOrM543_COUNT (0+XfOrM542_COUNT)
#   define SETUP_XfOrM543(x) SETUP_XfOrM542(x)
    if (honu_mode && ! is_symbol ) {
#     define XfOrM545_COUNT (0+XfOrM543_COUNT)
#     define SETUP_XfOrM545(x) SETUP_XfOrM543(x)
      (__funcarg121 = FUNCCALL(SETUP_XfOrM545(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg121 , 0 , indentation , "read: bad number: %5" , buf ) )) ; 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    if (is_kw ) {
#     define XfOrM544_COUNT (0+XfOrM543_COUNT)
#     define SETUP_XfOrM544(x) SETUP_XfOrM543(x)
      o = FUNCCALL(SETUP_XfOrM544(_), scheme_intern_exact_char_keyword (buf , i ) ); 
    }
    else o = FUNCCALL(SETUP_XfOrM543(_), scheme_intern_exact_char_symbol (buf , i ) ); 
  }
  if (stxsrc )
    o = (__funcarg120 = FUNCCALL(SETUP_XfOrM542(_), SPAN (port , pos ) ), FUNCCALL_AGAIN(scheme_make_stx_w_offset (o , line , col , pos , __funcarg120 , stxsrc , scheme_false ) )) ; 
  RET_VALUE_START (o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * read_number (int init_ch , Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , int is_float , int is_not_float , int radix , int radix_set , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params , Readtable * table ) {
  /* No conversion */
  return read_number_or_symbol (init_ch , init_ch < 0 , port , stxsrc , line , col , pos , is_float , is_not_float , radix , radix_set , 0 , 0 , params -> can_read_pipe_quote , ht , indentation , params , table ) ; 
}
static Scheme_Object * read_symbol (int init_ch , int skip_rt , Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params , Readtable * table ) {
  /* No conversion */
  return read_number_or_symbol (init_ch , skip_rt , port , stxsrc , line , col , pos , 0 , 0 , 10 , 0 , 1 , 0 , params -> can_read_pipe_quote , ht , indentation , params , table ) ; 
}
static Scheme_Object * read_keyword (int init_ch , Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params , Readtable * table ) {
  /* No conversion */
  return read_number_or_symbol (init_ch , 1 , port , stxsrc , line , col , pos , 0 , 0 , 10 , 0 , 1 , 1 , params -> can_read_pipe_quote , ht , indentation , params , table ) ; 
}
static int check_honu_num (mzchar * buf , int i ) {
  /* No conversion */
  int j , found_e = 0 , found_dot = 0 ; 
  for (j = 0 ; j < i ; j ++ ) {
    if (buf [j ] == '.' ) {
      if (found_dot ) {
        j = 0 ; 
        break ; 
      }
      found_dot = 1 ; 
    }
    else if ((buf [j ] == 'e' ) || (buf [j ] == 'E' ) ) {
      if (! j )
        break ; 
      found_e = j ; 
      j ++ ; 
      if ((buf [j ] == '+' ) || (buf [j ] == '-' ) )
        j ++ ; 
      if (! ((buf [j ] >= '0' ) && (buf [j ] <= '9' ) ) ) {
        j = 0 ; 
        break ; 
      }
      while (((buf [j ] >= '0' ) && (buf [j ] <= '9' ) ) ) {
        j ++ ; 
      }
      if (! buf [j ] )
        break ; 
      if (buf [j + 1 ] ) {
        j = 0 ; 
        break ; 
      }
      switch (buf [j ] ) {
        case 'd' : case 'D' : case 'f' : case 'F' : break ; 
        default : j = 0 ; 
        break ; 
      }
      break ; 
    }
    else if (delim [buf [j ] ] & 0x10 ) {
      if (j + 1 == i ) {
      }
      else {
        j = 0 ; 
        break ; 
      }
    }
  }
  if (! j ) {
    return - 1 ; 
  }
  return found_e ; 
}
static int u_strcmp (mzchar * s , const char * _t ) {
  /* No conversion */
  int i ; 
  unsigned char * t = (unsigned char * ) _t ; 
  for (i = 0 ; s [i ] && ((s [i ] + scheme_uchar_downs [(scheme_uchar_cases_table [(s [i ] >> 8 ) & 0x1FFF ] [s [i ] & 0xFF ] ) ] ) == ((mzchar ) ((unsigned char * ) t ) [i ] + scheme_uchar_downs [(scheme_uchar_cases_table [((mzchar ) ((unsigned char * ) t ) [i ] >> 8 ) & 0x1FFF ] [(mzchar ) ((unsigned char * ) t ) [i ] & 0xFF ] ) ] ) ) ; i ++ ) {
  }
  if (s [i ] || t [i ] )
    return 1 ; 
  return 0 ; 
}
/* this far 3808 */
/* this far 3808 */
static Scheme_Object * read_character (Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params ) {
  int ch , next ; 
  long __funcarg131 ; 
  long __funcarg130 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(indentation, 0), PUSH(port, 1), PUSH(stxsrc, 2), PUSH(ht, 3)));
# define XfOrM630_COUNT (4)
# define SETUP_XfOrM630(x) SETUP(XfOrM630_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  ch = FUNCCALL(SETUP_XfOrM630(_), scheme_getc_special_ok (port ) ); 
  if (ch == (- 2 ) ) {
#   define XfOrM647_COUNT (0+XfOrM630_COUNT)
#   define SETUP_XfOrM647(x) SETUP_XfOrM630(x)
    FUNCCALL(SETUP_XfOrM647(_), scheme_get_ready_read_special (port , stxsrc , ht ) ); 
    (__funcarg131 = FUNCCALL(SETUP_XfOrM647(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg131 , (- 2 ) , indentation , "read: found non-character after #\\" ) )) ; 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  next = FUNCCALL(SETUP_XfOrM630(_), scheme_peekc_special_ok (port ) ); 
  if ((ch >= '0' && ch <= '7' ) && (next >= '0' && next <= '7' ) ) {
    int last ; 
#   define XfOrM645_COUNT (0+XfOrM630_COUNT)
#   define SETUP_XfOrM645(x) SETUP_XfOrM630(x)
    last = (FUNCCALL(SETUP_XfOrM645(_), scheme_getc (port ) ), FUNCCALL(SETUP_XfOrM645(_), scheme_peekc_special_ok (port ) )) ; 
    if (last != (- 2 ) )
      FUNCCALL(SETUP_XfOrM645(_), scheme_getc (port ) ); 
    if (last < '0' || last > '7' || ch > '3' ) {
#     define XfOrM646_COUNT (0+XfOrM645_COUNT)
#     define SETUP_XfOrM646(x) SETUP_XfOrM645(x)
      FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , ((last == (- 1 ) ) || (last == (- 2 ) ) ) ? 3 : 4 , last , indentation , "read: bad character constant #\\%c%c%c" , ch , next , ((last == (- 1 ) ) || (last == (- 2 ) ) ) ? ' ' : last ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    ch = ((ch - '0' ) << 6 ) + ((next - '0' ) << 3 ) + (last - '0' ) ; 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_char (ch ) )) RET_VALUE_EMPTY_END ; 
  }
  if (((ch == 'u' ) || (ch == 'U' ) ) && ((next ) >= 0 ) && (((next >= '0' ) && (next <= '9' ) ) || ((next >= 'a' ) && (next <= 'f' ) ) || ((next >= 'A' ) && (next <= 'F' ) ) ) ) {
    int count = 0 , n = 0 , nbuf [10 ] , maxc = ((ch == 'u' ) ? 4 : 8 ) ; 
#   define XfOrM638_COUNT (0+XfOrM630_COUNT)
#   define SETUP_XfOrM638(x) SETUP_XfOrM630(x)
    while (count < maxc ) {
#     define XfOrM643_COUNT (0+XfOrM638_COUNT)
#     define SETUP_XfOrM643(x) SETUP_XfOrM638(x)
      ch = FUNCCALL(SETUP_XfOrM643(_), scheme_peekc_special_ok (port ) ); 
      if (((ch ) >= 0 ) && (((ch >= '0' ) && (ch <= '9' ) ) || ((ch >= 'a' ) && (ch <= 'f' ) ) || ((ch >= 'A' ) && (ch <= 'F' ) ) ) ) {
#       define XfOrM644_COUNT (0+XfOrM643_COUNT)
#       define SETUP_XfOrM644(x) SETUP_XfOrM643(x)
        nbuf [count ] = ch ; 
        n = n * 16 + (ch <= '9' ? ch - '0' : ((ch + scheme_uchar_ups [(scheme_uchar_cases_table [(ch >> 8 ) & 0x1FFF ] [ch & 0xFF ] ) ] ) - 'A' + 10 ) ) ; 
        FUNCCALL(SETUP_XfOrM644(_), scheme_getc (port ) ); 
        count ++ ; 
      }
      else break ; 
    }
    if ((n < 0 ) || ((n >= 0xD800 ) && (n <= 0xDFFF ) ) || (n > 0x10FFFF ) ) {
#     define XfOrM640_COUNT (0+XfOrM638_COUNT)
#     define SETUP_XfOrM640(x) SETUP_XfOrM638(x)
      FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , count + 2 , 0 , indentation , "read: bad character constant #\\%c%u" , (maxc == 4 ) ? 'u' : 'U' , nbuf , count ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else {
      ch = n ; 
    }
  }
  else if ((ch != (- 1 ) ) && (((scheme_uchar_table [(ch >> 8 ) & 0x1FFF ] [ch & 0xFF ] ) ) & 0x80 ) && ((next ) >= 0 ) && (((scheme_uchar_table [(next >> 8 ) & 0x1FFF ] [next & 0xFF ] ) ) & 0x80 ) ) {
    mzchar * buf , * oldbuf , onstack [32 ] ; 
    int i ; 
    long size = 31 , oldsize ; 
    BLOCK_SETUP((PUSH(buf, 0+XfOrM630_COUNT), PUSH(oldbuf, 1+XfOrM630_COUNT)));
#   define XfOrM632_COUNT (2+XfOrM630_COUNT)
#   define SETUP_XfOrM632(x) SETUP(XfOrM632_COUNT)
    buf = NULLED_OUT ; 
    oldbuf = NULLED_OUT ; 
    i = 1 ; 
    buf = onstack ; 
    buf [0 ] = ch ; 
    while ((ch = FUNCCALL(SETUP_XfOrM632(_), scheme_peekc_special_ok (port ) ), ((ch ) >= 0 ) && (((scheme_uchar_table [(ch >> 8 ) & 0x1FFF ] [ch & 0xFF ] ) ) & 0x80 ) ) ) {
#     define XfOrM636_COUNT (0+XfOrM632_COUNT)
#     define SETUP_XfOrM636(x) SETUP_XfOrM632(x)
      FUNCCALL(SETUP_XfOrM636(_), scheme_getc (port ) ); 
      if (i >= size ) {
#       define XfOrM637_COUNT (0+XfOrM636_COUNT)
#       define SETUP_XfOrM637(x) SETUP_XfOrM636(x)
        oldsize = size ; 
        oldbuf = buf ; 
        size *= 2 ; 
        buf = (mzchar * ) FUNCCALL(SETUP_XfOrM637(_), GC_malloc_atomic ((size + 1 ) * sizeof (mzchar ) ) ); 
        (memcpy (buf , oldbuf , oldsize * sizeof (mzchar ) ) ) ; 
      }
      buf [i ++ ] = ch ; 
    }
    buf [i ] = '\0' ; 
    switch ((buf [0 ] + scheme_uchar_downs [(scheme_uchar_cases_table [(buf [0 ] >> 8 ) & 0x1FFF ] [buf [0 ] & 0xFF ] ) ] ) ) {
#     define XfOrM633_COUNT (0+XfOrM632_COUNT)
#     define SETUP_XfOrM633(x) SETUP_XfOrM632(x)
      case 'n' : if (! FUNCCALL(SETUP_XfOrM633(_), u_strcmp (buf , "newline" ) ))
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_char ('\n' ) )) RET_VALUE_EMPTY_END ; 
      if (! FUNCCALL(SETUP_XfOrM633(_), u_strcmp (buf , "null" ) )|| ! FUNCCALL(SETUP_XfOrM633(_), u_strcmp (buf , "nul" ) ))
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_char ('\0' ) )) RET_VALUE_EMPTY_END ; 
      break ; 
      case 's' : if (! FUNCCALL(SETUP_XfOrM633(_), u_strcmp (buf , "space" ) ))
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_char (' ' ) )) RET_VALUE_EMPTY_END ; 
      break ; 
      case 'r' : if (! FUNCCALL(SETUP_XfOrM633(_), u_strcmp (buf , "rubout" ) ))
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_char (0x7f ) )) RET_VALUE_EMPTY_END ; 
      if (! FUNCCALL(SETUP_XfOrM633(_), u_strcmp (buf , "return" ) ))
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_char ('\r' ) )) RET_VALUE_EMPTY_END ; 
      break ; 
      case 'p' : if (! FUNCCALL(SETUP_XfOrM633(_), u_strcmp (buf , "page" ) ))
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_char ('\f' ) )) RET_VALUE_EMPTY_END ; 
      break ; 
      case 't' : if (! FUNCCALL(SETUP_XfOrM633(_), u_strcmp (buf , "tab" ) ))
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_char ('\t' ) )) RET_VALUE_EMPTY_END ; 
      break ; 
      case 'v' : if (! FUNCCALL(SETUP_XfOrM633(_), u_strcmp (buf , "vtab" ) ))
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_char (0xb ) )) RET_VALUE_EMPTY_END ; 
      break ; 
      case 'b' : if (! FUNCCALL(SETUP_XfOrM633(_), u_strcmp (buf , "backspace" ) ))
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_char ('\b' ) )) RET_VALUE_EMPTY_END ; 
      break ; 
      case 'l' : if (! FUNCCALL(SETUP_XfOrM633(_), u_strcmp (buf , "linefeed" ) ))
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_char ('\n' ) )) RET_VALUE_EMPTY_END ; 
      break ; 
      default : break ; 
    }
    (__funcarg130 = FUNCCALL(SETUP_XfOrM632(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg130 , 0 , indentation , "read: bad character constant: #\\%5" , buf ) )) ; 
  }
  if (ch == (- 1 ) ) {
#   define XfOrM631_COUNT (0+XfOrM630_COUNT)
#   define SETUP_XfOrM631(x) SETUP_XfOrM630(x)
    FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , 2 , (- 1 ) , indentation , "read: expected a character after #\\" ) ); 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_char (ch ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * read_quote (char * who , Scheme_Object * quote_symbol , int len , Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params ) {
  Scheme_Object * obj , * ret ; 
  Scheme_Object * __funcarg133 = NULLED_OUT ; 
  long __funcarg132 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSH(indentation, 0), PUSH(stxsrc, 1), PUSH(ret, 2), PUSH(port, 3), PUSH(obj, 4), PUSH(quote_symbol, 5), PUSH(who, 6)));
# define XfOrM648_COUNT (7)
# define SETUP_XfOrM648(x) SETUP(XfOrM648_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  obj = NULLED_OUT ; 
  ret = NULLED_OUT ; 
  obj = FUNCCALL(SETUP_XfOrM648(_), read_inner (port , stxsrc , ht , indentation , params , 0 ) ); 
  if ((((obj ) ) == (scheme_eof ) ) )
    FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , len , (- 1 ) , indentation , "read: expected an element for %s (found end-of-file)" , who ) ); 
  ret = (stxsrc ? FUNCCALL(SETUP_XfOrM648(_), scheme_make_stx_w_offset (quote_symbol , line , col , pos , len , stxsrc , scheme_false ) ): quote_symbol ) ; 
  ret = (__funcarg133 = FUNCCALL(SETUP_XfOrM648(_), scheme_make_pair (obj , scheme_null ) ), FUNCCALL_AGAIN(scheme_make_pair (ret , __funcarg133 ) )) ; 
  if (stxsrc ) {
#   define XfOrM649_COUNT (0+XfOrM648_COUNT)
#   define SETUP_XfOrM649(x) SETUP_XfOrM648(x)
    ((((Scheme_Inclhash_Object * ) (ret ) ) -> so . keyex |= 0x1 ) ) ; 
    ((((Scheme_Inclhash_Object * ) ((((Scheme_Simple_Object * ) (ret ) ) -> u . pair_val . cdr ) ) ) -> so . keyex |= 0x1 ) ) ; 
    ret = (__funcarg132 = FUNCCALL(SETUP_XfOrM649(_), SPAN (port , pos ) ), FUNCCALL_AGAIN(scheme_make_stx_w_offset (ret , line , col , pos , __funcarg132 , stxsrc , scheme_false ) )) ; 
  }
  RET_VALUE_START (ret ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * read_box (Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params ) {
  Scheme_Object * o , * bx ; 
  long __funcarg134 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(indentation, 0), PUSH(port, 1), PUSH(stxsrc, 2), PUSH(bx, 3), PUSH(o, 4)));
# define XfOrM650_COUNT (5)
# define SETUP_XfOrM650(x) SETUP(XfOrM650_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  o = NULLED_OUT ; 
  bx = NULLED_OUT ; 
  o = FUNCCALL(SETUP_XfOrM650(_), read_inner (port , stxsrc , ht , indentation , params , 0 ) ); 
  if ((((o ) ) == (scheme_eof ) ) )
    FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , 2 , (- 1 ) , indentation , "read: expected an element for #& box (found end-of-file)" ) ); 
  bx = FUNCCALL(SETUP_XfOrM650(_), scheme_box (o ) ); 
  if (stxsrc ) {
#   define XfOrM651_COUNT (0+XfOrM650_COUNT)
#   define SETUP_XfOrM651(x) SETUP_XfOrM650(x)
    ((((Scheme_Inclhash_Object * ) (bx ) ) -> so . keyex |= 0x1 ) ) ; 
    bx = (__funcarg134 = FUNCCALL(SETUP_XfOrM651(_), SPAN (port , pos ) ), FUNCCALL_AGAIN(scheme_make_stx_w_offset (bx , line , col , pos , __funcarg134 , stxsrc , scheme_false ) )) ; 
  }
  RET_VALUE_START (bx ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * read_hash (Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , char closer , int eq , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params ) {
  Scheme_Object * l , * result ; 
  Scheme_Hash_Table * t ; 
  long __funcarg135 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(ht, 0), PUSH(t, 1), PUSH(stxsrc, 2), PUSH(port, 3), PUSH(result, 4), PUSH(l, 5)));
# define XfOrM652_COUNT (6)
# define SETUP_XfOrM652(x) SETUP(XfOrM652_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  l = NULLED_OUT ; 
  result = NULLED_OUT ; 
  t = NULLED_OUT ; 
  l = FUNCCALL(SETUP_XfOrM652(_), read_list (port , stxsrc , line , col , pos , closer , 2 , 0 , ht , indentation , params ) ); 
  if (eq )
    t = FUNCCALL(SETUP_XfOrM652(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  else t = FUNCCALL(SETUP_XfOrM652(_), scheme_make_hash_table_equal () ); 
  FUNCCALL(SETUP_XfOrM652(_), scheme_hash_set (t , an_uninterned_symbol , l ) ); 
  if (! * ht ) {
    Scheme_Hash_Table * tht ; 
    BLOCK_SETUP((PUSH(tht, 0+XfOrM652_COUNT)));
#   define XfOrM653_COUNT (1+XfOrM652_COUNT)
#   define SETUP_XfOrM653(x) SETUP(XfOrM653_COUNT)
    tht = NULLED_OUT ; 
    tht = FUNCCALL(SETUP_XfOrM653(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
    * ht = tht ; 
  }
  result = (Scheme_Object * ) t ; 
  if (stxsrc )
    result = (__funcarg135 = FUNCCALL(SETUP_XfOrM652(_), SPAN (port , pos ) ), FUNCCALL_AGAIN(scheme_make_stx_w_offset (result , line , col , pos , __funcarg135 , stxsrc , scheme_false ) )) ; 
  RET_VALUE_START (result ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int skip_whitespace_comments (Scheme_Object * port , Scheme_Object * stxsrc , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params ) {
  int ch ; 
  int blockc_1 , blockc_2 ; 
  long __funcarg138 ; 
  long __funcarg136 ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(indentation, 0), PUSH(ht, 1), PUSH(stxsrc, 2), PUSH(params, 3), PUSH(port, 4)));
# define XfOrM654_COUNT (5)
# define SETUP_XfOrM654(x) SETUP(XfOrM654_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (params -> honu_mode ) {
    blockc_1 = '/' ; 
    blockc_2 = '*' ; 
  }
  else {
    blockc_1 = '#' ; 
    blockc_2 = '|' ; 
  }
  start_over : if (params -> table ) {
#   define XfOrM670_COUNT (0+XfOrM654_COUNT)
#   define SETUP_XfOrM670(x) SETUP_XfOrM654(x)
    while ((ch = FUNCCALL(SETUP_XfOrM670(_), scheme_getc_special_ok (port ) ), ((ch ) >= 0 ) ) ) {
#     define XfOrM672_COUNT (0+XfOrM670_COUNT)
#     define SETUP_XfOrM672(x) SETUP_XfOrM670(x)
      if (! (FUNCCALL(SETUP_XfOrM672(_), readtable_kind (params -> table , ch , params ) )& 0x1 ) )
        break ; 
    }
    RET_VALUE_START (ch ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM667_COUNT (0+XfOrM654_COUNT)
#   define SETUP_XfOrM667(x) SETUP_XfOrM654(x)
    while ((ch = FUNCCALL(SETUP_XfOrM667(_), scheme_getc_special_ok (port ) ), ((ch ) >= 0 ) && (((scheme_uchar_table [(ch >> 8 ) & 0x1FFF ] [ch & 0xFF ] ) ) & 0x10 ) ) ) {
    }
  }
  if ((! params -> honu_mode && (ch == ';' ) ) || (params -> honu_mode && (ch == '/' ) && (FUNCCALL(SETUP_XfOrM654(_), scheme_peekc_special_ok (port ) )== '/' ) ) ) {
#   define XfOrM664_COUNT (0+XfOrM654_COUNT)
#   define SETUP_XfOrM664(x) SETUP_XfOrM654(x)
    do {
#     define XfOrM666_COUNT (0+XfOrM664_COUNT)
#     define SETUP_XfOrM666(x) SETUP_XfOrM664(x)
      ch = FUNCCALL(SETUP_XfOrM666(_), scheme_getc_special_ok (port ) ); 
      if (ch == (- 2 ) )
        FUNCCALL(SETUP_XfOrM666(_), scheme_get_ready_read_special (port , stxsrc , ht ) ); 
    }
    while (ch != '\n' && ch != '\r' && ch != (- 1 ) ) ; 
    goto start_over ; 
  }
  if (ch == blockc_1 && (FUNCCALL(SETUP_XfOrM654(_), scheme_peekc_special_ok (port ) )== blockc_2 ) ) {
    int depth = 0 ; 
    int ch2 = 0 ; 
    long col , pos , line ; 
#   define XfOrM657_COUNT (0+XfOrM654_COUNT)
#   define SETUP_XfOrM657(x) SETUP_XfOrM654(x)
    FUNCCALL(SETUP_XfOrM657(_), scheme_tell_all (port , & line , & col , & pos ) ); 
    (void ) FUNCCALL(SETUP_XfOrM657(_), scheme_getc (port ) ); 
    do {
#     define XfOrM661_COUNT (0+XfOrM657_COUNT)
#     define SETUP_XfOrM661(x) SETUP_XfOrM657(x)
      ch = FUNCCALL(SETUP_XfOrM661(_), scheme_getc_special_ok (port ) ); 
      if (ch == (- 1 ) )
        (__funcarg138 = FUNCCALL(SETUP_XfOrM661(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg138 , (- 1 ) , indentation , "read: end of file in #| comment" ) )) ; 
      else if (ch == (- 2 ) )
        FUNCCALL(SETUP_XfOrM661(_), scheme_get_ready_read_special (port , stxsrc , ht ) ); 
      if ((ch2 == blockc_2 ) && (ch == blockc_1 ) ) {
        if (! (depth -- ) )
          goto start_over ; 
        ch = 0 ; 
      }
      else if ((ch2 == blockc_1 ) && (ch == blockc_2 ) ) {
        depth ++ ; 
        ch = 0 ; 
      }
      ch2 = ch ; 
    }
    while (1 ) ; 
    goto start_over ; 
  }
  if (ch == '#' && (FUNCCALL(SETUP_XfOrM654(_), scheme_peekc_special_ok (port ) )== ';' ) ) {
    Scheme_Object * skipped ; 
    long col , pos , line ; 
    BLOCK_SETUP((PUSH(skipped, 0+XfOrM654_COUNT)));
#   define XfOrM655_COUNT (1+XfOrM654_COUNT)
#   define SETUP_XfOrM655(x) SETUP(XfOrM655_COUNT)
    skipped = NULLED_OUT ; 
    FUNCCALL(SETUP_XfOrM655(_), scheme_tell_all (port , & line , & col , & pos ) ); 
    FUNCCALL_AGAIN(track_indentation (indentation , line , col ) ); 
    (void ) FUNCCALL(SETUP_XfOrM655(_), scheme_getc (port ) ); 
    skipped = FUNCCALL(SETUP_XfOrM655(_), read_inner (port , stxsrc , ht , indentation , params , 0 ) ); 
    if ((((skipped ) ) == (scheme_eof ) ) )
      (__funcarg136 = FUNCCALL(SETUP_XfOrM655(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg136 , (- 1 ) , indentation , "read: expected a commented-out element for `#;' (found end-of-file)" ) )) ; 
    if (* ht ) {
      Scheme_Object * v ; 
      BLOCK_SETUP((PUSH(v, 0+XfOrM655_COUNT)));
#     define XfOrM656_COUNT (1+XfOrM655_COUNT)
#     define SETUP_XfOrM656(x) SETUP(XfOrM656_COUNT)
      v = NULLED_OUT ; 
      v = FUNCCALL(SETUP_XfOrM656(_), scheme_hash_get (* ht , an_uninterned_symbol ) ); 
      if (! v )
        v = scheme_null ; 
      v = FUNCCALL(SETUP_XfOrM656(_), scheme_make_pair (skipped , v ) ); 
      FUNCCALL_AGAIN(scheme_hash_set (* ht , an_uninterned_symbol , v ) ); 
    }
    goto start_over ; 
  }
  RET_VALUE_START (ch ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void unexpected_closer (int ch , Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , Scheme_Object * indentation , ReadParams * params ) {
  char * suggestion = "" , * found = "unexpected" ; 
  const char * __funcarg143 = NULLED_OUT ; 
  const char * __funcarg142 = NULLED_OUT ; 
  const char * __funcarg141 = NULLED_OUT ; 
  const char * __funcarg140 = NULLED_OUT ; 
  const char * __funcarg139 = NULLED_OUT ; 
  PREPARE_VAR_STACK(10);
  BLOCK_SETUP_TOP((PUSH(indentation, 0), PUSH(port, 1), PUSH(stxsrc, 2), PUSH(__funcarg140, 3), PUSH(found, 4), PUSH(params, 5), PUSH(suggestion, 6), PUSH(__funcarg142, 7)));
# define XfOrM675_COUNT (8)
# define SETUP_XfOrM675(x) SETUP(XfOrM675_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (((Scheme_Type ) (((((long ) (indentation ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (indentation ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
    Scheme_Indent * indt ; 
    int opener ; 
    char * missing ; 
    BLOCK_SETUP((PUSH(indt, 0+XfOrM675_COUNT), PUSH(missing, 1+XfOrM675_COUNT)));
#   define XfOrM676_COUNT (2+XfOrM675_COUNT)
#   define SETUP_XfOrM676(x) SETUP(XfOrM676_COUNT)
    indt = NULLED_OUT ; 
    missing = NULLED_OUT ; 
    indt = (Scheme_Indent * ) (((Scheme_Simple_Object * ) (indentation ) ) -> u . pair_val . car ) ; 
    found = FUNCCALL(SETUP_XfOrM676(_), GC_malloc_atomic (100 ) ); 
    if (indt -> closer == '}' )
      opener = '{' ; 
    else if (indt -> closer == ']' )
      opener = '[' ; 
    else opener = '(' ; 
    {
      Scheme_Object * l ; 
      Scheme_Indent * indt2 ; 
      l = NULLED_OUT ; 
      indt2 = NULLED_OUT ; 
      missing = "expected" ; 
      for (l = (((Scheme_Simple_Object * ) (indentation ) ) -> u . pair_val . cdr ) ; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
        indt2 = (Scheme_Indent * ) (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
        if (indt2 -> closer == ch ) {
          missing = "missing" ; 
        }
      }
    }
    if (ch == indt -> closer ) {
#     define XfOrM680_COUNT (0+XfOrM676_COUNT)
#     define SETUP_XfOrM680(x) SETUP_XfOrM676(x)
      (sprintf (found , "unexpected" ) ) ; 
    }
    else if (indt -> multiline ) {
#     define XfOrM679_COUNT (0+XfOrM676_COUNT)
#     define SETUP_XfOrM679(x) SETUP_XfOrM676(x)
      (__funcarg142 = FUNCCALL(SETUP_XfOrM679(_), closer_name (params , indt -> closer ) ), __funcarg143 = FUNCCALL(SETUP_XfOrM679(_), opener_name (params , opener ) ), (sprintf (found , "%s %s to close %s on line %ld, found instead" , missing , __funcarg142 , __funcarg143 , indt -> start_line ) ) ) ; 
    }
    else {
#     define XfOrM678_COUNT (0+XfOrM676_COUNT)
#     define SETUP_XfOrM678(x) SETUP_XfOrM676(x)
      (__funcarg140 = FUNCCALL(SETUP_XfOrM678(_), closer_name (params , indt -> closer ) ), __funcarg141 = FUNCCALL(SETUP_XfOrM678(_), opener_name (params , opener ) ), (sprintf (found , "%s %s to close preceding %s, found instead" , missing , __funcarg140 , __funcarg141 ) ) ) ; 
    }
    if (indt -> suspicious_line ) {
#     define XfOrM677_COUNT (0+XfOrM676_COUNT)
#     define SETUP_XfOrM677(x) SETUP_XfOrM676(x)
      suggestion = FUNCCALL(SETUP_XfOrM677(_), GC_malloc_atomic (100 ) ); 
      (__funcarg139 = FUNCCALL(SETUP_XfOrM677(_), closer_name (params , indt -> suspicious_closer ) ), (sprintf (suggestion , "; indentation suggests a missing %s before line %ld" , __funcarg139 , indt -> suspicious_line ) ) ) ; 
    }
  }
  FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , 1 , 0 , indentation , "read: %s `%c'%s" , found , ch , suggestion ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void pop_indentation (Scheme_Object * indentation ) {
  /* No conversion */
  if (((Scheme_Type ) (((((long ) (indentation ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (indentation ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
    Scheme_Indent * indt ; 
    indt = (Scheme_Indent * ) (((Scheme_Simple_Object * ) (indentation ) ) -> u . pair_val . car ) ; 
    indentation = (((Scheme_Simple_Object * ) (indentation ) ) -> u . pair_val . cdr ) ; 
    if (((Scheme_Type ) (((((long ) (indentation ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (indentation ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
      Scheme_Indent * old_indt ; 
      old_indt = (Scheme_Indent * ) (((Scheme_Simple_Object * ) (indentation ) ) -> u . pair_val . car ) ; 
      if (! old_indt -> suspicious_line ) {
        if (indt -> suspicious_line ) {
          old_indt -> suspicious_line = indt -> suspicious_line ; 
          old_indt -> suspicious_closer = indt -> suspicious_closer ; 
        }
      }
      if (! old_indt -> suspicious_quote ) {
        if (indt -> suspicious_quote ) {
          old_indt -> suspicious_quote = indt -> suspicious_quote ; 
          old_indt -> quote_for_char = indt -> quote_for_char ; 
        }
      }
    }
  }
}
typedef struct Scheme_Load_Delay {
  Scheme_Type type ; 
  Scheme_Object * path ; 
  long file_offset , size ; 
  unsigned long symtab_size ; 
  Scheme_Object * * symtab ; 
  long * shared_offsets ; 
  Scheme_Object * insp ; 
  Scheme_Hash_Table * rn_memory ; 
}
Scheme_Load_Delay ; 
typedef struct CPort {
  Scheme_Type type ; 
  unsigned long pos , size ; 
  unsigned char * start ; 
  unsigned long symtab_size ; 
  long base ; 
  Scheme_Object * orig_port ; 
  Scheme_Hash_Table * * ht ; 
  Scheme_Unmarshal_Tables * ut ; 
  Scheme_Object * * symtab ; 
  Scheme_Object * insp ; 
  Scheme_Object * magic_sym , * magic_val ; 
  long * shared_offsets ; 
  Scheme_Load_Delay * delay_info ; 
}
CPort ; 
static Scheme_Object * read_marshalled (int type , CPort * port ) ; 
static Scheme_Object * read_compact_list (int c , int proper , int use_stack , CPort * port ) ; 
static Scheme_Object * read_compact_quote (CPort * port , int embedded ) ; 
void scheme_ill_formed (struct CPort * port , const char * file , int line ) {
  /* No conversion */
  scheme_read_err (port -> orig_port , ((void * ) 0 ) , - 1 , - 1 , (port -> pos + port -> base ) , - 1 , 0 , ((void * ) 0 ) , "read (compiled): ill-formed code" " [%s:%d]" , file , line ) ; 
}
__xform_nongcing__ static long read_compact_number (CPort * port ) {
  /* No conversion */
  long flag , v , a , b , c , d ; 
  if (! (port -> pos < port -> size ) )
    return 0 ; 
  ; 
  flag = ((int ) (port -> start [port -> pos ++ ] ) ) ; 
  if (flag < 128 )
    return flag ; 
  else if (! (flag & 0x40 ) ) {
    if (! (port -> pos < port -> size ) )
      return 0 ; 
    ; 
    a = ((int ) (port -> start [port -> pos ++ ] ) ) ; 
    v = (flag & 0x3F ) + (a << 6 ) ; 
    return v ; 
  }
  else if (! (flag & 0x20 ) ) {
    return - (flag & 0x1F ) ; 
  }
  if (! (port -> pos + 3 < port -> size ) )
    return 0 ; 
  ; 
  a = ((int ) (port -> start [port -> pos ++ ] ) ) ; 
  b = ((int ) (port -> start [port -> pos ++ ] ) ) ; 
  c = ((int ) (port -> start [port -> pos ++ ] ) ) ; 
  d = ((int ) (port -> start [port -> pos ++ ] ) ) ; 
  v = a + (b << 8 ) + (c << 16 ) + (d << 24 ) ; 
  if (flag & 0x10 )
    return v ; 
  else return - v ; 
}
static char * read_compact_chars (CPort * port , char * buffer , int bsize , int l ) {
  char * s ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(port, 1)));
# define XfOrM697_COUNT (2)
# define SETUP_XfOrM697(x) SETUP(XfOrM697_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  if (l < bsize )
    s = buffer ; 
  else s = (char * ) FUNCCALL(SETUP_XfOrM697(_), GC_malloc_atomic (l + 1 ) ); 
  (memcpy (s , port -> start + port -> pos , l ) ) ; 
  port -> pos += l ; 
  s [l ] = 0 ; 
  RET_VALUE_START (s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * read_compact_svector (CPort * port , int l ) {
  Scheme_Object * o ; 
  mzshort * v ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(v, 1), PUSH(port, 2)));
# define XfOrM698_COUNT (3)
# define SETUP_XfOrM698(x) SETUP(XfOrM698_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  o = NULLED_OUT ; 
  v = NULLED_OUT ; 
  o = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM698(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  o -> type = scheme_svector_type ; 
  (((Scheme_Simple_Object * ) (o ) ) -> u . svector_val . len ) = l ; 
  if (l )
    v = ((mzshort * ) FUNCCALL(SETUP_XfOrM698(_), GC_malloc_atomic (sizeof (mzshort ) * (l ) ) )) ; 
  else v = ((void * ) 0 ) ; 
  (((Scheme_Simple_Object * ) (o ) ) -> u . svector_val . vec ) = v ; 
  while (l -- ) {
    mzshort cn ; 
#   define XfOrM700_COUNT (0+XfOrM698_COUNT)
#   define SETUP_XfOrM700(x) SETUP_XfOrM698(x)
    cn = (read_compact_number (port ) ) ; 
    v [l ] = cn ; 
  }
  RET_VALUE_START (o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int cpt_branch [256 ] ; 
static Scheme_Object * read_compact (CPort * port , int use_stack ) ; 
static Scheme_Object * read_compact_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  CPort * port = (CPort * ) p -> ku . k . p1 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  return read_compact (port , p -> ku . k . i1 ) ; 
}
/* this far 4450 */
/* this far 4450 */
static Scheme_Object * read_compact (CPort * port , int use_stack ) {
  unsigned int l ; 
  char * s , buffer [32 ] ; 
  int ch ; 
  int need_car = 0 , proper = 0 ; 
  Scheme_Object * v , * first = ((void * ) 0 ) , * last = ((void * ) 0 ) ; 
  Scheme_Object * __funcarg153 = NULLED_OUT ; 
  Scheme_Object * __funcarg152 = NULLED_OUT ; 
  long __funcarg150 ; 
  Scheme_Config * __funcarg149 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(11);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(port, 1), PUSH(first, 2), PUSH(last, 3), PUSH(s, 4)));
# define XfOrM702_COUNT (5)
# define SETUP_XfOrM702(x) SETUP(XfOrM702_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  s = NULLED_OUT ; 
  v = NULLED_OUT ; 
  {
    unsigned long _stk_pos ; 
#   define XfOrM823_COUNT (0+XfOrM702_COUNT)
#   define SETUP_XfOrM823(x) SETUP_XfOrM702(x)
    _stk_pos = (unsigned long ) & _stk_pos ; 
    if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
      Scheme_Thread * p = scheme_current_thread ; 
#     define XfOrM824_COUNT (0+XfOrM823_COUNT)
#     define SETUP_XfOrM824(x) SETUP_XfOrM823(x)
      p -> ku . k . p1 = (void * ) port ; 
      p -> ku . k . i1 = use_stack ; 
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_handle_stack_overflow (read_compact_k ) )) RET_VALUE_EMPTY_END ; 
    }
  }
  while (1 ) {
#   define XfOrM763_COUNT (0+XfOrM702_COUNT)
#   define SETUP_XfOrM763(x) SETUP_XfOrM702(x)
    if (! (port -> pos < port -> size ) )
      FUNCCALL(SETUP_XfOrM763(_), scheme_ill_formed (port , "./../src/read.c" , 4344 ) ); 
    ; 
    ch = ((int ) (port -> start [port -> pos ++ ] ) ) ; 
    switch (cpt_branch [ch ] ) {
#     define XfOrM768_COUNT (0+XfOrM763_COUNT)
#     define SETUP_XfOrM768(x) SETUP_XfOrM763(x)
      case CPT_ESCAPE : {
        int len ; 
        Scheme_Object * ep ; 
        char * s ; 
        ReadParams params ; 
        BLOCK_SETUP((PUSH(params.table, 0+XfOrM768_COUNT), PUSH(params.magic_sym, 1+XfOrM768_COUNT), PUSH(params.magic_val, 2+XfOrM768_COUNT), PUSH(params.delay_load_info, 3+XfOrM768_COUNT), PUSH(s, 4+XfOrM768_COUNT), PUSH(ep, 5+XfOrM768_COUNT)));
#       define XfOrM822_COUNT (6+XfOrM768_COUNT)
#       define SETUP_XfOrM822(x) SETUP(XfOrM822_COUNT)
        ep = NULLED_OUT ; 
        s = NULLED_OUT ; 
        params.table = NULLED_OUT ; 
        params.magic_sym = NULLED_OUT ; 
        params.magic_val = NULLED_OUT ; 
        params.delay_load_info = NULLED_OUT ; 
        len = (read_compact_number (port ) ) ; 
        if (! ((unsigned ) len <= port -> size - port -> pos ) )
          FUNCCALL(SETUP_XfOrM822(_), scheme_ill_formed (port , "./../src/read.c" , 4357 ) ); 
        ; 
        s = FUNCCALL(SETUP_XfOrM822(_), read_compact_chars (port , buffer , 32 , len ) ); 
        if (s != buffer )
          len = - len ; 
        ep = FUNCCALL(SETUP_XfOrM822(_), scheme_make_sized_byte_string_input_port (s , len ) ); 
        params . can_read_compiled = 1 ; 
        params . can_read_pipe_quote = 1 ; 
        params . can_read_box = 1 ; 
        params . can_read_graph = 1 ; 
        params . case_sensitive = scheme_case_sensitive ; 
        params . square_brackets_are_parens = 1 ; 
        params . curly_braces_are_parens = 1 ; 
        params . read_decimal_inexact = 1 ; 
        params . can_read_dot = 1 ; 
        params . can_read_infix_dot = 1 ; 
        params . can_read_quasi = 1 ; 
        params . honu_mode = 0 ; 
        params . table = ((void * ) 0 ) ; 
        v = FUNCCALL(SETUP_XfOrM822(_), read_inner (ep , ((void * ) 0 ) , port -> ht , scheme_null , & params , 0 ) ); 
      }
      break ; 
      case CPT_SYMBOL : l = (read_compact_number (port ) ) ; 
      if (! (l <= port -> size - port -> pos ) )
        FUNCCALL(SETUP_XfOrM768(_), scheme_ill_formed (port , "./../src/read.c" , 4391 ) ); 
      ; 
      s = FUNCCALL(SETUP_XfOrM768(_), read_compact_chars (port , buffer , 32 , l ) ); 
      v = FUNCCALL_AGAIN(scheme_intern_exact_symbol (s , l ) ); 
      if (((v ) == (port -> magic_sym ) ) )
        v = port -> magic_val ; 
      break ; 
      case CPT_SYMREF : l = (read_compact_number (port ) ) ; 
      if (! (l < port -> symtab_size ) )
        FUNCCALL(SETUP_XfOrM768(_), scheme_ill_formed (port , "./../src/read.c" , 4400 ) ); 
      ; 
      v = port -> symtab [l ] ; 
      if (! v ) {
        long save_pos = port -> pos ; 
#       define XfOrM821_COUNT (0+XfOrM768_COUNT)
#       define SETUP_XfOrM821(x) SETUP_XfOrM768(x)
        port -> pos = port -> shared_offsets [l - 1 ] ; 
        v = FUNCCALL(SETUP_XfOrM821(_), read_compact (port , 0 ) ); 
        port -> pos = save_pos ; 
        port -> symtab [l ] = v ; 
      }
      break ; 
      case CPT_WEIRD_SYMBOL : {
        int uninterned ; 
#       define XfOrM820_COUNT (0+XfOrM768_COUNT)
#       define SETUP_XfOrM820(x) SETUP_XfOrM768(x)
        uninterned = (read_compact_number (port ) ) ; 
        l = (read_compact_number (port ) ) ; 
        if (! (l <= port -> size - port -> pos ) )
          FUNCCALL(SETUP_XfOrM820(_), scheme_ill_formed (port , "./../src/read.c" , 4417 ) ); 
        ; 
        s = FUNCCALL(SETUP_XfOrM820(_), read_compact_chars (port , buffer , 32 , l ) ); 
        if (uninterned )
          v = FUNCCALL(SETUP_XfOrM820(_), scheme_make_exact_symbol (s , l ) ); 
        else v = FUNCCALL(SETUP_XfOrM820(_), scheme_intern_exact_parallel_symbol (s , l ) ); 
      }
      break ; 
      case CPT_KEYWORD : l = (read_compact_number (port ) ) ; 
      if (! (l <= port -> size - port -> pos ) )
        FUNCCALL(SETUP_XfOrM768(_), scheme_ill_formed (port , "./../src/read.c" , 4432 ) ); 
      ; 
      s = FUNCCALL(SETUP_XfOrM768(_), read_compact_chars (port , buffer , 32 , l ) ); 
      v = FUNCCALL_AGAIN(scheme_intern_exact_keyword (s , l ) ); 
      break ; 
      case CPT_BYTE_STRING : l = (read_compact_number (port ) ) ; 
      if (! (l <= port -> size - port -> pos ) )
        FUNCCALL(SETUP_XfOrM768(_), scheme_ill_formed (port , "./../src/read.c" , 4438 ) ); 
      ; 
      s = FUNCCALL(SETUP_XfOrM768(_), read_compact_chars (port , buffer , 32 , l ) ); 
      v = FUNCCALL_AGAIN(scheme_make_immutable_sized_byte_string (s , l , l < 32 ) ); 
      break ; 
      case CPT_CHAR_STRING : {
        unsigned int el ; 
        mzchar * us ; 
        BLOCK_SETUP((PUSH(us, 0+XfOrM768_COUNT)));
#       define XfOrM819_COUNT (1+XfOrM768_COUNT)
#       define SETUP_XfOrM819(x) SETUP(XfOrM819_COUNT)
        us = NULLED_OUT ; 
        el = (read_compact_number (port ) ) ; 
        l = (read_compact_number (port ) ) ; 
        if (! (el <= port -> size - port -> pos ) )
          FUNCCALL(SETUP_XfOrM819(_), scheme_ill_formed (port , "./../src/read.c" , 4448 ) ); 
        ; 
        s = FUNCCALL(SETUP_XfOrM819(_), read_compact_chars (port , buffer , 32 , el ) ); 
        us = (mzchar * ) FUNCCALL(SETUP_XfOrM819(_), GC_malloc_atomic ((l + 1 ) * sizeof (mzchar ) ) ); 
        FUNCCALL(SETUP_XfOrM819(_), scheme_utf8_decode_all ((const unsigned char * ) s , el , us , 0 ) ); 
        us [l ] = 0 ; 
        v = FUNCCALL(SETUP_XfOrM819(_), scheme_make_immutable_sized_char_string (us , l , 0 ) ); 
      }
      break ; 
      case CPT_CHAR : l = (read_compact_number (port ) ) ; 
      v = ((((mzchar ) l ) < 256 ) ? scheme_char_constants [(unsigned char ) (l ) ] : FUNCCALL(SETUP_XfOrM768(_), scheme_make_char (l ) )) ; 
      break ; 
      case CPT_INT : v = ((Scheme_Object * ) (void * ) (long ) ((((long ) ((read_compact_number (port ) ) ) ) << 1 ) | 0x1 ) ) ; 
      break ; 
      case CPT_NULL : v = scheme_null ; 
      break ; 
      case CPT_TRUE : v = scheme_true ; 
      break ; 
      case CPT_FALSE : v = scheme_false ; 
      break ; 
      case CPT_VOID : v = scheme_void ; 
      break ; 
      case CPT_BOX : v = (__funcarg153 = FUNCCALL(SETUP_XfOrM768(_), read_compact (port , 0 ) ), FUNCCALL_AGAIN(scheme_box (__funcarg153 ) )) ; 
      break ; 
      case CPT_PAIR : if (need_car ) {
        Scheme_Object * car , * cdr ; 
        BLOCK_SETUP((PUSH(cdr, 0+XfOrM768_COUNT), PUSH(car, 1+XfOrM768_COUNT)));
#       define XfOrM818_COUNT (2+XfOrM768_COUNT)
#       define SETUP_XfOrM818(x) SETUP(XfOrM818_COUNT)
        car = NULLED_OUT ; 
        cdr = NULLED_OUT ; 
        car = FUNCCALL(SETUP_XfOrM818(_), read_compact (port , 0 ) ); 
        cdr = FUNCCALL_AGAIN(read_compact (port , 0 ) ); 
        v = FUNCCALL_AGAIN(scheme_make_pair (car , cdr ) ); 
      }
      else {
        need_car = 1 ; 
        continue ; 
      }
      break ; 
      case CPT_LIST : l = (read_compact_number (port ) ) ; 
      if (need_car ) {
#       define XfOrM815_COUNT (0+XfOrM768_COUNT)
#       define SETUP_XfOrM815(x) SETUP_XfOrM768(x)
        if (l == 1 ) {
          Scheme_Object * car , * cdr ; 
          BLOCK_SETUP((PUSH(cdr, 0+XfOrM815_COUNT), PUSH(car, 1+XfOrM815_COUNT)));
#         define XfOrM816_COUNT (2+XfOrM815_COUNT)
#         define SETUP_XfOrM816(x) SETUP(XfOrM816_COUNT)
          car = NULLED_OUT ; 
          cdr = NULLED_OUT ; 
          car = FUNCCALL(SETUP_XfOrM816(_), read_compact (port , 0 ) ); 
          cdr = FUNCCALL_AGAIN(read_compact (port , 0 ) ); 
          v = FUNCCALL_AGAIN(scheme_make_pair (car , cdr ) ); 
        }
        else v = FUNCCALL(SETUP_XfOrM815(_), read_compact_list (l , 0 , 0 , port ) ); 
      }
      else {
        need_car = l ; 
        continue ; 
      }
      break ; 
      case CPT_VECTOR : {
        Scheme_Object * vec ; 
        unsigned int i ; 
        BLOCK_SETUP((PUSH(vec, 0+XfOrM768_COUNT)));
#       define XfOrM811_COUNT (1+XfOrM768_COUNT)
#       define SETUP_XfOrM811(x) SETUP(XfOrM811_COUNT)
        vec = NULLED_OUT ; 
        l = (read_compact_number (port ) ) ; 
        vec = FUNCCALL(SETUP_XfOrM811(_), scheme_make_vector (l , ((void * ) 0 ) ) ); 
        for (i = 0 ; i < l ; i ++ ) {
          Scheme_Object * cv ; 
          BLOCK_SETUP((PUSH(cv, 0+XfOrM811_COUNT)));
#         define XfOrM813_COUNT (1+XfOrM811_COUNT)
#         define SETUP_XfOrM813(x) SETUP(XfOrM813_COUNT)
          cv = NULLED_OUT ; 
          cv = FUNCCALL(SETUP_XfOrM813(_), read_compact (port , 0 ) ); 
          (((Scheme_Vector * ) (vec ) ) -> els ) [i ] = cv ; 
        }
        v = vec ; 
      }
      break ; 
      case CPT_HASH_TABLE : {
        Scheme_Hash_Table * t ; 
        Scheme_Object * l ; 
        int eq , len ; 
        BLOCK_SETUP((PUSH(t, 0+XfOrM768_COUNT), PUSH(l, 1+XfOrM768_COUNT)));
#       define XfOrM807_COUNT (2+XfOrM768_COUNT)
#       define SETUP_XfOrM807(x) SETUP(XfOrM807_COUNT)
        t = NULLED_OUT ; 
        l = NULLED_OUT ; 
        eq = (read_compact_number (port ) ) ; 
        if (eq )
          t = FUNCCALL(SETUP_XfOrM807(_), scheme_make_hash_table_equal () ); 
        else t = FUNCCALL(SETUP_XfOrM807(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
        len = (read_compact_number (port ) ) ; 
        l = scheme_null ; 
        while (len -- ) {
          Scheme_Object * k , * v ; 
          BLOCK_SETUP((PUSH(v, 0+XfOrM807_COUNT), PUSH(k, 1+XfOrM807_COUNT)));
#         define XfOrM810_COUNT (2+XfOrM807_COUNT)
#         define SETUP_XfOrM810(x) SETUP(XfOrM810_COUNT)
          k = NULLED_OUT ; 
          v = NULLED_OUT ; 
          k = FUNCCALL(SETUP_XfOrM810(_), read_compact (port , 0 ) ); 
          v = FUNCCALL_AGAIN(read_compact (port , 0 ) ); 
          l = (__funcarg152 = FUNCCALL(SETUP_XfOrM810(_), scheme_make_pair (k , v ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg152 , l ) )) ; 
        }
        FUNCCALL(SETUP_XfOrM807(_), scheme_hash_set (t , an_uninterned_symbol , l ) ); 
        if (! (* port -> ht ) ) {
          Scheme_Hash_Table * tht ; 
          BLOCK_SETUP((PUSH(tht, 0+XfOrM807_COUNT)));
#         define XfOrM808_COUNT (1+XfOrM807_COUNT)
#         define SETUP_XfOrM808(x) SETUP(XfOrM808_COUNT)
          tht = NULLED_OUT ; 
          tht = FUNCCALL(SETUP_XfOrM808(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
          * (port -> ht ) = tht ; 
        }
        v = (Scheme_Object * ) t ; 
      }
      break ; 
      case CPT_STX : case CPT_GSTX : {
#       define XfOrM804_COUNT (0+XfOrM768_COUNT)
#       define SETUP_XfOrM804(x) SETUP_XfOrM768(x)
        if (! port -> ut ) {
          Scheme_Unmarshal_Tables * ut ; 
          Scheme_Hash_Table * rht ; 
          char * decoded ; 
          BLOCK_SETUP((PUSH(rht, 0+XfOrM804_COUNT), PUSH(decoded, 1+XfOrM804_COUNT), PUSH(ut, 2+XfOrM804_COUNT)));
#         define XfOrM806_COUNT (3+XfOrM804_COUNT)
#         define SETUP_XfOrM806(x) SETUP(XfOrM806_COUNT)
          ut = NULLED_OUT ; 
          rht = NULLED_OUT ; 
          decoded = NULLED_OUT ; 
          ut = ((Scheme_Unmarshal_Tables * ) FUNCCALL(SETUP_XfOrM806(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Unmarshal_Tables ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
          ut -> type = scheme_rt_unmarshal_info ; 
          port -> ut = ut ; 
          ut -> rp = port ; 
          decoded = (char * ) FUNCCALL(SETUP_XfOrM806(_), GC_malloc_atomic (port -> symtab_size ) ); 
          (memset (decoded , 0 , port -> symtab_size ) ) ; 
          ut -> decoded = decoded ; 
          rht = FUNCCALL(SETUP_XfOrM806(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
          port -> ut -> rns = rht ; 
        }
        if (* port -> ht )
          FUNCCALL(SETUP_XfOrM804(_), scheme_ill_formed (port , "./../src/read.c" , 4579 ) ); 
        v = FUNCCALL(SETUP_XfOrM804(_), read_compact (port , 1 ) ); 
        if (* port -> ht ) {
#         define XfOrM805_COUNT (0+XfOrM804_COUNT)
#         define SETUP_XfOrM805(x) SETUP_XfOrM804(x)
          v = FUNCCALL(SETUP_XfOrM805(_), resolve_references (v , ((void * ) 0 ) , ((void * ) 0 ) , 0 , scheme_placeholder_type ) ); 
          * port -> ht = ((void * ) 0 ) ; 
        }
        v = FUNCCALL(SETUP_XfOrM804(_), scheme_unmarshal_datum_to_syntax (v , port -> ut , ch == CPT_GSTX ) ); 
        scheme_num_read_syntax_objects ++ ; 
        if (! v )
          FUNCCALL(SETUP_XfOrM804(_), scheme_ill_formed (port , "./../src/read.c" , 4591 ) ); 
      }
      break ; 
      case CPT_MARSHALLED : v = (__funcarg150 = (read_compact_number (port ) ) , FUNCCALL(SETUP_XfOrM768(_), read_marshalled (__funcarg150 , port ) )) ; 
      break ; 
      case CPT_QUOTE : v = FUNCCALL(SETUP_XfOrM768(_), read_compact_quote (port , 1 ) ); 
      break ; 
      case CPT_REFERENCE : l = (read_compact_number (port ) ) ; 
      if (! (l < 911 ) )
        FUNCCALL(SETUP_XfOrM768(_), scheme_ill_formed (port , "./../src/read.c" , 4602 ) ); 
      ; 
      v = variable_references [l ] ; 
      break ; 
      case CPT_LOCAL : {
        int p ; 
#       define XfOrM803_COUNT (0+XfOrM768_COUNT)
#       define SETUP_XfOrM803(x) SETUP_XfOrM768(x)
        p = (read_compact_number (port ) ) ; 
        if (p < 0 )
          FUNCCALL(SETUP_XfOrM803(_), scheme_ill_formed (port , "./../src/read.c" , 4610 ) ); 
        v = FUNCCALL(SETUP_XfOrM803(_), scheme_make_local (scheme_local_type , p ) ); 
      }
      break ; 
      case CPT_LOCAL_UNBOX : {
        int p ; 
#       define XfOrM802_COUNT (0+XfOrM768_COUNT)
#       define SETUP_XfOrM802(x) SETUP_XfOrM768(x)
        p = (read_compact_number (port ) ) ; 
        if (p < 0 )
          FUNCCALL(SETUP_XfOrM802(_), scheme_ill_formed (port , "./../src/read.c" , 4619 ) ); 
        v = FUNCCALL(SETUP_XfOrM802(_), scheme_make_local (scheme_local_unbox_type , p ) ); 
      }
      break ; 
      case CPT_SVECTOR : {
        int l ; 
#       define XfOrM801_COUNT (0+XfOrM768_COUNT)
#       define SETUP_XfOrM801(x) SETUP_XfOrM768(x)
        l = (read_compact_number (port ) ) ; 
        v = FUNCCALL(SETUP_XfOrM801(_), read_compact_svector (port , l ) ); 
      }
      break ; 
      case CPT_APPLICATION : {
        int c , i ; 
        Scheme_App_Rec * a ; 
        BLOCK_SETUP((PUSH(a, 0+XfOrM768_COUNT)));
#       define XfOrM798_COUNT (1+XfOrM768_COUNT)
#       define SETUP_XfOrM798(x) SETUP(XfOrM798_COUNT)
        a = NULLED_OUT ; 
        c = (read_compact_number (port ) ) + 1 ; 
        a = FUNCCALL(SETUP_XfOrM798(_), scheme_malloc_application (c ) ); 
        for (i = 0 ; i < c ; i ++ ) {
#         define XfOrM800_COUNT (0+XfOrM798_COUNT)
#         define SETUP_XfOrM800(x) SETUP_XfOrM798(x)
          v = FUNCCALL(SETUP_XfOrM800(_), read_compact (port , 1 ) ); 
          a -> args [i ] = v ; 
        }
        FUNCCALL(SETUP_XfOrM798(_), scheme_finish_application (a ) ); 
        v = (Scheme_Object * ) a ; 
      }
      break ; 
      case CPT_LET_ONE : {
        Scheme_Let_One * lo ; 
        int et ; 
        BLOCK_SETUP((PUSH(lo, 0+XfOrM768_COUNT)));
#       define XfOrM797_COUNT (1+XfOrM768_COUNT)
#       define SETUP_XfOrM797(x) SETUP(XfOrM797_COUNT)
        lo = NULLED_OUT ; 
        lo = (Scheme_Let_One * ) FUNCCALL(SETUP_XfOrM797(_), GC_malloc_one_tagged (sizeof (Scheme_Let_One ) ) ); 
        lo -> iso . so . type = scheme_let_one_type ; 
        v = FUNCCALL(SETUP_XfOrM797(_), read_compact (port , 1 ) ); 
        lo -> value = v ; 
        v = FUNCCALL(SETUP_XfOrM797(_), read_compact (port , 1 ) ); 
        lo -> body = v ; 
        et = FUNCCALL(SETUP_XfOrM797(_), scheme_get_eval_type (lo -> value ) ); 
        (& lo -> iso ) -> so . keyex = et ; 
        v = (Scheme_Object * ) lo ; 
      }
      break ; 
      case CPT_BRANCH : {
        Scheme_Object * test , * tbranch , * fbranch ; 
        BLOCK_SETUP((PUSH(test, 0+XfOrM768_COUNT), PUSH(tbranch, 1+XfOrM768_COUNT), PUSH(fbranch, 2+XfOrM768_COUNT)));
#       define XfOrM796_COUNT (3+XfOrM768_COUNT)
#       define SETUP_XfOrM796(x) SETUP(XfOrM796_COUNT)
        test = NULLED_OUT ; 
        tbranch = NULLED_OUT ; 
        fbranch = NULLED_OUT ; 
        test = FUNCCALL(SETUP_XfOrM796(_), read_compact (port , 1 ) ); 
        tbranch = FUNCCALL_AGAIN(read_compact (port , 1 ) ); 
        fbranch = FUNCCALL_AGAIN(read_compact (port , 1 ) ); 
        v = FUNCCALL_AGAIN(scheme_make_branch (test , tbranch , fbranch ) ); 
      }
      break ; 
      case CPT_MODULE_INDEX : {
        Scheme_Object * path , * base ; 
        BLOCK_SETUP((PUSH(base, 0+XfOrM768_COUNT), PUSH(path, 1+XfOrM768_COUNT)));
#       define XfOrM795_COUNT (2+XfOrM768_COUNT)
#       define SETUP_XfOrM795(x) SETUP(XfOrM795_COUNT)
        path = NULLED_OUT ; 
        base = NULLED_OUT ; 
        path = FUNCCALL(SETUP_XfOrM795(_), read_compact (port , 0 ) ); 
        base = FUNCCALL_AGAIN(read_compact (port , 0 ) ); 
        v = FUNCCALL_AGAIN(scheme_make_modidx (path , base , scheme_false ) ); 
      }
      break ; 
      case CPT_MODULE_VAR : {
        Module_Variable * mv ; 
        Scheme_Object * mod , * var ; 
        int pos ; 
        BLOCK_SETUP((PUSH(mod, 0+XfOrM768_COUNT), PUSH(mv, 1+XfOrM768_COUNT), PUSH(var, 2+XfOrM768_COUNT)));
#       define XfOrM794_COUNT (3+XfOrM768_COUNT)
#       define SETUP_XfOrM794(x) SETUP(XfOrM794_COUNT)
        mv = NULLED_OUT ; 
        mod = NULLED_OUT ; 
        var = NULLED_OUT ; 
        mod = FUNCCALL(SETUP_XfOrM794(_), read_compact (port , 0 ) ); 
        var = FUNCCALL_AGAIN(read_compact (port , 0 ) ); 
        pos = (read_compact_number (port ) ) ; 
        mv = ((Module_Variable * ) FUNCCALL(SETUP_XfOrM794(_), GC_malloc_one_small_tagged ((((sizeof (Module_Variable ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
        mv -> so . type = scheme_module_variable_type ; 
        mv -> modidx = mod ; 
        mv -> insp = port -> insp ; 
        mv -> sym = var ; 
        mv -> pos = pos ; 
        v = (Scheme_Object * ) mv ; 
      }
      break ; 
      case CPT_PATH : {
#       define XfOrM791_COUNT (0+XfOrM768_COUNT)
#       define SETUP_XfOrM791(x) SETUP_XfOrM768(x)
        l = (read_compact_number (port ) ) ; 
        if (! (l <= port -> size - port -> pos ) )
          FUNCCALL(SETUP_XfOrM791(_), scheme_ill_formed (port , "./../src/read.c" , 4707 ) ); 
        ; 
        s = FUNCCALL(SETUP_XfOrM791(_), read_compact_chars (port , buffer , 32 , l ) ); 
        v = FUNCCALL_AGAIN(scheme_make_sized_path (s , l , l < 32 ) ); 
        if (FUNCCALL(SETUP_XfOrM791(_), scheme_is_relative_path ((((Scheme_Simple_Object * ) (v ) ) -> u . byte_str_val . string_val ) , (((Scheme_Simple_Object * ) (v ) ) -> u . byte_str_val . tag_val ) , scheme_unix_path_type ) )) {
          Scheme_Object * dir ; 
          BLOCK_SETUP((PUSH(dir, 0+XfOrM791_COUNT)));
#         define XfOrM792_COUNT (1+XfOrM791_COUNT)
#         define SETUP_XfOrM792(x) SETUP(XfOrM792_COUNT)
          dir = NULLED_OUT ; 
          dir = (__funcarg149 = FUNCCALL(SETUP_XfOrM792(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg149 , MZCONFIG_LOAD_DIRECTORY ) )) ; 
          if (((Scheme_Type ) (((((long ) (dir ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (dir ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) {
            Scheme_Object * a [2 ] ; 
            BLOCK_SETUP((PUSHARRAY(a, 2, 0+XfOrM792_COUNT)));
#           define XfOrM793_COUNT (3+XfOrM792_COUNT)
#           define SETUP_XfOrM793(x) SETUP(XfOrM793_COUNT)
            a[0] = NULLED_OUT ; 
            a[1] = NULLED_OUT ; 
            a [0 ] = dir ; 
            a [1 ] = v ; 
            v = FUNCCALL(SETUP_XfOrM793(_), scheme_build_path (2 , a ) ); 
          }
        }
      }
      break ; 
      case CPT_CLOSURE : {
        Scheme_Closure * cl ; 
        BLOCK_SETUP((PUSH(cl, 0+XfOrM768_COUNT)));
#       define XfOrM789_COUNT (1+XfOrM768_COUNT)
#       define SETUP_XfOrM789(x) SETUP(XfOrM789_COUNT)
        cl = NULLED_OUT ; 
        l = (read_compact_number (port ) ) ; 
        if (! (l < port -> symtab_size ) )
          FUNCCALL(SETUP_XfOrM789(_), scheme_ill_formed (port , "./../src/read.c" , 4728 ) ); 
        ; 
        cl = FUNCCALL(SETUP_XfOrM789(_), scheme_malloc_empty_closure () ); 
        port -> symtab [l ] = (Scheme_Object * ) cl ; 
        v = FUNCCALL(SETUP_XfOrM789(_), read_compact (port , 0 ) ); 
        if (! ((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_closure_type ) ) || ((Scheme_Closure * ) v ) -> code -> closure_size ) {
#         define XfOrM790_COUNT (0+XfOrM789_COUNT)
#         define SETUP_XfOrM790(x) SETUP_XfOrM789(x)
          FUNCCALL(SETUP_XfOrM790(_), scheme_ill_formed (port , "./../src/read.c" , 4734 ) ); 
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        }
        cl -> code = ((Scheme_Closure * ) v ) -> code ; 
        v = (Scheme_Object * ) cl ; 
        break ; 
      }
      case CPT_DELAY_REF : {
#       define XfOrM785_COUNT (0+XfOrM768_COUNT)
#       define SETUP_XfOrM785(x) SETUP_XfOrM768(x)
        l = (read_compact_number (port ) ) ; 
        if (! (l < port -> symtab_size ) )
          FUNCCALL(SETUP_XfOrM785(_), scheme_ill_formed (port , "./../src/read.c" , 4744 ) ); 
        ; 
        v = port -> symtab [l ] ; 
        if (! v ) {
#         define XfOrM786_COUNT (0+XfOrM785_COUNT)
#         define SETUP_XfOrM786(x) SETUP_XfOrM785(x)
          if (port -> delay_info ) {
#           define XfOrM788_COUNT (0+XfOrM786_COUNT)
#           define SETUP_XfOrM788(x) SETUP_XfOrM786(x)
            v = FUNCCALL(SETUP_XfOrM788(_), scheme_make_raw_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (l ) ) << 1 ) | 0x1 ) ) , (Scheme_Object * ) port -> delay_info ) ); 
          }
          else {
            long save_pos = port -> pos ; 
#           define XfOrM787_COUNT (0+XfOrM786_COUNT)
#           define SETUP_XfOrM787(x) SETUP_XfOrM786(x)
            port -> pos = port -> shared_offsets [l - 1 ] ; 
            v = FUNCCALL(SETUP_XfOrM787(_), read_compact (port , 0 ) ); 
            port -> pos = save_pos ; 
            port -> symtab [l ] = v ; 
          }
        }
        break ; 
      }
      case 192 : case 207 : {
        Scheme_Type type ; 
        int k ; 
#       define XfOrM782_COUNT (0+XfOrM768_COUNT)
#       define SETUP_XfOrM782(x) SETUP_XfOrM768(x)
        if (((ch >= 207 ) && (ch < 222 ) ) ) {
          k = 1 ; 
          type = scheme_local_unbox_type ; 
          ch -= 207 ; 
        }
        else {
          k = 0 ; 
          type = scheme_local_type ; 
          ch -= 192 ; 
        }
        if (ch < 64 )
          v = scheme_local [ch ] [k ] ; 
        else v = FUNCCALL(SETUP_XfOrM782(_), scheme_make_local (type , ch ) ); 
      }
      break ; 
      case 80 : {
#       define XfOrM781_COUNT (0+XfOrM768_COUNT)
#       define SETUP_XfOrM781(x) SETUP_XfOrM768(x)
        l = ch - 80 ; 
        v = FUNCCALL(SETUP_XfOrM781(_), read_marshalled (l , port ) ); 
      }
      break ; 
      case 60 : {
#       define XfOrM780_COUNT (0+XfOrM768_COUNT)
#       define SETUP_XfOrM780(x) SETUP_XfOrM768(x)
        l = ch - 60 ; 
        if (! (l <= port -> size - port -> pos ) )
          FUNCCALL(SETUP_XfOrM780(_), scheme_ill_formed (port , "./../src/read.c" , 4792 ) ); 
        ; 
        s = FUNCCALL(SETUP_XfOrM780(_), read_compact_chars (port , buffer , 32 , l ) ); 
        v = FUNCCALL_AGAIN(scheme_intern_exact_symbol (s , l ) ); 
        if (((v ) == (port -> magic_sym ) ) )
          v = port -> magic_val ; 
      }
      break ; 
      case 34 : {
        l = ch - 34 ; 
        v = ((Scheme_Object * ) (void * ) (long ) ((((long ) (l ) ) << 1 ) | 0x1 ) ) ; 
      }
      break ; 
      case 222 : {
#       define XfOrM778_COUNT (0+XfOrM768_COUNT)
#       define SETUP_XfOrM778(x) SETUP_XfOrM768(x)
        l = ch - 222 ; 
        v = FUNCCALL(SETUP_XfOrM778(_), read_compact_svector (port , l ) ); 
      }
      break ; 
      case 92 : case (92 + 65 ) : {
        int ppr = ((ch >= 92 ) && (ch < (92 + 65 ) ) ) ; 
#       define XfOrM774_COUNT (0+XfOrM768_COUNT)
#       define SETUP_XfOrM774(x) SETUP_XfOrM768(x)
        l = ch - (ppr ? 92 : (92 + 65 ) ) ; 
        if (need_car ) {
#         define XfOrM776_COUNT (0+XfOrM774_COUNT)
#         define SETUP_XfOrM776(x) SETUP_XfOrM774(x)
          if (l == 1 ) {
            Scheme_Object * car , * cdr ; 
            BLOCK_SETUP((PUSH(cdr, 0+XfOrM776_COUNT), PUSH(car, 1+XfOrM776_COUNT)));
#           define XfOrM777_COUNT (2+XfOrM776_COUNT)
#           define SETUP_XfOrM777(x) SETUP(XfOrM777_COUNT)
            car = NULLED_OUT ; 
            cdr = NULLED_OUT ; 
            car = FUNCCALL(SETUP_XfOrM777(_), read_compact (port , 0 ) ); 
            cdr = (ppr ? scheme_null : FUNCCALL(SETUP_XfOrM777(_), read_compact (port , 0 ) )) ; 
            v = FUNCCALL(SETUP_XfOrM777(_), scheme_make_pair (car , cdr ) ); 
          }
          else v = FUNCCALL(SETUP_XfOrM776(_), read_compact_list (l , ppr , 0 , port ) ); 
        }
        else {
          proper = ppr ; 
          need_car = l ; 
          continue ; 
        }
      }
      break ; 
      case 247 : {
        int c , i ; 
        Scheme_App_Rec * a ; 
        BLOCK_SETUP((PUSH(a, 0+XfOrM768_COUNT)));
#       define XfOrM771_COUNT (1+XfOrM768_COUNT)
#       define SETUP_XfOrM771(x) SETUP(XfOrM771_COUNT)
        a = NULLED_OUT ; 
        c = (ch - 247 ) + 1 ; 
        a = FUNCCALL(SETUP_XfOrM771(_), scheme_malloc_application (c ) ); 
        for (i = 0 ; i < c ; i ++ ) {
#         define XfOrM773_COUNT (0+XfOrM771_COUNT)
#         define SETUP_XfOrM773(x) SETUP_XfOrM771(x)
          v = FUNCCALL(SETUP_XfOrM773(_), read_compact (port , 1 ) ); 
          a -> args [i ] = v ; 
        }
        FUNCCALL(SETUP_XfOrM771(_), scheme_finish_application (a ) ); 
        v = (Scheme_Object * ) a ; 
      }
      break ; 
      case 248 : {
        short et ; 
        Scheme_App2_Rec * app ; 
        BLOCK_SETUP((PUSH(app, 0+XfOrM768_COUNT)));
#       define XfOrM770_COUNT (1+XfOrM768_COUNT)
#       define SETUP_XfOrM770(x) SETUP(XfOrM770_COUNT)
        app = NULLED_OUT ; 
        app = ((Scheme_App2_Rec * ) FUNCCALL(SETUP_XfOrM770(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_App2_Rec ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
        app -> iso . so . type = scheme_application2_type ; 
        v = FUNCCALL(SETUP_XfOrM770(_), read_compact (port , 1 ) ); 
        app -> rator = v ; 
        v = FUNCCALL(SETUP_XfOrM770(_), read_compact (port , 1 ) ); 
        app -> rand = v ; 
        et = FUNCCALL(SETUP_XfOrM770(_), scheme_get_eval_type (app -> rand ) ); 
        et = et << 3 ; 
        et += FUNCCALL(SETUP_XfOrM770(_), scheme_get_eval_type (app -> rator ) ); 
        (& app -> iso ) -> so . keyex = et ; 
        v = (Scheme_Object * ) app ; 
      }
      break ; 
      case 249 : {
        short et ; 
        Scheme_App3_Rec * app ; 
        BLOCK_SETUP((PUSH(app, 0+XfOrM768_COUNT)));
#       define XfOrM769_COUNT (1+XfOrM768_COUNT)
#       define SETUP_XfOrM769(x) SETUP(XfOrM769_COUNT)
        app = NULLED_OUT ; 
        app = ((Scheme_App3_Rec * ) FUNCCALL(SETUP_XfOrM769(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_App3_Rec ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
        app -> iso . so . type = scheme_application3_type ; 
        v = FUNCCALL(SETUP_XfOrM769(_), read_compact (port , 1 ) ); 
        app -> rator = v ; 
        v = FUNCCALL(SETUP_XfOrM769(_), read_compact (port , 1 ) ); 
        app -> rand1 = v ; 
        v = FUNCCALL(SETUP_XfOrM769(_), read_compact (port , 1 ) ); 
        app -> rand2 = v ; 
        et = FUNCCALL(SETUP_XfOrM769(_), scheme_get_eval_type (app -> rand2 ) ); 
        et = et << 3 ; 
        et += FUNCCALL(SETUP_XfOrM769(_), scheme_get_eval_type (app -> rand1 ) ); 
        et = et << 3 ; 
        et += FUNCCALL(SETUP_XfOrM769(_), scheme_get_eval_type (app -> rator ) ); 
        (& app -> iso ) -> so . keyex = et ; 
        v = (Scheme_Object * ) app ; 
      }
      break ; 
      default : v = ((void * ) 0 ) ; 
      break ; 
    }
    if (! v )
      FUNCCALL(SETUP_XfOrM763(_), scheme_ill_formed (port , "./../src/read.c" , 4904 ) ); 
    if (need_car ) {
      Scheme_Object * pair ; 
      BLOCK_SETUP((PUSH(pair, 0+XfOrM763_COUNT)));
#     define XfOrM765_COUNT (1+XfOrM763_COUNT)
#     define SETUP_XfOrM765(x) SETUP(XfOrM765_COUNT)
      pair = NULLED_OUT ; 
      if (0 ) {
#       define XfOrM766_COUNT (0+XfOrM765_COUNT)
#       define SETUP_XfOrM766(x) SETUP_XfOrM765(x)
        if ((scheme_current_thread -> list_stack_pos ) >= 500 ) {
          Scheme_Simple_Object * sa ; 
          BLOCK_SETUP((PUSH(sa, 0+XfOrM766_COUNT)));
#         define XfOrM767_COUNT (1+XfOrM766_COUNT)
#         define SETUP_XfOrM767(x) SETUP(XfOrM767_COUNT)
          sa = NULLED_OUT ; 
          sa = FUNCCALL(SETUP_XfOrM767(_), malloc_list_stack () ); 
          (scheme_current_thread -> list_stack ) = sa ; 
          (scheme_current_thread -> list_stack_pos ) = 0 ; 
        }
        pair = (Scheme_Object * ) ((scheme_current_thread -> list_stack ) + ((scheme_current_thread -> list_stack_pos ) ++ ) ) ; 
        pair -> type = scheme_pair_type ; 
        (((Scheme_Simple_Object * ) (pair ) ) -> u . pair_val . car ) = v ; 
        (((Scheme_Simple_Object * ) (pair ) ) -> u . pair_val . cdr ) = scheme_null ; 
      }
      else pair = FUNCCALL(SETUP_XfOrM765(_), scheme_make_pair (v , scheme_null ) ); 
      if (last )
        (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = pair ; 
      else first = pair ; 
      last = pair ; 
      -- need_car ; 
      if (! need_car && proper )
        break ; 
    }
    else {
      if (last )
        (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = v ; 
      break ; 
    }
  }
  RET_VALUE_START (first ? first : v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * read_compact_list (int c , int proper , int use_stack , CPort * port ) {
  Scheme_Object * v , * first , * last , * pair ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(last, 1), PUSH(pair, 2), PUSH(first, 3), PUSH(port, 4)));
# define XfOrM825_COUNT (5)
# define SETUP_XfOrM825(x) SETUP(XfOrM825_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  v = NULLED_OUT ; 
  first = NULLED_OUT ; 
  last = NULLED_OUT ; 
  pair = NULLED_OUT ; 
  v = FUNCCALL(SETUP_XfOrM825(_), read_compact (port , 0 ) ); 
  if (0 ) {
#   define XfOrM833_COUNT (0+XfOrM825_COUNT)
#   define SETUP_XfOrM833(x) SETUP_XfOrM825(x)
    if ((scheme_current_thread -> list_stack_pos ) >= 500 ) {
      Scheme_Simple_Object * sa ; 
      BLOCK_SETUP((PUSH(sa, 0+XfOrM833_COUNT)));
#     define XfOrM834_COUNT (1+XfOrM833_COUNT)
#     define SETUP_XfOrM834(x) SETUP(XfOrM834_COUNT)
      sa = NULLED_OUT ; 
      sa = FUNCCALL(SETUP_XfOrM834(_), malloc_list_stack () ); 
      (scheme_current_thread -> list_stack ) = sa ; 
      (scheme_current_thread -> list_stack_pos ) = 0 ; 
    }
    last = (Scheme_Object * ) ((scheme_current_thread -> list_stack ) + ((scheme_current_thread -> list_stack_pos ) ++ ) ) ; 
    last -> type = scheme_pair_type ; 
    (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . car ) = v ; 
    (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = scheme_null ; 
  }
  else last = FUNCCALL(SETUP_XfOrM825(_), scheme_make_pair (v , scheme_null ) ); 
  first = last ; 
  while (-- c ) {
#   define XfOrM830_COUNT (0+XfOrM825_COUNT)
#   define SETUP_XfOrM830(x) SETUP_XfOrM825(x)
    v = FUNCCALL(SETUP_XfOrM830(_), read_compact (port , 0 ) ); 
    if (0 ) {
#     define XfOrM831_COUNT (0+XfOrM830_COUNT)
#     define SETUP_XfOrM831(x) SETUP_XfOrM830(x)
      if ((scheme_current_thread -> list_stack_pos ) >= 500 ) {
        Scheme_Simple_Object * sa ; 
        BLOCK_SETUP((PUSH(sa, 0+XfOrM831_COUNT)));
#       define XfOrM832_COUNT (1+XfOrM831_COUNT)
#       define SETUP_XfOrM832(x) SETUP(XfOrM832_COUNT)
        sa = NULLED_OUT ; 
        sa = FUNCCALL(SETUP_XfOrM832(_), malloc_list_stack () ); 
        (scheme_current_thread -> list_stack ) = sa ; 
        (scheme_current_thread -> list_stack_pos ) = 0 ; 
      }
      pair = (Scheme_Object * ) ((scheme_current_thread -> list_stack ) + ((scheme_current_thread -> list_stack_pos ) ++ ) ) ; 
      pair -> type = scheme_pair_type ; 
      (((Scheme_Simple_Object * ) (pair ) ) -> u . pair_val . car ) = v ; 
      (((Scheme_Simple_Object * ) (pair ) ) -> u . pair_val . cdr ) = scheme_null ; 
    }
    else pair = FUNCCALL(SETUP_XfOrM830(_), scheme_make_pair (v , scheme_null ) ); 
    (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = pair ; 
    last = pair ; 
  }
  if (! proper ) {
#   define XfOrM826_COUNT (0+XfOrM825_COUNT)
#   define SETUP_XfOrM826(x) SETUP_XfOrM825(x)
    v = FUNCCALL(SETUP_XfOrM826(_), read_compact (port , 0 ) ); 
    (((Scheme_Simple_Object * ) (last ) ) -> u . pair_val . cdr ) = v ; 
  }
  RET_VALUE_START (first ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * read_compact_quote (CPort * port , int embedded ) {
  Scheme_Hash_Table * * q_ht , * * old_ht ; 
  Scheme_Object * v ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(q_ht, 1), PUSH(old_ht, 2), PUSH(port, 3)));
# define XfOrM835_COUNT (4)
# define SETUP_XfOrM835(x) SETUP(XfOrM835_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  q_ht = NULLED_OUT ; 
  old_ht = NULLED_OUT ; 
  v = NULLED_OUT ; 
  q_ht = ((Scheme_Hash_Table * * ) FUNCCALL(SETUP_XfOrM835(_), GC_malloc (sizeof (Scheme_Hash_Table * ) * (1 ) ) )) ; 
  * q_ht = ((void * ) 0 ) ; 
  old_ht = port -> ht ; 
  port -> ht = q_ht ; 
  v = FUNCCALL(SETUP_XfOrM835(_), read_compact (port , 0 ) ); 
  port -> ht = old_ht ; 
  if (* q_ht )
    FUNCCALL(SETUP_XfOrM835(_), resolve_references (v , ((void * ) 0 ) , ((void * ) 0 ) , 0 , scheme_placeholder_type ) ); 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * read_marshalled (int type , CPort * port ) {
  Scheme_Object * l ; 
  ListStackRec r ; 
  Scheme_Type_Reader reader ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(r.stack, 0), PUSH(l, 1), PUSH(port, 2)));
# define XfOrM836_COUNT (3)
# define SETUP_XfOrM836(x) SETUP(XfOrM836_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  l = NULLED_OUT ; 
  r.stack = NULLED_OUT ; 
  (r . pos = (scheme_current_thread -> list_stack_pos ) , r . stack = (scheme_current_thread -> list_stack ) ) ; 
  l = FUNCCALL(SETUP_XfOrM836(_), read_compact (port , 1 ) ); 
  if ((type < 0 ) || (type >= _scheme_last_type_ ) ) {
#   define XfOrM838_COUNT (0+XfOrM836_COUNT)
#   define SETUP_XfOrM838(x) SETUP_XfOrM836(x)
    ((scheme_current_thread -> list_stack_pos ) = r . pos , (scheme_current_thread -> list_stack ) = r . stack ) ; 
    FUNCCALL(SETUP_XfOrM838(_), scheme_ill_formed (port , "./../src/read.c" , 5031 ) ); 
  }
  reader = scheme_type_readers [type ] ; 
  if (! reader ) {
#   define XfOrM837_COUNT (0+XfOrM836_COUNT)
#   define SETUP_XfOrM837(x) SETUP_XfOrM836(x)
    ((scheme_current_thread -> list_stack_pos ) = r . pos , (scheme_current_thread -> list_stack ) = r . stack ) ; 
    FUNCCALL(SETUP_XfOrM837(_), scheme_ill_formed (port , "./../src/read.c" , 5038 ) ); 
  }
  l = FUNCCALL(SETUP_XfOrM836(_), reader (l ) ); 
  ((scheme_current_thread -> list_stack_pos ) = r . pos , (scheme_current_thread -> list_stack ) = r . stack ) ; 
  if (! l )
    FUNCCALL(SETUP_XfOrM836(_), scheme_ill_formed (port , "./../src/read.c" , 5046 ) ); 
  RET_VALUE_START (l ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static long read_simple_number_from_port (Scheme_Object * port ) {
  long a , b , c , d ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(port, 0)));
# define XfOrM839_COUNT (1)
# define SETUP_XfOrM839(x) SETUP(XfOrM839_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a = (unsigned char ) FUNCCALL(SETUP_XfOrM839(_), scheme_get_byte (port ) ); 
  b = (unsigned char ) FUNCCALL(SETUP_XfOrM839(_), scheme_get_byte (port ) ); 
  c = (unsigned char ) FUNCCALL(SETUP_XfOrM839(_), scheme_get_byte (port ) ); 
  d = (unsigned char ) FUNCCALL_EMPTY(scheme_get_byte (port ) ); 
  RET_VALUE_START ((a + (b << 8 ) + (c << 16 ) + (d << 24 ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * read_compiled (Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , Scheme_Hash_Table * * ht , ReadParams * params ) {
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * result , * insp ; 
  long size , shared_size , got , offset = 0 ; 
  CPort * rp ; 
  long symtabsize ; 
  Scheme_Object * * symtab ; 
  long * so ; 
  Scheme_Load_Delay * delay_info ; 
  Scheme_Hash_Table * * local_ht ; 
  int all_short ; 
  Scheme_Config * __funcarg155 = NULLED_OUT ; 
  Scheme_Hash_Table * __funcarg154 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(12);
  BLOCK_SETUP_TOP((PUSH(local_ht, 0), PUSH(params, 1), PUSH(symtab, 2), PUSH(so, 3), PUSH(stxsrc, 4), PUSH(result, 5), PUSH(ht, 6), PUSH(rp, 7), PUSH(delay_info, 8), PUSH(port, 9), PUSH(insp, 10)));
# define XfOrM840_COUNT (11)
# define SETUP_XfOrM840(x) SETUP(XfOrM840_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  result = NULLED_OUT ; 
  insp = NULLED_OUT ; 
  rp = NULLED_OUT ; 
  symtab = NULLED_OUT ; 
  so = NULLED_OUT ; 
  delay_info = NULLED_OUT ; 
  local_ht = NULLED_OUT ; 
  if (0 )
    FUNCCALL(SETUP_XfOrM840(_), scheme_alloc_list_stack (p ) ); 
  if (! cpt_branch [1 ] ) {
    int i ; 
    for (i = 0 ; i < 256 ; i ++ ) {
      cpt_branch [i ] = i ; 
    }
    for (i = 34 ; i < 60 ; i ++ ) {
      cpt_branch [i ] = 34 ; 
    }
    ; 
    for (i = 60 ; i < 80 ; i ++ ) {
      cpt_branch [i ] = 60 ; 
    }
    ; 
    for (i = 80 ; i < 92 ; i ++ ) {
      cpt_branch [i ] = 80 ; 
    }
    ; 
    for (i = (92 + 65 ) ; i < ((92 + 65 ) + 65 ) ; i ++ ) {
      cpt_branch [i ] = (92 + 65 ) ; 
    }
    ; 
    for (i = 92 ; i < (92 + 65 ) ; i ++ ) {
      cpt_branch [i ] = 92 ; 
    }
    ; 
    for (i = 192 ; i < 207 ; i ++ ) {
      cpt_branch [i ] = 192 ; 
    }
    ; 
    for (i = 207 ; i < 222 ; i ++ ) {
      cpt_branch [i ] = 207 ; 
    }
    ; 
    for (i = 222 ; i < 247 ; i ++ ) {
      cpt_branch [i ] = 222 ; 
    }
    ; 
    for (i = 247 ; i < 255 ; i ++ ) {
      cpt_branch [i ] = 247 ; 
    }
    ; 
    cpt_branch [248 ] = 248 ; 
    cpt_branch [249 ] = 249 ; 
  }
  if (! variable_references )
    variable_references = FUNCCALL(SETUP_XfOrM840(_), scheme_make_builtin_references_table () ); 
  if (params -> delay_load_info ) {
#   define XfOrM862_COUNT (0+XfOrM840_COUNT)
#   define SETUP_XfOrM862(x) SETUP_XfOrM840(x)
    delay_info = ((Scheme_Load_Delay * ) FUNCCALL(SETUP_XfOrM862(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Load_Delay ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    delay_info -> type = scheme_rt_delay_load_info ; 
    delay_info -> path = params -> delay_load_info ; 
  }
  else delay_info = ((void * ) 0 ) ; 
  size = FUNCCALL(SETUP_XfOrM840(_), scheme_get_byte (port ) ); 
  {
    char buf [64 ] ; 
#   define XfOrM861_COUNT (0+XfOrM840_COUNT)
#   define SETUP_XfOrM861(x) SETUP_XfOrM840(x)
    if (size < 0 )
      size = 0 ; 
    if (size > 63 )
      size = 63 ; 
    got = FUNCCALL(SETUP_XfOrM861(_), scheme_get_bytes (port , size , buf , 0 ) ); 
    buf [got ] = 0 ; 
    if ((strcmp (buf , "372" "" ) ) )
      FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , got , 0 , ((void * ) 0 ) , "read (compiled): code compiled for version %s, not %s" , (buf [0 ] ? buf : "???" ) , "372" "" ) ); 
  }
  offset += size + 1 ; 
  symtabsize = FUNCCALL(SETUP_XfOrM840(_), read_simple_number_from_port (port ) ); 
  offset += 4 ; 
  all_short = FUNCCALL(SETUP_XfOrM840(_), scheme_get_byte (port ) ); 
  so = (long * ) FUNCCALL(SETUP_XfOrM840(_), scheme_malloc_fail_ok (GC_malloc_atomic , sizeof (long ) * symtabsize ) ); 
  if ((got = FUNCCALL(SETUP_XfOrM840(_), scheme_get_bytes (port , (all_short ? 2 : 4 ) * (symtabsize - 1 ) , (char * ) so , 0 ) )) != ((all_short ? 2 : 4 ) * (symtabsize - 1 ) ) )
    FUNCCALL_EMPTY(scheme_read_err (port , ((void * ) 0 ) , - 1 , - 1 , - 1 , - 1 , 0 , ((void * ) 0 ) , "read (compiled): ill-formed code (bad table count: %ld != %ld)" , got , (all_short ? 2 : 4 ) * (symtabsize - 1 ) ) ); 
  offset += got ; 
  {
    long j , v ; 
    unsigned char * so_c = (unsigned char * ) so ; 
    for (j = symtabsize - 1 ; j -- ; ) {
      if (all_short ) {
        v = so_c [j * 2 ] + (so_c [j * 2 + 1 ] << 8 ) ; 
      }
      else {
        v = so_c [j * 4 ] + (so_c [j * 4 + 1 ] << 8 ) + (so_c [j * 4 + 2 ] << 16 ) + (so_c [j * 4 + 3 ] << 24 ) ; 
      }
      so [j ] = v ; 
    }
  }
  shared_size = FUNCCALL(SETUP_XfOrM840(_), read_simple_number_from_port (port ) ); 
  size = FUNCCALL(SETUP_XfOrM840(_), read_simple_number_from_port (port ) ); 
  if (shared_size >= size ) {
#   define XfOrM853_COUNT (0+XfOrM840_COUNT)
#   define SETUP_XfOrM853(x) SETUP_XfOrM840(x)
    FUNCCALL_EMPTY(scheme_read_err (port , ((void * ) 0 ) , - 1 , - 1 , - 1 , - 1 , 0 , ((void * ) 0 ) , "read (compiled): ill-formed code (shared size %ld >= total size %ld)" , shared_size , size ) ); 
  }
  offset += 8 ; 
  rp = ((CPort * ) FUNCCALL(SETUP_XfOrM840(_), GC_malloc_one_small_tagged ((((sizeof (CPort ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  rp -> type = scheme_rt_compact_port ; 
  {
    unsigned char * st ; 
    BLOCK_SETUP((PUSH(st, 0+XfOrM840_COUNT)));
#   define XfOrM852_COUNT (1+XfOrM840_COUNT)
#   define SETUP_XfOrM852(x) SETUP(XfOrM852_COUNT)
    st = NULLED_OUT ; 
    st = (unsigned char * ) FUNCCALL(SETUP_XfOrM852(_), scheme_malloc_fail_ok (GC_malloc_atomic , size + 1 ) ); 
    rp -> start = st ; 
  }
  rp -> pos = 0 ; 
  {
    long base ; 
#   define XfOrM851_COUNT (0+XfOrM840_COUNT)
#   define SETUP_XfOrM851(x) SETUP_XfOrM840(x)
    FUNCCALL(SETUP_XfOrM851(_), scheme_tell_all (port , ((void * ) 0 ) , ((void * ) 0 ) , & base ) ); 
    rp -> base = base ; 
  }
  rp -> orig_port = port ; 
  rp -> size = size ; 
  if ((got = FUNCCALL(SETUP_XfOrM840(_), scheme_get_bytes (port , size , (char * ) rp -> start , 0 ) )) != size )
    FUNCCALL_EMPTY(scheme_read_err (port , ((void * ) 0 ) , - 1 , - 1 , - 1 , - 1 , 0 , ((void * ) 0 ) , "read (compiled): ill-formed code (bad count: %ld != %ld, started at %ld)" , got , size , rp -> base ) ); 
  local_ht = ((Scheme_Hash_Table * * ) FUNCCALL(SETUP_XfOrM840(_), GC_malloc (sizeof (Scheme_Hash_Table * ) * (1 ) ) )) ; 
  symtab = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM840(_), GC_malloc (sizeof (Scheme_Object * ) * (symtabsize ) ) )) ; 
  rp -> symtab_size = symtabsize ; 
  rp -> ht = local_ht ; 
  rp -> symtab = symtab ; 
  insp = (__funcarg155 = FUNCCALL(SETUP_XfOrM840(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg155 , MZCONFIG_CODE_INSPECTOR ) )) ; 
  rp -> insp = insp ; 
  rp -> magic_sym = params -> magic_sym ; 
  rp -> magic_val = params -> magic_val ; 
  rp -> shared_offsets = so ; 
  rp -> delay_info = delay_info ; 
  if (! delay_info ) {
    long j , len ; 
    Scheme_Object * v ; 
    BLOCK_SETUP((PUSH(v, 0+XfOrM840_COUNT)));
#   define XfOrM844_COUNT (1+XfOrM840_COUNT)
#   define SETUP_XfOrM844(x) SETUP(XfOrM844_COUNT)
    v = NULLED_OUT ; 
    len = symtabsize ; 
    for (j = 1 ; j < len ; j ++ ) {
#     define XfOrM848_COUNT (0+XfOrM844_COUNT)
#     define SETUP_XfOrM848(x) SETUP_XfOrM844(x)
      if (! symtab [j ] ) {
#       define XfOrM850_COUNT (0+XfOrM848_COUNT)
#       define SETUP_XfOrM850(x) SETUP_XfOrM848(x)
        v = FUNCCALL(SETUP_XfOrM850(_), read_compact (rp , 0 ) ); 
        symtab [j ] = v ; 
      }
      else {
        if (j + 1 < len )
          rp -> pos = so [j ] ; 
        else rp -> pos = shared_size ; 
      }
    }
  }
  else {
    rp -> pos = shared_size ; 
    delay_info -> file_offset = offset + 2 ; 
    delay_info -> size = shared_size ; 
    delay_info -> symtab_size = rp -> symtab_size ; 
    delay_info -> symtab = rp -> symtab ; 
    delay_info -> shared_offsets = rp -> shared_offsets ; 
    delay_info -> insp = rp -> insp ; 
  }
  result = FUNCCALL(SETUP_XfOrM840(_), read_marshalled (scheme_compilation_top_type , rp ) ); 
  if (* local_ht ) {
#   define XfOrM842_COUNT (0+XfOrM840_COUNT)
#   define SETUP_XfOrM842(x) SETUP_XfOrM840(x)
    FUNCCALL_EMPTY(scheme_read_err (port , ((void * ) 0 ) , - 1 , - 1 , - 1 , - 1 , 0 , ((void * ) 0 ) , "read (compiled): ill-formed code (unexpected graph structure)" ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (((Scheme_Type ) (((((long ) (result ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (result ) ) -> type ) ) == (Scheme_Type ) (scheme_compilation_top_type ) ) ) {
    Scheme_Compilation_Top * top = (Scheme_Compilation_Top * ) result ; 
    BLOCK_SETUP((PUSH(top, 0+XfOrM840_COUNT)));
#   define XfOrM841_COUNT (1+XfOrM840_COUNT)
#   define SETUP_XfOrM841(x) SETUP(XfOrM841_COUNT)
    (__funcarg154 = FUNCCALL(SETUP_XfOrM841(_), scheme_make_hash_table (SCHEME_hash_ptr ) ), FUNCCALL_AGAIN(scheme_validate_code (rp , top -> code , __funcarg154 , top -> max_let_depth , top -> prefix -> num_toplevels , top -> prefix -> num_stxes , top -> prefix -> num_lifts ) )) ; 
  }
  else FUNCCALL(SETUP_XfOrM840(_), scheme_ill_formed (rp , "./../src/read.c" , 5270 ) ); 
  RET_VALUE_START (result ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_load_delayed_code (int which , Scheme_Load_Delay * delay_info ) {
  CPort * rp ; 
  char * filename ; 
  long size , got ; 
  unsigned char * st ; 
  Scheme_Object * port , * v ; 
  Scheme_Hash_Table * * ht ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(filename, 1), PUSH(rp, 2), PUSH(port, 3), PUSH(delay_info, 4), PUSH(st, 5), PUSH(ht, 6)));
# define XfOrM884_COUNT (7)
# define SETUP_XfOrM884(x) SETUP(XfOrM884_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  rp = NULLED_OUT ; 
  filename = NULLED_OUT ; 
  st = NULLED_OUT ; 
  port = NULLED_OUT ; 
  v = NULLED_OUT ; 
  ht = NULLED_OUT ; 
  filename = FUNCCALL(SETUP_XfOrM884(_), scheme_expand_filename ((((Scheme_Simple_Object * ) (delay_info -> path ) ) -> u . byte_str_val . string_val ) , (((Scheme_Simple_Object * ) (delay_info -> path ) ) -> u . byte_str_val . tag_val ) , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ); 
  port = FUNCCALL_AGAIN(scheme_open_input_file (filename , "on-demand-loader" ) ); 
  size = delay_info -> size ; 
  rp = ((CPort * ) FUNCCALL(SETUP_XfOrM884(_), GC_malloc_one_small_tagged ((((sizeof (CPort ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  rp -> type = scheme_rt_compact_port ; 
  st = (unsigned char * ) FUNCCALL(SETUP_XfOrM884(_), GC_malloc_atomic (size + 1 ) ); 
  rp -> start = st ; 
  rp -> pos = 0 ; 
  rp -> base = 0 ; 
  rp -> orig_port = port ; 
  rp -> size = size ; 
  ht = ((Scheme_Hash_Table * * ) FUNCCALL(SETUP_XfOrM884(_), GC_malloc (sizeof (Scheme_Hash_Table * ) * (1 ) ) )) ; 
  FUNCCALL(SETUP_XfOrM884(_), scheme_set_file_position (port , delay_info -> file_offset ) ); 
  if ((got = FUNCCALL(SETUP_XfOrM884(_), scheme_get_bytes (port , size , (char * ) rp -> start , 0 ) )) != size )
    FUNCCALL_EMPTY(scheme_read_err (port , ((void * ) 0 ) , - 1 , - 1 , - 1 , - 1 , 0 , ((void * ) 0 ) , "on-demand load: ill-formed code (bad count: %ld != %ld, started at %ld)" , got , size , rp -> base ) ); 
  FUNCCALL(SETUP_XfOrM884(_), scheme_close_input_port (port ) ); 
  rp -> symtab_size = delay_info -> symtab_size ; 
  rp -> ht = ht ; 
  rp -> symtab = delay_info -> symtab ; 
  rp -> insp = delay_info -> insp ; 
  rp -> shared_offsets = delay_info -> shared_offsets ; 
  rp -> delay_info = delay_info ; 
  rp -> pos = delay_info -> shared_offsets [which - 1 ] ; 
  v = FUNCCALL(SETUP_XfOrM884(_), read_compact (rp , 0 ) ); 
  delay_info -> symtab [which ] = v ; 
  if (* ht ) {
#   define XfOrM885_COUNT (0+XfOrM884_COUNT)
#   define SETUP_XfOrM885(x) SETUP_XfOrM884(x)
    FUNCCALL(SETUP_XfOrM885(_), resolve_references (v , ((void * ) 0 ) , ((void * ) 0 ) , 0 , scheme_placeholder_type ) ); 
  }
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_unmarshal_wrap_get (Scheme_Unmarshal_Tables * ut , Scheme_Object * wraps_key , int * _decoded ) {
  long l ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(ut, 0), PUSH(_decoded, 1)));
# define XfOrM886_COUNT (2)
# define SETUP_XfOrM886(x) SETUP(XfOrM886_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  l = (((long ) (wraps_key ) ) >> 1 ) ; 
  if ((l < 0 ) || ((unsigned long ) l >= ut -> rp -> symtab_size ) )
    FUNCCALL(SETUP_XfOrM886(_), scheme_ill_formed (ut -> rp , "./../src/read.c" , 5338 ) ); 
  if (! ut -> rp -> symtab [l ] ) {
    Scheme_Object * v ; 
    long save_pos ; 
    BLOCK_SETUP((PUSH(v, 0+XfOrM886_COUNT)));
#   define XfOrM887_COUNT (1+XfOrM886_COUNT)
#   define SETUP_XfOrM887(x) SETUP(XfOrM887_COUNT)
    v = NULLED_OUT ; 
    if (! ut -> rp -> delay_info )
      FUNCCALL(SETUP_XfOrM887(_), scheme_ill_formed (ut -> rp , "./../src/read.c" , 5345 ) ); 
    save_pos = ut -> rp -> pos ; 
    ut -> rp -> pos = ut -> rp -> shared_offsets [l - 1 ] ; 
    v = FUNCCALL(SETUP_XfOrM887(_), read_compact (ut -> rp , 0 ) ); 
    ut -> rp -> pos = save_pos ; 
    ut -> rp -> symtab [l ] = v ; 
  }
  * _decoded = ut -> decoded [l ] ; 
  RET_VALUE_START (ut -> rp -> symtab [l ] ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_unmarshal_wrap_set (Scheme_Unmarshal_Tables * ut , Scheme_Object * wraps_key , Scheme_Object * v ) {
  /* No conversion */
  long l ; 
  l = (((long ) (wraps_key ) ) >> 1 ) ; 
  ut -> rp -> symtab [l ] = v ; 
  ut -> decoded [l ] = 1 ; 
}
Scheme_Object * scheme_make_default_readtable () {
  /* No conversion */
  return scheme_false ; 
}
static int readtable_kind (Readtable * t , int ch , ReadParams * params ) {
  int k ; 
  Scheme_Object * v ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(t, 1), PUSH(params, 2)));
# define XfOrM890_COUNT (3)
# define SETUP_XfOrM890(x) SETUP(XfOrM890_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  if (ch < 128 )
    k = t -> fast_mapping [ch ] ; 
  else {
#   define XfOrM893_COUNT (0+XfOrM890_COUNT)
#   define SETUP_XfOrM893(x) SETUP_XfOrM890(x)
    v = FUNCCALL(SETUP_XfOrM893(_), scheme_hash_get (t -> mapping , ((Scheme_Object * ) (void * ) (long ) ((((long ) (ch ) ) << 1 ) | 0x1 ) ) ) ); 
    if (! v ) {
      if ((((scheme_uchar_table [(ch >> 8 ) & 0x1FFF ] [ch & 0xFF ] ) ) & 0x10 ) )
        k = 0x1 ; 
      else k = 0x2 ; 
    }
    else k = (((long ) ((((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) ) ) >> 1 ) ; 
  }
  if (k == 0x20 ) {
#   define XfOrM892_COUNT (0+XfOrM890_COUNT)
#   define SETUP_XfOrM892(x) SETUP_XfOrM890(x)
    v = FUNCCALL(SETUP_XfOrM892(_), scheme_hash_get (t -> mapping , ((Scheme_Object * ) (void * ) (long ) ((((long ) (ch ) ) << 1 ) | 0x1 ) ) ) ); 
    ch = (((long ) ((((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) ) ) >> 1 ) ; 
    if (ch < 128 )
      k = builtin_fast [ch ] ; 
    else if ((((scheme_uchar_table [(ch >> 8 ) & 0x1FFF ] [ch & 0xFF ] ) ) & 0x10 ) )
      k = 0x1 ; 
    else k = 0x2 ; 
  }
  if (k == 0x10 ) {
    if (! params -> can_read_pipe_quote )
      RET_VALUE_START (0x2 ) RET_VALUE_END ; 
  }
  RET_VALUE_START (k ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * readtable_call (int w_char , int ch , Scheme_Object * proc , ReadParams * params , Scheme_Object * port , Scheme_Object * src , long line , long col , long pos , Scheme_Hash_Table * * ht ) {
  int cnt ; 
  Scheme_Object * a [6 ] , * v ; 
  Scheme_Cont_Frame_Data cframe ; 
  long __funcarg156 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(10);
  BLOCK_SETUP_TOP((PUSH(ht, 0), PUSH(src, 1), PUSHARRAY(a, 6, 2), PUSH(proc, 5), PUSH(cframe.cache, 6), PUSH(v, 7), PUSH(port, 8)));
# define XfOrM895_COUNT (9)
# define SETUP_XfOrM895(x) SETUP(XfOrM895_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  NULL_OUT_ARRAY (a ) ; 
  v = NULLED_OUT ; 
  cframe.cache = NULLED_OUT ; 
  if (w_char ) {
#   define XfOrM902_COUNT (0+XfOrM895_COUNT)
#   define SETUP_XfOrM902(x) SETUP_XfOrM895(x)
    a [0 ] = ((((mzchar ) ch ) < 256 ) ? scheme_char_constants [(unsigned char ) (ch ) ] : FUNCCALL(SETUP_XfOrM902(_), scheme_make_char (ch ) )) ; 
    a [1 ] = port ; 
    a [2 ] = proc ; 
    if (! src && FUNCCALL(SETUP_XfOrM902(_), scheme_check_proc_arity (((void * ) 0 ) , 2 , 2 , 3 , a ) )) {
      cnt = 2 ; 
    }
    else {
      cnt = 6 ; 
      a [2 ] = (src ? src : scheme_false ) ; 
      a [3 ] = (line > 0 ) ? ((Scheme_Object * ) (void * ) (long ) ((((long ) (line ) ) << 1 ) | 0x1 ) ) : scheme_false ; 
      a [4 ] = (col > 0 ) ? ((Scheme_Object * ) (void * ) (long ) ((((long ) (col - 1 ) ) << 1 ) | 0x1 ) ) : scheme_false ; 
      a [5 ] = (pos > 0 ) ? ((Scheme_Object * ) (void * ) (long ) ((((long ) (pos ) ) << 1 ) | 0x1 ) ) : scheme_false ; 
    }
  }
  else {
    if (src ) {
      cnt = 2 ; 
      a [0 ] = src ; 
      a [1 ] = port ; 
    }
    else {
      cnt = 1 ; 
      a [0 ] = port ; 
    }
  }
  FUNCCALL(SETUP_XfOrM895(_), scheme_push_continuation_frame (& cframe ) ); 
  FUNCCALL(SETUP_XfOrM895(_), scheme_set_in_read_mark (src , ht ) ); 
  v = FUNCCALL_AGAIN(scheme_apply (proc , cnt , a ) ); 
  FUNCCALL_AGAIN(scheme_pop_continuation_frame (& cframe ) ); 
  if (! FUNCCALL(SETUP_XfOrM895(_), scheme_special_comment_value (v ) )&& ! ((Scheme_Type ) (scheme_placeholder_type ) == (Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) ) ) {
#   define XfOrM896_COUNT (0+XfOrM895_COUNT)
#   define SETUP_XfOrM896(x) SETUP_XfOrM895(x)
    if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ) {
#     define XfOrM898_COUNT (0+XfOrM896_COUNT)
#     define SETUP_XfOrM898(x) SETUP_XfOrM896(x)
      if (! src )
        v = FUNCCALL(SETUP_XfOrM898(_), scheme_syntax_to_datum (v , 0 , ((void * ) 0 ) ) ); 
    }
    else if (src ) {
      Scheme_Object * s ; 
      BLOCK_SETUP((PUSH(s, 0+XfOrM896_COUNT)));
#     define XfOrM897_COUNT (1+XfOrM896_COUNT)
#     define SETUP_XfOrM897(x) SETUP(XfOrM897_COUNT)
      s = NULLED_OUT ; 
      s = (__funcarg156 = FUNCCALL(SETUP_XfOrM897(_), SPAN (port , pos ) ), FUNCCALL_AGAIN(scheme_make_stx_w_offset (scheme_false , line , col , pos , __funcarg156 , src , scheme_false ) )) ; 
      v = FUNCCALL_AGAIN(scheme_datum_to_syntax (v , s , scheme_false , 1 , 0 ) ); 
    }
    v = FUNCCALL(SETUP_XfOrM896(_), copy_to_protect_placeholders (v , src , ht ) ); 
  }
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_set_in_read_mark (Scheme_Object * src , Scheme_Hash_Table * * ht ) {
  Scheme_Object * v ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(v, 0)));
# define XfOrM905_COUNT (1)
# define SETUP_XfOrM905(x) SETUP(XfOrM905_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  if (ht )
    v = FUNCCALL(SETUP_XfOrM905(_), scheme_make_raw_pair ((Scheme_Object * ) ht , (src ? scheme_true : scheme_false ) ) ); 
  else v = scheme_false ; 
  FUNCCALL_EMPTY(scheme_set_cont_mark (an_uninterned_symbol , v ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * readtable_handle (Readtable * t , int * _ch , int * _use_default , ReadParams * params , Scheme_Object * port , Scheme_Object * src , long line , long col , long pos , Scheme_Hash_Table * * ht ) {
  int ch = * _ch ; 
  Scheme_Object * v ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSH(port, 0), PUSH(src, 1), PUSH(_ch, 2), PUSH(params, 3), PUSH(ht, 4), PUSH(v, 5), PUSH(_use_default, 6)));
# define XfOrM906_COUNT (7)
# define SETUP_XfOrM906(x) SETUP(XfOrM906_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  v = FUNCCALL(SETUP_XfOrM906(_), scheme_hash_get (t -> mapping , ((Scheme_Object * ) (void * ) (long ) ((((long ) (ch ) ) << 1 ) | 0x1 ) ) ) ); 
  if (! v ) {
    * _use_default = 1 ; 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if ((((long ) ((((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) ) ) >> 1 ) == 0x20 ) {
    * _ch = (((long ) ((((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) ) ) >> 1 ) ; 
    * _use_default = 1 ; 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  * _use_default = 0 ; 
  v = (((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) ; 
  v = FUNCCALL(SETUP_XfOrM906(_), readtable_call (1 , ch , v , params , port , src , line , col , pos , ht ) ); 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int readtable_effective_char (Readtable * t , int ch ) {
  Scheme_Object * v ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(v, 0)));
# define XfOrM909_COUNT (1)
# define SETUP_XfOrM909(x) SETUP(XfOrM909_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  if (! t )
    RET_VALUE_START (ch ) RET_VALUE_END ; 
  v = FUNCCALL(SETUP_XfOrM909(_), scheme_hash_get (t -> mapping , ((Scheme_Object * ) (void * ) (long ) ((((long ) (ch ) ) << 1 ) | 0x1 ) ) ) ); 
  if (v ) {
    if ((((long ) ((((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . car ) ) ) >> 1 ) == 0x20 )
      RET_VALUE_START ((((long ) ((((Scheme_Simple_Object * ) (v ) ) -> u . pair_val . cdr ) ) ) >> 1 ) ) RET_VALUE_END ; 
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (ch ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * readtable_handle_hash (Readtable * t , int ch , int * _use_default , ReadParams * params , Scheme_Object * port , Scheme_Object * src , long line , long col , long pos , Scheme_Hash_Table * * ht ) {
  Scheme_Object * v ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(ht, 0), PUSH(port, 1), PUSH(src, 2), PUSH(v, 3), PUSH(_use_default, 4), PUSH(params, 5)));
# define XfOrM911_COUNT (6)
# define SETUP_XfOrM911(x) SETUP(XfOrM911_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  v = FUNCCALL(SETUP_XfOrM911(_), scheme_hash_get (t -> mapping , ((Scheme_Object * ) (void * ) (long ) ((((long ) (- ch ) ) << 1 ) | 0x1 ) ) ) ); 
  if (! v ) {
    * _use_default = 1 ; 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  * _use_default = 0 ; 
  v = FUNCCALL(SETUP_XfOrM911(_), readtable_call (1 , ch , v , params , port , src , line , col , pos , ht ) ); 
  if (FUNCCALL(SETUP_XfOrM911(_), scheme_special_comment_value (v ) ))
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  else RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_readtable (int argc , Scheme_Object * * argv ) {
  Scheme_Object * sym , * val ; 
  Readtable * t , * orig_t ; 
  Scheme_Hash_Table * ht ; 
  char * fast ; 
  int i , ch ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSH(fast, 0), PUSH(argv, 1), PUSH(ht, 2), PUSH(t, 3), PUSH(val, 4), PUSH(sym, 5), PUSH(orig_t, 6)));
# define XfOrM913_COUNT (7)
# define SETUP_XfOrM913(x) SETUP(XfOrM913_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sym = NULLED_OUT ; 
  val = NULLED_OUT ; 
  t = NULLED_OUT ; 
  orig_t = NULLED_OUT ; 
  ht = NULLED_OUT ; 
  fast = NULLED_OUT ; 
  if ((((argv [0 ] ) ) == (scheme_false ) ) )
    orig_t = ((void * ) 0 ) ; 
  else {
#   define XfOrM949_COUNT (0+XfOrM913_COUNT)
#   define SETUP_XfOrM949(x) SETUP_XfOrM913(x)
    if (! ((Scheme_Type ) (scheme_readtable_type ) == (Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) ) ) {
#     define XfOrM950_COUNT (0+XfOrM949_COUNT)
#     define SETUP_XfOrM950(x) SETUP_XfOrM949(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("make-readtable" , "readtable or #f" , 0 , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    orig_t = (Readtable * ) argv [0 ] ; 
  }
  if (! terminating_macro_symbol ) {
#   define XfOrM946_COUNT (0+XfOrM913_COUNT)
#   define SETUP_XfOrM946(x) SETUP_XfOrM913(x)
    FUNCCALL(SETUP_XfOrM946(_), scheme_register_static ((void * ) & terminating_macro_symbol , sizeof (terminating_macro_symbol ) ) ); 
    FUNCCALL(SETUP_XfOrM946(_), scheme_register_static ((void * ) & non_terminating_macro_symbol , sizeof (non_terminating_macro_symbol ) ) ); 
    FUNCCALL_AGAIN(scheme_register_static ((void * ) & dispatch_macro_symbol , sizeof (dispatch_macro_symbol ) ) ); 
    FUNCCALL_AGAIN(scheme_register_static ((void * ) & builtin_fast , sizeof (builtin_fast ) ) ); 
    terminating_macro_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("terminating-macro" ) ); 
    non_terminating_macro_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("non-terminating-macro" ) ); 
    dispatch_macro_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("dispatch-macro" ) ); 
    fast = FUNCCALL_AGAIN(GC_malloc_atomic (128 ) ); 
    (memset (fast , 0x2 , 128 ) ) ; 
    for (i = 0 ; i < 128 ; i ++ ) {
      if ((((scheme_uchar_table [(i >> 8 ) & 0x1FFF ] [i & 0xFF ] ) ) & 0x10 ) )
        fast [i ] = 0x1 ; 
    }
    fast [';' ] = 0x4 ; 
    fast ['\'' ] = 0x4 ; 
    fast [',' ] = 0x4 ; 
    fast ['"' ] = 0x4 ; 
    fast ['|' ] = 0x10 ; 
    fast ['\\' ] = 0x8 ; 
    fast ['(' ] = 0x4 ; 
    fast ['[' ] = 0x4 ; 
    fast ['{' ] = 0x4 ; 
    fast [')' ] = 0x4 ; 
    fast [']' ] = 0x4 ; 
    fast ['}' ] = 0x4 ; 
    builtin_fast = fast ; 
  }
  t = ((Readtable * ) FUNCCALL(SETUP_XfOrM913(_), GC_malloc_one_small_tagged ((((sizeof (Readtable ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  t -> so . type = scheme_readtable_type ; 
  if (orig_t )
    ht = FUNCCALL(SETUP_XfOrM913(_), scheme_clone_hash_table (orig_t -> mapping ) ); 
  else ht = FUNCCALL(SETUP_XfOrM913(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  t -> mapping = ht ; 
  fast = FUNCCALL(SETUP_XfOrM913(_), GC_malloc_atomic (128 ) ); 
  (memcpy (fast , (orig_t ? orig_t -> fast_mapping : builtin_fast ) , 128 ) ) ; 
  t -> fast_mapping = fast ; 
  t -> symbol_parser = (orig_t ? orig_t -> symbol_parser : ((void * ) 0 ) ) ; 
  for (i = 1 ; i < argc ; i += 3 ) {
#   define XfOrM930_COUNT (0+XfOrM913_COUNT)
#   define SETUP_XfOrM930(x) SETUP_XfOrM913(x)
    if (! (((argv [i ] ) ) == (scheme_false ) ) && ! ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_type ) ) ) {
#     define XfOrM945_COUNT (0+XfOrM930_COUNT)
#     define SETUP_XfOrM945(x) SETUP_XfOrM930(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("make-readtable" , "character or #f" , i , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    if (i + 1 >= argc ) {
#     define XfOrM944_COUNT (0+XfOrM930_COUNT)
#     define SETUP_XfOrM944(x) SETUP_XfOrM930(x)
      if ((((argv [i ] ) ) == (scheme_false ) ) )
        FUNCCALL(SETUP_XfOrM944(_), scheme_arg_mismatch ("make-readtable" , "expected 'non-terminating-macro after #f" , ((void * ) 0 ) ) ); 
      else FUNCCALL(SETUP_XfOrM944(_), scheme_arg_mismatch ("make-readtable" , "expected 'terminating-macro, 'non-terminating-macro, 'dispatch-macro," " or character argument after character argument: " , argv [i ] ) ); 
    }
    sym = argv [i + 1 ] ; 
    if (! ((sym ) == (terminating_macro_symbol ) ) && ! ((sym ) == (non_terminating_macro_symbol ) ) && ! ((sym ) == (dispatch_macro_symbol ) ) && ! ((Scheme_Type ) (((((long ) (sym ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (sym ) ) -> type ) ) == (Scheme_Type ) (scheme_char_type ) ) ) {
#     define XfOrM943_COUNT (0+XfOrM930_COUNT)
#     define SETUP_XfOrM943(x) SETUP_XfOrM930(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("make-readtable" , "'terminating-macro, 'non-terminating-macro, 'dispatch-macro, or character" , i + 1 , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    if ((((argv [i ] ) ) == (scheme_false ) ) && ! ((sym ) == (non_terminating_macro_symbol ) ) ) {
#     define XfOrM942_COUNT (0+XfOrM930_COUNT)
#     define SETUP_XfOrM942(x) SETUP_XfOrM930(x)
      FUNCCALL(SETUP_XfOrM942(_), scheme_arg_mismatch ("make-readtable" , "expected 'non-terminating-macro after #f, given: " , sym ) ); 
    }
    if (i + 2 >= argc ) {
#     define XfOrM941_COUNT (0+XfOrM930_COUNT)
#     define SETUP_XfOrM941(x) SETUP_XfOrM930(x)
      FUNCCALL(SETUP_XfOrM941(_), scheme_arg_mismatch ("make-readtable" , (((Scheme_Type ) (((((long ) (sym ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (sym ) ) -> type ) ) == (Scheme_Type ) (scheme_char_type ) ) ? "expected readtable or #f argument after character argument, given: " : "expected procedure argument after symbol argument, given: " ) , argv [i + 1 ] ) ); 
    }
    if ((((argv [i ] ) ) == (scheme_false ) ) ) {
#     define XfOrM940_COUNT (0+XfOrM930_COUNT)
#     define SETUP_XfOrM940(x) SETUP_XfOrM930(x)
      FUNCCALL(SETUP_XfOrM940(_), scheme_check_proc_arity ("make-readtable" , 6 , i + 2 , argc , argv ) ); 
      t -> symbol_parser = argv [i + 2 ] ; 
    }
    else if (((sym ) == (dispatch_macro_symbol ) ) ) {
#     define XfOrM939_COUNT (0+XfOrM930_COUNT)
#     define SETUP_XfOrM939(x) SETUP_XfOrM930(x)
      ch = (((Scheme_Small_Object * ) (argv [i ] ) ) -> u . char_val ) ; 
      FUNCCALL(SETUP_XfOrM939(_), scheme_check_proc_arity ("make-readtable" , 6 , i + 2 , argc , argv ) ); 
      FUNCCALL_AGAIN(scheme_hash_set (t -> mapping , ((Scheme_Object * ) (void * ) (long ) ((((long ) (- ch ) ) << 1 ) | 0x1 ) ) , argv [i + 2 ] ) ); 
    }
    else {
#     define XfOrM931_COUNT (0+XfOrM930_COUNT)
#     define SETUP_XfOrM931(x) SETUP_XfOrM930(x)
      if (((Scheme_Type ) (((((long ) (sym ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (sym ) ) -> type ) ) == (Scheme_Type ) (scheme_char_type ) ) ) {
        Readtable * src ; 
        int sch ; 
#       define XfOrM935_COUNT (0+XfOrM931_COUNT)
#       define SETUP_XfOrM935(x) SETUP_XfOrM931(x)
        src = NULLED_OUT ; 
        if ((((argv [i + 2 ] ) ) == (scheme_false ) ) ) {
          src = ((void * ) 0 ) ; 
        }
        else {
#         define XfOrM936_COUNT (0+XfOrM935_COUNT)
#         define SETUP_XfOrM936(x) SETUP_XfOrM935(x)
          if (! ((Scheme_Type ) (scheme_readtable_type ) == (Scheme_Type ) (((((long ) (argv [i + 2 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i + 2 ] ) ) -> type ) ) ) ) {
#           define XfOrM937_COUNT (0+XfOrM936_COUNT)
#           define SETUP_XfOrM937(x) SETUP_XfOrM936(x)
            FUNCCALL_EMPTY(scheme_wrong_type ("make-readtable" , "readtable or #f" , i + 2 , argc , argv ) ); 
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          }
          src = (Readtable * ) (argv [i + 2 ] ) ; 
        }
        sch = (((Scheme_Small_Object * ) (argv [i + 1 ] ) ) -> u . char_val ) ; 
        if (! src )
          val = ((void * ) 0 ) ; 
        else val = FUNCCALL(SETUP_XfOrM935(_), scheme_hash_get (src -> mapping , ((Scheme_Object * ) (void * ) (long ) ((((long ) (sch ) ) << 1 ) | 0x1 ) ) ) ); 
        if (! val )
          val = FUNCCALL(SETUP_XfOrM935(_), scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (0x20 ) ) << 1 ) | 0x1 ) ) , ((Scheme_Object * ) (void * ) (long ) ((((long ) (sch ) ) << 1 ) | 0x1 ) ) ) ); 
      }
      else {
        int kind ; 
#       define XfOrM934_COUNT (0+XfOrM931_COUNT)
#       define SETUP_XfOrM934(x) SETUP_XfOrM931(x)
        FUNCCALL(SETUP_XfOrM934(_), scheme_check_proc_arity ("make-readtable" , 6 , i + 2 , argc , argv ) ); 
        kind = (((sym ) == (non_terminating_macro_symbol ) ) ? 0x2 : 0x4 ) ; 
        val = FUNCCALL(SETUP_XfOrM934(_), scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (kind ) ) << 1 ) | 0x1 ) ) , argv [i + 2 ] ) ); 
      }
      ch = (((Scheme_Small_Object * ) (argv [i ] ) ) -> u . char_val ) ; 
      if (! val ) {
#       define XfOrM933_COUNT (0+XfOrM931_COUNT)
#       define SETUP_XfOrM933(x) SETUP_XfOrM931(x)
        FUNCCALL(SETUP_XfOrM933(_), scheme_hash_set (t -> mapping , ((Scheme_Object * ) (void * ) (long ) ((((long ) (ch ) ) << 1 ) | 0x1 ) ) , ((void * ) 0 ) ) ); 
        if (ch < 128 )
          t -> fast_mapping [ch ] = 0 ; 
      }
      else {
#       define XfOrM932_COUNT (0+XfOrM931_COUNT)
#       define SETUP_XfOrM932(x) SETUP_XfOrM931(x)
        FUNCCALL(SETUP_XfOrM932(_), scheme_hash_set (t -> mapping , ((Scheme_Object * ) (void * ) (long ) ((((long ) (ch ) ) << 1 ) | 0x1 ) ) , val ) ); 
        if (ch < 128 )
          t -> fast_mapping [ch ] = (char ) (((long ) ((((Scheme_Simple_Object * ) (val ) ) -> u . pair_val . car ) ) ) >> 1 ) ; 
      }
    }
  }
  RET_VALUE_START ((Scheme_Object * ) t ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * readtable_mapping (int argc , Scheme_Object * * argv ) {
  Scheme_Object * v1 , * v2 , * a [3 ] ; 
  Readtable * t ; 
  int ch ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSH(v2, 0), PUSH(t, 1), PUSH(argv, 2), PUSHARRAY(a, 3, 3), PUSH(v1, 6)));
# define XfOrM951_COUNT (7)
# define SETUP_XfOrM951(x) SETUP(XfOrM951_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v1 = NULLED_OUT ; 
  v2 = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  a[2] = NULLED_OUT ; 
  t = NULLED_OUT ; 
  if (! ((Scheme_Type ) (scheme_readtable_type ) == (Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) ) ) {
#   define XfOrM958_COUNT (0+XfOrM951_COUNT)
#   define SETUP_XfOrM958(x) SETUP_XfOrM951(x)
    FUNCCALL(SETUP_XfOrM958(_), scheme_wrong_type ("readtable-mapping" , "readtable" , 0 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_type ) ) ) {
#   define XfOrM957_COUNT (0+XfOrM951_COUNT)
#   define SETUP_XfOrM957(x) SETUP_XfOrM951(x)
    FUNCCALL(SETUP_XfOrM957(_), scheme_wrong_type ("readtable-mapping" , "character" , 1 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  t = (Readtable * ) argv [0 ] ; 
  ch = (((Scheme_Small_Object * ) (argv [1 ] ) ) -> u . char_val ) ; 
  v1 = FUNCCALL(SETUP_XfOrM951(_), scheme_hash_get (t -> mapping , ((Scheme_Object * ) (void * ) (long ) ((((long ) (ch ) ) << 1 ) | 0x1 ) ) ) ); 
  v2 = FUNCCALL_AGAIN(scheme_hash_get (t -> mapping , ((Scheme_Object * ) (void * ) (long ) ((((long ) (- ch ) ) << 1 ) | 0x1 ) ) ) ); 
  a [0 ] = argv [1 ] ; 
  a [1 ] = scheme_false ; 
  if (v1 ) {
    int v ; 
#   define XfOrM953_COUNT (0+XfOrM951_COUNT)
#   define SETUP_XfOrM953(x) SETUP_XfOrM951(x)
    v = (((long ) ((((Scheme_Simple_Object * ) (v1 ) ) -> u . pair_val . car ) ) ) >> 1 ) ; 
    if (v & 0x20 ) {
#     define XfOrM956_COUNT (0+XfOrM953_COUNT)
#     define SETUP_XfOrM956(x) SETUP_XfOrM953(x)
      v = (((long ) ((((Scheme_Simple_Object * ) (v1 ) ) -> u . pair_val . cdr ) ) ) >> 1 ) ; 
      a [0 ] = ((((mzchar ) v ) < 256 ) ? scheme_char_constants [(unsigned char ) (v ) ] : FUNCCALL(SETUP_XfOrM956(_), scheme_make_char (v ) )) ; 
      a [1 ] = scheme_false ; 
    }
    else if (v & 0x2 ) {
      a [0 ] = non_terminating_macro_symbol ; 
      a [1 ] = (((Scheme_Simple_Object * ) (v1 ) ) -> u . pair_val . cdr ) ; 
    }
    else if (v & 0x4 ) {
      a [0 ] = terminating_macro_symbol ; 
      a [1 ] = (((Scheme_Simple_Object * ) (v1 ) ) -> u . pair_val . cdr ) ; 
    }
  }
  a [2 ] = scheme_false ; 
  if (v2 ) {
    a [2 ] = v2 ; 
  }
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM951(_), scheme_values (3 , a ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * readtable_p (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return (((Scheme_Type ) (scheme_readtable_type ) == (Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * readtable_or_false_p (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  if ((((argv [0 ] ) ) == (scheme_false ) ) )
    return scheme_true ; 
  return readtable_p (argc , argv ) ; 
}
static Scheme_Object * current_readtable (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return scheme_param_config ("current-readtable" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_READTABLE ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , readtable_or_false_p , "readtable" , 0 ) ; 
}
static Scheme_Object * current_reader_guard (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return scheme_param_config ("current-reader-guard" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_READER_GUARD ) ) << 1 ) | 0x1 ) ) , argc , argv , 1 , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ; 
}
static Scheme_Object * do_reader (Scheme_Object * modpath , Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params ) {
  Scheme_Object * name , * a [2 ] , * proc , * v ; 
  Scheme_Config * __funcarg157 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(11);
  BLOCK_SETUP_TOP((PUSH(params, 0), PUSH(stxsrc, 1), PUSHARRAY(a, 2, 2), PUSH(name, 5), PUSH(ht, 6), PUSH(proc, 7), PUSH(v, 8), PUSH(modpath, 9), PUSH(port, 10)));
# define XfOrM963_COUNT (11)
# define SETUP_XfOrM963(x) SETUP(XfOrM963_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  name = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  proc = NULLED_OUT ; 
  v = NULLED_OUT ; 
  proc = (__funcarg157 = FUNCCALL(SETUP_XfOrM963(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg157 , MZCONFIG_READER_GUARD ) )) ; 
  a [0 ] = modpath ; 
  modpath = FUNCCALL(SETUP_XfOrM963(_), scheme_apply (proc , 1 , a ) ); 
  a [0 ] = modpath ; 
  if (stxsrc )
    name = FUNCCALL(SETUP_XfOrM963(_), scheme_intern_symbol ("read-syntax" ) ); 
  else name = FUNCCALL(SETUP_XfOrM963(_), scheme_intern_symbol ("read" ) ); 
  a [1 ] = name ; 
  proc = FUNCCALL(SETUP_XfOrM963(_), scheme_dynamic_require (2 , a ) ); 
  a [0 ] = proc ; 
  if (! FUNCCALL(SETUP_XfOrM963(_), scheme_check_proc_arity (((void * ) 0 ) , stxsrc ? 2 : 1 , 0 , 1 , a ) )) {
#   define XfOrM964_COUNT (0+XfOrM963_COUNT)
#   define SETUP_XfOrM964(x) SETUP_XfOrM963(x)
    FUNCCALL(SETUP_XfOrM964(_), scheme_wrong_type ("#reader" , (stxsrc ? "procedure (arity 2)" : "procedure (arity 1)" ) , - 1 , - 1 , a ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  v = FUNCCALL(SETUP_XfOrM963(_), readtable_call (0 , 0 , proc , params , port , stxsrc , line , col , pos , ht ) ); 
  if (FUNCCALL(SETUP_XfOrM963(_), scheme_special_comment_value (v ) ))
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  else RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * read_reader (Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params ) {
  Scheme_Object * modpath ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(indentation, 0), PUSH(ht, 1), PUSH(modpath, 2), PUSH(stxsrc, 3), PUSH(params, 4), PUSH(port, 5)));
# define XfOrM965_COUNT (6)
# define SETUP_XfOrM965(x) SETUP(XfOrM965_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  modpath = NULLED_OUT ; 
  modpath = FUNCCALL(SETUP_XfOrM965(_), scheme_read (port ) ); 
  if ((((modpath ) ) == (scheme_eof ) ) ) {
#   define XfOrM966_COUNT (0+XfOrM965_COUNT)
#   define SETUP_XfOrM966(x) SETUP_XfOrM965(x)
    FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , 1 , (- 1 ) , indentation , "read: expected a datum after #reader, found end-of-file" ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(do_reader (modpath , port , stxsrc , line , col , pos , ht , indentation , params ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * read_lang (Scheme_Object * port , Scheme_Object * stxsrc , long line , long col , long pos , Scheme_Hash_Table * * ht , Scheme_Object * indentation , ReadParams * params ) {
  int size , len ; 
  mzchar * buf , * naya , ch = 0 ; 
  Scheme_Object * modpath ; 
  long __funcarg169 ; 
  long __funcarg168 ; 
  long __funcarg165 ; 
  long __funcarg164 ; 
  long __funcarg163 ; 
  Scheme_Object * __funcarg162 = NULLED_OUT ; 
  Scheme_Object * __funcarg161 = NULLED_OUT ; 
  Scheme_Object * __funcarg160 = NULLED_OUT ; 
  Scheme_Object * __funcarg159 = NULLED_OUT ; 
  Scheme_Object * __funcarg158 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(10);
  BLOCK_SETUP_TOP((PUSH(__funcarg158, 0), PUSH(indentation, 1), PUSH(port, 2), PUSH(modpath, 3), PUSH(stxsrc, 4), PUSH(__funcarg160, 5), PUSH(naya, 6), PUSH(params, 7), PUSH(buf, 8), PUSH(ht, 9)));
# define XfOrM967_COUNT (10)
# define SETUP_XfOrM967(x) SETUP(XfOrM967_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  buf = NULLED_OUT ; 
  naya = NULLED_OUT ; 
  modpath = NULLED_OUT ; 
  size = 32 ; 
  buf = ((mzchar * ) FUNCCALL(SETUP_XfOrM967(_), GC_malloc_atomic (sizeof (mzchar ) * (size ) ) )) ; 
  len = 0 ; 
  while (1 ) {
#   define XfOrM979_COUNT (0+XfOrM967_COUNT)
#   define SETUP_XfOrM979(x) SETUP_XfOrM967(x)
    ch = FUNCCALL(SETUP_XfOrM979(_), scheme_getc_special_ok (port ) ); 
    if (ch == (- 1 ) ) {
      break ; 
    }
    else if (ch == (- 2 ) ) {
#     define XfOrM985_COUNT (0+XfOrM979_COUNT)
#     define SETUP_XfOrM985(x) SETUP_XfOrM979(x)
      (__funcarg169 = FUNCCALL(SETUP_XfOrM985(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg169 , ch , indentation , "read: found non-character while reading `#lang'" ) )) ; 
    }
    else if ((((scheme_uchar_table [(ch >> 8 ) & 0x1FFF ] [ch & 0xFF ] ) ) & 0x10 ) ) {
      break ; 
    }
    else {
#     define XfOrM980_COUNT (0+XfOrM979_COUNT)
#     define SETUP_XfOrM980(x) SETUP_XfOrM979(x)
      if ((ch < 128 ) && ((((scheme_uchar_table [(ch >> 8 ) & 0x1FFF ] [ch & 0xFF ] ) ) & 0x80 ) || (((scheme_uchar_table [(ch >> 8 ) & 0x1FFF ] [ch & 0xFF ] ) ) & 0x40 ) || (ch == '-' ) || (ch == '+' ) || (ch == '_' ) || (ch == '/' ) ) ) {
#       define XfOrM982_COUNT (0+XfOrM980_COUNT)
#       define SETUP_XfOrM982(x) SETUP_XfOrM980(x)
        if (len + 1 >= size ) {
          size *= 2 ; 
#         define XfOrM983_COUNT (0+XfOrM982_COUNT)
#         define SETUP_XfOrM983(x) SETUP_XfOrM982(x)
          naya = ((mzchar * ) FUNCCALL(SETUP_XfOrM983(_), GC_malloc_atomic (sizeof (mzchar ) * (size ) ) )) ; 
          (memcpy (naya , buf , len * sizeof (mzchar ) ) ) ; 
          buf = naya ; 
        }
        buf [len ++ ] = ch ; 
      }
      else {
#       define XfOrM981_COUNT (0+XfOrM980_COUNT)
#       define SETUP_XfOrM981(x) SETUP_XfOrM980(x)
        (__funcarg168 = FUNCCALL(SETUP_XfOrM981(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg168 , ch , indentation , "read: expected only alphanumberic, `-', `+', `_', or `/'" " characters for `#lang', found %c" , ch ) )) ; 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
    }
  }
  if (! len ) {
#   define XfOrM970_COUNT (0+XfOrM967_COUNT)
#   define SETUP_XfOrM970(x) SETUP_XfOrM967(x)
    (__funcarg165 = FUNCCALL(SETUP_XfOrM970(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg165 , ch , indentation , ((ch == ' ' ) ? "read: expected a single space after `#lang'" : "read: expected a non-empty sequence of alphanumberic, `-', `+', `_', or `/' after `#lang '" ) ) )) ; 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (buf [0 ] == '/' ) {
#   define XfOrM969_COUNT (0+XfOrM967_COUNT)
#   define SETUP_XfOrM969(x) SETUP_XfOrM967(x)
    (__funcarg164 = FUNCCALL(SETUP_XfOrM969(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg164 , ch , indentation , "read: a name that does not start `/' after `#lang'" ) )) ; 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (buf [len - 1 ] == '/' ) {
#   define XfOrM968_COUNT (0+XfOrM967_COUNT)
#   define SETUP_XfOrM968(x) SETUP_XfOrM967(x)
    (__funcarg163 = FUNCCALL(SETUP_XfOrM968(_), SPAN (port , pos ) ), FUNCCALL_EMPTY(scheme_read_err (port , stxsrc , line , col , pos , __funcarg163 , ch , indentation , "read: a name that does not end `/' after `#lang'" ) )) ; 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  modpath = (__funcarg158 = FUNCCALL(SETUP_XfOrM967(_), scheme_intern_symbol ("lib" ) ), __funcarg159 = (__funcarg160 = FUNCCALL(SETUP_XfOrM967(_), scheme_make_utf8_string ("lang/reader.ss" ) ), __funcarg161 = (__funcarg162 = FUNCCALL(SETUP_XfOrM967(_), scheme_make_sized_char_string (buf , len , 0 ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg162 , scheme_null ) )) , FUNCCALL_AGAIN(scheme_make_pair (__funcarg160 , __funcarg161 ) )) , FUNCCALL_AGAIN(scheme_make_pair (__funcarg158 , __funcarg159 ) )) ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(do_reader (modpath , port , stxsrc , line , col , pos , ht , indentation , params ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int is_placeholder (Scheme_Object * a , Scheme_Object * src ) {
  /* No conversion */
  if (src && ((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    a = ((Scheme_Stx * ) a ) -> val ; 
  return ((Scheme_Type ) (scheme_placeholder_type ) == (Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) ) ; 
}
static Scheme_Object * copy_to_protect (Scheme_Object * v , Scheme_Object * src , Scheme_Hash_Table * ht , Scheme_Hash_Table * * oht ) ; 
static Scheme_Object * copy_to_protect_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * v = (Scheme_Object * ) p -> ku . k . p1 ; 
  Scheme_Object * src = (Scheme_Object * ) p -> ku . k . p2 ; 
  Scheme_Hash_Table * ht = (Scheme_Hash_Table * ) p -> ku . k . p3 ; 
  Scheme_Hash_Table * * oht = (Scheme_Hash_Table * * ) p -> ku . k . p4 ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  p -> ku . k . p2 = ((void * ) 0 ) ; 
  p -> ku . k . p3 = ((void * ) 0 ) ; 
  p -> ku . k . p4 = ((void * ) 0 ) ; 
  return copy_to_protect (v , src , ht , oht ) ; 
}
static Scheme_Object * copy_to_protect (Scheme_Object * v , Scheme_Object * src , Scheme_Hash_Table * ht , Scheme_Hash_Table * * oht ) {
  Scheme_Object * o , * ph ; 
  int immutable ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(ht, 1), PUSH(src, 2), PUSH(ph, 3), PUSH(o, 4), PUSH(oht, 5)));
# define XfOrM989_COUNT (6)
# define SETUP_XfOrM989(x) SETUP(XfOrM989_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  o = NULLED_OUT ; 
  ph = NULLED_OUT ; 
  {
    unsigned long _stk_pos ; 
#   define XfOrM1006_COUNT (0+XfOrM989_COUNT)
#   define SETUP_XfOrM1006(x) SETUP_XfOrM989(x)
    _stk_pos = (unsigned long ) & _stk_pos ; 
    if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
      Scheme_Thread * p = scheme_current_thread ; 
#     define XfOrM1007_COUNT (0+XfOrM1006_COUNT)
#     define SETUP_XfOrM1007(x) SETUP_XfOrM1006(x)
      p -> ku . k . p1 = (void * ) v ; 
      p -> ku . k . p2 = (void * ) src ; 
      p -> ku . k . p3 = (void * ) ht ; 
      p -> ku . k . p4 = (void * ) oht ; 
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_handle_stack_overflow (copy_to_protect_k ) )) RET_VALUE_EMPTY_END ; 
    }
  }
  {
#   define XfOrM1004_COUNT (0+XfOrM989_COUNT)
#   define SETUP_XfOrM1004(x) SETUP_XfOrM989(x)
    if ((scheme_fuel_counter ) <= 0 ) {
#     define XfOrM1005_COUNT (0+XfOrM1004_COUNT)
#     define SETUP_XfOrM1005(x) SETUP_XfOrM1004(x)
      FUNCCALL(SETUP_XfOrM1005(_), scheme_out_of_fuel () ); 
    }
  }
  ; 
  if (src && ((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    o = ((Scheme_Stx * ) v ) -> val ; 
  else o = v ; 
  if ((((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || ((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) || ((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) && (! src || ((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ) ) {
#   define XfOrM1000_COUNT (0+XfOrM989_COUNT)
#   define SETUP_XfOrM1000(x) SETUP_XfOrM989(x)
    ph = FUNCCALL(SETUP_XfOrM1000(_), scheme_hash_get (ht , o ) ); 
    if (ph ) {
#     define XfOrM1001_COUNT (0+XfOrM1000_COUNT)
#     define SETUP_XfOrM1001(x) SETUP_XfOrM1000(x)
      if (src ) {
#       define XfOrM1003_COUNT (0+XfOrM1001_COUNT)
#       define SETUP_XfOrM1003(x) SETUP_XfOrM1001(x)
        if (((Scheme_Type ) (((((long ) ((((Scheme_Small_Object * ) (ph ) ) -> u . ptr_val ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Small_Object * ) (ph ) ) -> u . ptr_val ) ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
          FUNCCALL(SETUP_XfOrM1003(_), scheme_make_graph_stx ((((Scheme_Small_Object * ) (ph ) ) -> u . ptr_val ) , - 1 , - 1 , - 1 ) ); 
        else (((Scheme_Small_Object * ) (ph ) ) -> u . ptr_val ) = scheme_true ; 
      }
      if (! * oht ) {
#       define XfOrM1002_COUNT (0+XfOrM1001_COUNT)
#       define SETUP_XfOrM1002(x) SETUP_XfOrM1001(x)
        ht = FUNCCALL(SETUP_XfOrM1002(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
        * oht = ht ; 
      }
      RET_VALUE_START (ph ) RET_VALUE_END ; 
    }
    ph = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM1000(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    ph -> type = scheme_placeholder_type ; 
    (((Scheme_Small_Object * ) (ph ) ) -> u . ptr_val ) = scheme_false ; 
    FUNCCALL(SETUP_XfOrM1000(_), scheme_hash_set (ht , o , ph ) ); 
  }
  else ph = ((void * ) 0 ) ; 
  if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
    Scheme_Object * a , * d ; 
    BLOCK_SETUP((PUSH(a, 0+XfOrM989_COUNT), PUSH(d, 1+XfOrM989_COUNT)));
#   define XfOrM998_COUNT (2+XfOrM989_COUNT)
#   define SETUP_XfOrM998(x) SETUP(XfOrM998_COUNT)
    a = NULLED_OUT ; 
    d = NULLED_OUT ; 
    a = FUNCCALL(SETUP_XfOrM998(_), copy_to_protect ((((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . car ) , src , ht , oht ) ); 
    d = FUNCCALL_AGAIN(copy_to_protect ((((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . cdr ) , src , ht , oht ) ); 
    immutable = (((Scheme_Inclhash_Object * ) (o ) ) -> so . keyex & 0x1 ) ; 
    if (immutable && ((a ) == ((((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . car ) ) ) && ((d ) == ((((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . cdr ) ) ) && ! FUNCCALL(SETUP_XfOrM998(_), is_placeholder (a , src ) )&& ! FUNCCALL(SETUP_XfOrM998(_), is_placeholder (d , src ) )) {
#     define XfOrM999_COUNT (0+XfOrM998_COUNT)
#     define SETUP_XfOrM999(x) SETUP_XfOrM998(x)
      if (ph )
        FUNCCALL(SETUP_XfOrM999(_), scheme_hash_set (ht , o , ((void * ) 0 ) ) ); 
      RET_VALUE_START (v ) RET_VALUE_END ; 
    }
    o = FUNCCALL(SETUP_XfOrM998(_), scheme_make_pair (a , d ) ); 
    if (src || immutable )
      ((((Scheme_Inclhash_Object * ) (o ) ) -> so . keyex |= 0x1 ) ) ; 
  }
  else if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_box_type ) ) ) {
    Scheme_Object * x ; 
    BLOCK_SETUP((PUSH(x, 0+XfOrM989_COUNT)));
#   define XfOrM996_COUNT (1+XfOrM989_COUNT)
#   define SETUP_XfOrM996(x) SETUP(XfOrM996_COUNT)
    x = NULLED_OUT ; 
    x = FUNCCALL(SETUP_XfOrM996(_), copy_to_protect ((((Scheme_Small_Object * ) (o ) ) -> u . ptr_val ) , src , ht , oht ) ); 
    immutable = (((Scheme_Inclhash_Object * ) (o ) ) -> so . keyex & 0x1 ) ; 
    if (immutable && ((x ) == ((((Scheme_Small_Object * ) (o ) ) -> u . ptr_val ) ) ) && ! FUNCCALL(SETUP_XfOrM996(_), is_placeholder (x , src ) )) {
#     define XfOrM997_COUNT (0+XfOrM996_COUNT)
#     define SETUP_XfOrM997(x) SETUP_XfOrM996(x)
      if (ph )
        FUNCCALL(SETUP_XfOrM997(_), scheme_hash_set (ht , o , ((void * ) 0 ) ) ); 
      RET_VALUE_START (v ) RET_VALUE_END ; 
    }
    o = FUNCCALL(SETUP_XfOrM996(_), scheme_box (x ) ); 
    if (src || immutable )
      ((((Scheme_Inclhash_Object * ) (o ) ) -> so . keyex |= 0x1 ) ) ; 
  }
  else if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_vector_type ) ) ) {
    int immutable = (((Scheme_Inclhash_Object * ) (o ) ) -> so . keyex & 0x1 ) ; 
    int i , len , use_copy = ! immutable ; 
    Scheme_Object * a , * o2 ; 
    BLOCK_SETUP((PUSH(a, 0+XfOrM989_COUNT), PUSH(o2, 1+XfOrM989_COUNT)));
#   define XfOrM992_COUNT (2+XfOrM989_COUNT)
#   define SETUP_XfOrM992(x) SETUP(XfOrM992_COUNT)
    a = NULLED_OUT ; 
    o2 = NULLED_OUT ; 
    len = (((Scheme_Vector * ) (o ) ) -> size ) ; 
    o2 = FUNCCALL(SETUP_XfOrM992(_), scheme_make_vector (len , ((void * ) 0 ) ) ); 
    for (i = 0 ; i < len ; i ++ ) {
#     define XfOrM995_COUNT (0+XfOrM992_COUNT)
#     define SETUP_XfOrM995(x) SETUP_XfOrM992(x)
      a = FUNCCALL(SETUP_XfOrM995(_), copy_to_protect ((((Scheme_Vector * ) (o ) ) -> els ) [i ] , src , ht , oht ) ); 
      if (! ((a ) == ((((Scheme_Vector * ) (o ) ) -> els ) [i ] ) ) || FUNCCALL(SETUP_XfOrM995(_), is_placeholder (a , src ) ))
        use_copy = 1 ; 
      (((Scheme_Vector * ) (o2 ) ) -> els ) [i ] = a ; 
    }
    if (! use_copy ) {
#     define XfOrM993_COUNT (0+XfOrM992_COUNT)
#     define SETUP_XfOrM993(x) SETUP_XfOrM992(x)
      if (ph )
        FUNCCALL(SETUP_XfOrM993(_), scheme_hash_set (ht , o , ((void * ) 0 ) ) ); 
      RET_VALUE_START (v ) RET_VALUE_END ; 
    }
    o = o2 ; 
    if (src || immutable )
      ((((Scheme_Inclhash_Object * ) (o ) ) -> so . keyex |= 0x1 ) ) ; 
  }
  else {
    RET_VALUE_START (v ) RET_VALUE_END ; 
  }
  if (src && ((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) ) {
#   define XfOrM990_COUNT (0+XfOrM989_COUNT)
#   define SETUP_XfOrM990(x) SETUP_XfOrM989(x)
    o = FUNCCALL(SETUP_XfOrM990(_), scheme_datum_to_syntax (o , v , v , 0 , 2 ) ); 
    if (ph && (! ((((((Scheme_Small_Object * ) (ph ) ) -> u . ptr_val ) ) ) == (scheme_false ) ) ) )
      FUNCCALL(SETUP_XfOrM990(_), scheme_make_graph_stx (o , - 1 , - 1 , - 1 ) ); 
  }
  if (ph )
    (((Scheme_Small_Object * ) (ph ) ) -> u . ptr_val ) = o ; 
  RET_VALUE_START (o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * copy_to_protect_placeholders (Scheme_Object * v , Scheme_Object * src , Scheme_Hash_Table * * oht ) {
  Scheme_Hash_Table * ht ; 
  PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(src, 1), PUSH(oht, 2), PUSH(ht, 3)));
# define XfOrM1008_COUNT (4)
# define SETUP_XfOrM1008(x) SETUP(XfOrM1008_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ht = NULLED_OUT ; 
  ht = FUNCCALL(SETUP_XfOrM1008(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(copy_to_protect (v , src , ht , oht ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int mark_indent_SIZE (void * p ) {
  return ((sizeof (Scheme_Indent ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_indent_MARK (void * p ) {
  return ((sizeof (Scheme_Indent ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_indent_FIXUP (void * p ) {
  return ((sizeof (Scheme_Indent ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_cport_SIZE (void * p ) {
  return ((sizeof (CPort ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_cport_MARK (void * p ) {
  CPort * cp = (CPort * ) p ; 
  GC_mark (cp -> start ) ; 
  GC_mark (cp -> orig_port ) ; 
  GC_mark (cp -> ht ) ; 
  GC_mark (cp -> ut ) ; 
  GC_mark (cp -> symtab ) ; 
  GC_mark (cp -> insp ) ; 
  GC_mark (cp -> magic_sym ) ; 
  GC_mark (cp -> magic_val ) ; 
  GC_mark (cp -> shared_offsets ) ; 
  GC_mark (cp -> delay_info ) ; 
  return ((sizeof (CPort ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_cport_FIXUP (void * p ) {
  CPort * cp = (CPort * ) p ; 
  GC_fixup (& (cp -> start ) ) ; 
  GC_fixup (& (cp -> orig_port ) ) ; 
  GC_fixup (& (cp -> ht ) ) ; 
  GC_fixup (& (cp -> ut ) ) ; 
  GC_fixup (& (cp -> symtab ) ) ; 
  GC_fixup (& (cp -> insp ) ) ; 
  GC_fixup (& (cp -> magic_sym ) ) ; 
  GC_fixup (& (cp -> magic_val ) ) ; 
  GC_fixup (& (cp -> shared_offsets ) ) ; 
  GC_fixup (& (cp -> delay_info ) ) ; 
  return ((sizeof (CPort ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_readtable_SIZE (void * p ) {
  return ((sizeof (Readtable ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_readtable_MARK (void * p ) {
  Readtable * t = (Readtable * ) p ; 
  GC_mark (t -> mapping ) ; 
  GC_mark (t -> fast_mapping ) ; 
  GC_mark (t -> symbol_parser ) ; 
  GC_mark (t -> names ) ; 
  return ((sizeof (Readtable ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_readtable_FIXUP (void * p ) {
  Readtable * t = (Readtable * ) p ; 
  GC_fixup (& (t -> mapping ) ) ; 
  GC_fixup (& (t -> fast_mapping ) ) ; 
  GC_fixup (& (t -> symbol_parser ) ) ; 
  GC_fixup (& (t -> names ) ) ; 
  return ((sizeof (Readtable ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_read_params_SIZE (void * p ) {
  return ((sizeof (ReadParams ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_read_params_MARK (void * p ) {
  ReadParams * rp = (ReadParams * ) p ; 
  GC_mark (rp -> table ) ; 
  GC_mark (rp -> magic_sym ) ; 
  GC_mark (rp -> magic_val ) ; 
  GC_mark (rp -> delay_load_info ) ; 
  return ((sizeof (ReadParams ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_read_params_FIXUP (void * p ) {
  ReadParams * rp = (ReadParams * ) p ; 
  GC_fixup (& (rp -> table ) ) ; 
  GC_fixup (& (rp -> magic_sym ) ) ; 
  GC_fixup (& (rp -> magic_val ) ) ; 
  GC_fixup (& (rp -> delay_load_info ) ) ; 
  return ((sizeof (ReadParams ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_delay_load_SIZE (void * p ) {
  return ((sizeof (Scheme_Load_Delay ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_delay_load_MARK (void * p ) {
  Scheme_Load_Delay * ld = (Scheme_Load_Delay * ) p ; 
  GC_mark (ld -> path ) ; 
  GC_mark (ld -> symtab ) ; 
  GC_mark (ld -> shared_offsets ) ; 
  GC_mark (ld -> insp ) ; 
  GC_mark (ld -> rn_memory ) ; 
  return ((sizeof (Scheme_Load_Delay ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_delay_load_FIXUP (void * p ) {
  Scheme_Load_Delay * ld = (Scheme_Load_Delay * ) p ; 
  GC_fixup (& (ld -> path ) ) ; 
  GC_fixup (& (ld -> symtab ) ) ; 
  GC_fixup (& (ld -> shared_offsets ) ) ; 
  GC_fixup (& (ld -> insp ) ) ; 
  GC_fixup (& (ld -> rn_memory ) ) ; 
  return ((sizeof (Scheme_Load_Delay ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_unmarshal_tables_SIZE (void * p ) {
  return ((sizeof (Scheme_Unmarshal_Tables ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_unmarshal_tables_MARK (void * p ) {
  Scheme_Unmarshal_Tables * ut = (Scheme_Unmarshal_Tables * ) p ; 
  GC_mark (ut -> rns ) ; 
  GC_mark (ut -> rp ) ; 
  GC_mark (ut -> decoded ) ; 
  return ((sizeof (Scheme_Unmarshal_Tables ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_unmarshal_tables_FIXUP (void * p ) {
  Scheme_Unmarshal_Tables * ut = (Scheme_Unmarshal_Tables * ) p ; 
  GC_fixup (& (ut -> rns ) ) ; 
  GC_fixup (& (ut -> rp ) ) ; 
  GC_fixup (& (ut -> decoded ) ) ; 
  return ((sizeof (Scheme_Unmarshal_Tables ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static void register_traversers (void ) {
  GC_register_traversers (scheme_indent_type , mark_indent_SIZE , mark_indent_MARK , mark_indent_FIXUP , 1 , 1 ) ; 
  GC_register_traversers (scheme_rt_compact_port , mark_cport_SIZE , mark_cport_MARK , mark_cport_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_readtable_type , mark_readtable_SIZE , mark_readtable_MARK , mark_readtable_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_read_params , mark_read_params_SIZE , mark_read_params_MARK , mark_read_params_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_delay_load_info , mark_delay_load_SIZE , mark_delay_load_MARK , mark_delay_load_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_unmarshal_info , mark_unmarshal_tables_SIZE , mark_unmarshal_tables_MARK , mark_unmarshal_tables_FIXUP , 1 , 0 ) ; 
}
