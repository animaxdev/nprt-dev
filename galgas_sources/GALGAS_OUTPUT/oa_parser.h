//---------------------------------------------------------------------------*
//                                                                           *
//                            File 'oa_parser.h'                             *
//         Generated by version GALGAS_BETA_VERSION (LL(1) grammar)          *
//                     october 28th, 2006, at 21h27'13"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef oa_parser_DEFINED
#define oa_parser_DEFINED

#include <string.h>

//---------------------------------------------------------------------------*

#include "galgas/C_GGS_Object.h"
#include "galgas/AC_galgas_io.h"
#include "galgas/GGS_location.h"
#include "galgas/GGS_lbool.h"
#include "galgas/GGS_lchar.h"
#include "galgas/GGS_lstring.h"
#include "galgas/GGS_ldouble.h"
#include "galgas/GGS_luint.h"
#include "galgas/GGS_lsint.h"
#include "galgas/GGS_luint64.h"
#include "galgas/GGS_lsint64.h"
#include "galgas/GGS_stringset.h"
#include "galgas/AC_galgas_map.h"
#include "galgas/AC_galgas_list.h"

//---------------------------------------------------------------------------*

#include "oa_scanner.h"

// Include imported semantics
#include "oa_semantics.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                          Class Predeclarations                            *
//                                                                           *
//---------------------------------------------------------------------------*


//---------------------------------------------------------------------------*
//                                                                           *
//                    Parser class oa_parser declaration                     *
//                                                                           *
//---------------------------------------------------------------------------*

class oa_parser {
  public : virtual ~oa_parser (void) {}

  protected : virtual void nt_axiome_ (oa_scanner &) = 0 ;

  protected : void pr_axiome_oa_parser_171_14_ (oa_scanner &) ;

  protected : virtual sint16 select_repeat_oa_parser_0 (oa_scanner &) = 0 ;

  protected : virtual sint16 select_oa_parser_1 (oa_scanner &) = 0 ;

  protected : virtual sint16 select_oa_parser_2 (oa_scanner &) = 0 ;

  protected : virtual sint16 select_oa_parser_3 (oa_scanner &) = 0 ;

  protected : virtual sint16 select_oa_parser_4 (oa_scanner &) = 0 ;

  protected : virtual sint16 select_oa_parser_5 (oa_scanner &) = 0 ;

  protected : virtual sint16 select_oa_parser_6 (oa_scanner &) = 0 ;

  protected : virtual sint16 select_oa_parser_7 (oa_scanner &) = 0 ;

  protected : virtual sint16 select_oa_parser_8 (oa_scanner &) = 0 ;

  protected : virtual sint16 select_oa_parser_9 (oa_scanner &) = 0 ;

  protected : virtual sint16 select_oa_parser_10 (oa_scanner &) = 0 ;

  protected : virtual sint16 select_oa_parser_11 (oa_scanner &) = 0 ;

  protected : virtual sint16 select_oa_parser_12 (oa_scanner &) = 0 ;

  protected : virtual sint16 select_oa_parser_13 (oa_scanner &) = 0 ;

  protected : virtual sint16 select_oa_parser_14 (oa_scanner &) = 0 ;

} ;

//---------------------------------------------------------------------------*

#endif
