#include "precomp.h"
extern void * dlopen (__const char * __file , int __mode ) __attribute__ ((__nothrow__ ) ) ; 
extern int dlclose (void * __handle ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern void * dlsym (void * __restrict __handle , __const char * __restrict __name ) __attribute__ ((__nothrow__ ) ) __attribute__ ((__nonnull__ (2 ) ) ) ; 
extern char * dlerror (void ) __attribute__ ((__nothrow__ ) ) ; 
static Scheme_Object * load_extension (int argc , Scheme_Object * * argv ) ; 
static Scheme_Object * current_load_extension (int argc , Scheme_Object * argv [] ) ; 
static Scheme_Hash_Table * loaded_extensions ; 
static Scheme_Hash_Table * fullpath_loaded_extensions ; 
void scheme_init_dynamic_extension (Scheme_Env * env ) {
  Scheme_Object * __funcarg5 = NULLED_OUT ; 
  Scheme_Object * __funcarg4 = NULLED_OUT ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(env, 0)));
# define XfOrM1_COUNT (1)
# define SETUP_XfOrM1(x) SETUP(XfOrM1_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (scheme_starting_up ) {
#   define XfOrM2_COUNT (0+XfOrM1_COUNT)
#   define SETUP_XfOrM2(x) SETUP_XfOrM1(x)
    FUNCCALL(SETUP_XfOrM2(_), scheme_register_static ((void * ) & loaded_extensions , sizeof (loaded_extensions ) ) ); 
    FUNCCALL(SETUP_XfOrM2(_), scheme_register_static ((void * ) & fullpath_loaded_extensions , sizeof (fullpath_loaded_extensions ) ) ); 
    loaded_extensions = FUNCCALL_AGAIN(scheme_make_hash_table (SCHEME_hash_ptr ) ); 
    fullpath_loaded_extensions = FUNCCALL_AGAIN(scheme_make_hash_table (SCHEME_hash_string ) ); 
  }
  (__funcarg5 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_prim_w_everything (load_extension , 0 , "load-extension" , 1 , 1 , 0 , 0 , - 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("load-extension" , __funcarg5 , env ) )) ; 
  (__funcarg4 = FUNCCALL(SETUP_XfOrM1(_), scheme_register_parameter (current_load_extension , "current-load-extension" , MZCONFIG_LOAD_EXTENSION_HANDLER ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("current-load-extension" , __funcarg4 , env ) )) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * current_load_extension (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return scheme_param_config ("current-load-extension" , ((Scheme_Object * ) (void * ) (long ) ((((long ) (MZCONFIG_LOAD_EXTENSION_HANDLER ) ) << 1 ) | 0x1 ) ) , argc , argv , 2 , ((void * ) 0 ) , ((void * ) 0 ) , 0 ) ; 
}
typedef Scheme_Object * (* Init_Procedure ) (Scheme_Env * ) ; 
typedef Scheme_Object * (* Reload_Procedure ) (Scheme_Env * ) ; 
typedef Scheme_Object * (* Modname_Procedure ) (void ) ; 
typedef struct {
  void * handle ; 
  Init_Procedure init_f ; 
  Reload_Procedure reload_f ; 
  Modname_Procedure modname_f ; 
}
ExtensionData ; 
static char * copy_vers (char * vers ) {
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(vers, 0)));
# define XfOrM4_COUNT (1)
# define SETUP_XfOrM4(x) SETUP(XfOrM4_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  if (vers ) {
    int len = strlen (vers ) ; 
    char * vcopy ; 
    BLOCK_SETUP((PUSH(vcopy, 0+XfOrM4_COUNT)));
#   define XfOrM5_COUNT (1+XfOrM4_COUNT)
#   define SETUP_XfOrM5(x) SETUP(XfOrM5_COUNT)
    vcopy = NULLED_OUT ; 
    vcopy = (char * ) FUNCCALL(SETUP_XfOrM5(_), GC_malloc_atomic (len + 1 ) ); 
    (memcpy (vcopy , vers , len + 1 ) ) ; 
    RET_VALUE_START (vcopy ) RET_VALUE_END ; 
  }
  else RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
typedef char * (* Setup_Procedure ) () ; 
static Scheme_Object * do_load_extension (const char * filename , Scheme_Object * expected_module , Scheme_Env * env ) {
  Init_Procedure init_f ; 
  Reload_Procedure reload_f ; 
  Modname_Procedure modname_f ; 
  ExtensionData * ed ; 
  void * handle ; 
  int comppath ; 
  char * __funcarg7 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(9);
  BLOCK_SETUP_TOP((PUSH(filename, 0), PUSH(handle, 1), PUSH(expected_module, 2), PUSH(env, 3), PUSH(ed, 4)));
# define XfOrM6_COUNT (5)
# define SETUP_XfOrM6(x) SETUP(XfOrM6_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  ed = NULLED_OUT ; 
  handle = NULLED_OUT ; 
  comppath = FUNCCALL(SETUP_XfOrM6(_), scheme_is_complete_path (filename , strlen (filename ) , scheme_unix_path_type ) ); 
  reload_f = ((void * ) 0 ) ; 
  modname_f = ((void * ) 0 ) ; 
  handle = ((void * ) 0 ) ; 
  if (comppath )
    init_f = (Init_Procedure ) FUNCCALL(SETUP_XfOrM6(_), scheme_hash_get (fullpath_loaded_extensions , (Scheme_Object * ) filename ) ); 
  else init_f = ((void * ) 0 ) ; 
  if (! init_f ) {
    void * dl ; 
    Setup_Procedure f ; 
    char * vers ; 
    BLOCK_SETUP((PUSH(dl, 0+XfOrM6_COUNT), PUSH(vers, 1+XfOrM6_COUNT)));
#   define XfOrM12_COUNT (2+XfOrM6_COUNT)
#   define SETUP_XfOrM12(x) SETUP(XfOrM12_COUNT)
    dl = NULLED_OUT ; 
    vers = NULLED_OUT ; 
    if (filename [0 ] != '/' ) {
      int l = strlen (filename ) ; 
      char * s ; 
      BLOCK_SETUP((PUSH(s, 0+XfOrM12_COUNT)));
#     define XfOrM17_COUNT (1+XfOrM12_COUNT)
#     define SETUP_XfOrM17(x) SETUP(XfOrM17_COUNT)
      s = NULLED_OUT ; 
      s = (char * ) FUNCCALL(SETUP_XfOrM17(_), GC_malloc_atomic (l + 3 ) ); 
      s [0 ] = '.' ; 
      s [1 ] = '/' ; 
      (memcpy (s + 2 , filename , l + 1 ) ) ; 
      filename = s ; 
    }
    dl = FUNCCALL(SETUP_XfOrM12(_), dlopen ((char * ) filename , (0x00002 ) ) ); 
    if (! dl )
      (__funcarg7 = FUNCCALL(SETUP_XfOrM12(_), dlerror () ), FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_FILESYSTEM , "load-extension: couldn't open \"%s\" (%s)" , filename , __funcarg7 ) )) ; 
    handle = dl ; 
    f = (Setup_Procedure ) FUNCCALL(SETUP_XfOrM12(_), dlsym (dl , "scheme_initialize_internal" ) ); 
    if (! f ) {
      const char * err ; 
      BLOCK_SETUP((PUSH(err, 0+XfOrM12_COUNT)));
#     define XfOrM16_COUNT (1+XfOrM12_COUNT)
#     define SETUP_XfOrM16(x) SETUP(XfOrM16_COUNT)
      err = NULLED_OUT ; 
      err = FUNCCALL(SETUP_XfOrM16(_), dlerror () ); 
      FUNCCALL_AGAIN(dlclose (dl ) ); 
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_FILESYSTEM , "load-extension: \"%s\" is not an extension (%s)" , filename , err ) ); 
    }
    vers = FUNCCALL(SETUP_XfOrM12(_), f () ); 
    if (! vers || (strcmp (vers , "372" "" "@3m" ) ) ) {
#     define XfOrM15_COUNT (0+XfOrM12_COUNT)
#     define SETUP_XfOrM15(x) SETUP_XfOrM12(x)
      vers = FUNCCALL(SETUP_XfOrM15(_), copy_vers (vers ) ); 
      FUNCCALL(SETUP_XfOrM15(_), dlclose (dl ) ); 
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_FILESYSTEM_VERSION , "load-extension: bad version %s (not %s) from \"%s\"" , vers , "372" "" "@3m" , filename ) ); 
    }
    init_f = (Init_Procedure ) FUNCCALL(SETUP_XfOrM12(_), dlsym (dl , "scheme_initialize" ) ); 
    if (init_f ) {
#     define XfOrM14_COUNT (0+XfOrM12_COUNT)
#     define SETUP_XfOrM14(x) SETUP_XfOrM12(x)
      reload_f = (Reload_Procedure ) FUNCCALL(SETUP_XfOrM14(_), dlsym (dl , "scheme_reload" ) ); 
      if (reload_f )
        modname_f = (Modname_Procedure ) FUNCCALL(SETUP_XfOrM14(_), dlsym (dl , "scheme_module_name" ) ); 
    }
    if (! init_f || ! reload_f || ! modname_f ) {
      const char * err ; 
      BLOCK_SETUP((PUSH(err, 0+XfOrM12_COUNT)));
#     define XfOrM13_COUNT (1+XfOrM12_COUNT)
#     define SETUP_XfOrM13(x) SETUP(XfOrM13_COUNT)
      err = NULLED_OUT ; 
      err = FUNCCALL(SETUP_XfOrM13(_), dlerror () ); 
      FUNCCALL_AGAIN(dlclose (dl ) ); 
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_FILESYSTEM , "load-extension: no %s in \"%s\" (%s)" , (init_f ? (reload_f ? "scheme_module_name" : "scheme_reload" ) : "scheme_initialize" ) , filename , err ) ); 
    }
    if (comppath )
      FUNCCALL(SETUP_XfOrM12(_), scheme_hash_set (fullpath_loaded_extensions , (Scheme_Object * ) filename , ((Scheme_Object * ) (((long ) init_f ) | 0x1 ) ) ) ); 
  }
  ed = (ExtensionData * ) FUNCCALL(SETUP_XfOrM6(_), scheme_hash_get (loaded_extensions , ((Scheme_Object * ) (((long ) init_f ) | 0x1 ) ) ) ); 
  if (ed ) {
    init_f = ed -> reload_f ; 
    modname_f = ed -> modname_f ; 
  }
  else {
#   define XfOrM10_COUNT (0+XfOrM6_COUNT)
#   define SETUP_XfOrM10(x) SETUP_XfOrM6(x)
    ed = ((ExtensionData * ) FUNCCALL(SETUP_XfOrM10(_), GC_malloc_atomic (sizeof (ExtensionData ) * (1 ) ) )) ; 
    ed -> handle = handle ; 
    ed -> init_f = init_f ; 
    ed -> reload_f = reload_f ; 
    ed -> modname_f = modname_f ; 
    FUNCCALL(SETUP_XfOrM10(_), scheme_hash_set (loaded_extensions , ((Scheme_Object * ) (((long ) init_f ) | 0x1 ) ) , (Scheme_Object * ) ed ) ); 
  }
  if (((Scheme_Type ) (((((long ) (expected_module ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (expected_module ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
    Scheme_Object * n ; 
    BLOCK_SETUP((PUSH(n, 0+XfOrM6_COUNT)));
#   define XfOrM7_COUNT (1+XfOrM6_COUNT)
#   define SETUP_XfOrM7(x) SETUP(XfOrM7_COUNT)
    n = NULLED_OUT ; 
    n = FUNCCALL(SETUP_XfOrM7(_), modname_f () ); 
    if (! ((expected_module ) == (n ) ) ) {
      Scheme_Object * other ; 
      BLOCK_SETUP((PUSH(other, 0+XfOrM7_COUNT)));
#     define XfOrM8_COUNT (1+XfOrM7_COUNT)
#     define SETUP_XfOrM8(x) SETUP(XfOrM8_COUNT)
      other = NULLED_OUT ; 
      if (n && ((Scheme_Type ) (((((long ) (n ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (n ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) ) {
        char * s , * t ; 
        long len , slen ; 
        BLOCK_SETUP((PUSH(t, 0+XfOrM8_COUNT), PUSH(s, 1+XfOrM8_COUNT)));
#       define XfOrM9_COUNT (2+XfOrM8_COUNT)
#       define SETUP_XfOrM9(x) SETUP(XfOrM9_COUNT)
        s = NULLED_OUT ; 
        t = NULLED_OUT ; 
        t = "module `" ; 
        len = strlen (t ) ; 
        slen = (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (n ) ) ) -> len ) ; 
        s = (char * ) FUNCCALL(SETUP_XfOrM9(_), GC_malloc_atomic (len + slen + 2 ) ); 
        (memcpy (s , t , len ) ) ; 
        (memcpy (s + len , (((Scheme_Symbol * ) ((Scheme_Simple_Object * ) (n ) ) ) -> s ) , slen ) ) ; 
        s [len + slen ] = '\'' ; 
        s [len + slen + 1 ] = 0 ; 
        other = FUNCCALL(SETUP_XfOrM9(_), scheme_make_sized_byte_string (s , len + slen + 1 , 0 ) ); 
      }
      else other = FUNCCALL(SETUP_XfOrM8(_), scheme_make_byte_string ("non-module" ) ); 
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_FILESYSTEM , "load-extension: expected module `%S', but found %T in: %s" , expected_module , other , filename ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
  }
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(init_f (env ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
void scheme_register_extension_global (void * ptr , long size ) {
  GC_add_roots ((char * ) ptr , (char * ) (((char * ) ptr ) + size + 1 ) ) ; 
}
static Scheme_Object * load_extension (int argc , Scheme_Object * * argv ) {
  /* No conversion */
  return scheme_load_with_clrd (argc , argv , "load-extension" , MZCONFIG_LOAD_EXTENSION_HANDLER ) ; 
}
Scheme_Object * scheme_default_load_extension (int argc , Scheme_Object * * argv ) {
  char * filename ; 
  Scheme_Object * expected_module ; 
  Scheme_Env * __funcarg9 = NULLED_OUT ; 
  Scheme_Object * __funcarg8 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(expected_module, 0), PUSH(filename, 1)));
# define XfOrM19_COUNT (2)
# define SETUP_XfOrM19(x) SETUP(XfOrM19_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  filename = NULLED_OUT ; 
  expected_module = NULLED_OUT ; 
  if (! (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_unix_path_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("default-load-extension-handler" , "path or string" , 0 , argc , argv ) ); 
  expected_module = argv [1 ] ; 
  if (! (((expected_module ) ) == (scheme_false ) ) && ! ((Scheme_Type ) (((((long ) (expected_module ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (expected_module ) ) -> type ) ) == (Scheme_Type ) (scheme_symbol_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type ("default-load-extension-handler" , "symbol or #f" , 1 , argc , argv ) ); 
  filename = FUNCCALL(SETUP_XfOrM19(_), scheme_expand_string_filename (argv [0 ] , "default-load-extension-handler" , ((void * ) 0 ) , 0x4 ) ); 
  RET_VALUE_START ((__funcarg8 = (__funcarg9 = FUNCCALL(SETUP_XfOrM19(_), scheme_get_env (((void * ) 0 ) ) ), FUNCCALL_AGAIN(do_load_extension (filename , expected_module , __funcarg9 ) )) , FUNCCALL_EMPTY(scheme_force_value (__funcarg8 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_load_extension (const char * filename , Scheme_Env * env ) {
  Scheme_Object * a [1 ] ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSHARRAY(a, 1, 0)));
# define XfOrM20_COUNT (3)
# define SETUP_XfOrM20(x) SETUP(XfOrM20_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  a[0] = NULLED_OUT ; 
  a [0 ] = FUNCCALL(SETUP_XfOrM20(_), scheme_make_byte_string (filename ) ); 
  RET_VALUE_START (FUNCCALL(SETUP_XfOrM20(_), load_extension (1 , a ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
