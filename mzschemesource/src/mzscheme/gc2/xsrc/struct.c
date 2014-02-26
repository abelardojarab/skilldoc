#include "precomp.h"
Scheme_Object * scheme_arity_at_least , * scheme_date ; 
Scheme_Object * scheme_make_arity_at_least ; 
Scheme_Object * scheme_source_property ; 
Scheme_Object * scheme_input_port_property , * scheme_output_port_property ; 
Scheme_Object * scheme_make_struct_type_proc ; 
Scheme_Object * location_struct ; 
typedef enum {
  SCHEME_CONSTR = 1 , SCHEME_PRED , SCHEME_GETTER , SCHEME_SETTER , SCHEME_GEN_GETTER , SCHEME_GEN_SETTER }
Scheme_ProcT ; 
typedef struct {
  Scheme_Object so ; 
  Scheme_Object * evt ; 
  Scheme_Object * wrapper ; 
}
Wrapped_Evt ; 
typedef struct {
  Scheme_Object so ; 
  Scheme_Object * maker ; 
}
Nack_Guard_Evt ; 
static Scheme_Object * make_inspector (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * make_sibling_inspector (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * inspector_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * current_inspector (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * current_code_inspector (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * make_struct_type_property (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * struct_type_property_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * check_evt_property_value_ok (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * check_write_property_value_ok (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * check_input_port_property_value_ok (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * check_output_port_property_value_ok (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * make_struct_type (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * make_struct_field_accessor (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * make_struct_field_mutator (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * nack_evt (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * handle_evt (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * handle_evt_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * struct_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * struct_type_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * proc_struct_type_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * struct_info (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * struct_type_info (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * struct_type_pred (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * struct_type_constr (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * struct_to_vector (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * struct_setter_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * struct_getter_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * struct_pred_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * struct_constr_p (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * make_struct_proc (Scheme_Struct_Type * struct_type , char * func_name , Scheme_ProcT proc_type , int field_num ) ; 
static Scheme_Object * make_name (const char * pre , const char * tn , int tnl , const char * post1 , const char * fn , int fnl , const char * post2 , int sym ) ; 
static void get_struct_type_info (int argc , Scheme_Object * argv [] , Scheme_Object * * a , int always ) ; 
static Scheme_Object * write_property ; 
Scheme_Object * scheme_recur_symbol , * scheme_display_symbol , * scheme_write_special_symbol ; 
static Scheme_Object * evt_property ; 
static int evt_struct_is_ready (Scheme_Object * o , Scheme_Schedule_Info * sinfo ) ; 
static int is_evt_struct (Scheme_Object * ) ; 
static Scheme_Object * proc_property ; 
static int wrapped_evt_is_ready (Scheme_Object * o , Scheme_Schedule_Info * sinfo ) ; 
static int nack_guard_evt_is_ready (Scheme_Object * o , Scheme_Schedule_Info * sinfo ) ; 
static int nack_evt_is_ready (Scheme_Object * o , Scheme_Schedule_Info * sinfo ) ; 
static int poll_evt_is_ready (Scheme_Object * o , Scheme_Schedule_Info * sinfo ) ; 
Scheme_Object * make_special_comment (int argc , Scheme_Object * * argv ) ; 
Scheme_Object * special_comment_value (int argc , Scheme_Object * * argv ) ; 
Scheme_Object * special_comment_p (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * check_location_fields (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * check_exn_source_property_value_ok (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * exn_source_p (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * exn_source_get (int argc , Scheme_Object * * argv ) ; 
static void register_traversers (void ) ; 
static Scheme_Object * ellipses_symbol ; 
void scheme_init_struct (Scheme_Env * env ) {
  Scheme_Object * * as_names ; 
  Scheme_Object * * as_values , * as_et ; 
  int as_count ; 
  Scheme_Object * * ts_names ; 
  Scheme_Object * * ts_values , * ts_et ; 
  int ts_count ; 
  Scheme_Object * * loc_names ; 
  Scheme_Object * * loc_values , * loc_et ; 
  int loc_count ; 
  int i ; 
  static const char * arity_fields [1 ] = {
    "value" }
  ; 
  static const char * date_fields [10 ] = {
    "second" , "minute" , "hour" , "day" , "month" , "year" , "week-day" , "year-day" , "dst?" , "time-zone-offset" }
  ; 
  static const char * location_fields [10 ] = {
    "source" , "line" , "column" , "position" , "span" }
  ; 
  char * __funcarg48 = NULLED_OUT ; 
  char * __funcarg46 = NULLED_OUT ; 
  Scheme_Object * __funcarg44 = NULLED_OUT ; 
  char * __funcarg43 = NULLED_OUT ; 
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
  PREPARE_VAR_STACK(16);
  BLOCK_SETUP_TOP((PUSH(ts_et, 0), PUSH(env, 1), PUSH(loc_names, 2), PUSH(as_values, 3), PUSH(loc_values, 4), PUSH(ts_names, 5), PUSH(loc_et, 6), PUSH(as_et, 7), PUSH(ts_values, 8), PUSH(as_names, 9)));
# define XfOrM1_COUNT (10)
# define SETUP_XfOrM1(x) SETUP(XfOrM1_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  as_names = NULLED_OUT ; 
  as_values = NULLED_OUT ; 
  as_et = NULLED_OUT ; 
  ts_names = NULLED_OUT ; 
  ts_values = NULLED_OUT ; 
  ts_et = NULLED_OUT ; 
  loc_names = NULLED_OUT ; 
  loc_values = NULLED_OUT ; 
  loc_et = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM1(_), register_traversers () ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_arity_at_least , sizeof (scheme_arity_at_least ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_make_arity_at_least , sizeof (scheme_make_arity_at_least ) ) ); 
  scheme_arity_at_least = FUNCCALL_AGAIN(scheme_make_struct_type_from_string ("arity-at-least" , ((void * ) 0 ) , 1 , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ); 
  as_names = FUNCCALL_AGAIN(scheme_make_struct_names_from_array ("arity-at-least" , 1 , arity_fields , 0x80 , & as_count ) ); 
  as_values = FUNCCALL_AGAIN(scheme_make_struct_values (scheme_arity_at_least , as_names , as_count , 0x80 ) ); 
  scheme_make_arity_at_least = as_values [1 ] ; 
  for (i = 0 ; i < as_count - 1 ; i ++ ) {
#   define XfOrM12_COUNT (0+XfOrM1_COUNT)
#   define SETUP_XfOrM12(x) SETUP_XfOrM1(x)
    (__funcarg48 = FUNCCALL(SETUP_XfOrM12(_), scheme_symbol_val (as_names [i ] ) ), FUNCCALL_AGAIN(scheme_add_global_constant (__funcarg48 , as_values [i ] , env ) )) ; 
  }
  as_et = FUNCCALL(SETUP_XfOrM1(_), scheme_make_struct_exptime (as_names , as_count , ((void * ) 0 ) , ((void * ) 0 ) , 0x80 ) ); 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_keyword_symbol (as_names [as_count - 1 ] , as_et , env ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_date , sizeof (scheme_date ) ) ); 
  scheme_date = FUNCCALL_AGAIN(scheme_make_struct_type_from_string ("date" , ((void * ) 0 ) , 10 , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ); 
  ts_names = FUNCCALL_AGAIN(scheme_make_struct_names_from_array ("date" , 10 , date_fields , 0x80 , & ts_count ) ); 
  ts_values = FUNCCALL_AGAIN(scheme_make_struct_values (scheme_date , ts_names , ts_count , 0x80 ) ); 
  for (i = 0 ; i < ts_count - 1 ; i ++ ) {
#   define XfOrM10_COUNT (0+XfOrM1_COUNT)
#   define SETUP_XfOrM10(x) SETUP_XfOrM1(x)
    (__funcarg46 = FUNCCALL(SETUP_XfOrM10(_), scheme_symbol_val (ts_names [i ] ) ), FUNCCALL_AGAIN(scheme_add_global_constant (__funcarg46 , ts_values [i ] , env ) )) ; 
  }
  ts_et = FUNCCALL(SETUP_XfOrM1(_), scheme_make_struct_exptime (ts_names , ts_count , ((void * ) 0 ) , ((void * ) 0 ) , 0x80 ) ); 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_keyword_symbol (ts_names [ts_count - 1 ] , ts_et , env ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & location_struct , sizeof (location_struct ) ) ); 
  location_struct = (__funcarg44 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim (check_location_fields ) ), FUNCCALL_AGAIN(scheme_make_struct_type_from_string ("srcloc" , ((void * ) 0 ) , 5 , ((void * ) 0 ) , __funcarg44 , 1 ) )) ; 
  loc_names = FUNCCALL_AGAIN(scheme_make_struct_names_from_array ("srcloc" , 5 , location_fields , 0x80 | 0x10 , & loc_count ) ); 
  loc_values = FUNCCALL_AGAIN(scheme_make_struct_values (location_struct , loc_names , loc_count , 0x80 | 0x10 ) ); 
  for (i = 0 ; i < loc_count - 1 ; i ++ ) {
#   define XfOrM8_COUNT (0+XfOrM1_COUNT)
#   define SETUP_XfOrM8(x) SETUP_XfOrM1(x)
    (__funcarg43 = FUNCCALL(SETUP_XfOrM8(_), scheme_symbol_val (loc_names [i ] ) ), FUNCCALL_AGAIN(scheme_add_global_constant (__funcarg43 , loc_values [i ] , env ) )) ; 
  }
  loc_et = FUNCCALL(SETUP_XfOrM1(_), scheme_make_struct_exptime (loc_names , loc_count , ((void * ) 0 ) , ((void * ) 0 ) , 0x80 | 0x10 ) ); 
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_keyword_symbol (loc_names [loc_count - 1 ] , loc_et , env ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & write_property , sizeof (write_property ) ) ); 
  {
    Scheme_Object * guard , * a [2 ] , * pred , * access ; 
    BLOCK_SETUP((PUSH(pred, 0+XfOrM1_COUNT), PUSHARRAY(a, 2, 1+XfOrM1_COUNT), PUSH(access, 4+XfOrM1_COUNT), PUSH(guard, 5+XfOrM1_COUNT)));
#   define XfOrM6_COUNT (6+XfOrM1_COUNT)
#   define SETUP_XfOrM6(x) SETUP(XfOrM6_COUNT)
    guard = NULLED_OUT ; 
    a[0] = NULLED_OUT ; 
    a[1] = NULLED_OUT ; 
    pred = NULLED_OUT ; 
    access = NULLED_OUT ; 
    guard = FUNCCALL(SETUP_XfOrM6(_), scheme_make_prim_w_arity (check_write_property_value_ok , "guard-for-prop:custom-write" , 2 , 2 ) ); 
    a [0 ] = FUNCCALL(SETUP_XfOrM6(_), scheme_intern_symbol ("custom-write" ) ); 
    a [1 ] = guard ; 
    FUNCCALL(SETUP_XfOrM6(_), make_struct_type_property (2 , a ) ); 
    write_property = scheme_current_thread -> ku . multiple . array [0 ] ; 
    pred = scheme_current_thread -> ku . multiple . array [1 ] ; 
    access = scheme_current_thread -> ku . multiple . array [2 ] ; 
    FUNCCALL(SETUP_XfOrM6(_), scheme_add_global_constant ("prop:custom-write" , write_property , env ) ); 
    FUNCCALL_AGAIN(scheme_add_global_constant ("custom-write?" , pred , env ) ); 
    FUNCCALL_AGAIN(scheme_add_global_constant ("custom-write-accessor" , access , env ) ); 
  }
  FUNCCALL(SETUP_XfOrM1(_), scheme_register_static ((void * ) & evt_property , sizeof (evt_property ) ) ); 
  {
    Scheme_Object * guard ; 
    BLOCK_SETUP((PUSH(guard, 0+XfOrM1_COUNT)));
#   define XfOrM5_COUNT (1+XfOrM1_COUNT)
#   define SETUP_XfOrM5(x) SETUP(XfOrM5_COUNT)
    guard = NULLED_OUT ; 
    guard = FUNCCALL(SETUP_XfOrM5(_), scheme_make_prim_w_arity (check_evt_property_value_ok , "guard-for-prop:evt" , 2 , 2 ) ); 
    evt_property = (__funcarg41 = FUNCCALL(SETUP_XfOrM5(_), scheme_intern_symbol ("evt" ) ), FUNCCALL_AGAIN(scheme_make_struct_type_property_w_guard (__funcarg41 , guard ) )) ; 
    FUNCCALL_AGAIN(scheme_add_global_constant ("prop:evt" , evt_property , env ) ); 
    FUNCCALL_AGAIN(scheme_add_evt (scheme_structure_type , (Scheme_Ready_Fun ) evt_struct_is_ready , ((void * ) 0 ) , is_evt_struct , 1 ) ); 
  }
  {
#   define XfOrM4_COUNT (0+XfOrM1_COUNT)
#   define SETUP_XfOrM4(x) SETUP_XfOrM1(x)
    FUNCCALL(SETUP_XfOrM4(_), scheme_register_static ((void * ) & proc_property , sizeof (proc_property ) ) ); 
    proc_property = (__funcarg40 = FUNCCALL(SETUP_XfOrM4(_), scheme_intern_symbol ("procedure" ) ), FUNCCALL_AGAIN(scheme_make_struct_type_property (__funcarg40 ) )) ; 
    FUNCCALL_AGAIN(scheme_add_global_constant ("prop:procedure" , proc_property , env ) ); 
  }
  {
    Scheme_Object * guard ; 
    BLOCK_SETUP((PUSH(guard, 0+XfOrM1_COUNT)));
#   define XfOrM3_COUNT (1+XfOrM1_COUNT)
#   define SETUP_XfOrM3(x) SETUP(XfOrM3_COUNT)
    guard = NULLED_OUT ; 
    FUNCCALL(SETUP_XfOrM3(_), scheme_register_static ((void * ) & scheme_input_port_property , sizeof (scheme_input_port_property ) ) ); 
    FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_output_port_property , sizeof (scheme_output_port_property ) ) ); 
    guard = FUNCCALL_AGAIN(scheme_make_prim_w_arity (check_input_port_property_value_ok , "guard-for-prop:input-port" , 2 , 2 ) ); 
    scheme_input_port_property = (__funcarg39 = FUNCCALL(SETUP_XfOrM3(_), scheme_intern_symbol ("input-port" ) ), FUNCCALL_AGAIN(scheme_make_struct_type_property_w_guard (__funcarg39 , guard ) )) ; 
    guard = FUNCCALL_AGAIN(scheme_make_prim_w_arity (check_output_port_property_value_ok , "guard-for-prop:output-port" , 2 , 2 ) ); 
    scheme_output_port_property = (__funcarg38 = FUNCCALL(SETUP_XfOrM3(_), scheme_intern_symbol ("output-port" ) ), FUNCCALL_AGAIN(scheme_make_struct_type_property_w_guard (__funcarg38 , guard ) )) ; 
    FUNCCALL_AGAIN(scheme_add_global_constant ("prop:input-port" , scheme_input_port_property , env ) ); 
    FUNCCALL_AGAIN(scheme_add_global_constant ("prop:output-port" , scheme_output_port_property , env ) ); 
  }
  FUNCCALL(SETUP_XfOrM1(_), scheme_register_static ((void * ) & scheme_recur_symbol , sizeof (scheme_recur_symbol ) ) ); 
  FUNCCALL(SETUP_XfOrM1(_), scheme_register_static ((void * ) & scheme_display_symbol , sizeof (scheme_display_symbol ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_write_special_symbol , sizeof (scheme_write_special_symbol ) ) ); 
  scheme_recur_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("recur" ) ); 
  scheme_display_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("display" ) ); 
  scheme_write_special_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("write-special" ) ); 
  FUNCCALL_AGAIN(scheme_add_evt (scheme_wrap_evt_type , (Scheme_Ready_Fun ) wrapped_evt_is_ready , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ); 
  FUNCCALL_AGAIN(scheme_add_evt (scheme_handle_evt_type , (Scheme_Ready_Fun ) wrapped_evt_is_ready , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ); 
  FUNCCALL_AGAIN(scheme_add_evt (scheme_nack_guard_evt_type , (Scheme_Ready_Fun ) nack_guard_evt_is_ready , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ); 
  FUNCCALL_AGAIN(scheme_add_evt (scheme_nack_evt_type , (Scheme_Ready_Fun ) nack_evt_is_ready , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ); 
  FUNCCALL_AGAIN(scheme_add_evt (scheme_poll_evt_type , (Scheme_Ready_Fun ) poll_evt_is_ready , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_make_struct_type_proc , sizeof (scheme_make_struct_type_proc ) ) ); 
  scheme_make_struct_type_proc = FUNCCALL_AGAIN(scheme_make_prim_w_everything (make_struct_type , 0 , "make-struct-type" , 4 , 10 , 0 , 5 , 5 ) ); 
  FUNCCALL_AGAIN(scheme_add_global_constant ("make-struct-type" , scheme_make_struct_type_proc , env ) ); 
  (__funcarg37 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_everything (make_struct_type_property , 0 , "make-struct-type-property" , 1 , 2 , 0 , 3 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-struct-type-property" , __funcarg37 , env ) )) ; 
  (__funcarg36 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (make_struct_field_accessor , "make-struct-field-accessor" , 2 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-struct-field-accessor" , __funcarg36 , env ) )) ; 
  (__funcarg35 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (make_struct_field_mutator , "make-struct-field-mutator" , 2 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-struct-field-mutator" , __funcarg35 , env ) )) ; 
  (__funcarg34 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (scheme_wrap_evt , "wrap-evt" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("wrap-evt" , __funcarg34 , env ) )) ; 
  (__funcarg33 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (handle_evt , "handle-evt" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("handle-evt" , __funcarg33 , env ) )) ; 
  (__funcarg32 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (nack_evt , "nack-guard-evt" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("nack-guard-evt" , __funcarg32 , env ) )) ; 
  (__funcarg31 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (scheme_poll_evt , "poll-guard-evt" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("poll-guard-evt" , __funcarg31 , env ) )) ; 
  (__funcarg30 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (handle_evt_p , "handle-evt?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("handle-evt?" , __funcarg30 , env ) )) ; 
  (__funcarg29 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (struct_p , "struct?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("struct?" , __funcarg29 , env ) )) ; 
  (__funcarg28 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (struct_type_p , "struct-type?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("struct-type?" , __funcarg28 , env ) )) ; 
  (__funcarg27 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (struct_type_property_p , "struct-type-property?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("struct-type-property?" , __funcarg27 , env ) )) ; 
  (__funcarg26 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (proc_struct_type_p , "procedure-struct-type?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("procedure-struct-type?" , __funcarg26 , env ) )) ; 
  (__funcarg25 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_everything (struct_info , 0 , "struct-info" , 1 , 1 , 0 , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("struct-info" , __funcarg25 , env ) )) ; 
  (__funcarg24 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_everything (struct_type_info , 0 , "struct-type-info" , 1 , 1 , 0 , 8 , 8 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("struct-type-info" , __funcarg24 , env ) )) ; 
  (__funcarg23 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (struct_type_pred , "struct-type-make-predicate" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("struct-type-make-predicate" , __funcarg23 , env ) )) ; 
  (__funcarg22 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (struct_type_constr , "struct-type-make-constructor" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("struct-type-make-constructor" , __funcarg22 , env ) )) ; 
  (__funcarg21 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (struct_to_vector , "struct->vector" , 1 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("struct->vector" , __funcarg21 , env ) )) ; 
  (__funcarg20 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (struct_setter_p , "struct-mutator-procedure?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("struct-mutator-procedure?" , __funcarg20 , env ) )) ; 
  (__funcarg19 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (struct_getter_p , "struct-accessor-procedure?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("struct-accessor-procedure?" , __funcarg19 , env ) )) ; 
  (__funcarg18 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (struct_pred_p , "struct-predicate-procedure?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("struct-predicate-procedure?" , __funcarg18 , env ) )) ; 
  (__funcarg17 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (struct_constr_p , "struct-constructor-procedure?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("struct-constructor-procedure?" , __funcarg17 , env ) )) ; 
  (__funcarg16 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (make_inspector , "make-inspector" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-inspector" , __funcarg16 , env ) )) ; 
  (__funcarg15 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (make_sibling_inspector , "make-sibling-inspector" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-sibling-inspector" , __funcarg15 , env ) )) ; 
  (__funcarg14 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (inspector_p , "inspector?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("inspector?" , __funcarg14 , env ) )) ; 
  (__funcarg13 = FUNCCALL(SETUP_XfOrM1(_), scheme_register_parameter (current_inspector , "current-inspector" , MZCONFIG_INSPECTOR ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-inspector" , __funcarg13 , env ) )) ; 
  (__funcarg12 = FUNCCALL(SETUP_XfOrM1(_), scheme_register_parameter (current_code_inspector , "current-code-inspector" , MZCONFIG_CODE_INSPECTOR ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-code-inspector" , __funcarg12 , env ) )) ; 
  (__funcarg11 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (make_special_comment , "make-special-comment" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-special-comment" , __funcarg11 , env ) )) ; 
  (__funcarg10 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_arity (special_comment_value , "special-comment-value" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("special-comment-value" , __funcarg10 , env ) )) ; 
  (__funcarg9 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (special_comment_p , "special-comment?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("special-comment?" , __funcarg9 , env ) )) ; 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & ellipses_symbol , sizeof (ellipses_symbol ) ) ); 
  ellipses_symbol = FUNCCALL_AGAIN(scheme_intern_symbol ("..." ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_source_property , sizeof (scheme_source_property ) ) ); 
  {
    Scheme_Object * guard ; 
    BLOCK_SETUP((PUSH(guard, 0+XfOrM1_COUNT)));
#   define XfOrM2_COUNT (1+XfOrM1_COUNT)
#   define SETUP_XfOrM2(x) SETUP(XfOrM2_COUNT)
    guard = NULLED_OUT ; 
    guard = FUNCCALL(SETUP_XfOrM2(_), scheme_make_prim_w_arity (check_exn_source_property_value_ok , "guard-for-prop:exn:srclocs" , 2 , 2 ) ); 
    scheme_source_property = (__funcarg8 = FUNCCALL(SETUP_XfOrM2(_), scheme_intern_symbol ("prop:exn:srclocs" ) ), FUNCCALL_AGAIN(scheme_make_struct_type_property_w_guard (__funcarg8 , guard ) )) ; 
  }
  FUNCCALL(SETUP_XfOrM1(_), scheme_add_global_constant ("prop:exn:srclocs" , scheme_source_property , env ) ); 
  (__funcarg7 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (exn_source_p , "exn:srclocs?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("exn:srclocs?" , __funcarg7 , env ) )) ; 
  (__funcarg6 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_folding_prim (exn_source_get , "exn:srclocs-accessor" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("exn:srclocs-accessor" , __funcarg6 , env ) )) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_initial_inspectors (void ) {
  Scheme_Inspector * superior , * root ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(superior, 0), PUSH(root, 1)));
# define XfOrM13_COUNT (2)
# define SETUP_XfOrM13(x) SETUP(XfOrM13_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  superior = NULLED_OUT ; 
  root = NULLED_OUT ; 
  superior = ((Scheme_Inspector * ) FUNCCALL(SETUP_XfOrM13(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Inspector ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  superior -> so . type = scheme_inspector_type ; 
  superior -> depth = 0 ; 
  root = ((Scheme_Inspector * ) FUNCCALL(SETUP_XfOrM13(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Inspector ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  root -> so . type = scheme_inspector_type ; 
  root -> depth = 1 ; 
  root -> superior = superior ; 
  RET_VALUE_START ((Scheme_Object * ) root ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_inspector (Scheme_Object * superior ) {
  Scheme_Inspector * naya ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(superior, 0), PUSH(naya, 1)));
# define XfOrM14_COUNT (2)
# define SETUP_XfOrM14(x) SETUP(XfOrM14_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  naya = NULLED_OUT ; 
  naya = ((Scheme_Inspector * ) FUNCCALL(SETUP_XfOrM14(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Inspector ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  naya -> so . type = scheme_inspector_type ; 
  naya -> depth = ((Scheme_Inspector * ) superior ) -> depth + 1 ; 
  naya -> superior = (Scheme_Inspector * ) superior ; 
  RET_VALUE_START ((Scheme_Object * ) naya ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_inspector (int argc , Scheme_Object * * argv ) {
  Scheme_Object * superior ; 
  Scheme_Config * __funcarg49 = NULLED_OUT ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(superior, 0)));
# define XfOrM15_COUNT (1)
# define SETUP_XfOrM15(x) SETUP(XfOrM15_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  superior = NULLED_OUT ; 
  if (argc ) {
#   define XfOrM16_COUNT (0+XfOrM15_COUNT)
#   define SETUP_XfOrM16(x) SETUP_XfOrM15(x)
    superior = argv [0 ] ; 
    if (! ((Scheme_Type ) (((((long ) (superior ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (superior ) ) -> type ) ) == (Scheme_Type ) (scheme_inspector_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("make-inspector" , "inspector" , 0 , argc , argv ) ); 
  }
  else superior = (__funcarg49 = FUNCCALL(SETUP_XfOrM15(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg49 , MZCONFIG_INSPECTOR ) )) ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_inspector (superior ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_sibling_inspector (int argc , Scheme_Object * * argv ) {
  Scheme_Object * superior ; 
  Scheme_Config * __funcarg50 = NULLED_OUT ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(superior, 0)));
# define XfOrM17_COUNT (1)
# define SETUP_XfOrM17(x) SETUP(XfOrM17_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  superior = NULLED_OUT ; 
  if (argc ) {
#   define XfOrM18_COUNT (0+XfOrM17_COUNT)
#   define SETUP_XfOrM18(x) SETUP_XfOrM17(x)
    superior = argv [0 ] ; 
    if (! ((Scheme_Type ) (((((long ) (superior ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (superior ) ) -> type ) ) == (Scheme_Type ) (scheme_inspector_type ) ) )
      FUNCCALL_EMPTY(scheme_wrong_type ("make-sibling-inspector" , "inspector" , 0 , argc , argv ) ); 
  }
  else superior = (__funcarg50 = FUNCCALL(SETUP_XfOrM17(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg50 , MZCONFIG_INSPECTOR ) )) ; 
  superior = (Scheme_Object * ) ((Scheme_Inspector * ) superior ) -> superior ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_inspector (superior ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * inspector_p (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_inspector_type ) ) ? scheme_true : scheme_false ) ; 
}
int scheme_is_subinspector (Scheme_Object * i , Scheme_Object * sup ) {
  /* No conversion */
  Scheme_Inspector * ins , * superior ; 
  if ((((i ) ) == (scheme_false ) ) )
    return 1 ; 
  ins = (Scheme_Inspector * ) i ; 
  superior = (Scheme_Inspector * ) sup ; 
  while (ins -> depth > superior -> depth ) {
    if (ins -> superior == superior )
      return 1 ; 
    ins = ins -> superior ; 
  }
  return 0 ; 
}
static Scheme_Object * current_inspector (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("current-inspector" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_INSPECTOR ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , inspector_p , "inspector" , 0 ) ; 
}
static Scheme_Object * current_code_inspector (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("current-code-inspector" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_CODE_INSPECTOR ) ) << 1 ) | 0x1 ) ) , argc , argv , - 1 , inspector_p , "inspector" , 0 ) ; 
}
static Scheme_Object * prop_pred (int argc , Scheme_Object * * args , Scheme_Object * prim ) {
  Scheme_Struct_Type * stype ; 
  Scheme_Object * prop = ((Scheme_Primitive_Closure * ) prim ) -> val [0 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(prop, 0), PUSH(stype, 1)));
# define XfOrM25_COUNT (2)
# define SETUP_XfOrM25(x) SETUP(XfOrM25_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  stype = NULLED_OUT ; 
  if ((((Scheme_Type ) (((((long ) (args [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (args [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) )
    stype = ((Scheme_Structure * ) args [0 ] ) -> stype ; 
  else if (((Scheme_Type ) (((((long ) (args [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_struct_type_type ) ) )
    stype = (Scheme_Struct_Type * ) args [0 ] ; 
  else RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
  if (stype -> num_props < 0 ) {
#   define XfOrM29_COUNT (0+XfOrM25_COUNT)
#   define SETUP_XfOrM29(x) SETUP_XfOrM25(x)
    if (FUNCCALL(SETUP_XfOrM29(_), scheme_hash_get ((Scheme_Hash_Table * ) stype -> props , prop ) ))
      RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
  }
  else {
    int i ; 
    for (i = stype -> num_props ; i -- ; ) {
      if ((((((Scheme_Simple_Object * ) (stype -> props [i ] ) ) -> u . pair_val . car ) ) == (prop ) ) )
        RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
    }
  }
  RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
__xform_nongcing__ static Scheme_Object * do_prop_accessor (Scheme_Object * prop , Scheme_Object * arg ) {
  /* No conversion */
  Scheme_Struct_Type * stype ; 
  if ((((Scheme_Type ) (((((long ) (arg ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (arg ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (arg ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (arg ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) )
    stype = ((Scheme_Structure * ) arg ) -> stype ; 
  else if (((Scheme_Type ) (((((long ) (arg ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (arg ) ) -> type ) ) == (Scheme_Type ) (scheme_struct_type_type ) ) )
    stype = (Scheme_Struct_Type * ) arg ; 
  else stype = ((void * ) 0 ) ; 
  if (stype ) {
    if (stype -> num_props < 0 ) {
      Scheme_Object * v ; 
      v = (Scheme_Object * ) scheme_eq_hash_get ((Scheme_Hash_Table * ) stype -> props , prop ) ; 
      if (v )
        return v ; 
    }
    else {
      int i ; 
      for (i = stype -> num_props ; i -- ; ) {
        if ((((((Scheme_Simple_Object * ) (stype -> props [i ] ) ) -> u . pair_val . car ) ) == (prop ) ) )
          return (((Scheme_Simple_Object * ) (stype -> props [i ] ) ) -> u . pair_val . cdr ) ; 
      }
    }
  }
  return ((void * ) 0 ) ; 
}
static Scheme_Object * prop_accessor (int argc , Scheme_Object * * args , Scheme_Object * prim ) {
  /* No conversion */
  Scheme_Object * v ; 
  v = do_prop_accessor (((Scheme_Primitive_Closure * ) prim ) -> val [0 ] , args [0 ] ) ; 
  if (! v )
    scheme_wrong_type (((Scheme_Primitive_Proc * ) prim ) -> name , "struct or struct-type with property" , 0 , 1 , args ) ; 
  return v ; 
}
static Scheme_Object * make_struct_type_property (int argc , Scheme_Object * argv [] ) {
  Scheme_Struct_Property * p ; 
  Scheme_Object * a [3 ] , * v ; 
  char * name ; 
  int len ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSH(name, 0), PUSH(v, 1), PUSHARRAY(a, 3, 2), PUSH(argv, 5), PUSH(p, 6)));
# define XfOrM37_COUNT (7)
# define SETUP_XfOrM37(x) SETUP(XfOrM37_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  p = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  a[2] = NULLED_OUT ; 
  v = NULLED_OUT ; 
  name = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
    FUNCCALL(SETUP_XfOrM37(_), scheme_wrong_type ("make-struct-type-property" , "symbol" , 0 , argc , argv ) ); 
  if ((argc > 1 ) && (! (((argv [1 ] ) ) == (scheme_false ) ) ) && ! FUNCCALL(SETUP_XfOrM37(_), scheme_check_proc_arity (((void * ) 0 ) , 2 , 1 , argc , argv ) )) {
#   define XfOrM38_COUNT (0+XfOrM37_COUNT)
#   define SETUP_XfOrM38(x) SETUP_XfOrM37(x)
    FUNCCALL(SETUP_XfOrM38(_), scheme_wrong_type ("make-struct-type-property" , "procedure (arity 2) or #f" , 1 , argc , argv ) ); 
  }
  p = ((Scheme_Struct_Property * ) FUNCCALL(SETUP_XfOrM37(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Struct_Property ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  p -> so . type = scheme_struct_property_type ; 
  p -> name = argv [0 ] ; 
  if ((argc > 1 ) && (! (((argv [1 ] ) ) == (scheme_false ) ) ) )
    p -> guard = argv [1 ] ; 
  a [0 ] = (Scheme_Object * ) p ; 
  len = (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (argv [0 ] ) ) ) -> len ) ; 
  name = ((char * ) FUNCCALL(SETUP_XfOrM37(_), GC_malloc_atomic (sizeof (char ) * (len + 2 ) ) )) ; 
  (memcpy (name , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (argv [0 ] ) ) ) -> s ) , len ) ) ; 
  name [len ] = '?' ; 
  name [len + 1 ] = 0 ; 
  v = FUNCCALL(SETUP_XfOrM37(_), scheme_make_folding_prim_closure (prop_pred , 1 , a , name , 1 , 1 , 0 ) ); 
  a [1 ] = v ; 
  name = ((char * ) FUNCCALL(SETUP_XfOrM37(_), GC_malloc_atomic (sizeof (char ) * (len + 10 ) ) )) ; 
  (memcpy (name , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (argv [0 ] ) ) ) -> s ) , len ) ) ; 
  (memcpy (name + len , "-accessor" , 10 ) ) ; 
  v = FUNCCALL(SETUP_XfOrM37(_), scheme_make_folding_prim_closure (prop_accessor , 1 , a , name , 1 , 1 , 0 ) ); 
  a [2 ] = v ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM37(_), scheme_values (3 , a ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_struct_type_property_w_guard (Scheme_Object * name , Scheme_Object * guard ) {
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * a [2 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 2, 0), PUSH(p, 3)));
# define XfOrM39_COUNT (4)
# define SETUP_XfOrM39(x) SETUP(XfOrM39_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  a [0 ] = name ; 
  a [1 ] = guard ; 
  (void ) FUNCCALL(SETUP_XfOrM39(_), make_struct_type_property (2 , a ) ); 
  RET_VALUE_START (p -> ku . multiple . array [0 ] ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_struct_type_property (Scheme_Object * name ) {
  /* No conversion */
  return scheme_make_struct_type_property_w_guard (name , scheme_false ) ; 
}
Scheme_Object * scheme_struct_type_property_ref (Scheme_Object * prop , Scheme_Object * s ) {
  /* No conversion */
  return do_prop_accessor (prop , s ) ; 
}
static Scheme_Object * struct_type_property_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_struct_property_type ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * guard_property (Scheme_Object * prop , Scheme_Object * v , Scheme_Struct_Type * t ) {
  Scheme_Struct_Property * p = (Scheme_Struct_Property * ) prop ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(9);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(p, 1)));
# define XfOrM43_COUNT (2)
# define SETUP_XfOrM43(x) SETUP(XfOrM43_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (p -> guard ) {
    Scheme_Object * a [2 ] , * info [8 ] , * l ; 
    BLOCK_SETUP((PUSHARRAY(info, 8, 0+XfOrM43_COUNT), PUSHARRAY(a, 2, 3+XfOrM43_COUNT), PUSH(l, 6+XfOrM43_COUNT)));
#   define XfOrM44_COUNT (7+XfOrM43_COUNT)
#   define SETUP_XfOrM44(x) SETUP(XfOrM44_COUNT)
    a[0] = NULLED_OUT ; 
    a[1] = NULLED_OUT ; 
    NULL_OUT_ARRAY (info ) ; 
    l = NULLED_OUT ; 
    a [0 ] = (Scheme_Object * ) t ; 
    FUNCCALL(SETUP_XfOrM44(_), get_struct_type_info (1 , a , info , 1 ) ); 
    l = FUNCCALL_AGAIN(scheme_build_list (8 , info ) ); 
    a [0 ] = v ; 
    a [1 ] = l ; 
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM44(_), scheme_do_eval (p -> guard , 2 , a , 1 ) )) RET_VALUE_END ; 
  }
  else RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int extract_accessor_offset (Scheme_Object * acc ) {
  /* No conversion */
  Struct_Proc_Info * i = (Struct_Proc_Info * ) ((Scheme_Primitive_Closure * ) acc ) -> val [0 ] ; 
  if (i -> struct_type -> name_pos )
    return i -> struct_type -> parent_types [i -> struct_type -> name_pos - 1 ] -> num_slots ; 
  else return 0 ; 
}
static Scheme_Object * check_evt_property_value_ok (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * v , * l , * acc ; 
  int pos , num_islots ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(acc, 1), PUSH(l, 2), PUSH(argv, 3)));
# define XfOrM46_COUNT (4)
# define SETUP_XfOrM46(x) SETUP(XfOrM46_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  l = NULLED_OUT ; 
  acc = NULLED_OUT ; 
  v = argv [0 ] ; 
  if (FUNCCALL(SETUP_XfOrM46(_), scheme_is_evt (v ) ))
    RET_VALUE_START (v ) RET_VALUE_END ; 
  if (FUNCCALL(SETUP_XfOrM46(_), scheme_check_proc_arity (((void * ) 0 ) , 1 , 0 , 1 , & v ) ))
    RET_VALUE_START (v ) RET_VALUE_END ; 
  if (! (((((long ) (v ) ) & 0x1 ) && ((((long ) (v ) ) >> 1 ) >= 0 ) ) || (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) && ((& ((Scheme_Bignum * ) v ) -> iso ) -> so . keyex & 0x1 ) ) ) )
    FUNCCALL(SETUP_XfOrM46(_), scheme_arg_mismatch ("guard-for-prop:evt" , "property value is not a evt, procedure (arity 1), or exact non-negative integer: " , v ) ); 
  l = argv [1 ] ; 
  l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
  num_islots = (((long ) ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ) ) >> 1 ) ; 
  l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
  l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
  acc = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
  l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
  l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
  l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
  if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
    pos = num_islots ; 
  else pos = (((long ) (v ) ) >> 1 ) ; 
  if (pos >= num_islots ) {
#   define XfOrM50_COUNT (0+XfOrM46_COUNT)
#   define SETUP_XfOrM50(x) SETUP_XfOrM46(x)
    FUNCCALL(SETUP_XfOrM50(_), scheme_arg_mismatch ("guard-for-prop:evt" , "field index >= initialized-field count for structure type: " , v ) ); 
  }
  for (; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
    if ((((long ) ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ) ) >> 1 ) == pos )
      break ; 
  }
  if (! ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#   define XfOrM47_COUNT (0+XfOrM46_COUNT)
#   define SETUP_XfOrM47(x) SETUP_XfOrM46(x)
    FUNCCALL(SETUP_XfOrM47(_), scheme_arg_mismatch ("guard-for-prop:evt" , "field index not declared immutable: " , v ) ); 
  }
  pos += FUNCCALL(SETUP_XfOrM46(_), extract_accessor_offset (acc ) ); 
  v = ((Scheme_Object * ) (void * ) (long ) ((((long ) (pos ) ) << 1 ) | 0x1 ) ) ; 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int evt_struct_is_ready (Scheme_Object * o , Scheme_Schedule_Info * sinfo ) {
  Scheme_Object * v ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(sinfo, 1), PUSH(o, 2)));
# define XfOrM51_COUNT (3)
# define SETUP_XfOrM51(x) SETUP(XfOrM51_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  v = NULLED_OUT ; 
  v = (scheme_struct_type_property_ref (evt_property , o ) ) ; 
  if (! v ) {
#   define XfOrM59_COUNT (0+XfOrM51_COUNT)
#   define SETUP_XfOrM59(x) SETUP_XfOrM51(x)
    if ((scheme_is_input_port (o ) ) ) {
#     define XfOrM61_COUNT (0+XfOrM59_COUNT)
#     define SETUP_XfOrM61(x) SETUP_XfOrM59(x)
      v = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM61(_), scheme_input_port_record (o ) ); 
    }
    else {
#     define XfOrM60_COUNT (0+XfOrM59_COUNT)
#     define SETUP_XfOrM60(x) SETUP_XfOrM59(x)
      v = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM60(_), scheme_output_port_record (o ) ); 
    }
    FUNCCALL(SETUP_XfOrM59(_), scheme_set_sync_target (sinfo , v , ((void * ) 0 ) , ((void * ) 0 ) , 0 , 1 ) ); 
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  if ((((long ) (v ) ) & 0x1 ) )
    v = ((Scheme_Structure * ) o ) -> slots [(((long ) (v ) ) >> 1 ) ] ; 
  if (FUNCCALL(SETUP_XfOrM51(_), scheme_is_evt (v ) )) {
#   define XfOrM58_COUNT (0+XfOrM51_COUNT)
#   define SETUP_XfOrM58(x) SETUP_XfOrM51(x)
    FUNCCALL(SETUP_XfOrM58(_), scheme_set_sync_target (sinfo , v , ((void * ) 0 ) , ((void * ) 0 ) , 0 , 1 ) ); 
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  if ((! (((long ) (v ) ) & 0x1 ) && ((((v ) -> type ) >= scheme_prim_type ) && (((v ) -> type ) <= scheme_native_closure_type ) ) ) ) {
#   define XfOrM52_COUNT (0+XfOrM51_COUNT)
#   define SETUP_XfOrM52(x) SETUP_XfOrM51(x)
    if (sinfo -> false_positive_ok ) {
      sinfo -> potentially_false_positive = 1 ; 
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
    if (FUNCCALL(SETUP_XfOrM52(_), scheme_check_proc_arity (((void * ) 0 ) , 1 , 0 , 1 , & v ) )) {
      Scheme_Object * f = v , * result , * a [1 ] ; 
      BLOCK_SETUP((PUSHARRAY(a, 1, 0+XfOrM52_COUNT), PUSH(result, 3+XfOrM52_COUNT)));
#     define XfOrM53_COUNT (4+XfOrM52_COUNT)
#     define SETUP_XfOrM53(x) SETUP(XfOrM53_COUNT)
      result = NULLED_OUT ; 
      a[0] = NULLED_OUT ; 
      a [0 ] = o ; 
      result = FUNCCALL(SETUP_XfOrM53(_), scheme_apply (f , 1 , a ) ); 
      if (FUNCCALL(SETUP_XfOrM53(_), scheme_is_evt (result ) )) {
#       define XfOrM54_COUNT (0+XfOrM53_COUNT)
#       define SETUP_XfOrM54(x) SETUP_XfOrM53(x)
        {
#         define XfOrM55_COUNT (0+XfOrM54_COUNT)
#         define SETUP_XfOrM55(x) SETUP_XfOrM54(x)
          if ((scheme_fuel_counter ) <= 0 ) {
#           define XfOrM56_COUNT (0+XfOrM55_COUNT)
#           define SETUP_XfOrM56(x) SETUP_XfOrM55(x)
            FUNCCALL(SETUP_XfOrM56(_), scheme_out_of_fuel () ); 
          }
        }
        ; 
        FUNCCALL(SETUP_XfOrM54(_), scheme_set_sync_target (sinfo , result , ((void * ) 0 ) , ((void * ) 0 ) , 0 , 1 ) ); 
        RET_VALUE_START (0 ) RET_VALUE_END ; 
      }
      FUNCCALL(SETUP_XfOrM53(_), scheme_set_sync_target (sinfo , o , o , ((void * ) 0 ) , 0 , 0 ) ); 
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
  }
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int is_evt_struct (Scheme_Object * o ) {
  /* No conversion */
  if (scheme_struct_type_property_ref (evt_property , o ) )
    return 1 ; 
  if (scheme_struct_type_property_ref (scheme_input_port_property , o ) )
    return 1 ; 
  if (scheme_struct_type_property_ref (scheme_output_port_property , o ) )
    return 1 ; 
  return 0 ; 
}
static Scheme_Object * check_port_property_value_ok (const char * name , int input , int argc , Scheme_Object * argv [] ) {
  Scheme_Object * v , * l , * acc ; 
  int pos , num_islots ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(name, 0), PUSH(v, 1), PUSH(acc, 2), PUSH(l, 3), PUSH(argv, 4)));
# define XfOrM63_COUNT (5)
# define SETUP_XfOrM63(x) SETUP(XfOrM63_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  l = NULLED_OUT ; 
  acc = NULLED_OUT ; 
  v = argv [0 ] ; 
  if ((input && (scheme_is_input_port (v ) ) ) || (! input && (scheme_is_output_port (v ) ) ) )
    RET_VALUE_START (v ) RET_VALUE_END ; 
  if (! (((((long ) (v ) ) & 0x1 ) && ((((long ) (v ) ) >> 1 ) >= 0 ) ) || (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) && ((& ((Scheme_Bignum * ) v ) -> iso ) -> so . keyex & 0x1 ) ) ) )
    FUNCCALL(SETUP_XfOrM63(_), scheme_arg_mismatch (name , (input ? "property value is not an input port or exact non-negative integer: " : "property value is not an output port or exact non-negative integer: " ) , v ) ); 
  l = argv [1 ] ; 
  l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
  num_islots = (((long ) ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ) ) >> 1 ) ; 
  l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
  l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
  acc = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
  l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
  l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ; 
  l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
  if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
    pos = num_islots ; 
  else pos = (((long ) (v ) ) >> 1 ) ; 
  if (pos >= num_islots ) {
#   define XfOrM67_COUNT (0+XfOrM63_COUNT)
#   define SETUP_XfOrM67(x) SETUP_XfOrM63(x)
    FUNCCALL(SETUP_XfOrM67(_), scheme_arg_mismatch (name , "field index >= initialized-field count for structure type: " , v ) ); 
  }
  for (; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
    if ((((long ) ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ) ) >> 1 ) == pos )
      break ; 
  }
  if (! ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ) {
#   define XfOrM64_COUNT (0+XfOrM63_COUNT)
#   define SETUP_XfOrM64(x) SETUP_XfOrM63(x)
    FUNCCALL(SETUP_XfOrM64(_), scheme_arg_mismatch (name , "field index not declared immutable: " , v ) ); 
  }
  pos += FUNCCALL(SETUP_XfOrM63(_), extract_accessor_offset (acc ) ); 
  v = ((Scheme_Object * ) (void * ) (long ) ((((long ) (pos ) ) << 1 ) | 0x1 ) ) ; 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * check_input_port_property_value_ok (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return check_port_property_value_ok ("guard-for-prop:input-port" , 1 , argc , argv ) ; 
}
static Scheme_Object * check_output_port_property_value_ok (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return check_port_property_value_ok ("guard-for-prop:output-port" , 0 , argc , argv ) ; 
}
static Scheme_Object * check_write_property_value_ok (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * v ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(v, 0)));
# define XfOrM70_COUNT (1)
# define SETUP_XfOrM70(x) SETUP(XfOrM70_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  v = argv [0 ] ; 
  if (! FUNCCALL(SETUP_XfOrM70(_), scheme_check_proc_arity (((void * ) 0 ) , 3 , 0 , argc , argv ) )) {
#   define XfOrM71_COUNT (0+XfOrM70_COUNT)
#   define SETUP_XfOrM71(x) SETUP_XfOrM70(x)
    FUNCCALL(SETUP_XfOrM71(_), scheme_arg_mismatch ("guard-for-prop:custom-write" , "not a procedure of arity 3: " , v ) ); 
  }
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_is_writable_struct (Scheme_Object * s ) {
  /* No conversion */
  return scheme_struct_type_property_ref (write_property , s ) ; 
}
static char * type_name_string (Scheme_Object * sym ) {
  /* No conversion */
  return (char * ) make_name ("struct:" , (char * ) sym , - 1 , "" , ((void * ) 0 ) , 0 , "" , 0 ) ; 
}
static void wrong_struct_type (char * name , Scheme_Object * expected , Scheme_Object * received , int which , int argc , Scheme_Object * * argv ) {
  char * __funcarg53 = NULLED_OUT ; 
  char * __funcarg52 = NULLED_OUT ; 
  char * __funcarg51 = NULLED_OUT ; 
  PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(expected, 0), PUSH(name, 1), PUSH(__funcarg52, 2), PUSH(argv, 3), PUSH(received, 4)));
# define XfOrM74_COUNT (5)
# define SETUP_XfOrM74(x) SETUP(XfOrM74_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (((expected ) == (received ) ) )
    (__funcarg52 = FUNCCALL(SETUP_XfOrM74(_), type_name_string (expected ) ), __funcarg53 = FUNCCALL(SETUP_XfOrM74(_), type_name_string (received ) ), FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: expects args of type <%s>; " "given instance of a different <%s>" , name , __funcarg52 , __funcarg53 ) )) ; 
  else (__funcarg51 = FUNCCALL(SETUP_XfOrM74(_), type_name_string (expected ) ), FUNCCALL_EMPTY(scheme_wrong_type (name , __funcarg51 , which , argc , argv ) )) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_is_struct_instance (Scheme_Object * type , Scheme_Object * v ) {
  /* No conversion */
  Scheme_Struct_Type * stype = (Scheme_Struct_Type * ) type ; 
  Scheme_Structure * s = (Scheme_Structure * ) v ; 
  return ((stype -> name_pos <= s -> stype -> name_pos ) && (stype == s -> stype -> parent_types [stype -> name_pos ] ) ) ; 
}
Scheme_Object * scheme_struct_ref (Scheme_Object * sv , int pos ) {
  /* No conversion */
  Scheme_Structure * s = (Scheme_Structure * ) sv ; 
  return s -> slots [pos ] ; 
}
void scheme_struct_set (Scheme_Object * sv , int pos , Scheme_Object * v ) {
  /* No conversion */
  Scheme_Structure * s = (Scheme_Structure * ) sv ; 
  s -> slots [pos ] = v ; 
}
Scheme_Object * scheme_make_struct_instance (Scheme_Object * _stype , int argc , Scheme_Object * * args ) {
  Scheme_Structure * inst ; 
  Scheme_Struct_Type * stype ; 
  Scheme_Object * * guard_argv = ((void * ) 0 ) , * v ; 
  int p , i , j , nis , ns , c , gcount ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(args, 0), PUSH(inst, 1), PUSH(v, 2), PUSH(guard_argv, 3), PUSH(stype, 4)));
# define XfOrM78_COUNT (5)
# define SETUP_XfOrM78(x) SETUP(XfOrM78_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  inst = NULLED_OUT ; 
  stype = NULLED_OUT ; 
  v = NULLED_OUT ; 
  stype = (Scheme_Struct_Type * ) _stype ; 
  c = stype -> num_slots ; 
  inst = (Scheme_Structure * ) FUNCCALL(SETUP_XfOrM78(_), GC_malloc_one_tagged (sizeof (Scheme_Structure ) + ((c - 1 ) * sizeof (Scheme_Object * ) ) ) ); 
  inst -> so . type = (stype -> proc_attr ? scheme_proc_struct_type : scheme_structure_type ) ; 
  inst -> stype = stype ; 
  for (p = stype -> name_pos ; p >= 0 ; p -- ) {
#   define XfOrM97_COUNT (0+XfOrM78_COUNT)
#   define SETUP_XfOrM97(x) SETUP_XfOrM78(x)
    if (stype -> parent_types [p ] -> guard ) {
      int got ; 
#     define XfOrM98_COUNT (0+XfOrM97_COUNT)
#     define SETUP_XfOrM98(x) SETUP_XfOrM97(x)
      if (! guard_argv ) {
#       define XfOrM100_COUNT (0+XfOrM98_COUNT)
#       define SETUP_XfOrM100(x) SETUP_XfOrM98(x)
        guard_argv = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM100(_), GC_malloc (sizeof (Scheme_Object * ) * (argc + 1 ) ) )) ; 
        (memcpy (guard_argv , args , sizeof (Scheme_Object * ) * argc ) ) ; 
        args = guard_argv ; 
      }
      gcount = stype -> parent_types [p ] -> num_islots ; 
      guard_argv [argc ] = guard_argv [gcount ] ; 
      guard_argv [gcount ] = stype -> name ; 
      v = FUNCCALL(SETUP_XfOrM98(_), scheme_do_eval (stype -> parent_types [p ] -> guard , gcount + 1 , guard_argv , - 1 ) ); 
      got = (((v ) == (((Scheme_Object * ) 0x6 ) ) ) ? (scheme_current_thread -> ku . multiple . count ) : 1 ) ; 
      if (gcount != got ) {
#       define XfOrM99_COUNT (0+XfOrM98_COUNT)
#       define SETUP_XfOrM99(x) SETUP_XfOrM98(x)
        FUNCCALL(SETUP_XfOrM99(_), scheme_wrong_return_arity ("constructor" , gcount , got , (got == 1 ) ? (Scheme_Object * * ) v : (scheme_current_thread -> ku . multiple . array ) , "calling guard procedure" ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      if (((v ) == (((Scheme_Object * ) 0x6 ) ) ) )
        (memcpy (guard_argv , (scheme_current_thread -> ku . multiple . array ) , gcount * sizeof (Scheme_Object * ) ) ) ; 
      else guard_argv [0 ] = v ; 
      guard_argv [gcount ] = guard_argv [argc ] ; 
    }
  }
  j = c ; 
  i = argc ; 
  for (p = stype -> name_pos ; p >= 0 ; p -- ) {
    if (p ) {
      ns = stype -> parent_types [p ] -> num_slots - stype -> parent_types [p - 1 ] -> num_slots ; 
      nis = stype -> parent_types [p ] -> num_islots - stype -> parent_types [p - 1 ] -> num_islots ; 
    }
    else {
      ns = stype -> parent_types [0 ] -> num_slots ; 
      nis = stype -> parent_types [0 ] -> num_islots ; 
    }
    ns -= nis ; 
    while (ns -- ) {
      inst -> slots [-- j ] = stype -> parent_types [p ] -> uninit_val ; 
    }
    while (nis -- ) {
      inst -> slots [-- j ] = args [-- i ] ; 
    }
  }
  RET_VALUE_START ((Scheme_Object * ) inst ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_struct_instance (int argc , Scheme_Object * * args , Scheme_Object * prim ) {
  /* No conversion */
  return scheme_make_struct_instance (((Scheme_Primitive_Closure * ) prim ) -> val [0 ] , argc , args ) ; 
}
static Scheme_Object * make_simple_struct_instance (int argc , Scheme_Object * * args , Scheme_Object * prim ) {
  Scheme_Structure * inst ; 
  Scheme_Struct_Type * stype = (Scheme_Struct_Type * ) ((Scheme_Primitive_Closure * ) prim ) -> val [0 ] ; 
  int i , c ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(inst, 0), PUSH(args, 1), PUSH(stype, 2)));
# define XfOrM102_COUNT (3)
# define SETUP_XfOrM102(x) SETUP(XfOrM102_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  inst = NULLED_OUT ; 
  c = stype -> num_slots ; 
  inst = (Scheme_Structure * ) FUNCCALL(SETUP_XfOrM102(_), GC_malloc_one_tagged (sizeof (Scheme_Structure ) + ((c - 1 ) * sizeof (Scheme_Object * ) ) ) ); 
  inst -> so . type = scheme_structure_type ; 
  inst -> stype = stype ; 
  for (i = 0 ; i < argc ; i ++ ) {
    inst -> slots [i ] = args [i ] ; 
  }
  RET_VALUE_START ((Scheme_Object * ) inst ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int is_simple_struct_type (Scheme_Struct_Type * stype ) {
  /* No conversion */
  int p ; 
  if (stype -> proc_attr )
    return 0 ; 
  for (p = stype -> name_pos ; p >= 0 ; p -- ) {
    if (stype -> parent_types [p ] -> guard )
      return 0 ; 
    if (stype -> parent_types [p ] -> num_slots != stype -> parent_types [p ] -> num_islots )
      return 0 ; 
  }
  return 1 ; 
}
static Scheme_Object * struct_pred (int argc , Scheme_Object * * args , Scheme_Object * prim ) {
  /* No conversion */
  if ((((Scheme_Type ) (((((long ) (args [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (args [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) ) {
    Scheme_Struct_Type * stype = (Scheme_Struct_Type * ) ((Scheme_Primitive_Closure * ) prim ) -> val [0 ] ; 
    if (((stype -> name_pos <= ((Scheme_Structure * ) args [0 ] ) -> stype -> name_pos ) && (stype == ((Scheme_Structure * ) args [0 ] ) -> stype -> parent_types [stype -> name_pos ] ) ) )
      return scheme_true ; 
  }
  return scheme_false ; 
}
static int parse_pos (const char * who , Struct_Proc_Info * i , Scheme_Object * * args , int argc ) {
  /* No conversion */
  int pos ; 
  if (! (((long ) (args [1 ] ) ) & 0x1 ) || ((((long ) (args [1 ] ) ) >> 1 ) < 0 ) ) {
    if (((Scheme_Type ) (((((long ) (args [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) && ((& ((Scheme_Bignum * ) args [1 ] ) -> iso ) -> so . keyex & 0x1 ) ) {
      pos = 32769 ; 
    }
    else {
      if (! who )
        who = i -> func_name ; 
      scheme_wrong_type (who , "non-negative exact integer" , 1 , argc , args ) ; 
      return 0 ; 
    }
  }
  else pos = (((long ) (args [1 ] ) ) >> 1 ) ; 
  if ((pos < i -> struct_type -> num_slots ) && i -> struct_type -> name_pos )
    pos += i -> struct_type -> parent_types [i -> struct_type -> name_pos - 1 ] -> num_slots ; 
  if (pos >= i -> struct_type -> num_slots ) {
    int sc ; 
    if (! who )
      who = i -> func_name ; 
    sc = (i -> struct_type -> name_pos ? (i -> struct_type -> num_slots - i -> struct_type -> parent_types [i -> struct_type -> name_pos - 1 ] -> num_slots ) : i -> struct_type -> num_slots ) ; 
    if (! sc ) {
      scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: no slots in <struct:%S>; given index: %V" , who , i -> struct_type -> name , args [1 ] ) ; 
    }
    else {
      scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: slot index for <struct:%S> not in [0, %d]: %V" , who , i -> struct_type -> name , sc - 1 , args [1 ] ) ; 
    }
    return 0 ; 
  }
  return pos ; 
}
static Scheme_Object * struct_getter (int argc , Scheme_Object * * args , Scheme_Object * prim ) {
  Scheme_Structure * inst ; 
  int pos ; 
  Struct_Proc_Info * i = (Struct_Proc_Info * ) ((Scheme_Primitive_Closure * ) prim ) -> val [0 ] ; 
  char * __funcarg54 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(inst, 0), PUSH(args, 1), PUSH(i, 2)));
# define XfOrM117_COUNT (3)
# define SETUP_XfOrM117(x) SETUP(XfOrM117_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  inst = NULLED_OUT ; 
  inst = (Scheme_Structure * ) args [0 ] ; 
  if (! (((Scheme_Type ) (((((long ) (args [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (args [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) ) {
#   define XfOrM119_COUNT (0+XfOrM117_COUNT)
#   define SETUP_XfOrM119(x) SETUP_XfOrM117(x)
    (__funcarg54 = FUNCCALL(SETUP_XfOrM119(_), type_name_string (i -> struct_type -> name ) ), FUNCCALL_EMPTY(scheme_wrong_type (i -> func_name , __funcarg54 , 0 , argc , args ) )) ; 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  else if (! ((i -> struct_type -> name_pos <= inst -> stype -> name_pos ) && (i -> struct_type == inst -> stype -> parent_types [i -> struct_type -> name_pos ] ) ) ) {
#   define XfOrM118_COUNT (0+XfOrM117_COUNT)
#   define SETUP_XfOrM118(x) SETUP_XfOrM117(x)
    FUNCCALL(SETUP_XfOrM118(_), wrong_struct_type (i -> func_name , i -> struct_type -> name , ((((Scheme_Structure * ) inst ) -> stype ) -> name ) , 0 , argc , args ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (argc == 2 )
    pos = FUNCCALL(SETUP_XfOrM117(_), parse_pos (((void * ) 0 ) , i , args , argc ) ); 
  else pos = i -> field ; 
  RET_VALUE_START (inst -> slots [pos ] ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * struct_setter (int argc , Scheme_Object * * args , Scheme_Object * prim ) {
  Scheme_Structure * inst ; 
  int pos ; 
  Scheme_Object * v ; 
  Struct_Proc_Info * i = (Struct_Proc_Info * ) ((Scheme_Primitive_Closure * ) prim ) -> val [0 ] ; 
  char * __funcarg55 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(inst, 1), PUSH(args, 2), PUSH(i, 3)));
# define XfOrM120_COUNT (4)
# define SETUP_XfOrM120(x) SETUP(XfOrM120_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  inst = NULLED_OUT ; 
  v = NULLED_OUT ; 
  if (! (((Scheme_Type ) (((((long ) (args [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (args [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (args [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) ) {
#   define XfOrM126_COUNT (0+XfOrM120_COUNT)
#   define SETUP_XfOrM126(x) SETUP_XfOrM120(x)
    (__funcarg55 = FUNCCALL(SETUP_XfOrM126(_), type_name_string (i -> struct_type -> name ) ), FUNCCALL_EMPTY(scheme_wrong_type (i -> func_name , __funcarg55 , 0 , argc , args ) )) ; 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  inst = (Scheme_Structure * ) args [0 ] ; 
  if (! ((i -> struct_type -> name_pos <= inst -> stype -> name_pos ) && (i -> struct_type == inst -> stype -> parent_types [i -> struct_type -> name_pos ] ) ) ) {
#   define XfOrM125_COUNT (0+XfOrM120_COUNT)
#   define SETUP_XfOrM125(x) SETUP_XfOrM120(x)
    FUNCCALL(SETUP_XfOrM125(_), wrong_struct_type (i -> func_name , i -> struct_type -> name , ((((Scheme_Structure * ) inst ) -> stype ) -> name ) , 0 , argc , args ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (argc == 3 ) {
#   define XfOrM124_COUNT (0+XfOrM120_COUNT)
#   define SETUP_XfOrM124(x) SETUP_XfOrM120(x)
    pos = FUNCCALL(SETUP_XfOrM124(_), parse_pos (((void * ) 0 ) , i , args , argc ) ); 
    v = args [2 ] ; 
  }
  else {
    pos = i -> field ; 
    v = args [1 ] ; 
  }
  if (i -> struct_type -> immutables ) {
    Scheme_Struct_Type * t = i -> struct_type ; 
    int p = pos ; 
#   define XfOrM121_COUNT (0+XfOrM120_COUNT)
#   define SETUP_XfOrM121(x) SETUP_XfOrM120(x)
    if (t -> name_pos )
      p -= t -> parent_types [t -> name_pos - 1 ] -> num_slots ; 
    if (t -> immutables [p ] ) {
#     define XfOrM122_COUNT (0+XfOrM121_COUNT)
#     define SETUP_XfOrM122(x) SETUP_XfOrM121(x)
      FUNCCALL(SETUP_XfOrM122(_), scheme_arg_mismatch (i -> func_name , "cannot modify value of immutable field in structure: " , args [0 ] ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  inst -> slots [pos ] = v ; 
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * struct_p (int argc , Scheme_Object * argv [] ) {
  Scheme_Config * __funcarg56 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM127_COUNT (1)
# define SETUP_XfOrM127(x) SETUP(XfOrM127_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) ) {
    Scheme_Object * insp ; 
    BLOCK_SETUP((PUSH(insp, 0+XfOrM127_COUNT)));
#   define XfOrM128_COUNT (1+XfOrM127_COUNT)
#   define SETUP_XfOrM128(x) SETUP(XfOrM128_COUNT)
    insp = NULLED_OUT ; 
    insp = (__funcarg56 = FUNCCALL(SETUP_XfOrM128(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg56 , MZCONFIG_INSPECTOR ) )) ; 
    if (FUNCCALL_EMPTY(scheme_inspector_sees_part (argv [0 ] , insp , - 1 ) ))
      RET_VALUE_START (scheme_true ) RET_VALUE_END ; 
    else RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (scheme_false ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * struct_type_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_struct_type_type ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * proc_struct_type_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_struct_type_type ) ) ) {
    if (((Scheme_Struct_Type * ) argv [0 ] ) -> proc_attr )
      return scheme_true ; 
    else return scheme_false ; 
  }
  scheme_wrong_type ("procedure-struct-type?" , "struct-type" , 0 , argc , argv ) ; 
  return ((void * ) 0 ) ; 
}
static Scheme_Object * struct_info (int argc , Scheme_Object * argv [] ) {
  Scheme_Structure * s ; 
  Scheme_Struct_Type * stype ; 
  int p ; 
  Scheme_Object * insp , * a [2 ] ; 
  Scheme_Config * __funcarg57 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 2, 0), PUSH(stype, 3), PUSH(s, 4), PUSH(insp, 5)));
# define XfOrM132_COUNT (6)
# define SETUP_XfOrM132(x) SETUP(XfOrM132_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  stype = NULLED_OUT ; 
  insp = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  if ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) ) {
#   define XfOrM133_COUNT (0+XfOrM132_COUNT)
#   define SETUP_XfOrM133(x) SETUP_XfOrM132(x)
    s = (Scheme_Structure * ) argv [0 ] ; 
    insp = (__funcarg57 = FUNCCALL(SETUP_XfOrM133(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg57 , MZCONFIG_INSPECTOR ) )) ; 
    stype = s -> stype ; 
    p = stype -> name_pos + 1 ; 
    while (p -- ) {
#     define XfOrM136_COUNT (0+XfOrM133_COUNT)
#     define SETUP_XfOrM136(x) SETUP_XfOrM133(x)
      stype = stype -> parent_types [p ] ; 
      if ((scheme_is_subinspector (stype -> inspector , insp ) ) ) {
#       define XfOrM137_COUNT (0+XfOrM136_COUNT)
#       define SETUP_XfOrM137(x) SETUP_XfOrM136(x)
        a [0 ] = (Scheme_Object * ) stype ; 
        a [1 ] = ((((stype ) == (s -> stype ) ) ) ? scheme_false : scheme_true ) ; 
        RET_VALUE_START (FUNCCALL(SETUP_XfOrM137(_), scheme_values (2 , a ) )) RET_VALUE_END ; 
      }
    }
  }
  a [0 ] = scheme_false ; 
  a [1 ] = scheme_true ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM132(_), scheme_values (2 , a ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * check_type_and_inspector (const char * who , int always , int argc , Scheme_Object * argv [] ) {
  Scheme_Object * insp ; 
  Scheme_Struct_Type * stype ; 
  Scheme_Config * __funcarg58 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(insp, 0), PUSH(argv, 1), PUSH(who, 2), PUSH(stype, 3)));
# define XfOrM138_COUNT (4)
# define SETUP_XfOrM138(x) SETUP(XfOrM138_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  insp = NULLED_OUT ; 
  stype = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_struct_type_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type (who , "struct-type" , 0 , argc , argv ) ); 
  stype = (Scheme_Struct_Type * ) argv [0 ] ; 
  insp = (__funcarg58 = FUNCCALL(SETUP_XfOrM138(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg58 , MZCONFIG_INSPECTOR ) )) ; 
  if (! always && ! (scheme_is_subinspector (stype -> inspector , insp ) ) ) {
#   define XfOrM139_COUNT (0+XfOrM138_COUNT)
#   define SETUP_XfOrM139(x) SETUP_XfOrM138(x)
    FUNCCALL(SETUP_XfOrM139(_), scheme_arg_mismatch (who , "current inspector cannot extract info for struct-type: " , argv [0 ] ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  RET_VALUE_START (insp ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void get_struct_type_info (int argc , Scheme_Object * argv [] , Scheme_Object * * a , int always ) {
  Scheme_Struct_Type * stype , * parent ; 
  Scheme_Object * insp , * ims ; 
  int p , cnt ; 
  PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(stype, 0), PUSH(ims, 1), PUSH(a, 2), PUSH(insp, 3), PUSH(parent, 4), PUSH(argv, 5)));
# define XfOrM140_COUNT (6)
# define SETUP_XfOrM140(x) SETUP(XfOrM140_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  stype = NULLED_OUT ; 
  parent = NULLED_OUT ; 
  insp = NULLED_OUT ; 
  ims = NULLED_OUT ; 
  insp = FUNCCALL(SETUP_XfOrM140(_), check_type_and_inspector ("struct-type-info" , always , argc , argv ) ); 
  stype = (Scheme_Struct_Type * ) argv [0 ] ; 
  if (! stype -> accessor ) {
    Scheme_Object * p ; 
    char * fn ; 
    BLOCK_SETUP((PUSH(fn, 0+XfOrM140_COUNT), PUSH(p, 1+XfOrM140_COUNT)));
#   define XfOrM148_COUNT (2+XfOrM140_COUNT)
#   define SETUP_XfOrM148(x) SETUP(XfOrM148_COUNT)
    p = NULLED_OUT ; 
    fn = NULLED_OUT ; 
    fn = (char * ) FUNCCALL(SETUP_XfOrM148(_), make_name ("" , (char * ) stype -> name , - 1 , "-ref" , ((void * ) 0 ) , 0 , "" , 0 ) ); 
    p = FUNCCALL(SETUP_XfOrM148(_), make_struct_proc (stype , fn , SCHEME_GEN_GETTER , 0 ) ); 
    stype -> accessor = p ; 
    fn = (char * ) FUNCCALL(SETUP_XfOrM148(_), make_name ("" , (char * ) stype -> name , - 1 , "-set!" , ((void * ) 0 ) , 0 , "" , 0 ) ); 
    p = FUNCCALL(SETUP_XfOrM148(_), make_struct_proc (stype , fn , SCHEME_GEN_SETTER , 0 ) ); 
    stype -> mutator = p ; 
  }
  if (stype -> name_pos )
    parent = stype -> parent_types [stype -> name_pos - 1 ] ; 
  else parent = ((void * ) 0 ) ; 
  a [0 ] = stype -> name ; 
  cnt = stype -> num_islots - (parent ? parent -> num_islots : 0 ) ; 
  a [1 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (cnt ) ) << 1 ) | 0x1 ) ) ; 
  a [2 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (stype -> num_slots - (parent ? parent -> num_slots : 0 ) - cnt ) ) << 1 ) | 0x1 ) ) ; 
  a [3 ] = stype -> accessor ; 
  a [4 ] = stype -> mutator ; 
  p = stype -> name_pos ; 
  while (-- p >= 0 ) {
#   define XfOrM146_COUNT (0+XfOrM140_COUNT)
#   define SETUP_XfOrM146(x) SETUP_XfOrM140(x)
    if ((scheme_is_subinspector (stype -> parent_types [p ] -> inspector , insp ) ) ) {
      break ; 
    }
  }
  ims = scheme_null ; 
  if (stype -> immutables ) {
    int i ; 
#   define XfOrM141_COUNT (0+XfOrM140_COUNT)
#   define SETUP_XfOrM141(x) SETUP_XfOrM140(x)
    for (i = stype -> num_islots ; i -- ; ) {
#     define XfOrM143_COUNT (0+XfOrM141_COUNT)
#     define SETUP_XfOrM143(x) SETUP_XfOrM141(x)
      if (stype -> immutables [i ] )
        ims = FUNCCALL(SETUP_XfOrM143(_), scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (i ) ) << 1 ) | 0x1 ) ) , ims ) ); 
    }
  }
  a [5 ] = ims ; 
  a [6 ] = ((p >= 0 ) ? (Scheme_Object * ) stype -> parent_types [p ] : scheme_false ) ; 
  a [7 ] = ((p == stype -> name_pos - 1 ) ? scheme_false : scheme_true ) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * struct_type_info (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * a [8 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 8, 0)));
# define XfOrM149_COUNT (3)
# define SETUP_XfOrM149(x) SETUP(XfOrM149_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  NULL_OUT_ARRAY (a ) ; 
  FUNCCALL(SETUP_XfOrM149(_), get_struct_type_info (argc , argv , a , 0 ) ); 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM149(_), scheme_values (8 , a ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * struct_type_pred (int argc , Scheme_Object * argv [] ) {
  Scheme_Struct_Type * stype ; 
  char * __funcarg61 = NULLED_OUT ; 
  Scheme_Object * __funcarg60 = NULLED_OUT ; 
  char * __funcarg59 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(stype, 0), PUSH(argv, 1)));
# define XfOrM150_COUNT (2)
# define SETUP_XfOrM150(x) SETUP(XfOrM150_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  stype = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM150(_), check_type_and_inspector ("struct-type-make-predicate" , 0 , argc , argv ) ); 
  stype = (Scheme_Struct_Type * ) argv [0 ] ; 
  RET_VALUE_START ((__funcarg59 = (__funcarg60 = (__funcarg61 = FUNCCALL(SETUP_XfOrM150(_), scheme_symbol_val (stype -> name ) ), FUNCCALL_AGAIN(make_name ("" , __funcarg61 , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (stype -> name ) ) ) -> len ) , "?" , ((void * ) 0 ) , 0 , "" , 1 ) )) , FUNCCALL_AGAIN(scheme_symbol_val (__funcarg60 ) )) , FUNCCALL_EMPTY(make_struct_proc (stype , __funcarg59 , SCHEME_PRED , stype -> num_slots ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * struct_type_constr (int argc , Scheme_Object * argv [] ) {
  Scheme_Struct_Type * stype ; 
  char * __funcarg64 = NULLED_OUT ; 
  Scheme_Object * __funcarg63 = NULLED_OUT ; 
  char * __funcarg62 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(stype, 0), PUSH(argv, 1)));
# define XfOrM151_COUNT (2)
# define SETUP_XfOrM151(x) SETUP(XfOrM151_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  stype = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM151(_), check_type_and_inspector ("struct-type-make-constructor" , 0 , argc , argv ) ); 
  stype = (Scheme_Struct_Type * ) argv [0 ] ; 
  RET_VALUE_START ((__funcarg62 = (__funcarg63 = (__funcarg64 = FUNCCALL(SETUP_XfOrM151(_), scheme_symbol_val (stype -> name ) ), FUNCCALL_AGAIN(make_name ("make-" , __funcarg64 , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (stype -> name ) ) ) -> len ) , "" , ((void * ) 0 ) , 0 , "" , 1 ) )) , FUNCCALL_AGAIN(scheme_symbol_val (__funcarg63 ) )) , FUNCCALL_EMPTY(make_struct_proc (stype , __funcarg62 , SCHEME_CONSTR , stype -> num_slots ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_struct_to_vector (Scheme_Object * _s , Scheme_Object * unknown_val , Scheme_Object * insp ) {
  Scheme_Structure * s ; 
  Scheme_Struct_Type * stype ; 
  Scheme_Object * v , * name ; 
  GC_CAN_IGNORE Scheme_Object * * array ; 
  int i , m , p , n , last_is_unknown ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(unknown_val, 1), PUSH(s, 2), PUSH(insp, 3), PUSH(stype, 4), PUSH(name, 5)));
# define XfOrM152_COUNT (6)
# define SETUP_XfOrM152(x) SETUP(XfOrM152_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  stype = NULLED_OUT ; 
  v = NULLED_OUT ; 
  name = NULLED_OUT ; 
  if (! unknown_val )
    unknown_val = ellipses_symbol ; 
  s = (Scheme_Structure * ) _s ; 
  stype = s -> stype ; 
  p = stype -> name_pos + 1 ; 
  m = 0 ; 
  last_is_unknown = 0 ; 
  while (p -- ) {
#   define XfOrM166_COUNT (0+XfOrM152_COUNT)
#   define SETUP_XfOrM166(x) SETUP_XfOrM152(x)
    stype = stype -> parent_types [p ] ; 
    if (! (scheme_is_subinspector (stype -> inspector , insp ) ) ) {
      if (! last_is_unknown )
        m ++ ; 
      last_is_unknown = 1 ; 
    }
    else {
      last_is_unknown = 0 ; 
      if (p )
        m += stype -> num_slots - stype -> parent_types [p - 1 ] -> num_slots ; 
      else m += stype -> num_slots ; 
    }
  }
  stype = s -> stype ; 
  p = stype -> name_pos + 1 ; 
  i = stype -> num_slots ; 
  last_is_unknown = 0 ; 
  name = FUNCCALL(SETUP_XfOrM152(_), make_name ("struct:" , (char * ) ((((Scheme_Structure * ) s ) -> stype ) -> name ) , - 1 , "" , ((void * ) 0 ) , 0 , "" , 1 ) ); 
  v = FUNCCALL_AGAIN(scheme_make_vector (m + 1 , ((void * ) 0 ) ) ); 
  array = (((Scheme_Vector * ) (v ) ) -> els ) ; 
  array [0 ] = name ; 
  while (p -- ) {
#   define XfOrM158_COUNT (0+XfOrM152_COUNT)
#   define SETUP_XfOrM158(x) SETUP_XfOrM152(x)
    stype = stype -> parent_types [p ] ; 
    if (p )
      n = stype -> num_slots - stype -> parent_types [p - 1 ] -> num_slots ; 
    else n = stype -> num_slots ; 
    if (! (scheme_is_subinspector (stype -> inspector , insp ) ) ) {
      if (! last_is_unknown )
        array [1 + (-- m ) ] = unknown_val ; 
      i -= n ; 
      last_is_unknown = 1 ; 
    }
    else {
      while (n -- ) {
        array [1 + (-- m ) ] = s -> slots [-- i ] ; 
      }
      last_is_unknown = 0 ; 
    }
  }
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * struct_to_vector (int argc , Scheme_Object * argv [] ) {
  Scheme_Config * __funcarg66 = NULLED_OUT ; 
  Scheme_Object * __funcarg65 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM169_COUNT (1)
# define SETUP_XfOrM169(x) SETUP(XfOrM169_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_structure_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_proc_struct_type ) ) ) ) {
    char * tn , * s ; 
    int l ; 
    Scheme_Object * v ; 
    BLOCK_SETUP((PUSH(v, 0+XfOrM169_COUNT), PUSH(s, 1+XfOrM169_COUNT), PUSH(tn, 2+XfOrM169_COUNT)));
#   define XfOrM170_COUNT (3+XfOrM169_COUNT)
#   define SETUP_XfOrM170(x) SETUP(XfOrM170_COUNT)
    tn = NULLED_OUT ; 
    s = NULLED_OUT ; 
    v = NULLED_OUT ; 
    tn = FUNCCALL(SETUP_XfOrM170(_), scheme_get_type_name (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) ); 
    l = strlen (tn ) - 2 ; 
    s = FUNCCALL(SETUP_XfOrM170(_), GC_malloc_atomic (l + 8 ) ); 
    (strcpy (s , "struct:" ) ) ; 
    (memcpy (s + 7 , tn + 1 , l ) ) ; 
    s [7 + l ] = 0 ; 
    v = FUNCCALL(SETUP_XfOrM170(_), scheme_intern_symbol (s ) ); 
    v = FUNCCALL_AGAIN(scheme_make_vector (2 , v ) ); 
    (((Scheme_Vector * ) (v ) ) -> els ) [1 ] = (argc > 1 ) ? argv [1 ] : ellipses_symbol ; 
    RET_VALUE_START (v ) RET_VALUE_END ; 
  }
  RET_VALUE_START ((__funcarg65 = (__funcarg66 = FUNCCALL(SETUP_XfOrM169(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg66 , MZCONFIG_INSPECTOR ) )) , FUNCCALL_EMPTY(scheme_struct_to_vector (argv [0 ] , (argc > 1 ) ? argv [1 ] : ((void * ) 0 ) , __funcarg65 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_inspector_sees_part (Scheme_Object * s , Scheme_Object * insp , int pos ) {
  /* No conversion */
  Scheme_Struct_Type * stype = ((Scheme_Structure * ) s ) -> stype ; 
  int p ; 
  p = stype -> name_pos ; 
  if (pos == - 1 ) {
    Scheme_Object * prev = ((void * ) 0 ) ; 
    while (p > - 1 ) {
      if (! ((stype -> parent_types [p ] -> inspector ) == (prev ) ) ) {
        prev = stype -> parent_types [p ] -> inspector ; 
        if (scheme_is_subinspector (prev , insp ) )
          return 1 ; 
      }
      p -- ; 
    }
    return 0 ; 
  }
  else if (pos == - 2 ) {
    Scheme_Object * prev = ((void * ) 0 ) ; 
    while (p > - 1 ) {
      if (! ((stype -> parent_types [p ] -> inspector ) == (prev ) ) ) {
        prev = stype -> parent_types [p ] -> inspector ; 
        if (! scheme_is_subinspector (prev , insp ) )
          return 0 ; 
      }
      p -- ; 
    }
    return 1 ; 
  }
  else {
    while (p && (stype -> parent_types [p - 1 ] -> num_slots > pos ) ) {
      p -- ; 
    }
    return scheme_is_subinspector (stype -> parent_types [p ] -> inspector , insp ) ; 
  }
}
static Scheme_Object * struct_setter_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_prim_type ) ) && ((((Scheme_Primitive_Proc * ) argv [0 ] ) -> pp . flags & (32 | (64 | 128 ) ) ) == (32 | (64 | 128 ) ) ) ) || (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_prim_type ) ) && ((((Scheme_Primitive_Proc * ) argv [0 ] ) -> pp . flags & (32 | (64 | 128 ) ) ) == (32 | 128 ) ) ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * struct_getter_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_prim_type ) ) && ((((Scheme_Primitive_Proc * ) argv [0 ] ) -> pp . flags & (4 ) ) == (4 ) ) ) || (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_prim_type ) ) && ((((Scheme_Primitive_Proc * ) argv [0 ] ) -> pp . flags & (32 | (64 | 128 ) ) ) == (32 | 0 ) ) ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * struct_pred_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_prim_type ) ) && ((((Scheme_Primitive_Proc * ) argv [0 ] ) -> pp . flags & (8 ) ) == (8 ) ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * struct_constr_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return ((((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_prim_type ) ) && ((((Scheme_Primitive_Proc * ) argv [0 ] ) -> pp . flags & (32 | (64 | 128 ) ) ) == (32 | 64 ) ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * make_struct_field_xxor (const char * who , int getter , int argc , Scheme_Object * argv [] ) {
  Struct_Proc_Info * i ; 
  int pos ; 
  char * name ; 
  const char * fieldstr ; 
  char digitbuf [20 ] ; 
  int fieldstrlen ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(i, 0), PUSH(fieldstr, 1), PUSH(name, 2), PUSH(argv, 3), PUSH(who, 4)));
# define XfOrM189_COUNT (5)
# define SETUP_XfOrM189(x) SETUP(XfOrM189_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  i = NULLED_OUT ; 
  name = NULLED_OUT ; 
  fieldstr = NULLED_OUT ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_prim_type ) ) && ((((Scheme_Primitive_Proc * ) argv [0 ] ) -> pp . flags & (32 | (64 | 128 ) ) ) == (32 | (getter ? 0 : 128 ) ) ) ) ) {
#   define XfOrM195_COUNT (0+XfOrM189_COUNT)
#   define SETUP_XfOrM195(x) SETUP_XfOrM189(x)
    FUNCCALL_EMPTY(scheme_wrong_type (who , (getter ? "accessor procedure that requires a field index" : "mutator procedure that requires a field index" ) , 0 , argc , argv ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  i = (Struct_Proc_Info * ) ((Scheme_Primitive_Closure * ) argv [0 ] ) -> val [0 ] ; 
  pos = FUNCCALL(SETUP_XfOrM189(_), parse_pos (who , i , argv , argc ) ); 
  if (argc > 2 ) {
#   define XfOrM193_COUNT (0+XfOrM189_COUNT)
#   define SETUP_XfOrM193(x) SETUP_XfOrM189(x)
    if (! ((Scheme_Type ) (((((long ) (argv [2 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [2 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
#     define XfOrM194_COUNT (0+XfOrM193_COUNT)
#     define SETUP_XfOrM194(x) SETUP_XfOrM193(x)
      FUNCCALL_EMPTY(scheme_wrong_type (who , "symbol" , 2 , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    fieldstr = FUNCCALL(SETUP_XfOrM193(_), scheme_symbol_val (argv [2 ] ) ); 
    fieldstrlen = (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (argv [2 ] ) ) ) -> len ) ; 
  }
  else {
#   define XfOrM192_COUNT (0+XfOrM189_COUNT)
#   define SETUP_XfOrM192(x) SETUP_XfOrM189(x)
    (sprintf (digitbuf , "field%d" , (int ) (((long ) (argv [1 ] ) ) >> 1 ) ) ) ; 
    fieldstr = digitbuf ; 
    fieldstrlen = strlen (fieldstr ) ; 
  }
  if (getter ) {
#   define XfOrM191_COUNT (0+XfOrM189_COUNT)
#   define SETUP_XfOrM191(x) SETUP_XfOrM189(x)
    name = (char * ) FUNCCALL(SETUP_XfOrM191(_), make_name ("" , (char * ) i -> struct_type -> name , - 1 , "-" , fieldstr , fieldstrlen , "" , 0 ) ); 
  }
  else {
#   define XfOrM190_COUNT (0+XfOrM189_COUNT)
#   define SETUP_XfOrM190(x) SETUP_XfOrM189(x)
    name = (char * ) FUNCCALL(SETUP_XfOrM190(_), make_name ("set-" , (char * ) i -> struct_type -> name , - 1 , "-" , fieldstr , fieldstrlen , "!" , 0 ) ); 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(make_struct_proc (i -> struct_type , name , (getter ? SCHEME_GETTER : SCHEME_SETTER ) , pos ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_struct_field_accessor (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return make_struct_field_xxor ("make-struct-field-accessor" , 1 , argc , argv ) ; 
}
static Scheme_Object * make_struct_field_mutator (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return make_struct_field_xxor ("make-struct-field-mutator" , 0 , argc , argv ) ; 
}
static Scheme_Object * wrap_evt (const char * who , int wrap , int argc , Scheme_Object * argv [] ) {
  Wrapped_Evt * ww ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(ww, 0), PUSH(argv, 1), PUSH(who, 2)));
# define XfOrM198_COUNT (3)
# define SETUP_XfOrM198(x) SETUP(XfOrM198_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ww = NULLED_OUT ; 
  if (! FUNCCALL(SETUP_XfOrM198(_), scheme_is_evt (argv [0 ] ) )|| (wrap && FUNCCALL(SETUP_XfOrM198(_), handle_evt_p (0 , argv ) )) )
    FUNCCALL_EMPTY(scheme_wrong_type (who , wrap ? "non-handle evt" : "evt" , 0 , argc , argv ) ); 
  FUNCCALL(SETUP_XfOrM198(_), scheme_check_proc_arity (who , 1 , 1 , argc , argv ) ); 
  ww = ((Wrapped_Evt * ) FUNCCALL(SETUP_XfOrM198(_), GC_malloc_one_small_tagged ((((sizeof (Wrapped_Evt ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  ww -> so . type = (wrap ? scheme_wrap_evt_type : scheme_handle_evt_type ) ; 
  ww -> evt = argv [0 ] ; 
  ww -> wrapper = argv [1 ] ; 
  RET_VALUE_START ((Scheme_Object * ) ww ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_wrap_evt (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return wrap_evt ("wrap-evt" , 1 , argc , argv ) ; 
}
Scheme_Object * handle_evt (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return wrap_evt ("handle-evt" , 0 , argc , argv ) ; 
}
Scheme_Object * handle_evt_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_handle_evt_type ) ) )
    return scheme_true ; 
  if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_evt_set_type ) ) ) {
    Evt_Set * es = (Evt_Set * ) argv [0 ] ; 
    int i ; 
    for (i = es -> argc ; i -- ; ) {
      if (((Scheme_Type ) (((((long ) (es -> argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (es -> argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_handle_evt_type ) ) ) {
        return scheme_true ; 
      }
    }
  }
  if (argc )
    return scheme_false ; 
  else return ((void * ) 0 ) ; 
}
static Scheme_Object * nack_evt (int argc , Scheme_Object * argv [] ) {
  Nack_Guard_Evt * nw ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(nw, 0), PUSH(argv, 1)));
# define XfOrM207_COUNT (2)
# define SETUP_XfOrM207(x) SETUP(XfOrM207_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  nw = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM207(_), scheme_check_proc_arity ("nack-guard-evt" , 1 , 0 , argc , argv ) ); 
  nw = ((Nack_Guard_Evt * ) FUNCCALL(SETUP_XfOrM207(_), GC_malloc_one_small_tagged ((((sizeof (Nack_Guard_Evt ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  nw -> so . type = scheme_nack_guard_evt_type ; 
  nw -> maker = argv [0 ] ; 
  RET_VALUE_START ((Scheme_Object * ) nw ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_poll_evt (int argc , Scheme_Object * argv [] ) {
  Nack_Guard_Evt * nw ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(nw, 0), PUSH(argv, 1)));
# define XfOrM208_COUNT (2)
# define SETUP_XfOrM208(x) SETUP(XfOrM208_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  nw = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM208(_), scheme_check_proc_arity ("poll-guard-evt" , 1 , 0 , argc , argv ) ); 
  nw = ((Nack_Guard_Evt * ) FUNCCALL(SETUP_XfOrM208(_), GC_malloc_one_small_tagged ((((sizeof (Nack_Guard_Evt ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  nw -> so . type = scheme_poll_evt_type ; 
  nw -> maker = argv [0 ] ; 
  RET_VALUE_START ((Scheme_Object * ) nw ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int wrapped_evt_is_ready (Scheme_Object * o , Scheme_Schedule_Info * sinfo ) {
  Wrapped_Evt * ww = (Wrapped_Evt * ) o ; 
  Scheme_Object * wrapper ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(sinfo, 0), PUSH(ww, 1), PUSH(wrapper, 2)));
# define XfOrM209_COUNT (3)
# define SETUP_XfOrM209(x) SETUP(XfOrM209_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  wrapper = NULLED_OUT ; 
  if (ww -> so . type == scheme_wrap_evt_type ) {
    wrapper = ww -> wrapper ; 
  }
  else {
#   define XfOrM210_COUNT (0+XfOrM209_COUNT)
#   define SETUP_XfOrM210(x) SETUP_XfOrM209(x)
    wrapper = FUNCCALL(SETUP_XfOrM210(_), scheme_box (ww -> wrapper ) ); 
  }
  FUNCCALL_EMPTY(scheme_set_sync_target (sinfo , ww -> evt , wrapper , ((void * ) 0 ) , 0 , 1 ) ); 
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int nack_guard_evt_is_ready (Scheme_Object * o , Scheme_Schedule_Info * sinfo ) {
  Nack_Guard_Evt * nw = (Nack_Guard_Evt * ) o ; 
  Scheme_Object * sema , * a [1 ] , * result ; 
  Scheme_Object * nack ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(9);
  BLOCK_SETUP_TOP((PUSH(nack, 0), PUSHARRAY(a, 1, 1), PUSH(result, 4), PUSH(o, 5), PUSH(nw, 6), PUSH(sinfo, 7), PUSH(sema, 8)));
# define XfOrM212_COUNT (9)
# define SETUP_XfOrM212(x) SETUP(XfOrM212_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sema = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  result = NULLED_OUT ; 
  nack = NULLED_OUT ; 
  if (sinfo -> false_positive_ok ) {
    sinfo -> potentially_false_positive = 1 ; 
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  }
  sema = FUNCCALL(SETUP_XfOrM212(_), scheme_make_sema (0 ) ); 
  FUNCCALL(SETUP_XfOrM212(_), scheme_set_sync_target (sinfo , o , ((void * ) 0 ) , sema , 0 , 0 ) ); 
  nack = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM212(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  nack -> type = scheme_nack_evt_type ; 
  (((Scheme_Simple_Object * ) (nack ) ) -> u . two_ptr_val . ptr1 ) = sema ; 
  result = FUNCCALL(SETUP_XfOrM212(_), scheme_get_thread_dead (scheme_current_thread ) ); 
  (((Scheme_Simple_Object * ) (nack ) ) -> u . two_ptr_val . ptr2 ) = result ; 
  a [0 ] = nack ; 
  result = FUNCCALL(SETUP_XfOrM212(_), scheme_apply (nw -> maker , 1 , a ) ); 
  if (FUNCCALL(SETUP_XfOrM212(_), scheme_is_evt (result ) )) {
#   define XfOrM213_COUNT (0+XfOrM212_COUNT)
#   define SETUP_XfOrM213(x) SETUP_XfOrM212(x)
    FUNCCALL(SETUP_XfOrM213(_), scheme_set_sync_target (sinfo , result , ((void * ) 0 ) , ((void * ) 0 ) , 0 , 1 ) ); 
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (1 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int nack_evt_is_ready (Scheme_Object * o , Scheme_Schedule_Info * sinfo ) {
  Scheme_Object * a [2 ] , * wset ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(sinfo, 0), PUSHARRAY(a, 2, 1), PUSH(wset, 4), PUSH(o, 5)));
# define XfOrM215_COUNT (6)
# define SETUP_XfOrM215(x) SETUP(XfOrM215_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a[1] = NULLED_OUT ; 
  wset = NULLED_OUT ; 
  wset = (((Scheme_Simple_Object * ) (o ) ) -> u . two_ptr_val . ptr1 ) ; 
  if (((Scheme_Type ) (((((long ) (wset ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (wset ) ) -> type ) ) == (Scheme_Type ) (scheme_sema_type ) ) ) {
#   define XfOrM216_COUNT (0+XfOrM215_COUNT)
#   define SETUP_XfOrM216(x) SETUP_XfOrM215(x)
    a [0 ] = wset ; 
    a [1 ] = (((Scheme_Simple_Object * ) (o ) ) -> u . two_ptr_val . ptr2 ) ; 
    wset = FUNCCALL(SETUP_XfOrM216(_), scheme_make_evt_set (2 , a ) ); 
    (((Scheme_Simple_Object * ) (o ) ) -> u . two_ptr_val . ptr1 ) = wset ; 
  }
  FUNCCALL(SETUP_XfOrM215(_), scheme_set_sync_target (sinfo , wset , scheme_void , ((void * ) 0 ) , 0 , 1 ) ); 
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int poll_evt_is_ready (Scheme_Object * o , Scheme_Schedule_Info * sinfo ) {
  Nack_Guard_Evt * nw = (Nack_Guard_Evt * ) o ; 
  Scheme_Object * a [1 ] , * result ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(sinfo, 0), PUSHARRAY(a, 1, 1), PUSH(result, 4)));
# define XfOrM217_COUNT (5)
# define SETUP_XfOrM217(x) SETUP(XfOrM217_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  result = NULLED_OUT ; 
  if (sinfo -> false_positive_ok ) {
    sinfo -> potentially_false_positive = 1 ; 
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  }
  a [0 ] = (sinfo -> is_poll ? scheme_true : scheme_false ) ; 
  result = FUNCCALL(SETUP_XfOrM217(_), scheme_apply (nw -> maker , 1 , a ) ); 
  if (FUNCCALL(SETUP_XfOrM217(_), scheme_is_evt (result ) )) {
#   define XfOrM218_COUNT (0+XfOrM217_COUNT)
#   define SETUP_XfOrM218(x) SETUP_XfOrM217(x)
    FUNCCALL(SETUP_XfOrM218(_), scheme_set_sync_target (sinfo , result , ((void * ) 0 ) , ((void * ) 0 ) , 0 , 1 ) ); 
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (1 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * * scheme_make_struct_values (Scheme_Object * type , Scheme_Object * * names , int count , int flags ) {
  Scheme_Struct_Type * struct_type ; 
  Scheme_Object * * values ; 
  int slot_num , pos ; 
  char * __funcarg74 = NULLED_OUT ; 
  char * __funcarg73 = NULLED_OUT ; 
  char * __funcarg72 = NULLED_OUT ; 
  char * __funcarg71 = NULLED_OUT ; 
  char * __funcarg68 = NULLED_OUT ; 
  char * __funcarg67 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(struct_type, 0), PUSH(names, 1), PUSH(values, 2)));
# define XfOrM220_COUNT (3)
# define SETUP_XfOrM220(x) SETUP(XfOrM220_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  struct_type = NULLED_OUT ; 
  values = NULLED_OUT ; 
  struct_type = (Scheme_Struct_Type * ) type ; 
  if (flags & 0x80 )
    -- count ; 
  values = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM220(_), GC_malloc (sizeof (Scheme_Object * ) * (count ) ) )) ; 
  pos = 0 ; 
  if (! (flags & 0x01 ) )
    values [pos ++ ] = (Scheme_Object * ) struct_type ; 
  if (! (flags & 0x02 ) ) {
    Scheme_Object * vi ; 
    BLOCK_SETUP((PUSH(vi, 0+XfOrM220_COUNT)));
#   define XfOrM230_COUNT (1+XfOrM220_COUNT)
#   define SETUP_XfOrM230(x) SETUP(XfOrM230_COUNT)
    vi = NULLED_OUT ; 
    vi = (__funcarg74 = FUNCCALL(SETUP_XfOrM230(_), scheme_symbol_val (names [pos ] ) ), FUNCCALL_AGAIN(make_struct_proc (struct_type , __funcarg74 , SCHEME_CONSTR , struct_type -> num_slots ) )) ; 
    values [pos ] = vi ; 
    pos ++ ; 
  }
  if (! (flags & 0x04 ) ) {
    Scheme_Object * vi ; 
    BLOCK_SETUP((PUSH(vi, 0+XfOrM220_COUNT)));
#   define XfOrM229_COUNT (1+XfOrM220_COUNT)
#   define SETUP_XfOrM229(x) SETUP(XfOrM229_COUNT)
    vi = NULLED_OUT ; 
    vi = (__funcarg73 = FUNCCALL(SETUP_XfOrM229(_), scheme_symbol_val (names [pos ] ) ), FUNCCALL_AGAIN(make_struct_proc (struct_type , __funcarg73 , SCHEME_PRED , 0 ) )) ; 
    values [pos ] = vi ; 
    pos ++ ; 
  }
  if (flags & 0x20 )
    -- count ; 
  if (flags & 0x40 )
    -- count ; 
  slot_num = (struct_type -> name_pos ? struct_type -> parent_types [struct_type -> name_pos - 1 ] -> num_slots : 0 ) ; 
  while (pos < count ) {
#   define XfOrM226_COUNT (0+XfOrM220_COUNT)
#   define SETUP_XfOrM226(x) SETUP_XfOrM220(x)
    if (! (flags & 0x08 ) ) {
      Scheme_Object * vi ; 
      BLOCK_SETUP((PUSH(vi, 0+XfOrM226_COUNT)));
#     define XfOrM228_COUNT (1+XfOrM226_COUNT)
#     define SETUP_XfOrM228(x) SETUP(XfOrM228_COUNT)
      vi = NULLED_OUT ; 
      vi = (__funcarg72 = FUNCCALL(SETUP_XfOrM228(_), scheme_symbol_val (names [pos ] ) ), FUNCCALL_AGAIN(make_struct_proc (struct_type , __funcarg72 , SCHEME_GETTER , slot_num ) )) ; 
      values [pos ] = vi ; 
      pos ++ ; 
    }
    if (! (flags & 0x10 ) ) {
      Scheme_Object * vi ; 
      BLOCK_SETUP((PUSH(vi, 0+XfOrM226_COUNT)));
#     define XfOrM227_COUNT (1+XfOrM226_COUNT)
#     define SETUP_XfOrM227(x) SETUP(XfOrM227_COUNT)
      vi = NULLED_OUT ; 
      vi = (__funcarg71 = FUNCCALL(SETUP_XfOrM227(_), scheme_symbol_val (names [pos ] ) ), FUNCCALL_AGAIN(make_struct_proc (struct_type , __funcarg71 , SCHEME_SETTER , slot_num ) )) ; 
      values [pos ] = vi ; 
      pos ++ ; 
    }
    slot_num ++ ; 
  }
  if (flags & 0x20 ) {
    Scheme_Object * vi ; 
    BLOCK_SETUP((PUSH(vi, 0+XfOrM220_COUNT)));
#   define XfOrM222_COUNT (1+XfOrM220_COUNT)
#   define SETUP_XfOrM222(x) SETUP(XfOrM222_COUNT)
    vi = NULLED_OUT ; 
    vi = (__funcarg68 = FUNCCALL(SETUP_XfOrM222(_), scheme_symbol_val (names [pos ] ) ), FUNCCALL_AGAIN(make_struct_proc (struct_type , __funcarg68 , SCHEME_GEN_GETTER , slot_num ) )) ; 
    values [pos ] = vi ; 
    pos ++ ; 
  }
  if (flags & 0x40 ) {
    Scheme_Object * vi ; 
    BLOCK_SETUP((PUSH(vi, 0+XfOrM220_COUNT)));
#   define XfOrM221_COUNT (1+XfOrM220_COUNT)
#   define SETUP_XfOrM221(x) SETUP(XfOrM221_COUNT)
    vi = NULLED_OUT ; 
    vi = (__funcarg67 = FUNCCALL(SETUP_XfOrM221(_), scheme_symbol_val (names [pos ] ) ), FUNCCALL_AGAIN(make_struct_proc (struct_type , __funcarg67 , SCHEME_GEN_SETTER , slot_num ) )) ; 
    values [pos ] = vi ; 
    pos ++ ; 
  }
  RET_VALUE_START (values ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * * _make_struct_names (const char * base , int blen , int fcount , Scheme_Object * field_symbols , const char * * field_strings , int flags , int * count_out ) {
  Scheme_Object * * names ; 
  const char * field_name ; 
  int count , fnlen ; 
  int slot_num , pos ; 
  DECL_RET_SAVE (Scheme_Object * * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(base, 0), PUSH(field_name, 1), PUSH(names, 2), PUSH(field_symbols, 3), PUSH(field_strings, 4)));
# define XfOrM231_COUNT (5)
# define SETUP_XfOrM231(x) SETUP(XfOrM231_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  names = NULLED_OUT ; 
  field_name = NULLED_OUT ; 
  count = 0 ; 
  if (! (flags & 0x01 ) )
    count ++ ; 
  if (! (flags & 0x02 ) )
    count ++ ; 
  if (! (flags & 0x04 ) )
    count ++ ; 
  if (! (flags & 0x08 ) )
    count += fcount ; 
  if (! (flags & 0x10 ) )
    count += fcount ; 
  if (flags & 0x20 )
    count ++ ; 
  if (flags & 0x40 )
    count ++ ; 
  if (flags & 0x80 )
    count ++ ; 
  if (count_out ) {
    * count_out = count ; 
    count_out = ((void * ) 0 ) ; 
  }
  names = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM231(_), GC_malloc (sizeof (Scheme_Object * ) * (count ) ) )) ; 
  pos = 0 ; 
  if (! (flags & 0x01 ) ) {
    Scheme_Object * nm ; 
    BLOCK_SETUP((PUSH(nm, 0+XfOrM231_COUNT)));
#   define XfOrM248_COUNT (1+XfOrM231_COUNT)
#   define SETUP_XfOrM248(x) SETUP(XfOrM248_COUNT)
    nm = NULLED_OUT ; 
    nm = FUNCCALL(SETUP_XfOrM248(_), make_name ("struct:" , base , blen , "" , ((void * ) 0 ) , 0 , "" , 1 ) ); 
    names [pos ++ ] = nm ; 
  }
  if (! (flags & 0x02 ) ) {
    Scheme_Object * nm ; 
    BLOCK_SETUP((PUSH(nm, 0+XfOrM231_COUNT)));
#   define XfOrM247_COUNT (1+XfOrM231_COUNT)
#   define SETUP_XfOrM247(x) SETUP(XfOrM247_COUNT)
    nm = NULLED_OUT ; 
    nm = FUNCCALL(SETUP_XfOrM247(_), make_name ("make-" , base , blen , "" , ((void * ) 0 ) , 0 , "" , 1 ) ); 
    names [pos ++ ] = nm ; 
  }
  if (! (flags & 0x04 ) ) {
    Scheme_Object * nm ; 
    BLOCK_SETUP((PUSH(nm, 0+XfOrM231_COUNT)));
#   define XfOrM246_COUNT (1+XfOrM231_COUNT)
#   define SETUP_XfOrM246(x) SETUP(XfOrM246_COUNT)
    nm = NULLED_OUT ; 
    nm = FUNCCALL(SETUP_XfOrM246(_), make_name ("" , base , blen , "?" , ((void * ) 0 ) , 0 , "" , 1 ) ); 
    names [pos ++ ] = nm ; 
  }
  if (fcount ) {
#   define XfOrM235_COUNT (0+XfOrM231_COUNT)
#   define SETUP_XfOrM235(x) SETUP_XfOrM231(x)
    for (slot_num = 0 ; slot_num < fcount ; slot_num ++ ) {
#     define XfOrM241_COUNT (0+XfOrM235_COUNT)
#     define SETUP_XfOrM241(x) SETUP_XfOrM235(x)
      if (field_symbols ) {
        Scheme_Object * fn = (((Scheme_Simple_Object * ) (field_symbols ) ) -> u . pair_val . car ) ; 
        BLOCK_SETUP((PUSH(fn, 0+XfOrM241_COUNT)));
#       define XfOrM245_COUNT (1+XfOrM241_COUNT)
#       define SETUP_XfOrM245(x) SETUP(XfOrM245_COUNT)
        field_symbols = (((Scheme_Simple_Object * ) (field_symbols ) ) -> u . pair_val . cdr ) ; 
        field_name = FUNCCALL(SETUP_XfOrM245(_), scheme_symbol_val (fn ) ); 
        fnlen = (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (fn ) ) ) -> len ) ; 
      }
      else {
        field_name = field_strings [slot_num ] ; 
        fnlen = strlen (field_name ) ; 
      }
      if (! (flags & 0x08 ) ) {
        Scheme_Object * nm ; 
        BLOCK_SETUP((PUSH(nm, 0+XfOrM241_COUNT)));
#       define XfOrM243_COUNT (1+XfOrM241_COUNT)
#       define SETUP_XfOrM243(x) SETUP(XfOrM243_COUNT)
        nm = NULLED_OUT ; 
        nm = FUNCCALL(SETUP_XfOrM243(_), make_name ("" , base , blen , "-" , field_name , fnlen , "" , 1 ) ); 
        names [pos ++ ] = nm ; 
      }
      if (! (flags & 0x10 ) ) {
        Scheme_Object * nm ; 
        BLOCK_SETUP((PUSH(nm, 0+XfOrM241_COUNT)));
#       define XfOrM242_COUNT (1+XfOrM241_COUNT)
#       define SETUP_XfOrM242(x) SETUP(XfOrM242_COUNT)
        nm = NULLED_OUT ; 
        nm = FUNCCALL(SETUP_XfOrM242(_), make_name ("set-" , base , blen , "-" , field_name , fnlen , "!" , 1 ) ); 
        names [pos ++ ] = nm ; 
      }
    }
  }
  if (flags & 0x20 ) {
    Scheme_Object * nm ; 
    BLOCK_SETUP((PUSH(nm, 0+XfOrM231_COUNT)));
#   define XfOrM234_COUNT (1+XfOrM231_COUNT)
#   define SETUP_XfOrM234(x) SETUP(XfOrM234_COUNT)
    nm = NULLED_OUT ; 
    nm = FUNCCALL(SETUP_XfOrM234(_), make_name ("" , base , blen , "-ref" , ((void * ) 0 ) , 0 , "" , 1 ) ); 
    names [pos ++ ] = nm ; 
  }
  if (flags & 0x40 ) {
    Scheme_Object * nm ; 
    BLOCK_SETUP((PUSH(nm, 0+XfOrM231_COUNT)));
#   define XfOrM233_COUNT (1+XfOrM231_COUNT)
#   define SETUP_XfOrM233(x) SETUP(XfOrM233_COUNT)
    nm = NULLED_OUT ; 
    nm = FUNCCALL(SETUP_XfOrM233(_), make_name ("" , base , blen , "-set!" , ((void * ) 0 ) , 0 , "" , 1 ) ); 
    names [pos ++ ] = nm ; 
  }
  if (flags & 0x80 ) {
    Scheme_Object * nm ; 
    BLOCK_SETUP((PUSH(nm, 0+XfOrM231_COUNT)));
#   define XfOrM232_COUNT (1+XfOrM231_COUNT)
#   define SETUP_XfOrM232(x) SETUP(XfOrM232_COUNT)
    nm = NULLED_OUT ; 
    nm = FUNCCALL(SETUP_XfOrM232(_), make_name ("" , base , blen , "" , ((void * ) 0 ) , 0 , "" , 1 ) ); 
    names [pos ++ ] = nm ; 
  }
  RET_VALUE_START (names ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * * scheme_make_struct_names (Scheme_Object * base , Scheme_Object * field_symbols , int flags , int * count_out ) {
  int len ; 
  char * __funcarg75 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(count_out, 0), PUSH(base, 1), PUSH(field_symbols, 2)));
# define XfOrM250_COUNT (3)
# define SETUP_XfOrM250(x) SETUP(XfOrM250_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  len = field_symbols ? FUNCCALL(SETUP_XfOrM250(_), scheme_list_length (field_symbols ) ): 0 ; 
  RET_VALUE_START ((__funcarg75 = FUNCCALL(SETUP_XfOrM250(_), scheme_symbol_val (base ) ), FUNCCALL_EMPTY(_make_struct_names (__funcarg75 , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (base ) ) ) -> len ) , len , field_symbols , ((void * ) 0 ) , flags , count_out ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * * scheme_make_struct_names_from_array (const char * base , int fcount , const char * * fields , int flags , int * count_out ) {
  /* No conversion */
  return _make_struct_names (base , strlen (base ) , fcount , ((void * ) 0 ) , fields , flags , count_out ) ; 
}
static Scheme_Object * make_struct_proc (Scheme_Struct_Type * struct_type , char * func_name , Scheme_ProcT proc_type , int field_num ) {
  Scheme_Object * p , * a [1 ] ; 
  short flags = 0 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(7);
  BLOCK_SETUP_TOP((PUSH(struct_type, 0), PUSHARRAY(a, 1, 1), PUSH(p, 4), PUSH(func_name, 5)));
# define XfOrM252_COUNT (6)
# define SETUP_XfOrM252(x) SETUP(XfOrM252_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  p = NULLED_OUT ; 
  a[0] = NULLED_OUT ; 
  if (proc_type == SCHEME_CONSTR ) {
    int simple ; 
#   define XfOrM257_COUNT (0+XfOrM252_COUNT)
#   define SETUP_XfOrM257(x) SETUP_XfOrM252(x)
    simple = FUNCCALL(SETUP_XfOrM257(_), is_simple_struct_type (struct_type ) ); 
    a [0 ] = (Scheme_Object * ) struct_type ; 
    p = FUNCCALL(SETUP_XfOrM257(_), scheme_make_folding_prim_closure ((simple ? make_simple_struct_instance : make_struct_instance ) , 1 , a , func_name , struct_type -> num_islots , struct_type -> num_islots , 0 ) ); 
    flags |= 64 | 32 ; 
  }
  else if (proc_type == SCHEME_PRED ) {
#   define XfOrM256_COUNT (0+XfOrM252_COUNT)
#   define SETUP_XfOrM256(x) SETUP_XfOrM252(x)
    a [0 ] = (Scheme_Object * ) struct_type ; 
    p = FUNCCALL(SETUP_XfOrM256(_), scheme_make_folding_prim_closure (struct_pred , 1 , a , func_name , 1 , 1 , 1 ) ); 
    flags |= 8 ; 
  }
  else {
    Struct_Proc_Info * i ; 
    int need_pos ; 
    BLOCK_SETUP((PUSH(i, 0+XfOrM252_COUNT)));
#   define XfOrM253_COUNT (1+XfOrM252_COUNT)
#   define SETUP_XfOrM253(x) SETUP(XfOrM253_COUNT)
    i = NULLED_OUT ; 
    i = ((Struct_Proc_Info * ) FUNCCALL(SETUP_XfOrM253(_), GC_malloc_one_small_tagged ((((sizeof (Struct_Proc_Info ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    i -> type = scheme_rt_struct_proc_info ; 
    i -> struct_type = struct_type ; 
    i -> func_name = func_name ; 
    i -> field = field_num ; 
    if ((proc_type == SCHEME_GEN_GETTER ) || (proc_type == SCHEME_GEN_SETTER ) )
      need_pos = 1 ; 
    else need_pos = 0 ; 
    a [0 ] = (Scheme_Object * ) i ; 
    if ((proc_type == SCHEME_GETTER ) || (proc_type == SCHEME_GEN_GETTER ) ) {
#     define XfOrM255_COUNT (0+XfOrM253_COUNT)
#     define SETUP_XfOrM255(x) SETUP_XfOrM253(x)
      p = FUNCCALL(SETUP_XfOrM255(_), scheme_make_folding_prim_closure (struct_getter , 1 , a , func_name , 1 + need_pos , 1 + need_pos , 1 ) ); 
      if (need_pos )
        flags |= 0 | 32 ; 
      else flags |= 4 ; 
    }
    else {
#     define XfOrM254_COUNT (0+XfOrM253_COUNT)
#     define SETUP_XfOrM254(x) SETUP_XfOrM253(x)
      p = FUNCCALL(SETUP_XfOrM254(_), scheme_make_folding_prim_closure (struct_setter , 1 , a , func_name , 2 + need_pos , 2 + need_pos , 0 ) ); 
      if (need_pos )
        flags |= 128 | 32 ; 
      else flags |= (64 | 128 ) | 32 ; 
    }
  }
  ((Scheme_Closed_Primitive_Proc * ) p ) -> pp . flags |= flags ; 
  RET_VALUE_START (p ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_name (const char * pre , const char * tn , int ltn , const char * post1 , const char * fn , int lfn , const char * post2 , int sym ) {
  int total , lp , lp1 , lp2 , xltn , xlfn ; 
  char * name , buffer [256 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(post1, 0), PUSH(post2, 1), PUSH(pre, 2), PUSH(fn, 3), PUSH(name, 4), PUSH(tn, 5)));
# define XfOrM258_COUNT (6)
# define SETUP_XfOrM258(x) SETUP(XfOrM258_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  name = NULLED_OUT ; 
  if (ltn < 0 )
    xltn = (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) ((Scheme_Object * ) tn ) ) ) -> len ) ; 
  else xltn = ltn ; 
  if (lfn < 0 )
    xlfn = (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) ((Scheme_Object * ) fn ) ) ) -> len ) ; 
  else xlfn = lfn ; 
  total = lp = strlen (pre ) ; 
  total += xltn ; 
  total += (lp1 = strlen (post1 ) ) ; 
  total += xlfn ; 
  total += (lp2 = strlen (post2 ) ) ; 
  if (sym && (total < 256 ) )
    name = buffer ; 
  else name = (char * ) FUNCCALL(SETUP_XfOrM258(_), GC_malloc_atomic (sizeof (char ) * (total + 1 ) ) ); 
  (memcpy (name , pre , lp ) ) ; 
  total = lp ; 
  (memcpy (name + total , (ltn < 0 ) ? (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) ((Scheme_Object * ) tn ) ) ) -> s ) : tn , xltn ) ) ; 
  total += xltn ; 
  (memcpy (name + total , post1 , lp1 ) ) ; 
  total += lp1 ; 
  (memcpy (name + total , (lfn < 0 ) ? (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) ((Scheme_Object * ) fn ) ) ) -> s ) : fn , xlfn ) ) ; 
  total += xlfn ; 
  (memcpy (name + total , post2 , lp2 ) ) ; 
  total += lp2 ; 
  name [total ] = 0 ; 
  if (sym )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_intern_exact_symbol (name , total ) )) RET_VALUE_EMPTY_END ; 
  else RET_VALUE_START ((Scheme_Object * ) name ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * get_phase_ids (Scheme_Object * _v , int phase ) {
  Scheme_Object * * v = (Scheme_Object * * ) _v ; 
  Scheme_Object * l , * * names , * tp , * cns , * prd , * super_exptime , * w , * macro ; 
  Scheme_Hash_Table * ht ; 
  int count , i , flags ; 
  Scheme_Object * __funcarg79 = NULLED_OUT ; 
  Scheme_Object * __funcarg78 = NULLED_OUT ; 
  Scheme_Object * __funcarg77 = NULLED_OUT ; 
  Scheme_Object * __funcarg76 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(13);
  BLOCK_SETUP_TOP((PUSH(macro, 0), PUSH(prd, 1), PUSH(names, 2), PUSH(l, 3), PUSH(ht, 4), PUSH(cns, 5), PUSH(v, 6), PUSH(super_exptime, 7), PUSH(tp, 8), PUSH(w, 9)));
# define XfOrM259_COUNT (10)
# define SETUP_XfOrM259(x) SETUP(XfOrM259_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  l = NULLED_OUT ; 
  names = NULLED_OUT ; 
  tp = NULLED_OUT ; 
  cns = NULLED_OUT ; 
  prd = NULLED_OUT ; 
  super_exptime = NULLED_OUT ; 
  w = NULLED_OUT ; 
  macro = NULLED_OUT ; 
  ht = NULLED_OUT ; 
  ht = (Scheme_Hash_Table * ) v [3 ] ; 
  if (! ht ) {
#   define XfOrM270_COUNT (0+XfOrM259_COUNT)
#   define SETUP_XfOrM270(x) SETUP_XfOrM259(x)
    ht = FUNCCALL(SETUP_XfOrM270(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
    v [3 ] = (Scheme_Object * ) ht ; 
  }
  l = FUNCCALL(SETUP_XfOrM259(_), scheme_hash_get (ht , ((Scheme_Object * ) (void * ) (long ) ((((long ) (phase ) ) << 1 ) | 0x1 ) ) ) ); 
  if (l )
    RET_VALUE_START (l ) RET_VALUE_END ; 
  names = (Scheme_Object * * ) v [0 ] ; 
  count = (((long ) (v [1 ] ) ) >> 1 ) ; 
  super_exptime = v [2 ] ; 
  w = FUNCCALL(SETUP_XfOrM259(_), scheme_sys_wraps ((Scheme_Comp_Env * ) (((Scheme_Object * ) (void * ) (long ) ((((long ) (phase ) ) << 1 ) | 0x1 ) ) ) ) ); 
  tp = names [0 ] ; 
  cns = names [1 ] ; 
  prd = names [2 ] ; 
  tp = FUNCCALL(SETUP_XfOrM259(_), scheme_datum_to_syntax (tp , scheme_false , w , 0 , 0 ) ); 
  cns = FUNCCALL_AGAIN(scheme_datum_to_syntax (cns , scheme_false , w , 0 , 0 ) ); 
  prd = FUNCCALL_AGAIN(scheme_datum_to_syntax (prd , scheme_false , w , 0 , 0 ) ); 
  if (super_exptime ) {
#   define XfOrM269_COUNT (0+XfOrM259_COUNT)
#   define SETUP_XfOrM269(x) SETUP_XfOrM259(x)
    super_exptime = FUNCCALL(SETUP_XfOrM269(_), get_phase_ids ((((Scheme_Simple_Object * ) (super_exptime ) ) -> u . two_ptr_val . ptr2 ) , phase ) ); 
    super_exptime = (((Scheme_Small_Object * ) (super_exptime ) ) -> u . ptr_val ) ; 
    l = (__funcarg79 = FUNCCALL(SETUP_XfOrM269(_), scheme_datum_to_syntax (v [4 ] , scheme_false , w , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg79 , scheme_null ) )) ; 
    super_exptime = (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (super_exptime ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . cdr ) ; 
  }
  else {
#   define XfOrM268_COUNT (0+XfOrM259_COUNT)
#   define SETUP_XfOrM268(x) SETUP_XfOrM259(x)
    l = FUNCCALL(SETUP_XfOrM268(_), scheme_make_pair (scheme_true , scheme_null ) ); 
  }
  if (count > 3 ) {
    Scheme_Object * n , * gets , * sets ; 
    BLOCK_SETUP((PUSH(gets, 0+XfOrM259_COUNT), PUSH(n, 1+XfOrM259_COUNT), PUSH(sets, 2+XfOrM259_COUNT)));
#   define XfOrM261_COUNT (3+XfOrM259_COUNT)
#   define SETUP_XfOrM261(x) SETUP(XfOrM261_COUNT)
    n = NULLED_OUT ; 
    gets = NULLED_OUT ; 
    sets = NULLED_OUT ; 
    if (super_exptime ) {
      gets = (((Scheme_Simple_Object * ) (super_exptime ) ) -> u . pair_val . car ) ; 
      sets = ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (super_exptime ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) ; 
    }
    else {
      gets = scheme_null ; 
      sets = scheme_null ; 
    }
    flags = (((long ) (v [5 ] ) ) >> 1 ) ; 
    for (i = 3 ; i < count - 1 ; i ++ ) {
#     define XfOrM264_COUNT (0+XfOrM261_COUNT)
#     define SETUP_XfOrM264(x) SETUP_XfOrM261(x)
      n = names [i ] ; 
      n = FUNCCALL(SETUP_XfOrM264(_), scheme_datum_to_syntax (n , scheme_false , w , 0 , 0 ) ); 
      gets = FUNCCALL_AGAIN(scheme_make_immutable_pair (n , gets ) ); 
      if (! (flags & 0x10 ) ) {
        i ++ ; 
#       define XfOrM265_COUNT (0+XfOrM264_COUNT)
#       define SETUP_XfOrM265(x) SETUP_XfOrM264(x)
        n = names [i ] ; 
        n = FUNCCALL(SETUP_XfOrM265(_), scheme_datum_to_syntax (n , scheme_false , w , 0 , 0 ) ); 
        sets = FUNCCALL_AGAIN(scheme_make_immutable_pair (n , sets ) ); 
      }
      else sets = FUNCCALL(SETUP_XfOrM264(_), scheme_make_immutable_pair (scheme_false , sets ) ); 
    }
    l = (__funcarg78 = FUNCCALL(SETUP_XfOrM261(_), scheme_make_immutable_pair (sets , l ) ), FUNCCALL_AGAIN(scheme_make_pair (gets , __funcarg78 ) )) ; 
  }
  else {
#   define XfOrM260_COUNT (0+XfOrM259_COUNT)
#   define SETUP_XfOrM260(x) SETUP_XfOrM259(x)
    if (super_exptime )
      l = (__funcarg77 = FUNCCALL(SETUP_XfOrM260(_), scheme_make_immutable_pair (((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (super_exptime ) ) -> u . pair_val . cdr ) ) ) -> u . pair_val . car ) ) , l ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair ((((Scheme_Simple_Object * ) (super_exptime ) ) -> u . pair_val . car ) , __funcarg77 ) )) ; 
    else l = (__funcarg76 = FUNCCALL(SETUP_XfOrM260(_), scheme_make_immutable_pair (scheme_null , l ) ), FUNCCALL_AGAIN(scheme_make_immutable_pair (scheme_null , __funcarg76 ) )) ; 
  }
  l = FUNCCALL(SETUP_XfOrM259(_), scheme_make_immutable_pair (prd , l ) ); 
  l = FUNCCALL(SETUP_XfOrM259(_), scheme_make_immutable_pair (cns , l ) ); 
  l = FUNCCALL_AGAIN(scheme_make_immutable_pair (tp , l ) ); 
  macro = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM259(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  macro -> type = scheme_macro_type ; 
  (((Scheme_Small_Object * ) (macro ) ) -> u . ptr_val ) = l ; 
  FUNCCALL(SETUP_XfOrM259(_), scheme_hash_set (ht , ((Scheme_Object * ) (void * ) (long ) ((((long ) (phase ) ) << 1 ) | 0x1 ) ) , macro ) ); 
  RET_VALUE_START (macro ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_struct_exptime (Scheme_Object * * names , int count , Scheme_Object * super_sym , Scheme_Object * super_exptime , int flags ) {
  Scheme_Object * macro ; 
  Scheme_Object * * v ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(macro, 1), PUSH(names, 2), PUSH(super_exptime, 3), PUSH(super_sym, 4)));
# define XfOrM271_COUNT (5)
# define SETUP_XfOrM271(x) SETUP(XfOrM271_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  macro = NULLED_OUT ; 
  v = NULLED_OUT ; 
  if (! (flags & 0x80 ) ) {
#   define XfOrM272_COUNT (0+XfOrM271_COUNT)
#   define SETUP_XfOrM272(x) SETUP_XfOrM271(x)
    FUNCCALL_EMPTY(scheme_signal_error ("struct exptime needs SCHEME_STRUCT_EXPTIME" ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  v = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM271(_), GC_malloc (sizeof (Scheme_Object * ) * (6 ) ) )) ; 
  v [0 ] = (Scheme_Object * ) names ; 
  v [1 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (count ) ) << 1 ) | 0x1 ) ) ; 
  v [2 ] = super_exptime ; 
  v [3 ] = ((void * ) 0 ) ; 
  v [4 ] = super_sym ; 
  v [5 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (flags ) ) << 1 ) | 0x1 ) ) ; 
  macro = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM271(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Simple_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  macro -> type = scheme_lazy_macro_type ; 
  (((Scheme_Simple_Object * ) (macro ) ) -> u . two_ptr_val . ptr1 ) = (Scheme_Object * ) get_phase_ids ; 
  (((Scheme_Simple_Object * ) (macro ) ) -> u . two_ptr_val . ptr2 ) = (Scheme_Object * ) v ; 
  RET_VALUE_START (macro ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 2743 */
/* this far 2739 */
static Scheme_Object * _make_struct_type (Scheme_Object * basesym , const char * base , int blen , Scheme_Object * parent , Scheme_Object * inspector , int num_fields , int num_uninit_fields , Scheme_Object * uninit_val , Scheme_Object * props , Scheme_Object * proc_attr , Scheme_Object * immutable_pos_list , Scheme_Object * guard ) {
  Scheme_Struct_Type * struct_type , * parent_type ; 
  int j , depth ; 
  int props_delta = 0 , prop_needs_const = 0 ; 
  Scheme_Config * __funcarg80 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(17);
  BLOCK_SETUP_TOP((PUSH(struct_type, 0), PUSH(proc_attr, 1), PUSH(immutable_pos_list, 2), PUSH(inspector, 3), PUSH(parent_type, 4), PUSH(uninit_val, 5), PUSH(base, 6), PUSH(guard, 7), PUSH(basesym, 8), PUSH(props, 9)));
# define XfOrM273_COUNT (10)
# define SETUP_XfOrM273(x) SETUP(XfOrM273_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  struct_type = NULLED_OUT ; 
  parent_type = NULLED_OUT ; 
  parent_type = (Scheme_Struct_Type * ) parent ; 
  depth = parent_type ? (1 + parent_type -> name_pos ) : 0 ; 
  struct_type = (Scheme_Struct_Type * ) FUNCCALL(SETUP_XfOrM273(_), GC_malloc_one_tagged (sizeof (Scheme_Struct_Type ) + (depth * sizeof (Scheme_Struct_Type * ) ) ) ); 
  depth = parent_type ? (1 + parent_type -> name_pos ) : 0 ; 
  struct_type -> so . type = scheme_struct_type_type ; 
  struct_type -> name_pos = depth ; 
  struct_type -> parent_types [depth ] = struct_type ; 
  for (j = depth ; j -- ; ) {
    struct_type -> parent_types [j ] = parent_type -> parent_types [j ] ; 
  }
  {
    Scheme_Object * tn ; 
    BLOCK_SETUP((PUSH(tn, 0+XfOrM273_COUNT)));
#   define XfOrM338_COUNT (1+XfOrM273_COUNT)
#   define SETUP_XfOrM338(x) SETUP(XfOrM338_COUNT)
    tn = NULLED_OUT ; 
    if (basesym )
      tn = basesym ; 
    else tn = FUNCCALL(SETUP_XfOrM338(_), scheme_intern_exact_symbol (base , blen ) ); 
    struct_type -> name = tn ; 
  }
  struct_type -> num_slots = num_fields + num_uninit_fields + (parent_type ? parent_type -> num_slots : 0 ) ; 
  struct_type -> num_islots = num_fields + (parent_type ? parent_type -> num_islots : 0 ) ; 
  if (parent_type )
    struct_type -> proc_attr = parent_type -> proc_attr ; 
  if ((num_fields < 0 ) || (num_uninit_fields < 0 ) || (num_fields > 32768 ) || (num_uninit_fields > 32768 ) || (num_uninit_fields + num_fields > 32768 ) || (parent_type && ((struct_type -> num_slots < parent_type -> num_slots ) || (struct_type -> num_islots < parent_type -> num_islots ) ) ) ) {
#   define XfOrM337_COUNT (0+XfOrM273_COUNT)
#   define SETUP_XfOrM337(x) SETUP_XfOrM273(x)
    FUNCCALL(SETUP_XfOrM337(_), scheme_raise_exn (MZEXN_FAIL , "too many fields for struct-type; maximum total field count is 32768" ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  if (! inspector ) {
#   define XfOrM335_COUNT (0+XfOrM273_COUNT)
#   define SETUP_XfOrM335(x) SETUP_XfOrM273(x)
    if (parent_type )
      inspector = parent_type -> inspector ; 
    else {
#     define XfOrM336_COUNT (0+XfOrM335_COUNT)
#     define SETUP_XfOrM336(x) SETUP_XfOrM335(x)
      inspector = (__funcarg80 = FUNCCALL(SETUP_XfOrM336(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg80 , MZCONFIG_INSPECTOR ) )) ; 
    }
  }
  struct_type -> inspector = inspector ; 
  if (parent_type ) {
    struct_type -> num_props = parent_type -> num_props ; 
    struct_type -> props = parent_type -> props ; 
  }
  if (! uninit_val )
    uninit_val = scheme_false ; 
  struct_type -> uninit_val = uninit_val ; 
  if (props ) {
    Scheme_Object * l ; 
    BLOCK_SETUP((PUSH(l, 0+XfOrM273_COUNT)));
#   define XfOrM327_COUNT (1+XfOrM273_COUNT)
#   define SETUP_XfOrM327(x) SETUP(XfOrM327_COUNT)
    l = NULLED_OUT ; 
    for (l = props ; ! ((l ) == (scheme_null ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#     define XfOrM331_COUNT (0+XfOrM327_COUNT)
#     define SETUP_XfOrM331(x) SETUP_XfOrM327(x)
      if (((((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) ) == (proc_property ) ) ) {
#       define XfOrM332_COUNT (0+XfOrM331_COUNT)
#       define SETUP_XfOrM332(x) SETUP_XfOrM331(x)
        if (proc_attr ) {
#         define XfOrM333_COUNT (0+XfOrM332_COUNT)
#         define SETUP_XfOrM333(x) SETUP_XfOrM332(x)
          FUNCCALL(SETUP_XfOrM333(_), scheme_arg_mismatch ("make-struct-type" , "given both a prop:procedure property value and a procedure specification: " , proc_attr ) ); 
        }
        proc_attr = (((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) ; 
        if ((((long ) (proc_attr ) ) & 0x1 ) )
          prop_needs_const = 1 ; 
        props_delta = 1 ; 
        break ; 
      }
    }
  }
  if (proc_attr ) {
    Scheme_Object * pa = proc_attr ; 
    BLOCK_SETUP((PUSH(pa, 0+XfOrM273_COUNT)));
#   define XfOrM322_COUNT (1+XfOrM273_COUNT)
#   define SETUP_XfOrM322(x) SETUP(XfOrM322_COUNT)
    if ((((long ) (pa ) ) & 0x1 ) || ((Scheme_Type ) (((((long ) (pa ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (pa ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) ) {
      long pos ; 
#     define XfOrM323_COUNT (0+XfOrM322_COUNT)
#     define SETUP_XfOrM323(x) SETUP_XfOrM322(x)
      if ((((long ) (pa ) ) & 0x1 ) )
        pos = (((long ) (pa ) ) >> 1 ) ; 
      else pos = struct_type -> num_slots ; 
      if (pos >= struct_type -> num_islots ) {
#       define XfOrM326_COUNT (0+XfOrM323_COUNT)
#       define SETUP_XfOrM326(x) SETUP_XfOrM323(x)
        FUNCCALL(SETUP_XfOrM326(_), scheme_arg_mismatch ("make-struct-type" , "index for procedure >= initialized-field count: " , pa ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      if (parent_type ) {
#       define XfOrM324_COUNT (0+XfOrM323_COUNT)
#       define SETUP_XfOrM324(x) SETUP_XfOrM323(x)
        if (parent_type -> proc_attr ) {
#         define XfOrM325_COUNT (0+XfOrM324_COUNT)
#         define SETUP_XfOrM325(x) SETUP_XfOrM324(x)
          FUNCCALL(SETUP_XfOrM325(_), scheme_arg_mismatch ("make-struct-type" , "parent type already has procedure specification, new one disallowed: " , pa ) ); 
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        }
        pos += parent_type -> num_slots ; 
        pa = ((Scheme_Object * ) (void * ) (long ) ((((long ) (pos ) ) << 1 ) | 0x1 ) ) ; 
      }
    }
    struct_type -> proc_attr = pa ; 
  }
  if ((struct_type -> proc_attr && (((long ) (struct_type -> proc_attr ) ) & 0x1 ) ) || ! ((immutable_pos_list ) == (scheme_null ) ) ) {
    Scheme_Object * l , * a ; 
    char * ims ; 
    int n , p ; 
    BLOCK_SETUP((PUSH(ims, 0+XfOrM273_COUNT), PUSH(a, 1+XfOrM273_COUNT), PUSH(l, 2+XfOrM273_COUNT)));
#   define XfOrM312_COUNT (3+XfOrM273_COUNT)
#   define SETUP_XfOrM312(x) SETUP(XfOrM312_COUNT)
    l = NULLED_OUT ; 
    a = NULLED_OUT ; 
    ims = NULLED_OUT ; 
    n = struct_type -> num_slots ; 
    if (parent_type )
      n -= parent_type -> num_slots ; 
    ims = (char * ) FUNCCALL(SETUP_XfOrM312(_), GC_malloc_atomic (n ) ); 
    (memset (ims , 0 , n ) ) ; 
    if (proc_attr && (((long ) (proc_attr ) ) & 0x1 ) && ! prop_needs_const ) {
      p = (((long ) (proc_attr ) ) >> 1 ) ; 
      ims [p ] = 1 ; 
    }
    for (l = immutable_pos_list ; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#     define XfOrM318_COUNT (0+XfOrM312_COUNT)
#     define SETUP_XfOrM318(x) SETUP_XfOrM312(x)
      a = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
      if ((((long ) (a ) ) & 0x1 ) )
        p = (((long ) (a ) ) >> 1 ) ; 
      else p = struct_type -> num_slots ; 
      if (p >= struct_type -> num_islots ) {
#       define XfOrM320_COUNT (0+XfOrM318_COUNT)
#       define SETUP_XfOrM320(x) SETUP_XfOrM318(x)
        FUNCCALL(SETUP_XfOrM320(_), scheme_raise_exn (MZEXN_FAIL_CONTRACT , "make-struct-type: index %V for immutable field >= initialized-field count %d in list: %V" , a , struct_type -> num_islots , immutable_pos_list ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      if (ims [p ] ) {
#       define XfOrM319_COUNT (0+XfOrM318_COUNT)
#       define SETUP_XfOrM319(x) SETUP_XfOrM318(x)
        FUNCCALL(SETUP_XfOrM319(_), scheme_raise_exn (MZEXN_FAIL_CONTRACT , "make-struct-type: redundant immutable field index %V in list: %V" , a , immutable_pos_list ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      ims [p ] = 1 ; 
    }
    if (proc_attr && (((long ) (proc_attr ) ) & 0x1 ) && prop_needs_const ) {
#     define XfOrM313_COUNT (0+XfOrM312_COUNT)
#     define SETUP_XfOrM313(x) SETUP_XfOrM312(x)
      p = (((long ) (proc_attr ) ) >> 1 ) ; 
      if (! ims [p ] ) {
#       define XfOrM314_COUNT (0+XfOrM313_COUNT)
#       define SETUP_XfOrM314(x) SETUP_XfOrM313(x)
        FUNCCALL(SETUP_XfOrM314(_), scheme_arg_mismatch ("make-struct-type" , "field is not specified as immutable for a prop:procedure index: " , proc_attr ) ); 
      }
    }
    struct_type -> immutables = ims ; 
  }
  if (props ) {
    int num_props , i ; 
    Scheme_Hash_Table * can_override ; 
    Scheme_Object * l , * a , * prop , * propv ; 
    BLOCK_SETUP((PUSH(prop, 0+XfOrM273_COUNT), PUSH(a, 1+XfOrM273_COUNT), PUSH(propv, 2+XfOrM273_COUNT), PUSH(l, 3+XfOrM273_COUNT), PUSH(can_override, 4+XfOrM273_COUNT)));
#   define XfOrM276_COUNT (5+XfOrM273_COUNT)
#   define SETUP_XfOrM276(x) SETUP(XfOrM276_COUNT)
    can_override = NULLED_OUT ; 
    l = NULLED_OUT ; 
    a = NULLED_OUT ; 
    prop = NULLED_OUT ; 
    propv = NULLED_OUT ; 
    can_override = FUNCCALL(SETUP_XfOrM276(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
    num_props = FUNCCALL_AGAIN(scheme_list_length (props ) )- props_delta ; 
    if ((struct_type -> num_props < 0 ) || (struct_type -> num_props + num_props > 5 ) ) {
      Scheme_Hash_Table * ht ; 
      BLOCK_SETUP((PUSH(ht, 0+XfOrM276_COUNT)));
#     define XfOrM295_COUNT (1+XfOrM276_COUNT)
#     define SETUP_XfOrM295(x) SETUP(XfOrM295_COUNT)
      ht = NULLED_OUT ; 
      ht = FUNCCALL(SETUP_XfOrM295(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
      if (struct_type -> num_props >= 0 ) {
#       define XfOrM309_COUNT (0+XfOrM295_COUNT)
#       define SETUP_XfOrM309(x) SETUP_XfOrM295(x)
        for (i = 0 ; i < struct_type -> num_props ; i ++ ) {
#         define XfOrM311_COUNT (0+XfOrM309_COUNT)
#         define SETUP_XfOrM311(x) SETUP_XfOrM309(x)
          prop = (((Scheme_Simple_Object * ) (struct_type -> props [i ] ) ) -> u . pair_val . car ) ; 
          FUNCCALL(SETUP_XfOrM311(_), scheme_hash_set (ht , prop , (((Scheme_Simple_Object * ) (struct_type -> props [i ] ) ) -> u . pair_val . cdr ) ) ); 
          FUNCCALL_AGAIN(scheme_hash_set (can_override , prop , scheme_true ) ); 
        }
      }
      else {
        Scheme_Hash_Table * oht = (Scheme_Hash_Table * ) struct_type -> props ; 
        BLOCK_SETUP((PUSH(oht, 0+XfOrM295_COUNT)));
#       define XfOrM304_COUNT (1+XfOrM295_COUNT)
#       define SETUP_XfOrM304(x) SETUP(XfOrM304_COUNT)
        for (i = oht -> count ; i -- ; ) {
#         define XfOrM307_COUNT (0+XfOrM304_COUNT)
#         define SETUP_XfOrM307(x) SETUP_XfOrM304(x)
          if (oht -> vals [i ] ) {
#           define XfOrM308_COUNT (0+XfOrM307_COUNT)
#           define SETUP_XfOrM308(x) SETUP_XfOrM307(x)
            prop = oht -> keys [i ] ; 
            FUNCCALL(SETUP_XfOrM308(_), scheme_hash_set (ht , prop , oht -> vals [i ] ) ); 
            FUNCCALL_AGAIN(scheme_hash_set (can_override , prop , scheme_true ) ); 
          }
        }
      }
      for (l = props ; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#       define XfOrM300_COUNT (0+XfOrM295_COUNT)
#       define SETUP_XfOrM300(x) SETUP_XfOrM295(x)
        a = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
        prop = (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) ; 
        if (((prop ) == (proc_property ) ) ) {
          if (props_delta )
            props_delta = 0 ; 
          else break ; 
        }
        else {
#         define XfOrM301_COUNT (0+XfOrM300_COUNT)
#         define SETUP_XfOrM301(x) SETUP_XfOrM300(x)
          if (FUNCCALL(SETUP_XfOrM301(_), scheme_hash_get (ht , prop ) )) {
#           define XfOrM302_COUNT (0+XfOrM301_COUNT)
#           define SETUP_XfOrM302(x) SETUP_XfOrM301(x)
            if (! FUNCCALL(SETUP_XfOrM302(_), scheme_hash_get (can_override , prop ) ))
              break ; 
            FUNCCALL(SETUP_XfOrM302(_), scheme_hash_set (can_override , prop , ((void * ) 0 ) ) ); 
          }
          propv = FUNCCALL(SETUP_XfOrM301(_), guard_property (prop , (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) , struct_type ) ); 
          FUNCCALL(SETUP_XfOrM301(_), scheme_hash_set (ht , prop , propv ) ); 
        }
      }
      struct_type -> props = (Scheme_Object * * ) ht ; 
      struct_type -> num_props = - 1 ; 
    }
    else {
      Scheme_Object * * pa ; 
      int j ; 
      BLOCK_SETUP((PUSH(pa, 0+XfOrM276_COUNT)));
#     define XfOrM278_COUNT (1+XfOrM276_COUNT)
#     define SETUP_XfOrM278(x) SETUP(XfOrM278_COUNT)
      pa = NULLED_OUT ; 
      for (i = 0 ; i < struct_type -> num_props ; i ++ ) {
#       define XfOrM294_COUNT (0+XfOrM278_COUNT)
#       define SETUP_XfOrM294(x) SETUP_XfOrM278(x)
        prop = (((Scheme_Simple_Object * ) (struct_type -> props [i ] ) ) -> u . pair_val . car ) ; 
        FUNCCALL(SETUP_XfOrM294(_), scheme_hash_set (can_override , prop , scheme_true ) ); 
      }
      pa = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM278(_), GC_malloc (sizeof (Scheme_Object * ) * (i + num_props ) ) )) ; 
      (memcpy (pa , struct_type -> props , sizeof (Scheme_Object * ) * i ) ) ; 
      num_props = i ; 
      for (l = props ; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
#       define XfOrM286_COUNT (0+XfOrM278_COUNT)
#       define SETUP_XfOrM286(x) SETUP_XfOrM278(x)
        a = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
        prop = (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) ; 
        if (((prop ) == (proc_property ) ) ) {
          if (props_delta )
            props_delta = 0 ; 
          else break ; 
        }
        else {
#         define XfOrM287_COUNT (0+XfOrM286_COUNT)
#         define SETUP_XfOrM287(x) SETUP_XfOrM286(x)
          for (j = 0 ; j < num_props ; j ++ ) {
            if ((((((Scheme_Simple_Object * ) (pa [j ] ) ) -> u . pair_val . car ) ) == (prop ) ) )
              break ; 
          }
          if (j < num_props ) {
#           define XfOrM289_COUNT (0+XfOrM287_COUNT)
#           define SETUP_XfOrM289(x) SETUP_XfOrM287(x)
            if (! FUNCCALL(SETUP_XfOrM289(_), scheme_hash_get (can_override , prop ) ))
              break ; 
            FUNCCALL(SETUP_XfOrM289(_), scheme_hash_set (can_override , prop , ((void * ) 0 ) ) ); 
          }
          else {
            num_props ++ ; 
          }
          propv = FUNCCALL(SETUP_XfOrM287(_), guard_property (prop , (((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . cdr ) , struct_type ) ); 
          a = FUNCCALL(SETUP_XfOrM287(_), scheme_make_pair (prop , propv ) ); 
          pa [j ] = a ; 
        }
      }
      struct_type -> num_props = num_props ; 
      struct_type -> props = pa ; 
    }
    if (! ((l ) == (scheme_null ) ) ) {
#     define XfOrM277_COUNT (0+XfOrM276_COUNT)
#     define SETUP_XfOrM277(x) SETUP_XfOrM276(x)
      a = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
      FUNCCALL(SETUP_XfOrM277(_), scheme_arg_mismatch ("make-struct-type" , "duplicate property binding: " , a ) ); 
    }
  }
  if (guard ) {
#   define XfOrM274_COUNT (0+XfOrM273_COUNT)
#   define SETUP_XfOrM274(x) SETUP_XfOrM273(x)
    if (! FUNCCALL(SETUP_XfOrM274(_), scheme_check_proc_arity (((void * ) 0 ) , struct_type -> num_islots + 1 , - 1 , 0 , & guard ) )) {
#     define XfOrM275_COUNT (0+XfOrM274_COUNT)
#     define SETUP_XfOrM275(x) SETUP_XfOrM274(x)
      FUNCCALL(SETUP_XfOrM275(_), scheme_raise_exn (MZEXN_FAIL_CONTRACT , "make-struct-type: guard procedure does not accept %d arguments " "(one more than the number constructor arguments): %V" , struct_type -> num_islots + 1 , guard ) ); 
    }
    struct_type -> guard = guard ; 
  }
  RET_VALUE_START ((Scheme_Object * ) struct_type ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_struct_type (Scheme_Object * base , Scheme_Object * parent , Scheme_Object * inspector , int num_fields , int num_uninit , Scheme_Object * uninit_val , Scheme_Object * properties , Scheme_Object * guard ) {
  /* No conversion */
  return _make_struct_type (base , ((void * ) 0 ) , 0 , parent , inspector , num_fields , num_uninit , uninit_val , properties , ((void * ) 0 ) , scheme_null , guard ) ; 
}
Scheme_Object * scheme_make_proc_struct_type (Scheme_Object * base , Scheme_Object * parent , Scheme_Object * inspector , int num_fields , int num_uninit , Scheme_Object * uninit_val , Scheme_Object * proc_attr , Scheme_Object * guard ) {
  /* No conversion */
  return _make_struct_type (base , ((void * ) 0 ) , 0 , parent , inspector , num_fields , num_uninit , uninit_val , scheme_null , proc_attr , scheme_null , guard ) ; 
}
Scheme_Object * scheme_make_struct_type_from_string (const char * base , Scheme_Object * parent , int num_fields , Scheme_Object * props , Scheme_Object * guard , int immutable ) {
  Scheme_Object * imm = scheme_null ; 
  int i ; 
  PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(guard, 0), PUSH(base, 1), PUSH(imm, 2), PUSH(props, 3), PUSH(parent, 4)));
# define XfOrM343_COUNT (5)
# define SETUP_XfOrM343(x) SETUP(XfOrM343_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (immutable ) {
#   define XfOrM344_COUNT (0+XfOrM343_COUNT)
#   define SETUP_XfOrM344(x) SETUP_XfOrM343(x)
    for (i = 0 ; i < num_fields ; i ++ ) {
#     define XfOrM346_COUNT (0+XfOrM344_COUNT)
#     define SETUP_XfOrM346(x) SETUP_XfOrM344(x)
      imm = FUNCCALL(SETUP_XfOrM346(_), scheme_make_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (i ) ) << 1 ) | 0x1 ) ) , imm ) ); 
    }
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(_make_struct_type (((void * ) 0 ) , base , strlen (base ) , parent , scheme_false , num_fields , 0 , ((void * ) 0 ) , props , ((void * ) 0 ) , imm , guard ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_struct_type (int argc , Scheme_Object * * argv ) {
  int initc , uninitc , num_props = 0 , i ; 
  Scheme_Object * props = scheme_null , * l , * a , * * r ; 
  Scheme_Object * inspector = ((void * ) 0 ) , * * names , * uninit_val ; 
  Scheme_Struct_Type * type ; 
  Scheme_Object * proc_attr = ((void * ) 0 ) , * immutable_pos_list = scheme_null , * guard = ((void * ) 0 ) ; 
  Scheme_Config * __funcarg81 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(12);
  BLOCK_SETUP_TOP((PUSH(proc_attr, 0), PUSH(immutable_pos_list, 1), PUSH(inspector, 2), PUSH(a, 3), PUSH(r, 4), PUSH(props, 5), PUSH(uninit_val, 6), PUSH(guard, 7), PUSH(names, 8), PUSH(type, 9), PUSH(argv, 10), PUSH(l, 11)));
# define XfOrM347_COUNT (12)
# define SETUP_XfOrM347(x) SETUP(XfOrM347_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  l = NULLED_OUT ; 
  a = NULLED_OUT ; 
  r = NULLED_OUT ; 
  names = NULLED_OUT ; 
  uninit_val = NULLED_OUT ; 
  type = NULLED_OUT ; 
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("make-struct-type" , "symbol" , 0 , argc , argv ) ); 
  if (! (((argv [1 ] ) ) == (scheme_false ) ) && ! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_struct_type_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("make-struct-type" , "struct-type or #f" , 1 , argc , argv ) ); 
  if (! (((long ) (argv [2 ] ) ) & 0x1 ) || ((((long ) (argv [2 ] ) ) >> 1 ) < 0 ) ) {
#   define XfOrM368_COUNT (0+XfOrM347_COUNT)
#   define SETUP_XfOrM368(x) SETUP_XfOrM347(x)
    if (((Scheme_Type ) (((((long ) (argv [2 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [2 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) && ((& ((Scheme_Bignum * ) argv [2 ] ) -> iso ) -> so . keyex & 0x1 ) )
      initc = - 1 ; 
    else {
#     define XfOrM369_COUNT (0+XfOrM368_COUNT)
#     define SETUP_XfOrM369(x) SETUP_XfOrM368(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("make-struct-type" , "non-negative exact integer" , 2 , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  else initc = (((long ) (argv [2 ] ) ) >> 1 ) ; 
  if (! (((long ) (argv [3 ] ) ) & 0x1 ) || ((((long ) (argv [3 ] ) ) >> 1 ) < 0 ) ) {
#   define XfOrM366_COUNT (0+XfOrM347_COUNT)
#   define SETUP_XfOrM366(x) SETUP_XfOrM347(x)
    if (((Scheme_Type ) (((((long ) (argv [3 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [3 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) && ((& ((Scheme_Bignum * ) argv [3 ] ) -> iso ) -> so . keyex & 0x1 ) )
      uninitc = - 1 ; 
    else {
#     define XfOrM367_COUNT (0+XfOrM366_COUNT)
#     define SETUP_XfOrM367(x) SETUP_XfOrM366(x)
      FUNCCALL_EMPTY(scheme_wrong_type ("make-struct-type" , "non-negative exact integer" , 3 , argc , argv ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  else uninitc = (((long ) (argv [3 ] ) ) >> 1 ) ; 
  if (argc > 4 ) {
#   define XfOrM348_COUNT (0+XfOrM347_COUNT)
#   define SETUP_XfOrM348(x) SETUP_XfOrM347(x)
    uninit_val = argv [4 ] ; 
    if (argc > 5 ) {
#     define XfOrM349_COUNT (0+XfOrM348_COUNT)
#     define SETUP_XfOrM349(x) SETUP_XfOrM348(x)
      props = argv [5 ] ; 
      for (l = props ; ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
        a = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
        if (! ((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) || ! ((Scheme_Type ) (((((long ) ((((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) ((((Scheme_Simple_Object * ) (a ) ) -> u . pair_val . car ) ) ) -> type ) ) == (Scheme_Type ) (scheme_struct_property_type ) ) )
          break ; 
        num_props ++ ; 
      }
      if (! ((l ) == (scheme_null ) ) ) {
#       define XfOrM363_COUNT (0+XfOrM349_COUNT)
#       define SETUP_XfOrM363(x) SETUP_XfOrM349(x)
        FUNCCALL_EMPTY(scheme_wrong_type ("make-struct-type" , "list of struct-type-property--value pairs" , 5 , argc , argv ) ); 
      }
      if (argc > 6 ) {
#       define XfOrM350_COUNT (0+XfOrM349_COUNT)
#       define SETUP_XfOrM350(x) SETUP_XfOrM349(x)
        if ((((argv [6 ] ) ) == (scheme_false ) ) )
          inspector = scheme_false ; 
        else {
#         define XfOrM362_COUNT (0+XfOrM350_COUNT)
#         define SETUP_XfOrM362(x) SETUP_XfOrM350(x)
          if (! ((Scheme_Type ) (((((long ) (argv [6 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [6 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_inspector_type ) ) )
            FUNCCALL_EMPTY(scheme_wrong_type ("make-struct-type" , "inspector or #f" , 6 , argc , argv ) ); 
          inspector = argv [6 ] ; 
        }
        if (argc > 7 ) {
#         define XfOrM351_COUNT (0+XfOrM350_COUNT)
#         define SETUP_XfOrM351(x) SETUP_XfOrM350(x)
          if (! (((argv [7 ] ) ) == (scheme_false ) ) ) {
#           define XfOrM360_COUNT (0+XfOrM351_COUNT)
#           define SETUP_XfOrM360(x) SETUP_XfOrM351(x)
            proc_attr = argv [7 ] ; 
            if (! (((((long ) (proc_attr ) ) & 0x1 ) && ((((long ) (proc_attr ) ) >> 1 ) >= 0 ) ) || (((Scheme_Type ) (((((long ) (proc_attr ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (proc_attr ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) && ((& ((Scheme_Bignum * ) proc_attr ) -> iso ) -> so . keyex & 0x1 ) ) || (! (((long ) (proc_attr ) ) & 0x1 ) && ((((proc_attr ) -> type ) >= scheme_prim_type ) && (((proc_attr ) -> type ) <= scheme_native_closure_type ) ) ) ) ) {
#             define XfOrM361_COUNT (0+XfOrM360_COUNT)
#             define SETUP_XfOrM361(x) SETUP_XfOrM360(x)
              FUNCCALL_EMPTY(scheme_wrong_type ("make-struct-type" , "exact non-negative integer, procedure, or #f" , 7 , argc , argv ) ); 
              RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
            }
          }
          if (argc > 8 ) {
#           define XfOrM352_COUNT (0+XfOrM351_COUNT)
#           define SETUP_XfOrM352(x) SETUP_XfOrM351(x)
            l = immutable_pos_list = argv [8 ] ; 
            if (FUNCCALL(SETUP_XfOrM352(_), scheme_proper_list_length (l ) )< 0 )
              l = ((void * ) 0 ) ; 
            for (; l && ((Scheme_Type ) (((((long ) (l ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (l ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; l = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . cdr ) ) {
              a = (((Scheme_Simple_Object * ) (l ) ) -> u . pair_val . car ) ; 
              if (! (((((long ) (a ) ) & 0x1 ) && ((((long ) (a ) ) >> 1 ) >= 0 ) ) || (((Scheme_Type ) (((((long ) (a ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (a ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) && ! ((& ((Scheme_Bignum * ) a ) -> iso ) -> so . keyex & 0x1 ) ) ) ) {
                l = ((void * ) 0 ) ; 
                break ; 
              }
            }
            if (! l ) {
#             define XfOrM355_COUNT (0+XfOrM352_COUNT)
#             define SETUP_XfOrM355(x) SETUP_XfOrM352(x)
              FUNCCALL_EMPTY(scheme_wrong_type ("make-struct-type" , "list of exact non-negative integers" , 8 , argc , argv ) ); 
              RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
            }
            if (argc > 9 ) {
#             define XfOrM353_COUNT (0+XfOrM352_COUNT)
#             define SETUP_XfOrM353(x) SETUP_XfOrM352(x)
              if ((! (((argv [9 ] ) ) == (scheme_false ) ) ) ) {
#               define XfOrM354_COUNT (0+XfOrM353_COUNT)
#               define SETUP_XfOrM354(x) SETUP_XfOrM353(x)
                guard = argv [9 ] ; 
                if (! (! (((long ) (guard ) ) & 0x1 ) && ((((guard ) -> type ) >= scheme_prim_type ) && (((guard ) -> type ) <= scheme_native_closure_type ) ) ) )
                  FUNCCALL_EMPTY(scheme_wrong_type ("make-struct-type" , "procedure or #f" , 9 , argc , argv ) ); 
              }
            }
          }
        }
      }
    }
  }
  else uninit_val = scheme_false ; 
  if (! inspector )
    inspector = (__funcarg81 = FUNCCALL(SETUP_XfOrM347(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg81 , MZCONFIG_INSPECTOR ) )) ; 
  type = (Scheme_Struct_Type * ) FUNCCALL(SETUP_XfOrM347(_), _make_struct_type (argv [0 ] , ((void * ) 0 ) , 0 , (((argv [1 ] ) ) == (scheme_false ) ) ? ((void * ) 0 ) : argv [1 ] , inspector , initc , uninitc , uninit_val , props , proc_attr , immutable_pos_list , guard ) ); 
  names = FUNCCALL(SETUP_XfOrM347(_), scheme_make_struct_names (argv [0 ] , ((void * ) 0 ) , 0x20 | 0x40 , & i ) ); 
  r = FUNCCALL_AGAIN(scheme_make_struct_values ((Scheme_Object * ) type , names , i , 0x20 | 0x40 ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_values (i , r ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_extract_struct_procedure (Scheme_Object * obj , int num_rands , Scheme_Object * * rands , int * is_method ) {
  Scheme_Struct_Type * stype ; 
  Scheme_Object * a , * proc ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(proc, 0), PUSH(obj, 1), PUSH(rands, 2)));
# define XfOrM370_COUNT (3)
# define SETUP_XfOrM370(x) SETUP(XfOrM370_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  stype = NULLED_OUT ; 
  a = NULLED_OUT ; 
  proc = NULLED_OUT ; 
  stype = ((Scheme_Structure * ) obj ) -> stype ; 
  a = stype -> proc_attr ; 
  if ((((long ) (a ) ) & 0x1 ) ) {
    * is_method = 0 ; 
    proc = ((Scheme_Structure * ) obj ) -> slots [(((long ) (a ) ) >> 1 ) ] ; 
  }
  else {
    * is_method = 1 ; 
    proc = a ; 
  }
  if (num_rands >= 0 ) {
#   define XfOrM371_COUNT (0+XfOrM370_COUNT)
#   define SETUP_XfOrM371(x) SETUP_XfOrM370(x)
    if (! (! (((long ) (proc ) ) & 0x1 ) && ((((proc ) -> type ) >= scheme_prim_type ) && (((proc ) -> type ) <= scheme_native_closure_type ) ) ) || ! FUNCCALL(SETUP_XfOrM371(_), scheme_check_proc_arity (((void * ) 0 ) , num_rands , - 1 , 0 , & obj ) )) {
#     define XfOrM372_COUNT (0+XfOrM371_COUNT)
#     define SETUP_XfOrM372(x) SETUP_XfOrM371(x)
      FUNCCALL(SETUP_XfOrM372(_), scheme_wrong_count_m ((char * ) obj , - 1 , 0 , num_rands , rands , 0 ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  RET_VALUE_START (proc ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int exact_pos_integer (Scheme_Object * o ) {
  /* No conversion */
  if ((((long ) (o ) ) & 0x1 ) )
    return (((long ) (o ) ) >> 1 ) > 0 ; 
  else if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
    return ((& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex & 0x1 ) ; 
  else return 0 ; 
}
static int exact_nneg_integer (Scheme_Object * o ) {
  /* No conversion */
  if ((((long ) (o ) ) & 0x1 ) )
    return (((long ) (o ) ) >> 1 ) >= 0 ; 
  else if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) )
    return ((& ((Scheme_Bignum * ) o ) -> iso ) -> so . keyex & 0x1 ) ; 
  else return 0 ; 
}
Scheme_Object * scheme_make_location (Scheme_Object * src , Scheme_Object * line , Scheme_Object * col , Scheme_Object * pos , Scheme_Object * span ) {
  Scheme_Object * a [5 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 5, 0)));
# define XfOrM377_COUNT (3)
# define SETUP_XfOrM377(x) SETUP(XfOrM377_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  NULL_OUT_ARRAY (a ) ; 
  a [0 ] = src ; 
  a [1 ] = line ; 
  a [2 ] = col ; 
  a [3 ] = pos ; 
  a [4 ] = span ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM377(_), scheme_make_struct_instance (location_struct , 5 , a ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_is_location (Scheme_Object * o ) {
  /* No conversion */
  return scheme_is_struct_instance (location_struct , o ) ; 
}
static Scheme_Object * check_location_fields (int argc , Scheme_Object * * argv ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM379_COUNT (1)
# define SETUP_XfOrM379(x) SETUP(XfOrM379_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if ((! (((argv [1 ] ) ) == (scheme_false ) ) ) && ! FUNCCALL(SETUP_XfOrM379(_), exact_pos_integer (argv [1 ] ) ))
    FUNCCALL(SETUP_XfOrM379(_), scheme_wrong_field_type (argv [5 ] , "exact positive integer or #f" , argv [1 ] ) ); 
  if ((! (((argv [2 ] ) ) == (scheme_false ) ) ) && ! FUNCCALL(SETUP_XfOrM379(_), exact_nneg_integer (argv [2 ] ) ))
    FUNCCALL(SETUP_XfOrM379(_), scheme_wrong_field_type (argv [5 ] , "exact non-negative integer or #f" , argv [2 ] ) ); 
  if ((! (((argv [3 ] ) ) == (scheme_false ) ) ) && ! FUNCCALL(SETUP_XfOrM379(_), exact_pos_integer (argv [3 ] ) ))
    FUNCCALL(SETUP_XfOrM379(_), scheme_wrong_field_type (argv [5 ] , "exact positive integer or #f" , argv [3 ] ) ); 
  if ((! (((argv [4 ] ) ) == (scheme_false ) ) ) && ! FUNCCALL(SETUP_XfOrM379(_), exact_nneg_integer (argv [4 ] ) ))
    FUNCCALL(SETUP_XfOrM379(_), scheme_wrong_field_type (argv [5 ] , "exact non-negative integer or #f" , argv [4 ] ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_values (5 , argv ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_special_comment_value (Scheme_Object * o ) {
  /* No conversion */
  if (((Scheme_Type ) (((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ) == (Scheme_Type ) (scheme_special_comment_type ) ) )
    return ((Scheme_Small_Object * ) o ) -> u . ptr_val ; 
  else return ((void * ) 0 ) ; 
}
Scheme_Object * make_special_comment (int argc , Scheme_Object * * argv ) {
  Scheme_Object * o ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(argv, 1)));
# define XfOrM381_COUNT (2)
# define SETUP_XfOrM381(x) SETUP(XfOrM381_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  o = NULLED_OUT ; 
  o = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM381(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  o -> type = scheme_special_comment_type ; 
  (((Scheme_Small_Object * ) (o ) ) -> u . ptr_val ) = argv [0 ] ; 
  RET_VALUE_START (o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * special_comment_value (int argc , Scheme_Object * * argv ) {
  Scheme_Object * v ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(argv, 1)));
# define XfOrM382_COUNT (2)
# define SETUP_XfOrM382(x) SETUP(XfOrM382_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  v = FUNCCALL(SETUP_XfOrM382(_), scheme_special_comment_value (argv [0 ] ) ); 
  if (! v )
    FUNCCALL_EMPTY(scheme_wrong_type ("special-comment-value" , "special comment" , 0 , argc , argv ) ); 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * special_comment_p (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_special_comment_type ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * exn_source_p (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return (scheme_struct_type_property_ref (scheme_source_property , argv [0 ] ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * exn_source_get (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  Scheme_Object * v ; 
  v = scheme_struct_type_property_ref (scheme_source_property , argv [0 ] ) ; 
  if (! v )
    scheme_wrong_type ("exn:srclocs-accessor" , "exn:srclocs" , 0 , argc , argv ) ; 
  return v ; 
}
static Scheme_Object * check_exn_source_property_value_ok (int argc , Scheme_Object * argv [] ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM386_COUNT (1)
# define SETUP_XfOrM386(x) SETUP(XfOrM386_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM386(_), scheme_check_proc_arity ("guard-for-prop:exn:srclocs" , 1 , 0 , argc , argv ) ); 
  RET_VALUE_START (argv [0 ] ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int mark_struct_val_SIZE (void * p ) {
  Scheme_Structure * s = (Scheme_Structure * ) p ; 
  int num_slots = ((Scheme_Struct_Type * ) GC_resolve (s -> stype ) ) -> num_slots ; 
  return (((sizeof (Scheme_Structure ) + ((num_slots - 1 ) * sizeof (Scheme_Object * ) ) ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_struct_val_MARK (void * p ) {
  Scheme_Structure * s = (Scheme_Structure * ) p ; 
  int num_slots = ((Scheme_Struct_Type * ) GC_resolve (s -> stype ) ) -> num_slots ; 
  int i ; 
  GC_mark (s -> stype ) ; 
  for (i = num_slots ; i -- ; ) GC_mark (s -> slots [i ] ) ; 
  return (((sizeof (Scheme_Structure ) + ((num_slots - 1 ) * sizeof (Scheme_Object * ) ) ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_struct_val_FIXUP (void * p ) {
  Scheme_Structure * s = (Scheme_Structure * ) p ; 
  int num_slots = ((Scheme_Struct_Type * ) GC_resolve (s -> stype ) ) -> num_slots ; 
  int i ; 
  GC_fixup (& (s -> stype ) ) ; 
  for (i = num_slots ; i -- ; ) GC_fixup (& (s -> slots [i ] ) ) ; 
  return (((sizeof (Scheme_Structure ) + ((num_slots - 1 ) * sizeof (Scheme_Object * ) ) ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_struct_type_val_SIZE (void * p ) {
  Scheme_Struct_Type * t = (Scheme_Struct_Type * ) p ; 
  return (((sizeof (Scheme_Struct_Type ) + (t -> name_pos * sizeof (Scheme_Struct_Type * ) ) ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_struct_type_val_MARK (void * p ) {
  Scheme_Struct_Type * t = (Scheme_Struct_Type * ) p ; 
  int i ; 
  for (i = t -> name_pos + 1 ; i -- ; ) {
    GC_mark (t -> parent_types [i ] ) ; 
  }
  GC_mark (t -> name ) ; 
  GC_mark (t -> inspector ) ; 
  GC_mark (t -> accessor ) ; 
  GC_mark (t -> mutator ) ; 
  GC_mark (t -> uninit_val ) ; 
  GC_mark (t -> props ) ; 
  GC_mark (t -> proc_attr ) ; 
  GC_mark (t -> guard ) ; 
  GC_mark (t -> immutables ) ; 
  return (((sizeof (Scheme_Struct_Type ) + (t -> name_pos * sizeof (Scheme_Struct_Type * ) ) ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_struct_type_val_FIXUP (void * p ) {
  Scheme_Struct_Type * t = (Scheme_Struct_Type * ) p ; 
  int i ; 
  for (i = t -> name_pos + 1 ; i -- ; ) {
    GC_fixup (& (t -> parent_types [i ] ) ) ; 
  }
  GC_fixup (& (t -> name ) ) ; 
  GC_fixup (& (t -> inspector ) ) ; 
  GC_fixup (& (t -> accessor ) ) ; 
  GC_fixup (& (t -> mutator ) ) ; 
  GC_fixup (& (t -> uninit_val ) ) ; 
  GC_fixup (& (t -> props ) ) ; 
  GC_fixup (& (t -> proc_attr ) ) ; 
  GC_fixup (& (t -> guard ) ) ; 
  GC_fixup (& (t -> immutables ) ) ; 
  return (((sizeof (Scheme_Struct_Type ) + (t -> name_pos * sizeof (Scheme_Struct_Type * ) ) ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_struct_proc_info_SIZE (void * p ) {
  return ((sizeof (Struct_Proc_Info ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_struct_proc_info_MARK (void * p ) {
  Struct_Proc_Info * i = (Struct_Proc_Info * ) p ; 
  GC_mark (i -> struct_type ) ; 
  GC_mark (i -> func_name ) ; 
  return ((sizeof (Struct_Proc_Info ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_struct_proc_info_FIXUP (void * p ) {
  Struct_Proc_Info * i = (Struct_Proc_Info * ) p ; 
  GC_fixup (& (i -> struct_type ) ) ; 
  GC_fixup (& (i -> func_name ) ) ; 
  return ((sizeof (Struct_Proc_Info ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_struct_property_SIZE (void * p ) {
  return ((sizeof (Scheme_Struct_Property ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_struct_property_MARK (void * p ) {
  Scheme_Struct_Property * i = (Scheme_Struct_Property * ) p ; 
  GC_mark (i -> name ) ; 
  GC_mark (i -> guard ) ; 
  return ((sizeof (Scheme_Struct_Property ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_struct_property_FIXUP (void * p ) {
  Scheme_Struct_Property * i = (Scheme_Struct_Property * ) p ; 
  GC_fixup (& (i -> name ) ) ; 
  GC_fixup (& (i -> guard ) ) ; 
  return ((sizeof (Scheme_Struct_Property ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_wrapped_evt_SIZE (void * p ) {
  return ((sizeof (Wrapped_Evt ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_wrapped_evt_MARK (void * p ) {
  Wrapped_Evt * ww = (Wrapped_Evt * ) p ; 
  GC_mark (ww -> evt ) ; 
  GC_mark (ww -> wrapper ) ; 
  return ((sizeof (Wrapped_Evt ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_wrapped_evt_FIXUP (void * p ) {
  Wrapped_Evt * ww = (Wrapped_Evt * ) p ; 
  GC_fixup (& (ww -> evt ) ) ; 
  GC_fixup (& (ww -> wrapper ) ) ; 
  return ((sizeof (Wrapped_Evt ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_nack_guard_evt_SIZE (void * p ) {
  return ((sizeof (Nack_Guard_Evt ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_nack_guard_evt_MARK (void * p ) {
  Nack_Guard_Evt * nw = (Nack_Guard_Evt * ) p ; 
  GC_mark (nw -> maker ) ; 
  return ((sizeof (Nack_Guard_Evt ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_nack_guard_evt_FIXUP (void * p ) {
  Nack_Guard_Evt * nw = (Nack_Guard_Evt * ) p ; 
  GC_fixup (& (nw -> maker ) ) ; 
  return ((sizeof (Nack_Guard_Evt ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static void register_traversers (void ) {
  GC_register_traversers (scheme_structure_type , mark_struct_val_SIZE , mark_struct_val_MARK , mark_struct_val_FIXUP , 0 , 0 ) ; 
  GC_register_traversers (scheme_proc_struct_type , mark_struct_val_SIZE , mark_struct_val_MARK , mark_struct_val_FIXUP , 0 , 0 ) ; 
  GC_register_traversers (scheme_struct_type_type , mark_struct_type_val_SIZE , mark_struct_type_val_MARK , mark_struct_type_val_FIXUP , 0 , 0 ) ; 
  GC_register_traversers (scheme_struct_property_type , mark_struct_property_SIZE , mark_struct_property_MARK , mark_struct_property_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_wrap_evt_type , mark_wrapped_evt_SIZE , mark_wrapped_evt_MARK , mark_wrapped_evt_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_handle_evt_type , mark_wrapped_evt_SIZE , mark_wrapped_evt_MARK , mark_wrapped_evt_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_nack_guard_evt_type , mark_nack_guard_evt_SIZE , mark_nack_guard_evt_MARK , mark_nack_guard_evt_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_poll_evt_type , mark_nack_guard_evt_SIZE , mark_nack_guard_evt_MARK , mark_nack_guard_evt_FIXUP , 1 , 0 ) ; 
  GC_register_traversers (scheme_rt_struct_proc_info , mark_struct_proc_info_SIZE , mark_struct_proc_info_MARK , mark_struct_proc_info_FIXUP , 1 , 0 ) ; 
}
