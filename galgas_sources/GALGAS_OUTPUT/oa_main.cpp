//-----------------------------------------------------------------------------*
//                                                                             *
//                             File 'oa_main.cpp'                              *
//                         Generated by version 2.5.8                          *
//                        may 23th, 2014, at 16h50'12"                         *
//                                                                             *
//-----------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#include "oa_main.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/F_DisplayException.h"
#include "utilities/basic-allocation.h"
#include "utilities/cpp-allocation.h"
#include "utilities/C_PrologueEpilogue.h"
#include "command_line_interface/F_mainForLIBPM.h"
#include "command_line_interface/C_builtin_CLI_Options.h"
#include "command_line_interface/F_Analyze_CLI_Options.h"
#include "project_header.h"

//-----------------------------------------------------------------------------*

#include "oa_grammar.h"

//-----------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "oa_main.gProgram", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif

//-----------------------------------------------------------------------------*
//                                                                             *
//                      print_tool_help_message                                *
//                                                                             *
//-----------------------------------------------------------------------------*

static void print_tool_help_message (void) {
  co << "Compiled with GALGAS revision NUMERO_REVISION_GALGAS\n" ;
}

//-----------------------------------------------------------------------------*

static const char * kSourceFileExtensions [] = {
  "nprt",
  NULL
} ;    

//-----------------------------------------------------------------------------*

static const char * kSourceFileHelpMessages [] = {
  "an '.nprt' source file",
  NULL
} ;    

//-----------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static const char * kVersionString = "version " PROJECT_VERSION_STRING " [debug]" ;
#else
  static const char * kVersionString = "version " PROJECT_VERSION_STRING ;
#endif

//-----------------------------------------------------------------------------*
//                                                                             *
//                      M A I N    F O R    L I B P M                          *
//                                                                             *
//-----------------------------------------------------------------------------*

int mainForLIBPM (int inArgc, const char * inArgv []) {
//--- Analyze Command Line Options
  TC_UniqueArray <C_String> sourceFilesArray ;
  F_Analyze_CLI_Options (inArgc, inArgv,
                         kVersionString,
                         sourceFilesArray,
                         kSourceFileExtensions,
                         kSourceFileHelpMessages,
                         print_tool_help_message) ;
//---
  bool verboseOptionOn = true ;
  int16_t returnCode = 0 ; // No error
//--- Set Execution mode
  C_String executionModeOptionErrorMessage ;
  setExecutionMode (executionModeOptionErrorMessage) ;
  if (executionModeOptionErrorMessage.length () > 0) {
    co << executionModeOptionErrorMessage ;
    returnCode = 1 ;
  }else{
  //--- Common lexique object
    C_Compiler * commonLexique = NULL ;
    macroMyNew (commonLexique, C_Compiler (NULL, "", "" COMMA_HERE)) ;
    try{
      routine_before (commonLexique COMMA_HERE) ;
      verboseOptionOn = gOption_galgas_5F_builtin_5F_options_verbose_5F_output.mValue ;
      for (int32_t i=0 ; i<sourceFilesArray.count () ; i++) {
        setCurrentCompiledFilePath (sourceFilesArray (i COMMA_HERE)) ;
        if (gOption_galgas_5F_builtin_5F_options_trace.mValue) {
          enableTraceWithPath (sourceFilesArray (i COMMA_HERE)) ;
        }
        const C_String fileExtension = sourceFilesArray (i COMMA_HERE).pathExtension () ;
        const GALGAS_string sfp = GALGAS_string (sourceFilesArray (i COMMA_HERE)) ;
        const GALGAS_location location = commonLexique->here () ;
        const GALGAS_lstring sourceFilePath (sfp, location) ;
        int16_t r = 0 ;
        if (fileExtension == "nprt") {
          routine_programRule_5F__30_ (sourceFilePath, commonLexique COMMA_HERE) ;
        }else{
          printf ("*** Error: unhandled extension for file '%s' ***\n", sourceFilesArray (i COMMA_HERE).cString (HERE)) ;
          r = 1 ;
        }
        if (r != 0) {
          returnCode = r ;
        }
        closeTrace () ;
      }
    //--- Error or warnings ?
      if (totalErrorCount () > 0) {
        returnCode = 1 ; // Error code
      }else if (totalWarningCount () > 0) {
        if (gOption_galgas_5F_builtin_5F_options_treat_5F_warnings_5F_as_5F_error.mValue) {
          returnCode = 1 ; // Error code
          if (verboseOptionOn) {
            printf ("** Note: warnings are treated as errors. **\n") ;
          }
        }
      }
    //--- Epilogue
      routine_after (commonLexique COMMA_HERE) ;
    //--- Display error and warnings count
      if (gOption_galgas_5F_builtin_5F_options_verbose_5F_output.mValue || (totalWarningCount () > 0) || (totalErrorCount () > 0)) {
        C_String message ;
        if (totalWarningCount () == 0) {
          message << "No warning" ;
        }else if (totalWarningCount () == 1) {
          message << "1 warning" ;
        }else{
          message << cStringWithSigned (totalWarningCount ()) << " warnings" ;
        }
        message << ", " ;
        if (totalErrorCount () == 0) {
          message << "no error" ;
        }else if (totalErrorCount () == 1) {
          message << "1 error" ;
        }else{
          message << cStringWithSigned (totalErrorCount ()) << " errors" ;
        }
        message << ".\n" ;
        ggs_printMessage (message COMMA_HERE) ;
      }
    }catch (const ::std:: exception & e) {
      F_default_display_exception (e) ;
      returnCode = 1 ; // Error code
    }catch (...) {
      printf ("**** Unknow exception ****\n") ;
      throw ;
    }
    macroDetachSharedObject (commonLexique) ;
  }
  return returnCode ;
}

//-----------------------------------------------------------------------------*
//                                                                             *
//                              Routine 'before'                               *
//                                                                             *
//-----------------------------------------------------------------------------*

void routine_before (C_Compiler * /* inCompiler */
                     COMMA_UNUSED_LOCATION_ARGS) {
}


//-----------------------------------------------------------------------------*
//                                                                             *
//                           Routine 'programRule_0'                           *
//                                                                             *
//-----------------------------------------------------------------------------*

void routine_programRule_5F__30_ (const GALGAS_lstring constinArgument_inSourceFile,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  {
  cGrammar_oa_5F_grammar::_performSourceFileParsing_ (inCompiler, constinArgument_inSourceFile COMMA_SOURCE_FILE_AT_LINE (14)) ;
  }
}


//-----------------------------------------------------------------------------*
//                                                                             *
//                               Routine 'after'                               *
//                                                                             *
//-----------------------------------------------------------------------------*

void routine_after (C_Compiler * /* inCompiler */
                    COMMA_UNUSED_LOCATION_ARGS) {
}


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2


