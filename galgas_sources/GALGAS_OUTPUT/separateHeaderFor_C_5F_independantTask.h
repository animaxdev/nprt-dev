//-----------------------------------------------------------------------------*
//                                                                             *
//              File 'separateHeaderFor_C_5F_independantTask.h'                *
//                         Generated by version 2.5.8                          *
//                        may 19th, 2014, at 19h44'36"                         *
//                                                                             *
//-----------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//-----------------------------------------------------------------------------*
//                                                                             *
//                Pointer class for @C_independantTask class                 *
//                                                                             *
//-----------------------------------------------------------------------------*

class cPtr_C_5F_independantTask : public cPtr_AC_5F_task {
//--- START OF USER ZONE 2

  public : virtual bool taskDependsOnTask (void) const ;
  public : virtual bool taskDependsOnMessage (void) const ;
  public : virtual uint32_t getTaskDependanceValue (void) const ;
  public : virtual uint32_t getTaskEveryParameter (void) const ;

//--- END OF USER ZONE 2

//--- Attributes

//--- Constructor
  public : cPtr_C_5F_independantTask (LOCATION_ARGS) ;

//--- Attribute accessors
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

