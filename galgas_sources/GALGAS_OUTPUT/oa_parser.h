//---------------------------------------------------------------------------*
//                                                                           *
//                            File 'oa_parser.h'                             *
//               Generated by version 0.14.0 (LL(1) grammar)                 *
//                     january 17th, 2005, at 13h54'53"                      *
//                                                                           *
// This program is free software; you can redistribute it and/or modify it   *
// under the terms of the GNU General Public License as published by the     *
// Free Software Foundation.                                                 *
//                                                                           *
// This program is distributed in the hope it will be useful, but WITHOUT    *
// ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or     *
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for  *
// more details.                                                             *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef oa_parser_DEFINED
#define oa_parser_DEFINED

#include <string.h>

// Include predefined semantics types definition *
#include "memory/C_reference_count.h"
#include "galgas/AC_galgas_io.h"
#include "galgas/GGS_location.h"
#include "galgas/GGS_lbool.h"
#include "galgas/GGS_lchar.h"
#include "galgas/GGS_lstring.h"
#include "galgas/GGS_ldfloat.h"
#include "galgas/GGS_luint.h"
#include "galgas/GGS_lsint.h"
#include "galgas/AC_galgas_map.h"
// Include scanner definition *
#include "oa_scanner.h"
// Include imported semantics *
#include "oa_semantics.h"


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                    Parser class oa_parser declaration                     *
//                                                                           *
//---------------------------------------------------------------------------*

class oa_parser {
  public : virtual ~oa_parser (void) {}

  protected : virtual void nt_axiome_ (oa_scanner &) = 0 ;

  protected : void pr_axiome_oa_parser_175_14_ (oa_scanner &) ;

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
