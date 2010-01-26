//---------------------------------------------------------------------------*
//                                                                           *
//                      File 'include_AC_canMessage.h'                       *
//                 Generated by version GALGAS_BETA_VERSION                  *
//                     january 24th, 2010, at 10h7'45"                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*
//                                                                           *
//                   abstract class 'cPtr_AC_canMessage'                     *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_AC_canMessage : public cPtr__AC_galgas_class {
//--- START OF USER ZONE 2

  public : virtual bool messageDependsOnTask (void) const = 0 ;
  public : virtual bool messageDependsOnMessage (void) const = 0 ;
  public : virtual PMUInt32 getMessageDependanceValue (void) const = 0 ;

//--- END OF USER ZONE 2

//--- Constructor
  public : cPtr_AC_canMessage (LOCATION_ARGS) ;

//--- Attributes
//--- Class message
  public : virtual const char * instanceMessage (void) const ;
  public : static const char * _static_message (void) ;

//--- Method for 'description' reader
  public : virtual void
  appendForDescription (C_String & ioString,
                        const PMSInt32 inIndentation) const ;

//--- Galgas RTTI
  public : virtual AC_galgasClassRunTimeInformationEX * galgasRTTI (void) const ;
} ;

//---------------------------------------------------------------------------*

