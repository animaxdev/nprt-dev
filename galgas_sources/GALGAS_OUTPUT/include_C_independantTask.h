//---------------------------------------------------------------------------*
//                                                                           *
//                    File 'include_C_independantTask.h'                     *
//                 Generated by version GALGAS_BETA_VERSION                  *
//                     january 17th, 2010, at 19h28'55"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*
//                                                                           *
//                 abstract class 'cPtr_C_independantTask'                   *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_C_independantTask : public cPtr_AC_task {
  private : typedef cPtr_AC_task inherited ;
//--- START OF USER ZONE 2

  public : virtual bool taskDependsOnTask (void) const ;
  public : virtual bool taskDependsOnMessage (void) const ;
  public : virtual PMUInt32 getTaskDependanceValue (void) const ;
  public : virtual PMUInt32 getTaskEveryParameter (void) const ;

//--- END OF USER ZONE 2

//--- Constructor
  public : cPtr_C_independantTask (LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_GGS_Object::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected : virtual ~cPtr_C_independantTask (void) {}
  #endif

//--- Attributes
//--- Class message
  public : virtual const char * instanceMessage (void) const ;
  public : static const char * _static_message (void) ;

//--- Method for 'description' reader
  public : virtual void
  appendForDescription (C_String & ioString,
                        const PMSInt32 inIndentation) const ;

//--- Comparison
  public : virtual bool
  isEqualToObject (const cPtr__AC_galgas_class * inOperand) const ;

//--- Galgas RTTI
  public : virtual AC_galgasClassRunTimeInformationEX * galgasRTTI (void) const ;
} ;

//---------------------------------------------------------------------------*

