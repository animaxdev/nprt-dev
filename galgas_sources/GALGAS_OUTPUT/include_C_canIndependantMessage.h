//---------------------------------------------------------------------------*
//                                                                           *
//                 File 'include_C_canIndependantMessage.h'                  *
//         Generated by version GALGAS_BETA_VERSION (LL(1) grammar)          *
//                       may 28th, 2006, at 19h38'57"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*
//                                                                           *
//                   class 'cPtr_C_canIndependantMessage'                    *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_C_canIndependantMessage : public cPtr_AC_canMessage {
  private : typedef cPtr_AC_canMessage inherited ;
//--- START OF USER ZONE 2

  public : virtual bool messageDependsOnTask (void) const ;
  public : virtual bool messageDependsOnMessage (void) const ;
  public : virtual uint32 getMessageDependanceValue (void) const ;

//--- END OF USER ZONE 2

  public : cPtr_C_canIndependantMessage (LOCATION_ARGS) ;
  public : virtual void appendForDescription (C_Lexique & _inLexique, C_String & ioString COMMA_LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------*

