//-----------------------------------------------------------------------------*
//                                                                             *
//  GALGAS prologue / epilogue handling class                                *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 2009, ..., 2010 Pierre Molinaro.                             *
//                                                                             *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                               *
//                                                                             *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes  *
//  ECN, École Centrale de Nantes (France)                                     *
//                                                                             *
//  This library is free software; you can redistribute it and/or modify it    *
//  under the terms of the GNU Lesser General Public License as published      *
//  by the Free Software Foundation; either version 2 of the License, or       *
//  (at your option) any later version.                                        *
//                                                                             *
//  This program is distributed in the hope it will be useful, but WITHOUT     *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or      *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for   *
//  more details.                                                              *
//                                                                             *
//-----------------------------------------------------------------------------*

#ifndef PM_PROLOGUE_EPILOGUE_CLASS_DEFINED
#define PM_PROLOGUE_EPILOGUE_CLASS_DEFINED

//-----------------------------------------------------------------------------*
//                                                                             *
//                 Prologue / Epilogue Action class                          *
//                                                                             *
//-----------------------------------------------------------------------------*

class C_PrologueEpilogue {
//--- Constructor
  public : C_PrologueEpilogue (void (* inPrologueAction) (void),
                               void (* inEpilogueAction) (void)) ;
//--- No copy
  private : C_PrologueEpilogue (C_PrologueEpilogue &) ;
  private : C_PrologueEpilogue & operator = (C_PrologueEpilogue &) ;
//--- Attributes
  public : const C_PrologueEpilogue * mNextObjectLink ;
  public : void (* mPrologueAction) (void) ;
  public : void (* mEpilogueAction) (void) ;
//--- Running actions
  private : static void runPrologueActions (void) ;
  private : static void runEpilogueActions (void) ;
//--- Friend routine (runs runPrologueActions, runEpilogueActions)
  friend int main (int argc, const char * argv []) ;
} ;

//-----------------------------------------------------------------------------*

#endif
