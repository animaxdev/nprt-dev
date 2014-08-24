//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               File 'separateHeaderFor_C_5F_taskDependsFromMessage.h'                                *
//                                             Generated by version 2.7.0                                              *
//                                           august 8th, 2014, at 20h3'48"                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Pointer class for @C_taskDependsFromMessage class                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_C_5F_taskDependsFromMessage : public cPtr_AC_5F_task {
//--- START OF USER ZONE 2

  public : virtual bool taskDependsOnTask (void) const ;
  public : virtual bool taskDependsOnMessage (void) const ;
  public : virtual uint32_t getTaskDependanceValue (void) const ;
  public : virtual uint32_t getTaskEveryParameter (void) const ;

//--- END OF USER ZONE 2

//--- Attributes
  public : GALGAS_uint mAttribute_mMessage ;
  public : GALGAS_luint mAttribute_mEvery ;

//--- Constructor
  public : cPtr_C_5F_taskDependsFromMessage (const GALGAS_uint & in_mMessage,
                                             const GALGAS_luint & in_mEvery
                                             COMMA_LOCATION_ARGS) ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_uint reader_mMessage (UNUSED_LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_luint reader_mEvery (UNUSED_LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

