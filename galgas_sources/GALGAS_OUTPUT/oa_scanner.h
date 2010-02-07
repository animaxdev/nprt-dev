//---------------------------------------------------------------------------*
//                                                                           *
//                           File 'oa_scanner.h'                             *
//                 Generated by version GALGAS_BETA_VERSION                  *
//                     february 7th, 2010, at 20h59'25"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1


#ifndef oa_5F_scanner_0_DEFINED
#define oa_5F_scanner_0_DEFINED

//---------------------------------------------------------------------------*

#include "galgas/GGS_lstring.h"
#include "galgas/GGS_luint.h"
#include "galgas/GGS_lsint.h"
#include "galgas/GGS_luint64.h"
#include "galgas/GGS_lsint64.h"
#include "galgas/GGS_lchar.h"
#include "galgas/GGS_ldouble.h"
#include "galgas/GGS_lbool.h"
#include "galgas-utilities/C_Lexique.h"

//---------------------------------------------------------------------------*
//                                                                           *
//                    E X T E R N    R O U T I N E S                         *
//                                                                           *
//---------------------------------------------------------------------------*

//---------------------------------------------------------------------------*
//                                                                           *
//                    E X T E R N    F U N C T I O N S                       *
//                                                                           *
//---------------------------------------------------------------------------*

//---------------------------------------------------------------------------*
//                                                                           *
//                       T O K E N    C L A S S                              *
//                                                                           *
//---------------------------------------------------------------------------*

class cTokenFor_oa_5F_scanner : public cToken {
  public : C_String mLexicalAttribute_identifierString ;
  public : PMUInt32 mLexicalAttribute_ulongValue ;

  public : cTokenFor_oa_5F_scanner (void) ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                     S C A N N E R    C L A S S                            *
//                                                                           *
//---------------------------------------------------------------------------*

class C_Lexique_oa_5F_scanner : public C_Lexique {
//--- Constructors
  public : C_Lexique_oa_5F_scanner (C_Compiler * inCallerCompiler,
                       const C_String & inDependencyFileExtension,
                       const C_String & inDependencyFilePath,
                       C_galgas_io * inParametersPtr,
                       const C_String & inSourceFileName
                       COMMA_LOCATION_ARGS) ;

  public : C_Lexique_oa_5F_scanner (C_Compiler * inCallerCompiler,
                       C_galgas_io * inParametersPtr,
                       const C_String & inSourceString,
                       const C_String & inStringForError
                       COMMA_LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_GGS_Object::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected : virtual ~ C_Lexique_oa_5F_scanner (void) {}
  #endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2


//--- Terminal symbols enumeration
  public : enum {kToken_,
   kToken_identifier,
   kToken_literal_5F_integer,
   kToken_system,
   kToken_end,
   kToken_task,
   kToken_standard,
   kToken_extended,
   kToken_message,
   kToken_length,
   kToken_priority,
   kToken_period,
   kToken_offset,
   kToken_on,
   kToken_deadline,
   kToken_duration,
   kToken_processor,
   kToken_can,
   kToken_van,
   kToken_network,
   kToken_scalingfactor,
   kToken_every,
   kToken__2C_,
   kToken__3B_,
   kToken__2E__2E_} ;

//--- Key words table 'keyWordList'
  public : static PMSInt16 search_into_keyWordList (const C_String & inSearchedString) ;

//--- Key words table 'delimitorsList'
  public : static PMSInt16 search_into_delimitorsList (const C_String & inSearchedString) ;
  

//--- Assign from attribute
  public : void assignFromAttribute_identifierString (GGS_lstring & outValue) const ;
  public : void assignFromAttribute_ulongValue (GGS_luint & outValue) const ;


//--- Attribute access
  public : C_String attributeValue_identifierString (void) const ;
  public : PMUInt32 attributeValue_ulongValue (void) const ;


//--- Parse lexical token
  protected : virtual bool parseLexicalToken (void) ;

//--- Append terminal message
  protected : virtual void appendTerminalMessageToSyntaxErrorMessage (const PMSInt16 numeroTerminal,
                                                              C_String & messageErreur) ;

//--- Get terminal count
  public : virtual PMSInt16 terminalVocabularyCount (void) const { return 24 ; }

//--- Get Token String
  public : virtual C_String getCurrentTokenString (const cToken * inTokenPtr) const ;

//--- Enter Token
  protected : void enterToken (const cTokenFor_oa_5F_scanner & inToken) ;
} ;

//---------------------------------------------------------------------------*

#endif
