//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'oa_grammar.cpp'                            *
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

#include "oa_grammar.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//              L L ( 1 )    P R O D U C T I O N    R U L E S                *
//                                                                           *
//---------------------------------------------------------------------------*

#define TERMINAL(t)     ((t)+1)
#define NONTERMINAL(nt) ((-nt)-1)
#define END_PRODUCTION  (0)

static const sint16 gProductions [] = {
// At index 0 : <axiome>, in file 'oa_parser', line 175
  TERMINAL (oa_scanner::oa_scanner_1_system) // $system$
, NONTERMINAL (1) // <select_repeat_oa_parser_0>
, TERMINAL (oa_scanner::oa_scanner_1_end) // $end$
, END_PRODUCTION
//---- Added productions from 'select' and 'repeat' instructions
// At index 4 : <select_repeat_oa_parser_0>, in file 'oa_parser', line 183
, END_PRODUCTION
// At index 5 : <select_repeat_oa_parser_0>, in file 'oa_parser', line 183
, TERMINAL (oa_scanner::oa_scanner_1_processor) // $processor$
, TERMINAL (oa_scanner::oa_scanner_1_identifier) // $identifier$
, NONTERMINAL (2) // <select_oa_parser_1>
, TERMINAL (oa_scanner::oa_scanner_1__3B) // $;$
, NONTERMINAL (1) // <select_repeat_oa_parser_0>
, END_PRODUCTION
// At index 11 : <select_repeat_oa_parser_0>, in file 'oa_parser', line 183
, NONTERMINAL (3) // <select_oa_parser_2>
, TERMINAL (oa_scanner::oa_scanner_1_network) // $network$
, TERMINAL (oa_scanner::oa_scanner_1_identifier) // $identifier$
, NONTERMINAL (4) // <select_oa_parser_3>
, TERMINAL (oa_scanner::oa_scanner_1__3B) // $;$
, NONTERMINAL (1) // <select_repeat_oa_parser_0>
, END_PRODUCTION
// At index 18 : <select_repeat_oa_parser_0>, in file 'oa_parser', line 183
, TERMINAL (oa_scanner::oa_scanner_1_task) // $task$
, TERMINAL (oa_scanner::oa_scanner_1_identifier) // $identifier$
, TERMINAL (oa_scanner::oa_scanner_1_priority) // $priority$
, TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) // $literal_integer$
, TERMINAL (oa_scanner::oa_scanner_1_duration) // $duration$
, TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) // $literal_integer$
, TERMINAL (oa_scanner::oa_scanner_1__2E_2E) // $..$
, TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) // $literal_integer$
, NONTERMINAL (5) // <select_oa_parser_4>
, NONTERMINAL (6) // <select_oa_parser_5>
, NONTERMINAL (7) // <select_oa_parser_6>
, TERMINAL (oa_scanner::oa_scanner_1__3B) // $;$
, NONTERMINAL (1) // <select_repeat_oa_parser_0>
, END_PRODUCTION
// At index 32 : <select_repeat_oa_parser_0>, in file 'oa_parser', line 183
, NONTERMINAL (11) // <select_oa_parser_10>
, TERMINAL (oa_scanner::oa_scanner_1_identifier) // $identifier$
, TERMINAL (oa_scanner::oa_scanner_1_network) // $network$
, TERMINAL (oa_scanner::oa_scanner_1_identifier) // $identifier$
, TERMINAL (oa_scanner::oa_scanner_1_length) // $length$
, TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) // $literal_integer$
, TERMINAL (oa_scanner::oa_scanner_1_priority) // $priority$
, TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) // $literal_integer$
, NONTERMINAL (12) // <select_oa_parser_11>
, NONTERMINAL (13) // <select_oa_parser_12>
, NONTERMINAL (14) // <select_oa_parser_13>
, TERMINAL (oa_scanner::oa_scanner_1__3B) // $;$
, NONTERMINAL (1) // <select_repeat_oa_parser_0>
, END_PRODUCTION
// At index 46 : <select_oa_parser_1>, in file 'oa_parser', line 189
, END_PRODUCTION
// At index 47 : <select_oa_parser_1>, in file 'oa_parser', line 189
, TERMINAL (oa_scanner::oa_scanner_1_step) // $step$
, TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) // $literal_integer$
, END_PRODUCTION
// At index 50 : <select_oa_parser_2>, in file 'oa_parser', line 202
, TERMINAL (oa_scanner::oa_scanner_1_can) // $can$
, END_PRODUCTION
// At index 52 : <select_oa_parser_2>, in file 'oa_parser', line 202
, TERMINAL (oa_scanner::oa_scanner_1_van) // $van$
, END_PRODUCTION
// At index 54 : <select_oa_parser_3>, in file 'oa_parser', line 213
, END_PRODUCTION
// At index 55 : <select_oa_parser_3>, in file 'oa_parser', line 213
, TERMINAL (oa_scanner::oa_scanner_1_factor) // $factor$
, TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) // $literal_integer$
, END_PRODUCTION
// At index 58 : <select_oa_parser_4>, in file 'oa_parser', line 238
, TERMINAL (oa_scanner::oa_scanner_1_offset) // $offset$
, TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) // $literal_integer$
, END_PRODUCTION
// At index 61 : <select_oa_parser_4>, in file 'oa_parser', line 238
, END_PRODUCTION
// At index 62 : <select_oa_parser_5>, in file 'oa_parser', line 245
, TERMINAL (oa_scanner::oa_scanner_1_deadline) // $deadline$
, TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) // $literal_integer$
, END_PRODUCTION
// At index 65 : <select_oa_parser_5>, in file 'oa_parser', line 245
, END_PRODUCTION
// At index 66 : <select_oa_parser_6>, in file 'oa_parser', line 254
, TERMINAL (oa_scanner::oa_scanner_1_period) // $period$
, TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) // $literal_integer$
, TERMINAL (oa_scanner::oa_scanner_1_processor) // $processor$
, TERMINAL (oa_scanner::oa_scanner_1_identifier) // $identifier$
, END_PRODUCTION
// At index 71 : <select_oa_parser_6>, in file 'oa_parser', line 254
, TERMINAL (oa_scanner::oa_scanner_1_on) // $on$
, NONTERMINAL (8) // <select_oa_parser_7>
, END_PRODUCTION
// At index 74 : <select_oa_parser_7>, in file 'oa_parser', line 264
, TERMINAL (oa_scanner::oa_scanner_1_task) // $task$
, TERMINAL (oa_scanner::oa_scanner_1_identifier) // $identifier$
, NONTERMINAL (9) // <select_oa_parser_8>
, END_PRODUCTION
// At index 78 : <select_oa_parser_7>, in file 'oa_parser', line 264
, TERMINAL (oa_scanner::oa_scanner_1_message) // $message$
, TERMINAL (oa_scanner::oa_scanner_1_identifier) // $identifier$
, TERMINAL (oa_scanner::oa_scanner_1_processor) // $processor$
, TERMINAL (oa_scanner::oa_scanner_1_identifier) // $identifier$
, NONTERMINAL (10) // <select_oa_parser_9>
, END_PRODUCTION
// At index 84 : <select_oa_parser_8>, in file 'oa_parser', line 269
, END_PRODUCTION
// At index 85 : <select_oa_parser_8>, in file 'oa_parser', line 269
, TERMINAL (oa_scanner::oa_scanner_1_every) // $every$
, TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) // $literal_integer$
, END_PRODUCTION
// At index 88 : <select_oa_parser_9>, in file 'oa_parser', line 288
, END_PRODUCTION
// At index 89 : <select_oa_parser_9>, in file 'oa_parser', line 288
, TERMINAL (oa_scanner::oa_scanner_1_every) // $every$
, TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) // $literal_integer$
, END_PRODUCTION
// At index 92 : <select_oa_parser_10>, in file 'oa_parser', line 309
, TERMINAL (oa_scanner::oa_scanner_1_standard) // $standard$
, TERMINAL (oa_scanner::oa_scanner_1_message) // $message$
, END_PRODUCTION
// At index 95 : <select_oa_parser_10>, in file 'oa_parser', line 309
, TERMINAL (oa_scanner::oa_scanner_1_extended) // $extended$
, TERMINAL (oa_scanner::oa_scanner_1_message) // $message$
, END_PRODUCTION
// At index 98 : <select_oa_parser_10>, in file 'oa_parser', line 309
, TERMINAL (oa_scanner::oa_scanner_1_message) // $message$
, END_PRODUCTION
// At index 100 : <select_oa_parser_11>, in file 'oa_parser', line 346
, TERMINAL (oa_scanner::oa_scanner_1_offset) // $offset$
, TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) // $literal_integer$
, END_PRODUCTION
// At index 103 : <select_oa_parser_11>, in file 'oa_parser', line 346
, END_PRODUCTION
// At index 104 : <select_oa_parser_12>, in file 'oa_parser', line 353
, TERMINAL (oa_scanner::oa_scanner_1_deadline) // $deadline$
, TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) // $literal_integer$
, END_PRODUCTION
// At index 107 : <select_oa_parser_12>, in file 'oa_parser', line 353
, END_PRODUCTION
// At index 108 : <select_oa_parser_13>, in file 'oa_parser', line 361
, TERMINAL (oa_scanner::oa_scanner_1_period) // $period$
, TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) // $literal_integer$
, END_PRODUCTION
// At index 111 : <select_oa_parser_13>, in file 'oa_parser', line 361
, TERMINAL (oa_scanner::oa_scanner_1_on) // $on$
, NONTERMINAL (15) // <select_oa_parser_14>
, END_PRODUCTION
// At index 114 : <select_oa_parser_14>, in file 'oa_parser', line 367
, TERMINAL (oa_scanner::oa_scanner_1_message) // $message$
, TERMINAL (oa_scanner::oa_scanner_1_identifier) // $identifier$
, END_PRODUCTION
// At index 117 : <select_oa_parser_14>, in file 'oa_parser', line 367
, TERMINAL (oa_scanner::oa_scanner_1_task) // $task$
, TERMINAL (oa_scanner::oa_scanner_1_identifier) // $identifier$
, END_PRODUCTION
// At index 120 : <>, in file '', line 0
, NONTERMINAL (0) // <axiome>
, END_PRODUCTION
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//            L L ( 1 )    P R O D U C T I O N    I N D E X E S              *
//                                                                           *
//---------------------------------------------------------------------------*

static const sint16 gProductionIndexes [36] = {
0, // index 0 : <axiome>, in file 'oa_parser', line 175
4, // index 1 : <select_repeat_oa_parser_0>, in file 'oa_parser', line 183
5, // index 2 : <select_repeat_oa_parser_0>, in file 'oa_parser', line 183
11, // index 3 : <select_repeat_oa_parser_0>, in file 'oa_parser', line 183
18, // index 4 : <select_repeat_oa_parser_0>, in file 'oa_parser', line 183
32, // index 5 : <select_repeat_oa_parser_0>, in file 'oa_parser', line 183
46, // index 6 : <select_oa_parser_1>, in file 'oa_parser', line 189
47, // index 7 : <select_oa_parser_1>, in file 'oa_parser', line 189
50, // index 8 : <select_oa_parser_2>, in file 'oa_parser', line 202
52, // index 9 : <select_oa_parser_2>, in file 'oa_parser', line 202
54, // index 10 : <select_oa_parser_3>, in file 'oa_parser', line 213
55, // index 11 : <select_oa_parser_3>, in file 'oa_parser', line 213
58, // index 12 : <select_oa_parser_4>, in file 'oa_parser', line 238
61, // index 13 : <select_oa_parser_4>, in file 'oa_parser', line 238
62, // index 14 : <select_oa_parser_5>, in file 'oa_parser', line 245
65, // index 15 : <select_oa_parser_5>, in file 'oa_parser', line 245
66, // index 16 : <select_oa_parser_6>, in file 'oa_parser', line 254
71, // index 17 : <select_oa_parser_6>, in file 'oa_parser', line 254
74, // index 18 : <select_oa_parser_7>, in file 'oa_parser', line 264
78, // index 19 : <select_oa_parser_7>, in file 'oa_parser', line 264
84, // index 20 : <select_oa_parser_8>, in file 'oa_parser', line 269
85, // index 21 : <select_oa_parser_8>, in file 'oa_parser', line 269
88, // index 22 : <select_oa_parser_9>, in file 'oa_parser', line 288
89, // index 23 : <select_oa_parser_9>, in file 'oa_parser', line 288
92, // index 24 : <select_oa_parser_10>, in file 'oa_parser', line 309
95, // index 25 : <select_oa_parser_10>, in file 'oa_parser', line 309
98, // index 26 : <select_oa_parser_10>, in file 'oa_parser', line 309
100, // index 27 : <select_oa_parser_11>, in file 'oa_parser', line 346
103, // index 28 : <select_oa_parser_11>, in file 'oa_parser', line 346
104, // index 29 : <select_oa_parser_12>, in file 'oa_parser', line 353
107, // index 30 : <select_oa_parser_12>, in file 'oa_parser', line 353
108, // index 31 : <select_oa_parser_13>, in file 'oa_parser', line 361
111, // index 32 : <select_oa_parser_13>, in file 'oa_parser', line 361
114, // index 33 : <select_oa_parser_14>, in file 'oa_parser', line 367
117, // index 34 : <select_oa_parser_14>, in file 'oa_parser', line 367
120 // index 35 : <>, in file '', line 0
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//      L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S       *
//                                                                           *
//---------------------------------------------------------------------------*

static const sint16 gFirstProductionIndexes [18] = {
0, // at 0 : <axiome>
1, // at 1 : <select_repeat_oa_parser_0>
6, // at 2 : <select_oa_parser_1>
8, // at 3 : <select_oa_parser_2>
10, // at 4 : <select_oa_parser_3>
12, // at 5 : <select_oa_parser_4>
14, // at 6 : <select_oa_parser_5>
16, // at 7 : <select_oa_parser_6>
18, // at 8 : <select_oa_parser_7>
20, // at 9 : <select_oa_parser_8>
22, // at 10 : <select_oa_parser_9>
24, // at 11 : <select_oa_parser_10>
27, // at 12 : <select_oa_parser_11>
29, // at 13 : <select_oa_parser_12>
31, // at 14 : <select_oa_parser_13>
33, // at 15 : <select_oa_parser_14>
35, // at 16 : <>
0} ;

//---------------------------------------------------------------------------*
//                                                                           *
//               L L ( 1 )    D E C I S I O N    T A B L E S                 *
//                                                                           *
//---------------------------------------------------------------------------*

static const sint16 gDecision [] = {
// At index 0 : <axiome> only one production, no choice
  -1,
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 1 : <select_repeat_oa_parser_0>
oa_scanner::oa_scanner_1_end, -1, // Choice 1
oa_scanner::oa_scanner_1_processor, -1, // Choice 2
oa_scanner::oa_scanner_1_can, oa_scanner::oa_scanner_1_van, -1, // Choice 3
oa_scanner::oa_scanner_1_task, -1, // Choice 4
oa_scanner::oa_scanner_1_standard, oa_scanner::oa_scanner_1_extended, oa_scanner::oa_scanner_1_message, -1, // Choice 5
  -1,
// At index 15 : <select_oa_parser_1>
oa_scanner::oa_scanner_1__3B, -1, // Choice 1
oa_scanner::oa_scanner_1_step, -1, // Choice 2
  -1,
// At index 20 : <select_oa_parser_2>
oa_scanner::oa_scanner_1_can, -1, // Choice 1
oa_scanner::oa_scanner_1_van, -1, // Choice 2
  -1,
// At index 25 : <select_oa_parser_3>
oa_scanner::oa_scanner_1__3B, -1, // Choice 1
oa_scanner::oa_scanner_1_factor, -1, // Choice 2
  -1,
// At index 30 : <select_oa_parser_4>
oa_scanner::oa_scanner_1_offset, -1, // Choice 1
oa_scanner::oa_scanner_1_period, oa_scanner::oa_scanner_1_on, oa_scanner::oa_scanner_1_deadline, -1, // Choice 2
  -1,
// At index 37 : <select_oa_parser_5>
oa_scanner::oa_scanner_1_deadline, -1, // Choice 1
oa_scanner::oa_scanner_1_period, oa_scanner::oa_scanner_1_on, -1, // Choice 2
  -1,
// At index 43 : <select_oa_parser_6>
oa_scanner::oa_scanner_1_period, -1, // Choice 1
oa_scanner::oa_scanner_1_on, -1, // Choice 2
  -1,
// At index 48 : <select_oa_parser_7>
oa_scanner::oa_scanner_1_task, -1, // Choice 1
oa_scanner::oa_scanner_1_message, -1, // Choice 2
  -1,
// At index 53 : <select_oa_parser_8>
oa_scanner::oa_scanner_1__3B, -1, // Choice 1
oa_scanner::oa_scanner_1_every, -1, // Choice 2
  -1,
// At index 58 : <select_oa_parser_9>
oa_scanner::oa_scanner_1__3B, -1, // Choice 1
oa_scanner::oa_scanner_1_every, -1, // Choice 2
  -1,
// At index 63 : <select_oa_parser_10>
oa_scanner::oa_scanner_1_standard, -1, // Choice 1
oa_scanner::oa_scanner_1_extended, -1, // Choice 2
oa_scanner::oa_scanner_1_message, -1, // Choice 3
  -1,
// At index 70 : <select_oa_parser_11>
oa_scanner::oa_scanner_1_offset, -1, // Choice 1
oa_scanner::oa_scanner_1_period, oa_scanner::oa_scanner_1_on, oa_scanner::oa_scanner_1_deadline, -1, // Choice 2
  -1,
// At index 77 : <select_oa_parser_12>
oa_scanner::oa_scanner_1_deadline, -1, // Choice 1
oa_scanner::oa_scanner_1_period, oa_scanner::oa_scanner_1_on, -1, // Choice 2
  -1,
// At index 83 : <select_oa_parser_13>
oa_scanner::oa_scanner_1_period, -1, // Choice 1
oa_scanner::oa_scanner_1_on, -1, // Choice 2
  -1,
// At index 88 : <select_oa_parser_14>
oa_scanner::oa_scanner_1_message, -1, // Choice 1
oa_scanner::oa_scanner_1_task, -1, // Choice 2
  -1,
// At index 93 : <> only one production, no choice
  -1,
0} ;

//---------------------------------------------------------------------------*
//                                                                           *
//       L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S        *
//                                                                           *
//---------------------------------------------------------------------------*

static const sint16 gDecisionIndexes [18] = {
0, // at 0 : <axiome>
1, // at 1 : <select_repeat_oa_parser_0>
15, // at 2 : <select_oa_parser_1>
20, // at 3 : <select_oa_parser_2>
25, // at 4 : <select_oa_parser_3>
30, // at 5 : <select_oa_parser_4>
37, // at 6 : <select_oa_parser_5>
43, // at 7 : <select_oa_parser_6>
48, // at 8 : <select_oa_parser_7>
53, // at 9 : <select_oa_parser_8>
58, // at 10 : <select_oa_parser_9>
63, // at 11 : <select_oa_parser_10>
70, // at 12 : <select_oa_parser_11>
77, // at 13 : <select_oa_parser_12>
83, // at 14 : <select_oa_parser_13>
88, // at 15 : <select_oa_parser_14>
93, // at 16 : <>
0} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                   'axiome' non terminal implementation                    *
//                                                                           *
//---------------------------------------------------------------------------*


void oa_grammar::nt_axiome_ (oa_scanner & lexique_var_) {
  pr_axiome_oa_parser_175_14_ (lexique_var_) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                   Grammar start symbol implementation                     *
//                                                                           *
//---------------------------------------------------------------------------*


void oa_grammar::startParsing_ (oa_scanner & lexique_var_) {
// classesCount : 0
  const bool ok = lexique_var_.performTopDownParsing (gProductions, gProductionIndexes,
                                gFirstProductionIndexes, gDecision, gDecisionIndexes, 120) ;
  if (ok && ! lexique_var_.parseOnlyFlagOn ()) {
    nt_axiome_ (lexique_var_) ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//      'select_repeat_oa_parser_0' added non terminal implementation        *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 oa_grammar::select_repeat_oa_parser_0 (oa_scanner & lexique_var_) {
  return lexique_var_.getNextProductionIndex () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//          'select_oa_parser_1' added non terminal implementation           *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 oa_grammar::select_oa_parser_1 (oa_scanner & lexique_var_) {
  return lexique_var_.getNextProductionIndex () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//          'select_oa_parser_2' added non terminal implementation           *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 oa_grammar::select_oa_parser_2 (oa_scanner & lexique_var_) {
  return lexique_var_.getNextProductionIndex () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//          'select_oa_parser_3' added non terminal implementation           *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 oa_grammar::select_oa_parser_3 (oa_scanner & lexique_var_) {
  return lexique_var_.getNextProductionIndex () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//          'select_oa_parser_4' added non terminal implementation           *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 oa_grammar::select_oa_parser_4 (oa_scanner & lexique_var_) {
  return lexique_var_.getNextProductionIndex () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//          'select_oa_parser_5' added non terminal implementation           *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 oa_grammar::select_oa_parser_5 (oa_scanner & lexique_var_) {
  return lexique_var_.getNextProductionIndex () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//          'select_oa_parser_6' added non terminal implementation           *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 oa_grammar::select_oa_parser_6 (oa_scanner & lexique_var_) {
  return lexique_var_.getNextProductionIndex () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//          'select_oa_parser_7' added non terminal implementation           *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 oa_grammar::select_oa_parser_7 (oa_scanner & lexique_var_) {
  return lexique_var_.getNextProductionIndex () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//          'select_oa_parser_8' added non terminal implementation           *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 oa_grammar::select_oa_parser_8 (oa_scanner & lexique_var_) {
  return lexique_var_.getNextProductionIndex () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//          'select_oa_parser_9' added non terminal implementation           *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 oa_grammar::select_oa_parser_9 (oa_scanner & lexique_var_) {
  return lexique_var_.getNextProductionIndex () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//         'select_oa_parser_10' added non terminal implementation           *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 oa_grammar::select_oa_parser_10 (oa_scanner & lexique_var_) {
  return lexique_var_.getNextProductionIndex () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//         'select_oa_parser_11' added non terminal implementation           *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 oa_grammar::select_oa_parser_11 (oa_scanner & lexique_var_) {
  return lexique_var_.getNextProductionIndex () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//         'select_oa_parser_12' added non terminal implementation           *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 oa_grammar::select_oa_parser_12 (oa_scanner & lexique_var_) {
  return lexique_var_.getNextProductionIndex () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//         'select_oa_parser_13' added non terminal implementation           *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 oa_grammar::select_oa_parser_13 (oa_scanner & lexique_var_) {
  return lexique_var_.getNextProductionIndex () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//         'select_oa_parser_14' added non terminal implementation           *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 oa_grammar::select_oa_parser_14 (oa_scanner & lexique_var_) {
  return lexique_var_.getNextProductionIndex () ;
}

//---------------------------------------------------------------------------*

