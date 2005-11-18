//---------------------------------------------------------------------------*//                                                                           *//     C++ class for implementing UNIQUE STACK                               *//                                                                           *//  Copyright (C) 2003 Pierre Molinaro.                                      *//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*//  ECN, Ecole Centrale de Nantes                                            *//                                                                           *//  This program is free software; you can redistribute it and/or modify it  *//  under the terms of the GNU General Public License as published by the    *//  Free Software Foundation.                                                *//                                                                           *//  This program is distributed in the hope it will be useful, but WITHOUT   *//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or    *//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for *//   more details.                                                           *//                                                                           *//---------------------------------------------------------------------------*#include "C_us.h"//---------------------------------------------------------------------------*#include <stddef.h>#include <string.h>#include <limits.h>//---------------------------------------------------------------------------*uint64 C_us::smTrivialAdd ;//---------------------------------------------------------------------------*//                                                                           *//                    Cache for addition                                     *//                                                                           *//---------------------------------------------------------------------------*//--- Cache is handled by an prime integer sized array #include "cache/TC_prime_cache2.h"typedef TC_prime_cache2 <C_us::cVDLnodeInfo *> cCacheClass ;static cCacheClass gCache ;//---------------------------------------------------------------------------*//                                                                           *//                       Global unique array                                 *//   (three possibilities, choose with COLLISION_RESOLUTION symbol)          *//                They differ on collisions handling                         *//                                                                           *//---------------------------------------------------------------------------*#define COLLISION_RESOLUTION 3//--- First possibility : a linear ordered list#if COLLISION_RESOLUTION == 1  #include "generic_maps/TC_LinearListForCollision.h"  typedef TC_LinearListForCollision <C_us::cVDLnodeInfo> cVDLmapType ;#endif//--- Second possibility : an AVL tree#if COLLISION_RESOLUTION == 2  #include "generic_maps/TC_AVL_TreeForCollision.h"  typedef TC_AVL_TreeForCollision <C_us::cVDLnodeInfo> cVDLmapType ;#endif//--- Third possibility : an AVL tree, elements are block-allocated for efficiency#if COLLISION_RESOLUTION == 3  #include "generic_maps/TC_Block_AVL_TreeForCollision.h"  const sint32 kBlockSize = 131072 ;  typedef TC_Block_AVL_TreeForCollision <C_us::cVDLnodeInfo, kBlockSize> cVDLmapType ;#endif//--- Class protected static variable for allocation infocVDLmapType::cAllocInfo cVDLmapType::smAllocInfo ;//---------------------------------------------------------------------------*//                                                                           *//  VDD objects hash map                                                     *//                                                                           *//---------------------------------------------------------------------------*#include "generic_maps/TC_HashMap.h"static TC_HashMap <cVDLmapType, C_us::cVDLnodeInfo> gMap ;//---------------------------------------------------------------------------*void C_us::reallocUniqueTable (const sint32 inTableUniqueNewSize) {  gMap.reallocMap (inTableUniqueNewSize) ;}//---------------------------------------------------------------------------*//                                                                           *//  Static VDL variable used as root of all existing C_us instances        *//                                                                           *//---------------------------------------------------------------------------*static C_us gVDLlistRoot ;//---------------------------------------------------------------------------*//                                                                           *//       Node count : for giving an unique ID to every node                  *//                                                                           *//---------------------------------------------------------------------------*sint32 C_us::smNodeCount = 0 ;//---------------------------------------------------------------------------*//                                                                           *//     Realloc addition cache                                                *//                                                                           *//---------------------------------------------------------------------------*void C_us::reallocAdditionCache (const sint32 inNewCacheSize) {  gCache.reallocCache (inNewCacheSize) ;}//---------------------------------------------------------------------------*//                                                                           *//       Default constructor                                                 *//                                                                           *//---------------------------------------------------------------------------*C_us::C_us (void) {  mRootPointer = (cVDLnodeInfo *) NULL ;//--- Link  initLinks () ;}//---------------------------------------------------------------------------*void C_us::initLinks (void) {  mPtrToNextExisting = this ;  mPtrToPreviousExisting = this ;  C_us * nextFromRoot = gVDLlistRoot.mPtrToNextExisting ;  mPtrToPreviousExisting = & gVDLlistRoot ;  nextFromRoot->mPtrToPreviousExisting = this ;  mPtrToNextExisting = nextFromRoot ;  gVDLlistRoot.mPtrToNextExisting = this ;}//---------------------------------------------------------------------------*//                                                                           *//       Destructor                                                          *//                                                                           *//---------------------------------------------------------------------------*C_us::~C_us (void) {  mRootPointer = (cVDLnodeInfo *) NULL ;//--- Unlink  C_us * next = mPtrToNextExisting ;  C_us * previous = mPtrToPreviousExisting ;  previous->mPtrToNextExisting = next ;  next->mPtrToPreviousExisting = previous ;}//---------------------------------------------------------------------------*//                                                                           *//       Set to NULL vector                                                  *//                                                                           *//---------------------------------------------------------------------------*void C_us::setToNullVector (void) {  mRootPointer = (cVDLnodeInfo *) NULL ;}//---------------------------------------------------------------------------*//                                                                           *//       Null vector ?                                                       *//                                                                           *//---------------------------------------------------------------------------*bool C_us::isNullVector (void) const {  return mRootPointer == NULL ;}//---------------------------------------------------------------------------*//                                                                           *//       Vector comparison                                                   *//                                                                           *//---------------------------------------------------------------------------*bool C_us::operator == (const C_us & inOperand) const {  return mRootPointer == inOperand.mRootPointer ;}//---------------------------------------------------------------------------*//                                                                           *//       Push a new value on stack                                           *//                                                                           *//---------------------------------------------------------------------------*void C_us::pushValue (const sint32 inIndex) {  mRootPointer = find_or_add (inIndex, mRootPointer) ;}//---------------------------------------------------------------------------*//                                                                           *//       Reset entry to zero                                                 *//                                                                           *//---------------------------------------------------------------------------*void C_us::suppressEntryAtLevel (const sint32 inLevel) {  mRootPointer = internalSuppressEntry (inLevel, mRootPointer) ;}//---------------------------------------------------------------------------*C_us::cVDLnodeInfo * C_us::internalSuppressEntry (const sint32 inLevel,                       cVDLnodeInfo * const inPointer) {  cVDLnodeInfo * result = (cVDLnodeInfo *) NULL ;  if (inPointer != NULL) {    if (inLevel <= 0) {      result = inPointer->mPtrToNext ;    }else{      result = find_or_add (inPointer->mIndex,                            internalSuppressEntry (inLevel-1, inPointer->mPtrToNext)) ;    }  }  return result ;}//---------------------------------------------------------------------------*//                                                                           *//       Handle copy                                                         *//                                                                           *//---------------------------------------------------------------------------*C_us::C_us (const C_us & inOperand) {  mRootPointer = inOperand.mRootPointer ;  initLinks () ;}//---------------------------------------------------------------------------*void C_us::operator = (const C_us & inOperand) {  mRootPointer = inOperand.mRootPointer ;}//---------------------------------------------------------------------------*//                                                                           *//       Cache for addition                                                  *//                                                                           *//---------------------------------------------------------------------------*uint64 C_us::getCacheEntriesCount (void) {  return gCache.getCacheEntriesCount () ;}//---------------------------------------------------------------------------*uint64 C_us::getCacheSuccessCount (void) {  return gCache.getCacheEntriesCount () ;}//---------------------------------------------------------------------------*uint64 C_us::getCacheFailureCount (void) {  return gCache.getCacheMissCount () ;}//---------------------------------------------------------------------------*uint64 C_us::getCacheOverrideCount (void) {  return gCache.getCacheOverrideCount () ;}//---------------------------------------------------------------------------*uint64 C_us::getUnusedCacheEntriesCount (void) {  return gCache.getUnusedCacheEntriesCount () ;}//---------------------------------------------------------------------------*//                                                                           *//       Explore a VDL                                                       *//                                                                           *//---------------------------------------------------------------------------* void C_us::explore_vdl (C_us & ioVDL, sint32 & outIndex) {  if (ioVDL.mRootPointer == NULL) {    outIndex  = -1 ;  }else{    outIndex = ioVDL.mRootPointer->mIndex ;    ioVDL.mRootPointer = ioVDL.mRootPointer->mPtrToNext ;  }}//---------------------------------------------------------------------------*//                                                                           *//       Constructor for 'C_us::cVDLnodeInfo'                                *//                                                                           *//---------------------------------------------------------------------------*sint32 C_us::smNodeCompare = 0 ;sint32 C_us::cVDLnodeInfo::compare (const cVDLnodeInfo & inInfo) const {  smNodeCompare ++ ;  sint32 result = ((sint32) mPtrToNext) - ((sint32) inInfo.mPtrToNext) ;  if (result == 0) {    result = mIndex - inInfo.mIndex ;  }  return result ;}//---------------------------------------------------------------------------*//                                                                           *//       Get node size                                                       *//                                                                           *//---------------------------------------------------------------------------*uint32 C_us::getNodeSize (void) {  return cVDLmapType::getNodeSize () ;}//---------------------------------------------------------------------------*//                                                                           *//       Internal static method for adding a value to an index               *//                                                                           *//---------------------------------------------------------------------------*C_us::cVDLnodeInfo * C_us::find_or_add (const sint32 inIndex,             C_us::cVDLnodeInfo * const inPointerToNext) {//--- Do search or insert  cVDLnodeInfo info ;  info.mIndex = inIndex ;  info.mPtrToNext = inPointerToNext ;  bool insertionPerformed = false ; // Not used  cVDLnodeInfo * p = gMap.search_or_insert (info, insertionPerformed) ;  if (insertionPerformed) {    smNodeCount ++ ;    p->mID = smNodeCount ;  }  return p ;}//---------------------------------------------------------------------------*//                                                                           *//       Print a vector                                                      *//                                                                           *//---------------------------------------------------------------------------* void C_us:: printVector (FILE * inFile,              const char * inPrefix,              const sint32 inFirst,              const sint32 inStep) const {   if (inFile != NULL) {     bool firstPrint = true ;     cVDLnodeInfo * p = mRootPointer ;      while (p != NULL) {       if (((p->mIndex - inFirst) % inStep) == 0) {         if (firstPrint) {           firstPrint = false ;         }else{           ::fprintf (inFile, " ") ;         }         ::fprintf (inFile, "%s%ld",                    inPrefix,                    (sint32) ((p->mIndex - inFirst) / inStep)) ;       }       p = p->mPtrToNext ;     }   } }//---------------------------------------------------------------------------* void C_us::printVector (AC_OutputStream & inStream,                           const char * inPrefix,                           const sint32 inFirst,                           const sint32 inStep) const {   bool firstPrint = true ;   cVDLnodeInfo * p = mRootPointer ;    while (p != NULL) {     if (((p->mIndex - inFirst) % inStep) == 0) {       if (firstPrint) {         firstPrint = false ;       }else{         inStream << " " ;       }       inStream << inPrefix << ((p->mIndex - inFirst) / inStep) ;     }     p = p->mPtrToNext ;   } }//---------------------------------------------------------------------------* void C_us::printVector (FILE * inFile,                           const TC_UniqueArray <C_String> & inNames,                           const sint32 inFirst,                           const sint32 inStep) const {   if (inFile != NULL) {     bool firstPrint = true ;     cVDLnodeInfo * p = mRootPointer ;      while (p != NULL) {       if (((p->mIndex - inFirst) % inStep) == 0) {         if (firstPrint) {           firstPrint = false ;         }else{           ::fprintf (inFile, " ") ;         }         ::fprintf (inFile, "%s",                    inNames ((p->mIndex - inFirst) / inStep COMMA_HERE).cString ()) ;       }       p = p->mPtrToNext ;     }   } }//---------------------------------------------------------------------------* void C_us::printVector (AC_OutputStream & inStream,                         const TC_UniqueArray <C_String> & inNames,                         const sint32 inFirst,                         const sint32 inStep) const {   bool firstPrint = true ;   cVDLnodeInfo * p = mRootPointer ;    while (p != NULL) {     if (((p->mIndex - inFirst) % inStep) == 0) {       if (firstPrint) {         firstPrint = false ;       }else{         inStream << " " ;       }       inStream << (inNames ((p->mIndex - inFirst) / inStep COMMA_HERE)) ;     }     p = p->mPtrToNext ;   } }//---------------------------------------------------------------------------*//                                                                           *//       Collect unused elements                                             *//                                                                           *//---------------------------------------------------------------------------*void C_us::collectUnusedNodes (void) {//--- First : clear all addition cache entries  gCache.clearAllCacheEntries () ;//--- Second : mark all used elements  C_us * p = gVDLlistRoot.mPtrToNextExisting ;  while (p != & gVDLlistRoot) {    cVDLnodeInfo * infoPtr = p->mRootPointer ;    while ((infoPtr != NULL) && ! infoPtr->isMarked ()) {      infoPtr->mark () ;      infoPtr = infoPtr->mPtrToNext ;    }    p = p->mPtrToNextExisting ;  }//--- Third : sweep unused objets  gMap.sweepUnmarkedObjects () ;}//---------------------------------------------------------------------------*//                                                                           *//       Print VDL summary                                                   *//                                                                           *//---------------------------------------------------------------------------*void C_us::printVDLsummary (AC_OutputStream & inOutputStream) {  const uint64 n = getTrivialAddCount () + getCacheSuccessCount () + getCacheFailureCount () ;  inOutputStream << "Summary of VDL operations :\n"                    "  " << getVDLnodeCount ()                 << " VDL used nodes (size " << getNodeSize () << " bytes) ;\n"                    "  " << cVDLmapType::getCreatedObjectsCount ()                 << " VDL created nodes (total size "                 << ((cVDLmapType::getCreatedObjectsCount () * getNodeSize ()) / 1024ULL)                 << " kbytes) ;\n"                    "  " << getNodeComparesCount () << " comparisons ;\n"                    "  " << getTrivialAddCount ()                 << " trivial additions (" << ((100ULL * getTrivialAddCount ()) / n)                 << "%) ;\n"                    "  " << getCacheSuccessCount ()                 << " cache successes (" << ((100ULL * getCacheSuccessCount ()) / n) << "%) ;\n"                    "  " << getCacheFailureCount () << " cache failures ("                 << ((100ULL * getCacheFailureCount ()) / n) << "%), including "                 << getCacheOverrideCount () << " cache overrides ("                 << ((100ULL * getCacheOverrideCount ()) / n) << "%) ;\n"                    "  " << getUnusedCacheEntriesCount () << " unused cache entries ("                 << ((100ULL * getUnusedCacheEntriesCount ()) / getCacheEntriesCount ())                 << "%, total entries = " << getCacheEntriesCount () << ").\n" ;}//---------------------------------------------------------------------------*