//---------------------------------------------------------------------------*
//                                                                           *
//                        File 'oa_cli_options.cpp'                          *
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

#include <string.h>

#include "oa_cli_options.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                          C O N S T R U C T O R                            *
//                                                                           *
//---------------------------------------------------------------------------*

oa_cli_options::oa_cli_options (void)
:mStringValue (1 COMMA_HERE) {
  mBoolValue [0] = 0 ;
  mBoolValue [1] = 0 ;
  mBoolValue [2] = 0 ;
  mBoolValue [3] = false ; // Extra unused entry
  mUintValue [0] = 0 ; // Extra unused entry
}

//---------------------------------------------------------------------------*
//                                                                           *
//              G E T    B O O L    O P T I O N S    C O U N T               *
//                                                                           *
//---------------------------------------------------------------------------*

sint32 oa_cli_options::getBoolOptionsCount (void) const {
  return 3 ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//               G E T    B O O L    O P T I O N    V A L U E                *
//                                                                           *
//---------------------------------------------------------------------------*

bool oa_cli_options::getBoolOptionValue (const sint32 inIndex) const {
  return ((inIndex >= 0) && (inIndex < 3)) ? mBoolValue [inIndex] : false ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//               S E T    B O O L    O P T I O N    V A L U E                *
//                                                                           *
//---------------------------------------------------------------------------*

void oa_cli_options::setBoolOptionValue (const sint32 inIndex, const bool inValue) {
  if ((inIndex >= 0) && (inIndex < 3)) {
    mBoolValue [inIndex] = inValue ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//           G E T    B O O L    O P T I O N    C H A R A C T E R            *
//                                                                           *
//---------------------------------------------------------------------------*

char oa_cli_options::getBoolOptionChar (const sint32 inIndex) const {
  const char kCharArray [4] = {'C', 'B', 'M', '\0'} ;
  return ((inIndex >= 0) && (inIndex < 3)) ? kCharArray [inIndex] : '\0' ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//              G E T    B O O L    O P T I O N    S T R I N G               *
//                                                                           *
//---------------------------------------------------------------------------*

const char * oa_cli_options::getBoolOptionString (const sint32 inIndex) const {
  const char * kStringArray [4] = {"create-intermediate-files",
    "force-B-algorithm",
    "use-can-max-length",
    ""} ;
  return ((inIndex >= 0) && (inIndex < 3)) ? kStringArray [inIndex] : "" ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//         G E T    B O O L    O P T I O N    D E S C R I P T I O N          *
//                                                                           *
//---------------------------------------------------------------------------*

const char * oa_cli_options::getBoolOptionDescription (const sint32 inIndex) const {
  const char * kDescriptionArray [4] = {"Create the intermediate files",
    "For independant resources, force B algorithm",
    "Use only CAN messages max length",
    ""} ;
  return ((inIndex >= 0) && (inIndex < 3)) ? kDescriptionArray [inIndex] : "" ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//    G E T    B O O L    O P T I O N    V A L U E    F R O M    K E Y S     *
//                                                                           *
//---------------------------------------------------------------------------*

bool oa_cli_options::getBoolOptionValueFromKeys (const char * inModuleName,
                              const char * inOptionName,
                              bool * outFound) const {
  const char * kKeyArray [4] = {"createIntermediateFiles",
    "forceBalgorithm",
    "useCANmaxLegth",
    ""} ;
  bool result = false ;
  bool found = strcmp (inModuleName, "oa_cli_options") == 0 ;
  if (found) {
    found = false ;
    sint32 index = 0 ;
    while ((index < 3) && ! found) {
      found = strcmp (inOptionName, kKeyArray [index]) == 0 ;
      if (found) {
        result = mBoolValue [index] ;
      }
      index ++ ;
    }
  }
  if (outFound != NULL) {
    * outFound = found ;
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//              G E T    U I N T    O P T I O N S    C O U N T               *
//                                                                           *
//---------------------------------------------------------------------------*

sint32 oa_cli_options::getUintOptionsCount (void) const {
  return 0 ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//               G E T    U I N T    O P T I O N    V A L U E                *
//                                                                           *
//---------------------------------------------------------------------------*

uint32 oa_cli_options::getUintOptionValue (const sint32 inIndex) const {
  return ((inIndex >= 0) && (inIndex < 0)) ? mUintValue [inIndex] : 0 ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//      G E T    U I N T    O P T I O N    D E F A U L T    V A L U E        *
//                                                                           *
//---------------------------------------------------------------------------*

uint32 oa_cli_options::getUintOptionDefaultValue (const sint32 inIndex) const {
  const uint32 kDefaultValues [1] = {
  0} ;
  return ((inIndex >= 0) && (inIndex < 0)) ? kDefaultValues [inIndex] : 0 ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//               S E T    U I N T    O P T I O N    V A L U E                *
//                                                                           *
//---------------------------------------------------------------------------*

void oa_cli_options::setUintOptionValue (const sint32 inIndex, const uint32 inValue) {
  if ((inIndex >= 0) && (inIndex < 0)) {
    mUintValue [inIndex] = inValue ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//           G E T    U I N T    O P T I O N    C H A R A C T E R            *
//                                                                           *
//---------------------------------------------------------------------------*

char oa_cli_options::getUintOptionChar (const sint32 inIndex) const {
  const char kCharArray [1] = {'\0'} ;
  return ((inIndex >= 0) && (inIndex < 0)) ? kCharArray [inIndex] : '\0' ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//              G E T    U I N T    O P T I O N    S T R I N G               *
//                                                                           *
//---------------------------------------------------------------------------*

const char * oa_cli_options::getUintOptionString (const sint32 inIndex) const {
  const char * kStringArray [1] = {""} ;
  return ((inIndex >= 0) && (inIndex < 0)) ? kStringArray [inIndex] : "" ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//         G E T   U I N T    O P T I O N    D E S C R I P T I O N           *
//                                                                           *
//---------------------------------------------------------------------------*

const char * oa_cli_options::getUintOptionDescription (const sint32 inIndex) const {
  const char * kDescriptionArray [1] = {""} ;
  return ((inIndex >= 0) && (inIndex < 0)) ? kDescriptionArray [inIndex] : "" ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//    G E T    U I N T    O P T I O N    V A L U E    F R O M    K E Y S     *
//                                                                           *
//---------------------------------------------------------------------------*

uint32 oa_cli_options::getUintOptionValueFromKeys (const char * inModuleName,
                              const char * inOptionName,
                              bool * outFound) const {
  const char * kKeyArray [1] = {""} ;
  uint32 result = 0 ;
  bool found = strcmp (inModuleName, "oa_cli_options") == 0 ;
  if (found) {
    found = false ;
    sint32 index = 0 ;
    while ((index < 0) && ! found) {
      found = strcmp (inOptionName, kKeyArray [index]) == 0 ;
      if (found) {
        result = mUintValue [index] ;
      }
      index ++ ;
    }
  }
  if (outFound != NULL) {
    * outFound = found ;
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//            G E T    S T R I N G    O P T I O N S    C O U N T             *
//                                                                           *
//---------------------------------------------------------------------------*

sint32 oa_cli_options::getStringOptionsCount (void) const {
  return 0 ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//            G E T    S T R I N G    O P T I O N S    V A L U E             *
//                                                                           *
//---------------------------------------------------------------------------*

C_string oa_cli_options::
getStringOptionValue (const sint32 /* inIndex */) const {
  return C_string () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//            S E T    S T R I N G    O P T I O N S    V A L U E             *
//                                                                           *
//---------------------------------------------------------------------------*

void oa_cli_options::
setStringOptionValue (const sint32 /* inIndex */, const C_string & /* inValue */) {
}

//---------------------------------------------------------------------------*
//                                                                           *
//              G E T    S T R I N G    O P T I O N    C H A R               *
//                                                                           *
//---------------------------------------------------------------------------*

char oa_cli_options::
getStringOptionChar (const sint32 /* inIndex */) const {
  return '\0' ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//            G E T    S T R I N G    O P T I O N    S T R I N G             *
//                                                                           *
//---------------------------------------------------------------------------*

const char * oa_cli_options::
getStringOptionString (const sint32 /* inIndex */) const {
  return "" ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       G E T    S T R I N G    O P T I O N    D E S C R I P T I O N        *
//                                                                           *
//---------------------------------------------------------------------------*

const char * oa_cli_options::
getStringOptionDescription (const sint32 /* inIndex */) const {
  return "" ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//   G E T    S T R I N G    O P T I O N    V A L U E   F R O M   K E Y S    *
//                                                                           *
//---------------------------------------------------------------------------*

C_string oa_cli_options::
getStringOptionValueFromKeys (const char * /* inModuleName */,
                              const char * /* inOptionName */,
                              bool * outFound) const {
  if (* outFound) {
    * outFound = false ;
  }
  return C_string () ;
}

//---------------------------------------------------------------------------*

