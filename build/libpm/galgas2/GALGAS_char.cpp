//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//   GALGAS_char                                                                                                       *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2002, ..., 2016 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@ec-nantes.fr                                                                              *
//                                                                                                                     *
//  LS2N, Laboratoire des Sciences du Numérique de Nantes, ECN, École Centrale de Nantes (France)                      *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.                                                                                                 *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for            *
//  more details.                                                                                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#include "all-predefined-types.h"
#include "galgas2/C_Compiler.h"
#include "strings/unicode_character_cpp.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#if COMPILE_FOR_WINDOWS == 0
  #include <termios.h>
  #include <string.h>
  #include <unistd.h>
  #include <sys/ioctl.h>
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_char::GALGAS_char (void) :
AC_GALGAS_root (),
mIsValid (false),
mCharValue (TO_UNICODE (0)) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_char GALGAS_char::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_char (TO_UNICODE (0)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#if COMPILE_FOR_WINDOWS == 1
  GALGAS_char GALGAS_char::constructor_unicodeCharacterFromRawKeyboard (C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
    inCompiler->onTheFlyRunTimeError (
      "@char unicodeCharacterFromRawKeyboard constructor is not implemented for Windows"
      COMMA_THERE
    ) ;
    return GALGAS_char () ; // Poison value
  }
#endif

//----------------------------------------------------------------------------------------------------------------------

#if COMPILE_FOR_WINDOWS == 0
  static void waitForRawInput (void) {
    bool waiting = true ;
    while (waiting) {
      int bytesAvailable = 0 ;
      ioctl (STDIN_FILENO, FIONREAD, & bytesAvailable) ;
      waiting = bytesAvailable == 0 ;
      if (waiting) {
        usleep (10000) ; // 10 ms
      }
    }
  }
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#if COMPILE_FOR_WINDOWS == 0
  GALGAS_char GALGAS_char::constructor_unicodeCharacterFromRawKeyboard (C_Compiler * /* inCompiler */
                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  //--- Save current configuration
    struct termios termios_orig ;
    tcgetattr (STDIN_FILENO, &termios_orig) ;
  //--- Set new configuration
    struct termios raw ;
    tcgetattr (STDIN_FILENO, &raw) ;
    cfmakeraw (& raw) ;
    raw.c_oflag = OPOST | OCRNL ;
    raw.c_iflag = 0 ;
    raw.c_lflag = ISIG ;
    tcsetattr (STDIN_FILENO, TCSANOW, & raw);
  //--- Wait for input character
    waitForRawInput () ;
  //--- Get character
    uint8_t c = '\0' ;
    ssize_t unusedResult __attribute__ ((unused)) = read (STDIN_FILENO, & c, 1) ;
  //--- ASCII ?
    uint32_t unicodeChar = c ;
    if ((unicodeChar & 0xE0) == 0xC0) { // 2 bytes
      unicodeChar &= 0x1F ;
      unicodeChar <<= 6 ;
      waitForRawInput () ;
      unusedResult = read (STDIN_FILENO, & c, 1) ;
      c &= 0x3F ;
      unicodeChar |= c ;
    }else if ((unicodeChar & 0xF0) == 0xE0) { // 3 bytes
      unicodeChar &= 0x0F ;
      unicodeChar <<= 6 ;
      waitForRawInput () ;
      unusedResult = read (STDIN_FILENO, & c, 1) ;
      c &= 0x3F ;
      unicodeChar |= c ;
      unicodeChar <<= 6 ;
      waitForRawInput () ;
      unusedResult = read (STDIN_FILENO, & c, 1) ;
      c &= 0x3F ;
      unicodeChar |= c ;
    }else if ((unicodeChar & 0xF8) == 0xF0) { // 4 bytes
      unicodeChar &= 0x0F ;
      unicodeChar <<= 6 ;
      waitForRawInput () ;
      unusedResult = read (STDIN_FILENO, & c, 1) ;
      c &= 0x3F ;
      unicodeChar |= c ;
      unicodeChar <<= 6 ;
      waitForRawInput () ;
      unusedResult = read (STDIN_FILENO, & c, 1) ;
      c &= 0x3F ;
      unicodeChar |= c ;
      unicodeChar <<= 6 ;
      waitForRawInput () ;
      unusedResult = read (STDIN_FILENO, & c, 1) ;
      c &= 0x3F ;
      unicodeChar |= c ;
    }
  //--- Restore configuration
    tcsetattr (STDIN_FILENO, TCSANOW, &termios_orig) ;
  //--- Return input character
    return GALGAS_char (TO_UNICODE (unicodeChar)) ;
  }
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_char::GALGAS_char (const utf32 inValue) :
AC_GALGAS_root (),
mIsValid (true),
mCharValue (inValue) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typeComparisonResult GALGAS_char::objectCompare (const GALGAS_char & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t r = ((int32_t) UNICODE_VALUE (mCharValue)) - ((int32_t) UNICODE_VALUE (inOperand.mCharValue)) ;
    if (r < 0) {
      result = kFirstOperandLowerThanSecond ;
    }else if (r > 0) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = kOperandEqual ;
    }
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_char::description (C_String & ioString,
                               const int32_t /* inIndentation */) const {
  ioString << "<@char:" ;
  if (isValid ()) {
    if (isprint ((int) UNICODE_VALUE (mCharValue))) {
      ioString << "'" ;
      ioString.appendUnicodeCharacter (mCharValue COMMA_HERE) ;
      ioString << "'" ;
    }else{
      ioString << unicodeName (mCharValue) ;
    }
  }else{
    ioString << "not built" ;
  }
  ioString << ">" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_string GALGAS_char::getter_string (LOCATION_ARGS) const {
  C_String s ;
  s.appendUnicodeCharacter (mCharValue COMMA_THERE) ;
  return GALGAS_string (s) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_string GALGAS_char::getter_utf_33__32_CharConstantRepresentation (UNUSED_LOCATION_ARGS) const {
  C_String s ;
  s.appendCString ("TO_UNICODE (") ;
  s.appendCLiteralCharConstant (mCharValue) ;
  s.appendCString (")") ;
  return GALGAS_string (s) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint GALGAS_char::getter_uint (UNUSED_LOCATION_ARGS) const {
  return GALGAS_uint (UNICODE_VALUE (mCharValue)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_bool GALGAS_char::getter_isalnum (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (
      ((UNICODE_VALUE (mCharValue) >= '0') && (UNICODE_VALUE (mCharValue) <= '9'))
   || ((UNICODE_VALUE (mCharValue) >= 'a') && (UNICODE_VALUE (mCharValue) <= 'z'))
   || ((UNICODE_VALUE (mCharValue) >= 'A') && (UNICODE_VALUE (mCharValue) <= 'Z'))
  ) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_bool GALGAS_char::getter_isalpha (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (((UNICODE_VALUE (mCharValue) >= 'a') && (UNICODE_VALUE (mCharValue) <= 'z'))
                             || ((UNICODE_VALUE (mCharValue) >= 'A') && (UNICODE_VALUE (mCharValue) <= 'Z'))) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_bool GALGAS_char::getter_iscntrl (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (((UNICODE_VALUE (mCharValue) >= 1) && (UNICODE_VALUE (mCharValue) <= 31)) || (UNICODE_VALUE (mCharValue) == 127)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_bool GALGAS_char::getter_isdigit (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool  (((UNICODE_VALUE (mCharValue) >= '0') && (UNICODE_VALUE (mCharValue) <= '9'))) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_bool GALGAS_char::getter_islower (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (((UNICODE_VALUE (mCharValue) >= 'a') && (UNICODE_VALUE (mCharValue) <= 'z'))) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_bool GALGAS_char::getter_isupper (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (((UNICODE_VALUE (mCharValue) >= 'A') && (UNICODE_VALUE (mCharValue) <= 'Z'))) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_bool GALGAS_char::getter_isxdigit (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (((UNICODE_VALUE (mCharValue) >= '0') && (UNICODE_VALUE (mCharValue) <= '9')) 
                             || ((UNICODE_VALUE (mCharValue) >= 'a') && (UNICODE_VALUE (mCharValue) <= 'f'))
                             || ((UNICODE_VALUE (mCharValue) >= 'A') && (UNICODE_VALUE (mCharValue) <= 'F'))) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_bool GALGAS_char::getter_isUnicodeLetter (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (isUnicodeLetter (mCharValue)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_bool GALGAS_char::getter_isUnicodeMark (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (isUnicodeMark  (mCharValue)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_bool GALGAS_char::getter_isUnicodeSymbol (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (isUnicodeCommand (mCharValue)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_bool GALGAS_char::getter_isUnicodeCommand (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (isUnicodeCommand (mCharValue)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_bool GALGAS_char::getter_isUnicodeSeparator (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (isUnicodeSeparator (mCharValue)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_bool GALGAS_char::getter_isUnicodePunctuation (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (isUnicodePunctuation (mCharValue)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_bool GALGAS_char::getter_isUnicodeNumber (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (isUnicodeNumber (mCharValue)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_string GALGAS_char::getter_unicodeName (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (unicodeName (mCharValue)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_char GALGAS_char::getter_unicodeToLower (UNUSED_LOCATION_ARGS) const {
  return GALGAS_char (unicodeToLower (mCharValue)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_char GALGAS_char::getter_unicodeToUpper (UNUSED_LOCATION_ARGS) const {
  return GALGAS_char (unicodeToUpper (mCharValue)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_char GALGAS_char::constructor_unicodeCharacterWithUnsigned (const GALGAS_uint & inValue
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_char result ;
  if (inValue.isValid ()) {
    result = GALGAS_char (TO_UNICODE (inValue.uintValue ())) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_char GALGAS_char::constructor_replacementCharacter (UNUSED_LOCATION_ARGS) {
  return GALGAS_char (UNICODE_REPLACEMENT_CHARACTER) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
