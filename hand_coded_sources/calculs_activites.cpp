/*--------------------------------------------------------------------------*/

#include<stdlib.h> 
#include "files/C_HTML_FileWrite.h"
#include "utilities/MF_MemoryControl.h"

#include "oa_semantics.h"
#include "CANMessageBounds.h"
#include "ExtendedList.h"
#include "VerifyConditions.h"
#include "activities_core.h"

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

uint32 cPtr_C_canIndependantMessage::getMessageDependanceValue (void) const {
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

uint32 cPtr_C_canMessageFromMessage::getMessageDependanceValue (void) const {
  return mMessageIndex.getValue () ;
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

uint32 cPtr_C_canMessageFromTask::getMessageDependanceValue (void) const {
  return mTaskIndex.getValue () ;
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

uint32 cPtr_C_independantTask::getTaskDependanceValue (void) const {
  return 0 ;
}

//--------------------------------------------------------------------------*

uint32 cPtr_C_independantTask::getTaskEveryParameter (void) const {
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

uint32 cPtr_C_taskDependsFromTask::getTaskDependanceValue (void) const {
  return mTask.getValue () ;
}

//--------------------------------------------------------------------------*

uint32 cPtr_C_taskDependsFromTask::getTaskEveryParameter (void) const {
  return mEvery.getValue () ;
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

uint32 cPtr_C_taskDependsFromMessage::getTaskDependanceValue (void) const {
  return mMessage.getValue () ;
}

//--------------------------------------------------------------------------*

uint32 cPtr_C_taskDependsFromMessage::getTaskEveryParameter (void) const {
  return mEvery.getValue () ;
}

//--------------------------------------------------------------------------*
//                                                                          *
//     Build style file                                                     *
//                                                                          *
//--------------------------------------------------------------------------*


static void buildCSSfile (const C_String & inDirectory) {
//--- Style file name
  const C_String styleFileName = inDirectory + "/style.css" ;
//--- Build file
  C_TextFileWrite f (styleFileName COMMA_SAFARI_CREATOR COMMA_HERE) ;
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
performComputations (C_Lexique & inLexique,
                     GGS_M_processor & inProcessorMap,
                     GGS_M_network & inNetworkMap,
                     GGS_M_messages & inMessagesMap,
                     GGS_M_tasks & inTasksMap) {  
  TC_UniqueArray <cResource> Resource ;
  TC_UniqueArray <cElement> Element ;

  const bool CreateIntermediateFiles = inLexique.getBoolOptionValueFromKeys ("oa_cli_options", "createIntermediateFiles", true) ;
  const bool useCANmaxLengthOnly = inLexique.getBoolOptionValueFromKeys ("oa_cli_options", "useCANmaxLegth", true) ;
  bool forceBalgorithm = true ;
  const C_String sourceFile = inLexique.getSourceFile () ;
  

  const C_String htmlFileName = sourceFile.getPath () + "/" + sourceFile.getFileNameWithoutSuffix () + ".html" ;
  const C_String activitiesHTMLFileName = sourceFile.getPath () + "/" + sourceFile.getFileNameWithoutSuffix () + "_activities.html" ;
  const C_String raw_outputHTMLFileName = sourceFile.getPath () + "/" + sourceFile.getFileNameWithoutSuffix () + "_raw_output.html" ;

  buildCSSfile (sourceFile.getPath ()) ;
  C_HTML_FileWrite htmlFile ( htmlFileName,
                              sourceFile.getFileNameWithSuffix () + " results",
                              "style.css"
                              COMMA_SAFARI_CREATOR
                              COMMA_HERE) ;
  if(useCANmaxLengthOnly){
  	printf("Elements have their upper duration bounds.\n"); 
  }
  char MessageType = '\0' ;
  bool DependentHasOffset = false ;
	sint32  index ;
	GGS_M_processor::element_type * processor = inProcessorMap.getFirstItem () ;
//--- Print processors map
  htmlFile.writeTitleComment ("Processors map", "title") ;
  htmlFile.outputRawData ("<br><table class=\"result\"><tr class=\"result_title\"><td>");
	htmlFile.outputRawData ("#<th>Name<th>ScaFactor</tr>") ;
	index = 1 ;
	while (processor != NULL) {
	  macroValidPointer (processor) ;
	  htmlFile.outputRawData ("<tr class=\"result_line\"><td>") ;
	  htmlFile << index ;
	  htmlFile.outputRawData ("</td><td>") ;
	  htmlFile << processor->mKey ;
	  htmlFile.outputRawData ("</td><td>") ;
	  htmlFile << processor->mInfo.mStep.getValue () ;
	  htmlFile.outputRawData ("</td></tr>") ;
	  processor = processor->getNextItem () ;
	  index ++ ;
	}
	htmlFile.outputRawData ("</table>") ;
	htmlFile.outputRawData ("<br>");
//--- Build processors map  
  index = 0 ;
  processor = inProcessorMap.getFirstItem () ;
  while (processor != NULL) {
    macroValidPointer (processor) ;
    cResource resource ;
    strcpy (resource.mResourceName, processor->mKey.getStringPtr ());
  	resource.mResourceType= 2; // Processor = 2
   	resource.mStep = (sint32) processor->mInfo.mStep.getValue () ;
    
    Resource.addObject (resource) ;
    processor = processor->getNextItem () ;
    index ++ ;
  }
  sint32 NumberOfProcessors = index ;
	
  const char * kNetworkTypes [] = {"VAN","CAN"} ;
	GGS_M_network::element_type * network = inNetworkMap.getFirstItem () ;
//--- Print network map
  htmlFile.writeTitleComment ("Networks map", "title") ;
  htmlFile.outputRawData ("<br><table class=\"result\"><tr class=\"result_title\"><td>");
  htmlFile.outputRawData ("#<th>Name<th>Type<th>ScaFactor</tr>") ;
  index = 1 ;
  while (network != NULL) {
    macroValidPointer (network) ;
    htmlFile.outputRawData ("<tr class=\"result_line\"><td>") ;
    htmlFile << index ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << network->mKey ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << kNetworkTypes [network->mInfo.mCANnetwork.getValue ()] ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << network->mInfo.mScalingFactor.getValue () ;
    htmlFile.outputRawData ("</td></tr>") ;
    network = network->getNextItem () ;
    index ++ ;
  }
  htmlFile.outputRawData ("</table>") ;
  htmlFile.outputRawData ("<br>");
//--- Build networks map  
  sint32 min_NetworkStep = SINT32_MAX ;
  index = 0 ;
  network = inNetworkMap.getFirstItem ();
  while (network != NULL) {
    macroValidPointer (network) ;
    cResource resource ;
    strcpy(resource.mResourceName,network->mKey.getStringPtr ());
  	resource.mResourceType= network->mInfo.mCANnetwork.getValue ();
    resource.mStep = (sint32) network->mInfo.mScalingFactor.getValue () ;		
 		min_NetworkStep = min (min_NetworkStep, resource.mStep);
 	 	
 	 	Resource.addObject (resource) ;
    network = network->getNextItem () ;
    index ++ ;
  }
  
//--- Build tasks map  
  GGS_M_tasks::element_type * task = inTasksMap.getFirstItem () ;
  index = 0 ;
  task = inTasksMap.getFirstItem () ;
  while (task != NULL) {
    macroValidPointer (task) ;
    cElement element ;
    strcpy(element.mElementName,task->mKey.getStringPtr ());   
    element.mElementType = 'T';    
    element.mId_inList =index;
  	element.mResourceId = (sint32) task->mInfo.mProcessor.getValue ();
    element.mPriority = (sint32) task->mInfo.mPriority.getValue ();
// �    element.mEvery = 1 ;
    sint32 Sca = Resource (element.mResourceId COMMA_HERE).mStep ;
//    printf (" Sca : %ld \n",Sca);
    element.mEvery = (sint32) task->mInfo.mTaskKind ()->getTaskEveryParameter () ;
  	element.mOffset = Sca*(sint32) task->mInfo.mOffset.getValue ();  
    element.mMaxDuration = Sca*(sint32) task->mInfo.mDurationMax.getValue (); 
    element.mMinDuration = useCANmaxLengthOnly
                          ? element.mMaxDuration :(Sca*(sint32)  task->mInfo.mDurationMin.getValue ());
        
    element.mDeadline = (sint32) task->mInfo.mDeadline.getValue ();
    if ( element.mDeadline !=  SINT32_MAX){ // UINT32_MAX -> SINT32_MAX by PM, 17/1/2005
    	 element.mDeadline = Sca*element.mDeadline;
    }  
 //................................................   
    if (task->mInfo.mTaskKind ()->taskDependsOnTask ()) {
    	sint32 elementIndex = (sint32) task->mInfo.mTaskKind ()->getTaskDependanceValue ();
    	element.mEveryMultiple = 
    		 (sint32) task->mInfo.mTaskKind ()->getTaskEveryParameter () * Element (elementIndex COMMA_HERE).mEveryMultiple; 
   		element.mPeriod = Sca*(sint32) task->mInfo.mPeriod.getValue ();
    } else if (task->mInfo.mTaskKind ()->taskDependsOnMessage ()){
    
    }else{
    	element.mEveryMultiple = (sint32) task->mInfo.mTaskKind ()->getTaskEveryParameter () ;
    	element.mPeriod = Sca*(sint32) task->mInfo.mPeriod.getValue ();
    }
 //................................................
  	if (task->mInfo.mTaskKind ()->taskDependsOnTask ()) {
      element.mIsIndependant=false ;
    	element.mPredecessorType = 'T'; 
      element.mPredecessorId = 
      sint32 (task->mInfo.mTaskKind ()->getTaskDependanceValue ());
    }else if (task->mInfo.mTaskKind ()->taskDependsOnMessage ()) {
      element.mIsIndependant=false ;
    	element.mPredecessorType = 'M'; 
      element.mPredecessorId = 
      sint32 (task->mInfo.mTaskKind ()->getTaskDependanceValue ()) ;
    }else{ 
    	element.mIsIndependant=true ;
    }
    if (!element.mIsIndependant && (element.mOffset != 0)){
      DependentHasOffset = DependentHasOffset || true ;
    }
    Element.addObject (element) ;
		task = task->getNextItem () ;
    index ++ ;
  }
  sint32 NumberOfTasks = index;
	
  const char * kMessageClasses [] = {"standard", "extended", "  VAN   "} ;
  GGS_M_messages::element_type * message = inMessagesMap.getFirstItem () ;

//--- Build messages map
  index = 0 ;
  message = inMessagesMap.getFirstItem () ;
  while (message != NULL) {
    macroValidPointer (message) ;
    cElement element ;
    strcpy(element.mElementName,message->mKey.getStringPtr ());
  	element.mElementType = 'M';
    element.mId_inList = index;
  	element.mResourceId = NumberOfProcessors + 
  		(sint32) message->mInfo.mNetworkIndex.getValue ();
  	element.mPriority = (sint32) message->mInfo.mPriority.getValue ();
  	element.mEvery = 1 ;
  	sint32 ScalingFactor = 
					 Resource (element.mResourceId COMMA_HERE).mStep;
	//  printf (" Sca : %ld \n",ScalingFactor);
	  element.mOffset = ScalingFactor*(sint32) message->mInfo.mOffset.getValue (); 
  	if ( Resource (element.mResourceId COMMA_HERE).mResourceType == 1 ){ //CAN = 1
    	if (strstr(kMessageClasses [message->mInfo.mClass.getValue ()],"standard") != NULL){ 
    		MessageType = 'S';
    	}else if (strstr(kMessageClasses [message->mInfo.mClass.getValue ()],
      					"extended") != NULL){ 
      	MessageType = 'X' ;
      }else{ 
      	printf ("ERROR : message #%ld is neither standard (S)\
      		nor extended (X) message!\n", index) ;
      }
      
      element.mMaxDuration = ScalingFactor* maxCANMessageTime(MessageType,
      											 (uint32) element.mMinDuration,
      											 message->mInfo.mBytesCount.getValue ());
  
      element.mMinDuration = useCANmaxLengthOnly
        ? element.mMaxDuration
        : (ScalingFactor * minCANMessageTime(MessageType,
                            message->mInfo.mPriority.getValue (),
                            message->mInfo.mBytesCount.getValue ()));
                            
  	}else if (Resource (element.mResourceId COMMA_HERE).mResourceType == 0 ){ //VAN = 0
    	
    	element.mMinDuration= ScalingFactor *(64+10* (sint32) message->mInfo.mBytesCount.getValue ()) ;

    	element.mMaxDuration= ScalingFactor* element.mMinDuration;
  	}else{ 
       printf ("ERROR : bus is neither CAN nor VAN!\n") ;
      fflush (stdout);  
		}
		
    element.mDeadline =  (sint32) message->mInfo.mDeadline.getValue ();
    if ( element.mDeadline !=  SINT32_MAX){ // UINT32_MAX -> SINT32_MAX by PM, 17/1/2005
    	 element.mDeadline = ScalingFactor *element.mDeadline;
    }  
 //...........................................................................
    sint32 elementIndex ;
   if (message->mInfo.mMessageKind ()->messageDependsOnTask ()) {
   	 elementIndex = (sint32) message->mInfo.mMessageKind ()->getMessageDependanceValue ();
     element.mEveryMultiple = Element (elementIndex COMMA_HERE).mEveryMultiple ;  
     element.mPeriod = Element (elementIndex COMMA_HERE).mPeriod ; 
   }else if (message->mInfo.mMessageKind ()->messageDependsOnMessage ()) {
     elementIndex = (sint32) message->mInfo.mMessageKind ()->getMessageDependanceValue () + NumberOfTasks ;
     element.mEveryMultiple = Element (elementIndex COMMA_HERE).mEveryMultiple; 
     element.mPeriod = Element (elementIndex COMMA_HERE).mPeriod ;
   } else{
   	 element.mEveryMultiple = 1;
   	  element.mPeriod = ScalingFactor * (sint32) message->mInfo.mPeriod.getValue ();
   }
 //.................................................................................   
  	if (message->mInfo.mMessageKind ()->messageDependsOnTask ()) {
      element.mIsIndependant=false ;
    	element.mPredecessorType = 'T'; 
      element.mPredecessorId = 
         (sint32) message->mInfo.mMessageKind ()->getMessageDependanceValue ();
    }else if (message->mInfo.mMessageKind ()->messageDependsOnMessage ()) {
    	element.mIsIndependant=false ;
    	element.mPredecessorType = 'M'; 
      element.mPredecessorId = \
      	(sint32) message->mInfo.mMessageKind ()->getMessageDependanceValue () ;
    }else{ 
    	element.mIsIndependant=true ;
    }
    if (!element.mIsIndependant && (element.mOffset != 0)){
      DependentHasOffset = DependentHasOffset || true ;
    }
    Element.addObject (element) ;
	  message = message->getNextItem () ;
    index ++ ;
  }
  sint32 NumberOfMessages = index;  
//*----------------------------------------------------------------------/  
	//--- Print task map
  
	htmlFile.writeTitleComment ("Tasks map", "title") ;
  htmlFile.outputRawData ("<br><table class=\"result\"><tr class=\"result_title\"><td>") ;
  htmlFile.outputRawData ("#<th>Name<th>Processor<th>Priority<th>");
  htmlFile.outputRawData ("Offset<th>Min<th>Max<th>Period<th>") ;
  htmlFile.outputRawData ("Deadline<th>Dependence<th>Every</tr>") ;
  index = 1 ;
  task = inTasksMap.getFirstItem () ;
  while (task != NULL) {
    macroValidPointer (task) ;
    htmlFile.outputRawData ("<tr class=\"result_line\"><td>") ;
    htmlFile << index ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << task->mKey.getStringPtr () ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << task->mInfo.mProcessor.getValue ()+1 ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << task->mInfo.mPriority.getValue () ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << task->mInfo.mOffset.getValue ();
    htmlFile.outputRawData ("</td><td>") ;
    if (useCANmaxLengthOnly){
      htmlFile << task->mInfo.mDurationMax.getValue () ;
    }else {
      htmlFile << task->mInfo.mDurationMin.getValue () ;
    }
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << task->mInfo.mDurationMax.getValue () ;
    htmlFile.outputRawData ("</td><td>") ;
//....................................................................   
    if (task->mInfo.mTaskKind ()->taskDependsOnMessage ()) {
    	sint32 elementIndex = (sint32) task->mInfo.mTaskKind ()->getTaskDependanceValue () + NumberOfTasks ;
    	Element (index-1 COMMA_HERE).mEveryMultiple = 
    		 (sint32) task->mInfo.mTaskKind ()->getTaskEveryParameter () * Element (elementIndex COMMA_HERE).mEveryMultiple; 
    	Element (index-1 COMMA_HERE).mPeriod = Element (elementIndex COMMA_HERE).mPeriod  ;
    }
 //...................................................................
    sint32 resourceId = (sint32) task->mInfo.mProcessor.getValue ();
    sint32 Scal = Resource (resourceId COMMA_HERE).mStep ;

    htmlFile << Element (index-1 COMMA_HERE).mEveryMultiple * Element (index-1 COMMA_HERE).mPeriod /Scal ;
    htmlFile.outputRawData ("</td><td>") ;
    if (task->mInfo.mDeadline.getValue () == UINT32_MAX){
    	htmlFile.outputRawData ("Unknown</td><td>") ;
    }else{
     	htmlFile << task->mInfo.mDeadline.getValue () ;
    	htmlFile.outputRawData ("</td><td>") ;
    }
    if (task->mInfo.mTaskKind ()->taskDependsOnTask ()) {
      htmlFile.outputRawData ("task #") ;
      htmlFile << task->mInfo.mTaskKind ()->getTaskDependanceValue ()+1 ;
    }else if (task->mInfo.mTaskKind ()->taskDependsOnMessage ()) {
      htmlFile.outputRawData ("message #") ;
      htmlFile << task->mInfo.mTaskKind ()->getTaskDependanceValue ()+1 ;
    }else{
    	htmlFile.outputRawData (" ---") ;
    }
     htmlFile.outputRawData ("</td><td>") ;
     htmlFile << task->mInfo.mTaskKind ()->getTaskEveryParameter () ;
      
    htmlFile.outputRawData ("</td></tr>") ;
    task = task->getNextItem () ;
    index ++ ;
  }
  htmlFile.outputRawData ("</table>") ;
  htmlFile.outputRawData ("<br>");

//--- Print messages map
  htmlFile.writeTitleComment ("Messages map", "title") ;
  htmlFile.outputRawData ("<br><table class=\"result\"><tr class=\"result_title\"><td>") ;
  htmlFile.outputRawData ("#<th>Name<th>Network<th>Type<th>Priority<th>Byte");
  htmlFile.outputRawData ("<th> min--max ") ;
  htmlFile.outputRawData ("<th>Offset<th>Period<th>Deadline<th>Dependence</tr>") ;
  index = 1 ;
  message = inMessagesMap.getFirstItem () ;
  while (message != NULL) {
    macroValidPointer (message) ;
    htmlFile.outputRawData ("<tr class=\"result_line\"><td>") ;
    htmlFile << index ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << message->mKey.getStringPtr () ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << message->mInfo.mNetworkIndex.getValue () +1;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << kMessageClasses [message->mInfo.mClass.getValue ()];
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << message->mInfo.mPriority.getValue () ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << message->mInfo.mBytesCount.getValue () ;
    htmlFile.outputRawData ("</td><td>") ;
    
    sint32 resourceId =  NumberOfProcessors + (sint32) message->mInfo.mNetworkIndex.getValue ();
    sint32 Scal = Resource (resourceId COMMA_HERE).mStep ;
    
    if ( (strstr(kMessageClasses [message->mInfo.mClass.getValue ()],"standard") != NULL)
    		|| 
    		(strstr(kMessageClasses [message->mInfo.mClass.getValue ()],"extended") != NULL)
    		){ 
      		if (useCANmaxLengthOnly){
      		  htmlFile << Element((index-1+NumberOfTasks) COMMA_HERE).mMaxDuration / Scal ;
      		}else{
      			htmlFile << Element((index-1+NumberOfTasks) COMMA_HERE).mMinDuration / Scal;
      			htmlFile.outputRawData ("--");
      			htmlFile << Element((index-1+NumberOfTasks) COMMA_HERE).mMaxDuration / Scal ;
      		}
    }else{
      htmlFile <<Element((index-1+NumberOfTasks) COMMA_HERE).mMaxDuration /Scal ;
    }
    htmlFile.outputRawData ("</td><td>");    
    htmlFile << message->mInfo.mOffset.getValue () ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << Element (index-1 + NumberOfTasks  COMMA_HERE).mEveryMultiple *  
                Element (index-1 + NumberOfTasks  COMMA_HERE).mPeriod /Scal;
    htmlFile.outputRawData ("</td><td>") ; 
    if (message->mInfo.mDeadline.getValue () == UINT32_MAX){
    	htmlFile.outputRawData ("Unknown</td><td>") ;
    }else{
     	htmlFile << message->mInfo.mDeadline.getValue () ;
    	htmlFile.outputRawData ("</td><td>") ;
    }
   	if (message->mInfo.mMessageKind ()->messageDependsOnTask ()) {
    	htmlFile.outputRawData ("task #") ;
     	htmlFile << message->mInfo.mMessageKind ()->getMessageDependanceValue ()+1 ;
    }else if (message->mInfo.mMessageKind ()->messageDependsOnMessage ()) {
    	htmlFile.outputRawData ("message # ") ;
 	   	htmlFile << message->mInfo.mMessageKind ()->getMessageDependanceValue ()+1 ;
    }else{
    	htmlFile.outputRawData (" ---") ;
    }
    
    htmlFile.outputRawData ("</td></tr>") ;
    message = message->getNextItem () ;
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
   
   sint32 NoInterButUseB = 
         BuildExtendedList (ReadyAtThisInstant, Element, 
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
  	ExtractWorstBestRT (exElement, Resource, MTElement, 
                        responseTimeArray, CreateIntermediateFiles, 
                        raw_outputHTMLFileName, htmlFile);
    printf ("Results are stored in %s file.\n", htmlFileName.getStringPtr ());
    
 	}else{
    printf ("System map is stored in %s file.\n", htmlFileName.getStringPtr ());
 	}
 	fflush (stdout);
}

/*--------------------------------------------------------------------------*/
