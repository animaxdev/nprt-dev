//---------------------------------------------------------------------------*
//                                                                           *
//                         File 'include_AC_task.h'                          *
//         Generated by version GALGAS_BETA_VERSION (LL(1) grammar)          *
//                      april 15th, 2007, at 10h46'31"                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*
//                                                                           *
//                      abstract class 'cPtr_AC_task'                        *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_AC_task : public cPtr__AC_galgas_class {
//--- START OF USER ZONE 2

  public : virtual bool taskDependsOnTask (void) const = 0 ;
  public : virtual bool taskDependsOnMessage (void) const = 0 ;
  public : virtual uint32 getTaskDependanceValue (void) const = 0 ;
  public : virtual uint32 getTaskEveryParameter (void) const = 0 ;

//--- END OF USER ZONE 2

//--- Constructor
  public : cPtr_AC_task (LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_GGS_Object::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected : virtual ~cPtr_AC_task (void) {}
  #endif

//--- Attributes
//--- Method for 'description' reader
  public : virtual void
  appendForDescription (C_Compiler & _inLexique,
                        C_String & ioString,
                        const sint32 inIndentation
                        COMMA_LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------*

