//---------------------------------------------------------------------------*
//                                                                           *
//                  File 'include_C_taskDependsFromTask.h'                   *
//         Generated by version GALGAS_BETA_VERSION (LL(1) grammar)          *
//                      april 25th, 2006, at 18h47'51"                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*
//                                                                           *
//                    class 'cPtr_C_taskDependsFromTask'                     *
//                                                                           *
//---------------------------------------------------------------------------*

#ifndef C_taskDependsFromTask_DEFINED
#define C_taskDependsFromTask_DEFINED

class cPtr_C_taskDependsFromTask : public cPtr_AC_task {
  private : typedef cPtr_AC_task inherited ;
//--- START OF USER ZONE 2

  public : virtual bool taskDependsOnTask (void) const ;
  public : virtual bool taskDependsOnMessage (void) const ;
  public : virtual uint32 getTaskDependanceValue (void) const ;
  public : virtual uint32 getTaskEveryParameter (void) const ;

//--- END OF USER ZONE 2

  public : cPtr_C_taskDependsFromTask (const GGS_luint & ,
                                const GGS_luint &  COMMA_LOCATION_ARGS) ;
  public : GGS_luint  mTask ;
  public : GGS_luint  mEvery ;
  public : virtual void appendForDescription (C_Lexique & _inLexique, C_String & ioString COMMA_LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------*

#endif

