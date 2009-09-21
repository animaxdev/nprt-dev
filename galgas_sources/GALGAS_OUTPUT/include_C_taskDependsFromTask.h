//---------------------------------------------------------------------------*
//                                                                           *
//                  File 'include_C_taskDependsFromTask.h'                   *
//                 Generated by version GALGAS_BETA_VERSION                  *
//                    september 21th, 2009, at 21h4'48"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*
//                                                                           *
//               abstract class 'cPtr_C_taskDependsFromTask'                 *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_C_taskDependsFromTask : public cPtr_AC_task {
  private : typedef cPtr_AC_task inherited ;
//--- START OF USER ZONE 2

  public : virtual bool taskDependsOnTask (void) const ;
  public : virtual bool taskDependsOnMessage (void) const ;
  public : virtual PMUInt32 getTaskDependanceValue (void) const ;
  public : virtual PMUInt32 getTaskEveryParameter (void) const ;

//--- END OF USER ZONE 2

//--- Constructor
  public : cPtr_C_taskDependsFromTask (const GGS_luint & ,
                                const GGS_luint & 
                                COMMA_LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_GGS_Object::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected : virtual ~cPtr_C_taskDependsFromTask (void) {}
  #endif

//--- Attributes
  public : GGS_luint  mTask ;
  public : GGS_luint  mEvery ;
//--- Class message
  public : virtual const char * _message (void) const ;
  public : static const char * _static_message (void) ;

//--- Method for 'description' reader
  public : virtual void
  appendForDescription (C_Compiler & inLexique,
                        C_String & ioString,
                        const PMSInt32 inIndentation
                        COMMA_LOCATION_ARGS) const ;

//--- Comparison
  public : virtual bool
  isEqualToObject (const cPtr__AC_galgas_class * inOperand) const ;

//--- Galgas RTTI
  public : virtual AC_galgasClassRunTimeInformation * galgasRTTI (void) const ;

//--- Make clone
  public : virtual cPtr__AC_galgas_class * makeClone (void) const ;
} ;

//---------------------------------------------------------------------------*

