//---------------------------------------------------------------------------*
//                                                                           *
//                            File 'oa_parser.h'                             *
//             Generated by version version GALGAS_BETA_VERSION              *
//                    february 18th, 2012, at 11h31'51"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef oa_parser_ENTITIES_DEFINED
#define oa_parser_ENTITIES_DEFINED

//---------------------------------------------------------------------------*

#include "galgas2/predefined-types.h"

//---------------------------------------------------------------------------*

#include "oa_scanner.h"

//---------------------------------------------------------------------------*

#include "oa_semantics.h"

//---------------------------------------------------------------------------*

class GALGAS__32_stringlist ;
class GALGAS_AC_5F_canMessage ;
class GALGAS_AC_5F_task ;
class GALGAS_C_5F_canIndependantMessage ;
class GALGAS_C_5F_canMessageFromMessage ;
class GALGAS_C_5F_canMessageFromTask ;
class GALGAS_C_5F_independantTask ;
class GALGAS_C_5F_taskDependsFromMessage ;
class GALGAS_C_5F_taskDependsFromTask ;
class GALGAS_M_5F_messages ;
class GALGAS_M_5F_network ;
class GALGAS_M_5F_processor ;
class GALGAS_M_5F_tasks ;
class GALGAS_application ;
class GALGAS_binaryset ;
class GALGAS_bool ;
class GALGAS_char ;
class GALGAS_data ;
class GALGAS_double ;
class GALGAS_filewrapper ;
class GALGAS_function ;
class GALGAS_functionlist ;
class GALGAS_lbool ;
class GALGAS_lchar ;
class GALGAS_ldouble ;
class GALGAS_location ;
class GALGAS_lsint ;
class GALGAS_lsint_36__34_ ;
class GALGAS_lstring ;
class GALGAS_lstringlist ;
class GALGAS_luint ;
class GALGAS_luint_36__34_ ;
class GALGAS_luintlist ;
class GALGAS_object ;
class GALGAS_objectlist ;
class GALGAS_range ;
class GALGAS_sint ;
class GALGAS_sint_36__34_ ;
class GALGAS_string ;
class GALGAS_stringlist ;
class GALGAS_stringset ;
class GALGAS_type ;
class GALGAS_typelist ;
class GALGAS_uint ;
class GALGAS_uint_36__34_ ;
class GALGAS_uint_36__34_list ;
class GALGAS_uintlist ;

//---------------------------------------------------------------------------*
//                                                                           *
//                   Parser class 'oa_parser' declaration                    *
//                                                                           *
//---------------------------------------------------------------------------*

class cParser_oa_5F_parser {
//--- Virtual destructor
  public : virtual ~ cParser_oa_5F_parser (void) {}

//--- Non terminal declarations
  protected : virtual void nt_axiome_ (C_Lexique_oa_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_axiome_parse (C_Lexique_oa_5F_scanner * inLexique) = 0 ;


//--- Rule declarations
  protected : void rule_oa_5F_parser_axiome_i0_ (C_Lexique_oa_5F_scanner * inLexique) ;

  protected : void rule_oa_5F_parser_axiome_i0_parse (C_Lexique_oa_5F_scanner * inLexique) ;



//--- Select methods
  protected : virtual PMSInt32 select_oa_5F_parser_0 (C_Lexique_oa_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_oa_5F_parser_1 (C_Lexique_oa_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_oa_5F_parser_2 (C_Lexique_oa_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_oa_5F_parser_3 (C_Lexique_oa_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_oa_5F_parser_4 (C_Lexique_oa_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_oa_5F_parser_5 (C_Lexique_oa_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_oa_5F_parser_6 (C_Lexique_oa_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_oa_5F_parser_7 (C_Lexique_oa_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_oa_5F_parser_8 (C_Lexique_oa_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_oa_5F_parser_9 (C_Lexique_oa_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_oa_5F_parser_10 (C_Lexique_oa_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_oa_5F_parser_11 (C_Lexique_oa_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_oa_5F_parser_12 (C_Lexique_oa_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_oa_5F_parser_13 (C_Lexique_oa_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_oa_5F_parser_14 (C_Lexique_oa_5F_scanner *) = 0 ;


} ;

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

#endif
