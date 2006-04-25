//---------------------------------------------------------------------------*
//                                                                           *
//                         File 'include_AC_task.h'                          *
//         Generated by version GALGAS_BETA_VERSION (LL(1) grammar)          *
//                      april 25th, 2006, at 18h47'51"                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*
//                                                                           *
//                      abstract class 'cPtr_AC_task'                        *
//                                                                           *
//---------------------------------------------------------------------------*

#ifndef AC_task_DEFINED
#define AC_task_DEFINED

//---------------------------------------------------------------------------*

class cPtr_AC_task : public C_GGS_Object {
//--- START OF USER ZONE 2

  public : virtual bool taskDependsOnTask (void) const = 0 ;
  public : virtual bool taskDependsOnMessage (void) const = 0 ;
  public : virtual uint32 getTaskDependanceValue (void) const = 0 ;
  public : virtual uint32 getTaskEveryParameter (void) const = 0 ;

//--- END OF USER ZONE 2

  public : cPtr_AC_task (LOCATION_ARGS) ;
  public : virtual void appendForDescription (C_Lexique & _inLexique, C_String & ioString COMMA_LOCATION_ARGS) const = 0 ;
} ;

//---------------------------------------------------------------------------*

#endif

