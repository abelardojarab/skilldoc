#include "precomp.h"
enum {
  _ISupper = ((0 ) < 8 ? ((1 << (0 ) ) << 8 ) : ((1 << (0 ) ) >> 8 ) ) , _ISlower = ((1 ) < 8 ? ((1 << (1 ) ) << 8 ) : ((1 << (1 ) ) >> 8 ) ) , _ISalpha = ((2 ) < 8 ? ((1 << (2 ) ) << 8 ) : ((1 << (2 ) ) >> 8 ) ) , _ISdigit = ((3 ) < 8 ? ((1 << (3 ) ) << 8 ) : ((1 << (3 ) ) >> 8 ) ) , _ISxdigit = ((4 ) < 8 ? ((1 << (4 ) ) << 8 ) : ((1 << (4 ) ) >> 8 ) ) , _ISspace = ((5 ) < 8 ? ((1 << (5 ) ) << 8 ) : ((1 << (5 ) ) >> 8 ) ) , _ISprint = ((6 ) < 8 ? ((1 << (6 ) ) << 8 ) : ((1 << (6 ) ) >> 8 ) ) , _ISgraph = ((7 ) < 8 ? ((1 << (7 ) ) << 8 ) : ((1 << (7 ) ) >> 8 ) ) , _ISblank = ((8 ) < 8 ? ((1 << (8 ) ) << 8 ) : ((1 << (8 ) ) >> 8 ) ) , _IScntrl = ((9 ) < 8 ? ((1 << (9 ) ) << 8 ) : ((1 << (9 ) ) >> 8 ) ) , _ISpunct = ((10 ) < 8 ? ((1 << (10 ) ) << 8 ) : ((1 << (10 ) ) >> 8 ) ) , _ISalnum = ((11 ) < 8 ? ((1 << (11 ) ) << 8 ) : ((1 << (11 ) ) >> 8 ) ) }
; 
extern double exp (double __x ) __attribute__ ((__nothrow__ ) ) ; 
extern double frexp (double __x , int * __exponent ) __attribute__ ((__nothrow__ ) ) ; 
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
int scheme_hash_request_count ; 
int scheme_hash_iteration_count ; 
static short keygen ; 
__xform_nongcing__ static inline long PTR_TO_LONG (Scheme_Object * o ) {
  /* No conversion */
  short v ; 
  if ((((long ) (o ) ) & 0x1 ) )
    return (long ) o ; 
  v = o -> keyex ; 
  if (! (v & 0xFFFC ) ) {
    if (! keygen )
      keygen += 4 ; 
    v |= keygen ; 
    o -> keyex = v ; 
    keygen += 4 ; 
  }
  return (o -> type << 16 ) | v ; 
}
typedef int (* Hash_Compare_Proc ) (void * , void * ) ; 
typedef unsigned long hash_v_t ; 
static void string_hash_indices (void * _key , long * _h , long * _h2 ) {
  /* No conversion */
  const char * key = (char * ) _key ; 
  long i , h , h2 ; 
  h2 = h = i = 0 ; 
  while (key [i ] ) {
    int c = key [i ++ ] ; 
    h += (h << 5 ) + h + c ; 
    h2 += c ; 
  }
  * _h = h ; 
  * _h2 = h2 ; 
}
static void id_hash_indices (void * _key , long * _h , long * _h2 ) {
  /* No conversion */
  Scheme_Object * key = (Scheme_Object * ) _key ; 
  long lkey ; 
  if (((Scheme_Type ) (((((long ) (key ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (key ) ) -> type ) ) == (Scheme_Type ) (scheme_stx_type ) ) )
    key = ((Scheme_Stx * ) key ) -> val ; 
  lkey = PTR_TO_LONG ((Scheme_Object * ) key ) ; 
  * _h = (lkey >> 2 ) ; 
  * _h2 = (lkey >> 3 ) ; 
}
static int not_stx_bound_eq (char * a , char * b ) {
  /* No conversion */
  return ! scheme_stx_bound_eq ((Scheme_Object * ) a , (Scheme_Object * ) b , 0 ) ; 
}
static Scheme_Object GONE [1 ] ; 
Scheme_Hash_Table * scheme_make_hash_table (int type ) {
  Scheme_Hash_Table * table ; 
  DECL_RET_SAVE (Scheme_Hash_Table * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(table, 0)));
# define XfOrM8_COUNT (1)
# define SETUP_XfOrM8(x) SETUP(XfOrM8_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  table = NULLED_OUT ; 
  table = ((Scheme_Hash_Table * ) FUNCCALL(SETUP_XfOrM8(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Hash_Table ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  table -> size = 0 ; 
  table -> iso . so . type = scheme_hash_table_type ; 
  if (type == SCHEME_hash_string ) {
    table -> make_hash_indices = string_hash_indices ; 
    table -> compare = (Hash_Compare_Proc ) strcmp ; 
  }
  if (type == SCHEME_hash_bound_id ) {
    table -> make_hash_indices = id_hash_indices ; 
    table -> compare = (Hash_Compare_Proc ) not_stx_bound_eq ; 
  }
  RET_VALUE_START (table ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_hash (Scheme_Hash_Table * table , Scheme_Object * key , int set , Scheme_Object * val ) {
  Scheme_Object * tkey , * * keys ; 
  hash_v_t h , h2 , useme = 0 ; 
  unsigned long mask ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(tkey, 0), PUSH(keys, 1), PUSH(val, 2), PUSH(key, 3), PUSH(table, 4)));
# define XfOrM11_COUNT (5)
# define SETUP_XfOrM11(x) SETUP(XfOrM11_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  tkey = NULLED_OUT ; 
  keys = NULLED_OUT ; 
  rehash_key : mask = table -> size - 1 ; 
  if (table -> make_hash_indices ) {
#   define XfOrM44_COUNT (0+XfOrM11_COUNT)
#   define SETUP_XfOrM44(x) SETUP_XfOrM11(x)
    FUNCCALL(SETUP_XfOrM44(_), table -> make_hash_indices ((void * ) key , (long * ) & h , (long * ) & h2 ) ); 
    h = h & mask ; 
    h2 = h2 & mask ; 
  }
  else {
    unsigned long lkey ; 
#   define XfOrM43_COUNT (0+XfOrM11_COUNT)
#   define SETUP_XfOrM43(x) SETUP_XfOrM11(x)
    lkey = (unsigned long ) (PTR_TO_LONG ((Scheme_Object * ) key ) ) ; 
    h = (lkey >> 2 ) & mask ; 
    h2 = (lkey >> 3 ) & mask ; 
  }
  h2 |= 1 ; 
  keys = table -> keys ; 
  if (table -> compare ) {
    scheme_hash_request_count ++ ; 
#   define XfOrM30_COUNT (0+XfOrM11_COUNT)
#   define SETUP_XfOrM30(x) SETUP_XfOrM11(x)
    while ((tkey = keys [h ] ) ) {
#     define XfOrM37_COUNT (0+XfOrM30_COUNT)
#     define SETUP_XfOrM37(x) SETUP_XfOrM30(x)
      if (((tkey ) == (GONE ) ) ) {
        if (set > 1 ) {
          useme = h ; 
          set = 1 ; 
        }
      }
      else if (! FUNCCALL(SETUP_XfOrM37(_), table -> compare (tkey , (char * ) key ) )) {
        if (set ) {
          table -> vals [h ] = val ; 
          if (! val ) {
            keys [h ] = GONE ; 
            -- table -> count ; 
          }
          RET_VALUE_START (val ) RET_VALUE_END ; 
        }
        else RET_VALUE_START (table -> vals [h ] ) RET_VALUE_END ; 
      }
      scheme_hash_iteration_count ++ ; 
      h = (h + h2 ) & mask ; 
    }
  }
  else {
    scheme_hash_request_count ++ ; 
    while ((tkey = keys [h ] ) ) {
      if (((tkey ) == (key ) ) ) {
        if (set ) {
          table -> vals [h ] = val ; 
          if (! val ) {
            keys [h ] = GONE ; 
            -- table -> count ; 
          }
          RET_VALUE_START (val ) RET_VALUE_END ; 
        }
        else RET_VALUE_START (table -> vals [h ] ) RET_VALUE_END ; 
      }
      else if (((tkey ) == (GONE ) ) ) {
        if (set > 1 ) {
          useme = h ; 
          set = 1 ; 
        }
      }
      scheme_hash_iteration_count ++ ; 
      h = (h + h2 ) & mask ; 
    }
  }
  if (! set || ! val )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  if (set == 1 )
    h = useme ; 
  else if (table -> mcount * 1.4 >= table -> size ) {
    int i , oldsize = table -> size , size ; 
    Scheme_Object * * oldkeys = table -> keys ; 
    Scheme_Object * * oldvals = table -> vals ; 
    BLOCK_SETUP((PUSH(oldkeys, 0+XfOrM11_COUNT), PUSH(oldvals, 1+XfOrM11_COUNT)));
#   define XfOrM13_COUNT (2+XfOrM11_COUNT)
#   define SETUP_XfOrM13(x) SETUP(XfOrM13_COUNT)
    size = oldsize << 1 ; 
    table -> size = size ; 
    {
      Scheme_Object * * ba ; 
      BLOCK_SETUP((PUSH(ba, 0+XfOrM13_COUNT)));
#     define XfOrM16_COUNT (1+XfOrM13_COUNT)
#     define SETUP_XfOrM16(x) SETUP(XfOrM16_COUNT)
      ba = NULLED_OUT ; 
      ba = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM16(_), GC_malloc (sizeof (Scheme_Object * ) * (size ) ) )) ; 
      table -> vals = ba ; 
      ba = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM16(_), GC_malloc (sizeof (Scheme_Object * ) * (size ) ) )) ; 
      table -> keys = ba ; 
    }
    table -> count = 0 ; 
    table -> mcount = 0 ; 
    for (i = 0 ; i < oldsize ; i ++ ) {
#     define XfOrM15_COUNT (0+XfOrM13_COUNT)
#     define SETUP_XfOrM15(x) SETUP_XfOrM13(x)
      if (oldkeys [i ] && ! ((oldkeys [i ] ) == (GONE ) ) )
        FUNCCALL(SETUP_XfOrM15(_), do_hash (table , oldkeys [i ] , 2 , oldvals [i ] ) ); 
    }
    goto rehash_key ; 
  }
  else {
    table -> mcount ++ ; 
  }
  table -> count ++ ; 
  table -> keys [h ] = key ; 
  table -> vals [h ] = val ; 
  RET_VALUE_START (val ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * do_hash_set (Scheme_Hash_Table * table , Scheme_Object * key , Scheme_Object * val ) {
  /* No conversion */
  Scheme_Object * tkey , * * keys ; 
  hash_v_t h , h2 , useme = 0 ; 
  unsigned long mask ; 
  unsigned long lkey ; 
  int set = 2 ; 
  mask = table -> size - 1 ; 
  lkey = (unsigned long ) PTR_TO_LONG ((Scheme_Object * ) key ) ; 
  h = (lkey >> 2 ) & mask ; 
  h2 = (lkey >> 3 ) & mask ; 
  h2 |= 1 ; 
  keys = table -> keys ; 
  scheme_hash_request_count ++ ; 
  while ((tkey = keys [h ] ) ) {
    if (((tkey ) == (key ) ) ) {
      table -> vals [h ] = val ; 
      if (! val ) {
        keys [h ] = GONE ; 
        -- table -> count ; 
      }
      return val ; 
    }
    else if (((tkey ) == (GONE ) ) ) {
      if (set > 1 ) {
        useme = h ; 
        set = 1 ; 
      }
    }
    scheme_hash_iteration_count ++ ; 
    h = (h + h2 ) & mask ; 
  }
  if (! val )
    return ((void * ) 0 ) ; 
  if (set == 1 )
    h = useme ; 
  else if (table -> mcount * 1.4 >= table -> size ) {
    return do_hash (table , key , 2 , val ) ; 
  }
  else {
    table -> mcount ++ ; 
  }
  table -> count ++ ; 
  table -> keys [h ] = key ; 
  table -> vals [h ] = val ; 
  return val ; 
}
__xform_nongcing__ static Scheme_Object * do_hash_get (Scheme_Hash_Table * table , Scheme_Object * key ) {
  /* No conversion */
  Scheme_Object * tkey , * * keys ; 
  hash_v_t h , h2 ; 
  unsigned long mask ; 
  unsigned long lkey ; 
  mask = table -> size - 1 ; 
  lkey = (unsigned long ) PTR_TO_LONG ((Scheme_Object * ) key ) ; 
  h = (lkey >> 2 ) & mask ; 
  h2 = (lkey >> 3 ) & mask ; 
  h2 |= 1 ; 
  keys = table -> keys ; 
  scheme_hash_request_count ++ ; 
  while ((tkey = keys [h ] ) ) {
    if (((tkey ) == (key ) ) ) {
      return table -> vals [h ] ; 
    }
    scheme_hash_iteration_count ++ ; 
    h = (h + h2 ) & mask ; 
  }
  return ((void * ) 0 ) ; 
}
void scheme_hash_set (Scheme_Hash_Table * table , Scheme_Object * key , Scheme_Object * val ) {
  PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(val, 0), PUSH(key, 1), PUSH(table, 2)));
# define XfOrM63_COUNT (3)
# define SETUP_XfOrM63(x) SETUP(XfOrM63_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! table -> vals ) {
    Scheme_Object * * ba ; 
    BLOCK_SETUP((PUSH(ba, 0+XfOrM63_COUNT)));
#   define XfOrM64_COUNT (1+XfOrM63_COUNT)
#   define SETUP_XfOrM64(x) SETUP(XfOrM64_COUNT)
    ba = NULLED_OUT ; 
    table -> size = 8 ; 
    ba = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM64(_), GC_malloc (sizeof (Scheme_Object * ) * (table -> size ) ) )) ; 
    table -> vals = ba ; 
    ba = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM64(_), GC_malloc (sizeof (Scheme_Object * ) * (table -> size ) ) )) ; 
    table -> keys = ba ; 
  }
  if (table -> make_hash_indices )
    FUNCCALL(SETUP_XfOrM63(_), do_hash (table , key , 2 , val ) ); 
  else FUNCCALL_EMPTY(do_hash_set (table , key , val ) ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_hash_get (Scheme_Hash_Table * table , Scheme_Object * key ) {
  /* No conversion */
  if (! table -> vals )
    return ((void * ) 0 ) ; 
  else if (table -> make_hash_indices )
    return do_hash (table , key , 0 , ((void * ) 0 ) ) ; 
  else return do_hash_get (table , key ) ; 
}
Scheme_Object * scheme_eq_hash_get (Scheme_Hash_Table * table , Scheme_Object * key ) {
  /* No conversion */
  if (! table -> vals )
    return ((void * ) 0 ) ; 
  else return do_hash_get (table , key ) ; 
}
Scheme_Object * scheme_hash_get_atomic (Scheme_Hash_Table * table , Scheme_Object * key ) {
  Scheme_Object * r ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(r, 0), PUSH(key, 1), PUSH(table, 2)));
# define XfOrM67_COUNT (3)
# define SETUP_XfOrM67(x) SETUP(XfOrM67_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  r = NULLED_OUT ; 
  FUNCCALL(SETUP_XfOrM67(_), scheme_start_atomic () ); 
  r = FUNCCALL_AGAIN(scheme_hash_get (table , key ) ); 
  FUNCCALL_AGAIN(scheme_end_atomic_no_swap () ); 
  RET_VALUE_START (r ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_hash_set_atomic (Scheme_Hash_Table * table , Scheme_Object * key , Scheme_Object * val ) {
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(val, 0), PUSH(key, 1), PUSH(table, 2)));
# define XfOrM68_COUNT (3)
# define SETUP_XfOrM68(x) SETUP(XfOrM68_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM68(_), scheme_start_atomic () ); 
  FUNCCALL_EMPTY(scheme_hash_set (table , key , val ) ); 
  FUNCCALL_EMPTY(scheme_end_atomic_no_swap () ); 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_hash_table_equal (Scheme_Hash_Table * t1 , Scheme_Hash_Table * t2 ) {
  Scheme_Object * * vals , * * keys , * v ; 
  int i ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(5);
  BLOCK_SETUP_TOP((PUSH(v, 0), PUSH(keys, 1), PUSH(vals, 2), PUSH(t2, 3), PUSH(t1, 4)));
# define XfOrM69_COUNT (5)
# define SETUP_XfOrM69(x) SETUP(XfOrM69_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  vals = NULLED_OUT ; 
  keys = NULLED_OUT ; 
  v = NULLED_OUT ; 
  if ((t1 -> count != t2 -> count ) || (t1 -> make_hash_indices != t2 -> make_hash_indices ) || (t1 -> compare != t2 -> compare ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  keys = t1 -> keys ; 
  vals = t1 -> vals ; 
  for (i = t1 -> size ; i -- ; ) {
#   define XfOrM72_COUNT (0+XfOrM69_COUNT)
#   define SETUP_XfOrM72(x) SETUP_XfOrM69(x)
    if (vals [i ] ) {
#     define XfOrM73_COUNT (0+XfOrM72_COUNT)
#     define SETUP_XfOrM73(x) SETUP_XfOrM72(x)
      v = FUNCCALL(SETUP_XfOrM73(_), scheme_hash_get (t2 , keys [i ] ) ); 
      if (! v )
        RET_VALUE_START (0 ) RET_VALUE_END ; 
      if (! FUNCCALL(SETUP_XfOrM73(_), scheme_equal (vals [i ] , v ) ))
        RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
  }
  RET_VALUE_START (1 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Hash_Table * scheme_clone_hash_table (Scheme_Hash_Table * ht ) {
  Scheme_Hash_Table * table ; 
  Scheme_Object * * ba ; 
  DECL_RET_SAVE (Scheme_Hash_Table * ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(ba, 0), PUSH(table, 1), PUSH(ht, 2)));
# define XfOrM74_COUNT (3)
# define SETUP_XfOrM74(x) SETUP(XfOrM74_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  table = NULLED_OUT ; 
  ba = NULLED_OUT ; 
  table = ((Scheme_Hash_Table * ) FUNCCALL(SETUP_XfOrM74(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Hash_Table ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  (memcpy (table , ht , sizeof (Scheme_Hash_Table ) ) ) ; 
  (& (table -> iso ) ) -> so . keyex = 0 ; 
  if (table -> size ) {
#   define XfOrM76_COUNT (0+XfOrM74_COUNT)
#   define SETUP_XfOrM76(x) SETUP_XfOrM74(x)
    ba = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM76(_), GC_malloc (sizeof (Scheme_Object * ) * (table -> size ) ) )) ; 
    (memcpy (ba , table -> vals , sizeof (Scheme_Object * ) * table -> size ) ) ; 
    table -> vals = ba ; 
    ba = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM76(_), GC_malloc (sizeof (Scheme_Object * ) * (table -> size ) ) )) ; 
    (memcpy (ba , table -> keys , sizeof (Scheme_Object * ) * table -> size ) ) ; 
    table -> keys = ba ; 
  }
  if (table -> mutex ) {
    Scheme_Object * sema ; 
    BLOCK_SETUP((PUSH(sema, 0+XfOrM74_COUNT)));
#   define XfOrM75_COUNT (1+XfOrM74_COUNT)
#   define SETUP_XfOrM75(x) SETUP(XfOrM75_COUNT)
    sema = NULLED_OUT ; 
    sema = FUNCCALL(SETUP_XfOrM75(_), scheme_make_sema (1 ) ); 
    table -> mutex = sema ; 
  }
  RET_VALUE_START (table ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_reset_hash_table (Scheme_Hash_Table * table , int * history ) {
  PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(table, 0)));
# define XfOrM77_COUNT (1)
# define SETUP_XfOrM77(x) SETUP(XfOrM77_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if ((table -> size <= 8 ) || (table -> count * 1.4 > (table -> size >> 1 ) ) ) {
#   define XfOrM79_COUNT (0+XfOrM77_COUNT)
#   define SETUP_XfOrM79(x) SETUP_XfOrM77(x)
    (memset (table -> vals , 0 , sizeof (Scheme_Object * ) * table -> size ) ) ; 
    (memset (table -> keys , 0 , sizeof (Scheme_Object * ) * table -> size ) ) ; 
  }
  else {
    Scheme_Object * * ba ; 
    BLOCK_SETUP((PUSH(ba, 0+XfOrM77_COUNT)));
#   define XfOrM78_COUNT (1+XfOrM77_COUNT)
#   define SETUP_XfOrM78(x) SETUP(XfOrM78_COUNT)
    ba = NULLED_OUT ; 
    table -> size >>= 1 ; 
    ba = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM78(_), GC_malloc (sizeof (Scheme_Object * ) * (table -> size ) ) )) ; 
    (memcpy (ba , table -> vals , sizeof (Scheme_Object * ) * table -> size ) ) ; 
    table -> vals = ba ; 
    ba = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM78(_), GC_malloc (sizeof (Scheme_Object * ) * (table -> size ) ) )) ; 
    (memcpy (ba , table -> keys , sizeof (Scheme_Object * ) * table -> size ) ) ; 
    table -> keys = ba ; 
  }
  table -> count = 0 ; 
  table -> mcount = 0 ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Bucket_Table * scheme_make_bucket_table (int size , int type ) {
  Scheme_Bucket_Table * table ; 
  size_t asize ; 
  DECL_RET_SAVE (Scheme_Bucket_Table * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(table, 0)));
# define XfOrM80_COUNT (1)
# define SETUP_XfOrM80(x) SETUP(XfOrM80_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  table = NULLED_OUT ; 
  table = ((Scheme_Bucket_Table * ) FUNCCALL(SETUP_XfOrM80(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Bucket_Table ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  table -> size = 2 ; 
  while (table -> size < size ) {
    table -> size <<= 1 ; 
  }
  table -> count = 0 ; 
  table -> so . type = scheme_bucket_table_type ; 
  asize = (size_t ) table -> size * sizeof (Scheme_Bucket * ) ; 
  {
    Scheme_Bucket * * ba ; 
    BLOCK_SETUP((PUSH(ba, 0+XfOrM80_COUNT)));
#   define XfOrM81_COUNT (1+XfOrM80_COUNT)
#   define SETUP_XfOrM81(x) SETUP(XfOrM81_COUNT)
    ba = NULLED_OUT ; 
    ba = (Scheme_Bucket * * ) FUNCCALL(SETUP_XfOrM81(_), GC_malloc (asize ) ); 
    table -> buckets = ba ; 
  }
  table -> weak = (type == SCHEME_hash_weak_ptr ) ; 
  RET_VALUE_START (table ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Bucket_Table * scheme_clone_bucket_table (Scheme_Bucket_Table * bt ) {
  Scheme_Bucket_Table * table ; 
  size_t asize ; 
  DECL_RET_SAVE (Scheme_Bucket_Table * ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(table, 0), PUSH(bt, 1)));
# define XfOrM84_COUNT (2)
# define SETUP_XfOrM84(x) SETUP(XfOrM84_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  table = NULLED_OUT ; 
  table = ((Scheme_Bucket_Table * ) FUNCCALL(SETUP_XfOrM84(_), GC_malloc_one_small_tagged ((((sizeof (Scheme_Bucket_Table ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
  table -> so . type = scheme_bucket_table_type ; 
  table -> size = bt -> size ; 
  table -> count = bt -> count ; 
  table -> weak = bt -> weak ; 
  table -> with_home = 0 ; 
  table -> make_hash_indices = bt -> make_hash_indices ; 
  table -> compare = bt -> compare ; 
  if (bt -> mutex ) {
    Scheme_Object * sema ; 
    BLOCK_SETUP((PUSH(sema, 0+XfOrM84_COUNT)));
#   define XfOrM86_COUNT (1+XfOrM84_COUNT)
#   define SETUP_XfOrM86(x) SETUP(XfOrM86_COUNT)
    sema = NULLED_OUT ; 
    sema = FUNCCALL(SETUP_XfOrM86(_), scheme_make_sema (1 ) ); 
    table -> mutex = sema ; 
  }
  {
    Scheme_Bucket * * ba ; 
    BLOCK_SETUP((PUSH(ba, 0+XfOrM84_COUNT)));
#   define XfOrM85_COUNT (1+XfOrM84_COUNT)
#   define SETUP_XfOrM85(x) SETUP(XfOrM85_COUNT)
    ba = NULLED_OUT ; 
    asize = (size_t ) table -> size * sizeof (Scheme_Bucket * ) ; 
    ba = (Scheme_Bucket * * ) FUNCCALL(SETUP_XfOrM85(_), GC_malloc (asize ) ); 
    table -> buckets = ba ; 
    (memcpy (ba , bt -> buckets , asize ) ) ; 
  }
  RET_VALUE_START (table ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Bucket * get_bucket (Scheme_Bucket_Table * table , const char * key , int add , Scheme_Bucket * b ) {
  hash_v_t h , h2 ; 
  Scheme_Bucket * bucket ; 
  Compare_Proc compare = table -> compare ; 
  unsigned long mask ; 
  DECL_RET_SAVE (Scheme_Bucket * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(bucket, 0), PUSH(table, 1), PUSH(key, 2), PUSH(b, 3)));
# define XfOrM87_COUNT (4)
# define SETUP_XfOrM87(x) SETUP(XfOrM87_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  bucket = NULLED_OUT ; 
  rehash_key : mask = table -> size - 1 ; 
  if (table -> make_hash_indices ) {
#   define XfOrM120_COUNT (0+XfOrM87_COUNT)
#   define SETUP_XfOrM120(x) SETUP_XfOrM87(x)
    FUNCCALL(SETUP_XfOrM120(_), table -> make_hash_indices ((void * ) key , (long * ) & h , (long * ) & h2 ) ); 
    h = h & mask ; 
    h2 = h2 & mask ; 
  }
  else {
    unsigned long lkey ; 
#   define XfOrM119_COUNT (0+XfOrM87_COUNT)
#   define SETUP_XfOrM119(x) SETUP_XfOrM87(x)
    lkey = (unsigned long ) (PTR_TO_LONG ((Scheme_Object * ) key ) ) ; 
    h = (lkey >> 2 ) & mask ; 
    h2 = (lkey >> 3 ) & mask ; 
  }
  h2 |= 0x1 ; 
  if (table -> weak ) {
    scheme_hash_request_count ++ ; 
#   define XfOrM110_COUNT (0+XfOrM87_COUNT)
#   define SETUP_XfOrM110(x) SETUP_XfOrM87(x)
    while ((bucket = table -> buckets [h ] ) ) {
#     define XfOrM115_COUNT (0+XfOrM110_COUNT)
#     define SETUP_XfOrM115(x) SETUP_XfOrM110(x)
      if (bucket -> key ) {
        void * hk = (void * ) (((Scheme_Small_Object * ) (bucket -> key ) ) -> u . ptr_val ) ; 
#       define XfOrM116_COUNT (0+XfOrM115_COUNT)
#       define SETUP_XfOrM116(x) SETUP_XfOrM115(x)
        if (! hk ) {
          if (add ) {
            -- table -> count ; 
            break ; 
          }
        }
        else if (((hk ) == (key ) ) )
          RET_VALUE_START (bucket ) RET_VALUE_END ; 
        else if (compare && ! FUNCCALL(SETUP_XfOrM116(_), compare ((void * ) hk , (void * ) key ) ))
          RET_VALUE_START (bucket ) RET_VALUE_END ; 
      }
      else if (add )
        break ; 
      scheme_hash_iteration_count ++ ; 
      h = (h + h2 ) & mask ; 
    }
  }
  else {
    scheme_hash_request_count ++ ; 
#   define XfOrM107_COUNT (0+XfOrM87_COUNT)
#   define SETUP_XfOrM107(x) SETUP_XfOrM87(x)
    while ((bucket = table -> buckets [h ] ) ) {
#     define XfOrM109_COUNT (0+XfOrM107_COUNT)
#     define SETUP_XfOrM109(x) SETUP_XfOrM107(x)
      if (((bucket -> key ) == (key ) ) )
        RET_VALUE_START (bucket ) RET_VALUE_END ; 
      else if (compare && ! FUNCCALL(SETUP_XfOrM109(_), compare ((void * ) bucket -> key , (void * ) key ) ))
        RET_VALUE_START (bucket ) RET_VALUE_END ; 
      scheme_hash_iteration_count ++ ; 
      h = (h + h2 ) & mask ; 
    }
  }
  if (! add )
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  if (table -> count * 1.4 >= table -> size ) {
    int i , oldsize = table -> size ; 
    size_t asize ; 
    Scheme_Bucket * * old = table -> buckets ; 
    BLOCK_SETUP((PUSH(old, 0+XfOrM87_COUNT)));
#   define XfOrM93_COUNT (1+XfOrM87_COUNT)
#   define SETUP_XfOrM93(x) SETUP(XfOrM93_COUNT)
    if (table -> weak && (table -> size > 4096 ) ) {
      int actual = 0 ; 
#     define XfOrM101_COUNT (0+XfOrM93_COUNT)
#     define SETUP_XfOrM101(x) SETUP_XfOrM93(x)
      FUNCCALL(SETUP_XfOrM101(_), scheme_collect_garbage () ); 
      for (i = 0 ; i < oldsize ; i ++ ) {
        if (old [i ] && old [i ] -> key && (((Scheme_Small_Object * ) (old [i ] -> key ) ) -> u . ptr_val ) ) {
          actual ++ ; 
        }
      }
      if (actual * 1.4 < table -> count ) {
        table -> size >>= 1 ; 
      }
    }
    table -> size <<= 1 ; 
    asize = (size_t ) table -> size * sizeof (Scheme_Bucket * ) ; 
    {
      Scheme_Bucket * * ba ; 
      BLOCK_SETUP((PUSH(ba, 0+XfOrM93_COUNT)));
#     define XfOrM100_COUNT (1+XfOrM93_COUNT)
#     define SETUP_XfOrM100(x) SETUP(XfOrM100_COUNT)
      ba = NULLED_OUT ; 
      ba = (Scheme_Bucket * * ) FUNCCALL(SETUP_XfOrM100(_), GC_malloc (asize ) ); 
      table -> buckets = ba ; 
    }
    table -> count = 0 ; 
    if (table -> weak ) {
#     define XfOrM97_COUNT (0+XfOrM93_COUNT)
#     define SETUP_XfOrM97(x) SETUP_XfOrM93(x)
      for (i = 0 ; i < oldsize ; i ++ ) {
#       define XfOrM99_COUNT (0+XfOrM97_COUNT)
#       define SETUP_XfOrM99(x) SETUP_XfOrM97(x)
        if (old [i ] && old [i ] -> key && (((Scheme_Small_Object * ) (old [i ] -> key ) ) -> u . ptr_val ) )
          FUNCCALL(SETUP_XfOrM99(_), get_bucket (table , (char * ) (((Scheme_Small_Object * ) (old [i ] -> key ) ) -> u . ptr_val ) , 1 , old [i ] ) ); 
      }
    }
    else {
#     define XfOrM94_COUNT (0+XfOrM93_COUNT)
#     define SETUP_XfOrM94(x) SETUP_XfOrM93(x)
      for (i = 0 ; i < oldsize ; i ++ ) {
#       define XfOrM96_COUNT (0+XfOrM94_COUNT)
#       define SETUP_XfOrM96(x) SETUP_XfOrM94(x)
        if (old [i ] && old [i ] -> key )
          FUNCCALL(SETUP_XfOrM96(_), get_bucket (table , old [i ] -> key , 1 , old [i ] ) ); 
      }
    }
    goto rehash_key ; 
  }
  if (b ) {
    bucket = b ; 
  }
  else {
    size_t bsize ; 
    Scheme_Type type ; 
#   define XfOrM88_COUNT (0+XfOrM87_COUNT)
#   define SETUP_XfOrM88(x) SETUP_XfOrM87(x)
    if (table -> with_home ) {
      bsize = sizeof (Scheme_Bucket_With_Home ) ; 
      type = scheme_variable_type ; 
    }
    else {
      bsize = sizeof (Scheme_Bucket ) ; 
      type = scheme_bucket_type ; 
    }
    bucket = (Scheme_Bucket * ) FUNCCALL(SETUP_XfOrM88(_), GC_malloc_one_tagged (bsize ) ); 
    bucket -> so . type = type ; 
    if (type == scheme_variable_type )
      ((Scheme_Bucket_With_Flags * ) bucket ) -> flags = 32 ; 
    if (table -> weak ) {
      void * kb ; 
      BLOCK_SETUP((PUSH(kb, 0+XfOrM88_COUNT)));
#     define XfOrM89_COUNT (1+XfOrM88_COUNT)
#     define SETUP_XfOrM89(x) SETUP(XfOrM89_COUNT)
      kb = NULLED_OUT ; 
      kb = FUNCCALL(SETUP_XfOrM89(_), GC_malloc_weak_box ((void * ) key , (void * * ) bucket , (void * * ) & bucket -> val - (void * * ) bucket ) ); 
      bucket -> key = (char * ) kb ; 
    }
    else bucket -> key = (char * ) key ; 
    bucket -> val = ((void * ) 0 ) ; 
  }
  table -> buckets [h ] = bucket ; 
  table -> count ++ ; 
  RET_VALUE_START (bucket ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Bucket * scheme_bucket_or_null_from_table (Scheme_Bucket_Table * table , const char * key , int add ) {
  Scheme_Bucket * b ; 
  DECL_RET_SAVE (Scheme_Bucket * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(b, 0)));
# define XfOrM121_COUNT (1)
# define SETUP_XfOrM121(x) SETUP(XfOrM121_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  b = NULLED_OUT ; 
  b = FUNCCALL(SETUP_XfOrM121(_), get_bucket (table , key , add , ((void * ) 0 ) ) ); 
  RET_VALUE_START (b ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Bucket * scheme_bucket_from_table (Scheme_Bucket_Table * table , const char * key ) {
  /* No conversion */
  return scheme_bucket_or_null_from_table (table , key , 1 ) ; 
}
void scheme_add_to_table (Scheme_Bucket_Table * table , const char * key , void * val , int constant ) {
  Scheme_Bucket * b ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(b, 0), PUSH(val, 1), PUSH(table, 2)));
# define XfOrM123_COUNT (3)
# define SETUP_XfOrM123(x) SETUP(XfOrM123_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  b = NULLED_OUT ; 
  b = FUNCCALL(SETUP_XfOrM123(_), get_bucket (table , key , 1 , ((void * ) 0 ) ) ); 
  if (val )
    b -> val = val ; 
  if (constant && table -> with_home )
    ((Scheme_Bucket_With_Flags * ) b ) -> flags |= 1 ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_add_bucket_to_table (Scheme_Bucket_Table * table , Scheme_Bucket * b ) {
  /* No conversion */
  get_bucket (table , table -> weak ? (char * ) (((Scheme_Small_Object * ) (b -> key ) ) -> u . ptr_val ) : b -> key , 1 , b ) ; 
}
void * scheme_lookup_in_table (Scheme_Bucket_Table * table , const char * key ) {
  Scheme_Bucket * bucket ; 
  DECL_RET_SAVE (void * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(bucket, 0)));
# define XfOrM125_COUNT (1)
# define SETUP_XfOrM125(x) SETUP(XfOrM125_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  bucket = NULLED_OUT ; 
  bucket = FUNCCALL(SETUP_XfOrM125(_), get_bucket (table , key , 0 , ((void * ) 0 ) ) ); 
  if (bucket )
    RET_VALUE_START (bucket -> val ) RET_VALUE_END ; 
  else RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_change_in_table (Scheme_Bucket_Table * table , const char * key , void * naya ) {
  Scheme_Bucket * bucket ; 
  PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(naya, 0), PUSH(bucket, 1)));
# define XfOrM126_COUNT (2)
# define SETUP_XfOrM126(x) SETUP(XfOrM126_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  bucket = NULLED_OUT ; 
  bucket = FUNCCALL(SETUP_XfOrM126(_), get_bucket (table , key , 0 , ((void * ) 0 ) ) ); 
  if (bucket )
    bucket -> val = naya ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_bucket_table_equal (Scheme_Bucket_Table * t1 , Scheme_Bucket_Table * t2 ) {
  Scheme_Bucket * * buckets , * bucket ; 
  void * v ; 
  const char * key ; 
  int i , weak , checked = 0 ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(6);
  BLOCK_SETUP_TOP((PUSH(buckets, 0), PUSH(bucket, 1), PUSH(v, 2), PUSH(key, 3), PUSH(t2, 4), PUSH(t1, 5)));
# define XfOrM127_COUNT (6)
# define SETUP_XfOrM127(x) SETUP(XfOrM127_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  buckets = NULLED_OUT ; 
  bucket = NULLED_OUT ; 
  v = NULLED_OUT ; 
  key = NULLED_OUT ; 
  if ((t1 -> weak != t2 -> weak ) || (t1 -> make_hash_indices != t2 -> make_hash_indices ) || (t1 -> compare != t2 -> compare ) )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  buckets = t1 -> buckets ; 
  weak = t1 -> weak ; 
  for (i = t1 -> size ; i -- ; ) {
#   define XfOrM143_COUNT (0+XfOrM127_COUNT)
#   define SETUP_XfOrM143(x) SETUP_XfOrM127(x)
    bucket = buckets [i ] ; 
    if (bucket ) {
#     define XfOrM144_COUNT (0+XfOrM143_COUNT)
#     define SETUP_XfOrM144(x) SETUP_XfOrM143(x)
      if (weak ) {
        key = (const char * ) (((Scheme_Small_Object * ) (bucket -> key ) ) -> u . ptr_val ) ; 
      }
      else {
        key = bucket -> key ; 
      }
      if (key ) {
        checked ++ ; 
#       define XfOrM145_COUNT (0+XfOrM144_COUNT)
#       define SETUP_XfOrM145(x) SETUP_XfOrM144(x)
        v = FUNCCALL(SETUP_XfOrM145(_), scheme_lookup_in_table (t2 , key ) ); 
        if (! v )
          RET_VALUE_START (0 ) RET_VALUE_END ; 
        if (! FUNCCALL(SETUP_XfOrM145(_), scheme_equal ((Scheme_Object * ) bucket -> val , (Scheme_Object * ) v ) ))
          RET_VALUE_START (0 ) RET_VALUE_END ; 
      }
    }
  }
  if (t2 -> count == checked )
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  buckets = t2 -> buckets ; 
  weak = t2 -> weak ; 
  for (i = t2 -> size ; i -- ; ) {
    bucket = buckets [i ] ; 
    if (bucket ) {
      if (weak ) {
        key = (const char * ) (((Scheme_Small_Object * ) (bucket -> key ) ) -> u . ptr_val ) ; 
      }
      else {
        key = bucket -> key ; 
      }
      if (key ) {
        if (! checked )
          RET_VALUE_START (0 ) RET_VALUE_END ; 
        -- checked ; 
      }
    }
  }
  RET_VALUE_START (! checked ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_init_hash_key_procs (void ) {
}
long scheme_hash_key (Scheme_Object * o ) {
  return PTR_TO_LONG (o ) ; 
}
static long equal_hash_key (Scheme_Object * o , long k ) ; 
static Scheme_Object * hash_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * v = (Scheme_Object * ) p -> ku . k . p1 ; 
  long nv ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  nv = equal_hash_key (v , p -> ku . k . i1 ) ; 
  return scheme_make_integer_value (nv ) ; 
}
static long equal_hash_key (Scheme_Object * o , long k ) {
  Scheme_Type t ; 
  static int hash_counter = 20 ; 
  Scheme_Object * __funcarg5 = NULLED_OUT ; 
  Scheme_Config * __funcarg4 = NULLED_OUT ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(o, 0)));
# define XfOrM149_COUNT (1)
# define SETUP_XfOrM149(x) SETUP(XfOrM149_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  top : t = ((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ; 
  k += t ; 
  switch (t ) {
#   define XfOrM150_COUNT (0+XfOrM149_COUNT)
#   define SETUP_XfOrM150(x) SETUP_XfOrM149(x)
    case scheme_integer_type : RET_VALUE_START (k + (((long ) (o ) ) >> 1 ) ) RET_VALUE_END ; 
    case scheme_double_type : {
      double d ; 
      int e ; 
#     define XfOrM219_COUNT (0+XfOrM150_COUNT)
#     define SETUP_XfOrM219(x) SETUP_XfOrM150(x)
      d = (((Scheme_Double * ) (o ) ) -> double_val ) ; 
      if (isnan (d ) ) {
        d = 0.0 ; 
        e = 1000 ; 
      }
      else if ((isinf (d ) && (d > 0 ) ) ) {
        d = 0.5 ; 
        e = 1000 ; 
      }
      else if ((isinf (d ) && (d < 0 ) ) ) {
        d = - 0.5 ; 
        e = 1000 ; 
      }
      else if (! d && (scheme_minus_zero_p (d ) ) ) {
        d = 0 ; 
        e = 1000 ; 
      }
      else {
#       define XfOrM220_COUNT (0+XfOrM219_COUNT)
#       define SETUP_XfOrM220(x) SETUP_XfOrM219(x)
        d = FUNCCALL(SETUP_XfOrM220(_), frexp (d , & e ) ); 
      }
      RET_VALUE_START (k + ((long ) (d * (1 << 30 ) ) ) + e ) RET_VALUE_END ; 
    }
    case scheme_bignum_type : {
      int i = (((Scheme_Bignum * ) o ) -> len ) ; 
      bigdig * d = (((Scheme_Bignum * ) o ) -> digits ) , k2 ; 
      k2 = k ; 
      while (i -- ) {
        k2 = (k2 << 3 ) + k2 + d [i ] ; 
      }
      RET_VALUE_START ((long ) k2 ) RET_VALUE_END ; 
    }
    break ; 
    case scheme_rational_type : {
#     define XfOrM215_COUNT (0+XfOrM150_COUNT)
#     define SETUP_XfOrM215(x) SETUP_XfOrM150(x)
      k += (__funcarg5 = FUNCCALL(SETUP_XfOrM215(_), scheme_rational_numerator (o ) ), FUNCCALL_AGAIN(equal_hash_key (__funcarg5 , 0 ) )) ; 
      o = FUNCCALL(SETUP_XfOrM215(_), scheme_rational_denominator (o ) ); 
      break ; 
    }
    case scheme_complex_type : case scheme_complex_izi_type : {
      Scheme_Complex * c = (Scheme_Complex * ) o ; 
      BLOCK_SETUP((PUSH(c, 0+XfOrM150_COUNT)));
#     define XfOrM214_COUNT (1+XfOrM150_COUNT)
#     define SETUP_XfOrM214(x) SETUP(XfOrM214_COUNT)
      k += FUNCCALL(SETUP_XfOrM214(_), equal_hash_key (c -> r , 0 ) ); 
      o = c -> i ; 
      break ; 
    }
    case scheme_pair_type : {
#     define XfOrM208_COUNT (0+XfOrM150_COUNT)
#     define SETUP_XfOrM208(x) SETUP_XfOrM150(x)
      if (! -- hash_counter ) {
#       define XfOrM209_COUNT (0+XfOrM208_COUNT)
#       define SETUP_XfOrM209(x) SETUP_XfOrM208(x)
        hash_counter = 20 ; 
        {
#         define XfOrM212_COUNT (0+XfOrM209_COUNT)
#         define SETUP_XfOrM212(x) SETUP_XfOrM209(x)
          if ((scheme_fuel_counter ) <= 0 ) {
#           define XfOrM213_COUNT (0+XfOrM212_COUNT)
#           define SETUP_XfOrM213(x) SETUP_XfOrM212(x)
            FUNCCALL(SETUP_XfOrM213(_), scheme_out_of_fuel () ); 
          }
        }
        ; 
        {
          unsigned long _stk_pos ; 
#         define XfOrM210_COUNT (0+XfOrM209_COUNT)
#         define SETUP_XfOrM210(x) SETUP_XfOrM209(x)
          _stk_pos = (unsigned long ) & _stk_pos ; 
          if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
            Scheme_Object * nv ; 
            long val ; 
            Scheme_Thread * p = scheme_current_thread ; 
            BLOCK_SETUP((PUSH(nv, 0+XfOrM210_COUNT)));
#           define XfOrM211_COUNT (1+XfOrM210_COUNT)
#           define SETUP_XfOrM211(x) SETUP(XfOrM211_COUNT)
            nv = NULLED_OUT ; 
            p -> ku . k . p1 = (void * ) o ; 
            p -> ku . k . i1 = (k - t ) ; 
            nv = FUNCCALL(SETUP_XfOrM211(_), scheme_handle_stack_overflow (hash_k ) ); 
            (scheme_get_int_val (nv , & val ) ) ; 
            RET_VALUE_START (val ) RET_VALUE_END ; 
          }
        }
      }
      k += FUNCCALL(SETUP_XfOrM208(_), equal_hash_key ((((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . car ) , 0 ) ); 
      o = (((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . cdr ) ; 
      break ; 
    }
    case scheme_vector_type : case scheme_wrap_chunk_type : {
      int len = (((Scheme_Vector * ) (o ) ) -> size ) , i , val ; 
#     define XfOrM196_COUNT (0+XfOrM150_COUNT)
#     define SETUP_XfOrM196(x) SETUP_XfOrM150(x)
      if (! -- hash_counter ) {
#       define XfOrM203_COUNT (0+XfOrM196_COUNT)
#       define SETUP_XfOrM203(x) SETUP_XfOrM196(x)
        hash_counter = 20 ; 
        {
#         define XfOrM206_COUNT (0+XfOrM203_COUNT)
#         define SETUP_XfOrM206(x) SETUP_XfOrM203(x)
          if ((scheme_fuel_counter ) <= 0 ) {
#           define XfOrM207_COUNT (0+XfOrM206_COUNT)
#           define SETUP_XfOrM207(x) SETUP_XfOrM206(x)
            FUNCCALL(SETUP_XfOrM207(_), scheme_out_of_fuel () ); 
          }
        }
        ; 
        {
          unsigned long _stk_pos ; 
#         define XfOrM204_COUNT (0+XfOrM203_COUNT)
#         define SETUP_XfOrM204(x) SETUP_XfOrM203(x)
          _stk_pos = (unsigned long ) & _stk_pos ; 
          if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
            Scheme_Object * nv ; 
            long val ; 
            Scheme_Thread * p = scheme_current_thread ; 
            BLOCK_SETUP((PUSH(nv, 0+XfOrM204_COUNT)));
#           define XfOrM205_COUNT (1+XfOrM204_COUNT)
#           define SETUP_XfOrM205(x) SETUP(XfOrM205_COUNT)
            nv = NULLED_OUT ; 
            p -> ku . k . p1 = (void * ) o ; 
            p -> ku . k . i1 = (k - t ) ; 
            nv = FUNCCALL(SETUP_XfOrM205(_), scheme_handle_stack_overflow (hash_k ) ); 
            (scheme_get_int_val (nv , & val ) ) ; 
            RET_VALUE_START (val ) RET_VALUE_END ; 
          }
        }
      }
      if (! len )
        RET_VALUE_START (k + 1 ) RET_VALUE_END ; 
      -- len ; 
      for (i = 0 ; i < len ; i ++ ) {
#       define XfOrM200_COUNT (0+XfOrM196_COUNT)
#       define SETUP_XfOrM200(x) SETUP_XfOrM196(x)
        {
#         define XfOrM201_COUNT (0+XfOrM200_COUNT)
#         define SETUP_XfOrM201(x) SETUP_XfOrM200(x)
          if ((scheme_fuel_counter ) <= 0 ) {
#           define XfOrM202_COUNT (0+XfOrM201_COUNT)
#           define SETUP_XfOrM202(x) SETUP_XfOrM201(x)
            FUNCCALL(SETUP_XfOrM202(_), scheme_out_of_fuel () ); 
          }
        }
        ; 
        val = FUNCCALL(SETUP_XfOrM200(_), equal_hash_key ((((Scheme_Vector * ) (o ) ) -> els ) [i ] , 0 ) ); 
        k = (k << 5 ) + k + val ; 
      }
      o = (((Scheme_Vector * ) (o ) ) -> els ) [len ] ; 
      break ; 
    }
    case scheme_char_type : RET_VALUE_START (k + (((Scheme_Small_Object * ) (o ) ) -> u . char_val ) ) RET_VALUE_END ; 
    case scheme_byte_string_type : case scheme_unix_path_type : case scheme_windows_path_type : {
      int i = (((Scheme_Simple_Object * ) (o ) ) -> u . byte_str_val . tag_val ) ; 
      char * s = (((Scheme_Simple_Object * ) (o ) ) -> u . byte_str_val . string_val ) ; 
      while (i -- ) {
        k += s [i ] ; 
        (k += (k << 10 ) , k ^= (k >> 6 ) ) ; 
      }
      RET_VALUE_START (k ) RET_VALUE_END ; 
    }
    case scheme_char_string_type : {
      int i = (((Scheme_Simple_Object * ) (o ) ) -> u . char_str_val . tag_val ) ; 
      mzchar * s = (((Scheme_Simple_Object * ) (o ) ) -> u . char_str_val . string_val ) ; 
      while (i -- ) {
        k += s [i ] ; 
        (k += (k << 10 ) , k ^= (k >> 6 ) ) ; 
      }
      RET_VALUE_START (k ) RET_VALUE_END ; 
    }
    case scheme_structure_type : case scheme_proc_struct_type : {
      Scheme_Object * insp ; 
      BLOCK_SETUP((PUSH(insp, 0+XfOrM150_COUNT)));
#     define XfOrM181_COUNT (1+XfOrM150_COUNT)
#     define SETUP_XfOrM181(x) SETUP(XfOrM181_COUNT)
      insp = NULLED_OUT ; 
      insp = (__funcarg4 = FUNCCALL(SETUP_XfOrM181(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg4 , MZCONFIG_INSPECTOR ) )) ; 
      if (FUNCCALL(SETUP_XfOrM181(_), scheme_inspector_sees_part (o , insp , - 2 ) )) {
        int i ; 
        Scheme_Structure * s1 = (Scheme_Structure * ) o ; 
        BLOCK_SETUP((PUSH(s1, 0+XfOrM181_COUNT)));
#       define XfOrM182_COUNT (1+XfOrM181_COUNT)
#       define SETUP_XfOrM182(x) SETUP(XfOrM182_COUNT)
        if (! -- hash_counter ) {
#         define XfOrM185_COUNT (0+XfOrM182_COUNT)
#         define SETUP_XfOrM185(x) SETUP_XfOrM182(x)
          hash_counter = 20 ; 
          {
#           define XfOrM188_COUNT (0+XfOrM185_COUNT)
#           define SETUP_XfOrM188(x) SETUP_XfOrM185(x)
            if ((scheme_fuel_counter ) <= 0 ) {
#             define XfOrM189_COUNT (0+XfOrM188_COUNT)
#             define SETUP_XfOrM189(x) SETUP_XfOrM188(x)
              FUNCCALL(SETUP_XfOrM189(_), scheme_out_of_fuel () ); 
            }
          }
          ; 
          {
            unsigned long _stk_pos ; 
#           define XfOrM186_COUNT (0+XfOrM185_COUNT)
#           define SETUP_XfOrM186(x) SETUP_XfOrM185(x)
            _stk_pos = (unsigned long ) & _stk_pos ; 
            if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
              Scheme_Object * nv ; 
              long val ; 
              Scheme_Thread * p = scheme_current_thread ; 
              BLOCK_SETUP((PUSH(nv, 0+XfOrM186_COUNT)));
#             define XfOrM187_COUNT (1+XfOrM186_COUNT)
#             define SETUP_XfOrM187(x) SETUP(XfOrM187_COUNT)
              nv = NULLED_OUT ; 
              p -> ku . k . p1 = (void * ) o ; 
              p -> ku . k . i1 = (k - t ) ; 
              nv = FUNCCALL(SETUP_XfOrM187(_), scheme_handle_stack_overflow (hash_k ) ); 
              (scheme_get_int_val (nv , & val ) ) ; 
              RET_VALUE_START (val ) RET_VALUE_END ; 
            }
          }
        }
        for (i = ((((Scheme_Structure * ) s1 ) -> stype ) -> num_slots ) ; i -- ; ) {
#         define XfOrM184_COUNT (0+XfOrM182_COUNT)
#         define SETUP_XfOrM184(x) SETUP_XfOrM182(x)
          k += FUNCCALL(SETUP_XfOrM184(_), equal_hash_key (s1 -> slots [i ] , 0 ) ); 
          (k += (k << 10 ) , k ^= (k >> 6 ) ) ; 
        }
        RET_VALUE_START (k ) RET_VALUE_END ; 
      }
      else RET_VALUE_START (k + ((PTR_TO_LONG (o ) ) >> 4 ) ) RET_VALUE_END ; 
      break ; 
    }
    case scheme_box_type : {
#     define XfOrM178_COUNT (0+XfOrM150_COUNT)
#     define SETUP_XfOrM178(x) SETUP_XfOrM150(x)
      {
#       define XfOrM179_COUNT (0+XfOrM178_COUNT)
#       define SETUP_XfOrM179(x) SETUP_XfOrM178(x)
        if ((scheme_fuel_counter ) <= 0 ) {
#         define XfOrM180_COUNT (0+XfOrM179_COUNT)
#         define SETUP_XfOrM180(x) SETUP_XfOrM179(x)
          FUNCCALL(SETUP_XfOrM180(_), scheme_out_of_fuel () ); 
        }
      }
      ; 
      k += 1 ; 
      o = (((Scheme_Small_Object * ) (o ) ) -> u . ptr_val ) ; 
      break ; 
    }
    case scheme_hash_table_type : {
      Scheme_Hash_Table * ht = (Scheme_Hash_Table * ) o ; 
      Scheme_Object * * vals , * * keys ; 
      int i ; 
      long vk ; 
      BLOCK_SETUP((PUSH(keys, 0+XfOrM150_COUNT), PUSH(vals, 1+XfOrM150_COUNT), PUSH(ht, 2+XfOrM150_COUNT)));
#     define XfOrM168_COUNT (3+XfOrM150_COUNT)
#     define SETUP_XfOrM168(x) SETUP(XfOrM168_COUNT)
      vals = NULLED_OUT ; 
      keys = NULLED_OUT ; 
      if (! -- hash_counter ) {
#       define XfOrM173_COUNT (0+XfOrM168_COUNT)
#       define SETUP_XfOrM173(x) SETUP_XfOrM168(x)
        hash_counter = 20 ; 
        {
#         define XfOrM176_COUNT (0+XfOrM173_COUNT)
#         define SETUP_XfOrM176(x) SETUP_XfOrM173(x)
          if ((scheme_fuel_counter ) <= 0 ) {
#           define XfOrM177_COUNT (0+XfOrM176_COUNT)
#           define SETUP_XfOrM177(x) SETUP_XfOrM176(x)
            FUNCCALL(SETUP_XfOrM177(_), scheme_out_of_fuel () ); 
          }
        }
        ; 
        {
          unsigned long _stk_pos ; 
#         define XfOrM174_COUNT (0+XfOrM173_COUNT)
#         define SETUP_XfOrM174(x) SETUP_XfOrM173(x)
          _stk_pos = (unsigned long ) & _stk_pos ; 
          if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
            Scheme_Object * nv ; 
            long val ; 
            Scheme_Thread * p = scheme_current_thread ; 
            BLOCK_SETUP((PUSH(nv, 0+XfOrM174_COUNT)));
#           define XfOrM175_COUNT (1+XfOrM174_COUNT)
#           define SETUP_XfOrM175(x) SETUP(XfOrM175_COUNT)
            nv = NULLED_OUT ; 
            p -> ku . k . p1 = (void * ) o ; 
            p -> ku . k . i1 = (k - t ) ; 
            nv = FUNCCALL(SETUP_XfOrM175(_), scheme_handle_stack_overflow (hash_k ) ); 
            (scheme_get_int_val (nv , & val ) ) ; 
            RET_VALUE_START (val ) RET_VALUE_END ; 
          }
        }
      }
      k = (k << 1 ) + 3 ; 
      keys = ht -> keys ; 
      vals = ht -> vals ; 
      for (i = ht -> size ; i -- ; ) {
#       define XfOrM171_COUNT (0+XfOrM168_COUNT)
#       define SETUP_XfOrM171(x) SETUP_XfOrM168(x)
        if (vals [i ] ) {
#         define XfOrM172_COUNT (0+XfOrM171_COUNT)
#         define SETUP_XfOrM172(x) SETUP_XfOrM171(x)
          vk = FUNCCALL(SETUP_XfOrM172(_), equal_hash_key (keys [i ] , 0 ) ); 
          (vk += (vk << 10 ) , vk ^= (vk >> 6 ) ) ; 
          vk += FUNCCALL(SETUP_XfOrM172(_), equal_hash_key (vals [i ] , 0 ) ); 
          (vk += (vk << 10 ) , vk ^= (vk >> 6 ) ) ; 
          k += vk ; 
        }
      }
      RET_VALUE_START (k ) RET_VALUE_END ; 
    }
    case scheme_bucket_table_type : {
      Scheme_Bucket_Table * ht = (Scheme_Bucket_Table * ) o ; 
      Scheme_Bucket * * buckets , * bucket ; 
      const char * key ; 
      int i , weak ; 
      long vk ; 
      BLOCK_SETUP((PUSH(bucket, 0+XfOrM150_COUNT), PUSH(buckets, 1+XfOrM150_COUNT), PUSH(key, 2+XfOrM150_COUNT), PUSH(ht, 3+XfOrM150_COUNT)));
#     define XfOrM152_COUNT (4+XfOrM150_COUNT)
#     define SETUP_XfOrM152(x) SETUP(XfOrM152_COUNT)
      buckets = NULLED_OUT ; 
      bucket = NULLED_OUT ; 
      key = NULLED_OUT ; 
      if (! -- hash_counter ) {
#       define XfOrM163_COUNT (0+XfOrM152_COUNT)
#       define SETUP_XfOrM163(x) SETUP_XfOrM152(x)
        hash_counter = 20 ; 
        {
#         define XfOrM166_COUNT (0+XfOrM163_COUNT)
#         define SETUP_XfOrM166(x) SETUP_XfOrM163(x)
          if ((scheme_fuel_counter ) <= 0 ) {
#           define XfOrM167_COUNT (0+XfOrM166_COUNT)
#           define SETUP_XfOrM167(x) SETUP_XfOrM166(x)
            FUNCCALL(SETUP_XfOrM167(_), scheme_out_of_fuel () ); 
          }
        }
        ; 
        {
          unsigned long _stk_pos ; 
#         define XfOrM164_COUNT (0+XfOrM163_COUNT)
#         define SETUP_XfOrM164(x) SETUP_XfOrM163(x)
          _stk_pos = (unsigned long ) & _stk_pos ; 
          if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
            Scheme_Object * nv ; 
            long val ; 
            Scheme_Thread * p = scheme_current_thread ; 
            BLOCK_SETUP((PUSH(nv, 0+XfOrM164_COUNT)));
#           define XfOrM165_COUNT (1+XfOrM164_COUNT)
#           define SETUP_XfOrM165(x) SETUP(XfOrM165_COUNT)
            nv = NULLED_OUT ; 
            p -> ku . k . p1 = (void * ) o ; 
            p -> ku . k . i1 = (k - t ) ; 
            nv = FUNCCALL(SETUP_XfOrM165(_), scheme_handle_stack_overflow (hash_k ) ); 
            (scheme_get_int_val (nv , & val ) ) ; 
            RET_VALUE_START (val ) RET_VALUE_END ; 
          }
        }
      }
      buckets = ht -> buckets ; 
      weak = ht -> weak ; 
      k = (k << 1 ) + 7 ; 
      for (i = ht -> size ; i -- ; ) {
#       define XfOrM158_COUNT (0+XfOrM152_COUNT)
#       define SETUP_XfOrM158(x) SETUP_XfOrM152(x)
        bucket = buckets [i ] ; 
        if (bucket ) {
#         define XfOrM159_COUNT (0+XfOrM158_COUNT)
#         define SETUP_XfOrM159(x) SETUP_XfOrM158(x)
          if (weak ) {
            key = (const char * ) (((Scheme_Small_Object * ) (bucket -> key ) ) -> u . ptr_val ) ; 
          }
          else {
            key = bucket -> key ; 
          }
          if (key ) {
#           define XfOrM160_COUNT (0+XfOrM159_COUNT)
#           define SETUP_XfOrM160(x) SETUP_XfOrM159(x)
            vk = FUNCCALL(SETUP_XfOrM160(_), equal_hash_key ((Scheme_Object * ) bucket -> val , 0 ) ); 
            (vk += (vk << 10 ) , vk ^= (vk >> 6 ) ) ; 
            vk += FUNCCALL(SETUP_XfOrM160(_), equal_hash_key ((Scheme_Object * ) key , 0 ) ); 
            (vk += (vk << 10 ) , vk ^= (vk >> 6 ) ) ; 
            k += vk ; 
          }
        }
      }
      RET_VALUE_START (k ) RET_VALUE_END ; 
    }
    default : {
      Scheme_Primary_Hash_Proc h1 = scheme_type_hash1s [t ] ; 
#     define XfOrM151_COUNT (0+XfOrM150_COUNT)
#     define SETUP_XfOrM151(x) SETUP_XfOrM150(x)
      if (h1 )
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(h1 (o , k ) )) RET_VALUE_EMPTY_END ; 
      else RET_VALUE_START (k + ((PTR_TO_LONG (o ) ) >> 4 ) ) RET_VALUE_END ; 
    }
  }
  (k += (k << 10 ) , k ^= (k >> 6 ) ) ; 
  goto top ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
long scheme_equal_hash_key (Scheme_Object * o ) {
  /* No conversion */
  return equal_hash_key (o , 0 ) ; 
}
static Scheme_Object * hash2_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Scheme_Object * v = (Scheme_Object * ) p -> ku . k . p1 ; 
  long nv ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  nv = scheme_equal_hash_key2 (v ) ; 
  return ((Scheme_Object * ) (void * ) (long ) ((((long ) (nv ) ) << 1 ) | 0x1 ) ) ; 
}
long scheme_equal_hash_key2 (Scheme_Object * o ) {
  Scheme_Type t ; 
  static int hash_counter = 20 ; 
  Scheme_Object * __funcarg7 = NULLED_OUT ; 
  Scheme_Config * __funcarg6 = NULLED_OUT ; 
  DECL_RET_SAVE (long ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(o, 0)));
# define XfOrM227_COUNT (1)
# define SETUP_XfOrM227(x) SETUP(XfOrM227_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  top : t = ((((long ) (o ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (o ) ) -> type ) ; 
  switch (t ) {
#   define XfOrM228_COUNT (0+XfOrM227_COUNT)
#   define SETUP_XfOrM228(x) SETUP_XfOrM227(x)
    case scheme_integer_type : RET_VALUE_START (t ) RET_VALUE_END ; 
    case scheme_double_type : {
      double d ; 
      int e ; 
#     define XfOrM290_COUNT (0+XfOrM228_COUNT)
#     define SETUP_XfOrM290(x) SETUP_XfOrM228(x)
      d = (((Scheme_Double * ) (o ) ) -> double_val ) ; 
      if (isnan (d ) || (isinf (d ) && (d > 0 ) ) || (isinf (d ) && (d < 0 ) ) ) {
        e = 1 ; 
      }
      else {
#       define XfOrM291_COUNT (0+XfOrM290_COUNT)
#       define SETUP_XfOrM291(x) SETUP_XfOrM290(x)
        d = FUNCCALL(SETUP_XfOrM291(_), frexp (d , & e ) ); 
      }
      RET_VALUE_START (e ) RET_VALUE_END ; 
    }
    case scheme_bignum_type : RET_VALUE_START ((((Scheme_Bignum * ) o ) -> digits ) [0 ] ) RET_VALUE_END ; 
    case scheme_rational_type : RET_VALUE_START ((__funcarg7 = FUNCCALL(SETUP_XfOrM228(_), scheme_rational_numerator (o ) ), FUNCCALL_EMPTY(scheme_equal_hash_key2 (__funcarg7 ) )) ) RET_VALUE_END ; 
    case scheme_complex_type : case scheme_complex_izi_type : {
      long v1 , v2 ; 
      Scheme_Complex * c = (Scheme_Complex * ) o ; 
      BLOCK_SETUP((PUSH(c, 0+XfOrM228_COUNT)));
#     define XfOrM289_COUNT (1+XfOrM228_COUNT)
#     define SETUP_XfOrM289(x) SETUP(XfOrM289_COUNT)
      v1 = FUNCCALL(SETUP_XfOrM289(_), scheme_equal_hash_key2 (c -> r ) ); 
      v2 = FUNCCALL(SETUP_XfOrM289(_), scheme_equal_hash_key2 (c -> i ) ); 
      RET_VALUE_START (v1 + v2 ) RET_VALUE_END ; 
    }
    case scheme_pair_type : {
      long v1 , v2 ; 
#     define XfOrM283_COUNT (0+XfOrM228_COUNT)
#     define SETUP_XfOrM283(x) SETUP_XfOrM228(x)
      if (! -- hash_counter ) {
#       define XfOrM284_COUNT (0+XfOrM283_COUNT)
#       define SETUP_XfOrM284(x) SETUP_XfOrM283(x)
        hash_counter = 20 ; 
        {
#         define XfOrM287_COUNT (0+XfOrM284_COUNT)
#         define SETUP_XfOrM287(x) SETUP_XfOrM284(x)
          if ((scheme_fuel_counter ) <= 0 ) {
#           define XfOrM288_COUNT (0+XfOrM287_COUNT)
#           define SETUP_XfOrM288(x) SETUP_XfOrM287(x)
            FUNCCALL(SETUP_XfOrM288(_), scheme_out_of_fuel () ); 
          }
        }
        ; 
        {
          unsigned long _stk_pos ; 
#         define XfOrM285_COUNT (0+XfOrM284_COUNT)
#         define SETUP_XfOrM285(x) SETUP_XfOrM284(x)
          _stk_pos = (unsigned long ) & _stk_pos ; 
          if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
            Scheme_Object * nv ; 
            long val ; 
            Scheme_Thread * p = scheme_current_thread ; 
            BLOCK_SETUP((PUSH(nv, 0+XfOrM285_COUNT)));
#           define XfOrM286_COUNT (1+XfOrM285_COUNT)
#           define SETUP_XfOrM286(x) SETUP(XfOrM286_COUNT)
            nv = NULLED_OUT ; 
            p -> ku . k . p1 = (void * ) o ; 
            p -> ku . k . i1 = 0 ; 
            nv = FUNCCALL(SETUP_XfOrM286(_), scheme_handle_stack_overflow (hash2_k ) ); 
            (scheme_get_int_val (nv , & val ) ) ; 
            RET_VALUE_START (val ) RET_VALUE_END ; 
          }
        }
      }
      v1 = FUNCCALL(SETUP_XfOrM283(_), scheme_equal_hash_key2 ((((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . car ) ) ); 
      v2 = FUNCCALL(SETUP_XfOrM283(_), scheme_equal_hash_key2 ((((Scheme_Simple_Object * ) (o ) ) -> u . pair_val . cdr ) ) ); 
      RET_VALUE_START (v1 + v2 ) RET_VALUE_END ; 
    }
    case scheme_vector_type : case scheme_wrap_chunk_type : {
      int len = (((Scheme_Vector * ) (o ) ) -> size ) , i ; 
      long k = 0 ; 
#     define XfOrM271_COUNT (0+XfOrM228_COUNT)
#     define SETUP_XfOrM271(x) SETUP_XfOrM228(x)
      if (! -- hash_counter ) {
#       define XfOrM278_COUNT (0+XfOrM271_COUNT)
#       define SETUP_XfOrM278(x) SETUP_XfOrM271(x)
        hash_counter = 20 ; 
        {
#         define XfOrM281_COUNT (0+XfOrM278_COUNT)
#         define SETUP_XfOrM281(x) SETUP_XfOrM278(x)
          if ((scheme_fuel_counter ) <= 0 ) {
#           define XfOrM282_COUNT (0+XfOrM281_COUNT)
#           define SETUP_XfOrM282(x) SETUP_XfOrM281(x)
            FUNCCALL(SETUP_XfOrM282(_), scheme_out_of_fuel () ); 
          }
        }
        ; 
        {
          unsigned long _stk_pos ; 
#         define XfOrM279_COUNT (0+XfOrM278_COUNT)
#         define SETUP_XfOrM279(x) SETUP_XfOrM278(x)
          _stk_pos = (unsigned long ) & _stk_pos ; 
          if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
            Scheme_Object * nv ; 
            long val ; 
            Scheme_Thread * p = scheme_current_thread ; 
            BLOCK_SETUP((PUSH(nv, 0+XfOrM279_COUNT)));
#           define XfOrM280_COUNT (1+XfOrM279_COUNT)
#           define SETUP_XfOrM280(x) SETUP(XfOrM280_COUNT)
            nv = NULLED_OUT ; 
            p -> ku . k . p1 = (void * ) o ; 
            p -> ku . k . i1 = 0 ; 
            nv = FUNCCALL(SETUP_XfOrM280(_), scheme_handle_stack_overflow (hash2_k ) ); 
            (scheme_get_int_val (nv , & val ) ) ; 
            RET_VALUE_START (val ) RET_VALUE_END ; 
          }
        }
      }
      for (i = 0 ; i < len ; i ++ ) {
#       define XfOrM275_COUNT (0+XfOrM271_COUNT)
#       define SETUP_XfOrM275(x) SETUP_XfOrM271(x)
        {
#         define XfOrM276_COUNT (0+XfOrM275_COUNT)
#         define SETUP_XfOrM276(x) SETUP_XfOrM275(x)
          if ((scheme_fuel_counter ) <= 0 ) {
#           define XfOrM277_COUNT (0+XfOrM276_COUNT)
#           define SETUP_XfOrM277(x) SETUP_XfOrM276(x)
            FUNCCALL(SETUP_XfOrM277(_), scheme_out_of_fuel () ); 
          }
        }
        ; 
        k += FUNCCALL(SETUP_XfOrM275(_), scheme_equal_hash_key2 ((((Scheme_Vector * ) (o ) ) -> els ) [i ] ) ); 
      }
      RET_VALUE_START (k ) RET_VALUE_END ; 
    }
    case scheme_char_type : RET_VALUE_START (t ) RET_VALUE_END ; 
    case scheme_byte_string_type : case scheme_unix_path_type : case scheme_windows_path_type : {
      int k = 0 , i = (((Scheme_Simple_Object * ) (o ) ) -> u . byte_str_val . tag_val ) ; 
      char * s = (((Scheme_Simple_Object * ) (o ) ) -> u . byte_str_val . string_val ) ; 
      while (i -- ) {
        k += s [i ] ; 
      }
      RET_VALUE_START (k ) RET_VALUE_END ; 
    }
    case scheme_char_string_type : {
      int k = 0 , i = (((Scheme_Simple_Object * ) (o ) ) -> u . char_str_val . tag_val ) ; 
      mzchar * s = (((Scheme_Simple_Object * ) (o ) ) -> u . char_str_val . string_val ) ; 
      while (i -- ) {
        k += s [i ] ; 
      }
      RET_VALUE_START (k ) RET_VALUE_END ; 
    }
    case scheme_structure_type : case scheme_proc_struct_type : {
      Scheme_Object * insp ; 
      BLOCK_SETUP((PUSH(insp, 0+XfOrM228_COUNT)));
#     define XfOrM256_COUNT (1+XfOrM228_COUNT)
#     define SETUP_XfOrM256(x) SETUP(XfOrM256_COUNT)
      insp = NULLED_OUT ; 
      insp = (__funcarg6 = FUNCCALL(SETUP_XfOrM256(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg6 , MZCONFIG_INSPECTOR ) )) ; 
      if (FUNCCALL(SETUP_XfOrM256(_), scheme_inspector_sees_part (o , insp , - 2 ) )) {
        int i ; 
        long k = 0 ; 
        Scheme_Structure * s1 = (Scheme_Structure * ) o ; 
        BLOCK_SETUP((PUSH(s1, 0+XfOrM256_COUNT)));
#       define XfOrM257_COUNT (1+XfOrM256_COUNT)
#       define SETUP_XfOrM257(x) SETUP(XfOrM257_COUNT)
        if (! -- hash_counter ) {
#         define XfOrM260_COUNT (0+XfOrM257_COUNT)
#         define SETUP_XfOrM260(x) SETUP_XfOrM257(x)
          hash_counter = 20 ; 
          {
#           define XfOrM263_COUNT (0+XfOrM260_COUNT)
#           define SETUP_XfOrM263(x) SETUP_XfOrM260(x)
            if ((scheme_fuel_counter ) <= 0 ) {
#             define XfOrM264_COUNT (0+XfOrM263_COUNT)
#             define SETUP_XfOrM264(x) SETUP_XfOrM263(x)
              FUNCCALL(SETUP_XfOrM264(_), scheme_out_of_fuel () ); 
            }
          }
          ; 
          {
            unsigned long _stk_pos ; 
#           define XfOrM261_COUNT (0+XfOrM260_COUNT)
#           define SETUP_XfOrM261(x) SETUP_XfOrM260(x)
            _stk_pos = (unsigned long ) & _stk_pos ; 
            if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
              Scheme_Object * nv ; 
              long val ; 
              Scheme_Thread * p = scheme_current_thread ; 
              BLOCK_SETUP((PUSH(nv, 0+XfOrM261_COUNT)));
#             define XfOrM262_COUNT (1+XfOrM261_COUNT)
#             define SETUP_XfOrM262(x) SETUP(XfOrM262_COUNT)
              nv = NULLED_OUT ; 
              p -> ku . k . p1 = (void * ) o ; 
              p -> ku . k . i1 = 0 ; 
              nv = FUNCCALL(SETUP_XfOrM262(_), scheme_handle_stack_overflow (hash2_k ) ); 
              (scheme_get_int_val (nv , & val ) ) ; 
              RET_VALUE_START (val ) RET_VALUE_END ; 
            }
          }
        }
        for (i = ((((Scheme_Structure * ) s1 ) -> stype ) -> num_slots ) ; i -- ; ) {
#         define XfOrM259_COUNT (0+XfOrM257_COUNT)
#         define SETUP_XfOrM259(x) SETUP_XfOrM257(x)
          k += FUNCCALL(SETUP_XfOrM259(_), scheme_equal_hash_key2 (s1 -> slots [i ] ) ); 
        }
        RET_VALUE_START (k ) RET_VALUE_END ; 
      }
      else RET_VALUE_START (t ) RET_VALUE_END ; 
    }
    case scheme_box_type : o = (((Scheme_Small_Object * ) (o ) ) -> u . ptr_val ) ; 
    goto top ; 
    case scheme_hash_table_type : {
      Scheme_Hash_Table * ht = (Scheme_Hash_Table * ) o ; 
      Scheme_Object * * vals , * * keys ; 
      int i ; 
      long k = 0 ; 
      BLOCK_SETUP((PUSH(keys, 0+XfOrM228_COUNT), PUSH(vals, 1+XfOrM228_COUNT), PUSH(ht, 2+XfOrM228_COUNT)));
#     define XfOrM246_COUNT (3+XfOrM228_COUNT)
#     define SETUP_XfOrM246(x) SETUP(XfOrM246_COUNT)
      vals = NULLED_OUT ; 
      keys = NULLED_OUT ; 
      if (! -- hash_counter ) {
#       define XfOrM251_COUNT (0+XfOrM246_COUNT)
#       define SETUP_XfOrM251(x) SETUP_XfOrM246(x)
        hash_counter = 20 ; 
        {
#         define XfOrM254_COUNT (0+XfOrM251_COUNT)
#         define SETUP_XfOrM254(x) SETUP_XfOrM251(x)
          if ((scheme_fuel_counter ) <= 0 ) {
#           define XfOrM255_COUNT (0+XfOrM254_COUNT)
#           define SETUP_XfOrM255(x) SETUP_XfOrM254(x)
            FUNCCALL(SETUP_XfOrM255(_), scheme_out_of_fuel () ); 
          }
        }
        ; 
        {
          unsigned long _stk_pos ; 
#         define XfOrM252_COUNT (0+XfOrM251_COUNT)
#         define SETUP_XfOrM252(x) SETUP_XfOrM251(x)
          _stk_pos = (unsigned long ) & _stk_pos ; 
          if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
            Scheme_Object * nv ; 
            long val ; 
            Scheme_Thread * p = scheme_current_thread ; 
            BLOCK_SETUP((PUSH(nv, 0+XfOrM252_COUNT)));
#           define XfOrM253_COUNT (1+XfOrM252_COUNT)
#           define SETUP_XfOrM253(x) SETUP(XfOrM253_COUNT)
            nv = NULLED_OUT ; 
            p -> ku . k . p1 = (void * ) o ; 
            p -> ku . k . i1 = 0 ; 
            nv = FUNCCALL(SETUP_XfOrM253(_), scheme_handle_stack_overflow (hash2_k ) ); 
            (scheme_get_int_val (nv , & val ) ) ; 
            RET_VALUE_START (val ) RET_VALUE_END ; 
          }
        }
      }
      keys = ht -> keys ; 
      vals = ht -> vals ; 
      for (i = ht -> size ; i -- ; ) {
#       define XfOrM249_COUNT (0+XfOrM246_COUNT)
#       define SETUP_XfOrM249(x) SETUP_XfOrM246(x)
        if (vals [i ] ) {
#         define XfOrM250_COUNT (0+XfOrM249_COUNT)
#         define SETUP_XfOrM250(x) SETUP_XfOrM249(x)
          k += FUNCCALL(SETUP_XfOrM250(_), scheme_equal_hash_key2 (keys [i ] ) ); 
          k += FUNCCALL(SETUP_XfOrM250(_), scheme_equal_hash_key2 (vals [i ] ) ); 
        }
      }
      RET_VALUE_START (k ) RET_VALUE_END ; 
    }
    case scheme_bucket_table_type : {
      Scheme_Bucket_Table * ht = (Scheme_Bucket_Table * ) o ; 
      Scheme_Bucket * * buckets , * bucket ; 
      const char * key ; 
      int i , weak ; 
      long k = 0 ; 
      BLOCK_SETUP((PUSH(bucket, 0+XfOrM228_COUNT), PUSH(buckets, 1+XfOrM228_COUNT), PUSH(key, 2+XfOrM228_COUNT), PUSH(ht, 3+XfOrM228_COUNT)));
#     define XfOrM230_COUNT (4+XfOrM228_COUNT)
#     define SETUP_XfOrM230(x) SETUP(XfOrM230_COUNT)
      buckets = NULLED_OUT ; 
      bucket = NULLED_OUT ; 
      key = NULLED_OUT ; 
      if (! -- hash_counter ) {
#       define XfOrM241_COUNT (0+XfOrM230_COUNT)
#       define SETUP_XfOrM241(x) SETUP_XfOrM230(x)
        hash_counter = 20 ; 
        {
#         define XfOrM244_COUNT (0+XfOrM241_COUNT)
#         define SETUP_XfOrM244(x) SETUP_XfOrM241(x)
          if ((scheme_fuel_counter ) <= 0 ) {
#           define XfOrM245_COUNT (0+XfOrM244_COUNT)
#           define SETUP_XfOrM245(x) SETUP_XfOrM244(x)
            FUNCCALL(SETUP_XfOrM245(_), scheme_out_of_fuel () ); 
          }
        }
        ; 
        {
          unsigned long _stk_pos ; 
#         define XfOrM242_COUNT (0+XfOrM241_COUNT)
#         define SETUP_XfOrM242(x) SETUP_XfOrM241(x)
          _stk_pos = (unsigned long ) & _stk_pos ; 
          if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
            Scheme_Object * nv ; 
            long val ; 
            Scheme_Thread * p = scheme_current_thread ; 
            BLOCK_SETUP((PUSH(nv, 0+XfOrM242_COUNT)));
#           define XfOrM243_COUNT (1+XfOrM242_COUNT)
#           define SETUP_XfOrM243(x) SETUP(XfOrM243_COUNT)
            nv = NULLED_OUT ; 
            p -> ku . k . p1 = (void * ) o ; 
            p -> ku . k . i1 = 0 ; 
            nv = FUNCCALL(SETUP_XfOrM243(_), scheme_handle_stack_overflow (hash2_k ) ); 
            (scheme_get_int_val (nv , & val ) ) ; 
            RET_VALUE_START (val ) RET_VALUE_END ; 
          }
        }
      }
      buckets = ht -> buckets ; 
      weak = ht -> weak ; 
      for (i = ht -> size ; i -- ; ) {
#       define XfOrM236_COUNT (0+XfOrM230_COUNT)
#       define SETUP_XfOrM236(x) SETUP_XfOrM230(x)
        bucket = buckets [i ] ; 
        if (bucket ) {
#         define XfOrM237_COUNT (0+XfOrM236_COUNT)
#         define SETUP_XfOrM237(x) SETUP_XfOrM236(x)
          if (weak ) {
            key = (const char * ) (((Scheme_Small_Object * ) (bucket -> key ) ) -> u . ptr_val ) ; 
          }
          else {
            key = bucket -> key ; 
          }
          if (key ) {
#           define XfOrM238_COUNT (0+XfOrM237_COUNT)
#           define SETUP_XfOrM238(x) SETUP_XfOrM237(x)
            k += FUNCCALL(SETUP_XfOrM238(_), scheme_equal_hash_key ((Scheme_Object * ) bucket -> val ) ); 
            k += FUNCCALL(SETUP_XfOrM238(_), scheme_equal_hash_key ((Scheme_Object * ) key ) ); 
          }
        }
      }
      RET_VALUE_START (k ) RET_VALUE_END ; 
    }
    default : {
      Scheme_Secondary_Hash_Proc h2 = scheme_type_hash2s [t ] ; 
#     define XfOrM229_COUNT (0+XfOrM228_COUNT)
#     define SETUP_XfOrM229(x) SETUP_XfOrM228(x)
      if (h2 )
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(h2 (o ) )) RET_VALUE_EMPTY_END ; 
      else RET_VALUE_START (t ) RET_VALUE_END ; 
    }
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
