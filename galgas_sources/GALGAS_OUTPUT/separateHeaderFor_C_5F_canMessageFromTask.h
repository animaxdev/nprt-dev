//---------------------------------------------------------------------------*
//                                                                           *
//            File 'separateHeaderFor_C_5F_canMessageFromTask.h'             *
//             Generated by version version GALGAS_BETA_VERSION              *
//                      july 16th, 2011, at 15h22'10"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*
//                                                                           *
//               Pointer class for @C_canMessageFromTask class               *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_C_5F_canMessageFromTask : public cPtr_AC_5F_canMessage {
//--- START OF USER ZONE 2

  public : virtual bool messageDependsOnTask (void) const ;
  public : virtual bool messageDependsOnMessage (void) const ;
  public : virtual PMUInt32 getMessageDependanceValue (void) const ;

//--- END OF USER ZONE 2

//--- Attributes
  public : GALGAS_uint mAttribute_mTaskIndex ;

//--- Constructor
  public : cPtr_C_5F_canMessageFromTask (const GALGAS_uint & in_mTaskIndex
                                         COMMA_LOCATION_ARGS) ;

//--- Description
  public : virtual void description (C_String & ioString,
                                     const PMSInt32 inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

