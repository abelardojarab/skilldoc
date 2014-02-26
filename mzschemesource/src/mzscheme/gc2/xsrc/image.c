#include "precomp.h"
int (* scheme_actual_main ) (int argc , char * * argv ) ; 
void scheme_set_actual_main (int (* m ) (int argc , char * * argv ) ) {
  /* No conversion */
  scheme_actual_main = m ; 
}
int scheme_image_main (int argc , char * * argv ) {
  /* No conversion */
  return scheme_actual_main (argc , argv ) ; 
}
void scheme_no_dumps (char * why ) {
  /* No conversion */
}
