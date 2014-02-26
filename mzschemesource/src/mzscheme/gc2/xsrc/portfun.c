#include "precomp.h"
static Scheme_Object * input_port_p (int , Scheme_Object * [] ) ; 
static Scheme_Object * output_port_p (int , Scheme_Object * [] ) ; 
static Scheme_Object * port_closed_p (int , Scheme_Object * [] ) ; 
static Scheme_Object * current_input_port (int , Scheme_Object * [] ) ; 
static Scheme_Object * current_output_port (int , Scheme_Object * [] ) ; 
static Scheme_Object * current_error_port (int , Scheme_Object * [] ) ; 
static Scheme_Object * make_input_port (int , Scheme_Object * [] ) ; 
static Scheme_Object * make_output_port (int , Scheme_Object * [] ) ; 
static Scheme_Object * open_input_file (int , Scheme_Object * [] ) ; 
static Scheme_Object * open_output_file (int , Scheme_Object * [] ) ; 
static Scheme_Object * open_input_output_file (int , Scheme_Object * [] ) ; 
static Scheme_Object * close_input_port (int , Scheme_Object * [] ) ; 
static Scheme_Object * close_output_port (int , Scheme_Object * [] ) ; 
static Scheme_Object * call_with_output_file (int , Scheme_Object * [] ) ; 
static Scheme_Object * call_with_input_file (int , Scheme_Object * [] ) ; 
static Scheme_Object * with_input_from_file (int , Scheme_Object * [] ) ; 
static Scheme_Object * with_output_to_file (int , Scheme_Object * [] ) ; 
static Scheme_Object * read_f (int , Scheme_Object * [] ) ; 
static Scheme_Object * read_recur_f (int , Scheme_Object * [] ) ; 
static Scheme_Object * read_honu_f (int , Scheme_Object * [] ) ; 
static Scheme_Object * read_honu_recur_f (int , Scheme_Object * [] ) ; 
static Scheme_Object * read_syntax_f (int , Scheme_Object * [] ) ; 
static Scheme_Object * read_syntax_recur_f (int , Scheme_Object * [] ) ; 
static Scheme_Object * read_honu_syntax_f (int , Scheme_Object * [] ) ; 
static Scheme_Object * read_honu_syntax_recur_f (int , Scheme_Object * [] ) ; 
static Scheme_Object * read_char (int , Scheme_Object * [] ) ; 
static Scheme_Object * read_char_spec (int , Scheme_Object * [] ) ; 
static Scheme_Object * read_byte (int , Scheme_Object * [] ) ; 
static Scheme_Object * read_byte_spec (int , Scheme_Object * [] ) ; 
static Scheme_Object * read_line (int , Scheme_Object * [] ) ; 
static Scheme_Object * read_byte_line (int , Scheme_Object * [] ) ; 
static Scheme_Object * sch_read_string (int , Scheme_Object * [] ) ; 
static Scheme_Object * sch_read_string_bang (int , Scheme_Object * [] ) ; 
static Scheme_Object * sch_peek_string (int , Scheme_Object * [] ) ; 
static Scheme_Object * sch_peek_string_bang (int , Scheme_Object * [] ) ; 
static Scheme_Object * sch_read_bytes (int , Scheme_Object * [] ) ; 
static Scheme_Object * sch_read_bytes_bang (int , Scheme_Object * [] ) ; 
static Scheme_Object * sch_peek_bytes (int , Scheme_Object * [] ) ; 
static Scheme_Object * sch_peek_bytes_bang (int , Scheme_Object * [] ) ; 
static Scheme_Object * read_bytes_bang (int , Scheme_Object * [] ) ; 
static Scheme_Object * read_bytes_bang_nonblock (int , Scheme_Object * [] ) ; 
static Scheme_Object * read_bytes_bang_break (int , Scheme_Object * [] ) ; 
static Scheme_Object * peek_bytes_bang (int , Scheme_Object * [] ) ; 
static Scheme_Object * peek_bytes_bang_nonblock (int , Scheme_Object * [] ) ; 
static Scheme_Object * peek_bytes_bang_break (int , Scheme_Object * [] ) ; 
static Scheme_Object * write_bytes (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * write_string (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * write_bytes_avail (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * write_bytes_avail_nonblock (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * write_bytes_avail_break (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * can_write_atomic (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * can_provide_progress_evt (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * can_write_special (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * peek_char (int , Scheme_Object * [] ) ; 
static Scheme_Object * peek_char_spec (int , Scheme_Object * [] ) ; 
static Scheme_Object * peek_byte (int , Scheme_Object * [] ) ; 
static Scheme_Object * peek_byte_spec (int , Scheme_Object * [] ) ; 
static Scheme_Object * eof_object_p (int , Scheme_Object * [] ) ; 
static Scheme_Object * char_ready_p (int , Scheme_Object * [] ) ; 
static Scheme_Object * byte_ready_p (int , Scheme_Object * [] ) ; 
static Scheme_Object * peeked_read (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * progress_evt (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * write_bytes_avail_evt (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * write_special_evt (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * sch_write (int , Scheme_Object * [] ) ; 
static Scheme_Object * display (int , Scheme_Object * [] ) ; 
static Scheme_Object * sch_print (int , Scheme_Object * [] ) ; 
static Scheme_Object * newline (int , Scheme_Object * [] ) ; 
static Scheme_Object * write_char (int , Scheme_Object * [] ) ; 
static Scheme_Object * write_byte (int , Scheme_Object * [] ) ; 
static Scheme_Object * load (int , Scheme_Object * [] ) ; 
static Scheme_Object * current_load (int , Scheme_Object * [] ) ; 
static Scheme_Object * current_load_directory (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * current_write_directory (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * default_load (int , Scheme_Object * [] ) ; 
static Scheme_Object * transcript_on (int , Scheme_Object * [] ) ; 
static Scheme_Object * transcript_off (int , Scheme_Object * [] ) ; 
static Scheme_Object * flush_output (int , Scheme_Object * [] ) ; 
static Scheme_Object * open_input_char_string (int , Scheme_Object * [] ) ; 
static Scheme_Object * open_input_byte_string (int , Scheme_Object * [] ) ; 
static Scheme_Object * open_output_string (int , Scheme_Object * [] ) ; 
static Scheme_Object * get_output_char_string (int , Scheme_Object * [] ) ; 
static Scheme_Object * get_output_byte_string (int , Scheme_Object * [] ) ; 
static Scheme_Object * sch_pipe (int , Scheme_Object * * args ) ; 
static Scheme_Object * pipe_length (int , Scheme_Object * * args ) ; 
static Scheme_Object * port_read_handler (int , Scheme_Object * * args ) ; 
static Scheme_Object * port_display_handler (int , Scheme_Object * * args ) ; 
static Scheme_Object * port_write_handler (int , Scheme_Object * * args ) ; 
static Scheme_Object * port_print_handler (int , Scheme_Object * * args ) ; 
static Scheme_Object * global_port_print_handler (int , Scheme_Object * * args ) ; 
static Scheme_Object * global_port_count_lines (int , Scheme_Object * * args ) ; 
static Scheme_Object * port_count_lines (int , Scheme_Object * * args ) ; 
static Scheme_Object * port_next_location (int , Scheme_Object * * args ) ; 
static Scheme_Object * sch_default_read_handler (void * ignore , int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * sch_default_display_handler (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * sch_default_write_handler (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * sch_default_print_handler (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * sch_default_global_port_print_handler (int argc , Scheme_Object * argv [] ) ; 
static void register_traversers (void ) ; 
static Scheme_Object * any_symbol , * any_one_symbol ; 
static Scheme_Object * cr_symbol , * lf_symbol , * crlf_symbol ; 
static Scheme_Object * module_symbol ; 
static Scheme_Object * default_read_handler ; 
static Scheme_Object * default_display_handler ; 
static Scheme_Object * default_write_handler ; 
static Scheme_Object * default_print_handler ; 
Scheme_Object * scheme_default_global_print_handler ; 
Scheme_Object * scheme_write_proc , * scheme_display_proc , * scheme_print_proc ; 
static Scheme_Object * dummy_input_port , * dummy_output_port ; 
void scheme_init_port_fun (Scheme_Env * env ) {
  Scheme_Object * p ; 
  Scheme_Object * __funcarg99 = NULLED_OUT ; 
  Scheme_Object * __funcarg98 = NULLED_OUT ; 
  Scheme_Object * __funcarg97 = NULLED_OUT ; 
  Scheme_Object * __funcarg96 = NULLED_OUT ; 
  Scheme_Object * __funcarg95 = NULLED_OUT ; 
  Scheme_Object * __funcarg94 = NULLED_OUT ; 
  Scheme_Object * __funcarg93 = NULLED_OUT ; 
  Scheme_Object * __funcarg92 = NULLED_OUT ; 
  Scheme_Object * __funcarg91 = NULLED_OUT ; 
  Scheme_Object * __funcarg90 = NULLED_OUT ; 
  Scheme_Object * __funcarg89 = NULLED_OUT ; 
  Scheme_Object * __funcarg88 = NULLED_OUT ; 
  Scheme_Object * __funcarg87 = NULLED_OUT ; 
  Scheme_Object * __funcarg86 = NULLED_OUT ; 
  Scheme_Object * __funcarg85 = NULLED_OUT ; 
  Scheme_Object * __funcarg84 = NULLED_OUT ; 
  Scheme_Object * __funcarg83 = NULLED_OUT ; 
  Scheme_Object * __funcarg82 = NULLED_OUT ; 
  Scheme_Object * __funcarg81 = NULLED_OUT ; 
  Scheme_Object * __funcarg80 = NULLED_OUT ; 
  Scheme_Object * __funcarg79 = NULLED_OUT ; 
  Scheme_Object * __funcarg78 = NULLED_OUT ; 
  Scheme_Object * __funcarg77 = NULLED_OUT ; 
  Scheme_Object * __funcarg76 = NULLED_OUT ; 
  Scheme_Object * __funcarg75 = NULLED_OUT ; 
  Scheme_Object * __funcarg74 = NULLED_OUT ; 
  Scheme_Object * __funcarg73 = NULLED_OUT ; 
  Scheme_Object * __funcarg72 = NULLED_OUT ; 
  Scheme_Object * __funcarg71 = NULLED_OUT ; 
  Scheme_Object * __funcarg70 = NULLED_OUT ; 
  Scheme_Object * __funcarg69 = NULLED_OUT ; 
  Scheme_Object * __funcarg68 = NULLED_OUT ; 
  Scheme_Object * __funcarg67 = NULLED_OUT ; 
  Scheme_Object * __funcarg66 = NULLED_OUT ; 
  Scheme_Object * __funcarg65 = NULLED_OUT ; 
  Scheme_Object * __funcarg64 = NULLED_OUT ; 
  Scheme_Object * __funcarg63 = NULLED_OUT ; 
  Scheme_Object * __funcarg62 = NULLED_OUT ; 
  Scheme_Object * __funcarg61 = NULLED_OUT ; 
  Scheme_Object * __funcarg60 = NULLED_OUT ; 
  Scheme_Object * __funcarg59 = NULLED_OUT ; 
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
  Scheme_Object * __funcarg45 = NULLED_OUT ; 
  Scheme_Object * __funcarg44 = NULLED_OUT ; 
  Scheme_Object * __funcarg43 = NULLED_OUT ; 
  Scheme_Object * __funcarg42 = NULLED_OUT ; 
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
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(p, 1)));
# define XfOrM1_COUNT (2)
# define SETUP_XfOrM1(x) SETUP(XfOrM1_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  p = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM1(_), register_traversers () ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & default_read_handler , sizeof (default_read_handler ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & default_display_handler , sizeof (default_display_handler ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & default_write_handler , sizeof (default_write_handler ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & default_print_handler , sizeof (default_print_handler ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_write_proc , sizeof (scheme_write_proc ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_display_proc , sizeof (scheme_display_proc ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_print_proc , sizeof (scheme_print_proc ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & any_symbol , sizeof (any_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & any_one_symbol , sizeof (any_one_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & cr_symbol , sizeof (cr_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & lf_symbol , sizeof (lf_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & crlf_symbol , sizeof (crlf_symbol ) ) ); 
  any_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("any" ) ); 
  any_one_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("any-one" ) ); 
  cr_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("return" ) ); 
  lf_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("linefeed" ) ); 
  crlf_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("return-linefeed" ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & module_symbol , sizeof (module_symbol ) ) ); 
  module_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("module" ) ); 
  scheme_write_proc = FUNCCALL_AGAIN(scheme_make_noncm_prim (sch_write , "write" , 1 , 2 ) ); 
  scheme_display_proc = FUNCCALL_AGAIN(scheme_make_noncm_prim (display , "display" , 1 , 2 ) ); 
  scheme_print_proc = FUNCCALL_AGAIN(scheme_make_noncm_prim (sch_print , "print" , 1 , 2 ) ); 
  default_read_handler = FUNCCALL_AGAIN(scheme_make_closed_prim_w_arity (sch_default_read_handler , ((void * ) 0 ) , "default-port-read-handler" , 1 , 2 ) ); 
  default_display_handler = FUNCCALL_AGAIN(scheme_make_prim_w_arity (sch_default_display_handler , "default-port-display-handler" , 2 , 2 ) ); 
  default_write_handler = FUNCCALL_AGAIN(scheme_make_prim_w_arity (sch_default_write_handler , "default-port-write-handler" , 2 , 2 ) ); 
  default_print_handler = FUNCCALL_AGAIN(scheme_make_prim_w_arity (sch_default_print_handler , "default-port-print-handler" , 2 , 2 ) ); 
  FUNCCALL_AGAIN(scheme_init_port_fun_config () ); 
  FUNCCALL_AGAIN(scheme_add_global_constant ("eof" , scheme_eof , env ) ); 
  (__funcarg99 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (input_port_p , "input-port?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("input-port?" , __funcarg99 , env ) )) ; 
  (__funcarg98 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (output_port_p , "output-port?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("output-port?" , __funcarg98 , env ) )) ; 
  (__funcarg97 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (scheme_file_stream_port_p , "file-stream-port?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("file-stream-port?" , __funcarg97 , env ) )) ; 
  (__funcarg96 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (scheme_terminal_port_p , "terminal-port?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("terminal-port?" , __funcarg96 , env ) )) ; 
  (__funcarg95 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (port_closed_p , "port-closed?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("port-closed?" , __funcarg95 , env ) )) ; 
  (__funcarg94 = FUNCCALL(SETUP_XfOrM1(_), scheme_register_parameter (current_input_port , "current-input-port" , MZCONFIG_INPUT_PORT ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-input-port" , __funcarg94 , env ) )) ; 
  (__funcarg93 = FUNCCALL(SETUP_XfOrM1(_), scheme_register_parameter (current_output_port , "current-output-port" , MZCONFIG_OUTPUT_PORT ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-output-port" , __funcarg93 , env ) )) ; 
  (__funcarg92 = FUNCCALL(SETUP_XfOrM1(_), scheme_register_parameter (current_error_port , "current-error-port" , MZCONFIG_ERROR_PORT ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-error-port" , __funcarg92 , env ) )) ; 
  (__funcarg91 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (open_input_file , "open-input-file" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("open-input-file" , __funcarg91 , env ) )) ; 
  (__funcarg90 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (open_input_byte_string , "open-input-bytes" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("open-input-bytes" , __funcarg90 , env ) )) ; 
  (__funcarg89 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (open_input_char_string , "open-input-string" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("open-input-string" , __funcarg89 , env ) )) ; 
  (__funcarg88 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (open_output_file , "open-output-file" , 1 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("open-output-file" , __funcarg88 , env ) )) ; 
  (__funcarg87 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (open_output_string , "open-output-bytes" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("open-output-bytes" , __funcarg87 , env ) )) ; 
  (__funcarg86 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (open_output_string , "open-output-string" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("open-output-string" , __funcarg86 , env ) )) ; 
  (__funcarg85 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (get_output_byte_string , "get-output-bytes" , 1 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("get-output-bytes" , __funcarg85 , env ) )) ; 
  (__funcarg84 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (get_output_char_string , "get-output-string" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("get-output-string" , __funcarg84 , env ) )) ; 
  (__funcarg83 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (open_input_output_file , "open-input-output-file" , 1 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("open-input-output-file" , __funcarg83 , env ) )) ; 
  (__funcarg82 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (close_input_port , "close-input-port" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("close-input-port" , __funcarg82 , env ) )) ; 
  (__funcarg81 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (close_output_port , "close-output-port" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("close-output-port" , __funcarg81 , env ) )) ; 
  (__funcarg80 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_everything (call_with_output_file , 0 , "call-with-output-file" , 2 , 4 , 0 , 0 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("call-with-output-file" , __funcarg80 , env ) )) ; 
  (__funcarg79 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_everything (call_with_input_file , 0 , "call-with-input-file" , 2 , 3 , 0 , 0 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("call-with-input-file" , __funcarg79 , env ) )) ; 
  (__funcarg78 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_everything (with_output_to_file , 0 , "with-output-to-file" , 2 , 4 , 0 , 0 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("with-output-to-file" , __funcarg78 , env ) )) ; 
  (__funcarg77 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_everything (with_input_from_file , 0 , "with-input-from-file" , 2 , 3 , 0 , 0 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("with-input-from-file" , __funcarg77 , env ) )) ; 
  (__funcarg76 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (make_input_port , "make-input-port" , 4 , 10 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-input-port" , __funcarg76 , env ) )) ; 
  (__funcarg75 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (make_output_port , "make-output-port" , 4 , 11 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-output-port" , __funcarg75 , env ) )) ; 
  (__funcarg74 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (read_f , "read" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read" , __funcarg74 , env ) )) ; 
  (__funcarg73 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (read_recur_f , "read/recursive" , 0 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read/recursive" , __funcarg73 , env ) )) ; 
  (__funcarg72 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (read_syntax_f , "read-syntax" , 0 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-syntax" , __funcarg72 , env ) )) ; 
  (__funcarg71 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (read_syntax_recur_f , "read-syntax/recursive" , 0 , 5 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-syntax/recursive" , __funcarg71 , env ) )) ; 
  (__funcarg70 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (read_honu_f , "read-honu" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-honu" , __funcarg70 , env ) )) ; 
  (__funcarg69 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (read_honu_recur_f , "read-honu/recursive" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-honu/recursive" , __funcarg69 , env ) )) ; 
  (__funcarg68 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (read_honu_syntax_f , "read-honu-syntax" , 0 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-honu-syntax" , __funcarg68 , env ) )) ; 
  (__funcarg67 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (read_honu_syntax_recur_f , "read-honu-syntax/recursive" , 0 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-honu-syntax/recursive" , __funcarg67 , env ) )) ; 
  (__funcarg66 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (read_char , "read-char" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-char" , __funcarg66 , env ) )) ; 
  (__funcarg65 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (read_char_spec , "read-char-or-special" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-char-or-special" , __funcarg65 , env ) )) ; 
  (__funcarg64 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (read_byte , "read-byte" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-byte" , __funcarg64 , env ) )) ; 
  (__funcarg63 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (read_byte_spec , "read-byte-or-special" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-byte-or-special" , __funcarg63 , env ) )) ; 
  (__funcarg62 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (read_byte_line , "read-bytes-line" , 0 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-bytes-line" , __funcarg62 , env ) )) ; 
  (__funcarg61 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (read_line , "read-line" , 0 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-line" , __funcarg61 , env ) )) ; 
  (__funcarg60 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (sch_read_string , "read-string" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-string" , __funcarg60 , env ) )) ; 
  (__funcarg59 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (sch_read_string_bang , "read-string!" , 1 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-string!" , __funcarg59 , env ) )) ; 
  (__funcarg58 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (sch_peek_string , "peek-string" , 2 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("peek-string" , __funcarg58 , env ) )) ; 
  (__funcarg57 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (sch_peek_string_bang , "peek-string!" , 2 , 5 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("peek-string!" , __funcarg57 , env ) )) ; 
  (__funcarg56 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (sch_read_bytes , "read-bytes" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-bytes" , __funcarg56 , env ) )) ; 
  (__funcarg55 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (sch_read_bytes_bang , "read-bytes!" , 1 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-bytes!" , __funcarg55 , env ) )) ; 
  (__funcarg54 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (sch_peek_bytes , "peek-bytes" , 2 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("peek-bytes" , __funcarg54 , env ) )) ; 
  (__funcarg53 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (sch_peek_bytes_bang , "peek-bytes!" , 2 , 5 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("peek-bytes!" , __funcarg53 , env ) )) ; 
  (__funcarg52 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (read_bytes_bang , "read-bytes-avail!" , 1 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-bytes-avail!" , __funcarg52 , env ) )) ; 
  (__funcarg51 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (read_bytes_bang_nonblock , "read-bytes-avail!*" , 1 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-bytes-avail!*" , __funcarg51 , env ) )) ; 
  (__funcarg50 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (read_bytes_bang_break , "read-bytes-avail!/enable-break" , 1 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("read-bytes-avail!/enable-break" , __funcarg50 , env ) )) ; 
  (__funcarg49 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (peek_bytes_bang , "peek-bytes-avail!" , 2 , 6 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("peek-bytes-avail!" , __funcarg49 , env ) )) ; 
  (__funcarg48 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (peek_bytes_bang_nonblock , "peek-bytes-avail!*" , 2 , 6 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("peek-bytes-avail!*" , __funcarg48 , env ) )) ; 
  (__funcarg47 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (peek_bytes_bang_break , "peek-bytes-avail!/enable-break" , 2 , 6 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("peek-bytes-avail!/enable-break" , __funcarg47 , env ) )) ; 
  (__funcarg46 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (can_provide_progress_evt , "port-provides-progress-evts?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("port-provides-progress-evts?" , __funcarg46 , env ) )) ; 
  (__funcarg45 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (write_bytes , "write-bytes" , 1 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("write-bytes" , __funcarg45 , env ) )) ; 
  (__funcarg44 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (write_string , "write-string" , 1 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("write-string" , __funcarg44 , env ) )) ; 
  (__funcarg43 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (write_bytes_avail , "write-bytes-avail" , 1 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("write-bytes-avail" , __funcarg43 , env ) )) ; 
  (__funcarg42 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (write_bytes_avail_nonblock , "write-bytes-avail*" , 1 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("write-bytes-avail*" , __funcarg42 , env ) )) ; 
  (__funcarg41 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (write_bytes_avail_break , "write-bytes-avail/enable-break" , 1 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("write-bytes-avail/enable-break" , __funcarg41 , env ) )) ; 
  (__funcarg40 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (can_write_atomic , "port-writes-atomic?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("port-writes-atomic?" , __funcarg40 , env ) )) ; 
  (__funcarg39 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (can_write_special , "port-writes-special?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("port-writes-special?" , __funcarg39 , env ) )) ; 
  (__funcarg38 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (scheme_write_special , "write-special" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("write-special" , __funcarg38 , env ) )) ; 
  (__funcarg37 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (scheme_write_special_nonblock , "write-special-avail*" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("write-special-avail*" , __funcarg37 , env ) )) ; 
  (__funcarg36 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (peek_char , "peek-char" , 0 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("peek-char" , __funcarg36 , env ) )) ; 
  (__funcarg35 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (peek_char_spec , "peek-char-or-special" , 0 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("peek-char-or-special" , __funcarg35 , env ) )) ; 
  (__funcarg34 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (peek_byte , "peek-byte" , 0 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("peek-byte" , __funcarg34 , env ) )) ; 
  (__funcarg33 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (peek_byte_spec , "peek-byte-or-special" , 0 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("peek-byte-or-special" , __funcarg33 , env ) )) ; 
  p = FUNCCALL_AGAIN(scheme_make_folding_prim (eof_object_p , "eof-object?" , 1 , 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 16384 ; 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("eof-object?" , p , env ) ); 
  (__funcarg32 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (byte_ready_p , "byte-ready?" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("byte-ready?" , __funcarg32 , env ) )) ; 
  (__funcarg31 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (char_ready_p , "char-ready?" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("char-ready?" , __funcarg31 , env ) )) ; 
  FUNCCALL_AGAIN(scheme_add_global_constant ("write" , scheme_write_proc , env ) ); 
  FUNCCALL_AGAIN(scheme_add_global_constant ("display" , scheme_display_proc , env ) ); 
  FUNCCALL_AGAIN(scheme_add_global_constant ("print" , scheme_print_proc , env ) ); 
  (__funcarg30 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (newline , "newline" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("newline" , __funcarg30 , env ) )) ; 
  (__funcarg29 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (write_char , "write-char" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("write-char" , __funcarg29 , env ) )) ; 
  (__funcarg28 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (write_byte , "write-byte" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("write-byte" , __funcarg28 , env ) )) ; 
  (__funcarg27 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (peeked_read , "port-commit-peeked" , 3 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("port-commit-peeked" , __funcarg27 , env ) )) ; 
  (__funcarg26 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (progress_evt , "port-progress-evt" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("port-progress-evt" , __funcarg26 , env ) )) ; 
  (__funcarg25 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (write_bytes_avail_evt , "write-bytes-avail-evt" , 1 , 4 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("write-bytes-avail-evt" , __funcarg25 , env ) )) ; 
  (__funcarg24 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (write_special_evt , "write-special-evt" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("write-special-evt" , __funcarg24 , env ) )) ; 
  (__funcarg23 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (port_read_handler , "port-read-handler" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("port-read-handler" , __funcarg23 , env ) )) ; 
  (__funcarg22 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (port_display_handler , "port-display-handler" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("port-display-handler" , __funcarg22 , env ) )) ; 
  (__funcarg21 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (port_write_handler , "port-write-handler" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("port-write-handler" , __funcarg21 , env ) )) ; 
  (__funcarg20 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (port_print_handler , "port-print-handler" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("port-print-handler" , __funcarg20 , env ) )) ; 
  (__funcarg19 = FUNCCALL(SETUP_XfOrM1(_), scheme_register_parameter (global_port_print_handler , "global-port-print-handler" , MZCONFIG_PORT_PRINT_HANDLER ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("global-port-print-handler" , __funcarg19 , env ) )) ; 
  (__funcarg18 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_everything (load , 0 , "load" , 1 , 1 , 0 , 0 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("load" , __funcarg18 , env ) )) ; 
  (__funcarg17 = FUNCCALL(SETUP_XfOrM1(_), scheme_register_parameter (current_load , "current-load" , MZCONFIG_LOAD_HANDLER ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-load" , __funcarg17 , env ) )) ; 
  (__funcarg16 = FUNCCALL(SETUP_XfOrM1(_), scheme_register_parameter (current_load_directory , "current-load-relative-directory" , MZCONFIG_LOAD_DIRECTORY ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-load-relative-directory" , __funcarg16 , env ) )) ; 
  (__funcarg15 = FUNCCALL(SETUP_XfOrM1(_), scheme_register_parameter (current_write_directory , "current-write-relative-directory" , MZCONFIG_WRITE_DIRECTORY ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-write-relative-directory" , __funcarg15 , env ) )) ; 
  (__funcarg14 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (transcript_on , "transcript-on" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("transcript-on" , __funcarg14 , env ) )) ; 
  (__funcarg13 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (transcript_off , "transcript-off" , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("transcript-off" , __funcarg13 , env ) )) ; 
  (__funcarg12 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (flush_output , "flush-output" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("flush-output" , __funcarg12 , env ) )) ; 
  (__funcarg11 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (scheme_file_position , "file-position" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("file-position" , __funcarg11 , env ) )) ; 
  (__funcarg10 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (scheme_file_buffer , "file-stream-buffer-mode" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("file-stream-buffer-mode" , __funcarg10 , env ) )) ; 
  (__funcarg9 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (scheme_file_identity , "port-file-identity" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("port-file-identity" , __funcarg9 , env ) )) ; 
  (__funcarg8 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_everything (sch_pipe , 0 , "make-pipe" , 0 , 3 , 0 , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-pipe" , __funcarg8 , env ) )) ; 
  (__funcarg7 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (pipe_length , "pipe-content-length" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("pipe-content-length" , __funcarg7 , env ) )) ; 
  (__funcarg6 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_noncm_prim (port_count_lines , "port-count-lines!" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("port-count-lines!" , __funcarg6 , env ) )) ; 
  (__funcarg5 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_everything (port_next_location , 0 , "port-next-location" , 1 , 1 , 0 , 3 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("port-next-location" , __funcarg5 , env ) )) ; 
  (__funcarg4 = FUNCCALL(SETUP_XfOrM1(_), scheme_register_parameter (global_port_count_lines , "port-count-lines-enabled" , MZCONFIG_PORT_COUNT_LINES ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("port-count-lines-enabled" , __funcarg4 , env ) )) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_init_port_fun_config (void ) {
  Scheme_Object * __funcarg101 = NULLED_OUT ; 
  Scheme_Object * __funcarg100 = NULLED_OUT ; 
  PREPARE_VAR_STACK(1);
# define XfOrM2_COUNT (0)
# define SETUP_XfOrM2(x) SETUP(XfOrM2_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  FUNCCALL(SETUP_XfOrM2(_), scheme_set_root_param (MZCONFIG_LOAD_DIRECTORY , scheme_false ) ); 
  FUNCCALL(SETUP_XfOrM2(_), scheme_set_root_param (MZCONFIG_WRITE_DIRECTORY , scheme_false ) ); 
  (__funcarg100 = (__funcarg101 = FUNCCALL(SETUP_XfOrM2(_), scheme_make_path ("compiled" ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (__funcarg101 , scheme_null ) )) , FUNCCALL_AGAIN(scheme_set_root_param (MZCONFIG_USE_COMPILED_KIND , __funcarg100 ) )) ; 
  FUNCCALL_AGAIN(scheme_set_root_param (MZCONFIG_USE_USER_PATHS , (scheme_ignore_user_paths ? scheme_false : scheme_true ) ) ); 
  {
    Scheme_Object * dlh ; 
    BLOCK_SETUP((PUSH(dlh, 0+XfOrM2_COUNT)));
#   define XfOrM3_COUNT (1+XfOrM2_COUNT)
#   define SETUP_XfOrM3(x) SETUP(XfOrM3_COUNT)
    dlh = NULLED_OUT ; 
    dlh = FUNCCALL(SETUP_XfOrM3(_), scheme_make_prim_w_everything (default_load , 0 , "default-load-handler" , 2 , 2 , 0 , 0 , - 1 ) ); 
    FUNCCALL_EMPTY(scheme_set_root_param (MZCONFIG_LOAD_HANDLER , dlh ) ); 
  }
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & scheme_default_global_print_handler , sizeof (scheme_default_global_print_handler ) ) ); 
  scheme_default_global_print_handler = FUNCCALL_EMPTY(scheme_make_prim_w_arity (sch_default_global_port_print_handler , "default-global-port-print-handler" , 2 , 2 ) ); 
  FUNCCALL_EMPTY(scheme_set_root_param (MZCONFIG_PORT_PRINT_HANDLER , scheme_default_global_print_handler ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Port * scheme_port_record (Scheme_Object * port ) {
  DECL_RET_SAVE (Scheme_Port * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(port, 0)));
# define XfOrM4_COUNT (1)
# define SETUP_XfOrM4(x) SETUP(XfOrM4_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if ((scheme_is_input_port (port ) ) )
    RET_VALUE_START ((Scheme_Port * ) FUNCCALL(SETUP_XfOrM4(_), scheme_input_port_record (port ) )) RET_VALUE_END ; 
  else RET_VALUE_START ((Scheme_Port * ) FUNCCALL_EMPTY(scheme_output_port_record (port ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline Scheme_Input_Port * input_port_record_slow (Scheme_Object * port ) {
  Scheme_Object * v ; 
  DECL_RET_SAVE (Scheme_Input_Port * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(port, 1)));
# define XfOrM5_COUNT (2)
# define SETUP_XfOrM5(x) SETUP(XfOrM5_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  while (1 ) {
#   define XfOrM11_COUNT (0+XfOrM5_COUNT)
#   define SETUP_XfOrM11(x) SETUP_XfOrM5(x)
    if (((Scheme_Type ) (((((long ) (port ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (port ) ) -> type ) ) == (Scheme_Type ) (scheme_input_port_type ) ) )
      RET_VALUE_START ((Scheme_Input_Port * ) port ) RET_VALUE_END ; 
    if (! (((Scheme_Type ) (((((long ) (port ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (port ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (port ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (port ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) ) {
#     define XfOrM14_COUNT (0+XfOrM11_COUNT)
#     define SETUP_XfOrM14(x) SETUP_XfOrM11(x)
      if (! dummy_input_port ) {
#       define XfOrM15_COUNT (0+XfOrM14_COUNT)
#       define SETUP_XfOrM15(x) SETUP_XfOrM14(x)
        FUNCCALL(SETUP_XfOrM15(_), scheme_register_static ((void * ) & dummy_input_port , sizeof (dummy_input_port ) ) ); 
        dummy_input_port = FUNCCALL(SETUP_XfOrM15(_), scheme_make_byte_string_input_port ("" ) ); 
      }
      RET_VALUE_START ((Scheme_Input_Port * ) dummy_input_port ) RET_VALUE_END ; 
    }
    v = (scheme_struct_type_property_ref (scheme_input_port_property , port ) ) ; 
    if (! v )
      v = scheme_false ; 
    else if ((((long ) (v ) ) & 0x1 ) )
      v = ((Scheme_Structure * ) port ) -> slots [(((long ) (v ) ) >> 1 ) ] ; 
    port = v ; 
    {
#     define XfOrM12_COUNT (0+XfOrM11_COUNT)
#     define SETUP_XfOrM12(x) SETUP_XfOrM11(x)
      if ((scheme_fuel_counter ) <= 0 ) {
#       define XfOrM13_COUNT (0+XfOrM12_COUNT)
#       define SETUP_XfOrM13(x) SETUP_XfOrM12(x)
        FUNCCALL(SETUP_XfOrM13(_), scheme_out_of_fuel () ); 
      }
    }
    ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Input_Port * scheme_input_port_record (Scheme_Object * port ) {
  /* No conversion */
  if (((Scheme_Type ) (((((long ) (port ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (port ) ) -> type ) ) == (Scheme_Type ) (scheme_input_port_type ) ) )
    return (Scheme_Input_Port * ) port ; 
  else return input_port_record_slow (port ) ; 
}
static inline Scheme_Output_Port * output_port_record_slow (Scheme_Object * port ) {
  Scheme_Object * v ; 
  DECL_RET_SAVE (Scheme_Output_Port * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(port, 1)));
# define XfOrM17_COUNT (2)
# define SETUP_XfOrM17(x) SETUP(XfOrM17_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  while (1 ) {
#   define XfOrM23_COUNT (0+XfOrM17_COUNT)
#   define SETUP_XfOrM23(x) SETUP_XfOrM17(x)
    if (((Scheme_Type ) (((((long ) (port ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (port ) ) -> type ) ) == (Scheme_Type ) (scheme_output_port_type ) ) )
      RET_VALUE_START ((Scheme_Output_Port * ) port ) RET_VALUE_END ; 
    if (! (((Scheme_Type ) (((((long ) (port ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (port ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (port ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (port ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) ) {
#     define XfOrM26_COUNT (0+XfOrM23_COUNT)
#     define SETUP_XfOrM26(x) SETUP_XfOrM23(x)
      if (! dummy_output_port ) {
#       define XfOrM27_COUNT (0+XfOrM26_COUNT)
#       define SETUP_XfOrM27(x) SETUP_XfOrM26(x)
        FUNCCALL(SETUP_XfOrM27(_), scheme_register_static ((void * ) & dummy_output_port , sizeof (dummy_output_port ) ) ); 
        dummy_output_port = FUNCCALL(SETUP_XfOrM27(_), scheme_make_null_output_port (1 ) ); 
      }
      RET_VALUE_START ((Scheme_Output_Port * ) dummy_output_port ) RET_VALUE_END ; 
    }
    v = (scheme_struct_type_property_ref (scheme_output_port_property , port ) ) ; 
    if (! v )
      v = scheme_false ; 
    else if ((((long ) (v ) ) & 0x1 ) )
      v = ((Scheme_Structure * ) port ) -> slots [(((long ) (v ) ) >> 1 ) ] ; 
    port = v ; 
    {
#     define XfOrM24_COUNT (0+XfOrM23_COUNT)
#     define SETUP_XfOrM24(x) SETUP_XfOrM23(x)
      if ((scheme_fuel_counter ) <= 0 ) {
#       define XfOrM25_COUNT (0+XfOrM24_COUNT)
#       define SETUP_XfOrM25(x) SETUP_XfOrM24(x)
        FUNCCALL(SETUP_XfOrM25(_), scheme_out_of_fuel () ); 
      }
    }
    ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Output_Port * scheme_output_port_record (Scheme_Object * port ) {
  /* No conversion */
  if (((Scheme_Type ) (((((long ) (port ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (port ) ) -> type ) ) == (Scheme_Type ) (scheme_output_port_type ) ) )
    return (Scheme_Output_Port * ) port ; 
  else return output_port_record_slow (port ) ; 
}
int scheme_is_input_port (Scheme_Object * port ) {
  /* No conversion */
  if (((Scheme_Type ) (((((long ) (port ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (port ) ) -> type ) ) == (Scheme_Type ) (scheme_input_port_type ) ) )
    return 1 ; 
  if ((((Scheme_Type ) (((((long ) (port ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (port ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (port ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (port ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) )
    if (scheme_struct_type_property_ref (scheme_input_port_property , port ) )
    return 1 ; 
  return 0 ; 
}
int scheme_is_output_port (Scheme_Object * port ) {
  /* No conversion */
  if (((Scheme_Type ) (((((long ) (port ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (port ) ) -> type ) ) == (Scheme_Type ) (scheme_output_port_type ) ) )
    return 1 ; 
  if ((((Scheme_Type ) (((((long ) (port ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (port ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (port ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (port ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) )
    if (scheme_struct_type_property_ref (scheme_output_port_property , port ) )
    return 1 ; 
  return 0 ; 
}
/* this far 922 */
static long string_get_or_peek_bytes (Scheme_Input_Port * port , char * buffer , long offset , long size , int peek , long skip , Scheme_Object * unless ) {
  /* No conversion */
  Scheme_Indexed_String * is ; 
  if (unless && scheme_unless_ready (unless ) )
    return (- 3 ) ; 
  is = (Scheme_Indexed_String * ) port -> port_data ; 
  if (is -> index + skip >= is -> size )
    return (- 1 ) ; 
  else if (size == 1 ) {
    int pos = is -> index ; 
    if (buffer )
      buffer [offset ] = is -> string [pos + skip ] ; 
    if (! peek )
      is -> index = pos + 1 ; 
    return 1 ; 
  }
  else {
    long l , delta ; 
    delta = is -> index + skip ; 
    if (delta + size <= is -> size )
      l = size ; 
    else l = (is -> size - delta ) ; 
    if (buffer )
      memcpy (buffer + offset , is -> string + delta , l ) ; 
    if (! peek )
      is -> index += l ; 
    return l ; 
  }
}
static long string_get_bytes (Scheme_Input_Port * port , char * buffer , long offset , long size , int nonblock , Scheme_Object * unless ) {
  /* No conversion */
  return string_get_or_peek_bytes (port , buffer , offset , size , 0 , 0 , unless ) ; 
}
static long string_peek_bytes (Scheme_Input_Port * port , char * buffer , long offset , long size , Scheme_Object * sskip , int nonblock , Scheme_Object * unless ) {
  /* No conversion */
  long skip ; 
  if ((((long ) (sskip ) ) & 0x1 ) )
    skip = (((long ) (sskip ) ) >> 1 ) ; 
  else skip = ((Scheme_Indexed_String * ) port -> port_data ) -> size ; 
  return string_get_or_peek_bytes (port , buffer , offset , size , 1 , skip , unless ) ; 
}
static int string_byte_ready (Scheme_Input_Port * port ) {
  /* No conversion */
  return 1 ; 
}
static void string_close_in (Scheme_Input_Port * port ) {
  /* No conversion */
}
static Scheme_Indexed_String * make_indexed_string (const char * str , long len ) {
  Scheme_Indexed_String * is ; 
  DECL_RET_SAVE (Scheme_Indexed_String * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(str, 0), PUSH(is, 1)));
# define XfOrM38_COUNT (2)
# define SETUP_XfOrM38(x) SETUP(XfOrM38_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  is = NULLED_OUT ; 
  is = ((Scheme_Indexed_String * ) FUNCCALL(SETUP_XfOrM38(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Indexed_String ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  is -> type = scheme_rt_indexed_string ; 
  if (str ) {
#   define XfOrM40_COUNT (0+XfOrM38_COUNT)
#   define SETUP_XfOrM40(x) SETUP_XfOrM38(x)
    if (len < 0 ) {
      is -> string = (char * ) str ; 
      is -> size = - len ; 
    }
    else {
      char * ca ; 
      BLOCK_SETUP((PUSH(ca, 0+XfOrM40_COUNT)));
#     define XfOrM41_COUNT (1+XfOrM40_COUNT)
#     define SETUP_XfOrM41(x) SETUP(XfOrM41_COUNT)
      ca = NULLED_OUT ; 
      ca = (char * ) FUNCCALL(SETUP_XfOrM41(_), GC_malloc_atomic (len ) ); 
      is -> string = ca ; 
      (memcpy (is -> string , str , len ) ) ; 
      is -> size = len ; 
    }
  }
  else {
    char * ca ; 
    BLOCK_SETUP((PUSH(ca, 0+XfOrM38_COUNT)));
#   define XfOrM39_COUNT (1+XfOrM38_COUNT)
#   define SETUP_XfOrM39(x) SETUP(XfOrM39_COUNT)
    ca = NULLED_OUT ; 
    is -> size = 100 ; 
    ca = (char * ) FUNCCALL(SETUP_XfOrM39(_), GC_malloc_atomic (is -> size + 1 ) ); 
    is -> string = ca ; 
  }
  is -> index = 0 ; 
  RET_VALUE_START ((is ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_sized_byte_string_input_port (const char * str , long len ) {
  Scheme_Input_Port * ip ; 
  Scheme_Object * __funcarg103 = NULLED_OUT ; 
  Scheme_Indexed_String * __funcarg102 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(ip, 0), PUSH(__funcarg102, 1)));
# define XfOrM43_COUNT (2)
# define SETUP_XfOrM43(x) SETUP(XfOrM43_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ip = NULLED_OUT ; 
  ip = (__funcarg102 = FUNCCALL(SETUP_XfOrM43(_), make_indexed_string (str , len ) ), __funcarg103 = FUNCCALL(SETUP_XfOrM43(_), scheme_intern_symbol ("string" ) ), FUNCCALL_AGAIN(scheme_make_input_port (scheme_string_input_port_type , __funcarg102 , __funcarg103 , string_get_bytes , string_peek_bytes , scheme_progress_evt_via_get , scheme_peeked_read_via_get , string_byte_ready , string_close_in , ((void * ) 0 ) , 0 ) )) ; 
  RET_VALUE_START ((Scheme_Object * ) ip ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_byte_string_input_port (const char * str ) {
  /* No conversion */
  return scheme_make_sized_byte_string_input_port (str , strlen (str ) ) ; 
}
static long string_write_bytes (Scheme_Output_Port * port , const char * str , long d , long len , int rarely_block , int enable_break ) {
  Scheme_Indexed_String * is ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(str, 0), PUSH(is, 1)));
# define XfOrM45_COUNT (2)
# define SETUP_XfOrM45(x) SETUP(XfOrM45_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  is = NULLED_OUT ; 
  is = (Scheme_Indexed_String * ) port -> port_data ; 
  if (is -> index + len >= is -> size ) {
    char * old ; 
    BLOCK_SETUP((PUSH(old, 0+XfOrM45_COUNT)));
#   define XfOrM46_COUNT (1+XfOrM45_COUNT)
#   define SETUP_XfOrM46(x) SETUP(XfOrM46_COUNT)
    old = NULLED_OUT ; 
    old = is -> string ; 
    if (len > is -> size )
      is -> size += 2 * len ; 
    else is -> size *= 2 ; 
    {
      char * ca ; 
      BLOCK_SETUP((PUSH(ca, 0+XfOrM46_COUNT)));
#     define XfOrM47_COUNT (1+XfOrM46_COUNT)
#     define SETUP_XfOrM47(x) SETUP(XfOrM47_COUNT)
      ca = NULLED_OUT ; 
      ca = (char * ) FUNCCALL(SETUP_XfOrM47(_), GC_malloc_atomic (is -> size + 1 ) ); 
      is -> string = ca ; 
    }
    (memcpy (is -> string , old , is -> index ) ) ; 
  }
  (memcpy (is -> string + is -> index , str + d , len ) ) ; 
  is -> index += len ; 
  RET_VALUE_START (len ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void string_close_out (Scheme_Output_Port * port ) {
  /* No conversion */
  return ; 
}
Scheme_Object * scheme_make_byte_string_output_port (void ) {
  Scheme_Output_Port * op ; 
  Scheme_Object * __funcarg105 = NULLED_OUT ; 
  Scheme_Indexed_String * __funcarg104 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(__funcarg104, 0), PUSH(op, 1)));
# define XfOrM49_COUNT (2)
# define SETUP_XfOrM49(x) SETUP(XfOrM49_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  op = NULLED_OUT ; 
  op = (__funcarg104 = FUNCCALL(SETUP_XfOrM49(_), make_indexed_string (((void * ) 0 ) , 0 ) ), __funcarg105 = FUNCCALL(SETUP_XfOrM49(_), scheme_intern_symbol ("string" ) ), FUNCCALL_AGAIN(scheme_make_output_port (scheme_string_output_port_type , __funcarg104 , __funcarg105 , scheme_write_evt_via_write , string_write_bytes , ((void * ) 0 ) , string_close_out , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) )) ; 
  RET_VALUE_START ((Scheme_Object * ) op ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 1126 */
char * scheme_get_reset_sized_byte_string_output (Scheme_Object * port , long * size , int reset , long startpos , long endpos ) {
  Scheme_Output_Port * op ; 
  Scheme_Indexed_String * is ; 
  char * v ; 
  long len ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(size, 0), PUSH(op, 1), PUSH(is, 2), PUSH(v, 3)));
# define XfOrM50_COUNT (4)
# define SETUP_XfOrM50(x) SETUP(XfOrM50_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  op = NULLED_OUT ; 
  is = NULLED_OUT ; 
  v = NULLED_OUT ; 
  if (! (scheme_is_output_port (port ) ) )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  op = FUNCCALL(SETUP_XfOrM50(_), scheme_output_port_record (port ) ); 
  if (op -> sub_type != scheme_string_output_port_type )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  is = (Scheme_Indexed_String * ) op -> port_data ; 
  len = is -> index ; 
  if (is -> u . hot > len )
    len = is -> u . hot ; 
  if (endpos < 0 )
    endpos = len ; 
  if (reset ) {
    char * ca ; 
    BLOCK_SETUP((PUSH(ca, 0+XfOrM50_COUNT)));
#   define XfOrM52_COUNT (1+XfOrM50_COUNT)
#   define SETUP_XfOrM52(x) SETUP(XfOrM52_COUNT)
    ca = NULLED_OUT ; 
    v = is -> string ; 
    is -> size = 31 ; 
    ca = (char * ) FUNCCALL(SETUP_XfOrM52(_), GC_malloc_atomic ((is -> size ) + 1 ) ); 
    is -> string = ca ; 
    is -> index = 0 ; 
    is -> u . hot = 0 ; 
    if ((startpos > 0 ) || (endpos < len ) ) {
#     define XfOrM53_COUNT (0+XfOrM52_COUNT)
#     define SETUP_XfOrM53(x) SETUP_XfOrM52(x)
      len = endpos - startpos ; 
      ca = (char * ) FUNCCALL(SETUP_XfOrM53(_), GC_malloc_atomic (len + 1 ) ); 
      (memcpy (ca , v XFORM_OK_PLUS startpos , len ) ) ; 
      v = ca ; 
    }
  }
  else {
#   define XfOrM51_COUNT (0+XfOrM50_COUNT)
#   define SETUP_XfOrM51(x) SETUP_XfOrM50(x)
    len = endpos - startpos ; 
    v = (char * ) FUNCCALL(SETUP_XfOrM51(_), GC_malloc_atomic (len + 1 ) ); 
    (memcpy (v , is -> string XFORM_OK_PLUS startpos , len ) ) ; 
  }
  v [len ] = 0 ; 
  if (size )
    * size = len ; 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
char * scheme_get_sized_byte_string_output (Scheme_Object * port , long * size ) {
  /* No conversion */
  return scheme_get_reset_sized_byte_string_output (port , size , 0 , 0 , - 1 ) ; 
}
char * scheme_get_string_output (Scheme_Object * port ) {
  /* No conversion */
  return scheme_get_sized_byte_string_output (port , ((void * ) 0 ) ) ; 
}
typedef struct User_Input_Port {
  Scheme_Type type ; 
  Scheme_Object * evt ; 
  Scheme_Object * read_proc ; 
  Scheme_Object * peek_proc ; 
  Scheme_Object * close_proc ; 
  Scheme_Object * progress_evt_proc ; 
  Scheme_Object * peeked_read_proc ; 
  Scheme_Object * location_proc ; 
  Scheme_Object * count_lines_proc ; 
  Scheme_Object * buffer_mode_proc ; 
  Scheme_Object * reuse_str ; 
  Scheme_Object * peeked ; 
}
User_Input_Port ; 
static long user_read_result (const char * who , Scheme_Input_Port * port , Scheme_Object * val , Scheme_Object * bstr , int peek , int nonblock , int evt_ok , int special_ok , int false_ok , Scheme_Schedule_Info * sinfo ) {
  Scheme_Object * a [2 ] ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK(9);
  BLOCK_SETUP_TOP((PUSH(sinfo, 0), PUSH(val, 1), PUSHARRAY(a, 2, 2), PUSH(who, 5), PUSH(bstr, 6), PUSH(port, 7)));
# define XfOrM56_COUNT (8)
# define SETUP_XfOrM56(x) SETUP(XfOrM56_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  val_again : if ((((val ) ) == (scheme_eof ) ) )
    RET_VALUE_START ((- 1 ) ) RET_VALUE_END ; 
  else {
    int n ; 
#   define XfOrM57_COUNT (0+XfOrM56_COUNT)
#   define SETUP_XfOrM57(x) SETUP_XfOrM56(x)
    if (! (((long ) (val ) ) & 0x1 ) || ((((long ) (val ) ) >> 1 ) < 0 ) ) {
#     define XfOrM59_COUNT (0+XfOrM57_COUNT)
#     define SETUP_XfOrM59(x) SETUP_XfOrM57(x)
      a [0 ] = val ; 
      if (((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) && ((& ((Scheme_Bignum * ) val ) -> iso ) -> so . keyex & 0x1 ) ) {
        n = - 1 ; 
      }
      else if (peek && (((val ) ) == (scheme_false ) ) ) {
#       define XfOrM71_COUNT (0+XfOrM59_COUNT)
#       define SETUP_XfOrM71(x) SETUP_XfOrM59(x)
        if (false_ok )
          RET_VALUE_START ((- 3 ) ) RET_VALUE_END ; 
        FUNCCALL(SETUP_XfOrM71(_), scheme_arg_mismatch (who , "returned #f when no progress evt was supplied: " , val ) ); 
        RET_VALUE_START (0 ) RET_VALUE_END ; 
      }
      else if ((! (((long ) (val ) ) & 0x1 ) && ((((val ) -> type ) >= scheme_prim_type ) && (((val ) -> type ) <= scheme_native_closure_type ) ) ) ) {
        Scheme_Object * orig = val ; 
        BLOCK_SETUP((PUSH(orig, 0+XfOrM59_COUNT)));
#       define XfOrM68_COUNT (1+XfOrM59_COUNT)
#       define SETUP_XfOrM68(x) SETUP(XfOrM68_COUNT)
        a [0 ] = val ; 
        if (FUNCCALL(SETUP_XfOrM68(_), scheme_check_proc_arity (((void * ) 0 ) , 4 , 0 , 1 , a ) )) {
#         define XfOrM69_COUNT (0+XfOrM68_COUNT)
#         define SETUP_XfOrM69(x) SETUP_XfOrM68(x)
          if (! special_ok ) {
#           define XfOrM70_COUNT (0+XfOrM69_COUNT)
#           define SETUP_XfOrM70(x) SETUP_XfOrM69(x)
            FUNCCALL(SETUP_XfOrM70(_), scheme_arg_mismatch (who , "the port has no specific peek procedure, so" " a special read result is not allowed: " , orig ) ); 
            RET_VALUE_START (0 ) RET_VALUE_END ; 
          }
          port -> special = a [0 ] ; 
          RET_VALUE_START ((- 2 ) ) RET_VALUE_END ; 
        }
        else val = ((void * ) 0 ) ; 
        n = 0 ; 
      }
      else if (evt_ok && FUNCCALL(SETUP_XfOrM59(_), scheme_is_evt (val ) )) {
#       define XfOrM62_COUNT (0+XfOrM59_COUNT)
#       define SETUP_XfOrM62(x) SETUP_XfOrM59(x)
        if (nonblock > 0 ) {
#         define XfOrM65_COUNT (0+XfOrM62_COUNT)
#         define SETUP_XfOrM65(x) SETUP_XfOrM62(x)
          if (sinfo ) {
#           define XfOrM67_COUNT (0+XfOrM65_COUNT)
#           define SETUP_XfOrM67(x) SETUP_XfOrM65(x)
            FUNCCALL(SETUP_XfOrM67(_), scheme_set_sync_target (sinfo , val , (Scheme_Object * ) port , ((void * ) 0 ) , 0 , 1 ) ); 
            RET_VALUE_START (0 ) RET_VALUE_END ; 
          }
          else {
#           define XfOrM66_COUNT (0+XfOrM65_COUNT)
#           define SETUP_XfOrM66(x) SETUP_XfOrM65(x)
            a [0 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
            a [1 ] = val ; 
            val = FUNCCALL(SETUP_XfOrM66(_), scheme_sync_timeout (2 , a ) ); 
            if (! val )
              RET_VALUE_START (0 ) RET_VALUE_END ; 
            else if (FUNCCALL(SETUP_XfOrM66(_), scheme_is_evt (val ) ))
              RET_VALUE_START (0 ) RET_VALUE_END ; 
            goto val_again ; 
          }
        }
        else {
#         define XfOrM63_COUNT (0+XfOrM62_COUNT)
#         define SETUP_XfOrM63(x) SETUP_XfOrM62(x)
          a [0 ] = val ; 
          if (nonblock < 0 )
            val = FUNCCALL(SETUP_XfOrM63(_), scheme_sync_enable_break (1 , a ) ); 
          else val = FUNCCALL(SETUP_XfOrM63(_), scheme_sync (1 , a ) ); 
          if (port -> closed ) {
#           define XfOrM64_COUNT (0+XfOrM63_COUNT)
#           define SETUP_XfOrM64(x) SETUP_XfOrM63(x)
            if (peek )
              FUNCCALL(SETUP_XfOrM64(_), scheme_peek_byte ((Scheme_Object * ) port ) ); 
            else FUNCCALL(SETUP_XfOrM64(_), scheme_get_byte ((Scheme_Object * ) port ) ); 
            RET_VALUE_START (0 ) RET_VALUE_END ; 
          }
          goto val_again ; 
        }
      }
      else {
        val = ((void * ) 0 ) ; 
        n = 0 ; 
      }
      if (! val ) {
#       define XfOrM60_COUNT (0+XfOrM59_COUNT)
#       define SETUP_XfOrM60(x) SETUP_XfOrM59(x)
        FUNCCALL(SETUP_XfOrM60(_), scheme_wrong_type (who , (peek ? (evt_ok ? (special_ok ? "non-negative exact integer, eof, evt, #f, or procedure for special" : "non-negative exact integer, eof, evt, or #f" ) : "non-negative exact integer, eof, #f, or procedure for special" ) : (evt_ok ? (special_ok ? "non-negative exact integer, eof, evt, or procedure for special" : "non-negative exact integer, eof, or evt" ) : "non-negative exact integer, eof, or procedure for special" ) ) , - 1 , - 1 , a ) ); 
        RET_VALUE_START (0 ) RET_VALUE_END ; 
      }
    }
    else n = (((long ) (val ) ) >> 1 ) ; 
    if ((n < 0 ) || (n > (((Scheme_Simple_Object * ) (bstr ) ) -> u . byte_str_val . tag_val ) ) ) {
#     define XfOrM58_COUNT (0+XfOrM57_COUNT)
#     define SETUP_XfOrM58(x) SETUP_XfOrM57(x)
      FUNCCALL(SETUP_XfOrM58(_), scheme_arg_mismatch (who , "result integer is larger than the supplied string: " , val ) ); 
    }
    RET_VALUE_START (n ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static long user_get_or_peek_bytes (Scheme_Input_Port * port , char * buffer , long offset , long size , int nonblock , int peek , Scheme_Object * peek_skip , Scheme_Object * unless , Scheme_Schedule_Info * sinfo ) {
  Scheme_Object * fun , * val , * a [3 ] , * bstr ; 
  User_Input_Port * uip = (User_Input_Port * ) port -> port_data ; 
  long r ; 
  Scheme_Cont_Frame_Data cframe ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK(14);
  BLOCK_SETUP_TOP((PUSH(uip, 0), PUSHARRAY(a, 3, 1), PUSH(cframe.cache, 4), PUSH(port, 5), PUSH(unless, 6), PUSH(sinfo, 7), PUSH(val, 8), PUSH(peek_skip, 9), PUSH(bstr, 10), PUSH(buffer, 11), PUSH(fun, 12)));
# define XfOrM73_COUNT (13)
# define SETUP_XfOrM73(x) SETUP(XfOrM73_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  fun = NULLED_OUT ; 
  val = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  a[2] = NULLED_OUT ; 
  bstr = NULLED_OUT ; 
  cframe.cache = NULLED_OUT ; 
  val = uip -> peeked ; 
  if (val ) {
    uip -> peeked = ((void * ) 0 ) ; 
    if ((((long ) (val ) ) & 0x1 ) ) {
      buffer [offset ] = (char ) (((long ) (val ) ) >> 1 ) ; 
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
    else if ((((val ) ) == (scheme_void ) ) ) {
      RET_VALUE_START ((- 2 ) ) RET_VALUE_END ; 
    }
    else RET_VALUE_START ((- 1 ) ) RET_VALUE_END ; 
  }
  if (unless && ((Scheme_Type ) (((((long ) (unless ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (unless ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) )
    unless = (((Scheme_Simple_Object * ) (unless ) ) -> u . pair_val . cdr ) ; 
  if (peek )
    fun = uip -> peek_proc ; 
  else fun = uip -> read_proc ; 
  while (1 ) {
    int nb ; 
#   define XfOrM83_COUNT (0+XfOrM73_COUNT)
#   define SETUP_XfOrM83(x) SETUP_XfOrM73(x)
    if (uip -> reuse_str && (size == (((Scheme_Simple_Object * ) (uip -> reuse_str ) ) -> u . byte_str_val . tag_val ) ) ) {
      bstr = uip -> reuse_str ; 
      uip -> reuse_str = ((void * ) 0 ) ; 
    }
    else {
      char * vb ; 
      BLOCK_SETUP((PUSH(vb, 0+XfOrM83_COUNT)));
#     define XfOrM90_COUNT (1+XfOrM83_COUNT)
#     define SETUP_XfOrM90(x) SETUP(XfOrM90_COUNT)
      vb = NULLED_OUT ; 
      vb = FUNCCALL(SETUP_XfOrM90(_), GC_malloc_atomic (size + 1 ) ); 
      bstr = FUNCCALL_AGAIN(scheme_make_sized_byte_string (vb , size , 0 ) ); 
    }
    a [0 ] = bstr ; 
    a [1 ] = peek_skip ; 
    a [2 ] = unless ? unless : scheme_false ; 
    nb = nonblock ; 
    if (! nb ) {
#     define XfOrM88_COUNT (0+XfOrM83_COUNT)
#     define SETUP_XfOrM88(x) SETUP_XfOrM83(x)
      if (FUNCCALL(SETUP_XfOrM88(_), scheme_can_break (scheme_current_thread ) )) {
        nb = - 1 ; 
      }
    }
    FUNCCALL(SETUP_XfOrM83(_), scheme_push_break_enable (& cframe , 0 , 0 ) ); 
    val = FUNCCALL(SETUP_XfOrM83(_), scheme_apply (fun , peek ? 3 : 1 , a ) ); 
    if ((size <= 1024 ) && ((((long ) (val ) ) & 0x1 ) || (((val ) ) == (scheme_eof ) ) || (! (((long ) (val ) ) & 0x1 ) && ((((val ) -> type ) >= scheme_prim_type ) && (((val ) -> type ) <= scheme_native_closure_type ) ) ) ) ) {
      uip -> reuse_str = bstr ; 
    }
    r = FUNCCALL(SETUP_XfOrM83(_), user_read_result (peek ? "user port peek" : "user port read" , port , val , bstr , peek , nb , 1 , ! ! uip -> peek_proc , ! ! unless , sinfo ) ); 
    FUNCCALL(SETUP_XfOrM83(_), scheme_pop_break_enable (& cframe , 1 ) ); 
    if (r > 0 ) {
#     define XfOrM86_COUNT (0+XfOrM83_COUNT)
#     define SETUP_XfOrM86(x) SETUP_XfOrM83(x)
      (memcpy (buffer + offset , (((Scheme_Simple_Object * ) (bstr ) ) -> u . byte_str_val . string_val ) , r ) ) ; 
      RET_VALUE_START (r ) RET_VALUE_END ; 
    }
    else if (r ) {
      RET_VALUE_START (r ) RET_VALUE_END ; 
    }
    FUNCCALL(SETUP_XfOrM83(_), scheme_thread_block_enable_break (0.0 , nonblock < 0 ) ); 
    scheme_current_thread -> ran_some = 1 ; 
    if (nonblock > 0 ) {
      if (sinfo )
        sinfo -> spin = 1 ; 
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static long user_get_bytes (Scheme_Input_Port * port , char * buffer , long offset , long size , int nonblock , Scheme_Object * unless ) {
  /* No conversion */
  return user_get_or_peek_bytes (port , buffer , offset , size , nonblock , 0 , ((void * ) 0 ) , unless , ((void * ) 0 ) ) ; 
}
static long user_peek_bytes (Scheme_Input_Port * port , char * buffer , long offset , long size , Scheme_Object * skip , int nonblock , Scheme_Object * unless ) {
  /* No conversion */
  return user_get_or_peek_bytes (port , buffer , offset , size , nonblock , 1 , skip , unless , ((void * ) 0 ) ) ; 
}
static int user_peeked_read (Scheme_Input_Port * port , long size , Scheme_Object * unless_evt , Scheme_Object * target_evt ) {
  User_Input_Port * uip = (User_Input_Port * ) port -> port_data ; 
  Scheme_Object * val , * a [3 ] ; 
  Scheme_Cont_Frame_Data cframe ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(val, 0), PUSH(uip, 1), PUSHARRAY(a, 3, 2), PUSH(cframe.cache, 5)));
# define XfOrM97_COUNT (6)
# define SETUP_XfOrM97(x) SETUP(XfOrM97_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  val = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  a[2] = NULLED_OUT ; 
  cframe.cache = NULLED_OUT ; 
  a [0 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (size ) ) << 1 ) | 0x1 ) ) ; 
  a [1 ] = unless_evt ; 
  a [2 ] = target_evt ; 
  FUNCCALL(SETUP_XfOrM97(_), scheme_push_break_enable (& cframe , 0 , 0 ) ); 
  val = FUNCCALL_AGAIN(scheme_apply (uip -> peeked_read_proc , 3 , a ) ); 
  FUNCCALL_AGAIN(scheme_pop_break_enable (& cframe , 1 ) ); 
  RET_VALUE_START ((! (((val ) ) == (scheme_false ) ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * user_progress_evt (Scheme_Input_Port * port ) {
  User_Input_Port * uip = (User_Input_Port * ) port -> port_data ; 
  Scheme_Object * evt , * a [1 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 1, 0), PUSH(evt, 3)));
# define XfOrM98_COUNT (4)
# define SETUP_XfOrM98(x) SETUP(XfOrM98_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  evt = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  evt = FUNCCALL(SETUP_XfOrM98(_), scheme_do_eval (uip -> progress_evt_proc , 0 , ((void * ) 0 ) , 1 ) ); 
  if (! FUNCCALL(SETUP_XfOrM98(_), scheme_is_evt (evt ) )) {
#   define XfOrM99_COUNT (0+XfOrM98_COUNT)
#   define SETUP_XfOrM99(x) SETUP_XfOrM98(x)
    a [0 ] = evt ; 
    FUNCCALL(SETUP_XfOrM99(_), scheme_wrong_type ("user port progress-evt" , "evt" , - 1 , - 1 , a ) ); 
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  RET_VALUE_START (evt ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int user_byte_ready_sinfo (Scheme_Input_Port * port , Scheme_Schedule_Info * sinfo ) {
  int c , can_peek ; 
  char s [1 ] ; 
  User_Input_Port * uip = (User_Input_Port * ) port -> port_data ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(uip, 0)));
# define XfOrM100_COUNT (1)
# define SETUP_XfOrM100(x) SETUP(XfOrM100_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  can_peek = (uip -> peek_proc ? 1 : 0 ) ; 
  c = FUNCCALL(SETUP_XfOrM100(_), user_get_or_peek_bytes (port , s , 0 , 1 , 1 , can_peek , ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) , ((void * ) 0 ) , sinfo ) ); 
  if (c == (- 1 ) ) {
    if (! can_peek )
      uip -> peeked = scheme_true ; 
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  }
  else if (c ) {
    if (! can_peek ) {
      if (c == (- 2 ) )
        uip -> peeked = scheme_void ; 
      else uip -> peeked = ((Scheme_Object * ) (void * ) (long ) ((((long ) (s [0 ] ) ) << 1 ) | 0x1 ) ) ; 
    }
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int user_byte_ready (Scheme_Input_Port * port ) {
  /* No conversion */
  return user_byte_ready_sinfo (port , ((void * ) 0 ) ) ; 
}
int scheme_user_port_byte_probably_ready (Scheme_Input_Port * ip , Scheme_Schedule_Info * sinfo ) {
  /* No conversion */
  User_Input_Port * uip = (User_Input_Port * ) ip -> port_data ; 
  if (uip -> peeked )
    return 1 ; 
  if (sinfo -> false_positive_ok ) {
    sinfo -> potentially_false_positive = 1 ; 
    return 1 ; 
  }
  else {
    return user_byte_ready_sinfo (ip , sinfo ) ; 
  }
}
static void user_needs_wakeup_input (Scheme_Input_Port * port , void * fds ) {
  /* No conversion */
}
static void user_close_input (Scheme_Input_Port * port ) {
  /* No conversion */
  User_Input_Port * uip = (User_Input_Port * ) port -> port_data ; 
  scheme_apply_multi (uip -> close_proc , 0 , ((void * ) 0 ) ) ; 
}
static Scheme_Object * user_input_location (Scheme_Port * p ) {
  /* No conversion */
  Scheme_Input_Port * ip = (Scheme_Input_Port * ) p ; 
  User_Input_Port * uip = (User_Input_Port * ) ip -> port_data ; 
  return scheme_apply_multi (uip -> location_proc , 0 , ((void * ) 0 ) ) ; 
}
static void user_input_count_lines (Scheme_Port * p ) {
  /* No conversion */
  Scheme_Input_Port * ip = (Scheme_Input_Port * ) p ; 
  User_Input_Port * uip = (User_Input_Port * ) ip -> port_data ; 
  scheme_apply_multi (uip -> count_lines_proc , 0 , ((void * ) 0 ) ) ; 
}
static int user_buffer_mode (Scheme_Object * buffer_mode_proc , int mode , int line_ok ) {
  Scheme_Object * v , * a [1 ] ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSHARRAY(a, 1, 1), PUSH(buffer_mode_proc, 4)));
# define XfOrM112_COUNT (5)
# define SETUP_XfOrM112(x) SETUP(XfOrM112_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  if (mode < 0 ) {
#   define XfOrM115_COUNT (0+XfOrM112_COUNT)
#   define SETUP_XfOrM115(x) SETUP_XfOrM112(x)
    v = FUNCCALL(SETUP_XfOrM115(_), scheme_apply (buffer_mode_proc , 0 , ((void * ) 0 ) ) ); 
    if ((! (((v ) ) == (scheme_false ) ) ) ) {
#     define XfOrM116_COUNT (0+XfOrM115_COUNT)
#     define SETUP_XfOrM116(x) SETUP_XfOrM115(x)
      if (((v ) == (scheme_block_symbol ) ) )
        mode = 0 ; 
      else if (line_ok && ((v ) == (scheme_line_symbol ) ) )
        mode = 1 ; 
      else if (((v ) == (scheme_none_symbol ) ) )
        mode = 2 ; 
      else {
#       define XfOrM117_COUNT (0+XfOrM116_COUNT)
#       define SETUP_XfOrM117(x) SETUP_XfOrM116(x)
        a [0 ] = v ; 
        FUNCCALL(SETUP_XfOrM117(_), scheme_wrong_type ("user port buffer-mode" , line_ok ? "'block, 'line, 'none, or #f" : "'block, 'none, or #f" , - 1 , - 1 , a ) ); 
        RET_VALUE_START (0 ) RET_VALUE_END ; 
      }
    }
  }
  else {
#   define XfOrM113_COUNT (0+XfOrM112_COUNT)
#   define SETUP_XfOrM113(x) SETUP_XfOrM112(x)
    switch (mode ) {
      case 0 : a [0 ] = scheme_block_symbol ; 
      break ; 
      case 1 : a [0 ] = scheme_line_symbol ; 
      break ; 
      case 2 : a [0 ] = scheme_none_symbol ; 
      break ; 
    }
    FUNCCALL(SETUP_XfOrM113(_), scheme_apply_multi (buffer_mode_proc , 1 , a ) ); 
  }
  RET_VALUE_START (mode ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int user_input_buffer_mode (Scheme_Port * p , int mode ) {
  /* No conversion */
  Scheme_Input_Port * ip = (Scheme_Input_Port * ) p ; 
  User_Input_Port * uip = (User_Input_Port * ) ip -> port_data ; 
  return user_buffer_mode (uip -> buffer_mode_proc , mode , 0 ) ; 
}
typedef struct User_Output_Port {
  Scheme_Type type ; 
  Scheme_Object * evt ; 
  Scheme_Object * write_evt_proc ; 
  Scheme_Object * write_proc ; 
  Scheme_Object * flush_proc ; 
  Scheme_Object * close_proc ; 
  Scheme_Object * write_special_evt_proc ; 
  Scheme_Object * write_special_proc ; 
  Scheme_Object * location_proc ; 
  Scheme_Object * count_lines_proc ; 
  Scheme_Object * buffer_mode_proc ; 
}
User_Output_Port ; 
int scheme_user_port_write_probably_ready (Scheme_Output_Port * port , Scheme_Schedule_Info * sinfo ) {
  /* No conversion */
  Scheme_Object * val ; 
  User_Output_Port * uop = (User_Output_Port * ) port -> port_data ; 
  if (port -> closed )
    return 1 ; 
  val = uop -> evt ; 
  scheme_set_sync_target (sinfo , val , (Scheme_Object * ) port , ((void * ) 0 ) , 0 , 1 ) ; 
  return 0 ; 
}
static int user_write_ready (Scheme_Output_Port * port ) {
  /* No conversion */
  return 1 ; 
}
static long user_write_result (const char * who , Scheme_Output_Port * port , int evt_ok , Scheme_Object * val , int rarely_block , int enable_break , long len ) {
  Scheme_Object * p [2 ] ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(val, 0), PUSHARRAY(p, 2, 1), PUSH(who, 4), PUSH(port, 5)));
# define XfOrM121_COUNT (6)
# define SETUP_XfOrM121(x) SETUP(XfOrM121_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  p[0] = NULLED_OUT ; 
  p[1] = NULLED_OUT ; 
  while (1 ) {
#   define XfOrM132_COUNT (0+XfOrM121_COUNT)
#   define SETUP_XfOrM132(x) SETUP_XfOrM121(x)
    if ((((val ) ) == (scheme_false ) ) ) {
#     define XfOrM141_COUNT (0+XfOrM132_COUNT)
#     define SETUP_XfOrM141(x) SETUP_XfOrM132(x)
      if (! rarely_block )
        RET_VALUE_START (0 ) RET_VALUE_END ; 
      else if (rarely_block == 2 )
        RET_VALUE_START (- 1 ) RET_VALUE_END ; 
      else if (! evt_ok )
        FUNCCALL(SETUP_XfOrM141(_), scheme_arg_mismatch (who , "bad result for write event: " , val ) ); 
      else RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    else if ((((long ) (val ) ) & 0x1 ) && ((((long ) (val ) ) >> 1 ) >= 0 ) && ((((long ) (val ) ) >> 1 ) <= len ) ) {
      int n ; 
#     define XfOrM139_COUNT (0+XfOrM132_COUNT)
#     define SETUP_XfOrM139(x) SETUP_XfOrM132(x)
      n = (((long ) (val ) ) >> 1 ) ; 
      if (! n && len ) {
#       define XfOrM140_COUNT (0+XfOrM139_COUNT)
#       define SETUP_XfOrM140(x) SETUP_XfOrM139(x)
        FUNCCALL(SETUP_XfOrM140(_), scheme_arg_mismatch (who , (evt_ok ? "bad result for non-flush write: " : "bad result for non-flush write event: " ) , val ) ); 
      }
      if (! len && ! rarely_block )
        RET_VALUE_START (1 ) RET_VALUE_END ; 
      else RET_VALUE_START (n ) RET_VALUE_END ; 
    }
    else if (evt_ok && FUNCCALL(SETUP_XfOrM132(_), scheme_is_evt (val ) )) {
#     define XfOrM136_COUNT (0+XfOrM132_COUNT)
#     define SETUP_XfOrM136(x) SETUP_XfOrM132(x)
      if (rarely_block == 2 ) {
        RET_VALUE_START (0 ) RET_VALUE_END ; 
      }
      else {
#       define XfOrM137_COUNT (0+XfOrM136_COUNT)
#       define SETUP_XfOrM137(x) SETUP_XfOrM136(x)
        p [0 ] = val ; 
        if (enable_break )
          val = FUNCCALL(SETUP_XfOrM137(_), scheme_sync_enable_break (1 , p ) ); 
        else val = FUNCCALL(SETUP_XfOrM137(_), scheme_sync (1 , p ) ); 
        if (port -> closed )
          RET_VALUE_START (0 ) RET_VALUE_END ; 
      }
    }
    else {
#     define XfOrM133_COUNT (0+XfOrM132_COUNT)
#     define SETUP_XfOrM133(x) SETUP_XfOrM132(x)
      if (((((long ) (val ) ) & 0x1 ) && ((((long ) (val ) ) >> 1 ) > 0 ) ) || (((Scheme_Type ) (((((long ) (val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (val ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) && ((& ((Scheme_Bignum * ) val ) -> iso ) -> so . keyex & 0x1 ) ) ) {
#       define XfOrM135_COUNT (0+XfOrM133_COUNT)
#       define SETUP_XfOrM135(x) SETUP_XfOrM133(x)
        FUNCCALL(SETUP_XfOrM135(_), scheme_arg_mismatch (who , "result integer is larger than the supplied string: " , val ) ); 
      }
      else {
#       define XfOrM134_COUNT (0+XfOrM133_COUNT)
#       define SETUP_XfOrM134(x) SETUP_XfOrM133(x)
        p [0 ] = val ; 
        FUNCCALL(SETUP_XfOrM134(_), scheme_wrong_type (who , "non-negative exact integer, #f, or evt" , - 1 , - 1 , p ) ); 
      }
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static long user_write_bytes (Scheme_Output_Port * port , const char * str , long offset , long len , int rarely_block , int enable_break ) {
  Scheme_Object * p [5 ] , * to_write , * val ; 
  User_Output_Port * uop = (User_Output_Port * ) port -> port_data ; 
  int n , re_enable_break ; 
  Scheme_Cont_Frame_Data cframe ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK_ONCE(9);
  BLOCK_SETUP_TOP((PUSH(uop, 0), PUSH(str, 1), PUSH(port, 2), PUSH(to_write, 3), PUSH(val, 4), PUSH(cframe.cache, 5), PUSHARRAY(p, 5, 6)));
# define XfOrM142_COUNT (9)
# define SETUP_XfOrM142(x) SETUP(XfOrM142_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  NULL_OUT_ARRAY (p ) ; 
  to_write = NULLED_OUT ; 
  val = NULLED_OUT ; 
  cframe.cache = NULLED_OUT ; 
  if (enable_break )
    re_enable_break = 1 ; 
  else re_enable_break = FUNCCALL(SETUP_XfOrM142(_), scheme_can_break (scheme_current_thread ) ); 
  to_write = FUNCCALL(SETUP_XfOrM142(_), scheme_make_sized_offset_byte_string ((char * ) str , offset , len , 1 ) ); 
  p [0 ] = to_write ; 
  ((((Scheme_Inclhash_Object * ) (p [0 ] ) ) -> so . keyex |= 0x1 ) ) ; 
  p [1 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
  p [2 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (len ) ) << 1 ) | 0x1 ) ) ; 
  p [3 ] = (rarely_block ? scheme_true : scheme_false ) ; 
  p [4 ] = (re_enable_break ? scheme_true : scheme_false ) ; 
  while (1 ) {
#   define XfOrM147_COUNT (0+XfOrM142_COUNT)
#   define SETUP_XfOrM147(x) SETUP_XfOrM142(x)
    FUNCCALL(SETUP_XfOrM147(_), scheme_push_break_enable (& cframe , 0 , 0 ) ); 
    val = FUNCCALL(SETUP_XfOrM147(_), scheme_apply (uop -> write_proc , 5 , p ) ); 
    FUNCCALL_AGAIN(scheme_pop_break_enable (& cframe , 1 ) ); 
    n = FUNCCALL_AGAIN(user_write_result ("user port write" , port , 1 , val , rarely_block , enable_break , len ) ); 
    if (! n && ! rarely_block ) {
    }
    else {
      if (n || (rarely_block != 1 ) ) {
        if (! rarely_block && ! len )
          RET_VALUE_START (0 ) RET_VALUE_END ; 
        RET_VALUE_START (n ) RET_VALUE_END ; 
      }
    }
    FUNCCALL(SETUP_XfOrM147(_), scheme_thread_block (0.0 ) ); 
    scheme_current_thread -> ran_some = 1 ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * user_write_evt_wrapper (void * d , int argc , struct Scheme_Object * argv [] ) {
  Scheme_Object * val , * port ; 
  long r , len ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(port, 0)));
# define XfOrM151_COUNT (1)
# define SETUP_XfOrM151(x) SETUP(XfOrM151_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  val = NULLED_OUT ; 
  port = NULLED_OUT ; 
  port = (Scheme_Object * ) ((void * * ) d ) [0 ] ; 
  val = (Scheme_Object * ) ((void * * ) d ) [1 ] ; 
  len = (((long ) (val ) ) >> 1 ) ; 
  val = argv [0 ] ; 
  r = FUNCCALL(SETUP_XfOrM151(_), user_write_result ("user port write-evt" , (Scheme_Output_Port * ) port , 0 , val , 1 , 0 , len ) ); 
  if (! r && len ) {
#   define XfOrM152_COUNT (0+XfOrM151_COUNT)
#   define SETUP_XfOrM152(x) SETUP_XfOrM151(x)
    FUNCCALL_EMPTY(scheme_arg_mismatch ("user port write-evt" , "port is closed: " , port ) ); 
  }
  RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (r ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * user_write_bytes_evt (Scheme_Output_Port * port , const char * buffer , long offset , long size ) {
  Scheme_Object * to_write , * wrapper ; 
  Scheme_Object * a [3 ] , * val ; 
  void * * args ; 
  User_Output_Port * uop = (User_Output_Port * ) port -> port_data ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(9);
  BLOCK_SETUP_TOP((PUSH(wrapper, 0), PUSH(uop, 1), PUSHARRAY(a, 3, 2), PUSH(port, 5), PUSH(args, 6), PUSH(to_write, 7), PUSH(val, 8)));
# define XfOrM153_COUNT (9)
# define SETUP_XfOrM153(x) SETUP(XfOrM153_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  to_write = NULLED_OUT ; 
  wrapper = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  a[2] = NULLED_OUT ; 
  val = NULLED_OUT ; 
  args = NULLED_OUT ; 
  to_write = FUNCCALL(SETUP_XfOrM153(_), scheme_make_sized_offset_byte_string ((char * ) buffer , offset , size , 1 ) ); 
  ((((Scheme_Inclhash_Object * ) (to_write ) ) -> so . keyex |= 0x1 ) ) ; 
  a [0 ] = to_write ; 
  a [1 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
  a [2 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (size ) ) << 1 ) | 0x1 ) ) ; 
  val = FUNCCALL(SETUP_XfOrM153(_), scheme_apply (uop -> write_evt_proc , 3 , a ) ); 
  if (! FUNCCALL(SETUP_XfOrM153(_), scheme_is_evt (val ) )) {
#   define XfOrM154_COUNT (0+XfOrM153_COUNT)
#   define SETUP_XfOrM154(x) SETUP_XfOrM153(x)
    a [0 ] = val ; 
    FUNCCALL(SETUP_XfOrM154(_), scheme_wrong_type ("user port write-evt" , "evt" , - 1 , - 1 , a ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  args = ((void * * ) FUNCCALL(SETUP_XfOrM153(_), GC_malloc (sizeof (void * ) * (2 ) ) )) ; 
  args [0 ] = port ; 
  args [1 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (size ) ) << 1 ) | 0x1 ) ) ; 
  wrapper = FUNCCALL(SETUP_XfOrM153(_), scheme_make_closed_prim (user_write_evt_wrapper , args ) ); 
  a [0 ] = val ; 
  a [1 ] = wrapper ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM153(_), scheme_wrap_evt (2 , a ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void user_needs_wakeup_output (Scheme_Output_Port * port , void * fds ) {
  /* No conversion */
}
static void user_close_output (Scheme_Output_Port * port ) {
  /* No conversion */
  User_Output_Port * uop = (User_Output_Port * ) port -> port_data ; 
  scheme_apply_multi (uop -> close_proc , 0 , ((void * ) 0 ) ) ; 
}
static int user_write_special (Scheme_Output_Port * port , Scheme_Object * v , int nonblock ) {
  Scheme_Object * a [3 ] ; 
  User_Output_Port * uop = (User_Output_Port * ) port -> port_data ; 
  int re_enable_break ; 
  Scheme_Cont_Frame_Data cframe ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(uop, 1), PUSHARRAY(a, 3, 2), PUSH(cframe.cache, 5)));
# define XfOrM157_COUNT (6)
# define SETUP_XfOrM157(x) SETUP(XfOrM157_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  a[2] = NULLED_OUT ; 
  cframe.cache = NULLED_OUT ; 
  re_enable_break = FUNCCALL(SETUP_XfOrM157(_), scheme_can_break (scheme_current_thread ) ); 
  a [0 ] = v ; 
  a [1 ] = (nonblock ? scheme_true : scheme_false ) ; 
  a [2 ] = (re_enable_break ? scheme_true : scheme_false ) ; 
  FUNCCALL(SETUP_XfOrM157(_), scheme_push_break_enable (& cframe , 0 , 0 ) ); 
  v = FUNCCALL_AGAIN(scheme_apply (uop -> write_special_proc , 3 , a ) ); 
  while (1 ) {
#   define XfOrM161_COUNT (0+XfOrM157_COUNT)
#   define SETUP_XfOrM161(x) SETUP_XfOrM157(x)
    if (FUNCCALL(SETUP_XfOrM161(_), scheme_is_evt (v ) )) {
#     define XfOrM162_COUNT (0+XfOrM161_COUNT)
#     define SETUP_XfOrM162(x) SETUP_XfOrM161(x)
      if (! nonblock ) {
#       define XfOrM163_COUNT (0+XfOrM162_COUNT)
#       define SETUP_XfOrM163(x) SETUP_XfOrM162(x)
        a [0 ] = v ; 
        if (re_enable_break )
          v = FUNCCALL(SETUP_XfOrM163(_), scheme_sync_enable_break (1 , a ) ); 
        else v = FUNCCALL(SETUP_XfOrM163(_), scheme_sync (1 , a ) ); 
      }
      else RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    else break ; 
  }
  FUNCCALL(SETUP_XfOrM157(_), scheme_pop_break_enable (& cframe , 1 ) ); 
  RET_VALUE_START ((! (((v ) ) == (scheme_false ) ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * user_write_special_evt (Scheme_Output_Port * port , Scheme_Object * v ) {
  Scheme_Object * a [1 ] ; 
  User_Output_Port * uop = (User_Output_Port * ) port -> port_data ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSHARRAY(a, 1, 1)));
# define XfOrM164_COUNT (4)
# define SETUP_XfOrM164(x) SETUP(XfOrM164_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a [0 ] = v ; 
  v = FUNCCALL(SETUP_XfOrM164(_), scheme_apply (uop -> write_special_evt_proc , 1 , a ) ); 
  if (! FUNCCALL(SETUP_XfOrM164(_), scheme_is_evt (v ) )) {
#   define XfOrM165_COUNT (0+XfOrM164_COUNT)
#   define SETUP_XfOrM165(x) SETUP_XfOrM164(x)
    a [0 ] = v ; 
    FUNCCALL(SETUP_XfOrM165(_), scheme_wrong_type ("user port write-special-evt" , "evt" , - 1 , - 1 , a ) ); 
  }
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * user_output_location (Scheme_Port * p ) {
  /* No conversion */
  Scheme_Output_Port * op = (Scheme_Output_Port * ) p ; 
  User_Output_Port * uop = (User_Output_Port * ) op -> port_data ; 
  return scheme_apply_multi (uop -> location_proc , 0 , ((void * ) 0 ) ) ; 
}
static void user_output_count_lines (Scheme_Port * p ) {
  /* No conversion */
  Scheme_Output_Port * op = (Scheme_Output_Port * ) p ; 
  User_Output_Port * uop = (User_Output_Port * ) op -> port_data ; 
  scheme_apply_multi (uop -> count_lines_proc , 0 , ((void * ) 0 ) ) ; 
}
static int user_output_buffer_mode (Scheme_Port * p , int mode ) {
  /* No conversion */
  Scheme_Output_Port * op = (Scheme_Output_Port * ) p ; 
  User_Output_Port * uop = (User_Output_Port * ) op -> port_data ; 
  return user_buffer_mode (uop -> buffer_mode_proc , mode , 1 ) ; 
}
int scheme_is_user_port (Scheme_Object * port ) {
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(port, 0)));
# define XfOrM169_COUNT (1)
# define SETUP_XfOrM169(x) SETUP(XfOrM169_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((scheme_is_input_port (port ) ) ) {
    Scheme_Input_Port * ip ; 
    BLOCK_SETUP((PUSH(ip, 0+XfOrM169_COUNT)));
#   define XfOrM171_COUNT (1+XfOrM169_COUNT)
#   define SETUP_XfOrM171(x) SETUP(XfOrM171_COUNT)
    ip = NULLED_OUT ; 
    ip = FUNCCALL(SETUP_XfOrM171(_), scheme_input_port_record (port ) ); 
    RET_VALUE_START (((scheme_user_input_port_type ) == (ip -> sub_type ) ) ) RET_VALUE_END ; 
  }
  else {
    Scheme_Output_Port * op ; 
    BLOCK_SETUP((PUSH(op, 0+XfOrM169_COUNT)));
#   define XfOrM170_COUNT (1+XfOrM169_COUNT)
#   define SETUP_XfOrM170(x) SETUP(XfOrM170_COUNT)
    op = NULLED_OUT ; 
    op = FUNCCALL(SETUP_XfOrM170(_), scheme_output_port_record (port ) ); 
    RET_VALUE_START (((scheme_user_output_port_type ) == (op -> sub_type ) ) ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void pipe_did_read (Scheme_Input_Port * port , Scheme_Pipe * pipe ) {
  PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(pipe, 0), PUSH(port, 1)));
# define XfOrM172_COUNT (2)
# define SETUP_XfOrM172(x) SETUP(XfOrM172_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (port && port -> progress_evt ) {
#   define XfOrM175_COUNT (0+XfOrM172_COUNT)
#   define SETUP_XfOrM175(x) SETUP_XfOrM172(x)
    FUNCCALL(SETUP_XfOrM175(_), scheme_post_sema_all (port -> progress_evt ) ); 
    port -> progress_evt = ((void * ) 0 ) ; 
  }
  while (((Scheme_Type ) (((((long ) (pipe -> wakeup_on_read ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (pipe -> wakeup_on_read ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
    Scheme_Object * sema ; 
    BLOCK_SETUP((PUSH(sema, 0+XfOrM172_COUNT)));
#   define XfOrM174_COUNT (1+XfOrM172_COUNT)
#   define SETUP_XfOrM174(x) SETUP(XfOrM174_COUNT)
    sema = NULLED_OUT ; 
    sema = (((Scheme_Simple_Object * ) (pipe -> wakeup_on_read ) ) -> u . pair_val . car ) ; 
    pipe -> wakeup_on_read = (((Scheme_Simple_Object * ) (pipe -> wakeup_on_read ) ) -> u . pair_val . cdr ) ; 
    FUNCCALL(SETUP_XfOrM174(_), scheme_post_sema (sema ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void pipe_did_write (Scheme_Pipe * pipe ) {
  PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(pipe, 0)));
# define XfOrM176_COUNT (1)
# define SETUP_XfOrM176(x) SETUP(XfOrM176_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  while (((Scheme_Type ) (((((long ) (pipe -> wakeup_on_write ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (pipe -> wakeup_on_write ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
    Scheme_Object * sema ; 
    BLOCK_SETUP((PUSH(sema, 0+XfOrM176_COUNT)));
#   define XfOrM178_COUNT (1+XfOrM176_COUNT)
#   define SETUP_XfOrM178(x) SETUP(XfOrM178_COUNT)
    sema = NULLED_OUT ; 
    sema = (((Scheme_Simple_Object * ) (pipe -> wakeup_on_write ) ) -> u . pair_val . car ) ; 
    pipe -> wakeup_on_write = (((Scheme_Simple_Object * ) (pipe -> wakeup_on_write ) ) -> u . pair_val . cdr ) ; 
    FUNCCALL(SETUP_XfOrM178(_), scheme_post_sema (sema ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 2052 */
/* this far 2020 */
static long pipe_get_or_peek_bytes (Scheme_Input_Port * p , char * buffer , long offset , long size , int nonblock , int peek , long peek_skip , Scheme_Object * unless ) {
  Scheme_Pipe * pipe ; 
  long c , skipped = 0 ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(unless, 0), PUSH(buffer, 1), PUSH(pipe, 2), PUSH(p, 3)));
# define XfOrM179_COUNT (4)
# define SETUP_XfOrM179(x) SETUP(XfOrM179_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  pipe = NULLED_OUT ; 
  pipe = (Scheme_Pipe * ) (p -> port_data ) ; 
  while ((pipe -> bufstart == pipe -> bufend ) && ! pipe -> eof ) {
#   define XfOrM197_COUNT (0+XfOrM179_COUNT)
#   define SETUP_XfOrM197(x) SETUP_XfOrM179(x)
    if (nonblock > 0 )
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    FUNCCALL(SETUP_XfOrM197(_), scheme_block_until_unless ((Scheme_Ready_Fun ) scheme_byte_ready_or_user_port_ready , ((void * ) 0 ) , (Scheme_Object * ) p , 0.0 , unless , nonblock ) ); 
    FUNCCALL_AGAIN(scheme_wait_input_allowed (p , nonblock ) ); 
    if ((scheme_unless_ready (unless ) ) )
      RET_VALUE_START ((- 3 ) ) RET_VALUE_END ; 
  }
  if (p -> closed ) {
#   define XfOrM195_COUNT (0+XfOrM179_COUNT)
#   define SETUP_XfOrM195(x) SETUP_XfOrM179(x)
    FUNCCALL(SETUP_XfOrM195(_), scheme_getc ((Scheme_Object * ) p ) ); 
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  if (pipe -> bufstart == pipe -> bufend )
    c = (- 1 ) ; 
  else {
    long bs = pipe -> bufstart ; 
#   define XfOrM188_COUNT (0+XfOrM179_COUNT)
#   define SETUP_XfOrM188(x) SETUP_XfOrM179(x)
    c = 0 ; 
    if (bs > pipe -> bufend ) {
      int n ; 
#     define XfOrM192_COUNT (0+XfOrM188_COUNT)
#     define SETUP_XfOrM192(x) SETUP_XfOrM188(x)
      n = pipe -> buflen - bs ; 
      if (n < peek_skip ) {
        peek_skip -= n ; 
        bs += n ; 
        skipped += n ; 
        n = 0 ; 
      }
      else {
        bs += peek_skip ; 
        n -= peek_skip ; 
        skipped += peek_skip ; 
        peek_skip = 0 ; 
      }
      if (n > size )
        n = size ; 
      if (buffer )
        (memcpy (buffer + offset , pipe -> buf + bs , n ) ) ; 
      bs += n ; 
      if (bs == pipe -> buflen )
        bs = 0 ; 
      if (! peek )
        pipe -> bufstart = bs ; 
      size -= n ; 
      c += n ; 
    }
    if (bs < pipe -> bufend ) {
      int n ; 
#     define XfOrM189_COUNT (0+XfOrM188_COUNT)
#     define SETUP_XfOrM189(x) SETUP_XfOrM188(x)
      n = pipe -> bufend - bs ; 
      if (n < peek_skip ) {
        peek_skip -= n ; 
        bs += n ; 
        skipped += n ; 
        n = 0 ; 
      }
      else {
        bs += peek_skip ; 
        n -= peek_skip ; 
        skipped += peek_skip ; 
        peek_skip = 0 ; 
      }
      if (n > size )
        n = size ; 
      if (buffer )
        (memcpy (buffer + offset + c , pipe -> buf + bs , n ) ) ; 
      bs += n ; 
      if (! peek )
        pipe -> bufstart = bs ; 
      size -= n ; 
      c += n ; 
    }
  }
  if (! peek && (c > 0 ) ) {
#   define XfOrM186_COUNT (0+XfOrM179_COUNT)
#   define SETUP_XfOrM186(x) SETUP_XfOrM179(x)
    if (pipe -> bufmaxextra ) {
      if (pipe -> bufmaxextra > c )
        pipe -> bufmaxextra -= c ; 
      else pipe -> bufmaxextra = 0 ; 
    }
    FUNCCALL(SETUP_XfOrM186(_), pipe_did_read (p , pipe ) ); 
  }
  else {
#   define XfOrM180_COUNT (0+XfOrM179_COUNT)
#   define SETUP_XfOrM180(x) SETUP_XfOrM179(x)
    if (! c ) {
#     define XfOrM184_COUNT (0+XfOrM180_COUNT)
#     define SETUP_XfOrM184(x) SETUP_XfOrM180(x)
      if (size && pipe -> eof )
        RET_VALUE_START ((- 1 ) ) RET_VALUE_END ; 
      if (! nonblock ) {
        Scheme_Object * my_sema , * wp ; 
        BLOCK_SETUP((PUSH(my_sema, 0+XfOrM184_COUNT), PUSH(wp, 1+XfOrM184_COUNT)));
#       define XfOrM185_COUNT (2+XfOrM184_COUNT)
#       define SETUP_XfOrM185(x) SETUP(XfOrM185_COUNT)
        my_sema = NULLED_OUT ; 
        wp = NULLED_OUT ; 
        my_sema = FUNCCALL(SETUP_XfOrM185(_), scheme_make_sema (0 ) ); 
        wp = FUNCCALL_AGAIN(scheme_make_pair (my_sema , pipe -> wakeup_on_write ) ); 
        pipe -> wakeup_on_write = wp ; 
        FUNCCALL(SETUP_XfOrM185(_), scheme_wait_sema (my_sema , (nonblock < 0 ) ? - 1 : 0 ) ); 
      }
    }
    else if (c > 0 ) {
      if (pipe -> bufmax ) {
        if (pipe -> bufmaxextra < c + skipped ) {
          pipe -> bufmaxextra = c + skipped ; 
        }
      }
    }
  }
  RET_VALUE_START (c ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static long pipe_get_bytes (Scheme_Input_Port * p , char * buffer , long offset , long size , int nonblock , Scheme_Object * unless ) {
  /* No conversion */
  return pipe_get_or_peek_bytes (p , buffer , offset , size , nonblock , 0 , 0 , unless ) ; 
}
static long pipe_peek_bytes (Scheme_Input_Port * p , char * buffer , long offset , long size , Scheme_Object * skip , int nonblock , Scheme_Object * unless ) {
  /* No conversion */
  long peek_skip ; 
  if ((((long ) (skip ) ) & 0x1 ) )
    peek_skip = (((long ) (skip ) ) >> 1 ) ; 
  else {
    peek_skip = 0x7FFFFFFFFFFFFFFF ; 
  }
  return pipe_get_or_peek_bytes (p , buffer , offset , size , nonblock , 1 , peek_skip , unless ) ; 
}
/* this far 2263 */
/* this far 2239 */
static long pipe_write_bytes (Scheme_Output_Port * p , const char * str , long d , long len , int rarely_block , int enable_break ) {
  Scheme_Pipe * pipe ; 
  long avail , firstpos , firstn , secondn , endpos ; 
  long wrote = 0 ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(str, 0), PUSH(pipe, 1), PUSH(p, 2)));
# define XfOrM201_COUNT (3)
# define SETUP_XfOrM201(x) SETUP(XfOrM201_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  pipe = NULLED_OUT ; 
  pipe = (Scheme_Pipe * ) (p -> port_data ) ; 
  try_again : if (pipe -> eof || ! len )
    RET_VALUE_START (len + wrote ) RET_VALUE_END ; 
  if (pipe -> bufstart <= pipe -> bufend ) {
    firstn = pipe -> buflen - pipe -> bufend ; 
    avail = firstn + pipe -> bufstart - 1 ; 
    if (! pipe -> bufstart )
      -- firstn ; 
  }
  else {
    firstn = avail = pipe -> bufstart - pipe -> bufend - 1 ; 
  }
  firstpos = pipe -> bufend ; 
  if (pipe -> bufmax ) {
    long extra ; 
    extra = pipe -> buflen - (pipe -> bufmax + pipe -> bufmaxextra ) ; 
    if (extra > 0 )
      avail -= extra ; 
  }
  if (pipe -> bufmax && (avail < len ) ) {
    long xavail = avail ; 
    long can_extra ; 
#   define XfOrM209_COUNT (0+XfOrM201_COUNT)
#   define SETUP_XfOrM209(x) SETUP_XfOrM201(x)
    can_extra = ((pipe -> bufmax + pipe -> bufmaxextra ) - pipe -> buflen ) ; 
    if (can_extra > 0 )
      xavail += can_extra ; 
    if (xavail < len ) {
      Scheme_Object * my_sema ; 
      BLOCK_SETUP((PUSH(my_sema, 0+XfOrM209_COUNT)));
#     define XfOrM210_COUNT (1+XfOrM209_COUNT)
#     define SETUP_XfOrM210(x) SETUP(XfOrM210_COUNT)
      my_sema = NULLED_OUT ; 
      xavail = FUNCCALL(SETUP_XfOrM210(_), pipe_write_bytes (p , str , d , xavail , rarely_block , enable_break ) ); 
      wrote += xavail ; 
      d += xavail ; 
      len -= xavail ; 
      if ((rarely_block && wrote ) || (rarely_block == 2 ) )
        RET_VALUE_START (wrote ) RET_VALUE_END ; 
      while (1 ) {
#       define XfOrM216_COUNT (0+XfOrM210_COUNT)
#       define SETUP_XfOrM216(x) SETUP_XfOrM210(x)
        if (pipe -> bufstart <= pipe -> bufend ) {
          avail = (pipe -> buflen - pipe -> bufend ) + pipe -> bufstart - 1 ; 
        }
        else {
          avail = pipe -> bufstart - pipe -> bufend - 1 ; 
        }
        if (pipe -> bufmax ) {
          long extra ; 
          extra = pipe -> buflen - (pipe -> bufmax + pipe -> bufmaxextra ) ; 
          if (extra > 0 )
            avail -= extra ; 
        }
        if (avail || pipe -> eof || p -> closed )
          goto try_again ; 
        my_sema = FUNCCALL(SETUP_XfOrM216(_), scheme_make_sema (0 ) ); 
        {
          Scheme_Object * wp ; 
          BLOCK_SETUP((PUSH(wp, 0+XfOrM216_COUNT)));
#         define XfOrM217_COUNT (1+XfOrM216_COUNT)
#         define SETUP_XfOrM217(x) SETUP(XfOrM217_COUNT)
          wp = NULLED_OUT ; 
          wp = FUNCCALL(SETUP_XfOrM217(_), scheme_make_pair (my_sema , pipe -> wakeup_on_read ) ); 
          pipe -> wakeup_on_read = wp ; 
        }
        FUNCCALL(SETUP_XfOrM216(_), scheme_wait_sema (my_sema , enable_break ? - 1 : 0 ) ); 
      }
    }
  }
  if (avail < len ) {
    unsigned char * old ; 
    int newlen ; 
    BLOCK_SETUP((PUSH(old, 0+XfOrM201_COUNT)));
#   define XfOrM205_COUNT (1+XfOrM201_COUNT)
#   define SETUP_XfOrM205(x) SETUP(XfOrM205_COUNT)
    old = NULLED_OUT ; 
    old = pipe -> buf ; 
    newlen = 2 * (pipe -> buflen + len ) ; 
    if (pipe -> bufmax && (newlen > (pipe -> bufmax + pipe -> bufmaxextra ) ) )
      newlen = pipe -> bufmax + pipe -> bufmaxextra ; 
    {
      unsigned char * uca ; 
      BLOCK_SETUP((PUSH(uca, 0+XfOrM205_COUNT)));
#     define XfOrM208_COUNT (1+XfOrM205_COUNT)
#     define SETUP_XfOrM208(x) SETUP(XfOrM208_COUNT)
      uca = NULLED_OUT ; 
      uca = (unsigned char * ) FUNCCALL(SETUP_XfOrM208(_), GC_malloc_atomic (newlen ) ); 
      pipe -> buf = uca ; 
    }
    if (pipe -> bufstart <= pipe -> bufend ) {
#     define XfOrM207_COUNT (0+XfOrM205_COUNT)
#     define SETUP_XfOrM207(x) SETUP_XfOrM205(x)
      (memcpy (pipe -> buf , old + pipe -> bufstart , pipe -> bufend - pipe -> bufstart ) ) ; 
      pipe -> bufend -= pipe -> bufstart ; 
      pipe -> bufstart = 0 ; 
    }
    else {
      int slen ; 
#     define XfOrM206_COUNT (0+XfOrM205_COUNT)
#     define SETUP_XfOrM206(x) SETUP_XfOrM205(x)
      slen = pipe -> buflen - pipe -> bufstart ; 
      (memcpy (pipe -> buf , old + pipe -> bufstart , slen ) ) ; 
      (memcpy (pipe -> buf + slen , old , pipe -> bufend ) ) ; 
      pipe -> bufstart = 0 ; 
      pipe -> bufend += slen ; 
    }
    pipe -> buflen = newlen ; 
    firstpos = pipe -> bufend ; 
    firstn = len ; 
    endpos = firstpos + firstn ; 
    secondn = 0 ; 
  }
  else {
    if (firstn >= len ) {
      firstn = len ; 
      endpos = (firstpos + len ) % pipe -> buflen ; 
      secondn = 0 ; 
    }
    else {
      secondn = len - firstn ; 
      endpos = secondn ; 
    }
  }
  if (firstn )
    (memcpy (pipe -> buf + firstpos , str + d , firstn ) ) ; 
  if (secondn )
    (memcpy (pipe -> buf , str + d + firstn , secondn ) ) ; 
  pipe -> bufend = endpos ; 
  FUNCCALL_EMPTY(pipe_did_write (pipe ) ); 
  RET_VALUE_START (len + wrote ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int pipe_byte_ready (Scheme_Input_Port * p ) {
  /* No conversion */
  Scheme_Pipe * pipe ; 
  int v ; 
  pipe = (Scheme_Pipe * ) (p -> port_data ) ; 
  v = (pipe -> bufstart != pipe -> bufend || pipe -> eof ) ; 
  return v ; 
}
static void pipe_in_close (Scheme_Input_Port * p ) {
  Scheme_Pipe * pipe ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(pipe, 0)));
# define XfOrM225_COUNT (1)
# define SETUP_XfOrM225(x) SETUP(XfOrM225_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  pipe = NULLED_OUT ; 
  pipe = (Scheme_Pipe * ) (p -> port_data ) ; 
  pipe -> eof = 1 ; 
  FUNCCALL(SETUP_XfOrM225(_), pipe_did_read (p , pipe ) ); 
  FUNCCALL_EMPTY(pipe_did_write (pipe ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void pipe_out_close (Scheme_Output_Port * p ) {
  Scheme_Pipe * pipe ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(pipe, 0)));
# define XfOrM226_COUNT (1)
# define SETUP_XfOrM226(x) SETUP(XfOrM226_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  pipe = NULLED_OUT ; 
  pipe = (Scheme_Pipe * ) (p -> port_data ) ; 
  pipe -> eof = 1 ; 
  FUNCCALL(SETUP_XfOrM226(_), pipe_did_read (((void * ) 0 ) , pipe ) ); 
  FUNCCALL_EMPTY(pipe_did_write (pipe ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int pipe_out_ready (Scheme_Output_Port * p ) {
  /* No conversion */
  Scheme_Pipe * pipe ; 
  long avail ; 
  pipe = (Scheme_Pipe * ) (p -> port_data ) ; 
  if (pipe -> eof || ! pipe -> bufmax )
    return 1 ; 
  if (pipe -> bufend >= pipe -> bufstart ) {
    avail = pipe -> bufend - pipe -> bufstart ; 
  }
  else {
    avail = pipe -> bufend + (pipe -> buflen - pipe -> bufstart ) ; 
  }
  avail = pipe -> bufmax + pipe -> bufmaxextra - 1 - avail ; 
  return avail > 0 ; 
}
void scheme_pipe_with_limit (Scheme_Object * * read , Scheme_Object * * write , int queuelimit ) {
  Scheme_Pipe * pipe ; 
  Scheme_Input_Port * readp ; 
  Scheme_Output_Port * writep ; 
  Scheme_Object * name ; 
  PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(write, 0), PUSH(name, 1), PUSH(read, 2), PUSH(writep, 3), PUSH(readp, 4), PUSH(pipe, 5)));
# define XfOrM230_COUNT (6)
# define SETUP_XfOrM230(x) SETUP(XfOrM230_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  pipe = NULLED_OUT ; 
  readp = NULLED_OUT ; 
  writep = NULLED_OUT ; 
  name = NULLED_OUT ; 
  if (queuelimit )
    queuelimit ++ ; 
  pipe = ((Scheme_Pipe * ) FUNCCALL(SETUP_XfOrM230(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Pipe ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  pipe -> type = scheme_rt_pipe ; 
  pipe -> buflen = ((queuelimit && (queuelimit < 100 ) ) ? queuelimit : 100 ) ; 
  {
    unsigned char * uca ; 
    BLOCK_SETUP((PUSH(uca, 0+XfOrM230_COUNT)));
#   define XfOrM231_COUNT (1+XfOrM230_COUNT)
#   define SETUP_XfOrM231(x) SETUP(XfOrM231_COUNT)
    uca = NULLED_OUT ; 
    uca = (unsigned char * ) FUNCCALL(SETUP_XfOrM231(_), GC_malloc_atomic (pipe -> buflen ) ); 
    pipe -> buf = uca ; 
  }
  pipe -> bufstart = pipe -> bufend = 0 ; 
  pipe -> eof = 0 ; 
  pipe -> bufmax = queuelimit ; 
  pipe -> wakeup_on_read = scheme_null ; 
  pipe -> wakeup_on_write = scheme_null ; 
  name = FUNCCALL(SETUP_XfOrM230(_), scheme_intern_symbol ("pipe" ) ); 
  readp = FUNCCALL_AGAIN(scheme_make_input_port (scheme_pipe_read_port_type , (void * ) pipe , name , pipe_get_bytes , pipe_peek_bytes , scheme_progress_evt_via_get , scheme_peeked_read_via_get , pipe_byte_ready , pipe_in_close , ((void * ) 0 ) , 0 ) ); 
  writep = FUNCCALL_AGAIN(scheme_make_output_port (scheme_pipe_write_port_type , (void * ) pipe , name , scheme_write_evt_via_write , pipe_write_bytes , pipe_out_ready , pipe_out_close , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ); 
  * read = (Scheme_Object * ) readp ; 
  * write = (Scheme_Object * ) writep ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_pipe (Scheme_Object * * read , Scheme_Object * * write ) {
  /* No conversion */
  scheme_pipe_with_limit (read , write , 0 ) ; 
}
static Scheme_Object * sch_pipe (int argc , Scheme_Object * * args ) {
  Scheme_Object * v [2 ] ; 
  int bufmax ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSHARRAY(v, 2, 0), PUSH(args, 3)));
# define XfOrM233_COUNT (4)
# define SETUP_XfOrM233(x) SETUP(XfOrM233_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v[0] = NULLED_OUT ; 
  v[1] = NULLED_OUT ; 
  if (argc == 1 ) {
    Scheme_Object * o = args [0 ] ; 
#   define XfOrM234_COUNT (0+XfOrM233_COUNT)
#   define SETUP_XfOrM234(x) SETUP_XfOrM233(x)
    if ((((o ) ) == (scheme_false ) ) ) {
      bufmax = 0 ; 
    }
    else if (((((long ) (o ) ) & 0x1 ) || ((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) && (scheme_is_positive (o ) ) ) {
      if ((((long ) (o ) ) & 0x1 ) )
        bufmax = (((long ) (o ) ) >> 1 ) ; 
      else bufmax = 0 ; 
    }
    else {
#     define XfOrM235_COUNT (0+XfOrM234_COUNT)
#     define SETUP_XfOrM235(x) SETUP_XfOrM234(x)
      FUNCCALL(SETUP_XfOrM235(_), scheme_wrong_type ("make-pipe" , "positive exact integer or #f" , 0 , argc , args ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  else bufmax = 0 ; 
  FUNCCALL(SETUP_XfOrM233(_), scheme_pipe_with_limit (& v [0 ] , & v [1 ] , bufmax ) ); 
  if (argc > 1 )
    ((Scheme_Input_Port * ) (v [0 ] ) ) -> name = args [1 ] ; 
  if (argc > 2 )
    ((Scheme_Output_Port * ) (v [1 ] ) ) -> name = args [2 ] ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM233(_), scheme_values (2 , v ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * pipe_length (int argc , Scheme_Object * * argv ) {
  Scheme_Object * o ; 
  Scheme_Pipe * pipe = ((void * ) 0 ) ; 
  int avail ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(pipe, 0), PUSH(argv, 1), PUSH(o, 2)));
# define XfOrM238_COUNT (3)
# define SETUP_XfOrM238(x) SETUP(XfOrM238_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  o = NULLED_OUT ; 
  o = argv [0 ] ; 
  if ((scheme_is_output_port (o ) ) ) {
    Scheme_Output_Port * op ; 
    BLOCK_SETUP((PUSH(op, 0+XfOrM238_COUNT)));
#   define XfOrM244_COUNT (1+XfOrM238_COUNT)
#   define SETUP_XfOrM244(x) SETUP(XfOrM244_COUNT)
    op = NULLED_OUT ; 
    op = FUNCCALL(SETUP_XfOrM244(_), scheme_output_port_record (o ) ); 
    if (op -> sub_type == scheme_pipe_write_port_type ) {
      pipe = (Scheme_Pipe * ) op -> port_data ; 
    }
  }
  else if ((scheme_is_input_port (o ) ) ) {
    Scheme_Input_Port * ip ; 
    BLOCK_SETUP((PUSH(ip, 0+XfOrM238_COUNT)));
#   define XfOrM242_COUNT (1+XfOrM238_COUNT)
#   define SETUP_XfOrM242(x) SETUP(XfOrM242_COUNT)
    ip = NULLED_OUT ; 
    ip = FUNCCALL(SETUP_XfOrM242(_), scheme_input_port_record (o ) ); 
    if (ip -> sub_type == scheme_pipe_read_port_type ) {
      pipe = (Scheme_Pipe * ) ip -> port_data ; 
    }
  }
  if (! pipe ) {
#   define XfOrM241_COUNT (0+XfOrM238_COUNT)
#   define SETUP_XfOrM241(x) SETUP_XfOrM238(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("pipe-content-length" , "pipe input port or output port" , 0 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (pipe -> bufend >= pipe -> bufstart ) {
    avail = pipe -> bufend - pipe -> bufstart ; 
  }
  else {
    avail = pipe -> bufend + (pipe -> buflen - pipe -> bufstart ) ; 
  }
  RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (avail ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * input_port_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (scheme_is_input_port (argv [0 ] ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * output_port_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (scheme_is_output_port (argv [0 ] ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * port_closed_p (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * v = argv [0 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(argv, 1)));
# define XfOrM248_COUNT (2)
# define SETUP_XfOrM248(x) SETUP(XfOrM248_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((scheme_is_input_port (v ) ) ) {
    Scheme_Input_Port * ip ; 
    BLOCK_SETUP((PUSH(ip, 0+XfOrM248_COUNT)));
#   define XfOrM251_COUNT (1+XfOrM248_COUNT)
#   define SETUP_XfOrM251(x) SETUP(XfOrM251_COUNT)
    ip = NULLED_OUT ; 
    ip = FUNCCALL(SETUP_XfOrM251(_), scheme_input_port_record (v ) ); 
    RET_VALUE_START (ip -> closed ? scheme_true : scheme_false ) RET_VALUE_END ; 
  }
  else if ((scheme_is_output_port (v ) ) ) {
    Scheme_Output_Port * op ; 
    BLOCK_SETUP((PUSH(op, 0+XfOrM248_COUNT)));
#   define XfOrM250_COUNT (1+XfOrM248_COUNT)
#   define SETUP_XfOrM250(x) SETUP(XfOrM250_COUNT)
    op = NULLED_OUT ; 
    op = FUNCCALL(SETUP_XfOrM250(_), scheme_output_port_record (v ) ); 
    RET_VALUE_START (op -> closed ? scheme_true : scheme_false ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM249_COUNT (0+XfOrM248_COUNT)
#   define SETUP_XfOrM249(x) SETUP_XfOrM248(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("port-closed?" , "input-port or output-port" , 0 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * current_input_port (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("current-input-port" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_INPUT_PORT ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , input_port_p , "input-port" , 0 ) ; 
}
static Scheme_Object * current_output_port (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("current-output-port" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_OUTPUT_PORT ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , output_port_p , "output-port" , 0 ) ; 
}
static Scheme_Object * current_error_port (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("current-error-port" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_ERROR_PORT ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , output_port_p , "output-port" , 0 ) ; 
}
static Scheme_Object * make_input_port (int argc , Scheme_Object * argv [] ) {
  Scheme_Input_Port * ip ; 
  User_Input_Port * uip ; 
  Scheme_Object * name ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(uip, 0), PUSH(ip, 1), PUSH(argv, 2), PUSH(name, 3)));
# define XfOrM255_COUNT (4)
# define SETUP_XfOrM255(x) SETUP(XfOrM255_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ip = NULLED_OUT ; 
  uip = NULLED_OUT ; 
  name = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM255(_), scheme_check_proc_arity ("make-input-port" , 1 , 1 , argc , argv ) ); 
  FUNCCALL_AGAIN(scheme_check_proc_arity2 ("make-input-port" , 3 , 2 , argc , argv , 1 ) ); 
  FUNCCALL_AGAIN(scheme_check_proc_arity ("make-input-port" , 0 , 3 , argc , argv ) ); 
  if (argc > 4 )
    FUNCCALL(SETUP_XfOrM255(_), scheme_check_proc_arity2 ("make-input-port" , 0 , 4 , argc , argv , 1 ) ); 
  if (argc > 5 )
    FUNCCALL(SETUP_XfOrM255(_), scheme_check_proc_arity2 ("make-input-port" , 3 , 5 , argc , argv , 1 ) ); 
  if (argc > 6 )
    FUNCCALL(SETUP_XfOrM255(_), scheme_check_proc_arity2 ("make-input-port" , 0 , 6 , argc , argv , 1 ) ); 
  if (argc > 7 )
    FUNCCALL(SETUP_XfOrM255(_), scheme_check_proc_arity ("make-input-port" , 0 , 7 , argc , argv ) ); 
  if (argc > 8 ) {
#   define XfOrM258_COUNT (0+XfOrM255_COUNT)
#   define SETUP_XfOrM258(x) SETUP_XfOrM255(x)
    if (! (((((long ) (argv [8 ] ) ) & 0x1 ) && (((long ) (argv [8 ] ) ) >> 1 ) > 0 ) || (((Scheme_Type ) (((((long ) (argv [8 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [8 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) && ((& ((Scheme_Bignum * ) argv [8 ] ) -> iso ) -> so . keyex & 0x1 ) ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("make-input-port" , "exact, positive integer" , 8 , argc , argv ) ); 
  }
  if (argc > 9 ) {
#   define XfOrM257_COUNT (0+XfOrM255_COUNT)
#   define SETUP_XfOrM257(x) SETUP_XfOrM255(x)
    if ((! (((argv [9 ] ) ) == (scheme_false ) ) ) && ! FUNCCALL(SETUP_XfOrM257(_), scheme_check_proc_arity (((void * ) 0 ) , 0 , 9 , argc , argv ) )&& ! FUNCCALL(SETUP_XfOrM257(_), scheme_check_proc_arity (((void * ) 0 ) , 1 , 9 , argc , argv ) ))
      FUNCCALL_EMPTY(scheme_wrong_type ("make-input-port" , "procedure (arities 0 and 1)" , 9 , argc , argv ) ); 
  }
  name = argv [0 ] ; 
  if ((argc > 5 ) && (((argv [2 ] ) ) == (scheme_false ) ) && ! (((argv [4 ] ) ) == (scheme_false ) ) )
    FUNCCALL(SETUP_XfOrM255(_), scheme_arg_mismatch ("make-input-port" , "peek argument is #f, but progress-evt argument is not: " , argv [4 ] ) ); 
  if ((argc > 5 ) && (((argv [4 ] ) ) == (scheme_false ) ) && ! (((argv [5 ] ) ) == (scheme_false ) ) )
    FUNCCALL(SETUP_XfOrM255(_), scheme_arg_mismatch ("make-input-port" , "progress-evt argument is #f, but commit argument is not: " , argv [6 ] ) ); 
  if ((argc > 4 ) && ! (((argv [4 ] ) ) == (scheme_false ) ) && ((argc < 6 ) || (((argv [5 ] ) ) == (scheme_false ) ) ) )
    FUNCCALL(SETUP_XfOrM255(_), scheme_arg_mismatch ("make-input-port" , "commit argument is #f, but progress-evt argument is not: " , argv [6 ] ) ); 
  uip = ((User_Input_Port * ) FUNCCALL(SETUP_XfOrM255(_), GC_malloc_one_small_tagged ((((sizeof (User_Input_Port ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  uip -> type = scheme_rt_user_input ; 
  uip -> read_proc = argv [1 ] ; 
  uip -> peek_proc = argv [2 ] ; 
  if ((((uip -> peek_proc ) ) == (scheme_false ) ) )
    uip -> peek_proc = ((void * ) 0 ) ; 
  uip -> close_proc = argv [3 ] ; 
  uip -> progress_evt_proc = ((argc > 4 ) ? argv [4 ] : scheme_false ) ; 
  if ((((uip -> progress_evt_proc ) ) == (scheme_false ) ) )
    uip -> progress_evt_proc = ((void * ) 0 ) ; 
  uip -> peeked_read_proc = ((argc > 5 ) ? argv [5 ] : scheme_false ) ; 
  if ((((uip -> peeked_read_proc ) ) == (scheme_false ) ) )
    uip -> peeked_read_proc = ((void * ) 0 ) ; 
  uip -> location_proc = ((argc > 6 ) ? argv [6 ] : scheme_false ) ; 
  if ((((uip -> location_proc ) ) == (scheme_false ) ) )
    uip -> location_proc = ((void * ) 0 ) ; 
  if (argc > 7 )
    uip -> count_lines_proc = argv [7 ] ; 
  uip -> buffer_mode_proc = ((argc > 9 ) ? argv [9 ] : scheme_false ) ; 
  if ((((uip -> buffer_mode_proc ) ) == (scheme_false ) ) )
    uip -> buffer_mode_proc = ((void * ) 0 ) ; 
  ip = FUNCCALL(SETUP_XfOrM255(_), scheme_make_input_port (scheme_user_input_port_type , uip , name , user_get_bytes , uip -> peek_proc ? user_peek_bytes : ((void * ) 0 ) , uip -> progress_evt_proc ? user_progress_evt : ((void * ) 0 ) , uip -> peeked_read_proc ? user_peeked_read : ((void * ) 0 ) , user_byte_ready , user_close_input , user_needs_wakeup_input , 0 ) ); 
  if (uip -> location_proc )
    FUNCCALL(SETUP_XfOrM255(_), scheme_set_port_location_fun ((Scheme_Port * ) ip , user_input_location ) ); 
  if (uip -> count_lines_proc )
    FUNCCALL(SETUP_XfOrM255(_), scheme_set_port_count_lines_fun ((Scheme_Port * ) ip , user_input_count_lines ) ); 
  if (! uip -> peek_proc )
    ip -> pending_eof = 1 ; 
  if (argc > 8 ) {
    if ((((long ) (argv [8 ] ) ) & 0x1 ) )
      ip -> p . position = ((((long ) (argv [8 ] ) ) >> 1 ) - 1 ) ; 
    else ip -> p . position = - 1 ; 
  }
  if (uip -> buffer_mode_proc )
    ip -> p . buffer_mode_fun = user_input_buffer_mode ; 
  if (ip -> p . count_lines && uip -> count_lines_proc )
    FUNCCALL(SETUP_XfOrM255(_), scheme_apply_multi (uip -> count_lines_proc , 0 , ((void * ) 0 ) ) ); 
  RET_VALUE_START ((Scheme_Object * ) ip ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_output_port (int argc , Scheme_Object * argv [] ) {
  Scheme_Output_Port * op ; 
  User_Output_Port * uop ; 
  Scheme_Object * name ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(uop, 0), PUSH(op, 1), PUSH(argv, 2), PUSH(name, 3)));
# define XfOrM259_COUNT (4)
# define SETUP_XfOrM259(x) SETUP(XfOrM259_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  op = NULLED_OUT ; 
  uop = NULLED_OUT ; 
  name = NULLED_OUT ; 
  if (! FUNCCALL(SETUP_XfOrM259(_), scheme_is_evt (argv [1 ] ) )) {
#   define XfOrM265_COUNT (0+XfOrM259_COUNT)
#   define SETUP_XfOrM265(x) SETUP_XfOrM259(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("make-output-port" , "evt" , 1 , argc , argv ) ); 
  }
  FUNCCALL(SETUP_XfOrM259(_), scheme_check_proc_arity ("make-output-port" , 5 , 2 , argc , argv ) ); 
  FUNCCALL(SETUP_XfOrM259(_), scheme_check_proc_arity ("make-output-port" , 0 , 3 , argc , argv ) ); 
  if (argc > 4 )
    FUNCCALL(SETUP_XfOrM259(_), scheme_check_proc_arity2 ("make-output-port" , 3 , 4 , argc , argv , 1 ) ); 
  if (argc > 5 )
    FUNCCALL(SETUP_XfOrM259(_), scheme_check_proc_arity2 ("make-output-port" , 3 , 5 , argc , argv , 1 ) ); 
  if (argc > 6 )
    FUNCCALL(SETUP_XfOrM259(_), scheme_check_proc_arity2 ("make-output-port" , 1 , 6 , argc , argv , 1 ) ); 
  if (argc > 7 )
    FUNCCALL(SETUP_XfOrM259(_), scheme_check_proc_arity2 ("make-output-port" , 0 , 7 , argc , argv , 1 ) ); 
  if (argc > 8 )
    FUNCCALL(SETUP_XfOrM259(_), scheme_check_proc_arity ("make-output-port" , 0 , 8 , argc , argv ) ); 
  if (argc > 9 ) {
#   define XfOrM264_COUNT (0+XfOrM259_COUNT)
#   define SETUP_XfOrM264(x) SETUP_XfOrM259(x)
    if (! (((((long ) (argv [9 ] ) ) & 0x1 ) && (((long ) (argv [9 ] ) ) >> 1 ) > 0 ) || (((Scheme_Type ) (((((long ) (argv [9 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [9 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) && ((& ((Scheme_Bignum * ) argv [9 ] ) -> iso ) -> so . keyex & 0x1 ) ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("make-output-port" , "exact, positive integer" , 9 , argc , argv ) ); 
  }
  if (argc > 10 ) {
#   define XfOrM263_COUNT (0+XfOrM259_COUNT)
#   define SETUP_XfOrM263(x) SETUP_XfOrM259(x)
    if ((! (((argv [10 ] ) ) == (scheme_false ) ) ) && ! FUNCCALL(SETUP_XfOrM263(_), scheme_check_proc_arity (((void * ) 0 ) , 0 , 10 , argc , argv ) )&& ! FUNCCALL(SETUP_XfOrM263(_), scheme_check_proc_arity (((void * ) 0 ) , 1 , 10 , argc , argv ) ))
      FUNCCALL_EMPTY(scheme_wrong_type ("make-output-port" , "procedure (arities 0 and 1)" , 10 , argc , argv ) ); 
  }
  if ((argc > 6 ) && (((argv [4 ] ) ) == (scheme_false ) ) && ! (((argv [6 ] ) ) == (scheme_false ) ) )
    FUNCCALL(SETUP_XfOrM259(_), scheme_arg_mismatch ("make-output-port" , "write-special argument is #f, but write-special-evt argument is not: " , argv [6 ] ) ); 
  if ((argc > 6 ) && (((argv [5 ] ) ) == (scheme_false ) ) && ! (((argv [6 ] ) ) == (scheme_false ) ) )
    FUNCCALL(SETUP_XfOrM259(_), scheme_arg_mismatch ("make-output-port" , "write-evt argument is #f, but write-special-evt argument is not: " , argv [6 ] ) ); 
  if ((argc > 5 ) && ! (((argv [5 ] ) ) == (scheme_false ) ) && ((argc < 7 ) || (((argv [6 ] ) ) == (scheme_false ) ) ) && ! (((argv [4 ] ) ) == (scheme_false ) ) )
    FUNCCALL(SETUP_XfOrM259(_), scheme_arg_mismatch ("make-output-port" , "write-special-evt argument is #f, but write-evt argument is not, and write-special argument is not: " , argv [4 ] ) ); 
  name = argv [0 ] ; 
  uop = ((User_Output_Port * ) FUNCCALL(SETUP_XfOrM259(_), GC_malloc_one_small_tagged ((((sizeof (User_Output_Port ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  uop -> type = scheme_rt_user_output ; 
  uop -> evt = argv [1 ] ; 
  uop -> write_proc = argv [2 ] ; 
  uop -> close_proc = argv [3 ] ; 
  uop -> write_evt_proc = ((argc > 5 ) ? argv [5 ] : scheme_false ) ; 
  if ((((uop -> write_evt_proc ) ) == (scheme_false ) ) )
    uop -> write_evt_proc = ((void * ) 0 ) ; 
  if ((argc < 5 ) || (((argv [4 ] ) ) == (scheme_false ) ) ) {
    uop -> write_special_proc = ((void * ) 0 ) ; 
    uop -> write_special_evt_proc = ((void * ) 0 ) ; 
  }
  else {
    uop -> write_special_proc = argv [4 ] ; 
    uop -> write_special_evt_proc = ((argc > 6 ) ? argv [6 ] : scheme_false ) ; 
    if ((((uop -> write_special_evt_proc ) ) == (scheme_false ) ) )
      uop -> write_special_evt_proc = ((void * ) 0 ) ; 
  }
  if ((argc > 7 ) && (! (((argv [7 ] ) ) == (scheme_false ) ) ) )
    uop -> location_proc = argv [7 ] ; 
  if (argc > 8 )
    uop -> count_lines_proc = argv [8 ] ; 
  if ((argc > 10 ) && (! (((argv [10 ] ) ) == (scheme_false ) ) ) )
    uop -> buffer_mode_proc = argv [10 ] ; 
  op = FUNCCALL(SETUP_XfOrM259(_), scheme_make_output_port (scheme_user_output_port_type , uop , name , uop -> write_evt_proc ? user_write_bytes_evt : ((void * ) 0 ) , user_write_bytes , user_write_ready , user_close_output , user_needs_wakeup_output , uop -> write_special_evt_proc ? user_write_special_evt : ((void * ) 0 ) , uop -> write_special_proc ? user_write_special : ((void * ) 0 ) , 0 ) ); 
  if (uop -> location_proc )
    FUNCCALL(SETUP_XfOrM259(_), scheme_set_port_location_fun ((Scheme_Port * ) op , user_output_location ) ); 
  if (uop -> count_lines_proc )
    FUNCCALL(SETUP_XfOrM259(_), scheme_set_port_count_lines_fun ((Scheme_Port * ) op , user_output_count_lines ) ); 
  if (argc > 9 ) {
    if ((((long ) (argv [9 ] ) ) & 0x1 ) )
      op -> p . position = ((((long ) (argv [9 ] ) ) >> 1 ) - 1 ) ; 
    else op -> p . position = - 1 ; 
  }
  if (uop -> buffer_mode_proc )
    op -> p . buffer_mode_fun = user_output_buffer_mode ; 
  if (op -> p . count_lines && uop -> count_lines_proc )
    FUNCCALL(SETUP_XfOrM259(_), scheme_apply_multi (uop -> count_lines_proc , 0 , ((void * ) 0 ) ) ); 
  RET_VALUE_START ((Scheme_Object * ) op ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * open_input_file (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_do_open_input_file ("open-input-file" , 0 , argc , argv ) ; 
}
static Scheme_Object * open_input_byte_string (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * o ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(argv, 1)));
# define XfOrM267_COUNT (2)
# define SETUP_XfOrM267(x) SETUP(XfOrM267_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  o = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("open-input-bytes" , "byte string" , 0 , argc , argv ) ); 
  o = FUNCCALL(SETUP_XfOrM267(_), scheme_make_sized_byte_string_input_port ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) , (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . tag_val ) ) ); 
  if (argc > 1 )
    ((Scheme_Input_Port * ) o ) -> name = argv [1 ] ; 
  RET_VALUE_START (o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * open_input_char_string (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * o ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(argv, 1)));
# define XfOrM268_COUNT (2)
# define SETUP_XfOrM268(x) SETUP(XfOrM268_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  o = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("open-input-string" , "string" , 0 , argc , argv ) ); 
  o = FUNCCALL(SETUP_XfOrM268(_), scheme_char_string_to_byte_string (argv [0 ] ) ); 
  o = FUNCCALL_AGAIN(scheme_make_sized_byte_string_input_port ((((Scheme_Simple_Object * ) (o ) ) -> u . byte_str_val . string_val ) , (((Scheme_Simple_Object * ) (o ) ) -> u . byte_str_val . tag_val ) ) ); 
  if (argc > 1 )
    ((Scheme_Input_Port * ) o ) -> name = argv [1 ] ; 
  RET_VALUE_START (o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * open_output_file (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_do_open_output_file ("open-output-file" , 0 , argc , argv , 0 ) ; 
}
static Scheme_Object * open_input_output_file (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_do_open_output_file ("open-input-output-file" , 0 , argc , argv , 1 ) ; 
}
static Scheme_Object * open_output_string (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * o ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(argv, 1)));
# define XfOrM271_COUNT (2)
# define SETUP_XfOrM271(x) SETUP(XfOrM271_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  o = NULLED_OUT ; 
  o = FUNCCALL(SETUP_XfOrM271(_), scheme_make_byte_string_output_port () ); 
  if (argc )
    ((Scheme_Output_Port * ) o ) -> name = argv [0 ] ; 
  RET_VALUE_START (o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * do_get_output_string (const char * who , int is_byte , int argc , Scheme_Object * argv [] ) {
  Scheme_Output_Port * op ; 
  char * s ; 
  long size , startpos , endpos ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(op, 0), PUSH(s, 1), PUSH(argv, 2), PUSH(who, 3)));
# define XfOrM272_COUNT (4)
# define SETUP_XfOrM272(x) SETUP(XfOrM272_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  op = NULLED_OUT ; 
  s = NULLED_OUT ; 
  op = FUNCCALL(SETUP_XfOrM272(_), scheme_output_port_record (argv [0 ] ) ); 
  if (! (scheme_is_output_port (argv [0 ] ) ) || (op -> sub_type != scheme_string_output_port_type ) )
    FUNCCALL_EMPTY(scheme_wrong_type (who , "string output port" , 0 , argc , argv ) ); 
  if (argc > 2 ) {
    long len ; 
    Scheme_Indexed_String * is ; 
#   define XfOrM274_COUNT (0+XfOrM272_COUNT)
#   define SETUP_XfOrM274(x) SETUP_XfOrM272(x)
    is = NULLED_OUT ; 
    is = (Scheme_Indexed_String * ) op -> port_data ; 
    len = is -> index ; 
    if (is -> u . hot > len )
      len = is -> u . hot ; 
    startpos = FUNCCALL(SETUP_XfOrM274(_), scheme_extract_index (who , 2 , argc , argv , len + 1 , 0 ) ); 
    if (argc > 3 ) {
#     define XfOrM275_COUNT (0+XfOrM274_COUNT)
#     define SETUP_XfOrM275(x) SETUP_XfOrM274(x)
      if ((((argv [3 ] ) ) == (scheme_false ) ) )
        endpos = len ; 
      else {
#       define XfOrM278_COUNT (0+XfOrM275_COUNT)
#       define SETUP_XfOrM278(x) SETUP_XfOrM275(x)
        endpos = FUNCCALL(SETUP_XfOrM278(_), scheme_extract_index (who , 3 , argc , argv , len + 1 , 1 ) ); 
        if (endpos < 0 )
          endpos = len + 1 ; 
      }
      if (! (startpos <= len ) ) {
#       define XfOrM277_COUNT (0+XfOrM275_COUNT)
#       define SETUP_XfOrM277(x) SETUP_XfOrM275(x)
        FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: starting index %V out of range [%d, %d] for port: %V" , who , argv [2 ] , 0 , len , argv [0 ] ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      if (! (endpos >= startpos && endpos <= len ) ) {
#       define XfOrM276_COUNT (0+XfOrM275_COUNT)
#       define SETUP_XfOrM276(x) SETUP_XfOrM275(x)
        FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: ending index %V out of range [%d, %d] for port: %V" , who , argv [3 ] , startpos , len , argv [0 ] ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
    }
    else endpos = - 1 ; 
  }
  else {
    startpos = 0 ; 
    endpos = - 1 ; 
  }
  s = FUNCCALL(SETUP_XfOrM272(_), scheme_get_reset_sized_byte_string_output (argv [0 ] , & size , ((argc > 1 ) && (! (((argv [1 ] ) ) == (scheme_false ) ) ) ) , startpos , endpos ) ); 
  if (is_byte )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_byte_string (s , size , 0 ) )) RET_VALUE_EMPTY_END ; 
  else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_utf8_string (s , size ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * get_output_byte_string (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_get_output_string ("get-output-bytes" , 1 , argc , argv ) ; 
}
static Scheme_Object * get_output_char_string (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_get_output_string ("get-output-string" , 0 , argc , argv ) ; 
}
static Scheme_Object * close_input_port (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! scheme_is_input_port (argv [0 ] ) )
    scheme_wrong_type ("close-input-port" , "input-port" , 0 , argc , argv ) ; 
  scheme_close_input_port (argv [0 ] ) ; 
  return (scheme_void ) ; 
}
static Scheme_Object * close_output_port (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! scheme_is_output_port (argv [0 ] ) )
    scheme_wrong_type ("close-output-port" , "output-port" , 0 , argc , argv ) ; 
  scheme_close_output_port (argv [0 ] ) ; 
  return (scheme_void ) ; 
}
static Scheme_Object * call_with_output_file (int argc , Scheme_Object * argv [] ) {
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * port , * v , * * m ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(m, 0), PUSH(v, 1), PUSH(port, 2), PUSH(p, 3), PUSH(argv, 4)));
# define XfOrM283_COUNT (5)
# define SETUP_XfOrM283(x) SETUP(XfOrM283_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  port = NULLED_OUT ; 
  v = NULLED_OUT ; 
  m = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM283(_), scheme_check_proc_arity ("call-with-output-file" , 1 , 1 , argc , argv ) ); 
  port = FUNCCALL_AGAIN(scheme_do_open_output_file ("call-with-output-file" , 1 , argc , argv , 0 ) ); 
  v = FUNCCALL_AGAIN(scheme_do_eval (argv [1 ] , 1 , & port , - 1 ) ); 
  m = p -> ku . multiple . array ; 
  if (v == ((Scheme_Object * ) 0x6 ) ) {
    if (((m ) == (p -> values_buffer ) ) )
      p -> values_buffer = ((void * ) 0 ) ; 
  }
  FUNCCALL(SETUP_XfOrM283(_), scheme_close_output_port (port ) ); 
  p -> ku . multiple . array = m ; 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * call_with_input_file (int argc , Scheme_Object * argv [] ) {
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * port , * v , * * m ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(m, 0), PUSH(v, 1), PUSH(port, 2), PUSH(p, 3), PUSH(argv, 4)));
# define XfOrM285_COUNT (5)
# define SETUP_XfOrM285(x) SETUP(XfOrM285_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  port = NULLED_OUT ; 
  v = NULLED_OUT ; 
  m = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM285(_), scheme_check_proc_arity ("call-with-input-file" , 1 , 1 , argc , argv ) ); 
  port = FUNCCALL_AGAIN(scheme_do_open_input_file ("call-with-input-file" , 1 , argc , argv ) ); 
  v = FUNCCALL_AGAIN(scheme_do_eval (argv [1 ] , 1 , & port , - 1 ) ); 
  m = p -> ku . multiple . array ; 
  if (v == ((Scheme_Object * ) 0x6 ) ) {
    if (((m ) == (p -> values_buffer ) ) )
      p -> values_buffer = ((void * ) 0 ) ; 
  }
  FUNCCALL(SETUP_XfOrM285(_), scheme_close_input_port (port ) ); 
  p -> ku . multiple . array = m ; 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * with_call_thunk (void * d ) {
  /* No conversion */
  return scheme_do_eval ((((Scheme_Simple_Object * ) ((Scheme_Object * ) d ) ) -> u . pair_val . car ) , 0 , ((void * ) 0 ) , - 1 ) ; 
}
static void with_close_output (void * d ) {
  /* No conversion */
  scheme_close_output_port ((((Scheme_Simple_Object * ) ((Scheme_Object * ) d ) ) -> u . pair_val . cdr ) ) ; 
}
static Scheme_Object * with_output_to_file (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * port , * v ; 
  Scheme_Cont_Frame_Data cframe ; 
  Scheme_Config * config ; 
  Scheme_Config * __funcarg107 = NULLED_OUT ; 
  Scheme_Object * __funcarg106 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(port, 1), PUSH(config, 2), PUSH(cframe.cache, 3), PUSH(argv, 4)));
# define XfOrM289_COUNT (5)
# define SETUP_XfOrM289(x) SETUP(XfOrM289_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  port = NULLED_OUT ; 
  v = NULLED_OUT ; 
  cframe.cache = NULLED_OUT ; 
  config = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM289(_), scheme_check_proc_arity ("with-output-to-file" , 0 , 1 , argc , argv ) ); 
  port = FUNCCALL_AGAIN(scheme_do_open_output_file ("with-output-to-file" , 1 , argc , argv , 0 ) ); 
  config = (__funcarg107 = FUNCCALL(SETUP_XfOrM289(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_extend_config (__funcarg107 , MZCONFIG_OUTPUT_PORT , port ) )) ; 
  FUNCCALL_AGAIN(scheme_push_continuation_frame (& cframe ) ); 
  FUNCCALL_AGAIN(scheme_set_cont_mark (scheme_parameterization_key , (Scheme_Object * ) config ) ); 
  v = (__funcarg106 = FUNCCALL(SETUP_XfOrM289(_), scheme_make_pair (argv [1 ] , port ) ), FUNCCALL_AGAIN(scheme_dynamic_wind (((void * ) 0 ) , with_call_thunk , with_close_output , ((void * ) 0 ) , __funcarg106 ) )) ; 
  FUNCCALL_AGAIN(scheme_pop_continuation_frame (& cframe ) ); 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void with_close_input (void * d ) {
  /* No conversion */
  scheme_close_input_port ((((Scheme_Simple_Object * ) ((Scheme_Object * ) d ) ) -> u . pair_val . cdr ) ) ; 
}
static Scheme_Object * with_input_from_file (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * port , * v ; 
  Scheme_Cont_Frame_Data cframe ; 
  Scheme_Config * config ; 
  Scheme_Config * __funcarg109 = NULLED_OUT ; 
  Scheme_Object * __funcarg108 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(port, 1), PUSH(config, 2), PUSH(cframe.cache, 3), PUSH(argv, 4)));
# define XfOrM291_COUNT (5)
# define SETUP_XfOrM291(x) SETUP(XfOrM291_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  port = NULLED_OUT ; 
  v = NULLED_OUT ; 
  cframe.cache = NULLED_OUT ; 
  config = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM291(_), scheme_check_proc_arity ("with-input-from-file" , 0 , 1 , argc , argv ) ); 
  port = FUNCCALL_AGAIN(scheme_do_open_input_file ("with-input-from-file" , 1 , argc , argv ) ); 
  config = (__funcarg109 = FUNCCALL(SETUP_XfOrM291(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_extend_config (__funcarg109 , MZCONFIG_INPUT_PORT , port ) )) ; 
  FUNCCALL_AGAIN(scheme_push_continuation_frame (& cframe ) ); 
  FUNCCALL_AGAIN(scheme_set_cont_mark (scheme_parameterization_key , (Scheme_Object * ) config ) ); 
  v = (__funcarg108 = FUNCCALL(SETUP_XfOrM291(_), scheme_make_pair (argv [1 ] , port ) ), FUNCCALL_AGAIN(scheme_dynamic_wind (((void * ) 0 ) , with_call_thunk , with_close_input , ((void * ) 0 ) , __funcarg108 ) )) ; 
  FUNCCALL_AGAIN(scheme_pop_continuation_frame (& cframe ) ); 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * sch_default_read_handler (void * ignore , int argc , Scheme_Object * argv [] ) {
  Scheme_Object * src ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(src, 0), PUSH(argv, 1)));
# define XfOrM292_COUNT (2)
# define SETUP_XfOrM292(x) SETUP(XfOrM292_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  src = NULLED_OUT ; 
  if (! (scheme_is_input_port (argv [0 ] ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("default-port-read-handler" , "input-port" , 0 , argc , argv ) ); 
  if ((Scheme_Object * ) argv [0 ] == scheme_orig_stdin_port )
    FUNCCALL(SETUP_XfOrM292(_), scheme_flush_orig_outputs () ); 
  if (argc > 1 )
    src = argv [1 ] ; 
  else src = ((void * ) 0 ) ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_internal_read (argv [0 ] , src , - 1 , 0 , 0 , 0 , 0 , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int extract_recur_args (const char * who , int argc , Scheme_Object * * argv , int delta , Scheme_Object * * _readtable , int * _recur_graph ) {
  /* No conversion */
  int pre_char = - 1 ; 
  if (argc > delta + 1 ) {
    if ((! (((argv [delta + 1 ] ) ) == (scheme_false ) ) ) ) {
      if (! ((Scheme_Type ) (((((long ) (argv [delta + 1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [delta + 1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_type ) ) )
        scheme_wrong_type (who , "character or #f" , delta + 1 , argc , argv ) ; 
      pre_char = (((Scheme_Small_Object * ) (argv [delta + 1 ] ) ) -> u . char_val ) ; 
    }
    if (argc > delta + 2 ) {
      Scheme_Object * readtable ; 
      readtable = argv [delta + 2 ] ; 
      if ((! (((readtable ) ) == (scheme_false ) ) ) && ! ((Scheme_Type ) (scheme_readtable_type ) == (Scheme_Type ) (((((long ) (readtable ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (readtable ) ) -> type ) ) ) ) {
        scheme_wrong_type (who , "readtable or #f" , delta + 2 , argc , argv ) ; 
      }
      * _readtable = readtable ; 
      if (argc > delta + 3 ) {
        * _recur_graph = (! (((argv [delta + 3 ] ) ) == (scheme_false ) ) ) ; 
      }
    }
  }
  return pre_char ; 
}
static Scheme_Object * do_read_f (const char * who , int argc , Scheme_Object * argv [] , int honu_mode , int recur ) {
  Scheme_Object * port , * readtable = ((void * ) 0 ) ; 
  int pre_char = - 1 , recur_graph = recur ; 
  Scheme_Input_Port * ip ; 
  Scheme_Config * __funcarg110 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(readtable, 0), PUSH(port, 1), PUSH(ip, 2), PUSH(argv, 3), PUSH(who, 4)));
# define XfOrM299_COUNT (5)
# define SETUP_XfOrM299(x) SETUP(XfOrM299_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  port = NULLED_OUT ; 
  ip = NULLED_OUT ; 
  if (argc && ! (scheme_is_input_port (argv [0 ] ) ) )
    FUNCCALL(SETUP_XfOrM299(_), scheme_wrong_type (who , "input-port" , 0 , argc , argv ) ); 
  if (argc )
    port = argv [0 ] ; 
  else port = (__funcarg110 = FUNCCALL(SETUP_XfOrM299(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg110 , MZCONFIG_INPUT_PORT ) )) ; 
  if (recur && ! honu_mode ) {
#   define XfOrM302_COUNT (0+XfOrM299_COUNT)
#   define SETUP_XfOrM302(x) SETUP_XfOrM299(x)
    pre_char = FUNCCALL(SETUP_XfOrM302(_), extract_recur_args (who , argc , argv , 0 , & readtable , & recur_graph ) ); 
  }
  ip = FUNCCALL(SETUP_XfOrM299(_), scheme_input_port_record (port ) ); 
  if (ip -> read_handler && ! honu_mode && ! recur ) {
    Scheme_Object * o [1 ] ; 
    BLOCK_SETUP((PUSHARRAY(o, 1, 0+XfOrM299_COUNT)));
#   define XfOrM301_COUNT (3+XfOrM299_COUNT)
#   define SETUP_XfOrM301(x) SETUP(XfOrM301_COUNT)
    o[0] = NULLED_OUT ; 
    o [0 ] = port ; 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM301(_), scheme_do_eval (ip -> read_handler , 1 , o , 1 ) )) RET_VALUE_END ; 
  }
  else {
#   define XfOrM300_COUNT (0+XfOrM299_COUNT)
#   define SETUP_XfOrM300(x) SETUP_XfOrM299(x)
    if (port == scheme_orig_stdin_port )
      FUNCCALL(SETUP_XfOrM300(_), scheme_flush_orig_outputs () ); 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM300(_), scheme_internal_read (port , ((void * ) 0 ) , - 1 , 0 , honu_mode , recur_graph , recur , pre_char , readtable , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) ) )) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * read_f (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_read_f ("read" , argc , argv , 0 , 0 ) ; 
}
static Scheme_Object * read_recur_f (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_read_f ("read/recursive" , argc , argv , 0 , 1 ) ; 
}
static Scheme_Object * read_honu_f (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_read_f ("read-honu" , argc , argv , 1 , 0 ) ; 
}
static Scheme_Object * read_honu_recur_f (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_read_f ("read-honu/recursive" , argc , argv , 1 , 1 ) ; 
}
static Scheme_Object * do_read_syntax_f (const char * who , int argc , Scheme_Object * argv [] , int honu_mode , int recur ) {
  Scheme_Object * port , * readtable = ((void * ) 0 ) ; 
  int pre_char = - 1 , recur_graph = recur ; 
  Scheme_Input_Port * ip ; 
  Scheme_Config * __funcarg111 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(9);
  BLOCK_SETUP_TOP((PUSH(readtable, 0), PUSH(port, 1), PUSH(ip, 2), PUSH(argv, 3), PUSH(who, 4)));
# define XfOrM307_COUNT (5)
# define SETUP_XfOrM307(x) SETUP(XfOrM307_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  port = NULLED_OUT ; 
  ip = NULLED_OUT ; 
  if ((argc > 1 ) && ! (scheme_is_input_port (argv [1 ] ) ) )
    FUNCCALL(SETUP_XfOrM307(_), scheme_wrong_type (who , "input-port" , 1 , argc , argv ) ); 
  if (argc > 1 )
    port = argv [1 ] ; 
  else port = (__funcarg111 = FUNCCALL(SETUP_XfOrM307(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg111 , MZCONFIG_INPUT_PORT ) )) ; 
  if (recur && ! honu_mode ) {
#   define XfOrM311_COUNT (0+XfOrM307_COUNT)
#   define SETUP_XfOrM311(x) SETUP_XfOrM307(x)
    pre_char = FUNCCALL(SETUP_XfOrM311(_), extract_recur_args (who , argc , argv , 1 , & readtable , & recur_graph ) ); 
  }
  ip = FUNCCALL(SETUP_XfOrM307(_), scheme_input_port_record (port ) ); 
  if (ip -> read_handler && ! honu_mode && ! recur ) {
    Scheme_Object * o [2 ] , * result ; 
    BLOCK_SETUP((PUSHARRAY(o, 2, 0+XfOrM307_COUNT), PUSH(result, 3+XfOrM307_COUNT)));
#   define XfOrM309_COUNT (4+XfOrM307_COUNT)
#   define SETUP_XfOrM309(x) SETUP(XfOrM309_COUNT)
    o[0] = NULLED_OUT ; 
    o[1] = NULLED_OUT ; 
    result = NULLED_OUT ; 
    o [0 ] = port ; 
    o [1 ] = (argc ? argv [0 ] : ip -> name ) ; 
    result = FUNCCALL(SETUP_XfOrM309(_), scheme_do_eval (ip -> read_handler , 2 , o , 1 ) ); 
    if (((Scheme_Type ) (((((long ) (result ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (result ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) || (((result ) ) == (scheme_eof ) ) )
      RET_VALUE_START (result ) RET_VALUE_END ; 
    else {
#     define XfOrM310_COUNT (0+XfOrM309_COUNT)
#     define SETUP_XfOrM310(x) SETUP_XfOrM309(x)
      o [0 ] = result ; 
      FUNCCALL(SETUP_XfOrM310(_), scheme_wrong_type ("read handler for read-syntax" , "syntax object" , 0 , - 1 , o ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  else {
    Scheme_Object * src ; 
    BLOCK_SETUP((PUSH(src, 0+XfOrM307_COUNT)));
#   define XfOrM308_COUNT (1+XfOrM307_COUNT)
#   define SETUP_XfOrM308(x) SETUP(XfOrM308_COUNT)
    src = NULLED_OUT ; 
    src = (argc ? argv [0 ] : ip -> name ) ; 
    if (port == scheme_orig_stdin_port )
      FUNCCALL(SETUP_XfOrM308(_), scheme_flush_orig_outputs () ); 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM308(_), scheme_internal_read (port , src , - 1 , 0 , honu_mode , recur , recur_graph , pre_char , readtable , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) ) )) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * read_syntax_f (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_read_syntax_f ("read-syntax" , argc , argv , 0 , 0 ) ; 
}
static Scheme_Object * read_syntax_recur_f (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_read_syntax_f ("read-syntax/recursive" , argc , argv , 0 , 1 ) ; 
}
static Scheme_Object * read_honu_syntax_f (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_read_syntax_f ("read-honu-syntax" , argc , argv , 1 , 0 ) ; 
}
static Scheme_Object * read_honu_syntax_recur_f (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_read_syntax_f ("read-honu-syntax/recursive" , argc , argv , 1 , 1 ) ; 
}
static Scheme_Object * do_read_char (char * name , int argc , Scheme_Object * argv [] , int peek , int spec , int is_byte ) {
  Scheme_Object * port ; 
  int ch ; 
  Scheme_Config * __funcarg112 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(name, 0), PUSH(port, 1), PUSH(argv, 2)));
# define XfOrM316_COUNT (3)
# define SETUP_XfOrM316(x) SETUP(XfOrM316_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  port = NULLED_OUT ; 
  if (argc && ! (scheme_is_input_port (argv [0 ] ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type (name , "input-port" , 0 , argc , argv ) ); 
  if (argc )
    port = argv [0 ] ; 
  else port = (__funcarg112 = FUNCCALL(SETUP_XfOrM316(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg112 , MZCONFIG_INPUT_PORT ) )) ; 
  if (peek ) {
    Scheme_Object * skip , * unless_evt = ((void * ) 0 ) ; 
    BLOCK_SETUP((PUSH(unless_evt, 0+XfOrM316_COUNT), PUSH(skip, 1+XfOrM316_COUNT)));
#   define XfOrM321_COUNT (2+XfOrM316_COUNT)
#   define SETUP_XfOrM321(x) SETUP(XfOrM321_COUNT)
    skip = NULLED_OUT ; 
    if (argc > 1 ) {
#     define XfOrM325_COUNT (0+XfOrM321_COUNT)
#     define SETUP_XfOrM325(x) SETUP_XfOrM321(x)
      skip = argv [1 ] ; 
      if (! ((((long ) (skip ) ) & 0x1 ) && ((((long ) (skip ) ) >> 1 ) >= 0 ) ) && ! (((Scheme_Type ) (((((long ) (skip ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (skip ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) && ((& ((Scheme_Bignum * ) skip ) -> iso ) -> so . keyex & 0x1 ) ) ) {
#       define XfOrM330_COUNT (0+XfOrM325_COUNT)
#       define SETUP_XfOrM330(x) SETUP_XfOrM325(x)
        FUNCCALL_EMPTY(scheme_wrong_type (name , "non-negative exact integer" , 1 , argc , argv ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      if (argc > 2 ) {
#       define XfOrM326_COUNT (0+XfOrM325_COUNT)
#       define SETUP_XfOrM326(x) SETUP_XfOrM325(x)
        if ((! (((argv [2 ] ) ) == (scheme_false ) ) ) ) {
#         define XfOrM327_COUNT (0+XfOrM326_COUNT)
#         define SETUP_XfOrM327(x) SETUP_XfOrM326(x)
          unless_evt = argv [2 ] ; 
          if (! ((Scheme_Type ) (((((long ) (unless_evt ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (unless_evt ) ) -> type ) ) == (Scheme_Type ) (scheme_progress_evt_type ) ) ) {
#           define XfOrM329_COUNT (0+XfOrM327_COUNT)
#           define SETUP_XfOrM329(x) SETUP_XfOrM327(x)
            FUNCCALL_EMPTY(scheme_wrong_type (name , "progress evt" , 2 , argc , argv ) ); 
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          }
          if (! ((port ) == ((((Scheme_Simple_Object * ) (unless_evt ) ) -> u . two_ptr_val . ptr1 ) ) ) ) {
#           define XfOrM328_COUNT (0+XfOrM327_COUNT)
#           define SETUP_XfOrM328(x) SETUP_XfOrM327(x)
            FUNCCALL(SETUP_XfOrM328(_), scheme_arg_mismatch (name , "evt is not a progress evt for the given port: " , unless_evt ) ); 
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          }
        }
      }
    }
    else skip = ((void * ) 0 ) ; 
    if (spec ) {
#     define XfOrM323_COUNT (0+XfOrM321_COUNT)
#     define SETUP_XfOrM323(x) SETUP_XfOrM321(x)
      if (is_byte ) {
#       define XfOrM324_COUNT (0+XfOrM323_COUNT)
#       define SETUP_XfOrM324(x) SETUP_XfOrM323(x)
        ch = FUNCCALL(SETUP_XfOrM324(_), scheme_peek_byte_special_ok_skip (port , skip , unless_evt ) ); 
      }
      else ch = FUNCCALL(SETUP_XfOrM323(_), scheme_peekc_special_ok_skip (port , skip ) ); 
    }
    else {
#     define XfOrM322_COUNT (0+XfOrM321_COUNT)
#     define SETUP_XfOrM322(x) SETUP_XfOrM321(x)
      if (is_byte )
        ch = FUNCCALL(SETUP_XfOrM322(_), scheme_peek_byte_skip (port , skip , unless_evt ) ); 
      else ch = FUNCCALL(SETUP_XfOrM322(_), scheme_peekc_skip (port , skip ) ); 
    }
  }
  else {
#   define XfOrM318_COUNT (0+XfOrM316_COUNT)
#   define SETUP_XfOrM318(x) SETUP_XfOrM316(x)
    if (spec ) {
#     define XfOrM320_COUNT (0+XfOrM318_COUNT)
#     define SETUP_XfOrM320(x) SETUP_XfOrM318(x)
      if (is_byte )
        ch = FUNCCALL(SETUP_XfOrM320(_), scheme_get_byte_special_ok (port ) ); 
      else ch = FUNCCALL(SETUP_XfOrM320(_), scheme_getc_special_ok (port ) ); 
    }
    else {
#     define XfOrM319_COUNT (0+XfOrM318_COUNT)
#     define SETUP_XfOrM319(x) SETUP_XfOrM318(x)
      if (is_byte )
        ch = FUNCCALL(SETUP_XfOrM319(_), scheme_get_byte (port ) ); 
      else ch = FUNCCALL(SETUP_XfOrM319(_), scheme_getc (port ) ); 
    }
  }
  if (ch == (- 2 ) ) {
#   define XfOrM317_COUNT (0+XfOrM316_COUNT)
#   define SETUP_XfOrM317(x) SETUP_XfOrM316(x)
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_get_ready_special (port , ((void * ) 0 ) , peek ) )) RET_VALUE_EMPTY_END ; 
  }
  else if (ch == (- 1 ) )
    RET_VALUE_START (scheme_eof ) RET_VALUE_END ; 
  else if (is_byte )
    RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (ch ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
  else RET_VALUE_START (((((mzchar ) ch ) < 256 ) ? scheme_char_constants [(unsigned char ) (ch ) ] : FUNCCALL_EMPTY(scheme_make_char (ch ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * read_char (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_read_char ("read-char" , argc , argv , 0 , 0 , 0 ) ; 
}
static Scheme_Object * read_char_spec (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_read_char ("read-char-or-special" , argc , argv , 0 , 1 , 0 ) ; 
}
static Scheme_Object * peek_char (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_read_char ("peek-char" , argc , argv , 1 , 0 , 0 ) ; 
}
static Scheme_Object * peek_char_spec (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_read_char ("peek-char-or-special" , argc , argv , 1 , 1 , 0 ) ; 
}
static Scheme_Object * read_byte (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_read_char ("read-byte" , argc , argv , 0 , 0 , 1 ) ; 
}
static Scheme_Object * read_byte_spec (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_read_char ("read-byte-or-special" , argc , argv , 0 , 1 , 1 ) ; 
}
static Scheme_Object * peek_byte (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_read_char ("peek-byte" , argc , argv , 1 , 0 , 1 ) ; 
}
static Scheme_Object * peek_byte_spec (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_read_char ("peek-byte-or-special" , argc , argv , 1 , 1 , 1 ) ; 
}
static Scheme_Object * do_read_line (int as_bytes , const char * who , int argc , Scheme_Object * argv [] ) {
  Scheme_Object * port ; 
  int ch ; 
  int crlf = 0 , cr = 0 , lf = 1 ; 
  char * buf , * oldbuf , onstack [32 ] ; 
  long size = 31 , oldsize , i = 0 ; 
  Scheme_Config * __funcarg113 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(oldbuf, 0), PUSH(buf, 1), PUSH(port, 2)));
# define XfOrM339_COUNT (3)
# define SETUP_XfOrM339(x) SETUP(XfOrM339_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  port = NULLED_OUT ; 
  buf = NULLED_OUT ; 
  oldbuf = NULLED_OUT ; 
  if (argc && ! (scheme_is_input_port (argv [0 ] ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type (who , "input-port" , 0 , argc , argv ) ); 
  if (argc > 1 ) {
    Scheme_Object * v = argv [1 ] ; 
#   define XfOrM358_COUNT (0+XfOrM339_COUNT)
#   define SETUP_XfOrM358(x) SETUP_XfOrM339(x)
    if (((v ) == (any_symbol ) ) ) {
      crlf = cr = lf = 1 ; 
    }
    else if (((v ) == (any_one_symbol ) ) ) {
      crlf = 0 ; 
      cr = lf = 1 ; 
    }
    else if (((v ) == (cr_symbol ) ) ) {
      crlf = lf = 0 ; 
      cr = 1 ; 
    }
    else if (((v ) == (lf_symbol ) ) ) {
      crlf = cr = 0 ; 
      lf = 1 ; 
    }
    else if (((v ) == (crlf_symbol ) ) ) {
      lf = cr = 0 ; 
      crlf = 1 ; 
    }
    else FUNCCALL_EMPTY(scheme_wrong_type (who , "newline specification symbol" , 1 , argc , argv ) ); 
  }
  if (argc )
    port = argv [0 ] ; 
  else port = (__funcarg113 = FUNCCALL(SETUP_XfOrM339(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg113 , MZCONFIG_INPUT_PORT ) )) ; 
  if ((Scheme_Object * ) port == scheme_orig_stdin_port )
    FUNCCALL(SETUP_XfOrM339(_), scheme_flush_orig_outputs () ); 
  buf = onstack ; 
  while (1 ) {
#   define XfOrM350_COUNT (0+XfOrM339_COUNT)
#   define SETUP_XfOrM350(x) SETUP_XfOrM339(x)
    ch = FUNCCALL(SETUP_XfOrM350(_), scheme_get_byte (port ) ); 
    if (ch == (- 1 ) ) {
      if (! i )
        RET_VALUE_START (scheme_eof ) RET_VALUE_END ; 
      break ; 
    }
    if (ch == '\r' ) {
#     define XfOrM353_COUNT (0+XfOrM350_COUNT)
#     define SETUP_XfOrM353(x) SETUP_XfOrM350(x)
      if (crlf ) {
        int ch2 ; 
#       define XfOrM355_COUNT (0+XfOrM353_COUNT)
#       define SETUP_XfOrM355(x) SETUP_XfOrM353(x)
        ch2 = FUNCCALL(SETUP_XfOrM355(_), scheme_peek_byte_skip (port , ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) , ((void * ) 0 ) ) ); 
        if (ch2 == '\n' ) {
#         define XfOrM356_COUNT (0+XfOrM355_COUNT)
#         define SETUP_XfOrM356(x) SETUP_XfOrM355(x)
          FUNCCALL(SETUP_XfOrM356(_), scheme_get_byte (port ) ); 
          break ; 
        }
        else if (cr )
          break ; 
      }
      else {
        if (cr )
          break ; 
      }
    }
    else if (ch == '\n' ) {
      if (lf )
        break ; 
    }
    if (i >= size ) {
#     define XfOrM351_COUNT (0+XfOrM350_COUNT)
#     define SETUP_XfOrM351(x) SETUP_XfOrM350(x)
      oldsize = size ; 
      oldbuf = buf ; 
      size *= 2 ; 
      buf = (char * ) FUNCCALL(SETUP_XfOrM351(_), GC_malloc_atomic (size + 1 ) ); 
      (memcpy (buf , oldbuf , oldsize ) ) ; 
    }
    buf [i ++ ] = ch ; 
  }
  if (as_bytes ) {
#   define XfOrM341_COUNT (0+XfOrM339_COUNT)
#   define SETUP_XfOrM341(x) SETUP_XfOrM339(x)
    buf [i ] = '\0' ; 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_byte_string (buf , i , buf == (char * ) onstack ) )) RET_VALUE_EMPTY_END ; 
  }
  else {
#   define XfOrM340_COUNT (0+XfOrM339_COUNT)
#   define SETUP_XfOrM340(x) SETUP_XfOrM339(x)
    buf [i ] = '\0' ; 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_utf8_string (buf , i ) )) RET_VALUE_EMPTY_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * read_line (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_read_line (0 , "read-line" , argc , argv ) ; 
}
static Scheme_Object * read_byte_line (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_read_line (1 , "read-byte-line" , argc , argv ) ; 
}
static Scheme_Object * do_general_read_bytes (int as_bytes , const char * who , int argc , Scheme_Object * argv [] , int alloc_mode , int only_avail , int peek ) {
  Scheme_Object * port , * str , * peek_skip , * unless_evt = ((void * ) 0 ) ; 
  long size , start , finish , got ; 
  int delta , size_too_big = 0 ; 
  Scheme_Config * __funcarg115 = NULLED_OUT ; 
  char * __funcarg114 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(unless_evt, 0), PUSH(port, 1), PUSH(peek_skip, 2), PUSH(str, 3), PUSH(who, 4), PUSH(argv, 5)));
# define XfOrM366_COUNT (6)
# define SETUP_XfOrM366(x) SETUP(XfOrM366_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  port = NULLED_OUT ; 
  str = NULLED_OUT ; 
  peek_skip = NULLED_OUT ; 
  if (alloc_mode ) {
#   define XfOrM391_COUNT (0+XfOrM366_COUNT)
#   define SETUP_XfOrM391(x) SETUP_XfOrM366(x)
    if (! (((long ) (argv [0 ] ) ) & 0x1 ) ) {
      if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) {
        size = 1 ; 
        size_too_big = 1 ; 
      }
      else size = - 1 ; 
    }
    else size = (((long ) (argv [0 ] ) ) >> 1 ) ; 
    if (size < 0 ) {
#     define XfOrM392_COUNT (0+XfOrM391_COUNT)
#     define SETUP_XfOrM392(x) SETUP_XfOrM391(x)
      FUNCCALL_EMPTY(scheme_wrong_type (who , "non-negative exact integer" , 0 , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    str = ((void * ) 0 ) ; 
  }
  else {
#   define XfOrM386_COUNT (0+XfOrM366_COUNT)
#   define SETUP_XfOrM386(x) SETUP_XfOrM366(x)
    if (as_bytes ) {
#     define XfOrM389_COUNT (0+XfOrM386_COUNT)
#     define SETUP_XfOrM389(x) SETUP_XfOrM386(x)
      if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) && (! (((Scheme_Inclhash_Object * ) (argv [0 ] ) ) -> so . keyex & 0x1 ) ) ) ) {
#       define XfOrM390_COUNT (0+XfOrM389_COUNT)
#       define SETUP_XfOrM390(x) SETUP_XfOrM389(x)
        FUNCCALL_EMPTY(scheme_wrong_type (who , "mutable byte string" , 0 , argc , argv ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
    }
    else {
#     define XfOrM387_COUNT (0+XfOrM386_COUNT)
#     define SETUP_XfOrM387(x) SETUP_XfOrM386(x)
      if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) && (! (((Scheme_Inclhash_Object * ) (argv [0 ] ) ) -> so . keyex & 0x1 ) ) ) ) {
#       define XfOrM388_COUNT (0+XfOrM387_COUNT)
#       define SETUP_XfOrM388(x) SETUP_XfOrM387(x)
        FUNCCALL_EMPTY(scheme_wrong_type (who , "mutable string" , 0 , argc , argv ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
    }
    str = argv [0 ] ; 
    size = 0 ; 
  }
  if (peek ) {
    Scheme_Object * v ; 
#   define XfOrM381_COUNT (0+XfOrM366_COUNT)
#   define SETUP_XfOrM381(x) SETUP_XfOrM366(x)
    v = NULLED_OUT ; 
    v = argv [1 ] ; 
    if ((((long ) (v ) ) & 0x1 ) && ((((long ) (v ) ) >> 1 ) >= 0 ) )
      peek_skip = v ; 
    else if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) && ((& ((Scheme_Bignum * ) v ) -> iso ) -> so . keyex & 0x1 ) )
      peek_skip = v ; 
    else {
#     define XfOrM385_COUNT (0+XfOrM381_COUNT)
#     define SETUP_XfOrM385(x) SETUP_XfOrM381(x)
      FUNCCALL_EMPTY(scheme_wrong_type (who , "non-negative exact integer" , 1 , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    if (only_avail ) {
#     define XfOrM382_COUNT (0+XfOrM381_COUNT)
#     define SETUP_XfOrM382(x) SETUP_XfOrM381(x)
      if ((! (((argv [2 ] ) ) == (scheme_false ) ) ) ) {
#       define XfOrM383_COUNT (0+XfOrM382_COUNT)
#       define SETUP_XfOrM383(x) SETUP_XfOrM382(x)
        unless_evt = argv [2 ] ; 
        if (! ((Scheme_Type ) (((((long ) (unless_evt ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (unless_evt ) ) -> type ) ) == (Scheme_Type ) (scheme_progress_evt_type ) ) ) {
#         define XfOrM384_COUNT (0+XfOrM383_COUNT)
#         define SETUP_XfOrM384(x) SETUP_XfOrM383(x)
          FUNCCALL_EMPTY(scheme_wrong_type (who , "progress evt or #f" , 2 , argc , argv ) ); 
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        }
      }
      delta = 2 ; 
    }
    else delta = 1 ; 
  }
  else {
    peek_skip = ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
    delta = 0 ; 
  }
  if ((argc > (1 + delta ) ) && ! (scheme_is_input_port (argv [1 + delta ] ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type (who , "input-port" , 1 + delta , argc , argv ) ); 
  if (alloc_mode ) {
    start = 0 ; 
    finish = size ; 
  }
  else {
#   define XfOrM378_COUNT (0+XfOrM366_COUNT)
#   define SETUP_XfOrM378(x) SETUP_XfOrM366(x)
    FUNCCALL(SETUP_XfOrM378(_), scheme_get_substring_indices (who , str , argc , argv , 2 + delta , 3 + delta , & start , & finish ) ); 
    size = finish - start ; 
  }
  if (argc > (delta + 1 ) )
    port = argv [delta + 1 ] ; 
  else port = (__funcarg115 = FUNCCALL(SETUP_XfOrM366(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg115 , MZCONFIG_INPUT_PORT ) )) ; 
  if (unless_evt ) {
#   define XfOrM376_COUNT (0+XfOrM366_COUNT)
#   define SETUP_XfOrM376(x) SETUP_XfOrM366(x)
    if (! ((port ) == ((((Scheme_Simple_Object * ) (unless_evt ) ) -> u . two_ptr_val . ptr1 ) ) ) ) {
#     define XfOrM377_COUNT (0+XfOrM376_COUNT)
#     define SETUP_XfOrM377(x) SETUP_XfOrM376(x)
      FUNCCALL(SETUP_XfOrM377(_), scheme_arg_mismatch (who , "evt is not a progress evt for the given port: " , unless_evt ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  if ((Scheme_Object * ) port == scheme_orig_stdin_port )
    FUNCCALL(SETUP_XfOrM366(_), scheme_flush_orig_outputs () ); 
  if (! size ) {
#   define XfOrM374_COUNT (0+XfOrM366_COUNT)
#   define SETUP_XfOrM374(x) SETUP_XfOrM366(x)
    if (alloc_mode ) {
#     define XfOrM375_COUNT (0+XfOrM374_COUNT)
#     define SETUP_XfOrM375(x) SETUP_XfOrM374(x)
      if (as_bytes )
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_byte_string ("" , 0 , 0 ) )) RET_VALUE_EMPTY_END ; 
      else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_char_string ((mzchar * ) "\0\0\0" , 0 , 0 ) )) RET_VALUE_EMPTY_END ; 
    }
    else RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
  }
  if (alloc_mode ) {
#   define XfOrM372_COUNT (0+XfOrM366_COUNT)
#   define SETUP_XfOrM372(x) SETUP_XfOrM366(x)
    if (size_too_big ) {
#     define XfOrM373_COUNT (0+XfOrM372_COUNT)
#     define SETUP_XfOrM373(x) SETUP_XfOrM372(x)
      (__funcarg114 = FUNCCALL(SETUP_XfOrM373(_), scheme_make_provided_string (argv [0 ] , 0 , ((void * ) 0 ) ) ), FUNCCALL_EMPTY(scheme_raise_out_of_memory (who , "making string of length %s" , __funcarg114 ) )) ; 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    if (as_bytes )
      str = FUNCCALL(SETUP_XfOrM372(_), scheme_alloc_byte_string (size , 0 ) ); 
    else str = FUNCCALL(SETUP_XfOrM372(_), scheme_alloc_char_string (size , 0 ) ); 
  }
  if (as_bytes ) {
#   define XfOrM370_COUNT (0+XfOrM366_COUNT)
#   define SETUP_XfOrM370(x) SETUP_XfOrM366(x)
    got = FUNCCALL(SETUP_XfOrM370(_), scheme_get_byte_string_special_ok_unless (who , port , (((Scheme_Simple_Object * ) (str ) ) -> u . byte_str_val . string_val ) , start , size , only_avail , peek , peek_skip , unless_evt ) ); 
    if (got == (- 2 ) ) {
      Scheme_Object * res ; 
      BLOCK_SETUP((PUSH(res, 0+XfOrM370_COUNT)));
#     define XfOrM371_COUNT (1+XfOrM370_COUNT)
#     define SETUP_XfOrM371(x) SETUP(XfOrM371_COUNT)
      res = NULLED_OUT ; 
      res = FUNCCALL(SETUP_XfOrM371(_), scheme_get_special_proc (port ) ); 
      if (! only_avail )
        FUNCCALL(SETUP_XfOrM371(_), scheme_bad_time_for_special (who , port ) ); 
      RET_VALUE_START (res ) RET_VALUE_END ; 
    }
  }
  else {
#   define XfOrM369_COUNT (0+XfOrM366_COUNT)
#   define SETUP_XfOrM369(x) SETUP_XfOrM366(x)
    got = FUNCCALL(SETUP_XfOrM369(_), scheme_get_char_string (who , port , (((Scheme_Simple_Object * ) (str ) ) -> u . char_str_val . string_val ) , start , size , peek , peek_skip ) ); 
  }
  if (got == (- 1 ) )
    RET_VALUE_START (scheme_eof ) RET_VALUE_END ; 
  if (alloc_mode ) {
#   define XfOrM367_COUNT (0+XfOrM366_COUNT)
#   define SETUP_XfOrM367(x) SETUP_XfOrM366(x)
    if (got < size ) {
#     define XfOrM368_COUNT (0+XfOrM367_COUNT)
#     define SETUP_XfOrM368(x) SETUP_XfOrM367(x)
      if (as_bytes )
        str = FUNCCALL(SETUP_XfOrM368(_), scheme_make_sized_byte_string ((((Scheme_Simple_Object * ) (str ) ) -> u . byte_str_val . string_val ) , got , 1 ) ); 
      else str = FUNCCALL(SETUP_XfOrM368(_), scheme_make_sized_char_string ((((Scheme_Simple_Object * ) (str ) ) -> u . char_str_val . string_val ) , got , 1 ) ); 
    }
    RET_VALUE_START (str ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (got ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * sch_read_bytes (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_general_read_bytes (1 , "read-bytes" , argc , argv , 1 , 0 , 0 ) ; 
}
static Scheme_Object * sch_read_bytes_bang (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_general_read_bytes (1 , "read-bytes!" , argc , argv , 0 , 0 , 0 ) ; 
}
static Scheme_Object * sch_peek_bytes (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_general_read_bytes (1 , "peek-bytes" , argc , argv , 1 , 0 , 1 ) ; 
}
static Scheme_Object * sch_peek_bytes_bang (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_general_read_bytes (1 , "peek-bytes!" , argc , argv , 0 , 0 , 1 ) ; 
}
static Scheme_Object * read_bytes_bang (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_general_read_bytes (1 , "read-bytes-avail!" , argc , argv , 0 , 1 , 0 ) ; 
}
static Scheme_Object * read_bytes_bang_nonblock (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_general_read_bytes (1 , "read-bytes-avail!*" , argc , argv , 0 , 2 , 0 ) ; 
}
static Scheme_Object * peeked_read (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * port , * unless_evt , * target_evt ; 
  long size ; 
  int v ; 
  Scheme_Config * __funcarg116 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(unless_evt, 0), PUSH(target_evt, 1), PUSH(port, 2)));
# define XfOrM401_COUNT (3)
# define SETUP_XfOrM401(x) SETUP(XfOrM401_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  port = NULLED_OUT ; 
  unless_evt = NULLED_OUT ; 
  target_evt = NULLED_OUT ; 
  if (((((long ) (argv [0 ] ) ) & 0x1 ) && ((((long ) (argv [0 ] ) ) >> 1 ) > 0 ) ) || (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) && ((& ((Scheme_Bignum * ) argv [0 ] ) -> iso ) -> so . keyex & 0x1 ) ) ) {
    if ((((long ) (argv [0 ] ) ) & 0x1 ) )
      size = (((long ) (argv [0 ] ) ) >> 1 ) ; 
    else size = 0x7FFFFFFF ; 
  }
  else {
#   define XfOrM405_COUNT (0+XfOrM401_COUNT)
#   define SETUP_XfOrM405(x) SETUP_XfOrM401(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("port-commit-peeked" , "positive exact integer" , 0 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  unless_evt = argv [1 ] ; 
  target_evt = argv [2 ] ; 
  if (! ((Scheme_Type ) (((((long ) (unless_evt ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (unless_evt ) ) -> type ) ) == (Scheme_Type ) (scheme_progress_evt_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("port-commit-peeked" , "progress evt" , 1 , argc , argv ) ); 
  {
    Scheme_Type t ; 
#   define XfOrM404_COUNT (0+XfOrM401_COUNT)
#   define SETUP_XfOrM404(x) SETUP_XfOrM401(x)
    t = ((((long ) (target_evt ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (target_evt ) ) -> type ) ; 
    if (! ((Scheme_Type ) (t ) == (Scheme_Type ) (scheme_sema_type ) ) && ! ((Scheme_Type ) (t ) == (Scheme_Type ) (scheme_channel_type ) ) && ! ((Scheme_Type ) (t ) == (Scheme_Type ) (scheme_channel_put_type ) ) && ! ((Scheme_Type ) (t ) == (Scheme_Type ) (scheme_always_evt_type ) ) && ! ((Scheme_Type ) (t ) == (Scheme_Type ) (scheme_never_evt_type ) ) && ! ((Scheme_Type ) (t ) == (Scheme_Type ) (scheme_semaphore_repost_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("port-commit-peeked" , "channel-put evt, channel, semaphore, semephore-peek evt, always evt, or never evt" , 2 , argc , argv ) ); 
  }
  if (argc > 3 ) {
#   define XfOrM403_COUNT (0+XfOrM401_COUNT)
#   define SETUP_XfOrM403(x) SETUP_XfOrM401(x)
    port = argv [3 ] ; 
    if (! (scheme_is_input_port (port ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("port-commit-peeked" , "input-port" , 3 , argc , argv ) ); 
  }
  else port = (__funcarg116 = FUNCCALL(SETUP_XfOrM401(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg116 , MZCONFIG_INPUT_PORT ) )) ; 
  if (! ((port ) == ((((Scheme_Simple_Object * ) (unless_evt ) ) -> u . two_ptr_val . ptr1 ) ) ) ) {
#   define XfOrM402_COUNT (0+XfOrM401_COUNT)
#   define SETUP_XfOrM402(x) SETUP_XfOrM401(x)
    FUNCCALL(SETUP_XfOrM402(_), scheme_arg_mismatch ("port-commit-peeked" , "evt is not a progress evt for the given port: " , unless_evt ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  v = FUNCCALL_EMPTY(scheme_peeked_read (port , size , unless_evt , target_evt ) ); 
  RET_VALUE_START ((v ? scheme_true : scheme_false ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * peek_bytes_bang (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_general_read_bytes (1 , "peek-bytes-avail!" , argc , argv , 0 , 1 , 1 ) ; 
}
static Scheme_Object * peek_bytes_bang_nonblock (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_general_read_bytes (1 , "peek-bytes-avail!*" , argc , argv , 0 , 2 , 1 ) ; 
}
static Scheme_Object * sch_read_string (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_general_read_bytes (0 , "read-string" , argc , argv , 1 , 0 , 0 ) ; 
}
static Scheme_Object * sch_read_string_bang (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_general_read_bytes (0 , "read-string!" , argc , argv , 0 , 0 , 0 ) ; 
}
static Scheme_Object * sch_peek_string (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_general_read_bytes (0 , "peek-string" , argc , argv , 1 , 0 , 1 ) ; 
}
static Scheme_Object * sch_peek_string_bang (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_general_read_bytes (0 , "peek-string!" , argc , argv , 0 , 0 , 1 ) ; 
}
static Scheme_Object * read_bytes_bang_break (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_general_read_bytes (1 , "read-bytes-avail!/enable-break" , argc , argv , 0 , - 1 , 0 ) ; 
}
static Scheme_Object * peek_bytes_bang_break (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_general_read_bytes (1 , "peek-bytes-avail!/enable-break" , argc , argv , 0 , - 1 , 1 ) ; 
}
static Scheme_Object * progress_evt (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * port , * v ; 
  Scheme_Config * __funcarg117 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(port, 1)));
# define XfOrM415_COUNT (2)
# define SETUP_XfOrM415(x) SETUP(XfOrM415_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  port = NULLED_OUT ; 
  v = NULLED_OUT ; 
  if (argc ) {
#   define XfOrM418_COUNT (0+XfOrM415_COUNT)
#   define SETUP_XfOrM418(x) SETUP_XfOrM415(x)
    if (! (scheme_is_input_port (argv [0 ] ) ) ) {
#     define XfOrM419_COUNT (0+XfOrM418_COUNT)
#     define SETUP_XfOrM419(x) SETUP_XfOrM418(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("port-progress-evt" , "input-port" , 0 , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    port = argv [0 ] ; 
  }
  else {
#   define XfOrM417_COUNT (0+XfOrM415_COUNT)
#   define SETUP_XfOrM417(x) SETUP_XfOrM415(x)
    port = (__funcarg117 = FUNCCALL(SETUP_XfOrM417(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg117 , MZCONFIG_INPUT_PORT ) )) ; 
  }
  v = FUNCCALL(SETUP_XfOrM415(_), scheme_progress_evt (port ) ); 
  if (! v ) {
#   define XfOrM416_COUNT (0+XfOrM415_COUNT)
#   define SETUP_XfOrM416(x) SETUP_XfOrM415(x)
    FUNCCALL(SETUP_XfOrM416(_), scheme_arg_mismatch ("port-progress-evt" , "port does not provide progress evts: " , port ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_write_bytes_avail (int as_bytes , const char * who , int argc , Scheme_Object * argv [] , int rarely_block , int get_evt ) {
  Scheme_Object * port , * str ; 
  long size , start , finish , putten ; 
  Scheme_Config * __funcarg118 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(port, 0), PUSH(str, 1), PUSH(who, 2), PUSH(argv, 3)));
# define XfOrM420_COUNT (4)
# define SETUP_XfOrM420(x) SETUP(XfOrM420_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  port = NULLED_OUT ; 
  str = NULLED_OUT ; 
  if (as_bytes && ! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ) {
#   define XfOrM422_COUNT (0+XfOrM420_COUNT)
#   define SETUP_XfOrM422(x) SETUP_XfOrM420(x)
    FUNCCALL_EMPTY(scheme_wrong_type (who , "byte string" , 0 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  else if (! as_bytes && ! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) ) {
#   define XfOrM421_COUNT (0+XfOrM420_COUNT)
#   define SETUP_XfOrM421(x) SETUP_XfOrM420(x)
    FUNCCALL_EMPTY(scheme_wrong_type (who , "string" , 0 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  else str = argv [0 ] ; 
  if ((argc > 1 ) && ! (scheme_is_output_port (argv [1 ] ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type (who , "output-port" , 1 , argc , argv ) ); 
  FUNCCALL(SETUP_XfOrM420(_), scheme_get_substring_indices (who , str , argc , argv , 2 , 3 , & start , & finish ) ); 
  size = finish - start ; 
  if (argc > 1 )
    port = argv [1 ] ; 
  else port = (__funcarg118 = FUNCCALL(SETUP_XfOrM420(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg118 , MZCONFIG_OUTPUT_PORT ) )) ; 
  if (get_evt )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_write_evt (who , port , ((void * ) 0 ) , (((Scheme_Simple_Object * ) (str ) ) -> u . byte_str_val . string_val ) , start , size ) )) RET_VALUE_EMPTY_END ; 
  else if (as_bytes )
    putten = FUNCCALL(SETUP_XfOrM420(_), scheme_put_byte_string (who , port , (((Scheme_Simple_Object * ) (str ) ) -> u . byte_str_val . string_val ) , start , size , rarely_block ) ); 
  else putten = FUNCCALL_EMPTY(scheme_put_char_string (who , port , (((Scheme_Simple_Object * ) (str ) ) -> u . char_str_val . string_val ) , start , size ) ); 
  if (putten < 0 )
    RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
  else RET_VALUE_START (((Scheme_Object * ) (void * ) (long ) ((((long ) (putten ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * write_bytes (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_write_bytes_avail (1 , "write-bytes" , argc , argv , 0 , 0 ) ; 
}
static Scheme_Object * write_bytes_avail (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_write_bytes_avail (1 , "write-bytes-avail" , argc , argv , 1 , 0 ) ; 
}
static Scheme_Object * write_bytes_avail_break (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_write_bytes_avail (1 , "write-bytes-avail" , argc , argv , - 1 , 0 ) ; 
}
static Scheme_Object * write_bytes_avail_nonblock (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_write_bytes_avail (1 , "write-bytes-avail*" , argc , argv , 2 , 0 ) ; 
}
static Scheme_Object * write_string (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_write_bytes_avail (0 , "write-string" , argc , argv , 0 , 0 ) ; 
}
static Scheme_Object * write_bytes_avail_evt (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_write_bytes_avail (1 , "write-bytes-avail-evt" , argc , argv , 1 , 1 ) ; 
}
static Scheme_Object * do_write_special (const char * name , int argc , Scheme_Object * argv [] , int nonblock , int get_evt ) {
  Scheme_Output_Port * op ; 
  Scheme_Object * port ; 
  int ok ; 
  Scheme_Config * __funcarg119 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(name, 0), PUSH(op, 1), PUSH(port, 2), PUSH(argv, 3)));
# define XfOrM429_COUNT (4)
# define SETUP_XfOrM429(x) SETUP(XfOrM429_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  op = NULLED_OUT ; 
  port = NULLED_OUT ; 
  if (argc > 1 ) {
#   define XfOrM436_COUNT (0+XfOrM429_COUNT)
#   define SETUP_XfOrM436(x) SETUP_XfOrM429(x)
    if (! (scheme_is_output_port (argv [1 ] ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type (name , "output-port" , 1 , argc , argv ) ); 
    port = argv [1 ] ; 
  }
  else port = (__funcarg119 = FUNCCALL(SETUP_XfOrM429(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg119 , MZCONFIG_OUTPUT_PORT ) )) ; 
  op = FUNCCALL(SETUP_XfOrM429(_), scheme_output_port_record (port ) ); 
  if (op -> write_special_fun ) {
#   define XfOrM433_COUNT (0+XfOrM429_COUNT)
#   define SETUP_XfOrM433(x) SETUP_XfOrM429(x)
    if (get_evt ) {
#     define XfOrM435_COUNT (0+XfOrM433_COUNT)
#     define SETUP_XfOrM435(x) SETUP_XfOrM433(x)
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_write_evt (name , port , argv [0 ] , ((void * ) 0 ) , 0 , 0 ) )) RET_VALUE_EMPTY_END ; 
    }
    else {
      Scheme_Write_Special_Fun ws = op -> write_special_fun ; 
#     define XfOrM434_COUNT (0+XfOrM433_COUNT)
#     define SETUP_XfOrM434(x) SETUP_XfOrM433(x)
      ok = FUNCCALL(SETUP_XfOrM434(_), ws (op , argv [0 ] , nonblock ) ); 
    }
  }
  else {
#   define XfOrM432_COUNT (0+XfOrM429_COUNT)
#   define SETUP_XfOrM432(x) SETUP_XfOrM429(x)
    FUNCCALL(SETUP_XfOrM432(_), scheme_arg_mismatch (name , "port does not support special values: " , port ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (ok ) {
    Scheme_Port * ip ; 
    BLOCK_SETUP((PUSH(ip, 0+XfOrM429_COUNT)));
#   define XfOrM430_COUNT (1+XfOrM429_COUNT)
#   define SETUP_XfOrM430(x) SETUP(XfOrM430_COUNT)
    ip = NULLED_OUT ; 
    ip = FUNCCALL(SETUP_XfOrM430(_), scheme_port_record (port ) ); 
    if (ip -> position >= 0 )
      ip -> position += 1 ; 
    if (ip -> count_lines ) {
      ip -> column += 1 ; 
      ip -> readpos += 1 ; 
      ip -> charsSinceNewline += 1 ; 
      ip -> utf8state = 0 ; 
    }
    RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * can_write_atomic (int argc , Scheme_Object * argv [] ) {
  Scheme_Output_Port * op ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(op, 0)));
# define XfOrM437_COUNT (1)
# define SETUP_XfOrM437(x) SETUP(XfOrM437_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  op = NULLED_OUT ; 
  if (! (scheme_is_output_port (argv [0 ] ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("port-writes-atomic?" , "output-port" , 0 , argc , argv ) ); 
  op = FUNCCALL(SETUP_XfOrM437(_), scheme_output_port_record (argv [0 ] ) ); 
  if (op -> write_string_evt_fun )
    RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
  else RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * can_provide_progress_evt (int argc , Scheme_Object * argv [] ) {
  Scheme_Input_Port * ip ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(ip, 0)));
# define XfOrM438_COUNT (1)
# define SETUP_XfOrM438(x) SETUP(XfOrM438_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ip = NULLED_OUT ; 
  if (! (scheme_is_input_port (argv [0 ] ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("port-provides-progress-evt?" , "input-port" , 0 , argc , argv ) ); 
  ip = FUNCCALL(SETUP_XfOrM438(_), scheme_input_port_record (argv [0 ] ) ); 
  if (ip -> progress_evt_fun )
    RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
  else RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * can_write_special (int argc , Scheme_Object * argv [] ) {
  Scheme_Output_Port * op ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(op, 0)));
# define XfOrM439_COUNT (1)
# define SETUP_XfOrM439(x) SETUP(XfOrM439_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  op = NULLED_OUT ; 
  if (! (scheme_is_output_port (argv [0 ] ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("port-writes-special?" , "output-port" , 0 , argc , argv ) ); 
  op = FUNCCALL(SETUP_XfOrM439(_), scheme_output_port_record (argv [0 ] ) ); 
  if (op -> write_special_fun )
    RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
  else RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_write_special (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_write_special ("write-special" , argc , argv , 0 , 0 ) ; 
}
Scheme_Object * scheme_write_special_nonblock (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_write_special ("write-special-avail*" , argc , argv , 1 , 0 ) ; 
}
static Scheme_Object * write_special_evt (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_write_special ("write-special-evt" , argc , argv , 1 , 1 ) ; 
}
Scheme_Object * scheme_call_enable_break (Scheme_Prim * prim , int argc , Scheme_Object * argv [] ) {
  Scheme_Cont_Frame_Data cframe ; 
  Scheme_Object * v ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(prim, 1), PUSH(cframe.cache, 2), PUSH(argv, 3)));
# define XfOrM443_COUNT (4)
# define SETUP_XfOrM443(x) SETUP(XfOrM443_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  cframe.cache = NULLED_OUT ; 
  v = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM443(_), scheme_push_break_enable (& cframe , 1 , 1 ) ); 
  v = FUNCCALL_AGAIN(prim (argc , argv ) ); 
  FUNCCALL_AGAIN(scheme_pop_break_enable (& cframe , 0 ) ); 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * eof_object_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return ((((argv [0 ] ) ) == (scheme_eof ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * char_ready_p (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * port ; 
  Scheme_Config * __funcarg120 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(port, 0)));
# define XfOrM445_COUNT (1)
# define SETUP_XfOrM445(x) SETUP(XfOrM445_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  port = NULLED_OUT ; 
  if (argc && ! (scheme_is_input_port (argv [0 ] ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("char-ready?" , "input-port" , 0 , argc , argv ) ); 
  if (argc )
    port = argv [0 ] ; 
  else port = (__funcarg120 = FUNCCALL(SETUP_XfOrM445(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg120 , MZCONFIG_INPUT_PORT ) )) ; 
  RET_VALUE_START ((FUNCCALL_EMPTY(scheme_char_ready (port ) )? scheme_true : scheme_false ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * byte_ready_p (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * port ; 
  Scheme_Config * __funcarg121 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(port, 0)));
# define XfOrM446_COUNT (1)
# define SETUP_XfOrM446(x) SETUP(XfOrM446_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  port = NULLED_OUT ; 
  if (argc && ! (scheme_is_input_port (argv [0 ] ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("byte-ready?" , "input-port" , 0 , argc , argv ) ); 
  if (argc )
    port = argv [0 ] ; 
  else port = (__funcarg121 = FUNCCALL(SETUP_XfOrM446(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg121 , MZCONFIG_INPUT_PORT ) )) ; 
  RET_VALUE_START ((FUNCCALL_EMPTY(scheme_byte_ready (port ) )? scheme_true : scheme_false ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * sch_default_display_handler (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! scheme_is_output_port (argv [1 ] ) )
    scheme_wrong_type ("default-port-display-handler" , "output-port" , 1 , argc , argv ) ; 
  scheme_internal_display (argv [0 ] , argv [1 ] ) ; 
  return scheme_void ; 
}
static Scheme_Object * sch_default_write_handler (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! scheme_is_output_port (argv [1 ] ) )
    scheme_wrong_type ("default-port-write-handler" , "output-port" , 1 , argc , argv ) ; 
  scheme_internal_write (argv [0 ] , argv [1 ] ) ; 
  return scheme_void ; 
}
static Scheme_Object * sch_default_print_handler (int argc , Scheme_Object * argv [] ) {
  Scheme_Config * __funcarg123 = NULLED_OUT ; 
  Scheme_Object * __funcarg122 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM449_COUNT (1)
# define SETUP_XfOrM449(x) SETUP(XfOrM449_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! (scheme_is_output_port (argv [1 ] ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("default-port-print-handler" , "output-port" , 1 , argc , argv ) ); 
  RET_VALUE_START ((__funcarg122 = (__funcarg123 = FUNCCALL(SETUP_XfOrM449(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg123 , MZCONFIG_PORT_PRINT_HANDLER ) )) , FUNCCALL_EMPTY(scheme_do_eval (__funcarg122 , argc , argv , 1 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * sch_default_global_port_print_handler (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! scheme_is_output_port (argv [1 ] ) )
    scheme_wrong_type ("default-global-port-print-handler" , "output-port" , 1 , argc , argv ) ; 
  scheme_internal_print (argv [0 ] , argv [1 ] ) ; 
  return scheme_void ; 
}
static Scheme_Object * display_write (char * name , int argc , Scheme_Object * argv [] , int escape ) {
  Scheme_Object * port ; 
  Scheme_Output_Port * op ; 
  Scheme_Config * __funcarg124 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(port, 0), PUSH(op, 1), PUSH(argv, 2), PUSH(name, 3)));
# define XfOrM451_COUNT (4)
# define SETUP_XfOrM451(x) SETUP(XfOrM451_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  port = NULLED_OUT ; 
  op = NULLED_OUT ; 
  if (argc > 1 ) {
#   define XfOrM461_COUNT (0+XfOrM451_COUNT)
#   define SETUP_XfOrM461(x) SETUP_XfOrM451(x)
    if (! (scheme_is_output_port (argv [1 ] ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type (name , "output-port" , 1 , argc , argv ) ); 
    port = argv [1 ] ; 
  }
  else port = (__funcarg124 = FUNCCALL(SETUP_XfOrM451(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg124 , MZCONFIG_OUTPUT_PORT ) )) ; 
  op = FUNCCALL(SETUP_XfOrM451(_), scheme_output_port_record (port ) ); 
  if (escape > 0 ) {
#   define XfOrM455_COUNT (0+XfOrM451_COUNT)
#   define SETUP_XfOrM455(x) SETUP_XfOrM451(x)
    if (! op -> display_handler ) {
      Scheme_Object * v = argv [0 ] ; 
      BLOCK_SETUP((PUSH(v, 0+XfOrM455_COUNT)));
#     define XfOrM457_COUNT (1+XfOrM455_COUNT)
#     define SETUP_XfOrM457(x) SETUP(XfOrM457_COUNT)
      if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ) {
#       define XfOrM460_COUNT (0+XfOrM457_COUNT)
#       define SETUP_XfOrM460(x) SETUP_XfOrM457(x)
        FUNCCALL(SETUP_XfOrM460(_), scheme_put_byte_string (name , port , (((Scheme_Simple_Object * ) (v ) ) -> u . byte_str_val . string_val ) , 0 , (((Scheme_Simple_Object * ) (v ) ) -> u . byte_str_val . tag_val ) , 0 ) ); 
      }
      else if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) ) {
#       define XfOrM459_COUNT (0+XfOrM457_COUNT)
#       define SETUP_XfOrM459(x) SETUP_XfOrM457(x)
        FUNCCALL(SETUP_XfOrM459(_), scheme_put_char_string (name , port , (((Scheme_Simple_Object * ) (v ) ) -> u . char_str_val . string_val ) , 0 , (((Scheme_Simple_Object * ) (v ) ) -> u . char_str_val . tag_val ) ) ); 
      }
      else if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
#       define XfOrM458_COUNT (0+XfOrM457_COUNT)
#       define SETUP_XfOrM458(x) SETUP_XfOrM457(x)
        FUNCCALL(SETUP_XfOrM458(_), scheme_put_byte_string (name , port , (char * ) v , ((char * ) ((((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (v ) ) ) -> s ) ) ) - ((char * ) v ) , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (v ) ) ) -> len ) , 0 ) ); 
      }
      else FUNCCALL(SETUP_XfOrM457(_), scheme_internal_display (v , port ) ); 
    }
    else {
      Scheme_Object * a [2 ] ; 
      BLOCK_SETUP((PUSHARRAY(a, 2, 0+XfOrM455_COUNT)));
#     define XfOrM456_COUNT (3+XfOrM455_COUNT)
#     define SETUP_XfOrM456(x) SETUP(XfOrM456_COUNT)
      a[0] = NULLED_OUT ; 
      a[1] = NULLED_OUT ; 
      a [0 ] = argv [0 ] ; 
      a [1 ] = port ; 
      FUNCCALL(SETUP_XfOrM456(_), scheme_do_eval (op -> display_handler , 2 , a , - 1 ) ); 
    }
  }
  else if (! escape ) {
    Scheme_Object * h ; 
    BLOCK_SETUP((PUSH(h, 0+XfOrM451_COUNT)));
#   define XfOrM453_COUNT (1+XfOrM451_COUNT)
#   define SETUP_XfOrM453(x) SETUP(XfOrM453_COUNT)
    h = NULLED_OUT ; 
    h = op -> write_handler ; 
    if (! h )
      FUNCCALL(SETUP_XfOrM453(_), scheme_internal_write (argv [0 ] , port ) ); 
    else {
      Scheme_Object * a [2 ] ; 
      BLOCK_SETUP((PUSHARRAY(a, 2, 0+XfOrM453_COUNT)));
#     define XfOrM454_COUNT (3+XfOrM453_COUNT)
#     define SETUP_XfOrM454(x) SETUP(XfOrM454_COUNT)
      a[0] = NULLED_OUT ; 
      a[1] = NULLED_OUT ; 
      a [0 ] = argv [0 ] ; 
      a [1 ] = port ; 
      FUNCCALL(SETUP_XfOrM454(_), scheme_do_eval (h , 2 , a , - 1 ) ); 
    }
  }
  else {
    Scheme_Object * h ; 
    Scheme_Object * a [2 ] ; 
    BLOCK_SETUP((PUSH(h, 0+XfOrM451_COUNT), PUSHARRAY(a, 2, 1+XfOrM451_COUNT)));
#   define XfOrM452_COUNT (4+XfOrM451_COUNT)
#   define SETUP_XfOrM452(x) SETUP(XfOrM452_COUNT)
    h = NULLED_OUT ; 
    a[0] = NULLED_OUT ; 
    a[1] = NULLED_OUT ; 
    a [0 ] = argv [0 ] ; 
    a [1 ] = port ; 
    h = op -> print_handler ; 
    if (! h )
      FUNCCALL(SETUP_XfOrM452(_), sch_default_print_handler (2 , a ) ); 
    else FUNCCALL(SETUP_XfOrM452(_), scheme_do_eval (h , 2 , a , - 1 ) ); 
  }
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * sch_write (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return display_write ("write" , argc , argv , 0 ) ; 
}
static Scheme_Object * display (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return display_write ("display" , argc , argv , 1 ) ; 
}
static Scheme_Object * sch_print (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return display_write ("print" , argc , argv , - 1 ) ; 
}
static Scheme_Object * newline (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * port ; 
  Scheme_Config * __funcarg125 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(port, 0)));
# define XfOrM465_COUNT (1)
# define SETUP_XfOrM465(x) SETUP(XfOrM465_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  port = NULLED_OUT ; 
  if (argc && ! (scheme_is_output_port (argv [0 ] ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("newline" , "output-port" , 0 , argc , argv ) ); 
  if (argc )
    port = argv [0 ] ; 
  else port = (__funcarg125 = FUNCCALL(SETUP_XfOrM465(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg125 , MZCONFIG_OUTPUT_PORT ) )) ; 
  (void ) FUNCCALL_EMPTY(scheme_put_byte_string ("newline" , port , "\n" , 0 , 1 , 0 ) ); 
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * write_byte (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * port ; 
  int v ; 
  unsigned char buffer [1 ] ; 
  Scheme_Config * __funcarg126 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(port, 0)));
# define XfOrM466_COUNT (1)
# define SETUP_XfOrM466(x) SETUP(XfOrM466_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  port = NULLED_OUT ; 
  if (argc && ! (((long ) (argv [0 ] ) ) & 0x1 ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("write-byte" , "exact integer in [0,255]" , 0 , argc , argv ) ); 
  v = (((long ) (argv [0 ] ) ) >> 1 ) ; 
  if ((v < 0 ) || (v > 255 ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("write-byte" , "exact integer in [0,255]" , 0 , argc , argv ) ); 
  if (argc > 1 ) {
#   define XfOrM467_COUNT (0+XfOrM466_COUNT)
#   define SETUP_XfOrM467(x) SETUP_XfOrM466(x)
    if (! (scheme_is_output_port (argv [1 ] ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("write-byte" , "output-port" , 1 , argc , argv ) ); 
    port = argv [1 ] ; 
  }
  else port = (__funcarg126 = FUNCCALL(SETUP_XfOrM466(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg126 , MZCONFIG_OUTPUT_PORT ) )) ; 
  buffer [0 ] = v ; 
  FUNCCALL_EMPTY(scheme_put_byte_string ("write-byte" , port , (char * ) buffer , 0 , 1 , 0 ) ); 
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * write_char (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * port ; 
  unsigned char buffer [6 ] ; 
  unsigned int ubuffer [1 ] ; 
  int len ; 
  Scheme_Config * __funcarg127 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(port, 0), PUSH(argv, 1)));
# define XfOrM468_COUNT (2)
# define SETUP_XfOrM468(x) SETUP(XfOrM468_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  port = NULLED_OUT ; 
  if (argc && ! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("write-char" , "character" , 0 , argc , argv ) ); 
  if (argc > 1 ) {
#   define XfOrM469_COUNT (0+XfOrM468_COUNT)
#   define SETUP_XfOrM469(x) SETUP_XfOrM468(x)
    if (! (scheme_is_output_port (argv [1 ] ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("write-char" , "output-port" , 1 , argc , argv ) ); 
    port = argv [1 ] ; 
  }
  else port = (__funcarg127 = FUNCCALL(SETUP_XfOrM468(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg127 , MZCONFIG_OUTPUT_PORT ) )) ; 
  ubuffer [0 ] = (((Scheme_Small_Object * ) (argv [0 ] ) ) -> u . char_val ) ; 
  len = FUNCCALL(SETUP_XfOrM468(_), scheme_utf8_encode_all (ubuffer , 1 , buffer ) ); 
  FUNCCALL_EMPTY(scheme_put_byte_string ("write-char" , port , (char * ) buffer , 0 , len , 0 ) ); 
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * port_read_handler (int argc , Scheme_Object * argv [] ) {
  Scheme_Input_Port * ip ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(ip, 0), PUSH(argv, 1)));
# define XfOrM470_COUNT (2)
# define SETUP_XfOrM470(x) SETUP(XfOrM470_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ip = NULLED_OUT ; 
  if (! (scheme_is_input_port (argv [0 ] ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("port-read-handler" , "input-port" , 0 , argc , argv ) ); 
  ip = FUNCCALL(SETUP_XfOrM470(_), scheme_input_port_record (argv [0 ] ) ); 
  if (argc == 1 ) {
    if (ip -> read_handler )
      RET_VALUE_START (ip -> read_handler ) RET_VALUE_END ; 
    else RET_VALUE_START (default_read_handler ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM471_COUNT (0+XfOrM470_COUNT)
#   define SETUP_XfOrM471(x) SETUP_XfOrM470(x)
    if (argv [1 ] == default_read_handler )
      ip -> read_handler = ((void * ) 0 ) ; 
    else {
#     define XfOrM472_COUNT (0+XfOrM471_COUNT)
#     define SETUP_XfOrM472(x) SETUP_XfOrM471(x)
      if (! FUNCCALL(SETUP_XfOrM472(_), scheme_check_proc_arity (((void * ) 0 ) , 1 , 1 , argc , argv ) )|| ! FUNCCALL(SETUP_XfOrM472(_), scheme_check_proc_arity (((void * ) 0 ) , 2 , 1 , argc , argv ) )) {
#       define XfOrM473_COUNT (0+XfOrM472_COUNT)
#       define SETUP_XfOrM473(x) SETUP_XfOrM472(x)
        FUNCCALL_EMPTY(scheme_wrong_type ("port-read-handler" , "procedure (arity 1 and 2)" , 1 , argc , argv ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      ip -> read_handler = argv [1 ] ; 
    }
    RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * port_display_handler (int argc , Scheme_Object * argv [] ) {
  Scheme_Output_Port * op ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(op, 0), PUSH(argv, 1)));
# define XfOrM475_COUNT (2)
# define SETUP_XfOrM475(x) SETUP(XfOrM475_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  op = NULLED_OUT ; 
  if (! (scheme_is_output_port (argv [0 ] ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("port-display-handler" , "output-port" , 0 , argc , argv ) ); 
  op = FUNCCALL(SETUP_XfOrM475(_), scheme_output_port_record (argv [0 ] ) ); 
  if (argc == 1 ) {
    if (op -> display_handler )
      RET_VALUE_START (op -> display_handler ) RET_VALUE_END ; 
    else RET_VALUE_START (default_display_handler ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM476_COUNT (0+XfOrM475_COUNT)
#   define SETUP_XfOrM476(x) SETUP_XfOrM475(x)
    FUNCCALL(SETUP_XfOrM476(_), scheme_check_proc_arity ("port-display-handler" , 2 , 1 , argc , argv ) ); 
    if (argv [1 ] == default_display_handler )
      op -> display_handler = ((void * ) 0 ) ; 
    else op -> display_handler = argv [1 ] ; 
    RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * port_write_handler (int argc , Scheme_Object * argv [] ) {
  Scheme_Output_Port * op ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(op, 0), PUSH(argv, 1)));
# define XfOrM478_COUNT (2)
# define SETUP_XfOrM478(x) SETUP(XfOrM478_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  op = NULLED_OUT ; 
  if (! (scheme_is_output_port (argv [0 ] ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("port-write-handler" , "output-port" , 0 , argc , argv ) ); 
  op = FUNCCALL(SETUP_XfOrM478(_), scheme_output_port_record (argv [0 ] ) ); 
  if (argc == 1 ) {
    if (op -> write_handler )
      RET_VALUE_START (op -> write_handler ) RET_VALUE_END ; 
    else RET_VALUE_START (default_write_handler ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM479_COUNT (0+XfOrM478_COUNT)
#   define SETUP_XfOrM479(x) SETUP_XfOrM478(x)
    FUNCCALL(SETUP_XfOrM479(_), scheme_check_proc_arity ("port-write-handler" , 2 , 1 , argc , argv ) ); 
    if (argv [1 ] == default_write_handler )
      op -> write_handler = ((void * ) 0 ) ; 
    else op -> write_handler = argv [1 ] ; 
    RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * port_print_handler (int argc , Scheme_Object * argv [] ) {
  Scheme_Output_Port * op ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(op, 0), PUSH(argv, 1)));
# define XfOrM481_COUNT (2)
# define SETUP_XfOrM481(x) SETUP(XfOrM481_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  op = NULLED_OUT ; 
  if (! (scheme_is_output_port (argv [0 ] ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("port-print-handler" , "output-port" , 0 , argc , argv ) ); 
  op = FUNCCALL(SETUP_XfOrM481(_), scheme_output_port_record (argv [0 ] ) ); 
  if (argc == 1 ) {
    if (op -> print_handler )
      RET_VALUE_START (op -> print_handler ) RET_VALUE_END ; 
    else RET_VALUE_START (default_print_handler ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM482_COUNT (0+XfOrM481_COUNT)
#   define SETUP_XfOrM482(x) SETUP_XfOrM481(x)
    FUNCCALL(SETUP_XfOrM482(_), scheme_check_proc_arity ("port-print-handler" , 2 , 1 , argc , argv ) ); 
    if (argv [1 ] == default_print_handler )
      op -> print_handler = ((void * ) 0 ) ; 
    else op -> print_handler = argv [1 ] ; 
    RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * global_port_print_handler (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("global-port-print-handler" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_PORT_PRINT_HANDLER ) ) << 1 ) | 0x1 ) ) , argc , argv , 2 , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ; 
}
static Scheme_Object * port_count_lines (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! scheme_is_input_port (argv [0 ] ) && ! scheme_is_output_port (argv [0 ] ) )
    scheme_wrong_type ("port-count-lines!" , "port" , 0 , argc , argv ) ; 
  scheme_count_lines (argv [0 ] ) ; 
  return scheme_void ; 
}
static Scheme_Object * global_port_count_lines (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return scheme_param_config ("port-count-lines-enabled" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_PORT_COUNT_LINES ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ; 
}
static Scheme_Object * port_next_location (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * a [3 ] ; 
  long line , col , pos ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 3, 0), PUSH(argv, 3)));
# define XfOrM487_COUNT (4)
# define SETUP_XfOrM487(x) SETUP(XfOrM487_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  a[2] = NULLED_OUT ; 
  if (! (scheme_is_input_port (argv [0 ] ) ) && ! (scheme_is_output_port (argv [0 ] ) ) )
    FUNCCALL(SETUP_XfOrM487(_), scheme_wrong_type ("port-next-location" , "port" , 0 , argc , argv ) ); 
  FUNCCALL(SETUP_XfOrM487(_), scheme_tell_all (argv [0 ] , & line , & col , & pos ) ); 
  a [0 ] = ((line < 0 ) ? scheme_false : FUNCCALL(SETUP_XfOrM487(_), scheme_make_integer_value (line ) )) ; 
  a [1 ] = ((col < 0 ) ? scheme_false : FUNCCALL(SETUP_XfOrM487(_), scheme_make_integer_value (col ) )) ; 
  a [2 ] = ((pos < 0 ) ? scheme_false : FUNCCALL(SETUP_XfOrM487(_), scheme_make_integer_value (pos + 1 ) )) ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM487(_), scheme_values (3 , a ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
typedef struct {
  Scheme_Type type ; 
  Scheme_Config * config ; 
  Scheme_Object * port ; 
  Scheme_Thread * p ; 
  Scheme_Object * stxsrc ; 
  Scheme_Object * expected_module ; 
  Scheme_Object * delay_load_info ; 
}
LoadHandlerData ; 
static void post_load_handler (void * data ) {
  /* No conversion */
  LoadHandlerData * lhd = (LoadHandlerData * ) data ; 
  scheme_close_input_port ((Scheme_Object * ) lhd -> port ) ; 
}
static Scheme_Object * do_load_handler (void * data ) {
  LoadHandlerData * lhd = (LoadHandlerData * ) data ; 
  Scheme_Object * port = lhd -> port ; 
  Scheme_Thread * p = lhd -> p ; 
  Scheme_Config * config = lhd -> config ; 
  Scheme_Object * last_val = scheme_void , * obj , * * save_array = ((void * ) 0 ) ; 
  Scheme_Env * genv ; 
  int save_count = 0 , got_one = 0 ; 
  Scheme_Object * __funcarg134 = NULLED_OUT ; 
  Scheme_Object * __funcarg133 = NULLED_OUT ; 
  Scheme_Object * __funcarg132 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(14);
  BLOCK_SETUP_TOP((PUSH(save_array, 0), PUSH(genv, 1), PUSH(config, 2), PUSH(port, 3), PUSH(obj, 4), PUSH(lhd, 5), PUSH(last_val, 6), PUSH(p, 7)));
# define XfOrM489_COUNT (8)
# define SETUP_XfOrM489(x) SETUP(XfOrM489_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  obj = NULLED_OUT ; 
  genv = NULLED_OUT ; 
  while ((obj = FUNCCALL(SETUP_XfOrM489(_), scheme_internal_read (port , lhd -> stxsrc , 1 , 0 , 0 , 0 , 0 , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , lhd -> delay_load_info ) )) && ! (((obj ) ) == (scheme_eof ) ) ) {
#   define XfOrM507_COUNT (0+XfOrM489_COUNT)
#   define SETUP_XfOrM507(x) SETUP_XfOrM489(x)
    save_array = ((void * ) 0 ) ; 
    got_one = 1 ; 
    if (((Scheme_Type ) (((((long ) (lhd -> expected_module ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lhd -> expected_module ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
      Scheme_Object * a , * d , * other = ((void * ) 0 ) ; 
      Scheme_Module * m ; 
      BLOCK_SETUP((PUSH(d, 0+XfOrM507_COUNT), PUSH(other, 1+XfOrM507_COUNT), PUSH(a, 2+XfOrM507_COUNT), PUSH(m, 3+XfOrM507_COUNT)));
#     define XfOrM510_COUNT (4+XfOrM507_COUNT)
#     define SETUP_XfOrM510(x) SETUP(XfOrM510_COUNT)
      a = NULLED_OUT ; 
      d = NULLED_OUT ; 
      m = NULLED_OUT ; 
      d = obj ; 
      m = FUNCCALL(SETUP_XfOrM510(_), scheme_extract_compiled_module (((Scheme_Stx * ) d ) -> val ) ); 
      if (m ) {
        if (! ((m -> modname ) == (lhd -> expected_module ) ) ) {
          other = m -> modname ; 
          d = ((void * ) 0 ) ; 
        }
      }
      else {
#       define XfOrM516_COUNT (0+XfOrM510_COUNT)
#       define SETUP_XfOrM516(x) SETUP_XfOrM510(x)
        if (! (((Scheme_Type ) (((((long ) (d ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (d ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (d ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (d ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) d ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) d ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
          d = ((void * ) 0 ) ; 
        else {
#         define XfOrM517_COUNT (0+XfOrM516_COUNT)
#         define SETUP_XfOrM517(x) SETUP_XfOrM516(x)
          a = (((Scheme_Type ) (((((long ) (d ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (d ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (d ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM517(_), scheme_stx_content (d ) )) ) -> u . pair_val . car ) ) ; 
          if (! ((((Scheme_Stx * ) a ) -> val ) == (module_symbol ) ) )
            d = ((void * ) 0 ) ; 
          else {
#           define XfOrM518_COUNT (0+XfOrM517_COUNT)
#           define SETUP_XfOrM518(x) SETUP_XfOrM517(x)
            d = (((Scheme_Type ) (((((long ) (d ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (d ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (d ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM518(_), scheme_stx_content (d ) )) ) -> u . pair_val . cdr ) ) ; 
            if (! (((Scheme_Type ) (((((long ) (d ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (d ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || (((Scheme_Type ) (((((long ) (d ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (d ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) && ((Scheme_Type ) (((((long ) (((Scheme_Stx * ) d ) -> val ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (((Scheme_Stx * ) d ) -> val ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) ) )
              d = ((void * ) 0 ) ; 
            else {
#             define XfOrM519_COUNT (0+XfOrM518_COUNT)
#             define SETUP_XfOrM519(x) SETUP_XfOrM518(x)
              a = (((Scheme_Type ) (((((long ) (d ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (d ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (d ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM519(_), scheme_stx_content (d ) )) ) -> u . pair_val . car ) ) ; 
              other = ((Scheme_Stx * ) a ) -> val ; 
              if (! ((other ) == (lhd -> expected_module ) ) )
                d = ((void * ) 0 ) ; 
            }
          }
        }
      }
      if (! d ) {
#       define XfOrM513_COUNT (0+XfOrM510_COUNT)
#       define SETUP_XfOrM513(x) SETUP_XfOrM510(x)
        if (! other || ! ((Scheme_Type ) (((((long ) (other ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (other ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
          other = FUNCCALL(SETUP_XfOrM513(_), scheme_make_byte_string ("something else" ) ); 
        else {
          char * s , * t ; 
          long len , slen ; 
          BLOCK_SETUP((PUSH(t, 0+XfOrM513_COUNT), PUSH(s, 1+XfOrM513_COUNT)));
#         define XfOrM515_COUNT (2+XfOrM513_COUNT)
#         define SETUP_XfOrM515(x) SETUP(XfOrM515_COUNT)
          s = NULLED_OUT ; 
          t = NULLED_OUT ; 
          t = "declaration for `" ; 
          len = strlen (t ) ; 
          slen = (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (other ) ) ) -> len ) ; 
          s = (char * ) FUNCCALL(SETUP_XfOrM515(_), GC_malloc_atomic (len + slen + 2 ) ); 
          (memcpy (s , t , len ) ) ; 
          (memcpy (s + len , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (other ) ) ) -> s ) , slen ) ) ; 
          s [len + slen ] = '\'' ; 
          s [len + slen + 1 ] = 0 ; 
          other = FUNCCALL(SETUP_XfOrM515(_), scheme_make_sized_byte_string (s , len + slen + 1 , 0 ) ); 
        }
        {
          Scheme_Input_Port * ip ; 
          BLOCK_SETUP((PUSH(ip, 0+XfOrM513_COUNT)));
#         define XfOrM514_COUNT (1+XfOrM513_COUNT)
#         define SETUP_XfOrM514(x) SETUP(XfOrM514_COUNT)
          ip = NULLED_OUT ; 
          ip = FUNCCALL(SETUP_XfOrM514(_), scheme_input_port_record (port ) ); 
          FUNCCALL_AGAIN(scheme_raise_exn (MZEXN_FAIL , "default-load-handler: expected a `module' declaration for `%S', found: %T in: %V" , lhd -> expected_module , other , ip -> name ) ); 
        }
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      d = FUNCCALL(SETUP_XfOrM510(_), scheme_internal_read (port , lhd -> stxsrc , 1 , 0 , 0 , 0 , 0 , - 1 , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
      if (! (((d ) ) == (scheme_eof ) ) ) {
        Scheme_Input_Port * ip ; 
        BLOCK_SETUP((PUSH(ip, 0+XfOrM510_COUNT)));
#       define XfOrM512_COUNT (1+XfOrM510_COUNT)
#       define SETUP_XfOrM512(x) SETUP(XfOrM512_COUNT)
        ip = NULLED_OUT ; 
        ip = FUNCCALL(SETUP_XfOrM512(_), scheme_input_port_record (port ) ); 
        FUNCCALL_AGAIN(scheme_raise_exn (MZEXN_FAIL , "default-load-handler: expected only a `module' declaration for `%S'," " but found an extra expression in: %V" , lhd -> expected_module , ip -> name ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      if (! m ) {
#       define XfOrM511_COUNT (0+XfOrM510_COUNT)
#       define SETUP_XfOrM511(x) SETUP_XfOrM510(x)
        a = (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . car ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM511(_), scheme_stx_content (obj ) )) ) -> u . pair_val . car ) ) ; 
        d = (((Scheme_Type ) (((((long ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ? (((Scheme_Simple_Object * ) (obj ) ) -> u . pair_val . cdr ) : (((Scheme_Simple_Object * ) (FUNCCALL(SETUP_XfOrM511(_), scheme_stx_content (obj ) )) ) -> u . pair_val . cdr ) ) ; 
        a = (__funcarg134 = FUNCCALL(SETUP_XfOrM511(_), scheme_sys_wraps (((void * ) 0 ) ) ), FUNCCALL_AGAIN(scheme_datum_to_syntax (module_symbol , a , __funcarg134 , 0 , 1 ) )) ; 
        d = FUNCCALL_AGAIN(scheme_make_immutable_pair (a , d ) ); 
        obj = FUNCCALL_AGAIN(scheme_datum_to_syntax (d , obj , scheme_false , 0 , 1 ) ); 
      }
    }
    else {
      Scheme_Object * a ; 
      BLOCK_SETUP((PUSH(a, 0+XfOrM507_COUNT)));
#     define XfOrM509_COUNT (1+XfOrM507_COUNT)
#     define SETUP_XfOrM509(x) SETUP(XfOrM509_COUNT)
      a = NULLED_OUT ; 
      a = (__funcarg133 = FUNCCALL(SETUP_XfOrM509(_), scheme_intern_symbol ("#%top-interaction" ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg133 , obj ) )) ; 
      obj = FUNCCALL_AGAIN(scheme_datum_to_syntax (a , obj , scheme_false , 0 , 0 ) ); 
    }
    genv = FUNCCALL(SETUP_XfOrM507(_), scheme_get_env (config ) ); 
    if (genv -> rename )
      obj = FUNCCALL(SETUP_XfOrM507(_), scheme_add_rename (obj , genv -> rename ) ); 
    if (genv -> exp_env && genv -> exp_env -> rename )
      obj = FUNCCALL(SETUP_XfOrM507(_), scheme_add_rename (obj , genv -> exp_env -> rename ) ); 
    if (genv -> template_env && genv -> template_env -> rename )
      obj = FUNCCALL(SETUP_XfOrM507(_), scheme_add_rename (obj , genv -> template_env -> rename ) ); 
    last_val = (__funcarg132 = FUNCCALL(SETUP_XfOrM507(_), scheme_get_param (config , MZCONFIG_EVAL_HANDLER ) ), FUNCCALL_AGAIN(_scheme_apply_multi_with_prompt (__funcarg132 , 1 , & obj ) )) ; 
    if (last_val == ((Scheme_Object * ) 0x6 ) ) {
      save_array = p -> ku . multiple . array ; 
      save_count = p -> ku . multiple . count ; 
      if (((save_array ) == (p -> values_buffer ) ) )
        p -> values_buffer = ((void * ) 0 ) ; 
    }
    if (((Scheme_Type ) (((((long ) (lhd -> expected_module ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lhd -> expected_module ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
      break ; 
  }
  if (((Scheme_Type ) (((((long ) (lhd -> expected_module ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (lhd -> expected_module ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) && ! got_one ) {
    Scheme_Input_Port * ip ; 
    BLOCK_SETUP((PUSH(ip, 0+XfOrM489_COUNT)));
#   define XfOrM491_COUNT (1+XfOrM489_COUNT)
#   define SETUP_XfOrM491(x) SETUP(XfOrM491_COUNT)
    ip = NULLED_OUT ; 
    ip = FUNCCALL(SETUP_XfOrM491(_), scheme_input_port_record (port ) ); 
    FUNCCALL_AGAIN(scheme_raise_exn (MZEXN_FAIL , "default-load-handler: expected a `module' declaration for `%S', but found end-of-file in: %V" , lhd -> expected_module , ip -> name ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (save_array ) {
    p -> ku . multiple . array = save_array ; 
    p -> ku . multiple . count = save_count ; 
  }
  RET_VALUE_START (last_val ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * default_load (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * port , * name , * expected_module , * v ; 
  int use_delay_load ; 
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Config * config ; 
  LoadHandlerData * lhd ; 
  Scheme_Cont_Frame_Data cframe ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(9);
  BLOCK_SETUP_TOP((PUSH(port, 0), PUSH(lhd, 1), PUSH(cframe.cache, 2), PUSH(name, 3), PUSH(v, 4), PUSH(config, 5), PUSH(expected_module, 6), PUSH(argv, 7), PUSH(p, 8)));
# define XfOrM522_COUNT (9)
# define SETUP_XfOrM522(x) SETUP(XfOrM522_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  port = NULLED_OUT ; 
  name = NULLED_OUT ; 
  expected_module = NULLED_OUT ; 
  v = NULLED_OUT ; 
  config = NULLED_OUT ; 
  lhd = NULLED_OUT ; 
  cframe.cache = NULLED_OUT ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) )
    FUNCCALL(SETUP_XfOrM522(_), scheme_wrong_type ("default-load-handler" , "path or string" , 0 , argc , argv ) ); 
  expected_module = argv [1 ] ; 
  if (! (((expected_module ) ) == (scheme_false ) ) && ! ((Scheme_Type ) (((((long ) (expected_module ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (expected_module ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
    FUNCCALL(SETUP_XfOrM522(_), scheme_wrong_type ("default-load-handler" , "symbol or #f" , 1 , argc , argv ) ); 
  port = FUNCCALL(SETUP_XfOrM522(_), scheme_do_open_input_file ("default-load-handler" , 0 , 1 , argv ) ); 
  if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) {
    long len ; 
#   define XfOrM528_COUNT (0+XfOrM522_COUNT)
#   define SETUP_XfOrM528(x) SETUP_XfOrM522(x)
    len = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . tag_val ) ; 
    if ((len < 3 ) || ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) [len - 3 ] != '.' ) || ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) [len - 2 ] != 'z' ) || ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) [len - 1 ] != 'o' ) )
      FUNCCALL(SETUP_XfOrM528(_), scheme_count_lines (port ) ); 
  }
  else {
    long len ; 
#   define XfOrM527_COUNT (0+XfOrM522_COUNT)
#   define SETUP_XfOrM527(x) SETUP_XfOrM522(x)
    len = (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) ; 
    if ((len < 3 ) || ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) [len - 3 ] != '.' ) || ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) [len - 2 ] != 'z' ) || ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) [len - 1 ] != 'o' ) )
      FUNCCALL(SETUP_XfOrM527(_), scheme_count_lines (port ) ); 
  }
  config = FUNCCALL(SETUP_XfOrM522(_), scheme_current_config () ); 
  v = FUNCCALL(SETUP_XfOrM522(_), scheme_get_param (config , MZCONFIG_LOAD_DELAY_ENABLED ) ); 
  use_delay_load = (! (((v ) ) == (scheme_false ) ) ) ; 
  if ((! (((expected_module ) ) == (scheme_false ) ) ) ) {
#   define XfOrM526_COUNT (0+XfOrM522_COUNT)
#   define SETUP_XfOrM526(x) SETUP_XfOrM522(x)
    config = FUNCCALL(SETUP_XfOrM526(_), scheme_extend_config (config , MZCONFIG_CASE_SENS , (scheme_case_sensitive ? scheme_true : scheme_false ) ) ); 
    config = FUNCCALL(SETUP_XfOrM526(_), scheme_extend_config (config , MZCONFIG_SQUARE_BRACKETS_ARE_PARENS , scheme_true ) ); 
    config = FUNCCALL_AGAIN(scheme_extend_config (config , MZCONFIG_CURLY_BRACES_ARE_PARENS , scheme_true ) ); 
    config = FUNCCALL_AGAIN(scheme_extend_config (config , MZCONFIG_CAN_READ_GRAPH , scheme_true ) ); 
    config = FUNCCALL_AGAIN(scheme_extend_config (config , MZCONFIG_CAN_READ_COMPILED , scheme_true ) ); 
    config = FUNCCALL_AGAIN(scheme_extend_config (config , MZCONFIG_CAN_READ_BOX , scheme_true ) ); 
    config = FUNCCALL_AGAIN(scheme_extend_config (config , MZCONFIG_CAN_READ_PIPE_QUOTE , scheme_true ) ); 
    config = FUNCCALL_AGAIN(scheme_extend_config (config , MZCONFIG_CAN_READ_DOT , scheme_true ) ); 
    config = FUNCCALL_AGAIN(scheme_extend_config (config , MZCONFIG_CAN_READ_INFIX_DOT , scheme_true ) ); 
    config = FUNCCALL_AGAIN(scheme_extend_config (config , MZCONFIG_CAN_READ_QUASI , scheme_true ) ); 
    config = FUNCCALL_AGAIN(scheme_extend_config (config , MZCONFIG_CAN_READ_READER , scheme_true ) ); 
    config = FUNCCALL_AGAIN(scheme_extend_config (config , MZCONFIG_READ_DECIMAL_INEXACT , scheme_true ) ); 
    config = FUNCCALL_AGAIN(scheme_extend_config (config , MZCONFIG_READTABLE , scheme_false ) ); 
  }
  lhd = ((LoadHandlerData * ) FUNCCALL(SETUP_XfOrM522(_), GC_malloc_one_small_tagged ((((sizeof (LoadHandlerData ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  lhd -> type = scheme_rt_load_handler_data ; 
  lhd -> p = p ; 
  lhd -> config = config ; 
  lhd -> port = port ; 
  name = FUNCCALL(SETUP_XfOrM522(_), scheme_input_port_record (port ) )-> name ; 
  lhd -> stxsrc = name ; 
  lhd -> expected_module = expected_module ; 
  if (use_delay_load ) {
#   define XfOrM525_COUNT (0+XfOrM522_COUNT)
#   define SETUP_XfOrM525(x) SETUP_XfOrM522(x)
    v = FUNCCALL(SETUP_XfOrM525(_), scheme_path_to_complete_path (argv [0 ] , ((void * ) 0 ) ) ); 
    lhd -> delay_load_info = v ; 
  }
  if ((! (((expected_module ) ) == (scheme_false ) ) ) ) {
#   define XfOrM524_COUNT (0+XfOrM522_COUNT)
#   define SETUP_XfOrM524(x) SETUP_XfOrM522(x)
    FUNCCALL(SETUP_XfOrM524(_), scheme_push_continuation_frame (& cframe ) ); 
    FUNCCALL(SETUP_XfOrM524(_), scheme_set_cont_mark (scheme_parameterization_key , (Scheme_Object * ) config ) ); 
  }
  v = FUNCCALL(SETUP_XfOrM522(_), scheme_dynamic_wind (((void * ) 0 ) , do_load_handler , post_load_handler , ((void * ) 0 ) , (void * ) lhd ) ); 
  if ((! (((expected_module ) ) == (scheme_false ) ) ) ) {
#   define XfOrM523_COUNT (0+XfOrM522_COUNT)
#   define SETUP_XfOrM523(x) SETUP_XfOrM522(x)
    FUNCCALL(SETUP_XfOrM523(_), scheme_pop_continuation_frame (& cframe ) ); 
  }
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_load_with_clrd (int argc , Scheme_Object * argv [] , char * who , int handler_param ) {
  const char * filename ; 
  Scheme_Object * load_dir , * a [2 ] , * filename_path , * v ; 
  Scheme_Cont_Frame_Data cframe ; 
  Scheme_Config * config ; 
  Scheme_Config * __funcarg136 = NULLED_OUT ; 
  Scheme_Object * __funcarg135 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(11);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(config, 1), PUSHARRAY(a, 2, 2), PUSH(load_dir, 5), PUSH(who, 6), PUSH(filename_path, 7), PUSH(cframe.cache, 8), PUSH(filename, 9), PUSH(argv, 10)));
# define XfOrM529_COUNT (11)
# define SETUP_XfOrM529(x) SETUP(XfOrM529_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  filename = NULLED_OUT ; 
  load_dir = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  filename_path = NULLED_OUT ; 
  v = NULLED_OUT ; 
  cframe.cache = NULLED_OUT ; 
  config = NULLED_OUT ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) )
    FUNCCALL(SETUP_XfOrM529(_), scheme_wrong_type (who , "path or string" , 0 , argc , argv ) ); 
  filename = FUNCCALL(SETUP_XfOrM529(_), scheme_expand_string_filename (argv [0 ] , who , ((void * ) 0 ) , 0x1 ) ); 
  load_dir = FUNCCALL_AGAIN(scheme_get_file_directory (filename ) ); 
  filename_path = FUNCCALL_AGAIN(scheme_make_sized_path ((char * ) filename , - 1 , 0 ) ); 
  config = (__funcarg136 = FUNCCALL(SETUP_XfOrM529(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_extend_config (__funcarg136 , MZCONFIG_LOAD_DIRECTORY , load_dir ) )) ; 
  FUNCCALL_AGAIN(scheme_push_continuation_frame (& cframe ) ); 
  FUNCCALL_AGAIN(scheme_set_cont_mark (scheme_parameterization_key , (Scheme_Object * ) config ) ); 
  a [0 ] = filename_path ; 
  a [1 ] = scheme_false ; 
  v = (__funcarg135 = FUNCCALL(SETUP_XfOrM529(_), scheme_get_param (config , handler_param ) ), FUNCCALL_AGAIN(scheme_do_eval (__funcarg135 , 2 , a , - 1 ) )) ; 
  FUNCCALL_AGAIN(scheme_pop_continuation_frame (& cframe ) ); 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * load (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_load_with_clrd (argc , argv , "load" , MZCONFIG_LOAD_HANDLER ) ; 
}
static Scheme_Object * current_load (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("current-load" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_LOAD_HANDLER ) ) << 1 ) | 0x1 ) ) , argc , argv , 2 , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ; 
}
static Scheme_Object * abs_directory_p (const char * name , int argc , Scheme_Object * * argv ) {
  Scheme_Object * d = argv [0 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(name, 0), PUSH(d, 1)));
# define XfOrM532_COUNT (2)
# define SETUP_XfOrM532(x) SETUP(XfOrM532_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! (((d ) ) == (scheme_false ) ) ) {
    char * expanded ; 
    Scheme_Object * ed ; 
    char * s ; 
    int len ; 
    BLOCK_SETUP((PUSH(expanded, 0+XfOrM532_COUNT), PUSH(ed, 1+XfOrM532_COUNT), PUSH(s, 2+XfOrM532_COUNT)));
#   define XfOrM533_COUNT (3+XfOrM532_COUNT)
#   define SETUP_XfOrM533(x) SETUP(XfOrM533_COUNT)
    expanded = NULLED_OUT ; 
    ed = NULLED_OUT ; 
    s = NULLED_OUT ; 
    if (! (((Scheme_Type ) (((((long ) (d ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (d ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (d ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (d ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) )
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    ed = (((Scheme_Type ) (((((long ) (d ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (d ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ? d : FUNCCALL(SETUP_XfOrM533(_), scheme_char_string_to_path (d ) )) ; 
    s = (((Scheme_Simple_Object * ) (ed ) ) -> u . byte_str_val . string_val ) ; 
    len = (((Scheme_Simple_Object * ) (ed ) ) -> u . byte_str_val . tag_val ) ; 
    if (! FUNCCALL(SETUP_XfOrM533(_), scheme_is_complete_path (s , len , scheme_unix_path_type ) ))
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: not a complete path: \"%q\"" , name , s ) ); 
    expanded = FUNCCALL(SETUP_XfOrM533(_), scheme_expand_string_filename (d , name , ((void * ) 0 ) , 0x10 ) ); 
    ed = FUNCCALL_AGAIN(scheme_make_sized_path (expanded , strlen (expanded ) , 1 ) ); 
    RET_VALUE_START (ed ) RET_VALUE_END ; 
  }
  RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * lr_abs_directory_p (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return abs_directory_p ("current-load-relative-directory" , argc , argv ) ; 
}
static Scheme_Object * current_load_directory (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("current-load-relative-directory" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_LOAD_DIRECTORY ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , lr_abs_directory_p , "path, string, or #f" , 1 ) ; 
}
static Scheme_Object * wr_abs_directory_p (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return abs_directory_p ("current-write-relative-directory" , argc , argv ) ; 
}
static Scheme_Object * current_write_directory (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("current-write-relative-directory" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_WRITE_DIRECTORY ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , wr_abs_directory_p , "path, string, or #f" , 1 ) ; 
}
Scheme_Object * scheme_load (const char * file ) {
  Scheme_Object * p [1 ] ; 
  mz_jmp_buf newbuf , * volatile savebuf ; 
  Scheme_Object * volatile val ; 
  Scheme_Object * __funcarg137 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(val, 0), PUSHARRAY(p, 1, 1), PUSH(savebuf, 4)));
# define XfOrM538_COUNT (5)
# define SETUP_XfOrM538(x) SETUP(XfOrM538_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  p[0] = NULLED_OUT ; 
  savebuf = NULLED_OUT ; 
  val = NULLED_OUT ; 
  p [0 ] = FUNCCALL(SETUP_XfOrM538(_), scheme_make_path (file ) ); 
  savebuf = scheme_current_thread -> error_buf ; 
  scheme_current_thread -> error_buf = & newbuf ; 
  if (((newbuf ) . gcvs = (long ) __gc_var_stack__ , (newbuf ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((newbuf ) . jb ) , (_setjmp (((newbuf ) . jb ) -> jb ) ) ) ) ) {
    val = ((void * ) 0 ) ; 
  }
  else {
#   define XfOrM539_COUNT (0+XfOrM538_COUNT)
#   define SETUP_XfOrM539(x) SETUP_XfOrM538(x)
    val = (__funcarg137 = FUNCCALL(SETUP_XfOrM539(_), scheme_make_prim ((Scheme_Prim * ) load ) ), FUNCCALL_AGAIN(scheme_apply_multi (__funcarg137 , 1 , p ) )) ; 
  }
  scheme_current_thread -> error_buf = savebuf ; 
  RET_VALUE_START (val ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * transcript_on (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) )
    scheme_wrong_type ("transcript-on" , "path or string" , 0 , argc , argv ) ; 
  scheme_raise_exn (MZEXN_FAIL_UNSUPPORTED , "transcript-on: not supported" ) ; 
  return scheme_void ; 
}
static Scheme_Object * transcript_off (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  scheme_raise_exn (MZEXN_FAIL_UNSUPPORTED , "transcript-off: not supported" ) ; 
  return scheme_void ; 
}
static Scheme_Object * flush_output (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * op ; 
  Scheme_Config * __funcarg138 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(op, 0)));
# define XfOrM543_COUNT (1)
# define SETUP_XfOrM543(x) SETUP(XfOrM543_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  op = NULLED_OUT ; 
  if (argc && ! (scheme_is_output_port (argv [0 ] ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("flush-output" , "output-port" , 0 , argc , argv ) ); 
  if (argc )
    op = argv [0 ] ; 
  else op = (__funcarg138 = FUNCCALL(SETUP_XfOrM543(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg138 , MZCONFIG_OUTPUT_PORT ) )) ; 
  FUNCCALL_EMPTY(scheme_flush_output (op ) ); 
  RET_VALUE_START ((scheme_void ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int mark_load_handler_data_SIZE (void * p ) {
  return ((sizeof (LoadHandlerData ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_load_handler_data_MARK (void * p ) {
  LoadHandlerData * d = (LoadHandlerData * ) p ; 
  GC_mark (d -> config ) ; 
  GC_mark (d -> port ) ; 
  GC_mark (d -> p ) ; 
  GC_mark (d -> stxsrc ) ; 
  GC_mark (d -> expected_module ) ; 
  GC_mark (d -> delay_load_info ) ; 
  return ((sizeof (LoadHandlerData ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_load_handler_data_FIXUP (void * p ) {
  LoadHandlerData * d = (LoadHandlerData * ) p ; 
  GC_fixup (& (d -> config ) ) ; 
  GC_fixup (& (d -> port ) ) ; 
  GC_fixup (& (d -> p ) ) ; 
  GC_fixup (& (d -> stxsrc ) ) ; 
  GC_fixup (& (d -> expected_module ) ) ; 
  GC_fixup (& (d -> delay_load_info ) ) ; 
  return ((sizeof (LoadHandlerData ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_indexed_string_SIZE (void * p ) {
  return ((sizeof (Scheme_Indexed_String ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_indexed_string_MARK (void * p ) {
  Scheme_Indexed_String * is = (Scheme_Indexed_String * ) p ; 
  GC_mark (is -> string ) ; 
  return ((sizeof (Scheme_Indexed_String ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_indexed_string_FIXUP (void * p ) {
  Scheme_Indexed_String * is = (Scheme_Indexed_String * ) p ; 
  GC_fixup (& (is -> string ) ) ; 
  return ((sizeof (Scheme_Indexed_String ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_user_input_SIZE (void * p ) {
  return ((sizeof (User_Input_Port ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_user_input_MARK (void * p ) {
  User_Input_Port * uip = (User_Input_Port * ) p ; 
  GC_mark (uip -> read_proc ) ; 
  GC_mark (uip -> peek_proc ) ; 
  GC_mark (uip -> progress_evt_proc ) ; 
  GC_mark (uip -> peeked_read_proc ) ; 
  GC_mark (uip -> location_proc ) ; 
  GC_mark (uip -> count_lines_proc ) ; 
  GC_mark (uip -> buffer_mode_proc ) ; 
  GC_mark (uip -> close_proc ) ; 
  GC_mark (uip -> reuse_str ) ; 
  GC_mark (uip -> peeked ) ; 
  return ((sizeof (User_Input_Port ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_user_input_FIXUP (void * p ) {
  User_Input_Port * uip = (User_Input_Port * ) p ; 
  GC_fixup (& (uip -> read_proc ) ) ; 
  GC_fixup (& (uip -> peek_proc ) ) ; 
  GC_fixup (& (uip -> progress_evt_proc ) ) ; 
  GC_fixup (& (uip -> peeked_read_proc ) ) ; 
  GC_fixup (& (uip -> location_proc ) ) ; 
  GC_fixup (& (uip -> count_lines_proc ) ) ; 
  GC_fixup (& (uip -> buffer_mode_proc ) ) ; 
  GC_fixup (& (uip -> close_proc ) ) ; 
  GC_fixup (& (uip -> reuse_str ) ) ; 
  GC_fixup (& (uip -> peeked ) ) ; 
  return ((sizeof (User_Input_Port ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_user_output_SIZE (void * p ) {
  return ((sizeof (User_Output_Port ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_user_output_MARK (void * p ) {
  User_Output_Port * uop = (User_Output_Port * ) p ; 
  GC_mark (uop -> evt ) ; 
  GC_mark (uop -> write_evt_proc ) ; 
  GC_mark (uop -> write_proc ) ; 
  GC_mark (uop -> write_special_evt_proc ) ; 
  GC_mark (uop -> write_special_proc ) ; 
  GC_mark (uop -> location_proc ) ; 
  GC_mark (uop -> count_lines_proc ) ; 
  GC_mark (uop -> buffer_mode_proc ) ; 
  GC_mark (uop -> close_proc ) ; 
  return ((sizeof (User_Output_Port ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_user_output_FIXUP (void * p ) {
  User_Output_Port * uop = (User_Output_Port * ) p ; 
  GC_fixup (& (uop -> evt ) ) ; 
  GC_fixup (& (uop -> write_evt_proc ) ) ; 
  GC_fixup (& (uop -> write_proc ) ) ; 
  GC_fixup (& (uop -> write_special_evt_proc ) ) ; 
  GC_fixup (& (uop -> write_special_proc ) ) ; 
  GC_fixup (& (uop -> location_proc ) ) ; 
  GC_fixup (& (uop -> count_lines_proc ) ) ; 
  GC_fixup (& (uop -> buffer_mode_proc ) ) ; 
  GC_fixup (& (uop -> close_proc ) ) ; 
  return ((sizeof (User_Output_Port ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static void register_traversers (void ) {
  GC_register_traversers (scheme_rt_indexed_string , mark_indexed_string_SIZE , mark_indexed_string_MARK , mark_indexed_string_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_load_handler_data , mark_load_handler_data_SIZE , mark_load_handler_data_MARK , mark_load_handler_data_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_user_input , mark_user_input_SIZE , mark_user_input_MARK , mark_user_input_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_user_output , mark_user_output_SIZE , mark_user_output_MARK , mark_user_output_FIXUP , 1 , 0 ) ; 
}
