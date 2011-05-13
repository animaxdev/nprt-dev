//---------------------------------------------------------------------------*
//                                                                           *
//  'GALGAS_string' : class of galgas string                                 *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 1996, ..., 2010 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//                                                                           *
//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*
//  ECN, Ecole Centrale de Nantes (France)                                   *
//                                                                           *
//  This library is free software; you can redistribute it and/or modify it  *
//  under the terms of the GNU Lesser General Public License as published    *
//  by the Free Software Foundation; either version 2 of the License, or     *
//  (at your option) any later version.                                      *
//                                                                           *
//  This program is distributed in the hope it will be useful, but WITHOUT   *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or    *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for *
//  more details.                                                            *
//                                                                           *
//---------------------------------------------------------------------------*

#include "predefined-types.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "galgas2/C_Compiler.h"
#include "command_line_interface/mainForLIBPM.h"
#include "command_line_interface/F_Analyze_CLI_Options.h"
#include "strings/unicode_character_cpp.h"

//---------------------------------------------------------------------------*

#include <dirent.h>
#include <stdlib.h>
#include <string.h>

//---------------------------------------------------------------------------*
//                                                                           *
//     GALGAS_string                                                         *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_string::GALGAS_string (void) :
mIsValid (false),
mString () {
}

//---------------------------------------------------------------------------*

GALGAS_string::GALGAS_string (const C_String & inString) :
mIsValid (true),
mString (inString) {
  if (traceIsEnabled ()) {
    appendTrace ("string", true, C_String ("'") + inString + "'") ;
  }
}

//---------------------------------------------------------------------------*

void GALGAS_string::drop (void) {
  mIsValid = false ;
  mString.releaseString () ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::makeEmptyString (void) {
  GALGAS_string result ;
  result.mIsValid = true ;
  return result ;
}

//---------------------------------------------------------------------------*

typeComparisonResult GALGAS_string::objectCompare (const GALGAS_string & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const PMSInt32 r = mString.compare (inOperand.mString) ;
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

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::operator_concat (const GALGAS_string & inOperand2
                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_string (mString + inOperand2.mString) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_lstring GALGAS_string::reader_nowhere (LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (isValid ()) {
    result.mAttribute_string = * this ;
    result.mAttribute_location = GALGAS_location::constructor_nowhere (THERE) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_bool GALGAS_string::reader_fileExists (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = GALGAS_bool (mString.fileExists ()) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_bool GALGAS_string::reader_directoryExists (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = GALGAS_bool (mString.directoryExists ()) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_uint GALGAS_string::reader_length (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    result = GALGAS_uint ((PMUInt32) mString.length ()) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::reader_md_35_ (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    result = GALGAS_string (mString.md5 ()) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::reader_utf_33__32_Representation (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    C_String s ;
    s.appendUTF32LiteralStringConstant (mString) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::reader_HTMLRepresentation (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    result = GALGAS_string (mString.HTMLRepresentation ()) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::reader_utf_38_Representation (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    C_String s ;
    s.appendCLiteralStringConstant (mString) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::reader_identifierRepresentation (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    result = GALGAS_string (mString.identifierRepresentation ()) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::reader_rightSubString (const GALGAS_uint & inLength
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (inLength.isValid ()) {
    result = GALGAS_string (mString.rightSubString ((PMSInt32) inLength.uintValue ())) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::reader_leftSubString (const GALGAS_uint & inLength
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (inLength.isValid ()) {
    result = GALGAS_string (mString.leftSubString ((PMSInt32) inLength.uintValue ())) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::reader_subString (const GALGAS_uint & inStart,
                                               const GALGAS_uint & inLength
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if ((inStart.isValid ()) && (inLength.isValid ())) {
    const PMSInt32 start = (PMSInt32) inStart.uintValue () ;
    const PMSInt32 aLength = (PMSInt32) inLength.uintValue () ;
    result = GALGAS_string (mString.subString (start, aLength)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::reader_absolutePathFromPath (const GALGAS_string & inBasePath
                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (inBasePath.isValid ()) {
    const C_String path = mString ;
    const PMSInt32 stringLength = path.length () ;
    C_String r ;
    if ((stringLength > 0) && (UNICODE_VALUE (path (0 COMMA_HERE)) == '/')) {
      r = path ;
    }else{
      r = inBasePath.mString ;
      r.appendUnicodeCharacter (TO_UNICODE ('/') COMMA_HERE) ;
      r.appendString (path) ;
    }
    result = GALGAS_string (r.stringByStandardizingPath ()) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::reader_relativePathFromPath (const GALGAS_string & inReferencePath
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid () && inReferencePath.isValid ()) {
    result = GALGAS_string (mString.relativePathFromPath (inReferencePath.mString)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::reader_stringByStandardizingPath (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.stringByStandardizingPath ()) ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::reader_pathExtension (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.pathExtension ()) ;
}

//---------------------------------------------------------------------------*

GALGAS_char GALGAS_string::reader_firstCharacterOrNul (UNUSED_LOCATION_ARGS) const {
  return GALGAS_char (mString.readCharOrNul (0 COMMA_HERE)) ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::reader_stringByDeletingPathExtension (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.stringByDeletingPathExtension ()) ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::reader_stringByDeletingLastPathComponent (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.stringByDeletingLastPathComponent ()) ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::reader_stringByCapitalizingFirstCharacter (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.stringByCapitalizingFirstCharacter ()) ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::reader_uppercaseString (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.uppercaseString ()) ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::reader_lowercaseString (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.lowercaseString ()) ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::reader_reversedString (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.reversedString ()) ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::reader_stringByTrimmingWhiteSpaces (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.stringByTrimmingWhiteSpaces ()) ;
}

//---------------------------------------------------------------------------*

GALGAS_uint GALGAS_string::reader_currentColumn (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    result = GALGAS_uint (mString.currentColumn ()) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

void GALGAS_string::modifier_appendSpacesUntilColumn (GALGAS_uint inColumnIndex,
                                                      C_Compiler * /* inCompiler */
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  if (isValid () && inColumnIndex.isValid ()) {
    mString.appendSpacesUntilColumn (inColumnIndex.uintValue ()) ;
  }
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::reader_stringByLeftPadding (const GALGAS_uint & inPaddedStringLength,
                                                         const GALGAS_char & inPaddingChar
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if ((inPaddedStringLength.isValid ()) && (inPaddingChar.isValid ())) {
    const utf32 paddingChar = inPaddingChar.charValue () ;
    const PMSInt32 paddedStringLength = (PMSInt32) inPaddedStringLength.uintValue () ;
    const PMSInt32 paddingLength = paddedStringLength - mString.length () ;
    C_String s ; s.setCapacity (paddedStringLength) ;
    for (PMSInt32 i=0 ; i<paddingLength ; i++) {
      s.appendUnicodeCharacter (paddingChar COMMA_HERE) ;
    }
    s << mString ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::reader_stringByRightPadding (const GALGAS_uint & inPaddedStringLength,
                                                            const GALGAS_char & inPaddingChar
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if ((inPaddedStringLength.isValid ()) && (inPaddingChar.isValid ())) {
    const utf32 paddingChar = inPaddingChar.charValue () ;
    const PMSInt32 paddedStringLength = (PMSInt32) inPaddedStringLength.uintValue () ;
    const PMSInt32 paddingLength = paddedStringLength - mString.length () ;
    C_String s ; s.setCapacity (paddedStringLength) ;
    s << mString ;
    for (PMSInt32 i=0 ; i<paddingLength ; i++) {
      s.appendUnicodeCharacter (paddingChar COMMA_HERE) ;
    }
    result = GALGAS_string (s) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::reader_stringByLeftAndRightPadding (const GALGAS_uint & inPaddedStringLength,
                                                                   const GALGAS_char & inPaddingChar
                                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if ((inPaddedStringLength.isValid ()) && (inPaddingChar.isValid ())) {
    const utf32 paddingChar = inPaddingChar.charValue () ;
    const PMSInt32 paddedStringLength = (PMSInt32) inPaddedStringLength.uintValue () ;
    const PMSInt32 paddingLength = paddedStringLength - mString.length () ;
    C_String s ; s.setCapacity (paddedStringLength) ;
    for (PMSInt32 i=0 ; i<(paddingLength / 2) ; i++) {
      s.appendUnicodeCharacter (paddingChar COMMA_HERE) ;
    }
    s << mString ;
    for (PMSInt32 i=paddingLength / 2 ; i<paddingLength ; i++) {
      s.appendUnicodeCharacter (paddingChar COMMA_HERE) ;
    }
    result = GALGAS_string (s) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::reader_lastPathComponent (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.lastPathComponent ()) ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::reader_stringByReplacingStringByString (const GALGAS_string & inSearchedString,
                                                                       const GALGAS_string & inReplacementString,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const {
  GALGAS_string result ;
  if ((inSearchedString.isValid ()) && (inReplacementString.isValid ())) {
    if (inSearchedString.mString.length () == 0) {
      inCompiler->onTheFlyRunTimeError (
        "@string stringByReplacingStringByString reader called with empty searched string"
        COMMA_THERE
      ) ;
    }else{
      bool ok = false ;
      PMUInt32 replacementCount = 0 ;
      const C_String s = mString.stringByReplacingStringByString (inSearchedString.mString, inReplacementString.mString, replacementCount, ok COMMA_THERE) ;
      result = GALGAS_string (s) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::reader_stringByRemovingCharacterAtIndex (const GALGAS_uint & inIndex,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (inIndex.isValid ()) {
    if (inIndex.uintValue () < (PMUInt32) mString.length ()) {
      C_String s = mString ;
      s.suppress ((PMSInt32) inIndex.uintValue (), 1 COMMA_THERE) ;
      result = GALGAS_string (s) ;
    }else{
      inCompiler->onTheFlyRunTimeError (
        "@string stringByRemovingCharacterAtIndex reader called with index greater or equal to length"
        COMMA_THERE
      ) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_char GALGAS_string::reader_characterAtIndex (const GALGAS_uint & inIndex,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_char result ;
  if (inIndex.isValid ()) {
    const PMSInt32 idx = (PMSInt32) inIndex.uintValue () ;
    const PMSInt32 stringLength = mString.length () ;
    if (idx >= stringLength) {
      C_String message ;
      message << "string index (" << cStringWithSigned (idx) << ") too large (string length: " << cStringWithSigned (stringLength) << ")" ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    }else{
      result = GALGAS_char (mString (idx COMMA_HERE)) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

void GALGAS_string::description (C_String & ioString,
                                 const PMSInt32 /* inIndentation */) const {
  ioString << "<@string:" ;
  if (isValid ()) {
    ioString << "\"" << mString << "\"" ;
  }else{
    ioString << "not built" ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::reader_unixPathWithNativePath (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.unixPathWithNativePath ()) ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::reader_nativePathWithUnixPath (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.nativePathWithUnixPath ()) ;
}

//---------------------------------------------------------------------------*

GALGAS_stringlist GALGAS_string::reader_componentsSeparatedByString (const GALGAS_string & inSeparator
                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if (inSeparator.isValid ()) {
    result = GALGAS_stringlist::constructor_emptyList (THERE) ;
    TC_UniqueArray <C_String> components ;
    mString.componentsSeparatedByString (inSeparator.mString, components) ;
    for (PMSInt32 i=0 ; i<components.count () ; i++) {
      result.addAssign_operation (GALGAS_string (components (i COMMA_HERE)) COMMA_HERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_sint GALGAS_string::reader_system (UNUSED_LOCATION_ARGS) const {
  return GALGAS_sint (::system (mString.cString (HERE))) ;
}

//---------------------------------------------------------------------------*

static void
recursiveSearchForRegularFiles (const C_String & inUnixStartPath,
                                const bool inRecursiveSearch,
                                const C_String & inRelativePath,
                                GALGAS_stringlist & ioResult) {
  const C_String nativeStartPath = inUnixStartPath.nativePathWithUnixPath () ;
  DIR * dir = ::opendir (nativeStartPath.cString (HERE)) ;
  if (dir != NULL) {
    struct dirent  * current = readdir (dir) ;
    while (current != NULL) {
      if (current->d_name [0] != '.') {
        C_String name = nativeStartPath ;
        name << "/" << current->d_name ;
        if (name.directoryExists ()) {
          if (inRecursiveSearch) {
            recursiveSearchForRegularFiles (name,
                                            inRecursiveSearch,
                                            inRelativePath + current->d_name + "/",
                                            ioResult) ;
          }
        }else if (name.fileExists ()) {
          const C_String relativePath = inRelativePath + current->d_name ;
          ioResult.addAssign_operation (GALGAS_string (relativePath) COMMA_HERE) ;
        }
      }
      current = readdir (dir) ;
    }
  }
  closedir (dir) ;
}

//---------------------------------------------------------------------------*

GALGAS_stringlist GALGAS_string::reader_regularFiles (const GALGAS_bool & inRecursiveSearch
                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if (inRecursiveSearch.isValid ()) {
    result = GALGAS_stringlist::constructor_emptyList (THERE) ;
    recursiveSearchForRegularFiles (mString,
                                    inRecursiveSearch.boolValue (),
                                    "",
                                    result) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

static void
recursiveSearchForHiddenFiles (const C_String & inUnixStartPath,
                                const bool inRecursiveSearch,
                                const C_String & inRelativePath,
                                GALGAS_stringlist & ioResult) {
  const C_String nativeStartPath = inUnixStartPath.nativePathWithUnixPath () ;
  DIR * dir = ::opendir (nativeStartPath.cString (HERE)) ;
  if (dir != NULL) {
    struct dirent  * current = readdir (dir) ;
    while (current != NULL) {
      if ((strlen (current->d_name) > 1) && (current->d_name [0] == '.') && (strcmp (current->d_name, "..") != 0)) {
        C_String name = nativeStartPath ;
        name << "/" << current->d_name ;
        if (name.directoryExists ()) {
          if (inRecursiveSearch) {
            recursiveSearchForHiddenFiles (name,
                                           inRecursiveSearch,
                                           inRelativePath + current->d_name + "/",
                                           ioResult) ;
          }
        }else if (name.fileExists ()) {
          const C_String relativePath = inRelativePath + current->d_name ;
          ioResult.addAssign_operation (GALGAS_string (relativePath) COMMA_HERE) ;
        }
      }
      current = readdir (dir) ;
    }
  }
  closedir (dir) ;
}

//---------------------------------------------------------------------------*

GALGAS_stringlist GALGAS_string::reader_hiddenFiles (const GALGAS_bool & inRecursiveSearch
                                                     COMMA_LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if (inRecursiveSearch.isValid ()) {
    result = GALGAS_stringlist::constructor_emptyList (THERE) ;
    recursiveSearchForHiddenFiles (mString,
                                   inRecursiveSearch.boolValue (),
                                   "",
                                   result) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

static void
recursiveSearchForDirectories (const C_String & inUnixStartPath,
                               const bool inRecursiveSearch,
                               const C_String & inRelativePath,
                               GALGAS_stringlist & ioResult) {
  const C_String nativeStartPath = inUnixStartPath.nativePathWithUnixPath () ;
  DIR * dir = ::opendir (nativeStartPath.cString (HERE)) ;
  if (dir != NULL) {
    struct dirent  * current = readdir (dir) ;
    while (current != NULL) {
      if (current->d_name [0] != '.') {
        C_String name = nativeStartPath ;
        name << "/" << current->d_name ;
        if (name.directoryExists ()) {
          const C_String relativePath = inRelativePath + current->d_name ;
          ioResult.addAssign_operation (GALGAS_string (relativePath) COMMA_HERE) ;
          if (inRecursiveSearch) {
            recursiveSearchForDirectories (name,
                                           inRecursiveSearch,
                                           inRelativePath + current->d_name + "/",
                                           ioResult) ;
          }
        }
      }
      current = readdir (dir) ;
    }
  }
  closedir (dir) ;
}

//---------------------------------------------------------------------------*

GALGAS_stringlist GALGAS_string::reader_directories (const GALGAS_bool & inRecursiveSearch
                                                     COMMA_LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if (inRecursiveSearch.isValid ()) {
    result = GALGAS_stringlist::constructor_emptyList (THERE) ;
    if (mString.directoryExists ()) {
      recursiveSearchForDirectories (mString,
                                     inRecursiveSearch.boolValue (),
                                     "",
                                     result) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

static void
recursiveSearchForRegularFiles (const C_String & inUnixStartPath,
                                GALGAS_stringlist inExtensionList,
                                const bool inRecursiveSearch,
                                const C_String & inRelativePath,
                                GALGAS_stringlist & ioResult) {
  const C_String nativeStartPath = inUnixStartPath.nativePathWithUnixPath () ;
  DIR * dir = ::opendir (nativeStartPath.cString (HERE)) ;
  if (dir != NULL) {
    struct dirent  * current = readdir (dir) ;
    while (current != NULL) {
      if (current->d_name [0] != '.') {
        C_String name = nativeStartPath ;
        name << "/" << current->d_name ;
        if (name.directoryExists ()) {
          if (inRecursiveSearch) {
            recursiveSearchForRegularFiles (name,
                                            inExtensionList,
                                            inRecursiveSearch,
                                            inRelativePath + current->d_name + "/",
                                            ioResult) ;
          }
        }else if (name.fileExists ()) {
          const C_String extension = name.pathExtension () ;
          bool extensionFound = false ;
          cEnumerator_stringlist currentExtension (inExtensionList, kEnumeration_up) ;
          while (currentExtension.hasCurrentObject () && ! extensionFound) {
            extensionFound = currentExtension.current_mValue (HERE).stringValue () == extension ;
            currentExtension.gotoNextObject () ;
          }
          if (extensionFound) {
            const C_String relativePath = inRelativePath + current->d_name ;
            ioResult.addAssign_operation (GALGAS_string (relativePath) COMMA_HERE) ;
          }
        }
      }
      current = readdir (dir) ;
    }
  }
  closedir (dir) ;
}

//---------------------------------------------------------------------------*

GALGAS_stringlist GALGAS_string::reader_regularFilesWithExtensions (const GALGAS_bool & inRecursiveSearch,
                                                                      const GALGAS_stringlist & inExtensionList
                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if ((inRecursiveSearch.isValid ()) && (inExtensionList.isValid ())) {
    result = GALGAS_stringlist::constructor_emptyList (THERE) ;
    if (mString.directoryExists ()) {
      recursiveSearchForRegularFiles (mString,
                                      inExtensionList,
                                      inRecursiveSearch.boolValue (),
                                      "",
                                      result) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

static void
recursiveSearchForDirectories (const C_String & inUnixStartPath,
                               GALGAS_stringlist inExtensionList,
                               const bool inRecursiveSearch,
                               const C_String & inRelativePath,
                               GALGAS_stringlist & ioResult) {
  const C_String nativeStartPath = inUnixStartPath.nativePathWithUnixPath () ;
  DIR * dir = ::opendir (nativeStartPath.cString (HERE)) ;
  if (dir != NULL) {
    struct dirent  * current = readdir (dir) ;
    while (current != NULL) {
      if (current->d_name [0] != '.') {
        C_String name = nativeStartPath ;
        name << "/" << current->d_name ;
        if (name.directoryExists ()) {
        //--- Look for extension
          const C_String extension = name.pathExtension () ;
          bool extensionFound = false ;
          cEnumerator_stringlist currentExtension (inExtensionList, kEnumeration_up) ;
          while (currentExtension.hasCurrentObject () && ! extensionFound) {
            extensionFound = currentExtension.current_mValue (HERE).stringValue () == extension ;
            currentExtension.gotoNextObject () ;
          }
          if (extensionFound) {
            const C_String relativePath = inRelativePath + current->d_name ;
            ioResult.addAssign_operation (GALGAS_string (relativePath) COMMA_HERE) ;
          }
        //--- Recursive Search ?
          if (inRecursiveSearch) {
            recursiveSearchForDirectories (name,
                                           inExtensionList,
                                           inRecursiveSearch,
                                           inRelativePath + current->d_name + "/",
                                           ioResult) ;
          }
        }
      }
      current = readdir (dir) ;
    }
  }
  closedir (dir) ;
}

//---------------------------------------------------------------------------*

GALGAS_stringlist GALGAS_string::reader_directoriesWithExtensions (const GALGAS_bool & inRecursiveSearch,
                                                                   const GALGAS_stringlist & inExtensionList
                                                                   COMMA_LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if ((inRecursiveSearch.isValid ()) && (inExtensionList.isValid ())) {
    result = GALGAS_stringlist::constructor_emptyList (THERE) ;
    if (mString.directoryExists ()) {
      recursiveSearchForDirectories (mString,
                                     inExtensionList,
                                     inRecursiveSearch.boolValue (),
                                     "",
                                     result) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

//GALGAS_string GALGAS_string::stringWithColumnCount (const C_String & inString) {
//  return GALGAS_string (true, C_String::stringWithRepeatedCharacter (TO_UNICODE (' '), inString.currentColumn ())) ;
//}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_stringWithSequenceOfCharacters (const GALGAS_char & inCharacter,
                                                                         const GALGAS_uint & inCount
                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if ((inCount.isValid ()) && (inCharacter.isValid ())) {
    const utf32 character = inCharacter.charValue () ;
    C_String s ;
    for (PMUInt32 i=0 ; i<inCount.uintValue () ; i++) {
      s.appendUnicodeCharacter (character COMMA_HERE) ;
    }
    result = GALGAS_string (s) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_stringWithSourceFilePath (C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  return GALGAS_string (inCompiler->sourceFilePath ()) ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_stringWithContentsOfFile (const GALGAS_string & inFilePath,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inFilePath.isValid ()) {
    inCompiler->logFileRead (inFilePath.mString) ;
    if (inFilePath.mString.fileExists ()) {
      result = GALGAS_string (C_String::stringWithContentOfFile (inFilePath.mString)) ;
    }else{
      C_String message ;
      message << "cannot read '" << inFilePath.mString << "' file (does not exist)" ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_stringWithMainFirstArgument (UNUSED_LOCATION_ARGS) {
  return GALGAS_string (C_String (mainFirstArgument ())) ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_stringWithVersionString (UNUSED_LOCATION_ARGS) {
  return GALGAS_string (C_String (compilerVersionString ())) ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_stringWithCurrentDirectory (UNUSED_LOCATION_ARGS) {
  return GALGAS_string (C_String::currentDirectory ()) ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_stringWithEnvironmentVariable (const GALGAS_string & inEnvironmentVariableName,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inEnvironmentVariableName.isValid ()) {
    const char * value = ::getenv (inEnvironmentVariableName.mString.cString (HERE)) ;
    if (value == NULL) {
      C_String message ;
      message << "the '" << inEnvironmentVariableName.mString << "' environment variable does not exist" ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    }else{
      result = GALGAS_string (value) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_stringWithEnvironmentVariableOrEmpty (const GALGAS_string & inEnvironmentVariableName
                                                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inEnvironmentVariableName.isValid ()) {
    const char * value = ::getenv (inEnvironmentVariableName.mString.cString (HERE)) ;
    result = GALGAS_string (value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_componentsJoinedByString (const GALGAS_stringlist & inComponents,
                                                                   const GALGAS_string & inSeparator
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if ((inComponents.isValid ()) && (inSeparator.isValid ())) {
    bool first = true ;
    C_String s ;
    cEnumerator_stringlist current (inComponents, kEnumeration_up) ;
    while (current.hasCurrentObject ()) {
      if (first) {
        first = false ;
      }else{
        s << inSeparator.mString ;
      }
      s << current.current_mValue (HERE).mString ;
      current.gotoNextObject () ;
    }
    result = GALGAS_string (s) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_stringWithCurrentDateTime (UNUSED_LOCATION_ARGS) {
  const time_t currentTime = ::time (NULL) ;
  char * timeString = NULL ;
  bool ok = currentTime >= 0 ;
  if (ok) {
    timeString = ::ctime (& currentTime) ;
    ok = timeString != NULL ;
    if (ok) {
      const size_t length = ::strlen (timeString) ;
      ok = length > 0 ;
      if (ok) {
        timeString [length - 1] = '\0' ; // Suppress trailing '\n'
      }
    }
  }
  return GALGAS_string (ok ? timeString : "") ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_retrieveAndResetTemplateString (C_Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  return inCompiler->retrieveAndResetTemplateString () ;
}

//---------------------------------------------------------------------------*

GALGAS_bool GALGAS_string::reader_doesEnvironmentVariableExist (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (::getenv (mString.cString (HERE)) != NULL) ;
}

//---------------------------------------------------------------------------*

void GALGAS_string::class_method_deleteFile (GALGAS_string inFilePath,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  if (inFilePath.isValid ()) {
    if (! inCompiler->mPerformGeneration) {
      inCompiler->ggs_printWarning (C_String ("Need to delete '") + inFilePath.mString + "'.\n") ;
    }else if (inFilePath.mString.length () == 0) {
      inCompiler->onTheFlyRunTimeError ("cannot perform file delete: file name is an empty string" COMMA_THERE) ;
    }else{
      const char * errorMessage = inFilePath.mString.deleteFile () ;
      if (errorMessage == NULL) {
        inCompiler->ggs_printRewriteFileSuccess (C_String ("Deleted '") + inFilePath.mString + "'.\n") ;
      }else{
        C_String message ;
        message << "cannot perform file delete: " << errorMessage ;
        inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
      }
    }
  }
}

//---------------------------------------------------------------------------*

void GALGAS_string::class_method_deleteFileIfExists (GALGAS_string inFilePath,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  if ((inFilePath.isValid ()) && inFilePath.mString.fileExists ()) {
    class_method_deleteFile (inFilePath, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------*

void GALGAS_string::class_method_removeEmptyDirectory (GALGAS_string inDirectoryPath,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  if (inDirectoryPath.isValid ()) {
    if (! inCompiler->mPerformGeneration) {
      inCompiler->ggs_printWarning (C_String ("Need to remove directory '") + inDirectoryPath.mString + "'.\n") ;
    }else if (inDirectoryPath.mString.length () == 0) {
      inCompiler->onTheFlyRunTimeError ("cannot perform directory removing: directory path is an empty string" COMMA_THERE) ;
    }else{
      const char * errorMessage = inDirectoryPath.mString.removeDirectory () ;
      if (errorMessage != NULL) {
        C_String message ;
        message << "cannot perform directory removing: " << errorMessage ;
        inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
      }
    }
  }
}

//---------------------------------------------------------------------------*

static const char *
recursiveRemoveDirectory (const C_String & inUnixDirectoryPath) {
  const char * result = NULL ;
  const C_String nativeStartPath = inUnixDirectoryPath.nativePathWithUnixPath () ;
  DIR * dir = ::opendir (nativeStartPath.cString (HERE)) ;
  if (dir != NULL) {
    struct dirent  * current = readdir (dir) ;
    while ((current != NULL) && (NULL == result)) {
      if ((strcmp (current->d_name, ".") != 0) && (strcmp (current->d_name, "..") != 0)) {
        C_String name = nativeStartPath ;
        name << "/" << current->d_name ;
        if (name.directoryExists ()) {
          recursiveRemoveDirectory (name) ;
        }else if (name.fileExists ()) {
          result = name.deleteFile () ;
        }
      }
      current = readdir (dir) ;
    }
  }
  closedir (dir) ;
  if (NULL == result) {
    result = inUnixDirectoryPath.removeDirectory () ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

void GALGAS_string::class_method_removeDirectoryRecursively (GALGAS_string inDirectoryPath,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) {
  if (inDirectoryPath.isValid ()) {
    if (! inCompiler->mPerformGeneration) {
      inCompiler->ggs_printWarning (C_String ("Need to remove directory '") + inDirectoryPath.mString + "'.\n") ;
    }else if (inDirectoryPath.mString.length () == 0) {
      inCompiler->onTheFlyRunTimeError ("cannot perform directory removing: directory path is an empty string" COMMA_THERE) ;
    }else{
      const char * errorMessage = recursiveRemoveDirectory (inDirectoryPath.mString) ;
      if (errorMessage != NULL) {
        C_String message ;
        message << "cannot perform directory removing: " << errorMessage ;
        inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
      }
    }
  }
}

//---------------------------------------------------------------------------*

void GALGAS_string::class_method_generateFile (GALGAS_string inStartPath,
                                               GALGAS_string inFileName,
                                               GALGAS_string inLineCommentPrefix,
                                               GALGAS_string inDefaultUserZone1,
                                               GALGAS_string inGeneratedZone2,
                                               GALGAS_string inDefaultUserZone2,
                                               GALGAS_string inGeneratedZone3,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  const bool built = (inStartPath.isValid ())
    && (inFileName.isValid ())
    && (inLineCommentPrefix.isValid ())
    && (inDefaultUserZone1.isValid ())
    && (inDefaultUserZone2.isValid ())
    && (inDefaultUserZone2.isValid ())
    && (inGeneratedZone3.isValid ())
  ;
  if (built) {
    TC_UniqueArray <C_String> directoriesToExclude ;
    inCompiler->generateFileFromPathes (inStartPath.mString,
                                        directoriesToExclude,
                                        inLineCommentPrefix.mString,
                                        inFileName.mString,
                                        inDefaultUserZone1.mString,
                                        inGeneratedZone2.mString,
                                        inDefaultUserZone2.mString,
                                        inGeneratedZone3.mString) ;
  }
}

//---------------------------------------------------------------------------*

void GALGAS_string::method_makeDirectory (C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  const bool ok = mString.makeDirectoryIfDoesNotExist () ;
  if (! ok) {
    C_String message ;
    message << "cannot create '" << mString << "' directory" ;
    inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------*

void GALGAS_string::
method_makeDirectoryAndWriteToFile (GALGAS_string inFilePath,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) const {
  if (inFilePath.isValid ()) {
  //--- Make directory
    const C_String directory = inFilePath.mString.stringByDeletingLastPathComponent () ;
    bool ok = directory.makeDirectoryIfDoesNotExist () ;
    if (! ok) {
      C_String message ;
      message << "cannot create '" << directory << "' directory" ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    }else{
      method_writeToFile (inFilePath, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------*

void GALGAS_string::method_writeToFile (GALGAS_string inFilePath,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) const {
  if (inFilePath.isValid ()) {
//    inCompiler->addDependancyOutputFilePath (inFilePath.mString) ;
    if (inCompiler->mPerformGeneration) {
      const bool fileAlreadyExists = inFilePath.mString.fileExists () ;
      const bool verboseOptionOn = gOption_galgas_5F_cli_5F_options_verbose_5F_output.mValue ;
      const bool ok = mString.writeToFile (inFilePath.mString COMMA_TEACH_TEXT_CREATOR COMMA_THERE) ;
      if (ok && verboseOptionOn && fileAlreadyExists) {
        inCompiler->ggs_printRewriteFileSuccess (C_String ("Replaced '") + inFilePath.mString + "'.\n") ;
      }else if (ok && verboseOptionOn && ! fileAlreadyExists) {
        inCompiler->ggs_printCreatedFileSuccess (C_String ("Created '") + inFilePath.mString + "'.\n") ;
      }else if (! ok) {
        C_String message ;
        message << "cannot write '" << inFilePath.mString << "' file" ;
        inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
      }
    }else{
      inCompiler->ggs_printWarning (C_String ("Need to write '") + inFilePath.mString + "'.\n") ;
    }
  }
}

//---------------------------------------------------------------------------*

void GALGAS_string::method_writeToFileWhenDifferentContents (GALGAS_string inFilePath,
                                                             GALGAS_bool & outFileWritten,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const {
  if (inFilePath.isValid ()) {
    bool needToWrite = true ;
    const bool fileAlreadyExists = inFilePath.mString.fileExists () ;
    if (fileAlreadyExists) {
      inCompiler->logFileRead (inFilePath.mString) ;
      const C_String readContents = C_String::stringWithContentOfFile (inFilePath.mString) ;
      needToWrite = mString.compare (readContents) != 0 ;
    }
    outFileWritten = GALGAS_bool (needToWrite) ;
    if (needToWrite) {
      if (inCompiler->mPerformGeneration) {
        const bool verboseOptionOn = gOption_galgas_5F_cli_5F_options_verbose_5F_output.mValue ;
        bool ok = inFilePath.mString.stringByDeletingLastPathComponent ().makeDirectoryIfDoesNotExist () ;
        if (! ok) {
          C_String message ;
          message << "cannot create '" << inFilePath.mString << "' directory" ;
          inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
          outFileWritten.drop () ;
        }else{
          ok = mString.writeToFile (inFilePath.mString COMMA_TEACH_TEXT_CREATOR COMMA_THERE) ;
          if (ok && verboseOptionOn && fileAlreadyExists) {
            inCompiler->ggs_printRewriteFileSuccess (C_String ("Replaced '") + inFilePath.mString + "'.\n") ;
          }else if (ok && verboseOptionOn && ! fileAlreadyExists) {
            inCompiler->ggs_printCreatedFileSuccess (C_String ("Created '") + inFilePath.mString + "'.\n") ;
          }else if (! ok) {
            C_String message ;
            message << "cannot write '" << inFilePath.mString << "' file" ;
            inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
            outFileWritten.drop () ;
          }
        }
      }else{
        inCompiler->ggs_printWarning (C_String ("Need to write '") + inFilePath.mString + "'.\n") ;
      }
    }
  }
}

//---------------------------------------------------------------------------*

void GALGAS_string::method_writeToExecutableFile (GALGAS_string inFilePath,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const {
  if (inFilePath.isValid ()) {
 //   inCompiler->addDependancyOutputFilePath (inFilePath.mString) ;
    const bool fileAlreadyExists = inFilePath.mString.fileExists () ;
    if (inCompiler->mPerformGeneration) {
      const bool verboseOptionOn = gOption_galgas_5F_cli_5F_options_verbose_5F_output.mValue ;
      const bool ok = mString.writeToExecutableFile (inFilePath.mString COMMA_TEACH_TEXT_CREATOR COMMA_THERE) ;
      if (ok && verboseOptionOn && fileAlreadyExists) {
        inCompiler->ggs_printRewriteFileSuccess (C_String ("Replaced '") + inFilePath.mString + "'.\n") ;
      }else if (ok && verboseOptionOn && ! fileAlreadyExists) {
        inCompiler->ggs_printCreatedFileSuccess (C_String ("Created '") + inFilePath.mString + "'.\n") ;
      }else if (! ok) {
        C_String message ;
        message << "cannot write '" << inFilePath.mString << "' file" ;
        inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
      }
    }else{
      inCompiler->ggs_printWarning (C_String ("Need to write '") + inFilePath.mString + "'.\n") ;
    }
  }
}

//---------------------------------------------------------------------------*

void GALGAS_string::method_writeToExecutableFileWhenDifferentContents (GALGAS_string inFilePath,
                                                                       GALGAS_bool & outFileWritten,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const {
  if (inFilePath.isValid ()) {
//    inCompiler->addDependancyOutputFilePath (inFilePath.mString) ;
    bool needToWrite = true ;
    const bool fileAlreadyExists = inFilePath.mString.fileExists () ;
    if (fileAlreadyExists) {
      inCompiler->logFileRead (inFilePath.mString) ;
      const C_String readContents = C_String::stringWithContentOfFile (inFilePath.mString) ;
      needToWrite = mString.compare (readContents) != 0 ;
    }
    outFileWritten = GALGAS_bool (needToWrite) ;
    if (needToWrite) {
      if (inCompiler->mPerformGeneration) {
        const bool verboseOptionOn = gOption_galgas_5F_cli_5F_options_verbose_5F_output.mValue ;
        bool ok = inFilePath.mString.stringByDeletingLastPathComponent ().makeDirectoryIfDoesNotExist () ;
        if (! ok) {
          C_String message ;
          message << "cannot create '" << inFilePath.mString << "' directory" ;
          inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
          outFileWritten.drop () ;
        }else{
          ok = mString.writeToExecutableFile (inFilePath.mString COMMA_TEACH_TEXT_CREATOR COMMA_THERE) ;
          if (ok && verboseOptionOn && fileAlreadyExists) {
            inCompiler->ggs_printRewriteFileSuccess (C_String ("Replaced '") + inFilePath.mString + "'.\n") ;
          }else if (ok && verboseOptionOn && ! fileAlreadyExists) {
            inCompiler->ggs_printCreatedFileSuccess (C_String ("Created '") + inFilePath.mString + "'.\n") ;
          }else if (! ok) {
            C_String message ;
            message << "cannot write '" << inFilePath.mString << "' file" ;
            inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
            outFileWritten.drop () ;
          }
        }
      }else{
        inCompiler->ggs_printWarning (C_String ("Need to write '") + inFilePath.mString + "'.\n") ;
      }
    }
  }
}

//---------------------------------------------------------------------------*

GALGAS_uint GALGAS_string::reader_capacity (UNUSED_LOCATION_ARGS) const {
  return GALGAS_uint ((PMUInt32) mString.capacity ()) ;
}

//---------------------------------------------------------------------------*

void GALGAS_string::modifier_setCapacity (GALGAS_uint inNewCapacity,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  if (inNewCapacity.isValid ()) {
    if (inNewCapacity.uintValue () <= ((PMUInt32) PMSINT32_MAX)) {
      mString.setCapacity ((PMSInt32) inNewCapacity.uintValue ()) ; 
    }else{
      C_String message ;
      message << "setCapacity argument value (" ;
      message.appendUnsigned (inNewCapacity.uintValue ()) ;
      message << ") too large (should be <= 2**31-1)" ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    } 
  }
}

//---------------------------------------------------------------------------*

void GALGAS_string::modifier_incIndentation (GALGAS_uint inIndentation,
                                             C_Compiler * /* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) {
  if (inIndentation.isValid ()) {
    mString.incIndentation ((PMSInt32) inIndentation.uintValue ()) ; 
  }
}

//---------------------------------------------------------------------------*

void GALGAS_string::modifier_decIndentation (GALGAS_uint inIndentation,
                                             C_Compiler * /* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) {
  if (inIndentation.isValid ()) {
    mString.incIndentation (- ((PMSInt32) inIndentation.uintValue ())) ; 
  }
}

//---------------------------------------------------------------------------*

void GALGAS_string::modifier_setCharacterAtIndex (GALGAS_char inCharacter,
                                                  GALGAS_uint inIndex,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  if ((inCharacter.isValid ()) && (inIndex.isValid ())) {
    const PMSInt32 idx = (PMSInt32) inIndex.uintValue () ;
    const PMSInt32 stringLength = mString.length () ;
    if (idx >= stringLength) {
      C_String message ;
      message << "string index (" << cStringWithSigned (idx) << ") too large (string length: " << cStringWithSigned (stringLength) << ")" ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    }else{
      mString.setUnicodeCharacterAtIndex (inCharacter.charValue (), idx COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------*

void GALGAS_string::dotAssign_operation (GALGAS_string inOperand
                                         COMMA_UNUSED_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid ()) {
    mString << inOperand.mString ;
  }
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_CppLineComment (UNUSED_LOCATION_ARGS) {
  C_String s ; s.appendCppHyphenLineComment () ;
  return GALGAS_string (s) ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_CppTitleComment (const GALGAS_string & inTitle
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inTitle.isValid ()) {
    C_String s ;
    s.appendCppTitleComment (inTitle.mString) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_CppChar (const GALGAS_char & inCharacter
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inCharacter.isValid ()) {
    C_String s ;
    s.appendCLiteralCharConstant (inCharacter.charValue ()) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_CppString (const GALGAS_string & inString
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inString.isValid ()) {
    C_String s ;
    s.appendCLiteralStringConstant (inString.mString) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_bool GALGAS_string::reader_isDecimalUnsignedNumber (UNUSED_LOCATION_ARGS) const {
  bool isDecimalUnsignedNumber = true ;
  for (PMSInt32 i=0 ; (i<mString.length ()) && isDecimalUnsignedNumber ; i++) {
    const utf32 c = mString (i COMMA_HERE) ;
    isDecimalUnsignedNumber = (UNICODE_VALUE (c) >= '0') && (UNICODE_VALUE (c) <= '9') ;
  }
  return GALGAS_bool (isDecimalUnsignedNumber) ;
}

//---------------------------------------------------------------------------*

GALGAS_uint GALGAS_string::reader_decimalUnsignedNumber (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  bool ok = true ;
  const PMUInt32 max = PMUINT32_MAX / 10 ;
  PMUInt32 decimalUnsignedValue = 0 ;
  for (PMSInt32 i=0 ; (i<mString.length ()) && ok ; i++) {
    const utf32 c = mString (i COMMA_HERE) ;
    if ((UNICODE_VALUE (c) < '0') || (UNICODE_VALUE (c) > '9')) {
      inCompiler->onTheFlyRunTimeError ("cannot convert a string to a decimal number: it contains a non-digit character" COMMA_THERE) ;
      ok = false ;
    }else{
      const PMUInt32 digit = UNICODE_VALUE (c) - '0' ;
      if (decimalUnsignedValue > max) {
        inCompiler->onTheFlyRunTimeError ("cannot convert a string to a decimal number: number is > 2**32 - 1" COMMA_THERE) ;
        ok = false ;
      }else if ((decimalUnsignedValue == max) && (digit > (PMUINT32_MAX % 10))) {
        inCompiler->onTheFlyRunTimeError ("cannot convert a string to a decimal number: number is > 2**32 - 1" COMMA_THERE) ;
        ok = false ;
      }else{
        decimalUnsignedValue = decimalUnsignedValue * 10 + digit ;
      }
    }
  }
  GALGAS_uint result ;
  if (ok) {
    result = GALGAS_uint (decimalUnsignedValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

AC_OutputStream & operator << (AC_OutputStream & inStream,
                               const GALGAS_string & inString) {
  inStream << inString.stringValue () ;
  return inStream ;
}

//---------------------------------------------------------------------------*

AC_OutputStream & operator << (AC_OutputStream & inStream,
                               const GALGAS_lstring & inString) {
  inStream << inString.mAttribute_string.stringValue () ;
  return inStream ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//    S Y M B O L I C    L I N K S                                           *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_bool GALGAS_string::reader_isSymbolicLink (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = GALGAS_bool (mString.isSymbolicLink ()) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_stringWithSymbolicLinkContents (const GALGAS_string & inSymbolicLink,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inSymbolicLink.isValid ()) {
    bool ok = false ;
    const C_String r = inSymbolicLink.mString.stringWithSymbolicLinkContents (ok) ;
    if (ok) {
      result = GALGAS_string (r) ;
    }else{
      C_String s ;
      s << "'@string stringWithSymbolicLinkContents' error; receiver's value '" << inSymbolicLink.mString << "' is not a symbolic link" ;
      inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

void GALGAS_string::method_makeSymbolicLinkWithPath (GALGAS_string inPath,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  if (isValid () && inPath.isValid ()) {
    const bool ok = mString.makeSymbolicLinkWithPath (inPath.mString) ;
    if (! ok) {
        C_String s ;
        s << "'@string makeSymbolicLinkWithPath' error; cannot make a symbolic link with receiver's value '"
          << mString
          << "' and path given '" << inPath << "' by argument's value" ;
        inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------*
