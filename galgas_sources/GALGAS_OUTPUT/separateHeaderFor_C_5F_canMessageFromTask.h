//-----------------------------------------------------------------------------*
//                                                                             *
//             File 'separateHeaderFor_C_5F_canMessageFromTask.h'              *
//                         Generated by version 2.5.8                          *
//                        may 23th, 2014, at 16h50'10"                         *
//                                                                             *
//-----------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//-----------------------------------------------------------------------------*
//                                                                             *
//                Pointer class for @C_canMessageFromTask class                *
//                                                                             *
//-----------------------------------------------------------------------------*

class cPtr_C_5F_canMessageFromTask : public cPtr_AC_5F_canMessage {
//--- START OF USER ZONE 2

  public : virtual bool messageDependsOnTask (void) const ;
  public : virtual bool messageDependsOnMessage (void) const ;
  public : virtual uint32_t getMessageDependanceValue (void) const ;

//--- END OF USER ZONE 2

//--- Attributes
  public : GALGAS_uint mAttribute_mTaskIndex ;

//--- Constructor
  public : cPtr_C_5F_canMessageFromTask (const GALGAS_uint & in_mTaskIndex
                                         COMMA_LOCATION_ARGS) ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_uint reader_mTaskIndex (UNUSED_LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

