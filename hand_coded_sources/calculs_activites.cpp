/*--------------------------------------------------------------------------*/

#include<stdlib.h> 
#include "files/C_HTML_FileWrite.h"
#include "utilities/MF_MemoryControl.h"

#include "oa_semantics.h"
#include "CANMessageBounds.h"
#include "ExtendedList.h"
#include "VerifyConditions.h"
#include "activities_core.h"
#include "oa_cli_options.h"

//--------------------------------------------------------------------------*
//                                                                          *
//     cPtr_C_canIndependantMessage                                         *
//                                                                          *
//--------------------------------------------------------------------------*

bool cPtr_C_canIndependantMessage::messageDependsOnMessage (void) const {
  return false ;
}

//--------------------------------------------------------------------------*

bool cPtr_C_canIndependantMessage::messageDependsOnTask (void) const {
  return false ;
}

//--------------------------------------------------------------------------*

PMUInt32 cPtr_C_canIndependantMessage::getMessageDependanceValue (void) const {
  return 0 ;
}

//--------------------------------------------------------------------------*
//                                                                          *
//     cPtr_C_canMessageFromMessage                                         *
//                                                                          *
//--------------------------------------------------------------------------*

bool cPtr_C_canMessageFromMessage::messageDependsOnMessage (void) const {
  return true ;
}

//--------------------------------------------------------------------------*

bool cPtr_C_canMessageFromMessage::messageDependsOnTask (void) const {
  return false ;
}

//--------------------------------------------------------------------------*

PMUInt32 cPtr_C_canMessageFromMessage::getMessageDependanceValue (void) const {
  return mMessageIndex.uintValue () ;
}

//--------------------------------------------------------------------------*
//                                                                          *
//     cPtr_C_canMessageFromTask                                            *
//                                                                          *
//--------------------------------------------------------------------------*

bool cPtr_C_canMessageFromTask::messageDependsOnMessage (void) const {
  return false ;
}

//--------------------------------------------------------------------------*

bool cPtr_C_canMessageFromTask::messageDependsOnTask (void) const {
  return true ;
}

//--------------------------------------------------------------------------*

PMUInt32 cPtr_C_canMessageFromTask::getMessageDependanceValue (void) const {
  return mTaskIndex.uintValue () ;
}

//--------------------------------------------------------------------------*
//                                                                          *
//     cPtr_C_independantTask                                               *
//                                                                          *
//--------------------------------------------------------------------------*

bool cPtr_C_independantTask::taskDependsOnTask (void) const {
  return false ;
}

//--------------------------------------------------------------------------*

bool cPtr_C_independantTask::taskDependsOnMessage (void) const {
  return false ;
}

//--------------------------------------------------------------------------*

PMUInt32 cPtr_C_independantTask::getTaskDependanceValue (void) const {
  return 0 ;
}

//--------------------------------------------------------------------------*

PMUInt32 cPtr_C_independantTask::getTaskEveryParameter (void) const {
  return 1 ;
}

//--------------------------------------------------------------------------*
//                                                                          *
//     cPtr_C_taskDependsFromTask                                           *
//                                                                          *
//--------------------------------------------------------------------------*

bool cPtr_C_taskDependsFromTask::taskDependsOnTask (void) const {
  return true ;
}

//--------------------------------------------------------------------------*

bool cPtr_C_taskDependsFromTask::taskDependsOnMessage (void) const {
  return false ;
}

//--------------------------------------------------------------------------*

PMUInt32 cPtr_C_taskDependsFromTask::getTaskDependanceValue (void) const {
  return mTask.uintValue () ;
}

//--------------------------------------------------------------------------*

PMUInt32 cPtr_C_taskDependsFromTask::getTaskEveryParameter (void) const {
  return mEvery.uintValue () ;
}

//--------------------------------------------------------------------------*
//                                                                          *
//     cPtr_C_taskDependsFromMessage                                        *
//                                                                          *
//--------------------------------------------------------------------------*

bool cPtr_C_taskDependsFromMessage::taskDependsOnTask (void) const {
  return false ;
}

//--------------------------------------------------------------------------*

bool cPtr_C_taskDependsFromMessage::taskDependsOnMessage (void) const {
  return true ;
}

//--------------------------------------------------------------------------*

PMUInt32 cPtr_C_taskDependsFromMessage::getTaskDependanceValue (void) const {
  return mMessage.uintValue () ;
}

//--------------------------------------------------------------------------*

PMUInt32 cPtr_C_taskDependsFromMessage::getTaskEveryParameter (void) const {
  return mEvery.uintValue () ;
}

//--------------------------------------------------------------------------*
//                                                                          *
//     Build style file                                                     *
//                                                                          *
//--------------------------------------------------------------------------*


static void buildCSSfile (C_CompilerEx & inLexique,
                          const C_String & inDirectory) {
//--- Style file name
  const C_String styleFileName = inDirectory + "/style.css" ;
//--- Build file
  bool ok = false ;
  C_TextFileWrite f (styleFileName COMMA_SAFARI_CREATOR, ok) ;
  if (! ok) {
    C_String message ;
    message << "Cannot open '" << styleFileName << "' file in write mode." ;
    inLexique.onTheFlySemanticError (message COMMA_HERE) ;
  }
  f << "body {\n"
       "  font-family: Helvetica, sans-serif ;\n"
       "	font-size: small ;\n"
       "}\n"
       "\n"
       "h1 {\n"
       "  text-align: center ;\n"
       "}\n"
       "\n"
       "a.header_link {\n"
       "	 border: 1px solid #999999 ;\n"
       "	 padding: 4px ;\n"
       "  background-color: #FFFFCC ;\n"
       "  font-weight: bold ;\n"
       "}\n"
       "\n"
       "a:visited, a:link, a:active{\n"
       " color: blue ;\n"
       " text-decoration: underline ;\n"
       "}\n"
       "\n"
       "a:hover {\n"
       "  color:green ;\n"
       "  background-color: #FF9966 ;\n"
       "  text-decoration: none ;\n"
       "}\n"
       "\n"
       "table.title {\n"
       "  width: 100% ;\n"
       "	border: 1px solid #999999 ;\n"
       "  background-color: yellow ;\n"
       "  font-weight: bold ;\n"
       "	text-align: center ;\n"
       "}\n"
       "\n"
       "table.result {\n"
       "	border: 1px solid #999999 ;\n"
       "}\n"
       "\n"
       "tr.result_line {\n"
       "  background-color: #EEEEEE ;\n"
       "}\n"
       "\n"
       "tr.result_title {\n"
       "  background-color: #CCFFFF ;\n"
       "  font-weight: bold ;\n"
       "}\n"
       "\n"
       "span.error {\n"
       "  font-weight: bold ;\n"
       "  color: red ;\n"
       "}\n"
       "\n"
       "span.warning {\n"
       "  font-weight: bold ;\n"
       "  color: #FF9966 ;\n"
       "}\n"
       "\n"
       "span.success {\n"
       "  font-weight: bold ;\n"
       "  color: green ;\n"
       "}\n"
       "\n"
       "span.list {\n"
       "  display: block ;\n"
       "  line-height: 100% ;\n"
       "}\n"
       "\n"
       "\n" ;
}

//--------------------------------------------------------------------------*
//                                                                          *
//     Perform scheduling computations                                      *
//                                                                          *
//--------------------------------------------------------------------------*

void
routine_performComputations (C_CompilerEx & inLexique,
                             GGS_M_processor & inProcessorMap,
                             GGS_M_network & inNetworkMap,
                             GGS_M_messages & inMessagesMap,
                             GGS_M_tasks & inTasksMap
                             COMMA_UNUSED_LOCATION_ARGS) {  
  TC_UniqueArray <cResource> Resource ;
  TC_UniqueArray <cElement> Element ;

  const bool CreateIntermediateFiles = gOption_oa_5F_cli_5F_options_createIntermediateFiles.mValue ;
  const bool useCANmaxLengthOnly = gOption_oa_5F_cli_5F_options_useCANmaxLegth.mValue ;
  bool forceBalgorithm = true ;
  const C_String sourceFile = inLexique.sourceFileName () ;
  

  const C_String htmlFileName = sourceFile.stringByDeletingLastPathComponent () + "/" + sourceFile.lastPathComponentWithoutExtension () + ".html" ;
  const C_String activitiesHTMLFileName = sourceFile.stringByDeletingLastPathComponent () + "/" + sourceFile.lastPathComponentWithoutExtension () + "_activities.html" ;
  const C_String raw_outputHTMLFileName = sourceFile.stringByDeletingLastPathComponent () + "/" + sourceFile.lastPathComponentWithoutExtension () + "_raw_output.html" ;

  buildCSSfile (inLexique, sourceFile.stringByDeletingLastPathComponent ()) ;
  bool ok = false ;
  C_HTML_FileWrite htmlFile (htmlFileName,
                             sourceFile.lastPathComponent () + " results",
                             "style.css",
                             ""
                             COMMA_SAFARI_CREATOR,
                             ok) ;
  if (! ok) {
    C_String message ;
    message << "Cannot open '" << htmlFileName << "' file in write mode." ;
    inLexique.onTheFlySemanticError (message COMMA_HERE) ;
  }
  if(useCANmaxLengthOnly){
  	printf("Elements have their upper duration bounds.\n"); 
  }
  char MessageType = '\0' ;
  bool DependentHasOffset = false ;
	PMSInt32  index ;
	GGS_M_processor::cElement * processor = inProcessorMap.firstObject () ;
//--- Print processors map
  htmlFile.appendCppTitleComment ("Processors map", "title") ;
  htmlFile.outputRawData ("<br><table class=\"result\"><tr class=\"result_title\"><td>");
	htmlFile.outputRawData ("#<th>Name<th>ScaFactor</tr>") ;
	index = 1 ;
	while (processor != NULL) {
	  macroValidPointer (processor) ;
	  htmlFile.outputRawData ("<tr class=\"result_line\"><td>") ;
	  htmlFile << cStringWithSigned (index) ;
	  htmlFile.outputRawData ("</td><td>") ;
	  htmlFile << processor->mKey ;
	  htmlFile.outputRawData ("</td><td>") ;
	  htmlFile << cStringWithUnsigned (processor->mInfo.mStep.uintValue ()) ;
	  htmlFile.outputRawData ("</td></tr>") ;
	  processor = processor->nextObject () ;
	  index ++ ;
	}
	htmlFile.outputRawData ("</table>") ;
	htmlFile.outputRawData ("<br>");
//--- Build processors map  
  index = 0 ;
  processor = inProcessorMap.firstObject () ;
  while (processor != NULL) {
    macroValidPointer (processor) ;
    cResource resource ;
    strcpy (resource.mResourceName, processor->mKey.cString (HERE));
  	resource.mResourceType= 2; // Processor = 2
   	resource.mStep = (PMSInt32) processor->mInfo.mStep.uintValue () ;
    
    Resource.addObject (resource) ;
    processor = processor->nextObject () ;
    index ++ ;
  }
  PMSInt32 NumberOfProcessors = index ;
	
  const char * kNetworkTypes [] = {"VAN","CAN"} ;
	GGS_M_network::cElement * network = inNetworkMap.firstObject () ;
//--- Print network map
  htmlFile.appendCppTitleComment ("Networks map", "title") ;
  htmlFile.outputRawData ("<br><table class=\"result\"><tr class=\"result_title\"><td>");
  htmlFile.outputRawData ("#<th>Name<th>Type<th>ScaFactor</tr>") ;
  index = 1 ;
  while (network != NULL) {
    macroValidPointer (network) ;
    htmlFile.outputRawData ("<tr class=\"result_line\"><td>") ;
    htmlFile << cStringWithSigned (index) ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << network->mKey ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << kNetworkTypes [network->mInfo.mCANnetwork.boolValue ()] ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << cStringWithUnsigned (network->mInfo.mScalingFactor.uintValue ()) ;
    htmlFile.outputRawData ("</td></tr>") ;
    network = network->nextObject () ;
    index ++ ;
  }
  htmlFile.outputRawData ("</table>") ;
  htmlFile.outputRawData ("<br>");
//--- Build networks map  
  PMSInt32 min_NetworkStep = PMSINT32_MAX ;
  index = 0 ;
  network = inNetworkMap.firstObject ();
  while (network != NULL) {
    macroValidPointer (network) ;
    cResource resource ;
    strcpy(resource.mResourceName,network->mKey.cString (HERE));
  	resource.mResourceType= network->mInfo.mCANnetwork.boolValue ();
    resource.mStep = (PMSInt32) network->mInfo.mScalingFactor.uintValue () ;		
 		min_NetworkStep = min (min_NetworkStep, resource.mStep);
 	 	
 	 	Resource.addObject (resource) ;
    network = network->nextObject () ;
    index ++ ;
  }
  
//--- Build tasks map  
  GGS_M_tasks::cElement * task = inTasksMap.firstObject () ;
  index = 0 ;
  task = inTasksMap.firstObject () ;
  while (task != NULL) {
    macroValidPointer (task) ;
    cElement element ;
    strcpy(element.mElementName,task->mKey.cString (HERE));   
    element.mElementType = 'T';    
    element.mId_inList =index;
  	element.mResourceId = (PMSInt32) task->mInfo.mProcessor.uintValue ();
    element.mPriority = (PMSInt32) task->mInfo.mPriority.uintValue ();
// �    element.mEvery = 1 ;
    PMSInt32 Sca = Resource (element.mResourceId COMMA_HERE).mStep ;
//    printf (" Sca : %ld \n",Sca);
    element.mEvery = (PMSInt32) task->mInfo.mTaskKind (HERE)->getTaskEveryParameter () ;
  	element.mOffset = Sca*(PMSInt32) task->mInfo.mOffset.uintValue ();  
    element.mMaxDuration = Sca*(PMSInt32) task->mInfo.mDurationMax.uintValue (); 
    element.mMinDuration = useCANmaxLengthOnly
                          ? element.mMaxDuration :(Sca*(PMSInt32)  task->mInfo.mDurationMin.uintValue ());
        
    element.mDeadline = (PMSInt32) task->mInfo.mDeadline.uintValue ();
    if ( element.mDeadline !=  PMSINT32_MAX){ // PMUINT32_MAX -> PMSINT32_MAX by PM, 17/1/2005
    	 element.mDeadline = Sca*element.mDeadline;
    }  
 //................................................   
    if (task->mInfo.mTaskKind (HERE)->taskDependsOnTask ()) {
    	PMSInt32 elementIndex = (PMSInt32) task->mInfo.mTaskKind (HERE)->getTaskDependanceValue ();
    	element.mEveryMultiple = 
    		 (PMSInt32) task->mInfo.mTaskKind (HERE)->getTaskEveryParameter () * Element (elementIndex COMMA_HERE).mEveryMultiple; 
   		element.mPeriod = Sca*(PMSInt32) task->mInfo.mPeriod.uintValue ();
    } else if (task->mInfo.mTaskKind (HERE)->taskDependsOnMessage ()){
    
    }else{
    	element.mEveryMultiple = (PMSInt32) task->mInfo.mTaskKind (HERE)->getTaskEveryParameter () ;
    	element.mPeriod = Sca*(PMSInt32) task->mInfo.mPeriod.uintValue ();
    }
 //................................................
  	if (task->mInfo.mTaskKind (HERE)->taskDependsOnTask ()) {
      element.mIsIndependant=false ;
    	element.mPredecessorType = 'T'; 
      element.mPredecessorId = 
      PMSInt32 (task->mInfo.mTaskKind (HERE)->getTaskDependanceValue ());
    }else if (task->mInfo.mTaskKind (HERE)->taskDependsOnMessage ()) {
      element.mIsIndependant=false ;
    	element.mPredecessorType = 'M'; 
      element.mPredecessorId = 
      PMSInt32 (task->mInfo.mTaskKind (HERE)->getTaskDependanceValue ()) ;
    }else{ 
    	element.mIsIndependant=true ;
    }
    if (!element.mIsIndependant && (element.mOffset != 0)){
      DependentHasOffset = DependentHasOffset || true ;
    }
    Element.addObject (element) ;
		task = task->nextObject () ;
    index ++ ;
  }
  PMSInt32 NumberOfTasks = index;
	
  const char * kMessageClasses [] = {"standard", "extended", "  VAN   "} ;
  GGS_M_messages::cElement * message = inMessagesMap.firstObject () ;

//--- Build messages map
  index = 0 ;
  message = inMessagesMap.firstObject () ;
  while (message != NULL) {
    macroValidPointer (message) ;
    cElement element ;
    strcpy(element.mElementName,message->mKey.cString (HERE));
  	element.mElementType = 'M';
    element.mId_inList = index;
  	element.mResourceId = NumberOfProcessors + 
  		(PMSInt32) message->mInfo.mNetworkIndex.uintValue ();
  	element.mPriority = (PMSInt32) message->mInfo.mPriority.uintValue ();
  	element.mEvery = 1 ;
  	PMSInt32 ScalingFactor = 
					 Resource (element.mResourceId COMMA_HERE).mStep;
	//  printf (" Sca : %ld \n",ScalingFactor);
	  element.mOffset = ScalingFactor*(PMSInt32) message->mInfo.mOffset.uintValue (); 
  	if ( Resource (element.mResourceId COMMA_HERE).mResourceType == 1 ){ //CAN = 1
    	if (strstr(kMessageClasses [message->mInfo.mClass.uintValue ()],"standard") != NULL){ 
    		MessageType = 'S';
    	}else if (strstr(kMessageClasses [message->mInfo.mClass.uintValue ()],
      					"extended") != NULL){ 
      	MessageType = 'X' ;
      }else{ 
      	co << "ERROR : message #"
      	   << cStringWithSigned (index)
      	   << " is neither standard (S) nor extended (X) message!\n" ;
      }
      
      element.mMaxDuration = ScalingFactor* maxCANMessageTime(MessageType,
      											 (PMUInt32) element.mMinDuration,
      											 message->mInfo.mBytesCount.uintValue ());
  
      element.mMinDuration = useCANmaxLengthOnly
        ? element.mMaxDuration
        : (ScalingFactor * minCANMessageTime(MessageType,
                            message->mInfo.mPriority.uintValue (),
                            message->mInfo.mBytesCount.uintValue ()));
                            
  	}else if (Resource (element.mResourceId COMMA_HERE).mResourceType == 0 ){ //VAN = 0
    	
    	element.mMinDuration= ScalingFactor *(64+10* (PMSInt32) message->mInfo.mBytesCount.uintValue ()) ;

    	element.mMaxDuration= ScalingFactor* element.mMinDuration;
  	}else{ 
       printf ("ERROR : bus is neither CAN nor VAN!\n") ;
      fflush (stdout);  
		}
		
    element.mDeadline =  (PMSInt32) message->mInfo.mDeadline.uintValue ();
    if ( element.mDeadline !=  PMSINT32_MAX){ // PMUINT32_MAX -> PMSINT32_MAX by PM, 17/1/2005
    	 element.mDeadline = ScalingFactor *element.mDeadline;
    }  
 //...........................................................................
    PMSInt32 elementIndex ;
   if (message->mInfo.mMessageKind (HERE)->messageDependsOnTask ()) {
   	 elementIndex = (PMSInt32) message->mInfo.mMessageKind (HERE)->getMessageDependanceValue ();
     element.mEveryMultiple = Element (elementIndex COMMA_HERE).mEveryMultiple ;  
     element.mPeriod = Element (elementIndex COMMA_HERE).mPeriod ; 
   }else if (message->mInfo.mMessageKind (HERE)->messageDependsOnMessage ()) {
     elementIndex = (PMSInt32) message->mInfo.mMessageKind (HERE)->getMessageDependanceValue () + NumberOfTasks ;
     element.mEveryMultiple = Element (elementIndex COMMA_HERE).mEveryMultiple; 
     element.mPeriod = Element (elementIndex COMMA_HERE).mPeriod ;
   } else{
   	 element.mEveryMultiple = 1;
   	  element.mPeriod = ScalingFactor * (PMSInt32) message->mInfo.mPeriod.uintValue ();
   }
 //.................................................................................   
  	if (message->mInfo.mMessageKind (HERE)->messageDependsOnTask ()) {
      element.mIsIndependant=false ;
    	element.mPredecessorType = 'T'; 
      element.mPredecessorId = 
         (PMSInt32) message->mInfo.mMessageKind (HERE)->getMessageDependanceValue ();
    }else if (message->mInfo.mMessageKind (HERE)->messageDependsOnMessage ()) {
    	element.mIsIndependant=false ;
    	element.mPredecessorType = 'M'; 
      element.mPredecessorId = \
      	(PMSInt32) message->mInfo.mMessageKind (HERE)->getMessageDependanceValue () ;
    }else{ 
    	element.mIsIndependant=true ;
    }
    if (!element.mIsIndependant && (element.mOffset != 0)){
      DependentHasOffset = DependentHasOffset || true ;
    }
    Element.addObject (element) ;
	  message = message->nextObject () ;
    index ++ ;
  }
  PMSInt32 NumberOfMessages = index;  
//*----------------------------------------------------------------------/  
	//--- Print task map
  
	htmlFile.appendCppTitleComment ("Tasks map", "title") ;
  htmlFile.outputRawData ("<br><table class=\"result\"><tr class=\"result_title\"><td>") ;
  htmlFile.outputRawData ("#<th>Name<th>Processor<th>Priority<th>");
  htmlFile.outputRawData ("Offset<th>Min<th>Max<th>Period<th>") ;
  htmlFile.outputRawData ("Deadline<th>Dependence<th>Every</tr>") ;
  index = 1 ;
  task = inTasksMap.firstObject () ;
  while (task != NULL) {
    macroValidPointer (task) ;
    htmlFile.outputRawData ("<tr class=\"result_line\"><td>") ;
    htmlFile << cStringWithSigned (index) ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << task->mKey.cString (HERE) ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << cStringWithUnsigned (task->mInfo.mProcessor.uintValue ()+1) ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << cStringWithUnsigned (task->mInfo.mPriority.uintValue ()) ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << cStringWithUnsigned (task->mInfo.mOffset.uintValue ());
    htmlFile.outputRawData ("</td><td>") ;
    if (useCANmaxLengthOnly){
      htmlFile << cStringWithUnsigned (task->mInfo.mDurationMax.uintValue ()) ;
    }else {
      htmlFile << cStringWithUnsigned (task->mInfo.mDurationMin.uintValue ()) ;
    }
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << cStringWithUnsigned (task->mInfo.mDurationMax.uintValue ()) ;
    htmlFile.outputRawData ("</td><td>") ;
//....................................................................   
    if (task->mInfo.mTaskKind (HERE)->taskDependsOnMessage ()) {
    	PMSInt32 elementIndex = (PMSInt32) task->mInfo.mTaskKind (HERE)->getTaskDependanceValue () + NumberOfTasks ;
    	Element (index-1 COMMA_HERE).mEveryMultiple = 
    		 (PMSInt32) task->mInfo.mTaskKind (HERE)->getTaskEveryParameter () * Element (elementIndex COMMA_HERE).mEveryMultiple; 
    	Element (index-1 COMMA_HERE).mPeriod = Element (elementIndex COMMA_HERE).mPeriod  ;
    }
 //...................................................................
    PMSInt32 resourceId = (PMSInt32) task->mInfo.mProcessor.uintValue ();
    PMSInt32 Scal = Resource (resourceId COMMA_HERE).mStep ;

    htmlFile << cStringWithSigned (Element (index-1 COMMA_HERE).mEveryMultiple * Element (index-1 COMMA_HERE).mPeriod /Scal) ;
    htmlFile.outputRawData ("</td><td>") ;
    if (task->mInfo.mDeadline.uintValue () == PMUINT32_MAX){
    	htmlFile.outputRawData ("Unknown</td><td>") ;
    }else{
     	htmlFile << cStringWithUnsigned (task->mInfo.mDeadline.uintValue ()) ;
    	htmlFile.outputRawData ("</td><td>") ;
    }
    if (task->mInfo.mTaskKind (HERE)->taskDependsOnTask ()) {
      htmlFile.outputRawData ("task #") ;
      htmlFile << cStringWithUnsigned (task->mInfo.mTaskKind (HERE)->getTaskDependanceValue ()+1) ;
    }else if (task->mInfo.mTaskKind (HERE)->taskDependsOnMessage ()) {
      htmlFile.outputRawData ("message #") ;
      htmlFile << cStringWithUnsigned (task->mInfo.mTaskKind (HERE)->getTaskDependanceValue ()+1) ;
    }else{
    	htmlFile.outputRawData (" ---") ;
    }
     htmlFile.outputRawData ("</td><td>") ;
     htmlFile << cStringWithUnsigned (task->mInfo.mTaskKind (HERE)->getTaskEveryParameter ()) ;
      
    htmlFile.outputRawData ("</td></tr>") ;
    task = task->nextObject () ;
    index ++ ;
  }
  htmlFile.outputRawData ("</table>") ;
  htmlFile.outputRawData ("<br>");

//--- Print messages map
  htmlFile.appendCppTitleComment ("Messages map", "title") ;
  htmlFile.outputRawData ("<br><table class=\"result\"><tr class=\"result_title\"><td>") ;
  htmlFile.outputRawData ("#<th>Name<th>Network<th>Type<th>Priority<th>Byte");
  htmlFile.outputRawData ("<th> min--max ") ;
  htmlFile.outputRawData ("<th>Offset<th>Period<th>Deadline<th>Dependence</tr>") ;
  index = 1 ;
  message = inMessagesMap.firstObject () ;
  while (message != NULL) {
    macroValidPointer (message) ;
    htmlFile.outputRawData ("<tr class=\"result_line\"><td>") ;
    htmlFile << cStringWithSigned (index) ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << message->mKey.cString (HERE) ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << cStringWithUnsigned (message->mInfo.mNetworkIndex.uintValue () +1) ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << kMessageClasses [message->mInfo.mClass.uintValue ()];
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << cStringWithUnsigned (message->mInfo.mPriority.uintValue ()) ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << cStringWithUnsigned (message->mInfo.mBytesCount.uintValue ()) ;
    htmlFile.outputRawData ("</td><td>") ;
    
    PMSInt32 resourceId =  NumberOfProcessors + (PMSInt32) message->mInfo.mNetworkIndex.uintValue ();
    PMSInt32 Scal = Resource (resourceId COMMA_HERE).mStep ;
    
    if ( (strstr(kMessageClasses [message->mInfo.mClass.uintValue ()],"standard") != NULL)
    		|| 
    		(strstr(kMessageClasses [message->mInfo.mClass.uintValue ()],"extended") != NULL)
    		){ 
      		if (useCANmaxLengthOnly){
      		  htmlFile << cStringWithSigned (Element((index-1+NumberOfTasks) COMMA_HERE).mMaxDuration / Scal) ;
      		}else{
      			htmlFile << cStringWithSigned (Element((index-1+NumberOfTasks) COMMA_HERE).mMinDuration / Scal);
      			htmlFile.outputRawData ("--");
      			htmlFile << cStringWithSigned (Element((index-1+NumberOfTasks) COMMA_HERE).mMaxDuration / Scal) ;
      		}
    }else{
      htmlFile << cStringWithSigned (Element((index-1+NumberOfTasks) COMMA_HERE).mMaxDuration /Scal) ;
    }
    htmlFile.outputRawData ("</td><td>");    
    htmlFile << cStringWithUnsigned (message->mInfo.mOffset.uintValue ()) ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << cStringWithSigned (Element (index-1 + NumberOfTasks  COMMA_HERE).mEveryMultiple *  
                                   Element (index-1 + NumberOfTasks  COMMA_HERE).mPeriod /Scal);
    htmlFile.outputRawData ("</td><td>") ; 
    if (message->mInfo.mDeadline.uintValue () == PMUINT32_MAX){
    	htmlFile.outputRawData ("Unknown</td><td>") ;
    }else{
     	htmlFile << cStringWithUnsigned (message->mInfo.mDeadline.uintValue ()) ;
    	htmlFile.outputRawData ("</td><td>") ;
    }
   	if (message->mInfo.mMessageKind (HERE)->messageDependsOnTask ()) {
    	htmlFile.outputRawData ("task #") ;
     	htmlFile << cStringWithUnsigned (message->mInfo.mMessageKind (HERE)->getMessageDependanceValue ()+1) ;
    }else if (message->mInfo.mMessageKind (HERE)->messageDependsOnMessage ()) {
    	htmlFile.outputRawData ("message # ") ;
 	   	htmlFile << cStringWithUnsigned (message->mInfo.mMessageKind (HERE)->getMessageDependanceValue ()+1) ;
    }else{
    	htmlFile.outputRawData (" ---") ;
    }
    
    htmlFile.outputRawData ("</td></tr>") ;
    message = message->nextObject () ;
    index ++ ;
  }
  htmlFile.outputRawData ("</table>") ;
  htmlFile.outputRawData ("<br>");
  htmlFile.flush () ;
//*----------------------------------------------------------------------/  
  
// Verification of  necessary scheduling conditions 

  if (NecessaryConditions_OK (inLexique, Element, Resource) ){
  
  	TC_UniqueArray <cActivity> exElement ;
  	TC_UniqueArray <cResponseTime> responseTimeArray ;
  	TC_UniqueArray <cMTElement> MTElement ;
  	TC_UniqueArray <cReadyAtThisInstant>  ReadyAtThisInstant;
   
   PMSInt32 NoInterButUseB = 
         BuildExtendedList (inLexique,
                            ReadyAtThisInstant, Element, 
             Resource, exElement, 
             MTElement,NumberOfTasks,
             NumberOfMessages,CreateIntermediateFiles,
             forceBalgorithm,
             activitiesHTMLFileName);
 	
 		// ScheduleExtendedList (exElement, responseTimeArray) ;    
    if (forceBalgorithm) {
  //    printf ("Algorithm \"B\" is used.\n") ; fflush (stdout) ;
      scheduleActivities (NoInterButUseB, DependentHasOffset, 
                          ReadyAtThisInstant, exElement, 
                          Resource, responseTimeArray) ;
    }else{
      printf ("Algorithm \"A\" is used.\n") ; fflush (stdout) ;
      independantResourcesScheduleActivities (exElement, responseTimeArray) ;
    }
		//Extract absolute bornes (min & max)
  	ExtractWorstBestRT (inLexique,
                        exElement, Resource, MTElement, 
                        responseTimeArray, CreateIntermediateFiles, 
                        raw_outputHTMLFileName, htmlFile);
    printf ("Results are stored in %s file.\n", htmlFileName.cString (HERE));
    
 	}else{
    printf ("System map is stored in %s file.\n", htmlFileName.cString (HERE));
 	}
 	fflush (stdout);
}

/*--------------------------------------------------------------------------*/
