//---------------------------------------------------------------------------*
//                                                                           *
//                           File 'oa_grammar.h'                             *
//                        Generated by version 2.5.4                         *
//                     january 30th, 2014, at 17h15'5"                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef GRAMMAR_oa_5F_grammar_HAS_BEEN_DEFINED
#define GRAMMAR_oa_5F_grammar_HAS_BEEN_DEFINED

//-----------------------------------------------------------------------------*

#include "oa_parser.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//-----------------------------------------------------------------------------*

class cGrammar_oa_5F_grammar : public cParser_oa_5F_parser {
//------------------------------------- 'axiome' non terminal
//--- 'parse' label
  public : virtual void nt_axiome_parse (C_Lexique_oa_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_axiome_ (C_Lexique_oa_5F_scanner * inCompiler) ;

//--- Start symbol
  public : static void _performSourceFileParsing_ (C_Compiler * inCompiler,
                                                   GALGAS_lstring inFileName
                                                   COMMA_LOCATION_ARGS) ;

  public : static void _performSourceStringParsing_ (C_Compiler * inCompiler,
                                                     GALGAS_string inSourceString
                                                     COMMA_LOCATION_ARGS) ;

  public : virtual PMSInt32 select_oa_5F_parser_0 (C_Lexique_oa_5F_scanner *) ;

  public : virtual PMSInt32 select_oa_5F_parser_1 (C_Lexique_oa_5F_scanner *) ;

  public : virtual PMSInt32 select_oa_5F_parser_2 (C_Lexique_oa_5F_scanner *) ;

  public : virtual PMSInt32 select_oa_5F_parser_3 (C_Lexique_oa_5F_scanner *) ;

  public : virtual PMSInt32 select_oa_5F_parser_4 (C_Lexique_oa_5F_scanner *) ;

  public : virtual PMSInt32 select_oa_5F_parser_5 (C_Lexique_oa_5F_scanner *) ;

  public : virtual PMSInt32 select_oa_5F_parser_6 (C_Lexique_oa_5F_scanner *) ;

  public : virtual PMSInt32 select_oa_5F_parser_7 (C_Lexique_oa_5F_scanner *) ;

  public : virtual PMSInt32 select_oa_5F_parser_8 (C_Lexique_oa_5F_scanner *) ;

  public : virtual PMSInt32 select_oa_5F_parser_9 (C_Lexique_oa_5F_scanner *) ;

  public : virtual PMSInt32 select_oa_5F_parser_10 (C_Lexique_oa_5F_scanner *) ;

  public : virtual PMSInt32 select_oa_5F_parser_11 (C_Lexique_oa_5F_scanner *) ;

  public : virtual PMSInt32 select_oa_5F_parser_12 (C_Lexique_oa_5F_scanner *) ;

  public : virtual PMSInt32 select_oa_5F_parser_13 (C_Lexique_oa_5F_scanner *) ;

  public : virtual PMSInt32 select_oa_5F_parser_14 (C_Lexique_oa_5F_scanner *) ;
} ;

//-----------------------------------------------------------------------------*

#endif
