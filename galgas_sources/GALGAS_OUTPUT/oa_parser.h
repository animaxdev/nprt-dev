//---------------------------------------------------------------------------*
//                                                                           *
//                            File 'oa_parser.h'                             *
//                 Generated by version GALGAS_BETA_VERSION                  *
//                    november 15th, 2009, at 20h55'33"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef oa_parser_DEFINED
#define oa_parser_DEFINED

#include <string.h>

//---------------------------------------------------------------------------*

#include "galgas/GGS__header.h"
#include "oa_scanner.h"

//---------------------------------------------------------------------------*

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

  protected : void pr_axiome_oa_parser_14_13_ (oa_scanner &) ;

  protected : virtual PMSInt16 select_oa_parser_0 (oa_scanner &) = 0 ;

  protected : virtual PMSInt16 select_oa_parser_1 (oa_scanner &) = 0 ;

  protected : virtual PMSInt16 select_oa_parser_2 (oa_scanner &) = 0 ;

  protected : virtual PMSInt16 select_oa_parser_3 (oa_scanner &) = 0 ;

  protected : virtual PMSInt16 select_oa_parser_4 (oa_scanner &) = 0 ;

  protected : virtual PMSInt16 select_oa_parser_5 (oa_scanner &) = 0 ;

  protected : virtual PMSInt16 select_oa_parser_6 (oa_scanner &) = 0 ;

  protected : virtual PMSInt16 select_oa_parser_7 (oa_scanner &) = 0 ;

  protected : virtual PMSInt16 select_oa_parser_8 (oa_scanner &) = 0 ;

  protected : virtual PMSInt16 select_oa_parser_9 (oa_scanner &) = 0 ;

  protected : virtual PMSInt16 select_oa_parser_10 (oa_scanner &) = 0 ;

  protected : virtual PMSInt16 select_oa_parser_11 (oa_scanner &) = 0 ;

  protected : virtual PMSInt16 select_oa_parser_12 (oa_scanner &) = 0 ;

  protected : virtual PMSInt16 select_oa_parser_13 (oa_scanner &) = 0 ;

  protected : virtual PMSInt16 select_oa_parser_14 (oa_scanner &) = 0 ;

} ;

//---------------------------------------------------------------------------*

#endif
