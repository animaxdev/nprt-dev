//---------------------------------------------------------------------------*
//                                                                           *
//     C++ class for implementing UNIQUE STACK for activities to schedule    *
//                                                                           *
//  Copyright (C) 2004 Pierre Molinaro.                                      *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*
//  ECN, Ecole Centrale de Nantes                                            *
//                                                                           *
//  This program is free software; you can redistribute it and/or modify it  *
//  under the terms of the GNU General Public License as published by the    *
//  Free Software Foundation.                                                *
//                                                                           *
//  This program is distributed in the hope it will be useful, but WITHOUT   *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or    *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for *
//   more details.                                                           *
//                                                                           *
//---------------------------------------------------------------------------*

#include "C_VDL_hashmap.h"

//---------------------------------------------------------------------------*

#include <stddef.h>
#include <string.h>
#include <limits.h>

//---------------------------------------------------------------------------*
//                                                                           *
//  VDD objects hash map                                                     *
//                                                                           *
//---------------------------------------------------------------------------*

static C_VDL_hashmap gMap ;

//---------------------------------------------------------------------------*

void C_activitiesToSchedule::reallocUniqueTable (const PMSInt32 inTableUniqueNewSize) {
  gMap.reallocMap (inTableUniqueNewSize) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//  Static VDL variable used as root of all existing C_activitiesToSchedule instances        *
//                                                                           *
//---------------------------------------------------------------------------*

static C_activitiesToSchedule gVDLlistRoot ;

//---------------------------------------------------------------------------*
//                                                                           *
//       Node count : for giving an unique ID to every node                  *
//                                                                           *
//---------------------------------------------------------------------------*

PMSInt32 C_activitiesToSchedule::smNodeCount = 0 ;

//---------------------------------------------------------------------------*
//                                                                           *
//       Default constructor                                                 *
//                                                                           *
//---------------------------------------------------------------------------*

C_activitiesToSchedule::C_activitiesToSchedule (void) :
mPtrToNextExisting (this),
mPtrToPreviousExisting (this),
mRootPointer (NULL) {
//--- Link
  initLinks () ;
}

//---------------------------------------------------------------------------*

void C_activitiesToSchedule::initLinks (void) {
  mPtrToNextExisting = this ;
  mPtrToPreviousExisting = this ;
  C_activitiesToSchedule * nextFromRoot = gVDLlistRoot.mPtrToNextExisting ;
  mPtrToPreviousExisting = & gVDLlistRoot ;
  nextFromRoot->mPtrToPreviousExisting = this ;
  mPtrToNextExisting = nextFromRoot ;
  gVDLlistRoot.mPtrToNextExisting = this ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Destructor                                                          *
//                                                                           *
//---------------------------------------------------------------------------*

C_activitiesToSchedule::~C_activitiesToSchedule (void) {
  mRootPointer = (cVDLnodeInfo *) NULL ;
//--- Unlink
  C_activitiesToSchedule * next = mPtrToNextExisting ;
  C_activitiesToSchedule * previous = mPtrToPreviousExisting ;
  previous->mPtrToNextExisting = next ;
  next->mPtrToPreviousExisting = previous ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Set to NULL vector                                                  *
//                                                                           *
//---------------------------------------------------------------------------*

void C_activitiesToSchedule::setToEmptyList (void) {
  mRootPointer = (cVDLnodeInfo *) NULL ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Set to NULL vector                                                  *
//                                                                           *
//---------------------------------------------------------------------------*

bool C_activitiesToSchedule::isListEmpty (void) const {
  return mRootPointer == NULL ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Vector comparison                                                   *
//                                                                           *
//---------------------------------------------------------------------------*

bool C_activitiesToSchedule::
operator == (const C_activitiesToSchedule & inOperand) const {
  return mRootPointer == inOperand.mRootPointer ;
}

//---------------------------------------------------------------------------*

bool C_activitiesToSchedule::
operator != (const C_activitiesToSchedule & inOperand) const {
  return mRootPointer != inOperand.mRootPointer ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Enter a value                                                       *
//                                                                           *
//---------------------------------------------------------------------------*

C_activitiesToSchedule::cVDLnodeInfo * C_activitiesToSchedule::
internalAddEntry (const PMSInt32 inActivityIndex,
                  const PMSInt32 inActivityPriority,
                  const PMSInt32 inActivityScheduleInstant,
                  cVDLnodeInfo * const inPointerToNext) {
  cVDLnodeInfo * p ;
  if (inPointerToNext == NULL) {
    p = find_or_add (inActivityIndex, 
                     inActivityPriority,
                     inActivityScheduleInstant,
                     NULL) ;
  }else{
    bool insertOnTop = inActivityScheduleInstant < inPointerToNext->mScheduleInstant ;
    if ((! insertOnTop) && (inActivityScheduleInstant == inPointerToNext->mScheduleInstant)) {
      insertOnTop = inActivityPriority < inPointerToNext->mActivityPriority ;
      if ((! insertOnTop) && (inActivityPriority == inPointerToNext->mActivityPriority)) {
        insertOnTop = inActivityIndex < inPointerToNext->mActivityIndex ;
      }
    }
    if (insertOnTop) {
      p = find_or_add (inActivityIndex, 
                       inActivityPriority,
                       inActivityScheduleInstant,
                       inPointerToNext) ;
    }else{
      cVDLnodeInfo * temp = internalAddEntry (inActivityIndex, 
                                              inActivityPriority,
                                              inActivityScheduleInstant,
                                              inPointerToNext->mPtrToNext) ;
     p = find_or_add (inPointerToNext->mActivityIndex,
                      inPointerToNext->mActivityPriority,
                      inPointerToNext->mScheduleInstant,
                      temp) ;   
    }
  }
  return p ;
}

//---------------------------------------------------------------------------*

void C_activitiesToSchedule::
addEntry (const PMSInt32 inActivityIndex,
          const PMSInt32 inActivityPriority,
          const PMSInt32 inActivityScheduleInstant) {
//--- Check that entry index is unique
  bool unique = true ;
  cVDLnodeInfo * p = mRootPointer ;
  while (unique && (p != NULL)) {
    unique = inActivityIndex != p->mActivityIndex ;
    p = p->mPtrToNext ;
  }
//--- Perform entry
  if (unique) {
//    bool cacheSuccess ;
//    PMSInt32 hashCode ;
//    PMSInt32 result ;
//    gAddEntryCache.getCacheEntry (inActivityIndex, inActivityPriority, inActivityScheduleInstant, 
//                                  cacheSuccess, hashCode, result) ;
//    if (cacheSuccess) {
//      mRootPointer = (cVDLnodeInfo *) result ;
//    }else{
      mRootPointer = internalAddEntry (inActivityIndex,
                                       inActivityPriority,
                                       inActivityScheduleInstant,
                                       mRootPointer) ;
//      gAddEntryCache.writeCacheEntry (inActivityIndex, inActivityPriority, inActivityScheduleInstant,
//                                      hashCode, (PMSInt32) mRootPointer) ;
//    }
  }else{
    co << "**** ERROR !!! Activity index "
       << cStringWithSigned (inActivityIndex)
       << " already exists in schedule activity list at schedule instant "
       << cStringWithSigned (inActivityScheduleInstant)
       << " ****\n" ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Get first activity to schedule                                      *
//                                                                           *
//---------------------------------------------------------------------------*

void C_activitiesToSchedule::
internalGetFirstToScheduleAndSuppress (cVDLnodeInfo * & ioPtr,
                            const PMSInt32 inActivityIndex) {
  cVDLnodeInfo * result = ioPtr->mPtrToNext ;
  if (ioPtr->mActivityIndex != inActivityIndex) {
    internalGetFirstToScheduleAndSuppress (result, inActivityIndex) ;
    result = find_or_add (ioPtr->mActivityIndex,
                          ioPtr->mActivityPriority,
                          ioPtr->mScheduleInstant,
                          result) ;
  }
  ioPtr = result ;
}
//---------------------------------------------------------------------------*

PMSInt32 C_activitiesToSchedule::
getFirstToScheduleAndSuppress (const PMSInt32 inCurrentInstant) {
  PMSInt32 activityIndex = -1 ; // Means none
  if ((mRootPointer != NULL) && (mRootPointer->mScheduleInstant <= inCurrentInstant)) {
  //--- Find min priority activity
    PMSInt32 priority = mRootPointer->mActivityPriority ;
    activityIndex = mRootPointer->mActivityIndex ;
    cVDLnodeInfo * p = mRootPointer->mPtrToNext ;
    while ((p != NULL) && (p->mScheduleInstant <= inCurrentInstant)) {
      if (priority > p->mActivityPriority) {
        priority = p->mActivityPriority ;
        activityIndex = p->mActivityIndex ;
      }
      p = p->mPtrToNext ;
    }
    internalGetFirstToScheduleAndSuppress (mRootPointer, activityIndex) ;
  }
  return activityIndex ;
}
//---------------------------------------------------------------------------*
//static 
void LowerPriorityOnResource (PMSInt32 & lowerPriority, const PMSInt32 activityIndex, 
                              const PMSInt32 ResourceIndex,
                              const TC_UniqueArray <cActivity> & inActivities){                             
  if (activityIndex >= 0){
	  PMSInt32 successorIndex = inActivities (activityIndex COMMA_HERE).mSuccessorId;
	  if (successorIndex >= 0){
	    if ( (ResourceIndex == inActivities (successorIndex COMMA_HERE).mResourceId)
	       &&
        ( (inActivities (successorIndex COMMA_HERE).mOccurrence % inActivities (successorIndex COMMA_HERE).mEvery) == 0 ) ){   
	      lowerPriority = MAX(lowerPriority, inActivities (successorIndex COMMA_HERE).mPriority);
	   	  LowerPriorityOnResource (lowerPriority, successorIndex, ResourceIndex, inActivities);
   	  }	
	  	PMSInt32 OtherHeirId = inActivities (successorIndex COMMA_HERE).mOtherHeirId ;
		  while ( OtherHeirId >= 0 ) {
		    if ( (ResourceIndex == inActivities (OtherHeirId COMMA_HERE).mResourceId)
		       &&
           ( (inActivities (OtherHeirId COMMA_HERE).mOccurrence % inActivities (OtherHeirId COMMA_HERE).mEvery) == 0 ) ){ 
			    lowerPriority = MAX(lowerPriority, inActivities (OtherHeirId COMMA_HERE).mPriority);
	        LowerPriorityOnResource (lowerPriority, OtherHeirId, ResourceIndex, inActivities);
	      }
			  OtherHeirId = inActivities (OtherHeirId COMMA_HERE).mOtherHeirId;
	  	}
	  }                                
  }                                  
}
//---------------------------------------------------------------------------*
PMSInt32 C_activitiesToSchedule::
getLowerPriority (const PMSInt32 currentActivityIndex, 
                  const TC_UniqueArray <cActivity> & inActivities) {
  PMSInt32 lowerPriority = 0 ; 
  PMSInt32 activityIndex = currentActivityIndex ;// Means none
  PMSInt32 ResourceIndex = inActivities (activityIndex COMMA_HERE).mResourceId;
  LowerPriorityOnResource (lowerPriority, currentActivityIndex, ResourceIndex, inActivities);
  if (mRootPointer != NULL) {
  //--- Find min priority activity
    activityIndex = mRootPointer->mActivityIndex ;
    lowerPriority = MAX(lowerPriority, inActivities (activityIndex COMMA_HERE).mPriority);
    LowerPriorityOnResource (lowerPriority, activityIndex, ResourceIndex, inActivities); 
    cVDLnodeInfo * p = mRootPointer->mPtrToNext ;
    while (p != NULL) {
      activityIndex = p->mActivityIndex ;
      lowerPriority = MAX(lowerPriority, inActivities (activityIndex COMMA_HERE).mPriority);
      LowerPriorityOnResource (lowerPriority, activityIndex, ResourceIndex, inActivities); 
      p = p->mPtrToNext ;
    }
  }
  return lowerPriority ;
}
//---------------------------------------------------------------------------*
//static 
void SuccessorsMaxBusyDuration (PMSInt32 & ioBusyDuration, const PMSInt32 activityIndex, 
                                const PMSInt32 ResourceIndex,
                                const TC_UniqueArray <cActivity> & inActivities){
                              
  if (activityIndex >= 0){
	  PMSInt32 successorIndex = inActivities (activityIndex COMMA_HERE).mSuccessorId;
	  if (successorIndex >= 0){
	    if ( (ResourceIndex == inActivities (successorIndex COMMA_HERE).mResourceId)
	        &&
          ( (inActivities (successorIndex COMMA_HERE).mOccurrence % inActivities (successorIndex COMMA_HERE).mEvery) == 0 ) ){   
	   
	  		ioBusyDuration += inActivities (successorIndex COMMA_HERE).mOffset +
	  		                  inActivities (successorIndex COMMA_HERE).mMaxDuration ;
	  	  SuccessorsMaxBusyDuration(ioBusyDuration, successorIndex, ResourceIndex, inActivities);
	  	}	
	  	PMSInt32 OtherHeirId = inActivities (successorIndex COMMA_HERE).mOtherHeirId ;
		  while ( OtherHeirId >= 0 ) {
		    if ( (ResourceIndex == inActivities (OtherHeirId COMMA_HERE).mResourceId)
		       &&
           ( (inActivities (OtherHeirId COMMA_HERE).mOccurrence % inActivities (OtherHeirId COMMA_HERE).mEvery) == 0 ) ){   
	   
			    ioBusyDuration += inActivities (OtherHeirId COMMA_HERE).mOffset + 
			                      inActivities (OtherHeirId COMMA_HERE).mMaxDuration;
	        SuccessorsMaxBusyDuration(ioBusyDuration, OtherHeirId, ResourceIndex, inActivities);
	      }
			  OtherHeirId = inActivities (OtherHeirId COMMA_HERE).mOtherHeirId;
	  	}
	  }                                
  }                                  
}
//---------------------------------------------------------------------------*
PMSInt32 C_activitiesToSchedule::
getMaximumBusyPeriod (const PMSInt32 currentActivityIndex, 
                      const TC_UniqueArray <cActivity> & inActivities) {
 
  PMSInt32 BusyDuration=0;
  const PMSInt32 ResourceIndex = inActivities (currentActivityIndex COMMA_HERE).mResourceId;
  SuccessorsMaxBusyDuration (BusyDuration, currentActivityIndex, ResourceIndex, inActivities);
  if (mRootPointer != NULL){
    PMSInt32 activityIndex = mRootPointer->mActivityIndex;
    BusyDuration +=inActivities (activityIndex COMMA_HERE).mMaxDuration; 
  	SuccessorsMaxBusyDuration (BusyDuration, activityIndex, ResourceIndex, inActivities);
   	cVDLnodeInfo * p = mRootPointer->mPtrToNext ;
  	while (p != NULL){
  	  activityIndex = p->mActivityIndex;
  	  BusyDuration +=inActivities (activityIndex COMMA_HERE).mMaxDuration;
  		SuccessorsMaxBusyDuration (BusyDuration, activityIndex, ResourceIndex, inActivities);	
  		p = p->mPtrToNext ;
		}  
  }	
  return BusyDuration;   
}
//---------------------------------------------------------------------------*
//static 
void SuccessorsMinBusyDuration4Activity (PMSInt32 & ioBusyDuration, const PMSInt32 activityIndex, 
                                const PMSInt32 ResourceIndex,
                                const PMSInt32 priorityOfCurrentActivity,
                                const TC_UniqueArray <cActivity> & inActivities){
                              
  if (activityIndex >= 0){
	  PMSInt32 successorIndex = inActivities (activityIndex COMMA_HERE).mSuccessorId;
	  if (successorIndex >= 0){
	    if ( (ResourceIndex == inActivities (successorIndex COMMA_HERE).mResourceId)
	        &&
          ( (inActivities (successorIndex COMMA_HERE).mOccurrence % inActivities (successorIndex COMMA_HERE).mEvery) == 0 ) ){   
	   
	      PMSInt32 successorPriority = inActivities (successorIndex COMMA_HERE).mPriority;
	  		if ( (inActivities (successorIndex COMMA_HERE).mOffset == 0)
	  		    &&
	  		    (successorPriority <= priorityOfCurrentActivity) ){
	  		  ioBusyDuration += inActivities (successorIndex COMMA_HERE).mMinDuration ;
	  	    SuccessorsMinBusyDuration4Activity(ioBusyDuration, successorIndex, ResourceIndex, priorityOfCurrentActivity, inActivities);
	  	  }
	  	}	
	  	PMSInt32 OtherHeirId = inActivities (successorIndex COMMA_HERE).mOtherHeirId ;
		  while ( OtherHeirId >= 0 ) {
		    if ( (ResourceIndex == inActivities (OtherHeirId COMMA_HERE).mResourceId)
		     &&
         ( (inActivities (OtherHeirId COMMA_HERE).mOccurrence % inActivities (OtherHeirId COMMA_HERE).mEvery) == 0 ) ){   
	   
	        PMSInt32 HeirPriority = inActivities (OtherHeirId COMMA_HERE).mPriority;
		      if ( (inActivities (OtherHeirId COMMA_HERE).mOffset == 0)
		          &&
		          (HeirPriority <= priorityOfCurrentActivity)){
			      ioBusyDuration += inActivities (OtherHeirId COMMA_HERE).mMinDuration;
	          SuccessorsMinBusyDuration4Activity(ioBusyDuration, OtherHeirId, ResourceIndex, priorityOfCurrentActivity, inActivities);
	        }
	      }
			  OtherHeirId = inActivities (OtherHeirId COMMA_HERE).mOtherHeirId;
	  	}
	  }                                
  }                                  
}
//---------------------------------------------------------------------------*
PMSInt32 C_activitiesToSchedule::
getMinimumBusyPeriod4Activity (const PMSInt32 currentActivityIndex, 
                      const TC_UniqueArray <cActivity> & inActivities) {
 
  PMSInt32 BusyDuration=0;
  const PMSInt32 ResourceIndex = inActivities (currentActivityIndex COMMA_HERE).mResourceId;
  const PMSInt32 priorityOfCurrentActivity = inActivities (currentActivityIndex COMMA_HERE).mPriority;
  SuccessorsMinBusyDuration4Activity (BusyDuration, currentActivityIndex, ResourceIndex, priorityOfCurrentActivity, inActivities);
  if (mRootPointer != NULL){
    PMSInt32 activityIndex = mRootPointer->mActivityIndex;
    if (priorityOfCurrentActivity >= inActivities (activityIndex COMMA_HERE).mPriority){ 
    	BusyDuration +=inActivities (activityIndex COMMA_HERE).mMinDuration; 
  		SuccessorsMinBusyDuration4Activity (BusyDuration, activityIndex, ResourceIndex, priorityOfCurrentActivity, inActivities);
  	}
   	cVDLnodeInfo * p = mRootPointer->mPtrToNext ;
  	while (p != NULL){
  	  activityIndex = p->mActivityIndex;
      if (priorityOfCurrentActivity >= inActivities (activityIndex COMMA_HERE).mPriority){ 
	   	  BusyDuration +=inActivities (activityIndex COMMA_HERE).mMinDuration;
	  		SuccessorsMinBusyDuration4Activity (BusyDuration, activityIndex, ResourceIndex, priorityOfCurrentActivity, inActivities);	
	  	}
	  		p = p->mPtrToNext ;
		}  
  }	
  return BusyDuration;   
}
//--------------------------------------------------------------------------------
/*PMSInt32 C_activitiesToSchedule::
getLeastBusyPeriod (const PMSInt32 inCurrentActivity,
                    const TC_UniqueArray <cActivity> & inActivities) {
  PMSInt32 LeastActiviyPeriod = 0 ; // Means none
  const PMSInt32 priorityOfCurrentActivity = inActivities (inCurrentActivity COMMA_HERE).mPriority;
  if (mRootPointer != NULL){
  	if(priorityOfCurrentActivity >= mRootPointer->mActivityPriority){
  		PMSInt32 activityIndex = mRootPointer->mActivityIndex;
  		LeastActiviyPeriod = inActivities (activityIndex COMMA_HERE).mMinDuration;
  	}
  	cVDLnodeInfo * p = mRootPointer->mPtrToNext ;
  	while (p != NULL){
  		if (priorityOfCurrentActivity >= p->mActivityPriority){
  		 	PMSInt32 activityIndex = p->mActivityIndex;
  		 	LeastActiviyPeriod += inActivities (activityIndex COMMA_HERE).mMinDuration;
  		}
  		 p = p->mPtrToNext ;
  	}	
  }	
 return LeastActiviyPeriod;   
}*/

//---------------------------------------------------------------------------*
//static 
void SuccessorsMinBusyDuration (PMSInt32 & ioBusyDuration, const PMSInt32 activityIndex, 
                                const PMSInt32 ResourceIndex,
                                const TC_UniqueArray <cActivity> & inActivities){
                              
  if (activityIndex >= 0){
	  PMSInt32 successorIndex = inActivities (activityIndex COMMA_HERE).mSuccessorId;
	  if (successorIndex >= 0){
	    if ( (ResourceIndex == inActivities (successorIndex COMMA_HERE).mResourceId)
	        &&
         ( (inActivities (successorIndex COMMA_HERE).mOccurrence % inActivities (successorIndex COMMA_HERE).mEvery) == 0 ) ){   
	   
	  		ioBusyDuration += inActivities (successorIndex COMMA_HERE).mOffset +
	  		                  inActivities (successorIndex COMMA_HERE).mMinDuration ;
	  	  SuccessorsMinBusyDuration(ioBusyDuration, successorIndex, ResourceIndex, inActivities);
	  	}	
	  	PMSInt32 OtherHeirId = inActivities (successorIndex COMMA_HERE).mOtherHeirId ;
		  while ( OtherHeirId >= 0 ) {
		    if ( (ResourceIndex == inActivities (OtherHeirId COMMA_HERE).mResourceId)
		        &&
            ( (inActivities (OtherHeirId COMMA_HERE).mOccurrence % inActivities (OtherHeirId COMMA_HERE).mEvery) == 0 ) ){   
	   
			    ioBusyDuration += inActivities (OtherHeirId COMMA_HERE).mOffset + 
			                      inActivities (OtherHeirId COMMA_HERE).mMinDuration;
	        SuccessorsMinBusyDuration(ioBusyDuration, OtherHeirId, ResourceIndex, inActivities);
	      }
			  OtherHeirId = inActivities (OtherHeirId COMMA_HERE).mOtherHeirId;
	  	}
	  }                                
  }                                  
}
//---------------------------------------------------------------------------*
PMSInt32 C_activitiesToSchedule::
getMinimumBusyPeriod (const PMSInt32 currentActivityIndex, 
                      const TC_UniqueArray <cActivity> & inActivities) {
 
  PMSInt32 BusyDuration=0;
  const PMSInt32 ResourceIndex = inActivities (currentActivityIndex COMMA_HERE).mResourceId;
  SuccessorsMinBusyDuration (BusyDuration, currentActivityIndex, ResourceIndex, inActivities);
  if (mRootPointer != NULL){
    PMSInt32 activityIndex = mRootPointer->mActivityIndex;
    BusyDuration +=inActivities (activityIndex COMMA_HERE).mMinDuration; 
  	SuccessorsMinBusyDuration (BusyDuration, activityIndex, ResourceIndex, inActivities);
   	cVDLnodeInfo * p = mRootPointer->mPtrToNext ;
  	while (p != NULL){
  	  activityIndex = p->mActivityIndex;
  	  BusyDuration +=inActivities (activityIndex COMMA_HERE).mMinDuration;
  		SuccessorsMinBusyDuration (BusyDuration, activityIndex, ResourceIndex, inActivities);	
  		p = p->mPtrToNext ;
		}  
  }	
  return BusyDuration;   
}

//--------------------------------------------------------------------------*/

PMSInt32 C_activitiesToSchedule::
getFirstToSchedule (const PMSInt32 inCurrentInstant) const {
  PMSInt32 activityIndex = -1 ; // Means none
  if ((mRootPointer != NULL) && (mRootPointer->mScheduleInstant <= inCurrentInstant)) {
  //--- Find min priority activity
    PMSInt32 priority = mRootPointer->mActivityPriority ;
    activityIndex = mRootPointer->mActivityIndex ;
    cVDLnodeInfo * p = mRootPointer->mPtrToNext ;
    while ((p != NULL) && (p->mScheduleInstant <= inCurrentInstant)) {
      if (priority > p->mActivityPriority) {
        priority = p->mActivityPriority ;
        activityIndex = p->mActivityIndex ;
      }
      p = p->mPtrToNext ;
    }
  }
  return activityIndex ;
}
//----------------------------------------------------------------------------*/
PMSInt32 C_activitiesToSchedule::
getFirstScheduledInstant (const PMSInt32 inCurrentInstant) const {
  PMSInt32 scheduledInstant=-1 ; // 
  if ((mRootPointer != NULL) && (mRootPointer->mScheduleInstant <= inCurrentInstant)) {
  //--- Find min priority activity
    scheduledInstant=mRootPointer->mScheduleInstant;
    PMSInt32 priority = mRootPointer->mActivityPriority ;
    cVDLnodeInfo * p = mRootPointer->mPtrToNext ;
    while ((p != NULL) && (p->mScheduleInstant <= inCurrentInstant)) {
      if (priority > p->mActivityPriority) {
        scheduledInstant=p->mScheduleInstant;
        priority = p->mActivityPriority ;
      }
      p = p->mPtrToNext ;
    }
  }
  return scheduledInstant ;
}
//--------------------------------------------------------------------------*/

bool C_activitiesToSchedule::
 AnyReadyToScheduleAt (const PMSInt32 inCurrentInstant) const {
  return (mRootPointer != NULL) && (mRootPointer->mScheduleInstant <= inCurrentInstant) ;
}
//---------------------------------------------------------------------------*

PMSInt32 C_activitiesToSchedule::getNextScheduleTime (void) const {
  return (mRootPointer != NULL) ? mRootPointer->mScheduleInstant : PMSINT32_MAX ;
}
//---------------------------------------------------------------------------*/
bool C_activitiesToSchedule::
AnyNotReadyToScheduleAt (const PMSInt32 inCurrentInstant) const {
  bool NotReadyAt = false; // Means none
  if (mRootPointer != NULL) {
  //--- Find min priority activity
    if (mRootPointer->mScheduleInstant > inCurrentInstant){
   		NotReadyAt = true;
    }else{
	    cVDLnodeInfo * p = mRootPointer->mPtrToNext ;
	    while ( (p != NULL) && !NotReadyAt) {
	      if (p->mScheduleInstant > inCurrentInstant) {
	       	NotReadyAt = true;
	      }
	      p = p->mPtrToNext ;
	    }
	  }
  }
  return NotReadyAt ;
}
//---------------------------------------------------------------------------*
//                                                                           *
//       Print list                                                          *
//                                                                           *
//---------------------------------------------------------------------------*

 void C_activitiesToSchedule::
 printList (AC_OutputStream & inStream,
            const TC_UniqueArray <C_String> & inNames) const {
   cVDLnodeInfo * p = mRootPointer ;
   while (p != NULL) {
     const PMSInt32 index = p->mActivityIndex ;
     if (index < inNames.count ()) {
      inStream << inNames (index COMMA_HERE) << " " ;
     }
     inStream << "#" << cStringWithSigned (index) << " at "
              << cStringWithSigned (p->mScheduleInstant) << ", priority "
              << cStringWithSigned (p->mActivityPriority) << "\n" ;
     p = p->mPtrToNext ;
   }
 }

//---------------------------------------------------------------------------*
//                                                                           *
//       Handle copy                                                         *
//                                                                           *
//---------------------------------------------------------------------------*

C_activitiesToSchedule::C_activitiesToSchedule (const C_activitiesToSchedule & inOperand) :
mPtrToNextExisting (this),
mPtrToPreviousExisting (this),
mRootPointer (inOperand.mRootPointer) {
  initLinks () ;
}

//---------------------------------------------------------------------------*

C_activitiesToSchedule & C_activitiesToSchedule::operator = (const C_activitiesToSchedule & inOperand) {
  mRootPointer = inOperand.mRootPointer ;
  return *this ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Constructor for 'C_activitiesToSchedule::cVDLnodeInfo'              *
//                                                                           *
//---------------------------------------------------------------------------*

PMSInt32 C_activitiesToSchedule::smNodeCompare = 0 ;

PMSInt C_activitiesToSchedule::cVDLnodeInfo::
compare (const cVDLnodeInfo & inInfo) const {
  smNodeCompare ++ ;
  PMSInt result = mActivityIndex - inInfo.mActivityIndex ;
  if (result == 0) {
    result = ((PMSInt) mPtrToNext) - ((PMSInt) inInfo.mPtrToNext) ;
    if (result == 0) {
      result = mScheduleInstant - inInfo.mScheduleInstant ;
      if (result == 0) {
        result = mActivityPriority - inInfo.mActivityPriority ;
      }
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Get node size                                                       *
//                                                                           *
//---------------------------------------------------------------------------*

PMUInt32 C_activitiesToSchedule::getNodeSize (void) {
  return C_VDL_hashmap::getNodeSize () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Internal static method for adding a value to an index               *
//                                                                           *
//---------------------------------------------------------------------------*

C_activitiesToSchedule::cVDLnodeInfo * C_activitiesToSchedule::
find_or_add (const PMSInt32 inIndex,
             const PMSInt32 inActivityPriority,
             const PMSInt32 inScheduleInstant,
             C_activitiesToSchedule::cVDLnodeInfo * const inPointerToNext) {
//--- Do search or insert
  cVDLnodeInfo info ;
  info.mActivityIndex = inIndex ;
  info.mActivityPriority = inActivityPriority ;
  info.mScheduleInstant = inScheduleInstant ;
  info.mPtrToNext = inPointerToNext ;
  bool insertionPerformed = false ; // Not used
  cVDLnodeInfo * p = gMap.search_or_insert (info, insertionPerformed) ;
  if (insertionPerformed) {
    smNodeCount ++ ;
    p->mID = smNodeCount ;
  }
  return p ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Collect unused elements                                             *
//                                                                           *
//---------------------------------------------------------------------------*

void C_activitiesToSchedule::collectUnusedNodes (void) {
//--- Second : mark all used elements
  C_activitiesToSchedule * p = gVDLlistRoot.mPtrToNextExisting ;
  while (p != & gVDLlistRoot) {
    cVDLnodeInfo * infoPtr = p->mRootPointer ;
    while ((infoPtr != NULL) && ! infoPtr->isMarked ()) {
      infoPtr->mark () ;
      infoPtr = infoPtr->mPtrToNext ;
    }
    p = p->mPtrToNextExisting ;
  }
//--- Third : sweep unused objets
  gMap.sweepUnmarkedObjects () ;
}

//---------------------------------------------------------------------------*
