//---------------------------------------------------------------------------*
//                                                                           *
//                    File 'include_C_independantTask.h'                     *
//         Generated by version GALGAS_BETA_VERSION (LL(1) grammar)          *
//                      march 12th, 2006, at 21h54'25"                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*
//                                                                           *
//                      class 'cPtr_C_independantTask'                       *
//                                                                           *
//---------------------------------------------------------------------------*

#ifndef C_independantTask_DEFINED
#define C_independantTask_DEFINED

class cPtr_C_independantTask : public cPtr_AC_task {
  private : typedef cPtr_AC_task inherited ;
//--- START OF USER ZONE 2

  public : virtual bool taskDependsOnTask (void) const ;
  public : virtual bool taskDependsOnMessage (void) const ;
  public : virtual uint32 getTaskDependanceValue (void) const ;
  public : virtual uint32 getTaskEveryParameter (void) const ;

//--- END OF USER ZONE 2

  public : cPtr_C_independantTask (LOCATION_ARGS) ;
} ;

//---------------------------------------------------------------------------*

class GGG_C_independantTask : public GGG_AC_task {
  private : typedef GGG_AC_task inherited ;
  public : GGG_C_independantTask (LOCATION_ARGS) ;
} ;

//---------------------------------------------------------------------------*

#endif

