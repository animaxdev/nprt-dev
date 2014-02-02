//---------------------------------------------------------------------------*
//                                                                           *
//           File 'separateHeaderFor_C_5F_taskDependsFromTask.h'             *
//                        Generated by version 2.5.4                         *
//                     january 30th, 2014, at 17h15'5"                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//-----------------------------------------------------------------------------*
//                                                                             *
//              Pointer class for @C_taskDependsFromTask class               *
//                                                                             *
//-----------------------------------------------------------------------------*

class cPtr_C_5F_taskDependsFromTask : public cPtr_AC_5F_task {
//--- START OF USER ZONE 2

  public : virtual bool taskDependsOnTask (void) const ;
  public : virtual bool taskDependsOnMessage (void) const ;
  public : virtual PMUInt32 getTaskDependanceValue (void) const ;
  public : virtual PMUInt32 getTaskEveryParameter (void) const ;

//--- END OF USER ZONE 2

//--- Attributes
  public : GALGAS_uint mAttribute_mTask ;
  public : GALGAS_luint mAttribute_mEvery ;

//--- Constructor
  public : cPtr_C_5F_taskDependsFromTask (const GALGAS_uint & in_mTask,
                                          const GALGAS_luint & in_mEvery
                                          COMMA_LOCATION_ARGS) ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_uint reader_mTask (UNUSED_LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_luint reader_mEvery (UNUSED_LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const PMSInt32 inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

