#include "precomp.h"
static void * * dgc_array ; 
static int * dgc_count ; 
static int dgc_size ; 
static int use_registered_statics ; 
void scheme_set_stack_base (void * base , int no_auto_statics ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(base, 0)));
# define XfOrM1_COUNT (1)
# define SETUP_XfOrM1(x) SETUP(XfOrM1_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM1(_), GC_init_type_tags (_scheme_last_type_ , scheme_pair_type , scheme_weak_box_type , scheme_ephemeron_type , scheme_rt_weak_array , scheme_cust_box_type ) ); 
  FUNCCALL(SETUP_XfOrM1(_), scheme_register_traversers () ); 
  FUNCCALL_EMPTY(GC_set_stack_base (base ) ); 
  use_registered_statics = no_auto_statics ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_set_stack_bounds (void * base , void * deepest , int no_auto_statics ) {
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(deepest, 0)));
# define XfOrM2_COUNT (1)
# define SETUP_XfOrM2(x) SETUP(XfOrM2_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM2(_), scheme_set_stack_base (base , no_auto_statics ) ); 
  if (deepest ) {
    scheme_stack_boundary = (unsigned long ) deepest ; 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
extern unsigned long scheme_get_stack_base () {
  /* No conversion */
  return (unsigned long ) GC_get_stack_base () ; 
}
void scheme_dont_gc_ptr (void * p ) {
  int i , oldsize ; 
  void * * naya ; 
  int * nayac ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(p, 0), PUSH(nayac, 1), PUSH(naya, 2)));
# define XfOrM5_COUNT (3)
# define SETUP_XfOrM5(x) SETUP(XfOrM5_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  naya = NULLED_OUT ; 
  nayac = NULLED_OUT ; 
  for (i = 0 ; i < dgc_size ; i ++ ) {
    if (dgc_array [i ] == p ) {
      dgc_count [i ] ++ ; 
      RET_NOTHING ; 
    }
  }
  for (i = 0 ; i < dgc_size ; i ++ ) {
    if (! dgc_array [i ] ) {
      dgc_array [i ] = p ; 
      dgc_count [i ] = 1 ; 
      RET_NOTHING ; 
    }
  }
  oldsize = dgc_size ; 
  if (! dgc_array ) {
#   define XfOrM10_COUNT (0+XfOrM5_COUNT)
#   define SETUP_XfOrM10(x) SETUP_XfOrM5(x)
    FUNCCALL(SETUP_XfOrM10(_), scheme_register_static ((void * ) & dgc_array , sizeof (dgc_array ) ) ); 
    FUNCCALL(SETUP_XfOrM10(_), scheme_register_static ((void * ) & dgc_count , sizeof (dgc_count ) ) ); 
    dgc_size = 50 ; 
  }
  else dgc_size *= 2 ; 
  naya = ((void * * ) FUNCCALL(SETUP_XfOrM5(_), GC_malloc (sizeof (void * ) * (dgc_size ) ) )) ; 
  nayac = ((int * ) FUNCCALL(SETUP_XfOrM5(_), GC_malloc (sizeof (int ) * (dgc_size ) ) )) ; 
  for (i = 0 ; i < oldsize ; i ++ ) {
    naya [i ] = dgc_array [i ] ; 
    nayac [i ] = dgc_count [i ] ; 
  }
  for (; i < dgc_size ; i ++ ) {
    naya [i ] = ((void * ) 0 ) ; 
    nayac [i ] = 0 ; 
  }
  dgc_array = naya ; 
  dgc_count = nayac ; 
  dgc_array [oldsize ] = p ; 
  dgc_count [oldsize ] = 1 ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_gc_ptr_ok (void * p ) {
  /* No conversion */
  int i ; 
  for (i = 0 ; i < dgc_size ; i ++ ) {
    if (dgc_array [i ] == p ) {
      if (! (-- dgc_count [i ] ) )
        dgc_array [i ] = ((void * ) 0 ) ; 
      break ; 
    }
  }
}
void * scheme_calloc (size_t num , size_t size ) {
  void * space ; 
  DECL_RET_SAVE (void * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(space, 0)));
# define XfOrM24_COUNT (1)
# define SETUP_XfOrM24(x) SETUP(XfOrM24_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  space = NULLED_OUT ; 
  space = FUNCCALL(SETUP_XfOrM24(_), malloc (num * size ) ); 
  if (! space )
    FUNCCALL_EMPTY(scheme_raise_out_of_memory (((void * ) 0 ) , ((void * ) 0 ) ) ); 
  RET_VALUE_START ((space ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
char * scheme_strdup (const char * str ) {
  char * naya ; 
  long len ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(str, 0), PUSH(naya, 1)));
# define XfOrM25_COUNT (2)
# define SETUP_XfOrM25(x) SETUP(XfOrM25_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  naya = NULLED_OUT ; 
  len = strlen (str ) + 1 ; 
  naya = (char * ) FUNCCALL(SETUP_XfOrM25(_), GC_malloc_atomic (len * sizeof (char ) ) ); 
  (memcpy (naya , str , len ) ) ; 
  RET_VALUE_START (naya ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
char * scheme_strdup_eternal (const char * str ) {
  char * naya ; 
  long len ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(str, 0), PUSH(naya, 1)));
# define XfOrM26_COUNT (2)
# define SETUP_XfOrM26(x) SETUP(XfOrM26_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  naya = NULLED_OUT ; 
  len = strlen (str ) + 1 ; 
  naya = (char * ) FUNCCALL(SETUP_XfOrM26(_), scheme_malloc_eternal (len * sizeof (char ) ) ); 
  (memcpy (naya , str , len ) ) ; 
  RET_VALUE_START (naya ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_cptr (void * cptr , Scheme_Object * typetag ) {
  Scheme_Object * o ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(typetag, 1), PUSH(cptr, 2)));
# define XfOrM27_COUNT (3)
# define SETUP_XfOrM27(x) SETUP(XfOrM27_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  o = NULLED_OUT ; 
  o = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM27(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Cptr ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) ); 
  o -> type = scheme_cpointer_type ; 
  (((Scheme_Cptr * ) (o ) ) -> val ) = cptr ; 
  (((Scheme_Cptr * ) (o ) ) -> type ) = (void * ) typetag ; 
  RET_VALUE_START (o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_offset_cptr (void * cptr , long offset , Scheme_Object * typetag ) {
  Scheme_Object * o ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(o, 0), PUSH(typetag, 1), PUSH(cptr, 2)));
# define XfOrM28_COUNT (3)
# define SETUP_XfOrM28(x) SETUP(XfOrM28_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  o = NULLED_OUT ; 
  o = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM28(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Offset_Cptr ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) ); 
  o -> type = scheme_offset_cpointer_type ; 
  (((Scheme_Cptr * ) (o ) ) -> val ) = cptr ; 
  (((Scheme_Cptr * ) (o ) ) -> type ) = (void * ) typetag ; 
  ((Scheme_Offset_Cptr * ) o ) -> offset = offset ; 
  RET_VALUE_START (o ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void * * scheme_malloc_immobile_box (void * p ) {
  /* No conversion */
  return GC_malloc_immobile_box (p ) ; 
}
void scheme_free_immobile_box (void * * b ) {
  /* No conversion */
  GC_free_immobile_box (b ) ; 
}
static void (* save_oom ) (void ) ; 
static void raise_out_of_memory (void ) {
  /* No conversion */
  GC_out_of_memory = save_oom ; 
  scheme_raise_out_of_memory (((void * ) 0 ) , ((void * ) 0 ) ) ; 
}
void * scheme_malloc_fail_ok (void * (* f ) (size_t ) , size_t s ) {
  void * v ; 
  DECL_RET_SAVE (void * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(v, 0)));
# define XfOrM32_COUNT (1)
# define SETUP_XfOrM32(x) SETUP(XfOrM32_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  v = NULLED_OUT ; 
  save_oom = GC_out_of_memory ; 
  GC_out_of_memory = raise_out_of_memory ; 
  v = FUNCCALL(SETUP_XfOrM32(_), f (s ) ); 
  GC_out_of_memory = save_oom ; 
  RET_VALUE_START (v ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_end_stubborn_change (void * p ) {
  /* No conversion */
}
void * scheme_malloc_eternal (size_t n ) {
  void * s ; 
  DECL_RET_SAVE (void * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(s, 0)));
# define XfOrM34_COUNT (1)
# define SETUP_XfOrM34(x) SETUP(XfOrM34_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  s = FUNCCALL(SETUP_XfOrM34(_), malloc (n ) ); 
  if (! s ) {
#   define XfOrM35_COUNT (0+XfOrM34_COUNT)
#   define SETUP_XfOrM35(x) SETUP_XfOrM34(x)
    if (GC_out_of_memory )
      FUNCCALL(SETUP_XfOrM35(_), GC_out_of_memory () ); 
    else {
#     define XfOrM36_COUNT (0+XfOrM35_COUNT)
#     define SETUP_XfOrM36(x) SETUP_XfOrM35(x)
      if (scheme_console_printf )
        FUNCCALL(SETUP_XfOrM36(_), scheme_console_printf ("out of memory\n" ) ); 
      else (printf ("out of memory\n" ) ) ; 
      FUNCCALL_EMPTY(exit (1 ) ); 
    }
  }
  (memset (s , 0 , n ) ) ; 
  RET_VALUE_START (s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void * scheme_malloc_uncollectable (size_t size_in_bytes ) {
  void * p ; 
  DECL_RET_SAVE (void * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(p, 0)));
# define XfOrM37_COUNT (1)
# define SETUP_XfOrM37(x) SETUP(XfOrM37_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  p = NULLED_OUT ; 
  p = FUNCCALL(SETUP_XfOrM37(_), GC_malloc (size_in_bytes ) ); 
  FUNCCALL_AGAIN(scheme_dont_gc_ptr (p ) ); 
  RET_VALUE_START (p ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_register_static (void * ptr , long size ) {
  GC_add_roots ((char * ) ptr , (char * ) (((char * ) ptr ) + size + 1 ) ) ; 
}
typedef struct Finalization {
  Scheme_Type type ; 
  void (* f ) (void * o , void * data ) ; 
  void * data ; 
  struct Finalization * next , * prev ; 
}
Finalization ; 
typedef struct {
  Scheme_Type type ; 
  short lifetime ; 
  Finalization * scheme_first , * scheme_last ; 
  void (* ext_f ) (void * o , void * data ) ; 
  void * ext_data ; 
  Finalization * prim_first , * prim_last ; 
}
Finalizations ; 
typedef char * (* GC_get_type_name_proc ) (short t ) ; 
typedef char * (* GC_get_xtagged_name_proc ) (void * p ) ; 
typedef void (* GC_for_each_found_proc ) (void * p ) ; 
typedef void (* GC_print_tagged_value_proc ) (const char * prefix , void * v , int xtagged , unsigned long diff , int max_w , const char * suffix ) ; 
extern void GC_dump_with_traces (int flags , GC_get_type_name_proc get_type_name , GC_get_xtagged_name_proc get_xtagged_name , GC_for_each_found_proc for_each_found , short trace_for_tag , GC_print_tagged_value_proc print_tagged_value , int path_length_limit ) ; 
static int mark_finalization_SIZE (void * p ) {
  return ((sizeof (Finalization ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_finalization_MARK (void * p ) {
  Finalization * f = (Finalization * ) p ; 
  GC_mark (f -> data ) ; 
  GC_mark (f -> next ) ; 
  GC_mark (f -> prev ) ; 
  return ((sizeof (Finalization ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_finalization_FIXUP (void * p ) {
  Finalization * f = (Finalization * ) p ; 
  GC_fixup (& (f -> data ) ) ; 
  GC_fixup (& (f -> next ) ) ; 
  GC_fixup (& (f -> prev ) ) ; 
  return ((sizeof (Finalization ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_finalizations_SIZE (void * p ) {
  return ((sizeof (Finalizations ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_finalizations_MARK (void * p ) {
  Finalizations * f = (Finalizations * ) p ; 
  GC_mark (f -> scheme_first ) ; 
  GC_mark (f -> scheme_last ) ; 
  GC_mark (f -> prim_first ) ; 
  GC_mark (f -> prim_last ) ; 
  GC_mark (f -> ext_data ) ; 
  return ((sizeof (Finalizations ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_finalizations_FIXUP (void * p ) {
  Finalizations * f = (Finalizations * ) p ; 
  GC_fixup (& (f -> scheme_first ) ) ; 
  GC_fixup (& (f -> scheme_last ) ) ; 
  GC_fixup (& (f -> prim_first ) ) ; 
  GC_fixup (& (f -> prim_last ) ) ; 
  GC_fixup (& (f -> ext_data ) ) ; 
  return ((sizeof (Finalizations ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int current_lifetime ; 
void scheme_reset_finalizations (void ) {
  /* No conversion */
  current_lifetime ++ ; 
}
static void do_next_finalization (void * o , void * data ) {
  Finalizations * fns = * (Finalizations * * ) data ; 
  Finalization * fn ; 
  PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(data, 0), PUSH(fns, 1), PUSH(fn, 2), PUSH(o, 3)));
# define XfOrM39_COUNT (4)
# define SETUP_XfOrM39(x) SETUP(XfOrM39_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  fn = NULLED_OUT ; 
  if (fns -> lifetime != current_lifetime )
    RET_NOTHING ; 
  if (fns -> scheme_first ) {
#   define XfOrM42_COUNT (0+XfOrM39_COUNT)
#   define SETUP_XfOrM42(x) SETUP_XfOrM39(x)
    if (fns -> scheme_first -> next || fns -> ext_f || fns -> prim_first ) {
#     define XfOrM43_COUNT (0+XfOrM42_COUNT)
#     define SETUP_XfOrM43(x) SETUP_XfOrM42(x)
      FUNCCALL(SETUP_XfOrM43(_), GC_set_finalizer (o , 1 , fns -> scheme_first -> next ? 1 : 2 , do_next_finalization , data , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
    }
    fn = fns -> scheme_first ; 
    fns -> scheme_first = fn -> next ; 
    if (! fn -> next )
      fns -> scheme_last = ((void * ) 0 ) ; 
    else fn -> next -> prev = ((void * ) 0 ) ; 
    FUNCCALL(SETUP_XfOrM42(_), fn -> f (o , fn -> data ) ); 
    RET_NOTHING ; 
  }
  if (fns -> ext_f )
    FUNCCALL(SETUP_XfOrM39(_), fns -> ext_f (o , fns -> ext_data ) ); 
  for (fn = fns -> prim_first ; fn ; fn = fn -> next ) {
#   define XfOrM41_COUNT (0+XfOrM39_COUNT)
#   define SETUP_XfOrM41(x) SETUP_XfOrM39(x)
    FUNCCALL(SETUP_XfOrM41(_), fn -> f (o , fn -> data ) ); 
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
typedef void (* finalizer_function ) (void * p , void * data ) ; 
static int traversers_registered ; 
static Finalizations * * save_fns_ptr ; 
static void add_finalizer (void * v , void (* f ) (void * , void * ) , void * data , int prim , int ext , void (* * ext_oldf ) (void * p , void * data ) , void * * ext_olddata , int no_dup , int rmve ) {
  finalizer_function oldf ; 
  void * olddata ; 
  Finalizations * fns , * * fns_ptr , * prealloced ; 
  Finalization * fn ; 
  PREPARE_VAR_STACK_ONCE(8);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(prealloced, 1), PUSH(ext_olddata, 2), PUSH(fn, 3), PUSH(data, 4), PUSH(fns_ptr, 5), PUSH(olddata, 6), PUSH(fns, 7)));
# define XfOrM44_COUNT (8)
# define SETUP_XfOrM44(x) SETUP(XfOrM44_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  olddata = NULLED_OUT ; 
  fns = NULLED_OUT ; 
  fns_ptr = NULLED_OUT ; 
  prealloced = NULLED_OUT ; 
  fn = NULLED_OUT ; 
  if (! traversers_registered ) {
#   define XfOrM67_COUNT (0+XfOrM44_COUNT)
#   define SETUP_XfOrM67(x) SETUP_XfOrM44(x)
    FUNCCALL(SETUP_XfOrM67(_), GC_register_traversers (scheme_rt_finalization , mark_finalization_SIZE , mark_finalization_MARK , mark_finalization_FIXUP , 1 , 0 ) ); 
    FUNCCALL(SETUP_XfOrM67(_), GC_register_traversers (scheme_rt_finalizations , mark_finalizations_SIZE , mark_finalizations_MARK , mark_finalizations_FIXUP , 1 , 0 ) ); 
    traversers_registered = 1 ; 
    FUNCCALL(SETUP_XfOrM67(_), scheme_register_static ((void * ) & save_fns_ptr , sizeof (save_fns_ptr ) ) ); 
  }
  if (save_fns_ptr ) {
    fns_ptr = save_fns_ptr ; 
    save_fns_ptr = ((void * ) 0 ) ; 
  }
  else fns_ptr = ((Finalizations * * ) FUNCCALL(SETUP_XfOrM44(_), GC_malloc (sizeof (Finalizations * ) * (1 ) ) )) ; 
  if (! ext && ! rmve ) {
#   define XfOrM65_COUNT (0+XfOrM44_COUNT)
#   define SETUP_XfOrM65(x) SETUP_XfOrM44(x)
    fn = ((Finalization * ) FUNCCALL(SETUP_XfOrM65(_), GC_malloc_one_small_tagged ((((sizeof (Finalization ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    fn -> type = scheme_rt_finalization ; 
    fn -> f = f ; 
    fn -> data = data ; 
  }
  else fn = ((void * ) 0 ) ; 
  if (! rmve ) {
#   define XfOrM64_COUNT (0+XfOrM44_COUNT)
#   define SETUP_XfOrM64(x) SETUP_XfOrM44(x)
    prealloced = ((Finalizations * ) FUNCCALL(SETUP_XfOrM64(_), GC_malloc_one_small_tagged ((((sizeof (Finalizations ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
    prealloced -> type = scheme_rt_finalizations ; 
  }
  else prealloced = ((void * ) 0 ) ; 
  FUNCCALL(SETUP_XfOrM44(_), GC_set_finalizer (v , 1 , prim ? 2 : 1 , do_next_finalization , fns_ptr , & oldf , & olddata ) ); 
  if (oldf ) {
#   define XfOrM61_COUNT (0+XfOrM44_COUNT)
#   define SETUP_XfOrM61(x) SETUP_XfOrM44(x)
    if (oldf != do_next_finalization ) {
#     define XfOrM63_COUNT (0+XfOrM61_COUNT)
#     define SETUP_XfOrM63(x) SETUP_XfOrM61(x)
      FUNCCALL(SETUP_XfOrM63(_), scheme_warning ("warning: non-MzScheme finalization on object dropped!" ) ); 
    }
    else {
      * fns_ptr = * (Finalizations * * ) olddata ; 
      save_fns_ptr = (Finalizations * * ) olddata ; 
      * save_fns_ptr = ((void * ) 0 ) ; 
    }
  }
  else if (rmve ) {
#   define XfOrM60_COUNT (0+XfOrM44_COUNT)
#   define SETUP_XfOrM60(x) SETUP_XfOrM44(x)
    FUNCCALL(SETUP_XfOrM60(_), GC_set_finalizer (v , 1 , 3 , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
    save_fns_ptr = fns_ptr ; 
    RET_NOTHING ; 
  }
  if (! (* fns_ptr ) ) {
    prealloced -> lifetime = current_lifetime ; 
    * fns_ptr = prealloced ; 
  }
  fns = * fns_ptr ; 
  if (ext ) {
#   define XfOrM57_COUNT (0+XfOrM44_COUNT)
#   define SETUP_XfOrM57(x) SETUP_XfOrM44(x)
    if (ext_oldf )
      * ext_oldf = fns -> ext_f ; 
    fns -> ext_f = f ; 
    if (ext_olddata )
      * ext_olddata = fns -> ext_data ; 
    fns -> ext_data = data ; 
    if (! f && ! fns -> prim_first && ! fns -> scheme_first ) {
#     define XfOrM58_COUNT (0+XfOrM57_COUNT)
#     define SETUP_XfOrM58(x) SETUP_XfOrM57(x)
      FUNCCALL(SETUP_XfOrM58(_), GC_set_finalizer (v , 1 , 3 , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
      save_fns_ptr = fns_ptr ; 
      * save_fns_ptr = ((void * ) 0 ) ; 
    }
  }
  else {
#   define XfOrM45_COUNT (0+XfOrM44_COUNT)
#   define SETUP_XfOrM45(x) SETUP_XfOrM44(x)
    if (prim ) {
#     define XfOrM47_COUNT (0+XfOrM45_COUNT)
#     define SETUP_XfOrM47(x) SETUP_XfOrM45(x)
      if (no_dup ) {
        Finalization * fnx ; 
        fnx = NULLED_OUT ; 
        for (fnx = fns -> prim_first ; fnx ; fnx = fnx -> next ) {
          if (fnx -> f == f && fnx -> data == data ) {
            if (rmve ) {
              if (fnx -> prev )
                fnx -> prev -> next = fnx -> next ; 
              else fns -> prim_first = fnx -> next ; 
              if (fnx -> next )
                fnx -> next -> prev = fnx -> prev ; 
              else fns -> prim_last = fnx -> prev ; 
            }
            fn = ((void * ) 0 ) ; 
            break ; 
          }
        }
      }
      if (fn ) {
        fn -> next = fns -> prim_first ; 
        fns -> prim_first = fn ; 
        if (! fn -> next )
          fns -> prim_last = fn ; 
        else fn -> next -> prev = fn ; 
      }
      if (! fns -> ext_f && ! fns -> prim_first && ! fns -> scheme_first ) {
#       define XfOrM48_COUNT (0+XfOrM47_COUNT)
#       define SETUP_XfOrM48(x) SETUP_XfOrM47(x)
        FUNCCALL(SETUP_XfOrM48(_), GC_set_finalizer (v , 1 , 3 , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
        save_fns_ptr = fns_ptr ; 
        * save_fns_ptr = ((void * ) 0 ) ; 
      }
    }
    else {
      fn -> next = fns -> scheme_first ; 
      fns -> scheme_first = fn ; 
      if (! fn -> next )
        fns -> scheme_last = fn ; 
      else fn -> next -> prev = fn ; 
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_add_finalizer (void * p , void (* f ) (void * p , void * data ) , void * data ) {
  /* No conversion */
  add_finalizer (p , f , data , 1 , 0 , ((void * ) 0 ) , ((void * ) 0 ) , 0 , 0 ) ; 
}
void scheme_add_finalizer_once (void * p , void (* f ) (void * p , void * data ) , void * data ) {
  /* No conversion */
  add_finalizer (p , f , data , 1 , 0 , ((void * ) 0 ) , ((void * ) 0 ) , 1 , 0 ) ; 
}
void scheme_subtract_finalizer (void * p , void (* f ) (void * p , void * data ) , void * data ) {
  /* No conversion */
  add_finalizer (p , f , data , 1 , 0 , ((void * ) 0 ) , ((void * ) 0 ) , 1 , 1 ) ; 
}
void scheme_add_scheme_finalizer (void * p , void (* f ) (void * p , void * data ) , void * data ) {
  /* No conversion */
  add_finalizer (p , f , data , 0 , 0 , ((void * ) 0 ) , ((void * ) 0 ) , 0 , 0 ) ; 
}
void scheme_add_scheme_finalizer_once (void * p , void (* f ) (void * p , void * data ) , void * data ) {
  /* No conversion */
  add_finalizer (p , f , data , 0 , 0 , ((void * ) 0 ) , ((void * ) 0 ) , 1 , 0 ) ; 
}
void scheme_register_finalizer (void * p , void (* f ) (void * p , void * data ) , void * data , void (* * oldf ) (void * p , void * data ) , void * * olddata ) {
  /* No conversion */
  add_finalizer (p , f , data , 0 , 1 , oldf , olddata , 0 , 0 ) ; 
}
void scheme_remove_all_finalization (void * p ) {
  /* No conversion */
  GC_set_finalizer (p , 1 , 3 , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) ) ; 
}
void scheme_collect_garbage (void ) {
  /* No conversion */
  GC_gcollect () ; 
}
unsigned long scheme_get_deeper_address (void ) {
  /* No conversion */
  int v , * vp ; 
  vp = & v ; 
  return (unsigned long ) vp ; 
}
void (* scheme_external_dump_info ) (void ) ; 
void (* scheme_external_dump_arg ) (Scheme_Object * arg ) ; 
char * (* scheme_external_dump_type ) (void * v ) ; 
Scheme_Object * scheme_dump_gc_stats (int c , Scheme_Object * p [] ) {
  Scheme_Object * result = scheme_void ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(result, 0), PUSH(p, 1)));
# define XfOrM77_COUNT (2)
# define SETUP_XfOrM77(x) SETUP(XfOrM77_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM77(_), scheme_start_atomic () ); 
  if (scheme_external_dump_arg )
    FUNCCALL(SETUP_XfOrM77(_), scheme_external_dump_arg (c ? p [0 ] : ((void * ) 0 ) ) ); 
  FUNCCALL(SETUP_XfOrM77(_), scheme_console_printf ("Begin Dump\n" ) ); 
  FUNCCALL_AGAIN(GC_dump_with_traces (0 , scheme_get_type_name , ((void * ) 0 ) , ((void * ) 0 ) , 0 , ((void * ) 0 ) , 1000 ) ); 
  if (scheme_external_dump_info )
    FUNCCALL(SETUP_XfOrM77(_), scheme_external_dump_info () ); 
  FUNCCALL(SETUP_XfOrM77(_), scheme_console_printf ("End Dump\n" ) ); 
  FUNCCALL_AGAIN(scheme_end_atomic () ); 
  RET_VALUE_START (result ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
