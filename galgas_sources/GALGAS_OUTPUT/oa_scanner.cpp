//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'oa_scanner.cpp'                            *
//         Generated by version GALGAS_BETA_VERSION (LL(1) grammar)          *
//                     december 10th, 2006, at 15h5'5"                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if LIBPM_VERSION != THE_LIBPM_VERSION
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include <ctype.h>
#include <string.h>

#include "utilities/MF_MemoryControl.h"
#include "oa_scanner.h"

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define LINE_AND_SOURCE_FILE sourceText ()->sourceFileName ().cString (), currentLineNumber ()
  #define COMMA_LINE_AND_SOURCE_FILE , LINE_AND_SOURCE_FILE
#else
  #define LINE_AND_SOURCE_FILE
  #define COMMA_LINE_AND_SOURCE_FILE
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//                               Constructor                                 *
//                                                                           *
//---------------------------------------------------------------------------*

oa_scanner::
oa_scanner (AC_galgas_io * inGalgasInputOutput COMMA_LOCATION_ARGS)
: C_Lexique (inGalgasInputOutput COMMA_THERE) {
}

//---------------------------------------------------------------------------*
//                                                                           *
//                        Lexical error message list                         *
//                                                                           *
//---------------------------------------------------------------------------*

//--- Message 0
static const char * gErrorMessage_0 = "decimal number too large" ;
//--- Message 1
static const char * gErrorMessage_1 = "internal error" ;
//--- Message 2
static const char * gErrorMessage_2 = "incorrect end of comment" ;

//---------------------------------------------------------------------------*
//                                                                           *
//                          Syntax error messages                            *
//                                                                           *
//---------------------------------------------------------------------------*

//--- Syntax error message for terminal '$identifier$' :
static const char * gSyntaxErrorMessage_identifier = "an identifier" ;

//--- Syntax error message for terminal '$system$' :
static const char * gSyntaxErrorMessage_system = "the 'system' key word" ;

//--- Syntax error message for terminal '$end$' :
static const char * gSyntaxErrorMessage_end = "the 'end' key word" ;

//--- Syntax error message for terminal '$task$' :
static const char * gSyntaxErrorMessage_task = "the 'task' key word" ;

//--- Syntax error message for terminal '$standard$' :
static const char * gSyntaxErrorMessage_standard = "the 'standard' key word" ;

//--- Syntax error message for terminal '$extended$' :
static const char * gSyntaxErrorMessage_extended = "the 'extended' key word" ;

//--- Syntax error message for terminal '$message$' :
static const char * gSyntaxErrorMessage_message = "the 'message' key word" ;

//--- Syntax error message for terminal '$length$' :
static const char * gSyntaxErrorMessage_length = "the 'length' key word" ;

//--- Syntax error message for terminal '$priority$' :
static const char * gSyntaxErrorMessage_priority = "the 'priority' key word" ;

//--- Syntax error message for terminal '$period$' :
static const char * gSyntaxErrorMessage_period = "the 'period' key word" ;

//--- Syntax error message for terminal '$offset$' :
static const char * gSyntaxErrorMessage_offset = "the 'offset' key word" ;

//--- Syntax error message for terminal '$on$' :
static const char * gSyntaxErrorMessage_on = "the 'on' key word" ;

//--- Syntax error message for terminal '$deadline$' :
static const char * gSyntaxErrorMessage_deadline = "the 'deadline' key word" ;

//--- Syntax error message for terminal '$duration$' :
static const char * gSyntaxErrorMessage_duration = "the 'duration' key word" ;

//--- Syntax error message for terminal '$processor$' :
static const char * gSyntaxErrorMessage_processor = "the 'processor' key word" ;

//--- Syntax error message for terminal '$can$' :
static const char * gSyntaxErrorMessage_can = "the 'can' key word" ;

//--- Syntax error message for terminal '$van$' :
static const char * gSyntaxErrorMessage_van = "the 'van' key word" ;

//--- Syntax error message for terminal '$network$' :
static const char * gSyntaxErrorMessage_network = "the 'network' key word" ;

//--- Syntax error message for terminal '$scalingfactor$' :
static const char * gSyntaxErrorMessage_scalingfactor = "the 'scalingfactor' key word" ;

//--- Syntax error message for terminal '$every$' :
static const char * gSyntaxErrorMessage_every = "the 'every' key word" ;

//--- Syntax error message for terminal '$,$' :
static const char * gSyntaxErrorMessage__2C = "the '','' delimitor" ;

//--- Syntax error message for terminal '$;$' :
static const char * gSyntaxErrorMessage__3B = "the '';'' delimitor" ;

//--- Syntax error message for terminal '$..$' :
static const char * gSyntaxErrorMessage__2E_2E = "the ''..'' delimitor" ;

//--- Syntax error message for terminal '$literal_integer$' :
static const char * gSyntaxErrorMessage_literal_5Finteger = "a decimal number" ;

//---------------------------------------------------------------------------*
//                                                                           *
//                appendTerminalMessageToSyntaxErrorMessage                  *
//                                                                           *
//---------------------------------------------------------------------------*

void oa_scanner::
appendTerminalMessageToSyntaxErrorMessage (const sint16 inTerminalIndex,
                                           C_String & outSyntaxErrorMessage) {
  static const char * syntaxErrorMessageArray [25] = {"end of source",
       gSyntaxErrorMessage_identifier,
       gSyntaxErrorMessage_system,
       gSyntaxErrorMessage_end,
       gSyntaxErrorMessage_task,
       gSyntaxErrorMessage_standard,
       gSyntaxErrorMessage_extended,
       gSyntaxErrorMessage_message,
       gSyntaxErrorMessage_length,
       gSyntaxErrorMessage_priority,
       gSyntaxErrorMessage_period,
       gSyntaxErrorMessage_offset,
       gSyntaxErrorMessage_on,
       gSyntaxErrorMessage_deadline,
       gSyntaxErrorMessage_duration,
       gSyntaxErrorMessage_processor,
       gSyntaxErrorMessage_can,
       gSyntaxErrorMessage_van,
       gSyntaxErrorMessage_network,
       gSyntaxErrorMessage_scalingfactor,
       gSyntaxErrorMessage_every,
       gSyntaxErrorMessage__2C,
       gSyntaxErrorMessage__3B,
       gSyntaxErrorMessage__2E_2E,
       gSyntaxErrorMessage_literal_5Finteger} ;
  outSyntaxErrorMessage << syntaxErrorMessageArray [inTerminalIndex] ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                     Key words table 'delimitorsList'                      *
//                                                                           *
//---------------------------------------------------------------------------*

const sint16 oa_scanner::oa_scanner_table_size_delimitorsList = 3 ;

const C_lexique_table_entry oa_scanner::oa_scanner_table_for_delimitorsList [3] = {
  C_lexique_table_entry (",", 1, oa_scanner_1__2C),
  C_lexique_table_entry (";", 1, oa_scanner_1__3B),
  C_lexique_table_entry ("..", 2, oa_scanner_1__2E_2E)
} ;

sint16 oa_scanner::search_into_delimitorsList (const C_String & inSearchedString) {
  return searchInList (inSearchedString, oa_scanner_table_for_delimitorsList, oa_scanner_table_size_delimitorsList) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                      Key words table 'keyWordList'                        *
//                                                                           *
//---------------------------------------------------------------------------*

const sint16 oa_scanner::oa_scanner_table_size_keyWordList = 19 ;

const C_lexique_table_entry oa_scanner::oa_scanner_table_for_keyWordList [19] = {
  C_lexique_table_entry ("on", 2, oa_scanner_1_on),
  C_lexique_table_entry ("can", 3, oa_scanner_1_can),
  C_lexique_table_entry ("end", 3, oa_scanner_1_end),
  C_lexique_table_entry ("van", 3, oa_scanner_1_van),
  C_lexique_table_entry ("task", 4, oa_scanner_1_task),
  C_lexique_table_entry ("every", 5, oa_scanner_1_every),
  C_lexique_table_entry ("length", 6, oa_scanner_1_length),
  C_lexique_table_entry ("offset", 6, oa_scanner_1_offset),
  C_lexique_table_entry ("period", 6, oa_scanner_1_period),
  C_lexique_table_entry ("system", 6, oa_scanner_1_system),
  C_lexique_table_entry ("message", 7, oa_scanner_1_message),
  C_lexique_table_entry ("network", 7, oa_scanner_1_network),
  C_lexique_table_entry ("deadline", 8, oa_scanner_1_deadline),
  C_lexique_table_entry ("duration", 8, oa_scanner_1_duration),
  C_lexique_table_entry ("extended", 8, oa_scanner_1_extended),
  C_lexique_table_entry ("priority", 8, oa_scanner_1_priority),
  C_lexique_table_entry ("standard", 8, oa_scanner_1_standard),
  C_lexique_table_entry ("processor", 9, oa_scanner_1_processor),
  C_lexique_table_entry ("scalingfactor", 13, oa_scanner_1_scalingfactor)
} ;

sint16 oa_scanner::search_into_keyWordList (const C_String & inSearchedString) {
  return searchInList (inSearchedString, oa_scanner_table_for_keyWordList, oa_scanner_table_size_keyWordList) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                          getCurrentTokenString                            *
//                                                                           *
//---------------------------------------------------------------------------*

C_String oa_scanner::
getCurrentTokenString (const cToken * inTokenPtr) const {
  cTokenFor_oa_scanner * _p = (cTokenFor_oa_scanner *) inTokenPtr ;
  C_String s ;
  switch (_p->_mTokenCode) {
  case  oa_scanner_1_:
    s << "$$" ;
    break ;
  case  oa_scanner_1_identifier:
    s << '$'
      << "identifier"
      << '$' ;
    s << ' ' ;
    s.writeCstringConstant (_p->identifierString) ;
    break;
  case  oa_scanner_1_system:
    s << '$'
      << "system"
      << '$' ;
    break;
  case  oa_scanner_1_end:
    s << '$'
      << "end"
      << '$' ;
    break;
  case  oa_scanner_1_task:
    s << '$'
      << "task"
      << '$' ;
    break;
  case  oa_scanner_1_standard:
    s << '$'
      << "standard"
      << '$' ;
    break;
  case  oa_scanner_1_extended:
    s << '$'
      << "extended"
      << '$' ;
    break;
  case  oa_scanner_1_message:
    s << '$'
      << "message"
      << '$' ;
    break;
  case  oa_scanner_1_length:
    s << '$'
      << "length"
      << '$' ;
    break;
  case  oa_scanner_1_priority:
    s << '$'
      << "priority"
      << '$' ;
    break;
  case  oa_scanner_1_period:
    s << '$'
      << "period"
      << '$' ;
    break;
  case  oa_scanner_1_offset:
    s << '$'
      << "offset"
      << '$' ;
    break;
  case  oa_scanner_1_on:
    s << '$'
      << "on"
      << '$' ;
    break;
  case  oa_scanner_1_deadline:
    s << '$'
      << "deadline"
      << '$' ;
    break;
  case  oa_scanner_1_duration:
    s << '$'
      << "duration"
      << '$' ;
    break;
  case  oa_scanner_1_processor:
    s << '$'
      << "processor"
      << '$' ;
    break;
  case  oa_scanner_1_can:
    s << '$'
      << "can"
      << '$' ;
    break;
  case  oa_scanner_1_van:
    s << '$'
      << "van"
      << '$' ;
    break;
  case  oa_scanner_1_network:
    s << '$'
      << "network"
      << '$' ;
    break;
  case  oa_scanner_1_scalingfactor:
    s << '$'
      << "scalingfactor"
      << '$' ;
    break;
  case  oa_scanner_1_every:
    s << '$'
      << "every"
      << '$' ;
    break;
  case  oa_scanner_1__2C:
    s << '$'
      << ","
      << '$' ;
    break;
  case  oa_scanner_1__3B:
    s << '$'
      << ";"
      << '$' ;
    break;
  case  oa_scanner_1__2E_2E:
    s << '$'
      << ".."
      << '$' ;
    break;
  case  oa_scanner_1_literal_5Finteger:
    s << '$'
      << "literal_integer"
      << '$' ;
    s << ' ' << _p->ulongValue ;
    break;
  default:
    break ;
  }
  return s ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                            parseLexicalToken                              *
//                                                                           *
//---------------------------------------------------------------------------*

bool oa_scanner::
parseLexicalToken (void) {
  cTokenFor_oa_scanner _token ;
  bool loop_ = true ;
  _token._mTokenCode = -1 ;
  while (_token._mTokenCode < 0) {
    _token.identifierString.clear () ;
    _token.ulongValue = 0 ;
    mCurrentTokenStartLocation = currentLocation () ;
    try{
      if (testForInputChar ('a', 'z') ||
          testForInputChar ('A', 'Z')) {
        do {
          scanner_action_enterCharacterIntoString (_token.identifierString, previousChar ()) ;
          if (testForInputChar ('a', 'z') ||
              testForInputChar ('A', 'Z') ||
              testForInputChar ('_') ||
              testForInputChar ('0', '9')) {
          }else{
            loop_ = false ;
          }
        }while (loop_) ;
        loop_ = true ;
        _token._mTokenCode = search_into_keyWordList (_token.identifierString) ;
        if (_token._mTokenCode == -1) {
          _token._mTokenCode = oa_scanner_1_identifier ;
        }
        _enterToken (_token) ;
      }else if (testForInputString ("..", 2)) {
        _token._mTokenCode = oa_scanner_1__2E_2E ;
        _enterToken (_token) ;
      }else if (testForInputString (",", 1)) {
        _token._mTokenCode = oa_scanner_1__2C ;
        _enterToken (_token) ;
      }else if (testForInputString (";", 1)) {
        _token._mTokenCode = oa_scanner_1__3B ;
        _enterToken (_token) ;
      }else if (testForInputChar ('0', '9')) {
        scanner_action_enterDigitIntoUlong (_token.ulongValue, previousChar (), gErrorMessage_0, gErrorMessage_1) ;
        do {
          if (testForInputChar ('0', '9')) {
            scanner_action_enterDigitIntoUlong (_token.ulongValue, previousChar (), gErrorMessage_0, gErrorMessage_1) ;
          }else if (testForInputChar ('_')) {
          }else{
            loop_ = false ;
          }
        }while (loop_) ;
        loop_ = true ;
        _token._mTokenCode = oa_scanner_1_literal_5Finteger ;
        _enterToken (_token) ;
      }else if (testForInputChar ('\x1', ' ')) {
      }else if (testForInputChar ('#')) {
        do {
          if (testForInputChar ('\x1', '\t') ||
              testForInputChar ('\v', '\xFF')) {
          }else{
            loop_ = false ;
          }
        }while (loop_) ;
        loop_ = true ;
        if (testForInputChar ('\n')) {
        }else{
          lexicalError (gErrorMessage_2 COMMA_LINE_AND_SOURCE_FILE) ;
        }
      }else if (testForInputChar ('\0')) { // End of source text ? 
        _token._mTokenCode = oa_scanner_1_ ; // Empty string code
      }else{ // Unknown input character
        unknownCharacterLexicalError (LINE_AND_SOURCE_FILE) ;
      }
    }catch (const C_lexicalErrorException &) {
      _token._mTokenCode = -1 ; // No token
      advance () ; // ... go throught unknown character
    }
  }
  return _token._mTokenCode > 0 ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                   parseLexicalTokenForLexicalColoring                     *
//                                                                           *
//---------------------------------------------------------------------------*

sint16 oa_scanner::
parseLexicalTokenForLexicalColoring (void) {
  cTokenFor_oa_scanner _token ;
  bool loop_ = true ;
  _token._mTokenCode = -1 ;
  while (_token._mTokenCode < 0) {
    _token.identifierString.clear () ;
    _token.ulongValue = 0 ;
    mCurrentTokenStartLocation = currentLocation () ;
    try{
      if (testForInputChar ('a', 'z') ||
          testForInputChar ('A', 'Z')) {
        do {
          scanner_action_enterCharacterIntoString (_token.identifierString, previousChar ()) ;
          if (testForInputChar ('a', 'z') ||
              testForInputChar ('A', 'Z') ||
              testForInputChar ('_') ||
              testForInputChar ('0', '9')) {
          }else{
            loop_ = false ;
          }
        }while (loop_) ;
        loop_ = true ;
        _token._mTokenCode = search_into_keyWordList (_token.identifierString) ;
        if (_token._mTokenCode == -1) {
          _token._mTokenCode = oa_scanner_1_identifier ;
        }
      }else if (testForInputString ("..", 2)) {
        _token._mTokenCode = oa_scanner_1__2E_2E ;
      }else if (testForInputString (",", 1)) {
        _token._mTokenCode = oa_scanner_1__2C ;
      }else if (testForInputString (";", 1)) {
        _token._mTokenCode = oa_scanner_1__3B ;
      }else if (testForInputChar ('0', '9')) {
        scanner_action_enterDigitIntoUlong (_token.ulongValue, previousChar (), gErrorMessage_0, gErrorMessage_1) ;
        do {
          if (testForInputChar ('0', '9')) {
            scanner_action_enterDigitIntoUlong (_token.ulongValue, previousChar (), gErrorMessage_0, gErrorMessage_1) ;
          }else if (testForInputChar ('_')) {
          }else{
            loop_ = false ;
          }
        }while (loop_) ;
        loop_ = true ;
        _token._mTokenCode = oa_scanner_1_literal_5Finteger ;
      }else if (testForInputChar ('\x1', ' ')) {
      }else if (testForInputChar ('#')) {
        do {
          if (testForInputChar ('\x1', '\t') ||
              testForInputChar ('\v', '\xFF')) {
          }else{
            loop_ = false ;
          }
        }while (loop_) ;
        loop_ = true ;
        if (testForInputChar ('\n')) {
        }else{
          lexicalError (gErrorMessage_2 COMMA_LINE_AND_SOURCE_FILE) ;
        }
      }else if (testForInputChar ('\0')) { // End of source text ? 
        _token._mTokenCode = oa_scanner_1_ ; // Empty string code
      }else{ // Unknown input character
        unknownCharacterLexicalError (LINE_AND_SOURCE_FILE) ;
      }
    }catch (const C_lexicalErrorException &) {
      _token._mTokenCode = -1 ; // No token
      advance () ; // ... go throught unknown character
      throw ;
    }
  }
  return _token._mTokenCode ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                            Styles definition                              *
//                                                                           *
//---------------------------------------------------------------------------*

sint32 oa_scanner::getStylesCount (void) {
  return 5 ;
}

//---------------------------------------------------------------------------*

const char * oa_scanner::getStyleName (const sint32 inIndex) {
  const char * kStylesArray [6] = {"Default style", "Identifiers", "Key words", "Delimitors", "Integer constants", NULL} ;
  return (inIndex < 5) ? kStylesArray [inIndex] : NULL ;
} ;

//---------------------------------------------------------------------------*

const char * oa_scanner::getStyleIdentifier (const sint32 inIndex) {
  const char * kStylesArray [6] = {"", "identifier", "keyWords", "delimitors", "integer_csts", NULL} ;
  return (inIndex < 5) ? kStylesArray [inIndex] : NULL ;
} ;

//---------------------------------------------------------------------------*

uint8 oa_scanner::
terminalStyleIndex (const sint32 inTerminal) {
  static const uint8 kTerminalSymbolStyles [25] = {0,
    1 /* oa_scanner_1_identifier */,
    2 /* oa_scanner_1_system */,
    2 /* oa_scanner_1_end */,
    2 /* oa_scanner_1_task */,
    2 /* oa_scanner_1_standard */,
    2 /* oa_scanner_1_extended */,
    2 /* oa_scanner_1_message */,
    2 /* oa_scanner_1_length */,
    2 /* oa_scanner_1_priority */,
    2 /* oa_scanner_1_period */,
    2 /* oa_scanner_1_offset */,
    2 /* oa_scanner_1_on */,
    2 /* oa_scanner_1_deadline */,
    2 /* oa_scanner_1_duration */,
    2 /* oa_scanner_1_processor */,
    2 /* oa_scanner_1_can */,
    2 /* oa_scanner_1_van */,
    2 /* oa_scanner_1_network */,
    2 /* oa_scanner_1_scalingfactor */,
    2 /* oa_scanner_1_every */,
    3 /* oa_scanner_1__2C */,
    3 /* oa_scanner_1__3B */,
    3 /* oa_scanner_1__2E_2E */,
    4 /* oa_scanner_1_literal_5Finteger */
  } ;
  return kTerminalSymbolStyles [inTerminal] ;
}

//---------------------------------------------------------------------------*

void oa_scanner::_enterToken (const cTokenFor_oa_scanner & inToken) {
  cTokenFor_oa_scanner * _p = NULL ;
  macroMyNew (_p, cTokenFor_oa_scanner ()) ;
  _p->_mTokenCode = inToken._mTokenCode ;
  _p->_mCurrentLocation = _mCurrentLocation ;
  _p->identifierString = inToken.identifierString ;
  _p->ulongValue = inToken.ulongValue ;
  _enterTokenFromPointer (_p) ;
}

//---------------------------------------------------------------------------*

void oa_scanner::
_assignFromAttribute_identifierString (GGS_lstring & outValue) const {
  cTokenFor_oa_scanner * _p = (cTokenFor_oa_scanner *) mCurrentTokenPtr ;
  outValue = GGS_lstring (* this, _p->identifierString) ;
}

//---------------------------------------------------------------------------*

void oa_scanner::
_assignFromAttribute_ulongValue (GGS_luint & outValue) const {
  cTokenFor_oa_scanner * _p = (cTokenFor_oa_scanner *) mCurrentTokenPtr ;
  outValue = GGS_luint (* this, _p->ulongValue) ;
}

//---------------------------------------------------------------------------*

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*

