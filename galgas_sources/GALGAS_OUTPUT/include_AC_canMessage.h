//---------------------------------------------------------------------------*
//                                                                           *
//                      File 'include_AC_canMessage.h'                       *
//         Generated by version GALGAS_BETA_VERSION (LL(1) grammar)          *
//                      march 16th, 2006, at 13h14'40"                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*
//                                                                           *
//                   abstract class 'cPtr_AC_canMessage'                     *
//                                                                           *
//---------------------------------------------------------------------------*

#ifndef AC_canMessage_DEFINED
#define AC_canMessage_DEFINED

//---------------------------------------------------------------------------*

class cPtr_AC_canMessage : public GGS_class {
//--- START OF USER ZONE 2

  public : virtual bool messageDependsOnTask (void) const = 0 ;
  public : virtual bool messageDependsOnMessage (void) const = 0 ;
  public : virtual uint32 getMessageDependanceValue (void) const = 0 ;

//--- END OF USER ZONE 2

  public : cPtr_AC_canMessage (LOCATION_ARGS) ;
} ;

//---------------------------------------------------------------------------*

/* class GGG_AC_canMessage : public C_GGS_object {
  public : GGG_AC_canMessage (LOCATION_ARGS) ;
} ; */

//---------------------------------------------------------------------------*

#endif

