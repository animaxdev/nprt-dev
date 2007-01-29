//---------------------------------------------------------------------------*
//                                                                           *
//                File 'include_C_taskDependsFromMessage.h'                  *
//         Generated by version GALGAS_BETA_VERSION (LL(1) grammar)          *
//                     january 29th, 2007, at 20h40'8"                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*
//                                                                           *
//              abstract class 'cPtr_C_taskDependsFromMessage'               *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_C_taskDependsFromMessage : public cPtr_AC_task {
  private : typedef cPtr_AC_task inherited ;
//--- START OF USER ZONE 2

  public : virtual bool taskDependsOnTask (void) const ;
  public : virtual bool taskDependsOnMessage (void) const ;
  public : virtual uint32 getTaskDependanceValue (void) const ;
  public : virtual uint32 getTaskEveryParameter (void) const ;

//--- END OF USER ZONE 2

//--- Constructor
  public : cPtr_C_taskDependsFromMessage (const GGS_luint & ,
                                const GGS_luint &  COMMA_LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_GGS_Object::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected : virtual ~cPtr_C_taskDependsFromMessage (void) {}
  #endif

  public : GGS_luint  mMessage ;
  public : GGS_luint  mEvery ;
//--- Method for 'description' reader
  public : virtual void appendForDescription (C_Lexique & _inLexique,
                                              C_String & ioString,
                                              const sint32 inIndentation
                                              COMMA_LOCATION_ARGS) const ;
//--- Comparison
  public : virtual bool isEqualToObject (const C_GGS_Object * inOperand) const ;
} ;

//---------------------------------------------------------------------------*

