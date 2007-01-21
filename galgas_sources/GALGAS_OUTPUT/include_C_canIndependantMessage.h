//---------------------------------------------------------------------------*
//                                                                           *
//                 File 'include_C_canIndependantMessage.h'                  *
//         Generated by version GALGAS_BETA_VERSION (LL(1) grammar)          *
//                     january 21th, 2007, at 20h49'48"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*
//                                                                           *
//              abstract class 'cPtr_C_canIndependantMessage'                *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_C_canIndependantMessage : public cPtr_AC_canMessage {
  private : typedef cPtr_AC_canMessage inherited ;
//--- START OF USER ZONE 2

  public : virtual bool messageDependsOnTask (void) const ;
  public : virtual bool messageDependsOnMessage (void) const ;
  public : virtual uint32 getMessageDependanceValue (void) const ;

//--- END OF USER ZONE 2

//--- Constructor
  public : cPtr_C_canIndependantMessage (LOCATION_ARGS) ;

//--- Declaring a protected virual desstructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_GGS_Object::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected : virtual ~cPtr_C_canIndependantMessage (void) {}
  #endif

//--- Method for 'description' reader
  public : virtual void appendForDescription (C_Lexique & _inLexique,
                                              C_String & ioString,
                                              const sint32 inIndentation
                                              COMMA_LOCATION_ARGS) const ;
//--- Comparison
  public : virtual bool isEqualToObject (const C_GGS_Object * inOperand) const ;
} ;

//---------------------------------------------------------------------------*

