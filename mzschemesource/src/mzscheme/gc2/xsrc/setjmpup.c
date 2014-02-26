#include "precomp.h"
void * (* scheme_get_external_stack_val ) (void ) ; 
void (* scheme_set_external_stack_val ) (void * ) ; 
static void * stack_copy_cache [10 ] ; 
static long stack_copy_size_cache [10 ] ; 
static int scc_pos ; 
void scheme_flush_stack_copy_cache (void ) {
  int i ; 
  for (i = 0 ; i < 10 ; i ++ ) {
    stack_copy_cache [i ] = ((void * ) 0 ) ; 
    stack_copy_size_cache [i ] = 0 ; 
  }
}
void scheme_copy_stack (Scheme_Jumpup_Buf * b , void * base , void * start , void * gc_var_stack_in ) {
  long size , msize ; 
  void * here ; 
  PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(b, 0), PUSH(base, 1), PUSH(gc_var_stack_in, 2)));
# define XfOrM1_COUNT (3)
# define SETUP_XfOrM1(x) SETUP(XfOrM1_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  here = NULLED_OUT ; 
  here = & size ; 
  size = (long ) here XFORM_OK_MINUS (long ) start ; 
  size = - size ; 
  b -> stack_from = here ; 
  if (size < 0 )
    size = 0 ; 
  msize = size ; 
  if (b -> stack_max_size < size ) {
    void * copy ; 
    unsigned long diff ; 
    BLOCK_SETUP((PUSH(copy, 0+XfOrM1_COUNT)));
#   define XfOrM3_COUNT (1+XfOrM1_COUNT)
#   define SETUP_XfOrM3(x) SETUP(XfOrM3_COUNT)
    copy = NULLED_OUT ; 
    diff = (unsigned long ) b XFORM_OK_MINUS (unsigned long ) base ; 
    b = ((void * ) 0 ) ; 
    copy = ((void * ) 0 ) ; 
    {
      int i ; 
      for (i = 0 ; i < 10 ; i ++ ) {
        if ((stack_copy_size_cache [i ] >= size ) && (stack_copy_size_cache [i ] < (size + 100 ) ) ) {
          copy = stack_copy_cache [i ] ; 
          msize = stack_copy_size_cache [i ] ; 
          stack_copy_cache [i ] = ((void * ) 0 ) ; 
          stack_copy_size_cache [i ] = 0 ; 
          break ; 
        }
      }
    }
    if (! copy ) {
#     define XfOrM4_COUNT (0+XfOrM3_COUNT)
#     define SETUP_XfOrM4(x) SETUP_XfOrM3(x)
      copy = FUNCCALL(SETUP_XfOrM4(_), GC_malloc_atomic (size ) ); 
    }
    b = (Scheme_Jumpup_Buf * ) (((char * ) base ) XFORM_OK_PLUS diff ) ; 
    b -> stack_copy = copy ; 
    b -> stack_max_size = msize ; 
  }
  b -> stack_size = size ; 
  b -> gc_var_stack = gc_var_stack_in ; 
  if (scheme_get_external_stack_val ) {
    void * es ; 
    BLOCK_SETUP((PUSH(es, 0+XfOrM1_COUNT)));
#   define XfOrM2_COUNT (1+XfOrM1_COUNT)
#   define SETUP_XfOrM2(x) SETUP(XfOrM2_COUNT)
    es = NULLED_OUT ; 
    es = FUNCCALL(SETUP_XfOrM2(_), scheme_get_external_stack_val () ); 
    b -> external_stack = es ; 
  }
  (memcpy ((b -> stack_copy ) , b -> stack_from , size ) ) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void uncopy_stack (int ok , Scheme_Jumpup_Buf * b , long * prev ) {
  GC_CAN_IGNORE Scheme_Jumpup_Buf * c ; 
  long top_delta = 0 , bottom_delta = 0 , size ; 
  void * cfrom , * cto ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(prev, 0), PUSH(b, 1)));
# define XfOrM10_COUNT (2)
# define SETUP_XfOrM10(x) SETUP(XfOrM10_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  cfrom = NULLED_OUT ; 
  cto = NULLED_OUT ; 
  if (! ok ) {
    unsigned long z ; 
    long junk [200 ] ; 
#   define XfOrM11_COUNT (0+XfOrM10_COUNT)
#   define SETUP_XfOrM11(x) SETUP_XfOrM10(x)
    z = (unsigned long ) & junk [0 ] ; 
    FUNCCALL(SETUP_XfOrM11(_), uncopy_stack (((z ) < (((unsigned long ) (b ) -> stack_from ) ) ) , b , junk ) ); 
  }
  prev [199 ] = 0 ; 
  ; 
  c = b ; 
  while (c ) {
    size = c -> stack_size - top_delta ; 
    cto = (char * ) c -> stack_from + bottom_delta ; 
    cfrom = (char * ) (c -> stack_copy ) + bottom_delta ; 
    memcpy (cto , cfrom , size ) ; 
    if (c -> cont ) {
      bottom_delta = ((unsigned long ) c -> stack_from + c -> stack_size - (unsigned long ) c -> cont -> buf . stack_from ) ; 
      top_delta = bottom_delta ; 
      c = & c -> cont -> buf ; 
    }
    else c = ((void * ) 0 ) ; 
  }
  GC_variable_stack = b -> gc_var_stack ; 
  if (scheme_set_external_stack_val )
    FUNCCALL(SETUP_XfOrM10(_), scheme_set_external_stack_val (b -> external_stack ) ); 
  (((long * ) (void * ) ((b -> buf ) . gcvs ) ) [1 ] = (b -> buf ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (b -> buf ) . gcvs , scheme_jit_longjmp ((b -> buf ) . jb , 1 ) ) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static long find_same (char * p , char * low , long max_size ) {
  long cnt = 0 ; 
  if (max_size > 4096 ) {
    cnt = max_size - 4096 ; 
    max_size = 4096 ; 
  }
  while (max_size -- ) {
    if (p [max_size ] != low [max_size ] )
      break ; 
    cnt ++ ; 
  }
  if (cnt & (8 - 1 ) ) {
    cnt -= (cnt & (8 - 1 ) ) ; 
  }
  return cnt ; 
}
static void * align_var_stack (void * * vs , void * s ) {
  void * * nvs , * * next ; 
  long i , cnt ; 
  void * a ; 
  while ((((unsigned long ) vs ) < ((unsigned long ) s ) ) ) {
    vs = (void * * ) (* vs ) ; 
  }
  s = (void * ) vs ; 
  nvs = * vs ; 
  while (nvs ) {
    next = ((void * ) 0 ) ; 
    cnt = ((long * ) nvs ) [1 ] ; 
    for (i = 0 ; i < cnt ; i ++ ) {
      a = nvs [i + 2 ] ; 
      if (! a ) {
        a = nvs [i + 3 ] ; 
        i += 2 ; 
      }
      if ((((unsigned long ) a ) < ((unsigned long ) s ) ) ) {
        vs = nvs ; 
        s = (void * ) vs ; 
        next = * nvs ; 
        break ; 
      }
    }
    nvs = next ; 
  }
  return s ; 
}
static void * shift_var_stack (void * s ) {
  void * * vs = (void * * ) s ; 
  long cnt ; 
  cnt = ((long * ) vs ) [1 ] ; 
  return (void * ) (vs + cnt + 2 ) ; 
}
int scheme_setjmpup_relative (Scheme_Jumpup_Buf * b , void * base , void * volatile start , struct Scheme_Cont * c ) {
  int local ; 
  long disguised_b ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(base, 0), PUSH(c, 1), PUSH(start, 2), PUSH(b, 3)));
# define XfOrM12_COUNT (4)
# define SETUP_XfOrM12(x) SETUP(XfOrM12_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM12(_), scheme_flush_stack_cache () ); 
  ; 
  if (! (local = ((b -> buf ) . gcvs = (long ) __gc_var_stack__ , (b -> buf ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((b -> buf ) . jb ) , (_setjmp (((b -> buf ) . jb ) -> jb ) ) ) ) ) ) {
#   define XfOrM13_COUNT (0+XfOrM12_COUNT)
#   define SETUP_XfOrM13(x) SETUP_XfOrM12(x)
    if (c ) {
      long same_size ; 
      same_size = find_same ((c -> buf . stack_copy ) , c -> buf . stack_from , c -> buf . stack_size ) ; 
      b -> cont = c ; 
      start = (void * ) ((char * ) c -> buf . stack_from + (c -> buf . stack_size - same_size ) ) ; 
      start = align_var_stack (__gc_var_stack__ , start ) ; 
    }
    else b -> cont = ((void * ) 0 ) ; 
    start = FUNCCALL(SETUP_XfOrM13(_), shift_var_stack (start ) ); 
    ; 
    disguised_b = (long ) b ; 
    b = ((void * ) 0 ) ; 
    FUNCCALL(SETUP_XfOrM13(_), scheme_copy_stack ((Scheme_Jumpup_Buf * ) disguised_b , base , start , __gc_var_stack__ ) ); 
    if (0 ) {
#     define XfOrM14_COUNT (0+XfOrM13_COUNT)
#     define SETUP_XfOrM14(x) SETUP_XfOrM13(x)
      base = FUNCCALL_EMPTY(GC_malloc (0 ) ); 
    }
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  RET_VALUE_START (local ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_longjmpup (Scheme_Jumpup_Buf * b ) {
  long z ; 
  long junk [200 ] ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(b, 0)));
# define XfOrM16_COUNT (1)
# define SETUP_XfOrM16(x) SETUP(XfOrM16_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM16(_), scheme_flush_stack_cache () ); 
  FUNCCALL_EMPTY(uncopy_stack ((((unsigned long ) & z ) < (((unsigned long ) (b ) -> stack_from ) ) ) , b , junk ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_init_jmpup_buf (Scheme_Jumpup_Buf * b ) {
  /* No conversion */
  b -> stack_size = b -> stack_max_size = 0 ; 
  b -> stack_from = b -> stack_copy = ((void * ) 0 ) ; 
}
void scheme_reset_jmpup_buf (Scheme_Jumpup_Buf * b ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(b, 0)));
# define XfOrM18_COUNT (1)
# define SETUP_XfOrM18(x) SETUP(XfOrM18_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (b -> stack_copy ) {
#   define XfOrM19_COUNT (0+XfOrM18_COUNT)
#   define SETUP_XfOrM19(x) SETUP_XfOrM18(x)
    stack_copy_cache [scc_pos ] = b -> stack_copy ; 
    stack_copy_size_cache [scc_pos ] = b -> stack_max_size ; 
    scc_pos ++ ; 
    if (scc_pos == 10 )
      scc_pos = 0 ; 
    FUNCCALL(SETUP_XfOrM19(_), scheme_init_jmpup_buf (b ) ); 
  }
  (memset (& b -> buf , 0 , sizeof (mz_jmp_buf ) ) ) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
