#include "precomp.h"
Scheme_Object * scheme_always_ready_evt ; 
Scheme_Object * scheme_system_idle_channel ; 
static Scheme_Object * make_sema (int n , Scheme_Object * * p ) ; 
static Scheme_Object * semap (int n , Scheme_Object * * p ) ; 
static Scheme_Object * hit_sema (int n , Scheme_Object * * p ) ; 
static Scheme_Object * block_sema_p (int n , Scheme_Object * * p ) ; 
static Scheme_Object * block_sema (int n , Scheme_Object * * p ) ; 
static Scheme_Object * block_sema_breakable (int n , Scheme_Object * * p ) ; 
static Scheme_Object * make_sema_repost (int n , Scheme_Object * * p ) ; 
static Scheme_Object * make_channel (int n , Scheme_Object * * p ) ; 
static Scheme_Object * make_channel_put (int n , Scheme_Object * * p ) ; 
static Scheme_Object * channel_p (int n , Scheme_Object * * p ) ; 
static Scheme_Object * make_alarm (int n , Scheme_Object * * p ) ; 
static Scheme_Object * make_sys_idle (int n , Scheme_Object * * p ) ; 
static int channel_get_ready (Scheme_Object * ch , Scheme_Schedule_Info * sinfo ) ; 
static int channel_put_ready (Scheme_Object * ch , Scheme_Schedule_Info * sinfo ) ; 
static int channel_syncer_ready (Scheme_Object * ch , Scheme_Schedule_Info * sinfo ) ; 
static int alarm_ready (Scheme_Object * ch , Scheme_Schedule_Info * sinfo ) ; 
static int always_ready (Scheme_Object * w ) ; 
static int never_ready (Scheme_Object * w ) ; 
static int pending_break (Scheme_Thread * p ) ; 
int scheme_main_was_once_suspended ; 
static Scheme_Object * system_idle_put_evt ; 
static void register_traversers (void ) ; 
typedef struct {
  Scheme_Object so ; 
  double sleep_end ; 
}
Scheme_Alarm ; 
static int sema_ready (Scheme_Object * s ) {
  /* No conversion */
  return scheme_wait_sema (s , 1 ) ; 
}
static Scheme_Object * sema_for_repost (Scheme_Object * s , int * repost ) {
  /* No conversion */
  * repost = 1 ; 
  return (((Scheme_Small_Object * ) (s ) ) -> u . ptr_val ) ; 
}
void scheme_init_sema (Scheme_Env * env ) {
  Scheme_Object * o ; 
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
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(env, 0), PUSH(o, 1)));
# define XfOrM3_COUNT (2)
# define SETUP_XfOrM3(x) SETUP(XfOrM3_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  o = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM3(_), register_traversers () ); 
  (__funcarg16 = FUNCCALL(SETUP_XfOrM3(_), scheme_make_prim_w_arity (make_sema , "make-semaphore" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-semaphore" , __funcarg16 , env ) )) ; 
  (__funcarg15 = FUNCCALL(SETUP_XfOrM3(_), scheme_make_folding_prim (semap , "semaphore?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("semaphore?" , __funcarg15 , env ) )) ; 
  (__funcarg14 = FUNCCALL(SETUP_XfOrM3(_), scheme_make_prim_w_arity (hit_sema , "semaphore-post" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("semaphore-post" , __funcarg14 , env ) )) ; 
  (__funcarg13 = FUNCCALL(SETUP_XfOrM3(_), scheme_make_prim_w_arity (block_sema_p , "semaphore-try-wait?" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("semaphore-try-wait?" , __funcarg13 , env ) )) ; 
  (__funcarg12 = FUNCCALL(SETUP_XfOrM3(_), scheme_make_prim_w_arity (block_sema , "semaphore-wait" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("semaphore-wait" , __funcarg12 , env ) )) ; 
  (__funcarg11 = FUNCCALL(SETUP_XfOrM3(_), scheme_make_prim_w_arity (block_sema_breakable , "semaphore-wait/enable-break" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("semaphore-wait/enable-break" , __funcarg11 , env ) )) ; 
  (__funcarg10 = FUNCCALL(SETUP_XfOrM3(_), scheme_make_prim_w_arity (make_sema_repost , "semaphore-peek-evt" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("semaphore-peek-evt" , __funcarg10 , env ) )) ; 
  (__funcarg9 = FUNCCALL(SETUP_XfOrM3(_), scheme_make_prim_w_arity (make_channel , "make-channel" , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("make-channel" , __funcarg9 , env ) )) ; 
  (__funcarg8 = FUNCCALL(SETUP_XfOrM3(_), scheme_make_prim_w_arity (make_channel_put , "channel-put-evt" , 2 , 2 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("channel-put-evt" , __funcarg8 , env ) )) ; 
  (__funcarg7 = FUNCCALL(SETUP_XfOrM3(_), scheme_make_folding_prim (channel_p , "channel?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("channel?" , __funcarg7 , env ) )) ; 
  (__funcarg6 = FUNCCALL(SETUP_XfOrM3(_), scheme_make_prim_w_arity (make_alarm , "alarm-evt" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("alarm-evt" , __funcarg6 , env ) )) ; 
  (__funcarg5 = FUNCCALL(SETUP_XfOrM3(_), scheme_make_prim_w_arity (make_sys_idle , "system-idle-evt" , 0 , 0 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("system-idle-evt" , __funcarg5 , env ) )) ; 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & scheme_always_ready_evt , sizeof (scheme_always_ready_evt ) ) ); 
  scheme_always_ready_evt = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM3(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  scheme_always_ready_evt -> type = scheme_always_evt_type ; 
  FUNCCALL(SETUP_XfOrM3(_), scheme_add_global_constant ("always-evt" , scheme_always_ready_evt , env ) ); 
  o = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM3(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  o -> type = scheme_never_evt_type ; 
  FUNCCALL_EMPTY(scheme_add_global_constant ("never-evt" , o , env ) ); 
  FUNCCALL_EMPTY(scheme_register_static ((void * ) & scheme_system_idle_channel , sizeof (scheme_system_idle_channel ) ) ); 
  scheme_system_idle_channel = FUNCCALL_EMPTY(scheme_make_channel () ); 
  FUNCCALL_EMPTY(scheme_add_evt (scheme_sema_type , sema_ready , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ); 
  FUNCCALL_EMPTY(scheme_add_evt_through_sema (scheme_semaphore_repost_type , sema_for_repost , ((void * ) 0 ) ) ); 
  FUNCCALL_EMPTY(scheme_add_evt (scheme_channel_type , (Scheme_Ready_Fun ) channel_get_ready , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ); 
  FUNCCALL_EMPTY(scheme_add_evt (scheme_channel_put_type , (Scheme_Ready_Fun ) channel_put_ready , ((void * ) 0 ) , ((void * ) 0 ) , 1 ) ); 
  FUNCCALL_EMPTY(scheme_add_evt (scheme_channel_syncer_type , (Scheme_Ready_Fun ) channel_syncer_ready , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ); 
  FUNCCALL_EMPTY(scheme_add_evt (scheme_alarm_type , (Scheme_Ready_Fun ) alarm_ready , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ); 
  FUNCCALL_EMPTY(scheme_add_evt (scheme_always_evt_type , always_ready , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ); 
  FUNCCALL_EMPTY(scheme_add_evt (scheme_never_evt_type , never_ready , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_sema (long v ) {
  Scheme_Sema * sema ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(sema, 0)));
# define XfOrM4_COUNT (1)
# define SETUP_XfOrM4(x) SETUP(XfOrM4_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sema = NULLED_OUT ; 
  sema = ((Scheme_Sema * ) FUNCCALL(SETUP_XfOrM4(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Sema ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  sema -> value = v ; 
  sema -> so . type = scheme_sema_type ; 
  RET_VALUE_START ((Scheme_Object * ) sema ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_sema (int n , Scheme_Object * * p ) {
  long v ; 
  char * __funcarg17 = NULLED_OUT ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(p, 0)));
# define XfOrM5_COUNT (1)
# define SETUP_XfOrM5(x) SETUP(XfOrM5_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (n ) {
#   define XfOrM6_COUNT (0+XfOrM5_COUNT)
#   define SETUP_XfOrM6(x) SETUP_XfOrM5(x)
    if (! (((long ) (p [0 ] ) ) & 0x1 ) ) {
#     define XfOrM8_COUNT (0+XfOrM6_COUNT)
#     define SETUP_XfOrM8(x) SETUP_XfOrM6(x)
      if (! ((Scheme_Type ) (((((long ) (p [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_bignum_type ) ) || ! ((& ((Scheme_Bignum * ) p [0 ] ) -> iso ) -> so . keyex & 0x1 ) )
        FUNCCALL_EMPTY(scheme_wrong_type ("make-semaphore" , "non-negative exact integer" , 0 , n , p ) ); 
    }
    if (! (scheme_get_int_val (p [0 ] , & v ) ) ) {
#     define XfOrM7_COUNT (0+XfOrM6_COUNT)
#     define SETUP_XfOrM7(x) SETUP_XfOrM6(x)
      (__funcarg17 = FUNCCALL(SETUP_XfOrM7(_), scheme_make_provided_string (p [0 ] , 0 , ((void * ) 0 ) ) ), FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL , "make-semaphore: starting value %s is too large" , __funcarg17 ) )) ; 
    }
    else if (v < 0 )
      FUNCCALL_EMPTY(scheme_wrong_type ("make-semaphore" , "non-negative exact integer" , 0 , n , p ) ); 
  }
  else v = 0 ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sema (v ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_sema_repost (int n , Scheme_Object * * p ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (p [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_sema_type ) ) )
    scheme_wrong_type ("semaphore-peek-evt" , "semaphore" , 0 , n , p ) ; 
  return scheme_make_sema_repost (p [0 ] ) ; 
}
Scheme_Object * scheme_make_sema_repost (Scheme_Object * sema ) {
  Scheme_Object * o ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(sema, 1)));
# define XfOrM10_COUNT (2)
# define SETUP_XfOrM10(x) SETUP(XfOrM10_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  o = NULLED_OUT ; 
  o = ((Scheme_Object * ) FUNCCALL(SETUP_XfOrM10(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Small_Object ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  o -> type = scheme_semaphore_repost_type ; 
  (((Scheme_Small_Object * ) (o ) ) -> u . ptr_val ) = sema ; 
  RET_VALUE_START (o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * semap (int n , Scheme_Object * * p ) {
  /* No conversion */
  return ((Scheme_Type ) (((((long ) (p [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_sema_type ) ) ? scheme_true : scheme_false ; 
}
void scheme_post_sema (Scheme_Object * o ) {
  Scheme_Sema * t = (Scheme_Sema * ) o ; 
  int v , consumed ; 
  PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(t, 0)));
# define XfOrM12_COUNT (1)
# define SETUP_XfOrM12(x) SETUP(XfOrM12_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (t -> value < 0 )
    RET_NOTHING ; 
  v = t -> value + 1 ; 
  if (v > t -> value ) {
#   define XfOrM13_COUNT (0+XfOrM12_COUNT)
#   define SETUP_XfOrM13(x) SETUP_XfOrM12(x)
    t -> value = v ; 
    while (t -> first ) {
      Scheme_Channel_Syncer * w ; 
      BLOCK_SETUP((PUSH(w, 0+XfOrM13_COUNT)));
#     define XfOrM20_COUNT (1+XfOrM13_COUNT)
#     define SETUP_XfOrM20(x) SETUP(XfOrM20_COUNT)
      w = NULLED_OUT ; 
      w = t -> first ; 
      t -> first = w -> next ; 
      if (! w -> next )
        t -> last = ((void * ) 0 ) ; 
      else t -> first -> prev = ((void * ) 0 ) ; 
      if ((! w -> syncing || ! w -> syncing -> result ) && ! FUNCCALL(SETUP_XfOrM20(_), pending_break (w -> p ) )) {
#       define XfOrM22_COUNT (0+XfOrM20_COUNT)
#       define SETUP_XfOrM22(x) SETUP_XfOrM20(x)
        if (w -> syncing ) {
#         define XfOrM24_COUNT (0+XfOrM22_COUNT)
#         define SETUP_XfOrM24(x) SETUP_XfOrM22(x)
          w -> syncing -> result = w -> syncing_i + 1 ; 
          if (w -> syncing -> disable_break )
            w -> syncing -> disable_break -> suspend_break ++ ; 
          FUNCCALL(SETUP_XfOrM24(_), scheme_post_syncing_nacks (w -> syncing ) ); 
          if (! w -> syncing -> reposts || ! w -> syncing -> reposts [w -> syncing_i ] ) {
            t -> value -= 1 ; 
            consumed = 1 ; 
          }
          else consumed = 0 ; 
        }
        else {
          consumed = 1 ; 
        }
        w -> picked = 1 ; 
      }
      else consumed = 0 ; 
      w -> in_line = 0 ; 
      w -> prev = ((void * ) 0 ) ; 
      w -> next = ((void * ) 0 ) ; 
      if (w -> picked ) {
#       define XfOrM21_COUNT (0+XfOrM20_COUNT)
#       define SETUP_XfOrM21(x) SETUP_XfOrM20(x)
        FUNCCALL(SETUP_XfOrM21(_), scheme_weak_resume_thread (w -> p ) ); 
        if (consumed )
          break ; 
      }
    }
    RET_NOTHING ; 
  }
  FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL , "semaphore-post: the maximum post count has already been reached" ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_post_sema_all (Scheme_Object * o ) {
  Scheme_Sema * t = (Scheme_Sema * ) o ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(t, 0), PUSH(o, 1)));
# define XfOrM26_COUNT (2)
# define SETUP_XfOrM26(x) SETUP(XfOrM26_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  while (t -> first ) {
#   define XfOrM28_COUNT (0+XfOrM26_COUNT)
#   define SETUP_XfOrM28(x) SETUP_XfOrM26(x)
    FUNCCALL(SETUP_XfOrM28(_), scheme_post_sema (o ) ); 
  }
  t -> value = - 1 ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * hit_sema (int n , Scheme_Object * * p ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (p [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_sema_type ) ) )
    scheme_wrong_type ("semaphore-post" , "semaphore" , 0 , n , p ) ; 
  scheme_post_sema (p [0 ] ) ; 
  return scheme_void ; 
}
static int out_of_line (Scheme_Object * a ) {
  Scheme_Thread * p ; 
  int n , i ; 
  Scheme_Channel_Syncer * w ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(p, 0)));
# define XfOrM30_COUNT (1)
# define SETUP_XfOrM30(x) SETUP(XfOrM30_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  p = NULLED_OUT ; 
  w = NULLED_OUT ; 
  n = (((long ) (((Scheme_Object * * ) a ) [0 ] ) ) >> 1 ) ; 
  for (i = 0 ; i < n ; i ++ ) {
    w = (((Scheme_Channel_Syncer * * * ) a ) [1 ] ) [i ] ; 
    if (w -> picked )
      RET_VALUE_START (1 ) RET_VALUE_END ; 
  }
  p = ((Scheme_Thread * * ) a ) [2 ] ; 
  if (p -> external_break ) {
    int v ; 
#   define XfOrM31_COUNT (0+XfOrM30_COUNT)
#   define SETUP_XfOrM31(x) SETUP_XfOrM30(x)
    -- p -> suspend_break ; 
    v = FUNCCALL(SETUP_XfOrM31(_), scheme_can_break (p ) ); 
    p -> suspend_break ++ ; 
    if (v )
      RET_VALUE_START (1 ) RET_VALUE_END ; 
  }
  if ((p -> running & 0x10 ) || scheme_main_was_once_suspended )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void get_into_line (Scheme_Sema * sema , Scheme_Channel_Syncer * w ) {
  /* No conversion */
  Scheme_Channel_Syncer * last , * first ; 
  w -> in_line = 1 ; 
  w -> picked = 0 ; 
  if (((Scheme_Type ) (((((long ) (sema ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (sema ) ) -> type ) ) == (Scheme_Type ) (scheme_never_evt_type ) ) ) {
    return ; 
  }
  else if (((Scheme_Type ) (((((long ) (sema ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (sema ) ) -> type ) ) == (Scheme_Type ) (scheme_sema_type ) ) ) {
    last = sema -> last ; 
    first = sema -> first ; 
  }
  else if (((Scheme_Type ) (((((long ) (sema ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (sema ) ) -> type ) ) == (Scheme_Type ) (scheme_channel_type ) ) ) {
    last = ((Scheme_Channel * ) sema ) -> get_last ; 
    first = ((Scheme_Channel * ) sema ) -> get_first ; 
  }
  else {
    last = ((Scheme_Channel_Put * ) sema ) -> ch -> put_last ; 
    first = ((Scheme_Channel_Put * ) sema ) -> ch -> put_first ; 
  }
  w -> prev = last ; 
  if (last )
    last -> next = w ; 
  else first = w ; 
  last = w ; 
  w -> next = ((void * ) 0 ) ; 
  if (((Scheme_Type ) (((((long ) (sema ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (sema ) ) -> type ) ) == (Scheme_Type ) (scheme_sema_type ) ) ) {
    sema -> last = last ; 
    sema -> first = first ; 
  }
  else if (((Scheme_Type ) (((((long ) (sema ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (sema ) ) -> type ) ) == (Scheme_Type ) (scheme_channel_type ) ) ) {
    ((Scheme_Channel * ) sema ) -> get_last = last ; 
    ((Scheme_Channel * ) sema ) -> get_first = first ; 
  }
  else {
    ((Scheme_Channel_Put * ) sema ) -> ch -> put_last = last ; 
    ((Scheme_Channel_Put * ) sema ) -> ch -> put_first = first ; 
  }
}
static void get_outof_line (Scheme_Sema * sema , Scheme_Channel_Syncer * w ) {
  /* No conversion */
  Scheme_Channel_Syncer * last , * first ; 
  w -> in_line = 0 ; 
  if (((Scheme_Type ) (((((long ) (sema ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (sema ) ) -> type ) ) == (Scheme_Type ) (scheme_never_evt_type ) ) ) {
    return ; 
  }
  else if (((Scheme_Type ) (((((long ) (sema ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (sema ) ) -> type ) ) == (Scheme_Type ) (scheme_sema_type ) ) ) {
    last = sema -> last ; 
    first = sema -> first ; 
  }
  else if (((Scheme_Type ) (((((long ) (sema ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (sema ) ) -> type ) ) == (Scheme_Type ) (scheme_channel_type ) ) ) {
    last = ((Scheme_Channel * ) sema ) -> get_last ; 
    first = ((Scheme_Channel * ) sema ) -> get_first ; 
  }
  else {
    last = ((Scheme_Channel_Put * ) sema ) -> ch -> put_last ; 
    first = ((Scheme_Channel_Put * ) sema ) -> ch -> put_first ; 
  }
  if (w -> prev )
    w -> prev -> next = w -> next ; 
  else first = w -> next ; 
  if (w -> next )
    w -> next -> prev = w -> prev ; 
  else last = w -> prev ; 
  if (((Scheme_Type ) (((((long ) (sema ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (sema ) ) -> type ) ) == (Scheme_Type ) (scheme_sema_type ) ) ) {
    sema -> last = last ; 
    sema -> first = first ; 
  }
  else if (((Scheme_Type ) (((((long ) (sema ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (sema ) ) -> type ) ) == (Scheme_Type ) (scheme_channel_type ) ) ) {
    ((Scheme_Channel * ) sema ) -> get_last = last ; 
    ((Scheme_Channel * ) sema ) -> get_first = first ; 
  }
  else {
    ((Scheme_Channel_Put * ) sema ) -> ch -> put_last = last ; 
    ((Scheme_Channel_Put * ) sema ) -> ch -> put_first = first ; 
  }
}
static void ext_get_into_line (Scheme_Object * ch , Scheme_Schedule_Info * sinfo ) {
  Scheme_Channel_Syncer * w ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(sinfo, 0), PUSH(w, 1), PUSH(ch, 2)));
# define XfOrM50_COUNT (3)
# define SETUP_XfOrM50(x) SETUP(XfOrM50_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  w = NULLED_OUT ; 
  w = ((Scheme_Channel_Syncer * ) FUNCCALL(SETUP_XfOrM50(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Channel_Syncer ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  w -> so . type = scheme_channel_syncer_type ; 
  if (sinfo -> false_positive_ok )
    w -> p = sinfo -> false_positive_ok ; 
  else w -> p = scheme_current_thread ; 
  w -> syncing = (Syncing * ) sinfo -> current_syncing ; 
  w -> obj = ch ; 
  w -> syncing_i = sinfo -> w_i ; 
  FUNCCALL(SETUP_XfOrM50(_), get_into_line ((Scheme_Sema * ) ch , w ) ); 
  FUNCCALL_EMPTY(scheme_set_sync_target (sinfo , (Scheme_Object * ) w , ((void * ) 0 ) , ((void * ) 0 ) , 0 , 0 ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_get_outof_line (Scheme_Channel_Syncer * ch_w ) {
  /* No conversion */
  get_outof_line ((Scheme_Sema * ) ch_w -> obj , ch_w ) ; 
}
static int try_channel (Scheme_Sema * sema , Syncing * syncing , int pos , Scheme_Object * * result ) {
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(syncing, 0), PUSH(result, 1), PUSH(sema, 2)));
# define XfOrM52_COUNT (3)
# define SETUP_XfOrM52(x) SETUP(XfOrM52_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (((Scheme_Type ) (((((long ) (sema ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (sema ) ) -> type ) ) == (Scheme_Type ) (scheme_channel_type ) ) ) {
    Scheme_Channel * ch = (Scheme_Channel * ) sema ; 
    Scheme_Channel_Syncer * w = ch -> put_first , * next ; 
    int picked = 0 ; 
    BLOCK_SETUP((PUSH(next, 0+XfOrM52_COUNT), PUSH(w, 1+XfOrM52_COUNT)));
#   define XfOrM64_COUNT (2+XfOrM52_COUNT)
#   define SETUP_XfOrM64(x) SETUP(XfOrM64_COUNT)
    next = NULLED_OUT ; 
    while (w ) {
#     define XfOrM70_COUNT (0+XfOrM64_COUNT)
#     define SETUP_XfOrM70(x) SETUP_XfOrM64(x)
      if (w -> syncing == syncing ) {
        w = w -> next ; 
      }
      else {
        Scheme_Channel_Put * chp = (Scheme_Channel_Put * ) w -> obj ; 
        BLOCK_SETUP((PUSH(chp, 0+XfOrM70_COUNT)));
#       define XfOrM71_COUNT (1+XfOrM70_COUNT)
#       define SETUP_XfOrM71(x) SETUP(XfOrM71_COUNT)
        if (! w -> syncing -> result && ! FUNCCALL(SETUP_XfOrM71(_), pending_break (w -> p ) )) {
#         define XfOrM72_COUNT (0+XfOrM71_COUNT)
#         define SETUP_XfOrM72(x) SETUP_XfOrM71(x)
          w -> picked = 1 ; 
          w -> syncing -> result = w -> syncing_i + 1 ; 
          if (w -> syncing -> disable_break )
            w -> syncing -> disable_break -> suspend_break ++ ; 
          FUNCCALL(SETUP_XfOrM72(_), scheme_post_syncing_nacks (w -> syncing ) ); 
          if (result )
            * result = chp -> val ; 
          if (syncing && (pos >= 0 ) ) {
#           define XfOrM73_COUNT (0+XfOrM72_COUNT)
#           define SETUP_XfOrM73(x) SETUP_XfOrM72(x)
            syncing -> result = pos + 1 ; 
            if (syncing -> disable_break )
              syncing -> disable_break -> suspend_break ++ ; 
            FUNCCALL(SETUP_XfOrM73(_), scheme_post_syncing_nacks (syncing ) ); 
            syncing -> set -> argv [pos ] = chp -> val ; 
          }
          picked = 1 ; 
          FUNCCALL(SETUP_XfOrM72(_), scheme_weak_resume_thread (w -> p ) ); 
        }
        next = w -> next ; 
        FUNCCALL(SETUP_XfOrM71(_), get_outof_line ((Scheme_Sema * ) chp , w ) ); 
        w = next ; 
        if (picked )
          RET_VALUE_START (1 ) RET_VALUE_END ; 
      }
    }
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  else {
    Scheme_Channel_Put * chp = (Scheme_Channel_Put * ) sema ; 
    Scheme_Channel_Syncer * w = chp -> ch -> get_first , * next ; 
    int picked = 0 ; 
    BLOCK_SETUP((PUSH(next, 0+XfOrM52_COUNT), PUSH(w, 1+XfOrM52_COUNT), PUSH(chp, 2+XfOrM52_COUNT)));
#   define XfOrM53_COUNT (3+XfOrM52_COUNT)
#   define SETUP_XfOrM53(x) SETUP(XfOrM53_COUNT)
    next = NULLED_OUT ; 
    while (w ) {
#     define XfOrM59_COUNT (0+XfOrM53_COUNT)
#     define SETUP_XfOrM59(x) SETUP_XfOrM53(x)
      if (w -> syncing == syncing ) {
        w = w -> next ; 
      }
      else {
#       define XfOrM60_COUNT (0+XfOrM59_COUNT)
#       define SETUP_XfOrM60(x) SETUP_XfOrM59(x)
        if (! w -> syncing -> result && ! FUNCCALL(SETUP_XfOrM60(_), pending_break (w -> p ) )) {
#         define XfOrM61_COUNT (0+XfOrM60_COUNT)
#         define SETUP_XfOrM61(x) SETUP_XfOrM60(x)
          w -> picked = 1 ; 
          w -> syncing -> set -> argv [w -> syncing_i ] = chp -> val ; 
          w -> syncing -> result = w -> syncing_i + 1 ; 
          if (w -> syncing -> disable_break )
            w -> syncing -> disable_break -> suspend_break ++ ; 
          FUNCCALL(SETUP_XfOrM61(_), scheme_post_syncing_nacks (w -> syncing ) ); 
          if (syncing && (pos >= 0 ) ) {
#           define XfOrM62_COUNT (0+XfOrM61_COUNT)
#           define SETUP_XfOrM62(x) SETUP_XfOrM61(x)
            syncing -> result = pos + 1 ; 
            if (syncing -> disable_break )
              syncing -> disable_break -> suspend_break ++ ; 
            FUNCCALL(SETUP_XfOrM62(_), scheme_post_syncing_nacks (syncing ) ); 
          }
          picked = 1 ; 
          FUNCCALL(SETUP_XfOrM61(_), scheme_weak_resume_thread (w -> p ) ); 
        }
        next = w -> next ; 
        FUNCCALL(SETUP_XfOrM60(_), get_outof_line ((Scheme_Sema * ) chp -> ch , w ) ); 
        w = next ; 
        if (picked )
          RET_VALUE_START (1 ) RET_VALUE_END ; 
      }
    }
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_try_plain_sema (Scheme_Object * o ) {
  /* No conversion */
  Scheme_Sema * sema = (Scheme_Sema * ) o ; 
  if (sema -> value ) {
    if (sema -> value > 0 )
      -- sema -> value ; 
    return 1 ; 
  }
  else return 0 ; 
}
int scheme_wait_semas_chs (int n , Scheme_Object * * o , int just_try , Syncing * syncing ) {
  Scheme_Sema * * semas = (Scheme_Sema * * ) o ; 
  int v , i , ii ; 
  Scheme_Config * __funcarg18 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(syncing, 0), PUSH(semas, 1)));
# define XfOrM77_COUNT (2)
# define SETUP_XfOrM77(x) SETUP(XfOrM77_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (just_try ) {
    Scheme_Sema * sema = semas [0 ] ; 
    BLOCK_SETUP((PUSH(sema, 0+XfOrM77_COUNT)));
#   define XfOrM198_COUNT (1+XfOrM77_COUNT)
#   define SETUP_XfOrM198(x) SETUP(XfOrM198_COUNT)
    if (just_try > 0 ) {
#     define XfOrM200_COUNT (0+XfOrM198_COUNT)
#     define SETUP_XfOrM200(x) SETUP_XfOrM198(x)
      if (sema -> so . type == scheme_sema_type ) {
#       define XfOrM202_COUNT (0+XfOrM200_COUNT)
#       define SETUP_XfOrM202(x) SETUP_XfOrM200(x)
        v = (scheme_try_plain_sema ((Scheme_Object * ) sema ) ) ; 
      }
      else {
#       define XfOrM201_COUNT (0+XfOrM200_COUNT)
#       define SETUP_XfOrM201(x) SETUP_XfOrM200(x)
        v = FUNCCALL(SETUP_XfOrM201(_), try_channel (sema , syncing , 0 , ((void * ) 0 ) ) ); 
      }
    }
    else {
      Scheme_Cont_Frame_Data cframe ; 
      BLOCK_SETUP((PUSH(cframe.cache, 0+XfOrM198_COUNT)));
#     define XfOrM199_COUNT (1+XfOrM198_COUNT)
#     define SETUP_XfOrM199(x) SETUP(XfOrM199_COUNT)
      cframe.cache = NULLED_OUT ; 
      FUNCCALL(SETUP_XfOrM199(_), scheme_push_break_enable (& cframe , 1 , 1 ) ); 
      FUNCCALL_AGAIN(scheme_wait_sema ((Scheme_Object * ) sema , 0 ) ); 
      FUNCCALL_AGAIN(scheme_pop_break_enable (& cframe , 0 ) ); 
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
  }
  else {
    int start_pos ; 
#   define XfOrM78_COUNT (0+XfOrM77_COUNT)
#   define SETUP_XfOrM78(x) SETUP_XfOrM77(x)
    if (n > 1 ) {
#     define XfOrM196_COUNT (0+XfOrM78_COUNT)
#     define SETUP_XfOrM196(x) SETUP_XfOrM78(x)
      if (syncing )
        start_pos = syncing -> start_pos ; 
      else {
        Scheme_Object * rand_state ; 
        BLOCK_SETUP((PUSH(rand_state, 0+XfOrM196_COUNT)));
#       define XfOrM197_COUNT (1+XfOrM196_COUNT)
#       define SETUP_XfOrM197(x) SETUP(XfOrM197_COUNT)
        rand_state = NULLED_OUT ; 
        rand_state = (__funcarg18 = FUNCCALL(SETUP_XfOrM197(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg18 , MZCONFIG_SCHEDULER_RANDOM_STATE ) )) ; 
        start_pos = FUNCCALL_AGAIN(scheme_rand ((Scheme_Random_State * ) rand_state ) ); 
      }
    }
    else start_pos = 0 ; 
    i = 0 ; 
    for (ii = 0 ; ii < n ; ii ++ ) {
#     define XfOrM191_COUNT (0+XfOrM78_COUNT)
#     define SETUP_XfOrM191(x) SETUP_XfOrM78(x)
      i = (start_pos + ii ) % n ; 
      if (semas [i ] -> so . type == scheme_sema_type ) {
        if (semas [i ] -> value ) {
          if ((semas [i ] -> value > 0 ) && (! syncing || ! syncing -> reposts || ! syncing -> reposts [i ] ) )
            -- semas [i ] -> value ; 
          break ; 
        }
      }
      else if (semas [i ] -> so . type == scheme_never_evt_type ) {
      }
      else if (semas [i ] -> so . type == scheme_channel_syncer_type ) {
      }
      else if (FUNCCALL(SETUP_XfOrM191(_), try_channel (semas [i ] , syncing , i , ((void * ) 0 ) ) ))
        break ; 
    }
    if (ii >= n ) {
      Scheme_Channel_Syncer * * ws , * w ; 
      BLOCK_SETUP((PUSH(ws, 0+XfOrM78_COUNT), PUSH(w, 1+XfOrM78_COUNT)));
#     define XfOrM79_COUNT (2+XfOrM78_COUNT)
#     define SETUP_XfOrM79(x) SETUP(XfOrM79_COUNT)
      ws = NULLED_OUT ; 
      w = NULLED_OUT ; 
      ws = ((Scheme_Channel_Syncer * * ) FUNCCALL(SETUP_XfOrM79(_), GC_malloc (sizeof (Scheme_Channel_Syncer * ) * (n ) ) )) ; 
      for (i = 0 ; i < n ; i ++ ) {
#       define XfOrM183_COUNT (0+XfOrM79_COUNT)
#       define SETUP_XfOrM183(x) SETUP_XfOrM79(x)
        if (semas [i ] -> so . type == scheme_channel_syncer_type ) {
          ws [i ] = (Scheme_Channel_Syncer * ) semas [i ] ; 
          semas [i ] = (Scheme_Sema * ) ws [i ] -> obj ; 
        }
        else {
#         define XfOrM184_COUNT (0+XfOrM183_COUNT)
#         define SETUP_XfOrM184(x) SETUP_XfOrM183(x)
          w = ((Scheme_Channel_Syncer * ) FUNCCALL(SETUP_XfOrM184(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Channel_Syncer ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
          ws [i ] = w ; 
          w -> so . type = scheme_channel_syncer_type ; 
          w -> p = scheme_current_thread ; 
          w -> syncing = syncing ; 
          w -> obj = (Scheme_Object * ) semas [i ] ; 
          w -> syncing_i = i ; 
        }
      }
      while (1 ) {
        int out_of_a_line ; 
#       define XfOrM130_COUNT (0+XfOrM79_COUNT)
#       define SETUP_XfOrM130(x) SETUP_XfOrM79(x)
        for (i = 0 ; i < n ; i ++ ) {
#         define XfOrM178_COUNT (0+XfOrM130_COUNT)
#         define SETUP_XfOrM178(x) SETUP_XfOrM130(x)
          if (! ws [i ] -> in_line ) {
#           define XfOrM179_COUNT (0+XfOrM178_COUNT)
#           define SETUP_XfOrM179(x) SETUP_XfOrM178(x)
            FUNCCALL(SETUP_XfOrM179(_), get_into_line (semas [i ] , ws [i ] ) ); 
          }
        }
        if (! scheme_current_thread -> next ) {
          void * * a ; 
          BLOCK_SETUP((PUSH(a, 0+XfOrM130_COUNT)));
#         define XfOrM175_COUNT (1+XfOrM130_COUNT)
#         define SETUP_XfOrM175(x) SETUP(XfOrM175_COUNT)
          a = NULLED_OUT ; 
          scheme_current_thread -> suspend_break ++ ; 
          a = ((void * * ) FUNCCALL(SETUP_XfOrM175(_), GC_malloc (sizeof (void * ) * (3 ) ) )) ; 
          a [0 ] = ((Scheme_Object * ) (void * ) (long ) ((((long ) (n ) ) << 1 ) | 0x1 ) ) ; 
          a [1 ] = ws ; 
          a [2 ] = scheme_current_thread ; 
          scheme_main_was_once_suspended = 0 ; 
          FUNCCALL(SETUP_XfOrM175(_), scheme_block_until (out_of_line , ((void * ) 0 ) , (Scheme_Object * ) a , (float ) 0.0 ) ); 
          -- scheme_current_thread -> suspend_break ; 
        }
        else {
          int old_nkc ; 
#         define XfOrM174_COUNT (0+XfOrM130_COUNT)
#         define SETUP_XfOrM174(x) SETUP_XfOrM130(x)
          old_nkc = (scheme_current_thread -> running & 0x8 ) ; 
          if (! old_nkc )
            scheme_current_thread -> running += 0x8 ; 
          FUNCCALL(SETUP_XfOrM174(_), scheme_weak_suspend_thread (scheme_current_thread ) ); 
          if (! old_nkc && (scheme_current_thread -> running & 0x8 ) )
            scheme_current_thread -> running -= 0x8 ; 
        }
        out_of_a_line = 0 ; 
        if (! syncing ) {
          i = 0 ; 
          for (ii = 0 ; ii < n ; ii ++ ) {
            i = (start_pos + ii ) % n ; 
            if (ws [i ] -> picked ) {
              out_of_a_line = 1 ; 
              if (semas [i ] -> value ) {
                if (semas [i ] -> value > 0 )
                  -- (semas [i ] -> value ) ; 
                break ; 
              }
            }
          }
          if (ii >= n )
            i = n ; 
        }
        else {
          if (syncing -> result ) {
            out_of_a_line = 1 ; 
            i = syncing -> result - 1 ; 
          }
          else {
            out_of_a_line = 0 ; 
            i = n ; 
          }
        }
        if (! out_of_a_line ) {
#         define XfOrM161_COUNT (0+XfOrM130_COUNT)
#         define SETUP_XfOrM161(x) SETUP_XfOrM130(x)
          for (i = 0 ; i < n ; i ++ ) {
#           define XfOrM163_COUNT (0+XfOrM161_COUNT)
#           define SETUP_XfOrM163(x) SETUP_XfOrM161(x)
            if (ws [i ] -> in_line )
              FUNCCALL(SETUP_XfOrM163(_), get_outof_line (semas [i ] , ws [i ] ) ); 
          }
          FUNCCALL(SETUP_XfOrM161(_), scheme_thread_block (0 ) ); 
          scheme_current_thread -> ran_some = 1 ; 
        }
        else {
#         define XfOrM146_COUNT (0+XfOrM130_COUNT)
#         define SETUP_XfOrM146(x) SETUP_XfOrM130(x)
          if ((scheme_current_thread -> running & 0x4 ) || ((scheme_current_thread -> running & 0x10 ) && ! (scheme_current_thread -> running & 0x20 ) ) ) {
            i = - 1 ; 
          }
          if (! syncing ) {
            int j ; 
#           define XfOrM151_COUNT (0+XfOrM146_COUNT)
#           define SETUP_XfOrM151(x) SETUP_XfOrM146(x)
            for (j = 0 ; j < n ; j ++ ) {
#             define XfOrM156_COUNT (0+XfOrM151_COUNT)
#             define SETUP_XfOrM156(x) SETUP_XfOrM151(x)
              if (j != i ) {
#               define XfOrM157_COUNT (0+XfOrM156_COUNT)
#               define SETUP_XfOrM157(x) SETUP_XfOrM156(x)
                if (ws [j ] -> picked ) {
#                 define XfOrM158_COUNT (0+XfOrM157_COUNT)
#                 define SETUP_XfOrM158(x) SETUP_XfOrM157(x)
                  if (semas [j ] -> value ) {
#                   define XfOrM159_COUNT (0+XfOrM158_COUNT)
#                   define SETUP_XfOrM159(x) SETUP_XfOrM158(x)
                    if (semas [j ] -> value > 0 )
                      -- semas [j ] -> value ; 
                    FUNCCALL(SETUP_XfOrM159(_), scheme_post_sema ((Scheme_Object * ) semas [j ] ) ); 
                  }
                }
              }
            }
          }
          if (i < n ) {
            int j ; 
#           define XfOrM148_COUNT (0+XfOrM146_COUNT)
#           define SETUP_XfOrM148(x) SETUP_XfOrM146(x)
            for (j = 0 ; j < n ; j ++ ) {
#             define XfOrM150_COUNT (0+XfOrM148_COUNT)
#             define SETUP_XfOrM150(x) SETUP_XfOrM148(x)
              if (ws [j ] -> in_line )
                FUNCCALL(SETUP_XfOrM150(_), get_outof_line (semas [j ] , ws [j ] ) ); 
            }
          }
          if (i == - 1 ) {
#           define XfOrM147_COUNT (0+XfOrM146_COUNT)
#           define SETUP_XfOrM147(x) SETUP_XfOrM146(x)
            FUNCCALL(SETUP_XfOrM147(_), scheme_thread_block (0 ) ); 
            scheme_current_thread -> ran_some = 1 ; 
          }
          if (i < n )
            break ; 
        }
        for (ii = 0 ; ii < n ; ii ++ ) {
#         define XfOrM142_COUNT (0+XfOrM130_COUNT)
#         define SETUP_XfOrM142(x) SETUP_XfOrM130(x)
          i = (start_pos + ii ) % n ; 
          if (semas [i ] -> so . type == scheme_sema_type ) {
            if (semas [i ] -> value ) {
              if ((semas [i ] -> value > 0 ) && (! syncing || ! syncing -> reposts || ! syncing -> reposts [i ] ) )
                -- semas [i ] -> value ; 
              break ; 
            }
          }
          else if (semas [i ] -> so . type == scheme_never_evt_type ) {
          }
          else if (FUNCCALL(SETUP_XfOrM142(_), try_channel (semas [i ] , syncing , i , ((void * ) 0 ) ) ))
            break ; 
        }
        if (ii < n ) {
          int j ; 
#         define XfOrM135_COUNT (0+XfOrM130_COUNT)
#         define SETUP_XfOrM135(x) SETUP_XfOrM130(x)
          for (j = 0 ; j < n ; j ++ ) {
#           define XfOrM137_COUNT (0+XfOrM135_COUNT)
#           define SETUP_XfOrM137(x) SETUP_XfOrM135(x)
            if (ws [j ] -> in_line )
              FUNCCALL(SETUP_XfOrM137(_), get_outof_line (semas [j ] , ws [j ] ) ); 
          }
          break ; 
        }
        if (! syncing ) {
#         define XfOrM131_COUNT (0+XfOrM130_COUNT)
#         define SETUP_XfOrM131(x) SETUP_XfOrM130(x)
          syncing = ((Syncing * ) FUNCCALL(SETUP_XfOrM131(_), GC_malloc_one_small_tagged ((((sizeof (Syncing ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
          syncing -> type = scheme_rt_syncing ; 
          syncing -> start_pos = start_pos ; 
          {
            int j ; 
#           define XfOrM132_COUNT (0+XfOrM131_COUNT)
#           define SETUP_XfOrM132(x) SETUP_XfOrM131(x)
            for (j = 0 ; j < n ; j ++ ) {
#             define XfOrM134_COUNT (0+XfOrM132_COUNT)
#             define SETUP_XfOrM134(x) SETUP_XfOrM132(x)
              if (ws [j ] -> in_line )
                FUNCCALL(SETUP_XfOrM134(_), get_outof_line (semas [j ] , ws [j ] ) ); 
              ws [j ] -> syncing = syncing ; 
            }
          }
        }
      }
    }
    v = i + 1 ; 
  }
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_wait_sema (Scheme_Object * o , int just_try ) {
  Scheme_Object * a [1 ] ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 1, 0)));
# define XfOrM203_COUNT (3)
# define SETUP_XfOrM203(x) SETUP(XfOrM203_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a [0 ] = o ; 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM203(_), scheme_wait_semas_chs (1 , a , just_try , ((void * ) 0 ) ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * block_sema_p (int n , Scheme_Object * * p ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (p [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_sema_type ) ) )
    scheme_wrong_type ("semaphore-try-wait?" , "sema" , 0 , n , p ) ; 
  return scheme_wait_sema (p [0 ] , 1 ) ? scheme_true : scheme_false ; 
}
static Scheme_Object * block_sema (int n , Scheme_Object * * p ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (p [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_sema_type ) ) )
    scheme_wrong_type ("semaphore-wait" , "sema" , 0 , n , p ) ; 
  scheme_wait_sema (p [0 ] , 0 ) ; 
  scheme_check_break_now () ; 
  return scheme_void ; 
}
static Scheme_Object * block_sema_breakable (int n , Scheme_Object * * p ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (p [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_sema_type ) ) )
    scheme_wrong_type ("semaphore-wait/enable-break" , "sema" , 0 , n , p ) ; 
  scheme_wait_sema (p [0 ] , - 1 ) ; 
  return scheme_void ; 
}
static int pending_break (Scheme_Thread * p ) {
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(p, 0)));
# define XfOrM207_COUNT (1)
# define SETUP_XfOrM207(x) SETUP(XfOrM207_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (p -> running & (0x4 | 0x10 ) )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  if (p -> external_break ) {
    int v ; 
#   define XfOrM208_COUNT (0+XfOrM207_COUNT)
#   define SETUP_XfOrM208(x) SETUP_XfOrM207(x)
    if (! p -> next ) {
      -- p -> suspend_break ; 
    }
    v = FUNCCALL(SETUP_XfOrM208(_), scheme_can_break (p ) ); 
    if (! p -> next )
      p -> suspend_break ++ ; 
    RET_VALUE_START (v ) RET_VALUE_END ; 
  }
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_channel () {
  Scheme_Channel * c ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(c, 0)));
# define XfOrM210_COUNT (1)
# define SETUP_XfOrM210(x) SETUP(XfOrM210_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  c = NULLED_OUT ; 
  c = ((Scheme_Channel * ) FUNCCALL(SETUP_XfOrM210(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Channel ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  c -> so . type = scheme_channel_type ; 
  RET_VALUE_START ((Scheme_Object * ) c ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_channel (int n , Scheme_Object * * p ) {
  /* No conversion */
  return scheme_make_channel () ; 
}
Scheme_Object * scheme_make_channel_put_evt (Scheme_Object * ch , Scheme_Object * v ) {
  Scheme_Channel_Put * cp ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(cp, 1), PUSH(ch, 2)));
# define XfOrM212_COUNT (3)
# define SETUP_XfOrM212(x) SETUP(XfOrM212_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  cp = NULLED_OUT ; 
  cp = ((Scheme_Channel_Put * ) FUNCCALL(SETUP_XfOrM212(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Channel_Put ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  cp -> so . type = scheme_channel_put_type ; 
  cp -> ch = (Scheme_Channel * ) ch ; 
  cp -> val = v ; 
  RET_VALUE_START ((Scheme_Object * ) cp ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_channel_put (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_channel_type ) ) )
    scheme_wrong_type ("channel-put-evt" , "channel" , 0 , argc , argv ) ; 
  return scheme_make_channel_put_evt (argv [0 ] , argv [1 ] ) ; 
}
static Scheme_Object * channel_p (int n , Scheme_Object * * p ) {
  /* No conversion */
  return (((Scheme_Type ) (((((long ) (p [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (p [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_channel_type ) ) ? scheme_true : scheme_false ) ; 
}
static int channel_get_ready (Scheme_Object * ch , Scheme_Schedule_Info * sinfo ) {
  Scheme_Object * result ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(sinfo, 0), PUSH(result, 1), PUSH(ch, 2)));
# define XfOrM215_COUNT (3)
# define SETUP_XfOrM215(x) SETUP(XfOrM215_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  result = NULLED_OUT ; 
  if (FUNCCALL(SETUP_XfOrM215(_), try_channel ((Scheme_Sema * ) ch , (Syncing * ) sinfo -> current_syncing , - 1 , & result ) )) {
#   define XfOrM216_COUNT (0+XfOrM215_COUNT)
#   define SETUP_XfOrM216(x) SETUP_XfOrM215(x)
    FUNCCALL(SETUP_XfOrM216(_), scheme_set_sync_target (sinfo , result , ((void * ) 0 ) , ((void * ) 0 ) , 0 , 0 ) ); 
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  }
  FUNCCALL(SETUP_XfOrM215(_), ext_get_into_line (ch , sinfo ) ); 
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int channel_put_ready (Scheme_Object * ch , Scheme_Schedule_Info * sinfo ) {
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sinfo, 0), PUSH(ch, 1)));
# define XfOrM217_COUNT (2)
# define SETUP_XfOrM217(x) SETUP(XfOrM217_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (FUNCCALL(SETUP_XfOrM217(_), try_channel ((Scheme_Sema * ) ch , (Syncing * ) sinfo -> current_syncing , - 1 , ((void * ) 0 ) ) ))
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  FUNCCALL_EMPTY(ext_get_into_line (ch , sinfo ) ); 
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int channel_syncer_ready (Scheme_Object * ch_w , Scheme_Schedule_Info * sinfo ) {
  /* No conversion */
  Scheme_Channel_Syncer * w = (Scheme_Channel_Syncer * ) ch_w ; 
  if (w -> picked ) {
    return 1 ; 
  }
  return 0 ; 
}
int scheme_try_channel_get (Scheme_Object * ch ) {
  /* No conversion */
  if (try_channel ((Scheme_Sema * ) ch , ((void * ) 0 ) , - 1 , ((void * ) 0 ) ) ) {
    return 1 ; 
  }
  return 0 ; 
}
static Scheme_Object * make_alarm (int argc , Scheme_Object * * argv ) {
  Scheme_Alarm * a ; 
  double sleep_end ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(a, 0)));
# define XfOrM222_COUNT (1)
# define SETUP_XfOrM222(x) SETUP(XfOrM222_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a = NULLED_OUT ; 
  if (! ((((long ) (argv [0 ] ) ) & 0x1 ) || ((((argv [0 ] ) -> type ) >= scheme_bignum_type ) && (((argv [0 ] ) -> type ) <= scheme_complex_izi_type ) ) ) ) {
#   define XfOrM223_COUNT (0+XfOrM222_COUNT)
#   define SETUP_XfOrM223(x) SETUP_XfOrM222(x)
    FUNCCALL_EMPTY(scheme_wrong_type ("alarm-evt" , "real number" , 0 , argc , argv ) ); 
  }
  sleep_end = FUNCCALL(SETUP_XfOrM222(_), scheme_get_val_as_double (argv [0 ] ) ); 
  a = ((Scheme_Alarm * ) FUNCCALL(SETUP_XfOrM222(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Alarm ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  a -> so . type = scheme_alarm_type ; 
  a -> sleep_end = sleep_end ; 
  RET_VALUE_START ((Scheme_Object * ) a ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int alarm_ready (Scheme_Object * _a , Scheme_Schedule_Info * sinfo ) {
  /* No conversion */
  Scheme_Alarm * a = (Scheme_Alarm * ) _a ; 
  if (! sinfo -> sleep_end || (sinfo -> sleep_end > a -> sleep_end ) )
    sinfo -> sleep_end = a -> sleep_end ; 
  if (a -> sleep_end <= scheme_get_inexact_milliseconds () )
    return 1 ; 
  return 0 ; 
}
static int always_ready (Scheme_Object * w ) {
  /* No conversion */
  return 1 ; 
}
static int never_ready (Scheme_Object * w ) {
  /* No conversion */
  return 0 ; 
}
static Scheme_Object * make_sys_idle (int n , Scheme_Object * * p ) {
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(3);
# define XfOrM227_COUNT (0)
# define SETUP_XfOrM227(x) SETUP(XfOrM227_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! system_idle_put_evt ) {
    Scheme_Object * a [2 ] ; 
    BLOCK_SETUP((PUSHARRAY(a, 2, 0+XfOrM227_COUNT)));
#   define XfOrM228_COUNT (3+XfOrM227_COUNT)
#   define SETUP_XfOrM228(x) SETUP(XfOrM228_COUNT)
    a[0] = NULLED_OUT ; 
    a[1] = NULLED_OUT ; 
    FUNCCALL(SETUP_XfOrM228(_), scheme_register_static ((void * ) & system_idle_put_evt , sizeof (system_idle_put_evt ) ) ); 
    system_idle_put_evt = FUNCCALL_AGAIN(scheme_make_channel_put_evt (scheme_system_idle_channel , scheme_void ) ); 
    a [0 ] = system_idle_put_evt ; 
    a [1 ] = scheme_void_proc ; 
    system_idle_put_evt = FUNCCALL(SETUP_XfOrM228(_), scheme_wrap_evt (2 , a ) ); 
  }
  RET_VALUE_START (system_idle_put_evt ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int mark_channel_syncer_SIZE (void * p ) {
  return ((sizeof (Scheme_Channel_Syncer ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_channel_syncer_MARK (void * p ) {
  Scheme_Channel_Syncer * w = (Scheme_Channel_Syncer * ) p ; 
  GC_mark (w -> p ) ; 
  GC_mark (w -> prev ) ; 
  GC_mark (w -> next ) ; 
  GC_mark (w -> syncing ) ; 
  GC_mark (w -> obj ) ; 
  return ((sizeof (Scheme_Channel_Syncer ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_channel_syncer_FIXUP (void * p ) {
  Scheme_Channel_Syncer * w = (Scheme_Channel_Syncer * ) p ; 
  GC_fixup (& (w -> p ) ) ; 
  GC_fixup (& (w -> prev ) ) ; 
  GC_fixup (& (w -> next ) ) ; 
  GC_fixup (& (w -> syncing ) ) ; 
  GC_fixup (& (w -> obj ) ) ; 
  return ((sizeof (Scheme_Channel_Syncer ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_alarm_SIZE (void * p ) {
  return ((sizeof (Scheme_Alarm ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_alarm_MARK (void * p ) {
  return ((sizeof (Scheme_Alarm ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_alarm_FIXUP (void * p ) {
  return ((sizeof (Scheme_Alarm ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static void register_traversers (void ) {
  GC_register_traversers (scheme_alarm_type , mark_alarm_SIZE , mark_alarm_MARK , mark_alarm_FIXUP , 1 , 1 ) ; 
  GC_register_traversers (scheme_channel_syncer_type , mark_channel_syncer_SIZE , mark_channel_syncer_MARK , mark_channel_syncer_FIXUP , 1 , 0 ) ; 
}
