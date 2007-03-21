//---------------------------------------------------------------------------*
//                                                                           *
//                         File 'oa_cli_options.h'                           *
//         Generated by version GALGAS_BETA_VERSION (LL(1) grammar)          *
//                      march 21th, 2007, at 14h50'44"                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef oa_cli_options_0_DEFINED
#define oa_cli_options_0_DEFINED
#include "command_line_interface/AC_CLI_Options.h"

//---------------------------------------------------------------------------*

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                  Command Line Options definitions class                   *
//                                                                           *
//---------------------------------------------------------------------------*

class oa_cli_options : public AC_CLI_Options {
//--- Constructor
  public : oa_cli_options (void) ;

//--- Boolean Command Line Interface Options
  public : virtual sint32 getBoolOptionsCount (void) const ;

  public : virtual bool
  getBoolOptionValue (const sint32 inIndex) const ;

  public : virtual void
  setBoolOptionValue (const sint32 inIndex, const bool inValue) ;

  public : virtual char
  getBoolOptionChar (const sint32 inIndex) const ;

  public : virtual const char *
  getBoolOptionString (const sint32 inIndex) const ;

  public : virtual const char *
  getBoolOptionDescription (const sint32 inIndex) const ;

  public : virtual bool
  boolOptionValueFromKeys (const char * inModuleName,
                           const char * inOptionName,
                           bool * outFound) const ;


//--- Unsigned integer Command Line Interface Options
  public : virtual sint32 getUintOptionsCount (void) const ;

  public : virtual uint32
  getUintOptionValue (const sint32 inIndex) const ;

  public : virtual uint32
  getUintOptionDefaultValue (const sint32 inIndex) const ;

  public : virtual void
  setUintOptionValue (const sint32 inIndex, const uint32 inValue) ;

  public : virtual char
  getUintOptionChar (const sint32 inIndex) const ;

  public : virtual const char *
  getUintOptionString (const sint32 inIndex) const ;

  public : virtual const char *
  getUintOptionDescription (const sint32 inIndex) const ;

  public : virtual uint32
  uintOptionValueFromKeys (const char * inModuleName,
                           const char * inOptionName,
                           bool * outFound) const ;

//--- String Command Line Interface Options
  public : virtual sint32 getStringOptionsCount (void) const ;

  public : virtual C_String
  getStringOptionValue (const sint32 inIndex) const ;

  public : virtual void
  setStringOptionValue (const sint32 inIndex, const C_String & inValue) ;

  public : virtual char
  getStringOptionChar (const sint32 inIndex) const ;

  public : virtual const char *
  getStringOptionString (const sint32 inIndex) const ;

  public : virtual const char *
  getStringOptionDescription (const sint32 inIndex) const ;

  public : virtual C_String
  stringOptionValueFromKeys (const char * inModuleName,
                             const char * inOptionName,
                             bool * outFound) const ;

//--- Private arraies : current options values
  private : bool mBoolOptionValues [4] ;
  private : uint32 mUintOptionValues [1] ;
  private : C_String mStringOptionValues [1] ;
  private : TC_UniqueArray <C_String> mStringValue ;
} ;

//---------------------------------------------------------------------------*

#endif
