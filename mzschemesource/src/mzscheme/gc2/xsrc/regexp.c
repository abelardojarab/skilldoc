#include "precomp.h"
enum {
  mzu_Cn , mzu_Cc , mzu_Cf , mzu_Cs , mzu_Co , mzu_Ll , mzu_Lu , mzu_Lt , mzu_Lm , mzu_Lo , mzu_Nd , mzu_Nl , mzu_No , mzu_Ps , mzu_Pe , mzu_Pi , mzu_Pf , mzu_Pc , mzu_Pd , mzu_Po , mzu_Mn , mzu_Mc , mzu_Me , mzu_Sc , mzu_Sk , mzu_Sm , mzu_So , mzu_Zl , mzu_Zp , mzu_Zs }
; 
typedef long rxpos ; 
struct Regwork ; 
typedef int (* Scheme_Regexp_Matcher ) (struct Regwork * rw ) ; 
typedef struct regexp {
  Scheme_Type type ; 
  short keyex ; 
  Scheme_Object * source ; 
  long nsubexp , ncounter , maxlookback ; 
  long regsize ; 
  short flags ; 
  unsigned char * regstart ; 
  long regmust ; 
  long regmlen ; 
  char program [1 ] ; 
}
regexp ; 
typedef struct Regwork {
  Scheme_Type type ; 
  char * str ; 
  char * instr ; 
  Scheme_Object * port ; 
  Scheme_Object * unless_evt ; 
  short nonblock , aborted ; 
  rxpos instr_size ; 
  rxpos input_maxend ; 
  rxpos input , input_end , input_start ; 
  rxpos boi , bol ; 
  rxpos * startp ; 
  rxpos * maybep ; 
  rxpos * endp ; 
  int * counters ; 
  Scheme_Object * peekskip ; 
}
Regwork ; 
static regexp * regcomp (char * , rxpos , int , int ) ; 
static char * regstr , * regparsestr ; 
static int regmatchmin , regmatchmax , regmaxbackposn , regsavepos ; 
static Scheme_Hash_Table * regbackknown ; 
static Scheme_Hash_Table * regbackdepends ; 
static rxpos regparse , regparse_end ; 
static int regnpar ; 
static int regncounter ; 
static rxpos regcode ; 
static rxpos regcodesize ; 
static rxpos regcodemax ; 
static long regmaxlookback ; 
static rxpos reg (int , int * , int , int , int ) ; 
static rxpos regbranch (int * , int , int ) ; 
static rxpos regpiece (int * , int , int ) ; 
static rxpos regatom (int * , int , int ) ; 
static rxpos regranges (int parse_flags , int at_start ) ; 
static rxpos regunicode (int invert ) ; 
static int regdigit () ; 
static rxpos regnode (char ) ; 
static void regarg (int ) ; 
static rxpos regnext (rxpos ) ; 
static void regc (char ) ; 
static void reginsert (char , rxpos ) ; 
static rxpos reginsertwithop (char , rxpos , int ) ; 
static rxpos reginsertwithopop (char , rxpos , int , int ) ; 
static void regtail (rxpos , rxpos ) ; 
static void regoptail (rxpos , rxpos ) ; 
static int regstrcspn (char * , char * , char * ) ; 
static unsigned char * extract_regstart (rxpos scan , int * _anch ) ; 
static int check_and_propagate_depends (void ) ; 
static int merge_tables (Scheme_Hash_Table * dest , Scheme_Hash_Table * src ) ; 
static void regerror (char * s ) {
  /* No conversion */
  scheme_raise_exn (MZEXN_FAIL_CONTRACT , "regexp: %s" , s ) ; 
}
const char * failure_msg_for_read ; 
static void regcomperror (char * s ) {
  /* No conversion */
  if (failure_msg_for_read ) {
    failure_msg_for_read = s ; 
    (((long * ) (void * ) ((* (scheme_current_thread -> error_buf ) ) . gcvs ) ) [1 ] = (* (scheme_current_thread -> error_buf ) ) . gcvs_cnt , GC_variable_stack = (void * * ) (void * ) (* (scheme_current_thread -> error_buf ) ) . gcvs , scheme_jit_longjmp ((* (scheme_current_thread -> error_buf ) ) . jb , 1 ) ) ; 
  }
  else regerror (s ) ; 
}
static regexp * regcomp (char * expstr , rxpos exp , int explen , int pcre ) {
  regexp * r ; 
  rxpos scan , next ; 
  rxpos longest ; 
  int len , longest_is_ci ; 
  int flags ; 
  DECL_RET_SAVE (regexp * ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(r, 0)));
# define XfOrM4_COUNT (1)
# define SETUP_XfOrM4(x) SETUP(XfOrM4_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  r = NULLED_OUT ; 
  regstr = ((void * ) 0 ) ; 
  regparsestr = expstr ; 
  regparse = exp ; 
  regparse_end = exp + explen ; 
  regnpar = 1 ; 
  regncounter = 0 ; 
  regmaxlookback = 0 ; 
  regcode = 1 ; 
  regcodesize = 0 ; 
  regcodemax = 0 ; 
  regmaxbackposn = 0 ; 
  regbackknown = ((void * ) 0 ) ; 
  regbackdepends = ((void * ) 0 ) ; 
  FUNCCALL(SETUP_XfOrM4(_), regc (156 ) ); 
  if (FUNCCALL(SETUP_XfOrM4(_), reg (0 , & flags , 0 , 0 , 0x1 | 0x4 | (pcre ? 0x2 : 0 ) ) )== 0 ) {
#   define XfOrM25_COUNT (0+XfOrM4_COUNT)
#   define SETUP_XfOrM25(x) SETUP_XfOrM4(x)
    {
#     define XfOrM26_COUNT (0+XfOrM25_COUNT)
#     define SETUP_XfOrM26(x) SETUP_XfOrM25(x)
      FUNCCALL(SETUP_XfOrM26(_), regcomperror ("unknown regexp failure" ) ); 
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    ; 
  }
  if (regcodemax >= 32767L ) {
#   define XfOrM24_COUNT (0+XfOrM4_COUNT)
#   define SETUP_XfOrM24(x) SETUP_XfOrM4(x)
    FUNCCALL(SETUP_XfOrM24(_), regcomperror ("regexp too big" ) ); 
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  ; 
  if (regmaxbackposn >= regnpar ) {
#   define XfOrM23_COUNT (0+XfOrM4_COUNT)
#   define SETUP_XfOrM23(x) SETUP_XfOrM4(x)
    FUNCCALL(SETUP_XfOrM23(_), regcomperror ("backreference number is larger than the highest-numbered cluster" ) ); 
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  ; 
  r = (regexp * ) FUNCCALL(SETUP_XfOrM4(_), GC_malloc_one_tagged (sizeof (regexp ) + (unsigned ) regcodemax ) ); 
  r -> type = scheme_regexp_type ; 
  r -> regsize = regcodemax ; 
  r -> nsubexp = regnpar ; 
  r -> ncounter = regncounter ; 
  r -> maxlookback = regmaxlookback ; 
  regparse = exp ; 
  regparse_end = exp + explen ; 
  regnpar = 1 ; 
  regncounter = 0 ; 
  regcodesize = regcodemax ; 
  regstr = (char * ) r ; 
  regcode = (char * ) r -> program - (char * ) r ; 
  regcodesize += regcode ; 
  regcodemax = 0 ; 
  regbackknown = ((void * ) 0 ) ; 
  regbackdepends = ((void * ) 0 ) ; 
  FUNCCALL(SETUP_XfOrM4(_), regc (156 ) ); 
  if (FUNCCALL(SETUP_XfOrM4(_), reg (0 , & flags , 0 , 0 , 0x1 | 0x4 | (pcre ? 0x2 : 0 ) ) )== 0 ) {
#   define XfOrM21_COUNT (0+XfOrM4_COUNT)
#   define SETUP_XfOrM21(x) SETUP_XfOrM4(x)
    {
#     define XfOrM22_COUNT (0+XfOrM21_COUNT)
#     define SETUP_XfOrM22(x) SETUP_XfOrM21(x)
      FUNCCALL(SETUP_XfOrM22(_), regcomperror ("unknown regexp failure (late)" ) ); 
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    ; 
  }
  if (regcode >= regcodesize ) {
#   define XfOrM19_COUNT (0+XfOrM4_COUNT)
#   define SETUP_XfOrM19(x) SETUP_XfOrM4(x)
    {
#     define XfOrM20_COUNT (0+XfOrM19_COUNT)
#     define SETUP_XfOrM20(x) SETUP_XfOrM19(x)
      FUNCCALL(SETUP_XfOrM20(_), regcomperror ("wrote too far" ) ); 
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    ; 
  }
  r -> regstart = ((void * ) 0 ) ; 
  r -> regmust = - 1 ; 
  r -> regmlen = 0 ; 
  scan = ((r -> program + 1 ) - (char * ) r ) ; 
  {
    unsigned char * rs ; 
    int anch = 0 ; 
    BLOCK_SETUP((PUSH(rs, 0+XfOrM4_COUNT)));
#   define XfOrM18_COUNT (1+XfOrM4_COUNT)
#   define SETUP_XfOrM18(x) SETUP(XfOrM18_COUNT)
    rs = NULLED_OUT ; 
    rs = FUNCCALL(SETUP_XfOrM18(_), extract_regstart (scan , & anch ) ); 
    r -> regstart = rs ; 
    if (anch )
      r -> flags |= 0x04 ; 
  }
  next = FUNCCALL(SETUP_XfOrM4(_), regnext (scan ) ); 
  if ((regstr [next ] ) == 0 ) {
#   define XfOrM5_COUNT (0+XfOrM4_COUNT)
#   define SETUP_XfOrM5(x) SETUP_XfOrM4(x)
    scan = ((scan ) + 3 ) ; 
    if (flags & 0x04 ) {
#     define XfOrM6_COUNT (0+XfOrM5_COUNT)
#     define SETUP_XfOrM6(x) SETUP_XfOrM5(x)
      longest = 0 ; 
      longest_is_ci = 0 ; 
      len = 0 ; 
      for (; scan != 0 ; scan = FUNCCALL(SETUP_XfOrM6(_), regnext (scan ) )) {
        if ((((regstr [scan ] ) == 11 ) || ((regstr [scan ] ) == 12 ) ) && ((int ) (((unsigned char * ) regstr ) [((scan ) + 3 ) ] << 8 ) | (((unsigned char * ) regstr ) [((scan ) + 3 ) + 1 ] ) ) >= len ) {
          rxpos ls = (((scan ) + 3 ) + 2 ) ; 
          int ll = ((int ) (((unsigned char * ) regstr ) [((scan ) + 3 ) ] << 8 ) | (((unsigned char * ) regstr ) [((scan ) + 3 ) + 1 ] ) ) , i ; 
          for (i = 0 ; i < ll ; i ++ ) {
            if (! regstr [ls + i ] )
              break ; 
          }
          if (i >= ll ) {
            longest = ls ; 
            len = ll ; 
            longest_is_ci = ((regstr [scan ] ) == 12 ) ; 
          }
        }
      }
      if (longest ) {
        r -> regmust = longest ; 
        if (longest_is_ci )
          r -> flags |= 0x08 ; 
        r -> regmlen = len ; 
      }
    }
  }
  RET_VALUE_START ((r ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static unsigned char * map_create (unsigned char * map ) {
  DECL_RET_SAVE (unsigned char * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(map, 0)));
# define XfOrM27_COUNT (1)
# define SETUP_XfOrM27(x) SETUP(XfOrM27_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (! map ) {
#   define XfOrM28_COUNT (0+XfOrM27_COUNT)
#   define SETUP_XfOrM28(x) SETUP_XfOrM27(x)
    map = (unsigned char * ) FUNCCALL(SETUP_XfOrM28(_), GC_malloc_atomic (32 ) ); 
    (memset (map , 0 , 32 ) ) ; 
  }
  RET_VALUE_START (map ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static unsigned char * map_start (unsigned char * map , int c ) {
  DECL_RET_SAVE (unsigned char * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(map, 0)));
# define XfOrM29_COUNT (1)
# define SETUP_XfOrM29(x) SETUP(XfOrM29_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  map = FUNCCALL(SETUP_XfOrM29(_), map_create (map ) ); 
  map [c >> 3 ] |= ((unsigned char ) 1 << (c & 0x7 ) ) ; 
  RET_VALUE_START (map ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static unsigned char * map_copy (unsigned char * map , char * s , int pos ) {
  DECL_RET_SAVE (unsigned char * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(map, 0), PUSH(s, 1)));
# define XfOrM30_COUNT (2)
# define SETUP_XfOrM30(x) SETUP(XfOrM30_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  map = FUNCCALL(SETUP_XfOrM30(_), map_create (map ) ); 
  (memcpy (map , s XFORM_OK_PLUS pos , 32 ) ) ; 
  RET_VALUE_START (map ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static unsigned char * map_range (unsigned char * map , char * s , int pos , int invert ) {
  int rs , re ; 
  DECL_RET_SAVE (unsigned char * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(map, 0)));
# define XfOrM31_COUNT (1)
# define SETUP_XfOrM31(x) SETUP(XfOrM31_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  rs = ((unsigned char ) (s [pos ++ ] ) ) ; 
  re = ((unsigned char ) (s [pos ++ ] ) ) ; 
  if (! invert ) {
#   define XfOrM37_COUNT (0+XfOrM31_COUNT)
#   define SETUP_XfOrM37(x) SETUP_XfOrM31(x)
    while (rs <= re ) {
#     define XfOrM39_COUNT (0+XfOrM37_COUNT)
#     define SETUP_XfOrM39(x) SETUP_XfOrM37(x)
      map = FUNCCALL(SETUP_XfOrM39(_), map_start (map , rs ) ); 
      rs ++ ; 
    }
  }
  else {
#   define XfOrM32_COUNT (0+XfOrM31_COUNT)
#   define SETUP_XfOrM32(x) SETUP_XfOrM31(x)
    while (rs > 0 ) {
#     define XfOrM36_COUNT (0+XfOrM32_COUNT)
#     define SETUP_XfOrM36(x) SETUP_XfOrM32(x)
      map = FUNCCALL(SETUP_XfOrM36(_), map_start (map , rs - 1 ) ); 
      -- rs ; 
    }
    while (re < 255 ) {
#     define XfOrM34_COUNT (0+XfOrM32_COUNT)
#     define SETUP_XfOrM34(x) SETUP_XfOrM32(x)
      map = FUNCCALL(SETUP_XfOrM34(_), map_start (map , re + 1 ) ); 
      re ++ ; 
    }
  }
  RET_VALUE_START (map ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static unsigned char * extract_regstart (rxpos scan , int * _anch ) {
  rxpos next ; 
  int retry , the_op ; 
  unsigned char * map = ((void * ) 0 ) ; 
  DECL_RET_SAVE (unsigned char * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(map, 0), PUSH(_anch, 1)));
# define XfOrM40_COUNT (2)
# define SETUP_XfOrM40(x) SETUP(XfOrM40_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  do {
#   define XfOrM47_COUNT (0+XfOrM40_COUNT)
#   define SETUP_XfOrM47(x) SETUP_XfOrM40(x)
    retry = 0 ; 
    the_op = (regstr [scan ] ) ; 
    switch (the_op ) {
#     define XfOrM48_COUNT (0+XfOrM47_COUNT)
#     define SETUP_XfOrM48(x) SETUP_XfOrM47(x)
      case 39 : case 40 : case 13 : case 35 : case 36 : case 30 : case 31 : case 32 : scan = FUNCCALL(SETUP_XfOrM48(_), regnext (scan ) ); 
      retry = 1 ; 
      break ; 
      case 22 : case 23 : case 25 : case 26 : scan += ((int ) (((unsigned char * ) regstr ) [((scan ) + 3 ) ] << 8 ) | (((unsigned char * ) regstr ) [((scan ) + 3 ) + 1 ] ) ) ; 
      scan = FUNCCALL(SETUP_XfOrM48(_), regnext (scan ) ); 
      retry = 1 ; 
      break ; 
      case 24 : scan = FUNCCALL(SETUP_XfOrM48(_), regnext (scan ) ); 
      retry = 1 ; 
      break ; 
      case 15 : case 17 : scan = ((scan ) + 3 ) ; 
      retry = 1 ; 
      break ; 
      case 18 : case 19 : if (((int ) (((unsigned char * ) regstr ) [((scan ) + 3 ) ] << 8 ) | (((unsigned char * ) regstr ) [((scan ) + 3 ) + 1 ] ) ) > 0 ) {
        scan = ((scan ) + 7 ) ; 
        retry = 1 ; 
      }
      break ; 
      case 11 : map = FUNCCALL(SETUP_XfOrM48(_), map_start (map , ((unsigned char ) (regstr [(((scan ) + 3 ) + 2 ) ] ) ) ) ); 
      break ; 
      case 12 : {
        int c = ((unsigned char ) (regstr [(((scan ) + 3 ) + 2 ) ] ) ) ; 
#       define XfOrM51_COUNT (0+XfOrM48_COUNT)
#       define SETUP_XfOrM51(x) SETUP_XfOrM48(x)
        map = FUNCCALL(SETUP_XfOrM51(_), map_start (map , c ) ); 
        map = FUNCCALL(SETUP_XfOrM51(_), map_start (map , (((c >= 'a' ) && (c <= 'z' ) ) ? (c - ('a' - 'A' ) ) : c ) ) ); 
      }
      break ; 
      case 5 : map = FUNCCALL(SETUP_XfOrM48(_), map_copy (map , regstr , ((scan ) + 3 ) ) ); 
      break ; 
      case 6 : map = FUNCCALL(SETUP_XfOrM48(_), map_start (map , ((unsigned char ) (regstr [((scan ) + 3 ) ] ) ) ) ); 
      break ; 
      case 7 : map = FUNCCALL(SETUP_XfOrM48(_), map_range (map , regstr , ((scan ) + 3 ) , 0 ) ); 
      break ; 
      case 8 : map = FUNCCALL(SETUP_XfOrM48(_), map_range (map , regstr , ((scan ) + 3 ) , 1 ) ); 
      break ; 
      case 1 : if (_anch )
        * _anch = 1 ; 
      break ; 
      case 9 : next = FUNCCALL(SETUP_XfOrM48(_), regnext (scan ) ); 
      if (! next || ((regstr [next ] ) == 0 ) || ((regstr [next ] ) == 27 ) ) {
        scan = ((scan ) + 3 ) ; 
        retry = 1 ; 
      }
      break ; 
      default : if ((the_op == 20 ) || (the_op >= 43 && the_op < 77 ) ) {
        scan = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
        retry = 1 ; 
      }
      break ; 
    }
  }
  while (retry ) ; 
  RET_VALUE_START (map ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * reg_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  int * flagp = (int * ) p -> ku . k . p1 ; 
  int res ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  res = reg (p -> ku . k . i1 , flagp , p -> ku . k . i2 , p -> ku . k . i3 , p -> ku . k . i4 ) ; 
  return ((Scheme_Object * ) (void * ) (long ) ((((long ) (res ) ) << 1 ) | 0x1 ) ) ; 
}
static rxpos reg (int paren , int * flagp , int paren_set , int lookahead , int parse_flags ) {
  rxpos ret ; 
  rxpos br ; 
  rxpos ender ; 
  int parno = 0 ; 
  int flags , matchmin , matchmax , brcount ; 
  Scheme_Hash_Table * backdepends ; 
  DECL_RET_SAVE (rxpos ) PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(flagp, 0), PUSH(backdepends, 1)));
# define XfOrM54_COUNT (2)
# define SETUP_XfOrM54(x) SETUP(XfOrM54_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  backdepends = NULLED_OUT ; 
  {
    unsigned long _stk_pos ; 
#   define XfOrM106_COUNT (0+XfOrM54_COUNT)
#   define SETUP_XfOrM106(x) SETUP_XfOrM54(x)
    _stk_pos = (unsigned long ) & _stk_pos ; 
    if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
      Scheme_Thread * p = scheme_current_thread ; 
      Scheme_Object * ov ; 
      BLOCK_SETUP((PUSH(ov, 0+XfOrM106_COUNT)));
#     define XfOrM107_COUNT (1+XfOrM106_COUNT)
#     define SETUP_XfOrM107(x) SETUP(XfOrM107_COUNT)
      ov = NULLED_OUT ; 
      p -> ku . k . i1 = paren ; 
      p -> ku . k . p1 = (void * ) flagp ; 
      p -> ku . k . i2 = paren_set ; 
      p -> ku . k . i3 = lookahead ; 
      p -> ku . k . i4 = parse_flags ; 
      ov = FUNCCALL(SETUP_XfOrM107(_), scheme_handle_stack_overflow (reg_k ) ); 
      RET_VALUE_START ((((long ) (ov ) ) >> 1 ) ) RET_VALUE_END ; 
    }
  }
  * flagp = 0x01 ; 
  if (paren ) {
#   define XfOrM100_COUNT (0+XfOrM54_COUNT)
#   define SETUP_XfOrM100(x) SETUP_XfOrM54(x)
    if (lookahead ) {
#     define XfOrM104_COUNT (0+XfOrM100_COUNT)
#     define SETUP_XfOrM104(x) SETUP_XfOrM100(x)
      parno = 0 ; 
      ret = FUNCCALL(SETUP_XfOrM104(_), regnode (lookahead ) ); 
      FUNCCALL_AGAIN(regarg (0 ) ); 
      if ((lookahead == 25 ) || (lookahead == 26 ) ) {
#       define XfOrM105_COUNT (0+XfOrM104_COUNT)
#       define SETUP_XfOrM105(x) SETUP_XfOrM104(x)
        FUNCCALL(SETUP_XfOrM105(_), regarg (0 ) ); 
        FUNCCALL(SETUP_XfOrM105(_), regarg (0 ) ); 
      }
    }
    else if (paren_set ) {
#     define XfOrM101_COUNT (0+XfOrM100_COUNT)
#     define SETUP_XfOrM101(x) SETUP_XfOrM100(x)
      parno = regnpar ; 
      regnpar ++ ; 
      if (43 + parno >= 77 ) {
#       define XfOrM103_COUNT (0+XfOrM101_COUNT)
#       define SETUP_XfOrM103(x) SETUP_XfOrM101(x)
        ret = FUNCCALL(SETUP_XfOrM103(_), regnode (20 ) ); 
        FUNCCALL(SETUP_XfOrM103(_), regarg (parno ) ); 
      }
      else {
#       define XfOrM102_COUNT (0+XfOrM101_COUNT)
#       define SETUP_XfOrM102(x) SETUP_XfOrM101(x)
        ret = FUNCCALL(SETUP_XfOrM102(_), regnode (43 + parno ) ); 
      }
    }
    else ret = 0 ; 
  }
  else ret = 0 ; 
  br = FUNCCALL(SETUP_XfOrM54(_), regbranch (& flags , parse_flags , 0 ) ); 
  if (br == 0 ) {
#   define XfOrM99_COUNT (0+XfOrM54_COUNT)
#   define SETUP_XfOrM99(x) SETUP_XfOrM54(x)
    FUNCCALL(SETUP_XfOrM99(_), regcomperror ("branch failed!?" ) ); 
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  ; 
  if (ret != 0 )
    FUNCCALL(SETUP_XfOrM54(_), regtail (ret , br ) ); 
  else ret = br ; 
  if (! (flags & 0x01 ) ) {
    * flagp &= ~ 0x01 ; 
    backdepends = ((void * ) 0 ) ; 
  }
  else if (regbackdepends ) {
    backdepends = regbackdepends ; 
    regbackdepends = ((void * ) 0 ) ; 
  }
  else backdepends = ((void * ) 0 ) ; 
  * flagp |= flags & (0x04 | 0x08 ) ; 
  matchmin = regmatchmin ; 
  matchmax = regmatchmax ; 
  brcount = 1 ; 
  while (regparsestr [regparse ] == '|' ) {
    brcount ++ ; 
    regparse ++ ; 
#   define XfOrM92_COUNT (0+XfOrM54_COUNT)
#   define SETUP_XfOrM92(x) SETUP_XfOrM54(x)
    br = FUNCCALL(SETUP_XfOrM92(_), regbranch (& flags , parse_flags , 0 ) ); 
    if (br == 0 ) {
#     define XfOrM96_COUNT (0+XfOrM92_COUNT)
#     define SETUP_XfOrM96(x) SETUP_XfOrM92(x)
      FUNCCALL(SETUP_XfOrM96(_), regcomperror ("next branch failed!?" ) ); 
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    ; 
    FUNCCALL(SETUP_XfOrM92(_), regtail (ret , br ) ); 
    if (! (flags & 0x01 ) )
      * flagp &= ~ 0x01 ; 
    else if ((* flagp ) & 0x01 ) {
#     define XfOrM94_COUNT (0+XfOrM92_COUNT)
#     define SETUP_XfOrM94(x) SETUP_XfOrM92(x)
      if (regbackdepends ) {
#       define XfOrM95_COUNT (0+XfOrM94_COUNT)
#       define SETUP_XfOrM95(x) SETUP_XfOrM94(x)
        if (backdepends )
          FUNCCALL(SETUP_XfOrM95(_), merge_tables (backdepends , regbackdepends ) ); 
        else backdepends = regbackdepends ; 
        regbackdepends = ((void * ) 0 ) ; 
      }
      else backdepends = ((void * ) 0 ) ; 
    }
    * flagp |= flags & 0x04 ; 
    if (! (flags & 0x08 ) )
      * flagp &= ~ 0x08 ; 
    else {
      if (regmatchmin < matchmin )
        matchmin = regmatchmin ; 
      if (regmatchmax > matchmax )
        matchmax = regmatchmax ; 
    }
  }
  regbackdepends = backdepends ; 
  regmatchmin = matchmin ; 
  regmatchmax = matchmax ; 
  if (paren && paren_set ) {
    Scheme_Object * assumed ; 
    BLOCK_SETUP((PUSH(assumed, 0+XfOrM54_COUNT)));
#   define XfOrM80_COUNT (1+XfOrM54_COUNT)
#   define SETUP_XfOrM80(x) SETUP(XfOrM80_COUNT)
    assumed = NULLED_OUT ; 
    if (! regbackknown )
      regbackknown = FUNCCALL(SETUP_XfOrM80(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
    assumed = FUNCCALL(SETUP_XfOrM80(_), scheme_hash_get (regbackknown , ((Scheme_Object * ) (void * ) (long ) ((((long ) (parno ) ) << 1 ) | 0x1 ) ) ) ); 
    if (! ((* flagp ) & 0x01 ) ) {
#     define XfOrM84_COUNT (0+XfOrM80_COUNT)
#     define SETUP_XfOrM84(x) SETUP_XfOrM80(x)
      if (assumed && ! (((assumed ) ) == (scheme_false ) ) ) {
#       define XfOrM85_COUNT (0+XfOrM84_COUNT)
#       define SETUP_XfOrM85(x) SETUP_XfOrM84(x)
        {
#         define XfOrM86_COUNT (0+XfOrM85_COUNT)
#         define SETUP_XfOrM86(x) SETUP_XfOrM85(x)
          FUNCCALL(SETUP_XfOrM86(_), regcomperror ("`*', `+', or `{...,}' operand can be empty due to backreference" ) ); 
          RET_VALUE_START (0 ) RET_VALUE_END ; 
        }
        ; 
      }
      FUNCCALL(SETUP_XfOrM84(_), scheme_hash_set (regbackknown , ((Scheme_Object * ) (void * ) (long ) ((((long ) (parno ) ) << 1 ) | 0x1 ) ) , scheme_false ) ); 
    }
    else {
#     define XfOrM81_COUNT (0+XfOrM80_COUNT)
#     define SETUP_XfOrM81(x) SETUP_XfOrM80(x)
      if (! backdepends )
        FUNCCALL(SETUP_XfOrM81(_), scheme_hash_set (regbackknown , ((Scheme_Object * ) (void * ) (long ) ((((long ) (parno ) ) << 1 ) | 0x1 ) ) , scheme_true ) ); 
      else {
#       define XfOrM82_COUNT (0+XfOrM81_COUNT)
#       define SETUP_XfOrM82(x) SETUP_XfOrM81(x)
        if (assumed ) {
#         define XfOrM83_COUNT (0+XfOrM82_COUNT)
#         define SETUP_XfOrM83(x) SETUP_XfOrM82(x)
          FUNCCALL(SETUP_XfOrM83(_), check_and_propagate_depends () ); 
        }
        else FUNCCALL(SETUP_XfOrM82(_), scheme_hash_set (regbackknown , ((Scheme_Object * ) (void * ) (long ) ((((long ) (parno ) ) << 1 ) | 0x1 ) ) , (Scheme_Object * ) backdepends ) ); 
      }
    }
  }
  if ((brcount == 1 ) && paren && (! paren_set || ((flags & 0x08 ) && (regmatchmin == regmatchmax ) && (regmatchmax < 0x7FFFF ) ) ) && ! lookahead ) {
#   define XfOrM77_COUNT (0+XfOrM54_COUNT)
#   define SETUP_XfOrM77(x) SETUP_XfOrM54(x)
    if (br + 3 < regcodesize ) {
      int top ; 
#     define XfOrM79_COUNT (0+XfOrM77_COUNT)
#     define SETUP_XfOrM79(x) SETUP_XfOrM77(x)
      if (regcode <= regcodesize )
        top = regcode ; 
      else top = regcodesize ; 
      (memmove (regstr + ret , regstr + br + 3 , top - (br + 3 ) ) ) ; 
    }
    * flagp = flags ; 
    regcode -= (br + 3 - ret ) ; 
    if (paren_set ) {
      * flagp |= 0x10 ; 
      * flagp &= ~ 0x20 ; 
      regsavepos = parno ; 
    }
  }
  else {
#   define XfOrM61_COUNT (0+XfOrM54_COUNT)
#   define SETUP_XfOrM61(x) SETUP_XfOrM54(x)
    if (lookahead ) {
#     define XfOrM72_COUNT (0+XfOrM61_COUNT)
#     define SETUP_XfOrM72(x) SETUP_XfOrM61(x)
      if ((lookahead == 25 ) || (lookahead == 26 ) ) {
#       define XfOrM73_COUNT (0+XfOrM72_COUNT)
#       define SETUP_XfOrM73(x) SETUP_XfOrM72(x)
        if (! ((* flagp ) & 0x08 ) ) {
#         define XfOrM76_COUNT (0+XfOrM73_COUNT)
#         define SETUP_XfOrM76(x) SETUP_XfOrM73(x)
          FUNCCALL_EMPTY(regcomperror ("lookbehind pattern does not match a bounded byte width" ) ); 
          RET_VALUE_START (0 ) RET_VALUE_END ; 
        }
        ; 
        if (matchmax > 0x7FFF ) {
#         define XfOrM75_COUNT (0+XfOrM73_COUNT)
#         define SETUP_XfOrM75(x) SETUP_XfOrM73(x)
          FUNCCALL_EMPTY(regcomperror ("lookbehind match is potentially too long (more than 32767 bytes)" ) ); 
          RET_VALUE_START (0 ) RET_VALUE_END ; 
        }
        ; 
        if (matchmax > regmaxlookback )
          regmaxlookback = matchmax ; 
        if (ret + 8 < regcodesize ) {
          regstr [ret + 5 ] = (matchmin >> 8 ) ; 
          regstr [ret + 6 ] = (matchmin & 255 ) ; 
          regstr [ret + 7 ] = (matchmax >> 8 ) ; 
          regstr [ret + 8 ] = (matchmax & 255 ) ; 
        }
      }
    }
    if (paren ) {
#     define XfOrM66_COUNT (0+XfOrM61_COUNT)
#     define SETUP_XfOrM66(x) SETUP_XfOrM61(x)
      if (lookahead ) {
#       define XfOrM70_COUNT (0+XfOrM66_COUNT)
#       define SETUP_XfOrM70(x) SETUP_XfOrM66(x)
        ender = FUNCCALL_EMPTY(regnode (27 ) ); 
        if (ret + 4 < regcodesize ) {
          int delta = (ender - ret ) ; 
          regstr [ret + 3 ] = (delta >> 8 ) ; 
          regstr [ret + 4 ] = (delta & 255 ) ; 
        }
      }
      else if (paren_set ) {
#       define XfOrM68_COUNT (0+XfOrM66_COUNT)
#       define SETUP_XfOrM68(x) SETUP_XfOrM66(x)
        if (43 + parno >= 77 ) {
#         define XfOrM69_COUNT (0+XfOrM68_COUNT)
#         define SETUP_XfOrM69(x) SETUP_XfOrM68(x)
          ender = regcode ; 
          FUNCCALL_EMPTY(regarg (parno ) ); 
          FUNCCALL_EMPTY(reginsert (21 , ender ) ); 
        }
        else ender = FUNCCALL_EMPTY(regnode (77 + parno ) ); 
      }
      else {
#       define XfOrM67_COUNT (0+XfOrM66_COUNT)
#       define SETUP_XfOrM67(x) SETUP_XfOrM66(x)
        ender = FUNCCALL_EMPTY(regnode (13 ) ); 
      }
    }
    else {
#     define XfOrM65_COUNT (0+XfOrM61_COUNT)
#     define SETUP_XfOrM65(x) SETUP_XfOrM61(x)
      ender = FUNCCALL_EMPTY(regnode (0 ) ); 
    }
    FUNCCALL_EMPTY(regtail (ret , ender ) ); 
    if (regcodesize ) {
#     define XfOrM62_COUNT (0+XfOrM61_COUNT)
#     define SETUP_XfOrM62(x) SETUP_XfOrM61(x)
      for (br = ret ; br != 0 ; br = FUNCCALL_EMPTY(regnext (br ) )) {
#       define XfOrM64_COUNT (0+XfOrM62_COUNT)
#       define SETUP_XfOrM64(x) SETUP_XfOrM62(x)
        FUNCCALL_EMPTY(regoptail (br , ender ) ); 
      }
    }
  }
  if (paren && regparsestr [regparse ++ ] != ')' ) {
#   define XfOrM59_COUNT (0+XfOrM54_COUNT)
#   define SETUP_XfOrM59(x) SETUP_XfOrM54(x)
    {
#     define XfOrM60_COUNT (0+XfOrM59_COUNT)
#     define SETUP_XfOrM60(x) SETUP_XfOrM59(x)
      FUNCCALL_EMPTY(regcomperror ("missing closing parenthesis in pattern" ) ); 
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    ; 
  }
  else if (! paren && regparse != regparse_end ) {
#   define XfOrM55_COUNT (0+XfOrM54_COUNT)
#   define SETUP_XfOrM55(x) SETUP_XfOrM54(x)
    if (regparsestr [regparse ] == ')' ) {
#     define XfOrM57_COUNT (0+XfOrM55_COUNT)
#     define SETUP_XfOrM57(x) SETUP_XfOrM55(x)
      {
#       define XfOrM58_COUNT (0+XfOrM57_COUNT)
#       define SETUP_XfOrM58(x) SETUP_XfOrM57(x)
        FUNCCALL_EMPTY(regcomperror ("extra closing parenthesis in pattern" ) ); 
        RET_VALUE_START (0 ) RET_VALUE_END ; 
      }
      ; 
    }
    else {
#     define XfOrM56_COUNT (0+XfOrM55_COUNT)
#     define SETUP_XfOrM56(x) SETUP_XfOrM55(x)
      FUNCCALL_EMPTY(regcomperror ("junk on end" ) ); 
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    ; 
  }
  RET_VALUE_START (ret ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static rxpos regbranch (int * flagp , int parse_flags , int without_branch_node ) {
  rxpos ret ; 
  rxpos chain , latest ; 
  int flags = 0 , matchmin = 0 , matchmax = 0 , pcount = 0 , save_flags ; 
  DECL_RET_SAVE (rxpos ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(flagp, 0)));
# define XfOrM108_COUNT (1)
# define SETUP_XfOrM108(x) SETUP(XfOrM108_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  * flagp = (0 | 0x08 ) ; 
  if (! without_branch_node )
    ret = FUNCCALL(SETUP_XfOrM108(_), regnode (9 ) ); 
  else ret = 0 ; 
  chain = 0 ; 
  while (regparse != regparse_end && regparsestr [regparse ] != '|' && regparsestr [regparse ] != ')' ) {
#   define XfOrM116_COUNT (0+XfOrM108_COUNT)
#   define SETUP_XfOrM116(x) SETUP_XfOrM108(x)
    save_flags = flags ; 
    latest = FUNCCALL(SETUP_XfOrM116(_), regpiece (& flags , parse_flags , ! chain && ! without_branch_node ) ); 
    if (latest == 0 ) {
#     define XfOrM120_COUNT (0+XfOrM116_COUNT)
#     define SETUP_XfOrM120(x) SETUP_XfOrM116(x)
      FUNCCALL(SETUP_XfOrM120(_), regcomperror ("piece failed!?" ) ); 
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    ; 
    if (flags & 0x20 ) {
      regcode = latest ; 
      flags = save_flags ; 
    }
    else {
      pcount ++ ; 
#     define XfOrM117_COUNT (0+XfOrM116_COUNT)
#     define SETUP_XfOrM117(x) SETUP_XfOrM116(x)
      * flagp |= flags & 0x01 ; 
      if (chain == 0 ) {
        * flagp |= flags & 0x04 ; 
        if (without_branch_node )
          ret = latest ; 
      }
      else FUNCCALL(SETUP_XfOrM117(_), regtail (chain , latest ) ); 
      if (! (flags & 0x08 ) )
        * flagp &= ~ 0x08 ; 
      matchmin += regmatchmin ; 
      matchmax += regmatchmax ; 
      if (matchmax > 0x7FFF )
        matchmax = 0x10000 ; 
      chain = latest ; 
    }
  }
  regmatchmin = matchmin ; 
  regmatchmax = matchmax ; 
  if (chain == 0 ) {
#   define XfOrM110_COUNT (0+XfOrM108_COUNT)
#   define SETUP_XfOrM110(x) SETUP_XfOrM108(x)
    latest = FUNCCALL(SETUP_XfOrM110(_), regnode (13 ) ); 
    if (without_branch_node )
      ret = latest ; 
    * flagp = 0x02 | 0x20 | 0x08 ; 
    regmatchmin = regmatchmax = 0 ; 
  }
  if (pcount == 1 ) {
    * flagp = flags ; 
  }
  RET_VALUE_START ((ret ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static rxpos regpiece (int * flagp , int parse_flags , int at_start ) {
  rxpos ret ; 
  char op ; 
  rxpos next ; 
  int flags , greedy ; 
  int minreps = 0 , maxreps = 0 , counter ; 
  int origsavepos , origmatchmin , origmatchmax ; 
  rxpos __funcarg14 ; 
  rxpos __funcarg13 ; 
  rxpos __funcarg12 ; 
  rxpos __funcarg11 ; 
  rxpos __funcarg10 ; 
  rxpos __funcarg9 ; 
  rxpos __funcarg8 ; 
  rxpos __funcarg7 ; 
  rxpos __funcarg6 ; 
  rxpos __funcarg5 ; 
  rxpos __funcarg4 ; 
  DECL_RET_SAVE (rxpos ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(flagp, 0)));
# define XfOrM121_COUNT (1)
# define SETUP_XfOrM121(x) SETUP(XfOrM121_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ret = FUNCCALL(SETUP_XfOrM121(_), regatom (& flags , parse_flags , at_start ) ); 
  if (ret == 0 ) {
#   define XfOrM174_COUNT (0+XfOrM121_COUNT)
#   define SETUP_XfOrM174(x) SETUP_XfOrM121(x)
    FUNCCALL(SETUP_XfOrM174(_), regcomperror ("atom failed!?" ) ); 
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  ; 
  origsavepos = regsavepos ; 
  origmatchmin = regmatchmin ; 
  origmatchmax = regmatchmax ; 
  op = regparsestr [regparse ] ; 
  if (! ((op ) == '*' || (op ) == '+' || (op ) == '?' || ((parse_flags & 0x2 ) && ((op ) == '{' ) ) ) ) {
    * flagp = (flags & ~ 0x10 ) ; 
  }
  else {
#   define XfOrM124_COUNT (0+XfOrM121_COUNT)
#   define SETUP_XfOrM124(x) SETUP_XfOrM121(x)
    if (op == '{' ) {
      int ch , maxspec = 0 ; 
#     define XfOrM146_COUNT (0+XfOrM124_COUNT)
#     define SETUP_XfOrM146(x) SETUP_XfOrM124(x)
      minreps = maxreps = 0 ; 
      regparse ++ ; 
      do {
#       define XfOrM168_COUNT (0+XfOrM146_COUNT)
#       define SETUP_XfOrM168(x) SETUP_XfOrM146(x)
        ch = regparsestr [regparse ] ; 
        if ((ch >= '0' ) && (ch <= '9' ) ) {
#         define XfOrM171_COUNT (0+XfOrM168_COUNT)
#         define SETUP_XfOrM171(x) SETUP_XfOrM168(x)
          minreps = (minreps * 10 ) + (ch - '0' ) ; 
          if (minreps > 0x7FFF ) {
#           define XfOrM172_COUNT (0+XfOrM171_COUNT)
#           define SETUP_XfOrM172(x) SETUP_XfOrM171(x)
            FUNCCALL(SETUP_XfOrM172(_), regcomperror ("minimum repetition count too large" ) ); 
            RET_VALUE_START (0 ) RET_VALUE_END ; 
          }
          ; 
          regparse ++ ; 
        }
        else if (ch == ',' || ch == '}' )
          break ; 
        else {
#         define XfOrM169_COUNT (0+XfOrM168_COUNT)
#         define SETUP_XfOrM169(x) SETUP_XfOrM168(x)
          {
#           define XfOrM170_COUNT (0+XfOrM169_COUNT)
#           define SETUP_XfOrM170(x) SETUP_XfOrM169(x)
            FUNCCALL(SETUP_XfOrM170(_), regcomperror ("expected digit, comma, or `}' to end repetition specification started with `{'" ) ); 
            RET_VALUE_START (0 ) RET_VALUE_END ; 
          }
          ; 
        }
      }
      while (1 ) ; 
      if (ch == ',' ) {
        regparse ++ ; 
#       define XfOrM152_COUNT (0+XfOrM146_COUNT)
#       define SETUP_XfOrM152(x) SETUP_XfOrM146(x)
        do {
#         define XfOrM158_COUNT (0+XfOrM152_COUNT)
#         define SETUP_XfOrM158(x) SETUP_XfOrM152(x)
          ch = regparsestr [regparse ] ; 
          if ((ch >= '0' ) && (ch <= '9' ) ) {
#           define XfOrM161_COUNT (0+XfOrM158_COUNT)
#           define SETUP_XfOrM161(x) SETUP_XfOrM158(x)
            maxspec = 1 ; 
            maxreps = (maxreps * 10 ) + (ch - '0' ) ; 
            if (maxreps > 0x7FFF ) {
#             define XfOrM162_COUNT (0+XfOrM161_COUNT)
#             define SETUP_XfOrM162(x) SETUP_XfOrM161(x)
              FUNCCALL(SETUP_XfOrM162(_), regcomperror ("maximum repetition count too large" ) ); 
              RET_VALUE_START (0 ) RET_VALUE_END ; 
            }
            ; 
            regparse ++ ; 
          }
          else if (ch == '}' )
            break ; 
          else {
#           define XfOrM159_COUNT (0+XfOrM158_COUNT)
#           define SETUP_XfOrM159(x) SETUP_XfOrM158(x)
            {
#             define XfOrM160_COUNT (0+XfOrM159_COUNT)
#             define SETUP_XfOrM160(x) SETUP_XfOrM159(x)
              FUNCCALL(SETUP_XfOrM160(_), regcomperror ("expected digit or `}' to end repetition specification started with `{'" ) ); 
              RET_VALUE_START (0 ) RET_VALUE_END ; 
            }
            ; 
          }
        }
        while (1 ) ; 
      }
      else {
        maxspec = 1 ; 
        maxreps = minreps ; 
      }
      if (maxspec && (maxreps < minreps ) ) {
#       define XfOrM149_COUNT (0+XfOrM146_COUNT)
#       define SETUP_XfOrM149(x) SETUP_XfOrM146(x)
        {
#         define XfOrM150_COUNT (0+XfOrM149_COUNT)
#         define SETUP_XfOrM150(x) SETUP_XfOrM149(x)
          FUNCCALL(SETUP_XfOrM150(_), regcomperror ("maximum repetition count is less than maximum repetition count" ) ); 
          RET_VALUE_START (0 ) RET_VALUE_END ; 
        }
        ; 
      }
      if (maxspec && ! maxreps ) {
        regparse ++ ; 
#       define XfOrM147_COUNT (0+XfOrM146_COUNT)
#       define SETUP_XfOrM147(x) SETUP_XfOrM146(x)
        if (regparsestr [regparse ] == '?' )
          regparse ++ ; 
        if (((regparsestr [regparse ] ) == '*' || (regparsestr [regparse ] ) == '+' || (regparsestr [regparse ] ) == '?' || ((parse_flags & 0x2 ) && ((regparsestr [regparse ] ) == '{' ) ) ) ) {
#         define XfOrM148_COUNT (0+XfOrM147_COUNT)
#         define SETUP_XfOrM148(x) SETUP_XfOrM147(x)
          FUNCCALL(SETUP_XfOrM148(_), regcomperror ("nested `*', `?', `+', or `{...}' in pattern" ) ); 
          RET_VALUE_START (0 ) RET_VALUE_END ; 
        }
        ; 
        regcode = ret ; 
        * flagp = 0x08 | 0x20 ; 
        regmatchmin = regmatchmax = 0 ; 
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(regnode (13 ) )) RET_VALUE_EMPTY_END ; 
      }
      op = '*' ; 
      if (maxreps || minreps )
        counter = regncounter ++ ; 
      else counter = 0 ; 
    }
    else counter = 0 ; 
    if (! (flags & 0x01 ) && (op != '?' ) ) {
#     define XfOrM144_COUNT (0+XfOrM124_COUNT)
#     define SETUP_XfOrM144(x) SETUP_XfOrM124(x)
      {
#       define XfOrM145_COUNT (0+XfOrM144_COUNT)
#       define SETUP_XfOrM145(x) SETUP_XfOrM144(x)
        FUNCCALL(SETUP_XfOrM145(_), regcomperror ("`*', `+', or `{...}' operand could be empty" ) ); 
        RET_VALUE_START (0 ) RET_VALUE_END ; 
      }
      ; 
    }
    if (regbackdepends ) {
#     define XfOrM143_COUNT (0+XfOrM124_COUNT)
#     define SETUP_XfOrM143(x) SETUP_XfOrM124(x)
      FUNCCALL(SETUP_XfOrM143(_), check_and_propagate_depends () ); 
      regbackdepends = ((void * ) 0 ) ; 
    }
    if (maxreps || minreps ) {
      if (minreps > 0 )
        * flagp = 0x01 ; 
      if ((flags & 0x08 ) && maxreps ) {
        regmatchmin = (origmatchmin * minreps ) ; 
        regmatchmax = (origmatchmax * maxreps ) ; 
        if (regmatchmax > 0x7FFF )
          regmatchmax = 0x10000 ; 
        * flagp |= 0x08 ; 
      }
    }
    else * flagp = (op != '+' ) ? 0 : 0x01 ; 
    * flagp |= 0x04 ; 
    if (regparsestr [regparse + 1 ] == '?' ) {
      greedy = 0 ; 
      regparse ++ ; 
    }
    else greedy = 1 ; 
    if (op == '*' && (flags & 0x02 ) ) {
#     define XfOrM139_COUNT (0+XfOrM124_COUNT)
#     define SETUP_XfOrM139(x) SETUP_XfOrM124(x)
      if (! minreps && ! maxreps )
        FUNCCALL(SETUP_XfOrM139(_), reginsert (greedy ? 14 : 16 , ret ) ); 
      else FUNCCALL(SETUP_XfOrM139(_), reginsertwithopop (greedy ? 18 : 19 , ret , minreps , maxreps ) ); 
    }
    else if (op == '*' && greedy ) {
      rxpos br , nothing ; 
#     define XfOrM134_COUNT (0+XfOrM124_COUNT)
#     define SETUP_XfOrM134(x) SETUP_XfOrM124(x)
      if (minreps || maxreps ) {
        rxpos x ; 
#       define XfOrM138_COUNT (0+XfOrM134_COUNT)
#       define SETUP_XfOrM138(x) SETUP_XfOrM134(x)
        x = FUNCCALL(SETUP_XfOrM138(_), reginsertwithopop (32 , ret , counter , maxreps ) ); 
        FUNCCALL(SETUP_XfOrM138(_), regtail (ret , x ) ); 
      }
      FUNCCALL(SETUP_XfOrM134(_), reginsert (9 , ret ) ); 
      if (minreps || maxreps ) {
#       define XfOrM137_COUNT (0+XfOrM134_COUNT)
#       define SETUP_XfOrM137(x) SETUP_XfOrM134(x)
        br = FUNCCALL(SETUP_XfOrM137(_), reginsertwithop (30 , ret , counter ) ); 
        FUNCCALL(SETUP_XfOrM137(_), regtail (ret , br ) ); 
      }
      else br = ret ; 
      (__funcarg14 = FUNCCALL(SETUP_XfOrM134(_), regnode (10 ) ), FUNCCALL_AGAIN(regoptail (br , __funcarg14 ) )) ; 
      FUNCCALL_AGAIN(regoptail (br , br ) ); 
      (__funcarg13 = FUNCCALL(SETUP_XfOrM134(_), regnode (9 ) ), FUNCCALL_AGAIN(regtail (br , __funcarg13 ) )) ; 
      nothing = FUNCCALL_AGAIN(regnode (13 ) ); 
      if (minreps ) {
        rxpos n ; 
#       define XfOrM136_COUNT (0+XfOrM134_COUNT)
#       define SETUP_XfOrM136(x) SETUP_XfOrM134(x)
        n = FUNCCALL(SETUP_XfOrM136(_), reginsertwithopop (31 , nothing , counter , minreps ) ); 
        FUNCCALL(SETUP_XfOrM136(_), regtail (nothing , n ) ); 
      }
      if (minreps || maxreps ) {
        rxpos n ; 
#       define XfOrM135_COUNT (0+XfOrM134_COUNT)
#       define SETUP_XfOrM135(x) SETUP_XfOrM134(x)
        n = FUNCCALL(SETUP_XfOrM135(_), reginsertwithop (33 , nothing , counter ) ); 
        FUNCCALL(SETUP_XfOrM135(_), regtail (nothing , n ) ); 
      }
      FUNCCALL(SETUP_XfOrM134(_), regtail (br , nothing ) ); 
    }
    else if (op == '*' ) {
      rxpos br , nothing , x , next_to_x ; 
#     define XfOrM130_COUNT (0+XfOrM124_COUNT)
#     define SETUP_XfOrM130(x) SETUP_XfOrM124(x)
      if (minreps || maxreps ) {
        rxpos fail ; 
#       define XfOrM133_COUNT (0+XfOrM130_COUNT)
#       define SETUP_XfOrM133(x) SETUP_XfOrM130(x)
        x = FUNCCALL(SETUP_XfOrM133(_), reginsertwithopop (32 , ret , counter , maxreps ) ); 
        FUNCCALL(SETUP_XfOrM133(_), regtail (ret , x ) ); 
        fail = FUNCCALL_AGAIN(regnode (9 ) ); 
        FUNCCALL_AGAIN(regnode (34 ) ); 
        FUNCCALL_AGAIN(regarg (counter ) ); 
        FUNCCALL_AGAIN(reginsert (9 , ret ) ); 
        fail += 3 ; 
        FUNCCALL(SETUP_XfOrM133(_), regtail (ret , fail ) ); 
        x += 3 ; 
      }
      else x = ret ; 
      FUNCCALL(SETUP_XfOrM130(_), reginsert (9 , ret ) ); 
      next = ret ; 
      next_to_x = (x - next ) + 3 ; 
      FUNCCALL(SETUP_XfOrM130(_), reginsert (13 , ret ) ); 
      next += 3 ; 
      nothing = ret ; 
      if (minreps ) {
#       define XfOrM132_COUNT (0+XfOrM130_COUNT)
#       define SETUP_XfOrM132(x) SETUP_XfOrM130(x)
        nothing = FUNCCALL(SETUP_XfOrM132(_), reginsertwithopop (31 , ret , counter , minreps ) ); 
        FUNCCALL(SETUP_XfOrM132(_), regtail (ret , nothing ) ); 
        next += (nothing - ret ) ; 
      }
      FUNCCALL(SETUP_XfOrM130(_), reginsert (9 , ret ) ); 
      next += 3 ; 
      nothing += 3 ; 
      if (minreps || maxreps ) {
#       define XfOrM131_COUNT (0+XfOrM130_COUNT)
#       define SETUP_XfOrM131(x) SETUP_XfOrM130(x)
        br = FUNCCALL(SETUP_XfOrM131(_), reginsertwithop (30 , ret , counter ) ); 
        FUNCCALL(SETUP_XfOrM131(_), regtail (ret , br ) ); 
        next += (br - ret ) ; 
        nothing += (br - ret ) ; 
      }
      else br = ret ; 
      FUNCCALL(SETUP_XfOrM130(_), regtail (br , next ) ); 
      x = next + next_to_x ; 
      (__funcarg12 = FUNCCALL(SETUP_XfOrM130(_), regnode (10 ) ), FUNCCALL_AGAIN(regtail (x , __funcarg12 ) )) ; 
      FUNCCALL_AGAIN(regtail (x , br ) ); 
      (__funcarg11 = FUNCCALL(SETUP_XfOrM130(_), regnode (10 ) ), FUNCCALL_AGAIN(regtail (next , __funcarg11 ) )) ; 
      FUNCCALL_AGAIN(regtail (next , nothing ) ); 
    }
    else if (op == '+' && (flags & 0x02 ) )
      FUNCCALL(SETUP_XfOrM124(_), reginsert (greedy ? 15 : 17 , ret ) ); 
    else if (op == '+' && greedy ) {
#     define XfOrM129_COUNT (0+XfOrM124_COUNT)
#     define SETUP_XfOrM129(x) SETUP_XfOrM124(x)
      next = FUNCCALL(SETUP_XfOrM129(_), regnode (9 ) ); 
      FUNCCALL(SETUP_XfOrM129(_), regtail (ret , next ) ); 
      (__funcarg10 = FUNCCALL(SETUP_XfOrM129(_), regnode (10 ) ), FUNCCALL_AGAIN(regtail (__funcarg10 , ret ) )) ; 
      (__funcarg9 = FUNCCALL(SETUP_XfOrM129(_), regnode (9 ) ), FUNCCALL_AGAIN(regtail (next , __funcarg9 ) )) ; 
      (__funcarg8 = FUNCCALL(SETUP_XfOrM129(_), regnode (13 ) ), FUNCCALL_AGAIN(regtail (ret , __funcarg8 ) )) ; 
    }
    else if (op == '+' ) {
#     define XfOrM128_COUNT (0+XfOrM124_COUNT)
#     define SETUP_XfOrM128(x) SETUP_XfOrM124(x)
      next = FUNCCALL(SETUP_XfOrM128(_), regnode (9 ) ); 
      FUNCCALL(SETUP_XfOrM128(_), regtail (ret , next ) ); 
      FUNCCALL_AGAIN(regnode (13 ) ); 
      (__funcarg7 = FUNCCALL(SETUP_XfOrM128(_), regnode (9 ) ), FUNCCALL_AGAIN(regtail (next , __funcarg7 ) )) ; 
      (__funcarg6 = FUNCCALL(SETUP_XfOrM128(_), regnode (10 ) ), FUNCCALL_AGAIN(regtail (__funcarg6 , ret ) )) ; 
      (__funcarg5 = FUNCCALL(SETUP_XfOrM128(_), regnode (10 ) ), FUNCCALL_AGAIN(regtail (next , __funcarg5 ) )) ; 
      FUNCCALL_AGAIN(regtail (next , next + 3 ) ); 
    }
    else if (op == '?' && greedy ) {
#     define XfOrM127_COUNT (0+XfOrM124_COUNT)
#     define SETUP_XfOrM127(x) SETUP_XfOrM124(x)
      FUNCCALL(SETUP_XfOrM127(_), reginsert (9 , ret ) ); 
      (__funcarg4 = FUNCCALL(SETUP_XfOrM127(_), regnode (9 ) ), FUNCCALL_AGAIN(regtail (ret , __funcarg4 ) )) ; 
      next = FUNCCALL_AGAIN(regnode (13 ) ); 
      FUNCCALL_AGAIN(regtail (ret , next ) ); 
      FUNCCALL_AGAIN(regoptail (ret , next ) ); 
    }
    else if (op == '?' ) {
#     define XfOrM126_COUNT (0+XfOrM124_COUNT)
#     define SETUP_XfOrM126(x) SETUP_XfOrM124(x)
      FUNCCALL(SETUP_XfOrM126(_), reginsert (9 , ret ) ); 
      FUNCCALL(SETUP_XfOrM126(_), reginsert (13 , ret ) ); 
      FUNCCALL_AGAIN(reginsert (9 , ret ) ); 
      FUNCCALL_AGAIN(regtail (ret , ret + 6 ) ); 
      next = FUNCCALL_AGAIN(regnode (10 ) ); 
      FUNCCALL_AGAIN(regtail (ret + 6 , next ) ); 
      FUNCCALL_AGAIN(regoptail (ret + 6 , next ) ); 
      FUNCCALL_AGAIN(regoptail (ret + 6 , ret + 3 ) ); 
    }
    regparse ++ ; 
    if (((regparsestr [regparse ] ) == '*' || (regparsestr [regparse ] ) == '+' || (regparsestr [regparse ] ) == '?' || ((parse_flags & 0x2 ) && ((regparsestr [regparse ] ) == '{' ) ) ) ) {
#     define XfOrM125_COUNT (0+XfOrM124_COUNT)
#     define SETUP_XfOrM125(x) SETUP_XfOrM124(x)
      FUNCCALL(SETUP_XfOrM125(_), regcomperror ("nested `*', `?', `+', or `{...}' in pattern" ) ); 
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    ; 
  }
  if (flags & 0x10 ) {
    rxpos sv ; 
#   define XfOrM122_COUNT (0+XfOrM121_COUNT)
#   define SETUP_XfOrM122(x) SETUP_XfOrM121(x)
    sv = FUNCCALL(SETUP_XfOrM122(_), regnode (35 ) ); 
    FUNCCALL(SETUP_XfOrM122(_), regarg (origsavepos ) ); 
    FUNCCALL_AGAIN(regarg (origmatchmax ) ); 
    FUNCCALL_AGAIN(regtail (ret , sv ) ); 
    if (origmatchmax ) {
#     define XfOrM123_COUNT (0+XfOrM122_COUNT)
#     define SETUP_XfOrM123(x) SETUP_XfOrM122(x)
      sv = FUNCCALL(SETUP_XfOrM123(_), reginsertwithop (36 , ret , origsavepos ) ); 
      FUNCCALL(SETUP_XfOrM123(_), regtail (ret , sv ) ); 
    }
    * flagp &= ~ 0x02 ; 
  }
  RET_VALUE_START ((ret ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static rxpos regatom (int * flagp , int parse_flags , int at_start ) {
  rxpos ret ; 
  int flags ; 
  rxpos __funcarg15 ; 
  DECL_RET_SAVE (rxpos ) PREPARE_VAR_STACK(2);
  BLOCK_SETUP_TOP((PUSH(flagp, 0)));
# define XfOrM175_COUNT (1)
# define SETUP_XfOrM175(x) SETUP(XfOrM175_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  * flagp = (0 | 0x08 ) ; 
  regmatchmin = regmatchmax = 1 ; 
  switch (regparsestr [regparse ++ ] ) {
#   define XfOrM177_COUNT (0+XfOrM175_COUNT)
#   define SETUP_XfOrM177(x) SETUP_XfOrM175(x)
    case '^' : if (parse_flags & 0x4 )
      ret = FUNCCALL(SETUP_XfOrM177(_), regnode (1 ) ); 
    else ret = FUNCCALL(SETUP_XfOrM177(_), regnode (39 ) ); 
    regmatchmin = regmatchmax = 0 ; 
    break ; 
    case '$' : if (parse_flags & 0x4 )
      ret = FUNCCALL(SETUP_XfOrM177(_), regnode (2 ) ); 
    else ret = FUNCCALL(SETUP_XfOrM177(_), regnode (40 ) ); 
    regmatchmin = regmatchmax = 0 ; 
    break ; 
    case '.' : -- regparse ; 
    ret = FUNCCALL(SETUP_XfOrM177(_), regranges (parse_flags , at_start ) ); 
    * flagp |= 0x01 | 0x02 ; 
    break ; 
    case '[' : -- regparse ; 
    ret = FUNCCALL(SETUP_XfOrM177(_), regranges (parse_flags , at_start ) ); 
    * flagp |= 0x01 | 0x02 ; 
    break ; 
    case '(' : {
#     define XfOrM213_COUNT (0+XfOrM177_COUNT)
#     define SETUP_XfOrM213(x) SETUP_XfOrM177(x)
      if (regparsestr [regparse ] == '?' ) {
        int moded = 0 ; 
#       define XfOrM218_COUNT (0+XfOrM213_COUNT)
#       define SETUP_XfOrM218(x) SETUP_XfOrM213(x)
        while (1 ) {
          if (regparsestr [regparse + 1 ] == 'i' ) {
            parse_flags &= ~ 0x1 ; 
            regparse ++ ; 
            moded = 1 ; 
          }
          else if (regparsestr [regparse + 1 ] == 'm' ) {
            parse_flags &= ~ 0x4 ; 
            regparse ++ ; 
            moded = 1 ; 
          }
          else if (regparsestr [regparse + 1 ] == 's' ) {
            parse_flags |= 0x4 ; 
            regparse ++ ; 
            moded = 1 ; 
          }
          else if ((regparsestr [regparse + 1 ] == '-' ) && (regparsestr [regparse + 2 ] == 'i' ) ) {
            parse_flags |= 0x1 ; 
            regparse += 2 ; 
            moded = 1 ; 
          }
          else if ((regparsestr [regparse + 1 ] == '-' ) && (regparsestr [regparse + 2 ] == 'm' ) ) {
            parse_flags |= 0x4 ; 
            regparse += 2 ; 
            moded = 1 ; 
          }
          else if ((regparsestr [regparse + 1 ] == '-' ) && (regparsestr [regparse + 2 ] == 's' ) ) {
            parse_flags &= ~ 0x4 ; 
            regparse += 2 ; 
            moded = 1 ; 
          }
          else {
            break ; 
          }
        }
        if (regparsestr [regparse + 1 ] == ':' ) {
#         define XfOrM253_COUNT (0+XfOrM218_COUNT)
#         define SETUP_XfOrM253(x) SETUP_XfOrM218(x)
          regparse += 2 ; 
          ret = FUNCCALL(SETUP_XfOrM253(_), reg (1 , & flags , 0 , 0 , parse_flags ) ); 
          * flagp = flags ; 
        }
        else if (moded ) {
#         define XfOrM251_COUNT (0+XfOrM218_COUNT)
#         define SETUP_XfOrM251(x) SETUP_XfOrM218(x)
          {
#           define XfOrM252_COUNT (0+XfOrM251_COUNT)
#           define SETUP_XfOrM252(x) SETUP_XfOrM251(x)
            FUNCCALL(SETUP_XfOrM252(_), regcomperror ("expected `:' or another mode after `(?' and a mode sequence (where a mode is `i', `-i', `m', `-m', `s', or `-s')" ) ); 
            RET_VALUE_START (0 ) RET_VALUE_END ; 
          }
          ; 
        }
        else if (regparsestr [regparse + 1 ] == '(' ) {
#         define XfOrM227_COUNT (0+XfOrM218_COUNT)
#         define SETUP_XfOrM227(x) SETUP_XfOrM218(x)
          if (((regparsestr [regparse + 2 ] >= '0' ) && (regparsestr [regparse + 2 ] <= '9' ) ) || ((regparsestr [regparse + 2 ] == '?' ) && ((regparsestr [regparse + 3 ] == '=' ) || (regparsestr [regparse + 3 ] == '!' ) || (regparsestr [regparse + 3 ] == '<' ) ) ) ) {
            rxpos test , tbr , fbr , ender ; 
            int flags , matchmin , matchmax ; 
            Scheme_Hash_Table * backdepends ; 
            regparse ++ ; 
            BLOCK_SETUP((PUSH(backdepends, 0+XfOrM227_COUNT)));
#           define XfOrM229_COUNT (1+XfOrM227_COUNT)
#           define SETUP_XfOrM229(x) SETUP(XfOrM229_COUNT)
            backdepends = NULLED_OUT ; 
            ret = FUNCCALL(SETUP_XfOrM229(_), regnode (42 ) ); 
            FUNCCALL_AGAIN(regarg (0 ) ); 
            FUNCCALL_AGAIN(regarg (0 ) ); 
            if (regparsestr [regparse + 1 ] != '?' ) {
              int posn ; 
              regparse ++ ; 
#             define XfOrM247_COUNT (0+XfOrM229_COUNT)
#             define SETUP_XfOrM247(x) SETUP_XfOrM229(x)
              posn = FUNCCALL(SETUP_XfOrM247(_), regdigit () ); 
              test = FUNCCALL(SETUP_XfOrM247(_), regnode (28 ) ); 
              FUNCCALL_AGAIN(regarg (posn ) ); 
              if (regparsestr [regparse ] == ')' ) {
                regparse ++ ; 
              }
              else {
#               define XfOrM248_COUNT (0+XfOrM247_COUNT)
#               define SETUP_XfOrM248(x) SETUP_XfOrM247(x)
                {
#                 define XfOrM249_COUNT (0+XfOrM248_COUNT)
#                 define SETUP_XfOrM249(x) SETUP_XfOrM248(x)
                  FUNCCALL(SETUP_XfOrM249(_), regcomperror ("expected `)' after `(?(' followed by a digit" ) ); 
                  RET_VALUE_START (0 ) RET_VALUE_END ; 
                }
                ; 
              }
            }
            else {
#             define XfOrM246_COUNT (0+XfOrM229_COUNT)
#             define SETUP_XfOrM246(x) SETUP_XfOrM229(x)
              test = FUNCCALL(SETUP_XfOrM246(_), regatom (& flags , parse_flags , 1 ) ); 
            }
            if (test != ((ret ) + 7 ) ) {
#             define XfOrM244_COUNT (0+XfOrM229_COUNT)
#             define SETUP_XfOrM244(x) SETUP_XfOrM229(x)
              {
#               define XfOrM245_COUNT (0+XfOrM244_COUNT)
#               define SETUP_XfOrM245(x) SETUP_XfOrM244(x)
                FUNCCALL(SETUP_XfOrM245(_), regcomperror ("test went to wrong place!?" ) ); 
                RET_VALUE_START (0 ) RET_VALUE_END ; 
              }
              ; 
            }
            (__funcarg15 = FUNCCALL(SETUP_XfOrM229(_), regnode (0 ) ), FUNCCALL_AGAIN(regtail (test , __funcarg15 ) )) ; 
            if (regparsestr [regparse ] == ')' ) {
#             define XfOrM242_COUNT (0+XfOrM229_COUNT)
#             define SETUP_XfOrM242(x) SETUP_XfOrM229(x)
              {
#               define XfOrM243_COUNT (0+XfOrM242_COUNT)
#               define SETUP_XfOrM243(x) SETUP_XfOrM242(x)
                FUNCCALL(SETUP_XfOrM243(_), regcomperror ("expected an expression after test in `(?(...))'" ) ); 
                RET_VALUE_START (0 ) RET_VALUE_END ; 
              }
              ; 
            }
            regbackdepends = ((void * ) 0 ) ; 
            * flagp |= 0x01 ; 
            tbr = FUNCCALL(SETUP_XfOrM229(_), regbranch (& flags , parse_flags , 1 ) ); 
            if (! (flags & 0x01 ) ) {
              * flagp &= ~ 0x01 ; 
              backdepends = ((void * ) 0 ) ; 
            }
            else if (regbackdepends ) {
              backdepends = regbackdepends ; 
              regbackdepends = ((void * ) 0 ) ; 
            }
            else backdepends = ((void * ) 0 ) ; 
            if (! (flags & 0x08 ) )
              * flagp &= ~ 0x08 ; 
            matchmin = regmatchmin ; 
            matchmax = regmatchmax ; 
            if (regparsestr [regparse ] == ')' ) {
#             define XfOrM239_COUNT (0+XfOrM229_COUNT)
#             define SETUP_XfOrM239(x) SETUP_XfOrM229(x)
              fbr = FUNCCALL(SETUP_XfOrM239(_), regnode (13 ) ); 
              * flagp &= ~ 0x01 ; 
              matchmin = 0 ; 
            }
            else if (regparsestr [regparse ] != '|' ) {
#             define XfOrM237_COUNT (0+XfOrM229_COUNT)
#             define SETUP_XfOrM237(x) SETUP_XfOrM229(x)
              {
#               define XfOrM238_COUNT (0+XfOrM237_COUNT)
#               define SETUP_XfOrM238(x) SETUP_XfOrM237(x)
                FUNCCALL(SETUP_XfOrM238(_), regcomperror ("expected `)' or `|' after first branch of `(?(...)...)'" ) ); 
                RET_VALUE_START (0 ) RET_VALUE_END ; 
              }
              ; 
            }
            else {
              regparse ++ ; 
#             define XfOrM231_COUNT (0+XfOrM229_COUNT)
#             define SETUP_XfOrM231(x) SETUP_XfOrM229(x)
              fbr = FUNCCALL(SETUP_XfOrM231(_), regbranch (& flags , parse_flags , 1 ) ); 
              if (regparsestr [regparse ] != ')' ) {
#               define XfOrM235_COUNT (0+XfOrM231_COUNT)
#               define SETUP_XfOrM235(x) SETUP_XfOrM231(x)
                {
#                 define XfOrM236_COUNT (0+XfOrM235_COUNT)
#                 define SETUP_XfOrM236(x) SETUP_XfOrM235(x)
                  FUNCCALL(SETUP_XfOrM236(_), regcomperror ("expected `)' to close `(?(...)...' after second branch" ) ); 
                  RET_VALUE_START (0 ) RET_VALUE_END ; 
                }
                ; 
              }
              if (! (flags & 0x01 ) ) {
                * flagp &= ~ 0x01 ; 
                backdepends = ((void * ) 0 ) ; 
              }
              else if (regbackdepends ) {
#               define XfOrM233_COUNT (0+XfOrM231_COUNT)
#               define SETUP_XfOrM233(x) SETUP_XfOrM231(x)
                if (backdepends )
                  FUNCCALL(SETUP_XfOrM233(_), merge_tables (backdepends , regbackdepends ) ); 
                else backdepends = regbackdepends ; 
              }
              if (! (flags & 0x08 ) )
                * flagp &= ~ 0x08 ; 
              else {
                if (regmatchmin < matchmin )
                  matchmin = regmatchmin ; 
                if (regmatchmax > matchmax )
                  matchmax = regmatchmax ; 
              }
            }
            regmatchmax = matchmax ; 
            regmatchmin = matchmin ; 
            regbackdepends = backdepends ; 
            if (((ret ) + 5 ) + 1 < regcodesize ) {
              int delta ; 
              delta = tbr - ret ; 
              regstr [((ret ) + 3 ) ] = delta >> 8 ; 
              regstr [((ret ) + 3 ) + 1 ] = delta & 255 ; 
              delta = fbr - ret ; 
              regstr [((ret ) + 5 ) ] = delta >> 8 ; 
              regstr [((ret ) + 5 ) + 1 ] = delta & 255 ; 
            }
            ender = FUNCCALL(SETUP_XfOrM229(_), regnode (13 ) ); 
            FUNCCALL(SETUP_XfOrM229(_), regtail (tbr , ender ) ); 
            FUNCCALL_AGAIN(regtail (fbr , ender ) ); 
            FUNCCALL_AGAIN(regtail (ret , ender ) ); 
            regparse ++ ; 
          }
          else {
#           define XfOrM228_COUNT (0+XfOrM227_COUNT)
#           define SETUP_XfOrM228(x) SETUP_XfOrM227(x)
            FUNCCALL(SETUP_XfOrM228(_), regcomperror ("expected `(?=', `(?!', `(?<', or digit after `(?('" ) ); 
            RET_VALUE_START (0 ) RET_VALUE_END ; 
          }
          ; 
        }
        else if (regparsestr [regparse + 1 ] == '>' ) {
#         define XfOrM226_COUNT (0+XfOrM218_COUNT)
#         define SETUP_XfOrM226(x) SETUP_XfOrM218(x)
          regparse += 2 ; 
          ret = FUNCCALL(SETUP_XfOrM226(_), reg (1 , & flags , 0 , 24 , parse_flags ) ); 
          * flagp = flags ; 
        }
        else {
#         define XfOrM219_COUNT (0+XfOrM218_COUNT)
#         define SETUP_XfOrM219(x) SETUP_XfOrM218(x)
          if (regparsestr [regparse + 1 ] == '=' ) {
#           define XfOrM225_COUNT (0+XfOrM219_COUNT)
#           define SETUP_XfOrM225(x) SETUP_XfOrM219(x)
            regparse += 2 ; 
            ret = FUNCCALL(SETUP_XfOrM225(_), reg (1 , & flags , 0 , 22 , parse_flags ) ); 
          }
          else if (regparsestr [regparse + 1 ] == '!' ) {
#           define XfOrM224_COUNT (0+XfOrM219_COUNT)
#           define SETUP_XfOrM224(x) SETUP_XfOrM219(x)
            regparse += 2 ; 
            ret = FUNCCALL(SETUP_XfOrM224(_), reg (1 , & flags , 0 , 23 , parse_flags ) ); 
          }
          else if ((regparsestr [regparse + 1 ] == '<' ) && (regparsestr [regparse + 2 ] == '=' ) ) {
#           define XfOrM223_COUNT (0+XfOrM219_COUNT)
#           define SETUP_XfOrM223(x) SETUP_XfOrM219(x)
            regparse += 3 ; 
            ret = FUNCCALL(SETUP_XfOrM223(_), reg (1 , & flags , 0 , 25 , parse_flags ) ); 
          }
          else if ((regparsestr [regparse + 1 ] == '<' ) && (regparsestr [regparse + 2 ] == '!' ) ) {
#           define XfOrM222_COUNT (0+XfOrM219_COUNT)
#           define SETUP_XfOrM222(x) SETUP_XfOrM219(x)
            regparse += 3 ; 
            ret = FUNCCALL(SETUP_XfOrM222(_), reg (1 , & flags , 0 , 26 , parse_flags ) ); 
          }
          else {
#           define XfOrM220_COUNT (0+XfOrM219_COUNT)
#           define SETUP_XfOrM220(x) SETUP_XfOrM219(x)
            {
#             define XfOrM221_COUNT (0+XfOrM220_COUNT)
#             define SETUP_XfOrM221(x) SETUP_XfOrM220(x)
              FUNCCALL(SETUP_XfOrM221(_), regcomperror ("expected `:', `=', `!', `<=', `<!', `i', `-i', `m', `-m', `s', or `-s' after `(?'" ) ); 
              RET_VALUE_START (0 ) RET_VALUE_END ; 
            }
            ; 
          }
          regmatchmin = regmatchmax = 0 ; 
          * flagp = 0x08 ; 
          regbackdepends = ((void * ) 0 ) ; 
        }
      }
      else {
#       define XfOrM215_COUNT (0+XfOrM213_COUNT)
#       define SETUP_XfOrM215(x) SETUP_XfOrM213(x)
        ret = FUNCCALL(SETUP_XfOrM215(_), reg (1 , & flags , 1 , 0 , parse_flags ) ); 
        if (flags & 0x10 ) {
          * flagp = flags ; 
        }
        else {
          * flagp |= flags & (0x01 | 0x04 ) ; 
          if (! (flags & 0x08 ) )
            * flagp &= ~ 0x08 ; 
        }
      }
      if (ret == 0 ) {
#       define XfOrM214_COUNT (0+XfOrM213_COUNT)
#       define SETUP_XfOrM214(x) SETUP_XfOrM213(x)
        FUNCCALL(SETUP_XfOrM214(_), regcomperror ("cluster failed!?" ) ); 
        RET_VALUE_START (0 ) RET_VALUE_END ; 
      }
      ; 
    }
    break ; 
    case '|' : case ')' : {
#     define XfOrM212_COUNT (0+XfOrM177_COUNT)
#     define SETUP_XfOrM212(x) SETUP_XfOrM177(x)
      FUNCCALL(SETUP_XfOrM212(_), regcomperror ("internal urp" ) ); 
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    ; 
    break ; 
    case '?' : {
#     define XfOrM211_COUNT (0+XfOrM177_COUNT)
#     define SETUP_XfOrM211(x) SETUP_XfOrM177(x)
      FUNCCALL(SETUP_XfOrM211(_), regcomperror ("`?' follows nothing in pattern" ) ); 
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    ; 
    break ; 
    case '+' : {
#     define XfOrM210_COUNT (0+XfOrM177_COUNT)
#     define SETUP_XfOrM210(x) SETUP_XfOrM177(x)
      FUNCCALL(SETUP_XfOrM210(_), regcomperror ("`+' follows nothing in pattern" ) ); 
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    ; 
    break ; 
    case '*' : {
#     define XfOrM209_COUNT (0+XfOrM177_COUNT)
#     define SETUP_XfOrM209(x) SETUP_XfOrM177(x)
      FUNCCALL(SETUP_XfOrM209(_), regcomperror ("`*' follows nothing in pattern" ) ); 
      RET_VALUE_START (0 ) RET_VALUE_END ; 
    }
    ; 
    break ; 
    case '\\' : {
      int c ; 
#     define XfOrM198_COUNT (0+XfOrM177_COUNT)
#     define SETUP_XfOrM198(x) SETUP_XfOrM177(x)
      if (regparse == regparse_end ) {
#       define XfOrM208_COUNT (0+XfOrM198_COUNT)
#       define SETUP_XfOrM208(x) SETUP_XfOrM198(x)
        FUNCCALL(SETUP_XfOrM208(_), regcomperror ("trailing backslash in pattern" ) ); 
        RET_VALUE_START (0 ) RET_VALUE_END ; 
      }
      ; 
      c = regparsestr [regparse ++ ] ; 
      if ((parse_flags & 0x2 ) && (c == 'b' ) ) {
#       define XfOrM207_COUNT (0+XfOrM198_COUNT)
#       define SETUP_XfOrM207(x) SETUP_XfOrM198(x)
        ret = FUNCCALL(SETUP_XfOrM207(_), regnode (37 ) ); 
        regmatchmin = regmatchmax = 0 ; 
        if (! regmaxlookback )
          regmaxlookback = 1 ; 
      }
      else if ((parse_flags & 0x2 ) && (c == 'B' ) ) {
#       define XfOrM206_COUNT (0+XfOrM198_COUNT)
#       define SETUP_XfOrM206(x) SETUP_XfOrM198(x)
        ret = FUNCCALL(SETUP_XfOrM206(_), regnode (38 ) ); 
        regmatchmin = regmatchmax = 0 ; 
        if (! regmaxlookback )
          regmaxlookback = 1 ; 
      }
      else if ((parse_flags & 0x2 ) && (c == 'p' ) ) {
#       define XfOrM205_COUNT (0+XfOrM198_COUNT)
#       define SETUP_XfOrM205(x) SETUP_XfOrM198(x)
        ret = FUNCCALL(SETUP_XfOrM205(_), regunicode (0 ) ); 
        regmatchmax = 6 ; 
        * flagp |= 0x01 ; 
      }
      else if ((parse_flags & 0x2 ) && (c == 'P' ) ) {
#       define XfOrM204_COUNT (0+XfOrM198_COUNT)
#       define SETUP_XfOrM204(x) SETUP_XfOrM198(x)
        ret = FUNCCALL(SETUP_XfOrM204(_), regunicode (1 ) ); 
        regmatchmax = 6 ; 
        * flagp |= 0x01 ; 
      }
      else if ((parse_flags & 0x2 ) && (c >= '0' ) && (c <= '9' ) ) {
        int posn ; 
#       define XfOrM200_COUNT (0+XfOrM198_COUNT)
#       define SETUP_XfOrM200(x) SETUP_XfOrM198(x)
        -- regparse ; 
        posn = FUNCCALL(SETUP_XfOrM200(_), regdigit () ); 
        if (parse_flags & 0x1 )
          ret = FUNCCALL(SETUP_XfOrM200(_), regnode (28 ) ); 
        else ret = FUNCCALL(SETUP_XfOrM200(_), regnode (29 ) ); 
        FUNCCALL(SETUP_XfOrM200(_), regarg (posn ) ); 
        * flagp &= ~ 0x08 ; 
        {
          Scheme_Object * f ; 
          BLOCK_SETUP((PUSH(f, 0+XfOrM200_COUNT)));
#         define XfOrM201_COUNT (1+XfOrM200_COUNT)
#         define SETUP_XfOrM201(x) SETUP(XfOrM201_COUNT)
          f = NULLED_OUT ; 
          if (regbackknown )
            f = FUNCCALL(SETUP_XfOrM201(_), scheme_hash_get (regbackknown , ((Scheme_Object * ) (void * ) (long ) ((((long ) (posn ) ) << 1 ) | 0x1 ) ) ) ); 
          else f = ((void * ) 0 ) ; 
          if (f ) {
            if ((! (((f ) ) == (scheme_false ) ) ) )
              * flagp |= 0x01 ; 
          }
          else {
#           define XfOrM202_COUNT (0+XfOrM201_COUNT)
#           define SETUP_XfOrM202(x) SETUP_XfOrM201(x)
            * flagp |= 0x01 ; 
            if (! regbackdepends )
              regbackdepends = FUNCCALL(SETUP_XfOrM202(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
            FUNCCALL(SETUP_XfOrM202(_), scheme_hash_set (regbackdepends , ((Scheme_Object * ) (void * ) (long ) ((((long ) (posn ) ) << 1 ) | 0x1 ) ) , scheme_true ) ); 
          }
        }
      }
      else {
#       define XfOrM199_COUNT (0+XfOrM198_COUNT)
#       define SETUP_XfOrM199(x) SETUP_XfOrM198(x)
        regparse -= 2 ; 
        ret = FUNCCALL(SETUP_XfOrM199(_), regranges (parse_flags , at_start ) ); 
        * flagp |= 0x01 | 0x02 ; 
      }
    }
    break ; 
    default : {
      int len , ilen , c ; 
      char ender ; 
      regparse -- ; 
#     define XfOrM178_COUNT (0+XfOrM177_COUNT)
#     define SETUP_XfOrM178(x) SETUP_XfOrM177(x)
      if (parse_flags & 0x2 ) {
#       define XfOrM194_COUNT (0+XfOrM178_COUNT)
#       define SETUP_XfOrM194(x) SETUP_XfOrM178(x)
        if (regparsestr [regparse ] == '{' ) {
#         define XfOrM197_COUNT (0+XfOrM194_COUNT)
#         define SETUP_XfOrM197(x) SETUP_XfOrM194(x)
          FUNCCALL(SETUP_XfOrM197(_), regcomperror ("`{' follows nothing in pattern" ) ); 
          RET_VALUE_START (0 ) RET_VALUE_END ; 
        }
        ; 
        if (regparsestr [regparse ] == '}' ) {
#         define XfOrM196_COUNT (0+XfOrM194_COUNT)
#         define SETUP_XfOrM196(x) SETUP_XfOrM194(x)
          FUNCCALL(SETUP_XfOrM196(_), regcomperror ("unmatched `}' in pattern" ) ); 
          RET_VALUE_START (0 ) RET_VALUE_END ; 
        }
        ; 
        if (regparsestr [regparse ] == ']' ) {
#         define XfOrM195_COUNT (0+XfOrM194_COUNT)
#         define SETUP_XfOrM195(x) SETUP_XfOrM194(x)
          FUNCCALL(SETUP_XfOrM195(_), regcomperror ("unmatched `]' in pattern" ) ); 
          RET_VALUE_START (0 ) RET_VALUE_END ; 
        }
        ; 
      }
      for (len = ilen = 0 ; regparse + ilen < regparse_end ; len ++ , ilen ++ ) {
#       define XfOrM192_COUNT (0+XfOrM178_COUNT)
#       define SETUP_XfOrM192(x) SETUP_XfOrM178(x)
        if (regparsestr [regparse + ilen ] == '\\' ) {
          if (regparse + ilen + 1 >= regparse_end )
            break ; 
          c = regparsestr [regparse + ilen + 1 ] ; 
          if (((c >= 'a' ) && (c <= 'z' ) ) || ((c >= 'A' ) && (c <= 'Z' ) ) || ((c >= '0' ) && (c <= '9' ) ) )
            break ; 
          ilen ++ ; 
        }
        else if (FUNCCALL(SETUP_XfOrM192(_), regstrcspn (regparsestr + regparse + ilen , regparsestr + regparse + ilen + 1 , (parse_flags & 0x2 ) ? "^$.[()|?+*\\{}]" : "^$.[()|?+*\\" ) )< 1 )
          break ; 
      }
      if (len <= 0 ) {
#       define XfOrM189_COUNT (0+XfOrM178_COUNT)
#       define SETUP_XfOrM189(x) SETUP_XfOrM178(x)
        FUNCCALL(SETUP_XfOrM189(_), regcomperror ("internal disaster" ) ); 
        RET_VALUE_START (0 ) RET_VALUE_END ; 
      }
      ; 
      if ((len == 1 ) && at_start ) {
#       define XfOrM188_COUNT (0+XfOrM178_COUNT)
#       define SETUP_XfOrM188(x) SETUP_XfOrM178(x)
        ret = FUNCCALL(SETUP_XfOrM188(_), regranges (parse_flags , at_start ) ); 
        * flagp |= 0x01 | 0x02 ; 
      }
      else {
#       define XfOrM179_COUNT (0+XfOrM178_COUNT)
#       define SETUP_XfOrM179(x) SETUP_XfOrM178(x)
        if (! (parse_flags & 0x1 ) ) {
          int i ; 
          for (i = 0 ; i < ilen ; i ++ ) {
            c = regparsestr [regparse + i ] ; 
            if (((((c >= 'a' ) && (c <= 'z' ) ) ? (c - ('a' - 'A' ) ) : c ) != c ) || ((((c >= 'A' ) && (c <= 'Z' ) ) ? (c + ('a' - 'A' ) ) : c ) != c ) ) {
              break ; 
            }
          }
          if (i >= ilen )
            parse_flags |= 0x1 ; 
        }
        ender = regparsestr [regparse + ilen ] ; 
        if (len > 1 && ((ender ) == '*' || (ender ) == '+' || (ender ) == '?' || ((parse_flags & 0x2 ) && ((ender ) == '{' ) ) ) ) {
          len -- ; 
          ilen -- ; 
          if (regparsestr [regparse + ilen ] == '\\' )
            -- ilen ; 
        }
        * flagp |= 0x01 ; 
        if (len == 1 )
          * flagp |= 0x02 ; 
        regmatchmin = regmatchmax = len ; 
        ret = FUNCCALL_EMPTY(regnode ((parse_flags & 0x1 ) ? 11 : 12 ) ); 
        FUNCCALL_EMPTY(regarg (len ) ); 
        while (len > 0 ) {
#         define XfOrM181_COUNT (0+XfOrM179_COUNT)
#         define SETUP_XfOrM181(x) SETUP_XfOrM179(x)
          c = regparsestr [regparse ++ ] ; 
          if (c == '\\' )
            c = regparsestr [regparse ++ ] ; 
          if (! (parse_flags & 0x1 ) )
            c = (((c >= 'A' ) && (c <= 'Z' ) ) ? (c + ('a' - 'A' ) ) : c ) ; 
          FUNCCALL_EMPTY(regc (c ) ); 
          len -- ; 
        }
      }
    }
    break ; 
  }
  if (! ret ) {
#   define XfOrM176_COUNT (0+XfOrM175_COUNT)
#   define SETUP_XfOrM176(x) SETUP_XfOrM175(x)
    FUNCCALL_EMPTY(regcomperror ("failed!?" ) ); 
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  ; 
  RET_VALUE_START (ret ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int regcharclass (int c , char * map ) {
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(map, 0)));
# define XfOrM270_COUNT (1)
# define SETUP_XfOrM270(x) SETUP(XfOrM270_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  switch (c ) {
#   define XfOrM271_COUNT (0+XfOrM270_COUNT)
#   define SETUP_XfOrM271(x) SETUP_XfOrM270(x)
    case 'd' : for (c = 0 ; c < 10 ; c ++ ) {
      map ['0' + c ] = 1 ; 
    }
    break ; 
    case 'D' : for (c = 0 ; c < '0' ; c ++ ) {
      map [c ] = 1 ; 
    }
    for (c = '9' + 1 ; c < 256 ; c ++ ) {
      map [c ] = 1 ; 
    }
    break ; 
    case 'w' : for (c = 0 ; c < 26 ; c ++ ) {
      map ['a' + c ] = 1 ; 
      map ['A' + c ] = 1 ; 
    }
    for (c = 0 ; c < 10 ; c ++ ) {
      map ['0' + c ] = 1 ; 
    }
    map ['_' ] = 1 ; 
    break ; 
    case 'W' : for (c = 0 ; c < '0' ; c ++ ) {
      map [c ] = 1 ; 
    }
    for (c = '9' + 1 ; c < 'A' ; c ++ ) {
      map [c ] = 1 ; 
    }
    for (c = 'Z' + 1 ; c < '_' ; c ++ ) {
      map [c ] = 1 ; 
    }
    for (c = 'z' + 1 ; c < 256 ; c ++ ) {
      map [c ] = 1 ; 
    }
    break ; 
    case 's' : map ['\t' ] = 1 ; 
    map ['\n' ] = 1 ; 
    map ['\f' ] = 1 ; 
    map ['\r' ] = 1 ; 
    map [' ' ] = 1 ; 
    break ; 
    case 'S' : for (c = 0 ; c < 256 ; c ++ ) {
      switch (c ) {
        case '\t' : case '\n' : case '\f' : case '\r' : case ' ' : break ; 
        default : map [c ] = 1 ; 
        break ; 
      }
    }
    break ; 
    default : if (((c >= 'a' ) && (c <= 'z' ) ) || ((c >= 'A' ) && (c <= 'Z' ) ) ) {
#     define XfOrM272_COUNT (0+XfOrM271_COUNT)
#     define SETUP_XfOrM272(x) SETUP_XfOrM271(x)
      {
#       define XfOrM273_COUNT (0+XfOrM272_COUNT)
#       define SETUP_XfOrM273(x) SETUP_XfOrM272(x)
        FUNCCALL(SETUP_XfOrM273(_), regcomperror ("illegal alphabetic escape" ) ); 
        RET_VALUE_START (0 ) RET_VALUE_END ; 
      }
      ; 
    }
    map [c ] = 1 ; 
    break ; 
  }
  RET_VALUE_START (1 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int is_posix_char_class (char * str , int pos , int len , char * map ) {
  int c ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(map, 0), PUSH(str, 1)));
# define XfOrM296_COUNT (2)
# define SETUP_XfOrM296(x) SETUP(XfOrM296_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (pos + 8 <= len ) {
#   define XfOrM303_COUNT (0+XfOrM296_COUNT)
#   define SETUP_XfOrM303(x) SETUP_XfOrM296(x)
    if (! (scheme_strncmp (":alnum:]" , str XFORM_OK_PLUS pos , 8 ) ) ) {
#     define XfOrM338_COUNT (0+XfOrM303_COUNT)
#     define SETUP_XfOrM338(x) SETUP_XfOrM303(x)
      if (map ) {
#       define XfOrM339_COUNT (0+XfOrM338_COUNT)
#       define SETUP_XfOrM339(x) SETUP_XfOrM338(x)
        FUNCCALL(SETUP_XfOrM339(_), regcharclass ('d' , map ) ); 
        for (c = 'a' ; c <= 'z' ; c ++ ) {
          map [c ] = 1 ; 
          map [c - ('a' - 'A' ) ] = 1 ; 
        }
      }
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
    else if (! (scheme_strncmp (":alpha:]" , str XFORM_OK_PLUS pos , 8 ) ) ) {
      if (map ) {
        for (c = 'a' ; c <= 'z' ; c ++ ) {
          map [c ] = 1 ; 
          map [c - ('a' - 'A' ) ] = 1 ; 
        }
      }
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
    else if (! (scheme_strncmp (":ascii:]" , str XFORM_OK_PLUS pos , 8 ) ) ) {
      if (map ) {
        for (c = 0 ; c <= 127 ; c ++ ) {
          map [c ] = 1 ; 
        }
      }
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
    else if (! (scheme_strncmp (":blank:]" , str XFORM_OK_PLUS pos , 8 ) ) ) {
      if (map ) {
        map [' ' ] = 1 ; 
        map ['\t' ] = 1 ; 
      }
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
    else if (! (scheme_strncmp (":cntrl:]" , str XFORM_OK_PLUS pos , 8 ) ) ) {
      if (map ) {
        for (c = 0 ; c <= 31 ; c ++ ) {
          map [c ] = 1 ; 
        }
      }
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
    else if (! (scheme_strncmp (":digit:]" , str XFORM_OK_PLUS pos , 8 ) ) ) {
#     define XfOrM322_COUNT (0+XfOrM303_COUNT)
#     define SETUP_XfOrM322(x) SETUP_XfOrM303(x)
      if (map ) {
#       define XfOrM323_COUNT (0+XfOrM322_COUNT)
#       define SETUP_XfOrM323(x) SETUP_XfOrM322(x)
        FUNCCALL(SETUP_XfOrM323(_), regcharclass ('d' , map ) ); 
      }
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
    else if (! (scheme_strncmp (":graph:]" , str XFORM_OK_PLUS pos , 8 ) ) ) {
      if (map ) {
        for (c = 0 ; c <= 127 ; c ++ ) {
          if ((((scheme_uchar_table [(c >> 8 ) & 0x1FFF ] [c & 0xFF ] ) ) & 0x800 ) )
            map [c ] = 1 ; 
        }
      }
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
    else if (! (scheme_strncmp (":lower:]" , str XFORM_OK_PLUS pos , 8 ) ) ) {
      if (map ) {
        for (c = 'a' ; c <= 'z' ; c ++ ) {
          map [c ] = 1 ; 
        }
      }
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
    else if (! (scheme_strncmp (":print:]" , str XFORM_OK_PLUS pos , 8 ) ) ) {
      if (map ) {
        for (c = 0 ; c <= 127 ; c ++ ) {
          if ((((scheme_uchar_table [(c >> 8 ) & 0x1FFF ] [c & 0xFF ] ) ) & 0x800 ) )
            map [c ] = 1 ; 
        }
        map [' ' ] = 1 ; 
        map ['\t' ] = 1 ; 
      }
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
    else if (! (scheme_strncmp (":space:]" , str XFORM_OK_PLUS pos , 8 ) ) ) {
#     define XfOrM308_COUNT (0+XfOrM303_COUNT)
#     define SETUP_XfOrM308(x) SETUP_XfOrM303(x)
      if (map ) {
#       define XfOrM309_COUNT (0+XfOrM308_COUNT)
#       define SETUP_XfOrM309(x) SETUP_XfOrM308(x)
        FUNCCALL(SETUP_XfOrM309(_), regcharclass ('s' , map ) ); 
      }
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
    else if (! (scheme_strncmp (":upper:]" , str XFORM_OK_PLUS pos , 8 ) ) ) {
      if (map ) {
        for (c = 'A' ; c <= 'Z' ; c ++ ) {
          map [c ] = 1 ; 
        }
      }
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
  }
  if ((pos + 7 <= len ) && ! (scheme_strncmp (":word:]" , str XFORM_OK_PLUS pos , 7 ) ) ) {
#   define XfOrM301_COUNT (0+XfOrM296_COUNT)
#   define SETUP_XfOrM301(x) SETUP_XfOrM296(x)
    if (map ) {
#     define XfOrM302_COUNT (0+XfOrM301_COUNT)
#     define SETUP_XfOrM302(x) SETUP_XfOrM301(x)
      FUNCCALL(SETUP_XfOrM302(_), regcharclass ('w' , map ) ); 
    }
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  }
  if ((pos + 9 <= len ) && ! (scheme_strncmp (":xdigit:]" , str XFORM_OK_PLUS pos , 9 ) ) ) {
#   define XfOrM297_COUNT (0+XfOrM296_COUNT)
#   define SETUP_XfOrM297(x) SETUP_XfOrM296(x)
    if (map ) {
#     define XfOrM298_COUNT (0+XfOrM297_COUNT)
#     define SETUP_XfOrM298(x) SETUP_XfOrM297(x)
      FUNCCALL(SETUP_XfOrM298(_), regcharclass ('d' , map ) ); 
      for (c = 'a' ; c <= 'f' ; c ++ ) {
        map [c ] = 1 ; 
        map [c - ('a' - 'A' ) ] = 1 ; 
      }
    }
    RET_VALUE_START (1 ) RET_VALUE_END ; 
  }
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int is_posix_char_class_in_unicode (mzchar * str , int pos , int len , char * map ) {
  /* No conversion */
  int ulen ; 
  int i ; 
  char buf [10 ] ; 
  if (pos + 7 > len )
    return 0 ; 
  ulen = len - pos ; 
  if (ulen > 9 )
    ulen = 9 ; 
  for (i = 0 ; i < ulen ; i ++ ) {
    if (str [pos + i ] > 127 )
      return 0 ; 
    buf [i ] = (char ) str [pos + i ] ; 
  }
  return is_posix_char_class (buf , 0 , ulen , map ) ; 
}
static char * regrange (int parse_flags , char * map ) {
  int xclass , c ; 
  int classend , can_range = 0 ; 
  int exclude = 0 ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(map, 0)));
# define XfOrM345_COUNT (1)
# define SETUP_XfOrM345(x) SETUP(XfOrM345_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (regparsestr [regparse ] == '^' ) {
    exclude = 1 ; 
    regparse ++ ; 
  }
  if (regparsestr [regparse ] == ']' || regparsestr [regparse ] == '-' ) {
    c = regparsestr [regparse ] ; 
    map [c ] = 1 ; 
    regparse ++ ; 
  }
  while (regparse != regparse_end && regparsestr [regparse ] != ']' ) {
#   define XfOrM377_COUNT (0+XfOrM345_COUNT)
#   define SETUP_XfOrM377(x) SETUP_XfOrM345(x)
    if (regparsestr [regparse ] == '-' ) {
      regparse ++ ; 
#     define XfOrM386_COUNT (0+XfOrM377_COUNT)
#     define SETUP_XfOrM386(x) SETUP_XfOrM377(x)
      if (regparsestr [regparse ] == ']' || regparse == regparse_end ) {
        map ['-' ] = 1 ; 
      }
      else {
#       define XfOrM387_COUNT (0+XfOrM386_COUNT)
#       define SETUP_XfOrM387(x) SETUP_XfOrM386(x)
        if (! can_range ) {
#         define XfOrM401_COUNT (0+XfOrM387_COUNT)
#         define SETUP_XfOrM401(x) SETUP_XfOrM387(x)
          {
#           define XfOrM402_COUNT (0+XfOrM401_COUNT)
#           define SETUP_XfOrM402(x) SETUP_XfOrM401(x)
            FUNCCALL(SETUP_XfOrM402(_), regcomperror ("misplaced hypen within square brackets in pattern" ) ); 
            RET_VALUE_START (0 ) RET_VALUE_END ; 
          }
          ; 
        }
        else {
#         define XfOrM388_COUNT (0+XfOrM387_COUNT)
#         define SETUP_XfOrM388(x) SETUP_XfOrM387(x)
          xclass = ((unsigned char ) (regparsestr [regparse - 2 ] ) ) + 1 ; 
          classend = ((unsigned char ) (regparsestr [regparse ] ) ) ; 
          if (classend == '-' ) {
#           define XfOrM399_COUNT (0+XfOrM388_COUNT)
#           define SETUP_XfOrM399(x) SETUP_XfOrM388(x)
            {
#             define XfOrM400_COUNT (0+XfOrM399_COUNT)
#             define SETUP_XfOrM400(x) SETUP_XfOrM399(x)
              FUNCCALL(SETUP_XfOrM400(_), regcomperror ("misplaced hypen within square brackets in pattern" ) ); 
              RET_VALUE_START (0 ) RET_VALUE_END ; 
            }
            ; 
          }
          if ((classend == '\\' ) && (parse_flags & 0x2 ) ) {
#           define XfOrM394_COUNT (0+XfOrM388_COUNT)
#           define SETUP_XfOrM394(x) SETUP_XfOrM388(x)
            if (regparse + 1 == regparse_end ) {
#             define XfOrM397_COUNT (0+XfOrM394_COUNT)
#             define SETUP_XfOrM397(x) SETUP_XfOrM394(x)
              {
#               define XfOrM398_COUNT (0+XfOrM397_COUNT)
#               define SETUP_XfOrM398(x) SETUP_XfOrM397(x)
                FUNCCALL(SETUP_XfOrM398(_), regcomperror ("escaping backslash at end pattern (within square brackets)" ) ); 
                RET_VALUE_START (0 ) RET_VALUE_END ; 
              }
              ; 
            }
            regparse ++ ; 
            classend = ((unsigned char ) (regparsestr [regparse ] ) ) ; 
            if (((classend >= 'a' ) && (classend <= 'z' ) ) || ((classend >= 'A' ) && (classend <= 'Z' ) ) ) {
#             define XfOrM395_COUNT (0+XfOrM394_COUNT)
#             define SETUP_XfOrM395(x) SETUP_XfOrM394(x)
              {
#               define XfOrM396_COUNT (0+XfOrM395_COUNT)
#               define SETUP_XfOrM396(x) SETUP_XfOrM395(x)
                FUNCCALL(SETUP_XfOrM396(_), regcomperror ("misplaced hypen within square brackets in pattern" ) ); 
                RET_VALUE_START (0 ) RET_VALUE_END ; 
              }
              ; 
            }
          }
          if (xclass > classend + 1 ) {
#           define XfOrM393_COUNT (0+XfOrM388_COUNT)
#           define SETUP_XfOrM393(x) SETUP_XfOrM388(x)
            FUNCCALL(SETUP_XfOrM393(_), regcomperror ("invalid range within square brackets in pattern" ) ); 
            RET_VALUE_START (0 ) RET_VALUE_END ; 
          }
          ; 
          for (; xclass <= classend ; xclass ++ ) {
            c = xclass ; 
            map [c ] = 1 ; 
            if (! (parse_flags & 0x1 ) ) {
              c = (((c >= 'a' ) && (c <= 'z' ) ) ? (c - ('a' - 'A' ) ) : c ) ; 
              map [c ] = 1 ; 
              c = (((c >= 'A' ) && (c <= 'Z' ) ) ? (c + ('a' - 'A' ) ) : c ) ; 
              map [c ] = 1 ; 
            }
          }
          regparse ++ ; 
        }
      }
      can_range = 0 ; 
    }
    else if ((regparsestr [regparse ] == '\\' ) && (parse_flags & 0x2 ) ) {
#     define XfOrM383_COUNT (0+XfOrM377_COUNT)
#     define SETUP_XfOrM383(x) SETUP_XfOrM377(x)
      c = ((unsigned char ) (regparsestr [regparse + 1 ] ) ) ; 
      if (((c >= 'a' ) && (c <= 'z' ) ) || ((c >= 'A' ) && (c <= 'Z' ) ) ) {
#       define XfOrM385_COUNT (0+XfOrM383_COUNT)
#       define SETUP_XfOrM385(x) SETUP_XfOrM383(x)
        FUNCCALL(SETUP_XfOrM385(_), regcharclass (c , map ) ); 
        can_range = 0 ; 
      }
      else {
        map [c ] = 1 ; 
        can_range = 1 ; 
      }
      regparse += 2 ; 
    }
    else if ((regparsestr [regparse ] == '[' ) && (parse_flags & 0x2 ) && (regparsestr [regparse + 1 ] == ':' ) && FUNCCALL(SETUP_XfOrM377(_), is_posix_char_class (regparsestr , regparse + 1 , regparse_end , map ) )) {
      regparse += 2 ; 
      while (regparsestr [regparse ] != ']' ) {
        regparse ++ ; 
      }
      regparse ++ ; 
      can_range = 0 ; 
    }
    else {
      c = ((unsigned char ) (regparsestr [regparse ++ ] ) ) ; 
      map [c ] = 1 ; 
      if (! (parse_flags & 0x1 ) ) {
        c = (((c >= 'A' ) && (c <= 'Z' ) ) ? (c + ('a' - 'A' ) ) : c ) ; 
        map [c ] = 1 ; 
        c = (((c >= 'a' ) && (c <= 'z' ) ) ? (c - ('a' - 'A' ) ) : c ) ; 
        map [c ] = 1 ; 
      }
      can_range = 1 ; 
    }
  }
  if (exclude ) {
    for (c = 0 ; c < 256 ; c ++ ) {
      map [c ] = ! map [c ] ; 
    }
  }
  if (regparsestr [regparse ] != ']' ) {
#   define XfOrM346_COUNT (0+XfOrM345_COUNT)
#   define SETUP_XfOrM346(x) SETUP_XfOrM345(x)
    FUNCCALL(SETUP_XfOrM346(_), regcomperror ("missing closing square bracket in pattern" ) ); 
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  ; 
  regparse ++ ; 
  RET_VALUE_START (map ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static rxpos regranges (int parse_flags , int at_start ) {
  int c ; 
  rxpos ret , save_regparse = 0 ; 
  int count , all_ci , num_ci , off_ranges , on_ranges , now_on , last_on , use_ci ; 
  char * new_map = ((void * ) 0 ) , * accum_map = ((void * ) 0 ) ; 
  DECL_RET_SAVE (rxpos ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(accum_map, 0), PUSH(new_map, 1)));
# define XfOrM406_COUNT (2)
# define SETUP_XfOrM406(x) SETUP(XfOrM406_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  count = 0 ; 
  while (1 ) {
#   define XfOrM483_COUNT (0+XfOrM406_COUNT)
#   define SETUP_XfOrM483(x) SETUP_XfOrM406(x)
    if (! new_map )
      new_map = (char * ) FUNCCALL(SETUP_XfOrM483(_), GC_malloc_atomic (256 ) ); 
    (memset (new_map , 0 , 256 ) ) ; 
    if (regparsestr [regparse ] == '\\' && (regparse + 1 < regparse_end ) ) {
#     define XfOrM494_COUNT (0+XfOrM483_COUNT)
#     define SETUP_XfOrM494(x) SETUP_XfOrM483(x)
      c = ((unsigned char ) (regparsestr [++ regparse ] ) ) ; 
      if (parse_flags & 0x2 ) {
#       define XfOrM495_COUNT (0+XfOrM494_COUNT)
#       define SETUP_XfOrM495(x) SETUP_XfOrM494(x)
        if ((c >= '0' ) && (c <= '9' ) )
          break ; 
        if (((c >= 'a' ) && (c <= 'z' ) ) || ((c >= 'A' ) && (c <= 'Z' ) ) )
          FUNCCALL(SETUP_XfOrM495(_), regcharclass (regparsestr [regparse ] , new_map ) ); 
        else new_map [c ] = 1 ; 
      }
      else new_map [c ] = 1 ; 
      regparse ++ ; 
    }
    else if (FUNCCALL(SETUP_XfOrM483(_), regstrcspn (regparsestr + regparse , regparsestr + regparse + 1 , (parse_flags & 0x2 ) ? "^$.[()|?+*\\{}]" : "^$.[()|?+*\\" ) )) {
      c = ((unsigned char ) (regparsestr [regparse ] ) ) ; 
      new_map [c ] = 1 ; 
      if (! (parse_flags & 0x1 ) ) {
        c = (((c >= 'A' ) && (c <= 'Z' ) ) ? (c + ('a' - 'A' ) ) : c ) ; 
        new_map [c ] = 1 ; 
        c = (((c >= 'a' ) && (c <= 'z' ) ) ? (c - ('a' - 'A' ) ) : c ) ; 
        new_map [c ] = 1 ; 
      }
      regparse ++ ; 
    }
    else if (regparsestr [regparse ] == '.' ) {
      for (c = 0 ; c < 256 ; c ++ ) {
        new_map [c ] = 1 ; 
      }
      if (! (parse_flags & 0x4 ) )
        new_map ['\n' ] = 0 ; 
      regparse ++ ; 
    }
    else if (regparsestr [regparse ] == '[' ) {
      regparse ++ ; 
#     define XfOrM488_COUNT (0+XfOrM483_COUNT)
#     define SETUP_XfOrM488(x) SETUP_XfOrM483(x)
      FUNCCALL(SETUP_XfOrM488(_), regrange (parse_flags , new_map ) ); 
    }
    else break ; 
    if (accum_map && (regparse < regparse_end ) && (regparsestr [regparse ] != '|' ) && (regparsestr [regparse ] != ')' ) )
      break ; 
    if (accum_map ) {
      for (c = 0 ; c < 256 ; c ++ ) {
        accum_map [c ] |= new_map [c ] ; 
      }
    }
    else {
      accum_map = new_map ; 
      new_map = ((void * ) 0 ) ; 
    }
    save_regparse = regparse ; 
    if (! at_start || (regparsestr [regparse ] != '|' ) || (regparse >= regparse_end ) || (regparsestr [regparse ] == ')' ) )
      break ; 
    regparse ++ ; 
  }
  regparse = save_regparse ; 
  if (! accum_map ) {
#   define XfOrM469_COUNT (0+XfOrM406_COUNT)
#   define SETUP_XfOrM469(x) SETUP_XfOrM406(x)
    FUNCCALL(SETUP_XfOrM469(_), regcomperror ("should have found one range!" ) ); 
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
  ; 
  use_ci = 0 ; 
  while (1 ) {
#   define XfOrM438_COUNT (0+XfOrM406_COUNT)
#   define SETUP_XfOrM438(x) SETUP_XfOrM406(x)
    count = 0 ; 
    num_ci = 0 ; 
    all_ci = 1 ; 
    on_ranges = 0 ; 
    off_ranges = 0 ; 
    now_on = 0 ; 
    last_on = - 1 ; 
    for (c = 0 ; c < 256 ; c ++ ) {
      if (accum_map [c ] ) {
        if (now_on < 0 )
          off_ranges ++ ; 
        now_on = 1 ; 
        count ++ ; 
        last_on = c ; 
        if (c != (((c >= 'A' ) && (c <= 'Z' ) ) ? (c + ('a' - 'A' ) ) : c ) ) {
          if (accum_map [(((c >= 'A' ) && (c <= 'Z' ) ) ? (c + ('a' - 'A' ) ) : c ) ] != accum_map [c ] )
            all_ci = 0 ; 
          num_ci ++ ; 
        }
        else if (c != (((c >= 'a' ) && (c <= 'z' ) ) ? (c - ('a' - 'A' ) ) : c ) ) {
          if (accum_map [(((c >= 'a' ) && (c <= 'z' ) ) ? (c - ('a' - 'A' ) ) : c ) ] != accum_map [c ] )
            all_ci = 0 ; 
          num_ci ++ ; 
        }
      }
      else {
        if (now_on > 0 )
          on_ranges ++ ; 
        now_on = - 1 ; 
      }
    }
    if (now_on > 0 )
      on_ranges ++ ; 
    else off_ranges ++ ; 
    if (count == 256 ) {
#     define XfOrM458_COUNT (0+XfOrM438_COUNT)
#     define SETUP_XfOrM458(x) SETUP_XfOrM438(x)
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(regnode (3 ) )) RET_VALUE_EMPTY_END ; 
    }
    else if ((count == 255 ) && ! accum_map ['\n' ] ) {
#     define XfOrM457_COUNT (0+XfOrM438_COUNT)
#     define SETUP_XfOrM457(x) SETUP_XfOrM438(x)
      RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(regnode (4 ) )) RET_VALUE_EMPTY_END ; 
    }
    else if (count == 1 ) {
#     define XfOrM456_COUNT (0+XfOrM438_COUNT)
#     define SETUP_XfOrM456(x) SETUP_XfOrM438(x)
      ret = FUNCCALL(SETUP_XfOrM456(_), regnode (6 ) ); 
      FUNCCALL(SETUP_XfOrM456(_), regc (last_on ) ); 
      RET_VALUE_START (ret ) RET_VALUE_END ; 
    }
    else if ((on_ranges == 1 ) || (off_ranges == 1 ) ) {
      int rs = 255 , re = 255 , on ; 
#     define XfOrM447_COUNT (0+XfOrM438_COUNT)
#     define SETUP_XfOrM447(x) SETUP_XfOrM438(x)
      if (on_ranges == 1 )
        on = 1 ; 
      else on = 0 ; 
      for (c = 0 ; c < 256 ; c ++ ) {
        if (! ! accum_map [c ] == on ) {
          rs = c ; 
          break ; 
        }
      }
      for (c ++ ; c < 256 ; c ++ ) {
        if (! accum_map [c ] == on ) {
          re = c - 1 ; 
          break ; 
        }
      }
      if (on )
        ret = FUNCCALL(SETUP_XfOrM447(_), regnode (7 ) ); 
      else ret = FUNCCALL(SETUP_XfOrM447(_), regnode (8 ) ); 
      FUNCCALL(SETUP_XfOrM447(_), regc (rs ) ); 
      FUNCCALL_AGAIN(regc (re ) ); 
      RET_VALUE_START (ret ) RET_VALUE_END ; 
    }
    else {
      rxpos a ; 
#     define XfOrM439_COUNT (0+XfOrM438_COUNT)
#     define SETUP_XfOrM439(x) SETUP_XfOrM438(x)
      ret = FUNCCALL(SETUP_XfOrM439(_), regnode (5 ) ); 
      a = regcode ; 
      for (c = 0 ; c < 32 ; c ++ ) {
#       define XfOrM446_COUNT (0+XfOrM439_COUNT)
#       define SETUP_XfOrM446(x) SETUP_XfOrM439(x)
        FUNCCALL(SETUP_XfOrM446(_), regc (0 ) ); 
      }
      if (regcode <= regcodesize ) {
        for (c = 0 ; c < 256 ; c ++ ) {
          if (accum_map [c ] ) {
            regstr [a + (c >> 3 ) ] |= (1 << (c & 0x7 ) ) ; 
          }
        }
      }
      RET_VALUE_START (ret ) RET_VALUE_END ; 
    }
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static char * prop_names [] = {
  "Cn" , "Cc" , "Cf" , "Cs" , "Co" , "Ll" , "Lu" , "Lt" , "Lm" , "Lo" , "Nd" , "Nl" , "No" , "Ps" , "Pe" , "Pi" , "Pf" , "Pc" , "Pd" , "Po" , "Mn" , "Mc" , "Me" , "Sc" , "Sk" , "Sm" , "So" , "Zl" , "Zp" , "Zs" , ((void * ) 0 ) }
; 
static rxpos regunicode (int negate ) {
  /* No conversion */
  rxpos ret ; 
  int len , bottom , top , i ; 
  if (regparsestr [regparse ] != '{' ) {
    {
      regcomperror ("expected { after \\p or \\P" ) ; 
      return 0 ; 
    }
    ; 
  }
  regparse ++ ; 
  if (regparsestr [regparse ] == '^' ) {
    negate = ! negate ; 
    regparse ++ ; 
  }
  len = 0 ; 
  while ((regparsestr [regparse + len ] != '}' ) && (regparse + len < regparse_end ) ) {
    len ++ ; 
  }
  if (regparse + len >= regparse_end ) {
    {
      regcomperror ("missing } to close \\p{ or \\P{" ) ; 
      return 0 ; 
    }
    ; 
  }
  bottom = top = - 1 ; 
  if (len == 2 ) {
    for (i = 0 ; prop_names [i ] ; i ++ ) {
      if ((regparsestr [regparse ] == prop_names [i ] [0 ] ) && (regparsestr [regparse + 1 ] == prop_names [i ] [1 ] ) ) {
        bottom = top = i ; 
        break ; 
      }
    }
    if (bottom == - 1 ) {
      if ((regparsestr [regparse ] == 'L' ) && (regparsestr [regparse + 1 ] == '&' ) ) {
        bottom = mzu_Ll ; 
        top = mzu_Lm ; 
      }
    }
  }
  else if (len == 1 ) {
    if (regparsestr [regparse ] == '.' ) {
      bottom = 0 ; 
      top = mzu_Zs ; 
    }
    else {
      for (i = 0 ; prop_names [i ] ; i ++ ) {
        if (regparsestr [regparse ] == prop_names [i ] [0 ] ) {
          bottom = i ; 
          while (prop_names [i + 1 ] ) {
            if (regparsestr [regparse ] != prop_names [i + 1 ] [0 ] )
              break ; 
            i ++ ; 
          }
          top = i ; 
          break ; 
        }
      }
    }
  }
  if (bottom < 0 ) {
    {
      regcomperror ("unrecognized property name in \\p{} or \\P{}" ) ; 
      return 0 ; 
    }
    ; 
  }
  regparse += len + 1 ; 
  ret = regnode (41 ) ; 
  regarg ((negate << 13 ) | (bottom << 6 ) | top ) ; 
  return ret ; 
}
static int regdigit () {
  /* No conversion */
  int posn , c ; 
  c = regparsestr [regparse ++ ] ; 
  posn = c - '0' ; 
  while (regparse < regparse_end ) {
    c = regparsestr [regparse ] ; 
    if ((c >= '0' ) && (c <= '9' ) ) {
      posn = (posn * 10 ) + (c - '0' ) ; 
      if (posn > 0x7FFF ) {
        regcomperror ("backreference number is too large" ) ; 
        return 0 ; 
      }
      ; 
      regparse ++ ; 
    }
    else break ; 
  }
  if (posn > regmaxbackposn )
    regmaxbackposn = posn ; 
  return posn ; 
}
static rxpos regnode (char op ) {
  /* No conversion */
  rxpos ret ; 
  rxpos ptr ; 
  ret = regcode ; 
  if (regcode + 3 >= regcodesize ) {
    regcode += 3 ; 
    if (regcode > regcodemax )
      regcodemax = regcode ; 
    return ret ; 
  }
  ptr = ret ; 
  regstr [ptr ++ ] = op ; 
  regstr [ptr ++ ] = '\0' ; 
  regstr [ptr ++ ] = '\0' ; 
  regcode = ptr ; 
  if (regcode > regcodemax )
    regcodemax = regcode ; 
  return ret ; 
}
static void regc (char b ) {
  /* No conversion */
  if (regcode + 1 < regcodesize )
    regstr [regcode ] = b ; 
  regcode ++ ; 
  if (regcode > regcodemax )
    regcodemax = regcode ; 
}
static void regarg (int v ) {
  /* No conversion */
  regc (v >> 8 ) ; 
  regc (v & 255 ) ; 
}
static void regshift (int amt , rxpos opnd ) {
  /* No conversion */
  if (regcode + amt < regcodesize ) {
    memmove (regstr XFORM_OK_PLUS opnd + amt , regstr XFORM_OK_PLUS opnd , regcode - opnd ) ; 
  }
  regcode += amt ; 
  if (regcode > regcodemax )
    regcodemax = regcode ; 
}
static void reginsert (char op , rxpos opnd ) {
  /* No conversion */
  regshift (3 , opnd ) ; 
  if (opnd + 3 >= regcodesize ) {
    return ; 
  }
  regstr [opnd ++ ] = op ; 
  regstr [opnd ++ ] = '\0' ; 
  regstr [opnd ++ ] = '\0' ; 
}
static rxpos reginsertwithop (char op , rxpos opnd , int arg ) {
  /* No conversion */
  regshift (5 , opnd ) ; 
  if (opnd + 5 >= regcodesize ) {
    return opnd + 5 ; 
  }
  regstr [opnd ++ ] = op ; 
  regstr [opnd ++ ] = '\0' ; 
  regstr [opnd ++ ] = '\0' ; 
  regstr [opnd ++ ] = (arg >> 8 ) ; 
  regstr [opnd ++ ] = (arg & 255 ) ; 
  return opnd ; 
}
static rxpos reginsertwithopop (char op , rxpos opnd , int arg , int arg2 ) {
  /* No conversion */
  regshift (7 , opnd ) ; 
  if (opnd + 7 >= regcodesize ) {
    return opnd + 7 ; 
  }
  regstr [opnd ++ ] = op ; 
  regstr [opnd ++ ] = '\0' ; 
  regstr [opnd ++ ] = '\0' ; 
  regstr [opnd ++ ] = (arg >> 8 ) ; 
  regstr [opnd ++ ] = (arg & 255 ) ; 
  regstr [opnd ++ ] = (arg2 >> 8 ) ; 
  regstr [opnd ++ ] = (arg2 & 255 ) ; 
  return opnd ; 
}
static void regtail (rxpos p , rxpos val ) {
  /* No conversion */
  rxpos scan ; 
  rxpos temp ; 
  int offset ; 
  scan = p ; 
  for (; ; ) {
    if (scan + 2 >= regcodesize ) {
      return ; 
    }
    temp = regnext (scan ) ; 
    if (temp == 0 )
      break ; 
    scan = temp ; 
  }
  if (scan + 2 >= regcodesize ) {
    return ; 
  }
  if ((regstr [scan ] ) == 10 )
    offset = scan - val ; 
  else offset = val - scan ; 
  regstr [scan + 1 ] = (offset >> 8 ) & 255 ; 
  regstr [scan + 2 ] = offset & 255 ; 
}
static void regoptail (rxpos p , rxpos val ) {
  /* No conversion */
  if (p == 0 || (p >= regcodesize ) || (regstr [p ] ) != 9 ) {
    return ; 
  }
  regtail (((p ) + 3 ) , val ) ; 
}
static int merge_tables (Scheme_Hash_Table * dest , Scheme_Hash_Table * src ) {
  int i ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(src, 0), PUSH(dest, 1)));
# define XfOrM551_COUNT (2)
# define SETUP_XfOrM551(x) SETUP(XfOrM551_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  for (i = src -> size ; i -- ; ) {
#   define XfOrM554_COUNT (0+XfOrM551_COUNT)
#   define SETUP_XfOrM554(x) SETUP_XfOrM551(x)
    if (src -> vals [i ] ) {
#     define XfOrM555_COUNT (0+XfOrM554_COUNT)
#     define SETUP_XfOrM555(x) SETUP_XfOrM554(x)
      FUNCCALL(SETUP_XfOrM555(_), scheme_hash_set (dest , src -> keys [i ] , src -> vals [i ] ) ); 
    }
  }
  RET_VALUE_START (1 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int check_and_propagate_depends (void ) {
  int i , j ; 
  Scheme_Hash_Table * backdepends = regbackdepends , * ht , * next_ht = ((void * ) 0 ) ; 
  Scheme_Object * v ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(next_ht, 0), PUSH(v, 1), PUSH(backdepends, 2), PUSH(ht, 3)));
# define XfOrM556_COUNT (4)
# define SETUP_XfOrM556(x) SETUP(XfOrM556_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  ht = NULLED_OUT ; 
  v = NULLED_OUT ; 
  while (backdepends ) {
#   define XfOrM580_COUNT (0+XfOrM556_COUNT)
#   define SETUP_XfOrM580(x) SETUP_XfOrM556(x)
    for (i = backdepends -> size ; i -- ; ) {
#     define XfOrM592_COUNT (0+XfOrM580_COUNT)
#     define SETUP_XfOrM592(x) SETUP_XfOrM580(x)
      if (backdepends -> vals [i ] ) {
#       define XfOrM593_COUNT (0+XfOrM592_COUNT)
#       define SETUP_XfOrM593(x) SETUP_XfOrM592(x)
        if (regbackknown )
          v = FUNCCALL(SETUP_XfOrM593(_), scheme_hash_get (regbackknown , backdepends -> keys [i ] ) ); 
        else v = ((void * ) 0 ) ; 
        if (v ) {
#         define XfOrM595_COUNT (0+XfOrM593_COUNT)
#         define SETUP_XfOrM595(x) SETUP_XfOrM593(x)
          if ((((v ) ) == (scheme_false ) ) ) {
#           define XfOrM601_COUNT (0+XfOrM595_COUNT)
#           define SETUP_XfOrM601(x) SETUP_XfOrM595(x)
            {
#             define XfOrM602_COUNT (0+XfOrM601_COUNT)
#             define SETUP_XfOrM602(x) SETUP_XfOrM601(x)
              FUNCCALL(SETUP_XfOrM602(_), regcomperror ("*, +, or {...,} operand could be empty (via empty backreference)" ) ); 
              RET_VALUE_START (0 ) RET_VALUE_END ; 
            }
            ; 
          }
          if (((Scheme_Type ) (((((long ) (v ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (v ) ) -> type ) ) == (Scheme_Type ) (scheme_hash_table_type ) ) ) {
#           define XfOrM596_COUNT (0+XfOrM595_COUNT)
#           define SETUP_XfOrM596(x) SETUP_XfOrM595(x)
            FUNCCALL(SETUP_XfOrM596(_), scheme_hash_set (regbackknown , backdepends -> keys [i ] , scheme_true ) ); 
            if (! next_ht )
              next_ht = FUNCCALL(SETUP_XfOrM596(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
            ht = (Scheme_Hash_Table * ) v ; 
            for (j = ht -> size ; j -- ; ) {
#             define XfOrM599_COUNT (0+XfOrM596_COUNT)
#             define SETUP_XfOrM599(x) SETUP_XfOrM596(x)
              if (ht -> vals [j ] ) {
#               define XfOrM600_COUNT (0+XfOrM599_COUNT)
#               define SETUP_XfOrM600(x) SETUP_XfOrM599(x)
                FUNCCALL(SETUP_XfOrM600(_), scheme_hash_set (next_ht , ht -> keys [j ] , ht -> vals [j ] ) ); 
              }
            }
          }
        }
        else {
#         define XfOrM594_COUNT (0+XfOrM593_COUNT)
#         define SETUP_XfOrM594(x) SETUP_XfOrM593(x)
          if (! regbackknown )
            regbackknown = FUNCCALL(SETUP_XfOrM594(_), scheme_make_hash_table (SCHEME_hash_ptr ) ); 
          FUNCCALL(SETUP_XfOrM594(_), scheme_hash_set (regbackknown , backdepends -> keys [i ] , scheme_true ) ); 
        }
      }
    }
    backdepends = next_ht ; 
    next_ht = ((void * ) 0 ) ; 
  }
  RET_VALUE_START (1 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static inline rxpos l_strchr (char * str , rxpos a , int l , int c ) {
  /* No conversion */
  int i ; 
  for (i = 0 ; i < l ; i ++ ) {
    if (str [a + i ] == c )
      return a + i ; 
  }
  return - 1 ; 
}
static inline rxpos l_strchr_ci (char * str , rxpos a , int l , int c ) {
  /* No conversion */
  int i , ch ; 
  for (i = 0 ; i < l ; i ++ ) {
    ch = str [a + i ] ; 
    ch = (((ch >= 'A' ) && (ch <= 'Z' ) ) ? (ch + ('a' - 'A' ) ) : ch ) ; 
    if (ch == c )
      return a + i ; 
  }
  return - 1 ; 
}
static inline int in_ranges (char * str , rxpos a , int l , int c ) {
  /* No conversion */
  int i ; 
  l *= 2 ; 
  for (i = 0 ; i < l ; i += 2 ) {
    if ((((unsigned char ) (str [a + i ] ) ) <= c ) && (((unsigned char ) (str [a + i + 1 ] ) ) >= c ) )
      return 1 ; 
  }
  return 0 ; 
}
static inline int in_ranges_ci (char * str , rxpos a , int l , int c ) {
  /* No conversion */
  int i ; 
  l *= 2 ; 
  c = (((c >= 'A' ) && (c <= 'Z' ) ) ? (c + ('a' - 'A' ) ) : c ) ; 
  for (i = 0 ; i < l ; i += 2 ) {
    if ((((unsigned char ) (str [a + i ] ) ) <= c ) && (((unsigned char ) (str [a + i + 1 ] ) ) >= c ) )
      return 1 ; 
  }
  return 0 ; 
}
static int regtry (regexp * , char * , int , int , rxpos * , rxpos * , rxpos * , int * , Regwork * rw , rxpos , int , int , int ) ; 
static int regtry_port (regexp * , Scheme_Object * , Scheme_Object * , int nonblock , rxpos * , rxpos * , rxpos * , int * , char * * , rxpos * , rxpos * , rxpos , Scheme_Object * , Scheme_Object * , rxpos , int , int , int ) ; 
static int regmatch (Regwork * rw , rxpos ) ; 
static int regrepeat (Regwork * rw , rxpos , int ) ; 
/* this far 2547 */
/* this far 2547 */
static int regexec (const char * who , regexp * prog , char * string , int stringpos , int stringlen , rxpos * startp , rxpos * maybep , rxpos * endp , Scheme_Object * port , Scheme_Object * unless_evt , int nonblock , char * * stringp , int peek , int get_offsets , Scheme_Object * discard_oport , Scheme_Object * portstart , Scheme_Object * portend , Scheme_Object * * _dropped ) {
  int spos ; 
  int * counters ; 
  Scheme_Object * dropped = ((void * ) 0 ) , * peekskip = ((void * ) 0 ) ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(18);
  BLOCK_SETUP_TOP((PUSH(port, 0), PUSH(_dropped, 1), PUSH(dropped, 2), PUSH(discard_oport, 3), PUSH(startp, 4), PUSH(endp, 5), PUSH(unless_evt, 6), PUSH(portstart, 7), PUSH(string, 8), PUSH(peekskip, 9), PUSH(who, 10), PUSH(prog, 11), PUSH(portend, 12), PUSH(maybep, 13), PUSH(counters, 14), PUSH(stringp, 15)));
# define XfOrM615_COUNT (16)
# define SETUP_XfOrM615(x) SETUP(XfOrM615_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  counters = NULLED_OUT ; 
  if (((unsigned char ) (prog -> program [0 ] ) ) != 156 ) {
#   define XfOrM672_COUNT (0+XfOrM615_COUNT)
#   define SETUP_XfOrM672(x) SETUP_XfOrM615(x)
    FUNCCALL(SETUP_XfOrM672(_), regerror ("corrupted program" ) ); 
    RET_VALUE_START ((0 ) ) RET_VALUE_END ; 
  }
  if (! port && (prog -> regmust >= 0 ) ) {
#   define XfOrM655_COUNT (0+XfOrM615_COUNT)
#   define SETUP_XfOrM655(x) SETUP_XfOrM615(x)
    spos = stringpos ; 
    while (1 ) {
      int i , l = prog -> regmlen , ch , pos ; 
      GC_CAN_IGNORE char * p ; 
#     define XfOrM664_COUNT (0+XfOrM655_COUNT)
#     define SETUP_XfOrM664(x) SETUP_XfOrM655(x)
      if ((spos - stringpos ) + l <= stringlen ) {
#       define XfOrM671_COUNT (0+XfOrM664_COUNT)
#       define SETUP_XfOrM671(x) SETUP_XfOrM664(x)
        if (prog -> flags & 0x08 )
          pos = FUNCCALL(SETUP_XfOrM671(_), l_strchr_ci (string , spos , stringlen - (spos - stringpos ) - (l - 1 ) , ((char * ) prog XFORM_OK_PLUS prog -> regmust ) [0 ] ) ); 
        else pos = FUNCCALL(SETUP_XfOrM671(_), l_strchr (string , spos , stringlen - (spos - stringpos ) - (l - 1 ) , ((char * ) prog XFORM_OK_PLUS prog -> regmust ) [0 ] ) ); 
        if (pos == - 1 )
          RET_VALUE_START (0 ) RET_VALUE_END ; 
      }
      else RET_VALUE_START (0 ) RET_VALUE_END ; 
      p = ((char * ) prog XFORM_OK_PLUS prog -> regmust ) ; 
      if (prog -> flags & 0x08 ) {
        for (i = 0 ; i < l ; i ++ ) {
          ch = string [pos + i ] ; 
          ch = (((ch >= 'A' ) && (ch <= 'Z' ) ) ? (ch + ('a' - 'A' ) ) : ch ) ; 
          if (ch != p [i ] )
            break ; 
        }
      }
      else {
        for (i = 0 ; i < l ; i ++ ) {
          if (string [pos + i ] != p [i ] )
            break ; 
        }
      }
      if (i >= l )
        break ; 
      spos = pos + 1 ; 
    }
  }
  if (prog -> ncounter ) {
#   define XfOrM654_COUNT (0+XfOrM615_COUNT)
#   define SETUP_XfOrM654(x) SETUP_XfOrM615(x)
    counters = (int * ) FUNCCALL(SETUP_XfOrM654(_), GC_malloc_atomic (sizeof (int ) * prog -> ncounter ) ); 
  }
  else counters = ((void * ) 0 ) ; 
  if (port ) {
#   define XfOrM645_COUNT (0+XfOrM615_COUNT)
#   define SETUP_XfOrM645(x) SETUP_XfOrM615(x)
    if (peek ) {
      peekskip = portstart ; 
      dropped = portstart ; 
    }
    else {
      long amt , got ; 
#     define XfOrM646_COUNT (0+XfOrM645_COUNT)
#     define SETUP_XfOrM646(x) SETUP_XfOrM645(x)
      if ((((long ) (portstart ) ) & 0x1 ) ) {
        amt = (((long ) (portstart ) ) >> 1 ) ; 
        if (amt > 4096 )
          amt = 4096 ; 
      }
      else amt = 4096 ; 
      dropped = ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
      if (amt ) {
        char * drain ; 
        BLOCK_SETUP((PUSH(drain, 0+XfOrM646_COUNT)));
#       define XfOrM647_COUNT (1+XfOrM646_COUNT)
#       define SETUP_XfOrM647(x) SETUP(XfOrM647_COUNT)
        drain = NULLED_OUT ; 
        drain = (char * ) FUNCCALL(SETUP_XfOrM647(_), GC_malloc_atomic (amt ) ); 
        do {
#         define XfOrM650_COUNT (0+XfOrM647_COUNT)
#         define SETUP_XfOrM650(x) SETUP_XfOrM647(x)
          got = FUNCCALL(SETUP_XfOrM650(_), scheme_get_byte_string (who , port , drain , 0 , amt , 0 , 0 , 0 ) ); 
          if (got != (- 1 ) ) {
            Scheme_Object * delta ; 
            BLOCK_SETUP((PUSH(delta, 0+XfOrM650_COUNT)));
#           define XfOrM651_COUNT (1+XfOrM650_COUNT)
#           define SETUP_XfOrM651(x) SETUP(XfOrM651_COUNT)
            delta = NULLED_OUT ; 
            if (discard_oport )
              FUNCCALL(SETUP_XfOrM651(_), scheme_put_byte_string (who , discard_oport , drain , 0 , got , 0 ) ); 
            dropped = FUNCCALL(SETUP_XfOrM651(_), scheme_bin_plus (dropped , ((Scheme_Object * ) (void * ) (long ) ((((long ) (amt ) ) << 1 ) | 0x1 ) ) ) ); 
            delta = FUNCCALL_AGAIN(scheme_bin_minus (portstart , dropped ) ); 
            if (FUNCCALL(SETUP_XfOrM651(_), scheme_bin_gt (((Scheme_Object * ) (void * ) (long ) ((((long ) (amt ) ) << 1 ) | 0x1 ) ) , delta ) ))
              amt = (((long ) (delta ) ) >> 1 ) ; 
          }
        }
        while ((got != (- 1 ) ) && amt ) ; 
        if (amt )
          RET_VALUE_START (0 ) RET_VALUE_END ; 
      }
    }
    if (portend )
      portend = FUNCCALL(SETUP_XfOrM645(_), scheme_bin_minus (portend , dropped ) ); 
  }
  if (prog -> flags & 0x04 ) {
#   define XfOrM632_COUNT (0+XfOrM615_COUNT)
#   define SETUP_XfOrM632(x) SETUP_XfOrM615(x)
    if (port ) {
      rxpos len = 0 , space = 0 ; 
#     define XfOrM633_COUNT (0+XfOrM632_COUNT)
#     define SETUP_XfOrM633(x) SETUP_XfOrM632(x)
      * stringp = ((void * ) 0 ) ; 
      if (FUNCCALL(SETUP_XfOrM633(_), regtry_port (prog , port , unless_evt , nonblock , startp , maybep , endp , counters , stringp , & len , & space , 0 , portend , peekskip , 0 , 1 , 1 , 0 ) )) {
#       define XfOrM643_COUNT (0+XfOrM633_COUNT)
#       define SETUP_XfOrM643(x) SETUP_XfOrM633(x)
        if (! peek ) {
          char * drain ; 
          long got ; 
          BLOCK_SETUP((PUSH(drain, 0+XfOrM643_COUNT)));
#         define XfOrM644_COUNT (1+XfOrM643_COUNT)
#         define SETUP_XfOrM644(x) SETUP(XfOrM644_COUNT)
          drain = NULLED_OUT ; 
          if (discard_oport && * startp )
            FUNCCALL(SETUP_XfOrM644(_), scheme_put_byte_string (who , discard_oport , * stringp , 0 , * startp , 0 ) ); 
          if (get_offsets )
            drain = * stringp ; 
          else drain = (char * ) FUNCCALL(SETUP_XfOrM644(_), GC_malloc_atomic (* endp ) ); 
          got = FUNCCALL(SETUP_XfOrM644(_), scheme_get_byte_string (who , port , drain , 0 , * endp , 0 , 0 , 0 ) ); 
        }
        * _dropped = dropped ; 
        RET_VALUE_START (1 ) RET_VALUE_END ; 
      }
      else {
#       define XfOrM634_COUNT (0+XfOrM633_COUNT)
#       define SETUP_XfOrM634(x) SETUP_XfOrM633(x)
        if (! peek ) {
          char * drain ; 
          long got ; 
          BLOCK_SETUP((PUSH(drain, 0+XfOrM634_COUNT)));
#         define XfOrM635_COUNT (1+XfOrM634_COUNT)
#         define SETUP_XfOrM635(x) SETUP(XfOrM635_COUNT)
          drain = NULLED_OUT ; 
          if (portend && (((long ) (portend ) ) & 0x1 ) && (((long ) (portend ) ) >> 1 ) < 4096 ) {
            got = (((long ) (portend ) ) >> 1 ) ; 
          }
          else got = 4096 ; 
          drain = (char * ) FUNCCALL(SETUP_XfOrM635(_), GC_malloc_atomic (got ) ); 
          while ((got = FUNCCALL(SETUP_XfOrM635(_), scheme_get_byte_string (who , port , drain , 0 , got , 0 , 0 , 0 ) )) != (- 1 ) ) {
#           define XfOrM639_COUNT (0+XfOrM635_COUNT)
#           define SETUP_XfOrM639(x) SETUP_XfOrM635(x)
            if (discard_oport )
              FUNCCALL(SETUP_XfOrM639(_), scheme_put_byte_string (who , discard_oport , drain , 0 , got , 0 ) ); 
            if (portend ) {
#             define XfOrM640_COUNT (0+XfOrM639_COUNT)
#             define SETUP_XfOrM640(x) SETUP_XfOrM639(x)
              portend = FUNCCALL(SETUP_XfOrM640(_), scheme_bin_minus (portend , ((Scheme_Object * ) (void * ) (long ) ((((long ) (got ) ) << 1 ) | 0x1 ) ) ) ); 
              if ((((long ) (portend ) ) & 0x1 ) ) {
                got = (((long ) (portend ) ) >> 1 ) ; 
                if (! got )
                  break ; 
                else if (got > 4096 )
                  got = 4096 ; 
              }
            }
            else got = 4096 ; 
          }
        }
        RET_VALUE_START (0 ) RET_VALUE_END ; 
      }
    }
    else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(regtry (prog , string , stringpos , stringlen , startp , maybep , endp , counters , 0 , stringpos , 1 , 1 , 0 ) )) RET_VALUE_EMPTY_END ; 
  }
  spos = stringpos ; 
  if (port ) {
    int at_line_start = 1 ; 
    rxpos len = 0 , skip = 0 , space = 0 ; 
#   define XfOrM617_COUNT (0+XfOrM615_COUNT)
#   define SETUP_XfOrM617(x) SETUP_XfOrM615(x)
    * stringp = ((void * ) 0 ) ; 
    do {
      int discard = skip - prog -> maxlookback ; 
#     define XfOrM626_COUNT (0+XfOrM617_COUNT)
#     define SETUP_XfOrM626(x) SETUP_XfOrM617(x)
      if (discard >= 256 ) {
#       define XfOrM629_COUNT (0+XfOrM626_COUNT)
#       define SETUP_XfOrM629(x) SETUP_XfOrM626(x)
        if (! peek ) {
#         define XfOrM631_COUNT (0+XfOrM629_COUNT)
#         define SETUP_XfOrM631(x) SETUP_XfOrM629(x)
          if (discard_oport )
            FUNCCALL(SETUP_XfOrM631(_), scheme_put_byte_string (who , discard_oport , * stringp , 0 , discard , 0 ) ); 
          FUNCCALL(SETUP_XfOrM631(_), scheme_get_byte_string (who , port , * stringp , 0 , discard , 0 , 0 , 0 ) ); 
          if (portend )
            portend = FUNCCALL(SETUP_XfOrM631(_), scheme_bin_minus (portend , ((Scheme_Object * ) (void * ) (long ) ((((long ) (discard ) ) << 1 ) | 0x1 ) ) ) ); 
        }
        else {
#         define XfOrM630_COUNT (0+XfOrM629_COUNT)
#         define SETUP_XfOrM630(x) SETUP_XfOrM629(x)
          peekskip = FUNCCALL(SETUP_XfOrM630(_), scheme_bin_plus (peekskip , ((Scheme_Object * ) (void * ) (long ) ((((long ) (discard ) ) << 1 ) | 0x1 ) ) ) ); 
        }
        dropped = FUNCCALL(SETUP_XfOrM629(_), scheme_bin_plus (dropped , ((Scheme_Object * ) (void * ) (long ) ((((long ) (discard ) ) << 1 ) | 0x1 ) ) ) ); 
        len -= discard ; 
        skip -= discard ; 
        (memmove (* stringp , * stringp + discard , len ) ) ; 
      }
      if (FUNCCALL(SETUP_XfOrM626(_), regtry_port (prog , port , unless_evt , nonblock , startp , maybep , endp , counters , stringp , & len , & space , skip , portend , peekskip , 0 , ! space , at_line_start , 1 ) )) {
#       define XfOrM627_COUNT (0+XfOrM626_COUNT)
#       define SETUP_XfOrM627(x) SETUP_XfOrM626(x)
        if (! peek ) {
          char * drain ; 
          BLOCK_SETUP((PUSH(drain, 0+XfOrM627_COUNT)));
#         define XfOrM628_COUNT (1+XfOrM627_COUNT)
#         define SETUP_XfOrM628(x) SETUP(XfOrM628_COUNT)
          drain = NULLED_OUT ; 
          if (discard_oport && * startp )
            FUNCCALL(SETUP_XfOrM628(_), scheme_put_byte_string (who , discard_oport , * stringp , 0 , * startp , 0 ) ); 
          if (get_offsets )
            drain = * stringp ; 
          else drain = (char * ) FUNCCALL(SETUP_XfOrM628(_), GC_malloc_atomic (* endp ) ); 
          FUNCCALL(SETUP_XfOrM628(_), scheme_get_byte_string (who , port , drain , 0 , * endp , 0 , 0 , 0 ) ); 
        }
        * _dropped = dropped ; 
        RET_VALUE_START (1 ) RET_VALUE_END ; 
      }
      at_line_start = ((skip < len ) && ((* stringp ) [skip ] == '\n' ) ) ; 
      skip ++ ; 
    }
    while (len >= skip ) ; 
    if (! peek ) {
#     define XfOrM618_COUNT (0+XfOrM617_COUNT)
#     define SETUP_XfOrM618(x) SETUP_XfOrM617(x)
      if (len > 0 ) {
#       define XfOrM619_COUNT (0+XfOrM618_COUNT)
#       define SETUP_XfOrM619(x) SETUP_XfOrM618(x)
        if (discard_oport )
          FUNCCALL(SETUP_XfOrM619(_), scheme_put_byte_string (who , discard_oport , * stringp , 0 , len , 0 ) ); 
        FUNCCALL(SETUP_XfOrM619(_), scheme_get_byte_string (who , port , * stringp , 0 , len , 0 , 0 , 0 ) ); 
      }
    }
  }
  else {
#   define XfOrM616_COUNT (0+XfOrM615_COUNT)
#   define SETUP_XfOrM616(x) SETUP_XfOrM615(x)
    if (FUNCCALL_EMPTY(regtry (prog , string , spos , stringlen - (spos - stringpos ) , startp , maybep , endp , counters , 0 , stringpos , 1 , 1 , 1 ) ))
      RET_VALUE_START (1 ) RET_VALUE_END ; 
  }
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int regtry (regexp * prog , char * string , int stringpos , int stringlen , rxpos * startp , rxpos * maybep , rxpos * endp , int * counters , Regwork * rw , rxpos stringorigin , int atstart , int atlinestart , int unanchored ) {
  int i ; 
  Regwork _rw ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(14);
  BLOCK_SETUP_TOP((PUSH(prog, 0), PUSH(string, 1), PUSH(endp, 2), PUSH(startp, 3), PUSH(rw, 4), PUSH(_rw.str, 5), PUSH(_rw.instr, 6), PUSH(_rw.port, 7), PUSH(_rw.unless_evt, 8), PUSH(_rw.startp, 9), PUSH(_rw.maybep, 10), PUSH(_rw.endp, 11), PUSH(_rw.counters, 12), PUSH(_rw.peekskip, 13)));
# define XfOrM673_COUNT (14)
# define SETUP_XfOrM673(x) SETUP(XfOrM673_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  _rw.str = NULLED_OUT ; 
  _rw.instr = NULLED_OUT ; 
  _rw.port = NULLED_OUT ; 
  _rw.unless_evt = NULLED_OUT ; 
  _rw.startp = NULLED_OUT ; 
  _rw.maybep = NULLED_OUT ; 
  _rw.endp = NULLED_OUT ; 
  _rw.counters = NULLED_OUT ; 
  _rw.peekskip = NULLED_OUT ; 
  if (! rw ) {
    rw = & _rw ; 
    rw -> port = ((void * ) 0 ) ; 
  }
  rw -> instr = string ; 
  rw -> input = stringpos ; 
  rw -> input_end = stringpos + stringlen ; 
  rw -> input_start = stringorigin ; 
  rw -> startp = startp ; 
  rw -> maybep = maybep ; 
  rw -> endp = endp ; 
  rw -> counters = counters ; 
  if (atstart )
    rw -> boi = stringpos ; 
  else rw -> boi = - 1 ; 
  if (atlinestart )
    rw -> bol = stringpos ; 
  else rw -> bol = - 1 ; 
  for (i = prog -> nsubexp ; i -- ; ) {
    startp [i ] = - 1 ; 
    endp [i ] = - 1 ; 
  }
  regstr = (char * ) prog ; 
  while (1 ) {
    int found ; 
#   define XfOrM682_COUNT (0+XfOrM673_COUNT)
#   define SETUP_XfOrM682(x) SETUP_XfOrM673(x)
    found = FUNCCALL(SETUP_XfOrM682(_), regmatch (rw , ((prog -> program + 1 ) - (char * ) prog ) ) ); 
    if (found ) {
      startp [0 ] = stringpos ; 
      endp [0 ] = rw -> input ; 
      RET_VALUE_START (1 ) RET_VALUE_END ; 
    }
    else if (unanchored ) {
      if (! stringlen )
        RET_VALUE_START (0 ) RET_VALUE_END ; 
      stringpos ++ ; 
      -- stringlen ; 
      if (prog -> regstart ) {
        unsigned char * rs = prog -> regstart ; 
        int c ; 
        while (1 ) {
          if (! stringlen )
            RET_VALUE_START (0 ) RET_VALUE_END ; 
          c = ((unsigned char ) (string [stringpos ] ) ) ; 
          if (rs [c >> 3 ] & (1 << (c & 0x7 ) ) )
            break ; 
          stringpos ++ ; 
          -- stringlen ; 
        }
      }
      if (string [stringpos - 1 ] == '\n' )
        rw -> bol = stringpos ; 
      else rw -> bol = - 1 ; 
      rw -> boi = - 1 ; 
      rw -> input = stringpos ; 
      for (i = prog -> nsubexp ; i -- ; ) {
        startp [i ] = - 1 ; 
        endp [i ] = - 1 ; 
      }
    }
    else RET_VALUE_START (0 ) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static void read_more_from_regport (Regwork * rw , rxpos need_total ) {
  long got ; 
  Scheme_Object * peekskip ; 
  PREPARE_VAR_STACK(3);
  BLOCK_SETUP_TOP((PUSH(peekskip, 0), PUSH(rw, 1)));
# define XfOrM693_COUNT (2)
# define SETUP_XfOrM693(x) SETUP(XfOrM693_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  peekskip = NULLED_OUT ; 
  if (need_total > rw -> input_maxend ) {
    need_total = rw -> input_maxend ; 
    if (need_total <= rw -> input_end ) {
      rw -> port = ((void * ) 0 ) ; 
      RET_NOTHING ; 
    }
  }
  if (rw -> instr_size < need_total ) {
    char * naya ; 
    long size = rw -> instr_size ; 
    BLOCK_SETUP((PUSH(naya, 0+XfOrM693_COUNT)));
#   define XfOrM700_COUNT (1+XfOrM693_COUNT)
#   define SETUP_XfOrM700(x) SETUP(XfOrM700_COUNT)
    naya = NULLED_OUT ; 
    size = size * 2 ; 
    if (size < need_total )
      size += need_total ; 
    if (size < 16 )
      size = 16 ; 
    naya = (char * ) FUNCCALL(SETUP_XfOrM700(_), GC_malloc_atomic (size ) ); 
    (memcpy (naya , rw -> instr , rw -> input_end ) ) ; 
    rw -> instr = naya ; 
    rw -> instr_size = size ; 
  }
  rw -> str = regstr ; 
  if (rw -> input_maxend < rw -> instr_size )
    got = rw -> input_maxend - rw -> input_end ; 
  else got = rw -> instr_size - rw -> input_end ; 
  if (rw -> peekskip )
    peekskip = FUNCCALL(SETUP_XfOrM693(_), scheme_bin_plus (((Scheme_Object * ) (void * ) (long ) ((((long ) (rw -> input_end ) ) << 1 ) | 0x1 ) ) , rw -> peekskip ) ); 
  else peekskip = ((Scheme_Object * ) (void * ) (long ) ((((long ) (rw -> input_end ) ) << 1 ) | 0x1 ) ) ; 
  got = FUNCCALL(SETUP_XfOrM693(_), scheme_get_byte_string_unless ("regexp-match" , rw -> port , rw -> instr , rw -> input_end , got , (rw -> nonblock ? 2 : 1 ) , 1 , peekskip , rw -> unless_evt ) ); 
  regstr = rw -> str ; 
  if (got < 1 ) {
    if (! got )
      rw -> aborted = 1 ; 
    rw -> port = ((void * ) 0 ) ; 
    rw -> unless_evt = ((void * ) 0 ) ; 
  }
  else {
#   define XfOrM694_COUNT (0+XfOrM693_COUNT)
#   define SETUP_XfOrM694(x) SETUP_XfOrM693(x)
    rw -> input_end += got ; 
    if (need_total > rw -> input_end ) {
#     define XfOrM695_COUNT (0+XfOrM694_COUNT)
#     define SETUP_XfOrM695(x) SETUP_XfOrM694(x)
      if (rw -> nonblock ) {
        rw -> port = ((void * ) 0 ) ; 
        rw -> unless_evt = ((void * ) 0 ) ; 
        rw -> aborted = 1 ; 
      }
      else {
#       define XfOrM696_COUNT (0+XfOrM695_COUNT)
#       define SETUP_XfOrM696(x) SETUP_XfOrM695(x)
        if (rw -> peekskip )
          peekskip = FUNCCALL(SETUP_XfOrM696(_), scheme_bin_plus (((Scheme_Object * ) (void * ) (long ) ((((long ) (rw -> input_end ) ) << 1 ) | 0x1 ) ) , rw -> peekskip ) ); 
        else peekskip = ((Scheme_Object * ) (void * ) (long ) ((((long ) (rw -> input_end ) ) << 1 ) | 0x1 ) ) ; 
        rw -> str = regstr ; 
        got = FUNCCALL(SETUP_XfOrM696(_), scheme_get_byte_string_unless ("regexp-match" , rw -> port , rw -> instr , rw -> input_end , need_total - rw -> input_end , 0 , 1 , peekskip , rw -> unless_evt ) ); 
        regstr = rw -> str ; 
        if (got == (- 1 ) ) {
          rw -> port = ((void * ) 0 ) ; 
          rw -> unless_evt = ((void * ) 0 ) ; 
        }
        else rw -> input_end += got ; 
      }
    }
  }
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 2804 */
static int regtry_port (regexp * prog , Scheme_Object * port , Scheme_Object * unless_evt , int nonblock , rxpos * startp , rxpos * maybep , rxpos * endp , int * counters , char * * work_string , rxpos * len , rxpos * size , rxpos skip , Scheme_Object * maxlen , Scheme_Object * peekskip , rxpos origin , int atstart , int atlinestart , int read_at_least_one ) {
  int m ; 
  Regwork rw ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(13);
  BLOCK_SETUP_TOP((PUSH(work_string, 0), PUSH(len, 1), PUSH(size, 2), PUSH(rw.str, 3), PUSH(rw.instr, 4), PUSH(rw.port, 5), PUSH(rw.unless_evt, 6), PUSH(rw.startp, 7), PUSH(rw.maybep, 8), PUSH(rw.endp, 9), PUSH(rw.counters, 10), PUSH(rw.peekskip, 11), PUSH(port, 12)));
# define XfOrM703_COUNT (13)
# define SETUP_XfOrM703(x) SETUP(XfOrM703_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  rw.str = NULLED_OUT ; 
  rw.instr = NULLED_OUT ; 
  rw.port = NULLED_OUT ; 
  rw.unless_evt = NULLED_OUT ; 
  rw.startp = NULLED_OUT ; 
  rw.maybep = NULLED_OUT ; 
  rw.endp = NULLED_OUT ; 
  rw.counters = NULLED_OUT ; 
  rw.peekskip = NULLED_OUT ; 
  rw . port = port ; 
  rw . unless_evt = unless_evt ; 
  rw . nonblock = (short ) nonblock ; 
  rw . aborted = 0 ; 
  rw . instr_size = * size ; 
  if (maxlen && (((long ) (maxlen ) ) & 0x1 ) )
    rw . input_maxend = (((long ) (maxlen ) ) >> 1 ) ; 
  else rw . input_maxend = 0x7FFFFFFFFFFFFFFF ; 
  rw . peekskip = peekskip ; 
  m = FUNCCALL(SETUP_XfOrM703(_), regtry (prog , * work_string , skip , (* len ) - skip , startp , maybep , endp , counters , & rw , origin , atstart , atlinestart , 0 ) ); 
  if (read_at_least_one && ! rw . aborted && (rw . input_end == skip ) && rw . port ) {
#   define XfOrM704_COUNT (0+XfOrM703_COUNT)
#   define SETUP_XfOrM704(x) SETUP_XfOrM703(x)
    FUNCCALL(SETUP_XfOrM704(_), read_more_from_regport (& rw , rw . input_end + 1 ) ); 
  }
  * work_string = rw . instr ; 
  * len = rw . input_end ; 
  * size = rw . instr_size ; 
  if (rw . aborted )
    RET_VALUE_START (0 ) RET_VALUE_END ; 
  else RET_VALUE_START (m ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * regmatch_k (void ) {
  /* No conversion */
  Scheme_Thread * p = scheme_current_thread ; 
  Regwork * rw = (Regwork * ) p -> ku . k . p1 ; 
  int res ; 
  p -> ku . k . p1 = ((void * ) 0 ) ; 
  regstr = rw -> str ; 
  res = regmatch (rw , p -> ku . k . i1 ) ; 
  return (res ? scheme_true : scheme_false ) ; 
}
static int regmatch (Regwork * rw , rxpos prog ) {
  rxpos scan ; 
  rxpos is ; 
  int the_op ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(4);
  BLOCK_SETUP_TOP((PUSH(rw, 0)));
# define XfOrM706_COUNT (1)
# define SETUP_XfOrM706(x) SETUP(XfOrM706_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  {
    unsigned long _stk_pos ; 
#   define XfOrM940_COUNT (0+XfOrM706_COUNT)
#   define SETUP_XfOrM940(x) SETUP_XfOrM706(x)
    _stk_pos = (unsigned long ) & _stk_pos ; 
    if (((_stk_pos ) < (scheme_stack_boundary ) ) ) {
      Scheme_Thread * p = scheme_current_thread ; 
      Regwork * rw2 ; 
      Scheme_Object * res ; 
      BLOCK_SETUP((PUSH(rw2, 0+XfOrM940_COUNT), PUSH(res, 1+XfOrM940_COUNT), PUSH(p, 2+XfOrM940_COUNT)));
#     define XfOrM941_COUNT (3+XfOrM940_COUNT)
#     define SETUP_XfOrM941(x) SETUP(XfOrM941_COUNT)
      rw2 = NULLED_OUT ; 
      res = NULLED_OUT ; 
      rw2 = ((Regwork * ) FUNCCALL(SETUP_XfOrM941(_), GC_malloc_one_small_tagged ((((sizeof (Regwork ) * (1 ) + (1 << 3 ) - 1 ) >> 3 ) << 3 ) ) )) ; 
      (memcpy (rw2 , rw , sizeof (Regwork ) ) ) ; 
      rw2 -> type = scheme_rt_regwork ; 
      rw2 -> str = regstr ; 
      p -> ku . k . p1 = rw2 ; 
      p -> ku . k . i1 = prog ; 
      res = FUNCCALL(SETUP_XfOrM941(_), scheme_handle_stack_overflow (regmatch_k ) ); 
      (memcpy (rw , rw2 , sizeof (Regwork ) ) ) ; 
      RET_VALUE_START ((! (((res ) ) == (scheme_false ) ) ) ) RET_VALUE_END ; 
    }
  }
  if ((scheme_fuel_counter ) <= 0 ) {
    char * rs ; 
    BLOCK_SETUP((PUSH(rs, 0+XfOrM706_COUNT)));
#   define XfOrM939_COUNT (1+XfOrM706_COUNT)
#   define SETUP_XfOrM939(x) SETUP(XfOrM939_COUNT)
    rs = NULLED_OUT ; 
    rs = regstr ; 
    FUNCCALL(SETUP_XfOrM939(_), scheme_out_of_fuel () ); 
    regstr = rs ; 
  }
  is = rw -> input ; 
  scan = prog ; 
  while (scan != 0 ) {
#   define XfOrM823_COUNT (0+XfOrM706_COUNT)
#   define SETUP_XfOrM823(x) SETUP_XfOrM706(x)
    the_op = (regstr [scan ] ) ; 
    switch (the_op ) {
#     define XfOrM824_COUNT (0+XfOrM823_COUNT)
#     define SETUP_XfOrM824(x) SETUP_XfOrM823(x)
      case 1 : if (is != rw -> boi )
        RET_VALUE_START ((0 ) ) RET_VALUE_END ; 
      scan = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
      break ; 
      case 2 : if (rw -> port && (((is ) + (1 ) ) > rw -> input_end ) )
        FUNCCALL(SETUP_XfOrM824(_), read_more_from_regport (rw , (is ) + (1 ) ) ); 
      if (is != rw -> input_end )
        RET_VALUE_START ((0 ) ) RET_VALUE_END ; 
      scan = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
      break ; 
      case 39 : if ((is != rw -> bol ) && ((is <= rw -> input_start ) || (rw -> instr [is - 1 ] != '\n' ) ) )
        RET_VALUE_START ((0 ) ) RET_VALUE_END ; 
      scan = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
      break ; 
      case 40 : if (rw -> port && (((is ) + (1 ) ) > rw -> input_end ) )
        FUNCCALL(SETUP_XfOrM824(_), read_more_from_regport (rw , (is ) + (1 ) ) ); 
      if (is != rw -> input_end ) {
        if (rw -> instr [is ] != '\n' )
          RET_VALUE_START ((0 ) ) RET_VALUE_END ; 
      }
      scan = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
      break ; 
      case 3 : if (rw -> port && (((is ) + (1 ) ) > rw -> input_end ) )
        FUNCCALL(SETUP_XfOrM824(_), read_more_from_regport (rw , (is ) + (1 ) ) ); 
      if (is == rw -> input_end )
        RET_VALUE_START ((0 ) ) RET_VALUE_END ; 
      is ++ ; 
      scan = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
      break ; 
      case 4 : if (rw -> port && (((is ) + (1 ) ) > rw -> input_end ) )
        FUNCCALL(SETUP_XfOrM824(_), read_more_from_regport (rw , (is ) + (1 ) ) ); 
      if (is == rw -> input_end )
        RET_VALUE_START ((0 ) ) RET_VALUE_END ; 
      if (rw -> instr [is ] == '\n' )
        RET_VALUE_START (0 ) RET_VALUE_END ; 
      is ++ ; 
      scan = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
      break ; 
      case 11 : {
        int len , i ; 
        rxpos opnd ; 
#       define XfOrM931_COUNT (0+XfOrM824_COUNT)
#       define SETUP_XfOrM931(x) SETUP_XfOrM824(x)
        opnd = (((scan ) + 3 ) + 2 ) ; 
        len = ((int ) (((unsigned char * ) regstr ) [((scan ) + 3 ) ] << 8 ) | (((unsigned char * ) regstr ) [((scan ) + 3 ) + 1 ] ) ) ; 
        if (rw -> port ) {
#         define XfOrM935_COUNT (0+XfOrM931_COUNT)
#         define SETUP_XfOrM935(x) SETUP_XfOrM931(x)
          for (i = 0 ; i < len ; i ++ ) {
#           define XfOrM937_COUNT (0+XfOrM935_COUNT)
#           define SETUP_XfOrM937(x) SETUP_XfOrM935(x)
            if (rw -> port && (((is + i ) + (1 ) ) > rw -> input_end ) )
              FUNCCALL(SETUP_XfOrM937(_), read_more_from_regport (rw , (is + i ) + (1 ) ) ); 
            if (is + i >= rw -> input_end )
              RET_VALUE_START (0 ) RET_VALUE_END ; 
            if (regstr [opnd + i ] != rw -> instr [is + i ] )
              RET_VALUE_START (0 ) RET_VALUE_END ; 
          }
        }
        else {
          if (len > rw -> input_end - is )
            RET_VALUE_START (0 ) RET_VALUE_END ; 
          for (i = 0 ; i < len ; i ++ ) {
            if (regstr [opnd + i ] != rw -> instr [is + i ] )
              RET_VALUE_START (0 ) RET_VALUE_END ; 
          }
        }
        is += len ; 
      }
      scan = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
      break ; 
      case 12 : {
        int len , i ; 
        char c ; 
        rxpos opnd ; 
#       define XfOrM924_COUNT (0+XfOrM824_COUNT)
#       define SETUP_XfOrM924(x) SETUP_XfOrM824(x)
        opnd = (((scan ) + 3 ) + 2 ) ; 
        len = ((int ) (((unsigned char * ) regstr ) [((scan ) + 3 ) ] << 8 ) | (((unsigned char * ) regstr ) [((scan ) + 3 ) + 1 ] ) ) ; 
        if (rw -> port ) {
#         define XfOrM928_COUNT (0+XfOrM924_COUNT)
#         define SETUP_XfOrM928(x) SETUP_XfOrM924(x)
          for (i = 0 ; i < len ; i ++ ) {
#           define XfOrM930_COUNT (0+XfOrM928_COUNT)
#           define SETUP_XfOrM930(x) SETUP_XfOrM928(x)
            if (rw -> port && (((is + i ) + (1 ) ) > rw -> input_end ) )
              FUNCCALL(SETUP_XfOrM930(_), read_more_from_regport (rw , (is + i ) + (1 ) ) ); 
            if (is + i >= rw -> input_end )
              RET_VALUE_START (0 ) RET_VALUE_END ; 
            c = rw -> instr [is + i ] ; 
            c = (((c >= 'A' ) && (c <= 'Z' ) ) ? (c + ('a' - 'A' ) ) : c ) ; 
            if (regstr [opnd + i ] != c )
              RET_VALUE_START (0 ) RET_VALUE_END ; 
          }
        }
        else {
          if (len > rw -> input_end - is )
            RET_VALUE_START (0 ) RET_VALUE_END ; 
          for (i = 0 ; i < len ; i ++ ) {
            c = rw -> instr [is + i ] ; 
            c = (((c >= 'A' ) && (c <= 'Z' ) ) ? (c + ('a' - 'A' ) ) : c ) ; 
            if (regstr [opnd + i ] != c )
              RET_VALUE_START (0 ) RET_VALUE_END ; 
          }
        }
        is += len ; 
      }
      scan = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
      break ; 
      case 5 : {
        int c ; 
#       define XfOrM923_COUNT (0+XfOrM824_COUNT)
#       define SETUP_XfOrM923(x) SETUP_XfOrM824(x)
        if (rw -> port && (((is ) + (1 ) ) > rw -> input_end ) )
          FUNCCALL(SETUP_XfOrM923(_), read_more_from_regport (rw , (is ) + (1 ) ) ); 
        if (is == rw -> input_end )
          RET_VALUE_START (0 ) RET_VALUE_END ; 
        c = ((unsigned char ) (rw -> instr [is ] ) ) ; 
        if (! (regstr [((scan ) + 3 ) + (c >> 3 ) ] & (1 << (c & 0x7 ) ) ) )
          RET_VALUE_START ((0 ) ) RET_VALUE_END ; 
        is ++ ; 
        scan = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
      }
      break ; 
      case 6 : if (rw -> port && (((is ) + (1 ) ) > rw -> input_end ) )
        FUNCCALL(SETUP_XfOrM824(_), read_more_from_regport (rw , (is ) + (1 ) ) ); 
      if (is == rw -> input_end )
        RET_VALUE_START (0 ) RET_VALUE_END ; 
      if (rw -> instr [is ] != regstr [((scan ) + 3 ) ] )
        RET_VALUE_START (0 ) RET_VALUE_END ; 
      is ++ ; 
      scan = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
      break ; 
      case 7 : {
        int c ; 
#       define XfOrM922_COUNT (0+XfOrM824_COUNT)
#       define SETUP_XfOrM922(x) SETUP_XfOrM824(x)
        if (rw -> port && (((is ) + (1 ) ) > rw -> input_end ) )
          FUNCCALL(SETUP_XfOrM922(_), read_more_from_regport (rw , (is ) + (1 ) ) ); 
        if (is == rw -> input_end )
          RET_VALUE_START (0 ) RET_VALUE_END ; 
        c = ((unsigned char ) (rw -> instr [is ] ) ) ; 
        if ((c < ((unsigned char ) (regstr [((scan ) + 3 ) ] ) ) ) || (c > ((unsigned char ) (regstr [((scan ) + 3 ) + 1 ] ) ) ) )
          RET_VALUE_START ((0 ) ) RET_VALUE_END ; 
        is ++ ; 
        scan = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
      }
      break ; 
      case 8 : {
        int c ; 
#       define XfOrM921_COUNT (0+XfOrM824_COUNT)
#       define SETUP_XfOrM921(x) SETUP_XfOrM824(x)
        if (rw -> port && (((is ) + (1 ) ) > rw -> input_end ) )
          FUNCCALL(SETUP_XfOrM921(_), read_more_from_regport (rw , (is ) + (1 ) ) ); 
        if (is == rw -> input_end )
          RET_VALUE_START (0 ) RET_VALUE_END ; 
        c = ((unsigned char ) (rw -> instr [is ] ) ) ; 
        if ((c >= ((unsigned char ) (regstr [((scan ) + 3 ) ] ) ) ) && (c <= ((unsigned char ) (regstr [((scan ) + 3 ) + 1 ] ) ) ) )
          RET_VALUE_START ((0 ) ) RET_VALUE_END ; 
        is ++ ; 
        scan = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
      }
      break ; 
      case 13 : scan = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
      break ; 
      case 10 : scan = scan - (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ; 
      break ; 
      case 9 : {
        rxpos delta ; 
        rxpos next ; 
#       define XfOrM917_COUNT (0+XfOrM824_COUNT)
#       define SETUP_XfOrM917(x) SETUP_XfOrM824(x)
        next = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
        if ((regstr [next ] ) != 9 )
          scan = ((scan ) + 3 ) ; 
        else {
#         define XfOrM918_COUNT (0+XfOrM917_COUNT)
#         define SETUP_XfOrM918(x) SETUP_XfOrM917(x)
          do {
#           define XfOrM920_COUNT (0+XfOrM918_COUNT)
#           define SETUP_XfOrM920(x) SETUP_XfOrM918(x)
            rw -> input = is ; 
            if (FUNCCALL(SETUP_XfOrM920(_), regmatch (rw , ((scan ) + 3 ) ) ))
              RET_VALUE_START ((1 ) ) RET_VALUE_END ; 
            scan = next ; 
            delta = (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ; 
            if (! delta )
              break ; 
            next = scan + delta ; 
          }
          while ((regstr [next ] ) == 9 ) ; 
          scan = ((scan ) + 3 ) ; 
        }
      }
      break ; 
      case 14 : case 15 : case 16 : case 17 : case 18 : case 19 : {
        char nextch ; 
        int no ; 
        rxpos save , body ; 
        int min , maxc ; 
        int nongreedy = (the_op == 16 || the_op == 17 || the_op == 19 ) ; 
        rxpos next ; 
#       define XfOrM897_COUNT (0+XfOrM824_COUNT)
#       define SETUP_XfOrM897(x) SETUP_XfOrM824(x)
        nextch = '\0' ; 
        next = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
        if ((regstr [next ] ) == 11 )
          nextch = regstr [(((next ) + 3 ) + 2 ) ] ; 
        if ((the_op == 18 ) || (the_op == 19 ) ) {
          min = ((int ) (((unsigned char * ) regstr ) [((scan ) + 3 ) ] << 8 ) | (((unsigned char * ) regstr ) [((scan ) + 3 ) + 1 ] ) ) ; 
          maxc = ((int ) (((unsigned char * ) regstr ) [((scan ) + 5 ) ] << 8 ) | (((unsigned char * ) regstr ) [((scan ) + 5 ) + 1 ] ) ) ; 
          body = ((scan ) + 7 ) ; 
        }
        else {
          body = ((scan ) + 3 ) ; 
          min = ((the_op == 14 ) || (the_op == 16 ) ) ? 0 : 1 ; 
          maxc = 0 ; 
        }
        save = is ; 
        rw -> input = is ; 
        if (nongreedy && rw -> port ) {
          Scheme_Object * saveport ; 
          BLOCK_SETUP((PUSH(saveport, 0+XfOrM897_COUNT)));
#         define XfOrM914_COUNT (1+XfOrM897_COUNT)
#         define SETUP_XfOrM914(x) SETUP(XfOrM914_COUNT)
          saveport = NULLED_OUT ; 
          if (rw -> port && (((save ) + (1 ) ) > rw -> input_end ) )
            FUNCCALL(SETUP_XfOrM914(_), read_more_from_regport (rw , (save ) + (1 ) ) ); 
          saveport = rw -> port ; 
          rw -> port = ((void * ) 0 ) ; 
          no = FUNCCALL(SETUP_XfOrM914(_), regrepeat (rw , body , maxc ) ); 
          rw -> port = saveport ; 
          nongreedy = 2 ; 
        }
        else no = FUNCCALL(SETUP_XfOrM897(_), regrepeat (rw , body , maxc ) ); 
        if (! nongreedy ) {
#         define XfOrM909_COUNT (0+XfOrM897_COUNT)
#         define SETUP_XfOrM909(x) SETUP_XfOrM897(x)
          if (nextch )
            if (rw -> port && (((save + no ) + (1 ) ) > rw -> input_end ) )
            FUNCCALL(SETUP_XfOrM909(_), read_more_from_regport (rw , (save + no ) + (1 ) ) ); 
          while (no >= min ) {
#           define XfOrM912_COUNT (0+XfOrM909_COUNT)
#           define SETUP_XfOrM912(x) SETUP_XfOrM909(x)
            if (nextch == '\0' || ((save + no < rw -> input_end ) && (rw -> instr [save + no ] == nextch ) ) ) {
#             define XfOrM913_COUNT (0+XfOrM912_COUNT)
#             define SETUP_XfOrM913(x) SETUP_XfOrM912(x)
              rw -> input = is + no ; 
              if (FUNCCALL(SETUP_XfOrM913(_), regmatch (rw , next ) ))
                RET_VALUE_START ((1 ) ) RET_VALUE_END ; 
            }
            no -- ; 
          }
        }
        else {
          int i ; 
#         define XfOrM898_COUNT (0+XfOrM897_COUNT)
#         define SETUP_XfOrM898(x) SETUP_XfOrM897(x)
          for (i = min ; i <= no ; i ++ ) {
#           define XfOrM904_COUNT (0+XfOrM898_COUNT)
#           define SETUP_XfOrM904(x) SETUP_XfOrM898(x)
            if (nextch )
              if (rw -> port && (((save + i ) + (1 ) ) > rw -> input_end ) )
              FUNCCALL(SETUP_XfOrM904(_), read_more_from_regport (rw , (save + i ) + (1 ) ) ); 
            if (nextch == '\0' || ((save + i < rw -> input_end ) && (rw -> instr [save + i ] == nextch ) ) ) {
#             define XfOrM907_COUNT (0+XfOrM904_COUNT)
#             define SETUP_XfOrM907(x) SETUP_XfOrM904(x)
              rw -> input = save + i ; 
              if (FUNCCALL(SETUP_XfOrM907(_), regmatch (rw , next ) )) {
                RET_VALUE_START ((1 ) ) RET_VALUE_END ; 
              }
            }
            if ((i == no ) && (nongreedy == 2 ) ) {
#             define XfOrM905_COUNT (0+XfOrM904_COUNT)
#             define SETUP_XfOrM905(x) SETUP_XfOrM904(x)
              if ((rw -> input_end - save ) > no ) {
                int moreno ; 
                Scheme_Object * saveport ; 
                BLOCK_SETUP((PUSH(saveport, 0+XfOrM905_COUNT)));
#               define XfOrM906_COUNT (1+XfOrM905_COUNT)
#               define SETUP_XfOrM906(x) SETUP(XfOrM906_COUNT)
                saveport = NULLED_OUT ; 
                saveport = rw -> port ; 
                rw -> port = ((void * ) 0 ) ; 
                is = save + no ; 
                rw -> input = is ; 
                moreno = FUNCCALL(SETUP_XfOrM906(_), regrepeat (rw , body , maxc ? maxc - no : 0 ) ); 
                rw -> port = saveport ; 
                if (! moreno )
                  nongreedy = 1 ; 
                else no += moreno ; 
              }
            }
          }
        }
        RET_VALUE_START ((0 ) ) RET_VALUE_END ; 
      }
      break ; 
      case 0 : case 27 : rw -> input = is ; 
      RET_VALUE_START ((1 ) ) RET_VALUE_END ; 
      break ; 
      case 28 : {
        int no , len , start , i ; 
#       define XfOrM890_COUNT (0+XfOrM824_COUNT)
#       define SETUP_XfOrM890(x) SETUP_XfOrM824(x)
        no = ((int ) (((unsigned char * ) regstr ) [((scan ) + 3 ) ] << 8 ) | (((unsigned char * ) regstr ) [((scan ) + 3 ) + 1 ] ) ) ; 
        if (rw -> endp [no ] == - 1 )
          RET_VALUE_START (0 ) RET_VALUE_END ; 
        start = rw -> startp [no ] ; 
        len = rw -> endp [no ] - start ; 
        if (rw -> port ) {
#         define XfOrM894_COUNT (0+XfOrM890_COUNT)
#         define SETUP_XfOrM894(x) SETUP_XfOrM890(x)
          for (i = 0 ; i < len ; i ++ ) {
#           define XfOrM896_COUNT (0+XfOrM894_COUNT)
#           define SETUP_XfOrM896(x) SETUP_XfOrM894(x)
            if (rw -> port && (((is + i ) + (1 ) ) > rw -> input_end ) )
              FUNCCALL(SETUP_XfOrM896(_), read_more_from_regport (rw , (is + i ) + (1 ) ) ); 
            if (is + i >= rw -> input_end )
              RET_VALUE_START (0 ) RET_VALUE_END ; 
            if (rw -> instr [start + i ] != rw -> instr [is + i ] )
              RET_VALUE_START (0 ) RET_VALUE_END ; 
          }
        }
        else {
          if (len > rw -> input_end - is )
            RET_VALUE_START (0 ) RET_VALUE_END ; 
          for (i = 0 ; i < len ; i ++ ) {
            if (rw -> instr [start + i ] != rw -> instr [is + i ] )
              RET_VALUE_START (0 ) RET_VALUE_END ; 
          }
        }
        is += len ; 
        scan = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
        break ; 
      }
      case 29 : {
        int no , len , start , i , c1 , c2 ; 
#       define XfOrM883_COUNT (0+XfOrM824_COUNT)
#       define SETUP_XfOrM883(x) SETUP_XfOrM824(x)
        no = ((int ) (((unsigned char * ) regstr ) [((scan ) + 3 ) ] << 8 ) | (((unsigned char * ) regstr ) [((scan ) + 3 ) + 1 ] ) ) ; 
        if (rw -> endp [no ] == - 1 )
          RET_VALUE_START (0 ) RET_VALUE_END ; 
        start = rw -> startp [no ] ; 
        len = rw -> endp [no ] - start ; 
        if (rw -> port ) {
#         define XfOrM887_COUNT (0+XfOrM883_COUNT)
#         define SETUP_XfOrM887(x) SETUP_XfOrM883(x)
          for (i = 0 ; i < len ; i ++ ) {
#           define XfOrM889_COUNT (0+XfOrM887_COUNT)
#           define SETUP_XfOrM889(x) SETUP_XfOrM887(x)
            if (rw -> port && (((is + i ) + (1 ) ) > rw -> input_end ) )
              FUNCCALL(SETUP_XfOrM889(_), read_more_from_regport (rw , (is + i ) + (1 ) ) ); 
            if (is + i >= rw -> input_end )
              RET_VALUE_START (0 ) RET_VALUE_END ; 
            c1 = rw -> instr [start + i ] ; 
            c1 = (((c1 >= 'A' ) && (c1 <= 'Z' ) ) ? (c1 + ('a' - 'A' ) ) : c1 ) ; 
            c2 = rw -> instr [is + i ] ; 
            c2 = (((c2 >= 'A' ) && (c2 <= 'Z' ) ) ? (c2 + ('a' - 'A' ) ) : c2 ) ; 
            if (c1 != c2 )
              RET_VALUE_START (0 ) RET_VALUE_END ; 
          }
        }
        else {
          if (len > rw -> input_end - is )
            RET_VALUE_START (0 ) RET_VALUE_END ; 
          for (i = 0 ; i < len ; i ++ ) {
            c1 = rw -> instr [start + i ] ; 
            c1 = (((c1 >= 'A' ) && (c1 <= 'Z' ) ) ? (c1 + ('a' - 'A' ) ) : c1 ) ; 
            c2 = rw -> instr [is + i ] ; 
            c2 = (((c2 >= 'A' ) && (c2 <= 'Z' ) ) ? (c2 + ('a' - 'A' ) ) : c2 ) ; 
            if (c1 != c2 )
              RET_VALUE_START (0 ) RET_VALUE_END ; 
          }
        }
        is += len ; 
        scan = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
        break ; 
      }
      case 22 : case 23 : case 24 : case 25 : case 26 : {
        int t , no , no_start , no_end ; 
        rxpos save , next ; 
#       define XfOrM866_COUNT (0+XfOrM824_COUNT)
#       define SETUP_XfOrM866(x) SETUP_XfOrM824(x)
        next = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
        t = ((the_op != 23 ) && (the_op != 26 ) ) ; 
        if ((the_op == 25 ) || (the_op == 26 ) ) {
          no_start = ((int ) (((unsigned char * ) regstr ) [((scan ) + 5 ) ] << 8 ) | (((unsigned char * ) regstr ) [((scan ) + 5 ) + 1 ] ) ) ; 
          no_end = ((int ) (((unsigned char * ) regstr ) [((scan ) + 7 ) ] << 8 ) | (((unsigned char * ) regstr ) [((scan ) + 7 ) + 1 ] ) ) ; 
        }
        else no_start = no_end = 0 ; 
        save = is ; 
        if (no_end ) {
#         define XfOrM870_COUNT (0+XfOrM866_COUNT)
#         define SETUP_XfOrM870(x) SETUP_XfOrM866(x)
          for (no = no_start ; no <= no_end ; no ++ ) {
#           define XfOrM877_COUNT (0+XfOrM870_COUNT)
#           define SETUP_XfOrM877(x) SETUP_XfOrM870(x)
            if (is - rw -> input_start >= no ) {
#             define XfOrM879_COUNT (0+XfOrM877_COUNT)
#             define SETUP_XfOrM879(x) SETUP_XfOrM877(x)
              rw -> input = save - no ; 
              if (FUNCCALL(SETUP_XfOrM879(_), regmatch (rw , next ) )) {
                if (is == save ) {
                  if (! t )
                    RET_VALUE_START (0 ) RET_VALUE_END ; 
                  break ; 
                }
              }
            }
            else {
              no = no_end + 1 ; 
              break ; 
            }
          }
          if (no > no_end ) {
            if (t )
              RET_VALUE_START (0 ) RET_VALUE_END ; 
          }
        }
        else {
#         define XfOrM867_COUNT (0+XfOrM866_COUNT)
#         define SETUP_XfOrM867(x) SETUP_XfOrM866(x)
          rw -> input = is ; 
          if (FUNCCALL(SETUP_XfOrM867(_), regmatch (rw , next ) )) {
            if (! t )
              RET_VALUE_START (0 ) RET_VALUE_END ; 
          }
          else {
            if (t )
              RET_VALUE_START (0 ) RET_VALUE_END ; 
          }
          if (the_op == 24 )
            is = rw -> input ; 
        }
        scan = scan + ((int ) (((unsigned char * ) regstr ) [((scan ) + 3 ) ] << 8 ) | (((unsigned char * ) regstr ) [((scan ) + 3 ) + 1 ] ) ) ; 
        scan = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
      }
      break ; 
      case 30 : {
        int no ; 
        no = ((int ) (((unsigned char * ) regstr ) [((scan ) + 3 ) ] << 8 ) | (((unsigned char * ) regstr ) [((scan ) + 3 ) + 1 ] ) ) ; 
        rw -> counters [no ] = 0 ; 
        scan = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
      }
      break ; 
      case 33 : {
        int no ; 
        no = ((int ) (((unsigned char * ) regstr ) [((scan ) + 3 ) ] << 8 ) | (((unsigned char * ) regstr ) [((scan ) + 3 ) + 1 ] ) ) ; 
        rw -> counters [no ] -= 1 ; 
        scan = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
      }
      break ; 
      case 34 : {
        int no ; 
        no = ((int ) (((unsigned char * ) regstr ) [((scan ) + 3 ) ] << 8 ) | (((unsigned char * ) regstr ) [((scan ) + 3 ) + 1 ] ) ) ; 
        rw -> counters [no ] -= 1 ; 
        RET_VALUE_START (0 ) RET_VALUE_END ; 
      }
      break ; 
      case 32 : {
        int no , maxreps ; 
        no = ((int ) (((unsigned char * ) regstr ) [((scan ) + 3 ) ] << 8 ) | (((unsigned char * ) regstr ) [((scan ) + 3 ) + 1 ] ) ) ; 
        maxreps = ((int ) (((unsigned char * ) regstr ) [((scan ) + 5 ) ] << 8 ) | (((unsigned char * ) regstr ) [((scan ) + 5 ) + 1 ] ) ) ; 
        rw -> counters [no ] ++ ; 
        if (maxreps && (rw -> counters [no ] > maxreps ) )
          RET_VALUE_START (0 ) RET_VALUE_END ; 
        scan = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
      }
      break ; 
      case 31 : {
        int no , minreps ; 
        no = ((int ) (((unsigned char * ) regstr ) [((scan ) + 3 ) ] << 8 ) | (((unsigned char * ) regstr ) [((scan ) + 3 ) + 1 ] ) ) ; 
        minreps = ((int ) (((unsigned char * ) regstr ) [((scan ) + 5 ) ] << 8 ) | (((unsigned char * ) regstr ) [((scan ) + 5 ) + 1 ] ) ) ; 
        if (rw -> counters [no ] < minreps )
          RET_VALUE_START (0 ) RET_VALUE_END ; 
        scan = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
      }
      break ; 
      case 35 : {
        int no , len ; 
        no = ((int ) (((unsigned char * ) regstr ) [((scan ) + 3 ) ] << 8 ) | (((unsigned char * ) regstr ) [((scan ) + 3 ) + 1 ] ) ) ; 
        len = ((int ) (((unsigned char * ) regstr ) [((scan ) + 5 ) ] << 8 ) | (((unsigned char * ) regstr ) [((scan ) + 5 ) + 1 ] ) ) ; 
        if (! len || (is > rw -> maybep [no ] ) ) {
          rw -> startp [no ] = is - len ; 
          rw -> endp [no ] = is ; 
        }
        else {
          rw -> startp [no ] = - 1 ; 
          rw -> endp [no ] = - 1 ; 
        }
        scan = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
      }
      break ; 
      case 36 : {
        int no ; 
        no = ((int ) (((unsigned char * ) regstr ) [((scan ) + 3 ) ] << 8 ) | (((unsigned char * ) regstr ) [((scan ) + 3 ) + 1 ] ) ) ; 
        rw -> maybep [no ] = is ; 
        scan = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
      }
      break ; 
      case 37 : {
        int c , w1 , w2 ; 
#       define XfOrM854_COUNT (0+XfOrM824_COUNT)
#       define SETUP_XfOrM854(x) SETUP_XfOrM824(x)
        if (rw -> port && (((is ) + (1 ) ) > rw -> input_end ) )
          FUNCCALL(SETUP_XfOrM854(_), read_more_from_regport (rw , (is ) + (1 ) ) ); 
        if (is > rw -> input_start ) {
          c = rw -> instr [is - 1 ] ; 
          w1 = (((c >= 'a' ) && (c <= 'z' ) ) || ((c >= 'A' ) && (c <= 'Z' ) ) || ((c >= '0' ) && (c <= '9' ) ) || (c == '_' ) ) ; 
        }
        else w1 = 0 ; 
        if (is < rw -> input_end ) {
          c = rw -> instr [is ] ; 
          w2 = (((c >= 'a' ) && (c <= 'z' ) ) || ((c >= 'A' ) && (c <= 'Z' ) ) || ((c >= '0' ) && (c <= '9' ) ) || (c == '_' ) ) ; 
        }
        else w2 = 0 ; 
        if (w1 == w2 )
          RET_VALUE_START (0 ) RET_VALUE_END ; 
        scan = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
      }
      break ; 
      case 38 : {
        int c , w1 , w2 ; 
#       define XfOrM851_COUNT (0+XfOrM824_COUNT)
#       define SETUP_XfOrM851(x) SETUP_XfOrM824(x)
        if (rw -> port && (((is ) + (1 ) ) > rw -> input_end ) )
          FUNCCALL(SETUP_XfOrM851(_), read_more_from_regport (rw , (is ) + (1 ) ) ); 
        if (is > rw -> input_start ) {
          c = rw -> instr [is - 1 ] ; 
          w1 = (((c >= 'a' ) && (c <= 'z' ) ) || ((c >= 'A' ) && (c <= 'Z' ) ) || ((c >= '0' ) && (c <= '9' ) ) || (c == '_' ) ) ; 
        }
        else w1 = 0 ; 
        if (is < rw -> input_end ) {
          c = rw -> instr [is ] ; 
          w2 = (((c >= 'a' ) && (c <= 'z' ) ) || ((c >= 'A' ) && (c <= 'Z' ) ) || ((c >= '0' ) && (c <= '9' ) ) || (c == '_' ) ) ; 
        }
        else w2 = 0 ; 
        if (w1 != w2 )
          RET_VALUE_START (0 ) RET_VALUE_END ; 
        scan = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
      }
      break ; 
      case 41 : {
        unsigned char buf [6 ] ; 
        mzchar us [1 ] ; 
        int c , data ; 
        int v , pos ; 
        int negate , bottom , top ; 
#       define XfOrM839_COUNT (0+XfOrM824_COUNT)
#       define SETUP_XfOrM839(x) SETUP_XfOrM824(x)
        data = ((int ) (((unsigned char * ) regstr ) [((scan ) + 3 ) ] << 8 ) | (((unsigned char * ) regstr ) [((scan ) + 3 ) + 1 ] ) ) ; 
        negate = data >> 13 ; 
        bottom = (data >> 6 ) & 0x3F ; 
        top = data & 0x3F ; 
        if (rw -> port && (((rw -> input ) + (1 ) ) > rw -> input_end ) )
          FUNCCALL(SETUP_XfOrM839(_), read_more_from_regport (rw , (rw -> input ) + (1 ) ) ); 
        if (rw -> input < rw -> input_end ) {
#         define XfOrM842_COUNT (0+XfOrM839_COUNT)
#         define SETUP_XfOrM842(x) SETUP_XfOrM839(x)
          c = ((unsigned char ) (rw -> instr [rw -> input ] ) ) ; 
          if (c < 128 ) {
            v = c ; 
            pos = 1 ; 
          }
          else {
#           define XfOrM843_COUNT (0+XfOrM842_COUNT)
#           define SETUP_XfOrM843(x) SETUP_XfOrM842(x)
            pos = 1 ; 
            buf [0 ] = c ; 
            while (1 ) {
#             define XfOrM847_COUNT (0+XfOrM843_COUNT)
#             define SETUP_XfOrM847(x) SETUP_XfOrM843(x)
              v = FUNCCALL(SETUP_XfOrM847(_), scheme_utf8_decode_prefix (buf , pos , us , 0 ) ); 
              if (v == 1 ) {
                v = us [0 ] ; 
                break ; 
              }
              else if (v < - 1 )
                RET_VALUE_START (0 ) RET_VALUE_END ; 
              if (rw -> port && (((rw -> input ) + (pos + 1 ) ) > rw -> input_end ) )
                FUNCCALL(SETUP_XfOrM847(_), read_more_from_regport (rw , (rw -> input ) + (pos + 1 ) ) ); 
              if (rw -> input + pos < rw -> input_end ) {
                buf [pos ] = rw -> instr [rw -> input + pos ] ; 
                pos ++ ; 
              }
              else RET_VALUE_START (0 ) RET_VALUE_END ; 
            }
          }
        }
        else RET_VALUE_START (0 ) RET_VALUE_END ; 
        is += pos ; 
        v = (((scheme_uchar_cats_table [(v >> 8 ) & 0x1FFF ] [v & 0xFF ] ) ) & 0x1F ) ; 
        if (negate ) {
          if ((v >= bottom ) && (v <= top ) )
            RET_VALUE_START (0 ) RET_VALUE_END ; 
        }
        else {
          if ((v < bottom ) || (v > top ) )
            RET_VALUE_START (0 ) RET_VALUE_END ; 
        }
        scan = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
      }
      break ; 
      case 42 : {
        rxpos test = ((scan ) + 7 ) ; 
        int t ; 
#       define XfOrM836_COUNT (0+XfOrM824_COUNT)
#       define SETUP_XfOrM836(x) SETUP_XfOrM824(x)
        if ((regstr [test ] ) == 28 ) {
          int no ; 
          no = ((int ) (((unsigned char * ) regstr ) [((test ) + 3 ) ] << 8 ) | (((unsigned char * ) regstr ) [((test ) + 3 ) + 1 ] ) ) ; 
          t = (rw -> endp [no ] > - 1 ) ; 
        }
        else {
#         define XfOrM837_COUNT (0+XfOrM836_COUNT)
#         define SETUP_XfOrM837(x) SETUP_XfOrM836(x)
          rw -> input = is ; 
          t = FUNCCALL(SETUP_XfOrM837(_), regmatch (rw , test ) ); 
        }
        if (t )
          scan = scan + ((int ) (((unsigned char * ) regstr ) [((scan ) + 3 ) ] << 8 ) | (((unsigned char * ) regstr ) [((scan ) + 3 ) + 1 ] ) ) ; 
        else scan = scan + ((int ) (((unsigned char * ) regstr ) [((scan ) + 5 ) ] << 8 ) | (((unsigned char * ) regstr ) [((scan ) + 5 ) + 1 ] ) ) ; 
      }
      break ; 
      default : {
        int isopen ; 
        int no ; 
#       define XfOrM825_COUNT (0+XfOrM824_COUNT)
#       define SETUP_XfOrM825(x) SETUP_XfOrM824(x)
        switch (the_op ) {
          case 20 : isopen = 1 ; 
          no = ((int ) (((unsigned char * ) regstr ) [((scan ) + 3 ) ] << 8 ) | (((unsigned char * ) regstr ) [((scan ) + 3 ) + 1 ] ) ) ; 
          if (! no )
            no = - 1 ; 
          break ; 
          case 21 : isopen = 0 ; 
          no = ((int ) (((unsigned char * ) regstr ) [((scan ) + 3 ) ] << 8 ) | (((unsigned char * ) regstr ) [((scan ) + 3 ) + 1 ] ) ) ; 
          if (! no )
            no = - 1 ; 
          break ; 
          default : if (the_op < 77 ) {
            isopen = 1 ; 
            no = the_op - 43 ; 
          }
          else {
            isopen = 0 ; 
            no = the_op - 77 ; 
          }
        }
        if (no < 0 ) {
          scan = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
        }
        else {
          rxpos next ; 
#         define XfOrM826_COUNT (0+XfOrM825_COUNT)
#         define SETUP_XfOrM826(x) SETUP_XfOrM825(x)
          next = (scan + (((((unsigned char * ) regstr ) [(scan ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(scan ) + 2 ] & 255 ) ) ) ; 
          rw -> input = is ; 
          if (isopen ) {
            int oldmaybe ; 
#           define XfOrM830_COUNT (0+XfOrM826_COUNT)
#           define SETUP_XfOrM830(x) SETUP_XfOrM826(x)
            oldmaybe = rw -> maybep [no ] ; 
            rw -> maybep [no ] = is ; 
            if (FUNCCALL(SETUP_XfOrM830(_), regmatch (rw , next ) ))
              RET_VALUE_START ((1 ) ) RET_VALUE_END ; 
            else {
              rw -> maybep [no ] = oldmaybe ; 
              RET_VALUE_START ((0 ) ) RET_VALUE_END ; 
            }
          }
          else {
            int oldstart , oldend ; 
#           define XfOrM827_COUNT (0+XfOrM826_COUNT)
#           define SETUP_XfOrM827(x) SETUP_XfOrM826(x)
            oldstart = rw -> startp [no ] ; 
            oldend = rw -> endp [no ] ; 
            rw -> startp [no ] = rw -> maybep [no ] ; 
            rw -> endp [no ] = is ; 
            if (FUNCCALL(SETUP_XfOrM827(_), regmatch (rw , next ) )) {
              RET_VALUE_START ((1 ) ) RET_VALUE_END ; 
            }
            else {
              rw -> startp [no ] = oldstart ; 
              rw -> endp [no ] = oldend ; 
              RET_VALUE_START ((0 ) ) RET_VALUE_END ; 
            }
          }
        }
      }
      break ; 
    }
  }
  FUNCCALL_EMPTY(regerror ("corrupted pointers" ) ); 
  RET_VALUE_START ((0 ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int regrepeat (Regwork * rw , rxpos p , int maxc ) {
  int count = 0 ; 
  rxpos scan ; 
  rxpos opnd ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(rw, 0)));
# define XfOrM942_COUNT (1)
# define SETUP_XfOrM942(x) SETUP(XfOrM942_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  scan = rw -> input ; 
  opnd = ((p ) + 3 ) ; 
  switch ((regstr [p ] ) ) {
#   define XfOrM943_COUNT (0+XfOrM942_COUNT)
#   define SETUP_XfOrM943(x) SETUP_XfOrM942(x)
    case 3 : if (rw -> port ) {
#     define XfOrM995_COUNT (0+XfOrM943_COUNT)
#     define SETUP_XfOrM995(x) SETUP_XfOrM943(x)
      if (maxc ) {
#       define XfOrM999_COUNT (0+XfOrM995_COUNT)
#       define SETUP_XfOrM999(x) SETUP_XfOrM995(x)
        while (rw -> port && (rw -> input_end < scan + maxc ) ) {
#         define XfOrM1001_COUNT (0+XfOrM999_COUNT)
#         define SETUP_XfOrM1001(x) SETUP_XfOrM999(x)
          FUNCCALL(SETUP_XfOrM1001(_), read_more_from_regport (rw , scan + maxc ) ); 
        }
      }
      else {
#       define XfOrM996_COUNT (0+XfOrM995_COUNT)
#       define SETUP_XfOrM996(x) SETUP_XfOrM995(x)
        while (rw -> port ) {
#         define XfOrM998_COUNT (0+XfOrM996_COUNT)
#         define SETUP_XfOrM998(x) SETUP_XfOrM996(x)
          FUNCCALL(SETUP_XfOrM998(_), read_more_from_regport (rw , rw -> input_end + 4096 ) ); 
        }
      }
    }
    count = rw -> input_end - scan ; 
    if (maxc && (count > maxc ) )
      count = maxc ; 
    scan += count ; 
    break ; 
    case 4 : {
#     define XfOrM990_COUNT (0+XfOrM943_COUNT)
#     define SETUP_XfOrM990(x) SETUP_XfOrM943(x)
      if (rw -> port && (((scan ) + (1 ) ) > rw -> input_end ) )
        FUNCCALL(SETUP_XfOrM990(_), read_more_from_regport (rw , (scan ) + (1 ) ) ); 
      while (scan != rw -> input_end && (rw -> instr [scan ] != '\n' ) ) {
        count ++ ; 
        scan ++ ; 
#       define XfOrM993_COUNT (0+XfOrM990_COUNT)
#       define SETUP_XfOrM993(x) SETUP_XfOrM990(x)
        if (maxc ) {
          maxc -- ; 
          if (! maxc )
            break ; 
        }
        if (rw -> port && (((scan ) + (1 ) ) > rw -> input_end ) )
          FUNCCALL(SETUP_XfOrM993(_), read_more_from_regport (rw , (scan ) + (1 ) ) ); 
      }
    }
    break ; 
    case 11 : {
      rxpos opnd2 = (opnd + 2 ) ; 
#     define XfOrM985_COUNT (0+XfOrM943_COUNT)
#     define SETUP_XfOrM985(x) SETUP_XfOrM943(x)
      if (rw -> port && (((scan ) + (1 ) ) > rw -> input_end ) )
        FUNCCALL(SETUP_XfOrM985(_), read_more_from_regport (rw , (scan ) + (1 ) ) ); 
      while (scan != rw -> input_end && (regstr [opnd2 ] == rw -> instr [scan ] ) ) {
        count ++ ; 
        scan ++ ; 
#       define XfOrM988_COUNT (0+XfOrM985_COUNT)
#       define SETUP_XfOrM988(x) SETUP_XfOrM985(x)
        if (maxc ) {
          maxc -- ; 
          if (! maxc )
            break ; 
        }
        if (rw -> port && (((scan ) + (1 ) ) > rw -> input_end ) )
          FUNCCALL(SETUP_XfOrM988(_), read_more_from_regport (rw , (scan ) + (1 ) ) ); 
      }
    }
    break ; 
    case 12 : {
      char c ; 
      rxpos opnd2 = (opnd + 2 ) ; 
#     define XfOrM980_COUNT (0+XfOrM943_COUNT)
#     define SETUP_XfOrM980(x) SETUP_XfOrM943(x)
      if (rw -> port && (((scan ) + (1 ) ) > rw -> input_end ) )
        FUNCCALL(SETUP_XfOrM980(_), read_more_from_regport (rw , (scan ) + (1 ) ) ); 
      while (scan != rw -> input_end ) {
#       define XfOrM983_COUNT (0+XfOrM980_COUNT)
#       define SETUP_XfOrM983(x) SETUP_XfOrM980(x)
        c = rw -> instr [scan ] ; 
        c = (((c >= 'A' ) && (c <= 'Z' ) ) ? (c + ('a' - 'A' ) ) : c ) ; 
        if (regstr [opnd2 ] != c )
          break ; 
        count ++ ; 
        scan ++ ; 
        if (maxc ) {
          maxc -- ; 
          if (! maxc )
            break ; 
        }
        if (rw -> port && (((scan ) + (1 ) ) > rw -> input_end ) )
          FUNCCALL(SETUP_XfOrM983(_), read_more_from_regport (rw , (scan ) + (1 ) ) ); 
      }
    }
    break ; 
    case 5 : {
      int c ; 
      rxpos init = scan ; 
#     define XfOrM971_COUNT (0+XfOrM943_COUNT)
#     define SETUP_XfOrM971(x) SETUP_XfOrM943(x)
      if (rw -> port || maxc ) {
#       define XfOrM975_COUNT (0+XfOrM971_COUNT)
#       define SETUP_XfOrM975(x) SETUP_XfOrM971(x)
        if (rw -> port && (((scan ) + (1 ) ) > rw -> input_end ) )
          FUNCCALL(SETUP_XfOrM975(_), read_more_from_regport (rw , (scan ) + (1 ) ) ); 
        while (scan != rw -> input_end ) {
#         define XfOrM978_COUNT (0+XfOrM975_COUNT)
#         define SETUP_XfOrM978(x) SETUP_XfOrM975(x)
          c = ((unsigned char ) (rw -> instr [scan ] ) ) ; 
          if (! (regstr [opnd + (c >> 3 ) ] & (1 << (c & 0x7 ) ) ) )
            break ; 
          scan ++ ; 
          if (maxc ) {
            maxc -- ; 
            if (! maxc )
              break ; 
          }
          if (rw -> port && (((scan ) + (1 ) ) > rw -> input_end ) )
            FUNCCALL(SETUP_XfOrM978(_), read_more_from_regport (rw , (scan ) + (1 ) ) ); 
        }
      }
      else {
        int e = rw -> input_end ; 
        while (scan != e ) {
          c = ((unsigned char ) (rw -> instr [scan ] ) ) ; 
          if (! (regstr [opnd + (c >> 3 ) ] & (1 << (c & 0x7 ) ) ) )
            break ; 
          scan ++ ; 
        }
      }
      count = scan - init ; 
    }
    break ; 
    case 6 : {
      rxpos init = scan ; 
      char c ; 
#     define XfOrM962_COUNT (0+XfOrM943_COUNT)
#     define SETUP_XfOrM962(x) SETUP_XfOrM943(x)
      c = regstr [opnd ] ; 
      if (rw -> port || maxc ) {
#       define XfOrM966_COUNT (0+XfOrM962_COUNT)
#       define SETUP_XfOrM966(x) SETUP_XfOrM962(x)
        if (rw -> port && (((scan ) + (1 ) ) > rw -> input_end ) )
          FUNCCALL(SETUP_XfOrM966(_), read_more_from_regport (rw , (scan ) + (1 ) ) ); 
        while ((scan != rw -> input_end ) && (rw -> instr [scan ] == c ) ) {
          scan ++ ; 
#         define XfOrM969_COUNT (0+XfOrM966_COUNT)
#         define SETUP_XfOrM969(x) SETUP_XfOrM966(x)
          if (maxc ) {
            maxc -- ; 
            if (! maxc )
              break ; 
          }
          if (rw -> port && (((scan ) + (1 ) ) > rw -> input_end ) )
            FUNCCALL(SETUP_XfOrM969(_), read_more_from_regport (rw , (scan ) + (1 ) ) ); 
        }
      }
      else {
        int e = rw -> input_end ; 
        while ((scan != e ) && (rw -> instr [scan ] == c ) ) {
          scan ++ ; 
        }
      }
      count = scan - init ; 
    }
    break ; 
    case 7 : {
      rxpos init = scan ; 
      int c , sr , er ; 
#     define XfOrM953_COUNT (0+XfOrM943_COUNT)
#     define SETUP_XfOrM953(x) SETUP_XfOrM943(x)
      if (rw -> port && (((scan ) + (1 ) ) > rw -> input_end ) )
        FUNCCALL(SETUP_XfOrM953(_), read_more_from_regport (rw , (scan ) + (1 ) ) ); 
      sr = ((unsigned char ) (regstr [opnd ] ) ) ; 
      er = ((unsigned char ) (regstr [opnd + 1 ] ) ) ; 
      if (rw -> port || maxc ) {
#       define XfOrM957_COUNT (0+XfOrM953_COUNT)
#       define SETUP_XfOrM957(x) SETUP_XfOrM953(x)
        while (scan != rw -> input_end ) {
#         define XfOrM960_COUNT (0+XfOrM957_COUNT)
#         define SETUP_XfOrM960(x) SETUP_XfOrM957(x)
          c = ((unsigned char ) (rw -> instr [scan ] ) ) ; 
          if ((c < sr ) || (c > er ) )
            break ; 
          scan ++ ; 
          if (maxc ) {
            maxc -- ; 
            if (! maxc )
              break ; 
          }
          if (rw -> port && (((scan ) + (1 ) ) > rw -> input_end ) )
            FUNCCALL(SETUP_XfOrM960(_), read_more_from_regport (rw , (scan ) + (1 ) ) ); 
        }
      }
      else {
        int e = rw -> input_end ; 
        while (scan != e ) {
          c = ((unsigned char ) (rw -> instr [scan ] ) ) ; 
          if ((c < sr ) || (c > er ) )
            break ; 
          scan ++ ; 
        }
      }
      count = scan - init ; 
    }
    break ; 
    case 8 : {
      rxpos init = scan ; 
      int c , sr , er ; 
#     define XfOrM944_COUNT (0+XfOrM943_COUNT)
#     define SETUP_XfOrM944(x) SETUP_XfOrM943(x)
      if (rw -> port && (((scan ) + (1 ) ) > rw -> input_end ) )
        FUNCCALL(SETUP_XfOrM944(_), read_more_from_regport (rw , (scan ) + (1 ) ) ); 
      sr = ((unsigned char ) (regstr [opnd ] ) ) ; 
      er = ((unsigned char ) (regstr [opnd + 1 ] ) ) ; 
      if (rw -> port || maxc ) {
#       define XfOrM948_COUNT (0+XfOrM944_COUNT)
#       define SETUP_XfOrM948(x) SETUP_XfOrM944(x)
        while (scan != rw -> input_end ) {
#         define XfOrM951_COUNT (0+XfOrM948_COUNT)
#         define SETUP_XfOrM951(x) SETUP_XfOrM948(x)
          c = ((unsigned char ) (rw -> instr [scan ] ) ) ; 
          if ((c >= sr ) && (c <= er ) )
            break ; 
          scan ++ ; 
          if (maxc ) {
            maxc -- ; 
            if (! maxc )
              break ; 
          }
          if (rw -> port && (((scan ) + (1 ) ) > rw -> input_end ) )
            FUNCCALL(SETUP_XfOrM951(_), read_more_from_regport (rw , (scan ) + (1 ) ) ); 
        }
      }
      else {
        int e = rw -> input_end ; 
        while (scan != e ) {
          c = ((unsigned char ) (rw -> instr [scan ] ) ) ; 
          if ((c >= sr ) && (c <= er ) )
            break ; 
          scan ++ ; 
        }
      }
      count = scan - init ; 
    }
    break ; 
    default : FUNCCALL(SETUP_XfOrM943(_), regerror ("internal foulup" ) ); 
    count = 0 ; 
    break ; 
  }
  rw -> input = scan ; 
  RET_VALUE_START ((count ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static rxpos regnext (rxpos p ) {
  /* No conversion */
  int offset ; 
  if (p + 2 >= regcodesize )
    return 0 ; 
  offset = (((((unsigned char * ) regstr ) [(p ) + 1 ] & 255 ) << 8 ) + (((unsigned char * ) regstr ) [(p ) + 2 ] & 255 ) ) ; 
  if (offset == 0 )
    return 0 ; 
  if ((regstr [p ] ) == 10 )
    return (p - offset ) ; 
  else return (p + offset ) ; 
}
static int regstrcspn (char * s1 , char * e1 , char * s2 ) {
  /* No conversion */
  char * scan1 ; 
  char * scan2 ; 
  int count ; 
  count = 0 ; 
  for (scan1 = s1 ; scan1 != e1 ; scan1 ++ ) {
    for (scan2 = s2 ; * scan2 != '\0' ; ) {
      if (* scan1 == * scan2 ++ )
        return (count ) ; 
    }
    count ++ ; 
  }
  return (count ) ; 
}
extern char * strncpy () ; 
static char * regsub (regexp * prog , char * src , int sourcelen , long * lenout , char * insrc , rxpos * startp , rxpos * endp ) {
  char * dest ; 
  char c ; 
  long no ; 
  long len ; 
  long destalloc , destlen , srcpos ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(startp, 0), PUSH(lenout, 1), PUSH(src, 2), PUSH(prog, 3), PUSH(insrc, 4), PUSH(dest, 5), PUSH(endp, 6)));
# define XfOrM1010_COUNT (7)
# define SETUP_XfOrM1010(x) SETUP(XfOrM1010_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  dest = NULLED_OUT ; 
  destalloc = 2 * sourcelen ; 
  destlen = 0 ; 
  dest = (char * ) FUNCCALL(SETUP_XfOrM1010(_), GC_malloc_atomic (destalloc + 1 ) ); 
  srcpos = 0 ; 
  while (srcpos < sourcelen ) {
#   define XfOrM1022_COUNT (0+XfOrM1010_COUNT)
#   define SETUP_XfOrM1022(x) SETUP_XfOrM1010(x)
    c = src [srcpos ++ ] ; 
    if (c == '&' )
      no = 0 ; 
    else if (c == '\\' ) {
      if (src [srcpos ] == '\\' || src [srcpos ] == '&' )
        no = - 1 ; 
      else if (src [srcpos ] == '$' ) {
        no = prog -> nsubexp + 1 ; 
        srcpos ++ ; 
      }
      else {
        no = 0 ; 
        while ('0' <= src [srcpos ] && src [srcpos ] <= '9' ) {
          no = (no * 10 ) + (src [srcpos ++ ] - '0' ) ; 
        }
      }
    }
    else no = - 1 ; 
    if (no < 0 ) {
#     define XfOrM1026_COUNT (0+XfOrM1022_COUNT)
#     define SETUP_XfOrM1026(x) SETUP_XfOrM1022(x)
      if (c == '\\' && (src [srcpos ] == '\\' || src [srcpos ] == '&' ) )
        c = src [srcpos ++ ] ; 
      if (destlen + 1 >= destalloc ) {
        char * old = dest ; 
        destalloc *= 2 ; 
        BLOCK_SETUP((PUSH(old, 0+XfOrM1026_COUNT)));
#       define XfOrM1027_COUNT (1+XfOrM1026_COUNT)
#       define SETUP_XfOrM1027(x) SETUP(XfOrM1027_COUNT)
        dest = (char * ) FUNCCALL(SETUP_XfOrM1027(_), GC_malloc_atomic (destalloc + 1 ) ); 
        (memcpy (dest , old , destlen ) ) ; 
      }
      dest [destlen ++ ] = c ; 
    }
    else if (no >= prog -> nsubexp ) {
    }
    else if (startp [no ] != - 1 && endp [no ] != - 1 ) {
#     define XfOrM1023_COUNT (0+XfOrM1022_COUNT)
#     define SETUP_XfOrM1023(x) SETUP_XfOrM1022(x)
      len = endp [no ] - startp [no ] ; 
      if (len + destlen >= destalloc ) {
        char * old = dest ; 
        BLOCK_SETUP((PUSH(old, 0+XfOrM1023_COUNT)));
#       define XfOrM1024_COUNT (1+XfOrM1023_COUNT)
#       define SETUP_XfOrM1024(x) SETUP(XfOrM1024_COUNT)
        destalloc = 2 * destalloc + len + destlen ; 
        dest = (char * ) FUNCCALL(SETUP_XfOrM1024(_), GC_malloc_atomic (destalloc + 1 ) ); 
        (memcpy (dest , old , destlen ) ) ; 
      }
      (memcpy (dest + destlen , insrc + startp [no ] , len ) ) ; 
      destlen += len ; 
    }
  }
  dest [destlen ] = '\0' ; 
  if (lenout )
    * lenout = destlen ; 
  RET_VALUE_START (dest ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int compare_ranges (const void * a , const void * b ) {
  /* No conversion */
  unsigned int av , bv ; 
  av = * (unsigned int * ) a ; 
  bv = * (unsigned int * ) b ; 
  if (av == bv )
    return 0 ; 
  else if (av < bv )
    return - 1 ; 
  else return 1 ; 
}
typedef struct {
  int i ; 
  int orig_len ; 
  int size ; 
}
RoomState ; 
static unsigned char * make_room (unsigned char * r , int j , int need_extra , RoomState * rs ) {
  int nrs ; 
  unsigned char * nr ; 
  DECL_RET_SAVE (unsigned char * ) PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(r, 0), PUSH(rs, 1), PUSH(nr, 2)));
# define XfOrM1034_COUNT (3)
# define SETUP_XfOrM1034(x) SETUP(XfOrM1034_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  nr = NULLED_OUT ; 
  if ((rs -> size - j - (rs -> orig_len - rs -> i ) ) < need_extra ) {
#   define XfOrM1035_COUNT (0+XfOrM1034_COUNT)
#   define SETUP_XfOrM1035(x) SETUP_XfOrM1034(x)
    nrs = ((rs -> size ) * 2 ) + need_extra ; 
    nr = (unsigned char * ) FUNCCALL(SETUP_XfOrM1035(_), GC_malloc_atomic (nrs + 1 ) ); 
    (memcpy (nr , r , j ) ) ; 
    r = nr ; 
    rs -> size = nrs ; 
  }
  RET_VALUE_START (r ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static unsigned char * add_byte_range (const unsigned char * lo , const unsigned char * hi , int count , unsigned char * r , int * _j , RoomState * rs , int did_alt , int wrap_alts ) {
  int same_chars , j , i ; 
  const unsigned char * lowest = (unsigned char * ) "\200\200\200\200\200" ; 
  const unsigned char * highest = (unsigned char * ) "\277\277\277\277\277" ; 
  unsigned char p , q ; 
  DECL_RET_SAVE (unsigned char * ) PREPARE_VAR_STACK(8);
  BLOCK_SETUP_TOP((PUSH(hi, 0), PUSH(r, 1), PUSH(rs, 2), PUSH(highest, 3), PUSH(lowest, 4), PUSH(_j, 5), PUSH(lo, 6)));
# define XfOrM1036_COUNT (7)
# define SETUP_XfOrM1036(x) SETUP(XfOrM1036_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  for (same_chars = 0 ; same_chars < count ; same_chars ++ ) {
    if (lo [same_chars ] != hi [same_chars ] )
      break ; 
  }
  j = * _j ; 
  if (same_chars ) {
#   define XfOrM1057_COUNT (0+XfOrM1036_COUNT)
#   define SETUP_XfOrM1057(x) SETUP_XfOrM1036(x)
    r = FUNCCALL(SETUP_XfOrM1057(_), make_room (r , j , 4 + same_chars , rs ) ); 
    if (! did_alt ) {
      r [j ++ ] = '|' ; 
      did_alt = 1 ; 
    }
    for (i = 0 ; i < same_chars ; i ++ ) {
      r [j ++ ] = lo [i ] ; 
    }
  }
  if (same_chars < count ) {
    int choices = 0 ; 
#   define XfOrM1037_COUNT (0+XfOrM1036_COUNT)
#   define SETUP_XfOrM1037(x) SETUP_XfOrM1036(x)
    for (i = same_chars + 1 ; i < count ; i ++ ) {
      if (lo [i ] != 128 )
        break ; 
    }
    if (i == count )
      p = lo [same_chars ] ; 
    else {
      p = lo [same_chars ] + 1 ; 
      choices ++ ; 
    }
    for (i = same_chars + 1 ; i < count ; i ++ ) {
      if (hi [i ] != 191 )
        break ; 
    }
    if (i == count )
      q = hi [same_chars ] ; 
    else {
      q = hi [same_chars ] - 1 ; 
      choices ++ ; 
    }
    if (p <= q )
      choices ++ ; 
    if ((wrap_alts || same_chars ) && (choices > 1 ) ) {
#     define XfOrM1049_COUNT (0+XfOrM1037_COUNT)
#     define SETUP_XfOrM1049(x) SETUP_XfOrM1037(x)
      r = FUNCCALL(SETUP_XfOrM1049(_), make_room (r , j , 4 , rs ) ); 
      if (! did_alt ) {
        r [j ++ ] = '|' ; 
        did_alt = 1 ; 
      }
      r [j ++ ] = '(' ; 
      r [j ++ ] = '?' ; 
      r [j ++ ] = ':' ; 
    }
    if (p > lo [same_chars ] ) {
#     define XfOrM1047_COUNT (0+XfOrM1037_COUNT)
#     define SETUP_XfOrM1047(x) SETUP_XfOrM1037(x)
      r = FUNCCALL(SETUP_XfOrM1047(_), make_room (r , j , 2 , rs ) ); 
      if (! did_alt ) {
        r [j ++ ] = '|' ; 
        did_alt = 1 ; 
      }
      r [j ++ ] = lo [same_chars ] ; 
      * _j = j ; 
      r = FUNCCALL(SETUP_XfOrM1047(_), add_byte_range (lo XFORM_OK_PLUS same_chars + 1 , highest , count - same_chars - 1 , r , _j , rs , 1 , 1 ) ); 
      j = * _j ; 
      p = lo [same_chars ] + 1 ; 
      did_alt = 0 ; 
    }
    if (q < hi [same_chars ] ) {
#     define XfOrM1045_COUNT (0+XfOrM1037_COUNT)
#     define SETUP_XfOrM1045(x) SETUP_XfOrM1037(x)
      r = FUNCCALL(SETUP_XfOrM1045(_), make_room (r , j , 2 , rs ) ); 
      if (! did_alt ) {
        r [j ++ ] = '|' ; 
        did_alt = 1 ; 
      }
      r [j ++ ] = hi [same_chars ] ; 
      * _j = j ; 
      r = FUNCCALL(SETUP_XfOrM1045(_), add_byte_range (lowest , hi XFORM_OK_PLUS same_chars + 1 , count - same_chars - 1 , r , _j , rs , 1 , 1 ) ); 
      j = * _j ; 
      did_alt = 0 ; 
      q = hi [same_chars ] - 1 ; 
    }
    if (p <= q ) {
      const char * any_str = "[\200-\277]" ; 
      const int any_len = 5 ; 
      BLOCK_SETUP((PUSH(any_str, 0+XfOrM1037_COUNT)));
#     define XfOrM1039_COUNT (1+XfOrM1037_COUNT)
#     define SETUP_XfOrM1039(x) SETUP(XfOrM1039_COUNT)
      r = FUNCCALL(SETUP_XfOrM1039(_), make_room (r , j , 6 + ((count - same_chars - 1 ) * any_len ) , rs ) ); 
      if (! did_alt ) {
        r [j ++ ] = '|' ; 
        did_alt = 1 ; 
      }
      if (p == q ) {
        r [j ++ ] = p ; 
      }
      else {
        r [j ++ ] = '[' ; 
        r [j ++ ] = p ; 
        r [j ++ ] = '-' ; 
        r [j ++ ] = q ; 
        r [j ++ ] = ']' ; 
      }
      for (i = same_chars + 1 ; i < count ; i ++ ) {
#       define XfOrM1041_COUNT (0+XfOrM1039_COUNT)
#       define SETUP_XfOrM1041(x) SETUP_XfOrM1039(x)
        (memcpy (r + j , any_str , any_len ) ) ; 
        j += any_len ; 
      }
    }
    if ((wrap_alts || same_chars ) && (choices > 1 ) ) {
#     define XfOrM1038_COUNT (0+XfOrM1037_COUNT)
#     define SETUP_XfOrM1038(x) SETUP_XfOrM1037(x)
      r = FUNCCALL(SETUP_XfOrM1038(_), make_room (r , j , 1 , rs ) ); 
      r [j ++ ] = ')' ; 
    }
  }
  * _j = j ; 
  RET_VALUE_START (r ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static unsigned char * add_range (unsigned char * r , int * _j , RoomState * rs , unsigned int start , unsigned int end , int did_alt ) {
  unsigned int top ; 
  int count ; 
  unsigned char lo [6 ] , hi [6 ] ; 
  PREPARE_VAR_STACK_ONCE(3);
  BLOCK_SETUP_TOP((PUSH(r, 0), PUSH(rs, 1), PUSH(_j, 2)));
# define XfOrM1063_COUNT (3)
# define SETUP_XfOrM1063(x) SETUP(XfOrM1063_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (start <= 0x7FF ) {
    top = 0x7FF ; 
    count = 2 ; 
  }
  else if (start <= 0xFFFF ) {
    top = 0xFFFF ; 
    count = 3 ; 
  }
  else if (start <= 0x1FFFFF ) {
    top = 0x1FFFFF ; 
    count = 4 ; 
  }
  else if (start <= 0x3FFFFFF ) {
    top = 0x3FFFFFF ; 
    count = 5 ; 
  }
  else {
    top = 0x7FFFFFFF ; 
    count = 6 ; 
  }
  if (end > top ) {
#   define XfOrM1064_COUNT (0+XfOrM1063_COUNT)
#   define SETUP_XfOrM1064(x) SETUP_XfOrM1063(x)
    r = FUNCCALL(SETUP_XfOrM1064(_), add_range (r , _j , rs , top + 1 , end , did_alt ) ); 
    end = top ; 
    did_alt = 0 ; 
  }
  FUNCCALL(SETUP_XfOrM1063(_), scheme_utf8_encode_all (& start , 1 , lo ) ); 
  FUNCCALL(SETUP_XfOrM1063(_), scheme_utf8_encode_all (& end , 1 , hi ) ); 
  RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(add_byte_range (lo , hi , count , r , _j , rs , did_alt , 0 ) )) RET_VALUE_EMPTY_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static int need_ci_alternates (unsigned char * s , int delta , int len ) {
  /* No conversion */
  mzchar us [1 ] , c ; 
  scheme_utf8_decode (s , delta , len , us , 0 , 1 , ((void * ) 0 ) , 0 , 0 ) ; 
  c = us [0 ] ; 
  return ((c != (c + scheme_uchar_ups [(scheme_uchar_cases_table [(c >> 8 ) & 0x1FFF ] [c & 0xFF ] ) ] ) ) || (c != (c + scheme_uchar_downs [(scheme_uchar_cases_table [(c >> 8 ) & 0x1FFF ] [c & 0xFF ] ) ] ) ) || (c != (c + scheme_uchar_folds [(scheme_uchar_cases_table [(c >> 8 ) & 0x1FFF ] [c & 0xFF ] ) ] ) ) || (c != (c + scheme_uchar_titles [(scheme_uchar_cases_table [(c >> 8 ) & 0x1FFF ] [c & 0xFF ] ) ] ) ) ) ; 
}
/* this far 4461 */
/* this far 4461 */
/* this far 4221 */
/* this far 4219 */
/* this far 4461 */
/* this far 4461 */
/* this far 4221 */
/* this far 4219 */
static int translate (unsigned char * s , int len , char * * result , int pcre ) {
  int j , parse_flags = 0x1 | 0x4 ; 
  RoomState rs ; 
  unsigned char * r ; 
  Scheme_Object * parse_params = ((void * ) 0 ) ; 
  Scheme_Object * __funcarg112 = NULLED_OUT ; 
  Scheme_Object * __funcarg111 = NULLED_OUT ; 
  Scheme_Object * __funcarg110 = NULLED_OUT ; 
  Scheme_Object * __funcarg109 = NULLED_OUT ; 
  Scheme_Object * __funcarg108 = NULLED_OUT ; 
  Scheme_Object * __funcarg107 = NULLED_OUT ; 
  Scheme_Object * __funcarg97 = NULLED_OUT ; 
  Scheme_Object * __funcarg96 = NULLED_OUT ; 
  Scheme_Object * __funcarg95 = NULLED_OUT ; 
  Scheme_Object * __funcarg94 = NULLED_OUT ; 
  Scheme_Object * __funcarg93 = NULLED_OUT ; 
  Scheme_Object * __funcarg92 = NULLED_OUT ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK(12);
  BLOCK_SETUP_TOP((PUSH(__funcarg96, 0), PUSH(r, 1), PUSH(__funcarg93, 2), PUSH(result, 3), PUSH(__funcarg111, 4), PUSH(parse_params, 5), PUSH(s, 6), PUSH(__funcarg108, 7)));
# define XfOrM1071_COUNT (8)
# define SETUP_XfOrM1071(x) SETUP(XfOrM1071_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  r = NULLED_OUT ; 
  rs . orig_len = len ; 
  rs . size = len ; 
  r = (unsigned char * ) FUNCCALL(SETUP_XfOrM1071(_), GC_malloc_atomic (rs . size + 1 ) ); 
  for (rs . i = j = 0 ; rs . i < len ; ) {
#   define XfOrM1302_COUNT (0+XfOrM1071_COUNT)
#   define SETUP_XfOrM1302(x) SETUP_XfOrM1071(x)
    if (s [rs . i ] == '[' ) {
      int k = rs . i + 1 , saw_big = 0 ; 
      int not_mode = 0 ; 
#     define XfOrM1357_COUNT (0+XfOrM1302_COUNT)
#     define SETUP_XfOrM1357(x) SETUP_XfOrM1302(x)
      if ((k < len ) && (s [k ] == '^' ) ) {
        not_mode = 1 ; 
        k ++ ; 
      }
      if ((k < len ) && (s [k ] == ']' ) )
        k ++ ; 
      while ((k < len ) && (s [k ] != ']' ) ) {
#       define XfOrM1527_COUNT (0+XfOrM1357_COUNT)
#       define SETUP_XfOrM1527(x) SETUP_XfOrM1357(x)
        if (s [k ] > 127 )
          saw_big = 1 ; 
        else if (pcre && (s [k ] == '\\' ) && (k + 1 < len ) )
          k ++ ; 
        else if (pcre && (s [k ] == '[' ) && (k + 1 < len ) && (s [k + 1 ] == ':' ) && FUNCCALL(SETUP_XfOrM1527(_), is_posix_char_class ((char * ) s , k + 1 , len , ((void * ) 0 ) ) )) {
          while (s [k ] != ']' ) {
            k ++ ; 
          }
        }
        k ++ ; 
      }
      if ((k >= len ) || (! saw_big && ! not_mode ) ) {
        while (rs . i <= k ) {
          r [j ++ ] = s [rs . i ++ ] ; 
        }
      }
      else {
        char * simple_on ; 
        Scheme_Object * ranges ; 
        unsigned int * us , * range_array ; 
        int ulen , on_count , range_len , rp , p ; 
        BLOCK_SETUP((PUSH(ranges, 0+XfOrM1357_COUNT), PUSH(range_array, 1+XfOrM1357_COUNT), PUSH(simple_on, 2+XfOrM1357_COUNT), PUSH(us, 3+XfOrM1357_COUNT)));
#       define XfOrM1358_COUNT (4+XfOrM1357_COUNT)
#       define SETUP_XfOrM1358(x) SETUP(XfOrM1358_COUNT)
        simple_on = NULLED_OUT ; 
        ranges = NULLED_OUT ; 
        us = NULLED_OUT ; 
        range_array = NULLED_OUT ; 
        ulen = FUNCCALL(SETUP_XfOrM1358(_), scheme_utf8_decode (s , rs . i + 1 , k , ((void * ) 0 ) , 0 , - 1 , ((void * ) 0 ) , 0 , 0 ) ); 
        us = (unsigned int * ) FUNCCALL(SETUP_XfOrM1358(_), GC_malloc_atomic (ulen * sizeof (unsigned int ) ) ); 
        FUNCCALL(SETUP_XfOrM1358(_), scheme_utf8_decode (s , rs . i + 1 , k , us , 0 , - 1 , ((void * ) 0 ) , 0 , 0 ) ); 
        simple_on = (char * ) FUNCCALL(SETUP_XfOrM1358(_), GC_malloc_atomic (128 ) ); 
        (memset (simple_on , 0 , 128 ) ) ; 
        ranges = scheme_null ; 
        p = 0 ; 
        if (not_mode )
          p ++ ; 
        if (us [p ] == '-' ) {
          simple_on ['-' ] = 1 ; 
          p ++ ; 
        }
        while (p < ulen ) {
#         define XfOrM1458_COUNT (0+XfOrM1358_COUNT)
#         define SETUP_XfOrM1458(x) SETUP_XfOrM1358(x)
          if (((p + 2 ) < ulen ) && us [p + 1 ] == '-' && (! pcre || ((us [p ] != '\\' ) && (us [p + 2 ] != '\\' ) ) ) ) {
            int beg = us [p ] , end = us [p + 2 ] ; 
#           define XfOrM1479_COUNT (0+XfOrM1458_COUNT)
#           define SETUP_XfOrM1479(x) SETUP_XfOrM1458(x)
            if (end == '-' ) {
#             define XfOrM1517_COUNT (0+XfOrM1479_COUNT)
#             define SETUP_XfOrM1517(x) SETUP_XfOrM1479(x)
              {
#               define XfOrM1518_COUNT (0+XfOrM1517_COUNT)
#               define SETUP_XfOrM1518(x) SETUP_XfOrM1517(x)
                FUNCCALL(SETUP_XfOrM1518(_), regcomperror ("misplaced hypen within square brackets in pattern" ) ); 
                RET_VALUE_START (0 ) RET_VALUE_END ; 
              }
              ; 
            }
            if (end < beg ) {
#             define XfOrM1515_COUNT (0+XfOrM1479_COUNT)
#             define SETUP_XfOrM1515(x) SETUP_XfOrM1479(x)
              {
#               define XfOrM1516_COUNT (0+XfOrM1515_COUNT)
#               define SETUP_XfOrM1516(x) SETUP_XfOrM1515(x)
                FUNCCALL(SETUP_XfOrM1516(_), regcomperror ("invalid range within square brackets in pattern" ) ); 
                RET_VALUE_START (0 ) RET_VALUE_END ; 
              }
              ; 
            }
            if ((beg > 127 ) || (end > 127 ) ) {
#             define XfOrM1483_COUNT (0+XfOrM1479_COUNT)
#             define SETUP_XfOrM1483(x) SETUP_XfOrM1479(x)
              ranges = (__funcarg110 = (__funcarg111 = FUNCCALL(SETUP_XfOrM1483(_), scheme_make_integer_value_from_unsigned (beg ) ), __funcarg112 = FUNCCALL(SETUP_XfOrM1483(_), scheme_make_integer_value_from_unsigned (end ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg111 , __funcarg112 ) )) , FUNCCALL_AGAIN(scheme_make_pair (__funcarg110 , ranges ) )) ; 
              if (! (parse_flags & 0x1 ) ) {
                int c , beg2 , end2 , c2 , mode ; 
#               define XfOrM1484_COUNT (0+XfOrM1483_COUNT)
#               define SETUP_XfOrM1484(x) SETUP_XfOrM1483(x)
                for (mode = 0 ; mode < 4 ; mode ++ ) {
#                 define XfOrM1500_COUNT (0+XfOrM1484_COUNT)
#                 define SETUP_XfOrM1500(x) SETUP_XfOrM1484(x)
                  for (c = beg ; c <= end ; c ++ ) {
#                   define XfOrM1508_COUNT (0+XfOrM1500_COUNT)
#                   define SETUP_XfOrM1508(x) SETUP_XfOrM1500(x)
                    switch (mode ) {
                      case 0 : beg2 = (c + scheme_uchar_folds [(scheme_uchar_cases_table [(c >> 8 ) & 0x1FFF ] [c & 0xFF ] ) ] ) ; 
                      break ; 
                      case 1 : beg2 = (c + scheme_uchar_downs [(scheme_uchar_cases_table [(c >> 8 ) & 0x1FFF ] [c & 0xFF ] ) ] ) ; 
                      break ; 
                      case 2 : beg2 = (c + scheme_uchar_ups [(scheme_uchar_cases_table [(c >> 8 ) & 0x1FFF ] [c & 0xFF ] ) ] ) ; 
                      break ; 
                      case 3 : default : beg2 = (c + scheme_uchar_titles [(scheme_uchar_cases_table [(c >> 8 ) & 0x1FFF ] [c & 0xFF ] ) ] ) ; 
                      break ; 
                    }
                    if (c != beg2 ) {
#                     define XfOrM1509_COUNT (0+XfOrM1508_COUNT)
#                     define SETUP_XfOrM1509(x) SETUP_XfOrM1508(x)
                      end2 = beg2 ; 
                      for (; c <= end ; c ++ ) {
                        switch (mode ) {
                          case 0 : c2 = (c + scheme_uchar_folds [(scheme_uchar_cases_table [(c >> 8 ) & 0x1FFF ] [c & 0xFF ] ) ] ) ; 
                          break ; 
                          case 1 : c2 = (c + scheme_uchar_downs [(scheme_uchar_cases_table [(c >> 8 ) & 0x1FFF ] [c & 0xFF ] ) ] ) ; 
                          break ; 
                          case 2 : c2 = (c + scheme_uchar_ups [(scheme_uchar_cases_table [(c >> 8 ) & 0x1FFF ] [c & 0xFF ] ) ] ) ; 
                          break ; 
                          case 3 : default : c2 = (c + scheme_uchar_titles [(scheme_uchar_cases_table [(c >> 8 ) & 0x1FFF ] [c & 0xFF ] ) ] ) ; 
                          break ; 
                        }
                        if ((c2 == c ) || (c2 != end2 + 1 ) )
                          break ; 
                      }
                      ranges = (__funcarg107 = (__funcarg108 = FUNCCALL(SETUP_XfOrM1509(_), scheme_make_integer_value_from_unsigned (beg2 ) ), __funcarg109 = FUNCCALL(SETUP_XfOrM1509(_), scheme_make_integer_value_from_unsigned (end2 ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg108 , __funcarg109 ) )) , FUNCCALL_AGAIN(scheme_make_pair (__funcarg107 , ranges ) )) ; 
                    }
                  }
                }
              }
            }
            else {
              int w ; 
              for (w = beg ; w <= end ; w ++ ) {
                simple_on [w ] = 1 ; 
              }
            }
            p += 3 ; 
          }
          else if (pcre && (us [p ] == '\\' ) ) {
#           define XfOrM1473_COUNT (0+XfOrM1458_COUNT)
#           define SETUP_XfOrM1473(x) SETUP_XfOrM1458(x)
            if ((p + 1 ) < ulen ) {
              int c = us [p + 1 ] ; 
#             define XfOrM1475_COUNT (0+XfOrM1473_COUNT)
#             define SETUP_XfOrM1475(x) SETUP_XfOrM1473(x)
              if (((c >= 'a' ) && (c <= 'z' ) ) || ((c >= 'A' ) && (c <= 'Z' ) ) ) {
#               define XfOrM1478_COUNT (0+XfOrM1475_COUNT)
#               define SETUP_XfOrM1478(x) SETUP_XfOrM1475(x)
                FUNCCALL(SETUP_XfOrM1478(_), regcharclass (c , simple_on ) ); 
                p += 2 ; 
              }
              else if (c < 128 ) {
                simple_on [c ] = 1 ; 
                p += 2 ; 
              }
              else {
                p ++ ; 
              }
            }
            else {
#             define XfOrM1474_COUNT (0+XfOrM1473_COUNT)
#             define SETUP_XfOrM1474(x) SETUP_XfOrM1473(x)
              FUNCCALL(SETUP_XfOrM1474(_), regcomperror ("trailing \\ in pattern" ) ); 
              RET_VALUE_START (0 ) RET_VALUE_END ; 
            }
            ; 
          }
          else if (us [p ] > 127 ) {
            int c = us [p ] ; 
#           define XfOrM1465_COUNT (0+XfOrM1458_COUNT)
#           define SETUP_XfOrM1465(x) SETUP_XfOrM1458(x)
            ranges = (__funcarg95 = (__funcarg96 = FUNCCALL(SETUP_XfOrM1465(_), scheme_make_integer_value_from_unsigned (c ) ), __funcarg97 = FUNCCALL(SETUP_XfOrM1465(_), scheme_make_integer_value_from_unsigned (c ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg96 , __funcarg97 ) )) , FUNCCALL_AGAIN(scheme_make_pair (__funcarg95 , ranges ) )) ; 
            if (! (parse_flags & 0x1 ) ) {
              int mode , c2 ; 
#             define XfOrM1466_COUNT (0+XfOrM1465_COUNT)
#             define SETUP_XfOrM1466(x) SETUP_XfOrM1465(x)
              for (mode = 0 ; mode < 4 ; mode ++ ) {
#               define XfOrM1470_COUNT (0+XfOrM1466_COUNT)
#               define SETUP_XfOrM1470(x) SETUP_XfOrM1466(x)
                switch (mode ) {
                  case 0 : c2 = (c + scheme_uchar_folds [(scheme_uchar_cases_table [(c >> 8 ) & 0x1FFF ] [c & 0xFF ] ) ] ) ; 
                  break ; 
                  case 1 : c2 = (c + scheme_uchar_downs [(scheme_uchar_cases_table [(c >> 8 ) & 0x1FFF ] [c & 0xFF ] ) ] ) ; 
                  break ; 
                  case 2 : c2 = (c + scheme_uchar_ups [(scheme_uchar_cases_table [(c >> 8 ) & 0x1FFF ] [c & 0xFF ] ) ] ) ; 
                  break ; 
                  case 3 : default : c2 = (c + scheme_uchar_titles [(scheme_uchar_cases_table [(c >> 8 ) & 0x1FFF ] [c & 0xFF ] ) ] ) ; 
                  break ; 
                }
                if (c2 != c ) {
#                 define XfOrM1471_COUNT (0+XfOrM1470_COUNT)
#                 define SETUP_XfOrM1471(x) SETUP_XfOrM1470(x)
                  ranges = (__funcarg92 = (__funcarg93 = FUNCCALL(SETUP_XfOrM1471(_), scheme_make_integer_value_from_unsigned (c2 ) ), __funcarg94 = FUNCCALL(SETUP_XfOrM1471(_), scheme_make_integer_value_from_unsigned (c2 ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg93 , __funcarg94 ) )) , FUNCCALL_AGAIN(scheme_make_pair (__funcarg92 , ranges ) )) ; 
                }
              }
            }
            p ++ ; 
          }
          else if (pcre && (us [p ] == '[' ) && ((p + 1 ) < ulen ) && (us [p + 1 ] == ':' ) && FUNCCALL(SETUP_XfOrM1458(_), is_posix_char_class_in_unicode (us , p + 1 , ulen , simple_on ) )) {
            while (us [p ] != ']' ) {
              p ++ ; 
            }
            p ++ ; 
          }
          else {
#           define XfOrM1459_COUNT (0+XfOrM1458_COUNT)
#           define SETUP_XfOrM1459(x) SETUP_XfOrM1458(x)
            if (((p + 1 ) < ulen ) && (us [p ] == '-' ) ) {
#             define XfOrM1460_COUNT (0+XfOrM1459_COUNT)
#             define SETUP_XfOrM1460(x) SETUP_XfOrM1459(x)
              {
#               define XfOrM1461_COUNT (0+XfOrM1460_COUNT)
#               define SETUP_XfOrM1461(x) SETUP_XfOrM1460(x)
                FUNCCALL(SETUP_XfOrM1461(_), regcomperror ("misplaced hypen within square brackets in pattern" ) ); 
                RET_VALUE_START (0 ) RET_VALUE_END ; 
              }
              ; 
              RET_VALUE_START (0 ) RET_VALUE_END ; 
            }
            simple_on [us [p ] ] = 1 ; 
            p ++ ; 
          }
        }
        range_len = FUNCCALL(SETUP_XfOrM1358(_), scheme_list_length (ranges ) ); 
        range_array = (unsigned int * ) FUNCCALL(SETUP_XfOrM1358(_), GC_malloc_atomic (2 * range_len * sizeof (unsigned int ) ) ); 
        for (rp = 0 ; ((Scheme_Type ) (((((long ) (ranges ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (ranges ) ) -> type ) ) == (Scheme_Type ) (scheme_pair_type ) ) ; ranges = (((Scheme_Simple_Object * ) (ranges ) ) -> u . pair_val . cdr ) , rp += 2 ) {
          unsigned long hi , lo ; 
#         define XfOrM1396_COUNT (0+XfOrM1358_COUNT)
#         define SETUP_XfOrM1396(x) SETUP_XfOrM1358(x)
          (scheme_get_unsigned_int_val (((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (ranges ) ) -> u . pair_val . car ) ) ) -> u . pair_val . car ) ) , & lo ) ) ; 
          (scheme_get_unsigned_int_val ((((Scheme_Simple_Object * ) ((((Scheme_Simple_Object * ) (ranges ) ) -> u . pair_val . car ) ) ) -> u . pair_val . cdr ) , & hi ) ) ; 
          range_array [rp ] = (unsigned int ) lo ; 
          range_array [rp + 1 ] = (unsigned int ) hi ; 
        }
        range_len *= 2 ; 
        FUNCCALL(SETUP_XfOrM1358(_), qsort (range_array , range_len >> 1 , 2 * sizeof (unsigned int ) , compare_ranges ) ); 
        for (rp = 0 ; rp < range_len ; rp += 2 ) {
          if (range_array [rp ] < 128 ) {
            for (p = range_array [rp ] ; p < 128 ; p ++ ) {
              simple_on [p ] = 1 ; 
            }
            range_array [rp ] = 128 ; 
          }
        }
        if (! (parse_flags & 0x1 ) ) {
          for (p = 'a' ; p <= 'z' ; p ++ ) {
            if (simple_on [p ] )
              simple_on [(((p >= 'a' ) && (p <= 'z' ) ) ? (p - ('a' - 'A' ) ) : p ) ] = 1 ; 
            if (simple_on [(((p >= 'a' ) && (p <= 'z' ) ) ? (p - ('a' - 'A' ) ) : p ) ] )
              simple_on [p ] = 1 ; 
          }
        }
        on_count = 0 ; 
        for (p = 0 ; p < 128 ; p ++ ) {
          if (simple_on [p ] )
            on_count ++ ; 
        }
        if (not_mode ) {
          unsigned int last_end ; 
          int did_alt ; 
#         define XfOrM1368_COUNT (0+XfOrM1358_COUNT)
#         define SETUP_XfOrM1368(x) SETUP_XfOrM1358(x)
          r = FUNCCALL(SETUP_XfOrM1368(_), make_room (r , j , 6 + (128 - on_count ) + ((pcre && ! simple_on ['\\' ] ) ? 1 : 0 ) , & rs ) ); 
          r [j ++ ] = '(' ; 
          r [j ++ ] = '?' ; 
          r [j ++ ] = ':' ; 
          if (on_count < 128 ) {
            if (! on_count ) {
              r [j ++ ] = '[' ; 
              r [j ++ ] = 0 ; 
              r [j ++ ] = '-' ; 
              r [j ++ ] = 127 ; 
              r [j ++ ] = ']' ; 
            }
            else {
              r [j ++ ] = '[' ; 
              if (! simple_on [']' ] )
                r [j ++ ] = ']' ; 
              for (p = 0 ; p < 128 ; p ++ ) {
                if ((p != '-' ) && (p != ']' ) && (! pcre || (p != '\\' ) ) )
                  if (! simple_on [p ] )
                  r [j ++ ] = p ; 
              }
              if (pcre && ! simple_on ['\\' ] ) {
                r [j ++ ] = '\\' ; 
                r [j ++ ] = '\\' ; 
              }
              if (! simple_on ['-' ] )
                r [j ++ ] = '-' ; 
              r [j ++ ] = ']' ; 
            }
            did_alt = 0 ; 
          }
          else did_alt = 1 ; 
          last_end = 128 ; 
          for (rp = 0 ; rp < range_len ; rp += 2 ) {
#           define XfOrM1374_COUNT (0+XfOrM1368_COUNT)
#           define SETUP_XfOrM1374(x) SETUP_XfOrM1368(x)
            if (range_array [rp ] > last_end ) {
#             define XfOrM1375_COUNT (0+XfOrM1374_COUNT)
#             define SETUP_XfOrM1375(x) SETUP_XfOrM1374(x)
              r = FUNCCALL(SETUP_XfOrM1375(_), add_range (r , & j , & rs , last_end , range_array [rp ] - 1 , did_alt ) ); 
              did_alt = 0 ; 
            }
            if ((range_array [rp + 1 ] + 1 ) > last_end )
              last_end = range_array [rp + 1 ] + 1 ; 
          }
          if (last_end <= 0x10FFFF ) {
#           define XfOrM1369_COUNT (0+XfOrM1368_COUNT)
#           define SETUP_XfOrM1369(x) SETUP_XfOrM1368(x)
            if (last_end < 0xD800 ) {
#             define XfOrM1371_COUNT (0+XfOrM1369_COUNT)
#             define SETUP_XfOrM1371(x) SETUP_XfOrM1369(x)
              r = FUNCCALL(SETUP_XfOrM1371(_), add_range (r , & j , & rs , last_end , 0xD7FF , did_alt ) ); 
              did_alt = 0 ; 
              r = FUNCCALL(SETUP_XfOrM1371(_), add_range (r , & j , & rs , 0xE000 , 0x10FFFF , did_alt ) ); 
            }
            else {
#             define XfOrM1370_COUNT (0+XfOrM1369_COUNT)
#             define SETUP_XfOrM1370(x) SETUP_XfOrM1369(x)
              r = FUNCCALL(SETUP_XfOrM1370(_), add_range (r , & j , & rs , last_end , 0x10FFFF , did_alt ) ); 
              did_alt = 0 ; 
            }
          }
          r = FUNCCALL(SETUP_XfOrM1368(_), make_room (r , j , 1 , & rs ) ); 
          r [j ++ ] = ')' ; 
        }
        else {
          int p , did_alt ; 
#         define XfOrM1359_COUNT (0+XfOrM1358_COUNT)
#         define SETUP_XfOrM1359(x) SETUP_XfOrM1358(x)
          r = FUNCCALL(SETUP_XfOrM1359(_), make_room (r , j , 5 + on_count + ((pcre && simple_on ['\\' ] ) ? 1 : 0 ) , & rs ) ); 
          r [j ++ ] = '(' ; 
          r [j ++ ] = '?' ; 
          r [j ++ ] = ':' ; 
          if (on_count ) {
            if (on_count == 128 ) {
              r [j ++ ] = '[' ; 
              r [j ++ ] = 0 ; 
              r [j ++ ] = '-' ; 
              r [j ++ ] = 127 ; 
              r [j ++ ] = ']' ; 
            }
            else {
              r [j ++ ] = '[' ; 
              if (simple_on [']' ] )
                r [j ++ ] = ']' ; 
              for (p = 0 ; p < 128 ; p ++ ) {
                if ((p != '-' ) && (p != ']' ) && (! pcre || (p != '\\' ) ) )
                  if (simple_on [p ] )
                  r [j ++ ] = p ; 
              }
              if (pcre && simple_on ['\\' ] ) {
                r [j ++ ] = '\\' ; 
                r [j ++ ] = '\\' ; 
              }
              if (simple_on ['-' ] )
                r [j ++ ] = '-' ; 
              r [j ++ ] = ']' ; 
            }
            did_alt = 0 ; 
          }
          else did_alt = 1 ; 
          for (rp = 0 ; rp < range_len ; rp += 2 ) {
#           define XfOrM1361_COUNT (0+XfOrM1359_COUNT)
#           define SETUP_XfOrM1361(x) SETUP_XfOrM1359(x)
            r = FUNCCALL(SETUP_XfOrM1361(_), add_range (r , & j , & rs , range_array [rp ] , range_array [rp + 1 ] , did_alt ) ); 
            did_alt = 0 ; 
          }
          r = FUNCCALL(SETUP_XfOrM1359(_), make_room (r , j , 1 , & rs ) ); 
          r [j ++ ] = ')' ; 
        }
      }
      rs . i = k + 1 ; 
    }
    else if (s [rs . i ] == '\\' ) {
      r [j ++ ] = s [rs . i ++ ] ; 
      if ((rs . i < len ) && (s [rs . i ] > 127 ) ) {
        r [j ++ ] = s [rs . i ++ ] ; 
        while ((rs . i < len ) && ((s [rs . i ] & 0xC0 ) == 0x80 ) ) {
          r [j ++ ] = s [rs . i ++ ] ; 
        }
      }
      else r [j ++ ] = s [rs . i ++ ] ; 
    }
    else if ((s [rs . i ] == '.' ) && (! pcre || (rs . i < 3 ) || (s [rs . i - 1 ] != '{' ) || ((s [rs . i - 2 ] == 'p' ) && (s [rs . i - 2 ] == 'P' ) ) || (s [rs . i - 3 ] != '\\' ) ) ) {
#     define XfOrM1351_COUNT (0+XfOrM1302_COUNT)
#     define SETUP_XfOrM1351(x) SETUP_XfOrM1302(x)
      r = FUNCCALL(SETUP_XfOrM1351(_), make_room (r , j , (parse_flags & 0x4 ) ? 9 : 8 , & rs ) ); 
      r [j ++ ] = '(' ; 
      r [j ++ ] = '?' ; 
      r [j ++ ] = ':' ; 
      r [j ++ ] = '[' ; 
      r [j ++ ] = '\00' ; 
      r [j ++ ] = '-' ; 
      if (! (parse_flags & 0x4 ) ) {
        r [j ++ ] = '\n' - 1 ; 
        r [j ++ ] = '\n' + 1 ; 
        r [j ++ ] = '-' ; 
      }
      r [j ++ ] = '\177' ; 
      r [j ++ ] = ']' ; 
      r = FUNCCALL(SETUP_XfOrM1351(_), add_range (r , & j , & rs , 128 , 0xD7FF , 0 ) ); 
      r = FUNCCALL_AGAIN(add_range (r , & j , & rs , 0xE000 , 0x10FFFF , 0 ) ); 
      r = FUNCCALL_AGAIN(make_room (r , j , 1 , & rs ) ); 
      r [j ++ ] = ')' ; 
      rs . i ++ ; 
    }
    else if (s [rs . i ] > 127 ) {
      int k = rs . i + 1 ; 
#     define XfOrM1327_COUNT (0+XfOrM1302_COUNT)
#     define SETUP_XfOrM1327(x) SETUP_XfOrM1302(x)
      while ((k < len ) && ((s [k ] & 0xC0 ) == 0x80 ) ) {
        k ++ ; 
      }
      if ((k < len ) && ((s [k ] == '+' ) || (s [k ] == '*' ) || (s [k ] == '?' ) || (! (parse_flags & 0x1 ) && FUNCCALL(SETUP_XfOrM1327(_), need_ci_alternates (s , rs . i , k ) )) ) ) {
        int orig_i ; 
#       define XfOrM1331_COUNT (0+XfOrM1327_COUNT)
#       define SETUP_XfOrM1331(x) SETUP_XfOrM1327(x)
        r = FUNCCALL(SETUP_XfOrM1331(_), make_room (r , j , 4 , & rs ) ); 
        r [j ++ ] = '(' ; 
        r [j ++ ] = '?' ; 
        r [j ++ ] = ':' ; 
        orig_i = rs . i ; 
        while (rs . i < k ) {
          r [j ++ ] = s [rs . i ++ ] ; 
        }
        if (! (parse_flags & 0x1 ) ) {
          mzchar us [1 ] , c0 , c1 , wrote [4 ] ; 
          int clen , ci , num_wrote = 1 , mode ; 
          unsigned char s2 [6 ] ; 
#         define XfOrM1332_COUNT (0+XfOrM1331_COUNT)
#         define SETUP_XfOrM1332(x) SETUP_XfOrM1331(x)
          FUNCCALL(SETUP_XfOrM1332(_), scheme_utf8_decode (s , orig_i , k , us , 0 , 1 , ((void * ) 0 ) , 0 , 0 ) ); 
          c0 = us [0 ] ; 
          wrote [0 ] = c0 ; 
          for (mode = 0 ; mode < 4 ; mode ++ ) {
#           define XfOrM1340_COUNT (0+XfOrM1332_COUNT)
#           define SETUP_XfOrM1340(x) SETUP_XfOrM1332(x)
            switch (mode ) {
              case 0 : c1 = (c0 + scheme_uchar_folds [(scheme_uchar_cases_table [(c0 >> 8 ) & 0x1FFF ] [c0 & 0xFF ] ) ] ) ; 
              break ; 
              case 1 : c1 = (c0 + scheme_uchar_downs [(scheme_uchar_cases_table [(c0 >> 8 ) & 0x1FFF ] [c0 & 0xFF ] ) ] ) ; 
              break ; 
              case 2 : c1 = (c0 + scheme_uchar_ups [(scheme_uchar_cases_table [(c0 >> 8 ) & 0x1FFF ] [c0 & 0xFF ] ) ] ) ; 
              break ; 
              case 3 : default : c1 = (c0 + scheme_uchar_titles [(scheme_uchar_cases_table [(c0 >> 8 ) & 0x1FFF ] [c0 & 0xFF ] ) ] ) ; 
              break ; 
            }
            for (ci = 0 ; ci < num_wrote ; ci ++ ) {
              if (c1 == wrote [ci ] )
                break ; 
            }
            if (ci >= num_wrote ) {
#             define XfOrM1341_COUNT (0+XfOrM1340_COUNT)
#             define SETUP_XfOrM1341(x) SETUP_XfOrM1340(x)
              wrote [num_wrote ++ ] = c1 ; 
              us [0 ] = c1 ; 
              clen = FUNCCALL(SETUP_XfOrM1341(_), scheme_utf8_encode (us , 0 , 1 , s2 , 0 , 0 ) ); 
              r = FUNCCALL_AGAIN(make_room (r , j , clen + 1 , & rs ) ); 
              r [j ++ ] = '|' ; 
              for (ci = 0 ; ci < clen ; ci ++ ) {
                r [j ++ ] = s2 [ci ] ; 
              }
            }
          }
        }
        r [j ++ ] = ')' ; 
      }
      else {
        while (rs . i < k ) {
          r [j ++ ] = s [rs . i ++ ] ; 
        }
      }
    }
    else {
#     define XfOrM1303_COUNT (0+XfOrM1302_COUNT)
#     define SETUP_XfOrM1303(x) SETUP_XfOrM1302(x)
      if (s [rs . i ] == '(' ) {
        int old_flags = parse_flags ; 
#       define XfOrM1306_COUNT (0+XfOrM1303_COUNT)
#       define SETUP_XfOrM1306(x) SETUP_XfOrM1303(x)
        if ((rs . i + 1 < len ) && (s [rs . i + 1 ] == '?' ) ) {
          int k ; 
          for (k = rs . i + 2 ; k < len ; k ++ ) {
            if ((s [k ] == ':' ) || (s [k ] == '<' ) || (s [k ] == '>' ) || (s [k ] == '=' ) || (s [k ] == '!' ) )
              break ; 
            if (s [k ] == 'i' ) {
              parse_flags &= ~ 0x1 ; 
            }
            else if (s [k ] == 's' ) {
              parse_flags |= 0x4 ; 
            }
            else if (s [k ] == 'm' ) {
              parse_flags &= ~ 0x4 ; 
            }
            else if (s [k ] == '-' ) {
              if (k + 1 < len ) {
                k ++ ; 
                if (s [k ] == 'i' ) {
                  parse_flags |= 0x1 ; 
                }
                else if (s [k ] == 's' ) {
                  parse_flags &= ~ 0x4 ; 
                }
                else if (s [k ] == 'm' ) {
                  parse_flags |= 0x4 ; 
                }
              }
            }
          }
        }
        if (parse_params || (parse_flags != old_flags ) ) {
#         define XfOrM1307_COUNT (0+XfOrM1306_COUNT)
#         define SETUP_XfOrM1307(x) SETUP_XfOrM1306(x)
          parse_params = FUNCCALL(SETUP_XfOrM1307(_), scheme_make_raw_pair (((Scheme_Object * ) (void * ) (long ) ((((long ) (old_flags ) ) << 1 ) | 0x1 ) ) , parse_params ) ); 
        }
      }
      else if (s [rs . i ] == ')' ) {
        if (parse_params ) {
          parse_flags = (((long ) ((((Scheme_Simple_Object * ) (parse_params ) ) -> u . pair_val . car ) ) ) >> 1 ) ; 
          parse_params = (((Scheme_Simple_Object * ) (parse_params ) ) -> u . pair_val . cdr ) ; 
        }
      }
      r [j ++ ] = s [rs . i ++ ] ; 
    }
  }
  r [j ] = 0 ; 
  * result = (char * ) r ; 
  RET_VALUE_START (j ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int scheme_is_pregexp (Scheme_Object * o ) {
  /* No conversion */
  return ! ! (((regexp * ) o ) -> flags & 0x02 ) ; 
}
static Scheme_Object * do_make_regexp (const char * who , int is_byte , int pcre , int argc , Scheme_Object * argv [] ) {
  Scheme_Object * re , * bs ; 
  char * s ; 
  int slen ; 
  Scheme_Config * __funcarg113 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(6);
  BLOCK_SETUP_TOP((PUSH(bs, 0), PUSH(re, 1), PUSH(s, 2), PUSH(argv, 3), PUSH(who, 4)));
# define XfOrM1533_COUNT (5)
# define SETUP_XfOrM1533(x) SETUP(XfOrM1533_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  re = NULLED_OUT ; 
  bs = NULLED_OUT ; 
  s = NULLED_OUT ; 
  if (is_byte ) {
#   define XfOrM1539_COUNT (0+XfOrM1533_COUNT)
#   define SETUP_XfOrM1539(x) SETUP_XfOrM1533(x)
    if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
      FUNCCALL(SETUP_XfOrM1539(_), scheme_wrong_type (who , "byte string" , 0 , argc , argv ) ); 
    bs = argv [0 ] ; 
  }
  else {
#   define XfOrM1538_COUNT (0+XfOrM1533_COUNT)
#   define SETUP_XfOrM1538(x) SETUP_XfOrM1533(x)
    if (! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
      FUNCCALL(SETUP_XfOrM1538(_), scheme_wrong_type (who , "string" , 0 , argc , argv ) ); 
    bs = FUNCCALL(SETUP_XfOrM1538(_), scheme_char_string_to_byte_string (argv [0 ] ) ); 
  }
  s = (((Scheme_Simple_Object * ) (bs ) ) -> u . byte_str_val . string_val ) ; 
  slen = (((Scheme_Simple_Object * ) (bs ) ) -> u . byte_str_val . tag_val ) ; 
  if (! is_byte ) {
#   define XfOrM1537_COUNT (0+XfOrM1533_COUNT)
#   define SETUP_XfOrM1537(x) SETUP_XfOrM1533(x)
    slen = FUNCCALL(SETUP_XfOrM1537(_), translate ((unsigned char * ) s , slen , & s , pcre ) ); 
  }
  re = (Scheme_Object * ) FUNCCALL(SETUP_XfOrM1533(_), regcomp (s , 0 , slen , pcre ) ); 
  if (! is_byte )
    ((regexp * ) re ) -> flags |= 0x01 ; 
  if (pcre )
    ((regexp * ) re ) -> flags |= 0x02 ; 
  if ((((Scheme_Inclhash_Object * ) (argv [0 ] ) ) -> so . keyex & 0x1 ) )
    ((regexp * ) re ) -> source = argv [0 ] ; 
  else if (is_byte ) {
    Scheme_Object * src ; 
    BLOCK_SETUP((PUSH(src, 0+XfOrM1533_COUNT)));
#   define XfOrM1536_COUNT (1+XfOrM1533_COUNT)
#   define SETUP_XfOrM1536(x) SETUP(XfOrM1536_COUNT)
    src = NULLED_OUT ; 
    src = FUNCCALL(SETUP_XfOrM1536(_), scheme_make_immutable_sized_byte_string ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . string_val ) , (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . byte_str_val . tag_val ) , 1 ) ); 
    ((regexp * ) re ) -> source = src ; 
  }
  else {
    Scheme_Object * src ; 
    BLOCK_SETUP((PUSH(src, 0+XfOrM1533_COUNT)));
#   define XfOrM1535_COUNT (1+XfOrM1533_COUNT)
#   define SETUP_XfOrM1535(x) SETUP(XfOrM1535_COUNT)
    src = NULLED_OUT ; 
    src = FUNCCALL(SETUP_XfOrM1535(_), scheme_make_immutable_sized_char_string ((((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . string_val ) , (((Scheme_Simple_Object * ) (argv [0 ] ) ) -> u . char_str_val . tag_val ) , 1 ) ); 
    ((regexp * ) re ) -> source = src ; 
  }
  {
    Scheme_Object * b ; 
    BLOCK_SETUP((PUSH(b, 0+XfOrM1533_COUNT)));
#   define XfOrM1534_COUNT (1+XfOrM1533_COUNT)
#   define SETUP_XfOrM1534(x) SETUP(XfOrM1534_COUNT)
    b = NULLED_OUT ; 
    b = (__funcarg113 = FUNCCALL(SETUP_XfOrM1534(_), scheme_current_config () ), FUNCCALL_AGAIN(scheme_get_param (__funcarg113 , MZCONFIG_USE_JIT ) )) ; 
    if ((! (((b ) ) == (scheme_false ) ) ) )
      ((regexp * ) re ) -> flags |= 0x10 ; 
  }
  RET_VALUE_START (re ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * make_regexp (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_make_regexp ("byte-regexp" , 1 , 0 , argc , argv ) ; 
}
static Scheme_Object * make_utf8_regexp (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_make_regexp ("regexp" , 0 , 0 , argc , argv ) ; 
}
static Scheme_Object * make_pregexp (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_make_regexp ("byte-pregexp" , 1 , 1 , argc , argv ) ; 
}
static Scheme_Object * make_utf8_pregexp (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return do_make_regexp ("pregexp" , 0 , 1 , argc , argv ) ; 
}
Scheme_Object * scheme_make_regexp (Scheme_Object * str , int is_byte , int pcre , int * volatile result_is_err_string ) {
  mz_jmp_buf * volatile save , newbuf ; 
  Scheme_Object * volatile result ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(save, 0), PUSH(str, 1), PUSH(result, 2), PUSH(result_is_err_string, 3)));
# define XfOrM1544_COUNT (4)
# define SETUP_XfOrM1544(x) SETUP(XfOrM1544_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  save = NULLED_OUT ; 
  result = NULLED_OUT ; 
  * result_is_err_string = 0 ; 
  save = scheme_current_thread -> error_buf ; 
  scheme_current_thread -> error_buf = & newbuf ; 
  failure_msg_for_read = "yes" ; 
  if (! ((newbuf ) . gcvs = (long ) __gc_var_stack__ , (newbuf ) . gcvs_cnt = (long ) (__gc_var_stack__ [1 ] ) , (scheme_jit_setjmp_prepare ((newbuf ) . jb ) , (_setjmp (((newbuf ) . jb ) -> jb ) ) ) ) ) {
#   define XfOrM1546_COUNT (0+XfOrM1544_COUNT)
#   define SETUP_XfOrM1546(x) SETUP_XfOrM1544(x)
    if (is_byte ) {
#     define XfOrM1548_COUNT (0+XfOrM1546_COUNT)
#     define SETUP_XfOrM1548(x) SETUP_XfOrM1546(x)
      if (pcre )
        result = FUNCCALL(SETUP_XfOrM1548(_), make_pregexp (1 , & str ) ); 
      else result = FUNCCALL(SETUP_XfOrM1548(_), make_regexp (1 , & str ) ); 
    }
    else {
#     define XfOrM1547_COUNT (0+XfOrM1546_COUNT)
#     define SETUP_XfOrM1547(x) SETUP_XfOrM1546(x)
      if (pcre )
        result = FUNCCALL(SETUP_XfOrM1547(_), make_utf8_pregexp (1 , & str ) ); 
      else result = FUNCCALL(SETUP_XfOrM1547(_), make_utf8_regexp (1 , & str ) ); 
    }
  }
  else {
    result = (Scheme_Object * ) failure_msg_for_read ; 
    * result_is_err_string = 1 ; 
  }
  failure_msg_for_read = ((void * ) 0 ) ; 
  scheme_current_thread -> error_buf = save ; 
  RET_VALUE_START (result ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static regexp * regcomp_object (Scheme_Object * str ) {
  DECL_RET_SAVE (regexp * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(str, 0)));
# define XfOrM1549_COUNT (1)
# define SETUP_XfOrM1549(x) SETUP(XfOrM1549_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (((Scheme_Type ) (((((long ) (str ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (str ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
    RET_VALUE_START ((regexp * ) FUNCCALL(SETUP_XfOrM1549(_), make_regexp (1 , & str ) )) RET_VALUE_END ; 
  else RET_VALUE_START ((regexp * ) FUNCCALL(SETUP_XfOrM1549(_), make_utf8_regexp (1 , & str ) )) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
long rx_buffer_size ; 
rxpos * startp_buffer , * endp_buffer , * maybep_buffer ; 
void scheme_clear_rx_buffers (void ) {
  /* No conversion */
  startp_buffer = ((void * ) 0 ) ; 
  endp_buffer = ((void * ) 0 ) ; 
  maybep_buffer = ((void * ) 0 ) ; 
}
static Scheme_Object * gen_compare (char * name , int pos , int argc , Scheme_Object * argv [] , int peek , int nonblock ) {
  regexp * r ; 
  char * full_s ; 
  rxpos * startp , * maybep , * endp ; 
  int offset = 0 , orig_offset , endset , m , was_non_byte ; 
  Scheme_Object * iport , * oport = ((void * ) 0 ) , * startv = ((void * ) 0 ) , * endv = ((void * ) 0 ) , * dropped , * unless_evt = ((void * ) 0 ) ; 
  Scheme_Object * __funcarg115 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(17);
  BLOCK_SETUP_TOP((PUSH(full_s, 0), PUSH(r, 1), PUSH(unless_evt, 2), PUSH(dropped, 3), PUSH(maybep, 4), PUSH(endv, 5), PUSH(startv, 6), PUSH(name, 7), PUSH(startp, 8), PUSH(iport, 9), PUSH(endp, 10), PUSH(oport, 11), PUSH(argv, 12)));
# define XfOrM1551_COUNT (13)
# define SETUP_XfOrM1551(x) SETUP(XfOrM1551_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  r = NULLED_OUT ; 
  full_s = NULLED_OUT ; 
  startp = NULLED_OUT ; 
  maybep = NULLED_OUT ; 
  endp = NULLED_OUT ; 
  iport = NULLED_OUT ; 
  dropped = NULLED_OUT ; 
  if (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) != scheme_regexp_type && ! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) && ! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL(SETUP_XfOrM1551(_), scheme_wrong_type (name , "regexp, byte-regexp, string, or byte string" , 0 , argc , argv ) ); 
  if ((peek || (! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) && ! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) ) ) && ! (scheme_is_input_port (argv [1 ] ) ) )
    FUNCCALL(SETUP_XfOrM1551(_), scheme_wrong_type (name , peek ? "input-port" : "string, byte string, or input port" , 1 , argc , argv ) ); 
  if (((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) ) {
    iport = ((void * ) 0 ) ; 
    endset = (((Scheme_Simple_Object * ) (argv [1 ] ) ) -> u . char_str_val . tag_val ) ; 
  }
  else if ((scheme_is_input_port (argv [1 ] ) ) ) {
    iport = argv [1 ] ; 
    endset = - 2 ; 
  }
  else {
    iport = ((void * ) 0 ) ; 
    endset = (((Scheme_Simple_Object * ) (argv [1 ] ) ) -> u . byte_str_val . tag_val ) ; 
  }
  if (argc > 2 ) {
    int len = endset ; 
#   define XfOrM1581_COUNT (0+XfOrM1551_COUNT)
#   define SETUP_XfOrM1581(x) SETUP_XfOrM1551(x)
    offset = FUNCCALL(SETUP_XfOrM1581(_), scheme_extract_index (name , 2 , argc , argv , len + 1 , 0 ) ); 
    if (! iport && (offset > len ) ) {
#     define XfOrM1597_COUNT (0+XfOrM1581_COUNT)
#     define SETUP_XfOrM1597(x) SETUP_XfOrM1581(x)
      FUNCCALL(SETUP_XfOrM1597(_), scheme_out_of_string_range (name , "offset " , argv [2 ] , argv [1 ] , 0 , len ) ); 
      RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
    }
    else if (offset < 0 ) {
      offset = 0x7FFFFFFF ; 
    }
    startv = argv [2 ] ; 
    if (argc > 3 ) {
#     define XfOrM1582_COUNT (0+XfOrM1581_COUNT)
#     define SETUP_XfOrM1582(x) SETUP_XfOrM1581(x)
      if (! (((argv [3 ] ) ) == (scheme_false ) ) ) {
#       define XfOrM1591_COUNT (0+XfOrM1582_COUNT)
#       define SETUP_XfOrM1591(x) SETUP_XfOrM1582(x)
        endset = FUNCCALL(SETUP_XfOrM1591(_), scheme_extract_index (name , 3 , argc , argv , len + 1 , 1 ) ); 
        if (iport ) {
#         define XfOrM1593_COUNT (0+XfOrM1591_COUNT)
#         define SETUP_XfOrM1593(x) SETUP_XfOrM1591(x)
          if (endset < 0 ) {
            endset = 0x7FFFFFFF ; 
          }
          if (FUNCCALL(SETUP_XfOrM1593(_), scheme_bin_lt (argv [3 ] , argv [2 ] ) )) {
#           define XfOrM1594_COUNT (0+XfOrM1593_COUNT)
#           define SETUP_XfOrM1594(x) SETUP_XfOrM1593(x)
            FUNCCALL(SETUP_XfOrM1594(_), scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: ending index %V is smaller than starting index %V for port" , name , argv [3 ] , argv [2 ] ) ); 
            RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
          }
        }
        else if (endset < offset || endset > len ) {
#         define XfOrM1592_COUNT (0+XfOrM1591_COUNT)
#         define SETUP_XfOrM1592(x) SETUP_XfOrM1591(x)
          FUNCCALL(SETUP_XfOrM1592(_), scheme_out_of_string_range (name , "ending " , argv [3 ] , argv [1 ] , offset , len ) ); 
          RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
        }
        endv = argv [3 ] ; 
      }
      if (argc > 4 ) {
#       define XfOrM1583_COUNT (0+XfOrM1582_COUNT)
#       define SETUP_XfOrM1583(x) SETUP_XfOrM1582(x)
        if (peek ) {
#         define XfOrM1586_COUNT (0+XfOrM1583_COUNT)
#         define SETUP_XfOrM1586(x) SETUP_XfOrM1583(x)
          if (! (((argv [4 ] ) ) == (scheme_false ) ) ) {
#           define XfOrM1587_COUNT (0+XfOrM1586_COUNT)
#           define SETUP_XfOrM1587(x) SETUP_XfOrM1586(x)
            unless_evt = argv [4 ] ; 
            if (! ((Scheme_Type ) (((((long ) (unless_evt ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (unless_evt ) ) -> type ) ) == (Scheme_Type ) (scheme_progress_evt_type ) ) ) {
#             define XfOrM1590_COUNT (0+XfOrM1587_COUNT)
#             define SETUP_XfOrM1590(x) SETUP_XfOrM1587(x)
              FUNCCALL(SETUP_XfOrM1590(_), scheme_wrong_type (name , "progress evt or #f" , 4 , argc , argv ) ); 
              RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
            }
            if (! iport ) {
#             define XfOrM1589_COUNT (0+XfOrM1587_COUNT)
#             define SETUP_XfOrM1589(x) SETUP_XfOrM1587(x)
              FUNCCALL(SETUP_XfOrM1589(_), scheme_arg_mismatch (name , "progress evt cannot be used with string input: " , unless_evt ) ); 
            }
            else if (! ((iport ) == ((((Scheme_Simple_Object * ) (unless_evt ) ) -> u . two_ptr_val . ptr1 ) ) ) ) {
#             define XfOrM1588_COUNT (0+XfOrM1587_COUNT)
#             define SETUP_XfOrM1588(x) SETUP_XfOrM1587(x)
              FUNCCALL(SETUP_XfOrM1588(_), scheme_arg_mismatch (name , "evt is not a progress evt for the given port:" , unless_evt ) ); 
              RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
            }
          }
        }
        else {
#         define XfOrM1584_COUNT (0+XfOrM1583_COUNT)
#         define SETUP_XfOrM1584(x) SETUP_XfOrM1583(x)
          if ((! (((argv [4 ] ) ) == (scheme_false ) ) ) ) {
#           define XfOrM1585_COUNT (0+XfOrM1584_COUNT)
#           define SETUP_XfOrM1585(x) SETUP_XfOrM1584(x)
            if (! (scheme_is_output_port (argv [4 ] ) ) )
              FUNCCALL(SETUP_XfOrM1585(_), scheme_wrong_type (name , "output port or #f" , 4 , argc , argv ) ); 
            oport = argv [4 ] ; 
          }
        }
      }
    }
  }
  if (iport && ! startv )
    startv = ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
  if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    r = FUNCCALL(SETUP_XfOrM1551(_), regcomp_object (argv [0 ] ) ); 
  else r = (regexp * ) argv [0 ] ; 
  was_non_byte = 0 ; 
  orig_offset = 0 ; 
  if (! iport ) {
#   define XfOrM1578_COUNT (0+XfOrM1551_COUNT)
#   define SETUP_XfOrM1578(x) SETUP_XfOrM1551(x)
    if (((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
      full_s = (((Scheme_Simple_Object * ) (argv [1 ] ) ) -> u . byte_str_val . string_val ) ; 
    else {
      int blen ; 
#     define XfOrM1579_COUNT (0+XfOrM1578_COUNT)
#     define SETUP_XfOrM1579(x) SETUP_XfOrM1578(x)
      blen = FUNCCALL(SETUP_XfOrM1579(_), scheme_utf8_encode ((((Scheme_Simple_Object * ) (argv [1 ] ) ) -> u . char_str_val . string_val ) , offset , endset , ((void * ) 0 ) , 0 , 0 ) ); 
      full_s = (char * ) FUNCCALL(SETUP_XfOrM1579(_), GC_malloc_atomic (blen ) ); 
      FUNCCALL(SETUP_XfOrM1579(_), scheme_utf8_encode ((((Scheme_Simple_Object * ) (argv [1 ] ) ) -> u . char_str_val . string_val ) , offset , endset , (unsigned char * ) full_s , 0 , 0 ) ); 
      orig_offset = offset ; 
      offset = 0 ; 
      endset = blen ; 
      if (r -> flags & 0x01 )
        was_non_byte = 1 ; 
      else {
#       define XfOrM1580_COUNT (0+XfOrM1579_COUNT)
#       define SETUP_XfOrM1580(x) SETUP_XfOrM1579(x)
        orig_offset = FUNCCALL(SETUP_XfOrM1580(_), scheme_utf8_encode ((((Scheme_Simple_Object * ) (argv [1 ] ) ) -> u . char_str_val . string_val ) , 0 , orig_offset , ((void * ) 0 ) , 0 , 0 ) ); 
      }
    }
  }
  else full_s = ((void * ) 0 ) ; 
  if (startp_buffer && (r -> nsubexp <= rx_buffer_size ) ) {
    startp = startp_buffer ; 
    maybep = maybep_buffer ; 
    endp = endp_buffer ; 
    startp_buffer = ((void * ) 0 ) ; 
  }
  else {
#   define XfOrM1576_COUNT (0+XfOrM1551_COUNT)
#   define SETUP_XfOrM1576(x) SETUP_XfOrM1551(x)
    startp = ((rxpos * ) FUNCCALL(SETUP_XfOrM1576(_), GC_malloc_atomic (sizeof (rxpos ) * (r -> nsubexp ) ) )) ; 
    maybep = ((void * ) 0 ) ; 
    endp = ((rxpos * ) FUNCCALL(SETUP_XfOrM1576(_), GC_malloc_atomic (sizeof (rxpos ) * (r -> nsubexp ) ) )) ; 
  }
  if ((r -> nsubexp > 1 ) && ! maybep )
    maybep = ((rxpos * ) FUNCCALL(SETUP_XfOrM1551(_), GC_malloc_atomic (sizeof (rxpos ) * (r -> nsubexp ) ) )) ; 
  dropped = ((Scheme_Object * ) (void * ) (long ) ((((long ) (0 ) ) << 1 ) | 0x1 ) ) ; 
  m = FUNCCALL(SETUP_XfOrM1551(_), regexec (name , r , full_s , offset , endset - offset , startp , maybep , endp , iport , unless_evt , nonblock , & full_s , peek , pos , oport , startv , endv , & dropped ) ); 
  if (m ) {
    int i ; 
    Scheme_Object * l = scheme_null , * rs ; 
    BLOCK_SETUP((PUSH(l, 0+XfOrM1551_COUNT), PUSH(rs, 1+XfOrM1551_COUNT)));
#   define XfOrM1555_COUNT (2+XfOrM1551_COUNT)
#   define SETUP_XfOrM1555(x) SETUP(XfOrM1555_COUNT)
    rs = NULLED_OUT ; 
    if (oport && ! iport )
      FUNCCALL(SETUP_XfOrM1555(_), scheme_put_byte_string (name , oport , full_s , 0 , * startp , 0 ) ); 
    if (pos > 1 ) {
      dropped = scheme_true ; 
    }
    else {
#     define XfOrM1556_COUNT (0+XfOrM1555_COUNT)
#     define SETUP_XfOrM1556(x) SETUP_XfOrM1555(x)
      for (i = r -> nsubexp ; i -- ; ) {
#       define XfOrM1566_COUNT (0+XfOrM1556_COUNT)
#       define SETUP_XfOrM1566(x) SETUP_XfOrM1556(x)
        if (startp [i ] != - 1 ) {
#         define XfOrM1567_COUNT (0+XfOrM1566_COUNT)
#         define SETUP_XfOrM1567(x) SETUP_XfOrM1566(x)
          if (pos ) {
            Scheme_Object * startpd , * endpd ; 
            BLOCK_SETUP((PUSH(startpd, 0+XfOrM1567_COUNT), PUSH(endpd, 1+XfOrM1567_COUNT)));
#           define XfOrM1571_COUNT (2+XfOrM1567_COUNT)
#           define SETUP_XfOrM1571(x) SETUP(XfOrM1571_COUNT)
            startpd = NULLED_OUT ; 
            endpd = NULLED_OUT ; 
            if (was_non_byte ) {
              int uspd , uepd ; 
#             define XfOrM1574_COUNT (0+XfOrM1571_COUNT)
#             define SETUP_XfOrM1574(x) SETUP_XfOrM1571(x)
              uspd = FUNCCALL(SETUP_XfOrM1574(_), scheme_utf8_decode ((const unsigned char * ) full_s , offset , startp [i ] , ((void * ) 0 ) , 0 , - 1 , ((void * ) 0 ) , 0 , 0 ) ); 
              uspd += orig_offset ; 
              startpd = ((Scheme_Object * ) (void * ) (long ) ((((long ) (uspd ) ) << 1 ) | 0x1 ) ) ; 
              uepd = FUNCCALL(SETUP_XfOrM1574(_), scheme_utf8_decode ((const unsigned char * ) full_s , startp [i ] , endp [i ] , ((void * ) 0 ) , 0 , - 1 , ((void * ) 0 ) , 0 , 0 ) ); 
              uepd += uspd ; 
              endpd = ((Scheme_Object * ) (void * ) (long ) ((((long ) (uepd ) ) << 1 ) | 0x1 ) ) ; 
            }
            else {
              int v ; 
#             define XfOrM1572_COUNT (0+XfOrM1571_COUNT)
#             define SETUP_XfOrM1572(x) SETUP_XfOrM1571(x)
              v = startp [i ] + orig_offset ; 
              startpd = ((Scheme_Object * ) (void * ) (long ) ((((long ) (v ) ) << 1 ) | 0x1 ) ) ; 
              v = endp [i ] + orig_offset ; 
              endpd = ((Scheme_Object * ) (void * ) (long ) ((((long ) (v ) ) << 1 ) | 0x1 ) ) ; 
              if (iport ) {
#               define XfOrM1573_COUNT (0+XfOrM1572_COUNT)
#               define SETUP_XfOrM1573(x) SETUP_XfOrM1572(x)
                startpd = FUNCCALL(SETUP_XfOrM1573(_), scheme_bin_plus (startpd , dropped ) ); 
                endpd = FUNCCALL(SETUP_XfOrM1573(_), scheme_bin_plus (endpd , dropped ) ); 
              }
            }
            l = (__funcarg115 = FUNCCALL(SETUP_XfOrM1571(_), scheme_make_pair (startpd , endpd ) ), FUNCCALL_AGAIN(scheme_make_pair (__funcarg115 , l ) )) ; 
          }
          else {
            long len ; 
#           define XfOrM1568_COUNT (0+XfOrM1567_COUNT)
#           define SETUP_XfOrM1568(x) SETUP_XfOrM1567(x)
            len = endp [i ] - startp [i ] ; 
            if (was_non_byte ) {
#             define XfOrM1570_COUNT (0+XfOrM1568_COUNT)
#             define SETUP_XfOrM1570(x) SETUP_XfOrM1568(x)
              rs = FUNCCALL(SETUP_XfOrM1570(_), scheme_make_sized_offset_utf8_string (full_s , startp [i ] , len ) ); 
            }
            else {
#             define XfOrM1569_COUNT (0+XfOrM1568_COUNT)
#             define SETUP_XfOrM1569(x) SETUP_XfOrM1568(x)
              rs = FUNCCALL(SETUP_XfOrM1569(_), scheme_make_sized_offset_byte_string (full_s , startp [i ] , len , 1 ) ); 
            }
            l = FUNCCALL(SETUP_XfOrM1568(_), scheme_make_pair (rs , l ) ); 
          }
        }
        else l = FUNCCALL(SETUP_XfOrM1566(_), scheme_make_pair (scheme_false , l ) ); 
      }
      dropped = l ; 
    }
  }
  else {
#   define XfOrM1554_COUNT (0+XfOrM1551_COUNT)
#   define SETUP_XfOrM1554(x) SETUP_XfOrM1551(x)
    if (oport && ! iport )
      FUNCCALL(SETUP_XfOrM1554(_), scheme_put_byte_string (name , oport , full_s , 0 , endset , 0 ) ); 
    dropped = scheme_false ; 
  }
  if (! startp_buffer || (r -> nsubexp > rx_buffer_size ) ) {
    rx_buffer_size = r -> nsubexp ; 
    startp_buffer = startp ; 
    maybep_buffer = maybep ; 
    endp_buffer = endp ; 
  }
  else if (maybep && ! maybep_buffer && (r -> nsubexp == rx_buffer_size ) ) {
    maybep_buffer = maybep ; 
  }
  RET_VALUE_START (dropped ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * compare (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return gen_compare ("regexp-match" , 0 , argc , argv , 0 , 0 ) ; 
}
static Scheme_Object * positions (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return gen_compare ("regexp-match-positions" , 1 , argc , argv , 0 , 0 ) ; 
}
static Scheme_Object * compare_bool (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return gen_compare ("regexp-match?" , 2 , argc , argv , 0 , 0 ) ; 
}
static Scheme_Object * compare_peek (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return gen_compare ("regexp-match-peek" , 0 , argc , argv , 1 , 0 ) ; 
}
static Scheme_Object * positions_peek (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return gen_compare ("regexp-match-peek-positions" , 1 , argc , argv , 1 , 0 ) ; 
}
static Scheme_Object * compare_peek_nonblock (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return gen_compare ("regexp-match-peek-immediate" , 0 , argc , argv , 1 , 1 ) ; 
}
static Scheme_Object * positions_peek_nonblock (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return gen_compare ("regexp-match-peek-positions-immediate" , 1 , argc , argv , 1 , 1 ) ; 
}
static char * build_call_name (const char * n ) {
  char * m ; 
  int l ; 
  DECL_RET_SAVE (char * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(n, 0), PUSH(m, 1)));
# define XfOrM1608_COUNT (2)
# define SETUP_XfOrM1608(x) SETUP(XfOrM1608_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  m = NULLED_OUT ; 
  l = strlen (n ) ; 
  m = (char * ) FUNCCALL(SETUP_XfOrM1608(_), GC_malloc_atomic (l + 42 ) ); 
  (memcpy (m , n , l ) ) ; 
  (strcpy (m XFORM_OK_PLUS l , " (calling given filter procedure)" ) ) ; 
  RET_VALUE_START (m ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
/* this far 5284 */
/* this far 5284 */
static Scheme_Object * gen_replace (const char * name , int argc , Scheme_Object * argv [] , int all ) {
  Scheme_Object * orig ; 
  regexp * r ; 
  char * source , * prefix = ((void * ) 0 ) , * deststr ; 
  rxpos * startp , * maybep , * endp ; 
  int prefix_len = 0 , sourcelen , srcoffset = 0 , was_non_byte , destlen ; 
  char * __funcarg119 = NULLED_OUT ; 
  char * __funcarg118 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK(16);
  BLOCK_SETUP_TOP((PUSH(deststr, 0), PUSH(startp, 1), PUSH(r, 2), PUSH(source, 3), PUSH(name, 4), PUSH(orig, 5), PUSH(maybep, 6), PUSH(prefix, 7), PUSH(argv, 8), PUSH(endp, 9)));
# define XfOrM1609_COUNT (10)
# define SETUP_XfOrM1609(x) SETUP(XfOrM1609_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_each(x)
# define FUNCCALL(s, x) FUNCCALL_each(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_each(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_each(x)
  orig = NULLED_OUT ; 
  r = NULLED_OUT ; 
  source = NULLED_OUT ; 
  deststr = NULLED_OUT ; 
  startp = NULLED_OUT ; 
  maybep = NULLED_OUT ; 
  endp = NULLED_OUT ; 
  if (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) != scheme_regexp_type && ! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) && ! ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type (name , "regexp, byte-regexp, string, or byte string" , 0 , argc , argv ) ); 
  if (! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) && ! ((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type (name , "string or byte string" , 1 , argc , argv ) ); 
  if (! ((Scheme_Type ) (((((long ) (argv [2 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [2 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) && ! ((Scheme_Type ) (((((long ) (argv [2 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [2 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) && ! (! (((long ) (argv [2 ] ) ) & 0x1 ) && ((((argv [2 ] ) -> type ) >= scheme_prim_type ) && (((argv [2 ] ) -> type ) <= scheme_native_closure_type ) ) ) )
    FUNCCALL_EMPTY(scheme_wrong_type (name , "string, byte string, or procedure" , 2 , argc , argv ) ); 
  if (((Scheme_Type ) (((((long ) (argv [2 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [2 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ) {
#   define XfOrM1676_COUNT (0+XfOrM1609_COUNT)
#   define SETUP_XfOrM1676(x) SETUP_XfOrM1609(x)
    if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) || ((((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == scheme_regexp_type ) && (((regexp * ) argv [0 ] ) -> flags & 0x01 ) ) ) {
#     define XfOrM1677_COUNT (0+XfOrM1676_COUNT)
#     define SETUP_XfOrM1677(x) SETUP_XfOrM1676(x)
      if (((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) ) {
#       define XfOrM1678_COUNT (0+XfOrM1677_COUNT)
#       define SETUP_XfOrM1678(x) SETUP_XfOrM1677(x)
        FUNCCALL(SETUP_XfOrM1678(_), scheme_arg_mismatch (name , "cannot replace a string with a byte string: " , argv [2 ] ) ); 
      }
    }
  }
  if (((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) || ((Scheme_Type ) (((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    r = FUNCCALL(SETUP_XfOrM1609(_), regcomp_object (argv [0 ] ) ); 
  else r = (regexp * ) argv [0 ] ; 
  if ((! (((long ) (argv [2 ] ) ) & 0x1 ) && ((((argv [2 ] ) -> type ) >= scheme_prim_type ) && (((argv [2 ] ) -> type ) <= scheme_native_closure_type ) ) ) ) {
#   define XfOrM1674_COUNT (0+XfOrM1609_COUNT)
#   define SETUP_XfOrM1674(x) SETUP_XfOrM1609(x)
    if (! FUNCCALL(SETUP_XfOrM1674(_), scheme_check_proc_arity (((void * ) 0 ) , r -> nsubexp , 2 , argc , argv ) )) {
#     define XfOrM1675_COUNT (0+XfOrM1674_COUNT)
#     define SETUP_XfOrM1675(x) SETUP_XfOrM1674(x)
      FUNCCALL_EMPTY(scheme_raise_exn (MZEXN_FAIL_CONTRACT , "%s: regexp produces %d matches: %V; procedure does not accept %d arguments: %V" , name , r -> nsubexp , (Scheme_Object * ) r , r -> nsubexp , argv [2 ] ) ); 
    }
  }
  if (((Scheme_Type ) (((((long ) (argv [1 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [1 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) ) {
#   define XfOrM1673_COUNT (0+XfOrM1609_COUNT)
#   define SETUP_XfOrM1673(x) SETUP_XfOrM1609(x)
    orig = FUNCCALL(SETUP_XfOrM1673(_), scheme_char_string_to_byte_string (argv [1 ] ) ); 
    if (r -> flags & 0x01 )
      was_non_byte = 1 ; 
    else was_non_byte = 0 ; 
  }
  else {
    orig = argv [1 ] ; 
    was_non_byte = 0 ; 
  }
  source = (((Scheme_Simple_Object * ) (orig ) ) -> u . byte_str_val . string_val ) ; 
  sourcelen = (((Scheme_Simple_Object * ) (orig ) ) -> u . byte_str_val . tag_val ) ; 
  deststr = ((void * ) 0 ) ; 
  destlen = 0 ; 
  startp = ((rxpos * ) FUNCCALL(SETUP_XfOrM1609(_), GC_malloc_atomic (sizeof (rxpos ) * (r -> nsubexp ) ) )) ; 
  if (r -> nsubexp > 1 )
    maybep = ((rxpos * ) FUNCCALL(SETUP_XfOrM1609(_), GC_malloc_atomic (sizeof (rxpos ) * (r -> nsubexp ) ) )) ; 
  else maybep = ((void * ) 0 ) ; 
  endp = ((rxpos * ) FUNCCALL(SETUP_XfOrM1609(_), GC_malloc_atomic (sizeof (rxpos ) * (r -> nsubexp ) ) )) ; 
  while (1 ) {
    int m ; 
#   define XfOrM1641_COUNT (0+XfOrM1609_COUNT)
#   define SETUP_XfOrM1641(x) SETUP_XfOrM1609(x)
    m = FUNCCALL(SETUP_XfOrM1641(_), regexec (name , r , source , srcoffset , sourcelen - srcoffset , startp , maybep , endp , ((void * ) 0 ) , ((void * ) 0 ) , 0 , ((void * ) 0 ) , 0 , 0 , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) , ((void * ) 0 ) ) ); 
    if (m ) {
      char * insert ; 
      long len , end , startpd , endpd ; 
      BLOCK_SETUP((PUSH(insert, 0+XfOrM1641_COUNT)));
#     define XfOrM1646_COUNT (1+XfOrM1641_COUNT)
#     define SETUP_XfOrM1646(x) SETUP(XfOrM1646_COUNT)
      insert = NULLED_OUT ; 
      if ((startp [0 ] == endp [0 ] ) && all ) {
#       define XfOrM1671_COUNT (0+XfOrM1646_COUNT)
#       define SETUP_XfOrM1671(x) SETUP_XfOrM1646(x)
        FUNCCALL(SETUP_XfOrM1671(_), scheme_arg_mismatch (name , "found a zero-width match for pattern: " , argv [0 ] ) ); 
        RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
      }
      if ((! (((long ) (argv [2 ] ) ) & 0x1 ) && ((((argv [2 ] ) -> type ) >= scheme_prim_type ) && (((argv [2 ] ) -> type ) <= scheme_native_closure_type ) ) ) ) {
        int i ; 
        Scheme_Object * m , * * args , * quick_args [5 ] ; 
        BLOCK_SETUP((PUSH(args, 0+XfOrM1646_COUNT), PUSHARRAY(quick_args, 5, 1+XfOrM1646_COUNT), PUSH(m, 4+XfOrM1646_COUNT)));
#       define XfOrM1654_COUNT (5+XfOrM1646_COUNT)
#       define SETUP_XfOrM1654(x) SETUP(XfOrM1654_COUNT)
        m = NULLED_OUT ; 
        args = NULLED_OUT ; 
        NULL_OUT_ARRAY (quick_args ) ; 
        if (r -> nsubexp <= 5 ) {
          args = quick_args ; 
        }
        else {
#         define XfOrM1669_COUNT (0+XfOrM1654_COUNT)
#         define SETUP_XfOrM1669(x) SETUP_XfOrM1654(x)
          args = ((Scheme_Object * * ) FUNCCALL(SETUP_XfOrM1669(_), GC_malloc (sizeof (Scheme_Object * ) * (r -> nsubexp ) ) )) ; 
        }
        for (i = r -> nsubexp ; i -- ; ) {
#         define XfOrM1664_COUNT (0+XfOrM1654_COUNT)
#         define SETUP_XfOrM1664(x) SETUP_XfOrM1654(x)
          if (startp [i ] == - 1 ) {
            args [i ] = scheme_false ; 
          }
          else {
            long len ; 
#           define XfOrM1665_COUNT (0+XfOrM1664_COUNT)
#           define SETUP_XfOrM1665(x) SETUP_XfOrM1664(x)
            len = endp [i ] - startp [i ] ; 
            if (was_non_byte ) {
#             define XfOrM1667_COUNT (0+XfOrM1665_COUNT)
#             define SETUP_XfOrM1667(x) SETUP_XfOrM1665(x)
              m = FUNCCALL(SETUP_XfOrM1667(_), scheme_make_sized_offset_utf8_string (source , startp [i ] , len ) ); 
              args [i ] = m ; 
            }
            else {
#             define XfOrM1666_COUNT (0+XfOrM1665_COUNT)
#             define SETUP_XfOrM1666(x) SETUP_XfOrM1665(x)
              m = FUNCCALL(SETUP_XfOrM1666(_), scheme_make_sized_offset_byte_string (source , startp [i ] , len , 1 ) ); 
              args [i ] = m ; 
            }
          }
        }
        m = FUNCCALL(SETUP_XfOrM1654(_), scheme_do_eval (argv [2 ] , r -> nsubexp , args , 1 ) ); 
        if (! was_non_byte ) {
#         define XfOrM1657_COUNT (0+XfOrM1654_COUNT)
#         define SETUP_XfOrM1657(x) SETUP_XfOrM1654(x)
          if (! ((Scheme_Type ) (((((long ) (m ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (m ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) ) {
#           define XfOrM1658_COUNT (0+XfOrM1657_COUNT)
#           define SETUP_XfOrM1658(x) SETUP_XfOrM1657(x)
            args [0 ] = m ; 
            (__funcarg119 = FUNCCALL(SETUP_XfOrM1658(_), build_call_name (name ) ), FUNCCALL_AGAIN(scheme_wrong_type (__funcarg119 , "byte string" , - 1 , - 1 , args ) )) ; 
          }
          insert = (((Scheme_Simple_Object * ) (m ) ) -> u . byte_str_val . string_val ) ; 
          len = (((Scheme_Simple_Object * ) (m ) ) -> u . byte_str_val . tag_val ) ; 
        }
        else {
#         define XfOrM1655_COUNT (0+XfOrM1654_COUNT)
#         define SETUP_XfOrM1655(x) SETUP_XfOrM1654(x)
          if (! ((Scheme_Type ) (((((long ) (m ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (m ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) ) {
#           define XfOrM1656_COUNT (0+XfOrM1655_COUNT)
#           define SETUP_XfOrM1656(x) SETUP_XfOrM1655(x)
            args [0 ] = m ; 
            (__funcarg118 = FUNCCALL(SETUP_XfOrM1656(_), build_call_name (name ) ), FUNCCALL_AGAIN(scheme_wrong_type (__funcarg118 , "string" , - 1 , - 1 , args ) )) ; 
          }
          len = FUNCCALL(SETUP_XfOrM1655(_), scheme_utf8_encode ((((Scheme_Simple_Object * ) (m ) ) -> u . char_str_val . string_val ) , 0 , (((Scheme_Simple_Object * ) (m ) ) -> u . char_str_val . tag_val ) , ((void * ) 0 ) , 0 , 0 ) ); 
          insert = (char * ) FUNCCALL(SETUP_XfOrM1655(_), GC_malloc_atomic (len ) ); 
          FUNCCALL(SETUP_XfOrM1655(_), scheme_utf8_encode ((((Scheme_Simple_Object * ) (m ) ) -> u . char_str_val . string_val ) , 0 , (((Scheme_Simple_Object * ) (m ) ) -> u . char_str_val . tag_val ) , (unsigned char * ) insert , 0 , 0 ) ); 
        }
      }
      else {
#       define XfOrM1650_COUNT (0+XfOrM1646_COUNT)
#       define SETUP_XfOrM1650(x) SETUP_XfOrM1646(x)
        if (! deststr ) {
#         define XfOrM1651_COUNT (0+XfOrM1650_COUNT)
#         define SETUP_XfOrM1651(x) SETUP_XfOrM1650(x)
          if (((Scheme_Type ) (((((long ) (argv [2 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [2 ] ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) ) {
            Scheme_Object * bs ; 
            BLOCK_SETUP((PUSH(bs, 0+XfOrM1651_COUNT)));
#           define XfOrM1653_COUNT (1+XfOrM1651_COUNT)
#           define SETUP_XfOrM1653(x) SETUP(XfOrM1653_COUNT)
            bs = NULLED_OUT ; 
            bs = FUNCCALL(SETUP_XfOrM1653(_), scheme_char_string_to_byte_string (argv [2 ] ) ); 
            deststr = (((Scheme_Simple_Object * ) (bs ) ) -> u . byte_str_val . string_val ) ; 
            destlen = (((Scheme_Simple_Object * ) (bs ) ) -> u . byte_str_val . tag_val ) ; 
          }
          else {
            deststr = (((Scheme_Simple_Object * ) (argv [2 ] ) ) -> u . byte_str_val . string_val ) ; 
            destlen = (((Scheme_Simple_Object * ) (argv [2 ] ) ) -> u . byte_str_val . tag_val ) ; 
          }
        }
        insert = FUNCCALL(SETUP_XfOrM1650(_), regsub (r , deststr , destlen , & len , source , startp , endp ) ); 
      }
      end = sourcelen ; 
      startpd = startp [0 ] ; 
      endpd = endp [0 ] ; 
      if (! startpd && (endpd == end ) && ! prefix ) {
#       define XfOrM1649_COUNT (0+XfOrM1646_COUNT)
#       define SETUP_XfOrM1649(x) SETUP_XfOrM1646(x)
        if (was_non_byte )
          RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_utf8_string (insert , len ) )) RET_VALUE_EMPTY_END ; 
        else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_byte_string (insert , len , 0 ) )) RET_VALUE_EMPTY_END ; 
      }
      else if (! all ) {
        char * result ; 
        long total ; 
        BLOCK_SETUP((PUSH(result, 0+XfOrM1646_COUNT)));
#       define XfOrM1648_COUNT (1+XfOrM1646_COUNT)
#       define SETUP_XfOrM1648(x) SETUP(XfOrM1648_COUNT)
        result = NULLED_OUT ; 
        total = len + (startpd - srcoffset ) + (end - endpd ) ; 
        result = (char * ) FUNCCALL(SETUP_XfOrM1648(_), GC_malloc_atomic (total + 1 ) ); 
        (memcpy (result , source + srcoffset , startpd - srcoffset ) ) ; 
        (memcpy (result + (startpd - srcoffset ) , insert , len ) ) ; 
        (memcpy (result + (startpd - srcoffset ) + len , source + endpd , (end - endpd ) + 1 ) ) ; 
        if (was_non_byte )
          RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_utf8_string (result , total ) )) RET_VALUE_EMPTY_END ; 
        else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_byte_string (result , total , 0 ) )) RET_VALUE_EMPTY_END ; 
      }
      else {
        char * naya ; 
        long total ; 
        BLOCK_SETUP((PUSH(naya, 0+XfOrM1646_COUNT)));
#       define XfOrM1647_COUNT (1+XfOrM1646_COUNT)
#       define SETUP_XfOrM1647(x) SETUP(XfOrM1647_COUNT)
        naya = NULLED_OUT ; 
        total = len + prefix_len + (startpd - srcoffset ) ; 
        naya = (char * ) FUNCCALL(SETUP_XfOrM1647(_), GC_malloc_atomic (total + 1 ) ); 
        (memcpy (naya , prefix , prefix_len ) ) ; 
        (memcpy (naya + prefix_len , source + srcoffset , startpd - srcoffset ) ) ; 
        (memcpy (naya + prefix_len + (startpd - srcoffset ) , insert , len ) ) ; 
        prefix = naya ; 
        prefix_len = total ; 
        srcoffset = endpd ; 
      }
    }
    else if (! prefix ) {
      if (was_non_byte )
        RET_VALUE_START (argv [1 ] ) RET_VALUE_END ; 
      else RET_VALUE_START (orig ) RET_VALUE_END ; 
    }
    else {
      char * result ; 
      long total , slen ; 
      BLOCK_SETUP((PUSH(result, 0+XfOrM1641_COUNT)));
#     define XfOrM1644_COUNT (1+XfOrM1641_COUNT)
#     define SETUP_XfOrM1644(x) SETUP(XfOrM1644_COUNT)
      result = NULLED_OUT ; 
      slen = sourcelen - srcoffset ; 
      total = prefix_len + slen ; 
      result = (char * ) FUNCCALL(SETUP_XfOrM1644(_), GC_malloc_atomic (total + 1 ) ); 
      (memcpy (result , prefix , prefix_len ) ) ; 
      (memcpy (result + prefix_len , source + srcoffset , slen ) ) ; 
      result [prefix_len + slen ] = 0 ; 
      if (was_non_byte )
        RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_utf8_string (result , total ) )) RET_VALUE_EMPTY_END ; 
      else RET_VALUE_EMPTY_START (FUNCCALL_EMPTY(scheme_make_sized_byte_string (result , total , 0 ) )) RET_VALUE_EMPTY_END ; 
    }
    {
#     define XfOrM1642_COUNT (0+XfOrM1641_COUNT)
#     define SETUP_XfOrM1642(x) SETUP_XfOrM1641(x)
      if ((scheme_fuel_counter ) <= 0 ) {
#       define XfOrM1643_COUNT (0+XfOrM1642_COUNT)
#       define SETUP_XfOrM1643(x) SETUP_XfOrM1642(x)
        FUNCCALL(SETUP_XfOrM1643(_), scheme_out_of_fuel () ); 
      }
    }
    ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
static Scheme_Object * replace (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return gen_replace ("regexp-replace" , argc , argv , 0 ) ; 
}
static Scheme_Object * replace_star (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return gen_replace ("regexp-replace*" , argc , argv , 1 ) ; 
}
static Scheme_Object * regexp_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (((((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == scheme_regexp_type ) && (((regexp * ) argv [0 ] ) -> flags & 0x01 ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * byte_regexp_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (((((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == scheme_regexp_type ) && ! (((regexp * ) argv [0 ] ) -> flags & 0x01 ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * pregexp_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (((((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == scheme_regexp_type ) && (((regexp * ) argv [0 ] ) -> flags & 0x01 ) && (((regexp * ) argv [0 ] ) -> flags & 0x02 ) ) ? scheme_true : scheme_false ) ; 
}
static Scheme_Object * byte_pregexp_p (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  return (((((((long ) (argv [0 ] ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (argv [0 ] ) ) -> type ) == scheme_regexp_type ) && ! (((regexp * ) argv [0 ] ) -> flags & 0x01 ) && (((regexp * ) argv [0 ] ) -> flags & 0x02 ) ) ? scheme_true : scheme_false ) ; 
}
Scheme_Object * scheme_regexp_source (Scheme_Object * re ) {
  /* No conversion */
  return ((regexp * ) re ) -> source ; 
}
int scheme_regexp_is_byte (Scheme_Object * re ) {
  /* No conversion */
  return ! (((regexp * ) re ) -> flags & 0x01 ) ; 
}
static int mark_regexp_SIZE (void * p ) {
  regexp * r = (regexp * ) p ; 
  return (((sizeof (regexp ) + r -> regsize ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_regexp_MARK (void * p ) {
  regexp * r = (regexp * ) p ; 
  GC_mark (r -> source ) ; 
  GC_mark (r -> regstart ) ; 
  return (((sizeof (regexp ) + r -> regsize ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_regexp_FIXUP (void * p ) {
  regexp * r = (regexp * ) p ; 
  GC_fixup (& (r -> source ) ) ; 
  GC_fixup (& (r -> regstart ) ) ; 
  return (((sizeof (regexp ) + r -> regsize ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_regwork_SIZE (void * p ) {
  return ((sizeof (Regwork ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_regwork_MARK (void * p ) {
  Regwork * r = (Regwork * ) p ; 
  GC_mark (r -> str ) ; 
  GC_mark (r -> instr ) ; 
  GC_mark (r -> port ) ; 
  GC_mark (r -> unless_evt ) ; 
  GC_mark (r -> startp ) ; 
  GC_mark (r -> maybep ) ; 
  GC_mark (r -> endp ) ; 
  GC_mark (r -> counters ) ; 
  GC_mark (r -> peekskip ) ; 
  return ((sizeof (Regwork ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
static int mark_regwork_FIXUP (void * p ) {
  Regwork * r = (Regwork * ) p ; 
  GC_fixup (& (r -> str ) ) ; 
  GC_fixup (& (r -> instr ) ) ; 
  GC_fixup (& (r -> port ) ) ; 
  GC_fixup (& (r -> unless_evt ) ) ; 
  GC_fixup (& (r -> startp ) ) ; 
  GC_fixup (& (r -> maybep ) ) ; 
  GC_fixup (& (r -> endp ) ) ; 
  GC_fixup (& (r -> counters ) ) ; 
  GC_fixup (& (r -> peekskip ) ) ; 
  return ((sizeof (Regwork ) + (1 << 3 ) - 1 ) >> 3 ) ; 
}
void scheme_regexp_initialize (Scheme_Env * env ) {
  Scheme_Object * __funcarg136 = NULLED_OUT ; 
  Scheme_Object * __funcarg135 = NULLED_OUT ; 
  Scheme_Object * __funcarg134 = NULLED_OUT ; 
  Scheme_Object * __funcarg133 = NULLED_OUT ; 
  Scheme_Object * __funcarg132 = NULLED_OUT ; 
  Scheme_Object * __funcarg131 = NULLED_OUT ; 
  Scheme_Object * __funcarg130 = NULLED_OUT ; 
  Scheme_Object * __funcarg129 = NULLED_OUT ; 
  Scheme_Object * __funcarg128 = NULLED_OUT ; 
  Scheme_Object * __funcarg127 = NULLED_OUT ; 
  Scheme_Object * __funcarg126 = NULLED_OUT ; 
  Scheme_Object * __funcarg125 = NULLED_OUT ; 
  Scheme_Object * __funcarg124 = NULLED_OUT ; 
  Scheme_Object * __funcarg123 = NULLED_OUT ; 
  Scheme_Object * __funcarg122 = NULLED_OUT ; 
  Scheme_Object * __funcarg121 = NULLED_OUT ; 
  Scheme_Object * __funcarg120 = NULLED_OUT ; 
  PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(env, 0)));
# define XfOrM1687_COUNT (1)
# define SETUP_XfOrM1687(x) SETUP(XfOrM1687_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  FUNCCALL(SETUP_XfOrM1687(_), GC_register_traversers (scheme_regexp_type , mark_regexp_SIZE , mark_regexp_MARK , mark_regexp_FIXUP , 0 , 0 ) ); 
  FUNCCALL(SETUP_XfOrM1687(_), GC_register_traversers (scheme_rt_regwork , mark_regwork_SIZE , mark_regwork_MARK , mark_regwork_FIXUP , 1 , 0 ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & regparsestr , sizeof (regparsestr ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & regstr , sizeof (regstr ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & regbackknown , sizeof (regbackknown ) ) ); 
  FUNCCALL_AGAIN(scheme_register_static ((void * ) & regbackdepends , sizeof (regbackdepends ) ) ); 
  (__funcarg136 = FUNCCALL(SETUP_XfOrM1687(_), scheme_make_prim_w_arity (make_regexp , "byte-regexp" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("byte-regexp" , __funcarg136 , env ) )) ; 
  (__funcarg135 = FUNCCALL(SETUP_XfOrM1687(_), scheme_make_prim_w_arity (make_utf8_regexp , "regexp" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("regexp" , __funcarg135 , env ) )) ; 
  (__funcarg134 = FUNCCALL(SETUP_XfOrM1687(_), scheme_make_prim_w_arity (make_pregexp , "byte-pregexp" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("byte-pregexp" , __funcarg134 , env ) )) ; 
  (__funcarg133 = FUNCCALL(SETUP_XfOrM1687(_), scheme_make_prim_w_arity (make_utf8_pregexp , "pregexp" , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("pregexp" , __funcarg133 , env ) )) ; 
  (__funcarg132 = FUNCCALL(SETUP_XfOrM1687(_), scheme_make_prim_w_arity (compare , "regexp-match" , 2 , 5 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("regexp-match" , __funcarg132 , env ) )) ; 
  (__funcarg131 = FUNCCALL(SETUP_XfOrM1687(_), scheme_make_prim_w_arity (positions , "regexp-match-positions" , 2 , 5 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("regexp-match-positions" , __funcarg131 , env ) )) ; 
  (__funcarg130 = FUNCCALL(SETUP_XfOrM1687(_), scheme_make_prim_w_arity (compare_bool , "regexp-match?" , 2 , 5 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("regexp-match?" , __funcarg130 , env ) )) ; 
  (__funcarg129 = FUNCCALL(SETUP_XfOrM1687(_), scheme_make_prim_w_arity (compare_peek , "regexp-match-peek" , 2 , 5 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("regexp-match-peek" , __funcarg129 , env ) )) ; 
  (__funcarg128 = FUNCCALL(SETUP_XfOrM1687(_), scheme_make_prim_w_arity (positions_peek , "regexp-match-peek-positions" , 2 , 5 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("regexp-match-peek-positions" , __funcarg128 , env ) )) ; 
  (__funcarg127 = FUNCCALL(SETUP_XfOrM1687(_), scheme_make_prim_w_arity (compare_peek_nonblock , "regexp-match-peek-immediate" , 2 , 5 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("regexp-match-peek-immediate" , __funcarg127 , env ) )) ; 
  (__funcarg126 = FUNCCALL(SETUP_XfOrM1687(_), scheme_make_prim_w_arity (positions_peek_nonblock , "regexp-match-peek-positions-immediate" , 2 , 5 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("regexp-match-peek-positions-immediate" , __funcarg126 , env ) )) ; 
  (__funcarg125 = FUNCCALL(SETUP_XfOrM1687(_), scheme_make_prim_w_arity (replace , "regexp-replace" , 3 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("regexp-replace" , __funcarg125 , env ) )) ; 
  (__funcarg124 = FUNCCALL(SETUP_XfOrM1687(_), scheme_make_prim_w_arity (replace_star , "regexp-replace*" , 3 , 3 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("regexp-replace*" , __funcarg124 , env ) )) ; 
  (__funcarg123 = FUNCCALL(SETUP_XfOrM1687(_), scheme_make_folding_prim (regexp_p , "regexp?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("regexp?" , __funcarg123 , env ) )) ; 
  (__funcarg122 = FUNCCALL(SETUP_XfOrM1687(_), scheme_make_folding_prim (byte_regexp_p , "byte-regexp?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("byte-regexp?" , __funcarg122 , env ) )) ; 
  (__funcarg121 = FUNCCALL(SETUP_XfOrM1687(_), scheme_make_folding_prim (pregexp_p , "pregexp?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("pregexp?" , __funcarg121 , env ) )) ; 
  (__funcarg120 = FUNCCALL(SETUP_XfOrM1687(_), scheme_make_folding_prim (byte_pregexp_p , "byte-pregexp?" , 1 , 1 , 1 ) ), FUNCCALL_AGAIN(scheme_add_global_constant ("byte-pregexp?" , __funcarg120 , env ) )) ; 
  RET_NOTHING_AT_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
