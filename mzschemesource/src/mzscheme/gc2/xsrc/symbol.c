#include "precomp.h"
enum {
  _ISupper = ((0 ) < 8 ? ((1 << (0 ) ) << 8 ) : ((1 << (0 ) ) >> 8 ) ) , _ISlower = ((1 ) < 8 ? ((1 << (1 ) ) << 8 ) : ((1 << (1 ) ) >> 8 ) ) , _ISalpha = ((2 ) < 8 ? ((1 << (2 ) ) << 8 ) : ((1 << (2 ) ) >> 8 ) ) , _ISdigit = ((3 ) < 8 ? ((1 << (3 ) ) << 8 ) : ((1 << (3 ) ) >> 8 ) ) , _ISxdigit = ((4 ) < 8 ? ((1 << (4 ) ) << 8 ) : ((1 << (4 ) ) >> 8 ) ) , _ISspace = ((5 ) < 8 ? ((1 << (5 ) ) << 8 ) : ((1 << (5 ) ) >> 8 ) ) , _ISprint = ((6 ) < 8 ? ((1 << (6 ) ) << 8 ) : ((1 << (6 ) ) >> 8 ) ) , _ISgraph = ((7 ) < 8 ? ((1 << (7 ) ) << 8 ) : ((1 << (7 ) ) >> 8 ) ) , _ISblank = ((8 ) < 8 ? ((1 << (8 ) ) << 8 ) : ((1 << (8 ) ) >> 8 ) ) , _IScntrl = ((9 ) < 8 ? ((1 << (9 ) ) << 8 ) : ((1 << (9 ) ) >> 8 ) ) , _ISpunct = ((10 ) < 8 ? ((1 << (10 ) ) << 8 ) : ((1 << (10 ) ) >> 8 ) ) , _ISalnum = ((11 ) < 8 ? ((1 << (11 ) ) << 8 ) : ((1 << (11 ) ) >> 8 ) ) }
; 
extern __const unsigned short int * * __ctype_b_loc (void ) __attribute__ ((__const ) ) ; 
Scheme_Hash_Table * scheme_symbol_table = ((void * ) 0 ) ; 
Scheme_Hash_Table * scheme_keyword_table = ((void * ) 0 ) ; 
Scheme_Hash_Table * scheme_parallel_symbol_table = ((void * ) 0 ) ; 
unsigned long scheme_max_found_symbol_name ; 
int scheme_case_sensitive = 1 ; 
void scheme_set_case_sensitive (int v ) {
  /* No conversion */
  scheme_case_sensitive = v ; 
}
static Scheme_Object * symbol_p_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_to_symbol_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_to_uninterned_symbol_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * symbol_to_string_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * keyword_p_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * keyword_lt (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * string_to_keyword_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * keyword_to_string_prim (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Object * gensym (int argc , Scheme_Object * argv [] ) ; 
static int gensym_counter ; 
typedef unsigned long hash_v_t ; 
static Scheme_Object * rehash_symbol_bucket (Scheme_Hash_Table * table , GC_CAN_IGNORE const char * key , unsigned int length , Scheme_Object * naya ) ; 
static Scheme_Object * symbol_bucket (Scheme_Hash_Table * table , GC_CAN_IGNORE const char * key , unsigned int length , Scheme_Object * naya ) {
  /* No conversion */
  hash_v_t h , h2 ; 
  unsigned long mask ; 
  Scheme_Object * bucket ; 
  mask = table -> size - 1 ; 
  {
    unsigned int i ; 
    i = 0 ; 
    h = 0xF0E1D2C3 ; 
    h2 = 0 ; 
    while (i < length ) {
      int c = key [i ++ ] ; 
      h ^= (h << 5 ) + (h >> 2 ) + c ; 
      h2 += c ; 
    }
    h ^= (h << 5 ) + (h >> 2 ) + 0xA0A0 ; 
    h ^= (h << 5 ) + (h >> 2 ) + 0x0505 ; 
    h = h & mask ; 
    h2 = h2 & mask ; 
  }
  h2 |= 0x1 ; 
  while ((bucket = table -> keys [4 + h ] ) ) {
    if (((bucket ) == (scheme_false ) ) ) {
      if (naya ) {
        -- table -> count ; 
        break ; 
      }
    }
    else if (((int ) length == (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (bucket ) ) ) -> len ) ) && ! memcmp (key , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (bucket ) ) ) -> s ) , length ) )
      return bucket ; 
    h = (h + h2 ) & mask ; 
  }
  key = ((void * ) 0 ) ; 
  if (! naya )
    return ((void * ) 0 ) ; 
  if (table -> count * 2 >= table -> size ) {
    return rehash_symbol_bucket (table , key , length , naya ) ; 
  }
  table -> keys [4 + h ] = naya ; 
  table -> count ++ ; 
  return naya ; 
}
/* this far 186 */
static Scheme_Object * rehash_symbol_bucket (Scheme_Hash_Table * table , GC_CAN_IGNORE const char * key , unsigned int length , Scheme_Object * naya ) {
  int i , oldsize = table -> size , newsize , lostc ; 
  size_t asize ; 
  Scheme_Object * cb ; 
  Scheme_Object * * old = table -> keys ; 
  PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(table, 0), PUSH(cb, 1), PUSH(naya, 2), PUSH(old, 3)));
# define XfOrM13_COUNT (4)
# define SETUP_XfOrM13(x) SETUP(XfOrM13_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  cb = NULLED_OUT ; 
  lostc = 0 ; 
  for (i = 0 ; i < oldsize ; i ++ ) {
    cb = old [4 + i ] ; 
    if (cb == scheme_false )
      lostc ++ ; 
  }
  if ((lostc * 2 ) < table -> count )
    newsize = oldsize << 1 ; 
  else newsize = oldsize ; 
  asize = (size_t ) newsize * sizeof (Scheme_Object * ) ; 
  {
    Scheme_Object * * ba ; 
    BLOCK_SETUP((PUSH(ba, 0+XfOrM13_COUNT)));
#   define XfOrM16_COUNT (1+XfOrM13_COUNT)
#   define SETUP_XfOrM16(x) SETUP(XfOrM16_COUNT)
    ba = NULLED_OUT ; 
    ba = (Scheme_Object * * ) FUNCCALL(SETUP_XfOrM16(_), GC_malloc_weak_array (sizeof (Scheme_Object * ) * newsize , scheme_false ) ); 
    table -> keys = ba ; 
  }
  table -> size = newsize ; 
  table -> count = 0 ; 
  for (i = 0 ; i < oldsize ; i ++ ) {
#   define XfOrM15_COUNT (0+XfOrM13_COUNT)
#   define SETUP_XfOrM15(x) SETUP_XfOrM13(x)
    cb = old [4 + i ] ; 
    if (cb && (cb != scheme_false ) )
      FUNCCALL(SETUP_XfOrM15(_), symbol_bucket (table , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (cb ) ) ) -> s ) , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (cb ) ) ) -> len ) , cb ) ); 
  }
  key = (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (naya ) ) ) -> s ) ; 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(symbol_bucket (table , key , length , naya ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Hash_Table * init_one_symbol_table () {
  Scheme_Hash_Table * symbol_table ; 
  int size ; 
  Scheme_Object * * ba ; 
  DECL_RET_SAVE (Scheme_Hash_Table * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(symbol_table, 0), PUSH(ba, 1)));
# define XfOrM19_COUNT (2)
# define SETUP_XfOrM19(x) SETUP(XfOrM19_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  symbol_table = NULLED_OUT ; 
  ba = NULLED_OUT ; 
  symbol_table = FUNCCALL(SETUP_XfOrM19(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
  symbol_table -> size = 256 ; 
  size = symbol_table -> size * sizeof (Scheme_Object * ) ; 
  ba = (Scheme_Object * * ) FUNCCALL(SETUP_XfOrM19(_), GC_malloc_weak_array (size , scheme_false ) ); 
  symbol_table -> keys = ba ; 
  RET_VALUE_START (symbol_table ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_init_symbol_table () {
  /* No conversion */
  scheme_register_static ((void * ) & scheme_symbol_table , sizeof (scheme_symbol_table ) ) ; 
  scheme_register_static ((void * ) & scheme_keyword_table , sizeof (scheme_keyword_table ) ) ; 
  scheme_register_static ((void * ) & scheme_parallel_symbol_table , sizeof (scheme_parallel_symbol_table ) ) ; 
  scheme_symbol_table = init_one_symbol_table () ; 
  scheme_keyword_table = init_one_symbol_table () ; 
  scheme_parallel_symbol_table = init_one_symbol_table () ; 
}
void scheme_init_symbol_type (Scheme_Env * env ) {
  /* No conversion */
}
void scheme_init_symbol (Scheme_Env * env ) {
  Scheme_Object * p ; 
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
# define XfOrM22_COUNT (2)
# define SETUP_XfOrM22(x) SETUP(XfOrM22_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  p = NULLED_OUT ; 
  p = FUNCCALL(SETUP_XfOrM22(_), scheme_make_folding_prim (symbol_p_prim , "symbol?" , 1 , 1 , 1 ) ); 
  (((Scheme_Prim_Proc_Header * ) p ) -> flags ) |= 16384 ; 
  FUNCCALL(SETUP_XfOrM22(_), scheme_add_global_constant ("symbol?" , p , env ) ); 
  (__funcarg11 = FUNCCALL(SETUP_XfOrM22(_), scheme_make_noncm_prim (string_to_symbol_prim , "string->symbol" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string->symbol" , __funcarg11 , env ) )) ; 
  (__funcarg10 = FUNCCALL(SETUP_XfOrM22(_), scheme_make_noncm_prim (string_to_uninterned_symbol_prim , "string->uninterned-symbol" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string->uninterned-symbol" , __funcarg10 , env ) )) ; 
  (__funcarg9 = FUNCCALL(SETUP_XfOrM22(_), scheme_make_noncm_prim (symbol_to_string_prim , "symbol->string" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("symbol->string" , __funcarg9 , env ) )) ; 
  (__funcarg8 = FUNCCALL(SETUP_XfOrM22(_), scheme_make_folding_prim (keyword_p_prim , "keyword?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("keyword?" , __funcarg8 , env ) )) ; 
  (__funcarg7 = FUNCCALL(SETUP_XfOrM22(_), scheme_make_folding_prim (keyword_lt , "keyword<?" , 2 , - 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("keyword<?" , __funcarg7 , env ) )) ; 
  (__funcarg6 = FUNCCALL(SETUP_XfOrM22(_), scheme_make_noncm_prim (string_to_keyword_prim , "string->keyword" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("string->keyword" , __funcarg6 , env ) )) ; 
  (__funcarg5 = FUNCCALL(SETUP_XfOrM22(_), scheme_make_noncm_prim (keyword_to_string_prim , "keyword->string" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("keyword->string" , __funcarg5 , env ) )) ; 
  (__funcarg4 = FUNCCALL(SETUP_XfOrM22(_), scheme_make_noncm_prim (gensym , "gensym" , 0 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("gensym" , __funcarg4 , env ) )) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_a_symbol (const char * name , unsigned int len , int kind ) {
  Scheme_Symbol * sym ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(sym, 0), PUSH(name, 1)));
# define XfOrM23_COUNT (2)
# define SETUP_XfOrM23(x) SETUP(XfOrM23_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sym = NULLED_OUT ; 
  sym = (Scheme_Symbol * ) FUNCCALL(SETUP_XfOrM23(_), GC_malloc_one_tagged (sizeof (Scheme_Symbol ) + len - 3 ) ); 
  sym -> iso . so . type = scheme_symbol_type ; 
  (& sym -> iso ) -> so . keyex = kind ; 
  sym -> len = len ; 
  (memcpy (sym -> s , name , len ) ) ; 
  sym -> s [len ] = 0 ; 
  if (len > scheme_max_found_symbol_name ) {
#   define XfOrM24_COUNT (0+XfOrM23_COUNT)
#   define SETUP_XfOrM24(x) SETUP_XfOrM23(x)
    scheme_max_found_symbol_name = len ; 
    FUNCCALL(SETUP_XfOrM24(_), scheme_reset_prepared_error_buffer () ); 
  }
  RET_VALUE_START ((Scheme_Object * ) sym ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_make_symbol (const char * name ) {
  /* No conversion */
  return make_a_symbol (name , strlen (name ) , 0x1 ) ; 
}
Scheme_Object * scheme_make_exact_symbol (const char * name , unsigned int len ) {
  /* No conversion */
  return make_a_symbol (name , len , 0x1 ) ; 
}
Scheme_Object * scheme_make_exact_char_symbol (const mzchar * name , unsigned int len ) {
  char buf [64 ] , * bs ; 
  long blen ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(bs, 0)));
# define XfOrM27_COUNT (1)
# define SETUP_XfOrM27(x) SETUP(XfOrM27_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  bs = NULLED_OUT ; 
  bs = FUNCCALL(SETUP_XfOrM27(_), scheme_utf8_encode_to_buffer_len (name , len , buf , 64 , & blen ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(make_a_symbol (bs , blen , 0x1 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_intern_exact_symbol_in_table (Scheme_Hash_Table * symbol_table , int kind , const char * name , unsigned int len ) {
  Scheme_Object * sym ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(symbol_table, 0), PUSH(sym, 1), PUSH(name, 2)));
# define XfOrM28_COUNT (3)
# define SETUP_XfOrM28(x) SETUP(XfOrM28_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  sym = NULLED_OUT ; 
  sym = FUNCCALL(SETUP_XfOrM28(_), symbol_bucket (symbol_table , name , len , ((void * ) 0 ) ) ); 
  if (! sym ) {
#   define XfOrM29_COUNT (0+XfOrM28_COUNT)
#   define SETUP_XfOrM29(x) SETUP_XfOrM28(x)
    sym = FUNCCALL(SETUP_XfOrM29(_), make_a_symbol (name , len , kind ) ); 
    FUNCCALL(SETUP_XfOrM29(_), symbol_bucket (symbol_table , name , len , sym ) ); 
  }
  RET_VALUE_START (sym ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_intern_exact_symbol (const char * name , unsigned int len ) {
  /* No conversion */
  return scheme_intern_exact_symbol_in_table (scheme_symbol_table , 0 , name , len ) ; 
}
Scheme_Object * scheme_intern_exact_parallel_symbol (const char * name , unsigned int len ) {
  /* No conversion */
  return scheme_intern_exact_symbol_in_table (scheme_parallel_symbol_table , 0x2 , name , len ) ; 
}
Scheme_Object * scheme_intern_exact_char_symbol (const mzchar * name , unsigned int len ) {
  char buf [64 ] , * bs ; 
  long blen ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(bs, 0)));
# define XfOrM32_COUNT (1)
# define SETUP_XfOrM32(x) SETUP(XfOrM32_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  bs = NULLED_OUT ; 
  bs = FUNCCALL(SETUP_XfOrM32(_), scheme_utf8_encode_to_buffer_len (name , len , buf , 64 , & blen ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_intern_exact_symbol_in_table (scheme_symbol_table , 0 , bs , blen ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_intern_exact_keyword (const char * name , unsigned int len ) {
  Scheme_Object * s ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(s, 0)));
# define XfOrM33_COUNT (1)
# define SETUP_XfOrM33(x) SETUP(XfOrM33_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  s = FUNCCALL(SETUP_XfOrM33(_), scheme_intern_exact_symbol_in_table (scheme_keyword_table , 0 , name , len ) ); 
  if (s -> type == scheme_symbol_type )
    s -> type = scheme_keyword_type ; 
  RET_VALUE_START (s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_intern_exact_char_keyword (const mzchar * name , unsigned int len ) {
  char buf [64 ] , * bs ; 
  long blen ; 
  Scheme_Object * s ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(bs, 1)));
# define XfOrM34_COUNT (2)
# define SETUP_XfOrM34(x) SETUP(XfOrM34_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  bs = NULLED_OUT ; 
  s = NULLED_OUT ; 
  bs = FUNCCALL(SETUP_XfOrM34(_), scheme_utf8_encode_to_buffer_len (name , len , buf , 64 , & blen ) ); 
  s = FUNCCALL_AGAIN(scheme_intern_exact_symbol_in_table (scheme_keyword_table , 0 , bs , blen ) ); 
  if (s -> type == scheme_symbol_type )
    s -> type = scheme_keyword_type ; 
  RET_VALUE_START (s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_intern_symbol (const char * name ) {
  PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(name, 0)));
# define XfOrM35_COUNT (1)
# define SETUP_XfOrM35(x) SETUP(XfOrM35_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (! scheme_case_sensitive ) {
    unsigned long i , len ; 
    char * naya ; 
    char on_stack [256 ] ; 
    BLOCK_SETUP((PUSH(naya, 0+XfOrM35_COUNT)));
#   define XfOrM36_COUNT (1+XfOrM35_COUNT)
#   define SETUP_XfOrM36(x) SETUP(XfOrM36_COUNT)
    naya = NULLED_OUT ; 
    len = strlen (name ) ; 
    if (len >= 256 )
      naya = (char * ) FUNCCALL(SETUP_XfOrM36(_), GC_malloc_atomic (len + 1 ) ); 
    else naya = on_stack ; 
    for (i = 0 ; i < len ; i ++ ) {
      int c = ((unsigned char * ) name ) [i ] ; 
      c = (c + scheme_uchar_downs [(scheme_uchar_cases_table [(c >> 8 ) & 0x1FFF ] [c & 0xFF ] ) ] ) ; 
      naya [i ] = c ; 
    }
    naya [len ] = 0 ; 
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_intern_exact_symbol (naya , len ) )) RET_VALUE_EMPTY_END ; 
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_intern_exact_symbol (name , strlen (name ) ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
const char * scheme_symbol_name_and_size (Scheme_Object * sym , unsigned int * length , int flags ) {
  int has_space = 0 , has_special = 0 , has_pipe = 0 , has_upper = 0 , digit_start ; 
  int dz ; 
  unsigned int i , len = (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (sym ) ) ) -> len ) , total_length ; 
  int pipe_quote ; 
  char buf [100 ] ; 
  char * s , * result ; 
  Scheme_Config * __funcarg12 = NULLED_OUT ; 
  DECL_RET_SAVE (const char * ) PREPARE_VAR_STACK(5);
  BLOCK_SETUP_TOP((PUSH(result, 0), PUSH(sym, 1), PUSH(length, 2), PUSH(s, 3)));
# define XfOrM39_COUNT (4)
# define SETUP_XfOrM39(x) SETUP(XfOrM39_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  s = NULLED_OUT ; 
  result = NULLED_OUT ; 
  if ((flags & 0x2 ) || (flags & 0x1 ) )
    pipe_quote = 1 ; 
  else if (flags & 0x4 )
    pipe_quote = 0 ; 
  else {
#   define XfOrM70_COUNT (0+XfOrM39_COUNT)
#   define SETUP_XfOrM70(x) SETUP_XfOrM39(x)
    pipe_quote = (! ((((__funcarg12 = FUNCCALL(SETUP_XfOrM70(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg12 , MZCONFIG_CAN_READ_PIPE_QUOTE ) )) ) ) == (scheme_false ) ) ) ; 
  }
  if (len < 100 ) {
#   define XfOrM69_COUNT (0+XfOrM39_COUNT)
#   define SETUP_XfOrM69(x) SETUP_XfOrM39(x)
    s = buf ; 
    (memcpy (buf , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (sym ) ) ) -> s ) , len + 1 ) ) ; 
  }
  else s = FUNCCALL(SETUP_XfOrM39(_), scheme_symbol_val (sym ) ); 
  if (len ) {
#   define XfOrM66_COUNT (0+XfOrM39_COUNT)
#   define SETUP_XfOrM66(x) SETUP_XfOrM39(x)
    if (flags & 0x10 ) {
      digit_start = 0 ; 
    }
    else {
#     define XfOrM67_COUNT (0+XfOrM66_COUNT)
#     define SETUP_XfOrM67(x) SETUP_XfOrM66(x)
      digit_start = (((* FUNCCALL(SETUP_XfOrM67(_), __ctype_b_loc () )) [(int ) (((unsigned char ) s [0 ] ) ) ] & (unsigned short int ) _ISdigit ) || (s [0 ] == '.' ) || (s [0 ] == '+' ) || (s [0 ] == '-' ) ) ; 
      if (s [0 ] == '#' && (len == 1 || s [1 ] != '%' ) )
        has_special = 1 ; 
      if (s [0 ] == '.' && len == 1 )
        has_special = 1 ; 
    }
  }
  else {
    digit_start = 0 ; 
    if (! (flags & 0x10 ) )
      has_space = 1 ; 
  }
  for (i = 0 ; i < len ; i ++ ) {
#   define XfOrM57_COUNT (0+XfOrM39_COUNT)
#   define SETUP_XfOrM57(x) SETUP_XfOrM39(x)
    if (((* FUNCCALL(SETUP_XfOrM57(_), __ctype_b_loc () )) [(int ) (((unsigned char ) s [i ] ) ) ] & (unsigned short int ) _ISspace ) ) {
      if ((flags & 0x1 ) && (s [i ] == ' ' ) ) {
      }
      else has_space = 1 ; 
    }
    else if (((s [i ] == '(' ) || (s [i ] == '[' ) || (s [i ] == '{' ) || (s [i ] == ')' ) || (s [i ] == ']' ) || (s [i ] == '}' ) || (s [i ] == ')' ) || (s [i ] == '\\' ) || (s [i ] == '"' ) || (s [i ] == '\'' ) || (s [i ] == '`' ) || (s [i ] == ',' ) || (s [i ] == ';' ) || (((s [i ] == '>' ) || (s [i ] == '<' ) ) && (flags & 0x1 ) ) ) )
      has_special = 1 ; 
    else if (s [i ] == '|' )
      has_pipe = 1 ; 
    else if (flags & 0x8 ) {
      int ch = ((unsigned char * ) s ) [i ] ; 
#     define XfOrM58_COUNT (0+XfOrM57_COUNT)
#     define SETUP_XfOrM58(x) SETUP_XfOrM57(x)
      if (ch > 127 ) {
        mzchar buf [2 ] ; 
        int ul = 2 ; 
#       define XfOrM59_COUNT (0+XfOrM58_COUNT)
#       define SETUP_XfOrM59(x) SETUP_XfOrM58(x)
        while (1 ) {
#         define XfOrM62_COUNT (0+XfOrM59_COUNT)
#         define SETUP_XfOrM62(x) SETUP_XfOrM59(x)
          if (FUNCCALL(SETUP_XfOrM62(_), scheme_utf8_decode ((unsigned char * ) s , i , i + ul , buf , 0 , 1 , ((void * ) 0 ) , 0 , 0 ) )> 0 )
            break ; 
          ul ++ ; 
        }
        ch = buf [0 ] ; 
        if ((((scheme_uchar_table [(ch >> 8 ) & 0x1FFF ] [ch & 0xFF ] ) ) & 0x2000 ) ) {
          mzchar * rc ; 
          BLOCK_SETUP((PUSH(rc, 0+XfOrM59_COUNT)));
#         define XfOrM60_COUNT (1+XfOrM59_COUNT)
#         define SETUP_XfOrM60(x) SETUP(XfOrM60_COUNT)
          rc = NULLED_OUT ; 
          buf [1 ] = 0 ; 
          rc = FUNCCALL(SETUP_XfOrM60(_), scheme_string_recase (buf , 0 , 1 , 3 , 1 , ((void * ) 0 ) ) ); 
          if ((rc != buf ) || (rc [0 ] != ch ) )
            has_upper = 1 ; 
          ch = 'a' ; 
        }
        i += (ul - 1 ) ; 
      }
      if ((ch + scheme_uchar_folds [(scheme_uchar_cases_table [(ch >> 8 ) & 0x1FFF ] [ch & 0xFF ] ) ] ) != ch )
        has_upper = 1 ; 
    }
  }
  result = ((void * ) 0 ) ; 
  total_length = 0 ; 
  if (! has_space && ! has_special && (! pipe_quote || ! has_pipe ) && ! has_upper ) {
    mzchar cbuf [100 ] , * cs ; 
    long clen ; 
    BLOCK_SETUP((PUSH(cs, 0+XfOrM39_COUNT)));
#   define XfOrM45_COUNT (1+XfOrM39_COUNT)
#   define SETUP_XfOrM45(x) SETUP(XfOrM45_COUNT)
    cs = NULLED_OUT ; 
    dz = 0 ; 
    cs = FUNCCALL(SETUP_XfOrM45(_), scheme_utf8_decode_to_buffer_len ((unsigned char * ) s , len , cbuf , 100 , & clen ) ); 
    if (cs && digit_start && ! (flags & 0x1 ) && ((! (((FUNCCALL(SETUP_XfOrM45(_), scheme_read_number (cs , clen , 0 , 0 , 1 , 10 , 0 , ((void * ) 0 ) , & dz , 1 , ((void * ) 0 ) , 0 , 0 , 0 , 0 , ((void * ) 0 ) ) )) ) == (scheme_false ) ) ) || dz ) ) {
#     define XfOrM47_COUNT (0+XfOrM45_COUNT)
#     define SETUP_XfOrM47(x) SETUP_XfOrM45(x)
      if (pipe_quote )
        has_space = 1 ; 
      else {
#       define XfOrM48_COUNT (0+XfOrM47_COUNT)
#       define SETUP_XfOrM48(x) SETUP_XfOrM47(x)
        result = (char * ) FUNCCALL(SETUP_XfOrM48(_), GC_malloc_atomic (len + 2 ) ); 
        total_length = len + 1 ; 
        (memcpy (result + 1 , s , len ) ) ; 
        result [0 ] = '\\' ; 
        result [len + 1 ] = 0 ; 
      }
    }
    else {
      total_length = len ; 
      result = s ; 
    }
  }
  if (! result ) {
#   define XfOrM40_COUNT (0+XfOrM39_COUNT)
#   define SETUP_XfOrM40(x) SETUP_XfOrM39(x)
    if (! has_pipe && pipe_quote ) {
#     define XfOrM44_COUNT (0+XfOrM40_COUNT)
#     define SETUP_XfOrM44(x) SETUP_XfOrM40(x)
      result = (char * ) FUNCCALL(SETUP_XfOrM44(_), GC_malloc_atomic (len + 3 ) ); 
      total_length = len + 2 ; 
      (memcpy (result + 1 , s , len ) ) ; 
      result [0 ] = '|' ; 
      result [len + 1 ] = '|' ; 
      result [len + 2 ] = 0 ; 
    }
    else {
      int p = 0 ; 
      unsigned int i = 0 ; 
#     define XfOrM41_COUNT (0+XfOrM40_COUNT)
#     define SETUP_XfOrM41(x) SETUP_XfOrM40(x)
      result = (char * ) FUNCCALL(SETUP_XfOrM41(_), GC_malloc_atomic ((2 * len ) + 1 ) ); 
      for (i = 0 ; i < len ; i ++ ) {
#       define XfOrM43_COUNT (0+XfOrM41_COUNT)
#       define SETUP_XfOrM43(x) SETUP_XfOrM41(x)
        if (((* FUNCCALL(SETUP_XfOrM43(_), __ctype_b_loc () )) [(int ) (((unsigned char ) s [i ] ) ) ] & (unsigned short int ) _ISspace ) || ((s [i ] == '(' ) || (s [i ] == '[' ) || (s [i ] == '{' ) || (s [i ] == ')' ) || (s [i ] == ']' ) || (s [i ] == '}' ) || (s [i ] == ')' ) || (s [i ] == '\\' ) || (s [i ] == '"' ) || (s [i ] == '\'' ) || (s [i ] == '`' ) || (s [i ] == ',' ) || (s [i ] == ';' ) || (((s [i ] == '>' ) || (s [i ] == '<' ) ) && (flags & 0x1 ) ) ) || ((s [i ] == '|' ) && pipe_quote ) || (! i && s [0 ] == '#' ) || (has_upper && ((((unsigned char ) s [i ] ) >= 'A' ) && (((unsigned char ) s [i ] ) <= 'Z' ) ) ) )
          result [p ++ ] = '\\' ; 
        result [p ++ ] = s [i ] ; 
      }
      result [p ] = 0 ; 
      total_length = p ; 
    }
  }
  if (length )
    * length = total_length ; 
  RET_VALUE_START ((result == buf ) ? FUNCCALL(SETUP_XfOrM39(_), scheme_symbol_val (sym ) ): result ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
const char * scheme_symbol_name (Scheme_Object * sym ) {
  /* No conversion */
  return scheme_symbol_name_and_size (sym , ((void * ) 0 ) , 0 ) ; 
}
char * scheme_symbol_val (Scheme_Object * sym ) {
  char * s ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(s, 0), PUSH(sym, 1)));
# define XfOrM72_COUNT (2)
# define SETUP_XfOrM72(x) SETUP(XfOrM72_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  s = FUNCCALL(SETUP_XfOrM72(_), GC_malloc_atomic ((((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (sym ) ) ) -> len ) + 1 ) ); 
  (memcpy (s , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (sym ) ) ) -> s ) , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (sym ) ) ) -> len ) + 1 ) ) ; 
  RET_VALUE_START (s ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * symbol_p_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ? scheme_true : scheme_false ; 
}
static Scheme_Object * string_to_symbol_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    scheme_wrong_type ("string->symbol" , "string" , 0 , argc , argv ) ; 
  return scheme_intern_exact_char_symbol ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) , (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) ) ; 
}
static Scheme_Object * string_to_uninterned_symbol_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    scheme_wrong_type ("string->uninterned-symbol" , "string" , 0 , argc , argv ) ; 
  return scheme_make_exact_char_symbol ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) , (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) ) ; 
}
static Scheme_Object * symbol_to_string_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
    scheme_wrong_type ("symbol->string" , "symbol" , 0 , argc , argv ) ; 
  return scheme_make_sized_offset_utf8_string ((char * ) (argv [0 ] ) , ((unsigned long ) (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (argv [0 ] ) ) ) -> s ) - (unsigned long ) (argv [0 ] ) ) , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (argv [0 ] ) ) ) -> len ) ) ; 
}
static Scheme_Object * keyword_p_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_keyword_type ) ) ? scheme_true : scheme_false ; 
}
static Scheme_Object * keyword_lt (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  Scheme_Object * prev = argv [0 ] , * kw ; 
  GC_CAN_IGNORE unsigned char * a , * b ; 
  int i , al , bl , t ; 
  if (! ((Scheme_Type ) (((((long ) (prev ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (prev ) ) -> type ) ) == (Scheme_Type ) (scheme_keyword_type ) ) )
    scheme_wrong_type ("keyword<?" , "keyword" , 0 , argc , argv ) ; 
  for (i = 1 ; i < argc ; i ++ ) {
    kw = argv [i ] ; 
    if (! ((Scheme_Type ) (((((long ) (kw ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (kw ) ) -> type ) ) == (Scheme_Type ) (scheme_keyword_type ) ) )
      scheme_wrong_type ("keyword<?" , "keyword" , i , argc , argv ) ; 
    a = (unsigned char * ) (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (prev ) ) ) -> s ) ; 
    al = (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (prev ) ) ) -> len ) ; 
    b = (unsigned char * ) (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (kw ) ) ) -> s ) ; 
    bl = (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (kw ) ) ) -> len ) ; 
    t = ((al < bl ) ? al : bl ) ; 
    while (t -- ) {
      if (* a < * b ) {
        al = 0 ; 
        bl = 1 ; 
        break ; 
      }
      else if (* a > * b ) {
        al = bl = 0 ; 
        break ; 
      }
      else {
        a ++ ; 
        b ++ ; 
      }
    }
    a = b = ((void * ) 0 ) ; 
    if (al >= bl ) {
      for (i ++ ; i < argc ; i ++ ) {
        if (! ((Scheme_Type ) (((((long ) (argv [i ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [i ] ) ) -> type ) ) == (Scheme_Type ) (scheme_keyword_type ) ) )
          scheme_wrong_type ("keyword<?" , "keyword" , i , argc , argv ) ; 
      }
      return scheme_false ; 
    }
    prev = kw ; 
  }
  return scheme_true ; 
}
static Scheme_Object * string_to_keyword_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    scheme_wrong_type ("string->keyword" , "string" , 0 , argc , argv ) ; 
  return scheme_intern_exact_char_keyword ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) , (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) ) ; 
}
static Scheme_Object * keyword_to_string_prim (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_keyword_type ) ) )
    scheme_wrong_type ("keyword->string" , "keyword" , 0 , argc , argv ) ; 
  return scheme_make_sized_offset_utf8_string ((char * ) (argv [0 ] ) , ((unsigned long ) (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (argv [0 ] ) ) ) -> s ) - (unsigned long ) (argv [0 ] ) ) , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (argv [0 ] ) ) ) -> len ) ) ; 
}
static Scheme_Object * gensym (int argc , Scheme_Object * argv [] ) {
  char buffer [100 ] , * str ; 
  Scheme_Object * r ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(str, 0), PUSH(r, 1)));
# define XfOrM105_COUNT (2)
# define SETUP_XfOrM105(x) SETUP(XfOrM105_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  str = NULLED_OUT ; 
  r = NULLED_OUT ; 
  if (argc )
    r = argv [0 ] ; 
  else r = ((void * ) 0 ) ; 
  if (r && ! ((Scheme_Type ) (((((long ) (r ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (r ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) && ! ((Scheme_Type ) (((((long ) (r ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (r ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("gensym" , "symbol or string" , 0 , argc , argv ) ); 
  if (r ) {
    char buf [64 ] ; 
#   define XfOrM106_COUNT (0+XfOrM105_COUNT)
#   define SETUP_XfOrM106(x) SETUP_XfOrM105(x)
    if (((Scheme_Type ) (((((long ) (r ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (r ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) ) {
#     define XfOrM107_COUNT (0+XfOrM106_COUNT)
#     define SETUP_XfOrM107(x) SETUP_XfOrM106(x)
      str = FUNCCALL(SETUP_XfOrM107(_), scheme_utf8_encode_to_buffer ((((Scheme_Simple_Object * ) (r ) ) -> u . char_str_val . string_val ) , (((Scheme_Simple_Object * ) (r ) ) -> u . char_str_val . tag_val ) , buf , 64 ) ); 
    }
    else str = (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (r ) ) ) -> s ) ; 
    (sprintf (buffer , "%.80s%d" , str , gensym_counter ++ ) ) ; 
    str = ((void * ) 0 ) ; 
  }
  else (sprintf (buffer , "g%d" , gensym_counter ++ ) ) ; 
  r = FUNCCALL(SETUP_XfOrM105(_), scheme_make_symbol (buffer ) ); 
  RET_VALUE_START (r ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_symbol_append (Scheme_Object * s1 , Scheme_Object * s2 ) {
  char * s ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(s1, 0), PUSH(s2, 1), PUSH(s, 2)));
# define XfOrM108_COUNT (3)
# define SETUP_XfOrM108(x) SETUP(XfOrM108_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  s = NULLED_OUT ; 
  s = ((char * ) FUNCCALL(SETUP_XfOrM108(_), GC_malloc_atomic (sizeof (char ) * ((((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (s1 ) ) ) -> len ) + (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (s2 ) ) ) -> len ) + 1 ) ) )) ; 
  (memcpy (s , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (s1 ) ) ) -> s ) , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (s1 ) ) ) -> len ) ) ) ; 
  (memcpy (s + (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (s1 ) ) ) -> len ) , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (s2 ) ) ) -> s ) , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (s2 ) ) ) -> len ) + 1 ) ) ; 
  if (((& ((Scheme_Symbol * ) (s1 ) ) -> iso ) -> so . keyex & 0x1 ) || ((& ((Scheme_Symbol * ) (s2 ) ) -> iso ) -> so . keyex & 0x1 ) )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_exact_symbol (s , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (s1 ) ) ) -> len ) + (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (s2 ) ) ) -> len ) ) )) RET_VALUE_EMPTY_END ; 
  else if (((& ((Scheme_Symbol * ) (s1 ) ) -> iso ) -> so . keyex & 0x2 ) || ((& ((Scheme_Symbol * ) (s2 ) ) -> iso ) -> so . keyex & 0x2 ) )
    RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_intern_exact_parallel_symbol (s , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (s1 ) ) ) -> len ) + (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (s2 ) ) ) -> len ) ) )) RET_VALUE_EMPTY_END ; 
  else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_intern_exact_symbol (s , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (s1 ) ) ) -> len ) + (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (s2 ) ) ) -> len ) ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
