//---------------------------------------------------------------------------*
//                                                                           *
//                            File 'oa_main.cpp'                             *
//         Generated by version GALGAS_BETA_VERSION (LL(1) grammar)          *
//                    december 27th, 2005, at 21h32'20"                      *
//                                                                           *
// This file is free software; you can redistribute it and/or modify it      *
// under the terms of the GNU Lesser General Public License as published     *
// by the Free Software Foundation; either version 2 of the License, or      *
// (at your option) any later version.                                       *
//                                                                           *
// This file is distributed in the hope it will be useful, but WITHOUT       *
// ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or     *
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public       *
// License for more details.                                                 *
//                                                                           *
// You should have received a copy of the GNU General Public License along   *
// with this program; if not, write to the Free Software Foundation          *
// Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA            *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#include "utilities/F_DisplayException.h"
#include "time/C_Timer.h"
#include "generic_arraies/TC_UniqueArray.h"
#include "command_line_interface/F_Analyze_CLI_Options.h"
#include "command_line_interface/mainForLIBPM.h"
#include "command_line_interface/C_builtin_CLI_Options.h"
#include "command_line_interface/C_CLI_OptionGroup.h"
#include "oa_cli_options.h"

//---------------------------------------------------------------------------*

#include "oa_main.h"

//---------------------------------------------------------------------------*

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

class C_options_for_oa_main : public C_CLI_OptionGroup {
//--- Constructor
  public : C_options_for_oa_main (const bool inAcceptsDebugOption) ;

//--- Included options
  private : C_builtin_CLI_Options mBuiltinOptions ;
  private : oa_cli_options mOptions_oa_cli_options; 
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                    C_options_for_oa_main  CONSTRUCTOR                     *
//                                                                           *
//---------------------------------------------------------------------------*

C_options_for_oa_main::
C_options_for_oa_main (const bool inAcceptsDebugOption)
:mBuiltinOptions (inAcceptsDebugOption) {
  add (& mBuiltinOptions) ;
  add (& mOptions_oa_cli_options) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                          C O N S T R U C T O R                            *
//                                                                           *
//---------------------------------------------------------------------------*


oa_main::
oa_main (const C_galgas_io_parameters & inIOparameters) :
mScanner_ (& mTerminalIO), mTerminalIO (inIOparameters) {
  mSourceFileExtension_ = "nprt" ;
}

//---------------------------------------------------------------------------*

void oa_main
::doCompilation (const C_String & inSourceFileName_,
                 sint16 & returnCode) {
  C_Timer timer ;
  try{
    if (mTerminalIO.versionModeOn ()) {
      ::printf ("Reading '%s'\n", inSourceFileName_.cString ()) ;
    }
    mScanner_.resetAndLoadSourceFromFile (inSourceFileName_) ;
    beforeParsing_ () ;
    oa_grammar grammar_ ;
    grammar_.startParsing_ (mScanner_) ;
    if (mTerminalIO.getErrorTotalCount () == 0) {
      afterParsing_ () ;
    }
    ::printf ("Analysis of '%s' completed. ", mScanner_.sourceFileName ().lastPathComponent ().cString ()) ;
    switch (mTerminalIO.getErrorTotalCount ()) {
    case 0 :
      ::printf ("No error, ") ;
      break ;
    case 1 :
      ::printf ("1 error, ") ;
      returnCode = 1 ; // Error code
      break ;
    default :
      ::printf ("%ld errors, ", mTerminalIO.getErrorTotalCount ()) ;
      returnCode = 1 ; // Error code
      break ;
    }
    switch (mTerminalIO.getWarningsCount ()) {
    case 0 :
      ::printf ("no warning") ;
      break ;
    case 1 :
      ::printf ("1 warning") ;
      break ;
    default :
      ::printf ("%ld warnings", mTerminalIO.getWarningsCount ()) ;
      break ;
    }
    timer.stopTimer () ;
      co << " (" << timer << ").\n" ;
  }catch (const C_TextReadException & inFileReadError) {
    ::printf ("Error : %s\n", inFileReadError.what ()) ; // Error when reading source file
    returnCode = 1 ;
  }
}

//---------------------------------------------------------------------------*

int mainForLIBPM  (const int argc, const char * argv []) {
  sint16 returnCode = 0 ; // No error
//--- Input/output parameters
  C_options_for_oa_main options (false) ;
  C_galgas_io_parameters IOparameters  (& options) ;
  IOparameters.mCompilerVersion = "version 1.1.9" ;
  IOparameters.mMaxErrorsCount = 100 ;
  IOparameters.mMaxWarningsCount = 100 ;
  TC_UniqueArray <C_String> sourceFilesArray ;
  #ifdef TARGET_API_MAC_CARBON
    printf ("%s\n", IOparameters.mCompilerVersion.cString ()) ;
  #endif
  #ifdef COMPILE_FOR_WIN32
    printf ("%s\n", IOparameters.mCompilerVersion.cString ()) ;
  #endif
  F_Analyze_CLI_Options (argc, argv,
                               "version 1.1.9",
                               options,
                               sourceFilesArray,
                               "nprt",
                               IOparameters.mCocoaOutput) ;
  oa_main compiler (IOparameters) ;
  try{
    for (sint32 i=0 ; (i<sourceFilesArray.count ()) && (returnCode == 0) ; i++) {
      compiler.doCompilation (sourceFilesArray (i COMMA_HERE), returnCode) ;
    }
  }catch (const M_STD_NAMESPACE exception & e) {
    F_default_display_exception (e) ;
    returnCode = 1 ; // Error code
  }catch (...) {
    F_default_display_unknown_exception () ;
    returnCode = 2 ; // Error code
  }
  return returnCode ;
}

//---------------------------------------------------------------------------*

