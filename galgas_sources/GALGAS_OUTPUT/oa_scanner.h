//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                File 'oa_scanner.h'                                                  *
//                                             Generated by version 2.7.0                                              *
//                                           august 8th, 2014, at 20h3'48"                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1


#ifndef oa_5F_scanner_CLASS_DEFINED
#define oa_5F_scanner_CLASS_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "galgas2/C_Lexique.h"
#include "galgas2/predefined-types.h"

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                    E X T E R N    R O U T I N E S                                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                    E X T E R N    F U N C T I O N S                                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       T O K E N    C L A S S                                                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cTokenFor_oa_5F_scanner : public cToken {
  public : C_String mLexicalAttribute_identifierString ;
  public : uint32_t mLexicalAttribute_ulongValue ;

  public : cTokenFor_oa_5F_scanner (void) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                     S C A N N E R    C L A S S                                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class C_Lexique_oa_5F_scanner : public C_Lexique {
//--- Constructors
  public : C_Lexique_oa_5F_scanner (C_Compiler * inCallerCompiler,
                       const C_String & inDependencyFileExtension,
                       const C_String & inDependencyFilePath,
                       const C_String & inSourceFileName
                       COMMA_LOCATION_ARGS) ;

  public : C_Lexique_oa_5F_scanner (C_Compiler * inCallerCompiler,
                       const C_String & inSourceString,
                       const C_String & inStringForError
                       COMMA_LOCATION_ARGS) ;

//--- Instrospection
  public : static GALGAS_stringlist symbols (LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_SharedObject::detachPointer may invoke delete.
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
  public : static int16_t search_into_keyWordList (const C_String & inSearchedString) ;

//--- Key words table 'delimitorsList'
  public : static int16_t search_into_delimitorsList (const C_String & inSearchedString) ;
  

//--- Assign from attribute
  public : GALGAS_lstring synthetizedAttribute_identifierString (void) const ;
  public : GALGAS_luint synthetizedAttribute_ulongValue (void) const ;


//--- Attribute access
  public : C_String attributeValue_identifierString (void) const ;
  public : uint32_t attributeValue_ulongValue (void) const ;


//--- Indexing keys

//--- Indexing directory
  protected : virtual C_String indexingDirectory (void) const ;

//--- Parse lexical token
  protected : virtual bool parseLexicalToken (void) ;

//--- Get terminal message
  protected : virtual C_String getMessageForTerminal (const int16_t inTerminalSymbol) const ;

//--- Get terminal count
  public : virtual int16_t terminalVocabularyCount (void) const { return 24 ; }

//--- Get Token String
  public : virtual C_String getCurrentTokenString (const cToken * inTokenPtr) const ;

//--- Enter Token
  protected : void enterToken (const cTokenFor_oa_5F_scanner & inToken) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

#endif
