//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'oa_semantics.h'                            *
//         Generated by version GALGAS_BETA_VERSION (LL(1) grammar)          *
//                      march 27th, 2006, at 18h52'8"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef oa_semantics_DEFINED
#define oa_semantics_DEFINED

#include <string.h>

#include "galgas/C_GGS_Object.h"
#include "galgas/AC_galgas_io.h"
#include "galgas/GGS_location.h"
#include "galgas/GGS_lbool.h"
#include "galgas/GGS_lchar.h"
#include "galgas/GGS_lstring.h"
#include "galgas/GGS_ldouble.h"
#include "galgas/GGS_luint.h"
#include "galgas/GGS_lsint.h"
#include "galgas/GGS_stringset.h"
#include "galgas/AC_galgas_map.h"
#include "galgas/C_Lexique.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                          Class Predeclarations                            *
//                                                                           *
//---------------------------------------------------------------------------*

class GGS_M_processor ;
class GGS_M_network ;
class GGS_AC_canMessage ;
class GGS_C_canIndependantMessage ;
class GGS_C_canMessageFromMessage ;
class GGS_C_canMessageFromTask ;
class GGS_M_messages ;
class GGS_AC_task ;
class GGS_C_independantTask ;
class GGS_C_taskDependsFromTask ;
class GGS_C_taskDependsFromMessage ;
class GGS_M_tasks ;

//---------------------------------------------------------------------------*
//                                                                           *
//                            Map '@M_processor'                             *
//                                                                           *
//---------------------------------------------------------------------------*

class elementOf_GGS_M_processor ;

class GGS_M_processor : public AC_galgas_map {
//--- Element Class
  public : typedef elementOf_GGS_M_processor element_type ;
//--- Get pointers
  public : inline element_type * rootObject (void) const { return (element_type *) mRoot ; }
  public : inline element_type * firstObject (void) const { return (element_type *) mFirstItem ; }
  public : inline element_type * lastObject (void) const { return (element_type *) mLastItem ; }
//--- Create a new element
  protected : virtual AC_galgas_map_element * new_element (const GGS_lstring & inKey, void * inInfo) ;
//--- Get object pointer (for method call)
  public : inline GGS_M_processor * operator () (UNUSED_LOCATION_ARGS) { return this ; }
//--- 'empty' constructor
  public : static GGS_M_processor constructor_empty (LOCATION_ARGS) ;
//--- Method used for duplicate a map
  protected : virtual void internalInsertForDuplication (AC_galgas_map_element * inPtr) ;
//--- 'insertKey' Insert Method
  public : void methode_insertKey (C_Lexique & inLexique,
                                const GGS_lstring & inKey,
                                const GGS_luint &  inParameter0 COMMA_LOCATION_ARGS) ;
//--- 'searchKey' Search Method
  public : void methode_searchKey (C_Lexique & inLexique,
                                const GGS_lstring & inKey,
                                GGS_luint   & outParameter0 COMMA_LOCATION_ARGS) ;
//--- 'searchKeyGetIndex' Search Method
  public : void methode_searchKeyGetIndex (C_Lexique & inLexique,
                                const GGS_lstring & inKey,
                                GGS_luint & outIndex,
                                GGS_luint   & outParameter0 COMMA_LOCATION_ARGS) ;
//--- Internal method for inserting an element
  protected : void insertElement (C_Lexique & inLexique,
                                  const char * inErrorMessage,
                                  const GGS_lstring & inKey,
                                  const GGS_luint & inParameter0,
                                  GGS_luint * outIndex
                                  COMMA_LOCATION_ARGS) ;
//--- Internal method for searching for an element
  protected : void searchElement (C_Lexique & inLexique,
                                  const char * inErrorMessage,
                                  const GGS_lstring & inKey,
                                  GGS_luint & outParameter0,
                                  GGS_luint * outIndex
                                  COMMA_LOCATION_ARGS) ;
  public : GGS_string reader_description (void) const ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                             Map '@M_network'                              *
//                                                                           *
//---------------------------------------------------------------------------*

class elementOf_GGS_M_network ;

class GGS_M_network : public AC_galgas_map {
//--- Element Class
  public : typedef elementOf_GGS_M_network element_type ;
//--- Get pointers
  public : inline element_type * rootObject (void) const { return (element_type *) mRoot ; }
  public : inline element_type * firstObject (void) const { return (element_type *) mFirstItem ; }
  public : inline element_type * lastObject (void) const { return (element_type *) mLastItem ; }
//--- Create a new element
  protected : virtual AC_galgas_map_element * new_element (const GGS_lstring & inKey, void * inInfo) ;
//--- Get object pointer (for method call)
  public : inline GGS_M_network * operator () (UNUSED_LOCATION_ARGS) { return this ; }
//--- 'empty' constructor
  public : static GGS_M_network constructor_empty (LOCATION_ARGS) ;
//--- Method used for duplicate a map
  protected : virtual void internalInsertForDuplication (AC_galgas_map_element * inPtr) ;
//--- 'insertKey' Insert Method
  public : void methode_insertKey (C_Lexique & inLexique,
                                const GGS_lstring & inKey,
                                const GGS_bool&  inParameter0,
                                const GGS_luint &  inParameter1 COMMA_LOCATION_ARGS) ;
//--- 'searchKey' Search Method
  public : void methode_searchKey (C_Lexique & inLexique,
                                const GGS_lstring & inKey,
                                GGS_bool  & outParameter0,
                                GGS_luint   & outParameter1 COMMA_LOCATION_ARGS) ;
//--- 'searchKeyGetIndex' Search Method
  public : void methode_searchKeyGetIndex (C_Lexique & inLexique,
                                const GGS_lstring & inKey,
                                GGS_luint & outIndex,
                                GGS_bool  & outParameter0,
                                GGS_luint   & outParameter1 COMMA_LOCATION_ARGS) ;
//--- Internal method for inserting an element
  protected : void insertElement (C_Lexique & inLexique,
                                  const char * inErrorMessage,
                                  const GGS_lstring & inKey,
                                  const GGS_bool& inParameter0,
                                  const GGS_luint & inParameter1,
                                  GGS_luint * outIndex
                                  COMMA_LOCATION_ARGS) ;
//--- Internal method for searching for an element
  protected : void searchElement (C_Lexique & inLexique,
                                  const char * inErrorMessage,
                                  const GGS_lstring & inKey,
                                  GGS_bool& outParameter0,
                                  GGS_luint & outParameter1,
                                  GGS_luint * outIndex
                                  COMMA_LOCATION_ARGS) ;
  public : GGS_string reader_description (void) const ;
} ;

class cPtr_AC_canMessage ;

//---------------------------------------------------------------------------*
//                                                                           *
//                     GALGAS class 'GGS_AC_canMessage'                      *
//                                                                           *
//---------------------------------------------------------------------------*

class GGS_AC_canMessage {
  protected : cPtr_AC_canMessage * mPointer ;
  public : GGS_AC_canMessage (void) ;
  public : GGS_AC_canMessage (const GGS_AC_canMessage &) ;
  public : virtual ~GGS_AC_canMessage (void) ;
  public : void operator = (const GGS_AC_canMessage &) ;
  public : inline bool isBuilt (void) const { return mPointer != NULL ; }
  public : inline bool isEqualTo (const GGS_AC_canMessage & operand_) const {
    return mPointer == operand_.mPointer ;
  }
  public : void operator = (cPtr_AC_canMessage * inSource) ;
  public : GGS_AC_canMessage (cPtr_AC_canMessage * inSource) ;
  public : inline cPtr_AC_canMessage * getPtr (void) const {
    return mPointer ;
  }
  public : void drop_operation (void) ;
  public : GGS_string reader_description (void) const ;
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : cPtr_AC_canMessage * operator () (LOCATION_ARGS) const ;
  #else
    public : inline cPtr_AC_canMessage * operator () (LOCATION_ARGS) const { return mPointer ; }
  #endif
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                            Map '@M_messages'                              *
//                                                                           *
//---------------------------------------------------------------------------*

class elementOf_GGS_M_messages ;

class GGS_M_messages : public AC_galgas_map {
//--- Element Class
  public : typedef elementOf_GGS_M_messages element_type ;
//--- Get pointers
  public : inline element_type * rootObject (void) const { return (element_type *) mRoot ; }
  public : inline element_type * firstObject (void) const { return (element_type *) mFirstItem ; }
  public : inline element_type * lastObject (void) const { return (element_type *) mLastItem ; }
//--- Create a new element
  protected : virtual AC_galgas_map_element * new_element (const GGS_lstring & inKey, void * inInfo) ;
//--- Get object pointer (for method call)
  public : inline GGS_M_messages * operator () (UNUSED_LOCATION_ARGS) { return this ; }
//--- 'empty' constructor
  public : static GGS_M_messages constructor_empty (LOCATION_ARGS) ;
//--- Method used for duplicate a map
  protected : virtual void internalInsertForDuplication (AC_galgas_map_element * inPtr) ;
//--- 'insertKey' Insert Method
  public : void methode_insertKey (C_Lexique & inLexique,
                                const GGS_lstring & inKey,
                                const GGS_luint &  inParameter0,
                                const GGS_luint &  inParameter1,
                                const GGS_luint &  inParameter2,
                                const GGS_luint &  inParameter3,
                                const GGS_luint &  inParameter4,
                                const GGS_luint &  inParameter5,
                                const GGS_luint &  inParameter6,
                                const GGS_AC_canMessage &  inParameter7 COMMA_LOCATION_ARGS) ;
//--- 'searchKey' Search Method
  public : void methode_searchKey (C_Lexique & inLexique,
                                const GGS_lstring & inKey,
                                GGS_luint   & outParameter0,
                                GGS_luint   & outParameter1,
                                GGS_luint   & outParameter2,
                                GGS_luint   & outParameter3,
                                GGS_luint   & outParameter4,
                                GGS_luint   & outParameter5,
                                GGS_luint   & outParameter6,
                                GGS_AC_canMessage   & outParameter7 COMMA_LOCATION_ARGS) ;
//--- 'searchKeyGetIndex' Search Method
  public : void methode_searchKeyGetIndex (C_Lexique & inLexique,
                                const GGS_lstring & inKey,
                                GGS_luint & outIndex,
                                GGS_luint   & outParameter0,
                                GGS_luint   & outParameter1,
                                GGS_luint   & outParameter2,
                                GGS_luint   & outParameter3,
                                GGS_luint   & outParameter4,
                                GGS_luint   & outParameter5,
                                GGS_luint   & outParameter6,
                                GGS_AC_canMessage   & outParameter7 COMMA_LOCATION_ARGS) ;
//--- Internal method for inserting an element
  protected : void insertElement (C_Lexique & inLexique,
                                  const char * inErrorMessage,
                                  const GGS_lstring & inKey,
                                  const GGS_luint & inParameter0,
                                  const GGS_luint & inParameter1,
                                  const GGS_luint & inParameter2,
                                  const GGS_luint & inParameter3,
                                  const GGS_luint & inParameter4,
                                  const GGS_luint & inParameter5,
                                  const GGS_luint & inParameter6,
                                  const GGS_AC_canMessage & inParameter7,
                                  GGS_luint * outIndex
                                  COMMA_LOCATION_ARGS) ;
//--- Internal method for searching for an element
  protected : void searchElement (C_Lexique & inLexique,
                                  const char * inErrorMessage,
                                  const GGS_lstring & inKey,
                                  GGS_luint & outParameter0,
                                  GGS_luint & outParameter1,
                                  GGS_luint & outParameter2,
                                  GGS_luint & outParameter3,
                                  GGS_luint & outParameter4,
                                  GGS_luint & outParameter5,
                                  GGS_luint & outParameter6,
                                  GGS_AC_canMessage & outParameter7,
                                  GGS_luint * outIndex
                                  COMMA_LOCATION_ARGS) ;
  public : GGS_string reader_description (void) const ;
} ;

class cPtr_AC_task ;

//---------------------------------------------------------------------------*
//                                                                           *
//                        GALGAS class 'GGS_AC_task'                         *
//                                                                           *
//---------------------------------------------------------------------------*

class GGS_AC_task {
  protected : cPtr_AC_task * mPointer ;
  public : GGS_AC_task (void) ;
  public : GGS_AC_task (const GGS_AC_task &) ;
  public : virtual ~GGS_AC_task (void) ;
  public : void operator = (const GGS_AC_task &) ;
  public : inline bool isBuilt (void) const { return mPointer != NULL ; }
  public : inline bool isEqualTo (const GGS_AC_task & operand_) const {
    return mPointer == operand_.mPointer ;
  }
  public : void operator = (cPtr_AC_task * inSource) ;
  public : GGS_AC_task (cPtr_AC_task * inSource) ;
  public : inline cPtr_AC_task * getPtr (void) const {
    return mPointer ;
  }
  public : void drop_operation (void) ;
  public : GGS_string reader_description (void) const ;
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : cPtr_AC_task * operator () (LOCATION_ARGS) const ;
  #else
    public : inline cPtr_AC_task * operator () (LOCATION_ARGS) const { return mPointer ; }
  #endif
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                              Map '@M_tasks'                               *
//                                                                           *
//---------------------------------------------------------------------------*

class elementOf_GGS_M_tasks ;

class GGS_M_tasks : public AC_galgas_map {
//--- Element Class
  public : typedef elementOf_GGS_M_tasks element_type ;
//--- Get pointers
  public : inline element_type * rootObject (void) const { return (element_type *) mRoot ; }
  public : inline element_type * firstObject (void) const { return (element_type *) mFirstItem ; }
  public : inline element_type * lastObject (void) const { return (element_type *) mLastItem ; }
//--- Create a new element
  protected : virtual AC_galgas_map_element * new_element (const GGS_lstring & inKey, void * inInfo) ;
//--- Get object pointer (for method call)
  public : inline GGS_M_tasks * operator () (UNUSED_LOCATION_ARGS) { return this ; }
//--- 'empty' constructor
  public : static GGS_M_tasks constructor_empty (LOCATION_ARGS) ;
//--- Method used for duplicate a map
  protected : virtual void internalInsertForDuplication (AC_galgas_map_element * inPtr) ;
//--- 'insertKey' Insert Method
  public : void methode_insertKey (C_Lexique & inLexique,
                                const GGS_lstring & inKey,
                                const GGS_luint &  inParameter0,
                                const GGS_luint &  inParameter1,
                                const GGS_luint &  inParameter2,
                                const GGS_luint &  inParameter3,
                                const GGS_luint &  inParameter4,
                                const GGS_luint &  inParameter5,
                                const GGS_luint &  inParameter6,
                                const GGS_AC_task &  inParameter7 COMMA_LOCATION_ARGS) ;
//--- 'searchKey' Search Method
  public : void methode_searchKey (C_Lexique & inLexique,
                                const GGS_lstring & inKey,
                                GGS_luint   & outParameter0,
                                GGS_luint   & outParameter1,
                                GGS_luint   & outParameter2,
                                GGS_luint   & outParameter3,
                                GGS_luint   & outParameter4,
                                GGS_luint   & outParameter5,
                                GGS_luint   & outParameter6,
                                GGS_AC_task   & outParameter7 COMMA_LOCATION_ARGS) ;
//--- 'searchKeyGetIndex' Search Method
  public : void methode_searchKeyGetIndex (C_Lexique & inLexique,
                                const GGS_lstring & inKey,
                                GGS_luint & outIndex,
                                GGS_luint   & outParameter0,
                                GGS_luint   & outParameter1,
                                GGS_luint   & outParameter2,
                                GGS_luint   & outParameter3,
                                GGS_luint   & outParameter4,
                                GGS_luint   & outParameter5,
                                GGS_luint   & outParameter6,
                                GGS_AC_task   & outParameter7 COMMA_LOCATION_ARGS) ;
//--- Internal method for inserting an element
  protected : void insertElement (C_Lexique & inLexique,
                                  const char * inErrorMessage,
                                  const GGS_lstring & inKey,
                                  const GGS_luint & inParameter0,
                                  const GGS_luint & inParameter1,
                                  const GGS_luint & inParameter2,
                                  const GGS_luint & inParameter3,
                                  const GGS_luint & inParameter4,
                                  const GGS_luint & inParameter5,
                                  const GGS_luint & inParameter6,
                                  const GGS_AC_task & inParameter7,
                                  GGS_luint * outIndex
                                  COMMA_LOCATION_ARGS) ;
//--- Internal method for searching for an element
  protected : void searchElement (C_Lexique & inLexique,
                                  const char * inErrorMessage,
                                  const GGS_lstring & inKey,
                                  GGS_luint & outParameter0,
                                  GGS_luint & outParameter1,
                                  GGS_luint & outParameter2,
                                  GGS_luint & outParameter3,
                                  GGS_luint & outParameter4,
                                  GGS_luint & outParameter5,
                                  GGS_luint & outParameter6,
                                  GGS_AC_task & outParameter7,
                                  GGS_luint * outIndex
                                  COMMA_LOCATION_ARGS) ;
  public : GGS_string reader_description (void) const ;
} ;

void routine_performComputations (C_Lexique &,
                                GGS_M_processor  &,
                                GGS_M_network  &,
                                GGS_M_messages  &,
                                GGS_M_tasks  & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                      Element of map '@M_processor'                        *
//                                                                           *
//---------------------------------------------------------------------------*

class e_M_processor {
  public : GGS_luint  mStep ;
} ;

//---------------------------------------------------------------------------*

class elementOf_GGS_M_processor : public AC_galgas_map_element {
//--- Constructor
  public : elementOf_GGS_M_processor (const GGS_lstring & inKey,
                                    const sint32 inIndex,
                                     const e_M_processor & inInfo) ;
//--- Get pointers
  public : inline elementOf_GGS_M_processor * nextObject (void) const { return (elementOf_GGS_M_processor *) mNextItem ; }
  public : inline elementOf_GGS_M_processor * infObject (void) const { return (elementOf_GGS_M_processor *) mInfPtr ; }
  public : inline elementOf_GGS_M_processor * supObject (void) const { return (elementOf_GGS_M_processor *) mSupPtr ; }
//--- Data member
  public : e_M_processor mInfo ;
//--- Method for 'description' reader
  public : void appendForMapDescription (C_String & ioString) const ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                       Element of map '@M_network'                         *
//                                                                           *
//---------------------------------------------------------------------------*

class e_M_network {
  public : GGS_bool mCANnetwork ;
  public : GGS_luint  mScalingFactor ;
} ;

//---------------------------------------------------------------------------*

class elementOf_GGS_M_network : public AC_galgas_map_element {
//--- Constructor
  public : elementOf_GGS_M_network (const GGS_lstring & inKey,
                                    const sint32 inIndex,
                                     const e_M_network & inInfo) ;
//--- Get pointers
  public : inline elementOf_GGS_M_network * nextObject (void) const { return (elementOf_GGS_M_network *) mNextItem ; }
  public : inline elementOf_GGS_M_network * infObject (void) const { return (elementOf_GGS_M_network *) mInfPtr ; }
  public : inline elementOf_GGS_M_network * supObject (void) const { return (elementOf_GGS_M_network *) mSupPtr ; }
//--- Data member
  public : e_M_network mInfo ;
//--- Method for 'description' reader
  public : void appendForMapDescription (C_String & ioString) const ;
} ;

//---------------------------------------------------------------------------*


#include "include_AC_canMessage.h"

//---------------------------------------------------------------------------*
//                                                                           *
//                     class 'C_canIndependantMessage'                       *
//                                                                           *
//---------------------------------------------------------------------------*


#include "include_C_canIndependantMessage.h"

//---------------------------------------------------------------------------*
//                                                                           *
//                GALGAS class 'GGS_C_canIndependantMessage'                 *
//                                                                           *
//---------------------------------------------------------------------------*

class GGS_C_canIndependantMessage {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : static cPtr_C_canIndependantMessage * constructor_new (LOCATION_ARGS) ;
  #else
    public : inline static cPtr_C_canIndependantMessage * constructor_new (LOCATION_ARGS) {
      return new cPtr_C_canIndependantMessage(THERE) ;
    }
  #endif
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                     class 'C_canMessageFromMessage'                       *
//                                                                           *
//---------------------------------------------------------------------------*


#include "include_C_canMessageFromMessage.h"

//---------------------------------------------------------------------------*
//                                                                           *
//                GALGAS class 'GGS_C_canMessageFromMessage'                 *
//                                                                           *
//---------------------------------------------------------------------------*

class GGS_C_canMessageFromMessage {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : static cPtr_C_canMessageFromMessage * constructor_new (const GGS_luint & argument_0 COMMA_LOCATION_ARGS) ;
  #else
    public : inline static cPtr_C_canMessageFromMessage * constructor_new (const GGS_luint & argument_0 COMMA_LOCATION_ARGS) {
      return new cPtr_C_canMessageFromMessage(argument_0 COMMA_THERE) ;
    }
  #endif
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                       class 'C_canMessageFromTask'                        *
//                                                                           *
//---------------------------------------------------------------------------*


#include "include_C_canMessageFromTask.h"

//---------------------------------------------------------------------------*
//                                                                           *
//                 GALGAS class 'GGS_C_canMessageFromTask'                   *
//                                                                           *
//---------------------------------------------------------------------------*

class GGS_C_canMessageFromTask {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : static cPtr_C_canMessageFromTask * constructor_new (const GGS_luint & argument_0 COMMA_LOCATION_ARGS) ;
  #else
    public : inline static cPtr_C_canMessageFromTask * constructor_new (const GGS_luint & argument_0 COMMA_LOCATION_ARGS) {
      return new cPtr_C_canMessageFromTask(argument_0 COMMA_THERE) ;
    }
  #endif
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                       Element of map '@M_messages'                        *
//                                                                           *
//---------------------------------------------------------------------------*

class e_M_messages {
  public : GGS_luint  mClass ;
  public : GGS_luint  mNetworkIndex ;
  public : GGS_luint  mBytesCount ;
  public : GGS_luint  mPriority ;
  public : GGS_luint  mOffset ;
  public : GGS_luint  mDeadline ;
  public : GGS_luint  mPeriod ;
  public : GGS_AC_canMessage  mMessageKind ;
} ;

//---------------------------------------------------------------------------*

class elementOf_GGS_M_messages : public AC_galgas_map_element {
//--- Constructor
  public : elementOf_GGS_M_messages (const GGS_lstring & inKey,
                                    const sint32 inIndex,
                                     const e_M_messages & inInfo) ;
//--- Get pointers
  public : inline elementOf_GGS_M_messages * nextObject (void) const { return (elementOf_GGS_M_messages *) mNextItem ; }
  public : inline elementOf_GGS_M_messages * infObject (void) const { return (elementOf_GGS_M_messages *) mInfPtr ; }
  public : inline elementOf_GGS_M_messages * supObject (void) const { return (elementOf_GGS_M_messages *) mSupPtr ; }
//--- Data member
  public : e_M_messages mInfo ;
//--- Method for 'description' reader
  public : void appendForMapDescription (C_String & ioString) const ;
} ;

//---------------------------------------------------------------------------*


#include "include_AC_task.h"

//---------------------------------------------------------------------------*
//                                                                           *
//                        class 'C_independantTask'                          *
//                                                                           *
//---------------------------------------------------------------------------*


#include "include_C_independantTask.h"

//---------------------------------------------------------------------------*
//                                                                           *
//                   GALGAS class 'GGS_C_independantTask'                    *
//                                                                           *
//---------------------------------------------------------------------------*

class GGS_C_independantTask {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : static cPtr_C_independantTask * constructor_new (LOCATION_ARGS) ;
  #else
    public : inline static cPtr_C_independantTask * constructor_new (LOCATION_ARGS) {
      return new cPtr_C_independantTask(THERE) ;
    }
  #endif
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                      class 'C_taskDependsFromTask'                        *
//                                                                           *
//---------------------------------------------------------------------------*


#include "include_C_taskDependsFromTask.h"

//---------------------------------------------------------------------------*
//                                                                           *
//                 GALGAS class 'GGS_C_taskDependsFromTask'                  *
//                                                                           *
//---------------------------------------------------------------------------*

class GGS_C_taskDependsFromTask {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : static cPtr_C_taskDependsFromTask * constructor_new (const GGS_luint & argument_0,
                                const GGS_luint & argument_1 COMMA_LOCATION_ARGS) ;
  #else
    public : inline static cPtr_C_taskDependsFromTask * constructor_new (const GGS_luint & argument_0,
                                const GGS_luint & argument_1 COMMA_LOCATION_ARGS) {
      return new cPtr_C_taskDependsFromTask(argument_0,
                                argument_1 COMMA_THERE) ;
    }
  #endif
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                     class 'C_taskDependsFromMessage'                      *
//                                                                           *
//---------------------------------------------------------------------------*


#include "include_C_taskDependsFromMessage.h"

//---------------------------------------------------------------------------*
//                                                                           *
//               GALGAS class 'GGS_C_taskDependsFromMessage'                 *
//                                                                           *
//---------------------------------------------------------------------------*

class GGS_C_taskDependsFromMessage {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : static cPtr_C_taskDependsFromMessage * constructor_new (const GGS_luint & argument_0,
                                const GGS_luint & argument_1 COMMA_LOCATION_ARGS) ;
  #else
    public : inline static cPtr_C_taskDependsFromMessage * constructor_new (const GGS_luint & argument_0,
                                const GGS_luint & argument_1 COMMA_LOCATION_ARGS) {
      return new cPtr_C_taskDependsFromMessage(argument_0,
                                argument_1 COMMA_THERE) ;
    }
  #endif
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                        Element of map '@M_tasks'                          *
//                                                                           *
//---------------------------------------------------------------------------*

class e_M_tasks {
  public : GGS_luint  mPriority ;
  public : GGS_luint  mOffset ;
  public : GGS_luint  mDeadline ;
  public : GGS_luint  mDurationMin ;
  public : GGS_luint  mDurationMax ;
  public : GGS_luint  mProcessor ;
  public : GGS_luint  mPeriod ;
  public : GGS_AC_task  mTaskKind ;
} ;

//---------------------------------------------------------------------------*

class elementOf_GGS_M_tasks : public AC_galgas_map_element {
//--- Constructor
  public : elementOf_GGS_M_tasks (const GGS_lstring & inKey,
                                    const sint32 inIndex,
                                     const e_M_tasks & inInfo) ;
//--- Get pointers
  public : inline elementOf_GGS_M_tasks * nextObject (void) const { return (elementOf_GGS_M_tasks *) mNextItem ; }
  public : inline elementOf_GGS_M_tasks * infObject (void) const { return (elementOf_GGS_M_tasks *) mInfPtr ; }
  public : inline elementOf_GGS_M_tasks * supObject (void) const { return (elementOf_GGS_M_tasks *) mSupPtr ; }
//--- Data member
  public : e_M_tasks mInfo ;
//--- Method for 'description' reader
  public : void appendForMapDescription (C_String & ioString) const ;
} ;

//---------------------------------------------------------------------------*

#endif
