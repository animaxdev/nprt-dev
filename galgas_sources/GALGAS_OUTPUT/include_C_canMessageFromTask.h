//---------------------------------------------------------------------------*
//                                                                           *
//                  File 'include_C_canMessageFromTask.h'                    *
//         Generated by version GALGAS_BETA_VERSION (LL(1) grammar)          *
//                      march 16th, 2006, at 13h14'40"                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*
//                                                                           *
//                    class 'cPtr_C_canMessageFromTask'                      *
//                                                                           *
//---------------------------------------------------------------------------*

#ifndef C_canMessageFromTask_DEFINED
#define C_canMessageFromTask_DEFINED

class cPtr_C_canMessageFromTask : public cPtr_AC_canMessage {
  private : typedef cPtr_AC_canMessage inherited ;
//--- START OF USER ZONE 2

  public : virtual bool messageDependsOnTask (void) const ;
  public : virtual bool messageDependsOnMessage (void) const ;
  public : virtual uint32 getMessageDependanceValue (void) const ;

//--- END OF USER ZONE 2

  public : cPtr_C_canMessageFromTask (const GGS_luint &  COMMA_LOCATION_ARGS) ;
  public : GGS_luint  mTaskIndex ;
} ;

//---------------------------------------------------------------------------*

/* class GGG_C_canMessageFromTask : public GGG_AC_canMessage {
  private : typedef GGG_AC_canMessage inherited ;
  public : GGG_C_canMessageFromTask (const GGS_luint &  COMMA_LOCATION_ARGS) ;
} ; */

//---------------------------------------------------------------------------*

#endif

