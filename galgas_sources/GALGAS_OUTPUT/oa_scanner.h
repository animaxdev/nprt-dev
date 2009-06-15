//---------------------------------------------------------------------------*
//                                                                           *
//                           File 'oa_scanner.h'                             *
//                 Generated by version GALGAS_BETA_VERSION                  *
//                       june 15th, 2009, at 15h45'4"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef oa_scanner_0_DEFINED
#define oa_scanner_0_DEFINED

//---------------------------------------------------------------------------*

#include "galgas/GGS_lstring.h"
#include "galgas/GGS_luint.h"
#include "galgas/GGS_lsint.h"
#include "galgas/GGS_luint64.h"
#include "galgas/GGS_lsint64.h"
#include "galgas/GGS_lchar.h"
#include "galgas/GGS_ldouble.h"
#include "galgas/GGS_lbool.h"
#include "galgas/C_Lexique.h"

//---------------------------------------------------------------------------*
//                                                                           *
//                          Lexical scanner class                            *
//                                                                           *
//---------------------------------------------------------------------------*

class cTokenFor_oa_scanner : public cToken {
  public : C_String mLexicalAttribute_identifierString ;
  public : uint32 mLexicalAttribute_ulongValue ;

  public : cTokenFor_oa_scanner (void) ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                          Lexical scanner class                            *
//                                                                           *
//---------------------------------------------------------------------------*

class oa_scanner : public C_Lexique {
//--- Constructors
  public : oa_scanner (C_Compiler * inCallerCompiler,
                       const C_String & inDependencyFileExtension,
                       const C_String & inDependencyFilePath,
                       C_galgas_io * inParametersPtr,
                       const C_String & inSourceFileName
                       COMMA_LOCATION_ARGS) ;

  public : oa_scanner (C_Compiler * inCallerCompiler,
                       C_galgas_io * inParametersPtr,
                       const C_String & inSourceString,
                       const C_String & inStringForError
                       COMMA_LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_GGS_Object::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected : virtual ~oa_scanner (void) {}
  #endif

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//--- Terminal symbols enumeration
  public : enum {oa_scanner_1_,
  oa_scanner_1_identifier,
  oa_scanner_1_system,
  oa_scanner_1_end,
  oa_scanner_1_task,
  oa_scanner_1_standard,
  oa_scanner_1_extended,
  oa_scanner_1_message,
  oa_scanner_1_length,
  oa_scanner_1_priority,
  oa_scanner_1_period,
  oa_scanner_1_offset,
  oa_scanner_1_on,
  oa_scanner_1_deadline,
  oa_scanner_1_duration,
  oa_scanner_1_processor,
  oa_scanner_1_can,
  oa_scanner_1_van,
  oa_scanner_1_network,
  oa_scanner_1_scalingfactor,
  oa_scanner_1_every,
  oa_scanner_1__2C_,
  oa_scanner_1__3B_,
  oa_scanner_1__2E__2E_,
  oa_scanner_1_literal_5F_integer} ;

//--- Key words table 'keyWordList'
  public : static sint16 search_into_keyWordList (const C_String & inSearchedString) ;

//--- Key words table 'delimitorsList'
  public : static sint16 search_into_delimitorsList (const C_String & inSearchedString) ;

  protected : virtual bool parseLexicalToken (void) ;
  protected : virtual sint16 parseLexicalTokenForLexicalColoring (void) ;
  protected : virtual void appendTerminalMessageToSyntaxErrorMessage (const sint16 numeroTerminal,
                                                              C_String & messageErreur) ;

//--- Get attribute values
  public : void assignFromAttribute_identifierString (GGS_lstring & outValue) const ;
  public : C_String attributeValue_identifierString (void) const ;
  public : void assignFromAttribute_ulongValue (GGS_luint & outValue) const ;
  public : uint32 attributeValue_ulongValue (void) const ;
//--- Get terminal count
  public : virtual sint16 terminalVocabularyCount (void) const { return 24 ; }
//--- Get Token String
  public : virtual C_String getCurrentTokenString (const cToken * inTokenPtr) const ;
//--- Enter Token
  protected : void enterToken (const cTokenFor_oa_scanner & inToken) ;
//--- Style Definition
  public : static sint32 getStylesCount (void) ;
  public : static const char * getStyleName (const sint32 inIndex) ;
  public : static const char * getStyleIdentifier (const sint32 inIndex) ;
//--- Virtual method called getting terminal style index
  public : virtual uint8 terminalStyleIndex (const sint32 inTerminal) ;
} ;

//---------------------------------------------------------------------------*

#endif
