//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'oa_grammar.cpp'                            *
//         Generated by version GALGAS_BETA_VERSION (LL(1) grammar)          *
//                      march 24th, 2008, at 16h8'50"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if LIBPM_VERSION != THE_LIBPM_VERSION
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include "utilities/MF_MemoryControl.h"

//---------------------------------------------------------------------------*

#include "oa_grammar.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "oa_grammar.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif

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
// At index 0 : <axiome>, in file 'oa_parser.ggs', line 13
  TERMINAL (oa_scanner::oa_scanner_1_system) // $system$
, NONTERMINAL (1) // <select_repeat_oa_parser_0>
, TERMINAL (oa_scanner::oa_scanner_1_end) // $end$
, END_PRODUCTION
//---- Added productions from 'select' and 'repeat' instructions
// At index 4 : <select_repeat_oa_parser_0>, in file 'oa_parser.ggs', line 20
, END_PRODUCTION
// At index 5 : <select_repeat_oa_parser_0>, in file 'oa_parser.ggs', line 20
, TERMINAL (oa_scanner::oa_scanner_1_processor) // $processor$
, TERMINAL (oa_scanner::oa_scanner_1_identifier) // $identifier$
, NONTERMINAL (2) // <select_oa_parser_1>
, TERMINAL (oa_scanner::oa_scanner_1__3B) // $;$
, NONTERMINAL (1) // <select_repeat_oa_parser_0>
, END_PRODUCTION
// At index 11 : <select_repeat_oa_parser_0>, in file 'oa_parser.ggs', line 20
, NONTERMINAL (3) // <select_oa_parser_2>
, TERMINAL (oa_scanner::oa_scanner_1_network) // $network$
, TERMINAL (oa_scanner::oa_scanner_1_identifier) // $identifier$
, NONTERMINAL (4) // <select_oa_parser_3>
, TERMINAL (oa_scanner::oa_scanner_1__3B) // $;$
, NONTERMINAL (1) // <select_repeat_oa_parser_0>
, END_PRODUCTION
// At index 18 : <select_repeat_oa_parser_0>, in file 'oa_parser.ggs', line 20
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
// At index 32 : <select_repeat_oa_parser_0>, in file 'oa_parser.ggs', line 20
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
// At index 46 : <select_oa_parser_1>, in file 'oa_parser.ggs', line 26
, END_PRODUCTION
// At index 47 : <select_oa_parser_1>, in file 'oa_parser.ggs', line 26
, TERMINAL (oa_scanner::oa_scanner_1_scalingfactor) // $scalingfactor$
, TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) // $literal_integer$
, END_PRODUCTION
// At index 50 : <select_oa_parser_2>, in file 'oa_parser.ggs', line 39
, TERMINAL (oa_scanner::oa_scanner_1_can) // $can$
, END_PRODUCTION
// At index 52 : <select_oa_parser_2>, in file 'oa_parser.ggs', line 39
, TERMINAL (oa_scanner::oa_scanner_1_van) // $van$
, END_PRODUCTION
// At index 54 : <select_oa_parser_3>, in file 'oa_parser.ggs', line 50
, END_PRODUCTION
// At index 55 : <select_oa_parser_3>, in file 'oa_parser.ggs', line 50
, TERMINAL (oa_scanner::oa_scanner_1_scalingfactor) // $scalingfactor$
, TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) // $literal_integer$
, END_PRODUCTION
// At index 58 : <select_oa_parser_4>, in file 'oa_parser.ggs', line 76
, TERMINAL (oa_scanner::oa_scanner_1_offset) // $offset$
, TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) // $literal_integer$
, END_PRODUCTION
// At index 61 : <select_oa_parser_4>, in file 'oa_parser.ggs', line 76
, END_PRODUCTION
// At index 62 : <select_oa_parser_5>, in file 'oa_parser.ggs', line 85
, TERMINAL (oa_scanner::oa_scanner_1_deadline) // $deadline$
, TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) // $literal_integer$
, END_PRODUCTION
// At index 65 : <select_oa_parser_5>, in file 'oa_parser.ggs', line 85
, END_PRODUCTION
// At index 66 : <select_oa_parser_6>, in file 'oa_parser.ggs', line 94
, TERMINAL (oa_scanner::oa_scanner_1_period) // $period$
, TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) // $literal_integer$
, TERMINAL (oa_scanner::oa_scanner_1_processor) // $processor$
, TERMINAL (oa_scanner::oa_scanner_1_identifier) // $identifier$
, END_PRODUCTION
// At index 71 : <select_oa_parser_6>, in file 'oa_parser.ggs', line 94
, TERMINAL (oa_scanner::oa_scanner_1_on) // $on$
, NONTERMINAL (8) // <select_oa_parser_7>
, END_PRODUCTION
// At index 74 : <select_oa_parser_7>, in file 'oa_parser.ggs', line 107
, TERMINAL (oa_scanner::oa_scanner_1_task) // $task$
, TERMINAL (oa_scanner::oa_scanner_1_identifier) // $identifier$
, NONTERMINAL (9) // <select_oa_parser_8>
, END_PRODUCTION
// At index 78 : <select_oa_parser_7>, in file 'oa_parser.ggs', line 107
, TERMINAL (oa_scanner::oa_scanner_1_message) // $message$
, TERMINAL (oa_scanner::oa_scanner_1_identifier) // $identifier$
, TERMINAL (oa_scanner::oa_scanner_1_processor) // $processor$
, TERMINAL (oa_scanner::oa_scanner_1_identifier) // $identifier$
, NONTERMINAL (10) // <select_oa_parser_9>
, END_PRODUCTION
// At index 84 : <select_oa_parser_8>, in file 'oa_parser.ggs', line 112
, END_PRODUCTION
// At index 85 : <select_oa_parser_8>, in file 'oa_parser.ggs', line 112
, TERMINAL (oa_scanner::oa_scanner_1_every) // $every$
, TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) // $literal_integer$
, END_PRODUCTION
// At index 88 : <select_oa_parser_9>, in file 'oa_parser.ggs', line 131
, END_PRODUCTION
// At index 89 : <select_oa_parser_9>, in file 'oa_parser.ggs', line 131
, TERMINAL (oa_scanner::oa_scanner_1_every) // $every$
, TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) // $literal_integer$
, END_PRODUCTION
// At index 92 : <select_oa_parser_10>, in file 'oa_parser.ggs', line 152
, TERMINAL (oa_scanner::oa_scanner_1_standard) // $standard$
, TERMINAL (oa_scanner::oa_scanner_1_message) // $message$
, END_PRODUCTION
// At index 95 : <select_oa_parser_10>, in file 'oa_parser.ggs', line 152
, TERMINAL (oa_scanner::oa_scanner_1_extended) // $extended$
, TERMINAL (oa_scanner::oa_scanner_1_message) // $message$
, END_PRODUCTION
// At index 98 : <select_oa_parser_10>, in file 'oa_parser.ggs', line 152
, TERMINAL (oa_scanner::oa_scanner_1_message) // $message$
, END_PRODUCTION
// At index 100 : <select_oa_parser_11>, in file 'oa_parser.ggs', line 190
, TERMINAL (oa_scanner::oa_scanner_1_offset) // $offset$
, TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) // $literal_integer$
, END_PRODUCTION
// At index 103 : <select_oa_parser_11>, in file 'oa_parser.ggs', line 190
, END_PRODUCTION
// At index 104 : <select_oa_parser_12>, in file 'oa_parser.ggs', line 199
, TERMINAL (oa_scanner::oa_scanner_1_deadline) // $deadline$
, TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) // $literal_integer$
, END_PRODUCTION
// At index 107 : <select_oa_parser_12>, in file 'oa_parser.ggs', line 199
, END_PRODUCTION
// At index 108 : <select_oa_parser_13>, in file 'oa_parser.ggs', line 207
, TERMINAL (oa_scanner::oa_scanner_1_period) // $period$
, TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) // $literal_integer$
, END_PRODUCTION
// At index 111 : <select_oa_parser_13>, in file 'oa_parser.ggs', line 207
, TERMINAL (oa_scanner::oa_scanner_1_on) // $on$
, NONTERMINAL (15) // <select_oa_parser_14>
, END_PRODUCTION
// At index 114 : <select_oa_parser_14>, in file 'oa_parser.ggs', line 216
, TERMINAL (oa_scanner::oa_scanner_1_message) // $message$
, TERMINAL (oa_scanner::oa_scanner_1_identifier) // $identifier$
, END_PRODUCTION
// At index 117 : <select_oa_parser_14>, in file 'oa_parser.ggs', line 216
, TERMINAL (oa_scanner::oa_scanner_1_task) // $task$
, TERMINAL (oa_scanner::oa_scanner_1_identifier) // $identifier$
, END_PRODUCTION
// At index 120 : <>, in file '.ggs', line 0
, NONTERMINAL (0) // <axiome>
, END_PRODUCTION
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                     P R O D U C T I O N    N A M E S                      *
//                                                                           *
//---------------------------------------------------------------------------*

static const char * gProductionNames [36] = {
 "<axiome>, in file 'oa_parser.ggs', line 13", // at index 0
 "<select_repeat_oa_parser_0>, in file 'oa_parser.ggs', line 20", // at index 1
 "<select_repeat_oa_parser_0>, in file 'oa_parser.ggs', line 20", // at index 2
 "<select_repeat_oa_parser_0>, in file 'oa_parser.ggs', line 20", // at index 3
 "<select_repeat_oa_parser_0>, in file 'oa_parser.ggs', line 20", // at index 4
 "<select_repeat_oa_parser_0>, in file 'oa_parser.ggs', line 20", // at index 5
 "<select_oa_parser_1>, in file 'oa_parser.ggs', line 26", // at index 6
 "<select_oa_parser_1>, in file 'oa_parser.ggs', line 26", // at index 7
 "<select_oa_parser_2>, in file 'oa_parser.ggs', line 39", // at index 8
 "<select_oa_parser_2>, in file 'oa_parser.ggs', line 39", // at index 9
 "<select_oa_parser_3>, in file 'oa_parser.ggs', line 50", // at index 10
 "<select_oa_parser_3>, in file 'oa_parser.ggs', line 50", // at index 11
 "<select_oa_parser_4>, in file 'oa_parser.ggs', line 76", // at index 12
 "<select_oa_parser_4>, in file 'oa_parser.ggs', line 76", // at index 13
 "<select_oa_parser_5>, in file 'oa_parser.ggs', line 85", // at index 14
 "<select_oa_parser_5>, in file 'oa_parser.ggs', line 85", // at index 15
 "<select_oa_parser_6>, in file 'oa_parser.ggs', line 94", // at index 16
 "<select_oa_parser_6>, in file 'oa_parser.ggs', line 94", // at index 17
 "<select_oa_parser_7>, in file 'oa_parser.ggs', line 107", // at index 18
 "<select_oa_parser_7>, in file 'oa_parser.ggs', line 107", // at index 19
 "<select_oa_parser_8>, in file 'oa_parser.ggs', line 112", // at index 20
 "<select_oa_parser_8>, in file 'oa_parser.ggs', line 112", // at index 21
 "<select_oa_parser_9>, in file 'oa_parser.ggs', line 131", // at index 22
 "<select_oa_parser_9>, in file 'oa_parser.ggs', line 131", // at index 23
 "<select_oa_parser_10>, in file 'oa_parser.ggs', line 152", // at index 24
 "<select_oa_parser_10>, in file 'oa_parser.ggs', line 152", // at index 25
 "<select_oa_parser_10>, in file 'oa_parser.ggs', line 152", // at index 26
 "<select_oa_parser_11>, in file 'oa_parser.ggs', line 190", // at index 27
 "<select_oa_parser_11>, in file 'oa_parser.ggs', line 190", // at index 28
 "<select_oa_parser_12>, in file 'oa_parser.ggs', line 199", // at index 29
 "<select_oa_parser_12>, in file 'oa_parser.ggs', line 199", // at index 30
 "<select_oa_parser_13>, in file 'oa_parser.ggs', line 207", // at index 31
 "<select_oa_parser_13>, in file 'oa_parser.ggs', line 207", // at index 32
 "<select_oa_parser_14>, in file 'oa_parser.ggs', line 216", // at index 33
 "<select_oa_parser_14>, in file 'oa_parser.ggs', line 216", // at index 34
 "<>, in file '.ggs', line 0" // at index 35
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//            L L ( 1 )    P R O D U C T I O N    I N D E X E S              *
//                                                                           *
//---------------------------------------------------------------------------*

static const sint16 gProductionIndexes [36] = {
0, // index 0 : <axiome>, in file 'oa_parser.ggs', line 13
4, // index 1 : <select_repeat_oa_parser_0>, in file 'oa_parser.ggs', line 20
5, // index 2 : <select_repeat_oa_parser_0>, in file 'oa_parser.ggs', line 20
11, // index 3 : <select_repeat_oa_parser_0>, in file 'oa_parser.ggs', line 20
18, // index 4 : <select_repeat_oa_parser_0>, in file 'oa_parser.ggs', line 20
32, // index 5 : <select_repeat_oa_parser_0>, in file 'oa_parser.ggs', line 20
46, // index 6 : <select_oa_parser_1>, in file 'oa_parser.ggs', line 26
47, // index 7 : <select_oa_parser_1>, in file 'oa_parser.ggs', line 26
50, // index 8 : <select_oa_parser_2>, in file 'oa_parser.ggs', line 39
52, // index 9 : <select_oa_parser_2>, in file 'oa_parser.ggs', line 39
54, // index 10 : <select_oa_parser_3>, in file 'oa_parser.ggs', line 50
55, // index 11 : <select_oa_parser_3>, in file 'oa_parser.ggs', line 50
58, // index 12 : <select_oa_parser_4>, in file 'oa_parser.ggs', line 76
61, // index 13 : <select_oa_parser_4>, in file 'oa_parser.ggs', line 76
62, // index 14 : <select_oa_parser_5>, in file 'oa_parser.ggs', line 85
65, // index 15 : <select_oa_parser_5>, in file 'oa_parser.ggs', line 85
66, // index 16 : <select_oa_parser_6>, in file 'oa_parser.ggs', line 94
71, // index 17 : <select_oa_parser_6>, in file 'oa_parser.ggs', line 94
74, // index 18 : <select_oa_parser_7>, in file 'oa_parser.ggs', line 107
78, // index 19 : <select_oa_parser_7>, in file 'oa_parser.ggs', line 107
84, // index 20 : <select_oa_parser_8>, in file 'oa_parser.ggs', line 112
85, // index 21 : <select_oa_parser_8>, in file 'oa_parser.ggs', line 112
88, // index 22 : <select_oa_parser_9>, in file 'oa_parser.ggs', line 131
89, // index 23 : <select_oa_parser_9>, in file 'oa_parser.ggs', line 131
92, // index 24 : <select_oa_parser_10>, in file 'oa_parser.ggs', line 152
95, // index 25 : <select_oa_parser_10>, in file 'oa_parser.ggs', line 152
98, // index 26 : <select_oa_parser_10>, in file 'oa_parser.ggs', line 152
100, // index 27 : <select_oa_parser_11>, in file 'oa_parser.ggs', line 190
103, // index 28 : <select_oa_parser_11>, in file 'oa_parser.ggs', line 190
104, // index 29 : <select_oa_parser_12>, in file 'oa_parser.ggs', line 199
107, // index 30 : <select_oa_parser_12>, in file 'oa_parser.ggs', line 199
108, // index 31 : <select_oa_parser_13>, in file 'oa_parser.ggs', line 207
111, // index 32 : <select_oa_parser_13>, in file 'oa_parser.ggs', line 207
114, // index 33 : <select_oa_parser_14>, in file 'oa_parser.ggs', line 216
117, // index 34 : <select_oa_parser_14>, in file 'oa_parser.ggs', line 216
120 // index 35 : <>, in file '.ggs', line 0
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
oa_scanner::oa_scanner_1_scalingfactor, -1, // Choice 2
  -1,
// At index 20 : <select_oa_parser_2>
oa_scanner::oa_scanner_1_can, -1, // Choice 1
oa_scanner::oa_scanner_1_van, -1, // Choice 2
  -1,
// At index 25 : <select_oa_parser_3>
oa_scanner::oa_scanner_1__3B, -1, // Choice 1
oa_scanner::oa_scanner_1_scalingfactor, -1, // Choice 2
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

void oa_grammar::
nt_axiome_ (oa_scanner & _inLexique) {
pr_axiome_oa_parser_13_4_ (_inLexique) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                   Grammar start symbol implementation                     *
//                                                                           *
//---------------------------------------------------------------------------*

void oa_grammar::_performSourceFileParsing_ (C_Compiler & _inCompiler,
                                GGS_string * _inSentStringPtr,
                                const GGS_lstring _inFileName
                                COMMA_LOCATION_ARGS) {
  const C_String sourceFileName = _inFileName.string ().isAbsolutePath ()
    ? _inFileName.string ()
    : _inCompiler.sourceFileName ().stringByDeletingLastPathComponent ().stringByAppendingPathComponent (_inFileName.string ()) ;
  if (sourceFileName.fileExists ()) {
    oa_scanner * scanner_ = NULL ;
    macroMyNew (scanner_, oa_scanner (_inCompiler.ioParametersPtr (), sourceFileName COMMA_HERE)) ;
    if (scanner_->sourceText () != NULL) {
      scanner_->mPerformGeneration = _inCompiler.mPerformGeneration ;
// classCount : 0
      const bool ok = scanner_->performTopDownParsing (gProductions, gProductionNames, gProductionIndexes,
                                                       gFirstProductionIndexes, gDecision, gDecisionIndexes, 120) ;
      if (ok && ! scanner_->mParseOnlyFlag) {
        oa_grammar _grammar ;
        _grammar.nt_axiome_ (*scanner_) ;
        if (_inSentStringPtr != NULL) {
          _inSentStringPtr->_dotAssign_operation (scanner_->sentString ()) ;
        }
      }
    }else{
      C_String message ;
      message << "the '" << sourceFileName << "' file exits, but cannot be read" ;
      _inFileName.signalSemanticError (_inCompiler, message COMMA_THERE) ;
    }
    macroDetachPointer (scanner_, oa_scanner) ;
  }else{
    C_String message ;
    message << "the '" << sourceFileName << "' file does not exist" ;
    _inFileName.signalSemanticError (_inCompiler, message COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------*

void oa_grammar::_performSourceStringParsing_ (C_Compiler & _inCompiler,
                                GGS_string * _inSentStringPtr,
                                const GGS_string _inSourceString
                                COMMA_UNUSED_LOCATION_ARGS) {
  oa_scanner * scanner_ = NULL ;
  macroMyNew (scanner_, oa_scanner (_inCompiler.ioParametersPtr (), _inSourceString, "Error when parsing dynamic string" COMMA_HERE)) ;
  scanner_->mPerformGeneration = _inCompiler.mPerformGeneration ;
// classCount : 0
  const bool ok = scanner_->performTopDownParsing (gProductions, gProductionNames, gProductionIndexes,
                                                   gFirstProductionIndexes, gDecision, gDecisionIndexes, 120) ;
  if (ok && ! scanner_->mParseOnlyFlag) {
    oa_grammar _grammar ;
    _grammar.nt_axiome_ (*scanner_) ;
    if (_inSentStringPtr != NULL) {
      _inSentStringPtr->_dotAssign_operation (scanner_->sentString ()) ;
    }
  }
  macroDetachPointer (scanner_, oa_scanner) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//      'select_repeat_oa_parser_0' added non terminal implementation        *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 oa_grammar::select_repeat_oa_parser_0 (oa_scanner & _inLexique) {
  return _inLexique.nextProductionIndex () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//          'select_oa_parser_1' added non terminal implementation           *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 oa_grammar::select_oa_parser_1 (oa_scanner & _inLexique) {
  return _inLexique.nextProductionIndex () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//          'select_oa_parser_2' added non terminal implementation           *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 oa_grammar::select_oa_parser_2 (oa_scanner & _inLexique) {
  return _inLexique.nextProductionIndex () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//          'select_oa_parser_3' added non terminal implementation           *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 oa_grammar::select_oa_parser_3 (oa_scanner & _inLexique) {
  return _inLexique.nextProductionIndex () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//          'select_oa_parser_4' added non terminal implementation           *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 oa_grammar::select_oa_parser_4 (oa_scanner & _inLexique) {
  return _inLexique.nextProductionIndex () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//          'select_oa_parser_5' added non terminal implementation           *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 oa_grammar::select_oa_parser_5 (oa_scanner & _inLexique) {
  return _inLexique.nextProductionIndex () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//          'select_oa_parser_6' added non terminal implementation           *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 oa_grammar::select_oa_parser_6 (oa_scanner & _inLexique) {
  return _inLexique.nextProductionIndex () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//          'select_oa_parser_7' added non terminal implementation           *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 oa_grammar::select_oa_parser_7 (oa_scanner & _inLexique) {
  return _inLexique.nextProductionIndex () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//          'select_oa_parser_8' added non terminal implementation           *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 oa_grammar::select_oa_parser_8 (oa_scanner & _inLexique) {
  return _inLexique.nextProductionIndex () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//          'select_oa_parser_9' added non terminal implementation           *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 oa_grammar::select_oa_parser_9 (oa_scanner & _inLexique) {
  return _inLexique.nextProductionIndex () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//         'select_oa_parser_10' added non terminal implementation           *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 oa_grammar::select_oa_parser_10 (oa_scanner & _inLexique) {
  return _inLexique.nextProductionIndex () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//         'select_oa_parser_11' added non terminal implementation           *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 oa_grammar::select_oa_parser_11 (oa_scanner & _inLexique) {
  return _inLexique.nextProductionIndex () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//         'select_oa_parser_12' added non terminal implementation           *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 oa_grammar::select_oa_parser_12 (oa_scanner & _inLexique) {
  return _inLexique.nextProductionIndex () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//         'select_oa_parser_13' added non terminal implementation           *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 oa_grammar::select_oa_parser_13 (oa_scanner & _inLexique) {
  return _inLexique.nextProductionIndex () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//         'select_oa_parser_14' added non terminal implementation           *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 oa_grammar::select_oa_parser_14 (oa_scanner & _inLexique) {
  return _inLexique.nextProductionIndex () ;
}

//---------------------------------------------------------------------------*

