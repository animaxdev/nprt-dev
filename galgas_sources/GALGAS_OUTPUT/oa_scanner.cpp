//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'oa_scanner.cpp'                            *
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

#include <ctype.h>
#include <string.h>

#include "oa_scanner.h"

#include "galgas/lexical_actions.h" // Generated by 'include "..."'

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                               Constructor                                 *
//                                                                           *
//---------------------------------------------------------------------------*

oa_scanner::
oa_scanner (AC_galgas_io * inGalgasInputOutput)
: C_lexique (inGalgasInputOutput) {
  ulongValue = 0 ;
  identifierString.clearString () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                        Lexical error message list                         *
//                                                                           *
//---------------------------------------------------------------------------*

//--- Message 0 (decimalNumberTooLarge) :
static const char * gErrorMessage_0 = "decimal number too large" ;
//--- Message 1 (internalError) :
static const char * gErrorMessage_1 = "internal error" ;
//--- Message 2 (incorrectEndOfComment) :
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
//--- Syntax error message for terminal '$factor$' :
static const char * gSyntaxErrorMessage_factor = "the 'factor' key word" ;
//--- Syntax error message for terminal '$step$' :
static const char * gSyntaxErrorMessage_step = "the 'step' key word" ;
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

void oa_scanner::
appendTerminalMessageToSyntaxErrorMessage (const sint16 inTerminalIndex,
                                           C_string & outSyntaxErrorMessage) {
  static const char * syntaxErrorMessageArray [26] = {"end of source",
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
       gSyntaxErrorMessage_factor,
       gSyntaxErrorMessage_step,
       gSyntaxErrorMessage_every,
       gSyntaxErrorMessage__2C,
       gSyntaxErrorMessage__3B,
       gSyntaxErrorMessage__2E_2E,
       gSyntaxErrorMessage_literal_5Finteger} ;
  outSyntaxErrorMessage << syntaxErrorMessageArray [inTerminalIndex] ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                      Key words table 'keyWordList'                        *
//                                                                           *
//---------------------------------------------------------------------------*

const sint16 oa_scanner::oa_scanner_table_size_keyWordList = 20 ;

const C_lexique_table_entry oa_scanner::oa_scanner_table_for_keyWordList [20] = {
  C_lexique_table_entry ("on", 2, oa_scanner_1_on),
  C_lexique_table_entry ("can", 3, oa_scanner_1_can),
  C_lexique_table_entry ("end", 3, oa_scanner_1_end),
  C_lexique_table_entry ("van", 3, oa_scanner_1_van),
  C_lexique_table_entry ("step", 4, oa_scanner_1_step),
  C_lexique_table_entry ("task", 4, oa_scanner_1_task),
  C_lexique_table_entry ("every", 5, oa_scanner_1_every),
  C_lexique_table_entry ("factor", 6, oa_scanner_1_factor),
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
  C_lexique_table_entry ("processor", 9, oa_scanner_1_processor)
} ;

sint16 oa_scanner::search_into_keyWordList (const C_string & inSearchedString) {
  return searchInList (inSearchedString, oa_scanner_table_for_keyWordList, oa_scanner_table_size_keyWordList) ;
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

sint16 oa_scanner::search_into_delimitorsList (const C_string & inSearchedString) {
  return searchInList (inSearchedString, oa_scanner_table_for_delimitorsList, oa_scanner_table_size_delimitorsList) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//               Get next token : method 'parseLexicalToken'                 *
//                                                                           *
//---------------------------------------------------------------------------*

void oa_scanner::
parseLexicalToken (const bool inPropagateLexicaleErrorException) {
  bool loop_ = true ;
  mCurrentTokenCode = -1 ;
  ulongValue = 0 ;
  identifierString.clearString () ;
  while (mCurrentTokenCode < 0) {
    mCurrentTokenStartLocation = getCurrentLocation () ;
    try{
      if (testForInputChar ('a', 'z') ||
          testForInputChar ('A', 'Z')) {
        do {
          enterCharacterIntoString (identifierString, getPreviousChar (), * this) ;
          if (testForInputChar ('a', 'z') ||
              testForInputChar ('A', 'Z') ||
              testForInputChar ('_') ||
              testForInputChar ('0', '9')) {
          }else{
            loop_ = false ;
          }
        }while (loop_) ;
        loop_ = true ;
        mCurrentTokenCode = search_into_keyWordList (identifierString) ;
        if (mCurrentTokenCode == -1) {
          mCurrentTokenCode = oa_scanner_1_identifier ;
        }
      }else if (testForInputString ("..", 2)) {
        mCurrentTokenCode = oa_scanner_1__2E_2E ;
      }else if (testForInputString (",", 1)) {
        mCurrentTokenCode = oa_scanner_1__2C ;
      }else if (testForInputString (";", 1)) {
        mCurrentTokenCode = oa_scanner_1__3B ;
      }else if (testForInputChar ('0', '9')) {
        enterDigitIntoUlong (ulongValue, getPreviousChar (), gErrorMessage_0, gErrorMessage_1, * this) ;
        do {
          if (testForInputChar ('0', '9')) {
            enterDigitIntoUlong (ulongValue, getPreviousChar (), gErrorMessage_0, gErrorMessage_1, * this) ;
          }else if (testForInputChar ('_')) {
          }else{
            loop_ = false ;
          }
        }while (loop_) ;
        loop_ = true ;
        mCurrentTokenCode = oa_scanner_1_literal_5Finteger ;
      }else if (testForInputChar (((char) 0x1), ' ')) {
      }else if (testForInputChar ('#')) {
        do {
          if (testForInputChar (((char) 0x1), '\t') ||
              testForInputChar ('\v', ((char) 0xFF))) {
          }else{
            loop_ = false ;
          }
        }while (loop_) ;
        loop_ = true ;
        if (testForInputChar ('\n')) {
        }else{
          lexicalError (gErrorMessage_2) ;
        }
      }else if (testForInputChar ('\0')) { // End of source text ? 
        mCurrentTokenCode = oa_scanner_1_ ; // Empty string code
      }else{ // Unknown input character
        lexicalError ("Unknown character") ;
      }
    }catch (const C_lexicalErrorException &) {
      mCurrentTokenCode = -1 ; // No token
      advance () ; // ... go throught unknown character
      if (inPropagateLexicaleErrorException) {
        throw ;
      }
    }
  }
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

uint8 oa_scanner::
getTerminalStyleIndex (const sint32 inTerminal) {
  static const uint8 kTerminalSymbolStyles [26] = {0,
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
    2 /* oa_scanner_1_factor */,
    2 /* oa_scanner_1_step */,
    2 /* oa_scanner_1_every */,
    3 /* oa_scanner_1__2C */,
    3 /* oa_scanner_1__3B */,
    3 /* oa_scanner_1__2E_2E */,
    4 /* oa_scanner_1_literal_5Finteger */
  } ;
  return kTerminalSymbolStyles [inTerminal] ;
}

//---------------------------------------------------------------------------*

