//---------------------------------------------------------------------------*
//                                                                           *
//                             File 'oa_main.h'                              *
//               Generated by version 0.14.0 (LL(1) grammar)                 *
//                     january 17th, 2005, at 13h54'54"                      *
//                                                                           *
// This program is free software; you can redistribute it and/or modify it   *
// under the terms of the GNU General Public License as published by the     *
// Free Software Foundation.                                                 *
//                                                                           *
// This program is distributed in the hope it will be useful, but WITHOUT    *
// ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or     *
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for  *
// more details.                                                             *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef INTERFACE_oa_main_DEFINED
#define INTERFACE_oa_main_DEFINED

#include "oa_grammar.h"
#include "oa_scanner.h"
#include "galgas/C_galgas_terminal_io.h"

//---------------------------------------------------------------------------*

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

class oa_main : public C_defaultUserSemanticActions {
  protected : oa_scanner mScanner_ ;
  protected : C_galgas_terminal_io mTerminalIO ;
  protected : C_string mSourceFileExtension_ ;

//--- Command line options
  protected : bool mOption_oa_cli_options_createIntermediateFiles ;
  protected : bool mOption_oa_cli_options_forceBalgorithm ;
  protected : bool mOption_oa_cli_options_useCANmaxLegth ;

//--- Constructor
  public : oa_main (const C_galgas_io_parameters & inIOparameters) ;

  public : void doCompilation (const C_string & inSourceFileName_,
                               sint16 & returnCode) ;
} ;

//---------------------------------------------------------------------------*

#endif
