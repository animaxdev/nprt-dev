//---------------------------------------------------------------------------*
//                                                                           *
//                           File 'oa_parser.cpp'                            *
//                 Generated by version GALGAS_BETA_VERSION                  *
//                      june 11th, 2009, at 21h29'53"                        *
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

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "oa_parser.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "oa_parser.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                Implementation of production rule 'axiome'                 *
//                                                                           *
//---------------------------------------------------------------------------*

void oa_parser::
pr_axiome_oa_parser_13_13_ (oa_scanner & inLexique) {
  GGS_M_processor  var_cas_outProcessorMap ;
  var_cas_outProcessorMap = GGS_M_processor ::constructor_emptyMap (inLexique COMMA_HERE) ;
  GGS_M_network  var_cas_outNetworkMap ;
  var_cas_outNetworkMap = GGS_M_network ::constructor_emptyMap (inLexique COMMA_HERE) ;
  GGS_M_messages  var_cas_outMessagesMap ;
  var_cas_outMessagesMap = GGS_M_messages ::constructor_emptyMap (inLexique COMMA_HERE) ;
  GGS_M_tasks  var_cas_outTaskMap ;
  var_cas_outTaskMap = GGS_M_tasks ::constructor_emptyMap (inLexique COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_system) COMMA_HERE) ;
  { bool syntaxRepeat_0 = true ;
    while (syntaxRepeat_0) {
      switch (select_repeat_oa_parser_0 (inLexique)) {
        case 2 : {
          inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_processor) COMMA_HERE) ;
          GGS_lstring  var_cas_processorName ;
          inLexique.assignFromAttribute_identifierString (var_cas_processorName) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_identifier) COMMA_HERE) ;
          GGS_luint  var_cas_step ;
          switch (select_oa_parser_1 (inLexique)) {
            case 1 : {
              var_cas_step = GGS_luint ::constructor_new (inLexique, GGS_uint (1U), GGS_location (inLexique) COMMA_HERE) ;
              } break ;
            case 2 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_scalingfactor) COMMA_HERE) ;
              inLexique.assignFromAttribute_ulongValue (var_cas_step) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_literal_5F_integer) COMMA_HERE) ;
              if (((var_cas_step.reader_uint (inLexique COMMA_SOURCE_FILE_AT_LINE (31))).operator_isEqual (GGS_uint (0U))).isBuiltAndTrue ()) {
                var_cas_step.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("the step value must be > 0") COMMA_SOURCE_FILE_AT_LINE (33)) ;
              }
              } break ;
            default :
              break ;
          }
          var_cas_outProcessorMap.modifier_insertKey (inLexique, var_cas_processorName, var_cas_step COMMA_SOURCE_FILE_AT_LINE (35)) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1__3B_) COMMA_HERE) ;
          } break ;
        case 3 : {
          GGS_bool var_cas_network ;
          switch (select_oa_parser_2 (inLexique)) {
            case 1 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_can) COMMA_HERE) ;
              var_cas_network = GGS_bool (true) ;
              } break ;
            case 2 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_van) COMMA_HERE) ;
              var_cas_network = GGS_bool (false) ;
              } break ;
            default :
              break ;
          }
          inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_network) COMMA_HERE) ;
          GGS_lstring  var_cas_networkName ;
          inLexique.assignFromAttribute_identifierString (var_cas_networkName) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_identifier) COMMA_HERE) ;
          GGS_luint  var_cas_factor ;
          switch (select_oa_parser_3 (inLexique)) {
            case 1 : {
              var_cas_factor = GGS_luint ::constructor_new (inLexique, GGS_uint (1U), GGS_location (inLexique) COMMA_HERE) ;
              } break ;
            case 2 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_scalingfactor) COMMA_HERE) ;
              inLexique.assignFromAttribute_ulongValue (var_cas_factor) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_literal_5F_integer) COMMA_HERE) ;
              if (((var_cas_factor.reader_uint (inLexique COMMA_SOURCE_FILE_AT_LINE (55))).operator_isEqual (GGS_uint (0U))).isBuiltAndTrue ()) {
                var_cas_factor.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("the factor value must be > 0") COMMA_SOURCE_FILE_AT_LINE (57)) ;
              }
              } break ;
            default :
              break ;
          }
          var_cas_outNetworkMap.modifier_insertKey (inLexique, var_cas_networkName, var_cas_network, var_cas_factor COMMA_SOURCE_FILE_AT_LINE (59)) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1__3B_) COMMA_HERE) ;
          } break ;
        case 4 : {
          inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_task) COMMA_HERE) ;
          GGS_lstring  var_cas_taskName ;
          inLexique.assignFromAttribute_identifierString (var_cas_taskName) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_identifier) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_priority) COMMA_HERE) ;
          GGS_luint  var_cas_taskPriority ;
          inLexique.assignFromAttribute_ulongValue (var_cas_taskPriority) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_literal_5F_integer) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_duration) COMMA_HERE) ;
          GGS_luint  var_cas_taskDurationMin ;
          inLexique.assignFromAttribute_ulongValue (var_cas_taskDurationMin) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_literal_5F_integer) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1__2E__2E_) COMMA_HERE) ;
          GGS_luint  var_cas_taskDurationMax ;
          inLexique.assignFromAttribute_ulongValue (var_cas_taskDurationMax) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_literal_5F_integer) COMMA_HERE) ;
          GGS_luint  var_cas_taskOffset ;
          GGS_bool var_cas_explicitOffset ;
          switch (select_oa_parser_4 (inLexique)) {
            case 1 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_offset) COMMA_HERE) ;
              inLexique.assignFromAttribute_ulongValue (var_cas_taskOffset) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_literal_5F_integer) COMMA_HERE) ;
              var_cas_explicitOffset = GGS_bool (true) ;
              } break ;
            case 2 : {
              var_cas_taskOffset = GGS_luint ::constructor_new (inLexique, GGS_uint (0U), GGS_location (inLexique) COMMA_HERE) ;
              var_cas_explicitOffset = GGS_bool (false) ;
              } break ;
            default :
              break ;
          }
          GGS_luint  var_cas_taskDeadline ;
          switch (select_oa_parser_5 (inLexique)) {
            case 1 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_deadline) COMMA_HERE) ;
              inLexique.assignFromAttribute_ulongValue (var_cas_taskDeadline) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_literal_5F_integer) COMMA_HERE) ;
              } break ;
            case 2 : {
              var_cas_taskDeadline = GGS_luint ::constructor_new (inLexique, GGS_uint (4294967295U), GGS_location (inLexique) COMMA_HERE) ;
              } break ;
            default :
              break ;
          }
          GGS_AC_task  var_cas_taskKind ;
          GGS_luint  var_cas_taskProcessorIndex ;
          GGS_luint  var_cas_taskPeriod ;
          switch (select_oa_parser_6 (inLexique)) {
            case 1 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_period) COMMA_HERE) ;
              inLexique.assignFromAttribute_ulongValue (var_cas_taskPeriod) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_literal_5F_integer) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_processor) COMMA_HERE) ;
              GGS_lstring  var_cas_taskProcessorName ;
              inLexique.assignFromAttribute_identifierString (var_cas_taskProcessorName) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_identifier) COMMA_HERE) ;
              GGS_luint  automatic_var_0 ;
              const GGS_M_processor  _temp_2777 = var_cas_outProcessorMap ;
              if (_temp_2777.isBuilt ()) {
                _temp_2777 (HERE)->method_searchKeyGetIndex (inLexique, var_cas_taskProcessorName, var_cas_taskProcessorIndex, automatic_var_0 COMMA_SOURCE_FILE_AT_LINE (100)) ;
              }
              var_cas_taskKind = GGS_C_independantTask ::constructor_new (inLexique COMMA_HERE) ;
              } break ;
            case 2 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_on) COMMA_HERE) ;
              if ((var_cas_explicitOffset).isBuiltAndTrue ()) {
                GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("A dependant task cannot have an offset") COMMA_SOURCE_FILE_AT_LINE (106)) ;
              }
              switch (select_oa_parser_7 (inLexique)) {
                case 1 : {
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_task) COMMA_HERE) ;
                  GGS_lstring  var_cas_masterTaskName ;
                  inLexique.assignFromAttribute_identifierString (var_cas_masterTaskName) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_identifier) COMMA_HERE) ;
                  GGS_luint  var_cas_every ;
                  switch (select_oa_parser_8 (inLexique)) {
                    case 1 : {
                      var_cas_every = GGS_luint ::constructor_new (inLexique, GGS_uint (1U), GGS_location (inLexique) COMMA_HERE) ;
                      } break ;
                    case 2 : {
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_every) COMMA_HERE) ;
                      inLexique.assignFromAttribute_ulongValue (var_cas_every) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_literal_5F_integer) COMMA_HERE) ;
                      } break ;
                    default :
                      break ;
                  }
                  GGS_luint  var_cas_masterTaskIndex ;
                  GGS_luint  automatic_var_1 ;
                  GGS_luint  automatic_var_2 ;
                  GGS_luint  automatic_var_3 ;
                  GGS_luint  automatic_var_4 ;
                  GGS_luint  automatic_var_5 ;
                  GGS_AC_task  automatic_var_6 ;
                  const GGS_M_tasks  _temp_3341 = var_cas_outTaskMap ;
                  if (_temp_3341.isBuilt ()) {
                    _temp_3341 (HERE)->method_searchKeyGetIndex (inLexique, var_cas_masterTaskName, var_cas_masterTaskIndex, automatic_var_1, automatic_var_2, automatic_var_3, automatic_var_4, automatic_var_5, var_cas_taskProcessorIndex, var_cas_taskPeriod, automatic_var_6 COMMA_SOURCE_FILE_AT_LINE (119)) ;
                  }
                  var_cas_taskKind = GGS_C_taskDependsFromTask ::constructor_new (inLexique, var_cas_masterTaskIndex, var_cas_every COMMA_HERE) ;
                  } break ;
                case 2 : {
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_message) COMMA_HERE) ;
                  GGS_lstring  var_cas_masterMessageName ;
                  inLexique.assignFromAttribute_identifierString (var_cas_masterMessageName) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_identifier) COMMA_HERE) ;
                  GGS_luint  var_cas_masterMessageIndex ;
                  GGS_luint  automatic_var_7 ;
                  GGS_luint  automatic_var_8 ;
                  GGS_luint  automatic_var_9 ;
                  GGS_luint  automatic_var_10 ;
                  GGS_luint  automatic_var_11 ;
                  GGS_luint  automatic_var_12 ;
                  GGS_AC_canMessage  automatic_var_13 ;
                  const GGS_M_messages  _temp_3689 = var_cas_outMessagesMap ;
                  if (_temp_3689.isBuilt ()) {
                    _temp_3689 (HERE)->method_searchKeyGetIndex (inLexique, var_cas_masterMessageName, var_cas_masterMessageIndex, automatic_var_7, automatic_var_8, automatic_var_9, automatic_var_10, automatic_var_11, automatic_var_12, var_cas_taskPeriod, automatic_var_13 COMMA_SOURCE_FILE_AT_LINE (126)) ;
                  }
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_processor) COMMA_HERE) ;
                  GGS_lstring  var_cas_taskProcessorName ;
                  inLexique.assignFromAttribute_identifierString (var_cas_taskProcessorName) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_identifier) COMMA_HERE) ;
                  GGS_luint  var_cas_every ;
                  switch (select_oa_parser_9 (inLexique)) {
                    case 1 : {
                      var_cas_every = GGS_luint ::constructor_new (inLexique, GGS_uint (1U), GGS_location (inLexique) COMMA_HERE) ;
                      } break ;
                    case 2 : {
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_every) COMMA_HERE) ;
                      inLexique.assignFromAttribute_ulongValue (var_cas_every) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_literal_5F_integer) COMMA_HERE) ;
                      } break ;
                    default :
                      break ;
                  }
                  GGS_luint  automatic_var_14 ;
                  const GGS_M_processor  _temp_4080 = var_cas_outProcessorMap ;
                  if (_temp_4080.isBuilt ()) {
                    _temp_4080 (HERE)->method_searchKeyGetIndex (inLexique, var_cas_taskProcessorName, var_cas_taskProcessorIndex, automatic_var_14 COMMA_SOURCE_FILE_AT_LINE (137)) ;
                  }
                  var_cas_taskKind = GGS_C_taskDependsFromMessage ::constructor_new (inLexique, var_cas_masterMessageIndex, var_cas_every COMMA_HERE) ;
                  } break ;
                default :
                  break ;
              }
              } break ;
            default :
              break ;
          }
          var_cas_outTaskMap.modifier_insertKey (inLexique, var_cas_taskName, var_cas_taskPriority, var_cas_taskOffset, var_cas_taskDeadline, var_cas_taskDurationMin, var_cas_taskDurationMax, var_cas_taskProcessorIndex, var_cas_taskPeriod, var_cas_taskKind COMMA_SOURCE_FILE_AT_LINE (141)) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1__3B_) COMMA_HERE) ;
          } break ;
        case 5 : {
          GGS_luint  var_cas_messageClass ;
          switch (select_oa_parser_10 (inLexique)) {
            case 1 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_standard) COMMA_HERE) ;
              var_cas_messageClass = GGS_luint ::constructor_new (inLexique, GGS_uint (0U), GGS_location (inLexique) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_message) COMMA_HERE) ;
              } break ;
            case 2 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_extended) COMMA_HERE) ;
              var_cas_messageClass = GGS_luint ::constructor_new (inLexique, GGS_uint (1U), GGS_location (inLexique) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_message) COMMA_HERE) ;
              } break ;
            case 3 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_message) COMMA_HERE) ;
              var_cas_messageClass = GGS_luint ::constructor_new (inLexique, GGS_uint (2U), GGS_location (inLexique) COMMA_HERE) ;
              } break ;
            default :
              break ;
          }
          GGS_lstring  var_cas_messageName ;
          inLexique.assignFromAttribute_identifierString (var_cas_messageName) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_identifier) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_network) COMMA_HERE) ;
          GGS_lstring  var_cas_networkName ;
          inLexique.assignFromAttribute_identifierString (var_cas_networkName) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_identifier) COMMA_HERE) ;
          GGS_luint  var_cas_networkIndex ;
          GGS_bool var_cas_CANnetwork ;
          GGS_luint  automatic_var_15 ;
          const GGS_M_network  _temp_5217 = var_cas_outNetworkMap ;
          if (_temp_5217.isBuilt ()) {
            _temp_5217 (HERE)->method_searchKeyGetIndex (inLexique, var_cas_networkName, var_cas_networkIndex, var_cas_CANnetwork, automatic_var_15 COMMA_SOURCE_FILE_AT_LINE (171)) ;
          }
          if (((var_cas_CANnetwork).operator_and ((var_cas_messageClass.reader_uint (inLexique COMMA_SOURCE_FILE_AT_LINE (172))).operator_isEqual (GGS_uint (2U)))).isBuiltAndTrue ()) {
            var_cas_messageClass.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("a CAN message must be either standard either extended") COMMA_SOURCE_FILE_AT_LINE (174)) ;
          }else if ((((var_cas_CANnetwork).operator_not ()).operator_and ((var_cas_messageClass.reader_uint (inLexique COMMA_SOURCE_FILE_AT_LINE (174))).operator_isNotEqual (GGS_uint (2U)))).isBuiltAndTrue ()) {
            var_cas_messageClass.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("a VAN message cannot be standard or extended") COMMA_SOURCE_FILE_AT_LINE (176)) ;
          }
          inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_length) COMMA_HERE) ;
          GGS_luint  var_cas_bytesCount ;
          inLexique.assignFromAttribute_ulongValue (var_cas_bytesCount) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_literal_5F_integer) COMMA_HERE) ;
          if (((var_cas_CANnetwork).operator_and ((var_cas_bytesCount.reader_uint (inLexique COMMA_SOURCE_FILE_AT_LINE (180))).operator_strictSup (GGS_uint (8U)))).isBuiltAndTrue ()) {
            var_cas_bytesCount.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("CAN message length must be <= 8 bytes") COMMA_SOURCE_FILE_AT_LINE (182)) ;
          }else if ((((var_cas_CANnetwork).operator_not ()).operator_and ((var_cas_bytesCount.reader_uint (inLexique COMMA_SOURCE_FILE_AT_LINE (182))).operator_strictSup (GGS_uint (28U)))).isBuiltAndTrue ()) {
            var_cas_bytesCount.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("VAN message must be <= 28 bytes") COMMA_SOURCE_FILE_AT_LINE (184)) ;
          }
          inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_priority) COMMA_HERE) ;
          GGS_luint  var_cas_priority ;
          inLexique.assignFromAttribute_ulongValue (var_cas_priority) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_literal_5F_integer) COMMA_HERE) ;
          GGS_luint  var_cas_offset ;
          GGS_bool var_cas_explicitOffset ;
          switch (select_oa_parser_11 (inLexique)) {
            case 1 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_offset) COMMA_HERE) ;
              inLexique.assignFromAttribute_ulongValue (var_cas_offset) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_literal_5F_integer) COMMA_HERE) ;
              var_cas_explicitOffset = GGS_bool (true) ;
              } break ;
            case 2 : {
              var_cas_offset = GGS_luint ::constructor_new (inLexique, GGS_uint (0U), GGS_location (inLexique) COMMA_HERE) ;
              var_cas_explicitOffset = GGS_bool (false) ;
              } break ;
            default :
              break ;
          }
          GGS_luint  var_cas_deadline ;
          switch (select_oa_parser_12 (inLexique)) {
            case 1 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_deadline) COMMA_HERE) ;
              inLexique.assignFromAttribute_ulongValue (var_cas_deadline) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_literal_5F_integer) COMMA_HERE) ;
              } break ;
            case 2 : {
              var_cas_deadline = GGS_luint ::constructor_new (inLexique, GGS_uint (4294967295U), GGS_location (inLexique) COMMA_HERE) ;
              } break ;
            default :
              break ;
          }
          GGS_AC_canMessage  var_cas_messageKind ;
          GGS_luint  var_cas_period ;
          switch (select_oa_parser_13 (inLexique)) {
            case 1 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_period) COMMA_HERE) ;
              inLexique.assignFromAttribute_ulongValue (var_cas_period) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_literal_5F_integer) COMMA_HERE) ;
              var_cas_messageKind = GGS_C_canIndependantMessage ::constructor_new (inLexique COMMA_HERE) ;
              } break ;
            case 2 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_on) COMMA_HERE) ;
              if ((var_cas_explicitOffset).isBuiltAndTrue ()) {
                GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("A dependant task cannot have an offset") COMMA_SOURCE_FILE_AT_LINE (215)) ;
              }
              switch (select_oa_parser_14 (inLexique)) {
                case 1 : {
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_message) COMMA_HERE) ;
                  GGS_lstring  var_cas_name ;
                  inLexique.assignFromAttribute_identifierString (var_cas_name) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_identifier) COMMA_HERE) ;
                  GGS_luint  var_cas_messageIndex ;
                  GGS_luint  automatic_var_16 ;
                  GGS_luint  automatic_var_17 ;
                  GGS_luint  automatic_var_18 ;
                  GGS_luint  automatic_var_19 ;
                  GGS_luint  automatic_var_20 ;
                  GGS_luint  automatic_var_21 ;
                  GGS_AC_canMessage  automatic_var_22 ;
                  const GGS_M_messages  _temp_6806 = var_cas_outMessagesMap ;
                  if (_temp_6806.isBuilt ()) {
                    _temp_6806 (HERE)->method_searchKeyGetIndex (inLexique, var_cas_name, var_cas_messageIndex, automatic_var_16, automatic_var_17, automatic_var_18, automatic_var_19, automatic_var_20, automatic_var_21, var_cas_period, automatic_var_22 COMMA_SOURCE_FILE_AT_LINE (221)) ;
                  }
                  var_cas_messageKind = GGS_C_canMessageFromMessage ::constructor_new (inLexique, var_cas_messageIndex COMMA_HERE) ;
                  } break ;
                case 2 : {
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_task) COMMA_HERE) ;
                  GGS_lstring  var_cas_taskName ;
                  inLexique.assignFromAttribute_identifierString (var_cas_taskName) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_identifier) COMMA_HERE) ;
                  GGS_luint  var_cas_taskIndex ;
                  GGS_luint  automatic_var_23 ;
                  GGS_luint  automatic_var_24 ;
                  GGS_luint  automatic_var_25 ;
                  GGS_luint  automatic_var_26 ;
                  GGS_luint  automatic_var_27 ;
                  GGS_luint  automatic_var_28 ;
                  GGS_AC_task  automatic_var_29 ;
                  const GGS_M_tasks  _temp_7081 = var_cas_outTaskMap ;
                  if (_temp_7081.isBuilt ()) {
                    _temp_7081 (HERE)->method_searchKeyGetIndex (inLexique, var_cas_taskName, var_cas_taskIndex, automatic_var_23, automatic_var_24, automatic_var_25, automatic_var_26, automatic_var_27, automatic_var_28, var_cas_period, automatic_var_29 COMMA_SOURCE_FILE_AT_LINE (228)) ;
                  }
                  var_cas_messageKind = GGS_C_canMessageFromTask ::constructor_new (inLexique, var_cas_taskIndex COMMA_HERE) ;
                  } break ;
                default :
                  break ;
              }
              } break ;
            default :
              break ;
          }
          var_cas_outMessagesMap.modifier_insertKey (inLexique, var_cas_messageName, var_cas_messageClass, var_cas_networkIndex, var_cas_bytesCount, var_cas_priority, var_cas_offset, var_cas_deadline, var_cas_period, var_cas_messageKind COMMA_SOURCE_FILE_AT_LINE (232)) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1__3B_) COMMA_HERE) ;
          } break ;
        default :
          syntaxRepeat_0 = false ;
          break ;
      }
    }
  }
  inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_end) COMMA_HERE) ;
  if (var_cas_outProcessorMap.isBuilt () &&
      var_cas_outNetworkMap.isBuilt () &&
      var_cas_outMessagesMap.isBuilt () &&
      var_cas_outTaskMap.isBuilt ()) {
    ::routine_performComputations (inLexique,  var_cas_outProcessorMap,  var_cas_outNetworkMap,  var_cas_outMessagesMap,  var_cas_outTaskMap COMMA_SOURCE_FILE_AT_LINE (237)) ;
  }
}

//---------------------------------------------------------------------------*

