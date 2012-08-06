//---------------------------------------------------------------------------*
//                                                                           *
//  Declaration of 'mainForLIBPM' routine prototype.                         *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2002, ..., 2011 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//                                                                           *
//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*
//  ECN, Ecole Centrale de Nantes (France)                                   *
//                                                                           *
//  This library is free software; you can redistribute it and/or modify it  *
//  under the terms of the GNU Lesser General Public License as published    *
//  by the Free Software Foundation; either version 2 of the License, or     *
//  (at your option) any later version.                                      *
//                                                                           *
//  This program is distributed in the hope it will be useful, but WITHOUT   *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or    *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for *
//  more details.                                                            *
//                                                                           *
//---------------------------------------------------------------------------*

#ifndef ROUTINE_LIBPM_MAIN_DECLARED
#define ROUTINE_LIBPM_MAIN_DECLARED

//---------------------------------------------------------------------------*

#include "collections/TC_UniqueArray.h"

//---------------------------------------------------------------------------*

int mainForLIBPM (const TC_UniqueArray <C_String> & inSourceArray) ;

//---------------------------------------------------------------------------*

void print_tool_help_message (void) ;

//---------------------------------------------------------------------------*

extern const char * kSourceFileExtensions [] ;
extern const char * kSourceFileHelpMessages [] ;
extern const char * kVersionString ;

//---------------------------------------------------------------------------*

const char * mainFirstArgument (void) ;

//---------------------------------------------------------------------------*

#endif