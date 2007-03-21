//---------------------------------------------------------------------------*
//                                                                           *
//                            File 'oa_main.cpp'                             *
//         Generated by version GALGAS_BETA_VERSION (LL(1) grammar)          *
//                      march 21th, 2007, at 14h50'51"                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#include "version_libpm.h"
#if LIBPM_VERSION != THE_LIBPM_VERSION
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include "utilities/F_DisplayException.h"
#include "utilities/MF_MemoryControl.h"
#include "generic_arraies/TC_UniqueArray.h"
#include "command_line_interface/F_Analyze_CLI_Options.h"
#include "command_line_interface/mainForLIBPM.h"
#include "utilities/MF_MemoryControl.h"

#ifdef TARGET_API_MAC_CARBON
  #include <SIOUX.H>
#endif

#ifdef COMPILE_FOR_WIN32
  #ifdef __MWERKS__
    #include <WINSIOUX.H>
  #endif
#endif

//---------------------------------------------------------------------------*

#include "oa_grammar.h"
#include "oa_main.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "oa_main.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//                    C_options_for_oa_main  CONSTRUCTOR                     *
//                                                                           *
//---------------------------------------------------------------------------*

C_options_for_oa_main::
C_options_for_oa_main (const bool inAcceptsDebugOption)
:mBuiltinOptions (inAcceptsDebugOption) {
  add (& mBuiltinOptions) ;
  add (& mGalgasOptions) ;
  add (& mOptions_oa_cli_options) ;
}

int mainForLIBPM  (const int argc, const char * argv []) {
  bool verboseOptionOn = true ;
  sint16 returnCode = 0 ; // No error
  {
  //--- Input/output parameters
    C_options_for_oa_main options (false) ;
    C_galgas_io_parameters IOparameters  (& options) ;
    #ifndef DO_NOT_GENERATE_CHECKINGS
      IOparameters.mCompilerVersion = "version 1.1.9" " [debug]" ;
    #else
      IOparameters.mCompilerVersion = "version 1.1.9" ;
    #endif
    IOparameters.mMaxErrorCount = 100 ;
    IOparameters.mMaxWarningCount = 100 ;
    const char * extensions [] = {"nprt", NULL} ;
    const char * helpMessages [] = {"an '.nprt' source file", NULL} ;
    TC_UniqueArray <C_String> sourceFilesArray ;
  //--- Analyze Command Line Options
    F_Analyze_CLI_Options (argc, argv,
                           "version 1.1.9",
                           options,
                           sourceFilesArray,
                           extensions,
                           helpMessages,
                           IOparameters.mCocoaOutput) ;
  //--- Build galgas io object
    C_galgas_io * galgasIOptr = NULL ;
    macroMyNew (galgasIOptr, C_galgas_io (IOparameters, C_galgas_io::kTerminalOutputKind COMMA_HERE)) ;
  //--- Common lexique object
    C_Compiler * _commonLexique = NULL ;
    macroMyNew (_commonLexique, C_Compiler (galgasIOptr COMMA_HERE)) ;
  //--- Ask Save On Close ? (Carbon and Windows SIOUX Only)
    #ifdef SIOUX_IS_IMPLEMENTED
      SIOUXSettings.asktosaveonclose = options.boolOptionValueFromKeys ("generic_cli_options",
                                                                        ASK_TO_SAVE_ON_CLOSE,
                                                                        false) ;
    #endif
  //--- Enable 64 bit alloc debug ? Only if compiled in 64 bit and in debug mode
    #ifndef DO_NOT_GENERATE_CHECKINGS
      #ifdef __LP64__
        if (options.boolOptionValueFromKeys ("generic_cli_options",
                                             "enable_allocation_debugging",
                                             false)) {
          enableAllocDebugFor64BitTool () ;
        }
      #endif
    #endif
    try{
      verboseOptionOn = options.boolOptionValueFromKeys ("generic_galgas_cli_options",
                                                         "verbose_output",
                                                         false) ;
      oa_main_prologue (options, sourceFilesArray) ;
      for (sint32 i=0 ; i<sourceFilesArray.count () ; i++) {
        const C_String fileExtension = sourceFilesArray (i COMMA_HERE).pathExtension () ;
        sint16 r = 0 ;
        if (fileExtension.compare ("nprt") == 0) {
          C_Compiler & _inLexique = * _commonLexique ;
          const GGS_string _source (true, sourceFilesArray (i COMMA_HERE)) ;
          const GGS_location _here (_inLexique) ;
          const GGS_lstring var_cas_inSourceFile (GGS_lstring::constructor_new (_inLexique, _source, _here COMMA_HERE)) ;
          { oa_scanner * scanner_ = NULL ;
            const C_String sourceFileName = _inLexique.sourceFileName ().stringByDeletingLastPathComponent ().stringByAppendingPathComponent (var_cas_inSourceFile) ;
            macroMyNew (scanner_, oa_scanner (_inLexique.ioParametersPtr (), sourceFileName COMMA_HERE)) ;
            scanner_->mPerformGeneration = _inLexique.mPerformGeneration ;
            oa_grammar grammar_ ;
            try{
              grammar_.startParsing_ (*scanner_) ;
            }catch (const C_TextReadException & inFileReadError) {
              var_cas_inSourceFile.signalSemanticError (_inLexique, inFileReadError.what () COMMA_SOURCE_FILE_AT_LINE (14)) ;
            }
            macroDetachPointer (scanner_, oa_scanner) ;
          }
          if (verboseOptionOn || ((_inLexique.totalErrorCount () + _inLexique.totalWarningCount ()) > 0)) {
            co << "Analysis of '" << sourceFilesArray (i COMMA_HERE).lastPathComponent () << "' completed. " ;
            switch (_commonLexique->totalErrorCount ()) {
            case 0 :
              if (verboseOptionOn) {
                co << "No error, " ;
              }
              break ;
            case 1 :
              co << "1 error, " ;
              returnCode = 1 ; // Error code
              break ;
            default :
              co << _commonLexique->totalErrorCount () << " errors, " ;
              returnCode = 1 ; // Error code
              break ;
            }
            switch (_commonLexique->totalWarningCount ()) {
            case 0 :
              if (verboseOptionOn) {
                co << "no warning" ;
              }
              break ;
            case 1 :
              co << "1 warning" ;
              break ;
            default :
              co << _commonLexique->totalWarningCount () << " warnings" ;
              break ;
            }
            if (verboseOptionOn || ((_commonLexique->totalErrorCount () + _commonLexique->totalWarningCount ()) > 0)) {
              co << ".\n" ;
            }
          }
        }else{
          printf ("*** Error: unhandled extension for file '%s' ***\n", sourceFilesArray (i COMMA_HERE).cString ()) ;
          r = 1 ;
        }
        if (r != 0) {
          returnCode = r ;
        }
      }
    //--- Error or warnings ?
      if (_commonLexique->totalErrorCount () > 0) {
        returnCode = 1 ; // Error code
      }else if (_commonLexique->totalWarningCount () > 0) {
        const bool warningsAreTreatedAsError
            = options.boolOptionValueFromKeys ("generic_galgas_cli_options",
                                               "treat_warnings_as_error",
                                               false) ;
        if (warningsAreTreatedAsError) {
          returnCode = 1 ; // Error code
          if (verboseOptionOn) {
            printf ("** Note: warnings are treated as errors. **\n") ;
          }
        }
      }
    //--- Epilogue
      oa_main_epilogue (options) ;
    }catch (const M_STD_NAMESPACE exception & e) {
      F_default_display_exception (e) ;
      returnCode = 1 ; // Error code
    }catch (...) {
      F_default_display_unknown_exception () ;
      returnCode = 2 ; // Error code
    }
    macroDetachPointer (galgasIOptr, C_galgas_io) ;
    macroDetachPointer (_commonLexique, C_Compiler) ;
    C_TreewalkingDispacher::releaseAllTables () ;
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    C_GGS_Object::checkAllObjectsHaveBeenReleased () ;
  #endif
  if (verboseOptionOn) {
    #ifndef DO_NOT_GENERATE_CHECKINGS
      const uint64 maxUsedMemorySize = getMaxUsedMemorySize () ;
      const uint64 oneMegaByte = 1 << 20 ;
      const uint64 megaBytes = maxUsedMemorySize / oneMegaByte ;
      const uint64 fraction = ((maxUsedMemorySize % oneMegaByte) * 1000) / oneMegaByte ;
      co << getCreatedDynamicObjectsTotalCount ()
         << " C++ objects have been created ("
         << megaBytes << "." << widthWithZeroFill (3) << fraction
         << " MB).\n" ;
      deactivateMemoryControl () ;
      if ((getAllocationBalance () != 0) && (returnCode == 0)) {
        display_pointers () ;
      }
    #endif
  }
  return returnCode ;
}

//---------------------------------------------------------------------------*

//--- START OF USER ZONE 2


//---------------------------------------------------------------------------*
//                                                                           *
//                     P R O G R A M    P R O L O G U E                      *
//                                                                           *
//---------------------------------------------------------------------------*

void oa_main_prologue (const C_options_for_oa_main & /* inOptions */,
                       const TC_UniqueArray <C_String> & /* inSourceFilesArray */) {
// ADD YOUR CODE HERE
}
//---------------------------------------------------------------------------*
//                                                                           *
//                     P R O G R A M    E P I L O G U E                      *
//                                                                           *
//---------------------------------------------------------------------------*

void oa_main_epilogue (const C_options_for_oa_main & /* inOptions */) {
// ADD YOUR CODE HERE
}

//--- END OF USER ZONE 2


